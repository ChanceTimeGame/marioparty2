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

extern s32 D_800EDF18_EEB18; // next free node while a tree is read
extern Tree D_800EDF20_EEB20; // DC delta tree (leaves: delta << quantize shift)
extern s16 D_800EFF52_F0B52; // largest DC delta (an escape: another delta follows)
extern s16 D_800EFF54_F0B54; // smallest DC delta (an escape)

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

INCLUDE_ASM("asm/nonmatchings/93A80", func_8009576C_9636C);

INCLUDE_ASM("asm/nonmatchings/93A80", func_80095D70_96970);

INCLUDE_ASM("asm/nonmatchings/93A80", func_80096188_96D88);

INCLUDE_ASM("asm/nonmatchings/93A80", func_80096708_97308);

INCLUDE_ASM("asm/nonmatchings/93A80", func_80096C10_97810);
