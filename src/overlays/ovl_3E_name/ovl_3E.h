#ifndef _OVL_3E_H
#define _OVL_3E_H

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
void func_80044D98_45998(void (*)(void));
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

extern board_overlay_entrypoint D_80111920_2A6BF0_name_3E[]; /* the overlay's scene table */
extern s16 D_80111950_2A6C20_name_3E[8]; /* star positions, shuffled */
extern s16 D_80111960_2A6C30_name_3E[8]; /* each position's earliest slot */
extern s16 D_80111970_2A6C40_name_3E[]; /* positions not to show first, -1 ended */
extern s16 D_80111974_2A6C44_name_3E[8]; /* star position board flags */
extern s16 D_80111984_2A6C54_name_3E[8]; /* star spaces */
extern s16 D_80111994_2A6C64_name_3E[8]; /* star camera spaces */
extern s32 D_801119A4_2A6C74_name_3E; /* guide motions */
extern s32 D_801119A8_2A6C78_name_3E;
extern f32 D_801119AC_2A6C7C_name_3E[9]; /* per board */
extern s32 D_801119D0_2A6CA0_name_3E;
extern u8 D_801119D4_2A6CA4_name_3E[3][4]; /* steal-a-star chance by turn band, coin band */
extern s16 D_801119E4_2A6CB4_name_3E[8];
extern s16 D_801119F4_2A6CC4_name_3E[8];
extern s16 D_80111A04_2A6CD4_name_3E[7][2]; /* star space marker offsets */
extern s16 D_80111A20_2A6CF0_name_3E[2][2];
extern s16 D_80111A28_2A6CF8_name_3E[2][2];
extern s16 D_80111A30_2A6D00_name_3E[2];
extern s16 D_80111A34_2A6D04_name_3E[2][2]; /* signpost marker offsets */
extern s16 D_80111A3C_2A6D0C_name_3E[2][2]; /* signpost facing: from, to spaces */
extern s16 D_80111A44_2A6D14_name_3E[8]; /* star spaces (markers) */
extern s16 D_80111A54_2A6D24_name_3E[8]; /* their flags */
extern s32 D_80111A64_2A6D34_name_3E; /* marker id, -1 none */
extern s16 D_80111A68_2A6D38_name_3E[2];
extern s16 D_80111A6C_2A6D3C_name_3E[2]; /* bank spaces */
extern Vec D_80111A70_2A6D40_name_3E[5]; /* bank coin offsets */
extern Vec D_80111AAC_2A6D7C_name_3E[5]; /* bank coin rotations (x, z used) */
extern s16 D_80111AE8_2A6DB8_name_3E[2]; /* signpost spaces */
extern u8 D_80111AED_2A6DBD_name_3E[]; /* signpost model per board, at [board * 2] */
extern s32 D_80111AF8_2A6DC8_name_3E[9]; /* per board: sound, -1 none (played as s16) */
extern s32 D_80111B1C_2A6DEC_name_3E[9]; /* per board: sound, -1 none (played as s16) */
extern s32 D_80111B40_2A6E10_name_3E[9]; /* per board: delay */
extern s32 D_80111B64_2A6E34_name_3E[9]; /* per board: sound, -1 none (played as s16) */
extern s16 D_80111B88_2A6E58_name_3E[2];
extern s16 D_80111B8C_2A6E5C_name_3E;
extern BoardEventTableEntry D_80112484_2A7754_name_3E[];
extern BoardEventTableEntry D_801124EC_2A77BC_name_3E[];
extern BoardEventTableEntry D_8011280C_2A7ADC_name_3E[];

/* 3E's rodata (0x2A8860-0x2A89A0, carved by the coordinator) */
typedef struct Unk4Bytes {
    u8 b[4];
} Unk4Bytes;
extern u8 D_80113590_2A8860_name_3E[4]; /* {1, 2, 4, 8}: window choice masks per pad; read by 6 functions */

/* ---- 3E bss (asm/data/overlays/ovl_3E_name/ovl_3E_bss.bss.s) ---- */

extern Process* D_801136D0_2A89A0_name_3E; /* star appear process */
extern s32 D_801136D4_2A89A4_name_3E; /* star process: 1 = take a star away */
extern s32 D_801136D8_2A89A8_name_3E; /* help windows */
extern s32 D_801136DC_2A89AC_name_3E;
extern s32 D_801136E0_2A89B0_name_3E;
extern s32 D_801136E4_2A89B4_name_3E;
extern s32 D_801136E8_2A89B8_name_3E;
extern s32 D_801136F0_2A89C0_name_3E[4]; /* the other players, by rank */
extern s32 D_80113700_2A89D0_name_3E[4]; /* players other than the current one, by coins */
extern s32 D_80113710_2A89E0_name_3E; /* what can be stolen: 0 coins, 1 a star, 2 nothing */
extern s32 D_80113714_2A89E4_name_3E; /* the player Boo steals from */
extern s32 D_80113718_2A89E8_name_3E; /* Boo's choice: a player slot, or 0/1/2 */
extern MBModel* D_8011371C_2A89EC_name_3E;
extern MBModel* D_80113720_2A89F0_name_3E[7];
extern MBModel* D_8011373C_2A8A0C_name_3E;
extern MBModel* D_80113740_2A8A10_name_3E[2];
extern MBModel* D_80113748_2A8A18_name_3E;
extern MBModel* D_80113750_2A8A20_name_3E[10]; /* bank coins */
extern MBModel* D_80113778_2A8A48_name_3E;
extern MBModel* D_8011377C_2A8A4C_name_3E[2]; /* signposts */
extern MBModel* D_80113784_2A8A54_name_3E;
extern MBModel* D_80113788_2A8A58_name_3E;
extern s32 D_8011378C_2A8A5C_name_3E;
extern Vec D_80113790_2A8A60_name_3E[12]; /* path positions */
extern Vec D_80113820_2A8AF0_name_3E[12]; /* path rotations */
extern s32 D_801138B0_2A8B80_name_3E; /* path step */

/* fork C */
typedef struct Unk3EParticle {
    /* 0x00 */ Vec vel;
    /* 0x0C */ f32 alpha;
    /* 0x10 */ f32 scaleSpeed;
    /* 0x14 */ f32 fadeSpeed;
    /* 0x18 */ MBModel* model;
    /* 0x1C */ u16 kill; /* delete when faded out, else only pause */
    /* 0x1E */ char unk_1E[2];
} Unk3EParticle; /* size 0x20 (MP3 UnkChillyWaters) */

extern s8 D_800CCC16; /* set while the lamp's star event runs */
extern s16 D_800FA188_FAD88;
extern MBModel* D_801138BC_2A8B8C_name_3E;
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
/* Retail calls these two as int-returning (no sign extension of the result at the call). The ids
   are only passed on to s16 parameters, so the host's truncation keeps them right. */
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
void func_800629F0_635F0(s16 player, s16 arg1); /* status window alpha? */
void func_800628C0_634C0(s16 player, s16 arg1, f32 arg2);
void func_80062A28_63628(s16 player, f32 arg1); /* status window shake */

typedef struct Unk3EVec2f {
    f32 x;
    f32 y;
} Unk3EVec2f;
extern s32 D_8011237C_2A764C_name_3E[6]; /* per character: sprite file */
extern Unk3EVec2f D_8011233C_2A760C_name_3E[4]; /* per player: lost star start */
extern Unk3EVec2f D_8011235C_2A762C_name_3E[4]; /* per player: lost star velocity */
f32 __sinf(f32);
extern Unk3EVec2f D_80112504_2A77D4_name_3E[4]; /* per player: window slide positions */
extern Unk3EVec2f D_80112524_2A77F4_name_3E[4];
extern Unk3EVec2f D_80112544_2A7814_name_3E[4];
extern Unk3EVec2f D_80112564_2A7834_name_3E[4];
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

typedef struct Unk3EWindowSlide {
    /* 0x00 */ s16 x0;
    /* 0x02 */ s16 y0;
    /* 0x04 */ s16 x1;
    /* 0x06 */ s16 y1;
    /* 0x08 */ s16 frames;
    /* 0x0A */ s16 sprite; /* -1: none */
    /* 0x0C */ char unk_0C[4];
} Unk3EWindowSlide; /* size 0x10 */

/* ---- 297AD0.c ---- */

void func_80102800_297AD0_name_3E(void);
s16 func_80102830_297B00_name_3E(void);
void func_8010285C_297B2C_name_3E(void);
void func_80102A44_297D14_name_3E(void);
void func_80102AB0_297D80_name_3E(void);
void func_80102B54_297E24_name_3E(void);
s32 func_80102C3C_297F0C_name_3E(s32 space);
void func_80102D28_297FF8_name_3E(void);
void func_80102F4C_29821C_name_3E(UnkMBGuideData* guide);
void func_80102FFC_2982CC_name_3E(void);
void func_80103548_298818_name_3E(void);
void func_80103968_298C38_name_3E(MBModel* parent);
void func_801039E4_298CB4_name_3E(MBModel* parent);
void func_80103A64_298D34_name_3E(void);
void func_80103AF4_298DC4_name_3E(void);
s32 func_80103B70_298E40_name_3E(void);
void func_80103BC4_298E94_name_3E(void);
void func_80103C94_298F64_name_3E(void);
s32 func_80103CF4_298FC4_name_3E(u8* items);
s32 func_80103FB0_299280_name_3E(void); /* the chosen option */
s32 func_801041D4_2994A4_name_3E(void); /* the chosen option */
void func_80104380_299650_name_3E(void);
s32 func_801045C0_299890_name_3E(void);
void func_80104778_299A48_name_3E(void);
void func_80104F7C_29A24C_name_3E(void);
s32 func_8010537C_29A64C_name_3E(u8* items);
s32 func_80105630_29A900_name_3E(s32 arg0, u8* items);
void func_801058A4_29AB74_name_3E(void);
void func_801058DC_29ABAC_name_3E(void);
void func_80105974_29AC44_name_3E(void);
void func_80105B9C_29AE6C_name_3E(void);
void func_80105C24_29AEF4_name_3E(void);
void func_80105C50_29AF20_name_3E(s16 arg0);
void func_80105D54_29B024_name_3E(void);
void func_80105DDC_29B0AC_name_3E(void);
void func_80105EC4_29B194_name_3E(void);
void func_80105F0C_29B1DC_name_3E(s16 arg0);
void func_8010602C_29B2FC_name_3E(void);
void func_8010608C_29B35C_name_3E(void);
void func_80106188_29B458_name_3E(s16 arg0);
void func_801062F4_29B5C4_name_3E(void);
void func_8010635C_29B62C_name_3E(s16 arg0);
void func_801064B8_29B788_name_3E(void);
void func_80106518_29B7E8_name_3E(void);
void func_80106574_29B844_name_3E(s32 arg0);
void func_80106618_29B8E8_name_3E(s32 arg0);
void func_80106684_29B954_name_3E(void);
void func_801066FC_29B9CC_name_3E(void);
void func_80106738_29BA08_name_3E(void);
void func_80106944_29BC14_name_3E(void);
void func_801069C8_29BC98_name_3E(void);
void func_80106B08_29BDD8_name_3E(void);
void func_80106C44_29BF14_name_3E(void);
void func_80106D78_29C048_name_3E(s32 arg0);
void func_80106DCC_29C09C_name_3E(s16 arg0, s32 arg1);
s32 func_80106FE0_29C2B0_name_3E(void);
s32 func_801075F8_29C8C8_name_3E(void);
void func_80107C54_29CF24_name_3E(void);
void func_80107D6C_29D03C_name_3E(void);
void func_80107E84_29D154_name_3E(void);
void func_80107F9C_29D26C_name_3E(void);
void func_801080B4_29D384_name_3E(void);
s32 func_801081CC_29D49C_name_3E(s32 arg0);
void func_80108424_29D6F4_name_3E(void);
void func_8010871C_29D9EC_name_3E(void);
void func_80108A14_29DCE4_name_3E(void);
void func_80108A38_29DD08_name_3E(void);
void func_80108A5C_29DD2C_name_3E(void);
void func_80108A80_29DD50_name_3E(void);
void func_80108AA4_29DD74_name_3E(void);
void func_80108AC8_29DD98_name_3E(void);
void func_80108AEC_29DDBC_name_3E(void);
void func_80108B10_29DDE0_name_3E(void);
void func_80108B34_29DE04_name_3E(void);
void func_80108B58_29DE28_name_3E(void);
void func_80108B7C_29DE4C_name_3E(void);
void func_80108BA0_29DE70_name_3E(void);
void func_80108BC4_29DE94_name_3E(void);
void func_80108BE8_29DEB8_name_3E(void);
void func_80108C0C_29DEDC_name_3E(void);
void func_80108E0C_29E0DC_name_3E(void);
void func_8010964C_29E91C_name_3E(void);
s32 func_80109A78_29ED48_name_3E(s32 arg0);
s32 func_80109AE4_29EDB4_name_3E(void);
void func_80109B30_29EE00_name_3E(void);
s32 func_8010A13C_29F40C_name_3E(s32 arg0);
void func_8010A1DC_29F4AC_name_3E(s32 arg0);
s32 func_8010A27C_29F54C_name_3E(s32 player);
void func_8010AB58_29FE28_name_3E(void);
s32 func_8010AB7C_29FE4C_name_3E(s32 arg0);
void func_8010B8B8_2A0B88_name_3E(void);
void func_8010BA0C_2A0CDC_name_3E(s32 arg0);
void func_8010BA48_2A0D18_name_3E(void);
void func_8010C44C_2A171C_name_3E(void);
void func_8010C468_2A1738_name_3E(void);
omObjData* func_8010C484_2A1754_name_3E(Vec* pos, f32 scaleSpeed, f32 fadeSpeed, s16 kill, Vec* vel);
void func_8010C5C4_2A1894_name_3E(omObjData* obj);
void func_8010C6DC_2A19AC_name_3E(void);
void func_8010CA78_2A1D48_name_3E(void);
void func_8010CAE8_2A1DB8_name_3E(void);
void func_8010CCD4_2A1FA4_name_3E(void);
Process* func_8010CF20_2A21F0_name_3E(s16 sprite, s16 x0, s16 y0, s16 x1, s16 y1, s16 frames);
void func_8010CFCC_2A229C_name_3E(void);
void func_8010D37C_2A264C_name_3E(void);
void func_8010D6C8_2A2998_name_3E(void);
void func_8010D9F4_2A2CC4_name_3E(void);
void func_8010DE58_2A3128_name_3E(void);
void func_8010E3D0_2A36A0_name_3E(void);
void func_8010E640_2A3910_name_3E(void);
void func_8010E874_2A3B44_name_3E(void);
void func_8010EB88_2A3E58_name_3E(void);
void func_8010F1FC_2A44CC_name_3E(void);
void func_8010F430_2A4700_name_3E(void);
void func_8010F940_2A4C10_name_3E(void);
s32 func_8010FB50_2A4E20_name_3E(void);
void func_8010FD84_2A5054_name_3E(void);
s32 func_801104E0_2A57B0_name_3E(void);
void func_80110794_2A5A64_name_3E(void);
void func_80110F78_2A6248_name_3E(void);
void func_801112E4_2A65B4_name_3E(void);
void func_80111338_2A6608_name_3E(void);
s32 func_8011155C_2A682C_name_3E(void);
s32 func_801118D8_2A6BA8_name_3E(void);

#endif
