#ifndef _OVL_0B_H
#define _OVL_0B_H

/* Overlay 0B: Day at the Races. Four retail files:
   125FE0.c (the entry point alone), 126030.c (from 80102850: level objects),
   1277D0.c (from 80103FF0: race game), 12BE50.c (from 80108670: Filet Relay's game frame: state machine,
   cameras, lights, pads, sprite models). .rodata is 1277D0.c's alone. */

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/data.h"
#include "game/collision.h"

typedef f32 Matrix4f[4][4];

/* One of the level's thirty objects. */
typedef struct DRObjDef {
    /* 0x00 */ Vec pos;
    /* 0x0C */ f32 rot;
    /* 0x10 */ f32 scale;
    /* 0x14 */ s32 file;
    /* 0x18 */ s32 attr;
    /* 0x1C */ u16 func;  /* index in D_8010A498 */
    /* 0x1E */ u16 count; /* models */
    /* 0x20 */ s32 motion;
} DRObjDef; /* size = 0x24 */

/* A level object's work, omObjData::unk_50, 0x24 bytes. */
typedef struct DRObjWork {
    /* 0x00 */ Vec pos;
    /* 0x0C */ s16 state;
    /* 0x0E */ char unk_0E[6];
    /* 0x14 */ f32 phaseA;
    /* 0x18 */ f32 phaseB;
    /* 0x1C */ char unk_1C[8];
} DRObjWork; /* size = 0x24 */

/* Abs of an s8 stick. */
#define DR_ABS(x) ((x) < 0 ? -(x) : (x))

typedef struct DRCamDef {
    /* 0x00 */ Vec start;
    /* 0x0C */ Vec eye;
    /* 0x18 */ s16 vp[4];
    /* 0x20 */ s16 scissor[4];
} DRCamDef; /* size = 0x28 */

typedef struct DRLight {
    /* 0x0 */ u8 dir[3];
    /* 0x4 */ f32 color[3];
} DRLight; /* size = 0x10 */

/* A camera path's key. */
typedef struct DRCamKey {
    /* 0x00 */ Vec pos;
    /* 0x0C */ Vec target;
    /* 0x18 */ f32 fov;
    /* 0x1C */ s32 frame;
} DRCamKey; /* size = 0x20 */

typedef struct DRCamPath {
    /* 0x0 */ s16 frame;
    /* 0x2 */ s16 last; /* the final key */
    /* 0x4 */ s16 seg;
    /* 0x8 */ DRCamKey* keys;
} DRCamPath; /* size = 0xC */

/* A camera object's work, 0xB0 bytes. */
typedef struct DRCam {
    /* 0x00 */ s16 mode; /* index in D_8010AAD0; 1 resets the eye, 2 follows path */
    /* 0x02 */ s16 cam;
    /* 0x04 */ Vec target;
    /* 0x10 */ Vec eye;
    /* 0x1C */ f32 fov;
    /* 0x20 */ f32 nearZ;
    /* 0x24 */ f32 farZ;
    /* 0x28 */ f32 aspect;
    /* 0x2C */ Matrix4f inv;
    /* 0x6C */ Matrix4f view;
    /* 0xAC */ DRCamPath* path;
} DRCam; /* size = 0xB0 */

typedef struct DRPad {
    /* 0x0 */ u16 trg;
    /* 0x2 */ u16 btn;
    /* 0x4 */ s8 stkX;
    /* 0x5 */ s8 stkY;
    /* 0x6 */ u16 dirTrg;
    /* 0x8 */ u16 dir;     /* stick as direction bits 0x100-0x800 */
    /* 0xA */ u16 dirPrev;
} DRPad; /* size = 0xC */

/* The game state (D_8010AE70), Filet Relay's FRGame with another layout. */
typedef struct DRGame {
    /* 0x00 */ u8 state;
    /* 0x01 */ u8 next;
    /* 0x02 */ u8 sub;
    /* 0x03 */ u8 timer;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 time;
    /* 0x08 */ s16 frame;
    /* 0x0A */ s16 count;
    /* 0x0C */ s16 rank[4]; /* coins won by player */
    /* 0x14 */ DRPad pad[4];
} DRGame; /* size = 0x44 */

/* A sprite model of the list at D_8010AEC8. */
typedef struct DRSprMdl {
    /* 0x00 */ s16 flags; /* 1: skip */
    /* 0x02 */ s16 sprite;
    /* 0x04 */ void (*func)(struct DRSprMdl*);
    /* 0x08 */ Vec pos;
    /* 0x14 */ Vec vel;
    /* 0x20 */ Vec unk_20;
    /* 0x2C */ f32 scale;
    /* 0x30 */ u8 alpha;
    /* 0x34 */ struct DRSprMdl* next;
    /* 0x38 */ struct DRSprMdl* prev;
} DRSprMdl; /* size = 0x3C */

void HuVecAdd(Vec*, Vec*, Vec*);
void HuVecAddScaled(Vec*, Vec*, f32, Vec*);
void HuVecCopyXYZ(Vec*, f32, f32, f32);
f32 HuVecDistance(Vec*, Vec*);
f32 HuVecGetLength3F(Vec*);
void HuVecMulScalar(Vec*, f32, Vec*);
void HuVecSubtract(Vec*, Vec*, Vec*);
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size);
f32 HuMathSin(f32);
void HuMemFree(void*);
s16 LoadFormFile(s32, s32);
s32 PlaySound(s32);
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
void omDelObj(omObjData*);
void omSetRot(omObjData*, f32, f32, f32);
void omSetSca(omObjData*, f32, f32, f32);
void omSetTra(omObjData*, f32, f32, f32);
void espDispOff(u16);
void espPosSet(u16 spriteId, s16 x, s16 y);
u16 func_80018A30_19630(s32 file, s32 attr);
u16 func_80018A64_19664(s32 file, s32 attr);
u16 func_80020EBC_21ABC(void* arg0, s32 arg1, u8 arg2);
void* func_80027154_27D54(s32 size, s16 tag);
omObjData** func_80076D80_77980(s32);
u16 func_80078EA8_79AA8(void);
u8 rand8(void);
void func_80029FE4_2ABE4(s16, f32);
void func_80029E80_2AA80(s16, s32, s32);
void func_80029BF0_2A7F0(s16, s16, s16, s16, s16);
void func_8002979C_2A39C(s16, f32, f32, f32);
void func_800298A4_2A4A4(s16, s32, s32);
void func_8002F1A4_2FDA4(void);
void func_8002CA48_2D648(u8, u8, u8);
void func_80029708_2A308(s32);
void func_8002D4D0_2E0D0(s16);
s32 func_8002C8B8_2D4B8(void*, s16);
void func_80076BD0_777D0(s32, s32);
omObjData* func_80076D98_77998(s32, u16);
void func_80029714_2A314(s16, f32, f32, f32);
void func_800297E8_2A3E8(s16, f32, f32, f32);
f32 func_80029CE4_2A8E4(s16);
f32 func_80029D0C_2A90C(s16);
void func_80029C74_2A874(s16, f32);
f32 func_800B75A8_B81A8(f32 y, f32 x);
void func_80079848_7A448(s16);
void func_8002D0A0_2DCA0(s16, u8);

extern u16 D_801011FC_101DFC;
extern u8 D_80102720_103320;
extern s16 D_800FFFD6_100BD6; /* current viewport */
extern f32 D_800FC8F8_FD4F8[][6]; /* per camera: rot, x, z, fov, far, near */
extern s8 ContStkX[4];
extern s8 ContStkY[4];

extern DRObjDef D_8010A060_12D840_DayAtTheRaces[30];
extern void* D_8010A498_12DC78_DayAtTheRaces[];

/* The group's object array, as Speed Hockey's: a struct, so stores through a work pointer reload it. */
typedef struct DRObjs {
    omObjData** objs;
} DRObjs;
extern DRObjs D_8010AC10_12E3F0_DayAtTheRaces; /* the thirty level objects */
extern DRGame D_8010AE70_12E650_DayAtTheRaces;
extern omObjData* D_8010AEB4_12E694_DayAtTheRaces[2]; /* cameras */
extern omObjData* D_8010AEBC_12E69C_DayAtTheRaces;    /* the sprite model object */
extern s32 D_8010AEC0_12E6A0_DayAtTheRaces;           /* the game's own random seed */
extern DRSprMdl D_8010AEC8_12E6A8_DayAtTheRaces;      /* the list's head */
extern DRSprMdl* D_8010AF04_12E6E4_DayAtTheRaces;     /* its tail */

extern DRCamDef D_8010AA60_12E240_DayAtTheRaces[2];
extern DRLight D_8010AAB0_12E290_DayAtTheRaces[2];
extern void (*D_8010AAD0_12E2B0_DayAtTheRaces[3])(DRCam*);
extern void (*D_8010AADC_12E2BC_DayAtTheRaces[9])(omObjData*);

/* main functions without a header */
void func_8002864C_2924C(void);
void func_80026D28_27928(s16);
void func_80026E00_27A00(s16, f32, f32, f32);
void func_80026DAC_279AC(s16, u8, u8, u8);
s16 func_800691FC_69DFC(s16 mesNo, ...);
void func_800211E8_21DE8(s16, u8);
void func_80021160_21D60(s16, s32, s32);
void func_80021250_21E50(s16, u8, u8, u8);
void func_800212A4_21EA4(s16);
s32 func_80069538_6A138(void);
void func_80079614_7A214(s16 time);
void func_800794A8_7A0A8(s32);
void func_80079128_79D28(void);
void func_80020070_20C70(s32);
void func_80020718_21318(s16, void*, void*);
void func_8002EDA8_2F9A8(void);
void func_80020D20_21920(s16);
void func_80023124_23D24(void);
void func_8002308C_23C8C(s16);
s32 func_8008F618_90218(void);
void func_800B3170_B3D70(Vec*, Vec*);
void func_800B33E0_B3FE0(Vec*);
void func_800B1C70_B2870(Mtx*, u16*, f32, f32, f32, f32, f32);
void func_800B2400_B3000(Matrix4f, f32, f32, f32, f32, f32, f32, f32);
void func_800B3040_B3C40(Matrix4f, void*);
s32 func_8003DF08_3EB08(void*);

/* overlay functions used across files */
void func_801036C4_126EA4_DayAtTheRaces(void);
void func_80103688_126E68_DayAtTheRaces(void);
void func_80108374_12BB54_DayAtTheRaces(void);
void func_80108414_12BBF4_DayAtTheRaces(void);
void func_80108458_12BC38_DayAtTheRaces(void);
u16 func_8010868C_12BE6C_DayAtTheRaces(s8 x, s8 y);
void func_80108900_12C0E0_DayAtTheRaces(void);
void func_80108954_12C134_DayAtTheRaces(DRCam* w);
void func_80108BB0_12C390_DayAtTheRaces(Matrix4f in, Matrix4f out);
void func_80108FE4_12C7C4_DayAtTheRaces(omObjData* obj);
void func_80109104_12C8E4_DayAtTheRaces(void);
void func_801095F0_12CDD0_DayAtTheRaces(void);
void func_80109628_12CE08_DayAtTheRaces(void);
void func_801098DC_12D0BC_DayAtTheRaces(void);
void func_80109A90_12D270_DayAtTheRaces(void);
void func_80109AFC_12D2DC_DayAtTheRaces(s32 seed);
s32 func_80109B20_12D300_DayAtTheRaces(void);
s32 func_80109B2C_12D30C_DayAtTheRaces(s32 n);
u16 func_80109BE0_12D3C0_DayAtTheRaces(s32 port);
void func_80109BFC_12D3DC_DayAtTheRaces(s32 cam, Vec* out);
void func_80109C5C_12D43C_DayAtTheRaces(s32 cam, Vec* v);
void func_80109C98_12D478_DayAtTheRaces(s32 cam, Vec* target, Vec* eye, f32 fov, f32 aspect);
void func_80109D40_12D520_DayAtTheRaces(s32 cam, DRCamPath* path);
s32 func_80109D7C_12D55C_DayAtTheRaces(s32 cam);
u8 func_80109DA0_12D580_DayAtTheRaces(void);
void func_80109DAC_12D58C_DayAtTheRaces(u8 state);
u16 func_80109DD8_12D5B8_DayAtTheRaces(void);
s16 func_80109DE4_12D5C4_DayAtTheRaces(s16 i);
void func_80109DFC_12D5DC_DayAtTheRaces(s16 i, s16 v);
DRSprMdl* func_80109E14_12D5F4_DayAtTheRaces(s16 flags, s16 unk, void* func);
void func_80109F64_12D744_DayAtTheRaces(DRSprMdl* m);
void func_80109FC4_12D7A4_DayAtTheRaces(void);
s16 func_8010A018_12D7F8_DayAtTheRaces(s32 file);


#endif
