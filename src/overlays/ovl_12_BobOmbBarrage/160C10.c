#include "ovl_12.h"

omObjData* func_801028F0_160C10_BobOmbBarrage(void) {
    Vec v;
    f32 s;
    omObjData* obj;

    D_800FD474_FE074.x = D_800FD474_FE074.y = D_800FD474_FE074.z = 0.0f;
    D_800FA610_FB210 = 800.0f;
    D_8010274C_10334C.x = D_8010274C_10334C.y = D_8010274C_10334C.z = 0.0f;
    D_800C9B80_CA780->fov[0] = D_80109280_1675A0_BobOmbBarrage = 45.0f;
    D_800C9B80_CA780->fov[1] = D_80109284_1675A4_BobOmbBarrage = 80.0f;
    D_800C9B80_CA780->fov[2] = D_80109288_1675A8_BobOmbBarrage = 8000.0f;
    HuVecCopyXYZ(&D_8010928C_1675AC_BobOmbBarrage, 0.0f, 500.0f, 477.2727f);
    HuVecCopyXYZ(&D_80109298_1675B8_BobOmbBarrage, 0.0f, 200.0f, 250.0f);
    v.x = 0.0f;
    v.y = -(D_80109298_1675B8_BobOmbBarrage.z - D_8010928C_1675AC_BobOmbBarrage.z);
    v.z = D_80109298_1675B8_BobOmbBarrage.y - D_8010928C_1675AC_BobOmbBarrage.y;
    s = 1.0f / func_800B1830_B2430(v.y * v.y + v.z * v.z);
    HuVecCopyXYZ(&D_801092A4_1675C4_BobOmbBarrage, s * v.x, s * v.y, s * v.z);
    obj = omAddObj(0x7FDA, 0x10, 0, -1, func_80102B2C_160E4C_BobOmbBarrage);
    ScissorSet(0, D_80108D58_167078_BobOmbBarrage[0], D_80108D58_167078_BobOmbBarrage[1], D_80108D58_167078_BobOmbBarrage[2], D_80108D58_167078_BobOmbBarrage[3]);
    ViewportSet(0, D_80108D40_167060_BobOmbBarrage[0], D_80108D40_167060_BobOmbBarrage[1], D_80108D40_167060_BobOmbBarrage[2], D_80108D40_167060_BobOmbBarrage[3], D_80108D40_167060_BobOmbBarrage[4], D_80108D40_167060_BobOmbBarrage[5]);
    Hu3DCamSetPositionOrientation(0, &D_8010928C_1675AC_BobOmbBarrage, &D_80109298_1675B8_BobOmbBarrage, &D_801092A4_1675C4_BobOmbBarrage);
    Hu3DCamSetPerspective(0, D_80109280_1675A0_BobOmbBarrage, D_80109284_1675A4_BobOmbBarrage, D_80109288_1675A8_BobOmbBarrage);
    func_80102B2C_160E4C_BobOmbBarrage(obj);
    return obj;
}

void func_80102B2C_160E4C_BobOmbBarrage(omObjData* obj) {
    obj->func_ptr = func_80102B50_160E70_BobOmbBarrage;
    func_80102C64_160F84_BobOmbBarrage();
}

void func_80102B50_160E70_BobOmbBarrage(omObjData* obj) {
    switch (D_801092B0_1675D0_BobOmbBarrage.state) {
    case 1:
    case 2:
        break;
    case 3:
        func_80102C74_160F94_BobOmbBarrage();
        if (D_801092B0_1675D0_BobOmbBarrage.time <= D_801092B0_1675D0_BobOmbBarrage.t) {
            D_801092B0_1675D0_BobOmbBarrage.state = 1;
        } else {
            D_801092B0_1675D0_BobOmbBarrage.t++;
        }
        break;
    }
    Hu3DCamSetPerspective(0, 60.0f, 80.0f, 8000.0f);
    Hu3DCamSetPositionOrientation(0, &D_8010928C_1675AC_BobOmbBarrage, &D_80109298_1675B8_BobOmbBarrage, &D_801092A4_1675C4_BobOmbBarrage);
    Hu3DCamUpdateMtx(0);
}

void func_80102C04_160F24_BobOmbBarrage(Vec* eye, Vec* at, s32 time, s32 mode) {
    D_801092B0_1675D0_BobOmbBarrage.state = 3;
    D_801092B0_1675D0_BobOmbBarrage.t = 0;
    D_801092B0_1675D0_BobOmbBarrage.time = time;
    D_801092B0_1675D0_BobOmbBarrage.mode = mode;
    func_800B3170_B3D70(&D_801092B0_1675D0_BobOmbBarrage.from, eye);
    func_800B3170_B3D70(&D_801092B0_1675D0_BobOmbBarrage.to, at);
}

void func_80102C64_160F84_BobOmbBarrage(void) {
    D_801092B0_1675D0_BobOmbBarrage.mode = -1;
}

#ifdef NON_MATCHING
void func_80102C74_160F94_BobOmbBarrage(void) {
    Vec v;
    f32 u;
    f32 k;
    f32 one;

    u = (f32)D_801092B0_1675D0_BobOmbBarrage.t / (f32)D_801092B0_1675D0_BobOmbBarrage.time;
    if (u > 1.0f) {
        u = 1.0f;
    }
    switch (D_801092B0_1675D0_BobOmbBarrage.mode) {
    case 0:
        break;
    case 1:
        one = 1.0f;
        k = u - one;
        u = -k * k + one;
        if (u < 0.0f) {
            u = 0.0f;
        }
        break;
    }
    if (u > 1.0f) {
        u = 1.0f;
    }
    v.x = (D_801092B0_1675D0_BobOmbBarrage.to.x - D_801092B0_1675D0_BobOmbBarrage.from.x) * u + D_801092B0_1675D0_BobOmbBarrage.from.x;
    v.y = (D_801092B0_1675D0_BobOmbBarrage.to.y - D_801092B0_1675D0_BobOmbBarrage.from.y) * u + D_801092B0_1675D0_BobOmbBarrage.from.y;
    v.z = (D_801092B0_1675D0_BobOmbBarrage.to.z - D_801092B0_1675D0_BobOmbBarrage.from.z) * u + D_801092B0_1675D0_BobOmbBarrage.from.z;
    func_800B3170_B3D70(&D_8010928C_1675AC_BobOmbBarrage, &v);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_12_BobOmbBarrage/160C10", func_80102C74_160F94_BobOmbBarrage);
#endif

s32 func_80102D94_1610B4_BobOmbBarrage(void) {
    return 0;
}
