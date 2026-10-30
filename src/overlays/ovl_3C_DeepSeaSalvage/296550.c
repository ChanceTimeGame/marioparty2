#include "ovl_3C.h"

/* The fish object's models: five copies of the fish, two of them drawn with attribute 4 (MP1
   func_800FEA00). */
void func_801074E0_296550_DeepSeaSalvage(omObjData* obj) {
    s16 i;

    for (i = 0; i < 5; i++) {
        obj->model[i + 1] = func_80027D3C_2893C(obj->model[0]);
    }
    func_800298A4_2A4A4(obj->model[2], 4, 4);
    func_800298A4_2A4A4(obj->model[5], 4, 4);
    for (i = 0; i < 2; i++) {
        func_80107864_2968D4_DeepSeaSalvage(obj, i);
    }
    D_80108E70_297EE0_DeepSeaSalvage = 0;
}

/* Start a fish at one edge (dir != 0: the right, swimming left) with a random speed, depth and
   scale (MP1 func_800FEAC4). */
void func_801075A4_296614_DeepSeaSalvage(s16 idx, s16 dir) {
    if (dir != 0) {
        D_801088F8_297968_DeepSeaSalvage[idx].pos.x = 1002.0f;
        D_801088F8_297968_DeepSeaSalvage[idx].vx =
            -((f32)(((func_801060C8_295138_DeepSeaSalvage() * 5) >> 16) + 8) + D_80108E74_297EE4_DeepSeaSalvage[idx] * 10.0f);
        D_801088F8_297968_DeepSeaSalvage[idx].rot.y = 0.0f;
    } else {
        D_801088F8_297968_DeepSeaSalvage[idx].pos.x = -1002.0f;
        D_801088F8_297968_DeepSeaSalvage[idx].vx =
            (f32)(((func_801060C8_295138_DeepSeaSalvage() * 5) >> 16) + 8) + D_80108E74_297EE4_DeepSeaSalvage[idx] * 10.0f;
        D_801088F8_297968_DeepSeaSalvage[idx].rot.y = 180.0f;
    }
    D_801088F8_297968_DeepSeaSalvage[idx].pos.y = 380.0f - (f32)((func_801060C8_295138_DeepSeaSalvage() * 652) >> 16) - 100.0;
    D_80108E74_297EE4_DeepSeaSalvage[idx] = (f32)(((func_801060C8_295138_DeepSeaSalvage() * 3) >> 16) + 5) / 10.0f * 1.5;
    D_801088F8_297968_DeepSeaSalvage[idx].pos.z = D_80108E74_297EE4_DeepSeaSalvage[idx] * 50.0 + -300.0;
}

/* Start fish idx and fill its history; its model idx * 3 + 2 is drawn with attribute 4 at
   random (MP1 func_800FED88). */
void func_80107864_2968D4_DeepSeaSalvage(omObjData* obj, s16 idx) {
    s16 j;

    func_801075A4_296614_DeepSeaSalvage(idx, idx);
    D_801088F8_297968_DeepSeaSalvage[idx].rot.x = D_801088F8_297968_DeepSeaSalvage[idx].rot.z = 0.0f;
    for (j = 0; j < 10; j++) {
        D_80108978_2979E8_DeepSeaSalvage[idx][j].pos.x = D_801088F8_297968_DeepSeaSalvage[idx].pos.x;
        D_80108978_2979E8_DeepSeaSalvage[idx][j].pos.y = D_801088F8_297968_DeepSeaSalvage[idx].pos.y;
        D_80108978_2979E8_DeepSeaSalvage[idx][j].pos.z = D_801088F8_297968_DeepSeaSalvage[idx].pos.z;
        D_80108978_2979E8_DeepSeaSalvage[idx][j].rot.x = D_801088F8_297968_DeepSeaSalvage[idx].rot.x;
        D_80108978_2979E8_DeepSeaSalvage[idx][j].rot.y = D_801088F8_297968_DeepSeaSalvage[idx].rot.y;
        D_80108978_2979E8_DeepSeaSalvage[idx][j].rot.z = D_801088F8_297968_DeepSeaSalvage[idx].rot.z;
    }
    if ((func_801060C8_295138_DeepSeaSalvage() * 2) >> 16) {
        func_800298A4_2A4A4(obj->model[idx * 3 + 2], 4, 0);
    } else {
        func_800298A4_2A4A4(obj->model[idx * 3 + 2], 4, 4);
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/296550", func_80107A10_296A80_DeepSeaSalvage);

/* The sea surface (model 0 of the backdrop): its vertices and the scrolling texture (MP1
   func_800FF6E0). */
void func_8010819C_29720C_DeepSeaSalvage(omObjData* obj) {
    func_8002A00C_2AC0C(obj->model[0]);
    D_80108E7C_297EEC_DeepSeaSalvage = 0.0f;
    func_8003EAF0_3F6F0("dmy_I8", D_80108E80_297EF0_DeepSeaSalvage);
    D_80108E84_297EF4_DeepSeaSalvage = D_80108E88_297EF8_DeepSeaSalvage = 0.0f;
}

/* Scroll the surface texture and ripple its vertices: x moves by +-40 sin(angle) in alternating
   groups of four, the pattern flipping every 40 vertices (MP1 func_800FF730). */
void func_801081EC_29725C_DeepSeaSalvage(omObjData* obj) {
    HmfData* hmf;
    HmfVtx* src;
    HmfVtx* dst;
    s16 flip = 0;
    s16 row = 0;
    s16 i;

    hmf = D_800FC834_FD434[obj->model[0]].hmf;
    D_80108E84_297EF4_DeepSeaSalvage -= 0.1f;
    func_8002BED4_2CAD4(obj->model[0], D_80108E84_297EF4_DeepSeaSalvage, D_80108E88_297EF8_DeepSeaSalvage,
                        D_80108E80_297EF0_DeepSeaSalvage[0], D_80108E80_297EF0_DeepSeaSalvage[1], "yura", 1);
    src = hmf->unk40;
    dst = hmf->unk44[D_800FDBE0_FE7E0];
    for (i = 0; i < hmf->unk18; i++) {
        if (!(i & 3)) {
            flip = row ^ 1;
            if (!(i & 4)) {
                flip = row;
            }
        }
        if (flip == 0) {
            dst->unk00 = src->unk00 + HuMathSin(D_80108E7C_297EEC_DeepSeaSalvage) * 40.0;
        } else {
            dst->unk00 = src->unk00 - HuMathSin(D_80108E7C_297EEC_DeepSeaSalvage) * 40.0;
        }
        flip ^= 1;
        if ((i + 1) % 40 == 0) {
            row ^= 1;
        }
        src++;
        dst++;
    }
    D_80108E7C_297EEC_DeepSeaSalvage = func_800B0D98_B1998(D_80108E7C_297EEC_DeepSeaSalvage + 4.0, 360.0);
}
