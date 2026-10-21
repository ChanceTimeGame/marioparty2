#ifndef _GAME_HMFMAN_H
#define _GAME_HMFMAN_H

#include "ultra64.h"
#include "common_structs.h"

/* HMF model data. Names follow MP3's include/game/hmfman.h where MP3 has the
   field at the same offset; MP2's HmfData differs from MP3's from 0x50 on
   (fields sit 4 bytes later), so it is built from MP2's own units. */

typedef struct HmfVtx {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s16 unk04;
    /* 0x06 */ char unk06[2];
    /* 0x08 */ s16 unk08;
    /* 0x0A */ s16 unk0A;
    /* 0x0C */ u8 unk0C[3];
    /* 0x0F */ u8 unk0F;
} HmfVtx; /* size = 0x10 (MP1 unk2C0C0StructE0) */

typedef struct HmfFace {
    /* 0x00 */ u8 unk00;
    /* 0x01 */ char unk01;
    /* 0x02 */ s16 unk02[1]; /* unknown array size */
    /* 0x04 */ char unk04[8];
    /* 0x0C */ f32 unk0C;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
} HmfFace; /* size = 0x18 (MP1 unk2C0C0StructB0) */

typedef struct HmfPal {
    /* 0x00 */ char unk00[0x1C];
    /* 0x1C */ u8 unk1C;
    /* 0x1D */ char unk1D;
    /* 0x1E */ s16 unk1E; /* colour count; MP1 0x1A */
    /* 0x20 */ s16 unk20;
    /* 0x22 */ char unk22[2];
    /* 0x24 */ void* unk24;
    /* 0x28 */ u16* unk28; /* the palette */
} HmfPal; /* MP1 unk2C0C0Struct60 / unk388E0Struct80 */

typedef struct HmfTex {
    /* 0x00 */ char unk00[0x1C];
    /* 0x1C */ u8 unk1C; /* format; MP1 0x18 */
    /* 0x1D */ u8 unk1D; /* size */
    /* 0x1E */ u8 unk1E; /* width */
    /* 0x1F */ u8 unk1F; /* height */
    /* 0x20 */ char unk20[2];
    /* 0x22 */ s16 unk22;
    /* 0x24 */ u16 unk24; /* users */
    /* 0x26 */ char unk26[2];
    /* 0x28 */ u8* unk28; /* image */
    /* 0x2C */ void* unk2C; /* MP1 0x28 */
    /* 0x30 */ HmfPal* unk30; /* MP1 0x2C */
} HmfTex; /* size >= 0x34; MP1 unk2C0C0Struct70 */

typedef struct HmfTexRef {
    /* 0x00 */ s8 unk00;
    /* 0x01 */ s8 unk01;
    /* 0x02 */ s8 unk02;
    /* 0x03 */ s8 unk03;
    /* 0x04 */ s8 unk04;
    /* 0x05 */ u8 unk05;
    /* 0x06 */ u8 unk06;
    /* 0x07 */ u8 unk07;
    /* 0x08 */ char unk08;
    /* 0x09 */ u8 unk09;
    /* 0x0A */ char unk0A[2];
    /* 0x0C */ HmfTex* unk0C;
} HmfTexRef; /* size = 0x10; MP1 unk2C0C0Struct80 */

typedef struct HmfMat {
    /* 0x00 */ u8 unk00; /* index */
    /* 0x01 */ u8 unk01[3]; /* colour */
    /* 0x04 */ u8 unk04;
    /* 0x05 */ u8 unk05[3]; /* second colour (vertex colour of unlit faces) */
    /* 0x08 */ u8 unk08;
    /* 0x09 */ u8 unk09[3];
    /* 0x0C */ u8 unk0C; /* flags; s8 or u8 both match */
    /* 0x0D */ u8 unk0D;
} HmfMat; /* size = 0xE */

typedef struct HmfAnimTrack {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s16 unk04;
    /* 0x06 */ s16 unk06;
    /* 0x08 */ u16* unk08;
    /* 0x0C */ s32* unk0C;
} HmfAnimTrack; /* size = 0x10 */

typedef struct HmfAnim {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s16 unk04;
    /* 0x06 */ char unk06[2];
    /* 0x08 */ f32 unk08; /* frame; 19BF0's s32 zero store matches as f32 */
    /* 0x0C */ HmfAnimTrack unk0C[16];
} HmfAnim;

typedef struct HmfDisp {
    /* 0x00 */ void* unk00[4];
} HmfDisp; /* MP3 HmfModelData_Unk64_Unk3C_Struct */

typedef struct HmfPart {
    /* 0x00 */ s16 unk00; /* material colour track target */
    /* 0x02 */ s16 unk02; /* alpha */
    /* 0x04 */ s16 unk04; /* face count */
    /* 0x06 */ char unk06[2];
    /* 0x08 */ s16 unk08; /* name hash (func_8001F4AC_200AC of unk12) */
    /* 0x0A */ s16 unk0A; /* first vertex */
    /* 0x0C */ s16 unk0C; /* vertex count */
    /* 0x0E */ u16 unk0E; /* first face */
    /* 0x10 */ u16 unk10; /* face count */
    /* 0x12 */ char unk12[0x1C]; /* name */
    /* 0x2E */ u8 unk2E; /* reflection texture (unk88 index), 0xFF for none; MP3 0x1C */
    /* 0x2F */ u8 unk2F;
    /* 0x30 */ char unk30[0x12];
    /* 0x42 */ s16 unk42; /* 0x42-0x4C: -0x8000 in a display-list model (274D0) */
    /* 0x44 */ s16 unk44;
    /* 0x46 */ s16 unk46;
    /* 0x48 */ s16 unk48;
    /* 0x4A */ s16 unk4A;
    /* 0x4C */ s16 unk4C;
    /* 0x4E */ char unk4E[2];
    /* 0x50 */ s32 unk50;
    /* 0x54 */ struct HmfFaceRec* unk54; /* faces (0x34 bytes each; 30560) */
    /* 0x58 */ struct HmfData* unk58; /* linked model drawn after this part */
    /* 0x5C */ s32 unk5C; /* 30560: a HmfTexRef* (the texture its second list loads), -1 none */
    /* 0x60 */ s32 unk60; /* 30560: a HmfTexRef* (the texture loaded last) */
    /* 0x64 */ Gfx* unk64; /* second display list, appended to the part's own (30560) */
} HmfPart; /* size = 0x68; MP3 HmfModelData_Unk64_Unk60_Struct */

typedef struct ColVtx {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ s16 z;
} ColVtx;

/* A copy of a model's vertex positions and colours (HmfData.unk5C; 30560) */
typedef struct HmfVtxCopy {
    /* 0x00 */ s16 unk00; /* vertex count */
    /* 0x02 */ char unk02[2];
    /* 0x04 */ ColVtx* unk04;
    /* 0x08 */ u8* unk08; /* colours, 3 bytes each */
    /* 0x0C */ u8* unk0C; /* one bit per vertex */
} HmfVtxCopy; /* size = 0x10 */

typedef struct HitXform {
    /* 0x00 */ s16 unk00; /* part index, < 0 for none */
    /* 0x02 */ s16 unk02; /* offset to the next sibling */
    /* 0x04 */ s16 unk04; /* offset to the first child */
    /* 0x06 */ char unk06[2];
    /* 0x08 */ Vec unk08;
    /* 0x14 */ Vec unk14;
    /* 0x20 */ Vec unk20; /* scale */
    /* 0x2C */ Vec unk2C; /* translation */
    /* 0x38 */ Vec unk38; /* rotation */
    /* 0x44 */ u8 unk44;
    /* 0x45 */ u8 unk45;
    /* 0x46 */ char unk46[2];
    /* 0x48 */ struct HmfData* unk48;
    /* 0x4C */ f32 unk4C[4][4];
} HitXform; /* size 0x8C; MP1 unk2C0C0Struct40 */

typedef struct HmfData {
    /* 0x00 */ u8 unk00;
    /* 0x01 */ u8 unk01; /* the model's draw flags (HmfModel.unk00) */
    /* 0x02 */ u8 unk02; /* 0x02-0x05: colour (MP1 0x2A) */
    /* 0x03 */ u8 unk03;
    /* 0x04 */ u8 unk04;
    /* 0x05 */ u8 unk05;
    /* 0x06 */ u8 unk06; /* 0x06-0x09: second colour (MP1 0x2E) */
    /* 0x07 */ u8 unk07;
    /* 0x08 */ u8 unk08;
    /* 0x09 */ u8 unk09;
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ u8 unk0B; /* link count */
    /* 0x0C */ u8 unk0C; /* times drawn this frame */
    /* 0x0D */ char unk0D;
    /* 0x0E */ s16 unk0E; /* MP1 0x68; MP3's s16 (s16/u16 both match) */
    /* 0x10 */ s16 unk10;
    /* 0x12 */ s16 unk12; /* texture count; MP1 0x6C */
    /* 0x14 */ s16 unk14; /* MP3 HmfData.unk14 */
    /* 0x16 */ s16 unk16; /* motion object count (unk84) */
    /* 0x18 */ s16 unk18; /* vertex count; MP1 0x72 */
    /* 0x1A */ s16 unk1A; /* MP1 0x74 */
    /* 0x1C */ s16 unk1C; /* u16 in 1D0B0's view */
    /* 0x1E */ s16 unk1E;
    /* 0x20 */ char unk20[2];
    /* 0x22 */ s16 unk22; /* morph animation count (unkBC) */
    /* 0x24 */ char unk24[2];
    /* 0x26 */ s16 unk26;
    /* 0x28 */ s16 unk28; /* texture-animation count (3D6A0); unkC8's entry count (274D0) */
    /* 0x2A */ char unk2A[6];
    /* 0x30 */ u8* unk30; /* chunk end (3D6A0) */
    /* 0x34 */ u8* unk34; /* chunk start (3D6A0) */
    /* 0x38 */ void* unk38; /* the MAP1 chunk */
    /* 0x3C */ HmfDisp* unk3C; /* or a single Gfx* list, by flag */
    /* 0x40 */ HmfVtx* unk40; /* MP1 0x04 */
    /* 0x44 */ HmfVtx* unk44[4]; /* per frame buffer; MP1 0x08 */
    /* 0x54 */ ColVtx* unk54; /* MP1 0x78 */
    /* 0x58 */ u8* unk58; /* vertex colours, 3 bytes each; MP1 0x7C */
    /* 0x5C */ HmfVtxCopy* unk5C;
    /* 0x60 */ s16* unk60; /* per vertex: its slot in the frame's vertex buffer */
    /* 0x64 */ HmfPart* unk64;
    /* 0x68 */ s16 unk68; /* MP1 0x84 */
    /* 0x6A */ char unk6A[2];
    /* 0x6C */ HitXform* unk6C; /* MP1 0x88 */
    /* 0x70 */ char unk70[0x14];
    /* 0x84 */ void* unk84; /* MP1 0xA0 */
    /* 0x88 */ HmfTexRef* unk88; /* MP1 0xA4 */
    /* 0x8C */ HmfMat* unk8C; /* MP1 0xA8 */
    /* 0x90 */ void* unk90; /* MP1 0xAC, an HmfMotion */
    /* 0x94 */ void* unk94; /* MP1 0xB0: the motion blended in */
    /* 0x98 */ void* unk98; /* MP1 0xB4: the third motion */
    /* 0x9C */ HmfAnim* unk9C; /* MP1 0xB8 */
    /* 0xA0 */ void* unkA0;
    /* 0xA4 */ f32 unkA4; /* MP1 0xC0 */
    /* 0xA8 */ f32 unkA8; /* unk94's frame */
    /* 0xAC */ f32 unkAC; /* blend weight */
    /* 0xB0 */ f32 unkB0; /* unk98's frame */
    /* 0xB4 */ HmfFace* unkB4; /* MP1 0xD0 */
    /* 0xB8 */ void* unkB8; /* 1D0B0's HmfDispData */
    /* 0xBC */ void* unkBC; /* 1D0B0's HmfMtnData: morph animations (unk22) */
    /* 0xC0 */ char unkC0[8];
    /* 0xC8 */ s32 unkC8; /* a u8* list (texture animation slots, unk28 entries): a pointer in an s32 slot; HMF_TEXANIM (3D6A0) */
    /* 0xCC */ Gfx*** unkCC; /* -> per-part second display lists (30560) */
    /* 0xD0 */ struct HmfData_UnkD0* unkD0; /* the drawing model's lights */
    /* 0xD4 */ void (*unkD4)(f32 (*)[4], f32, f32, f32); /* rotation */
    /* 0xD8 */ void (*unkD8)(f32 (*)[4], f32, f32, f32);
    /* 0xDC */ char unkDC[4];
} HmfData; /* size 0xE0 (Hu3DModelCreate allocates it); MP1 unk2C0C0StructC0 */

typedef struct HmfData_UnkD0 {
    /* 0x00 */ s8 unk00;
    /* 0x01 */ s8 unk01;
    /* 0x02 */ s8 unk02;
    /* 0x03 */ s8 unk03;
    /* 0x04 */ s8 unk04;
    /* 0x05 */ s8 unk05;
    /* 0x06 */ s8 unk06;
    /* 0x07 */ char unk07[1];
    /* 0x08 */ Light unk08[1]; /* length unknown */
} HmfData_UnkD0; /* size unknown */

typedef struct HmfModel {
    /* 0x00 */ s8 unk00;
    /* 0x01 */ u8 unk01;
    /* 0x02 */ u8 unk02;
    /* 0x03 */ u8 unk03;
    /* 0x04 */ u8 unk04;
    /* 0x05 */ u8 unk05;
    /* 0x06 */ u8 unk06;
    /* 0x07 */ s8 unk07;
    /* 0x08 */ u8 unk08;
    /* 0x09 */ u8 unk09;
    /* 0x0A */ u8 unk0A;
    /* 0x0C */ s16 unk0C;
    /* 0x0E */ s16 unk0E;
    /* 0x10 */ s16 unk10; /* hit grid; MP1 unk_04 */
    /* 0x12 */ char unk12[2];
    /* 0x14 */ f32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ Vec pos;
    /* 0x28 */ Vec rot;
    /* 0x34 */ Vec scale;
    /* 0x40 */ f32 unk40;
    /* 0x44 */ f32 unk44;
    /* 0x48 */ f32 unk48;
    /* 0x4C */ f32 unk4C;
    /* 0x50 */ f32 unk50;
    /* 0x54 */ f32 unk54;
    /* 0x58 */ f32 unk58;
    /* 0x5C */ f32 unk5C;
    /* 0x60 */ f32 unk60;
    /* 0x64 */ HmfData* hmf;
    /* 0x68 */ HmfData* unk68; /* the model whose part unk0A this one follows (MP1 0x70) */
    /* 0x6C */ HmfData* unk6C; /* released instead of hmf while unk09 is set and unk14 != 0 */
    /* 0x70 */ void (*unk70)(Gfx**, s32, s32);
    /* 0x74 */ f32 mtx[16];
    /* 0xB4 */ struct HmfModel* unkB4;
    /* 0xB8 */ s32 unkB8;
    /* 0xBC */ void* unkBC;
} HmfModel; /* size = 0xC0 */

/* Motion slots (128, allocated by func_80038DD0_399D0); MP1 unk34D80Struct40 */
typedef struct HmfMotionSlot {
    /* 0x00 */ u8 unk00;
    /* 0x01 */ char unk01;
    /* 0x02 */ s16 unk02; /* length; -1 when the slot is free */
    /* 0x04 */ char unk04[4];
    /* 0x08 */ struct HmfMotionTrack** unk08; /* tracks (0x10 bytes each; 30560's HmfMotionTrack) */
    /* 0x0C */ u8* unk0C; /* per track: its kind (0x4E transform tree, 0x0D motion object) */
    /* 0x10 */ s16* unk10; /* key frames */
    /* 0x14 */ f32* unk14; /* key values */
    /* 0x18 */ s32 unk18;
} HmfMotionSlot; /* size 0x1C */

extern HmfModel* D_800FC834_FD434; /* HmfModelData */
extern HmfMotionSlot* D_800F92B4_F9EB4;
extern s8 D_800FDC9C_FE89C;  /* MP3 HmfPauseF; s8 as 5F3B0/58080/80230 load it */
extern u16 D_800FDCD0_FE8D0; /* set while models are live (274D0, 30560) */
extern void* D_800FD2A8_FDEA8; /* model matrix buffer (274D0 passes it to HmfModel.unk70) */

#endif
