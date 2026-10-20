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
void func_80094058_94C58(u16* outbuf, u16* pixY, u16* pixU, u16* pixV);
void func_800945F0_951F0(u16* outbuf, u16* pixY, u16* pixU, u16* pixV);

extern u8 D_800ED910_EE510[0x300]; // channel + 0x100 -> 5-bit field << 1
extern u8 D_800EDC10_EE810[0x300]; // the same with the alpha bit
extern s32 D_800EDF10_EEB10; // chroma subsampled vertically too (two luma block rows per chroma row)
extern void (*D_800EDF14_EEB14)(u16* outbuf, u16* y, u16* u, u16* v); // colour converter for the sampling
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

/* Reads one basis vector from the nest: a 16-bit code gives its position, sample step (1 or 2)
   and row step (one or two nest rows), the sign and the low scale bits. The vector's mean is
   removed; the scale (a running sum of deltas) is advanced. Returns the vector's factor: scale
   over its largest magnitude, in 1/0x1000 units. */
static inline s32 ReadBasis(s16* basis, s32* scale, s32 plane) {
    u16 code;
    s32 step;
    s32 pitch;
    u8* p;
    u8* q;
    s32 sum;
    s32 mean;
    s16 max;
    s16 v;
    s16* b;
    s32 f;
    s32 k;
    s32 flag;
    s32 w;

    code = *D_800EFFCC_F0BCC[plane]++ << 8;
    code |= *D_800EFFCC_F0BCC[plane]++;
    if (D_800F0A54_F1654 == 0) {
        w = D_800F0A48_F1648;
        step = ((code >> 11) & 1) + 1;
        p = D_800F0A44_F1644 + ((code & 0x3F) + ((code >> 6) & 0x1F) * w);
        flag = (code >> 12) & 1;
    } else {
        w = D_800F0A48_F1648;
        step = ((code >> 12) & 1) + 1;
        p = D_800F0A44_F1644 + (((code >> 6) & 0x1F) + (code & 0x3F) * w);
        flag = (code >> 11) & 1;
    }
    pitch = flag ? D_800F0A50_F1650 : w;
    q = p;
    sum = basis[0] = *q; q += step;
    sum += basis[1] = *q; q += step;
    sum += basis[2] = *q; q += step;
    sum += basis[3] = *q;
    p += pitch;
    q = p;
    sum += basis[4] = *q; q += step;
    sum += basis[5] = *q; q += step;
    sum += basis[6] = *q; q += step;
    sum += basis[7] = *q;
    p += pitch;
    q = p;
    sum += basis[8] = *q; q += step;
    sum += basis[9] = *q; q += step;
    sum += basis[10] = *q; q += step;
    sum += basis[11] = *q;
    p += pitch;
    q = p;
    sum += basis[12] = *q; q += step;
    sum += basis[13] = *q; q += step;
    sum += basis[14] = *q; q += step;
    sum += basis[15] = *q;
    mean = sum >> 4;

#define SUB_MEAN()                  \
    v = *b -= mean;                 \
    b++;                            \
    v = (v < 0) ? -v : v;           \
    if (max < v) {                  \
        max = v;                    \
    }

    b = basis;
    max = *b -= mean;
    b++;
    max = (max < 0) ? -max : max;
    SUB_MEAN();
    SUB_MEAN();
    SUB_MEAN();
    SUB_MEAN();
    SUB_MEAN();
    SUB_MEAN();
    SUB_MEAN();
    SUB_MEAN();
    SUB_MEAN();
    SUB_MEAN();
    SUB_MEAN();
    SUB_MEAN();
    SUB_MEAN();
    SUB_MEAN();
    SUB_MEAN();
#undef SUB_MEAN
    k = (*scale += decodeSym(&D_800EFF80_F0B80[plane], &D_800EEF40_EFB40)) + ((code >> 13) & 3);
    if (code & 0x8000) {
        f = -D_800F0AE0_F16E0[max];
    } else {
        f = D_800F0AE0_F16E0[max];
    }
    return f * k;
}

/* Decodes one 4x4 block of a plane: a flat block (no basis vectors) is interpolated from its
   neighbours' DC values, 8 means 16 raw samples, otherwise DC plus up to 7 scaled basis vectors. */
// flat-block stores scheduled differently and register allocation in the basis loop (masked 114)
#ifdef NON_MATCHING
void func_800932E4_93EE4(s16* block, HVQCursor* c, s32 plane) {
    u8 bn;
    u8 dc;
    u8 right;
    u8 up;
    u8 down;
    s32 c2;
    u32 base;
    s16 dr;
    s16 ur;
    s16 ul;
    s16 dl;
    s32 ud;
    s32 lr;
    s32 s0;
    s32 s1;
    u32 t0;
    u32 t1;
    u32 t2;
    u32 t3;
    s32 ulx;
    s32 urx;
    s32 dlx;
    s32 drx;

    bn = c->curbn;
    dc = c->curdc;
    if (bn == 0) {
        right = dc;
        if (c->nextbn == 0) {
            right = c->nextdc;
        }
        up = dc;
        if (*c->bnprev == 0) {
            up = *c->dcprev;
        }
        down = dc;
        if (*c->bnnext == 0) {
            down = *c->dcnext;
        }
        c2 = dc * 2;
        base = (dc * 8) + 4;
        dr = (down + right) - c2;
        ur = (up + right) - c2;
        ul = (up + c->left) - c2;
        dl = (c->left + down) - c2;
        ud = up - down;
        lr = c->left - right;
        s0 = ud + lr;
        s1 = ud - lr;
        t0 = base + s0;
        t1 = base + s1;
        t2 = base - s1;
        t3 = base - s0;
        ulx = up - c->left;
        urx = up - right;
        dlx = down - c->left;
        drx = down - right;
        block[0] = (t0 + ul) >> 3;
        block[1] = (t0 + ulx) >> 3;
        block[2] = (t1 + urx) >> 3;
        block[3] = (t1 + ur) >> 3;
        block[4] = (t0 - ulx) >> 3;
        block[5] = (base - dr) >> 3;
        block[6] = (base - dl) >> 3;
        block[7] = (t1 - urx) >> 3;
        block[8] = (t2 - dlx) >> 3;
        block[9] = (base - ur) >> 3;
        block[10] = (base - ul) >> 3;
        block[11] = (t3 - drx) >> 3;
        block[12] = (t2 + dl) >> 3;
        block[13] = (t2 + dlx) >> 3;
        block[14] = (t3 + drx) >> 3;
        block[15] = (t3 + dr) >> 3;
        c->left = dc;
    } else {
        if (bn == 8) {
#define RAW() *block++ = *D_800EFFCC_F0BCC[plane]++
            RAW(); RAW(); RAW(); RAW();
            RAW(); RAW(); RAW(); RAW();
            RAW(); RAW(); RAW(); RAW();
            RAW(); RAW(); RAW(); RAW();
#undef RAW
        } else {
            s16 basis[16];
            s32 acc[16];
            s32 scale;
            s32 i;
            s32 f;

            scale = 0;
            acc[0] = acc[1] = acc[2] = acc[3] = acc[4] = acc[5] = acc[6] = acc[7] = acc[8] = acc[9] =
                acc[10] = acc[11] = acc[12] = acc[13] = acc[14] = acc[15] =
                    (dc << D_800F13D8_F1FD8) + D_800F13DC_F1FDC;
            for (i = bn; i > 0; i--) {
                f = ReadBasis(basis, &scale, plane);
                acc[0] += f * basis[0];
                acc[1] += f * basis[1];
                acc[2] += f * basis[2];
                acc[3] += f * basis[3];
                acc[4] += f * basis[4];
                acc[5] += f * basis[5];
                acc[6] += f * basis[6];
                acc[7] += f * basis[7];
                acc[8] += f * basis[8];
                acc[9] += f * basis[9];
                acc[10] += f * basis[10];
                acc[11] += f * basis[11];
                acc[12] += f * basis[12];
                acc[13] += f * basis[13];
                acc[14] += f * basis[14];
                acc[15] += f * basis[15];
            }
            block[0] = acc[0] >> D_800F13D8_F1FD8;
            block[1] = acc[1] >> D_800F13D8_F1FD8;
            block[2] = acc[2] >> D_800F13D8_F1FD8;
            block[3] = acc[3] >> D_800F13D8_F1FD8;
            block[4] = acc[4] >> D_800F13D8_F1FD8;
            block[5] = acc[5] >> D_800F13D8_F1FD8;
            block[6] = acc[6] >> D_800F13D8_F1FD8;
            block[7] = acc[7] >> D_800F13D8_F1FD8;
            block[8] = acc[8] >> D_800F13D8_F1FD8;
            block[9] = acc[9] >> D_800F13D8_F1FD8;
            block[10] = acc[10] >> D_800F13D8_F1FD8;
            block[11] = acc[11] >> D_800F13D8_F1FD8;
            block[12] = acc[12] >> D_800F13D8_F1FD8;
            block[13] = acc[13] >> D_800F13D8_F1FD8;
            block[14] = acc[14] >> D_800F13D8_F1FD8;
            block[15] = acc[15] >> D_800F13D8_F1FD8;
        }
        c->left = c->nextdc;
    }
    c->bnprev++;
    c->dcprev++;
    c->bnnext++;
    c->dcnext++;
}
#else
INCLUDE_ASM("asm/nonmatchings/93A80", func_800932E4_93EE4);
#endif

#define UV_BASE ((s32)(16384 * (513.0 / 512.0))) // 0x4020: 0x100 bias and rounding, << 6
#define CONVERT(UPTR, VPTR, R, G, B) \
    v = *(VPTR) - 128;               \
    R = 90 * v + UV_BASE;            \
    u = *(UPTR) - 128;               \
    G = -22 * u + -46 * v + UV_BASE; \
    B = 113 * u + UV_BASE;

static inline u16 getRGB(s16 y, s16 r, s16 g, s16 b) {
    return (D_800ED910_EE510[(y + r) >> 6] << 10) | (D_800ED910_EE510[(y + g) >> 6] << 5) |
           D_800EDC10_EE810[(y + b) >> 6];
}

/* YUV to RGBA5551 for chroma sampled 2:1 across only: a chroma block covers two luma blocks
   side by side (8 x 4 pixels). */
void func_80094058_94C58(u16* outbuf, u16* pixY, u16* pixU, u16* pixV) {
    s32 i;
    u16* pixY1;
    u16* pixY2;
    u16* curoutbuf;
    s16 u;
    s16 v;
    s16 ruv1, guv1, buv1;
    s16 ruv2, guv2, buv2;
    s16 ruv3, guv3, buv3;
    s16 ruv4, guv4, buv4;

    pixY1 = pixY;
    pixY2 = pixY + 16;
    for (i = 4; i > 0; i--) {
        curoutbuf = outbuf;
        CONVERT(pixU++, pixV++, ruv1, guv1, buv1);
        *curoutbuf++ = getRGB(*pixY1++ << 6, ruv1, guv1, buv1);
        *curoutbuf++ = getRGB(*pixY1++ << 6, ruv1, guv1, buv1);
        CONVERT(pixU++, pixV++, ruv2, guv2, buv2);
        *curoutbuf++ = getRGB(*pixY1++ << 6, ruv2, guv2, buv2);
        *curoutbuf++ = getRGB(*pixY1++ << 6, ruv2, guv2, buv2);
        CONVERT(pixU++, pixV++, ruv3, guv3, buv3);
        *curoutbuf++ = getRGB(*pixY2++ << 6, ruv3, guv3, buv3);
        *curoutbuf++ = getRGB(*pixY2++ << 6, ruv3, guv3, buv3);
        CONVERT(pixU++, pixV++, ruv4, guv4, buv4);
        *curoutbuf++ = getRGB(*pixY2++ << 6, ruv4, guv4, buv4);
        *curoutbuf++ = getRGB(*pixY2++ << 6, ruv4, guv4, buv4);
        outbuf += D_800F12FC_F1EFC;
    }
}

/* YUV to RGBA5551 for chroma sampled 2:1 both ways: a chroma block covers four luma blocks
   (8 x 8 pixels), each chroma sample a 2 x 2 square. */
void func_800945F0_951F0(u16* outbuf, u16* pixY, u16* pixU, u16* pixV) {
    s32 i;
    u16* pixY1;
    u16* pixY2;
    u16* curoutbuf;
    s16 u;
    s16 v;
    s16 ruv1, guv1, buv1;
    s16 ruv2, guv2, buv2;
    s16 ruv3, guv3, buv3;
    s16 ruv4, guv4, buv4;

    pixY1 = pixY;
    pixY2 = pixY = pixY + 16;
    i = 4;
    while (i > 0) {
        curoutbuf = outbuf;
        CONVERT(pixU++, pixV++, ruv1, guv1, buv1);
        *curoutbuf++ = getRGB(*pixY1++ << 6, ruv1, guv1, buv1);
        *curoutbuf++ = getRGB(*pixY1++ << 6, ruv1, guv1, buv1);
        CONVERT(pixU++, pixV++, ruv2, guv2, buv2);
        *curoutbuf++ = getRGB(*pixY1++ << 6, ruv2, guv2, buv2);
        *curoutbuf++ = getRGB(*pixY1++ << 6, ruv2, guv2, buv2);
        CONVERT(pixU++, pixV++, ruv3, guv3, buv3);
        *curoutbuf++ = getRGB(*pixY2++ << 6, ruv3, guv3, buv3);
        *curoutbuf++ = getRGB(*pixY2++ << 6, ruv3, guv3, buv3);
        CONVERT(pixU++, pixV++, ruv4, guv4, buv4);
        *curoutbuf++ = getRGB(*pixY2++ << 6, ruv4, guv4, buv4);
        *curoutbuf++ = getRGB(*pixY2++ << 6, ruv4, guv4, buv4);
        outbuf += D_800F12FC_F1EFC;
        curoutbuf = outbuf;
        *curoutbuf++ = getRGB(*pixY1++ << 6, ruv1, guv1, buv1);
        *curoutbuf++ = getRGB(*pixY1++ << 6, ruv1, guv1, buv1);
        *curoutbuf++ = getRGB(*pixY1++ << 6, ruv2, guv2, buv2);
        *curoutbuf++ = getRGB(*pixY1++ << 6, ruv2, guv2, buv2);
        *curoutbuf++ = getRGB(*pixY2++ << 6, ruv3, guv3, buv3);
        *curoutbuf++ = getRGB(*pixY2++ << 6, ruv3, guv3, buv3);
        *curoutbuf++ = getRGB(*pixY2++ << 6, ruv4, guv4, buv4);
        *curoutbuf++ = getRGB(*pixY2++ << 6, ruv4, guv4, buv4);
        i -= 2;
        outbuf += D_800F12FC_F1EFC;
    }
    pixY = pixY + 16;
    pixY1 = pixY;
    pixY2 = pixY + 16;
    i = 4;
    while (i > 0) {
        curoutbuf = outbuf;
        CONVERT(pixU++, pixV++, ruv1, guv1, buv1);
        *curoutbuf++ = getRGB(*pixY1++ << 6, ruv1, guv1, buv1);
        *curoutbuf++ = getRGB(*pixY1++ << 6, ruv1, guv1, buv1);
        CONVERT(pixU++, pixV++, ruv2, guv2, buv2);
        *curoutbuf++ = getRGB(*pixY1++ << 6, ruv2, guv2, buv2);
        *curoutbuf++ = getRGB(*pixY1++ << 6, ruv2, guv2, buv2);
        CONVERT(pixU++, pixV++, ruv3, guv3, buv3);
        *curoutbuf++ = getRGB(*pixY2++ << 6, ruv3, guv3, buv3);
        *curoutbuf++ = getRGB(*pixY2++ << 6, ruv3, guv3, buv3);
        CONVERT(pixU++, pixV++, ruv4, guv4, buv4);
        *curoutbuf++ = getRGB(*pixY2++ << 6, ruv4, guv4, buv4);
        *curoutbuf++ = getRGB(*pixY2++ << 6, ruv4, guv4, buv4);
        outbuf += D_800F12FC_F1EFC;
        curoutbuf = outbuf;
        *curoutbuf++ = getRGB(*pixY1++ << 6, ruv1, guv1, buv1);
        *curoutbuf++ = getRGB(*pixY1++ << 6, ruv1, guv1, buv1);
        *curoutbuf++ = getRGB(*pixY1++ << 6, ruv2, guv2, buv2);
        *curoutbuf++ = getRGB(*pixY1++ << 6, ruv2, guv2, buv2);
        *curoutbuf++ = getRGB(*pixY2++ << 6, ruv3, guv3, buv3);
        *curoutbuf++ = getRGB(*pixY2++ << 6, ruv3, guv3, buv3);
        *curoutbuf++ = getRGB(*pixY2++ << 6, ruv4, guv4, buv4);
        *curoutbuf++ = getRGB(*pixY2++ << 6, ruv4, guv4, buv4);
        i -= 2;
        outbuf += D_800F12FC_F1EFC;
    }
}

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
        D_800EDF14_EEB14(outbuf, (u16*)D_800F1318_F1F18, (u16*)D_800F1398_F1F98, (u16*)D_800F13B8_F1FB8);
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
    D_800EDF14_EEB14(outbuf, (u16*)D_800F1318_F1F18, (u16*)D_800F1398_F1F98, (u16*)D_800F13B8_F1FB8);
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

/* The nest: 0xA64 bytes coded as Huffman deltas, read on from the header stream. */
static inline void ReadNest(BitStream* buf) {
    s32 n;
    s32 acc = 0;
    u8* nest = D_800EFFE0_F0BE0;

    for (n = 0xA64; n > 0; n--) {
        acc += decodeSym(buf, &D_800EF750_F0350);
        *nest++ = acc;
    }
}

/* Reads an image set's header: sizes, the colour converter for its chroma sampling, the four
   Huffman trees and their leaf tables, and the Huffman-coded nest (the basis-vector source). */
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
    ReadNest(&D_800EFF58_F0B58);
}

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
