#ifndef _OVL_43_H
#define _OVL_43_H

/* Board overlay 43 (2C7CF0.c), generated from ovl_3E.h by mp2twincopy.py header. Notes below are 3E's.
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

extern s16 D_80113AD0_2D8FC0_name_43[8]; /* star positions, shuffled */
extern s16 D_80113AE0_2D8FD0_name_43[8]; /* each position's earliest slot */
extern s16 D_80113AF0_2D8FE0_name_43[]; /* positions not to show first, -1 ended */
extern s16 D_80113AF8_2D8FE8_name_43[8]; /* star position board flags */
extern s16 D_80113B08_2D8FF8_name_43[8]; /* star spaces */
extern s16 D_80113B18_2D9008_name_43[8]; /* star camera spaces */
extern s32 D_80113B28_2D9018_name_43; /* guide motions */
extern s32 D_80113B2C_2D901C_name_43;
extern f32 D_80113B30_2D9020_name_43[9]; /* per board */
extern s32 D_80113B54_2D9044_name_43;
extern u8 D_80113B58_2D9048_name_43[3][4]; /* steal-a-star chance by turn band, coin band */
extern s16 D_80113B88_2D9078_name_43[7][2]; /* star space marker offsets */
extern s16 D_80113BB4_2D90A4_name_43[2][2];
extern s16 D_80113BBC_2D90AC_name_43[2];
extern s16 D_80113BC0_2D90B0_name_43[2][2]; /* signpost marker offsets */
extern s16 D_80113BC8_2D90B8_name_43[2][2]; /* signpost facing: from, to spaces */
extern s16 D_80113BD0_2D90C0_name_43[8]; /* star spaces (markers) */
extern s16 D_80113BE0_2D90D0_name_43[8]; /* their flags */
extern s32 D_80113BF0_2D90E0_name_43; /* marker id, -1 none */
extern s16 D_80113BF4_2D90E4_name_43[2]; /* bank spaces */
extern Vec D_80113BF8_2D90E8_name_43[5]; /* bank coin offsets */
extern Vec D_80113C34_2D9124_name_43[5]; /* bank coin rotations (x, z used) */
extern s16 D_80113C70_2D9160_name_43[2]; /* signpost spaces */
extern u8 D_80113C75_2D9165_name_43[]; /* signpost model per board, at [board * 2] */
extern s32 D_80113C80_2D9170_name_43[9]; /* per board: sound, -1 none (played as s16) */
extern s32 D_80113CA4_2D9194_name_43[9]; /* per board: sound, -1 none (played as s16) */
extern s32 D_80113CC8_2D91B8_name_43[9]; /* per board: delay */
extern s32 D_80113CEC_2D91DC_name_43[9]; /* per board: sound, -1 none (played as s16) */
extern s16 D_80113D10_2D9200_name_43[2];
extern s16 D_80113D14_2D9204_name_43;

/* 3E's rodata (0x2A8860-0x2A89A0, carved by the coordinator) */
extern const u8 D_80115280_2DA770_name_43[4]; /* {1, 2, 4, 8}: window choice masks per pad; read by 6 functions */

/* ---- 3E bss (asm/data/overlays/ovl_3E_name/ovl_3E_bss.bss.s) ---- */

extern Process* D_801153C0_2DA8B0_name_43; /* star appear process */
extern s32 D_801153C4_2DA8B4_name_43; /* star process: 1 = take a star away */
extern s32 D_801153C8_2DA8B8_name_43; /* help windows */
extern s32 D_801153CC_2DA8BC_name_43;
extern s32 D_801153D0_2DA8C0_name_43;
extern s32 D_801153D4_2DA8C4_name_43;
extern s32 D_801153D8_2DA8C8_name_43;
extern s32 D_801153E0_2DA8D0_name_43[4]; /* the other players, by rank */
extern s32 D_801153F0_2DA8E0_name_43[4]; /* players other than the current one, by coins */
extern s32 D_80115400_2DA8F0_name_43; /* what can be stolen: 0 coins, 1 a star, 2 nothing */
extern s32 D_80115404_2DA8F4_name_43; /* the player Boo steals from */
extern s32 D_80115408_2DA8F8_name_43; /* Boo's choice: a player slot, or 0/1/2 */
extern MBModel* D_8011540C_2DA8FC_name_43;
extern MBModel* D_80115410_2DA900_name_43[7];
extern MBModel* D_8011542C_2DA91C_name_43;
extern MBModel* D_80115430_2DA920_name_43[10]; /* bank coins */
extern MBModel* D_80115458_2DA948_name_43;
extern MBModel* D_8011545C_2DA94C_name_43[2]; /* signposts */

extern Vec2f3E D_80114344_2D9834_name_43[4];
extern Vec2f3E D_80114364_2D9854_name_43[4]; /* per player: window positions (item events) */
extern Vec2f3E D_80114384_2D9874_name_43[4];
extern Vec2f3E D_801143A4_2D9894_name_43[4];
extern s32 D_801143C4_2D98B4_name_43[6]; /* per board: message */
s32 func_80060210_60E10(s32);
s32 func_800609D8_615D8(void); /* status windows still moving */
void MBStatusItemDispSetAll(s32);
extern s16 D_801143DC_2D98CC_name_43[6]; /* per board: message window */
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
extern f32 D_801147E4_2D9CD4_name_43[4]; /* scissor box {0, 0, 320, 240} */
extern s32 D_80114CA4_2DA194_name_43[]; /* decision trees (CPU item use) */
extern s32 D_80114D04_2DA1F4_name_43[];
extern s32 D_80114F44_2DA434_name_43[];
extern s32 D_801150B8_2DA5A8_name_43[];
s16 GetCurrentPlayerIndex(void);
s16 RNGPercentChance(s8 arg0);
extern u8 D_800CC000[]; /* item prices */
extern s32 D_80115118_2DA608_name_43[]; /* decision trees (CPU shop) */
extern s32 D_80115124_2DA614_name_43[];
extern s32 D_80115190_2DA680_name_43[]; /* decision tree (CPU yes/no) */
extern s32 D_801151B4_2DA6A4_name_43; /* set: the CPU's next answer is option 2 */
extern u8* D_80115200_2DA6F0_name_43[]; /* per character: items the CPU tries to buy */
extern s8* D_80115260_2DA750_name_43[]; /* per character: their percent chances */
extern u8 D_80115278_2DA768_name_43[]; /* per character: list length */
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
extern MBModel* D_80115488_2DA978_name_43;
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

extern s32 D_801141E4_2D96D4_name_43[6]; /* per character: sprite file */
extern Unk3EVec2f D_801141A4_2D9694_name_43[4]; /* per player: lost star start */
extern Unk3EVec2f D_801141C4_2D96B4_name_43[4]; /* per player: lost star velocity */
f32 __sinf(f32);
extern Unk3ERange D_801141FC_2D96EC_name_43[6]; /* turn range -> star price */
extern Unk3ERange D_80114210_2D9700_name_43[14]; /* press count range -> discount */
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


/* ---- 2C7CF0.c (all 135 functions; twins copied from 3E/41/main, the rest void(void) until fork B) ---- */

s16 func_80102830_2C7D20_name_43(void);
void func_8010285C_2C7D4C_name_43(void);
void func_80102A44_2C7F34_name_43(void);
void func_80102AB0_2C7FA0_name_43(void);
void func_80102B54_2C8044_name_43(void);
s32 func_80102C3C_2C812C_name_43(s32 space);
void func_80102D28_2C8218_name_43(void);
void func_80102F4C_2C843C_name_43(UnkMBGuideData* guide);
void func_80102FFC_2C84EC_name_43(void);
void func_80103548_2C8A38_name_43(void);
void func_80103968_2C8E58_name_43(MBModel* parent);
void func_801039E4_2C8ED4_name_43(MBModel* parent);
void func_80103A64_2C8F54_name_43(void);
void func_80103D48_2C9238_name_43(MBModel* parent);
void func_80103DB0_2C92A0_name_43(void);
void func_80103E40_2C9330_name_43(void);
s32 func_80103EBC_2C93AC_name_43(void);
void func_80103F10_2C9400_name_43(void);
void func_80103FE0_2C94D0_name_43(void);
s32 func_80104040_2C9530_name_43(u8* items);
s32 func_801042FC_2C97EC_name_43(void); /* the chosen option */
s32 func_80104520_2C9A10_name_43(void); /* the chosen option */
void func_801046CC_2C9BBC_name_43(void);
s32 func_8010490C_2C9DFC_name_43(void);
void func_80104AC4_2C9FB4_name_43(void);
void func_801052C8_2CA7B8_name_43(void);
s32 func_801056C8_2CABB8_name_43(u8* items);
s32 func_8010597C_2CAE6C_name_43(s32 arg0, u8* items);
void func_80105BF0_2CB0E0_name_43(void);
void func_80105C2C_2CB11C_name_43(void);
void func_80105D18_2CB208_name_43(void);
void func_80106004_2CB4F4_name_43(void);
void func_801060C8_2CB5B8_name_43(void);
void func_801060F4_2CB5E4_name_43(s16 arg0);
void func_801061F8_2CB6E8_name_43(void);
void func_80106280_2CB770_name_43(void);
void func_80106368_2CB858_name_43(void);
void func_801063B0_2CB8A0_name_43(void);
void func_801064AC_2CB99C_name_43(s16 arg0);
void func_80106618_2CBB08_name_43(void);
void func_80106680_2CBB70_name_43(s16 arg0);
void func_801067DC_2CBCCC_name_43(void);
void func_8010683C_2CBD2C_name_43(void);
void func_80106898_2CBD88_name_43(s32 arg0);
void func_8010693C_2CBE2C_name_43(s32 arg0);
void func_801069A8_2CBE98_name_43(void);
void func_80106A20_2CBF10_name_43(void);
void func_80106A5C_2CBF4C_name_43(s16 arg0);
void func_80106BEC_2CC0DC_name_43(void);
void func_80106C4C_2CC13C_name_43(s16 arg0);
void func_80106DD8_2CC2C8_name_43(void);
void func_80106E38_2CC328_name_43(void);
void func_80106F50_2CC440_name_43(void);
s32 func_80107068_2CC558_name_43(s32 arg0); /* the chosen option */
void func_801072C0_2CC7B0_name_43(void);
void func_801075B8_2CCAA8_name_43(void);
void func_801078B0_2CCDA0_name_43(void);
void func_801078D4_2CCDC4_name_43(void);
void func_801078F8_2CCDE8_name_43(void);
void func_8010791C_2CCE0C_name_43(void);
void func_80107940_2CCE30_name_43(void);
void func_80107964_2CCE54_name_43(void);
void func_80107988_2CCE78_name_43(void);
void func_801079AC_2CCE9C_name_43(void);
void func_801079D0_2CCEC0_name_43(void);
void func_801079F4_2CCEE4_name_43(void);
void func_80107CFC_2CD1EC_name_43(void);
void func_80107EFC_2CD3EC_name_43(void); /* star / bank space */
void func_8010873C_2CDC2C_name_43(void);
s32 func_80108B70_2CE060_name_43(s32 arg0);
s32 func_80108BDC_2CE0CC_name_43(void);
void func_80108C28_2CE118_name_43(void);
void func_80109234_2CE724_name_43(MBModel* model);
void func_801092D4_2CE7C4_name_43(MBModel* model);
s32 func_80109374_2CE864_name_43(s32 player);
void func_80109C50_2CF140_name_43(void);
s32 func_80109C74_2CF164_name_43(s32 player);
void func_8010A9B0_2CFEA0_name_43(void);
void func_8010B868_2D0D58_name_43(void);
Process* func_8010B9BC_2D0EAC_name_43(void* arg0);
void func_8010B9F8_2D0EE8_name_43(void);
void func_8010BA14_2D0F04_name_43(void);
omObjData* func_8010BA30_2D0F20_name_43(Vec* pos, f32 scaleSpeed, f32 fadeSpeed, s16 kill, Vec* vel);
omObjData* func_8010BB70_2D1060_name_43(Vec* pos, f32 scaleSpeed, f32 fadeSpeed, s16 kill, Vec* vel);
void func_8010BCB0_2D11A0_name_43(omObjData* obj);
void func_8010BDC8_2D12B8_name_43(void);
void func_8010C164_2D1654_name_43(void);
void func_8010C1D4_2D16C4_name_43(void);
void func_8010C3C0_2D18B0_name_43(void);
Process* func_8010C60C_2D1AFC_name_43(s16 sprite, s16 x0, s16 y0, s16 x1, s16 y1, s16 frames);
void func_8010C6B8_2D1BA8_name_43(void);
void func_8010CA68_2D1F58_name_43(void);
void func_8010CDB4_2D22A4_name_43(void);
void func_8010D0E0_2D25D0_name_43(void);
void func_8010D544_2D2A34_name_43(void);
void func_8010DABC_2D2FAC_name_43(void);
void func_8010DD2C_2D321C_name_43(void);
void func_8010DF60_2D3450_name_43(void);
void func_8010E274_2D3764_name_43(void);
void func_8010E8E8_2D3DD8_name_43(void);
void func_8010EB1C_2D400C_name_43(void);
void func_8010F02C_2D451C_name_43(void);
void func_8010F23C_2D472C_name_43(void);
void func_8010F26C_2D475C_name_43(void);
void func_8010F2B4_2D47A4_name_43(void);
s32 func_8010F32C_2D481C_name_43(void);
s32 func_8010F548_2D4A38_name_43(s32 arg0); /* 43 (169B0 func_80016A44-like) */
void func_8010FAD0_2D4FC0_name_43(void);
void func_8010FAEC_2D4FDC_name_43(void);
void func_8010FB08_2D4FF8_name_43(void);
void func_8010FB24_2D5014_name_43(void);
s32 func_8010FD0C_2D51FC_name_43(s32 arg0);
void func_8010FD8C_2D527C_name_43(void);
void func_8010FDA8_2D5298_name_43(void);
void func_8010FDC4_2D52B4_name_43(void);
void func_8010FDE0_2D52D0_name_43(void);
void func_8011081C_2D5D0C_name_43(void);
void func_801109A4_2D5E94_name_43(void);
s32 func_80110CCC_2D61BC_name_43(s32 arg0);
s32 func_80110F2C_2D641C_name_43(s32 arg0);
void func_801114F0_2D69E0_name_43(void);
void func_8011150C_2D69FC_name_43(void);
void func_80111528_2D6A18_name_43(void);
s32 func_801115C0_2D6AB0_name_43(void);
void func_801117F4_2D6CE4_name_43(void);
void func_801119D4_2D6EC4_name_43(void);
void func_80112248_2D7738_name_43(void);
s32 func_8011228C_2D777C_name_43(void);
void func_801124C0_2D79B0_name_43(void);
s32 func_801128E0_2D7DD0_name_43(u8* items);
void func_80112C2C_2D811C_name_43(void);
void func_80113460_2D8950_name_43(void);
s32 func_801134B4_2D89A4_name_43(void); /* fork D: returns the use-item answer */
s32 func_801136D8_2D8BC8_name_43(void);
s32 func_80113A54_2D8F44_name_43(void);

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

extern DecisionTreeNonLeafNode D_80113E54_2D9344_name_43[];
extern DecisionTreeNonLeafNode D_80113E9C_2D938C_name_43[];
extern DecisionTreeNonLeafNode D_80113F20_2D9410_name_43[];
extern s16 D_80113FF8_2D94E8_name_43[];
extern DecisionTreeNonLeafNode D_80114030_2D9520_name_43[];
extern s16 D_80114064_2D9554_name_43[];
extern u8 D_8011410C_2D95FC_name_43[]; /* by rank */
extern u8 D_80114130_2D9620_name_43[][4]; /* shop by turn band, rank */
extern u8 D_8011413C_2D962C_name_43[][3]; /* turn band starts by game length */
extern s8 D_80114148_2D9638_name_43[][5]; /* shop items, -1 none */
extern u32 D_8011416C_2D965C_name_43[]; /* shop messages */
extern s32 D_80115480_2DA970_name_43;
extern u8* D_80115484_2DA974_name_43;

/* ---- 43-A: data the twins use that 3E's header names differently ---- */
extern MBModel* D_80115464_2DA954_name_43;
extern MBModel* D_80115468_2DA958_name_43[3]; /* 43: three */
extern MBModel* D_80115474_2DA964_name_43;
extern MBModel* D_80115478_2DA968_name_43[2];
extern DecisionTreeNonLeafNode D_80113D7C_2D926C_name_43[];
extern DecisionTreeNonLeafNode D_80113DC4_2D92B4_name_43[];
extern DecisionTreeNonLeafNode D_80113F2C_2D941C_name_43[];
extern DecisionTreeNonLeafNode D_80113F5C_2D944C_name_43[];
extern s16 D_80113FC8_2D94B8_name_43[]; /* direction prompt choices */
extern s16 D_80113FE0_2D94D0_name_43[]; /* direction prompt choices */
extern DecisionTreeNonLeafNode D_801145EC_2D9ADC_name_43[];
extern DecisionTreeNonLeafNode D_80114620_2D9B10_name_43[];

#endif
