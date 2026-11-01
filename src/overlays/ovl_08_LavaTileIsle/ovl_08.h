#ifndef _OVL_08_H
#define _OVL_08_H

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/data.h"
#include "game/collision.h"

/* Lava Tile Isle, an item minigame. Retail files 113C80.c, 114640.c (from 801031C0, 3-nop
   pad) and 115B60.c (from 801046E0, 1-nop pad); .data is asm, .rodata from 0x11B7A0 (114640.c)
   and 0x11B840 (115B60.c). */

/* ---- main-segment API missing from include/ ---- */
typedef struct LTCharData {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s32 unk_04; /* model/motion directory */
    /* 0x08 */ s32 unk_08; /* model file */
    /* 0x0C */ char unk_0C[0xC];
} LTCharData;
extern LTCharData D_800CD438_CE038[];
typedef struct LTEspSlot {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ char unk_06[0x1E];
} LTEspSlot; /* size = 0x24 */
extern LTEspSlot* D_800F93FC_F9FFC;
extern u16 D_800CAFD8[]; /* item ids; the low byte is the item */
extern u16 D_800CAFE4[]; /* item odds, percent */
extern u16 D_800FA606_FB206;
extern u16 D_801011FC_101DFC;
extern u8 D_80102720_103320;
extern s8 ContStkX[4];
extern s8 ContStkY[4];
extern u16 ContBtn[4];
extern u16 ContBtnTrg[4];
extern Gfx* D_800FDBCC_FE7CC;

void* func_80027154_27D54(s32 size, s16 tag); /* HuMemAllocTag */
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size); /* memset */
u16 func_80018A64_19664(s32 file, s32 attr);
void func_80018CCC_198CC(omObjData* obj, u16 slot, s32 file);
u16 func_80020EBC_21ABC(void* arg0, s32 arg1, u8 arg2); /* 3D sprite */
void* DataRead(s32 dirAndFile);
void HuMemMemoryFreePerm(void* ptr);
u16 LoadFormFile(s32, s32);
void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
s16 func_80027D3C_2893C(s16 linkMdlId); /* model copy */
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void func_8002979C_2A39C(s16 idx, f32 x, f32 y, f32 z); /* model rotation */
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_800298A4_2A4A4(s16, s32, s32); /* model attribute */
void func_80029A8C_2A68C(s16);
void func_80029B80_2A780(s16 arg0, s16 arg1);
void func_80029C74_2A874(s16, f32); /* motion frame */
f32 func_80029CE4_2A8E4(s16);
f32 func_80029D0C_2A90C(s16);
s32 func_80029E14_2AA14(s16 arg0);
void func_80029E80_2AA80(s16, s32, s32);
void func_8002A00C_2AC0C(s16 model);
void espDispOff(u16);
s16 func_8001A2F8_1AEF8(s32);
s16 func_8001AAAC_1B6AC(s16, s32, s32);
extern int guRandom(void);
void omSetTra(omObjData*, f32, f32, f32);
void omSetSca(omObjData*, f32, f32, f32);
void func_8000BEB0_CAB0(omObjData* obj, f32 arg1);
void func_8000BEBC_CABC(omObjData* obj, f32 arg1);
void func_8000BEC8_CAC8(omObjData* obj, f32 arg1);
void func_8000C35C_CF5C(omObjData* obj, f32 x, f32 y, f32 z);
void func_8000C36C_CF6C(omObjData* obj, f32 x, f32 y, f32 z);
void func_8000C38C_CF8C(void);
void func_8000C398_CF98(void);
void func_8000C3A8_CFA8(void);
void func_8000C3B8_CFB8(void);
void func_8000C3C8_CFC8(void);
void func_8000C460_D060(void);
void func_8000C578_D178(s32);
void func_8002D4D0_2E0D0(s16 n);
void func_8002F290_2FE90(s32* arg0, s32 n);
void func_80020D20_21920(s16 arg0);
void func_80020070_20C70(s32);
void func_80021198_21D98(s16 index, u16 arg1);
void func_8002AC10_2B810(s16 arg0, f32 arg1, f32 arg2, s32 arg3);
void func_8002C524_2D124(s16, s16, s16);
void func_8002C570_2D170(s16);
void func_8002C628_2D228(s16 arg0, s16 arg1, char* arg2);
void func_80069770_6A370(void);
void func_80079868_7A468(void);
void func_80079128_79D28(void);
void func_8002C59C_2D19C(s32, s32, s32, s32, s32);
void func_8007273C_7333C(const u8* arg0, u8 arg1);
void func_8007A27C_7AE7C(s32 prio, s32 sprId, void* draw, f32 fov, Vec* eye, Vec* at);
HuSprite* func_80082550_83150(s16 grpIdx, s16 idx);
void func_800794A8_7A0A8(s32);
void func_800798F8_7A4F8(s16 sound, s16 pan);
omObjData* func_800732B0_73EB0(u32 arg0);
u16 func_80078EA8_79AA8(void);
s16 func_800691FC_69DFC(s16 mesNo, ...); /* MP1 GMesCreate */
s32 func_80069538_6A138(void);           /* MP1 GMesStatAllGet */
void func_8006D4D0_6E0D0(s16);           /* the seconds counter */
void func_8006D518_6E118(void);
s32 func_8008F618_90218(void);
s32 PlaySound(s32);
s16 PlayMusic(s16);
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
void InitFadeIn(s32, s32);
void InitFadeOut(s32, s32);
u8 rand8(void);
f32 func_800B75A8_B81A8(f32 y, f32 x); /* atan2, degrees */
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* cos */

extern f32 D_800FA5BC_FB1BC[];
extern f32 D_80101078_101C78;
extern f32 D_800F8410_F9010;

typedef struct LTRect {
    /* 0x00 */ s8 id;
    /* 0x04 */ f32 x0;
    /* 0x08 */ f32 z0;
    /* 0x0C */ f32 x1;
    /* 0x10 */ f32 z1;
} LTRect; /* size = 0x14 */

extern s32 D_800F9D30_FA930[];
extern s32 D_800F8FD0_F9BD0; /* game state */
void func_8000C690_D290(void);
void func_8006961C_6A21C(s16 mesId, f32 x, f32 y);
void func_8007954C_7A14C(s16);
s32 func_80079574_7A174(void);
void func_800799A4_7A5A4(s16, s32);
void func_80026D28_27928(s16);
void func_80026E00_27A00(s16, f32, f32, f32);
void func_80026DAC_279AC(s16, u8, u8, u8);
void func_80029708_2A308(s32);
void func_8000C024_CC24(omObjData* obj, u8 idx, u8 val);
void func_8000C6FC_D2FC(omObjData* obj, u32 dir, s32 file, u16 player, s32 arg4, s32 arg5);
s32 func_80019B9C_1A79C(omObjData* obj, u16 motion); /* player motion */
void func_80019E84_1AA84(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4);
void func_80019F0C_1AB0C(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4); /* motion */
void func_8000E0C0_ECC0(MgWork* w, s32 slot, void* hook);
extern f32 D_800BF7C8_C03C8;
void func_80079848_7A448(s16 arg0);
void func_8000BEF8_CAF8(omObjData*, s32, f32);
void func_8000BF54_CB54(omObjData* obj, f32 arg1, f32 arg2, f32 minX, f32 minZ, f32 maxX, f32 maxZ);
void func_8000C018_CC18(u16);
u16 func_80018A30_19630(s32 arg0, s32 arg1); /* model from a file */
void func_8002BED4_2CAD4(s16 arg0, f32 arg1, f32 arg2, u16 arg3, u16 arg4, char* arg5, u8 arg6); /* texture scroll */
void func_8002D1EC_2DDEC(s16 arg0, u8 arg1);
void func_8002D274_2DE74(s16 arg0, u8 arg1, u8 arg2, u8 arg3);
void func_8002D2B4_2DEB4(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_8003EAF0_3F6F0(char* arg0, void* arg1); /* the size of the texture named arg0 */

/* ---- .data and .bss, in address order ---- */
extern s32 D_8010A1B0_11B630_LavaTileIsle; /* seconds */
extern u32 D_8010A1B4_11B634_LavaTileIsle; /* state 0 frames */
extern u32 D_8010A1B8_11B638_LavaTileIsle; /* state 2 frames */
extern s32 D_8010A1BC_11B63C_LavaTileIsle; /* state 1 frames */
extern s32 D_8010A1C0_11B640_LavaTileIsle;
extern s32 D_8010A1C4_11B644_LavaTileIsle; /* players still standing */
extern s16 D_8010A1C8_11B648_LavaTileIsle;
extern s8 D_8010A1CA_11B64A_LavaTileIsle; /* quit state */
extern u8 D_8010A1D0_11B650_LavaTileIsle[4]; /* platform 3 model states by step */

extern u16 D_8010A1D4_11B654_LavaTileIsle; /* step timer */
extern f32 D_8010A1D8_11B658_LavaTileIsle; /* bob angle */
extern s16 D_8010A1DC_11B65C_LavaTileIsle; /* 1: the loops are stopped */
extern s8 D_8010A1E0_11B660_LavaTileIsle[8]; /* the tile that moves, by step */
extern u8 D_8010A1E8_11B668_LavaTileIsle[8];

extern u16 D_8010A1F0_11B670_LavaTileIsle;
extern f32 D_8010A1F4_11B674_LavaTileIsle;
extern s32 D_8010A200_11B680_LavaTileIsle[4]; /* player of slot i */

extern u8 D_8010A210_11B690_LavaTileIsle[24][4]; /* every order of the four corners */
extern Vec D_8010A270_11B6F0_LavaTileIsle[4]; /* the corners */


extern s32 D_8010A2A0_11B720_LavaTileIsle;   /* unused by code */
extern s32 D_8010A2A4_11B724_LavaTileIsle;   /* unused by code */
extern s32 D_8010A2B4_11B734_LavaTileIsle;   /* unused by code */
extern s32 D_8010A2B8_11B738_LavaTileIsle;   /* unused by code */
extern s32 D_8010A2BC_11B73C_LavaTileIsle;   /* unused by code */
extern s32 D_8010A2C4_11B744_LavaTileIsle;   /* unused by code */
extern s32 D_8010A304_11B784_LavaTileIsle;   /* unused by code */
extern s32 D_8010A314_11B794_LavaTileIsle;   /* unused by code */
extern s32 D_8010A315_11B795_LavaTileIsle;   /* unused by code */
extern s32 D_8010A318_11B798_LavaTileIsle;   /* unused by code */
extern s32 D_8010A31C_11B79C_LavaTileIsle;   /* unused by code */
extern s32 D_8010A490_11B910_LavaTileIsle;   /* unused by code */
extern s16 D_8010A494_11B914_LavaTileIsle;
extern s16 D_8010A496_11B916_LavaTileIsle;
extern f32 D_8010A4A0_11B920_LavaTileIsle; /* moving tile's start x */
extern f32 D_8010A4A4_11B924_LavaTileIsle; /* start z */
extern f32 D_8010A4A8_11B928_LavaTileIsle; /* speed */
extern s16 D_8010A4AC_11B92C_LavaTileIsle; /* sound */
extern s16 D_8010A4AE_11B92E_LavaTileIsle;
extern s16 D_8010A4B0_11B930_LavaTileIsle;
extern f32 D_8010A4B4_11B934_LavaTileIsle;
extern f32 D_8010A4B8_11B938_LavaTileIsle;
extern f32 D_8010A4BC_11B93C_LavaTileIsle;
extern s16 D_8010A4C0_11B940_LavaTileIsle; /* tile model */
extern s16 D_8010A4C2_11B942_LavaTileIsle; /* second tile model */
extern u16 D_8010A4C4_11B944_LavaTileIsle[2]; /* texture size */
extern u16 D_8010A4C8_11B948_LavaTileIsle[2];
extern f32 D_8010A4CC_11B94C_LavaTileIsle; /* lava scroll */
extern s16 D_8010A4D0_11B950_LavaTileIsle; /* lava model */
extern s32 D_8010A4E0_11B960_LavaTileIsle;   /* unused by code */
extern s8 D_8010A4E2_11B962_LavaTileIsle; /* next slot */
extern u8 D_8010A4E3_11B963_LavaTileIsle; /* the order, 0-23 */
extern s32 D_8010A4E8_11B968_LavaTileIsle;   /* unused by code */
extern s32 D_8010A4EB_11B96B_LavaTileIsle;   /* unused by code */
extern Vec D_8010A500_11B980_LavaTileIsle[4];

extern LTRect D_8010A530_11B9B0_LavaTileIsle[4];

extern Vec D_8010A580_11BA00_LavaTileIsle[3];

extern LTRect D_8010A5A8_11BA28_LavaTileIsle[5];

extern s8 D_8010A60C_11BA8C_LavaTileIsle;
extern omObjData* D_8010A610_11BA90_LavaTileIsle;
extern omObjData* D_8010A614_11BA94_LavaTileIsle;
extern s8 D_8010A618_11BA98_LavaTileIsle;
extern s8 D_8010A619_11BA99_LavaTileIsle; /* result: -1 none yet, 0 a winner, 1 a draw */

/* ---- the overlay ---- */
void func_80102800_113C80_LavaTileIsle(void);
void func_8010291C_113D9C_LavaTileIsle(void);
void func_801029A8_113E28_LavaTileIsle(void);
void func_80102AB0_113F30_LavaTileIsle(void);
void func_80102BD0_114050_LavaTileIsle(void);
void func_801031C0_114640_LavaTileIsle(void);
void func_80103300_114780_LavaTileIsle(omObjData* obj);
void func_801036B4_114B34_LavaTileIsle(omObjData* obj);
void func_80103790_114C10_LavaTileIsle(omObjData* obj);
void func_8010385C_114CDC_LavaTileIsle(omObjData* obj);
void func_801039A4_114E24_LavaTileIsle(omObjData* obj);
void func_80103B04_114F84_LavaTileIsle(omObjData* obj);
void func_80104154_1155D4_LavaTileIsle(omObjData* obj);
void func_801046E0_115B60_LavaTileIsle(void);
void func_8010479C_115C1C_LavaTileIsle(omObjData* obj);
void func_80104C94_116114_LavaTileIsle(omObjData* obj);
void func_801052A8_116728_LavaTileIsle(void);
void func_80105400_116880_LavaTileIsle(void);
void func_801057C0_116C40_LavaTileIsle(void);
void func_80105E34_1172B4_LavaTileIsle(void);
void func_80105E80_117300_LavaTileIsle(void);
void func_80105F6C_1173EC_LavaTileIsle(void);
void func_80106120_1175A0_LavaTileIsle(void);
void func_80106444_1178C4_LavaTileIsle(void);
void func_801066D4_117B54_LavaTileIsle(void);
void func_801069D8_117E58_LavaTileIsle(void);
void func_80106F2C_1183AC_LavaTileIsle(void);
void func_80107414_118894_LavaTileIsle(void);
void func_80107694_118B14_LavaTileIsle(void);
void func_80107B24_118FA4_LavaTileIsle(void);
void func_80107E3C_1192BC_LavaTileIsle(void);
void func_801081C4_119644_LavaTileIsle(void);
void func_80108204_119684_LavaTileIsle(void);
void func_80108388_119808_LavaTileIsle(void);
void func_80108494_119914_LavaTileIsle(void);
s32 func_80108648_119AC8_LavaTileIsle(omObjData* obj);
void func_801095BC_11AA3C_LavaTileIsle(void);
s32 func_80109E5C_11B2DC_LavaTileIsle(omObjData* obj);
void func_80109E70_11B2F0_LavaTileIsle(void);
void func_80109F44_11B3C4_LavaTileIsle(void);

#endif
