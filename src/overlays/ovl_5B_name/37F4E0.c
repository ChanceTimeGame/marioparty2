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

/* Starts the menu's processes and brings the host in (he jumps in from the left, unless the
   menu was entered from 58 or the ending); returns once the menu is ready (D_80114750). */
void func_80103EB4_380B64_name_5B(void) {
    Vec start;
    Vec pos;
    s16 i;
    u16 model = D_80114758_391408_name_5B[0x2B];
    u16 shadow = D_80114758_391408_name_5B[0x32];

    omAddPrcObj(func_80105530_3821E0_name_5B, 0x3F00, 0x800, 0);
    omAddPrcObj(func_801068C4_383574_name_5B, 0x3F00, 0x800, 0);
    omAddPrcObj(func_80106D2C_3839DC_name_5B, 0x3F00, 0x800, 0);
    omAddPrcObj(func_8010607C_382D2C_name_5B, 0x3F00, 0x800, 0);
    if (D_8011269C_38F34C_name_5B == 0) {
        if (D_801148A2_391552_name_5B != 0) {
            i = 0;
            func_80104300_380FB0_name_5B();
            _SetFlag(1);
            D_80114740_3913F0_name_5B = 1;
            D_80114750_391400_name_5B = 0;
            do {
                if (i == 10) {
                    PlaySound(0xBF);
                }
                i++;
                HuPrcVSleep();
            } while (D_80114750_391400_name_5B == 0);
            return;
        }
        if (D_80114740_3913F0_name_5B != 0 && D_80114870_391520_name_5B == 0) {
            func_80029E80_2AA80(model, 2, 2);
            HuPrcVSleep();
            D_80114750_391400_name_5B = 0;
            do {
                HuPrcVSleep();
            } while (D_80114750_391400_name_5B == 0);
            return;
        }
        while (func_80029CE4_2A8E4(model) < 60.0f) {
            HuPrcVSleep();
        }
        func_80029E80_2AA80(model, 1, 1);
        PlaySound(0x122);
        start.x = D_800FC834_FD434[(s16)model].pos.x;
        start.y = D_800FC834_FD434[(s16)model].pos.y;
        start.z = D_800FC834_FD434[(s16)model].pos.z;
        for (i = 0; i < 16; i++) {
            pos.x = (-223.0f - start.x) / 15.0f * i + start.x;
            pos.y = (6.0f - start.y) / 15.0f * i + start.y;
            pos.y += HuMathSin(i * 12.0f) * 200.0f;
            pos.z = (80.0f - start.z) / 15.0f * i + start.z;
            D_800FC834_FD434[(s16)model].rot.y = i * 1.3333334f;
            func_80029714_2A314(model, pos.x, pos.y, pos.z);
            if (pos.y < start.y) {
                func_80029714_2A314(shadow, pos.x, 6.0f, pos.z);
            } else {
                func_80029714_2A314(shadow, pos.x, 15.0f, pos.z);
            }
            HuPrcVSleep();
        }
        func_80029E80_2AA80(model, 1, 0);
        D_80114750_391400_name_5B = 0;
        while (func_80029CE4_2A8E4(model) < func_80029D0C_2A90C(model)) {
            HuPrcVSleep();
        }
    } else {
        HuPrcVSleep();
        D_80114750_391400_name_5B = 0;
    }
    func_8002C9C0_2D5C0(model, D_801147D0_391480_name_5B[0x2D]);
    func_80029E80_2AA80(model, 2, 2);
    while (D_80114750_391400_name_5B == 0) {
        HuPrcVSleep();
    }
}

/* The scene when every board is cleared (D_801148A2): Bowser and three Koopa Kids march in,
   chase the host off screen, and a Koopa Kid (kid[0]) takes his place as the menu's host. */
#ifdef NON_MATCHING
/* masked 152: register allocation (retail spills bowser, bowserShadow and hostShadow to the stack,
   frame 0xF8) and the scheduling that follows from it; the logic is complete. */
void func_80104300_380FB0_name_5B(void) {
    s16 kid[3];
    s16 kidShadow[3];
    s16 kidMdl[3];
    s16 bowserMdl[2];
    s16 kidMot[4];
    s16 bowserMot[3];
    Vec kidPos[3];
    Vec hostPos;
    Vec bowserPos;
    f32 x;
    f32 y;
    f32 d;
    s16 i;
    s16 j;
    s16 shadowSrc;
    u16 bowser;
    u16 bowserShadow;
    u16 host = D_80114758_391408_name_5B[0x2B];
    u16 hostShadow = D_80114758_391408_name_5B[0x32];

    for (i = 0; i < 11; i++) {
        D_80112694_38F344_name_5B = i / 10.0f * -20.0f + 58.0f;
        Hu3DCamSetPerspective(0, D_80112694_38F344_name_5B, D_8011485C_39150C_name_5B, D_80114858_391508_name_5B);
        HuPrcVSleep();
    }
    PlaySound(0xBF);
    shadowSrc = LoadFormFile(0xD, 0x22B9);
    bowser = LoadFormFile(0x8003C, 0x26B9);
    bowserShadow = func_80027D3C_2893C(shadowSrc);
    bowserMot[0] = func_80029E14_2AA14(bowser);
    bowserMdl[0] = LoadFormFile(0x80043, 0x288);
    bowserMot[1] = func_80029E14_2AA14(bowserMdl[0]);
    bowserMdl[1] = LoadFormFile(0x8003F, 0x288);
    bowserMot[2] = func_80029E14_2AA14(bowserMdl[1]);
    func_80029714_2A314(bowser, 1500.0f, 22.0f, 50.0f);
    func_8002979C_2A39C(bowser, 0.0f, -90.0f, 0.0f);
    func_8002C9C0_2D5C0(bowser, bowserMot[1]);
    func_80029E80_2AA80(bowser, 2, 2);
    func_80029714_2A314(bowserShadow, 1500.0f, 22.0f, 50.0f);
    func_800297E8_2A3E8(bowserShadow, 3.0f, 3.0f, 3.0f);
    kidMdl[0] = LoadFormFile(0x800B3, 0x288);
    kidMot[1] = func_80029E14_2AA14(kidMdl[0]);
    kidMdl[1] = LoadFormFile(0x800B8, 0x288);
    kidMot[2] = func_80029E14_2AA14(kidMdl[1]);
    kidMdl[2] = LoadFormFile(0x800B9, 0x288);
    kidMot[3] = func_80029E14_2AA14(kidMdl[2]);
    for (i = 0; i < 3; i++) {
        if (i == 0) {
            kid[0] = LoadFormFile(0x800B0, 0x22B9);
            kidMot[0] = func_80029E14_2AA14(kid[0]);
        } else {
            kid[i] = func_80027D3C_2893C(kid[0]);
        }
        x = i * 150 + 900;
        func_80029714_2A314(kid[i], x, 22.0f, 80.0f);
        func_8002979C_2A39C(kid[i], 0.0f, -90.0f, 0.0f);
        func_8002C9C0_2D5C0(kid[i], kidMot[1]);
        func_80029E80_2AA80(kid[i], 2, 2);
        kidShadow[i] = func_80027D3C_2893C(shadowSrc);
        func_80029714_2A314(kidShadow[i], x, 22.0f, 80.0f);
    }
    func_8002C9C0_2D5C0(host, D_801147D0_391480_name_5B[0x2C]);
    for (i = 0; i < 10; i++) {
        D_800FC834_FD434[(s16)host].rot.y = i * 9.0f;
        HuPrcVSleep();
    }
    for (i = 0; i < 35; i++) {
        x = 900.0f - HuMathSin(i * 2.5714285f) * 1050.0f;
        for (j = 0; j < 3; j++) {
            D_800FC834_FD434[kidShadow[j]].pos.x = D_800FC834_FD434[kid[j]].pos.x = x + j * 150;
        }
        D_800FC834_FD434[(s16)bowserShadow].pos.x = D_800FC834_FD434[(s16)bowser].pos.x = x + 600.0f;
        HuPrcVSleep();
    }
    func_80029BF0_2A7F0(bowser, bowserMot[0], 0, 5, 2);
    for (i = 0; i < 11; i++) {
        for (j = 0; j < 3; j++) {
            D_800FC834_FD434[kid[j]].rot.y = -90.0f - i * 9.0f;
            if (i == 5) {
                func_80029BF0_2A7F0(kid[j], kidMot[0], 0, 5, 2);
            }
        }
        HuPrcVSleep();
    }
    func_80029BF0_2A7F0(kid[0], kidMot[1], 0, 3, 2);
    func_80029760_2A360(kid[0], &kidPos[0]);
    func_80029BF0_2A7F0(kid[2], kidMot[1], 0, 3, 2);
    func_80029760_2A360(kid[2], &kidPos[2]);
    for (i = 0; i < 10; i++) {
        x = kidPos[0].z - kidPos[0].z / 10.0f * i;
        D_800FC834_FD434[kid[0]].pos.z = x;
        D_800FC834_FD434[kid[2]].pos.z = x;
        D_800FC834_FD434[kidShadow[0]].pos.z = x;
        D_800FC834_FD434[kidShadow[2]].pos.z = x;
        d = i * 7.0f;
        x = d + kidPos[0].x;
        D_800FC834_FD434[kid[0]].pos.x = x;
        D_800FC834_FD434[kidShadow[0]].pos.x = x;
        x = kidPos[2].x - d;
        D_800FC834_FD434[kid[2]].pos.x = x;
        D_800FC834_FD434[kidShadow[2]].pos.x = x;
        d = i * 9.0f;
        D_800FC834_FD434[kid[0]].rot.y = -180.0f - d;
        D_800FC834_FD434[kid[2]].rot.y = d + -180.0f;
        if (i == 5) {
            func_80029BF0_2A7F0(kid[0], kidMot[0], 0, 5, 2);
            func_80029BF0_2A7F0(kid[2], kidMot[0], 0, 5, 2);
        }
        HuPrcVSleep();
    }
    for (i = 0; i < 3; i++) {
        func_8002C9C0_2D5C0(kid[i], kidMot[2]);
        func_80029FE4_2ABE4(kid[i], 1.5f);
    }
    func_80029760_2A360(host, &hostPos);
    func_8002C9C0_2D5C0(host, D_801147D0_391480_name_5B[0x34]);
    func_80029E80_2AA80(host, 2, 2);
    func_80029FE4_2ABE4(host, 4.0f);
    func_8002C9C0_2D5C0(bowser, bowserMot[2]);
    PlaySound(0x124);
    for (i = 0; i < 20; i++) {
        y = HuMathSin(i * 9.0f) * 350.0f;
        if (i >= 16 && y + hostPos.y < 170.0f) {
            y = 170.0f - hostPos.x; /* retail: x, not y */
        }
        if (i == 5) {
            PlaySound(0x126);
        }
        D_800FC834_FD434[(s16)host].pos.y = y + hostPos.y;
        d = i * 2.5f;
        D_800FC834_FD434[(s16)host].pos.x = hostPos.x - d;
        D_800FC834_FD434[(s16)hostShadow].pos.x = hostPos.x - d;
        D_800FC834_FD434[(s16)host].rot.x = i * -4.5f;
        D_800FC834_FD434[(s16)host].rot.y = i * -22.5f;
        HuPrcVSleep();
    }
    for (i = 0; i < 11; i++) {
        D_800FC834_FD434[kid[0]].rot.y = i * 18.0f + -270.0f;
        D_800FC834_FD434[kid[1]].rot.y = i * 9.0f + -180.0f;
        HuPrcVSleep();
    }
    for (i = 0; i < 3; i++) {
        func_80029BF0_2A7F0(kid[i], kidMot[3], 0, 5, 2);
        func_80029760_2A360(kid[i], &kidPos[i]);
    }
    func_80029BF0_2A7F0(bowser, bowserMot[1], 0, 5, 2);
    func_80029760_2A360(host, &hostPos);
    func_80029760_2A360(bowser, &bowserPos);
    for (i = 0; i < 60; i++) {
        x = (HuMathSin(i * 1.5f + 270.0f) + 1.0f) * 1500.0f;
        for (j = 0; j < 3; j++) {
            D_800FC834_FD434[kid[j]].pos.x = kidPos[j].x - x;
            D_800FC834_FD434[kidShadow[j]].pos.x = kidPos[j].x - x;
        }
        D_800FC834_FD434[(s16)host].pos.x = hostPos.x - x;
        D_800FC834_FD434[(s16)host].pos.y = HuMathSin(i * 40) * (x / 50.0f) + hostPos.y;
        D_800FC834_FD434[(s16)hostShadow].pos.x = hostPos.x - x;
        D_800FC834_FD434[(s16)bowser].pos.x = bowserPos.x - x;
        D_800FC834_FD434[(s16)bowserShadow].pos.x = bowserPos.x - x;
        func_80029FE4_2ABE4(bowser, i * 0.03f + 1.0f);
        HuPrcVSleep();
    }
    func_800283DC_28FDC(bowser);
    func_800283DC_28FDC(bowserShadow);
    func_800283DC_28FDC(bowserMdl[0]);
    func_800283DC_28FDC(bowserMdl[1]);
    for (i = 1; i < 3; i++) {
        func_800283DC_28FDC(kid[i]);
        func_800283DC_28FDC(kidShadow[i]);
    }
    func_800283DC_28FDC(host);
    func_800283DC_28FDC(hostShadow);
    D_80114758_391408_name_5B[0x2B] = kid[0];
    D_80114758_391408_name_5B[0x32] = hostShadow = kidShadow[0];
    D_801147D0_391480_name_5B[0x2C] = kidMot[0];
    D_801147D0_391480_name_5B[0x2D] = kidMot[0];
    D_801147D0_391480_name_5B[0x2E] = kidMot[0];
    D_801147D0_391480_name_5B[0x30] = kidMot[0];
    D_801147D0_391480_name_5B[0x34] = kidMot[1];
    func_8002C9C0_2D5C0(kid[0], kidMot[1]);
    func_80029E80_2AA80(kid[0], 2, 2);
    func_80029760_2A360(kid[0], &hostPos);
    D_800FC834_FD434[kid[0]].rot.y = 90.0f;
    for (i = 0; i < 31; i++) {
        func_80029714_2A314(kid[0], (-223.0f - hostPos.x) / 30.0f * i + hostPos.x, (6.0f - hostPos.y) / 30.0f * i + hostPos.y,
                            (80.0f - hostPos.z) / 30.0f * i + hostPos.z);
        func_80029714_2A314(hostShadow, (-223.0f - hostPos.x) / 30.0f * i + hostPos.x, (6.0f - hostPos.y) / 30.0f * i + hostPos.y,
                            (80.0f - hostPos.z) / 30.0f * i + hostPos.z);
        HuPrcVSleep();
    }
    for (i = 0; i < 11; i++) {
        D_800FC834_FD434[kid[0]].rot.y = i * -7.0f + 90.0f;
        if (i == 5) {
            func_80029BF0_2A7F0(kid[0], kidMot[0], 0, 5, 2);
        }
        HuPrcVSleep();
    }
    func_80108788_385438_name_5B(1, 10, 1, (void*)-1);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_80104300_380FB0_name_5B);
#endif

/* A Koopa Kid is the menu's host (D_80114740 set, D_80114870 clear): he replaces the host
   model and its motions. */
void func_80105410_3820C0_name_5B(void) {
    s16 mdl[2];
    s16 mot[2];
    s16 kid;
    u16 host = D_80114758_391408_name_5B[0x2B];
    u16 shadow = D_80114758_391408_name_5B[0x32];

    kid = LoadFormFile(0x800B0, 0x22B9);
    mot[0] = func_80029E14_2AA14(kid);
    mdl[0] = LoadFormFile(0x800B3, 0x288);
    mot[1] = func_80029E14_2AA14(mdl[0]);
    func_80029714_2A314(kid, -223.0f, 6.0f, 80.0f);
    D_800FC834_FD434[kid].rot.y = 20.0f;
    func_80029714_2A314(shadow, -223.0f, 6.0f, 80.0f);
    D_80114758_391408_name_5B[0x2B] = kid;
    D_801147D0_391480_name_5B[0x2C] = mot[0];
    D_801147D0_391480_name_5B[0x2D] = mot[0];
    D_801147D0_391480_name_5B[0x2E] = mot[0];
    D_801147D0_391480_name_5B[0x30] = mot[0];
    D_801147D0_391480_name_5B[0x34] = mot[1];
    func_800283DC_28FDC(host);
}


__asm__(".section .rodata");
const char D_801138D4_390584_name_5B[] = "panelhook";

/* The choice panel (model [0x33]) and its three sprites ("panelhook"): D_80114750 0 brings it
   in and sets the choices' screen positions (D_80114878), 1 takes it away. Never returns. */
void func_80105530_3821E0_name_5B(void) {
    f32 mtx[4][4];
    Vec2f scr;
    Vec start;
    Vec pos;
    s16 i;
    s16 grp0 = 0;
    u16 spr0 = 0;
    s16 grp1 = 0;
    u16 spr1 = 0;
    u16 panel = D_80114758_391408_name_5B[0x33];

    D_80114750_391400_name_5B = -1;
    while (1) {
        HuPrcVSleep();
        switch (D_80114750_391400_name_5B) {
        case 0:
            PlaySound(0xAE);
            D_801148A4_391554_name_5B = D_80114872_391522_name_5B;
            func_80109374_386024_name_5B(D_80114878_391528_name_5B);
            func_80109380_386030_name_5B(5);
            if (D_8011473E_3913EE_name_5B != 0) {
                D_80113A10_3906C0_name_5B = 0;
            }
            func_800298A4_2A4A4(panel, 4, 0);
            grp0 = func_8001A2F8_1AEF8(0x9000F);
            spr0 = func_8001AAAC_1B6AC(grp0, 0, 1);
            func_8001A6BC_1B2BC(spr0, 0x100);
            func_8001A788_1B388(spr0, 20000);
            grp1 = func_8001A2F8_1AEF8(0x9001D);
            spr1 = func_8001AAAC_1B6AC(grp1, 0, 1);
            func_8001A6BC_1B2BC(spr1, 0x100);
            func_8001A788_1B388(spr1, 20000);
            if (D_80114740_3913F0_name_5B == 0) {
                espDispOff(spr1);
            }
            func_8001A788_1B388(spr0, 20000);
            D_801132B0_38FF60_name_5B = func_8001A2F8_1AEF8(0x90027);
            D_801132B2_38FF62_name_5B = func_8001AAAC_1B6AC(D_801132B0_38FF60_name_5B, 0, 1);
            func_8001A6BC_1B2BC(D_801132B2_38FF62_name_5B, 0x100);
            func_8001A788_1B388(D_801132B2_38FF62_name_5B, 20000);
            if (!_CheckFlag(0x40)) {
                espDispOff(D_801132B2_38FF62_name_5B);
            }
            start.x = 120.0f;
            start.y = 760.0f;
            start.z = 0.0f;
            func_8002C9C0_2D5C0(panel, D_801147D0_391480_name_5B[0x33]);
            func_80029E80_2AA80(panel, 1, 1);
            for (i = 0; i < 6; i++) {
                pos.x = (120.0f - start.x) / 5.0f * i + start.x;
                pos.y = (80.0f - start.y) / 5.0f * i + start.y;
                pos.z = (0.0f - start.z) / 5.0f * i + start.z;
                func_80029714_2A314(panel, pos.x, pos.y, pos.z);
                if (i == 5) {
                    func_8002C9C0_2D5C0(panel, D_801147D0_391480_name_5B[0x33]);
                }
                func_80023554_24154(panel, func_80029CE4_2A8E4(panel), D_801138D4_390584_name_5B, mtx);
                func_8010A8F4_3875A4_name_5B(panel, &scr, mtx);
                espPosSet(spr0, scr.unk_00, scr.unk_04 + 60.0f);
                espPosSet(spr1, D_80113248_38FEF8_name_5B[5][0] + scr.unk_00 - 100.0f,
                          scr.unk_04 + 60.0f + D_80113248_38FEF8_name_5B[5][1] - 80.0f);
                espPosSet(D_801132B2_38FF62_name_5B, D_80113248_38FEF8_name_5B[9][0] + scr.unk_00 - 100.0f,
                          scr.unk_04 + 60.0f + D_80113248_38FEF8_name_5B[9][1] - 80.0f);
                HuPrcVSleep();
            }
            while (func_80029CE4_2A8E4(panel) < func_80029D0C_2A90C(panel)) {
                if (func_80029CE4_2A8E4(panel) == 6.0f) {
                    func_80088604_89204(D_80114862_391512_name_5B, 5, 0, 5);
                }
                if (func_80029CE4_2A8E4(panel) == 26.0f) {
                    func_80088604_89204(D_80114862_391512_name_5B, 5, 0, 10);
                }
                func_80023554_24154(panel, func_80029CE4_2A8E4(panel), D_801138D4_390584_name_5B, mtx);
                func_8010A8F4_3875A4_name_5B(panel, &scr, mtx);
                espPosSet(spr0, scr.unk_00, scr.unk_04 + 60.0f);
                espPosSet(spr1, D_80113248_38FEF8_name_5B[5][0] + scr.unk_00 - 100.0f,
                          scr.unk_04 + 60.0f + D_80113248_38FEF8_name_5B[5][1] - 80.0f);
                espPosSet(D_801132B2_38FF62_name_5B, D_80113248_38FEF8_name_5B[9][0] + scr.unk_00 - 100.0f,
                          scr.unk_04 + 60.0f + D_80113248_38FEF8_name_5B[9][1] - 80.0f);
                HuPrcVSleep();
            }
            for (i = 0; i < 10; i++) {
                D_80114878_391528_name_5B[i][0] = D_80113248_38FEF8_name_5B[i][0] + scr.unk_00 - 100.0f;
                D_80114878_391528_name_5B[i][1] = D_80113248_38FEF8_name_5B[i][1] + scr.unk_04 + 60.0f - 80.0f;
            }
            D_801132AE_38FF5E_name_5B = 0;
            if (_CheckFlag(0x40)) {
                HuPrcVSleep();
                D_801148A4_391554_name_5B = 9;
                D_801132AE_38FF5E_name_5B = 2;
                func_8010933C_385FEC_name_5B(9);
            } else {
                func_8010933C_385FEC_name_5B(D_80114872_391522_name_5B);
            }
            if (D_8011473E_3913EE_name_5B == 0 && D_80113A10_3906C0_name_5B != 2) {
                D_80113A10_3906C0_name_5B = 0;
            }
            while (D_80113A10_3906C0_name_5B != 2) {
                HuPrcVSleep();
            }
            if (D_8011269E_38F34E_name_5B != -1) {
                while (D_80113A12_3906C2_name_5B == 0) {
                    HuPrcVSleep();
                }
                D_80114750_391400_name_5B = 1;
            } else {
                D_8011473C_3913EC_name_5B = 1;
                HuPrcSleep(5);
                D_80114750_391400_name_5B = -1;
                D_801132AE_38FF5E_name_5B = 2;
            }
            break;
        case 1:
            D_80113A10_3906C0_name_5B = 1;
            D_80113A12_3906C2_name_5B = 1;
            D_801132AE_38FF5E_name_5B = 1;
            D_8011473C_3913EC_name_5B = 0;
            start.x = D_800FC834_FD434[(s16)panel].pos.x;
            start.y = D_800FC834_FD434[(s16)panel].pos.y;
            start.z = D_800FC834_FD434[(s16)panel].pos.z;
            for (i = 0; i < 6; i++) {
                pos.x = (120.0f - start.x) / 5.0f * i + start.x;
                pos.y = (800.0f - start.y) / 5.0f * i + start.y;
                pos.z = (0.0f - start.z) / 5.0f * i + start.z;
                func_80029714_2A314(panel, pos.x, pos.y, pos.z);
                func_80023554_24154(panel, func_80029CE4_2A8E4(panel), D_801138D4_390584_name_5B, mtx);
                func_8010A8F4_3875A4_name_5B(panel, &scr, mtx);
                espPosSet(spr0, scr.unk_00, scr.unk_04 + 60.0f);
                espPosSet(spr1, D_80113248_38FEF8_name_5B[5][0] + scr.unk_00 - 100.0f,
                          scr.unk_04 + 60.0f + D_80113248_38FEF8_name_5B[5][1] - 80.0f);
                espPosSet(D_801132B2_38FF62_name_5B, D_80113248_38FEF8_name_5B[9][0] + scr.unk_00 - 100.0f,
                          scr.unk_04 + 60.0f + D_80113248_38FEF8_name_5B[9][1] - 80.0f);
                if (i == 5) {
                    func_8002C9C0_2D5C0(panel, D_801147D0_391480_name_5B[0x33]);
                }
                HuPrcVSleep();
            }
            func_800298A4_2A4A4(panel, 4, 4);
            func_8001AC44_1B844(D_801132B2_38FF62_name_5B);
            SprAnimKill(D_801132B0_38FF60_name_5B);
            func_8001AC44_1B844(spr1);
            SprAnimKill(grp1);
            func_8001AC44_1B844(spr0);
            SprAnimKill(grp0);
            D_80114750_391400_name_5B = -1;
            break;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_8010607C_382D2C_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_80106868_383518_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_801068C4_383574_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_80106D2C_3839DC_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_80107748_3843F8_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_801085A8_385258_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_801086E0_385390_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_80108788_385438_name_5B);

/* The menu's pointer sprite (D_801148A0): while D_8011473C is set it slides to the position
   D_80113A14[D_80113A22] over D_80113A20 frames whenever D_80113A22 changes. Never returns. */
void func_80108F18_385BC8_name_5B(void) {
    s16 prev;
    s16 i;
    s16 x0;
    s16 dx;
    s16 y0;
    s16 dy;
    f32 s;

    prev = -1;
    D_8011473C_3913EC_name_5B = 0;
    D_801148A0_391550_name_5B = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x900F8), 0, 1);
    func_8001A788_1B388(D_801148A0_391550_name_5B, 1);
    espPosSet(D_801148A0_391550_name_5B, 160, 120);
    espDispOff(D_801148A0_391550_name_5B);
    D_80113A1C_3906CC_name_5B = 160;
    D_80113A1E_3906CE_name_5B = 120;
    D_80113A20_3906D0_name_5B = 10;
    omAddPrcObj(func_801091EC_385E9C_name_5B, 0x3F00, 0x100, 0);
    while (1) {
        HuPrcVSleep();
        if (D_8011473C_3913EC_name_5B != 0) {
            if (prev != D_80113A22_3906D2_name_5B && D_80113A22_3906D2_name_5B != -1) {
                if (D_80113A14_3906C4_name_5B[D_80113A22_3906D2_name_5B][0] != D_80113A1C_3906CC_name_5B
                    || D_80113A14_3906C4_name_5B[D_80113A22_3906D2_name_5B][1] != D_80113A1E_3906CE_name_5B) {
                    x0 = D_80113A1C_3906CC_name_5B;
                    y0 = D_80113A1E_3906CE_name_5B;
                    dx = D_80113A14_3906C4_name_5B[D_80113A22_3906D2_name_5B][0] - x0;
                    dy = D_80113A14_3906C4_name_5B[D_80113A22_3906D2_name_5B][1] - y0;
                    for (i = 1; i <= D_80113A20_3906D0_name_5B; i++) {
                        s = HuMathSin(90.0f / D_80113A20_3906D0_name_5B * i);
                        D_80113A1C_3906CC_name_5B = x0 + dx * s;
                        D_80113A1E_3906CE_name_5B = y0 + dy * s;
                        espPosSet(D_801148A0_391550_name_5B, D_80113A1C_3906CC_name_5B, D_80113A1E_3906CE_name_5B);
                        HuPrcVSleep();
                    }
                }
                prev = D_80113A22_3906D2_name_5B;
            }
        } else {
            prev = D_80113A22_3906D2_name_5B;
        }
        espPosSet(D_801148A0_391550_name_5B, D_80113A1C_3906CC_name_5B, D_80113A1E_3906CE_name_5B);
    }
}

/* Fades the pointer sprite in or out over five frames whenever D_8011473C changes. */
void func_801091EC_385E9C_name_5B(void) {
    s16 shown;
    s16 i;

    shown = 0;
    while (1) {
        HuPrcVSleep();
        if (shown == D_8011473C_3913EC_name_5B) {
            continue;
        }
        if (D_8011473C_3913EC_name_5B != 0) {
            espDispOn(D_801148A0_391550_name_5B);
            for (i = 0; i < 5; i++) {
                func_8001A6BC_1B2BC(D_801148A0_391550_name_5B, i * 63.75f);
                HuPrcVSleep();
            }
        } else {
            for (i = 0; i < 5; i++) {
                func_8001A6BC_1B2BC(D_801148A0_391550_name_5B, 255.0f - i * 63.75f);
                HuPrcVSleep();
            }
            espDispOff(D_801148A0_391550_name_5B);
        }
        shown = D_8011473C_3913EC_name_5B;
    }
}

/* Points the pointer at choice n of the current position table. */
void func_8010933C_385FEC_name_5B(s16 n) {
    D_80113A1C_3906CC_name_5B = D_80113A14_3906C4_name_5B[n][0];
    D_80113A1E_3906CE_name_5B = D_80113A14_3906C4_name_5B[n][1];
    D_80113A22_3906D2_name_5B = n;
}

void func_80109374_386024_name_5B(s16 (*pos)[2]) {
    D_80113A14_3906C4_name_5B = pos;
}

/* The pointer's slide length in frames. */
void func_80109380_386030_name_5B(s16 frames) {
    D_80113A20_3906D0_name_5B = frames;
}

/* Moves the pointer to choice n (slides). */
void func_8010938C_38603C_name_5B(s16 n) {
    D_80113A22_3906D2_name_5B = n;
}

/* The menu's leaving object: once the menu is leaving (or the game is resetting), fades out
   (unless D_8011269A) and hands over to 80109408. */
void func_80109398_386048_name_5B(omObjData* obj) {
    if (D_80112690_38F340_name_5B != 0 || D_801011FC_101DFC != 0) {
        if (D_8011269A_38F34A_name_5B == 0) {
            InitFadeOut(D_80113A1A_3906CA_name_5B, 8);
            func_800794A8_7A0A8(15);
        }
        obj->func_ptr = func_80109408_3860B8_name_5B;
    }
}

/* After the fade: goes to (D_80114850 1), calls (2) or returns to (otherwise) overlay
   D_8011473A. */
void func_80109408_3860B8_name_5B(omObjData* obj) {
    u16 stat;

    if (func_8008F618_90218() != 0) {
        return;
    }
    if (D_801148A2_391552_name_5B != 0 && _CheckFlag(1)) {
        func_8007DF5C_7EB5C();
    }
    func_8001AC44_1B844(D_801148A0_391550_name_5B);
    func_8008CE5C_8DA5C();
    stat = 0x14;
    if (D_8011473A_3913EA_name_5B == 0x61) {
        stat = 0x12;
    }
    if (D_8011473A_3913EA_name_5B == 0x58) {
        stat |= 0x1000;
    }
    switch (D_80114850_391500_name_5B) {
        case 2:
            omOvlCallEx(D_8011473A_3913EA_name_5B, D_80114852_391502_name_5B, stat);
            break;
        case 1:
            omOvlGotoEx(D_8011473A_3913EA_name_5B, D_80114852_391502_name_5B, stat);
            break;
        default:
            omOvlReturnEx(1);
            break;
    }
}

/* Debug camera on controller 2: C-up/C-down zoom (Z faster; retail tests port 1's Z for C-up),
   the stick turns, L/R-ish buttons 0x800/0x400 move along the view, 0x200/0x100 strafe, C-right
   and C-left change the field of view, START (trigger) prints the camera. */
#ifdef NON_MATCHING
/* Same instruction count; differs in float register allocation (rx/spd swapped) and where the
   D_8010274C base is loaded in the 0x800/0x400 arms. */
void func_801094F8_3861A8_name_5B(void) {
    f32 zoom;
    f32 spd;
    f32 rx;
    f32 ry;
    f32 b;
    f32 inv;

    if (ContBtn[1] & 0x20) {
        if (ContBtn[0] & 0x2000) {
            zoom = D_800FA610_FB210 + 30.0f;
        } else {
            zoom = D_800FA610_FB210 + 10.0f;
        }
        D_800FA610_FB210 = zoom;
    }
    if ((ContBtn[1] & 0x10) && D_800FA610_FB210 - 10.0f != 0.0f) {
        if (ContBtn[1] & 0x2000) {
            zoom = D_800FA610_FB210 - 30.0f;
        } else {
            zoom = D_800FA610_FB210 - 10.0f;
        }
        D_800FA610_FB210 = zoom;
    }
    rx = D_80114744_3913F4_name_5B.x;
    ry = D_80114744_3913F4_name_5B.y;
    if (ContBtn[1] & 0x2000) {
        spd = 5.0f;
    } else {
        spd = 2.0f;
    }
    ry += -ContStkX[1] / 30 * spd;
    if (ry >= 360.0f) {
        ry -= 360.0f;
    } else if (ry < 0.0f) {
        ry += 360.0f;
    }
    D_80114744_3913F4_name_5B.y = ry;
    rx += (s8)(ContStkY[1] / 30) * spd;
    if (rx >= 360.0f) {
        rx -= 360.0f;
    } else if (rx < 0.0f) {
        rx += 360.0f;
    }
    D_80114744_3913F4_name_5B.x = rx;
    D_800FD474_FE074.x = (s16)rx;
    D_800FD474_FE074.y = (s16)D_80114744_3913F4_name_5B.y;
    if (ContBtn[1] & 0x2000) {
        spd = 10.0f;
    } else {
        spd = 2.0f;
    }
    if (ContBtn[1] & 0x800) {
        b = HuMathSin(ry) * HuMathSin(rx);
        spd = -spd;
        b *= spd;
        D_8010274C_10334C.x += b;
        D_8010274C_10334C.y += func_800B7890_B8490(rx) * spd;
        D_8010274C_10334C.z += func_800B7890_B8490(ry) * HuMathSin(rx) * spd;
    } else if (ContBtn[1] & 0x400) {
        b = HuMathSin(ry) * HuMathSin(rx);
        b *= spd;
        D_8010274C_10334C.x += b;
        D_8010274C_10334C.y += func_800B7890_B8490(rx) * spd;
        D_8010274C_10334C.z += func_800B7890_B8490(ry) * HuMathSin(rx) * spd;
    } else if (ContBtn[1] & 0x200) {
        rx = D_800C9B80_CA780->pos.z - D_8010274C_10334C.z;
        b = -(D_800C9B80_CA780->pos.x - D_8010274C_10334C.x);
        inv = 1.0f / func_800B1830_B2430(rx * rx + b * b);
        D_8010274C_10334C.x += rx * inv * spd;
        D_8010274C_10334C.y += 0.0f;
        D_8010274C_10334C.z += b * inv * spd;
    } else if (ContBtn[1] & 0x100) {
        rx = -(D_800C9B80_CA780->pos.z - D_8010274C_10334C.z);
        b = D_800C9B80_CA780->pos.x - D_8010274C_10334C.x;
        inv = 1.0f / func_800B1830_B2430(rx * rx + b * b);
        D_8010274C_10334C.x += rx * inv * spd;
        D_8010274C_10334C.y += 0.0f;
        D_8010274C_10334C.z += b * inv * spd;
    }
    if (ContBtn[1] & 2) {
        D_80112694_38F344_name_5B += 1.0f;
    }
    if (ContBtn[1] & 1) {
        D_80112694_38F344_name_5B -= 1.0f;
    }
    Hu3DCamSetPerspective(0, D_80112694_38F344_name_5B, D_8011485C_39150C_name_5B, D_80114858_391508_name_5B);
    if (ContBtnTrg[1] & 0x4000) {
        osSyncPrintf("CRot   (%f,%f,%f)\n", D_800FD474_FE074.x, D_800FD474_FE074.y, D_800FD474_FE074.z);
        osSyncPrintf("Center (%f,%f,%f)\n", D_8010274C_10334C.x, D_8010274C_10334C.y, D_8010274C_10334C.z);
        osSyncPrintf("CZoom  %f CFovy %f\n", D_800FA610_FB210, D_80112694_38F344_name_5B);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_801094F8_3861A8_name_5B);
#endif

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_80109B1C_3867CC_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_8010A0F0_386DA0_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_8010A1E4_386E94_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_8010A53C_3871EC_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_8010A7F4_3874A4_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/37F4E0", func_8010A8F4_3875A4_name_5B);
