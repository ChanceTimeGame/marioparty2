#ifndef _OVL_04_H
#define _OVL_04_H

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/data.h"
#include "game/collision.h"

/* Hammer Slammer, an item minigame for one player. One retail file, F84C0.c; .data is asm
   (0xFECF0), .rodata from 0xFEE50. */

typedef struct HSState {
    /* 0x00 */ s8 player;
    /* 0x01 */ s8 port;
    /* 0x02 */ s8 character;
    /* 0x03 */ s8 cpu; /* -1: a human */
    /* 0x04 */ s16 cpuTimer; /* the power the CPU stops at */
    /* 0x06 */ s16 cpuDelay;
    /* 0x08 */ s8 swing; /* frames of the swing */
    /* 0x09 */ s8 result; /* the panel, 0-5; 6 the top, a coin toss; -1 missed; -2 not yet */
    /* 0x0A */ char unk_0A[2];
    /* 0x0C */ f32 y; /* the puck */
    /* 0x10 */ f32 vy;
    /* 0x14 */ f32 power[3]; /* the last three frames */
    /* 0x20 */ char unk_20[0xC];
} HSState; /* size = 0x2C */

/* ---- main-segment API missing from include/ ---- */
typedef struct HSEspSlot {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ char unk_06[0x1E];
} HSEspSlot; /* size = 0x24 */
typedef struct HSCharData {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s32 unk_04; /* model/motion directory */
    /* 0x08 */ char unk_08[0x10];
} HSCharData; /* size = 0x18 */
extern HSCharData D_800CD438_CE038[];
extern u16 D_800CAFD8[];
extern u16 D_800CAFE4[];
extern u16 D_801011FC_101DFC;
extern u16 ContBtnTrg[4];
extern f32 D_800FA5BC_FB1BC[];
extern HSEspSlot* D_800F93FC_F9FFC;
extern Gfx* D_800FDBCC_FE7CC;
extern f32 D_80101078_101C78;
extern f32 D_800F8410_F9010;

void func_80020D20_21920(s16 arg0);
void func_80079128_79D28(void);
void func_80029708_2A308(s32);
void func_80018E30_19A30(s32);
s32 func_80018E78_19A78(void);
void ScissorSet(u8, f32, f32, f32, f32);
void ViewportSet(u8, f32, f32, f32, f32, f32, f32);
void func_80026D28_27928(s16);
void func_80026E00_27A00(s16, f32, f32, f32);
void func_80026DAC_279AC(s16, u8, u8, u8);
void func_8007273C_7333C(const u8* arg0, u8 arg1);
s16 func_80025384_25F84(s16 arg0, s16 arg1, s16 arg2, s32 arg3);
void func_80025554_26154(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
s32 func_80025718_26318(s16 arg0, s16 arg1, s16 arg2);
u16 LoadFormFile(s32, s32);
void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void func_8002979C_2A39C(s16 idx, f32 x, f32 y, f32 z); /* model rotation */
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_800298A4_2A4A4(s16, s32, s32); /* model attribute */
void func_80029B80_2A780(s16 arg0, s16 arg1);
void func_80029BF0_2A7F0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void func_80029C74_2A874(s16, f32); /* motion frame */
s32 func_80029E14_2AA14(s16 arg0); /* main: u8; retail callers re-extend the result */
void func_80029E80_2AA80(s16, s32, s32);
void func_8002D0A0_2DCA0(s16 arg0, u8 arg1);
void func_8002D124_2DD24(s16 index);
void func_8002D1EC_2DDEC(s16 arg0, u8 arg1);
void func_8002D274_2DE74(s16 arg0, u8 arg1, u8 arg2, u8 arg3);
void func_8002D2B4_2DEB4(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
s32 func_80073014_73C14(u32 arg0, void* arg1); /* main: s16; retail does not re-extend */
omObjData* func_800732B0_73EB0(u32 arg0);
void espDispOff(u16);
s16 func_8001A2F8_1AEF8(s32);
s16 func_8001AAAC_1B6AC(s16 arg0, u16 arg1, u16 arg2);
void omSetTra(omObjData*, f32, f32, f32);
void omSetSca(omObjData*, f32, f32, f32);
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
s32 omOvlReturnEx(s16);
HuSprite* func_80082550_83150(s16 grpIdx, s16 idx);
s16 SprCreate(s32 num, s32 attr);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprAttrSet(s16 grpIdx, s16 idx, s32 flag);
void SprAttrReset(s16, s16, s32);
void SprPos3DSet(s16 grpIdx, s16 idx, s16 camIdx, f32 x, f32 y, f32 z);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
void func_800824B4_830B4(s16 grpIdx, s32 idx, u8 r, u8 g, u8 b, u16 a);
s16 func_800691FC_69DFC(s16 mesNo, ...); /* MP1 GMesCreate */
void func_8006D4D0_6E0D0(s16); /* the seconds counter */
void func_8006D518_6E118(void);
s16 PlayMusic(s16);
s32 PlaySound(s32);
void func_800794A8_7A0A8(s32);
void func_80079518_7A118(s8);
void func_80079614_7A214(s16 time);
void func_800796F0_7A2F0(s16 sound, s16 pitch);
void func_80079848_7A448(s16 arg0);
void InitFadeIn(s32, s32);
void InitFadeOut(s32, s32);
s32 _CheckFlag(s32);
u8 rand8(void);
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* cos */
void Hu3DCamSetPerspective(s16, f32, f32, f32);
void Hu3DCamSetPositionOrientation(s16 camIndex, Vec* pos, Vec* at, Vec* up);
void Hu3DCamUpdateMtx(s16 camIndex);

void* func_80027154_27D54(s32 size, s16 tag); /* HuMemAllocTag */
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size); /* memset */
void func_8002C524_2D124(s16, s16, s16);
void func_8002C628_2D228(s16 arg0, s16 arg1, char* arg2);
void func_80019E84_1AA84(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4);
void omSetRot(omObjData*, f32, f32, f32);
u16 func_80078EA8_79AA8(void);
extern u8 D_80102720_103320;
void func_8002C570_2D170(s16 arg0);
void func_80029AFC_2A6FC(s16 arg0);
void func_80053FC8_54BC8(void);
void func_80053FE8_54BE8(s32 arg0);
void func_80054018_54C18(s16 arg0, s16 arg1);
void MBDBackKill(void);
void func_80050AE0_516E0(void);
s16 func_8002838C_28F8C(s32 arg0, void (*arg1)(Gfx**, s32, s32), u8 arg2);

/* The sparkle clock's step: faster while the arc lasts. */
#define HS_STEP ((u32)((s16)(u16)D_80109BD2_FF892_HammerSlammer >= 0 \
    ? (s32)(g = D_80109C30_FF8F0_HammerSlammer + 5) + (s16)((s16)(u16)D_80109BD2_FF892_HammerSlammer / 3) \
    : (s32)D_80109C30_FF8F0_HammerSlammer + 1))

/* ---- .data ---- */
extern f32 D_80109030_FECF0_HammerSlammer[7]; /* panel x; [6] the player's */
extern f32 D_8010904C_FED0C_HammerSlammer[7]; /* panel y; [6] the player's */
extern f32 D_80109068_FED28_HammerSlammer[6];
extern f32 D_80109080_FED40_HammerSlammer[6];
extern f32 D_80109098_FED58_HammerSlammer[6];
extern s32 D_801090B0_FED70_HammerSlammer[6]; /* voice directory per character */
extern s32 D_801090C8_FED88_HammerSlammer[11];
extern Gfx D_80109140_FEE00_HammerSlammer[];

/* ---- .bss ---- */
extern HSState D_80109B20_FF7E0_HammerSlammer;
extern omObjData* D_80109B50_FF810_HammerSlammer;
extern s16 D_80109B54_FF814_HammerSlammer; /* state */
extern f32 D_80109B58_FF818_HammerSlammer;
extern f32 D_80109B60_FF820_HammerSlammer[8]; /* spark y */
extern f32 D_80109B80_FF840_HammerSlammer[4]; /* trail y */
extern omObjData* D_80109B90_FF850_HammerSlammer;
extern u32 D_80109B94_FF854_HammerSlammer; /* time in the state */
extern u8 D_80109B98_FF858_HammerSlammer;
extern u16 D_80109B9A_FF85A_HammerSlammer; /* done */
extern f32 D_80109BA0_FF860_HammerSlammer[4]; /* trail x */
extern f32 D_80109BB0_FF870_HammerSlammer[8]; /* spark clock */
extern u8 D_80109BD0_FF890_HammerSlammer; /* the quit fade's counter */
extern s8 D_80109BD1_FF891_HammerSlammer; /* shake */
extern s16 D_80109BD2_FF892_HammerSlammer;
extern s16 D_80109BD8_FF898_HammerSlammer[12];
extern s32 D_80109BCC_FF88C_HammerSlammer; /* the visible player model */
extern f32 D_80109BF0_FF8B0_HammerSlammer;
extern f32 D_80109BF4_FF8B4_HammerSlammer;
extern s32 D_80109BF8_FF8B8_HammerSlammer; /* frames */
extern f32 D_80109C00_FF8C0_HammerSlammer[8]; /* spark speed */
extern s32 D_80109C1C_FF8DC_HammerSlammer[3]; /* voice channel: s16 in an s32 */
extern u8 D_80109C28_FF8E8_HammerSlammer;
extern s8 D_80109C29_FF8E9_HammerSlammer; /* shake sign */
extern s32 D_80109C2C_FF8EC_HammerSlammer;
extern u32 D_80109C30_FF8F0_HammerSlammer; /* trail clock */
extern f32 D_80109C34_FF8F4_HammerSlammer; /* the bell's speed */
extern s32 D_80109C38_FF8F8_HammerSlammer[6]; /* item on panel 1-5; the low half is read by its label */

void func_80102800_F84C0_HammerSlammer(void);
void func_80102A24_F86E4_HammerSlammer(omObjData* obj);
void func_80102FB0_F8C70_HammerSlammer(omObjData* obj);
void func_80103484_F9144_HammerSlammer(omObjData* obj);
void func_80103554_F9214_HammerSlammer(omObjData* obj);
void func_8010363C_F92FC_HammerSlammer(omObjData* obj);
void func_80103ECC_F9B8C_HammerSlammer(omObjData* obj);
void func_80104000_F9CC0_HammerSlammer(omObjData* obj);
void func_8010746C_FD12C_HammerSlammer(s16 arg0, s16 arg1);
void func_801074B0_FD170_HammerSlammer(Gfx** gfx, s32 arg1, s32 arg2);
void func_80107A2C_FD6EC_HammerSlammer(Gfx** gfx, s32 arg1, s32 arg2);

#endif /* _OVL_04_H */
