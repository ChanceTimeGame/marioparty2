#ifndef _OVL_62_H
#define _OVL_62_H

/* Overlay 62: the title screen and the opening (intro) movie, entered through ExecBoardScene with
   main's D_800CD414 as the entry:
   - entry 0 (80102998): the title. A process (8010D3C0, fork C) runs the title scene; the state
     object (80102DC0) fades in, then START (80102FD8, pad 1) once the title is up (8010D484) leaves
     for the main menu: omOvlCallEx(0x5B, 0, 0x1081) and omOvlHisChg(1, 0x62, 0, 0x192), so the
     menu returns here. When the title process times out (80102BD0, state 5) it fades to the boot
     logos' entry 1 (omOvlGotoEx(0x57, 1, 0x92)).
   - entry 1 (801029C0): the opening. A process (801059F0 -> 80105A1C) runs the script (80105AB8,
     fork B). START during it (state 3) fades to the title (62, entry 0); near its end the script
     sets state 4 (80102BFC), where START goes to the main menu as above; when the script returns,
     80105A1C fades to the boot logos' entry 1 (0x57, 1, 0x92).
   Main's D_801011FC == 1 (START seen elsewhere) also ends states 3/4 (80102B88).
   Scene tools here: a message window (801031D0/801033F8), a full-screen fade (801035AC in,
   80103730 out), a light mask with up to 8 stamps (801038DC..8010433C), the curtain blend
   (8010436C), sprite groups (80104448..80104668), an RGBA32 picture (80105280, 80104778) and
   model helpers for the script (80105460..801057D4).
   Retail's overlay is three files: ovl_62_entrypoint.c (80102800), 3D4D50.c (80102830-801029EC)
   and 3D4F20.c (80102A00-end; built with the KMC mul fix). Every function is global. .data stays
   asm (declared here); .rodata is carved (3D4F20). Data and bss are big-endian only through the
   two s32 fields read as s16 low halves (D_80111D50, Ovl62Sprite), and the image headers, which
   are read byte by byte.
   Prototypes past 80105A1C come from register use only: the fork owning a function fixes its line
   and retypes its data. */

#include "common.h"
#include "process.h"
#include "game/data.h"
#include "game/object.h"
#include "game/board.h"
#include "game/window.h"
#include "game/sprite.h"
#include "game/camera.h"
#include "game/pad.h"

/* ---- types ---- */

/* An 8-bit intensity image (I8): 801038DC loads file 0xE000F into D_8011268C. */
typedef struct Ovl62Image {
    /* 0x00 */ s32 w;
    /* 0x04 */ s32 h;
    /* 0x08 */ u8* data;
} Ovl62Image; /* size = 0xC */

/* One stamp of the light mask (D_80112060[8]). The mask is a 160x128 I8 buffer per frame buffer
   (D_80112148, three of them); each frame it is cleared to 0xFF and every active stamp writes its
   image where it is darker (8010421C); 80103BF0 draws it full screen. Only stamp 0's color is
   used: it is the mask's primitive color (80103AC0). */
typedef struct Ovl62Stamp {
    /* 0x00 */ u8 color[4];
    /* 0x04 */ s32 x;
    /* 0x08 */ s32 y;
    /* 0x0C */ s32 w;
    /* 0x10 */ s32 h;
    /* 0x14 */ u8* data; /* NULL: inactive */
} Ovl62Stamp; /* size = 0x18 */

/* A one-member sprite group (80104448). The three fields are s32 but every user passes them on as
   s16 (retail reads the low halves). */
typedef struct Ovl62Sprite {
    /* 0x00 */ s32 active;
    /* 0x04 */ s32 anim;
    /* 0x08 */ s32 grp;
} Ovl62Sprite; /* size = 0xC */

/* A model pair animated between two named parts (8010436C, 8010440C; the curtain,
   "C161_000-donchou" / "C161_000-donchou2"). */
typedef struct Ovl62Blend {
    /* 0x00 */ s16 model;
    /* 0x02 */ s16 model2;
    /* 0x04 */ char* part;
    /* 0x08 */ char* part2;
    /* 0x0C */ f32 t;
} Ovl62Blend; /* size = 0x10 */

/* Message window placement (D_80111030): MP1 func_800FC528's arguments. */
typedef struct Ovl62WinDef {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ s32 cols;
    /* 0x0C */ s32 rows;
} Ovl62WinDef;

/* ---- main ---- */

extern u16 D_801011FC_101DFC; /* main: START pressed during a skippable scene */
extern u8 D_800FDBE0_FE7E0;   /* main: the frame buffer being drawn (0-2) */
extern u8 D_800FDEAE_FEAAE;
extern s8 ContStkX[4];
extern s8 ContStkY[4];

void ExecBoardScene(void*, s16);
s16 LoadFormFile(s32, s32);
s32 HuGetPadInserted(s16);
void HuMemFree(void*);
void MBDBackKill(void);
u16 MBDCameraPos3DSet(Vec*);
s16 DrawDebugText(u16, u16, char*); /* MP1 print8 */
void ScissorSet(u8 arg0, f32 x1, f32 y1, f32 x2, f32 y2);
void ViewportSet(u8, f32, f32, f32, f32, f32, f32);
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* cos */
void HuVecCopyXYZ(Vec*, f32, f32, f32);
s16 SprCreate(s32 num, s32 attr);
s16 SprAnimRead(void*);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
void SprAttrSet(s16, s16, s32);
void SprAttrReset(s16 grpIdx, s16 idx, s32 flag);
void SprPosSet(s16 grpIdx, s16 idx, s16 x, s16 y);
void SprKill(s16 idx);
void SprAnimKill(s16 anim);
void func_80082488_83088(s16 grpIdx, s16 idx, u16 a); /* sprite alpha */
HuSprite* func_80082550_83150(s16 grpIdx, s16 idx);
void func_80018E30_19A30(s32);
void func_80020D20_21920(s16 arg0);
void func_80026D28_27928(s32);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void* func_80027154_27D54(s32, s32); /* HuMemAllocTag */
void func_80027340_27F40(void*);
s16 func_8002838C_28F8C(s32 arg0, void (*arg1)(Gfx**), u8 arg2); /* add a draw callback */
void func_800283DC_28FDC(s16 arg0);
void func_80029708_2A308(s32);
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029AFC_2A6FC(s16);
void func_8002A00C_2AC0C(s16);
void func_8002A4E0_2B0E0(s16 arg0, s16 arg1, f32 arg2, char* arg3, char* arg4, s32 arg5);
void func_8002CA48_2D648(u8 arg0, u8 arg1, u8 arg2);
void func_80046238_46E38(void);
void func_80047B78_48778(void);
void func_80050A30_51630(u8*);
void func_80050AE0_516E0(void);
f32 func_80052E5C_53A5C(void);
void func_80052E68_53A68(f32); /* MBCameraZoomSet */
void func_80056658_57258(Vec*, Vec*, Vec*); /* direction from a to b as a rotation */
omObjData* func_8005845C_5905C(s32 arg0, Vec* arg1, s32 arg2, MBModel* arg3);
omObjData* func_80058F18_59B18(s32 arg0, Vec* arg1, s32 arg2, MBModel* arg3);
void func_80059400_5A000(void);
void func_8005E260_5EE60(s16 playerIndex);
s32 func_80068448_69048(void);
void func_80079868_7A468(void);
s32 func_800888A8_894A8(s16, s16, s16, s16, s32, s16);
void func_800890CC_89CCC(s16, s32, s32, s32);
s32 func_80089404_8A004(s16 win_id, u32 spriteMainFsPair, s16 arg2, s16 arg3, s16 arg4);
void func_80089A48_8A648(s16, s16);
void func_80089B2C_8A72C(s16, s16);
void func_80089C78_8A878(s16 winId, u8 arg1);
void func_80089CAC_8A8AC(s16 winId, u8 idx, u8 r, u8 g, u8 b);
void func_80089DA0_8A9A0(s16 winId, u8 r, u8 g, u8 b);
void func_8008AD44_8B944(s16);
s16 func_8008BA30_8C630(s16 winId);
void func_8008D530_8E130(s16 winId, u8 r, u8 g, u8 b);
void func_8008D5D8_8E1D8(s16 winId); /* hide a window */
void func_8008D6F0_8E2F0(s16 winId); /* show a window */
void func_8008D88C_8E48C(s16);
void omSetRot(omObjData*, f32, f32, f32);
int sprintf(char* dst, const char* fmt, ...);

/* ---- 62 .data (asm, 3E3530.data.s) ---- */

extern board_overlay_entrypoint D_80111010_3E3530_TitleScreenAndIntro[]; /* 0 title, 1 intro, -1 */
extern Ovl62WinDef D_80111030_3E3550_TitleScreenAndIntro;                 /* {28, 208, 24, 2} */
extern Gfx D_80111040_3E3560_TitleScreenAndIntro[];                       /* fill set-up (801037D0) */
extern Gfx D_80111090_3E35B0_TitleScreenAndIntro[];                       /* mask set-up (80103BF0) */
extern u8* D_801110E0_3E3600_TitleScreenAndIntro;                         /* RGBA32 picture (80105280), NULL when none */
extern Gfx D_801110E8_3E3608_TitleScreenAndIntro[];                       /* 80104778's set-up */
extern Vec D_80111128_3E3648_TitleScreenAndIntro;                         /* debug camera start */

/* ---- 62 .bss (asm, ovl_62_bss.bss.s) ---- */

extern s32 D_80111D30_3E4250_TitleScreenAndIntro; /* entry: 0 title, 1 intro */
extern s32 D_80111D40_3E4260_TitleScreenAndIntro; /* title/intro state (80102C28, 80102DC0) */
extern s32 D_80111D44_3E4264_TitleScreenAndIntro; /* next overlay */
extern s16 D_80111D48_3E4268_TitleScreenAndIntro; /* its event */
extern u16 D_80111D4A_3E426A_TitleScreenAndIntro; /* its stat */
extern s32 D_80111D50_3E4270_TitleScreenAndIntro; /* message window, -1 none (read as s16: D_80111D52 is its low half) */
extern s32 D_80111D54_3E4274_TitleScreenAndIntro; /* mask width (160) */
extern s32 D_80111D58_3E4278_TitleScreenAndIntro; /* mask height (128) */
extern u8 D_80111D5C_3E427C_TitleScreenAndIntro[4]; /* full-screen fill color */
extern s16 D_80111D60_3E4280_TitleScreenAndIntro; /* fill draw callback */
extern s16 D_80111D62_3E4282_TitleScreenAndIntro; /* mask draw callback */
extern s32 D_80111D64_3E4284_TitleScreenAndIntro; /* 80105280's image width */
extern s32 D_80111D68_3E4288_TitleScreenAndIntro; /* its height */
extern s16 D_80111D6C_3E428C_TitleScreenAndIntro; /* its draw callback */
extern Process* D_80111D70_3E4290_TitleScreenAndIntro; /* the title camera process (8010DF5C) */
extern s32 D_80111E38_3E4358_TitleScreenAndIntro[16][7]; /* 0x1C each; 80105A1C clears word 0 */
extern Ovl62Stamp D_80112060_3E4580_TitleScreenAndIntro[8];
extern u8* D_80112144_3E4664_TitleScreenAndIntro; /* I8 alpha image (file 0x1B) */
extern u8* D_80112148_3E4668_TitleScreenAndIntro; /* the three masks */
extern Process* D_8011265C_3E4B7C_TitleScreenAndIntro; /* the scene process */
extern omObjData* D_80112668_3E4B88_TitleScreenAndIntro; /* the state object */
extern s32 D_80112678_3E4B98_TitleScreenAndIntro;
extern Ovl62Image D_8011268C_3E4BAC_TitleScreenAndIntro; /* the default stamp image */
extern u8* D_801138A0_3E5DC0_TitleScreenAndIntro;        /* the mask being drawn */

/* ---- functions: 3D4D50.c ---- */

void func_80102830_3D4D50_TitleScreenAndIntro(void);
void func_80102998_3D4EB8_TitleScreenAndIntro(void);
void func_801029C0_3D4EE0_TitleScreenAndIntro(void);
s32 func_801029EC_3D4F0C_TitleScreenAndIntro(void);

/* ---- functions: 3D4F20.c, 62-A ---- */

s32 func_80102A00_3D4F20_TitleScreenAndIntro(void);
void func_80102A08_3D4F28_TitleScreenAndIntro(void);
void func_80102A38_3D4F58_TitleScreenAndIntro(void);
omObjData* func_80102A68_3D4F88_TitleScreenAndIntro(void);
void func_80102AB4_3D4FD4_TitleScreenAndIntro(omObjData* obj);
omObjData* func_80102AF8_3D5018_TitleScreenAndIntro(void);
void func_80102B44_3D5064_TitleScreenAndIntro(omObjData* obj);
void func_80102B88_3D50A8_TitleScreenAndIntro(void);
void func_80102BD0_3D50F0_TitleScreenAndIntro(void);
void func_80102BFC_3D511C_TitleScreenAndIntro(s32 state);
void func_80102C28_3D5148_TitleScreenAndIntro(omObjData* obj);
void func_80102DC0_3D52E0_TitleScreenAndIntro(omObjData* obj);
void func_80102F64_3D5484_TitleScreenAndIntro(omObjData* obj);
s32 func_80102FD8_3D54F8_TitleScreenAndIntro(void);
s32 func_80103028_3D5548_TitleScreenAndIntro(void);
s32 func_80103048_3D5568_TitleScreenAndIntro(void);
void func_80103054_3D5574_TitleScreenAndIntro(s32 ovl, s16 event, u16 stat);
void func_80103070_3D5590_TitleScreenAndIntro(void);
void func_801030A0_3D55C0_TitleScreenAndIntro(void);
void func_801030D0_3D55F0_TitleScreenAndIntro(void);
void func_80103100_3D5620_TitleScreenAndIntro(void);
s32 func_8010312C_3D564C_TitleScreenAndIntro(s32 x, s32 y, s32 cols, s32 rows);
void func_801031D0_3D56F0_TitleScreenAndIntro(s32 mess, s32 wait);
void func_801033F8_3D5918_TitleScreenAndIntro(s32 mess, s32 wait, s32 keep);
void func_80103478_3D5998_TitleScreenAndIntro(void);
void func_80103498_3D59B8_TitleScreenAndIntro(void);
void func_801034A4_3D59C4_TitleScreenAndIntro(u8 r, u8 g, u8 b, u8 a);
void func_801034C0_3D59E0_TitleScreenAndIntro(omObjData* obj);
omObjData* func_801035AC_3D5ACC_TitleScreenAndIntro(s32 time);
void func_8010364C_3D5B6C_TitleScreenAndIntro(omObjData* obj);
omObjData* func_80103730_3D5C50_TitleScreenAndIntro(s32 time);
void func_801037D0_3D5CF0_TitleScreenAndIntro(Gfx** gfx);
s16 func_801038A0_3D5DC0_TitleScreenAndIntro(void);
s32 func_801038D0_3D5DF0_TitleScreenAndIntro(void); /* the frame buffer being drawn */
void func_801038DC_3D5DFC_TitleScreenAndIntro(void);
void func_80103A54_3D5F74_TitleScreenAndIntro(void);
void func_80103AC0_3D5FE0_TitleScreenAndIntro(u8 r, u8 g, u8 b, u8 a);
void func_80103ADC_3D5FFC_TitleScreenAndIntro(s32 i, s32 x, s32 y);
void func_80103B04_3D6024_TitleScreenAndIntro(s32 i, s32 x, s32 y, u8* data);
void func_80103BD4_3D60F4_TitleScreenAndIntro(s32 i);
void func_80103BF0_3D6110_TitleScreenAndIntro(Gfx** gfx);
void func_8010415C_3D667C_TitleScreenAndIntro(u8 value);
void func_8010421C_3D673C_TitleScreenAndIntro(Ovl62Stamp* stamp, s32 x, s32 y);
s16 func_8010433C_3D685C_TitleScreenAndIntro(void);
void func_8010436C_3D688C_TitleScreenAndIntro(Ovl62Blend* blend, s16 model, char* part, s16 model2, char* part2);
void func_8010440C_3D692C_TitleScreenAndIntro(Ovl62Blend* blend, f32 t);
void func_80104448_3D6968_TitleScreenAndIntro(s32 file, s16 x, s16 y, Ovl62Sprite* spr);
void func_80104524_3D6A44_TitleScreenAndIntro(Ovl62Sprite* spr);
void func_80104564_3D6A84_TitleScreenAndIntro(Ovl62Sprite* spr);
void func_801045A4_3D6AC4_TitleScreenAndIntro(Ovl62Sprite* spr, s32 prio);
void func_801045CC_3D6AEC_TitleScreenAndIntro(Ovl62Sprite* spr, s32 alpha);
void func_801045F0_3D6B10_TitleScreenAndIntro(Ovl62Sprite* spr);
void func_80104614_3D6B34_TitleScreenAndIntro(Ovl62Sprite* spr, s32 attr);
void func_80104638_3D6B58_TitleScreenAndIntro(Ovl62Sprite* spr);
void func_80104668_3D6B88_TitleScreenAndIntro(Ovl62Sprite* dst, Ovl62Sprite* mask);
void func_80104690_3D6BB0_TitleScreenAndIntro(s16 grp, s16 idx, s16 maskGrp, s16 maskIdx);
void func_80104778_3D6C98_TitleScreenAndIntro(Gfx** gfx);
s16 func_80105204_3D7724_TitleScreenAndIntro(void);
void func_80105234_3D7754_TitleScreenAndIntro(void);
void func_80105280_3D77A0_TitleScreenAndIntro(void);
void func_801053D8_3D78F8_TitleScreenAndIntro(void);
u16 func_80105460_3D7980_TitleScreenAndIntro(s32 file, f32 x, f32 y, f32 z, f32 scale, s32 attr);
u16 func_80105504_3D7A24_TitleScreenAndIntro(s32 file, f32 x, f32 y, f32 z, f32 scale, s32 attr);
void func_801055A0_3D7AC0_TitleScreenAndIntro(s16 model);
void func_801055C8_3D7AE8_TitleScreenAndIntro(s16 model);
void func_801055F0_3D7B10_TitleScreenAndIntro(MBModel* model, f32 angle);
void func_80105658_3D7B78_TitleScreenAndIntro(MBModel* model, f32 x, f32 y, f32 z);
void func_80105668_3D7B88_TitleScreenAndIntro(MBModel* model, Vec* pos);
void func_80105684_3D7BA4_TitleScreenAndIntro(MBModel* model, f32 x, f32 y, f32 z, s32 time);
void func_801056CC_3D7BEC_TitleScreenAndIntro(MBModel* model, f32 x, f32 y, f32 z, f32 time);
void func_8010571C_3D7C3C_TitleScreenAndIntro(MBModel* model, f32 x, f32 y, f32 z);
void func_80105758_3D7C78_TitleScreenAndIntro(MBModel* model, f32 dx, f32 dy, f32 dz);
void func_801057D4_3D7CF4_TitleScreenAndIntro(f32 angle, Vec* out);
void func_80105818_3D7D38_TitleScreenAndIntro(void);
void func_80105824_3D7D44_TitleScreenAndIntro(void);
void func_8010582C_3D7D4C_TitleScreenAndIntro(void);
void func_80105834_3D7D54_TitleScreenAndIntro(void);
void func_80105840_3D7D60_TitleScreenAndIntro(void);
void func_80105880_3D7DA0_TitleScreenAndIntro(void);
Process* func_801059F0_3D7F10_TitleScreenAndIntro(void);
void func_80105A1C_3D7F3C_TitleScreenAndIntro(void);

/* ---- the opening's cast (62-B and 62-C) ---- */

/* one motion of an opening model: file, loaded motion (-1 none; read as s16 through its low
   half), and a name the overlay never reads */
typedef struct Ovl62Motion {
    /* 0x00 */ s32 file;
    /* 0x04 */ s32 mot;
    /* 0x08 */ char* name;
} Ovl62Motion; /* size = 0xC */

/* an opening model (D_80111874[9]): 80110CAC's arguments and its motions */
typedef struct Ovl62ModelDef {
    /* 0x00 */ s32 file;
    /* 0x04 */ s32 attr;
    /* 0x08 */ f32 unk08;
    /* 0x0C */ f32 sx;    /* MBModelFileCreate's scales */
    /* 0x10 */ f32 sy;
    /* 0x14 */ Ovl62Motion* mots;
} Ovl62ModelDef; /* size = 0x18 */

/* how many motions of which model 80110CCC marks unloaded (D_80111AF0[9]) */
typedef struct Ovl62MotCount {
    /* 0x00 */ s32 def;
    /* 0x04 */ s32 count;
} Ovl62MotCount;

/* a model placement (D_8011194C[16]): file, position, rotation, scale */
typedef struct Ovl62ModelPlace {
    /* 0x00 */ s32 file;
    /* 0x04 */ Vec pos;
    /* 0x10 */ f32 rot;
    /* 0x14 */ f32 scale;
} Ovl62ModelPlace; /* size = 0x18 */

/* ---- 62-B ---- */

/* A texture file swapped onto a model (80110BF0's third argument). */
typedef struct Ovl62File {
    /* 0x00 */ s32 file;
    /* 0x04 */ s32 unk04;
} Ovl62File; /* size = 0x8 */

#include "game/hmfman.h" /* D_800F92B4: motion lengths */

/* .data, asm (3E3530.data.s): the motion and texture tables, in address order */
extern Ovl62Motion D_80111140_3E3660_TitleScreenAndIntro[18]; /* slot 0 */
extern Ovl62File D_80111218_3E3738_TitleScreenAndIntro[5];
extern Ovl62Motion D_80111240_3E3760_TitleScreenAndIntro[16]; /* slot 1 */
extern Ovl62File D_80111300_3E3820_TitleScreenAndIntro[4];
extern Ovl62Motion D_80111320_3E3840_TitleScreenAndIntro[16]; /* slot 2 */
extern Ovl62File D_801113E0_3E3900_TitleScreenAndIntro[4];
extern Ovl62Motion D_80111400_3E3920_TitleScreenAndIntro[17]; /* slot 3 */
extern Ovl62File D_801114CC_3E39EC_TitleScreenAndIntro[2];
extern Ovl62Motion D_801114DC_3E39FC_TitleScreenAndIntro[27]; /* slot 4 */
extern Ovl62File D_80111620_3E3B40_TitleScreenAndIntro[5];
extern Ovl62Motion D_80111648_3E3B68_TitleScreenAndIntro[14]; /* slot 5 */
extern Ovl62Motion D_801116F0_3E3C10_TitleScreenAndIntro[12]; /* slot 6 */
extern Ovl62File D_80111780_3E3CA0_TitleScreenAndIntro[1];
extern Ovl62Motion D_80111788_3E3CA8_TitleScreenAndIntro[11]; /* slot 7 */
extern Ovl62File D_8011180C_3E3D2C_TitleScreenAndIntro[2];
extern Ovl62Motion D_8011181C_3E3D3C_TitleScreenAndIntro[6]; /* slot 8 */
extern Ovl62File D_80111864_3E3D84_TitleScreenAndIntro[2];
extern Ovl62ModelDef D_80111874_3E3D94_TitleScreenAndIntro[9];
extern Ovl62ModelPlace D_8011194C_3E3E6C_TitleScreenAndIntro[16];

/* .bss, asm */
extern MBModel* D_80111D78_3E4298_TitleScreenAndIntro[32]; /* the cast (slots 0-8 used) */
extern s16 D_80111DF8_3E4318_TitleScreenAndIntro[32];      /* props (80105460's ids) */
extern s16 D_80111FF8_3E4518_TitleScreenAndIntro;          /* the music (80110F68) */

void HuPrcSleep(s32 time);
void MBModelDispOn(MBModel*);
void MBModelDispOff(MBModel*);
void MBModelKill(void*);
void MBMotionSet(MBModel*, s16, s32);
void MBMotionShiftSet(void* arg0, s16 arg1, s32 arg2, s32 arg3, u16 arg4);
void func_80059618_5A218(void*); /* wait for a model's motion to end */
void func_800B3170_B3D70(Vec*, Vec*); /* copy */
void HuVecSubtract(Vec*, Vec*, Vec*);
void Hu3DCam3DToScreen(s16 camIndex, Vec* worldPos, Vec2f* outPos);
s16 func_80027D3C_2893C(s16 linkMdlId); /* model copy */
void func_8002979C_2A39C(s16 idx, f32 x, f32 y, f32 z); /* model rotation */
void func_80029B80_2A780(s16 arg0, s16 arg1);
void func_80029E80_2AA80(s16, s32, s32);
void func_8002D0A0_2DCA0(s16, u8); /* model alpha */
s32 func_80011018_11C18(s16); /* the music is playing */
void func_80050E00_51A00(s32);
void func_800531AC_53DAC(void);
void omDelObj(omObjData*);
void omSetTra(omObjData*, f32, f32, f32);

/* Fork C's helpers called with the types their registers show (62-B, reported to the
   coordinator): these return what the script keeps, take a Vec*, or (80110CAC) pass
   MBModelFileCreate's float scales. Drop the casts once the 62-C prototypes agree. */

void func_80105AB8_3D7FD8_TitleScreenAndIntro(void); /* the intro script */

/* ---- 62-C ---- */


/* the 0x1C slots of D_80111E38 start with a sprite group. Retail has two arrays here,
   D_80111E38 (2 slots) and D_80111E70 (14): the opening's clear loops run 16 slots from
   D_80111E38 into D_80111E70. */
#define OVL62_SPRITE(i) ((Ovl62Sprite*)D_80111E38_3E4358_TitleScreenAndIntro[i])
#define OVL62_SPRITE2(i) ((Ovl62Sprite*)D_80111E70_3E4390_TitleScreenAndIntro[i])

/* main */
s32 func_80011018_11C18(s16); /* the music is playing */
void func_800531AC_53DAC(void);
void func_80050E00_51A00(s32);
void Hu3DCam3DToScreen(s16 camIndex, Vec* worldPos, Vec2f* outPos);
void Hu3DCamSetPerspective(s16, f32, f32, f32);
void Hu3DCamSetPositionOrientation(s16, Vec*, Vec*, Vec*);
void Hu3DCamUpdateMtx(s16);
void func_800B3170_B3D70(Vec*, Vec*); /* HuVecCopy3F */
void HuVecSubtract(Vec*, Vec*, Vec*);
void func_800B33E0_B3FE0(Vec*);       /* normalise */
void omSetTra(omObjData*, f32, f32, f32);
void omDelObj(omObjData*);
void func_8002979C_2A39C(s16, f32, f32, f32); /* model rotation */
void func_80029A8C_2A68C(s16);
void func_8002AC10_2B810(s16, f32, f32, s32);
void HmfModelObjAttrSet(s16, s32, s32);
extern f32 D_800CA02C_CAC2C;
u16 func_8002109C_21C9C(s16 index, s32 arg1);
u16 func_80020EBC_21ABC(void*, s32, u8);
void func_80021250_21E50(s16 index, u8 arg1, u8 arg2, u8 arg3);
void func_800211E8_21DE8(s16 index, u8 arg1);
void func_8002308C_23C8C(s32 index);
void MBMotionShiftSet(void* arg0, s16 arg1, s32 arg2, s32 arg3, u16 arg4);
MBModel* MBModelFileCreate(s32 arg0, s32 arg1, f32 arg2, f32 arg3, u32* arg4);
s16 func_80025384_25F84(s16 arg0, s16 arg1, s16 arg2, s32 arg3);
s32 func_80025718_26318(s16 arg0, s16 arg1, s16 arg2);
void func_8003E888_3F488(s16);
extern u8 D_800FDCA0_FE8A0[13][3];
extern u8 D_80101658_102258[13][3];
s32 func_8002C8B8_2D4B8(void*, s16);
void func_80039018_39C18(s16);
void func_80029BF0_2A7F0(s16, s16, s16, s16, s16);
void func_8002C9C0_2D5C0(s16, s16);
void func_80029E80_2AA80(s16, s32, s32);
s32 PlaySound(s32);

/* 62 .data (asm) */
#define D_8011186C_3E3D8C_TitleScreenAndIntro (&D_80111864_3E3D84_TitleScreenAndIntro[1].file) /* {file, 0} */
extern Vec D_80111ACC_3E3FEC_TitleScreenAndIntro; /* title camera position */
extern Vec D_80111AD8_3E3FF8_TitleScreenAndIntro; /* target */
extern Vec D_80111AE4_3E4004_TitleScreenAndIntro; /* up */
extern Ovl62MotCount D_80111AF0_3E4010_TitleScreenAndIntro[9];

/* 62 .bss (asm) */
extern s16 D_80111DF8_3E4318_TitleScreenAndIntro[32];     /* model ids */
extern s32 D_80111E70_3E4390_TitleScreenAndIntro[14][7];
extern s16 D_80111FF8_3E4518_TitleScreenAndIntro;         /* the title music */
extern Ovl62Blend D_80112000_3E4520_TitleScreenAndIntro;  /* the curtain */
extern Ovl62Blend D_80112010_3E4530_TitleScreenAndIntro;  /* stage lights */
extern Ovl62Blend D_80112020_3E4540_TitleScreenAndIntro;
extern Vec D_80112030_3E4550_TitleScreenAndIntro;
extern s32 D_80112660_3E4B80_TitleScreenAndIntro;         /* the title is up (START accepted) */

Process* func_8010D3C0_3DF8E0_TitleScreenAndIntro(void);
void func_8010D3EC_3DF90C_TitleScreenAndIntro(void);
void func_8010D478_3DF998_TitleScreenAndIntro(void);
s32 func_8010D484_3DF9A4_TitleScreenAndIntro(void); /* the intro is done */
void func_8010D490_3DF9B0_TitleScreenAndIntro(void);
void func_8010D684_3DFBA4_TitleScreenAndIntro(s32 x, s32 y, f32 scale);
void func_8010D778_3DFC98_TitleScreenAndIntro(void);
void func_8010D7C8_3DFCE8_TitleScreenAndIntro(void);
void func_8010D95C_3DFE7C_TitleScreenAndIntro(u16 alpha, s32 time);
void func_8010DA5C_3DFF7C_TitleScreenAndIntro(u16 alpha, s32 time);
void func_8010DB5C_3E007C_TitleScreenAndIntro(Vec* pos, u16 alpha, s32 time);
void func_8010DCA4_3E01C4_TitleScreenAndIntro(Vec* pos, u16 alpha, s32 time);
void func_8010DE00_3E0320_TitleScreenAndIntro(Vec* pos, s32 time);
void func_8010DEA0_3E03C0_TitleScreenAndIntro(void);
void func_8010DF30_3E0450_TitleScreenAndIntro(void);
Process* func_8010DF5C_3E047C_TitleScreenAndIntro(void); /* the title camera process */
void func_8010DF90_3E04B0_TitleScreenAndIntro(void);
void func_8010DF98_3E04B8_TitleScreenAndIntro(omObjData* obj);
void func_8010E008_3E0528_TitleScreenAndIntro(omObjData* obj);
void func_8010E0C4_3E05E4_TitleScreenAndIntro(s32 time); /* open the curtain */
void func_8010E154_3E0674_TitleScreenAndIntro(omObjData* obj);
void func_8010E210_3E0730_TitleScreenAndIntro(s32 time); /* close the curtain */
void func_8010E2A0_3E07C0_TitleScreenAndIntro(omObjData* obj);
void func_8010E320_3E0840_TitleScreenAndIntro(omObjData* obj);
void func_8010E408_3E0928_TitleScreenAndIntro(s32 time); /* stage lights off */
void func_8010E4C8_3E09E8_TitleScreenAndIntro(omObjData* obj);
void func_8010E5B0_3E0AD0_TitleScreenAndIntro(s32 time); /* stage lights on */
void func_8010E670_3E0B90_TitleScreenAndIntro(omObjData* obj);
void func_8010E8C0_3E0DE0_TitleScreenAndIntro(omObjData* obj);
omObjData* func_8010EB08_3E1028_TitleScreenAndIntro(void);
void func_8010EB88_3E10A8_TitleScreenAndIntro(omObjData* obj);
void func_8010ED80_3E12A0_TitleScreenAndIntro(omObjData* obj);
omObjData* func_8010EFBC_3E14DC_TitleScreenAndIntro(void);
void func_8010F074_3E1594_TitleScreenAndIntro(omObjData* obj);
void func_8010F1D0_3E16F0_TitleScreenAndIntro(omObjData* obj);
omObjData* func_8010F328_3E1848_TitleScreenAndIntro(void);
void func_8010F3F4_3E1914_TitleScreenAndIntro(void);
void func_8010F540_3E1A60_TitleScreenAndIntro(void);
void func_8010F5AC_3E1ACC_TitleScreenAndIntro(void);
void func_8010F95C_3E1E7C_TitleScreenAndIntro(void);
void func_8010F988_3E1EA8_TitleScreenAndIntro(void);
Process* func_8010FAB4_3E1FD4_TitleScreenAndIntro(void);
void func_8010FAE0_3E2000_TitleScreenAndIntro(void);
omObjData* func_8010FB2C_3E204C_TitleScreenAndIntro(void);
void func_8010FBD4_3E20F4_TitleScreenAndIntro(omObjData* obj);
omObjData* func_8010FC98_3E21B8_TitleScreenAndIntro(f32 x, f32 y, f32 z);
void func_8010FD28_3E2248_TitleScreenAndIntro(omObjData* obj);
omObjData* func_8010FE44_3E2364_TitleScreenAndIntro(void);
omObjData* func_8010FE7C_3E239C_TitleScreenAndIntro(s16 sprite, f32 x, f32 y, f32 z, f32 scale); /* smoke puff */
void func_801100B0_3E25D0_TitleScreenAndIntro(omObjData* obj);
omObjData* func_80110238_3E2758_TitleScreenAndIntro(s16 sprite, Vec* pos, Vec* dir, f32 scale);
void func_80110354_3E2874_TitleScreenAndIntro(omObjData* obj);
void func_801103FC_3E291C_TitleScreenAndIntro(omObjData* obj);
void func_8011058C_3E2AAC_TitleScreenAndIntro(omObjData* obj);
void func_80110708_3E2C28_TitleScreenAndIntro(omObjData* obj);
omObjData* func_80110888_3E2DA8_TitleScreenAndIntro(void);
void func_80110964_3E2E84_TitleScreenAndIntro(omObjData* obj);
omObjData* func_801109F4_3E2F14_TitleScreenAndIntro(s32 mess, s32 time); /* 801033F8(mess, 0, 1) */
void func_80110A58_3E2F78_TitleScreenAndIntro(s32 mess, s32 time);
void func_80110A7C_3E2F9C_TitleScreenAndIntro(omObjData* obj);
omObjData* func_80110AE4_3E3004_TitleScreenAndIntro(void);
void func_80110B18_3E3038_TitleScreenAndIntro(s32 chr); /* free texture animation set 1 */
void func_80110B84_3E30A4_TitleScreenAndIntro(s32 chr); /* set 2 */
void func_80110BF0_3E3110_TitleScreenAndIntro(s16 model, s16 chr, s32 file); /* texture animation set 1 */
void func_80110C20_3E3140_TitleScreenAndIntro(s16 model, s16 chr, s32 file); /* set 2 */
void func_80110C50_3E3170_TitleScreenAndIntro(s16 model, s16 chr, s16 idx);  /* set 1, main's file table */
MBModel* func_80110CAC_3E31CC_TitleScreenAndIntro(s32 file, s32 attr, f32 arg2, f32 arg3, u32* out); /* MBModelFileCreate */
void func_80110CCC_3E31EC_TitleScreenAndIntro(void);
s32 func_80110D64_3E3284_TitleScreenAndIntro(s32 file); /* load a motion */
void func_80110D8C_3E32AC_TitleScreenAndIntro(s32 i, s32 j); /* load motion j of model i */
void func_80110DDC_3E32FC_TitleScreenAndIntro(s32 i, s32 j); /* free it */
s32 func_80110E30_3E3350_TitleScreenAndIntro(s32 i, s32 j);
void func_80110E60_3E3380_TitleScreenAndIntro(s32 i, s32 j, s16 arg2, s16 arg3, s16 arg4); /* blend to it */
void func_80110EEC_3E340C_TitleScreenAndIntro(s32 i, s32 j, s16 arg2); /* set it */
s16 func_80110F68_3E3488_TitleScreenAndIntro(s16 music);
s16 func_80110FBC_3E34DC_TitleScreenAndIntro(s16 sound);

#endif
