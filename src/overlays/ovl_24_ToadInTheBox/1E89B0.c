#include "ovl_24.h"

void func_80102800_1E89B0_ToadInTheBox(void) {
    u8 cam;

    func_8002D4D0_2E0D0(0x32);
    func_8002F290_2FE90(D_800F9D30_FA930, 0x40);
    func_80020D20_21920(0x20);
    omInitObjMan(0x64, 0);
    func_80079128_79D28();
    func_80029708_2A308(0);
    func_8000C38C_CF8C();
    func_8000C3C8_CFC8();
    func_80018E30_19A30(1);
    cam = func_80018E78_19A78();
    ScissorSet(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 15.0f, 2200.0f, 4000.0f);
    D_800FA606_FB206 = 0;
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    func_8000C460_D060();
    func_8000C578_D178(1);
    func_80026D28_27928(1);
    func_80026E00_27A00(0, 0.0f, 80.0f, 130.0f);
    func_80026DAC_279AC(0, 0x90, 0x90, 0x90);
    func_80026E00_27A00(1, 0.0f, 80.0f, 130.0f);
    func_80026DAC_279AC(1, 0, 0, 0);
    omAddObj(0, 0, 0, -1, func_80102DCC_1E8F7C_ToadInTheBox);
    omSetStatBit(omAddObj(8, 0, 0, -1, func_80104EFC_1EB0AC_ToadInTheBox), 0xA0);
    func_8000C018_CC18(D_800F8FE0_F9BE0);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(2, 1, 0, -1, func_801049AC_1EAB5C_ToadInTheBox);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = D_8010B4B0_1F1660_ToadInTheBox[0] = omAddObj(2, 7, 1, -1, func_80104AD8_1EAC88_ToadInTheBox);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = D_8010B4B0_1F1660_ToadInTheBox[1] = omAddObj(2, 7, 1, -1, func_80104AF4_1EACA4_ToadInTheBox);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = D_8010B4B0_1F1660_ToadInTheBox[2] = omAddObj(2, 7, 1, -1, func_80104B10_1EACC0_ToadInTheBox);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = D_8010B4B0_1F1660_ToadInTheBox[3] = omAddObj(2, 7, 1, -1, func_80104B2C_1EACDC_ToadInTheBox);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = D_8010B4A0_1F1650_ToadInTheBox[0] = omAddObj(2, 2, 1, -1, func_80104CF4_1EAEA4_ToadInTheBox);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = D_8010B4A0_1F1650_ToadInTheBox[1] = omAddObj(2, 2, 1, -1, func_80104D10_1EAEC0_ToadInTheBox);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = D_8010B4A0_1F1650_ToadInTheBox[2] = omAddObj(2, 2, 1, -1, func_80104D2C_1EAEDC_ToadInTheBox);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = D_8010B4A0_1F1650_ToadInTheBox[3] = omAddObj(2, 2, 1, -1, func_80104D48_1EAEF8_ToadInTheBox);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = D_8010B458_1F1608_ToadInTheBox[0] = omAddObj(3, 0x13, 0x3C, -1, func_8010559C_1EB74C_ToadInTheBox);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = D_8010B458_1F1608_ToadInTheBox[1] = omAddObj(3, 0x13, 0x3C, -1, func_80105638_1EB7E8_ToadInTheBox);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = D_8010B458_1F1608_ToadInTheBox[2] = omAddObj(3, 0x13, 0x3C, -1, func_801056D4_1EB884_ToadInTheBox);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = D_8010B458_1F1608_ToadInTheBox[3] = omAddObj(3, 0x13, 0x3C, -1, func_80105770_1EB920_ToadInTheBox);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_80079E60_7AA60), 0xA0);
    InitFadeIn(0, 8);
}

void func_80102DCC_1E8F7C_ToadInTheBox(omObjData* obj) {
    s32 i;

    D_8010B452_1F1602_ToadInTheBox = 0;
    D_8010B492_1F1642_ToadInTheBox = 0;
    D_8010B48C_1F163C_ToadInTheBox = 0;
    D_8010B4C0_1F1670_ToadInTheBox = 5;
    D_8010B49C_1F164C_ToadInTheBox = 0;
    D_8010B450_1F1600_ToadInTheBox = 1;
    D_8010B496_1F1646_ToadInTheBox = 0x5A;
    D_8010B4C1_1F1671_ToadInTheBox[0] = rand8() % 3 + 1;
    D_8010B4C1_1F1671_ToadInTheBox[1] = rand8() % 3 + 1;
    D_8010B4C1_1F1671_ToadInTheBox[2] = (rand8() & 1) + 1;
    D_8010B4C1_1F1671_ToadInTheBox[3] = (rand8() & 1) + 1;
    D_8010B4C1_1F1671_ToadInTheBox[4] = 0;
    D_8010B468_1F1618_ToadInTheBox[0] = D_8010B468_1F1618_ToadInTheBox[1] = D_8010B468_1F1618_ToadInTheBox[2] = D_8010B468_1F1618_ToadInTheBox[3] = 0;
    for (i = 0; i < 4; i++) {
        D_8010B3B8_1F1568_ToadInTheBox[i] = &D_8010B390_1F1540_ToadInTheBox[i];
        bzero(D_8010B3B8_1F1568_ToadInTheBox[i], sizeof(TBInfo));
        D_8010B428_1F15D8_ToadInTheBox[i] = &D_8010B3C8_1F1578_ToadInTheBox[i];
        bzero(D_8010B428_1F15D8_ToadInTheBox[i], sizeof(TBBox));
        D_8010B428_1F15D8_ToadInTheBox[i]->state = 0;
    }
    D_8010B4CC_1F167C_ToadInTheBox = rand8() & 1;
    D_8010B474_1F1624_ToadInTheBox = 0;
    D_8010B490_1F1640_ToadInTheBox = 0;
    D_8010B46C_1F161C_ToadInTheBox = omAddObj(1, 2, 1, -1, NULL);
    *D_8010B46C_1F161C_ToadInTheBox->model = LoadFormFile(0x340009, 0x49D);
    func_80029E80_2AA80(*D_8010B46C_1F161C_ToadInTheBox->model, 2, 2);
    HmfModelObjAttrSet(*D_8010B46C_1F161C_ToadInTheBox->model, 0x600, 0x400);
    omSetTra(D_8010B46C_1F161C_ToadInTheBox, -3.0f, 13.0f, 240.0f);
    omSetSca(D_8010B46C_1F161C_ToadInTheBox, 0.4532f, 0.4532f, 0.4532f);
    D_8010B4C8_1F1678_ToadInTheBox = omAddObj(1, 2, 1, -1, NULL);
    *D_8010B4C8_1F1678_ToadInTheBox->model = LoadFormFile(0x34000A, 0x49D);
    func_80029E80_2AA80(*D_8010B4C8_1F1678_ToadInTheBox->model, 2, 2);
    HmfModelObjAttrSet(*D_8010B4C8_1F1678_ToadInTheBox->model, 0x600, 0x400);
    omSetTra(D_8010B4C8_1F1678_ToadInTheBox, 0.0f, 48.0f, 240.0f);
    omSetSca(D_8010B4C8_1F1678_ToadInTheBox, 0.4219f, 0.4219f, 0.4219f);
    D_8010B498_1F1648_ToadInTheBox = omAddObj(1, 6, 1, -1, NULL);
    *D_8010B498_1F1648_ToadInTheBox->model = LoadFormFile(0x340007, 0x4A9);
    func_8002D124_2DD24(*D_8010B498_1F1648_ToadInTheBox->model);
    func_80029AFC_2A6FC(*D_8010B498_1F1648_ToadInTheBox->model);
    func_8002D0A0_2DCA0(*D_8010B498_1F1648_ToadInTheBox->model, 0xFF);
    HmfModelObjAttrSet(*D_8010B498_1F1648_ToadInTheBox->model, 0x600, 0);
    omSetTra(D_8010B498_1F1648_ToadInTheBox, -382.2f, -15.0f, 112.5f);
    omSetRot(D_8010B498_1F1648_ToadInTheBox, 0.0f, 0.0f, 0.0f);
    omSetSca(D_8010B498_1F1648_ToadInTheBox, 1.335938f, 1.0f, 2.4f);
    omSetSca(D_8010B498_1F1648_ToadInTheBox, 0.4f, 0.5f, 0.8f);
    {
        f32 sx[4] = { 1.335938f, 1.316406f, 1.316406f, 1.335938f };
        f32 ox[4] = { 12.5f, 12.5f, 0.0f, -7.5f };
        f32 ry[4] = { 5.5f, 2.5f, -1.5f, -4.0f };
        s16 j;

        for (j = 1; j < 4; j++) {
            if (j != 0) {
                D_8010B498_1F1648_ToadInTheBox->model[j] = func_80027D3C_2893C(*D_8010B498_1F1648_ToadInTheBox->model);
            }
            func_80029714_2A314(D_8010B498_1F1648_ToadInTheBox->model[j], j * 278.0 - 422.0 + ox[j], -25.0f, 0.0f);
            func_8002979C_2A39C(D_8010B498_1F1648_ToadInTheBox->model[j], 0.0f, ry[j] * 1.2, 0.0f);
            func_800297E8_2A3E8(D_8010B498_1F1648_ToadInTheBox->model[j], sx[j], 1.0f, 2.4f);
            func_80029714_2A314(D_8010B498_1F1648_ToadInTheBox->model[j], (f32)j * 245.0 * 1.04 + -382.2, -15.0f, 80.0f);
            func_8002979C_2A39C(D_8010B498_1F1648_ToadInTheBox->model[j], 0.0f, 0.0f, 0.0f);
            func_800297E8_2A3E8(D_8010B498_1F1648_ToadInTheBox->model[j], 0.4f, 0.5f, 0.8f);
        }
    }
    for (i = 0; i < 4; i++) {
        D_8010B440_1F15F0_ToadInTheBox[i] = omAddObj(6, 2, 1, -1, NULL);
        *D_8010B440_1F15F0_ToadInTheBox[i]->model = LoadFormFile(0x340000, 0x40D);
        omSetSca(D_8010B440_1F15F0_ToadInTheBox[i], 3.0f, 3.0f, 0.0f);
        HmfModelObjAttrSet(*D_8010B440_1F15F0_ToadInTheBox[i]->model, 0x600, 0);
        D_8010B478_1F1628_ToadInTheBox[i] = omAddObj(6, 5, 2, -1, NULL);
        D_8010B478_1F1628_ToadInTheBox[i]->model[3] = LoadFormFile(0x80000, 0x4AD);
        if (i == 0) {
            D_8010B478_1F1628_ToadInTheBox[i]->model[0] = LoadFormFile(0x80000, 0x4BD);
        } else {
            D_8010B478_1F1628_ToadInTheBox[i]->model[0] = func_80027D3C_2893C(*D_8010B478_1F1628_ToadInTheBox[0]->model);
        }
        if (i == 0) {
            D_8010B478_1F1628_ToadInTheBox[0]->model[1] = LoadFormFile(0x80006, 0x49D);
            D_8010B478_1F1628_ToadInTheBox[0]->model[2] = LoadFormFile(0x80001, 0x49D);
        }
        func_8002D124_2DD24(D_8010B478_1F1628_ToadInTheBox[i]->model[3]);
        func_80029AFC_2A6FC(D_8010B478_1F1628_ToadInTheBox[i]->model[3]);
        func_8002D0A0_2DCA0(D_8010B478_1F1628_ToadInTheBox[i]->model[3], 0xFF);
        HmfModelObjAttrSet(*D_8010B478_1F1628_ToadInTheBox[i]->model, 0x600, 0x400);
        HmfModelObjAttrSet(D_8010B478_1F1628_ToadInTheBox[i]->model[3], 0x600, 0x400);
        D_8010B4D0_1F1680_ToadInTheBox[i] = omAddObj(6, 5, 3, -1, NULL);
        if (i == 0) {
            D_8010B4D0_1F1680_ToadInTheBox[i]->model[0] = LoadFormFile(0x800B0, 0x4BD);
        } else {
            D_8010B4D0_1F1680_ToadInTheBox[i]->model[0] = func_80027D3C_2893C(*D_8010B4D0_1F1680_ToadInTheBox[0]->model);
        }
        if (i == 0) {
            D_8010B4D0_1F1680_ToadInTheBox[0]->model[1] = LoadFormFile(0x800B1, 0x49D);
            D_8010B4D0_1F1680_ToadInTheBox[0]->model[2] = LoadFormFile(0x800B6, 0x49D);
            D_8010B4D0_1F1680_ToadInTheBox[0]->model[3] = LoadFormFile(0x800B3, 0x49D);
        }
        func_80029B80_2A780(*D_8010B4D0_1F1680_ToadInTheBox[i]->model, D_8010B4D0_1F1680_ToadInTheBox[0]->model[1]);
        func_80029E80_2AA80(*D_8010B4D0_1F1680_ToadInTheBox[i]->model, 1, 1);
        HmfModelObjAttrSet(*D_8010B4D0_1F1680_ToadInTheBox[i]->model, 0x600, 0x400);
    }
    func_8002838C_28F8C(0, func_80109568_1EF718_ToadInTheBox, 2);
    obj->func_ptr = func_8010377C_1E992C_ToadInTheBox;
}

__asm__(".section .rodata");
const u32 D_8010ABF0_1F0DA0_ToadInTheBox[4] = { 0x41B40000, 0x41480000, 0x00000000, 0xC0F00000 };

__asm__(".section .rodata");
const u32 D_8010AC00_1F0DB0_ToadInTheBox[6] = { 0x00000002, 0x00000003, 0x00000007, 0x00000004, 0x00000005, 0x00000006 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_ToadInTheBox/1E89B0", func_8010377C_1E992C_ToadInTheBox);

void func_801049AC_1EAB5C_ToadInTheBox(omObjData* obj) {
    f32 zero;
    GroundWork* g;

    obj->model[0] = func_80018A30_19630(0x340002, 0x49D);
    zero = 0.0f;
    obj->trans.z = zero;
    obj->trans.y = zero;
    obj->trans.x = zero;
    func_80029714_2A314(*obj->model, zero, obj->trans.y, obj->trans.z);
    obj->unk_50 = g = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(g, 0, 0xB4);
    obj->func_ptr = NULL;
    g->unk_03 = 1;
    D_8010274C_10334C.x = zero;
    D_8010274C_10334C.y = 360.0f;
    D_8010274C_10334C.z = zero;
    D_800FD474_FE074.x = zero;
    D_800FD474_FE074.y = zero;
    D_800FD474_FE074.z = zero;
    D_800FA610_FB210 = 3450.0f;
    func_8000BEF8_CAF8(obj, 2, zero);
    func_8000BE74_CA74(obj, 0.01f);
    func_8000BE8C_CA8C(obj, 0.5f);
    func_8000BE98_CA98(obj, 10.0f);
    g->unk_04 = 0;
}

void func_80104AD8_1EAC88_ToadInTheBox(omObjData* obj) {
    func_80104B48_1EACF8_ToadInTheBox(obj, 0);
}

void func_80104AF4_1EACA4_ToadInTheBox(omObjData* obj) {
    func_80104B48_1EACF8_ToadInTheBox(obj, 1);
}

void func_80104B10_1EACC0_ToadInTheBox(omObjData* obj) {
    func_80104B48_1EACF8_ToadInTheBox(obj, 2);
}

void func_80104B2C_1EACDC_ToadInTheBox(omObjData* obj) {
    func_80104B48_1EACF8_ToadInTheBox(obj, 3);
}

void func_80104B48_1EACF8_ToadInTheBox(omObjData* obj, s32 i) {
    GroundWork* g;

    obj->model[0] = func_80018A30_19630(0x340002, 0x49D);
    obj->trans.x = i * 245.0 * 1.08 + -396.90000000000003;
    obj->trans.y = -200.0f;
    obj->trans.z = 140.0f;
    obj->model[1] = func_80018A30_19630(0x340002, 0x4DD);
    obj->model[2] = func_80018A30_19630(0x340003, 0x4DD);
    obj->model[3] = func_80018A30_19630(0x340004, 0x4DD);
    obj->model[4] = func_80018A30_19630(0x340005, 0x4DD);
    obj->model[5] = func_80018A30_19630(0x340006, 0x4DD);
    obj->unk_50 = g = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(g, 0, 0xB4);
    obj->func_ptr = NULL;
    g->unk_03 = 1;
    func_8000BF54_CB54(obj, 87.5f, 197.5f, -100.0f, -100.0f, 100.0f, 800.0f);
    func_8000BE8C_CA8C(obj, 0.5f);
    func_8000BE98_CA98(obj, 10.0f);
    g->unk_04 = 0;
}

void func_80104CF4_1EAEA4_ToadInTheBox(omObjData* obj) {
    func_80104D64_1EAF14_ToadInTheBox(obj, 0);
}

void func_80104D10_1EAEC0_ToadInTheBox(omObjData* obj) {
    func_80104D64_1EAF14_ToadInTheBox(obj, 1);
}

void func_80104D2C_1EAEDC_ToadInTheBox(omObjData* obj) {
    func_80104D64_1EAF14_ToadInTheBox(obj, 2);
}

void func_80104D48_1EAEF8_ToadInTheBox(omObjData* obj) {
    func_80104D64_1EAF14_ToadInTheBox(obj, 3);
}

void func_80104D64_1EAF14_ToadInTheBox(omObjData* obj, s32 i) {
    GroundWork* g;

    obj->model[0] = func_80018A30_19630(0x340002, 0x49D);
    obj->model[1] = func_80018A30_19630(0x340008, 0x4B9);
    HmfModelObjAttrSet(obj->model[1], 0x600, 0x400);
    obj->trans.x = i * 245.0 + -367.5;
    obj->trans.y = 1280.0f;
    obj->trans.z = 250.0f;
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, 250.0f);
    obj->scale.x = 1.2f;
    obj->scale.y = 1.2f;
    obj->scale.z = 1.2f;
    func_800297E8_2A3E8(obj->model[1], obj->scale.x, obj->scale.y, 1.2f);
    obj->unk_50 = g = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(g, 0, 0xB4);
    obj->func_ptr = NULL;
    g->unk_03 = 1;
    func_8000BF54_CB54(obj, 200.0f, 200.0f, -100.0f, -100.0f, 100.0f, 100.0f);
    func_8000BE8C_CA8C(obj, 0.5f);
    func_8000BE98_CA98(obj, 10.0f);
    g->unk_04 = 0;
}

void func_80104EFC_1EB0AC_ToadInTheBox(omObjData* obj) {
    D_8010B488_1F1638_ToadInTheBox = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x34000B), 0, 0);
    espDispOff(D_8010B488_1F1638_ToadInTheBox);
    D_8010B494_1F1644_ToadInTheBox = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x34000C), 0, 0);
    espDispOff(D_8010B494_1F1644_ToadInTheBox);
    obj->func_ptr = func_80104F90_1EB140_ToadInTheBox;
}

void func_80104F90_1EB140_ToadInTheBox(omObjData* obj) {
    s8 i;

    func_801097C4_1EF974_ToadInTheBox(D_8010B488_1F1638_ToadInTheBox, 0.0f, D_8010B450_1F1600_ToadInTheBox * D_8010B49C_1F164C_ToadInTheBox, 1.0f);
    if (D_8010B496_1F1646_ToadInTheBox == 1) {
        func_800298A4_2A4A4(*D_8010B4C8_1F1678_ToadInTheBox->model, 4, 4);
        func_800298A4_2A4A4(*D_8010B46C_1F161C_ToadInTheBox->model, 4, 4);
        func_80029C74_2A874(*D_8010B4C8_1F1678_ToadInTheBox->model, 0.0f);
        func_80029C74_2A874(*D_8010B46C_1F161C_ToadInTheBox->model, 0.0f);
    } else if ((u16)(D_8010B496_1F1646_ToadInTheBox % 20) == 0 && D_8010B496_1F1646_ToadInTheBox != 0) {
        func_800298A4_2A4A4(*D_8010B4C8_1F1678_ToadInTheBox->model, 4, 0);
        func_800298A4_2A4A4(*D_8010B46C_1F161C_ToadInTheBox->model, 4, 0);
        func_80109524_1EF6D4_ToadInTheBox(D_8010B4C8_1F1678_ToadInTheBox, 0);
        func_80109524_1EF6D4_ToadInTheBox(D_8010B46C_1F161C_ToadInTheBox, 0);
    }
    if ((func_80078EA8_79AA8() & 0xFFFF) + D_80102720_103320 == 0) {
        u16 t = D_8010B496_1F1646_ToadInTheBox;

        if (t != 0) {
            t--;
        }
        D_8010B496_1F1646_ToadInTheBox = t;
    }
    for (i = 0; i < 4; i++) {
        if (D_8010B428_1F15D8_ToadInTheBox[i]->state == 2) {
            omObjData* box = D_8010B4A0_1F1650_ToadInTheBox[i];

            func_80029714_2A314(box->model[1], box->trans.x, box->trans.y + (D_8010B450_1F1600_ToadInTheBox * D_8010B49C_1F164C_ToadInTheBox) * 3.6875, box->trans.z);
        }
    }
    D_80102750_103350 = (D_8010B450_1F1600_ToadInTheBox * D_8010B49C_1F164C_ToadInTheBox) * 3.6875 + 350.0;
    D_8010B450_1F1600_ToadInTheBox = -D_8010B450_1F1600_ToadInTheBox;
    D_8010B49C_1F164C_ToadInTheBox -= D_8010B450_1F1600_ToadInTheBox == 1 && D_8010B49C_1F164C_ToadInTheBox > 0;
}

void func_80105288_1EB438_ToadInTheBox(omObjData* obj, s32 dir, s32 file, u16 player, f32 x, f32 y, f32 z) {
    s32 mot;
    TBInfo** p;
    TBInfo** q;
    s32 k;
    TBInfo* t;
    s32 a;
    s32 b;

    a = 0x4B9;
    b = 0x49D;
    func_8000C6FC_D2FC(obj, dir, file, player, a, b);
    func_8000E0C0_ECC0(obj->unk_50, 4, func_801094FC_1EF6AC_ToadInTheBox);
    obj->model[3] = LoadFormFile(7, 0x48D);
    obj->model[4] = LoadFormFile(8, 0x48D);
    obj->model[6] = LoadFormFile(9, 0x48D);
    obj->model[5] = LoadFormFile(0xA, 0x48D);
    obj->model[7] = LoadFormFile(0xC, 0x48D);
    obj->model[8] = LoadFormFile(0xB, 0x48D);
    func_80019F0C_1AB0C(obj, 0, dir, 1, 0);
    func_80019F0C_1AB0C(obj, 6, dir | 4, 1, 0x13);
    if (D_8010B4CC_1F167C_ToadInTheBox != 0) {
        mot = dir | 0x4E;
    } else {
        mot = dir | 0x4F;
    }
    func_80019F0C_1AB0C(obj, 0xD, mot, 1, 0x78);
    func_80019F0C_1AB0C(obj, 0xE, dir | 0x57, 1, 0x64);
    func_80019F0C_1AB0C(obj, 0xC, dir | 0x55, 1, 0x78);
    func_80019E84_1AA84(obj, 0x15, dir | 0x2E, 0, 0);
    obj->trans.x = x;
    obj->trans.y = y;
    obj->trans.z = z;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, z);
    func_8000C024_CC24(obj, 0, 2);
    func_8000C024_CC24(obj, 1, 2);
    func_8000C024_CC24(obj, 2, 2);
    func_8000C024_CC24(obj, 3, 2);
    func_8000C024_CC24(obj, 4, 2);
    func_8000C024_CC24(obj, 5, 2);
    func_8000C024_CC24(obj, 6, 2);
    func_8000C024_CC24(obj, 7, 2);
    func_8000C024_CC24(obj, 8, 2);
    k = player;
    q = D_8010B3B8_1F1568_ToadInTheBox;
    p = q + k;
    (*p)->character = gPlayers[player].character;
    t = *p;
    if (gPlayers[player].flags & 1) {
        t->cpu = gPlayers[player].cpu_difficulty;
    } else {
        t->cpu = -1;
    }
    D_8010B3B8_1F1568_ToadInTheBox[player]->port = gPlayers[player].port;
}

void func_8010559C_1EB74C_ToadInTheBox(omObjData* obj) {
    s32 file = D_800CD438_CE038[gPlayers[0].character].model;
    s32 dir = D_800CD438_CE038[gPlayers[0].character].dir;

    func_80105288_1EB438_ToadInTheBox(obj, dir, file, 0, -367.5f, 300.0f, 250.0f);
    ((MgWork*)obj->unk_50)->unk_59 = 0;
    obj->func_ptr = func_80105950_1EBB00_ToadInTheBox;
}

void func_80105638_1EB7E8_ToadInTheBox(omObjData* obj) {
    s32 file = D_800CD438_CE038[gPlayers[1].character].model;
    s32 dir = D_800CD438_CE038[gPlayers[1].character].dir;

    func_80105288_1EB438_ToadInTheBox(obj, dir, file, 1, -122.5f, 300.0f, 250.0f);
    ((MgWork*)obj->unk_50)->unk_59 = 1;
    obj->func_ptr = func_80105950_1EBB00_ToadInTheBox;
}

void func_801056D4_1EB884_ToadInTheBox(omObjData* obj) {
    s32 file = D_800CD438_CE038[gPlayers[2].character].model;
    s32 dir = D_800CD438_CE038[gPlayers[2].character].dir;

    func_80105288_1EB438_ToadInTheBox(obj, dir, file, 2, 122.5f, 300.0f, 250.0f);
    ((MgWork*)obj->unk_50)->unk_59 = 2;
    obj->func_ptr = func_80105950_1EBB00_ToadInTheBox;
}

void func_80105770_1EB920_ToadInTheBox(omObjData* obj) {
    s32 file = D_800CD438_CE038[gPlayers[3].character].model;
    s32 dir = D_800CD438_CE038[gPlayers[3].character].dir;

    PlaySound(0x4A8);
    func_80105288_1EB438_ToadInTheBox(obj, dir, file, 3, 367.5f, 300.0f, 250.0f);
    ((MgWork*)obj->unk_50)->unk_59 = 3;
    obj->func_ptr = func_80105950_1EBB00_ToadInTheBox;
}

void func_80105834_1EB9E4_ToadInTheBox(omObjData* obj, s32 i) {
    s32 file = D_800CD438_CE038[gPlayers[i].character].model;
    s32 dir = D_800CD438_CE038[gPlayers[i].character].dir;
    f32 xs[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
    f32 ys[4] = { 10.0f, 30.0f, 0.0f, 20.0f };
    f32 zs[4] = { 10.0f, -20.0f, 30.0f, 40.0f };

    {
        f32 x = xs[i];
        f32 y = ys[i];
        f32 z = zs[i];

        func_80105288_1EB438_ToadInTheBox(obj, dir, file, i, x, y, z);
    }
    obj->func_ptr = func_80105950_1EBB00_ToadInTheBox;
}

__asm__(".section .rodata");
const u32 D_8010AD40_1F0EF0_ToadInTheBox[6] = { 0x40F00000, 0x41480000, 0x418C0000, 0x41C80000, 0x42480000, 0x00000000 };

__asm__(".section .rodata");
const u32 D_8010AD58_1F0F08_ToadInTheBox[6] = { 0x42340000, 0x43070000, 0x43610000, 0x439D8000, 0x43B40000, 0x00000000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_ToadInTheBox/1E89B0", func_80105950_1EBB00_ToadInTheBox);

s32 func_801094FC_1EF6AC_ToadInTheBox(omObjData* obj) {
    D_8010B428_1F15D8_ToadInTheBox[((MgWork*)obj->unk_50)->unk_59]->unk_08 = 1;
    return 0;
}

void func_80109524_1EF6D4_ToadInTheBox(omObjData* obj, s16 frame) {
    HmfModel* m = &D_800FC834_FD434[*obj->model];

    m->hmf->unk9C->unk08 = frame;
}

void func_80109568_1EF718_ToadInTheBox(Gfx** gfx, s32 mtx, s32 cam) {

    if ((D_8010B492_1F1642_ToadInTheBox == 6 && !_CheckFlag(0xC)) || (D_8010B492_1F1642_ToadInTheBox == 2 && D_8010B48C_1F163C_ToadInTheBox >= 60)) {
        gSPDisplayList(D_800FDBCC_FE7CC++, D_8010AB50_1F0D00_ToadInTheBox);
        gDPSetRenderMode(D_800FDBCC_FE7CC++, 0, 0x5041C8);
        gDPSetCombineLERP(D_800FDBCC_FE7CC++, 0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE);
        gDPSetPrimColor(D_800FDBCC_FE7CC++, 0, 0, 0, 0, 0, D_8010B492_1F1642_ToadInTheBox != 6 || _CheckFlag(0xC) ? (D_8010B48C_1F163C_ToadInTheBox < 70 ? (u8)((f32)(D_8010B48C_1F163C_ToadInTheBox - 60) / 10.0f * 96.0) : 0x60) : 0x60);
        gDPFillRectangle(D_800FDBCC_FE7CC++, 0, 0, D_8010B4C0_1F1670_ToadInTheBox * 70 + 20, 240);
        gDPFillRectangle(D_800FDBCC_FE7CC++, D_8010B4C0_1F1670_ToadInTheBox * 70 + 90, 0, 320, 240);
    }
}

void func_80109798_1EF948_ToadInTheBox(s16 spr) {
    func_801097C4_1EF974_ToadInTheBox(spr, 0.0f, 0.0f, 1.0f);
}

void func_801097C4_1EF974_ToadInTheBox(s16 spr, f32 x, f32 y, f32 scale) {
    HuSprite* s;
    HuSprite_Unk84_Unk00_Struct* frame;
    s16 tx;
    s16 ty;
    f32 x0;
    f32 x1;
    f32 y0;
    f32 y1;

    if (scale < 1.0f) {
        scale = 1.0f;
    }
    s = func_80082550_83150(D_800F93FC_F9FFC[spr].unk_04, 0);
    frame = &s->unk_84->unk00[s->unk_90];
    gSPDisplayList(D_800FDBCC_FE7CC++, D_8010AB08_1F0CB8_ToadInTheBox);
    gDPSetTextureLUT(D_800FDBCC_FE7CC++, G_TT_RGBA16);
    gDPLoadTLUT_pal256(D_800FDBCC_FE7CC++, s->unk_84->unk0C);
    for (ty = 0; ty < 240; ty += 40) {
        for (tx = 0; tx < 320; tx += 40) {
            if ((D_8010B496_1F1646_ToadInTheBox - 1) % 20 >= 10 && tx >= 40 && tx < 280 && ty >= 80) {
                continue;
            }
            x0 = (f32)(tx - 160) * scale + 160.0f + x;
            x1 = (f32)(tx - 119) * scale + 160.0f + x;
            y0 = (f32)(ty - 120) * scale + 120.0f + y;
            y1 = (f32)(ty - 79) * scale + 120.0f + y;
            gDPLoadTextureTile(D_800FDBCC_FE7CC++, frame->unk00, G_IM_FMT_CI, G_IM_SIZ_8b, 320, 240, tx, ty, tx + 41,
                               ty + 41, 0, G_TX_MIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_CLAMP, 0, 0, 0, 0);
            gSPScisTextureRectangle(D_800FDBCC_FE7CC++, TB_FIX(x0), TB_FIX(y0), TB_FIX(x1), TB_FIX(y1),
                                    G_TX_RENDERTILE, tx << 5, ty << 5, 0x400, 0x400);
        }
    }
    if ((D_8010B496_1F1646_ToadInTheBox - 1) % 20 >= 10) {
        s = func_80082550_83150(D_800F93FC_F9FFC[D_8010B494_1F1644_ToadInTheBox].unk_04, 0);
        frame = &s->unk_84->unk00[s->unk_90];
        gDPLoadTLUT_pal256(D_800FDBCC_FE7CC++, s->unk_84->unk0C);
        for (ty = 0; ty < 160; ty += 40) {
            for (tx = 0; tx < 240; tx += 40) {
                x0 = tx;
                x1 = tx + 41;
                x1 = x1 >= 240.0f ? 240.0f : x1;
                x1 = x1 >= 240.0f ? 240.0f : x1;
                y0 = ty + y;
                y1 = y0 + 41.0f;
                y1 = y1 >= 160.0f ? 160.0f : y1;
                gDPLoadTextureTile(D_800FDBCC_FE7CC++, frame->unk00, G_IM_FMT_CI, G_IM_SIZ_8b, 240, 160, tx, ty, tx + 41,
                                   ty + 41, 0, G_TX_MIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_CLAMP, 0, 0, 0, 0);
                gSPScisTextureRectangle(D_800FDBCC_FE7CC++, TB_FIX2(x0 + 40.0f, x0), TB_FIX2(y0 + 80.0f, y0), TB_FIX2(x1 + 40.0f, x1),
                                        TB_FIX2(y1 + 80.0f, y1), G_TX_RENDERTILE, tx << 5, ty << 5, 0x400, 0x400);
            }
        }
    }
    if (D_8010B492_1F1642_ToadInTheBox == 0 && D_8010B48C_1F163C_ToadInTheBox < 75) {
        gSPDisplayList(D_800FDBCC_FE7CC++, D_8010AB50_1F0D00_ToadInTheBox);
        gDPSetRenderMode(D_800FDBCC_FE7CC++, 0, 0x5041C8);
        gDPSetCombineLERP(D_800FDBCC_FE7CC++, 0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE);
        gDPSetAlphaDither(D_800FDBCC_FE7CC++, G_AD_PATTERN);
        gDPSetPrimColor(D_800FDBCC_FE7CC++, 0, 0, 0, 0, 0, D_8010B48C_1F163C_ToadInTheBox < 45 ? 0x60 : 0x60 - (u8)((f32)(D_8010B48C_1F163C_ToadInTheBox - 45) / 30.0f * 96.0));
        gDPFillRectangle(D_800FDBCC_FE7CC++, 0, 0, 320, 240);
    }
    if ((D_8010B492_1F1642_ToadInTheBox == 6 && !_CheckFlag(0xC)) || (D_8010B492_1F1642_ToadInTheBox == 2 && D_8010B48C_1F163C_ToadInTheBox >= 60)) {
        gSPDisplayList(D_800FDBCC_FE7CC++, D_8010AB50_1F0D00_ToadInTheBox);
        gDPSetRenderMode(D_800FDBCC_FE7CC++, 0, 0x5041C8);
        gDPSetCombineLERP(D_800FDBCC_FE7CC++, 0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE);
        gDPSetPrimColor(D_800FDBCC_FE7CC++, 0, 0, 0, 0, 0, D_8010B492_1F1642_ToadInTheBox != 6 || _CheckFlag(0xC) ? (D_8010B48C_1F163C_ToadInTheBox < 70 ? (u8)((f32)(D_8010B48C_1F163C_ToadInTheBox - 60) / 10.0f * 96.0) : 0x60) : 0x60);
        gDPFillRectangle(D_800FDBCC_FE7CC++, D_8010B4C0_1F1670_ToadInTheBox * 70 + 20, 0, D_8010B4C0_1F1670_ToadInTheBox * 70 + 90, 240);
    }
}
