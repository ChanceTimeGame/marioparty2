#ifndef _OVL_34_H
#define _OVL_34_H

/* Overlay 34 (259900.c): the Chance Time board event, a stand-alone scene (its own omInitObjMan)
   descended from MP1's ovl_01 ChanceTime (src/overlays/ovl_01_ChanceTime/, D51E0.c mostly).
   D_80110060 (_CheckFlag(0x45)) picks between the two variants of the event, as in MP1.
   The unit's .rodata is carved ([0x267360, .rodata, 259900]); .data and .bss stay asm. */

#include "common.h"
#include "game/board.h"
#include "game/object.h"
#include "game/camera.h"
#include "game/gamemes.h"

/* ---- main-segment API used by 34 ---- */

/* func_800615FC_621FC is defined (void) in 5F3B0.c; retail passes (-1, -1) here (MP1's
   func_80055A40_unproto). */
#define func_800615FC_621FC_unproto ((void (*)(s32, s32))func_800615FC_621FC)

void func_800615FC_621FC(void);
void func_800616C4_622C4(void);
void func_8000C018_CC18(u16); /* stores the low byte (C8E0: player object count) */
void func_8000C38C_CF8C(void);
void func_8000C398_CF98(void);
void func_8000C3A8_CFA8(void);
void func_8000C3B8_CFB8(void);
void func_8000C3C8_CFC8(void);
void func_8000C460_D060(void);
void func_8000C578_D178(u8);
void func_8000C690_D290(void);
u16 func_80018A64_19664(s32 arg0, s32 arg1);
void func_80020D20_21920(s16 arg0);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_8002D4D0_2E0D0(s16 n);
void func_8002F290_2FE90(s32* arg0, s32 n);
void func_8007273C_7333C(u8* arg0, u8 arg1);
void func_800B3820_B4420(Mtx* arg0); /* guMtxIdent */
void Hu3DCamSetPositionOrientation(s16, Vec*, Vec*, Vec*);
s16 func_800691FC_69DFC(s16 mesNo, ...);
s32 func_80069538_6A138(void);
void func_80069770_6A370(void);
f32 func_800B7890_B8490(f32); /* cos */
s32 PlaySound(s32);

extern s8 D_80102708_103308;
extern u16 D_800F8FE0_F9BE0;           /* player object count (C8E0) */
extern omObjData* D_800FC7B0_FD3B0[];  /* (C8E0) */
extern u16 D_800FC87A_FD47A;           /* player object count */
extern omObjData* D_800FFFD8_100BD8[]; /* player objects */
extern s16 D_800FA606_FB206;
extern s32 D_800F9D30_FA930[];
extern u8 D_800FDBCA_FE7CA;            /* matrix set count (30560) */
extern s32 D_800F8FD0_F9BD0;           /* scene state (C8E0 func_8000C3C8 copies it) */

/* ---- 34 work types ---- */

/* omObjData::unk_50 of the player objects (C8E0.c's MgWork, 0x15C bytes; MP1 CTPlayerWork). */
typedef struct CTPlayerWork {
    /* 0x00 */ char unk_00[0x38];
    /* 0x38 */ f32 unk_38; /* vertical speed; 1000.0f = on the ground */
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ char unk_44[0x18];
    /* 0x5C */ s32 unk_5C; /* flags (& 6 tested) */
    /* 0x60 */ char unk_60[0xFC];
} CTPlayerWork; /* size = 0x15C */

#define CT_PWORK(obj) ((CTPlayerWork*)(obj)->unk_50)

/* ---- .data (267160.data.s, asm) ---- */
extern s8 D_80110060_267160_ChanceTime; /* _CheckFlag(0x45): the event's second variant */
extern s8 D_80110062_267162_ChanceTime; /* state of the two block holders (1 spin, 2 stop) */
extern s8 D_80110063_267163_ChanceTime;
extern s8 D_80110064_267164_ChanceTime;
extern s8 D_80110068_267168_ChanceTime;
extern u32 D_801100F0_2671F0_ChanceTime; /* func_80102E4C frame counter */
extern s32 D_801100F4_2671F4_ChanceTime;
extern s8 D_801100F8_2671F8_ChanceTime;
extern s8 D_801100F9_2671F9_ChanceTime;
extern s8 D_801100FA_2671FA_ChanceTime;
extern s8 D_801100FB_2671FB_ChanceTime;
extern s8 D_801100FC_2671FC_ChanceTime;
extern f32 D_80110100_267200_ChanceTime;
extern s16 D_80110104_267204_ChanceTime; /* 0xFF: title alpha; retail reads (u8) as D_80110105 */
extern GAMEMES* D_80110108_267208_ChanceTime; /* the title message */
extern u8 D_80110230_267330_ChanceTime[]; /* SJIS "ＣＨＡＮＣＥＴＩＭＥ？" */
extern u8 D_80110248_267348_ChanceTime[]; /* SJIS "ＣＨＡＮＣＥＴＩＭＥ" */

/* ---- .bss (ovl_34_bss.bss.s) ---- */
extern s16 D_801106B0_2677B0_ChanceTime; /* title message */
extern omObjData* D_80110908_267A08_ChanceTime;
extern omObjData* D_8011090C_267A0C_ChanceTime; /* the two block holders */
extern omObjData* D_80110910_267A10_ChanceTime;
extern s16 D_80110914_267A14_ChanceTime; /* three models (0x440009..B) */
extern s16 D_80110916_267A16_ChanceTime;
extern s16 D_80110918_267A18_ChanceTime;
extern s8 D_80110D6A_267E6A_ChanceTime[4]; /* player order */
/* The panels' objects; retail writes the third (D_80110D88) as [2] in one branch. */
extern omObjData* D_80110D80_267E80_ChanceTime[2];
extern omObjData* D_80110D88_267E88_ChanceTime;

/* ---- overlay functions (all 62; signatures past fork A's range are inferred) ---- */
/* fork A */
void func_80102800_259900_ChanceTime(void); /* scene setup */
void func_80102E4C_259F4C_ChanceTime(omObjData* obj); /* event flow (MP1 func_800F6B00) */
void func_80103398_25A498_ChanceTime(omObjData* obj);
void func_801036C4_25A7C4_ChanceTime(omObjData* obj);
void func_80103714_25A814_ChanceTime(omObjData* obj);
void func_80103A64_25AB64_ChanceTime(omObjData* obj);
void func_80103ADC_25ABDC_ChanceTime(omObjData* obj, s8 arg1);
void func_801052B4_25C3B4_ChanceTime(omObjData* obj);
void func_801060E0_25D1E0_ChanceTime(void); /* process */
/* fork B */
s32 func_80106434_25D534_ChanceTime(s8 arg0);
void func_80106548_25D648_ChanceTime(omObjData* obj);
s32 func_80106604_25D704_ChanceTime(omObjData* obj, s8 dir, s16 count);
s32 func_80106B5C_25DC5C_ChanceTime(omObjData* obj, s16 a, s16 b);
s8 func_80107594_25E694_ChanceTime(omObjData* obj);
void func_801077D8_25E8D8_ChanceTime(omObjData* obj);
void func_80107B00_25EC00_ChanceTime(omObjData* obj);
void func_80109718_260818_ChanceTime(s8 arg0, s8 arg1);
s8 func_801097F8_2608F8_ChanceTime(s8 arg0, s8 arg1);
void func_8010985C_26095C_ChanceTime(void); /* process */
s8 func_80109CC4_260DC4_ChanceTime(s16 arg0, s16 arg1);
/* fork C */
void func_80109D84_260E84_ChanceTime(void); /* process */
void func_8010B02C_26212C_ChanceTime(omObjData* obj);
void func_8010B214_262314_ChanceTime(omObjData* obj);
void func_8010B28C_26238C_ChanceTime(void); /* process */
void func_8010B328_262428_ChanceTime(void); /* process */
void func_8010B3C4_2624C4_ChanceTime(s16 arg0, s16* arg1);
void func_8010B7F8_2628F8_ChanceTime(void); /* process */
void func_8010BB0C_262C0C_ChanceTime(s16 arg0, s16* arg1, s16* arg2);
void func_8010BB74_262C74_ChanceTime(void); /* process */
void func_8010BF28_263028_ChanceTime(omObjData* obj);
void func_8010BF50_263050_ChanceTime(void);
void func_8010BF7C_26307C_ChanceTime(omObjData* obj);
void func_8010BF98_263098_ChanceTime(omObjData* obj);
void func_8010BFB4_2630B4_ChanceTime(omObjData* obj);
void func_8010BFD0_2630D0_ChanceTime(omObjData* obj);
void func_8010BFEC_2630EC_ChanceTime(omObjData* obj);
void func_8010C008_263108_ChanceTime(omObjData* obj);
void func_8010C024_263124_ChanceTime(omObjData* obj);
void func_8010C080_263180_ChanceTime(omObjData* obj);
void func_8010C09C_26319C_ChanceTime(void);
void* func_8010C268_263368_ChanceTime(void);
void func_8010C44C_26354C_ChanceTime(omObjData* obj, s8 arg1);
/* fork D */
void func_8010CCF4_263DF4_ChanceTime(omObjData* obj, s8 arg1);
s32 func_8010DFF8_2650F8_ChanceTime(omObjData* obj, f32 size, omObjData* other);
void func_8010E0D4_2651D4_ChanceTime(omObjData* obj);
void func_8010E214_265314_ChanceTime(omObjData* obj);
void func_8010E440_265540_ChanceTime(omObjData* obj);
void func_8010E668_265768_ChanceTime(omObjData* obj);
void func_8010E71C_26581C_ChanceTime(omObjData* obj);
void func_8010E7C0_2658C0_ChanceTime(omObjData* obj);
void func_8010EED0_265FD0_ChanceTime(omObjData* obj);
void func_8010EF84_266084_ChanceTime(omObjData* obj, u32 arg1, s32 arg2, s32 arg3, f32 x, f32 y, f32 z);
void func_8010F304_266404_ChanceTime(omObjData* obj);
void func_8010F4B4_2665B4_ChanceTime(omObjData* obj, s32 arg1, s32 arg2, s32 arg3, f32 x, f32 y, f32 z);
void func_8010F760_266860_ChanceTime(omObjData* obj);
void func_8010F82C_26692C_ChanceTime(omObjData* obj);
void func_8010F8F8_2669F8_ChanceTime(omObjData* obj);
void func_8010F9C4_266AC4_ChanceTime(void* arg0, s8 arg1);
void func_8010FC18_266D18_ChanceTime(void); /* process */
void func_8010FD28_266E28_ChanceTime(void); /* process */
void func_8010FE50_266F50_ChanceTime(s16 arg0);
void func_8010FF1C_26701C_ChanceTime(void); /* process */

#endif
