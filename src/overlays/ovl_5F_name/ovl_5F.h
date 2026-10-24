#ifndef _OVL_5F_H
#define _OVL_5F_H

/* Overlay 5F: the minigame instructions screen (MP3 `inst`, MP1 ovl_6F_MinigameInstructions;
   overlay 60 is a near copy). Retail's overlay is three files: 3AB9A0.c (the entry point),
   3AB9D0.c (80102830-8011303C) and 3BC210.c (80113070, 801136C4). Every function is global.
   .data and .bss stay asm (declared here); each file's .rodata is carved.
   Prototypes past 80105B94 came from the asm's register use only: the fork that owns a
   function fixes its line. */

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

/* One minigame's demo on the instructions screen (D_80113C70, 30 entries; selected by
   D_80114F50). The two object functions are omAddObj callbacks of the demo's players. */
typedef struct Ovl5FDemo {
    /* 0x00 */ void (*setup)(void);
    /* 0x04 */ void (*unk04)(void);
    /* 0x08 */ void (*unk08)(omObjData*);
    /* 0x0C */ void (*unk0C)(omObjData*);
    /* 0x10 */ s16 unk10;
} Ovl5FDemo; /* size = 0x14 */

/* A model's float work (omObjData.unk_50 of func_80103608 / func_8010352C: a falling,
   swaying model). */
typedef struct Ovl5FFallWork {
    /* 0x00 */ Vec pos;
    /* 0x0C */ f32 scale;
    /* 0x10 */ f32 baseX;
    /* 0x14 */ f32 vel;
    /* 0x18 */ f32 floor;
    /* 0x1C */ f32 angle;
    /* 0x20 */ f32 angleVel;
    /* 0x24 */ s32 model; /* read as (s16): lh 0x26 */
} Ovl5FFallWork; /* size = 0x28 */

/* What main's D_800FC890 points at while 5F runs (func_80103994 moves the host off screen). */
typedef struct Ovl5FHostWork {
    /* 0x00 */ Vec pos;
    /* 0x0C */ f32 angle;
    /* 0x10 */ Vec rot;
    /* 0x1C */ u16 model;
    /* 0x1E */ s16 count;
    /* 0x20 */ char unk20[8];
    /* 0x28 */ f32 step;
    /* 0x2C */ char unk2C[4];
    /* 0x30 */ s16 mes[3]; /* the pages' messages while flag 0xC is set */
} Ovl5FHostWork;

/* A view of main's esprite slot (1AE60.c's local EspriteSlot, D_800F93FC). */
typedef struct Ovl5FEsprite {
    /* 0x00 */ char pad00[4];
    /* 0x04 */ s16 group;
    /* 0x06 */ char pad06[4];
    /* 0x0A */ s16 x;
    /* 0x0C */ s16 y;
    /* 0x0E */ char pad0E[0x16];
} Ovl5FEsprite; /* size = 0x24 */

/* ---- main-segment API used by 5F ---- */

void func_80089544_8A144(s16, s16); /* remove a window's sprite */
TextWindow* func_80089674_8A274(s16);
void func_80067EF8_68AF8(s32);
void func_800727F0_733F0(void);
void ExecBoardScene(void*, s16);
void HmfModelObjAttrSet(s16, s32, s32);
void Hu3DCam3DToScreen(s16 camIndex, Vec* worldPos, Vec2f* outPos);
f32 HuMathSin(f32);
void HuVecCopyXYZ(Vec*, f32, f32, f32);
f32 HuVecGetLength3F(Vec*);
s16 LoadFormFile(s32, s32);
s32 PlaySound(s32);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprAttrReset(s16 grpIdx, s16 idx, s32 flag);
void SprAttrSet(s16, s16, s32);
s16 SprCreate(s32 num, s32 attr);
void SprPosSet(s16 grpIdx, s16 idx, s16 x, s16 y);
void SprScaleSet(s16 group, s16 member, f32 x, f32 y);
void espDispOff(u16);
void espDispOn(u16);
void espPosSet(u16 spriteId, s16 x, s16 y);
void func_8000C460_D060(void);
u16 func_80018A30_19630(s32 arg0, s32 arg1); /* model from a file */
s16 func_8001A2F8_1AEF8(s32 arg0);
void func_8001A6BC_1B2BC(u16 spriteId, s16 arg1);
void func_8001A708_1B308(u16, u16);
void func_8001A854_1B454(u16 spriteId, s32 arg1, s32 arg2);
void func_8001A89C_1B49C(u16 spriteId, s32 arg1);
void func_8001A91C_1B51C(u16 spriteId, f32 x, f32 y);
void func_8001A96C_1B56C(u16, u8, u8, u8);
s32 func_8001AAAC_1B6AC(s16 arg0, u16 arg1, u16 arg2); /* s16 elsewhere; 5F's callers extend the result themselves */
void func_80020070_20C70(s32);
void func_80020D20_21920(s16 arg0);
void func_80023DAC_249AC(s16 arg0, char* arg1, s16 arg2, char* arg3);
void* func_80027154_27D54(s32, s32); /* HuMemAllocTag */
s32 func_80027D3C_2893C(s16); /* model copy (5F: the result is stored unextended) */
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void func_8002979C_2A39C(s16, f32, f32, f32); /* model rotation */
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029A8C_2A68C(s16);
void func_80029AFC_2A6FC(s16);
void func_80029BF0_2A7F0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void func_80029C74_2A874(s16, f32);
f32 func_80029CE4_2A8E4(s16);
f32 func_80029D0C_2A90C(s16); /* motion length */
f32 func_80029E3C_2AA3C(s16);
void func_80029FE4_2ABE4(s16, f32);
void func_8002A00C_2AC0C(s16);
void func_8002AC10_2B810(s16, f32, f32, s32);
void func_8002BED4_2CAD4(s16 arg0, f32 arg1, f32 arg2, u16 arg3, u16 arg4, char* arg5, u8 arg6);
void func_8002C524_2D124(s16, s16, s16);
void func_8002C570_2D170(s16);
void func_8002C628_2D228(s16 arg0, s16 arg1, char* arg2); /* attach to a model's hook node */
s32 func_8002C8B8_2D4B8(void*, s16); /* s16 in 274D0.c; retail uses the result unextended */
void func_8002C9C0_2D5C0(s16, s16);
f32 func_8002CA14_2D614(s32);
void func_8002D0A0_2DCA0(s16, u8); /* model alpha */
void func_8002D124_2DD24(s16 index);
void func_8002D4D0_2E0D0(s16 n);
f32 func_8002D958_2E558(f32);
s16 func_80038398_38F98(HmfData*, char*);
void func_8003E4F4_3F0F4(s16 arg0, u8 arg1, u8 arg2);
s32 func_8004E94C_4F54C(void);
s32 func_80059FD0_5ABD0(s32); /* the player's rank */
void* func_80068CD4_698D4(s32 stringIndex);
void func_80068D24_69924(void* file);
void func_80069698_6A298(void);
s16 func_8006A67C_6B27C(GAMEMES*, char*, u8, s16, s16);
u16 func_80078EA8_79AA8(void);
void func_8008221C_82E1C(s16 group, s16 member, f32 arg2);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
void func_800822A8_82EA8(s16 group, s16 member, u16 arg2, s32 arg3);
void func_800824F4_830F4(s16 group, s16 member, s16 arg2);
void func_800890CC_89CCC(s16, s32, s32, s32);
void func_80089308_89F08(s16, char*, s8); /* window message argument (a name string) */
s16 func_80089404_8A004(s16 win_id, u32 spriteMainFsPair, s16 arg2, s16 arg3, u16 arg4);
s16 func_8008BA30_8C630(s16 winId);
void func_8008DF9C_8EB9C(s32 winId, u16 btn);
s32 func_8008DFC4_8EBC4(s32 x, s32 y, s32 style);
void func_8008E2DC_8EEDC(s32 winId, s32 sound);
void func_8008E4D0_8F0D0(s32 winId, s32 sound);
void func_8008F624_90224(s32, s32, s32); /* wipe colour */
void func_80096188_96D88(u8* code, u16* outbuf, s32 outbufWidth, u8* workbuf);
void func_80096708_97308(void* header);
void func_80096C10_97810(u8 alpha);
void func_800B0EF0_B1AF0(void*, s32, s32); /* bzero-like fill */
void func_800B1F50_B2B50(f32 (*)[4], f32, f32, f32);
void func_800B2060_B2C60(f32 (*)[4], f32, f32, f32); /* 274D0.c's prototype */
f32 func_800B75A8_B81A8(f32, f32);
f32 func_800B7890_B8490(f32); /* cos */
void omDelObj(omObjData*);
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
void osSyncPrintf(const char* fmt, ...);

/* main bss words splat folded into a neighbour (named in symbol_addrs.txt by 5F-A) */
extern s32 D_800F9910_FA510;   /* flag bits; bit 0 = instructions skipped (D_800F95D4 + 0x33C) */
extern void* D_800FA640_FB240[4]; /* per-player minigame data (D_800FA63E + 2) */
extern Ovl5FHostWork* D_800FC890_FD490; /* (D_800FC88C + 4); 80103C84 reads s16s at 0x30-0x34 (message ids) */
extern s32 D_800FC8A0_FD4A0;   /* (D_800FC89C + 4) */

extern s8 ContStkX[4];
extern s8 ContStkY[4];
extern u8 D_80102708_103308;
extern u8 D_80102720_103320;
extern u8 D_800FA656; /* minigame variant */
extern u16 D_800F9208_F9E08; /* the battle's coin pot */
extern Ovl5FEsprite* D_800F93FC_F9FFC; /* EspriteSlot* (1AE60.c) */
extern u16 D_800CAFD8[]; /* item ids */

/* ---- 5F .data (asm, 3BC8A0.data.s) ---- */

extern board_overlay_entrypoint D_80113700_3BC8A0_name_5F[];
extern s16 D_80113710_3BC8B0_name_5F[][4]; /* per minigame: two instruction messages, the
    extra message (-1: none; [2]) and, indexed by D_80114DC6 instead, the variant message ([3]) */
extern f32 D_80113978_3BCB18_name_5F; /* the title face texture scroll */
extern s32 D_8011397C_3BCB1C_name_5F[10]; /* item icon sprite files, by item id */
extern s32 D_801139A4_3BCB44_name_5F[5][2]; /* item icon offsets (x, y) */
extern u16 D_801139CC_3BCB6C_name_5F[4]; /* lhu:1 addiu:1 */
extern f32 D_801139D4_3BCB74_name_5F; /* addiu:1 lwc1:1 */
extern f32 D_801139D8_3BCB78_name_5F; /* lwc1:2 */
extern f32 D_801139DC_3BCB7C_name_5F[33]; /* lwc1:1 */
extern s32 D_80113A60_3BCC00_name_5F[28]; /* addiu:1 */
extern s32 D_80113AD0_3BCC70_name_5F[21]; /* addiu:1 */
extern s32 D_80113B24_3BCCC4_name_5F[5]; /* addiu:1 */
extern s32 D_80113B38_3BCCD8_name_5F[6]; /* addiu:1 */
extern s16 D_80113B50_3BCCF0_name_5F[5]; /* addiu:3 */
extern s16 D_80113B5A_3BCCFA_name_5F[15]; /* sh:1 */
extern s32 D_80113B78_3BCD18_name_5F[62]; /* addiu:1 */
extern Ovl5FDemo D_80113C70_3BCE10_name_5F[30];
extern s32 D_80113EC8_3BD068_name_5F[4]; /* lw:2 sw:4 */
extern u16 D_80113ED8_3BD078_name_5F[6]; /* lhu:1 */
extern s32 D_80113EE4_3BD084_name_5F[6]; /* addiu:1 */
extern s32 D_80113EFC_3BD09C_name_5F[3]; /* addiu:1 */
extern u16 D_80113F08_3BD0A8_name_5F[6]; /* lhu:1 */
extern u16 D_80113F14_3BD0B4_name_5F[6]; /* lhu:1 */
extern u16 D_80113F20_3BD0C0_name_5F[6]; /* lhu:1 */
extern u16 D_80113F2C_3BD0CC_name_5F[12]; /* lhu:1 */
extern s32 D_80113F44_3BD0E4_name_5F; /* lw:1 */
extern s32 D_80113F48_3BD0E8_name_5F; /* lw:1 */
extern s32 D_80113F4C_3BD0EC_name_5F[16]; /* lw:1 */
extern s16 D_80113F8C_3BD12C_name_5F[6]; /* lh:1 */
extern s32 D_80113F98_3BD138_name_5F[3]; /* addiu:1 */
extern s32 D_80113FA4_3BD144_name_5F[6]; /* lw:1 */
extern f32 D_80113FBC_3BD15C_name_5F[8]; /* swc1:1 addiu:1 */
extern u8 D_80113FDC_3BD17C_name_5F[4]; /* lb:1 sb:1 */
extern u16 D_80113FE0_3BD180_name_5F[14]; /* lhu:1 */
extern s32 D_80113FFC_3BD19C_name_5F[6][9][2]; /* per character: {file, 0} pairs (5F-E: 80110480); splat labels D_80114004-D_80114024 are its fields */
extern char* D_801141A0_3BD340_name_5F[6][2]; /* per character: the two forms' model part names (5F-E: 80110480; D_801141A4 is [0][1]) */
extern char* D_801141D0_3BD370_name_5F[6][2]; /* per character: the hook nodes (5F-E; D_801141D4 is [0][1]) */
extern s32 D_80114204_3BD3A4_name_5F[6][2]; /* per character: CPU model file (5F-E) */
extern u16 D_80114230_3BD3D0_name_5F[6]; /* lhu:1 */
extern u16 D_8011423C_3BD3DC_name_5F[10]; /* lhu:1 */
extern u8 D_80114250_3BD3F0_name_5F[76]; /* lbu:1 */
extern s32 D_8011429C_3BD43C_name_5F[39]; /* addiu:1 */
extern s32 D_80114338_3BD4D8_name_5F[90]; /* addiu:1 */
extern s32 D_801144A0_3BD640_name_5F[584]; /* addiu:1 */

/* ---- 5F .bss (asm, ovl_5F_bss.bss.s) ---- */

extern s16 D_80114DC0_3BDF60_name_5F; /* the minigame (GwSystem.chosenMinigameIndex - 1) */
extern s16 D_80114DC2_3BDF62_name_5F; /* its type (D_800CAD90[minigame].unk_04's high byte): 3 = battle?, 4-5 = 1P */
extern s16 D_80114DC4_3BDF64_name_5F; /* the first player in group 0 */
extern s16 D_80114DC6_3BDF66_name_5F; /* the variant's message row (func_80103C84) */
extern s16 D_80114DC8_3BDF68_name_5F[6]; /* models: [0] backdrop, [1]-[2] title, [3]-[5] frame */
extern omObjData* D_80114DD8_3BDF78_name_5F[4]; /* the demo players' objects (asm labels DDC, DE0, DE4 are [1]-[3]) */
/* 80114DE8-80114DEF: the rest of asm label D_80114DE4 (12 bytes): 5F-B */
extern s32 D_80114DF0_3BDF90_name_5F; /* addiu:4 sw:1 */
extern s32 D_80114DF4_3BDF94_name_5F[2]; /* addiu:1 */
extern omObjData* D_80114DFC_3BDF9C_name_5F[5]; /* item icons / players' marker objects */
extern u16 D_80114E10_3BDFB0_name_5F; /* full-screen sprite (fades in) */
extern u16 D_80114E12_3BDFB2_name_5F; /* sprite shown over a model */
extern u16 D_80114E14_3BDFB4_name_5F;
extern u16 D_80114E16_3BDFB6_name_5F; /* named by 5F-A (a separate variable: retail does not share its address) */
extern s16 D_80114E18_3BDFB8_name_5F; /* model */
extern u16 D_80114E1A_3BDFBA_name_5F; /* blinking sprite */
extern s16 D_80114E1C_3BDFBC_name_5F; /* its process runs while set */
extern s16 D_80114E1E_3BDFBE_name_5F; /* the host model */
extern s16 D_80114E20_3BDFC0_name_5F[5]; /* its motions */
extern s16 D_80114E2A_3BDFCA_name_5F; /* the demo screen model */
extern s16 D_80114E2C_3BDFCC_name_5F; /* model (battle / some minigames) */
extern s16 D_80114E2E_3BDFCE_name_5F[5]; /* item icon sprites */
extern s16 D_80114E38_3BDFD8_name_5F; /* selected item icon */
extern u16 D_80114E3A_3BDFDA_name_5F; /* coin count shown (battle pot) */
extern s16 D_80114E3C_3BDFDC_name_5F; /* the instructions window */
extern s16 D_80114E3E_3BDFDE_name_5F[4]; /* its button sprites */
extern s16 D_80114E46_3BDFE6_name_5F; /* coin counter sprite group */
extern s16 D_80114E48_3BDFE8_name_5F; /* its show/hide state */
extern s16 D_80114E4A_3BDFEA_name_5F; /* set: the player skipped to the minigame (START) */
extern void* D_80114E4C_3BDFEC_name_5F; /* the minigame's demo files */
extern void* D_80114E50_3BDFF0_name_5F;
extern void* D_80114E54_3BDFF4_name_5F;
extern s32 D_80114E58_3BDFF8_name_5F[2]; /* addiu:2 */
extern s32 D_80114E60_3BE000_name_5F[6]; /* addiu:3 */
extern s32 D_80114E78_3BE018_name_5F[16]; /* addiu:2 */
extern f32 D_80114EB8_3BE058_name_5F; /* swc1:2 lwc1:2 */
extern f32 D_80114EBC_3BE05C_name_5F[6]; /* swc1:2 lwc1:1 */
extern s32 D_80114ED4_3BE074_name_5F[27]; /* addiu:1 */
extern s32 D_80114F40_3BE0E0_name_5F[4]; /* sw:1 lw:1 */
extern s32 D_80114F50_3BE0F0_name_5F[4]; /* lw:38 sw:1 */
extern s16 D_80114F60_3BE100_name_5F[8]; /* lh:2 sh:1 */
extern s16 D_80114F70_3BE110_name_5F;
extern s16 D_80114F72_3BE112_name_5F; /* sh:1 lh:1 lhu:1 */
extern s16 D_80114F74_3BE114_name_5F; /* sh:1 lh:1 */

/* 5F-E */

#include "game/malloc.h"

/* A demo player's work (D_800FA640[player], main's per-player minigame data, as 5F-E's demos
   use it; 0x35 and 0x6D are read as bytes elsewhere). */
typedef struct Ovl5FDemoPlayer {
    /* 0x00 */ Vec pos;
    /* 0x0C */ char unk0C[4];
    /* 0x10 */ f32 scale;
    /* 0x14 */ Vec rot;
    /* 0x20 */ char unk20[0x14];
    /* 0x34 */ s16 model;
    /* 0x36 */ s16 unk36; /* motions */
    /* 0x38 */ s16 unk38;
    /* 0x3A */ s16 unk3A;
    /* 0x3C */ s16 unk3C;
    /* 0x3E */ s16 unk3E;
    /* 0x40 */ s16 unk40;
    /* 0x42 */ char unk42[0xA];
    /* 0x4C */ s16 unk4C; /* forms */
    /* 0x4E */ s16 unk4E;
    /* 0x50 */ s16 unk50;
    /* 0x52 */ char unk52[0x1A];
    /* 0x6C */ u16 sprite; /* esprite of the button demo (80112A1C) */
    /* 0x6E */ char unk6E[0x1E];
    /* 0x8C */ s16 unk8C;
    /* 0x8E */ char unk8E[6];
    /* 0x94 */ f32 unk94;
} Ovl5FDemoPlayer;

#define DEMO_PLAYER(i) ((Ovl5FDemoPlayer*)D_800FA640_FB240[i])
/* D_800FA640[team] as a two-player team demo uses it (801116B0 / 80111A00): one shared model
   and two riders. */
typedef struct Ovl5FPairDemo {
    /* 0x00 */ Vec pos;
    /* 0x0C */ char unk0C[8];
    /* 0x14 */ Vec rot;
    /* 0x20 */ char unk20[0x14];
    /* 0x34 */ s16 model;
    /* 0x36 */ s16 unk36[2]; /* the riders' motions */
    /* 0x3A */ s16 unk3A[2];
    /* 0x3E */ s16 unk3E[2];
    /* 0x42 */ s16 unk42[2];
    /* 0x46 */ char unk46[6];
    /* 0x4C */ s16 unk4C[2]; /* the riders' forms */
    /* 0x50 */ s16 unk50[2];
    /* 0x54 */ char unk54[0x38];
    /* 0x8C */ s16 player[2]; /* the riders */
    /* 0x90 */ s16 unk90; /* button presses */
    /* 0x92 */ s16 unk92; /* the riders' mean stick x */
    /* 0x94 */ f32 unk94; /* 0: forms not shown yet */
} Ovl5FPairDemo;

#define PAIR_DEMO(i) ((Ovl5FPairDemo*)D_800FA640_FB240[i])

/* D_800FA640[team] in the two-rider pump demo (80112080 / 801123E4): a base form and two riders
   whose motions run in opposite directions. */
typedef struct Ovl5FPumpDemo {
    /* 0x00 */ Vec pos;
    /* 0x0C */ char unk0C[4];
    /* 0x10 */ f32 scale;
    /* 0x14 */ Vec rot;
    /* 0x20 */ char unk20[0x14];
    /* 0x34 */ s16 model;
    /* 0x36 */ s16 unk36[2]; /* the riders' motions */
    /* 0x3A */ char unk3A[0x12];
    /* 0x4C */ s16 unk4C; /* the base form */
    /* 0x4E */ char unk4E[4];
    /* 0x52 */ s16 unk52[2]; /* the riders' forms */
    /* 0x56 */ char unk56[0x36];
    /* 0x8C */ s16 player[2]; /* the riders */
    /* 0x90 */ s16 unk90; /* direction */
    /* 0x92 */ s16 unk92; /* the riders' mean stick x */
    /* 0x94 */ f32 unk94; /* rider 0's motion time */
    /* 0x98 */ f32 unk98; /* rider 1's (and the base's) motion time */
    /* 0x9C */ f32 unk9C; /* speed */
} Ovl5FPumpDemo;

#define PUMP_DEMO(i) ((Ovl5FPumpDemo*)D_800FA640_FB240[i])

/* func_80108D50's work: a form attached to a model's hook node */
typedef struct Ovl5FHookWork {
    /* 0x00 */ s32 form;
    /* 0x04 */ s32 model;
    /* 0x08 */ const char* hook;
} Ovl5FHookWork;

#ifndef ABS
#define ABS(x) ((x) < 0 ? -(x) : (x))
#endif

/* main's per-character data (19BF0.c's ActorCharData, 0x18 bytes each) */
typedef struct Ovl5FCharData {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 unk_04; /* the character's file directory */
    /* 0x08 */ s32 unk_08; /* its model file */
    /* 0x0C */ char unk_0C[0xC];
} Ovl5FCharData;
extern Ovl5FCharData D_800CD438_CE038[];

/* ---- 5F functions (source order) ---- */

void func_80102800_3AB9A0_name_5F(void);
void func_80102830_3AB9D0_name_5F(void);
void func_80102A14_3ABBB4_name_5F(void);
void func_80102AF0_3ABC90_name_5F(void);
void func_8010352C_3AC6CC_name_5F(omObjData*);
void func_80103608_3AC7A8_name_5F(omObjData*);
void func_80103778_3AC918_name_5F(omObjData*);
void func_8010382C_3AC9CC_name_5F(omObjData*);
void func_801038D4_3ACA74_name_5F(omObjData*);
void func_80103994_3ACB34_name_5F(omObjData*);
void func_80103B78_3ACD18_name_5F(omObjData*);
void func_80103C84_3ACE24_name_5F(s16, s32);
void func_801040D0_3AD270_name_5F(omObjData*);
void func_801041C4_3AD364_name_5F(void);
void func_80104280_3AD420_name_5F(omObjData*);
void func_8010433C_3AD4DC_name_5F(void);
void func_80104490_3AD630_name_5F(omObjData*);
void func_8010456C_3AD70C_name_5F(s32, s32);
void func_80104650_3AD7F0_name_5F(void);
void func_801046A4_3AD844_name_5F(void);
void func_801048F0_3ADA90_name_5F(void);
void func_801049F4_3ADB94_name_5F(void);
void func_80104D08_3ADEA8_name_5F(omObjData*);
void func_80104DA8_3ADF48_name_5F(s32, s32, f32, f32, f32);
void func_80104E98_3AE038_name_5F(s32);
s32 func_80104F18_3AE0B8_name_5F(s32);
s32 func_80105008_3AE1A8_name_5F(s32, s32);
s32 func_801050DC_3AE27C_name_5F(s32);
void func_80105110_3AE2B0_name_5F(omObjData*);
void func_80105258_3AE3F8_name_5F(void);
void func_801053F0_3AE590_name_5F(void);
void func_801054EC_3AE68C_name_5F(void);
void func_801056A8_3AE848_name_5F(void);
void func_8010578C_3AE92C_name_5F(void);
void func_80105860_3AEA00_name_5F(void);
s32 func_80105A14_3AEBB4_name_5F(void);
s32 func_80105A54_3AEBF4_name_5F(void);
void func_80105AB8_3AEC58_name_5F(void);
void func_80105B94_3AED34_name_5F(void);
void func_801072C8_3B0468_name_5F(s16, void*, void*, void*);
void func_80107C84_3B0E24_name_5F(s32);
void func_80107F74_3B1114_name_5F(void);
void func_80107FE0_3B1180_name_5F(void);
void func_80108170_3B1310_name_5F(void);
void func_80108458_3B15F8_name_5F(void);
void func_801085A0_3B1740_name_5F(s32);
void func_8010879C_3B193C_name_5F(s32, s32);
void func_8010881C_3B19BC_name_5F(s32);
void func_80108AEC_3B1C8C_name_5F(void);
s32 func_80108B80_3B1D20_name_5F(s32, s32);
s32 func_80108C24_3B1DC4_name_5F(s32, s32);
s32 func_80108C8C_3B1E2C_name_5F(s32, s32);
void func_80108D50_3B1EF0_name_5F(omObjData*);
f32 func_80108DCC_3B1F6C_name_5F(s32, s32, s32);
void func_80108E50_3B1FF0_name_5F(s32);
void func_801092B0_3B2450_name_5F(omObjData*);
void func_8010938C_3B252C_name_5F(s32);
void func_801093D4_3B2574_name_5F(s32);
void func_80109424_3B25C4_name_5F(s32);
void func_8010946C_3B260C_name_5F(s32);
void func_801094B4_3B2654_name_5F(s32);
void func_801094F4_3B2694_name_5F(s32, s32);
void func_801098FC_3B2A9C_name_5F(void);
void func_80109988_3B2B28_name_5F(void);
void func_80109A04_3B2BA4_name_5F(void);
void func_80109A80_3B2C20_name_5F(omObjData*);
void func_80109FA0_3B3140_name_5F(omObjData*);
void func_8010A000_3B31A0_name_5F(void);
void func_8010A038_3B31D8_name_5F(void);
void func_8010A0C4_3B3264_name_5F(void);
void func_8010A1A0_3B3340_name_5F(void);
void func_8010A2B0_3B3450_name_5F(void);
void func_8010A2EC_3B348C_name_5F(omObjData*);
void func_8010A45C_3B35FC_name_5F(void);
void func_8010A4F0_3B3690_name_5F(void);
void func_8010A628_3B37C8_name_5F(void);
void func_8010A818_3B39B8_name_5F(omObjData*);
void func_8010AAA0_3B3C40_name_5F(omObjData*);
void func_8010AC44_3B3DE4_name_5F(void);
void func_8010AEF8_3B4098_name_5F(void);
void func_8010AF84_3B4124_name_5F(omObjData*);
void func_8010B168_3B4308_name_5F(omObjData*);
void func_8010B30C_3B44AC_name_5F(omObjData*);
void func_8010B33C_3B44DC_name_5F(void);
void func_8010B460_3B4600_name_5F(void);
void func_8010B4F0_3B4690_name_5F(omObjData*);
void func_8010B624_3B47C4_name_5F(void);
void func_8010B798_3B4938_name_5F(omObjData*);
void func_8010BA24_3B4BC4_name_5F(void);
void func_8010BCF0_3B4E90_name_5F(omObjData*);
void func_8010C2A8_3B5448_name_5F(omObjData*);
void func_8010C40C_3B55AC_name_5F(void);
void func_8010C61C_3B57BC_name_5F(omObjData*);
void func_8010CD08_3B5EA8_name_5F(void);
void func_8010CFB8_3B6158_name_5F(void);
void func_8010D098_3B6238_name_5F(omObjData*);
void func_8010D640_3B67E0_name_5F(void);
void func_8010D798_3B6938_name_5F(omObjData*);
void func_8010DC40_3B6DE0_name_5F(void);
void func_8010DF10_3B70B0_name_5F(omObjData*);
void func_8010E65C_3B77FC_name_5F(void);
void func_8010E844_3B79E4_name_5F(void);
void func_8010E920_3B7AC0_name_5F(omObjData*);
void func_8010EEB4_3B8054_name_5F(void);
void func_8010F0C8_3B8268_name_5F(void);
void func_8010F1A4_3B8344_name_5F(omObjData*);
void func_8010F488_3B8628_name_5F(s32);
void func_8010F578_3B8718_name_5F(s32);
void func_8010F668_3B8808_name_5F(void);
void func_8010F8BC_3B8A5C_name_5F(omObjData*);
void func_8010FDD8_3B8F78_name_5F(void);
void func_80110050_3B91F0_name_5F(omObjData*);
void func_80110480_3B9620_name_5F(void);
void func_80110784_3B9924_name_5F(omObjData*);
void func_80110F2C_3BA0CC_name_5F(void);
void func_8011126C_3BA40C_name_5F(void);
void func_8011137C_3BA51C_name_5F(omObjData*);
void func_801116B0_3BA850_name_5F(void);
void func_801119A8_3BAB48_name_5F(void);
void func_80111A00_3BABA0_name_5F(omObjData*);
void func_80112080_3BB220_name_5F(void);
void func_8011238C_3BB52C_name_5F(void);
void func_801123E4_3BB584_name_5F(omObjData*);
void func_80112A1C_3BBBBC_name_5F(void);
void func_80112B20_3BBCC0_name_5F(omObjData*);
void func_80112C64_3BBE04_name_5F(void);
void func_80112E68_3BC008_name_5F(omObjData*);
void func_80112FE8_3BC188_name_5F(void);
void func_80113004_3BC1A4_name_5F(void);
void func_80113020_3BC1C0_name_5F(void);
void func_8011303C_3BC1DC_name_5F(void);
void func_80113070_3BC210_name_5F(s32);
void func_801136C4_3BC864_name_5F(s32);

#endif
