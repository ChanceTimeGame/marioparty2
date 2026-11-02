#ifndef _OVL_6C_H
#define _OVL_6C_H

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
   OVL6C_ constants below, the spaces in 801060EC, the tables marked STAGE, and whether a twin
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

#define OVL6C_STAGE 8
#define OVL6C_NEXT_SCENE 0x6C
#define OVL6C_NEXT_ENTRY 1
#define OVL6C_FLAG_BASE 9       /* first stop's flag; 65: 0xD, 68: 0x1B */
#define OVL6C_BOARD_MODEL 0x37  /* func_80074154 arguments */
#define OVL6C_BOARD_FILE 0x4F
#define OVL6C_MUSIC 0x4E

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

extern board_overlay_entrypoint D_80106560_406460_name_6C[]; /* the scene table */
extern CoasterSpaceFlag D_80106590_406490_name_6C[];         /* STAGE */
extern s32 D_80106594_406494_name_6C[];   /* save-menu backdrop by character (files 0xA010F-) */
extern s32 D_801065AC_4064AC_name_6C[6];  /* save-menu labels */
extern s32 D_801065C4_4064C4_name_6C[3];  /* difficulty label */
extern s32 D_801065D0_4064D0_name_6C[3];  /* farewell message by difficulty */
extern s16 D_801065DC_4064DC_name_6C[4][2]; /* save-menu window positions, then: */
extern s16 D_801065EC_4064EC_name_6C;
extern s16 D_801065EE_4064EE_name_6C;
extern s16 D_801065F0_4064F0_name_6C;
extern s16 D_801065F2_4064F2_name_6C;
extern s16 D_801065F4_4064F4_name_6C[2];
extern s32 D_8010665C_40655C_name_6C[2][2]; /* result banner file, [clear/fail][0] */
extern s32 D_8010666C_40656C_name_6C[2];    /* "continue?" banner file */
extern s8 D_80106674_406574_name_6C; /* nonzero skips the panels' waits (never set here) */
extern s8 D_80106675_406575_name_6C; /* the continue question is over */
extern s8 D_80106676_406576_name_6C; /* its answer, -1 = none */
extern s8 D_80106677_406577_name_6C; /* the result is over */
extern s8 D_80106678_406578_name_6C; /* the player chose to continue */
extern s16 D_8010667A_40657A_name_6C; /* coins counted so far */
extern s16 D_8010667C_40657C_name_6C[2][2]; /* the score panels' positions */
extern s16 D_80106684_406584_name_6C[4][4]; /* digit x by digit count, -1000 = hidden */
extern u8 D_801066A4_4065A4_name_6C[8];    /* character model */
extern s32 D_801066AC_4065AC_name_6C[6];   /* func_800732B0 argument by character, | 0x54 */
extern s16 D_801066C4_4065C4_name_6C[4][4]; /* copy of D_801062F8 for 80104E60 */
extern u8 D_801066E4_4065E4_name_6C[3][3]; /* STAGE: clear score, [minigame][difficulty] */

/* ---- .bss ---- */

extern CoasterGame D_80106740_406640_name_6C; /* the saved game */
extern s32 D_80106758_406658_name_6C[7];  /* save-menu windows; read as s16 */
extern unk_Struct02* D_80106774_406674_name_6C;
extern char D_80106778_406678_name_6C[8];
extern char D_80106780_406680_name_6C[8];
extern char D_80106788_406688_name_6C[8];
extern s32 D_80106798_406698_name_6C;     /* the fade window; read as s16 */
extern s16 D_8010679C_40669C_name_6C;     /* 0 clear, 1 fail */
extern s16 D_8010679E_40669E_name_6C;     /* coins before the result */
extern s16 D_801067A0_4066A0_name_6C;     /* lives before the result */
extern s32 D_801067A4_4066A4_name_6C;     /* sprite anim ids below: all read as s16 */
extern s32 D_801067A8_4066A8_name_6C;     /* "clear/fail" banner group */
extern s32 D_801067AC_4066AC_name_6C;
extern s32 D_801067B4_4066B4_name_6C;     /* "continue?" banner group */
extern s32 D_801067B8_4066B8_name_6C;
extern s32 D_801067C0_4066C0_name_6C[3];
extern s32 D_801067CC_4066CC_name_6C[2];
extern s32 D_801067D8_4066D8_name_6C[2][4];
extern s32 D_801067F8_4066F8_name_6C[3];  /* the score panels' groups: lives, coins, extra life */
extern Vec D_80106804_406704_name_6C;     /* camera */
extern Vec D_80106810_406710_name_6C;
extern Vec D_8010681C_40671C_name_6C;
extern Vec D_80106828_406728_name_6C;
extern Vec D_80106834_406734_name_6C;
extern Process* D_80106840_406740_name_6C;
extern Process* D_80106844_406744_name_6C;
extern MBModel* D_80106848_406748_name_6C; /* the two characters */
extern MBModel* D_8010684C_40674C_name_6C;
extern MBModel* D_80106850_406750_name_6C; /* the vehicle, model 0xAA */

/* ---- functions ---- */

void func_80102800_402700_name_6C(void);
void func_80102830_402730_name_6C(void);
s32 func_8010288C_40278C_name_6C(s32 bit);
void func_801028D0_4027D0_name_6C(void);
void func_80102C88_402B88_name_6C(void);
void func_80102CE4_402BE4_name_6C(void);
void func_801030B8_402FB8_name_6C(s32 sign);
void func_801032A0_4031A0_name_6C(void);
void func_80103808_403708_name_6C(void);
void func_801045CC_4044CC_name_6C(void);
void func_801045EC_4044EC_name_6C(void);
void func_80104654_404554_name_6C(void);
void func_80104680_404580_name_6C(void);
void func_80104A80_404980_name_6C(void);
void func_80104D4C_404C4C_name_6C(void);
void func_80104D9C_404C9C_name_6C(void);
void func_80104E08_404D08_name_6C(s8 idx);
void func_80104F50_404E50_name_6C(void);
void func_801050D0_404FD0_name_6C(void);
void func_80105250_405150_name_6C(void);
void func_801058D8_4057D8_name_6C(void);
void func_80105BB0_405AB0_name_6C(void);
void func_80105D30_405C30_name_6C(void);
void func_80105EE0_405DE0_name_6C(void);
s32 func_801060BC_405FBC_name_6C(s16 minigame);
void func_80106188_406088_name_6C(void);
void func_801062A0_4061A0_name_6C(void);
void func_801064A0_4063A0_name_6C(void);
void func_801031D0_4030D0_name_6C(void);
void func_8010350C_40340C_name_6C(void);
void func_8010320C_40310C_name_6C(void);
void func_8010333C_40323C_name_6C(void);
void func_801033B8_4032B8_name_6C(void);
void func_801034B8_4033B8_name_6C(void);
void func_80103530_403430_name_6C(void);
void func_801064DC_4063DC_name_6C(void);

/* S5-T2 (6C): the finale's own pieces */
extern s16 D_801065F8_4064F8_name_6C[4];   /* goal marker's space by difficulty */
extern s16 D_80106610_406510_name_6C[];    /* the walked path, -1 ends it */
extern BoardEventTableEntry D_80106634_406534_name_6C[];
extern MBModel* D_80106790_406690_name_6C;
extern MBModel* D_80106794_406694_name_6C[1];
SpaceData* GetSpaceData(s16);
MBModel* func_80043510_44110(u8 id, void* arg1);
void func_80043DAC_449AC(MBModel*);
void func_800B3170_B3D70(Vec*, Vec*);
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029A8C_2A68C(s16);
f32 func_80029CE4_2A8E4(s16);
f32 HuVecDistance(Vec* a, Vec* b);
Process* func_80056FD4_57BD4(Vec* arg0, Vec* arg1, Vec* arg2, f32 arg3);
void func_80056658_57258(Vec*, Vec*, Vec*);
Process* func_80056B78_57778(Vec* arg0, Vec* arg1, Vec* arg2, s32 arg3);
f32 func_800B1830_B2430(f32);
double func_800B727C_B7E7C(double, double); /* asm-only in main */
void func_800B3870_B4470(f32* m, f32 angle);
void func_80054C78_55878(s16 space, s16* chainOut, s16* indexOut);
void func_80074F7C_75B7C(s32 overlay, s16 event, s16 fade, s16 music);
void MBMotionShiftSet(void* arg0, s16 arg1, s32 arg2, s32 arg3, u16 arg4);
void func_80103428_403328_name_6C(s16 idx);

#endif
