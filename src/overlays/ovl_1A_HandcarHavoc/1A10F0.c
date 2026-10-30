#include "ovl_1A.h"

void func_80108360_1A10F0_HandcarHavoc(omObjData* obj) {
    s32 i = 0;

    for (i = 0; i < gNumOfControllers; i++) {}
}

void func_80108398_1A1128_HandcarHavoc(s32 arg0) {
    omOvlReturnEx(1);
}

/* The two viewports' cameras (fov 40, far 12000, near 4400). */
/* NON_MATCHING: the KMC mul fix adds a nop after four calls whose delay slot GCC filled with a mov.s (retail's has none); otherwise MP1's code. */
#ifdef NON_MATCHING
void func_801083B4_1A1144_HandcarHavoc(omObjData* obj) {
    Vec3f pos;
    Vec3f target;
    Vec3f up;
    f32 rx;
    f32 ry;
    s32 i;

    for (i = 0; i < 2; i++) {
        rx = D_80102770_103370[i].x;
        ry = D_80102770_103370[i].y;
        pos.x = HuMathSin(ry) * func_800B7890_B8490(rx) * D_800F94A8_FA0A8[i] + D_801013B0_101FB0[i].x;
        pos.y = -HuMathSin(rx) * D_800F94A8_FA0A8[i] + D_801013B0_101FB0[i].y;
        pos.z = func_800B7890_B8490(ry) * func_800B7890_B8490(rx) * D_800F94A8_FA0A8[i] + D_801013B0_101FB0[i].z;
        target.x = D_801013B0_101FB0[i].x;
        target.y = D_801013B0_101FB0[i].y;
        target.z = D_801013B0_101FB0[i].z;
        up.x = HuMathSin(ry) * HuMathSin(rx);
        up.y = func_800B7890_B8490(rx);
        up.z = func_800B7890_B8490(ry) * HuMathSin(rx);
        D_800FC8F8_FD4F8[i][1] = pos.x;
        D_800FC8F8_FD4F8[i][2] = pos.z;
        D_800FC8F8_FD4F8[i][0] = D_80102770_103370[i].y;
        D_800FC8F8_FD4F8[i][3] = 40.0f;
        D_800FC8F8_FD4F8[i][4] = 12000.0f;
        D_800FC8F8_FD4F8[i][5] = 4400.0f;
        Hu3DCamSetPositionOrientation(i, &pos, &target, &up);
        Hu3DCamUpdateMtx(i);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_801083B4_1A1144_HandcarHavoc);
#endif

/* Height of a face's plane at (x, z); -100000 for a vertical face. Unused. */
f32 func_801085F8_1A1388_HandcarHavoc(f32 x, f32 y, f32 z, ColVtx* vtx, s16* face) {
    Vec3f n;
    Vec3f p;
    ColVtx* a;
    f32 nx;
    f32 ny;
    f32 nz;

    a = &vtx[face[1]];
    p.x = a->x;
    p.y = a->y;
    p.z = a->z;
    func_8002DA3C_2E63C(&vtx[face[1]], &vtx[face[2]], &vtx[face[3]], &n);
    nx = n.x;
    ny = n.y;
    nz = n.z;
    if (ny == 0.0f) {
        return -100000.0f;
    }
    return y + (nx * (p.x - x) + ny * (p.y - y) + nz * (p.z - z)) / ny;
}

/* A rider's seat position: the car's rotations applied to (0, 162.5, seat offset). */
/* NON_MATCHING: float register allocation (masked 0; the lean products' temporaries), as in MP1. */
#ifdef NON_MATCHING
void func_80108730_1A14C0_HandcarHavoc(omObjData* obj, u16 seat, Vec* out) {
    Matrix4f m;
    f32 v[4];
    f32 t[4];
    HHCar* w;
    f32 rx;
    f32 ry;
    f32 rz;
    f32 s;
    f32 c;
    s32 i;
    s32 j;

    w = obj->unk_50;
    v[0] = 0.0f;
    v[1] = 162.5f;
    v[2] = w->seat[seat];
    v[3] = 1.0f;
    s = HuMathSin(w->rot.y);
    c = func_800B7890_B8490(w->rot.y);
    rx = s * w->lean + w->rot.x + s * w->tilt;
    ry = w->rot.y;
    rz = c * w->lean + w->rot.z + c * w->tilt;
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
        v[j] = 0.0f;
        for (i = 0; i < 4; i++) {
            v[j] += t[i] * m[i][j];
        }
    }
    out->x = obj->trans.x + v[0];
    out->y = obj->trans.y + v[1];
    out->z = obj->trans.z + v[2];
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_80108730_1A14C0_HandcarHavoc);
#endif

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_80108A1C_1A17AC_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_80108D5C_1A1AEC_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A10F0", func_80108E80_1A1C10_HandcarHavoc);

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
