#ifndef _OVL_64_H
#define _OVL_64_H

/* Overlays 64-6C: the Mini-Game Coaster stage scenes (MP1's Mini-Game Island ovl_73-7D). 64 is the
   template of the other eight. The scene table D_80106190 has five entries:
   0 801031D0  new game: stage = 0, on to the course scene 63
   1 80103208  back on the start space, stop flags 9-12 cleared
   2 801032FC  the board (common setup 80103270). The event table D_80106298 fires 80103328-80103394
               at the four stops (each names its minigame once, 801030B8), 801033B8 at the end
               (save point 80102CE4) and 801033F0 on event 0x11
   3 801060B0  the result, when a minigame returns: process 80105EB0 judges the score (80105CCC),
               builds the panels (80103418) and the scene (80104690), runs 80105AF0: on a clear the
               win streak multiplies the coins, counted into the save (801054E8); on a fail a life
               goes; none left, the continue question (801057C0)
   4 801060EC  back on the space after the last stop passed
   Retail's overlay is two files: 3E4320.c (the entry point) and 3E4350.c (everything else, built
   with the KMC mul fix, .rodata carved). Every function is global. .data and .bss are asm,
   declared here (typed from the code).

   OVL64_STAGE_CONSTANTS */

#include "common.h"
#include "process.h"
#include "game/data.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/sprite.h"
#include "game/window.h"
#include "game/gamemes.h"
#include "game/pad.h"
#include "game/board.h"

/* ---- types ---- */

/* The Mini-Game Coaster game, saved to EEPROM whole. This is main's Unk_800FD8A8 with the fields the
   stage scenes use; live copy D_800FD8A8_FE4A8, the copy loaded for the save menu D_801063B0. */
typedef struct CoasterGame {
    /* 0x00 */ u8 character;  /* player 1 */
    /* 0x01 */ u8 character2; /* player 2 */
    /* 0x02 */ s8 stage;      /* 0-based position on the course */
    /* 0x03 */ s8 lives;      /* 0-99 */
    /* 0x04 */ s8 difficulty; /* 0-2 */
    /* 0x05 */ s8 flags[7];   /* bitfield, read by 8010288C; bit 0 = this slot holds a game */
    /* 0x0C */ s8 streak;     /* minigames won in a row: multiplies the coins */
    /* 0x0D */ s8 coins;      /* 0-99, 100 buy a life */
    /* 0x0E */ s8 chain;      /* player 1's chain */
    /* 0x0F */ s8 space;      /* player 1's space */
    /* 0x10 */ s8 chapter;    /* 1-based */
    /* 0x11 */ s8 step;       /* within the chapter */
} CoasterGame; /* size = 0x12 */

/* A space whose type turns to 1 once a game flag is set (D_801061C0, 80102830). */
typedef struct CoasterSpaceFlag {
    /* 0x00 */ s16 space; /* -1 ends the list */
    /* 0x02 */ u16 flag;
} CoasterSpaceFlag; /* size = 4 */

/* ---- main ---- */

extern CoasterGame D_800FD8A8_FE4A8;
extern s16 mbDlgWinId;
extern s16 D_800FD2A6_FDEA6; /* the player's model */
extern MBModel* D_800FA618_FB218;
extern void* D_800CC8B8_CD4B8[]; /* per-character motion sets, indexed by character */
extern s16 D_800CD414_CE014;

void ExecBoardScene(board_overlay_entrypoint* table, s16 index);
void EventTableHydrate(void* table);
void BoardSpaceTypeSet(s16 spaceIndex, u8 spaceType);
void SetPlayerOntoChain(s16 player, s16 chain_index, s16 space_index);
void HuVecCopyXYZ(Vec*, f32, f32, f32);
void HuMemDirectFree(void* p);
void Hu3DCamSetPositionOrientation(s16 camIndex, Vec* pos, Vec* at, Vec* up);
void Hu3DCamUpdateMtx(s16 camIndex);
void CameraViewportSet(s16 camIndex, Vec* arg1, Vec* arg2);
void MBDlgWinClose(void);
void MBDlgWinExecY(s16 arg0, s32 arg1, s32 arg2);
void MBDlgWinInsertCreateY(s16 arg0, u32 arg1, char* arg2, char* arg3, char* arg4, char* arg5,
                           char* arg6, s16 arg7);
void MBModelKill(void*);
void MBMotionSet(MBModel*, s16, s32);
void MBMotionShiftSet(void* arg0, s16 arg1, s32 arg2, s32 arg3, u16 arg4);
void MBPlayerVibrate(s16, s16);
s32 MBWinCreate(s16 arg0, s16* arg1, s16 arg2); /* main: s16; the callers extend it themselves */
s32 PlaySound(s32);
void SprAnimKill(s16 animIdx);
s16 SprAnimRead(void*);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprAttrSet(s16, s16, s32);
s16 SprCreate(s32 num, s32 attr);
void SprPosSet(s16 grpIdx, s16 idx, s16 x, s16 y);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
void SprAttrReset(s16 grpIdx, s16 idx, s32 flag);
void SprKill(s16 idx);
void SprScaleSet(s16 group, s16 member, f32 x, f32 y);
void func_80020070_20C70(s32);
void func_80026D28_27928(s32);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_80028334_28F34(s16 arg0, u8 arg1);
void func_80029EDC_2AADC(s16 arg0, u8 arg1);
void func_80055A38_56638(s16 arg0, s32 arg1);
void func_80056168_56D68(void);
MBModel* func_80043510_44110(u8 id, void* arg1);
void func_8005670C_5730C(Vec*);
Process* func_80056B78_57778(Vec* arg0, Vec* arg1, Vec* arg2, s32 arg3);
Process* func_80056D80_57980(Vec*, Vec*, Vec*, s32);
s32 func_80057480_58080(s32 arg0, s32 arg1, s32 arg2, s32 arg3); /* 58080.c: s16 */
void func_8005AA48_5B648(MBModel*, const char*, s16);
void func_8005AA98_5B698(s16);
unk_Struct02* func_8005E688_5F288(s32, s32);
void func_8006985C_6A45C(GAMEMES* gMes);
s16 func_8006A608_6B208(GAMEMES* mes, char* str, u8 arg2, s16 arg3, s16 arg4);
void func_800732B0_73EB0(s32);
void func_80073410_74010(s16 index);
s8 func_800734B0_740B0(s16);
void func_800740AC_74CAC(void);
void func_800740B8_74CB8(void);
void func_80074154_74D54(s32, s32);
void func_800744C0_750C0(void);
void func_80074DB8_759B8(s32);
void func_80074FAC_75BAC(s8 map, s16 event, s16 fade, s16 music);
void func_80075010_75C10(s32);
void func_8007501C_75C1C(void);
s32 func_80075390_75F90(s32);
void func_800753D4_75FD4(s32 flag);
void func_80075424_76024(s32);
void func_80079428_7A028(s32);
void func_80079718_7A318(s32, s32);
void func_8007E018_7EC18(void);
void func_8007E0C8_7ECC8(void* buf);
void func_8008221C_82E1C(s16 group, s16 member, f32 arg2);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
void func_800822A8_82EA8(s16 group, s16 member, u16 arg2, s32 arg3);
void func_80082450_83050(s16 grpIdx, s32 idx, s32 r, s32 g, u8 b);
void func_800824F4_830F4(s16 group, s16 member, s16 arg2);
s16 func_800888A8_894A8(s16 x, s16 y, s16 w, s16 h, s32 arg4, s16 flags); /* main: s32 */
void func_800890CC_89CCC(s16, void*, s32, s32); /* a message id or a string */
void func_80089308_89F08(s16, char*, s32);
void func_80089A48_8A648(s16, s16);
void func_80089B2C_8A72C(s16, s16);
s16 func_8008BA30_8C630(s16 winId);
s32 func_8008BB48_8C748(s16, s16, s32);
void func_8008CCA8_8D8A8(s16);
void func_8008D07C_8DC7C(s16, s16, s16, s16);
void func_8008D530_8E130(s16 winId, u8 r, u8 g, u8 b);
void func_8008D904_8E504(s16 winId, s32 str, s8 idx);
void func_8008D974_8E574(char*, s16);
void func_8008D9D0_8E5D0(s32 str, s16 idx);
void func_8008DACC_8E6CC(s32, s16*, s32);
void func_8008E978_8F578(s16 winId);

/* ---- .data ---- */

extern board_overlay_entrypoint D_80106190_3E7CB0_name_64[]; /* the scene table */
extern CoasterSpaceFlag D_801061C0_3E7CE0_name_64[];         /* STAGE */
extern s32 D_801061D4_3E7CF4_name_64[];   /* save-menu backdrop by character (files 0xA010F-) */
extern s32 D_801061EC_3E7D0C_name_64[6];  /* save-menu labels */
extern s32 D_80106204_3E7D24_name_64[3];  /* difficulty label */
extern s32 D_80106210_3E7D30_name_64[3];  /* farewell message by difficulty */
extern s16 D_8010621C_3E7D3C_name_64[4][2]; /* save-menu window positions, then: */
extern s16 D_8010622C_3E7D4C_name_64;
extern s16 D_8010622E_3E7D4E_name_64;
extern s16 D_80106230_3E7D50_name_64;
extern s16 D_80106232_3E7D52_name_64;
extern s16 D_80106234_3E7D54_name_64[2];
extern BoardEventTableEntry D_80106298_3E7DB8_name_64[]; /* STAGE: the arrival's space events */
extern s32 D_801062D0_3E7DF0_name_64[2][2]; /* result banner file, [clear/fail][0] */
extern s32 D_801062E0_3E7E00_name_64[2];    /* "continue?" banner file */
extern s8 D_801062E8_3E7E08_name_64; /* nonzero skips the panels' waits (never set here) */
extern s8 D_801062E9_3E7E09_name_64; /* the continue question is over */
extern s8 D_801062EA_3E7E0A_name_64; /* its answer, -1 = none */
extern s8 D_801062EB_3E7E0B_name_64; /* the result is over */
extern s8 D_801062EC_3E7E0C_name_64; /* the player chose to continue */
extern s16 D_801062EE_3E7E0E_name_64; /* coins counted so far */
extern s16 D_801062F0_3E7E10_name_64[2][2]; /* the score panels' positions */
extern s16 D_801062F8_3E7E18_name_64[4][4]; /* digit x by digit count, -1000 = hidden */
extern u8 D_80106318_3E7E38_name_64[8];    /* character model */
extern s32 D_80106320_3E7E40_name_64[6];   /* func_800732B0 argument by character, | 0x54 */
extern s16 D_80106338_3E7E58_name_64[4][4]; /* copy of D_801062F8 for 80104E60 */
extern u8 D_80106358_3E7E78_name_64[3][3]; /* STAGE: clear score, [minigame][difficulty] */

/* ---- .bss ---- */

extern CoasterGame D_801063B0_3E7ED0_name_64; /* the saved game */
extern s32 D_801063C8_3E7EE8_name_64[7];  /* save-menu windows; read as s16 */
extern unk_Struct02* D_801063E4_3E7F04_name_64;
extern char D_801063E8_3E7F08_name_64[8];
extern char D_801063F0_3E7F10_name_64[8];
extern char D_801063F8_3E7F18_name_64[8];
extern s32 D_80106400_3E7F20_name_64;     /* the fade window; read as s16 */
extern s16 D_80106404_3E7F24_name_64;     /* 0 clear, 1 fail */
extern s16 D_80106406_3E7F26_name_64;     /* coins before the result */
extern s16 D_80106408_3E7F28_name_64;     /* lives before the result */
extern s32 D_8010640C_3E7F2C_name_64;     /* sprite anim ids below: all read as s16 */
extern s32 D_80106410_3E7F30_name_64;     /* "clear/fail" banner group */
extern s32 D_80106414_3E7F34_name_64;
extern s32 D_8010641C_3E7F3C_name_64;     /* "continue?" banner group */
extern s32 D_80106420_3E7F40_name_64;
extern s32 D_80106428_3E7F48_name_64[2];
extern s32 D_80106430_3E7F50_name_64;
extern s32 D_80106434_3E7F54_name_64[2];
extern s32 D_80106440_3E7F60_name_64[2][4];
extern s32 D_80106460_3E7F80_name_64[2];  /* the score panels' groups: lives, coins */
extern s32 D_80106468_3E7F88_name_64;     /* the extra coin panel group */
extern Vec D_8010646C_3E7F8C_name_64;     /* camera */
extern Vec D_80106478_3E7F98_name_64;
extern Vec D_80106484_3E7FA4_name_64;
extern Vec D_80106490_3E7FB0_name_64;
extern Vec D_8010649C_3E7FBC_name_64;
extern Process* D_801064A8_3E7FC8_name_64;
extern Process* D_801064AC_3E7FCC_name_64;
extern MBModel* D_801064B0_3E7FD0_name_64; /* the two characters */
extern MBModel* D_801064B4_3E7FD4_name_64;
extern MBModel* D_801064B8_3E7FD8_name_64; /* the vehicle, model 0xAA */

/* ---- functions ---- */

void func_80102800_3E4320_name_64(void);
void func_80102830_3E4350_name_64(void);
s32 func_8010288C_3E43AC_name_64(s32 bit);
void func_801028D0_3E43F0_name_64(void);
void func_80102C88_3E47A8_name_64(void);
void func_80102CE4_3E4804_name_64(void);
void func_801030B8_3E4BD8_name_64(s32 sign);
void func_801031D0_3E4CF0_name_64(void);
void func_80103208_3E4D28_name_64(void);
void func_80103270_3E4D90_name_64(void);
void func_801032FC_3E4E1C_name_64(void);
void func_80103328_3E4E48_name_64(void);
void func_8010334C_3E4E6C_name_64(void);
void func_80103370_3E4E90_name_64(void);
void func_80103394_3E4EB4_name_64(void);
void func_801033B8_3E4ED8_name_64(void);
void func_801033F0_3E4F10_name_64(void);
void func_80103418_3E4F38_name_64(void);
void func_801041DC_3E5CFC_name_64(void);
void func_801041FC_3E5D1C_name_64(void);
void func_80104264_3E5D84_name_64(void);
void func_80104290_3E5DB0_name_64(void);
void func_80104690_3E61B0_name_64(void);
void func_8010495C_3E647C_name_64(void);
void func_801049AC_3E64CC_name_64(void);
void func_80104A18_3E6538_name_64(s8 idx);
void func_80104B60_3E6680_name_64(void);
void func_80104CE0_3E6800_name_64(void);
void func_80104E60_3E6980_name_64(void);
void func_801054E8_3E7008_name_64(void);
void func_801057C0_3E72E0_name_64(void);
void func_80105940_3E7460_name_64(void);
void func_80105AF0_3E7610_name_64(void);
s32 func_80105CCC_3E77EC_name_64(s16 minigame);
void func_80105D98_3E78B8_name_64(void);
void func_80105EB0_3E79D0_name_64(void);
void func_801060B0_3E7BD0_name_64(void);
void func_801060EC_3E7C0C_name_64(void);

#endif
