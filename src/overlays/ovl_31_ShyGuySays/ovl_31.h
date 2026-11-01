#ifndef _OVL_31_H
#define _OVL_31_H

/* Overlay 31: Shy Guy Says (MP1 ovl_28_ShyGuySays/1D9690.c). Four players stand at the edge of a
   platform and raise the flag the Shy Guy names (B = left, A = right); a wrong or late flag ends in
   the Shy Guy's cannon firing a Bill at the player, who falls away. Rounds get shorter until at most
   one player is left. Differences from MP1: the Shy Guy feints (states 1-4), a time bar shows the
   time left, the shot is a homing object (func_80108A78_24C388_ShyGuySays) rather than a fall.
   One retail file, 246110.c; .data up to 0x24DB10, .rodata carved from there. N64 offsets are in
   the comments. */

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/data.h"
#include "game/collision.h"
#include "game/board.h"
#include "game/malloc.h"

/* A motion and its length (MP1 unkStructShyGuySays_03). */
typedef struct SGSMot {
    /* 0x00 */ s16 id;
    /* 0x02 */ s16 len;
} SGSMot;

/* One player's state (MP1 unkStruct_ShyGuySays_01). */
typedef struct SGSPlayer {
    /* 0x00 */ s16 active;
    /* 0x04 */ s32 action; /* 0 none, 1 left flag, 2 right flag, 0x200 out */
    /* 0x08 */ s16 port; /* -1 for a CPU */
    /* 0x0A */ s16 wait; /* CPU reaction, 1-5 */
    /* 0x0C */ s16 level; /* CPU mistake rate */
    /* 0x0E */ s16 rank;
    /* 0x10 */ s32 left; /* 1 down, 2 up */
    /* 0x14 */ s32 right;
    /* 0x18 */ u32 timer; /* CPU delay, then the time until the player is gone */
    /* 0x1C */ SGSMot mot[5];
    /* 0x30 */ char unk_30[0x60];
    /* 0x90 */ f32 baseX;
    /* 0x94 */ s16 swayX;
    /* 0x96 */ s16 swayY;
    /* 0x98 */ s16 cpuCount;
    /* 0x9A */ s16 cpuBusy;
    /* 0x9C */ s16 forced;
    /* 0x9E */ s16 glow;
    /* 0xA0 */ s16 unk_A0;
    /* 0xA4 */ s32 fallTime;
} SGSPlayer; /* size = 0xA8 */

/* The voices of a player's win motions: a handle, set once from the files (D_8010A590_24DEA0_ShyGuySays). */
typedef struct SGSVoice {
    /* 0x00 */ s32 a;
    /* 0x04 */ s32 b;
    /* 0x08 */ char unk_08[8];
} SGSVoice; /* size = 0x10 */

/* A sprite effect (MP1 unkStruct_ShyGuySays_06). */
typedef struct SGSFx {
    /* 0x00 */ s16 used;
    /* 0x02 */ s16 sprite;
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
    /* 0x0C */ f32 z;
    /* 0x10 */ s16 time;
    /* 0x12 */ u16 flags;
} SGSFx; /* size = 0x14 */

/* A delayed sound. */
typedef struct SGSSound {
    /* 0x00 */ s16 id;
    /* 0x02 */ s16 delay;
    /* 0x04 */ s16 player; /* < 0: a plain sound */
} SGSSound; /* size = 6 */

/* The homing shot (0x38). */
typedef struct SGSShot {
    /* 0x00 */ omObjData* target;
    /* 0x04 */ Vec pos;
    /* 0x10 */ f32 pitch;
    /* 0x14 */ f32 yaw;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ Vec vel;
    /* 0x28 */ f32 speed;
    /* 0x2C */ f32 radius;
    /* 0x30 */ s16 model;
    /* 0x32 */ s16 mdl;
    /* 0x34 */ f32 spin;
} SGSShot; /* size = 0x38 */

/* The background sprites that breathe (0x14). */
typedef struct SGSBack {
    /* 0x00 */ s16 model;
    /* 0x02 */ s16 angle;
    /* 0x04 */ f32 scale;
    /* 0x08 */ f32 x;
    /* 0x0C */ f32 y;
    /* 0x10 */ f32 z;
} SGSBack; /* size = 0x14 */

/* A flag vertex and its weight (func_80108430_24BD40_ShyGuySays). */
typedef struct SGSFlagVtx {
    /* 0x00 */ s32 index; /* 0xFF ends the list */
    /* 0x04 */ f32 weight;
} SGSFlagVtx;

typedef struct SGSCharData { /* D_800CD438, one per character */
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 unk_04; /* motion file base */
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ char unk_14[4];
} SGSCharData; /* size = 0x18 */

/* ---- main-segment API missing from include/ ---- */
extern SGSCharData D_800CD438_CE038[];
extern f32 D_800CA02C_CAC2C; /* the wobble phase */
extern u16 D_800F8FE0_F9BE0;
extern u16 D_800FC87A_FD47A;
extern u16 D_800FA606_FB206;
extern u16 D_801011FC_101DFC;
extern u8 D_80102720_103320;
extern u16 ContBtnTrg[4];
extern u8 D_800FDBE0_FE7E0; /* current vertex buffer */
extern u8 D_800FDBCA_FE7CA; /* vertex buffer count */
extern Vec D_8010274C_10334C; /* Center */
extern Vec D_800FD474_FE074; /* CRot */
extern f32 D_800FA610_FB210; /* CZoom */

void Hu3DCamSetPerspective(s16, f32, f32, f32);
void func_80020D20_21920(s16 arg0);
void func_8002D4D0_2E0D0(s16 n);
void func_80026DAC_279AC(s16, u8, u8, u8);
void func_80026E00_27A00(s16, f32, f32, f32);
void func_8007273C_7333C(const u8* arg0, u8 arg1);
void* HuMemAlloc(s32 size);
void HuMemFree(void* arg0);
void* func_80027154_27D54(s32 size, s16 arg1);
s16 func_80027D3C_2893C(s16 linkMdlId);
s16 func_80027FA4_28BA4(u32 arg0, void* arg1, u8 arg2);
u16 func_80018A30_19630(s32 arg0, s32 arg1);
s16 func_80018ACC_196CC(s32 arg0);
s16 func_8001F4AC_200AC(u8* arg0);
u16 LoadFormFile(s32, s32);
void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
void func_80029714_2A314(s16 idx, f32 x, f32 y, f32 z);
void func_8002979C_2A39C(s16 idx, f32 x, f32 y, f32 z);
void func_800297E8_2A3E8(s16 idx, f32 x, f32 y, f32 z);
void func_800298A4_2A4A4(s16 arg0, s32 arg1, s32 arg2);
void func_80029A8C_2A68C(s16 arg0);
void func_80029BF0_2A7F0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
f32 func_80029D0C_2A90C(s16 arg0);
s32 func_80029E14_2AA14(s16 arg0); /* main: u8; retail callers take a word */
void func_8002A00C_2AC0C(s16 arg0);
void func_8002A15C_2AD5C(s16 arg0, s16 arg1, f32 arg2);
void func_8002AC10_2B810(s16 arg0, f32 arg1, f32 arg2, s32 arg3);
s16 func_80038398_38F98(HmfData* arg0, char* arg1);
omObjData* func_800732B0_73EB0(u32 arg0);
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
s32 omOvlReturnEx(s16);
HuSprite_Unk84_Struct* SprAnimGet(s16 animIdx);
s16 SprAnimRead(void* arg0);
s16 SprCreate(s32 num, s32 attr);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprAttrSet(s16 grpIdx, s16 idx, s32 flag);
void SprAttrReset(s16 grpIdx, s16 idx, s32 flag);
void SprBankSet(s16 grpIdx, s16 idx, u16 bank);
void SprPosSet(s16 grpIdx, s16 idx, s16 x, s16 y);
void SprPos3DSet(s16 grpIdx, s16 idx, s16 camIdx, f32 x, f32 y, f32 z);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
void SprScaleSet(s16 grpIdx, s16 idx, f32 sx, f32 sy);
void func_8008221C_82E1C(s16 group, s16 member, f32 arg2);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
void func_80082450_83050(s16 grpIdx, s32 idx, s32 r, s32 g, u8 b);
s16 func_800691FC_69DFC(s16 mesNo, ...); /* MP1 GMesCreate */
s32 func_80069538_6A138(void); /* MP1 GMesStatAllGet */
u16 func_80078EA8_79AA8(void);
void func_80079614_7A214(s16 time);
s16 func_80079798_7A398(s16 arg0, s16 arg1);
void func_800798F8_7A4F8(s16 arg0, s16 arg1);
s32 func_8008F618_90218(void);
s16 PlayMusic(s16);
s32 PlaySound(s32);
f64 fabs(f64);
f32 fabsf(f32);
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* cos */
f32 func_800B75A8_B81A8(f32 y, f32 x); /* atan2 */
f64 func_800B0D98_B1998(f64 x, f64 y); /* fmod */
s32 func_800B0FD0_B1BD0(const char* a, const char* b); /* strcmp, asm only */
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size);

/* ---- .data ---- */
extern u32 D_80109DB0_24D6C0_ShyGuySays; /* the random seed; retail also reads its low half by label */
extern u16 D_80109DB4_24D6C4_ShyGuySays; /* main process phase */
extern s16 D_80109DB6_24D6C6_ShyGuySays; /* result phase */
extern s16 D_80109DB8_24D6C8_ShyGuySays;
extern u16 D_80109DBA_24D6CA_ShyGuySays; /* camera move on */
extern s16 D_80109DBC_24D6CC_ShyGuySays; /* camera move frame */
extern s16 D_80109DBE_24D6CE_ShyGuySays; /* 1P result phase */
extern s16 D_80109DC0_24D6D0_ShyGuySays;
extern s32 D_80109DC4_24D6D4_ShyGuySays; /* quit fade countdown; retail reads its low half by label */
extern char D_80109DC8_24D6D8_ShyGuySays[6][2][0x20]; /* the two hand parts of each character */
extern s32 D_80109F48_24D858_ShyGuySays[6][4]; /* the hand models */
extern u16 D_80109FA8_24D8B8_ShyGuySays[6]; /* the shadow model */
extern s16 D_80109FB4_24D8C4_ShyGuySays[4]; /* voice pan */
extern s32 D_80109FBC_24D8CC_ShyGuySays; /* CPU penalty when every human is out */
extern s32 D_80109FC0_24D8D0_ShyGuySays; /* the round it was last counted */
extern Vec D_80109FC4_24D8D4_ShyGuySays[3]; /* puffs round a falling player */
extern f32 D_80109FE8_24D8F8_ShyGuySays[6]; /* shadow height */
extern Vec D_8010A000_24D910_ShyGuySays[3]; /* the background sprites */
extern f32 D_8010A024_24D934_ShyGuySays[3];
extern u32 D_8010A030_24D940_ShyGuySays;
extern u32 D_8010A034_24D944_ShyGuySays; /* flag wave */
extern s32 D_8010A038_24D948_ShyGuySays; /* shots in this round */
extern u16 D_8010A03C_24D94C_ShyGuySays; /* the flag asked for */
extern u16 D_8010A03E_24D94E_ShyGuySays;
extern u16 D_8010A040_24D950_ShyGuySays; /* the player shot */
extern f32 D_8010A044_24D954_ShyGuySays; /* the round's length */
extern SGSFlagVtx D_8010A048_24D958_ShyGuySays[4];
extern SGSFlagVtx D_8010A068_24D978_ShyGuySays[4];
extern f32 D_8010A088_24D998_ShyGuySays[4]; /* the angle that faces each player */
extern f32 D_8010A098_24D9A8_ShyGuySays; /* facing front */
extern Gfx D_8010A190_24DAA0_ShyGuySays[];
extern f32 D_8010A1D0_24DAE0_ShyGuySays[3]; /* sprite model scale */
extern Vec2f D_8010A1DC_24DAEC_ShyGuySays[3]; /* sprite model offset */

/* ---- .bss ---- */
extern Vec D_8010A560_24DE70_ShyGuySays;
extern Vec D_8010A56C_24DE7C_ShyGuySays;
extern omObjData* D_8010A578_24DE88_ShyGuySays; /* the main object */
extern s32 D_8010A57C_24DE8C_ShyGuySays; /* state timer */
extern s32 D_8010A580_24DE90_ShyGuySays; /* time bar */
extern s32 D_8010A584_24DE94_ShyGuySays; /* 1 intro, 2 play, 3 end */
extern s16 D_8010A588_24DE98_ShyGuySays; /* players left */
extern s16 D_8010A58A_24DE9A_ShyGuySays;
extern s16 D_8010A58C_24DE9C_ShyGuySays; /* round */
extern SGSVoice D_8010A590_24DEA0_ShyGuySays[4];
extern SGSPlayer D_8010A5D0_24DEE0_ShyGuySays[4];
extern s16 D_8010A870_24E180_ShyGuySays[5]; /* characters */
extern s16 D_8010A87A_24E18A_ShyGuySays; /* result shown */
extern s16 D_8010A87C_24E18C_ShyGuySays; /* 1P rule */
extern s16 D_8010A87E_24E18E_ShyGuySays; /* the human */
extern omObjData* D_8010A880_24E190_ShyGuySays; /* the Shy Guy */
extern u32 D_8010A888_24E198_ShyGuySays[3]; /* left and right flag: 1 down, 2 up; [2] set in the set-up */
extern u32 D_8010A894_24E1A4_ShyGuySays;
extern s32 D_8010A898_24E1A8_ShyGuySays; /* cannon state, 0 none */
extern SGSMot D_8010A8A0_24E1B0_ShyGuySays[7];
extern s32 D_8010A8BC_24E1CC_ShyGuySays; /* game state */
extern s16 D_8010A8C0_24E1D0_ShyGuySays[2];
extern f32 D_8010A8C4_24E1D4_ShyGuySays; /* the time to answer */
extern s32 D_8010A8C8_24E1D8_ShyGuySays; /* time bar on */
extern f32* D_8010A8CC_24E1DC_ShyGuySays; /* 1/i */
extern s16 D_8010A8D0_24E1E0_ShyGuySays[2];
extern s16 D_8010A8D4_24E1E4_ShyGuySays;
extern SGSFx D_8010A8D8_24E1E8_ShyGuySays[16];
extern SGSSound D_8010AA18_24E328_ShyGuySays[10];
extern SGSShot D_8010AA58_24E368_ShyGuySays[4];
extern SGSBack D_8010AB38_24E448_ShyGuySays[3];
extern s16 D_8010AB74_24E484_ShyGuySays;

/* ---- overlay functions ---- */
void func_80079E60_7AA60(void);
void func_80102800_246110_ShyGuySays(void);
void func_80102A04_246314_ShyGuySays(omObjData* obj);
void func_80102AFC_24640C_ShyGuySays(omObjData* obj);
void func_80102BE4_2464F4_ShyGuySays(void);
void func_80102C18_246528_ShyGuySays(omObjData* obj);
void func_80102F7C_24688C_ShyGuySays(omObjData* obj);
void func_80103104_246A14_ShyGuySays(omObjData* obj);
void func_801031AC_246ABC_ShyGuySays(void);
void func_80103218_246B28_ShyGuySays(omObjData* obj, f32 t);
void func_801033E0_246CF0_ShyGuySays(void);
void func_80103448_246D58_ShyGuySays(s16 id, s16 delay, s16 player);
void func_801034C0_246DD0_ShyGuySays(void);
void func_8010361C_246F2C_ShyGuySays(void);
void func_8010369C_246FAC_ShyGuySays(void);
u16 func_801036BC_246FCC_ShyGuySays(u16 range);
void func_8010372C_24703C_ShyGuySays(u16 seed);
f32 func_80103750_247060_ShyGuySays(f32 a, f32 b, f32 step);
f32 func_801038B8_2471C8_ShyGuySays(f32 y, f32 x);
void func_80103930_247240_ShyGuySays(s16 model, SGSMot* mot, s16 dir);
void func_80103A3C_24734C_ShyGuySays(s16 model);
void func_80103AB4_2473C4_ShyGuySays(s16 model);
s32 func_80103B28_247438_ShyGuySays(s16 model);
void func_80103BC0_2474D0_ShyGuySays(s16 model, omObjData* obj);
void func_80103C2C_24753C_ShyGuySays(omObjData* obj, SGSPlayer* p, u16 i, s32 file);
void func_80103CC4_2475D4_ShyGuySays(s16 dst, s16 src, s32 a, s32 b);
s16 func_80103EB0_2477C0_ShyGuySays(s16 model, char* name);
void func_80103FC0_2478D0_ShyGuySays(void);
void func_801040CC_2479DC_ShyGuySays(omObjData* obj);
void func_80104564_247E74_ShyGuySays(omObjData* obj);
void func_80104990_2482A0_ShyGuySays(omObjData* obj);
void func_80104D00_248610_ShyGuySays(omObjData* obj, s16 action);
void func_80104FF4_248904_ShyGuySays(s32 answer);
void func_80105154_248A64_ShyGuySays(void);
void func_80105278_248B88_ShyGuySays(void);
s16 func_80105348_248C58_ShyGuySays(void);
s16 func_801053C8_248CD8_ShyGuySays(void);
void func_801054AC_248DBC_ShyGuySays(void);
s16 func_801055D0_248EE0_ShyGuySays(void);
s16 func_8010568C_248F9C_ShyGuySays(u16 i, s16 answer);
void func_80105740_249050_ShyGuySays(u16 i);
void func_80105844_249154_ShyGuySays(u16* out);
void func_80105908_249218_ShyGuySays(s16 rank);
void func_80105974_249284_ShyGuySays(SGSPlayer* p, u16 i);
s32 func_80105A2C_24933C_ShyGuySays(SGSPlayer* p);
s32 func_80105B10_249420_ShyGuySays(void);
void func_80105B70_249480_ShyGuySays(omObjData* obj);
void func_80105E50_249760_ShyGuySays(omObjData* obj);
void func_80106130_249A40_ShyGuySays(omObjData* obj);
void func_80106250_249B60_ShyGuySays(void);
u16 func_80106258_249B68_ShyGuySays(s32 file);
void func_8010629C_249BAC_ShyGuySays(void);
void func_801063B4_249CC4_ShyGuySays(void);
s16 func_801064B0_249DC0_ShyGuySays(f32 x, f32 y, f32 z, s16 anim, u16 flags, u16 time);
void func_80106690_249FA0_ShyGuySays(omObjData* obj);
void func_80106A94_24A3A4_ShyGuySays(omObjData* obj);
void func_8010794C_24B25C_ShyGuySays(omObjData* obj, u16 cmd);
s16 func_801081B8_24BAC8_ShyGuySays(omObjData* obj);
f32 func_80108310_24BC20_ShyGuySays(void);
s16 func_80108340_24BC50_ShyGuySays(void);
s16 func_801083B4_24BCC4_ShyGuySays(void);
void func_80108430_24BD40_ShyGuySays(s16 model, s16 part, f32 s, SGSFlagVtx* a, SGSFlagVtx* b, f32 wx, f32 wy, f32 wz);
void func_80108828_24C138_ShyGuySays(void);
void func_801088EC_24C1FC_ShyGuySays(s32 total, s32 now);
void func_801089A8_24C2B8_ShyGuySays(void);
void func_80108A78_24C388_ShyGuySays(omObjData* obj);
void func_80108DCC_24C6DC_ShyGuySays(omObjData* target, f32 x, f32 y, f32 z);
s32 func_80108FD4_24C8E4_ShyGuySays(omObjData* target, SGSShot* s);
f32 func_80109170_24CA80_ShyGuySays(Vec* in, Vec* out);
s32 func_8010924C_24CB5C_ShyGuySays(void);
s32 func_80109280_24CB90_ShyGuySays(u16 i);
s32 func_801092C8_24CBD8_ShyGuySays(HuSprite_Unk84_Struct* spr, s32 kind);
s32 func_801099BC_24D2CC_ShyGuySays(HuSprite_Unk84_Struct* spr, HmfData* hmf, f32 scale, u16 x, u16 y);

#endif
