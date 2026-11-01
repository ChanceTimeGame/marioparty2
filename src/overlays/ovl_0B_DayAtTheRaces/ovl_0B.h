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


#endif
