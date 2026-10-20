#include "common.h"
#include "game/hmfman.h"

/* func_8003C984 is MP1 src/34D80.c's func_80037178 (flatten a model's vertices onto a plane);
   func_8003C8E0 has no MP1 C and stays asm. MP2 model structs have MP3's layout. */

extern u8 D_800FDBE0_FE7E0;

INCLUDE_ASM("asm/nonmatchings/3D4E0", func_8003C8E0_3D4E0);

void func_8003C984_3D584(s16 arg0, Vec* n) {
    HmfModel* obj = &D_800FC834_FD434[arg0];
    HmfVtx* v = obj->hmf->unk44[D_800FDBE0_FE7E0];
    f32 d = n->x * obj->pos.x + n->y * obj->pos.y + n->z * obj->pos.z;
    f32 px;
    f32 pz;
    s16 i;

    for (i = 0; i < obj->hmf->unk18; i++) {
        px = v->unk00 + obj->pos.x;
        pz = v->unk04 + obj->pos.z;
        v->unk02 = (d - px * n->x - pz * n->z) / n->y - obj->pos.y + 0.5f;
        v++;
    }
}
