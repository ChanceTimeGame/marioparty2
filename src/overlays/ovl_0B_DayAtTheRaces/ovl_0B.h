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
    /* 0x0C */ s16 rank[4]; /* by player: the finishing place of the racer bet on */
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

#define DRF_ABS(x) ((x) < 0.0f ? -(x) : (x))

/* A racer's work, omObjData::unk_50, 0x68 bytes (D_8010AC6C keeps a copy for the replay). */
typedef struct DRPlayer {
    /* 0x00 */ s16 mode;  /* index in D_8010A908 */
    /* 0x02 */ s16 index; /* index in D_8010A538 and D_8010A638 */
    /* 0x04 */ s8 port;
    /* 0x05 */ s8 gear;   /* -1 none yet, else 0-2 */
    /* 0x06 */ s8 unk_06;
    /* 0x07 */ s8 rank;   /* finishing place, -1 none */
    /* 0x08 */ f32 x;
    /* 0x0C */ f32 speed;
    /* 0x10 */ f32 boost;
    /* 0x14 */ f32 accel;
    /* 0x18 */ f32 height; /* the bet marker sits this high */
    /* 0x1C */ f32 anim;
    /* 0x20 */ s16 alpha;
    /* 0x22 */ s16 motion;
    /* 0x24 */ s32 timer;
    /* 0x28 */ s32 timer2;
    /* 0x2C */ char unk_2C[8];
    /* 0x34 */ f32 baseX;
    /* 0x38 */ f32 phase;
    /* 0x3C */ f32 baseRot;
    /* 0x40 */ f32 last;
    /* 0x44 */ s8 busy; /* no movement */
    /* 0x45 */ s8 lock; /* no motion change */
    /* 0x46 */ s16 state;
    /* 0x48 */ s32 sub;
    /* 0x4C */ s32 wait;
    /* 0x50 */ s32 unk_50;
    /* 0x54 */ s32 unk_54;
    /* 0x58 */ char unk_58[0x10];
} DRPlayer; /* size = 0x68 */

/* A racer's motion. */
typedef struct DRMotion {
    /* 0x00 */ s32 file;
    /* 0x04 */ void (*func)(omObjData*, DRPlayer*);
    /* 0x08 */ s16 end;
    /* 0x0A */ s16 start; /* < 0: play once */
    /* 0x0C */ s16 loop;
    /* 0x10 */ f32 speed;
} DRMotion; /* size = 0x14 */

/* A racer. */
typedef struct DRChar {
    /* 0x00 */ Vec pos;
    /* 0x0C */ f32 scale;
    /* 0x10 */ Vec shadow;
    /* 0x1C */ f32 height;
    /* 0x20 */ s32 file;
    /* 0x24 */ s32 shadowFile;
    /* 0x28 */ s32 attr;
} DRChar; /* size = 0x2C */

/* The replay's start: what the race state keeps. */
typedef struct DRSave {
    /* 0x0 */ u16 flag;
    /* 0x2 */ u16 frame;
    /* 0x4 */ u16 list[4]; /* frames of the close finishes */
    /* 0xC */ u16 count;
    /* 0xE */ s16 seed;
} DRSave; /* size = 0x10 */

/* The race state, D_8010AC34. */
typedef struct DRRace {
    /* 0x00 */ s8 pick;   /* players who have bet */
    /* 0x01 */ s8 done;   /* racers past the line */
    /* 0x02 */ s16 time;
    /* 0x04 */ s16 photo; /* a close finish: replay */
    /* 0x06 */ s16 replay; /* slow-motion frame */
    /* 0x08 */ s8 mark[4];
    /* 0x0C */ s8 prev[4];
    /* 0x10 */ s32 sub;
    /* 0x14 */ s32 timer;
    /* 0x18 */ f32 camX;
} DRRace; /* size = 0x1C */

typedef struct DRDone {
    /* 0x0 */ s16 mes;
    /* 0x2 */ s16 end;
} DRDone;

/* A player's bet marker, omObjData::unk_50, 0x30 bytes. */
typedef struct DRBet {
    /* 0x00 */ omObjData* target;
    /* 0x04 */ s16 player;
    /* 0x06 */ s16 port;
    /* 0x08 */ char unk_08[2];
    /* 0x0A */ s16 cursor;
    /* 0x0C */ s16 delay;
    /* 0x10 */ s32 state;
    /* 0x14 */ s32 alpha;
    /* 0x18 */ s32 timer;
    /* 0x1C */ char unk_1C[0x14];
} DRBet; /* size = 0x30 */

typedef struct DRMark {
    /* 0x0 */ char unk_00[0xE];
    /* 0xE */ s16 value;
} DRMark;

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
extern DRObjs D_8010AC20_12E400_DayAtTheRaces; /* the four racers */
extern DRObjs D_8010AC24_12E404_DayAtTheRaces;
extern omObjData* D_8010AC28_12E408_DayAtTheRaces; /* the game object */
extern s8 D_8010AC2C_12E40C_DayAtTheRaces[4]; /* who bets when */
extern s8 D_8010AC30_12E410_DayAtTheRaces[4]; /* racer -> bet, -1 free */
extern DRRace D_8010AC34_12E414_DayAtTheRaces;
extern DRSave D_8010AC50_12E430_DayAtTheRaces;
extern s16 D_8010AC60_12E440_DayAtTheRaces[4];
extern u8 D_8010AC68_12E448_DayAtTheRaces[4];
extern DRPlayer D_8010AC6C_12E44C_DayAtTheRaces[4];
extern f32 D_8010AE0C_12E5EC_DayAtTheRaces[4];
extern f32 D_8010AE1C_12E5FC_DayAtTheRaces[4];
extern s16 D_8010AE30_12E610_DayAtTheRaces[9];
extern s32 D_8010AE48_12E628_DayAtTheRaces[4]; /* racers by gear */
extern s32 D_8010AE58_12E638_DayAtTheRaces[4]; /* racers by distance */
extern DRGame D_8010AE70_12E650_DayAtTheRaces;
extern omObjData* D_8010AEB4_12E694_DayAtTheRaces[2]; /* cameras */
extern omObjData* D_8010AEBC_12E69C_DayAtTheRaces;    /* the sprite model object */
extern s32 D_8010AEC0_12E6A0_DayAtTheRaces;           /* the game's own random seed */
extern DRSprMdl D_8010AEC8_12E6A8_DayAtTheRaces;      /* the list's head */
extern DRSprMdl* D_8010AF04_12E6E4_DayAtTheRaces;     /* its tail */

extern s32 D_8010A4C0_12DCA0_DayAtTheRaces[6];
extern u16 D_8010A4D8_12DCB8_DayAtTheRaces[4];
extern u8 D_8010A4E0_12DCC0_DayAtTheRaces[4][8];
extern f32 D_8010A500_12DCE0_DayAtTheRaces[9]; /* lap marks */
extern s16 D_8010A524_12DD04_DayAtTheRaces[10];
extern DRChar D_8010A538_12DD18_DayAtTheRaces[4];
extern f32 D_8010A5E8_12DDC8_DayAtTheRaces[4][5];
extern DRMotion D_8010A638_12DE18_DayAtTheRaces[4][9];
extern void (*D_8010A908_12E0E8_DayAtTheRaces[4])(omObjData*, DRPlayer*);
extern void (*D_8010A918_12E0F8_DayAtTheRaces[6])(omObjData*, DRPlayer*);
extern void (*D_8010A930_12E110_DayAtTheRaces[6])(omObjData*, DRBet*);
extern s32 D_8010A948_12E128_DayAtTheRaces[4];
extern void (*D_8010A958_12E138_DayAtTheRaces[9])(void);
extern DRCamKey D_8010A97C_12E15C_DayAtTheRaces[4];
extern DRCamPath D_8010A9FC_12E1DC_DayAtTheRaces;
extern Vec D_8010AA08_12E1E8_DayAtTheRaces;
extern Vec D_8010AA14_12E1F4_DayAtTheRaces;
extern s32 D_8010AA20_12E200_DayAtTheRaces;
extern s16 D_8010AA24_12E204_DayAtTheRaces;
extern DRDone D_8010AA28_12E208_DayAtTheRaces;
extern Vec D_8010AA2C_12E20C_DayAtTheRaces;
extern Vec D_8010AA38_12E218_DayAtTheRaces;
extern void (*D_8010AA44_12E224_DayAtTheRaces[7])(omObjData*);
extern DRCamDef D_8010AA60_12E240_DayAtTheRaces[2];
extern DRLight D_8010AAB0_12E290_DayAtTheRaces[2];
extern void (*D_8010AAD0_12E2B0_DayAtTheRaces[3])(DRCam*);
extern void (*D_8010AADC_12E2BC_DayAtTheRaces[9])(omObjData*);

/* main functions without a header */
void func_8002864C_2924C(void);
void func_8002D124_2DD24(s16);
f32 func_8002CA14_2D614(s16);
s16 func_800797DC_7A3DC(s32, s16);
void func_800799A4_7A5A4(s16, s32);
void func_800794F0_7A0F0(s32);
void func_8006D4D0_6E0D0(s16);
void func_8006D518_6E118(void);
s32 func_80059FD0_5ABD0(s32);
void func_80029FBC_2ABBC(s16, f32);
f32 func_80029E3C_2AA3C(s16);
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

/* all of the overlay's functions */
void func_80102800_125FE0_DayAtTheRaces(void);
void func_80102850_126030_DayAtTheRaces(omObjData* obj);
void func_801028CC_1260AC_DayAtTheRaces(omObjData* obj);
void func_80102940_126120_DayAtTheRaces(omObjData* obj);
void func_801029C4_1261A4_DayAtTheRaces(omObjData* obj);
void func_80102D08_1264E8_DayAtTheRaces(Vec* pos, Vec* rot);
void func_801031EC_1269CC_DayAtTheRaces(omObjData* obj);
void func_80103368_126B48_DayAtTheRaces(void);
void func_801041B8_127998_DayAtTheRaces(omObjData* obj, DRPlayer* w);
void func_8010430C_127AEC_DayAtTheRaces(omObjData* obj, DRPlayer* w);
void func_801043B4_127B94_DayAtTheRaces(omObjData* obj, DRPlayer* w);
void func_80104424_127C04_DayAtTheRaces(omObjData* obj, DRPlayer* w);
void func_80104494_127C74_DayAtTheRaces(omObjData* obj, DRPlayer* w);
void func_801045B4_127D94_DayAtTheRaces(omObjData* obj, DRPlayer* w);
void func_80104744_127F24_DayAtTheRaces(omObjData* obj, DRPlayer* w);
void func_80104750_127F30_DayAtTheRaces(omObjData* obj, DRPlayer* w);
void func_80104A40_128220_DayAtTheRaces(omObjData* obj, DRPlayer* w);
void func_80104D1C_1284FC_DayAtTheRaces(omObjData* obj, DRPlayer* w);
void func_80105040_128820_DayAtTheRaces(omObjData* obj, DRPlayer* w);
void func_8010537C_128B5C_DayAtTheRaces(omObjData* obj, DRPlayer* w);
void func_801058B4_129094_DayAtTheRaces(void);
void func_80105C84_129464_DayAtTheRaces(void);
omObjData* func_80105D9C_12957C_DayAtTheRaces(s32 i);
void func_80105DC4_1295A4_DayAtTheRaces(void);
omObjData* func_80105E80_129660_DayAtTheRaces(s32 i);
s32 func_80105EA8_129688_DayAtTheRaces(f32 x);
f32 func_80105EF0_1296D0_DayAtTheRaces(DRPlayer* w);
void func_80105F70_129750_DayAtTheRaces(omObjData* obj, DRPlayer* w);
void func_80105FE8_1297C8_DayAtTheRaces(omObjData* obj, DRPlayer* w);
void func_8010603C_12981C_DayAtTheRaces(omObjData* obj, DRPlayer* w);
void func_80106128_129908_DayAtTheRaces(omObjData* obj, DRPlayer* w);
void func_801062A8_129A88_DayAtTheRaces(omObjData* obj, DRPlayer* w);
void func_80106454_129C34_DayAtTheRaces(omObjData* obj, DRPlayer* w);
void func_801066CC_129EAC_DayAtTheRaces(omObjData* obj, DRPlayer* w);
void func_80106704_129EE4_DayAtTheRaces(omObjData* obj, DRPlayer* w);
void func_80106764_129F44_DayAtTheRaces(omObjData* obj);
s16 func_80106D5C_12A53C_DayAtTheRaces(DRBet* w, s32 dir);
void func_80106DE4_12A5C4_DayAtTheRaces(omObjData* obj, DRBet* w);
void func_80107368_12AB48_DayAtTheRaces(omObjData* obj, DRBet* w);
void func_80107400_12ABE0_DayAtTheRaces(omObjData* obj, DRBet* w);
void func_801074A0_12AC80_DayAtTheRaces(omObjData* obj);
void func_80107520_12AD00_DayAtTheRaces(omObjData* obj, s32 i);
void func_801076AC_12AE8C_DayAtTheRaces(void);
void func_80107788_12AF68_DayAtTheRaces(void);
void func_80107894_12B074_DayAtTheRaces(void);
void func_801078B0_12B090_DayAtTheRaces(void);
void func_8010796C_12B14C_DayAtTheRaces(omObjData* obj);
void func_80107A44_12B224_DayAtTheRaces(omObjData* obj);
void func_80107B20_12B300_DayAtTheRaces(s32 i);
void func_80107C5C_12B43C_DayAtTheRaces(void);
void func_80107D10_12B4F0_DayAtTheRaces(omObjData* obj);
void func_80107FF8_12B7D8_DayAtTheRaces(omObjData* obj);
void func_80108034_12B814_DayAtTheRaces(omObjData* obj);
void func_80108304_12BAE4_DayAtTheRaces(omObjData* obj);
void func_80108614_12BDF4_DayAtTheRaces(void);
void func_80108670_12BE50_DayAtTheRaces(void);
void func_8010873C_12BF1C_DayAtTheRaces(void);
void func_801087E0_12BFC0_DayAtTheRaces(void);
void func_80108870_12C050_DayAtTheRaces(void);
void func_801089BC_12C19C_DayAtTheRaces(DRCamPath* p, DRCamKey* out);
void func_80108AF4_12C2D4_DayAtTheRaces(DRCam* w);
void func_80108E20_12C600_DayAtTheRaces(omObjData* obj);
void func_8010909C_12C87C_DayAtTheRaces(s16 n);
void func_80109134_12C914_DayAtTheRaces(omObjData* obj);
void func_80109240_12CA20_DayAtTheRaces(omObjData* obj);
void func_80109248_12CA28_DayAtTheRaces(omObjData* obj);
void func_801092E4_12CAC4_DayAtTheRaces(omObjData* obj);
void func_801092EC_12CACC_DayAtTheRaces(omObjData* obj);
void func_801093E8_12CBC8_DayAtTheRaces(omObjData* obj);
void func_801094AC_12CC8C_DayAtTheRaces(omObjData* obj);
void func_80109570_12CD50_DayAtTheRaces(omObjData* obj);
void func_801095A4_12CD84_DayAtTheRaces(Vec* v);
void func_80109BA4_12D384_DayAtTheRaces(s32 port, s8 stkX, s8 stkY, u16 trg, u16 btn);
void func_801036C4_126EA4_DayAtTheRaces(void);
void func_80103688_126E68_DayAtTheRaces(void);
void func_80103EC4_1276A4_DayAtTheRaces(s32 stop);
void func_80103FF0_1277D0_DayAtTheRaces(omObjData* obj, s32 idx, f32 y, f32 rot, f32 scale, f32 speed);
void func_80104128_127908_DayAtTheRaces(omObjData* obj);
void func_80104364_127B44_DayAtTheRaces(omObjData* obj, DRPlayer* w);
s32 func_801053D0_128BB0_DayAtTheRaces(omObjData* obj, s32 mot);
void func_801055E4_128DC4_DayAtTheRaces(omObjData* obj, s32 mot, f32 t);
s32 func_801057AC_128F8C_DayAtTheRaces(omObjData* obj);
void func_80105894_129074_DayAtTheRaces(omObjData* obj, f32 speed);
void func_80105A94_129274_DayAtTheRaces(void);
void func_80106990_12A170_DayAtTheRaces(omObjData* obj, s32 idx);
void func_80103728_126F08_DayAtTheRaces(void);
void func_80103748_126F28_DayAtTheRaces(void);
void func_80103768_126F48_DayAtTheRaces(void);
void func_80103788_126F68_DayAtTheRaces(void);
void func_80103D5C_12753C_DayAtTheRaces(void);
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
s32 func_80109BE0_12D3C0_DayAtTheRaces(s32 port);
void func_80109BFC_12D3DC_DayAtTheRaces(s32 cam, Vec* out);
void func_80109C5C_12D43C_DayAtTheRaces(s32 cam, Vec* v);
void func_80109C98_12D478_DayAtTheRaces(s32 cam, Vec* target, Vec* eye, f32 fov, f32 aspect);
void func_80109D40_12D520_DayAtTheRaces(s32 cam, DRCamPath* path);
s32 func_80109D7C_12D55C_DayAtTheRaces(s32 cam);
u8 func_80109DA0_12D580_DayAtTheRaces(void);
void func_80109DAC_12D58C_DayAtTheRaces(s32 state);
u16 func_80109DD8_12D5B8_DayAtTheRaces(void);
s16 func_80109DE4_12D5C4_DayAtTheRaces(s16 i);
void func_80109DFC_12D5DC_DayAtTheRaces(s16 i, s16 v);
DRSprMdl* func_80109E14_12D5F4_DayAtTheRaces(s16 flags, s16 unk, void* func);
void func_80109F64_12D744_DayAtTheRaces(DRSprMdl* m);
void func_80109FC4_12D7A4_DayAtTheRaces(void);
s16 func_8010A018_12D7F8_DayAtTheRaces(s32 file);


#endif
