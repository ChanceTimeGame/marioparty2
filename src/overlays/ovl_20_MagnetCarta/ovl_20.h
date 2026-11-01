#ifndef _OVL_20_H
#define _OVL_20_H

/* Overlay 20: Magnet Carta. Written up at the end of the fork. */

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
#define MC_WRAP(a) ((a) >= 360.0f ? (a) - 360.0f : (a) < 0.0f ? (a) + 360.0f : (a))

/* One entry of D_8010BDD0_1D0180_MagnetCarta[50] (func_8010B430_1CF7E0_MagnetCarta clears it): 0-3 the carts, 4 the big piece, 5-8 the
   middle ones, 9-13 the small ones, 30 the scoreboard, 40 the signal, 45 the camera, 46 the banner.
   Same layout as Driver's Ed's DEObj. */
typedef struct MCObj {
    /* 0x00 */ omObjData* obj;
    /* 0x04 */ s16 spr;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ f32 x;
    /* 0x0C */ f32 y;
    /* 0x10 */ f32 z;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s16 unk_20[2];
    /* 0x24 */ s32 unk_24[2];
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30[4][4];
    /* 0x70 */ u16 timer;    /* signal: frame count; cart: stun; piece: being thrown */
    /* 0x72 */ u16 state;    /* signal: bob direction; piece: 0 free, 1 scoring, 2 gone */
    /* 0x74 */ u16 dust;
    /* 0x76 */ u16 attached; /* 1: this and D_8010BDD0_1D0180_MagnetCarta[target] are held together */
    /* 0x78 */ u16 target;
    /* 0x7A */ u16 spin;
    /* 0x7C */ u16 cpuWait;
    /* 0x7E */ u16 unk_7E;
    /* 0x80 */ s16 lift;
    /* 0x82 */ s16 unk_82;
    /* 0x84 */ s16 hit;
    /* 0x86 */ s16 unk_86;
    /* 0x88 */ f32 size;     /* signal: shadow scale; piece: shrink step */
    /* 0x8C */ s32 unk_8C;
    /* 0x90 */ s32 unk_90;
    /* 0x94 */ s32 unk_94;
} MCObj; /* size = 0x98 (N64) */

/* Motion of D_8010BDD0_1D0180_MagnetCarta[n], D_8010B7B0_1CFB60_MagnetCarta[18]. */
typedef struct MCCar {
    /* 0x00 */ f32 dir;
    /* 0x04 */ f32 prevDir;
    /* 0x08 */ f32 steer;
    /* 0x0C */ f32 speed;
    /* 0x10 */ f32 bounce;
    /* 0x14 */ f32 prevSpeed;
    /* 0x18 */ f32 mass;
    /* 0x1C */ u16 hit[18];
    /* 0x40 */ u16 wall;
    /* 0x42 */ u16 tick;
    /* 0x44 */ s16 sndFwd;
    /* 0x46 */ s16 sndBack;
    /* 0x48 */ f32 arc;
    /* 0x4C */ u8 cpuRand;
    /* 0x4D */ u8 cpuWait;
} MCCar; /* size = 0x50 */

typedef struct MCFx {
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
    /* 0x1E */ u8 owner;
    /* 0x1F */ char unk_1F;
} MCFx; /* size = 0x20 */

typedef struct MCFxWork {
    /* 0x000 */ MCFx fx[20];
    /* 0x280 */ u8 state[20];
} MCFxWork; /* size = 0x294 */

typedef struct MCStart {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ s16 z;
    /* 0x6 */ s16 rot;
} MCStart;

/* Where a small piece may start: nine points on a circle. */
typedef struct MCRing {
    /* 0x0 */ f32 r;
    /* 0x4 */ f32 unk_04[2];
    /* 0xC */ f32 angle;
} MCRing;

/* .data (0x1CF900-0x1CFA10) */
extern u16 D_8010B550_1CF900_MagnetCarta[6];        /* cart file per character */
extern f32 D_8010B55C_1CF90C_MagnetCarta[8];
extern s16 D_8010B57C_1CF92C_MagnetCarta[2];        /* team's cart magnet file */
extern MCStart D_8010B580_1CF930_MagnetCarta[2];    /* team 0's two starts */
extern MCStart D_8010B590_1CF940_MagnetCarta[2];    /* team 1's */
extern MCStart D_8010B5A0_1CF950_MagnetCarta[3];    /* the big piece's start */
extern MCRing D_8010B5B8_1CF968_MagnetCarta[][9];
extern u16 D_8010B648_1CF9F8_MagnetCarta[4];        /* signal lamp textures */
extern char* D_8010B650_1CFA00_MagnetCarta[4];      /* their names */

/* .bss */
extern MCCar D_8010B7B0_1CFB60_MagnetCarta[18];
extern s16 D_8010BD50_1D0100_MagnetCarta[4];        /* score digit textures */
extern s32 D_8010BD60_1D0110_MagnetCarta;
extern s16 D_8010BD68_1D0118_MagnetCarta[50];
extern s8 D_8010BDCC_1D017C_MagnetCarta[2];         /* team 0's starts taken */
extern s8 D_8010BDCE_1D017E_MagnetCarta;            /* score shown, team 0 */
extern MCObj D_8010BDD0_1D0180_MagnetCarta[50];
/* Fields retail addresses by their own labels. */
extern s16 D_8010D88C_1D1C3C_MagnetCarta;           /* D_8010BDD0_1D0180_MagnetCarta[45].spr */
extern u8 D_8010DB80_1D1F30_MagnetCarta;            /* game phase */
extern s16 D_8010DB82_1D1F32_MagnetCarta[3];        /* signal lamp texture slots */
extern s8 D_8010DB88_1D1F38_MagnetCarta[17];        /* ring points taken */
extern s8 D_8010DB98_1D1F48_MagnetCarta;            /* score, team 0 */
extern void* D_8010DB9C_1D1F4C_MagnetCarta[3];
extern s8 D_8010DBA8_1D1F58_MagnetCarta;            /* score, team 1 */
extern s8 D_8010DBA9_1D1F59_MagnetCarta;
extern s8 D_8010DBAB_1D1F5B_MagnetCarta;
extern u16 D_8010DBAC_1D1F5C_MagnetCarta;           /* the signal's state */
extern omObjData* D_8010DBB0_1D1F60_MagnetCarta;    /* dust */
extern s16 D_8010DBB4_1D1F64_MagnetCarta;
extern u8 D_8010DBB6_1D1F66_MagnetCarta;            /* added to the phase next frame */
extern u8 D_8010DBB7_1D1F67_MagnetCarta;
extern s16 D_8010DBB8_1D1F68_MagnetCarta;           /* phase countdown */
extern s8 D_8010DBBA_1D1F6A_MagnetCarta[2];         /* team 1's starts taken */
extern s8 D_8010DBBC_1D1F6C_MagnetCarta;            /* score shown, team 1 */
extern HuSprite_Unk84_Struct* D_8010DBC0_1D1F70_MagnetCarta;
extern s8 D_8010DBC4_1D1F74_MagnetCarta;
extern omObjData* D_8010DBC8_1D1F78_MagnetCarta;    /* sparks */

extern s16 D_800FA606_FB206;

/* Main functions. */
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16, f32, f32, f32);
void func_8003E560_3F160(s16 arg0, u8 arg1);
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
f32 func_800B75A8_B81A8(f32 y, f32 x); /* atan2, degrees */
void func_8006D4D0_6E0D0(s16 arg0);
void func_8006D518_6E118(void);
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
void func_80018E30_19A30(s32);
void ViewportSet(u8, f32, f32, f32, f32, f32, f32);
void ScissorSet(u8 arg0, f32 x1, f32 y1, f32 x2, f32 y2);
void InitFadeIn(s32, s32);
void func_80079848_7A448(s16 arg0);
void func_800B1F50_B2B50(f32* m, f32 x, f32 y, f32 z);
void func_800211E8_21DE8(s16 index, u8 arg1);
void func_800796F0_7A2F0(s16 sound, s16 pitch);
s16 func_8003DF08_3EB08(void*);
void func_80021250_21E50(s16 index, u8 arg1, u8 arg2, u8 arg3);
void func_80021160_21D60(s16 index, s32 arg1, s32 arg2);
u16 func_80020EBC_21ABC(void* arg0, s32 arg1, u8 arg2);
void func_8003E4F4_3F0F4(s16 arg0, u8 arg1, u8 arg2);

void func_80102800_1C6BB0_MagnetCarta(void);
void func_8010281C_1C6BCC_MagnetCarta(void);
void func_801028D0_1C6C80_MagnetCarta(omObjData* obj);
void func_801028FC_1C6CAC_MagnetCarta(omObjData* obj);
void func_80102AB0_1C6E60_MagnetCarta(void);
void func_80102AF8_1C6EA8_MagnetCarta(Gfx** gfxp);
void func_80102E14_1C71C4_MagnetCarta(void);
void func_80102E1C_1C71CC_MagnetCarta(omObjData* obj);
void func_80102EA0_1C7250_MagnetCarta(void);
void func_80102EDC_1C728C_MagnetCarta(omObjData* obj);
void func_80103064_1C7414_MagnetCarta(omObjData* obj);
void func_80103284_1C7634_MagnetCarta(void);
void func_801032C8_1C7678_MagnetCarta(omObjData* obj);
void func_80103494_1C7844_MagnetCarta(omObjData* obj);
void func_801035B4_1C7964_MagnetCarta(void);
void func_801035F0_1C79A0_MagnetCarta(s16 player, f32 x, f32 y, f32 z, u16 type, MCObj* p);
void func_80103760_1C7B10_MagnetCarta(omObjData* obj);
void func_80103894_1C7C44_MagnetCarta(omObjData* obj);
void func_801039B4_1C7D64_MagnetCarta(void);
void func_801039F0_1C7DA0_MagnetCarta(s16 player, f32 x, f32 y, f32 z, u16 type);
void func_80103B70_1C7F20_MagnetCarta(omObjData* obj);
void func_80103F34_1C82E4_MagnetCarta(omObjData* obj);
void func_801041F0_1C85A0_MagnetCarta(void);
void func_8010422C_1C85DC_MagnetCarta(void);
void func_801042F4_1C86A4_MagnetCarta(void);
void func_80104360_1C8710_MagnetCarta(omObjData* obj);
void func_80104490_1C8840_MagnetCarta(omObjData* obj);
void func_801045F4_1C89A4_MagnetCarta(omObjData* obj);
void func_80104640_1C89F0_MagnetCarta(omObjData* obj);
void func_801046C8_1C8A78_MagnetCarta(omObjData* obj);
void func_80104970_1C8D20_MagnetCarta(omObjData* obj);
void func_80104B70_1C8F20_MagnetCarta(void);
void func_80104BB4_1C8F64_MagnetCarta(omObjData* obj);
void func_80104E5C_1C920C_MagnetCarta(omObjData* obj);
void func_80105124_1C94D4_MagnetCarta(void);
void func_801051C8_1C9578_MagnetCarta(omObjData* obj);
void func_80105470_1C9820_MagnetCarta(omObjData* obj);
void func_80105730_1C9AE0_MagnetCarta(void);
void func_801057D4_1C9B84_MagnetCarta(omObjData* obj);
void func_80105E28_1CA1D8_MagnetCarta(omObjData* obj);
void func_80106BE0_1CAF90_MagnetCarta(omObjData* obj);
void func_80107140_1CB4F0_MagnetCarta(MCObj* p);
void func_80108174_1CC524_MagnetCarta(omObjData* obj);
void func_80108364_1CC714_MagnetCarta(omObjData* obj);
void func_80108888_1CCC38_MagnetCarta(void);
void func_80108A10_1CCDC0_MagnetCarta(void);
void func_80108A34_1CCDE4_MagnetCarta(omObjData* obj);
void func_80108A6C_1CCE1C_MagnetCarta(omObjData* obj);
void func_80108AC4_1CCE74_MagnetCarta(void);
void func_80109464_1CD814_MagnetCarta(void);
void func_801095E4_1CD994_MagnetCarta(void);
void func_8010A1AC_1CE55C_MagnetCarta(void);
void func_8010A8F4_1CECA4_MagnetCarta(void);
void func_8010A91C_1CECCC_MagnetCarta(omObjData* obj);
void func_8010A9E0_1CED90_MagnetCarta(void);
void func_8010AB44_1CEEF4_MagnetCarta(omObjData* obj);
void func_8010ACB4_1CF064_MagnetCarta(void);
f32 func_8010AEE0_1CF290_MagnetCarta(f32 y, f32 x);
f32 func_8010AF58_1CF308_MagnetCarta(f32 x);
void func_8010B0A8_1CF458_MagnetCarta(Vec* from, Vec* to, Vec* out);
void func_8010B430_1CF7E0_MagnetCarta(void);
void func_8010B524_1CF8D4_MagnetCarta(void);

#endif
