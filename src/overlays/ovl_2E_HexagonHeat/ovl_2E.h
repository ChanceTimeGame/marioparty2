#ifndef _OVL_2E_H
#define _OVL_2E_H

/* Overlay 2E: Hexagon Heat (4P). Seven coloured hexagon platforms around a centre one; a flag
   (func_801032F8) shows a colour, the Thwomp-like stompers (the six outer platforms' objects and
   the centre one, func_80106204) fall on every hexagon of another colour, and a player standing
   there (or in the lava, ground index 0) is out. Each round the stompers rise (state 1), wait,
   fall faster (state 2) and the colour changes. No MP1 ancestor (MP3 has a twin of
   func_8010537C in treadmill_grill).
   Retail is one file, 22E170.c; .rodata is carved from 0x232120. .data stays asm (231E90.data.s),
   declared here. */

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/data.h"
#include "game/collision.h"

/* ---- main-segment API used by 2E (missing from include/) ---- */

/* Per-character data, 0x18 bytes each. */
typedef struct HXCharData {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s32 unk_04; /* model/motion directory */
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10; /* model file */
    /* 0x14 */ char unk_14[4];
} HXCharData;
extern HXCharData D_800CD438_CE038[];

extern u16 D_800BF7E4_C03E4[][14]; /* per player sound ids */
extern f32 D_800BF79C_C039C;
extern f32 D_800BF7A4_C03A4;
extern f32 D_800BF7A8_C03A8;
extern f32 D_800BF7C8_C03C8;
extern f32 D_800BF7D4_C03D4;
extern f32 D_800BF7DC_C03DC;
extern s32 D_800F8FD0_F9BD0; /* scene state */
extern u16 D_800FA606_FB206;
extern u8 D_800FDBE0_FE7E0; /* current vertex buffer */
extern f32 D_8010105C_101C5C;
extern u16 D_801011FC_101DFC;
extern f32 D_80101300_101F00;
extern u8 D_80102720_103320;
extern s8 ContStkX[4];
extern s8 ContStkY[4];

void func_8002D4D0_2E0D0(s16 n);
void func_8002F290_2FE90(s32* arg0, s32 n);
void func_80020D20_21920(s16 arg0);
void func_8000C38C_CF8C(void);
void func_8000C398_CF98(void);
void func_8000C3A8_CFA8(void);
void func_8000C3B8_CFB8(void);
void func_8000C3C8_CFC8(void);
void func_8000C460_D060(void);
void func_8000C56C_D16C(s32);
void func_8000C578_D178(s32);
void func_8000C018_CC18(u16);
void func_80026DAC_279AC(s16, u8, u8, u8);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_80079E60_7AA60(void);
u16 func_80078EA8_79AA8(void);
u8 rand8(void);
s32 PlaySound(s32);
s16 func_80079574_7A174(void); /* music tempo */
void func_8007954C_7A14C(s16);
void func_800795D8_7A1D8(s16 sound, s8 volume);
void func_800796F0_7A2F0(s16 sound, s16 pitch);
void func_80079614_7A214(s16 time); /* music fade-out */
s16 func_800797DC_7A3DC(s32 id, s16 player);
void func_80079848_7A448(s16 arg0); /* stop a sound */
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
s16 func_800691FC_69DFC(s16 mesNo, ...); /* MP1 GMesCreate */
s32 func_80069538_6A138(void);          /* MP1 GMesStatAllGet */
omObjData* func_800732B0_73EB0(u32 arg0);
f32 func_800B1830_B2430(f32); /* sqrtf */
f64 fabs(f64); /* GCC builtin (abs.d) */
f32 func_800B75A8_B81A8(f32 y, f32 x); /* atan2, degrees */
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* cos */
f32 func_8002D958_2E558(f32); /* wraps an angle */
void* func_80027154_27D54(s32 size, s16 tag); /* HuMemAllocTag */
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size); /* memset */
u16 func_80018A30_19630(s32 arg0, s32 arg1); /* model from a file */
s16 func_80027D3C_2893C(s16 linkMdlId); /* model copy */
u16 LoadFormFile(s32, s32);
void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void func_8002979C_2A39C(s16 idx, f32 x, f32 y, f32 z); /* model rotation */
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_800298A4_2A4A4(s16, s32, s32); /* model attribute */
void func_80029A8C_2A68C(s16);
void func_80029AFC_2A6FC(s16);
void func_80029C74_2A874(s16, f32); /* motion frame */
f32 func_80029CE4_2A8E4(s16);
f32 func_80029D0C_2A90C(s16);
void func_8002A00C_2AC0C(s16 model);
void func_8002BED4_2CAD4(s16 model, f32 s, f32 t, u16 w, u16 h, char* part, u8 arg6); /* texture scroll */
void func_8002C20C_2CE0C(s16 arg0, char* arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5); /* part colour */
void func_8002D1EC_2DDEC(s16, u8);
void func_8002D274_2DE74(s16 arg0, u8 arg1, u8 arg2, u8 arg3); /* model light colour (2DE74.c: s8; retail passes 255) */
void func_8002D2B4_2DEB4(s16 arg0, f32 arg1, f32 arg2, f32 arg3); /* model light direction */
void func_8002D3C0_2DFC0(s16 arg0);
void func_8003EAF0_3F6F0(char* arg0, void* arg1); /* the size of the texture named arg0 */
u16 func_80020EBC_21ABC(void* arg0, s32 arg1, u8 arg2); /* 3D sprite (MP1 func_8001E00C) */
u16 func_8002109C_21C9C(s16 index, s32 arg1);
void func_80021160_21D60(s16 index, s32 arg1, s32 arg2);
/* GroundWork setters (C8E0.c) */
void func_8000BE8C_CA8C(omObjData*, f32);
void func_8000BE98_CA98(omObjData*, f32);    /* unk_0C */
void func_8000BEA4_CAA4(omObjData*, f32);
void func_8000BEF8_CAF8(omObjData*, s32, f32);
void func_8000BFA8_CBA8(omObjData*, f32 top, f32 depth, f32 radius); /* cylinder: unk_14, unk_98, unk_9C */
void func_8000BFF0_CBF0(omObjData*);
void func_8000C37C_CF7C(omObjData* obj, f32 x, f32 y, f32 z); /* obj->scale */
void func_8000D2F8_DEF8(omObjData*);
/* players */
void func_8000C6FC_D2FC(omObjData* obj, u32 dir, s32 file, u16 player, s32 arg4, s32 arg5); /* player object setup */
void func_8000BDC4_C9C4(omObjData* obj, u16 idx, s32 dir, s32 file, f32 arg4);
void func_8000CC74_D874(omObjData* obj, s16 model, s16 motion);
void func_8000C024_CC24(omObjData* obj, u8 idx, u8 val);
void func_8000E0C0_ECC0(MgWork* w, s32 slot, void* hook); /* w->unk_104[slot] = hook (slot < 21) */
s32 func_80019000_19C00(omObjData* obj);
s32 func_80019B9C_1A79C(omObjData* obj, u16 motion); /* player motion */
s32 func_80019CA4_1A8A4(omObjData* obj, u16 motion);
void func_80019F0C_1AB0C(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4); /* motion */

/* ---- .data (231E90; asm) ---- */

extern s32 D_80106520_231E90_HexagonHeat; /* the flag's colour (0-6), -1 before the first */
extern f32 D_80106524_231E94_HexagonHeat; /* the stompers' height (50-550) */
extern s32 D_80106528_231E98_HexagonHeat; /* stomper state: 0 up, 1 rising, 2 falling, 3 down */
extern s32 D_8010652C_231E9C_HexagonHeat; /* frames in the state */
extern s32 D_80106530_231EA0_HexagonHeat; /* glow step, +-4 */
extern s32 D_80106534_231EA4_HexagonHeat; /* glow */
extern f32 D_80106538_231EA8_HexagonHeat; /* 0 high .. 1 low */
extern s32 D_8010653C_231EAC_HexagonHeat; /* result: 0 playing, 1 one left, 2 none left */
extern s16 D_80106540_231EB0_HexagonHeat; /* result frames */
extern s32 D_80106544_231EB4_HexagonHeat; /* the last player standing, -1 none */
extern s32 D_80106548_231EB8_HexagonHeat; /* the falling sound, -1 none; D_8010654A_231EBA its low half */
extern u8 D_8010654C_231EBC_HexagonHeat[4]; /* player is out */
extern f32 D_80106550_231EC0_HexagonHeat[7][3]; /* hexagon colours */
extern f32 D_801065A4_231F14_HexagonHeat[7][3]; /* the colours shaded by height (edge) */
extern f32 D_801065F8_231F68_HexagonHeat[7][3]; /* (centre) */
extern f32 D_8010664C_231FBC_HexagonHeat[6][2]; /* outer stomper x, z */
extern f32 D_8010667C_231FEC_HexagonHeat[7][2]; /* hexagon x, z */
extern Vec D_801066B4_232024_HexagonHeat; /* the lit colour */
extern f32 D_801066C0_232030_HexagonHeat; /* fall speed */
extern s32 D_801066C4_232034_HexagonHeat; /* rounds */
extern s32 D_801066C8_232038_HexagonHeat;
extern f32 D_801066CC_23203C_HexagonHeat; /* flag motion frame */
extern f32 D_801066D0_232040_HexagonHeat;
extern f32 D_801066D4_232044_HexagonHeat;
extern s32 D_801066DC_23204C_HexagonHeat; /* the flag is moving */
extern f32 D_801066E0_232050_HexagonHeat; /* intro angle */
extern f32 D_801066E4_232054_HexagonHeat; /* intro radius */
extern s32 D_801066E8_232058_HexagonHeat;
extern s32 D_801066EC_23205C_HexagonHeat;
extern s32 D_801066F0_232060_HexagonHeat;
extern s32 D_801066F4_232064_HexagonHeat;
/* background actor hop timers: three bytes retail addresses by their own labels (D_801066F9/FA
   are undefined_syms.txt aliases), then a pad byte */
extern u8 D_801066F8_232068_HexagonHeat;
extern u8 D_801066F9_232069_HexagonHeat;
extern u8 D_801066FA_23206A_HexagonHeat;
extern s32 D_801066FC_23206C_HexagonHeat;
extern s32 D_80106700_232070_HexagonHeat;
extern s32 D_80106704_232074_HexagonHeat;
extern f32 D_80106708_232078_HexagonHeat[2]; /* lava bubble x, z */
extern f32 D_8010670C_23207C_HexagonHeat;
extern s16 D_80106710_232080_HexagonHeat;
extern s16 D_80106712_232082_HexagonHeat;
extern s16 D_80106714_232084_HexagonHeat;
extern f32 D_80106718_232088_HexagonHeat;
extern f32 D_8010671C_23208C_HexagonHeat; /* lava scroll */
extern f32 D_80106720_232090_HexagonHeat[4]; /* per COM difficulty */
extern s32 D_80106730_2320A0_HexagonHeat[4];
extern f32 D_80106740_2320B0_HexagonHeat[4];
extern s32 D_80106750_2320C0_HexagonHeat[4][4]; /* per player splash frames */
extern f32 D_80106790_232100_HexagonHeat[4];
extern s16 D_801067A0_232110_HexagonHeat; /* splash model, -1 none */
extern s32 D_801067A4_232114_HexagonHeat; /* stomper model; D_801067A6_232116 its low half */
extern s32 D_801067A8_232118_HexagonHeat; /* stompers made; D_801067AB_23211B its low byte */

/* ---- .bss (801067E0) ---- */

extern f32 D_801067E0_232150_HexagonHeat;
extern u16 D_801067E4_232154_HexagonHeat[2]; /* lava texture size */
extern s32 D_801067E8_232158_HexagonHeat; /* saved COM pad: ContBtn (D_801067EA its low half) */
extern s32 D_801067EC_23215C_HexagonHeat; /* ContBtnTrg (D_801067EE) */
extern s32 D_801067F0_232160_HexagonHeat; /* ContStkX (D_801067F3) */
extern s32 D_801067F4_232164_HexagonHeat; /* ContStkY (D_801067F7) */
extern f32 D_801067F8_232168_HexagonHeat[3][4][2]; /* background actor x, z */
extern s32 D_80106858_2321C8_HexagonHeat[4]; /* per player win motion */

/* ---- 22E170.c ---- */

void func_80102800_22E170_HexagonHeat(void);
void func_80102D30_22E6A0_HexagonHeat(void);
void func_801032F8_22EC68_HexagonHeat(omObjData* obj);
void func_801035D8_22EF48_HexagonHeat(void);
void func_8010370C_22F07C_HexagonHeat(void);
void func_80103ACC_22F43C_HexagonHeat(void);
void func_80103AF8_22F468_HexagonHeat(omObjData* obj);
void func_80103DEC_22F75C_HexagonHeat(omObjData* obj);
void func_801041BC_22FB2C_HexagonHeat(omObjData* obj);
void func_80104384_22FCF4_HexagonHeat(omObjData* obj);
void func_801047B8_230128_HexagonHeat(omObjData* obj);
f32 func_80104C80_2305F0_HexagonHeat(omObjData* obj);
void func_80104D38_2306A8_HexagonHeat(omObjData* obj);
void func_801051D0_230B40_HexagonHeat(omObjData* obj);
void func_8010537C_230CEC_HexagonHeat(omObjData* obj, f32 x, f32 y, f32 z);
void func_801054F8_230E68_HexagonHeat(omObjData* obj, f32* x, f32* y, f32* z);
void func_801056C4_231034_HexagonHeat(omObjData* obj, s32 dir, s32 arg2, s32 file, u16 player, f32 x, f32 y, f32 z);
void func_80105B78_2314E8_HexagonHeat(omObjData* obj);
void func_80105BF0_231560_HexagonHeat(omObjData* obj);
void func_80105C78_2315E8_HexagonHeat(omObjData* obj);
void func_80105D00_231670_HexagonHeat(omObjData* obj);
void func_80105D7C_2316EC_HexagonHeat(omObjData* obj);
void func_80105EF0_231860_HexagonHeat(omObjData* obj);
void func_80106058_2319C8_HexagonHeat(omObjData* obj);
void func_80106174_231AE4_HexagonHeat(omObjData* obj);
s32 func_801061B0_231B20_HexagonHeat(HmfData* hmf, HmfFace* face);
void func_80106204_231B74_HexagonHeat(omObjData* obj);

#endif
