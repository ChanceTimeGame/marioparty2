#ifndef _OVL_52_H
#define _OVL_52_H

/* Overlay 52 (358DE0.c): the end-of-game bonus stars, a stand-alone scene (its own omInitObjMan).
   MP1's end-game bonus overlays (ovl_42/ovl_43_UnknownEndGameBonuses*) are its ancestors: the stars
   and coins are shown, the minigame, coin and happening bonus stars are awarded, the ranking is
   computed (ties broken with a dice block), the winner is shown ("YOU ARE THE WINNER"), then it
   goes on to the results overlays (0x4F/0x50/0x51 by board).
   The unit's .rodata is carved and its .data is C; .bss stays asm. */

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
extern s16 D_800F8CE4_F98E4[]; /* board state halfwords; [10 + i]: player i's bonus stars */

void MBPlayerModelCreate(s16, void*, s32);
void func_8005ABC0_5B7C0(GW_PLAYER*, s16, s16);
void func_80056658_57258(Vec*, Vec*, Vec*); /* direction from a to b as a rotation */
MBModel* MBModelFileCreate(s32 arg0, s32 arg1, f32 arg2, f32 arg3, u32* arg4);
void MBMotionSet(MBModel*, s16, s32);
MBModel* func_80043510_44110(s32, void*);
MBModel* MBModelParamCreate(MBModel*);
u16 func_80059370_59F70(void);
void func_8002D124_2DD24(s16 index);
void func_800298A4_2A4A4(s16, s32, s32);
s16 func_80027D3C_2893C(s16 linkMdlId); /* model copy */
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_8002979C_2A39C(s16 idx, f32 x, f32 y, f32 z); /* model rotation */
void MBModelInit(void);
void func_8005E2B8_5EEB8(void);
void func_800593C0_59FC0(void);
void func_8005AB50_5B750(MBModel* arg0, s16 arg1, s16 arg2, s32 arg3);
void func_80043DAC_449AC(MBModel*);
s32 func_8005A5E8_5B1E8(MBModel* model, Vec* target, f32 speed); /* walk toward; TRUE when there */
s32 func_8005A7E8_5B3E8(MBModel* model, Vec* target, f32 step); /* turn toward; TRUE when facing */
void* func_8005A718_5B318(MBModel* model, f32 speed, u16 count, Vec* points); /* a path walk (3F ModelPathWork) */
s32 func_8005A778_5B378(void*); /* path finished */
void MBMotionShiftSet(void* arg0, s16 arg1, s32 arg2, s32 arg3, u16 arg4);
void func_8008DACC_8E6CC(s32, s16*, s32); /* a message's window size */
s32 func_8005AAC0_5B6C0(s32 x, s32 y, s32 w, s32 h); /* board message window */
void func_800890CC_89CCC(s16, s32, s32, s32);
void func_8005762C_5822C(s32 arg0);
void func_800794A8_7A0A8(s32);
s16 func_8003DF08_3EB08(void* arg);
s16 LoadFormFile(s32, s32);
void omSetTra(omObjData*, f32, f32, f32);
void omSetSca(omObjData*, f32, f32, f32);
u16 func_80020EBC_21ABC(void* arg0, s32 arg1, u8 arg2);
void func_80021160_21D60(s16 index, s32 arg1, s32 arg2);
void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
void func_80021250_21E50(s16 index, u8 arg1, u8 arg2, u8 arg3);
void func_800211E8_21DE8(s16 index, u8 arg1);
void func_8002308C_23C8C(s32 index);
void func_8008D974_8E574(char*, s16); /* message argument: a string */
void func_80089308_89F08(s16, char*, s8); /* window message argument (a string) */
void ShowTextWindow(s32 arg0);
void func_80057DA4_589A4(s32 arg0);
void func_8005ACD0_5B8D0(GW_PLAYER*, s16);
omObjData* func_800732B0_73EB0(u32 arg0);
omObjData* func_80058F18_59B18(s32 player, Vec* target, s32 time, Object* arg3); /* turn toward */
omObjData* func_8005845C_5905C(s32 player, Vec* target, s32 time, Object* arg3); /* walk to */
void func_8002D0A0_2DCA0(s16, u8); /* model alpha */
void func_8005A0CC_5ACCC(void);
void func_80046238_46E38(void);
void func_800461C8_46DC8(void);
s16 func_80046F98_47B98(s32);
void func_80046308_46F08(s32 arg0);
void func_80047D2C_4892C(void);
void func_80047BB8_487B8(s32);
s32 func_80047DE8_489E8(s32);
void func_80047B78_48778(void);
void func_80059520_5A120(MBModel*, s32, s32);
extern char* D_800CC5F8[]; /* per character: the name string */
extern u16 D_801011FC_101DFC;
extern u8 D_800FD866_FE466;

/* ---- overlay 52 data ---- */

extern ModelEmitterWork* D_801067E0_35CDC0_name_52[4];
extern u16 D_801067F0_35CDD0_name_52; /* set when the ceremony is over */
extern s32 D_801067F4_35CDD4_name_52; /* the winner effect's model (-1: none); read as (s16) */
extern omObjData* D_801067F8_35CDD8_name_52;
extern omObjData* D_801067FC_35CDDC_name_52[4]; /* the leaders' pulsing digits */
extern s32 D_8010680C_35CDEC_name_52[7]; /* per board: the stage */
extern Vec D_80106828_35CE08_name_52[4]; /* each player's place (splat: D_8010682C, D_80106830) */
extern Vec D_80106858_35CE38_name_52; /* a single winner's spot */
extern Vec D_80106864_35CE44_name_52; /* the host's place */
extern u32* D_80106960_35CF40_name_52[6]; /* per character: the board model's file list */
extern s8 D_80106978_35CF58_name_52[4]; /* per player: sound pan */
extern char* D_8010697C_35CF5C_name_52; /* "YOU ARE THE WINNER" */
extern s16 D_80106980_35CF60_name_52[2]; /* its position */
extern s32 D_80106984_35CF64_name_52[7]; /* per board: the host's model */
extern u32 D_801069A0_35CF80_name_52[7][2]; /* per board: the host's motions */

extern u32 D_801069D8_35CFB8_name_52[]; /* its file list */
extern s32 D_80106A04_35CFE4_name_52;
extern u16 D_80106A50_35D030_name_52[4]; /* per player: exit path length */
extern Vec* D_80106A58_35D038_name_52[4]; /* per player: exit path */
extern Vec D_80106A68_35D048_name_52; /* its start */
extern Vec D_80106A74_35D054_name_52; /* where it stops */
extern s32 D_80106A80_35D060_name_52[]; /* per board: its message */

/* ---- overlay 52 bss ---- */

extern u8 D_80106B30_35D110_name_52; /* board index */
extern MBModel* D_80106B34_35D114_name_52;
extern MBModel* D_80106B38_35D118_name_52; /* the character who ends the scene */
extern MBModel* D_80106B40_35D120_name_52[4]; /* the bonus star models */
extern s32 D_80106B50_35D130_name_52[4]; /* their effects; read as (s16) */
extern s32 D_80106B60_35D140_name_52[4]; /* the digit sprites; read as (s16) */
extern s32 D_80106B70_35D150_name_52; /* the digit graphic; read as (s16) */
extern s16 D_80106B74_35D154_name_52[2]; /* a message window's size */
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
#define func_80059370_s32() (((s32(*)(void))func_80059370_59F70)())
#define func_80027D3C_s32(m) (((s32(*)(s16))func_80027D3C_2893C)(m))

#define DEG 0.017453292519943295

#endif
