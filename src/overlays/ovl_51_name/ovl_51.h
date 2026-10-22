#ifndef _OVL_51_H
#define _OVL_51_H

/* Overlay 51 (352E10.c): the end-of-game results scene (MP1 ovl_40_ResultsScene). A scrollable
   stats table (stars, coins, minigame coins, max coins and the space counts, 12 rows, four on
   screen) with each player's icons, then the coin and star totals.
   The unit's .rodata is carved; .data and .bss stay asm. Sprite and window ids live in s32 slots
   read as their low half, (s16)X (splat labels the +2 half separately). */

#include "common.h"
#include "game/board.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/data.h"
#include "game/sprite.h"
#include "game/window.h"
#include "game/gamemes.h"
#include "game/pad.h"
#include "game/gamework.h" /* R51B */
#include "process.h" /* R51B */

/* ---- main-segment API used by 51 ---- */

f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* cos */
void MBDBackKill(void);
void MBModelDispOff(MBModel*);
MBModel* MBModelFileCreate(s32 arg0, s32 arg1, f32 arg2, f32 arg3, u32* arg4);
void MBModelKill(void*);
MBModel* MBModelParamCreate(MBModel*);
void MBMotionSet(MBModel*, s16, s32);
void MBPlayerModelCreate(s16, void*, s32);
s32 PlaySound(s32);
s16 SprCreate(s32 num, s32 attr);
s16 SprAnimRead(void*);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprAnimKill(s16 animIdx);
void SprKill(s16 idx);
void SprAttrSet(s16, s16, s32);
void SprAttrReset(s16 group, s16 member, s32 attr);
void SprPosSet(s16 grpIdx, s16 idx, s16 x, s16 y);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
void SprScaleSet(s16 group, s16 member, f32 x, f32 y);
void func_8008221C_82E1C(s16 group, s16 member, f32 arg2);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
void func_800822A8_82EA8(s16 group, s16 member, u16 arg2, s32 arg3);
void func_80082450_83050(s16 grpIdx, s32 idx, s32 r, s32 g, u8 b); /* sprite colour */
s32 func_80011018_11C18(s16);
void func_8004340C_4400C(void);
MBModel* func_80043510_44110(s32, void*);
ModelEmitterWork* func_80049ED4_4AAD4(MBModel*, s16);
void func_80049F90_4AB90(ModelEmitterWork*);
UnkMBGuideData* func_80050304_50F04(s32, s32); /* MBGuideCreate */
void func_8005057C_5117C(UnkMBGuideData*); /* MBGuideKill */
void func_80050AE0_516E0(void);
void func_8005390C_5450C(s32);
void func_80056658_57258(Vec*, Vec*, Vec*); /* direction from a to b as a rotation */
s32 func_80057480_58080(s32 arg0, s32 arg1, s32 arg2, s32 arg3); /* create a window; 58080.c: s16 */
omObjData* func_8005845C_5905C(s32 arg0, Vec* arg1, s32 arg2, Object* arg3);
void func_80059698_5A298(s32 arg0);
void func_80059704_5A304(void);
s32 func_8005973C_5A33C(s32 arg0, u16 arg1, s16 arg2, s16 arg3);
void func_80059868_5A468(s32 arg0, s32 arg1, s16 arg2); /* 5A468.c: s16 x; retail passes x unextended */
void func_800598D4_5A4D4(s32 arg0, f32 arg1, f32 arg2);
void func_80059974_5A574(s32 arg0, f32 arg1);
s32 func_8005A5E8_5B1E8(MBModel* model, Vec* target, f32 speed); /* walk toward; 1 on arrival */
s32 func_8005AAC0_5B6C0(s32 x, s32 y, s32 w, s32 h); /* board message window */
void func_8005E260_5EE60(s16 playerIndex);
void func_8005E584_5F184(void);
void func_8005FE10_60A10(void);
void func_8005FF9C_60B9C(void);
void func_800600DC_60CDC(s32, s32); /* inferred from 80107090 */
void func_800601DC_60DDC(s32 arg0, s32 arg1);
s32 func_80060210_60E10(s32);
s32 func_800609D8_615D8(void); /* status windows still moving */
void func_80068150_68D50(s16 index);
void func_800681D8_68DD8(s32, s32); /* inferred from 801076B8 */
s16 func_8006A608_6B208(void* mes, char* str, u8 arg2, s16 arg3, s16 arg4); /* MP1 GMesFontMesCreate */
void func_8006AE14_6BA14(void*);
void func_8007DF98_7EB98(void);
void func_800890CC_89CCC(s16, s32, s32, s32); /* load a message into a window */
void func_80089284_89E84(s16, s32, s32);
void func_80089308_89F08(s16, char*, s8); /* window message argument (slot; retail narrows it to s8) */
void func_800896DC_8A2DC(s16 winId, s16 x, s16 y); /* window position */
void func_80089A48_8A648(s16, s16);
void func_80089A7C_8A67C(s16 winId, s16 prio);
void func_80089B2C_8A72C(s16, s16);
void func_8008AD44_8B944(s16 win);
void func_8008CCA8_8D8A8(s16); /* kill a window */
void func_8008D5D8_8E1D8(s16 winId); /* hide a window */
void func_8008D6F0_8E2F0(s16 winId); /* show a window */
void func_8008DACC_8E6CC(s32, s16*, s32); /* a message's window size */
void func_8008E434_8F034(s32 arg0);
void func_8008E6CC_8F2CC(s16 arg0, s16 arg1);
void omDelObj(omObjData*);
extern u16 ContDStkTrg[4];
extern s16 D_800FA188_FAD88; /* R51B: the current music */
extern u16 D_801011FC_101DFC; /* R51B: set when the scene may end (MP1 D_800F5144) */
extern s16 D_800F8CE4_F98E4[]; /* board state halfwords: [0..3] player order, [10 + p] bonus stars */

/* ---- overlay 51 data ---- */

extern s32 D_8010846C_358A7C_name_51[6]; /* per board: the flag set on entry (5..10) */
extern f32 D_80108484_358A94_name_51[2]; /* the scroll arrows' swing (MP1 D_800FC0D8) */
extern s32 D_8010848C_358A9C_name_51; /* first stats row shown (0..8) */
extern s32 D_80108490_358AA0_name_51; /* cursor row on screen (0..3) */
extern s16 D_80108494_358AA4_name_51[4][2]; /* cursor positions */
extern s16 D_801084A4_358AB4_name_51[4][2]; /* row title sprites */
extern s16 D_801084B4_358AC4_name_51[4][2]; /* row windows */
extern s16 D_801084C4_358AD4_name_51[4][2]; /* character icons */
extern s16 D_801084D4_358AE4_name_51[4][2]; /* character names */
extern s16 D_801084E4_358AF4_name_51[2]; /* board title */
extern s16 D_801084E8_358AF8_name_51[2]; /* game length */
extern s16 D_801084EC_358AFC_name_51[2][2]; /* scroll arrows */
extern f32 D_801084F4_358B04_name_51[12]; /* row title scales */
extern s32 D_80108524_358B34_name_51[12]; /* row title sprite files */
extern s32 D_80108554_358B64_name_51[2]; /* scroll arrow files */
extern s32 D_8010855C_358B6C_name_51[3]; /* per game length */
extern s32 D_80108568_358B78_name_51[6]; /* per board */
extern s32 D_80108580_358B90_name_51[6]; /* per character: icon */
extern s32 D_80108598_358BA8_name_51[6]; /* per character: name */
extern s32 D_801085B0_358BC0_name_51[12]; /* per row: the explanation message */

/* R51B */
extern s32 D_801083C0_3589D0_name_51; /* the star count the tally adds up (MP1 GwCommon.starNum) */
extern s32 D_801083C4_3589D4_name_51; /* falling-coin sound pacing (MP1 D_800FC050) */
extern Vec D_801083C8_3589D8_name_51; /* star pile centre */
extern Vec D_801083D4_3589E4_name_51;
extern Vec D_801083E0_3589F0_name_51[3]; /* coin start points; [0].y is where a finished coin returns */
extern s32 D_8010845C_358A6C_name_51[4]; /* the players' status windows' slots (14..17) */
extern Vec D_80108404_358A14_name_51[4]; /* where each player's stars start */
extern Vec D_80108434_358A44_name_51; /* where the stars fly to */
extern s32 D_801086B8_358CC8_name_51; /* next coin model (0..19) */
extern char* D_801085E0_358BF0_name_51; /* "RESULTS" */
extern s16 D_801085E4_358BF4_name_51[2]; /* tally: title position */
extern s16 D_801085E8_358BF8_name_51[4][2]; /* tally: portraits (D_801085F8 with flag 0xD) */
extern s16 D_801085F8_358C08_name_51[4][2];
extern s16 D_80108608_358C18_name_51[4][2]; /* tally: icons (D_80108618 with flag 0xD) */
extern s16 D_80108618_358C28_name_51[4][2];
extern s16 D_80108628_358C38_name_51[4][2]; /* tally: star sprites */
extern s16 D_80108638_358C48_name_51[4][2]; /* tally: coin sprites (D_80108648 with flag 0xD) */
extern s16 D_80108648_358C58_name_51[4][2];
extern s16 D_80108658_358C68_name_51[8][2]; /* tally: star then coin counters (D_80108678 with flag 0xD) */
extern s16 D_80108678_358C88_name_51[8][2];
extern s32 D_80108698_358CA8_name_51[6]; /* per character: tally icon */
extern s16 D_801086B0_358CC0_name_51[4]; /* per column: x offset (slides in) */
extern const char D_801087AC_358DBC_name_51[]; /* "%d" */
extern const char D_801087B4_358DC4_name_51[]; /* "X%2d" */

/* ---- overlay 51 bss ---- */

extern s32 D_80108870_358E80_name_51[4]; /* each player's coins on entry */
extern s32 D_80108880_358E90_name_51; /* total coins */
extern s32 D_80108884_358E94_name_51;
extern s32 D_80108888_358E98_name_51; /* total stars with the bonus stars */
extern s32 D_8010888C_358E9C_name_51;
/* R51B */
extern MBModel* D_801087D0_358DE0_name_51; /* the bank model */
extern MBModel* D_801087D8_358DE8_name_51[20]; /* the coin models */
extern MBModel* D_80108828_358E38_name_51[7]; /* the star models */
extern s32 D_80108890_358EA0_name_51[3]; /* tally icons: coins, stars, star coins */
extern s32 D_801088A0_358EB0_name_51[3]; /* the five-digit counters: coins, stars, star coins */
extern ModelEmitterWork* D_801088C0_358ED0_name_51[8]; /* the star models' trails */
extern s32 D_801088E0_358EF0_name_51[4]; /* each player's stars before the bonus stars */
extern GAMEMES D_801088F0_358F00_name_51[3]; /* "X" beside each counter */
extern omObjData* D_80108A4C_35905C_name_51; /* the bank's bounce object */
extern s32 D_80108A50_359060_name_51; /* character name sprites */
extern s32 D_80108A58_359068_name_51[4];
extern s32 D_80108A68_359078_name_51; /* character icon sprites */
extern s32 D_80108A70_359080_name_51[4];
extern s32 D_80108A80_359090_name_51; /* board title sprite */
extern s32 D_80108A84_359094_name_51;
extern s32 D_80108A88_359098_name_51; /* cursor sprite */
extern s32 D_80108A8C_35909C_name_51;
extern s32 D_80108A90_3590A0_name_51; /* game length sprite */
extern s32 D_80108A94_3590A4_name_51;
extern s32 D_80108A98_3590A8_name_51; /* scroll arrow sprites */
extern s32 D_80108A9C_3590AC_name_51[2];
extern s32 D_80108AA4_3590B4_name_51; /* row title sprites */
extern s32 D_80108AA8_3590B8_name_51[12];
extern UnkMBGuideData* D_80108AD8_3590E8_name_51; /* the guide (host and its text window) */
extern s32 D_80108AE0_3590F0_name_51[12]; /* per row: the stats window (row 11 reuses [0]) */
extern u8 D_80108B10_359120_name_51[12][4][8]; /* the stats table's digits */
extern omObjData* D_80108C90_3592A0_name_51; /* the scroll-arrow object */
extern s32 D_80108C98_3592A8_name_51[8]; /* tally counters: message slot in D_80108D70 */
extern GAMEMES D_80108CB8_3592C8_name_51; /* the "RESULTS" title (D_80108CD8 is its strGId) */
extern s32 D_80108D2C_35933C_name_51; /* tally: portrait sprites */
extern s32 D_80108D30_359340_name_51[4];
extern s32 D_80108D40_359350_name_51[4]; /* tally: icon backs */
extern s32 D_80108D50_359360_name_51[4]; /* tally: icons */
extern s32 D_80108D60_359370_name_51; /* tally: star sprites */
extern s32 D_80108D64_359374_name_51;
extern s32 D_80108D68_359378_name_51; /* tally: coin sprites */
extern s32 D_80108D6C_35937C_name_51;
extern GAMEMES D_80108D70_359380_name_51[8]; /* tally counters' digits */
extern s32 D_80109110_359720_name_51; /* tally message window */

/* ---- overlay 51 functions ---- */

void func_80102800_352E10_name_51(void);
void func_801029A8_352FB8_name_51(omObjData*);
void func_80102B90_3531A0_name_51(void);
void func_80102E7C_35348C_name_51(u8*);
void func_80102EB4_3534C4_name_51(void);
void func_8010361C_353C2C_name_51(void);
void func_801037E0_353DF0_name_51(void);
void func_8010418C_35479C_name_51(void);
void func_80104308_354918_name_51(void);
void func_80104490_354AA0_name_51(void);
void func_80104F6C_35557C_name_51(void);
void func_80105468_355A78_name_51(void);
void func_801055E4_355BF4_name_51(void);
void func_801058CC_355EDC_name_51(void);
void func_80105BE0_3561F0_name_51(void);
void func_80105D38_356348_name_51(void);
void func_80105E6C_35647C_name_51(omObjData*);
void func_801062AC_3568BC_name_51(omObjData*);
void func_80106660_356C70_name_51(omObjData*);
void func_80106884_356E94_name_51(omObjData*);
void func_80106A60_357070_name_51(s32);
void func_80106A9C_3570AC_name_51(void);
void func_80107090_3576A0_name_51(void);
void func_801076B8_357CC8_name_51(void);
void func_801077A8_357DB8_name_51(omObjData*);
void func_80107818_357E28_name_51(void);
void func_80107EA4_3584B4_name_51(void);
void func_80107FE8_3585F8_name_51(void);
void func_80108034_358644_name_51(void);
void func_80108058_358668_name_51(void);
void func_801081CC_3587DC_name_51(void);
void func_801082AC_3588BC_name_51(omObjData*);

#endif
