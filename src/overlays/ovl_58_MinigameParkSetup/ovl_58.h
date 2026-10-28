#ifndef _OVL_58_H
#define _OVL_58_H

/* Overlay 58: the Mini-Game Park setup screens (players and pads, characters, CPU levels,
   handicaps, game length, bonus; then the minigame mode itself). One retail file, 36DF00.c.
   Every function is global. .data and .bss stay asm (declared here); the file's .rodata is
   carved. Prototypes past 801051BC came from the asm's register use only: the fork that owns
   a function fixes its line. */

#include "common.h"
#include "process.h"
#include "game/data.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/sprite.h"
#include "game/window.h"
#include "game/gamemes.h"
#include "game/gamework.h"
#include "game/pad.h"

/* ---- types ---- */

typedef f32 Matrix4f[4][4]; /* as in 30560.c */

/* The setup being built (D_80113958); func_8010E2B8 commits it to gPlayers and GwSystem. */
typedef struct Ovl58Setup {
    /* 0x00 */ u8 port[4];      /* controller port of player i (0xFF: none yet) */
    /* 0x04 */ u8 character[4]; /* character of player i */
    /* 0x08 */ u8 cpuLevel[4];  /* CPU level index of player i (0xFF: unset) */
    /* 0x0C */ u8 handicap[4];  /* player i's starting coins (gPlayers[i].coins) */
    /* 0x10 */ u8 humans;       /* number of human players: players >= humans are CPUs */
    /* 0x11 */ u8 cpus;         /* number of CPU players (80103F38: max players - humans) */
    /* 0x12 */ u8 gameLength;   /* GwSystem.current_game_length */
    /* 0x13 */ u8 bonus;        /* flag 0x4E */
    /* 0x14 */ u8 padCount;     /* controllers inserted at start */
    /* 0x15 */ u8 unk15;
    /* 0x16 */ s16 unk16;
} Ovl58Setup; /* size = 0x18 */

/* Four s16 copied whole into a local (80103F38, 8010E2B8): D_801138E0 (the four player
   models of the scene), D_80113618/D_80113620 (rodata tables). */
typedef struct Ovl58Quad {
    /* 0x00 */ s16 v[4];
} Ovl58Quad;

/* Mode 3's record to continue (D_80113826): from the story record D_800FD8A8 (source 1) or
   the saved copy D_800FD420 (source 0, in D_8011382D); field names are D_800FD8A8's. */
typedef struct Ovl58Story {
    /* 0x00 */ u8 chapter;      /* unk10 */
    /* 0x01 */ u8 character[2]; /* unk00, unk01 */
    /* 0x03 */ u8 unk3;         /* byte 0x03 */
    /* 0x04 */ u8 unk4;         /* byte 0x0D */
    /* 0x05 */ u8 unk5;         /* unk04 */
    /* 0x06 */ u8 step;         /* unk11 */
} Ovl58Story; /* size = 7 */

/* ---- main-segment API used by 58 (not declared by the headers above) ---- */

void Hu3DCam3DToScreen(s16 camIndex, Vec* worldPos, Vec2f* outPos);
void Hu3DCamSetPositionOrientation(s16, Vec*, Vec*, Vec*);
void Hu3DCamUpdateMtx(s16 camIndex);
s32 HuGetPadInserted(s16);
f32 HuMathSin(f32);
s16 LoadFormFile(s32, s32);
s32 PlaySound(s32);
void SprAnimKill(s16 animIdx);
void espDispOff(u16);
void espDispOn(u16);
void espPosSet(u16 spriteId, s16 x, s16 y);
s16 func_8001A2F8_1AEF8(s32 arg0);
void func_8001A6BC_1B2BC(u16 spriteId, s16 arg1);
void func_8001A788_1B388(u16 spriteId, s32 arg1);
void func_8001A7C8_1B3C8(u16, f32);
void func_8001A854_1B454(u16 spriteId, s32 arg1, s32 arg2);
void func_8001A89C_1B49C(u16 spriteId, s32 arg1);
void func_8001A91C_1B51C(u16 spriteId, f32 x, f32 y);
s16 func_8001AAAC_1B6AC(s16 arg0, u16 arg1, u16 arg2);
void func_8001AC44_1B844(u16 arg0);
void func_80020070_20C70(s32);
void func_80020D20_21920(s16 arg0);
void func_80023554_24154(s16 model, s16 frame, char* part, f32 mtx[4][4]);
void func_80025830_26430(Matrix4f, f32, f32, f32);
void func_80025884_26484(Matrix4f m, f32 x, f32 y, f32 z);
void func_80025BA4_267A4(Matrix4f, Matrix4f, Matrix4f);
void func_80026D28_27928(s32);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void* func_80027154_27D54(s32, s32);
void func_80029708_2A308(s32);
void func_80029714_2A314(s16, f32, f32, f32);
void func_8002979C_2A39C(s16, f32, f32, f32);
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029A8C_2A68C(s16);
void func_80029AFC_2A6FC(s16);
void func_80029C74_2A874(s16, f32);
f32 func_80029CE4_2A8E4(s16);
f32 func_80029D0C_2A90C(s16);
s16 func_80029E14_2AA14(s16);
void func_80029FE4_2ABE4(s16, f32);
HmfMotionObj* func_8002A9F4_2B5F4(s16 arg0, char* arg1);
void func_8002C9C0_2D5C0(s16, s16);
void func_8002CA48_2D648(u8 arg0, u8 arg1, u8 arg2);
void func_8002D1EC_2DDEC(s16 arg0, u8 arg1);
void func_8002D274_2DE74(s16 arg0, u8 arg1, u8 arg2, u8 arg3);
void func_8002D2B4_2DEB4(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_8002D4D0_2E0D0(s16 n);
void func_8003B72C_3C32C(s16 arg0, s16 arg1, char* arg2, s16 arg3, s16 arg4);
s16 func_80068040_68C40(s16);
s32 func_80075390_75F90(s32);
void func_800753D4_75FD4(s32 flag);
void func_80075424_76024(s32);
s32 func_80075478_76078(s32 flag);
void func_8007954C_7A14C(s16);
void func_800795D8_7A1D8(s16 sound, s8 volume);
void func_80079614_7A214(s16 time);
s32 func_8007975C_7A35C(s16 arg0, s16 arg1);
void func_8007E128_7ED28(void);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
void func_80088604_89204(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
s16 func_800888A8_894A8(s16, s16, s16, s16, s32, s16);
void func_800890CC_89CCC(s16, s32, s32, s32);
void func_80089284_89E84(s16, s32, s32);
void func_80089308_89F08(s16, char*, s32);
s16 func_80089404_8A004(s16 win_id, u32 spriteMainFsPair, s16 arg2, s16 arg3, u16 arg4);
TextWindow* func_80089674_8A274(s16);
void func_800896DC_8A2DC(s16 winId, s16 x, s16 y);
void func_80089A48_8A648(s16, s16);
void func_80089A7C_8A67C(s16, s16);
void func_80089B2C_8A72C(s16, s16);
void func_80089C78_8A878(s16 winId, u8 arg1);
void func_80089DA0_8A9A0(s16 winId, u8 r, u8 g, u8 b);
void func_8008AD44_8B944(s16);
s16 func_8008BA30_8C630(s16 winId);
s32 func_8008BB48_8C748(s16, s16, s32);
void func_8008CCA8_8D8A8(s16);
void func_8008D974_8E574(char*, s16);
void func_8008DACC_8E6CC(s32, s16*, s32);
s32 func_8008DFC4_8EBC4(s32 x, s32 y, s32 style);
void func_8008E2DC_8EEDC(s32 winId, s32 sound);
void func_8008E4D0_8F0D0(s32 winId, s32 sound);
void func_8008E644_8F244(s32 arg0, u8 arg1);
void func_8008F624_90224(s32, s32, s32);
f32 func_800B1830_B2430(f32);
void func_800B1F50_B2B50(Matrix4f m, f32 x, f32 y, f32 z);
f32 func_800B7890_B8490(f32);
void omPrcSetStatBit(Process*, s32);
void osSyncPrintf(const char* fmt, ...);
int sprintf(char* dst, const char* fmt, ...);
void func_80023D74_24974(void*);
void func_8003B76C_3C36C(s16 arg0, s16 arg1, char* arg2, s16 arg3, s16 arg4);
s16 func_80067F4C_68B4C(s16 arg0);
void func_80029760_2A360(s16 idx, Vec* arg1);
void func_800754BC_760BC(s32 flag);
void func_8007550C_7610C(s32 flag);
void func_8007E0F8_7ECF8(u8* buf);
void func_8007E150_7ED50(void);

extern s8 ContStkX[4];
extern s8 ContStkY[4];
extern f32 D_800F8410_F9010;
extern void* D_800F93FC_F9FFC;
extern f32 D_800FA5BC_FB1BC[];
extern u8 D_800FD420_FE020[0x12];
extern u8 D_800FD425_FE025[];
extern s16 D_800FD80C_FE40C;
extern s8 D_800FD8B8_FE4B8;
extern f32 D_8010105C_101C5C;
extern f32 D_80101078_101C78;
extern u16 D_801011FC_101DFC;
extern f32 D_80101300_101F00;
extern f32 D_80102750_103350[];
extern u8 D_800FD390_FDF90[]; /* raw */
extern Vec D_800FD478_FE078; /* raw guess */
extern s16 D_800CAD94; /* raw guess */

/* 58-C */
/* A view of main's esprite slot (1AE60.c's local EspriteSlot, D_800F93FC). */
typedef struct Ovl58Esprite {
    /* 0x00 */ char pad00[0xA];
    /* 0x0A */ s16 x;
    /* 0x0C */ s16 y;
    /* 0x0E */ char pad0E[0x16];
} Ovl58Esprite; /* size = 0x24 */

/* Two s16 copied whole into a local (8010A1E8: D_80113900, the bonus panels' models). */
typedef struct Ovl58Pair {
    /* 0x00 */ s16 v[2];
} Ovl58Pair;

/* ---- 58 .data (asm, 37E240.data.s; raw types unless noted) ---- */
extern s16 D_80112B40_37E240_MinigameParkSetup;
extern s16 D_80112B42_37E242_MinigameParkSetup;
extern s16 D_80112B44_37E244_MinigameParkSetup[2];
extern s32 D_80112B48_37E248_MinigameParkSetup;
extern f32 D_80112B4C_37E24C_MinigameParkSetup[28]; /* camera positions (D_80113870 points here) */
extern s32 D_80112BBC_37E2BC_MinigameParkSetup[]; /* a table func_80112360 reads; 80102CAC sets words 0x50 and 0x6E (D_80112CFC is word 0x50) */
extern s32 D_80112BCC_37E2CC_MinigameParkSetup[10];
extern s32 D_80112BF4_37E2F4_MinigameParkSetup[66];
extern s32 D_80112CFC_37E3FC_MinigameParkSetup[410];
extern s32 D_80113364_37EA64_MinigameParkSetup[8]; /* per D_80113814 (stage): D_80112BBC[0x50] */
extern s32 D_80113384_37EA84_MinigameParkSetup[8]; /* per D_80113814: D_80112BBC[0x6E] */
extern u8 D_801133A4_37EAA4_MinigameParkSetup[16];
extern s16 D_801133B4_37EAB4_MinigameParkSetup[][2]; /* icon offsets x, y per player slot (801051BC) */
extern s16 D_801133B6_37EAB6_MinigameParkSetup[47];
extern s32 D_80113414_37EB14_MinigameParkSetup[6];
extern s32 D_8011342C_37EB2C_MinigameParkSetup[8];
extern s16 D_8011344C_37EB4C_MinigameParkSetup;
extern s16 D_8011344E_37EB4E_MinigameParkSetup[11];
extern s32 D_80113464_37EB64_MinigameParkSetup;
extern s32 D_80113468_37EB68_MinigameParkSetup[4];
extern s32 D_80113478_37EB78_MinigameParkSetup[4];
extern s32 D_80113488_37EB88_MinigameParkSetup[6];
extern char* D_801134A0_37EBA0_MinigameParkSetup[6]; /* 58-C: game-length clock part names, 3 per mode */
extern s32 D_801134B8_37EBB8_MinigameParkSetup[30];
extern s16 D_80113530_37EC30_MinigameParkSetup[2];
extern s32 D_80113534_37EC34_MinigameParkSetup[6];
extern u8 D_8011354C_37EC4C_MinigameParkSetup[8];
extern s16 D_80113554_37EC54_MinigameParkSetup;
extern s16 D_80113556_37EC56_MinigameParkSetup;
extern s16 D_80113558_37EC58_MinigameParkSetup;
extern s16 D_8011355A_37EC5A_MinigameParkSetup;
extern s32 D_8011355C_37EC5C_MinigameParkSetup[10];
extern s32 D_80113584_37EC84_MinigameParkSetup[6];
extern s32 D_8011359C_37EC9C_MinigameParkSetup[9];
extern f32 D_801135C0_37ECC0_MinigameParkSetup; /* camera fov */
extern u8 D_801135C4_37ECC4_MinigameParkSetup[12];

/* ---- 58 .rodata (C, 36DF00.c) ---- */
extern const Ovl58Quad D_80113618_37ED18_MinigameParkSetup; /* {2, 0, 3, 1}: 80103F38 panel lift-in delays (x10 frames) */
extern const Ovl58Quad D_80113620_37ED20_MinigameParkSetup; /* {0, 1, 2, 3}: lift-out delays; 8010E2B8 CPU levels */
extern const char D_80113628_37ED28_MinigameParkSetup[]; /* "p_panel" */

/* ---- 58 .bss (asm, ovl_58_bss.bss.s; raw types unless noted) ---- */
extern s16 D_80113780_37EE80_MinigameParkSetup; /* setup step (the mode loops switch on it) */
extern s16 D_80113782_37EE82_MinigameParkSetup; /* 1: the step was entered backwards (B) */
extern s16 D_80113784_37EE84_MinigameParkSetup;
extern s16 D_80113786_37EE86_MinigameParkSetup;
extern s16 D_80113788_37EE88_MinigameParkSetup;
extern s32 D_8011378C_37EE8C_MinigameParkSetup;
extern s16 D_80113790_37EE90_MinigameParkSetup; /* set by 8010FB00 when its intro is done */
extern s16 D_80113798_37EE98_MinigameParkSetup;
extern s16 D_8011379A_37EE9A_MinigameParkSetup[11];
extern f32 D_801137B0_37EEB0_MinigameParkSetup[2]; /* panel origin x, y (801051BC) */
extern Process* D_801137B8_37EEB8_MinigameParkSetup[6]; /* 5 used: 80106AF8 processes */
extern s32 D_801137D0_37EED0_MinigameParkSetup[6];
extern s32 D_801137E8_37EEE8_MinigameParkSetup[6];
extern s16 D_80113800_37EF00_MinigameParkSetup;
extern s16 D_80113802_37EF02_MinigameParkSetup;
extern s16 D_80113804_37EF04_MinigameParkSetup[4]; /* per player; -1 for CPU players */
extern s16 D_8011380C_37EF0C_MinigameParkSetup[4];
extern s16 D_80113814_37EF14_MinigameParkSetup; /* stage (board index; 6 in modes 1-3) */
extern s16 D_80113816_37EF16_MinigameParkSetup; /* -1, or the 8010B6E8 choice (2 in mode 3) */
extern s16 D_80113818_37EF18_MinigameParkSetup;
extern s16 D_8011381A_37EF1A_MinigameParkSetup; /* the controlling pad */
extern u8 D_8011381B_37EF1B_MinigameParkSetup;
extern s16 D_8011381C_37EF1C_MinigameParkSetup;
extern s16 D_8011381E_37EF1E_MinigameParkSetup;
extern s16 D_80113820_37EF20_MinigameParkSetup;
extern s16 D_80113822_37EF22_MinigameParkSetup;
extern s16 D_80113824_37EF24_MinigameParkSetup; /* mode 3: the step B returns to */
extern Ovl58Story D_80113826_37EF26_MinigameParkSetup; /* 80113826-8011382C */
extern s8 D_8011382D_37EF2D_MinigameParkSetup; /* where D_80113826 came from: 1 story record, 0 save, -1 none */
extern s16 D_8011382E_37EF2E_MinigameParkSetup[2];
extern s16 D_80113832_37EF32_MinigameParkSetup[2];
extern s16 D_80113836_37EF36_MinigameParkSetup[2][2]; /* 58-C: bonus panel sprites' screen x, y (8010B6B4) */
extern s16 D_8011383E_37EF3E_MinigameParkSetup[3];
extern s16 D_80113844_37EF44_MinigameParkSetup[3];
extern s16 D_8011384A_37EF4A_MinigameParkSetup[3];
extern s32 D_80113850_37EF50_MinigameParkSetup[2];
extern s32 D_80113858_37EF58_MinigameParkSetup[2];
extern s32 D_80113860_37EF60_MinigameParkSetup;
extern s16 D_80113864_37EF64_MinigameParkSetup;
extern s16 D_80113866_37EF66_MinigameParkSetup;
extern s16 D_80113868_37EF68_MinigameParkSetup;
extern s16 D_8011386A_37EF6A_MinigameParkSetup[3];
extern f32* D_80113870_37EF70_MinigameParkSetup;
extern s32 D_80113878_37EF78_MinigameParkSetup[5];
extern s32 D_8011388C_37EF8C_MinigameParkSetup[3];
extern s32 D_80113898_37EF98_MinigameParkSetup[2];
extern s32 D_801138A0_37EFA0_MinigameParkSetup[4];
extern s16 D_801138B0_37EFB0_MinigameParkSetup;
extern s16 D_801138B2_37EFB2_MinigameParkSetup;
extern s32 D_801138B4_37EFB4_MinigameParkSetup;
extern s16 D_801138B8_37EFB8_MinigameParkSetup;
extern s16 D_801138BA_37EFBA_MinigameParkSetup;
extern s32 D_801138BC_37EFBC_MinigameParkSetup;
extern s32 D_801138C0_37EFC0_MinigameParkSetup[2];
extern s32 D_801138C8_37EFC8_MinigameParkSetup[6];
extern Ovl58Quad D_801138E0_37EFE0_MinigameParkSetup; /* + 4 bytes unreferenced */
extern s16 D_801138EC_37EFEC_MinigameParkSetup[3];
extern s16 D_801138F2_37EFF2_MinigameParkSetup[6];
extern s16 D_801138FE_37EFFE_MinigameParkSetup;
extern Ovl58Pair D_80113900_37F000_MinigameParkSetup; /* 58-C: the two bonus-panel models (+ 4 bytes unreferenced) */
extern s16 D_80113908_37F008_MinigameParkSetup[3];
extern s16 D_8011390E_37F00E_MinigameParkSetup[5];
extern s16 D_80113918_37F018_MinigameParkSetup[7];
extern s16 D_80113926_37F026_MinigameParkSetup[2];
extern s16 D_8011392A_37F02A_MinigameParkSetup;
extern s16 D_8011392C_37F02C_MinigameParkSetup; /* 1 while 80103F38 takes the player count */
extern s32 D_80113930_37F030_MinigameParkSetup[3];
extern s16 D_8011393C_37F03C_MinigameParkSetup; /* 80103F38: the selected panel (player count - 1) */
extern s16 D_80113940_37F040_MinigameParkSetup[7];
extern s16 D_8011394E_37F04E_MinigameParkSetup[5];
extern Ovl58Setup D_80113958_37F058_MinigameParkSetup; /* 80113958-8011396F */
extern s16 D_80113970_37F070_MinigameParkSetup[11];
extern s16 D_80113986_37F086_MinigameParkSetup[2];
extern s16 D_8011398A_37F08A_MinigameParkSetup[11];
extern s16 D_801139A0_37F0A0_MinigameParkSetup; /* model motion: the panel is down */
extern s16 D_801139A8_37F0A8_MinigameParkSetup;
extern s16 D_801139AA_37F0AA_MinigameParkSetup;
extern s16 D_801139AC_37F0AC_MinigameParkSetup;
extern s16 D_801139AE_37F0AE_MinigameParkSetup;
extern s16 D_801139B0_37F0B0_MinigameParkSetup;
extern s16 D_801139B2_37F0B2_MinigameParkSetup[4];
extern s16 D_801139BA_37F0BA_MinigameParkSetup;
extern s16 D_801139BC_37F0BC_MinigameParkSetup;
extern s16 D_801139BE_37F0BE_MinigameParkSetup;
extern s16 D_801139C0_37F0C0_MinigameParkSetup[2]; /* 58-C: [0] bonus model motion (panel down) */
extern s16 D_801139C4_37F0C4_MinigameParkSetup;
extern s16 D_801139C6_37F0C6_MinigameParkSetup[9];
extern s32 D_801139D8_37F0D8_MinigameParkSetup[135];
extern f32 D_80113BF4_37F2F4_MinigameParkSetup; /* camera far */
extern s32 D_80113BF8_37F2F8_MinigameParkSetup;
extern s32 D_80113BFC_37F2FC_MinigameParkSetup[3];
extern s32 D_80113C08_37F308_MinigameParkSetup[135];
extern f32 D_80113E24_37F524_MinigameParkSetup; /* camera near */

/* ---- 58 functions (source order) ---- */

void func_80102800_36DF00_MinigameParkSetup(void);
void func_80102A60_36E160_MinigameParkSetup(void);
void func_80102CAC_36E3AC_MinigameParkSetup(void);
void func_80102F00_36E600_MinigameParkSetup(void);
void func_80103140_36E840_MinigameParkSetup(void);
void func_801033E0_36EAE0_MinigameParkSetup(void);
void func_8010395C_36F05C_MinigameParkSetup(void);
void func_80103A88_36F188_MinigameParkSetup(void);
void func_80103ABC_36F1BC_MinigameParkSetup(void);
s32 func_80103F38_36F638_MinigameParkSetup(void);
void func_801051BC_3708BC_MinigameParkSetup(s16 sprite, s16 slot, s16 mode);
s32 func_801052B4_3709B4_MinigameParkSetup(void);
void func_80106A00_372100_MinigameParkSetup(s32, s32);
void func_80106AB4_3721B4_MinigameParkSetup(s32, s16);
void func_80106AF8_3721F8_MinigameParkSetup(void);
void func_80107014_372714_MinigameParkSetup(s32, s8);
void func_80107030_372730_MinigameParkSetup(s8, s16);
void func_801070B0_3727B0_MinigameParkSetup(s8, s16);
s16 func_801070E0_3727E0_MinigameParkSetup(s32);
void func_801070FC_3727FC_MinigameParkSetup(s32, s16);
s16 func_80107118_372818_MinigameParkSetup(s32);
void func_80107134_372834_MinigameParkSetup(s32, s8);
void func_80107180_372880_MinigameParkSetup(void);
void func_801074CC_372BCC_MinigameParkSetup(s32, f32, f32, f32);
void func_801075C8_372CC8_MinigameParkSetup(s32, f32, f32, f32);
void func_80107604_372D04_MinigameParkSetup(void);
s32 func_80107644_372D44_MinigameParkSetup(s16);
void func_80108BA8_3742A8_MinigameParkSetup(s32);
void func_80108C0C_37430C_MinigameParkSetup(void);
void func_8010903C_37473C_MinigameParkSetup(void);
s32 func_80109478_374B78_MinigameParkSetup(void);
void func_8010A02C_37572C_MinigameParkSetup(s16 dir); /* panel slides out: 0 forward, 1 back */
s32 func_8010A1E8_3758E8_MinigameParkSetup(void);
void func_8010B6B4_376DB4_MinigameParkSetup(s16 spr, s16* out); /* esprite x, y */
s32 func_8010B6E8_376DE8_MinigameParkSetup(void);
void func_8010C4B4_377BB4_MinigameParkSetup(s32);
s32 func_8010C6C8_377DC8_MinigameParkSetup(void);
s32 func_8010D260_378960_MinigameParkSetup(void);
void func_8010E1F0_3798F0_MinigameParkSetup(s16);
void func_8010E2B8_3799B8_MinigameParkSetup(void);
void func_8010E460_379B60_MinigameParkSetup(void);
void func_8010ED54_37A454_MinigameParkSetup(void);
void func_8010EEF8_37A5F8_MinigameParkSetup(void*);
void func_8010EF58_37A658_MinigameParkSetup(void);
void func_8010F0A4_37A7A4_MinigameParkSetup(void);
void func_8010F358_37AA58_MinigameParkSetup(void);
void func_8010FB00_37B200_MinigameParkSetup(void);
void func_80110278_37B978_MinigameParkSetup(void);
void func_80110350_37BA50_MinigameParkSetup(s32);
s32 func_801103A4_37BAA4_MinigameParkSetup(void);
s32 func_8011042C_37BB2C_MinigameParkSetup(void);
void func_801104B4_37BBB4_MinigameParkSetup(s32);
void func_801104DC_37BBDC_MinigameParkSetup(void);
void func_801104FC_37BBFC_MinigameParkSetup(s16 model, s16 sprite, const char* hook); /* sprite to a model hook */
void func_801105B8_37BCB8_MinigameParkSetup(s16, s16, s32, s32);
void func_8011060C_37BD0C_MinigameParkSetup(s32, void*, s16, s16);
s16 func_80110678_37BD78_MinigameParkSetup(s16 cur, s16 n, s16 stickX, s16 stickY); /* -1: no move */
void func_801109C8_37C0C8_MinigameParkSetup(void*);
void func_80110A28_37C128_MinigameParkSetup(void);
void func_80110AF0_37C1F0_MinigameParkSetup(s16);
void func_80110B98_37C298_MinigameParkSetup(s16, s16, s16, void*);
void func_80111328_37CA28_MinigameParkSetup(void);
void func_801115BC_37CCBC_MinigameParkSetup(void);
void func_8011170C_37CE0C_MinigameParkSetup(s16);
void func_80111744_37CE44_MinigameParkSetup(s16*);
void func_80111750_37CE50_MinigameParkSetup(s16);
void func_8011175C_37CE5C_MinigameParkSetup(s16);
void func_80111768_37CE68_MinigameParkSetup(void);
void func_80111D8C_37D48C_MinigameParkSetup(void);
void func_80112360_37DA60_MinigameParkSetup(s32 *arg0);
void func_80112454_37DB54_MinigameParkSetup(s32* table, s16 index, s16 model);
void func_80112810_37DF10_MinigameParkSetup(s16, void*, s32);
void func_80112910_37E010_MinigameParkSetup(s16, s32);
void func_80112950_37E050_MinigameParkSetup(void);

#endif /* _OVL_58_H */
