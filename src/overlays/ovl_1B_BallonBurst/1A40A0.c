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

__asm__(".section .rodata");
const u32 D_80109E88_1AB728_BallonBurst[6] = { 0x00000002, 0x00000003, 0x00000007, 0x00000004, 0x00000005, 0x00000006 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1B_BallonBurst/1A40A0", func_80103C10_1A54B0_BallonBurst);

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

