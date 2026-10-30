#ifndef _OVL_14_H
#define _OVL_14_H

/* Overlay 14: Shock, Drop or Roll (1 vs 3). The solo player (slot 0, the player whose group is 0:
   D_801072B8_1701F8_ShockDropOrRoll[0]) stands at the front and turns a big roller with the stick
   (D_801072B0, -45..45: the roller's spin D_80106F70 accelerates toward it, damped by 0.98 per
   frame); the three others (slots 1-3, x -200/0/200) stand on the roller and are carried along
   z by its surface speed D_801072C4. They run against it (their stick is turned into stick Y) and
   jump with A; a player carried past z 325 drops off the back or front (MgWork y <= 0 marks it
   fallen, SDPlayer.fell) and is out. 929 frames (about 15 s, the seconds counter) of play
   (D_80106F14); the three win if anybody is still on when time is up (each +10
   gPlayers[].coins_mg_bonus), the solo player wins when all three have fallen (+10 to it). The
   1P variant (_CheckFlag(0xC)) ends as soon as a human falls and pays every survivor.
   Retail is three files: 16B740.c (80102800-80105E90), 16EDD0.c (80105E90-80105FD0, the camera,
   end and shadow helpers shared with 0F's 147180.c), 16EF10.c (80105FD0-end, the roller and the
   stage; 1-nop text pad before it). .data stays asm (0x16FE10-0x16FED0); .rodata is carved per
   file (0x16FED0 16B740.c, 0x170070 16EF10.c). */

#include "common.h"
#include "game/object.h"
#include "game/collision.h"
#include "game/hmfman.h"
#include "game/pad.h"

/* ---- types ---- */

/* MgWork::unk_158 of each of the three roller players, 0xF8 bytes (func_80103FE8). */
typedef struct SDPlayer {
    /* 0x00 */ s8 fell;       /* 1: fell off (y <= 0) */
    /* 0x01 */ s8 dropped;    /* 1: the fall has been set up (the drop and spin) */
    /* 0x02 */ s8 cheered;    /* the win/lose motion has been played */
    /* 0x03 */ s8 dash;       /* CPU: runs at full stick for 10 frames (the roller sped up) */
    /* 0x04 */ s8 voiced;     /* the fall voice has been played */
    /* 0x05 */ u8 level;      /* CPU level row in D_80106F9C (D_801072BC[slot - 1]) */
    /* 0x06 */ s16 mark;      /* the marker model (stage model 0x24000A copies) */
    /* 0x08 */ s16 jumpWait;  /* frames since the last jump */
    /* 0x0A */ s16 aimWait;   /* CPU: frames since the aim offset was rerolled */
    /* 0x0C */ s16 spinWait;  /* CPU: frames since the roller speed was sampled */
    /* 0x0E */ char unk_0E[2];
    /* 0x10 */ f32 spin;      /* CPU: the sampled roller speed */
    /* 0x14 */ f32 aim;       /* CPU: aim offset */
    /* 0x18 */ f32 fallVel;   /* bounce speed after hitting the floor */
    /* 0x1C */ f32 rot[3];    /* marker rotation */
    /* 0x28 */ f32 pos[3];    /* position last frame */
    /* 0x34 */ u8 hist;       /* CPU: input delay ring index */
    /* 0x35 */ char unk_35;
    /* 0x36 */ s16 stk[32];   /* CPU: delayed stick X (read back by its low byte) */
    /* 0x76 */ s16 btn[32];   /* CPU: delayed ContBtn */
    /* 0xB6 */ s16 trg[32];   /* CPU: delayed ContBtnTrg */
} SDPlayer; /* size = 0xF8 (0xF6 + pad) */

/* A CPU level of the roller players (D_80106F9C_16FEDC_ShockDropOrRoll[5], indexed by
   SDPlayer.level). */
typedef struct SDLevel {
    /* 0x00 */ f32 aimNear;   /* |z| + aim at which the CPU runs at full stick */
    /* 0x04 */ f32 jumpZ;     /* |z| from which it jumps */
    /* 0x08 */ s16 jumpWait;  /* frames between jumps */
    /* 0x0A */ u8 stkFar;     /* stick when past aimNear (read as s8) */
    /* 0x0B */ u8 stkNear;    /* stick otherwise (read as s8) */
} SDLevel; /* size = 0xC */

/* The camera key of one stage of the roller camera (D_80107078: [7][3] values; D_801070EC: [2]
   win shots). */
typedef struct SDCamera {
    /* 0x00 */ f32 zoom;
    /* 0x04 */ Vec rot;
    /* 0x10 */ Vec center;
} SDCamera; /* size = 0x1C */

/* The players' MgWork and SDPlayer, gathered at the top of the update functions. */
typedef struct SDWorkPair {
    /* 0x00 */ MgWork* w[4];
    /* 0x10 */ SDPlayer* p[4];
} SDWorkPair;

/* ---- .data (asm, 0x16FE10-0x16FED0) ---- */

/* 16B740.c: 80106ED0-80106F60 */
extern s8 D_80106ED0_16FE10_ShockDropOrRoll;   /* the game is over */
extern s8 D_80106ED1_16FE11_ShockDropOrRoll;   /* the roller turns (the intro is running) */
extern s8 D_80106ED2_16FE12_ShockDropOrRoll;   /* the intro spin is done */
extern s8 D_80106ED3_16FE13_ShockDropOrRoll;   /* play has started (the CPUs move) */
extern s8 D_80106ED5_16FE15_ShockDropOrRoll;   /* result: 0 the three win, 1 the solo player (-1) */
extern u8 D_80106ED7_16FE17_ShockDropOrRoll;   /* game state (func_80104E24) */
extern s8 D_80106ED8_16FE18_ShockDropOrRoll;   /* the result camera runs */
extern s8 D_80106ED9_16FE19_ShockDropOrRoll;   /* the result camera has moved */
extern s8 D_80106EDA_16FE1A_ShockDropOrRoll;   /* the result is shown */
extern f32 D_80106EDC_16FE1C_ShockDropOrRoll[8]; /* the solo stick, last 8 frames (30.0f) */
extern u32 D_80106EFC_16FE3C_ShockDropOrRoll;  /* intro spin frames */
extern u32 D_80106F00_16FE40_ShockDropOrRoll;  /* intro spin step frames */
extern u32 D_80106F04_16FE44_ShockDropOrRoll;  /* intro spin step */
extern s8 D_80106F08_16FE48_ShockDropOrRoll;   /* D_80106EDC index */
extern s8 D_80106F09_16FE49_ShockDropOrRoll;   /* crank sound state: 1 slow, 2 fast */
extern f32 D_80106F0C_16FE4C_ShockDropOrRoll;  /* the crank's motion speed */
extern s8 D_80106F10_16FE50_ShockDropOrRoll;   /* the solo CPU is set up */
extern s32 D_80106F14_16FE54_ShockDropOrRoll;  /* play time left, frames (929) */
extern f32 D_80106F18_16FE58_ShockDropOrRoll[16]; /* the players' mean z, last 16 frames */
extern u8 D_80106F58_16FE98_ShockDropOrRoll;   /* D_80106F18 index */
extern s16 D_80106F5A_16FE9A_ShockDropOrRoll;  /* result camera frames */

/* 16EDD0.c: 80106F60-80106F70 */
extern s8 D_80106F60_16FEA0_ShockDropOrRoll;   /* the end fade has started */

/* 16EF10.c: 80106F70-80106F90 */
extern f32 D_80106F70_16FEB0_ShockDropOrRoll;  /* roller spin speed (degrees per frame) */
extern f32 D_80106F74_16FEB4_ShockDropOrRoll;  /* roller angle */
extern s8 D_80106F78_16FEB8_ShockDropOrRoll;   /* the roller sound is playing */
extern f32 D_80106F7C_16FEBC_ShockDropOrRoll[4]; /* the four fans' angles */
extern u8 D_80106F8C_16FECC_ShockDropOrRoll[4];  /* the four sparks' frames (0-23) */

/* ---- .rodata (16B740.c) ---- */
extern const char D_80106F90_16FED0_ShockDropOrRoll[];
extern const SDLevel D_80106F9C_16FEDC_ShockDropOrRoll[5];
extern const s32 D_80106FD8_16FF18_ShockDropOrRoll[4];
extern const s16 D_80106FE8_16FF28_ShockDropOrRoll[4];
extern const s8 D_80106FF0_16FF30_ShockDropOrRoll[8];
extern const s8 D_80106FF8_16FF38_ShockDropOrRoll[8];
extern const s16 D_80107000_16FF40_ShockDropOrRoll[4][8];

/* ---- .bss ---- */
extern s8 D_80107250_170190_ShockDropOrRoll;   /* solo CPU: turn direction (1, -1) */
extern s16 D_80107252_170192_ShockDropOrRoll;  /* solo CPU: flips toward a player near the middle */
extern s16 D_80107254_170194_ShockDropOrRoll;  /* solo CPU: frames since the last flip */
extern s16 D_80107256_170196_ShockDropOrRoll;  /* solo CPU: frames until the next flip */
extern u32 D_80107258_170198_ShockDropOrRoll;  /* game state frames */
extern s16 D_8010725C_17019C_ShockDropOrRoll;  /* 1P result wait */
extern s16 D_8010725E_17019E_ShockDropOrRoll;  /* result frames */
extern s16 D_80107260_1701A0_ShockDropOrRoll;  /* result length */
extern f32 D_80107268_1701A8_ShockDropOrRoll[4]; /* camera spline keys */
extern SDCamera D_80107278_1701B8_ShockDropOrRoll; /* the camera this frame */
extern s16 D_801072A0_1701E0_ShockDropOrRoll;  /* the roller sound */
extern s8 D_801072B0_1701F0_ShockDropOrRoll;   /* the solo stick (-45..45) */
extern s8 D_801072B1_1701F1_ShockDropOrRoll[3]; /* marker texture animations */
extern omObjData* D_801072B4_1701F4_ShockDropOrRoll; /* the solo player */
extern s8 D_801072B8_1701F8_ShockDropOrRoll[4]; /* player by slot (0 = solo) */
extern s8 D_801072B9_1701F9_ShockDropOrRoll[3]; /* = D_801072B8[1] */
extern s8 D_801072BA_1701FA_ShockDropOrRoll;    /* = D_801072B8[2] */
extern s8 D_801072BB_1701FB_ShockDropOrRoll;    /* = D_801072B8[3] */
extern s8 D_801072BC_1701FC_ShockDropOrRoll[5]; /* CPU level rows 0-4, shuffled */
extern f32 D_801072C4_170204_ShockDropOrRoll;   /* the roller's surface speed (z per frame) */
extern omObjData* D_801072C8_170208_ShockDropOrRoll; /* the stage */
extern s8 D_801072CC_17020C_ShockDropOrRoll[4]; /* spark texture animations */

/* ---- main ---- */
extern s8 ContStkX[4];
extern s8 ContStkY[4];
extern u16 D_801011FC_101DFC;
extern s32 D_800F8FD0_F9BD0; /* scene state */
extern u16 D_800FA606_FB206;
extern u16 D_800BF7E4_C03E4[][14]; /* per player sound ids */

/* Per-character data, 0x18 bytes each. */
typedef struct SDCharData {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s32 unk_04; /* motion directory */
    /* 0x08 */ s32 unk_08; /* model file */
    /* 0x0C */ char unk_0C[0xC];
} SDCharData;
extern SDCharData D_800CD438_CE038[];

s16 LoadFormFile(s32, s32);
s32 PlaySound(s32);
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* cos */
f32 func_800B75A8_B81A8(f32 y, f32 x); /* atan2, degrees */
void func_80007790_8390(omObjData* obj); /* player object update */
void func_8000BE8C_CA8C(omObjData*, f32);
void func_8000BEA4_CAA4(omObjData*, f32);
void func_8000BEB0_CAB0(omObjData*, f32);
void func_8000BEBC_CABC(omObjData*, f32);
void func_8000BEC8_CAC8(omObjData*, f32);
/* its second argument is a float that retail passes in a1 (as 0F) */
void func_8000BF24_CB24(omObjData*, s32, f32, f32, f32, f32);
void func_8000C004_CC04(omObjData*);
void func_8000C018_CC18(u16);
void func_8000C024_CC24(omObjData* obj, u8 idx, s8 val);
void func_8000C35C_CF5C(omObjData* obj, f32 x, f32 y, f32 z); /* obj->trans */
void func_8000C36C_CF6C(omObjData* obj, f32 x, f32 y, f32 z); /* obj->rot */
void func_8000C38C_CF8C(void);
void func_8000C398_CF98(void);
void func_8000C3A8_CFA8(void);
void func_8000C3B8_CFB8(void);
void func_8000C3C8_CFC8(void);
void func_8000C460_D060(void);
void func_8000C578_D178(u8);
void func_8000C6FC_D2FC(omObjData* obj, u32 dir, s32 file, u16 player, s32 arg4, s32 arg5); /* player object setup */
u16 func_80018A30_19630(s32, s32); /* model load */
void func_80018CCC_198CC(omObjData* obj, u16 slot, s32 file); /* loads obj->motion[slot] */
void func_80019B9C_1A79C(omObjData* obj, s32 motion); /* player motion */
void func_80019E84_1AA84(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4);
void func_80019F0C_1AB0C(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4); /* motion */
void func_8001A12C_1AD2C(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4, s32 arg5);
void func_80020070_20C70(s32);
void func_80020D20_21920(s16 arg0);
f32 func_8002662C_2722C(f32* keys, f32* times, f32 t); /* spline through four keys */
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void* func_80027154_27D54(s32, s32); /* HuMemAllocTag */
s16 func_80027D3C_2893C(s16 linkMdlId); /* model copy */
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void func_8002979C_2A39C(s16, f32, f32, f32); /* model rotation */
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029A8C_2A68C(s16);
void func_80029AFC_2A6FC(s16);
void func_80029B80_2A780(s16 arg0, s16 arg1);
void func_80029C74_2A874(s16, f32);
void func_8002C59C_2D19C(s32, s32, s32, s32, s32);
void func_8002D1EC_2DDEC(s16 arg0, u8 arg1);
void func_8002D274_2DE74(s16 arg0, u8 arg1, u8 arg2, u8 arg3); /* model light colour */
void func_8002D2B4_2DEB4(s16 arg0, f32 arg1, f32 arg2, f32 arg3); /* model light direction */
void func_8002D4D0_2E0D0(s16 n);
void func_8002F290_2FE90(s32* arg0, s32 n);
void func_8003E4F4_3F0F4(s16 arg0, u8 arg1, u8 arg2);
void func_8003E52C_3F12C(s16, u8);
void func_8003E560_3F160(s16, s32);
s16 func_800691FC_69DFC(s16 mesNo, ...);
s32 func_80069538_6A138(void);
void func_80069770_6A370(void);
void func_8006D4D0_6E0D0(s16); /* the seconds counter */
void func_8006D518_6E118(void);
void func_8007273C_7333C(u8* arg0, u8 arg1);
omObjData* func_800732B0_73EB0(u32 arg0);
void func_800795D8_7A1D8(s16 sound, s8 volume);
void func_800796F0_7A2F0(s16 sound, s16 pitch);
s16 func_80079798_7A398(s16, s16);
void func_800797DC_7A3DC(s32, s16);
void func_80079868_7A468(void);
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size); /* memset */
void func_800B2060_B2C60(f32 (*)[4], f32, f32, f32);
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);

/* ---- 16B740.c ---- */
void func_80102800_16B740_ShockDropOrRoll(void);
void func_80102EC8_16BE08_ShockDropOrRoll(omObjData* obj);
void func_80102F54_16BE94_ShockDropOrRoll(omObjData* obj);
void func_80102FE4_16BF24_ShockDropOrRoll(omObjData* obj);
void func_8010306C_16BFAC_ShockDropOrRoll(omObjData* obj);
void func_80103100_16C040_ShockDropOrRoll(omObjData* obj);
void func_801038C4_16C804_ShockDropOrRoll(omObjData* obj);
void func_80103FE8_16CF28_ShockDropOrRoll(omObjData* obj, s32 dir, s32 file, u16 player, f32 x, f32 y, f32 z, u16 slot);
void func_801044BC_16D3FC_ShockDropOrRoll(omObjData* obj);
void func_80104784_16D6C4_ShockDropOrRoll(omObjData* obj);
void func_80104B98_16DAD8_ShockDropOrRoll(omObjData* obj, s32 dir, s32 file, u16 player, f32 x, f32 y, f32 z);
void func_80104E24_16DD64_ShockDropOrRoll(omObjData* obj);
void func_80105920_16E860_ShockDropOrRoll(omObjData* obj);

/* ---- 16EDD0.c ---- */
void func_80105E90_16EDD0_ShockDropOrRoll(f32 zoom, f32 rx, f32 ry, f32 rz, f32 cx, f32 cy, f32 cz);
void func_80105ED0_16EE10_ShockDropOrRoll(omObjData* obj);
void func_80105F48_16EE88_ShockDropOrRoll(omObjData* obj);

/* ---- 16EF10.c ---- */
void func_80105FD0_16EF10_ShockDropOrRoll(omObjData* obj);
void func_80106394_16F2D4_ShockDropOrRoll(omObjData* obj);
void func_801064B0_16F3F0_ShockDropOrRoll(omObjData* obj);
void func_801065F0_16F530_ShockDropOrRoll(omObjData* obj);
void func_80106790_16F6D0_ShockDropOrRoll(omObjData* obj);

#endif
