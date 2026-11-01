#ifndef _OVL_1B_H
#define _OVL_1B_H

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/data.h"
#include "game/collision.h"

/* Ballon Burst: one retail file, 1A40A0.c; .data is asm (0x1AB520), .rodata from 0x1AB6D0. */

typedef struct BBWork {
    /* 0x00 */ s8 player;
    /* 0x01 */ u8 group;
    /* 0x02 */ s8 slot;
    /* 0x03 */ s8 character;
    /* 0x04 */ s8 port;
    /* 0x05 */ s8 cpu; /* -1: a human */
    /* 0x06 */ s8 unk_06;
    /* 0x07 */ s8 unk_07;
    /* 0x08 */ s8 unk_08;
    /* 0x09 */ s8 unk_09;
    /* 0x0A */ u8 unk_0A;
    /* 0x0B */ u8 unk_0B;
    /* 0x0C */ s8 unk_0C;
} BBWork; /* size = 0xD */

typedef struct BBView {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ f32 sx;
    /* 0x08 */ f32 sy;
    /* 0x0C */ char unk_0C[0xC];
    /* 0x18 */ f32 ox;
    /* 0x1C */ f32 oy;
    /* 0x20 */ char unk_20[0x14];
} BBView; /* size = 0x34 */

typedef struct BBEspSlot {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ char unk_06[0x1E];
} BBEspSlot; /* size = 0x24 */
typedef struct BBCharData {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s32 dir;
    /* 0x08 */ s32 model;
    /* 0x0C */ char unk_0C[0xC];
} BBCharData; /* size = 0x18 */

/* ---- main-segment API missing from include/ ---- */
extern BBCharData D_800CD438_CE038[];
extern BBEspSlot* D_800F93FC_F9FFC;
void ViewportSet(u8, f32, f32, f32, f32, f32, f32);
void func_80026D28_27928(s16);
void func_80026E00_27A00(s16, f32, f32, f32);
void func_80026DAC_279AC(s16, u8, u8, u8);
void func_8007273C_7333C(const u8* arg0, u8 arg1);
u16 LoadFormFile(s32, s32);
void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_800298A4_2A4A4(s16, s32, s32); /* model attribute */
void func_80029B80_2A780(s16 arg0, s16 arg1);
void func_80029BF0_2A7F0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void func_80029C74_2A874(s16, f32); /* motion frame */
s32 func_80029E14_2AA14(s16 arg0); /* main: u8; retail callers re-extend the result */
void func_80029E80_2AA80(s16, s32, s32);
void func_8002D0A0_2DCA0(s16 arg0, u8 arg1);
void func_8002D124_2DD24(s16 index);
omObjData* func_800732B0_73EB0(u32 arg0);
void espDispOff(u16);
s32 func_8001A2F8_1AEF8(s32); /* main: s16; retail re-extends the result */
s16 func_8001AAAC_1B6AC(s16 arg0, u16 arg1, u16 arg2);
void omSetTra(omObjData*, f32, f32, f32);
void omSetSca(omObjData*, f32, f32, f32);
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
s32 omOvlReturnEx(s16);
s16 SprCreate(s32 num, s32 attr);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprAttrSet(s16 grpIdx, s16 idx, s32 flag);
void SprAttrReset(s16, s16, s32);
s16 func_800691FC_69DFC(s16 mesNo, ...); /* MP1 GMesCreate */
void func_8006D4D0_6E0D0(s16); /* the seconds counter */
void func_8006D518_6E118(void);
s16 PlayMusic(s16);
s32 PlaySound(s32);
void func_800794A8_7A0A8(s32);
void func_80079614_7A214(s16 time);
void func_800796F0_7A2F0(s16 sound, s16 pitch);
void func_80079848_7A448(s16 arg0);
void InitFadeIn(s32, s32);
void InitFadeOut(s32, s32);
s32 _CheckFlag(s32);
u8 rand8(void);
f32 HuMathSin(f32);
void Hu3DCamSetPerspective(s16, f32, f32, f32);
void Hu3DCamSetPositionOrientation(s16 camIndex, Vec* pos, Vec* at, Vec* up);
void* func_80027154_27D54(s32 size, s16 tag); /* HuMemAllocTag */
s16 func_8002838C_28F8C(s32 arg0, void (*arg1)(Gfx**, s32, s32), u8 arg2);
void omSetRot(omObjData*, f32, f32, f32);
u16 func_80078EA8_79AA8(void);
void func_80020D20_21920(s16 arg0);
s16 func_80027D3C_2893C(s16 linkMdlId); /* model copy */
void func_80029708_2A308(s32);
void func_80029A8C_2A68C(s16);
f32 func_80029CE4_2A8E4(s16);
void func_8002A00C_2AC0C(s16 model);
void func_8002AC10_2B810(s16 arg0, f32 arg1, f32 arg2, s32 arg3);
void func_8002CD78_2D978(s16, u8, u8, u8, u8);
void func_8002CDB4_2D9B4(s16, u8, u8, u8, u8);
void func_8002CDF0_2D9F0(s16, u8, u8, u8, u8);
s16 func_80079798_7A398(s16 sfx, s16 player);
void func_800798F8_7A4F8(s16 sound, s16 pan);
void func_8007A27C_7AE7C(s32 prio, s32 sprId, void* draw, f32 fov, Vec* eye, Vec* at);
void func_8007A7FC_7B3FC(void*);
void SprPosSet(s16 grpIdx, s16 idx, s16 x, s16 y);
void SprScaleSet(s16 group, s16 member, f32 x, f32 y);
void SprExec(void);
extern f32 D_800CA02C_CAC2C;
extern Gfx* D_800FDBCC_FE7CC;
extern u16 D_801011FC_101DFC;
extern u8 D_80102720_103320;
void func_80081B28_82728(s16 group, s16 member, s16 arg2);

/* ---- .data ---- */
extern const char D_80109E30_1AB6D0_BallonBurst[];
extern f32 D_80109C88_1AB528_BallonBurst[6];
extern f32 D_80109CA0_1AB540_BallonBurst[6];
extern Vec D_80109D30_1AB5D0_BallonBurst[4]; /* the four seats */
extern s16 D_80109C80_1AB520_BallonBurst[4]; /* sound pan per seat */
extern f32 D_80109D00_1AB5A0_BallonBurst[6];
extern f32 D_80109D18_1AB5B8_BallonBurst[6];
extern f32 D_80109D60_1AB600_BallonBurst[6];
extern f32 D_80109D78_1AB618_BallonBurst[5];
extern s8 D_80109D8C_1AB62C_BallonBurst[8];
extern s8 D_80109D94_1AB634_BallonBurst[8];
extern s8 D_80109D9C_1AB63C_BallonBurst[][4];

/* ---- .bss ---- */
extern BBWork* D_8010A5F0_1ABE90_BallonBurst[4];
extern omObjData* D_8010A600_1ABEA0_BallonBurst;
extern Vec D_8010A608_1ABEA8_BallonBurst[2][8]; /* a hose per team; [7] the balloon end */
extern f32 D_8010A6C8_1ABF68_BallonBurst;
extern s16 D_8010A6CC_1ABF6C_BallonBurst;
extern s8 D_8010A6CE_1ABF6E_BallonBurst[4];
extern s16 D_8010A6D2_1ABF72_BallonBurst;
extern u8 D_8010A6D4_1ABF74_BallonBurst;
extern f32 D_8010A6D8_1ABF78_BallonBurst[4];
extern omObjData* D_8010A6E8_1ABF88_BallonBurst[4];
extern omObjData* D_8010A6F8_1ABF98_BallonBurst;
extern s16 D_8010A6FC_1ABF9C_BallonBurst;
extern omObjData* D_8010A704_1ABFA4_BallonBurst;
extern f32 D_8010A708_1ABFA8_BallonBurst[2];
extern f32 D_8010A710_1ABFB0_BallonBurst;
extern u8 D_8010A714_1ABFB4_BallonBurst[2];
extern f32 D_8010A718_1ABFB8_BallonBurst[2]; /* balloon height */
extern u16 D_8010A720_1ABFC0_BallonBurst;
extern u16 D_8010A722_1ABFC2_BallonBurst;
extern s8 D_8010A724_1ABFC4_BallonBurst[4];
extern omObjData* D_8010A728_1ABFC8_BallonBurst;
extern s16 D_8010A730_1ABFD0_BallonBurst[4][2]; /* the CPU script: phase, count */
extern s8 D_8010A740_1ABFE0_BallonBurst[2];
extern omObjData* D_8010A748_1ABFE8_BallonBurst[4];
extern f32 D_8010A758_1ABFF8_BallonBurst;
extern omObjData* D_8010A75C_1ABFFC_BallonBurst;
extern s32 D_8010A760_1AC000_BallonBurst;
extern f32 D_8010A764_1AC004_BallonBurst[2]; /* balloon speed */
extern omObjData* D_8010A76C_1AC00C_BallonBurst;
extern s32 D_8010A770_1AC010_BallonBurst;
extern f32 D_8010A778_1AC018_BallonBurst[2][0x31];
extern u16 D_8010A900_1AC1A0_BallonBurst;
extern f32 D_8010A904_1AC1A4_BallonBurst;
extern f32 D_8010A908_1AC1A8_BallonBurst[2][0x31];
extern f32 D_8010AA90_1AC330_BallonBurst;
extern omObjData* D_8010AA94_1AC334_BallonBurst;
extern omObjData* D_8010AA98_1AC338_BallonBurst[4];
extern s16 D_8010AAA8_1AC348_BallonBurst;
extern omObjData* D_8010AAB0_1AC350_BallonBurst[4];
extern s8 D_8010AAC0_1AC360_BallonBurst; /* the winning team; 2 none */
extern s32 D_8010AAC8_1AC368_BallonBurst[0xD];
extern s8 D_8010AAFC_1AC39C_BallonBurst[4]; /* the winners, then the losers */
extern s16 D_8010AB00_1AC3A0_BallonBurst;
extern u8 D_8010AB02_1AC3A2_BallonBurst; /* state */
extern f32 D_8010AB04_1AC3A4_BallonBurst;

void func_80102800_1A40A0_BallonBurst(void);
void func_801037F4_1A5094_BallonBurst(omObjData* obj);
void func_80103924_1A51C4_BallonBurst(omObjData* obj);
void func_80103C10_1A54B0_BallonBurst(BBView* view);
void func_8010644C_1A7CEC_BallonBurst(void);
void func_80106454_1A7CF4_BallonBurst(Gfx** gfx, s32 arg1, s32 arg2);
void func_801064A4_1A7D44_BallonBurst(omObjData* obj);
void func_801064C0_1A7D60_BallonBurst(omObjData* obj);
void func_801064DC_1A7D7C_BallonBurst(omObjData* obj);
void func_801064F8_1A7D98_BallonBurst(omObjData* obj);
void func_80106514_1A7DB4_BallonBurst(omObjData* obj, s32 player);
void func_80106AEC_1A838C_BallonBurst(omObjData* obj);
s32 func_80109B70_1AB410_BallonBurst(u16 player);
void func_80109BD0_1AB470_BallonBurst(void);

#endif /* _OVL_1B_H */
