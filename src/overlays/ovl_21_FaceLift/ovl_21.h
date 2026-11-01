#ifndef _OVL_21_H
#define _OVL_21_H

/* Overlay 21: Face Lift (MP1 ovl_0E_FaceLift/12BC20.c). Each of the four players grabs points of
   one of six faces (D_800FA656, D_801097F0_1D6B50_FaceLift) and drags them to copy the face the host shows, for
   30 s; the closest copy wins. Differences from MP1: the face, its parts and the target layouts
   come from a table instead of one set of arrays, the face mesh deforms through a list of touched
   vertices built at start-up from a second "touch" model (func_80106248_1D35A8_FaceLift), and the eyes follow a
   small star (func_80107348_1D46A8_FaceLift). One retail file, 1CFB60.c (80102800-80108E60). .rodata is carved
   from 0x1D6EC0; .data is asm, typed here from the code.
   N64 offsets are in the comments; structs with pointer fields change size on the host. */

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/data.h"

/* One grab point of a face (MP1 FaceLiftPart + a sound). 0x2C on the N64. */
typedef struct FLPart {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ s16 model; /* index into FLFace's mesh models */
    /* 0x0A */ s16 unk0A;
    /* 0x0C */ f32 left;
    /* 0x10 */ f32 top;
    /* 0x14 */ f32 right;
    /* 0x18 */ f32 bottom;
    /* 0x1C */ s16 count; /* vertices within radius (func_80106248_1D35A8_FaceLift) */
    /* 0x1E */ s16 unk1E;
    /* 0x20 */ s16* verts; /* their indices, heap-allocated at start-up */
    /* 0x24 */ f32 radius;
    /* 0x28 */ s32 sound; /* the drag sound */
} FLPart;

/* One face. 0x34 on the N64. */
typedef struct FLFace {
    /* 0x00 */ u8 numModels;
    /* 0x01 */ u8 numParts;
    /* 0x04 */ s32 file[4]; /* mesh models */
    /* 0x14 */ s32 touchFile[4]; /* the same meshes, with the grab colour */
    /* 0x24 */ s32 eyeFile[2];
    /* 0x2C */ FLPart* parts;
    /* 0x30 */ Vec2f* targets; /* three layouts of numParts (6 slots each) */
} FLFace;

/* Per-player work (func_80027154_27D54(0xE0), omObjData.unk_50); MP1 FaceLiftWork. */
typedef struct FLWork {
    /* 0x00 */ u16 sprite;
    /* 0x02 */ s16 grab;
    /* 0x04 */ u16 sel;
    /* 0x06 */ s16 sndOn;
    /* 0x08 */ s16 moving[6];
    /* 0x14 */ u16 frame;
    /* 0x16 */ s16 snd;
    /* 0x18 */ Vec pos;
    /* 0x24 */ Vec pts[6];
    /* 0x6C */ char unk_6C[0x18];
    /* 0x84 */ s16 order[6];
    /* 0x90 */ s16 cpuState;
    /* 0x92 */ s16 cpuIdx;
    /* 0x94 */ s16 cpuTimer;
    /* 0x96 */ s16 cpuRounds;
    /* 0x98 */ Vec cpuTarget[6];
} FLWork; /* size = 0xE0 */

/* The star that circles a winner (func_80027154_27D54(0x1C), omObjData.unk_50); MP1 FaceLiftStar. */
typedef struct FLStar {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
    /* 0x0C */ f32 angle;
    /* 0x10 */ f32 h;
    /* 0x14 */ s16 model;
    /* 0x16 */ u16 count;
    /* 0x18 */ s16 unk18;
    /* 0x1A */ s16 fade;
} FLStar; /* size = 0x1C */

/* Sparkle particles (0x294); MP1 FaceLiftFx, FaceLiftFxWork. */
typedef struct FLFx {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 player;
    /* 0x04 */ u16 alpha;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ f32 x;
    /* 0x0C */ f32 y;
    /* 0x10 */ f32 z;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 vy;
    /* 0x1C */ s16 model;
    /* 0x1E */ s16 unk_1E;
} FLFx; /* size = 0x20 */

typedef struct FLFxWork {
    /* 0x000 */ FLFx fx[20];
    /* 0x280 */ u8 state[20];
} FLFxWork; /* size = 0x294 */

typedef struct FLPos {
    s16 x;
    s16 y;
} FLPos;

typedef struct FLColor {
    u8 r;
    u8 g;
    u8 b;
} FLColor;

/* ---- main-segment API missing from include/ ---- */
typedef struct FLEspSlot {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ char unk_06[0x1E];
} FLEspSlot; /* size = 0x24 */
extern u8 D_800FA656;
extern u16 D_801011FC_101DFC;
extern u16 ContBtnTrg[4];
extern s8 ContStkX[4];
extern s8 ContStkY[4];
extern u8 D_800FDBE0_FE7E0; /* current vertex buffer */
extern FLEspSlot* D_800F93FC_F9FFC;
extern Gfx* D_800FDBCC_FE7CC;

void func_80020070_20C70(s16 count);
void func_8002D4D0_2E0D0(s16 n);
void func_80020D20_21920(s16 arg0);
void func_80079128_79D28(void);
void func_80026D28_27928(s16);
void func_80026E00_27A00(s16, f32, f32, f32);
void func_80026DAC_279AC(s16, u8, u8, u8);
void func_8007273C_7333C(const u8* arg0, u8 arg1);
void CameraViewportSet(s16 camIndex, Vec* arg1, Vec* arg2);
void CameraScissorSet(s16 camIndex, RectF* arg1);
void Hu3DCam3DToScreen(s16 camIndex, Vec* worldPos, Vec2f* outPos);
void Hu3DCamSetPerspective(s16, f32, f32, f32);
void Hu3DCamSetPositionOrientation(s16 camIndex, Vec* pos, Vec* at, Vec* up);
void Hu3DCamUpdateMtx(s16 camIndex);
void* func_80027154_27D54(s32 size, s32 tag);
void HuMemFree(void* arg0);
void espDispOff(u16);
void espDispOn(u16);
void espPosSet(u16 spriteId, s16 x, s16 y);
s16 func_8001A2F8_1AEF8(s32);
s16 func_8001AAAC_1B6AC(s16 arg0, u16 arg1, u16 arg2);
void func_8001A6BC_1B2BC(u16 spriteId, s16 arg1);
void func_8001A854_1B454(u16 spriteId, s32 arg1, s32 arg2);
void func_8001A91C_1B51C(u16 spriteId, f32 x, f32 y);
u16 LoadFormFile(s32, s32);
void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_800298A4_2A4A4(s16, s32, s32); /* model attribute */
void func_80029A8C_2A68C(s16 arg0);
void func_80029AFC_2A6FC(s16 arg0);
void func_80029EDC_2AADC(s16 arg0, s32 arg1); /* main: u8 */
void func_8002A00C_2AC0C(s16 arg0);
void func_8002D0A0_2DCA0(s16 arg0, u8 arg1);
void func_8002D124_2DD24(s16 index);
void func_8002D1EC_2DDEC(s16 arg0, u8 arg1);
void func_8002D274_2DE74(s16 arg0, u8 arg1, u8 arg2, u8 arg3); /* main: s8 */
void func_8002D2B4_2DEB4(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
s16 func_8002838C_28F8C(s32 arg0, void (*arg1)(Gfx**, s32, s32), u8 arg2);
void func_800283DC_28FDC(s16 arg0);
u16 func_80020EBC_21ABC(void* arg0, s32 arg1, u8 arg2);
void func_80021160_21D60(s16 index, s32 arg1, s32 arg2);
void func_800211E8_21DE8(s16 index, u8 arg1);
void func_80021250_21E50(s16 index, u8 arg1, u8 arg2, u8 arg3);
s16 func_8003DF08_3EB08(void* arg);
void func_80025770_26370(f32 (*mtx)[4], f32 x, f32 y, f32 z);
void omDelObj(omObjData*);
void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3);
s32 omOvlReturnEx(s16);
HuSprite* func_80082550_83150(s16 grpIdx, s16 idx);
s16 SprAnimRead(void* arg0);
s16 SprCreate(s32 num, s32 attr);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprAttrSet(s16 grpIdx, s16 idx, s32 flag);
void SprAttrReset(s16, s16, s32);
void SprPosSet(s16 grpIdx, s16 idx, s16 x, s16 y);
void SprScaleSet(s16 grpIdx, s16 idx, f32 sx, f32 sy);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
void func_800822A8_82EA8(s16 group, s16 member, u16 arg2, s32 arg3);
void func_800824F4_830F4(s16 grpIdx, s16 idx, s16 arg2);
s16 func_800691FC_69DFC(s16 mesNo, ...); /* MP1 GMesCreate */
s32 func_80069538_6A138(void); /* MP1 GMesStatAllGet */
s32 func_800696E4_6A2E4(void); /* MP1 GMesWait */
void func_8006D4D0_6E0D0(s16); /* the seconds counter */
void func_8006D518_6E118(void);
s16 PlayMusic(s16);
s32 PlaySound(s32);
void func_800794A8_7A0A8(s32);
void func_800796F0_7A2F0(s16 sound, s16 pitch);
s16 func_80079798_7A398(s16 arg0, s16 arg1);
void func_80079848_7A448(s16 arg0);
void InitFadeIn(s32, s32);
void InitFadeOut(s32, s32);
s32 func_8008F618_90218(void);
s32 _CheckFlag(s32);
u8 rand8(void);
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* cos */
f32 func_800B75A8_B81A8(f32 y, f32 x); /* atan2 */
f32 func_800B1830_B2430(f32 x); /* sqrtf */
void func_800B1960_B2560(f32 (*matrix)[4], f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp, f32 yUp, f32 zUp);
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size);

/* ---- .data ---- */
extern FLPart D_80108E60_1D61C0_FaceLift[6];
extern Vec2f D_80108F68_1D62C8_FaceLift[3 * 6];
extern FLPart D_80108FF8_1D6358_FaceLift[6];
extern Vec2f D_80109100_1D6460_FaceLift[3 * 6];
extern FLPart D_80109190_1D64F0_FaceLift[6];
extern Vec2f D_80109298_1D65F8_FaceLift[3 * 6];
extern FLPart D_80109328_1D6688_FaceLift[6];
extern Vec2f D_80109430_1D6790_FaceLift[3 * 6];
extern FLPart D_801094C0_1D6820_FaceLift[6];
extern Vec2f D_801095C8_1D6928_FaceLift[3 * 6];
extern FLPart D_80109658_1D69B8_FaceLift[6];
extern Vec2f D_80109760_1D6AC0_FaceLift[3 * 6];
extern FLFace D_801097F0_1D6B50_FaceLift[6];
extern u16 D_80109930_1D6C90_FaceLift; /* done: fade out */
extern Vec D_80109934_1D6C94_FaceLift[5]; /* viewports: scale */
extern Vec D_80109970_1D6CD0_FaceLift[5]; /* viewports: position */
extern RectF D_801099AC_1D6D0C_FaceLift[5]; /* scissors */
extern FLPos D_801099FC_1D6D5C_FaceLift[4]; /* each view's screen corner */
extern s32 D_80109A0C_1D6D6C_FaceLift[6]; /* cursor sprite per character */
extern const char* D_80109A24_1D6D84_FaceLift[6]; /* character name (Shift-JIS) */
extern f32 D_80109A3C_1D6D9C_FaceLift[4]; /* CPU spread by difficulty */
extern s16 D_80109A4C_1D6DAC_FaceLift[]; /* score positions, x y pairs */
extern s16 D_80109A4E_1D6DAE_FaceLift[]; /* label of D_80109A4C_1D6DAC_FaceLift[1] */
extern s16 D_80109A5C_1D6DBC_FaceLift[6]; /* cursor home: index into the parts, per face */
extern Gfx D_80109A68_1D6DC8_FaceLift[];
extern Gfx D_80109AB0_1D6E10_FaceLift[];
extern FLColor D_80109AF0_1D6E50_FaceLift[10]; /* the rainbow star's colours */
extern u8 D_80109B54_1D6EB4_FaceLift[]; /* "ABC" (Shift-JIS) */

/* ---- .bss ---- */
extern s16 D_80109B80_1D6EE0_FaceLift; /* the host's sprite */
extern s16 D_80109B82_1D6EE2_FaceLift; /* phase */
extern s16 D_80109B84_1D6EE4_FaceLift; /* phase timer */
extern s8 D_80109B86_1D6EE6_FaceLift; /* the face */
extern s8 D_80109B87_1D6EE7_FaceLift; /* the layout */
extern Vec D_80109B88_1D6EE8_FaceLift[6]; /* the host's parts */
extern s16 D_80109BD0_1D6F30_FaceLift; /* winner count */
extern s16 D_80109BD2_1D6F32_FaceLift[4]; /* winners */
extern omObjData* D_80109BE0_1D6F40_FaceLift[4];
extern omObjData* D_80109BF0_1D6F50_FaceLift; /* sparkles */
extern omObjData* D_80109BF4_1D6F54_FaceLift;
extern s16 D_80109BF8_1D6F58_FaceLift; /* the end timer */
extern s16 D_80109BFA_1D6F5A_FaceLift[4]; /* score sprites */
extern s16 D_80109C02_1D6F62_FaceLift[4]; /* rank */
extern s16 D_80109C0A_1D6F6A_FaceLift; /* _CheckFlag(0xC): no results */
extern s16 D_80109C0C_1D6F6C_FaceLift[4]; /* CPU difficulty */
extern FLPart* D_80109C14_1D6F74_FaceLift;
extern FLFace* D_80109C18_1D6F78_FaceLift;
extern Vec2f* D_80109C1C_1D6F7C_FaceLift;
extern s16 D_80109C20_1D6F80_FaceLift[5][6]; /* each view's mesh models, then its eyes */
extern omObjData* D_80109C60_1D6FC0_FaceLift[4]; /* a player's star */
extern omObjData* D_80109C70_1D6FD0_FaceLift; /* the host's star */
extern s16 D_80109C74_1D6FD4_FaceLift;
extern s16 D_80109C76_1D6FD6_FaceLift[4];
extern s16 D_80109C7E_1D6FDE_FaceLift;
extern s16 D_80109C80_1D6FE0_FaceLift;
extern Vec D_80109C90_1D6FF0_FaceLift[5]; /* star positions: players, then the host */
extern s16 D_80109CCC_1D702C_FaceLift[4]; /* touched vertices per mesh */
extern u8* D_80109CD8_1D7038_FaceLift[4]; /* per vertex: bit mask of the parts that move it */
extern Vec D_80109CF0_1D7050_FaceLift[6]; /* each part's point on the mesh */
extern ColVtx* D_80109D38_1D7098_FaceLift[4];
extern s16 D_80109D48_1D70A8_FaceLift[4]; /* scores */

void func_80102800_1CFB60_FaceLift(void);
void func_80102B90_1CFEF0_FaceLift(omObjData* obj);
void func_80102E18_1D0178_FaceLift(FLWork* w, f32 spread);
void func_80103048_1D03A8_FaceLift(omObjData* obj);
void func_801033B8_1D0718_FaceLift(s16 player, FLWork* w);
void func_80103E98_1D11F8_FaceLift(s16 player, FLWork* w, Vec2f* stick, u16* trg, u16* btn);
void func_801041F0_1D1550_FaceLift(omObjData* obj, f32 x, f32 y, s16 look);
void func_801043D0_1D1730_FaceLift(omObjData* obj, s16 player);
void func_80104598_1D18F8_FaceLift(omObjData* obj);
void func_80104690_1D19F0_FaceLift(omObjData* obj);
void func_801047A8_1D1B08_FaceLift(omObjData* obj);
void func_801048E4_1D1C44_FaceLift(omObjData* obj);
void func_801049B8_1D1D18_FaceLift(omObjData* obj);
void func_80104A28_1D1D88_FaceLift(omObjData* obj);
void func_80104A98_1D1DF8_FaceLift(omObjData* obj);
void func_80104AE4_1D1E44_FaceLift(omObjData* obj);
void func_80104D24_1D2084_FaceLift(omObjData* obj);
void func_80104D54_1D20B4_FaceLift(omObjData* obj);
void func_80104DA0_1D2100_FaceLift(omObjData* obj);
void func_8010508C_1D23EC_FaceLift(omObjData* obj);
void func_8010522C_1D258C_FaceLift(omObjData* obj);
void func_801052A8_1D2608_FaceLift(omObjData* obj);
void func_80105884_1D2BE4_FaceLift(omObjData* obj);
void func_801058C4_1D2C24_FaceLift(Gfx** gfx);
void func_80105924_1D2C84_FaceLift(omObjData* obj);
void func_80105988_1D2CE8_FaceLift(omObjData* obj);
void func_801059EC_1D2D4C_FaceLift(void);
void func_80105DB0_1D3110_FaceLift(omObjData* obj);
s32 func_80105F24_1D3284_FaceLift(s16 player, Vec* pos);
void func_80106248_1D35A8_FaceLift(omObjData* obj);
s16 func_801069D0_1D3D30_FaceLift(s16 model, ColVtx* list);
s16 func_80106C1C_1D3F7C_FaceLift(Vec* a, Vec* b, Vec* c, f32 x, f32 y);
void func_80106E24_1D4184_FaceLift(omObjData* obj, Vec* p0, Vec* p1, Vec* p2, Vec* p3, Vec* p4, Vec* p5);
void func_801072C0_1D4620_FaceLift(omObjData* obj);
void func_8010731C_1D467C_FaceLift(omObjData* obj);
omObjData* func_80107348_1D46A8_FaceLift(s16 player, u8 rainbow);
void func_8010744C_1D47AC_FaceLift(omObjData* obj);
void func_80107454_1D47B4_FaceLift(omObjData* obj);
void func_801074F8_1D4858_FaceLift(omObjData* obj);
void func_80107EBC_1D521C_FaceLift(omObjData* obj);
void func_80107FDC_1D533C_FaceLift(omObjData* obj);
void func_8010811C_1D547C_FaceLift(s16 player, f32 x, f32 y, f32 z, u16 type);
s16 func_801082A4_1D5604_FaceLift(void);
void func_80108890_1D5BF0_FaceLift(void);
s16 func_80108900_1D5C60_FaceLift(s16 x, s16 y);
void func_80108B1C_1D5E7C_FaceLift(s16 id);
void func_80108B78_1D5ED8_FaceLift(s16 id);
void func_80108BD4_1D5F34_FaceLift(s16 id, s32 val);
void func_80108D94_1D60F4_FaceLift(s16 id, s16 val);
void func_80108E24_1D6184_FaceLift(s16 id, s16 x, s16 y);

#endif /* _OVL_21_H */
