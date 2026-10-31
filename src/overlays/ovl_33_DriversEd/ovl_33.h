#ifndef _OVL_33_H
#define _OVL_33_H

/* Overlay 33: Driver's Ed. 1P (the player with group 0, func_80105634_2568B4_DriversEd) drives a car through the 20
   signs of one of five courses (D_800FA656 -> D_801086BC_25993C_DriversEd) in order, with a timer and the course's
   best time on screen. Phases D_80108680_259900_DriversEd: 0 intro camera + signal (START skips), 1 "ready", 2
   race (60 s, 30 frames per s, func_80104344_2555C4_DriversEd), 3 stopping, 4 result, 5 fade out and
   omOvlReturnEx(1). Up/down on the stick drive forward/back, left/right steer, R toggles the
   driver's view. Hitting a sign the wrong way or skipping one sets D_801086BD_25993D_DriversEd (failed); passing
   sign 20 and reaching z > 2160 sets D_801086DB_25995B_DriversEd; the time goes to GWMgRecordSet(course + 8, BCD)
   when it beats the record. Nothing is written to gPlayers[] (coins or otherwise).
   Retail is two files: 253A80.c (80102800-80107C50, 1-nop text pad) and 258ED0.c (the two table
   clears). .rodata is carved from 0x259840 (253A80.c only); .data is in 253A80.c.
   N64 offsets are in the comments; structs with pointer fields change size on the host. */

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/data.h"
#include "game/collision.h"
#include "game/malloc.h"

/* Angle wrap into [0, 360); the argument is evaluated again in every arm, as retail does. */
#define DE_WRAP(a) ((a) >= 360.0f ? (a) - 360.0f : (a) < 0.0f ? (a) + 360.0f : (a))

/* One entry of D_80108720_2599A0_DriversEd[50] (cleared by func_80107C50_258ED0_DriversEd). 0 the car, 5 the signal, 10 the course,
   11-30 the signs (obj->work[0] = the index), 35 the timer sprites. */
typedef struct DEObj {
    /* 0x00 */ omObjData* obj;
    /* 0x04 */ s16 spr;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ f32 x;     /* car: copy of its position */
    /* 0x0C */ f32 y;
    /* 0x10 */ f32 z;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s16 unk_20[2];
    /* 0x24 */ s32 unk_24[2];
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30[4][4];
    /* 0x70 */ u16 unk_70;
    /* 0x72 */ u16 unk_72;
    /* 0x74 */ u16 unk_74;
    /* 0x76 */ u16 unk_76;
    /* 0x78 */ u16 unk_78;
    /* 0x7A */ u16 unk_7A;
    /* 0x7C */ u16 unk_7C;
    /* 0x7E */ u16 unk_7E;
    /* 0x80 */ s16 unk_80;
    /* 0x82 */ s16 unk_82;
    /* 0x84 */ s16 unk_84;
    /* 0x86 */ s16 unk_86;
    /* 0x88 */ f32 unk_88;
    /* 0x8C */ s32 unk_8C;
    /* 0x90 */ s32 unk_90;
    /* 0x94 */ s32 unk_94;
} DEObj; /* size = 0x98 (N64) */

/* The car's driving state. */
typedef struct DECar {
    /* 0x00 */ f32 dir;      /* direction out of the last hit */
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ f32 steer;
    /* 0x0C */ f32 speed;
    /* 0x10 */ f32 bounce;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s16 hitSign;  /* the sign whose end was hit */
    /* 0x1A */ s16 hitSide;
    /* 0x1C */ u16 wallX;
    /* 0x1E */ u16 wallZ;
    /* 0x20 */ s16 unk_20;
    /* 0x22 */ s16 unk_22;
    /* 0x24 */ s16 sndFwd;
    /* 0x26 */ s16 sndBack;
    /* 0x28 */ s16 pitch;
} DECar;

/* A dust puff (MP1 FaceLift's effect work, 8 slots). */
typedef struct DEFx {
    /* 0x00 */ char unk_00[2];
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 alpha;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ f32 x;
    /* 0x0C */ f32 y;
    /* 0x10 */ f32 z;
    /* 0x14 */ char unk_14[4];
    /* 0x18 */ f32 vy;
    /* 0x1C */ s16 model;
    /* 0x1E */ char unk_1E[2];
} DEFx; /* size = 0x20 */

typedef struct DEFxWork {
    /* 0x000 */ DEFx fx[8];
    /* 0x100 */ u8 state[8];
} DEFxWork; /* size = 0x108 */

typedef struct DEPoint {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
    /* 0x0C */ f32 rot;
} DEPoint;

/* A key of the intro's camera path. */
typedef struct DECamKey {
    /* 0x00 */ f32 zoom;
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 z;
    /* 0x0C */ f32 time;
} DECamKey;

/* .data (253A80.c, 0x258FF0-0x259840) */
extern u16 D_80107D70_258FF0_DriversEd[6];           /* car file per character (dir 0x43) */
extern u16 D_80107D7C_258FFC_DriversEd[6];           /* driver file per character (dir 0x19) */
extern DEPoint D_80107D88_259008_DriversEd[5][20];   /* the signs of each course */
extern DEPoint D_801083C8_259648_DriversEd[5];       /* the car's start on each course */
extern DECamKey D_80108418_259698_DriversEd[5][4];   /* the intro path of each course */
extern u16 D_80108558_2597D8_DriversEd[20];          /* sign texture files (dir 0x43) */
extern u16 D_80108580_259800_DriversEd[4];           /* signal lamp textures */
extern char* D_80108588_259808_DriversEd[3];         /* their names */
extern s16 D_80108594_259814_DriversEd[7];           /* timer digit x positions */
extern s16 D_801085A4_259824_DriversEd[7];           /* the best time's digits */
extern u8 D_801085B2_259832_DriversEd;               /* the skid sound is on */

/* .bss */
extern u8 D_80108680_259900_DriversEd;               /* game phase */
extern u8 D_80108681_259901_DriversEd;               /* added to it next frame */
extern s16 D_80108682_259902_DriversEd;              /* the race time */
extern s16 D_80108684_259904_DriversEd;              /* phase countdown */
extern s16 D_80108686_259906_DriversEd;
extern omObjData* D_80108688_259908_DriversEd;       /* the dust object */
extern DECar D_80108690_259910_DriversEd;
/* Fields of D_80108690_259910_DriversEd that retail also addresses by their own labels. */
extern u16 D_801086A8_259928_DriversEd;              /* .hitSign */
extern u16 D_801086AA_25992A_DriversEd;              /* .hitSide */
extern s16 D_801086AC_25992C_DriversEd;              /* .wallX */
extern s16 D_801086AE_25992E_DriversEd;              /* .wallZ */
extern s8 D_801086BC_25993C_DriversEd;               /* the course */
extern s8 D_801086BD_25993D_DriversEd;               /* failed: a sign was missed or hit from the wrong side */
extern s8 D_801086BE_25993E_DriversEd;               /* the last sign passed */
extern s8 D_801086BF_25993F_DriversEd;               /* the next sign */
extern s8 D_801086C0_259940_DriversEd[20];           /* the sign was passed */
extern u8 D_801086D4_259954_DriversEd;
extern u8 D_801086D5_259955_DriversEd[6];            /* the timer's digits */
extern s8 D_801086DB_25995B_DriversEd;               /* 1 reached the goal, 2 parked in it */
extern void* D_801086DC_25995C_DriversEd[3];
extern s16 D_801086E8_259968_DriversEd[3];
extern u16 D_801086EE_25996E_DriversEd;              /* the signal's state */
extern s32 D_801086F0_259970_DriversEd;
extern s32 D_801086F4_259974_DriversEd;
extern u16 D_801086F8_259978_DriversEd;              /* driver's view */
extern f32 D_801086FC_25997C_DriversEd;
extern f32 D_80108700_259980_DriversEd;
extern u8 D_80108704_259984_DriversEd;               /* a new record */
extern s16 D_80108706_259986_DriversEd[5];           /* the final time's digits */
extern u16 D_80108710_259990_DriversEd;              /* the record as BCD */
extern DEObj D_80108720_2599A0_DriversEd[50];
extern f32 D_80108728_2599A8_DriversEd;              /* D_80108720_2599A0_DriversEd[0].x, .y, .z: written by these labels */
extern f32 D_8010872C_2599AC_DriversEd;
extern f32 D_80108730_2599B0_DriversEd;
extern f32 D_80108AA0_259D20_DriversEd;              /* D_80108720_2599A0_DriversEd[5].unk_88: retail addresses it by this label */
extern s16 D_8010A4D0_25B750_DriversEd[50];

void func_801075F0_258870_DriversEd(void);
void func_80102800_253A80_DriversEd(void);
void func_8010281C_253A9C_DriversEd(void);
void func_80102914_253B94_DriversEd(void);
void func_8010291C_253B9C_DriversEd(void);
void func_80102A24_253CA4_DriversEd(void);
void func_80102A2C_253CAC_DriversEd(omObjData* obj);
void func_80102A90_253D10_DriversEd(void);
void func_80102ACC_253D4C_DriversEd(omObjData* obj);
void func_80102C00_253E80_DriversEd(omObjData* obj);
void func_80102D20_253FA0_DriversEd(void);
void func_80102D5C_253FDC_DriversEd(s16 player, f32 x, f32 y, f32 z, u16 type);
void func_80102EE0_254160_DriversEd(omObjData* obj);
void func_80103074_2542F4_DriversEd(omObjData* obj);
void func_80103258_2544D8_DriversEd(void);
void func_801032FC_25457C_DriversEd(void);
void func_80103538_2547B8_DriversEd(omObjData* obj);
void func_80103894_254B14_DriversEd(void);
void func_801038D0_254B50_DriversEd(omObjData* obj);
void func_80103D74_254FF4_DriversEd(omObjData* obj);
void func_80104038_2552B8_DriversEd(void);
void func_80104074_2552F4_DriversEd(void);
void func_801040E0_255360_DriversEd(omObjData* obj);
void func_80104344_2555C4_DriversEd(omObjData* obj);
void func_8010443C_2556BC_DriversEd(omObjData* obj);
void func_801044C4_255744_DriversEd(omObjData* obj);
void func_80104984_255C04_DriversEd(omObjData* obj);
void func_80104D84_256004_DriversEd(omObjData* obj);
void func_80105108_256388_DriversEd(omObjData* obj);
void func_801053C8_256648_DriversEd(omObjData* obj);
void func_80105634_2568B4_DriversEd(void);
void func_8010570C_25698C_DriversEd(void);
void func_80105770_2569F0_DriversEd(omObjData* obj);
void func_801057E8_256A68_DriversEd(omObjData* obj);
void func_80105880_256B00_DriversEd(void);
void func_801058A8_256B28_DriversEd(void);
void func_80105BE0_256E60_DriversEd(void);
void func_8010644C_2576CC_DriversEd(void);
void func_80106828_257AA8_DriversEd(void);
void func_801068F4_257B74_DriversEd(s16 course, s16 key);
void func_80106B58_257DD8_DriversEd(s16 course);
void func_80106D4C_257FCC_DriversEd(s16 course, s16 key);
void func_80106E08_258088_DriversEd(void);
void func_80107118_258398_DriversEd(void);
void func_801072B8_258538_DriversEd(omObjData* obj);
void func_801073EC_25866C_DriversEd(void);
void func_80107530_2587B0_DriversEd(omObjData* obj);
f32 func_80107780_258A00_DriversEd(f32 x);
void func_801078D0_258B50_DriversEd(Vec* from, Vec* to, Vec* out);
void func_80107C50_258ED0_DriversEd(void);
void func_80107D44_258FC4_DriversEd(void);

/* main */
extern s8 ContStkX[4];
extern s8 ContStkY[4];
extern u8 D_800FA656;
extern u16 D_801011FC_101DFC;
extern s16 D_800FA606_FB206;
extern u16 D_800FC87A_FD47A;
extern u16 D_800F8FE0_F9BE0;
void func_80029714_2A314(s16, f32, f32, f32);
f32 HuMathSin(f32);
omObjData* omAddObj(s16, u16, u16, s16, void*);
f32 func_800B7890_B8490(f32);
void func_800298A4_2A4A4(s16, s32, s32);
void func_800297E8_2A3E8(s16, f32, f32, f32);
void SprAttrSet(s16 grpIdx, s16 idx, s32 flag);
void Hu3DCamSetPerspective(s16, f32, f32, f32);
s16 func_800691FC_69DFC(s16 mesNo, ...);
s16 LoadFormFile(s32, s32);
void func_80029E80_2AA80(s16, s32, s32);
void SprBankSet(s16 group, s16 member, s16 bank);
s32 PlaySound(s32);
s16 PlayMusic(s16);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
void func_800794A8_7A0A8(s32);
void func_80029AFC_2A6FC(s16);
void func_80029A8C_2A68C(s16);
void SprPosSet(s16, s16, s16, s16);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
s16 func_80079798_7A398(s16 sfx, s16 player);
void func_8002979C_2A39C(s16, f32, f32, f32);
void HuMemMemoryFreePerm(void *ptr);
void* DataRead(s32 dirAndFile);
f32 func_800B1830_B2430(f32);
void func_80079614_7A214(s16 time);
void func_8007273C_7333C(u8* arg0, u8 arg1);
s16 func_8003D8F0_3E4F0(HmfData*, void*, s16, char*);
s16 func_8001A2F8_1AEF8(s32 arg0);
u16 func_80018A30_19630(s32 file, s32 attr);
s16 SprCreate(s32 num, s32 attr);
void InitFadeOut(s32, s32);
void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
u8 rand8(void);
extern void osViBlack(u8);
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
void omSetStatBit(omObjData *obj, u16 stat);
s32 omOvlReturnEx(s16);
void omInitObjMan(s32, s32);
s32 func_8008F618_90218(void);
void func_80079128_79D28(void);
s32 func_80069538_6A138(void);
void func_8002D4D0_2E0D0(s16 n);
void* func_80027154_27D54(s32 size, s16 tag);
void func_80020D20_21920(s16 arg0);
s32 func_80018E78_19A78(void);
void func_80018E30_19A30(s32);
void ViewportSet(u8, f32, f32, f32, f32, f32, f32);
void ScissorSet(u8 arg0, f32 x1, f32 y1, f32 x2, f32 y2);
void InitFadeIn(s32, s32);
void func_80079E60_7AA60(void);
void func_80079848_7A448(s16 arg0);
void func_800B1F50_B2B50(f32* m, f32 x, f32 y, f32 z);
void func_800824F4_830F4(s16 group, s16 member, s16 arg2);
void func_800211E8_21DE8(s16 index, u8 arg1);
void func_800796F0_7A2F0(s16 sound, s16 pitch);
s32 func_800680D4_68CD4(s16 index); /* main returns u16; retail does not re-mask the result */
s16 func_8003DF08_3EB08(void*);
void func_80021250_21E50(s16 index, u8 arg1, u8 arg2, u8 arg3);
void func_80021160_21D60(s16 index, s32 arg1, s32 arg2);
u16 func_80020EBC_21ABC(void* arg0, s32 arg1, u8 arg2);
void GWMgRecordSet(s16, u16);
void func_8003E4F4_3F0F4(s16 arg0, u8 arg1, u8 arg2);

#endif
