#ifndef OVL_5E_H
#define OVL_5E_H

/* Overlay 5E: Mini-Game Park's minigame instructions screen (MP3 mgenter/mgmode ancestor). Shows the
   chosen minigame's rules, the screenshot pages, then START goes to the minigame, B back. */

#include "common.h"
#include "process.h"
#include "game/data.h"
#include "game/malloc.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/sprite.h"
#include "game/window.h"
#include "game/gamemes.h"
#include "game/gamework.h"
#include "game/pad.h"
#include "game/camera.h"

/* The three-at-once words of one rules text per page (80103388). */
typedef struct Ovl5EPageText {
    /* 0x000 */ GAMEMES mes[6];
    /* 0x2B8 */ s16 id[6];
} Ovl5EPageText;

/* main (1AE60.c EspriteSlot) */
typedef struct Ovl5EEsprite {
    /* 0x00 */ s16 pad00[2];
    /* 0x04 */ s16 unk4; /* sprite group */
    /* 0x06 */ u8 pad06[0x1E];
} Ovl5EEsprite; /* size 0x24 */

/* main */
void ExecBoardScene(void*, s16);
void func_80020070_20C70(s32);
void func_8002D4D0_2E0D0(s16 n);
void func_80020D20_21920(s16 arg0);
void func_80026D28_27928(s32);
void omPrcSetStatBit(Process*, s32);
void func_80029708_2A308(s32);
void func_8002CA48_2D648(u8 arg0, u8 arg1, u8 arg2);
s16 func_8001AAAC_1B6AC(s16 arg0, s32 arg1, s32 arg2);
s16 func_8001A2F8_1AEF8(s32 arg0);
void espPosSet(u16 spriteId, s16 x, s16 y);
void espDispOn(u16);
void espDispOff(u16);
void func_8001A788_1B388(u16 spriteId, s32 arg1);
void func_8001A6BC_1B2BC(u16 spriteId, s16 arg1);
void func_8001AC44_1B844(u16 arg0);
void SprAnimKill(s16 animIdx);
void SprPosSet(s16 grpIdx, s16 idx, s16 x, s16 y);
void func_8008DACC_8E6CC(s32, s16*, s32);
s32 func_8008E73C_8F33C(s16 portrait, s32 x, s32 y, s32 w, s32 h, u16 flags);
void func_80089A48_8A648(s16, s16);
void func_8008E978_8F578(s16 winId);
void func_800890CC_89CCC(s16, void*, s32, s32); /* a message id or a string */
s16 func_8008BA30_8C630(s16 winId);
void func_8008CCA8_8D8A8(s16);
void* func_80068CD4_698D4(s32 stringIndex);
void func_80068D24_69924(void* file);
s16 func_8006A608_6B208(void* mes, char* str, u8 arg2, s16 arg3, s16 arg4); /* MP1 GMesFontMesCreate */
HuSprite* func_80082550_83150(s16 grpIdx, s16 idx);
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32);
f32 func_800B1830_B2430(f32);
void* func_80027154_27D54(s32, s32);
void HuMemFree(void* ptr);
void func_80096188_96D88(u8* code, u16* outbuf, s32 outbufWidth, u8* workbuf);
void func_80096708_97308(void* header);
void func_80096C10_97810(u8 alpha);
void Hu3DCamUpdateMtx(s16 camIndex);
void Hu3DCamSetPositionOrientation(s16, Vec*, Vec*, Vec*);
s32 PlaySound(s32);

extern s16 D_800FD80C_FE40C;
extern s16 D_800CAFEE; /* main (3D6A0.c): the minigame variant override, -1 none */
extern s8 ContStkX[4];
extern u16 D_801011FC_101DFC; /* main: set while the game resets */
extern Ovl5EEsprite* D_800F93FC_F9FFC;
/* main: the model draw callbacks' view fan (2E0D0 HitViewFan); D_800FA5BC is its x field, [-1]
   the angle at D_800FA5B8. One object: written through D_800FA5B8. */
extern f32 D_800FA5B8_FB1B8[];
#define D_800FA5BC_FB1BC (D_800FA5B8_FB1B8 + 1)
extern f32 D_80101078_101C78;
extern f32 D_800F8410_F9010;

/* .data */
extern board_overlay_entrypoint D_80104C50_3AB8B0_name_5E[];
extern u16 D_80104C70_3AB8D0_name_5E; /* set: the scene ends (80103E08) */
extern s16 D_80104C72_3AB8D2_name_5E;
extern s16 D_80104C74_3AB8D4_name_5E[72]; /* per minigame: -1, or its index in the next two tables */
extern s32 D_80104D04_3AB964_name_5E[5];  /* message ids */
extern s16 D_80104D18_3AB978_name_5E[12]; /* string ids of the page captions */
extern f32 D_80104D30_3AB990_name_5E;     /* camera fov */
extern s8 D_80104D34_3AB994_name_5E[12];  /* [0] set: camera uses the fixed eye/at (80104390) */

/* .bss */
extern s16 D_80104D8E_3AB9EE_name_5E; /* set: 80103A4C moves the arrows */
extern s16 D_80104D90_3AB9F0_name_5E; /* arrows shown */
extern s16 D_80104D92_3AB9F2_name_5E; /* 0 starts the title slide-in, then -1 */
extern s16 D_80104D94_3AB9F4_name_5E; /* 0 starts the page slide-in, then -1 */
extern s16 D_80104D96_3AB9F6_name_5E; /* minigame index, 0-based */
extern s16 D_80104D98_3AB9F8_name_5E; /* page */
extern s16 D_80104D9A_3AB9FA_name_5E; /* page count */
extern s16 D_80104D9C_3AB9FC_name_5E; /* page turn: 1, -1, 0 none */
extern s16 D_80104D9E_3AB9FE_name_5E; /* left arrow x */
extern s16 D_80104DA0_3ABA00_name_5E; /* right arrow x */
extern s16 D_80104DA2_3ABA02_name_5E; /* left arrow y */
extern s16 D_80104DA4_3ABA04_name_5E; /* right arrow y */
extern s16 (*D_80104DB0_3ABA10_name_5E)[2]; /* cursor slot positions */
extern s16 D_80104DB4_3ABA14_name_5E;       /* cursor x */
extern s16 D_80104DB6_3ABA16_name_5E;       /* cursor y */
extern s16 D_80104DB8_3ABA18_name_5E;       /* cursor glide frames */
extern s16 D_80104DBA_3ABA1A_name_5E;       /* cursor slot, -1 none */
extern s16 D_80104DBC_3ABA1C_name_5E;       /* screenshot sprite file */
extern s16 D_80104DBE_3ABA1E_name_5E;       /* screenshot sprite */
extern s16 D_80104DC0_3ABA20_name_5E;       /* next of the three buffers */
extern void* D_80104DC4_3ABA24_name_5E[3];  /* screenshot buffers, 0x6000 each */
extern void* D_80104DD0_3ABA30_name_5E;     /* the sprite's own image */
extern s16 D_80104DE0_3ABA40_name_5E;       /* cursor shown */
extern f32 D_80104DE4_3ABA44_name_5E;       /* camera near */
extern s16 D_80104DF4_3ABA54_name_5E;       /* the controller */
extern s16 D_80104DF6_3ABA56_name_5E;       /* the next overlay */
extern f32 D_80104DF8_3ABA58_name_5E;       /* camera far */
extern s16 D_80104DFC_3ABA5C_name_5E;       /* exit: 0 return, 1 goto, 2 call */
extern s16 D_80104E04_3ABA64_name_5E;       /* cursor sprite */
extern Vec D_80104E08_3ABA68_name_5E;       /* fixed camera target (80104390) */
extern s16 D_80104E18_3ABA78_name_5E;       /* next overlay's entry */
extern Vec D_80104E24_3ABA84_name_5E;       /* fixed camera eye (80104390) */

void func_80102800_3A9460_name_5E(void);
void func_80102830_3A9490_name_5E(void);
void func_801029F8_3A9658_name_5E(void);
void func_80102A64_3A96C4_name_5E(void);
void func_80102E34_3A9A94_name_5E(void);
void func_80103174_3A9DD4_name_5E(void);
void func_8010331C_3A9F7C_name_5E(u8* str);
void func_80103388_3A9FE8_name_5E(void);
void func_80103A1C_3AA67C_name_5E(s16 x0, s16 y0, s16 x1, s16 y1);
void func_80103A4C_3AA6AC_name_5E(void);
void func_80103C7C_3AA8DC_name_5E(void);
void func_80103E08_3AAA68_name_5E(omObjData* obj);
void func_80103E98_3AAAF8_name_5E(omObjData* obj);
void func_80103F50_3AABB0_name_5E(void);
void func_801041E4_3AAE44_name_5E(void);
void func_80104334_3AAF94_name_5E(s16 n);
void func_8010436C_3AAFCC_name_5E(s16 (*table)[2]);
void func_80104378_3AAFD8_name_5E(s16 frames);
void func_80104384_3AAFE4_name_5E(s16 slot);
void func_80104390_3AAFF0_name_5E(void);
s16 func_80104964_3AB5C4_name_5E(void);
void func_80104A5C_3AB6BC_name_5E(s16 file);
void func_80104B90_3AB7F0_name_5E(void);

#endif /* OVL_5E_H */
