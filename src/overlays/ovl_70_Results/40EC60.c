#include "ovl_70.h"
#include "game/pad.h"

void func_80102800_40EC60_Results(void) {
    omInitObjMan(0x14, 0x14);
    func_8010492C_410D8C_Results();
    func_80104278_4106D8_Results();
    func_80104B90_410FF0_Results();
    func_80104D3C_41119C_Results();
    omAddPrcObj(&func_80103DB4_410214_Results, 0x300U, 0x3000, 0);
    PlayMusic(0x14);
    omAddObj(5, 0U, 0U, -1, &func_801041C8_410628_Results);
    omAddObj(5, 0U, 0U, -1, &func_801028A0_40ED00_Results);
}

void func_801028A0_40ED00_Results(void) {
    s8 i;

    if (D_801076A2_413B02_Results != 1) {
        for (i = 0; i < 4; i++) {
            if (!(gPlayers[i].flags & 1)) {
                if (ContBtn[gPlayers[i].port] & (A_BUTTON | START_BUTTON)) {
                    D_801076A1_413B01_Results = 1;
                }
            }
        }
    }
}

//related to creating(?) and moving the player sprites
__asm__(".section .rodata");
const char D_80107800_413C60_Results[] = "RESULTS";

// register allocation of the title string index (masked 2)
#ifdef NON_MATCHING
/* Builds the results table: title, place sprites, characters, coin icons, coin and star counts. */
void func_80102944_40EDA4_Results(void) {
    char buf[16];
    s16 coins[4];
    s8 digits[4][3];
    s8 nd[4];
    s32 i;
    s32 j;
    s32 n;
    s32 str;
    void* file;

    i = 0;
    func_801042D8_410738_Results();
    func_80088640_89240();
    D_80107868_413CC8_Results = func_800888A8_894A8(0, 0, 320, 240, 0, 4);
    func_80089B2C_8A72C(D_80107868_413CC8_Results, 200);
    func_8008D530_8E130(D_80107868_413CC8_Results, 0, 0, 0);
    str = func_8006A608_6B208(&D_80107870_413CD0_Results, D_801076BC_413B1C_Results, 1, -1, -1);
    SprPosSet(D_80107870_413CD0_Results.strGId[str], 0, D_801076C0_413B20_Results[0], D_801076C0_413B20_Results[1]);
    for (; i < 7; i++) {
        SprPrioSet(D_80107870_413CD0_Results.strGId[str], i + 1, 6);
    }

    D_801078E4_413D44_Results = SprCreate(0x11, 5);
    SprPosSet(D_801078E4_413D44_Results, 0, 0, 0);
    for (i = 0, n = 0; i < 4; i++) {
        file = DataRead((i + 0xD1) | 0xA0000);
        D_801078E8_413D48_Results[i] = SprAnimRead(file);
        DataClose(file);
        for (j = 0; j < 4; j++) {
            SprAnimSet(D_801078E4_413D44_Results, n + 1, D_801078E8_413D48_Results[i], 0);
            func_8008225C_82E5C(D_801078E4_413D44_Results, n + 1, 1);
            SprPrioSet(D_801078E4_413D44_Results, n + 1, 0x10);
            SprAttrSet(D_801078E4_413D44_Results, n + 1, 0x1000);
            if (D_80107850_413CB0_Results[j].rank == i) {
                if (_CheckFlag(0xD) != 0) {
                    SprPosSet(D_801078E4_413D44_Results, n + 1, D_801076C4_413B24_Results[RES_ROW_PLACE_D][D_80107850_413CB0_Results[j].place][0],
                              D_801076C4_413B24_Results[RES_ROW_PLACE_D][D_80107850_413CB0_Results[j].place][1]);
                } else {
                    SprPosSet(D_801078E4_413D44_Results, n + 1, D_801076C4_413B24_Results[RES_ROW_PLACE][D_80107850_413CB0_Results[j].place][0],
                              D_801076C4_413B24_Results[RES_ROW_PLACE][D_80107850_413CB0_Results[j].place][1]);
                }
            } else {
                if (_CheckFlag(0xD) != 0) {
                    SprPosSet(D_801078E4_413D44_Results, n + 1, -1000, D_801076C4_413B24_Results[RES_ROW_PLACE_D][D_80107850_413CB0_Results[j].place][1]);
                } else {
                    SprPosSet(D_801078E4_413D44_Results, n + 1, -1000, D_801076C4_413B24_Results[RES_ROW_PLACE][D_80107850_413CB0_Results[j].place][1]);
                }
            }
            n++;
        }
    }

    D_801078F8_413D58_Results = SprCreate(5, 5);
    SprPosSet(D_801078F8_413D58_Results, 0, 0, 0);
    for (i = 0; i < 4; i++) {
        file = DataRead(D_801076A4_413B04_Results[gPlayers[i].character]);
        D_80107900_413D60_Results[i] = SprAnimRead(file);
        DataClose(file);
        SprAnimSet(D_801078F8_413D58_Results, i + 1, D_80107900_413D60_Results[i], 0);
        func_8008225C_82E5C(D_801078F8_413D58_Results, i + 1, 1);
        SprPrioSet(D_801078F8_413D58_Results, i + 1, 0x10);
        SprAttrSet(D_801078F8_413D58_Results, i + 1, 0x1000);
        func_800822A8_82EA8(D_801078F8_413D58_Results, i + 1, 0, 0);
        func_8008221C_82E1C(D_801078F8_413D58_Results, i + 1, 0);
        if (_CheckFlag(0xD) != 0) {
            SprPosSet(D_801078F8_413D58_Results, i + 1, D_801076C4_413B24_Results[RES_ROW_CHAR_D][D_80107850_413CB0_Results[i].place][0],
                      D_801076C4_413B24_Results[RES_ROW_CHAR_D][D_80107850_413CB0_Results[i].place][1]);
        } else {
            SprPosSet(D_801078F8_413D58_Results, i + 1, D_801076C4_413B24_Results[RES_ROW_CHAR][D_80107850_413CB0_Results[i].place][0],
                      D_801076C4_413B24_Results[RES_ROW_CHAR][D_80107850_413CB0_Results[i].place][1]);
        }
    }

    D_80107CE8_414148_Results = SprCreate(5, 5);
    SprPosSet(D_80107CE8_414148_Results, 0, 0, 0);
    file = DataRead(0xA010E);
    D_80107CEC_41414C_Results = SprAnimRead(file);
    DataClose(file);
    for (i = 0; i < 4; i++) {
        SprAnimSet(D_80107CE8_414148_Results, i + 1, D_80107CEC_41414C_Results, 0);
        func_8008225C_82E5C(D_80107CE8_414148_Results, i + 1, 1);
        SprPrioSet(D_80107CE8_414148_Results, i + 1, 0x11);
        SprAttrSet(D_80107CE8_414148_Results, i + 1, 0x1000);
        SprScaleSet(D_80107CE8_414148_Results, i + 1, 0.5f, 0.5f);
        if (_CheckFlag(0xD) != 0) {
            SprPosSet(D_80107CE8_414148_Results, i + 1, D_801076C4_413B24_Results[RES_ROW_CHAR_D][D_80107850_413CB0_Results[i].place][0] * 2,
                      D_801076C4_413B24_Results[RES_ROW_CHAR_D][D_80107850_413CB0_Results[i].place][1] * 2);
        } else {
            SprPosSet(D_80107CE8_414148_Results, i + 1, D_801076C4_413B24_Results[RES_ROW_CHAR][D_80107850_413CB0_Results[i].place][0] * 2,
                      D_801076C4_413B24_Results[RES_ROW_CHAR][D_80107850_413CB0_Results[i].place][1] * 2);
        }
        func_8008221C_82E1C(D_80107CE8_414148_Results, i + 1, 0);
    }

    D_80107910_413D70_Results = SprCreate(5, 5);
    SprPosSet(D_80107910_413D70_Results, 0, 0, 0);
    file = DataRead(0xA0011);
    D_80107914_413D74_Results = SprAnimRead(file);
    DataClose(file);
    for (i = 0; i < 4; i++) {
        SprAnimSet(D_80107910_413D70_Results, i + 1, D_80107914_413D74_Results, 0);
        func_8008225C_82E5C(D_80107910_413D70_Results, i + 1, 1);
        SprPrioSet(D_80107910_413D70_Results, i + 1, 0x10);
        SprAttrSet(D_80107910_413D70_Results, i + 1, 0x1000);
        if (_CheckFlag(0xD) != 0) {
            SprAttrSet(D_80107910_413D70_Results, i + 1, 0x8000);
        }
        SprPosSet(D_80107910_413D70_Results, i + 1, D_801076C4_413B24_Results[RES_ROW_COINICON][D_80107850_413CB0_Results[i].place][0],
                  D_801076C4_413B24_Results[RES_ROW_COINICON][D_80107850_413CB0_Results[i].place][1]);
        func_8008221C_82E1C(D_80107910_413D70_Results, i + 1, 0);
    }

    D_80107918_413D78_Results = SprCreate(5, 5);
    SprPosSet(D_80107918_413D78_Results, 0, 0, 0);
    file = DataRead(0xA0010);
    D_8010791C_413D7C_Results = SprAnimRead(file);
    DataClose(file);
    for (i = 0; i < 4; i++) {
        SprAnimSet(D_80107918_413D78_Results, i + 1, D_8010791C_413D7C_Results, 0);
        func_8008225C_82E5C(D_80107918_413D78_Results, i + 1, 1);
        SprPrioSet(D_80107918_413D78_Results, i + 1, 0x10);
        SprAttrSet(D_80107918_413D78_Results, i + 1, 0x1000);
        if (_CheckFlag(0xD) != 0) {
            SprPosSet(D_80107918_413D78_Results, i + 1, D_801076C4_413B24_Results[RES_ROW_COINS_D][D_80107850_413CB0_Results[i].place][0],
                      D_801076C4_413B24_Results[RES_ROW_COINS_D][D_80107850_413CB0_Results[i].place][1]);
        } else {
            SprPosSet(D_80107918_413D78_Results, i + 1, D_801076C4_413B24_Results[RES_ROW_COINS][D_80107850_413CB0_Results[i].place][0],
                      D_801076C4_413B24_Results[RES_ROW_COINS][D_80107850_413CB0_Results[i].place][1]);
        }
        func_8008221C_82E1C(D_80107918_413D78_Results, i + 1, 0);
    }

    for (i = (_CheckFlag(0xD) != 0) * 4; i < 8; i++) {
        if (i < 4) {
            if (gPlayers[i].stars < 10) {
                sprintf(buf, "X%d", gPlayers[i].stars);
            } else {
                sprintf(buf, "%d", gPlayers[i].stars);
            }
        } else {
            sprintf(buf, "X");
        }
        D_80107CC0_414120_Results[i] =
            D_80107920_413D80_Results[i].strGId[func_8006A608_6B208(&D_80107920_413D80_Results[i], buf, 0, 0, -1)];
        if (i < 4) {
            SprPosSet(D_80107CC0_414120_Results[i], 0, D_801076C4_413B24_Results[RES_ROW_STARS][D_80107850_413CB0_Results[i].place][0],
                      D_801076C4_413B24_Results[RES_ROW_STARS][D_80107850_413CB0_Results[i].place][1]);
        } else if (_CheckFlag(0xD) != 0) {
            SprPosSet(D_80107CC0_414120_Results[i], 0, D_801076C4_413B24_Results[RES_ROW_STARS_D][D_80107850_413CB0_Results[i - 4].place][0],
                      D_801076C4_413B24_Results[RES_ROW_STARS_D][D_80107850_413CB0_Results[i - 4].place][1]);
        } else {
            SprPosSet(D_80107CC0_414120_Results[i], 0, D_801076C4_413B24_Results[RES_ROW_STARS][D_80107850_413CB0_Results[i - 4].place][0],
                      D_801076C4_413B24_Results[RES_ROW_STARS][D_80107850_413CB0_Results[i - 4].place][1]);
        }
    }

    for (i = 0; i < 4; i++) {
        coins[i] = gPlayers[i].coins;
        digits[i][0] = coins[i] / 100;
        digits[i][1] = (coins[i] - digits[i][0] * 100) / 10;
        digits[i][2] = coins[i] - digits[i][0] * 100 - digits[i][1] * 10;
        nd[i] = 0;
        if (coins[i] >= 10) {
            nd[i] = 1;
        }
        if (coins[i] >= 100) {
            nd[i] = 2;
        }
    }

    D_80107CE0_414140_Results = SprCreate(0xD, 5);
    SprPosSet(D_80107CE0_414140_Results, 0, 0, 0);
    file = DataRead(0x38);
    D_80107CE4_414144_Results = SprAnimRead(file);
    DataClose(file);
    for (i = 0, n = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            SprAnimSet(D_80107CE0_414140_Results, n + 1, D_80107CE4_414144_Results, 0);
            func_8008225C_82E5C(D_80107CE0_414140_Results, n + 1, 1);
            SprPrioSet(D_80107CE0_414140_Results, n + 1, 0x10);
            SprAttrSet(D_80107CE0_414140_Results, n + 1, 0x1000);
            if (_CheckFlag(0xD) != 0) {
                SprPosSet(D_80107CE0_414140_Results, n + 1,
                          D_801076C4_413B24_Results[RES_ROW_COINS_D][D_80107850_413CB0_Results[i].place][0] + (s16)(j * 16 + 24) +
                              D_80107774_413BD4_Results[0][nd[i]][j],
                          D_801076C4_413B24_Results[RES_ROW_COINS_D][D_80107850_413CB0_Results[i].place][1] + 4);
            } else {
                SprPosSet(D_80107CE0_414140_Results, n + 1,
                          D_801076C4_413B24_Results[RES_ROW_COINS][D_80107850_413CB0_Results[i].place][0] + (s16)(j * 16 + 24) +
                              D_80107774_413BD4_Results[0][nd[i]][j],
                          D_801076C4_413B24_Results[RES_ROW_COINS][D_80107850_413CB0_Results[i].place][1] + 4);
            }
            func_800822A8_82EA8(D_80107CE0_414140_Results, n + 1, digits[i][j], 0);
            func_8008221C_82E1C(D_80107CE0_414140_Results, n + 1, 0);
            n++;
        }
        if (_CheckFlag(0xD) != 0) {
            func_80104418_410878_Results(D_80107CC0_414120_Results[4 + i], 0, D_80107774_413BD4_Results[1][nd[i]][3]);
        } else {
            func_80104418_410878_Results(D_80107CC0_414120_Results[4 + i], 0, D_80107774_413BD4_Results[0][nd[i]][3]);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_70_Results/40EC60", func_80102944_40EDA4_Results);
#endif

// register allocation: n and j swap s0/s1 (masked 0)
#ifdef NON_MATCHING
/* Redraws each player's coin count. */
void func_801038A4_40FD04_Results(void) {
    s16 coins[4];
    s8 digits[4][3];
    s8 nd[4];
    s16 i;
    s16 j;
    s32 n;

    for (i = 0; i < 4; i++) {
        coins[i] = gPlayers[i].coins;
        digits[i][0] = coins[i] / 100;
        digits[i][1] = (coins[i] - digits[i][0] * 100) / 10;
        digits[i][2] = coins[i] - digits[i][0] * 100 - digits[i][1] * 10;
        nd[i] = 0;
        if (coins[i] >= 10) {
            nd[i] = 1;
        }
        if (coins[i] >= 100) {
            nd[i] = 2;
        }
    }
    for (i = 0, n = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            if (_CheckFlag(0xD) != 0) {
                SprPosSet(D_80107CE0_414140_Results, n + 1,
                          D_801076C4_413B24_Results[RES_ROW_COINS_D][D_80107850_413CB0_Results[i].place][0] + (s16)(j * 16 + 24) +
                              D_80107774_413BD4_Results[0][nd[i]][j],
                          D_801076C4_413B24_Results[RES_ROW_COINS_D][D_80107850_413CB0_Results[i].place][1] + 4);
            } else {
                SprPosSet(D_80107CE0_414140_Results, n + 1,
                          D_801076C4_413B24_Results[RES_ROW_COINS][D_80107850_413CB0_Results[i].place][0] + (s16)(j * 16 + 24) +
                              D_80107774_413BD4_Results[0][nd[i]][j],
                          D_801076C4_413B24_Results[RES_ROW_COINS][D_80107850_413CB0_Results[i].place][1] + 4);
            }
            n++;
            func_800822A8_82EA8(D_80107CE0_414140_Results, n, digits[i][j], 0);
        }
        if (_CheckFlag(0xD) != 0) {
            func_80104418_410878_Results(D_80107CC0_414120_Results[4 + i], 0, D_80107774_413BD4_Results[1][nd[i]][3]);
        } else {
            func_80104418_410878_Results(D_80107CC0_414120_Results[4 + i], 0, D_80107774_413BD4_Results[0][nd[i]][3]);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_70_Results/40EC60", func_801038A4_40FD04_Results);
#endif

void func_80103C6C_4100CC_Results(void) {
    s32 i;
    s32 var_s0_3;

    func_8006AE14_6BA14(&D_80107870_413CD0_Results);
    
    for (i = 0; i < 4; i++) {
        SprAnimKill(D_80107900_413D60_Results[i]);
    }

    for (i = 0; i < 4; i++) {
        SprAnimKill(D_801078E8_413D48_Results[i]);
    }

    SprKill(D_801078E4_413D44_Results);
    SprKill(D_801078F8_413D58_Results);
    SprAnimKill(D_80107CEC_41414C_Results);
    SprKill(D_80107CE8_414148_Results);
    SprAnimKill(D_80107914_413D74_Results);
    SprAnimKill(D_8010791C_413D7C_Results);
    SprKill(D_80107910_413D70_Results);
    SprKill(D_80107918_413D78_Results);
    SprKill(D_80107CE0_414140_Results);
    var_s0_3 = (_CheckFlag(0xD) != 0) * 4;

    for (; var_s0_3 < 8; var_s0_3++) {
        func_8006AE14_6BA14(&D_80107920_413D80_Results[var_s0_3]);
    }
    
    func_8008CE5C_8DA5C();
}

// the noCoins test: retail copies it to v0 first (masked 1)
#ifdef NON_MATCHING
/* The screen's process: show the table, count the minigame bonus coins, then the minigame coins,
   re-rank the players and wait for A/Start (or for nobody, when all four are CPUs). */
void func_80103DB4_410214_Results(void) {
    s16 i;
    s8 cpus;
    s32 allCpu;
    s32 autoSkip;
    s32 noCoins;

    noCoins = 0;
    func_80102944_40EDA4_Results();
    InitFadeIn(0, 16);
    if (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    for (i = 0; i < 4; i++) {
        if (D_80107830_413C90_Results[i] != 0 || D_80107838_413C98_Results[i] != 0) {
            break;
        }
    }
    if (i >= 4) {
        noCoins = 1;
    }
    D_801076A2_413B02_Results = 0;
    if (noCoins == 0) {
        HuPrcSleep(10);
    }
    if (D_801076A1_413B01_Results == 0) {
        for (i = 24; i > 0; i--) {
            HuPrcVSleep();
            if (D_801076A1_413B01_Results != 0) {
                break;
            }
        }
    }
    func_801046DC_410B3C_Results();
    HuPrcSleep(10);
    if (D_801076A1_413B01_Results == 0) {
        for (i = 24; i > 0; i--) {
            HuPrcVSleep();
            if (D_801076A1_413B01_Results != 0) {
                break;
            }
        }
    }
    func_80107140_4135A0_Results(30, 0);
    while (func_801072B0_413710_Results(0) == 0) {
        func_801038A4_40FD04_Results();
        func_80105AB8_411F18_Results();
        if (D_801076A1_413B01_Results == 0) {
            HuPrcVSleep();
        }
    }
    func_801038A4_40FD04_Results();
    func_80105AB8_411F18_Results();
    HuPrcSleep(10);
    if (D_801076A1_413B01_Results == 0) {
        for (i = 8; i > 0; i--) {
            HuPrcVSleep();
            if (D_801076A1_413B01_Results != 0) {
                break;
            }
        }
    }
    func_80107140_4135A0_Results(30, 1);
    while (func_801072B0_413710_Results(1) == 0) {
        func_801038A4_40FD04_Results();
        func_80105F50_4123B0_Results();
        if (D_801076A1_413B01_Results == 0) {
            HuPrcVSleep();
        }
    }
    func_801038A4_40FD04_Results();
    func_80105F50_4123B0_Results();
    if (D_801076A1_413B01_Results != 0 && noCoins != 1) {
        HuPrcSleep(8);
    }
    func_801044D0_410930_Results();
    func_801063E8_412848_Results();
    allCpu = 0;
    cpus = 0;
    for (i = 0; i < MAX_PLAYERS; i++) {
        if (gPlayers[i].flags & 1) {
            cpus++;
        }
    }
    if (cpus >= 4) {
        allCpu = 1;
    }
    autoSkip = allCpu;
    while (D_801077A4_413C04_Results == 0) {
        for (i = 0; i < MAX_PLAYERS; i++) {
            if (!(gPlayers[i].flags & 1)) {
                if (ContBtn[gPlayers[i].port] & (A_BUTTON | START_BUTTON)) {
                    D_801077A4_413C04_Results = 1;
                }
            }
        }
        if (autoSkip == 1) {
            HuPrcSleep(8);
            D_801077A4_413C04_Results = 1;
        }
        HuPrcVSleep();
    }
    HuPrcSleep(8);
    D_801076A2_413B02_Results = 1;
    InitFadeOut(0, 16);
    func_800794A8_7A0A8(40);
    D_801076A0_413B00_Results = 1;
    while (TRUE) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_70_Results/40EC60", func_80103DB4_410214_Results);
#endif

void func_801041C8_410628_Results(void) {
    s32 i;

    if (D_801076A0_413B00_Results != 0 && func_8008F618_90218() == 0) {
        for (i = 0; i < MAX_PLAYERS; i++) {
            gPlayers[i].coins_mg = 0;
            gPlayers[i].coins_mg_bonus = 0;
        }
        func_80107544_4139A4_Results();
        func_80103C6C_4100CC_Results();
        func_8010438C_4107EC_Results();
        func_801042B4_410714_Results();
        func_80059CC8_5A8C8();
        func_80059400_5A000();
        func_80059704_5A304();
        omOvlReturnEx(1);
    }
}

void func_80104278_4106D8_Results(void) {
    MBModelInit();
    func_8005E2B8_5EEB8();
    func_80059C28_5A828();
    func_800593C0_59FC0();
    func_8005965C_5A25C();
}

void func_801042B4_410714_Results(void) {
    func_8004340C_4400C();
    func_8005E2FC_5EEFC();
}

void func_801042D8_410738_Results(void) {
    func_80018E30_19A30(1);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_80050A30_51630(D_01164160);
    func_80050E00_51A00(D_801077A8_413C08_Results[GwSystem.current_board_index]);
}

void func_8010438C_4107EC_Results(void) {
    MBDBackKill();
    func_80050AE0_516E0();
}

void func_801043B0_410810_Results(s16 grp, s16 idx, s16 dx, s16 dy) {
    HuSprite* spr = HuSprGrpData[grp]->members[idx];

    spr->unk_48 += dx;
    spr->unk_4C += dy;
}

void func_80104418_410878_Results(s16 grp, s16 idx, s16 x) {
    HuSprGrpData[grp]->members[idx]->unk_48 = x;
}

void func_80104458_4108B8_Results(s16 grp, s16 idx, s16 y) {
    HuSprGrpData[grp]->members[idx]->unk_4C = y;
}

void func_80104498_4108F8_Results(s16 grp, s16 idx, s32 mask) {
    HuSprite* spr = HuSprGrpData[grp]->members[idx];

    spr->unk_24 = spr->unk_5C &= mask;
}

/* Shrinks the coin counters away. */
void func_801044D0_410930_Results(void) {
    s32 i;
    s32 j;
    f32 scale;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5;) {
            j++;
            SprScaleSet(D_80107CF0_414150_Results[i], j, 1.0f, 1.0f);
            SprScaleSet(D_80107D00_414160_Results[i], j, 1.0f, 1.0f);
        }
    }
    for (scale = 1.0f; scale > 0.0f; scale -= 0.3f) {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 5;) {
                j++;
                SprScaleSet(D_80107CF0_414150_Results[i], j, scale, scale);
                SprScaleSet(D_80107D00_414160_Results[i], j, scale, scale);
            }
        }
        if (D_801076A1_413B01_Results == 0) {
            HuPrcVSleep();
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5;) {
            j++;
            SprAttrSet(D_80107CF0_414150_Results[i], j, 0x8000);
            SprAttrSet(D_80107D00_414160_Results[i], j, 0x8000);
        }
    }
}

/* Grows the coin counters of the players who won coins. */
void func_801046DC_410B3C_Results(void) {
    s32 i;
    s32 j;
    f32 scale;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            if (D_80107830_413C90_Results[i] != 0) {
                func_80104498_4108F8_Results(D_80107CF0_414150_Results[i], j + 1, 0x7FFF);
            }
            if (D_80107838_413C98_Results[i] != 0) {
                func_80104498_4108F8_Results(D_80107D00_414160_Results[i], j + 1, 0x7FFF);
            }
        }
    }
    for (scale = 0.0f; scale < 1.0; scale += 0.3) {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 5;) {
                j++;
                SprScaleSet(D_80107CF0_414150_Results[i], j, scale, scale);
                SprScaleSet(D_80107D00_414160_Results[i], j, scale, scale);
            }
        }
        if (D_801076A1_413B01_Results == 0) {
            HuPrcVSleep();
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5;) {
            j++;
            SprScaleSet(D_80107CF0_414150_Results[i], j, 1.0f, 1.0f);
            SprScaleSet(D_80107D00_414160_Results[i], j, 1.0f, 1.0f);
        }
    }
}

// register allocation of the rank counter (masked 2, as MP1 func_800F7F38)
#ifdef NON_MATCHING
/* Ranks the players: stars first, then coins. */
void func_8010492C_410D8C_Results(void) {
    s32 score[4];
    s32 who[4];
    s32 place[4];
    s32 rank[4];
    s16 i;
    s16 j;
    s32 tmp;
    s8 r;
    s8 k;

    for (i = 0; i < 4; i++) {
        score[i] = gPlayers[i].coins;
        score[i] += gPlayers[i].stars * 10000;
        who[i] = i;
    }
    for (j = 0; j < 3; j++) {
        for (i = j + 1; i < 4; i++) {
            if (score[j] < score[i]) {
                tmp = score[j];
                score[j] = score[i];
                score[i] = tmp;
                tmp = who[j];
                who[j] = who[i];
                who[i] = tmp;
            }
        }
    }
    D_80107850_413CB0_Results[0].rank = 0;
    D_80107850_413CB0_Results[0].place = who[0];
    r = 0;
    k = 0;
    for (i = 1; i < 4; i++) {
        k++;
        if (score[i - 1] != score[i]) {
            r = k;
        }
        D_80107850_413CB0_Results[i].rank = r;
        D_80107850_413CB0_Results[i].place = who[i];
    }
    for (i = 0; i < 4; i++) {
        place[i] = D_80107850_413CB0_Results[i].place;
        rank[i] = D_80107850_413CB0_Results[i].rank;
    }
    for (i = 0; i < 4; i++) {
        D_80107850_413CB0_Results[place[i]].place = i;
        D_80107850_413CB0_Results[place[i]].rank = rank[i];
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_70_Results/40EC60", func_8010492C_410D8C_Results);
#endif

void func_80104B90_410FF0_Results(void) {
    s32 i;

    for (i = 0; i < MAX_PLAYERS; i++) {
        D_80107860_413CC0_Results[i] = gPlayers[i].coins;
        D_80107830_413C90_Results[i] =  gPlayers[i].coins_mg_bonus;
        D_80107838_413C98_Results[i] = gPlayers[i].coins_mg;
        if ((gPlayers[i].coins + D_80107830_413C90_Results[i] + D_80107838_413C98_Results[i]) > 999) {
            D_80107830_413C90_Results[i] = 999 - gPlayers[i].coins;
            D_80107838_413C98_Results[i] = 0;
        }
        if ((gPlayers[i].coins + D_80107830_413C90_Results[i] + D_80107838_413C98_Results[i] < 0)) {
            D_80107830_413C90_Results[i] = -gPlayers[i].coins;
            D_80107838_413C98_Results[i] = 0;
        }
        gPlayers[i].coins_total += gPlayers[i].coins_mg;
        gPlayers[i].coins_total += gPlayers[i].coins_mg_bonus;
        D_80107840_413CA0_Results[i] = gPlayers[i].coins_mg_bonus;
        D_80107848_413CA8_Results[i] = gPlayers[i].coins_mg;
    }
}

/* Builds each player's two coin counters: the minigame bonus coins (G1) and the minigame coins
   (G2). Member 0 is the backdrop, 1 the icon, 2-4 the digits, 5 the sign. */
void func_80104D3C_41119C_Results(void) {
    s16 nd[4];
    s16 nd2[4];
    s16 digits[4][3];
    s16 digits2[4][3];
    s32 n;
    s32 j;
    s32 i;
    void* file;

    for (i = 0; i < 4; i++) {
        digits[i][0] = ABS(D_80107840_413CA0_Results[i]) / 100;
        digits[i][1] = (ABS(D_80107840_413CA0_Results[i]) - digits[i][0] * 100) / 10;
        digits[i][2] = ABS(D_80107840_413CA0_Results[i]) - digits[i][0] * 100 - digits[i][1] * 10;
        nd[i] = 0;
        if (ABS(D_80107840_413CA0_Results[i]) >= 10) {
            nd[i] = 1;
        }
        if (ABS(D_80107840_413CA0_Results[i]) >= 100) {
            nd[i] = 2;
        }
        digits2[i][0] = ABS(D_80107848_413CA8_Results[i]) / 100;
        digits2[i][1] = (ABS(D_80107848_413CA8_Results[i]) - digits2[i][0] * 100) / 10;
        digits2[i][2] = ABS(D_80107848_413CA8_Results[i]) - digits2[i][0] * 100 - digits2[i][1] * 10;
        nd2[i] = 0;
        if (ABS(D_80107848_413CA8_Results[i]) >= 10) {
            nd2[i] = 1;
        }
        if (ABS(D_80107848_413CA8_Results[i]) >= 100) {
            nd2[i] = 2;
        }
    }
    for (i = 0; i < 4; i++) {
        n = 0;
        D_80107D10_414170_Results = SprCreate(6, 5);
        D_80107CF0_414150_Results[i] = D_80107D10_414170_Results;
        D_80107D14_414174_Results = SprCreate(6, 5);
        D_80107D00_414160_Results[i] = D_80107D14_414174_Results;
        file = DataRead(0xC0000);
        D_80107D18_414178_Results[i] = SprAnimRead(file);
        DataClose(file);
        file = DataRead(0xC0001);
        D_80107D28_414188_Results[i] = SprAnimRead(file);
        DataClose(file);
        SprAnimSet(D_80107D10_414170_Results, n, D_80107D18_414178_Results[i], 0);
        SprAnimSet(D_80107D14_414174_Results, n, D_80107D28_414188_Results[i], 0);
        func_800824F4_830F4(D_80107D10_414170_Results, n, -1);
        func_800824F4_830F4(D_80107D14_414174_Results, n, -1);
        SprAttrSet(D_80107D10_414170_Results, n, 0x8000);
        SprAttrSet(D_80107D14_414174_Results, n, 0x8000);
        if (_CheckFlag(0xD) != 0) {
            SprPosSet(D_80107D10_414170_Results, n, D_801076C4_413B24_Results[RES_ROW_CHAR_D][D_80107850_413CB0_Results[i].place][0] - 32,
                      D_801076C4_413B24_Results[RES_ROW_CHAR_D][D_80107850_413CB0_Results[i].place][1] - 16);
            SprPosSet(D_80107D14_414174_Results, n, D_801076C4_413B24_Results[RES_ROW_CHAR_D][D_80107850_413CB0_Results[i].place][0] + 32,
                      D_801076C4_413B24_Results[RES_ROW_CHAR_D][D_80107850_413CB0_Results[i].place][1] + 16);
        } else {
            SprPosSet(D_80107D10_414170_Results, n, D_801076C4_413B24_Results[RES_ROW_CHAR][D_80107850_413CB0_Results[i].place][0] - 32,
                      D_801076C4_413B24_Results[RES_ROW_CHAR][D_80107850_413CB0_Results[i].place][1] - 16);
            SprPosSet(D_80107D14_414174_Results, n, D_801076C4_413B24_Results[RES_ROW_CHAR][D_80107850_413CB0_Results[i].place][0] + 32,
                      D_801076C4_413B24_Results[RES_ROW_CHAR][D_80107850_413CB0_Results[i].place][1] + 16);
        }
        n++;
        SprAnimSet(D_80107D10_414170_Results, n, D_80107D18_414178_Results[i], 0);
        SprAnimSet(D_80107D14_414174_Results, n, D_80107D28_414188_Results[i], 0);
        func_8008225C_82E5C(D_80107D10_414170_Results, n, 1);
        func_8008225C_82E5C(D_80107D14_414174_Results, n, 1);
        SprPrioSet(D_80107D10_414170_Results, n, 5);
        SprPrioSet(D_80107D14_414174_Results, n, 5);
        SprAttrSet(D_80107D10_414170_Results, n, 0x1000);
        SprAttrSet(D_80107D14_414174_Results, n, 0x1000);
        SprPosSet(D_80107D10_414170_Results, n, 0, 0);
        SprPosSet(D_80107D14_414174_Results, n, 0, 0);
        func_800824F4_830F4(D_80107D10_414170_Results, n, 0);
        func_800824F4_830F4(D_80107D14_414174_Results, n, 0);
        n++;
        for (j = 0; j < 3; j++) {
            file = DataRead(0xC000D);
            D_80107D58_4141B8_Results[i][j] = SprAnimRead(file);
            DataClose(file);
            file = DataRead(0xC000D);
            D_80107D88_4141E8_Results[i][j] = SprAnimRead(file);
            DataClose(file);
            SprAnimSet(D_80107D10_414170_Results, n, D_80107D58_4141B8_Results[i][j], 0);
            SprAnimSet(D_80107D14_414174_Results, n, D_80107D88_4141E8_Results[i][j], 0);
            func_8008225C_82E5C(D_80107D10_414170_Results, n, 1);
            func_8008225C_82E5C(D_80107D14_414174_Results, n, 1);
            SprPrioSet(D_80107D10_414170_Results, n, 4);
            SprPrioSet(D_80107D14_414174_Results, n, 4);
            SprAttrSet(D_80107D10_414170_Results, n, 0x1000);
            SprAttrSet(D_80107D14_414174_Results, n, 0x1000);
            func_800822A8_82EA8(D_80107D10_414170_Results, n, digits[i][j], 0);
            func_800822A8_82EA8(D_80107D14_414174_Results, n, digits2[i][j], 0);
            func_800824F4_830F4(D_80107D10_414170_Results, n, 0);
            func_800824F4_830F4(D_80107D14_414174_Results, n, 0);
            func_8008221C_82E1C(D_80107D10_414170_Results, n, 0);
            func_8008221C_82E1C(D_80107D14_414174_Results, n, 0);
            SprPosSet(D_80107D10_414170_Results, n, D_801077C4_413C24_Results[nd[i]][j] + 4, -2);
            SprPosSet(D_80107D14_414174_Results, n, D_801077C4_413C24_Results[nd2[i]][j] + 4, 2);
            n++;
        }
        file = DataRead(0xC000D);
        D_80107D38_414198_Results[i] = SprAnimRead(file);
        DataClose(file);
        file = DataRead(0xC000D);
        D_80107D48_4141A8_Results[i] = SprAnimRead(file);
        DataClose(file);
        SprAnimSet(D_80107D10_414170_Results, n, D_80107D38_414198_Results[i], 0);
        SprAnimSet(D_80107D14_414174_Results, n, D_80107D48_4141A8_Results[i], 0);
        func_8008225C_82E5C(D_80107D10_414170_Results, n, 1);
        func_8008225C_82E5C(D_80107D14_414174_Results, n, 1);
        SprPrioSet(D_80107D10_414170_Results, n, 4);
        SprPrioSet(D_80107D14_414174_Results, n, 4);
        SprAttrSet(D_80107D10_414170_Results, n, 0x1000);
        SprAttrSet(D_80107D14_414174_Results, n, 0x1000);
        func_800824F4_830F4(D_80107D10_414170_Results, n, 0);
        func_800824F4_830F4(D_80107D14_414174_Results, n, 0);
        /* Retail picks both signs from the bonus coins' sign. */
        if (D_80107840_413CA0_Results[i] >= 0) {
            func_800822A8_82EA8(D_80107D10_414170_Results, n, 11, 0);
            SprPosSet(D_80107D10_414170_Results, n, D_801077C4_413C24_Results[nd[i]][2 - nd[i]] - 4, -2);
            func_800822A8_82EA8(D_80107D14_414174_Results, n, 11, 0);
            SprPosSet(D_80107D14_414174_Results, n, D_801077C4_413C24_Results[nd2[i]][2 - nd2[i]] - 4, 2);
        } else {
            func_800822A8_82EA8(D_80107D10_414170_Results, n, 12, 0);
            SprPosSet(D_80107D10_414170_Results, n, D_801077C4_413C24_Results[nd[i]][2 - nd[i]] - 4, -2);
            func_800822A8_82EA8(D_80107D14_414174_Results, n, 12, 0);
            SprPosSet(D_80107D14_414174_Results, n, D_801077C4_413C24_Results[nd2[i]][2 - nd2[i]] - 4, 2);
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            SprAttrSet(D_80107CF0_414150_Results[i], j + 1, 0x8000);
            SprAttrSet(D_80107D00_414160_Results[i], j + 1, 0x8000);
        }
    }
}

// retail has the KMC VR4300 mul fix here (a nop before a mult) but 4D3C has not: probably a
// second file from 80105AB8 (masked 2 with the fix on)
#ifdef NON_MATCHING
/* Redraws each player's bonus coin counter with the coins still to count. */
void func_80105AB8_411F18_Results(void) {
    s16 left[4];
    s16 nd[4];
    s16 digits[4][3];
    s32 i;
    s32 j;
    s16 n;

    for (i = 0; i < 4; i++) {
        left[i] = D_80107840_413CA0_Results[i] - (gPlayers[i].coins - D_80107860_413CC0_Results[i]);
        digits[i][0] = ABS(left[i]) / 100;
        digits[i][1] = (ABS(left[i]) - digits[i][0] * 100) / 10;
        digits[i][2] = ABS(left[i]) - digits[i][0] * 100 - digits[i][1] * 10;
        nd[i] = 0;
        if (ABS(left[i]) >= 10) {
            nd[i] = 1;
        }
        if (ABS(left[i]) >= 100) {
            nd[i] = 2;
        }
    }
    for (i = 0, n = 2; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            func_800822A8_82EA8(D_80107CF0_414150_Results[i], n, digits[i][j], 0);
            if (left[i] == 0) {
                SprPosSet(D_80107CF0_414150_Results[i], n, D_801077D8_413C38_Results[nd[i]][j], -2);
            } else {
                SprPosSet(D_80107CF0_414150_Results[i], n, D_801077D8_413C38_Results[nd[i]][j] + 4, -2);
            }
            n++;
        }
        if (left[i] == 0) {
            SprPosSet(D_80107CF0_414150_Results[i], n, -1000, -2);
            func_800822A8_82EA8(D_80107CF0_414150_Results[i], n, 10, 0);
        } else {
            if (left[i] > 0) {
                func_800822A8_82EA8(D_80107CF0_414150_Results[i], n, 11, 0);
            } else {
                func_800822A8_82EA8(D_80107CF0_414150_Results[i], n, 12, 0);
            }
            SprPosSet(D_80107CF0_414150_Results[i], n, D_801077D8_413C38_Results[nd[i]][2 - nd[i]] - 4, -2);
        }
        n = 2;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_70_Results/40EC60", func_80105AB8_411F18_Results);
#endif

// retail has the KMC VR4300 mul fix here (a nop before a mult) but 4D3C has not: probably a
// second file from 80105AB8 (masked 2 with the fix on)
#ifdef NON_MATCHING
/* Redraws each player's minigame coin counter with the coins still to count. */
void func_80105F50_4123B0_Results(void) {
    s16 left[4];
    s16 nd[4];
    s16 digits[4][3];
    s32 i;
    s32 j;
    s16 n;

    for (i = 0; i < 4; i++) {
        left[i] = D_80107848_413CA8_Results[i] - (gPlayers[i].coins - D_80107860_413CC0_Results[i]);
        digits[i][0] = ABS(left[i]) / 100;
        digits[i][1] = (ABS(left[i]) - digits[i][0] * 100) / 10;
        digits[i][2] = ABS(left[i]) - digits[i][0] * 100 - digits[i][1] * 10;
        nd[i] = 0;
        if (ABS(left[i]) >= 10) {
            nd[i] = 1;
        }
        if (ABS(left[i]) >= 100) {
            nd[i] = 2;
        }
    }
    for (i = 0, n = 2; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            func_800822A8_82EA8(D_80107D00_414160_Results[i], n, digits[i][j], 0);
            if (left[i] == 0) {
                SprPosSet(D_80107D00_414160_Results[i], n, D_801077EC_413C4C_Results[nd[i]][j], 2);
            } else {
                SprPosSet(D_80107D00_414160_Results[i], n, D_801077EC_413C4C_Results[nd[i]][j] + 4, 2);
            }
            n++;
        }
        if (left[i] == 0) {
            SprPosSet(D_80107D00_414160_Results[i], n, -1000, -2);
            func_800822A8_82EA8(D_80107D00_414160_Results[i], n, 10, 0);
        } else {
            if (left[i] > 0) {
                func_800822A8_82EA8(D_80107D00_414160_Results[i], n, 11, 0);
            } else {
                func_800822A8_82EA8(D_80107D00_414160_Results[i], n, 12, 0);
            }
            SprPosSet(D_80107D00_414160_Results[i], n, D_801077EC_413C4C_Results[nd[i]][2 - nd[i]] - 4, 2);
        }
        n = 2;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_70_Results/40EC60", func_80105F50_4123B0_Results);
#endif

// register allocation (p, t, d) and the speed * 25 strength reduction (masked 30)
#ifdef NON_MATCHING
/* A player's rank or place changed with the coins. */
#define MOVED(i)                                                                                      \
    (newRank[D_80107858_413CB8_Results[i].place] != oldRank[D_80107858_413CB8_Results[i].place] || \
     D_80107858_413CB8_Results[i].rank != D_80107850_413CB0_Results[i].rank)

/* Re-ranks the players after the coins: slides the rows that change out to the right, moves them
   to their new rows and slides them back in, one rank after another. */
void func_801063E8_412848_Results(void) {
    s16 delay[4];
    s16 off[4]; /* off[0] first sums the slide out */
    f32 ang[4];
    s8 taken[4];
    s8 newRank[4];
    s8 oldRank[4];
    u16 speed;
    s32 spd;
    s32 p;
    s32 i;
    s32 j;
    s32 n;
    s32 t;
    s32 d;
    s32 sum;

    p = 0;
    for (i = 0; i < 4; i++) {
        D_80107858_413CB8_Results[i] = D_80107850_413CB0_Results[i];
    }
    func_8010492C_410D8C_Results();
    speed = (D_801076A1_413B01_Results != 0) ? 3 : 1;
    for (i = 0; i < 4; i++) {
        oldRank[D_80107858_413CB8_Results[i].place] = D_80107858_413CB8_Results[i].rank;
        newRank[D_80107850_413CB0_Results[i].place] = D_80107850_413CB0_Results[i].rank;
    }

    /* Hide the place sprites of the players who move. */
    for (i = 0, n = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (D_80107858_413CB8_Results[j].rank == i && MOVED(j)) {
                SprAttrSet(D_801078E4_413D44_Results, n + 1, 0x8000);
            }
            n++;
        }
    }

    /* Slide them out to the right. */
    t = 0;
    off[0] = 0;
    spd = speed;
    do {
        d = HuMathSin(t) * -30.0f * spd;
        off[0] += d;
        for (i = 0, n = 0; i < 4; i++) {
            if (MOVED(i)) {
                func_801043B0_410810_Results(D_801078F8_413D58_Results, i + 1, d, 0);
                func_801043B0_410810_Results(D_80107CE8_414148_Results, i + 1, d * 2, 0);
                func_801043B0_410810_Results(D_80107910_413D70_Results, i + 1, d, 0);
                func_801043B0_410810_Results(D_80107918_413D78_Results, i + 1, d, 0);
                func_801043B0_410810_Results(D_80107CC0_414120_Results[i], 0, d, 0);
                func_801043B0_410810_Results(D_80107CC0_414120_Results[4 + i], 0, d, 0);
            }
            for (j = 0; j < 3; j++) {
                if (MOVED(i)) {
                    func_801043B0_410810_Results(D_80107CE0_414140_Results, n + 1, d, 0);
                }
                n++;
            }
        }
        HuPrcVSleep();
        t += spd * 5;
    } while (t < 90);

    /* Give each of them the first free row from its new rank down. */
    for (i = 0; i < 4; i++) {
        if (MOVED(i)) {
            taken[D_80107858_413CB8_Results[i].place] = 0;
        } else {
            taken[D_80107858_413CB8_Results[i].place] = 1;
        }
    }
    for (i = 0, n = 0; i < 4; i++) {
        if (MOVED(i)) {
            for (p = D_80107850_413CB0_Results[i].rank; p < 4; p++) {
                if (taken[p] == 0) {
                    taken[p] = 1;
                    break;
                }
            }
            if (p >= 4) {
                p = 0;
            }
            /* Retail uses the normal layout's character row in both layouts. */
            func_80104458_4108B8_Results(D_801078F8_413D58_Results, i + 1, D_801076C4_413B24_Results[RES_ROW_CHAR][p][1]);
            func_80104458_4108B8_Results(D_80107CE8_414148_Results, i + 1, D_801076C4_413B24_Results[RES_ROW_CHAR][p][1] * 2);
            func_80104458_4108B8_Results(D_80107910_413D70_Results, i + 1, D_801076C4_413B24_Results[RES_ROW_COINICON][p][1]);
            if (_CheckFlag(0xD) != 0) {
                func_80104458_4108B8_Results(D_80107918_413D78_Results, i + 1, D_801076C4_413B24_Results[RES_ROW_COINS_D][p][1]);
            } else {
                func_80104458_4108B8_Results(D_80107918_413D78_Results, i + 1, D_801076C4_413B24_Results[RES_ROW_COINS][p][1]);
            }
            func_80104458_4108B8_Results(D_80107CC0_414120_Results[i], 0, D_801076C4_413B24_Results[RES_ROW_STARS][p][1]);
            if (_CheckFlag(0xD) != 0) {
                func_80104458_4108B8_Results(D_80107CC0_414120_Results[4 + i], 0, D_801076C4_413B24_Results[RES_ROW_STARS_D][p][1]);
            } else {
                func_80104458_4108B8_Results(D_80107CC0_414120_Results[4 + i], 0, D_801076C4_413B24_Results[RES_ROW_STARS][p][1]);
            }
        }
        for (j = 0; j < 3; j++) {
            if (MOVED(i)) {
                if (_CheckFlag(0xD) != 0) {
                    func_80104458_4108B8_Results(D_80107CE0_414140_Results, n + 1, D_801076C4_413B24_Results[RES_ROW_COINS_D][p][1] + 4);
                } else {
                    func_80104458_4108B8_Results(D_80107CE0_414140_Results, n + 1, D_801076C4_413B24_Results[RES_ROW_COINS][p][1] + 4);
                }
            }
            n++;
        }
        if (D_80107858_413CB8_Results[i].rank == D_80107850_413CB0_Results[i].rank) {
            func_800822A8_82EA8(D_801078F8_413D58_Results, i + 1, 0, 0);
        } else if (D_80107858_413CB8_Results[i].rank > D_80107850_413CB0_Results[i].rank) {
            func_800822A8_82EA8(D_801078F8_413D58_Results, i + 1, 1, 0);
        } else {
            func_800822A8_82EA8(D_801078F8_413D58_Results, i + 1, 2, 0);
        }
    }

    /* Put them as far right as the slide in will bring them back. */
    sum = 0;
    for (t = 0; t < 90; t += speed * 5) {
        sum += HuMathSin(t) * 25.0f * speed;
    }
    if (off[0] >= 0) {
        sum += off[0];
    } else {
        sum -= off[0];
    }
    for (i = 0; i < 4; i++) {
        if (MOVED(i)) {
            delay[i] = D_80107850_413CB0_Results[i].rank * 8;
            func_801043B0_410810_Results(D_801078F8_413D58_Results, i + 1, sum, 0);
            func_801043B0_410810_Results(D_80107CE8_414148_Results, i + 1, sum * 2, 0);
            func_801043B0_410810_Results(D_80107910_413D70_Results, i + 1, sum, 0);
            func_801043B0_410810_Results(D_80107918_413D78_Results, i + 1, sum, 0);
            func_801043B0_410810_Results(D_80107CC0_414120_Results[i], 0, sum, 0);
            func_801043B0_410810_Results(D_80107CC0_414120_Results[4 + i], 0, sum, 0);
            for (j = 0; j < 3; j++) {
                func_801043B0_410810_Results(D_80107CE0_414140_Results, i * 3 + j + 1, sum, 0);
            }
        } else {
            delay[i] = -1;
        }
        ang[i] = 0.0f;
    }

    /* Slide them back in, one rank after another. */
    t = 0;
    do {
        for (i = 0; i < 4; i++) {
            if (delay[i] < 0) {
                continue;
            }
            if (D_801076A1_413B01_Results != 0) {
                delay[i] = 0;
            }
            if (delay[i] < t) {
                off[i] = -HuMathSin(ang[i]) * (speed * 25);
                func_801043B0_410810_Results(D_801078F8_413D58_Results, i + 1, off[i], 0);
                func_801043B0_410810_Results(D_80107CE8_414148_Results, i + 1, off[i] * 2, 0);
                func_801043B0_410810_Results(D_80107910_413D70_Results, i + 1, off[i], 0);
                func_801043B0_410810_Results(D_80107918_413D78_Results, i + 1, off[i], 0);
                func_801043B0_410810_Results(D_80107CC0_414120_Results[i], 0, off[i], 0);
                func_801043B0_410810_Results(D_80107CC0_414120_Results[4 + i], 0, off[i], 0);
                for (j = 0; j < 3; j++) {
                    func_801043B0_410810_Results(D_80107CE0_414140_Results, i * 3 + j + 1, off[i], 0);
                }
                ang[i] += speed * 5;
                if (ang[i] >= 90.0f) {
                    delay[i] = -1;
                    if (D_801076A1_413B01_Results == 0) {
                        omVibrate(i, 5, 0, 5);
                    }
                }
            }
        }
        t++;
        HuPrcVSleep();
    } while (delay[0] >= 0 || delay[1] >= 0 || delay[2] >= 0 || delay[3] >= 0);

    /* Show the new place sprites. */
    for (i = 0, n = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (D_80107850_413CB0_Results[j].rank == i) {
                SprAttrReset(D_801078E4_413D44_Results, n + 1, 0x8000);
                if (_CheckFlag(0xD) != 0) {
                    SprPosSet(D_801078E4_413D44_Results, n + 1, D_801076C4_413B24_Results[RES_ROW_PLACE_D][D_80107850_413CB0_Results[j].place][0],
                              D_801076C4_413B24_Results[RES_ROW_PLACE_D][D_80107850_413CB0_Results[j].place][1]);
                } else {
                    SprPosSet(D_801078E4_413D44_Results, n + 1, D_801076C4_413B24_Results[RES_ROW_PLACE][D_80107850_413CB0_Results[j].place][0],
                              D_801076C4_413B24_Results[RES_ROW_PLACE][D_80107850_413CB0_Results[j].place][1]);
                }
            } else {
                if (_CheckFlag(0xD) != 0) {
                    SprPosSet(D_801078E4_413D44_Results, n + 1, -1000, D_801076C4_413B24_Results[RES_ROW_PLACE_D][j][1]);
                } else {
                    SprPosSet(D_801078E4_413D44_Results, n + 1, -1000, D_801076C4_413B24_Results[RES_ROW_PLACE][j][1]);
                }
            }
            n++;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_70_Results/40EC60", func_801063E8_412848_Results);
#endif

/* Sets up counting the minigame coins (which 0: bonus coins, 1: minigame coins) in steps. */
void func_80107140_4135A0_Results(s16 steps, s32 which) {
    s16 i;
    s16 c;
    f32 f;

    for (i = 0; i < 4; i++) {
        D_80107860_413CC0_Results[i] = gPlayers[i].coins;
        if (which == 0) {
            c = D_80107830_413C90_Results[i];
        } else {
            c = D_80107838_413C98_Results[i];
        }
        if (!((c >= 0) ? (steps < c) : (steps < -c))) {
            if (c >= 0) {
                D_80107DB8_414218_Results[i] = 1;
            } else {
                D_80107DB8_414218_Results[i] = -1;
            }
        } else {
            f = (f32)c / steps;
            if (c >= 0) {
                f += 0.5f;
            } else {
                f -= 0.5f;
            }
            D_80107DB8_414218_Results[i] = f;
        }
        D_80107DC0_414220_Results[i] = 0;
    }
}

// stack slot of the spilled argument (retail 0x14, here above the pad; masked 2)
#ifdef NON_MATCHING
/* One step of counting the coins into the totals; true once every player is done. */
s8 func_801072B0_413710_Results(s32 which) {
    s8 upDone = 0;
    s8 downDone = 0;
    s8 upSound = 0;
    s8 downSound = 0;
    s8 i = 0;
    s8 done = 0;
    s32 goal;
    s32 n;
    s32 pad[4]; /* unused: retail frame size */

    for (; i < 4; i++) {
        if (which == 0) {
            goal = D_80107830_413C90_Results[i];
        } else {
            goal = D_80107838_413C98_Results[i];
        }
        if (D_80107DC0_414220_Results[i] != goal) {
            n = abs(D_80107DC0_414220_Results[i] + D_80107DB8_414218_Results[i]);
            if ((goal >= 0) ? (goal < n) : (-goal < n)) {
                AdjustPlayerCoins(i, goal - D_80107DC0_414220_Results[i]);
                D_80107DC0_414220_Results[i] = goal;
            } else {
                D_80107DC0_414220_Results[i] += D_80107DB8_414218_Results[i];
                AdjustPlayerCoins(i, D_80107DB8_414218_Results[i]);
            }
            if (upDone == 0 && D_80107DB8_414218_Results[i] > 0) {
                if (D_801077FE_413C5E_Results < 2) {
                    upSound = 1;
                }
                upDone = 1;
                if (++D_801077FE_413C5E_Results >= 3) {
                    D_801077FE_413C5E_Results = 0;
                }
            }
            if (downDone == 0 && D_80107DB8_414218_Results[i] < 0) {
                if (D_801077FF_413C5F_Results < 2) {
                    downSound = 1;
                }
                downDone = 1;
                if (++D_801077FF_413C5F_Results >= 3) {
                    D_801077FF_413C5F_Results = 0;
                }
            }
        } else {
            done++;
        }
    }
    if (upSound == 1) {
        PlaySound(9);
    } else if (downSound == 1) {
        PlaySound(0x33C);
    }
    return done > 3;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_70_Results/40EC60", func_801072B0_413710_Results);
#endif

void func_80107544_4139A4_Results(void) {
    s16 i;
    s16 j;

    for (i = 0; i < 4; i++) {
        SprAnimKill(D_80107D18_414178_Results[i]);
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            SprAnimKill(D_80107D58_4141B8_Results[i][j]);
        }
    }
    for (i = 0; i < 4; i++) {
        SprAnimKill(D_80107D38_414198_Results[i]);
    }
    for (i = 0; i < 4; i++) {
        SprKill(D_80107CF0_414150_Results[i]);
    }
}
