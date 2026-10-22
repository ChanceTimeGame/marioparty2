#ifndef _OVL_59_H
#define _OVL_59_H

#include "common.h"
#include "game/pad.h"

/* Overlay 59: a debug viewer of 0x200 bytes read from the EEPROM (MP3 storydebug's memory dump):
   up/down on the D-pad scroll eight bytes a line; it returns when D_801011FC_101DFC is set. */

extern char pfStrBuf[];
extern s32 fontcolor;
extern u16 D_801011FC_101DFC;
s16 DrawDebugText(u16, u16, char*); /* MP1 print8 */
s32 func_8001B078_1BC78(s32 arg0, UnkEep* arg1, s16 arg2); /* EEPROM read */
void CameraScissorSet(s16 camIndex, RectF* arg1);
void func_80020070_20C70(s32);
void func_80026D28_27928(s32);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);

extern RectF D_80102BC0_37F240_name_59;
extern s16 D_80102BD0_37F250_name_59; /* first byte shown */
extern u8 D_80102C10_37F290_name_59[0x200];

void func_80102830_37EEB0_name_59(void);
void func_80102918_37EF98_name_59(void);
void func_80102A34_37F0B4_name_59(void);
void func_80102ACC_37F14C_name_59(void);
void func_80102B78_37F1F8_name_59(omObjData*);
void func_80102BA4_37F224_name_59(omObjData*);

#endif
