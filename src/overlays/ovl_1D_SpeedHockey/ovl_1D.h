#ifndef _OVL_1D_H
#define _OVL_1D_H

/* Overlay 1D: Speed Hockey (2 vs 2 air hockey). No MP1 ancestor. Four retail files:
   1B4950.c (the entry point alone), 1B49A0.c (from 80102850: puck physics, puck/paddle/shadow
   objects, score sprites), 1B68F0.c (from 801047A0: the four player objects, CPU control),
   1B7900.c (from 801057B0: game state machine, camera, lights, pad save/restore).
   .data stays asm (1B8730.data.s; per file 801065E0 / 80106AC0 / 80106BD0); .rodata is carved
   per file ([0x1B8D90, .rodata, 1B49A0] and [0x1B8DB8, .rodata, 1B7900], jump tables only). */

#include "common.h"
#include "game/object.h"
#include "game/pad.h"

/* ---------------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------------- */

/* An axis-aligned box on the table plane (x and z). */
typedef struct SHBox {
    /* 0x0 */ f32 xMin;
    /* 0x4 */ f32 xMax;
    /* 0x8 */ f32 zMin;
    /* 0xC */ f32 zMax;
} SHBox;

/* A wall segment the puck bounces off. Entries 0-9 are the fixed rink walls (paddle -1);
   10-25 are rebuilt every step from the paddle boxes (paddle = index into D_80106CA0). */
typedef struct SHWall {
    /* 0x00 */ Vec p[2];
    /* 0x18 */ s32 paddle;
} SHWall; /* size = 0x1C */

/* omObjData::unk_50 of every object in the D_80106CA0 group (0x44 bytes each): paddles 0-3,
   the puck (4) and its two trailing shadows (5, 6). */
typedef struct SHObjWork {
    /* 0x00 */ omObjData* target; /* paddle: its player's object; shadow: the object it trails */
    /* 0x04 */ s32 goal;          /* puck: 0, or the goal it entered (2 right, 3 left) */
    /* 0x08 */ s32 state;         /* puck: 0 face-off wobble, 1 moving, 2 goal, 3 reset */
    /* 0x0C */ s32 hit;           /* paddle: hit the puck this step */
    /* 0x10 */ u16 timer;         /* puck */
    /* 0x12 */ s8 score[2];       /* puck: goals per team */
    /* 0x14 */ Vec pos;
    /* 0x20 */ Vec prev;
    /* 0x2C */ char unk2C[4];
    /* 0x30 */ Vec dir;           /* puck: unit direction */
    /* 0x3C */ f32 speed;
    /* 0x40 */ f32 spin;          /* added to rot.y each step */
} SHObjWork; /* size = 0x44 */

#define SH_WORK(obj) ((SHObjWork*)(obj)->unk_50)

/* One row of D_801065E0: the objects of the D_80106CA0 group. */
typedef struct SHObjDef {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
    /* 0x0C */ s32 file;
    /* 0x10 */ s32 attr;
    /* 0x14 */ u16 kind; /* index into D_80106AA8 */
} SHObjDef; /* size = 0x18 */

/* One row of D_80106688: the score sprites. */
typedef struct SHSprDef {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ s32 file;
    /* 0x8 */ s32 visible;
} SHSprDef; /* size = 0xC */

/* omObjData::unk_50 of a player (0x30 bytes). */
typedef struct SHPlayer {
    /* 0x00 */ s16 player;
    /* 0x02 */ s16 port;
    /* 0x04 */ s16 team;     /* 0 or 1 */
    /* 0x06 */ s16 state;    /* result: 0 wait, 1 win/lose motion, 2 done */
    /* 0x08 */ char unk08[2];
    /* 0x0A */ u16 cpuState; /* D_80106B98 index */
    /* 0x0C */ s16 cpuTimer;
    /* 0x0E */ s16 cpuLevel; /* gPlayers[].cpu_difficulty */
    /* 0x10 */ f32 cpuTarget; /* z the CPU paddle heads for */
    /* 0x14 */ f32 cpuRange;
    /* 0x18 */ s32 motion;   /* current motion slot */
    /* 0x1C */ struct {
        s16 len;
        s16 speed;
    } mot[3];
    /* 0x28 */ s32 timer;
    /* 0x2C */ char unk2C[4];
} SHPlayer; /* size = 0x30 */

/* One row of D_80106B08: a motion file and its speed. */
typedef struct SHMotDef {
    /* 0x0 */ s32 file;
    /* 0x4 */ u16 speed;
} SHMotDef; /* size = 0x8 */

/* CPU tuning per difficulty (D_80106AE0). */
typedef struct SHCpuDef {
    /* 0x0 */ u8 wait;
    /* 0x1 */ s8 fast;
    /* 0x2 */ s8 slow;
    /* 0x3 */ s8 chance; /* of 10: aim at random */
} SHCpuDef;

/* The camera (D_80106BD0). */
typedef struct SHCamera {
    /* 0x00 */ Vec eye;
    /* 0x0C */ Vec at;
    /* 0x18 */ f32 fov;
    /* 0x1C */ s16 vp[4];      /* viewport scale x/y, translate x/y */
    /* 0x24 */ s16 scissor[4]; /* x, y, w, h */
    /* 0x2C */ s32 file;
    /* 0x30 */ s16 sprite;
} SHCamera; /* size = 0x34 */

/* A light (D_80106C04). */
typedef struct SHLight {
    /* 0x0 */ u8 color[3];
    /* 0x4 */ f32 dir[3];
} SHLight; /* size = 0x10 */

/* Saved pad state per port (D_80106EC6). */
typedef struct SHPad {
    /* 0x0 */ u16 trg;
    /* 0x2 */ u16 btn;
    /* 0x4 */ s8 stkX;
    /* 0x5 */ s8 stkY;
} SHPad; /* size = 0x6 */

/* The game state (bss 80106EB0). */
typedef struct SHGame {
    /* 0x00 */ u8 state;      /* D_80106C24 index: 0 intro, 1 countdown, 2 play, 3 result, 4 exit */
    /* 0x01 */ u8 next;
    /* 0x02 */ u8 sub;
    /* 0x04 */ s32 timer;
    /* 0x08 */ s16 countdown;
    /* 0x0A */ s16 time;      /* frames left */
    /* 0x0C */ s16 winner[2]; /* players of the winning team */
    /* 0x10 */ s16 winnerCount;
    /* 0x12 */ s16 winTeam;   /* -1 draw */
    /* 0x14 */ u16 frame;
    /* 0x16 */ SHPad pad[4];
} SHGame;

/* ---------------------------------------------------------------------------------------------
   Data (.data, 1B8730.data.s, asm)
   --------------------------------------------------------------------------------------------- */

/* 1B49A0.c: 801065E0-80106AC0 */
extern SHObjDef D_801065E0_1B8730_SpeedHockey[7];
extern SHSprDef D_80106688_1B87D8_SpeedHockey[9];
extern SHWall D_801066F4_1B8844_SpeedHockey[4]; /* a paddle's edges: bottom, top, left, right */
extern SHBox D_80106764_1B88B4_SpeedHockey;     /* a paddle's box */
extern SHWall D_80106774_1B88C4_SpeedHockey[26];
extern SHBox D_80106A4C_1B8B9C_SpeedHockey; /* the rink */
extern SHBox D_80106A5C_1B8BAC_SpeedHockey; /* left goal mouth */
extern SHBox D_80106A6C_1B8BBC_SpeedHockey; /* right goal mouth */
extern f32 D_80106A7C_1B8BCC_SpeedHockey;   /* left goal line */
extern f32 D_80106A80_1B8BD0_SpeedHockey;   /* right goal line */
extern void (*D_80106A84_1B8BD4_SpeedHockey[4])(omObjData*, SHObjWork*);
extern void (*D_80106A94_1B8BE4_SpeedHockey[5])(omObjData*, SHObjWork*);
extern void (*D_80106AA8_1B8BF8_SpeedHockey[4])(omObjData*);

/* 1B68F0.c: 80106AC0-80106BD0 */
extern f32 D_80106AC0_1B8C10_SpeedHockey[4]; /* x per paddle slot */
extern f32 D_80106AD0_1B8C20_SpeedHockey[4]; /* rot.y per paddle slot */
extern SHCpuDef D_80106AE0_1B8C30_SpeedHockey[4];
extern s32 D_80106AF0_1B8C40_SpeedHockey[6];        /* model per character */
extern SHMotDef D_80106B08_1B8C58_SpeedHockey[6][3]; /* motions per character */
extern void (*D_80106B98_1B8CE8_SpeedHockey[3])(omObjData*, SHPlayer*);
extern void (*D_80106BA4_1B8CF4_SpeedHockey[5])(omObjData*);
extern void (*D_80106BB8_1B8D08_SpeedHockey[4])(omObjData*);

/* 1B7900.c: 80106BD0-80106C40 */
extern SHCamera D_80106BD0_1B8D20_SpeedHockey[1];
extern SHLight D_80106C04_1B8D54_SpeedHockey[2];
extern void (*D_80106C24_1B8D74_SpeedHockey[5])(omObjData*);

/* ---------------------------------------------------------------------------------------------
   Bss (ovl_1D_bss)
   --------------------------------------------------------------------------------------------- */

/* 1B49A0.c */
/* Object group 1: paddles, puck, shadows. Retail reloads the pointer after every store through
   an object, as GCC does for a struct member (not for a scalar global). */
typedef struct SHObjList {
    omObjData** objs;
} SHObjList;
extern SHObjList D_80106CA0_1B8DF0_SpeedHockey;
extern u16 D_80106CA4_1B8DF4_SpeedHockey[9];      /* score sprites */
extern SHBox D_80106CB8_1B8E08_SpeedHockey[4];    /* paddle boxes this step */
extern Vec D_80106CF8_1B8E48_SpeedHockey[26];     /* hit point per wall */
extern s32 D_80106E30_1B8F80_SpeedHockey[26];     /* walls hit */
/* 1B68F0.c */
extern omObjData** D_80106EA0_1B8FF0_SpeedHockey; /* object group 0: the players */
/* 1B7900.c */
extern SHGame D_80106EB0_1B9000_SpeedHockey;

/* ---------------------------------------------------------------------------------------------
   Main
   --------------------------------------------------------------------------------------------- */

extern s8 ContStkX[4];
extern s8 ContStkY[4];
extern u16 D_801011FC_101DFC; /* nonzero once the minigame is told to end */
extern u8 D_80102720_103320;
extern f32 D_80101078_101C78;
extern f32 D_800F8410_F9010;

typedef struct SHEsprite {
    /* 0x00 */ char unk00[4];
    /* 0x04 */ u16 unk04;
    /* 0x06 */ char unk06[0x1E];
} SHEsprite; /* size = 0x24 */
extern SHEsprite* D_800F93FC_F9FFC;

void HuVecAdd(Vec*, Vec*, Vec*);
void HuVecCopyXYZ(Vec*, f32, f32, f32);
f32 HuVecGetLength3F(Vec*);
void HuVecMulScalar(Vec*, f32, Vec*);
void HuVecSubtract(Vec*, Vec*, Vec*);
s16 LoadFormFile(s32, s32);
s32 PlaySound(s32);
void espDispOff(u16);
void espDispOn(u16);
void espPosSet(u16 spriteId, s16 x, s16 y);
u16 func_80018A30_19630(s32 file, s32 attr);
u16 func_80018A64_19664(s32 file, s32 attr);
s16 func_8001A2F8_1AEF8(s32);
void func_8001A91C_1B51C(u16 spriteId, f32 x, f32 y);
s16 func_8001AAAC_1B6AC(s16, s32, s32);
void func_8001AC44_1B844(u16);
void func_80020D20_21920(s16);
void func_80023124_23D24(void);
void func_80026D28_27928(s32);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16, f32, f32, f32);
void* func_80027154_27D54(s32 size, s32 tag); /* HuMemAllocTag */
void func_8002864C_2924C(void);
void func_80029708_2A308(s32);
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_80029BF0_2A7F0(s16, s16, s16, s16, s16);
void func_80029FBC_2ABBC(s16, f32);
s32 func_8002C8B8_2D4B8(void*, s16);
f32 func_8002CA14_2D614(s16);
void func_8002CA48_2D648(u8, u8, u8);
void func_8002D0A0_2DCA0(s16, u8); /* model alpha */
void func_8002D124_2DD24(s16);
void func_8002D4D0_2E0D0(s16);
void func_8002F1A4_2FDA4(void);
void func_8003C8E0_3D4E0(s16);
s16 func_800691FC_69DFC(s16 mesNo, ...);
s32 func_80069538_6A138(void);
void func_8006D4D0_6E0D0(s16); /* the seconds counter */
void func_8006D518_6E118(void);
void func_80076BD0_777D0(s32, s32);
omObjData** func_80076D80_77980(s32);
omObjData* func_80076D98_77998(s32, u16);
u16 func_80078EA8_79AA8(void);
void func_800797DC_7A3DC(s16 sfx, s16 player);
void func_800798F8_7A4F8(s16 sound, s16 pan);
void func_8007A27C_7AE7C(s32 prio, s32 sprId, void* draw, f32 fov, Vec* eye, Vec* at);
void func_8007A7FC_7B3FC(void*);
void* func_800B0EF0_B1AF0(void*, u8, u32); /* memset */
void func_800B3170_B3D70(Vec*, Vec*);    /* copy */
void func_800B33E0_B3FE0(Vec*);          /* normalise */
void omDelObj(omObjData*);
void omSetRot(omObjData*, f32, f32, f32);
void omSetSca(omObjData*, f32, f32, f32);
void omSetTra(omObjData*, f32, f32, f32);
void omVibrate(s16 player, s16, s16, s16);

/* ---------------------------------------------------------------------------------------------
   Overlay functions
   --------------------------------------------------------------------------------------------- */

/* 1B4950.c */
void func_80102800_1B4950_SpeedHockey(void);
/* 1B49A0.c */
s32 func_80102850_1B49A0_SpeedHockey(Vec* p, SHBox* box);
s32 func_801028B8_1B4A08_SpeedHockey(Vec* a, Vec* b, Vec* out);
s32 func_80102A88_1B4BD8_SpeedHockey(Vec* p, SHBox* box);
void func_80102B04_1B4C54_SpeedHockey(SHObjWork* w, SHWall* wall, Vec* hit);
s32 func_80102CD4_1B4E24_SpeedHockey(SHObjWork* w, s32 n);
s32 func_8010308C_1B51DC_SpeedHockey(SHObjWork* w, s32 n);
s32 func_80103488_1B55D8_SpeedHockey(SHObjWork* w);
s32 func_8010389C_1B59EC_SpeedHockey(Vec* p);
void func_801038E8_1B5A38_SpeedHockey(omObjData* obj, SHObjWork* w);
void func_80103B94_1B5CE4_SpeedHockey(omObjData* obj, SHObjWork* w);
void func_80103CB0_1B5E00_SpeedHockey(omObjData* obj, SHObjWork* w);
void func_80103D9C_1B5EEC_SpeedHockey(omObjData* obj, SHObjWork* w);
void func_80103DFC_1B5F4C_SpeedHockey(omObjData* obj, SHObjWork* w);
void func_80103E34_1B5F84_SpeedHockey(omObjData* obj, SHObjWork* w);
void func_80103F78_1B60C8_SpeedHockey(omObjData* obj);
void func_80104020_1B6170_SpeedHockey(omObjData* obj);
void func_801040B0_1B6200_SpeedHockey(omObjData* obj);
void func_8010411C_1B626C_SpeedHockey(void);
void func_8010443C_1B658C_SpeedHockey(void);
void func_80104540_1B6690_SpeedHockey(void);
void func_80104584_1B66D4_SpeedHockey(void);
void func_8010461C_1B676C_SpeedHockey(s32 paddle, omObjData* player);
void func_8010463C_1B678C_SpeedHockey(Vec* dir, Vec* pos, Vec* prev);
s32 func_801046A0_1B67F0_SpeedHockey(omObjData* player);
s32 func_801046EC_1B683C_SpeedHockey(void);
void func_8010472C_1B687C_SpeedHockey(u32 i, s16 x, s16 y, f32 scale);
/* 1B68F0.c */
void func_801047A0_1B68F0_SpeedHockey(omObjData* obj, s32 mot);
void func_801048D4_1B6A24_SpeedHockey(omObjData* obj, SHPlayer* w);
void func_8010491C_1B6A6C_SpeedHockey(omObjData* obj, SHPlayer* w);
void func_80104A90_1B6BE0_SpeedHockey(omObjData* obj, SHPlayer* w);
void func_80104C00_1B6D50_SpeedHockey(omObjData* obj);
void func_80104C64_1B6DB4_SpeedHockey(omObjData* obj);
void func_80104D4C_1B6E9C_SpeedHockey(omObjData* obj);
void func_801050F0_1B7240_SpeedHockey(omObjData* obj, s32 player, s32 team, s32 paddle);
void func_801053F0_1B7540_SpeedHockey(omObjData* obj);
void func_801054A8_1B75F8_SpeedHockey(omObjData* obj);
void func_80105560_1B76B0_SpeedHockey(omObjData* obj);
void func_80105618_1B7768_SpeedHockey(omObjData* obj);
void func_801056D0_1B7820_SpeedHockey(void);
void func_80105768_1B78B8_SpeedHockey(void);
/* 1B7900.c */
void func_801057B0_1B7900_SpeedHockey(void);
u16 func_801057CC_1B791C_SpeedHockey(u32 cam, s32 file);
void func_801058A4_1B79F4_SpeedHockey(void);
void func_80105934_1B7A84_SpeedHockey(void);
void func_801059C4_1B7B14_SpeedHockey(void);
void func_80105A18_1B7B68_SpeedHockey(omObjData* obj);
void func_80105B00_1B7C50_SpeedHockey(omObjData* obj);
void func_80105B6C_1B7CBC_SpeedHockey(omObjData* obj);
void func_80105C28_1B7D78_SpeedHockey(omObjData* obj);
void func_80105ED4_1B8024_SpeedHockey(omObjData* obj);
void func_80105F90_1B80E0_SpeedHockey(omObjData* obj);
void func_80106044_1B8194_SpeedHockey(omObjData* obj);
void func_80106074_1B81C4_SpeedHockey(Vec* v);
void func_801060C0_1B8210_SpeedHockey(void);
void func_801060F8_1B8248_SpeedHockey(void);
void func_801062EC_1B843C_SpeedHockey(void);
void func_801064A0_1B85F0_SpeedHockey(void);
void func_8010650C_1B865C_SpeedHockey(s32 port, s8 stkX, s8 stkY, u16 trg, u16 btn);
u8 func_80106548_1B8698_SpeedHockey(void);
void func_80106554_1B86A4_SpeedHockey(u8 state);
void func_80106580_1B86D0_SpeedHockey(s16 team);
s16 func_8010658C_1B86DC_SpeedHockey(void);
void func_80106598_1B86E8_SpeedHockey(s16 player);

#endif
