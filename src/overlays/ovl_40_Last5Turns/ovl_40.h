#ifndef _OVL_40_H
#define _OVL_40_H

/* Overlay 40 (2AEDB0.c): the Last 5 Turns event, a stand-alone scene (its own omInitObjMan) in
   the style of overlay 3F's duel scene. The host (MP1 ovl_3F_Last5Turns' successor) announces the
   last five turns, the players' status windows drop in one by one in rank order with their
   ranks, then the host announces a bonus event (D_80104B44: 0..2 picked at random, weighted by
   whether someone plays character 0; always 3 on board 5) and the player it favours
   (D_80104B20), which the board then applies. */

#include "common.h"
#include "game/board.h"
#include "game/object.h"
#include "game/camera.h"

/* ---- main-segment API used by 40 ---- */

/* A path the model walks (func_8005A718_5B318 in 58080); same as ovl_3F.h's. */
typedef struct ModelPathWork {
    /* 0x00 */ MBModel* model;
    /* 0x04 */ s16 count;
    /* 0x06 */ u16 index;
    /* 0x08 */ f32 speed;
    /* 0x0C */ Vec* points;
} ModelPathWork; /* size 0x10 */

/* Status-window layouts: four slots as from/to positions, and the frames the move takes (ovl_3F.h's
   Unk3FStatusLayout). */
typedef struct L5StatusLayout {
    /* 0x00 */ s16 pos[4][4]; /* x0, y0, x1, y1; -1 keeps the current value */
    /* 0x20 */ s16 unk20;
    /* 0x22 */ s16 frames;
} L5StatusLayout; /* size 0x24 */

extern u16 D_801011FC_101DFC;
extern s16 D_800FA604_FB204;
extern BoardStatus D_80101510_102110[];
extern Vec2f D_800FC990_FD590[];
extern Vec2f D_800FD854_FE454[];

void HidePlayerHUDVisibility(s32 arg0, s32 arg1);
void Hu3DCamSetPositionOrientation(s16, Vec*, Vec*, Vec*);
void Hu3DCamUpdateMtx(s16 camIndex);
void HuVecCopyXYZ(Vec*, f32, f32, f32);
void MBDBackKill(void);
MBModel* MBModelFileCreate(s32 arg0, s32 arg1, f32 arg2, f32 arg3, u32* arg4);
void MBMotionShiftSet(void* arg0, s16 arg1, s32 arg2, s32 arg3, u16 arg4);
s32 PlaySound(s32);
void ShowTextWindow(s32 arg0);
void* func_80027154_27D54(s32, s32); /* HuMemAllocTag */
void func_80043DAC_449AC(MBModel*);
omObjData* func_800446B4_452B4(MBModel* arg0, Vec* arg1, s32 arg2);
void func_80050AE0_516E0(void);
void func_8005321C_53E1C(f32, f32);
void func_80056658_57258(Vec*, Vec*, Vec*); /* direction from a to b as a rotation */
void func_8005762C_5822C(s32 arg0);
void func_80057DA4_589A4(s32 arg0);
void func_800581A0_58DA0(void);
void func_800593C0_59FC0(void);
void func_80059400_5A000(void);
s32 func_80059FD0_5ABD0(s32 player); /* the player's rank, 0 = first */
ModelPathWork* func_8005A718_5B318(MBModel* model, f32 speed, s16 count, Vec* points);
s32 func_8005A778_5B378(ModelPathWork*); /* path finished */
void func_8005AB50_5B750(MBModel* arg0, s16 arg1, s16 arg2, s32 arg3);
void func_8005E2B8_5EEB8(void);
void func_8005FE10_60A10(void);
void func_800600F8_60CF8(s32, s16, s16);
void func_800614B4_620B4(s32, s32);
s32 func_800696E4_6A2E4(void);
void func_80069770_6A370(void);
void func_80088640_89240(void);
/* s16 in 58080.c; retail re-extends the result here, as if it were an int. */
s32 func_800888A8_894A8(s16, s16, s16, s16, s32, s16);
void func_800890CC_89CCC(s16, s32, s32, s32);
void func_80089284_89E84(s16, s32, s32);
void func_80089308_89F08(s16, char*, s32); /* window message argument */
void func_80089A48_8A648(s16, s16);
void func_80089B2C_8A72C(s16, s16);
void func_8008AD44_8B944(s16);
void func_8008CCA8_8D8A8(s16);
void func_8008CE5C_8DA5C(void);
void func_8008D88C_8E48C(s16);
void func_8008D974_8E574(char*, s16);
void func_8008DACC_8E6CC(s32, s16*, s32); /* a message's window size */
void omDelObj(omObjData*);
int sprintf(char* dst, const char* fmt, ...);

/* ---- overlay 40 data and bss ---- */

extern s32 D_80104940_2B0EF0_Last5Turns;
extern s32 D_80104944_2B0EF4_Last5Turns;
extern s32 D_80104948_2B0EF8_Last5Turns[4];
extern L5StatusLayout D_80104958_2B0F08_Last5Turns[2];
extern s32 D_801049A0_2B0F50_Last5Turns; /* the next status window to drop in */
extern s32 D_801049A4_2B0F54_Last5Turns;
extern s16 D_801049A8_2B0F58_Last5Turns[4];
extern Vec D_801049B0_2B0F60_Last5Turns; /* the host's place */
extern Vec D_801049BC_2B0F6C_Last5Turns; /* the event model's place */
extern Vec D_801049C8_2B0F78_Last5Turns;
extern Vec D_801049D4_2B0F84_Last5Turns;
extern u32 D_80104A30_2B0FE0_Last5Turns[];
extern u32* D_80104A44_2B0FF4_Last5Turns[];

extern MBModel* D_80104B10_2B10C0_Last5Turns; /* the host */
extern MBModel* D_80104B14_2B10C4_Last5Turns; /* the event's model */
extern s32 D_80104B18_2B10C8_Last5Turns; /* step done */
extern s32 D_80104B1C_2B10CC_Last5Turns;
extern s32 D_80104B20_2B10D0_Last5Turns; /* the player the event favours */
extern s32 D_80104B24_2B10D4_Last5Turns; /* message window x (read as s16) */
extern s32 D_80104B28_2B10D8_Last5Turns; /* message window y (read as s16) */
extern s32 D_80104B2C_2B10DC_Last5Turns; /* message arguments variant */
extern s32 D_80104B30_2B10E0_Last5Turns; /* message id */
extern s32 D_80104B34_2B10E4_Last5Turns; /* bit 0: message waits for a press */
extern s32 D_80104B38_2B10E8_Last5Turns;
extern s32 D_80104B3C_2B10EC_Last5Turns;
extern s32 D_80104B40_2B10F0_Last5Turns; /* rank of the status window dropping in */
extern s32 D_80104B44_2B10F4_Last5Turns; /* the event: 0..3 */
extern s32 D_80104B48_2B10F8_Last5Turns[4]; /* players in the scene */
extern s32 D_80104B58_2B1108_Last5Turns; /* their count */
extern s32 D_80104B60_2B1110_Last5Turns[4]; /* players by rank */
extern s32 D_80104B70_2B1120_Last5Turns[4];
extern s32 D_80104B80_2B1130_Last5Turns; /* players sharing the lowest rank (board 5); bss 0x20 */

/* ---- overlay 40 functions ---- */

void func_80102800_2AEDB0_Last5Turns(void);
void func_8010294C_2AEEFC_Last5Turns(void);
void func_80102C40_2AF1F0_Last5Turns(omObjData* obj);
void func_80102C94_2AF244_Last5Turns(void);
void func_80102D20_2AF2D0_Last5Turns(void);
void func_80103B98_2B0148_Last5Turns(void);
void func_80103D60_2B0310_Last5Turns(void);
/* Returns the window id (an s16) as an int: its caller does not re-extend it. */
s32 func_801041B4_2B0764_Last5Turns(s16 x, s16 y, s16 w, s16 h, s16 arg4, s16 arg5, s32 arg6);
void func_8010431C_2B08CC_Last5Turns(void);
s32 func_80104404_2B09B4_Last5Turns(s32 rank);
void func_80104418_2B09C8_Last5Turns(s32 layout);
void func_80104750_2B0D00_Last5Turns(omObjData* obj);
void func_801047E8_2B0D98_Last5Turns(void);
void func_8010481C_2B0DCC_Last5Turns(omObjData* obj);
void func_80104864_2B0E14_Last5Turns(omObjData* obj);
void func_801048B8_2B0E68_Last5Turns(void);

#endif
