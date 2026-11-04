#include "ovl_5C.h"

/* 80110020: one of the six scrolling pieces of the current set */
/* 8010BA98: positions relative to the sliding board at scr */
#define BX(o) (scr.unk_00 + -90.0f + (o))
#define BY(o) (scr.unk_04 + 32.0f + (o))
#define BA98_PLACE()                                                                 \
    espPosSet(D_801123AC_3A026C_name_5C[(s16)slot], BX(14.0f), BY(2.0f));            \
    espPosSet(D_801123C0_3A0280_name_5C, BX(48.0f), BY(15.0f));                      \
    espPosSet(D_801123B6_3A0276_name_5C[(s16)slot], BX(48.0f), BY(15.0f));           \
    espPosSet(D_801123C2_3A0282_name_5C[0], BX(2.0f), BY(108.0f));                   \
    espPosSet(D_801123C2_3A0282_name_5C[1], BX(178.0f), BY(108.0f));                 \
    func_800896DC_8A2DC(info, BX(10.0f), BY(28.0f));                                 \
    func_800896DC_8A2DC(names, BX(20.0f), BY(83.0f));                                \
    func_800896DC_8A2DC(prices, BX(130.0f), BY(83.0f));                              \
    espPosSet(D_801123CC_3A028C_name_5C, BX(132.0f), BY(42.0f))

#define PIECE(n) D_80112F60_3A0E20_name_5C[D_80112F20_3A0DE0_name_5C + (n)]

__asm__(".section .rodata");
const char D_801122CC_3A018C_name_5C[] = "%d";

void func_8010A190_398050_name_5C(void) {
    char str[16];
    f32 y;
    f32 t;
    s16 win;
    s16 i;
    s16 result;
    s16 left;
    u8 greeted;

    greeted = 0;
    PlayMusic(0x33);
    func_8002CA48_2D648(0xC0, 0xFF, 0xFF);
    func_801096BC_39757C_name_5C(D_80110F64_39EE24_name_5C, 1);
    func_80107480_395340_name_5C(4);
    func_8002C59C_2D19C(0x3C0, 0x3E8, 0xFF, 0xFF, 0xFF);
    func_8010B08C_398F4C_name_5C();
    func_8010DF5C_39BE1C_name_5C();
    if (D_801124D6_3A0396_name_5C == D_80112F5A_3A0E1A_name_5C) {
        func_800298A4_2A4A4(D_80112F60_3A0E20_name_5C[30], 4, 0);
        func_800297E8_2A3E8(D_80112F60_3A0E20_name_5C[30], 0.4f, 0.4f, 1.0f);
        func_80029C74_2A874(D_80112F60_3A0E20_name_5C[30], func_80029D0C_2A90C(D_80112F60_3A0E20_name_5C[30]));
        for (i = 0; i < 3; i++) {
            func_8002A15C_2AD5C(D_80112F60_3A0E20_name_5C[27], D_80112F60_3A0E20_name_5C[28], 1.0f);
            HuPrcVSleep();
        }
    }
    D_80112F24_3A0DE4_name_5C = 80.0f;
    Hu3DCamSetPerspective(0, D_80111C40_39FB00_name_5C, 80.0f, D_80112F54_3A0E14_name_5C);
    HuPrcSleep(10);
    InitFadeIn(0, 8);
    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    if (D_80112428_3A02E8_name_5C[4] == D_80112440_3A0300_name_5C[4]) {
        D_801123D0_3A0290_name_5C = 0;
    } else {
        D_801123D0_3A0290_name_5C = 1;
    }
    D_801123CE_3A028E_name_5C = 0;
    D_801123A0_3A0260_name_5C = func_8001A2F8_1AEF8(0x900C4);
    D_801123A4_3A0264_name_5C = func_8001A2F8_1AEF8(0x900C6);
    D_801123A2_3A0262_name_5C = func_8001A2F8_1AEF8(0x900C5);
    D_801123A6_3A0266_name_5C[0] = func_8001A2F8_1AEF8(0x900C7);
    D_801123A6_3A0266_name_5C[1] = func_8001A2F8_1AEF8(0x900C8);
    D_801123AA_3A026A_name_5C = func_8001A2F8_1AEF8(0x42);
    D_801123CC_3A028C_name_5C = func_80109EA4_397D64_name_5C();
    for (i = 0; i < 5; i++) {
        D_801123AC_3A026C_name_5C[i] = func_8001AAAC_1B6AC(D_801123A0_3A0260_name_5C, i, 1);
        func_8001A788_1B388(D_801123AC_3A026C_name_5C[i], 5);
        espDispOff(D_801123AC_3A026C_name_5C[i]);
    }
    D_801123C0_3A0280_name_5C = func_8001AAAC_1B6AC(D_801123A4_3A0264_name_5C, 0, 1);
    espPosSet(D_801123C0_3A0280_name_5C, 0, -100);
    espDispOff(D_801123C0_3A0280_name_5C);
    for (i = 0; i < 5; i++) {
        D_801123B6_3A0276_name_5C[i] = func_8001AAAC_1B6AC(D_801123A2_3A0262_name_5C, i, 1);
        func_8001A788_1B388(D_801123B6_3A0276_name_5C[i], 5);
        espDispOff(D_801123B6_3A0276_name_5C[i]);
    }
    for (i = 0; i < 2; i++) {
        D_801123C2_3A0282_name_5C[i] = func_8001AAAC_1B6AC(D_801123A6_3A0266_name_5C[i], 0, 1);
        espDispOff(D_801123C2_3A0282_name_5C[i]);
    }
    D_801123C6_3A0286_name_5C[0] = func_8001AAAC_1B6AC(D_801123AA_3A026A_name_5C, 0, 1);
    func_8001A788_1B388(D_801123C6_3A0286_name_5C[0], 100);
    func_8001A6BC_1B2BC(D_801123C6_3A0286_name_5C[0], 0x100);
    D_801123C6_3A0286_name_5C[1] = func_8001AAAC_1B6AC(D_801123AA_3A026A_name_5C, 0, 1);
    func_8001A6BC_1B2BC(D_801123C6_3A0286_name_5C[1], 0xD0);
    espDispOff(D_801123C6_3A0286_name_5C[0]);
    espDispOff(D_801123C6_3A0286_name_5C[1]);
    func_8010E560_39C420_name_5C(D_800F8C60.coinNum);
    win = func_8008DFC4_8EBC4(100, 0x98, 7);
    func_8008D59C_8E19C(win, 1 << D_80112A00_3A08C0_name_5C);
    func_80089284_89E84(win, 0x20, 0x20);
    func_8008E644_8F244(win, 0xC0);
    while (1) {
        func_8008AD44_8B944(win);
        func_8008E2DC_8EEDC(win, 1);
        func_8010DF5C_39BE1C_name_5C();
        if (D_801124D6_3A0396_name_5C == D_80112F5A_3A0E1A_name_5C) {
            while (1) {
                func_800890CC_89CCC(win, (void*)0x3B9, -1, -1);
                while (func_8008BA30_8C630(win) != 0) {
                    HuPrcVSleep();
                }
                if (func_8008BB48_8C748(win, 0, 0) != 0) {
                    func_800890CC_89CCC(win, (void*)0x3BA, -1, -1);
                    while (func_8008BA30_8C630(win) != 0) {
                        HuPrcVSleep();
                    }
                    if (func_8008BB48_8C748(win, 0, 0) == 0) {
                        break;
                    }
                } else {
                    HuPrcSleep(10);
                    func_8008E4D0_8F0D0(win, 1);
                    func_80029E80_2AA80(D_80112F60_3A0E20_name_5C[27], 1, 1);
                    y = D_800FC834_FD434[D_80112F60_3A0E20_name_5C[30]].pos.y;
                    for (i = 0; i < 6; i++) {
                        D_800FC834_FD434[D_80112F60_3A0E20_name_5C[30]].pos.y = y - (1.0f - func_800B7890_B8490(i * 18.0f)) * 30.0f;
                        HuPrcVSleep();
                    }
                    D_800FC834_FD434[D_80112F60_3A0E20_name_5C[30]].pos.y = y - 25.0f;
                    HuPrcSleep(5);
                    for (i = 0; i < 35; i++) {
                        t = 1.0f - (i / 2) / 15.0f;
                        if (t < 0.0f) {
                            t = 0.0f;
                        }
                        func_8002A15C_2AD5C(D_80112F60_3A0E20_name_5C[27], D_80112F60_3A0E20_name_5C[28], t);
                        HuPrcVSleep();
                    }
                    func_80107660_395520_name_5C(6, 30, 1, func_8010B050_398F10_name_5C);
                    func_800794A8_7A0A8(50);
                    func_80079614_7A214(50);
                    InitFadeOut(0, 10);
                    while (func_8008F618_90218() != 0) {
                        HuPrcVSleep();
                    }
                    HuPrcSleep(20);
                    D_801106D4_39E594_name_5C = 1;
                    D_801106D2_39E592_name_5C = 1;
                    D_80112420_3A02E0_name_5C = 1;
                    D_80112F28_3A0DE8_name_5C = 0x5C;
                    D_80112426_3A02E6_name_5C = 1;
                    break;
                }
            }
            HuPrcSleep(10);
            func_8008E4D0_8F0D0(win, 1);
            func_8008E6AC_8F2AC(win);
            func_8010E318_39C1D8_name_5C();
            return;
        }
        left = D_80112F58_3A0E18_name_5C;
        if (_CheckFlag(0x10) == 0) {
            left -= D_80112F40_3A0E00_name_5C[4];
        }
        if (_CheckFlag(0x11) == 0) {
            left -= D_80112F40_3A0E00_name_5C[3];
        }
        if (left == 0) {
            if (D_80112428_3A02E8_name_5C[4] == D_80112440_3A0300_name_5C[4] && _CheckFlag(0x11) == 0) {
                func_800890CC_89CCC(win, (void*)0x3B5, -1, -1);
                while (func_8008BA30_8C630(win) != 0) {
                    HuPrcVSleep();
                }
            } else if (D_80112428_3A02E8_name_5C[0] == D_80112440_3A0300_name_5C[0] && D_80112428_3A02E8_name_5C[1] == D_80112440_3A0300_name_5C[1]
                       && D_80112428_3A02E8_name_5C[2] == D_80112440_3A0300_name_5C[2] && _CheckFlag(0x10) == 0 && _CheckFlag(0x11) == 0) {
                func_800890CC_89CCC(win, (void*)0x3B3, -1, -1);
                while (func_8008BA30_8C630(win) != 0) {
                    HuPrcVSleep();
                }
            } else {
                func_800890CC_89CCC(win, (void*)0x3B2, -1, -1);
                while (func_8008BA30_8C630(win) != 0) {
                    HuPrcVSleep();
                }
            }
            func_8008E4D0_8F0D0(win, 1);
            func_8008E6AC_8F2AC(win);
            func_8010E318_39C1D8_name_5C();
            return;
        }
        if (greeted == 0) {
            greeted = 1;
            if (_CheckFlag(0x10) != 0 && D_80112428_3A02E8_name_5C[4] == 0 && _CheckFlag(0x11) != 0 && D_80112428_3A02E8_name_5C[3] == 0 && _CheckFlag(0x1C) == 0) {
                func_800890CC_89CCC(win, (void*)0x3B7, -1, -1);
                while (func_8008BA30_8C630(win) != 0) {
                    HuPrcVSleep();
                }
                _SetFlag(0x1B);
            } else if (_CheckFlag(0x10) != 0 && D_80112428_3A02E8_name_5C[4] == 0 && _CheckFlag(0x11) == 0) {
                func_800890CC_89CCC(win, (void*)0x3B4, -1, -1);
                while (func_8008BA30_8C630(win) != 0) {
                    HuPrcVSleep();
                }
                _SetFlag(0x1C);
            } else if (_CheckFlag(0x11) != 0 && D_80112428_3A02E8_name_5C[3] == 0 && _CheckFlag(0x1B) == 0) {
                func_800890CC_89CCC(win, (void*)0x3B6, -1, -1);
                while (func_8008BA30_8C630(win) != 0) {
                    HuPrcVSleep();
                }
            } else {
                left = D_80112F5C_3A0E1C_name_5C - D_801124D6_3A0396_name_5C;
                if (_CheckFlag(0x10) == 0) {
                    left -= D_80112F40_3A0E00_name_5C[4];
                }
                if (_CheckFlag(0x11) == 0) {
                    left -= D_80112F40_3A0E00_name_5C[3];
                }
                sprintf(str, D_801122CC_3A018C_name_5C, left);
                func_80089308_89F08(win, str, 0);
                func_800890CC_89CCC(win, (void*)0x3B0, -1, -1);
                while (func_8008BA30_8C630(win) != 0) {
                    HuPrcVSleep();
                }
            }
        }
        while (1) {
            func_800890CC_89CCC(win, (void*)0x3B1, -1, -1);
            while (func_8008BA30_8C630(win) != 0) {
                HuPrcVSleep();
            }
            if (func_8008BB48_8C748(win, 0, 0) == 0) {
                break;
            }
            func_800890CC_89CCC(win, (void*)0x3BA, -1, -1);
            while (func_8008BA30_8C630(win) != 0) {
                HuPrcVSleep();
            }
            if (func_8008BB48_8C748(win, 0, 0) == 0) {
                HuPrcSleep(10);
                func_8008E4D0_8F0D0(win, 1);
                func_8008E6AC_8F2AC(win);
            func_8010E318_39C1D8_name_5C();
            return;
            }
        }
        HuPrcSleep(10);
        func_8008E4D0_8F0D0(win, 1);
        func_80107660_395520_name_5C(5, 20, 1, (void*)-1);
        result = 0;
        D_801123CA_3A028A_name_5C = 0;
        while (1) {
            D_801123CA_3A028A_name_5C = func_8010B16C_39902C_name_5C(win);
            if (D_801123CA_3A028A_name_5C == -1) {
                break;
            }
            result = func_8010BA98_399958_name_5C(win);
            if (result != -1) {
                break;
            }
        }
        func_8008E4D0_8F0D0(win, 1);
        func_80107660_395520_name_5C(4, 20, 1, (void*)-1);
        if (result == 1000) {
            if (D_80112428_3A02E8_name_5C[0] == D_80112440_3A0300_name_5C[0] && D_80112428_3A02E8_name_5C[1] == D_80112440_3A0300_name_5C[1]
                && D_80112428_3A02E8_name_5C[2] == D_80112440_3A0300_name_5C[2] && _CheckFlag(0x10) == 0 && _CheckFlag(0x11) == 0) {
                func_8008AD44_8B944(win);
                func_8008E2DC_8EEDC(win, 1);
                func_800890CC_89CCC(win, (void*)0x3B3, -1, -1);
                while (func_8008BA30_8C630(win) != 0) {
                    HuPrcVSleep();
                }
                goto close;
            }
            if (D_80112428_3A02E8_name_5C[4] == D_80112440_3A0300_name_5C[4] && D_801123D0_3A0290_name_5C == 1 && _CheckFlag(0x11) == 0) {
                D_801123D0_3A0290_name_5C = 0;
                func_8008AD44_8B944(win);
                func_8008E2DC_8EEDC(win, 1);
                func_800890CC_89CCC(win, (void*)0x3B5, -1, -1);
                while (func_8008BA30_8C630(win) != 0) {
                    HuPrcVSleep();
                }
                goto close;
            }
            func_800298A4_2A4A4(D_80112F60_3A0E20_name_5C[30], 4, 0);
            func_800297E8_2A3E8(D_80112F60_3A0E20_name_5C[30], 0.4f, 0.4f, 1.0f);
            func_80029E80_2AA80(D_80112F60_3A0E20_name_5C[30], 1, 0);
            HuPrcSleep(10);
            func_8008AD44_8B944(win);
            func_8008E2DC_8EEDC(win, 1);
            PlaySound(0xD1);
            func_800890CC_89CCC(win, (void*)0x3B8, -1, -1);
            while (func_8008BA30_8C630(win) != 0) {
                HuPrcVSleep();
            }
        }
    }
close:
    func_8008E4D0_8F0D0(win, 1);
    func_8008E6AC_8F2AC(win);
    func_8010E318_39C1D8_name_5C();
}

// decomp-permuter
void func_8010B050_398F10_name_5C(s16 *t)
{
  unsigned int end = t[1];
  s16 now = t[0];
  if (now == (end - 20))
  {
    func_80088604_89204(D_80112A00_3A08C0_name_5C, 2, 2, 20);
  }
}

void func_8010B08C_398F4C_name_5C(void) {
    s16 sum;
    s16 i;
    u8 kind;

    sum = 0;
    for (i = 0; i < 6; i++) {
        sum += D_800F8C60.boardRecord[i][0];
    }
    if (sum >= 15) {
        for (i = 0; i < 72; i++) {
            if (D_801120C8_39FF88_name_5C[i] != 0) {
                kind = D_800CAD90[i].unk_04;
                if (kind < 2 || kind == 2) {
                    func_80067EF8_68AF8(i);
                }
            }
        }
    }
}

__asm__(".section .rodata");
const char D_801122D0_3A0190_name_5C[] = "item_fook1";

__asm__(".section .rodata");
const char D_801122DC_3A019C_name_5C[] = "item_fook2";

__asm__(".section .rodata");
const char D_801122E8_3A01A8_name_5C[] = "item_fook3";

__asm__(".section .rodata");
const char D_801122F4_3A01B4_name_5C[] = "item_fook4";

__asm__(".section .rodata");
const char D_80112300_3A01C0_name_5C[] = "item_fook5";

// register allocation: model lives on the stack in retail, f20 holds 584.0f, some hoists differ (masked 87)
#ifdef NON_MATCHING
s16 func_8010B16C_39902C_name_5C(s16 win) {
    Vec2f scr;
    char str[8];
    u16 model;
    s16 i;
    s16 kind;
    s16 result;
    s16 next;

    model = D_80112F60_3A0E20_name_5C[26];
    func_800297E8_2A3E8(model, 0.35f, 0.35f, 0.35f);
    func_800298A4_2A4A4(model, 4, 0);
    for (i = 0; i < 5; i++) {
        espDispOn(D_801123AC_3A026C_name_5C[i]);
    }
    if (_CheckFlag(0x10) == 0) {
        espDispOff(D_801123AC_3A026C_name_5C[D_801120BC_39FF7C_name_5C[4]]);
    }
    if (_CheckFlag(0x11) == 0) {
        espDispOff(D_801123AC_3A026C_name_5C[D_801120BC_39FF7C_name_5C[3]]);
    }
    scr.unk_00 = 220.0f;
    scr.unk_04 = -50.0f;
    for (i = 0; i < 11; i++) {
        scr.unk_04 = HuMathSin(i * 9.0f) * 96.0f + -50.0f;
        func_8010E848_39C708_name_5C(5, model, &scr, 584.0f);
        func_801066D4_394594_name_5C(model, D_801123AC_3A026C_name_5C[0], D_801122D0_3A0190_name_5C);
        func_801067BC_39467C_name_5C(0, D_801123AC_3A026C_name_5C[0], 0, 16);
        func_801066D4_394594_name_5C(model, D_801123AC_3A026C_name_5C[1], D_801122DC_3A019C_name_5C);
        func_801067BC_39467C_name_5C(1, D_801123AC_3A026C_name_5C[1], 0, 16);
        func_801066D4_394594_name_5C(model, D_801123AC_3A026C_name_5C[2], D_801122E8_3A01A8_name_5C);
        func_801067BC_39467C_name_5C(2, D_801123AC_3A026C_name_5C[2], 0, 16);
        func_801066D4_394594_name_5C(model, D_801123AC_3A026C_name_5C[3], D_801122F4_3A01B4_name_5C);
        func_801067BC_39467C_name_5C(3, D_801123AC_3A026C_name_5C[3], 0, 16);
        func_801066D4_394594_name_5C(model, D_801123AC_3A026C_name_5C[4], D_80112300_3A01C0_name_5C);
        func_801067BC_39467C_name_5C(4, D_801123AC_3A026C_name_5C[4], 0, 16);
        HuPrcVSleep();
    }
    func_8010687C_39473C_name_5C();
    if (_CheckFlag(0x10) == 0) {
        D_80112458_3A0318_name_5C[3] = 0;
    }
    if (_CheckFlag(0x11) == 0) {
        D_80112458_3A0318_name_5C[4] = 0;
    }
    func_801088A8_396768_name_5C(D_801120BC_39FF7C_name_5C[D_801123CA_3A028A_name_5C]);
    D_80112476_3A0336_name_5C = D_801120BC_39FF7C_name_5C[D_801123CA_3A028A_name_5C];
    func_8008AD44_8B944(win);
    func_8008E2DC_8EEDC(win, 1);
    func_800890CC_89CCC(win, (void*)0x3BB, -1, -1);
    while (func_8008BA30_8C630(win) != 0) {
        HuPrcVSleep();
    }
    D_80112424_3A02E4_name_5C = 1;
    HuPrcSleep(5);
    func_8010B96C_39982C_name_5C(win);
    while (1) {
        if ((ContStkX[D_80112A00_3A08C0_name_5C] < 0 ? -ContStkX[D_80112A00_3A08C0_name_5C] : ContStkX[D_80112A00_3A08C0_name_5C]) >= 31
            || (ContStkY[D_80112A00_3A08C0_name_5C] < 0 ? -ContStkY[D_80112A00_3A08C0_name_5C] : ContStkY[D_80112A00_3A08C0_name_5C]) >= 31) {
            next = func_801068BC_39477C_name_5C(D_80112476_3A0336_name_5C, 5, -ContStkX[D_80112A00_3A08C0_name_5C], ContStkY[D_80112A00_3A08C0_name_5C]);
            if (next != -1) {
                PlaySound(1);
                func_801088F8_3967B8_name_5C(next);
                HuPrcSleep(6);
                D_80112476_3A0336_name_5C = next;
                func_8010B96C_39982C_name_5C(win);
            }
        }
        if (ContBtnTrg[D_80112A00_3A08C0_name_5C] & 0x8000) {
            PlaySound(2);
            func_8010DF5C_39BE1C_name_5C();
            kind = D_801120B0_39FF70_name_5C[D_80112476_3A0336_name_5C];
            if (D_80112F40_3A0E00_name_5C[kind] != 0) {
                result = D_801120B0_39FF70_name_5C[D_80112476_3A0336_name_5C];
                break;
            }
            if (D_80112428_3A02E8_name_5C[kind] == D_80112440_3A0300_name_5C[kind]) {
                func_800890CC_89CCC(win, (void*)0x3CC, -1, -1);
            } else {
                sprintf(str, D_801122CC_3A018C_name_5C, D_80112440_3A0300_name_5C[kind] - D_80112428_3A02E8_name_5C[kind]);
                func_80089308_89F08(win, str, 0);
                func_800890CC_89CCC(win, (void*)0x3CB, -1, -1);
            }
            while (func_8008BA30_8C630(win) != 0) {
                HuPrcVSleep();
            }
            func_8010B96C_39982C_name_5C(win);
        }
        if (ContBtnTrg[D_80112A00_3A08C0_name_5C] & 0x4000) {
            PlaySound(4);
            result = -1;
            D_80112476_3A0336_name_5C = -1;
            break;
        }
        HuPrcVSleep();
    }
    D_80112424_3A02E4_name_5C = 0;
    scr.unk_00 = 220.0f;
    scr.unk_04 = -50.0f;
    for (i = 0; i < 11; i++) {
        scr.unk_04 = func_800B7890_B8490(i * 9.0f) * 96.0f + -50.0f;
        func_8010E848_39C708_name_5C(5, model, &scr, 584.0f);
        if (D_80112476_3A0336_name_5C != 0) {
            func_801066D4_394594_name_5C(model, D_801123AC_3A026C_name_5C[0], D_801122D0_3A0190_name_5C);
        }
        if (D_80112476_3A0336_name_5C != 1) {
            func_801066D4_394594_name_5C(model, D_801123AC_3A026C_name_5C[1], D_801122DC_3A019C_name_5C);
        }
        if (D_80112476_3A0336_name_5C != 2) {
            func_801066D4_394594_name_5C(model, D_801123AC_3A026C_name_5C[2], D_801122E8_3A01A8_name_5C);
        }
        if (D_80112476_3A0336_name_5C != 3) {
            func_801066D4_394594_name_5C(model, D_801123AC_3A026C_name_5C[3], D_801122F4_3A01B4_name_5C);
        }
        if (D_80112476_3A0336_name_5C != 4) {
            func_801066D4_394594_name_5C(model, D_801123AC_3A026C_name_5C[4], D_80112300_3A01C0_name_5C);
        }
        HuPrcVSleep();
    }
    func_800298A4_2A4A4(model, 4, 4);
    return result;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/398050", func_8010B16C_39902C_name_5C);
#endif

void func_8010B96C_39982C_name_5C(s16 win) {
    char str[8];
    u16 kind;

    kind = D_801120B0_39FF70_name_5C[D_80112476_3A0336_name_5C];
    func_8010DF5C_39BE1C_name_5C();
    if (D_80112F40_3A0E00_name_5C[(s16)kind] == 0) {
        if (D_80112428_3A02E8_name_5C[(s16)kind] == D_80112440_3A0300_name_5C[(s16)kind]) {
            func_800890CC_89CCC(win, (void*)((s16)kind + 0x3C6), -1, -1);
        } else {
            func_800890CC_89CCC(win, (void*)((s16)kind + 0x3BC), -1, -1);
        }
    } else {
        sprintf(str, D_801122CC_3A018C_name_5C, D_80112F40_3A0E00_name_5C[(s16)kind]);
        func_80089308_89F08(win, str, 0);
        func_800890CC_89CCC(win, (void*)((s16)kind + 0x3C1), -1, -1);
    }
    while (func_8008BA30_8C630(win) != 0) {
        HuPrcVSleep();
    }
}

__asm__(".section .rodata");
const char D_8011230C_3A01CC_name_5C[] = "%3d";

// register allocation: 0.5f through an f-register, row kept in other registers, 5 fewer instructions (masked 120)
#ifdef NON_MATCHING
s16 func_8010BA98_399958_name_5C(s16 win) {
    Vec2f scr;
    Vec2f from;
    Vec2f to;
    char str[8];
    s16 info;
    s16 names;
    s16 prices;
    s16 scroll;
    s16 prevScroll;
    s16 row;
    s16 prevRow;
    u16 model;
    u16 slot;
    s16 i;
    s16 price;
    s16 n;
    s16 result;
    s16 idx;
    s32 newImage;
    f32 t;

    scroll = 0;
    prevScroll = 0;
    slot = D_801120BC_39FF7C_name_5C[D_801123CA_3A028A_name_5C];
    model = D_80112F60_3A0E20_name_5C[29];
    func_800297E8_2A3E8(model, 0.5f, 0.5f, 0.5f);
    func_800298A4_2A4A4(model, 4, 0);
    espDispOn(D_801123C0_3A0280_name_5C);
    espDispOn(D_801123B6_3A0276_name_5C[(s16)slot]);
    func_8001A91C_1B51C(D_801123B6_3A0276_name_5C[(s16)slot], 1.0f, 0.0f);
    func_8010DF5C_39BE1C_name_5C();
    info = func_800888A8_894A8(0, 0, 100, 50, 0, 4);
    func_80089284_89E84(info, 0x10020, 0x10020);
    func_80089A48_8A648(info, 0);
    func_80089B2C_8A72C(info, 0);
    func_800896DC_8A2DC(info, -200, 0);
    func_8010D93C_39B7FC_name_5C(info);
    names = func_800888A8_894A8(0, 0, 120, 50, 0, 4);
    func_80089284_89E84(names, 0x20, 0x20);
    func_80089A7C_8A67C(names, 20000);
    func_80089B2C_8A72C(names, 0);
    func_80089C78_8A878(names, 1);
    func_80089A48_8A648(names, 0);
    func_80089DA0_8A9A0(names, 0xC0, 0xC0, 0xC0);
    prices = func_800888A8_894A8(0, 0, 48, 50, 0, 4);
    func_80089284_89E84(prices, 0x10020, 0x10020);
    func_80089A7C_8A67C(prices, 20000);
    func_80089B2C_8A72C(prices, 0);
    func_80089C78_8A878(prices, 1);
    func_80089A48_8A648(prices, 0);
    func_80089DA0_8A9A0(prices, 0xC0, 0xC0, 0xC0);
    func_8010DD00_39BBC0_name_5C(names, prices, D_801123CA_3A028A_name_5C, 0);
    func_800890CC_89CCC(names, (void*)0x3D3, -1, -1);
    func_800890CC_89CCC(prices, (void*)0x3D3, -1, -1);
    espDispOff(D_801123C2_3A0282_name_5C[0]);
    if (D_80112F40_3A0E00_name_5C[D_801123CA_3A028A_name_5C] - 3 <= 0) {
        espDispOff(D_801123C2_3A0282_name_5C[1]);
    } else {
        espDispOn(D_801123C2_3A0282_name_5C[1]);
    }
    func_80109F9C_397E5C_name_5C(D_800CAD90[D_80112A10_3A08D0_name_5C[D_801123CA_3A028A_name_5C][0]].unk_06 & 0xFFF);
    espDispOn(D_801123CC_3A028C_name_5C);
    func_8001A91C_1B51C(D_801123CC_3A028C_name_5C, 0.6f, 0.6f);
    scr.unk_00 = 200.0f;
    for (i = 0; i < 11; i++) {
        scr.unk_04 = HuMathSin(i * 9.0f) * 216.0f + -170.0f;
        func_8010E848_39C708_name_5C(5, model, &scr, 588.0f);
        espPosSet(D_801123C0_3A0280_name_5C, BX(48.0f), BY(15.0f));
        func_800896DC_8A2DC(info, BX(10.0f), BY(28.0f));
        func_800896DC_8A2DC(names, BX(20.0f), BY(83.0f));
        func_800896DC_8A2DC(prices, BX(130.0f), BY(83.0f));
        espPosSet(D_801123C2_3A0282_name_5C[0], BX(2.0f), BY(108.0f));
        espPosSet(D_801123C2_3A0282_name_5C[1], BX(178.0f), BY(108.0f));
        espPosSet(D_801123CC_3A028C_name_5C, BX(132.0f), BY(42.0f));
        HuPrcVSleep();
    }
    from.unk_00 = ((Ovl5CEsprite*)D_800F93FC_F9FFC)[D_801123AC_3A026C_name_5C[(s16)slot]].x;
    from.unk_04 = ((Ovl5CEsprite*)D_800F93FC_F9FFC)[D_801123AC_3A026C_name_5C[(s16)slot]].y;
    to.unk_00 = BX(14.0f);
    to.unk_04 = BY(2.0f);
    for (i = 0; i < 11; i++) {
        t = i * 9.0f;
        espPosSet(D_801123AC_3A026C_name_5C[(s16)slot], HuMathSin(t) * (to.unk_00 - from.unk_00) + from.unk_00,
                  HuMathSin(t) * (to.unk_04 - from.unk_04) + from.unk_04);
        if (i - 5 > 0) {
            espPosSet(D_801123B6_3A0276_name_5C[(s16)slot], BX(48.0f), BY(15.0f));
            func_8001A91C_1B51C(D_801123B6_3A0276_name_5C[(s16)slot], 1.0f, (i - 5) * 0.2f * 1.1f);
        }
        HuPrcVSleep();
    }
    func_8001A91C_1B51C(D_801123B6_3A0276_name_5C[(s16)slot], 1.0f, 1.0f);
    for (i = 0; i < 11; i++) {
        scr.unk_04 = HuMathSin(i * 9.0f) * -46.0f + 46.0f;
        func_8010E848_39C708_name_5C(5, model, &scr, 588.0f);
        BA98_PLACE();
        HuPrcVSleep();
    }
    func_8008AD44_8B944(win);
    func_8008E2DC_8EEDC(win, 1);
    while (func_8008BA30_8C630(win) != 0) {
        HuPrcVSleep();
    }
    prevRow = -1;
    row = 0;
    newImage = 0;
    espDispOn(D_801123C6_3A0286_name_5C[0]);
    espDispOn(D_801123C6_3A0286_name_5C[1]);
    espPosSet(D_801123C6_3A0286_name_5C[0], BX(12.0f), BY(94.0f));
    espPosSet(D_801123C6_3A0286_name_5C[1], BX(12.0f), BY(94.0f));
    while (1) {
        if (D_800FC9E0_FD5E0[D_80112A00_3A08C0_name_5C] & 0x800) {
            if (row != 0) {
                PlaySound(1);
                row--;
            }
        } else if (D_800FC9E0_FD5E0[D_80112A00_3A08C0_name_5C] & 0x400) {
            if (row < 2 && scroll + row < D_80112F40_3A0E00_name_5C[D_801123CA_3A028A_name_5C] - 1) {
                PlaySound(1);
                row++;
            }
        } else if (D_800FC9E0_FD5E0[D_80112A00_3A08C0_name_5C] & 0x200) {
            if (scroll != 0) {
                PlaySound(1);
                scroll -= 3;
            }
        } else if (D_800FC9E0_FD5E0[D_80112A00_3A08C0_name_5C] & 0x100) {
            if (scroll < D_80112F40_3A0E00_name_5C[D_801123CA_3A028A_name_5C] - 3) {
                PlaySound(1);
                scroll += 3;
            }
        } else if (ContBtnTrg[D_80112A00_3A08C0_name_5C] & 0x8000) {
            price = D_801120C8_39FF88_name_5C[D_80112A10_3A08D0_name_5C[D_801123CA_3A028A_name_5C][row + scroll]];
            if (D_800F8C60.coinNum >= price) {
                PlaySound(2);
                func_80089308_89F08(win, D_801123E1_3A02A1_name_5C[row], 0);
                D_800F920C_F9E0C[win].unkAA = -1;
                func_800890CC_89CCC(win, (void*)0x3D0, -1, -1);
                while (func_8008BA30_8C630(win) != 0) {
                    HuPrcVSleep();
                }
                if (func_8008BB48_8C748(win, 0, 0) == 0) {
                    PlaySound(3);
                    D_800F920C_F9E0C[win].unkAA = 300;
                    D_801123CE_3A028E_name_5C = 1;
                    D_800F8C60.coinNum -= price;
                    func_8010E6D4_39C594_name_5C(D_800F8C60.coinNum);
                    idx = scroll + row;
                    func_80067F94_68B94(D_80112A10_3A08D0_name_5C[D_801123CA_3A028A_name_5C][idx]);
                    func_8010DF5C_39BE1C_name_5C();
                    n = D_80112F40_3A0E00_name_5C[D_801123CA_3A028A_name_5C];
                    if (n != 0) {
                        if (idx >= n) {
                            if (scroll < n) {
                                row--;
                            } else {
                                scroll -= 3;
                                func_8010DAD4_39B994_name_5C(names, prices, scroll);
                                prevScroll = scroll;
                            }
                        }
                        if (scroll >= D_80112F40_3A0E00_name_5C[D_801123CA_3A028A_name_5C] - 3) {
                            espDispOff(D_801123C2_3A0282_name_5C[1]);
                        } else {
                            espDispOn(D_801123C2_3A0282_name_5C[1]);
                        }
                        func_8010DD00_39BBC0_name_5C(names, prices, D_801123CA_3A028A_name_5C, scroll);
                        func_800890CC_89CCC(names, (void*)0x3D3, -1, -1);
                        func_800890CC_89CCC(prices, (void*)0x3D3, -1, -1);
                        while (func_8008BA30_8C630(names) != 0) {
                            HuPrcVSleep();
                        }
                        func_80109F9C_397E5C_name_5C(D_800CAD90[D_80112A10_3A08D0_name_5C[D_801123CA_3A028A_name_5C][scroll + row]].unk_06 & 0xFFF);
                    } else {
                        espDispOff(D_801123C6_3A0286_name_5C[0]);
                        espDispOff(D_801123C6_3A0286_name_5C[1]);
                        func_8008AD44_8B944(names);
                        func_8008AD44_8B944(prices);
                        espDispOff(D_801123CC_3A028C_name_5C);
                    }
                    func_8010D93C_39B7FC_name_5C(info);
                    prevRow = -1;
                    if (D_801124D6_3A0396_name_5C == D_80112F5A_3A0E1A_name_5C) {
                        func_80067F94_68B94(0x38);
                        func_80067EF8_68AF8(0x38);
                        func_800890CC_89CCC(win, (void*)0x3D5, -1, -1);
                        while (func_8008BA30_8C630(win) != 0) {
                            HuPrcVSleep();
                        }
                        result = 1000;
                        break;
                    } else if (D_80112428_3A02E8_name_5C[0] == D_80112440_3A0300_name_5C[0] && D_80112428_3A02E8_name_5C[1] == D_80112440_3A0300_name_5C[1]
                               && D_80112428_3A02E8_name_5C[2] == D_80112440_3A0300_name_5C[2] && _CheckFlag(0x10) == 0 && _CheckFlag(0x11) == 0) {
                        func_800890CC_89CCC(win, (void*)0x3D5, -1, -1);
                        while (func_8008BA30_8C630(win) != 0) {
                            HuPrcVSleep();
                        }
                        result = 1000;
                        break;
                    } else if (D_80112428_3A02E8_name_5C[4] == D_80112440_3A0300_name_5C[4] && D_801123D0_3A0290_name_5C == 1 && _CheckFlag(0x11) == 0) {
                        func_800890CC_89CCC(win, (void*)0x3D5, -1, -1);
                        while (func_8008BA30_8C630(win) != 0) {
                            HuPrcVSleep();
                        }
                        result = 1000;
                        break;
                    } else {
                        func_800890CC_89CCC(win, (void*)0x3D1, -1, -1);
                        while (func_8008BA30_8C630(win) != 0) {
                            HuPrcVSleep();
                        }
                        if (func_8008BB48_8C748(win, 0, 0) != 0) {
                            result = -1;
                            break;
                        }
                        if (D_80112F40_3A0E00_name_5C[D_801123CA_3A028A_name_5C] == 0) {
                            func_800890CC_89CCC(win, (void*)0x3D4, -1, -1);
                            while (func_8008BA30_8C630(win) != 0) {
                                HuPrcVSleep();
                            }
                            result = -1;
                            break;
                        }
                    }
                } else {
                    PlaySound(4);
                    D_800F920C_F9E0C[win].unkAA = 300;
                    func_8008D904_8E504(win, (void*)(D_80112A10_3A08D0_name_5C[D_801123CA_3A028A_name_5C][scroll + row] + 0x3D9), 0);
                    sprintf(str, D_8011230C_3A01CC_name_5C, D_801120C8_39FF88_name_5C[D_80112A10_3A08D0_name_5C[D_801123CA_3A028A_name_5C][scroll + row]]);
                    func_80089308_89F08(win, str, 1);
                    func_800890CC_89CCC(win, (void*)0x3CD, -1, -1);
                    while (func_8008BA30_8C630(win) != 0) {
                        HuPrcVSleep();
                    }
                }
            } else {
                PlaySound(5);
            }
        }
        if (prevScroll != scroll) {
            prevScroll = scroll;
            row = 0;
            espDispOff(D_801123CC_3A028C_name_5C);
            func_8010DAD4_39B994_name_5C(names, prices, scroll);
            prevRow = -1;
            espPosSet(D_801123C6_3A0286_name_5C[0], BX(12.0f), BY(94.0f) + 0.0f);
            espPosSet(D_801123C6_3A0286_name_5C[1], BX(12.0f), BY(94.0f) + 0.0f);
            newImage = 1;
        }
        if (row != prevRow) {
            prevRow = row;
            t = row * 14;
            espPosSet(D_801123C6_3A0286_name_5C[0], BX(12.0f), BY(94.0f) + t);
            espPosSet(D_801123C6_3A0286_name_5C[1], BX(12.0f), BY(94.0f) + t);
            func_8008D904_8E504(win, (void*)(D_80112A10_3A08D0_name_5C[D_801123CA_3A028A_name_5C][scroll + row] + 0x3D9), 0);
            sprintf(str, D_8011230C_3A01CC_name_5C, D_801120C8_39FF88_name_5C[D_80112A10_3A08D0_name_5C[D_801123CA_3A028A_name_5C][scroll + row]]);
            func_80089308_89F08(win, str, 1);
            func_800890CC_89CCC(win, (void*)0x3CD, -1, -1);
            while (func_8008BA30_8C630(win) != 0) {
                HuPrcVSleep();
            }
            newImage = 1;
        }
        if (newImage != 0) {
            newImage = 0;
            espDispOn(D_801123CC_3A028C_name_5C);
            func_80109F9C_397E5C_name_5C(D_800CAD90[D_80112A10_3A08D0_name_5C[D_801123CA_3A028A_name_5C][scroll + row]].unk_06 & 0xFFF);
        }
        if (ContBtnTrg[D_80112A00_3A08C0_name_5C] & 0x4000) {
            PlaySound(4);
            result = -1;
            break;
        }
        HuPrcVSleep();
    }
    espDispOff(D_801123C6_3A0286_name_5C[0]);
    espDispOff(D_801123C6_3A0286_name_5C[1]);
    for (i = 0; i < 11; i++) {
        scr.unk_04 = func_800B7890_B8490(i * 9.0f) * 170.0f + -170.0f;
        func_8010E848_39C708_name_5C(5, model, &scr, 588.0f);
        BA98_PLACE();
        HuPrcVSleep();
    }
    func_8008CCA8_8D8A8(info);
    func_8008CCA8_8D8A8(names);
    func_8008CCA8_8D8A8(prices);
    func_800298A4_2A4A4(model, 4, 4);
    return result;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/398050", func_8010BA98_399958_name_5C);
#endif

__asm__(".section .rodata");
const char D_80112310_3A01D0_name_5C[] = "%2d";

void func_8010D93C_39B7FC_name_5C(s16 win) {
    char owned[8];
    char sale[8];
    char total[8];

    sprintf(owned, D_80112310_3A01D0_name_5C, D_80112428_3A02E8_name_5C[D_801123CA_3A028A_name_5C]);
    if (owned[0] == ' ') {
        owned[0] = 0x1A;
    }
    func_80089308_89F08(win, owned, 0);
    sprintf(sale, D_80112310_3A01D0_name_5C, D_80112F40_3A0E00_name_5C[D_801123CA_3A028A_name_5C]);
    if (sale[0] == ' ') {
        sale[0] = 0x1A;
    }
    func_80089308_89F08(win, sale, 1);
    sprintf(total, D_80112310_3A01D0_name_5C, D_80112428_3A02E8_name_5C[D_801123CA_3A028A_name_5C] + D_80112F40_3A0E00_name_5C[D_801123CA_3A028A_name_5C]);
    if (total[0] == ' ') {
        total[0] = 0x1A;
    }
    func_80089308_89F08(win, total, 2);
    func_80089C78_8A878(win, 1);
    func_80089DA0_8A9A0(win, 0xC0, 0xC0, 0xC0);
    func_800890CC_89CCC(win, (void*)0x3D2, -1, -1);
    while (func_8008BA30_8C630(win) != 0) {
        HuPrcVSleep();
    }
    func_80089284_89E84(win, 4, 4);
}

void func_8010DAD4_39B994_name_5C(s16 names, s16 prices, s16 scroll) {
    u16 model;

    model = D_80112F60_3A0E20_name_5C[29];
    func_8008D5D8_8E1D8(names);
    func_8008D5D8_8E1D8(prices);
    espDispOff(D_801123C6_3A0286_name_5C[0]);
    espDispOff(D_801123C6_3A0286_name_5C[1]);
    func_8002C9C0_2D5C0(model, D_801124D2_3A0392_name_5C);
    func_80029E80_2AA80(model, 1, 0);
    func_8010DD00_39BBC0_name_5C(names, prices, D_801123CA_3A028A_name_5C, scroll);
    func_800890CC_89CCC(names, (void*)0x3D3, -1, -1);
    func_800890CC_89CCC(prices, (void*)0x3D3, -1, -1);
    while (func_8008BA30_8C630(names) != 0) {
        HuPrcVSleep();
    }
    while (func_80029CE4_2A8E4(model) < func_80029D0C_2A90C(model)) {
        HuPrcVSleep();
    }
    if (scroll == 0) {
        espDispOff(D_801123C2_3A0282_name_5C[0]);
    } else {
        espDispOn(D_801123C2_3A0282_name_5C[0]);
    }
    if (scroll >= D_80112F40_3A0E00_name_5C[D_801123CA_3A028A_name_5C] - 3) {
        espDispOff(D_801123C2_3A0282_name_5C[1]);
    } else {
        espDispOn(D_801123C2_3A0282_name_5C[1]);
    }
    func_8008D6F0_8E2F0(names);
    func_8008D6F0_8E2F0(prices);
    espDispOn(D_801123C6_3A0286_name_5C[0]);
    espDispOn(D_801123C6_3A0286_name_5C[1]);
}

__asm__(".section .rodata");
const char D_80112314_3A01D4_name_5C[] = "";

// register allocation: entry address temporaries (masked 8)
#ifdef NON_MATCHING
void func_8010DD00_39BBC0_name_5C(s16 names, s16 prices, s16 kind, s16 scroll) {
    s16 i;
    s16* entry;

    for (i = 0; i < 3; i++) {
        if (scroll + i >= D_80112F40_3A0E00_name_5C[kind]) {
            func_8008D904_8E504(names, D_80112314_3A01D4_name_5C, i);
            func_8008D904_8E504(prices, D_80112314_3A01D4_name_5C, i);
        } else {
            entry = &D_80112A10_3A08D0_name_5C[kind][scroll + i];
            func_8008D904_8E504(names, (void*)(*entry + 0x3D9), i);
            sprintf(D_801123D2_3A0292_name_5C[i], D_8011230C_3A01CC_name_5C, D_801120C8_39FF88_name_5C[*entry]);
            func_800B10E0_B1CE0(D_801123E1_3A02A1_name_5C[i], D_801123D2_3A0292_name_5C[i]);
            if (D_801123D2_3A0292_name_5C[i][0] == ' ') {
                D_801123D2_3A0292_name_5C[i][0] = 0x1A;
            }
            func_8008D904_8E504(prices, D_801123D2_3A0292_name_5C[i], i);
            if (D_800F8C60.coinNum < D_801120C8_39FF88_name_5C[D_80112A10_3A08D0_name_5C[kind][scroll + i]]) {
                func_8008DA84_8E684(names, i, 2);
                func_8008DA84_8E684(prices, i, 2);
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/398050", func_8010DD00_39BBC0_name_5C);
#endif

// register allocation: retail does not hoist D_80112440, so one saved register fewer (masked 19)
#ifdef NON_MATCHING
void func_8010DF5C_39BE1C_name_5C(void) {
    s16 i;
    u8 kind;

    for (i = 0; i < 9; i++) {
        D_80112F40_3A0E00_name_5C[i] = D_80112440_3A0300_name_5C[i] = D_80112428_3A02E8_name_5C[i] = 0;
    }
    D_80112F5C_3A0E1C_name_5C = 0;
    D_80112F5A_3A0E1A_name_5C = 0;
    D_801124D6_3A0396_name_5C = 0;
    D_80112F58_3A0E18_name_5C = 0;
    for (i = 0; i < 72; i++) {
        if (D_801120C8_39FF88_name_5C[i] != 0) {
            kind = D_800CAD90[i].unk_04;
            if (func_80067F4C_68B4C(i) != 0) {
                if (func_80068040_68C40(i) != 0) {
                    D_801124E0_3A03A0_name_5C[kind][D_80112428_3A02E8_name_5C[kind]] = i;
                    D_80112428_3A02E8_name_5C[kind]++;
                    D_801124D6_3A0396_name_5C++;
                } else {
                    D_80112A10_3A08D0_name_5C[kind][D_80112F40_3A0E00_name_5C[kind]] = i;
                    D_80112F40_3A0E00_name_5C[kind]++;
                    D_80112F58_3A0E18_name_5C++;
                }
                D_80112F5C_3A0E1C_name_5C++;
            }
            D_80112F5A_3A0E1A_name_5C++;
            D_80112440_3A0300_name_5C[kind] += 1;
        }
    }
    if (func_80068040_68C40(15) != 0) {
        D_801124E0_3A03A0_name_5C[1][D_80112428_3A02E8_name_5C[1]] = 15;
        D_80112428_3A02E8_name_5C[1]++;
        D_801124D6_3A0396_name_5C++;
        D_80112F5C_3A0E1C_name_5C++;
        D_80112F5A_3A0E1A_name_5C++;
        D_80112440_3A0300_name_5C[1]++;
    }
    if (func_80068040_68C40(0x22) != 0) {
        D_801124E0_3A03A0_name_5C[2][D_80112428_3A02E8_name_5C[2]] = 0x22;
        D_80112428_3A02E8_name_5C[2]++;
        D_801124D6_3A0396_name_5C++;
        D_80112F5C_3A0E1C_name_5C++;
        D_80112F5A_3A0E1A_name_5C++;
        D_80112440_3A0300_name_5C[2]++;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/398050", func_8010DF5C_39BE1C_name_5C);
#endif

void func_8010E2AC_39C16C_name_5C(void) {
    func_8010DF5C_39BE1C_name_5C();
    if (func_80068040_68C40(15) != 0) {
        D_801124D6_3A0396_name_5C--;
    }
    if (func_80068040_68C40(0x22) != 0) {
        D_801124D6_3A0396_name_5C--;
    }
}

void func_8010E318_39C1D8_name_5C(void) {
    s16 i;

    if (D_801106D2_39E592_name_5C == 0) {
        func_800794A8_7A0A8(30);
        InitFadeOut(0, 8);
        while (func_8008F618_90218() != 0) {
            HuPrcVSleep();
        }
        do {
            func_80079920_7A520();
        } while (D_800CD526_CE126 & 8);
    }
    for (i = 0; i < 5; i++) {
        func_8001AC44_1B844(D_801123AC_3A026C_name_5C[i]);
    }
    SprAnimKill(D_801123A0_3A0260_name_5C);
    func_8001AC44_1B844(D_801123C0_3A0280_name_5C);
    SprAnimKill(D_801123A4_3A0264_name_5C);
    for (i = 0; i < 5; i++) {
        func_8001AC44_1B844(D_801123B6_3A0276_name_5C[i]);
    }
    SprAnimKill(D_801123A2_3A0262_name_5C);
    func_8001AC44_1B844(D_801123C2_3A0282_name_5C[0]);
    SprAnimKill(D_801123A6_3A0266_name_5C[0]);
    func_8001AC44_1B844(D_801123C2_3A0282_name_5C[1]);
    SprAnimKill(D_801123A6_3A0266_name_5C[1]);
    func_8001AC44_1B844(D_801123C6_3A0286_name_5C[0]);
    func_8001AC44_1B844(D_801123C6_3A0286_name_5C[1]);
    SprAnimKill(D_801123AA_3A026A_name_5C);
    func_8010E7C4_39C684_name_5C();
    func_8010A0D0_397F90_name_5C();
    if (D_801123CE_3A028E_name_5C != 0) {
        func_8007DF5C_7EB5C();
    }
    if (D_801106D2_39E592_name_5C != 0) {
        while (1) {
            HuPrcVSleep();
        }
    }
    func_8002C59C_2D19C(0x3DE, 0x3E8, 0xFF, 0xFF, 0xFF);
    D_80112F24_3A0DE4_name_5C = 500.0f;
    Hu3DCamSetPerspective(0, D_80111C40_39FB00_name_5C, 500.0f, D_80112F54_3A0E14_name_5C);
    func_801096BC_39757C_name_5C(D_80110F64_39EE24_name_5C, 0);
    func_80107480_395340_name_5C(3);
    func_800298A4_2A4A4(D_80112F60_3A0E20_name_5C[6], 4, 4);
    PlayMusic(0x32);
    InitFadeIn(0, 8);
}

__asm__(".section .rodata");
const char D_80112318_3A01D8_name_5C[] = "%5d";

void func_8010E560_39C420_name_5C(u32 coins) {
    char str[8];
    s16 i;

    D_801123F0_3A02B0_name_5C = func_8001A2F8_1AEF8(0x2E);
    D_801123F4_3A02B4_name_5C = func_8001AAAC_1B6AC(D_801123F0_3A02B0_name_5C, 0, 1);
    espPosSet(D_801123F4_3A02B4_name_5C, 0x27, 0x18);
    D_801123F2_3A02B2_name_5C = func_8001A2F8_1AEF8(0x38);
    if (coins > 99999) {
        coins = 99999;
    }
    sprintf(str, D_80112318_3A01D8_name_5C, coins);
    for (i = 0; i < 5; i++) {
        D_801123F6_3A02B6_name_5C[i] = func_8001AAAC_1B6AC(D_801123F2_3A02B2_name_5C, str[i] & 0xF, 0);
        espPosSet(D_801123F6_3A02B6_name_5C[i], i * 12 + 0x3F, 0x18);
        if (str[i] < '0') {
            espDispOff(D_801123F6_3A02B6_name_5C[i]);
        } else {
            espDispOn(D_801123F6_3A02B6_name_5C[i]);
        }
    }
}

void func_8010E6D4_39C594_name_5C(u32 coins) {
    char str[8];
    s16 i;

    if (coins > 99999) {
        coins = 99999;
    }
    sprintf(str, D_80112318_3A01D8_name_5C, coins);
    for (i = 0; i < 5; i++) {
        if (str[i] < '0') {
            espDispOff(D_801123F6_3A02B6_name_5C[i]);
        } else {
            espDispOn(D_801123F6_3A02B6_name_5C[i]);
            func_8001A810_1B410(D_801123F6_3A02B6_name_5C[i], str[i] & 0xF);
        }
    }
}

void func_8010E7C4_39C684_name_5C(void) {
    s16 i;

    func_8001AC44_1B844(D_801123F4_3A02B4_name_5C);
    SprAnimKill(D_801123F0_3A02B0_name_5C);
    for (i = 0; i < 5; i++) {
        func_8001AC44_1B844(D_801123F6_3A02B6_name_5C[i]);
    }
    SprAnimKill(D_801123F2_3A02B2_name_5C);
}

void func_8010E848_39C708_name_5C(s16 view, s16 model, Vec2f* scr, f32 depth) {
    Vec pos;
    Ovl5CCamView* v;

    v = &D_801129F0_3A08B0_name_5C[view];
    func_80109BEC_397AAC_name_5C(view, depth, scr, &pos);
    func_80029714_2A314(model, pos.x, pos.y, pos.z);
    func_8002979C_2A39C(model, v->rot.x, v->rot.y, v->rot.z);
}

void func_8010E8CC_39C78C_name_5C(void) {
    s16 size[2];
    s16 win;
    s16 i;

    func_8002CA48_2D648(0, 0, 0);
    func_801094FC_3973BC_name_5C(D_80111C50_39FB10_name_5C);
    func_801096BC_39757C_name_5C(D_80111C50_39FB10_name_5C, 0);
    omAddPrcObj(func_801084C4_396384_name_5C, 0x3F00, 0x800, 0);
    func_801088E0_3967A0_name_5C(D_80112FB0_3A0E70_name_5C);
    func_80107480_395340_name_5C(7);
    D_801124D8_3A0398_name_5C = 0;
    D_80112422_3A02E2_name_5C = 0;
    D_80112F20_3A0DE0_name_5C = 0;
    D_80112478_3A0338_name_5C = 60.0f;
    omAddPrcObj(func_80110020_39DEE0_name_5C, 0x3F00, 0x800, 0);
    D_80112400_3A02C0_name_5C = 0;
    for (i = 0; i < 6; i++) {
        omAddPrcObj(func_8010FC20_39DAE0_name_5C, 0x3F00, 0x800, 0);
    }
    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    func_8008DBE0_8E7E0(size, 0x3D6, 0x3D8);
    win = func_8008E73C_8F33C(-1, (320 - size[0]) / 2, 0xCC, size[0], size[1], 0);
    func_8008D59C_8E19C(win, 1 << D_80112A00_3A08C0_name_5C);
    func_80089284_89E84(win, 0x20, 0x20);
    func_8008E978_8F578(win);
    D_8011243A_3A02FA_name_5C = 0;
    while (1) {
        func_800890CC_89CCC(win, (void*)0x3D6, -1, -1);
        while (func_8008BA30_8C630(win) != 0) {
            HuPrcVSleep();
        }
        if (func_8010EE64_39CD24_name_5C() == 0) {
            func_8008EED8_8FAD8(win, 0);
            func_800794A8_7A0A8(40);
            func_80079614_7A214(40);
            InitFadeOut(0, 20);
            while (func_8008F618_90218() != 0) {
                HuPrcVSleep();
            }
            HuPrcSleep(10);
            D_801106D4_39E594_name_5C = 1;
            D_80112420_3A02E0_name_5C = 1;
            D_80112F28_3A0DE8_name_5C = 0x5C;
            D_80112426_3A02E6_name_5C = 2;
            D_801106D2_39E592_name_5C = 1;
            while (1) {
                HuPrcVSleep();
            }
        }
        func_800890CC_89CCC(win, (void*)0x3D7, -1, -1);
        while (func_8008BA30_8C630(win) != 0) {
            HuPrcVSleep();
        }
        if (func_8008BB48_8C748(win, 0, 0) == 0) {
            break;
        }
        D_8011243A_3A02FA_name_5C = 1;
    }
    func_800890CC_89CCC(win, (void*)0x3D8, -1, -1);
    while (func_8008BA30_8C630(win) != 0) {
        HuPrcVSleep();
    }
    HuPrcSleep(30);
    func_8008EED8_8FAD8(win, 0);
    func_8008CCA8_8D8A8(win);
    D_80112422_3A02E2_name_5C = 1;
    HuPrcSleep(10);
    D_80112478_3A0338_name_5C *= 1.5f;
    while (1) {
        if (D_800FC834_FD434[D_80112F60_3A0E20_name_5C[4]].pos.z < 4000.0f) {
            break;
        }
        HuPrcVSleep();
    }
    PlaySound(0xAD);
    func_800794A8_7A0A8(120);
    func_80107660_395520_name_5C(8, 30, 1, (void*)-1);
    HuPrcSleep(10);
    func_80107660_395520_name_5C(9, 20, 2, (void*)-1);
    while (1) {
        if (D_800FC834_FD434[D_80112F60_3A0E20_name_5C[4]].pos.z < 350.0f) {
            break;
        }
        HuPrcVSleep();
    }
    func_8008F624_90224(0xFF, 0xFF, 0xFF);
    InitFadeOut(0, 15);
    func_80088604_89204(D_80112A00_3A08C0_name_5C, 2, 3, 10);
    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    func_80088604_89204(D_80112A00_3A08C0_name_5C, 2, 2, 20);
    HuPrcSleep(30);
    D_801106D4_39E594_name_5C = 1;
    for (i = 1; i < 4; i++) {
        gPlayers[i].group = 1;
    }
    gPlayers[0].group = 0;
    gPlayers[0].port = D_80112A01_3A08C1_name_5C;
    gPlayers[0].flags = 0;
    GwSystem.current_player_index = 0;
    GwSystem.chosenMinigameIndex = 0x39;
    D_80112420_3A02E0_name_5C = 2;
    D_80112F28_3A0DE8_name_5C = 0x5E;
    omOvlHisChg(0, 0x5C, 2, 0x114);
    D_801106D2_39E592_name_5C = 1;
    GwSystem.unk_25 = 0;
    while (1) {
        HuPrcVSleep();
    }
}

__asm__(".section .rodata");
const char D_8011231C_3A01DC_name_5C[20] = "c_panel";

// register allocation (masked 16)
#ifdef NON_MATCHING
s32 func_8010EE64_39CD24_name_5C(void) {
    s16 anim[6];
    s16 icon[6];
    Vec pos;
    u16 model;
    s16 panelAnim;
    s16 markerAnim;
    s16 panel;
    s16 marker;
    s16 i;
    s16 frame;
    s16 next;
    s32 result;
    f32 dir;

    model = D_80112F60_3A0E20_name_5C[24];
    if (D_8011243A_3A02FA_name_5C == 0) {
        func_8002C9C0_2D5C0(model, D_80112498_3A0358_name_5C[25]);
    } else {
        func_8002C9C0_2D5C0(model, D_80112498_3A0358_name_5C[26]);
    }
    func_80029C74_2A874(model, 30.0f);
    func_80029E80_2AA80(model, 1, 1);
    func_80029760_2A360(model, &pos);
    panelAnim = func_8001A2F8_1AEF8(0x90084);
    panel = func_8001AAAC_1B6AC(panelAnim, 0, 1);
    func_8001A6BC_1B2BC(panel, 0x100);
    espPosSet(panel, -100, -100);
    for (i = 0; i < 6; i++) {
        anim[i] = func_8001A2F8_1AEF8(D_8011215C_3A001C_name_5C[i]);
        icon[i] = func_8001AAAC_1B6AC(anim[i], 0, 1);
        func_8001A6BC_1B2BC(icon[i], 0x100);
        espPosSet(icon[i], -100, -100);
        if (i & 1) {
            HuPrcVSleep();
        }
        func_8010FFDC_39DE9C_name_5C(i, 0.0f, 0.0f, -300.0f);
    }
    HuPrcVSleep();
    markerAnim = func_8001A2F8_1AEF8(0x90093);
    marker = func_8001AAAC_1B6AC(markerAnim, 0, 1);
    func_8001A6BC_1B2BC(marker, 0x80);
    espDispOff(marker);
    func_800298A4_2A4A4(model, 4, 0);
    PlaySound(0xAC);
    if (D_8011243A_3A02FA_name_5C == 0) {
        dir = 1.0f;
    } else {
        dir = -1.0f;
    }
    for (frame = 0; frame < 20; frame++) {
        D_800FC834_FD434[(s16)model].pos.z = (1.0f - HuMathSin(frame * 4.5f)) * 600.0f * dir + pos.z;
        if (frame == 15) {
            func_80029E80_2AA80(model, 1, 0);
            func_80029FE4_2ABE4(model, 1.5f);
        }
        func_80106618_3944D8_name_5C(model, panel, D_8011231C_3A01DC_name_5C);
        for (i = 0; i < 6; i++) {
            func_8010FB28_39D9E8_name_5C(icon[i], i);
        }
        HuPrcVSleep();
    }
    while (1) {
        if (!(func_80029CE4_2A8E4(model) < func_80029D0C_2A90C(model))) {
            break;
        }
        func_80106618_3944D8_name_5C(model, panel, D_8011231C_3A01DC_name_5C);
        for (i = 0; i < 6; i++) {
            func_8010FB28_39D9E8_name_5C(icon[i], i);
        }
        HuPrcVSleep();
    }
    PlaySound(0xB1);
    func_8002C9C0_2D5C0(model, D_80112498_3A0358_name_5C[24]);
    while (1) {
        if (!(func_80029CE4_2A8E4(model) < 30.0f)) {
            break;
        }
        func_80106618_3944D8_name_5C(model, panel, D_8011231C_3A01DC_name_5C);
        for (i = 0; i < 6; i++) {
            func_8010FB28_39D9E8_name_5C(icon[i], i);
            func_801067BC_39467C_name_5C(i, icon[i], 10, -6);
        }
        HuPrcVSleep();
    }
    func_80029E80_2AA80(model, 1, 1);
    func_801088EC_3967AC_name_5C(5);
    func_8010687C_39473C_name_5C();
    func_801088A8_396768_name_5C(0);
    D_80112476_3A0336_name_5C = 0;
    D_80112424_3A02E4_name_5C = 1;
    HuPrcSleep(5);
    while (1) {
        if ((ContStkX[D_80112A00_3A08C0_name_5C] < 0 ? -ContStkX[D_80112A00_3A08C0_name_5C] : ContStkX[D_80112A00_3A08C0_name_5C]) >= 31
            || (ContStkY[D_80112A00_3A08C0_name_5C] < 0 ? -ContStkY[D_80112A00_3A08C0_name_5C] : ContStkY[D_80112A00_3A08C0_name_5C]) >= 31) {
            next = func_801068BC_39477C_name_5C(D_80112476_3A0336_name_5C, 6, -ContStkX[D_80112A00_3A08C0_name_5C], ContStkY[D_80112A00_3A08C0_name_5C]);
            if (next != -1) {
                func_801088F8_3967B8_name_5C(next);
                HuPrcSleep(6);
                D_80112476_3A0336_name_5C = next;
            }
        }
        if (ContBtnTrg[D_80112A00_3A08C0_name_5C] & 0x8000) {
            PlaySound((s16)(D_80112476_3A0336_name_5C + 0x107));
            PlaySound(2);
            func_80088604_89204(D_80112A00_3A08C0_name_5C, 2, 3, 10);
            func_8001A854_1B454(icon[D_80112476_3A0336_name_5C], 1, 0);
            func_8001A89C_1B49C(icon[D_80112476_3A0336_name_5C], 1);
            func_8010FFDC_39DE9C_name_5C(D_80112476_3A0336_name_5C, 0.0f, 0.0f, 0.0f);
            D_80112424_3A02E4_name_5C = 0;
            func_8010FBDC_39DA9C_name_5C(marker, icon[D_80112476_3A0336_name_5C]);
            result = 1;
            espDispOn(marker);
            gPlayers[0].character = D_80112477_3A0337_name_5C;
            break;
        }
        if (ContBtnTrg[D_80112A00_3A08C0_name_5C] & 0x4000) {
            PlaySound(4);
            D_80112424_3A02E4_name_5C = 0;
            result = 0;
            break;
        }
        for (i = 0; i < 6; i++) {
            if (D_80112476_3A0336_name_5C != i) {
                func_8001A854_1B454(icon[i], 0, 0);
            } else {
                func_8001A854_1B454(icon[i], 1, 0);
            }
            func_8001A89C_1B49C(icon[i], 1);
        }
        HuPrcVSleep();
    }
    func_80029E80_2AA80(model, 1, 0);
    func_80029FE4_2ABE4(model, 2.0f);
    PlaySound(0xB1);
    if (result != 0) {
        for (frame = 0; frame < 15; frame++) {
            func_80106618_3944D8_name_5C(model, panel, D_8011231C_3A01DC_name_5C);
            for (i = 0; i < 6; i++) {
                func_8010FB28_39D9E8_name_5C(icon[i], i);
            }
            for (i = 0; i < 4; i++) {
                func_8010FBDC_39DA9C_name_5C(marker, icon[D_80112476_3A0336_name_5C]);
            }
            HuPrcVSleep();
        }
        func_8002C9C0_2D5C0(model, D_80112498_3A0358_name_5C[25]);
        func_80029FE4_2ABE4(model, 1.5f);
        for (frame = 0; frame < 10; frame++) {
            D_800FC834_FD434[(s16)model].pos.z = pos.z - frame * 100;
            func_80106618_3944D8_name_5C(model, panel, D_8011231C_3A01DC_name_5C);
            for (i = 0; i < 6; i++) {
                func_8010FB28_39D9E8_name_5C(icon[i], i);
            }
            for (i = 0; i < 4; i++) {
                func_8010FBDC_39DA9C_name_5C(marker, icon[D_80112476_3A0336_name_5C]);
            }
            HuPrcVSleep();
        }
    } else {
        for (frame = 0; frame < 15; frame++) {
            func_80106618_3944D8_name_5C(model, panel, D_8011231C_3A01DC_name_5C);
            for (i = 0; i < 6; i++) {
                func_8010FB28_39D9E8_name_5C(icon[i], i);
            }
            for (i = 0; i < 4; i++) {
                func_8010FBDC_39DA9C_name_5C(marker, icon[D_80112476_3A0336_name_5C]);
            }
            HuPrcVSleep();
        }
        func_8002C9C0_2D5C0(model, D_80112498_3A0358_name_5C[26]);
        func_80029FE4_2ABE4(model, 1.5f);
        for (frame = 0; frame < 11; frame++) {
            D_800FC834_FD434[(s16)model].pos.z = (1.0f - func_800B7890_B8490(frame * 9.0f)) * 600.0f + pos.z;
            func_80106618_3944D8_name_5C(model, panel, D_8011231C_3A01DC_name_5C);
            for (i = 0; i < 6; i++) {
                func_8010FB28_39D9E8_name_5C(icon[i], i);
            }
            for (i = 0; i < 4; i++) {
                func_8010FBDC_39DA9C_name_5C(marker, icon[D_80112476_3A0336_name_5C]);
            }
            HuPrcVSleep();
        }
    }
    func_800298A4_2A4A4(model, 4, 4);
    func_8001AC44_1B844(panel);
    SprAnimKill(panelAnim);
    for (i = 0; i < 6; i++) {
        func_8001AC44_1B844(icon[i]);
        SprAnimKill(anim[i]);
    }
    SprAnimKill(markerAnim);
    func_8001AC44_1B844(marker);
    func_801095F0_3974B0_name_5C(D_80111C50_39FB10_name_5C, 24, model);
    return result;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/398050", func_8010EE64_39CD24_name_5C);
#endif

void func_8010FB28_39D9E8_name_5C(s16 sprite, s16 slot) {
    espPosSet(sprite, D_80112174_3A0034_name_5C[slot][0] + D_80112A04_3A08C4_name_5C.unk_00 - 68.0f,
              D_80112174_3A0034_name_5C[slot][1] + D_80112A04_3A08C4_name_5C.unk_04 - 3.0f);
}

void func_8010FBDC_39DA9C_name_5C(s16 sprite, s16 slot) {
    Ovl5CEsprite* esp = &((Ovl5CEsprite*)D_800F93FC_F9FFC)[slot];

    espPosSet(sprite, esp->x, esp->y);
}

// NON_MATCHING: register allocation (masked 10, raw 72): pos and m swap s4/s5, and retail keeps the
// allocation in v0 until after the index load. S3-Q05 tried: the array store with i = ... inside it,
// the store after the increment (i = D++ too: masked 44), m declared after pos/target: no change.
#ifdef NON_MATCHING
void func_8010FC20_39DAE0_name_5C(void) {
    Ovl5CMover* m;
    s16 i;
    u16 model;
    u16 shadow;
    Vec* pos;
    Vec* target;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 dist;

    m = func_80027154_27D54(sizeof(Ovl5CMover), 0x7918);
    i = D_80112400_3A02C0_name_5C;
    D_80112408_3A02C8_name_5C[i] = m;
    D_80112400_3A02C0_name_5C++;
    m->id = i;
    pos = &m->pos;
    target = &m->target;
    model = D_80112F60_3A0E20_name_5C[i * 3 + 6];
    shadow = D_80112F60_3A0E20_name_5C[i * 3 + 8];
    D_80101300_101F00 = 0.1f;
    D_8010105C_101C5C = 0.3f;
    func_80029A8C_2A68C(model);
    func_80029AFC_2A6FC(model);
    func_8002D1EC_2DDEC(model, 1);
    func_8002D274_2DE74(model, 0xFF, 0xFF, 0xC0);
    func_8002D2B4_2DEB4(model, 0.0f, 100.0f, 0.0f);
    D_8010105C_101C5C = 1.0f;
    D_80101300_101F00 = 1.0f;
    func_8002C9C0_2D5C0(model, D_80112498_3A0358_name_5C[i * 3 + 7]);
    func_80029E80_2AA80(model, 2, 2);
    func_800298A4_2A4A4(model, 4, 4);
    func_80029714_2A314(model, 0.0f, 0.0f, -300.0f);
    func_80029714_2A314(shadow, 0.0f, 0.0f, -300.0f);
    func_80029760_2A360(model, pos);
    m->target = m->pos;
    while (1) {
        if (pos->z < 250.0f && pos->z > -250.0f) {
            func_800298A4_2A4A4(model, 4, 0);
            func_800298A4_2A4A4(shadow, 4, 0);
        } else {
            func_800298A4_2A4A4(model, 4, 4);
            func_800298A4_2A4A4(shadow, 4, 4);
        }
        if (m->pos.x != m->target.x || pos->y != target->y || pos->z != target->z) {
            dx = m->target.x - m->pos.x;
            dy = target->y - pos->y;
            dz = target->z - pos->z;
            dist = func_800B1830_B2430(dx * dx + dy * dy + dz * dz);
            if (dist < m->speed) {
                m->pos = m->target;
            } else {
                m->pos.x += dx / dist * m->speed;
                pos->y += dy / dist * m->speed;
                pos->z += dz / dist * m->speed;
            }
            m->speed += 0.5f;
        }
        func_80029714_2A314(model, m->pos.x, pos->y, pos->z);
        func_80029714_2A314(shadow, m->pos.x, 0.0f, pos->z);
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/398050", func_8010FC20_39DAE0_name_5C);
#endif

// decomp-permuter
void func_8010FFDC_39DE9C_name_5C(s16 i, f32 x, f32 y, f32 z)
{
  f32 new_var;
  Ovl5CMover **list = D_80112408_3A02C8_name_5C;
  new_var = x;
  D_80112408_3A02C8_name_5C[i]->target.x = new_var;
  D_80112408_3A02C8_name_5C[i]->target.y = y;
  D_80112408_3A02C8_name_5C[i]->target.z = z;
  D_80112408_3A02C8_name_5C[i]->speed = 5.0f;
}

// register allocation: 5000.0f is not kept in a register, spill slots differ, 2 more instructions (masked 59)
#ifdef NON_MATCHING
void func_80110020_39DEE0_name_5C(void) {
    f32 z[6];
    Ovl5CModelDef* def;
    s16 i;
    s16 n;
    s32 stop;

    stop = 0;
    z[0] = -3000.0f;
    z[1] = -1000.0f;
    z[2] = 1000.0f;
    z[3] = 3000.0f;
    z[4] = 3000.0f;
    z[5] = 0.0f;
    func_800298A4_2A4A4(PIECE(4), 4, 4);
    func_800298A4_2A4A4(PIECE(5), 4, 4);
    while (1) {
        for (i = 0; i < 6; i++) {
            n = D_80112F20_3A0DE0_name_5C + i;
            def = &D_80111C50_39FB10_name_5C[n];
            z[i] -= D_80112478_3A0338_name_5C;
            if (z[i] < -3000.0f && !stop) {
                z[i] += 8000.0f;
            }
            if (z[i] > 5000.0f && !stop) {
                z[i] -= 8000.0f;
            }
            func_80029714_2A314(D_80112F60_3A0E20_name_5C[n], def->pos.x * 0.5f, def->pos.y * 0.5f, z[i] * 0.5f);
        }
        if (D_801124D8_3A0398_name_5C != 0 && D_80112478_3A0338_name_5C <= 0.0f && !stop) {
            stop = 1;
            D_80112158_3A0018_name_5C = 1;
            z[0] -= (s16)(z[0] / 2000.0f) * 2000.0f;
            D_800FC834_FD434[PIECE(0)].pos.z = z[0] * 0.5f;
            if (z[0] <= 0.0f) {
                z[3] = z[0] + 2000.0f;
                D_800FC834_FD434[PIECE(3)].pos.z = z[3] * 0.5f;
            } else {
                func_800298A4_2A4A4(PIECE(3), 4, 4);
            }
            z[1] = z[0] - 2000.0f;
            D_800FC834_FD434[PIECE(1)].pos.z = z[1] * 0.5f;
            z[2] = z[1] - 2000.0f;
            D_800FC834_FD434[PIECE(2)].pos.z = z[2] * 0.5f;
            z[5] = z[2] - 2000.0f;
            D_800FC834_FD434[PIECE(5)].pos.z = z[5] * 0.5f;
            func_800298A4_2A4A4(PIECE(5), 4, 0);
        }
        if (D_80112422_3A02E2_name_5C != 0 && !stop) {
            stop = 1;
            D_80112158_3A0018_name_5C = 1;
            z[0] -= (s16)(z[0] / 2000.0f) * 2000.0f;
            D_800FC834_FD434[PIECE(0)].pos.z = z[0] * 0.5f;
            if (z[0] >= 0.0f) {
                z[3] = z[0] - 2000.0f;
                D_800FC834_FD434[PIECE(3)].pos.z = z[3] * 0.5f;
                z[1] = z[0] + 2000.0f;
                D_800FC834_FD434[PIECE(1)].pos.z = z[1] * 0.5f;
                z[2] = z[1] + 2000.0f;
                D_800FC834_FD434[PIECE(2)].pos.z = z[2] * 0.5f;
                z[4] = z[2] + 2000.0f;
                D_800FC834_FD434[PIECE(4)].pos.z = z[4] * 0.5f;
            } else {
                z[1] = z[0] + 2000.0f;
                D_800FC834_FD434[PIECE(1)].pos.z = z[1] * 0.5f;
                z[2] = z[1] + 2000.0f;
                D_800FC834_FD434[PIECE(2)].pos.z = z[2] * 0.5f;
                z[3] = z[2] + 2000.0f;
                D_800FC834_FD434[PIECE(3)].pos.z = z[3] * 0.5f;
                z[4] = z[3] + 2000.0f;
                D_800FC834_FD434[PIECE(4)].pos.z = z[4] * 0.5f;
            }
            func_800298A4_2A4A4(PIECE(4), 4, 0);
        }
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/398050", func_80110020_39DEE0_name_5C);
#endif

/* .data (0x39FB10-0x3A0050, 80111C50-80112190) */
/* 80111C50 */
Ovl5CModelDef D_80111C50_39FB10_name_5C[28] = {
    { 0x900BF, 0x2231, 0, 0, 0x0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0x900BF, 0x2231, 0, 0, 0x0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0x900BF, 0x2231, 0, 0, 0x0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0x900BF, 0x2231, 0, 0, 0x0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0x900C0, 0x2231, 0, 2, 0x0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0x900C0, 0x2231, 0, 2, 0x0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0x200D2, 0x2245, 0, 0, 0x0, { 31.0f, 0.0f, 13.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0x20002, 0x14, 0, 0, 0x0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0xD, 0xA51, 0, 0, 0x0, { 31.0f, 0.0f, 13.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0x300D2, 0x2245, 0, 0, 0x0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0x30002, 0x14, 0, 0, 0x0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0xD, 0xA51, 0, 0, 0x0, { 31.0f, 0.0f, 13.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0x700D2, 0x2245, 0, 0, 0x0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0x70002, 0x14, 0, 0, 0x0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0xD, 0xA51, 0, 0, 0x0, { 31.0f, 0.0f, 13.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0x400D2, 0x2245, 0, 0, 0x0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0x40002, 0x14, 0, 0, 0x0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0xD, 0xA51, 0, 0, 0x0, { 31.0f, 0.0f, 13.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0x500D2, 0x2245, 0, 0, 0x0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0x50002, 0x14, 0, 0, 0x0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0xD, 0xA51, 0, 0, 0x0, { 31.0f, 0.0f, 13.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0x600D2, 0x2245, 0, 0, 0x0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0x60002, 0x14, 0, 0, 0x0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0xD, 0xA51, 0, 0, 0x0, { 31.0f, 0.0f, 13.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0x90074, 0x2215, 0, 2, 0x0, { -60.0f, 97.5f, 0.0f }, { 0.0f, 90.0f, 0.0f } },
    { 0x90075, 0x14, 0, 0, 0x0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { 0x90076, 0x14, 0, 0, 0x0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
    { -1, 0x0, 0, 0, 0x0, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
};
s16 D_801120B0_39FF70_name_5C[6] = { 0, 1, 2, 4, 3, 0 };
s16 D_801120BC_39FF7C_name_5C[6] = { 0, 1, 2, 4, 3, 0 };
s16 D_801120C8_39FF88_name_5C[72] = {
    980, 400, 600, 500, 400, 500, 700, 800, 800, 0, 900, 900, 700, 700, 100, 0, 50, 200, 150, 150,
    150, 150, 150, 150, 0, 100, 100, 100, 0, 50, 200, 150, 150, 0, 0, 150, 150, 50, 200, 150, 200,
    200, 150, 50, 150, 100, 0, 50, 50, 150, 50, 50, 150, 50, 150, 0, 0, 0, 0, 0, 0, 0, 0, 0, 980,
    150, 150, 200, 150, 150, 150, 150,
};
s16 D_80112158_3A0018_name_5C = 0;
s32 D_8011215C_3A001C_name_5C[6] = { 0x90094, 0x90095, 0x90096, 0x90097, 0x90098, 0x90099 };
s16 D_80112174_3A0034_name_5C[7][2] = { { 0x1C, 0x1C }, { 0x44, 0x1C }, { 0x6C, 0x1C }, { 0x1C, 0x44 }, { 0x44, 0x44 }, { 0x6C, 0x44 }, { 0, 0 } };
