#ifndef _OVL_4E_H
#define _OVL_4E_H

/* Overlay 4E: a "first to N wins" minigame match. The main process (func_80102B9C) runs three
   sliding menus: match length (func_80103034: 3/5/7 wins, D_800FA1A8), team mode
   (func_80103608: 4P, 1 vs 3, 2 vs 2, ...; D_801013F8), and for team modes the team layout
   (func_80103CD0: sets D_800FA040[] and gPlayers[].group). func_80104AF0 then picks the minigame
   (the list in 331200.c, or the only one) and leaves through omOvlHisChg: with D_8010DAB6 to
   the minigame itself (event 4), otherwise to a duel on a board (event 5). Coming back
   (D_800CD414 >= 4) the overlay starts in state 4 (func_80105454): wins are added and stamped
   on the score board, and once a player reaches the target the winners are announced.
   Retail's overlay is two files, split at the text pad after func_80109778: 32A1C0.c
   (80102800-80109778) and 331200.c (80109840-). .data and .bss stay asm; both files' .rodata
   is carved (0x335190, 0x335430). 32A1C0.c builds with the KMC mul fix.
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
#include "game/camera.h"
#include "game/hmfman.h"

#define PLAYER_MODEL(i) ((MBModel*)gPlayers[i].unk_24)
#define OVL4E_CAMERA ((HuCamera*)D_800FD2A8_FDEA8)
#define ABS(x) ((x) < 0 ? -(x) : (x))

/* ---- types ---- */

/* A camera key (0x1C): D_8010E144 points at a table of them (D_8010D1F8 has one). */
typedef struct Ovl4ECamKey {
    /* 0x00 */ Vec pos;
    /* 0x0C */ Vec unk0C;
    /* 0x18 */ f32 unk18;
} Ovl4ECamKey; /* size = 0x1C */

/* A view of main's esprite slot (1AE60.c's local EspriteSlot, D_800F93FC). */
typedef struct Ovl4EEsprite {
    /* 0x00 */ char pad00[0xA];
    /* 0x0A */ s16 x;
    /* 0x0C */ s16 y;
    /* 0x0E */ char pad0E[0x16];
} Ovl4EEsprite; /* size = 0x24 */

/* ---- main ---- */

extern void* D_800F93FC_F9FFC; /* 1AE60.c: EspriteSlot* */

/* Main symbols this overlay reaches at an offset (declared raw; their own types are elsewhere). */
extern u8 D_800F9D48_FA948[];   /* [0x2F8 + i]: per-player byte, set to i (the player order) */
extern u8 D_800FC9B8_FD5B8[];   /* [2 + i]: per-player byte, cleared; copied to stars */
extern s16 D_800FC8F0_FD4F0[];  /* [2] (0x800FC8F4) cleared */
extern s16 D_800F904A;
extern u8 D_800F9512_FA112;
extern s32 D_800FC880_FD480;   /* team mode 7: the single winner, or -1 */
extern BattleTargets D_800F8D1A_F991A;
void _SetFlag(s32);
void omOvlHisChg(s16 arg0, s32 overlay, s16 event, s16 stat);
s32 func_8003F6F0_402F0(s16);
extern s16 D_800FA1A8;          /* chosen item of the three-row menu (func_80103034) */
extern s8 ContStkX[4];
extern s8 ContStkY[4];
/* CenterM + 8 (main); only its 0x40 field is used here: the setup's team mode (0 4P, 1 1 vs 3,
   2 2 vs 2, 3 ...; 7 is set on some exits). */
typedef struct Ovl4ECenter {
    /* 0x00 */ char pad00[0x40];
    /* 0x40 */ s16 unk40;
} Ovl4ECenter;
extern Ovl4ECenter D_801013B8_101FB8;

void CameraViewportSet(s16, Vec*, Vec*);
void Hu3DCamSetPositionOrientation(s16, Vec*, Vec*, Vec*);
void Hu3DCamUpdateMtx(s16 camIndex);
void Hu3DCamSetPerspective(s16, f32, f32, f32);
f32 HuMathSin(f32);
s16 LoadFormFile(s32, s32);
void MBMotionSet(MBModel*, s16, s32);
s32 PlaySound(s32);
s16 PlayMusic(s16);
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

extern u16 D_8010D1F0_334BB0_name_4E; /* leave the setup (FE4E-B: u16, retail tests it with lhu) */
extern s16 D_8010D1F2_334BB2_name_4E;
extern s16 D_8010D1F4_334BB4_name_4E;
extern Ovl4ECamKey D_8010D1F8_334BB8_name_4E[];
extern s32 D_8010D214_334BD4_name_4E[];
extern u8 D_8010D448_334E08_name_4E[4];  /* wins needed per first-menu choice: 3, 5, 7 */
extern u8 D_8010D44C_334E0C_name_4E[4];  /* per team mode: stamp row spacing (FE4E-B: u8, retail reads it with lbu) */
extern u16 D_8010D4AC_334E6C_name_4E[];  /* per first-menu choice: stamp column origin */
extern Vec D_8010D4FC_334EBC_name_4E[4]; /* default positions (D_8010DBE8) */
extern Vec D_8010D52C_334EEC_name_4E[2]; /* team mode 7 positions */
extern Vec D_8010D544_334F04_name_4E[4]; /* 1 vs 3 positions */
extern Vec D_8010D574_334F34_name_4E[4]; /* 2 vs 2 positions */
extern Vec D_8010D5A4_334F64_name_4E;
extern Vec D_8010D5B0_334F70_name_4E;
extern Vec D_8010D5BC_334F7C_name_4E;
extern Vec D_8010D5C8_334F88_name_4E;
extern s32 D_8010D5D4_334F94_name_4E[8]; /* message ids (D_8010DC2C) when D_8010DAB6 */
extern s32 D_8010D5F4_334FB4_name_4E[8]; /* ... otherwise */
extern s16 D_8010D5FE_334FBE_name_4E[]; /* board per minigame index (inside D_8010D5F4's words) */
extern s32 D_8010D680_335040_name_4E[2]; /* messages naming two winners */
extern s32 D_8010D688_335048_name_4E[3]; /* ... three winners */
extern char* D_8010D694_335054_name_4E[7]; /* per character: name (" MARIO " ... "  ALL  ") */
extern s16 D_8010D614_334FD4_name_4E[4]; /* second menu row -> D_801013F8 */
extern s16 D_8010D61C_334FDC_name_4E[6]; /* third menu (1 vs 3): x offsets of the icons [1..4] and D_8010DAF0 [5] */
extern s16 D_8010D628_334FE8_name_4E[6]; /* ... 2 vs 2 */
extern s8 D_8010D634_334FF4_name_4E[4][4]; /* third menu (1 vs 3): icon order per choice */
extern s8 D_8010D644_335004_name_4E[4][4]; /* ... 2 vs 2 */
extern s8 D_8010D654_335014_name_4E[4][4]; /* (1 vs 3): D_8010DBE8 slot of each D_8010D544 position */
extern s8 D_8010D664_335024_name_4E[4][4]; /* ... 2 vs 2, D_8010D574 */
extern f32 D_8010D7B0_335170_name_4E;   /* camera field of view */

/* ---- bss (asm) ---- */

extern u8 D_8010DA80_335440_name_4E[4]; /* per player: walking (func_80105148) */
extern s16 D_8010DA90_335450_name_4E;   /* closes the message window (func_80107554) */

extern s16 D_8010DAB6_335476_name_4E;
extern s16 D_8010DAB8_335478_name_4E;
extern u16 D_8010DABC_33547C_name_4E;
extern u16 D_8010DAC4_335484_name_4E[3]; /* first menu's three row sprites */
extern u16 D_8010DAD2_335492_name_4E[4]; /* second menu's four row sprites */
extern u16 D_8010DAE6_3354A6_name_4E[6]; /* third menu: [0] panel, [1..4] = D_8010DAE8, [5] = D_8010DAF0 */
extern u16 D_8010DAE8_3354A8_name_4E[4]; /* third menu: the four character icons */
extern u16 D_8010DAF0_3354B0_name_4E;
extern s16 D_8010DAF2_3354B2_name_4E[4]; /* per player: sprite animations */
extern u16 D_8010DAFA_3354BA_name_4E[4]; /* per player: esprites */
extern s16 D_8010DB02_3354C2_name_4E;
extern u16 D_8010DB04_3354C4_name_4E;
extern s16 D_8010DB06_3354C6_name_4E[5];
extern s16 D_8010DB10_3354D0_name_4E[8];
extern s16 D_8010DB1A_3354DA_name_4E;
extern s16 D_8010DB20_3354E0_name_4E[32];
extern s16 D_8010DB60_335520_name_4E;   /* the message window */
extern s16 D_8010DB62_335522_name_4E;   /* 1: window sound request (func_80107554) */
extern u8 D_8010DB68_335528_name_4E[0x20]; /* a 0x20-byte message state (func_8006985C) */
extern s16 D_8010DB88_335548_name_4E[];
extern s16 D_8010DBDC_33559C_name_4E;
extern s16 D_8010DBDE_33559E_name_4E;
extern s16 D_8010DBE0_3355A0_name_4E;
extern u8 D_8010DBE2_3355A2_name_4E;
extern u8 D_8010DBE3_3355A3_name_4E;   /* bit per player: may walk to D_8010DBE8 (func_80105148) */
extern u8 D_8010DBE4_3355A4_name_4E;   /* walk speed */
extern Vec D_8010DBE8_3355A8_name_4E[4]; /* per-player target positions */
extern s8 D_8010DC20_3355E0_name_4E;   /* the team menu is waiting for input (arrows shown) */
extern s8 D_8010DC21_3355E1_name_4E;   /* move the arrows to D_8010DC22.. (func_801047B8) */
extern s16 D_8010DC22_3355E2_name_4E;
extern s16 D_8010DC24_3355E4_name_4E;
extern s16 D_8010DC26_3355E6_name_4E;
extern s16 D_8010DC28_3355E8_name_4E;
extern s32* D_8010DC2C_3355EC_name_4E; /* current message-id table */
extern omObjData* D_8010DC1C_3355DC_name_4E; /* the winners' models (func_801070AC) */
extern s16 D_8010DC90_335650_name_4E;
extern s16 D_8010DCA0_335660_name_4E[4];
extern s16 D_8010DCA6_335666_name_4E;   /* = D_8010DCA0[3] */
extern s16 D_8010DCC0_335680_name_4E[4][0x48]; /* per team mode: the minigames (D_8010DCA0 = count) */
extern s16 D_8010E140_335B00_name_4E;
extern Ovl4ECamKey* D_8010E144_335B04_name_4E;
extern f32 D_8010E150_335B10_name_4E;   /* camera far */
extern s16 D_8010E5F2_335FB2_name_4E;   /* cursor */
extern s16 D_8010E5F4_335FB4_name_4E;   /* controlling pad */
extern s16 D_8010E154_335B14_name_4E;
extern s16 D_8010E618_335FD8_name_4E;
extern f32 D_8010E63C_335FFC_name_4E;   /* camera near */
/* FE4E-B: per-slot screen positions (s16 x, y) */
typedef struct Ovl4EPos16 {
    s16 x;
    s16 y;
} Ovl4EPos16;
extern Ovl4EPos16 D_8010E648_336008_name_4E[];

/* ---- FE4E-B ---- */


extern s8 D_8010DA98_335458_name_4E[20];
extern Vec2f D_8010E148_335B08_name_4E; /* last projected screen position */

s16 func_8008BA30_8C630(s16 winId);
s32 func_8008BB48_8C748(s16, s16, s32);
void func_8008D904_8E504(s16 winId, s32, s8);
void func_80023554_24154(s16 model, s16 frame, char* part, f32 mtx[4][4]); /* part matrix */
f32 func_80029CE4_2A8E4(s16 model); /* motion frame */
void* func_8002A9F4_2B5F4(s16 model, char* part); /* HmfMotionObj* or HitXform* */
f32 func_800B1830_B2430(f32); /* sqrtf */
extern u16 D_801011FC_101DFC;
extern u8 D_800CB150;
extern u16 D_8010E5F0_335FB0_name_4E; /* esprite freed on leaving */
void MBDBackKill(void);
void func_80050AE0_516E0(void);
extern s16 D_8010DC18_3355D8_name_4E;  /* backdrop sprite file */
extern u16 D_8010DC1A_3355DA_name_4E;  /* backdrop esprite */
extern s16 D_8010DC92_335652_name_4E;  /* host model */
extern s16 D_8010DCB0_335670_name_4E;
extern void* D_8010D400_334DC0_name_4E[6]; /* per character: player model motions */
extern void* D_8010D418_334DD8_name_4E[6]; /* ... when D_800CD414 & 4 */
extern Vec D_8010D4B4_334E74_name_4E;  /* off-stage position */
MBModel* func_80043510_44110(s32, void*);
void func_8001A708_1B308(u16, u16);
void func_8002C9C0_2D5C0(s16, s16);
void func_800298A4_2A4A4(s16, s32, s32);
void MBModelDispOff(MBModel*);
void MBModelDispOn(MBModel*);
extern Vec D_8010D4C0_334E80_name_4E;    /* host's arrival position */
extern Vec D_8010D4CC_334E8C_name_4E[4]; /* players' hop targets */
f32 HuVecDistance(Vec*, Vec*);
void MBModelKill(void*);
void MBMotionShiftSet(void* arg0, s16 arg1, s32 arg2, s32 arg3, u16 arg4);
extern u16 D_8010DABA_33547A_name_4E;    /* the panel's sprite animation */
extern s16 D_8010DABE_33547E_name_4E[3]; /* first menu rows' sprite animations */
extern s16 D_8010DACA_33548A_name_4E[4]; /* second menu rows' sprite animations */
extern s16 D_8010DADA_33549A_name_4E[6]; /* third menu's sprite animations */
extern s32 D_8010D2DC_334C9C_name_4E[3]; /* sprite files: first menu rows */
extern s32 D_8010D2E8_334CA8_name_4E[4]; /* ... second menu rows */
extern s32 D_8010D2F8_334CB8_name_4E[6]; /* ... third menu */
extern s32 D_8010D430_334DF0_name_4E[6];  /* per character: score board icon file */
extern s32* D_8010D48C_334E4C_name_4E[6]; /* per match length (+3 when no team mode): board sprite files */
extern s16 D_8010D4A4_334E64_name_4E[4];  /* per team mode: team icons' y */
extern char D_8010DA84_335444_name_4E[];  /* "<n>=WIN MATCH" */

/* ---- 32A1C0.c ---- */

void func_80102800_32A1C0_name_4E(void);
void func_80102B94_32A554_name_4E(void);
void func_80102B9C_32A55C_name_4E(void);
s32 func_80103034_32A9F4_name_4E(void);
s32 func_80103608_32AFC8_name_4E(void);
s32 func_80103CD0_32B690_name_4E(void);
void func_801047B8_32C178_name_4E(s16 x0, s16 y0, s16 x1, s16 y1);
void func_801047E8_32C1A8_name_4E(void);
void func_80104A9C_32C45C_name_4E(void);
s32 func_80104AF0_32C4B0_name_4E(void);
void func_80105090_32CA50_name_4E(void);
void func_80105148_32CB08_name_4E(void);
void func_801053E0_32CDA0_name_4E(s32 player, s16 motion, u16 attr);
s32 func_80105454_32CE14_name_4E(void);
s32 func_80105F80_32D940_name_4E(void);
s32 func_80106228_32DBE8_name_4E(u8* wins);
void func_801064F0_32DEB0_name_4E(u8* wins);
void func_80106BF8_32E5B8_name_4E(u16 spr, s32 dx, s32 dy);
void func_80106C30_32E5F0_name_4E(s16 grp, s16 idx, s16 dx, s16 dy);
void func_80106CB0_32E670_name_4E(void);
void func_80106E18_32E7D8_name_4E(void);
void func_801070AC_32EA6C_name_4E(u8* list, s16 count);
void func_80107324_32ECE4_name_4E(void);
void func_8010732C_32ECEC_name_4E(s16 player);
void func_80107554_32EF14_name_4E(void);
void func_8010760C_32EFCC_name_4E(s32 mes);
s32 func_80107638_32EFF8_name_4E(void);
void func_801076C0_32F080_name_4E(void);
void func_801076E4_32F0A4_name_4E(void);
void func_801076F4_32F0B4_name_4E(void);
void func_80107718_32F0D8_name_4E(s32 arg0, s16 arg1);
void func_80107748_32F108_name_4E(s16 model, s32 spr, char* part);
void func_80107804_32F1C4_name_4E(s32 model, s32 spr, char* part);
void func_801078EC_32F2AC_name_4E(s16 i, s16 esp, s32 dx, s32 dy);
void func_80107940_32F300_name_4E(s16 i, Vec2f* pos, s16 dx, s16 dy);
void func_801079AC_32F36C_name_4E(void);
s16 func_801079EC_32F3AC_name_4E(s16 cur, s16 n, s16 dx, s16 dy);
void func_80107D3C_32F6FC_name_4E(omObjData* obj);
void func_80107E34_32F7F4_name_4E(omObjData* obj);
void func_80107F10_32F8D0_name_4E(void);
void func_8010832C_32FCEC_name_4E(void);
void func_8010896C_33032C_name_4E(void);
void func_80108A18_3303D8_name_4E(void);
void func_80108BE0_3305A0_name_4E(void);
s32 func_80108E3C_3307FC_name_4E(s16 i, s16 x, s16 y, s16 n);
void func_80108F24_3308E4_name_4E(void);
void func_80109750_331110_name_4E(s16 cursor);
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
void func_8010A660_332020_name_4E(s16 arg0);
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
void func_8010C5F4_333FB4_name_4E(Ovl4EPos16* arg0);
void func_8010C600_333FC0_name_4E(s16 arg0);
void func_8010C60C_333FCC_name_4E(s16 arg0);
void func_8010C618_333FD8_name_4E(s32 *arg0);
void func_8010C708_3340C8_name_4E(s32 arg0, s16 arg1, s16 arg2);
void func_8010C7AC_33416C_name_4E(s32 *arg0, s16 arg1);
void func_8010C86C_33422C_name_4E(s16 model, Vec* out, f32 mtx[4][4]);
void func_8010C96C_33432C_name_4E(s16 model, Vec2f* out, f32 mtx[4][4]);
void func_8010C9AC_33436C_name_4E(s32 cam, Vec* pos, Vec2f* out);
void func_8010CCB4_334674_name_4E(s16 arg0, f32 arg1, void *arg2, void *arg3);
void func_8010CF6C_33492C_name_4E(void);

#endif /* _OVL_4E_H */
