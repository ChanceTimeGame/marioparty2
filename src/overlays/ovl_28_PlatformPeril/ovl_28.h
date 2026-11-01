#ifndef _OVL_28_H
#define _OVL_28_H

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/data.h"
#include "game/collision.h"
#include "game/board.h"

/* Platform Peril, a 4P race along a course of moving platforms: the first to reach the goal
   platform wins. Retail files 205BA0.c and 20B4D0.c (from 80108130, 1-nop pad; .data 0x20C3E0 and 0x20C570 (801091D0), .rodata 0x20C740);
   .rodata from 0x20C580. */

/* Cloud sprite (D_801093BC_20C75C_PlatformPeril, 5 of them). */
typedef struct PPCloud {
    /* 0x00 */ u8 index;
    /* 0x01 */ u8 sprite;
    /* 0x02 */ char unk_02[2];
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
    /* 0x0C */ f32 phase;  /* wobble angle */
    /* 0x10 */ f32 amp;    /* wobble scale */
    /* 0x14 */ f32 rate;   /* wobble degrees per frame */
    /* 0x18 */ f32 drift;  /* pixels per frame */
    /* 0x1C */ f32 w;
    /* 0x20 */ f32 h;
} PPCloud; /* size = 0x24 */

/* Rows of one platform kind (D_80109048_20C3E8_PlatformPeril[kind]): where each next one appears. */
typedef struct PPSeq {
    /* 0x00 */ u8 master; /* ground index of the model the rest clone */
    /* 0x01 */ u8 next;
    /* 0x02 */ u8 rows[11]; /* 0 ends the list; row * 100 is -z */
} PPSeq; /* size = 0xD */

/* The goal platform's list: like PPSeq, but its rows run on to the next table. */
typedef struct PPGoalSeq {
    /* 0x00 */ u8 master;
    /* 0x01 */ u8 next;
    /* 0x02 */ u8 rows[26];
} PPGoalSeq; /* size = 0x1C */

/* All the lists: eight platform kinds, then the goal platform's. */
typedef struct PPSeqTable {
    /* 0x00 */ PPSeq seq[8];
    /* 0x68 */ PPGoalSeq goal;
} PPSeqTable; /* size = 0x84 */

/* Scenery strip (D_801090D8_20C478_PlatformPeril[2]). */
typedef struct PPStrip {
    /* 0x00 */ omObjData* obj; /* the first, its model is cloned */
    /* 0x04 */ char unk_04;
    /* 0x05 */ u8 next;
    /* 0x06 */ s8 x[5];
    /* 0x0B */ u8 z[5];
} PPStrip; /* size = 0x10 */

/* Per-platform state (D_801093F0_20C790_PlatformPeril, by GroundWork.unk_04). */
typedef struct PPPlat {
    /* 0x00 */ u8 state;  /* 2 rest, 3 shaking, 4 falling */
    /* 0x01 */ u8 kind;
    /* 0x02 */ u8 timer;
    /* 0x03 */ u8 speed;  /* fall speed; 0 does not fall */
    /* 0x04 */ f32 z;
    /* 0x08 */ f32 depth;
    /* 0x0C */ s8 dir;
    /* 0x0D */ char unk_0D;
    /* 0x0E */ s8 tex;
    /* 0x0F */ s8 goal;
} PPPlat; /* size = 0x10 */

/* What a player stands closest to (D_80109550_20C8F0_PlatformPeril[player]). */
typedef struct PPNear {
    /* 0x00 */ omObjData* obj;
    /* 0x04 */ u8 kind;
    /* 0x08 */ f32 dist;
    /* 0x0C */ u8 plat;
} PPNear; /* size = 0x10 */

enum PPFlowState { PP_NONE = -1, PP_INTRO, PP_START, PP_WAIT, PP_RACE, PP_GOAL, PP_WINCAM };

typedef struct PPFlow {
    /* 0x00 */ u16 state;
    /* 0x02 */ u16 timer;
} PPFlow;

/* Camera key (D_80109148_20C4E8_PlatformPeril[4]; D_801093B8_20C758_PlatformPeril holds 3 built at the end). */
typedef struct PPCamKey {
    /* 0x00 */ f32 time;
    /* 0x04 */ u32 zoom;
    /* 0x08 */ Vec center;
    /* 0x14 */ Vec rot;
} PPCamKey; /* size = 0x20 */

typedef struct PPCharData {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s32 unk_04; /* model/motion directory */
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
} PPCharData; /* size = 0x18 */

/* ---- main-segment API missing from include/ ---- */
extern PPCharData D_800CD438_CE038[];
extern s8 ContStkX[4];
extern s8 ContStkY[4];
extern s8 D_800BF795_C0395;
extern s32 D_800F8FD0_F9BD0;
extern f32 D_800F94A8_FA0A8[];    /* CZoomM */
extern omObjData* D_800F9CE0_FA8E0[]; /* collision list, D_800FA606_FB206 entries */
extern u16 D_800FA606_FB206;
extern u16 D_801011FC_101DFC;
extern Vec3f D_801013B0_101FB0[]; /* CenterM */
extern Vec3f D_80102770_103370[]; /* CRotM */


void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
f32 HuMathSin(f32);
u16 LoadFormFile(s32, s32);
s32 PlaySound(s32);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprAttrReset(s16 grpIdx, s16 idx, s32 flag);
void SprAttrSet(s16 grpIdx, s16 idx, s32 flag);
void SprBankSet(s16 group, s16 member, s16 bank); /* u16 bank in main; retail passes an s16 */
s16 SprCreate(s32 num, s32 attr);
void SprPosSet(s16, s16, s16, s16);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
void SprRotSet(s16 group, s16 member, f32 rot);
void SprScaleSet(s16 group, s16 member, f32 x, f32 y);
void func_80007790_8390(omObjData* obj);
void func_8000BDC4_C9C4(omObjData* obj, u16 idx, s32 dir, s32 file, f32 arg4);
void func_8000BE8C_CA8C(omObjData*, f32);
void func_8000BEB0_CAB0(omObjData* obj, f32 arg1);
void func_8000BF54_CB54(omObjData*, f32, f32, f32, f32, f32, f32);
void func_8000C018_CC18(u16);
void func_8000C024_CC24(omObjData* obj, u8 idx, s8 val);
void func_8000C2A0_CEA0(omObjData* obj, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_8000C37C_CF7C(omObjData* obj, f32 x, f32 y, f32 z);
void func_8000C460_D060(void);
void func_8000C578_D178(s32);
void func_8000C6FC_D2FC(omObjData* obj, u32 dir, s32 file, u16 player, s32 arg4, s32 arg5);
u16 func_80018D64_19964(s32 arg0, s32 arg1, s32 arg2);
void func_80018F58_19B58(s32);
void func_80019378_19F78(omObjData* obj);
s32 func_80019B9C_1A79C(omObjData* obj, u16 motion);
void func_80019E84_1AA84(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4);
s16 func_8001A2F8_1AEF8(s32 arg0);
void func_80020D20_21920(s16 arg0);
u16 func_8002109C_21C9C(s16 index, s32 arg1);
void func_800211E8_21DE8(s16 index, u8 arg1);
void func_80021250_21E50(s16 index, u8 arg1, u8 arg2, u8 arg3);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void* func_80027154_27D54(s32 size, s16 tag);
s16 func_80027D3C_2893C(s16 linkMdlId);
void func_80029714_2A314(s16, f32, f32, f32);
void func_800297E8_2A3E8(s16, f32, f32, f32);
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029A8C_2A68C(s16);
void func_8002A00C_2AC0C(s16 model);
void func_8002BCA8_2C8A8(s16 model, f32 s, f32 t, s32 arg3, s32 arg4);
void func_8002D4D0_2E0D0(s16 n);
s16 func_800691FC_69DFC(s16 mesNo, ...);
s32 func_80069538_6A138(void);
void func_8007273C_7333C(char* arg0, u8 arg1);
omObjData* func_800732B0_73EB0(u32 arg0);
u16 func_80078EA8_79AA8(void);
s16 func_800797DC_7A3DC(s32 sfx, s16 player);
void func_80079FF4_7ABF4(omObjData* object);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
void func_80082488_83088(s16, s16, u16);
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size);
f32 func_800B1830_B2430(f32);
f32 func_800B75A8_B81A8(f32 y, f32 x);
f32 func_800B7890_B8490(f32);
int abs(int);
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);

/* ---- .data, in address order (C, in 205BA0.c and 20B4D0.c) ---- */
extern f32 D_80109040_20C3E0_PlatformPeril;   /* camera target z */
extern u8 D_80109044_20C3E4_PlatformPeril;    /* clouds */
extern u8 D_80109045_20C3E5_PlatformPeril;    /* platforms */
extern PPSeqTable D_80109048_20C3E8_PlatformPeril;
/* Retail names these apart from the list (so the compiler cannot share one base): linker aliases of D_80109048.goal.next and .rows. */
extern u8 D_801090B1_20C451_PlatformPeril;
extern u8 D_801090B2_20C452_PlatformPeril[];
extern f32 D_801090CC_20C46C_PlatformPeril[3];
extern PPStrip D_801090D8_20C478_PlatformPeril[2];
extern s8 D_801090F8_20C498_PlatformPeril[20]; /* actors: x / 100 */
extern u8 D_8010910C_20C4AC_PlatformPeril[20]; /* actors: -z / 100 */
extern u8 D_80109120_20C4C0_PlatformPeril;    /* actors placed */
extern s8 D_80109121_20C4C1_PlatformPeril;    /* the winner, -1 none */
extern u8 D_80109122_20C4C2_PlatformPeril;    /* the goal platform */
extern u8 D_80109123_20C4C3_PlatformPeril;    /* players who fell */
extern u8 D_80109124_20C4C4_PlatformPeril;    /* the goal platform moves */
extern s16 D_80109126_20C4C6_PlatformPeril;   /* _CheckFlag(0xC): the 1P rule */
extern s16 D_80109128_20C4C8_PlatformPeril;   /* the human */
extern u8 D_8010912A_20C4CA_PlatformPeril;
extern f32 D_8010912C_20C4CC_PlatformPeril;
extern f32 D_80109130_20C4D0_PlatformPeril[];
extern f32 D_80109134_20C4D4_PlatformPeril[];
extern f32 D_80109138_20C4D8_PlatformPeril[];
extern f32 D_8010913C_20C4DC_PlatformPeril[];
extern u8 D_80109140_20C4E0_PlatformPeril; /* the winner walks in: frames left */
extern u8 D_80109141_20C4E1_PlatformPeril; /* its stick angle */
extern u8 D_80109142_20C4E2_PlatformPeril; /* the walk is over */
extern u8 D_80109143_20C4E3_PlatformPeril; /* the angle is set */
extern u8 D_80109144_20C4E4_PlatformPeril;
extern u8 D_80109145_20C4E5_PlatformPeril;
extern PPCamKey D_80109148_20C4E8_PlatformPeril[4];
extern f32 D_801091C8_20C568_PlatformPeril;
extern u8 D_801091CC_20C56C_PlatformPeril; /* camera key */
extern u8 D_801091CD_20C56D_PlatformPeril; /* its frame */
extern s8 D_801091D0_20C570_PlatformPeril[4]; /* retail reads 6: runs into D_801091D4_20C574_PlatformPeril */
extern s8 D_801091D4_20C574_PlatformPeril[6];

/* ---- .bss ---- */
extern u8 D_801093B0_20C750_PlatformPeril;
extern PPFlow D_801093B2_20C752_PlatformPeril;
extern u16 D_801093B4_20C754_PlatformPeril;   /* = D_801093B2_20C752_PlatformPeril.timer: retail also reads it by its own label */
extern PPCamKey* D_801093B8_20C758_PlatformPeril;
extern PPCloud* D_801093BC_20C75C_PlatformPeril;
extern u8 D_801093C0_20C760_PlatformPeril[4]; /* start lane per player */
extern u8 D_801093D0_20C770_PlatformPeril[4]; /* CPU steering extra */
extern f32 D_801093D8_20C778_PlatformPeril[4]; /* CPU jump distance */
extern PPPlat D_801093F0_20C790_PlatformPeril[22];
extern PPNear D_80109550_20C8F0_PlatformPeril[4];

#define PP_RAND() ((rand8() << 8) | rand8())
#define PP_RAND1() ((f32)(PP_RAND() % 201 - 100) / 100.0f)
#define PP_CENTERZ (D_801013B0_101FB0[0].z)
#define PP_RANGE(lo, hi) ((f32)(PP_RAND() % (s32)(((hi) - (lo)) + 1.0f)) + (lo))

void func_80102800_205BA0_PlatformPeril(void);
void func_8010281C_205BBC_PlatformPeril(PPCloud* c, u8 index, f32 w, f32 h);
void func_80102970_205D10_PlatformPeril(void);
s32 func_80102CC8_206068_PlatformPeril(s32 file, s32 prio, s32 attr, s32 alpha);
void func_80102DC8_206168_PlatformPeril(omObjData* obj);
void func_80102FE4_206384_PlatformPeril(void);
void func_80103018_2063B8_PlatformPeril(omObjData* obj, PPPlat* p);
void func_801032D8_206678_PlatformPeril(omObjData* obj);
void func_801037F0_206B90_PlatformPeril(omObjData* obj);
void func_80103B7C_206F1C_PlatformPeril(omObjData* obj, omObjData* src, s32 file, f32 x, f32 y, f32 z, u8 clone);
void func_80103D00_2070A0_PlatformPeril(omObjData* obj);
void func_80103DDC_20717C_PlatformPeril(omObjData* obj);
void func_80103EF8_207298_PlatformPeril(omObjData* obj);
void func_80104070_207410_PlatformPeril(omObjData* obj);
void func_801041EC_20758C_PlatformPeril(omObjData* obj);
void func_801043DC_20777C_PlatformPeril(omObjData* obj);
void func_801045A4_207944_PlatformPeril(omObjData* obj);
void func_80104734_207AD4_PlatformPeril(omObjData* obj);
void func_801048C4_207C64_PlatformPeril(omObjData* obj);
void func_80104A54_207DF4_PlatformPeril(omObjData* obj);
void func_80104BE4_207F84_PlatformPeril(void);
void func_80105088_208428_PlatformPeril(omObjData* obj);
void func_80105204_2085A4_PlatformPeril(omObjData* obj);
void func_80105434_2087D4_PlatformPeril(omObjData* obj);
void func_80105660_208A00_PlatformPeril(omObjData* obj, omObjData* src, s32 file, f32 x, f32 y, f32 z, u8 clone);
void func_8010571C_208ABC_PlatformPeril(omObjData* obj);
void func_8010587C_208C1C_PlatformPeril(omObjData* obj);
void func_801059E0_208D80_PlatformPeril(void);
void func_80105A70_208E10_PlatformPeril(omObjData* obj);
void func_80105D74_209114_PlatformPeril(omObjData* obj);
void func_80106040_2093E0_PlatformPeril(omObjData* obj);
void func_80106314_2096B4_PlatformPeril(void);
void func_801063A0_209740_PlatformPeril(u8 port);
void func_801064C4_209864_PlatformPeril(omObjData* obj);
void func_801068B4_209C54_PlatformPeril(omObjData* obj);
void func_801069BC_209D5C_PlatformPeril(omObjData* obj);
void func_80106B24_209EC4_PlatformPeril(omObjData* obj);
void func_80106CBC_20A05C_PlatformPeril(omObjData* obj);
void func_80106FEC_20A38C_PlatformPeril(void);
void func_8010707C_20A41C_PlatformPeril(void);
void func_801075D0_20A970_PlatformPeril(omObjData* obj);
void func_8010762C_20A9CC_PlatformPeril(void);
void func_80107650_20A9F0_PlatformPeril(omObjData* obj);
void func_80107688_20AA28_PlatformPeril(omObjData* obj);
void func_801076D0_20AA70_PlatformPeril(PPCamKey* k);
void func_80107844_20ABE4_PlatformPeril(PPCamKey* k, f32 t);
void func_8010796C_20AD0C_PlatformPeril(void);
void func_80107DA0_20B140_PlatformPeril(void);
void func_80107EEC_20B28C_PlatformPeril(void);
void func_80108130_20B4D0_PlatformPeril(u8 port);
void func_8010816C_20B50C_PlatformPeril(u16 difficulty, u8 player);
void func_8010826C_20B60C_PlatformPeril(omObjData* obj, f32* angle);
void func_801084FC_20B89C_PlatformPeril(omObjData* obj);
void func_801086A8_20BA48_PlatformPeril(omObjData* obj, f32* angle);
void func_801089AC_20BD4C_PlatformPeril(omObjData* obj, f32* angle);
void func_80108CB0_20C050_PlatformPeril(omObjData* obj, MgWork* w);
void func_80108E78_20C218_PlatformPeril(omObjData* obj);
#endif
