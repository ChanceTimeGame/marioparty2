#ifndef _OVL_6A_H
#define _OVL_6A_H

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

   Stage-specific, what the twins change (the rest of the code is the same to the register): the
   OVL6A_ constants below, the spaces in 801060EC, the tables marked STAGE, and whether a twin
   has more stops (65-6C add functions around 801033B8). Compare with ovl_65 and ovl_68 first. */

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

#define OVL6A_STAGE 6           /* 64: 0 (stage = which of the six Park stages) */
#define OVL6A_NEXT_SCENE 0x6A   /* scene 0 goes here */
#define OVL6A_NEXT_ENTRY 1
#define OVL6A_FLAG_BASE 9       /* first stop's flag; 65: 0xD, 68: 0x1B */
#define OVL6A_BOARD_MODEL 0x35  /* func_80074154 arguments */
#define OVL6A_BOARD_FILE 0x4D
#define OVL6A_MUSIC 0x4E

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

extern board_overlay_entrypoint D_80106210_3FE850_name_6A[]; /* the scene table */
extern CoasterSpaceFlag D_80106240_3FE880_name_6A[];         /* STAGE */
extern s32 D_8010625C_3FE89C_name_6A[];   /* save-menu backdrop by character (files 0xA010F-) */
extern s32 D_80106274_3FE8B4_name_6A[6];  /* save-menu labels */
extern s32 D_8010628C_3FE8CC_name_6A[3];  /* difficulty label */
extern s32 D_80106298_3FE8D8_name_6A[3];  /* farewell message by difficulty */
extern s16 D_801062A4_3FE8E4_name_6A[4][2]; /* save-menu window positions, then: */
extern s16 D_801062B4_3FE8F4_name_6A;
extern s16 D_801062B6_3FE8F6_name_6A;
extern s16 D_801062B8_3FE8F8_name_6A;
extern s16 D_801062BA_3FE8FA_name_6A;
extern s16 D_801062BC_3FE8FC_name_6A[2];
extern BoardEventTableEntry D_80106340_3FE980_name_6A[]; /* STAGE: the arrival's space events */
extern s32 D_80106388_3FE9C8_name_6A[2][2]; /* result banner file, [clear/fail][0] */
extern s32 D_80106398_3FE9D8_name_6A[2];    /* "continue?" banner file */
extern s8 D_801063A0_3FE9E0_name_6A; /* nonzero skips the panels' waits (never set here) */
extern s8 D_801063A1_3FE9E1_name_6A; /* the continue question is over */
extern s8 D_801063A2_3FE9E2_name_6A; /* its answer, -1 = none */
extern s8 D_801063A3_3FE9E3_name_6A; /* the result is over */
extern s8 D_801063A4_3FE9E4_name_6A; /* the player chose to continue */
extern s16 D_801063A6_3FE9E6_name_6A; /* coins counted so far */
extern s16 D_801063A8_3FE9E8_name_6A[2][2]; /* the score panels' positions */
extern s16 D_801063B0_3FE9F0_name_6A[4][4]; /* digit x by digit count, -1000 = hidden */
extern u8 D_801063D0_3FEA10_name_6A[8];    /* character model */
extern s32 D_801063D8_3FEA18_name_6A[6];   /* func_800732B0 argument by character, | 0x54 */
extern s16 D_801063F0_3FEA30_name_6A[4][4]; /* copy of D_801062F8 for 80104E60 */
extern u8 D_80106410_3FEA50_name_6A[3][3]; /* STAGE: clear score, [minigame][difficulty] */

/* ---- .bss ---- */

extern CoasterGame D_80106460_3FEAA0_name_6A; /* the saved game */
extern s32 D_80106478_3FEAB8_name_6A[7];  /* save-menu windows; read as s16 */
extern unk_Struct02* D_80106494_3FEAD4_name_6A;
extern char D_80106498_3FEAD8_name_6A[8];
extern char D_801064A0_3FEAE0_name_6A[8];
extern char D_801064A8_3FEAE8_name_6A[8];
extern s32 D_801064B0_3FEAF0_name_6A;     /* the fade window; read as s16 */
extern s16 D_801064B4_3FEAF4_name_6A;     /* 0 clear, 1 fail */
extern s16 D_801064B6_3FEAF6_name_6A;     /* coins before the result */
extern s16 D_801064B8_3FEAF8_name_6A;     /* lives before the result */
extern s32 D_801064BC_3FEAFC_name_6A;     /* sprite anim ids below: all read as s16 */
extern s32 D_801064C0_3FEB00_name_6A;     /* "clear/fail" banner group */
extern s32 D_801064C4_3FEB04_name_6A;
extern s32 D_801064CC_3FEB0C_name_6A;     /* "continue?" banner group */
extern s32 D_801064D0_3FEB10_name_6A;
extern s32 D_801064D8_3FEB18_name_6A[3];
extern s32 D_801064E4_3FEB24_name_6A[2];
extern s32 D_801064F0_3FEB30_name_6A[2][4];
extern s32 D_80106510_3FEB50_name_6A[3];  /* the score panels' groups: lives, coins, extra life */
extern Vec D_8010651C_3FEB5C_name_6A;     /* camera */
extern Vec D_80106528_3FEB68_name_6A;
extern Vec D_80106534_3FEB74_name_6A;
extern Vec D_80106540_3FEB80_name_6A;
extern Vec D_8010654C_3FEB8C_name_6A;
extern Process* D_80106558_3FEB98_name_6A;
extern Process* D_8010655C_3FEB9C_name_6A;
extern MBModel* D_80106560_3FEBA0_name_6A; /* the two characters */
extern MBModel* D_80106564_3FEBA4_name_6A;
extern MBModel* D_80106568_3FEBA8_name_6A; /* the vehicle, model 0xAA */

/* ---- functions ---- */

void func_80102800_3FAE40_name_6A(void);
void func_80102830_3FAE70_name_6A(void);
s32 func_8010288C_3FAECC_name_6A(s32 bit);
void func_801028D0_3FAF10_name_6A(void);
void func_80102C88_3FB2C8_name_6A(void);
void func_80102CE4_3FB324_name_6A(void);
void func_801030B8_3FB6F8_name_6A(s32 sign);
void func_8010320C_3FB84C_name_6A(void);
void func_80103284_3FB8C4_name_6A(void);
void func_80103310_3FB950_name_6A(void);
void func_80103460_3FBAA0_name_6A(void);
void func_80104224_3FC864_name_6A(void);
void func_80104244_3FC884_name_6A(void);
void func_801042AC_3FC8EC_name_6A(void);
void func_801042D8_3FC918_name_6A(void);
void func_801046D8_3FCD18_name_6A(void);
void func_801049A4_3FCFE4_name_6A(void);
void func_801049F4_3FD034_name_6A(void);
void func_80104A60_3FD0A0_name_6A(s8 idx);
void func_80104BA8_3FD1E8_name_6A(void);
void func_80104D28_3FD368_name_6A(void);
void func_80104EA8_3FD4E8_name_6A(void);
void func_80105530_3FDB70_name_6A(void);
void func_80105808_3FDE48_name_6A(void);
void func_80105988_3FDFC8_name_6A(void);
void func_80105B38_3FE178_name_6A(void);
s32 func_80105D14_3FE354_name_6A(s16 minigame);
void func_80105DE0_3FE420_name_6A(void);
void func_80105EF8_3FE538_name_6A(void);
void func_801060F8_3FE738_name_6A(void);
void func_801031D0_3FB810_name_6A(void);
void func_8010333C_3FB97C_name_6A(void);
void func_80103360_3FB9A0_name_6A(void);
void func_80103384_3FB9C4_name_6A(void);
void func_801033A8_3FB9E8_name_6A(void);
void func_801033CC_3FBA0C_name_6A(void);
void func_801033F0_3FBA30_name_6A(void);
void func_80103414_3FBA54_name_6A(void);
void func_80103438_3FBA78_name_6A(void);
void func_80106134_3FE774_name_6A(void);

#endif
