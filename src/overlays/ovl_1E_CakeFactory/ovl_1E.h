#ifndef _OVL_1E_H
#define _OVL_1E_H

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/data.h"
#include "game/collision.h"

/* ---- main-segment API used by 1E (missing from include/) ---- */

/* Cake Factory: 2 vs 2, four conveyor lanes. No MP1 ancestor. Retail files 1B8DF0.c (mul fix) and
   1BDFA0.c (80107 9B0, one function); .data is asm, .rodata carved from 0x1BE1F0. */


/* Per-character data, 0x18 bytes each. */
typedef struct CFCharData {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s32 unk_04; /* model/motion directory */
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10; /* model file */
    /* 0x14 */ char unk_14[4];
} CFCharData;
extern CFCharData D_800CD438_CE038[];

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

void func_8002CA48_2D648(u8, u8, u8);
void func_80026D28_27928(s32);
extern u8 D_800FD8AC[]; /* COM difficulty when flag 0xC is set */
extern Vec3f D_801013B0_101FB0[]; /* CenterM */
extern Vec3f D_80102770_103370[]; /* CRotM */
extern f32 D_800F94A8_FA0A8[];    /* CZoomM */
extern f32 D_800FC8F8_FD4F8[][6]; /* per camera: rot, x, z, fov, far, near (7AA60.c) */
extern f32 D_80100018_100C18[];
void Hu3DCamSetPositionOrientation(s16, Vec3f*, Vec3f*, Vec3f*);
void Hu3DCamUpdateMtx(s16 camIndex);
void func_8006D4D0_6E0D0(s16);    /* the seconds counter */
void func_8006D518_6E118(void);
void func_8002BCA8_2C8A8(s16 model, f32 s, f32 t, s32 arg3, s32 arg4); /* texture scroll */
void func_80023554_24154(s16 model, s16 frame, char* part, f32 mtx[4][4]); /* part matrix */
void func_800B1F50_B2B50(f32 (*m)[4], f32 x, f32 y, f32 z);
void func_80025830_26430(f32 (*m)[4], f32 x, f32 y, f32 z);
void func_80025884_26484(f32 (*m)[4], f32 x, f32 y, f32 z);
void func_80025BA4_267A4(f32 (*)[4], f32 (*)[4], f32 (*)[4]); /* MP1 MtxMult */
s16 func_8001A2F8_1AEF8(s32);
s16 func_8001AAAC_1B6AC(s16, s32, s32);
void func_8001A708_1B308(u16, s32);
void func_8001A91C_1B51C(u16 spriteId, f32 x, f32 y);
void func_80018CCC_198CC(omObjData* obj, u16 slot, s32 file);
u16 func_80018A64_19664(s32 file, s32 attr);
void func_80029B80_2A780(s16 arg0, s16 arg1);
void func_80029BF0_2A7F0(s16, s16, s16, s16, s16);
s32 func_80029E14_2AA14(s16 arg0); /* 2AA14.c: u8; retail callers re-extend the result */
void func_80029E80_2AA80(s16, s32, s32);
void func_80082488_83088(s16 grpIdx, s16 idx, u16 a);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
void SprAttrReset(s16 grpIdx, s16 idx, s32 flag);
void SprAttrSet(s16 grpIdx, s16 idx, s32 flag);
void SprBankSet(s16 grpIdx, s16 idx, s16 bank);
void SprPosSet(s16 grpIdx, s16 idx, s16 x, s16 y);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
void SprScaleSet(s16 group, s16 member, f32 x, f32 y);
void SprAnimSet(s16 group, s16 member, s16 anim, u16 arg3);
s16 SprAnimRead(void*);
s16 SprCreate(s32 num, s32 attr);
void espDispOn(u16);
void espPosSet(u16 spriteId, s16 x, s16 y);

/* ---- types ---- */

/* The work of one lane's conveyor belt (D_80107DA0_1BE390_CakeFactory[lane]->unk_50). Slots 1-6 of x/y/z are cakes
   riding the belt, 8-10 the toppings of the lane's three stations. The set-up loop writes index
   11 too, i.e. the next array's first element (retail: harmless, they are reset after it). */
typedef struct CFBelt {
    /* 0x00 */ f32 speedBase;
    /* 0x04 */ f32 speed;
    /* 0x08 */ f32 dir;
    /* 0x0C */ f32 x[11];
    /* 0x38 */ f32 y[11];
    /* 0x64 */ f32 z[11];
    /* 0x90 */ f32 phase; /* wraps at 180: one cake spawn slot */
    /* 0x94 */ f32 dropY;
    /* 0x98 */ f32 unk_98;
    /* 0x9C */ u16 unk_9C;
    /* 0x9E */ u16 unk_9E;
    /* 0xA0 */ u8 head;   /* next cake slot - 1 */
    /* 0xA1 */ u8 unk_A1;
    /* 0xA2 */ u8 every;  /* spawn every n+1 slots */
    /* 0xA3 */ u8 count;
    /* 0xA4 */ u8 lane;
    /* 0xA5 */ u8 team;
    /* 0xA6 */ u8 kind;   /* D_80107DB0_1BE3A0_CakeFactory[lane]: 1 or 2, the ingredient of this lane */
    /* 0xA7 */ char unk_A7[0xD];
} CFBelt; /* size = 0xB4 */

/* A team's oven (D_80107DB4_1BE3A4_CakeFactory[team]->unk_50). */
typedef struct CFTeam {
    /* 0x00 */ f32 y;
    /* 0x04 */ f32 speedMul;
    /* 0x08 */ f32 scoreScale;
    /* 0x0C */ f32 scoreAngle;
    /* 0x10 */ s16 unk_10[2];
    /* 0x14 */ s32 state;   /* 0 waits, 1 good cake, 2 bad cake, 3 down, 4, 5 up */
    /* 0x18 */ s32 slot[2]; /* kinds in the order they arrived */
    /* 0x20 */ s32 req[2];  /* req[0]: kinds being delivered, bits */
    /* 0x28 */ s32 result;  /* 1 good, 2 bad: read by the players */
    /* 0x2C */ s32 timer;
    /* 0x30 */ char unk_30[8];
    /* 0x38 */ u8 busy;     /* a topping is falling: the timer stops */
    /* 0x39 */ u8 count;    /* kinds delivered */
    /* 0x3A */ char unk_3A;
    /* 0x3B */ u8 score;
} CFTeam; /* size = 0x3C */

/* A player's work (D_800FFFD8_100BD8[i]->unk_50) and its start table. */
typedef struct CFPlayer {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
    /* 0x0C */ f32 rotY;
    /* 0x10 */ f32 scale;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ s32 player;
    /* 0x1C */ s32 state;
    /* 0x20 */ s32 timer;
} CFPlayer; /* size = 0x24 */

/* A lane's station state (bss; D_80107E50_1BE440_CakeFactory has no retail label of its own). */
typedef struct CFLane {
    /* 0x00 */ char unk_00[0xE];
    /* 0x0E */ s16 mdl[3];   /* topping models */
    /* 0x14 */ s16 state[3]; /* 0 idle, 3 in hand, 4 dropped, 5 falling, 6 on the cake */
    /* 0x1A */ char unk_1A[2];
    /* 0x1C */ s32 flags;    /* 2 grab frame, 4 cake taken, 0x40 hold */
    /* 0x20 */ s32 flags2;   /* 0x20 a cake in reach, 0x80 COM grab window */
    /* 0x24 */ u8 next;      /* next topping */
    /* 0x25 */ u8 cake;      /* cake in reach */
    /* 0x26 */ u8 taken;     /* cake taken */
    /* 0x27 */ char unk_27;
} CFLane; /* size = 0x28 */

/* Lane tables (.data): speed, direction, cake entry and exit. */
typedef struct CFBeltInit {
    /* 0x00 */ f32 speed;
    /* 0x04 */ f32 dir;
    /* 0x08 */ f32 x;
    /* 0x0C */ f32 z;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ u16 unk_14;
    /* 0x16 */ u16 unk_16;
} CFBeltInit; /* size = 0x18 */

/* The teams table, copied to the stack by value. */
typedef struct CFTable {
    s32 v[4];
} CFTable;

/* ---- .data (1BE020) ---- */

extern f32 D_80107A30_1BE020_CakeFactory[3][7];         /* no users */
extern CFPlayer D_80107A84_1BE074_CakeFactory[4];       /* start of each player; D_80107A88_1BE078_CakeFactory..A9C, AA0, AD4 are its fields */
extern f32 D_80107B14_1BE104_CakeFactory[2];            /* topping height */
extern f32 D_80107B1C_1BE10C_CakeFactory[2];            /* D_80107B20_1BE110_CakeFactory is [1] */
extern f32 D_80107B24_1BE114_CakeFactory[6];            /* belt speed per phase; retail reads [i-1] by D_80107B20_1BE110_CakeFactory */
extern f32 D_80107B3C_1BE12C_CakeFactory[2];
extern CFBeltInit D_80107B44_1BE134_CakeFactory[4];     /* D_80107B48_1BE138_CakeFactory..B5A are its fields */
extern s32 D_80107BA4_1BE194_CakeFactory[4];            /* score digit x; read by low half D_80107BA6 */
extern s32 D_80107BB4_1BE1A4_CakeFactory[2]; /* sprite positions; low halves */
extern s32 D_80107BBC_1BE1AC_CakeFactory[2]; /* undefined_syms.txt: no label in the .data blob; read by D_80107BBE */
extern s32 D_80107BC4_1BE1B4_CakeFactory[2]; /* D_80107BC6, D_80107BCA */
extern s32 D_80107BCC_1BE1BC_CakeFactory[4]; /* undefined_syms.txt; read by D_80107BCE, [2] by D_80107BD6 */
extern s32 D_80107BDC_1BE1CC_CakeFactory[7];
extern s32 D_80107BF8_1BE1E8_CakeFactory; /* players made */
extern s32 D_80107BFC_1BE1EC_CakeFactory;

/* split labels retail reads by their own address: low halves of D_80107BC4[0], [1], D_80107BCC[0], [2] */
extern s16 D_80107BC6_1BE1B6_CakeFactory;
extern s16 D_80107BCA_1BE1BA_CakeFactory;
extern s16 D_80107BCE_1BE1BE_CakeFactory;
extern s16 D_80107BD6_1BE1C6_CakeFactory;

/* ---- .bss (80107D90) ---- */

extern s16 D_80107D90_1BE380_CakeFactory;       /* 1: the one-player flag 0xC run */
extern s16 D_80107D92_1BE382_CakeFactory[7];    /* player models */
extern omObjData* D_80107DA0_1BE390_CakeFactory[4];  /* belts */
extern u8 D_80107DB0_1BE3A0_CakeFactory[4];     /* the ingredient of each lane, 1 or 2 */
extern omObjData* D_80107DB4_1BE3A4_CakeFactory[2];  /* ovens */
extern s32 D_80107DBC_1BE3AC_CakeFactory;       /* seconds left; low half D_80107DBE */
extern f32 D_80107DC0_1BE3B0_CakeFactory;       /* phase blend countdown */
extern f32 D_80107DC4_1BE3B4_CakeFactory;       /* phase blend length */
extern u16 D_80107DC8_1BE3B8_CakeFactory;
extern u16 D_80107DCA_1BE3BA_CakeFactory;       /* frames of this second */
extern s16 D_80107DCC_1BE3BC_CakeFactory[4];
extern s32 D_80107DD4_1BE3C4_CakeFactory;       /* sprite group; low half D_80107DD6_1BE3C6_CakeFactory */
extern s32 D_80107DD8_1BE3C8_CakeFactory;       /* D_80107DDA_1BE3CA_CakeFactory */
extern s32 D_80107DDC_1BE3CC_CakeFactory;       /* D_80107DDE_1BE3CE_CakeFactory */
extern s32 D_80107DE0_1BE3D0_CakeFactory;       /* D_80107DE2_1BE3D2_CakeFactory */
extern s16 D_80107DE4_1BE3D4_CakeFactory[2];    /* belt sounds */
extern f32 D_80107DF0_1BE3E0_CakeFactory[8];    /* belt texture scroll */
extern u8 D_80107E10_1BE400_CakeFactory[4];     /* human */
extern u8 D_80107E14_1BE404_CakeFactory;
extern Vec D_80107E18_1BE408_CakeFactory;
extern u16 D_80107E24_1BE414_CakeFactory[6];    /* buttons */
extern s32 D_80107E30_1BE420_CakeFactory[4];    /* the player at each lane */
extern Vec D_80107E40_1BE430_CakeFactory;
extern CFLane D_80107E50_1BE440_CakeFactory[4];
extern s32 D_80107EF0_1BE4E0_CakeFactory[24];
extern u8 D_80107F50_1BE540_CakeFactory;
extern u8 D_80107F51_1BE541_CakeFactory;
extern u8 D_80107F52_1BE542_CakeFactory[4];
extern s16 D_80107F56_1BE546_CakeFactory[5];    /* COM difficulty */
extern s32 D_80107F60_1BE550_CakeFactory[6];    /* win sound */
extern s32 D_80107F78_1BE568_CakeFactory[4];    /* the state's first frame */
extern s32 D_80107F88_1BE578_CakeFactory;       /* game state */
extern Vec D_80107F8C_1BE57C_CakeFactory;
extern s32 D_80107F98_1BE588_CakeFactory[4];
extern s16 D_80107FA8_1BE598_CakeFactory;
extern s32 D_80107FB0_1BE5A0_CakeFactory[4];    /* the lane of each player */
extern s32 D_80107FC0_1BE5B0_CakeFactory[5];    /* held A */
extern s32 D_80107FD4_1BE5C4_CakeFactory;
extern f32 D_80108020_1BE610_CakeFactory[4];    /* belt speed */
extern u16 D_80108030_1BE620_CakeFactory[4];    /* pressed */
extern s32 D_80108038_1BE628_CakeFactory;
extern u8 D_8010803C_1BE62C_CakeFactory[4];
extern s32 D_80108040_1BE630_CakeFactory[4];
extern u8 D_80108050_1BE640_CakeFactory[4];     /* 0 won */
extern s32 D_80108054_1BE644_CakeFactory;       /* phase, 1-5 */
extern s32 D_80108058_1BE648_CakeFactory[6];    /* player state */

/* ---- functions ---- */

void func_80102800_1B8DF0_CakeFactory(void);
void func_80102978_1B8F68_CakeFactory(void);
void func_80102CF8_1B92E8_CakeFactory(void);
void func_80102F64_1B9554_CakeFactory(void);
void func_80103114_1B9704_CakeFactory(omObjData* obj);
void func_80103190_1B9780_CakeFactory(omObjData* obj, u16 lane);
void func_801035E8_1B9BD8_CakeFactory(s16 model, Vec* out, f32 (*m)[4]);
void func_801036E8_1B9CD8_CakeFactory(omObjData* obj);
void func_80104388_1BA978_CakeFactory(omObjData* obj);
void func_801043BC_1BA9AC_CakeFactory(omObjData* obj);
void func_801043F0_1BA9E0_CakeFactory(omObjData* obj);
void func_80104424_1BAA14_CakeFactory(omObjData* obj);
void func_80104458_1BAA48_CakeFactory(void);
void func_80104544_1BAB34_CakeFactory(omObjData* obj);
void func_80105074_1BB664_CakeFactory(omObjData* obj);
void func_80105128_1BB718_CakeFactory(void);
void func_8010518C_1BB77C_CakeFactory(void);
void func_801055EC_1BBBDC_CakeFactory(omObjData* obj);
void func_80105A80_1BC070_CakeFactory(omObjData* obj);
void func_80105BE0_1BC1D0_CakeFactory(omObjData* obj);
void func_80105D40_1BC330_CakeFactory(void);
void func_80105DAC_1BC39C_CakeFactory(s32 player);
void func_8010633C_1BC92C_CakeFactory(s32 player);
void func_801064A4_1BCA94_CakeFactory(omObjData* obj);
void func_80106EE4_1BD4D4_CakeFactory(omObjData* obj);
void func_801072F4_1BD8E4_CakeFactory(void);
void func_8010740C_1BD9FC_CakeFactory(omObjData* obj);
void func_801079B0_1BDFA0_CakeFactory(s16 cam, f32 zoom, f32 rx, f32 ry, f32 rz, f32 cx, f32 cy, f32 cz);

#endif
