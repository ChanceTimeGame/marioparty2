#ifndef _OVL_41_H
#define _OVL_41_H

/* Board overlay 41 (2B10C0.c), mostly a copy of board 3E's code. Generated from ovl_3E.h: each 3E
   data/bss symbol was renamed to 41's by aligning the relocations of every 3E twin
   (tools/mp2twins.py) with 41's asm; 3E symbols with no 41 counterpart were dropped, and array
   sizes are 3E's unless a comment says 41. Board types both boards use are in
   include/game/board.h. Each function's prototype is its 3E twin's; functions without a 3E twin
   are void(void) until their fork fixes them. Main-segment declarations are 3E's. */

#include "common.h"
#include "game/board.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/data.h" /* fork D */

/* ---- main-segment API used by 3E ---- */

typedef struct MbTextWindow {
    /* 0x000 */ u8 unk_00[0x20];
    /* 0x020 */ u8 unk_20;
    /* 0x021 */ u8 unk_21[0x27C - 0x21];
} MbTextWindow; /* size 0x27C; the full type is TextWindow in 84FF0.c */

extern MbTextWindow* D_800F920C_F9E0C;
extern s32 D_800CCC18_CD818;
extern s32 D_800CC6A8_CD2A8[]; /* per board: the guide's model */
extern f32 D_800CC6C4_CD2C4[]; /* per board: the guide's facing angle */
extern s16 D_800F8D12_F9912;
extern s16 D_800CD414_CE014;
extern HmfModel* D_800FC834_FD434;

void ExecBoardScene(void*, s16);
void MBArrayShuffle(u8* output, s32 count);
void BoardSpaceTypeSet(s16 spaceIndex, u8 spaceType);
void func_800509C4_515C4(s16);
SpaceData* GetSpaceData(s16);
s32 PlaySound(s32);
void PlayMusic(s16);
MBModel* func_80043510_44110(s32, void*);
void func_80056754_57354(MBModel*);
void func_800B3170_B3D70(Vec*, Vec*);
ModelEmitterWork* func_80049ED4_4AAD4(MBModel*, s16);
void func_80049F90_4AB90(ModelEmitterWork*);
void HuVecCopyXYZ(Vec*, f32, f32, f32);
void func_800B39F0_B45F0(f32*, f32);
void MBModelKill(void*);
void MBMotionSet(MBModel*, s16, s32);
void MBMotionShiftSet(void* arg0, s16 arg1, s32 arg2, s32 arg3, u16 arg4);
void func_8005B338_5BF38(void*);
UnkMBGuideData* func_80050304_50F04(s32, s32); /* MBGuideCreate */
void func_8005057C_5117C(UnkMBGuideData*); /* MBGuideKill */
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* cos */
void func_8005AB50_5B750(MBModel* arg0, s16 arg1, s16 arg2, s32 arg3);
void func_8005AC6C_5B86C(MBModel*, s32);
void func_80067558_68158(void);
void func_80067720_68320(void);
void func_80051500_52100(void);
void func_80053608_54208(f32);
s32 func_80053998_54598(void); /* camera still moving */
void func_800890CC_89CCC(s16, s32, s32, s32);
void func_8008E2DC_8EEDC(s32 winId, s32 sound);
void func_8008E4D0_8F0D0(s32 winId, s32 sound);
void func_80057DC0_589C0(s16);
void func_8002D4A0_2E0A0(s16);
void func_80029FE4_2ABE4(s16, f32);
u16 MBDCameraPos3DSet(Vec*);
void MBCameraSpeedSet(f32);

extern s16 D_800FC734_FD334;
extern s16 D_800FA198_FAD98; /* camera button enabled */
extern s16 D_80101058_101C58;
GW_PLAYER* BoardPlayerGet(s32);
Process* func_80056D80_57980(Vec*, Vec*, Vec*, s32);
void func_8005670C_5730C(Vec*);
void MBPlayerVibrate(s16, s16);
void func_80079428_7A028(s32);
void MBPlayerMotionSet(s32 index, s16 animation, s32 unk);
void func_80079718_7A318(s32, s32);
void omPrcSetStatBit(Process*, s32);
void omPrcResetStatBit(Process* process, s32 bit);
void func_80067C6C_6886C(s32 arg0); /* map view */
extern s16 mbDlgWinId;
void func_8008D59C_8E19C(s16, s16);
void func_80089284_89E84(s16, s32, s32);
u8 func_80057718_58318(void);
void func_8008CFD0_8DBD0(s16, s16, s16, s16, u8);
void func_8008D07C_8DC7C(s16, s16, s16, s16);
void func_8008D854_8E454(s32 arg0, s16 arg1);
s32 func_8008BB48_8C748(s16, s16, s32);
s32 func_80059FD0_5ABD0(s32); /* the player's rank */
extern s16 D_800F8CE4_F98E4[]; /* board state halfwords; D_800F8D12 is [0x17] */
extern MBModel* D_800F64C8_F70C8; /* the item/Boo marker model */
void omInitObjMan(s32, s32);
void omOvlGotoEx(s32 arg0, s16 arg1, u16 arg2);
void SetPlayerOntoChain(s16 player, s16 chain_index, s16 space_index);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80062E10_63A10(s32 arg0, s16 arg1, s32 arg2, s32 arg3);
void func_80055928_56528(s16* arg0);
void func_80055980_56580(s16* arg0);
void func_8004D60C_4E20C(s32, void (*)(void)); /* board event slot */
void func_80044D98_45998(s32 (*)(void)); /* fork D: the CPU item check callback returns s32 */
void func_800542E8_54EE8(s32, s16);
void func_800632F0_63EF0(s16 arg0);
void func_80020070_20C70(s32);
void func_80053AA0_546A0(s32);
void EventTableHydrate(BoardEventTableEntry* table);
void func_80066C34_67834(u32 arg0);
void func_80043DAC_449AC(MBModel*);
MBModel* MBModelParamCreate(MBModel*);
s32 func_80041AEC_426EC(s8 arg0, void* arg1, s16 arg2, s16 arg3); /* space marker */
void func_80041B40_42740(s32 arg0);
void func_8002D124_2DD24(s16 index);
void MBModelDispOff(MBModel*);
void MBModelDispOn(MBModel*);
void HuVecAdd(Vec*, Vec*, Vec*);
void func_80029E80_2AA80(s16, s32, s32);
void func_80056658_57258(Vec*, Vec*, Vec*); /* direction from a to b as a rotation */
omObjData* omAddObj(s16, u16, u16, s16, void*);
void func_80041B60_42760(s8 arg0, Vec* arg1, s16 arg2, s16 arg3);
f32 func_80042BE0_437E0(Vec*); /* y angle of a rotation */
void MBMasuArrowAngleAdd(f32); /* 41 */

/* ---- 3E data (asm/data/overlays/ovl_3E_name/2A6BF0.data.s) ---- */

extern s16 D_80110A60_2BF320_name_41[8]; /* star positions, shuffled */
extern s16 D_80110A70_2BF330_name_41[8]; /* each position's earliest slot */
extern s16 D_80110A80_2BF340_name_41[]; /* positions not to show first, -1 ended */
extern s16 D_80110A84_2BF344_name_41[8]; /* star position board flags */
extern s16 D_80110A94_2BF354_name_41[8]; /* star spaces */
extern s16 D_80110AA4_2BF364_name_41[8]; /* star camera spaces */
extern s32 D_80110AB4_2BF374_name_41; /* guide motions */
extern s32 D_80110AB8_2BF378_name_41;
extern f32 D_80110ABC_2BF37C_name_41[9]; /* per board */
extern s32 D_80110AE0_2BF3A0_name_41;
extern u8 D_80110AE4_2BF3A4_name_41[3][4]; /* steal-a-star chance by turn band, coin band */
extern s16 D_80110AF0_2BF3B0_name_41[2]; /* -1 ended */
extern s16 D_80110AF4_2BF3B4_name_41[8]; /* -1 ended */
extern s16 D_80110B04_2BF3C4_name_41[7][2]; /* star space marker offsets */
extern s16 D_80110B20_2BF3E0_name_41[1][2]; /* 41: one entry */
extern s16 D_80110B24_2BF3E4_name_41[2][2];
extern s16 D_80110B2C_2BF3EC_name_41[2];
extern s16 D_80110B30_2BF3F0_name_41[2][2]; /* signpost marker offsets */
extern s16 D_80110B38_2BF3F8_name_41[2][2]; /* signpost facing: from, to spaces */
extern s16 D_80110B40_2BF400_name_41[8]; /* star spaces (markers) */
extern s16 D_80110B50_2BF410_name_41[8]; /* their flags */
extern s32 D_80110B60_2BF420_name_41; /* marker id, -1 none */
extern s16 D_80110B64_2BF424_name_41[2];
extern s16 D_80110B68_2BF428_name_41[2]; /* bank spaces */
extern Vec D_80110B6C_2BF42C_name_41[5]; /* bank coin offsets */
extern Vec D_80110BA8_2BF468_name_41[5]; /* bank coin rotations (x, z used) */
extern s16 D_80110BE4_2BF4A4_name_41[2]; /* signpost spaces */
extern u8 D_80110BE9_2BF4A9_name_41[]; /* signpost model per board, at [board * 2] */
extern s32 D_80110BF4_2BF4B4_name_41[9]; /* per board: sound, -1 none (played as s16) */
extern s32 D_80110C18_2BF4D8_name_41[9]; /* per board: sound, -1 none (played as s16) */
extern s32 D_80110C3C_2BF4FC_name_41[9]; /* per board: delay */
extern s32 D_80110C60_2BF520_name_41[9]; /* per board: sound, -1 none (played as s16) */
extern s16 D_80110C84_2BF544_name_41[2];
extern s16 D_80110C88_2BF548_name_41;
extern s16 D_80110C8C_2BF54C_name_41[2]; /* 41: second marker spaces */
extern s16 D_80110C90_2BF550_name_41[2][2]; /* 41: their facing, from and to spaces */
extern BoardEventTableEntry D_80110FD8_2BF898_name_41[];
extern BoardEventTableEntry D_80111040_2BF900_name_41[];
extern BoardEventTableEntry D_80111398_2BFC58_name_41[];


/* ---- 3E bss (asm/data/overlays/ovl_3E_name/ovl_3E_bss.bss.s) ---- */

extern Process* D_80111EC0_2C0780_name_41; /* star appear process */
extern s32 D_80111EC4_2C0784_name_41; /* star process: 1 = take a star away */
extern s32 D_80111EC8_2C0788_name_41; /* help windows */
extern s32 D_80111ECC_2C078C_name_41;
extern s32 D_80111ED0_2C0790_name_41;
extern s32 D_80111ED4_2C0794_name_41;
extern s32 D_80111ED8_2C0798_name_41;
extern s32 D_80111EE0_2C07A0_name_41[4]; /* the other players, by rank */
extern s32 D_80111EF0_2C07B0_name_41[4]; /* players other than the current one, by coins */
extern s32 D_80111F00_2C07C0_name_41; /* what can be stolen: 0 coins, 1 a star, 2 nothing */
extern s32 D_80111F04_2C07C4_name_41; /* the player Boo steals from */
extern s32 D_80111F08_2C07C8_name_41; /* Boo's choice: a player slot, or 0/1/2 */
extern MBModel* D_80111F0C_2C07CC_name_41;
extern MBModel* D_80111F10_2C07D0_name_41[7];
extern MBModel* D_80111F2C_2C07EC_name_41;
extern MBModel* D_80111F60_2C0820_name_41;
extern MBModel* D_80111F6C_2C082C_name_41;
extern MBModel* D_80111F30_2C07F0_name_41[1]; /* 41: one */
extern MBModel* D_80111F64_2C0824_name_41[2];
extern MBModel* D_80111F70_2C0830_name_41[2];
extern MBModel* D_80111F34_2C07F4_name_41;
extern MBModel* D_80111F38_2C07F8_name_41[10]; /* bank coins */
extern MBModel* D_80111F60_2C0820_name_41;
extern MBModel* D_80111F64_2C0824_name_41[2]; /* signposts */
extern MBModel* D_80111F78_2C0838_name_41;
extern s32 D_80110C98_2BF558_name_41;

s32 func_80060210_60E10(s32);
s32 func_800609D8_615D8(void); /* status windows still moving */
void MBStatusItemDispSetAll(s32);
Process* MBDCameraZoomMotStart(f32);
void func_800628C0_634C0(s32 player, f32, f32);
s32 func_8006286C_6346C(s32 player);
void func_800636F8_642F8(s32);
void func_800509FC_515FC(void);
void func_80054C78_55878(s16 space, s16* chainOut, s16* linkOut);
void MBDlgWinExec(s32, s32);
void func_800495D8_4A1D8(s32, s32);
s16 func_800632FC_63EFC(void); /* the board's music */
extern s16 D_800F8D16_F9916; /* D_800F8CE4_F98E4[0x19] */
s16 GetAbsSpaceIndexFromChainSpaceIndex(u16, u16);
s32 func_80046D2C_4792C(s32);
void func_8004655C_4715C(s32);
void func_80056458_57058(void); /* wait for the message window */
void func_8004CA14_4D614(s32 player, s32 coins); /* add coins */
void func_8006135C_61F5C(s32 player, s32 coins, s32);
void func_800797DC_7A3DC(s32, s16);
extern u16 D_800CAFD8[]; /* item ids; the low byte is the item */
extern s32 D_800CCBDC_CD7DC[]; /* per item: picture file */
s16 SprCreate(s32 num, s32 attr);
s16 SprAnimRead(void*);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
void SprAttrSet(s16, s16, s32);
void SprPosSet(s16 grpIdx, s16 idx, s16 x, s16 y);
void func_80082488_83088(s16 grpIdx, s16 idx, u16 a); /* sprite alpha */
void SprAnimKill(s16 animIdx);
void SprKill(s16 idx);
s16 func_80044800_45400(void* tree); /* MBComTreeExec: the CPU's choice */
void MBPlayerForwardSet(s16 playerNo);
void func_80061518_62118(void);
void func_80061584_62184(void);
s32 func_8004CC7C_4D87C(s32, s32, s32); /* help window */
void MBHelpWinKill(s32);
Process* func_80048A48_49648(s32 player);
s32 func_80047E70_48A70(s32);
void func_800495A8_4A1A8(s8 arg0);
void func_80063710_64310(Vec* pos);
void func_800558E8_564E8(s16);
s32 func_80054D3C_5593C(s16 arg0, s16* arg1, s16* arg2);
void func_80063734_64334(Vec* arg0);
void CameraScissorSet(s16, void*);
s16 GetCurrentPlayerIndex(void);
s16 RNGPercentChance(s8 arg0);
extern u8 D_800CC000[]; /* item prices */
void func_80056C30_57830(s16 playerNo, s32 arg1, s16 masuAbsIndex);
void func_8004CA34_4D634(s32, s32);
void func_800614B4_620B4(s32, s32);
void InitFadeOut(s32, s32);
void InitFadeIn(s32, s32);
s32 func_8008F618_90218(void); /* fade still running */
void func_80063C40_64840(s32, s32);
void* func_800672BC_67EBC(s16 arg0, s16 arg1, s32 arg2);
void func_8006735C_67F5C(void*);
void func_8005DDEC_5E9EC(s32 playerNo, s16 arg1, s16 arg2, s16 arg3, u16 arg4);
void MBDlgResultWinExec(s32);
void MBDlgWinClose(void);
void func_80056168_56D68(void);
void func_80056368_56F68(s16, u32, s32, s32, s32, s32, s32); /* message with two string args */
s32 MBRand(f32);
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_800629F0_635F0(s32 player, s16); /* status window */
void func_80062588_63188(s16);
extern MBModel* D_800CC1F0_CCDF0; /* the Bowser suit model */
void func_8005070C_5130C(void); /* MBKSuitCreate */
void MBKSuitMotionSet(s16 arg0, s32 arg1);
void func_800B3B80_B4780(f32* mtx, f32 angle); /* rotate a model matrix */
void func_80050860_51460(void); /* MBKSuitKill */
Process* func_80056B78_57778(Vec* arg0, Vec* arg1, Vec* arg2, s32 arg3); /* turn arg0 toward arg1 */

extern s8 D_800CCC16; /* set while the lamp's star event runs */
extern s16 D_800FA188_FAD88;
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_8002D0A0_2DCA0(s16, u8); /* model alpha */
void* func_80027154_27D54(s32, s32); /* HuMemAllocTag */
s32 MBRand(f32);
void omDelObj(omObjData*);
MBModel* MBModelFileCreate(s32 arg0, s32 arg1, f32 arg2, f32 arg3, u32* arg4);
s32 func_800556F4_562F4(s16, s16); /* space event call */
s16 func_800670B0_67CB0(void);
void* func_800672BC_67EBC(s16, s16, s32); /* player vibrate start */
void func_8006735C_67F5C(void*); /* player vibrate stop */
void func_8008F624_90224(s32, s32, s32); /* wipe colour */
void func_80054C78_55878(s16 space, s16* chainOut, s16* indexOut);
void func_800650BC_65CBC(void);
void func_80078FF8_79BF8(void);
void func_800115B4_121B4(s32);
void func_80055E60_56A60(void);
void SprPosSet(s16 grpIdx, s16 idx, s16 x, s16 y);
void func_8006296C_6356C(s16 player, f32* x, f32* y); /* status window position */
void func_800629AC_635AC(s16 player, s16 x, s16 y); /* status window move */
#include "game/malloc.h"
#include "game/data.h"
s16 SprCreate(s32 num, s32 attr);
s16 SprAnimRead(void* arg0);
/* Retail calls these two as int-returning (no sign extension of the result at the call). Every
   user here passes the id on to s16 parameters or stores it in a 16-bit slot, so the host's
   truncation keeps it right. */
#define SprCreate_s32(num, attr) (((s32(*)(s32, s32))SprCreate)(num, attr))
#define SprAnimRead_s32(data) (((s32(*)(void*))SprAnimRead)(data))
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
void SprAttrSet(s16 grpIdx, s16 idx, s32 flag);
void SprKill(s16 idx);
void SprAnimKill(s16 animIdx);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
void func_800822A8_82EA8(s16 group, s16 member, u16 arg2, s32 arg3);
void func_80082488_83088(s16 grpIdx, s16 idx, u16 a); /* sprite alpha */
void func_80062A28_63628(s16 player, f32 arg1); /* status window shake */

f32 __sinf(f32);
extern u16 ContDStkTrg[4];
void MBWinInsertOpen(s32 arg0, char* arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5);
void func_80055E3C_56A3C(s32 arg0);
/* Messages; indexed from 7, so the label is 14 bytes before the table (0x8011244C): a
   layout-dependent label, keep the data in place on the host. */
s32 func_800558F4_564F4(void); /* the current space (retail: int-returning) */
s32 func_80046D2C_4792C(s32 arg0);
omObjData* func_800446B4_452B4(MBModel* arg0, Vec* arg1, s32 arg2);
void func_80056C30_57830(s16 playerNo, s32 arg1, s16 masuAbsIndex);
Process* MBDCameraZoomMotStart(f32 arg0);
void MBDlgWinExec(s32 arg0, s32 arg1);
void func_80056368_56F68(s16 arg0, u32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6); /* message window; the s32s are strings */
void MBDlgWinClose(void);
void func_80056168_56D68(void);
void func_80078EC8_79AC8(void);
void func_8004CA34_4D634(s32 arg0, s32 arg1);
void func_800614B4_620B4(s32 arg0, s32 arg1);
void func_8006135C_61F5C(s32 arg0, s32 arg1, s32 arg2);
void func_8004655C_4715C(s32 arg0);
void func_80047A50_48650(s32);
s16 func_80046F98_47B98(s32);
void func_80064FF8_65BF8(void);
void func_80059120_59D20(void*, f32, f32);
void func_80047BB8_487B8(s32);
void func_8005DDEC_5E9EC(s32 playerNo, s16 arg1, s16 arg2, s16 arg3, u16 arg4);
void func_80053F7C_54B7C(void);
void func_8004CDE0_4D9E0(void);
s32 func_8004CE80_4DA80(void);
void func_8004D5B0_4E1B0(void);
void func_80053F54_54B54(void);
void func_80079848_7A448(s16 arg0);
void func_80046EDC_47ADC(s32);
s32 func_80060210_60E10(s32);
s32 func_800609D8_615D8(void);
void MBStatusItemDispSetAll(s32 arg0);
void func_80047D78_48978(s32 arg0, s32 arg1);
s16 GetAbsSpaceIndexFromChainSpaceIndex(u16, u16);
void func_800558E8_564E8(s16 arg0);
void func_80045650_46250(s32 arg0);


/* ---- 297AD0.c ---- */


/* fork B */
#include "game/data.h"
struct unk_8003B8D4Struct; /* 41B20.c's direction prompt */



void SetNextChainAndSpace(s16 arg0, s16 arg1, s16 arg2);
s16 GetAbsSpaceIndexFromChainSpaceIndex(u16, u16);
void HuVecMulScalar(Vec*, f32, Vec*);
s16 func_80079798_7A398(s16, s16);
void func_800797DC_7A3DC(s32, s16);
void omDelObj(omObjData*);
void func_8002D0A0_2DCA0(s16, u8);
/* 41B20.c defines this void: it returns func_800419A4_425A4's prompt only through v0 */
struct unk_8003B8D4Struct* func_80041A74_42674(s16, s16*);
s32 func_800417EC_423EC(struct unk_8003B8D4Struct*, s16, s16);
s32 func_80041610_42210(struct unk_8003B8D4Struct*, s32);
s32 DirectionPrompt(struct unk_8003B8D4Struct*);
void func_8004108C_41C8C(struct unk_8003B8D4Struct*);
s32 PlayerIsCPU(s16);
void MBDlgWinCreate(s32, s32);
void MBDlgWinExec(s32, s32);
void MBDlgWinClose(void);
void func_80056168_56D68(void);
Process* MBDCameraZoomMotStart(f32);
void func_80056C30_57830(s16 playerNo, s32 arg1, s16 masuAbsIndex);
s32 func_80046D2C_4792C(s32);
void func_8004655C_4715C(s32);
void* func_800672BC_67EBC(s16, s16, s32);
void func_8006735C_67F5C(void*);
s16 BoardGetChainLength(u16 chainIndex);
void HuVecSubtract(Vec*, Vec*, Vec*);
void MBVecNormalize(Vec*);
/* B2470.c types it (Vec*), but it is HuVecGetLength3F(x, y, z): func_800B1840_B2440 squares f12, f14, a2 */
f32 func_800B1870_B2470(f32 x, f32 y, f32 z);
f32 HuVecDistance(Vec* a, Vec* b);
Process* func_80056FD4_57BD4(Vec* arg0, Vec* arg1, Vec* arg2, f32 arg3);
Process* func_80057150_57D50(Vec* arg0, Vec* arg1, Vec* arg2, f32 arg3);
void func_800B3B80_B4780(f32* mtx, f32 angle); /* MP3 func_8008A430_8B030: matrix rotation */
void ChangeSpaceTextures(s16);
void func_8004CA34_4D634(s32, s32);
void func_800614B4_620B4(s32, s32);
void func_80056124_56D24(void);
void func_80056458_57058(void);
s32 func_800573AC_57FAC(void);
void func_80059120_59D20(void*, f32, f32);
void func_80059158_59D58(void*);
/* 63670.c defines it (void); retail passes 2 */
void func_8006706C_67C6C();
extern s8 D_800CCC16;
extern s16 D_800F64B0_F70B0;
s32 func_80047DE8_489E8(s32);
s16 SprCreate(s32 num, s32 attr);
s16 SprAnimRead(void*);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
void SprAttrSet(s16, s16, s32);
void SprPosSet(s16, s16, s16, s16);
void func_80082488_83088(s16, s16, u16);
void SprAnimKill(s16);
void SprKill(s16);
Process* func_80056B78_57778(Vec* arg0, Vec* arg1, Vec* arg2, s32 arg3);
void MBItemDescExec(s32 arg0);
void func_8008DAC0_8E6C0(s8 arg0);
void func_80056524_57124(s32);
extern u8 D_800CC000[]; /* item prices */
extern s32 D_800CCBDC_CD7DC[]; /* item sprite files */
#define ABS_F(x) ((x) > 0.0f ? (x) : 0.0f - (x))

extern DecisionTreeNonLeafNode D_80110CCC_2BF58C_name_41[];
extern DecisionTreeNonLeafNode D_80110CFC_2BF5BC_name_41[];
extern DecisionTreeNonLeafNode D_80110D14_2BF5D4_name_41[];
extern s16 D_80110D20_2BF5E0_name_41[];
extern DecisionTreeNonLeafNode D_80110D28_2BF5E8_name_41[];
extern s16 D_80110D50_2BF610_name_41[];

/* ---- 2B10C0.c: all 126 functions; each takes its 3E twin's prototype (tools/mp2twins.py),
   functions without a 3E twin are void(void) until their fork fixes them ---- */

s16 func_80102830_2B10F0_name_41(void);
void func_8010285C_2B111C_name_41(void);
void func_80102A44_2B1304_name_41(void);
void func_80102AB0_2B1370_name_41(void);
void func_80102B54_2B1414_name_41(void);
s32 func_80102C3C_2B14FC_name_41(s32 space);
void func_80102D28_2B15E8_name_41(void);
void func_80102F4C_2B180C_name_41(UnkMBGuideData* guide);
void func_80102FFC_2B18BC_name_41(void);
void func_80103548_2B1E08_name_41(void);
void func_80103968_2B2228_name_41(MBModel* parent);
void func_801039E4_2B22A4_name_41(MBModel* parent);
void func_80103A64_2B2324_name_41(void);
void func_80103AF4_2B23B4_name_41(void);
s32 func_80103B70_2B2430_name_41(void);
void func_80103BC4_2B2484_name_41(void);
void func_80103C94_2B2554_name_41(void);
s32 func_80103CF4_2B25B4_name_41(u8* items);
s32 func_80103FB0_2B2870_name_41(void); /* the chosen option */
s32 func_801041D4_2B2A94_name_41(void); /* the chosen option */
void func_80104380_2B2C40_name_41(void);
s32 func_801045C0_2B2E80_name_41(void);
void func_80104778_2B3038_name_41(void);
void func_80104F7C_2B383C_name_41(void);
s32 func_8010537C_2B3C3C_name_41(u8* items);
s32 func_80105630_2B3EF0_name_41(s32 arg0, u8* items);
void func_801058A4_2B4164_name_41(void);
void func_801058E0_2B41A0_name_41(void);
void func_80105980_2B4240_name_41(void);
void func_80105BE8_2B44A8_name_41(void);
void func_80105C70_2B4530_name_41(void);
void func_80105C9C_2B455C_name_41(s16 arg0);
void func_80105DA0_2B4660_name_41(void);
void func_80105E28_2B46E8_name_41(void);
void func_80105F10_2B47D0_name_41(void);
void func_80105F58_2B4818_name_41(s16 arg0);
void func_80106078_2B4938_name_41(void);
void func_801060D4_2B4994_name_41(void);
void func_801061D0_2B4A90_name_41(s16 arg0);
void func_8010633C_2B4BFC_name_41(void);
void func_801063A4_2B4C64_name_41(s16 arg0);
void func_80106500_2B4DC0_name_41(void);
void func_80106560_2B4E20_name_41(void);
void func_801065BC_2B4E7C_name_41(s32 arg0);
void func_80106660_2B4F20_name_41(s32 arg0);
void func_801066CC_2B4F8C_name_41(void);
void func_80106744_2B5004_name_41(void);
void func_80106780_2B5040_name_41(s16 arg0); /* a variant of 3E func_80105F0C */
void func_80106904_2B51C4_name_41(void);
void func_80106964_2B5224_name_41(void);
s32 func_801069E8_2B52A8_name_41(s32 arg0); /* the chosen option */
void func_80106C40_2B5500_name_41(void);
void func_80106F38_2B57F8_name_41(void);
void func_80107230_2B5AF0_name_41(void);
void func_80107254_2B5B14_name_41(void);
void func_80107278_2B5B38_name_41(void);
void func_8010729C_2B5B5C_name_41(void);
void func_801072C0_2B5B80_name_41(void);
void func_801072E4_2B5BA4_name_41(void);
void func_80107308_2B5BC8_name_41(void);
void func_8010732C_2B5BEC_name_41(void);
void func_80107350_2B5C10_name_41(void);
void func_80107374_2B5C34_name_41(void);
void func_80107574_2B5E34_name_41(void); /* star / bank space */
void func_80107DB4_2B6674_name_41(void);
s32 func_801081E0_2B6AA0_name_41(s32 arg0);
s32 func_8010824C_2B6B0C_name_41(void);
void func_80108298_2B6B58_name_41(void);
void func_801088A4_2B7164_name_41(MBModel* model);
void func_80108944_2B7204_name_41(MBModel* model);
s32 func_801089E4_2B72A4_name_41(s32 player);
void func_801092C0_2B7B80_name_41(void);
s32 func_801092E4_2B7BA4_name_41(s32 player);
void func_8010A020_2B88E0_name_41(void);
void func_8010A174_2B8A34_name_41(void); /* twin func_800491B4_49DB4 (main) */
void func_8010A1B0_2B8A70_name_41(void);
void func_8010AB8C_2B944C_name_41(void); /* twin func_80017228_17E28 (main) */
void func_8010ABA8_2B9468_name_41(void); /* twin func_80061734_62334 (main) */
omObjData* func_8010ABC4_2B9484_name_41(Vec* pos, f32 scaleSpeed, f32 fadeSpeed, s16 kill, Vec* vel);
void func_8010AD04_2B95C4_name_41(omObjData* obj);
void func_8010AE1C_2B96DC_name_41(void);
void func_8010B1B8_2B9A78_name_41(void);
void func_8010B228_2B9AE8_name_41(void);
void func_8010B414_2B9CD4_name_41(void);
Process* func_8010B660_2B9F20_name_41(s16 sprite, s16 x0, s16 y0, s16 x1, s16 y1, s16 frames);
void func_8010B70C_2B9FCC_name_41(void);
void func_8010BABC_2BA37C_name_41(void);
void func_8010BE08_2BA6C8_name_41(void);
void func_8010C134_2BA9F4_name_41(void);
void func_8010C598_2BAE58_name_41(void);
void func_8010CB10_2BB3D0_name_41(void);
void func_8010CD80_2BB640_name_41(void);
void func_8010CFB4_2BB874_name_41(void);
void func_8010D2C8_2BBB88_name_41(void);
void func_8010D93C_2BC1FC_name_41(void);
void func_8010DB70_2BC430_name_41(void);
void func_8010E080_2BC940_name_41(void);
void func_8010E290_2BCB50_name_41(void);
void func_8010E474_2BCD34_name_41(void);
void func_8010E4B4_2BCD74_name_41(void); /* twin func_8004D734_4E334 (main) */
void func_8010E4D4_2BCD94_name_41(void); /* twin func_8004D734_4E334 (main) */
void func_8010E4F4_2BCDB4_name_41(void); /* twin func_8004D734_4E334 (main) */
void func_8010E514_2BCDD4_name_41(void); /* twin func_8004D734_4E334 (main) */
void func_8010E534_2BCDF4_name_41(void); /* twin func_8004D734_4E334 (main) */
void func_8010E554_2BCE14_name_41(void); /* twin func_8004D734_4E334 (main) */
void func_8010E574_2BCE34_name_41(void);
s32 func_8010E5B8_2BCE78_name_41(void); /* the chosen option */
void func_8010E7E8_2BD0A8_name_41(void);
void func_8010E960_2BD220_name_41(void);
void func_8010EADC_2BD39C_name_41(void);
void func_8010F318_2BDBD8_name_41(void);
void func_8010F33C_2BDBFC_name_41(void);
void func_8010F378_2BDC38_name_41(void);
void func_8010F39C_2BDC5C_name_41(void);
void func_8010F3D8_2BDC98_name_41(void);
void func_8010F448_2BDD08_name_41(void);
void func_8010FC00_2BE4C0_name_41(omObjData* obj);
void func_8010FC54_2BE514_name_41(void);
void func_8010FD98_2BE658_name_41(void);
void func_801103B4_2BEC74_name_41(void); /* twin func_80017228_17E28 (main) */
void func_801103D0_2BEC90_name_41(void); /* twin func_80061734_62334 (main) */
void func_801103EC_2BECAC_name_41(void);
s32 func_80110440_2BED00_name_41(void); /* fork D: returns the use-item answer */
s32 func_80110664_2BEF24_name_41(void);
s32 func_801109E0_2BF2A0_name_41(void);

#endif
