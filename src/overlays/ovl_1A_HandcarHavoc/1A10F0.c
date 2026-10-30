#include "ovl_1A.h"

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_80108360_1A10F0_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_80108398_1A1128_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_801083B4_1A1144_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_801085F8_1A1388_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_80108730_1A14C0_HandcarHavoc);

/* The two wheel spots of one side (D_8010B184), placed on the car (MP1 func_800FD888). */
// NON_MATCHING: stack addressing of the unused copy array tmp (as MP1 func_800FD888)
#ifdef NON_MATCHING
void func_80108A1C_1A17AC_HandcarHavoc(omObjData* obj, u16 side, Vec* out) {
    HHMtx m;
    f32 v[4];
    f32 t[4];
    Vec tmp[2];
    HHCar* w;
    f32 rx;
    f32 ry;
    f32 rz;
    s32 k;
    s32 i;
    s32 j;

    w = obj->unk_50;
    rx = HuMathSin(w->rot.y) + w->rot.x;
    ry = w->rot.y;
    rz = func_800B7890_B8490(ry) + w->rot.z;
    if (rx < 0.0f) {
        rx += 360.0f;
    }
    if (rx >= 360.0f) {
        rx -= 360.0f;
    }
    if (ry < 0.0f) {
        ry += 360.0f;
    }
    if (ry >= 360.0f) {
        ry -= 360.0f;
    }
    if (rz < 0.0f) {
        rz += 360.0f;
    }
    if (rz >= 360.0f) {
        rz -= 360.0f;
    }
    for (k = 0; k < 2; k++) {
        v[0] = D_8010B184_1A3F14_HandcarHavoc[side * 2 + k].x;
        v[1] = D_8010B188_1A3F18_HandcarHavoc[side * 2 + k].x;
        v[2] = D_8010B18C_1A3F1C_HandcarHavoc[side * 2 + k].x;
        v[3] = 1.0f;
        guMtxIdentF(m);
        func_80025884_26484(m, 0.0f, ry, 0.0f);
        for (j = 0; j < 4; j++) {
            t[j] = 0;
            for (i = 0; i < 4; i++) {
                t[j] += v[i] * m[i][j];
            }
        }
        guMtxIdentF(m);
        func_80025884_26484(m, rx, 0.0f, rz);
        for (j = 0; j < 4; j++) {
            v[j] = 0;
            for (i = 0; i < 4; i++) {
                v[j] += t[i] * m[i][j];
            }
        }
        tmp[k].x = out[k].x = obj->trans.x + v[0];
        tmp[k].y = out[k].y = obj->trans.y + v[1];
        tmp[k].z = out[k].z = obj->trans.z + v[2];
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_80108A1C_1A17AC_HandcarHavoc);
#endif

/* Pumps the levers by the car's speed and pump power (MP1 func_800FDBC8). */
// NON_MATCHING: retail keeps the lever model zero-extended and sign-extends it at each use (as MP1)
#ifdef NON_MATCHING
void func_80108D5C_1A1AEC_HandcarHavoc(omObjData* obj) {
    HHCar* w;
    f32 pump;
    s32 mdl;

    w = obj->unk_50;
    func_80108E80_1A1C10_HandcarHavoc(obj->model[0], w->leverDir, fabs(w->speed) / 20.0);
    pump = w->pump;
    mdl = obj->model[1];
    w->lever1Dir = func_80108E80_1A1C10_HandcarHavoc(mdl, w->lever1Dir, pump);
    w->lever2Dir = func_80108E80_1A1C10_HandcarHavoc(obj->model[2], w->lever2Dir, pump);
    D_800FC834_FD434[obj->model[3]].unk40 = 18.0f - D_800FC834_FD434[(s16)mdl].unk40;
    D_800FC834_FD434[obj->model[4]].unk40 = D_800FC834_FD434[(s16)mdl].unk40;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_80108D5C_1A1AEC_HandcarHavoc);
#endif

/* Steps a model's animation frame back and forth between 0 and its length; returns the
   direction (1 = backwards; MP1 func_800FDCEC). */
u16 func_80108E80_1A1C10_HandcarHavoc(s16 mdl, u16 dir, f32 step) {
    f32 len;

    len = func_80029D0C_2A90C(mdl);
    if (dir) {
        D_800FC834_FD434[mdl].unk40 -= step;
        if (func_80029CE4_2A8E4(mdl) <= 0.0f) {
            dir = 0;
            D_800FC834_FD434[mdl].unk40 = fabsf(func_80029CE4_2A8E4(mdl));
        }
    } else {
        D_800FC834_FD434[mdl].unk40 += step;
        if (len <= func_80029CE4_2A8E4(mdl)) {
            dir = 1;
            D_800FC834_FD434[mdl].unk40 = len + (len - func_80029CE4_2A8E4(mdl));
        }
    }
    return dir;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_80108FBC_1A1D4C_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_8010929C_1A202C_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_80109484_1A2214_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_8010986C_1A25FC_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_80109B88_1A2918_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_80109BA4_1A2934_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_80109BC0_1A2950_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_80109D10_1A2AA0_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_8010A200_1A2F90_HandcarHavoc);

void func_8010A400_1A3190_HandcarHavoc(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_8010A408_1A3198_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_8010A440_1A31D0_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_8010A5B8_1A3348_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_8010A6A4_1A3434_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_8010A75C_1A34EC_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_8010A7D8_1A3568_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_8010A870_1A3600_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_8010AA30_1A37C0_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_8010ABC8_1A3958_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_8010AD1C_1A3AAC_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_8010AE30_1A3BC0_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_8010B024_1A3DB4_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_8010B0FC_1A3E8C_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_8010B108_1A3E98_HandcarHavoc);
