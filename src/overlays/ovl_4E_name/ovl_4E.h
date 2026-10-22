#ifndef _OVL_4E_H
#define _OVL_4E_H

/* Overlay 4E: mode and character setup (see the summary at the top of 32A1C0.c once written).
   Retail's overlay is two files, split at the text pad after func_80109778: 32A1C0.c
   (80102800-80109778) and 331200.c (80109840-). .data and .bss stay asm; both files' .rodata
   is carved (0x335190, 0x335430).
   Prototypes past func_8010760C came from m2c's register use only: the fork that owns a function
   fixes its line. */

#include "common.h"
#include "process.h"
#include "game/object.h"
#include "game/board.h"
#include "game/gamemes.h"
#include "game/sprite.h"
#include "game/window.h"
#include "game/pad.h"

#define ABS(x) ((x) < 0 ? -(x) : (x))

/* ---- types ---- */

/* A camera key (0x1C): D_8010E144 points at a table of them (D_8010D1F8 has one). */
typedef struct Ovl4ECamKey {
    /* 0x00 */ Vec pos;
    /* 0x0C */ Vec unk0C;
    /* 0x18 */ f32 unk18;
} Ovl4ECamKey; /* size = 0x1C */

/* ---- main ---- */

/* Main symbols this overlay reaches at an offset (declared raw; their own types are elsewhere). */
extern u8 D_800F9D48_FA948[];   /* [0x2F8 + i]: per-player byte, set to i (the player order) */
extern s8 D_800FC9B8_FD5B8[];   /* [2 + i]: per-player byte, cleared */
extern s16 D_800FC8F0_FD4F0[];  /* [2] (0x800FC8F4) cleared */
extern s16 D_800F904A;
extern s16 D_800FA1A8;          /* chosen item of the three-row menu (func_80103034) */
extern s8 ContStkX[4];
extern s8 ContStkY[4];
extern s16 D_801013B8_101FB8[]; /* CenterM + 8; [0x20] (0x801013F8): 0 or 7 */

void CameraViewportSet(s16, Vec*, Vec*);
void Hu3DCamSetPositionOrientation(s16, Vec*, Vec*, Vec*);
void Hu3DCamUpdateMtx(s16 camIndex);
void Hu3DCamSetPerspective(s16, f32, f32, f32);
f32 HuMathSin(f32);
s16 LoadFormFile(s32, s32);
void MBMotionSet(MBModel*, s16, s32);
s32 PlaySound(s32);
void PlayMusic(s16);
void InitFadeOut(s32, s32);
void InitFadeIn(s32, s32);
void ScissorSet(u8 arg0, f32 x1, f32 y1, f32 x2, f32 y2);
void SprAnimKill(s16 animIdx);
void SprPosSet(s16 grpIdx, s16 idx, s16 x, s16 y);
void espDispOff(u16);
void espDispOn(u16);
void espPosSet(u16 spriteId, s16 x, s16 y);
void MBModelInit(void);
void omInitObjMan(s32, s32);
s16 func_8001A2F8_1AEF8(s32 arg0);
void func_8001A6BC_1B2BC(u16 spriteId, s16 arg1);
void func_8001A788_1B388(u16 spriteId, s32 arg1);
void func_8001A91C_1B51C(u16 spriteId, f32 x, f32 y); /* sprite scale */
s16 func_8001AAAC_1B6AC(s16 arg0, u16 arg1, u16 arg2);
void func_8001AC44_1B844(u16 arg0);
void func_80020070_20C70(s32);
void func_80020D20_21920(s16 arg0);
void func_80026D28_27928(s32);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
s16 func_80027D3C_2893C(s16 linkMdlId); /* model copy */
void func_80029708_2A308(s32);
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void func_8002979C_2A39C(s16, f32, f32, f32); /* model rotation */
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_8002C59C_2D19C(s16 arg0, s16 arg1, u8 arg2, u8 arg3, u8 arg4);
void func_8002CA48_2D648(u8 arg0, u8 arg1, u8 arg2);
void func_8002D4D0_2E0D0(s16 n);
void func_80050A30_51630(u8*);
void func_80056658_57258(Vec*, Vec*, Vec*); /* direction from a to b as a rotation */
void func_800581A0_58DA0(void);
void func_800593C0_59FC0(void);
void func_8005965C_5A25C(void);
void func_8005A4EC_5B0EC(s32 player, s32 reaction); /* a player's reaction */
s32 func_8005A5E8_5B1E8(MBModel* model, Vec* target, f32 speed); /* walk toward; 1 on arrival */
void func_8005E2B8_5EEB8(void);
s16 func_800691FC_69DFC(s16 mesNo, ...);
s32 func_80069538_6A138(void);
void func_80069654_6A254(s16 mesId); /* close a message */
void func_8006985C_6A45C(GAMEMES* gMes);
s16 func_8006A608_6B208(void* mes, char* str, u8 arg2, s16 arg3, s16 arg4); /* MP1 GMesFontMesCreate */
s16 func_8006A67C_6B27C(GAMEMES*, char*, u8, s16, s16);
void func_800797DC_7A3DC(s32, s16);
HuSprite* func_80082550_83150(s16 grpIdx, s16 idx);
void func_80088640_89240(void);
void func_800890CC_89CCC(s16, s32, s32, s32);
void func_80089284_89E84(s16, s32, s32);
s32 func_8008DFC4_8EBC4(s16 x, s16 y, s32 style);
void func_8008E2DC_8EEDC(s32 winId, s32 sound);
void func_8008E4D0_8F0D0(s32 winId, s32 sound);
void func_8008E644_8F244(s32 arg0, u8 arg1);
u32 func_800A5610_A6210(char*); /* strlen */
f32 func_800B7890_B8490(f32); /* cos */

extern u8 D_01164160[];

/* ---- data (.data, asm) ---- */

extern s16 D_8010D1F0_334BB0_name_4E;
extern s16 D_8010D1F4_334BB4_name_4E;
extern Ovl4ECamKey D_8010D1F8_334BB8_name_4E[];
extern s32 D_8010D214_334BD4_name_4E[];
extern Vec D_8010D4FC_334EBC_name_4E[4]; /* default positions (D_8010DBE8) */
extern Vec D_8010D544_334F04_name_4E[4]; /* 1 vs 3 positions */
extern Vec D_8010D574_334F34_name_4E[4]; /* 2 vs 2 positions */
extern Vec D_8010D5A4_334F64_name_4E;
extern Vec D_8010D5B0_334F70_name_4E;
extern Vec D_8010D5BC_334F7C_name_4E;
extern Vec D_8010D5C8_334F88_name_4E;
extern s32 D_8010D5D4_334F94_name_4E[8]; /* message ids (D_8010DC2C) when D_8010DAB6 */
extern s32 D_8010D5F4_334FB4_name_4E[8]; /* ... otherwise */
extern s16 D_8010D614_334FD4_name_4E[4]; /* second menu row -> D_801013F8 */
extern s16 D_8010D61C_334FDC_name_4E[6]; /* third menu (1 vs 3): x offsets of the icons [1..4] and D_8010DAF0 [5] */
extern s16 D_8010D628_334FE8_name_4E[6]; /* ... 2 vs 2 */
extern s8 D_8010D634_334FF4_name_4E[4][4]; /* third menu (1 vs 3): icon order per choice */
extern s8 D_8010D644_335004_name_4E[4][4]; /* ... 2 vs 2 */
extern s8 D_8010D654_335014_name_4E[4][4]; /* (1 vs 3): D_8010DBE8 slot of each D_8010D544 position */
extern s8 D_8010D664_335024_name_4E[4][4]; /* ... 2 vs 2, D_8010D574 */
extern f32 D_8010D7B0_335170_name_4E;   /* camera field of view */

/* ---- bss (asm) ---- */

extern s16 D_8010DAB6_335476_name_4E;
extern s16 D_8010DAB8_335478_name_4E;
extern u16 D_8010DABC_33547C_name_4E;
extern u16 D_8010DAC4_335484_name_4E[3]; /* first menu's three row sprites */
extern u16 D_8010DAD2_335492_name_4E[4]; /* second menu's four row sprites */
extern u16 D_8010DAE6_3354A6_name_4E[6]; /* third menu: [0] panel, [1..4] = D_8010DAE8, [5] = D_8010DAF0 */
extern u16 D_8010DAE8_3354A8_name_4E[4]; /* third menu: the four character icons */
extern u16 D_8010DAF0_3354B0_name_4E;
extern s16 D_8010DB60_335520_name_4E;
extern s16 D_8010DBE0_3355A0_name_4E;
extern u8 D_8010DBE2_3355A2_name_4E;
extern s8 D_8010DBE3_3355A3_name_4E;
extern Vec D_8010DBE8_3355A8_name_4E[4]; /* per-player target positions */
extern s8 D_8010DC20_3355E0_name_4E;
extern s32* D_8010DC2C_3355EC_name_4E; /* current message-id table */
extern s16 D_8010DC90_335650_name_4E;
extern s16 D_8010DCA0_335660_name_4E[4];
extern s16 D_8010DCA6_335666_name_4E;   /* = D_8010DCA0[3] */
extern s16 D_8010E140_335B00_name_4E;
extern Ovl4ECamKey* D_8010E144_335B04_name_4E;
extern f32 D_8010E150_335B10_name_4E;   /* camera far */
extern s16 D_8010E5F2_335FB2_name_4E;   /* cursor */
extern s16 D_8010E5F4_335FB4_name_4E;   /* controlling pad */
extern s16 D_8010E154_335B14_name_4E;
extern s16 D_8010E618_335FD8_name_4E;
extern f32 D_8010E63C_335FFC_name_4E;   /* camera near */
extern s32 D_8010E648_336008_name_4E[];

/* ---- 32A1C0.c ---- */

void func_80102800_32A1C0_name_4E(void);
void func_80102B94_32A554_name_4E(void);
void func_80102B9C_32A55C_name_4E(void);
s32 func_80103034_32A9F4_name_4E(void);
s32 func_80103608_32AFC8_name_4E(void);
s32 func_80103CD0_32B690_name_4E(void);
void func_801047B8_32C178_name_4E(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void func_801047E8_32C1A8_name_4E(void);
void func_80104A9C_32C45C_name_4E(void);
s32 func_80104AF0_32C4B0_name_4E(void);
void func_80105090_32CA50_name_4E(void);
void func_80105148_32CB08_name_4E(void);
void func_801053E0_32CDA0_name_4E(s16 arg0, s16 arg1, s32 arg2);
s32 func_80105454_32CE14_name_4E(void);
s32 func_80105F80_32D940_name_4E(void);
s32 func_80106228_32DBE8_name_4E(s32 arg0);
void func_801064F0_32DEB0_name_4E(s32 arg0);
void func_80106BF8_32E5B8_name_4E(s32 arg0, s32 arg1, s32 arg2);
void func_80106C30_32E5F0_name_4E(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void func_80106CB0_32E670_name_4E(void);
void func_80106E18_32E7D8_name_4E(void);
void func_801070AC_32EA6C_name_4E(u8 *arg0, s16 arg1);
void func_80107324_32ECE4_name_4E(void);
void func_8010732C_32ECEC_name_4E(s16 arg0);
void func_80107554_32EF14_name_4E(void);
void func_8010760C_32EFCC_name_4E(s32 arg0);
s32 func_80107638_32EFF8_name_4E(void);
void func_801076C0_32F080_name_4E(void);
void func_801076E4_32F0A4_name_4E(void);
void func_801076F4_32F0B4_name_4E(void);
void func_80107718_32F0D8_name_4E(s32 arg0, s8 arg1);
void func_80107748_32F108_name_4E(s16 arg0, s32 arg1, s32 arg2);
void func_80107804_32F1C4_name_4E(s16 arg0, s32 arg1, s32 arg2);
void func_801078EC_32F2AC_name_4E(s32 arg0, s16 arg1, s32 arg2, s32 arg3);
void func_80107940_32F300_name_4E(s32 arg0, void *arg1, s16 arg2, s16 arg3);
void func_801079AC_32F36C_name_4E(void);
s16 func_801079EC_32F3AC_name_4E(s16 arg0, s16 arg1, s16 arg2, s32 arg3);
void func_80107D3C_32F6FC_name_4E(omObjData* obj);
void func_80107E34_32F7F4_name_4E(void);
void func_80107F10_32F8D0_name_4E(void);
void func_8010832C_32FCEC_name_4E(void);
void func_8010896C_33032C_name_4E(void);
void func_80108A18_3303D8_name_4E(void);
void func_80108BE0_3305A0_name_4E(void);
s32 func_80108E3C_3307FC_name_4E(s32 arg0, s16 arg1, s16 arg2, s16 arg3);
void func_80108F24_3308E4_name_4E(void);
void func_80109750_331110_name_4E(s16 arg0);
void func_80109778_331138_name_4E(void);

/* ---- 331200.c ---- */

s32 func_80109840_331200_name_4E(s32 arg0);
void func_80109914_3312D4_name_4E(void);
u32 func_8010993C_3312FC_name_4E(u32 arg0);
void func_80109988_331348_name_4E(void);
void func_801099D4_331394_name_4E(omObjData* obj);
void func_8010A244_331C04_name_4E(void);
void func_8010A2A0_331C60_name_4E(void);
void func_8010A300_331CC0_name_4E(void);
void func_8010A438_331DF8_name_4E(s32 arg0);
void func_8010A588_331F48_name_4E(void);
void func_8010A660_332020_name_4E(u32 arg0);
void func_8010AB48_332508_name_4E(void);
s16 func_8010AB58_332518_name_4E(void);
void func_8010AB64_332524_name_4E(void);
void func_8010ADE0_3327A0_name_4E(omObjData* obj);
void func_8010B480_332E40_name_4E(s16 arg0);
void func_8010B528_332EE8_name_4E(s16 arg0, s16 arg1, s16 arg2, void* fn);
void func_8010BCB8_333678_name_4E(f32 *arg0, f32 arg1, void* fn);
void func_8010C218_333BD8_name_4E(void);
void func_8010C4AC_333E6C_name_4E(void);
void func_8010C5BC_333F7C_name_4E(s16 arg0);
void func_8010C5F4_333FB4_name_4E(s32* arg0);
void func_8010C600_333FC0_name_4E(s16 arg0);
void func_8010C60C_333FCC_name_4E(s16 arg0);
void func_8010C618_333FD8_name_4E(s32 *arg0);
void func_8010C708_3340C8_name_4E(s32 arg0, s16 arg1, s16 arg2);
void func_8010C7AC_33416C_name_4E(s32 *arg0, s16 arg1);
void func_8010C86C_33422C_name_4E(s16 arg0, void *arg1, s32 arg2);
void func_8010C96C_33432C_name_4E(s16 arg0, s32 arg1);
void func_8010C9AC_33436C_name_4E(void *arg1, void *arg2);
void func_8010CCB4_334674_name_4E(s16 arg0, f32 arg1, void *arg2, void *arg3);
void func_8010CF6C_33492C_name_4E(void);

#endif /* _OVL_4E_H */
