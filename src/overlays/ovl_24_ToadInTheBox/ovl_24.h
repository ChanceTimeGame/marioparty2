#ifndef _OVL_24_H
#define _OVL_24_H

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/data.h"
#include "game/collision.h"

/* Toad in the Box: one retail file, 1E89B0.c; .data is asm (0x1F0CB0: display lists, sound pans),
   .rodata from 0x1F0D40. */

typedef struct TBInfo {
    /* 0x00 */ s8 character;
    /* 0x01 */ s8 port;
    /* 0x02 */ s8 cpu; /* -1: a human */
    /* 0x03 */ char unk_03;
    /* 0x04 */ u8 hits;
    /* 0x05 */ char unk_05;
    /* 0x06 */ s16 cpuState;
    /* 0x08 */ s16 cpuTime;
} TBInfo; /* size = 0xA */

typedef struct TBBox {
    /* 0x00 */ f32 angle;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ char unk_09;
    /* 0x0A */ u16 unk_0A;
    /* 0x0C */ s16 state;
    /* 0x0E */ char unk_0E[2];
    /* 0x10 */ s32 time;
    /* 0x14 */ f32 unk_14;
} TBBox; /* size = 0x18 */

typedef struct TBCharData {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s32 dir;
    /* 0x08 */ s32 model;
    /* 0x0C */ char unk_0C[0xC];
} TBCharData; /* size = 0x18 */

typedef struct TBEspSlot {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ char unk_06[0x1E];
} TBEspSlot; /* size = 0x24 */

/* MgWork 0xA8 is a u16 frame counter here (collision.h has it as padding): a struct view, not a
   pointer cast, because GCC's loop pass needs the store to be a struct field */
typedef struct TBWork {
    /* 0x00 */ char unk_00[0xA8];
    /* 0xA8 */ u16 unk_A8;
} TBWork;
#define TB_A8(w) (((TBWork*)(w))->unk_A8)

/* x reduced to 0..360 */
#define TB_MOD360(x) ((x) + (-(f32)((s32)(x) / 360) * 360.0 + ((x) < 0.0 ? 360.0 : 0.0)))

/* a float screen position to 10.2, rounded towards zero by hand; sign tested on a separate value */
#define TB_FIX2(f, s) ((s32)((f) * 4.0) + ((s) < 0.0f ? 1 : 0))
#define TB_FIX(f) TB_FIX2(f, f)

/* ---- main-segment API missing from include/ ---- */
extern TBCharData D_800CD438_CE038[];
extern u16 D_800FD410_FE010[];
extern s8 ContStkX[];
extern s8 ContStkY[];
extern s16 D_800FC9BE_FD5BE[4];
extern s16 D_800FD468_FE068[4];
void func_80019B28_1A728(omObjData* obj, u8 flags);
extern TBEspSlot* D_800F93FC_F9FFC;
void ViewportSet(u8, f32, f32, f32, f32, f32, f32);
void func_80026D28_27928(s16);
void func_80026E00_27A00(s16, f32, f32, f32);
void func_80026DAC_279AC(s16, u8, u8, u8);
u16 LoadFormFile(s32, s32);
void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void func_8002979C_2A39C(s16 idx, f32 x, f32 y, f32 z); /* model rotation */
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_800298A4_2A4A4(s16, s32, s32); /* model attribute */
void func_80029AFC_2A6FC(s16 arg0);
void func_80029B80_2A780(s16 arg0, s16 arg1);
void func_80029BF0_2A7F0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void func_80029C74_2A874(s16, f32); /* motion frame */
s32 func_80029E14_2AA14(s16 arg0); /* main: u8; retail callers re-extend the result */
void func_80029E80_2AA80(s16, s32, s32);
void func_8002D0A0_2DCA0(s16 arg0, u8 arg1);
void func_8002D124_2DD24(s16 index);
void func_8002D4D0_2E0D0(s16 n);
void func_8002F290_2FE90(s32* arg0, s32 n);
omObjData* func_800732B0_73EB0(u32 arg0);
void espDispOff(u16);
s32 func_8001A2F8_1AEF8(s32); /* main: s16; retail re-extends the result */
s16 func_8001AAAC_1B6AC(s16 arg0, u16 arg1, u16 arg2);
u16 func_80018A30_19630(s32 arg0, s32 arg1);
void omSetTra(omObjData*, f32, f32, f32);
void omSetRot(omObjData*, f32, f32, f32);
void omSetSca(omObjData*, f32, f32, f32);
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
s32 omOvlReturnEx(s16);
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
s16 func_80079798_7A398(s16 sfx, s16 player);
void func_800798F8_7A4F8(s16 sound, s16 pan);
void InitFadeIn(s32, s32);
void InitFadeOut(s32, s32);
s32 _CheckFlag(s32);
u8 rand8(void);
f32 HuMathSin(f32);
void Hu3DCamSetPerspective(s16, f32, f32, f32);
void* func_80027154_27D54(s32 size, s16 tag); /* HuMemAllocTag */
s16 func_8002838C_28F8C(s32 arg0, void (*arg1)(Gfx**, s32, s32), u8 arg2);
u16 func_80078EA8_79AA8(void);
void func_80020D20_21920(s16 arg0);
s16 func_80027D3C_2893C(s16 linkMdlId); /* model copy */
void func_80029708_2A308(s32);
void func_80007790_8390(omObjData* obj);
void func_8000BE74_CA74(omObjData*, f32);
void func_8000BE8C_CA8C(omObjData*, f32);
void func_8000BE98_CA98(omObjData*, f32);
void func_8000BEF8_CAF8(omObjData*, s32, f32);
void func_8000BF54_CB54(omObjData* obj, f32 arg1, f32 arg2, f32 minX, f32 minZ, f32 maxX, f32 maxZ);
void func_8000C018_CC18(u16);
void func_8000C024_CC24(omObjData* obj, u8 idx, s8 val);
void func_8000C38C_CF8C(void);
void func_8000C3B8_CFB8(void);
void func_8000C3C8_CFC8(void);
void func_8000C460_D060(void);
void func_8000C578_D178(u8);
void func_8000C6FC_D2FC(omObjData* obj, u32 dir, s32 file, u16 player, s32 arg4, s32 arg5);
void func_8000E0C0_ECC0(MgWork* work, s32 slot, void* hook);
void func_800191D4_19DD4(omObjData* obj, u8 idx, f32 x, f32 y, f32 z, f32 a, f32 b);
s32 func_80019B9C_1A79C(omObjData* obj, s32 motion); /* main: u16; retail passes a word */
void func_80019E84_1AA84(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4);
void func_80019F0C_1AB0C(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4);
HuSprite* func_80082550_83150(s16 grpIdx, s16 idx);
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size);
extern Gfx* D_800FDBCC_FE7CC;
extern u16 D_801011FC_101DFC;
extern u8 D_80102720_103320;
extern f32 D_80102750_103350;
extern s16 D_800FA606_FB206;

/* ---- .data ---- */
extern s16 D_8010AB00_1F0CB0_ToadInTheBox[4]; /* sound pan per player */
extern Gfx D_8010AB08_1F0CB8_ToadInTheBox[];
extern Gfx D_8010AB50_1F0D00_ToadInTheBox[];

/* ---- .bss ---- */
extern TBInfo D_8010B390_1F1540_ToadInTheBox[4];
extern TBInfo* D_8010B3B8_1F1568_ToadInTheBox[4];
extern TBBox D_8010B3C8_1F1578_ToadInTheBox[4];
extern TBBox* D_8010B428_1F15D8_ToadInTheBox[4];
extern omObjData* D_8010B440_1F15F0_ToadInTheBox[4];
extern s8 D_8010B450_1F1600_ToadInTheBox; /* the shake's sign */
extern u16 D_8010B452_1F1602_ToadInTheBox; /* the game is over */
extern omObjData* D_8010B458_1F1608_ToadInTheBox[4]; /* the players */
extern u8 D_8010B468_1F1618_ToadInTheBox[4];
extern omObjData* D_8010B46C_1F161C_ToadInTheBox;
extern u8 D_8010B470_1F1620_ToadInTheBox[4];
extern u8 D_8010B474_1F1624_ToadInTheBox;
extern omObjData* D_8010B478_1F1628_ToadInTheBox[4];
extern s16 D_8010B488_1F1638_ToadInTheBox; /* espr */
extern u32 D_8010B48C_1F163C_ToadInTheBox; /* time in the phase */
extern u8 D_8010B490_1F1640_ToadInTheBox;
extern s16 D_8010B492_1F1642_ToadInTheBox; /* phase */
extern s16 D_8010B494_1F1644_ToadInTheBox; /* espr */
extern u16 D_8010B496_1F1646_ToadInTheBox;
extern omObjData* D_8010B498_1F1648_ToadInTheBox;
extern s8 D_8010B49C_1F164C_ToadInTheBox; /* the shake's amplitude */
extern omObjData* D_8010B4A0_1F1650_ToadInTheBox[4]; /* the boxes */
extern omObjData* D_8010B4B0_1F1660_ToadInTheBox[4];
extern s8 D_8010B4C0_1F1670_ToadInTheBox; /* the winner */
extern s8 D_8010B4C1_1F1671_ToadInTheBox[5];
extern omObjData* D_8010B4C8_1F1678_ToadInTheBox;
extern u8 D_8010B4CC_1F167C_ToadInTheBox;
extern omObjData* D_8010B4D0_1F1680_ToadInTheBox[4];

/* ---- this overlay ---- */
void func_80102800_1E89B0_ToadInTheBox(void);
void func_80102DCC_1E8F7C_ToadInTheBox(omObjData* obj);
void func_8010377C_1E992C_ToadInTheBox(omObjData* obj);
void func_801049AC_1EAB5C_ToadInTheBox(omObjData* obj);
void func_80104AD8_1EAC88_ToadInTheBox(omObjData* obj);
void func_80104AF4_1EACA4_ToadInTheBox(omObjData* obj);
void func_80104B10_1EACC0_ToadInTheBox(omObjData* obj);
void func_80104B2C_1EACDC_ToadInTheBox(omObjData* obj);
void func_80104B48_1EACF8_ToadInTheBox(omObjData* obj, s32 i);
void func_80104CF4_1EAEA4_ToadInTheBox(omObjData* obj);
void func_80104D10_1EAEC0_ToadInTheBox(omObjData* obj);
void func_80104D2C_1EAEDC_ToadInTheBox(omObjData* obj);
void func_80104D48_1EAEF8_ToadInTheBox(omObjData* obj);
void func_80104D64_1EAF14_ToadInTheBox(omObjData* obj, s32 i);
void func_80104EFC_1EB0AC_ToadInTheBox(omObjData* obj);
void func_80104F90_1EB140_ToadInTheBox(omObjData* obj);
void func_80105288_1EB438_ToadInTheBox(omObjData* obj, s32 dir, s32 file, u16 player, f32 x, f32 y, f32 z);
void func_8010559C_1EB74C_ToadInTheBox(omObjData* obj);
void func_80105638_1EB7E8_ToadInTheBox(omObjData* obj);
void func_801056D4_1EB884_ToadInTheBox(omObjData* obj);
void func_80105770_1EB920_ToadInTheBox(omObjData* obj);
void func_80105834_1EB9E4_ToadInTheBox(omObjData* obj, s32 i);
void func_80105950_1EBB00_ToadInTheBox(omObjData* obj);
s32 func_801094FC_1EF6AC_ToadInTheBox(omObjData* obj);
void func_80109524_1EF6D4_ToadInTheBox(omObjData* obj, s16 frame);
void func_80109568_1EF718_ToadInTheBox(Gfx** gfx, s32 mtx, s32 cam);
void func_80109798_1EF948_ToadInTheBox(s16 spr);
void func_801097C4_1EF974_ToadInTheBox(s16 spr, f32 x, f32 y, f32 scale);

#endif
