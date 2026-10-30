#ifndef _OVL_0C_H
#define _OVL_0C_H

/* Overlay 0C: Hot Rope Jump (4P). Its game code descends from MP1's ovl_2E_HotRopeJump (207040.c,
   HotRopeJump.h): a flaming rope (a chain of 13 flame models, D_80111920_13D510_HotRopeJump) turns
   and the players jump it. MP2 changes the rules: a player the rope touches drops out (falls off
   the stage), the rope's speed follows a script of five phases (D_8010C1C0_137DB0_HotRopeJump),
   and the round ends when one player is left (or, in the 1P-vs-CPU variant, _CheckFlag(0xC), after
   50 jumps or when the human player is hit).
   Retail is two files: 12E3F0.c (80102800-80107FAC) and 133BA0.c from 80107FB0 (MP1's
   func_800FB260 onward). .data stays asm (137D00); .rodata is carved per file (0x138170, 0x138310).
   Prototypes past 80105570 are inferred from register use and MP1 (S4-0CB, S4-0CC: check yours).
   N64 offsets are in the comments; the structs with pointer fields change size on the host. */

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/data.h"
#include "game/collision.h"

typedef f32 Matrix4f[4][4];

/* ---- structs ---- */

/* A player's rope state (D_80111158_13CD48_HotRopeJump[4]; MP1 HRJPlayer 0x60, fields from 0x10
   on moved +4). omObjData::work holds a pointer to it (func_80105D74/func_80105D94). No pointer
   except unk_6C. */
typedef struct HRJPlayer {
    /* 0x00 */ s16 unk_00; /* 1: hit by the rope */
    /* 0x02 */ u16 state;  /* 1 stand, 2 jump, 4 land, 8 hit, 0x10 win, 0x20 falling, 0x100 intro,
                              0x400 fallen off the stage */
    /* 0x04 */ char unk_04[4];
    /* 0x08 */ s16 speed;  /* walk speed in the intro */
    /* 0x0A */ s16 unk_0A; /* CPU: stop jumping (set once the jump count passes unk_0C) */
    /* 0x0C */ s16 unk_0C; /* CPU: jumps it will make */
    /* 0x0E */ char unk_0E[6];
    /* 0x14 */ Vec home;
    /* 0x20 */ Vec hit;
    /* 0x2C */ char unk_2C[0xC];
    /* 0x38 */ f32 unk_38; /* intro step x */
    /* 0x3C */ char unk_3C[4];
    /* 0x40 */ f32 unk_40; /* intro step z */
    /* 0x44 */ s16 intro;  /* intro walk step */
    /* 0x46 */ u16 unk_46; /* frames since the hit */
    /* 0x48 */ s16 unk_48;
    /* 0x4A */ s16 unk_4A;
    /* 0x4C */ char unk_4C[0x18];
    /* 0x64 */ s16 unk_64; /* bounces after the hit (D_8010C230_137E20_HotRopeJump index, max 4) */
    /* 0x66 */ s16 unk_66; /* the motion's model frame count (HmfModel::unk02; retail reads its low
                              byte) */
    /* 0x68 */ s16 unk_68; /* 1: unk_6C is playing */
    /* 0x6A */ char unk_6A[2];
    /* 0x6C */ s16* unk_6C; /* func_800231D8_23DD8's motion ([0] its frame count; main types it unk1EA70StructC*) */
} HRJPlayer; /* size = 0x70 */

/* A player's work (obj->unk_50): main's MgWork (collision.h). Fields used here: unk_38 vertical
   speed (1000 on the ground), unk_3C facing, unk_57 port, unk_59 player, unk_D0, unk_EC. */

/* One phase of the rope's speed script (D_8010C148_137D38_HotRopeJump..D_8010C1A8, listed by
   D_8010C1C0_137DB0_HotRopeJump). */
typedef struct HRJPhase {
    /* 0x00 */ s32 count; /* turns in this phase; -1 = the last phase */
    /* 0x04 */ s32 mode;  /* 0 speed[0], 1 a random speed, 2 add speed[0], 3 75% speed[0] else
                             speed[1] or speed[2] */
    /* 0x08 */ f32 unk_08; /* passed to func_8010BF98 (the rope's swing) */
    /* 0x0C */ f32 speed[3];
} HRJPhase; /* size = 0x18 */

/* A flame model: the rope's 13 (D_80111920_13D510_HotRopeJump) and the two torches
   (D_80111924_13D514_HotRopeJump). MP1 HRJSeg (0x108) with one more word before angle: only the
   fields 12E3F0.c's first half uses are placed (S4-0CB/0CC: fill in from MP1's). */
typedef struct HRJSeg {
    /* 0x00 */ Vec pos;
    /* 0x0C */ Vec dir;   /* rope: the segment to the next one */
    /* 0x18 */ Vec vel;
    /* 0x24 */ Vec base;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 angle; /* rope turn angle */
    /* 0x38 */ f32 size;
    /* 0x3C */ s16 light; /* fields from here: S4-0CC, from MP1 +4 */
    /* 0x3E */ s16 model;
    /* 0x40 */ u16 anim;
    /* 0x42 */ u16 state;
    /* 0x44 */ s16 timer;
    /* 0x46 */ s16 delay;
    /* 0x48 */ char unk_48[8];
    /* 0x50 */ Mtx mtx[3];
} HRJSeg; /* size = 0x110 */

/* A floor light (D_80111420_13D010_HotRopeJump[32]; MP1 HRJLight 0x14 plus three fields). */
typedef struct HRJLight {
    /* 0x00 */ s16 used;
    /* 0x02 */ s16 x;
    /* 0x04 */ s16 y;
    /* 0x06 */ s16 z;
    /* 0x08 */ s32 radius;
    /* 0x0C */ f32 aspect;
    /* 0x10 */ s32 radiusSq;
    /* 0x14 */ s32 fade;     /* func_801089EC: frames left of the fade (0 none) */
    /* 0x18 */ s32 fadeTime; /* and its length */
    /* 0x1C */ f32 fadeFrom; /* the radius it fades from */
} HRJLight; /* size = 0x20 */

/* ---- overlay functions ---- */

/* 12E3F0.c */
void func_80102800_12E3F0_HotRopeJump(void);
void func_80102C10_12E800_HotRopeJump(omObjData* obj);
void func_80102D84_12E974_HotRopeJump(omObjData* obj);
void func_80102DD0_12E9C0_HotRopeJump(omObjData* obj);
void func_80102F18_12EB08_HotRopeJump(omObjData* obj);
void func_80103060_12EC50_HotRopeJump(omObjData* obj);
void func_801031A8_12ED98_HotRopeJump(omObjData* obj);
void func_801032F0_12EEE0_HotRopeJump(omObjData* obj, s32 player);
void func_80103620_12F210_HotRopeJump(omObjData* obj);
void func_80104518_130108_HotRopeJump(omObjData* obj);
void func_8010515C_130D4C_HotRopeJump(f32 x, f32 y, f32 z);
void func_80105214_130E04_HotRopeJump(omObjData* obj, s32 motion);
void func_8010530C_130EFC_HotRopeJump(omObjData* obj, HRJPlayer* p);
void func_80105410_131000_HotRopeJump(HmfData* hmf, Vec* src, s16 idx); /* unused */
s16 func_801054E4_1310D4_HotRopeJump(omObjData* obj, s32 motion);
void* func_80105570_131160_HotRopeJump(s16 arg0, s16 arg1);
void func_80105694_131284_HotRopeJump(s16 arg0, s32 arg1, void* arg2, s16 arg3);
void func_801057B4_1313A4_HotRopeJump(void* arg0, s16 arg1, s16 arg2);
s32 func_80105AB8_1316A8_HotRopeJump(omObjData* obj);
void func_80105CD4_1318C4_HotRopeJump(void);
void func_80105D74_131964_HotRopeJump(omObjData* obj, HRJPlayer* p);
HRJPlayer* func_80105D94_131984_HotRopeJump(omObjData* obj);
void func_80105DC0_1319B0_HotRopeJump(u8 count);
s16 func_80105F80_131B70_HotRopeJump(s16 sprite, u8 flags);
void func_80106034_131C24_HotRopeJump(s16 id, f32 speed);
void func_8010605C_131C4C_HotRopeJump(s16 id, f32 x, f32 y, f32 z);
void func_8010608C_131C7C_HotRopeJump(s16 id, f32 x, f32 y, f32 z);
void func_801060BC_131CAC_HotRopeJump(s16 id, u8 flags);
void func_801060EC_131CDC_HotRopeJump(s16 id, u8 r, u8 g, u8 b, s32 a);
void func_80106124_131D14_HotRopeJump(s16 id);
void func_801061B0_131DA0_HotRopeJump(void);
void func_80107424_133014_HotRopeJump(void);
void func_8010777C_13336C_HotRopeJump(void);
void func_8010781C_13340C_HotRopeJump(f32 zoom, f32 cx, f32 cy, f32 cz, f32 rx, f32 ry, f32 rz);
void func_801078A4_133494_HotRopeJump(f32 zoom, f32 cx, f32 cy, f32 cz, f32 rx, f32 ry, f32 rz, u16 frames);
void func_80107928_133518_HotRopeJump(f32 zoom, f32 cx, f32 cy, f32 cz, f32 rx, f32 ry, f32 rz);
void func_80107A84_133674_HotRopeJump(void);
void func_80107AE8_1336D8_HotRopeJump(void);
void func_80107B4C_13373C_HotRopeJump(omObjData* obj);
void func_80107CA4_133894_HotRopeJump(s32 cam, Vec* pos, Vec* out);
f32 func_80107F54_133B44_HotRopeJump(f32 from, f32 to, f32 rate);

/* 133BA0.c */
void func_80107FB0_133BA0_HotRopeJump(void);
void func_801080A0_133C90_HotRopeJump(void);
void func_801080D8_133CC8_HotRopeJump(f32 arg0);
void func_801085B4_1341A4_HotRopeJump(omObjData* obj);
void func_801086AC_13429C_HotRopeJump(omObjData* obj);
s16 func_80108850_134440_HotRopeJump(f32 x, f32 y, f32 z, f32 radius);
void func_80108918_134508_HotRopeJump(s16 id, f32 x, f32 y, f32 z);
void func_80108978_134568_HotRopeJump(s16 id, f32 radius, f32 h);
void func_801089D4_1345C4_HotRopeJump(s16 id);
void func_801089EC_1345DC_HotRopeJump(s16 id, s32 time);
void func_80108A44_134634_HotRopeJump(Gfx** gfx);
s16 func_80109078_134C68_HotRopeJump(void);
void func_801096E4_1352D4_HotRopeJump(omObjData* obj);
void func_80109A58_135648_HotRopeJump(omObjData* obj);
void func_8010A0F0_135CE0_HotRopeJump(omObjData* obj);
void func_8010A4E4_1360D4_HotRopeJump(omObjData* obj);
s16 func_8010B0A0_136C90_HotRopeJump(const Vtx_t* vtx, HuSprite_Unk84_Struct* tex, HuSprite_Unk84_Struct* anim);
void func_8010B754_137344_HotRopeJump(HRJSeg* seg, const Vtx_t* vtx, HuSprite_Unk84_Struct* anim);
void func_8010BB48_137738_HotRopeJump(f32 t);
f32 func_8010BF04_137AF4_HotRopeJump(f32 arg0, f32 arg1, f32 arg2);
void func_8010BF70_137B60_HotRopeJump(void);
void func_8010BF80_137B70_HotRopeJump(void);
void func_8010BF8C_137B7C_HotRopeJump(f32 speed);
void func_8010BF98_137B88_HotRopeJump(f32 arg0);
void func_8010C074_137C64_HotRopeJump(Matrix4f m, f32 x, f32 y, f32 z, Vec* out);

/* ---- .data (asm, 137D00) ---- */

extern s32 D_8010C110_137D00_HotRopeJump; /* jumps to win in the 1P variant (99; 50 with the flag) */
extern s32 D_8010C114_137D04_HotRopeJump; /* game state: 0 wait, 1 intro, 2 start message, 3 play,
                                             9/10 result, 11 end */
extern s16 D_8010C118_137D08_HotRopeJump; /* all in place / the round is over */
extern u16 D_8010C11A_137D0A_HotRopeJump; /* CPU players (bits) */
extern s32 D_8010C11C_137D0C_HotRopeJump[4]; /* each player's place (0-3) */
extern s32 D_8010C12C_137D1C_HotRopeJump[4]; /* {0,1,2,3}, drawn from */
extern f32 D_8010C13C_137D2C_HotRopeJump; /* camera pan this frame */
extern s32 D_8010C140_137D30_HotRopeJump; /* _CheckFlag(0xC): the 1P variant */
extern s32 D_8010C144_137D34_HotRopeJump; /* jumps (max 255); retail reads its low half by the label D_8010C146 */
extern HRJPhase D_8010C148_137D38_HotRopeJump[5];
extern HRJPhase* D_8010C1C0_137DB0_HotRopeJump[5];
extern s32 D_8010C1D4_137DC4_HotRopeJump[4][2]; /* sprite positions (read as s16: retail's labels
                                                    D_8010C1D6/D_8010C1DA are the low halves) */
extern f32 D_8010C1F4_137DE4_HotRopeJump[4]; /* place z / 100 */
extern omObjData* D_8010C204_137DF4_HotRopeJump; /* the player the camera follows */
extern s32 D_8010C208_137DF8_HotRopeJump; /* state timer */
extern s32 D_8010C20C_137DFC_HotRopeJump;
extern f32 D_8010C210_137E00_HotRopeJump; /* last turn angle */
extern f32 D_8010C214_137E04_HotRopeJump; /* 1: the rope is over the top */
extern s32 D_8010C218_137E08_HotRopeJump; /* result timer */
extern s32 D_8010C21C_137E0C_HotRopeJump; /* turns in this phase */
extern s32 D_8010C220_137E10_HotRopeJump; /* phase */
extern s32 D_8010C224_137E14_HotRopeJump; /* fade-out countdown; retail reads its low half (D_8010C226) as the fade time */
extern u16 D_8010C228_137E18_HotRopeJump[4]; /* jump hold frames */
extern s16 D_8010C230_137E20_HotRopeJump[6]; /* bounce sounds */
extern s16 D_8010C23C_137E2C_HotRopeJump[6]; /* per character: jump voice */
extern s16 D_8010C248_137E38_HotRopeJump[6]; /* per character: arrival voice */
extern u16 D_8010C254_137E44_HotRopeJump; /* players in place (bits) */
extern s16 D_8010C258_137E48_HotRopeJump[4];
extern f32 D_8010C260_137E50_HotRopeJump; /* the lights' blend 0..1 */
extern f32 D_8010C264_137E54_HotRopeJump; /* its target */
extern f32 D_8010C268_137E58_HotRopeJump; /* its last value */
extern f32 D_8010C26C_137E5C_HotRopeJump; /* 0.9 - 0.4 * blend */
extern Gfx D_8010C270_137E60_HotRopeJump[]; /* MP1 D_800FE500: reset lists */
extern Gfx D_8010C328_137F18_HotRopeJump[];
extern Gfx D_8010C348_137F38_HotRopeJump[];
extern Gfx D_8010C360_137F50_HotRopeJump[]; /* MP1 D_800FE610: the floor's setup list */
extern u8 D_8010C3A0_137F90_HotRopeJump[4][4]; /* light colours: [0]->[1] ambient, [2]->[3] light 3, rgb + pad;
                                                    retail names each byte's label (3A1..3AE) */
extern u16 D_8010C3B0_137FA0_HotRopeJump[4]; /* floor light colour at blend 0 (rgb + pad) */
extern u16 D_8010C3B8_137FA8_HotRopeJump[4]; /* at blend 1 */
extern f32 D_8010C3C0_137FB0_HotRopeJump; /* the blend D_80111416 was made for */
extern Vtx_t D_8010C3C4_137FB4_HotRopeJump[9]; /* torch flame (MP1 D_800FE650) */
extern s16 D_8010C454_138044_HotRopeJump; /* torch/camera intro state (MP1 D_800FE6E0.state) */
extern s16 D_8010C456_138046_HotRopeJump; /* and its timer */
extern s16 D_8010C458_138048_HotRopeJump[8]; /* its state durations, 0 = the last */
extern Vtx_t D_8010C468_138058_HotRopeJump[9]; /* rope flame (MP1 D_800FE6F4) */
extern s16 D_8010C4F8_1380E8_HotRopeJump; /* MP1 D_800FE784 */
extern s16 D_8010C4FA_1380EA_HotRopeJump;
extern s16 D_8010C4FC_1380EC_HotRopeJump[6];
extern u8 D_8010C508_1380F8_HotRopeJump[0x30]; /* byte tables (labels 508..50B: S4-0CC) */
extern u8 D_8010C538_138128_HotRopeJump[0x30]; /* byte tables (labels 538..53B: S4-0CC) */
extern s32 D_8010C568_138158_HotRopeJump[6];

/* ---- .bss ---- */

extern Mtx D_8010C940_138530_HotRopeJump[3][96];
extern f32 D_80111140_13CD30_HotRopeJump; /* saved D_800BF7C0_C03C0 */
extern f32 D_80111144_13CD34_HotRopeJump; /* saved D_800BF7A4_C03A4 */
extern f32 D_80111148_13CD38_HotRopeJump; /* saved D_800BF7A8_C03A8 */
extern f32 D_8011114C_13CD3C_HotRopeJump; /* saved D_800BF7D4_C03D4 */
extern omObjData* D_80111150_13CD40_HotRopeJump; /* the control object */
extern s32 D_80111154_13CD44_HotRopeJump; /* frame buffer index, 0..2 */
extern HRJPlayer D_80111158_13CD48_HotRopeJump[4];
extern s16 D_80111318_13CF08_HotRopeJump;
extern s32 D_8011131C_13CF0C_HotRopeJump; /* sprite ids: s32 slots read as s16 (low half) */
extern s32 D_80111320_13CF10_HotRopeJump;
extern f32 D_80111324_13CF14_HotRopeJump; /* rope speed */
extern f32 D_80111328_13CF18_HotRopeJump; /* target speed */
extern f32 D_8011132C_13CF1C_HotRopeJump; /* last target speed */
extern s32 D_80111330_13CF20_HotRopeJump; /* last swing */
extern s32 D_80111334_13CF24_HotRopeJump; /* human players; -1 once the CPU allowances are drawn */
extern s32 D_80111338_13CF28_HotRopeJump; /* players left */
extern s32 D_8011133C_13CF2C_HotRopeJump; /* the human player (1P variant) */
extern s32 D_80111340_13CF30_HotRopeJump; /* 1P variant: won */
extern s32 D_80111344_13CF34_HotRopeJump; /* music tempo */
extern s32 D_80111348_13CF38_HotRopeJump; /* music tempo at the start */
extern s32 D_80111350_13CF40_HotRopeJump[4][4]; /* per player: [0] win motion, [1] lose motion */
extern s32 D_80111394_13CF84_HotRopeJump; /* billboard slots */
extern f32 D_80111398_13CF88_HotRopeJump; /* rope swing */
extern s32 D_8011139C_13CF8C_HotRopeJump;
extern s32 D_801113A0_13CF90_HotRopeJump;
extern s32 D_801113A4_13CF94_HotRopeJump;
extern s32 D_801113A8_13CF98_HotRopeJump; /* billboard model */
extern Gfx* D_801113AC_13CF9C_HotRopeJump[3];
extern s32 D_801113B8_13CFA8_HotRopeJump;
extern Gfx* D_801113BC_13CFAC_HotRopeJump[3];
extern Vtx* D_801113C8_13CFB8_HotRopeJump[3];
extern Vec D_801113D4_13CFC4_HotRopeJump; /* camera (MP1 D_801004F0..D_8010052A) */
extern Vec D_801113E0_13CFD0_HotRopeJump;
extern Vec D_801113EC_13CFDC_HotRopeJump;
extern Vec D_801113F8_13CFE8_HotRopeJump;
extern f32 D_80111404_13CFF4_HotRopeJump;
extern f32 D_80111408_13CFF8_HotRopeJump;
extern s16 D_8011140C_13CFFC_HotRopeJump;
extern s16 D_8011140E_13CFFE_HotRopeJump;
extern u8 D_80111410_13D000_HotRopeJump[6]; /* light colours now: ambient rgb, then light 3 rgb (S4-0CC) */
extern u16 D_80111416_13D006_HotRopeJump[3]; /* the floor lights' colour (rgb) */
extern u16 D_80111418_13D008_HotRopeJump; /* its labels [1], [2] */
extern u16 D_8011141A_13D00A_HotRopeJump;
extern s16 D_8011141C_13D00C_HotRopeJump; /* the centre light */
extern HRJLight D_80111420_13D010_HotRopeJump[32]; /* floor lights (MP1 D_80100538); retail also
                                                       names their fields' labels 422..43C */
extern s16 D_80111820_13D410_HotRopeJump;
extern s16 D_80111822_13D412_HotRopeJump; /* the floor model */
extern s16 D_80111824_13D414_HotRopeJump; /* floor sprite */
extern Gfx* D_80111828_13D418_HotRopeJump; /* the floor's display list */
extern s16 D_8011182C_13D41C_HotRopeJump;
extern f32 D_80111830_13D420_HotRopeJump;
extern s16 D_80111834_13D424_HotRopeJump; /* torch sprites (flame texture, animation) */
extern s16 D_80111836_13D426_HotRopeJump;
extern s16 D_80111838_13D428_HotRopeJump; /* rope sprites (flame texture, animation) */
extern s16 D_8011183A_13D42A_HotRopeJump;
extern Matrix4f D_80111840_13D430_HotRopeJump;
extern Vec D_80111880_13D470_HotRopeJump; /* intro camera: start centre, end centre, start rot, end rot, start zoom, end zoom (MP1 D_80100818..) */
extern Vec D_8011188C_13D47C_HotRopeJump;
extern Vec D_80111898_13D488_HotRopeJump;
extern Vec D_801118A4_13D494_HotRopeJump;
extern f32 D_801118B0_13D4A0_HotRopeJump;
extern f32 D_801118B4_13D4A4_HotRopeJump;
extern s32 D_801118B8_13D4A8_HotRopeJump;
extern s32 D_801118BC_13D4AC_HotRopeJump;
extern s32 D_801118C0_13D4B0_HotRopeJump;
extern s32 D_801118C4_13D4B4_HotRopeJump;
extern s32 D_801118C8_13D4B8_HotRopeJump;
extern s32 D_801118CC_13D4BC_HotRopeJump[0x13];
extern s16* D_80111918_13D508_HotRopeJump[2]; /* func_80105570's motion (main: unk1EA70StructC*) */
extern HRJSeg* D_80111920_13D510_HotRopeJump; /* rope */
extern HRJSeg* D_80111924_13D514_HotRopeJump; /* torches */
extern s32 D_80111928_13D518_HotRopeJump; /* the place-3 player's model (lit), -1 none; read as s16 (D_8011192A, the low half) */
extern s16 D_8011192A_13D51A_HotRopeJump;

/* S4-0CA */

/* S4-0CC */
#define HRJ_ABS(x) ((x) < 0 ? -(x) : (x))
extern s16 D_800FFFD6_100BD6; /* current viewport */
void func_800B1FA0_B2BA0(Mtx* m, f32 x, f32 y, f32 z); /* guTranslate */
f32 __sinf(f32);
f32 __cosf(f32);
f32 fabsf(f32);
f32 sqrtf(f32);
u8 rand8(void);
s32 PlaySound(s32);
void omSetRot(omObjData* obj, f32 x, f32 y, f32 z);
void omSetSca(omObjData* obj, f32 x, f32 y, f32 z);
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size); /* memset */
void* HuMemAlloc(s32 size);
void* SprAnimGet(s16 animIdx);
void* func_80027154_27D54(s32 size, s16 tag); /* HuMemAllocTag */
s16 func_8002838C_28F8C(s32 arg0, void (*arg1)(Gfx**), u8 arg2); /* add a draw callback */
extern u8 D_800FDBCA_FE7CA; /* vertex buffer count */
extern u8 D_800FDBE0_FE7E0; /* the frame's vertex buffer */
void func_800204C0_210C0(s32, Gfx**);
/* Labels inside D_8010C3A0_137F90_HotRopeJump[4][4]: retail addresses each byte by its own label
   (GCC folds a base register for the array). */
extern u8 D_8010C3A1_137F91_HotRopeJump;
extern u8 D_8010C3A2_137F92_HotRopeJump;
extern u8 D_8010C3A4_137F94_HotRopeJump;
extern u8 D_8010C3A5_137F95_HotRopeJump;
extern u8 D_8010C3A6_137F96_HotRopeJump;
extern u8 D_8010C3A8_137F98_HotRopeJump;
extern u8 D_8010C3A9_137F99_HotRopeJump;
extern u8 D_8010C3AA_137F9A_HotRopeJump;
extern u8 D_8010C3AC_137F9C_HotRopeJump;
extern u8 D_8010C3AD_137F9D_HotRopeJump;
extern u8 D_8010C3AE_137F9E_HotRopeJump;
void HuMemFree(void* ptr);
void func_80026D28_27928(s32);
void func_80026DAC_279AC(s32, s32, s32, s32); /* light colour */
void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3); /* light direction */
void func_800B1960_B2560(Matrix4f m, f32 ex, f32 ey, f32 ez, f32 ax, f32 ay, f32 az, f32 ux, f32 uy, f32 uz); /* guLookAtF */
s16 func_8001A2F8_1AEF8(s32 arg0);

/* ---- main-segment API used by 0C (missing from include/) ---- */

extern f32 D_800BF7A4_C03A4; /* the player motion constants (MP1 D_800B8964..D_800B8994) */
extern f32 D_800BF7A8_C03A8;
extern f32 D_800BF7C0_C03C0;
extern f32 D_800BF7D4_C03D4;
extern s32 D_800F8FD0_F9BD0; /* scene state */
extern s16 D_800FA606_FB206;
extern u16 D_801011FC_101DFC;
extern u8 D_80102720_103320; /* board.h: cleared by objmain */
extern f32 D_800FD478_FE078; /* MP1 CRot.y */

typedef struct HRJCharData {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 dir;  /* the character's file directory */
    /* 0x08 */ s32 file; /* its model file */
    /* 0x0C */ char unk_0C[0xC];
} HRJCharData; /* size = 0x18 */
extern HRJCharData D_800CD438_CE038[];

void func_8002D4D0_2E0D0(s16 n);
void func_8002F290_2FE90(s32* arg0, s32 n);
void func_8000C018_CC18(u16);
void func_8000C024_CC24(omObjData* obj, u8 idx, s8 val);
void func_8000C35C_CF5C(omObjData* obj, f32 x, f32 y, f32 z); /* obj->trans */
void func_8000C578_D178(u8);
void func_8000C6FC_D2FC(omObjData* obj, u32 dir, s32 file, u16 player, s32 arg4, s32 arg5); /* player object setup */
s32 func_80019000_19C00(omObjData* obj); /* MP1 func_80017A60 */
void func_80019114_19D14(u8 mdl);
void func_800191D4_19DD4(omObjData* obj, u8 idx, f32 x, f32 y, f32 z, f32 a, f32 b);
void func_80019378_19F78(omObjData* obj); /* MP1 func_80017DB0 */
s32 func_80019B9C_1A79C(omObjData* obj, s32 motion); /* player motion */
void func_80019E84_1AA84(omObjData* obj, u16 slot, s32 file, s32 arg3, u16 arg4);
s16* func_800231D8_23DD8(s16 arg0, s16 arg1); /* main: unk1EA70StructC* */
void func_80023A08_24608(s16 arg0, s16* arg1, s16 arg2); /* main: unk1EA70StructC* */
void func_80023D74_24974(s32);
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_800298A4_2A4A4(s16, s32, s32);      /* model attribute */
void func_8002D1EC_2DDEC(s16 arg0, u8 arg1);
void func_8002D274_2DE74(s16 arg0, u8 arg1, u8 arg2, u8 arg3); /* model light colour */
void func_8002D2B4_2DEB4(s16 arg0, f32 arg1, f32 arg2, f32 arg3); /* model light direction */
void func_80030CD4_318D4(Matrix4f, Matrix4f);
s16 func_800691FC_69DFC(s16 mesNo, ...); /* MP1 GMesCreate */
s32 func_80069538_6A138(void);           /* MP1 GMesStatAllGet */
omObjData* func_800732B0_73EB0(u32 arg0);
u16 func_80078EA8_79AA8(void);
s16 func_80079574_7A174(void); /* music tempo */
void func_80079614_7A214(s16 time); /* music fade-out */
void func_80079718_7A318(s32, s32); /* character voice */
s16 func_80079798_7A398(s16 sfx, s16 player);
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
void omSetTra(omObjData*, f32, f32, f32);
s16 LoadFormFile(s32, s32);
s16 SprAnimRead(void*);
s16 SprCreate(s32 num, s32 attr);
void SprAnimSet(s16 group, s16 member, s16 anim, u16 arg3);
void SprPosSet(s16 group, s16 member, s16 x, s16 y);
void SprScaleSet(s16 group, s16 member, f32 x, f32 y);
void SprAttrSet(s16 group, s16 member, s32 flag);
void SprBankSet(s16 group, s16 member, s16 bank);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
void func_80082488_83088(s16 group, s16 member, u16 a); /* sprite alpha */
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* cos */
f32 func_800B75A8_B81A8(f32 y, f32 x); /* atan2, degrees */
f64 fabs(f64);

#endif
