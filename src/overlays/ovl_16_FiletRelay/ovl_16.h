#ifndef _OVL_16_H
#define _OVL_16_H

/* Overlay 16: Filet Relay (one against three, two lanes, two cameras). No MP1 ancestor; its frame
   is Speed Hockey's (ovl_1D). Four retail files:
   17A5B0.c (the entry point alone), 17A600.c (from 80102850: ray test, level objects),
   17C100.c (from 80104350: the two fish, the four penguins, CPU control),
   17EFA0.c (from 801071F0: game state machine, two cameras, lights, pads, sprite models).
   .data stays asm (180A20.data.s; 17EFA0.c's from 801093C0); .rodata is carved per file
   ([0x181210, .rodata, 17A600], [0x181228, .rodata, 17C100], [0x1813F0, .rodata, 17EFA0]). */

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/data.h"
#include "game/collision.h"

typedef f32 Matrix4f[4][4];

#define FR_ABS(x) ((x) < 0.0f ? -(x) : (x))

/* ---------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------- */

/* A segment and what it hit: func_80102CFC_17AAAC. Vertex and face data come from the model file. */
typedef struct FRRay {
    /* 0x00 */ Vec start;
    /* 0x0C */ Vec end;
    /* 0x18 */ Vec normal;
    /* 0x24 */ Vec hit;
} FRRay; /* size = 0x30 */

typedef struct FRMotion {
    /* 0x0 */ f32 length;
    /* 0x4 */ s16 loop; /* -1: play once, else repeat from this frame */
} FRMotion; /* size = 0x8 */

/* A level object's work, omObjData::unk_50, 0x58 bytes. */
typedef struct FRObjWork {
    /* 0x00 */ s32 motion;
    /* 0x04 */ FRMotion motions[3];
    /* 0x1C */ Vec pos;
    /* 0x28 */ Vec vel;
    /* 0x34 */ Vec acc;
    /* 0x40 */ s16 state;
    /* 0x42 */ s16 timer; /* thrown objects: the side */
    /* 0x44 */ s16 wait;  /* thrown objects: toggles the throw speed */
    /* 0x46 */ s16 index; /* the thrower's object */
    /* 0x48 */ f32 angle;
    /* 0x4C */ char unk_4C[0xC];
} FRObjWork; /* size = 0x58 */

/* One of the level's thirty objects. */
typedef struct FRObjDef {
    /* 0x00 */ Vec pos;
    /* 0x0C */ Vec rot;
    /* 0x18 */ f32 scale;
    /* 0x1C */ s32 file;
    /* 0x20 */ s32 attr;
    /* 0x24 */ u16 solid; /* bit 0: the model is a wall for the ray test */
    /* 0x26 */ u16 func;  /* index in D_80109148 */
} FRObjDef; /* size = 0x28 */

typedef struct FRSprDef {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ s32 file;
    /* 0x8 */ s32 visible;
    /* 0xC */ u16 prio;
} FRSprDef; /* size = 0x10 */

typedef struct FRMotDef {
    /* 0x0 */ s32 file;
    /* 0x4 */ u16 loop;
} FRMotDef; /* size = 0x8 */

/* A fish, omObjData::unk_50, 0x50 bytes. */
typedef struct FRFish {
    /* 0x00 */ Vec pos;
    /* 0x0C */ Vec vel;
    /* 0x18 */ Vec rot;
    /* 0x24 */ Vec rotVel;
    /* 0x30 */ s32 flying;
    /* 0x34 */ char unk_34[0x1C];
} FRFish; /* size = 0x50 */

/* A penguin, omObjData::unk_50, 0x100 bytes. */
typedef struct FRPlayer {
    /* 0x00 */ u16 flags; /* 1 on the ice, 4 no ray test */
    /* 0x02 */ s16 player;
    /* 0x04 */ s8 port;
    /* 0x05 */ s8 pan;
    /* 0x06 */ s8 team;
    /* 0x07 */ s8 order; /* -1 the solo player, else 0-2 along the relay */
    /* 0x08 */ s8 cam;
    /* 0x09 */ u8 character;
    /* 0x0C */ Vec pos;
    /* 0x18 */ Vec next;
    /* 0x24 */ Vec vel;
    /* 0x30 */ Vec acc;
    /* 0x3C */ Vec normal;
    /* 0x48 */ Vec hitPos;
    /* 0x54 */ f32 speed;
    /* 0x58 */ f32 goal;   /* z of the end of the leg */
    /* 0x5C */ f32 radius;
    /* 0x60 */ s16 unk_60; /* -1, never read */
    /* 0x62 */ s16 state;  /* index in D_80109364 */
    /* 0x64 */ s32 motion;
    /* 0x68 */ f32 step;   /* walked distance, for the footsteps */
    /* 0x6C */ FRMotion motions[12];
    /* 0xCC */ s16 unk_CC;
    /* 0xCE */ s16 cpu;    /* index in D_80109190 */
    /* 0xD0 */ s16 cpuTimer;
    /* 0xD2 */ char unk_D2;
    /* 0xD3 */ s8 cpuStick;
    /* 0xD4 */ f32 cpuTarget;
    /* 0xD8 */ f32 cpuSpeed;
    /* 0xDC */ s32 sub;
    /* 0xE0 */ s32 timer;
    /* 0xE4 */ s32 timer2;
    /* 0xE8 */ s32 slip;   /* frames over the fall speed */
    /* 0xEC */ f32 angle;  /* also the blink phase, the wobble phase */
    /* 0xF0 */ f32 turn;   /* also the wobble size */
    /* 0xF4 */ f32 turnStep;
    /* 0xF8 */ f32 wobbleGrow;
    /* 0xFC */ s16 endState;
} FRPlayer; /* size = 0x100 */

/* CPU difficulty. */
typedef struct FRCpu {
    /* 0x0 */ s8 hold;   /* frames between A presses */
    /* 0x1 */ s8 stick;
    /* 0x2 */ u8 unk_02;
    /* 0x3 */ s8 chance; /* out of 10 no steering, out of 25 press A anyway */
    /* 0x4 */ f32 speed;
    /* 0x8 */ f32 margin;
} FRCpu; /* size = 0xC */

/* A stretch of the course a CPU follows. */
typedef struct FRZone {
    /* 0x00 */ f32 zMin;
    /* 0x04 */ f32 zMax;
    /* 0x08 */ f32 x;
    /* 0x0C */ f32 jitter;
    /* 0x10 */ f32 speed; /* > 0: overrides the CPU's */
    /* 0x14 */ s32 valid; /* 0 ends the table */
} FRZone; /* size = 0x18 */

typedef struct FRChar {
    /* 0x0 */ s32 model;
    /* 0x4 */ s32 unk_04;
    /* 0x8 */ s32 sprite;
    /* 0xC */ f32 radius;
} FRChar; /* size = 0x10 */

/* A camera's definition. */
typedef struct FRCamDef {
    /* 0x00 */ Vec start;
    /* 0x0C */ Vec eye;
    /* 0x18 */ s16 vp[4];
    /* 0x20 */ s16 scissor[4];
} FRCamDef; /* size = 0x28 */

typedef struct FRLight {
    /* 0x0 */ u8 dir[3];
    /* 0x4 */ f32 color[3];
} FRLight; /* size = 0x10 */

/* A camera object's work, 0x104 bytes: it trails the target through a ring of eight positions. */
typedef struct FRCam {
    /* 0x00 */ s16 mode;  /* index in D_80109448; 1: resets to the start's eye */
    /* 0x02 */ char unk_02[2];
    /* 0x04 */ s16 cam;
    /* 0x06 */ s16 head;
    /* 0x08 */ Vec ring[8];
    /* 0x68 */ Vec eye;
    /* 0x74 */ f32 fov;
    /* 0x78 */ f32 nearZ;
    /* 0x7C */ f32 farZ;
    /* 0x80 */ f32 aspect;
    /* 0x84 */ Matrix4f inv;
    /* 0xC4 */ Matrix4f view;
} FRCam; /* size = 0x104 */

typedef struct FRPad {
    /* 0x0 */ u16 trg;
    /* 0x2 */ u16 btn;
    /* 0x4 */ s8 stkX;
    /* 0x5 */ s8 stkY;
} FRPad; /* size = 0x6 */

/* The game state (D_801096A0), Speed Hockey's SHGame with three winners. */
typedef struct FRGame {
    /* 0x00 */ u8 state;
    /* 0x01 */ u8 next;
    /* 0x02 */ u8 sub;
    /* 0x04 */ s32 timer;
    /* 0x08 */ s16 countdown;
    /* 0x0A */ s16 time;
    /* 0x0C */ s16 winner[3];
    /* 0x12 */ s16 winnerCount;
    /* 0x14 */ s16 winTeam;
    /* 0x16 */ s16 frame;
    /* 0x18 */ FRPad pad[4];
} FRGame; /* size = 0x30 */

/* A sprite model of the list at D_801096E0. */
typedef struct FRSprMdl {
    /* 0x00 */ s16 flags; /* 1: skip */
    /* 0x02 */ s16 sprite;
    /* 0x04 */ void (*func)(struct FRSprMdl*);
    /* 0x08 */ Vec pos;
    /* 0x14 */ Vec vel;
    /* 0x20 */ Vec unk_20;
    /* 0x2C */ f32 scale;
    /* 0x30 */ u8 alpha;
    /* 0x34 */ struct FRSprMdl* next;
    /* 0x38 */ struct FRSprMdl* prev;
} FRSprMdl; /* size = 0x3C */

/* ---------------------------------------------------------------------------------------
   main-segment API missing from include/
   --------------------------------------------------------------------------------------- */

void HuVecAdd(Vec*, Vec*, Vec*);
void HuVecAddScaled(Vec*, Vec*, f32, Vec*);
void HuVecCopyXYZ(Vec*, f32, f32, f32);
f32 HuVecDistance(Vec*, Vec*);
f32 HuVecGetLength3F(Vec*);
void HuVecMulScalar(Vec*, f32, Vec*);
void HuVecSubtract(Vec*, Vec*, Vec*);
void func_800B3170_B3D70(Vec*, Vec*); /* copy */
void func_800B33E0_B3FE0(Vec*);       /* normalise */
f32 func_800B3500_B4100(Vec*, Vec*);  /* dot */
void func_800B3530_B4130(Vec*, Vec*, Vec*); /* cross */
f32 func_800B75A8_B81A8(f32 y, f32 x); /* atan2, degrees */
void func_800B1C70_B2870(Mtx*, u16*, f32, f32, f32, f32, f32); /* guPerspective */
void func_800B2400_B3000(Matrix4f, f32, f32, f32, f32, f32, f32, f32); /* lookat */
void func_800B3040_B3C40(Matrix4f m, Mtx* mtx);
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
s16 func_8001A2F8_1AEF8(s32 arg0);
void func_8001A788_1B388(u16, s32);
void func_8001A91C_1B51C(u16 spriteId, f32 x, f32 y);
s32 func_8001AAAC_1B6AC(s16, s32, s32); /* main: s16; only the low half is used */
void func_8001AC44_1B844(u16);
void func_80020070_20C70(s32);
void func_80020718_21318(s16, void*, void*);
void func_80020D20_21920(s16 arg0);
u16 func_80020EBC_21ABC(void* arg0, s32 arg1, u8 arg2);
void func_80021160_21D60(s16 index, s32 arg1, s32 arg2);
void func_800211E8_21DE8(s16 index, u8 arg1);
void func_80021250_21E50(s16 index, u8 arg1, u8 arg2, u8 arg3);
void func_800212A4_21EA4(s16 index);
void func_8002308C_23C8C(s32);
void func_80023124_23D24(void);
void func_80026D28_27928(s32);
void func_80026DAC_279AC(s16, u8, u8, u8);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void* func_80027154_27D54(s32 size, s16 tag);
void func_8002864C_2924C(void);
void func_80029708_2A308(s32);
void func_80029714_2A314(s16, f32, f32, f32);
void func_800297E8_2A3E8(s16, f32, f32, f32);
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029BF0_2A7F0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
f32 func_80029CE4_2A8E4(s16);
f32 func_80029E3C_2AA3C(s16 idx);
void func_80029FBC_2ABBC(s16, f32);
void func_80029FE4_2ABE4(s16, f32);
void func_8002C59C_2D19C(s32, s32, s32, s32, s32);
void func_8002C628_2D228(s16 arg0, s16 arg1, char* arg2);
s32 func_8002C8B8_2D4B8(void*, s16);
f32 func_8002CA14_2D614(s16);
void func_8002CA48_2D648(u8 arg0, u8 arg1, u8 arg2);
void func_8002D4D0_2E0D0(s16 n);
void func_8002EDA8_2F9A8(void);
void func_8002F1A4_2FDA4(void);
void func_8002F290_2FE90(s32* arg0, s32 n);
void func_8003C8E0_3D4E0(s16);
s16 func_8003DF08_3EB08(void*);
s16 func_800691FC_69DFC(s16 mesNo, ...);
s32 func_80069538_6A138(void);
void func_8006D4D0_6E0D0(s16);
void func_8006D518_6E118(void);
void func_80076BD0_777D0(s32, s32);
omObjData** func_80076D80_77980(s32);
omObjData* func_80076D98_77998(s32, u16);
u16 func_80078EA8_79AA8(void);
void func_800795D8_7A1D8(s16 sound, s8 volume);
void func_80079718_7A318(s32, s32);
s16 func_80079798_7A398(s16 sfx, s16 player);
void func_800798F8_7A4F8(s16 sound, s16 pan);

extern u16 D_801011FC_101DFC;
extern u8 D_80102720_103320;
extern s16 D_800FFFD6_100BD6; /* current viewport */
extern f32 D_800FC8F8_FD4F8[][6]; /* per camera: rot, x, z, fov, far, near */
extern s8 ContStkX[4];
extern s8 ContStkY[4];

/* ---------------------------------------------------------------------------------------
   .data (asm; 17A600.c's and 17C100.c's, then 17EFA0.c's from 801093C0)
   --------------------------------------------------------------------------------------- */

extern FRObjDef D_80108C70_180A20_FiletRelay[30];
extern FRSprDef D_80109120_180ED0_FiletRelay[1];
extern FRMotDef D_80109130_180EE0_FiletRelay[3];
extern void* D_80109148_180EF8_FiletRelay[6];
extern Vec D_80109160_180F10_FiletRelay[4]; /* start positions, by order + 1 */
extern FRCpu D_80109190_180F40_FiletRelay[4];
extern FRZone D_801091C0_180F70_FiletRelay[];
extern u8 D_80109250_181000_FiletRelay[6][3];
/* The goal z by order: [-1] is 80109264, -1140, inside D_80109250's block. */
extern f32 D_80109268_181018_FiletRelay[];
extern f32 D_80109270_181020_FiletRelay; /* = D_80109268[2] */
extern FRChar D_80109274_181024_FiletRelay[6];
extern FRMotDef D_801092D4_181084_FiletRelay[12];
extern Vec D_80109334_1810E4_FiletRelay;
extern Vec D_80109340_1810F0_FiletRelay;
extern Vec D_8010934C_1810FC_FiletRelay;
extern Vec D_80109358_181108_FiletRelay;
extern void (*D_80109364_181114_FiletRelay[7])(omObjData*, FRPlayer*);
extern Vec D_80109380_181130_FiletRelay;
extern Vec D_8010938C_18113C_FiletRelay;
extern void (*D_80109398_181148_FiletRelay[5])(omObjData*, FRPlayer*);
extern s32 D_801093AC_18115C_FiletRelay[2];
extern f32 D_801093C0_181170_FiletRelay;
extern FRCamDef D_801093C4_181174_FiletRelay[2];
extern FRLight D_80109414_1811C4_FiletRelay[2];
extern void (*D_80109434_1811E4_FiletRelay[5])(omObjData*);
extern void (*D_80109448_1811F8_FiletRelay[6])(FRCam*);

/* ---------------------------------------------------------------------------------------
   .bss
   --------------------------------------------------------------------------------------- */

/* The group's object array, as Speed Hockey's: a struct, so stores through a work pointer reload
   it. */
typedef struct FRObjs {
    omObjData** objs;
} FRObjs;
extern FRObjs D_80109670_181420_FiletRelay; /* the thirty level objects */
extern s16 D_80109674_181424_FiletRelay[2];      /* the score sprite */
extern s32 D_80109678_181428_FiletRelay[2];      /* the ray test's HitList (2E0D0.c): a pointer inside */
extern FRObjs D_80109680_181430_FiletRelay;      /* the four penguins */
extern s16 D_80109684_181434_FiletRelay[4];      /* their map sprites */
extern FRObjs D_8010968C_18143C_FiletRelay;      /* the two fish */
extern s32 D_80109690_181440_FiletRelay;         /* which D_80109250 order */
extern s32 D_80109694_181444_FiletRelay;         /* relay penguins so far */
extern FRGame D_801096A0_181450_FiletRelay;
extern omObjData* D_801096D0_181480_FiletRelay[2]; /* cameras */
extern omObjData* D_801096D8_181488_FiletRelay;    /* the sprite model object */
extern FRSprMdl D_801096E0_181490_FiletRelay;      /* the list's head */
extern FRSprMdl* D_8010971C_1814CC_FiletRelay;     /* its tail */

/* ---------------------------------------------------------------------------------------
   Functions
   --------------------------------------------------------------------------------------- */

void func_80102800_17A5B0_FiletRelay(void);
void func_80102850_17A600_FiletRelay(Vec* out, Vec* a, Vec* b, Vec* c);
s32 func_801028F4_17A6A4_FiletRelay(s32 n, Vec* v, Vec* normal, Vec* p);
s32 func_80102AD4_17A884_FiletRelay(FRRay* ray, ColVtx* vtx, ColTri* face);
s32 func_80102CD8_17AA88_FiletRelay(s32 model, s16* v);
s32 func_80102CEC_17AA9C_FiletRelay(s32 model, s16* v);
s32 func_80102CFC_17AAAC_FiletRelay(FRRay* ray, void* filter);
void func_80102EB4_17AC64_FiletRelay(omObjData* obj, s32 motion, f32 speed);
s32 func_80102FC0_17AD70_FiletRelay(omObjData* obj);
s32 func_8010307C_17AE2C_FiletRelay(s32 i);
void func_8010309C_17AE4C_FiletRelay(s32 i);
void func_8010317C_17AF2C_FiletRelay(omObjData* obj);
void func_801033D8_17B188_FiletRelay(omObjData* obj);
void func_8010354C_17B2FC_FiletRelay(omObjData* obj);
void func_801036E8_17B498_FiletRelay(omObjData* obj);
void func_80103A30_17B7E0_FiletRelay(void);
void func_80103CF0_17BAA0_FiletRelay(void);
void func_80103DF0_17BBA0_FiletRelay(void);
void func_80103E44_17BBF4_FiletRelay(void);
s32 func_80103EE0_17BC90_FiletRelay(Vec* pos, f32 radius, Vec* out);
void func_80103FF8_17BDA8_FiletRelay(void);
s32 func_80104034_17BDE4_FiletRelay(FRRay* ray);
s32 func_80104054_17BE04_FiletRelay(FRRay* ray);
s32 func_80104074_17BE24_FiletRelay(Vec* from, Vec* to, Vec* vel, Vec* normal, f32* speed);
void func_801042D0_17C080_FiletRelay(s32 i, s16 x, s16 y, f32 scale);
void func_80104350_17C100_FiletRelay(omObjData* obj);
void func_80104488_17C238_FiletRelay(s32 i, Vec* pos, Vec* vel, Vec* rotVel);
void func_80104508_17C2B8_FiletRelay(s32 i, s16 model);
void func_80104578_17C328_FiletRelay(s32 i);
void func_801045C8_17C378_FiletRelay(omObjData* obj);
s32 func_8010474C_17C4FC_FiletRelay(omObjData* obj, s32 motion);
s32 func_8010483C_17C5EC_FiletRelay(omObjData* obj);
void func_801048F8_17C6A8_FiletRelay(omObjData* obj, f32 speed);
FRPlayer* func_80104930_17C6E0_FiletRelay(s16 player);
FRPlayer* func_801049AC_17C75C_FiletRelay(s8 order);
FRPlayer* func_801049FC_17C7AC_FiletRelay(FRPlayer* w);
void func_80104AE0_17C890_FiletRelay(FRPlayer* w);
s32 func_80104CA0_17CA50_FiletRelay(FRCpu* cpu, FRPlayer* w);
void func_80104EC8_17CC78_FiletRelay(omObjData* obj, FRPlayer* w);
void func_801052DC_17D08C_FiletRelay(omObjData* obj, FRPlayer* w);
void func_80105384_17D134_FiletRelay(omObjData* obj, FRPlayer* w);
void func_80105800_17D5B0_FiletRelay(omObjData* obj, FRPlayer* w);
void func_80105A4C_17D7FC_FiletRelay(omObjData* obj, FRPlayer* w);
void func_80105BA0_17D950_FiletRelay(omObjData* obj, FRPlayer* w);
void func_80105CAC_17DA5C_FiletRelay(omObjData* obj, FRPlayer* w);
void func_80105EEC_17DC9C_FiletRelay(omObjData* obj, FRPlayer* w);
void func_801060A4_17DE54_FiletRelay(omObjData* obj, FRPlayer* w);
void func_801060D4_17DE84_FiletRelay(omObjData* obj, FRPlayer* w);
void func_80106314_17E0C4_FiletRelay(omObjData* obj, FRPlayer* w);
void func_80106A2C_17E7DC_FiletRelay(omObjData* obj);
void func_80106AD8_17E888_FiletRelay(omObjData* obj, s32 player);
void func_80106F38_17ECE8_FiletRelay(void);
void func_80107018_17EDC8_FiletRelay(void);
void func_8010707C_17EE2C_FiletRelay(void);
void func_801071A8_17EF58_FiletRelay(void);
void func_801071F0_17EFA0_FiletRelay(void);
void func_8010720C_17EFBC_FiletRelay(void);
void func_8010729C_17F04C_FiletRelay(void);
void func_8010732C_17F0DC_FiletRelay(void);
void func_80107380_17F130_FiletRelay(omObjData* obj);
void func_80107438_17F1E8_FiletRelay(s16 n);
void func_801074A0_17F250_FiletRelay(void);
void func_801074D0_17F280_FiletRelay(omObjData* obj);
void func_801075BC_17F36C_FiletRelay(omObjData* obj);
void func_80107618_17F3C8_FiletRelay(omObjData* obj);
void func_801076EC_17F49C_FiletRelay(omObjData* obj);
void func_80107A3C_17F7EC_FiletRelay(omObjData* obj);
void func_80107AF8_17F8A8_FiletRelay(omObjData* obj);
void func_80107BAC_17F95C_FiletRelay(omObjData* obj);
void func_80107BDC_17F98C_FiletRelay(FRCam* w);
void func_80107C44_17F9F4_FiletRelay(FRCam* w);
void func_80107C4C_17F9FC_FiletRelay(Matrix4f in, Matrix4f out);
void func_80107EBC_17FC6C_FiletRelay(omObjData* obj);
void func_801080E0_17FE90_FiletRelay(Vec* v);
void func_8010812C_17FEDC_FiletRelay(void);
void func_80108164_17FF14_FiletRelay(void);
void func_80108458_180208_FiletRelay(void);
void func_8010860C_1803BC_FiletRelay(void);
void func_80108678_180428_FiletRelay(s32 port, s8 stkX, s8 stkY, u16 trg, u16 btn);
void func_801086B4_180464_FiletRelay(s32 cam, Vec* out);
void func_80108714_1804C4_FiletRelay(s32 cam, Vec* out);
void func_80108770_180520_FiletRelay(s32 cam, Vec* pos, Vec* eye, f32 fov, f32 aspect);
void func_801088A4_180654_FiletRelay(s32 cam, Vec* pos, Vec* eye, f32 fov, f32 aspect);
u8 func_80108990_180740_FiletRelay(void);
void func_8010899C_18074C_FiletRelay(u8 state);
void func_801089C8_180778_FiletRelay(s16 team);
s16 func_801089D4_180784_FiletRelay(void);
void func_801089E0_180790_FiletRelay(s16 player);
FRSprMdl* func_80108A1C_1807CC_FiletRelay(s16 flags, s16 unk, void* func);
void func_80108B6C_18091C_FiletRelay(FRSprMdl* m);
void func_80108BCC_18097C_FiletRelay(void);
s16 func_80108C20_1809D0_FiletRelay(s32 file);

#endif
