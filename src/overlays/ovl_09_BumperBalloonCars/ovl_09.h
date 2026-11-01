#ifndef _OVL_09_H
#define _OVL_09_H

/* Overlay 09: Bumper Balloon Cars. 4P free-for-all on a round rink (radius 460, cars kept inside
   459), split-free. Each car tows a balloon on its tail; a nose into it pops the balloon and the car
   spins off and flies away (func_8010765C_12076C_BumperBalloonCars). A plain bump only stuns. Same engine as Driver's Ed
   (ovl_33): the signal, the dust and the D_801086E0_1217F0_BumperBalloonCars table. Phases D_801086D2_1217E2_BumperBalloonCars: 0 the signal comes
   down (func_80103300_11C410_BumperBalloonCars), 1 "ready" (func_80103DB0_11CEC0_BumperBalloonCars), 2 play (func_80103BDC_11CCEC_BumperBalloonCars: 30 s, or until three are
   out), 3 and 4 the finish (func_80103A10_11CB20_BumperBalloonCars), 5 fade out and omOvlReturnEx(1). The result goes to
   gPlayers[].coins_mg_bonus as a placing, 0 first (func_80103AC8_11CBD8_BumperBalloonCars), not as coins. Retail is two
   files: 11B910.c and 121510.c (the two table clears, from 80108400, 16-aligned so no pad);
   .data is asm, .rodata is carved from 0x121680 (11B910.c only).
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

/* Angle wrap into [0, 360); the argument is evaluated again in every arm, as retail does. */
#define BBC_WRAP(a) ((a) >= 360.0f ? (a) - 360.0f : (a) < 0.0f ? (a) + 360.0f : (a))

/* One entry of D_801086E0_1217F0_BumperBalloonCars[50] (cleared by func_80108400_121510_BumperBalloonCars). 0-3 the cars, 5 the signal, 10 the
   arena, 15 the banner. Same layout as Driver's Ed's DEObj. */
typedef struct BBCObj {
    /* 0x00 */ omObjData* obj;
    /* 0x04 */ s16 spr;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ f32 x;     /* car: copy of its position */
    /* 0x0C */ f32 y;
    /* 0x10 */ f32 z;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s16 unk_20[2];
    /* 0x24 */ s32 unk_24[2];
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30[4][4];
    /* 0x70 */ u16 stun;     /* signal: frame count; car: frames left of a bump */
    /* 0x72 */ u16 out;      /* signal: bob direction; car: popped */
    /* 0x74 */ u16 dust;     /* dust cadence while driving */
    /* 0x76 */ u16 gone;     /* flown away */
    /* 0x78 */ u16 shadow;   /* the shadow's shrink timer */
    /* 0x7A */ u16 smoke;    /* smoke cadence */
    /* 0x7C */ u16 cpuWait;  /* COM: frames before it reacts again */
    /* 0x7E */ u16 cpuHold;  /* COM: frames it keeps its stick */
    /* 0x80 */ s16 lift;     /* signal: bob; car: lift-off height */
    /* 0x82 */ s16 unk_82;
    /* 0x84 */ s16 cpuHit;   /* COM: was bumped this frame */
    /* 0x86 */ s16 rumble;
    /* 0x88 */ f32 size;     /* signal: shadow scale */
    /* 0x8C */ s32 unk_8C;
    /* 0x90 */ s32 unk_90;
    /* 0x94 */ s32 unk_94;
} BBCObj; /* size = 0x98 (N64) */

/* A car's driving state, D_8010A490_1235A0_BumperBalloonCars[4]. */
typedef struct BBCCar {
    /* 0x00 */ f32 dir;      /* direction out of the last hit */
    /* 0x04 */ f32 prevDir;
    /* 0x08 */ f32 steer;
    /* 0x0C */ f32 speed;
    /* 0x10 */ f32 bounce;
    /* 0x14 */ f32 prevSpeed;
    /* 0x18 */ u16 hit[4];   /* touching this car */
    /* 0x20 */ u16 wall;     /* touching the rail */
    /* 0x22 */ u16 tick;
    /* 0x24 */ u16 hits;     /* popped: the balloon swells for two frames, bursts on the third */
    /* 0x26 */ s16 sndFwd;
    /* 0x28 */ s16 sndBack;
    /* 0x2A */ char unk_2A[2];
    /* 0x2C */ f32 arc;      /* COM: half width of its view (degrees) */
    /* 0x30 */ u16 cpuRand;  /* COM: of 10, how often it backs off */
    /* 0x32 */ u16 cpuWait;  /* COM: base delay */
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ s32 unk_38;
} BBCCar; /* size = 0x3C */

/* An effect sprite. D_8010A59C_1236AC_BumperBalloonCars's work is the dust, 20 slots; D_8010A598_1236A8_BumperBalloonCars's, the burst, sets up
   four slots but func_801040C8_11D1D8_BumperBalloonCars takes D_8010A59C_1236AC_BumperBalloonCars's, so its own stay idle. */
typedef struct BBCFx {
    /* 0x00 */ char unk_00[2];
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 alpha;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ f32 x;
    /* 0x0C */ f32 y;
    /* 0x10 */ f32 z;
    /* 0x14 */ char unk_14[4];
    /* 0x18 */ f32 vy;
    /* 0x1C */ s16 model;
    /* 0x1E */ char unk_1E[2];
} BBCFx; /* size = 0x20 */

typedef struct BBCFxWork {
    /* 0x000 */ BBCFx fx[20];
    /* 0x280 */ u8 state[20];
} BBCFxWork; /* size = 0x294 */

typedef struct BBCStart {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ s16 z;
    /* 0x6 */ s16 rot;
} BBCStart;

/* .data (0x121630-0x121680) */
extern u16 D_80108520_121630_BumperBalloonCars[6];       /* car file per character (dir 0x19) */
extern u16 D_8010852C_12163C_BumperBalloonCars[6];       /* balloon texture file per character */
extern BBCStart D_80108538_121648_BumperBalloonCars[4];  /* the four corners */
extern u16 D_80108558_121668_BumperBalloonCars[4];       /* signal lamp textures */
extern char* D_80108560_121670_BumperBalloonCars[4];     /* their names */
extern const char D_80108570_121680_BumperBalloonCars[];
extern const char D_80108580_121690_BumperBalloonCars[];
extern const char D_80108590_1216A0_BumperBalloonCars[];

/* .bss */
extern s8 D_80108630_121740_BumperBalloonCars[4];        /* COM: the stick it holds, y */
extern s8 D_80108634_121744_BumperBalloonCars[4];        /* x */
extern f32 D_80108638_121748_BumperBalloonCars;          /* where the balloon burst */
extern f32 D_8010863C_12174C_BumperBalloonCars;
extern f32 D_80108640_121750_BumperBalloonCars;
extern s16 D_80108650_121760_BumperBalloonCars;
extern s16 D_80108652_121762_BumperBalloonCars;          /* phase countdown */
extern s16 D_80108654_121764_BumperBalloonCars;          /* added to the phase next frame */
extern s16 D_80108658_121768_BumperBalloonCars[50];
extern s16 D_801086BC_1217CC_BumperBalloonCars[4];       /* signal lamp texture slots */
extern HuSprite_Unk84_Struct* D_801086C4_1217D4_BumperBalloonCars;
extern s32 D_801086CC_1217DC_BumperBalloonCars;
extern s16 D_801086D0_1217E0_BumperBalloonCars;          /* the first frames everybody jostles */
extern u16 D_801086D2_1217E2_BumperBalloonCars;          /* game phase */
extern BBCObj D_801086E0_1217F0_BumperBalloonCars[50];
/* Fields retail addresses by their own labels. */
extern s16 D_8010865E_12176E_BumperBalloonCars;          /* D_80108658_121768_BumperBalloonCars[3] */
extern u8 D_8010A58B_12369B_BumperBalloonCars;           /* D_8010A58A_12369A_BumperBalloonCars, low byte (big-endian): host view needed */
extern s16 D_80108CD4_121DE4_BumperBalloonCars;          /* D_801086E0_1217F0_BumperBalloonCars[10].spr */
extern BBCCar D_8010A490_1235A0_BumperBalloonCars[4];
extern s16 D_8010A580_123690_BumperBalloonCars[4];       /* corner taken */
extern u16 D_8010A588_123698_BumperBalloonCars;          /* the signal's state */
extern s16 D_8010A58A_12369A_BumperBalloonCars;          /* cars out */
extern void* D_8010A58C_12369C_BumperBalloonCars[3];
extern omObjData* D_8010A598_1236A8_BumperBalloonCars;   /* burst */
extern omObjData* D_8010A59C_1236AC_BumperBalloonCars;   /* dust */

void func_80102800_11B910_BumperBalloonCars(void);
void func_8010281C_11B92C_BumperBalloonCars(void);
void func_801028D0_11B9E0_BumperBalloonCars(omObjData* obj);
void func_801028FC_11BA0C_BumperBalloonCars(omObjData* obj);
void func_80102AB4_11BBC4_BumperBalloonCars(void);
void func_80102AFC_11BC0C_BumperBalloonCars(Gfx** gfxp);
void func_80102E28_11BF38_BumperBalloonCars(void);
void func_80102E30_11BF40_BumperBalloonCars(omObjData* obj);
void func_80102EB4_11BFC4_BumperBalloonCars(void);
void func_80102EF0_11C000_BumperBalloonCars(omObjData* obj);
void func_80103024_11C134_BumperBalloonCars(omObjData* obj);
void func_80103144_11C254_BumperBalloonCars(void);
void func_80103180_11C290_BumperBalloonCars(s16 player, f32 x, f32 y, f32 z, u16 type);
void func_80103300_11C410_BumperBalloonCars(omObjData* obj);
void func_801036AC_11C7BC_BumperBalloonCars(omObjData* obj);
void func_80103968_11CA78_BumperBalloonCars(void);
void func_801039A4_11CAB4_BumperBalloonCars(omObjData* obj);
void func_80103A10_11CB20_BumperBalloonCars(omObjData* obj);
void func_80103AC8_11CBD8_BumperBalloonCars(void);
void func_80103BDC_11CCEC_BumperBalloonCars(omObjData* obj);
void func_80103D64_11CE74_BumperBalloonCars(omObjData* obj);
void func_80103DB0_11CEC0_BumperBalloonCars(omObjData* obj);
void func_80103E38_11CF48_BumperBalloonCars(omObjData* obj);
void func_80103F6C_11D07C_BumperBalloonCars(omObjData* obj);
void func_8010408C_11D19C_BumperBalloonCars(void);
void func_801040C8_11D1D8_BumperBalloonCars(s16 player, f32 x, f32 y, f32 z, u16 type);
void func_80104244_11D354_BumperBalloonCars(omObjData* obj);
void func_80104A14_11DB24_BumperBalloonCars(omObjData* obj);
void func_80104D40_11DE50_BumperBalloonCars(omObjData* obj);
void func_80105090_11E1A0_BumperBalloonCars(BBCObj* p);
void func_80106004_11F114_BumperBalloonCars(omObjData* obj);
void func_80106600_11F710_BumperBalloonCars(omObjData* obj);
void func_80106B80_11FC90_BumperBalloonCars(void);
void func_80106C90_11FDA0_BumperBalloonCars(omObjData* obj);
void func_80106CB4_11FDC4_BumperBalloonCars(omObjData* obj);
void func_80106CEC_11FDFC_BumperBalloonCars(omObjData* obj);
void func_80106D44_11FE54_BumperBalloonCars(void);
void func_80106F9C_1200AC_BumperBalloonCars(void);
void func_801070EC_1201FC_BumperBalloonCars(void);
void func_8010765C_12076C_BumperBalloonCars(void);
void func_801079A8_120AB8_BumperBalloonCars(void);
void func_801079D0_120AE0_BumperBalloonCars(omObjData* obj);
void func_80107A74_120B84_BumperBalloonCars(void);
void func_80107BB8_120CC8_BumperBalloonCars(omObjData* obj);
void func_80107CCC_120DDC_BumperBalloonCars(void);
f32 func_80107EBC_120FCC_BumperBalloonCars(f32 y, f32 x);
f32 func_80107F34_121044_BumperBalloonCars(f32 x);
void func_80108084_121194_BumperBalloonCars(Vec* from, Vec* to, Vec* out);
void func_80108400_121510_BumperBalloonCars(void);
void func_801084F4_121604_BumperBalloonCars(void);

/* main */
extern s8 ContStkX[4];
extern s8 ContStkY[4];
extern u8 D_800FA656;
extern u16 D_801011FC_101DFC;
extern s16 D_800FA606_FB206;
extern u16 D_800FC87A_FD47A;
extern u16 D_800F8FE0_F9BE0;
void func_80029714_2A314(s16, f32, f32, f32);
f32 HuMathSin(f32);
omObjData* omAddObj(s16, u16, u16, s16, void*);
f32 func_800B7890_B8490(f32);
void func_800298A4_2A4A4(s16, s32, s32);
void func_800297E8_2A3E8(s16, f32, f32, f32);
void SprAttrSet(s16 grpIdx, s16 idx, s32 flag);
void Hu3DCamSetPerspective(s16, f32, f32, f32);
s16 func_800691FC_69DFC(s16 mesNo, ...);
s16 LoadFormFile(s32, s32);
void func_80029E80_2AA80(s16, s32, s32);
void SprBankSet(s16 group, s16 member, s16 bank);
s32 PlaySound(s32);
s16 PlayMusic(s16);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
void func_800794A8_7A0A8(s32);
void func_80029AFC_2A6FC(s16);
void func_80029A8C_2A68C(s16);
void SprPosSet(s16, s16, s16, s16);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
s16 func_80079798_7A398(s16 sfx, s16 player);
void func_8002979C_2A39C(s16, f32, f32, f32);
void HuMemMemoryFreePerm(void *ptr);
void* DataRead(s32 dirAndFile);
f32 func_800B1830_B2430(f32);
void func_80079614_7A214(s16 time);
void func_8007273C_7333C(u8* arg0, u8 arg1);
s16 func_8003D8F0_3E4F0(HmfData*, void*, s16, char*);
s16 func_8001A2F8_1AEF8(s32 arg0);
u16 func_80018A30_19630(s32 file, s32 attr);
s16 SprCreate(s32 num, s32 attr);
void InitFadeOut(s32, s32);
void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
u8 rand8(void);
extern void osViBlack(u8);
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
void omSetStatBit(omObjData *obj, u16 stat);
s32 omOvlReturnEx(s16);
void omInitObjMan(s32, s32);
s32 func_8008F618_90218(void);
void func_80079128_79D28(void);
s32 func_80069538_6A138(void);
void func_8002D4D0_2E0D0(s16 n);
void* func_80027154_27D54(s32 size, s16 tag);
void func_80020D20_21920(s16 arg0);
s32 func_80018E78_19A78(void);
void func_80018E30_19A30(s32);
void ViewportSet(u8, f32, f32, f32, f32, f32, f32);
void ScissorSet(u8 arg0, f32 x1, f32 y1, f32 x2, f32 y2);
void InitFadeIn(s32, s32);
void func_80079E60_7AA60(void);
void func_80079848_7A448(s16 arg0);
void func_800B1F50_B2B50(f32* m, f32 x, f32 y, f32 z);
void func_800824F4_830F4(s16 group, s16 member, s16 arg2);
void func_800211E8_21DE8(s16 index, u8 arg1);
void func_800796F0_7A2F0(s16 sound, s16 pitch);
s32 func_800680D4_68CD4(s16 index); /* main returns u16; retail does not re-mask the result */
s16 func_8003DF08_3EB08(void*);
void func_80021250_21E50(s16 index, u8 arg1, u8 arg2, u8 arg3);
void func_80021160_21D60(s16 index, s32 arg1, s32 arg2);
u16 func_80020EBC_21ABC(void* arg0, s32 arg1, u8 arg2);
void GWMgRecordSet(s16, u16);
void func_8003E4F4_3F0F4(s16 arg0, u8 arg1, u8 arg2);

extern u16 D_801011FC_101DFC;
extern f32 D_800F94A8_FA0A8[];  /* CZoomM */
extern Vec D_80102770_103370[]; /* CRotM */
extern Vec D_801013B0_101FB0[]; /* CenterM */
void* SprAnimGet(s16 animIdx);
void SprAttrReset(s16 grpIdx, s16 idx, s32 flag);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
void SprScaleSet(s16 group, s16 member, f32 x, f32 y);
void func_8000BE8C_CA8C(omObjData*, f32);
void func_8000BEA4_CAA4(omObjData*, f32);
void func_8000BF24_CB24(omObjData* obj, f32 arg1, f32 x0, f32 z0, f32 x1, f32 z1);
void func_8000C018_CC18(u16);
void func_80018F58_19B58(s32);
s32 func_8002838C_28F8C(s32 arg0, void (*arg1)(Gfx**), u8 arg2); /* main returns s16; retail does not extend it */
void func_80029EDC_2AADC(s16 arg0, u8 arg1);
void func_80079FF4_7ABF4(omObjData* object);
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size);
void func_8006D518_6E118(void);
void func_8006D4D0_6E0D0(s16 seconds);
s16 func_800797DC_7A3DC(s32 sfx, s16 player);
f32 func_800B75A8_B81A8(f32 y, f32 x); /* atan2, degrees */

#endif
