#ifndef _OVL_29_H
#define _OVL_29_H

/* Overlay 29: Totem Pole Pound (4P). Each player stands on a pedestal above a totem pole
   (TPPPole, D_80108300_212250_TotemPolePound[4]) and pounds it into the ground: A jumps (charge while held),
   B (0x2000 in ContBtnTrg) at the right height slams with a power level 0-2 (func_80103BB4: the
   jump's height as a percentage of the character's best, against D_80106E74/E78). The pole sinks
   unk08 steps per pound; at 15 (TPPPole::sunk) it is in. The first players to finish are recorded in
   D_801072C8_211218_TotemPolePound (TPPGame); a 30-second timer runs out otherwise. Game flow is the state
   D_80108288_2121D8_TotemPolePound run by func_801067A0_2106F0 (1 intro, 2 poles rise, 3 camera in, 4 start
   message, 5 "start", 6 play, 7 result, 8 wait, 9 fade, 10 done). The winners (the first to
   finish; with several the order is shuffled by func_80105FC8 and only the first counts) get
   gPlayers[].coins_mg_bonus = 10. _CheckFlag(0xC) skips the result message.
   Retail is two files: 20C750.c (80102800-80106BC0) and 210B10.c from 80106BC0 (the two table
   clears, LookAway's 16B3E0.c twin; 2-nop text pad). .rodata is carved from 0x210F90 (20C750.c
   only); .data (0x210BC0-0x210F90) is still the asm blob.
   All C; NON_MATCHING: 80102CB4, 801036DC, 80103E24, 80105368, 80105C64, 801064CC.
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

/* One entry of D_801072F0_211240_TotemPolePound[50] (cleared by func_80106BC0_210B10): LookAway's LAObj. Entries
   0-3 are the players by slot, 4 the stage (sprite backdrop), 5-8 the poles by player. */
typedef struct TPPObj {
    /* 0x00 */ omObjData* obj;
    /* 0x04 */ s16 spr;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ u16 unk_20;
    /* 0x22 */ u16 unk_22;
    /* 0x24 */ u16 unk_24;
    /* 0x26 */ u16 unk_26;
    /* 0x28 */ u16 unk_28;
    /* 0x2A */ u16 unk_2A;
    /* 0x2C */ u16 unk_2C;
    /* 0x2E */ u16 player;
    /* 0x30 */ s16 unk_30;
    /* 0x32 */ s16 unk_32;
    /* 0x34 */ s16 unk_34;
    /* 0x36 */ s16 unk_36;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
} TPPObj; /* size = 0x48 (N64) */

/* A dust puff (TPPFxWork::fx). */
typedef struct TPPFx {
    /* 0x00 */ char unk_00[2];
    /* 0x02 */ s16 alpha;   /* read as a u8 */
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
    /* 0x0C */ f32 z;
    /* 0x10 */ s16 id;      /* effect slot (D_800F86D8_F92D8) */
    /* 0x12 */ char unk_12[2];
} TPPFx; /* size = 0x14 */

/* D_80108100_212050_TotemPolePound->unk_50 (allocated 0x150): 4 puffs per player, fx[n * 4 + player]. */
typedef struct TPPFxWork {
    /* 0x000 */ TPPFx fx[16];
    /* 0x140 */ u8 state[16];
} TPPFxWork; /* size = 0x150 */

/* A player's totem pole (D_80108300_212250_TotemPolePound[4]). */
typedef struct TPPPole {
    /* 0x00 */ s32 state;   /* 1 rising, 2 still, 3 pounded */
    /* 0x04 */ u32 sunk;    /* steps driven in; 15 = done */
    /* 0x08 */ u32 depth;   /* steps of the current pound (power + 1) */
    /* 0x0C */ f32 floor;   /* y it sinks to */
    /* 0x10 */ f32 vel;
    /* 0x14 */ f32 acc;
    /* 0x18 */ s32 power;   /* 0-2: index of the shake tables */
    /* 0x1C */ u32 timer;
    /* 0x20 */ f32 spin;
    /* 0x24 */ f32 spinVel;
    /* 0x28 */ f32 spinAcc;
    /* 0x2C */ s16 anim;    /* hmf animation */
    /* 0x2E */ char unk_2E[2];
    /* 0x30 */ omObjData* obj;
} TPPPole; /* size = 0x34 (N64) */

/* A player's state (D_80108108_212058_TotemPolePound[4]). */
typedef struct TPPPlayer {
    /* 0x00 */ u32 state;   /* func_80104B98's state */
    /* 0x04 */ s32 chr;     /* character */
    /* 0x08 */ s32 won;
    /* 0x0C */ f32 height;  /* jump height so far */
    /* 0x10 */ f32 best;    /* the character's full jump height */
    /* 0x14 */ f32 vel;
    /* 0x18 */ f32 grav;
    /* 0x1C */ f32 grav2;
    /* 0x20 */ s32 released;
    /* 0x24 */ s32 power;
    /* 0x28 */ u32 sub;     /* motion sub-state */
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ f32 mtnTime;
    /* 0x34 */ f32 mtnSpeed;
    /* 0x38 */ s32 com;
    /* 0x3C */ s32 dif;     /* CPU difficulty */
    /* 0x40 */ u32 chance[3]; /* CPU: power-level chances (rand8 < chance[power]) */
    /* 0x4C */ u32 holdChance;
    /* 0x50 */ u32 jumpChance;
    /* 0x54 */ s32 holding;
    /* 0x58 */ u32 wait;
    /* 0x5C */ omObjData* obj;
} TPPPlayer; /* size = 0x60 (N64) */

/* The game (D_801072C8_211218_TotemPolePound; func_801068B0 clears 0x24 bytes). */
typedef struct TPPGame {
    /* 0x00 */ s32 rate;    /* 30: frames per timer step */
    /* 0x04 */ s32 time;    /* seconds left (30); read as an s16 at 0x06 */
    /* 0x08 */ u32 timer;
    /* 0x0C */ s32 over;
    /* 0x10 */ u32 nwin;
    /* 0x14 */ s32 win[4];  /* players by finishing order */
} TPPGame; /* size = 0x24 */

#define TPP_ABS(x) ((x) < 0.0 ? -(x) : (x))

/* ---- .data (asm, 0x210BC0-0x210F90) ---- */
extern s32 D_80106C70_210BC0_TotemPolePound[6];        /* voice directory by character */
extern u16 D_80106C88_210BD8_TotemPolePound[4];        /* voice file by D_80107250 */
extern s32 D_80106C90_210BE0_TotemPolePound[4];        /* dust textures (dir 0x39) */
extern f32 D_80106CA0_210BF0_TotemPolePound[4][3];     /* pole positions by player */
extern f32 D_80106CD0_210C20_TotemPolePound[4][2];     /* pole rise: vel, acc */
extern f32 D_80106CF0_210C40_TotemPolePound[4][2];     /* pole rise: spin vel, spin acc */
extern f32 D_80106D10_210C60_TotemPolePound[3];        /* shake amplitude by power */
extern u32 D_80106D1C_210C6C_TotemPolePound[3];        /* shake period by power */
extern u16 D_80106D28_210C78_TotemPolePound[4][2];     /* [1]: slot by player */
extern s32 D_80106D38_210C88_TotemPolePound[6][8];     /* motion files by character */
extern f32 D_80106DF8_210D48_TotemPolePound[4][3];     /* player positions */
extern f32 D_80106E28_210D78_TotemPolePound[6][3];     /* jump: vel, grav, grav2 by character */
extern f32 D_80106E74_210DC4_TotemPolePound[];         /* = D_80106E70[0][1] ({0, 45, 95}[6]): power 1 from */
extern f32 D_80106E78_210DC8_TotemPolePound[];         /* = D_80106E70[0][2]: power 2 from */
extern f32 D_80106EB8_210E08_TotemPolePound[3];        /* pole sink per power */
extern f32 D_80106EC4_210E14_TotemPolePound[6][2];     /* pound power 0: vel, acc */
extern f32 D_80106EF4_210E44_TotemPolePound[6][2];     /* power 1 */
extern f32 D_80106F24_210E74_TotemPolePound[6][2];     /* power 2 */
extern f32 D_80106F54_210EA4_TotemPolePound[6][3];     /* landing motion speed by power */
extern u32 D_80106F9C_210EEC_TotemPolePound[3][3][3];  /* CPU power chances [difficulty][rand][power] */
extern u32 D_80107008_210F58_TotemPolePound[3];        /* CPU hold chance by difficulty */
extern u32 D_80107014_210F64_TotemPolePound[3];        /* CPU jump chance by difficulty */
extern f32 D_80107020_210F70_TotemPolePound;           /* camera shake x */
extern f32 D_80107024_210F74_TotemPolePound;           /* camera shake y */
extern u32 D_80107028_210F78_TotemPolePound;           /* shake x period */
extern u32 D_8010702C_210F7C_TotemPolePound;           /* shake y period */
extern s16 D_80107030_210F80_TotemPolePound;           /* music started */
extern u8 D_80107032_210F82_TotemPolePound;            /* a player won */

/* ---- .bss ---- */
extern u8 D_80107250_2111A0_TotemPolePound[4][2];       /* voice index by player */
extern s16 D_80107260_2111B0_TotemPolePound[50];       /* sprite animations */
extern TPPGame D_801072C8_211218_TotemPolePound;
extern s32 D_801072CC_21121C_TotemPolePound;  /* = D_801072C8.time */
extern u32 D_801072D0_211220_TotemPolePound;  /* = D_801072C8.timer */
extern s32 D_801072D4_211224_TotemPolePound;  /* = D_801072C8.over (retail reads it by label) */
extern u32 D_801072D8_211228_TotemPolePound;  /* = D_801072C8.nwin */
extern TPPObj D_801072F0_211240_TotemPolePound[50];
extern omObjData* D_80107410_211360_TotemPolePound;    /* = D_801072F0[4].obj */
extern s16 D_80107414_211364_TotemPolePound;           /* = D_801072F0[4].spr */
extern omObjData* D_80108100_212050_TotemPolePound;    /* the dust object */
extern TPPPlayer D_80108108_212058_TotemPolePound[4];
extern u16 D_80108288_2121D8_TotemPolePound;           /* game state */
extern s16 D_80108290_2121E0_TotemPolePound[4][14];    /* sound effects by player */
extern TPPPole D_80108300_212250_TotemPolePound[4];

/* ---- main ---- */
typedef struct TPPCharData {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 dir;     /* the character's file directory */
    /* 0x08 */ s32 model;
    /* 0x0C */ s32 model2;
    /* 0x10 */ char unk_10[8];
} TPPCharData; /* size = 0x18 */

extern TPPCharData D_800CD438_CE038[];
extern s8 ContStkX[4];
extern s8 ContStkY[4];
extern f32 D_800F94A8_FA0A8[];    /* CZoomM */
extern Vec D_80102770_103370[];   /* CRotM */
extern Vec D_801013B0_101FB0[];   /* CenterM */
extern s16 D_800FA606_FB206;
extern u16 D_801011FC_101DFC;
extern f32 D_800BF7D4_C03D4;
s16 LoadFormFile(s32, s32);
s32 PlaySound(s32);
s16 PlayMusic(s16);
void* DataRead(s32 dirAndFile);
void HuMemMemoryFreePerm(void* ptr);
u8 rand8(void);
s32 _CheckFlag(s32);
void InitFadeIn(s32, s32);
void InitFadeOut(s32, s32);
s32 omOvlReturnEx(s16);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprAttrReset(s16 grpIdx, s16 idx, s32 flag);
void SprAttrSet(s16 grpIdx, s16 idx, s32 flag);
void SprBankSet(s16 group, s16 member, s16 bank);
s16 SprCreate(s32 num, s32 attr);
void SprPosSet(s16, s16, s16, s16);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
void SprScaleSet(s16 group, s16 member, f32 x, f32 y);
void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
void func_8000BE8C_CA8C(omObjData*, f32);
void func_8000BEA4_CAA4(omObjData*, f32);
void func_8000BF24_CB24(omObjData* obj, f32 arg1, f32 x0, f32 z0, f32 x1, f32 z1);
void func_8000C018_CC18(u16);
u16 func_80018A30_19630(s32 file, s32 attr);
void func_80018CCC_198CC(omObjData* obj, u16 slot, s32 file);
void func_80018E30_19A30(s32);
void func_80018F58_19B58(s32);
s16 func_8001A2F8_1AEF8(s32 arg0);
void func_80020D20_21920(s16 arg0);
u16 func_80020EBC_21ABC(void* arg0, s32 arg1, u8 arg2);
void func_80021160_21D60(s16 index, s32 arg1, s32 arg2);
void func_800211E8_21DE8(s16 index, u8 arg1);
void func_80021250_21E50(s16 index, u8 arg1, u8 arg2, u8 arg3);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16, f32, f32, f32);
void* func_80027154_27D54(s32 size, s16 tag);
void func_80029714_2A314(s16, f32, f32, f32);
void func_8002979C_2A39C(s16, f32, f32, f32);
void func_800297E8_2A3E8(s16, f32, f32, f32);
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029A8C_2A68C(s16);
void func_80029AFC_2A6FC(s16);
void func_80029B80_2A780(s16 arg0, s16 arg1);
void func_80029BF0_2A7F0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void func_80029C74_2A874(s16, f32);
f32 func_80029CE4_2A8E4(s16);
f32 func_80029D0C_2A90C(s16);
s32 func_80029E14_2AA14(s16 arg0);
f32 func_80029E3C_2AA3C(s16);
void func_80029EDC_2AADC(s16 arg0, u8 arg1);
void func_8002D4D0_2E0D0(s16 n);
s16 func_8003D8F0_3E4F0(HmfData*, void*, s16, char*);
s16 func_8003DF08_3EB08(void*);
void func_8003E4F4_3F0F4(s16 arg0, u8 arg1, u8 arg2);
void func_8003E560_3F160(s16, s32);
void func_8006D4D0_6E0D0(s16);
void func_8006D518_6E118(void);
s16 func_800691FC_69DFC(s16 mesNo, ...);
s32 func_80069538_6A138(void);
void func_8007273C_7333C(u8* arg0, u8 arg1);
omObjData* func_800732B0_73EB0(u32 arg0);
void func_80079128_79D28(void);
void func_800794A8_7A0A8(s32);
void func_80079614_7A214(s16 time);
s16 func_80079798_7A398(s16 sfx, s16 player);
void func_80079868_7A468(void);
void func_80079FF4_7ABF4(omObjData* object);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
s32 func_8008F618_90218(void);
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size);
void func_800B1F50_B2B50(f32* m, f32 x, f32 y, f32 z);
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
void osViBlack(u8 active);

/* ---- overlay functions ---- */

/* 20C750.c */
void func_80102800_20C750_TotemPolePound(void);
void func_8010281C_20C76C_TotemPolePound(s32 player);
void func_8010289C_20C7EC_TotemPolePound(omObjData* obj, u32 motion);
void func_801028D8_20C828_TotemPolePound(omObjData* obj, u16 motion, s16 arg2, s16 arg3);
f32 func_8010295C_20C8AC_TotemPolePound(omObjData* obj);
void func_801029BC_20C90C_TotemPolePound(omObjData* obj, u8 i);
void func_80102AC0_20CA10_TotemPolePound(s16 player, s16 sfx);
void func_80102B0C_20CA5C_TotemPolePound(s16 player, s32 kind);
f32 func_80102B78_20CAC8_TotemPolePound(f32 a, f32 b);
void func_80102BDC_20CB2C_TotemPolePound(void);
void func_80102BE4_20CB34_TotemPolePound(void);
void func_80102BEC_20CB3C_TotemPolePound(void);
void func_80102BF4_20CB44_TotemPolePound(omObjData* obj);
void func_80102CB4_20CC04_TotemPolePound(omObjData* obj);
void func_80102E10_20CD60_TotemPolePound(void);
void func_80102E4C_20CD9C_TotemPolePound(omObjData* obj, s16 n, s16 near);
void func_80102FBC_20CF0C_TotemPolePound(TPPPole* p);
s32 func_80103078_20CFC8_TotemPolePound(omObjData* obj);
s32 func_8010326C_20D1BC_TotemPolePound(omObjData* obj);
void func_80103424_20D374_TotemPolePound(omObjData* obj);
void func_801034A4_20D3F4_TotemPolePound(omObjData* obj);
void func_8010363C_20D58C_TotemPolePound(void);
void func_801036DC_20D62C_TotemPolePound(TPPPlayer* p);
void func_80103734_20D684_TotemPolePound(TPPPlayer* p);
void func_80103870_20D7C0_TotemPolePound(TPPPlayer* p);
f32 func_801038E4_20D834_TotemPolePound(TPPPlayer* p);
void func_80103950_20D8A0_TotemPolePound(TPPPlayer* p, f32 grav);
f32 func_801039B0_20D900_TotemPolePound(TPPPlayer* p);
f32 func_80103A4C_20D99C_TotemPolePound(TPPPlayer* p);
f32 func_80103ABC_20DA0C_TotemPolePound(TPPPlayer* p);
s32 func_80103AEC_20DA3C_TotemPolePound(TPPPlayer* p);
s32 func_80103B2C_20DA7C_TotemPolePound(TPPPlayer* p);
s32 func_80103BB4_20DB04_TotemPolePound(TPPPlayer* p);
void func_80103C48_20DB98_TotemPolePound(TPPPlayer* p);
void func_80103D64_20DCB4_TotemPolePound(TPPPlayer* p);
void func_80103E24_20DD74_TotemPolePound(TPPPlayer* p);
void func_80103FAC_20DEFC_TotemPolePound(TPPPlayer* p);
s32 func_80103FE4_20DF34_TotemPolePound(TPPPlayer* p);
s32 func_80104018_20DF68_TotemPolePound(TPPPlayer* p);
s32 func_8010404C_20DF9C_TotemPolePound(TPPPlayer* p);
u16 func_80104094_20DFE4_TotemPolePound(TPPPlayer* p);
u16 func_80104124_20E074_TotemPolePound(TPPPlayer* p);
void func_80104218_20E168_TotemPolePound(omObjData* obj);
void func_80104334_20E284_TotemPolePound(omObjData* obj);
s32 func_80104518_20E468_TotemPolePound(omObjData* obj);
s32 func_80104558_20E4A8_TotemPolePound(omObjData* obj);
s32 func_8010457C_20E4CC_TotemPolePound(omObjData* obj);
s32 func_801045DC_20E52C_TotemPolePound(omObjData* obj);
s32 func_80104630_20E580_TotemPolePound(omObjData* obj);
s32 func_801046D0_20E620_TotemPolePound(omObjData* obj);
s32 func_801047D4_20E724_TotemPolePound(omObjData* obj);
s32 func_801048A8_20E7F8_TotemPolePound(omObjData* obj);
s32 func_80104AB0_20EA00_TotemPolePound(omObjData* obj);
void func_80104B98_20EAE8_TotemPolePound(omObjData* obj);
void func_80104C9C_20EBEC_TotemPolePound(omObjData* obj);
void func_80104D18_20EC68_TotemPolePound(omObjData* obj);
void func_80105210_20F160_TotemPolePound(void);
void func_801052C8_20F218_TotemPolePound(void);
void func_80105368_20F2B8_TotemPolePound(omObjData* obj);
void func_80105558_20F4A8_TotemPolePound(omObjData* obj);
void func_80105794_20F6E4_TotemPolePound(void);
void func_801057DC_20F72C_TotemPolePound(TPPGame* g);
void func_801058DC_20F82C_TotemPolePound(void);
void func_80105A64_20F9B4_TotemPolePound(TPPGame* g);
void func_80105C64_20FBB4_TotemPolePound(TPPGame* g);
void func_80105E98_20FDE8_TotemPolePound(void);
void func_80105EEC_20FE3C_TotemPolePound(u32 state);
void func_80105F20_20FE70_TotemPolePound(u32 state);
s32 func_80105F54_20FEA4_TotemPolePound(void);
s32 func_80105F90_20FEE0_TotemPolePound(u32 state);
void func_80105FC8_20FF18_TotemPolePound(TPPGame* g);
s32 func_80106064_20FFB4_TotemPolePound(TPPGame* g);
s32 func_8010610C_21005C_TotemPolePound(TPPGame* g);
s32 func_801061FC_21014C_TotemPolePound(TPPGame* g);
s32 func_80106294_2101E4_TotemPolePound(TPPGame* g);
s32 func_80106384_2102D4_TotemPolePound(TPPGame* g);
s32 func_801063D0_210320_TotemPolePound(TPPGame* g);
s32 func_801064CC_21041C_TotemPolePound(TPPGame* g);
s32 func_8010661C_21056C_TotemPolePound(TPPGame* g);
void func_801066EC_21063C_TotemPolePound(omObjData* obj);
void func_80106710_210660_TotemPolePound(omObjData* obj);
void func_80106748_210698_TotemPolePound(omObjData* obj);
void func_801067A0_2106F0_TotemPolePound(omObjData* obj);
void func_801068B0_210800_TotemPolePound(omObjData* obj);
void func_801069A0_2108F0_TotemPolePound(void);

/* 210B10.c */
void func_80106BC0_210B10_TotemPolePound(void);
void func_80106C44_210B94_TotemPolePound(void);

#endif
