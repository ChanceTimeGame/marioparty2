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
#include "game/sprite.h"

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

#define RR_ABS(x) ((x) < 0.0f ? -(x) : (x))

/* func_8007A27C_7AE7C's camera sprite work (src/7AA60.c's CamSprWork). */
typedef struct RRCamSprWork {
    /* 0x00 */ s16 sprId;
    /* 0x04 */ f32 scaleX;
    /* 0x08 */ f32 scaleY;
    /* 0x0C */ f32 baseScaleX;
    /* 0x10 */ f32 baseScaleY;
    /* 0x14 */ f32 baseZoom;
    /* 0x18 */ f32 offsetX;
    /* 0x1C */ f32 offsetY;
    /* 0x20 */ Vec planePos;
    /* 0x2C */ void (*draw)(struct RRCamSprWork*);
    /* 0x30 */ HuCamera* cam;
} RRCamSprWork; /* size 0x34 */

/* ---- overlay functions ---- */

/* 144190.c */
void func_80102800_144190_RainbowRun(void);
void func_80102F3C_1448CC_RainbowRun(RRCamSprWork* work);
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
extern Gfx* D_800FDBCC_FE7CC; /* gMainGfxPos */
HuSprite* func_80082550_83150(s16 grpIdx, s16 idx);
s16 func_8001AAAC_1B6AC(s16 arg0, u16 arg1, u16 arg2);
s16 func_8001A2F8_1AEF8(s32 arg0);
void espDispOff(u16);
void func_8007A27C_7AE7C(s32 prio, s32 sprId, void* draw, f32 fov, Vec* eye, Vec* at);
void func_8002C59C_2D19C(s32, s32, s32, s32, s32);
void func_8000C38C_CF8C(void);
void func_8000C3C8_CFC8(void);
void func_8007273C_7333C(u8* arg0, u8 arg1);
void func_8000C018_CC18(u16);
void func_8000C460_D060(void);
void func_8000C578_D178(u8);
extern f32 D_800BF7AC_C03AC;
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_8002D4D0_2E0D0(s16 n);
void func_8002F290_2FE90(s32* arg0, s32 n);
void func_80020D20_21920(s16 arg0);
extern s32 D_800F9D30_FA930[];
extern u16 D_800FC87A_FD47A;
extern u16 D_800FA606_FB206;
extern u16 D_800F8FE0_F9BE0;
extern omObjData* D_800FC7B0_FD3B0[];
extern omObjData* D_800F9CE0_FA8E0[]; /* collision list, D_800FA606_FB206 entries */

/* An esprite slot (D_800F93FC_F9FFC[], 0x24 bytes). */
typedef struct RREspSlot {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ char unk_06[0x1E];
} RREspSlot;
extern RREspSlot* D_800F93FC_F9FFC;

/* Per-character data, 0x18 bytes each. */
typedef struct RRCharData {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s32 unk_04; /* model directory */
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10; /* model file */
    /* 0x14 */ char unk_14[4];
} RRCharData;
extern RRCharData D_800CD438_CE038[];
void func_800B8070_B8C70(f32 angle, f32* sin, f32* cos);
void func_8002A00C_2AC0C(s16 model);
void* func_80027154_27D54(s32 size, s32 tag); /* HuMemAllocTag */
extern s8 ContStkX[4];
extern s8 ContStkY[4];

/* ---- .data (14C080) ---- */

extern s32 D_8010A704_14C094_RainbowRun[2]; /* the title sprite's scroll x, y */
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

extern Vec D_8010A990_14C320_RainbowRun; /* the title camera's eye */
extern Vec D_8010A99C_14C32C_RainbowRun; /* the title camera's target */
extern omObjData* D_8010AC14_14C5A4_RainbowRun[3]; /* the followers */
extern s8 D_8010ACC0_14C650_RainbowRun[4]; /* [0] the player of group 0, [1..3] the others */
extern omObjData* D_8010ACC4_14C654_RainbowRun[3];

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
