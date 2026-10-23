#include "common.h"
#include "game/hmfman.h"

/* func_8003C984 is MP1 src/34D80.c's func_80037178 (flatten a model's vertices onto a plane);
   func_8003C8E0 has no MP1 C and stays asm. MP2 model structs have MP3's layout. */

extern u8 D_800FDBE0_FE7E0;
extern u8 D_800FDBCA_FE7CA; /* frame buffer count */
void func_8002A00C_2AC0C(s16);

/* MP1 src/34D80.c's func_800370D4: copy a model's base vertices into every frame buffer. */
void func_8003C8E0_3D4E0(s16 arg0) {
    HmfData* hmf;
    s16 i;

    func_8002A00C_2AC0C(arg0);
    hmf = D_800FC834_FD434[arg0].hmf;
    for (i = 0; i < D_800FDBCA_FE7CA; i++) {
        bcopy(hmf->unk40, hmf->unk44[i], hmf->unk18 * sizeof(HmfVtx));
    }
}

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
