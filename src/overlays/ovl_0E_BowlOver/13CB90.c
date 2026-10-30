#include "ovl_0E.h"



void func_80102800_13CB90_BowlOver(void) {
    s16 i;
    s16 k;
    s16 spr;

    for (i = 0; i < 4; i++) {
        if (gPlayers[i].group == 0) {
            break;
        }
    }
    switch (i) {
    case 1:
        D_8010A0AE_14443E_BowlOver[0] = 1;
        break;
    case 2:
        D_8010A0AE_14443E_BowlOver[0] = 2;
        break;
    case 3:
        D_8010A0AE_14443E_BowlOver[0] = 3;
        break;
    case 0:
    default:
        D_8010A0AE_14443E_BowlOver[0] = 0;
        break;
    }
    for (i = 1, k = 0; i < 4; i++, k++) {
        if (D_8010A0AE_14443E_BowlOver[0] == k) {
            k++;
        }
        D_8010A0AE_14443E_BowlOver[i] = k;
    }
    func_8002D4D0_2E0D0(5);
    func_8002F290_2FE90(D_800F9D30_FA930, 8);
    func_80020D20_21920(0x20);
    omInitObjMan(0x14, 0);
    func_80079128_79D28();
    func_80105AFC_13FE8C_BowlOver();
    ScissorSet(0, 0.0f, 0.0f, 0.0f, 0.0f);
    ScissorSet(1, 0.0f, 0.0f, 319.0f, 239.0f);
    func_80026DAC_279AC(1, 0xFF, 0xA4, 0x1B);
    func_80026E00_27A00(1, 42.0f, 90.0f, 51.0f);
    D_80101300_101F00 = 0.8f;
    D_8010105C_101C5C = 0.8f;
    func_8000C38C_CF8C();
    func_8000C3C8_CFC8();
    func_8007273C_7333C((u8*)"\x82\x72\x82\x73\x82\x60\x82\x71\x82\x73", 1);
    D_800FA606_FB206 = 0;
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    D_80109A40_143DD0_BowlOver = D_800FA656;
    D_8010A0A8_144438_BowlOver = omAddObj(0xF, 10, 0, -1, func_80105974_13FD04_BowlOver);
    func_8000C018_CC18(D_800F8FE0_F9BE0);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(0xA, 8, 0, -1, func_801070DC_14146C_BowlOver);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(0xA, 4, 0, -1, func_801072F0_141680_BowlOver);
    func_80107390_141720_BowlOver();
    func_801096A0_143A30_BowlOver();
    D_8010A0B8_144448_BowlOver[0] = omAddObj(0x14, 0x1E, 8, -1, func_8010977C_143B0C_BowlOver);
    D_8010A0B8_144448_BowlOver[1] = omAddObj(0x14, 0x1E, 8, -1, func_801097F4_143B84_BowlOver);
    D_8010A0B8_144448_BowlOver[2] = omAddObj(0x14, 0x1E, 8, -1, func_80109870_143C00_BowlOver);
    D_8010A0B8_144448_BowlOver[3] = omAddObj(0x19, 0x14, 8, -1, func_801098EC_143C7C_BowlOver);
    D_8010A0B8_144448_BowlOver[4] = omAddObj(0x19, 0x14, 8, -1, func_80109910_143CA0_BowlOver);
    D_8010A0B8_144448_BowlOver[5] = omAddObj(0x19, 0x14, 8, -1, func_80109934_143CC4_BowlOver);
    omAddObj(0, 0, 0, -1, func_80102E04_13D194_BowlOver);
    omAddObj(0, 0, 0, -1, func_80106450_1407E0_BowlOver);
    D_80109E0C_14419C_BowlOver.x = 0.0f;
    D_80109E0C_14419C_BowlOver.y = 400.0f;
    D_80109E0C_14419C_BowlOver.z = 0.0f;
    D_80109E00_144190_BowlOver.x = 0.0f;
    D_80109E00_144190_BowlOver.y = 885.0f;
    D_80109E00_144190_BowlOver.z = 1580.0f;
    spr = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x1E0019), 0, 1);
    espDispOff(spr);
    func_8007A27C_7AE7C(100, D_800F93FC_F9FFC[spr].unk_04, func_80105EE4_140274_BowlOver, 45.0f,
                        (Vec*)&D_80109E00_144190_BowlOver, (Vec*)&D_80109E0C_14419C_BowlOver);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(0xA, 4, 5, -1, func_801040A0_13E430_BowlOver);
    InitFadeIn(0, 0x10);
    D_8010A0AC_14443C_BowlOver = 2;
    spr = func_8001A2F8_1AEF8(0x1E001B);
    for (i = 0; i < 40; i++) {
        D_80109EF8_144288_BowlOver[i] = func_8001AAAC_1B6AC(spr, 0, 1);
        func_8001A91C_1B51C(D_80109EF8_144288_BowlOver[i], 1.0f, 1.0f);
        func_8001A788_1B388(D_80109EF8_144288_BowlOver[i], 7);
        espPosSet(D_80109EF8_144288_BowlOver[i], i * 8, 0);
        espDispOn(D_80109EF8_144288_BowlOver[i]);
    }
}

/* The game flow (states in D_8010997A_143D0A_BowlOver): 0-2 the intro (the alley camera sweeps in,
   the screen splits, the instructions), 3 a shell is rolling until it and the pins settle, then the
   next shell (5 -> 11, a fade and a reset) or the results: 4/6 the bowler's close-up, 7 coins (all
   three pin players standing: they win 10 each; all three down: the bowler wins 10; otherwise the
   pin players win; +1 coin to the bowler per empty slot's pin down), 8-9 the winners' message and
   jingle, 10/13 fade out and return; 12 a pause in demo play. */
// block layout and register allocation (masked ~80 of 1191): retail places the pin scan's found++ block
// before case 3, fills a different delay slot there, and does not hoist gPlayers in the coin loop
#ifdef NON_MATCHING
void func_80102E04_13D194_BowlOver(omObjData* obj) {
    s16 i;
    s16 h;
    u16 found;
    f32 y;

    func_8000C3C8_CFC8();
    switch (D_8010997A_143D0A_BowlOver) {
    case 0:
        func_8000C38C_CF8C();
        D_80109970_143D00_BowlOver++;
        PlayMusic(0x1B);
        D_8010997A_143D0A_BowlOver += 2;
        break;
    case 1:
        if (func_8008F618_90218() != 0) {
            break;
        }
        ScissorSet(0, 0.0f, 0.0f, 319.0f, 119.0f);
        ScissorSet(1, 0.0f, 121.0f, 319.0f, 239.0f);
        if (func_80069538_6A138() == 0 || (func_80069538_6A138() & 2)) {
            func_800691FC_69DFC(10, 30, 160, 24);
            func_8006D4D0_6E0D0(30);
            func_8000C3B8_CFB8();
            D_80109976_143D06_BowlOver = 0;
            D_80109977_143D07_BowlOver = 0;
        }
        D_80109970_143D00_BowlOver++;
        D_8010997A_143D0A_BowlOver += 2;
        break;
    case 2:
        if (D_80109984_143D14_BowlOver < 30) {
            func_801063D0_140760_BowlOver(1, 1900.0f, 360.5f, 0.0f, 0.0f, 0.0f,
                                          1240.0 - (f32)D_80109984_143D14_BowlOver * (890.0 / 30.0),
                                          (f32)D_80109984_143D14_BowlOver * 150.0 + -5360.0);
        }
        if (D_80109984_143D14_BowlOver == 30) {
            func_801063D0_140760_BowlOver(1, 1900.0f, 360.5f, 0.0f, 0.0f, 0.0f, 350.0f, -860.0f);
        }
        if (D_80109984_143D14_BowlOver == 43) {
            func_800691FC_69DFC(0);
        }
        if (D_80109984_143D14_BowlOver - 30 < 60) {
            h = (D_80109984_143D14_BowlOver - 30) * 2.0;
            ScissorSet(0, 0.0f, 0.0f, 319.0f, h);
            ScissorSet(1, 0.0f, h + 1, 319.0f, 239.0f);
            for (i = 0; i < 40; i++) {
                espPosSet(D_80109EF8_144288_BowlOver[i], i * 8, h + 1);
            }
            y = h + 1;
            if (y < 32.0f) {
                y = 0.0f;
            } else {
                y -= 32.0f;
            }
            for (i = 0; i < 2; i++) {
                espPosSet(D_8010A098_144428_BowlOver[i], 270 - (1 - i) * 24, y + 16.0f + 32.0f);
            }
        }
        if (D_80109984_143D14_BowlOver >= 90) {
            ScissorSet(0, 0.0f, 0.0f, 319.0f, 119.0f);
            ScissorSet(1, 0.0f, 121.0f, 319.0f, 239.0f);
            for (i = 0; i < 40; i++) {
                espPosSet(D_80109EF8_144288_BowlOver[i], i * 8, 119);
            }
            for (i = 0; i < 2; i++) {
                espPosSet(D_8010A098_144428_BowlOver[i], 270 - (1 - i) * 24, 135);
            }
            if (func_80069538_6A138() == 0 || (func_80069538_6A138() & 2)) {
                func_800691FC_69DFC(10, 30, 160, 24);
                func_8006D4D0_6E0D0(30);
                func_8000C3B8_CFB8();
                D_8010997A_143D0A_BowlOver++;
                D_80109976_143D06_BowlOver = 0;
                D_80109977_143D07_BowlOver = 0;
            }
        }
        D_80109984_143D14_BowlOver++;
        break;
    case 3:
        if (D_80109968_143CF8_BowlOver == 1 && D_8010996A_143CFA_BowlOver == 0) {
            ScissorSet(0, 0.0f, 0.0f, 319.0f, 239.0f);
            ScissorSet(1, 0.0f, 0.0f, 0.0f, 0.0f);
            for (i = 0; i < 40; i++) {
                espDispOff(D_80109EF8_144288_BowlOver[i]);
            }
            for (i = 0; i < 2; i++) {
                espDispOff(D_8010A098_144428_BowlOver[i]);
            }
            D_8010996A_143CFA_BowlOver = 1;
        }
        found = 0;
        if (D_80109960_143CF0_BowlOver != 1) {
            break;
        }
        for (i = 0; i < 6; i++) {
            if ((D_80109E50_1441E0_BowlOver[i].unk_17 == 1 && D_80109E50_1441E0_BowlOver[i].unk_18 == 0) ||
                D_80109F48_1442D8_BowlOver[i].unk_1A != 0 || D_80109F48_1442D8_BowlOver[i].unk_14 != 0) {
                found++;
                break;
            }
        }
        if (found != 0) {
            break;
        }
        D_80109975_143D05_BowlOver = 0;
        for (i = 0; i < 3; i++) {
            if (D_80109E50_1441E0_BowlOver[i].unk_17 == 1) {
                D_80109975_143D05_BowlOver++;
            }
        }
        if (D_80109970_143D00_BowlOver >= 2 || D_80109975_143D05_BowlOver >= 3) {
            func_800691FC_69DFC(3);
            func_800794A8_7A0A8(45);
            D_8010997A_143D0A_BowlOver++;
        } else {
            D_8010997A_143D0A_BowlOver = 5;
        }
        break;
    case 4:
        if (func_80069538_6A138() != 0) {
            break;
        }
        func_80079868_7A468();
        func_8000C398_CF98();
        D_8010997A_143D0A_BowlOver = 6;
        break;
    case 5:
        InitFadeOut(0, 20);
        func_8000C398_CF98();
        D_8010997A_143D0A_BowlOver = 11;
        break;
    case 6:
        func_801063D0_140760_BowlOver(0, 1900.0f, 350.5f, 0.0f, 0.0f, D_800FFFD8_100BD8[0]->trans.x, 20.0f, -830.0f);
        D_8010A0AC_14443C_BowlOver = 0;
        func_80029EDC_2AADC(D_800FFFD8_100BD8[0]->model[0], 0);
        func_80029EDC_2AADC(D_800FFFD8_100BD8[0]->model[1], D_8010A0AC_14443C_BowlOver);
        ScissorSet(0, 0.0f, 0.0f, 319.0f, 239.0f);
        ScissorSet(1, 0.0f, 0.0f, 0.0f, 0.0f);
        for (i = 0; i < 40; i++) {
            espDispOff(D_80109EF8_144288_BowlOver[i]);
        }
        for (i = 0; i < 2; i++) {
            espDispOff(D_8010A098_144428_BowlOver[i]);
        }
        Hu3DCamSetPerspective(0, 20.0f, 80.0f, 8000.0f);
        D_800FFFD8_100BD8[0]->rot.y = 0.0f;
        D_80109977_143D07_BowlOver = 1;
        func_80029EDC_2AADC(D_800FFFD8_100BD8[0]->model[0], 0);
        func_80029EDC_2AADC(D_800FFFD8_100BD8[0]->model[2], 1);
        func_80029EDC_2AADC(D_800FFFD8_100BD8[0]->model[3], 1);
        func_80029714_2A314(D_800FFFD8_100BD8[0]->model[2], D_800FFFD8_100BD8[0]->trans.x,
                            D_800FFFD8_100BD8[0]->trans.y, D_800FFFD8_100BD8[0]->trans.z);
        func_80029714_2A314(D_800FFFD8_100BD8[0]->model[3], D_800FFFD8_100BD8[0]->trans.x,
                            D_800FFFD8_100BD8[0]->trans.y, D_800FFFD8_100BD8[0]->trans.z);
        func_80029B80_2A780(D_800FFFD8_100BD8[0]->model[2], D_800FFFD8_100BD8[0]->motion[4]);
        D_8010997A_143D0A_BowlOver++;
        break;
    case 7:
        if (D_8010996C_143CFC_BowlOver == 1 || D_80109975_143D05_BowlOver == 0) {
            D_80109979_143D09_BowlOver = 0;
            for (i = 0; i < 3; i++) {
                gPlayers[D_8010A0AE_14443E_BowlOver[i + 1]].coins_mg_bonus += 10;
            }
        } else if (D_80109975_143D05_BowlOver >= 3) {
            D_80109979_143D09_BowlOver = 1;
            gPlayers[D_8010A0AE_14443E_BowlOver[0]].coins_mg_bonus += 10;
        } else {
            D_80109979_143D09_BowlOver = 2;
            for (i = 0; i < 3; i++) {
                gPlayers[D_8010A0AE_14443E_BowlOver[i + 1]].coins_mg_bonus += 10;
            }
        }
        for (i = 0; i < 3; i++) {
            if (D_80109E50_1441E0_BowlOver[i + 3].unk_17 == 1) {
                gPlayers[D_8010A0AE_14443E_BowlOver[0]].coins_mg++;
            }
        }
        if (_CheckFlag(0xC) != 0) {
            D_8010997A_143D0A_BowlOver = 12;
            D_80109E18_1441A8_BowlOver = 60;
            break;
        }
        D_8010997A_143D0A_BowlOver++;
        break;
    case 8:
        if (func_80069538_6A138() != 0 && !(func_80069538_6A138() & 2)) {
            break;
        }
        switch (D_80109979_143D09_BowlOver) {
        case 1:
            func_80029B80_2A780(D_800FFFD8_100BD8[0]->model[2], D_800FFFD8_100BD8[0]->motion[1]);
            func_800732B0_73EB0(D_800CD438_CE038[gPlayers[D_8010A0AE_14443E_BowlOver[0]].character].unk_04 | 0x4E);
            D_8010997C_143D0C_BowlOver = 120;
            func_800691FC_69DFC(6, gPlayers[D_8010A0AE_14443E_BowlOver[0]].character);
            PlayMusic(0x51);
            break;
        case 0:
        case 2:
            func_80029B80_2A780(D_800FFFD8_100BD8[0]->model[2], D_800FFFD8_100BD8[0]->motion[0]);
            func_800732B0_73EB0(D_800CD438_CE038[gPlayers[D_8010A0AE_14443E_BowlOver[0]].character].unk_04 | 0x55);
            D_8010997C_143D0C_BowlOver = 168;
            func_800691FC_69DFC(21, gPlayers[D_8010A0AE_14443E_BowlOver[1]].character,
                                gPlayers[D_8010A0AE_14443E_BowlOver[2]].character,
                                gPlayers[D_8010A0AE_14443E_BowlOver[3]].character);
            PlayMusic(0x52);
            break;
        }
        D_80109980_143D10_BowlOver = 0;
        D_8010997A_143D0A_BowlOver++;
        break;
    case 9:
        if (D_8010997C_143D0C_BowlOver < D_80109980_143D10_BowlOver++) {
            func_8000C3A8_CFA8();
            D_8010997A_143D0A_BowlOver++;
        }
        break;
    case 10:
        if (D_80109978_143D08_BowlOver == 0) {
            InitFadeOut(0, 20);
            func_800794A8_7A0A8(40);
            D_80109978_143D08_BowlOver = 1;
        } else if (func_8008F618_90218() == 0) {
            func_80069770_6A370();
            omOvlReturnEx(1);
        }
        break;
    case 11:
        if (func_8008F618_90218() != 0) {
            break;
        }
        D_80109964_143CF4_BowlOver = 0;
        D_8010A0AC_14443C_BowlOver = 2;
        D_80109968_143CF8_BowlOver = 0;
        D_8010996A_143CFA_BowlOver = 0;
        D_8010996C_143CFC_BowlOver = 0;
        D_8010996E_143CFE_BowlOver = 0;
        D_80109A50_143DE0_BowlOver = 0;
        D_80109974_143D04_BowlOver = 0;
        D_80109975_143D05_BowlOver = 0;
        D_80109976_143D06_BowlOver = 0;
        D_80109977_143D07_BowlOver = 0;
        D_80109978_143D08_BowlOver = 0;
        D_80109979_143D09_BowlOver = 0;
        D_8010997A_143D0A_BowlOver = 0;
        D_8010997C_143D0C_BowlOver = 0;
        D_80109980_143D10_BowlOver = 0;
        D_80109984_143D14_BowlOver = 0;
        func_80107570_141900_BowlOver();
        for (i = 0; i < 3; i++) {
            func_80108DCC_14315C_BowlOver(D_8010A0B8_144448_BowlOver[i]);
        }
        for (i = 3; i < 6; i++) {
            func_80109354_1436E4_BowlOver(D_8010A0B8_144448_BowlOver[i]);
        }
        D_80109971_143D01_BowlOver = 1;
        D_80109972_143D02_BowlOver = 1;
        D_80109973_143D03_BowlOver = 1;
        D_80109960_143CF0_BowlOver = 0;
        func_801063D0_140760_BowlOver(0, 939.0f, 326.0f, 0.0f, 0.0f, 0.0f, -86.8f, -4828.6f);
        func_801063D0_140760_BowlOver(1, 1900.0f, 360.5f, 0.0f, 0.0f, 0.0f, 350.0f, -860.0f);
        ScissorSet(0, 0.0f, 0.0f, 319.0f, 119.0f);
        ScissorSet(1, 0.0f, 121.0f, 319.0f, 239.0f);
        for (i = 0; i < 40; i++) {
            espDispOn(D_80109EF8_144288_BowlOver[i]);
        }
        for (i = 0; i < 2; i++) {
            espDispOn(D_8010A098_144428_BowlOver[i]);
        }
        InitFadeIn(0, 16);
        func_8000C38C_CF8C();
        D_8010997A_143D0A_BowlOver = 1;
        break;
    case 12:
        if ((s16)D_80109E18_1441A8_BowlOver-- < 0) {
            D_8010997A_143D0A_BowlOver++;
        }
        break;
    case 13:
        if (D_80109978_143D08_BowlOver == 0) {
            InitFadeOut(0, 20);
            func_800794A8_7A0A8(40);
            D_80109978_143D08_BowlOver = 1;
        } else if (func_8008F618_90218() == 0) {
            func_80069770_6A370();
            omOvlReturnEx(1);
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/13CB90", func_80102E04_13D194_BowlOver);
#endif

void func_801040A0_13E430_BowlOver(omObjData* obj) {
    f32 x;
    u8 chr;
    s32 dir;
    s32 file;
    s32 file2;

    x = 0.0f;
    chr = gPlayers[D_8010A0AE_14443E_BowlOver[0]].character;
    dir = D_800CD438_CE038[chr].unk_04;
    file = D_800CD438_CE038[chr].unk_08;
    file2 = D_800CD438_CE038[chr].unk_10;
    switch (D_80109A40_143DD0_BowlOver) {
    case 0:
        x = 35.0f;
        break;
    case 1:
        x = -200.0f;
        break;
    case 2:
        x = -235.0f;
        break;
    }
    func_80104D78_13F108_BowlOver(obj, dir, file, file2, D_8010A0AE_14443E_BowlOver[0], x, 0.0f, 300.0f);
    D_8010A09C_14442C_BowlOver.x = x;
    D_8010A09C_14442C_BowlOver.y = 0.0f;
    D_8010A09C_14442C_BowlOver.z = 300.0f;
}

void func_801041CC_13E55C_BowlOver(omObjData* obj) {
    f32 s;

    s = 0.0f;
    switch ((u16)(D_800CD438_CE038[gPlayers[D_8010A0AE_14443E_BowlOver[0]].character].unk_04 >> 16)) {
    case 3:
    case 6:
        s = 0.6f;
        break;
    case 2:
    case 4:
    case 5:
    case 7:
        s = 0.5f;
        break;
    }
    func_800297E8_2A3E8(obj->model[1], s * 4.0f, 1.0f, s * 4.0f);
    func_800297E8_2A3E8(obj->model[3], s * 4.0f, 1.0f, s * 4.0f);
    func_80029714_2A314(obj->model[1], obj->trans.x, 2.0f, obj->trans.z);
    func_80029714_2A314(obj->model[3], obj->trans.x, 2.0f, obj->trans.z);
}

const f32 D_80109B58_143EE8_BowlOver[3][2] = { { -100.0f, 130.0f }, { -200.0f, -80.0f }, { -250.0f, -120.0f } };

void func_801042F0_13E680_BowlOver(omObjData* obj) {
    u8 port;
    f32 lim;

    if (D_80109971_143D01_BowlOver == 1) {
        D_80109988_143D18_BowlOver = 929;
        D_8010998C_143D1C_BowlOver = 0;
        D_80109990_143D20_BowlOver = 0;
        D_80109992_143D22_BowlOver = 0;
        D_80109994_143D24_BowlOver = 0;
        D_80109996_143D26_BowlOver = 0;
        D_80109997_143D27_BowlOver = 0;
        D_80109998_143D28_BowlOver = 1;
        D_80109971_143D01_BowlOver = 0;
        obj->trans.x = D_8010A09C_14442C_BowlOver.x;
        obj->trans.y = D_8010A09C_14442C_BowlOver.y;
        obj->trans.z = D_8010A09C_14442C_BowlOver.z;
        D_8010A0A8_144438_BowlOver->trans.x = D_8010A09C_14442C_BowlOver.x;
        D_8010A0A8_144438_BowlOver->trans.y = D_8010A09C_14442C_BowlOver.y;
        D_8010A0A8_144438_BowlOver->trans.z = D_8010A09C_14442C_BowlOver.z;
        func_80029B80_2A780(obj->model[0], obj->motion[2]);
        func_80029E80_2AA80(obj->model[0], 1, 1);
    }
    if (D_80109992_143D22_BowlOver == 0) {
        func_80106648_1409D8_BowlOver(obj, D_8010A0A8_144438_BowlOver);
        D_80109992_143D22_BowlOver = 1;
    }
    func_801041CC_13E55C_BowlOver(obj);
    func_80029EDC_2AADC(D_800FFFD8_100BD8[0]->model[0], D_8010A0AC_14443C_BowlOver);
    func_80029EDC_2AADC(D_800FFFD8_100BD8[0]->model[1], D_8010A0AC_14443C_BowlOver);
    if (D_800F8FD0_F9BD0 != 1) {
        return;
    }
    if (D_801013B0_101FB0[1].z < -1900.0f) {
        func_80029EDC_2AADC(obj->model[0], 0);
        func_80029EDC_2AADC(obj->model[1], 0);
    }
    port = BO_WORK(obj)->unk_57;
    switch (D_8010998C_143D1C_BowlOver) {
    case 0:
        func_8006D4D0_6E0D0(D_80109988_143D18_BowlOver / 30);
        if (D_80109988_143D18_BowlOver > 0) {
            D_80109988_143D18_BowlOver--;
        }
        if (ContStkX[(s8)port] > 50) {
            obj->trans.x += 5.0f;
            lim = D_80109B58_143EE8_BowlOver[D_80109A40_143DD0_BowlOver][1];
            if (lim < obj->trans.x) {
                obj->trans.x = lim;
            }
            D_80109E1A_1441AA_BowlOver = 1;
            D_80109994_143D24_BowlOver = 1;
        } else if (ContStkX[(s8)port] < -50) {
            obj->trans.x -= 5.0f;
            lim = D_80109B58_143EE8_BowlOver[D_80109A40_143DD0_BowlOver][0];
            if (obj->trans.x < lim) {
                obj->trans.x = lim;
            }
            D_80109E1A_1441AA_BowlOver = 0;
            D_80109994_143D24_BowlOver = 1;
        } else {
            D_80109994_143D24_BowlOver = 0;
        }
        if (D_80109994_143D24_BowlOver == 0) {
            if (D_80109996_143D26_BowlOver == 0) {
                func_80029B80_2A780(obj->model[0], obj->motion[2]);
                func_80029E80_2AA80(obj->model[0], 1, 1);
                D_80109996_143D26_BowlOver = 1;
                D_80109997_143D27_BowlOver = 0;
            }
        } else if (D_80109997_143D27_BowlOver == 0) {
            func_80029B80_2A780(obj->model[0], obj->motion[2]);
            if (D_80109E1A_1441AA_BowlOver == 0) {
                func_80029E80_2AA80(obj->model[0], 2, 2);
            } else {
                func_80029E80_2AA80(obj->model[0], 6, 6);
            }
            D_80109996_143D26_BowlOver = 0;
            D_80109997_143D27_BowlOver = 1;
        }
        if ((ContBtnTrg[(s8)port] & 0x8000) || D_80109988_143D18_BowlOver == 0) {
            func_80029B80_2A780(obj->model[0], obj->motion[3]);
            D_8010998C_143D1C_BowlOver++;
            D_80109990_143D20_BowlOver = 0;
            func_8006D518_6E118();
        }
        func_8003B6E8_3C2E8(D_800FC834_FD434[obj->model[0]].hmf);
        break;
    case 1:
        if (D_80109998_143D28_BowlOver == 1) {
            obj->trans.z -= 6.0f;
            func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
        } else {
            D_8010998C_143D1C_BowlOver++;
        }
        if ((s16)D_80109990_143D20_BowlOver++ == 0x37) {
            D_80109998_143D28_BowlOver = 0;
            D_80109A41_143DD1_BowlOver--;
            func_8010655C_1408EC_BowlOver(obj, obj->trans.x + 100.0f, obj->trans.y + 50.0f, obj->trans.z - 10.0f);
            func_80079798_7A398(0x17D, D_8010A0AE_14443E_BowlOver[0]);
        }
        break;
    }
}

// register allocation: port and the pin table base swap t1/t2 (masked 0)
#ifdef NON_MATCHING
void func_8010487C_13EC0C_BowlOver(omObjData* obj) {
    BOPlayerWork* w;
    u8 port;
    u16 btn;
    s16 i;
    f32 sum;
    f32 n;

    w = BO_WORK(obj);
    port = w->unk_57;
    if (D_80109972_143D02_BowlOver == 1) {
        D_8010999A_143D2A_BowlOver = 0;
        D_8010999C_143D2C_BowlOver = 0;
        D_801099A0_143D30_BowlOver = 0;
        D_801099A4_143D34_BowlOver = -1.0f;
        D_80109E1C_1441AC_BowlOver = 0.0f;
        D_80109972_143D02_BowlOver = 0;
    }
    if (gPlayers[w->unk_59].flags & 1) {
        if (D_8010999A_143D2A_BowlOver == 0) {
            switch (gPlayers[w->unk_59].cpu_difficulty) {
            case 0:
                D_80109E1C_1441AC_BowlOver = 0.0f;
                break;
            case 1:
                D_80109E1C_1441AC_BowlOver = 5.0f;
                break;
            case 2:
                D_80109E1C_1441AC_BowlOver = 10.0f;
                break;
            case 3:
                D_80109E1C_1441AC_BowlOver = 15.0f;
                break;
            }
            D_8010999A_143D2A_BowlOver = 1;
        }
        sum = 0.0f;
        n = 0.0f;
        for (i = 0; i < 3; i++) {
            if ((D_80109E50_1441E0_BowlOver + D_8010A0B8_144448_BowlOver[i]->work[3])->unk_17 != 1) {
                sum += D_8010A0B8_144448_BowlOver[i]->trans.x;
                n += 1.0f;
            } else if ((D_80109E50_1441E0_BowlOver + D_8010A0B8_144448_BowlOver[i + 3]->work[3])->unk_17 != 1) {
                sum += D_8010A0B8_144448_BowlOver[i + 3]->trans.x;
                n += 1.0f;
            }
        }
        if (n != 0.0f) {
            sum = sum / n;
        } else {
            sum = 0.0f;
        }
        btn = 0;
        if (D_801099A0_143D30_BowlOver == 0x6E) {
            btn = 0x8000;
        }
        D_801099A4_143D34_BowlOver = -1.0f;
        switch (D_80109A40_143DD0_BowlOver) {
        case 0:
            if (D_801099A0_143D30_BowlOver == 0xFB) {
                D_801099A4_143D34_BowlOver = -10.0f;
            }
            if (D_801099A0_143D30_BowlOver >= 0x123) {
                if (D_8010A0A8_144438_BowlOver->trans.x < sum) {
                    D_801099A4_143D34_BowlOver = D_80109E1C_1441AC_BowlOver + 35.0f;
                } else {
                    D_801099A4_143D34_BowlOver = -35.0f - D_80109E1C_1441AC_BowlOver;
                }
            }
            break;
        case 1:
            if (D_801099A0_143D30_BowlOver >= 0x12D && D_801099A0_143D30_BowlOver < 0x135) {
                D_801099A4_143D34_BowlOver = 12.0f;
            }
            if (D_801099A0_143D30_BowlOver >= 0x123) {
                if (D_8010A0A8_144438_BowlOver->trans.x < sum) {
                    D_801099A4_143D34_BowlOver = D_80109E1C_1441AC_BowlOver + 35.0f;
                } else {
                    D_801099A4_143D34_BowlOver = -35.0f - D_80109E1C_1441AC_BowlOver;
                }
            }
            break;
        case 2:
            if (D_801099A0_143D30_BowlOver >= 0xC9 && D_801099A0_143D30_BowlOver < 0xD6) {
                D_801099A4_143D34_BowlOver = 40.0f;
            }
            if (D_801099A0_143D30_BowlOver >= 0x105 && D_801099A0_143D30_BowlOver < 0x115) {
                D_801099A4_143D34_BowlOver = -40.0f;
            }
            if (D_801099A0_143D30_BowlOver >= 0x123) {
                if (D_8010A0A8_144438_BowlOver->trans.x < sum) {
                    D_801099A4_143D34_BowlOver = D_80109E1C_1441AC_BowlOver + 35.0f;
                } else {
                    D_801099A4_143D34_BowlOver = -35.0f - D_80109E1C_1441AC_BowlOver;
                }
            }
            break;
        }
        if (ContBtn[(s8)port] & 0x1000) {
            btn |= 0x1000;
        }
        ContBtnTrg[(s8)port] = ContBtn[(s8)port] = btn;
        ContBtnTrg[(s8)port] = btn & (btn ^ D_8010999C_143D2C_BowlOver);
        D_8010999C_143D2C_BowlOver = btn;
        if (D_801099A4_143D34_BowlOver == -1.0f) {
            ContStkX[(s8)port] = 0;
            ContStkY[(s8)port] = 0;
        } else {
            ContStkX[(s8)port] = D_801099A4_143D34_BowlOver;
            ContStkY[(s8)port] = 0;
        }
    }
    D_801099A0_143D30_BowlOver++;
    func_801042F0_13E680_BowlOver(obj);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/13CB90", func_8010487C_13EC0C_BowlOver);
#endif

void func_80104D78_13F108_BowlOver(omObjData* obj, s32 dir, s32 file, s32 file2, u16 player, f32 x, f32 y, f32 z) {
    BOPlayerWork* w;
    u32 chr;

    obj->unk_50 = func_80027154_27D54(sizeof(BOPlayerWork), 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, sizeof(BOPlayerWork));
    w = BO_WORK(obj);
    w->unk_E8 = func_80027154_27D54(obj->mtncnt * 0xC, 0x7918);
    w->unk_57 = gPlayers[player].port;
    obj->model[0] = LoadFormFile(dir | file, 0x6B9);
    obj->model[1] = LoadFormFile(1, 0x6B9);
    obj->model[2] = LoadFormFile(dir | file2, 0x6B9);
    obj->model[3] = func_80027D3C_2893C(obj->model[1]);
    func_80018CCC_198CC(obj, 0, dir | 0x55);
    func_80018CCC_198CC(obj, 1, dir | 0x4E);
    func_80018CCC_198CC(obj, 2, dir | 0x36);
    func_80018CCC_198CC(obj, 3, dir | 0x34);
    func_80018CCC_198CC(obj, 4, dir);
    func_8002D1EC_2DDEC(obj->model[0], 1);
    func_8002D274_2DE74(obj->model[0], 0xFF, 0xA4, 0x1B);
    chr = (u32)dir >> 16;
    func_8002D2B4_2DEB4(obj->model[0], 42.0f, 90.0f, 51.0f);
    func_8002D1EC_2DDEC(obj->model[2], 1);
    func_8002D274_2DE74(obj->model[2], 0xFF, 0xA4, 0x1B);
    func_8002D2B4_2DEB4(obj->model[2], 42.0f, 90.0f, 51.0f);
    func_80029EDC_2AADC(obj->model[0], 2);
    func_80029EDC_2AADC(obj->model[2], 0);
    func_80029EDC_2AADC(obj->model[3], 0);
    func_8000C35C_CF5C(obj, x, y, z);
    func_80029714_2A314(obj->model[0], x, y, z);
    func_8000C36C_CF6C(obj, 0.0f, 180.0f, 0.0f);
    obj->scale.x = 1.5f;
    obj->scale.y = 1.5f;
    obj->scale.z = 1.5f;
    func_80029714_2A314(obj->model[2], x, y, z);
    func_800297E8_2A3E8(obj->model[2], 1.5f, 1.5f, 1.5f);
    func_800297E8_2A3E8(obj->model[1], 4.0f, 1.0f, 4.0f);
    obj->func_ptr = func_8010487C_13EC0C_BowlOver;
    w->unk_52 = 0;
    w->unk_B4 = 1.0f;
    w->unk_D0 = 0xFFFF;
    w->unk_38 = 1000.0f;
    w->unk_50 = 0;
    func_8000BEB0_CAB0(obj, 60.0f);
    func_8000BEBC_CABC(obj, 150.0f);
    func_8000BEC8_CAC8(obj, 20.0f);
    func_8000C024_CC24(obj, 0, 2);
    switch (chr) {
    case 6:
        w->unk_AC = 0.7f;
        break;
    case 4:
        w->unk_AC = 0.9f;
        break;
    case 5:
        w->unk_AC = 0.8f;
        break;
    default:
        w->unk_AC = 1.0f;
        break;
    }
    w->unk_59 = player;
    func_80029B80_2A780(obj->model[0], obj->motion[2]);
    func_80029E80_2AA80(obj->model[0], 1, 1);
    func_80029B80_2A780(obj->model[2], obj->motion[2]);
    func_80029E80_2AA80(obj->model[2], 1, 1);
}

void func_801051B4_13F544_BowlOver(omObjData* obj) {
    BOBallWork* w;
    f32 turn;
    f32 sc;
    s8 vol;
    s16 pitch;
    s16 snd;
    u8 v;
    s8 a;

    w = BO_BALL_WORK(obj);
    if (D_80109973_143D03_BowlOver == 1) {
        D_801099A8_143D38_BowlOver = 0;
        D_801099AC_143D3C_BowlOver = 2.0f;
        D_801099B0_143D40_BowlOver = 0.0f;
        D_801099B4_143D44_BowlOver = 0.0f;
        D_801099B8_143D48_BowlOver = 0.0f;
        D_801099BC_143D4C_BowlOver = 0.0f;
        D_80109E20_1441B0_BowlOver[0] = 0;
        D_80109E20_1441B0_BowlOver[1] = 0;
        D_801099C0_143D50_BowlOver = 0;
        D_801099C1_143D51_BowlOver = 0;
        D_8010A0A8_144438_BowlOver->trans.x = 0.0f;
        D_8010A0A8_144438_BowlOver->trans.y = 0.0f;
        D_8010A0A8_144438_BowlOver->trans.z = 0.0f;
        func_80029714_2A314(D_8010A0A8_144438_BowlOver->model[0], D_8010A0A8_144438_BowlOver->trans.x,
                            D_8010A0A8_144438_BowlOver->trans.y, D_8010A0A8_144438_BowlOver->trans.z);
        func_80029EDC_2AADC(D_8010A0A8_144438_BowlOver->model[1], 0);
        D_80109973_143D03_BowlOver = 0;
    }
    if (D_800F8FD0_F9BD0 != 1) {
        return;
    }
    if (w->unk_50 & 0x10) {
        return;
    }
    func_80029714_2A314(obj->model[1], obj->trans.x, 0.0f, obj->trans.z);
    if (obj->trans.z > -5550.0f) {
        if (D_8010996C_143CFC_BowlOver == 0) {
            if (obj->trans.y <= -5.0f) {
                obj->trans.y = -5.0f;
                if (D_801099C1_143D51_BowlOver == 0) {
                    D_80109E20_1441B0_BowlOver[0] = func_80079798_7A398(0x17E, D_8010A0AE_14443E_BowlOver[0]);
                    D_80109E20_1441B0_BowlOver[1] = snd = PlaySound(0x17F);
                    func_800795D8_7A1D8(snd, 0);
                    D_801099C1_143D51_BowlOver = 1;
                    func_800297E8_2A3E8(obj->model[1], 1.0f, 1.0f, 0.3f);
                }
            } else {
                obj->trans.y -= D_801099AC_143D3C_BowlOver;
                D_801099AC_143D3C_BowlOver *= 1.2f;
                sc = (obj->trans.y + 5.0f) / 30.0f + 1.0f;
                if ((obj->trans.y + 5.0f) / 30.0f + 1.0f <= 0.0f) {
                    sc = 1.0f;
                }
                func_800297E8_2A3E8(obj->model[1], 1.0f / sc, 1.0f / sc, 0.3f / sc);
                func_80029EDC_2AADC(D_8010A0A8_144438_BowlOver->model[1], 3);
            }
        }
        if (D_8010996C_143CFC_BowlOver == 0) {
            D_801099B8_143D48_BowlOver = 31.25f;
        } else {
            D_801099B8_143D48_BowlOver = 0.0f;
        }
        D_801099B0_143D40_BowlOver = ContStkX[(s8)BO_WORK(D_800FFFD8_100BD8[0])->unk_57] * 1.6;
        D_801099BC_143D4C_BowlOver -= D_801099B0_143D40_BowlOver;
        turn = D_801099BC_143D4C_BowlOver / 9.0f;
        if (!(BO_ABS(turn) < 263.0f)) {
            turn = 263.0f;
        }
        obj->rot.y = turn + obj->rot.y;
        if (D_8010996C_143CFC_BowlOver == 0) {
            D_801099B4_143D44_BowlOver -= D_801099BC_143D4C_BowlOver / 1700.0f;
        }
        D_801099BC_143D4C_BowlOver *= 0.9;
        vol = BO_ABS((turn / 263.0f) * 200.0f);
        if (vol > 0x5E) {
            vol = 0x5E;
        }
        pitch = BO_ABS(turn / 120.0f) * 400.0f;
        if (pitch > 400) {
            pitch = 400;
        }
        if (D_801099C0_143D50_BowlOver == 0) {
            if (D_80109968_143CF8_BowlOver == 1) {
                v = D_801099A8_143D38_BowlOver;
                D_801099A8_143D38_BowlOver = v - 2;
                a = v + 0x7D;
                if (a < 0) {
                    a = 0;
                }
                vol += D_801099A8_143D38_BowlOver;
                if (vol < 0) {
                    vol = 0;
                }
                func_800795D8_7A1D8(D_80109E20_1441B0_BowlOver[0], a);
                func_800795D8_7A1D8(D_80109E20_1441B0_BowlOver[1], vol);
            } else {
                func_800795D8_7A1D8(D_80109E20_1441B0_BowlOver[1], vol);
            }
            func_800796F0_7A2F0(D_80109E20_1441B0_BowlOver[1], pitch);
        }
        if (D_80109960_143CF0_BowlOver == 0) {
            D_801099B8_143D48_BowlOver *= 0.95;
            obj->trans.z -= D_801099B8_143D48_BowlOver;
        }
        if (func_801069D0_140D60_BowlOver(obj, &D_801099B4_143D44_BowlOver, &D_801099B8_143D48_BowlOver) == 1) {
            D_801099BC_143D4C_BowlOver = 0.0f;
        }
        if (D_80109960_143CF0_BowlOver == 0) {
            obj->trans.x += D_801099B4_143D44_BowlOver;
        }
        if (D_8010996C_143CFC_BowlOver == 0) {
            D_801013B0_101FB0[1].z -= D_801099B8_143D48_BowlOver;
            D_801013B0_101FB0[1].x += D_801099B4_143D44_BowlOver;
            if (D_80109968_143CF8_BowlOver == 0 && obj->trans.z < -4300.0f) {
                D_80109968_143CF8_BowlOver = 1;
            }
        } else {
            func_80029EDC_2AADC(D_8010A0A8_144438_BowlOver->model[1], 0);
            obj->trans.y -= 20.0f;
            if (obj->trans.y < -500.0f) {
                if (D_801099C0_143D50_BowlOver == 0) {
                    func_80079848_7A448(D_80109E20_1441B0_BowlOver[0]);
                    func_80079848_7A448(D_80109E20_1441B0_BowlOver[1]);
                    D_801099C0_143D50_BowlOver = 1;
                }
                D_80109960_143CF0_BowlOver = 1;
            }
        }
    } else {
        func_80029EDC_2AADC(D_8010A0A8_144438_BowlOver->model[1], 0);
        D_801099B8_143D48_BowlOver = 25.0f;
        obj->trans.y -= 20.0f;
        if (obj->trans.y < -500.0f) {
            if (D_801099C0_143D50_BowlOver == 0) {
                func_80079848_7A448(D_80109E20_1441B0_BowlOver[0]);
                func_80079848_7A448(D_80109E20_1441B0_BowlOver[1]);
                D_801099C0_143D50_BowlOver = 1;
            }
            D_80109960_143CF0_BowlOver = 1;
        }
    }
}

void func_80105974_13FD04_BowlOver(omObjData* obj) {
    BOBallWork* w;

    obj->unk_50 = w = func_80027154_27D54(sizeof(BOBallWork), 0x7918);
    func_800B0EF0_B1AF0(w, 0, sizeof(BOBallWork));
    obj->model[0] = func_80018A64_19664(5, 0x6B9);
    obj->model[1] = func_80018A64_19664(0x1E0001, 0x6B9);
    func_8002D1EC_2DDEC(obj->model[0], 1);
    func_8002D274_2DE74(obj->model[0], 0xFF, 0xA4, 0x1B);
    func_8002D2B4_2DEB4(obj->model[0], 42.0f, 90.0f, 51.0f);
    w->unk_7C = 0;
    w->unk_54 = 1;
    w->unk_44 = 0.1f;
    w->unk_48 = 30.0f;
    w->unk_34 = 50.0f;
    w->unk_3C = 0.0f;
    w->unk_78 = 0;
    w->unk_38 = 1000.0f;
    w->unk_52 = 3;
    w->unk_74 = 0.5f;
    w->unk_50 = 0x20;
    obj->trans.x = 0.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 0.0f;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80029EDC_2AADC(obj->model[1], 0);
    func_800297E8_2A3E8(obj->model[1], 0.0f, 0.0f, 0.0f);
    obj->func_ptr = func_801051B4_13F544_BowlOver;
}

void func_80105AFC_13FE8C_BowlOver(void) {
    omObjData* obj;
    s16 i;

    func_80020070_20C70(2);
    obj = omAddObj(0x7FDA, 0, 0, -1, func_80105D14_1400A4_BowlOver);
    omSetStatBit(obj, 0xA0);
    for (i = 0; i < 2; i++) {
        Hu3DCamSetPerspective(i, 53.0f, 80.0f, 8000.0f);
        CameraViewportSet(i, &D_801099C4_143D54_BowlOver[i], &D_801099DC_143D6C_BowlOver[i]);
        CameraScissorSet(i, &D_801099F4_143D84_BowlOver[i]);
    }
    func_801063D0_140760_BowlOver(0, 939.0f, 326.0f, 0.0f, 0.0f, 0.0f, -86.8f, -4828.6f);
    func_801063D0_140760_BowlOver(1, 1900.0f, 360.5f, 0.0f, 0.0f, 0.0f, 350.0f, -860.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    ViewportSet(1, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_80105D14_1400A4_BowlOver(obj);
}

void func_80105D14_1400A4_BowlOver(omObjData* obj) {
    Vec eye;
    Vec at;
    Vec up;
    f32 rx;
    f32 ry;
    s16 i;

    for (i = 0; i < 2; i++) {
        rx = D_80102770_103370[i].x;
        ry = D_80102770_103370[i].y;
        eye.x = HuMathSin(ry) * func_800B7890_B8490(rx) * D_800F94A8_FA0A8[i] + D_801013B0_101FB0[i].x;
        eye.y = -HuMathSin(rx) * D_800F94A8_FA0A8[i] + D_801013B0_101FB0[i].y;
        eye.z = func_800B7890_B8490(ry) * func_800B7890_B8490(rx) * D_800F94A8_FA0A8[i] + D_801013B0_101FB0[i].z;
        at.x = D_801013B0_101FB0[i].x;
        at.y = D_801013B0_101FB0[i].y;
        at.z = D_801013B0_101FB0[i].z;
        up.x = HuMathSin(ry) * HuMathSin(rx);
        up.y = func_800B7890_B8490(rx);
        up.z = func_800B7890_B8490(ry) * HuMathSin(rx);
        Hu3DCamSetPositionOrientation(i, &eye, &at, &up);
        Hu3DCamUpdateMtx(i);
    }
}

void func_80105EE4_140274_BowlOver(s16* sprId) {
    HuSprite* spr;
    u16 w, h, rows;
    s16 top, bottom;
    f32 x0, y0, x1, y1;
    f32 step, next;
    s32 s;

    spr = func_80082550_83150(*sprId, 0);
    w = spr->unk_84->unk14;
    h = spr->unk_84->unk16;
    gDPSetTextureLUT(D_800FDBCC_FE7CC++, G_TT_RGBA16);
    gDPLoadTLUT_pal256(D_800FDBCC_FE7CC++, spr->unk_84->unk0C);
    top = 0;
    bottom = 239;
    gDPSetScissor(D_800FDBCC_FE7CC++, G_SC_NON_INTERLACE, 0, top, 319, bottom);
    x0 = 0.0f;
    y0 = 0.0f;
    rows = 0x800 / w - 1;
    x1 = 318.0f;
    y1 = 238.0f;
    step = ((y1 - y0) < 0.0 ? -(y1 - y0) : (y1 - y0)) / (u16)(h / rows);
    for (s = 0; s < h - 1; s += rows) {
        next = y0 + step;
        if (s + rows >= h - 1) {
            rows = h - s - 1;
        }
        if (top <= next) {
            if (y1 < next) {
                step = y1 - y0;
            }
            gDPLoadTextureTile(D_800FDBCC_FE7CC++, spr->unk_84->unk08, G_IM_FMT_CI, G_IM_SIZ_8b, w, h, 0, s, w,
                               s + rows, 0, 0, 0, 0, 0, 0, 0);
            gSPScisTextureRectangle(D_800FDBCC_FE7CC++, (s32)(x0 * 4.0f), (s32)(y0 * 4.0f), (s32)(x1 * 4.0f),
                                    (s32)((y0 + step) * 4.0f), G_TX_RENDERTILE, 0, s << 5, 0x400, 0x400);
        }
        y0 += step;
        if (bottom <= y0) {
            break;
        }
    }
}
