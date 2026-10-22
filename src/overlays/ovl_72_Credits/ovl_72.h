#ifndef _OVL_72_H
#define _OVL_72_H

#include "common.h"
#include "game/pad.h"
#include "game/data.h"
#include "game/hmfman.h"
#include "game/gamemes.h"

/* Overlay 72: the staff credits. A logo fades in to music 6; then each section title slides in
   from the left (GAMEMES text) while its roles and names scroll up the right side as sprite text
   built from the credits font (func_80104480); models from D_80104EDC walk across the stage
   behind, and the finale character walks in and poses. START (once flag 0xB, "credits seen", is set,
   or after the roll) ends it: back to the caller when flag 0x1A is set, else to overlay 0x57. */

typedef struct CreditsModelSlot {
    /* 0x00 */ s16 used;
    /* 0x04 */ s32 file;
    /* 0x08 */ u16 model;
} CreditsModelSlot; /* size 0xC: models preloaded from D_80104EA0 */

typedef struct CreditsModelEntry {
    /* 0x00 */ s32 file; /* -1 ends the table */
    /* 0x04 */ s32 motion; /* -1: none */
    /* 0x08 */ s32 unk08;
    /* 0x0C */ s16 unk0C;
    /* 0x10 */ f32 x;    /* start, added to 650 * the back model's scale */
    /* 0x14 */ f32 xEnd; /* subtracted from -650 * the scale */
    /* 0x18 */ Vec rot;
    /* 0x24 */ f32 scale; /* scaled by 1.1 when used (the table is changed in place) */
    /* 0x28 */ s16 frame; /* motion start: -1 the first frame, -2 the last */
} CreditsModelEntry; /* size 0x2C */

typedef struct CreditsActor {
    /* 0x00 */ s16 model;
    /* 0x02 */ s16 mdlData; /* HmfModel unk02 when created */
    /* 0x04 */ s16 motion;
    /* 0x06 */ s16 motion2;
    /* 0x08 */ char unk08[0x3C];
} CreditsActor; /* size 0x44 */

typedef struct CreditsLine {
    /* 0x00 */ u16 len;  /* characters */
    /* 0x02 */ s16 spr;  /* sprite group */
    /* 0x04 */ f32 y;    /* in: start offset; out: fraction left when the next line may start */
    /* 0x08 */ s16 next; /* set: the next line may start */
    /* 0x0A */ s16 done; /* set: scrolled off and killed */
    /* 0x0C */ s16 last;
} CreditsLine; /* size 0x10 */

typedef struct CreditsRole {
    /* 0x00 */ s16 role;   /* message, -2 a blank sprite, -1 ends the list */
    /* 0x04 */ s16* names; /* messages (-2 blank), ended by -1 */
} CreditsRole; /* size 8 */

typedef struct CreditsSection {
    /* 0x00 */ s16 title; /* message, -1 ends the table */
    /* 0x04 */ CreditsRole* roles;
} CreditsSection; /* size 8 */

extern s16 omovlhisidx;
extern u8 D_01164160[];
s32 omDelPrcObj(void*);
s32 omOvlCallEx(s32 overlayID, s16 event, u16 stat);
u16 func_80018A30_19630(s32 arg0, s32 arg1); /* model from a file */
void func_80026D28_27928(s32);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_800283DC_28FDC(s16 arg0);
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void func_8002979C_2A39C(s16, f32, f32, f32); /* model rotation */
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029BF0_2A7F0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4); /* model motion blend */
void func_80029C74_2A874(s16, f32);
f32 func_80029CE4_2A8E4(s16); /* model motion time */
f32 func_80029D0C_2A90C(s16); /* motion length */
f32 func_80029E3C_2AA3C(s16);
s32 func_8002C8B8_2D4B8(void*, s16);
void func_8002C9C0_2D5C0(s16, s16);
f32 func_8002CA14_2D614(s32);
void func_8002CA48_2D648(u8 arg0, u8 arg1, u8 arg2);
void func_80039018_39C18(s16);
void HmfModelObjAttrSet(s16, s32, s32);
f32 MBDBackMdlScaleGet(void);
void MBDBackKill(void);
void func_80050A30_51630(u8*);
void func_80050AE0_516E0(void);
void func_80050E00_51A00(s32);
void func_8005321C_53E1C(f32, f32);
void* func_80068CD4_698D4(s32 stringIndex);
void func_80068D24_69924(void* file);
void func_80069698_6A298(void);
void func_8006985C_6A45C(GAMEMES* gMes);
s16 func_8006A608_6B208(void* mes, char* str, u8 arg2, s16 arg3, s16 arg4); /* MP1 GMesFontMesCreate */
void func_8007273C_7333C(u8* arg0, u8 arg1);
void func_8007E224_7EE24(void);
void func_8008F624_90224(s32, s32, s32); /* wipe colour */
s16 SprAnimRead(void*);
void SprAnimKill(s16);
s16 SprCreate(s32 num, s32 attr);
void SprKill(s16);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprPosSet(s16, s16, s16, s16);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
void SprAttrSet(s16, s16, s32);
void SprAttrReset(s16 group, s16 member, s32 flag);
void SprScaleSet(s16, s16, f32, f32);
void func_80082450_83050(s16 grpIdx, s32 idx, s32 r, s32 g, u8 b);
void func_80082488_83088(s16, s16, u16); /* sprite alpha */
void func_800824F4_830F4(s16 group, s16 member, s16 arg2);
s16 func_80089234_89E34(u8* str); /* string length in characters */
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* cos */

/* data */
extern s32 D_80104E80_417E10_Credits; /* actor index */
extern s32 D_80104E84_417E14_Credits; /* section title waiting */
extern s32 D_80104E88_417E18_Credits; /* roll over: START ends */
extern s32 D_80104E8C_417E1C_Credits; /* end now */
extern s32 D_80104E90_417E20_Credits; /* logo shown: the roll starts */
extern s32 D_80104E94_417E24_Credits; /* role title in place */
extern s32 D_80104E98_417E28_Credits; /* role's names done */
extern s32 D_80104E9C_417E2C_Credits; /* role title gone */
extern s32 D_80104EA0_417E30_Credits[]; /* model files to preload, -1 ends */
extern s32 D_80104ED8_417E68_Credits; /* GAMEMES used */
extern CreditsModelEntry D_80104EDC_417E6C_Credits[];
extern CreditsSection D_80105994_418924_Credits[];
extern u8 D_80105AB0_418A40_Credits[];

/* bss */
/* background models (s32 slots read as s16) */
extern s32 D_80105AC0_418A50_Credits;
extern s32 D_80105AC4_418A54_Credits;
extern s32 D_80105AC8_418A58_Credits;
extern CreditsActor D_80105AD0_418A60_Credits[];
extern s32 D_80105C24_418BB4_Credits; /* font sprite anim (read as s16) */
extern s32 D_80105C28_418BB8_Credits; /* blank sprite anim (read as s16) */
extern CreditsModelSlot D_80105C30_418BC0_Credits[20];
extern CreditsLine D_80105D20_418CB0_Credits[8];
extern CreditsLine D_80105DA0_418D30_Credits;
extern GAMEMES D_80105DB0_418D40_Credits[];

void func_80102800_415790_Credits(void);
void func_801028A8_415838_Credits(void);
void func_80102A90_415A20_Credits(void);
s32 func_80102CBC_415C4C_Credits(s32 file, s32 arg1);
void func_80102D6C_415CFC_Credits(void);
void func_80102F10_415EA0_Credits(void);
s32 func_8010371C_4166AC_Credits(char* str, s16 x, s16 y, s16 arg3, s16 arg4);
void func_80103920_4168B0_Credits(GAMEMES* mes);
s32 func_8010393C_4168CC_Credits(char* str);
void func_80103960_4168F0_Credits(void);
void func_80103FA4_416F34_Credits(void);
void func_80104248_4171D8_Credits(void);
s16 func_80104480_417410_Credits(u8* str, s16 color, s16 x, s16 arg3);
s16 func_801047E8_417778_Credits(s32 x, s32 y);
void func_80104980_417910_Credits(s16 spr);
void func_801049A0_417930_Credits(void);
void func_80104D44_417CD4_Credits(void);

#endif
