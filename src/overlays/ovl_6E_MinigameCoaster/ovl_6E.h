#ifndef _OVL_6E_H
#define _OVL_6E_H

/* Overlay 6E: the Mini-Game Coaster's start. The cast arrives, the rules are explained, the course
   is chosen (D_800FD8A8.unk04) and the car leaves. One retail file, 40A330.c. .data is C (no
   .bss: its zero words serve for it); .rodata is carved. */

#include "common.h"
#include "process.h"
#include "game/data.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/sprite.h"
#include "game/window.h"
#include "game/gamemes.h"
#include "game/gamework.h"
#include "game/board.h"
#include "game/camera.h"

#define PLAYER_MODEL(i) ((MBModel*)gPlayers[i].unk_24)

/* func_8005E688's sprite holder (5EF10.c's UnkList53): group unkA, animations in data. */
typedef struct CoasterSprite {
    /* 0x00 */ struct CoasterSprite* next;
    /* 0x04 */ struct CoasterSprite* prev;
    /* 0x08 */ s16 count;
    /* 0x0A */ s16 group;
    /* 0x0C */ s16* data;
} CoasterSprite;

/* main */
extern u16 D_801011FC_101DFC;
extern void* D_800FD2A8_FDEA8;
void func_80026D28_27928(s16);
void func_80026DAC_279AC(s16, u8, u8, u8);
void func_80026E00_27A00(s16, f32, f32, f32);
void func_800283DC_28FDC(s16);
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029A8C_2A68C(s16);
void func_80029FE4_2ABE4(s16, f32);
void func_8005E584_5F184(void);
void func_80050AE0_516E0(void);
void MBDBackKill(void);
void func_800581D0_58DD0(void);
void func_80059400_5A000(void);
void func_80059704_5A304(void);
void func_8005E260_5EE60(s16);
void func_800593C0_59FC0(void);
void func_8005965C_5A25C(void);
void func_800581A0_58DA0(void);
void func_80050A30_51630(u8*);
void func_80050E00_51A00(s32);
void func_80018E30_19A30(s32);
s32 func_8008F618_90218(void);
void func_8008CE5C_8DA5C(void);
MBModel* func_80043510_44110(u8, void*);
void func_80043DAC_449AC(void*);
void func_800B3170_B3D70(Vec*, Vec*);
void HuVecCopyXYZ(Vec*, f32, f32, f32);
f32 HuVecDistance(Vec*, Vec*);
void MBModelDispOff(MBModel*);
void MBModelDispOn(MBModel*);
void MBMotionSet(void*, s16, u16);
void MBMotionShiftSet(void*, s16, s16, s16, u16);
void MBPlayerVibrate(s16, s16);
void MBPlayerModelCreate(s16, void*, s32);
s32 PlaySound(s32);
void func_80056658_57258(Vec*, Vec*, Vec*);
void func_8005670C_5730C(Vec*);
Process* func_80056B78_57778(Vec*, Vec*, Vec*, s32);
Process* func_80056D80_57980(Vec*, Vec*, Vec*, s32);
omObjData* func_8005845C_5905C(s32, Vec*, s32, void*);
omObjData* func_80058F18_59B18(s32, Vec*, s32, void*);
void func_80059120_59D20(void*, f32, f32);
void func_8005AA48_5B648(void*, char*, s16);
void func_8005AA98_5B698(s16);
s32 func_8005AAC0_5B6C0(s32, s32, s32, s32);
void MBModelKill(void*);
void func_8008DACC_8E6CC(s16, s16*, ...);
void func_800890CC_89CCC(s16, void*, s16, s16);
void func_80089A48_8A648(s16, s8);
void func_80089308_89F08(s16, void*, s8);
void func_8008D974_8E574(char*, s16);
void ShowTextWindow(s32);
void func_80057730_58330(s32, s32);
void func_8005762C_5822C(s32);
void func_8005774C_5834C(s32, s32);
s32 func_8008BB48_8C748(s16, s16, s32); /* main: s8 start; retail extends the argument to s16 */
void func_800794A8_7A0A8(s32);
void func_80029E80_2AA80(s16, s32, s32);

void func_8008F624_90224(u8, u8, u8);
s32 func_8005973C_5A33C(s32, u16, s16, s16);
void func_800598A4_5A4A4(s32, u8);
void func_80059914_5A514(s32, s32);
void func_800599AC_5A5AC(s32, u8, u8, u8);
void func_80059698_5A298(s32);
void func_80061DC4_629C4(void);
void func_800622E4_62EE4(void);
void func_80062008_62C08(void);
void func_80062340_62F40(void);
s16 func_800797DC_7A3DC(s32, s16);
s16 PlayMusic(s16);
f32 __sinf(f32);

/* .data */
extern MBModel* D_80103E00_40B930_MinigameCoaster[5]; /* 0 host (0xA7), 1 0xB0, 2 0xAF, 3 car (0xAB), 4 0xB1 */
extern Vec D_80103E14_40B944_MinigameCoaster;
extern Vec D_80103E20_40B950_MinigameCoaster;
extern Vec D_80103E2C_40B95C_MinigameCoaster;
extern Vec D_80103E38_40B968_MinigameCoaster;
extern Vec D_80103E44_40B974_MinigameCoaster;
extern Vec D_80103E50_40B980_MinigameCoaster;
extern Vec D_80103E5C_40B98C_MinigameCoaster[2];
extern Vec D_80103E74_40B9A4_MinigameCoaster[2];
extern s32* D_80103F4C_40BA7C_MinigameCoaster[6]; /* per character: motion list */
extern s32 D_80103F64_40BA94_MinigameCoaster[];   /* motion list: count, then file ids */
extern Vec D_80103F74_40BAA4_MinigameCoaster;
extern Vec D_80103F80_40BAB0_MinigameCoaster[4];

void func_80102800_40A330(void);
void func_80102884_40A3B4_MinigameCoaster(s16);
void func_801028B8_40A3E8_MinigameCoaster(void);
void func_801028FC_40A42C_MinigameCoaster(void);
void func_801032AC_40ADDC_MinigameCoaster(s32, s32, s32);
void func_80103360_40AE90_MinigameCoaster(void);
void func_80103BCC_40B6FC_MinigameCoaster(void);
void func_80103C18_40B748_MinigameCoaster(omObjData*);
void func_80103C5C_40B78C_MinigameCoaster(void);
void func_80103C98_40B7C8_MinigameCoaster(void);
void func_80103D34_40B864_MinigameCoaster(void);
void func_80103DD4_40B904_MinigameCoaster(void);

#endif
