#ifndef _OVL_0A_H
#define _OVL_0A_H

/* Overlay 0A: Rakin' 'em In (4P free-for-all). Twenty items (vegetables) ride a turning table;
   each player has a rake at one corner (station D_80106CC0_125C00_RakinEmIn[player]) and swings
   it with A; items inside the rake's reach and angle are pulled towards the corner and fall into
   the player's basket, which scores the item's value (D_80106F0C_125E4C_RakinEmIn by kind:
   +1, -3, +3). 30 seconds (D_801070A2 = 901 frames in state 2) or until every item is gone.
   The object framework (RIObj[50], sprite animations s16[50]) is Look Away's (ovl_13).
   Retail is two files: 121740.c (80102800-80106C10) and 125B50.c from 80106C10 (the two table
   clears; 3-nop text pad). .rodata is carved from 0x125EE0 (121740.c only).
   N64 offsets are in the comments; structs with pointer fields change size on the host. */

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/data.h"
#include "game/collision.h"
#include "game/malloc.h"

/* One entry of D_80107250_126190_RakinEmIn[50] (cleared by func_80106C10_125B50_RakinEmIn).
   Entries 0-3 are the players, 4 the table, 5-8 the rakes (player + 5), 10-29 the items
   (item + 10), 30 the score HUD. */
typedef struct RIObj {
    /* 0x00 */ omObjData* obj;
    /* 0x04 */ s16 spr;       /* sprite group */
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s16 unk_20;    /* item: model's texture slot (func_8003D8F0) */
    /* 0x22 */ u16 unk_22;    /* item: texture frame (angle / 3.75) */
    /* 0x24 */ u16 unk_24;    /* player: 1 when it won (win motion) */
    /* 0x26 */ u16 unk_26;    /* rake (CPU): items it may let pass */
    /* 0x28 */ u16 unk_28;    /* rake: CPU difficulty; item: kind (0-2) */
    /* 0x2A */ u16 state;     /* player/rake state; item: the player whose basket it fell in */
    /* 0x2C */ u16 com;       /* players/rakes: gPlayers[].flags & 1; item: state */
    /* 0x2E */ u16 player;    /* index in D_80107250 */
    /* 0x30 */ s16 unk_30;    /* item: points it scores */
    /* 0x32 */ s16 unk_32;
    /* 0x34 */ s16 unk_34;
    /* 0x36 */ s16 unk_36;
    /* 0x38 */ f32 unk_38;    /* rake: reach; item: vertical speed */
    /* 0x3C */ f32 unk_3C;    /* rake: motion time; item: gravity */
    /* 0x40 */ f32 unk_40;    /* rake (CPU): reach error; item: x speed */
    /* 0x44 */ f32 unk_44;    /* item: z speed */
} RIObj; /* size = 0x48 (N64) */

/* A player's corner (D_80106CC0_125C00_RakinEmIn[4]). */
typedef struct RIStation {
    /* 0x00 */ Vec pos;       /* the rake's pivot */
    /* 0x0C */ Vec base;      /* the basket */
    /* 0x18 */ Vec left;      /* the basket's two edges */
    /* 0x24 */ Vec right;
    /* 0x30 */ Vec rake;      /* the rake's head */
    /* 0x3C */ f32 angle;
    /* 0x40 */ s16 target[4]; /* CPU: items it lets pass (-1 none) */
} RIStation; /* size = 0x48 */

/* An item on the table (D_801070B8_125FF8_RakinEmIn[20]). */
typedef struct RIItem {
    /* 0x00 */ u8 flags;      /* 1 pushed by item `by`, 2 raked this frame, 4 off the table, 0x10 in a
                                 basket, 0x20 bounced off a basket's edge */
    /* 0x01 */ u8 by;
    /* 0x02 */ char unk_02[2];
    /* 0x04 */ f32 dist;      /* from the table's centre */
    /* 0x08 */ f32 angle;     /* angle within its quarter */
} RIItem; /* size = 0xC */

/* A player's score display (D_801071B0_1260F0_RakinEmIn[4]; DSSScore in ovl_3C). */
typedef struct RIScore {
    /* 0x00 */ u16 score;
    /* 0x02 */ u16 shown;     /* the number on screen, counting towards score */
    /* 0x04 */ u16 state;     /* 1: the number pops */
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ f32 angle;
} RIScore; /* size = 0xC */

/* Per-character data (main D_800CD438_CE038, 0x18 bytes each). */
typedef struct RICharData {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 unk_04; /* the character's file directory */
    /* 0x08 */ s32 unk_08; /* its model file */
    /* 0x0C */ char unk_0C[0xC];
} RICharData; /* size = 0x18 */

/* ---- .data (0x125C00-0x125EE0) ---- */
extern RIStation D_80106CC0_125C00_RakinEmIn[4];
extern RIStation D_80106CF0_125C30_RakinEmIn[]; /* = &D_80106CC0[0].rake: only .pos is used */
extern u16 D_80106DE0_125D20_RakinEmIn[6];      /* rake texture file by character */
extern Vec D_80106DEC_125D2C_RakinEmIn[24];     /* item start positions */
extern s16 D_80106F0C_125E4C_RakinEmIn[4];      /* points by item kind */
extern u16 D_80106F14_125E54_RakinEmIn[4];      /* texture file by item kind */
extern u16 D_80106F1C_125E5C_RakinEmIn[16][2];  /* HUD sprite x, y */
extern u16 D_80106F1E_125E5E_RakinEmIn[][2];    /* = &D_80106F1C[0][1] */
extern s32 D_80106F5C_125E9C_RakinEmIn[6];      /* face sprite file by character */
extern s32 D_80106F74_125EB4_RakinEmIn;         /* camera set up */
extern u16 D_80106F78_125EB8_RakinEmIn[6][2];   /* player motion files by character */
extern u16 D_80106F7A_125EBA_RakinEmIn[];       /* = &D_80106F78[0][1] */
extern s16 D_80106F90_125ED0_RakinEmIn;         /* result wait */

/* ---- .bss ---- */
extern u16 D_801070A0_125FE0_RakinEmIn; /* game state */
extern s16 D_801070A2_125FE2_RakinEmIn; /* game state timer */
extern s16 D_801070A4_125FE4_RakinEmIn; /* 1P-flag result wait */
extern f32 D_801070A8_125FE8_RakinEmIn; /* table radius offset */
extern f32 D_801070AC_125FEC_RakinEmIn; /* rake angle window */
extern u64 D_801070B0_125FF0_RakinEmIn; /* start positions taken */
extern RIItem D_801070B8_125FF8_RakinEmIn[20];
extern u8 D_801071A8_1260E8_RakinEmIn;  /* kind 2 items left to place */
extern u8 D_801071A9_1260E9_RakinEmIn;  /* kind 1 items left to place */
extern u8 D_801071AA_1260EA_RakinEmIn;  /* items left on the table */
extern u8 D_801071AB_1260EB_RakinEmIn;  /* winners */
extern u8 D_801071AC_1260EC_RakinEmIn;  /* best score */
extern RIScore D_801071B0_1260F0_RakinEmIn[4];
extern s16 D_801071E0_126120_RakinEmIn[50]; /* sprite animations */
extern RIObj D_80107250_126190_RakinEmIn[50];
extern omObjData* D_80107370_1262B0_RakinEmIn; /* = D_80107250[4].obj */
extern s16 D_80107374_1262B4_RakinEmIn;        /* = D_80107250[4].spr */
extern RIObj D_801073B8_1262F8_RakinEmIn[];    /* = &D_80107250[5] (rakes) */
extern u16 D_801073E4_126324_RakinEmIn[];      /* = &D_80107250[5].com */
extern RIObj D_80107520_126460_RakinEmIn[];    /* = &D_80107250[10] (items) */
extern RIObj D_80107AC0_126A00_RakinEmIn;      /* = D_80107250[30] (HUD) */
extern s16 D_80107AC4_126A04_RakinEmIn;        /* = D_80107250[30].spr */

/* ---- main ---- */
extern s8 ContStkX[4];
extern s8 ContStkY[4];
extern f32 D_800F94A8_FA0A8[];    /* CZoomM */
extern Vec3f D_80102770_103370[]; /* CRotM */
extern Vec3f D_801013B0_101FB0[]; /* CenterM */
extern s16 D_800FA606_FB206;
extern RICharData D_800CD438_CE038[];
extern u16 D_801011FC_101DFC;
s16 LoadFormFile(s32, s32);
s32 PlaySound(s32);
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
void func_8000C024_CC24(omObjData* obj, u8 idx, s8 val);
void func_80018CCC_198CC(omObjData* obj, u16 slot, s32 file); /* loads obj->motion[slot] */
void func_80018E30_19A30(s32);
u16 func_80018A30_19630(s32 file, s32 attr); /* model from a file */
void func_80018F58_19B58(s32);
s16 func_8001A2F8_1AEF8(s32 arg0);
void func_80020D20_21920(s16 arg0);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16, f32, f32, f32);
void* func_80027154_27D54(s32 size, s16 tag);
void func_80029A8C_2A68C(s16);
void func_80029AFC_2A6FC(s16);
void func_80029B80_2A780(s16 arg0, s16 arg1); /* model motion */
void func_80029C74_2A874(s16, f32);
f32 func_80029CE4_2A8E4(s16);                 /* model motion time */
f32 func_80029D0C_2A90C(s16);                 /* motion length */
void func_80029EDC_2AADC(s16 arg0, u8 arg1);
void func_8002D4D0_2E0D0(s16 n);
void func_8003E4F4_3F0F4(s16 arg0, u8 arg1, u8 arg2);
void func_8003E560_3F160(s16, u8); /* defined (s16, s32) in 3D6A0.c; retail passes a u8 here */
s16 func_800691FC_69DFC(s16 mesNo, ...);
s32 func_80069538_6A138(void);
void func_8006D4D0_6E0D0(s16 seconds); /* timer display */
void func_8006D518_6E118(void);
void func_8007273C_7333C(u8* arg0, u8 arg1);
void func_80079128_79D28(void);
void func_80079614_7A214(s16 time);
s16 func_80079798_7A398(s16 sfx, s16 player);
s16 func_800797DC_7A3DC(s32 sfx, s16 player);
void func_800798F8_7A4F8(s16 sound, s16 pan);
void func_80079FF4_7ABF4(omObjData* object);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size);
f64 func_800B1820_B2420(f64);     /* sqrt, in double */
f64 func_800B75D0_B81D0(f64);     /* cos of degrees, in double */
f64 func_800B80D0_B8CD0(f64);     /* sin of degrees, in double */
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
void osViBlack(u8 active);
void Hu3DCamSetPerspective(s16, f32, f32, f32);
void ScissorSet(u8 arg0, f32 x1, f32 y1, f32 x2, f32 y2);
void ViewportSet(u8, f32, f32, f32, f32, f32, f32);
void InitFadeOut(s32, s32);
void InitFadeIn(s32, s32);

/* ---- overlay functions ---- */

/* 121740.c */
void func_80102800_121740_RakinEmIn(void);
void func_8010281C_12175C_RakinEmIn(u8 player);
u8 func_801028A0_1217E0_RakinEmIn(u8 n, u64* used);
f32 func_801029F0_121930_RakinEmIn(f32 x);
void func_80102B40_121A80_RakinEmIn(Vec* from, Vec* to, Vec* out);
f32 func_80102EB4_121DF4_RakinEmIn(f32 angle, f32 add);
void func_80102F0C_121E4C_RakinEmIn(void);
void func_8010302C_121F6C_RakinEmIn(RIObj* o, s16 member, u16 anim, u16 x, s32 y);
void func_801030E4_122024_RakinEmIn(omObjData* obj);
void func_801033B0_1222F0_RakinEmIn(omObjData* obj);
void func_801036B8_1225F8_RakinEmIn(void);
void func_801036F4_122634_RakinEmIn(void);
void func_8010378C_1226CC_RakinEmIn(omObjData* obj);
void func_80103BB0_122AF0_RakinEmIn(omObjData* obj);
void func_80103E04_122D44_RakinEmIn(void);
void func_80103E4C_122D8C_RakinEmIn(omObjData* obj);
void func_80103F9C_122EDC_RakinEmIn(omObjData* obj);
void func_8010428C_1231CC_RakinEmIn(void);
s16 func_80104340_123280_RakinEmIn(s16 player, s16 item);
void func_801043B0_1232F0_RakinEmIn(s16 player, s16 item);
void func_80104418_123358_RakinEmIn(s16 player);
void func_80104474_1233B4_RakinEmIn(RIObj* o);
s16 func_8010468C_1235CC_RakinEmIn(RIObj* o, s16 player);
void func_80104950_123890_RakinEmIn(omObjData* obj, s16 item);
u8 func_80104A6C_1239AC_RakinEmIn(f32 center, f32 angle, f32 range);
void func_80104BCC_123B0C_RakinEmIn(omObjData* obj);
void func_801051D8_124118_RakinEmIn(omObjData* obj);
void func_80105550_124490_RakinEmIn(void);
void func_801055F4_124534_RakinEmIn(omObjData* obj);
void func_80105E98_124DD8_RakinEmIn(omObjData* obj);
void func_80106060_124FA0_RakinEmIn(void);
void func_80106104_125044_RakinEmIn(omObjData* obj);
void func_80106164_1250A4_RakinEmIn(omObjData* obj);
void func_80106218_125158_RakinEmIn(omObjData* obj);
void func_80106258_125198_RakinEmIn(omObjData* obj);
void func_801062CC_12520C_RakinEmIn(void);
u8 func_801064C8_125408_RakinEmIn(void);
void func_801065BC_1254FC_RakinEmIn(omObjData* obj);
void func_801065E0_125520_RakinEmIn(omObjData* obj);
void func_80106618_125558_RakinEmIn(omObjData* obj);
void func_80106670_1255B0_RakinEmIn(omObjData* obj);
void func_80106920_125860_RakinEmIn(omObjData* obj);
void func_801069D8_125918_RakinEmIn(void);

/* 125B50.c */
void func_80106C10_125B50_RakinEmIn(void);
void func_80106C94_125BD4_RakinEmIn(void);

#endif
