#ifndef _OVL_1A_H
#define _OVL_1A_H

/* Overlay 1A: Handcar Havoc (2 vs 2), MP1's ovl_2F_HandcarHavoc (20F570.c, 216140.c,
   HandcarHavoc.h) ported to MP2's main API and reworked. Two teams pump a handcar each along a
   track (two viewports, one camera per team); a car that takes a bend too fast leans, tips over
   and throws its riders. MP2 adds a second track model (a lowered section and a jump), a 0x100
   work block with MP1's fields rearranged, and new sprite/marker objects (8010A870, 8010AD1C).

   Retail is two files: 19B590.c (game flow, cars, track helpers, timer, CPU) and 1A10F0.c from
   80108360 (MP1 216140.c's camera, seat/wheel helpers and sparks, then MP1 20F570.c's result
   flow and the marker objects). .data stays asm (1A3EB0; 19B590.c's .data is 8010B120-8010B176,
   1A10F0.c's from 8010B180); .rodata is carved per file (1A3F80, 1A4070).

   Types from the asm's accesses; MP1 names and offsets in the comments. */

#include "common.h"
#include "game/object.h"
#include "game/sprite.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"

/* ---------------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------------- */

/* A handcar (omObjData::unk_50 of D_8010D820[team], func_80027154_27D54(0x100)). No pointers.
   Model slots: [0] car, [1] lever, [2] lever (pumping), [4] the other lever model, [3+seat]
   riders (MP2: [6+seat]), [0xA]/[0xC] extra. MP1 HHCar (0xF8): offsets in the comments. */
typedef struct HHCar {
    /* 0x00 */ f32 unk00;
    /* 0x04 */ f32 pump;      /* pump power, +0.3 per A press (max 5) */
    /* 0x08 */ f32 speed;     /* along the track (negative = forward) */
    /* 0x0C */ f32 maxSpeed;
    /* 0x10 */ f32 leanIn;    /* both riders' stick lean */
    /* 0x14 */ f32 lean;      /* follows leanIn by 2 per frame */
    /* 0x18 */ f32 tilt;      /* side tilt; +-25 tipping, +-60 fallen */
    /* 0x1C */ char unk1C[4];
    /* 0x20 */ Vec rot;       /* MP1 0x2C */
    /* 0x2C */ Vec prevRot;   /* MP1 0x38 */
    /* 0x38 */ Vec slope;     /* MP1 0x44 */
    /* 0x44 */ Vec prevSlope; /* MP1 0x50 */
    /* 0x50 */ char unk50[0xC];
    /* 0x5C */ f32 dist[2];   /* each axle's distance into its track segment (MP1 0x68) */
    /* 0x64 */ f32 progress;  /* MP1 0x78 */
    /* 0x68 */ f32 unk68;
    /* 0x6C */ f32 decel;     /* MP1 0x80 */
    /* 0x70 */ f32 seat[2];   /* riders' side offsets (D_8010B14C by character; MP1 0x84) */
    /* 0x78 */ f32 tipTimer;  /* MP1 0x8C */
    /* 0x7C */ f32 skidTimer; /* MP1 0x90 */
    /* 0x80 */ f32 unk80;     /* MP1 0x94 */
    /* 0x84 */ f32 fallV0;    /* fall arc: v0, t, g, angle, side speed (MP1 0x98) */
    /* 0x88 */ f32 fallT;
    /* 0x8C */ f32 fallG;
    /* 0x90 */ f32 fallAngle;
    /* 0x94 */ f32 fallSide;
    /* 0x98 */ u16 unk98;
    /* 0x9A */ s16 unk9A;     /* 0x1A7 */
    /* 0x9C */ u16 cpu;       /* 1: both riders are COMs (MP1 0xAC) */
    /* 0x9E */ s16 unk9E;     /* MP1 0xAE */
    /* 0xA0 */ u16 team;      /* MP1 0xB0 */
    /* 0xA2 */ u16 player[2]; /* MP1 0xB2 */
    /* 0xA6 */ char unkA6[4];
    /* 0xAA */ u16 leverDir;  /* MP1 0xBA */
    /* 0xAC */ u16 lever1Dir;
    /* 0xAE */ u16 lever2Dir;
    /* 0xB0 */ s16 front[2];  /* MP1 0xC0 */
    /* 0xB4 */ char unkB4[4];
    /* 0xB8 */ u16 seg[2];    /* each axle's track segment (MP1 0xC4) */
    /* 0xBC */ u16 chips[2][2]; /* sparks per side and wheel (max D_8010B144; MP1 0xC8) */
    /* 0xC4 */ u16 brake;     /* MP1 0xD0 */
    /* 0xC6 */ u16 sndOn;
    /* 0xC8 */ s16 snd;
    /* 0xCA */ u16 sparkSndOn;
    /* 0xCC */ s16 sparkSnd;
    /* 0xCE */ char unkCE[2];
    /* 0xD0 */ u16 marker;    /* map marker sprite (MP1 0xDC) */
    /* 0xD2 */ u16 face[2];   /* riders' faces on the map */
    /* 0xD6 */ u16 goal;      /* MP1 0xE2 */
    /* 0xD8 */ u16 stopTimer;
    /* 0xDA */ char unkDA[4];
    /* 0xDE */ u16 cpuStickTime[2]; /* MP1 0xEA */
    /* 0xE2 */ u16 cpuBrakeTime[2];
    /* 0xE6 */ s8 cpuStick[2];
    /* 0xE8 */ u8 cpuDelay[2];
    /* 0xEA */ u8 unkEA;
    /* 0xEB */ u8 unkEB;      /* 1: the lowered section's markers were dropped */
    /* 0xEC */ u8 unkEC;      /* 1: the second set was dropped */
    /* 0xED */ u8 unkED;      /* blinking marker: shown/hidden */
    /* 0xEE */ u8 unkEE;      /* its blink counter */
    /* 0xEF */ char unkEF;
    /* 0xF0 */ s32 cheerMot[2]; /* a rider's cheer motion file (random of two per seat) */
    /* 0xF8 */ s32 loseMot[2];
} HHCar; /* size = 0x100 */

/* One frame's input for a rider (stick x/y, pressed, held). */
typedef struct HHPad {
    /* 0x00 */ s8 stkX;
    /* 0x01 */ s8 stkY;
    /* 0x02 */ u16 trg;
    /* 0x04 */ u16 btn;
} HHPad; /* size = 6 */

/* Per-character data (main D_800CD438_CE038, 0x18 bytes each). */
typedef struct HHCharData {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 dir;   /* the character's file directory */
    /* 0x08 */ s32 model; /* its model file */
    /* 0x0C */ char unk_0C[0xC];
} HHCharData; /* size = 0x18 */

/* The sun light's direction (D_8010B368). */
typedef struct HHLightDir {
    s16 x;
    s16 y;
    s16 z;
} HHLightDir;

/* obj->work[0..3] tested as one big-endian word (retail: lw + and 0x06000000 = work[0] & 6).
   Host hazard: on a little-endian host this is work[3]; the port wants (obj)->work[0] & 6. */
#define HH_DONE(obj) (*(u32*)(obj)->work & 0x06000000)

/* ---------------------------------------------------------------------------------------------
   Main code used here and missing from include/
   --------------------------------------------------------------------------------------------- */

extern Vec3f D_801013B0_101FB0[]; /* CenterM */
extern Vec3f D_80102770_103370[]; /* CRotM */
extern f32 D_800F94A8_FA0A8[];    /* CZoomM */
extern s32 D_800F9D30_FA930[];
extern f32 D_80101300_101F00;     /* model load scale */
extern HHCharData D_800CD438_CE038[];
extern u8 D_800FD8AC[];            /* COM difficulty for the whole minigame (_CheckFlag(0xC)) */
extern s8 ContStkX[4];
extern s8 ContStkY[4];

omObjData* omAddObj(s16, u16, u16, s16, void*);
void omDelObj(omObjData*);
void omSetTra(omObjData*, f32, f32, f32);
void omSetRot(omObjData*, f32, f32, f32);
void omSetObjPrio(omObjData*, s16);
s16 LoadFormFile(s32, s32);
s32 PlaySound(s16);
void espDispOn(u16);
void espDispOff(u16);
void espPosSet(u16 spriteId, s16 x, s16 y);
s16 func_8001A2F8_1AEF8(s32 arg0);
void func_8001A340_1AF40(s16, f32, f32, f32);
s16 func_8001AAAC_1B6AC(s16 arg0, u16 arg1, u16 arg2);
void func_8001A708_1B308(u16, u16);
void func_8001A91C_1B51C(u16 spriteId, f32 x, f32 y);
void func_80018CCC_198CC(omObjData* obj, u16 slot, s32 file);
u16 func_80018A64_19664(s32 arg0, s32 arg1);
void func_80018ED0_19AD0(s32);
void func_80018F58_19B58(s32);
void func_80020D20_21920(s16 arg0);
void func_80026D28_27928(s32);
void func_80026D50_27950(s16, u8, u8);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16, f32, f32, f32);
void* func_80027154_27D54(s32 size, s32 tag);
s16 func_80027D3C_2893C(s16 linkMdlId);
void func_80029708_2A308(s32);
void func_80029714_2A314(s16, f32, f32, f32);
void func_8002979C_2A39C(s16, f32, f32, f32);
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029A8C_2A68C(s16);
void func_80029AFC_2A6FC(s16);
void func_80029B80_2A780(s16 arg0, s16 arg1);
f32 func_80029CE4_2A8E4(s16);
f32 func_80029D0C_2A90C(s16);
void func_80029BF0_2A7F0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4); /* model motion blend */
s32 func_80029E14_2AA14(s16 arg0); /* 2AA14.c: u8; retail callers re-extend the result */
void func_80029E80_2AA80(s16, s32, s32);
void func_80029EDC_2AADC(s16, s16);
void func_8002BB4C_2C74C(s16 arg0, char* arg1, char* arg2);
void func_8002C59C_2D19C(s32, s32, s32, s32, s32);
void func_8002CA48_2D648(u8 arg0, u8 arg1, u8 arg2);
void func_8002D4D0_2E0D0(s16 n);
void func_8002F290_2FE90(s32* arg0, s32 n);
void func_8006D4D0_6E0D0(s16);
void func_8006D518_6E118(void);
void func_8007273C_7333C(u8* arg0, u8 arg1);
void func_80076BD0_777D0(s32, s32);
omObjData** func_80076D80_77980(s32);
void func_80079128_79D28(void);
s16 func_80079798_7A398(s16 sfx, s16 player);
void func_800796F0_7A2F0(s16 sound, s16 pitch);
void func_80079848_7A448(s16 arg0);
f64 fabs(f64);
f32 fabsf(f32);
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* cos */
void func_800B2060_B2C60(f32* m, f32 x, f32 y, f32 z); /* rotate matrix (MP1 func_8009ECB0) */
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
u8 rand8(void);
s32 _CheckFlag(s32);
void InitFadeIn(s32, s32);

/* ---------------------------------------------------------------------------------------------
   Overlay functions (all 65; MP1 ancestor in the comment). Those after 80105940 are inferred
   from registers and callers: forks B and C check their own.
   --------------------------------------------------------------------------------------------- */

/* 19B590.c */
void func_80102800_19B590_HandcarHavoc(void);                          /* MP1 F65E0: setup */
void func_80102E40_19BBD0_HandcarHavoc(omObjData* obj);                /* F72B0 */
void func_80102EAC_19BC3C_HandcarHavoc(omObjData* obj);                /* F7314: race flow */
void func_801030F4_19BE84_HandcarHavoc(omObjData* obj);                /* F757C: scenery */
void func_801032F4_19C084_HandcarHavoc(void);                          /* empty */
void func_801032FC_19C08C_HandcarHavoc(void);                          /* F7DD8: map */
void func_801033B0_19C140_HandcarHavoc(omObjData* obj);                /* F7E8C */
void func_801033EC_19C17C_HandcarHavoc(omObjData* obj);                /* F7EC8 */
void func_80103428_19C1B8_HandcarHavoc(omObjData* obj, u16 team, f32 x, s32 y, f32 z); /* F7F04: car init */
void func_80103DE4_19CB74_HandcarHavoc(omObjData* obj);                /* F8730: car */
void func_8010484C_19D5DC_HandcarHavoc(omObjData* obj);                /* F8E00: tilt */
u16 func_80104C00_19D990_HandcarHavoc(omObjData* obj);                 /* F917C */
void func_80104DE0_19DB70_HandcarHavoc(omObjData* obj);                /* F93DC: place models */
f32 func_801051E8_19DF78_HandcarHavoc(s8 stk);                         /* F9774 */
void func_801052B8_19E048_HandcarHavoc(omObjData* obj);                /* FA318: stop */
void func_80105394_19E124_HandcarHavoc(omObjData* obj);                /* FA3B8 */
void func_80105940_19E6D0_HandcarHavoc(omObjData* obj);                /* FA8C0 */
void func_80105FEC_19ED7C_HandcarHavoc(omObjData* obj);
void func_801060A4_19EE34_HandcarHavoc(omObjData* obj);
void func_80106164_19EEF4_HandcarHavoc(omObjData* obj);                /* FBA80: intro */
void func_8010625C_19EFEC_HandcarHavoc(omObjData* obj);                /* FBB78: result */
void func_801067A0_19F530_HandcarHavoc(void);                          /* FC058 */
void func_801068CC_19F65C_HandcarHavoc(u16 team, u16 i, Vec* out);     /* FC124 */
void func_801069D8_19F768_HandcarHavoc(u16 team, u16 i, Vec* out);     /* FC2A0? */
f32 func_80106AD0_19F860_HandcarHavoc(u16 team, f32 x, f32 y, f32 z, u16 i); /* FC22C */
void func_80106B84_19F914_HandcarHavoc(u16 team, u16 i, Vec* out);
void func_80106CA8_19FA38_HandcarHavoc(omObjData* obj, Vec* rot, Vec* pos); /* FC338 */
u16 func_80106E70_19FC00_HandcarHavoc(omObjData* obj);                 /* FC4B0 */
void func_801074A8_1A0238_HandcarHavoc(omObjData* obj, u16 side);      /* FCA58 */
void func_80107634_1A03C4_HandcarHavoc(omObjData* obj);                /* FCBA4 */
void func_80107740_1A04D0_HandcarHavoc(omObjData* obj);                /* FCE3C: timer */
void func_801078B8_1A0648_HandcarHavoc(omObjData* obj);                /* FCFB4 */
void func_80107900_1A0690_HandcarHavoc(u16 time, u16* digit);          /* FCFFC */
s16 func_80107AB0_1A0840_HandcarHavoc(void);                           /* FC85C */
void func_80107C64_1A09F4_HandcarHavoc(omObjData* obj, HHPad* pad, u16 seat); /* F6BBC: COM */

/* 1A10F0.c */
void func_80108360_1A10F0_HandcarHavoc(omObjData* obj);                /* FD1B0 */
void func_80108398_1A1128_HandcarHavoc(s32 arg0);                      /* FD1E8 */
void func_801083B4_1A1144_HandcarHavoc(omObjData* obj);                /* FD204: cameras */
f32 func_801085F8_1A1388_HandcarHavoc(f32 x, f32 y, f32 z, ColVtx* vtx, s16* face); /* FD464 */
void func_80108730_1A14C0_HandcarHavoc(omObjData* obj, u16 seat, Vec* out); /* FD59C */
void func_80108A1C_1A17AC_HandcarHavoc(omObjData* obj, u16 side, Vec* out); /* FD888 */
void func_80108D5C_1A1AEC_HandcarHavoc(omObjData* obj);                /* FDBC8 */
u16 func_80108E80_1A1C10_HandcarHavoc(s16 mdl, u16 dir, f32 step);     /* FDCEC */
void func_80108FBC_1A1D4C_HandcarHavoc(s32 team);                      /* FE8D4 */
void func_8010929C_1A202C_HandcarHavoc(s32 team, s32 i, s32 buf, s32 arg3); /* FEB4C */
s16 func_80109484_1A2214_HandcarHavoc(s32 team, s16 side, s16 wheel, s16 arg3); /* FECF4 */
void func_8010986C_1A25FC_HandcarHavoc(HHCar* w);                      /* FF0AC */
void func_80109B88_1A2918_HandcarHavoc(omObjData* obj);                /* FAF64 */
void func_80109BA4_1A2934_HandcarHavoc(omObjData* obj);                /* FAF80 */
void func_80109BC0_1A2950_HandcarHavoc(omObjData* obj, s16 team);      /* FAF9C */
void func_80109D10_1A2AA0_HandcarHavoc(omObjData* obj);                /* FB0EC */
void func_8010A200_1A2F90_HandcarHavoc(omObjData* obj);                /* FB5DC */
void func_8010A400_1A3190_HandcarHavoc(void);                          /* FB7DC: empty */
void func_8010A408_1A3198_HandcarHavoc(omObjData* obj);                /* FB7E4 */
void func_8010A440_1A31D0_HandcarHavoc(omObjData* obj);                /* FB81C */
void func_8010A5B8_1A3348_HandcarHavoc(omObjData* obj);                /* FB994 */
void func_8010A6A4_1A3434_HandcarHavoc(f32* a, f32 step);              /* FBFA0 */
f32 func_8010A75C_1A34EC_HandcarHavoc(f32 x);                          /* FC7E0 */
void func_8010A7D8_1A3568_HandcarHavoc(omObjData* obj);                /* FBF5C */
void func_8010A870_1A3600_HandcarHavoc(omObjData* obj);
void func_8010AA30_1A37C0_HandcarHavoc(omObjData* obj);
void func_8010ABC8_1A3958_HandcarHavoc(f32 x, f32 y, u16* arg2);
void func_8010AD1C_1A3AAC_HandcarHavoc(omObjData* obj);
void func_8010AE30_1A3BC0_HandcarHavoc(omObjData* obj);
void func_8010B024_1A3DB4_HandcarHavoc(omObjData* obj, u8 arg1, s16 arg2, s16 arg3, u16 arg4);
u8 func_8010B0FC_1A3E8C_HandcarHavoc(omObjData* obj);
void func_8010B108_1A3E98_HandcarHavoc(omObjData* obj, s16 arg1);

/* ---------------------------------------------------------------------------------------------
   .data (asm, 1A3EB0)
   --------------------------------------------------------------------------------------------- */

/* 19B590.c */
extern s16 D_8010B120_1A3EB0_HandcarHavoc;     /* 1: time ran out */
extern s32 D_8010B124_1A3EB4_HandcarHavoc[6];  /* map face sprite per character */
extern f32 D_8010B13C_1A3ECC_HandcarHavoc[2];  /* axle offsets (-200, 200 in MP1 order) */
extern u16 D_8010B144_1A3ED4_HandcarHavoc[2][2]; /* sparks allowed per side and wheel */
extern f32 D_8010B14C_1A3EDC_HandcarHavoc[6];  /* seat offset per character */
extern s32 D_8010B164_1A3EF4_HandcarHavoc[2];
extern u16 D_8010B16C_1A3EFC_HandcarHavoc;     /* MP1 D_800FF3E0 */
extern f32 D_8010B170_1A3F00_HandcarHavoc;     /* MP1 D_800FF3E4 */
extern u16 D_8010B174_1A3F04_HandcarHavoc;     /* MP1 D_800FF3E8 (4); the file's .data ends here */
/* 1A10F0.c */
extern u16 D_8010B180_1A3F10_HandcarHavoc;     /* 1: leave (MP1 D_800FF400) */
extern Vec D_8010B184_1A3F14_HandcarHavoc[4];  /* wheel spots per side; split labels B188, B18C */
extern f32 D_8010B1B4_1A3F44_HandcarHavoc[8];  /* spark lengths */
extern u16 D_8010B1D4_1A3F64_HandcarHavoc;
extern s16 D_8010B1D8_1A3F68_HandcarHavoc[2];
extern u16 D_8010B1DC_1A3F6C_HandcarHavoc;
extern s16 D_8010B1DE_1A3F6E_HandcarHavoc[5];

/* ---------------------------------------------------------------------------------------------
   .bss (8010B310-8010D880)
   --------------------------------------------------------------------------------------------- */

extern f32 D_8010B310_1A40A0_HandcarHavoc;
extern f32 D_8010B314_1A40A4_HandcarHavoc;
extern f32 D_8010B318_1A40A8_HandcarHavoc[4];
extern f32 D_8010B328_1A40B8_HandcarHavoc;
extern f32 D_8010B32C_1A40BC_HandcarHavoc;
extern f32 D_8010B330_1A40C0_HandcarHavoc[4];
extern f32 D_8010B340_1A40D0_HandcarHavoc[2];
extern f32 D_8010B348_1A40D8_HandcarHavoc[2];
extern f32 D_8010B350_1A40E0_HandcarHavoc[2];
extern f32 D_8010B358_1A40E8_HandcarHavoc;
extern s32 D_8010B35C_1A40EC_HandcarHavoc;
extern u16 D_8010B360_1A40F0_HandcarHavoc;
extern s16 D_8010B362_1A40F2_HandcarHavoc;     /* _CheckFlag(0xC): COM difficulty preset */
extern s16 D_8010B364_1A40F4_HandcarHavoc;     /* frames to the next second */
extern s16 D_8010B366_1A40F6_HandcarHavoc;     /* seconds left (300) */
extern HHLightDir D_8010B368_1A40F8_HandcarHavoc; /* sun light direction */
extern s32 D_8010B370_1A4100_HandcarHavoc;
extern s16 D_8010B374_1A4104_HandcarHavoc;     /* sun light level (215) */
extern s16 D_8010B376_1A4106_HandcarHavoc[2];  /* per team: the track model it runs on */
extern s16 D_8010B37A_1A410A_HandcarHavoc;     /* track model 1 (0x2A0004) */
extern s16 D_8010B37C_1A410C_HandcarHavoc;     /* track model 2 (0x2A0005) */
extern ColVtx* D_8010B380_1A4110_HandcarHavoc[2]; /* per team: its track's points */
extern ColVtx* D_8010B388_1A4118_HandcarHavoc; /* track 1's points */
extern ColVtx* D_8010B38C_1A411C_HandcarHavoc; /* track 2's points */
extern u16 D_8010B390_1A4120_HandcarHavoc[2];  /* per team: its track's point count */
extern s16 D_8010B394_1A4124_HandcarHavoc;     /* track 1's point count */
extern s16 D_8010B396_1A4126_HandcarHavoc;     /* track 2's point count */
extern f32 D_8010B398_1A4128_HandcarHavoc[2];  /* per team: track length left */
extern f32 D_8010B3A0_1A4130_HandcarHavoc;     /* track 1's length */
extern f32 D_8010B3A4_1A4134_HandcarHavoc;     /* track 2's length */
extern omObjData* D_8010B3A8_1A4138_HandcarHavoc; /* scenery */
extern omObjData* D_8010B3AC_1A413C_HandcarHavoc; /* intro */
extern omObjData* D_8010B3B0_1A4140_HandcarHavoc; /* result */
extern u8 D_8010B420_1A41B0_HandcarHavoc[0x180];
extern u8 D_8010B5A0_1A4330_HandcarHavoc[0x180];
extern u8 D_8010B720_1A44B0_HandcarHavoc[0x180];
extern u8 D_8010B8A0_1A4630_HandcarHavoc[0x1F20]; /* sparks (MP1 D_800FFCC0) */
extern s16 D_8010D7C0_1A6550_HandcarHavoc[2][8];
extern omObjData** D_8010D7E0_1A6570_HandcarHavoc; /* the two cameras */
extern s16 D_8010D7E4_1A6574_HandcarHavoc;     /* sprite 0x43 */
extern u16 D_8010D800_1A6590_HandcarHavoc;     /* race state: 0 intro, 1 race, 2 over */
extern s16 D_8010D802_1A6592_HandcarHavoc;     /* team 0's map marker sprite */
extern omObjData* D_8010D804_1A6594_HandcarHavoc; /* race timer */
extern s16 D_8010D814_1A65A4_HandcarHavoc;     /* sprite 0x2A0011 */
extern omObjData* D_8010D818_1A65A8_HandcarHavoc[2]; /* per team: 8010AD1C's sign object */
extern omObjData** D_8010D820_1A65B0_HandcarHavoc; /* the two cars */
extern u16 D_8010D824_1A65B4_HandcarHavoc;     /* end state */
extern s16 D_8010D826_1A65B6_HandcarHavoc;     /* team 1's map marker sprite */
extern s16 D_8010D82A_1A65BA_HandcarHavoc;     /* map track piece sprite */
extern s16 D_8010D82C_1A65BC_HandcarHavoc;     /* sprite 0x2A0012 */
extern omObjData* D_8010D830_1A65C0_HandcarHavoc; /* 8010A870's object */
extern s16 D_8010D85C_1A65EC_HandcarHavoc;     /* sprite 0x43 */
extern u16 D_8010D85E_1A65EE_HandcarHavoc;
extern s16 D_8010D860_1A65F0_HandcarHavoc;
extern s16 D_8010D862_1A65F2_HandcarHavoc;     /* winning team, -1 none */
extern u16 D_8010D870_1A6600_HandcarHavoc;
extern s16 D_8010D872_1A6602_HandcarHavoc;     /* sprite 0x10016 */
extern s16 D_8010D874_1A6604_HandcarHavoc;     /* sprite 0x10015 */
extern s16 D_8010D876_1A6606_HandcarHavoc;     /* map goal sprite */
extern s16 D_8010D878_1A6608_HandcarHavoc;     /* sprite 0x2A0013 */

#endif
