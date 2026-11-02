#include "ovl_1B.h"

__asm__(".section .data");
s16 D_80109C80_1AB520_BallonBurst[4] = { 0x20, 0x30, 0x50, 0x60 };
f32 D_80109C88_1AB528_BallonBurst[6] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -4.0f };
f32 D_80109CA0_1AB540_BallonBurst[24] = { -8.0f, -14.0f, -5.0f, -8.0f, 8.0f, 2.0f };
f32 D_80109D00_1AB5A0_BallonBurst[6] = { 4.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f };
f32 D_80109D18_1AB5B8_BallonBurst[6] = { 6.0f, 4.0f, 0.0f, 4.0f, 0.0f, 6.0f };
Vec D_80109D30_1AB5D0_BallonBurst[4] = {
    { -375.0f, -1715.0f, -3520.0f },
    { -203.0f, -1715.0f, -3520.0f },
    { 203.0f, -1715.0f, -3520.0f },
    { 375.0f, -1715.0f, -3520.0f },
};
f32 D_80109D60_1AB600_BallonBurst[6] = { -15.5f, -10.5f, -13.5f, -1.0f, -1.0f, 6.0f };
f32 D_80109D78_1AB618_BallonBurst[5] = { -26.5f, -22.5f, -29.5f, -20.0f, -20.0f };
s8 D_80109D8C_1AB62C_BallonBurst[8] = { 0x00, 0x19, 0x23, 0x32, 0x3C, 0x5A, 0, 0 };
s8 D_80109D94_1AB634_BallonBurst[8] = { 0x00, 0x19, 0x23, 0x32, 0x5A, 0, 0, 0 };
s8 D_80109D9C_1AB63C_BallonBurst[37][4] = {
    { 1, 0, -1, 0 },
    { 1, 1, 0, 0 },
    { 1, 0, 0, 0 },
    { 2, 0, 0, 0 },
    { 2, 0, 0, 0 },
    { 1, 0, 0, 0 },
    { 2, 0, 0, 0 },
    { 2, 1, 2, 1 },
    { 2, -1, 2, -1 },
    { 4, -1, 2, 0 },
    { 4, -1, 2, -2 },
    { 4, -1, 1, -1 },
    { 4, 0, 1, -1 },
    { 2, 0, 0, 0 },
    { 2, 0, 0, 0 },
    { 2, 0, 2, 0 },
    { 0, 0, 0, 0 },
    { 2, 0, 0, 0 },
    { 2, 0, 0, 0 },
    { 2, 0, 0, 0 },
    { 2, 2, 0, 2 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 2, 0, 0, 0 },
    { 2, 0, 0, 0 },
    { 0, 0, -2, 0 },
    { 0, 0, 0, 0 },
    { 2, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 2, 0, 2 },
    { 0, 2, 0, 2 },
    { 0, 2, 0, 2 },
    { 0, 0, 0, 0 },
};

__asm__(".section .rodata");
const char D_80109E30_1AB6D0_BallonBurst[] = "\202`\202a\202b\202c\202d\202e\202f\202g\202h\202i\202j\202k\202l\202m\202n\202o\202p\202q\202r\202s\202t\202u\202v\202w\202x\202y";

void func_80102800_1A40A0_BallonBurst(void) {
    s32 i;
    s32 k;
    s16 j;
    f32 t;
    f32 e;
    f64 u;
    f64 w;

    func_80020D20_21920(0x28);
    omInitObjMan(0x32, 0);
    i = 0;
    func_80079128_79D28();
    func_80029708_2A308(0);
    func_80026D28_27928(1);
    func_80026DAC_279AC(0, 0x90, 0x90, 0x90);
    func_80026DAC_279AC(1, 0xFF, 0xFF, 0xFF);
    func_80026E00_27A00(1, 50.0f, 80.0f, 130.0f);
    omAddObj(0, 0, 0, -1, func_801037F4_1A5094_BallonBurst);
    omAddObj(8, 0, 0, -1, func_80103924_1A51C4_BallonBurst);
    func_8007273C_7333C((const u8*)D_80109E30_1AB6D0_BallonBurst, 1);
    D_8010AAB0_1AC350_BallonBurst[0] = omAddObj(2, 7, 0, -1, func_801064A4_1A7D44_BallonBurst);
    D_8010AAB0_1AC350_BallonBurst[1] = omAddObj(2, 7, 0, -1, func_801064C0_1A7D60_BallonBurst);
    D_8010AAB0_1AC350_BallonBurst[2] = omAddObj(2, 7, 0, -1, func_801064DC_1A7D7C_BallonBurst);
    D_8010AAB0_1AC350_BallonBurst[3] = omAddObj(2, 7, 0, -1, func_801064F8_1A7D98_BallonBurst);
    D_8010A76C_1AC00C_BallonBurst = omAddObj(6, 2, 2, -1, NULL);
    *D_8010A76C_1AC00C_BallonBurst->model = LoadFormFile(0x2B0005, 0x499);
    omSetTra(D_8010A76C_1AC00C_BallonBurst, 0.0f, -2475.0f, -5925.0f);
    omSetSca(D_8010A76C_1AC00C_BallonBurst, 1.5f, 1.5f, 1.5f);
    HmfModelObjAttrSet(*D_8010A76C_1AC00C_BallonBurst->model, 0x600, 0x600);
    func_80029E80_2AA80(*D_8010A76C_1AC00C_BallonBurst->model, 2, 2);
    D_8010A728_1ABFC8_BallonBurst = omAddObj(6, 2, 2, -1, NULL);
    *D_8010A728_1ABFC8_BallonBurst->model = LoadFormFile(0x2B0000, 0x386A9);
    omSetTra(D_8010A728_1ABFC8_BallonBurst, 336.0f, -2223.0f, -5925.0f);
    omSetSca(D_8010A728_1ABFC8_BallonBurst, 1.8f, 1.8f, 1.8f);
    HmfModelObjAttrSet(*D_8010A728_1ABFC8_BallonBurst->model, 0x600, 0x600);
    func_80029E80_2AA80(*D_8010A728_1ABFC8_BallonBurst->model, 1, 1);
    HmfModelObjAttrSet(*D_8010A728_1ABFC8_BallonBurst->model, 0x20000, 0x20000);
    func_80029A8C_2A68C(*D_8010A728_1ABFC8_BallonBurst->model);
    func_8002A00C_2AC0C(*D_8010A728_1ABFC8_BallonBurst->model);
    func_8002CDF0_2D9F0(*D_8010A728_1ABFC8_BallonBurst->model, 0, 0, 0, 0);
    D_8010A6F8_1ABF98_BallonBurst = omAddObj(6, 2, 2, -1, NULL);
    *D_8010A6F8_1ABF98_BallonBurst->model = LoadFormFile(0x2B0000, 0x306A9);
    omSetTra(D_8010A6F8_1ABF98_BallonBurst, -336.0f, -2223.0f, -5925.0f);
    omSetSca(D_8010A6F8_1ABF98_BallonBurst, 1.8f, 1.8f, 1.8f);
    HmfModelObjAttrSet(*D_8010A6F8_1ABF98_BallonBurst->model, 0x600, 0x600);
    func_80029E80_2AA80(*D_8010A6F8_1ABF98_BallonBurst->model, 1, 1);
    HmfModelObjAttrSet(*D_8010A6F8_1ABF98_BallonBurst->model, 0x20000, 0x20000);
    func_80029A8C_2A68C(*D_8010A6F8_1ABF98_BallonBurst->model);
    func_8002A00C_2AC0C(*D_8010A6F8_1ABF98_BallonBurst->model);
    func_8002CDF0_2D9F0(*D_8010A6F8_1ABF98_BallonBurst->model, 0, 0, 0, 0);
    D_8010A600_1ABEA0_BallonBurst = omAddObj(6, 2, 2, -1, NULL);
    *D_8010A600_1ABEA0_BallonBurst->model = LoadFormFile(0x2B0006, 0x489);
    omSetTra(D_8010A600_1ABEA0_BallonBurst, 336.0f, -2223.0f, -5925.0f);
    omSetSca(D_8010A600_1ABEA0_BallonBurst, 1.85f, 1.85f, 1.85f);
    D_8010A75C_1ABFFC_BallonBurst = omAddObj(6, 2, 2, -1, NULL);
    *D_8010A75C_1ABFFC_BallonBurst->model = LoadFormFile(0x2B0006, 0x489);
    omSetTra(D_8010A75C_1ABFFC_BallonBurst, -336.0f, -2223.0f, -5925.0f);
    omSetSca(D_8010A75C_1ABFFC_BallonBurst, 1.85f, 1.85f, 1.85f);
    for (; i < 4; i++) {
        f32 ofs[4] = { 3.0f, 3.0f, -3.0f, -3.0f };

        D_8010A748_1ABFE8_BallonBurst[i] = omAddObj(6, 2, 2, -1, NULL);
        *D_8010A748_1ABFE8_BallonBurst[i]->model = LoadFormFile(i < 2 ? 0x2B0004 : 0x2B0003, 0x10489);
        omSetTra(D_8010A748_1ABFE8_BallonBurst[i], D_80109D30_1AB5D0_BallonBurst[i].x + ofs[i], D_80109D30_1AB5D0_BallonBurst[i].y, D_80109D30_1AB5D0_BallonBurst[i].z + 110.0f);
        omSetSca(D_8010A748_1ABFE8_BallonBurst[i], 0.89f, 1.000004f, 0.89f);
        omSetRot(D_8010A748_1ABFE8_BallonBurst[i], -13.573945f, 0.0f, 0.0f);
        HmfModelObjAttrSet(*D_8010A748_1ABFE8_BallonBurst[i]->model, 0x600, 0x600);
        func_80029E80_2AA80(*D_8010A748_1ABFE8_BallonBurst[i]->model, 1, 1);
        func_8002CD78_2D978(*D_8010A748_1ABFE8_BallonBurst[i]->model, 0, 0, 0, 0);
        func_8002CDB4_2D9B4(*D_8010A748_1ABFE8_BallonBurst[i]->model, 0, 0, 0, 0);
        D_8010AA98_1AC338_BallonBurst[i] = omAddObj(6, 2, 2, -1, NULL);
        *D_8010AA98_1AC338_BallonBurst[i]->model = LoadFormFile(i < 2 ? 0x2B0004 : 0x2B0003, 0x48D);
        omSetTra(D_8010AA98_1AC338_BallonBurst[i], D_80109D30_1AB5D0_BallonBurst[i].x + ofs[i], D_80109D30_1AB5D0_BallonBurst[i].y, D_80109D30_1AB5D0_BallonBurst[i].z + 110.0f);
        omSetSca(D_8010AA98_1AC338_BallonBurst[i], 0.89f, 1.000004f, 0.89f);
        omSetRot(D_8010AA98_1AC338_BallonBurst[i], -13.573945f, 0.0f, 0.0f);
        HmfModelObjAttrSet(*D_8010AA98_1AC338_BallonBurst[i]->model, 0x600, 0x600);
        func_80029E80_2AA80(*D_8010AA98_1AC338_BallonBurst[i]->model, 1, 1);
        func_8002CD78_2D978(*D_8010AA98_1AC338_BallonBurst[i]->model, 0, 0, 0, 0);
        func_8002CDF0_2D9F0(*D_8010AA98_1AC338_BallonBurst[i]->model, 0, 0, 0, 0);
        func_80029A8C_2A68C(*D_8010AA98_1AC338_BallonBurst[i]->model);
        func_8002D124_2DD24(*D_8010AA98_1AC338_BallonBurst[i]->model);
    }
    for (j = 0; j < 4; j++) {
        D_8010A6E8_1ABF88_BallonBurst[j] = omAddObj(6, 2, 2, -1, NULL);
        *D_8010A6E8_1ABF88_BallonBurst[j]->model = LoadFormFile(0x2B0007, 0x10429);
        omSetSca(D_8010A6E8_1ABF88_BallonBurst[j], 0.75f, 0.75f, 0.75f);
        HmfModelObjAttrSet(*D_8010A6E8_1ABF88_BallonBurst[j]->model, 0x600, 0x600);
        func_80029E80_2AA80(*D_8010A6E8_1ABF88_BallonBurst[j]->model, 1, 1);
        func_8002CD78_2D978(*D_8010A6E8_1ABF88_BallonBurst[j]->model, 0, 0, 0, 0);
        func_8002CDB4_2D9B4(*D_8010A6E8_1ABF88_BallonBurst[j]->model, 0, 0, 0, 0);
    }
    omSetTra(D_8010A6E8_1ABF88_BallonBurst[0], -372.7f, -1794.0f, -3420.0f);
    omSetTra(D_8010A6E8_1ABF88_BallonBurst[1], -194.9f, -1794.0f, -3420.0f);
    omSetTra(D_8010A6E8_1ABF88_BallonBurst[2], 204.3f, -1794.0f, -3420.0f);
    omSetTra(D_8010A6E8_1ABF88_BallonBurst[3], 383.1f, -1794.0f, -3420.0f);
    D_8010AA94_1AC334_BallonBurst = omAddObj(4, 8, 2, -1, NULL);
    *D_8010AA94_1AC334_BallonBurst->model = LoadFormFile(0x2B0001, 0x499);
    HmfModelObjAttrSet(*D_8010AA94_1AC334_BallonBurst->model, 0x600, 0x600);
    for (k = 1; k < 7; k++) {
        D_8010AA94_1AC334_BallonBurst->model[k] = func_80027D3C_2893C(*D_8010AA94_1AC334_BallonBurst->model);
    }
    for (k = 0; k < 3; k++) {
        func_800298A4_2A4A4(D_8010AA94_1AC334_BallonBurst->model[k], 4, 4);
    }
    D_8010A608_1ABEA8_BallonBurst[0][0].x = 33.0f;
    D_8010A608_1ABEA8_BallonBurst[0][0].y = -2210.0f;
    D_8010A608_1ABEA8_BallonBurst[0][0].z = -5490.0f;
    omSetTra(D_8010AA94_1AC334_BallonBurst, 33.0f, -2210.0f, -5490.0f);
    omSetSca(D_8010AA94_1AC334_BallonBurst, 0.5f, 0.5f, 0.5f);
    {
    Vec target;

    target.x = -324.0f;
    target.y = -2253.2f;
    target.z = -5925.0f;
    D_8010A718_1ABFB8_BallonBurst[0] = 0;
    D_8010A764_1AC004_BallonBurst[0] = 0;
    for (k = 1; k < 4; k++) {
        t = (f32)k / 6.0f;
        u = t;
        u = 1.0 - u;
        w = u * u;
        w = w * u;
        e = 1.0 - w;
        D_8010A608_1ABEA8_BallonBurst[0][k].x = D_8010A608_1ABEA8_BallonBurst[0][0].x * u + t * target.x;
        D_8010A608_1ABEA8_BallonBurst[0][k].y = D_8010A608_1ABEA8_BallonBurst[0][0].y * (1.0 - e) + e * target.y;
        D_8010A608_1ABEA8_BallonBurst[0][k].z = D_8010A608_1ABEA8_BallonBurst[0][0].z * (1.0 - e) + e * target.z;
        func_80029714_2A314(D_8010AA94_1AC334_BallonBurst->model[k], D_8010A608_1ABEA8_BallonBurst[0][k].x, D_8010A608_1ABEA8_BallonBurst[0][k].y, D_8010A608_1ABEA8_BallonBurst[0][k].z);
        func_800297E8_2A3E8(D_8010AA94_1AC334_BallonBurst->model[k], 0.5f, 0.5f, 0.5f);
    }
    D_8010A704_1ABFA4_BallonBurst = omAddObj(4, 8, 2, -1, NULL);
    *D_8010A704_1ABFA4_BallonBurst->model = LoadFormFile(0x2B0002, 0x499);
    HmfModelObjAttrSet(*D_8010A704_1ABFA4_BallonBurst->model, 0x600, 0x600);
    for (k = 1; k < 7; k++) {
        D_8010A704_1ABFA4_BallonBurst->model[k] = func_80027D3C_2893C(*D_8010A704_1ABFA4_BallonBurst->model);
    }
    for (k = 0; k < 3; k++) {
        func_800298A4_2A4A4(D_8010A704_1ABFA4_BallonBurst->model[k], 4, 4);
    }
    D_8010A608_1ABEA8_BallonBurst[1][0].x = -33.0f;
    D_8010A608_1ABEA8_BallonBurst[1][0].y = -2210.0f;
    D_8010A608_1ABEA8_BallonBurst[1][0].z = -5490.0f;
    omSetTra(D_8010A704_1ABFA4_BallonBurst, -33.0f, -2210.0f, -5490.0f);
    omSetSca(D_8010A704_1ABFA4_BallonBurst, 0.5f, 0.5f, 0.5f);
    target.x = 336.0f;
    target.y = -2253.2f;
    target.z = -5925.0f;
    D_8010A718_1ABFB8_BallonBurst[1] = 0;
    D_8010A764_1AC004_BallonBurst[1] = 0;
    for (k = 1; k < 4; k++) {
        t = (f32)k / 6.0f;
        u = t;
        u = 1.0 - u;
        w = u * u;
        w = w * u;
        e = 1.0 - w;
        D_8010A608_1ABEA8_BallonBurst[1][k].x = D_8010A608_1ABEA8_BallonBurst[1][0].x * u + t * target.x;
        D_8010A608_1ABEA8_BallonBurst[1][k].y = D_8010A608_1ABEA8_BallonBurst[1][0].y * (1.0 - e) + e * target.y;
        D_8010A608_1ABEA8_BallonBurst[1][k].z = D_8010A608_1ABEA8_BallonBurst[1][0].z * (1.0 - e) + e * target.z;
        func_80029714_2A314(D_8010A704_1ABFA4_BallonBurst->model[k], D_8010A608_1ABEA8_BallonBurst[1][k].x, D_8010A608_1ABEA8_BallonBurst[1][k].y, D_8010A608_1ABEA8_BallonBurst[1][k].z);
        func_800297E8_2A3E8(D_8010A704_1ABFA4_BallonBurst->model[k], 0.5f, 0.5f, 0.5f);
    }
    }
    InitFadeIn(0, 0x10);
}

void func_801037F4_1A5094_BallonBurst(omObjData* obj) {
    D_8010A6FC_1ABF9C_BallonBurst = -1;
    D_8010A900_1AC1A0_BallonBurst = 0;
    D_8010AB02_1AC3A2_BallonBurst = 0;
    D_8010A770_1AC010_BallonBurst = 0x3C;
    D_8010A760_1AC000_BallonBurst = 0;
    D_8010AAC0_1AC360_BallonBurst = 3;
    D_8010A720_1ABFC0_BallonBurst = 0;
    D_8010A722_1ABFC2_BallonBurst = 2;
    bzero(D_8010A908_1AC1A8_BallonBurst, sizeof(D_8010A908_1AC1A8_BallonBurst));
    bzero(D_8010A778_1AC018_BallonBurst, sizeof(D_8010A778_1AC018_BallonBurst));
    D_8010A708_1ABFA8_BallonBurst[0] = D_8010A708_1ABFA8_BallonBurst[1] = 0.0f;
    D_8010A740_1ABFE0_BallonBurst[0] = D_8010A740_1ABFE0_BallonBurst[1] = 0;
    D_8010A730_1ABFD0_BallonBurst[0][0] = D_8010A730_1ABFD0_BallonBurst[1][0] = D_8010A730_1ABFD0_BallonBurst[2][0] = D_8010A730_1ABFD0_BallonBurst[3][0] = 0;
    D_8010A6CE_1ABF6E_BallonBurst[0] = D_8010A6CE_1ABF6E_BallonBurst[1] = D_8010A6CE_1ABF6E_BallonBurst[2] = D_8010A6CE_1ABF6E_BallonBurst[3] = 0;
    D_8010AB00_1AC3A0_BallonBurst = 0;
    D_8010A6D8_1ABF78_BallonBurst[0] = D_8010A6D8_1ABF78_BallonBurst[1] = D_8010A6D8_1ABF78_BallonBurst[2] = D_8010A6D8_1ABF78_BallonBurst[3] = 0.0f;
    D_8010A724_1ABFC4_BallonBurst[0] = D_8010A724_1ABFC4_BallonBurst[1] = D_8010A724_1ABFC4_BallonBurst[2] = D_8010A724_1ABFC4_BallonBurst[3] = 0xA;
    D_8010A6D4_1ABF74_BallonBurst = 0;
    obj->func_ptr = NULL;
}

void func_80103924_1A51C4_BallonBurst(omObjData* obj) {
    Vec eye;
    Vec at;
    s32 tex;
    s32 tex2;

    eye.x = 7.0f;
    eye.y = 595.412f;
    eye.z = 1329.5f;
    at.x = 7.0f;
    at.y = 50.846f;
    at.z = 0.0f;
    eye.x = 7.0f;
    eye.y = 375.672f;
    eye.z = 1329.5f;
    at.x = 7.0f;
    at.y = 54.701f;
    at.z = 0.0f;
    D_8010AAA8_1AC348_BallonBurst = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x2B000A), 0, 0);
    espDispOff(D_8010AAA8_1AC348_BallonBurst);
    func_8007A27C_7AE7C(0x7FDA, D_800F93FC_F9FFC[D_8010AAA8_1AC348_BallonBurst].unk_04, func_80103C10_1A54B0_BallonBurst, 5.1275f, &eye, &at);
    Hu3DCamSetPerspective(0, 5.1275f, 8000.0f, 16000.0f);
    tex = func_8001A2F8_1AEF8(0x2B0009);
    D_8010A6CC_1ABF6C_BallonBurst = SprCreate(1, 0);
    SprAnimSet(D_8010A6CC_1ABF6C_BallonBurst, 0, tex, 0);
    SprAttrReset(D_8010A6CC_1ABF6C_BallonBurst, 0, 0xFFFF);
    SprAttrSet(D_8010A6CC_1ABF6C_BallonBurst, 0, 0x04004008);
    SprPosSet(D_8010A6CC_1ABF6C_BallonBurst, 0, 0x104, 0xDC);
    SprScaleSet(D_8010A6CC_1ABF6C_BallonBurst, 0, 1.0f, 1.0f);
    func_80081B28_82728(D_8010A6CC_1ABF6C_BallonBurst, 0, 0x4800);
    tex2 = func_8001A2F8_1AEF8(0x2B0008);
    D_8010A6D2_1ABF72_BallonBurst = SprCreate(1, 0);
    SprAnimSet(D_8010A6D2_1ABF72_BallonBurst, 0, tex2, 0);
    SprAttrReset(D_8010A6D2_1ABF72_BallonBurst, 0, 0xFFFF);
    SprAttrSet(D_8010A6D2_1ABF72_BallonBurst, 0, 0x04004008);
    SprPosSet(D_8010A6D2_1ABF72_BallonBurst, 0, 0x104, 0xDC);
    SprScaleSet(D_8010A6D2_1ABF72_BallonBurst, 0, 1.0f, 1.0f);
    func_80081B28_82728(D_8010A6D2_1ABF72_BallonBurst, 0, 0x4800);
    func_8002838C_28F8C(0, func_80106454_1A7CF4_BallonBurst, 0);
    omAddObj(0x64, 0, 0, -1, func_80109BD0_1AB470_BallonBurst);
    obj->func_ptr = func_8010644C_1A7CEC_BallonBurst;
}

/* The camera, the team meters and the game's states. NON_MATCHING: the C is the retail logic; retail
   also keeps a dead compare of the two meters at the top of the meter loop (class: dead code left by
   flow, see docs/DECOMP_WALLS.md), which moves the register allocation of the whole function.
   Calls equal retail (masked 355); GCC also cross-jumps two of the three D_8010AA90 stores. */
#ifdef NON_MATCHING
void func_80103C10_1A54B0_BallonBurst(BBView* view) {
    Vec eye;
    Vec at;
    Vec up;
    s8 n[2];
    BBWork* w;
    omObjData** o;
    s32 i;
    s32 j;
    s32 k;
    s8 c;
    s8 idx;
    f32 d;
    f32 m;
    f32 t;
    f64 e;
    f32* p;
    s32 flag;
    s8 x;

    eye.x = 7.0f;
    eye.y = -124.328f;
    eye.z = 1329.5f;
    at.x = 7.0f;
    at.y = -445.299f;
    at.z = 0.0f;
    up.x = 0.0f;
    up.y = 1.0f;
    up.z = 0.0f;
    if ((func_80078EA8_79AA8() & 0xFFFF) + D_80102720_103320 == 0) {
        flag = D_8010AB02_1AC3A2_BallonBurst;
        if (flag == 1) {
            for (k = 0; k < 2; k++) {
                for (i = 0; i < 2; i++) {
                    p = D_8010A708_1ABFA8_BallonBurst;
                    if (i == 0) {
                        p = &D_8010A708_1ABFA8_BallonBurst[1];
                    }
                    d = (*p - D_8010A708_1ABFA8_BallonBurst[i]) / 6.0f;
                    if (d > 5.0) {
                        m = (d > 25.0) ? 1.5f : (f32)((d - 5.0) / 40.0 + 1.0);
                    } else if (d < -5.0) {
                        m = (d < -25.0) ? 0.875f : (f32)(1.0 - (-d - 5.0) / 160.0);
                    } else {
                        m = 1.0f;
                    }
                    D_8010A708_1ABFA8_BallonBurst[i] += m * D_8010A908_1AC1A8_BallonBurst[i][0x2B];
                    D_8010A740_1ABFE0_BallonBurst[i] = 0;
                    d = D_8010A778_1AC018_BallonBurst[i][0x2B];
                    if (d != 0.0f && d > 0.0f) {
                        D_8010A740_1ABFE0_BallonBurst[i] = d;
                    }
                    for (j = 0x30; j > 0; j--) {
                        D_8010A908_1AC1A8_BallonBurst[i][j] = D_8010A908_1AC1A8_BallonBurst[i][j - 1];
                        D_8010A778_1AC018_BallonBurst[i][j] = D_8010A778_1AC018_BallonBurst[i][j - 1];
                    }
                    D_8010A908_1AC1A8_BallonBurst[i][0] = 0;
                    D_8010A778_1AC018_BallonBurst[i][0] = 0;
                }
            }
        } else if ((flag == 0) | (flag != 4)) {
            for (i = 0; i < 2; i++) {
                for (j = 0x30; j > 0; j--) {
                    D_8010A908_1AC1A8_BallonBurst[i][j] *= 0.925;
                    D_8010A778_1AC018_BallonBurst[i][j] *= 0.925;
                }
            }
        }
    }
    if ((func_80078EA8_79AA8() & 0xFFFF) + D_80102720_103320 == 0) {
        switch (D_8010AB02_1AC3A2_BallonBurst) {
        case 0:
            if (D_8010A770_1AC010_BallonBurst <= 0) {
                D_8010AB02_1AC3A2_BallonBurst = 1;
                D_8010A770_1AC010_BallonBurst = 0x384;
                D_8010A6FC_1ABF9C_BallonBurst = func_800691FC_69DFC(0xA, 0x1E, 0xA0, 0x20);
            } else {
                D_8010A5F0_1ABE90_BallonBurst[0]->unk_08 = D_8010A5F0_1ABE90_BallonBurst[1]->unk_08 = D_8010A5F0_1ABE90_BallonBurst[2]->unk_08 = D_8010A5F0_1ABE90_BallonBurst[3]->unk_08 = 2;
                if (D_8010A770_1AC010_BallonBurst == 0x2D && D_8010A900_1AC1A0_BallonBurst == 0 && D_801011FC_101DFC == 0) {
                    PlayMusic(0x1C);
                }
                if (D_8010A770_1AC010_BallonBurst == 0x28) {
                    func_800691FC_69DFC(0);
                }
            }
            break;
        case 1:
            if (D_8010A708_1ABFA8_BallonBurst[0] / 6.0f >= 50.0f || D_8010A708_1ABFA8_BallonBurst[1] / 6.0f >= 50.0f) {
                if (D_8010A708_1ABFA8_BallonBurst[0] / 6.0f >= 50.0f && D_8010A708_1ABFA8_BallonBurst[1] / 6.0f >= 50.0f) {
                    for (j = 0x30; j > 0; j--) {
                        if (!(D_8010A708_1ABFA8_BallonBurst[1] < D_8010A708_1ABFA8_BallonBurst[0])) {
                            if (!(D_8010A708_1ABFA8_BallonBurst[0] < D_8010A708_1ABFA8_BallonBurst[1])) {
                                for (i = 0; i < 2; i++) {
                                    D_8010A708_1ABFA8_BallonBurst[i] += D_8010A908_1AC1A8_BallonBurst[i][j];
                                }
                                continue;
                            }
                            D_8010AAC0_1AC360_BallonBurst = 1;
                        } else {
                            D_8010AAC0_1AC360_BallonBurst = 0;
                        }
                        break;
                    }
                    if (j == 0) {
                        D_8010AAC0_1AC360_BallonBurst = rand8() & 1;
                    }
                } else if (D_8010A708_1ABFA8_BallonBurst[0] / 6.0f >= 50.0f) {
                    D_8010AAC0_1AC360_BallonBurst = 0;
                } else {
                    D_8010AAC0_1AC360_BallonBurst = 1;
                }
                n[0] = 0;
                n[1] = 0;
                D_8010AAFC_1AC39C_BallonBurst[0] = D_8010AAFC_1AC39C_BallonBurst[1] = D_8010AAFC_1AC39C_BallonBurst[2] = D_8010AAFC_1AC39C_BallonBurst[3] = 0;
                for (c = 0; c < 4; c++) {
                    x = D_8010AAC0_1AC360_BallonBurst;
                    idx = n[x != D_8010A5F0_1ABE90_BallonBurst[c]->group];
                    if (x == D_8010A5F0_1ABE90_BallonBurst[c]->group) {
                        D_8010AAFC_1AC39C_BallonBurst[idx] = c;
                    } else {
                        D_8010AAFC_1AC39C_BallonBurst[idx + 2] = c;
                    }
                    x = D_8010AAC0_1AC360_BallonBurst;
                    n[x != D_8010A5F0_1ABE90_BallonBurst[c]->group]++;
                }
                D_8010AB02_1AC3A2_BallonBurst = 4;
                D_8010A770_1AC010_BallonBurst = 7;
                func_800794A8_7A0A8(0x28);
                for (i = 0; i < 4; i++) {
                    func_8002CD78_2D978(*D_8010A748_1ABFE8_BallonBurst[i]->model, 0, 0, 0, 0);
                    func_8002CDB4_2D9B4(*D_8010A748_1ABFE8_BallonBurst[i]->model, 0, 0, 0, 0);
                }
                break;
            }
            if (D_8010A770_1AC010_BallonBurst <= 0) {
                D_8010AB02_1AC3A2_BallonBurst = 7;
                D_8010A770_1AC010_BallonBurst = 0x3C;
                func_800794A8_7A0A8(0x28);
                func_800691FC_69DFC(3);
                func_8006D4D0_6E0D0(0);
                func_8006D518_6E118();
                D_8010AAC0_1AC360_BallonBurst = 2;
                for (i = 0; i < 4; i++) {
                    func_8002CD78_2D978(*D_8010A748_1ABFE8_BallonBurst[i]->model, 0, 0, 0, 0);
                    func_8002CDB4_2D9B4(*D_8010A748_1ABFE8_BallonBurst[i]->model, 0, 0, 0, 0);
                }
            } else {
                if ((D_8010A770_1AC010_BallonBurst + 1) % 30 == 0) {
                    func_8006D4D0_6E0D0(D_8010A770_1AC010_BallonBurst / 30 + 1);
                }
                break;
            }
        case 7:
            if (D_8010A770_1AC010_BallonBurst > 0) {
                break;
            }
            if (_CheckFlag(0xC) != 0) {
                D_8010AB02_1AC3A2_BallonBurst = 8;
                InitFadeOut(0, 0x14);
                D_8010A770_1AC010_BallonBurst = 0x14;
                for (i = 0; i < 4; i++) {
                    func_80029E80_2AA80(*D_8010AAB0_1AC350_BallonBurst[i]->model, 1, 1);
                }
            } else {
                D_8010AB02_1AC3A2_BallonBurst = 6;
                D_8010A770_1AC010_BallonBurst = 0x78;
                if (D_8010A900_1AC1A0_BallonBurst == 0 && D_801011FC_101DFC == 0) {
                    PlayMusic(0x57);
                }
                func_800691FC_69DFC(0x13);
                for (i = 0; i < 4; i++) {
                    w = D_8010A5F0_1ABE90_BallonBurst[i];
                    func_800298A4_2A4A4(*D_8010A748_1ABFE8_BallonBurst[i]->model, 4, 4);
                    func_80029C74_2A874(*D_8010AA98_1AC338_BallonBurst[i]->model, func_80029CE4_2A8E4(*D_8010A748_1ABFE8_BallonBurst[i]->model));
                    func_800298A4_2A4A4(*D_8010AA98_1AC338_BallonBurst[i]->model, 4, 0);
                    func_8002D124_2DD24(*D_8010AA98_1AC338_BallonBurst[i]->model);
                    omSetTra(D_8010AAB0_1AC350_BallonBurst[i], D_80109D30_1AB5D0_BallonBurst[(u8)w->slot].x + ((w->character == 5) ? 7.0 : 0.0) + D_80109C88_1AB528_BallonBurst[w->character],
                             D_80109D30_1AB5D0_BallonBurst[(u8)w->slot].y, D_80109D30_1AB5D0_BallonBurst[(u8)w->slot].z + ((w->character == 5) ? 45.0 : 0.0));
                }
                for (i = 0; i < 4; i++) {
                    func_80029BF0_2A7F0(*D_8010AAB0_1AC350_BallonBurst[i]->model, func_80029E14_2AA14(D_8010AAB0_1AC350_BallonBurst[i]->model[5]), 0, 0xC, 2);
                }
            }
        case 6:
            if (D_8010A770_1AC010_BallonBurst <= 0) {
                goto fade;
            }
            break;
        case 4:
            if (D_8010A770_1AC010_BallonBurst <= 0) {
                D_8010AB02_1AC3A2_BallonBurst = 5;
                D_8010A770_1AC010_BallonBurst = 0x1E;
                func_80029E80_2AA80(*D_8010AAB0_1AC350_BallonBurst[D_8010AAFC_1AC39C_BallonBurst[0]]->model, 1, 1);
                func_80029E80_2AA80(*D_8010AAB0_1AC350_BallonBurst[D_8010AAFC_1AC39C_BallonBurst[1]]->model, 1, 1);
                if (_CheckFlag(0xC) != 0) {
                    func_80029E80_2AA80(*D_8010AAB0_1AC350_BallonBurst[D_8010AAFC_1AC39C_BallonBurst[2]]->model, 1, 1);
                    func_80029E80_2AA80(*D_8010AAB0_1AC350_BallonBurst[D_8010AAFC_1AC39C_BallonBurst[3]]->model, 1, 1);
                } else {
                    func_80029B80_2A780(D_8010AAB0_1AC350_BallonBurst[D_8010AAFC_1AC39C_BallonBurst[2]]->model[0], D_8010AAB0_1AC350_BallonBurst[D_8010AAFC_1AC39C_BallonBurst[2]]->model[4]);
                    func_80029E80_2AA80(*D_8010AAB0_1AC350_BallonBurst[D_8010AAFC_1AC39C_BallonBurst[2]]->model, 2, 2);
                    func_80029B80_2A780(D_8010AAB0_1AC350_BallonBurst[D_8010AAFC_1AC39C_BallonBurst[3]]->model[0], D_8010AAB0_1AC350_BallonBurst[D_8010AAFC_1AC39C_BallonBurst[3]]->model[4]);
                    func_80029E80_2AA80(*D_8010AAB0_1AC350_BallonBurst[D_8010AAFC_1AC39C_BallonBurst[3]]->model, 2, 2);
                }
                func_8002D124_2DD24(*((D_8010AAC0_1AC360_BallonBurst != 0) ? D_8010A600_1ABEA0_BallonBurst : D_8010A75C_1ABFFC_BallonBurst)->model);
                PlaySound(0x211);
                D_8010A6C8_1ABF68_BallonBurst = 0.0f;
                D_8010AB04_1AC3A4_BallonBurst = 2.0f;
                D_8010A904_1AC1A4_BallonBurst = 2.0f;
                w = D_8010A5F0_1ABE90_BallonBurst[D_8010AAFC_1AC39C_BallonBurst[0]];
                omSetTra(D_8010AAB0_1AC350_BallonBurst[D_8010AAFC_1AC39C_BallonBurst[0]], D_80109D30_1AB5D0_BallonBurst[(u8)w->slot].x + ((w->character == 5) ? 7.0 : 0.0) + D_80109C88_1AB528_BallonBurst[w->character],
                         D_80109D30_1AB5D0_BallonBurst[(u8)w->slot].y, D_80109D30_1AB5D0_BallonBurst[(u8)w->slot].z + ((w->character == 5) ? 45.0 : 0.0));
                for (i = 1; _CheckFlag(0xC) != 0 ? i < 4 : i < 2; i++) {
                    w = D_8010A5F0_1ABE90_BallonBurst[D_8010AAFC_1AC39C_BallonBurst[i]];
                    omSetTra(D_8010AAB0_1AC350_BallonBurst[D_8010AAFC_1AC39C_BallonBurst[i]], D_80109D30_1AB5D0_BallonBurst[(u8)w->slot].x + ((w->character == 5) ? 7.0 : 0.0) + D_80109C88_1AB528_BallonBurst[w->character],
                             D_80109D30_1AB5D0_BallonBurst[(u8)w->slot].y, D_80109D30_1AB5D0_BallonBurst[(u8)w->slot].z + ((w->character == 5) ? 45.0 : 0.0));
                }
                goto run5;
            }
            if (D_8010A770_1AC010_BallonBurst == 1) {
                omVibrate(D_8010AAFC_1AC39C_BallonBurst[0], 0xA, 0, 0xA);
                omVibrate(D_8010AAFC_1AC39C_BallonBurst[1], 0xA, 0, 0xA);
                omVibrate(D_8010AAFC_1AC39C_BallonBurst[2], 0x14, 0, 0x14);
                omVibrate(D_8010AAFC_1AC39C_BallonBurst[3], 0x14, 0, 0x14);
            case 5:
            run5:
                if (D_8010A904_1AC1A4_BallonBurst > 0.0) {
                    D_8010AB04_1AC3A4_BallonBurst -= 0.25;
                    D_8010A6C8_1ABF68_BallonBurst += D_8010AB04_1AC3A4_BallonBurst;
                    if (D_8010A6C8_1ABF68_BallonBurst <= 0.0) {
                        D_8010A904_1AC1A4_BallonBurst -= 1.0;
                        if (D_8010A904_1AC1A4_BallonBurst > 0.0) {
                            D_8010A6C8_1ABF68_BallonBurst = -D_8010A6C8_1ABF68_BallonBurst;
                            D_8010AB04_1AC3A4_BallonBurst = D_8010A904_1AC1A4_BallonBurst;
                        } else {
                            D_8010A6C8_1ABF68_BallonBurst = 0.0f;
                        }
                    }
                }
                if (D_8010A770_1AC010_BallonBurst <= 0) {
                    D_8010AB02_1AC3A2_BallonBurst = 2;
                    D_8010A770_1AC010_BallonBurst = 0x3C;
                    func_800691FC_69DFC(3);
                    func_8006D518_6E118();
                    i = (_CheckFlag(0xC) != 0) ? 0 : D_8010AAC0_1AC360_BallonBurst * 2;
                    for (; _CheckFlag(0xC) != 0 ? i < 4 : i < D_8010AAC0_1AC360_BallonBurst * 2 + 2; i++) {
                        func_800298A4_2A4A4(*D_8010A748_1ABFE8_BallonBurst[i]->model, 4, 4);
                        func_80029C74_2A874(*D_8010AA98_1AC338_BallonBurst[i]->model, func_80029CE4_2A8E4(*D_8010A748_1ABFE8_BallonBurst[i]->model));
                        func_800298A4_2A4A4(*D_8010AA98_1AC338_BallonBurst[i]->model, 4, 0);
                        func_8002D124_2DD24(*D_8010AA98_1AC338_BallonBurst[i]->model);
                    }
                    for (i = 0; _CheckFlag(0xC) != 0 ? i < 4 : i < 2; i++) {
                        func_80029BF0_2A7F0(*D_8010AAB0_1AC350_BallonBurst[D_8010AAFC_1AC39C_BallonBurst[i]]->model, func_80029E14_2AA14(D_8010AAB0_1AC350_BallonBurst[D_8010AAFC_1AC39C_BallonBurst[i]]->model[6]), 0, 0x19, 2);
                    }
                } else if (D_8010A770_1AC010_BallonBurst == 0x19) {
                    omVibrate(D_8010AAFC_1AC39C_BallonBurst[2], 0x14, 0, 0x14);
                    omVibrate(D_8010AAFC_1AC39C_BallonBurst[3], 0x14, 0, 0x14);
                } else if (D_8010A770_1AC010_BallonBurst == 0x16) {
                    omVibrate(D_8010AAFC_1AC39C_BallonBurst[2], 1, 3, 6);
                    omVibrate(D_8010AAFC_1AC39C_BallonBurst[3], 1, 3, 6);
                } else {
                    break;
                }
                case 2:
                    if (D_8010A770_1AC010_BallonBurst == 1) {
                        omSetTra(D_8010A748_1ABFE8_BallonBurst[D_8010AAC0_1AC360_BallonBurst * 2], (D_80109D30_1AB5D0_BallonBurst[D_8010AAC0_1AC360_BallonBurst * 2].x - 3.0) * 0.96, D_80109D30_1AB5D0_BallonBurst[D_8010AAC0_1AC360_BallonBurst * 2].y * 0.947, (D_80109D30_1AB5D0_BallonBurst[D_8010AAC0_1AC360_BallonBurst * 2].z + 110.0f) * 0.9);
                        omSetTra(D_8010A748_1ABFE8_BallonBurst[D_8010AAC0_1AC360_BallonBurst * 2 + 1], (D_80109D30_1AB5D0_BallonBurst[D_8010AAC0_1AC360_BallonBurst * 2 + 1].x - 3.0) * 0.96, D_80109D30_1AB5D0_BallonBurst[D_8010AAC0_1AC360_BallonBurst * 2 + 1].y * 0.947, (D_80109D30_1AB5D0_BallonBurst[D_8010AAC0_1AC360_BallonBurst * 2 + 1].z + 110.0f) * 0.9);
                    } else if (D_8010A770_1AC010_BallonBurst <= 0) {
                        if (_CheckFlag(0xC) != 0) {
                            D_8010AB02_1AC3A2_BallonBurst = 8;
                            InitFadeOut(0, 0x14);
                            D_8010A770_1AC010_BallonBurst = 0x14;
                            gPlayers[D_8010AAFC_1AC39C_BallonBurst[0]].coins_mg_bonus += 10;
                            gPlayers[D_8010AAFC_1AC39C_BallonBurst[1]].coins_mg_bonus += 10;
                        } else {
                            D_8010AB02_1AC3A2_BallonBurst = 3;
                            D_8010A770_1AC010_BallonBurst = 0xA8;
                            gPlayers[D_8010AAFC_1AC39C_BallonBurst[0]].coins_mg_bonus += 10;
                            gPlayers[D_8010AAFC_1AC39C_BallonBurst[1]].coins_mg_bonus += 10;
                            if (D_8010A900_1AC1A0_BallonBurst == 0 && D_801011FC_101DFC == 0) {
                                PlayMusic(0x52);
                            }
                            func_800691FC_69DFC(0x11, D_8010A5F0_1ABE90_BallonBurst[D_8010AAFC_1AC39C_BallonBurst[0]]->character, D_8010A5F0_1ABE90_BallonBurst[D_8010AAFC_1AC39C_BallonBurst[1]]->character);
                        }
                    case 3:
                        if (D_8010A770_1AC010_BallonBurst <= 0) {
                        fade:
                            D_8010AB02_1AC3A2_BallonBurst = 8;
                            InitFadeOut(0, 0x14);
                            D_8010A770_1AC010_BallonBurst = 0x14;
                            break;
                        }
                        if (D_8010A770_1AC010_BallonBurst == 0xA8) {
                            s32 voice[6] = { 2, 3, 7, 4, 5, 6 };

                            w = D_8010A5F0_1ABE90_BallonBurst[D_8010AAFC_1AC39C_BallonBurst[0]];
                            o = &D_8010AAB0_1AC350_BallonBurst[D_8010AAFC_1AC39C_BallonBurst[0]];
                            func_80029BF0_2A7F0(*(*o)->model, func_80029E14_2AA14((*o)->model[3]), 0, 4, 0);
                            func_800732B0_73EB0((voice[w->character] << 0x10) | ((w->unk_0A == 0) ? 0x4F : 0x4E));
                            w = D_8010A5F0_1ABE90_BallonBurst[D_8010AAFC_1AC39C_BallonBurst[1]];
                            o = &D_8010AAB0_1AC350_BallonBurst[D_8010AAFC_1AC39C_BallonBurst[1]];
                            func_80029BF0_2A7F0(*(*o)->model, func_80029E14_2AA14((*o)->model[3]), 0, 4, 0);
                            func_800732B0_73EB0((voice[w->character] << 0x10) | ((w->unk_0A == 0) ? 0x4F : 0x4E));
                        }
                    }
            }
            break;
        case 8:
            if (D_8010A770_1AC010_BallonBurst <= 0) {
                D_8010A900_1AC1A0_BallonBurst = 1;
                D_8010A770_1AC010_BallonBurst = 0;
            }
            break;
        }
    }
    if (D_8010A708_1ABFA8_BallonBurst[0] > 300.0f) {
        D_8010A708_1ABFA8_BallonBurst[0] = 300.0f;
    }
    if (D_8010A708_1ABFA8_BallonBurst[1] > 300.0f) {
        D_8010A708_1ABFA8_BallonBurst[1] = 300.0f;
    }
    D_800FA610_FB210 = D_8010A710_1ABFB0_BallonBurst * 14.25 + 1436.705444;
    view->sy = view->sx = 1.0 / ((D_800FA610_FB210 - 1436.705444) / 4206.0 + 1.0);
    D_8010274C_10334C.x = D_8010A758_1ABFF8_BallonBurst + 7.0;
    D_8010274C_10334C.y = D_8010AA90_1AC330_BallonBurst + 50.846 - 0.0;
    view->ox = (D_8010274C_10334C.x - 7.0) * 0.216797 * view->sx;
    view->oy = (D_8010274C_10334C.y - 50.846) * 0.216797 * -view->sy;
    SprPosSet(D_8010A6CC_1ABF6C_BallonBurst, 0,
              (s16)((f32)D_80109D9C_1AB63C_BallonBurst[D_8010AB00_1AC3A0_BallonBurst][0] * 0.5 + 160.4 - (s16)(view->sx * ((D_8010AB02_1AC3A2_BallonBurst == 0) ? 24.1625 : 24.4125) + view->ox)
                    + (D_8010AB02_1AC3A2_BallonBurst == 5 && D_8010A770_1AC010_BallonBurst >= 0x10) + (((u16)D_8010AB00_1AC3A0_BallonBurst - 0x20U < 3) ? 1.0 : 0.0)),
              (s16)((f32)D_80109D9C_1AB63C_BallonBurst[D_8010AB00_1AC3A0_BallonBurst][1] * 0.5 + (s16)(view->sy * 58.125 + 122.5 - view->oy)));
    SprPosSet(D_8010A6D2_1ABF72_BallonBurst, 0,
              (s16)((f32)D_80109D9C_1AB63C_BallonBurst[D_8010AB00_1AC3A0_BallonBurst][2] * 0.5 + (s16)(view->sx * ((D_8010AB02_1AC3A2_BallonBurst == 0) ? 25.8875 : 25.1375) + 158.35 - view->ox)
                    + (D_8010AB02_1AC3A2_BallonBurst == 5 && D_8010A770_1AC010_BallonBurst >= 0x10) + (((u16)D_8010AB00_1AC3A0_BallonBurst - 0x1DU < 6) ? 1.0 : 0.0)),
              (s16)((f32)D_80109D9C_1AB63C_BallonBurst[D_8010AB00_1AC3A0_BallonBurst][3] * 0.5 + (s16)(view->sy * 58.125 + 122.5 - view->oy) + 0.0));
    SprScaleSet(D_8010A6CC_1ABF6C_BallonBurst, 0, view->sx, view->sy);
    SprScaleSet(D_8010A6D2_1ABF72_BallonBurst, 0, view->sx, view->sy);
    bcopy(view, &D_8010AAC8_1AC368_BallonBurst, sizeof(BBView));
    D_8010A714_1ABFB4_BallonBurst[1] = D_8010A714_1ABFB4_BallonBurst[0] = 0;
    if ((func_80078EA8_79AA8() & 0xFFFF) + D_80102720_103320 == 0) {
        D_8010A770_1AC010_BallonBurst--;
        D_8010A760_1AC000_BallonBurst++;
    }
    t = ((D_8010A708_1ABFA8_BallonBurst[1] < D_8010A708_1ABFA8_BallonBurst[0]) ? D_8010A708_1ABFA8_BallonBurst[0] : D_8010A708_1ABFA8_BallonBurst[1]) / 6.0f;
    if ((func_80078EA8_79AA8() & 0xFFFF) + D_80102720_103320 == 0) {
        if (D_8010AB02_1AC3A2_BallonBurst == 5 && D_8010A770_1AC010_BallonBurst >= 0x10) {
            D_8010A710_1ABFB0_BallonBurst = (f32)((rand8() & 0xFF) % (((D_8010A770_1AC010_BallonBurst - 0xF) * 0xC8) / 30)) * -0.5;
            D_8010A758_1ABFF8_BallonBurst = (f32)((rand8() & 0xFF) % (((D_8010A770_1AC010_BallonBurst - 0xF) * 0xC8) / 30)) * 0.6 - 0.3;
            D_8010AA90_1AC330_BallonBurst = (f32)((rand8() & 0xFF) % (((D_8010A770_1AC010_BallonBurst - 0xF) * 0xC8) / 30)) * 0.6 - 0.3 + D_8010A710_1ABFB0_BallonBurst * 1.125;
        } else if (D_8010AB02_1AC3A2_BallonBurst == 0 && D_8010A770_1AC010_BallonBurst >= 0x31) {
            f32 a = (f32)(D_8010A770_1AC010_BallonBurst - 0x30) / 12.0f;
            f32 b = (a * a * a * a + a) * 0.5;

            D_8010A710_1ABFB0_BallonBurst = -(45.0 - b * 30.0);
            D_8010A758_1ABFF8_BallonBurst = 0.0f;
            e = (f32)D_8010A770_1AC010_BallonBurst / 30.0f - 1.0;
            D_8010AA90_1AC330_BallonBurst = D_8010A710_1ABFB0_BallonBurst * 1.125 + e * e * 50.0 * 0.0;
        } else if (D_8010AB02_1AC3A2_BallonBurst == 2 && D_8010A770_1AC010_BallonBurst >= 0x1F) {
            f32 a = (f32)(D_8010A770_1AC010_BallonBurst - 0x1E) / 30.0f;

            a = a * a;
            a = a * a;
            a = a * a;
            func_8002D0A0_2DCA0(*D_8010AA98_1AC338_BallonBurst[D_8010AAC0_1AC360_BallonBurst * 2]->model, a * 255.0);
            func_8002D0A0_2DCA0(*D_8010AA98_1AC338_BallonBurst[D_8010AAC0_1AC360_BallonBurst * 2 + 1]->model, a * 255.0);
        } else if (D_8010AB02_1AC3A2_BallonBurst == 6 && D_8010A770_1AC010_BallonBurst >= 0x5B) {
            f32 a = (f32)(D_8010A770_1AC010_BallonBurst - 0x5A) / 30.0f;

            a = a * a;
            e = (a * a) * 255.0;
            for (i = 0; i < 4; i++) {
                func_8002D0A0_2DCA0(*D_8010AA98_1AC338_BallonBurst[i]->model, e);
            }
        } else {
            if ((s16)(D_8010AB00_1AC3A0_BallonBurst / 7) < (s16)((t - 25.0) / 4.5) && t < 50.0) {
                D_8010AB00_1AC3A0_BallonBurst++;
            }
            if (D_8010AB00_1AC3A0_BallonBurst % 7 != 0) {
                f32 a = (f32)(D_8010AB00_1AC3A0_BallonBurst % 7) / 7.0f;
                f32 b = 1.0 - a;

                D_8010A710_1ABFB0_BallonBurst = (f32)(s16)(D_8010AB00_1AC3A0_BallonBurst / 7) * 9.0 + -45.0 + (f32)((1.0 - b * b * b + a) * 0.5) * 9.0;
            } else {
                D_8010A710_1ABFB0_BallonBurst = (f32)(s16)(D_8010AB00_1AC3A0_BallonBurst / 7) * 9.0 + -45.0;
            }
            D_8010A758_1ABFF8_BallonBurst = 0.0f;
            D_8010AA90_1AC330_BallonBurst = D_8010A710_1ABFB0_BallonBurst * 1.125;
        }
    }
    D_800FA610_FB210 = D_8010A710_1ABFB0_BallonBurst * 37.5 + 7528.0;
    view->sy = view->sx = 1.0 / ((D_800FA610_FB210 - 1436.705444) / 4846.0 + 1.0);
    D_8010274C_10334C.x = D_8010A758_1ABFF8_BallonBurst * 0.88 + 7.0;
    D_8010274C_10334C.y = D_8010AA90_1AC330_BallonBurst + 50.846 - 632.0;
    view->ox = (D_8010274C_10334C.x - 7.0) * 0.256836 * view->sx;
    view->oy = (D_8010274C_10334C.y - 50.846) * 0.256836 * -view->sy;
    Hu3DCamSetPositionOrientation(0, &eye, &at, &up);
    D_800FA610_FB210 = D_8010A710_1ABFB0_BallonBurst * 14.25 + 1436.705444;
    view->sy = view->sx = 1.0 / ((D_800FA610_FB210 - 1436.705444) / 4206.0 + 1.0);
    D_8010274C_10334C.x = D_8010A758_1ABFF8_BallonBurst + 7.0;
    D_8010274C_10334C.y = D_8010AA90_1AC330_BallonBurst + 50.846 - 0.0;
    view->ox = (D_8010274C_10334C.x - 7.0) * 0.216797 * view->sx;
    view->oy = (D_8010274C_10334C.y - 50.846) * 0.216797 * -view->sy;
    D_800FA610_FB210 = D_8010A710_1ABFB0_BallonBurst * 37.5 + 7528.0;
    D_8010274C_10334C.x = D_8010A758_1ABFF8_BallonBurst * 0.88 + 7.0;
    D_8010274C_10334C.y = D_8010AA90_1AC330_BallonBurst * 0.92 + 50.846 - 632.0;
}
#else
__asm__(".section .rodata");
const u32 D_80109E88_1AB728_BallonBurst[6] = { 0x00000002, 0x00000003, 0x00000007, 0x00000004, 0x00000005, 0x00000006 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1B_BallonBurst/1A40A0", func_80103C10_1A54B0_BallonBurst);
#endif

__asm__(".section .rodata");
const u32 D_8010A0E8_1AB988_BallonBurst[1] = { 0x4042C000 };

__asm__(".section .rodata");
const char D_8010A0EC_1AB98C_BallonBurst[] = "";

__asm__(".section .rodata");
const u32 D_8010A0F0_1AB990_BallonBurst[1] = { 0x40BD6800 };

__asm__(".section .rodata");
const char D_8010A0F4_1AB994_BallonBurst[] = "";

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010A0F8_1AB998_BallonBurst[2] = { 0x409672D2, 0x5FE974A3 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010A100_1AB9A0_BallonBurst[2] = { 0x40B2EE00, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010A108_1AB9A8_BallonBurst[2] = { 0x3FF00000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010A110_1AB9B0_BallonBurst[2] = { 0x3FEC28F5, 0xC28F5C29 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010A118_1AB9B8_BallonBurst[2] = { 0x401C0000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010A120_1AB9C0_BallonBurst[2] = { 0x40496C49, 0xBA5E353F };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010A128_1AB9C8_BallonBurst[2] = { 0x4083C000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010A130_1AB9D0_BallonBurst[2] = { 0x3FD07000, 0x431BDE83 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010A138_1AB9D8_BallonBurst[2] = { 0x402C8000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010A140_1AB9E0_BallonBurst[2] = { 0x40B06E00, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010A148_1AB9E8_BallonBurst[2] = { 0x3FCBC001, 0x0C6F7A0B };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010A150_1AB9F0_BallonBurst[2] = { 0x3FEC28F5, 0xC28F5C29 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010A158_1AB9F8_BallonBurst[2] = { 0x3FED70A3, 0xD70A3D71 };

void func_8010644C_1A7CEC_BallonBurst(void) {
}

void func_80106454_1A7CF4_BallonBurst(Gfx** gfx, s32 arg1, s32 arg2) {
    SprExec(gfx, arg1, arg2);
    {
        Gfx* g = D_800FDBCC_FE7CC++;

        g->words.w0 = 0xEE000000;
        g->words.w1 = 0x7FFF7FFF;
    }
    func_8007A7FC_7B3FC(&D_8010AAC8_1AC368_BallonBurst);
}

void func_801064A4_1A7D44_BallonBurst(omObjData* obj) {
    func_80106514_1A7DB4_BallonBurst(obj, 0);
}

void func_801064C0_1A7D60_BallonBurst(omObjData* obj) {
    func_80106514_1A7DB4_BallonBurst(obj, 1);
}

void func_801064DC_1A7D7C_BallonBurst(omObjData* obj) {
    func_80106514_1A7DB4_BallonBurst(obj, 2);
}

void func_801064F8_1A7D98_BallonBurst(omObjData* obj) {
    func_80106514_1A7DB4_BallonBurst(obj, 3);
}

void func_80106514_1A7DB4_BallonBurst(omObjData* obj, s32 player) {
    BBWork* work;
    s32 dir;
    s32 file;
    s16 j;
    s32 slot;
    s32 attr;

    work = func_80027154_27D54(sizeof(BBWork), 0x7918);
    obj->unk_50 = work;
    D_8010A5F0_1ABE90_BallonBurst[player] = work;
    slot = func_80109B70_1AB410_BallonBurst(player);
    D_8010A5F0_1ABE90_BallonBurst[player]->player = player;
    D_8010A5F0_1ABE90_BallonBurst[player]->group = gPlayers[player].group;
    D_8010A5F0_1ABE90_BallonBurst[player]->slot = slot;
    D_8010A5F0_1ABE90_BallonBurst[player]->character = gPlayers[player].character;
    D_8010A5F0_1ABE90_BallonBurst[player]->port = gPlayers[player].port;
    D_8010A5F0_1ABE90_BallonBurst[player]->cpu = (gPlayers[player].flags & 1) ? gPlayers[player].cpu_difficulty : -1;
    D_8010A5F0_1ABE90_BallonBurst[player]->unk_06 = 0;
    D_8010A5F0_1ABE90_BallonBurst[player]->unk_07 = 0;
    D_8010A5F0_1ABE90_BallonBurst[player]->unk_08 = 0;
    D_8010A5F0_1ABE90_BallonBurst[player]->unk_0A = rand8() & 1;
    D_8010A5F0_1ABE90_BallonBurst[player]->unk_0B = 0;
    D_8010A5F0_1ABE90_BallonBurst[player]->unk_0C = -1;
    if (!(player & 1)) {
        for (j = 0; j < 0x31; j++) {
            D_8010A908_1AC1A8_BallonBurst[player / 2][j] = 0;
            D_8010A778_1AC018_BallonBurst[player / 2][j] = 0;
        }
    }
    D_8010A5F0_1ABE90_BallonBurst[player]->unk_09 = 0;
    dir = D_800CD438_CE038[gPlayers[player].character].dir;
    obj->model[0] = LoadFormFile(dir | D_800CD438_CE038[gPlayers[player].character].model, 0x20489);
    obj->model[1] = LoadFormFile(1, 0x489);
    obj->model[2] = LoadFormFile(dir | 0x15, attr = 0x2048D);
    file = dir | 0x4E;
    if (D_8010A5F0_1ABE90_BallonBurst[player]->unk_0A == 0) {
        file = dir | 0x4F;
    }
    obj->model[3] = LoadFormFile(file, attr);
    obj->model[4] = LoadFormFile(dir | 0x16, attr);
    obj->model[5] = LoadFormFile(dir | 0x14, attr);
    obj->model[6] = LoadFormFile(dir, attr);
    func_80029B80_2A780(obj->model[0], obj->model[2]);
    omSetTra(obj, D_80109D30_1AB5D0_BallonBurst[(u16)slot].x - 3.0 + ((D_8010A5F0_1ABE90_BallonBurst[player]->character == 5) ? 7.0 : 0.0) + D_80109C88_1AB528_BallonBurst[gPlayers[player].character],
             D_80109D30_1AB5D0_BallonBurst[(u16)slot].y + D_80109CA0_1AB540_BallonBurst[gPlayers[player].character] + 1.0f,
             D_80109D30_1AB5D0_BallonBurst[(u16)slot].z + ((D_8010A5F0_1ABE90_BallonBurst[player]->character == 5) ? 45.0 : 0.0));
    omSetSca(obj, 0.9f, 0.9f, 0.9f);
    func_80029714_2A314(obj->model[1], (D_80109D30_1AB5D0_BallonBurst[(u16)slot].x + ((D_8010A5F0_1ABE90_BallonBurst[player]->character == 5) ? 7.0 : 0.0) + D_80109C88_1AB528_BallonBurst[gPlayers[player].character]) * 0.97,
                        D_80109D30_1AB5D0_BallonBurst[(u16)slot].y - 8.0 + 1.0 + 85.0,
                        D_80109D30_1AB5D0_BallonBurst[(u16)slot].z + 0.0 + 300.0);
    func_800297E8_2A3E8(obj->model[1], 1.0f, 1.0f, 1.5f);
    HmfModelObjAttrSet(obj->model[0], 0x600, 0x600);
    obj->func_ptr = func_80106AEC_1A838C_BallonBurst;
    omSetStatBit(obj, 0xA0);
}

/* A player's object: the CPU press script, the pump, the team's balloon, hose and bang. NON_MATCHING:
   the C follows retail's calls, constants and branches; what is left is block layout and register
   allocation around the repeated blends (class: register residue, docs/DECOMP_WALLS.md). */
#ifdef NON_MATCHING
void func_80106AEC_1A838C_BallonBurst(omObjData* obj) {
    BBWork* w;
    s8 seat;
    s8 pl;
    s32 a;
    s32 b;
    s32 c;
    s16 k;
    s32 i;
    s32 j;
    s32 s;
    f32 t;
    f32 q;
    f32 r;
    f32 f;
    f32 v;
    f32 x;
    f32 y;
    f64 e;
    f64 g;
    omObjData* o;
    f32* p;

    a = 0;
    b = 0;
    w = obj->unk_50;
    seat = (u8)D_8010A714_1ABFB4_BallonBurst[w->group] + w->group * 2;
    pl = w->player;
    if (pl == 3 && (func_80078EA8_79AA8() & 0xFFFF) + D_80102720_103320 != 0 && D_8010AB02_1AC3A2_BallonBurst == 5) {
        t = (f32)D_8010A770_1AC010_BallonBurst / 30.0f;
        q = (t > 0.5) ? 0.0f : (f32)(2.0 * (0.5 - t));
        if (q < 0.0) {
            q = 0.0f;
        }
        o = (D_8010AAC0_1AC360_BallonBurst != 0) ? D_8010A728_1ABFC8_BallonBurst : D_8010A6F8_1ABF98_BallonBurst;
        t = (1.0 - t * t * t) * 1.5;
        func_8002AC10_2B810(*o->model, q, t * 5.0 + 1.0, 2);
        t = t * 360.0;
        D_800CA02C_CAC2C = t - (s16)((s32)t / 360) * 360.0;
    }
    if ((func_80078EA8_79AA8() & 0xFFFF) + D_80102720_103320 == 0) {
        w->unk_0B = (w->unk_0B >= 0x31) ? w->unk_0B : w->unk_0B + 2;
        if (w->unk_0B >= 0x31) {
            w->unk_0B = 0x30;
        }
        s = D_8010AB02_1AC3A2_BallonBurst;
        if (s == 5 && w->group != D_8010AAC0_1AC360_BallonBurst && _CheckFlag(0xC) == 0) {
            omSetTra(D_8010AAB0_1AC350_BallonBurst[pl], D_80109D30_1AB5D0_BallonBurst[seat].x + 0.0, D_80109D30_1AB5D0_BallonBurst[seat].y + ((w->character == s) ? -9.0 : 0.0) + ((w->group != D_8010AAC0_1AC360_BallonBurst) ? D_8010A6C8_1ABF68_BallonBurst * 10.0 : 0.0), D_80109D30_1AB5D0_BallonBurst[seat].z);
            omSetSca(D_8010A748_1ABFE8_BallonBurst[seat], 0.0f, 0.0f, 0.0f);
        }
        if (D_8010AB02_1AC3A2_BallonBurst == 1) {
            switch ((s8)(w->cpu + 1)) {
            case 1:
                switch (D_8010A730_1ABFD0_BallonBurst[pl][0]) {
                case 0:
                    D_8010A730_1ABFD0_BallonBurst[pl][0]++;
                    D_8010A730_1ABFD0_BallonBurst[pl][1] = (rand8() & 7 & 0xFF) + 2;
                case 1:
                    if (--D_8010A730_1ABFD0_BallonBurst[pl][1] != 0) {
                        break;
                    }
                    D_8010A730_1ABFD0_BallonBurst[pl][0]++;
                    D_8010A730_1ABFD0_BallonBurst[pl][1] = (rand8() & 1) + 4;
                case 2:
                    if (--D_8010A730_1ABFD0_BallonBurst[pl][1] != 0) {
                        a = 1;
                        break;
                    }
                    D_8010A730_1ABFD0_BallonBurst[pl][0]++;
                    D_8010A730_1ABFD0_BallonBurst[pl][1] = (rand8() & 1) + 2;
                case 3:
                    if (--D_8010A730_1ABFD0_BallonBurst[pl][1] != 0) {
                        break;
                    }
                    D_8010A730_1ABFD0_BallonBurst[pl][0]++;
                    D_8010A730_1ABFD0_BallonBurst[pl][1] = (rand8() & 1) + 4;
                case 4:
                    if (--D_8010A730_1ABFD0_BallonBurst[pl][1] != 0) {
                        b = 1;
                        break;
                    }
                    D_8010A730_1ABFD0_BallonBurst[pl][0]++;
                    D_8010A730_1ABFD0_BallonBurst[pl][1] = (rand8() & 1) + 2;
                case 5:
                    if (--D_8010A730_1ABFD0_BallonBurst[pl][1] == 0) {
                        D_8010A730_1ABFD0_BallonBurst[pl][0] = 2;
                        D_8010A730_1ABFD0_BallonBurst[pl][1] = (rand8() % 3 & 0xFF) + 4;
                    }
                    break;
                }
                break;
            case 2:
                switch (D_8010A730_1ABFD0_BallonBurst[pl][0]) {
                case 0:
                    D_8010A730_1ABFD0_BallonBurst[pl][0]++;
                    D_8010A730_1ABFD0_BallonBurst[pl][1] = (rand8() & 3 & 0xFF) + 2;
                case 1:
                    if (--D_8010A730_1ABFD0_BallonBurst[pl][1] != 0) {
                        break;
                    }
                    D_8010A730_1ABFD0_BallonBurst[pl][0]++;
                    D_8010A730_1ABFD0_BallonBurst[pl][1] = (rand8() & 1) + 5;
                case 2:
                    if (--D_8010A730_1ABFD0_BallonBurst[pl][1] != 0) {
                        a = 1;
                        break;
                    }
                    D_8010A730_1ABFD0_BallonBurst[pl][0]++;
                    D_8010A730_1ABFD0_BallonBurst[pl][1] = (rand8() & 1) + 2;
                case 3:
                    if (--D_8010A730_1ABFD0_BallonBurst[pl][1] != 0) {
                        break;
                    }
                    D_8010A730_1ABFD0_BallonBurst[pl][0]++;
                    D_8010A730_1ABFD0_BallonBurst[pl][1] = (rand8() & 1) + 5;
                case 4:
                    if (--D_8010A730_1ABFD0_BallonBurst[pl][1] != 0) {
                        b = 1;
                        break;
                    }
                    D_8010A730_1ABFD0_BallonBurst[pl][0]++;
                    D_8010A730_1ABFD0_BallonBurst[pl][1] = (rand8() & 1) + 2;
                case 5:
                    if (--D_8010A730_1ABFD0_BallonBurst[pl][1] == 0) {
                        D_8010A730_1ABFD0_BallonBurst[pl][0] = 2;
                        D_8010A730_1ABFD0_BallonBurst[pl][1] = ((rand8() % 5 & 0xFF) >> 1) + 5;
                    }
                    break;
                }
                break;
            case 3:
                switch (D_8010A730_1ABFD0_BallonBurst[pl][0]) {
                case 0:
                    D_8010A730_1ABFD0_BallonBurst[pl][0] = 2;
                    D_8010A730_1ABFD0_BallonBurst[pl][1] = 6;
                    break;
                case 2:
                    if (--D_8010A730_1ABFD0_BallonBurst[pl][1] != 0) {
                        a = 1;
                        break;
                    }
                    D_8010A730_1ABFD0_BallonBurst[pl][0]++;
                    D_8010A730_1ABFD0_BallonBurst[pl][1] = (rand8() % 3 & 0xFF) + 1;
                case 3:
                    if (--D_8010A730_1ABFD0_BallonBurst[pl][1] != 0) {
                        break;
                    }
                    D_8010A730_1ABFD0_BallonBurst[pl][0]++;
                    D_8010A730_1ABFD0_BallonBurst[pl][1] = ((rand8() % 30 & 0xFF) * 6) / 100;
                case 4:
                    if (D_8010A730_1ABFD0_BallonBurst[pl][1] < w->unk_06) {
                        b = 1;
                        break;
                    }
                    D_8010A730_1ABFD0_BallonBurst[pl][0]++;
                    D_8010A730_1ABFD0_BallonBurst[pl][1] = (rand8() % 3 & 0xFF) + 1;
                case 5:
                    if (--D_8010A730_1ABFD0_BallonBurst[pl][1] == 0) {
                        D_8010A730_1ABFD0_BallonBurst[pl][0] = 2;
                        D_8010A730_1ABFD0_BallonBurst[pl][1] = (rand8() & 1) + 5;
                    }
                    break;
                }
                break;
            case 4:
                switch (D_8010A730_1ABFD0_BallonBurst[pl][0]) {
                case 0:
                    D_8010A730_1ABFD0_BallonBurst[pl][0] = 2;
                    D_8010A730_1ABFD0_BallonBurst[pl][1] = (((rand8() % 5 & 0xFF) + 0x5F) * 6) / 100;
                case 2:
                    if (w->unk_06 < D_8010A730_1ABFD0_BallonBurst[pl][1]) {
                        a = 1;
                        break;
                    }
                    D_8010A730_1ABFD0_BallonBurst[pl][0]++;
                    D_8010A730_1ABFD0_BallonBurst[pl][1] = (rand8() & 1) + 1;
                case 3:
                    if (--D_8010A730_1ABFD0_BallonBurst[pl][1] != 0) {
                        break;
                    }
                    D_8010A730_1ABFD0_BallonBurst[pl][0]++;
                    D_8010A730_1ABFD0_BallonBurst[pl][1] = ((rand8() % 9 & 0xFF) * 6) / 100;
                case 4:
                    if (D_8010A730_1ABFD0_BallonBurst[pl][1] < w->unk_06) {
                        b = 1;
                        break;
                    }
                    D_8010A730_1ABFD0_BallonBurst[pl][0]++;
                    D_8010A730_1ABFD0_BallonBurst[pl][1] = (rand8() & 1) + 1;
                case 5:
                    if (--D_8010A730_1ABFD0_BallonBurst[pl][1] == 0) {
                        D_8010A730_1ABFD0_BallonBurst[pl][0] = 2;
                        D_8010A730_1ABFD0_BallonBurst[pl][1] = (((rand8() % 12 & 0xFF) + 0x58) * 6) / 100;
                    }
                    break;
                }
                break;
            case 0:
                a = (u16)ContBtn[w->port] >> 0xF;
                b = (ContBtn[w->port] & 0x6000) != 0;
                break;
            }
            if (b & a) {
                if (w->unk_08 >= 2) {
                    a = 0;
                } else {
                    b = 0;
                }
            }
            if (a != 0 && w->unk_06 < 6) {
                if (w->unk_08 > 0) {
                    if (w->unk_08 >= 2) {
                        c = D_8010A724_1ABFC4_BallonBurst[pl];
                        p = &D_8010A6D8_1ABF78_BallonBurst[pl];
                        if (c < 0xA) {
                            *p = *p * (1.0 - (f32)(1.0 - (f32)(1.0 - (f32)c / 10.0f)));
                        } else {
                            *p = 0.0f;
                        }
                    } else {
                        c = D_8010A724_1ABFC4_BallonBurst[pl];
                        if (c >= 5) {
                            e = w->unk_07 * 0.6 + 0.4;
                        } else {
                            t = 1.0 - (f32)(1.0 - (f32)c / 5.0f);
                            e = (w->unk_07 * 0.6 + 0.4) * t + D_8010A6D8_1ABF78_BallonBurst[pl] * (1.0 - t);
                        }
                        D_8010A6D8_1ABF78_BallonBurst[pl] = e;
                    }
                    D_8010A724_1ABFC4_BallonBurst[pl] = 0;
                    w->unk_07 = (w->unk_06 == 0);
                    w->unk_0B = 0x16;
                    if (w->unk_08 >= 2) {
                        if (w->unk_0C != -1) {
                            func_80079848_7A448(w->unk_0C);
                        }
                        w->unk_0C = func_80079798_7A398(0x210, pl);
                        func_800796F0_7A2F0(w->unk_0C, ((rand8() * 4 + rand8()) % 1001) - 0x258);
                        func_800798F8_7A4F8(w->unk_0C, D_80109C80_1AB520_BallonBurst[seat]);
                    }
                    if (w->unk_08 == 1) {
                        w->unk_07 = 0;
                    }
                }
                w->unk_0B--;
                t = w->unk_07 + 1;
                if (D_8010A778_1AC018_BallonBurst[w->group][w->unk_0B] < t) {
                    D_8010A778_1AC018_BallonBurst[w->group][w->unk_0B] = t;
                }
                w->unk_06++;
                w->unk_08 = 0;
                D_8010A908_1AC1A8_BallonBurst[w->group][0x15] += (w->unk_07 != 0) ? 1.25 : 0.5;
            } else {
                if (w->unk_08 == 0 && (b == 0 || w->unk_06 <= 0)) {
                    w->unk_08 = 1;
                }
                w->unk_0B = 0x16;
            }
            if (b != 0 && w->unk_06 > 0) {
                if (w->unk_08 < 2) {
                    c = D_8010A724_1ABFC4_BallonBurst[pl];
                    if (c >= 5) {
                        e = w->unk_07 * 0.6 + 0.4;
                    } else {
                        t = 1.0 - (f32)(1.0 - (f32)c / 5.0f);
                        e = (w->unk_07 * 0.6 + 0.4) * t + D_8010A6D8_1ABF78_BallonBurst[pl] * (1.0 - t);
                    }
                    D_8010A6D8_1ABF78_BallonBurst[pl] = e;
                    D_8010A724_1ABFC4_BallonBurst[pl] = 0;
                    if (w->unk_0C != -1) {
                        func_80079848_7A448(w->unk_0C);
                    }
                    w->unk_0C = func_80079798_7A398(0x20F, pl);
                    func_800796F0_7A2F0(w->unk_0C, ((rand8() * 4 + rand8()) % 1001) - 0x258);
                    func_800798F8_7A4F8(w->unk_0C, D_80109C80_1AB520_BallonBurst[seat]);
                }
                w->unk_06--;
                w->unk_08 = 3;
            } else if (w->unk_08 == 3 && (a == 0 || w->unk_06 >= 6)) {
                w->unk_08 = 2;
            }
            if (w->unk_06 == 0 && D_8010AB02_1AC3A2_BallonBurst == 1) {
                D_8010A6CE_1ABF6E_BallonBurst[pl] = (D_8010A6CE_1ABF6E_BallonBurst[pl] == 0);
                if (D_8010A6CE_1ABF6E_BallonBurst[pl] != 0) {
                    func_8002CD78_2D978(*D_8010A748_1ABFE8_BallonBurst[seat]->model, 0x40, 0x40, 0x40, 0);
                    func_8002CDB4_2D9B4(*D_8010A748_1ABFE8_BallonBurst[seat]->model, 0, 0, 0, 0);
                } else {
                    func_8002CD78_2D978(*D_8010A748_1ABFE8_BallonBurst[seat]->model, 0, 0, 0, 0);
                    func_8002CDB4_2D9B4(*D_8010A748_1ABFE8_BallonBurst[seat]->model, 0x10, 0x10, 0x10, 0);
                }
            } else if (w->unk_08 == 0 && w->unk_07 != 0 && w->unk_06 < 3 && D_8010AB02_1AC3A2_BallonBurst == 1) {
                if (w->unk_06 != D_8010A6CE_1ABF6E_BallonBurst[pl]) {
                    t = 1.0 - (f32)w->unk_06 / 3.0;
                    func_8002CD78_2D978(*D_8010A748_1ABFE8_BallonBurst[seat]->model, t * 64.0, t * 64.0, t * 64.0, 0);
                    func_8002CDB4_2D9B4(*D_8010A748_1ABFE8_BallonBurst[seat]->model, 0, 0, 0, 0);
                } else {
                    func_8002CD78_2D978(*D_8010A748_1ABFE8_BallonBurst[seat]->model, 0, 0, 0, 0);
                    func_8002CDB4_2D9B4(*D_8010A748_1ABFE8_BallonBurst[seat]->model, 0x10, 0x10, 0x10, 0);
                }
            } else {
                D_8010A6CE_1ABF6E_BallonBurst[pl] = 0;
                func_8002CD78_2D978(*D_8010A748_1ABFE8_BallonBurst[seat]->model, 0, 0, 0, 0);
                func_8002CDB4_2D9B4(*D_8010A748_1ABFE8_BallonBurst[seat]->model, 0, 0, 0, 0);
            }
        }
        if (D_8010AB02_1AC3A2_BallonBurst < 2 || ((D_8010AB02_1AC3A2_BallonBurst == 4) | (D_8010AB02_1AC3A2_BallonBurst == 7))) {
            j = 0;
            if (D_8010A724_1ABFC4_BallonBurst[pl] < 0x32 && w->unk_08 != 1) {
                j = (D_8010AB02_1AC3A2_BallonBurst == 1) | (D_8010AB02_1AC3A2_BallonBurst == 7);
            }
            D_8010A724_1ABFC4_BallonBurst[pl] += j;
            if (w->unk_08 >= 2) {
                c = D_8010A724_1ABFC4_BallonBurst[pl];
                if (c < 0xA) {
                    t = 90.0 - D_8010A6D8_1ABF78_BallonBurst[pl] * (1.0 - (f32)(1.0 - (f32)(1.0 - (f32)c / 10.0f))) * 180.0;
                } else {
                    t = 90.0f;
                }
                omSetRot(D_8010A6E8_1ABF88_BallonBurst[seat], 0.0f, 0.0f, t);
            } else {
                c = D_8010A724_1ABFC4_BallonBurst[pl];
                if (c >= 5) {
                    e = 90.0 - (w->unk_07 * 0.6 + 0.4) * 180.0;
                } else {
                    t = 1.0 - (f32)(1.0 - (f32)c / 5.0f);
                    e = 90.0 - ((w->unk_07 * 0.6 + 0.4) * t + D_8010A6D8_1ABF78_BallonBurst[pl] * (1.0 - t)) * 180.0;
                }
                omSetRot(D_8010A6E8_1ABF88_BallonBurst[seat], 0.0f, 0.0f, e);
            }
            func_80029C74_2A874(*D_8010A748_1ABFE8_BallonBurst[seat]->model, ((f32)w->unk_06 / 6.0f) * 12.5 + 0.0);
            func_80029C74_2A874(*obj->model, ((f32)w->unk_06 / 6.0f) * (15.0 - D_80109D18_1AB5B8_BallonBurst[w->character]) + D_80109D00_1AB5A0_BallonBurst[w->character]);
        }
        if (seat % 2 == 1) {
            f = (f32)(u32)D_8010A760_1AC000_BallonBurst - (f32)(D_8010A760_1AC000_BallonBurst / 360);
            t = D_8010A708_1ABFA8_BallonBurst[w->group];
            if (t == 0.0f) {
                r = 0.0f;
                if (!(t < 30.0)) {
                    r = (D_8010A708_1ABFA8_BallonBurst[w->group] / 6.0f - 5.0) * 0.4;
                }
            } else {
                r = 1.0f;
            }
            if (w->group != D_8010AAC0_1AC360_BallonBurst) {
                D_8010A764_1AC004_BallonBurst[w->group] += (D_8010A708_1ABFA8_BallonBurst[w->group] - 10.0) / 100.0;
                D_8010A764_1AC004_BallonBurst[w->group] = (D_8010A764_1AC004_BallonBurst[w->group] < 0.0) ? 0.0f : (D_8010A764_1AC004_BallonBurst[w->group] > 20.0) ? 20.0f : D_8010A764_1AC004_BallonBurst[w->group];
                D_8010A718_1ABFB8_BallonBurst[w->group] += D_8010A764_1AC004_BallonBurst[w->group];
                D_8010A718_1ABFB8_BallonBurst[w->group] = (D_8010A718_1ABFB8_BallonBurst[w->group] < 0.0) ? 0.0f : (D_8010A718_1ABFB8_BallonBurst[w->group] > 150.0) ? 150.0f : D_8010A718_1ABFB8_BallonBurst[w->group];
                e = 1.0 - (D_8010A708_1ABFA8_BallonBurst[w->group] / 6.0f) / 50.0;
                D_8010A718_1ABFB8_BallonBurst[w->group] = 110.0 - e * e * 110.0;
                D_8010A608_1ABEA8_BallonBurst[w->group][7].x = (HuMathSin(f * 1.5 + 90.0 + ((w->group != 0) ? 60.0 : 0.0)) * -r) * 12.0 + ((w->group != 0) ? 336.0 : -336.0);
                D_8010A608_1ABEA8_BallonBurst[w->group][7].y = D_8010A718_1ABFB8_BallonBurst[w->group] + -2223.0;
                t = HuMathSin(f * 1.75 + 100.0 + ((w->group != 0) ? 60.0 : 0.0)) + 1.0;
                D_8010A608_1ABEA8_BallonBurst[w->group][7].z = ((D_8010A708_1ABFA8_BallonBurst[w->group] > 40.0) ? t * 4.0 : t * (D_8010A708_1ABFA8_BallonBurst[w->group] * 0.1)) * 18.0 + -5925.0;
                omSetTra((w->group != 0) ? D_8010A728_1ABFC8_BallonBurst : D_8010A6F8_1ABF98_BallonBurst, D_8010A608_1ABEA8_BallonBurst[w->group][7].x, D_8010A608_1ABEA8_BallonBurst[w->group][7].y, D_8010A608_1ABEA8_BallonBurst[w->group][7].z - 1.0);
                x = (HuMathSin(f * 1.5 + ((w->group != 0) ? 60.0 : 0.0)) * -r) * 1.1;
                y = (HuMathSin(f * 1.5 + 90.0 + ((w->group != 0) ? 60.0 : 0.0)) * r) * 1.1;
                omSetRot((w->group != 0) ? D_8010A728_1ABFC8_BallonBurst : D_8010A6F8_1ABF98_BallonBurst,
                         (D_8010A708_1ABFA8_BallonBurst[w->group] / 6.0f < 25.0) ? 8.0f : (f32)(((D_8010A708_1ABFA8_BallonBurst[w->group] / 6.0f - 25.0) / 25.0) * 12.0 + 8.0), x, y);
            } else if (D_8010AB02_1AC3A2_BallonBurst != 4) {
                D_8010A764_1AC004_BallonBurst[w->group] -= 0.5;
                D_8010A764_1AC004_BallonBurst[w->group] = (D_8010A764_1AC004_BallonBurst[w->group] < -100.0) ? -100.0f : (D_8010A764_1AC004_BallonBurst[w->group] > 0.0) ? 0.0f : D_8010A764_1AC004_BallonBurst[w->group];
                D_8010A718_1ABFB8_BallonBurst[w->group] += D_8010A764_1AC004_BallonBurst[w->group];
                D_8010A718_1ABFB8_BallonBurst[w->group] = (D_8010A718_1ABFB8_BallonBurst[w->group] < 65.0) ? 65.0f : (D_8010A718_1ABFB8_BallonBurst[w->group] > 150.0) ? 150.0f : D_8010A718_1ABFB8_BallonBurst[w->group];
                D_8010A608_1ABEA8_BallonBurst[w->group][7].y = D_8010A718_1ABFB8_BallonBurst[w->group] + -2301.0;
            }
            omSetSca((w->group != 0) ? D_8010A728_1ABFC8_BallonBurst : D_8010A6F8_1ABF98_BallonBurst, 1.0f, 1.0f, 1.0f);
            t = D_8010A708_1ABFA8_BallonBurst[w->group] / 6.0f;
            func_8002CDF0_2D9F0(*((w->group != 0) ? D_8010A728_1ABFC8_BallonBurst : D_8010A6F8_1ABF98_BallonBurst)->model, (t > 40.0) ? (s32)((t - 40.0) * 15.0) & 0xFF : 0, 0, 0, 0);
            t = ((D_8010A708_1ABFA8_BallonBurst[w->group] / 50.0) / 6.0) * 90.0;
            if (t > 90.0) {
                t = 90.0f;
            }
            func_80029C74_2A874(*((w->group != 0) ? D_8010A728_1ABFC8_BallonBurst : D_8010A6F8_1ABF98_BallonBurst)->model, t);
            for (i = 0; (f32)D_80109D8C_1AB62C_BallonBurst[i + 1] < t; i++) {
            }
            x = ((t - (f32)D_80109D8C_1AB62C_BallonBurst[i]) / (f32)(D_80109D8C_1AB62C_BallonBurst[i + 1] - D_80109D8C_1AB62C_BallonBurst[i])) * (D_80109D60_1AB600_BallonBurst[i + 1] - D_80109D60_1AB600_BallonBurst[i]) + D_80109D60_1AB600_BallonBurst[i];
            for (i = 0; (f32)D_80109D94_1AB634_BallonBurst[i + 1] < t; i++) {
            }
            y = ((t - (f32)D_80109D94_1AB634_BallonBurst[i]) / (f32)(D_80109D94_1AB634_BallonBurst[i + 1] - D_80109D94_1AB634_BallonBurst[i])) * (D_80109D78_1AB618_BallonBurst[i + 1] - D_80109D78_1AB618_BallonBurst[i]) + D_80109D78_1AB618_BallonBurst[i];
            omSetTra((w->group != 0) ? D_8010A600_1ABEA0_BallonBurst : D_8010A75C_1ABFFC_BallonBurst, D_8010A608_1ABEA8_BallonBurst[w->group][7].x, -2244.0f, (x + y) * 0.5 * 10.0 + -6004.0);
            omSetSca((w->group != 0) ? D_8010A600_1ABEA0_BallonBurst : D_8010A75C_1ABFFC_BallonBurst, (t / 90.0) * 2.5 + 2.0, 2.0f, (x - y) * 0.4);
            s = D_8010AB02_1AC3A2_BallonBurst;
            if (s == 5) {
                if (w->group == D_8010AAC0_1AC360_BallonBurst && D_8010A770_1AC010_BallonBurst >= 0x10) {
                    t = (f32)(D_8010A770_1AC010_BallonBurst - 0xF) / 15.0f;
                    t = t * t;
                    o = (w->group != 0) ? D_8010A600_1ABEA0_BallonBurst : D_8010A75C_1ABFFC_BallonBurst;
                    e = (t * t) * 96.0;
                    func_8002D0A0_2DCA0(*o->model, e);
                }
                t = (f32)D_8010A770_1AC010_BallonBurst / 30.0f;
                q = (t > 0.5) ? 0.0f : (f32)(2.0 * (0.5 - t));
                if (q < 0.0) {
                    q = 0.0f;
                }
                o = (D_8010AAC0_1AC360_BallonBurst != 0) ? D_8010A728_1ABFC8_BallonBurst : D_8010A6F8_1ABF98_BallonBurst;
                t = (1.0 - t * t * t) * 1.5;
                func_8002AC10_2B810(*o->model, q, t * 5.0 + 1.0, 2);
                t = t * 360.0;
                D_800CA02C_CAC2C = t - (s16)((s32)t / 360) * 360.0;
            } else if ((u32)(D_8010AB02_1AC3A2_BallonBurst - 2) < 2) {
                func_8002AC10_2B810(*((D_8010AAC0_1AC360_BallonBurst != 0) ? D_8010A728_1ABFC8_BallonBurst : D_8010A6F8_1ABF98_BallonBurst)->model, 1.0f, 100.0f, 2);
            }
        }
        if (D_8010A714_1ABFB4_BallonBurst[w->group] == 1) {
            for (k = 3; k < 7; k++) {
                f = k - 2;
                e = (f + 0.1) / 4.6;
                t = e;
                y = t * t * t;
                g = 1.0 - (f32)((f - 0.2) / 5.0);
                v = 1.0 - g * g;
                q = e;
                if (D_8010A718_1ABFB8_BallonBurst[w->group] < 65.0) {
                } else {
                    r = (D_8010A718_1ABFB8_BallonBurst[w->group] - 65.0) / 55.0;
                    q = q * (1.0 - r) + v * r;
                }
                D_8010A608_1ABEA8_BallonBurst[w->group][k].x = D_8010A608_1ABEA8_BallonBurst[w->group][2].x * (1.0 - q) + q * D_8010A608_1ABEA8_BallonBurst[w->group][7].x;
                D_8010A608_1ABEA8_BallonBurst[w->group][k].y = D_8010A608_1ABEA8_BallonBurst[w->group][2].y * (1.0 - y) + y * D_8010A608_1ABEA8_BallonBurst[w->group][7].y;
                D_8010A608_1ABEA8_BallonBurst[w->group][k].z = D_8010A608_1ABEA8_BallonBurst[w->group][2].z * (1.0 - v) + v * D_8010A608_1ABEA8_BallonBurst[w->group][7].z;
                func_80029714_2A314(((w->group == 0) ? D_8010A704_1ABFA4_BallonBurst : D_8010AA94_1AC334_BallonBurst)->model[k], D_8010A608_1ABEA8_BallonBurst[w->group][k].x, D_8010A608_1ABEA8_BallonBurst[w->group][k].y, D_8010A608_1ABEA8_BallonBurst[w->group][k].z);
            }
            for (i = 0; i < 7; i++) {
                t = 0.0f;
                for (j = 0; j < 7; j++) {
                    t += D_8010A778_1AC018_BallonBurst[w->group][i * 7 + j];
                }
                if (t > 12.0f) {
                    t = 12.0f;
                }
                s = i == 2;
                t = t / 12.0;
                if (i == 3) {
                    s += 6;
                }
                if (i == 4) {
                    s += 3;
                }
                q = t * 0.4 + 0.77 + s * 0.01;
                t = t * 10.0;
                if ((s16)i == 0) {
                    o = (w->group != 0) ? D_8010AA94_1AC334_BallonBurst : D_8010A704_1ABFA4_BallonBurst;
                    omSetSca(o, q, q, q);
                    omSetTra(o, D_8010A608_1ABEA8_BallonBurst[w->group][0].x, t + D_8010A608_1ABEA8_BallonBurst[w->group][0].y, D_8010A608_1ABEA8_BallonBurst[w->group][0].z);
                } else {
                    func_800297E8_2A3E8(((w->group != 0) ? D_8010AA94_1AC334_BallonBurst : D_8010A704_1ABFA4_BallonBurst)->model[(s16)i], q, q, q);
                    func_80029714_2A314(((w->group != 0) ? D_8010AA94_1AC334_BallonBurst : D_8010A704_1ABFA4_BallonBurst)->model[(s16)i], D_8010A608_1ABEA8_BallonBurst[w->group][i].x, t + D_8010A608_1ABEA8_BallonBurst[w->group][i].y, D_8010A608_1ABEA8_BallonBurst[w->group][i].z);
                }
            }
        }
        D_8010A714_1ABFB4_BallonBurst[w->group]++;
        w->unk_09 = 1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1B_BallonBurst/1A40A0", func_80106AEC_1A838C_BallonBurst);
#endif

s32 func_80109B70_1AB410_BallonBurst(u16 player) {
    u16 n;

    if (gPlayers[player].group == 0) {
        n = D_8010A720_1ABFC0_BallonBurst++;
    } else {
        n = D_8010A722_1ABFC2_BallonBurst++;
    }
    return n;
}

void func_80109BD0_1AB470_BallonBurst(void) {
    if (D_8010A900_1AC1A0_BallonBurst != 0 || D_801011FC_101DFC != 0) {
        if (D_801011FC_101DFC != 0) {
            if (D_8010A6D4_1ABF74_BallonBurst == 0) {
                InitFadeOut(0, 0x14);
                func_800794A8_7A0A8(0x14);
                func_80079614_7A214(0x14);
            }
            D_8010A6D4_1ABF74_BallonBurst++;
            if (D_8010A6D4_1ABF74_BallonBurst < 0x19) {
                return;
            }
        }
        func_800794A8_7A0A8(0x28);
        omOvlReturnEx(1);
    }
}

