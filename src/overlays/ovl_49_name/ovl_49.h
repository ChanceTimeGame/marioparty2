#ifndef _OVL_49_H
#define _OVL_49_H

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

extern s16 D_80112C20_31D0D0_name_49[8]; /* star positions, shuffled */
extern s16 D_80112C30_31D0E0_name_49[8]; /* each position's earliest slot */
extern s16 D_80112C40_31D0F0_name_49[]; /* positions not to show first, -1 ended */
extern s16 D_80112C48_31D0F8_name_49[8]; /* star position board flags */
extern s16 D_80112C58_31D108_name_49[8]; /* star spaces */
extern s16 D_80112C68_31D118_name_49[8]; /* star camera spaces */
extern s32 D_80112C78_31D128_name_49;
extern u8 D_80112C7C_31D12C_name_49[3][4]; /* steal-a-star chance by turn band, coin band */
extern s16 D_80112CAC_31D15C_name_49[7][2]; /* star space marker offsets */
extern s16 D_80112CC8_31D178_name_49[2][2];
extern s16 D_80112CD0_31D180_name_49[2];
extern s16 D_80112CD4_31D184_name_49[2][2]; /* signpost marker offsets */
extern s16 D_80112CEC_31D19C_name_49[2][2]; /* signpost facing: from, to spaces */
extern s16 D_80112CF4_31D1A4_name_49[8]; /* star spaces (markers) */
extern s16 D_80112D04_31D1B4_name_49[8]; /* their flags */
extern s32 D_80112D14_31D1C4_name_49; /* marker id, -1 none */
extern s16 D_80112D18_31D1C8_name_49[2];
extern s16 D_80112D1C_31D1CC_name_49[2]; /* bank spaces */
extern Vec D_80112D24_31D1D4_name_49[5]; /* bank coin offsets */
extern Vec D_80112D60_31D210_name_49[5]; /* bank coin rotations (x, z used) */
extern s16 D_80112D9C_31D24C_name_49[2]; /* signpost spaces */
extern u8 D_80112DA1_31D251_name_49[]; /* signpost model per board, at [board * 2] */
extern s32 D_80112DAC_31D25C_name_49[9]; /* per board: sound, -1 none (played as s16) */
extern s32 D_80112DD0_31D280_name_49[9]; /* per board: sound, -1 none (played as s16) */
extern s32 D_80112DF4_31D2A4_name_49[9]; /* per board: delay */
extern s32 D_80112E18_31D2C8_name_49[9]; /* per board: sound, -1 none (played as s16) */
extern s16 D_80112E3C_31D2EC_name_49;

/* 3E's rodata (0x2A8860-0x2A89A0, carved by the coordinator) */
extern const u8 D_801147B0_31EC60_name_49[4]; /* {1, 2, 4, 8}: window choice masks per pad; read by 6 functions */

/* ---- 3E bss (asm/data/overlays/ovl_3E_name/ovl_3E_bss.bss.s) ---- */

extern Process* D_80114990_31EE40_name_49; /* star appear process */
extern s32 D_80114994_31EE44_name_49; /* star process: 1 = take a star away */
extern s32 D_80114998_31EE48_name_49; /* help windows */
extern s32 D_8011499C_31EE4C_name_49;
extern s32 D_801149A0_31EE50_name_49;
extern s32 D_801149A4_31EE54_name_49;
extern s32 D_801149A8_31EE58_name_49;
extern s32 D_801149B0_31EE60_name_49[4]; /* the other players, by rank */
extern s32 D_801149C0_31EE70_name_49[4]; /* players other than the current one, by coins */
extern s32 D_801149D0_31EE80_name_49; /* what can be stolen: 0 coins, 1 a star, 2 nothing */
extern s32 D_801149D4_31EE84_name_49; /* the player Boo steals from */
extern s32 D_801149D8_31EE88_name_49; /* Boo's choice: a player slot, or 0/1/2 */
extern MBModel* D_801149F0_31EEA0_name_49;
extern MBModel* D_801149F8_31EEA8_name_49[7];
extern MBModel* D_80114A20_31EED0_name_49;
extern MBModel* D_80114A28_31EED8_name_49[15]; /* bank coins */
extern MBModel* D_80114A64_31EF14_name_49;
extern MBModel* D_80114A68_31EF18_name_49[2]; /* signposts */

extern Vec2f3E D_80113724_31DBD4_name_49[4];
extern Vec2f3E D_80113744_31DBF4_name_49[4]; /* per player: window positions (item events) */
extern Vec2f3E D_80113764_31DC14_name_49[4];
extern Vec2f3E D_80113784_31DC34_name_49[4];
extern s32 D_801137A4_31DC54_name_49[6]; /* per board: message */
s32 func_80060210_60E10(s32);
s32 func_800609D8_615D8(void); /* status windows still moving */
void MBStatusItemDispSetAll(s32);
extern s16 D_801137BC_31DC6C_name_49[6]; /* per board: message window */
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
extern f32 D_80113D80_31E230_name_49[4]; /* scissor box {0, 0, 320, 240} */
extern s32 D_801142B8_31E768_name_49[]; /* decision trees (CPU item use) */
extern s32 D_80114318_31E7C8_name_49[];
extern s32 D_801144C8_31E978_name_49[];
extern s32 D_80114630_31EAE0_name_49[];
s16 GetCurrentPlayerIndex(void);
s16 RNGPercentChance(s8 arg0);
extern u8 D_800CC000[]; /* item prices */
extern s32 D_80114690_31EB40_name_49[]; /* decision trees (CPU shop) */
extern s32 D_801146A8_31EB58_name_49[];
extern s32 D_801146C0_31EB70_name_49[]; /* decision tree (CPU yes/no) */
extern s32 D_801146D8_31EB88_name_49; /* set: the CPU's next answer is option 2 */
extern u8* D_80114724_31EBD4_name_49[]; /* per character: items the CPU tries to buy */
extern s8* D_80114784_31EC34_name_49[]; /* per character: their percent chances */
extern u8 D_8011479C_31EC4C_name_49[]; /* per character: list length */
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
extern MBModel* D_80114A88_31EF38_name_49;
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

extern s32 D_80113594_31DA44_name_49[6]; /* per character: sprite file */
extern Unk3EVec2f D_80113554_31DA04_name_49[4]; /* per player: lost star start */
extern Unk3EVec2f D_80113574_31DA24_name_49[4]; /* per player: lost star velocity */
f32 __sinf(f32);
extern Unk3ERange D_801135AC_31DA5C_name_49[6]; /* turn range -> star price */
extern Unk3ERange D_801135C0_31DA70_name_49[14]; /* press count range -> discount */
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

s16 func_80102830_30CCE0_name_49(void);
void func_8010285C_30CD0C_name_49(void);
void func_80102A44_30CEF4_name_49(void);
void func_80102AB0_30CF60_name_49(void);
void func_80102B54_30D004_name_49(void);
s32 func_80102C3C_30D0EC_name_49(s32 space);
void func_80102D28_30D1D8_name_49(void);
void func_80102F4C_30D3FC_name_49(UnkMBGuideData* guide);
void func_80102FFC_30D4AC_name_49(void);
void func_80103500_30D9B0_name_49(void);
void func_80103920_30DDD0_name_49(MBModel* parent);
void func_8010399C_30DE4C_name_49(MBModel* parent);
void func_80103DBC_30E26C_name_49(void);
void func_80103E4C_30E2FC_name_49(void);
s32 func_80103EC8_30E378_name_49(void);
void func_80103F1C_30E3CC_name_49(void);
void func_80103FEC_30E49C_name_49(void);
s32 func_8010404C_30E4FC_name_49(u8* items);
s32 func_80104308_30E7B8_name_49(void); /* the chosen option */
s32 func_8010452C_30E9DC_name_49(void); /* the chosen option */
void func_801046D8_30EB88_name_49(void);
s32 func_80104918_30EDC8_name_49(void);
void func_80104AD0_30EF80_name_49(void);
void func_801052D4_30F784_name_49(void);
s32 func_801056D4_30FB84_name_49(u8* items);
s32 func_80105988_30FE38_name_49(s32 arg0, u8* items);
void func_80105CE8_310198_name_49(void);
void func_80106058_310508_name_49(void);
void func_80106084_310534_name_49(s16 arg0);
void func_80106188_310638_name_49(void);
void func_80106210_3106C0_name_49(void);
void func_801062F8_3107A8_name_49(void);
void func_801064C0_310970_name_49(void);
void func_801065D4_310A84_name_49(s16 arg0);
void func_80106740_310BF0_name_49(void);
void func_801067A8_310C58_name_49(s16 arg0);
void func_80106964_310E14_name_49(void);
void func_801069C0_310E70_name_49(s32 arg0);
void func_80106A64_310F14_name_49(s32 arg0);
void func_80106AD0_310F80_name_49(void);
s32 func_801071EC_31169C_name_49(s32 arg0); /* the chosen option */
void func_8010744C_3118FC_name_49(void);
void func_80107744_311BF4_name_49(void);
void func_80107C10_3120C0_name_49(void);
void func_80107E10_3122C0_name_49(void); /* star / bank space */
s32 func_80108BF0_3130A0_name_49(s32 arg0);
s32 func_80108C5C_31310C_name_49(void);
void func_80108CA8_313158_name_49(void);
void func_801092B4_313764_name_49(MBModel* model);
void func_80109354_313804_name_49(MBModel* model);
s32 func_801093F4_3138A4_name_49(s32 player);
void func_80109CD0_314180_name_49(void);
s32 func_80109CF4_3141A4_name_49(s32 player);
void func_8010AA30_314EE0_name_49(void);
omObjData* func_8010B5F8_315AA8_name_49(Vec* pos, f32 scaleSpeed, f32 fadeSpeed, s16 kill, Vec* vel);
void func_8010B738_315BE8_name_49(omObjData* obj);
void func_8010B850_315D00_name_49(void);
void func_8010BBEC_31609C_name_49(void);
void func_8010BC5C_31610C_name_49(void);
void func_8010BE48_3162F8_name_49(void);
Process* func_8010C094_316544_name_49(s16 sprite, s16 x0, s16 y0, s16 x1, s16 y1, s16 frames);
void func_8010C140_3165F0_name_49(void);
void func_8010C4F0_3169A0_name_49(void);
void func_8010C83C_316CEC_name_49(void);
void func_8010CB68_317018_name_49(void);
void func_8010CFCC_31747C_name_49(void);
void func_8010D544_3179F4_name_49(void);
void func_8010D7B4_317C64_name_49(void);
void func_8010D9E8_317E98_name_49(void);
void func_8010DCFC_3181AC_name_49(void);
void func_8010E370_318820_name_49(void);
void func_8010E5A4_318A54_name_49(void);
void func_8010EAB4_318F64_name_49(void);
void func_801125B0_31CA60_name_49(void);
s32 func_80112604_31CAB4_name_49(void); /* fork D: returns the use-item answer */
s32 func_80112828_31CCD8_name_49(void);
s32 func_80112BA4_31D054_name_49(void);

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

extern DecisionTreeNonLeafNode D_801131B4_31D664_name_49[];
extern DecisionTreeNonLeafNode D_801131F0_31D6A0_name_49[];
extern DecisionTreeNonLeafNode D_80113208_31D6B8_name_49[];
extern s16 D_80113384_31D834_name_49[];
extern s16 D_801133CC_31D87C_name_49[];
extern u8 D_801134B4_31D964_name_49[]; /* by rank */
extern u8 D_801134E0_31D990_name_49[][4]; /* shop by turn band, rank */
extern u8 D_801134EC_31D99C_name_49[][3]; /* turn band starts by game length */
extern s8 D_801134F8_31D9A8_name_49[][5]; /* shop items, -1 none */
extern u32 D_8011351C_31D9CC_name_49[]; /* shop messages */
extern s32 D_80114A80_31EF30_name_49;
extern u8* D_80114A84_31EF34_name_49;

/* data the copied twins use */
extern DecisionTreeNonLeafNode D_80112EFC_31D3AC_name_49[]; /* as D_80111C3C_2A6F0C_name_3E */
extern DecisionTreeNonLeafNode D_80112FC8_31D478_name_49[]; /* as D_80111C3C_2A6F0C_name_3E */
extern DecisionTreeNonLeafNode D_8011316C_31D61C_name_49[]; /* as D_80111C3C_2A6F0C_name_3E */
extern DecisionTreeNonLeafNode D_8011322C_31D6DC_name_49[]; /* as D_80111F84_2A7254_name_3E */
extern DecisionTreeNonLeafNode D_80113274_31D724_name_49[]; /* as D_80111F84_2A7254_name_3E */
extern DecisionTreeNonLeafNode D_80113304_31D7B4_name_49[]; /* as D_80111F84_2A7254_name_3E */
extern DecisionTreeNonLeafNode D_8011338C_31D83C_name_49[]; /* as D_80114558_2D9A48_name_43 */
extern DecisionTreeNonLeafNode D_801133B0_31D860_name_49[]; /* as D_8011457C_2D9A6C_name_43 */
extern MBModel* D_80114A14_31EEC4_name_49; /* as D_8011306C_2F179C_name_45 */
extern MBModel* D_80114A18_31EEC8_name_49[2]; /* as D_80113070_2F17A0_name_45 */
extern MBModel* D_80114A70_31EF20_name_49; /* as D_8011373C_2A8A0C_name_3E */
extern MBModel* D_80114A74_31EF24_name_49[3]; /* as D_80113740_2A8A10_name_3E */
extern Unk3EStealRange D_801135EC_31DA9C_name_49[24]; /* as D_80111704_2EFE34_name_45 */
extern s16 D_80112CDC_31D18C_name_49[3][2]; /* as D_80111A28_2A6CF8_name_3E */
extern s16 D_80112CE8_31D198_name_49[1][2]; /* as D_80111A28_2A6CF8_name_3E */
extern s16 D_80112E40_31D2F0_name_49[3]; /* as D_80111B88_2A6E58_name_3E */
extern s16 D_80112E48_31D2F8_name_49[1]; /* as D_80111B88_2A6E58_name_3E */
extern s16 D_80113334_31D7E4_name_49[]; /* as D_801120E0_2A73B0_name_3E */
extern s16 D_8011334C_31D7FC_name_49[]; /* as D_801120E0_2A73B0_name_3E */
extern s16 D_8011336C_31D81C_name_49[]; /* as D_801120E0_2A73B0_name_3E */
extern s16 D_80113656_31DB06_name_49[]; /* as D_8011176E_2EFE9E_name_45 */
extern u8 D_80113548_31D9F8_name_49[4][3]; /* as D_80111660_2EFD90_name_45 */

/* main's dice block process work (46250.c), copied with its twins */
typedef struct DiceProcWork {
    /* 0x00 */ s32 player;
    /* 0x04 */ s32 state;
} DiceProcWork;

/* func_80103D28's work for its star process func_80103A1C */
typedef struct Ovl49StarProcWork {
    /* 0x00 */ s32 arg;
    /* 0x04 */ Vec* pos;
} Ovl49StarProcWork;

/* the rest of the board's 147 functions; "B" ones have no twin (fork 49-B) */
void func_80103A1C_30DECC_name_49(void); /* as func_80048AA8_496A8 */
void func_80103D28_30E1D8_name_49(s32 arg0, Vec* arg1);
void func_80105BFC_3100AC_name_49(void);
void func_80105C38_3100E8_name_49(void); /* as func_801058E0_2B41A0_name_41 */
void func_80105F94_310444_name_49(void); /* B: unknown */
void func_80106340_3107F0_name_49(s16 arg0);
void func_80106460_310910_name_49(void);
void func_80106904_310DB4_name_49(void);
void func_80106B0C_310FBC_name_49(void);
void func_80106B84_311034_name_49(void);
void func_80106BF8_3110A8_name_49(s16 arg0); /* B: from callers */
void func_80106D34_3111E4_name_49(void);
void func_80106D94_311244_name_49(void);
void func_80106EAC_31135C_name_49(void);
void func_80106FC4_311474_name_49(void); /* as func_80107C54_29CF24_name_3E */
void func_801070D4_311584_name_49(void);
void func_80107A3C_311EEC_name_49(void);
void func_80107A60_311F10_name_49(void);
void func_80107A84_311F34_name_49(void);
void func_80107AA8_311F58_name_49(void);
void func_80107ACC_311F7C_name_49(void);
void func_80107AF0_311FA0_name_49(void);
void func_80107B14_311FC4_name_49(void);
void func_80107B38_311FE8_name_49(void);
void func_80107B5C_31200C_name_49(void);
void func_80107B80_312030_name_49(void);
void func_80107BA4_312054_name_49(void);
void func_80107BC8_312078_name_49(void);
void func_80107BEC_31209C_name_49(void);
void func_80108650_312B00_name_49(void); /* B: unknown */
Process* func_8010AB84_315034_name_49(void* arg0);
void func_8010ABC0_315070_name_49(void);
void func_8010B5C0_315A70_name_49(void);
void func_8010B5DC_315A8C_name_49(void);
s32 func_8010ECC4_319174_name_49(s32 arg0, s32 arg1); /* B: from callers */
s32 func_8010F320_3197D0_name_49(void);
s32 func_8010F340_3197F0_name_49(void);
s32 func_8010F360_319810_name_49(void);
s32 func_8010F380_319830_name_49(void);
s32 func_8010F3A0_319850_name_49(void);
s32 func_8010F3C0_319870_name_49(void);
s32 func_8010F3E0_319890_name_49(void);
void func_8010F400_3198B0_name_49(void); /* B: unknown */
void func_8010F56C_319A1C_name_49(void); /* B: unknown */
void func_8010F694_319B44_name_49(void); /* B: unknown */
void func_8010F754_319C04_name_49(void); /* B: unknown */
void func_8010F918_319DC8_name_49(void); /* B: unknown */
void func_8010F9A0_319E50_name_49(void); /* B: unknown */
void func_8010FC3C_31A0EC_name_49(void); /* B: unknown */
void func_8010FE80_31A330_name_49(void); /* B: unknown */
void func_8010FF2C_31A3DC_name_49(void); /* B: unknown */
void func_80110188_31A638_name_49(s32 player);
void func_801101E0_31A690_name_49(void); /* B: unknown */
void func_8011056C_31AA1C_name_49(void); /* B: unknown */
s32 func_80111300_31B7B0_name_49(s32 arg0); /* as func_80110CCC_2D61BC_name_43 */
void func_80111588_31BA38_name_49(s32 arg0); /* B: from callers */
void func_80111A78_31BF28_name_49(void);
void func_80111A94_31BF44_name_49(void);
void func_80111AB0_31BF60_name_49(void);
void func_80111ACC_31BF7C_name_49(s32 arg0); /* B: from callers */
void func_80111C64_31C114_name_49(void);
void func_80111C80_31C130_name_49(void);
void func_80111C9C_31C14C_name_49(void);
void func_80111CB8_31C168_name_49(s32 arg0); /* B: from callers */
void func_80111E50_31C300_name_49(void);
void func_80111E6C_31C31C_name_49(void);
void func_80111E88_31C338_name_49(void);
void func_80111EA4_31C354_name_49(void);
void func_80111EC0_31C370_name_49(void);
void func_80111EDC_31C38C_name_49(void); /* B: unknown */

#endif
