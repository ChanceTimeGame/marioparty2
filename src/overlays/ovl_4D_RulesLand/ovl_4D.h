#ifndef _OVL_4D_H
#define _OVL_4D_H

#include "common.h"
#include "game/board.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "process.h"
#include "game/gamemes.h"
#include "game/data.h"
#include "game/malloc.h"
#include "game/pad.h"

/* Overlay 4D: Rules Land's turn-order scene (main's board index 17). The host and the four players
   arrive through a warp model that scales up and down, drop in, hit the dice blocks; the result sorts gPlayers[]
   by rank in unk_1C and the host reads the order out. Ends with omOvlReturnEx(1). */

#define PM(i) ((MBModel*)gPlayers[i].unk_24)

/* main */
GW_PLAYER* BoardPlayerGet(s32);
extern u16 D_801011FC_101DFC;
void HidePlayerHUDVisibility(s32 arg0, s32 arg1);
void HuVecCopyXYZ(Vec*, f32, f32, f32);
f32 HuVecDistance(Vec* a, Vec* b);
void MBDBackKill(void);
u16 MBMotionCheck(void* arg0);
void MBMotionSet(void*, s16, u16);
void MBMotionShiftSet(void* ptr, s16 a, s16 b, s16 c, u16 d);
s32 PlaySound(s32);
f32 __sinf(f32);
/* ?? */ void bcopy();
void func_80026D28_27928(s32);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_800283DC_28FDC(s16 arg0);
MBModel* func_80043510_44110(s32, void*);
void func_800461C8_46DC8(void);
void func_80046238_46E38(void);
void func_80046308_46F08(s32 arg0);
void func_80046CD8_478D8(s32 arg0);
s32 func_80046D2C_4792C(s32);
s16 func_80046F98_47B98(s32);
void func_80047B78_48778(void);
void func_80047BB8_487B8(s32);
void func_80047D2C_4892C(void);
void func_80047DB0_489B0(s32 arg0, s32 arg1);
s32 func_80047DE8_489E8(s32);
void func_80050AE0_516E0(void);
void func_8005321C_53E1C(f32, f32);
void func_80056658_57258(Vec*, Vec*, Vec*);
void func_8005812C_58D2C(s32 arg0);
void func_80059400_5A000(void);
s32 func_80059520_5A120(MBModel* arg0, s32 arg1, s32 arg2);
void func_800595E8_5A1E8(void* arg0, s32 arg1, s32 arg2);
void func_8005E130_5ED30(s16 arg0, u32* arg1);
void func_8005E260_5EE60(s16 playerIndex);
void func_8005FE10_60A10(void);
void func_8005FF9C_60B9C(void);
s32 func_80060210_60E10(s32);
s32 func_800609D8_615D8(void);
void func_8006AE14_6BA14(GAMEMES* gMes);
void func_80079718_7A318(s32, s32);
void func_800890CC_89CCC(s16, s32, s32, s32);
void func_80089A48_8A648(s16, s16);
void func_8008AD44_8B944(s16 win);
s32 func_8008DFC4_8EBC4(s16 x, s16 y, s32 style);
void func_8008E2DC_8EEDC(s32 winId, s32 sound);
void func_8008E4D0_8F0D0(s32 winId, s32 sound);
void func_8008E6AC_8F2AC(s16 arg0);
void func_8008F624_90224(s32, s32, s32);
void func_800B3170_B3D70(Vec*, Vec*);
void omDelObj(omObjData*);
void MBModelDispOff(MBModel*);
void MBModelDispOn(MBModel*);
void MBModelKill(void*);
void MBModelInit(void);
void MBModelInit(void);

/* data */
extern omObjData* D_80103D50_329F80_RulesLand[16];
extern s32 D_80103D90_329FC0_RulesLand[4]; /* -1 = free, else a sprite id */
extern MBModel* D_80103DA0_329FD0_RulesLand[4]; /* [0] the host */
extern omObjData* D_80103DB0_329FE0_RulesLand[4];
extern s32 D_80103DC0_329FF0_RulesLand;
extern s32 D_80103DC4_329FF4_RulesLand;
extern s32 D_80103DC8_329FF8_RulesLand;
extern Process* D_80103DCC_329FFC_RulesLand;
extern s32 D_80103DD0_32A000_RulesLand; /* the window's y */
extern Vec D_80103DD4_32A004_RulesLand;
extern Vec D_80103DE0_32A010_RulesLand;
extern Vec D_80103DEC_32A01C_RulesLand[4]; /* player landing spots */
extern u32* D_80103EF4_32A124_RulesLand[6]; /* motion lists by character */
extern s32 D_80103F0C_32A13C_RulesLand[4];
extern Vec D_80103F1C_32A14C_RulesLand;
extern Vec D_80103F28_32A158_RulesLand[4];

/* bss */
extern GAMEMES D_80103F90_32A1C0_RulesLand;
extern u8 D_80104004_32A234_RulesLand;
extern s16 D_80104006_32A236_RulesLand;

/* overlay */
void func_80102800_328A30_RulesLand(void);
void func_80102880_328AB0_RulesLand(s32 a, s32 b);
void func_80102908_328B38_RulesLand(void);
void func_801029AC_328BDC_RulesLand(MBModel* model);
void func_80102A50_328C80_RulesLand(MBModel* model);
void func_80102AD4_328D04_RulesLand(void);
void func_80103220_329450_RulesLand(void);
void func_80103294_3294C4_RulesLand(void);
void func_80103330_329560_RulesLand(void);
void func_801033E4_329614_RulesLand(omObjData* obj);
void func_80103438_329668_RulesLand(void);
void func_80103464_329694_RulesLand(void);
void func_80103590_3297C0_RulesLand(void);
void func_8010364C_32987C_RulesLand(void);
void func_80103670_3298A0_RulesLand(void);
void func_801036B0_3298E0_RulesLand(void);
void func_801036E0_329910_RulesLand(void);
void func_80103748_329978_RulesLand(void);

#endif /* _OVL_4D_H */
