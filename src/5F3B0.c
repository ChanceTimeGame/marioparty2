#include "common.h"
#include "game/sprite.h"
#include "game/hmfman.h"
#include "game/gamework.h"
#include "game/board.h"

typedef struct Unk {
    s16 unk_00;
    s16 unk_02;
} Unk;


void SprAttrReset(s16, s16, s32);                        /* extern */
void SprAttrSet(s16, s16, u32);                          /* extern */
void SprPosSet(s16, s16, s16, s16);
void SprScaleSet(s16, s16, f32, f32);
void func_8005E7B0_5F3B0(s32);                         /* extern */
void func_8005F210_5FE10(s32);
void func_8005F2D8_5FED8(s32);
void func_8005F454_60054(s32);
void func_8005F604_60204(s32);
void func_8005F6C0_602C0(s32);
void func_8005F784_60384(s32);
void func_8005F86C_6046C(s32);
void func_80060034_60C34(u32, s32);
void func_800600F8_60CF8(s32, s16, s16);
extern s32 D_800CC990_CD590;
extern s32 D_800CC994_CD594;
extern s16 D_800E1D3E_E293E;
extern f32 D_800E1D44_E2944;
extern s16 D_800FA604_FB204;
extern Vec2f D_800FC990_FD590[];
extern UnkItemSprite2 D_800FC9EC_FD5EC[];
extern Vec2f D_800FD854_FE454[];
extern BoardStatus D_80101510_102110[];
extern Unk D_800CC99C_CD59C[];
extern omObjData* D_800E1D48_E2948[]; /* coin-change objects per player */

s32 func_80059FD0_5ABD0(s32);
void func_8008221C_82E1C(s16, s16, f32);
void func_8008225C_82E5C(s16, s16, s32);
void func_800822A8_82EA8(s16, s16, u16, s32);

/* Board status HUD and versus sprites. C from MP1 src/54120.c / 48D90.c and MP3 ovl_80_shared_board
   106A50.c (MBStatus and MBVs functions); the rest have no reference or differ (near) and stay asm. */

#define MB_MAX_PLAYERS 4

extern s16 D_800CC998_CD598;
extern s16 D_800CC99A_CD59A;
extern Process* D_800E1D20_E2920;
extern s16 D_800E1D40_E2940;
extern s16 D_800E1DD8_E29D8;
extern s16 D_800E1DDA_E29DA;
extern s16 D_800E1DDC_E29DC;
extern s16 D_800E1DDE_E29DE;
extern Process* D_800E1E54_E2A54;
extern s16 D_800E1E58_E2A58;
extern s16 D_800E1E5A_E2A5A;
extern u8 D_800E1E60_E2A60[];
extern s16 D_800E1E80_E2A80;
typedef struct GMesFontMes {
    /* 0x00 */ char unk00[0x20];
    /* 0x20 */ s16 sprId[16];
    /* 0x40 */ s16 unk40[16];
} GMesFontMes; /* MP1 unkCommonStruct0; written by func_8006A608_6B208 */
extern GMesFontMes D_800E1ED4_E2AD4;
extern GMesFontMes D_800E1D60_E2960;
extern GMesFontMes D_800E1DE0_E29E0;
extern s32 D_800CCBC4_CD7C4[];
extern s16 D_800E1EF4_E2AF4;
extern Process* D_800E1F48_E2B48;
extern s16 D_800FD2A2_FDEA2;
extern s16 D_800FD840_FE440;
extern s16 D_800E1D28_E2928[]; /* MP3 D_80105588: status sprite animations */
extern s16 D_800E1D38_E2938;   /* D_800E1D28_E2928[8] */
extern s16 D_800CCAFC_CD6FC[2];
extern s16 D_800F8CE4_F98E4;
extern s32 D_800CCB9C_CD79C[];
extern u8 D_800CCA7C_CD67C[][3]; /* status colours per space type (MP3 RGB D_8010188C) */

extern s32 D_800F8708_F9308;

extern f32 D_800CCB50_CD750[12];
void AdjustPlayerCoins(s32 index, s32 count);
s32 PlaySound(s32);

extern s16 D_800E1D58_E2958;
extern s16 D_800E1D5A_E295A;
extern s16 D_800E1D5C_E295C;
extern s16 D_800E1D5E_E295E;
extern Process* D_800E1DD4_E29D4;

s16 func_8006A608_6B208(void* mes, char* str, u8 arg2, s16 arg3, s16 arg4); /* MP1 GMesFontMesCreate */
void func_8006176C_6236C(void);
void func_800618F8_624F8(void);
void func_80061A68_62668(void);

extern u8 D_800CCB34_CD734[];
extern Unk* D_800CCBAC_CD7AC[];

#define ABS_F(x) (((x) > 0.0f) ? (x) : 0.0f - (x))
void omDelObj(omObjData*);
void func_80060DF8_619F8(omObjData*);

void func_8005FAB4_606B4(void);
void func_8005FCE8_608E8(s32 arg0);
void func_8005FA50_60650(void);
s16 func_80062CCC_638CC(void);
void omPrcSetStatBit(Process* process, s32 value);
void func_80082450_83050(s16 grpIdx, s32 idx, s32 r, s32 g, u8 b);

void* DataRead(s32 dirAndFile);
void DataClose(void* data);
s16 SprCreate(s32, s32);
void SprKill(s16);
void SprAnimKill(s16);
s16 SprAnimRead(void*);
void SprAnimSet(s16, s16, s16, u16);
void SprPrioSet(s16, s16, u16);
void MBStatusAnimKill(void);
void MBStatusItemDispSet(s32, s32);
void MBVsSprKill(void);
void func_8005FEDC_60ADC(s32);
s32 func_80060210_60E10(s32);
void func_8006135C_61F5C(s32 arg0, s32 arg1, s32);
void func_80061BD8_627D8(void);
void func_80061DC4_629C4(void);
void func_80062008_62C08(void);
void func_800622E4_62EE4(void);
void func_80062340_62F40(void);
void func_8006AE14_6BA14(void*);

typedef struct UnkCoinThing {
    u8 unk_00[3];
    char unk_03[5];
    s16 unk_08[2];
} UnkCoinThing;

void func_8005E7B0_5F3B0(s32 arg0) {
    UnkCoinThing coinDigits;
    BoardStatus* temp_s2;
    s32 var_v1;
    s32 i;
    
    temp_s2 = &D_80101510_102110[arg0];
    coinDigits.unk_00[0] = gPlayers[arg0].coins / 100;
    coinDigits.unk_00[1] = gPlayers[arg0].coins / 10 % 10;
    coinDigits.unk_00[2] = gPlayers[arg0].coins % 10;

    if (coinDigits.unk_00[0] == 0) {
        if (coinDigits.unk_00[1] == 0) {
            var_v1 = 1;
        } else {
            var_v1 = 2 | (-(coinDigits.unk_00[0] != 0) & 3);
        }
    } else {
        var_v1 = 2 | (-(coinDigits.unk_00[0] != 0) & 3);
    }
    
    if (var_v1 == 1) {
        SprAttrSet(temp_s2->unk_08, 6, 0x8000);
        coinDigits.unk_00[1] = coinDigits.unk_00[2];
    } else {
        SprAttrReset(temp_s2->unk_08, 6, 0x8000);
    }

    if (coinDigits.unk_00[0] == 0) {
        coinDigits.unk_00[0] = 10;
    }
    for (i = 0; i < 3; i++) {
        func_800822A8_82EA8(temp_s2->unk_08, i + 4, coinDigits.unk_00[i], 0);
        func_8008225C_82E5C(temp_s2->unk_08, i + 4, 1);
    }

    if (gPlayers[arg0].stars > 99) {
        func_800822A8_82EA8(temp_s2->unk_08, 7, 9, 0);
        func_800822A8_82EA8(temp_s2->unk_08, 8, 9, 0);
    } else {
        if (gPlayers[arg0].stars > 9) {
            func_800822A8_82EA8(temp_s2->unk_08, 7, (gPlayers[arg0].stars / 10), 0);
        } else {
            func_800822A8_82EA8(temp_s2->unk_08, 7, 10, 0);
        }
        func_800822A8_82EA8(temp_s2->unk_08, 8, gPlayers[arg0].stars % 10, 0);
    }
    func_8008225C_82E5C(temp_s2->unk_08, 7, 1);
    func_8008225C_82E5C(temp_s2->unk_08, 8, 1);

    coinDigits.unk_08[0] = gPlayers[arg0].coins;
    coinDigits.unk_08[1] = gPlayers[arg0].stars;
    for (i = 0; i < 2; i++) {
        if ((i != 0 && temp_s2->unk_44[i] != coinDigits.unk_08[i]) || (i == 0 && D_800E1D48_E2948[arg0] != 0)) {
            if (temp_s2->unk2[i] == 0) {
                func_8008221C_82E1C(temp_s2->unk_08, i + 2, 1.0f);
                temp_s2->unk2[i] = 0xF;
            }
        }

        if (temp_s2->unk2[i] != 0) {
            temp_s2->unk2[i]--;
            if (temp_s2->unk2[i] == 0) {
                if (i != 0 || D_800E1D48_E2948[arg0] == 0) {
                    func_800822A8_82EA8(temp_s2->unk_08, i + 2, 0U, 0);
                    func_8008221C_82E1C(temp_s2->unk_08, i + 2, 0);
                    func_8008225C_82E5C(temp_s2->unk_08, i + 2, 1);                       
                }
            }
        }
        temp_s2->unk_44[i] = coinDigits.unk_08[i];
    }
    if (temp_s2->unk1 != -1) {
        func_800822A8_82EA8(temp_s2->unk_08, 0xA, temp_s2->unk1, 0);
    } else {
        s32 temp = func_80059FD0_5ABD0(arg0);
        func_800822A8_82EA8(temp_s2->unk_08, 0xA, temp, 0);
    }
    func_8008225C_82E5C(temp_s2->unk_08, 0xA, 1);
    if (_CheckFlag(0xD) != 0) {
        SprAttrSet(temp_s2->unk_08, 7, 0x8000);
        SprAttrSet(temp_s2->unk_08, 8, 0x8000);
        SprAttrSet(temp_s2->unk_08, 3, 0x8000);
    }
}

void func_8005ECB8_5F8B8(void) {
    BoardStatus* sprite;
    s32 i, j;

    for (i = 0; i < 4; i++) {
        sprite = &D_80101510_102110[i];
        for (j = 0; j < 12; j++) {
            SprAttrSet(sprite->unk_08, j, 0x8000);
        }
    }
}

void func_8005ED40_5F940(void) {
    s32 i, j;
    BoardStatus* sprite;

    while (1) {
        if (D_800FDC9C_FE89C == 0) {
            for (i = 0; i < 4; i++) {
                if (D_800CC990_CD590 != -1) {
                    if ((D_800CC994_CD594 != -1) && (i != D_800CC990_CD590) && (i != D_800CC994_CD594)) {
                        continue;
                    }
                }
                
                sprite = &D_80101510_102110[i];
                if (sprite->unk_00 == 0) {
                    if (sprite->unk_06 & 1) {
                        for (j = 0; j < 12; j++) {
                            SprAttrSet(sprite->unk_08, j, 0x8000);
                        }
                        continue;
                    } else {
                        for (j = 0; j < 12; j++) {
                            SprAttrReset(sprite->unk_08, j, 0x8000);
                        }
                        if ((gPlayers[i].flags & 1) && !(sprite->unk_06 & 1)) {
                            SprAttrReset(sprite->unk_08, 9, 0x8000);
                        } else {
                            SprAttrSet(sprite->unk_08, 9, 0x8000);
                        }

                        if ((gPlayers[i].item != -1) && !(sprite->unk_06 & 1)) {
                            SprAttrReset(sprite->unk_08, 0xB, 0x8000);
                        } else {
                            SprAttrSet(sprite->unk_08, 0xB, 0x8000);
                        }
                        func_8005E7B0_5F3B0(i);
                    }
                } else {
                    if (sprite->unk_06 & 1) {
                        for (j = 0; j < 3; j++) {
                            SprAttrSet(sprite->unk_08, j, 0x8000);
                        }
                        SprAttrSet(sprite->unk_08, 9, 0x8000);
                        continue;
                    } else {
                        for (j = 0; j < 2; j++) {
                            SprAttrReset(sprite->unk_08, j, 0x8000);
                        }
                        if (sprite->unk_36 != -1) {
                            SprAttrReset(sprite->unk_08, j, 0x8000);
                        }
                        if ((gPlayers[i].flags) & 1 && !(sprite->unk_06 & 1)) {
                            SprAttrReset(sprite->unk_08, 9, 0x8000);
                        } else {
                            SprAttrSet(sprite->unk_08, 9, 0x8000);
                        }
                    }
                }
                if (sprite->unk_0C > 0) {
                    sprite->unk_0C--;
                    sprite->xPos += sprite->unk_20;
                    sprite->yPos += sprite->unk_24;
                    sprite->unk_20 += sprite->unk_28;
                    sprite->unk_24 += sprite->unk_2C;
                } else if (sprite->unk_0C == -1) {
                    sprite->unk_0C = -2;
                } else if (sprite->unk_0C != -2) {
                    sprite->xPos = sprite->unk_18;
                    sprite->yPos = sprite->unk_1C;
                    sprite->unk_0C = -1;
                }
                SprPosSet(sprite->unk_08, 0, ((s32) (sprite->xPos + 0.5f) + 56), ((s32) (sprite->yPos + 0.5f) + 19));     
            }
            if (D_800E1D3E_E293E != -1) {
                D_800E1D44_E2944 += 0.1f;
                if (D_800E1D44_E2944 > 1.0f) {
                    D_800E1D44_E2944 = 1.0f;
                }
                SprScaleSet(D_800E1D3E_E293E, 0, D_800E1D44_E2944, D_800E1D44_E2944);
                if (D_800FA604_FB204 > 0) {
                    D_800FA604_FB204--;
                    D_800FC9EC_FD5EC[0].unk_00 += D_800FD854_FE454[0].unk_00;
                    D_800FC9EC_FD5EC[0].unk_04 += D_800FD854_FE454[0].unk_04;
                    D_800FD854_FE454[0].unk_00 += D_800FC990_FD590[0].unk_00;
                    D_800FD854_FE454[0].unk_04 += D_800FC990_FD590[0].unk_04;
                    SprPosSet(D_800E1D3E_E293E, 0, D_800FC9EC_FD5EC[0].unk_00, D_800FC9EC_FD5EC[0].unk_04);
                }
            }
        }
        HuPrcVSleep();
    }
}

INCLUDE_ASM("asm/nonmatchings/5F3B0", func_8005F210_5FE10);

INCLUDE_ASM("asm/nonmatchings/5F3B0", func_8005F2D8_5FED8);

INCLUDE_ASM("asm/nonmatchings/5F3B0", func_8005F454_60054);

/* MP3 MBStatusBackSprCreate */
void func_8005F604_60204(s32 playerNo) {
    BoardStatus* temp_s0 = &D_80101510_102110[playerNo];
    s16 temp_v0 = SprCreate(0xC, 5);

    temp_s0->unk_08 = temp_v0;
    SprAnimSet(temp_v0, 0, D_800E1D28_E2928[0], 0);
    SprPrioSet(temp_v0, 0, ((playerNo * 5) + 0x4790));
    SprAttrSet(temp_v0, 0, 0x1000);
    SprPosSet(temp_v0, 0, 0, 0);
}

/* MP3 MBStatusRankSprCreate */
void func_8005F6C0_602C0(s32 playerNo) {
    BoardStatus* temp_v0 = &D_80101510_102110[playerNo];
    s16 temp_s0;

    temp_s0 = temp_v0->unk_08;
    SprAnimSet(temp_s0, 0xA, D_800E1D38_E2938, 0);
    func_8008225C_82E5C(temp_s0, 0xA, 1);
    func_800822A8_82EA8(temp_s0, 0xA, 0, 0);
    SprPrioSet(temp_s0, 0xA, ((playerNo * 5) + 0x478F));
    SprAttrSet(temp_s0, 0xA, 0x1000);
    SprPosSet(temp_s0, 0xA, D_800CCAFC_CD6FC[0], D_800CCAFC_CD6FC[1]);
}

INCLUDE_ASM("asm/nonmatchings/5F3B0", func_8005F784_60384);

INCLUDE_ASM("asm/nonmatchings/5F3B0", func_8005F86C_6046C);

void func_8005F954_60554(void) {
    void* data;

    if (D_800CC998_CD598 == -1) {
        D_800CC998_CD598 = SprCreate(1, 5);
    }
    data = DataRead(D_800CCB9C_CD79C[D_800F8CE4_F98E4]);
    if (D_800CC99A_CD59A == -1) {
        D_800CC99A_CD59A = SprAnimRead(data);
    }
    DataClose(data);
    SprAnimSet(D_800CC998_CD598, 0, D_800CC99A_CD59A, 0);
    func_8008225C_82E5C(D_800CC998_CD598, 0, 1);
    SprPrioSet(D_800CC998_CD598, 0, 0x4790);
    SprAttrSet(D_800CC998_CD598, 0, 0x1000);
    SprPosSet(D_800CC998_CD598, 0, 0xA0, 0x24);
}

void func_8005FA50_60650(void) {
    if (D_800CC99A_CD59A != -1) {
        SprAnimKill(D_800CC99A_CD59A);
        D_800CC99A_CD59A = -1;
    }
    if (D_800CC998_CD598 != -1) {
        SprKill(D_800CC998_CD598);
        D_800CC998_CD598 = -1;
    }
}

INCLUDE_ASM("asm/nonmatchings/5F3B0", func_8005FAB4_606B4);

void MBStatusAnimKill(void) {
    s32 i;
    s16* spriteIDs = D_800E1D28_E2928;

    SprAnimKill(spriteIDs[0]);
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        SprAnimKill(spriteIDs[i + 1]);
    }

    for (i = 0; i < 2; i++) {
        SprAnimKill(spriteIDs[i + 5]);
    }

    SprAnimKill(spriteIDs[8]);
    SprAnimKill(spriteIDs[9]);
    SprAnimKill(spriteIDs[10]);
}

void func_8005FCE8_608E8(s32 arg0) {
    BoardStatus* sprite;
    s32 i;

    sprite = &D_80101510_102110[arg0];
    for (i = 0; i < 2; i++) {
        sprite->unk2[i] = 0;
    }

    sprite->unk_44[0] = gPlayers[arg0].coins;
    sprite->unk_44[1] = gPlayers[arg0].stars;
    sprite->unk_06 = 0;
    sprite->unk1 = -1;
    sprite->unk_00 = 0;
    func_8005F604_60204(arg0);
    func_80060034_60C34(arg0, 0);
    func_800600F8_60CF8(arg0, D_800CC99C_CD59C[arg0].unk_00, D_800CC99C_CD59C[arg0].unk_02);
    func_8005F210_5FE10(arg0);
    func_8005F2D8_5FED8(arg0);
    func_8005F454_60054(arg0);
    func_8005F6C0_602C0(arg0);
    func_8005F784_60384(arg0);
    func_8005F86C_6046C(arg0);
    func_8005E7B0_5F3B0(arg0);
    D_800E1D48_E2948[arg0] = 0;
    sprite->unk30 = NULL;
}

void func_8005FE10_60A10(void) {
    s32 i;

    func_8005FAB4_606B4();
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        func_8005FCE8_608E8(i);
    }
    D_800E1D20_E2920 = omAddPrcObj(func_8005ED40_5F940, 0, 0x2000, 0);
    omPrcSetStatBit(D_800E1D20_E2920, 0x80);
    D_800E1D40_E2940 = -1;
    D_800E1D3E_E293E = -1;
    D_800CC990_CD590 = -1;
    D_800CC994_CD594 = -1;
    if (GwSystem.current_board_index == 2 && func_80062CCC_638CC() == 0 && _CheckFlag(0x17) != 0) {
        func_8005F954_60554();
    }
}

INCLUDE_ASM("asm/nonmatchings/5F3B0", func_8005FEDC_60ADC);

void func_8005FF9C_60B9C(void) {
    s32 i;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        func_8005FEDC_60ADC(i);
    }

    MBStatusAnimKill();
    HuPrcKill(D_800E1D20_E2920);
    MBVsSprKill();
    D_800CC990_CD590 = -1;
    D_800CC994_CD594 = -1;
    if (GwSystem.current_board_index == 2 && func_80062CCC_638CC() == 0) {
        func_8005FA50_60650();
    }
}

/* MP3 MBStatusColorSet */
void func_80060034_60C34(u32 playerNo, s32 turnStatus) {
    if (playerNo < MB_MAX_PLAYERS) {
        func_80082450_83050(D_80101510_102110[playerNo].unk_08, 0, D_800CCA7C_CD67C[turnStatus][0], D_800CCA7C_CD67C[turnStatus][1], D_800CCA7C_CD67C[turnStatus][2]);
        D_80101510_102110[playerNo].spaceType = turnStatus;
    }
}

INCLUDE_ASM("asm/nonmatchings/5F3B0", func_800600C0_60CC0);

INCLUDE_ASM("asm/nonmatchings/5F3B0", func_800600DC_60CDC);

/* MP3 MBStatusPosSet */
void func_800600F8_60CF8(s32 playerIndex, s16 arg1, s16 arg2) {
    BoardStatus* boardStatus;

    boardStatus = &D_80101510_102110[playerIndex];
    boardStatus->unk_18 = arg1;
    boardStatus->xPos = arg1;
    boardStatus->unk_1C = arg2;
    boardStatus->yPos = arg2;
    boardStatus->unk_20 = boardStatus->unk_24 = 0;
    boardStatus->unk_0C = -2;
    SprPosSet(boardStatus->unk_08, 0, arg1 + 0x38, arg2 + 0x13);
}

void HidePlayerHUDVisibility(s32 arg0, s32 arg1) {
    func_800600F8_60CF8(arg0, D_800CC99C_CD59C[arg1 * 4 + arg0].unk_00, D_800CC99C_CD59C[arg1 * 4 + arg0].unk_02);
}

void func_800601DC_60DDC(s32 arg0, s32 arg1) {
    func_800600F8_60CF8(arg0, D_800CC99C_CD59C[arg1].unk_00, D_800CC99C_CD59C[arg1].unk_02);
}

/* MP1 func_80054868: start the status windows' move for a layout (arg0) and set teams */
s32 func_80060210_60E10(s32 arg0) {
    u8 order[5];
    u8 blue[5];
    u8 red[4];
    u8 nblue = 0;
    u8 nred = 0;
    u8 n;
    BoardStatus* p;
    s32 i;

    if (arg0 == 2) {
        n = 0;
        nblue = nred;
        for (i = 0; i < 4; i++) {
            switch (D_80101510_102110[i].spaceType) {
                case 1:
                    blue[nblue++] = i;
                    break;
                case 2:
                    red[nred++] = i;
                    break;
                default:
                    n++;
                    break;
            }
        }
        if (n != 0) {
            for (i = 0; i < 5; i++) {
                blue[i] = i;
            }
            nblue = 5;
            nred = 0;
        }
        n = 0;
        for (i = 0; i < nblue; i++) {
            order[blue[i]] = n++;
        }
        for (i = 0; i < nred; i++) {
            order[red[i]] = n++;
        }
    }

    for (i = 0; i < 4; i++) {
        p = &D_80101510_102110[i];
        if (arg0 >= 10 && arg0 < 14 && i != arg0 - 10) {
            continue;
        }
        if (arg0 >= 14 && arg0 < 18 && i != arg0 - 14) {
            continue;
        }
        if (arg0 >= 18 && arg0 < 22 && i != arg0 - 18) {
            continue;
        }
        if (arg0 == 22 && i != D_800CC990_CD590) {
            continue;
        }
        if (arg0 == 23 && i != D_800CC994_CD594) {
            continue;
        }
        if (arg0 == 24 && i != D_800CC994_CD594) {
            continue;
        }
        switch (arg0) {
            case 0:
            case 10:
            case 11:
            case 12:
            case 13:
                func_800600F8_60CF8(i, D_800CC99C_CD59C[i + 4].unk_00, D_800CC99C_CD59C[i + 4].unk_02);
                break;
            case 22:
                func_800600F8_60CF8(D_800CC990_CD590, D_800CC99C_CD59C[4].unk_00, D_800CC99C_CD59C[4].unk_02);
                break;
            case 23:
                func_800600F8_60CF8(D_800CC994_CD594, D_800CC99C_CD59C[7].unk_00, D_800CC99C_CD59C[7].unk_02);
                break;
            case 24:
                func_800600F8_60CF8(D_800CC994_CD594, D_800CC99C_CD59C[5].unk_00, D_800CC99C_CD59C[5].unk_02);
                break;
        }
        p->unk_0C = 19;
        switch (arg0) {
            case 25:
            case 26:
                p->unk_0C = 5;
                goto block;
            case 6:
            case 7:
            case 8:
            case 9:
                p->unk_0C = 15;
            case 0:
            case 1:
            case 3:
            case 4:
            case 10:
            case 11:
            case 12:
            case 13:
            block:
                p->unk_18 = D_800CC99C_CD59C[D_800CCB34_CD734[arg0] + i].unk_00;
                p->unk_1C = D_800CC99C_CD59C[D_800CCB34_CD734[arg0] + i].unk_02;
                break;
            case 2:
                p->unk_18 = D_800CCBAC_CD7AC[nblue][order[i]].unk_00;
                p->unk_1C = D_800CCBAC_CD7AC[nblue][order[i]].unk_02;
                p->unk_0C = 9;
                break;
            case 5:
                if (160.0f <= p->xPos) {
                    p->unk_18 = p->xPos + 1920.0f;
                } else {
                    p->unk_18 = p->xPos - 1920.0f;
                }
                p->unk_1C = p->yPos;
                p->unk_0C = 19;
                break;
            case 14:
            case 15:
            case 16:
            case 17:
            case 18:
            case 19:
            case 20:
            case 21:
                p->unk_18 = D_800CC99C_CD59C[D_800CCB34_CD734[arg0] + i].unk_00;
                p->unk_1C = p->yPos;
                break;
            case 22:
                p->unk_18 = D_800CC99C_CD59C[0].unk_00;
                p->unk_1C = D_800CC99C_CD59C[0].unk_02;
                break;
            case 23:
                p->unk_18 = D_800CC99C_CD59C[3].unk_00;
                p->unk_1C = D_800CC99C_CD59C[3].unk_02;
                break;
            case 24:
                p->unk_18 = D_800CC99C_CD59C[1].unk_00;
                p->unk_1C = D_800CC99C_CD59C[1].unk_02;
                break;
        }
        p->unk_20 = p->unk_28 = (2.0f * (p->unk_18 - p->xPos)) / ((p->unk_0C + 1) * (p->unk_0C + 1));
        p->unk_24 = p->unk_2C = (2.0f * (p->unk_1C - p->yPos)) / ((p->unk_0C + 1) * (p->unk_0C + 1));
        if (arg0 == 5) {
            D_800FD854_FE454[0].unk_00 = D_800FC990_FD590[0].unk_00 = 0.0f;
            D_800FD854_FE454[0].unk_04 = D_800FC990_FD590[0].unk_04 = 2.0f;
            D_800FA604_FB204 = p->unk_0C;
        }
    }

    if ((arg0 == 2) & (nblue != 5)) {
        if (nblue == 4 || nblue == 0) {
            for (i = 0; i < 4; i++) {
                gPlayers[i].group = i;
            }
        } else if (nblue == 3) {
            for (i = 0; i < nblue; i++) {
                gPlayers[blue[i]].group = 1;
            }
            for (i = 0; i < nred; i++) {
                gPlayers[red[i]].group = 0;
            }
        } else {
            for (i = 0; i < nblue; i++) {
                gPlayers[blue[i]].group = 0;
            }
            for (i = 0; i < nred; i++) {
                gPlayers[red[i]].group = 1;
            }
        }
    }
    if (arg0 == 6 || arg0 == 7 || arg0 == 8 || arg0 == 9) {
        for (i = 0; i < 4; i++) {
            if (i == arg0 - 6) {
                gPlayers[i].group = 0;
            } else {
                gPlayers[i].group = 1;
            }
        }
    }
    return 0;
}

s32 func_800609D8_615D8(void) {
    s32 var_a0 = FALSE;
    s32 i;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        if (D_80101510_102110[i].unk_0C != -2) {
            var_a0 = TRUE;
        }
    }
    return var_a0;
}

s32 func_80060A1C_6161C(void) {
    u8 type1Indices[4];
    u8 type2Indices[4];
    u8 otherCount = 0;
    u8 redCount = 0;
    u8 blueCount = 0;
    s32 i;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        switch (D_80101510_102110[i].spaceType) {
            case 1:
                type1Indices[blueCount++] = i;
                break;
            case 2:
                type2Indices[redCount++] = i;
                break;
            default:
                otherCount++;
        }
    }

    if (otherCount > 0) {
        return -1;
    }

    if (blueCount == 0 || blueCount == 4) {
        return 0;
    }

    if (blueCount == 1) {
        D_800F8708_F9308 = type1Indices[0];
        return 1;
    }

    if (blueCount == 3) {
        D_800F8708_F9308 = type2Indices[0];
        return 1;
    }

    return 2;
}

/* MP3 MBVsSprCreate */
void func_80060B04_61704(void) {
    void* temp_s0;

    if (D_800E1D3E_E293E == -1) {
        D_800E1D3E_E293E = SprCreate(1, 5);
        temp_s0 = DataRead(0xA0160);
        D_800FC9EC_FD5EC[0].unk_04 = 158.0f;
        D_800E1D40_E2940 = SprAnimRead(temp_s0);
        DataClose(temp_s0);
        SprAnimSet(D_800E1D3E_E293E, 0, D_800E1D40_E2940, 0);
        SprPrioSet(D_800E1D3E_E293E, 0, 0x4780);
        SprAttrSet(D_800E1D3E_E293E, 0, 0x1000);
        SprPosSet(D_800E1D3E_E293E, 0, 0xA0, D_800FC9EC_FD5EC[0].unk_04);
        SprScaleSet(D_800E1D3E_E293E, 0, 0.0f, 0.0f);
        D_800E1D44_E2944 = 0.0f;
        D_800FC9EC_FD5EC[0].unk_00 = 160.0f;
        D_800FD854_FE454[0].unk_00 = D_800FD854_FE454[0].unk_04 = 0.0f;
        D_800FA604_FB204 = 0;
    }
}

void MBVsSprCreateY(f32 arg0, f32 arg1) {
    void *temp_s0;

    if (D_800E1D3E_E293E == -1) {
        D_800E1D3E_E293E = SprCreate(1, 5);
        temp_s0 = DataRead(0xA0160);
        D_800FC9EC_FD5EC[0].unk_04 = arg1;
        D_800E1D40_E2940 = SprAnimRead(temp_s0);
        DataClose(temp_s0);
        SprAnimSet(D_800E1D3E_E293E, 0, D_800E1D40_E2940, 0);
        SprPrioSet(D_800E1D3E_E293E, 0, 0x4780);
        SprAttrSet(D_800E1D3E_E293E, 0, 0x1000);
        SprPosSet(D_800E1D3E_E293E, 0, 0xA0, D_800FC9EC_FD5EC[0].unk_04);
        SprScaleSet(D_800E1D3E_E293E, 0, 0.0f, 0.0f);
        D_800E1D44_E2944 = 0.0f;
        D_800FC9EC_FD5EC[0].unk_00 = arg0;
        D_800FD854_FE454[0].unk_00 = D_800FD854_FE454[0].unk_04 = 0.0f;
        D_800FA604_FB204 = 0;
    }
}

void MBVsSprKill(void) {
    if (D_800E1D3E_E293E != -1) {
        SprKill(D_800E1D3E_E293E);
        D_800E1D3E_E293E = -1;
    }
    if (D_800E1D40_E2940 != -1) {
        SprAnimKill(D_800E1D40_E2940);
        D_800E1D40_E2940 = -1;
    }
}

INCLUDE_ASM("asm/nonmatchings/5F3B0", func_80060DF8_619F8);

void func_80060F90_61B90(s32 arg0) {
    omObjData* temp_v0;
    BoardStatus* temp_s0;
    s32 i;
    s32 j;

    temp_s0 = &D_80101510_102110[arg0];
    if (temp_s0->unk30 == NULL) {
        temp_v0 = omAddObj(-0x8000, 0, 0, -1, &func_80060DF8_619F8);
        temp_s0->unk30 = temp_v0;
        temp_v0->rot.x = 0.0f;
        temp_v0->work[0] = arg0;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 12; j++) {
                SprScaleSet(D_80101510_102110[i].unk_08, j, D_800CCB50_CD750[j], D_800CCB50_CD750[j]);
            }
        }
    }
}

void func_80061078_61C78(s32 arg0) {
    BoardStatus* temp_s1;
    s32 i;

    temp_s1 = &D_80101510_102110[arg0];

    if (temp_s1->unk30 != NULL) {
        omDelObj(temp_s1->unk30);
        temp_s1->unk30 = NULL;
        for (i = 0; i < 12; i++) {
            SprScaleSet(temp_s1->unk_08, i, D_800CCB50_CD750[i], D_800CCB50_CD750[i]);
        }
    }
}

void func_8006110C_61D0C(omObjData* arg0) {
    u32 var_s1 = 0;

    while (arg0->scale.y <= 0.0f) {
        if (arg0->trans.x > 0.0f) {
            AdjustPlayerCoins(arg0->work[0], 1);
            if (((arg0->work[3] != 0) & (var_s1 == 0)) && (arg0->scale.z >= 3.0f)) {
                PlaySound(0x32B);
                var_s1 = 1;
                arg0->scale.z -= 3.0f;
            }

            arg0->trans.x -= 1.0f;

        } else {
            AdjustPlayerCoins(arg0->work[0], -1);
            arg0->trans.x += 1.0f;

            if (arg0->work[3] != 0) {
                if ((var_s1 == 0) && (arg0->scale.z >= 3.0f)) {
                    PlaySound(0x33C);
                    var_s1 = 1;
                    arg0->scale.z -= 3.0f;
                }
                if (arg0->trans.x == 0.0f || gPlayers[arg0->work[0]].coins == 0) {
                    PlaySound(0x33D);
                }
            }
        }

        if (arg0->trans.x == 0.0f || gPlayers[arg0->work[0]].coins == 0) {
            D_800E1D48_E2948[arg0->work[0]] = NULL;
            omDelObj(arg0);
            return;
        }

        arg0->scale.y += arg0->scale.x;
    }
    arg0->scale.y = arg0->scale.y - 1.0f;
    arg0->scale.z = arg0->scale.z + 2.0f;
}

void func_8006135C_61F5C(s32 arg0, s32 arg1, s32 arg2) {
    if (arg1 != 0) {
        if (D_800E1D48_E2948[arg0] != NULL) {
            AdjustPlayerCoins(arg0, arg1);
            return;
        }
        if (((gPlayers[arg0].coins == 0) & (arg1 < 0)) == 0) {
            D_800E1D48_E2948[arg0] = omAddObj(-0x8000, 0, 0, -1, func_8006110C_61D0C);
            D_800E1D48_E2948[arg0]->work[0] = arg0;
            D_800E1D48_E2948[arg0]->trans.x = arg1;
            D_800E1D48_E2948[arg0]->scale.x = 30.0f / ABS_F((f32)arg1);
            D_800E1D48_E2948[arg0]->scale.y = 0.0f;
            D_800E1D48_E2948[arg0]->scale.z = 3.0f;
            D_800E1D48_E2948[arg0]->work[3] = arg2;
        }
    }
}

void func_800614B4_620B4(s32 arg0, s32 arg1) {
    func_8006135C_61F5C(arg0, arg1, 1);
}

s32 func_800614D0_620D0(s32 arg0) {
    if (D_800E1D48_E2948[arg0] != 0) {
        return 1;
    } else {
        return 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/5F3B0", func_800614E8_620E8);

INCLUDE_ASM("asm/nonmatchings/5F3B0", func_80061504_62104);

INCLUDE_ASM("asm/nonmatchings/5F3B0", func_80061518_62118);

INCLUDE_ASM("asm/nonmatchings/5F3B0", func_80061584_62184);

INCLUDE_ASM("asm/nonmatchings/5F3B0", func_800615F0_621F0);

void func_800615FC_621FC(void) {
    s32 i;

    func_8005FAB4_606B4();
    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        func_8005FCE8_608E8(i);
        func_800600F8_60CF8(i, D_800CC99C_CD59C[i + 4].unk_00, D_800CC99C_CD59C[i + 4].unk_02);
        func_80060034_60C34(i, (u8)gPlayers[i].player_space_color);
    }

    D_800E1D20_E2920 = omAddPrcObj(func_8005ED40_5F940, 0, 0x2000, 0);
    omPrcSetStatBit(D_800E1D20_E2920, 0x80);
    D_800E1D40_E2940 = -1;
    D_800E1D3E_E293E = -1;
}

void func_800616C4_622C4(void) {
    func_8005FEDC_60ADC(D_800CC990_CD590);
    func_8005FEDC_60ADC(D_800CC994_CD594);
    MBStatusAnimKill();
    HuPrcKill(D_800E1D20_E2920);
    MBVsSprKill();
    D_800CC990_CD590 = -1;
    D_800CC994_CD594 = -1;
}

INCLUDE_ASM("asm/nonmatchings/5F3B0", func_80061720_62320);

void func_80061734_62334(void) {
    func_80060210_60E10(0x16);
}

void func_80061750_62350(void) {
    func_80060210_60E10(0x17);
}

void func_8006176C_6236C(void) {
    s32 i;

    while (1) {
        if ((D_800FD2A2_FDEA2 == -1) || (D_800FD840_FE440 == -1)) {
            SprAttrSet(D_800E1E58_E2A58, 0, 0x8000);
            SprAttrSet(D_800E1E58_E2A58, 1, 0x8000);
            
            for (i = 0; i < 5; i++) {
                SprAttrSet(D_800E1E80_E2A80, i + 1, 0x8000);
            }
            
            SprAttrSet(D_800E1EF4_E2AF4, 1, 0x8000);
        } else {
            SprAttrReset(D_800E1E58_E2A58, 0, 0x8000);
            SprAttrReset(D_800E1E58_E2A58, 1, 0x8000);
            for (i = 0; i < 5; i++) {
                SprAttrReset(D_800E1E80_E2A80, i + 1, 0x8000);
            }
            SprAttrReset(D_800E1EF4_E2AF4, 1, 0x8000);
            func_8008225C_82E5C(D_800E1E58_E2A58, 0, 1);
            func_800822A8_82EA8(D_800E1E58_E2A58, 0, (u16) D_800FD2A2_FDEA2, 0);
            func_8008225C_82E5C(D_800E1E58_E2A58, 1, 1);
            func_800822A8_82EA8(D_800E1E58_E2A58, 1, (u16) D_800FD840_FE440, 0);
        }
        HuPrcVSleep();        
    }
}

INCLUDE_ASM("asm/nonmatchings/5F3B0", func_800618F8_624F8);

INCLUDE_ASM("asm/nonmatchings/5F3B0", func_80061A68_62668);

void func_80061BD8_627D8(void) {
    void* file;
    s32 i;

    func_8006A608_6B208(D_800E1E60_E2A60, "WORLD", 0, -1, -1);
    SprPosSet(D_800E1E80_E2A80, 0, 0xA0, 0x18);
    for (i = 1; i < 6; i++) {
        SprPrioSet(D_800E1E80_E2A80, i, 0xA);
    }
    func_8006A608_6B208(&D_800E1ED4_E2AD4, "=", 0, -1, -1);
    SprPosSet(D_800E1ED4_E2AD4.sprId[0], 0, 0xA0, 0x28);
    SprPrioSet(D_800E1ED4_E2AD4.sprId[0], 1, 0xA);
    file = DataRead(0x38);
    D_800E1E5A_E2A5A = SprAnimRead(file);
    DataClose(file);
    D_800E1E58_E2A58 = SprCreate(2, 5);

    for (i = 0; i < 2; i++) {
        SprAnimSet(D_800E1E58_E2A58, i, D_800E1E5A_E2A5A, 0);
        func_8008225C_82E5C(D_800E1E58_E2A58, i, 1);
        SprPrioSet(D_800E1E58_E2A58, i, 0xA);
        SprAttrSet(D_800E1E58_E2A58, i, 0x1000);
        if (i == 0) {
            SprPosSet(D_800E1E58_E2A58, 0, 0x90, 0x28);
        } else {
            SprPosSet(D_800E1E58_E2A58, i, 0x20, 0);
        }
    }

    D_800E1F48_E2B48 = omAddPrcObj(func_8006176C_6236C, 0, 0, 0);
    omPrcSetStatBit(D_800E1F48_E2B48, 0x80);
}

void func_80061DC4_629C4(void) {
    void* file;
    s32 i;

    D_800E1D58_E2958 = SprCreate(1, 5);
    SprPosSet(D_800E1D58_E2958, 0, 0x22, 0x1A);
    file = DataRead(D_800CCBC4_CD7C4[(s8)D_800FD8A8_FE4A8.unk00]);
    D_800E1D5A_E295A = SprAnimRead(file);
    DataClose(file);
    SprAnimSet(D_800E1D58_E2958, 0, D_800E1D5A_E295A, 0);
    func_8008225C_82E5C(D_800E1D58_E2958, 0, 1);
    SprPrioSet(D_800E1D58_E2958, 0, 0x10);
    SprAttrSet(D_800E1D58_E2958, 0, 0x1000);
    func_8006A608_6B208(&D_800E1D60_E2960, "X", 0, -1, -1);
    SprPosSet(D_800E1D60_E2960.sprId[0], 0, 0x32, 0x1A);
    SprPrioSet(D_800E1D60_E2960.sprId[0], 1, 0xA);
    file = DataRead(0x38);
    D_800E1D5E_E295E = SprAnimRead(file);
    DataClose(file);
    D_800E1D5C_E295C = SprCreate(2, 5);

    for (i = 0; i < 2; i++) {
        SprAnimSet(D_800E1D5C_E295C, i, D_800E1D5E_E295E, 0);
        func_8008225C_82E5C(D_800E1D5C_E295C, i, 1);
        SprPrioSet(D_800E1D5C_E295C, i, 0xA);
        SprAttrSet(D_800E1D5C_E295C, i, 0x1000);
        if (i == 0) {
            SprPosSet(D_800E1D5C_E295C, 0, 0x42, 0x1A);
        } else {
            SprPosSet(D_800E1D5C_E295C, i, i * 16, 0);
        }
    }

    D_800E1DD4_E29D4 = omAddPrcObj(func_800618F8_624F8, 0, 0, 0);
    omPrcSetStatBit(D_800E1DD4_E29D4, 0x80);
}

void func_80062008_62C08(void) {
    void* file;
    s32 i;

    file = DataRead(0xA0010);
    D_800E1DDE_E29DE = SprAnimRead(file);
    DataClose(file);
    D_800E1DDC_E29DC = SprCreate(1, 5);
    SprAnimSet(D_800E1DDC_E29DC, 0, D_800E1DDE_E29DE, 0);
    func_8008225C_82E5C(D_800E1DDC_E29DC, 0, 1);
    SprPrioSet(D_800E1DDC_E29DC, 0, 0x11);
    SprAttrSet(D_800E1DDC_E29DC, 0, 0x1000);
    SprScaleSet(D_800E1DDC_E29DC, 0, 0.5f, 0.5f);
    SprPosSet(D_800E1DDC_E29DC, 0, 0xF0, 0x1A);
    func_8008221C_82E1C(D_800E1DDC_E29DC, 0, 0.0f);
    func_8006A608_6B208(&D_800E1DE0_E29E0, "X", 0, -1, -1);
    SprPosSet(D_800E1DE0_E29E0.sprId[0], 0, 0x100, 0x1A);
    SprPrioSet(D_800E1DE0_E29E0.sprId[0], 1, 0xA);
    file = DataRead(0x38);
    D_800E1DDA_E29DA = SprAnimRead(file);
    DataClose(file);
    D_800E1DD8_E29D8 = SprCreate(2, 5);

    for (i = 0; i < 2; i++) {
        SprAnimSet(D_800E1DD8_E29D8, i, D_800E1DDA_E29DA, 0);
        func_8008225C_82E5C(D_800E1DD8_E29D8, i, 1);
        SprPrioSet(D_800E1DD8_E29D8, i, 0xA);
        SprAttrSet(D_800E1DD8_E29D8, i, 0x1000);
        if (i == 0) {
            SprPosSet(D_800E1DD8_E29D8, 0, 0x110, 0x1A);
        } else {
            SprPosSet(D_800E1DD8_E29D8, i, i * 16, 0);
        }
    }

    D_800E1E54_E2A54 = omAddPrcObj(func_80061A68_62668, 0, 0, 0);
    omPrcSetStatBit(D_800E1E54_E2A54, 0x80);
}

void func_80062268_62E68(void) {
    func_80061DC4_629C4();
    func_80062008_62C08();
    func_80061BD8_627D8();
}

void func_80062294_62E94(void) {
    func_8006AE14_6BA14(D_800E1E60_E2A60);
    func_8006AE14_6BA14(&D_800E1ED4_E2AD4);
    SprAnimKill(D_800E1E5A_E2A5A);
    SprKill(D_800E1E58_E2A58);
    omDelPrcObj(D_800E1F48_E2B48);
}

void func_800622E4_62EE4(void) {
    SprAnimKill(D_800E1D5A_E295A);
    SprKill(D_800E1D58_E2958);
    func_8006AE14_6BA14(&D_800E1D60_E2960);
    SprAnimKill(D_800E1D5E_E295E);
    SprKill(D_800E1D5C_E295C);
    omDelPrcObj(D_800E1DD4_E29D4);
}

void func_80062340_62F40(void) {
    func_8006AE14_6BA14(&D_800E1DE0_E29E0);
    SprAnimKill(D_800E1DDA_E29DA);
    SprKill(D_800E1DD8_E29D8);
    SprAnimKill(D_800E1DDE_E29DE);
    SprKill(D_800E1DDC_E29DC);
    omDelPrcObj(D_800E1E54_E2A54);
}

void func_8006239C_62F9C(void) {
    func_800622E4_62EE4();
    func_80062340_62F40();
    func_80062294_62E94();
}

INCLUDE_ASM("asm/nonmatchings/5F3B0", func_800623C8_62FC8);

INCLUDE_ASM("asm/nonmatchings/5F3B0", func_80062588_63188);

INCLUDE_ASM("asm/nonmatchings/5F3B0", MBStatusItemDispSet);

void MBStatusItemDispSetAll(s32 arg0) {
    s32 i;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        MBStatusItemDispSet(i, arg0);
    }
}

INCLUDE_ASM("asm/nonmatchings/5F3B0", func_8006286C_6346C);

void MBStatusSprPosGet(s16 arg0, s16 arg1, f32 *arg2, f32 *arg3) {
    HuSprite *sprite = HuSprGrpData[arg0]->members[arg1];

    *arg2 = sprite->unk_48;
    *arg3 = sprite->unk_4C;
}

INCLUDE_ASM("asm/nonmatchings/5F3B0", func_800628C0_634C0);

INCLUDE_ASM("asm/nonmatchings/5F3B0", func_8006296C_6356C);

INCLUDE_ASM("asm/nonmatchings/5F3B0", func_800629AC_635AC);

INCLUDE_ASM("asm/nonmatchings/5F3B0", func_800629F0_635F0);

INCLUDE_ASM("asm/nonmatchings/5F3B0", func_80062A28_63628);
