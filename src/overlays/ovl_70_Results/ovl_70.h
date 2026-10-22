#ifndef OVL_70_H
#define OVL_70_H

#include "common.h"
#include "game/gamemes.h"
#include "game/sprite.h"
#include "game/data.h"

/* Overlay 70: the minigame results screen of the board path. MP1's ancestor is
   ovl_7C_UnknownResultsScreen (308A50.c); MP2 adds the minigame bonus coins, counted in a second
   pass, and an alternative layout chosen by _CheckFlag(0xD). */

/* A player's standing (MP1 ResRank). */
typedef struct ResRank {
    /* 0x00 */ s8 rank;  /* 0 = first; tied players share a rank */
    /* 0x01 */ s8 place; /* row on the screen */
} ResRank;

/* Per table row, the {x, y} of each place. Rows: 0/1 place sprite, 2/3 character, 4 coin icon,
   5/6 coins, 7 stars, 8 unused here, 9 stars (layout 0xD), 10 unused here. Odd-numbered layouts
   (1, 3, 6, 9) are the _CheckFlag(0xD) variant. */
#define RES_ROW_PLACE 0
#define RES_ROW_PLACE_D 1
#define RES_ROW_CHAR 2
#define RES_ROW_CHAR_D 3
#define RES_ROW_COINICON 4
#define RES_ROW_COINS 5
#define RES_ROW_COINS_D 6
#define RES_ROW_STARS 7
#define RES_ROW_STARS_D 9

/* .data */
extern s8 D_801076A0_413B00_Results; /* the screen is finished */
extern s8 D_801076A1_413B01_Results; /* A/Start pressed: skip the waits */
extern s8 D_801076A2_413B02_Results; /* skipping is not allowed */
extern s32 D_801076A4_413B04_Results[6]; /* per character: portrait file */
extern char* D_801076BC_413B1C_Results; /* "RESULTS" */
extern s16 D_801076C0_413B20_Results[2]; /* title position */
extern s16 D_801076C4_413B24_Results[11][4][2]; /* RES_ROW_* */
/* Per layout (0, 0xD), per number of digits - 1: the x offset of each coin digit (-1000 hides it)
   and of the "X". */
extern s16 D_80107774_413BD4_Results[2][3][4];
extern s8 D_801077A4_413C04_Results; /* the screen may close */
extern s32 D_801077A8_413C08_Results[7]; /* per board: background */
/* Per number of digits - 1: the x offset of each digit of the minigame coins (-1000 hides it). */
extern s16 D_801077C4_413C24_Results[3][3];
extern s16 D_801077D8_413C38_Results[3][3];
extern s16 D_801077EC_413C4C_Results[3][3];
extern s8 D_801077FE_413C5E_Results;
extern s8 D_801077FF_413C5F_Results;

/* .bss. The s32 slots hold s16 sprite/group ids (stored as words, read as their low half). */
extern s16 D_80107830_413C90_Results[4]; /* minigame bonus coins to add */
extern s16 D_80107838_413C98_Results[4]; /* minigame coins to add */
extern s16 D_80107840_413CA0_Results[4]; /* minigame bonus coins won */
extern s16 D_80107848_413CA8_Results[4]; /* minigame coins won */
extern ResRank D_80107850_413CB0_Results[4];
extern ResRank D_80107858_413CB8_Results[4]; /* before the coins */
extern s16 D_80107860_413CC0_Results[4]; /* coins before the minigame */
extern s32 D_80107868_413CC8_Results;
extern GAMEMES D_80107870_413CD0_Results; /* the title */
extern s32 D_801078E4_413D44_Results;
extern s32 D_801078E8_413D48_Results[4];
extern s32 D_801078F8_413D58_Results;
extern s32 D_80107900_413D60_Results[4];
extern s32 D_80107910_413D70_Results;
extern s32 D_80107914_413D74_Results;
extern s32 D_80107918_413D78_Results;
extern s32 D_8010791C_413D7C_Results;
extern GAMEMES D_80107920_413D80_Results[8]; /* star counts */
extern s32 D_80107CC0_414120_Results[8];
extern s32 D_80107CE0_414140_Results;
extern s32 D_80107CE4_414144_Results;
extern s32 D_80107CE8_414148_Results;
extern s32 D_80107CEC_41414C_Results;
extern s32 D_80107CF0_414150_Results[4]; /* per player: bonus coin counter group */
extern s32 D_80107D00_414160_Results[4]; /* per player: minigame coin counter group */
extern s32 D_80107D10_414170_Results; /* the group being built */
extern s32 D_80107D14_414174_Results;
extern s32 D_80107D18_414178_Results[4];
extern s32 D_80107D28_414188_Results[4];
extern s32 D_80107D38_414198_Results[4];
extern s32 D_80107D48_4141A8_Results[4];
extern s32 D_80107D58_4141B8_Results[4][3];
extern s32 D_80107D88_4141E8_Results[4][3];
extern s16 D_80107DB8_414218_Results[4]; /* coins counted per step */
extern s16 D_80107DC0_414220_Results[4]; /* coins counted so far */

/* Main */
s16 SprCreate(s32 num, s32 attr);
s16 SprAnimRead(void* arg0);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
void SprAttrSet(s16 grpIdx, s16 idx, s32 flag);
void SprPosSet(s16 grpIdx, s16 idx, s16 x, s16 y);
void SprScaleSet(s16 group, s16 member, f32 x, f32 y);
void SprKill(s16 idx);
void SprAnimKill(s16 animIdx);
void func_8008221C_82E1C(s16 group, s16 member, f32 arg2);
void func_800824F4_830F4(s16 group, s16 member, s16 arg2);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
void func_800822A8_82EA8(s16 group, s16 member, u16 arg2, s32 arg3);
s16 func_8006A608_6B208(void* mes, char* str, u8 arg2, s16 arg3, s16 arg4); /* MP1 GMesFontMesCreate */
void func_8006AE14_6BA14(void*);
s16 func_800888A8_894A8(s16, s16, s16, s16, s32, s16);
void func_80089B2C_8A72C(s16, s16);
void func_8008D530_8E130(s16 arg0, u8 arg1, u8 arg2, u8 arg3);
s32 func_8008F618_90218(void); /* fade still running */
void InitFadeOut(s32, s32);
void InitFadeIn(s32, s32);
void func_800794A8_7A0A8(s32);
void PlayMusic(s16);
s32 PlaySound(s32);
void AdjustPlayerCoins(s32 index, s32 count);
f32 HuMathSin(f32);
int abs(int);
int sprintf(char* dst, const char* fmt, ...);
extern u8 D_01164160[];
void func_80050E00_51A00(s32);
void MBDBackKill(void);
void func_80050AE0_516E0(void);
void func_80059400_5A000(void);
void func_80059704_5A304(void);
void func_80059CC8_5A8C8(void);
void func_80059C28_5A828(void);
void func_8004340C_4400C(void);
void func_8005E2FC_5EEFC(void);

#define ABS(x) ((x) < 0 ? -(x) : (x))

/* Overlay */
void func_80102800_40EC60_Results(void);
void func_801028A0_40ED00_Results(void);
void func_80102944_40EDA4_Results(void);
void func_801038A4_40FD04_Results(void);
void func_80103C6C_4100CC_Results(void);
void func_80103DB4_410214_Results(void);
void func_801041C8_410628_Results(void);
void func_80104278_4106D8_Results(void);
void func_801042B4_410714_Results(void);
void func_801042D8_410738_Results(void);
void func_8010438C_4107EC_Results(void);
void func_801043B0_410810_Results(s16 grp, s16 idx, s16 dx, s16 dy);
void func_80104418_410878_Results(s16 grp, s16 idx, s16 x);
void func_80104458_4108B8_Results(s16 grp, s16 idx, s16 y);
void func_80104498_4108F8_Results(s16 grp, s16 idx, s32 mask);
void func_801044D0_410930_Results(void);
void func_801046DC_410B3C_Results(void);
void func_8010492C_410D8C_Results(void);
void func_80104B90_410FF0_Results(void);
void func_80104D3C_41119C_Results(void);
void func_80105AB8_411F18_Results(void);
void func_80105F50_4123B0_Results(void);
void func_801063E8_412848_Results(void);
void func_80107140_4135A0_Results(s16 steps, s32 which);
s8 func_801072B0_413710_Results(s32 which);
void func_80107544_4139A4_Results(void);

#endif
