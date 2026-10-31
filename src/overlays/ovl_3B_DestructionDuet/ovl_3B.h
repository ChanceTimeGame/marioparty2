#ifndef _OVL_3B_H
#define _OVL_3B_H

/* Overlay 3B: Destruction Duet (2 vs 2). Each team has a building (D_80108B60[team], model[2]) to
   ground-pound down; hit points in DD_HP(team), 30 per difficulty step above 30. Retail is one
   file, 28B620.c; .data (4 floats) is asm, .rodata is carved from 0x291250. */

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/collision.h"

/* ---- main-segment API used by 3B (missing from include/) ---- */

typedef struct DDCharData {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s32 unk_04; /* model/motion directory */
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ char unk_14[4];
} DDCharData;
extern DDCharData D_800CD438_CE038[];

extern f32 D_800BF7BC_C03BC;
extern f32 D_800BF7C0_C03C0;
extern f32 D_800BF7C4_C03C4;
extern f32 D_800BF7C8_C03C8;
extern f32 D_800BF7CC_C03CC;
extern f32 D_800F8410_F9010;
extern u16 D_800FA606_FB206;
extern u8 D_800FA656;
extern f32 D_800FA5BC_FB1BC[];
extern u16 D_800FD410_FE010[4];
extern s16 D_800FC9BE_FD5BE[4]; /* stick x as s16 */
extern s16 D_800FD468_FE068[4]; /* stick y as s16 */
extern f32 D_80101078_101C78;
extern u16 D_801011FC_101DFC;
extern u8 D_80102720_103320;
extern s8 ContStkX[4];
extern s8 ContStkY[4];

void func_8002D4D0_2E0D0(s16 n);
void func_8002F290_2FE90(s32* arg0, s32 n);
void func_80020D20_21920(s16 arg0);
void func_80079128_79D28(void);
void func_80029708_2A308(s32);
void func_8000C38C_CF8C(void);
void func_8000C3B8_CFB8(void);
void func_8000C3C8_CFC8(void);
void func_8000C460_D060(void);
void func_8000C578_D178(s32);
void func_8000C018_CC18(u16);
void func_80026D28_27928(s32);
void func_80026DAC_279AC(s16, u8, u8, u8);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
u16 func_80078EA8_79AA8(void);
s32 PlaySound(s32);
void func_80079518_7A118(s32);
void func_80079614_7A214(s16 time);
void func_80079848_7A448(s16 arg0);
void func_800798F8_7A4F8(s16 sound, s32 arg1);
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
s16 func_800691FC_69DFC(s16 mesNo, ...);
void func_8006D4D0_6E0D0(s16);
void func_8006D518_6E118(void);
void func_8007273C_7333C(char* arg0, u8 arg1);
omObjData* func_800732B0_73EB0(u32 arg0);
f32 func_800B1830_B2430(f32);
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32);
void* func_80027154_27D54(s32 size, s16 tag);
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size);
u16 func_80018A30_19630(s32 arg0, s32 arg1);
u16 LoadFormFile(s32, s32);
void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
void func_80029714_2A314(s16, f32, f32, f32);
void func_8002979C_2A39C(s16 idx, f32 x, f32 y, f32 z);
void func_800297E8_2A3E8(s16, f32, f32, f32);
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029AFC_2A6FC(s16);
void func_80029C74_2A874(s16, f32);
void func_8002CD78_2D978(s16, s32, s32, s32, s32);
void func_8002CDF0_2D9F0(s16, s32, s32, s32, s32);
void func_8002D1EC_2DDEC(s16, u8);
void func_8002D274_2DE74(s16 arg0, u8 arg1, u8 arg2, u8 arg3);
void func_8002D2B4_2DEB4(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_8000BE8C_CA8C(omObjData*, f32);
void func_8000BE98_CA98(omObjData*, f32);
void func_8000BFF0_CBF0(omObjData*);
void func_8000BF24_CB24(omObjData* obj, f32 arg1, f32 x0, f32 z0, f32 x1, f32 z1);
void func_8000BF54_CB54(omObjData*, f32, f32, f32, f32, f32, f32);
void func_8000BDC4_C9C4(omObjData* obj, u16 idx, s32 dir, s32 file, f32 arg4);
void func_8000C6FC_D2FC(omObjData* obj, u32 dir, s32 file, u16 player, s32 arg4, s32 arg5);
void func_8000CC74_D874(omObjData* obj, s16 model, s16 motion);
void func_8000C024_CC24(omObjData* obj, u8 idx, u8 val);
void func_8000E0C0_ECC0(MgWork* w, s32 slot, void* hook);
s32 func_80019000_19C00(omObjData* obj);
s32 func_80019B9C_1A79C(omObjData* obj, u16 motion);
void func_80019F0C_1AB0C(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4);
void func_80019E84_1AA84(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4);
void func_8001A12C_1AD2C(omObjData* obj, u16 slot, s32 file, s32 flags, u16 speed, s32 arg5);
void func_80007790_8390(omObjData* obj);
void func_800098D0_A4D0(omObjData* obj, f32 x, f32 y, f32 z);
void omSetTra(omObjData* obj, f32 x, f32 y, f32 z);
void Hu3DCamSetPositionOrientation(s16 camIndex, Vec* pos, Vec* at, Vec* up);
void Hu3DCamUpdateMtx(s16 camIndex);

/* ---- types ---- */

/* Per-player state, D_80108A50[4]. */
typedef struct DDPlayer {
    /* 0x00 */ s8 character;
    /* 0x01 */ s8 player;     /* gPlayers index */
    /* 0x02 */ s8 slot;       /* 0-1 team 0, 2-3 team 1 */
    /* 0x03 */ s8 port;
    /* 0x04 */ s8 difficulty; /* CPU difficulty, -1 human */
    /* 0x05 */ char unk_05;
    /* 0x06 */ u16 delay;     /* CPU: frames before moving */
    /* 0x08 */ s16 mode;      /* CPU goal */
    /* 0x0A */ u16 frames;    /* frames on the ground */
    /* 0x0C */ f32 radius;    /* CPU: arrival radius */
    /* 0x10 */ f32 targetX;
    /* 0x14 */ f32 targetZ;
    /* 0x18 */ f32 stickX;    /* last frame's */
    /* 0x1C */ f32 stickY;
} DDPlayer; /* size = 0x20 */

/* Tables a function copies whole (retail keeps every copy in its own stack slot). */
typedef struct DDVoice {
    s32 v[6];
} DDVoice;
typedef struct DDSpeed {
    f32 v[4];
} DDSpeed;
typedef struct DDByte4 {
    u8 v[4];
} DDByte4;

/* .data */
extern f32 D_80108420_291240_DestructionDuet[4]; /* each slot's start x */

/* .bss */
extern DDPlayer D_80108A50_291870_DestructionDuet[4];
extern DDPlayer* D_80108AD0_2918F0_DestructionDuet[4];
extern u8 D_80108AE0_291900_DestructionDuet[4];
extern s8 D_80108AE4_291904_DestructionDuet; /* winning team, 4 draw, 5 undecided */
extern s8 D_80108AE5_291905_DestructionDuet; /* shake sign */
extern f32 D_80108AE8_291908_DestructionDuet; /* speed factor after a landing */
extern u8 D_80108AEC_29190C_DestructionDuet;
extern u8 D_80108AED_29190D_DestructionDuet; /* next spark model, 0-7 */
extern omObjData* D_80108AF0_291910_DestructionDuet;
extern omObjData* D_80108AFC_29191C_DestructionDuet; /* the stage and effect models */
extern f32 D_80108B00_291920_DestructionDuet; /* fov; [1 + team] are the hit points */
extern f32 D_80108B04_291924_DestructionDuet[2]; /* hit points */
extern u8 D_80108B0C_29192C_DestructionDuet; /* difficulty, 0-2 (D_800FA656) */
extern u8 D_80108B0D_29192D_DestructionDuet[4]; /* slot -> player */
extern u32 D_80108B14_291934_DestructionDuet; /* state timer */
extern u16 D_80108B18_291938_DestructionDuet; /* leave */
extern s16 D_80108B1A_29193A_DestructionDuet[4]; /* hit cooldown */
extern Vec D_80108B28_291948_DestructionDuet[2]; /* building sway */
extern u8 D_80108B40_291960_DestructionDuet[4]; /* which win motion */
extern omObjData* D_80108B48_291968_DestructionDuet[4]; /* players */
extern u8 D_80108B58_291978_DestructionDuet[4];
extern omObjData* D_80108B60_291980_DestructionDuet[4]; /* building tops, 2-3 building bases */
extern Vec D_80108B70_291990_DestructionDuet; /* camera position */
extern u8 D_80108B7C_29199C_DestructionDuet;
extern u16 D_80108B80_2919A0_DestructionDuet[8]; /* spark ages */
extern u16 D_80108B82_2919A2_DestructionDuet[]; /* D_80108B80 + 1 */
extern u8 D_80108B90_2919B0_DestructionDuet[2]; /* building damage tier */
extern s16 D_80108B92_2919B2_DestructionDuet; /* game state */
extern Vec D_80108B94_2919B4_DestructionDuet; /* camera target */
extern s8 D_80108BB8_2919D8_DestructionDuet; /* shake size */
extern Vec D_80108BC0_2919E0_DestructionDuet[4]; /* player positions before the jump */

/* ---- functions ---- */

void func_80102800_28B620_DestructionDuet(void);
void func_80102D40_28BB60_DestructionDuet(omObjData* obj);
void func_801030E4_28BF04_DestructionDuet(void);
void func_80104204_28D024_DestructionDuet(omObjData* obj);
void func_80104550_28D370_DestructionDuet(omObjData* obj);
void func_80104668_28D488_DestructionDuet(omObjData* obj);
void func_80104684_28D4A4_DestructionDuet(omObjData* obj);
void func_801046A0_28D4C0_DestructionDuet(omObjData* obj);
void func_801046BC_28D4DC_DestructionDuet(omObjData* obj);
void func_801046D8_28D4F8_DestructionDuet(omObjData* obj, s32 arg1);
void func_80104A2C_28D84C_DestructionDuet(omObjData* obj);
void func_80104A3C_28D85C_DestructionDuet(void);
void func_80105CFC_28EB1C_DestructionDuet(omObjData* obj, s32 dir, s32 file, u16 player, f32 x, f32 y, f32 z);
void func_80106044_28EE64_DestructionDuet(omObjData* obj);
void func_801060E0_28EF00_DestructionDuet(omObjData* obj);
void func_80106180_28EFA0_DestructionDuet(omObjData* obj);
void func_80106220_28F040_DestructionDuet(omObjData* obj);
void func_801062C0_28F0E0_DestructionDuet(omObjData* obj, s32 player);
void func_801063CC_28F1EC_DestructionDuet(omObjData* obj);
s32 func_80107F48_290D68_DestructionDuet(omObjData* obj, GroundWork* ground);
s32 func_801081F0_291010_DestructionDuet(void);
s32 func_80108258_291078_DestructionDuet(omObjData* obj);
void func_80108318_291138_DestructionDuet(s16 model, s16 frame);
void func_8010835C_29117C_DestructionDuet(void);

#endif
