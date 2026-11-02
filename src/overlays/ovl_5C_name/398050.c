#include "ovl_5C.h"

__asm__(".section .rodata");
const char D_801122CC_3A018C_name_5C[] = "%d";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/398050", func_8010A190_398050_name_5C);

// register/schedule: the two loads and the subtraction order (masked 2)
#ifdef NON_MATCHING
void func_8010B050_398F10_name_5C(s16* t) {
    s16 end = t[1];
    s16 now = t[0];

    if (now == end - 20) {
        func_80088604_89204(D_80112A00_3A08C0_name_5C, 2, 2, 20);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/398050", func_8010B050_398F10_name_5C);
#endif

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
                kind = D_800CAD94[i].kind;
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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/398050", func_8010B16C_39902C_name_5C);

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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/398050", func_8010BA98_399958_name_5C);

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
            kind = D_800CAD94[i].kind;
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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/398050", func_8010E8CC_39C78C_name_5C);

__asm__(".section .rodata");
const char D_8011231C_3A01DC_name_5C[20] = "c_panel";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/398050", func_8010EE64_39CD24_name_5C);

void func_8010FB28_39D9E8_name_5C(s16 sprite, s16 slot) {
    espPosSet(sprite, D_80112174_3A0034_name_5C[slot][0] + D_80112A04_3A08C4_name_5C.unk_00 - 68.0f,
              D_80112174_3A0034_name_5C[slot][1] + D_80112A04_3A08C4_name_5C.unk_04 - 3.0f);
}

void func_8010FBDC_39DA9C_name_5C(s16 sprite, s16 slot) {
    Ovl5CEsprite* esp = &((Ovl5CEsprite*)D_800F93FC_F9FFC)[slot];

    espPosSet(sprite, esp->x, esp->y);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/398050", func_8010FC20_39DAE0_name_5C);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/398050", func_8010FFDC_39DE9C_name_5C);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/398050", func_80110020_39DEE0_name_5C);
