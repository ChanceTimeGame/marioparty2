#ifndef _OVL_66_H
#define _OVL_66_H

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
   OVL66_ constants below, the spaces in 801060EC, the tables marked STAGE, and whether a twin
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

#define OVL66_STAGE 2
#define OVL66_NEXT_SCENE 0x66
#define OVL66_NEXT_ENTRY 1
#define OVL66_FLAG_BASE 9       /* first stop's flag; 65: 0xD, 68: 0x1B */
#define OVL66_BOARD_MODEL 0x31
#define OVL66_BOARD_FILE 0x49
#define OVL66_MUSIC 0x4A

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
void MBDlgWinExec(s32, s32);
void SetNextChainAndSpace(s16 arg0, s16 arg1, s16 arg2);
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

extern board_overlay_entrypoint D_801061F0_3EF5A0_name_66[]; /* the scene table */
extern CoasterSpaceFlag D_80106220_3EF5D0_name_66[];         /* STAGE */
extern s32 D_80106234_3EF5E4_name_66[];   /* save-menu backdrop by character (files 0xA010F-) */
extern s32 D_8010624C_3EF5FC_name_66[6];  /* save-menu labels */
extern s32 D_80106264_3EF614_name_66[3];  /* difficulty label */
extern s32 D_80106270_3EF620_name_66[3];  /* farewell message by difficulty */
extern s16 D_8010627C_3EF62C_name_66[4][2]; /* save-menu window positions, then: */
extern s16 D_8010628C_3EF63C_name_66;
extern s16 D_8010628E_3EF63E_name_66;
extern s16 D_80106290_3EF640_name_66;
extern s16 D_80106292_3EF642_name_66;
extern s16 D_80106294_3EF644_name_66[2];
extern BoardEventTableEntry D_80106318_3EF6C8_name_66[]; /* STAGE: the arrival's space events */
extern s32 D_80106360_3EF710_name_66[2][2]; /* result banner file, [clear/fail][0] */
extern s32 D_80106370_3EF720_name_66[2];    /* "continue?" banner file */
extern s8 D_80106378_3EF728_name_66; /* nonzero skips the panels' waits (never set here) */
extern s8 D_80106379_3EF729_name_66; /* the continue question is over */
extern s8 D_8010637A_3EF72A_name_66; /* its answer, -1 = none */
extern s8 D_8010637B_3EF72B_name_66; /* the result is over */
extern s8 D_8010637C_3EF72C_name_66; /* the player chose to continue */
extern s16 D_8010637E_3EF72E_name_66; /* coins counted so far */
extern s16 D_80106380_3EF730_name_66[2][2]; /* the score panels' positions */
extern s16 D_80106388_3EF738_name_66[4][4]; /* digit x by digit count, -1000 = hidden */
extern u8 D_801063A8_3EF758_name_66[8];    /* character model */
extern s32 D_801063B0_3EF760_name_66[6];   /* func_800732B0 argument by character, | 0x54 */
extern s16 D_801063C8_3EF778_name_66[4][4]; /* copy of D_801062F8 for 80104E60 */
extern u8 D_801063E8_3EF798_name_66[3][3]; /* STAGE: clear score, [minigame][difficulty] */

/* ---- .bss ---- */

extern CoasterGame D_80106440_3EF7F0_name_66; /* the saved game */
extern s32 D_80106458_3EF808_name_66[7];  /* save-menu windows; read as s16 */
extern unk_Struct02* D_80106474_3EF824_name_66;
extern char D_80106478_3EF828_name_66[8];
extern char D_80106480_3EF830_name_66[8];
extern char D_80106488_3EF838_name_66[8];
extern s32 D_80106490_3EF840_name_66;     /* the fade window; read as s16 */
extern s16 D_80106494_3EF844_name_66;     /* 0 clear, 1 fail */
extern s16 D_80106496_3EF846_name_66;     /* coins before the result */
extern s16 D_80106498_3EF848_name_66;     /* lives before the result */
extern s32 D_8010649C_3EF84C_name_66;     /* sprite anim ids below: all read as s16 */
extern s32 D_801064A0_3EF850_name_66;     /* "clear/fail" banner group */
extern s32 D_801064A4_3EF854_name_66;
extern s32 D_801064AC_3EF85C_name_66;     /* "continue?" banner group */
extern s32 D_801064B0_3EF860_name_66;
extern s32 D_801064B8_3EF868_name_66[3];
extern s32 D_801064C4_3EF874_name_66[2];
extern s32 D_801064D0_3EF880_name_66[2][4];
extern s32 D_801064F0_3EF8A0_name_66[3];  /* the score panels' groups: lives, coins, extra life */
extern Vec D_801064FC_3EF8AC_name_66;     /* camera */
extern Vec D_80106508_3EF8B8_name_66;
extern Vec D_80106514_3EF8C4_name_66;
extern Vec D_80106520_3EF8D0_name_66;
extern Vec D_8010652C_3EF8DC_name_66;
extern Process* D_80106538_3EF8E8_name_66;
extern Process* D_8010653C_3EF8EC_name_66;
extern MBModel* D_80106540_3EF8F0_name_66; /* the two characters */
extern MBModel* D_80106544_3EF8F4_name_66;
extern MBModel* D_80106548_3EF8F8_name_66; /* the vehicle, model 0xAA */

/* ---- functions ---- */

void func_80102800_3EBBB0_name_66(void);
void func_80102830_3EBBE0_name_66(void);
s32 func_8010288C_3EBC3C_name_66(s32 bit);
void func_801028D0_3EBC80_name_66(void);
void func_80102C88_3EC038_name_66(void);
void func_80102CE4_3EC094_name_66(void);
void func_801030B8_3EC468_name_66(s32 sign);
void func_8010320C_3EC5BC_name_66(void);
void func_80103274_3EC624_name_66(void);
void func_80103300_3EC6B0_name_66(void);
void func_80103480_3EC830_name_66(void);
void func_80104244_3ED5F4_name_66(void);
void func_80104264_3ED614_name_66(void);
void func_801042CC_3ED67C_name_66(void);
void func_801042F8_3ED6A8_name_66(void);
void func_801046F8_3EDAA8_name_66(void);
void func_801049C4_3EDD74_name_66(void);
void func_80104A14_3EDDC4_name_66(void);
void func_80104A80_3EDE30_name_66(s8 idx);
void func_80104BC8_3EDF78_name_66(void);
void func_80104D48_3EE0F8_name_66(void);
void func_80104EC8_3EE278_name_66(void);
void func_80105550_3EE900_name_66(void);
void func_80105828_3EEBD8_name_66(void);
void func_801059A8_3EED58_name_66(void);
void func_80105B58_3EEF08_name_66(void);
s32 func_80105D34_3EF0E4_name_66(s16 minigame);
void func_80105E00_3EF1B0_name_66(void);
void func_80105F18_3EF2C8_name_66(void);
void func_80106118_3EF4C8_name_66(void);
void func_80106154_3EF504_name_66(void);

#endif
