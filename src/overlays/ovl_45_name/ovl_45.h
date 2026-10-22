#ifndef _OVL_45_H
#define _OVL_45_H

/* Board overlay 3E (297AD0.c). Board-library types shared by the other boards are in
   include/game/board.h; this header holds 3E's own structs, its data/bss and a prototype for
   every function of 297AD0.c. Prototypes after 80106944 (forks B-D) came from the asm's register
   use only: arguments read before any write, a return value its callers read. Integer arguments
   are written s32 even where the asm narrows them; the fork that owns a function fixes its line.
   Data and bss below are the symbols 80102800-80106944 use; add others in address order. */

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

/* ---- 3E data (asm/data/overlays/ovl_3E_name/2A6BF0.data.s) ---- */

extern s16 D_80110D00_2EF430_name_45[8]; /* star positions, shuffled */
extern s16 D_80110D10_2EF440_name_45[8]; /* each position's earliest slot */
extern s16 D_80110D20_2EF450_name_45[]; /* positions not to show first, -1 ended */
extern s16 D_80110D24_2EF454_name_45[8]; /* star position board flags */
extern s16 D_80110D34_2EF464_name_45[8]; /* star spaces */
extern s16 D_80110D44_2EF474_name_45[8]; /* star camera spaces */
extern s32 D_80110D54_2EF484_name_45; /* guide motions */
extern s32 D_80110D58_2EF488_name_45;
extern f32 D_80110D5C_2EF48C_name_45[9]; /* per board */
extern s32 D_80110D80_2EF4B0_name_45;
extern u8 D_80110D84_2EF4B4_name_45[3][4]; /* steal-a-star chance by turn band, coin band */
extern s16 D_80110DB4_2EF4E4_name_45[7][2]; /* star space marker offsets */
extern s16 D_80110DD0_2EF500_name_45[2][2];
extern s16 D_80110DD8_2EF508_name_45[2][2];
extern s16 D_80110DE0_2EF510_name_45[2];
extern s16 D_80110DE4_2EF514_name_45[2][2]; /* signpost marker offsets */
extern s16 D_80110DEC_2EF51C_name_45[2][2]; /* signpost facing: from, to spaces */
extern s16 D_80110DF4_2EF524_name_45[8]; /* star spaces (markers) */
extern s32 D_80110E14_2EF544_name_45; /* marker id, -1 none */
extern s16 D_80110E18_2EF548_name_45[2];
extern s16 D_80110E1C_2EF54C_name_45[2]; /* bank spaces */
extern Vec D_80110E20_2EF550_name_45[5]; /* bank coin offsets */
extern Vec D_80110E5C_2EF58C_name_45[5]; /* bank coin rotations (x, z used) */
extern s16 D_80110E98_2EF5C8_name_45[2]; /* signpost spaces */
extern u8 D_80110E9D_2EF5CD_name_45[]; /* signpost model per board, at [board * 2] */
extern s32 D_80110EA8_2EF5D8_name_45[9]; /* per board: sound, -1 none (played as s16) */
extern s32 D_80110ECC_2EF5FC_name_45[9]; /* per board: sound, -1 none (played as s16) */
extern s32 D_80110EF0_2EF620_name_45[9]; /* per board: delay */
extern s32 D_80110F14_2EF644_name_45[9]; /* per board: sound, -1 none (played as s16) */
extern s16 D_80110F38_2EF668_name_45[2];
extern s16 D_80110F3C_2EF66C_name_45;

/* 3E's rodata (0x2A8860-0x2A89A0, carved by the coordinator) */
extern const u8 D_80112EC0_2F15F0_name_45[4]; /* {1, 2, 4, 8}: window choice masks per pad; read by 6 functions */

/* ---- 3E bss (asm/data/overlays/ovl_3E_name/ovl_3E_bss.bss.s) ---- */

extern Process* D_80113000_2F1730_name_45; /* star appear process */
extern s32 D_80113004_2F1734_name_45; /* star process: 1 = take a star away */
extern s32 D_80113008_2F1738_name_45; /* help windows */
extern s32 D_8011300C_2F173C_name_45;
extern s32 D_80113010_2F1740_name_45;
extern s32 D_80113014_2F1744_name_45;
extern s32 D_80113018_2F1748_name_45;
extern s32 D_80113020_2F1750_name_45[4]; /* the other players, by rank */
extern s32 D_80113030_2F1760_name_45[4]; /* players other than the current one, by coins */
extern s32 D_80113040_2F1770_name_45; /* what can be stolen: 0 coins, 1 a star, 2 nothing */
extern s32 D_80113044_2F1774_name_45; /* the player Boo steals from */
extern s32 D_80113048_2F1778_name_45; /* Boo's choice: a player slot, or 0/1/2 */
extern MBModel* D_80113078_2F17A8_name_45;
extern MBModel* D_80113080_2F17B0_name_45[10]; /* bank coins */
extern MBModel* D_801130A8_2F17D8_name_45;
extern MBModel* D_801130AC_2F17DC_name_45[2]; /* signposts */

extern Vec2f3E D_80111834_2EFF64_name_45[4];
extern Vec2f3E D_80111854_2EFF84_name_45[4]; /* per player: window positions (item events) */
extern Vec2f3E D_80111874_2EFFA4_name_45[4];
extern Vec2f3E D_80111894_2EFFC4_name_45[4];
extern s32 D_801118B4_2EFFE4_name_45[6]; /* per board: message */
s32 func_80060210_60E10(s32);
s32 func_800609D8_615D8(void); /* status windows still moving */
void MBStatusItemDispSetAll(s32);
extern s16 D_801118CC_2EFFFC_name_45[6]; /* per board: message window */
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
extern f32 D_80111BFC_2F032C_name_45[4]; /* scissor box {0, 0, 320, 240} */
extern s32 D_80112770_2F0EA0_name_45[]; /* decision trees (CPU item use) */
extern s32 D_801127D0_2F0F00_name_45[];
extern s32 D_80112B00_2F1230_name_45[];
extern s32 D_80112CE0_2F1410_name_45[];
s16 GetCurrentPlayerIndex(void);
s16 RNGPercentChance(s8 arg0);
extern u8 D_800CC000[]; /* item prices */
extern s32 D_80112D40_2F1470_name_45[]; /* decision trees (CPU shop) */
extern s32 D_80112D58_2F1488_name_45[];
extern s32 D_80112DC4_2F14F4_name_45[]; /* decision tree (CPU yes/no) */
extern s32 D_80112DE8_2F1518_name_45; /* set: the CPU's next answer is option 2 */
extern u8* D_80112E34_2F1564_name_45[]; /* per character: items the CPU tries to buy */
extern s8* D_80112E94_2F15C4_name_45[]; /* per character: their percent chances */
extern u8 D_80112EAC_2F15DC_name_45[]; /* per character: list length */
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
extern MBModel* D_801130CC_2F17FC_name_45;
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

extern s32 D_801116AC_2EFDDC_name_45[6]; /* per character: sprite file */
extern Unk3EVec2f D_8011166C_2EFD9C_name_45[4]; /* per player: lost star start */
extern Unk3EVec2f D_8011168C_2EFDBC_name_45[4]; /* per player: lost star velocity */
f32 __sinf(f32);
extern Unk3ERange D_801116C4_2EFDF4_name_45[6]; /* turn range -> star price */
extern Unk3ERange D_801116D8_2EFE08_name_45[14]; /* press count range -> discount */
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

s16 func_80102830_2E0F60_name_45(void);
void func_8010285C_2E0F8C_name_45(void);
void func_80102A44_2E1174_name_45(void);
void func_80102AB0_2E11E0_name_45(void);
void func_80102B54_2E1284_name_45(void);
s32 func_80102C3C_2E136C_name_45(s32 space);
void func_80102D28_2E1458_name_45(void);
void func_80102F4C_2E167C_name_45(UnkMBGuideData* guide);
void func_80102FFC_2E172C_name_45(void);
void func_80103548_2E1C78_name_45(void);
void func_80103968_2E2098_name_45(MBModel* parent);
void func_801039E4_2E2114_name_45(MBModel* parent);
void func_80103A64_2E2194_name_45(void);
void func_80103AF4_2E2224_name_45(void);
s32 func_80103B70_2E22A0_name_45(void);
void func_80103BC4_2E22F4_name_45(void);
void func_80103C94_2E23C4_name_45(void);
s32 func_80103CF4_2E2424_name_45(u8* items);
s32 func_80103FB0_2E26E0_name_45(void); /* the chosen option */
s32 func_801041D4_2E2904_name_45(void); /* the chosen option */
void func_80104380_2E2AB0_name_45(void);
s32 func_801045C0_2E2CF0_name_45(void);
void func_80104778_2E2EA8_name_45(void);
void func_80104F7C_2E36AC_name_45(void);
s32 func_8010537C_2E3AAC_name_45(u8* items);
s32 func_80105630_2E3D60_name_45(s32 arg0, u8* items);
void func_801059C4_2E40F4_name_45(void);
void func_80105D0C_2E443C_name_45(void);
void func_80105D38_2E4468_name_45(s16 arg0);
void func_80105EC4_2E45F4_name_45(void);
void func_80105FAC_2E46DC_name_45(void);
void func_80106174_2E48A4_name_45(void);
void func_80106270_2E49A0_name_45(s16 arg0);
void func_801063DC_2E4B0C_name_45(void);
void func_80106444_2E4B74_name_45(s16 arg0);
void func_80106600_2E4D30_name_45(void);
void func_8010665C_2E4D8C_name_45(s32 arg0);
void func_80106700_2E4E30_name_45(s32 arg0);
void func_8010676C_2E4E9C_name_45(void);
void func_801067E4_2E4F14_name_45(void);
s32 func_80106C70_2E53A0_name_45(s32 arg0); /* the chosen option */
void func_80106EC8_2E55F8_name_45(void);
void func_801072D8_2E5A08_name_45(void);
void func_801078E0_2E6010_name_45(void);
void func_80107AE0_2E6210_name_45(void); /* star / bank space */
void func_80108320_2E6A50_name_45(void);
s32 func_80108754_2E6E84_name_45(s32 arg0);
s32 func_801087C0_2E6EF0_name_45(void);
void func_8010880C_2E6F3C_name_45(void);
void func_80108E18_2E7548_name_45(MBModel* model);
void func_80108EB8_2E75E8_name_45(MBModel* model);
s32 func_80108F58_2E7688_name_45(s32 player);
void func_80109834_2E7F64_name_45(void);
s32 func_80109858_2E7F88_name_45(s32 player);
void func_8010A594_2E8CC4_name_45(void);
void func_8010A724_2E8E54_name_45(void);
omObjData* func_8010B15C_2E988C_name_45(Vec* pos, f32 scaleSpeed, f32 fadeSpeed, s16 kill, Vec* vel);
void func_8010B29C_2E99CC_name_45(omObjData* obj);
void func_8010B3B4_2E9AE4_name_45(void);
void func_8010B750_2E9E80_name_45(void);
void func_8010B7C0_2E9EF0_name_45(void);
void func_8010B9AC_2EA0DC_name_45(void);
Process* func_8010BBF8_2EA328_name_45(s16 sprite, s16 x0, s16 y0, s16 x1, s16 y1, s16 frames);
void func_8010BCA4_2EA3D4_name_45(void);
void func_8010C054_2EA784_name_45(void);
void func_8010C3A0_2EAAD0_name_45(void);
void func_8010C6CC_2EADFC_name_45(void);
void func_8010CB30_2EB260_name_45(void);
void func_8010D0A8_2EB7D8_name_45(void);
void func_8010D318_2EBA48_name_45(void);
void func_8010D54C_2EBC7C_name_45(void);
void func_8010D860_2EBF90_name_45(void);
void func_8010DED4_2EC604_name_45(void);
void func_8010E108_2EC838_name_45(void);
void func_8010E618_2ECD48_name_45(void);
void func_80110690_2EEDC0_name_45(void);
s32 func_801106E4_2EEE14_name_45(void); /* fork D: returns the use-item answer */
s32 func_80110908_2EF038_name_45(void);
s32 func_80110C84_2EF3B4_name_45(void);

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

extern DecisionTreeNonLeafNode D_80111068_2EF798_name_45[];
extern DecisionTreeNonLeafNode D_80111110_2EF840_name_45[];
extern DecisionTreeNonLeafNode D_80111374_2EFAA4_name_45[];
extern s16 D_80111440_2EFB70_name_45[];
extern DecisionTreeNonLeafNode D_80111484_2EFBB4_name_45[];
extern s16 D_801114C4_2EFBF4_name_45[];
extern u8 D_801115D4_2EFD04_name_45[]; /* by rank */
extern u8 D_801115F8_2EFD28_name_45[][4]; /* shop by turn band, rank */
extern u8 D_80111604_2EFD34_name_45[][3]; /* turn band starts by game length */
extern s8 D_80111610_2EFD40_name_45[][5]; /* shop items, -1 none */
extern u32 D_80111634_2EFD64_name_45[]; /* shop messages */
extern s32 D_801130C4_2F17F4_name_45;
extern u8* D_801130C8_2F17F8_name_45;

/* ---- 45: other data and main-segment API ---- */
extern s16 D_800F8CE4_F98E4[]; /* board state halfwords */
extern void* D_80110F4C_2EF67C_name_45; /* a loaded data file */
extern s16 D_80110F50_2EF680_name_45; /* a sprite, -1 when none */
void func_8003E964_3F564(s16);

/* ---- 45: data that is a second copy of a 3E symbol (45 has more instances of some objects) ---- */
extern DecisionTreeNonLeafNode D_80110F9C_2EF6CC_name_45[]; /* as 3E D_80111C3C_2A6F0C_name_3E */
extern DecisionTreeNonLeafNode D_801110E0_2EF810_name_45[]; /* as 3E D_80111C3C_2A6F0C_name_3E */
extern DecisionTreeNonLeafNode D_8011117C_2EF8AC_name_45[]; /* as 3E D_80111C3C_2A6F0C_name_3E */
extern DecisionTreeNonLeafNode D_80111398_2EFAC8_name_45[]; /* as 3E D_80111F84_2A7254_name_3E */
extern DecisionTreeNonLeafNode D_801113D4_2EFB04_name_45[]; /* as 3E D_80111F84_2A7254_name_3E */
extern DecisionTreeNonLeafNode D_80111404_2EFB34_name_45[]; /* as 3E D_80111F84_2A7254_name_3E */
extern MBModel* D_8011304C_2F177C_name_45; /* as 3E D_8011371C_2A89EC_name_3E */
extern MBModel* D_80113050_2F1780_name_45[7]; /* as 3E D_80113720_2A89F0_name_3E */
extern u8 D_80111660_2EFD90_name_45[4][3]; /* as 3E D_80112330: per player, the other players */
extern Unk3EStealRange D_80111704_2EFE34_name_45[24]; /* as 3E D_801123D4 */
extern s16 D_8011176E_2EFE9E_name_45[]; /* as 3E D_8011243E */
extern DecisionTreeNonLeafNode D_80111964_2F0094_name_45[]; /* 8010F680: CPU choice, arg0 == 0 */
extern DecisionTreeNonLeafNode D_801119A0_2F00D0_name_45[]; /* 8010F680: CPU choice, arg0 != 0 */
extern MBModel* D_801130B4_2F17E4_name_45; /* as 3E D_8011371C_2A89EC_name_3E (second set) */
extern MBModel* D_801130B8_2F17E8_name_45[2]; /* as 3E D_80113720_2A89F0_name_3E (second set) */
extern MBModel* D_8011306C_2F179C_name_45; /* as 3E D_8011373C_2A8A0C_name_3E */
extern MBModel* D_80113070_2F17A0_name_45[2]; /* as 3E D_80113740_2A8A10_name_3E */
extern s16 D_80110E04_2EF534_name_45[8]; /* as 3E D_80111A54_2A6D24_name_3E */
extern s16 D_80111428_2EFB58_name_45[]; /* as 3E D_801120E0_2A73B0_name_3E */
extern s16 D_801114AC_2EFBDC_name_45[]; /* as 3E D_801120E0_2A73B0_name_3E */
extern s16 D_801114DC_2EFC0C_name_45[]; /* as 3E D_801120E0_2A73B0_name_3E */

/* ---- 45: functions whose twin is shared with another 45 function, a main-segment twin, or none
   (void(void) when unknown; 45-B fixes its own) ---- */
void func_801058A4_2E3FD4_name_45(void);
void func_801058E0_2E4010_name_45(void); /* 45-B */
void func_80105CA4_2E43D4_name_45(void); /* 45-B */
void func_80105E3C_2E456C_name_45(void);
void func_80105FF4_2E4724_name_45(s16 arg0);
void func_80106114_2E4844_name_45(void);
void func_801065A0_2E4CD0_name_45(void);
void func_80106820_2E4F50_name_45(s16 arg0); /* 45-B: from its caller */
void func_80106954_2E5084_name_45(void);
void func_801069D8_2E5108_name_45(void); /* 45-B */
void func_80106A18_2E5148_name_45(void); /* twin func_8005FA50_60650: no prototype found */
void func_80106A74_2E51A4_name_45(void); /* 45-B */
void func_80106B58_2E5288_name_45(void);
void func_801071C0_2E58F0_name_45(void);
void func_801075D0_2E5D00_name_45(void);
void func_801076E8_2E5E18_name_45(void);
void func_8010770C_2E5E3C_name_45(void);
void func_80107730_2E5E60_name_45(void);
void func_80107754_2E5E84_name_45(void);
void func_80107778_2E5EA8_name_45(void);
void func_8010779C_2E5ECC_name_45(void);
void func_801077C0_2E5EF0_name_45(void);
void func_801077E4_2E5F14_name_45(void);
void func_80107808_2E5F38_name_45(void);
void func_8010782C_2E5F5C_name_45(void);
void func_80107850_2E5F80_name_45(void);
void func_80107874_2E5FA4_name_45(void);
void func_80107898_2E5FC8_name_45(void);
void func_801078BC_2E5FEC_name_45(void);
Process* func_8010A6E8_2E8E18_name_45(void* arg0);
void func_8010B124_2E9854_name_45(void);
void func_8010B140_2E9870_name_45(void);
void func_8010E828_2ECF58_name_45(void); /* 45-B */
void func_8010E9D0_2ED100_name_45(void); /* 45-B */
void func_8010EA40_2ED170_name_45(void); /* 45-B */
s32 func_8010F680_2EDDB0_name_45(s32 arg0);
void func_8010F8E0_2EE010_name_45(void); /* 45-B */
void func_8010FBD8_2EE308_name_45(void); /* 45-B */
void func_8010FDCC_2EE4FC_name_45(s32 arg0);
void func_8010FE08_2EE538_name_45(void); /* 45-B */
void func_8011012C_2EE85C_name_45(s32 arg0); /* 45-B: from its callers */
void func_80110658_2EED88_name_45(void);
void func_80110674_2EEDA4_name_45(void);

#endif
