#include "ovl_1B.h"


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
    D_8010A608_1ABEA8_BallonBurst[0].x = 33.0f;
    D_8010A608_1ABEA8_BallonBurst[0].y = -2210.0f;
    D_8010A608_1ABEA8_BallonBurst[0].z = -5490.0f;
    omSetTra(D_8010AA94_1AC334_BallonBurst, 33.0f, -2210.0f, -5490.0f);
    omSetSca(D_8010AA94_1AC334_BallonBurst, 0.5f, 0.5f, 0.5f);
    {
    Vec target;

    target.x = -324.0f;
    target.y = -2253.2f;
    target.z = -5925.0f;
    D_8010A718_1ABFB8_BallonBurst = 0;
    D_8010A764_1AC004_BallonBurst = 0;
    for (k = 1; k < 4; k++) {
        t = (f32)k / 6.0f;
        u = t;
        u = 1.0 - u;
        w = u * u;
        w = w * u;
        e = 1.0 - w;
        D_8010A608_1ABEA8_BallonBurst[k].x = D_8010A608_1ABEA8_BallonBurst[0].x * u + t * target.x;
        D_8010A608_1ABEA8_BallonBurst[k].y = D_8010A608_1ABEA8_BallonBurst[0].y * (1.0 - e) + e * target.y;
        D_8010A608_1ABEA8_BallonBurst[k].z = D_8010A608_1ABEA8_BallonBurst[0].z * (1.0 - e) + e * target.z;
        func_80029714_2A314(D_8010AA94_1AC334_BallonBurst->model[k], D_8010A608_1ABEA8_BallonBurst[k].x, D_8010A608_1ABEA8_BallonBurst[k].y, D_8010A608_1ABEA8_BallonBurst[k].z);
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
    D_8010A668_1ABF08_BallonBurst[0].x = -33.0f;
    D_8010A668_1ABF08_BallonBurst[0].y = -2210.0f;
    D_8010A668_1ABF08_BallonBurst[0].z = -5490.0f;
    omSetTra(D_8010A704_1ABFA4_BallonBurst, -33.0f, -2210.0f, -5490.0f);
    omSetSca(D_8010A704_1ABFA4_BallonBurst, 0.5f, 0.5f, 0.5f);
    target.x = 336.0f;
    target.y = -2253.2f;
    target.z = -5925.0f;
    D_8010A71C_1ABFBC_BallonBurst = 0;
    D_8010A768_1AC008_BallonBurst = 0;
    for (k = 1; k < 4; k++) {
        t = (f32)k / 6.0f;
        u = t;
        u = 1.0 - u;
        w = u * u;
        w = w * u;
        e = 1.0 - w;
        D_8010A668_1ABF08_BallonBurst[k].x = D_8010A668_1ABF08_BallonBurst[0].x * u + t * target.x;
        D_8010A668_1ABF08_BallonBurst[k].y = D_8010A668_1ABF08_BallonBurst[0].y * (1.0 - e) + e * target.y;
        D_8010A668_1ABF08_BallonBurst[k].z = D_8010A668_1ABF08_BallonBurst[0].z * (1.0 - e) + e * target.z;
        func_80029714_2A314(D_8010A704_1ABFA4_BallonBurst->model[k], D_8010A668_1ABF08_BallonBurst[k].x, D_8010A668_1ABF08_BallonBurst[k].y, D_8010A668_1ABF08_BallonBurst[k].z);
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
    D_8010A730_1ABFD0_BallonBurst[0] = D_8010A730_1ABFD0_BallonBurst[2] = D_8010A730_1ABFD0_BallonBurst[4] = D_8010A730_1ABFD0_BallonBurst[6] = 0;
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
   flow, see docs/DECOMP_WALLS.md), which moves the register allocation of the whole function. */
#ifdef NON_MATCHING
/* BB6BEGIN */
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
            if (D_8010A770_1AC010_BallonBurst > 0) {
                if ((D_8010A770_1AC010_BallonBurst + 1) % 30 == 0) {
                    func_8006D4D0_6E0D0(D_8010A770_1AC010_BallonBurst / 30 + 1);
                }
                break;
            }
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
            fade:
                D_8010AB02_1AC3A2_BallonBurst = 8;
                InitFadeOut(0, 0x14);
                D_8010A770_1AC010_BallonBurst = 0x14;
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
                            goto fade;
                        }
                        if (D_8010A770_1AC010_BallonBurst == 0xA8) {
                            s32 voice[6] = { 2, 3, 7, 4, 5, 6 };

                            w = D_8010A5F0_1ABE90_BallonBurst[D_8010AAFC_1AC39C_BallonBurst[0]];
                            o = &D_8010AAB0_1AC350_BallonBurst[D_8010AAFC_1AC39C_BallonBurst[0]];
                            func_80029BF0_2A7F0(*(*o)->model, func_80029E14_2AA14((*o)->model[3]), 0, 4, 0);
                            if (w->unk_0A == 0) {
                                func_800732B0_73EB0((voice[w->character] << 0x10) | 0x4F);
                            } else {
                                func_800732B0_73EB0((voice[w->character] << 0x10) | 0x4E);
                            }
                            w = D_8010A5F0_1ABE90_BallonBurst[D_8010AAFC_1AC39C_BallonBurst[1]];
                            o = &D_8010AAB0_1AC350_BallonBurst[D_8010AAFC_1AC39C_BallonBurst[1]];
                            func_80029BF0_2A7F0(*(*o)->model, func_80029E14_2AA14((*o)->model[3]), 0, 4, 0);
                            if (w->unk_0A == 0) {
                                func_800732B0_73EB0((voice[w->character] << 0x10) | 0x4F);
                            } else {
                                func_800732B0_73EB0((voice[w->character] << 0x10) | 0x4E);
                            }
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
    bcopy(view, D_8010AAC8_1AC368_BallonBurst, 0x34);
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
/* BB6END */
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
    SprExec();
    {
        Gfx* g = D_800FDBCC_FE7CC++;

        g->words.w0 = 0xEE000000;
        g->words.w1 = 0x7FFF7FFF;
    }
    func_8007A7FC_7B3FC(D_8010AAC8_1AC368_BallonBurst);
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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1B_BallonBurst/1A40A0", func_80106AEC_1A838C_BallonBurst);

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

