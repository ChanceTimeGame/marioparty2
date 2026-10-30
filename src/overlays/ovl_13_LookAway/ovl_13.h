#ifndef _OVL_13_H
#define _OVL_13_H

/* Overlay 13: Look Away (1 vs 3). One player (slot 0, D_80106CD0_16BA70_LookAway[0]) holds the
   camera and points it in one of five directions; the other three turn their heads each round and
   are caught when they look the same way. Five rounds (D_801069A6_16B746_LookAway); the camera
   player wins with three catches (D_801069AA_16B74A_LookAway >= 3, flag 0x40), else the three win
   (flag 0x80). The winners get coins_mg_bonus = 10.
   Retail is two files: 1675A0.c (80102800-80106638) and 16B3E0.c from 80106640 (a 1-pad file
   holding the two table clears). .data is one asm blob (1675A0.c's); .rodata is carved from
   0x16B560. N64 offsets are in the comments; the structs with pointer fields change size on the
   host. */

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/data.h"
#include "game/collision.h"
#include "game/malloc.h"

/* One entry of D_80106CD0_16BA70_LookAway[50] (cleared by func_80106640_16B3E0_LookAway). Entries
   0-3 are the players by slot (0 = the camera player), 4 the stage, 5 the photo strip draw, 6 the
   countdown, 7 the round markers, 8 the lights. */
typedef struct LAObj {
    /* 0x00 */ omObjData* obj;
    /* 0x04 */ s16 spr;       /* sprite group */
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ u16 state;     /* player: func_801046E4 state; stage: pulse direction */
    /* 0x22 */ u16 unk_22;    /* sway direction / phase */
    /* 0x24 */ u16 unk_24;
    /* 0x26 */ u16 unk_26;    /* CPU: frames until it changes direction */
    /* 0x28 */ u16 timer;
    /* 0x2A */ u16 unk_2A;
    /* 0x2C */ s16 com;       /* gPlayers[].flags & 1 */
    /* 0x2E */ u16 player;
    /* 0x30 */ s16 unk_30;
    /* 0x32 */ s16 unk_32;
    /* 0x34 */ s16 unk_34;
    /* 0x36 */ s16 unk_36;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
} LAObj; /* size = 0x48 (N64) */

/* One sprite of the round marker group (D_801069B0_16B750_LookAway[15]): 0-5 the camera player's
   five rounds + 1, 6-11 its spare digits, 12-14 the three others' "caught" marks. */
typedef struct LAMark {
    /* 0x00 */ u8 state;
    /* 0x01 */ u8 flags;      /* 1: caught */
    /* 0x02 */ u8 count;
    /* 0x03 */ char unk_03;
    /* 0x04 */ f32 scale;
    /* 0x08 */ f32 t;
} LAMark; /* size = 0xC */

/* A stage light (D_80106A68_16B808_LookAway[10]). */
typedef struct LALight {
    /* 0x00 */ s16 id;
    /* 0x02 */ u8 state;
    /* 0x03 */ char unk_03;
    /* 0x04 */ f32 alpha;
    /* 0x08 */ f32 scale;
} LALight; /* size = 0xC */

/* One axis of a head turn (LADir::axis). */
typedef struct LAAxis {
    /* 0x00 */ f32 vel;
    /* 0x04 */ f32 acc;
    /* 0x08 */ f32 jerk;
} LAAxis; /* size = 0xC */

/* A player's chosen direction (D_80106BE8_16B988_LookAway[4]). Directions: 0 none (front), 1 up,
   2 right, 3 down, 4 left (func_80103FEC_168D8C_LookAway). */
typedef struct LADir {
    /* 0x00 */ u8 dir;
    /* 0x01 */ u8 shown;   /* the direction it turned to */
    /* 0x02 */ u8 prev;
    /* 0x03 */ u8 done;    /* both axes reached their target */
    /* 0x04 */ LAAxis axis[2];
} LADir; /* size = 0x1C */

/* ---- .data (asm, 0x16B490-0x16B560) ---- */
extern f32 D_801066F0_16B490_LookAway[4][3];  /* player start positions by slot */
extern u16 D_80106720_16B4C0_LookAway[9][2];  /* marker sprite x, y */
extern s16 D_80106722_16B4C2_LookAway[];      /* = D_80106720[0][1] (its y column) */
extern s32 D_80106744_16B4E4_LookAway;        /* camera set up */
extern u16 D_80106748_16B4E8_LookAway[6];     /* player model file by character */
extern s16 D_80106754_16B4F4_LookAway[6];     /* player motion directory by character */
extern u16 D_80106760_16B500_LookAway[13];    /* common motion files (in D_80106754's directory) */
extern u16 D_8010677C_16B51C_LookAway[3 * 6];  /* per-character motions [3][6] (no splat label: undefined_syms) */
extern char* D_801067A0_16B540_LookAway[8];   /* "c00Nl_0_DEF" by character (6) */

/* ---- .bss ---- */
extern u16 D_801069A0_16B740_LookAway; /* game state */
extern u16 D_801069A2_16B742_LookAway; /* game state timer */
extern s16 D_801069A4_16B744_LookAway; /* 1P-flag result wait */
extern u16 D_801069A6_16B746_LookAway; /* rounds left (5) */
extern u16 D_801069A8_16B748_LookAway; /* rounds played */
extern u16 D_801069AA_16B74A_LookAway; /* players caught */
extern u16 D_801069AC_16B74C_LookAway; /* round countdown (150) */
extern u16 D_801069AE_16B74E_LookAway; /* flags: 1/2/4 countdown marks, 0x10 lights on, 0x20 lights
                                          off, 0x40 camera player won, 0x80 the three won, 0x100
                                          the shutter fired */
extern LAMark D_801069B0_16B750_LookAway[15];
extern LAMark D_80106A34_16B7D4_LookAway[];   /* = D_801069B0[11] (indexed by slot 1-3) */
extern u8 D_80106A35_16B7D5_LookAway[];       /* = D_80106A34[0].flags */
extern LAMark D_80106A40_16B7E0_LookAway[3];  /* = D_801069B0[12] */
extern HuSprite_Unk84_Struct* D_80106A64_16B804_LookAway; /* the photo strip's image */
extern LALight D_80106A68_16B808_LookAway[10];
extern void* D_80106AE0_16B880_LookAway[4][16]; /* motion data by slot */
extern s16 D_80106BE0_16B980_LookAway[4];       /* current motion by slot */
extern LADir D_80106BE8_16B988_LookAway[4];
extern u8 D_80106BE9_16B989_LookAway[];          /* = D_80106BE8[0].shown */
extern u8 D_80106BEB_16B98B_LookAway;            /* = D_80106BE8[0].done */
extern LADir D_80106C04_16B9A4_LookAway[3];      /* = D_80106BE8[1] */
extern s16 D_80106C68_16BA08_LookAway[50];       /* sprite animations */
extern s16 D_80106C6A_16BA0A_LookAway;           /* = D_80106C68[1] */
extern LAObj D_80106CD0_16BA70_LookAway[50];
extern u16 D_80106CF0_16BA90_LookAway;           /* = D_80106CD0[0].state */
extern omObjData* D_80106DF0_16BB90_LookAway;    /* = D_80106CD0[4].obj */
extern s16 D_80106DF4_16BB94_LookAway;           /* = D_80106CD0[4].spr */
extern f32 D_80106E28_16BBC8_LookAway;           /* = D_80106CD0[4].unk_38 */
extern f32 D_80106E2C_16BBCC_LookAway;           /* = D_80106CD0[4].unk_3C */
extern omObjData* D_80106E38_16BBD8_LookAway;    /* = D_80106CD0[5].obj */
extern omObjData* D_80106E80_16BC20_LookAway;    /* = D_80106CD0[6].obj */
extern omObjData* D_80106EC8_16BC68_LookAway;    /* = D_80106CD0[7].obj */
extern s16 D_80106ECC_16BC6C_LookAway;           /* = D_80106CD0[7].spr */
extern omObjData* D_80106F10_16BCB0_LookAway;    /* = D_80106CD0[8].obj */

/* ---- main ---- */
extern s8 ContStkX[4];
extern s8 ContStkY[4];
extern f32 D_800F94A8_FA0A8[];    /* CZoomM */
extern Vec3f D_80102770_103370[]; /* CRotM */
extern Vec3f D_801013B0_101FB0[]; /* CenterM */
extern s16 D_800FA606_FB206;
extern u16 D_801011FC_101DFC;
s16 LoadFormFile(s32, s32);
s32 PlaySound(s32);
void* SprAnimGet(s16 animIdx);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprAttrReset(s16 grpIdx, s16 idx, s32 flag);
void SprAttrSet(s16 grpIdx, s16 idx, s32 flag);
void SprBankSet(s16 group, s16 member, s16 bank);
s16 SprCreate(s32 num, s32 attr);
void SprPosSet(s16, s16, s16, s16);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
void SprScaleSet(s16 group, s16 member, f32 x, f32 y);
void func_8000BE8C_CA8C(omObjData*, f32);
void func_8000BEA4_CAA4(omObjData*, f32);
void func_8000BF24_CB24(omObjData* obj, f32 arg1, f32 x0, f32 z0, f32 x1, f32 z1);
void func_8000C018_CC18(u16);
void func_80018F58_19B58(s32);
s16 func_8001A2F8_1AEF8(s32 arg0);
void func_80020D20_21920(s16 arg0);
u16 func_80020EBC_21ABC(void* arg0, s32 arg1, u8 arg2);
void func_80021160_21D60(s16 index, s32 arg1, s32 arg2);
void func_800211E8_21DE8(s16 index, u8 arg1);
void func_80021250_21E50(s16 index, u8 arg1, u8 arg2, u8 arg3);
void func_800212A4_21EA4(s16 index);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16, f32, f32, f32);
void* func_80027154_27D54(s32 size, s16 tag);
s16 func_8002838C_28F8C(s32 arg0, void (*arg1)(Gfx**), u8 arg2);
void func_80029714_2A314(s16, f32, f32, f32);
void func_800297E8_2A3E8(s16, f32, f32, f32);
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029A8C_2A68C(s16);
void func_80029AFC_2A6FC(s16);
void func_80029EDC_2AADC(s16 arg0, u8 arg1);
void func_8002D4D0_2E0D0(s16 n);
s16 func_8003DF08_3EB08(void*);
void func_8003E888_3F488(s16);
s16 func_800691FC_69DFC(s16 mesNo, ...);
s32 func_80069538_6A138(void);
void func_8007273C_7333C(u8* arg0, u8 arg1);
void func_80079518_7A118(s8 arg0);
void func_80079614_7A214(s16 time);
s16 func_800797DC_7A3DC(s32 sfx, s16 player);
void func_800798F8_7A4F8(s16 sound, s16 pan);
void func_80079FF4_7ABF4(omObjData* object);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size);
f64 func_800B80D0_B8CD0(f64); /* sin of degrees, in double */
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
void osViBlack(u8 active);

/* ---- overlay functions ---- */

/* 1675A0.c */
void func_80102800_1675A0_LookAway(void);
void func_8010281C_1675BC_LookAway(u8 player);
u8 func_801028A0_167640_LookAway(u8 n, u64* used);
void func_801029F0_167790_LookAway(void);
void func_80102AE0_167880_LookAway(omObjData* obj);
void func_80102CE8_167A88_LookAway(omObjData* obj);
void func_80102F90_167D30_LookAway(void);
void func_80102FD8_167D78_LookAway(Gfx** gfx);
void func_801032FC_16809C_LookAway(void);
void func_80103304_1680A4_LookAway(omObjData* obj);
void func_8010337C_16811C_LookAway(void);
void func_801033B8_168158_LookAway(omObjData* obj);
void func_801033F8_168198_LookAway(omObjData* obj);
void func_80103414_1681B4_LookAway(void);
void func_80103450_1681F0_LookAway(LAObj* o, s16 member, u16 anim, s32 x, s32 y);
void func_80103508_1682A8_LookAway(omObjData* obj);
void func_801037B0_168550_LookAway(omObjData* obj);
void func_80103A48_1687E8_LookAway(void);
void func_80103A98_168838_LookAway(omObjData* obj);
void func_80103D04_168AA4_LookAway(omObjData* obj);
void func_80103FB0_168D50_LookAway(void);
u8 func_80103FEC_168D8C_LookAway(s8 x, s8 y);
void func_80104060_168E00_LookAway(LADir* d, u8 axis, f32* val, f32 target);
void func_80104238_168FD8_LookAway(omObjData* obj, LADir* d);
void func_80104318_1690B8_LookAway(omObjData* obj);
u8 func_801043E0_169180_LookAway(omObjData* obj);
u8 func_801044E0_169280_LookAway(void);
void func_80104514_1692B4_LookAway(omObjData* obj, u8 motion);
u16 func_801045FC_16939C_LookAway(omObjData* obj);
void func_801046E4_169484_LookAway(omObjData* obj);
void func_8010580C_16A5AC_LookAway(omObjData* obj);
void func_80105B4C_16A8EC_LookAway(void);
void func_80105D3C_16AADC_LookAway(omObjData* obj);
void func_80105D64_16AB04_LookAway(omObjData* obj);
void func_80105DBC_16AB5C_LookAway(omObjData* obj);
void func_80105E30_16ABD0_LookAway(void);
void func_80105F28_16ACC8_LookAway(omObjData* obj);
void func_80105F4C_16ACEC_LookAway(omObjData* obj);
void func_80106008_16ADA8_LookAway(omObjData* obj);
void func_80106060_16AE00_LookAway(omObjData* obj);
void func_80106328_16B0C8_LookAway(omObjData* obj);
void func_8010640C_16B1AC_LookAway(void);

/* 16B3E0.c */
void func_80106640_16B3E0_LookAway(void);
void func_801066C4_16B464_LookAway(void);

#endif
