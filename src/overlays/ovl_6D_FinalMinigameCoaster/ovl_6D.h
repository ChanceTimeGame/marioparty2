#ifndef _OVL_6D_H
#define _OVL_6D_H

/* Overlay 6D: the Mini-Game Coaster's end scene, by course D_800FD8A8.unk04, and the final
   minigame's call and return. One retail file, 406640.c. .data is C (no .bss: the zero
   words at the head of .data serve for it); .rodata is carved. */

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
s32 func_8008BB48_8C748(s16, s8, s32);
void func_800794A8_7A0A8(s32);
void func_80029E80_2AA80(s16, s32, s32);

void func_800753D4_75FD4(s32);
s32 func_80075390_75F90(s32);
void func_80075424_76024(s32);
void func_80067E6C_68A6C(s32);
void func_800740AC_74CAC(void);
void func_8007E018_7EC18(void);
void func_8007E070_7EC70(void);
s16 PlayMusic(s16);
void HuMemDirectFree(void*);
f32 HuMathSin(f32);
typedef struct Vec2fxy {
    f32 x;
    f32 y;
} Vec2fxy;
void MBDCamera3Dto2D(Vec*, Vec2fxy*);
s16 func_80079718_7A318(s16, u8);
s16 SprAnimRead(void*);
void SprAnimSet(s16, s16, s16, u16);
void SprAttrSet(s16, s16, s32);
void SprPosSet(s16, s16, s16, s16);
void SprPrioSet(s16, s16, u16);
void SprScaleSet(s16, s16, f32, f32);
void func_8008221C_82E1C(s16, s16, f32);
void func_8008225C_82E5C(s16, s16, s32);
void func_80082450_83050(s16, s32, s32, s32, u8);
void func_800B3B80_B4780(f32*, f32);
extern s16 D_800CD414_CE014;
extern s32 D_800CD2C4_CDEC4;

/* .data */
extern s32 D_80106240_40A080_FinalMinigameCoaster[8];      /* written only by -1 in 80106054 */
extern MBModel* D_80106260_40A0A0_FinalMinigameCoaster[8]; /* 0 host, 3 car, 4 second 0xA7, 5-7 models 0x7B */
extern omObjData* D_80106280_40A0C0_FinalMinigameCoaster[8];
extern s32 D_801062A0_40A0E0_FinalMinigameCoaster; /* save on leaving */
extern s32 D_801062A4_40A0E4_FinalMinigameCoaster; /* call the minigame on leaving */
extern s32 D_801062A8_40A0E8_FinalMinigameCoaster; /* wait out the fade on leaving */
extern Vec D_801062AC_40A0EC_FinalMinigameCoaster;
extern Vec D_801062B8_40A0F8_FinalMinigameCoaster;
extern Vec D_801062C4_40A104_FinalMinigameCoaster;
extern Vec D_801062D0_40A110_FinalMinigameCoaster;
extern Vec D_801062DC_40A11C_FinalMinigameCoaster;
extern Vec D_801062E8_40A128_FinalMinigameCoaster[3];
extern Vec D_8010630C_40A14C_FinalMinigameCoaster;
extern Vec D_80106318_40A158_FinalMinigameCoaster;
extern Vec D_80106324_40A164_FinalMinigameCoaster;
extern Vec D_80106330_40A170_FinalMinigameCoaster;
extern Vec D_8010633C_40A17C_FinalMinigameCoaster;
extern Vec D_80106348_40A188_FinalMinigameCoaster;
extern Vec D_80106354_40A194_FinalMinigameCoaster;
extern Vec D_80106360_40A1A0_FinalMinigameCoaster;
extern Vec D_8010636C_40A1AC_FinalMinigameCoaster[2];
extern Vec D_80106384_40A1C4_FinalMinigameCoaster;
extern Vec D_80106390_40A1D0_FinalMinigameCoaster;
extern s32* D_80106444_40A284_FinalMinigameCoaster[6]; /* per character: motion list */
extern s32 D_8010645C_40A29C_FinalMinigameCoaster[];   /* motion list: count, then file ids */
extern s32 D_80106470_40A2B0_FinalMinigameCoaster[];
extern s32 D_8010647C_40A2BC_FinalMinigameCoaster[6];  /* per character: message */
extern s32 D_80106494_40A2D4_FinalMinigameCoaster[6];
extern s32 D_801064AC_40A2EC_FinalMinigameCoaster[5];

void* func_8005E688_5F288(u16, u16);

void func_80102800_406640_FinalMinigameCoaster(void);
void func_801028E0_406720_FinalMinigameCoaster(s16);
void func_80102914_406754_FinalMinigameCoaster(s32, s32, s32);
void func_801029C8_406808_FinalMinigameCoaster(s32, s32, s32, char*, char*);
s16 func_80102AEC_40692C_FinalMinigameCoaster(s32, s32, s32, char*, char*);
void func_80102C00_406A40_FinalMinigameCoaster(void);
void func_801031D0_407010_FinalMinigameCoaster(void);
void func_8010370C_40754C_FinalMinigameCoaster(void);
void func_80103E04_407C44_FinalMinigameCoaster(s32);
void func_80104270_4080B0_FinalMinigameCoaster(void);
void func_801042DC_40811C_FinalMinigameCoaster(void);
void func_80104380_4081C0_FinalMinigameCoaster(void);
void func_80104AFC_40893C_FinalMinigameCoaster(void);
void func_8010565C_40949C_FinalMinigameCoaster(void);
void func_80105CE8_409B28_FinalMinigameCoaster(void);
void func_80105EC0_409D00_FinalMinigameCoaster(void);
void func_80105FBC_409DFC_FinalMinigameCoaster(omObjData*);
void omDelObj(omObjData*);
void func_80106018_409E58_FinalMinigameCoaster(void);
void func_80106054_409E94_FinalMinigameCoaster(void);
void func_80106160_409FA0_FinalMinigameCoaster(void);
void func_80106214_40A054_FinalMinigameCoaster(void);

#endif
