#ifndef _OVL_22_H
#define _OVL_22_H

/* Overlay 22: Shell Shocked. Four tanks in split screen (one viewport each, D_8010D5E0_1E1CC0_ShellShocked), on one
   of three maps (D_800FA656, kept in D_8010DFDC_1E26BC_ShellShocked), 60 s (D_8010DFE4_1E26C4_ShellShocked). Each tank has
   three hit points; a shell or a mine hit takes one. Last tank standing wins, 10 coins. Flow
   func_80102BC8_1D72A8_ShellShocked. _CheckFlag(0xE) (D_8010D5BC_1E1C9C_ShellShocked) is the boss variant: player 0 alone against
   the rest; _CheckFlag(0xC) (D_8010D5C0_1E1CA0_ShellShocked) the 1P variant. Retail is four files: 1D6EE0.c, 1D8270.c
   (from 80103B90, 3-nop pad: the cameras), 1D9870.c (from 80105190, 3-nop pad: the COM) and
   1DD8C0.c (from 801091E0, 3-nop pad: the tanks). .data is asm, .rodata is carved per file.
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

/* One split-screen camera, D_8010D5E0_1E1CC0_ShellShocked[4]. */
typedef struct SSCam {
    /* 0x00 */ s32 index;
    /* 0x04 */ Vec pos;
    /* 0x10 */ Vec at;
    /* 0x1C */ Vec up;
    /* 0x28 */ f32 fov;
    /* 0x2C */ f32 aspect;
    /* 0x30 */ f32 far;
    /* 0x34 */ f32 dist;
    /* 0x38 */ s32 state;
    /* 0x3C */ Vec off;
    /* 0x48 */ s32 unk_48;
    /* 0x4C */ u32 timer;
    /* 0x50 */ f32 orbit;
} SSCam; /* size = 0x54 */

/* A COM order and a COM's state (func_80107738_1DBE18_ShellShocked copies an order into D_8010D740_1E1E20_ShellShocked[i]). */
typedef struct SSCom {
    /* 0x00 */ s32 state;
    /* 0x04 */ s32 timer;
    /* 0x08 */ s32 count;
    /* 0x0C */ char unk_0C[4];
    /* 0x10 */ s32 unk_10[4];
    /* 0x20 */ s32 player; /* who ran this */
    /* 0x24 */ s32 target;
    /* 0x28 */ s32 limit;
    /* 0x2C */ union { s32 i; f32 f; } a;
    /* 0x30 */ union { Vec v; f32 f; } b;
    /* 0x3C */ Vec goal;
    /* 0x48 */ char unk_48[0x74];
    /* 0xBC */ s32 hits;
    /* 0xC0 */ s32 lastTarget;
    /* 0xC4 */ s32 cellX;
    /* 0xC8 */ s32 cellY;
    /* 0xCC */ s32 stuck;
} SSCom; /* size = 0xD0 */

/* A tank's shell. */
typedef struct SSShell {
    /* 0x00 */ Vec pos;
    /* 0x0C */ Vec vel;
    /* 0x18 */ s32 state; /* 0 end, 1 idle, 2 charging, 3 lobbed, 4 straight, 5 blast, 6 blasting */
    /* 0x1C */ s32 active;
    /* 0x20 */ s32 timer;
    /* 0x24 */ s16 mdl;
    /* 0x26 */ s16 blast;
    /* 0x28 */ HmfMotionObj* mot;
} SSShell; /* size = 0x2C (N64) */

/* A tank, D_8010DA80_1E2160_ShellShocked[4]. */
typedef struct SSTank {
    /* 0x000 */ s32 chr;
    /* 0x004 */ s32 flash; /* invincible after a hit */
    /* 0x008 */ s32 hp;
    /* 0x00C */ s32 level; /* COM difficulty */
    /* 0x010 */ s32 alive;
    /* 0x014 */ char unk_14[0xC];
    /* 0x020 */ Vec pos;
    /* 0x02C */ Vec rot;
    /* 0x038 */ Vec scale;
    /* 0x044 */ f32 unk_44;
    /* 0x048 */ f32 unk_48;
    /* 0x04C */ s32 state; /* 2 playing, 3 end, 4 blown up, 5 wreck */
    /* 0x050 */ s32 unk_50;
    /* 0x054 */ s32 blowTimer;
    /* 0x058 */ s32 cooldown;
    /* 0x05C */ f32 recoil;
    /* 0x060 */ HmfMotionObj* motBody;
    /* 0x064 */ HmfMotionObj* motTurret;
    /* 0x068 */ HmfMotionObj* motGun;
    /* 0x06C */ HmfMotionObj* motA;
    /* 0x070 */ HmfMotionObj* motB;
    /* 0x074 */ char unk_74[8];
    /* 0x07C */ SSShell shell[1];
    /* 0x0A8 */ char unk_A8[0x84];
    /* 0x12C */ s16 blowMdl;
    /* 0x12E */ char unk_12E[2];
    /* 0x130 */ Vec blowPos;
    /* 0x13C */ char unk_13C[4];
    /* 0x140 */ s16 hudSpr;
    /* 0x142 */ s16 hudGrp;
    /* 0x144 */ s32 hudHold;
    /* 0x148 */ s32 engineOn;
    /* 0x14C */ s32 sndEnable;
    /* 0x150 */ s32 engineSe;
} SSTank; /* size = 0x154 (N64) */

typedef struct SSRect {
    f32 x1, y1, x2, y2;
} SSRect;

typedef struct SSView {
    f32 v[6];
} SSView;

/* Names of a character's tank parts. */
typedef struct SSChrParts {
    /* 0x00 */ char* body;
    /* 0x04 */ char* motB;
    /* 0x08 */ char* turret;
    /* 0x0C */ char* unk_0C[2];
    /* 0x14 */ char* gun;
    /* 0x18 */ char* head;
    /* 0x1C */ char* shell;
    /* 0x20 */ char* unk_20;
} SSChrParts; /* size = 0x24 (N64) */

/* Start places of a map. */
typedef struct SSStart {
    f32* rot;
    Vec* pos;
} SSStart;

/* A map: its model and its pillars. */
typedef struct SSMap {
    s32 file;
    s32 count;
    Vec* pillars;
} SSMap;

typedef struct SSTimer {
    s32 seconds;
    s32 frames;
} SSTimer;

/* .data (asm) */
extern SSRect D_8010CAE0_1E11C0_ShellShocked[4];
extern SSView D_8010CB20_1E1200_ShellShocked[4];
extern f32 D_8010CB80_1E1260_ShellShocked[4];
extern f32 D_8010CB90_1E1270_ShellShocked[4];
extern f32 D_8010CBA0_1E1280_ShellShocked[4];
extern s32 D_8010CBB0_1E1290_ShellShocked[3][4];
extern s32 D_8010CBE0_1E12C0_ShellShocked[4];
extern s32 D_8010CBF0_1E12D0_ShellShocked[4];
extern s32 D_8010CC00_1E12E0_ShellShocked[4];
extern s32 D_8010CC10_1E12F0_ShellShocked[4];
extern f32 D_8010CC20_1E1300_ShellShocked[2][4];
extern f32 D_8010CC40_1E1320_ShellShocked[4];
extern f32 D_8010CC50_1E1330_ShellShocked[4];
extern f32 D_8010CC60_1E1340_ShellShocked[8];
extern s32 D_8010CC80_1E1360_ShellShocked[8];
extern SSChrParts D_8010CCA0_1E1380_ShellShocked[7];
extern s32 D_8010CD9C_1E147C_ShellShocked[8];
extern SSStart D_8010CE3C_1E151C_ShellShocked[3];
extern SSMap D_8010CEFC_1E15DC_ShellShocked[3];
extern Vec D_8010CF20_1E1600_ShellShocked[4];

/* .bss (asm) */
extern omObjData* D_8010D570_1E1C50_ShellShocked[16];
extern s32 D_8010D5B0_1E1C90_ShellShocked;
extern s32 D_8010D5B4_1E1C94_ShellShocked;
extern s32 D_8010D5B8_1E1C98_ShellShocked;
extern s32 D_8010D5BC_1E1C9C_ShellShocked;
extern s32 D_8010D5C0_1E1CA0_ShellShocked;
extern s32 D_8010D5C8_1E1CA8_ShellShocked[6];
extern SSCam D_8010D5E0_1E1CC0_ShellShocked[4];
extern s32 D_8010D730_1E1E10_ShellShocked;
extern SSCom D_8010D740_1E1E20_ShellShocked[4];
extern SSTank D_8010DA80_1E2160_ShellShocked[4];
extern f32 D_8010DFD0_1E26B0_ShellShocked;
extern SSStart* D_8010DFD4_1E26B4_ShellShocked;
extern s32 D_8010DFD8_1E26B8_ShellShocked;
extern s32 D_8010DFDC_1E26BC_ShellShocked;
extern SSMap* D_8010DFE0_1E26C0_ShellShocked;
extern SSTimer D_8010DFE4_1E26C4_ShellShocked;

/* main */
extern u16 D_801011FC_101DFC;
extern u8 D_800FA656;
extern s8 D_800FDEAE_FEAAE;
extern s8 ContStkX[];
extern s8 ContStkY[];

extern void func_80020070_20C70(s16);
extern void func_80020D20_21920(s16);
extern void func_80026D28_27928(s16);
extern void func_80026DAC_279AC(s16, u8, u8, u8);
extern void func_80026E00_27A00(s16, f32, f32, f32);
extern void func_8002D4D0_2E0D0(s16);
extern s16 func_800691FC_69DFC(s16, ...);
extern s32 func_80069538_6A138(void);
extern s32 func_800696E4_6A2E4(void);
extern void func_8006D4D0_6E0D0(s16);
extern void func_8006D518_6E118(void);
extern s16 func_800797DC_7A3DC(s32, s16);
extern void func_80079868_7A468(void);
extern void func_80079128_79D28(void);
extern void func_800794A8_7A0A8(s32);
extern s32 func_8008F618_90218(void);
extern void func_800B3170_B3D70(Vec*, Vec*);
extern f32 func_800B1830_B2430(f32);
extern f32 func_800B7890_B8490(f32);
extern f32 func_800B75A8_B81A8(f32, f32);
extern f32 HuMathSin(f32);
extern void HuVecCopyXYZ(Vec*, f32, f32, f32);
extern void HuVecSubtract(Vec*, Vec*, Vec*);
extern void func_80029714_2A314(s16, f32, f32, f32);
extern void func_8002979C_2A39C(s16, f32, f32, f32);
extern void func_800297E8_2A3E8(s16, f32, f32, f32);
extern void func_800298A4_2A4A4(s16, s32, s32);
extern void func_80029EDC_2AADC(s16, s16);
extern void func_80029F2C_2AB2C(s16, s32);
extern void func_80029FE4_2ABE4(s16, f32);
extern HmfMotionObj* func_8002A9F4_2B5F4(s16, char*);
extern s16 func_8001A2F8_1AEF8(s32);
extern s16 func_8001AAAC_1B6AC(s16, s32, s32);
extern void func_8001A854_1B454(u16, s32, s32);
extern void func_8001A91C_1B51C(u16, f32, f32);
extern void func_8008225C_82E5C(s16, s16, s32);
extern f32 func_80029CE4_2A8E4(s16);
extern f32 func_80029D0C_2A90C(s16);
extern void func_80029C74_2A874(s16, f32);
extern void func_80079848_7A448(s16);
extern s16 func_80079798_7A398(s16, s16);
extern void func_800796F0_7A2F0(s16, s16);
extern void func_80029E80_2AA80(s16, s32, s32);
extern s16 PlayMusic(s16);
extern s32 PlaySound(s32);
extern s32 omOvlReturnEx(s16);
extern u8 rand8(void);
extern void InitFadeIn(s32, s32);
extern void InitFadeOut(s32, s32);
extern void ScissorSet(u8, f32, f32, f32, f32);
extern void ViewportSet(u8, f32, f32, f32, f32, f32, f32);
extern void omVibrate(s16, s16, s16, s16);
extern void omSetStatBit(omObjData*, u16);
extern omObjData* omAddObj(s16, u16, u16, s16, void*);
extern void omSetTra(omObjData*, f32, f32, f32);
extern void omSetSca(omObjData*, f32, f32, f32);
extern void omSetRot(omObjData*, f32, f32, f32);
extern u16 LoadFormFile(s32, s32);
extern void espPosSet(u16, s16, s16);
extern void espDispOn(u16);
extern void espDispOff(u16);
extern s32 _CheckFlag(s32);
extern void Hu3DCamUpdateMtx(s16);
extern f32 sqrtf(f32);
extern void Hu3DCamSetPerspective(s16, f32, f32, f32);
extern void Hu3DCamSetPositionOrientation(s16, Vec*, Vec*, Vec*);

/* 1D6EE0.c */
void func_80102800_1D6EE0_ShellShocked(void);
void func_8010281C_1D6EFC_ShellShocked(void);
void func_80102824_1D6F04_ShellShocked(void);
void func_80102B8C_1D726C_ShellShocked(void);
void func_80102BC8_1D72A8_ShellShocked(omObjData* obj);
void func_801031A4_1D7884_ShellShocked(omObjData* obj);
void func_801031BC_1D789C_ShellShocked(omObjData* obj);
void func_80103500_1D7BE0_ShellShocked(omObjData* obj);
void func_80103518_1D7BF8_ShellShocked(omObjData* obj);
void func_8010386C_1D7F4C_ShellShocked(omObjData* obj);
omObjData* func_80103884_1D7F64_ShellShocked(s32 i);
s32 func_80103898_1D7F78_ShellShocked(void);
void func_801038A4_1D7F84_ShellShocked(s32 player);
s32 func_801038B0_1D7F90_ShellShocked(void);
void func_801038BC_1D7F9C_ShellShocked(s32 n);
void func_801038C8_1D7FA8_ShellShocked(void);
s32 func_801038E0_1D7FC0_ShellShocked(void);
s32 func_801038F8_1D7FD8_ShellShocked(void);
void func_80103904_1D7FE4_ShellShocked(void);
s32 func_80103938_1D8018_ShellShocked(void);
s32 func_80103944_1D8024_ShellShocked(void);
s32 func_80103950_1D8030_ShellShocked(s32 i);
s32 func_80103998_1D8078_ShellShocked(s32 i);
f32 func_801039BC_1D809C_ShellShocked(void);
s32* func_801039F8_1D80D8_ShellShocked(void);

/* 1D8270.c */
void func_80103B90_1D8270_ShellShocked(s32 i);
void func_80104CE0_1D93C0_ShellShocked(omObjData* obj);
void func_80104D38_1D9418_ShellShocked(void);
void func_80105014_1D96F4_ShellShocked(omObjData* obj);
void func_80105044_1D9724_ShellShocked(s32 i, s32 state);
s32 func_80105068_1D9748_ShellShocked(s32 i);
void func_801050D0_1D97B0_ShellShocked(s32 i, s32 x, s32 y);

/* 1D9870.c */
void func_80105190_1D9870_ShellShocked(void);
void func_80105304_1D99E4_ShellShocked(void);
void func_80105360_1D9A40_ShellShocked(s32 i);
void func_80105428_1D9B08_ShellShocked(s32 i);
void func_80105648_1D9D28_ShellShocked(s32 i);
void func_80105758_1D9E38_ShellShocked(s32 i);
void func_80105960_1DA040_ShellShocked(s32 i);
void func_801060D0_1DA7B0_ShellShocked(s32 i);
void func_80106770_1DAE50_ShellShocked(s32 i);
void func_80106D84_1DB464_ShellShocked(s32 i);
s32 func_80106E4C_1DB52C_ShellShocked(s32 i);
f32 func_80107044_1DB724_ShellShocked(s32 i, s32 target);
s32 func_801072FC_1DB9DC_ShellShocked(s32 i, s32 target);
SSCom* func_80107714_1DBDF4_ShellShocked(s32 i);
void func_80107738_1DBE18_ShellShocked(s32 i, s32 force, SSCom* cmd);
void func_80107A90_1DC170_ShellShocked(s32 i);
void func_80107AB8_1DC198_ShellShocked(s32 i, f32 x, f32 z, s32 limit);
void func_80107B60_1DC240_ShellShocked(s32 i, f32 x, f32 z, s32 limit);
void func_80107C04_1DC2E4_ShellShocked(s32 i);
void func_80107EF8_1DC5D8_ShellShocked(s32 i, s32 target, s32 time);
void func_80107FB4_1DC694_ShellShocked(s32 i, s32 target, s32 time);
void func_80108034_1DC714_ShellShocked(s32 i, s32 target, f32 dist, s32 time);
void func_801080C0_1DC7A0_ShellShocked(s32 i, s32 target, f32 a, f32 b, s32 limit);
void func_80108100_1DC7E0_ShellShocked(s32 i);
void func_80108190_1DC870_ShellShocked(s32 i);
s32 func_801083C4_1DCAA4_ShellShocked(s32 i, s32 x, s32 z);
s32 func_8010856C_1DCC4C_ShellShocked(s32 i, s32 x, s32 z);
s32 func_80108714_1DCDF4_ShellShocked(s32 i);
f32 func_801087F8_1DCED8_ShellShocked(s32 i, s32* who);
s32 func_8010895C_1DD03C_ShellShocked(s32 i);
s32 func_80108E68_1DD548_ShellShocked(s32 i, s32 target, f32 angle, s32 pillars);
s32 func_8010913C_1DD81C_ShellShocked(f32 x, f32 z, f32* cx, f32* cz);

/* 1DD8C0.c */
void func_801091E0_1DD8C0_ShellShocked(omObjData* obj);
void func_801091F0_1DD8D0_ShellShocked(omObjData* obj);
void func_8010991C_1DDFFC_ShellShocked(s32 i);
void func_80109D08_1DE3E8_ShellShocked(void);
void func_80109F4C_1DE62C_ShellShocked(void);
void func_8010A19C_1DE87C_ShellShocked(omObjData* obj);
void func_8010A1E4_1DE8C4_ShellShocked(s32 i);
s32 func_8010A368_1DEA48_ShellShocked(s32 i, s16 x, s16 y);
s32 func_8010A954_1DF034_ShellShocked(s32 i, s16 x, s16 y);
s32 func_8010B08C_1DF76C_ShellShocked(s32 i, s16 x, s16 y);
s32 func_8010B0B4_1DF794_ShellShocked(s32 i, s16 x, s16 y);
void func_8010B0DC_1DF7BC_ShellShocked(void);
void func_8010B0E4_1DF7C4_ShellShocked(s32 i);
void func_8010B3EC_1DFACC_ShellShocked(s32 i);
void func_8010B494_1DFB74_ShellShocked(s32 i, s32 kind);
void func_8010B618_1DFCF8_ShellShocked(s32 i);
s32 func_8010BB0C_1E01EC_ShellShocked(s32 i, SSShell* shell);
s32 func_8010BEB4_1E0594_ShellShocked(void);
f32 func_8010C000_1E06E0_ShellShocked(void);
void func_8010C0A0_1E0780_ShellShocked(s32 i, s32 hp);
s32 func_8010C100_1E07E0_ShellShocked(s32 i);
s32 func_8010C124_1E0804_ShellShocked(s32 i, s32 by);
s32 func_8010C1F0_1E08D0_ShellShocked(s32 i);
s32 func_8010C218_1E08F8_ShellShocked(s32 i, Vec* pos, f32 angle);
void func_8010C57C_1E0C5C_ShellShocked(void);
void func_8010C5C0_1E0CA0_ShellShocked(s32 i);
void func_8010C604_1E0CE4_ShellShocked(void);
void func_8010C66C_1E0D4C_ShellShocked(s32 i);
void func_8010C6C4_1E0DA4_ShellShocked(s32 i, s32 speed);
void func_8010C7AC_1E0E8C_ShellShocked(void);
void func_8010C7E4_1E0EC4_ShellShocked(s32 i);
void func_8010C808_1E0EE8_ShellShocked(s32 i);
void func_8010C848_1E0F28_ShellShocked(s32 i);
void func_8010C86C_1E0F4C_ShellShocked(s32 i);
void func_8010C890_1E0F70_ShellShocked(void);
s32 func_8010C8AC_1E0F8C_ShellShocked(Vec* a, Vec* b, f32* m);
void func_8010CA20_1E1100_ShellShocked(Vec* a, Vec* b, Vec* out);
f32 func_8010CA68_1E1148_ShellShocked(Vec* a, Vec* b);
f32 func_8010CAA4_1E1184_ShellShocked(void);

#define ABS(x) ((x) < 0.0f ? -(x) : (x))

#endif
