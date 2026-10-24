#ifndef _OVL_60_H
#define _OVL_60_H

/* Overlay 60: the minigame instructions screen for minigame table indices 30 and up
   (func_8003F6F0; below 30 it is overlay 5F, of which 60 is a copy with its own demos).
   Retail's overlay is three files: 3BDF60.c (the entry point), 3BDF90.c (80102830-80112BE0) and
   3CE370.c (80112C10, 80113264). Every function is global. .data and .bss stay asm (declared
   here); each file's .rodata is carved.
   This header was derived from ovl_5F.h (tools/mp2twincopy.py header): the types are 5F's,
   renamed Ovl5F* -> Ovl60*; the "5F-<W>" section notes name the 5F fork that found them.
   Prototypes of 60's own functions (no 5F twin) came from the asm's register use and the demo
   table D_80113810 only: the fork that owns a function fixes its line. */

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
typedef struct Ovl60Demo {
    /* 0x00 */ void (*setup)(void);
    /* 0x04 */ void (*unk04)(void);
    /* 0x08 */ void (*unk08)(omObjData*);
    /* 0x0C */ void (*unk0C)(omObjData*);
    /* 0x10 */ u16 unk10; /* the players' Ovl60Player.flags (5F-C) */
    /* 0x12 */ u16 unk12; /* the same for players outside group 0 */
} Ovl60Demo; /* size = 0x14 */

/* A model's float work (omObjData.unk_50 of func_80103608 / func_8010352C: a falling,
   swaying model). */
typedef struct Ovl60FallWork {
    /* 0x00 */ Vec pos;
    /* 0x0C */ f32 scale;
    /* 0x10 */ f32 baseX;
    /* 0x14 */ f32 vel;
    /* 0x18 */ f32 floor;
    /* 0x1C */ f32 angle;
    /* 0x20 */ f32 angleVel;
    /* 0x24 */ s32 model; /* read as (s16): lh 0x26 */
} Ovl60FallWork; /* size = 0x28 */

/* What main's D_800FC890 points at while 5F/60 runs (func_80103994 moves the host off screen). */
typedef struct Ovl60HostWork {
    /* 0x00 */ Vec pos;
    /* 0x0C */ f32 angle;
    /* 0x10 */ Vec rot;
    /* 0x1C */ u16 model;
    /* 0x1E */ s16 count;
    /* 0x20 */ char unk20[8];
    /* 0x28 */ f32 step;
    /* 0x2C */ char unk2C[4];
    /* 0x30 */ s16 mes[3]; /* the pages' messages while flag 0xC is set */
} Ovl60HostWork;

/* A view of main's esprite slot (1AE60.c's local EspriteSlot, D_800F93FC). */
typedef struct Ovl60Esprite {
    /* 0x00 */ char pad00[4];
    /* 0x04 */ s16 group;
    /* 0x06 */ char pad06[4];
    /* 0x0A */ s16 x;
    /* 0x0C */ s16 y;
    /* 0x0E */ char pad0E[0x16];
} Ovl60Esprite; /* size = 0x24 */

/* 5F-B */
/* Initial state of one falling model (D_801139D4): copied into its Ovl60FallWork. */
typedef struct Ovl60FallInit {
    /* 0x00 */ Vec pos;
    /* 0x0C */ f32 floor;
    /* 0x10 */ f32 scale;
    /* 0x14 */ s16 work[4]; /* the object's work bytes (read as their low bytes) */
} Ovl60FallInit; /* size = 0x1C */

/* 5F-C */

/* What main's D_800FA640 entries point at while a demo runs: one demo player. */
typedef struct Ovl60Player {
    /* 0x00 */ Vec pos;
    /* 0x0C */ f32 angle;
    /* 0x10 */ f32 scale;
    /* 0x14 */ Vec rot;
    /* 0x20 */ f32 vy; /* jump speed (func_80108E50, 5F-B) */
    /* 0x24 */ char unk24[8];
    /* 0x2C */ f32 unk2C; /* the floor (func_80108E50) */
    /* 0x30 */ u16 flags; /* 1, 2, 4, 8, 0x10, 0x20: which motions; 0x100: the alternative set */
    /* 0x32 */ u16 unk32; /* bit 0: the idle motion may be set */
    /* 0x34 */ s16 model;
    /* 0x36 */ s16 mot[11];
    /* 0x4C */ s16 model2;
    /* 0x4E */ s16 model3;
    /* 0x50 */ char unk50[0x1C];
    /* 0x6C */ s16 unk6C; /* item icon sprite (func_8010456C) */
    /* 0x6E */ char unk6E[0x1E];
    /* 0x8C */ s16 count;
    /* 0x8E */ s16 count2;
    /* 0x90 */ char unk90[4];
    /* 0x94 */ f32 vel;
    /* 0x98 */ f32 floor;
    /* 0x9C */ f32 unk9C;
    /* 0xA0 */ char unkA0[4];
    /* 0xA4 */ void (*actA)(omObjData*); /* A button action (flag 4) */
    /* 0xA8 */ void (*actB)(omObjData*); /* B button action (flag 0x10) */
} Ovl60Player;

/* omObjData.unk_50 of func_80108D50 (a model attached to another model's hook node). */
typedef struct Ovl60Attach {
    /* 0x00 */ s32 model;
    /* 0x04 */ s32 parent;
    /* 0x08 */ char* hook;
} Ovl60Attach;

/* D_80113F44: per character, a part model file and the nodes it hangs between. */
typedef struct Ovl60CharHook {
    /* 0x00 */ s32 file;
    /* 0x04 */ char* node;
    /* 0x08 */ char* hook;
} Ovl60CharHook;

/* A view of main's per-character table D_800CD438 (19BF0.c's ActorCharData). */
typedef struct Ovl60CharData {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 dir;   /* the character's file directory */
    /* 0x08 */ s32 model; /* its model file */
    /* 0x0C */ s32 unk_0C; /* another model file (60-C: 8010F480's head) */
    /* 0x10 */ char unk_10[8];
} Ovl60CharData;

extern Ovl60CharData D_800CD438_CE038[];

/* |stick axis| of demo player i as a float (func_80108C8C read up to twice, as retail does) */
#define OVL60_STICK_ABS(i, axis) \
    (f32)(func_80108C8C_3C43EC_name_60(i, axis) < 0 ? -func_80108C8C_3C43EC_name_60(i, axis) \
                                                     : func_80108C8C_3C43EC_name_60(i, axis))
/* end 5F-C */

/* 5F-E: a Mini-Game Coaster game's setup (D_80113E0C / D_80113EA8 / D_80114010, by
   D_800FD8A8.unk04, indexed by D_80113DC0[minigame]; 3CE370.c). */
typedef struct Ovl60QuestGame {
    /* 0x00 */ s8 group; /* player 1's group */
    /* 0x01 */ s8 group2; /* player 2's group; -1: player 2 is a CPU */
    /* 0x02 */ u8 variant; /* D_800FA656 */
    /* 0x03 */ u8 cpu2; /* player 2's (and the partners') CPU difficulty */
    /* 0x04 */ u8 cpu; /* everyone's CPU difficulty */
    /* 0x05 */ char unk05;
    /* 0x06 */ s16 mes[3]; /* the instruction pages' messages */
} Ovl60QuestGame; /* size = 0xC */

/* ---- main-segment API used by 5F and 60 ---- */

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
extern Ovl60HostWork* D_800FC890_FD490; /* (D_800FC88C + 4); 80103C84 reads s16s at 0x30-0x34 (message ids) */
extern s32 D_800FC8A0_FD4A0;   /* (D_800FC89C + 4) */

extern s8 ContStkX[4];
extern s8 ContStkY[4];
extern u8 D_80102708_103308;
extern u8 D_80102720_103320;
extern u8 D_800FA656; /* minigame variant */
extern u16 D_800F9208_F9E08; /* the battle's coin pot */
extern Ovl60Esprite* D_800F93FC_F9FFC; /* EspriteSlot* (1AE60.c) */
extern u16 D_800CAFD8[]; /* item ids */

/* ---- 60 .data (asm, 3CEA00.data.s; the same layout as 5F's up to the demo table) ---- */

extern board_overlay_entrypoint D_801132A0_3CEA00_name_60[];

extern s16 D_801132B0_3CEA10_name_60[][4]; /* per minigame: two instruction messages, the
    extra message (-1: none; [2]) and, indexed by D_80114DC6 instead, the variant message ([3]) */
extern f32 D_80113518_3CEC78_name_60; /* the title face texture scroll */
extern s32 D_8011351C_3CEC7C_name_60[10]; /* item icon sprite files, by item id */
extern s32 D_80113544_3CECA4_name_60[5][2]; /* item icon offsets (x, y) */
extern u16 D_8011356C_3CECCC_name_60[4]; /* window buttons, by controller port */
extern Ovl60FallInit D_80113574_3CECD4_name_60[12]; /* the falling models (5F-B; asm labels A60, AD0 are [5], [9]) */
extern u16 D_801136C4_3CEE24_name_60[3][3]; /* item minigame: last turn of each stage, by game length */
extern u16 D_801136D8_3CEE38_name_60[4][3]; /* item minigame: item set by rank and stage (4: random 0/1) */
extern u16 D_801136F0_3CEE50_name_60[4][5]; /* item minigame: the sets' items (asm label B5A is [1][0]) */
extern s16 D_80113718_3CEE78_name_60[4][5][6]; /* item minigame: each item's chance, by set and character */
extern Ovl60Demo D_80113810_3CEF70_name_60[44]; /* 5F has 30; the asm labels 814/818/81C are [0]'s fields */
extern omObjData* D_80113B80_3CF2E0_name_60[4]; /* the players' action objects (5F-C) */
extern u16 D_80113B90_3CF2F0_name_60[6]; /* motion file per character (with flag 0x100) */
extern s8 D_80113DC0_3CF520_name_60[76]; /* 5F-E: per minigame, its Mini-Game Coaster setup (-1: none) */
extern Ovl60QuestGame D_80113E0C_3CF56C_name_60[]; /* 5F-E: Mini-Game Coaster setups, difficulty 0 (13 entries; the index can run into the next table) */
extern Ovl60QuestGame D_80113EA8_3CF608_name_60[]; /* difficulty 1 (30 entries) */
extern Ovl60QuestGame D_80114010_3CF770_name_60[]; /* difficulty 2 (43 entries) */

/* ---- 60 .bss (asm, ovl_60_bss.bss.s; 5F's layout moved by -0x4D0 up to 80114A70, then 0x20 more) ---- */

extern s16 D_801148F0_3D0050_name_60; /* the minigame (GwSystem.chosenMinigameIndex - 1) */
extern s16 D_801148F2_3D0052_name_60; /* its type (D_800CAD90[minigame].unk_04's high byte): 3 = battle?, 4-5 = 1P */
extern s16 D_801148F4_3D0054_name_60; /* the first player in group 0 */
extern s16 D_801148F6_3D0056_name_60; /* the variant's message row (func_80103C84) */
extern s16 D_801148F8_3D0058_name_60[6]; /* models: [0] backdrop, [1]-[2] title, [3]-[5] frame */
extern omObjData* D_80114908_3D0068_name_60[6]; /* the falling models' objects (Ovl60FallWork; asm labels DDC, DE0, DE4 are [1]-[3]) */
extern omObjData* D_80114920_3D0080_name_60[8]; /* objects riding a falling model (func_80104D08); DF4, DFC, E0C are [1], [3], [7] */
extern omObjData* D_8011492C_3D008C_name_60[5]; /* item icons / players' marker objects */
extern u16 D_80114940_3D00A0_name_60; /* full-screen sprite (fades in) */
extern u16 D_80114942_3D00A2_name_60; /* sprite shown over a model */
extern u16 D_80114944_3D00A4_name_60;
extern u16 D_80114946_3D00A6_name_60; /* named by 5F-A (a separate variable: retail does not share its address) */
extern s16 D_80114948_3D00A8_name_60; /* model */
extern u16 D_8011494A_3D00AA_name_60; /* blinking sprite */
extern s16 D_8011494C_3D00AC_name_60; /* its process runs while set */
extern s16 D_8011494E_3D00AE_name_60; /* the host model */
extern s16 D_80114950_3D00B0_name_60[5]; /* its motions */
extern s16 D_8011495A_3D00BA_name_60; /* the demo screen model */
extern s16 D_8011495C_3D00BC_name_60; /* model (battle / some minigames) */
extern s16 D_8011495E_3D00BE_name_60[5]; /* item icon sprites */
extern s16 D_80114968_3D00C8_name_60; /* selected item icon */
extern u16 D_8011496A_3D00CA_name_60; /* coin count shown (battle pot) */
extern s16 D_8011496C_3D00CC_name_60; /* the instructions window */
extern s16 D_8011496E_3D00CE_name_60[4]; /* its button sprites */
extern s16 D_80114976_3D00D6_name_60; /* coin counter sprite group */
extern s16 D_80114978_3D00D8_name_60; /* its show/hide state */
extern s16 D_8011497A_3D00DA_name_60; /* set: the player skipped to the minigame (START) */
extern void* D_8011497C_3D00DC_name_60; /* the minigame's demo files */
extern void* D_80114980_3D00E0_name_60;
extern void* D_80114984_3D00E4_name_60;
extern GAMEMES D_80114988_3D00E8_name_60[2]; /* the minigame's name, one per line (asm labels E60-ED4 are fields) */
extern Process* D_80114A70_3D01D0_name_60[4]; /* [0]: func_80105860's process (type 4) */
extern s32 D_80114A80_3D01E0_name_60[2]; /* the demo (index into D_80113810); [0] only */
extern s16 D_80114AB0_3D0210_name_60[8]; /* lh:2 sh:1 */
extern s16 D_80114AC0_3D0220_name_60; /* sh:1 lh:1 lhu:1 */
extern const char D_80114348_3CFAA8_name_60[]; /* "\xFF": an empty window message (defined in 3BDF90.c after its user) */
extern s16 D_80114AC2_3D0222_name_60; /* the first player in group 0 (80102830; 5F's D_80114F70) */
extern s16 D_80114AC4_3D0224_name_60; /* sh:1 lh:1 */

/* 5F-B */

extern s16 D_800CAFEE; /* main (3D6A0.c): the minigame variant override, -1 none */
extern f32 D_800BF7A4_C03A4; /* main: jump speed (func_80108E50) */
extern f32 D_800BF7A8_C03A8; /* main: swing step (func_80108DCC) */
extern f32 D_800BF7D4_C03D4; /* main: swing cap (func_80108DCC) */
extern s16 D_800CAFE4[5]; /* main (3D6A0.c): item chances */
extern s16 D_80102758_103358[9]; /* main bss (0x12 bytes; 30560.c uses [0]-[7]); [8]: the item minigame's set */

/* 5F-E */

#include "game/malloc.h"
#include "game/gamework.h"

/* A demo player's work (D_800FA640[player], main's per-player minigame data, as 5F-E's demos
   use it; 0x35 and 0x6D are read as bytes elsewhere). */
typedef struct Ovl60DemoPlayer {
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
} Ovl60DemoPlayer;

#define DEMO_PLAYER(i) ((Ovl60DemoPlayer*)D_800FA640_FB240[i])
/* D_800FA640[team] as a two-player team demo uses it (801116B0 / 80111A00): one shared model
   and two riders. */
typedef struct Ovl60PairDemo {
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
} Ovl60PairDemo;

#define PAIR_DEMO(i) ((Ovl60PairDemo*)D_800FA640_FB240[i])

/* D_800FA640[team] in the two-rider pump demo (80112080 / 801123E4): a base form and two riders
   whose motions run in opposite directions. */
typedef struct Ovl60PumpDemo {
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
} Ovl60PumpDemo;

#define PUMP_DEMO(i) ((Ovl60PumpDemo*)D_800FA640_FB240[i])

/* func_80108D50's work: a form attached to a model's hook node */
typedef struct Ovl60HookWork {
    /* 0x00 */ s32 form;
    /* 0x04 */ s32 model;
    /* 0x08 */ const char* hook;
} Ovl60HookWork;

#ifndef ABS
#define ABS(x) ((x) < 0 ? -(x) : (x))
#endif

/* 5F-E: Ovl60CharData is 5F-C's (above) */

/* ---- 60 functions (address order; 3BDF60.c, 3BDF90.c, 3CE370.c) ---- */

void func_80102800_3BDF60_name_60(void);
void func_80102830_3BDF90_name_60(void);
void func_80102A14_3BE174_name_60(void);
void func_80102AF0_3BE250_name_60(void);
void func_8010352C_3BEC8C_name_60(omObjData*);
void func_80103608_3BED68_name_60(omObjData*);
void func_80103778_3BEED8_name_60(omObjData*);
void func_8010382C_3BEF8C_name_60(omObjData*);
void func_801038D4_3BF034_name_60(omObjData*);
void func_80103994_3BF0F4_name_60(omObjData*);
void func_80103B78_3BF2D8_name_60(omObjData*);
void func_80103C84_3BF3E4_name_60(s16, s32);
void func_801040D0_3BF830_name_60(omObjData*);
void func_801041C4_3BF924_name_60(void);
void func_80104280_3BF9E0_name_60(omObjData*);
void func_8010433C_3BFA9C_name_60(void);
void func_80104490_3BFBF0_name_60(omObjData*);
void func_8010456C_3BFCCC_name_60(s32, s32);
void func_80104650_3BFDB0_name_60(void);
void func_801046A4_3BFE04_name_60(void);
void func_801048F0_3C0050_name_60(void);
void func_801049F4_3C0154_name_60(void);
void func_80104D08_3C0468_name_60(omObjData*);
void func_80104DA8_3C0508_name_60(s32, s32, f32, f32, f32);
void func_80104E98_3C05F8_name_60(s32);
s32 func_80104F18_3C0678_name_60(s32);
s32 func_80105008_3C0768_name_60(s32, s32);
s32 func_801050DC_3C083C_name_60(s32);
void func_80105110_3C0870_name_60(omObjData*);
void func_80105258_3C09B8_name_60(void);
void func_801053F0_3C0B50_name_60(void);
void func_801054EC_3C0C4C_name_60(void);
void func_801056A8_3C0E08_name_60(void);
void func_8010578C_3C0EEC_name_60(void);
void func_80105860_3C0FC0_name_60(void);
s32 func_80105A14_3C1174_name_60(void);
s32 func_80105A54_3C11B4_name_60(void);
void func_80105AB8_3C1218_name_60(void);
void func_80105B94_3C12F4_name_60(void);
void func_801072C8_3C2A28_name_60(s16 model, void* header, void* code, u8* alpha);
void func_80107C84_3C33E4_name_60(s32);
void func_80107F74_3C36D4_name_60(void);
void func_80107FE0_3C3740_name_60(void);
void func_80108170_3C38D0_name_60(void);
void func_80108458_3C3BB8_name_60(void);
void func_801085A0_3C3D00_name_60(s32);
void func_8010879C_3C3EFC_name_60(s32, s32);
void func_8010881C_3C3F7C_name_60(s32);
void func_80108AEC_3C424C_name_60(void);
s32 func_80108B80_3C42E0_name_60(s32, s32);
s32 func_80108C24_3C4384_name_60(s32, s32);
s32 func_80108C8C_3C43EC_name_60(s32, s32);
void func_80108D50_3C44B0_name_60(omObjData*);
f32 func_80108DCC_3C452C_name_60(f32* angle, f32* pos, f32 scale);
void func_80108E50_3C45B0_name_60(omObjData*);
void func_801092B0_3C4A10_name_60(omObjData*);
void func_8010938C_3C4AEC_name_60(s32);
void func_801093D4_3C4B34_name_60(s32);
void func_80109424_3C4B84_name_60(s32);
void func_8010946C_3C4BCC_name_60(s32);
void func_801094B4_3C4C14_name_60(s32);
void func_801094F4_3C4C54_name_60(s32, s32);
void func_801098FC_3C505C_name_60(void);
void func_80109988_3C50E8_name_60(void);
void func_80109A04_3C5164_name_60(void);
void func_80109A80_3C51E0_name_60(omObjData*);
void func_80109FA0_3C5700_name_60(omObjData*);
void func_8010A000_3C5760_name_60(void);
void func_8010A038_3C5798_name_60(void); /* Ovl60Demo.unk04 */
void func_8010A0C4_3C5824_name_60(void);
void func_8010A1A0_3C5900_name_60(void);
void func_8010A2B0_3C5A10_name_60(void);
void func_8010A2EC_3C5A4C_name_60(omObjData*);
void func_8010A45C_3C5BBC_name_60(void);
void func_8010A4F0_3C5C50_name_60(void);
void func_8010A580_3C5CE0_name_60(void); /* Ovl60Demo.unk04 */
void func_8010A60C_3C5D6C_name_60(void); /* demo setup (Ovl60Demo.setup) */
void func_8010A834_3C5F94_name_60(omObjData*); /* Ovl60Demo.unk08 */
void func_8010AB44_3C62A4_name_60(void* player, f32); /* player = D_800FA640[i] (8010B4E0 / 80112158); from registers */
void func_8010AD2C_3C648C_name_60(void* player, f32); /* player = D_800FA640[i] (8010B4E0 / 80112158); from registers */
void func_8010AEF4_3C6654_name_60(void* player, f32); /* player = D_800FA640[i] (8010B4E0 / 80112158); from registers */
void func_8010B048_3C67A8_name_60(void); /* demo setup (Ovl60Demo.setup) */
void func_8010B488_3C6BE8_name_60(void); /* Ovl60Demo.unk04 */
void func_8010B4E0_3C6C40_name_60(omObjData*); /* Ovl60Demo.unk08 */
void func_8010B884_3C6FE4_name_60(void); /* demo setup (Ovl60Demo.setup) */
void func_8010BAF4_3C7254_name_60(void); /* Ovl60Demo.unk04 */
void func_8010BBFC_3C735C_name_60(omObjData*); /* Ovl60Demo.unk08 */
void func_8010BE6C_3C75CC_name_60(void); /* demo setup (Ovl60Demo.setup) */
void func_8010BFA8_3C7708_name_60(omObjData*); /* Ovl60Demo.unk08 */
void func_8010C284_3C79E4_name_60(void); /* demo setup (Ovl60Demo.setup) */
void func_8010C3A8_3C7B08_name_60(omObjData*); /* Ovl60Demo.unk08 */
void func_8010C634_3C7D94_name_60(void); /* demo setup (Ovl60Demo.setup) */
void func_8010C7F4_3C7F54_name_60(void); /* Ovl60Demo.unk04 */
void func_8010C904_3C8064_name_60(omObjData*);
void func_8010CB10_3C8270_name_60(omObjData*);
void func_8010CCB4_3C8414_name_60(omObjData*); /* from registers */
void func_8010CE78_3C85D8_name_60(void); /* demo setup (Ovl60Demo.setup) */
void func_8010D070_3C87D0_name_60(omObjData*); /* Ovl60Demo.unk08 */
void func_8010D3D0_3C8B30_name_60(void); /* demo setup (Ovl60Demo.setup) */
void func_8010D6C0_3C8E20_name_60(void); /* Ovl60Demo.unk04 */
void func_8010D74C_3C8EAC_name_60(omObjData*); /* Ovl60Demo.unk08 */
void func_8010D994_3C90F4_name_60(void); /* demo setup (Ovl60Demo.setup) */
void func_8010DC98_3C93F8_name_60(omObjData*); /* Ovl60Demo.unk08 */
void func_8010DF64_3C96C4_name_60(void); /* demo setup (Ovl60Demo.setup) */
void func_8010E11C_3C987C_name_60(omObjData*); /* Ovl60Demo.unk08 */
void func_8010E454_3C9BB4_name_60(void); /* demo setup (Ovl60Demo.setup) */
void func_8010E6A0_3C9E00_name_60(omObjData*); /* Ovl60Demo.unk08 */
void func_8010EC90_3CA3F0_name_60(void); /* demo setup (Ovl60Demo.setup) */
void func_8010EDD4_3CA534_name_60(void); /* demo setup (Ovl60Demo.setup) */
void func_8010F01C_3CA77C_name_60(omObjData*); /* Ovl60Demo.unk08 */
void func_8010F480_3CABE0_name_60(void); /* demo setup (Ovl60Demo.setup) */
void func_8010F63C_3CAD9C_name_60(void); /* Ovl60Demo.unk04 */
void func_8010F6C8_3CAE28_name_60(omObjData*); /* Ovl60Demo.unk08 */
void func_8010FA50_3CB1B0_name_60(void); /* demo setup (Ovl60Demo.setup) */
void func_8010FCC8_3CB428_name_60(void); /* Ovl60Demo.unk04 */
void func_8010FDA8_3CB508_name_60(omObjData*); /* Ovl60Demo.unk08 */
void func_801100BC_3CB81C_name_60(void); /* demo setup (Ovl60Demo.setup) */
void func_801102F4_3CBA54_name_60(omObjData*); /* Ovl60Demo.unk08 */
void func_801105D4_3CBD34_name_60(void); /* demo setup (Ovl60Demo.setup) */
void func_80110700_3CBE60_name_60(omObjData*); /* Ovl60Demo.unk08 */
void func_80110858_3CBFB8_name_60(void); /* demo setup (Ovl60Demo.setup) */
void func_80110A84_3CC1E4_name_60(void); /* Ovl60Demo.unk04 */
void func_80110B7C_3CC2DC_name_60(omObjData*); /* Ovl60Demo.unk08 */
void func_80110DA8_3CC508_name_60(void); /* demo setup (Ovl60Demo.setup) */
void func_80110F7C_3CC6DC_name_60(omObjData*); /* from registers */
void func_80111228_3CC988_name_60(void); /* demo setup (Ovl60Demo.setup) */
void func_80111430_3CCB90_name_60(omObjData*); /* Ovl60Demo.unk08 */
struct Ovl60TeamDemo; /* 60-C (below) */
void func_801116F0_3CCE50_name_60(struct Ovl60TeamDemo* p, f32 x); /* 60-C: the arm by stick x */
void func_801118C8_3CD028_name_60(struct Ovl60TeamDemo* p, f32 y); /* 60-C: the boom by stick y */
void func_80111A90_3CD1F0_name_60(struct Ovl60TeamDemo* p); /* 60-C: A/B drive the model's motion */
void func_80111BCC_3CD32C_name_60(void); /* demo setup (Ovl60Demo.setup) */
void func_80112100_3CD860_name_60(void); /* Ovl60Demo.unk04 */
void func_80112158_3CD8B8_name_60(omObjData*); /* Ovl60Demo.unk08 */
void func_80112610_3CDD70_name_60(void); /* demo setup (Ovl60Demo.setup) */
void func_80112818_3CDF78_name_60(omObjData*); /* Ovl60Demo.unk08 */
void func_80112B8C_3CE2EC_name_60(void);
void func_80112BA8_3CE308_name_60(void);
void func_80112BC4_3CE324_name_60(void);
void func_80112BE0_3CE340_name_60(void);
void func_80112C10_3CE370_name_60(s16);
void func_80113264_3CE9C4_name_60(s16);

/* 5F-D: Ovl60Player, Ovl60CharData and Ovl60Attach are 5F-C's (above) */

/* ---- 60 only: data the new demos (8010A60C - 80112818, forks 60-B/60-C) read ---- */
/* Declared raw from the label sizes and the asm's loads: retype yours. The demo table's
   fields (D_80113818 = D_80113810[0].unk08 etc.) are not declared: index D_80113810. */

extern char* D_80113B9C_3CF2FC_name_60[7]; /* per character: the node the head model hangs from (8010F480, 80110DA8, 80112610) */
extern s32 D_80113BB8_3CF318_name_60[3]; /* 8010B048 */
extern s32 D_80113BC4_3CF324_name_60[3]; /* 8010B048 */
extern u16 D_80113BD0_3CF330_name_60[6]; /* lhu (8010B884) */
extern s32 D_80113BDC_3CF33C_name_60[3]; /* 8010C634 */
extern s32 D_80113BE8_3CF348_name_60; /* 8010C634 */
extern s32 D_80113BEC_3CF34C_name_60[7]; /* 8010CE78 */
extern s32 D_80113C08_3CF368_name_60; /* lw (8010CE78) */
extern s32 D_80113C0C_3CF36C_name_60[13]; /* lw (8010CE78) */
extern s32 D_80113C40_3CF3A0_name_60[9]; /* 8010D3D0 */
extern s32 D_80113C64_3CF3C4_name_60[3]; /* 8010D3D0 */
extern u16 D_80113C70_3CF3D0_name_60[6]; /* lhu (8010D3D0) */
extern s32 D_80113C7C_3CF3DC_name_60[6]; /* lw (8010E454) */
extern char* D_80113C94_3CF3F4_name_60[6]; /* 8010EDD4: the ball's texture: [0] the default, [chr] the character's ("152_01a_DEF"...) */
extern u16 D_80113CAC_3CF40C_name_60[8]; /* per character: the body form file (| 0x400000; 8010F480) */
extern s32 D_80113CBC_3CF41C_name_60[6][4]; /* 8010FA50: per character, the four form files (| 0x410000) */
extern char* D_80113D1C_3CF47C_name_60[6][2]; /* 8010FA50: per character, the hook nodes forms 0 and 1 hang from (asm label D20 is [0][1]) */
extern char* D_80113D4C_3CF4AC_name_60[6][2]; /* 8010FA50: per character, forms 0 and 1's own nodes (asm label D50 is [0][1]) */
extern u16 D_80113D7C_3CF4DC_name_60[6]; /* per character: the held form's file (| 0x420000; 801100BC) */
extern u16 D_80113D88_3CF4E8_name_60[6]; /* lhu (801105D4) */
extern s32 D_80113D94_3CF4F4_name_60[3]; /* 80111BCC */
extern s32 D_80113DA0_3CF500_name_60[3]; /* 80111BCC */
extern u16 D_80113DAC_3CF50C_name_60[10]; /* lhu (80112610) */

extern s32 D_80114A88_3D01E8_name_60; /* sw (8010CE78) */
extern s32 D_80114A8C_3D01EC_name_60[9]; /* lw/sw (8010CE78, 8010D070) */
extern u8 D_80114AC3_3D0223_name_60; /* the low byte of D_80114AC2 (801105D4 stores D_80114AC2 into a work byte: retail reads this label) */
/* 60-C */

void func_8002BB4C_2C74C(s16 arg0, char* arg1, char* arg2); /* texture swap */
extern const char D_80114708_3CFE68_name_60[]; /* "item_hook" (defined in 3BDF90.c after 8010EDD4) */

/* D_800FA640[i] in the form-blend demo (8010FA50 / 8010FDA8): the character model and four
   forms; forms 0 and 1 hang from the model and blend towards forms 2 and 3. */
typedef struct Ovl60FormPlayer {
    /* 0x00 */ Vec pos;
    /* 0x0C */ f32 angle;
    /* 0x10 */ f32 scale;
    /* 0x14 */ Vec rot;
    /* 0x20 */ char unk20[0x14];
    /* 0x34 */ s16 model;
    /* 0x36 */ s16 mot[11];
    /* 0x4C */ s16 form[4];
    /* 0x54 */ char unk54[0x40];
    /* 0x94 */ f32 phase; /* degrees, 0-180 */
    /* 0x98 */ f32 blend; /* sin(phase) */
} Ovl60FormPlayer;

void func_8002A15C_2AD5C(s16 model, s16 motion, f32 t); /* MP1 func_80026174: blend two models */

u16 func_80018D64_19964(s32 arg0, s32 arg1, s32 arg2); /* a sprite-model slot (D_800F86D8) from a file */
void func_80021160_21D60(s16 index, s32 arg1, s32 arg2);

f32 fabsf(f32);

/* D_800FA640[team] in the two-player machine demo (80111BCC / 80112158): one machine per team
   (models 0x4A0000-0x4A000B, the second team's set from 0x4A0005), two riders' forms; rider 0
   steers with the stick and A/B, rider 1 fires with A. */
typedef struct Ovl60TeamDemo {
    /* 0x00 */ Vec pos;
    /* 0x0C */ char unk0C[4];
    /* 0x10 */ f32 scale;
    /* 0x14 */ Vec rot;
    /* 0x20 */ char unk20[0x14];
    /* 0x34 */ s16 model; /* the base */
    /* 0x36 */ char unk36[0x16];
    /* 0x4C */ s16 form[7]; /* [0] arm, [1] boom, [2]-[3] the firing pair, [4] lowered part, [5]-[6] the riders */
    /* 0x5A */ char unk5A[0x32];
    /* 0x8C */ s16 player[2]; /* the riders: the team's two players */
    /* 0x90 */ s16 state; /* rider 1's fire state */
    /* 0x92 */ s16 timer;
    /* 0x94 */ f32 arm; /* -9.5 .. 9.5 */
    /* 0x98 */ f32 boom;
    /* 0x9C */ f32 speed; /* the base motion's speed, -1.2 .. 1.2 */
} Ovl60TeamDemo;

#define TEAM_DEMO(i) ((Ovl60TeamDemo*)D_800FA640_FB240[i])

/* end 60-C */
#define OVL60_ABS(x) ((x) < 0 ? -(x) : (x))

#endif
