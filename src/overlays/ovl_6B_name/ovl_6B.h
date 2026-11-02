#ifndef _OVL_6B_H
#define _OVL_6B_H

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
   OVL6B_ constants below, the spaces in 801060EC, the tables marked STAGE, and whether a twin
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

#define OVL6B_STAGE 7           /* 64: 0 (stage = which of the six Park stages) */
#define OVL6B_NEXT_SCENE 0x6B   /* scene 0 goes here */
#define OVL6B_NEXT_ENTRY 1
#define OVL6B_FLAG_BASE 9       /* first stop's flag; 65: 0xD, 68: 0x1B */
#define OVL6B_BOARD_MODEL 0x36  /* func_80074154 arguments */
#define OVL6B_BOARD_FILE 0x4E
#define OVL6B_MUSIC 0x4F

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

extern board_overlay_entrypoint D_80106210_4024B0_name_6B[]; /* the scene table */
extern CoasterSpaceFlag D_80106240_4024E0_name_6B[];         /* STAGE */
extern s32 D_8010625C_4024FC_name_6B[];   /* save-menu backdrop by character (files 0xA010F-) */
extern s32 D_80106274_402514_name_6B[6];  /* save-menu labels */
extern s32 D_8010628C_40252C_name_6B[3];  /* difficulty label */
extern s32 D_80106298_402538_name_6B[3];  /* farewell message by difficulty */
extern s16 D_801062A4_402544_name_6B[4][2]; /* save-menu window positions, then: */
extern s16 D_801062B4_402554_name_6B;
extern s16 D_801062B6_402556_name_6B;
extern s16 D_801062B8_402558_name_6B;
extern s16 D_801062BA_40255A_name_6B;
extern s16 D_801062BC_40255C_name_6B[2];
extern BoardEventTableEntry D_80106340_4025E0_name_6B[]; /* STAGE: the arrival's space events */
extern s32 D_80106388_402628_name_6B[2][2]; /* result banner file, [clear/fail][0] */
extern s32 D_80106398_402638_name_6B[2];    /* "continue?" banner file */
extern s8 D_801063A0_402640_name_6B; /* nonzero skips the panels' waits (never set here) */
extern s8 D_801063A1_402641_name_6B; /* the continue question is over */
extern s8 D_801063A2_402642_name_6B; /* its answer, -1 = none */
extern s8 D_801063A3_402643_name_6B; /* the result is over */
extern s8 D_801063A4_402644_name_6B; /* the player chose to continue */
extern s16 D_801063A6_402646_name_6B; /* coins counted so far */
extern s16 D_801063A8_402648_name_6B[2][2]; /* the score panels' positions */
extern s16 D_801063B0_402650_name_6B[4][4]; /* digit x by digit count, -1000 = hidden */
extern u8 D_801063D0_402670_name_6B[8];    /* character model */
extern s32 D_801063D8_402678_name_6B[6];   /* func_800732B0 argument by character, | 0x54 */
extern s16 D_801063F0_402690_name_6B[4][4]; /* copy of D_801062F8 for 80104E60 */
extern u8 D_80106410_4026B0_name_6B[3][3]; /* STAGE: clear score, [minigame][difficulty] */

/* ---- .bss ---- */

extern CoasterGame D_80106460_402700_name_6B; /* the saved game */
extern s32 D_80106478_402718_name_6B[7];  /* save-menu windows; read as s16 */
extern unk_Struct02* D_80106494_402734_name_6B;
extern char D_80106498_402738_name_6B[8];
extern char D_801064A0_402740_name_6B[8];
extern char D_801064A8_402748_name_6B[8];
extern s32 D_801064B0_402750_name_6B;     /* the fade window; read as s16 */
extern s16 D_801064B4_402754_name_6B;     /* 0 clear, 1 fail */
extern s16 D_801064B6_402756_name_6B;     /* coins before the result */
extern s16 D_801064B8_402758_name_6B;     /* lives before the result */
extern s32 D_801064BC_40275C_name_6B;     /* sprite anim ids below: all read as s16 */
extern s32 D_801064C0_402760_name_6B;     /* "clear/fail" banner group */
extern s32 D_801064C4_402764_name_6B;
extern s32 D_801064CC_40276C_name_6B;     /* "continue?" banner group */
extern s32 D_801064D0_402770_name_6B;
extern s32 D_801064D8_402778_name_6B[3];
extern s32 D_801064E4_402784_name_6B[2];
extern s32 D_801064F0_402790_name_6B[2][4];
extern s32 D_80106510_4027B0_name_6B[3];  /* the score panels' groups: lives, coins, extra life */
extern Vec D_8010651C_4027BC_name_6B;     /* camera */
extern Vec D_80106528_4027C8_name_6B;
extern Vec D_80106534_4027D4_name_6B;
extern Vec D_80106540_4027E0_name_6B;
extern Vec D_8010654C_4027EC_name_6B;
extern Process* D_80106558_4027F8_name_6B;
extern Process* D_8010655C_4027FC_name_6B;
extern MBModel* D_80106560_402800_name_6B; /* the two characters */
extern MBModel* D_80106564_402804_name_6B;
extern MBModel* D_80106568_402808_name_6B; /* the vehicle, model 0xAA */

/* ---- functions ---- */

void func_80102800_3FEAA0_name_6B(void);
void func_80102830_3FEAD0_name_6B(void);
s32 func_8010288C_3FEB2C_name_6B(s32 bit);
void func_801028D0_3FEB70_name_6B(void);
void func_80102C88_3FEF28_name_6B(void);
void func_80102CE4_3FEF84_name_6B(void);
void func_801030B8_3FF358_name_6B(s32 sign);
void func_8010320C_3FF4AC_name_6B(void);
void func_80103284_3FF524_name_6B(void);
void func_80103310_3FF5B0_name_6B(void);
void func_80103460_3FF700_name_6B(void);
void func_80104224_4004C4_name_6B(void);
void func_80104244_4004E4_name_6B(void);
void func_801042AC_40054C_name_6B(void);
void func_801042D8_400578_name_6B(void);
void func_801046D8_400978_name_6B(void);
void func_801049A4_400C44_name_6B(void);
void func_801049F4_400C94_name_6B(void);
void func_80104A60_400D00_name_6B(s8 idx);
void func_80104BA8_400E48_name_6B(void);
void func_80104D28_400FC8_name_6B(void);
void func_80104EA8_401148_name_6B(void);
void func_80105530_4017D0_name_6B(void);
void func_80105808_401AA8_name_6B(void);
void func_80105988_401C28_name_6B(void);
void func_80105B38_401DD8_name_6B(void);
s32 func_80105D14_401FB4_name_6B(s16 minigame);
void func_80105DE0_402080_name_6B(void);
void func_80105EF8_402198_name_6B(void);
void func_801060F8_402398_name_6B(void);
void func_801031D0_3FF470_name_6B(void);
void func_8010333C_3FF5DC_name_6B(void);
void func_80103360_3FF600_name_6B(void);
void func_80103384_3FF624_name_6B(void);
void func_801033A8_3FF648_name_6B(void);
void func_801033CC_3FF66C_name_6B(void);
void func_801033F0_3FF690_name_6B(void);
void func_80103414_3FF6B4_name_6B(void);
void func_80103438_3FF6D8_name_6B(void);
void func_80106134_4023D4_name_6B(void);

#endif
