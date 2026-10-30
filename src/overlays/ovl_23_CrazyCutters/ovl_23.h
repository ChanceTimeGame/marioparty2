#ifndef _OVL_23_H
#define _OVL_23_H

/* Overlay 23: Crazy Cutters (4 players, free for all), descended from MP1's ovl_0D_CrazyCutter
   (1250D0.c, 12AFE0.c, CrazyCutter.h). Each player traces the dotted outline of one of three shapes
   (D_80109918, from the minigame variant D_800FA656) in a quarter of the screen with a cutter; the
   score is the share of the outline cut. Two retail files: 1E1C50.c (game) and 1E7CC0.c (from
   80108870: image pixel helpers, MP1 12AFE0.c). .data stays asm; .rodata is carved
   ([0x1E8840, .rodata, 1E1C50]; 1E7CC0.c has none). */

#include "common.h"
#include "game/object.h"
#include "game/sprite.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/data.h"
#include "game/malloc.h"

/* ---------------------------------------------------------------------------------------------
   Main-segment API (missing from include/)
   --------------------------------------------------------------------------------------------- */

void func_8002D4D0_2E0D0(s16 n);
void func_80020D20_21920(s16 arg0);
void func_80076BD0_777D0(s32, s32);
void func_8002CA48_2D648(u8 arg0, u8 arg1, u8 arg2);
s16 func_800691FC_69DFC(s16 mesNo, ...); /* MP1 GMesCreate */
s32 func_80069538_6A138(void);          /* MP1 GMesStatAllGet */
s32 func_800696E4_6A2E4(void);          /* MP1 GMesWait */
void func_8006D4D0_6E0D0(s16);          /* the seconds counter (MP1 func_80079078) */
void func_8006D518_6E118(void);         /* MP1 func_800790C0 */
s32 PlaySound(s32);
void func_80079848_7A448(s16 id); /* stop a sound (MP1 func_8006071C) */
void omDelObj(omObjData*);
void omSetTra(omObjData*, f32, f32, f32);
void omSetRot(omObjData*, f32, f32, f32);
void omSetSca(omObjData*, f32, f32, f32);
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3); /* MP1 func_80060F04 */
u16 LoadFormFile(s32, s32); /* util.c */
void* func_80027154_27D54(s32, s32); /* HuMemAllocTag */
s32 func_80027D3C_2893C(s16 linkMdlId); /* model copy; s16 in main: 80105B40 stores the result unextended */
void func_80018CCC_198CC(omObjData* obj, u16 slot, s32 file); /* loads obj->motion[slot] */
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void func_8002979C_2A39C(s16, f32, f32, f32); /* model rotation */
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_800298A4_2A4A4(s16, s32, s32);      /* model attribute */
void func_80029A8C_2A68C(s16);
void func_80029AFC_2A6FC(s16);
void func_80029B80_2A780(s16 arg0, s16 arg1); /* model motion */
f32 func_80029CE4_2A8E4(s16);
f32 func_80029D0C_2A90C(s16); /* motion length */
void func_8002A00C_2AC0C(s16);
void func_8002AC10_2B810(s16, f32, f32, s32);
void func_800283DC_28FDC(s16 arg0);
void func_8002D0A0_2DCA0(s16, u8); /* model alpha */
void func_8002D124_2DD24(s16 index);
void func_8003E4F4_3F0F4(s16 arg0, u8 arg1, u8 arg2);
void Hu3DCam3DToScreen(s16 camIndex, Vec* worldPos, Vec2f* outPos);
void HmfModelObjAttrSet(s16, s32, s32);
f32 HuMathSin(f32);
f32 fabsf(f32);
f32 func_800B7890_B8490(f32);          /* cos */
f32 func_800B1830_B2430(f32);          /* sqrtf */
f32 func_800B75A8_B81A8(f32 y, f32 x); /* atan2, degrees */
s16 func_8001A2F8_1AEF8(s32 arg0);
s16 func_8001AAAC_1B6AC(s16 arg0, u16 arg1, u16 arg2);
void func_8001A708_1B308(u16, u16);
void func_8001A91C_1B51C(u16 spriteId, f32 x, f32 y);
void espDispOn(u16);
void espPosSet(u16 spriteId, s16 x, s16 y);
s16 SprAnimRead(void*);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprAttrSet(s16, s16, s32);
void SprAttrReset(s16 grpIdx, s16 idx, s32 flag);
s16 SprCreate(s32 num, s32 attr);
void SprKill(s16 idx);
void SprPosSet(s16 grpIdx, s16 idx, s16 x, s16 y);
void SprScaleSet(s16 group, s16 member, f32 x, f32 y);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
void func_800822A8_82EA8(s16 group, s16 member, u16 arg2, s32 arg3);
void func_80082488_83088(s16 grpIdx, s16 idx, u16 a); /* sprite alpha */
void func_800824F4_830F4(s16 group, s16 member, s16 arg2);
HuSprite* func_80082550_83150(s16 grpIdx, s16 idx);
/* 73BA0.c defines arg3 s16; retail passes a full word here (lw) */
omObjData* func_80073328_73F28(u32 arg0, s16 arg1, s16 arg2, s32 arg3);
u16 func_80078EA8_79AA8(void);

extern s8 ContStkX[4];
extern s8 ContStkY[4];
extern u8 D_800FA656;          /* minigame variant: the shape */
extern u16 D_801011FC_101DFC;  /* nonzero once the minigame is told to end */
extern void* D_800F93FC_F9FFC; /* 1AE60.c: EspriteSlot* */

/* ---------------------------------------------------------------------------------------------
   Structs
   --------------------------------------------------------------------------------------------- */

/* One player's cutter (omObjData::unk_50 of the func_80103508 objects; MP1 CrazyCutterPlayer
   0x51C). MP2 adds the two 10-entry arrays at 0x3F8/0x420; MP1's fields from 0x3F8 on sit +0x50. */
typedef struct CCPlayer {
    /* 0x000 */ f32 x;
    /* 0x004 */ f32 y;
    /* 0x008 */ f32 z;
    /* 0x00C */ f32 prevX;
    /* 0x010 */ f32 prevZ;
    /* 0x014 */ f32 rotX;
    /* 0x018 */ f32 rotY;
    /* 0x01C */ f32 rotZ;
    /* 0x020 */ f32 velX;
    /* 0x024 */ f32 angle;
    /* 0x028 */ s32 unk28;
    /* 0x02C */ f32 unk2C;
    /* 0x030 */ s32 player;
    /* 0x034 */ s32 moving;
    /* 0x038 */ s32 trailX[60]; /* last positions, newest first */
    /* 0x128 */ s32 trailY[60];
    /* 0x218 */ s32 visitedX[60]; /* distinct positions (30 used) */
    /* 0x308 */ s32 visitedY[60];
    /* 0x3F8 */ s32 lastX[10]; /* MP2: the last 10 positions (func_80105098) */
    /* 0x420 */ s32 lastY[10];
    /* 0x448 */ s32 unk448;
    /* 0x44C */ s32 unk44C;
    /* 0x450 */ s32 unk450;
    /* 0x454 */ f32 startX;
    /* 0x458 */ f32 startZ;
    /* 0x45C */ f32 velZ;
    /* 0x460 */ s32 timer;
    /* 0x464 */ s32 state;
    /* 0x468 */ s16 unk468; /* motion handles of the two cutter models */
    /* 0x46A */ s16 unk46A;
    /* 0x46C */ s32 difficulty;
    /* 0x470 */ s32 visitedCount;
    /* 0x474 */ s32 pathX[30]; /* CPU route (-3: start, -2: end) */
    /* 0x4EC */ s32 pathY[30];
    /* 0x564 */ s32 target;
    /* 0x568 */ s32 unk568; /* rumble countdown (MP1 unk518) */
    /* 0x56C */ s32 startGX; /* MP2: the start point in grid units */
    /* 0x570 */ s32 startGY;
} CCPlayer; /* size = 0x574 */

/* One falling piece (omObjData::unk_50 of the func_80105B40 objects; MP1 CrazyCutterPiece 0x44).
   S4-23B: from MP1 only, check against the asm (MP2 allocates 0x48). */
typedef struct CCPiece {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
    /* 0x0C */ f32 rotX;
    /* 0x10 */ f32 rotY;
    /* 0x14 */ f32 rotZ;
    /* 0x18 */ f32 scaleX;
    /* 0x1C */ f32 scaleY;
    /* 0x20 */ f32 scaleZ;
    /* 0x24 */ s32 player;
    /* 0x28 */ s32 timer;
    /* 0x2C */ f32 velY;
    /* 0x30 */ s32 state;
    /* 0x34 */ f32 angle;
    /* 0x38 */ f32 dist;
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ u16 alpha;
    /* 0x44 */ s32 unk44;
} CCPiece; /* size = 0x48 */

/* S4-23B: the shadow under a falling piece (D_80109980[4]; MP1 D_800FD4E8). */
typedef struct CCShadow {
    /* 0x00 */ s32 model; /* read as s16 */
    /* 0x04 */ f32 scale;
    /* 0x08 */ f32 unk8;
} CCShadow; /* size = 0xC */

/* An expanding/shrinking cut ring (omObjData::unk_50 of the func_801079E0 objects; MP1
   CrazyCutterRing). The N64 allocation is 0x1C bytes; size it by sizeof on the host. */
typedef struct CCRing {
    /* 0x00 */ s32 player;
    /* 0x04 */ f32 radius;
    /* 0x08 */ f32 step;
    /* 0x0C */ f32 end;
    /* 0x10 */ s32 width;
    /* 0x14 */ u8* mask;
    /* 0x18 */ s32 frame;
} CCRing;

/* ---------------------------------------------------------------------------------------------
   .data (asm, 0x80109070-0x801093F0)
   --------------------------------------------------------------------------------------------- */

extern s32 D_80109070_1E84C0_CrazyCutters[4]; /* per screen quarter: shape sprite x (read as s16) */
extern s32 D_80109080_1E84D0_CrazyCutters[4]; /* ... and y */
extern f32 D_80109090_1E84E0_CrazyCutters[4]; /* per screen quarter: world x offset */
extern f32 D_801090A0_1E84F0_CrazyCutters[4]; /* ... and z */
extern s8 D_801090B0_1E8500_CrazyCutters[12]; /* 3x3 cut mask */
extern s8 D_801090BC_1E850C_CrazyCutters[4];  /* 1x1 cut mask */
/* per character: model directory, model file; then per player: motion files */
extern s32 D_801090C0_1E8510_CrazyCutters[6];
extern s32 D_801090D8_1E8528_CrazyCutters[6];
extern s32 D_801090F0_1E8540_CrazyCutters[6];
extern s32 D_80109108_1E8558_CrazyCutters[6];
extern s32 D_80109120_1E8570_CrazyCutters[6];
extern s32 D_80109138_1E8588_CrazyCutters[6];
extern s32 D_80109150_1E85A0_CrazyCutters[6];
extern s32 D_80109168_1E85B8_CrazyCutters[6];
extern s32 D_80109180_1E85D0_CrazyCutters[6];
/* CPU routes per shape: (x, y) pairs; (-3, -3) start, (-2, -2) end, -1 terminator */
extern s32 D_80109198_1E85E8_CrazyCutters[47];
extern s32 D_80109254_1E86A4_CrazyCutters[49];
extern s32 D_80109318_1E8768_CrazyCutters[51];
extern s32 D_801093E4_1E8834_CrazyCutters[3];

/* ---------------------------------------------------------------------------------------------
   .bss (asm, 0x80109560-0x80109AA0). MP1 names in brackets where the use matches.
   --------------------------------------------------------------------------------------------- */

extern s32 D_80109560_1E89B0_CrazyCutters; /* [D_800FD134] */
extern s32 D_80109564_1E89B4_CrazyCutters;
extern f32 D_80109568_1E89B8_CrazyCutters; /* [D_800FD138] */
extern s32 D_8010956C_1E89BC_CrazyCutters; /* [D_800FD13C] */
extern f32 D_80109570_1E89C0_CrazyCutters; /* [D_800FD140] */
extern f32 D_80109574_1E89C4_CrazyCutters; /* [D_800FD144] */
extern s32 D_80109578_1E89C8_CrazyCutters; /* [D_800FD148] */
extern s16 D_8010957C_1E89CC_CrazyCutters; /* [D_800FD14C] */
extern u16 D_8010957E_1E89CE_CrazyCutters; /* seconds left [D_800FD14E] */
extern u16 D_80109580_1E89D0_CrazyCutters; /* frames to the next second [D_800FD150] */
extern s32 D_80109584_1E89D4_CrazyCutters; /* index of the route's turn point */
extern s32 D_80109588_1E89D8_CrazyCutters[4];
extern s16 D_80109598_1E89E8_CrazyCutters[4]; /* shape sprite files [D_800FD156] */
extern u16 D_801095B0_1E8A00_CrazyCutters[4]; /* shape sprites [D_800FD160] */
extern u16 D_801095C8_1E8A18_CrazyCutters[80]; /* background tiles [D_800FD170] */
extern u16 D_80109668_1E8AB8_CrazyCutters;
extern s32 D_80109670_1E8AC0_CrazyCutters[80]; /* tile x [D_800FD1C0] */
extern s32 D_801097B0_1E8C00_CrazyCutters[80]; /* tile y [D_800FD300] */
extern s32 D_801098F0_1E8D40_CrazyCutters; /* divider sprite x (read as s16) */
extern s32 D_801098F4_1E8D44_CrazyCutters; /* ... y */
extern s32 D_801098F8_1E8D48_CrazyCutters; /* flow timer [D_800FD460] */
extern s32 D_801098FC_1E8D4C_CrazyCutters; /* players may start [D_800FD464] */
extern s32 D_80109900_1E8D50_CrazyCutters; /* [D_800FD468] */
extern s32 D_80109908_1E8D58_CrazyCutters[4]; /* outline pixels per quarter [D_800FD470] */
extern s32 D_80109918_1E8D68_CrazyCutters; /* the shape, 0-2 [D_800FD480] */
extern s32 D_80109920_1E8D70_CrazyCutters[4]; /* [D_800FD488] */
extern s32 D_80109930_1E8D80_CrazyCutters; /* outline image width [D_800FD498] */
extern s32 D_80109934_1E8D84_CrazyCutters; /* ... height [D_800FD49C] */
extern u8* D_80109938_1E8D88_CrazyCutters[4]; /* outline images per quarter [D_800FD4A0] */
extern s32 D_80109948_1E8D98_CrazyCutters; /* input enabled [D_800FD4B0] */
extern s32 D_80109950_1E8DA0_CrazyCutters[4]; /* cut hits [D_800FD4B8] */
extern s32 D_80109960_1E8DB0_CrazyCutters[4]; /* cut misses [D_800FD4C8] */
extern s32 D_80109970_1E8DC0_CrazyCutters[4]; /* per player flags, func_80106D28/D44 [D_800FD4D8] */
/* S4-23B: per player, the falling piece's shadow model ([D_800FD4E8]); retail stores the model
   as a word and reads it as s16 at +2 (label D_80109982). */
extern CCShadow D_80109980_1E8DD0_CrazyCutters[4];
extern s32 D_801099B0_1E8E00_CrazyCutters;
extern s32 D_801099B4_1E8E04_CrazyCutters;
extern s32 D_801099B8_1E8E08_CrazyCutters;
extern s32 D_801099BC_1E8E0C_CrazyCutters;
extern s32 D_801099C0_1E8E10_CrazyCutters;
extern s32 D_801099C4_1E8E14_CrazyCutters;
extern s32 D_801099C8_1E8E18_CrazyCutters; /* [D_800FD530] */
extern s32 D_801099CC_1E8E1C_CrazyCutters; /* [D_800FD534] */
extern s32 D_801099D0_1E8E20_CrazyCutters; /* [D_800FD538] */
extern s32 D_801099D8_1E8E28_CrazyCutters[4];
extern f32 D_801099E8_1E8E38_CrazyCutters; /* cutter speed [D_800FD53C] */
extern s16 D_801099EC_1E8E3C_CrazyCutters;
extern s16 D_801099EE_1E8E3E_CrazyCutters;
extern s16 D_801099F0_1E8E40_CrazyCutters; /* result kind [D_800FD544] */
extern s32 D_801099F4_1E8E44_CrazyCutters; /* shake state [D_800FD548]; read as s16 at +2 */
extern s32 D_801099F8_1E8E48_CrazyCutters; /* shake timer [D_800FD54C] */
extern s32 D_801099FC_1E8E4C_CrazyCutters; /* route index of the start point [D_800FD550] */
extern s32 D_80109A00_1E8E50_CrazyCutters; /* _CheckFlag(0xC) [D_800FD554] */
extern s32 D_80109A08_1E8E58_CrazyCutters[4]; /* screen quarter -> player (by team) */
extern f32 D_80109A18_1E8E68_CrazyCutters[4]; /* [D_800FD558] */
extern f32 D_80109A28_1E8E78_CrazyCutters[4]; /* [D_800FD568] */
extern f32 D_80109A38_1E8E88_CrazyCutters[4]; /* [D_800FD578] */
extern s16 D_80109A48_1E8E98_CrazyCutters[4]; /* [D_800FD588] */
extern u16 D_80109A50_1E8EA0_CrazyCutters; /* [D_800FD590] */
extern s16 D_80109A52_1E8EA2_CrazyCutters[4]; /* scores [D_800FD592] */
extern s16 D_80109A5A_1E8EAA_CrazyCutters; /* route index the CPU must pass [D_800FD59A] */
extern s32 D_80109A60_1E8EB0_CrazyCutters[4]; /* the motion chosen for slot 2 */
extern omObjData* D_80109A70_1E8EC0_CrazyCutters[4]; /* player objects [D_800FD5A0] */
extern s16 D_80109A80_1E8ED0_CrazyCutters; /* [D_800FD5B0] */
extern s16 D_80109A82_1E8ED2_CrazyCutters[4];
extern s16 D_80109A8A_1E8EDA_CrazyCutters;
extern s16 D_80109A8C_1E8EDC_CrazyCutters;
extern s16 D_80109A90_1E8EE0_CrazyCutters; /* sound [D_800FD5C2] */
extern s16 D_80109A92_1E8EE2_CrazyCutters; /* cutting sound [D_800FD5C6] */
extern s16 D_80109A94_1E8EE4_CrazyCutters; /* [D_800FD5C8] */
extern s16 D_80109A96_1E8EE6_CrazyCutters;
extern s16 D_80109A98_1E8EE8_CrazyCutters;
extern s16 D_80109A9A_1E8EEA_CrazyCutters; /* music handle */

/* ---------------------------------------------------------------------------------------------
   Functions (MP1 equivalent in brackets). Past 80105A00 (S4-23B) inferred from MP1 and the asm.
   --------------------------------------------------------------------------------------------- */

/* 1E1C50.c */
void func_80102800_1E1C50_CrazyCutters(void); /* [F65E0] setup */
void func_80102A44_1E1E94_CrazyCutters(omObjData*); /* [F686C] */
void func_80102AA8_1E1EF8_CrazyCutters(omObjData*); /* [F68C4] */
void func_80102B64_1E1FB4_CrazyCutters(f32 zoom, f32 rx, f32 ry, f32 rz, f32 cx, f32 cy, f32 cz); /* [F6938] */
void func_80102C18_1E2068_CrazyCutters(omObjData*); /* [F69EC] */
void func_80102D30_1E2180_CrazyCutters(omObjData*); /* [F6B04] */
void func_801030B4_1E2504_CrazyCutters(omObjData*); /* [F6F00] */
void func_8010332C_1E277C_CrazyCutters(omObjData*); /* [F7180] */
void func_80103508_1E2958_CrazyCutters(omObjData* obj, s32 player); /* [F731C] */
void func_801040F0_1E3540_CrazyCutters(omObjData*); /* [F8144] */
void func_8010454C_1E399C_CrazyCutters(omObjData*); /* [F8598] */
s32 func_80104FF4_1E4444_CrazyCutters(CCPlayer* st, s16* cur, s32 wide); /* [F8F74] */
s32 func_80105098_1E44E8_CrazyCutters(CCPlayer* st, s16* cur);
void func_801050FC_1E454C_CrazyCutters(CCPlayer* st, s16* cur); /* [F8FDC] */
void func_80105254_1E46A4_CrazyCutters(omObjData*); /* [F90E4] */
void func_80105648_1E4A98_CrazyCutters(omObjData*); /* [F94C0] */
void func_80105664_1E4AB4_CrazyCutters(omObjData*); /* [F94DC] */
void func_80105680_1E4AD0_CrazyCutters(omObjData*); /* [F94F8] */
void func_8010569C_1E4AEC_CrazyCutters(omObjData*); /* [F9514] */
f32 func_801056B8_1E4B08_CrazyCutters(CCPlayer* st); /* [F9530] */
void func_801057D8_1E4C28_CrazyCutters(omObjData*); /* [F9654] */
void func_80105830_1E4C80_CrazyCutters(omObjData*);
void func_8010585C_1E4CAC_CrazyCutters(Vec* pos, s16* out, s32 quarter); /* [F9694] */
void func_8010593C_1E4D8C_CrazyCutters(void); /* [F978C] */
void func_80105978_1E4DC8_CrazyCutters(omObjData*); /* [F97C8] */
void func_80105A74_1E4EC4_CrazyCutters(CCPlayer* st); /* [F98B4] */
void func_80105B40_1E4F90_CrazyCutters(omObjData* parent, s32 player); /* [F9968] */
void func_80105FE4_1E5434_CrazyCutters(omObjData*); /* [F9D98] */
s32 func_801065F4_1E5A44_CrazyCutters(s32 quarter); /* [FA38C] */
void func_801067D4_1E5C24_CrazyCutters(omObjData*); /* [FA56C] */
void func_80106A5C_1E5EAC_CrazyCutters(omObjData*); /* [FA808] */
void func_80106AD4_1E5F24_CrazyCutters(omObjData*); /* [FA880] */
void func_80106B54_1E5FA4_CrazyCutters(omObjData*); /* [FA9D8] */
void func_80106B94_1E5FE4_CrazyCutters(omObjData*); /* [FAA18] */
s32 func_80106D28_1E6178_CrazyCutters(s32 player, s32 flag); /* [FAAB0] */
void func_80106D44_1E6194_CrazyCutters(s32 player, s32 flag, s32 on); /* [FAACC] */
f32 func_80106D84_1E61D4_CrazyCutters(f32 x); /* [FAB0C] */
f32 func_80106EB0_1E6300_CrazyCutters(s16* from, s16* to, s32 mode); /* [FAC38] */
f32 func_80107204_1E6654_CrazyCutters(Vec* from, Vec* to, s32 mode); /* [FAF8C] */
void func_80107530_1E6980_CrazyCutters(s32 sprite, s32 player); /* [FB2B8] */
void func_801076B8_1E6B08_CrazyCutters(s32); /* [FB450] */
void func_801077B0_1E6C00_CrazyCutters(s32); /* [FB548] */
void func_801078A8_1E6CF8_CrazyCutters(omObjData* parent, s32 sprite, s32 sprite2, s32 player); /* [FB640] */
void func_801079E0_1E6E30_CrazyCutters(omObjData*); /* [FB778] */
s32 func_80107BBC_1E700C_CrazyCutters(CCPlayer* st); /* [FB944] */
s16 func_80107D74_1E71C4_CrazyCutters(s32 idx); /* [FBAFC] */
void func_80107DA4_1E71F4_CrazyCutters(void); /* [FBB2C] */
void func_80107DFC_1E724C_CrazyCutters(omObjData*); /* [FBB94] */
s32 func_80108108_1E7558_CrazyCutters(s16 grpIdx, s32 idx, s32 x, s32 y); /* [FBEA8] */
void func_80108214_1E7664_CrazyCutters(void); /* [FBFB4] */
s16 func_80108284_1E76D4_CrazyCutters(s16 x, s16 y); /* [FC024] */
void func_801084A0_1E78F0_CrazyCutters(s16); /* [FC240] */
void func_801084FC_1E794C_CrazyCutters(s16 grp, s16 value); /* [FC29C] */
void func_801086BC_1E7B0C_CrazyCutters(s16, s16); /* [FC45C] */
void func_8010874C_1E7B9C_CrazyCutters(void); /* sorts the players into screen quarters */
s32 func_8010882C_1E7C7C_CrazyCutters(s32 player); /* the player's screen quarter */

/* 1E7CC0.c (MP1 12AFE0.c) */
u8* func_80108870_1E7CC0_CrazyCutters(s16 grpIdx, s16 idx, s32* width, s32* height); /* [FC4F0] */
s32 func_80108A8C_1E7EDC_CrazyCutters(s16 grpIdx, s16 idx, s32 x0, s32 y0, s32 w, s32 h, s8* mask); /* [FC70C] */
s32 func_80108C40_1E8090_CrazyCutters(s16 grpIdx, s16 idx, s32 x, s32 y); /* [FC8C0] */
s32 func_80108D18_1E8168_CrazyCutters(u32 arg0, s32 arg1, u32 arg2, u8* arg3, s32 arg4); /* [FC998] */
s32 func_80108D74_1E81C4_CrazyCutters(s32 arg0, s32 arg1, s32 arg2, u8* arg3, u8 arg4); /* [FC9F4] */
s32 func_80108DA0_1E81F0_CrazyCutters(u8* pal, u16 fmt); /* [FCA20] */
s32 func_80108E2C_1E827C_CrazyCutters(s16 grpIdx, s16 idx, s32 x0, s32 y0, s32 w, s32 h, s8* mask); /* [FCAAC] */
s32 func_80108FE4_1E8434_CrazyCutters(u32 arg0, s32 arg1, u32 arg2, u8* arg3, s32 arg4); /* [FCC64] */
s32 func_80109048_1E8498_CrazyCutters(s32 arg0, s32 arg1, s32 arg2, u8* arg3, u8 arg4); /* [FCCC8] */
/* The nop between func_80108FE4 and func_80109048: func_80108E2C's 8-bit pixel test. */
extern s32 D_80109044_1E8494_CrazyCutters(s32, s32, s32, u8*, u8);

#endif
