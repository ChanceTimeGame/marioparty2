#ifndef _OVL_54_H
#define _OVL_54_H

/* Overlay 54 (360670.c): a short stand-alone scene (its own omInitObjMan) in which the current
   player (D_8010388C) rides away on a model (0x72, D_80103880): the model bobs in front of a
   sprite backdrop, flies off, comes back for the player, who jumps on, and both fly into the
   distance (shrinking) while the backdrop fades. Then the scene returns to the board.
   (MP1's ovl_5D_BowserVisitEternalStar is the closest ancestor; MP3's majinlamp shares the
   entry function's shape.) */

#include "common.h"
#include "game/board.h"
#include "game/object.h"
#include "game/hmfman.h"

#define PLAYER_MODEL(p) ((MBModel*)(p)->unk_24)

extern u16 D_801011FC_101DFC;
extern s16 D_800F64B0_F70B0;

void* DataRead(s32 dirAndFile);
void DataClose(void*);
GW_PLAYER* BoardPlayerGet(s32);
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* cos */
void HuVecCopyXYZ(Vec*, f32, f32, f32);
void MBDBackKill(void);
void MBDlgResultWinExec(s32);
void MBDlgWinExecY(s16 arg0, s32 arg1, s32 arg2);
void MBModelKill(void*);
void MBPlayerMotionSet(s32, s16, u16);
s32 PlaySound(s32);
void SprAnimKill(s16 animIdx);
s16 SprAnimRead(void*);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprAttrSet(s16, s16, s32);
s16 SprCreate(s32 num, s32 attr);
void SprKill(s16 idx);
void SprPosSet(s16 grpIdx, s16 idx, s16 x, s16 y);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
void SprScaleSet(s16 group, s16 member, f32 x, f32 y);
MBModel* func_80043510_44110(s32, void*);
void func_80050AE0_516E0(void);
void func_8005321C_53E1C(f32, f32);
void func_8005670C_5730C(Vec*);
Process* func_80056B78_57778(Vec* arg0, Vec* arg1, Vec* arg2, s32 arg3); /* turn arg0 toward arg1 */
/* Object* in 58080.c; arg0 is a player index or a model (retail passes both). */
omObjData* func_80058B58_59758(void* arg0, Vec* arg1, s32 arg2, Vec* arg3);
omObjData* func_80058F18_59B18(s32 arg0, Vec* arg1, s32 arg2, void* arg3);
void func_8005DDEC_5E9EC(s32 playerNo, s16 arg1, s16 arg2, s16 arg3, u16 arg4);
void func_8005E154_5ED54(s16 playerNo);
void func_8005E260_5EE60(s16 playerIndex);
void func_8005E2B8_5EEB8(void);
s16 func_80079428_7A028(s32);
void func_80079718_7A318(s32, s32);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
void func_80082488_83088(s16 grpIdx, s16 idx, u16 a); /* sprite alpha */
void func_80088640_89240(void);
void func_8008CE5C_8DA5C(void);
void func_8008F624_90224(s32, s32, s32); /* wipe colour */
void func_800B3170_B3D70(Vec*, Vec*); /* HuVecCopy3F */
void func_800B3870_B4470(f32* mtx, f32 angle);

/* ---- overlay 54 data and bss ---- */

extern s16 D_801037D0_361640_name_54; /* 1: the model pulses, 0: normal size, -1: neither */
extern s16 D_801037D2_361642_name_54; /* the player rides the model */
extern s16 D_801037D4_361644_name_54; /* the player turns with the model */
extern s16 D_801037D6_361646_name_54; /* the model bobs */
extern f32 D_801037D8_361648_name_54; /* the player's height above the model (times its scale) */

extern MBModel* D_80103880_3616F0_name_54; /* the model */
extern GW_PLAYER* D_80103884_3616F4_name_54; /* the player */
extern s16 D_80103888_3616F8_name_54;       /* the backdrop sprite */
extern s16 D_8010388A_3616FA_name_54;       /* its animation */
extern s32 D_8010388C_3616FC_name_54;       /* the player's index (read as s16 too) */

/* ---- overlay 54 functions ---- */

void func_80102800_360670_name_54(void);
void func_801028B4_360724_name_54(omObjData* obj);
void func_80102ACC_36093C_name_54(void);
void func_80103430_3612A0_name_54(omObjData* obj);
void func_80103474_3612E4_name_54(omObjData* obj);
void func_801034C8_361338_name_54(void);
void func_801036A8_361518_name_54(void);
void func_801036EC_36155C_name_54(void);
void func_801037A8_361618_name_54(void);

#endif
