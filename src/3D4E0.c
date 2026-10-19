#include "common.h"

/* func_8003C984 is MP1 src/34D80.c's func_80037178 (flatten a model's vertices onto a plane);
   func_8003C8E0 has no MP1 C and stays asm. MP2 model structs have MP3's layout. */

typedef struct HmfVtx {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ char unk_06[0xA];
} HmfVtx; /* size = 0x10 (MP1 unk2C0C0StructE0) */

typedef struct HmfData {
    /* 0x00 */ char unk_00[0x18];
    /* 0x18 */ s16 unk_18; /* vertex count; MP1 unk_72 */
    /* 0x1A */ char unk_1A[0x2A];
    /* 0x44 */ HmfVtx* unk_44[4]; /* MP1 unk_08 */
} HmfData;

typedef struct HmfModel {
    /* 0x00 */ char unk_00[0x1C];
    /* 0x1C */ f32 unk_1C; /* MP1 unk_24 */
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ char unk_28[0x3C];
    /* 0x64 */ HmfData* unk_64; /* MP1 unk_6C */
    /* 0x68 */ char unk_68[0x58];
} HmfModel; /* size = 0xC0 */

extern HmfModel* D_800FC834_FD434;
extern u8 D_800FDBE0_FE7E0;

INCLUDE_ASM("asm/nonmatchings/3D4E0", func_8003C8E0_3D4E0);

void func_8003C984_3D584(s16 arg0, Vec* n) {
    HmfModel* obj = &D_800FC834_FD434[arg0];
    HmfVtx* v = obj->unk_64->unk_44[D_800FDBE0_FE7E0];
    f32 d = n->x * obj->unk_1C + n->y * obj->unk_20 + n->z * obj->unk_24;
    f32 px;
    f32 pz;
    s16 i;

    for (i = 0; i < obj->unk_64->unk_18; i++) {
        px = v->unk_00 + obj->unk_1C;
        pz = v->unk_04 + obj->unk_24;
        v->unk_02 = (d - px * n->x - pz * n->z) / n->y - obj->unk_20 + 0.5f;
        v++;
    }
}
