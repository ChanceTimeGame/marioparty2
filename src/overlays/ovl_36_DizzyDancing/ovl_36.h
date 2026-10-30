#ifndef _OVL_36_H
#define _OVL_36_H

/* Overlay 36: Dizzy Dancing (4P). The players ride a spinning turntable (D_80107870[6], spin
   direction D_8010785B) that carries them outwards; when they reach the rim they are all thrown
   to the corners (MgWork positions from a local table), landing dizzy with a stick remap
   (D_8010785C: 0 none, 1 mirrored, 2-5 rotated/flipped) until a CPU plan or their own recovery
   sets DDCpu.flags & 1. A ball (D_80107870[7]) then descends to the centre; the first player to
   touch it (D_8010785A) wins 10 coins. 30 seconds (901 frames), then nobody wins. No MP1 ancestor.
   Retail is two files: 26FEE0.c (KMC mul fix, blank lines stripped) and 274C00.c (the two table
   clears). .data (0x274CB0) is still asm; .rodata is carved from 0x274D30. */

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/data.h"
#include "game/collision.h"

/* ---- main-segment API used by 36 (missing from include/) ---- */

typedef struct DDCharData {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s32 unk_04; /* model/motion directory */
    /* 0x08 */ s32 unk_08; /* model file */
    /* 0x0C */ char unk_0C[0xC];
} DDCharData; /* size = 0x18 */
extern DDCharData D_800CD438_CE038[];

extern f32 D_800BF79C_C039C;
extern s32 D_800F8FD0_F9BD0; /* scene state */
extern u16 D_800FA606_FB206;
extern f32 D_800F94A8_FA0A8[];    /* CZoomM */
extern Vec3f D_80102770_103370[]; /* CRotM */
extern Vec3f D_801013B0_101FB0[]; /* CenterM */
extern u16 D_801011FC_101DFC;
extern omObjData* D_800FFFD8_100BD8[];
extern u16 D_800FC87A_FD47A;
extern s8 ContStkX[4];
extern s8 ContStkY[4];

void func_8002D4D0_2E0D0(s16 n);
void func_80020D20_21920(s16 arg0);
void func_8000C460_D060(void);
void func_80026DAC_279AC(s16, u8, u8, u8);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
u8 rand8(void);
s32 PlaySound(s32);
s16 PlayMusic(s16);
void func_800794A8_7A0A8(s32);
void func_80079614_7A214(s16 time); /* music fade-out */
s16 func_800797DC_7A3DC(s32 id, s16 player);
s16 func_80079798_7A398(s16 sfx, s16 player);
void func_80079128_79D28(void);
void func_80079FF4_7ABF4(omObjData* object);
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
s16 func_800691FC_69DFC(s16 mesNo, ...); /* MP1 GMesCreate */
s32 func_80069538_6A138(void);          /* MP1 GMesStatAllGet */
void func_8006D4D0_6E0D0(s16);
void func_8006D518_6E118(void);
omObjData* func_800732B0_73EB0(u32 arg0);
void func_8007273C_7333C(u8* arg0, u8 arg1);
f64 func_800B1820_B2420(f64); /* sqrt */
f64 func_800B75D0_B81D0(f64); /* cos */
f64 func_800B80D0_B8CD0(f64); /* sin */
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* cos */
void* func_80027154_27D54(s32 size, s16 tag); /* HuMemAllocTag */
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size); /* memset */
void func_800B1F50_B2B50(f32* m, f32 x, f32 y, f32 z);
u16 func_80018A30_19630(s32 arg0, s32 arg1); /* model from a file */
u16 LoadFormFile(s32, s32);
void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_800298A4_2A4A4(s16, s32, s32); /* model attribute */
void func_80029A8C_2A68C(s16);
void func_80029AFC_2A6FC(s16);
void func_80029EDC_2AADC(s16 arg0, u8 arg1);
s16 func_8001A2F8_1AEF8(s32 arg0);
void* SprAnimGet(s16 animIdx);
s16 SprCreate(s32 num, s32 attr);
void SprAttrReset(s16 grpIdx, s16 idx, s32 flag);
void SprScaleSet(s16 group, s16 member, f32 x, f32 y);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprBankSet(s16 group, s16 member, s16 bank);
void SprAttrSet(s16, s16, s32);
void SprPosSet(s16 grpIdx, s16 idx, s16 x, s16 y);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
s16 func_8002838C_28F8C(s32 arg0, void (*arg1)(Gfx**), u8 arg2);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
s32 func_8001B434_1C034(Vec* tri, Vec* pos, f32 r, Vec* hit); /* sphere against a triangle */
void HuVecCopyXYZ(Vec*, f32, f32, f32);
void omSetSca(omObjData*, f32, f32, f32);
/* GroundWork setters (C8E0.c) */
void func_8000BE8C_CA8C(omObjData*, f32);
void func_8000BE98_CA98(omObjData*, f32);
void func_8000BEA4_CAA4(omObjData*, f32);
void func_8000BF24_CB24(omObjData* obj, f32 arg1, f32 x0, f32 z0, f32 x1, f32 z1);
void func_8000BFA8_CBA8(omObjData*, f32 top, f32 depth, f32 radius);
void func_8000C018_CC18(u16);
/* players */
void func_8000C6FC_D2FC(omObjData* obj, u32 dir, s32 file, u16 player, s32 arg4, s32 arg5);
void func_8000C024_CC24(omObjData* obj, u8 idx, u8 val);
void func_8000E0C0_ECC0(MgWork* w, s32 slot, void* hook);
void func_80007790_8390(omObjData* obj);
s32 func_80019000_19C00(omObjData* obj);
u16 func_80018FF0_19BF0(omObjData* obj);
s32 func_80019B9C_1A79C(omObjData* obj, u16 motion);
s32 func_80019CA4_1A8A4(omObjData* obj, u16 motion);
void func_800191D4_19DD4(omObjData* obj, u8 idx, f32 x, f32 y, f32 z, f32 a, f32 b);
void func_80019F0C_1AB0C(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4);
void func_80019E84_1AA84(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4);
s32 func_8008F618_90218(void);
void InitFadeIn(s32, s32);
void InitFadeOut(s32, s32);
void func_80018E30_19A30(s32);
void func_80018F58_19B58(s32);
void ViewportSet(u8, f32, f32, f32, f32, f32, f32);
void Hu3DCamSetPerspective(s16, f32, f32, f32);
s32 _CheckFlag(s32);
void osViBlack(u8 active);
s32 omOvlReturnEx(s16);

/* ---- this overlay ---- */

/* The actor table, 0x48 bytes each: [0..3] the players, [4] the backdrop sprite object, [5] the
   floor picture, [6] the turntable, [7] the ball, [8..11] the invisible walls. */
typedef struct DDActor {
    /* 0x00 */ omObjData* obj;
    /* 0x04 */ s16 unk_04;
    /* 0x08 */ s32 unk_08[6];
    /* 0x20 */ u16 state;
    /* 0x22 */ u16 unk_22; /* frames; the ball: bob on */
    /* 0x24 */ u16 unk_24; /* the ball: shadow on */
    /* 0x26 */ u16 unk_26;
    /* 0x28 */ u16 unk_28; /* countdown */
    /* 0x2A */ u16 unk_2A; /* CPU plan */
    /* 0x2C */ u16 unk_2C; /* CPU player */
    /* 0x2E */ s16 unk_2E;
    /* 0x30 */ s16 unk_30; /* a player: on the disc (carried by it) */
    /* 0x32 */ s16 unk_32;
    /* 0x34 */ s16 unk_34;
    /* 0x36 */ s16 unk_36;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
} DDActor; /* size = 0x48 */

/* What a CPU player knows, one per player. */
typedef struct DDCpu {
    /* 0x00 */ f32 dist;  /* distance from the centre */
    /* 0x04 */ f32 angle; /* direction to the centre */
    /* 0x08 */ u16 flags; /* 1 stick already chosen (no dizzy remap), 2 has made its first plan */
    /* 0x0C */ f32 otherDist[4];
    /* 0x1C */ f32 otherAngle[4];
    /* 0x2C */ f32 otherY[4];
    /* 0x3C */ s16 stkX; /* big-endian low byte read as s8 */
    /* 0x3E */ s16 stkY;
} DDCpu; /* size = 0x40 */

/* What SprAnimGet hands the full-screen backdrop. */
/* C8E0.c MgMotion: MgWork.unk_E8, one per motion slot. */
typedef struct DDMotion {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ char unk_04[8];
} DDMotion; /* size = 0xC */

typedef struct DDImage {
    /* 0x00 */ char unk_00[8];
    /* 0x08 */ void* pixels;
    /* 0x0C */ void* palette;
} DDImage;

/* .data (274CB0, in 26FEE0.c) */
extern s32 D_801075D0_274CB0_DizzyDancing[6];  /* win motions' directory, by character */
extern u16 D_801075E8_274CC8_DizzyDancing[4];  /* win voice file */
extern s32 D_801075F0_274CD0_DizzyDancing;     /* camera set */
extern f32 D_801075F4_274CD4_DizzyDancing;     /* player 0's last x */
extern f32 D_801075F8_274CD8_DizzyDancing;     /* player 0's last z */
extern f32 D_801075FC_274CDC_DizzyDancing;     /* arm angles */
extern f32 D_80107600_274CE0_DizzyDancing;
extern f32 D_80107604_274CE4_DizzyDancing;     /* ball wobble phases */
extern f32 D_80107608_274CE8_DizzyDancing;
extern f32 D_8010760C_274CEC_DizzyDancing[4][3]; /* start positions */
extern s16 D_8010763C_274D1C_DizzyDancing;     /* result delay */
extern u8 D_8010763E_274D1E_DizzyDancing;      /* music started */
extern s16 D_80107640_274D20_DizzyDancing;     /* result timeout, 300 */

/* .bss */
extern u16 D_80107850_274F30_DizzyDancing;     /* game state */
extern u16 D_80107852_274F32_DizzyDancing;     /* 1 thrown, 2 ball down, 4 ready, 8 touched, 0x10 time up, 0x20 all done */
extern s16 D_80107854_274F34_DizzyDancing;     /* timer, frames */
extern s16 D_80107856_274F36_DizzyDancing;
extern u16 D_80107858_274F38_DizzyDancing;     /* ground objects */
extern u8 D_8010785A_274F3A_DizzyDancing;      /* the winner */
extern u8 D_8010785B_274F3B_DizzyDancing;      /* spin direction */
extern u8 D_8010785C_274F3C_DizzyDancing;      /* stick remap */
extern u8 D_8010785D_274F3D_DizzyDancing[4][2]; /* win motion variant, win motion */
/* Retail's own labels inside D_80107870: */
extern omObjData* D_80107990_275070_DizzyDancing; /* = D_80107870[4].obj */
extern omObjData* D_801079D8_2750B8_DizzyDancing; /* = D_80107870[5].obj */
extern DDActor D_80107A20_275100_DizzyDancing;    /* = D_80107870[6] */
extern DDActor D_80107A68_275148_DizzyDancing;    /* = D_80107870[7] */
extern DDActor D_80107AB0_275190_DizzyDancing[];  /* = &D_80107870[8] */
extern s16 D_801078A0_274F80_DizzyDancing[];      /* = &D_80107870[0].unk_30, stride 0x48 */
extern u16 D_80107A40_275120_DizzyDancing;     /* = D_80107870[6].state */
extern u16 D_80107A88_275168_DizzyDancing;     /* = D_80107870[7].state */
extern s16 D_80107994_275074_DizzyDancing;     /* = D_80107870[4].unk_04: the backdrop sprite group */
extern DDImage* D_80107868_274F48_DizzyDancing;
extern DDActor D_80107870_274F50_DizzyDancing[50];
extern s16 D_80108680_275D60_DizzyDancing[50];
extern DDCpu D_801086F0_275DD0_DizzyDancing[4];

void func_80102800_26FEE0_DizzyDancing(void);
void func_8010281C_26FEFC_DizzyDancing(u8 player);
u8 func_801028A0_26FF80_DizzyDancing(u8 n, u64* used);
f32 func_801029F0_2700D0_DizzyDancing(f32 x);
void func_80102B40_270220_DizzyDancing(Vec* from, Vec* to, Vec* out);
f32 func_80102EB4_270594_DizzyDancing(f32 angle, f32 add);
void func_80102F0C_2705EC_DizzyDancing(omObjData* obj, MgWork* w, f32 x, f32 y, f32 z);
void func_80102F9C_27067C_DizzyDancing(void);
void func_8010311C_2707FC_DizzyDancing(Gfx** gfxp);
void func_80103440_270B20_DizzyDancing(omObjData* obj);
void func_80103448_270B28_DizzyDancing(omObjData* obj);
void func_801034C0_270BA0_DizzyDancing(void);
void func_801034FC_270BDC_DizzyDancing(omObjData* obj);
void func_80103504_270BE4_DizzyDancing(omObjData* obj);
void func_80103760_270E40_DizzyDancing(void);
void func_801037A8_270E88_DizzyDancing(omObjData* obj);
void func_80103EF8_2715D8_DizzyDancing(omObjData* obj);
void func_801040D4_2717B4_DizzyDancing(void);
void func_80104110_2717F0_DizzyDancing(omObjData* obj);
void func_80104118_2717F8_DizzyDancing(omObjData* obj);
void func_80104284_271964_DizzyDancing(void);
s16 func_80104320_271A00_DizzyDancing(omObjData* obj, Vec* hit);
void func_8010449C_271B7C_DizzyDancing(omObjData* obj);
void func_80104AB4_272194_DizzyDancing(omObjData* obj);
void func_80104BCC_2722AC_DizzyDancing(void);
u8 func_80104C08_2722E8_DizzyDancing(u16* table);
u8 func_80104C5C_27233C_DizzyDancing(omObjData* obj, s16 near);
void func_8010504C_27272C_DizzyDancing(omObjData* obj);
s32 func_80105A4C_27312C_DizzyDancing(omObjData* obj);
s32 func_80105A74_273154_DizzyDancing(omObjData* obj);
s32 func_80105AD0_2731B0_DizzyDancing(omObjData* obj);
void func_80105AF4_2731D4_DizzyDancing(omObjData* obj, u8 player);
void func_80105D70_273450_DizzyDancing(omObjData* obj, u16 a, u16 b);
void func_80105DF0_2734D0_DizzyDancing(omObjData* obj);
void func_80106650_273D30_DizzyDancing(omObjData* obj);
void func_80106BEC_2742CC_DizzyDancing(void);
void func_80106D44_274424_DizzyDancing(omObjData* obj);
void func_80106DA4_274484_DizzyDancing(omObjData* obj);
void func_80106E58_274538_DizzyDancing(omObjData* obj);
void func_80106E98_274578_DizzyDancing(omObjData* obj);
void func_80106F0C_2745EC_DizzyDancing(omObjData* obj);
void func_80106F30_274610_DizzyDancing(omObjData* obj);
void func_80106F68_274648_DizzyDancing(omObjData* obj);
void func_80106FC0_2746A0_DizzyDancing(omObjData* obj);
void func_80107230_274910_DizzyDancing(omObjData* obj);
void func_801072F0_2749D0_DizzyDancing(void);
void func_80107520_274C00_DizzyDancing(void);
void func_801075A4_274C84_DizzyDancing(void);

#endif
