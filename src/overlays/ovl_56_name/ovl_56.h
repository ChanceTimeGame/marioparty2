#ifndef _OVL_56_H
#define _OVL_56_H

#include "common.h"
#include "game/pad.h"
#include "game/data.h"
#include "game/hmfman.h"
#include "game/camera.h"

/* Overlay 56: a debug model/motion viewer for the six characters (MP3 mchar's ancestor; its
   strings: "MOTIONNO.%3d <%s>", "CENTER:", "ROTATE:", "ZOOM:", "M_TIME:"). Each character has three
   models (D_80104220: four variants of three form files per character; C-down cycles the variant)
   and a current and a previous motion. L-pad left/right pick the character, C-up the model, the
   repeat-scrolled stick buttons step the motion number (0-208, named by D_80103ED0), Z+R+L
   (0x30) leaves, the stick and C buttons turn and move the camera centre. */

/* Model/motion ids are kept in s32 slots and read back as s16 (retail lh of the low half). */
#define OVL56_CUR_MODEL() (D_80104E90_36DAB0_name_56[D_80104214_36CE34_name_56][D_80104218_36CE38_name_56])

extern s8 ContStkX[4];
extern s8 ContStkY[4];
extern s32 fontcolor;
extern u16 D_801011FC_101DFC;
u16 LoadFormFile(s32, s32); /* s16 in main; retail zero-extends the result here */
s16 func_80025384_25F84(s16 arg0, s16 arg1, s16 arg2, s32 arg3);
void func_800283DC_28FDC(s16 arg0);
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029AFC_2A6FC(s16);
void func_80029BF0_2A7F0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4); /* model motion blend */
s32 func_8002C8B8_2D4B8(void*, s16);
void func_8002C9C0_2D5C0(s16, s16);
void func_8002D4D0_2E0D0(s16 n);
void func_80020070_20C70(s32);
void func_80020D20_21920(s16 arg0);
void func_80026D28_27928(s32);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_80029708_2A308(s32);
void func_80039018_39C18(s16);
f32 func_8003B628_3C228(HmfMotionSlot*, s16, f32, f32, f32);
void func_80072FDC_73BDC(void);
omObjData* func_800732B0_73EB0(u32 arg0);
f32 HuMathSin(f32);
f32 func_800B1830_B2430(f32); /* sqrtf */
f32 func_800B7890_B8490(f32); /* cos */
s16 DrawDebugText(u16, u16, char*); /* MP1 print8 */

/* data */
extern u16 D_80103EC0_36CAE0_name_56;    /* set: leave */
extern u8 D_80103EC2_36CAE2_name_56;     /* debug text on */
extern s16 D_80103EC4_36CAE4_name_56[6]; /* character data directories */
extern char* D_80103ED0_36CAF0_name_56[209]; /* motion names */
extern s16 D_80104214_36CE34_name_56;    /* character 0-5 */
extern s16 D_80104216_36CE36_name_56;    /* motion 0-208 */
extern s16 D_80104218_36CE38_name_56;    /* model 0-2 */
extern u16 D_8010421A_36CE3A_name_56;    /* form variant 0-3 */
extern u8 D_8010421C_36CE3C_name_56;
extern u8 D_8010421E_36CE3E_name_56;     /* frames until the variant reloads */
extern s32 D_80104220_36CE40_name_56[6][4][3]; /* form files: [character][variant][model] */

/* bss */
extern char D_80104D80_36D9A0_name_56[0x100];
extern Vec D_80104E80_36DAA0_name_56;    /* camera rotation */
extern s32 D_80104E90_36DAB0_name_56[6][3]; /* models */
extern s32 D_80104ED8_36DAF8_name_56[6][2]; /* current, previous motion */

void func_80102800_36B420_name_56(void);
void func_80102954_36B574_name_56(omObjData*);
void func_80102A8C_36B6AC_name_56(omObjData*);
void func_801034E4_36C104_name_56(s16 variant);
void func_80103778_36C398_name_56(s16 motion);
void func_801038D4_36C4F4_name_56(omObjData*);
void func_80103DB8_36C9D8_name_56(void);
void func_80103E34_36CA54_name_56(omObjData*);
void func_80103E90_36CAB0_name_56(omObjData*);

#endif
