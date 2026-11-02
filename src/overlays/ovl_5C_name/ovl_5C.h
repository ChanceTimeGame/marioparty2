#ifndef _OVL_5C_H
#define _OVL_5C_H

/* Overlay 5C: Mini-Game Park. Retail's overlay is three files: 3906C0.c (80102800-80107480),
   395340.c (80107480-8010A190) and 398050.c (8010A190-end). Every function is global. .data and
   .bss stay asm (declared here); each file's .rodata is carved. Much of it is a copy of the menu
   helpers of 5B, 58 and 4E. Prototypes past 801096BC came from m2c's register use only, and the
   externs still marked m2c are by access width: the owner of a function fixes its lines.
   Flow: entry D_800CD414 0/2/4 runs the lobby 80102B78 (2 runs 8010A190 first; what 2 and 4 mean
   is not known yet), 1 runs 8010E8CC. The lobby moves a cursor over six attractions (D_80112476); A flies the
   camera (80107F28) and starts one, B asks to leave for 5B. D_80112420 0/1/2 picks return, goto or
   call of overlay D_80112F28 at entry D_80112426 in 80106DE4. */

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
#include "game/camera.h"
#include "game/board.h"

#define ABS(x) ((x) < 0.0f ? -(x) : (x))

/* ---- types ---- */

/* A selection cursor (D_80112350[i], five; the process 80105DD0 drives each one). = 58's. */
typedef struct Ovl5CCursor {
    /* 0x00 */ u8 active;       /* 0: hidden (801062AC) */
    /* 0x01 */ u8 port;         /* the pad that moves it */
    /* 0x02 */ u8 count;        /* number of slots */
    /* 0x03 */ u8 pad03;
    /* 0x04 */ s16 id;          /* cursor index; also the sprite's member */
    /* 0x06 */ s16 done;        /* 1: A pressed on the slot */
    /* 0x08 */ s16 sel;         /* slot under the cursor */
    /* 0x0A */ s16 prevSel;
    /* 0x0C */ s16 (*slots)[2]; /* slot positions x, y */
    /* 0x10 */ f32 x;
    /* 0x14 */ f32 y;
} Ovl5CCursor; /* size = 0x18 */

/* One of the scene's models (801094FC loads a -1-terminated list into D_80112F60). */
typedef struct Ovl5CModelDef {
    /* 0x00 */ s32 file;
    /* 0x04 */ s32 attr; /* | 0x288 */
    /* 0x08 */ s16 unk08;
    /* 0x0A */ s16 unk0A; /* motion mode */
    /* 0x0C */ u32 place;
    /* 0x10 */ Vec pos;
    /* 0x1C */ Vec rot;
} Ovl5CModelDef; /* size = 0x28 */

/* The fields of an esprite this overlay reads (D_800F93FC). */
typedef struct Ovl5CEsprite {
    /* 0x00 */ char pad00[0xA];
    /* 0x0A */ s16 x;
    /* 0x0C */ s16 y;
    /* 0x0E */ char pad0E[0x16];
} Ovl5CEsprite; /* size = 0x24 */

typedef struct Ovl5CPos16 {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
} Ovl5CPos16; /* size = 4 */

/* A position on the Park's paths (D_80111C24; a zero position ends the list). */
typedef struct Ovl5CPathNode {
    /* 0x00 */ Vec pos;
    /* 0x0C */ Vec unk0C;
    /* 0x18 */ f32 t; /* arrival frame (80107058) */
} Ovl5CPathNode; /* size = 0x1C */

/* A stop of a camera flight (80107F28; a zero zoom ends the list). */
typedef struct Ovl5CCamNode {
    /* 0x00 */ f32 zoom;
    /* 0x04 */ Vec at;
    /* 0x10 */ Vec rot;
    /* 0x1C */ Vec eye; /* worked out by 80107F28 */
    /* 0x28 */ f32 t;   /* arrival frame */
} Ovl5CCamNode; /* size = 0x2C */

/* One camera view (D_801106D8, through D_801129F0). */
typedef struct Ovl5CCamView {
    /* 0x00 */ Vec rot;  /* -> D_800FD474 */
    /* 0x0C */ Vec at;   /* -> D_8010274C */
    /* 0x18 */ f32 zoom; /* -> D_800FA610 */
} Ovl5CCamView; /* size = 0x1C */

/* One attraction (D_80111464, ended by base -1): indices into D_80112F60. */
typedef struct Ovl5CAttraction {
    /* 0x00 */ s16 base;
    /* 0x02 */ s16 b;     /* -1 none: follows base's height and scale */
    /* 0x04 */ s16 c;     /* -1 none: scales with base */
    /* 0x06 */ s16 mark;  /* -1 none: the marker above it */
    /* 0x08 */ f32 scale; /* marker's */
    /* 0x0C */ f32 t;     /* phase, degrees */
} Ovl5CAttraction; /* size = 0x10 */

/* An entry of main's mini-game table (D_800CAD94). */
typedef struct Ovl5CMgInfo {
    /* 0x00 */ u8 kind;
    /* 0x01 */ char pad01[7];
} Ovl5CMgInfo; /* size = 8 */

/* ---- main ---- */

extern void* D_800F93FC_F9FFC; /* 1AE60.c: EspriteSlot* */

/* main: the model draw callbacks' view fan (2E0D0 HitViewFan); D_800FA5BC is its x field, [-1]
   the angle at D_800FA5B8. One object: written through D_800FA5B8. */
extern f32 D_800FA5B8_FB1B8[];
#define D_800FA5BC_FB1BC (D_800FA5B8_FB1B8 + 1)
extern f32 D_80101078_101C78;
extern f32 D_800F8410_F9010;

/* main prototypes as 5B, 58 and 4E use them */
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
void func_800890CC_89CCC(s16, void*, s32, s32); /* a message id or a string */
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
s32 func_8008E73C_8F33C(s16 portrait, s32 x, s32 y, s32 w, s32 h, u16 flags); /* main 4D660.c: x, y s32 */
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
extern u16 D_801011FC_101DFC; /* main: set while the game resets */
void func_8001A7C8_1B3C8(u16, f32);
void func_8001A854_1B454(u16 spriteId, s32 arg1, s32 arg2);
void func_8001A89C_1B49C(u16 spriteId, s32 arg1);
void* func_80027154_27D54(s32, s32);
void func_8002D1EC_2DDEC(s16 arg0, u8 arg1);
void func_8002D274_2DE74(s16 arg0, u8 arg1, u8 arg2, u8 arg3);
void func_8002D2B4_2DEB4(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
s32 func_80075390_75F90(s32);
void func_800753D4_75FD4(s32 flag);
void func_80075424_76024(s32);
s32 func_80075478_76078(s32 flag);
void func_8007954C_7A14C(s16);
void func_800795D8_7A1D8(s16 sound, s8 volume);
s32 func_8007975C_7A35C(s16 arg0, s16 arg1);
void func_8007E128_7ED28(void);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
s16 func_80089404_8A004(s16 win_id, u32 spriteMainFsPair, s16 arg2, s16 arg3, u16 arg4);
TextWindow* func_80089674_8A274(s16);
void func_800896DC_8A2DC(s16 winId, s16 x, s16 y);
void func_8008D974_8E574(char*, s16);
void func_8008DACC_8E6CC(s32, s16*, s32);
void func_80023D74_24974(void*);
void func_800754BC_760BC(s32 flag);
void func_8007550C_7610C(s32 flag);
void func_8007E0F8_7ECF8(u8* buf);
void func_8007E150_7ED50(void);
extern u8 D_800FD420_FE020[0x12];
extern u8 D_800FD425_FE025[];
extern s8 D_800FD8B8_FE4B8;
extern f32 D_8010105C_101C5C;
extern f32 D_80101300_101F00;
extern f32 D_80102750_103350[];
extern u8 D_800FD390_FDF90[]; /* raw */
extern Vec D_800FD478_FE078; /* raw guess */
extern Ovl5CMgInfo D_800CAD94[];
extern u8 D_800F9D48_FA948[];   /* [0x2F8 + i]: per-player byte, set to i (the player order) */
extern u8 D_800FC9B8_FD5B8[];   /* [2 + i]: per-player byte, cleared; copied to stars */
extern s16 D_800FC8F0_FD4F0[];  /* [2] (0x800FC8F4) cleared */
extern s16 D_800F904A;
extern u8 D_800F9512_FA112;
extern s32 D_800FC880_FD480;   /* team mode 7: the single winner, or -1 */
void _SetFlag(s32);
void omOvlHisChg(s16 arg0, s32 overlay, s16 event, s16 stat);
s32 func_8003F6F0_402F0(s16);
extern s16 D_800FA1A8;          /* chosen item of the three-row menu (func_80103034) */
void CameraViewportSet(s16, Vec*, Vec*);
void Hu3DCamSetPerspective(s16, f32, f32, f32);
void MBMotionSet(MBModel*, s16, s32);
s16 PlayMusic(s16);
void InitFadeOut(s32, s32);
void InitFadeIn(s32, s32);
void ScissorSet(u8 arg0, f32 x1, f32 y1, f32 x2, f32 y2);
void SprPosSet(s16 grpIdx, s16 idx, s16 x, s16 y);
void MBModelInit(void);
void omInitObjMan(s32, s32);
void func_8002C59C_2D19C(s16 arg0, s16 arg1, u8 arg2, u8 arg3, u8 arg4);
void func_80050A30_51630(u8*);
void func_80056658_57258(Vec*, Vec*, Vec*); /* direction from a to b as a rotation */
void func_800581A0_58DA0(void);
void func_800593C0_59FC0(void);
void func_8005965C_5A25C(void);
void func_8005A4EC_5B0EC(s32 player, s32 reaction); /* a player's reaction */
s32 func_8005A5E8_5B1E8(MBModel* model, Vec* target, f32 speed); /* walk toward; 1 on arrival */
void func_8005E2B8_5EEB8(void);
s16 func_800691FC_69DFC(s16 mesNo, ...);
s32 func_80069538_6A138(void);
void func_80069654_6A254(s16 mesId); /* close a message */
void func_8006985C_6A45C(GAMEMES* gMes);
s16 func_8006A608_6B208(void* mes, char* str, u8 arg2, s16 arg3, s16 arg4); /* MP1 GMesFontMesCreate */
s16 func_8006A67C_6B27C(GAMEMES*, char*, u8, s16, s16);
void func_800797DC_7A3DC(s32, s16);
HuSprite* func_80082550_83150(s16 grpIdx, s16 idx);
void func_80088640_89240(void);
void func_8008D904_8E504(s16 winId, s32, s8);
extern u8 D_800CB150;
void MBDBackKill(void);
void func_80050AE0_516E0(void);
MBModel* func_80043510_44110(s32, void*);
void func_8001A708_1B308(u16, u16);
void MBModelDispOff(MBModel*);
void MBModelDispOn(MBModel*);
f32 HuVecDistance(Vec*, Vec*);
void MBModelKill(void*);
void MBMotionShiftSet(void* arg0, s16 arg1, s32 arg2, s32 arg3, u16 arg4);

void func_80079128_79D28(void);
void func_80079920_7A520(void);
void func_8002A15C_2AD5C(s16 model, s16 other, f32 blend);
void func_8002D0A0_2DCA0(s16 model, u8 alpha);
void func_8002D124_2DD24(s16 model);
f32 func_8002662C_2722C(f32* p, f32* t, f32 time);
void func_8008D59C_8E19C(s16 win, s16 mask);
void func_800B1E50_B2A50(f32 m[4][4], f32 x, f32 y, f32 z);


extern u16 D_800CD526_CE126;
extern s16 D_800FFE00_100A00[]; /* 21920.c: [6][3][13]; [0xEA] is the word past it, 80102B78 clears it */

/* ---- data ---- */
extern s16 D_801106D0_39E590_name_5C; /* m2c */
extern u16 D_801106D2_39E592_name_5C;
extern s16 D_801106D4_39E594_name_5C; /* m2c */
extern Ovl5CCamView D_801106D8_39E598_name_5C[];
extern Ovl5CCamNode D_80110A3C_39E8FC_name_5C[];
extern Ovl5CCamNode D_80110B44_39EA04_name_5C[];
extern Ovl5CCamNode D_80110C4C_39EB0C_name_5C[];
extern Ovl5CCamNode D_80110D54_39EC14_name_5C[];
extern Ovl5CCamNode D_80110E5C_39ED1C_name_5C[];
extern Ovl5CModelDef D_80110F64_39EE24_name_5C[];
extern Vec D_80111138_39EFF8_name_5C; /* record board model rotation */
extern Ovl5CAttraction D_80111464_39F324_name_5C[];
extern s16 D_801114B6_39F376_name_5C;
extern s32 D_801114EC_39F3AC_name_5C[7]; /* the record page's mini-game of each line (labels: D_801114EE = [0] low half) */
extern s32 D_801114D4_39F394_name_5C[6]; /* message of each attraction; [1] depends on progress */
extern s32 D_80111508_39F3C8_name_5C[]; /* no direct code user yet */
extern s32 D_80111620_39F4E0_name_5C[]; /* no direct code user yet */
extern s32 D_80111834_39F6F4_name_5C[]; /* no direct code user yet */
extern s32 D_801119A0_39F860_name_5C[]; /* no direct code user yet */
extern Ovl5CPathNode* D_80111C24_39FAE4_name_5C[4];
extern s16 D_80111C34_39FAF4_name_5C; /* m2c */
extern f32 D_80111C40_39FB00_name_5C; /* m2c */
extern s8 D_80111C44_39FB04_name_5C; /* m2c */
extern s32 D_80111C50_39FB10_name_5C; /* m2c */
extern s32 D_80111C60_39FB20_name_5C; /* m2c */
extern s32 D_801120B0_39FF70_name_5C; /* m2c */
extern s32 D_801120BC_39FF7C_name_5C; /* m2c */
extern s16 D_801120C2_39FF82_name_5C; /* m2c */
extern s16 D_801120C4_39FF84_name_5C; /* m2c */
extern s32 D_801120C8_39FF88_name_5C; /* m2c */
extern s16 D_80112158_3A0018_name_5C; /* m2c */
extern s32 D_8011215C_3A001C_name_5C; /* m2c */
extern s32 D_80112174_3A0034_name_5C; /* m2c */
extern s32 D_80112176_3A0036_name_5C; /* m2c */

/* ---- bss ---- */
extern s16 D_80112330_3A01F0_name_5C; /* m2c */
extern s16 D_80112332_3A01F2_name_5C; /* m2c */
extern s16 D_80112334_3A01F4_name_5C; /* m2c */
extern s16 D_80112336_3A01F6_name_5C; /* m2c */
extern Process* D_80112338_3A01F8_name_5C[6]; /* 80105DD0 processes */
extern Ovl5CCursor* D_80112350_3A0210_name_5C[6]; /* 58-B: 5 used */
extern s16 D_80112364_3A0224_name_5C;
extern s16 D_80112366_3A0226_name_5C; /* m2c */
extern s16 D_80112368_3A0228_name_5C; /* m2c */
extern s16 D_8011236A_3A022A_name_5C;   /* the message window */
extern s16 D_8011236C_3A022C_name_5C; /* m2c */
extern s16 (*D_80112370_3A0230_name_5C)[2]; /* 58-E: cursor slot positions (80111744) */
extern s16 D_80112374_3A0234_name_5C; /* 58-E: cursor x */
extern s16 D_80112376_3A0236_name_5C; /* 58-E: cursor y */
extern s16 D_80112378_3A0238_name_5C; /* 58-E: cursor glide frames */
extern s16 D_8011237A_3A023A_name_5C; /* cursor slot (-1 none) */
extern s16 D_8011237C_3A023C_name_5C; /* m2c */
extern s16 D_8011237E_3A023E_name_5C; /* m2c */
extern s16 D_80112380_3A0240_name_5C; /* m2c */
extern s32 D_80112384_3A0244_name_5C; /* m2c */
extern s32 D_80112390_3A0250_name_5C; /* m2c */
extern s16 D_801123A0_3A0260_name_5C; /* m2c */
extern s16 D_801123A2_3A0262_name_5C; /* m2c */
extern s16 D_801123A4_3A0264_name_5C; /* m2c */
extern s32 D_801123A6_3A0266_name_5C; /* m2c */
extern s16 D_801123AA_3A026A_name_5C; /* m2c */
extern s32 D_801123AC_3A026C_name_5C; /* m2c */
extern s16 D_801123AE_3A026E_name_5C; /* m2c */
extern s16 D_801123B0_3A0270_name_5C; /* m2c */
extern s16 D_801123B2_3A0272_name_5C; /* m2c */
extern s16 D_801123B4_3A0274_name_5C; /* m2c */
extern s32 D_801123B6_3A0276_name_5C; /* m2c */
extern s16 D_801123C0_3A0280_name_5C; /* m2c */
extern u16 D_801123C2_3A0282_name_5C; /* m2c */
extern u16 D_801123C4_3A0284_name_5C; /* m2c */
extern s32 D_801123C6_3A0286_name_5C; /* m2c */
extern u16 D_801123C8_3A0288_name_5C; /* m2c */
extern s16 D_801123CA_3A028A_name_5C; /* m2c */
extern s16 D_801123CC_3A028C_name_5C; /* m2c */
extern s16 D_801123CE_3A028E_name_5C; /* m2c */
extern s16 D_801123D0_3A0290_name_5C; /* m2c */
extern s32 D_801123D2_3A0292_name_5C; /* m2c */
extern s32 D_801123E1_3A02A1_name_5C; /* m2c */
extern s16 D_801123F0_3A02B0_name_5C; /* m2c */
extern s16 D_801123F2_3A02B2_name_5C; /* m2c */
extern u16 D_801123F4_3A02B4_name_5C; /* m2c */
extern s32 D_801123F6_3A02B6_name_5C; /* m2c */
extern s16 D_80112400_3A02C0_name_5C; /* m2c */
extern s32 D_80112408_3A02C8_name_5C; /* m2c */
extern s16 D_80112420_3A02E0_name_5C; /* m2c */
extern s16 D_80112422_3A02E2_name_5C; /* m2c */
extern s16 D_80112424_3A02E4_name_5C; /* 1 while 80103F38 takes the player count */
extern s16 D_80112426_3A02E6_name_5C; /* m2c */
extern s16 D_80112428_3A02E8_name_5C[3]; /* compared with D_80112440 */
extern s16 D_8011242A_3A02EA_name_5C; /* m2c */
extern s16 D_8011242C_3A02EC_name_5C; /* m2c */
extern s16 D_8011242E_3A02EE_name_5C; /* m2c */
extern s16 D_80112430_3A02F0_name_5C; /* m2c */
extern s16 D_8011243A_3A02FA_name_5C; /* m2c */
extern s16 D_80112440_3A0300_name_5C[3];
extern u16 D_80112442_3A0302_name_5C; /* m2c */
extern u16 D_80112444_3A0304_name_5C; /* m2c */
extern s16 D_80112448_3A0308_name_5C; /* m2c */
extern s8 D_80112458_3A0318_name_5C[30]; /* 58-B: cursor on each slot, -1 none */
extern s8 D_8011245A_3A031A_name_5C; /* m2c */
extern s8 D_8011245B_3A031B_name_5C; /* m2c */
extern s8 D_8011245C_3A031C_name_5C; /* m2c */
extern s16 D_80112476_3A0336_name_5C; /* attraction under the cursor */
extern f32 D_80112478_3A0338_name_5C; /* m2c */
extern s16 D_80112498_3A0358_name_5C[58]; /* each model's motion (8010A0F0); labels 7E0-838 are elements */
extern s32 D_801124A6_3A0366_name_5C; /* m2c */
extern s16 D_801124C8_3A0388_name_5C; /* m2c */
extern s16 D_801124CA_3A038A_name_5C; /* m2c */
extern s16 D_801124CC_3A038C_name_5C; /* m2c */
extern s16 D_801124D2_3A0392_name_5C; /* m2c */
extern s16 D_801124D6_3A0396_name_5C; /* a count from 8010E2AC; 10, 20, 30, 42 trigger messages in 80102B78 */
extern s16 D_801124D8_3A0398_name_5C; /* m2c */
extern s32 D_801124E0_3A03A0_name_5C; /* m2c */
extern s32 D_80112570_3A0430_name_5C; /* m2c */
extern s32 D_80112600_3A04C0_name_5C; /* m2c */
extern Ovl5CCamView* D_801129F0_3A08B0_name_5C; /* the current list of views */
extern Vec D_801129F4_3A08B4_name_5C; /* camera position (801086E0) */
extern s16 D_80112A00_3A08C0_name_5C; /* m2c */
extern u8 D_80112A01_3A08C1_name_5C; /* m2c */
extern Vec2f D_80112A04_3A08C4_name_5C; /* last projected screen position */
extern s32 D_80112A10_3A08D0_name_5C; /* m2c */
extern s16 D_80112F20_3A0DE0_name_5C; /* m2c */
extern f32 D_80112F24_3A0DE4_name_5C; /* camera near */
extern s16 D_80112F28_3A0DE8_name_5C; /* m2c */
extern Vec D_80112F2C_3A0DEC_name_5C; /* fixed camera target (80109B1C) */
extern u16 D_80112F38_3A0DF8_name_5C; /* esprite freed on leaving */
extern s32 D_80112F40_3A0E00_name_5C; /* m2c */
extern u16 D_80112F46_3A0E06_name_5C; /* m2c */
extern u16 D_80112F48_3A0E08_name_5C; /* m2c */
extern f32 D_80112F54_3A0E14_name_5C; /* camera far */
extern u16 D_80112F58_3A0E18_name_5C; /* m2c */
extern s16 D_80112F5A_3A0E1A_name_5C; /* m2c */
extern u16 D_80112F5C_3A0E1C_name_5C; /* m2c */
extern s16 D_80112F60_3A0E20_name_5C[60]; /* model per D_80110F64 entry */
extern u16 D_80112F90_3A0E50_name_5C; /* m2c */
extern s16 D_80112F94_3A0E54_name_5C; /* m2c */
extern s32 D_80112F96_3A0E56_name_5C; /* m2c */
extern u16 D_80112F9A_3A0E5A_name_5C; /* m2c */
extern s16 D_80112F9C_3A0E5C_name_5C; /* m2c */
extern Vec D_80112FA0_3A0E60_name_5C; /* fixed camera eye (80109B1C) */
extern Ovl5CPos16 D_80112FB0_3A0E70_name_5C[];
extern s32 D_80112FB2_3A0E72_name_5C; /* m2c */
extern s16 D_80113028_3A0EE8_name_5C; /* m2c */

/* ---- functions ---- */
void func_80102800_3906C0_name_5C(void);
void func_80102AB0_390970_name_5C(void);
void func_80102B78_390A38_name_5C(void);
void func_80103770_391630_name_5C(void);
void func_801038A8_391768_name_5C(s16* t);
void func_8010392C_3917EC_name_5C(s16* t);
void func_801039A8_391868_name_5C(s16 total, s16 idx, s16 frame);
void func_80103A10_3918D0_name_5C(s16 total, s16 idx, s16 frame);
void func_80103A54_391914_name_5C(s16 total, s16 idx, s16 frame);
void func_80103B30_3919F0_name_5C(void);
void func_80103D08_391BC8_name_5C(void);
void func_80103E1C_391CDC_name_5C(void);
s32 func_80104484_392344_name_5C(void);
s32 func_80104F88_392E48_name_5C(void);
s16 func_801054F0_3933B0_name_5C(s16 x, s16 y);
s16 func_801055BC_39347C_name_5C(s16 x, s16 y);
void func_80105688_393548_name_5C(void);
void func_80105DB0_393C70_name_5C(s16 i);
void func_80105DD0_393C90_name_5C(void);
void func_801062AC_39416C_name_5C(s16 cursor, s8 active);
void func_801062C8_394188_name_5C(s16 cursor, s16 slot);
void func_80106348_394208_name_5C(s16 cursor, s16 slot);
s16 func_80106378_394238_name_5C(s16 cursor);
void func_80106394_394254_name_5C(s16 cursor, s16 done);
s16 func_801063B0_394270_name_5C(s16 cursor);
void func_801063CC_39428C_name_5C(s16 (*slots)[2], s8 count);
void func_80106418_3942D8_name_5C(void);
void func_801064D4_394394_name_5C(s32 mes);
s32 func_80106500_3943C0_name_5C(void);
void func_80106588_394448_name_5C(void);
void func_801065AC_39446C_name_5C(void);
void func_801065D0_394490_name_5C(char* str, s32 unused);
void func_801065F8_3944B8_name_5C(void);
void func_80106618_3944D8_name_5C(s16 model, s32 spr, char* part);
void func_801066D4_394594_name_5C(s32 model, s32 spr, char* part);
void func_801067BC_39467C_name_5C(s16 i, s16 esp, s32 dx, s32 dy);
void func_80106810_3946D0_name_5C(s16 i, Vec2f* pos, s16 dx, s16 dy);
void func_8010687C_39473C_name_5C(void);
s16 func_801068BC_39477C_name_5C(s16 cur, s16 n, s16 dx, s16 dy);
void func_80106C0C_394ACC_name_5C(void);
void func_80106D70_394C30_name_5C(omObjData* obj);
void func_80106DE4_394CA4_name_5C(omObjData* obj);
void func_80106EB8_394D78_name_5C(void);
f32 func_80107058_394F18_name_5C(Ovl5CPathNode* path, f32 speed);
void func_801071E4_3950A4_name_5C(Ovl5CPathNode* path, s16 model, f32 total);
void func_80107480_395340_name_5C(s16 arg0);
void func_80107660_395520_name_5C(s16 view, s16 time, s16 mode, void (*cb)(s16*));
void func_80107F28_395DE8_name_5C(Ovl5CCamNode* path, f32 speed, void (*cb)(s16, s16, s16));
void func_801084C4_396384_name_5C(void);
void func_80108758_396618_name_5C(void);
void func_801088A8_396768_name_5C(s16 n);
void func_801088E0_3967A0_name_5C(s16 (*slots)[2]);
void func_801088EC_3967AC_name_5C(s16 time);
void func_801088F8_3967B8_name_5C(s16 slot);
void func_80108904_3967C4_name_5C(void);
void func_80108F28_396DE8_name_5C(void);
void func_801094FC_3973BC_name_5C(Ovl5CModelDef* defs);
void func_801095F0_3974B0_name_5C(Ovl5CModelDef* defs, s16 i, s16 model);
void func_801096BC_39757C_name_5C(Ovl5CModelDef* defs, s16 place);
void func_801097A4_397664_name_5C(void);
void func_801098A4_397764_name_5C(s16 model, Vec2f* out, f32 mtx[4][4]); /* a model point on screen */
void func_801098E4_3977A4_name_5C(void *arg1, void *arg2);
void func_80109BEC_397AAC_name_5C(s16 view, f32 depth, Vec2f* scr, Vec* out); /* screen point to world */
s16 func_80109EA4_397D64_name_5C(void);
void func_80109F9C_397E5C_name_5C(s16 arg0);
void func_8010A0D0_397F90_name_5C(void);
void func_8010A190_398050_name_5C(void);
void func_8010B050_398F10_name_5C(void *arg0);
void func_8010B08C_398F4C_name_5C(void);
s16 func_8010B16C_39902C_name_5C(s16 arg0);
void func_8010B96C_39982C_name_5C(s16 arg0);
s16 func_8010BA98_399958_name_5C(s16 arg0);
void func_8010D93C_39B7FC_name_5C(s16 arg0);
void func_8010DAD4_39B994_name_5C(s16 arg0, s16 arg1, s16 arg2);
void func_8010DD00_39BBC0_name_5C(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void func_8010DF5C_39BE1C_name_5C(void);
void func_8010E2AC_39C16C_name_5C(void);
void func_8010E318_39C1D8_name_5C(void);
void func_8010E560_39C420_name_5C(u32 arg0);
void func_8010E6D4_39C594_name_5C(u32 arg0);
void func_8010E7C4_39C684_name_5C(void);
void func_8010E848_39C708_name_5C(s16 arg0, s16 arg1, s32 arg3);
void func_8010E8CC_39C78C_name_5C(void);
s32 func_8010EE64_39CD24_name_5C(void);
void func_8010FB28_39D9E8_name_5C(s32 arg0, s32 arg1);
void func_8010FBDC_39DA9C_name_5C(s32 arg0, s16 arg1);
void func_8010FC20_39DAE0_name_5C(void);
void func_8010FFDC_39DE9C_name_5C(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_80110020_39DEE0_name_5C(void);

#endif
