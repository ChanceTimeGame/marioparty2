#ifndef _OVL_61_H
#define _OVL_61_H

/* Overlay 61 ("donchou", the curtain): MP2's opening stage scene. Six characters (objects 0-5)
   stand on a stage; the presenter (object 6, scaled 0.7) talks in a message window (0xAB-0xB8)
   while an iris mask (a 320x240 8-bit coverage buffer per frame buffer, drawn as a full-screen
   textured fill: func_801062B8..func_80107054) dims the screen and cuts holes over the speakers.
   Three pairs walk forward, face the camera and call out (func_80102F74); the curtain closes and
   object 7 rises from below, turns and breathes sparks (func_80105C6C/func_80105DEC); then the
   presenter's finale and a fade out. Played to the end, it goes to overlay 0x72; once
   _CheckFlag(0x1A) is set, START (any inserted pad) sets D_801011FC and the scene ends with a
   music fade and omOvlReturnEx(1).
   One retail file (3D0050.c). .data stays asm; .rodata is carved (two tables, two strings). */

#include "common.h"
#include "process.h"
#include "game/object.h"
#include "game/window.h"
#include "game/sprite.h"
#include "game/pad.h"

/* A motion list (s32[]): count, then that many motion file ids (DataRead). */

/* omObjData.unk_50 of the eight character objects (D_801074D8). */
typedef struct Ovl61ChrWork {
    /* 0x00 */ Vec dir;   /* facing direction; rot.y follows it */
    /* 0x0C */ s16 mode;  /* index into the object's D_80107174 list */
    /* 0x0E */ s16 snd;   /* handle from func_80025384 / func_80025684 */
} Ovl61ChrWork; /* size = 0x10 */

/* omObjData.unk_50 of the curtain object (D_801074D0). */
typedef struct Ovl61CurtainWork {
    /* 0x00 */ s16 anim;  /* sprite animation (func_8001A2F8) or -1 */
    /* 0x02 */ s16 esp;   /* its esprite or -1 */
    /* 0x04 */ f32 y;     /* curtain height */
} Ovl61CurtainWork;

/* omObjData.unk_50 of the spark object (D_80107508): 16 sparks. */
typedef struct Ovl61SparkWork {
    /* 0x000 */ Vec pos[16];
    /* 0x0C0 */ Vec vel[16];
    /* 0x180 */ s16 active[16];
    /* 0x1A0 */ s16 slot[16];  /* sprite-model slot (func_80020EBC) */
    /* 0x1C0 */ s16 model[16];
    /* 0x1E0 */ s16 tex;
    /* 0x1E2 */ s16 delay;
    /* 0x1E4 */ f32 life[16];
    /* 0x224 */ f32 scale[16];
} Ovl61SparkWork; /* size = 0x264 */

/* The iris mask (D_80107544): up to four holes, each kept for the three frame buffers. */
typedef struct Ovl61Iris {
    /* 0x00 */ s16 count;
    /* 0x02 */ s16 flags[4]; /* 1 used, 2 closing, 4 frozen */
    /* 0x0A */ s16 x[4];
    /* 0x12 */ s16 y[4];
    /* 0x1A */ s16 fbX[3][4];
    /* 0x32 */ s16 fbY[3][4];
    /* 0x4A */ char pad4A[2];
    /* 0x4C */ f32 sx[4];
    /* 0x5C */ f32 sy[4];
    /* 0x6C */ f32 fbSx[3][4];
    /* 0x9C */ f32 fbSy[3][4];
    /* 0xCC */ u16 fadeTime;
    /* 0xD0 */ f32 col[4];
    /* 0xE0 */ f32 colStep[4];
} Ovl61Iris; /* size = 0xF0 */

/* Copies of D_80107440 / D_80107458 that func_80102F74 takes onto its stack. */
typedef struct Ovl61Pairs {
    s32 v[3][2]; /* the three pairs of character indices */
} Ovl61Pairs;
typedef struct Ovl61MotPairs {
    s32* v[3][2]; /* their motion lists */
} Ovl61MotPairs;

/* The drawn camera's position (D_800FD2A8 + 0xC). */
#define OVL61_CAM_POS ((Vec*)((u8*)D_800FD2A8_FDEA8 + 0xC))

/* main */
extern u16 D_801011FC_101DFC;
extern TextWindow* D_800F920C_F9E0C;
extern unk_800ECDE0* D_800F86D8_F92D8;
extern void* D_800FD2A8_FDEA8; /* the camera being drawn; its Vec at 0xC */
extern u8 D_800FDBE0_FE7E0;    /* the frame buffer being drawn */

typedef struct Ovl61Esprite {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s16 grp;
    /* 0x06 */ char unk06[0x1E];
} Ovl61Esprite; /* size = 0x24, 1AE60.c's EspriteSlot */
extern Ovl61Esprite* D_800F93FC_F9FFC;

s32 HuGetPadInserted(s16);
void* DataRead(s32 dirAndFile);
void* HuMemMemoryAllocTemp(u32 size);
void HuMemMemoryFreePerm(void* ptr);
void HuMemMemoryFreeTemp(void* ptr);
void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
void Hu3DCamSetPositionOrientation(s16, Vec*, Vec*, Vec*);
void Hu3DCamUpdateMtx(s16 camIndex);
f64 fabs(f64);
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* cos */
f32 HuVecDistance(Vec* a, Vec* b);
s16 LoadFormFile(s32, s32);
void MBVecNormalize(Vec*);
s32 PlaySound(s32);
void SprAnimKill(s16 animIdx);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
void espDispOff(u16);
void espPosSet(u16 spriteId, s16 x, s16 y);
void func_80015950_16550(s32);
s16 func_8001A2F8_1AEF8(s32 arg0);
void func_8001A708_1B308(u16, u16);
s16 func_8001AAAC_1B6AC(s16 arg0, u16 arg1, u16 arg2);
void func_8001AC44_1B844(u16 arg0);
void func_800209C4_215C4(s16 camIndex, Vec* worldPos, Vec2f* outPos);
void func_80020D20_21920(s16 arg0);
u16 func_80020EBC_21ABC(void* arg0, s32 arg1, u8 arg2);
void func_80021160_21D60(s16 index, s32 arg1, s32 arg2);
void func_800211E8_21DE8(s16 index, u8 arg1);
void func_80021250_21E50(s16 index, u8 arg1, u8 arg2, u8 arg3);
void func_8002308C_23C8C(s32 index);
s16 func_80025384_25F84(s16 arg0, s16 arg1, s16 arg2, s32 arg3);
void func_80025554_26154(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
s32 func_80025684_26284(s32 id); /* 26284.c: s16; retail callers re-extend the result */
void func_800256CC_262CC(s16 arg0, s16 arg1, s32 arg2, s32 arg3);
void* func_80027154_27D54(s32, s32); /* HuMemAllocTag */
void func_80027340_27F40(void*);
s16 func_8002838C_28F8C(s32 arg0, void (*arg1)(Gfx**, s32, s32), u8 arg2);
void func_800283DC_28FDC(s16 arg0);
void func_80029714_2A314(s16, f32, f32, f32); /* model position */
void func_8002979C_2A39C(s16, f32, f32, f32); /* model rotation */
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale */
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029AFC_2A6FC(s16);
void func_80029B80_2A780(s16 arg0, s16 arg1);
void func_80029BF0_2A7F0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void func_8002A00C_2AC0C(s16);
void func_8002A4E0_2B0E0(s16 arg0, s16 arg1, f32 arg2, char* arg3, char* arg4, s32 arg5);
s32 func_8002C8B8_2D4B8(void*, s16); /* s16 in 274D0.c; retail uses the result unextended */
void func_8002C9C0_2D5C0(s16, s16);
void func_80039018_39C18(s16 arg0);
s16 func_8003DF08_3EB08(void* arg);
void func_8003E888_3F488(s16 arg0);
f32 func_80042BE0_437E0(Vec*); /* y angle of a direction */
void func_80056658_57258(Vec*, Vec*, Vec*); /* direction from a to b */
void func_80079614_7A214(s16 time); /* music fade-out */
s32 func_8007975C_7A35C(s16 arg0, s16 arg1); /* character voice */
void func_80079A70_7A670(s32);
void func_80079B88_7A788(void);
HuSprite* func_80082550_83150(s16 grpIdx, s16 idx);
s32 func_800888A8_894A8(s16, s16, s16, s16, s32, s16);
void func_800890CC_89CCC(s16, s32, s32, s32);
s32 func_80089404_8A004(s16 win_id, u32 spriteMainFsPair, s16 arg2, s16 arg3, s16 arg4);
void func_80089A48_8A648(s16, s16);
void func_80089B2C_8A72C(s16, s16);
void func_80089C78_8A878(s16 winId, u8 arg1);
void func_80089DA0_8A9A0(s16 winId, u8 r, u8 g, u8 b);
void func_8008D530_8E130(s16 winId, u8 r, u8 g, u8 b);
void func_8008D5D8_8E1D8(s16 winId); /* hide a window */
void func_8008D6F0_8E2F0(s16 winId); /* show a window */
void func_8008DACC_8E6CC(s32, s16*, s32); /* a message's window size */
void omDelObj(omObjData*);
void omSetRot(omObjData*, f32, f32, f32);
void omSetSca(omObjData*, f32, f32, f32);
void omSetTra(omObjData*, f32, f32, f32);

/* .data */
extern Vec D_80107080_3D48D0_name_61; /* camera position */
extern Vec D_8010708C_3D48DC_name_61; /* camera target */
extern Vec D_80107098_3D48E8_name_61; /* camera up */
extern s16 D_801070A4_3D48F4_name_61[8];
extern s32* D_80107174_3D49C4_name_61[8];
extern s16 D_80107194_3D49E4_name_61;
extern Vec D_80107198_3D49E8_name_61;
extern s32* D_801071EC_3D4A3C_name_61[6];
extern s32 D_80107204_3D4A54_name_61[];
extern s32 D_8010720C_3D4A5C_name_61[];
extern Vec D_80107224_3D4A74_name_61[2];
extern Vec D_8010723C_3D4A8C_name_61[2];
extern Vec D_80107254_3D4AA4_name_61;
extern s32 D_801072D8_3D4B28_name_61[];
extern Vec D_801072F8_3D4B48_name_61[8];
extern s32* D_80107388_3D4BD8_name_61[6];
extern Vec D_801073A0_3D4BF0_name_61;
extern Vec D_801073AC_3D4BFC_name_61;
extern s32 D_801073B8_3D4C08_name_61[8];
extern Vec D_801073D8_3D4C28_name_61[8];
extern s32 D_80107440_3D4C90_name_61[3][2];
extern s32* D_80107458_3D4CA8_name_61[3][2];

/* .bss */
extern omObjData* D_801074D0_3D4D20_name_61;    /* the curtain */
extern omObjData* D_801074D8_3D4D28_name_61[8]; /* characters 0-5, Toad (6), host (7) */
extern s16 D_801074F8_3D4D48_name_61;           /* the scene is over */
extern s16 D_801074FA_3D4D4A_name_61[3];
extern s16 D_80107500_3D4D50_name_61;           /* message window */
extern s16 D_80107502_3D4D52_name_61;
extern s16 D_80107504_3D4D54_name_61;
extern s16 D_80107506_3D4D56_name_61;
extern omObjData* D_80107508_3D4D58_name_61;    /* sparks */
extern u8* D_8010750C_3D4D5C_name_61[3];        /* iris coverage, 320x240 per frame buffer */
extern Gfx* D_80107518_3D4D68_name_61[3];       /* iris display list per frame buffer */
extern s32 D_80107524_3D4D74_name_61;           /* iris colour r, g, b, a */
extern s32 D_80107528_3D4D78_name_61;
extern s32 D_8010752C_3D4D7C_name_61;
extern s32 D_80107530_3D4D80_name_61;
extern s16 D_80107534_3D4D84_name_61;
extern s16 D_80107536_3D4D86_name_61;
extern s16 D_80107538_3D4D88_name_61;
extern s16 D_8010753A_3D4D8A_name_61;           /* hole bitmap width */
extern s16 D_8010753C_3D4D8C_name_61;           /* hole bitmap height */
extern u8* D_80107540_3D4D90_name_61;           /* hole bitmap */
extern Ovl61Iris* D_80107544_3D4D94_name_61;

/* 3D0050.c */
void func_80102800_3D0050_name_61(void);
void func_80102A10_3D0260_name_61(void);
void func_80102AC8_3D0318_name_61(void);
void func_80102B50_3D03A0_name_61(void);
void func_80102BC0_3D0410_name_61(void);
void func_80102F74_3D07C4_name_61(void);
void func_80103EA0_3D16F0_name_61(void);
void func_801046E0_3D1F30_name_61(void);
void func_8010492C_3D217C_name_61(void);
void func_80104A88_3D22D8_name_61(void);
void func_80104A90_3D22E0_name_61(f32 time);
void func_80104C14_3D2464_name_61(void);
void func_80104DA8_3D25F8_name_61(f32 time);
void func_80104F24_3D2774_name_61(void);
void func_8010509C_3D28EC_name_61(f32 y, u16 time);
void func_80105160_3D29B0_name_61(u16 time);
void func_80105398_3D2BE8_name_61(f32 y);
void func_801053AC_3D2BFC_name_61(s32 file);
void func_8010544C_3D2C9C_name_61(void);
void func_801054A0_3D2CF0_name_61(void);
void func_8010568C_3D2EDC_name_61(s32 idx, s32* list);
void func_80105744_3D2F94_name_61(s32 idx);
void func_801057D4_3D3024_name_61(s32 idx, s32 mot, s16 arg2, s16 arg3);
void func_80105858_3D30A8_name_61(s32 idx, s32 mot, s16 arg2, s16 arg3, s16 arg4);
void func_801058B0_3D3100_name_61(s32 idx);
void func_801058F0_3D3140_name_61(s32 idx, s32 mode);
s16 func_801059B0_3D3200_name_61(s32 idx, Vec* target, f32 speed);
s32 func_80105ABC_3D330C_name_61(s32 idx, Vec* target, f32 step);
void func_80105C6C_3D34BC_name_61(void);
void func_80105DEC_3D363C_name_61(omObjData* obj);
s16 func_80106168_3D39B8_name_61(void);
void func_801061A8_3D39F8_name_61(void);
void func_80106208_3D3A58_name_61(void);
void func_8010621C_3D3A6C_name_61(void);
void func_8010622C_3D3A7C_name_61(s16 win);
void func_8010624C_3D3A9C_name_61(s16 win, s32 mess, s16 arg2, s16 arg3);
void func_801062B8_3D3B08_name_61(void);
void func_801064A0_3D3CF0_name_61(void);
void func_8010652C_3D3D7C_name_61(Gfx** gfx, s32 arg1, s32 arg2);
void func_801066B8_3D3F08_name_61(s32 fb, s16 build);
void func_80106A04_3D4254_name_61(s32 fb, s32 hole);
void func_80106D18_3D4568_name_61(s32 fb);
s16 func_80106D54_3D45A4_name_61(s32 x, s32 y, f32 sx, f32 sy);
void func_80106E88_3D46D8_name_61(s16 hole);
void func_80106EAC_3D46FC_name_61(u8 r, u8 g, u8 b, u8 a);
void func_80106EE0_3D4730_name_61(s16 time, f32 dr, f32 dg, f32 db, f32 da);
void func_80106F44_3D4794_name_61(s16 hole, s16 x, s16 y);
void func_80106F64_3D47B4_name_61(s16 hole, f32 sx, f32 sy);
void func_80106F84_3D47D4_name_61(Vec2f* pos);
void func_80107030_3D4880_name_61(s16 hole);
void func_80107054_3D48A4_name_61(s16 hole);

#endif
