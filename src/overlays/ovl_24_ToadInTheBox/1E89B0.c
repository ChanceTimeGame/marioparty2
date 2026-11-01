#include "ovl_24.h"

/* .data (0x1F0CB0-0x1F0D40, 8010AB00-8010AB90) */
s16 D_8010AB00_1F0CB0_ToadInTheBox[4] = { 0x20, 0x30, 0x50, 0x60 }; /* sound pan per player */

Gfx D_8010AB08_1F0CB8_ToadInTheBox[] = {
    {{0xE7000000, 0x00000000}},
    {{0xE3000A01, 0x00000000}},
    {{0xFCFFFFFF, 0xFFFCF279}},
    {{0xE200001C, 0x0F0A4000}},
    {{0xE2001E01, 0x00000000}},
    {{0xE3000C00, 0x00000000}},
    {{0xE3001201, 0x00000000}},
    {{0xED000000, 0x005003C0}},
    {{0xDF000000, 0x00000000}},
};

Gfx D_8010AB50_1F0D00_ToadInTheBox[] = {
    {{0xE7000000, 0x00000000}},
    {{0xE3000A01, 0x00000000}},
    {{0xE3000C00, 0x00000000}},
    {{0xE3001201, 0x00000000}},
    {{0xE3001001, 0x00000000}},
    {{0xE3001A01, 0x00000030}},
    {{0xDF000000, 0x00000000}},
    {{0x00000000, 0x00000000}},
};

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

void func_8010377C_1E992C_ToadInTheBox(omObjData* obj) {
    s16 i;
    u8 h;
    u32 m2;
    s32 m;
    MgWork* w;
    TBBox* box;
    omObjData* x;
    f32 t;

    switch (D_8010B492_1F1642_ToadInTheBox) {
    case 0:
        if (D_8010B48C_1F163C_ToadInTheBox != 0) {
            if (D_8010B48C_1F163C_ToadInTheBox - 15 < 31) {
                t = 1.0 - (f32)(D_8010B48C_1F163C_ToadInTheBox - 15) / 30.0f;
                t = t * t;
                t = t * t;
                for (i = 0; i < 4; i++) {
                    x = D_8010B4A0_1F1650_ToadInTheBox[i];
                    func_80029714_2A314(x->model[1], x->trans.x, x->trans.y + t * 6.0 * 80.0 - 1000.0, x->trans.z);
                }
            } else if (D_8010B48C_1F163C_ToadInTheBox - 46 < 29) {
                func_8002D0A0_2DCA0(*D_8010B498_1F1648_ToadInTheBox->model, (u8)((1.0 - (f32)(D_8010B48C_1F163C_ToadInTheBox - 45) / 30.0f) * 255.0));
            }
        }
        if (D_8010B48C_1F163C_ToadInTheBox == 60) {
            func_800691FC_69DFC(0);
            if (D_8010B452_1F1602_ToadInTheBox == 0 && D_801011FC_101DFC == 0) {
                PlayMusic(0x2B);
            }
        }
        if (D_8010B48C_1F163C_ToadInTheBox == 75) {
            func_8002D0A0_2DCA0(*D_8010B498_1F1648_ToadInTheBox->model, 0xFF);
            func_800298A4_2A4A4(*D_8010B498_1F1648_ToadInTheBox->model, 4, 4);
            func_800298A4_2A4A4(D_8010B498_1F1648_ToadInTheBox->model[1], 4, 4);
            func_800298A4_2A4A4(D_8010B498_1F1648_ToadInTheBox->model[2], 4, 4);
            func_800298A4_2A4A4(D_8010B498_1F1648_ToadInTheBox->model[3], 4, 4);
        }
        if (D_8010B48C_1F163C_ToadInTheBox == 97) {
            for (i = 0; i < 4; i++) {
                D_8010B428_1F15D8_ToadInTheBox[i]->state = 3;
                D_8010B428_1F15D8_ToadInTheBox[i]->time = 0;
                D_8010B4A0_1F1650_ToadInTheBox[i]->trans.y = 280.0f;
            }
        }
        if (D_8010B48C_1F163C_ToadInTheBox != 105) {
            break;
        }
        D_8010B492_1F1642_ToadInTheBox = 1;
        D_8010B48C_1F163C_ToadInTheBox = 0;
        func_8000C3B8_CFB8();
        func_8000C3C8_CFC8();
    case 1:
        if (D_8010B48C_1F163C_ToadInTheBox >= 0xFFFFFFFF) {
            D_8010B48C_1F163C_ToadInTheBox = 0xFFFFFFFF;
        }
        for (i = 0; i < 4; i++) {
            if (D_8010B428_1F15D8_ToadInTheBox[(D_8010B48C_1F163C_ToadInTheBox & 1) ? i : 3 - i]->state == 5 && D_8010B428_1F15D8_ToadInTheBox[(D_8010B48C_1F163C_ToadInTheBox & 1) ? i : 3 - i]->time >= 36
                && D_8010B3B8_1F1568_ToadInTheBox[(D_8010B48C_1F163C_ToadInTheBox & 1) ? i : 3 - i]->hits >= 4) {
                break;
            }
        }
        if (i < 4) {
            D_8010B4C0_1F1670_ToadInTheBox = (D_8010B48C_1F163C_ToadInTheBox & 1) ? i : 3 - i;
            D_8010B492_1F1642_ToadInTheBox = 2;
            D_8010B48C_1F163C_ToadInTheBox = 0;
        }
        if (D_8010B48C_1F163C_ToadInTheBox >= 9000) {
            if (D_8010B474_1F1624_ToadInTheBox != 0) {
                D_8010B4C0_1F1670_ToadInTheBox = D_8010B474_1F1624_ToadInTheBox - 1;
                D_8010B492_1F1642_ToadInTheBox = 2;
            } else {
                D_8010B4C0_1F1670_ToadInTheBox = 4;
                D_8010B492_1F1642_ToadInTheBox = 4;
            }
            D_8010B48C_1F163C_ToadInTheBox = 0;
        }
        if (D_8010B48C_1F163C_ToadInTheBox == 8100 && D_8010B492_1F1642_ToadInTheBox == 1) {
            func_800691FC_69DFC(0xA, 0x1E, 0xA0, 0x20);
        }
        if (D_8010B492_1F1642_ToadInTheBox != 2) {
            if ((9000 - D_8010B48C_1F163C_ToadInTheBox) / 30 + 1 == 0 || D_8010B492_1F1642_ToadInTheBox == 4) {
                func_8006D4D0_6E0D0(0);
            } else {
                func_8006D4D0_6E0D0((9000 - D_8010B48C_1F163C_ToadInTheBox) / 30 + 1);
            }
        }
        break;
    case 2:
        if (D_8010B48C_1F163C_ToadInTheBox == 1) {
            for (i = 0; i < 4; i++) {
                MgWork* v = D_8010B458_1F1608_ToadInTheBox[i]->unk_50;

                if (i != D_8010B4C0_1F1670_ToadInTheBox) {
                    if (D_8010B428_1F15D8_ToadInTheBox[i]->state != 5 && (D_8010B428_1F15D8_ToadInTheBox[i]->state != 6 || D_8010B428_1F15D8_ToadInTheBox[i]->time >= 11)) {
                        D_8010B428_1F15D8_ToadInTheBox[i]->state = 11;
                        D_8010B428_1F15D8_ToadInTheBox[i]->time = 0;
                    }
                }
                if (v->unk_50 == 2 && TB_A8(v) < 60) {
                    TB_A8(v) = 60;
                } else if (v->unk_50 == 1) {
                    TB_A8(v) = 120;
                }
                D_8010B4A0_1F1650_ToadInTheBox[i]->trans.y = 1280.0f;
            }
            func_800794A8_7A0A8(0x28);
            func_800691FC_69DFC(3);
        } else if (D_8010B48C_1F163C_ToadInTheBox == 59) {
            if (D_8010B428_1F15D8_ToadInTheBox[D_8010B4C0_1F1670_ToadInTheBox]->state != 12) {
                D_8010B48C_1F163C_ToadInTheBox = 58;
            }
        } else if (D_8010B48C_1F163C_ToadInTheBox == 60) {
            f32 a[4] = { 22.5f, 12.5f, 0.0f, -7.5f };

            for (i = 0; i < 4; i++) {
                if (D_8010B428_1F15D8_ToadInTheBox[i]->state == 5 && D_8010B428_1F15D8_ToadInTheBox[i]->time < 11) {
                    D_8010B428_1F15D8_ToadInTheBox[i]->state = 11;
                    D_8010B428_1F15D8_ToadInTheBox[i]->time = 0;
                    D_8010B428_1F15D8_ToadInTheBox[i]->unk_14 = D_800FC834_FD434[D_8010B4A0_1F1650_ToadInTheBox[i]->model[1]].pos.y;
                } else if (D_8010B428_1F15D8_ToadInTheBox[i]->state == 5 && D_8010B428_1F15D8_ToadInTheBox[i]->time >= 11) {
                    D_8010B428_1F15D8_ToadInTheBox[i]->state = 11;
                    D_8010B428_1F15D8_ToadInTheBox[i]->time = 0;
                    D_8010B428_1F15D8_ToadInTheBox[i]->unk_14 = D_800FC834_FD434[*D_8010B478_1F1628_ToadInTheBox[i]->model].pos.y + 55.0;
                } else if (D_8010B428_1F15D8_ToadInTheBox[i]->state == 6 && D_8010B428_1F15D8_ToadInTheBox[i]->time < 11) {
                    D_8010B428_1F15D8_ToadInTheBox[i]->state = 11;
                    D_8010B428_1F15D8_ToadInTheBox[i]->time = 0;
                    D_8010B428_1F15D8_ToadInTheBox[i]->unk_14 = D_800FC834_FD434[D_8010B478_1F1628_ToadInTheBox[i]->model[3]].pos.y + 55.0;
                } else {
                    D_8010B428_1F15D8_ToadInTheBox[i]->state = 12;
                    D_8010B428_1F15D8_ToadInTheBox[i]->time = 0;
                }
            }
            gPlayers[D_8010B4C0_1F1670_ToadInTheBox].coins_mg_bonus += 10;
            if (!_CheckFlag(0xC)) {
                s32 b[6] = { 2, 3, 7, 4, 5, 6 };

                if (D_8010B452_1F1602_ToadInTheBox == 0 && D_801011FC_101DFC == 0) {
                    PlayMusic(0x51);
                }
                func_80079518_7A118(0x7F);
                m2 = b[D_8010B3B8_1F1568_ToadInTheBox[D_8010B4C0_1F1670_ToadInTheBox]->character] << 16;
                if (D_8010B4CC_1F167C_ToadInTheBox != 0) {
                    m2 |= 0x4E;
                } else {
                    m2 |= 0x4F;
                }
                func_800732B0_73EB0(m2);
                func_800691FC_69DFC(6, D_8010B3B8_1F1568_ToadInTheBox[D_8010B4C0_1F1670_ToadInTheBox]->character);
                if (9000 - D_8010B48C_1F163C_ToadInTheBox < 0x385) {
                    func_8006D518_6E118();
                }
                func_800298A4_2A4A4(*D_8010B498_1F1648_ToadInTheBox->model, 4, 0);
                omSetTra(D_8010B498_1F1648_ToadInTheBox, D_8010B4C0_1F1670_ToadInTheBox * 278.0 - 422.0 + a[D_8010B4C0_1F1670_ToadInTheBox], -25.0f, 0.0f);
                omSetTra(D_8010B498_1F1648_ToadInTheBox, D_8010B4C0_1F1670_ToadInTheBox * 245.0 * 1.08 + -396.90000000000003, -15.0f, 0.0f);
                omSetSca(D_8010B498_1F1648_ToadInTheBox, 0.0f, 0.5f, 0.8f);
                omSetRot(D_8010B498_1F1648_ToadInTheBox, 0.0f, 0.0f, 0.0f);
                for (i = 0; i < 4; i++) {
                    if (D_8010B4C0_1F1670_ToadInTheBox != i) {
                        h = D_8010B3B8_1F1568_ToadInTheBox[i]->hits;
                        if (h < 3 || (h == 3 && (rand8() & 1))) {
                        m = 0xE;
                        } else {
                        m = 0xC;
                        }
                    } else {
                        m = 0xD;
                    }
                    func_80019B9C_1A79C(D_8010B458_1F1608_ToadInTheBox[i], m);
                }
            } else {
                D_8010B492_1F1642_ToadInTheBox = 6;
                D_8010B48C_1F163C_ToadInTheBox = 0;
            }
        } else if (D_8010B48C_1F163C_ToadInTheBox - 61 < 30) {
                t = 1.0 - (f32)(D_8010B48C_1F163C_ToadInTheBox - 60) / 30.0f;
                omSetSca(D_8010B498_1F1648_ToadInTheBox, (1.0 - t * t) * 0.4, 0.5f, 0.8f);
                if (D_8010B48C_1F163C_ToadInTheBox == 62) {
                    func_800297E8_2A3E8(D_8010B458_1F1608_ToadInTheBox[D_8010B4C0_1F1670_ToadInTheBox]->model[1], 1.0f, 1.0f, 0.5f);
                }
                if (D_8010B48C_1F163C_ToadInTheBox == 63) {
                    func_800297E8_2A3E8(D_8010B458_1F1608_ToadInTheBox[D_8010B4C0_1F1670_ToadInTheBox]->model[1], 1.0f, 1.0f, 0.0f);
                }
        } else if (D_8010B48C_1F163C_ToadInTheBox == 180) {
            D_8010B492_1F1642_ToadInTheBox = 6;
            D_8010B48C_1F163C_ToadInTheBox = 0;
        }
        break;
    case 6:
        if (D_8010B48C_1F163C_ToadInTheBox == 1) {
            InitFadeOut(0, 0x14);
        } else if (D_8010B48C_1F163C_ToadInTheBox >= 25) {
            D_8010B452_1F1602_ToadInTheBox = 1;
        }
        break;
    case 4:
        if (D_8010B48C_1F163C_ToadInTheBox == 1) {
            for (i = 0; i < 4; i++) {
                w = D_8010B458_1F1608_ToadInTheBox[i]->unk_50;
                box = D_8010B428_1F15D8_ToadInTheBox[i];
                if (box->state != 5 && (box->state != 6 || box->time >= 11)) {
                    D_8010B428_1F15D8_ToadInTheBox[i]->state = 11;
                    D_8010B428_1F15D8_ToadInTheBox[i]->time = 0;
                }
                if (w->unk_50 == 2 && TB_A8(w) < 60) {
                    TB_A8(w) = 60;
                } else if (w->unk_50 == 1) {
                    TB_A8(w) = 120;
                }
                D_8010B4A0_1F1650_ToadInTheBox[i]->trans.y = 1280.0f;
            }
            func_800794A8_7A0A8(0x28);
            func_800691FC_69DFC(3);
            func_8006D4D0_6E0D0(0);
        } else if (D_8010B48C_1F163C_ToadInTheBox == 60) {
            if (!_CheckFlag(0xC)) {
                for (i = 0; i < 4; i++) {
                    if (D_8010B428_1F15D8_ToadInTheBox[i]->state == 5 && D_8010B428_1F15D8_ToadInTheBox[i]->time < 11) {
                        D_8010B428_1F15D8_ToadInTheBox[i]->state = 11;
                        D_8010B428_1F15D8_ToadInTheBox[i]->time = 0;
                        D_8010B428_1F15D8_ToadInTheBox[i]->unk_14 = D_800FC834_FD434[D_8010B4A0_1F1650_ToadInTheBox[i]->model[1]].pos.y;
                    } else if (D_8010B428_1F15D8_ToadInTheBox[i]->state == 5 && D_8010B428_1F15D8_ToadInTheBox[i]->time >= 11) {
                        D_8010B428_1F15D8_ToadInTheBox[i]->state = 11;
                        D_8010B428_1F15D8_ToadInTheBox[i]->time = 0;
                        D_8010B428_1F15D8_ToadInTheBox[i]->unk_14 = D_800FC834_FD434[*D_8010B478_1F1628_ToadInTheBox[i]->model].pos.y + 55.0;
                    } else if (D_8010B428_1F15D8_ToadInTheBox[i]->state == 6 && D_8010B428_1F15D8_ToadInTheBox[i]->time < 11) {
                        D_8010B428_1F15D8_ToadInTheBox[i]->state = 11;
                        D_8010B428_1F15D8_ToadInTheBox[i]->time = 0;
                        D_8010B428_1F15D8_ToadInTheBox[i]->unk_14 = D_800FC834_FD434[D_8010B478_1F1628_ToadInTheBox[i]->model[3]].pos.y + 55.0;
                    } else {
                        D_8010B428_1F15D8_ToadInTheBox[i]->state = 12;
                        D_8010B428_1F15D8_ToadInTheBox[i]->time = 0;
                    }
                }
                if (D_8010B452_1F1602_ToadInTheBox == 0 && D_801011FC_101DFC == 0) {
                    PlayMusic(0x57);
                }
                func_8006D518_6E118();
                func_800691FC_69DFC(0x13);
                func_80079518_7A118(0x7F);
                func_8006D518_6E118();
                for (i = 0; i < 4; i++) {
                    h = D_8010B3B8_1F1568_ToadInTheBox[i]->hits;
                    if (h < 3 || (h == 3 && (rand8() & 1))) {
                        m = 0xE;
                        } else {
                        m = 0xC;
                        }
                    func_80019B9C_1A79C(D_8010B458_1F1608_ToadInTheBox[i], m);
                }
            } else {
                D_8010B492_1F1642_ToadInTheBox = 6;
                D_8010B48C_1F163C_ToadInTheBox = 0;
            }
        } else if (D_8010B48C_1F163C_ToadInTheBox == 180) {
            InitFadeOut(0, 0x14);
        } else if (D_8010B48C_1F163C_ToadInTheBox >= 205) {
            D_8010B452_1F1602_ToadInTheBox = 1;
        }
        break;
    }
    D_8010B48C_1F163C_ToadInTheBox++;
    if (D_8010B452_1F1602_ToadInTheBox != 0 || D_801011FC_101DFC != 0) {
        if (D_801011FC_101DFC != 0) {
            if (D_8010B490_1F1640_ToadInTheBox == 0) {
                InitFadeOut(0, 0x14);
                func_800794A8_7A0A8(0x14);
                func_80079614_7A214(0x14);
            }
            D_8010B490_1F1640_ToadInTheBox++;
            if (D_8010B490_1F1640_ToadInTheBox < 25) {
                return;
            }
        }
        func_800794A8_7A0A8(0x28);
        omOvlReturnEx(1);
    }
}

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

#ifdef NON_MATCHING
/* NON_MATCHING: class 4, register/schedule; masked 30 lines, same calls and branches. Loop test and mtc1/cvt order differ. */
void func_80105950_1EBB00_ToadInTheBox(omObjData* obj) {
    s16 pl;
    s16 prev;
    MgWork* w = obj->unk_50;
    s8 pl8 = w->unk_59;
    f32 spd[6] = { 7.5f, 12.5f, 17.5f, 25.0f, 50.0f, 0.0f };
    TBInfo* info;
    TBBox* box;
    u16 btn;
    u16 trg;
    u16 d410;
    s8 stkx;
    s8 stky;
    s16 d9be;
    s16 d468;
    s32 mask;
    f32 t0;
    f32 t1;
    f32 t2;
    f32 c;
    f32 h;
    f32 v;
    f32 r;
    f32 t3;
    f32 x;
    f32 f;
    f64 d;
    s32 k;
    s32 a;
    s32 i1;
    s16 j;
    s16 snd;
    MgWork* m;
    omObjData* o;
    u8 u;
    u8 z;
    u16 cnt;
    s16 st;
    s16 st2s;
    u16 st2;
    f32* p;

    prev = -1;
    pl = pl8;
    info = D_8010B3B8_1F1568_ToadInTheBox[pl8];
    box = D_8010B428_1F15D8_ToadInTheBox[pl8];
    if (D_8010B492_1F1642_ToadInTheBox == 0 && D_8010B48C_1F163C_ToadInTheBox < 2) {
        return;
    }
    if (pl == 0) {
        D_8010B470_1F1620_ToadInTheBox[0] = D_8010B470_1F1620_ToadInTheBox[1] = D_8010B470_1F1620_ToadInTheBox[2] = D_8010B470_1F1620_ToadInTheBox[3] = 0;
    }
    btn = ContBtn[info->port];
    trg = ContBtnTrg[info->port];
    d410 = D_800FD410_FE010[info->port];
    stkx = ContStkX[info->port];
    stky = ContStkY[info->port];
    d9be = D_800FC9BE_FD5BE[info->port];
    d468 = D_800FD468_FE068[info->port];
    mask = (box->state == 2 && info->cpu == -1 && D_8010B492_1F1642_ToadInTheBox == 1) << 15;
    ContBtn[info->port] &= mask;
    ContBtnTrg[info->port] &= mask;
    D_800FD410_FE010[info->port] &= mask;
    ContStkX[info->port] = 0;
    ContStkY[info->port] = 0;
    D_800FC9BE_FD5BE[info->port] = 0;
    D_800FD468_FE068[info->port] = 0;
    if (box->state == 2 && D_8010B492_1F1642_ToadInTheBox == 1 && TB_A8(obj->unk_50) == 0) {
        switch ((s8)(info->cpu + 1)) {
        case 1:
            switch (info->cpuState) {
            case 0:
                info->cpuState++;
                info->cpuTime = rand8() % 90 + 30;
            case 1:
                if (--info->cpuTime == 0) {
                    info->cpuState++;
                    ContBtn[info->port] = 0x8000;
                    ContBtnTrg[info->port] = 0x8000;
                }
                break;
            case 2:
                break;
            }
            break;
        case 2:
            switch (info->cpuState) {
            case 0:
                info->cpuState++;
                info->cpuTime = rand8() % 60 + 20 + info->hits;
            case 1:
                if (--info->cpuTime != 0) {
                    break;
                }
                info->cpuState++;
                info->cpuTime = rand8() % 12 - 4;
            case 2:
                p = &spd[info->hits];
                f = (f32)(s32)((info->cpuTime * *p + box->angle + 45.0 + 360.0 - *p * 0.5) / 90.0) * 90.0 - 360.0;
                if ((f32)TB_MOD360(f) == 0.0) {
                    info->cpuState++;
                    ContBtn[info->port] = 0x8000;
                    ContBtnTrg[info->port] = 0x8000;
                }
                break;
            case 3:
                info->cpuState--;
                break;
            }
            break;
        case 3:
            switch (info->cpuState) {
            case 0:
                info->cpuState++;
                info->cpuTime = rand8() % 20 + 15 + info->hits * 10;
            case 1:
                if (--info->cpuTime != 0) {
                    break;
                }
                info->cpuState++;
                info->cpuTime = (rand8() & 7) - 4;
            case 2:
                p = &spd[info->hits];
                f = (f32)(s32)((info->cpuTime * *p + box->angle + 45.0 + 360.0 - *p * 0.5) / 90.0) * 90.0 - 360.0;
                if ((f32)TB_MOD360(f) == 0.0) {
                    info->cpuState++;
                    ContBtn[info->port] = 0x8000;
                    ContBtnTrg[info->port] = 0x8000;
                }
                break;
            case 3:
                info->cpuState--;
                break;
            }
            break;
        case 4:
            switch (info->cpuState) {
            case 0:
                info->cpuState++;
                a = rand8() % 30 + 10;
                k = rand8() % 10 + 10;
                if (info->hits != 1) {
                    k = 3;
                } else {
                    k = k + 3;
                }
                i1 = k;
                if (info->hits == 2) {
                    i1 = k + a;
                }
                info->cpuTime = i1;
            case 1:
                if (--info->cpuTime != 0) {
                    break;
                }
                if (info->hits >= 3) {
                    info->cpuState = 4;
                    info->cpuTime = rand8() % 10 + 1;
                    break;
                }
                info->cpuState++;
                info->cpuTime = rand8() & 3;
            case 2:
                p = &spd[info->hits];
                f = (f32)(s32)((info->cpuTime * *p + box->angle + 45.0 + 360.0 - *p * 0.5) / 90.0) * 90.0 - 360.0;
                if ((f32)TB_MOD360(f) == 0.0) {
                    info->cpuState++;
                    ContBtn[info->port] = 0x8000;
                    ContBtnTrg[info->port] = 0x8000;
                }
                break;
            case 4:
                if (--info->cpuTime != 0) {
                    break;
                }
                info->cpuState++;
            case 5:
                info->cpuState++;
                ContBtn[info->port] = 0x8000;
                ContBtnTrg[info->port] = 0x8000;
                break;
            case 3:
            case 6:
                info->cpuState--;
                break;
            }
            break;
        case 0:
            info->cpuState = 0;
            info->cpuTime = 0;
            break;
        }
    }
    func_80007790_8390(obj);
    if (D_8010B492_1F1642_ToadInTheBox == 0 && D_8010B48C_1F163C_ToadInTheBox < 60) {
        func_80079848_7A448(w->unk_C5);
    }
    j = obj->model[1];
    func_8002979C_2A39C(j, D_800FC834_FD434[j].pos.y / 60.0 + 7.0, 0.0f, 0.0f);
    ContBtn[info->port] = btn;
    ContBtnTrg[info->port] = trg;
    D_800FD410_FE010[info->port] = d410;
    ContStkX[info->port] = stkx;
    ContStkY[info->port] = stky;
    D_800FC9BE_FD5BE[info->port] = d9be;
    D_800FD468_FE068[info->port] = d468;
    if (D_8010B468_1F1618_ToadInTheBox[pl] == 1) {
        func_800298A4_2A4A4(*D_8010B440_1F15F0_ToadInTheBox[pl]->model, 4, 4);
    }
    {
        u8 c0 = D_8010B468_1F1618_ToadInTheBox[pl];

        if (c0 != 0) {
            c0--;
        }
        D_8010B468_1F1618_ToadInTheBox[pl] = c0;
    }
    st2s = box->state;
    st = st2s;
    if (prev != st2s) {
        do {
            prev = st;
            switch (st) {
            case 0:
                break;
            case 11:
                if (box->time == 0) {
                    func_80109524_1EF6D4_ToadInTheBox(D_8010B440_1F15F0_ToadInTheBox[pl], 0);
                    omSetTra(D_8010B440_1F15F0_ToadInTheBox[pl], pl * 245.0 + -367.5 - 15.0, box->unk_14, 250.0f);
                    func_800298A4_2A4A4(*D_8010B440_1F15F0_ToadInTheBox[pl]->model, 4, 0);
                    func_80029C74_2A874(*D_8010B440_1F15F0_ToadInTheBox[pl]->model, 0.0f);
                    D_8010B468_1F1618_ToadInTheBox[pl] = 20;
                } else if (box->time == 10) {
                    box->state = 12;
                    box->time = 0;
                    func_800298A4_2A4A4(D_8010B4A0_1F1650_ToadInTheBox[pl]->model[1], 4, 4);
                    func_800298A4_2A4A4(*D_8010B4D0_1F1680_ToadInTheBox[pl]->model, 4, 4);
                    func_800298A4_2A4A4(*D_8010B478_1F1628_ToadInTheBox[pl]->model, 4, 4);
                    func_800298A4_2A4A4(D_8010B478_1F1628_ToadInTheBox[pl]->model[3], 4, 4);
                }
                break;
            case 1:
                if (box->time < 31) {
                    break;
                }
                box->state = 2;
                box->time = 0;
            case 3:
                if (box->time < 8) {
                    {
                        f64 e2;
    f64 e = box->angle = box->angle + spd[info->hits] * (box->time / 8.0);

                        if (e > 360.0) {
                            e2 = e - 360.0;
                        } else {
                            e2 = e - 0.0;
                        }
                        box->angle = e2;
                    }
                    func_8002979C_2A39C(D_8010B4A0_1F1650_ToadInTheBox[pl]->model[1], box->angle, 0.0f, 0.0f);
                } else {
                    box->state = 2;
                    box->time = 0;
                }
                break;
            case 2:
                if (box->unk_08 == 1) {
                    box->state = 4;
                    box->time = 0;
                    cnt = box->unk_0A;
                    if (cnt <= 0xFFFE) {
                        st2 = cnt + 1;
                    } else {
                        st2 = cnt;
                    }
                    box->unk_0A = st2;
                    info->cpuState = 0;
                } else {
                    {
                        f64 e2;
    f64 e = box->angle = box->angle + spd[info->hits];

                        if (e > 360.0) {
                            e2 = e - 360.0;
                        } else {
                            e2 = e - 0.0;
                        }
                        box->angle = e2;
                    }
                    func_8002979C_2A39C(D_8010B4A0_1F1650_ToadInTheBox[pl]->model[1], box->angle, 0.0f, 0.0f);
                }
                break;
            case 4:
                if (box->time == 0) {
                    t1 = box->unk_0A / 20.0;
                    t2 = (f32)D_8010B48C_1F163C_ToadInTheBox / 9000.0f;
                    h = info->hits / 4.0;
                    c = 0.0f;
                    if (info->cpu != -1) {
                        c = 1.0f;
                    }
                    x = (info->hits - (D_8010B3B8_1F1568_ToadInTheBox[(pl + 1) % 4]->hits + D_8010B3B8_1F1568_ToadInTheBox[(pl + 2) % 4]->hits + D_8010B3B8_1F1568_ToadInTheBox[(pl + 3) % 4]->hits) / 3.0) / 8.0;
                    {
                    f32 ang[5] = { 45.0f, 135.0f, 225.0f, 315.0f, 360.0f };

                    t2 = t2 >= 0.5 ? 1.0f : 2.0 * t2;
                    t3 = t1 >= 1.0 ? 1.0f : t1;
                    v = 1.0 - x * 1.25 + t2 * 0.25 + t3 * 0.625 - c * 0.25;
                    v = (v - 1.0) * (h * 0.5 + 0.5) + 1.0;
                    r = v < 0.25 - h * 0.75 ? 0.25 - h * 0.75 : (h * 0.25 + 1.75 < v ? h * 0.25 + 1.75 : v);
                    x = 1.0 - r;
                    ang[0] = 45.0 - x * 45.0;
                    ang[1] = 135.0 - x * 15.0;
                    ang[2] = x * 15.0 + 225.0;
                    ang[3] = x * 45.0 + 315.0;
                    box->unk_04 = box->angle;
                    for (j = 0; j < 5; j++) {
                        if (box->angle < ang[j]) {
                            box->angle = (f32)(s16)(j % 4) * 90.0;
                            break;
                        }
                    }
                    }
                    if (D_8010B474_1F1624_ToadInTheBox != 0 && D_8010B474_1F1624_ToadInTheBox < 5 && box->angle == 0.0 && info->hits == 4) {
                        box->unk_04 = box->angle = (f32)(rand8() % 3) * 90.0 + 90.0;
                        box->unk_04 += (f32)(rand8() % 20) - 10.0;
                    }
                    if (box->angle - box->unk_04 < -180.0) {
                        box->unk_04 -= 360.0;
                    }
                    if (box->angle - box->unk_04 > 180.0) {
                        box->unk_04 += 360.0;
                    }
                    if ((D_8010B474_1F1624_ToadInTheBox == 0 || D_8010B474_1F1624_ToadInTheBox >= 5) && box->angle == 0.0 && info->hits == 4) {
                        D_8010B474_1F1624_ToadInTheBox = 5;
                        D_8010B470_1F1620_ToadInTheBox[pl] = 1;
                    }
                }
                t0 = (f32)box->time / 10.0f * 0.75 + 0.25;
                func_8002979C_2A39C(D_8010B4A0_1F1650_ToadInTheBox[pl]->model[1], t0 * box->angle + box->unk_04 * (1.0 - t0), 0.0f, 0.0f);
                if (box->time >= 10) {
                    {
                        f64 e2;
                        f64 e = box->angle = box->angle - (f32)((s32)box->angle / 360) * 360.0;

                        if (e < 0.0) {
                            e2 = e + 360.0;
                        } else {
                            e2 = e + 0.0;
                        }
                        e = box->angle = e2;
                        k = 5;
                        if (e != 0.0) {
                            if (e != 90.0) {
                                k = 9;
                                if (e == 180.0) {
                                    k = 8;
                                }
                            } else {
                                k = 7;
                            }
                        }
                        box->state = k;
                    }
                    box->time = 0;
                    func_80029714_2A314(D_8010B4A0_1F1650_ToadInTheBox[pl]->model[1], pl * 245.0 + -367.5, info->hits * 78.0 + 280.0, 250.0f);
                } else if (box->time > 0) {
                    func_80029714_2A314(D_8010B4A0_1F1650_ToadInTheBox[pl]->model[1], pl * 245.0 + -367.5, info->hits * 78.0 + 280.0 + (-(f = box->time - 5) * f / 25.0f + 1.0) * 100.0, 250.0f);
                }
                break;
            case 6:
                if (box->time == 0) {
                    box->unk_0A = 0;
                    info->hits++;
                    func_800298A4_2A4A4(D_8010B4B0_1F1660_ToadInTheBox[pl]->model[info->hits], 4, 0);
                    D_8010B4A0_1F1650_ToadInTheBox[pl]->trans.x = pl * 245.0 + -367.5;
                    D_8010B4A0_1F1650_ToadInTheBox[pl]->trans.y = info->hits * 78.0 + 280.0;
                    D_8010B4A0_1F1650_ToadInTheBox[pl]->trans.z = 250.0f;
                    o = D_8010B4A0_1F1650_ToadInTheBox[pl];
                    func_80029714_2A314(o->model[1], o->trans.x, o->trans.y, o->trans.z);
                    func_8000BF54_CB54(D_8010B4A0_1F1650_ToadInTheBox[pl], 200.0f, 200.0f, -100.0f, -100.0f, 100.0f, 100.0f);
                    snd = func_80079798_7A398(0x266, pl);
                    func_800796F0_7A2F0(snd, rand8() % 100 - 50);
                    func_800798F8_7A4F8(snd, D_8010AB00_1F0CB0_ToadInTheBox[pl]);
                }
                if (box->time < 31) {
                    t0 = 1.0 - (f32)box->time / 24.0f;
                    t1 = 1.0 - (f32)(box->time + 1) / 24.0f;
                    t0 = 1.0 - t0;
                    t1 = 1.0 - t1;
                    if (info->hits == 5 && D_8010B4C0_1F1670_ToadInTheBox != pl) {
                        t0 = 0.0f;
                        if (box->time < 10) {
                            D_8010B4B0_1F1660_ToadInTheBox[pl]->trans.x = pl * 245.0 * 1.16 + -426.29999999999995;
                            D_8010B4B0_1F1660_ToadInTheBox[pl]->trans.z = -220.0f;
                            D_8010B4B0_1F1660_ToadInTheBox[pl]->trans.y = ((f32)(info->hits - 2) + 0.0f) * (info->hits == 1 ? 90.0 : 78.0) + 4.0;
                        }
                        if (box->time == 10 && info->hits >= 5 && D_8010B4C0_1F1670_ToadInTheBox != pl) {
                            box->state = 12;
                            box->time = 0;
                            func_800298A4_2A4A4(D_8010B478_1F1628_ToadInTheBox[pl]->model[3], 4, 4);
                        }
                    } else {
                        if (box->time >= 25) {
                            k = 29 - box->time;
                            t0 = (((box->time - 30) & 1 ? (f32)-k : (f32)k) / 4.0) * 0.041666666666666664 * 0.5 + 1.0;
                        }
                        if (box->time + 1 >= 25) {
                            k = 28 - box->time;
                            t1 = (((box->time - 29) & 1 ? (f32)-k : (f32)k) / 4.0) * 0.041666666666666664 * 0.333 + 1.0;
                        }
                        if (box->time + 1 == 30) {
                            t1 = 1.0f;
                        }
                        if (box->time < 30) {
                            D_8010B4B0_1F1660_ToadInTheBox[pl]->trans.x = pl * 245.0 * 1.16 + -426.29999999999995;
                            D_8010B4B0_1F1660_ToadInTheBox[pl]->trans.z = -220.0f;
                            D_8010B4B0_1F1660_ToadInTheBox[pl]->trans.y = ((f32)(info->hits - 2) + t1) * (info->hits == 1 ? 90.0 : 78.0) + 4.0;
                        }
                    }
                    if (box->time == 10) {
                        func_800298A4_2A4A4(D_8010B478_1F1628_ToadInTheBox[pl]->model[3], 4, 4);
                        func_8002D0A0_2DCA0(D_8010B478_1F1628_ToadInTheBox[pl]->model[3], 0xFF);
                    } else if (box->time < 10) {
                        func_8002D0A0_2DCA0(D_8010B478_1F1628_ToadInTheBox[pl]->model[3], (u8)((1.0 - (f32)box->time / 10.0f) * 160.0));
                        func_80029C74_2A874(D_8010B478_1F1628_ToadInTheBox[pl]->model[3], (box->time * 6) % 60);
                        func_80029714_2A314(D_8010B478_1F1628_ToadInTheBox[pl]->model[3], pl * 245.0 + -367.5, 230.0 - HuMathSin((box->time + 40) * 7.0) * ((1.0 - (f32)(box->time + 40) / 60.0f) * 25.0 + 25.0) + (info->hits - 1) * 78.0, 250.0f);
                    }
                    if (info->hits == 1) {
                        func_80029714_2A314(D_8010B4B0_1F1660_ToadInTheBox[pl]->model[1], pl * 245.0 * 1.054688 + -387.59784, -15.0f, 110.0f);
                        D_8010B4B0_1F1660_ToadInTheBox[pl]->scale.x = 1.75f;
                        D_8010B4B0_1F1660_ToadInTheBox[pl]->scale.y = (f32)box->time / 30.0f * 1.75f;
                        D_8010B4B0_1F1660_ToadInTheBox[pl]->scale.z = 1.0f;
                        func_800297E8_2A3E8(D_8010B4B0_1F1660_ToadInTheBox[pl]->model[1], 1.57375f, t0 * 1.57375, 1.0f);
                    } else {
                        func_80029714_2A314(D_8010B4B0_1F1660_ToadInTheBox[pl]->model[info->hits], pl * 245.0 * 1.054688 + -387.59784, -15.0f, (f32)(info->hits - 1) * -3.0 + 110.0);
                        for (j = 1; j < info->hits; j++) {
                            func_80029714_2A314(D_8010B4B0_1F1660_ToadInTheBox[pl]->model[j], pl * 245.0 * 1.054688 + -387.59784, (info->hits - j - 1) * 81.9642857 + -15.0 + t0 * 81.9642857, (f32)(j - 1) * -3.0 + 110.0);
                        }
                        func_800297E8_2A3E8(D_8010B4B0_1F1660_ToadInTheBox[pl]->model[info->hits], 1.57375f, t0 * 1.57375, 1.0f);
                    }
                }
                if (box->time >= 30) {
                    t0 = 1.0 - (f32)(box->time - 30) / 15.0f;
                    t0 = t0 * t0;
                    if (box->time == 30) {
                        box->angle = (u8)D_8010B4C1_1F1671_ToadInTheBox[info->hits - 1] * 90;
                        if (info->hits >= 5 || D_8010B492_1F1642_ToadInTheBox != 1) {
                            box->state = 12;
                            box->time = 0;
                        } else {
                            func_800298A4_2A4A4(D_8010B4A0_1F1650_ToadInTheBox[pl]->model[1], 4, 0);
                        }
                        func_8002979C_2A39C(D_8010B4A0_1F1650_ToadInTheBox[pl]->model[1], box->angle, 0.0f, 0.0f);
                    }
                    if (box->time >= 45) {
                        box->state = D_8010B492_1F1642_ToadInTheBox == 1 ? 2 : 12;
                        box->time = 0;
                    } else if (info->hits < 5) {
                        k = (info->hits + 3) * 3;
                        if (box->time >= 45 - k) {
                            {
                                f64 e2;
    f64 e = box->angle = (p = &spd[info->hits], (f32)(k - 45 + box->time) / (f32)k * *p) + box->angle;

                                if (e > 360.0) {
                                    e2 = e - 360.0;
                                } else {
                                    e2 = e - 0.0;
                                }
                                box->angle = e2;
                            }
                            func_8002979C_2A39C(D_8010B4A0_1F1650_ToadInTheBox[pl]->model[1], box->angle, 0.0f, 0.0f);
                        }
                    }
                    o = D_8010B4A0_1F1650_ToadInTheBox[pl];
                    func_80029714_2A314(o->model[1], o->trans.x, o->trans.y + (t0 * (f32)(6 - info->hits)) * 80.0, o->trans.z);
                }
                break;
            case 5:
                if (box->time == 0) {
                    func_80109524_1EF6D4_ToadInTheBox(D_8010B440_1F15F0_ToadInTheBox[pl], 0);
                    omSetTra(D_8010B440_1F15F0_ToadInTheBox[pl], pl * 245.0 + -367.5 - 15.0, info->hits * 78.0 + 300.0, 250.0f);
                    func_800298A4_2A4A4(*D_8010B440_1F15F0_ToadInTheBox[pl]->model, 4, 0);
                    func_80029C74_2A874(*D_8010B440_1F15F0_ToadInTheBox[pl]->model, 0.0f);
                    D_8010B468_1F1618_ToadInTheBox[pl] = 20;
                    func_800798F8_7A4F8(func_80079798_7A398(0x269, pl), D_8010AB00_1F0CB0_ToadInTheBox[pl]);
                } else if (box->time == 10) {
                    func_800298A4_2A4A4(D_8010B4A0_1F1650_ToadInTheBox[pl]->model[1], 4, 4);
                    func_800298A4_2A4A4(*D_8010B478_1F1628_ToadInTheBox[pl]->model, 4, 0);
                    omSetTra(D_8010B478_1F1628_ToadInTheBox[pl], pl * 245.0 + -367.5, info->hits * 78.0 + 230.0, 250.0f);
                    func_80029B80_2A780(*D_8010B478_1F1628_ToadInTheBox[pl]->model, D_8010B478_1F1628_ToadInTheBox[0]->model[1]);
                    func_80029C74_2A874(*D_8010B478_1F1628_ToadInTheBox[pl]->model, 1.0f);
                    if (rand8() % 3 != 0) {
                        k = rand8() & 1 ? 0x26B : 0x26A;
                    } else {
                        k = 0x265;
                    }
                    func_800798F8_7A4F8(PlaySound(k), D_8010AB00_1F0CB0_ToadInTheBox[pl]);
                } else if (box->time >= 11 && box->time < 25) {
                    omSetTra(D_8010B478_1F1628_ToadInTheBox[pl], pl * 245.0 + -367.5, 230.0 - HuMathSin((box->time - 25) * 10.0) * ((1.0 - (f32)(box->time - 25) / 60.0f) * 25.0 + 35.0) + info->hits * 78.0, 250.0f);
                } else if (box->time >= 25 && box->time < 85) {
                    if (box->time == 25) {
                        func_80029B80_2A780(*D_8010B478_1F1628_ToadInTheBox[pl]->model, D_8010B478_1F1628_ToadInTheBox[0]->model[2]);
                        func_80029C74_2A874(*D_8010B478_1F1628_ToadInTheBox[pl]->model, 0.0f);
                        if (D_8010B496_1F1646_ToadInTheBox < 60 && D_8010B492_1F1642_ToadInTheBox == 1) {
                            D_8010B496_1F1646_ToadInTheBox = D_8010B496_1F1646_ToadInTheBox % 20 + 60;
                        }
                    }
                    func_80029C74_2A874(*D_8010B478_1F1628_ToadInTheBox[pl]->model, ((box->time - 25) * 6) % 60);
                    omSetTra(D_8010B478_1F1628_ToadInTheBox[pl], pl * 245.0 + -367.5, 230.0 - HuMathSin((box->time - 25) * 7.0) * ((1.0 - (f32)(box->time - 25) / 60.0f) * 25.0 + 25.0) + info->hits * 78.0, 250.0f);
                }
                if (box->time == 65) {
                    box->state = 6;
                    box->time = 0;
                    func_800298A4_2A4A4(*D_8010B478_1F1628_ToadInTheBox[pl]->model, 4, 4);
                    func_800298A4_2A4A4(D_8010B478_1F1628_ToadInTheBox[pl]->model[3], 4, 0);
                } else if (box->time == 85) {
                    func_800298A4_2A4A4(*D_8010B478_1F1628_ToadInTheBox[pl]->model, 4, 4);
                }
                break;
            case 9:
                if (box->time == 0) {
                    func_80109524_1EF6D4_ToadInTheBox(D_8010B440_1F15F0_ToadInTheBox[pl], 0);
                    omSetTra(D_8010B440_1F15F0_ToadInTheBox[pl], pl * 245.0 + -367.5 - 15.0, info->hits * 78.0 + 300.0, 250.0f);
                    func_800298A4_2A4A4(*D_8010B440_1F15F0_ToadInTheBox[pl]->model, 4, 0);
                    func_80029C74_2A874(*D_8010B440_1F15F0_ToadInTheBox[pl]->model, 2.0f);
                    D_8010B468_1F1618_ToadInTheBox[pl] = 20;
                    func_800798F8_7A4F8(func_80079798_7A398(0x269, pl), D_8010AB00_1F0CB0_ToadInTheBox[pl]);
                } else if (box->time == 10) {
                    func_800298A4_2A4A4(D_8010B4A0_1F1650_ToadInTheBox[pl]->model[1], 4, 4);
                    func_800298A4_2A4A4(*D_8010B4D0_1F1680_ToadInTheBox[pl]->model, 4, 0);
                    omSetTra(D_8010B4D0_1F1680_ToadInTheBox[pl], pl * 245.0 + -367.5, info->hits * 78.0 + 230.0, 250.0f);
                    func_80029B80_2A780(*D_8010B4D0_1F1680_ToadInTheBox[pl]->model, D_8010B4D0_1F1680_ToadInTheBox[0]->model[2]);
                    func_80029C74_2A874(*D_8010B4D0_1F1680_ToadInTheBox[pl]->model, 0.0f);
                    func_800798F8_7A4F8(PlaySound(0x268), D_8010AB00_1F0CB0_ToadInTheBox[pl]);
                } else if (box->time >= 11 && box->time < 300) {
                    f = box->time - 14;
                    t1 = (-(f * f) / 17.0f + 1.0) * 120.0;
                    t0 = D_800FC834_FD434[*D_8010B4D0_1F1680_ToadInTheBox[pl]->model].pos.y;
                    d = t1;
                    box->unk_14 = t0;
                    if (d > -220.0) {
                        omSetTra(D_8010B4D0_1F1680_ToadInTheBox[pl], pl * 245.0 + -367.5, info->hits * 78.0 + 230.0 + d, 250.0f);
                        func_80029C74_2A874(*D_8010B4D0_1F1680_ToadInTheBox[pl]->model, (f32)(box->time - 10) / 10.0f * 3.0);
                    } else {
                        m = obj->unk_50;
                        box->time = 300;
                        omSetTra(D_8010B4D0_1F1680_ToadInTheBox[pl], pl * 245.0 + -367.5, info->hits * 78.0 + 10.0, 250.0f);
                        func_80019B28_1A728(obj, 1);
                        TB_A8(m) = 20;
                        func_800191D4_19DD4(obj, 7, obj->trans.x, obj->trans.y, obj->trans.z, 0.0f, 0.0f);
                        func_800798F8_7A4F8(func_80079798_7A398(0x264, pl), D_8010AB00_1F0CB0_ToadInTheBox[pl]);
                        omVibrate(m->unk_59, 10, 0, 10);
                        func_80029C74_2A874(*D_8010B4D0_1F1680_ToadInTheBox[pl]->model, 7.0f);
                    }
                }
                if (box->time == 301) {
                    D_8010B450_1F1600_ToadInTheBox = D_8010B49C_1F164C_ToadInTheBox != 0 ? D_8010B450_1F1600_ToadInTheBox : 1;
                    D_8010B49C_1F164C_ToadInTheBox = D_8010B49C_1F164C_ToadInTheBox < 2 ? 2 : D_8010B49C_1F164C_ToadInTheBox;
                } else if (box->time >= 326 && box->time < 330) {
                    t0 = 1.0 - (f32)(box->time - 325) / 5.0f;
                    d = t0 * t0;
                    omSetSca(D_8010B4D0_1F1680_ToadInTheBox[pl], 1.0f, d * 0.1 + 0.9, 1.0f);
                    omSetRot(D_8010B4D0_1F1680_ToadInTheBox[pl], 5.0 - d * 5.0, 0.0f, 0.0f);
                } else if (box->time == 330) {
                    func_80029BF0_2A7F0(*D_8010B4D0_1F1680_ToadInTheBox[pl]->model, func_80029E14_2AA14(D_8010B4D0_1F1680_ToadInTheBox[0]->model[1]), 3, 2, 0);
                    omSetSca(D_8010B4D0_1F1680_ToadInTheBox[pl], 1.0f, 0.9f, 1.0f);
                    omSetRot(D_8010B4D0_1F1680_ToadInTheBox[pl], 5.0f, 0.0f, 0.0f);
                } else if (box->time >= 331) {
                    f = box->time - 340;
                    t1 = (-(f * f) / 100.0f + 1.0) * 170.0;
                    t0 = 1.0 - (f32)(box->time - 330) / 15.0f;
                    t0 = 1.0 - t0 * t0;
                    omSetTra(D_8010B4D0_1F1680_ToadInTheBox[pl], pl * 245.0 + -367.5, info->hits * 78.0 + 10.0 + t1, 250.0f);
                    omSetSca(D_8010B4D0_1F1680_ToadInTheBox[pl], 1.0f, 1.0f, 1.0f);
                    omSetRot(D_8010B4D0_1F1680_ToadInTheBox[pl], 0.0f, 0.0f, 0.0f);
                    func_80029C74_2A874(*D_8010B4D0_1F1680_ToadInTheBox[pl]->model, t0 > 0.5 ? 14.5f : 2.0 * t0 * 11.5 + 3.0);
                    if (box->time == 335) {
                        func_80109524_1EF6D4_ToadInTheBox(D_8010B440_1F15F0_ToadInTheBox[pl], 4);
                        func_80029C74_2A874(*D_8010B440_1F15F0_ToadInTheBox[pl]->model, 4.0f);
                        func_800298A4_2A4A4(*D_8010B440_1F15F0_ToadInTheBox[pl]->model, 4, 0);
                        D_8010B468_1F1618_ToadInTheBox[pl] = 20;
                    } else if (box->time >= 340) {
                        box->state = 10;
                        box->time = 0;
                        func_800298A4_2A4A4(*D_8010B4D0_1F1680_ToadInTheBox[pl]->model, 4, 4);
                        func_800298A4_2A4A4(D_8010B4A0_1F1650_ToadInTheBox[pl]->model[1], 4, 0);
                        break;
                    }
                } else if (box->time == 375) { /* never: retail tests it after >= 331 */
                    func_800298A4_2A4A4(*D_8010B440_1F15F0_ToadInTheBox[pl]->model, 4, 4);
                }
                {
                    MgWork* m2 = obj->unk_50;

                    if ((u32)(box->time - 300) < 30) {
                        cnt = TB_A8(m2);
                        if (cnt < 118) {
                            if (cnt >= 119) {
                                TB_A8(m2) = 118;
                            }
                        }
                    }
                    if (box->time < 330) {
                        if (TB_A8(m2) >= 119) {
                            TB_A8(m2) = 118;
                        }
                    }
                }
                break;
            case 10:
                m = obj->unk_50;
                if (TB_A8(m) >= 119 || TB_A8(m) == 0) {
                    box->state = 2;
                    box->time = 0;
                } else {
                    {
                        f64 e2;
    f64 e = box->angle = box->angle + spd[info->hits];

                        if (e > 360.0) {
                            e2 = e - 360.0;
                        } else {
                            e2 = e - 0.0;
                        }
                        box->angle = e2;
                    }
                    func_8002979C_2A39C(D_8010B4A0_1F1650_ToadInTheBox[pl]->model[1], box->angle, 0.0f, 0.0f);
                    if (TB_A8(m) < 118) {
                        if (info->cpu == -1 && (ContBtnTrg[m->unk_57] & 0x8000)) {
                            TB_A8(m) += 5;
                        }
                        if (TB_A8(m) >= 119) {
                            TB_A8(m) = 118;
                        }
                    }
                }
                break;
            case 7:
                if (box->time == 0) {
                    box->time = 5;
                }
                k = box->time - 10;
                if ((u32)k < 5) {
                    t0 = 1.0 - (f32)k / 5.0f;
                    t1 = 1.0 - t0 * (t0 * t0);
                    o = D_8010B4A0_1F1650_ToadInTheBox[pl];
                    func_80029714_2A314(o->model[1], o->trans.x, o->trans.y + t1 * 30.0, o->trans.z);
                    func_8002979C_2A39C(D_8010B4A0_1F1650_ToadInTheBox[pl]->model[1], 90.0f, 0.0f, (f32)(box->time - 10) / 5.0f * 15.0);
                } else if ((u32)(box->time - 15) < 7) {
                    f32 q = (f32)(box->time - 15) / 7.0f;
                    f64 e;

                    q = q * q;
                    o = D_8010B4A0_1F1650_ToadInTheBox[pl];
                    func_80029714_2A314(o->model[1], o->trans.x, o->trans.y + 30.0 - (e = q) * 185.0, o->trans.z);
                    func_8002979C_2A39C(D_8010B4A0_1F1650_ToadInTheBox[pl]->model[1], 90.0f, 0.0f, 15.0 - e * 45.0);
                } else if ((u32)(box->time - 22) < 8) {
                    f32 q = 1.0 - (f32)(box->time - 22) / 7.0f;
                    f64 e;

                    q = 1.0 - q * q;
                    o = D_8010B4A0_1F1650_ToadInTheBox[pl];
                    func_80029714_2A314(o->model[1], o->trans.x, o->trans.y - 155.0 + (e = q) * 155.0, o->trans.z);
                    func_8002979C_2A39C(D_8010B4A0_1F1650_ToadInTheBox[pl]->model[1], 90.0f, 0.0f, e * 30.0 + -30.0);
                    if (box->time == 22) {
                        m = obj->unk_50;
                        func_800191D4_19DD4(obj, 6, obj->trans.x, obj->trans.y + 40.0, obj->trans.z, -90.0f, 0.0f);
                        func_80019B28_1A728(obj, 2);
                        func_800798F8_7A4F8(func_80079798_7A398(0x262, pl), D_8010AB00_1F0CB0_ToadInTheBox[pl]);
                        omVibrate(m->unk_59, 2, 3, 10);
                        TB_A8(m) += 30;
                    }
                } else if (box->time == 30) {
                    box->state = 3;
                    box->time = 0;
                }
                break;
            case 8:
                if (box->time == 0) {
                    box->time = 7;
                }
                if ((u32)(box->time - 8) < 7) {
                    f32 q = box->time - 7;
                    f64 e;

                    q = -(q * q) / 52.0f;
                    o = D_8010B4A0_1F1650_ToadInTheBox[pl];
                    func_80029714_2A314(o->model[1], o->trans.x, o->trans.y + (e = q) * 150.0, o->trans.z - e * 20.0);
                    func_8002979C_2A39C(D_8010B4A0_1F1650_ToadInTheBox[pl]->model[1], (f32)box->time / 15.0f * 30.0 + 164.0, 0.0f, 0.0f);
                    if (box->time == 14) {
                        m = obj->unk_50;
                        func_800191D4_19DD4(obj, 6, obj->trans.x, obj->trans.y + 65.0, obj->trans.z, -90.0f, 0.0f);
                        func_800798F8_7A4F8(func_80079798_7A398(0x262, pl), D_8010AB00_1F0CB0_ToadInTheBox[pl]);
                        omVibrate(m->unk_59, 2, 3, 10);
                        func_8000BF54_CB54(D_8010B4A0_1F1650_ToadInTheBox[pl], 280.0f, 455.0f, -100.0f, -100.0f, 100.0f, 100.0f);
                        box->time++;
                    }
                } else {
                k = box->time;
                if ((u32)(k - 15) < 15) {
                    f32 q = k - 22;

                    q = -(q * q) / 52.0f;
                    o = D_8010B4A0_1F1650_ToadInTheBox[pl];
                    func_80029714_2A314(o->model[1], o->trans.x, o->trans.y + q * (k < 22 ? 150.0 : 205.0), D_8010B4A0_1F1650_ToadInTheBox[pl]->trans.z - q * 20.0);
                    func_8002979C_2A39C(D_8010B4A0_1F1650_ToadInTheBox[pl]->model[1], (f32)(box->time - 15) / 15.0f * 30.0 + 164.0, 0.0f, 0.0f);
                    if (box->time == 29) {
                        m = obj->unk_50;
                        func_8000BF54_CB54(D_8010B4A0_1F1650_ToadInTheBox[pl], 280.0f, 300.0f, -100.0f, -100.0f, 100.0f, 100.0f);
                        func_80019B28_1A728(obj, 1);
                        func_800191D4_19DD4(obj, 6, obj->trans.x, obj->trans.y - 0.0, obj->trans.z, -90.0f, 0.0f);
                        func_800798F8_7A4F8(func_80079798_7A398(0x263, pl), D_8010AB00_1F0CB0_ToadInTheBox[pl]);
                        omVibrate(m->unk_59, 2, 3, 10);
                        TB_A8(m) += 90;
                        box->time++;
                    }
                } else if ((u32)(box->time - 30) < 8) {
                    f = box->time - 37;
                    f = -(f * f) / 52.0f;
                    o = D_8010B4A0_1F1650_ToadInTheBox[pl];
                    func_80029714_2A314(o->model[1], o->trans.x, o->trans.y + f * 205.0, o->trans.z);
                    func_8002979C_2A39C(D_8010B4A0_1F1650_ToadInTheBox[pl]->model[1], (f32)(box->time - 30) / 15.0f * 30.0 + 164.0, 0.0f, 0.0f);
                }
                }
                if (box->time >= 38) {
                    box->state = 3;
                    box->time = 0;
                }
                break;
            case 12:
                break;
            }
            {
                u8 c1 = box->unk_08;

                if (c1 != 0) {
                    c1--;
                }
                box->unk_08 = c1;
            }
        } while (prev != (st = box->state));
    }
    if (box->state == 9 && box->time >= 10) {
        k = *D_8010B4D0_1F1680_ToadInTheBox[pl]->model;
    } else {
        k = D_8010B4A0_1F1650_ToadInTheBox[pl]->model[1];
    }
    box->unk_14 = D_800FC834_FD434[k].pos.y;
    if (pl == 3 && D_8010B474_1F1624_ToadInTheBox == 5) {
        u = 0;
        a = rand8() & 3;
        for (; u < 4; u++) {
            z = (u + a) - ((u8)((u + a) / 4) * 4);
            if (D_8010B470_1F1620_ToadInTheBox[z] != 0) {
                if (D_8010B474_1F1624_ToadInTheBox == 5) {
                    D_8010B474_1F1624_ToadInTheBox = z + 1;
                    D_8010B470_1F1620_ToadInTheBox[z] = 2;
                } else {
                    TBBox** b = &D_8010B428_1F15D8_ToadInTheBox[z];

                    t0 = (f32)(*b)->time / 10.0f * 0.75 + 0.25;
                    (*b)->unk_04 = (*b)->angle = (f32)(rand8() % 3) * 90.0 + 90.0;
                    (*b)->unk_04 += (f32)(rand8() % 20) - 10.0;
                    func_8002979C_2A39C(D_8010B4A0_1F1650_ToadInTheBox[z]->model[1], t0 * (*b)->angle + (*b)->unk_04 * (1.0 - t0), 0.0f, 0.0f);
                }
            }
        }
    }
    box->time++;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_24_ToadInTheBox/1E89B0", func_80105950_1EBB00_ToadInTheBox);
#endif

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
