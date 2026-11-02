#ifndef _OVL_11_H
#define _OVL_11_H

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/data.h"
#include "game/collision.h"

/* Move to the Music: one retail file, 155C90.c; .data is asm (0x160060: step tables, display lists),
   .rodata from 0x1602A0. */

typedef struct MMPlayer {
    /* 0x00 */ s8 player;
    /* 0x01 */ s8 cell; /* 0 = the solo dancer, 1..3 = the group */
    /* 0x02 */ u8 port;
    /* 0x03 */ s8 character;
    /* 0x04 */ s8 cpu; /* -1: a human */
    /* 0x05 */ s8 step[2][6];
    /* 0x11 */ s8 offs[2][6];
} MMPlayer; /* size = 0x1D */

typedef struct MMCharData {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s32 dir;
    /* 0x08 */ char unk_08[0x10];
} MMCharData; /* size = 0x18 */

/* ---- main-segment API missing from include/ ---- */
extern MMCharData D_800CD438_CE038[];
extern s16 D_800FA188_FAD88;
extern u8 D_800FA656;
extern u16 D_801011FC_101DFC;
extern s8 D_80102708_103308;

f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* cos */
void func_80082488_83088(s16, s16, u16);
void func_800298A4_2A4A4(s16, s32, s32);
void SprPosSet(s16, s16, s16, s16);
void func_80018CCC_198CC(omObjData*, u16, s32);
void func_80029B80_2A780(s16, s16);
u16 LoadFormFile(s32, s32);
void HmfModelObjAttrSet(s16, s32, s32);
HuSprite* func_80082550_83150(s16, s16);
void func_800297E8_2A3E8(s16, f32, f32, f32);
s16 func_800691FC_69DFC(s16, ...);
void func_8002D2B4_2DEB4(s16, f32, f32, f32);
void func_8002D274_2DE74(s16, u8, u8, u8); /* main: s8 */
void func_8002D1EC_2DDEC(s16, u8);
f32 func_80029D0C_2A90C(s16);
void func_80029714_2A314(s16, f32, f32, f32);
void func_800283DC_28FDC(s16);
s16 func_8001A2F8_1AEF8(s32);
void func_80029C74_2A874(s16, f32);
s16 func_8001AAAC_1B6AC(s16, u16, u16);
void espDispOff(u16);
void omVibrate(s16, s16, s16, s16);
omObjData* func_800732B0_73EB0(u32);
s32 func_80029E14_2AA14(s16); /* 2AA14.c: u8; retail callers re-extend the result */
f32 func_80029CE4_2A8E4(s16);
void func_80029BF0_2A7F0(s16, s16, s16, s16, s16);
void func_80026E00_27A00(s16, f32, f32, f32);
void func_80026DAC_279AC(s16, u8, u8, u8);
s32 func_80025718_26318(s16, s16, s16);
void func_80025554_26154(s16, s16, s16, s16);
s16 func_80025384_25F84(s16, s16, s16, s32);
void omSetTra(omObjData*, f32, f32, f32);
void func_800798F8_7A4F8(s16, s16);
s16 func_800797DC_7A3DC(s32, s16);
s16 func_80079798_7A398(s16, s16);
void func_80079614_7A214(s16);
void func_800795D8_7A1D8(s16, s8);
void func_8007273C_7333C(u8*, u8);
s16 func_8003DF08_3EB08(void*);
void func_80029AFC_2A6FC(s16);
void func_80029708_2A308(s32);
s16 func_8002838C_28F8C(s32, void (*)(Gfx**, s32, s32), u8);
s16 func_80027D3C_2893C(s16);
void func_80026D28_27928(s16);
void func_80021160_21D60(s16, s32, s32);
u16 func_80020EBC_21ABC(void*, s32, u8);
void func_80020D20_21920(s16);
void func_80011738_12338(s32, s32, void*);
void SprPrioSet(s16, s16, u16);
s16 SprCreate(s32, s32);
void SprAttrSet(s16, s16, s32);
void SprAttrReset(s16, s16, s32);
void SprAnimSet(s16, s16, s16, u16);
s32 PlaySound(s32);
void HuMemMemoryFreePerm(void*);
void Hu3DCamUpdateMtx(s16);
void Hu3DCamSetPositionOrientation(s16, Vec*, Vec*, Vec*);

/* ---- .data (asm) ---- */
extern u32 D_8010CBD0_160060_MoveToTheMusic[]; /* frames per state */
extern u32 D_8010CBF0_160080_MoveToTheMusic[];
extern u8 D_8010CC00_160090_MoveToTheMusic[2][6];
extern u8 D_8010CC05_160095_MoveToTheMusic; /* [0][5] */
extern u8 D_8010CC06_160096_MoveToTheMusic[6]; /* [1] */
extern s16 D_8010CC0C_16009C_MoveToTheMusic[];
extern Gfx D_8010CD78_160208_MoveToTheMusic[];
extern Gfx D_8010CDC8_160258_MoveToTheMusic[];

/* ---- .bss ---- */
extern MMPlayer D_8010D690_160B20_MoveToTheMusic[4];
extern MMPlayer* D_8010D708_160B98_MoveToTheMusic[4];
extern s16 D_8010D720_160BB0_MoveToTheMusic;
extern u8 D_8010D722_160BB2_MoveToTheMusic[6];
extern s32 D_8010D728_160BB8_MoveToTheMusic[4];
extern s16 D_8010D738_160BC8_MoveToTheMusic[4];
extern u8 D_8010D740_160BD0_MoveToTheMusic;
extern u8 D_8010D741_160BD1_MoveToTheMusic[3];
extern s16 D_8010D748_160BD8_MoveToTheMusic[8];
extern u8 D_8010D758_160BE8_MoveToTheMusic;
extern s16 D_8010D75A_160BEA_MoveToTheMusic;
extern s32 D_8010D75C_160BEC_MoveToTheMusic;
extern s32 D_8010D760_160BF0_MoveToTheMusic;
extern omObjData* D_8010D764_160BF4_MoveToTheMusic;
extern s16 D_8010D768_160BF8_MoveToTheMusic[4];
extern s32 D_8010D770_160C00_MoveToTheMusic[4];
extern omObjData* D_8010D780_160C10_MoveToTheMusic[4];
extern s16 D_8010D796_160C26_MoveToTheMusic;
extern s32 D_8010D798_160C28_MoveToTheMusic;
extern s16 D_8010D79C_160C2C_MoveToTheMusic[4];
extern s16 D_8010D7A4_160C34_MoveToTheMusic[4];
extern s16 D_8010D7AC_160C3C_MoveToTheMusic[4];
extern s32 D_8010D7B8_160C48_MoveToTheMusic[4];
extern u8 D_8010D7C8_160C58_MoveToTheMusic[4]; /* cell -> player */
extern s16 D_8010D7CC_160C5C_MoveToTheMusic; /* game state */
extern u8 D_8010D7CE_160C5E_MoveToTheMusic;
extern s16 D_8010D7D0_160C60_MoveToTheMusic;
extern s16 D_8010D7D4_160C64_MoveToTheMusic;
extern s32 D_8010D7D8_160C68_MoveToTheMusic[4];
extern s32 D_8010D7E8_160C78_MoveToTheMusic;
extern s16 D_8010D7F0_160C80_MoveToTheMusic[11];
extern u8 D_8010D806_160C96_MoveToTheMusic[6];
extern s16 D_8010D80C_160C9C_MoveToTheMusic;
extern s16 D_8010D80E_160C9E_MoveToTheMusic[4];

/* ---- 155C90.c ---- */
void func_80102800_155C90_MoveToTheMusic(void);
s16 func_80102A68_155EF8_MoveToTheMusic(s32);
void func_80102B18_155FA8_MoveToTheMusic(omObjData*);
void func_80103424_1568B4_MoveToTheMusic(void);
void func_80104DBC_15824C_MoveToTheMusic(omObjData*);
void func_80105568_1589F8_MoveToTheMusic(void);
void func_80105594_158A24_MoveToTheMusic(omObjData*);
void func_801055C8_158A58_MoveToTheMusic(omObjData*);
void func_801055FC_158A8C_MoveToTheMusic(omObjData*);
void func_80105630_158AC0_MoveToTheMusic(omObjData*);
void func_80105664_158AF4_MoveToTheMusic(omObjData*, s8);
void func_80105A20_158EB0_MoveToTheMusic(omObjData*);
void func_80105A3C_158ECC_MoveToTheMusic(omObjData*);
void func_80105A58_158EE8_MoveToTheMusic(omObjData*);
void func_80105A74_158F04_MoveToTheMusic(omObjData*);
void func_80105A90_158F20_MoveToTheMusic(omObjData*, s8);
void func_80106E84_15A314_MoveToTheMusic(s16, s16);
void func_80106EC8_15A358_MoveToTheMusic(Gfx**, s32, s32);
void func_8010A704_15DB94_MoveToTheMusic(s16);
void func_8010A730_15DBC0_MoveToTheMusic(s16, f32, f32, f32);
void func_8010B7F0_15EC80_MoveToTheMusic(omObjData*);

#endif
