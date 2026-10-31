#ifndef _OVL_32_H
#define _OVL_32_H

/* Overlay 32: Sneak 'n' Snore (4P). No MP1 ancestor. See the flow notes below the structs.
   Retail is three files: 24DE70.c (80102800-80106008, 2-nop pad), 251680.c (80106010-80106DDC,
   1-nop pad), 252450.c (80106DE0-end). .data stays asm (253920.data.s); .rodata is carved per
   file (0x253A40 24DE70, 0x253A50 252450; 251680 has none).

   Four players start at the far end (z -430) in lanes x = -225/-75/75/225 and creep towards
   z 200 while a Chain Chomp (object D_801084B0_253B20_SneakNSnore[0], func_80104218_24F888_SneakNSnore) sleeps at (100, 30, 550), its
   chain D_80108440_253AB0_SneakNSnore fixed at the post (0, 20, 500). A sleep bubble swells and shrinks; once the
   timer D_80108420_253A90_SneakNSnore passes the random wait D_801082D8_253948_SneakNSnore the Chomp wakes (D_801082DD_25394D_SneakNSnore), then lunges
   at the nearest player who is moving: state bits in obj->work[0] 1 chase, 2 carry back, 4 drop,
   8 go home. Reaching z 200 sets the lane's D_801082F0_253960_SneakNSnore to 2 (door open, the Chomp gets faster)
   and the player runs back; z <= -430 with the lane open is a win.
   D_800F8FD0_F9BD0 is the scene state: 0 intro, 1 game (61 s D_801082B0_253920_SneakNSnore), 2 end, 3 return.
   Player work[0]: 1 won, 2 caught, 4 being eaten. Player work[1]: lane. */

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/data.h"
#include "game/collision.h"

/* ---- structs ---- */

/* One link of the Chomp's chain, allocated 0x28 bytes (func_80103B98_24F208_SneakNSnore). No pointers. */
typedef struct SSLink {
    /* 0x00 */ Vec pos;
    /* 0x0C */ Vec prev; /* where it was the last time the head moved 80 units */
    /* 0x18 */ Vec rot;
    /* 0x24 */ f32 reach; /* furthest distance from the post */
} SSLink; /* size = 0x28 */

/* MgWork.unk_E8 entries (C8E0.c's MgMotion). */
typedef struct SSMotion {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x08 */ s32 unk_08;
} SSMotion; /* size = 0xC */

/* main's texture-animation slot (TexAnimSlot in ovl_5B.h). */
typedef struct SSTexAnim {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ char unk_08[2];
    /* 0x0A */ u8 unk_0A;
    /* 0x0B */ u8 unk_0B;
} SSTexAnim; /* size = 0xC */
extern SSTexAnim* D_800FD7F8_FE3F8;

/* Per-character data, 0x18 bytes each. */
typedef struct SSCharData {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s32 unk_04; /* model/motion directory */
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10; /* model file */
    /* 0x14 */ char unk_14[4];
} SSCharData;
extern SSCharData D_800CD438_CE038[];
extern f32 D_800BF7A0_C03A0;

/* ---- main-segment API (missing from include/) ---- */

extern s8 ContStkX[4];
extern s8 ContStkY[4];
extern u16 D_800BF7E4_C03E4[][14]; /* per player sound ids */
extern u16 D_800CD526_CE126;
extern s32 D_800F8FD0_F9BD0; /* scene state */
extern u16 D_800FA606_FB206;
extern u16 D_801011FC_101DFC;
extern u8 D_80102720_103320;
extern f32 D_80102750_103350[]; /* D_8010274C_10334C + 4: [1] is its z by retail's own label */
void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
f32 HuMathSin(f32);
u16 LoadFormFile(s32, s32);
s32 PlaySound(s32);
void func_80007790_8390(omObjData* obj); /* player object update (MP1 func_80005A28) */
void func_8000BEF8_CAF8(omObjData*, s32, f32);
void func_8000BF24_CB24(omObjData* obj, f32 arg1, f32 x0, f32 z0, f32 x1, f32 z1); /* hit box */
void func_8000BFF0_CBF0(omObjData*);
void func_8000C018_CC18(u16);
void func_8000C024_CC24(omObjData* obj, u8 idx, u8 val);
void func_8000C38C_CF8C(void);
void func_8000C398_CF98(void);
void func_8000C3A8_CFA8(void);
void func_8000C3B8_CFB8(void);
void func_8000C3C8_CFC8(void);
void func_8000C460_D060(void);
void func_8000C578_D178(s32);
void func_8000C690_D290(void);
void func_8000C6FC_D2FC(omObjData* obj, u32 dir, s32 file, u16 player, s32 arg4, s32 arg5); /* player object setup */
u16 func_80018A30_19630(s32 arg0, s32 arg1); /* model from a file */
void func_80018CCC_198CC(omObjData* obj, u16 slot, s32 file); /* util.c: (UnkUtil*, ...) loads obj->motion[slot] */
s32 func_80019000_19C00(omObjData* obj);
s32 func_80019B9C_1A79C(omObjData* obj, u16 motion); /* player motion */
void func_80019E04_1AA04(omObjData* obj, s32 idx, u16 motion);
void func_80019F0C_1AB0C(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4); /* motion */
void func_80020D20_21920(s16 arg0);
s16 func_80025384_25F84(s16 arg0, s16 arg1, s16 arg2, s32 arg3);
s32 func_80025684_26284(s32 id); /* 26284.c: s16; retail callers re-extend the result */
void func_80026DAC_279AC(s16, u8, u8, u8);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void* func_80027154_27D54(s32 size, s16 tag); /* HuMemAllocTag */
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_800298A4_2A4A4(s16, s32, s32); /* model attribute */
void func_80029A8C_2A68C(s16);
void func_80029BF0_2A7F0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void func_80029C74_2A874(s16, f32); /* motion frame */
f32 func_80029CE4_2A8E4(s16);
f32 func_80029D0C_2A90C(s16);
s32 func_80029E14_2AA14(s16 arg0); /* 2AA14.c: u8; retail callers re-extend the result */
void func_80029FE4_2ABE4(s16, f32);
void func_8002A00C_2AC0C(s16 model);
void func_8002AC10_2B810(s16, f32, f32, s32);
void func_8002C628_2D228(s16 arg0, s16 arg1, char* arg2); /* attach to a model's hook node */
void func_8002CA48_2D648(u8 arg0, u8 arg1, u8 arg2);
void func_8002D1EC_2DDEC(s16, u8);
void func_8002D274_2DE74(s16 arg0, u8 arg1, u8 arg2, u8 arg3); /* model light colour (2DE74.c: s8; retail passes 255) */
void func_8002D2B4_2DEB4(s16 arg0, f32 arg1, f32 arg2, f32 arg3); /* model light direction */
void func_8002D4D0_2E0D0(s16 n);
void func_8002F290_2FE90(s32* arg0, s32 n);
s16 func_8003DBE8_3E7E8(HmfData* arg0, u16 arg1, s16 arg2, char* arg3); /* sprite copy (3D6A0.c) */
void func_8003E4F4_3F0F4(s16 arg0, u8 arg1, u8 arg2);
void func_8003E888_3F488(s16);
void func_8003EE44_3FA44(HmfData* arg0);
void func_8003EEA4_3FAA4(HmfData* arg0);
s16 func_800691FC_69DFC(s16 mesNo, ...); /* MP1 GMesCreate */
s32 func_80069538_6A138(void);          /* MP1 GMesStatAllGet */
void func_8006961C_6A21C(s16 mesId, f32 x, f32 y);
void func_8006D4D0_6E0D0(s16 seconds); /* timer display */
void func_8006D518_6E118(void);
omObjData* func_800732B0_73EB0(u32 arg0);
u16 func_80078EA8_79AA8(void);
s16 func_80079428_7A028(s16 id);
s16 func_80079798_7A398(s16 sfx, s16 player);
s16 func_800797DC_7A3DC(s32 id, s16 player);
void func_80079868_7A468(void);
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size); /* memset */
f32 func_800B1830_B2430(f32); /* sqrtf */
void func_800B2060_B2C60(f32* m, f32 x, f32 y, f32 z); /* rotate matrix */
f32 func_800B75A8_B81A8(f32 y, f32 x); /* atan2, degrees */
f32 func_800B7890_B8490(f32); /* cos */
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);

/* ---- functions ---- */

/* 24DE70.c */
void func_80102800_24DE70_SneakNSnore(void);
void func_80102940_24DFB0_SneakNSnore(void);
void func_80102A54_24E0C4_SneakNSnore(void);
s16 func_80103994_24F004_SneakNSnore(s16 mdl, s32 file);
void func_80103AC8_24F138_SneakNSnore(s16 mdl, s16 frame);
void func_80103B98_24F208_SneakNSnore(omObjData* obj);
void func_80104218_24F888_SneakNSnore(omObjData* obj);
s8 func_80105574_250BE4_SneakNSnore(void);
void func_801055AC_250C1C_SneakNSnore(omObjData* obj);
f32 func_80105D78_2513E8_SneakNSnore(f32 a);
f32 func_80105E18_251488_SneakNSnore(f32 a, f32 target, f32 step);
void func_80105F58_2515C8_SneakNSnore(Vec* out, Vec* from, Vec* to);
/* 251680.c */
void func_80106010_251680_SneakNSnore(void);
void func_801060F0_251760_SneakNSnore(omObjData* obj);
void func_80106418_251A88_SneakNSnore(omObjData* obj);
void func_80106570_251BE0_SneakNSnore(omObjData* obj);
void func_80106628_251C98_SneakNSnore(omObjData* obj);
void func_80106868_251ED8_SneakNSnore(omObjData* obj);
/* 252450.c */
void func_80106DE0_252450_SneakNSnore(void);
void func_80106EA4_252514_SneakNSnore(omObjData* obj);
void func_801072E8_252958_SneakNSnore(omObjData* obj);
void func_8010807C_2536EC_SneakNSnore(omObjData* obj);

/* ---- .data (asm, 253920.data.s) ---- */

extern s32 D_801082B0_253920_SneakNSnore; /* time limit, seconds: 61 */
extern s8 D_801082B4_253924_SneakNSnore;  /* 1 while the Chomp is awake */
extern s32 D_801082B8_253928_SneakNSnore; /* frames of state 0 */
extern s32 D_801082BC_25392C_SneakNSnore; /* frames of state 2 */
extern s32 D_801082C0_253930_SneakNSnore; /* frames of state 1 */
extern s32 D_801082C4_253934_SneakNSnore; /* seconds left; retail reads the low half by D_801082C6_253936_SneakNSnore */
extern s32 D_801082C8_253938_SneakNSnore; /* winner animation frames */
extern s32 D_801082CC_25393C_SneakNSnore; /* frames to the fade */
extern s8 D_801082D0_253940_SneakNSnore;  /* camera on the winner: 1 moving, 2 there */
extern s8 D_801082D1_253941_SneakNSnore;  /* result: 1 time up / all caught, 2 winner, 3 1P failed */
extern s8 D_801082D2_253942_SneakNSnore;  /* the winner, -1 none */
extern s8 D_801082D3_253943_SneakNSnore;  /* result shown */
extern s8 D_801082D4_253944_SneakNSnore;  /* message state */
extern s8 D_801082D5_253945_SneakNSnore;  /* START skip state */
extern s32 D_801082D8_253948_SneakNSnore; /* frames until the Chomp wakes */
extern s8 D_801082DC_25394C_SneakNSnore;  /* chase target taken */
extern s8 D_801082DD_25394D_SneakNSnore;  /* awake */
extern s8 D_801082E0_253950_SneakNSnore[4]; /* player caught by the Chomp's eye, -1 none */
extern f32 D_801082E4_253954_SneakNSnore;   /* head travel since the links last moved */
extern s8 D_801082F0_253960_SneakNSnore[4]; /* per lane: 1 countdown over, 2 end reached */
extern f32 D_801082F4_253964_SneakNSnore;   /* lane bar height, 0.3 */
extern f32 D_801082F8_253968_SneakNSnore[4]; /* gate heights, 200 */
extern f32 D_80108308_253978_SneakNSnore[4]; /* gate scale */
extern f32 D_80108318_253988_SneakNSnore[4]; /* gate scale */
extern u32 D_80108328_253998_SneakNSnore;    /* frames of state 0 */
extern u32 D_8010832C_25399C_SneakNSnore;    /* frames with a winner */
extern s8 D_80108330_2539A0_SneakNSnore[16]; /* per gate: 0 shut, 1 opening, 2 open */
extern s16 D_80108340_2539B0_SneakNSnore;    /* players created */
extern s32 D_80108344_2539B4_SneakNSnore[4]; /* the port of each player; retail reads the low half by D_80108346_2539B6_SneakNSnore */
extern Vec D_80108354_2539C4_SneakNSnore[4]; /* lane starts; labels D_80108358_2539C8_SneakNSnore, D_8010835C_2539CC_SneakNSnore are its y, z */
extern u8 D_80108384_2539F4_SneakNSnore[4][4]; /* lane of each player per D_801084A8_253B18_SneakNSnore */
extern s8 D_80108394_253A04_SneakNSnore[4];    /* per player: 1 moved at all */
extern s16 D_80108398_253A08_SneakNSnore[4];   /* per port: stick held, frames */
extern s8 D_801083A0_253A10_SneakNSnore[4];
extern s8 D_801083A4_253A14_SneakNSnore[4]; /* frozen by the waking Chomp */
extern u8 D_801083A8_253A18_SneakNSnore[4]; /* per port: last stick y */
extern s8 D_801083AC_253A1C_SneakNSnore[4]; /* per port: direction */
extern f32 D_801083B0_253A20_SneakNSnore[4]; /* shrink when eaten */
extern s8 D_801083C0_253A30_SneakNSnore[4];
extern s8 D_801083C4_253A34_SneakNSnore[4];
extern s8 D_801083C8_253A38_SneakNSnore[4];
extern u8 D_801083CC_253A3C_SneakNSnore[4]; /* per port: CPU's random roll */

/* ---- .rodata ---- */

extern const char D_801083D0_253A40_SneakNSnore[16]; /* "c165n_4_DEF", in 24DE70.c */

/* ---- .bss (asm, ovl_32_bss.bss.s) ---- */

extern f32 D_80108410_253A80_SneakNSnore;
extern f32 D_80108414_253A84_SneakNSnore;
extern f32 D_80108418_253A88_SneakNSnore; /* bubble angle 0..180 */
extern f32 D_8010841C_253A8C_SneakNSnore; /* bubble size 1..5 */
extern s32 D_80108420_253A90_SneakNSnore; /* frames asleep */
extern s32 D_80108424_253A94_SneakNSnore; /* frames awake */
extern s32 D_80108428_253A98_SneakNSnore;
extern Vec D_8010842C_253A9C_SneakNSnore; /* the Chomp's target */
extern s8 D_80108438_253AA8_SneakNSnore;  /* player it chases */
extern u8 D_80108439_253AA9_SneakNSnore;  /* breath speed 0..2 */
extern u8 D_8010843A_253AAA_SneakNSnore;
extern u8 D_8010843B_253AAB_SneakNSnore;
/* D_8010843C_253AAC_SneakNSnore is D_80108440_253AB0_SneakNSnore[-1] (retail's label for D_80108440_253AB0_SneakNSnore[i - 1]). */
extern SSLink* D_80108440_253AB0_SneakNSnore[10];
extern u8 D_80108468_253AD8_SneakNSnore; /* eye texture: animation slot, 0xFF none */
extern u8 D_80108469_253AD9_SneakNSnore; /* eye texture: loaded id (bss label inside the D_80108468_253AD8_SneakNSnore pair) */
extern s16 D_8010846A_253ADA_SneakNSnore;   /* eye files */
extern s16 D_8010846C_253ADC_SneakNSnore;
extern f32 D_80108470_253AE0_SneakNSnore;
extern f32 D_80108478_253AE8_SneakNSnore[4]; /* per player: motion frame when frozen */
/* Per player: x and z when frozen, label D_8010848C_253AFC_SneakNSnore is its [0][1]. The stride is 0x10 but the bss
   holds 0x20 bytes: retail's players 2 and 3 run into D_801084A8_253B18_SneakNSnore and D_801084B0_253B20_SneakNSnore[2]. */
extern f32 D_80108488_253AF8_SneakNSnore[][4];
extern s32 D_801084A8_253B18_SneakNSnore; /* 0..3, which of the D_80108384_2539F4_SneakNSnore rows */
extern omObjData* D_801084B0_253B20_SneakNSnore[4]; /* [0] the Chomp */

#endif
