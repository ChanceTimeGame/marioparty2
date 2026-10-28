#include "common.h"
#include "ovl_5B.h"

#define ABS(x) ((x) < 0 ? -(x) : (x))


void func_80102830_37F4E0_name_5B(void) {
    D_8011269C_38F34C_name_5B = 0;
    func_80020070_20C70(1);
    func_8002D4D0_2E0D0(1);
    func_80020D20_21920(0x19);
    omInitObjMan(0x33, 0xF);
    func_80088640_89240();
    func_80079128_79D28();
    func_8007DD68_7E968();
    _ClearFlag(0x19);
    D_8011485C_39150C_name_5B = 80.0f;
    D_80114858_391508_name_5B = 8000.0f;
    D_80112694_38F344_name_5B = 58.0f;
    Hu3DCamSetPerspective(0, 58.0f, 80.0f, 8000.0f);
    omAddObj(0x2710, 0, 0, -1, func_80109398_386048_name_5B);
    func_80026D28_27928(3);
    func_80026DAC_279AC(2, 0, 0, 0);
    func_80026E00_27A00(2, 0.0f, 0.0f, 100.0f);
    func_80026DAC_279AC(3, 0xF0, 0xF0, 0xF0);
    func_80026E00_27A00(3, 0.0f, 100.0f, 0.0f);
    omAddPrcObj(func_80102C88_37F938_name_5B, 0x3F00, 0x1800, 0);
    omAddPrcObj(func_80108F18_385BC8_name_5B, 0x3F00, 0x800, 0);
    omPrcSetStatBit(omAddPrcObj(func_80109B1C_3867CC_name_5B, 0x1100, 0x800, 0), 0xA0);
    D_80113A1A_3906CA_name_5B = 0xFF;
    InitFadeIn(0xFF, 0x10);
    func_80029708_2A308(1);
    D_80114734_3913E4_name_5B = D_801126A0_38F350_name_5B;
    _ClearFlag(0x13);
    _ClearFlag(0x17);
    _ClearFlag(0);
    _ClearFlag(0xC);
    _ClearFlag(0x1A);
    _ClearFlag(0xE);
    if (_CheckFlag(2)) {
        D_80114860_391510_name_5B = 0;
    } else {
        D_80114860_391510_name_5B = 1;
    }
    D_80114742_3913F2_name_5B = 0;
    D_80114854_391504_name_5B = 0;
    D_801148A2_391552_name_5B = 0;
    D_80114740_3913F0_name_5B = 0;
    D_80114870_391520_name_5B = 0;
    D_800CAFEE = -1;
    if (_CheckFlag(5) && _CheckFlag(6) && _CheckFlag(7) && _CheckFlag(8) && _CheckFlag(9) && !_CheckFlag(1)) {
        D_801148A2_391552_name_5B = 1;
    }
    if (_CheckFlag(1)) {
        D_80114740_3913F0_name_5B = 1;
    }
    if (_CheckFlag(0xA)) {
        D_80114740_3913F0_name_5B = 1;
        D_80114870_391520_name_5B = 1;
    }
    if (_CheckFlag(0xB)) {
        if (!_CheckFlag(0x14)) {
            D_80114854_391504_name_5B = 1;
        }
        D_80114742_3913F2_name_5B = 1;
    }
    for (D_800FD80C_FE40C = 0; D_800FD80C_FE40C < 4; D_800FD80C_FE40C++) {
        if (HuGetPadInserted(D_800FD80C_FE40C)) {
            break;
        }
    }
    if (D_800FD80C_FE40C == 4) {
        D_800FD80C_FE40C = -1;
    }
    D_80114862_391512_name_5B = D_800FD80C_FE40C;
    D_80114850_391500_name_5B = 0;
    D_8011473A_3913EA_name_5B = 0x73;
    D_80114852_391502_name_5B = 0;
    omOvlHisChg(0, 0x5B, 0, 0x1014);
}

void func_80102BD0_37F880_name_5B(void) {
    func_80102830_37F4E0_name_5B();
    D_8011269C_38F34C_name_5B = 1;
    D_80112694_38F344_name_5B = 38.0f;
    Hu3DCamSetPerspective(0, 38.0f, D_8011485C_39150C_name_5B, D_80114858_391508_name_5B);
    func_8002CA48_2D648(0xFF, 0xFF, 0xFF);
}

void func_80102C34_37F8E4_name_5B(void) {
    func_80102830_37F4E0_name_5B();
    D_8011269C_38F34C_name_5B = 2;
    D_80112694_38F344_name_5B = 38.0f;
    Hu3DCamSetPerspective(0, 38.0f, D_8011485C_39150C_name_5B, D_80114858_391508_name_5B);
}

/* The menu's main process: the host walks in (or the camera turns to the menu), then the stick
   moves the cursor (D_801148A4) and A picks a choice: 0-5 and 8 a board (the setup, 80107748),
   6 and 7 the other modes; 9 continues the saved game. */
void func_80102C88_37F938_name_5B(void) {
    char buf[16];
    s16 sel;
    s32 file;
    u16 model;

    func_8010A0F0_386DA0_name_5B(D_801129B0_38F660_name_5B);
    func_8010A940_3875F0_name_5B();
    func_8002A00C_2AC0C(D_80114758_391408_name_5B[0]);
    func_8002A00C_2AC0C(D_80114758_391408_name_5B[7]);
    if (D_80114742_3913F2_name_5B == 0) {
        func_800298A4_2A4A4(D_80114758_391408_name_5B[7], 4, 4);
        func_800298A4_2A4A4(D_80114758_391408_name_5B[8], 4, 4);
    }
    omAddPrcObj(func_801085A8_385258_name_5B, 0x3F00, 0x800, 0);
    model = D_80114758_391408_name_5B[0x2B];
    file = DataRead(0x9005B);
    func_8003D8F0_3E4F0(D_800FC834_FD434[(s16)model].hmf, (void*)file, 0, "c170n_0_DEF");
    DataClose((void*)file);
    func_80029A8C_2A68C(model);
    func_80029AFC_2A6FC(model);
    if (D_80114740_3913F0_name_5B != 0 && D_80114870_391520_name_5B == 0) {
        D_80114872_391522_name_5B = 5;
    } else {
        D_80114872_391522_name_5B = 8;
    }
    D_801148A4_391554_name_5B = D_80114872_391522_name_5B;
    D_80114738_3913E8_name_5B = 1;
    if (D_8011269C_38F34C_name_5B == 0) {
        if (D_801148A2_391552_name_5B == 0) {
            PlayMusic(3);
        } else {
            D_80114872_391522_name_5B = 5;
            PlayMusic(0x5B);
        }
        if (D_80114740_3913F0_name_5B != 0 && D_80114870_391520_name_5B == 0) {
            func_80105410_3820C0_name_5B();
        }
        func_801086E0_385390_name_5B(0);
        while (func_8008F618_90218() != 0) {
            HuPrcVSleep();
        }
        HuPrcSleep(20);
        if (D_801148A2_391552_name_5B == 0) {
            func_80108788_385438_name_5B(1, 50, 1, func_80103A94_380744_name_5B);
        }
        D_8011473E_3913EE_name_5B = 1;
    } else if (D_8011269C_38F34C_name_5B == 1) {
        PlayMusic(3);
        if (D_80114740_3913F0_name_5B != 0 && D_80114870_391520_name_5B == 0) {
            func_80105410_3820C0_name_5B();
        }
        func_80029714_2A314(D_80114758_391408_name_5B[0x2B], -223.0f, 6.0f, 80.0f);
        D_800FC834_FD434[D_80114758_391408_name_5B[0x2B]].rot.y = 20.0f;
        func_80029714_2A314(D_80114758_391408_name_5B[0x32], -223.0f, 6.0f, 80.0f);
        func_8002C9C0_2D5C0(model, D_801147D0_391480_name_5B[0x2D]);
        func_80029E80_2AA80(model, 2, 2);
        func_800298A4_2A4A4(D_80114758_391408_name_5B[5], 4, 0);
        func_800298A4_2A4A4(D_80114758_391408_name_5B[6], 4, 0);
        func_800298A4_2A4A4(D_80114758_391408_name_5B[2], 4, 0);
        func_801086E0_385390_name_5B(0x18);
        func_80108788_385438_name_5B(0x19, 20, 1, (void*)-1);
        func_80108788_385438_name_5B(0x1A, 30, 0, func_80103984_380634_name_5B);
        func_80108788_385438_name_5B(1, 20, 1, (void*)-1);
        func_800298A4_2A4A4(D_80114758_391408_name_5B[6], 4, 4);
        func_800298A4_2A4A4(D_80114758_391408_name_5B[2], 4, 4);
        func_800298A4_2A4A4(D_80114758_391408_name_5B[5], 4, 4);
        D_8011473E_3913EE_name_5B = 0;
    } else if (D_8011269C_38F34C_name_5B == 2) {
        PlayMusic(4);
        func_801086E0_385390_name_5B(0xD);
        func_800298A4_2A4A4(D_80114758_391408_name_5B[5], 4, 0);
        func_800298A4_2A4A4(D_80114758_391408_name_5B[1], 4, 0);
        func_80029714_2A314(D_80114758_391408_name_5B[0x2B], -223.0f, 6.0f, 80.0f);
        D_800FC834_FD434[D_80114758_391408_name_5B[0x2B]].rot.y = 20.0f;
        func_80029714_2A314(D_80114758_391408_name_5B[0x32], -223.0f, 6.0f, 80.0f);
        func_8002C9C0_2D5C0(model, D_801147D0_391480_name_5B[0x2D]);
        func_80029E80_2AA80(model, 2, 2);
        while (func_8008F618_90218() != 0) {
            HuPrcVSleep();
        }
        D_801148A4_391554_name_5B = 6;
        D_80114738_3913E8_name_5B = 3;
        func_8010ACBC_38796C_name_5B();
        PlayMusic(3);
        func_80108788_385438_name_5B(1, 20, 1, (void*)-1);
        func_800298A4_2A4A4(D_80114758_391408_name_5B[1], 4, 4);
        func_800298A4_2A4A4(D_80114758_391408_name_5B[2], 4, 4);
        func_800298A4_2A4A4(D_80114758_391408_name_5B[5], 4, 4);
        func_800298A4_2A4A4(D_80114758_391408_name_5B[6], 4, 4);
        D_80114738_3913E8_name_5B = 1;
        D_801148A4_391554_name_5B = D_80114872_391522_name_5B;
    }
    func_80103EB4_380B64_name_5B();
    if (D_8011269E_38F34E_name_5B != -1) {
        func_801039BC_38066C_name_5B();
    }
    D_80113A12_3906C2_name_5B = 0;
    if ((s16)func_80029E14_2AA14(model) != D_801147D0_391480_name_5B[0x2E]) {
        func_80029BF0_2A7F0(model, D_801147D0_391480_name_5B[0x2E], 0, 5, 0);
    }
    while (D_80112690_38F340_name_5B == 0) {
        HuPrcVSleep();
        if (!(ABS(ContStkX[D_80114862_391512_name_5B]) < 31) || !(ABS(ContStkY[D_80114862_391512_name_5B]) < 31)) {
            sel = func_80103B54_380804_name_5B(-ContStkX[D_80114862_391512_name_5B], ContStkY[D_80114862_391512_name_5B]);
            if (sel != -1) {
                func_8010938C_38603C_name_5B(sel);
                HuPrcSleep(6);
                D_801148A4_391554_name_5B = sel;
                if (D_80113A12_3906C2_name_5B == -1) {
                    D_80113A12_3906C2_name_5B = 0;
                }
            }
        }
        if (!(ContBtnTrg[D_80114862_391512_name_5B] & 0x8000)) {
            continue;
        }
        PlaySound(0xAF);
        while (D_80113A12_3906C2_name_5B != -1 && D_80113A12_3906C2_name_5B != 2) {
            HuPrcVSleep();
        }
        if (D_801148A4_391554_name_5B == 8) {
            func_800890CC_89CCC(D_80113A18_3906C8_name_5B, 0xCE, -1, -1);
            while (func_8008BA30_8C630(D_80113A18_3906C8_name_5B) != 0) {
                HuPrcVSleep();
            }
            if (func_8008BB48_8C748(D_80113A18_3906C8_name_5B, 0, 0) != 0) {
                func_800890CC_89CCC(D_80113A18_3906C8_name_5B, 0xCD, -1, -1);
                while (func_8008BA30_8C630(D_80113A18_3906C8_name_5B) != 0) {
                    HuPrcVSleep();
                }
                continue;
            }
        }
        if (D_801148A4_391554_name_5B == 9) {
            func_80089308_89F08(D_80113A18_3906C8_name_5B, (char*)(GwSystem.current_board_index + 0xBE), 0);
            func_80089308_89F08(D_80113A18_3906C8_name_5B, (char*)(GwSystem.current_game_length + 0xBB), 1);
            sprintf(buf, "%d", GwSystem.current_turn);
            func_80089308_89F08(D_80113A18_3906C8_name_5B, buf, 2);
            if (D_80114740_3913F0_name_5B != 0 && D_80114870_391520_name_5B == 0) {
                func_800890CC_89CCC(D_80113A18_3906C8_name_5B, 0xE1, -1, -1);
            } else {
                func_800890CC_89CCC(D_80113A18_3906C8_name_5B, 0xD0, -1, -1);
            }
            while (func_8008BA30_8C630(D_80113A18_3906C8_name_5B) != 0) {
                HuPrcVSleep();
            }
            if (func_8008BB48_8C748(D_80113A18_3906C8_name_5B, 0, 0) != 0) {
                if (D_80114740_3913F0_name_5B != 0 && D_80114870_391520_name_5B == 0) {
                    func_800890CC_89CCC(D_80113A18_3906C8_name_5B, 0xE0, -1, -1);
                } else {
                    func_800890CC_89CCC(D_80113A18_3906C8_name_5B, 0xCF, -1, -1);
                }
                while (func_8008BA30_8C630(D_80113A18_3906C8_name_5B) != 0) {
                    HuPrcVSleep();
                }
                continue;
            }
            D_8011269E_38F34E_name_5B = GwSystem.current_board_index;
            D_801148A4_391554_name_5B = func_80106868_383518_name_5B(D_8011269E_38F34E_name_5B);
            func_801039BC_38066C_name_5B();
        }
        D_80114750_391400_name_5B = 1;
        func_80029BF0_2A7F0(model, D_801147D0_391480_name_5B[0x30], 0, 5, 2);
        while (D_80114750_391400_name_5B != -1) {
            HuPrcVSleep();
        }
        switch (D_801148A4_391554_name_5B) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 8:
            GwSystem.current_board_index = D_801148A4_391554_name_5B;
            if (D_801148A4_391554_name_5B == 8) {
                GwSystem.current_board_index = 8;
            }
            func_80108788_385438_name_5B(4, 20, 1, (void*)-1);
            func_800298A4_2A4A4(D_80114758_391408_name_5B[3], 4, 0);
            _SetFlag(0x17);
            func_80107748_3843F8_name_5B();
            while (1) {
                HuPrcVSleep();
            }
        case 6:
            func_800298A4_2A4A4(D_80114758_391408_name_5B[5], 4, 0);
            func_800298A4_2A4A4(D_80114758_391408_name_5B[1], 4, 0);
            func_80108788_385438_name_5B(3, 20, 1, (void*)-1);
            func_800794A8_7A0A8(20);
            func_80108788_385438_name_5B(5, 20, 0, (void*)-1);
            PlayMusic(4);
            func_80108788_385438_name_5B(7, 20, 1, (void*)-1);
            func_8002C9C0_2D5C0(model, D_801147D0_391480_name_5B[0x2C]);
            D_80114738_3913E8_name_5B = 6;
            func_8010ACBC_38796C_name_5B();
            PlayMusic(3);
            break;
        case 7:
            func_800298A4_2A4A4(D_80114758_391408_name_5B[6], 4, 0);
            func_800298A4_2A4A4(D_80114758_391408_name_5B[2], 4, 0);
            func_8002CA48_2D648(0xFF, 0xFF, 0xFF);
            func_80108788_385438_name_5B(2, 20, 0, (void*)-1);
            func_80108788_385438_name_5B(0x15, 20, 0, (void*)-1);
            func_80108788_385438_name_5B(0x16, 40, 0, func_80103984_380634_name_5B);
            func_800794A8_7A0A8(60);
            func_80108788_385438_name_5B(0x17, 20, 1, (void*)-1);
            HuPrcSleep(10);
            D_80112690_38F340_name_5B = 1;
            D_8011269A_38F34A_name_5B = 1;
            D_80114850_391500_name_5B = 2;
            D_8011473A_3913EA_name_5B = 0x5C;
            func_8008F624_90224(0xFF, 0xFF, 0xFF);
            while (1) {
                HuPrcVSleep();
            }
        }
        func_8002C9C0_2D5C0(model, D_801147D0_391480_name_5B[0x2D]);
        func_80029E80_2AA80(model, 2, 2);
        func_80108788_385438_name_5B(1, 20, 1, (void*)-1);
        func_800298A4_2A4A4(D_80114758_391408_name_5B[1], 4, 4);
        func_800298A4_2A4A4(D_80114758_391408_name_5B[2], 4, 4);
        func_800298A4_2A4A4(D_80114758_391408_name_5B[5], 4, 4);
        func_800298A4_2A4A4(D_80114758_391408_name_5B[6], 4, 4);
        D_80114738_3913E8_name_5B = 1;
        if (_CheckFlag(0x40)) {
            D_801148A4_391554_name_5B = 9;
        } else {
            D_801148A4_391554_name_5B = D_80114872_391522_name_5B;
        }
        D_80114750_391400_name_5B = 0;
        do {
            HuPrcVSleep();
        } while (D_80114750_391400_name_5B == 0);
        if (D_8011269E_38F34E_name_5B != -1) {
            func_801039BC_38066C_name_5B();
        }
        D_80113A12_3906C2_name_5B = 0;
        if ((s16)func_80029E14_2AA14(model) != D_801147D0_391480_name_5B[0x2E]) {
            func_80029BF0_2A7F0(model, D_801147D0_391480_name_5B[0x2E], 0, 5, 0);
        }
    }
    D_80112690_38F340_name_5B = 1;
    while (1) {
        HuPrcVSleep();
    }
}


/* Camera move callback: the controller rumbles every eighth frame. */
void func_80103984_380634_name_5B(s16* arg0) {
    if ((arg0[0] & 7) == 0) {
        func_80088604_89204(D_80114862_391512_name_5B, 5, 0, 5);
    }
}

/* Go straight to the board D_8011269E (its setup). Does not return. */
void func_801039BC_38066C_name_5B(void) {
    u16 model = D_80114758_391408_name_5B[0x2B];

    D_80114750_391400_name_5B = 1;
    _SetFlag(0x17);
    func_80029BF0_2A7F0(model, D_801147D0_391480_name_5B[0x30], 0, 5, 2);
    while (D_80114750_391400_name_5B != -1) {
        HuPrcVSleep();
    }
    func_80108788_385438_name_5B(4, 20, 1, (void*)-1);
    func_800298A4_2A4A4(D_80114758_391408_name_5B[3], 4, 0);
    D_801148A4_391554_name_5B = func_80106868_383518_name_5B(D_8011269E_38F34E_name_5B);
    func_80107748_3843F8_name_5B();
    while (1) {
        HuPrcVSleep();
    }
}

/* Camera move callback: zoom the field of view out and back (58 -> 38 -> 58). */
void func_80103A94_380744_name_5B(s16* arg0) {
    D_80112694_38F344_name_5B = HuMathSin(arg0[0] * 90.0f / arg0[1]) * -20.0f + 58.0f;
    Hu3DCamSetPerspective(0, D_80112694_38F344_name_5B, D_8011485C_39150C_name_5B, D_80114858_391508_name_5B);
    if (arg0[0] == 20) {
        func_8002C9C0_2D5C0(D_80114758_391408_name_5B[0x2B], D_801147D0_391480_name_5B[0x2C]);
    }
}

/* The choice the stick (x, y) points at from the cursor's choice, or -1. */
s16 func_80103B54_380804_name_5B(s16 x, s16 y) {
    f32 dir[10][2];
    f32 dist[10];
    f32 dx;
    f32 dy;
    f32 sx;
    f32 sy;
    f32 len;
    f32 best;
    s16 i;
    s16 sel;

    for (i = 0; i < 10; i++) {
        if (i == D_801148A4_391554_name_5B) {
            dist[i] = -1.0f;
        } else {
            dx = D_80114878_391528_name_5B[D_801148A4_391554_name_5B][0] - D_80114878_391528_name_5B[i][0];
            dy = D_80114878_391528_name_5B[D_801148A4_391554_name_5B][1] - D_80114878_391528_name_5B[i][1];
            len = dist[i] = func_800B1830_B2430(dx * dx + dy * dy);
            dir[i][0] = dx / len;
            dir[i][1] = dy / len;
        }
    }
    if (!_CheckFlag(0x40)) {
        dist[9] = -1.0f;
    }
    if (D_80114740_3913F0_name_5B == 0) {
        dist[5] = -1.0f;
    } else if (D_80114870_391520_name_5B == 0) {
        dist[0] = dist[1] = dist[2] = dist[3] = dist[8] = dist[4] = -1.0f;
    }
    len = func_800B1830_B2430(x * x + y * y);
    sx = x / len;
    sy = y / len;
    for (i = 0; i < 10; i++) {
        if (!(dist[i] < 0.0f)) {
            dx = sx - dir[i][0];
            dy = sy - dir[i][1];
            if (func_800B1830_B2430(dx * dx + dy * dy) > 0.5f) {
                dist[i] = -1.0f;
            }
        }
    }
    best = 100000.0f;
    sel = -1;
    for (i = 0; i < 10; i++) {
        if (!(dist[i] < 0.0f) && dist[i] < best) {
            best = dist[i];
            sel = i;
        }
    }
    return sel;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_80103EB4_380B64_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_80104300_380FB0_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_80105410_3820C0_name_5B);


__asm__(".section .rodata");
const char D_801138D4_390584_name_5B[] = "panelhook";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_80105530_3821E0_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_8010607C_382D2C_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_80106868_383518_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_801068C4_383574_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_80106D2C_3839DC_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_80107748_3843F8_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_801085A8_385258_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_801086E0_385390_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_80108788_385438_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_80108F18_385BC8_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_801091EC_385E9C_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_8010933C_385FEC_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_80109374_386024_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_80109380_386030_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_8010938C_38603C_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_80109398_386048_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_80109408_3860B8_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_801094F8_3861A8_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_80109B1C_3867CC_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_8010A0F0_386DA0_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_8010A1E4_386E94_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_8010A53C_3871EC_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_8010A7F4_3874A4_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_8010A8F4_3875A4_name_5B);
