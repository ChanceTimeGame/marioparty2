#ifndef _OVL_06_H
#define _OVL_06_H

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/data.h"
#include "game/collision.h"

/* Mallet-Go-Round, an item minigame for one player: a wheel of six slots turns and the player
   swings a mallet to knock items out of it. No MP1 ancestor; one retail file. .data is asm,
   .rodata carved from 0x10BCD0. */

/* One wheel slot, 0x20 bytes. */
typedef struct MGRSlot {
    /* 0x00 */ s8 item;
    /* 0x01 */ s8 hits;  /* blocks left, 0-2 */
    /* 0x02 */ s8 falling;
    /* 0x04 */ u16 timer;
    /* 0x08 */ f32 y;
    /* 0x0C */ f32 yBase;
    /* 0x10 */ f32 z;
    /* 0x14 */ f32 lift;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 bob;
} MGRSlot;

typedef struct MGRText {
    /* 0x00 */ s8 flag;
    /* 0x04 */ char* unk_04;
    /* 0x08 */ char* unk_08;
    /* 0x0C */ s32 unk_0C[2];
} MGRText;

/* ---- main-segment API missing from include/ ---- */
typedef struct MGRCharData {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s32 unk_04; /* model/motion directory */
    /* 0x08 */ s32 unk_08; /* model file */
    /* 0x0C */ char unk_0C[0xC];
} MGRCharData;
extern MGRCharData D_800CD438_CE038[];
typedef struct MGREspSlot {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ char unk_06[0x1E];
} MGREspSlot; /* size = 0x24 */
extern MGREspSlot* D_800F93FC_F9FFC;
extern u16 D_800CAFD8[]; /* item ids; the low byte is the item */
extern u16 D_800CAFE4[]; /* item odds, percent */
extern u16 D_800FA606_FB206;
extern u16 D_801011FC_101DFC;
extern u8 D_80102720_103320;
extern s8 ContStkX[4];
extern s8 ContStkY[4];
extern u16 ContBtn[4];
extern u16 ContBtnTrg[4];
extern Gfx* D_800FDBCC_FE7CC;

void* func_80027154_27D54(s32 size, s16 tag); /* HuMemAllocTag */
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size); /* memset */
u16 func_80018A64_19664(s32 file, s32 attr);
void func_80018CCC_198CC(omObjData* obj, u16 slot, s32 file);
u16 func_80020EBC_21ABC(void* arg0, s32 arg1, u8 arg2); /* 3D sprite */
void* DataRead(s32 dirAndFile);
void HuMemMemoryFreePerm(void* ptr);
u16 LoadFormFile(s32, s32);
void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
s16 func_80027D3C_2893C(s16 linkMdlId); /* model copy */
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void func_8002979C_2A39C(s16 idx, f32 x, f32 y, f32 z); /* model rotation */
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_800298A4_2A4A4(s16, s32, s32); /* model attribute */
void func_80029A8C_2A68C(s16);
void func_80029B80_2A780(s16 arg0, s16 arg1);
void func_80029C74_2A874(s16, f32); /* motion frame */
f32 func_80029CE4_2A8E4(s16);
f32 func_80029D0C_2A90C(s16);
s32 func_80029E14_2AA14(s16 arg0);
void func_80029E80_2AA80(s16, s32, s32);
void func_8002A00C_2AC0C(s16 model);
void espDispOff(u16);
s16 func_8001A2F8_1AEF8(s32);
s16 func_8001AAAC_1B6AC(s16, s32, s32);
extern int guRandom(void);
void func_8000BEB0_CAB0(omObjData* obj, f32 arg1);
void func_8000BEBC_CABC(omObjData* obj, f32 arg1);
void func_8000BEC8_CAC8(omObjData* obj, f32 arg1);
void func_8000C35C_CF5C(omObjData* obj, f32 x, f32 y, f32 z);
void func_8000C36C_CF6C(omObjData* obj, f32 x, f32 y, f32 z);
void func_8000C38C_CF8C(void);
void func_8000C398_CF98(void);
void func_8000C3A8_CFA8(void);
void func_8000C3B8_CFB8(void);
void func_8000C3C8_CFC8(void);
void func_8000C460_D060(void);
void func_8000C578_D178(s32);
void func_8002D4D0_2E0D0(s16 n);
void func_8002F290_2FE90(s32* arg0, s32 n);
void func_80020D20_21920(s16 arg0);
void func_80020070_20C70(s32);
void func_80021198_21D98(s16 index, u16 arg1);
void func_8002AC10_2B810(s16 arg0, f32 arg1, f32 arg2, s32 arg3);
void func_8002C524_2D124(s16, s16, s16);
void func_8002C570_2D170(s16);
void func_8002C628_2D228(s16 arg0, s16 arg1, char* arg2);
void func_80069770_6A370(void);
void func_80079868_7A468(void);
void func_80079128_79D28(void);
void func_8002C59C_2D19C(s32, s32, s32, s32, s32);
void func_8007273C_7333C(u8* arg0, u8 arg1);
void func_8007A27C_7AE7C(s32 prio, s32 sprId, void* draw, f32 fov, Vec* eye, Vec* at);
HuSprite* func_80082550_83150(s16 grpIdx, s16 idx);
void func_800794A8_7A0A8(s32);
void func_800798F8_7A4F8(s16 sound, s16 pan);
omObjData* func_800732B0_73EB0(u32 arg0);
u16 func_80078EA8_79AA8(void);
s16 func_800691FC_69DFC(s16 mesNo, ...); /* MP1 GMesCreate */
s32 func_80069538_6A138(void);           /* MP1 GMesStatAllGet */
void func_8006D4D0_6E0D0(s16);           /* the seconds counter */
void func_8006D518_6E118(void);
s32 func_8008F618_90218(void);
s32 PlaySound(s32);
s16 PlayMusic(s16);
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
void InitFadeIn(s32, s32);
void InitFadeOut(s32, s32);
u8 rand8(void);
f32 func_800B75A8_B81A8(f32 y, f32 x); /* atan2, degrees */
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* cos */

/* ---- .data and .bss, in address order (asm) ---- */
extern s8 D_80108450_10BC10_MalletGoRound; /* 1: the game is over */
extern s8 D_80108451_10BC11_MalletGoRound; /* 1: the players may start */
extern s8 D_80108452_10BC12_MalletGoRound; /* 1: the slots are in place */
extern s8 D_80108453_10BC13_MalletGoRound; /* result: -1 none yet, 0 item lost, 1/2 won */
extern s8 D_80108454_10BC14_MalletGoRound; /* scene state, 0-10 (func_801042D4) */
extern s8 D_80108455_10BC15_MalletGoRound; /* item in the broken slot, -1 none */
extern s8 D_80108456_10BC16_MalletGoRound; /* 1: a hit is stopping the wheel */
extern s8 D_80108457_10BC17_MalletGoRound; /* wheel direction: 0 forward, 1 back */
extern s8 D_80108458_10BC18_MalletGoRound; /* 1: throw the mallet away */
extern s8 D_80108459_10BC19_MalletGoRound; /* 1: the won item bobs */
extern s8 D_8010845A_10BC1A_MalletGoRound; /* 1: stop the countdown */
extern s8 D_8010845B_10BC1B_MalletGoRound; /* 1: the music was faded */
extern f32 D_8010845C_10BC1C_MalletGoRound;
extern s8 D_80108460_10BC20_MalletGoRound; /* 1: the mallet is swinging */
extern s8 D_80108461_10BC21_MalletGoRound;
extern s8 D_80108462_10BC22_MalletGoRound; /* follow-through step */
extern s32 D_80108464_10BC24_MalletGoRound; /* swing frame */
extern s8 D_80108468_10BC28_MalletGoRound; /* 1: the CPU plan is made */
extern s8 D_80108469_10BC29_MalletGoRound; /* 1: the CPU target is chosen */
extern s32 D_8010846C_10BC2C_MalletGoRound; /* CPU wait */
extern f32 D_80108470_10BC30_MalletGoRound; /* thrown mallet speed */
extern u32 D_80108474_10BC34_MalletGoRound; /* time left, frames */
extern f32 D_80108478_10BC38_MalletGoRound; /* bob angle */
extern MGRText D_8010847C_10BC3C_MalletGoRound; /* debug text; holds pointers to the strings at 80108530/80108544 */
extern s8 D_80108490_10BC50_MalletGoRound;
extern s8 D_80108494_10BC54_MalletGoRound[8]; /* stick history */
extern s8 D_8010849C_10BC5C_MalletGoRound[8];
extern s8 D_801084A4_10BC64_MalletGoRound;
extern u32 D_801084A8_10BC68_MalletGoRound; /* random seed */
extern f32 D_801084B0_10BC70_MalletGoRound; /* wheel angle */
extern s8 D_801084B4_10BC74_MalletGoRound; /* 1: the wheel is stopped */
extern s8 D_801084B5_10BC75_MalletGoRound; /* 1: stopped for good */
extern s8 D_801084B6_10BC76_MalletGoRound; /* 1: start the ending */
extern s32 D_801084B8_10BC78_MalletGoRound;
extern s8 D_801084BC_10BC7C_MalletGoRound; /* 1: the sparkles run */
extern u16 D_801084BE_10BC7E_MalletGoRound; /* wheel stop time */
extern f32 D_801084C0_10BC80_MalletGoRound;
extern f32 D_801084C4_10BC84_MalletGoRound;
extern f32 D_801084C8_10BC88_MalletGoRound; /* wheel speed */
extern f32 D_801084CC_10BC8C_MalletGoRound;
extern s8 D_801084D0_10BC90_MalletGoRound;
extern s8 D_801084D1_10BC91_MalletGoRound;
extern f32 D_801084D4_10BC94_MalletGoRound;
extern f32 D_801084D8_10BC98_MalletGoRound;
extern s32 D_801084DC_10BC9C_MalletGoRound;
extern s32 D_801084E0_10BCA0_MalletGoRound;
extern f32 D_801084E4_10BCA4_MalletGoRound;
extern f32 D_801084E8_10BCA8_MalletGoRound;
extern s8 D_801084EC_10BCAC_MalletGoRound;
extern s8 D_801084ED_10BCAD_MalletGoRound;
extern s8 D_801084EE_10BCAE_MalletGoRound;
extern f32 D_801084F0_10BCB0_MalletGoRound;
extern f32 D_801084F4_10BCB4_MalletGoRound;
extern Vec D_801084F8_10BCB8_MalletGoRound;
extern f32 D_80108504_10BCC4_MalletGoRound;
extern f32 D_80108508_10BCC8_MalletGoRound;
extern u16 D_8010850C_10BCCC_MalletGoRound;
extern Vec D_80108650_10BE10_MalletGoRound; /* background camera eye */
extern Vec D_8010865C_10BE1C_MalletGoRound; /* its target */
extern f32 D_80108668_10BE28_MalletGoRound;
extern f32 D_8010866C_10BE2C_MalletGoRound; /* hit effect time */
extern f32 D_80108670_10BE30_MalletGoRound; /* hit effect scale */
extern u16 D_80108674_10BE34_MalletGoRound; /* CPU plan: roll */
extern u16 D_80108676_10BE36_MalletGoRound; /* its running sum (undefined_syms.txt label) */
extern u32 D_80108678_10BE38_MalletGoRound;
extern s8 D_8010867C_10BE3C_MalletGoRound; /* CPU target slot */
extern s8 D_8010867D_10BE3D_MalletGoRound; /* best slot, 1-5 */
extern f32 D_80108680_10BE40_MalletGoRound;
extern s8 D_80108684_10BE44_MalletGoRound; /* walk-in frames */
extern u16 D_80108686_10BE46_MalletGoRound; /* ending frames (undefined_syms.txt label) */
extern s16 D_80108688_10BE48_MalletGoRound; /* ending length */
extern Vec D_80108690_10BE50_MalletGoRound;
extern Vec D_8010869C_10BE5C_MalletGoRound;
extern Vec D_801086A8_10BE68_MalletGoRound;
extern u8 D_801086B4_10BE74_MalletGoRound; /* next sparkle */
extern Vec D_801086B8_10BE78_MalletGoRound;
extern MGRSlot D_801086D0_10BE90_MalletGoRound[6]; /* the wheel, slot 0 = the bomb/empty */
extern omObjData* D_80108794_10BF54_MalletGoRound; /* the mallet */
extern omObjData* D_80108798_10BF58_MalletGoRound; /* the sparkles */
extern omObjData* D_8010879C_10BF5C_MalletGoRound; /* the slots */
extern omObjData* D_801087A0_10BF60_MalletGoRound; /* the player */
extern s8 D_801087A4_10BF64_MalletGoRound; /* slot hit */
extern s8 D_801087A5_10BF65_MalletGoRound; /* the player index */
extern omObjData* D_801087A8_10BF68_MalletGoRound; /* the wheel */

/* .rodata */
extern const u32 D_80108510_10BCD0_MalletGoRound[18];
extern const u8 D_80108558_10BD18_MalletGoRound[16]; /* item -> gPlayers[].coins_mg_bonus */

void func_80102800_105FC0_MalletGoRound(void);
void func_80102C14_1063D4_MalletGoRound(omObjData* obj);
void func_80102CAC_10646C_MalletGoRound(omObjData* obj);
void func_801037B0_106F70_MalletGoRound(omObjData* obj);
void func_80103DB4_107574_MalletGoRound(omObjData* obj);
void func_80103E7C_10763C_MalletGoRound(omObjData* obj);
void func_80103F78_107738_MalletGoRound(omObjData* obj, s32 dir, s32 file, u16 player, f32 x, f32 y, f32 z);
void func_801042D4_107A94_MalletGoRound(void);
void func_80104BC8_108388_MalletGoRound(s16* arg0);
void func_801050B0_108870_MalletGoRound(f32 fov, f32 x, f32 y, f32 z, f32 rx, f32 ry, f32 rz);
void func_801050F0_1088B0_MalletGoRound(void);
s32 func_80105168_108928_MalletGoRound(omObjData* obj, omObjData* item);
s32 func_80105224_1089E4_MalletGoRound(omObjData* obj, omObjData* item);
void func_80105284_108A44_MalletGoRound(omObjData* obj);
f32 func_80105308_108AC8_MalletGoRound(void);
u32 func_801054D4_108C94_MalletGoRound(u32 seed);
u32 func_801055A8_108D68_MalletGoRound(void);
u16 func_801055D0_108D90_MalletGoRound(s32 file, s32 attr, u8 arg2);
void func_80105630_108DF0_MalletGoRound(omObjData* obj);
void func_80105EEC_1096AC_MalletGoRound(omObjData* obj);
void func_801062EC_109AAC_MalletGoRound(omObjData* obj);
void func_80106C7C_10A43C_MalletGoRound(omObjData* obj);
void func_801079EC_10B1AC_MalletGoRound(omObjData* obj);
void func_80107F50_10B710_MalletGoRound(omObjData* obj);
void func_801082A8_10BA68_MalletGoRound(omObjData* obj);
void func_801083D8_10BB98_MalletGoRound(void);
void func_801083F8_10BBB8_MalletGoRound(void);
void func_80108404_10BBC4_MalletGoRound(s16 model, s16 arg1);

#endif
