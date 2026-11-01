#ifndef _OVL_27_H
#define _OVL_27_H

/* Overlay 27: Abandon Ship (4P). No MP1 ancestor bar the flag wave (MP1 Bombs Away 1B02A0.c).
   Retail is two files: 1FEE60.c (80102800-80106C38, 2-nop pad) and 2032A0.c (80106C40-end).
   .data stays asm (2059E0.data.s); .rodata is carved per file (0x205B30, 0x205B80). */

#include "common.h"
#include "game/object.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/pad.h"
#include "game/sprite.h"
#include "game/data.h"
#include "game/collision.h"

/* ---- structs ---- */

/* omObjData::unk_50 of a mast (0xAC, ColActorWork's size): func_80105EC8_202528_AbandonShip sets it up. */
typedef struct ASMastWork {
    /* 0x00 */ char unk_00[0x21];
    /* 0x21 */ u8 unk_21; /* the coin flash */
    /* 0x22 */ char unk_22[0x12];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50;
    /* 0x52 */ char unk_52[2];
    /* 0x54 */ u8 unk_54;
    /* 0x55 */ char unk_55[0x1F];
    /* 0x74 */ f32 unk_74;
    /* 0x78 */ s32 unk_78; /* flash frames */
    /* 0x7C */ s32 unk_7C;
    /* 0x80 */ char unk_80[0x2C];
} ASMastWork; /* size = 0xAC */

/* The sail's vertices: their column and row in the mesh. */
typedef struct ASFlagVtx {
    /* 0x0 */ s16 move; /* 0 on the edge */
    /* 0x2 */ s16 col;
    /* 0x4 */ s16 row;
} ASFlagVtx; /* size = 6 */

typedef struct ASCharData {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s32 unk_04; /* motion directory */
    /* 0x08 */ s32 unk_08; /* model file */
    /* 0x0C */ char unk_0C[0xC];
} ASCharData; /* size = 0x18 */

typedef struct ASRope {
    /* 0x0 */ f32 x;
    /* 0x4 */ f32 y;
} ASRope; /* size = 8 */

/* ---- main ---- */

extern f32 D_800BF7A0_C03A0;
extern f32 D_800BF7C8_C03C8;
extern ASCharData D_800CD438_CE038[];
extern s32 D_800F8FD0_F9BD0; /* scene state */
extern u16 D_800FA606_FB206;
extern u8 D_800FDBE0_FE7E0;
extern u16 D_801011FC_101DFC;
extern u8 D_80102720_103320;
extern f32 D_80102750_103350[]; /* D_8010274C_10334C + 4: retail's own label */
extern s8 ContStkX[4];
extern s8 ContStkY[4];

void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
void Hu3DCam3DToScreen(s16 camIndex, Vec* worldPos, Vec2f* outPos);
void Hu3DCamSetPerspective(s16, f32, f32, f32);
f32 HuMathSin(f32);
void InitFadeIn(s32, s32);
void InitFadeOut(s32, s32);
s16 PlayMusic(s16);
s32 PlaySound(s32);
void ScissorSet(u8, f32, f32, f32, f32);
void SprAttrSet(s16 grpIdx, s16 idx, s32 flag);
void ViewportSet(u8, f32, f32, f32, f32, f32, f32);
s32 _CheckFlag(s32);
void espDispOff(u16);
void espDispOn(u16);
void espPosSet(u16 spriteId, s16 x, s16 y);
void func_8000BEF8_CAF8(omObjData*, s32, f32);
void func_8000C018_CC18(u16);
void func_8000C024_CC24(omObjData* obj, u8 idx, u8 val);
void func_8000C38C_CF8C(void);
void func_8000C398_CF98(void);
void func_8000C3A8_CFA8(void);
void func_8000C3B8_CFB8(void);
void func_8000C3C8_CFC8(void);
void func_8000C460_D060(void);
void func_8000C578_D178(s32);
void func_8000C690_D290(void);
void func_8000C6FC_D2FC(omObjData* obj, u32 dir, s32 file, u16 player, s32 arg4, s32 arg5);
u16 func_80018A30_19630(s32 file, s32 attr);
void func_80018CCC_198CC(omObjData* obj, u16 slot, s32 file);
u16 func_80018D64_19964(s32 arg0, s32 arg1, s32 arg2);
void func_80018E30_19A30(s32);
s32 func_80018E78_19A78(void);
s16 func_8001A2F8_1AEF8(s32);
void func_8001A91C_1B51C(u16 spriteId, f32 x, f32 y);
s16 func_8001AAAC_1B6AC(s16 arg0, u16 arg1, u16 arg2);
void func_80020D20_21920(s16 arg0);
void func_80021198_21D98(s16 index, u16 arg1);
void func_800211E8_21DE8(s16 index, u8 arg1);
void func_80021250_21E50(s16 index, u8 arg1, u8 arg2, u8 arg3);
void func_80026DAC_279AC(s16, u8, u8, u8);
void* func_80027154_27D54(s32 size, s16 tag);
s16 func_80027D3C_2893C(s16 linkMdlId);
void func_80029714_2A314(s16, f32, f32, f32);
void func_8002979C_2A39C(s16 idx, f32 x, f32 y, f32 z);
void func_800297E8_2A3E8(s16, f32, f32, f32);
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029A8C_2A68C(s16);
void func_80029BF0_2A7F0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void func_80029C74_2A874(s16, f32);
s32 func_80029E14_2AA14(s16 arg0); /* 2AA14.c: u8; retail callers re-extend the result */
void func_80029E80_2AA80(s16, s32, s32);
void func_8002A00C_2AC0C(s16 model);
void func_8002A15C_2AD5C(s16 arg0, s16 arg1, f32 arg2);
void func_8002C3A0_2CFA0(s16 arg0);
void func_8002CA48_2D648(u8 arg0, u8 arg1, u8 arg2);
void func_8002D4D0_2E0D0(s16 n);
void func_8002F290_2FE90(s32* arg0, s32 n);
s16 func_800691FC_69DFC(s16 mesNo, ...);
s32 func_80069538_6A138(void);
void func_8006961C_6A21C(s16 mesId, f32 x, f32 y);
void func_8006D4D0_6E0D0(s16 seconds);
void func_8006D518_6E118(void);
u16 func_80078EA8_79AA8(void);
void func_80079128_79D28(void);
void func_800794A8_7A0A8(s32);
s16 func_80079798_7A398(s16 sfx, s16 player);
s16 func_800797DC_7A3DC(s32 id, s16 player);
void func_80079868_7A468(void);
void func_800799A4_7A5A4(s16, s32);
s32 func_8008F618_90218(void);
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size);
f32 func_800B1830_B2430(f32);
f32 func_800B7890_B8490(f32);
s32 omOvlReturnEx(s16);
u8 rand8(void);

/* ---- .data (asm, 2059E0.data.s) ---- */

extern s8 D_80109380_2059E0_AbandonShip; /* result: 0 none, 1 a winner, 2 all out */
extern s8 D_80109381_2059E1_AbandonShip; /* the winner, a player */
extern s32 D_80109384_2059E4_AbandonShip; /* seconds, 31 */
extern s8 D_80109388_2059E8_AbandonShip; /* boats made */
extern s8 D_80109389_2059E9_AbandonShip; /* sharks made: split label, byte 1 of 80109388 */
extern s32 D_8010938C_2059EC_AbandonShip; /* game frames */
extern u32 D_80109390_2059F0_AbandonShip; /* end frames */
extern s32 D_80109394_2059F4_AbandonShip; /* seconds left; low half read as (s16) */
extern s32 D_80109398_2059F8_AbandonShip;
extern s8 D_8010939C_2059FC_AbandonShip;
extern s8 D_8010939D_2059FD_AbandonShip;
extern s8 D_8010939E_2059FE_AbandonShip;
extern s8 D_8010939F_2059FF_AbandonShip;
extern f32 D_801093A0_205A00_AbandonShip[2]; /* rescue boats' fade */
extern f32 D_801093A8_205A08_AbandonShip[6]; /* shark jump heights */
extern s8 D_801093C0_205A20_AbandonShip; /* game state */
extern f32 D_801093C4_205A24_AbandonShip[4]; /* mast x */
extern f32 D_801093D4_205A34_AbandonShip; /* the waves' height */
extern f32 D_801093D8_205A38_AbandonShip; /* mast height */
extern u8 D_801093DC_205A3C_AbandonShip[3][8]; /* rope pattern's side per rung */
extern u8 D_801093F4_205A54_AbandonShip[3][5]; /* coin rung */
extern u8 D_80109404_205A64_AbandonShip[3][8]; /* rung spacing */
extern u16 D_8010941C_205A7C_AbandonShip; /* flag phase */
extern f32 D_80109420_205A80_AbandonShip;
extern f32 D_80109424_205A84_AbandonShip;
extern s8 D_80109428_205A88_AbandonShip;
extern f32 D_8010942C_205A8C_AbandonShip;
extern s8 D_80109430_205A90_AbandonShip;
extern s8 D_80109440_205AA0_AbandonShip;
extern s16 D_80109442_205AA2_AbandonShip; /* players made */
extern s32 D_80109444_205AA4_AbandonShip[4]; /* player by slot; the low half is the port */
extern Vec D_80109454_205AB4_AbandonShip[4]; /* start positions */
extern u8 D_80109484_205AE4_AbandonShip[5][4]; /* slot to mast */

/* ---- .bss (asm) ---- */

extern s16 D_80109540_205BA0_AbandonShip; /* the ship's sound */
extern omObjData* D_80109544_205BA4_AbandonShip[3]; /* passenger per boat */
extern omObjData* D_80109550_205BB0_AbandonShip[4]; /* players by mast */
extern s16 D_80109560_205BC0_AbandonShip[2];
extern Vec D_80109568_205BC8_AbandonShip[2]; /* boat target */
extern Vec D_80109580_205BE0_AbandonShip;
extern f32 D_80109584_205BE4_AbandonShip[2]; /* its y, z: retail's own label */
extern Vec D_8010958C_205BEC_AbandonShip;
extern u8 D_80109598_205BF8_AbandonShip[2]; /* shark frames */
extern u8 D_8010959A_205BFA_AbandonShip[2];
extern s8 D_8010959C_205BFC_AbandonShip[2]; /* shark jumps done */
extern s8 D_8010959E_205BFE_AbandonShip[2]; /* shark side */
extern f32 D_801095A0_205C00_AbandonShip;
extern Vec D_801095A4_205C04_AbandonShip;
extern Vec D_801095B0_205C10_AbandonShip;
extern Vec D_801095BC_205C1C_AbandonShip;
extern s16 D_801095C8_205C28_AbandonShip;
extern s8 D_801095CA_205C2A_AbandonShip[4]; /* coin flash on */
extern s8 D_801095CE_205C2E_AbandonShip[4]; /* coins taken */
extern s8 D_801095D2_205C32_AbandonShip; /* masts made */
extern s16 D_801095D4_205C34_AbandonShip;
extern s16 D_801095D6_205C36_AbandonShip;
extern s16 D_801095D8_205C38_AbandonShip;
extern s16 D_801095DA_205C3A_AbandonShip;
extern s16 D_801095DC_205C3C_AbandonShip;
extern ASFlagVtx* D_801095E0_205C40_AbandonShip;
extern s32 D_801095E4_205C44_AbandonShip[2];
extern Vec D_801095EC_205C4C_AbandonShip; /* the anchor */
extern u16 D_801095F8_205C58_AbandonShip[4];
extern s8 D_80109608_205C68_AbandonShip[4]; /* CPU pressed A */
extern u32 D_8010960C_205C6C_AbandonShip;
extern ASRope D_80109610_205C70_AbandonShip[4][5]; /* coin positions */
extern s8 D_801096B0_205D10_AbandonShip; /* the pattern */
extern f32 D_801096B8_205D18_AbandonShip[8]; /* rung heights */
extern omObjData* D_801096D8_205D38_AbandonShip[4]; /* masts */

/* ---- functions ---- */

/* 1FEE60.c */
void func_80102800_1FEE60_AbandonShip(void);
void func_8010292C_1FEF8C_AbandonShip(void);
void func_80102A50_1FF0B0_AbandonShip(void);
void func_80102EF8_1FF558_AbandonShip(void);
void func_80102F5C_1FF5BC_AbandonShip(omObjData* obj);
void func_80103070_1FF6D0_AbandonShip(omObjData* obj);
void func_801039B4_200014_AbandonShip(void);
void func_80103A0C_20006C_AbandonShip(omObjData* obj);
void func_80103BDC_20023C_AbandonShip(omObjData* obj);
void func_80104350_2009B0_AbandonShip(void);
void func_801044E0_200B40_AbandonShip(omObjData* obj);
void func_80104678_200CD8_AbandonShip(void);
void func_80104A8C_2010EC_AbandonShip(omObjData* obj);
void func_80104B54_2011B4_AbandonShip(omObjData* obj);
void func_80104C5C_2012BC_AbandonShip(s16 mdl);
void func_801050B8_201718_AbandonShip(s16 mdl, s32 phase);
void func_8010547C_201ADC_AbandonShip(s16* list, u16 n);
void func_80105508_201B68_AbandonShip(omObjData* obj);
void func_80105590_201BF0_AbandonShip(s8* flag);
void func_801055EC_201C4C_AbandonShip(omObjData* obj);
void func_80105754_201DB4_AbandonShip(omObjData* obj);
void func_80105A9C_2020FC_AbandonShip(omObjData* obj);
void func_80105C88_2022E8_AbandonShip(omObjData* obj);
void func_80105EC8_202528_AbandonShip(ASMastWork* w);
void func_80105F38_202598_AbandonShip(omObjData* obj);
void func_8010642C_202A8C_AbandonShip(omObjData* obj);
void func_801068F8_202F58_AbandonShip(omObjData* obj);
/* 2032A0.c */
void func_80106C40_2032A0_AbandonShip(void);
void func_80106D04_203364_AbandonShip(omObjData* obj);
void func_80106F5C_2035BC_AbandonShip(omObjData* obj);
void func_801089A4_205004_AbandonShip(omObjData* obj, f32 step);
void func_80108AB0_205110_AbandonShip(void);
void func_80108DF0_205450_AbandonShip(Vec* out, Vec* from, Vec* to);
void func_80108EA0_205500_AbandonShip(omObjData* obj);
void func_80109064_2056C4_AbandonShip(omObjData* obj);

#endif /* _OVL_27_H */
