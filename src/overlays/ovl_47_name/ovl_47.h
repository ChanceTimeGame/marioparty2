#ifndef _OVL_47_H
#define _OVL_47_H

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

#include "game/window.h" /* D_800F920C_F9E0C */
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
s16 PlayMusic(s16);
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

extern s16 D_80110980_305280_name_47[8]; /* star positions, shuffled */
extern s16 D_80110990_305290_name_47[8]; /* each position's earliest slot */
extern s16 D_801109A0_3052A0_name_47[]; /* positions not to show first, -1 ended */
extern s16 D_801109A4_3052A4_name_47[8]; /* star position board flags */
extern s16 D_801109B4_3052B4_name_47[8]; /* star spaces */
extern s16 D_801109C4_3052C4_name_47[8]; /* star camera spaces */
extern s32 D_801109D4_3052D4_name_47; /* guide motions */
extern s32 D_801109D8_3052D8_name_47;
extern f32 D_801109DC_3052DC_name_47[9]; /* per board */
extern s32 D_80110A00_305300_name_47;
extern u8 D_80110A04_305304_name_47[3][4]; /* steal-a-star chance by turn band, coin band */
extern s16 D_80110A2C_30532C_name_47[7][2]; /* star space marker offsets */
extern s16 D_80110A48_305348_name_47[2][2];
extern s16 D_80110A4C_30534C_name_47[2][2];
extern s16 D_80110A54_305354_name_47[2];
extern s16 D_80110A58_305358_name_47[2][2]; /* signpost marker offsets */
extern s16 D_80110A60_305360_name_47[2][2]; /* signpost facing: from, to spaces */
extern s16 D_80110A68_305368_name_47[8]; /* star spaces (markers) */
extern s16 D_80110A78_305378_name_47[8]; /* their flags */
extern s32 D_80110A88_305388_name_47; /* marker id, -1 none */
extern s16 D_80110A8C_30538C_name_47[2];
extern s16 D_80110A90_305390_name_47[2]; /* bank spaces */
extern Vec D_80110A94_305394_name_47[5]; /* bank coin offsets */
extern Vec D_80110AD0_3053D0_name_47[5]; /* bank coin rotations (x, z used) */
extern s16 D_80110B0C_30540C_name_47[2]; /* signpost spaces */
extern u8 D_80110B11_305411_name_47[]; /* signpost model per board, at [board * 2] */
extern s32 D_80110B1C_30541C_name_47[9]; /* per board: sound, -1 none (played as s16) */
extern s32 D_80110B40_305440_name_47[9]; /* per board: sound, -1 none (played as s16) */
extern s32 D_80110B64_305464_name_47[9]; /* per board: delay */
extern s32 D_80110B88_305488_name_47[9]; /* per board: sound, -1 none (played as s16) */
extern s16 D_80110BAC_3054AC_name_47[2];
extern s16 D_80110BB0_3054B0_name_47;

/* 3E's rodata (0x2A8860-0x2A89A0, carved by the coordinator) */
extern const u8 D_80112170_306A70_name_47[4]; /* {1, 2, 4, 8}: window choice masks per pad; read by 6 functions */

/* ---- 3E bss (asm/data/overlays/ovl_3E_name/ovl_3E_bss.bss.s) ---- */

extern Process* D_801122A0_306BA0_name_47; /* star appear process */
extern s32 D_801122A4_306BA4_name_47; /* star process: 1 = take a star away */
extern s32 D_801122A8_306BA8_name_47; /* help windows */
extern s32 D_801122AC_306BAC_name_47;
extern s32 D_801122B0_306BB0_name_47;
extern s32 D_801122B4_306BB4_name_47;
extern s32 D_801122B8_306BB8_name_47;
extern s32 D_801122C0_306BC0_name_47[4]; /* the other players, by rank */
extern s32 D_801122D0_306BD0_name_47[4]; /* players other than the current one, by coins */
extern s32 D_801122E0_306BE0_name_47; /* what can be stolen: 0 coins, 1 a star, 2 nothing */
extern s32 D_801122E4_306BE4_name_47; /* the player Boo steals from */
extern s32 D_801122E8_306BE8_name_47; /* Boo's choice: a player slot, or 0/1/2 */
extern MBModel* D_801122EC_306BEC_name_47;
extern MBModel* D_801122F0_306BF0_name_47[7];
extern MBModel* D_80112314_306C14_name_47;
extern MBModel* D_80112318_306C18_name_47[10]; /* bank coins */
extern MBModel* D_8011230C_306C0C_name_47;
extern MBModel* D_80112310_306C10_name_47[1];
extern MBModel* D_80112340_306C40_name_47;
extern MBModel* D_80112344_306C44_name_47[2]; /* signposts */

extern Vec2f3E D_80111008_305908_name_47[4];
extern Vec2f3E D_80111028_305928_name_47[4]; /* per player: window positions (item events) */
extern Vec2f3E D_80111048_305948_name_47[4];
extern Vec2f3E D_80111068_305968_name_47[4];
extern s32 D_80111088_305988_name_47[6]; /* per board: message */
s32 func_80060210_60E10(s32);
s32 func_800609D8_615D8(void); /* status windows still moving */
void MBStatusItemDispSetAll(s32);
extern s16 D_801110A0_3059A0_name_47[6]; /* per board: message window */
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
extern s32 D_80111200_305B00_name_47[]; /* decision tree */
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
extern f32 D_80111850_306150_name_47[4]; /* scissor box {0, 0, 320, 240} */
extern s32 D_80111C50_306550_name_47[]; /* decision trees (CPU item use) */
extern s32 D_80111CB0_3065B0_name_47[];
extern s32 D_80111E18_306718_name_47[];
extern s32 D_80111F50_306850_name_47[];
s16 GetCurrentPlayerIndex(void);
s16 RNGPercentChance(s8 arg0);
extern u8 D_800CC000[]; /* item prices */
extern s32 D_80111FB0_3068B0_name_47[]; /* decision trees (CPU shop) */
extern s32 D_80111FC8_3068C8_name_47[];
extern s32 D_80112070_306970_name_47[]; /* decision tree (CPU yes/no) */
extern s32 D_801120A0_3069A0_name_47; /* set: the CPU's next answer is option 2 */
extern u8* D_801120EC_3069EC_name_47[]; /* per character: items the CPU tries to buy */
extern s8* D_8011214C_306A4C_name_47[]; /* per character: their percent chances */
extern u8 D_80112164_306A64_name_47[]; /* per character: list length */
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
extern MBModel* D_80112378_306C78_name_47;
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

extern s32 D_80110E88_305788_name_47[6]; /* per character: sprite file */
extern Unk3EVec2f D_80110E48_305748_name_47[4]; /* per player: lost star start */
extern Unk3EVec2f D_80110E68_305768_name_47[4]; /* per player: lost star velocity */
f32 __sinf(f32);
extern Unk3ERange D_80110EA0_3057A0_name_47[6]; /* turn range -> star price */
extern Unk3ERange D_80110EB4_3057B4_name_47[14]; /* press count range -> discount */
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

s16 func_80102830_2F7130_name_47(void);
void func_8010285C_2F715C_name_47(void);
void func_80102A44_2F7344_name_47(void);
void func_80102AB0_2F73B0_name_47(void);
void func_80102B54_2F7454_name_47(void);
s32 func_80102C3C_2F753C_name_47(s32 space);
void func_80102D28_2F7628_name_47(void);
void func_80102F4C_2F784C_name_47(UnkMBGuideData* guide);
void func_80102FFC_2F78FC_name_47(void);
void func_80103548_2F7E48_name_47(void);
void func_80103968_2F8268_name_47(MBModel* parent);
void func_801039E4_2F82E4_name_47(MBModel* parent);
void func_80103A64_2F8364_name_47(void);
void func_80103AF4_2F83F4_name_47(void);
s32 func_80103B70_2F8470_name_47(void);
void func_80103BC4_2F84C4_name_47(void);
void func_80103C94_2F8594_name_47(void);
s32 func_80103CF4_2F85F4_name_47(u8* items);
s32 func_80103FB0_2F88B0_name_47(void); /* the chosen option */
s32 func_801041D4_2F8AD4_name_47(void); /* the chosen option */
void func_80104380_2F8C80_name_47(void);
s32 func_801045C0_2F8EC0_name_47(void);
void func_80104778_2F9078_name_47(void);
void func_80104F7C_2F987C_name_47(void);
s32 func_8010537C_2F9C7C_name_47(u8* items);
s32 func_80105630_2F9F30_name_47(s32 arg0, u8* items);
void func_80105984_2FA284_name_47(void);
void func_80105CBC_2FA5BC_name_47(void);
void func_80105CE8_2FA5E8_name_47(s16 arg0);
void func_80105DEC_2FA6EC_name_47(void);
void func_80105E74_2FA774_name_47(void);
void func_80105F5C_2FA85C_name_47(void);
void func_801063F0_2FACF0_name_47(s16 arg0);
void func_8010654C_2FAE4C_name_47(void);
void func_80106120_2FAA20_name_47(void);
void func_8010621C_2FAB1C_name_47(s16 arg0);
void func_80106388_2FAC88_name_47(void);
void func_801065AC_2FAEAC_name_47(void);
void func_80106608_2FAF08_name_47(s32 arg0);
void func_801066AC_2FAFAC_name_47(s32 arg0);
void func_80106718_2FB018_name_47(void);
void func_80106790_2FB090_name_47(void);
void func_801074B0_2FBDB0_name_47(void);
s32 func_80106C60_2FB560_name_47(s32 arg0); /* the chosen option */
void func_80106EC0_2FB7C0_name_47(void);
void func_801071B8_2FBAB8_name_47(void);
void func_80107730_2FC030_name_47(void);
void func_80107930_2FC230_name_47(void); /* star / bank space */
void func_80108170_2FCA70_name_47(void);
s32 func_8010859C_2FCE9C_name_47(s32 arg0);
s32 func_80108608_2FCF08_name_47(void);
void func_80108654_2FCF54_name_47(void);
void func_80108C60_2FD560_name_47(MBModel* model);
void func_80108D00_2FD600_name_47(MBModel* model);
s32 func_80108DA0_2FD6A0_name_47(s32 player);
void func_8010967C_2FDF7C_name_47(void);
s32 func_801096A0_2FDFA0_name_47(s32 player);
void func_8010A3DC_2FECDC_name_47(void);
void func_8010A56C_2FEE6C_name_47(void);
omObjData* func_8010AF80_2FF880_name_47(Vec* pos, f32 scaleSpeed, f32 fadeSpeed, s16 kill, Vec* vel);
void func_8010B0C0_2FF9C0_name_47(omObjData* obj);
void func_8010B1D8_2FFAD8_name_47(void);
void func_8010B574_2FFE74_name_47(void);
void func_8010B5E4_2FFEE4_name_47(void);
void func_8010B7D0_3000D0_name_47(void);
Process* func_8010BA1C_30031C_name_47(s16 sprite, s16 x0, s16 y0, s16 x1, s16 y1, s16 frames);
void func_8010BAC8_3003C8_name_47(void);
void func_8010BE78_300778_name_47(void);
void func_8010C1C4_300AC4_name_47(void);
void func_8010C4F0_300DF0_name_47(void);
void func_8010C954_301254_name_47(void);
void func_8010CECC_3017CC_name_47(void);
void func_8010D13C_301A3C_name_47(void);
void func_8010D370_301C70_name_47(void);
void func_8010D684_301F84_name_47(void);
void func_8010DCF8_3025F8_name_47(void);
void func_8010DF2C_30282C_name_47(void);
void func_8010E43C_302D3C_name_47(void);
s32 func_8010EB20_303420_name_47(void);
void func_80110310_304C10_name_47(void);
s32 func_80110364_304C64_name_47(void); /* fork D: returns the use-item answer */
s32 func_80110588_304E88_name_47(void);
s32 func_80110904_305204_name_47(void);
extern omObjData* D_80112360_306C60_name_47[4]; /* 47-A: objects deleted by func_80106844 (fork B: their use) */
extern DecisionTreeNonLeafNode D_80110CA0_3055A0_name_47[]; /* 47-A: CPU choice trees, by func_80106C60's arg0 */
extern DecisionTreeNonLeafNode D_80110CB8_3055B8_name_47[];
extern DecisionTreeNonLeafNode D_801116DC_305FDC_name_47[]; /* the same for func_8010F6B0 */
extern DecisionTreeNonLeafNode D_801116F4_305FF4_name_47[];
extern s16 D_80110A10_305310_name_47[6]; /* 47-A: -1 ended space lists for func_80105984 (41: D_80110AF0) */
extern s16 D_80110A1C_30531C_name_47[]; /* -1 ended */
void MBMasuArrowAngleAdd(f32); /* 47-A: as ovl_41.h (unprototyped it passes a double) */
extern u8 D_80110E3C_30573C_name_47[4][3]; /* 47-A: per player: the other players (3E: D_80112330) */
extern Unk3EStealRange D_80110EE0_3057E0_name_47[24]; /* turn and coin range -> message */
extern s16 D_80110F4A_30584A_name_47[];
/* 47-A: the rest (fork B's own functions are void(void) unless a caller shows more) */
void func_801058A4_2FA1A4_name_47(void);
void func_801058E0_2FA1E0_name_47(void);
void func_80105C5C_2FA55C_name_47(void);
void func_80105FA4_2FA8A4_name_47(s16 arg0);
void func_801060C4_2FA9C4_name_47(void);
void func_801067CC_2FB0CC_name_47(s32 arg0);
void func_80106844_2FB144_name_47(void);
void func_801068A8_2FB1A8_name_47(omObjData* obj);
void func_80106A6C_2FB36C_name_47(s32 arg0);
void func_80106B44_2FB444_name_47(s32 arg0);
void func_80106BBC_2FB4BC_name_47(void);
void func_801075C8_2FBEC8_name_47(void);
void func_801075EC_2FBEEC_name_47(void);
void func_80107610_2FBF10_name_47(void);
void func_80107634_2FBF34_name_47(void);
void func_80107658_2FBF58_name_47(void);
void func_8010767C_2FBF7C_name_47(void);
void func_801076A0_2FBFA0_name_47(void);
void func_801076C4_2FBFC4_name_47(void);
void func_801076E8_2FBFE8_name_47(void);
void func_8010770C_2FC00C_name_47(void);
Process* func_8010A530_2FEE30_name_47(void* arg0);
void func_8010AF48_2FF848_name_47(void);
void func_8010AF64_2FF864_name_47(void);
void func_8010E64C_302F4C_name_47(void);
void func_8010E738_303038_name_47(s32 arg0);
void func_8010EA94_303394_name_47(void);
void func_8010EAB0_3033B0_name_47(void);
void func_8010EACC_3033CC_name_47(void);
void func_8010EAE8_3033E8_name_47(void);
void func_8010EB04_303404_name_47(void);
s32 func_8010ED54_303654_name_47(void); /* 47-A: a count (func_8010EE00 adds 1) */
s32 func_8010EE00_303700_name_47(u8* items);
void func_8010F098_303998_name_47(void);
s32 func_8010F6B0_303FB0_name_47(s32 arg0); /* the chosen option */
void func_8010F910_304210_name_47(void);

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

extern DecisionTreeNonLeafNode D_80110C74_305574_name_47[];
extern DecisionTreeNonLeafNode D_80110BF0_3054F0_name_47[];
extern DecisionTreeNonLeafNode D_80110C50_305550_name_47[];
extern DecisionTreeNonLeafNode D_80110C8C_30558C_name_47[];
extern DecisionTreeNonLeafNode D_80110C8C_30558C_name_47[];
extern s16 D_80110CF8_3055F8_name_47[]; /* direction prompt choices */
extern s16 D_80110C98_305598_name_47[];
extern s16 D_80110CE0_3055E0_name_47[];
extern u8 D_80110DB0_3056B0_name_47[]; /* by rank */
extern u8 D_80110DD4_3056D4_name_47[][4]; /* shop by turn band, rank */
extern u8 D_80110DE0_3056E0_name_47[][3]; /* turn band starts by game length */
extern s8 D_80110DEC_3056EC_name_47[][5]; /* shop items, -1 none */
extern u32 D_80110E10_305710_name_47[]; /* shop messages */
extern s32 D_80112370_306C70_name_47;
extern u8* D_80112374_306C74_name_47;

/* 47-B */
extern BoardEventTableEntry D_80110F90_305890_name_47[];
extern BoardEventTableEntry D_80110FF8_3058F8_name_47[];
extern BoardEventTableEntry D_80111728_306028_name_47[];
extern MBModel* D_80112350_306C50_name_47[4]; /* per player: the model each D_80112360 object carries */
void func_800632E4_63EE4(void (*arg0)(void));
extern s16 D_801110BC_3059BC_name_47[4]; /* warp destination: current space */
extern s16 D_801110C4_3059C4_name_47[4]; /* warp destination: next space */
extern DecisionTreeNonLeafNode* D_801116BC_305FBC_name_47[4]; /* per player: CPU decision tree */
void func_80049FA0_4ABA0(void);
void func_800517C0_523C0(void);
void func_80051788_52388(void);
void func_800514F0_520F0(void);
f32 MBCameraSpeedGet(void);
f32 func_80053614_54214(void);
void func_8005660C_5720C(s16 arg0, s16 arg1); /* MBPlayerPosMasuSet */
extern s16 D_8011170C_30600C_name_47[2]; /* the launcher's facing: from space [1] toward [0] */
extern s16 D_80111710_306010_name_47[2]; /* per side: launch space */
extern s16 D_80111714_306014_name_47[2]; /* per side: landing chain space */

#endif
