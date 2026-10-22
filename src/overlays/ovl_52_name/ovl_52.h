#ifndef _OVL_52_H
#define _OVL_52_H

/* Overlay 52 (358DE0.c): the end-of-game bonus stars, a stand-alone scene (its own omInitObjMan).
   MP1's end-game bonus overlays (ovl_42/ovl_43_UnknownEndGameBonuses*) are its ancestors: the stars
   and coins are shown, the minigame, coin and happening bonus stars are awarded, the ranking is
   computed (ties broken with a dice block), the winner is shown ("YOU ARE THE WINNER"), then it
   goes on to the results overlays (0x4F/0x50/0x51 by board).
   The unit's .rodata is carved; .data and .bss stay asm. */

#include "common.h"
#include "game/board.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/data.h"
#include "game/malloc.h"
#include "game/sprite.h"
#include "game/window.h"
#include "game/gamemes.h"
#include "game/pad.h"

/* ---- main-segment API used by 52 ---- */

void func_80079128_79D28(void);
void func_80020D20_21920(s16 arg0);
void func_80050E00_51A00(s32);
void func_8005321C_53E1C(f32, f32);
void func_80088640_89240(void);
s32 func_8008F618_90218(void);
void func_8008CE5C_8DA5C(void);
void func_80018E30_19A30(s32);
void func_80050A30_51630(u8*);
void MBDBackKill(void);
void func_80050AE0_516E0(void);
void func_8005E260_5EE60(s16 playerIndex);
void func_800592E4_59EE4(void);
void func_80059400_5A000(void);
void MBModelKill(void*);
void func_800283DC_28FDC(s16 arg0);
void omDelObj(omObjData*);
void func_80049F90_4AB90(ModelEmitterWork*);
ModelEmitterWork* func_80049ED4_4AAD4(MBModel*, s16);
s16 func_8006A608_6B208(GAMEMES* gMes, char* str, u8 flag, s16 x, s16 arg4);
void func_8006AE14_6BA14(GAMEMES* gMes);
void SprScaleSet(s16 group, s16 member, f32 x, f32 y);
void SprPosSet(s16 grpIdx, s16 idx, s16 x, s16 y);
s16 SprCreate(s32 num, s32 attr);
s16 SprAnimRead(void*);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
void SprAttrSet(s16, s16, s32);
void SprAnimKill(s16 animIdx);
void SprKill(s16 idx);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
void func_800822A8_82EA8(s16 group, s16 member, u16 arg2, s32 arg3);
void func_80082450_83050(s16 grpIdx, s32 idx, s32 r, s32 g, u8 b);
void MBDCamera3Dto2D(Vec* arg0, Vec2f* arg1);
f32 __sinf(f32);
f32 __cosf(f32);
f32 HuMathSin(f32);
void HuVecCopyXYZ(Vec*, f32, f32, f32);
void MBModelDispOn(MBModel*);
void MBModelDispOff(MBModel*);
s32 PlaySound(s32);
void func_80015710_16310(s32 slot, s32 pan);
void func_800595E8_5A1E8(void* arg0, s32 arg1, s32 arg2);
void func_80059618_5A218(void* arg0);
s16 func_800797DC_7A3DC(s32, s16);

/* ---- overlay 52 data ---- */

extern ModelEmitterWork* D_801067E0_35CDC0_name_52[4];
extern u16 D_801067F0_35CDD0_name_52; /* set when the ceremony is over */
extern s32 D_801067F4_35CDD4_name_52; /* the winner effect's model (-1: none); read as (s16) */
extern omObjData* D_801067F8_35CDD8_name_52;
extern omObjData* D_801067FC_35CDDC_name_52[4]; /* the leaders' pulsing digits */
extern s32 D_8010680C_35CDEC_name_52[7]; /* per board: the stage */
extern u8 D_80106978_35CF58_name_52[4]; /* per player: sound pan */
extern char* D_8010697C_35CF5C_name_52; /* "YOU ARE THE WINNER" */
extern s16 D_80106980_35CF60_name_52[2]; /* its position */

/* ---- overlay 52 bss ---- */

extern u8 D_80106B30_35D110_name_52; /* board index */
extern MBModel* D_80106B34_35D114_name_52;
extern MBModel* D_80106B40_35D120_name_52[4]; /* the bonus star models */
extern s32 D_80106B50_35D130_name_52[4]; /* their effects; read as (s16) */
extern s32 D_80106B60_35D140_name_52[4]; /* the digit sprites; read as (s16) */
extern s32 D_80106B70_35D150_name_52; /* the digit graphic; read as (s16) */
extern s16 D_80106B74_35D154_name_52;
extern s16 D_80106B76_35D156_name_52;
extern GAMEMES D_80106B78_35D158_name_52; /* the "YOU ARE THE WINNER" text */

/* ---- overlay 52 functions ---- */

void func_80102800_358DE0_name_52(void);
void func_801028C4_358EA4_name_52(void);
void func_80102978_358F58_name_52(void);
void func_80102998_358F78_name_52(omObjData* obj);
void func_80102AA0_359080_name_52(void);
void func_80102EDC_3594BC_name_52(void);
void func_80102F78_359558_name_52(void);
void func_80103338_359918_name_52(void);
void func_801033D4_3599B4_name_52(s32 count, u8* flags);
void func_80103814_359DF4_name_52(void);
void func_80105574_35BB54_name_52(void);
void func_80105640_35BC20_name_52(omObjData* obj);
void func_80105674_35BC54_name_52(void);
void func_80105A48_35C028_name_52(void);
void func_80105B8C_35C16C_name_52(void);
void func_80105C24_35C204_name_52(void);
void func_80105C48_35C228_name_52(void);
void func_8010604C_35C62C_name_52(void);
void func_8010670C_35CCEC_name_52(void);

/* Retail calls these as int-returning: the result is re-extended. */
#define SprCreate_s32(num, attr) (((s32(*)(s32, s32))SprCreate)(num, attr))
#define SprAnimRead_s32(data) (((s32(*)(void*))SprAnimRead)(data))
#define func_8006A608_s32(g, s, f, x, y) (((s32(*)(GAMEMES*, char*, u8, s16, s16))func_8006A608_6B208)(g, s, f, x, y))

#define DEG 0.017453292519943295

#endif
