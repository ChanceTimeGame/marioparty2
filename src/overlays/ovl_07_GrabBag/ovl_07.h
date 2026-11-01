#ifndef _OVL_07_H
#define _OVL_07_H

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/data.h"
#include "game/collision.h"

/* ---- main-segment API missing from include/ ---- */
typedef struct GBCharData {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s32 unk_04; /* model/motion directory */
    /* 0x08 */ s32 unk_08; /* model file */
    /* 0x0C */ char unk_0C[0xC];
} GBCharData;
extern GBCharData D_800CD438_CE038[];
typedef struct GBEspSlot {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ char unk_06[0x1E];
} GBEspSlot; /* size = 0x24 */
extern GBEspSlot* D_800F93FC_F9FFC;
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
void func_80019378_19F78(omObjData* obj);
f32 func_800B1830_B2430(f32); /* sqrt */
void func_80007790_8390(omObjData* obj); /* player object update (MP1 func_80005A28) */
s32 func_80019000_19C00(omObjData* obj);
void func_800B2060_B2C60(f32 (*m)[4], f32 x, f32 y, f32 z); /* rotate matrix */
s16 func_800797DC_7A3DC(s32 id, s16 player);
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


extern omObjData* D_800F9CE0_FA8E0[]; /* item actors */
u16 func_80018D64_19964(s32 arg0, s32 arg1, s32 arg2); /* a sprite-model slot (D_800F86D8) from a file */
void func_8002CA48_2D648(u8 arg0, u8 arg1, u8 arg2);
void func_8000C2A0_CEA0(omObjData* obj, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_80021250_21E50(s16 index, u8 arg1, u8 arg2, u8 arg3);

/* The item work of a coin bag and a chain (0xB0): ColActorWork's layout, which main reads, with
   the fields this overlay names. */
typedef struct GBItem {
    /* 0x00 */ u8 unk_00[0x20];
    /* 0x20 */ char unk_20[2];
    /* 0x22 */ u8 unk_22; /* sprite-model slot */
    /* 0x23 */ char unk_23[3];
    /* 0x26 */ u8 unk_26[5]; /* the chain's slots */
    /* 0x2B */ char unk_2B[9];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50;
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ s8 unk_53;
    /* 0x54 */ u8 unk_54;
    /* 0x55 */ u8 unk_55;
    /* 0x56 */ char unk_56[2];
    /* 0x58 */ f32 unk_58;
    /* 0x5C */ f32 unk_5C;
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ f32 unk_68;
    /* 0x6C */ char unk_6C[4];
    /* 0x70 */ f32 unk_70;
    /* 0x74 */ f32 unk_74;
    /* 0x78 */ s32 unk_78;
    /* 0x7C */ s32 unk_7C;
    /* 0x80 */ s32 unk_80;
    /* 0x84 */ s32 (*unk_84[9])();
    /* 0xA8 */ void* unk_A8;
    /* 0xAC */ s8 unk_AC;
    /* 0xAD */ s8 unk_AD; /* player it flies to, -1 none */
    /* 0xAE */ s8 unk_AE; /* 0 or 1: the kind, for the sound */
} GBItem;

typedef struct GBPlayer {
    /* 0x000 */ MgWork w;
    /* 0x15C */ s8 unk_15C; /* start corner */
    /* 0x15D */ char unk_15D[3];
    /* 0x160 */ char unk_160[8];
    /* 0x168 */ s16 unk_168;
} GBPlayer;

void Hu3DCamSetPositionOrientation(s16 camIndex, Vec* pos, Vec* at, Vec* up);
void Hu3DCamUpdateMtx(s16 camIndex);
s16 SprAnimRead(void* arg0);
void HuMemMemoryFreeTemp(void* ptr);
void SprAttrSet(s16 grpIdx, s16 idx, s32 flag);
void CameraViewportSet(s16 camIndex, Vec* arg1, Vec* arg2);
void func_8003F710_40310(Gfx** arg0, void* timg, s32 fmt, s32 siz, s32 width, s32 height, s32 uls, s32 ult,
                         s32 lrs, s32 lrt, s32 pal, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts, s32 shiftt);
Vec func_801049F0_10E000_GrabBag(f32 x, f32 y, f32 z, f32 x2, f32 y2, f32 z2);
void func_80102998_10BFA8_GrabBag(void);
void func_80102B60_10C170_GrabBag(omObjData* obj, s32 t);
void func_80102D38_10C348_GrabBag(omObjData* obj);
void func_80103004_10C614_GrabBag(void);
void func_801030F0_10C700_GrabBag(omObjData* obj);
void func_801032E0_10C8F0_GrabBag(omObjData* obj);
void func_8010364C_10CC5C_GrabBag(omObjData* obj);
void func_80103B00_10D110_GrabBag(omObjData* obj);
void func_80104AA8_10E0B8_GrabBag(GBItem* w);
void func_80104B20_10E130_GrabBag(void);
s16 func_80104CB8_10E2C8_GrabBag(s32 file, s32 attr);
void func_80104BC0_10E1D0_GrabBag(omObjData* obj);
void func_80104D40_10E350_GrabBag(omObjData* obj);
void func_80104D8C_10E39C_GrabBag(s16 idx, f32 scale, s32 cam);
void func_801054D4_10EAE4_GrabBag(s16 idx, f32 scale, s32 cam);
void func_80105D44_10F354_GrabBag(s32 cam);
void func_80105DEC_10F3FC_GrabBag(omObjData* obj);
void func_80105E60_10F470_GrabBag(void);

/* ---- .data and .bss, in address order ---- */
extern s8 D_8010A300_113910_GrabBag;
extern u32 D_8010A304_113914_GrabBag; /* state 0 frames */
extern s32 D_8010A308_113918_GrabBag; /* state 2 frames */
extern s32 D_8010A30C_11391C_GrabBag; /* state 1 frames */
extern s32 D_8010A310_113920_GrabBag;
extern s32 D_8010A314_113924_GrabBag;
extern s8 D_8010A318_113928_GrabBag; /* quit state */
extern s32 D_8010A32C_11393C_GrabBag;
extern Vec D_8010A330_113940_GrabBag[4];
extern f32 D_8010A360_113970_GrabBag[5]; /* arc angle */
extern f32 D_8010A374_113984_GrabBag[4][5]; /* extra scale */
extern s8 D_8010A3C4_1139D4_GrabBag;
extern s16 D_8010A670_113C80_GrabBag;
extern GBItem* D_8010A674_113C84_GrabBag;
extern s32 D_8010A678_113C88_GrabBag;
extern s16 D_8010A67C_113C8C_GrabBag;
extern s16 D_8010A67E_113C8E_GrabBag;
extern s16 D_8010A680_113C90_GrabBag;
extern s16 D_8010A682_113C92_GrabBag;
extern s16 D_8010A684_113C94_GrabBag;
extern Vec D_8010A688_113C98_GrabBag[4][5];
extern Vec D_8010A778_113D88_GrabBag[4];
extern s8 D_8010A820_113E30_GrabBag;
extern s8 D_8010A82A_113E3A_GrabBag; /* chain step */
extern s8 D_8010A82B_113E3B_GrabBag;
extern s8 D_8010A82E_113E3E_GrabBag; /* seconds */
extern s8 D_8010A82F_113E3F_GrabBag;
extern s8 D_8010A834_113E44_GrabBag;
extern s32 D_8010A84C_113E5C_GrabBag;
extern Gfx D_8010A3D0_1139E0_GrabBag[];
extern Gfx D_8010A418_113A28_GrabBag[];
extern s16 D_8010A7B0_113DC0_GrabBag; /* lower backdrop sprite */
extern s16 D_8010A7B2_113DC2_GrabBag; /* upper backdrop sprite */
extern f32 D_8010A824_113E34_GrabBag; /* backdrop zoom */
/*EXTERNS*/

#endif
