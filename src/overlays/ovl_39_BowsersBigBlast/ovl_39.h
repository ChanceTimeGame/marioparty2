#ifndef _OVL_39_H
#define _OVL_39_H

/* Overlay 39: Bowser's Big Blast (4P). Five detonators under a giant Bowser; players take turns
   in a shuffled order walking along them and pushing one down. One of the five is live each
   round: Bowser's fuse burns and the presser is blown off; three blasts end the game and the
   survivor wins. Retail is one file, 27F4F0.c; .data (0x2847C0) is asm, .rodata is carved from
   0x284840. */

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/data.h"
#include "game/collision.h"

/* ---- main-segment API used by 39 (missing from include/) ---- */

/* Per-character data, 0x18 bytes each. */
typedef struct BBCharData {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s32 unk_04; /* model/motion directory */
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10; /* model file */
    /* 0x14 */ char unk_14[4];
} BBCharData;
extern BBCharData D_800CD438_CE038[];

extern u16 D_800BF7E4_C03E4[][14]; /* per player sound ids */
extern f32 D_800BF79C_C039C;
extern f32 D_800BF7A4_C03A4;
extern f32 D_800BF7A8_C03A8;
extern f32 D_800BF7C8_C03C8;
extern f32 D_800BF7D4_C03D4;
extern f32 D_800BF7DC_C03DC;
extern s32 D_800F8FD0_F9BD0; /* scene state */
extern u16 D_800FA606_FB206;
extern u8 D_800FDBE0_FE7E0; /* current vertex buffer */
extern f32 D_8010105C_101C5C;
extern u16 D_801011FC_101DFC;
extern f32 D_80101300_101F00;
extern u8 D_80102720_103320;
extern s8 ContStkX[4];
extern s8 ContStkY[4];

void func_8002D4D0_2E0D0(s16 n);
void func_8002F290_2FE90(s32* arg0, s32 n);
void func_80020D20_21920(s16 arg0);
void func_8000C38C_CF8C(void);
void func_8000C398_CF98(void);
void func_8000C3A8_CFA8(void);
void func_8000C3B8_CFB8(void);
void func_8000C3C8_CFC8(void);
void func_8000C460_D060(void);
void func_8000C56C_D16C(s32);
void func_8000C578_D178(s32);
void func_8000C018_CC18(u16);
void func_80026DAC_279AC(s16, u8, u8, u8);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_80079E60_7AA60(void);
u16 func_80078EA8_79AA8(void);
u8 rand8(void);
s32 PlaySound(s32);
s16 func_80079574_7A174(void); /* music tempo */
void func_8007954C_7A14C(s16);
void func_800795D8_7A1D8(s16 sound, s8 volume);
void func_800796F0_7A2F0(s16 sound, s16 pitch);
void func_80079614_7A214(s16 time); /* music fade-out */
s16 func_800797DC_7A3DC(s32 id, s16 player);
void func_80079848_7A448(s16 arg0); /* stop a sound */
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
s16 func_800691FC_69DFC(s16 mesNo, ...); /* MP1 GMesCreate */
s32 func_80069538_6A138(void);          /* MP1 GMesStatAllGet */
omObjData* func_800732B0_73EB0(u32 arg0);
f32 func_800B1830_B2430(f32); /* sqrtf */
f64 fabs(f64); /* GCC builtin (abs.d) */
f32 func_800B75A8_B81A8(f32 y, f32 x); /* atan2, degrees */
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* cos */
f32 func_8002D958_2E558(f32); /* wraps an angle */
void* func_80027154_27D54(s32 size, s16 tag); /* HuMemAllocTag */
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size); /* memset */
u16 func_80018A30_19630(s32 arg0, s32 arg1); /* model from a file */
s16 func_80027D3C_2893C(s16 linkMdlId); /* model copy */
u16 LoadFormFile(s32, s32);
void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void func_8002979C_2A39C(s16 idx, f32 x, f32 y, f32 z); /* model rotation */
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_800298A4_2A4A4(s16, s32, s32); /* model attribute */
void func_80029A8C_2A68C(s16);
void func_80029AFC_2A6FC(s16);
void func_80029C74_2A874(s16, f32); /* motion frame */
f32 func_80029CE4_2A8E4(s16);
f32 func_80029D0C_2A90C(s16);
void func_8002A00C_2AC0C(s16 model);
void func_8002BED4_2CAD4(s16 model, f32 s, f32 t, u16 w, u16 h, char* part, u8 arg6); /* texture scroll */
void func_8002C20C_2CE0C(s16 arg0, char* arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5); /* part colour */
void func_8002D1EC_2DDEC(s16, u8);
void func_8002D274_2DE74(s16 arg0, u8 arg1, u8 arg2, u8 arg3); /* model light colour (2DE74.c: s8; retail passes 255) */
void func_8002D2B4_2DEB4(s16 arg0, f32 arg1, f32 arg2, f32 arg3); /* model light direction */
void func_8002D3C0_2DFC0(s16 arg0);
void func_8003EAF0_3F6F0(char* arg0, void* arg1); /* the size of the texture named arg0 */
u16 func_80020EBC_21ABC(void* arg0, s32 arg1, u8 arg2); /* 3D sprite (MP1 func_8001E00C) */
u16 func_8002109C_21C9C(s16 index, s32 arg1);
void func_80021160_21D60(s16 index, s32 arg1, s32 arg2);
/* GroundWork setters (C8E0.c) */
void func_8000BE8C_CA8C(omObjData*, f32);
void func_8000BE98_CA98(omObjData*, f32);    /* unk_0C */
void func_8000BEA4_CAA4(omObjData*, f32);
void func_8000BEF8_CAF8(omObjData*, s32, f32);
void func_8000BFA8_CBA8(omObjData*, f32 top, f32 depth, f32 radius); /* cylinder: unk_14, unk_98, unk_9C */
void func_8000BFF0_CBF0(omObjData*);
void func_8000C37C_CF7C(omObjData* obj, f32 x, f32 y, f32 z); /* obj->scale */
void func_8000D2F8_DEF8(omObjData*);
/* players */
void func_8000C6FC_D2FC(omObjData* obj, u32 dir, s32 file, u16 player, s32 arg4, s32 arg5); /* player object setup */
void func_8000BDC4_C9C4(omObjData* obj, u16 idx, s32 dir, s32 file, f32 arg4);
void func_8000CC74_D874(omObjData* obj, s16 model, s16 motion);
void func_8000C024_CC24(omObjData* obj, u8 idx, u8 val);
void func_8000E0C0_ECC0(MgWork* w, s32 slot, void* hook); /* w->unk_104[slot] = hook (slot < 21) */
s32 func_80019000_19C00(omObjData* obj);
s32 func_80019B9C_1A79C(omObjData* obj, u16 motion); /* player motion */
s32 func_80019CA4_1A8A4(omObjData* obj, u16 motion);
void func_80019F0C_1AB0C(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4); /* motion */
void func_8000BEB0_CAB0(omObjData*, f32);
void func_8000BF24_CB24(omObjData* obj, f32 arg1, f32 x0, f32 z0, f32 x1, f32 z1); /* hit box */
void func_800115B4_121B4(s32);
void func_800116B4_122B4(s32, s32);
u16 func_80018D64_19964(s32 arg0, s32 arg1, s32 arg2); /* a sprite-model slot (D_800F86D8) from a file */
void func_80018F58_19B58(s32);
void func_80019E84_1AA84(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4);
s16 func_8001A2F8_1AEF8(s32 arg0);
void func_80021198_21D98(s16 index, u16 arg1);
void func_8002AC10_2B810(s16, f32, f32, s32);
void func_8002D0A0_2DCA0(s16, u8); /* model alpha */
void func_8002D124_2DD24(s16 index);
s32 func_80059FD0_5ABD0(s32); /* the player's rank */
void func_8006D4D0_6E0D0(s16); /* the seconds counter */
void func_8006D518_6E118(void);
void func_8007273C_7333C(char* arg0, u8 arg1);
s16 func_80079428_7A028(s32);
void func_800794F0_7A0F0(s8);
void func_8008221C_82E1C(s16 group, s16 member, f32 arg2);
s32 func_800824B4_830B4(s16, s32, s32, s32, s32, s32);
void func_80079FF4_7ABF4(omObjData* object);
void func_80079718_7A318(s16, s16);
extern f32 D_800CA02C_CAC2C;
extern f32 D_800F94A8_FA0A8[];    /* CZoomM */
extern Vec3f D_801013B0_101FB0[]; /* CenterM */
extern Vec3f D_801013B4_101FB4[]; /* = &CenterM[0].y */
extern Vec3f D_80102770_103370[]; /* CRotM */
extern Vec3f D_80102774_103374[]; /* = &CRotM[0].y */
void func_8000BF54_CB54(omObjData*, f32, f32, f32, f32, f32, f32); /* box */
void SprAttrSet(s16 grpIdx, s16 idx, s32 flag);
void SprAttrReset(s16 grpIdx, s16 idx, s32 flag);
s16 SprCreate(s32 num, s32 attr);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprBankSet(s16 group, s16 member, s16 bank);
void SprPos3DSet(s16 grpIdx, s16 idx, s16 camIdx, f32 x, f32 y, f32 z);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
void SprScaleSet(s16 group, s16 member, f32 x, f32 y);
void SprPosSet(s16 grpIdx, s16 idx, s16 x, s16 y);
u16 func_800211C0_21DC0(s16 index);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
void func_80007790_8390(omObjData* obj);
void func_80019378_19F78(omObjData* obj);

/* ---- types ---- */

#define BB_MODEL(i) (&D_800FC834_FD434[i])

/* Shared game state (0x10, allocated), D_80107D20. */
typedef struct BBState {
    /* 0x0 */ f32 timer;  /* turn timer in frames, -1 off */
    /* 0x4 */ u8 flow;    /* 80106EC4's state */
    /* 0x5 */ u8 music;   /* 80106D64's state */
    /* 0x6 */ u8 camera;  /* 801074A8's state */
    /* 0x7 */ u8 bowser;  /* 80103214's state */
    /* 0x8 */ u8 press;   /* 80104078's state */
    /* 0x9 */ u8 fade;    /* 80104A5C: a lid fades out */
    /* 0xA */ u8 hatch;   /* 80103BCC's state */
    /* 0xB */ u8 control; /* 80106400's state */
    /* 0xC */ u8 shake;   /* camera shake on */
} BBState;

/* Per-player game state (0xC, four allocated), D_80107D48. */
typedef struct BBPlayer {
    /* 0x0 */ u8 state;
    /* 0x1 */ u8 order;  /* place in the queue */
    /* 0x2 */ u8 slot;   /* detonator 0-4 */
    /* 0x3 */ char pad3;
    /* 0x4 */ f32 angle;
    /* 0x8 */ u8 hit;
    /* 0x9 */ u8 pressed;
    /* 0xA */ char padA[2];
} BBPlayer;

/* An effect sprite (4 bytes, two allocated), D_80107D2C. */
typedef struct BBFlash {
    /* 0x0 */ u8 group;
    /* 0x1 */ u8 anim;
    /* 0x2 */ u8 active;
    /* 0x3 */ s8 timer;
} BBFlash;

/* A camera key (0x20; two pairs of from/to allocated, 0x60 bytes), D_80107D24. */
typedef struct BBCamKey {
    /* 0x00 */ f32 time;
    /* 0x04 */ f32 zoom;
    /* 0x08 */ f32 cx, cy, cz;
    /* 0x14 */ f32 rx, ry, rz;
} BBCamKey;

/* ---- .data (0x2847C0, asm) ---- */

extern u8 D_80107AD0_2847C0_BowsersBigBlast;  /* the first turn's "go" message shown */
extern u8 D_80107AD1_2847C1_BowsersBigBlast;  /* next ground id */
extern f32 D_80107AD4_2847C4_BowsersBigBlast[5]; /* detonator x */
extern u8 D_80107AE8_2847D8_BowsersBigBlast;  /* leftmost live detonator */
extern u8 D_80107AE9_2847D9_BowsersBigBlast;  /* rightmost live detonator */
extern u8 D_80107AEA_2847DA_BowsersBigBlast;  /* lid to fade */
extern f32 D_80107AEC_2847DC_BowsersBigBlast[4]; /* queue x */
extern u8 D_80107AFC_2847EC_BowsersBigBlast;
extern f32 D_80107B00_2847F0_BowsersBigBlast[3];
extern u8 D_80107B0C_2847FC_BowsersBigBlast;
extern u8 D_80107B0D_2847FD_BowsersBigBlast; /* undefined_syms.txt */
extern f32 D_80107B10_284800_BowsersBigBlast;
extern f32 D_80107B14_284804_BowsersBigBlast;
extern u8 D_80107B18_284808_BowsersBigBlast;
extern u8 D_80107B19_284809_BowsersBigBlast;
extern u8 D_80107B1A_28480A_BowsersBigBlast;
extern u8 D_80107B1B_28480B_BowsersBigBlast;
extern u8 D_80107B1C_28480C_BowsersBigBlast;
extern u8 D_80107B1D_28480D_BowsersBigBlast;
extern u8 D_80107B1E_28480E_BowsersBigBlast;
extern u8 D_80107B1F_28480F_BowsersBigBlast;
extern u8 D_80107B20_284810_BowsersBigBlast;
extern u8 D_80107B24_284814_BowsersBigBlast[4]; /* CPU's chosen detonator */
extern u8 D_80107B28_284818_BowsersBigBlast;
extern u8 D_80107B29_284819_BowsersBigBlast;
extern u8 D_80107B2A_28481A_BowsersBigBlast;
extern u8 D_80107B2B_28481B_BowsersBigBlast;
extern s32 D_80107B2C_28481C_BowsersBigBlast;
extern u8 D_80107B30_284820_BowsersBigBlast;
extern u8 D_80107B31_284821_BowsersBigBlast;
extern u8 D_80107B32_284822_BowsersBigBlast;
extern s8 D_80107B34_284824_BowsersBigBlast[12];
extern f32 D_80107B40_284830_BowsersBigBlast;
extern f32 D_80107B44_284834_BowsersBigBlast;

/* ---- .bss ---- */

extern BBState* D_80107D20_284A10_BowsersBigBlast;
extern BBCamKey* D_80107D24_284A14_BowsersBigBlast;
extern omObjData* D_80107D28_284A18_BowsersBigBlast;
extern BBFlash* D_80107D2C_284A1C_BowsersBigBlast;
extern u16 D_80107D30_284A20_BowsersBigBlast[5]; /* the five 3D sprites */
extern u8 D_80107D3A_284A2A_BowsersBigBlast;  /* the live detonator */
extern u8 D_80107D3B_284A2B_BowsersBigBlast[4]; /* detonator still up; [4] is D_80107D3F */
extern u8 D_80107D3F_284A2F_BowsersBigBlast;
extern u8 D_80107D40_284A30_BowsersBigBlast;  /* detonators up */
extern u8 D_80107D41_284A31_BowsersBigBlast;  /* detonator being pressed */
extern u8 D_80107D42_284A32_BowsersBigBlast;  /* presser's character */
extern u8 D_80107D43_284A33_BowsersBigBlast[4]; /* each player's queue place */
extern BBPlayer* D_80107D48_284A38_BowsersBigBlast;
extern u8 D_80107D4C_284A3C_BowsersBigBlast;
extern f32 D_80107D50_284A40_BowsersBigBlast[5]; /* a blown-up player's flight: t, x, y, z, rot.x */
extern u8 D_80107D64_284A54_BowsersBigBlast;  /* players blown up */
extern u8 D_80107D65_284A55_BowsersBigBlast;  /* winner */
extern u8 D_80107D66_284A56_BowsersBigBlast;
extern u8 D_80107D67_284A57_BowsersBigBlast;
extern u8 D_80107D68_284A58_BowsersBigBlast;  /* added to the CPU's chance of the right pick */
extern u8 D_80107D69_284A59_BowsersBigBlast;  /* presser, vibrated */
extern u8 D_80107D6A_284A5A_BowsersBigBlast;  /* next coins_mg_bonus */
extern u8 D_80107D6B_284A5B_BowsersBigBlast[3]; /* blast models */

/* ---- functions ---- */

void func_80102800_27F4F0_BowsersBigBlast(void);
void func_8010281C_27F50C_BowsersBigBlast(void);
void func_80102824_27F514_BowsersBigBlast(omObjData* obj, s32 file, f32 x, f32 y, f32 z, s32 attr, u8 load);
void func_8010290C_27F5FC_BowsersBigBlast(omObjData* obj);
void func_80102974_27F664_BowsersBigBlast(omObjData* obj);
void func_80102AA8_27F798_BowsersBigBlast(omObjData* obj);
void func_80102B74_27F864_BowsersBigBlast(void);
void func_80102C94_27F984_BowsersBigBlast(void);
void func_80102D50_27FA40_BowsersBigBlast(void);
void func_80102E10_27FB00_BowsersBigBlast(f32 x, f32 y, f32 z, u8 size);
void func_80102F34_27FC24_BowsersBigBlast(void);
void func_80103060_27FD50_BowsersBigBlast(void);
void func_8010319C_27FE8C_BowsersBigBlast(void);
void func_80103214_27FF04_BowsersBigBlast(omObjData* obj);
void func_80103A54_280744_BowsersBigBlast(omObjData* obj);
void func_80103B84_280874_BowsersBigBlast(void);
void func_80103BCC_2808BC_BowsersBigBlast(omObjData* obj);
void func_80103F9C_280C8C_BowsersBigBlast(omObjData* obj);
void func_80104044_280D34_BowsersBigBlast(void);
void func_80104078_280D68_BowsersBigBlast(omObjData* obj);
void func_801048C4_2815B4_BowsersBigBlast(omObjData* obj);
void func_80104A5C_28174C_BowsersBigBlast(omObjData* obj);
void func_80104B28_281818_BowsersBigBlast(omObjData* obj);
void func_80104D10_281A00_BowsersBigBlast(void);
void func_80104D64_281A54_BowsersBigBlast(omObjData* obj);
void func_80104E98_281B88_BowsersBigBlast(omObjData* obj, BBPlayer* pl, u8 port);
void func_80104F04_281BF4_BowsersBigBlast(u8 port);
void func_80104F40_281C30_BowsersBigBlast(void);
u8 func_80104FE4_281CD4_BowsersBigBlast(BBPlayer* pl, s32 step);
void func_8010500C_281CFC_BowsersBigBlast(omObjData* obj, BBPlayer* pl, u8 port, f32 z);
void func_80105248_281F38_BowsersBigBlast(omObjData* obj);
void func_801053E0_2820D0_BowsersBigBlast(omObjData* obj);
void func_80105470_282160_BowsersBigBlast(omObjData* obj);
s32 func_801054A0_282190_BowsersBigBlast(omObjData* obj);
void func_801056A8_282398_BowsersBigBlast(omObjData* obj, BBPlayer* pl);
void func_80105C50_282940_BowsersBigBlast(omObjData* obj, u8 order, u8 port);
void func_80106400_2830F0_BowsersBigBlast(omObjData* obj);
void func_801065CC_2832BC_BowsersBigBlast(omObjData* obj);
void func_801069C8_2836B8_BowsersBigBlast(void);
void func_80106A50_283740_BowsersBigBlast(void);
void func_80106D64_283A54_BowsersBigBlast(void);
void func_80106EC4_283BB4_BowsersBigBlast(void);
void func_80107104_283DF4_BowsersBigBlast(void);
void func_801071B0_283EA0_BowsersBigBlast(omObjData* obj);
void func_8010721C_283F0C_BowsersBigBlast(omObjData* obj);
void func_80107240_283F30_BowsersBigBlast(omObjData* obj);
void func_80107278_283F68_BowsersBigBlast(omObjData* obj);
void func_801072C0_283FB0_BowsersBigBlast(void);
void func_801073E4_2840D4_BowsersBigBlast(BBCamKey* key, f32 t);
void func_801074A8_284198_BowsersBigBlast(void);
void func_80107840_284530_BowsersBigBlast(void);
u8 func_80107A08_2846F8_BowsersBigBlast(f32* out, u8* timer, f32 start, f32 end, f32 duration);
f32 func_80107A80_284770_BowsersBigBlast(f32 t, f32 p0, f32 p1, f32 p2);

#endif
