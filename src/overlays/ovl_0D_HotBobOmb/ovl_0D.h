#ifndef _OVL_0D_H
#define _OVL_0D_H

/* Overlay 0D: Hot Bob-omb (4P). MP2's game is new (MP1's ovl_07_HotBobOmb shares only the
   stick-direction helper func_801045B0 and the bomb-model update func_80104F7C): four players
   sit at the corners of a square (D_80106B20_13C850_HotBobOmb) and throw a lit bob-omb to each
   other with the stick and A; the fuse (D_80106E88_13CBB8_HotBobOmb, seconds) runs down; the
   holder when it reaches 0 is blown up. Three rounds (D_80106E80_13CBB0_HotBobOmb 0..2), each
   with its own random fuse (D_80106E90_13CBC0_HotBobOmb).
   One retail file, 138530.c (80102800-80106B10). .data is asm (13C840.data.s); .rodata is
   carved (0x13C9C0). N64 offsets are in the comments. */

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/data.h"
#include "game/collision.h"

/* ---- structs ---- */

/* A seat (D_80106B20_13C850_HotBobOmb[4]): where a player sits and where the bomb rests in
   front of them. obj->unk_50 of each player object points at its seat. Splat labels inside
   entry 0: D_80106B28 (z), D_80106B2C (rot), D_80106B30 (scale), D_80106B34/38/3C (bomb).
   Pointer-free. */
typedef struct HBSeat {
    /* 0x00 */ Vec pos;
    /* 0x0C */ f32 rot;     /* facing (y) */
    /* 0x10 */ f32 scale;
    /* 0x14 */ Vec bomb;    /* the bomb's place at this seat */
    /* 0x20 */ f32 bombRot; /* facing toward the centre */
    /* 0x24 */ f32 t;       /* 0..1 at 1/30 a frame (idle wobble) */
    /* 0x28 */ s32 player;  /* seat index = player */
    /* 0x2C */ char unk_2C[4];
} HBSeat; /* size = 0x30 */

/* Per-character data (main D_800CD438_CE038, 0x18 bytes each). */
typedef struct HBCharData {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 unk_04; /* the character's file directory */
    /* 0x08 */ s32 unk_08; /* its model file */
    /* 0x0C */ char unk_0C[0xC];
} HBCharData; /* size = 0x18 */

/* ---- main ---- */
extern HBCharData D_800CD438_CE038[];
extern u16 D_801011FC_101DFC; /* minigame over */
extern s8 ContStkX[4];
extern s8 ContStkY[4];
void func_80079E60_7AA60(void);
void func_8002D4D0_2E0D0(s16 n);
void func_80020D20_21920(s16 arg0);
void func_80079128_79D28(void);
void func_8000C38C_CF8C(void);
void func_8000C3C8_CFC8(void);
void func_8002CA48_2D648(u8 arg0, u8 arg1, u8 arg2);
void func_80026D28_27928(s32);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80018E30_19A30(s32);
s32 func_80018E78_19A78(void);
void func_8000C018_CC18(u16);
u16 func_80018A30_19630(s32 file, s32 attr);
u16 func_80018A64_19664(s32 file, s32 attr);
void func_80018CCC_198CC(omObjData* obj, u16 slot, s32 file);
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029E80_2AA80(s16, s32, s32);
void func_80029714_2A314(s16, f32, f32, f32);
void func_8002979C_2A39C(s16, f32, f32, f32);
void func_800297E8_2A3E8(s16, f32, f32, f32);
void func_80029A8C_2A68C(s16);
void func_80029B80_2A780(s16 arg0, s16 arg1);
void func_80029BF0_2A7F0(s16, s16, s16, s16, s16);
f32 func_80029CE4_2A8E4(s16);
f32 func_80029D0C_2A90C(s16);
s32 func_80029E14_2AA14(s16 arg0); /* 2AA14.c: u8; retail callers re-extend the result */
void func_8002C628_2D228(s16 arg0, s16 arg1, char* arg2);
void func_8002C6F4_2D2F4(HmfModel*, u16);
void func_8003E4F4_3F0F4(s16, u8, u8);
void func_80015710_16310(s32 slot, s32 pan);
s32 func_80069538_6A138(void); /* MP1 GMesStatAllGet */
s16 func_800691FC_69DFC(s16 mesNo, ...);
void func_800799A4_7A5A4(s16 sound, s32 frames);
void func_80079614_7A214(s16 time);
void func_800794A8_7A0A8(s32);
void func_80079684_7A284(s8);
s16 func_800797DC_7A3DC(s32 sfx, s16 player);
omObjData* func_800732B0_73EB0(u32 arg0);
s32 func_8008F618_90218(void);
s32 PlaySound(s32);
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
s16 LoadFormFile(s32, s32);
void HuMemMemoryFreePerm(void* ptr);
f32 HuMathSin(f32);
s16 SprCreate(s32 num, s32 attr);
s16 SprAnimRead(void*);
void SprAnimSet(s16 group, s16 member, s16 anim, u16 arg3);
void SprPosSet(s16 group, s16 member, s16 x, s16 y);
void SprAttrSet(s16 group, s16 member, s32 flag);
void SprAttrReset(s16 grpIdx, s16 idx, s32 flag);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
void Hu3DCamSetPositionOrientation(s16, Vec*, Vec*, Vec*);
void Hu3DCamUpdateMtx(s16 camIndex);

/* ---- .data (13C840.data.s, asm) ---- */
extern s32 D_80106B10_13C840_HotBobOmb[4];      /* seat -> player ({0,1,2,3}) */
extern HBSeat D_80106B20_13C850_HotBobOmb[4];
extern s32 D_80106BE0_13C910_HotBobOmb[4][5];   /* [from][to]: throw kind 0/1/2 (-1 self) */
extern s32 D_80106C30_13C960_HotBobOmb;         /* seats set up so far */
extern s32 D_80106C34_13C964_HotBobOmb[4];      /* sound pan per seat */
extern f32 D_80106C44_13C974_HotBobOmb;         /* fuse sprite's resting y */
extern s32 D_80106C48_13C978_HotBobOmb;         /* followed by two unreferenced words (0, 50.0f) */
extern s32 D_80106C54_13C984_HotBobOmb;         /* music started; followed by five unreferenced
                                                   words (0, 1.5f, 1.5f, 2.5f, 6.0f) */
extern s32 D_80106C6C_13C99C_HotBobOmb;         /* bomb fuse-model frame counter */
extern f32 D_80106C70_13C9A0_HotBobOmb;
extern f32 D_80106C74_13C9A4_HotBobOmb;
extern f32 D_80106C78_13C9A8_HotBobOmb;
extern s32 D_80106C7C_13C9AC_HotBobOmb;
extern s32 D_80106C80_13C9B0_HotBobOmb;
extern s32 D_80106C84_13C9B4_HotBobOmb;

/* ---- .bss ---- */
extern f32 D_80106E60_13CB90_HotBobOmb;
extern f32 D_80106E64_13CB94_HotBobOmb;
extern s32 D_80106E68_13CB98_HotBobOmb;
extern s32 D_80106E70_13CBA0_HotBobOmb[4];      /* controller port per player */
extern s32 D_80106E80_13CBB0_HotBobOmb;         /* round 0..2; low half read as D_80106E82 */
extern s16 D_80106E84_13CBB4_HotBobOmb;         /* _CheckFlag(0xC) */
extern s16 D_80106E86_13CBB6_HotBobOmb;         /* sound handle */
extern s32 D_80106E88_13CBB8_HotBobOmb;         /* fuse left (seconds) */
extern s32 D_80106E8C_13CBBC_HotBobOmb;         /* fuse sprite bob counter */
extern s32 D_80106E90_13CBC0_HotBobOmb[4];      /* [0..2] each round's fuse; [3] the fuse
                                                   sprite's bob period (splat label D_80106E9C) */
extern u16 D_80106EA0_13CBD0_HotBobOmb;
extern u16 D_80106EA2_13CBD2_HotBobOmb;         /* frames to the next fuse second */
extern u16 D_80106EA4_13CBD4_HotBobOmb;
extern s16 D_80106EA6_13CBD6_HotBobOmb[5];      /* bomb models (= the bomb object's model[0..4]) */
extern f32 D_80106EB0_13CBE0_HotBobOmb;
extern s16 D_80106EB4_13CBE4_HotBobOmb[3];      /* explosion models */
extern s32 D_80106EC0_13CBF0_HotBobOmb[4];
extern omObjData* D_80106ED4_13CC04_HotBobOmb;  /* the bomb object */
extern s16 D_80106ED8_13CC08_HotBobOmb;         /* fuse sprite */
extern s16 D_80106EDA_13CC0A_HotBobOmb[5];      /* bomb texture animations */
extern s32 D_80106EE4_13CC14_HotBobOmb;
extern s32 D_80106EE8_13CC18_HotBobOmb;         /* bomb state */
extern s32 D_80106EF0_13CC20_HotBobOmb[4];
extern u16 D_80106F00_13CC30_HotBobOmb[4];      /* buttons held */
extern s32 D_80106F08_13CC38_HotBobOmb[4];      /* each player's win/lose motion file */
extern s32 D_80106F1C_13CC4C_HotBobOmb;
extern s8 D_80106F20_13CC50_HotBobOmb[4];       /* stick x */
extern s32 D_80106F28_13CC58_HotBobOmb[4];      /* player state */
extern s32 D_80106F78_13CCA8_HotBobOmb;         /* throw across (seats 0<->3, 1<->2) */
extern s32 D_80106F7C_13CCAC_HotBobOmb;
extern s16 D_80106F80_13CCB0_HotBobOmb[4];      /* coins won */
extern u16 D_80106F88_13CCB8_HotBobOmb[4];      /* buttons pressed */
extern u8 D_80106F90_13CCC0_HotBobOmb;          /* fading out */
extern s16 D_80106F92_13CCC2_HotBobOmb;         /* background sprite */
extern s32 D_80106F94_13CCC4_HotBobOmb;
extern s32 D_80106F98_13CCC8_HotBobOmb;
extern Vec D_80106F9C_13CCCC_HotBobOmb;         /* camera */
extern s32 D_80106FA8_13CCD8_HotBobOmb[4];      /* per-player wait */
extern s32 D_80106FB8_13CCE8_HotBobOmb;         /* throw kind */
extern Vec D_80106FBC_13CCEC_HotBobOmb;
extern s32 D_80106FC8_13CCF8_HotBobOmb;         /* end state */
extern s16 D_80106FCC_13CCFC_HotBobOmb;
extern s32 D_80106FD0_13CD00_HotBobOmb;         /* flight frames left */
extern s32 D_80106FD4_13CD04_HotBobOmb;         /* flight length; low half read as D_80106FD6 */
extern Vec D_80106FD8_13CD08_HotBobOmb;
extern s32 D_80106FE8_13CD18_HotBobOmb[4];      /* state entered (1 = run the entry code) */
extern s32 D_80106FF8_13CD28_HotBobOmb;         /* thrower; low half read as D_80106FFA */
extern s32 D_80106FFC_13CD2C_HotBobOmb;         /* loser (-1) */
extern s32 D_8010700C_13CD3C_HotBobOmb;         /* game state: 0 intro, 1 play, 2 over */
extern u8 D_80107010_13CD40_HotBobOmb[4];       /* 1 = human */
extern s8 D_80107014_13CD44_HotBobOmb[4];       /* stick y */
extern s32 D_80107018_13CD48_HotBobOmb[4];      /* CPU hold time */
extern s32 D_80107028_13CD58_HotBobOmb;         /* catcher */

/* ---- 138530.c ---- */
void func_80102800_138530_HotBobOmb(void);
void func_801028D4_138604_HotBobOmb(void);
void func_80102A28_138758_HotBobOmb(omObjData* obj);
void func_80102A74_1387A4_HotBobOmb(omObjData* obj);
void func_80102B30_138860_HotBobOmb(void);
void func_80102CD4_138A04_HotBobOmb(void);
void func_80102D10_138A40_HotBobOmb(omObjData* obj);
void func_80102D8C_138ABC_HotBobOmb(omObjData* obj);
s16 func_80102DCC_138AFC_HotBobOmb(void);
void func_80102E94_138BC4_HotBobOmb(void);
void func_80102FF0_138D20_HotBobOmb(omObjData* obj);
void func_80103034_138D64_HotBobOmb(omObjData* obj);
void func_8010322C_138F5C_HotBobOmb(void);
void func_801032EC_13901C_HotBobOmb(void);
void func_8010349C_1391CC_HotBobOmb(omObjData* obj);
void func_801037D0_139500_HotBobOmb(omObjData* obj);
s32 func_801045B0_13A2E0_HotBobOmb(s8 x, s8 y);
s32 func_80104674_13A3A4_HotBobOmb(s32 player, u32 dir);
void func_80104790_13A4C0_HotBobOmb(s32 player);
void func_80104A50_13A780_HotBobOmb(s32 player);
void func_80104CD4_13AA04_HotBobOmb(void);
void func_80104D80_13AAB0_HotBobOmb(void);
void func_80104E34_13AB64_HotBobOmb(f32 x, f32 y, f32 z, f32 scale);
void func_80104F7C_13ACAC_HotBobOmb(omObjData* obj, s32 unused);
void func_80105124_13AE54_HotBobOmb(omObjData* obj);
void func_801056C8_13B3F8_HotBobOmb(omObjData* obj);
void func_80106750_13C480_HotBobOmb(omObjData* obj);

#endif
