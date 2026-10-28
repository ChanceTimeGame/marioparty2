#ifndef _OVL_5B_H
#define _OVL_5B_H

/* Overlay 5B: the main menu (Mario Party 2's lobby: board select, Mini-Game Park and the other
   modes; 58 is the setup screen it goes on to). Retail's overlay is three files: 37F4B0.c (the
   entry point), 37F4E0.c (80102830-8010A8F4) and 3875F0.c (8010A940-end). Every function is
   global. .data and .bss stay asm (declared here); each file's .rodata is carved.
   Prototypes past 80105530 came from m2c's register use only: the fork that owns a function fixes
   its line, and retypes its data (declared from the access width only). */

#include "common.h"
#include "process.h"
#include "game/data.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/sprite.h"
#include "game/window.h"
#include "game/gamemes.h"
#include "game/pad.h"

/* ---- types ---- */

/* One camera view (D_801126A0, through D_80114734; 801086E0 applies one, 80108788 moves to one). */
typedef struct Ovl5BCamView {
    /* 0x00 */ Vec rot;  /* -> D_800FD474 */
    /* 0x0C */ Vec at;   /* -> D_8010274C */
    /* 0x18 */ f32 zoom; /* -> D_800FA610 */
} Ovl5BCamView; /* size = 0x1C */

/* One of the menu's models (D_801129B0; 8010A0F0 loads them into D_80114758). */
typedef struct Ovl5BModelDef {
    /* 0x00 */ s32 file;
    /* 0x04 */ s32 attr; /* | 0x288 */
    /* 0x08 */ s16 unk08;
    /* 0x0A */ s16 unk0A; /* motion mode */
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ Vec pos;
    /* 0x1C */ Vec rot;
} Ovl5BModelDef; /* size = 0x28 */

/* ---- main-segment API used by 5B ---- */

void ExecBoardScene(void*, s16);
void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
void Hu3DCam3DToScreen(s16 camIndex, Vec* worldPos, Vec2f* outPos);
void Hu3DCamSetPositionOrientation(s16 camIndex, Vec* pos, Vec* at, Vec* up);
void Hu3DCamUpdateMtx(s16 camIndex);
s32 HuGetPadInserted(s16);
f32 HuMathSin(f32);
s16 LoadFormFile(s32, s32);
s32 PlaySound(s32);
void SprAnimKill(s16 animIdx);
void espDispOff(u16);
void espDispOn(u16);
void espPosSet(u16 spriteId, s16 x, s16 y);
s32 func_8000E930_F530(void);
void func_8000EA88_F688(s32 mono);
u16 func_80018A30_19630(s32, s32); /* model load */
s16 func_80018ACC_196CC(s32 arg0);
s16 func_8001A2F8_1AEF8(s32 arg0);
void func_8001A6BC_1B2BC(u16 spriteId, s16 arg1);
void func_8001A788_1B388(u16 spriteId, s32 arg1);
void func_8001A91C_1B51C(u16 spriteId, f32 x, f32 y);
void func_8001A96C_1B56C(u16, u8, u8, u8); /* sprite colour */
void func_8001A9C0_1B5C0(u16 spriteId, f32 arg1);
s16 func_8001AAAC_1B6AC(s16, s32, s32);
void func_8001AC44_1B844(u16 arg0);
void func_80020070_20C70(s32);
void func_80020D20_21920(s16 arg0);
void func_80023554_24154(s16 model, s16 frame, char* part, f32 mtx[4][4]); /* part matrix */
void func_80025830_26430(f32 m[4][4], f32 x, f32 y, f32 z); /* scale */
void func_80025884_26484(f32 m[4][4], f32 x, f32 y, f32 z); /* rotate */
void func_80025BA4_267A4(f32 (*)[4], f32 (*)[4], f32 (*)[4]); /* MP1 MtxMult */
void func_80026D28_27928(s32);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
s16 func_80027D3C_2893C(s16 linkMdlId);
s32 func_800283DC_28FDC(s16); /* remove a draw callback */
void func_80029708_2A308(s32);
void func_80029714_2A314(s16, f32, f32, f32);
void func_80029760_2A360(s16 idx, Vec *arg1);
void func_8002979C_2A39C(s16 idx, f32 x, f32 y, f32 z);
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029A8C_2A68C(s16);
void func_80029AFC_2A6FC(s16);
void func_80029B80_2A780(s16 arg0, s16 arg1);
void func_80029BF0_2A7F0(s16, s16, s16, s16, s16);
void func_80029C74_2A874(s16, f32);
f32 func_80029CE4_2A8E4(s16);
f32 func_80029D0C_2A90C(s16); /* motion length */
s32 func_80029E14_2AA14(s16 arg0); /* 2AA14.c: u8; retail callers re-extend the result */
void func_80029FE4_2ABE4(s16, f32);
void func_8002A00C_2AC0C(s16 model);
HmfMotionObj* func_8002A9F4_2B5F4(s16 arg0, char* arg1);
void func_8002AC10_2B810(s16 arg0, f32 arg1, f32 arg2, s32 arg3);
void func_8002BED4_2CAD4(s16 arg0, f32 arg1, f32 arg2, u16 arg3, u16 arg4, char* arg5, u8 arg6); /* texture scroll */
void func_8002C628_2D228(s16 arg0, s16 arg1, char* arg2); /* attach to a model's hook node */
void func_8002C9C0_2D5C0(s16, s16);
f32 func_8002CA14_2D614(s16);
void func_8002CA48_2D648(u8 arg0, u8 arg1, u8 arg2);
void func_8002D4D0_2E0D0(s16 n);
void func_80030CD4_318D4(f32 (*)[4], f32 (*)[4]);
void func_8003B72C_3C32C(s16 arg0, s16 arg1, char* arg2, s16 arg3, s16 arg4);
void func_8003B76C_3C36C(s16 arg0, s16 arg1, char* arg2, s16 arg3, s16 arg4);
s16 func_8003DF08_3EB08(void*);
void func_8003EE44_3FA44(HmfData* arg0);
void func_8003EEA4_3FAA4(HmfData* arg0);
s16 func_80067F4C_68B4C(s16 arg0);
s16 func_80068040_68C40(s16 arg0);
u16 func_800680D4_68CD4(s32); /* the minigame record (time) */
void func_80079614_7A214(s16 time); /* music fade-out */
void func_80079848_7A448(s16 arg0);
void func_80079868_7A468(void);
void func_80079DB4_7A9B4(void);
void func_8007DCE8_7E8E8(void);
s32 func_8007DD68_7E968(void);
void func_8007DF5C_7EB5C(void);
void func_80088604_89204(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
s32 func_800888A8_894A8(s16, s16, s16, s16, s32, s16);
void func_800890CC_89CCC(s16, s32, s32, s32);
void func_80089284_89E84(s16, s32, s32);
u32 func_800892D8_89ED8(s16 winId);
void func_80089308_89F08(s16, char*, s32); /* window message argument */
void func_80089A48_8A648(s16, s16);
void func_80089A7C_8A67C(s16 winId, s16 prio);
void func_80089B2C_8A72C(s16, s16);
void func_80089BBC_8A7BC(s16 winId, s32 alpha);
void func_80089C78_8A878(s16 winId, u8 arg1);
void func_80089CAC_8A8AC(s16 winId, u8 idx, u8 r, u8 g, u8 b);
void func_80089DA0_8A9A0(s16 winId, u8 r, u8 g, u8 b);
void func_8008AD44_8B944(s16);
s16 func_8008BA30_8C630(s16 winId);
s32 func_8008BB48_8C748(s16, s16, s32);
void func_8008CCA8_8D8A8(s16);
void func_8008D5D8_8E1D8(s16 winId); /* hide a window */
void func_8008D6F0_8E2F0(s16 winId); /* show a window */
void func_8008DBE0_8E7E0(s16* arg0, s16 arg1, s16 arg2);
void func_8008DF9C_8EB9C(s32 winId, u16 btn);
s32 func_8008DFC4_8EBC4(s16 x, s16 y, s32 style);
void func_8008E2DC_8EEDC(s32 winId, s32 sound);
void func_8008E4D0_8F0D0(s32 winId, s32 sound);
void func_8008E644_8F244(s32 arg0, u8 arg1);
void func_8008E6AC_8F2AC(s16 arg0);
void func_8008E6CC_8F2CC(s16 arg0, s16 arg1);
s32 func_8008E73C_8F33C(s16 portrait, s16 x, s16 y, s32 w, s32 h, u16 flags);
void func_8008E978_8F578(s16 winId);
void func_8008EED8_8FAD8(s16 arg0, s16 arg1);
void func_8008F624_90224(s32, s32, s32); /* wipe colour */
u32 func_800A5610_A6210(char*); /* strlen */
f32 func_800B1830_B2430(f32); /* sqrtf */
void func_800B1960_B2560(f32 m[4][4], f32 ex, f32 ey, f32 ez, f32 ax, f32 ay, f32 az, f32 ux, f32 uy, f32 uz); /* guLookAtF */
void func_800B1F50_B2B50(f32 m[4][4], f32 x, f32 y, f32 z); /* MP1 func_8009EA40: translation */
f32 func_800B75A8_B81A8(f32 y, f32 x);
f32 func_800B7890_B8490(f32); /* cos */
void omPrcSetStatBit(Process*, s32);
void osSyncPrintf(const char* fmt, ...);
int sprintf(char* dst, const char* fmt, ...);

extern s8 ContStkX[4];
extern s8 ContStkY[4];
extern s16 D_800CAFEE; /* main (3D6A0.c): the minigame variant override, -1 none */
extern s16 D_800FD80C_FE40C; /* main: a controller port (80102830 finds the first one plugged in) */

/* ---- 5B .data (asm, 38F320.data.s) ---- */

extern board_overlay_entrypoint D_80112670_38F320_name_5B[]; /* the three entry points (0: from the title, 1, 2), -1 */
extern u16 D_80112690_38F340_name_5B; /* set: the menu is leaving (80102C88 stops) */
extern f32 D_80112694_38F344_name_5B; /* camera field of view */
extern s8 D_80112698_38F348_name_5B[2]; /* 80109B1C */
extern s16 D_8011269A_38F34A_name_5B;
extern s16 D_8011269C_38F34C_name_5B; /* the entry point used (0, 1, 2) */
extern s16 D_8011269E_38F34E_name_5B; /* board to go to directly (-1: none) */
extern Ovl5BCamView D_801126A0_38F350_name_5B[28]; /* camera views (D_80114734) */
extern Ovl5BModelDef D_801129B0_38F660_name_5B[55]; /* the menu's models, file -1 ends (54 entries) */
extern f32 D_80112A3C_38F6EC_name_5B; /* = D_801129B0[3].pos.y (80107748) */
extern f32 D_80112A40_38F6F0_name_5B; /* = D_801129B0[3].pos.z */
extern s16 D_80113248_38FEF8_name_5B[10][2]; /* the menu choices' sprite offsets from the panel (x, y; 80105530); labels 324A, 325C are [0][1], [5] */
extern s32 D_80113270_38FF20_name_5B[11]; /* 8010607C */
extern u8 D_8011329C_38FF4C_name_5B; /* 8010607C */
extern u8 D_8011329D_38FF4D_name_5B; /* 8010607C */
extern u8 D_8011329E_38FF4E_name_5B[16]; /* 8010607C */
extern s16 D_801132AE_38FF5E_name_5B; /* the panel's state (80105530: 0 coming in, 1 leaving, 2 shown) */
extern s16 D_801132B0_38FF60_name_5B; /* the continue choice's sprite group (80105530) */
extern u16 D_801132B2_38FF62_name_5B; /* its sprite */
extern s32 D_801132B4_38FF64_name_5B; /* 801068C4 */
extern s32 D_801132B8_38FF68_name_5B[19]; /* 80107748 */
extern s32 D_80113304_38FFB4_name_5B[20]; /* 801068C4 */
extern s32 D_80113354_390004_name_5B[50]; /* 80106D2C */
extern s32 D_8011341C_3900CC_name_5B[9]; /* 80106D2C */
extern s32 D_80113440_3900F0_name_5B; /* 80106D2C */
extern s32 D_80113444_3900F4_name_5B[9]; /* 80107748 */
extern s32 D_80113468_390118_name_5B[10]; /* 80107748 */
extern s16 D_80113490_390140_name_5B; /* 8010ACBC 8010DCAC */
extern s16 D_80113492_390142_name_5B; /* 8010ACBC 80110908 */
extern s32 D_80113494_390144_name_5B[7]; /* 8010ACBC */
extern s16 D_801134B0_390160_name_5B[8]; /* 8010ACBC */
extern s16 D_801134C0_390170_name_5B[7]; /* 8010ACBC */
extern s16 D_801134CE_39017E_name_5B; /* 8010ACBC */
extern s16 D_801134D0_390180_name_5B[2]; /* 8010ACBC 8010DA34 */
extern s32 D_801134D4_390184_name_5B[8]; /* unused by code */
extern s32 D_801134F4_3901A4_name_5B[7]; /* unused by code */
extern s32 D_80113510_3901C0_name_5B[7]; /* unused by code */
extern s32 D_8011352C_3901DC_name_5B[10]; /* unused by code */
extern s32 D_80113554_390204_name_5B[10]; /* unused by code */
extern s32 D_8011357C_39022C_name_5B[8]; /* unused by code */
extern s32 D_8011359C_39024C_name_5B[4]; /* unused by code */
extern s32 D_801135AC_39025C_name_5B[9]; /* unused by code */
extern s32 D_801135D0_390280_name_5B[4]; /* unused by code */
extern s16 D_801135E0_390290_name_5B[202]; /* 8010CB88 */
extern s32 D_80113774_390424_name_5B[1]; /* 8010B654 */
extern s32 D_80113778_390428_name_5B[17]; /* 8010B654 */
extern s32 D_801137BC_39046C_name_5B[3]; /* 8010B654 */
extern s32 D_801137C8_390478_name_5B[3]; /* 8010B654 */
extern s32 D_801137D4_390484_name_5B[6]; /* 8010B654 */
extern s16 D_801137EC_39049C_name_5B[2]; /* 8010B654 */
extern s16 D_801137F0_3904A0_name_5B[1]; /* 8010CB88 */
extern s16 D_801137F2_3904A2_name_5B[1]; /* 8010CB88 */
extern s16 D_801137F4_3904A4_name_5B[28]; /* 8010CB88 */
extern s32 D_8011382C_3904DC_name_5B[2]; /* 8010CB88 */
extern s16 D_80113834_3904E4_name_5B[2]; /* 8010CB88 */
extern s32 D_80113838_3904E8_name_5B; /* 8010DCAC 8010DF24 80110AF8 80112094 */
extern s16 D_8011383C_3904EC_name_5B[6]; /* 8010E618 8010ED80 */
extern s32 D_80113848_3904F8_name_5B[7]; /* 8010E618 8010ED80 */
extern s16 D_80113864_390514_name_5B[13]; /* 8010ED80 */
extern s16 D_8011387E_39052E_name_5B[13]; /* 8010F734 */
extern s16 D_80113898_390548_name_5B[4]; /* 80110908 80110AF8 80112094 */

/* ---- 5B .bss (asm, ovl_5B_bss.bss.s) ---- */

extern s16 D_80113A10_3906C0_name_5B; /* 80105530 801068C4 */
extern s16 D_80113A12_3906C2_name_5B;
extern s16 (*D_80113A14_3906C4_name_5B)[2]; /* the pointer's position table (x, y per choice; 80109374) */
extern s16 D_80113A18_3906C8_name_5B; /* the message window */
extern s16 D_80113A1A_3906CA_name_5B; /* 80102830 80109398 */
extern s16 D_80113A1C_3906CC_name_5B; /* the pointer sprite's x */
extern s16 D_80113A1E_3906CE_name_5B; /* its y */
extern s16 D_80113A20_3906D0_name_5B; /* its slide length in frames */
extern s16 D_80113A22_3906D2_name_5B; /* the choice it points at (-1: none) */
extern s32 D_80113A30_3906E0_name_5B[324]; /* 80112304 */
extern s32 D_80113F40_390BF0_name_5B[6]; /* 80112304 */
extern s32 D_80113F58_390C08_name_5B[1]; /* 80112304 */
extern s32 D_80113F5C_390C0C_name_5B[5]; /* 80112304 */
extern s32 D_80113F70_390C20_name_5B[1]; /* 80112304 */
extern s16 D_80113F74_390C24_name_5B[7]; /* 80112304 */
extern u16 D_80113F82_390C32_name_5B; /* 80112304 */
extern s16 D_80113F84_390C34_name_5B; /* 8010B654 80112304 */
extern u16 D_80113F86_390C36_name_5B[5]; /* 80112304 */
extern s32 D_80113F90_390C40_name_5B[36]; /* 80112304 */
extern s16 D_80114020_390CD0_name_5B[72]; /* 80112304 */
extern s16 D_801140B0_390D60_name_5B[504]; /* 80112304 */
extern u16 D_801144A0_391150_name_5B; /* 80112304 */
extern s16 D_801144A2_391152_name_5B; /* 8010ACBC 80110AF8 */
extern s16 D_801144A4_391154_name_5B; /* 8010A940 */
extern u16 D_801144A6_391156_name_5B; /* 8010A940 8010DF24 */
extern s16 D_801144A8_391158_name_5B; /* 8010A940 8010C828 */
extern u16 D_801144AA_39115A_name_5B; /* 8010A940 8010C828 */
extern s16 D_801144AC_39115C_name_5B; /* 8010B654 8010CB88 8010D6E8 */
extern s16 D_801144AE_39115E_name_5B; /* 8010B654 8010CB88 8010D6E8 */
extern s16 D_801144B0_391160_name_5B[2]; /* 8010B654 8010CB88 8010D6E8 */
extern s32 D_801144B4_391164_name_5B[3]; /* 8010B654 8010CB88 8010D6E8 */
extern s32 D_801144C0_391170_name_5B[4]; /* 8010B654 8010CB88 */
extern s32 D_801144D0_391180_name_5B[1]; /* 8010B654 */
extern s32 D_801144D4_391184_name_5B; /* 8010B654 */
extern u8 D_801144D8_391188_name_5B[64]; /* 8010B654 */
extern s32 D_80114518_3911C8_name_5B[28]; /* 8010B654 */
extern s16 D_80114588_391238_name_5B[1]; /* 8010B654 */
extern u8 D_8011458A_39123A_name_5B[398]; /* 8010B654 */
extern s32 D_80114718_3913C8_name_5B[6]; /* 80110AF8 80112094 */
extern s16 D_80114730_3913E0_name_5B[2]; /* 8010A940 8010ACBC 8010DCAC 80110908 */
extern Ovl5BCamView* D_80114734_3913E4_name_5B; /* the camera view table */
extern s16 D_80114738_3913E8_name_5B; /* the current screen */
extern s16 D_8011473A_3913EA_name_5B; /* the overlay to go to */
extern s16 D_8011473C_3913EC_name_5B; /* the pointer sprite is shown (80108F18) */
extern s16 D_8011473E_3913EE_name_5B; /* 80102C88 80105530 801068C4 */
extern s16 D_80114740_3913F0_name_5B; /* 80102830 80102C88 80103B54 80103EB4 80105530 8010607C 801068C4 80107748 8010E618 8010ED80 */
extern s16 D_80114742_3913F2_name_5B; /* 80102830 80102C88 8010ACBC */
extern Vec D_80114744_3913F4_name_5B; /* camera position (801086E0) */
extern s16 D_80114750_391400_name_5B; /* handshake between the menu processes (0, 1, -1) */
extern s16 D_80114758_391408_name_5B[60]; /* model per D_801129B0 entry (8010A0F0); splat labels 75A-7BE are elements; [0x2B] is the host */
extern s16 D_801147D0_391480_name_5B[58]; /* each model's motion (8010A0F0); labels 7E0-838 are elements */
extern Vec D_80114844_3914F4_name_5B;
extern s16 D_80114850_391500_name_5B; /* 80102830 80102C88 80107748 80109408 8010DA34 80110AF8 */
extern s16 D_80114852_391502_name_5B; /* 80102830 80107748 80109408 */
extern s16 D_80114854_391504_name_5B; /* 80102830 8010ACBC */
extern f32 D_80114858_391508_name_5B; /* camera far */
extern f32 D_8011485C_39150C_name_5B; /* camera near */
extern s16 D_80114860_391510_name_5B; /* 80102830 8010A940 8010ACBC 8010D8B0 */
extern s16 D_80114862_391512_name_5B; /* the controller port that drives the menu (-1: none) */
extern Vec D_80114864_391514_name_5B;
extern s16 D_80114870_391520_name_5B; /* 80102830 80102C88 80103B54 80103EB4 801068C4 80107748 */
extern s16 D_80114872_391522_name_5B; /* the cursor's first choice (5 or 8) */
extern s16 D_80114878_391528_name_5B[10][2]; /* menu choices' screen positions (x, y); label 87A is [0][1] */
extern u16 D_801148A0_391550_name_5B; /* the pointer sprite */
extern s16 D_801148A2_391552_name_5B; /* 80102830 80102C88 80103EB4 801068C4 80109408 */
extern s16 D_801148A4_391554_name_5B; /* the menu cursor (choice 0-9) */

/* ---- 5B functions ---- */

void func_80102800_37F4B0_name_5B(void);
void func_80102830_37F4E0_name_5B(void);
void func_80102BD0_37F880_name_5B(void);
void func_80102C34_37F8E4_name_5B(void);
void func_80102C88_37F938_name_5B(void);
void func_80103984_380634_name_5B(s16* arg0);
void func_801039BC_38066C_name_5B(void);
void func_80103A94_380744_name_5B(s16* arg0);
s16 func_80103B54_380804_name_5B(s16 x, s16 y);
void func_80103EB4_380B64_name_5B(void);
void func_80104300_380FB0_name_5B(void);
void func_80105410_3820C0_name_5B(void);
void func_80105530_3821E0_name_5B(void);
void func_8010607C_382D2C_name_5B(void);
s32 func_80106868_383518_name_5B(s16 arg0);
void func_801068C4_383574_name_5B(void);
void func_80106D2C_3839DC_name_5B(void);
void func_80107748_3843F8_name_5B(void);
void func_801085A8_385258_name_5B(void);
void func_801086E0_385390_name_5B(s16 arg0);
void func_80108788_385438_name_5B(s16 view, s16 frames, s16 mode, void (*cb)(s16*));
void func_80108F18_385BC8_name_5B(void);
void func_801091EC_385E9C_name_5B(void);
void func_8010933C_385FEC_name_5B(s16 arg0);
void func_80109374_386024_name_5B(s16 (*pos)[2]); /* stores D_80113A14 */
void func_80109380_386030_name_5B(s16 arg0);
void func_8010938C_38603C_name_5B(s16 arg0);
void func_80109398_386048_name_5B(omObjData* obj);
void func_80109408_3860B8_name_5B(omObjData* obj);
void func_801094F8_3861A8_name_5B(void);
void func_80109B1C_3867CC_name_5B(void);
void func_8010A0F0_386DA0_name_5B(s32 *arg0);
void func_8010A1E4_386E94_name_5B(s32 arg0, s16 arg1, s16 arg2);
void func_8010A53C_3871EC_name_5B(s16 arg0, f32 arg1, void *arg2, void *arg3);
void func_8010A7F4_3874A4_name_5B(s16 model, Vec* out, f32 mtx[4][4]); /* a point of the model in world space */
void func_8010A8F4_3875A4_name_5B(s16 model, Vec2f* out, f32 mtx[4][4]); /* the same on screen */
void func_8010A940_3875F0_name_5B(void);
void func_8010ACBC_38796C_name_5B(void);
s16 func_8010B5A8_388258_name_5B(s16 arg0, s32, s16 arg2);
void func_8010B654_388304_name_5B(void);
void func_8010C5D4_389284_name_5B(void);
void func_8010C828_3894D8_name_5B(s16 arg0);
void func_8010CB88_389838_name_5B(void);
void func_8010D6E8_38A398_name_5B(s16 *arg0);
void func_8010D8B0_38A560_name_5B(void);
void func_8010DA34_38A6E4_name_5B(void);
void func_8010DCAC_38A95C_name_5B(void);
void func_8010DF24_38ABD4_name_5B(void);
s32 func_8010E618_38B2C8_name_5B(void);
s32 func_8010ED80_38BA30_name_5B(void);
s32 func_8010F734_38C3E4_name_5B(void);
s32 func_801101E8_38CE98_name_5B(void);
s16 func_80110770_38D420_name_5B(s16 arg0, s16 arg1);
s16 func_8011083C_38D4EC_name_5B(s16 arg0, s16 arg1);
void func_80110908_38D5B8_name_5B(void);
void func_80110AF8_38D7A8_name_5B(void);
void func_80112094_38ED44_name_5B(s32 arg0);
void func_80112304_38EFB4_name_5B(void);

/* 5B-C */

extern u16 D_801011FC_101DFC; /* main: set while the game resets */

#endif
