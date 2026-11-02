#ifndef OVL_5D_H
#define OVL_5D_H

/* Overlay 5D: Mini-Game Park's "Mini-Game Battle" hall: pick one of the five categories (4P, 1 vs 3,
   2 vs 2, Battle, Duel; D_8010ADD0) and a minigame from its board of unlocked pictures. Called with
   omOvlHisChg, and goes on to 5E (the player) with D_8010CE28. Retail's overlay is three files:
   3A01F0.c (80102800-80107C20), 3A5610.c (80107C20-801080C0) and 3A5AB0.c (801080C0-end). Every
   function is global. .rodata is carved; .data and .bss stay asm (declared here, typed by use).
   The segment has `subalign: 4`: 3A5AB0.c's .rodata starts 4-aligned. */

#include "common.h"
#include "process.h"
#include "game/data.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/sprite.h"
#include "game/window.h"
#include "game/gamemes.h"
#include "game/pad.h"
#include "game/camera.h"
#include "game/malloc.h"

#define ABS(x) ((x) < 0 ? -(x) : (x))

/* ---- types ---- */

/* One camera view (D_8010ADDC through D_8010CCE8; 801080C0 applies one, 801082A0 moves to one). */
typedef struct Ovl5DCamView {
    /* 0x00 */ Vec rot;  /* -> D_800FD474 */
    /* 0x0C */ Vec at;   /* -> D_8010274C */
    /* 0x18 */ f32 zoom; /* -> D_800FA610 */
} Ovl5DCamView; /* size = 0x1C */

/* One of the hall's models (D_8010B140; 8010A13C loads them into D_8010CCD0). */
typedef struct Ovl5DModelDef {
    /* 0x00 */ s32 file; /* -1 ends the table */
    /* 0x04 */ s32 attr; /* | 0x288; 4 = always hidden by 8010A2FC */
    /* 0x08 */ s16 unk08;
    /* 0x0A */ s16 unk0A; /* motion mode */
    /* 0x0C */ s32 group; /* shown by 8010A2FC when equal to its argument */
    /* 0x10 */ Vec pos;
    /* 0x1C */ Vec rot;
} Ovl5DModelDef; /* size = 0x28 */

/* One category's messages (D_8010B300). */
typedef struct Ovl5DCatMess {
    /* 0x00 */ s32 locked;
    /* 0x04 */ s32 some;
    /* 0x08 */ s32 all; /* every minigame of the category unlocked */
    /* 0x0C */ s32 chosen;
    /* 0x10 */ s32 pick;
    /* 0x14 */ s32 confirm;
} Ovl5DCatMess; /* size = 0x18 */

/* One decoration sprite of the panel (D_8010B4A4; 801049A8). Same shape as 5B's Ovl5BSprDef. */
typedef struct Ovl5DSprDef {
    /* 0x00 */ s32 file; /* sprite group; 0 ends the table */
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
    /* 0x0C */ f32 sx;
    /* 0x10 */ f32 sy;
} Ovl5DSprDef; /* size = 0x14 */

/* One key of a camera path (80108B68; MP1 OverworldCamKey). A zoom of 0 ends the path. */
typedef struct Ovl5DCamKey {
    /* 0x00 */ f32 zoom;
    /* 0x04 */ Vec center;
    /* 0x10 */ Vec rot;
    /* 0x1C */ Vec pos;
    /* 0x28 */ f32 time;
} Ovl5DCamKey; /* size = 0x2C */

/* The texture slot of a sprite: main's bank header (80082550's result, field 0x84). */
typedef struct Ovl5DSprFrame {
    /* 0x00 */ void* image;
} Ovl5DSprFrame;

/* An espr slot, read for its screen position and sprite group (D_800F93FC). */
typedef struct Ovl5DEspr {
    /* 0x00 */ char unk00[4];
    /* 0x04 */ s16 grp;
    /* 0x06 */ char unk06[4];
    /* 0x0A */ s16 x;
    /* 0x0C */ s16 y;
    /* 0x0E */ char unk0E[0x16];
} Ovl5DEspr; /* size = 0x24 */

/* ---- main ---- */

extern s8 ContStkX[4];
extern s8 ContStkY[4];
extern u16 ContBtnTrg[4];
extern s16 D_800CAFEE;
extern f32 D_800F8410_F9010;
extern u8 D_800F851A_F911A;
extern u16 D_800F9208_F9E08;
extern Ovl5DEspr* D_800F93FC_F9FFC;
extern u8 D_800F9D48_FA948[]; /* [0x2F8..0x2FB]: player order of a team minigame */
extern f32 D_800FA5BC_FB1BC[];
extern s16 D_800FC9BE_FD5BE[]; /* [5..9]: each category's last minigame */
extern s16 D_800FD80C_FE40C;
extern s16 D_800FFE00_100A00[]; /* [0xEA]: last category, -1 at first */
extern f32 D_80101078_101C78;
extern u16 D_801011FC_101DFC;

void func_80020070_20C70(s32);
void func_80020D20_21920(s16);
void func_80023554_24154(s16 model, s16 frame, char* part, f32 mtx[4][4]);
void func_80025830_26430(f32 (*)[4], f32, f32, f32);
void func_80025884_26484(f32 (*)[4], f32, f32, f32);
void func_80025BA4_267A4(f32 (*)[4], f32 (*)[4], f32 (*)[4]);
f32 func_8002662C_2722C(f32* keys, f32* times, f32 t);
void func_80026D28_27928(s32);
void func_80026DAC_279AC(s32, s32, s32, s32);
void func_80026E00_27A00(s16, f32, f32, f32);
void* func_80027154_27D54(s32 size, s32 tag);
void func_80029708_2A308(s32);
void func_80029714_2A314(s16, f32, f32, f32);
void func_80029760_2A360(s16, Vec*);
void func_8002979C_2A39C(s16, f32, f32, f32);
void func_800297E8_2A3E8(s16, f32, f32, f32);
void func_800298A4_2A4A4(s16, s32, s32);
f32 func_80029CE4_2A8E4(s16);
s16 func_80029E14_2AA14(s16);
void func_8002A00C_2AC0C(s16);
void func_8002BED4_2CAD4(s16, f32, f32, u16, u16, char*, u8);
void func_8002C59C_2D19C(s16, s16, u8, u8, u8);
void func_8002C9C0_2D5C0(s16, s16);
void func_8002CA48_2D648(u8, u8, u8);
void func_8002D4D0_2E0D0(s16);
s16 func_80067F4C_68B4C(s16);
void func_80067F94_68B94(s16);
s16 func_80068040_68C40(s16);
void func_80079614_7A214(s32);
void func_80088604_89204(s16, s16, s16, s16);
void func_800890CC_89CCC(s16, s32, s32, s32);
void func_80089284_89E84(s16, s32, s32);
void func_80089308_89F08(s16, char*, s32);
void func_80089A7C_8A67C(s16, s16);
void func_8008AD44_8B944(s16);
s16 func_8008BA30_8C630(s16);
s32 func_8008BB48_8C748(s16, s16, s32);
void func_8008CCA8_8D8A8(s16);
void func_8008D904_8E504(s16, s32, s8);
void func_8008DBE0_8E7E0(s16*, s16, s16);
s32 func_8008E73C_8F33C(s16, s32, s32, s32, s32, u16);
void func_8008E978_8F578(s16);
void func_8008EED8_8FAD8(s16, s16);
void func_8008F624_90224(s32, s32, s32);
void func_80096188_96D88(u8* code, u16* outbuf, s32 outbufWidth, u8* workbuf);
void func_80096708_97308(void* header);
void func_80096C10_97810(u8 alpha);
f32 func_800B1830_B2430(f32);
void func_800B1960_B2560(f32 (*)[4], f32, f32, f32, f32, f32, f32, f32, f32, f32);
void func_800B1F50_B2B50(f32 (*)[4], f32, f32, f32);
f32 func_800B7890_B8490(f32);
f32 HuMathSin(f32);
void HuMemFree(void*);
void Hu3DCamSetPositionOrientation(s16, Vec*, Vec*, Vec*);
void Hu3DCamUpdateMtx(s16);
s16 LoadFormFile(s32, s32);
s32 PlaySound(s32);
void SprAnimKill(s16);
void espDispOff(u16);
void espDispOn(u16);
void espPosSet(u16, s16, s16);
s16 func_8001A2F8_1AEF8(s32);
void func_8001A6BC_1B2BC(u16, s16);
void func_8001A788_1B388(u16, s32);
void func_8001A91C_1B51C(u16, f32, f32);
void func_8001A96C_1B56C(u16, u8, u8, u8);
s16 func_8001AAAC_1B6AC(s16, s32, s32);
void func_8001AC44_1B844(u16);
void omPrcSetStatBit(Process*, s32);
void omVibrate(s16, s16, s16, s16);

/* ---- .data ---- */

extern s16 D_8010ADD0_3A87C0_name_5D[6]; /* category of each menu row: 1 2 3 4 0 */
extern Ovl5DCamView D_8010ADDC_3A87CC_name_5D[31];
extern Ovl5DModelDef D_8010B140_3A8B30_name_5D[11];
extern u8 D_8010B2F8_3A8CE8_name_5D[8]; /* model of each category (5, then padding) */
/* retail labels [3] and [4] separately (asm aliases in undefined_syms.txt) */
#define D_8010B2FB_3A8CEB_name_5D (D_8010B2F8_3A8CE8_name_5D[3])
#define D_8010B2FC_3A8CEC_name_5D (D_8010B2F8_3A8CE8_name_5D[4])
extern Ovl5DCatMess D_8010B300_3A8CF0_name_5D[5];
extern s16 D_8010B378_3A8D68_name_5D[6];
extern char** D_8010B484_3A8E74_name_5D[5];
extern s16 D_8010B498_3A8E88_name_5D[6];
extern Ovl5DSprDef D_8010B4A4_3A8E94_name_5D[10];
extern s16 D_8010B56C_3A8F5C_name_5D[6]; /* 1 vs 3: x of the panel's digits */
extern s16 D_8010B578_3A8F68_name_5D[6];
extern s16 D_8010B584_3A8F74_name_5D[6]; /* 2 vs 2 */
extern s16 D_8010B590_3A8F80_name_5D[6];
extern s16 D_8010B59C_3A8F8C_name_5D[4][4]; /* 1 vs 3: team orders */
extern s16 D_8010B5BC_3A8FAC_name_5D[4][4]; /* 2 vs 2 */
extern s32 D_8010B5DC_3A8FCC_name_5D[6];
extern s32 D_8010B5F4_3A8FE4_name_5D[7];
extern f32 D_8010B610_3A9000_name_5D; /* fovy */
extern s8 D_8010B614_3A9004_name_5D;

/* ---- .bss ---- */

extern s16 D_8010BA70_3A9460_name_5D; /* the port that plays the menu */
extern s16 D_8010BA78_3A9468_name_5D[30][2]; /* positions of the pictures on the board */
extern s16 D_8010BAF0_3A94E0_name_5D[9][0x48]; /* locked minigames per category */
extern s16 D_8010C000_3A99F0_name_5D[9];
extern s16 D_8010C018_3A9A08_name_5D[9]; /* minigames per category */
extern s16 D_8010C030_3A9A20_name_5D[9]; /* unlocked minigames per category */
extern s16 D_8010C042_3A9A32_name_5D;
extern s16 D_8010C044_3A9A34_name_5D; /* unlocked */
extern s16 D_8010C046_3A9A36_name_5D;
extern s16 D_8010C050_3A9A40_name_5D[9][0x48]; /* unlocked minigames, by category */
extern s16 D_8010C560_3A9F50_name_5D;
extern s16 D_8010C562_3A9F52_name_5D; /* the message window */
extern s16 D_8010C564_3A9F54_name_5D; /* panel state: 0 open, 1 close, 2 open and running */
extern s16 D_8010C566_3A9F56_name_5D; /* an unlock scene runs */
extern s16 D_8010C568_3A9F58_name_5D;
extern s16 D_8010C56A_3A9F5A_name_5D;
extern s16 D_8010C56C_3A9F5C_name_5D; /* the chosen picture */
extern s16 D_8010C56E_3A9F5E_name_5D; /* picture sprite group */
extern s16 D_8010C570_3A9F60_name_5D[5][25];
extern Vec D_8010C670_3AA060_name_5D[5][25];
extern s16 D_8010CC4C_3AA63C_name_5D;
extern s16 D_8010CC4E_3AA63E_name_5D;
extern s16 D_8010CC50_3AA640_name_5D[6];
extern s16 D_8010CC5C_3AA64C_name_5D[6];
extern s16 D_8010CC68_3AA658_name_5D[4];
extern s16 D_8010CC70_3AA660_name_5D[4];
extern s16 D_8010CC78_3AA668_name_5D[4];
extern s16 D_8010CC80_3AA670_name_5D[4];
extern s16 D_8010CC88_3AA678_name_5D;
extern s16 D_8010CC8A_3AA67A_name_5D;
extern s16 D_8010CC8C_3AA67C_name_5D;
extern s16 D_8010CC8E_3AA67E_name_5D;
extern s16 D_8010CC90_3AA680_name_5D;
extern s16 D_8010CC92_3AA682_name_5D;
extern s16 D_8010CC94_3AA684_name_5D;
extern s16 (*D_8010CCA0_3AA690_name_5D)[2]; /* cursor targets */
extern s16 D_8010CCA4_3AA694_name_5D;
extern s16 D_8010CCA6_3AA696_name_5D;
extern s16 D_8010CCA8_3AA698_name_5D;
extern s16 D_8010CCAA_3AA69A_name_5D;
extern s16 D_8010CCAC_3AA69C_name_5D;
extern s16 D_8010CCAE_3AA69E_name_5D;
extern s16 D_8010CCB0_3AA6A0_name_5D;
extern void* D_8010CCB4_3AA6A4_name_5D[3];
extern void* D_8010CCC0_3AA6B0_name_5D;
extern s16 D_8010CCD0_3AA6C0_name_5D[10]; /* the models */
extern s16 D_8010CCE4_3AA6D4_name_5D; /* the cursor */
extern Ovl5DCamView* D_8010CCE8_3AA6D8_name_5D;
extern f32 D_8010CCF0_3AA6E0_name_5D[25][2];
extern s16 D_8010CDB8_3AA7A8_name_5D; /* event of the next overlay */
extern f32 D_8010CDBC_3AA7AC_name_5D;
extern s16 D_8010CDC0_3AA7B0_name_5D[10];
extern f32 D_8010CDD4_3AA7C4_name_5D;
extern Vec D_8010CDD8_3AA7C8_name_5D;
extern u16 D_8010CDE4_3AA7D4_name_5D; /* leave */
extern Vec D_8010CDE8_3AA7D8_name_5D; /* wrapped copy of the camera's rotation */
extern s16 D_8010CDF4_3AA7E4_name_5D; /* how to leave */
extern s16 D_8010CDF6_3AA7E6_name_5D; /* the cursor shows */
extern s8 D_8010CDF8_3AA7E8_name_5D[30];
extern s16 D_8010CE16_3AA806_name_5D; /* the category row */
extern Vec D_8010CE1C_3AA80C_name_5D;
extern s16 D_8010CE28_3AA818_name_5D; /* next overlay */
extern s16 D_8010CE2A_3AA81A_name_5D;

/* ---- 3A01F0.c ---- */

void func_80102800_3A01F0_name_5D(void);
void func_801029EC_3A03DC_name_5D(void);
void func_8010336C_3A0D5C_name_5D(s16);
void func_801034C0_3A0EB0_name_5D(void);
void func_80103580_3A0F70_name_5D(s16*);
void func_8010359C_3A0F8C_name_5D(void);
void func_80103E58_3A1848_name_5D(s16);
void func_80103FF0_3A19E0_name_5D(void);
void func_80104224_3A1C14_name_5D(void);
void func_801045F0_3A1FE0_name_5D(s16, s16);
void func_801049A8_3A2398_name_5D(void);
void func_8010543C_3A2E2C_name_5D(void);
u16 func_80105648_3A3038_name_5D(void);
void func_8010608C_3A3A7C_name_5D(void);
void func_80106208_3A3BF8_name_5D(s16, s16, s16, s16);
void func_80106238_3A3C28_name_5D(void);
void func_80106468_3A3E58_name_5D(void);
void func_80106CC4_3A46B4_name_5D(void);
void func_80106F5C_3A494C_name_5D(void);
void func_801075D0_3A4FC0_name_5D(s16, s16);
void func_801077B8_3A51A8_name_5D(void);
void func_80107B20_3A5510_name_5D(void);
void func_80107B8C_3A557C_name_5D(s16, s16, s32, s32);
void func_80107BE0_3A55D0_name_5D(void);

/* ---- 3A5610.c ---- */

s16 func_80107C20_3A5610_name_5D(s16, s16, s16, s16);
void func_80107F70_3A5960_name_5D(omObjData*);
void func_80107FE4_3A59D4_name_5D(omObjData*);

/* ---- 3A5AB0.c ---- */

void func_801080C0_3A5AB0_name_5D(s16);
void func_801082A0_3A5C90_name_5D(s16, s16, s16, void (*)(s16*));
void func_80108B68_3A6558_name_5D(Ovl5DCamKey*, f32, void (*)(s32, s16, s16));
void func_80109104_3A6AF4_name_5D(void);
void func_80109398_3A6D88_name_5D(void);
void func_801094E8_3A6ED8_name_5D(s16);
void func_80109520_3A6F10_name_5D(s16 (*)[2]);
void func_8010952C_3A6F1C_name_5D(s16);
void func_80109538_3A6F28_name_5D(s16);
void func_80109544_3A6F34_name_5D(void);
HuSprite* func_80082550_83150(s16, s16);
void func_80109B68_3A7558_name_5D(void);
void func_8010A13C_3A7B2C_name_5D(Ovl5DModelDef*);
void func_8010A230_3A7C20_name_5D(Ovl5DModelDef*, s16, s16);
void func_8010A2FC_3A7CEC_name_5D(Ovl5DModelDef*, s16);
void func_8010A3E4_3A7DD4_name_5D(s16, Vec*, f32 (*)[4]);
void func_8010A4E4_3A7ED4_name_5D(s16, Vec2f*, f32 (*)[4]);
void func_8010A524_3A7F14_name_5D(s16, Vec*, Vec2f*);
void func_8010A82C_3A821C_name_5D(s16, f32, Vec2f*, Vec*);
s16 func_8010AAE4_3A84D4_name_5D(void);
void func_8010ABDC_3A85CC_name_5D(s16);
void func_8010AD10_3A8700_name_5D(void);

#endif
