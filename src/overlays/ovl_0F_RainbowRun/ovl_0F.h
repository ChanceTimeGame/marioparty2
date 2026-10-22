#ifndef _OVL_0F_H
#define _OVL_0F_H

/* Overlay 0F: Rainbow Run. Its game code descends from MP1's ovl_1F_TightropeTreachery (197E20.c,
   19A360.c, 19ACC0.c, 19D510.c). Retail is three files: 144190.c, 1479E0.c from 80106050 and
   149120.c from 80107790. .data stays asm (14C080); .rodata is carved per file. Prototypes past
   801060D8 are inferred from register use (MG0F-B: check them). */

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"

typedef f32 Matrix4f[4][4];

/* ---- structs ---- */

/* A player object's work: main's minigame work (0x15C bytes; MP1's 0xE8 TTPlayerWork with fields
   from 0x50 moved). Fields from the asm. */
typedef struct RRPlayerWork {
    /* 0x00 */ char unk_00[0x57];
    /* 0x57 */ s8 port; /* controller port */
    /* 0x58 */ char unk_58[1];
    /* 0x59 */ s8 player; /* player index */
    /* 0x5A */ char unk_5A[0x102];
} RRPlayerWork; /* size = 0x15C */

#define RR_WORK(obj) ((RRPlayerWork*)(obj)->unk_50)

/* ---- overlay functions ---- */

/* 144190.c */
void func_80102800_144190_RainbowRun(void);
void func_80102F3C_1448CC_RainbowRun(omObjData* obj);
void func_80103648_144FD8_RainbowRun(omObjData* obj);
s32 func_801036CC_14505C_RainbowRun(omObjData* obj, omObjData* other);
void func_8010393C_1452CC_RainbowRun(omObjData* obj, s32 dir, s32 file, u16 player, f32 x, f32 y, f32 z);
void func_80103E1C_1457AC_RainbowRun(omObjData* obj);
void func_801041E4_145B74_RainbowRun(omObjData* obj);
void func_80104FB4_146944_RainbowRun(omObjData* obj);
void func_801057F0_147180_RainbowRun(f32 zoom, f32 rx, f32 ry, f32 rz, f32 cx, f32 cy, f32 cz);
void func_80105870_147200_RainbowRun(void);
void func_80105978_147308_RainbowRun(omObjData* obj);
void func_801059F0_147380_RainbowRun(omObjData* obj);
f32 func_80105A74_147404_RainbowRun(void);
void func_80105C40_1475D0_RainbowRun(Vec* pos, Vec* axis, f32 angle, Matrix4f m);
void func_80105E38_1477C8_RainbowRun(RRPlayerWork* work);
void func_80105ED4_147864_RainbowRun(omObjData* obj, f32 dist);
u32 func_80105F4C_1478DC_RainbowRun(u32 seed);
u32 func_80106020_1479B0_RainbowRun(void);

/* 1479E0.c */
void func_80106050_1479E0_RainbowRun(s16 model);
void func_801060D8_147A68_RainbowRun(omObjData* obj);
void func_80106838_1481C8_RainbowRun(void);
void func_80106CB8_148648_RainbowRun(omObjData* obj);
void func_80106D60_1486F0_RainbowRun(omObjData* obj);
void func_80106E70_148800_RainbowRun(omObjData* obj);
void func_80106E8C_14881C_RainbowRun(omObjData* obj);
void func_80107018_1489A8_RainbowRun(omObjData* obj, s32 arg1);
void func_801075FC_148F8C_RainbowRun(omObjData* obj);

/* 149120.c */
s8 func_80107790_149120_RainbowRun(omObjData* obj);
void func_80107878_149208_RainbowRun(void);
void func_80107A68_1493F8_RainbowRun(omObjData* obj);
void func_80107C5C_1495EC_RainbowRun(omObjData* obj);
void func_80108094_149A24_RainbowRun(omObjData* obj);
void func_8010815C_149AEC_RainbowRun(omObjData* obj, s16 arg1, s16 arg2);
void func_801087A8_14A138_RainbowRun(omObjData* obj);
void func_801087CC_14A15C_RainbowRun(omObjData* obj);
void func_801087F0_14A180_RainbowRun(omObjData* obj);
void func_80108814_14A1A4_RainbowRun(omObjData* obj);
void* func_80109240_14ABD0_RainbowRun(omObjData* obj, s32 arg1, s16 arg2, f32 arg3);
void func_80109534_14AEC4_RainbowRun(omObjData* obj);
void func_80109CC4_14B654_RainbowRun(omObjData* obj, s32 dir, s32 file, u16 player, f32 x, f32 y, f32 z, u16 idx);
void func_8010A42C_14BDBC_RainbowRun(omObjData* obj);
void func_8010A514_14BEA4_RainbowRun(omObjData* obj);
void func_8010A600_14BF90_RainbowRun(omObjData* obj);

/* MG0F-A */

/* ---- main-segment API used by 0F (missing from include/) ---- */

extern omObjData* D_800FFFD8_100BD8[]; /* player objects */
extern u16 D_801011FC_101DFC;
extern f32 D_80102750_103350[]; /* D_8010274C_10334C + 4: [1] is its z by retail's own label */
void func_80069770_6A370(void);
/* func_8000BF24_CB24: its second argument (s32 in main) is a float that retail passes in a1: callers
   cast (on the host the s32 slot would get a converted value, not the bits) */
void func_8000BF24_CB24(omObjData*, s32, f32, f32, f32, f32);
void func_8000BFF0_CBF0(omObjData*);
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
f32 func_800B75A8_B81A8(f32 y, f32 x); /* atan2, degrees */
u8 rand8(void);
void func_800B8070_B8C70(f32 angle, f32* sin, f32* cos);
void func_8002A00C_2AC0C(s16 model);
void* func_80027154_27D54(s32 size, s32 tag); /* HuMemAllocTag */
extern s8 ContStkX[4];
extern s8 ContStkY[4];

/* ---- .data (14C080) ---- */

extern s8 D_8010A751_14C0E1_RainbowRun; /* the camera shakes */
extern s16 D_8010A752_14C0E2_RainbowRun; /* shake frame */
extern f32 D_8010A754_14C0E4_RainbowRun;
extern f32 D_8010A758_14C0E8_RainbowRun[]; /* shake offsets x, y: [i * 2] */
extern f32 D_8010A75C_14C0EC_RainbowRun[]; /* [i * 2] (D_8010A758 + 4, retail's own label) */
extern s8 D_8010A778_14C108_RainbowRun; /* the fade-out started */
extern s8 D_8010A77C_14C10C_RainbowRun[8]; /* stick x history */
extern s8 D_8010A784_14C114_RainbowRun[8]; /* stick y history */
extern s8 D_8010A78C_14C11C_RainbowRun; /* next slot of the stick histories */
extern u16 D_8010A78E_14C11E_RainbowRun; /* func_80105E38's last buttons */
extern u32 D_8010A790_14C120_RainbowRun; /* random seed */

/* ---- .bss ---- */

extern f32 D_8010AA10_14C3A0_RainbowRun; /* camera zoom */
extern f32 D_8010ABEC_14C57C_RainbowRun; /* camera centre y */
extern f32 D_8010ABF4_14C584_RainbowRun; /* camera rot z */
extern f32 D_8010ABF8_14C588_RainbowRun; /* camera rot y */
extern f32 D_8010AC04_14C594_RainbowRun; /* camera centre z */
extern f32 D_8010AC10_14C5A0_RainbowRun; /* camera rot x */
extern f32 D_8010ACBC_14C64C_RainbowRun; /* camera centre x */
extern ColVtx* D_8010A9C0_14C350_RainbowRun; /* the rainbow's base vertices (func_80106050) */

/* MG0F-B */

#endif
