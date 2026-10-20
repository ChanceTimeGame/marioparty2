#include "common.h"

/* HVQ-MPS 1.1 image decoder (MP3 src/lib/hvq.c is the same code, still asm). A later revision of
   MP1's HVQ2 decoder (MP1 src/7CD60.c): the basis numbers and DC values have separate work
   buffers, the nest is Huffman coded, the scale table and block reader changed, and chroma
   sampling is 2:1 horizontally (H x 1) or in both directions. */

typedef struct BitStream {
    /* 0x00 */ u32 bit;
    /* 0x04 */ u32 value;
    /* 0x08 */ u32* pos;
} BitStream; // size 0xC

typedef struct Tree {
    /* 0x000 */ s16 root;
    /* 0x002 */ s16 array[2][512];
} Tree;

typedef struct HVQMPSHeader {
    /* 0x00 */ char version[16]; // "HVQ-MPS 1.1"
    /* 0x10 */ u32 unk10;
    /* 0x14 */ u16 width;
    /* 0x16 */ u16 height;
    /* 0x18 */ u8 h_sampling_rate;
    /* 0x19 */ u8 v_sampling_rate;
    /* 0x1A */ u8 quantize; // high nibble: DC shift; low nibble: scale precision
    /* 0x1B */ u8 nest_dir;
    /* 0x1C */ u32 basisnum_tree_offset;
    /* 0x20 */ u32 dc_tree_offset;
    /* 0x24 */ u32 scale_tree_offset;
    /* 0x28 */ u32 nest_tree_offset; // the nest's bit stream follows its tree
} HVQMPSHeader;

/* A plane's position in the basis-number and DC work buffers: the rows above, at and below the
   current block, and the values of the blocks either side. */
typedef struct HVQCursor {
    /* 0x00 */ u8* bnprev;
    /* 0x04 */ u8* dcprev;
    /* 0x08 */ u8* bncur;
    /* 0x0C */ u8* dccur;
    /* 0x10 */ u8* bnnext;
    /* 0x14 */ u8* dcnext;
    /* 0x18 */ u8 nextbn; // the block to the right
    /* 0x19 */ u8 nextdc;
    /* 0x1A */ u8 curbn;
    /* 0x1B */ u8 curdc;
    /* 0x1C */ u8 left; // DC of the block to the left
} HVQCursor; // size 0x20

typedef struct HVQMPSFrame {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u32 basisnum_offset[2]; // luma, chroma pairs
    /* 0x0C */ u32 dc_offset[3];
    /* 0x18 */ u32 scale_offset[3];
    /* 0x24 */ u32 fix_offset[3];
} HVQMPSFrame;

s32 func_800B0FD0_B1BD0(char* a, char* b); // strcmp
void func_80095D70_96970(u16* outbuf);
void func_800932E4_93EE4(s16* block, HVQCursor* c, s32 plane);
void func_80094058_94C58(u16* outbuf, s16 y[4][16], s16* u, s16* v);
void func_800945F0_951F0(u16* outbuf, s16 y[4][16], s16* u, s16* v);

extern u8 D_800ED910_EE510[0x300]; // channel + 0x100 -> 5-bit field << 1
extern u8 D_800EDC10_EE810[0x300]; // the same with the alpha bit
extern s32 D_800EDF10_EEB10; // chroma subsampled vertically too (two luma block rows per chroma row)
extern void (*D_800EDF14_EEB14)(u16* outbuf, s16 y[4][16], s16* u, s16* v); // colour converter for the sampling
extern s32 D_800EDF18_EEB18; // next free node while a tree is read
extern Tree D_800EDF20_EEB20; // DC delta tree (leaves: delta << quantize shift)
extern s16 D_800EFF52_F0B52; // largest DC delta (an escape: another delta follows)
extern s16 D_800EFF54_F0B54; // smallest DC delta (an escape)
extern Tree D_800EE730_EF330; // basis number tree (leaves: the byte)
extern Tree D_800EEF40_EFB40; // scale tree (leaves: value << 2)
extern Tree D_800EF750_F0350; // nest delta tree (leaves: value << 4)
extern BitStream D_800EFF58_F0B58; // header stream (the trees, the nest)
extern BitStream D_800EFF68_F0B68[2]; // basis numbers: luma, chroma pairs
extern BitStream D_800EFF80_F0B80[3]; // basis scales per plane
extern BitStream D_800EFFA8_F0BA8[3]; // DC deltas per plane
extern u8* D_800EFFCC_F0BCC[3]; // fixed-length codes (basis vector positions) per plane
extern u8 D_800EFFE0_F0BE0[0xA64]; // nest (0x46 x 0x26)
extern u8* D_800F0A44_F1644; // nest
extern s32 D_800F0A48_F1648; // nest width
extern s32 D_800F0A4C_F164C; // nest height
extern s32 D_800F0A50_F1650; // nest width * 2
extern s32 D_800F0A54_F1654; // nest stored transposed (0x26 wide)
extern HVQCursor D_800F0A58_F1658, D_800F0A78_F1678, D_800F0A98_F1698, D_800F0AB8_F16B8;
extern u8* D_800F12E0_F1EE0[3]; // basis numbers per plane (Y, U, V)
extern u8* D_800F12EC_F1EEC[3]; // DC values per plane
extern u16 D_800F12F8_F1EF8; // image width
extern u16 D_800F12FA_F1EFA; // image height
extern u16 D_800F1300_F1F00; // luma blocks across
extern u16 D_800F1302_F1F02; // luma blocks down
extern u16 D_800F1304_F1F04; // luma blocks
extern u16 D_800F1306_F1F06; // chroma blocks across
extern u16 D_800F1308_F1F08; // chroma blocks down
extern u16 D_800F130A_F1F0A; // chroma blocks
extern u8 D_800F130C_F1F0C; // horizontal sampling rate
extern u8 D_800F130D_F1F0D; // vertical sampling rate
extern s32 D_800F12FC_F1EFC; // output width in pixels
extern s32 D_800F1310_F1F10; // pixels a chroma block covers across (h_sampling_rate * 4)
extern s32 D_800F1314_F1F14; // output pixels a chroma block row covers (width * v_sampling_rate * 4)
extern s16 D_800F1318_F1F18[4][16]; // luma blocks: left, right, then the row below
extern s16 D_800F1398_F1F98[16]; // U block
extern s16 D_800F13B8_F1FB8[16]; // V block
extern s32 D_800F13D8_F1FD8; // basis scale shift (12 - precision)
extern s32 D_800F13DC_F1FDC; // its rounding (half of 1 << shift)
extern s32 D_800F0AE0_F16E0[0x200]; // 0x1000 / n

static inline u32 getBit(BitStream* buf) {
    u32 ret;
    if (buf->bit == 0) {
        buf->value = *buf->pos++;
        buf->bit = 1 << 31;
    }
    ret = (buf->value & buf->bit) != 0;
    buf->bit >>= 1;
    return ret;
}

static inline s16 getByte(BitStream* buf) {
    return (getBit(buf) << 7) | (getBit(buf) << 6) | (getBit(buf) << 5) | (getBit(buf) << 4) |
           (getBit(buf) << 3) | (getBit(buf) << 2) | (getBit(buf) << 1) | getBit(buf);
}

/* Reads a Huffman tree: a 1 bit is a node (both children follow), a 0 bit a leaf byte. */
s16 func_80092E80_93A80(BitStream* buf, Tree* tree) {
    if (getBit(buf)) {
        s32 pos = D_800EDF18_EEB18++;
        tree->array[0][pos] = func_80092E80_93A80(buf, tree);
        tree->array[1][pos] = func_80092E80_93A80(buf, tree);
        return pos;
    }
    return getByte(buf);
}

static inline s16 decodeHuff(BitStream* buf, Tree* tree) {
    u16 pos = tree->root;

    while ((s16)pos >= 0x100) {
        if (getBit(buf)) {
            pos = tree->array[1][(s16)pos];
        } else {
            pos = tree->array[0][(s16)pos];
        }
    }
    return pos;
}

static inline s16 decodeSym(BitStream* buf, Tree* tree) {
    return tree->array[0][decodeHuff(buf, tree)];
}

/* One DC delta; the extreme values are escapes that add the next delta. */
s32 func_80093134_93D34(BitStream* buf) {
    s16 delta;
    s16 val;

    delta = decodeSym(buf, &D_800EDF20_EEB20);
    if (delta == D_800EFF54_F0B54 || delta == D_800EFF52_F0B52) {
        do {
            val = decodeSym(buf, &D_800EDF20_EEB20);
            delta += val;
        } while (val <= D_800EFF54_F0B54 || val >= D_800EFF52_F0B52);
    }
    return delta;
}

INCLUDE_ASM("asm/nonmatchings/93A80", func_800932E4_93EE4);

INCLUDE_ASM("asm/nonmatchings/93A80", func_80094058_94C58);

INCLUDE_ASM("asm/nonmatchings/93A80", func_800945F0_951F0);

/* Shift a plane's cursor one block right: the current block takes the read-ahead one, which is
   refilled from the work buffers. */
#define ADVANCE(c)                  \
    (c).curbn = (c).nextbn;         \
    (c).nextbn = *++(c).bncur;      \
    (c).curdc = (c).nextdc;         \
    (c).nextdc = *++(c).dccur

#define ADVANCE_LAST(c)             \
    (c).curbn = (c).nextbn;         \
    (c).bncur++;                    \
    (c).curdc = (c).nextdc;         \
    (c).dccur++

#define START(c)                    \
    (c).nextbn = *(c).bncur;        \
    (c).nextdc = (c).left = *(c).dccur

/* Decodes and converts one row of chroma blocks (two luma blocks across each, and two luma rows
   when the chroma is subsampled vertically). */
void func_8009576C_9636C(u16* outbuf) {
    s32 i;

    START(D_800F0A98_F1698);
    START(D_800F0AB8_F16B8);
    START(D_800F0A58_F1658);
    if (D_800EDF10_EEB10) {
        START(D_800F0A78_F1678);
    }
    for (i = D_800F1306_F1F06 - 1; i > 0; i--) {
        ADVANCE(D_800F0A58_F1658);
        func_800932E4_93EE4(D_800F1318_F1F18[0], &D_800F0A58_F1658, 0);
        ADVANCE(D_800F0A58_F1658);
        func_800932E4_93EE4(D_800F1318_F1F18[1], &D_800F0A58_F1658, 0);
        if (D_800EDF10_EEB10) {
            ADVANCE(D_800F0A78_F1678);
            func_800932E4_93EE4(D_800F1318_F1F18[2], &D_800F0A78_F1678, 0);
            ADVANCE(D_800F0A78_F1678);
            func_800932E4_93EE4(D_800F1318_F1F18[3], &D_800F0A78_F1678, 0);
        }
        ADVANCE(D_800F0A98_F1698);
        func_800932E4_93EE4(D_800F1398_F1F98, &D_800F0A98_F1698, 1);
        ADVANCE(D_800F0AB8_F16B8);
        func_800932E4_93EE4(D_800F13B8_F1FB8, &D_800F0AB8_F16B8, 2);
        D_800EDF14_EEB14(outbuf, D_800F1318_F1F18, D_800F1398_F1F98, D_800F13B8_F1FB8);
        outbuf += D_800F1310_F1F10;
    }
    ADVANCE(D_800F0A58_F1658);
    func_800932E4_93EE4(D_800F1318_F1F18[0], &D_800F0A58_F1658, 0);
    ADVANCE_LAST(D_800F0A58_F1658);
    func_800932E4_93EE4(D_800F1318_F1F18[1], &D_800F0A58_F1658, 0);
    if (D_800EDF10_EEB10) {
        ADVANCE(D_800F0A78_F1678);
        func_800932E4_93EE4(D_800F1318_F1F18[2], &D_800F0A78_F1678, 0);
        ADVANCE_LAST(D_800F0A78_F1678);
        func_800932E4_93EE4(D_800F1318_F1F18[3], &D_800F0A78_F1678, 0);
    }
    ADVANCE_LAST(D_800F0A98_F1698);
    func_800932E4_93EE4(D_800F1398_F1F98, &D_800F0A98_F1698, 1);
    ADVANCE_LAST(D_800F0AB8_F16B8);
    func_800932E4_93EE4(D_800F13B8_F1FB8, &D_800F0AB8_F16B8, 2);
    D_800EDF14_EEB14(outbuf, D_800F1318_F1F18, D_800F1398_F1F98, D_800F13B8_F1FB8);
}

#define STEP_ROW(c)                       \
    (c).bnprev += D_800F1300_F1F00;       \
    (c).dcprev += D_800F1300_F1F00;       \
    (c).bncur += D_800F1300_F1F00;        \
    (c).dccur += D_800F1300_F1F00;        \
    (c).bnnext += D_800F1300_F1F00;       \
    (c).dcnext += D_800F1300_F1F00

/* Decodes the frame's blocks a chroma block row at a time; the top and bottom rows repeat their
   own row as the missing neighbour. */
void func_80095D70_96970(u16* outbuf) {
    s32 rows;

    D_800F0A98_F1698.bnprev = D_800F0A98_F1698.bncur = D_800F12E0_F1EE0[1];
    D_800F0A98_F1698.dcprev = D_800F0A98_F1698.dccur = D_800F12EC_F1EEC[1];
    D_800F0A98_F1698.bnnext = D_800F12E0_F1EE0[1] + D_800F1306_F1F06;
    D_800F0A98_F1698.dcnext = D_800F12EC_F1EEC[1] + D_800F1306_F1F06;
    D_800F0AB8_F16B8.bnprev = D_800F0AB8_F16B8.bncur = D_800F12E0_F1EE0[2];
    D_800F0AB8_F16B8.dcprev = D_800F0AB8_F16B8.dccur = D_800F12EC_F1EEC[2];
    D_800F0AB8_F16B8.bnnext = D_800F12E0_F1EE0[2] + D_800F1306_F1F06;
    D_800F0AB8_F16B8.dcnext = D_800F12EC_F1EEC[2] + D_800F1306_F1F06;
    D_800F0A58_F1658.bnprev = D_800F0A58_F1658.bncur = D_800F12E0_F1EE0[0];
    D_800F0A58_F1658.dcprev = D_800F0A58_F1658.dccur = D_800F12EC_F1EEC[0];
    D_800F0A58_F1658.bnnext = D_800F12E0_F1EE0[0] + D_800F1300_F1F00;
    D_800F0A58_F1658.dcnext = D_800F12EC_F1EEC[0] + D_800F1300_F1F00;
    if (D_800EDF10_EEB10) {
        D_800F0A78_F1678.bnprev = D_800F12E0_F1EE0[0];
        D_800F0A78_F1678.dcprev = D_800F12EC_F1EEC[0];
        D_800F0A78_F1678.bncur = D_800F12E0_F1EE0[0] + D_800F1300_F1F00;
        D_800F0A78_F1678.dccur = D_800F12EC_F1EEC[0] + D_800F1300_F1F00;
        D_800F0A78_F1678.bnnext = D_800F12E0_F1EE0[0] + D_800F1300_F1F00 + D_800F1300_F1F00;
        D_800F0A78_F1678.dcnext = D_800F12EC_F1EEC[0] + D_800F1300_F1F00 + D_800F1300_F1F00;
    }
    func_8009576C_9636C(outbuf);
    outbuf += D_800F1314_F1F14;
    D_800F0A98_F1698.bnprev = D_800F12E0_F1EE0[1];
    D_800F0A98_F1698.dcprev = D_800F12EC_F1EEC[1];
    D_800F0AB8_F16B8.bnprev = D_800F12E0_F1EE0[2];
    D_800F0AB8_F16B8.dcprev = D_800F12EC_F1EEC[2];
    if (D_800EDF10_EEB10) {
        D_800F0A58_F1658.bncur += D_800F1300_F1F00;
        D_800F0A58_F1658.dccur += D_800F1300_F1F00;
        D_800F0A58_F1658.bnnext += D_800F1300_F1F00;
        D_800F0A58_F1658.dcnext += D_800F1300_F1F00;
        STEP_ROW(D_800F0A78_F1678);
    } else {
        D_800F0A58_F1658.bnprev = D_800F12E0_F1EE0[0];
        D_800F0A58_F1658.dcprev = D_800F12EC_F1EEC[0];
    }
    for (rows = D_800F1308_F1F08 - 2; rows > 0; rows--) {
        func_8009576C_9636C(outbuf);
        outbuf += D_800F1314_F1F14;
        if (D_800EDF10_EEB10) {
            STEP_ROW(D_800F0A58_F1658);
            STEP_ROW(D_800F0A78_F1678);
        }
    }
    D_800F0A98_F1698.bnnext = D_800F0A98_F1698.bncur;
    D_800F0A98_F1698.dcnext = D_800F0A98_F1698.dccur;
    D_800F0AB8_F16B8.bnnext = D_800F0AB8_F16B8.bncur;
    D_800F0AB8_F16B8.dcnext = D_800F0AB8_F16B8.dccur;
    if (D_800EDF10_EEB10) {
        D_800F0A78_F1678.bnnext = D_800F0A78_F1678.bncur;
        D_800F0A78_F1678.dcnext = D_800F0A78_F1678.dccur;
    } else {
        D_800F0A58_F1658.bnnext = D_800F0A58_F1658.bncur;
        D_800F0A58_F1658.dcnext = D_800F0A58_F1658.dccur;
    }
    func_8009576C_9636C(outbuf);
}

static inline void ReadStream(BitStream* buf, u32* src) {
    if (*src) {
        buf->pos = &src[1];
    } else {
        buf->pos = NULL;
    }
    buf->bit = 0;
}

/* Decodes one frame into outbuf (outbufWidth pixels a row, RGBA5551); workbuf holds the basis
   numbers and DC values, two bytes per luma block and two per chroma block pair. */
// register allocation: retail does not relate &D_800EFFA8_F0BA8[1] and [2] (masked 70)
#ifdef NON_MATCHING
void func_80096188_96D88(u8* code, u16* outbuf, s32 outbufWidth, u8* workbuf) {
    HVQMPSFrame* frame = (HVQMPSFrame*)code;
    s32 i;
    s32 n;
    s32 rows;
    u8* p;
    u8* q;
    u8* pu;
    u8* pv;
    u8* qu;
    u8* qv;
    u8 c;
    u8 acc;
    u8 accu;
    u8 accv;
    u8 t;

    ReadStream(&D_800EFF68_F0B68[0], (u32*)(code + frame->basisnum_offset[0]));
    ReadStream(&D_800EFF68_F0B68[1], (u32*)(code + frame->basisnum_offset[1]));
    for (i = 0; i < 3; i++) {
        ReadStream(&D_800EFFA8_F0BA8[i], (u32*)(code + frame->dc_offset[i]));
        ReadStream(&D_800EFF80_F0B80[i], (u32*)(code + frame->scale_offset[i]));
        D_800EFFCC_F0BCC[i] = code + frame->fix_offset[i] + 4;
    }
    D_800F12E0_F1EE0[0] = workbuf;
    D_800F12FC_F1EFC = outbufWidth;
    D_800F12EC_F1EEC[0] = D_800F12E0_F1EE0[0] + D_800F1304_F1F04;
    D_800F12E0_F1EE0[1] = D_800F12EC_F1EEC[0] + D_800F1304_F1F04;
    D_800F12EC_F1EEC[1] = D_800F12E0_F1EE0[1] + D_800F130A_F1F0A;
    D_800F12E0_F1EE0[2] = D_800F12EC_F1EEC[1] + D_800F130A_F1F0A;
    D_800F12EC_F1EEC[2] = D_800F12E0_F1EE0[2] + D_800F130A_F1F0A;
    D_800F1310_F1F10 = D_800F130C_F1F0C * 4;
    D_800F1314_F1F14 = outbufWidth * (D_800F130D_F1F0D * 4);

    /* basis numbers: a byte per luma block, a nibble pair per chroma block pair */
    {
        u8* bn = D_800F12E0_F1EE0[0];
        s32 k;

        for (k = D_800F1304_F1F04; k > 0; k--) {
            *bn++ = decodeSym(&D_800EFF68_F0B68[0], &D_800EE730_EF330);
        }
    }
    {
        u8* bnu = D_800F12E0_F1EE0[1];
        u8* bnv = D_800F12E0_F1EE0[2];
        s32 k;

        for (k = D_800F130A_F1F0A; k > 0; k--) {
            c = decodeSym(&D_800EFF68_F0B68[1], &D_800EE730_EF330);
            *bnu++ = c & 0xF;
            *bnv++ = c >> 4;
        }
    }

    /* DC values: the first row by deltas, later rows predicted from the row above */
    p = q = D_800F12EC_F1EEC[0];
    acc = 0;
    for (n = D_800F1300_F1F00; n > 0; n--) {
        acc += func_80093134_93D34(&D_800EFFA8_F0BA8[0]);
        *p++ = acc;
    }
    for (rows = D_800F1302_F1F02; rows >= 2; rows--) {
        acc = *q;
        for (n = D_800F1300_F1F00; n > 0; n--) {
            q++;
            t = acc + func_80093134_93D34(&D_800EFFA8_F0BA8[0]);
            *p++ = t;
            acc = (*q + t) >> 1;
        }
    }
    pu = qu = D_800F12EC_F1EEC[1];
    pv = qv = D_800F12EC_F1EEC[2];
    accu = accv = 0;
    for (n = D_800F1306_F1F06; n > 0; n--) {
        accu += func_80093134_93D34(&D_800EFFA8_F0BA8[1]);
        *pu++ = accu;
        accv += func_80093134_93D34(&D_800EFFA8_F0BA8[2]);
        *pv++ = accv;
    }
    for (rows = D_800F1308_F1F08; rows >= 2; rows--) {
        accu = *qu;
        accv = *qv;
        for (n = D_800F1306_F1F06; n > 0; n--) {
            qu++;
            t = accu + func_80093134_93D34(&D_800EFFA8_F0BA8[1]);
            *pu++ = t;
            qv++;
            accu = (*qu + t) >> 1;
            t = accv + func_80093134_93D34(&D_800EFFA8_F0BA8[2]);
            *pv++ = t;
            accv = (*qv + t) >> 1;
        }
    }
    func_80095D70_96970(outbuf);
}
#else
INCLUDE_ASM("asm/nonmatchings/93A80", func_80096188_96D88);
#endif

static inline void ReadHufStream(BitStream* buf, Tree* tree, u32* src) {
    if (*src) {
        buf->pos = &src[1];
        buf->bit = 0;
        if (tree) {
            D_800EDF18_EEB18 = 0x100;
            tree->root = func_80092E80_93A80(buf, tree);
        }
    } else {
        buf->pos = NULL;
        buf->bit = 0;
    }
}

static inline void ReadNest(u8* nest) {
    s32 n;
    s32 acc = 0;

    for (n = 0xA64; n > 0; n--) {
        acc += decodeSym(&D_800EFF58_F0B58, &D_800EF750_F0350);
        *nest++ = acc;
    }
}

/* Reads an image set's header: sizes, the colour converter for its chroma sampling, the four
   Huffman trees and their leaf tables, and the Huffman-coded nest (the basis-vector source). */
// scheduling: the nest stream pointer set before the accumulator (masked 4)
#ifdef NON_MATCHING
void func_80096708_97308(HVQMPSHeader* header) {
    u8* code = (u8*)header;
    s32 i;
    s8 j;
    s32 shift;

    u16 w;
    u16 h;
    u8 hs;
    u8 vs;
    s32 prec;
    s32 bw;
    s32 bh;
    s32 cw;
    s32 ch;

    if (func_800B0FD0_B1BD0(header->version, "HVQ-MPS 1.1") != 0) {
        osSyncPrintf("Error : This file is not HVQ-MPS 1.1");
        return;
    }
    D_800F12F8_F1EF8 = w = header->width;
    D_800F12FA_F1EFA = h = header->height;
    D_800F130C_F1F0C = hs = header->h_sampling_rate;
    bw = w >> 2;
    cw = bw / hs;
    D_800F130D_F1F0D = vs = header->v_sampling_rate;
    bh = h >> 2;
    ch = bh / vs;
    D_800F1300_F1F00 = bw;
    D_800F1302_F1F02 = bh;
    D_800F1304_F1F04 = bw * bh;
    D_800F1306_F1F06 = cw;
    D_800F1308_F1F08 = ch;
    D_800F130A_F1F0A = cw * ch;
    if (vs == 1) {
        D_800EDF10_EEB10 = 0;
        D_800EDF14_EEB14 = func_80094058_94C58;
    } else {
        D_800EDF10_EEB10 = 1;
        D_800EDF14_EEB14 = func_800945F0_951F0;
    }
    D_800F0A54_F1654 = header->nest_dir;
    if (D_800F0A54_F1654 == 0) {
        D_800F0A48_F1648 = 0x46;
        D_800F0A4C_F164C = 0x26;
    } else {
        D_800F0A48_F1648 = 0x26;
        D_800F0A4C_F164C = 0x46;
    }
    D_800F0A50_F1650 = D_800F0A48_F1648 * 2;
    ReadHufStream(&D_800EFF58_F0B58, &D_800EE730_EF330, (u32*)(code + header->basisnum_tree_offset));
    ReadHufStream(&D_800EFF58_F0B58, &D_800EDF20_EEB20, (u32*)(code + header->dc_tree_offset));
    ReadHufStream(&D_800EFF58_F0B58, &D_800EEF40_EFB40, (u32*)(code + header->scale_tree_offset));
    ReadHufStream(&D_800EFF58_F0B58, &D_800EF750_F0350, (u32*)(code + header->nest_tree_offset));
    shift = header->quantize >> 4;
    prec = header->quantize & 0xF;
    for (j = i = 0; i < 0x100; i++, j++) {
        D_800EEF40_EFB40.array[0][i] = j << 2;
        D_800EDF20_EEB20.array[0][i] = j << shift;
        D_800EF750_F0350.array[0][i] = j << 4;
        D_800EE730_EF330.array[0][i] = i;
    }
    D_800EFF52_F0B52 = 0x7F << shift;
    D_800EFF54_F0B54 = -0x80 << shift;
    D_800F13D8_F1FD8 = 12 - prec;
    D_800F13DC_F1FDC = 1 << (D_800F13D8_F1FD8 - 1);
    D_800F0A44_F1644 = D_800EFFE0_F0BE0;
    ReadNest(D_800EFFE0_F0BE0);
}
#else
INCLUDE_ASM("asm/nonmatchings/93A80", func_80096708_97308);
#endif

/* Builds the 0x1000 / max reciprocal table and the two clamp tables that turn a colour channel
   (biased by 0x100) into its RGBA5551 field: without and with the alpha bit (alpha's top bit). */
// register allocation: retail keeps a masked copy of alpha >> 7 (masked 2)
#ifdef NON_MATCHING
void func_80096C10_97810(u8 alpha) {
    s32 i;
    s32 v;
    u8 t;

    D_800F0AE0_F16E0[0] = 0;
    for (i = 1; i < 0x200; i++) {
        D_800F0AE0_F16E0[i] = 0x1000 / i;
    }
    alpha >>= 7;
    for (i = 0, v = -0x100; i < 0x300; i++, v++) {
        if (v < 0) {
            D_800ED910_EE510[i] = 0;
            D_800EDC10_EE810[i] = alpha;
        } else if (v >= 0x100) {
            D_800ED910_EE510[i] = 0x3E;
            D_800EDC10_EE810[i] = alpha | 0x3E;
        } else {
            t = (v >> 2) & 0x3E;
            D_800ED910_EE510[i] = t;
            D_800EDC10_EE810[i] = t | alpha;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/93A80", func_80096C10_97810);
#endif
