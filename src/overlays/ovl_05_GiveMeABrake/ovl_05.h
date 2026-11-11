#ifndef _OVL_05_H
#define _OVL_05_H

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/data.h"

/* Give Me a Brake!, an item minigame for one player: the player rides a turntable of six item
   panels and presses A to jump off onto the panel under them. One retail file, FF7E0.c; .data is
   asm (0x105790), .rodata from 0x105830. */

typedef struct GBState {
    /* 0x00 */ s8 player;
    /* 0x01 */ s8 port;
    /* 0x02 */ s8 character;
    /* 0x03 */ s8 cpu; /* -1: a human */
    /* 0x04 */ s16 cpuTimer; /* panels the CPU lets pass; also its item once it is set */
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ s8 result; /* the panel, 0-5; -1 time out; -2 still riding */
    /* 0x09 */ char unk_09[0xF];
} GBState; /* size = 0x18 */

/* ---- main-segment API missing from include/ ---- */
typedef struct GBEspSlot {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ char unk_06[0x1E];
} GBEspSlot; /* size = 0x24 */
typedef struct GBCharData {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s32 unk_04; /* model/motion directory */
    /* 0x08 */ char unk_08[0x10];
} GBCharData; /* size = 0x18 */
extern GBCharData D_800CD438_CE038[];
extern u16 D_800CAFD8[];
extern u16 D_800CAFE4[];
extern u16 D_801011FC_101DFC;
extern u16 ContBtnTrg[4];
extern f32 D_800FA5BC_FB1BC[];
extern GBEspSlot* D_800F93FC_F9FFC;
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

/* func_80107608's rectangle: a 10.2 screen coordinate, and the step that fits 41 texels. */
#define GB_FIX(f) ((s32)((f) * 4.0) + ((f) < 0.0f ? 1 : 0))
#define GB_STEP(a, b) (s32)(41.0 / ((f32)(((s32)((b) * 4.0) + ((b) < 0.0f ? 1 : 0)) - (s32)((a) * 4.0) - ((a) < 0.0f ? 1 : 0)) / 4.0) * 1024.0)

/* ---- .data ---- */
extern s32 D_801087B0_105790_GiveMeABrake[6]; /* voice directory per character */
extern s32 D_801087C8_1057A8_GiveMeABrake[11]; /* panel sprite files by item */
extern f32 D_801087F4_1057D4_GiveMeABrake[3]; /* unused by code: 135, -22, 4 */
extern Gfx D_80108800_1057E0_GiveMeABrake[];

/* ---- .bss ---- */
extern GBState D_80108FE0_105FC0_GiveMeABrake;
extern u8 D_80109000_105FE0_GiveMeABrake; /* the quit fade's counter */
extern u32 D_80109004_105FE4_GiveMeABrake; /* the item's reveal clock, 0 = hidden */
extern s32 D_80109008_105FE8_GiveMeABrake; /* frame of the press */
extern f32 D_8010900C_105FEC_GiveMeABrake; /* jump velocity */
extern s32 D_80109010_105FF0_GiveMeABrake; /* frames */
extern u16 D_80109014_105FF4_GiveMeABrake; /* done */
extern f32 D_80109018_105FF8_GiveMeABrake; /* turntable angle */
extern f32 D_8010901C_105FFC_GiveMeABrake; /* landing z */
extern s16 D_80109020_106000_GiveMeABrake; /* the loop's sound */
extern omObjData* D_80109024_106004_GiveMeABrake;
extern s16 D_80109028_106008_GiveMeABrake; /* state */
extern f32 D_8010902C_10600C_GiveMeABrake[3]; /* trail x */
extern u16 D_80109038_106018_GiveMeABrake; /* brake time */
extern u8 D_8010903A_10601A_GiveMeABrake; /* next spark */
extern s8 D_8010903B_10601B_GiveMeABrake; /* shake */
extern s32 D_8010903C_10601C_GiveMeABrake[6]; /* item on panel 1-5; 0 is the empty panel; the low half is read by its label */
extern f32 D_80109054_106034_GiveMeABrake[3]; /* trail y */
extern f32 D_80109060_106040_GiveMeABrake; /* height */
extern u32 D_80109064_106044_GiveMeABrake; /* time in the state */
extern f32 D_80109068_106048_GiveMeABrake[3]; /* trail z */
extern f32 D_80109074_106054_GiveMeABrake; /* wheel motion frame */
extern s32 D_80109078_106058_GiveMeABrake; /* hand-out voice channels: s16 in an s32 */
extern s32 D_8010907C_10605C_GiveMeABrake;
extern s32 D_80109080_106060_GiveMeABrake;
extern s32 D_80109084_106064_GiveMeABrake;
extern s32 D_80109088_106068_GiveMeABrake; /* the player's visible model, index into model[] */
extern f32 D_8010908C_10606C_GiveMeABrake; /* landing x */
extern s16 D_80109090_106070_GiveMeABrake;
extern s16 D_80109098_106078_GiveMeABrake[8]; /* panel sprites, then the item trail */
extern f32 D_801090A8_106088_GiveMeABrake; /* turn speed; then the start angle */
extern f32 D_801090AC_10608C_GiveMeABrake; /* angle left to brake */
extern omObjData* D_801090B0_106090_GiveMeABrake; /* sparks */
extern s8 D_801090B4_106094_GiveMeABrake; /* shake sign */

void osSyncPrintf(const char* fmt, ...);
void func_80102800_FF7E0_GiveMeABrake(void);
void func_80102A70_FFA50_GiveMeABrake(omObjData* obj);
void func_80102D88_FFD68_GiveMeABrake(omObjData* obj);
void func_801032D4_1002B4_GiveMeABrake(omObjData* obj);
void func_801034C8_1004A8_GiveMeABrake(omObjData* obj);
void func_80103564_100544_GiveMeABrake(omObjData* obj);
void func_80103AB0_100A90_GiveMeABrake(omObjData* obj);
void func_80103BE8_100BC8_GiveMeABrake(omObjData* obj);
void func_80107598_104578_GiveMeABrake(s16 model, s16 frame);
void func_801075DC_1045BC_GiveMeABrake(s16 sprite);
void func_80107608_1045E8_GiveMeABrake(s16 sprite, f32 x, f32 y, f32 scale);
void func_801086C8_1056A8_GiveMeABrake(omObjData* obj);

#endif /* _OVL_05_H */
