#ifndef _OVL_12_H
#define _OVL_12_H

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/data.h"
#include "game/collision.h"

/* Bob-omb Barrage, a 1 vs 3 minigame: the lone player is Player 0 in the middle of the ring and
   walks; the three others stand on the rim and throw bob-ombs at him. Hit him and the three win;
   if the timer runs out he does. Retail files 160B20.c, 160C10.c (camera), 1610C0.c (flow, timer)
   and 161980.c (from 80103660, the game); .data is asm, .rodata per file from 0x1673B0 and 0x167410. */

/* One bob-omb, 0x58 bytes. State: 0 none, 1 waiting, 2 being fetched, 3 ready, 4 carried, 5 held
   lit, 6 flying, 7 gone, 8 blast, 9 waiting for the next, 10 hit. */
typedef struct BBBomb {
    /* 0x00 */ Vec pos;
    /* 0x0C */ Vec vel;
    /* 0x18 */ s32 t;
    /* 0x1C */ s32 fuse;
    /* 0x20 */ s32 state;
    /* 0x24 */ s16 mdl;    /* unlit */
    /* 0x26 */ s16 lit;
    /* 0x28 */ s16 shadow;
    /* 0x2A */ s16 blast;
    /* 0x2C */ s16 splash;
    /* 0x2E */ char unk_2E[6];
    /* 0x34 */ s16 fx;     /* fuse model-effect */
    /* 0x36 */ char unk_36[0x22];
} BBBomb; /* size = 0x58 */

typedef struct BBAi {
    /* 0x00 */ s32 state;
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
    /* 0x0C */ s32 t;
    /* 0x10 */ s32 time;
    /* 0x14 */ f32 power;
} BBAi;

/* The part of a player the state machines share, 0xCC bytes. */
typedef struct BBActor {
    /* 0x00 */ s32 side;   /* 1 lone, -1 thrower; player 0: 2 once he has sunk */
    /* 0x04 */ s32 t;
    /* 0x08 */ s32 unk_1C;
    /* 0x0C */ s32 state;
    /* 0x10 */ s32 timer;
    /* 0x14 */ s32 held;   /* thrower: bomb index or -1. Player 0: 0 once hit */
    /* 0x18 */ s32 reload;
    union {
        /* 0x1C */ BBBomb bomb[2]; /* throwers */
        /* 0x1C */ s16 dust[10];   /* player 0 */
    } u;
} BBActor; /* size = 0xCC */

/* One player, 0x388 bytes (D_801093A0_1676C0_BobOmbBarrage[4]; the current one is D_80109370_167690_BobOmbBarrage, its index D_8010A1C0_1684E0_BobOmbBarrage). */
typedef struct BBPlayer {
    /* 0x000 */ s32 chr;
    /* 0x004 */ s32 port;
    /* 0x008 */ char unk_08[4];
    /* 0x00C */ s32 diff;
    /* 0x010 */ s32 com;
    /* 0x014 */ BBActor act;
    /* 0x0E0 */ char unk_E0[0x218];
    /* 0x2F8 */ Vec pos;
    /* 0x304 */ Vec vel;
    /* 0x310 */ char unk_310[0xC];
    /* 0x31C */ f32 rot;
    /* 0x320 */ f32 rotShow;
    /* 0x324 */ f32 rotAim;
    /* 0x328 */ f32 power;
    /* 0x32C */ char unk_32C[4];
    /* 0x330 */ s16 mot[12];
    /* 0x348 */ char unk_348[0x24];
    /* 0x36C */ BBAi ai;
    /* 0x384 */ char unk_384[4];
} BBPlayer; /* size = 0x388 */

typedef struct BBTween {
    /* 0x00 */ s32 state;
    /* 0x04 */ s32 t;
    /* 0x08 */ s32 time;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 mode;
    /* 0x14 */ Vec from;
    /* 0x20 */ Vec to;
} BBTween;

/* Player 0's turn or hop, 0x1C bytes. */
typedef struct BBMove {
    /* 0x00 */ s32 state;
    /* 0x04 */ f32 from;
    /* 0x08 */ f32 to;
    /* 0x0C */ s32 t;
    /* 0x10 */ s32 time;
    /* 0x14 */ f32 y;
    /* 0x18 */ f32 height;
} BBMove;

typedef struct BBStart {
    /* 0x00 */ Vec pos;
    /* 0x0C */ f32 rot;
} BBStart;

typedef struct BBScript {
    /* 0x00 */ Vec dir;
    /* 0x0C */ f32 speed;
    /* 0x10 */ s32 time;
} BBScript; /* size = 0x14 */

typedef struct BBSpin {
    /* 0x00 */ f32 from;
    /* 0x04 */ f32 to;
    /* 0x08 */ f32 time;
    /* 0x0C */ char unk_0C[4];
} BBSpin;

typedef struct BBTimer {
    /* 0x00 */ s32 seconds;
    /* 0x04 */ s32 frames;
} BBTimer;

typedef struct BBPair {
    /* 0x00 */ s32 done;
    /* 0x04 */ s32 unk_04;
} BBPair;

/* ---- main-segment API missing from include/ ---- */
extern f32 D_800CA02C_CAC2C;
extern u8 D_800FDEAE_FEAAE;
extern u16 D_801011FC_101DFC;
extern s8 ContStkX[4];
extern s8 ContStkY[4];
extern u16 ContBtn[4];

void func_80020070_20C70(s32);
void func_80020D20_21920(s16 arg0);
void func_80026D28_27928(s32);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void* DataRead(s32 dirAndFile);
u16 LoadFormFile(s32, s32);
void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
s16 func_80027D3C_2893C(s16 linkMdlId); /* model copy */
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void func_8002979C_2A39C(s16 idx, f32 x, f32 y, f32 z); /* model rotation */
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_800298A4_2A4A4(s16, s32, s32); /* model attribute */
void func_80029A8C_2A68C(s16);
void func_80029B80_2A780(s16 arg0, s16 arg1);
void func_80029BF0_2A7F0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void func_80029C74_2A874(s16, f32); /* motion frame */
f32 func_80029CE4_2A8E4(s16);
f32 func_80029D0C_2A90C(s16);
s32 func_80029E14_2AA14(s16 arg0);
f32 func_80029E3C_2AA3C(s16);
void func_80029E80_2AA80(s16, s32, s32);
void func_80029EDC_2AADC(s16 arg0, u8 arg1);
void func_80029F2C_2AB2C(s16, s32);
void func_80029FE4_2ABE4(s16, f32);
void func_8002A00C_2AC0C(s16 model);
void func_8002AC10_2B810(s16 arg0, f32 arg1, f32 arg2, s32 arg3);
void func_8002BCA8_2C8A8(s16 model, f32 s, f32 t, s32 arg3, s32 arg4); /* texture scroll */
void func_8002C628_2D228(s16 arg0, s16 arg1, char* arg2);
void func_8002D4D0_2E0D0(s16 n);
void func_8003E4F4_3F0F4(s16 arg0, u8 arg1, u8 arg2);
void func_8003E52C_3F12C(s16 arg0, u8 arg1);
s16 func_800691FC_69DFC(s16 mesNo, ...); /* MP1 GMesCreate */
s32 func_80069538_6A138(void);           /* MP1 GMesStatAllGet */
s32 func_800696E4_6A2E4(void);           /* MP1 GMesWait */
void func_8006D4D0_6E0D0(s16);           /* the seconds counter */
void func_8006D518_6E118(void);
omObjData* func_800732B0_73EB0(u32 arg0);
s16 func_80079798_7A398(s16 sfx, s16 player);
void func_800797DC_7A3DC(s32, s16);
void func_80079848_7A448(s16 arg0);
void func_80079868_7A468(void);
s32 PlaySound(s32);
void omSetTra(omObjData*, f32, f32, f32);
void omSetSca(omObjData*, f32, f32, f32);
void omSetRot(omObjData*, f32, f32, f32);
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
void HuVecCopyXYZ(Vec*, f32, f32, f32);
void func_800B3170_B3D70(Vec*, Vec*); /* HuVecCopy3F */
f32 func_800B1830_B2430(f32); /* sqrtf */
f32 HuVecGetLength3F(Vec*);
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* cos */
f32 func_800B75A8_B81A8(f32 y, f32 x); /* atan2 */
void Hu3DCamSetPositionOrientation(s16, Vec*, Vec*, Vec*);
void Hu3DCamUpdateMtx(s16 camIndex);

/* ---- .data ---- */
extern f32 D_80108D40_167060_BobOmbBarrage[6]; /* viewport */
extern f32 D_80108D58_167078_BobOmbBarrage[6]; /* scissor */
extern s32* D_80108EEC_16720C_BobOmbBarrage[7]; /* per character: model and motion files */
extern s32 D_80108F08_167228_BobOmbBarrage[6]; /* stage files */
extern BBStart D_80108F20_167240_BobOmbBarrage[4];
extern s32 D_80108F60_167280_BobOmbBarrage[4]; /* per difficulty */
extern s32 D_80108F70_167290_BobOmbBarrage[4];
extern s32 D_80108F80_1672A0_BobOmbBarrage[4];
extern s32 D_80108F90_1672B0_BobOmbBarrage[4];
extern BBScript D_80108FA0_1672C0_BobOmbBarrage[4];
extern BBSpin D_80108FF0_167310_BobOmbBarrage[4];
extern f32 D_80109030_167350_BobOmbBarrage[4];
extern s32 D_80109040_167360_BobOmbBarrage[4];
extern s32 D_80109050_167370_BobOmbBarrage[4];
extern s32 D_80109060_167380_BobOmbBarrage[4];
extern s32 D_80109070_167390_BobOmbBarrage[4];
extern s32 D_80109080_1673A0_BobOmbBarrage[4];

extern const char D_801091A4_1674C4_BobOmbBarrage[]; /* "item_hook" */

/* ---- .bss ---- */
extern f32 D_80109280_1675A0_BobOmbBarrage; /* fov */
extern f32 D_80109284_1675A4_BobOmbBarrage; /* near */
extern f32 D_80109288_1675A8_BobOmbBarrage; /* far */
extern Vec D_8010928C_1675AC_BobOmbBarrage; /* eye */
extern Vec D_80109298_1675B8_BobOmbBarrage; /* at */
extern Vec D_801092A4_1675C4_BobOmbBarrage; /* up */
extern BBTween D_801092B0_1675D0_BobOmbBarrage;
extern s32 D_80109300_167620_BobOmbBarrage;
extern s32 D_80109304_167624_BobOmbBarrage;
extern s32 D_80109308_167628_BobOmbBarrage;
extern s16 D_8010930C_16762C_BobOmbBarrage;
extern BBTimer D_80109310_167630_BobOmbBarrage;
extern s32 D_80109318_167638_BobOmbBarrage;
extern s32 D_8010931C_16763C_BobOmbBarrage; /* _CheckFlag(0xC) */
extern BBPair D_80109320_167640_BobOmbBarrage[4];
extern f32 D_80109340_167660_BobOmbBarrage; /* stage texture scroll */
extern f32 D_80109344_167664_BobOmbBarrage;
extern s32 D_80109348_167668_BobOmbBarrage;
extern s32 D_8010934C_16766C_BobOmbBarrage;
extern f32 D_80109350_167670_BobOmbBarrage;
extern s32 D_80109358_167678_BobOmbBarrage[4]; /* player order: [0] is the lone player */
extern BBPlayer* D_80109370_167690_BobOmbBarrage;
extern BBMove D_80109378_167698_BobOmbBarrage;
extern s32 D_80109394_1676B4_BobOmbBarrage; /* flow state */
extern BBPlayer D_801093A0_1676C0_BobOmbBarrage[4];
extern s32 D_8010A1C0_1684E0_BobOmbBarrage; /* current player index. D_8010A1C2_1684E2_BobOmbBarrage is its low half */
extern s32 D_8010A1C4_1684E4_BobOmbBarrage;
extern omObjData* D_8010A1C8_1684E8_BobOmbBarrage[5];

void func_80102800_160B20_BobOmbBarrage(void);
void func_8010281C_160B3C_BobOmbBarrage(void);
omObjData* func_801028F0_160C10_BobOmbBarrage(void);
void func_80102B2C_160E4C_BobOmbBarrage(omObjData* obj);
void func_80102B50_160E70_BobOmbBarrage(omObjData* obj);
void func_80102C04_160F24_BobOmbBarrage(Vec* eye, Vec* at, s32 time, s32 mode);
void func_80102C64_160F84_BobOmbBarrage(void);
void func_80102C74_160F94_BobOmbBarrage(void);
s32 func_80102D94_1610B4_BobOmbBarrage(void);
void func_80102DA0_1610C0_BobOmbBarrage(void);
omObjData* func_80102E14_161134_BobOmbBarrage(void);
void func_80102E60_161180_BobOmbBarrage(omObjData* obj);
void func_80102E78_161198_BobOmbBarrage(void);
void func_80102EC8_1611E8_BobOmbBarrage(omObjData* obj);
omObjData* func_801033A8_1616C8_BobOmbBarrage(void);
void func_801033F4_161714_BobOmbBarrage(omObjData* obj);
void func_8010340C_16172C_BobOmbBarrage(omObjData* obj);
void func_8010359C_1618BC_BobOmbBarrage(s32 seconds);
s32 func_801035B4_1618D4_BobOmbBarrage(void);
s32 func_801035C0_1618E0_BobOmbBarrage(void);
void func_801035F8_161918_BobOmbBarrage(s32 arg0);
s32 func_80103604_161924_BobOmbBarrage(void);
void func_80103610_161930_BobOmbBarrage(void);
void func_80103628_161948_BobOmbBarrage(void);
s32 func_8010364C_16196C_BobOmbBarrage(void);
void func_80103660_161980_BobOmbBarrage(void);
omObjData* func_801036A0_1619C0_BobOmbBarrage(void);
void func_801036F0_161A10_BobOmbBarrage(omObjData* obj);
void func_80103D58_162078_BobOmbBarrage(omObjData* obj);
void func_80103DDC_1620FC_BobOmbBarrage(void);
void func_80103DE4_162104_BobOmbBarrage(omObjData* obj);
omObjData* func_80103DF4_162114_BobOmbBarrage(void);
omObjData* func_80103E40_162160_BobOmbBarrage(void);
void func_80103E9C_1621BC_BobOmbBarrage(omObjData* obj);
void func_80104778_162A98_BobOmbBarrage(void);
void func_80104850_162B70_BobOmbBarrage(s32 slot);
void func_801049E0_162D00_BobOmbBarrage(f32 x, f32 y, u16 btn);
void func_8010561C_16393C_BobOmbBarrage(void);
void func_801056D4_1639F4_BobOmbBarrage(void);
void func_80105754_163A74_BobOmbBarrage(void);
void func_80105964_163C84_BobOmbBarrage(Vec* dir, f32 speed, s32 time);
void func_801059E4_163D04_BobOmbBarrage(void);
void func_80106150_164470_BobOmbBarrage(void);
void func_8010684C_164B6C_BobOmbBarrage(void);
void func_80107700_165A20_BobOmbBarrage(s32 slot);
s32 func_80108114_166434_BobOmbBarrage(BBBomb* b);
s32 func_80108308_166628_BobOmbBarrage(BBBomb* b);
s32 func_80108414_166734_BobOmbBarrage(s16 mdl, s16 mot);
f32 func_801084A4_1667C4_BobOmbBarrage(void);
void func_801084E0_166800_BobOmbBarrage(void);
void func_801085DC_1668FC_BobOmbBarrage(void);
void func_8010868C_1669AC_BobOmbBarrage(void);
void func_80108844_166B64_BobOmbBarrage(void);
void func_80108998_166CB8_BobOmbBarrage(void);
void func_801089B4_166CD4_BobOmbBarrage(void);
void func_801089C4_166CE4_BobOmbBarrage(f32 from, f32 to, s32 time);
void func_801089E4_166D04_BobOmbBarrage(void);
void func_80108AB0_166DD0_BobOmbBarrage(f32 height, s32 time);
void func_80108AD4_166DF4_BobOmbBarrage(void);
s32 func_80108B80_166EA0_BobOmbBarrage(void);
void func_80108BCC_166EEC_BobOmbBarrage(void);
s32 func_80108D24_167044_BobOmbBarrage(s32 i);

#endif
