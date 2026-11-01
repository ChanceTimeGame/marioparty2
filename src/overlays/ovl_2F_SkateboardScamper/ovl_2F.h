#ifndef _OVL_2F_H
#define _OVL_2F_H

/* Overlay 2F: Skateboard Scamper (MP1 ovl_16 SkateBoardSkamper's descendant). Four players ride down a
   course (z from 9000 to -9400) with a chaser, D_80108B50_2384A0_SkateboardScamper, rolling after them.
   D_800F8FD0_F9BD0: 0 intro (the chaser wakes and drops in, func_801043E4), 1 race, 2 result, 3
   fade. A jumps, B pushes (speed by rank, func_80103BF4). One retail file; .rodata is carved from
   0x238600. N64 offsets are in the comments. */

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/data.h"
#include "game/collision.h"
#include "game/malloc.h"

/* Per-character data, 0x18 bytes each (main, table at D_800CD438_CE038). */
typedef struct SSCharData {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s32 unk_04; /* model/motion directory */
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ char unk_14[4];
} SSCharData;

/* ---- main-segment API used by 2F (missing from include/) ---- */
extern SSCharData D_800CD438_CE038[];
extern u8 D_800BF794_C0394; /* collision: the course object (MP1 D_800B8954) */
extern u8 D_800BF798_C0398; /* MP1 D_800B8958 */
extern u8 D_800BF799_C0399; /* MP1 D_800B8959 */
extern f32 D_800BF7A0_C03A0;
extern f32 D_800BF7A4_C03A4;
extern f32 D_800BF7A8_C03A8;
extern f32 D_800BF7C0_C03C0; /* top speed */
extern f32 D_800BF7C4_C03C4;
extern f32 D_800BF7C8_C03C8;
extern f32 D_800BF7CC_C03CC;
extern f32 D_800BF7D0_C03D0; /* MP1 D_800B8990 */
extern f32 D_800BF7D4_C03D4;
extern f32 D_800BF7D8_C03D8;
extern s32 D_800F8FD0_F9BD0; /* scene state */
extern omObjData* D_800F9CE0_FA8E0[];
extern f32 D_800FA5BC_FB1BC[];
extern u16 D_800FA606_FB206;
extern f32 D_800FD478_FE078; /* D_800FD474_FE074.y by retail's own label */
extern s16 D_800FD7FC_FE3FC;
extern f32 D_8010105C_101C5C;
extern u16 D_801011FC_101DFC;
extern f32 D_80101300_101F00;
extern u8 D_80102720_103320;
extern f32 D_80102750_103350[]; /* D_8010274C_10334C + 4: [0] y, [1] z, by retail's own label */

void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
void Hu3DCamSetPositionOrientation(s16, Vec*, Vec*, Vec*);
void Hu3DCamUpdateMtx(s16 camIndex);
f64 fabs(f64);
f32 HuMathSin(f32);
u16 LoadFormFile(s32, s32);
s32 PlaySound(s32);
f32 func_800023CC_2FCC(omObjData* obj, f32 x, f32 y, f32 z, Vec3f* normal);
f32 func_80002A28_3628(omObjData* obj, f32 x, f32 y, f32 z, f32 unused);
s32 func_80005110_5D10();
s32 func_80006F34_7B34(omObjData* obj, Vec4f* p, f32 arg2);
s32 func_8000DC10_E810(Vec4f* p, GroundWork* gw);
void func_8000776C_836C(omObjData* obj);
void func_8000BE8C_CA8C(omObjData*, f32);
void func_8000BEA4_CAA4(omObjData*, f32);
void func_8000BFF0_CBF0(omObjData*);
void func_8000C018_CC18(u16);
void func_8000C024_CC24(omObjData* obj, u8 idx, u8 val);
void func_8000C11C_CD1C(omObjData*, s32, s32, s32);
void func_8000C2A0_CEA0(omObjData* obj, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_8000C35C_CF5C(omObjData* obj, f32 x, f32 y, f32 z);
void func_8000C37C_CF7C(omObjData* obj, f32 x, f32 y, f32 z);
void func_8000C38C_CF8C(void);
void func_8000C398_CF98(void);
void func_8000C3A8_CFA8(void);
void func_8000C3B8_CFB8(void);
void func_8000C3C8_CFC8(void);
void func_8000C460_D060(void);
void func_8000C578_D178(s32);
void func_8000C584_D184(MgWork* w, s32 state);
void func_8000C6FC_D2FC(omObjData* obj, u32 dir, s32 file, u16 player, s32 arg4, s32 arg5);
void func_8000CC74_D874(omObjData* obj, s16 model, s16 motion);
void func_8000E0C0_ECC0(MgWork* w, s32 slot, void* hook);
u16 func_80018A30_19630(s32 file, s32 attr);
u16 func_80018A64_19664(s32 arg0, s32 arg1);
s32 func_80019000_19C00(omObjData* obj);
void func_80019378_19F78(omObjData* obj);
s32 func_80019B9C_1A79C(omObjData* obj, u16 motion);
s32 func_80019CA4_1A8A4(omObjData* obj, u16 motion);
void func_80019F0C_1AB0C(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4);
void func_8001A12C_1AD2C(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4, s32 arg5);
void func_80020D20_21920(s16 arg0);
u16 func_8002109C_21C9C(s16 index, s32 arg1);
void func_800211E8_21DE8(s16 index, u8 arg1);
void func_80021250_21E50(s16 index, u8 arg1, u8 arg2, u8 arg3);
void func_80026DAC_279AC(s16, u8, u8, u8);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void* func_80027154_27D54(s32 size, s16 tag);
s16 func_80027D3C_2893C(s16 linkMdlId);
void func_80029708_2A308(s32);
void func_80029714_2A314(s16, f32, f32, f32);
void func_8002979C_2A39C(s16 idx, f32 x, f32 y, f32 z);
void func_800297E8_2A3E8(s16, f32, f32, f32);
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029A8C_2A68C(s16);
void func_80029C74_2A874(s16, f32);
f32 func_80029CE4_2A8E4(s16);
f32 func_80029D0C_2A90C(s16);
f32 func_80029E3C_2AA3C(s16 idx);
void func_8002BB4C_2C74C(s16 arg0, char* arg1, char* arg2);
void func_8002CD6C_2D96C(u8 arg0);
void func_8002D1EC_2DDEC(s16, u8);
void func_8002D274_2DE74(s16 arg0, u8 arg1, u8 arg2, u8 arg3);
void func_8002D2B4_2DEB4(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_8002D4D0_2E0D0(s16 n);
f32 func_8002D958_2E558(f32);
void func_8002F290_2FE90(s32* arg0, s32 n);
void func_8003C984_3D584(s16 model, Vec3f* normal);
s16 func_800691FC_69DFC(s16 mesNo, ...);
s32 func_80069538_6A138(void);
void func_8007273C_7333C(u8* arg0, u8 arg1);
omObjData* func_800732B0_73EB0(u32 arg0);
u16 func_80078EA8_79AA8(void);
void func_800794F0_7A0F0(s32);
void func_80079614_7A214(s16 time);
void func_80079684_7A284(s8);
s16 func_80079798_7A398(s16 sfx, s16 player);
s16 func_800797DC_7A3DC(s32 id, s16 player);
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size);
void func_800B2060_B2C60(f32* m, f32 x, f32 y, f32 z);
f32 func_800B75A8_B81A8(f32 y, f32 x);
f32 func_800B7890_B8490(f32);
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);

/* ---- overlay .data (asm, in address order) ---- */
extern u32 D_80108AF0_238440_SkateboardScamper;    /* intro frames; 0x80108AF4 s32 -65536, unused */
extern u8 D_80108AF8_238448_SkateboardScamper[4];  /* finishing place per player, 0 still racing */
extern u8 D_80108AFC_23844C_SkateboardScamper;     /* players past the goal */
extern u8 D_80108AFD_23844D_SkateboardScamper;     /* players still in (from 4) */
extern u8 D_80108AFE_23844E_SkateboardScamper;
extern s8 D_80108AFF_23844F_SkateboardScamper;     /* winner, -1 none; 0x80108B00 f32 9700 unused */
extern f32 D_80108B04_238454_SkateboardScamper[4]; /* per-player jump tilt */
extern s32 D_80108B14_238464_SkateboardScamper[4]; /* players by rank */
extern f32 D_80108B24_238474_SkateboardScamper[8]; /* boost per rank; [4..7] drag, unused */
extern Vec D_80108B44_238494_SkateboardScamper;    /* the leader's position */
extern f32 D_80108B50_2384A0_SkateboardScamper;    /* the chaser: z */
extern f32 D_80108B54_2384A4_SkateboardScamper;    /* y */
extern f32 D_80108B58_2384A8_SkateboardScamper;    /* scale z */
extern f32 D_80108B5C_2384AC_SkateboardScamper;    /* scale x, y */
extern f32 D_80108B60_2384B0_SkateboardScamper;    /* speed */
extern s8 D_80108B64_2384B4_SkateboardScamper;     /* the chaser has shrunk away */
extern s32 D_80108B68_2384B8_SkateboardScamper;    /* light colour; retail reads the low byte */
extern s32 D_80108B6C_2384BC_SkateboardScamper;
extern s32 D_80108B70_2384C0_SkateboardScamper;
extern s32 D_80108B74_2384C4_SkateboardScamper;    /* light direction */
extern s32 D_80108B78_2384C8_SkateboardScamper;
extern s32 D_80108B7C_2384CC_SkateboardScamper;
extern f32 D_80108B80_2384D0_SkateboardScamper;    /* model 8: y */
extern f32 D_80108B84_2384D4_SkateboardScamper;
extern f32 D_80108B88_2384D8_SkateboardScamper;    /* its vertical speed, 1000.0f resting */
extern s32 D_80108B8C_2384DC_SkateboardScamper;
extern f32 D_80108B90_2384E0_SkateboardScamper;
extern f32 D_80108B94_2384E4_SkateboardScamper;
extern f32 D_80108B98_2384E8_SkateboardScamper;
extern f32 D_80108B9C_2384EC_SkateboardScamper;
extern f32 D_80108BA0_2384F0_SkateboardScamper;
extern f32 D_80108BA4_2384F4_SkateboardScamper;
extern f32 D_80108BA8_2384F8_SkateboardScamper;
extern f32 D_80108BAC_2384FC_SkateboardScamper;
extern f32 D_80108BB0_238500_SkateboardScamper;
extern f32 D_80108BB4_238504_SkateboardScamper;
extern f32 D_80108BB8_238508_SkateboardScamper[4]; /* z of the lights */
extern f32 D_80108BC8_238518_SkateboardScamper;
extern s32 D_80108BCC_23851C_SkateboardScamper;
extern s32 D_80108BD0_238520_SkateboardScamper;
extern f32 D_80108BD4_238524_SkateboardScamper;
extern f32 D_80108BD8_238528_SkateboardScamper;
extern f32 D_80108BDC_23852C_SkateboardScamper;
extern f32 D_80108BE0_238530_SkateboardScamper;
extern s32 D_80108BE4_238534_SkateboardScamper;
extern s32 D_80108BE8_238538_SkateboardScamper;
extern f32 D_80108BEC_23853C_SkateboardScamper;
extern f32 D_80108BF0_238540_SkateboardScamper;
extern f32 D_80108BF4_238544_SkateboardScamper;
extern u32 D_80108BF8_238548_SkateboardScamper;    /* 3600 */
extern u32 D_80108BFC_23854C_SkateboardScamper;
extern s32 D_80108C00_238550_SkateboardScamper;
extern u8 D_80108C04_238554_SkateboardScamper;
extern f32 D_80108C08_238558_SkateboardScamper[11]; /* course piece y by id (D_80108C24 = [7]) */
extern f32 D_80108C34_238584_SkateboardScamper[11]; /* its speed */
extern s32 D_80108C60_2385B0_SkateboardScamper;     /* model to copy, -1 none; retail reads the low half */
extern s32 D_80108C64_2385B4_SkateboardScamper;
extern f32 D_80108C68_2385B8_SkateboardScamper[4];  /* push factor by rank */
extern char* D_80108C78_2385C8_SkateboardScamper[6]; /* face textures by character */
extern f32 D_80108C90_2385E0_SkateboardScamper[5];  /* course z where a course item reappears */
extern s32 D_80108CA4_2385F4_SkateboardScamper;     /* sprite slot to copy, -1 none; low half read */

/* ---- overlay .bss ---- */
extern s32 D_80108D90_2386E0_SkateboardScamper[4];  /* per-player voice, -1 stopped */
extern s16 D_80108DA2_2386F2_SkateboardScamper;     /* never written in 2F: 0 */

/* ---- 232150.c ---- */
void func_80102800_232150_SkateboardScamper(void);
void func_80102F64_2328B4_SkateboardScamper(void);
void func_801030D8_232A28_SkateboardScamper(omObjData* obj);
void func_8010311C_232A6C_SkateboardScamper(omObjData* obj, u8 state, u32 t);
void func_8010337C_232CCC_SkateboardScamper(omObjData* obj);
void func_801035C8_232F18_SkateboardScamper(omObjData* obj);
s32 func_80103BAC_2334FC_SkateboardScamper(s32 n, s32 player);
s32 func_80103BF4_233544_SkateboardScamper(s32 player);
void func_80103C38_233588_SkateboardScamper(void);
void func_80103D80_2336D0_SkateboardScamper(omObjData* obj);
void func_80103F6C_2338BC_SkateboardScamper(void);
void func_80104258_233BA8_SkateboardScamper(omObjData* obj);
s32 func_801043E4_233D34_SkateboardScamper(omObjData* obj, u32 t);
void func_80104BAC_2344FC_SkateboardScamper(omObjData* obj);
void func_80104DB4_234704_SkateboardScamper(omObjData* obj, u32 t);
void func_80105100_234A50_SkateboardScamper(omObjData* obj);
void func_801054BC_234E0C_SkateboardScamper(omObjData* obj);
void func_801057C8_235118_SkateboardScamper(omObjData* obj);
void func_80105984_2352D4_SkateboardScamper(omObjData* obj);
void func_80105B40_235490_SkateboardScamper(omObjData* obj);
void func_80105C28_235578_SkateboardScamper(omObjData* obj);
void func_80105D10_235660_SkateboardScamper(omObjData* obj);
void func_80105D5C_2356AC_SkateboardScamper(omObjData* obj);
void func_80105DA4_2356F4_SkateboardScamper(omObjData* obj);
void func_80105DF0_235740_SkateboardScamper(omObjData* obj);
void func_80105E38_235788_SkateboardScamper(omObjData* obj);
void func_80105E84_2357D4_SkateboardScamper(omObjData* obj);
void func_80105EDC_23582C_SkateboardScamper(omObjData* obj);
void func_80105F28_235878_SkateboardScamper(omObjData* obj);
void func_80105F7C_2358CC_SkateboardScamper(omObjData* obj);
void func_80105FC8_235918_SkateboardScamper(omObjData* obj);
s32 func_80106010_235960_SkateboardScamper(omObjData* obj, f32* x, f32* y, f32* z, f32* ground, Vec3f* normal);
void func_8010618C_235ADC_SkateboardScamper(omObjData* obj, Vec3f* n);
f32 func_80106300_235C50_SkateboardScamper(f32 z);
f32 func_80106358_235CA8_SkateboardScamper(omObjData* obj, f32 angle, f32 x, f32 y, f32 z);
void func_80106A04_236354_SkateboardScamper(MgWork* w, f32 v);
s32 func_80106A58_2363A8_SkateboardScamper(u16 btn, f32 z);
void func_80106A94_2363E4_SkateboardScamper(omObjData* obj);
void func_80107994_2372E4_SkateboardScamper(omObjData* obj, s32 dir, s32 file, s32 arg3, u16 player, f32 x, f32 y, f32 z);
void func_80107D30_237680_SkateboardScamper(omObjData* obj);
void func_80107DAC_2376FC_SkateboardScamper(omObjData* obj);
void func_80107E2C_23777C_SkateboardScamper(omObjData* obj);
void func_80107EAC_2377FC_SkateboardScamper(omObjData* obj);
void func_80107F2C_23787C_SkateboardScamper(omObjData* obj);
void func_8010813C_237A8C_SkateboardScamper(omObjData* obj);
ColActorWork* func_801082C0_237C10_SkateboardScamper(omObjData* obj, s32 dir, f32 x, f32 y, f32 z, s32 arg5, s32 arg6);
void func_801084D8_237E28_SkateboardScamper(omObjData* obj);
void func_80108528_237E78_SkateboardScamper(omObjData* obj);
void func_8010857C_237ECC_SkateboardScamper(omObjData* obj);
void func_801085CC_237F1C_SkateboardScamper(omObjData* obj);
void func_80108624_237F74_SkateboardScamper(omObjData* obj);

#endif
