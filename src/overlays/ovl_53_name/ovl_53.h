#ifndef _OVL_53_H
#define _OVL_53_H

/* Overlay 53 (35D110.c): the Bowser space event, a stand-alone scene (its own omInitObjMan).
   Bowser (a per-board model) taunts the player, then a five-panel roulette (MP1's Bowser roulette,
   src/48D90.c func_8004858C/func_800499CC) picks one of his events; D_80105C2C runs the event, and
   func_80102D54 leaves to Chance Time (0x34), a board overlay, or back to the board.
   The unit's .rodata is carved; .data and .bss stay asm. */

#include "common.h"
#include "game/board.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/data.h"
#include "game/malloc.h"
#include "game/sprite.h"
#include "game/window.h"
#include "game/gamemes.h"
#include "game/pad.h"

/* ---- main-segment API used by 53 ---- */

void func_80079128_79D28(void);
void func_80018E30_19A30(s32);
void func_80050A30_51630(u8*);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026D50_27950(s16 arg0, u8 arg1, u8 arg2);
void MBModelInit(void);
void func_8005E2B8_5EEB8(void);
void func_800593C0_59FC0(void);
void func_800581A0_58DA0(void);
void func_8005965C_5A25C(void);
void func_8005FE10_60A10(void);
void func_80060034_60C34(u32, s32);
void HidePlayerHUDVisibility(s32 arg0, s32 arg1);
void func_80088640_89240(void);
void func_80050E00_51A00(s32);
void func_8005321C_53E1C(f32, f32);
MBModel* MBModelFileCreate(s32 arg0, s32 arg1, f32 arg2, f32 arg3, u32* arg4);
void func_8005AB50_5B750(MBModel* arg0, s16 arg1, s16 arg2, s32 arg3);
void func_80043DAC_449AC(MBModel*);
void MBMotionSet(MBModel*, s16, s32);
void MBMotionShiftSet(void* arg0, s16 arg1, s32 arg2, s32 arg3, u16 arg4);
void MBModelDispOff(MBModel*);
s32 PlaySound(s32);
void func_8008D974_8E574(s32, s16); /* message argument: a message id or a string */
void func_8008DACC_8E6CC(s32, s16*, s32); /* a message's window size */
s32 func_8005AAC0_5B6C0(s32 x, s32 y, s32 w, s32 h); /* board message window */
void func_80089308_89F08(s16, s32, s32); /* window message argument */
void func_800890CC_89CCC(s16, s32, s32, s32);
void ShowTextWindow(s32 arg0);
void func_80057730_58330(s32, s32); /* retail passes the window unextended here */
void func_8005762C_5822C(s32 arg0);
void func_80059520_5A120(MBModel*, s32, s32);
void func_800794A8_7A0A8(s32);
void MBDBackKill(void);
void func_80050AE0_516E0(void);
void func_8005E260_5EE60(s16 playerIndex);
void func_80059400_5A000(void);
void func_8008CE5C_8DA5C(void);
void func_8008CCA8_8D8A8(s16);
void omDelObj(omObjData*);
s16 SprCreate(s32 num, s32 attr);
s16 SprAnimRead(void*);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
void SprAttrSet(s16, s16, s32);
void SprPosSet(s16 grpIdx, s16 idx, s16 x, s16 y);
void SprAnimKill(s16 animIdx);
void SprKill(s16 idx);
void func_80082450_83050(s16 grpIdx, s32 idx, s32 r, s32 g, u8 b);
void func_800896DC_8A2DC(s16 winId, s16 x, s16 y); /* window position */
void func_8008D6F0_8E2F0(s16 winId);
void func_8008D530_8E130(s16 winId, u8 r, u8 g, u8 b);
void func_80089B2C_8A72C(s16, s16);
void func_80089A7C_8A67C(s16 winId, s16 prio);
void func_8008AD44_8B944(s16);
void func_80089C78_8A878(s16 winId, u8 arg1);
void func_80089DA0_8A9A0(s16 winId, u8 r, u8 g, u8 b);
void func_80089A48_8A648(s16, s16);
void func_8005A4EC_5B0EC(s32 player, s32 reaction); /* a player's reaction */
s16 func_800888A8_894A8(s16 x, s16 y, s16 w, s16 h, s32, s16 flags); /* create a window */
void func_8008D88C_8E48C(s16);
void func_800898F0_8A4F0(s16 winId, s16 x, s16 y);
void func_8008D5D8_8E1D8(s16 winId);
s32 func_8004E94C_4F54C(void);
s32 func_80059FD0_5ABD0(s32 player); /* the player's rank, 0 = first */
void func_800614B4_620B4(s32 player, s32 coins); /* give coins */
void func_8006135C_61F5C(s32 player, s32 coins, s32);
s32 func_80060210_60E10(s32);
void func_80060F90_61B90(s32);
void func_80061078_61C78(s32);
void func_80057448_58048(void);
void func_800615F0_621F0(s32);
extern s16 D_800F8D16_F9916; /* D_800F8CE4_F98E4[0x19] (ovl_3E.h) */

/* A board message window centred at y 80, sized for message mes (Bowser's lines). */
#define OVL53_MES_WIN(win, mes)                                                                   \
    func_8008DACC_8E6CC(1, D_80105DCC_3606DC_name_53, mes);                                      \
    win = func_8005AAC0_5B6C0((320 - D_80105DCC_3606DC_name_53[0]) / 2, 80, D_80105DCC_3606DC_name_53[0], \
                              D_80105DCC_3606DC_name_53[1])

extern u8 D_01164160[];
extern s16 D_800CD414_CE014;
extern s32 D_800CC5F8[]; /* per character: the name message (undefined_syms) */
extern u16 D_801011FC_101DFC;
extern u32 D_800FDC6C_FE86C;

/* ---- overlay 53 data and bss ---- */

/* A roulette panel window (MP1 unk48D90Box). */
typedef struct Ovl53Box {
    /* 0x00 */ s16 win;
    /* 0x02 */ s16 x;
    /* 0x04 */ s16 y;
    /* 0x06 */ s16 w;
    /* 0x08 */ s16 h;
} Ovl53Box; /* size = 0xA */

typedef struct Ovl53Rect {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
    /* 0x04 */ s16 w;
    /* 0x06 */ s16 h;
} Ovl53Rect; /* size = 8 */

extern Ovl53Rect D_80105B60_360470_name_53[5];
extern u8 D_80105B88_360498_name_53; /* the cursor's y */
/* Cursor animation step (MP1 unk48D90Step). */
typedef struct Ovl53Step {
    /* 0x00 */ s8 limit;
    /* 0x01 */ s8 x;
} Ovl53Step; /* size = 2 */

extern Ovl53Step D_80105B8C_36049C_name_53[]; /* MP1 D_800C4F40 */
extern s32 D_80105B94_3604A4_name_53[6];
extern s32 D_80105BAC_3604BC_name_53[6]; /* per board: Bowser's model */
extern u32 D_80105BC4_3604D4_name_53[6][4]; /* per board: Bowser's motions */
extern s32 D_80105C24_360534_name_53;
extern void (*D_80105C2C_36053C_name_53[])(void); /* the events */
extern s32 D_80105C58_360568_name_53[6]; /* per board: the board overlay */
extern u32 D_80105C70_360580_name_53;
extern s32 D_80105C74_360584_name_53[]; /* per event: who reacts (3-5 the player, 13-15 everyone) */
extern u16 D_80105C9C_3605AC_name_53[2][3][4]; /* coins: [kind][stage][rank] */
extern s32 D_80105CCC_3605DC_name_53[][2]; /* per game length: the last turn of stages 0 and 1 */

extern char D_80105D60_360670_name_53[10]; /* sprintf("%d") buffer: a panel's number */
extern const char D_80105D58_360668_name_53[]; /* "%d" */
extern s16 D_80105D6A_36067A_name_53; /* the "Bowser roulette" title window */
extern Ovl53Box D_80105D70_360680_name_53[5];
extern u8 D_80105DA2_3606B2_name_53[5]; /* each panel's event */
extern omObjData* D_80105DA8_3606B8_name_53; /* the roulette object */
extern s16 D_80105DAC_3606BC_name_53[2];
extern s16 D_80105DB0_3606C0_name_53;
extern s16 D_80105DB2_3606C2_name_53;
extern s16 D_80105DB4_3606C4_name_53;
extern s16 D_80105DB6_3606C6_name_53;
extern s16 D_80105DB8_3606C8_name_53;
extern s16 D_80105DBA_3606CA_name_53; /* the cursor sprite */
extern s16 D_80105DBC_3606CC_name_53;
extern s32 D_80105DC0_3606D0_name_53; /* the player */
extern s32 D_80105DC4_3606D4_name_53; /* the chosen event */
extern s32 D_80105DC8_3606D8_name_53;
extern s16 D_80105DCC_3606DC_name_53[2];
extern s16 D_80105DD0_3606E0_name_53; /* board index */
extern s16 D_80105DD2_3606E2_name_53; /* current player */
extern MBModel* D_80105DD4_3606E4_name_53; /* Bowser */

/* ---- overlay 53 functions ---- */

void func_80102800_35D110_name_53(void);
void func_80102A08_35D318_name_53(void);
void func_80102D28_35D638_name_53(omObjData*);
void func_80102D54_35D664_name_53(void);
void func_80102E84_35D794_name_53(void);
void func_80102ED0_35D7E0_name_53(omObjData*);
s32 func_80103ECC_35E7DC_name_53(void);
s32 func_80103ED8_35E7E8_name_53(void);
s32 func_80103EE4_35E7F4_name_53(void);
void func_80103F00_35E810_name_53(void);
void func_80103FB8_35E8C8_name_53(void);
void func_8010401C_35E92C_name_53(void);
void func_801041E4_35EAF4_name_53(void);
void func_801044A8_35EDB8_name_53(void);
void func_80104570_35EE80_name_53(s32);
void func_80104A30_35F340_name_53(void);
s32 func_80104A40_35F350_name_53(s32, s32);
void func_80104AEC_35F3FC_name_53(void);
void func_80104D6C_35F67C_name_53(void);
void func_80105088_35F998_name_53(void);
void func_80105150_35FA60_name_53(void);
void func_8010565C_35FF6C_name_53(void);
void func_80105870_360180_name_53(void);
void func_80105948_360258_name_53(void);
void func_80105A10_360320_name_53(void);
void func_80105B24_360434_name_53(void);

#endif
