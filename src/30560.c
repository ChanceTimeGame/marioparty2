#include "common.h"
#include "game/hmfman.h"
#include "game/camera.h"

/* Model (HMF) setup, display-list build and drawing, materials and textures, matrix walks, motion
   and morph/vertex animation. Most functions are MP1 src/2C0C0.c and src/34D80.c code (a few from
   MP3 src/22EB0.c); the rest were decompiled fresh. MP2's model structs have MP3's layout; fields are
   named by their MP2 offset. */

/* 30560's rodata (D2E30-D2EE0, carved): the strings first, then func_80038C04_39804's jump table
   and func_8003A2B0_3AEB0's doubles. Named, as functions still in asm use them */
const char D_800D2230_D2E30[] __attribute__((section(".rodata"))) = "Vertex Over!\n";
const char D_800D2240_D2E40[] __attribute__((section(".rodata"))) = "Texture Anime Over\n";
const char D_800D2254_D2E54[] __attribute__((section(".rodata"))) = "Mtx Over\n";
const char D_800D2260_D2E60[] __attribute__((section(".rodata"))) = "GfxMax Over\n";
const char D_800D2270_D2E70[] __attribute__((section(".rodata"))) = "Model Object Entry Over!! UCODE%d\n";
const char D_800D2294_D2E94[] __attribute__((section(".rodata"))) = "Can't find ObjName %s\n";

typedef f32 Matrix4f[4][4];

#define INTEGER_LOG2(x) ((x) <= 2 ? 1 : (x) <= 4 ? 2 : (x) <= 8 ? 3 : (x) <= 16 ? 4 : (x) <= 32 ? 5 : (x) <= 64 ? 6 : (x) <= 128 ? 7 : 8)

/* MP1 unk2C0C0StructE0 */

/* MP1 unk2C0C0StructB0 */

/* MP1 unk2C0C0Struct60 (4 bytes longer at the start in MP2) */

/* MP1 unk2C0C0Struct70 (4 bytes longer at the start in MP2) */

/* MP1 unk2C0C0Struct90 */

/* MP1 unk34D80Struct80 */
/* A motion track (MP1 unk34D80Struct60) */
typedef struct HmfMotionTrack {
    /* 0x00 */ u8 unk_00; /* channel: 0x17, 0x1B, 0x4C, 0x4F */
    /* 0x01 */ u8 unk_01; /* axis 'E', 'F', 'G' */
    /* 0x02 */ u8 unk_02; /* 'I': interpolated */
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ s16 unk_04; /* 0x8000: off */
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ u16 unk_08; /* target index; 0x7FFF for 0 */
    /* 0x0A */ s16 unk_0A; /* first key frame (in the slot's unk10) */
    /* 0x0C */ s16 unk_0C; /* first key value (in the slot's unk14) */
    /* 0x0E */ s16 unk_0E; /* key count */
} HmfMotionTrack; /* size = 0x10; MP1 unk34D80Struct60 */



/* MP1 unk2C0C0StructB4 */

/* MP1 unk2C0C0StructB8 */

/* MP3 HmfModelData_Unk64_Unk3C_Struct */

/* MP3 HmfModelData_Unk64_Unk60_Struct */

/* MP3 HmfData / MP1 unk2C0C0StructC0 (fields used here; MP1 offsets in the comments) */

/* MP1 unk2C0C0Struct10 */
typedef struct HmfLight {
    /* 0x00 */ Hilite unk_00;
    /* 0x10 */ char unk_10[0x30];
    /* 0x40 */ LookAt unk_40;
} HmfLight; /* size = 0x60 */

extern s16 D_800CA028_CAC28;
extern Gfx D_800CA030_CAC30[];
extern s16 D_800CA090_CAC90[];
extern s32 D_800CA098_CAC98[];
extern s16 D_800CAD20_CB920;
extern u32 D_800F60A4_F6CA4;
extern u8 D_800F8C48_F9848;
extern s16 D_800F8C54_F9854;
extern s16 D_800F8D24_F9924;
extern s16 D_800F9050_F9C50;
extern s16 D_800F928C_F9E8C;
extern u32 D_800F92E0_F9EE0;
extern void* D_800F93D8_F9FD8[];
extern u8 D_800F94C0_FA0C0;
extern u32 D_800F956C_FA16C;
extern u8 D_800F9D2C_FA92C;
extern s16 D_800FA1AA_FADAA;
extern u8 D_800FA5D8_FB1D8;
extern u8 D_800FA60C_FB20C;
extern s16 D_800FA61C_FB21C;
extern HmfLight* D_800FA658_FB258;
extern u8 D_800FC9E9_FD5E9;
extern s16 D_800FCE00_FDA00;
extern s16 D_800FD470_FE070;
extern HmfLight D_800FD4F0_FE0F0[];
extern u8 D_800FD800_FE400;
extern Gfx* D_800FD810_FE410[];
extern void* D_800FD83C_FE43C;
extern s32 D_800FD84C_FE44C;
extern s16 D_800FD8BA_FE4BA;
extern u8 D_800FDBCA_FE7CA;
extern Gfx* D_800FDBCC_FE7CC;
extern Gfx* D_800FDBD0_FE7D0;
extern u32 D_800FDBD4_FE7D4;
extern u8 D_800FDBE0_FE7E0;
extern u8 D_800FDC84_FE884;
extern s32 D_800FDC98_FE898;
extern u8 D_800FDEA0_FEAA0;
extern s16 D_800FFDFA_1009FA;
extern u8 D_8010002C_100C2C;
extern s16 D_8010106C_101C6C;
extern HmfVtx* D_80101170_101D70;
extern Matrix4f D_801016D0_1022D0[];
extern u32 D_801026D0_1032D0;
extern s16 D_80102718_103318;
extern s16 D_80102722_103322;
extern HmfVtx* D_80102728_103328[];
extern s16 D_801027FA_1033FA;

extern s16 D_800FDBC8_FE7C8;
extern u16 D_800F60A0_F6CA0;
extern u16 D_8010116E_101D6E;
/* D_800FDC48_FE848's entries (MP1 unk2C0C0StructF0 is larger) */
typedef struct HmfLayerEnt {
    /* 0x00 */ u8 unk00;
    /* 0x01 */ u8 unk01;
    /* 0x02 */ s16 unk02; /* its D_800F8C58_F9858 record */
    /* 0x04 */ f32 unk04; /* depth */
} HmfLayerEnt; /* size = 0x8; a depth-sorted list: unk00 next, unk01 previous */

/* D_800F8C58_F9858's entries (384, 0x8400 bytes): one sorted draw of a model part */
typedef struct HmfDrawRec {
    /* 0x00 */ s16 unk00; /* part */
    /* 0x02 */ char unk02[0x42];
    /* 0x44 */ void* unk44; /* the part's Mtx */
    /* 0x48 */ HmfData* unk48;
    /* 0x4C */ s32 unk4C; /* the part's flags */
    /* 0x50 */ u32 unk50; /* D_800F64C4_F70C4 */
    /* 0x54 */ struct HmfData_UnkD0* unk54;
} HmfDrawRec; /* size = 0x58 */

extern HmfLayerEnt* D_800FDC48_FE848[8]; /* 8 buffers of D_800CA080_CAC80[i] entries */
extern s16 D_80102758_103358[8];
extern s16 D_80101648_102248;
extern u8 D_800CA080_CAC80[8];
extern HmfDrawRec* D_800F8C58_F9858;
extern u8 D_800F842C_F902C;
extern u8 D_800FD2A4_FDEA4;
extern f32 D_80101300_101F00;
extern f32 D_8010105C_101C5C;

void* HuMemAlloc(s32);
void func_800270C0_27CC0(void* (*)(s32), void (*)(void*));
void func_800268D0_274D0(void);
void func_8003CAA0_3D6A0(void);
void func_8003B9D0_3C5D0(void);
extern Gfx* D_8010271C_10331C; /* second display list buffer */
extern u8 D_80101502_102102;
extern u16 D_800F9D38_FA938;
extern u16 D_800FA5B0_FB1B0;
extern u16 D_800FA19A_FAD9A;
extern u16 D_800FD850_FE450;
extern u16 D_800FD8C0_FE4C0;
extern u16 D_800F9D22_FA922;
extern HmfTexRef* D_800F8C4C_F984C; /* texture whose load went to the second list */
extern s16 D_80101646_102246;
extern u32 D_800F64C4_F70C4;
extern void* D_800FC888_FD488;
extern u64 D_800FA720_FB320;
extern u64 D_800FD8A0_FE4A0;
extern Light* D_800F8424_F9024;
/* 274D0's UnkLightData (0x1040 bytes); only its light count is read here */
typedef struct HmfLightSet {
    /* 0x00 */ s16 unk00;
} HmfLightSet;
extern HmfLightSet* D_800FA620_FB220;
/* "Vertex Over!\n" (30560's rodata, D2E30) */

void osSyncPrintf(const char* fmt, ...);
void func_80026C40_27840(void);
void func_8003057C_3117C(HmfData*);
void func_8003076C_3136C(HmfData*);
void func_80030668_31268(HmfData*);
void func_800329E8_335E8(HmfData*, s16);
void func_80038C04_39804(Gfx**, s16, s32);
void func_8003BB58_3C758(HmfData*);
extern f32 D_80101710_102310[4][4];
extern f32 D_80100050_100C50[4][4];
extern s16 D_8010107C_101C7C;
extern u8 D_800F9914_FA514;
/* "Mtx Over\n" (D2E54) */

void func_80025BA4_267A4(Matrix4f, Matrix4f, Matrix4f); /* multiply */
void func_800B3040_B3C40(Matrix4f, void*);           /* guMtxF2L */
s32 func_80038024_38C24(HmfData*, s16, Matrix4f, Matrix4f);
void func_80030D58_31958(HmfData*, s16);
void func_80031170_31D70(HmfData*, s16);
void func_800316F0_322F0(HmfData*, s16);
void func_80039B54_3A754(HmfData*, f32, HmfMotionSlot*, s32);
void func_8003A4B8_3B0B8(HmfData*, f32, f32);
extern Matrix4f D_80100010_100C10[];
extern s16 D_800F64B2_F70B2;
void func_80025770_26370(Matrix4f, f32, f32, f32);   /* translate */
void func_80025830_26430(Matrix4f, f32, f32, f32);   /* scale */
void func_800B1E50_B2A50(Matrix4f, f32, f32, f32);   /* scale matrix */
void func_800B1F50_B2B50(Matrix4f, f32, f32, f32);   /* translation matrix */
/* "GfxMax Over\n" (D2E60), "Model Object Entry Over!! UCODE%d\n" (D2E70) */

#define SQ(x) ((x) * (x))

f32 func_800B1830_B2430(f32); /* sqrtf */
void func_80031FD8_32BD8(HmfData*, s16, void*, Matrix4f);
void func_80036C44_37844(HmfData*, s32, s16);
void func_8003EBC8_3F7C8(HmfData*);
u8 func_8001D054_1DC54(void* arg0, u16 arg1, s32 arg2, void* arg3, s32 arg4);
void func_8002064C_2124C(s16, Gfx**);
void func_8002699C_2759C(s16);
s16 func_8007C058_7CC58(u8, u8, u8);
void func_8007C094_7CC94(s16);
void func_800368B4_374B4(u16);
void func_80036B98_37798(void);
void func_800319EC_325EC(HmfData*, s16, HmfDrawRec*);
void func_80035FBC_36BBC(HmfMat*, HmfTexRef*, s32);
/* "Can't find ObjName %s\n" (D2E94) */
s16 func_8001F4AC_200AC(char*); /* name hash */
s32 func_800B0FD0_B1BD0(char*, char*); /* strcmp */
void func_800B37C0_B43C0(Matrix4f); /* identity */
void func_800386DC_392DC(HmfData*, s16);
void func_80038964_39564(HmfData*, s16);
/* D_801016C4_1022C4's entries (16): texture animations */
typedef struct HmfTexAnimSlot {
    /* 0x00 */ void* unk00;
    /* 0x04 */ u8* unk04; /* the animation data */
    /* 0x08 */ u8* unk08; /* its frames; NULL when the slot is free */
    /* 0x0C */ s16 unk0C;
    /* 0x0E */ s16 unk0E;
} HmfTexAnimSlot; /* size = 0x10 */
extern HmfTexAnimSlot* D_801016C4_1022C4;
void func_8003B7A8_3C3A8(s16, s16, char*, s16, u16, u16);
void func_8003BAD8_3C6D8(s32);
void func_8003BD08_3C908(HmfData*, s16, f32);
void func_8003C6AC_3D2AC(HmfData*, f32);

/* HmfData.unkB8's entries (1D0B0's HmfDispData): a morph target */
typedef struct HmfMorph {
    /* 0x00 */ char unk00[0x1C];
    /* 0x1C */ s16 unk1C; /* vertex count */
    /* 0x1E */ char unk1E[0xA];
    /* 0x28 */ s16* unk28; /* vertices */
    /* 0x2C */ ColVtx* unk2C; /* their positions */
    /* 0x30 */ u8* unk30; /* and colours (3 bytes each; 0, 0, 0 keeps the model's) */
} HmfMorph; /* size = 0x34 */

/* HmfData.unkBC's entries (1D0B0's HmfMtnData): a morph animation */
typedef struct HmfMorphAnim {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02; /* frame count */
    /* 0x04 */ s16* unk04; /* per frame: the HmfMorph */
} HmfMorphAnim; /* size = 0x8 */
/* func_8003BD08_3C908's packed vertex animation: nibbles and bytes read at a half-byte cursor */
#define HMF_RD4(v) \
    if (half == 0) { \
        v = *p >> 4; \
    } else { \
        v = (u8) (*p & 0xF); \
        p++; \
    } \
    half ^= 1
#define HMF_RD8(v) \
    if (half == 0) { \
        v = *p; \
    } else { \
        v = ((*p & 0xF) << 4) | (p[1] >> 4); \
    } \
    p++
#define HMF_S4(v) ((v & 8) ? (s16) v | 0xFFF0 : (s16) v)
#define HMF_S8(v) ((v & 0x80) ? (s16) v | 0xFF00 : (s16) v)
void func_8002024C_20E4C();
void func_800260A4_26CA4(Matrix4f, Matrix4f);
void func_80026994_27594(s32);
void* func_80027154_27D54(s32, s16);
void HuMemFree(void*);
void func_80027340_27F40(void*);
void func_800274A4_280A4(void);
void func_8002FD38_30938(HmfData*);
void func_80030CD4_318D4(Matrix4f, Matrix4f);
void func_80036D5C_3795C(HmfData*, s16);
void func_80037C7C_3887C(HmfData*, s16);
s32 func_8003811C_38D1C(HmfData*, s16, s16);
s16 func_80038398_38F98(HmfData*, char*);
void func_800384C8_390C8(HmfData*, s16, HmfData*);
s16 func_80038E38_39A38(u8*, HmfData*);
void func_800B30D0_B3CD0(Matrix4f, void*);

void func_8002F960_30560(void* (*arg0)(s32), void (*arg1)(void*), u16 arg2, u16 arg3, u16 arg4, u8 arg5) {
    s16 i;

    D_800FDBCA_FE7CA = arg5;
    D_800FDBE0_FE7E0 = 0;
    func_800270C0_27CC0(arg0, arg1);
    D_800FDBC8_FE7C8 = arg2;
    D_800F60A0_F6CA0 = arg4;
    D_8010116E_101D6E = arg3;
    for (i = 0; i < arg5; i++) {
        D_80102728_103328[i] = HuMemAlloc(arg2 * sizeof(HmfVtx));
        D_800F93D8_F9FD8[i] = HuMemAlloc(arg4 * 64);
        D_800FD810_FE410[i] = HuMemAlloc(arg3 * sizeof(Gfx));
    }
    for (i = 0; i < 8; i++) {
        D_800FDC48_FE848[i] = HuMemAlloc(D_800CA080_CAC80[i] * 8);
    }
    D_800F8C58_F9858 = HuMemAlloc(0x8400);
    D_800FA620_FB220 = 0;
    func_800268D0_274D0();
    func_8003CAA0_3D6A0();
    func_8003B9D0_3C5D0();
    D_800F842C_F902C = 1;
    D_800FD2A4_FDEA4 = 2;
    D_80101300_101F00 = 1.0f;
    D_8010105C_101C5C = 1.0f;
    D_800FA60C_FB20C = 0;
    D_800F9D2C_FA92C = 0xFF;
    D_8010002C_100C2C = 0xFF;
    D_800FC9E9_FD5E9 = 0xFF;
    D_801027FA_1033FA = 950;
    D_800F8C54_F9854 = 1000;
    D_800F8C48_F9848 = 1;
}
/* exact c: marioparty func_8002B6C8 (src/2C0C0.c) */
void func_8002FB6C_3076C(void) {
    func_800274A4_280A4();

    if (D_800FDCD0_FE8D0 != 0) {
        s32 temp_v0 = D_800FDBE0_FE7E0;

        D_80101170_101D70 = D_80102728_103328[temp_v0];
        D_800FD83C_FE43C = D_800F93D8_F9FD8[temp_v0];
        D_800FDBD0_FE7D0 = D_800FDBCC_FE7CC = D_800FD810_FE410[temp_v0];
        D_800FA658_FB258 = &D_800FD4F0_FE0F0[temp_v0];

        if (++D_800FDBE0_FE7E0 >= D_800FDBCA_FE7CA) {
            D_800FDBE0_FE7E0 = 0;
        }

        func_80026994_27594(temp_v0);

        D_800FA61C_FB21C = 0;
        D_800F928C_F9E8C = 0;
        D_800FD8BA_FE4BA = 0;
        D_80102722_103322 = 0;
        D_800FA5D8_FB1D8 = 0;
        D_800FCE00_FDA00 = 0;
        D_80102718_103318 = 0;
        D_800F8D24_F9924 = 0;
        D_800FFDFA_1009FA = 0;
        D_800F9050_F9C50 = 0;

        func_8002024C_20E4C();

        D_800FDC98_FE898++;
    }
}

void func_8002FCAC_308AC(void) {
    HmfLayerEnt** p;
    s16 i;

    for (i = 0; i < 8; i++) {
        D_80102758_103358[i] = 2;
        p = &D_800FDC48_FE848[i];
        (*p)->unk00 = 1;
        (*p + 1)->unk01 = 0;
        (*p + 1)->unk00 = 0;
        (*p + 1)->unk04 = 200000.0f;
    }
    D_80101648_102248 = 0;
}
/* the per-part display lists (unk3C as a Gfx* array) */
#define HMF_DL(a) ((Gfx**) (a)->unk3C)

// register allocation only (masked 0): the vertex-buffer size lives in s0, and the end-list pointer in a0
#ifdef NON_MATCHING
void func_8002FD38_30938(HmfData* arg0) {
    s16 savedCount;
    s16 maxLen;
    Gfx* savedDl;
    HmfVtx* savedVtx;
    Gfx* buf2;
    Gfx* var_s4;
    HmfPart* part;
    HmfVtx* vtx;
    s16* map;
    s32 flags;
    s32 size;
    u16 vtxStart;
    s16 i;
    s16 j;

    maxLen = 0;
    if (arg0->unk10 == 0 || arg0->unk14 == 0) {
        return;
    }

    savedDl = D_800FDBCC_FE7CC;
    savedVtx = D_80101170_101D70;
    savedCount = D_800FA61C_FB21C;

    arg0->unk3C = func_80027154_27D54(arg0->unk10 * sizeof(Gfx*), D_800FA1AA_FADAA);
    buf2 = HuMemAlloc(25 * sizeof(Gfx));
    D_80101170_101D70 = HuMemAlloc((arg0->unk1C * 4 + arg0->unk10 * 8) * sizeof(HmfVtx));
    if (arg0->unkB8 != NULL || (D_800F64C4_F70C4 & 0x400000)) {
        if (arg0->unk60 != NULL) {
            HuMemFree(arg0->unk60);
        }
        arg0->unk60 = HuMemAlloc(arg0->unk14 * sizeof(s16));
        arg0->unk26 = 0;
    }
    if (D_80101170_101D70 == NULL) {
        D_80101170_101D70 = arg0->unk40 = (HmfVtx*) 0 + D_800FA61C_FB21C;
    }

    var_s4 = HuMemAlloc(arg0->unk1C * 4 * sizeof(Gfx) + 500 * sizeof(Gfx));
    if (var_s4 == NULL) {
        var_s4 = D_800FDBCC_FE7CC;
    }

    if (arg0->unkCC != NULL) {
        for (i = 0; i < arg0->unk10; i++) {
            if ((*arg0->unkCC)[i] != NULL) {
                func_80027340_27F40((*arg0->unkCC)[i]);
            }
        }
        HuMemFree(*arg0->unkCC);
        HuMemFree(arg0->unkCC);
        arg0->unkCC = NULL;
    }

    func_8003057C_3117C(arg0);
    D_800FA61C_FB21C = 0;
    D_80101646_102246 = 0;
    func_80026C40_27840();
    func_8003076C_3136C(arg0);

    part = arg0->unk64;
    for (i = 0; i < arg0->unk10; i++, part++) {
        D_800FDBCC_FE7CC = var_s4;
        D_8010271C_10331C = buf2;
        D_80101502_102102 = 0;
        vtxStart = D_800FA61C_FB21C;
        D_800F9D38_FA938 = 0;
        D_800FA5B0_FB1B0 = 0;
        D_800FA19A_FAD9A = 0;
        D_800FA720_FB320 = 0xFFFFFFFF;
        D_800FD8A0_FE4A0 = 0xFFFFFFFF;
        D_800FC888_FD488 = NULL;

        func_80038C04_39804(&D_800FDBCC_FE7CC, 1, 0);

        if (D_800F64C4_F70C4 & 0x200) {
            gSPLight(D_800FDBCC_FE7CC++, D_800F8424_F9024, D_800FA620_FB220->unk00 + 1);
            D_800FD850_FE450 = D_800F8424_F9024->l.col[0];
            D_800FD8C0_FE4C0 = D_800F8424_F9024->l.col[1];
            D_800F9D22_FA922 = D_800F8424_F9024->l.col[2];
        }

        flags = part->unk50;
        part->unk0A = D_800FA61C_FB21C;
        part->unk0E = D_80101646_102246;
        part->unk50 &= ~0x06000000;

        func_800329E8_335E8(arg0, i);

        flags &= 0x06000000;
        if (flags != 0) {
            part->unk50 |= flags;
        }

        part->unk0C = D_800FA61C_FB21C - part->unk0A;
        part->unk10 = D_80101646_102246 - part->unk0E;

        gSPEndDisplayList(D_800FDBCC_FE7CC++);
        part->unk60 = D_800FC888_FD488;

        if (D_8010271C_10331C == buf2) {
            HMF_DL(arg0)[i] = func_80027154_27D54(size = (D_800FDBCC_FE7CC - var_s4) * sizeof(Gfx), D_800FA1AA_FADAA);
            bcopy(var_s4, HMF_DL(arg0)[i], size);
            part->unk5C = NULL;
            part->unk64 = NULL;
        } else {
            gSPEndDisplayList(D_8010271C_10331C++);
            part->unk5C = D_800F8C4C_F984C;
            HMF_DL(arg0)[i] = func_80027154_27D54(
                (D_800FDBCC_FE7CC - var_s4 + D_8010271C_10331C - buf2) * sizeof(Gfx), D_800FA1AA_FADAA);
            bcopy(var_s4, HMF_DL(arg0)[i], (D_800FDBCC_FE7CC - var_s4) * sizeof(Gfx));
            part->unk64 = (D_800FDBCC_FE7CC - var_s4) + HMF_DL(arg0)[i];
            bcopy(buf2, part->unk64, (D_8010271C_10331C - buf2) * sizeof(Gfx));
        }

        if (maxLen < D_800FDBCC_FE7CC - var_s4) {
            maxLen = D_800FDBCC_FE7CC - var_s4;
        }

        if (part->unk50 & 0x06000000) {
            if (arg0->unkCC == NULL) {
                arg0->unkCC = func_80027154_27D54(sizeof(Gfx**), D_800FA1AA_FADAA);
                *arg0->unkCC = func_80027154_27D54(arg0->unk10 * sizeof(Gfx*), D_800FA1AA_FADAA);
                for (j = 0; j < arg0->unk10; j++) {
                    (*arg0->unkCC)[j] = NULL;
                }
            }
            D_800FDBCC_FE7CC = var_s4;
            D_800FA61C_FB21C = vtxStart;
            D_800F9D38_FA938 = 0;
            D_800FA5B0_FB1B0 = 0;
            D_800FA19A_FAD9A = 0;
            D_800F9D22_FA922 = 0;
            D_800FD8C0_FE4C0 = 0;
            D_800FD850_FE450 = 0;
            D_800FA720_FB320 = 0xFFFFFFFF;
            D_800FD8A0_FE4A0 = 0xFFFFFFFF;
            D_800FC888_FD488 = NULL;

            func_800329E8_335E8(arg0, i);

            gSPEndDisplayList(D_800FDBCC_FE7CC++);
            (*arg0->unkCC)[i] = func_80027154_27D54((D_800FDBCC_FE7CC - var_s4) * sizeof(Gfx), D_800FA1AA_FADAA);
            bcopy(var_s4, (*arg0->unkCC)[i], (D_800FDBCC_FE7CC - var_s4) * sizeof(Gfx));
        }
    }

    arg0->unk18 = D_800FA61C_FB21C;
    arg0->unk1A = D_80101646_102246;

    vtx = func_80027154_27D54(D_800FA61C_FB21C * sizeof(HmfVtx), D_800FA1AA_FADAA);
    bcopy(D_80101170_101D70, vtx, D_800FA61C_FB21C * sizeof(HmfVtx));
    arg0->unk40 = vtx;

    func_80030668_31268(arg0);

    for (i = 0; i < 4; i++) {
        arg0->unk44[i] = vtx;
    }

    if (arg0->unk60 != NULL) {
        map = func_80027154_27D54(arg0->unk14 * sizeof(s16), D_800FA1AA_FADAA);
        bcopy(arg0->unk60, map, arg0->unk14 * sizeof(s16));
        HuMemFree(arg0->unk60);
        arg0->unk60 = map;
    }

    if (arg0->unkB8 != NULL || (D_800F64C4_F70C4 & 0x400000)) {
        func_8003BB58_3C758(arg0);
    }

    if (arg0->unk1C * 4 + arg0->unk10 * 8 < D_800FA61C_FB21C) {
        osSyncPrintf(D_800D2230_D2E30);
    }

    HuMemFree(D_80101170_101D70);
    HuMemFree(var_s4);
    HuMemFree(buf2);

    D_800FA61C_FB21C = savedCount;
    D_80101170_101D70 = savedVtx;
    D_800FDBCC_FE7CC = savedDl;
}
#else
INCLUDE_ASM("asm/nonmatchings/30560", func_8002FD38_30938);
#endif

void func_8003057C_3117C(HmfData* arg0) {
    u16 var_a2;
    s16 var_a3 = 0;
    s16 i;

    for (i = 0, var_a2 = 0; i < arg0->unk10; i++) {
        if (arg0->unk64[i].unk50 & 0x20000) {
            var_a3 = 1;
        }
        var_a2 += arg0->unk64[i].unk04;
    }

    if (var_a3 && arg0->unkB4 == NULL) {
        arg0->unkB4 = func_80027154_27D54(var_a2 * sizeof(HmfFace), D_800FA1AA_FADAA);
    }
}
/* same c: marioparty func_8002BDC0 (src/2C0C0.c) */
void func_80030668_31268(HmfData* arg0) {
    HmfFace* var_a3;
    f32 var_f4;
    f32 var_f6;
    f32 var_f8;
    s16* var_a1;
    u16 temp_t2;
    s16 i;
    s16 j;

    if (arg0->unkB4 == NULL) {
        return;
    }

    var_a3 = arg0->unkB4;
    for (i = 0; i < arg0->unk1A; i++, var_a3++) {
        var_a1 = var_a3->unk02;
        temp_t2 = var_a3->unk00;

        var_f6 = var_f8 = var_f4 = 0.0f;
        for (j = 0; j < temp_t2; j++, var_a1++) {
            var_f6 += arg0->unk40[*var_a1].unk00;
            var_f8 += arg0->unk40[*var_a1].unk02;
            var_f4 += arg0->unk40[*var_a1].unk04;
        }

        var_a3->unk0C = var_f6 / temp_t2;
        var_a3->unk10 = var_f8 / temp_t2;
        var_a3->unk14 = var_f4 / temp_t2;
    }
}

void osSyncPrintf(const char* fmt, ...);
/* "Texture Anime Over\n": 30560's rodata (D2E30) is not carved while functions using it are asm,
   so C names the string, as MP3's hmfman.c does */

/* MP1 func_8002BEC4 (src/2C0C0.c) */
void func_8003076C_3136C(HmfData* arg0) {
    s16 var_t1 = 4;
    s16 i;
    s16 j;

    for (i = 0; i < arg0->unk12; i++) {
        if (arg0->unk88[i].unk09 == 255) {
            continue;
        }

        for (j = 0; j < i; j++) {
            if (arg0->unk88[i].unk0C == arg0->unk88[j].unk0C) {
                break;
            }
        }

        if (j != i) {
            arg0->unk88[i].unk03 = arg0->unk88[j].unk03;
            arg0->unk88[i].unk04 = arg0->unk88[j].unk04;
            continue;
        }

        arg0->unk88[i].unk03 = var_t1++;
        if (arg0->unk88[i].unk0C->unk30 != NULL) {
            arg0->unk88[i].unk04 = var_t1++;
        }

        if (var_t1 > 16) {
            osSyncPrintf(D_800D2240_D2E40);
            return;
        }
    }
}

/* same c: marioparty3 func_80023264_23E64 (src/22EB0.c) */
s32 func_800308D8_314D8(HmfData *arg0) {
    s32 var_s2;
    s16 i;

    var_s2 = 0;
    if (arg0->unk40 != NULL) {
        for (i = 0; i < ARRAY_COUNT(arg0->unk44); i++) {
            if (arg0->unk40 != arg0->unk44[i]) {
                if (arg0->unk0A != 0) {
                    func_80027340_27F40(arg0->unk44[i]);
                } else {
                    HuMemFree(arg0->unk44[i]);
                }
                arg0->unk44[i] = arg0->unk40;
                var_s2 = 1;
            }
        }

        if (arg0->unk0A != 0) {
            func_80027340_27F40(arg0->unk40);
        } else {
            HuMemFree(arg0->unk40);
        }
    }
    if (arg0->unk3C != NULL) {
        for (i = 0; i < arg0->unk10; i++) {
            if (arg0->unk0A != 0) {
                func_80027340_27F40(arg0->unk3C->unk00[i]);
            } else {
                HuMemFree(arg0->unk3C->unk00[i]);
            }
        }

        if (arg0->unk0A != 0) {
            func_80027340_27F40(arg0->unk3C);
        } else {
            HuMemFree(arg0->unk3C);
        }
    }
    D_8010106C_101C6C = arg0->unk0E;
    D_800FA1AA_FADAA = arg0->unk0E + 1;
    func_8002FD38_30938(arg0);
    return var_s2;
}

void func_80030A78_31678(HmfData* arg0, Matrix4f arg1, Matrix4f arg2) {
    Matrix4f sp10;

    if (arg0->unk14 != 0) {
        func_80030CD4_318D4(D_801016D0_1022D0[0], arg1);
        D_800FD470_FE070 = 1;
        guMtxIdentF(D_80101710_102310);
        D_8010107C_101C7C = 0;
        func_80030CD4_318D4(D_80100050_100C50, arg2);

        if (arg0->unk01 & 4) {
            if (arg0->unk64->unk50 & 0x70000000) {
                func_80038024_38C24(arg0, 0, arg1, sp10);
                func_80025BA4_267A4(arg2, sp10, arg1);
            }
            func_800B3040_B3C40(arg1, (u8*) D_800FD83C_FE43C + 0x40 * D_800F928C_F9E8C);
            func_80031FD8_32BD8(arg0, 0, (u8*) D_800FD83C_FE43C + 0x40 * (D_800F928C_F9E8C++), arg1);
            return;
        }

        if (arg0->unk84 == (void*) -1) {
            if (arg0->unk90 != NULL) {
                func_80039B54_3A754(arg0, arg0->unkA4, arg0->unk90, 1);
                if (arg0->unk94 != NULL) {
                    func_8003A4B8_3B0B8(arg0, arg0->unkA8, arg0->unkAC);
                }
                if (arg0->unk98 != NULL) {
                    func_80039B54_3A754(arg0, arg0->unkB0, arg0->unk98, 0);
                }
            }
            if (arg0->unk68 != 0) {
                func_80030D58_31958(arg0, 0);
                if (D_800F60A0_F6CA0 <= D_800F928C_F9E8C) {
                    osSyncPrintf(D_800D2254_D2E54);
                }
            }
        } else if (arg0->unk16 != 0) {
            if (D_800F9914_FA514 != 0 && arg0->unk0B == 1 && arg0->unk0C != 0) {
                func_800316F0_322F0(arg0, 0);
            } else {
                if (arg0->unk90 != NULL) {
                    func_80039B54_3A754(arg0, arg0->unkA4, arg0->unk90, 1);
                    if (arg0->unk94 != NULL) {
                        func_8003A4B8_3B0B8(arg0, arg0->unkA8, arg0->unkAC);
                    }
                    if (arg0->unk98 != NULL) {
                        func_80039B54_3A754(arg0, arg0->unkB0, arg0->unk98, 0);
                    }
                }
                func_80031170_31D70(arg0, 0);
            }
            if (D_800F60A0_F6CA0 <= D_800F928C_F9E8C) {
                osSyncPrintf(D_800D2254_D2E54);
            }
        }
    }
}
/* exact c: marioparty func_8002C37C (src/2C0C0.c) */
void func_80030CD4_318D4(Matrix4f arg0, Matrix4f arg1) {
    arg0[0][0] = arg1[0][0];
    arg0[0][1] = arg1[0][1];
    arg0[0][2] = arg1[0][2];
    arg0[0][3] = arg1[0][3];
    arg0[1][0] = arg1[1][0];
    arg0[1][1] = arg1[1][1];
    arg0[1][2] = arg1[1][2];
    arg0[1][3] = arg1[1][3];
    arg0[2][0] = arg1[2][0];
    arg0[2][1] = arg1[2][1];
    arg0[2][2] = arg1[2][2];
    arg0[2][3] = arg1[2][3];
    arg0[3][0] = arg1[3][0];
    arg0[3][1] = arg1[3][1];
    arg0[3][2] = arg1[3][2];
    arg0[3][3] = arg1[3][3];
}

extern Matrix4f D_80100010_100C10[];
extern s16 D_8010107C_101C7C;
void func_800B37C0_B43C0(Matrix4f);                  /* identity */
void func_80025770_26370(Matrix4f, f32, f32, f32);   /* translate */
void func_80025830_26430(Matrix4f, f32, f32, f32);   /* scale */
void func_80025BA4_267A4(Matrix4f, Matrix4f, Matrix4f); /* multiply */
void func_800B3040_B3C40(Matrix4f, void*);           /* guMtxF2L */
s32 func_80038024_38C24(HmfData*, s16, Matrix4f, Matrix4f);
void func_80030D58_31958(HmfData* arg0, s16 arg1);

/* MP1 func_8002C400 (src/2C0C0.c): draw a model's transform tree. The matrix stacks are
   D_801016D0_1022D0 (MP1 D_800F54C0, whose element -1 is MP1's D_800F5480) and
   D_80100010_100C10 (MP1 D_800F3FE0). */
void func_80030D58_31958(HmfData* arg0, s16 arg1) {
    HitXform* temp_s1;
    s16 var_s3;
    s16 var_s5;
    s16 temp_s4;
    Matrix4f sp10;
    Matrix4f sp50;

    temp_s1 = &arg0->unk6C[arg1];
    temp_s4 = temp_s1->unk00;
    var_s5 = 0;
    var_s3 = 0;

    if (arg0->unk90 == 0) {
        func_80025BA4_267A4(temp_s1->unk4C, D_801016D0_1022D0[0], sp10);
    } else {
        func_800B37C0_B43C0(sp10);
        if (temp_s1->unk2C.x != 0.0f || temp_s1->unk2C.y != 0.0f || temp_s1->unk2C.z != 0.0f) {
            func_80025770_26370(sp10, temp_s1->unk2C.x, temp_s1->unk2C.y, temp_s1->unk2C.z);
            var_s3 = 1;
        }
        if (temp_s1->unk38.x != 0.0f || temp_s1->unk38.y != 0.0f || temp_s1->unk38.z != 0.0f) {
            arg0->unkD4(sp10, temp_s1->unk38.x, temp_s1->unk38.y, temp_s1->unk38.z);
            var_s3 = 1;
        }
        if (temp_s1->unk20.x != 1.0f || temp_s1->unk20.y != 1.0f || temp_s1->unk20.z != 1.0f) {
            func_80025830_26430(sp10, temp_s1->unk20.x, temp_s1->unk20.y, temp_s1->unk20.z);
            func_800B37C0_B43C0(sp50);
            func_80025830_26430(sp50, temp_s1->unk20.x, temp_s1->unk20.y, temp_s1->unk20.z);
            D_8010107C_101C7C++;
            func_80025BA4_267A4(sp50, D_80100010_100C10[D_8010107C_101C7C], D_80100010_100C10[D_8010107C_101C7C + 1]);
            var_s5 = 1;
            var_s3 = 1;
        }
        if (var_s3 != 0) {
            D_800FD470_FE070++;
            func_80025BA4_267A4(sp10, D_801016D0_1022D0[D_800FD470_FE070 - 1], D_801016D0_1022D0[D_800FD470_FE070]);
        }
        func_80025BA4_267A4(D_801016D0_1022D0[D_800FD470_FE070], D_801016D0_1022D0[0], sp10);
    }

    if (temp_s4 >= 0) {
        if (temp_s1->unk48->unk64[temp_s4].unk50 & 0x70000000) {
            func_80038024_38C24(temp_s1->unk48, temp_s4, sp10, sp50);
            func_80025BA4_267A4(D_80100010_100C10[D_8010107C_101C7C + 1], sp50, sp10);
        }

        func_800B3040_B3C40(sp10, (u8*) D_800FD83C_FE43C + 0x40 * D_800F928C_F9E8C);
        func_80031FD8_32BD8(temp_s1->unk48, temp_s4, (u8*) D_800FD83C_FE43C + 0x40 * D_800F928C_F9E8C, sp10);
        D_800F928C_F9E8C++;
    }

    if (temp_s1->unk04 != 0) {
        func_80030D58_31958(arg0, arg1 + temp_s1->unk04);
    }

    if (var_s3 != 0) {
        D_800FD470_FE070--;
    }

    if (var_s5 != 0) {
        D_8010107C_101C7C--;
    }

    if (temp_s4 >= 0 && temp_s1->unk48 == arg0) {
        if (arg0->unk64[temp_s4].unk58 != 0) {
            func_80030D58_31958(arg0->unk64[temp_s4].unk58, 0);
        }
    }

    if (temp_s1->unk02 != 0) {
        func_80030D58_31958(arg0, arg1 + temp_s1->unk02);
    }
}

void func_80031170_31D70(HmfData* arg0, s16 arg1) {
    HmfMotionObj* temp_s1;
    s16* list;
    s16 count;
    s16 temp_v1;
    s16 var_s4;
    s16 var_s7;
    s16 var_s3;
    Matrix4f sp10;
    Matrix4f sp50;
    s16 i;

    temp_s1 = &arg0->unk84[arg1 & 0x7FFF];
    var_s7 = 0;
    var_s4 = 0;

    if (arg0->unk90 == NULL) {
        func_80025BA4_267A4(temp_s1->unk58, D_801016D0_1022D0[0], sp10);
        if (temp_s1->unk1C.x != 1.0f || temp_s1->unk1C.y != 1.0f || temp_s1->unk1C.z != 1.0f) {
            func_800B1E50_B2A50(sp50, temp_s1->unk1C.x, temp_s1->unk1C.y, temp_s1->unk1C.z);
            D_8010107C_101C7C++;
            func_80025BA4_267A4(sp50, D_80100010_100C10[D_8010107C_101C7C], D_80100010_100C10[D_8010107C_101C7C + 1]);
            var_s7 = 1;
        }
    } else {
        if (temp_s1->unk28.x != 0.0f || temp_s1->unk28.y != 0.0f || temp_s1->unk28.z != 0.0f) {
            func_800B1F50_B2B50(sp10, temp_s1->unk28.x, temp_s1->unk28.y, temp_s1->unk28.z);
            var_s4 = 1;
        }
        if (temp_s1->unk34.x != 0.0f || temp_s1->unk34.y != 0.0f || temp_s1->unk34.z != 0.0f) {
            if (var_s4 == 0) {
                arg0->unkD8(sp10, temp_s1->unk34.x, temp_s1->unk34.y, temp_s1->unk34.z);
            } else {
                arg0->unkD4(sp10, temp_s1->unk34.x, temp_s1->unk34.y, temp_s1->unk34.z);
            }
            var_s4 = 1;
        }
        if (temp_s1->unk40.x != 1.0f || temp_s1->unk40.y != 1.0f || temp_s1->unk40.z != 1.0f) {
            if (var_s4 != 0) {
                func_80025830_26430(sp10, temp_s1->unk40.x, temp_s1->unk40.y, temp_s1->unk40.z);
            } else {
                func_800B1E50_B2A50(sp10, temp_s1->unk40.x, temp_s1->unk40.y, temp_s1->unk40.z);
            }
            func_800B1E50_B2A50(sp50, temp_s1->unk40.x, temp_s1->unk40.y, temp_s1->unk40.z);
            D_8010107C_101C7C++;
            func_80025BA4_267A4(sp50, D_80100010_100C10[D_8010107C_101C7C], D_80100010_100C10[D_8010107C_101C7C + 1]);
            var_s7 = 1;
            var_s4 = 1;
        }
        if (var_s4 != 0) {
            D_800FD470_FE070++;
            func_80025BA4_267A4(sp10, D_801016D0_1022D0[D_800FD470_FE070 - 1], D_801016D0_1022D0[D_800FD470_FE070]);
        }
        if (D_800F64B2_F70B2 != 1 && arg0->unk0B == 1) {
            func_80030CD4_318D4(temp_s1->unk58, D_801016D0_1022D0[D_800FD470_FE070]);
        }
        func_80025BA4_267A4(D_801016D0_1022D0[D_800FD470_FE070], D_801016D0_1022D0[0], sp10);
    }

    func_800B3040_B3C40(sp10, (u8*) D_800FD83C_FE43C + 0x40 * D_800F928C_F9E8C);
    var_s3 = D_800F928C_F9E8C++;

    list = temp_s1->unk50;
    count = temp_s1->unk00;
    for (i = 0; i < count; i++) {
        temp_v1 = *list++;
        if (temp_v1 & 0x8000) {
            if (temp_v1 != -1) {
                func_80031170_31D70(arg0, temp_v1 & 0x7FFF);
            }
        } else {
            if (temp_s1->unk54->unk64[temp_v1].unk50 & 0x70000000) {
                func_80038024_38C24(temp_s1->unk54, temp_v1, sp10, sp50);
                func_80025BA4_267A4(D_80100010_100C10[D_8010107C_101C7C + 1], sp50, sp10);
                func_800B3040_B3C40(sp10, (u8*) D_800FD83C_FE43C + 0x40 * D_800F928C_F9E8C);
                var_s3 = D_800F928C_F9E8C++;
            }
            func_80031FD8_32BD8(temp_s1->unk54, temp_v1, (u8*) D_800FD83C_FE43C + 0x40 * var_s3, sp10);
            if (arg0->unk64[temp_v1].unk58 != NULL) {
                if (arg0 == temp_s1->unk54) {
                    func_80031170_31D70(arg0->unk64[temp_v1].unk58, 0);
                }
            }
        }
    }

    if (var_s4 != 0) {
        D_800FD470_FE070--;
    }

    if (var_s7 != 0) {
        D_8010107C_101C7C--;
    }
}
void func_800316F0_322F0(HmfData* arg0, s16 arg1) {
    HmfMotionObj* temp_s1;
    s16* list;
    s16 count;
    s16 temp_v1;
    s16 var_s7;
    s16 var_s3;
    Matrix4f sp10;
    Matrix4f sp50;
    s16 i;

    temp_s1 = &arg0->unk84[arg1 & 0x7FFF];
    var_s7 = 0;

    func_80025BA4_267A4(temp_s1->unk58, D_801016D0_1022D0[0], sp10);
    if (temp_s1->unk1C.x != 1.0f || temp_s1->unk1C.y != 1.0f || temp_s1->unk1C.z != 1.0f) {
        func_800B1E50_B2A50(sp50, temp_s1->unk1C.x, temp_s1->unk1C.y, temp_s1->unk1C.z);
        D_8010107C_101C7C++;
        func_80025BA4_267A4(sp50, D_80100010_100C10[D_8010107C_101C7C], D_80100010_100C10[D_8010107C_101C7C + 1]);
        var_s7 = 1;
    }

    func_800B3040_B3C40(sp10, (u8*) D_800FD83C_FE43C + 0x40 * D_800F928C_F9E8C);
    var_s3 = D_800F928C_F9E8C++;

    list = temp_s1->unk50;
    count = temp_s1->unk00;
    for (i = 0; i < count; i++) {
        temp_v1 = *list++;
        if (temp_v1 & 0x8000) {
            if (temp_v1 != -1) {
                func_800316F0_322F0(arg0, temp_v1 & 0x7FFF);
            }
        } else {
            if (temp_s1->unk54->unk64[temp_v1].unk50 & 0x70000000) {
                func_80038024_38C24(temp_s1->unk54, temp_v1, sp10, sp50);
                func_80025BA4_267A4(D_80100010_100C10[D_8010107C_101C7C + 1], sp50, sp10);
                func_800B3040_B3C40(sp10, (u8*) D_800FD83C_FE43C + 0x40 * D_800F928C_F9E8C);
                var_s3 = D_800F928C_F9E8C++;
            }
            func_80031FD8_32BD8(temp_s1->unk54, temp_v1, (u8*) D_800FD83C_FE43C + 0x40 * var_s3, sp10);
            if (arg0->unk64[temp_v1].unk58 != NULL) {
                if (arg0 == temp_s1->unk54) {
                    func_800316F0_322F0(arg0->unk64[temp_v1].unk58, 0);
                }
            }
        }
    }

    if (var_s7 != 0) {
        D_8010107C_101C7C--;
    }
}
void func_800319EC_325EC(HmfData* arg0, s16 arg1, HmfDrawRec* arg2) {
    HmfPart* temp_s4;
    s32 temp_v1;

    temp_v1 = arg0->unk64[arg1].unk50;
    if (temp_v1 & 0x06000000) {
        if (D_800F64C4_F70C4 == 0) {
            arg0->unk64[arg1].unk50 = temp_v1 & ~0x06000000;

            gSPSegment(D_800FDBCC_FE7CC++, 0x01, osVirtualToPhysical(D_80101170_101D70));

            func_800319EC_325EC(arg0, arg1, arg2);

            arg0->unk64[arg1].unk50 = temp_v1;
        } else {
            temp_s4 = &arg0->unk64[arg1];
            func_80036C44_37844(arg0, temp_s4->unk50 & ~0x06000000, arg1);

            gSPSegment(D_800FDBCC_FE7CC++, 0x01, osVirtualToPhysical(arg0->unk44[D_800FDBE0_FE7E0]));
            if (temp_s4->unk5C != NULL) {
                if ((D_800FC888_FD488 != temp_s4->unk5C && temp_s4->unk5C != (HmfTexRef*) -1) || arg0->unk38 != NULL) {
                    gSPDisplayList(D_800FDBCC_FE7CC++, temp_s4->unk64);
                }
                D_800FC888_FD488 = temp_s4->unk60;
            } else {
                D_800FC888_FD488 = NULL;
            }
            gSPDisplayList(D_800FDBCC_FE7CC++, HMF_DL(arg0)[arg1]);

            func_80036C44_37844(arg0, temp_s4->unk50, arg1);

            gSPMatrix(D_800FDBCC_FE7CC++, osVirtualToPhysical(arg2->unk44), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(D_800FDBCC_FE7CC++, (*arg0->unkCC)[arg1]);
            return;
        }
    }

    temp_s4 = &arg0->unk64[arg1];

    func_80036C44_37844(arg0, temp_s4->unk50, arg1);

    if (temp_s4->unk50 & 0x40000) {
        func_8003EBC8_3F7C8(arg0);
    }

    if (temp_s4->unk02 != -1 || (arg0->unk9C != NULL && arg0->unk8C[temp_s4->unk00].unk0C & 4)) {
        HmfMat* temp_a0 = &arg0->unk8C[temp_s4->unk00];
        gDPSetPrimColor(D_800FDBCC_FE7CC++, 0, 0, temp_a0->unk05[0], temp_a0->unk05[1], temp_a0->unk05[2], temp_s4->unk02);
    }

    if (D_800F64C4_F70C4 & 0x10000) {
        gDPSetEnvColor(D_800FDBCC_FE7CC++, arg0->unk06, arg0->unk07, arg0->unk08, arg0->unk09);
        gDPSetPrimColor(D_800FDBCC_FE7CC++, 0, 0, arg0->unk02, arg0->unk03, arg0->unk04, arg0->unk05);
    }

    if (D_800F64C4_F70C4 & 1) {
        if (HMF_DL(arg0)[arg1] == NULL) {
            return;
        }
        if (temp_s4->unk5C != NULL) {
            if ((D_800FC888_FD488 != temp_s4->unk5C && temp_s4->unk5C != (HmfTexRef*) -1) || arg0->unk38 != NULL) {
                gSPDisplayList(D_800FDBCC_FE7CC++, temp_s4->unk64);
            }
            D_800FC888_FD488 = temp_s4->unk60;
        } else {
            D_800FC888_FD488 = NULL;
        }
        gSPSegment(D_800FDBCC_FE7CC++, 0x01, osVirtualToPhysical(arg0->unk44[D_800FDBE0_FE7E0]));
        gSPDisplayList(D_800FDBCC_FE7CC++, HMF_DL(arg0)[arg1]);
    } else {
        gSPSegment(D_800FDBCC_FE7CC++, 0x01, osVirtualToPhysical(D_80101170_101D70));
        func_800329E8_335E8(arg0, arg1);
    }

    if (D_800FDBCC_FE7CC >= &D_800FDBD0_FE7D0[D_8010116E_101D6E * 8]) {
        osSyncPrintf(D_800D2260_D2E60);
    }
}
/* exact c: marioparty func_8002D270 (src/2C0C0.c) */
void func_80031F7C_32B7C(HmfData* arg0, s16 arg1, void* arg2) {
    Matrix4f sp10;

    func_800B30D0_B3CD0(sp10, arg2);
    func_80031FD8_32BD8(arg0, arg1, arg2, sp10);
}

void func_80031FD8_32BD8(HmfData* arg0, s16 arg1, void* arg2, Matrix4f arg3) {
    f32 temp_f4;
    f32 temp_f0;
    f32 temp_f2;
    f32 var_f12;
    u32 temp_v1;
    s16 temp_v0;
    s16 var_a1;
    s16 temp_s4;
    HmfLayerEnt* temp_a0;
    HmfLayerEnt* temp_s0;
    HmfDrawRec* rec;

    temp_s4 = arg0->unk00;
    temp_v0 = D_80102758_103358[temp_s4];

    if (temp_v0 >= D_800CA080_CAC80[temp_s4]) {
        osSyncPrintf(D_800D2270_D2E70, temp_s4);
        return;
    }

    temp_s0 = D_800FDC48_FE848[temp_s4];

    if (arg0->unk64[arg1].unk50 & 0x81210000) {
        temp_f4 = arg3[3][0];
        temp_f0 = arg3[3][1];
        temp_f2 = arg3[3][2];

        var_f12 = SQ(temp_f4) + SQ(temp_f0) + SQ(temp_f2);
        if (var_f12 != 0.0f) {
            var_f12 = func_800B1830_B2430(var_f12);
        } else {
            var_f12 = 0.0f;
        }

        temp_v1 = arg0->unk64[arg1].unk50;
        if (temp_v1 & 0x80010000) {
            var_f12 = 100000.0f - var_f12;
        } else if (!(temp_v1 & 0x01000000)) {
            var_f12 = -var_f12;
        }

        for (var_a1 = temp_s0->unk00; temp_s0[var_a1].unk00 != 0; var_a1 = temp_s0[var_a1].unk00) {
            if (var_f12 < temp_s0[var_a1].unk04) {
                break;
            }
        }
    } else {
        var_a1 = temp_s0->unk00;
        var_f12 = 0.0f;
    }

    arg0->unk64[arg1].unk2F = temp_v0;
    var_a1 = temp_s0[var_a1].unk01;

    temp_a0 = &temp_s0[temp_v0];
    temp_a0->unk01 = var_a1;
    temp_a0->unk00 = temp_s0[var_a1].unk00;

    temp_s0[var_a1].unk00 = temp_v0;
    temp_s0[temp_a0->unk00].unk01 = temp_v0;

    D_80102758_103358[temp_s4]++;

    temp_a0->unk04 = var_f12;
    rec = &D_800F8C58_F9858[D_80101648_102248];
    temp_a0->unk02 = D_80101648_102248++;
    rec->unk44 = arg2;
    rec->unk48 = arg0;
    rec->unk00 = arg1;
    rec->unk50 = D_800F64C4_F70C4;
    rec->unk4C = arg0->unk64[arg1].unk50;
    rec->unk54 = arg0->unkD0;
}
/* MP1 func_8002D614 (src/2C0C0.c): draw the depth-sorted part lists. Register allocation and
   loop-invariant choice differ (retail hoists &D_80102758[i] and &D_800FDC48[i], keeps the light
   colours as bytes; masked 116) */
#ifdef NON_MATCHING
Gfx* func_800322BC_32EBC(u16 arg0, Gfx* arg1, Gfx* arg2) {
    s16 sp36;
    u8 sp3F;
    u8 sp47;
    u8 sp4F;
    Gfx* var_s7;
    s32 var_fp;
    s16 sp2E;
    HmfDrawRec* temp_s1;
    HmfData* temp_s2;
    HmfLayerEnt* var_s3;
    s16 var_s4;
    s16 i;
    s16 j;
    s16 k;

    sp2E = func_8007C058_7CC58(0, 0, 230);
    var_s7 = D_800FDBCC_FE7CC;

    if (arg2 != NULL) {
        gSPDisplayList(D_800FDBCC_FE7CC++, arg2);
    }

    var_fp = (D_800FA5D8_FB1D8 != 0);

    func_8002699C_2759C(arg0);

    sp3F = D_800F8424_F9024->l.col[0];
    sp47 = D_800F8424_F9024->l.col[1];
    sp4F = D_800F8424_F9024->l.col[2];

    for (i = 0, sp36 = 0; i < 8; i++) {
        if (D_80102758_103358[i] == 2) {
            continue;
        }

        if (var_fp != 0) {
            gDPFullSync(D_800FDBCC_FE7CC++);
            gSPEndDisplayList(D_800FDBCC_FE7CC++);
            func_8001D054_1DC54(var_s7, D_800FA5D8_FB1D8, 0, NULL, 0);
            var_s7 = D_800FDBCC_FE7CC;
        }

        func_8002064C_2124C(arg0, &D_800FDBCC_FE7CC);

        sp36++;
        var_fp = 1;
        D_800FA5D8_FB1D8 = i;

        gSPDisplayList(D_800FDBCC_FE7CC++, arg1);

        D_800FA720_FB320 = 0xFFFFFFFF;
        D_800FD8A0_FE4A0 = 0xFFFFFFFF;
        D_800FD84C_FE44C = 0xFFFFFFFF;
        D_800FC888_FD488 = NULL;

        gSPNumLights(D_800FDBCC_FE7CC++, D_800FA620_FB220->unk00);

        for (j = 1; j < D_800FA620_FB220->unk00 + 1; j++) {
            gSPLight(D_800FDBCC_FE7CC++, D_800F8424_F9024 + j, j);
        }

        gSPLight(D_800FDBCC_FE7CC++, D_800F8424_F9024, D_800FA620_FB220->unk00 + 1);

        D_800F94C0_FA0C0 = 255;
        D_800FDEA0_FEAA0 = 255;
        D_800FD800_FE400 = 255;
        var_s4 = -1;

        func_80036B98_37798();

        var_s3 = &D_800FDC48_FE848[i][D_800FDC48_FE848[i]->unk00];
        for (k = 2; k < D_80102758_103358[i]; k++) {
            temp_s1 = &D_800F8C58_F9858[var_s3->unk02];
            temp_s2 = temp_s1->unk48;

            D_800FD850_FE450 = sp3F;
            D_800FD8C0_FE4C0 = sp47;
            D_800F9D22_FA922 = sp4F;
            D_800F9D38_FA938 = 0;
            D_800FA5B0_FB1B0 = 0;
            D_800FA19A_FAD9A = 0;

            func_80038C04_39804(&D_800FDBCC_FE7CC, D_800FA620_FB220->unk00 + 1,
                (D_800FD850_FE450 << 0x18) + (D_800FD8C0_FE4C0 << 0x10) + (D_800F9D22_FA922 << 8));
            func_80038C04_39804(&D_800FDBCC_FE7CC, 1, 0);

            if (temp_s1->unk54 != NULL) {
                gSPLight(D_800FDBCC_FE7CC++, &temp_s2->unkD0->unk08[D_800FDBE0_FE7E0], 2);
            }

            if (var_s4 != temp_s1->unk4C) {
                var_s4 = temp_s1->unk4C;
                func_800368B4_374B4(var_s4);
            }

            gSPMatrix(D_800FDBCC_FE7CC++, osVirtualToPhysical(temp_s1->unk44), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

            D_800F64C4_F70C4 = temp_s1->unk50;
            func_800319EC_325EC(temp_s2, temp_s1->unk00, temp_s1);

            if (temp_s1->unk54 != NULL) {
                gSPLight(D_800FDBCC_FE7CC++, &D_800F8424_F9024[2], 2);
            }

            var_s3 = &D_800FDC48_FE848[i][var_s3->unk00];
            if (var_s3->unk00 == 0) {
                break;
            }
        }
    }

    if (sp36 == 0) {
        gSPDisplayList(D_800FDBCC_FE7CC++, arg1);
        gSPNumLights(D_800FDBCC_FE7CC++, D_800FA620_FB220->unk00);

        for (j = 1; j < D_800FA620_FB220->unk00 + 1; j++) {
            gSPLight(D_800FDBCC_FE7CC++, D_800F8424_F9024 + j, j);
        }

        gSPLight(D_800FDBCC_FE7CC++, D_800F8424_F9024, D_800FA620_FB220->unk00 + 1);
    }

    func_8007C094_7CC94(sp2E);

    return var_s7;
}
#else
INCLUDE_ASM("asm/nonmatchings/30560", func_800322BC_32EBC);
#endif

/* A batch of faces drawn with one material and texture (MP1 unk2C0C0StructD0) */
typedef struct HmfDrawFace {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02[4];
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ char unk0B;
    /* 0x0C */ HmfMat* unk0C;
    /* 0x10 */ HmfTexRef* unk10;
} HmfDrawFace; /* size 0x14 */


extern HmfPart* D_800DEFB0_DFBB0;
extern s32 D_800DEFB4_DFBB4;
extern s16 D_800FCE92_FDA92;
extern s16 D_800FA1A6_FADA6;
extern u8 D_800CA088_CAC88[];
extern HmfDrawFace D_800F9918_FA518[];
extern s16 D_80101646_102246;
extern u32 D_800F64C4_F70C4;
void func_80033288_33E88(HmfData*, s32*);
void func_80035C18_36818(HmfData*, s16);

/* MP1 func_8002DC84 (src/2C0C0.c): batch a part's faces and their vertices. MP2 limits a batch's
   vertices by a per-mode table, keeps a vertex slot table (unk60) and records the faces (unkB4)
   only for parts with flag 0x20000 and no 0x06000000. Register allocation and stack slots
   differ (the record flag and sp1E are allocated differently); otherwise the same code. */
#ifdef NON_MATCHING
void func_800329E8_335E8(HmfData* arg0, s16 arg1) {
    s16 temp_v0_2;
    s16 var_s4;
    s16 var_s6;
    s16 var_t1;
    s16 temp_f2;
    s16 temp_f2_2;
    s16 var_a1;
    s16 var_a2;
    s16 var_a1_2;
    s32 temp_v0;
    s32 record;
    s16 sp16;
    u16 sp1E;
    HmfMat* sp24;
    HmfTexRef* sp2C;
    u8* var_a3;
    HmfFaceRec* temp_s1;
    HmfTexRef* var_s0;
    HmfMat* temp_s2;
    HmfDrawFace* temp_t2;
    HmfVtx* var_a0;
    ColVtx* temp_t0;
    s16 i;

    D_800DEFB0_DFBB0 = &arg0->unk64[arg1];
    sp16 = D_800DEFB0_DFBB0->unk04;
    D_800FCE92_FDA92 = 0;
    D_800DEFB4_DFBB4 = -1;
    D_800FA1A6_FADA6 = D_800FA61C_FB21C;
    temp_s1 = D_800DEFB0_DFBB0->unk54;
    sp24 = &arg0->unk8C[temp_s1->unk30];
    temp_v0 = D_800DEFB0_DFBB0->unk50 &= ~0x00040000;
    record = (temp_v0 & 0x06020000) == 0x20000;

    if ((D_800F64C4_F70C4 & 0x2001) == 0x2001) {
        func_80035C18_36818(arg0, arg1);
    }

    var_s6 = var_s4 = temp_s1->unk00 & 0x80;
    if (var_s4 != 0) {
        gSPClearGeometryMode(D_800FDBCC_FE7CC++, G_LIGHTING);
    } else {
        gSPSetGeometryMode(D_800FDBCC_FE7CC++, G_LIGHTING);
    }

    if (temp_s1->unk32 >= 0) {
        sp2C = &arg0->unk88[temp_s1->unk32];
    } else {
        sp2C = (HmfTexRef*) -1;
    }
    sp1E = D_800CA088_CAC88[(D_800F64C4_F70C4 & 0x1C00) >> 10];

    for (i = 0; i < sp16; i++) {
        temp_s1 = &arg0->unk64[arg1].unk54[i];
        if (temp_s1->unk00 >= 3) {
            temp_s2 = &arg0->unk8C[temp_s1->unk30];

            if (temp_s1->unk32 >= 0) {
                var_s0 = &arg0->unk88[temp_s1->unk32];
            } else {
                var_s0 = (HmfTexRef*) -1;
            }

            var_s4 = temp_s1->unk00 & 0x80;

            if (sp1E < D_800FA61C_FB21C - D_800FA1A6_FADA6 || sp24 != temp_s2 || sp2C != var_s0 || D_800FCE92_FDA92 >= 48 || var_s4 != var_s6) {
                sp24 = temp_s2;
                sp2C = var_s0;
                func_80033288_33E88(arg0, &D_800DEFB0_DFBB0->unk50);
                if (var_s4 != var_s6) {
                    if (var_s4 != 0) {
                        gSPClearGeometryMode(D_800FDBCC_FE7CC++, G_LIGHTING);
                    } else {
                        gSPSetGeometryMode(D_800FDBCC_FE7CC++, G_LIGHTING);
                    }
                    var_s6 = var_s4;
                }
                D_800FCE92_FDA92 = 0;
            }

            temp_t2 = &D_800F9918_FA518[D_800FCE92_FDA92];
            temp_v0_2 = temp_t2->unk00 = temp_s1->unk00 & 0x7F;

            if (temp_v0_2 == 2) {
                continue;
            }

            temp_t2->unk0C = temp_s2;
            temp_t2->unk10 = var_s0;

            if (var_s0 != (HmfTexRef*) -1) {
                var_a1 = var_s0->unk0C->unk1E << 5;
                var_a2 = var_s0->unk0C->unk1F << 5;
            } else {
                var_a1 = var_a2 = 0;
            }

            if (record) {
                arg0->unkB4[D_80101646_102246].unk00 = temp_v0_2;
            }

            for (var_t1 = 0; var_t1 < temp_v0_2; var_t1++) {
                temp_t0 = &arg0->unk54[temp_s1->unk04[var_t1]];

                if (var_s4 != 0) {
                    var_a3 = arg0->unk8C[temp_s1->unk2C[var_t1]].unk05;
                } else {
                    var_a3 = &arg0->unk58[temp_s1->unk04[var_t1] * 3];
                }

                temp_f2 = temp_s1->unk0C[var_t1] * var_a1;
                temp_f2_2 = temp_s1->unk1C[var_t1] * var_a2;

                var_a0 = &D_80101170_101D70[D_800FA61C_FB21C - 1];
                if (temp_v0 & 0x20000) {
                    if (record) {
                        arg0->unkB4[D_80101646_102246].unk02[var_t1] = D_800FA61C_FB21C;
                    }
                    var_a1_2 = D_800FA1A6_FADA6;
                } else {
                    for (var_a1_2 = D_800FA61C_FB21C - 1; var_a1_2 >= D_800FA1A6_FADA6; var_a1_2--, var_a0--) {
                        if (var_a0->unk00 == temp_t0->x && var_a0->unk02 == temp_t0->y && var_a0->unk04 == temp_t0->z
                            && (s8) var_a0->unk0C[0] == (s8) var_a3[0] && (s8) var_a0->unk0C[1] == (s8) var_a3[1] && (s8) var_a0->unk0C[2] == (s8) var_a3[2]
                            && var_a0->unk08 == temp_f2 && var_a0->unk0A == temp_f2_2) {
                            break;
                        }
                    }
                }

                if (var_a1_2 <= D_800FA1A6_FADA6) {
                    var_a0 = &D_80101170_101D70[D_800FA61C_FB21C];
                    var_a0->unk00 = temp_t0->x;
                    var_a0->unk02 = temp_t0->y;
                    var_a0->unk04 = temp_t0->z;
                    var_a0->unk0C[0] = var_a3[0];
                    var_a0->unk0C[1] = var_a3[1];
                    var_a0->unk0C[2] = var_a3[2];
                    var_a0->unk08 = temp_f2;
                    var_a0->unk0A = temp_f2_2;
                    var_a0->unk0F = 255;
                    temp_t2->unk02[var_t1] = D_800FA61C_FB21C - D_800FA1A6_FADA6;
                    temp_t2->unk0A = var_s4;
                    if (arg0->unk60 != NULL) {
                        arg0->unk60[temp_s1->unk04[var_t1]] = D_800FA61C_FB21C;
                    }
                    D_800FA61C_FB21C++;
                    D_800FFDFA_1009FA++;
                } else {
                    D_800F9050_F9C50++;
                    temp_t2->unk02[var_t1] = var_a1_2 - D_800FA1A6_FADA6;
                    if (arg0->unk60 != NULL) {
                        arg0->unk60[temp_s1->unk04[var_t1]] = var_a1_2;
                    }
                }
            }

            if (record) {
                D_80101646_102246++;
            }

            D_800FCE92_FDA92++;
        }
    }

    if (D_800FA61C_FB21C != D_800FA1A6_FADA6) {
        if (var_s4 != var_s6) {
            if (var_s4 != 0) {
                gSPClearGeometryMode(D_800FDBCC_FE7CC++, G_LIGHTING);
            } else {
                gSPSetGeometryMode(D_800FDBCC_FE7CC++, G_LIGHTING);
            }
        }

        func_80033288_33E88(arg0, &D_800DEFB0_DFBB0->unk50);
        gSPSetGeometryMode(D_800FDBCC_FE7CC++, G_LIGHTING);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/30560", func_800329E8_335E8);
#endif

void func_80033288_33E88(HmfData* arg0, s32* arg1) {
    HmfDrawFace* temp_a1;
    HmfTex* temp_a3;
    HmfMat* temp_s3;
    HmfTexRef* temp_s4;
    Gfx** dlp;
    u16 var_s0;
    u16 var_s1;
    u16 var_s2;
    u8* var_t0;
    u16* var_a0;
    s16 i;

    if (D_800FCE92_FDA92 == 0) {
        return;
    }

    /* D_800F9924_FA524 is D_800F9918_FA518[0].unk0C/unk10 under a second name */
    temp_s3 = D_800F9918_FA518[0].unk0C;
    temp_s4 = D_800F9918_FA518[0].unk10;

    if (!(*arg1 & 0x06000000)) {
        func_80035FBC_36BBC(temp_s3, temp_s4, *arg1);
        var_s0 = 0;
        var_s1 = 0;
        var_s2 = 0;

        if (temp_s4 == (HmfTexRef*) -1) {
            if (D_800F64C4_F70C4 & 0x200) {
                var_s2 = temp_s3->unk01[0] * D_80101300_101F00;
                if (var_s2 > 255) {
                    var_s2 = 255;
                }
                var_s1 = temp_s3->unk01[1] * D_80101300_101F00;
                if (var_s1 > 255) {
                    var_s1 = 255;
                }
                var_s0 = temp_s3->unk01[2] * D_80101300_101F00;
                if (var_s0 > 255) {
                    var_s0 = 255;
                }

                if (D_800FD850_FE450 != var_s2 || D_800FD8C0_FE4C0 != var_s1 || D_800F9D22_FA922 != var_s0) {
                    D_800FD850_FE450 = var_s2;
                    D_800FD8C0_FE4C0 = var_s1;
                    D_800F9D22_FA922 = var_s0;
                    func_80038C04_39804(&D_800FDBCC_FE7CC, D_800FA620_FB220->unk00 + 1,
                        (D_800FD850_FE450 << 24) + (D_800FD8C0_FE4C0 << 16) + (D_800F9D22_FA922 << 8));
                }
            }

            var_s2 = temp_s3->unk05[0] * D_8010105C_101C5C;
            if (var_s2 > 255) {
                var_s2 = 255;
            }
            var_s1 = temp_s3->unk05[1] * D_8010105C_101C5C;
            if (var_s1 > 255) {
                var_s1 = 255;
            }
            var_s0 = temp_s3->unk05[2] * D_8010105C_101C5C;
            if (var_s0 > 255) {
                var_s0 = 255;
            }

            if (D_800FA19A_FAD9A != var_s2 || D_800FA5B0_FB1B0 != var_s1 || D_800F9D38_FA938 != var_s0) {
                D_800FA19A_FAD9A = var_s2;
                D_800FA5B0_FB1B0 = var_s1;
                D_800F9D38_FA938 = var_s0;
                func_80038C04_39804(&D_800FDBCC_FE7CC, 1, (D_800FA19A_FAD9A << 24) + (D_800FA5B0_FB1B0 << 16) + (D_800F9D38_FA938 << 8));
            }
        } else {
            switch (temp_s4->unk00) {
                case 42:
                case 43:
                    var_s2 = temp_s3->unk01[0] * D_80101300_101F00;
                    if (var_s2 > 255) {
                        var_s2 = 255;
                    }
                    var_s1 = temp_s3->unk01[1] * D_80101300_101F00;
                    if (var_s1 > 255) {
                        var_s1 = 255;
                    }
                    var_s0 = temp_s3->unk01[2] * D_80101300_101F00;
                    if (var_s0 > 255) {
                        var_s0 = 255;
                    }
                    break;
                case 41:
                    var_s2 = D_80101300_101F00 * 255.0f;
                    if (var_s2 > 255) {
                        var_s2 = 255;
                    }
                    var_s1 = var_s0 = var_s2;
                    break;
            }

            if ((D_800F64C4_F70C4 & 0x200) && (D_800FD850_FE450 != var_s2 || D_800FD8C0_FE4C0 != var_s1 || D_800F9D22_FA922 != var_s0)) {
                D_800FD850_FE450 = var_s2;
                D_800FD8C0_FE4C0 = var_s1;
                D_800F9D22_FA922 = var_s0;
                func_80038C04_39804(&D_800FDBCC_FE7CC, D_800FA620_FB220->unk00 + 1,
                    (D_800FD850_FE450 << 24) + (D_800FD8C0_FE4C0 << 16) + (D_800F9D22_FA922 << 8));
            }

            switch (temp_s4->unk00) {
                case 43:
                    var_s2 = temp_s4->unk05 * D_8010105C_101C5C;
                    if (var_s2 > 255) {
                        var_s2 = 255;
                    }
                    var_s1 = temp_s4->unk06 * D_8010105C_101C5C;
                    if (var_s1 > 255) {
                        var_s1 = 255;
                    }
                    var_s0 = temp_s4->unk07 * D_8010105C_101C5C;
                    if (var_s0 > 255) {
                        var_s0 = 255;
                    }
                    break;
                case 41:
                    var_s2 = D_8010105C_101C5C * 255.0f;
                    if (var_s2 > 255) {
                        var_s2 = 255;
                    }
                    var_s0 = var_s2;
                    var_s1 = var_s0;
                    break;
                default:
                    var_s2 = temp_s3->unk05[0] * D_8010105C_101C5C;
                    if (var_s2 > 255) {
                        var_s2 = 255;
                    }
                    var_s1 = temp_s3->unk05[1] * D_8010105C_101C5C;
                    if (var_s1 > 255) {
                        var_s1 = 255;
                    }
                    var_s0 = temp_s3->unk05[2] * D_8010105C_101C5C;
                    if (var_s0 > 255) {
                        var_s0 = 255;
                    }
                    break;
            }

            if (D_800FA19A_FAD9A != var_s2 || D_800FA5B0_FB1B0 != var_s1 || D_800F9D38_FA938 != var_s0) {
                D_800FA19A_FAD9A = var_s2;
                D_800FA5B0_FB1B0 = var_s1;
                D_800F9D38_FA938 = var_s0;
                func_80038C04_39804(&D_800FDBCC_FE7CC, 1, (D_800FA19A_FAD9A << 24) + (D_800FA5B0_FB1B0 << 16) + (D_800F9D38_FA938 << 8));
            }

            if (temp_s4 != D_800FC888_FD488 && !(*arg1 & 0x08000000)) {
                D_80102722_103322++;
                temp_a3 = temp_s4->unk0C;
                D_800FC888_FD488 = temp_s4;

                if (temp_s4->unk03 != -1) {
                    var_t0 = (u8*) (temp_s4->unk03 << 24); /* a segmented address */
                    *arg1 |= 0x40000;
                    dlp = &D_800FDBCC_FE7CC;
                    D_80101502_102102 = 1;
                } else {
                    var_t0 = temp_a3->unk28;
                    if (D_80101502_102102 == 0) {
                        dlp = &D_8010271C_10331C;
                        D_800F8C4C_F984C = D_800FC888_FD488;
                    } else {
                        dlp = &D_800FDBCC_FE7CC;
                    }
                }

                if (temp_a3->unk1C != 2) {
                    if (D_800DEFB4_DFBB4 != G_TT_NONE) {
                        D_800DEFB4_DFBB4 = G_TT_NONE;
                        gDPSetTextureLUT(D_800FDBCC_FE7CC++, G_TT_NONE);
                    }

                    if (temp_a3->unk1D != 0) {
                        switch (temp_a3->unk1D) {
                            case G_IM_SIZ_16b:
                                D_800F92E0_F9EE0 = G_IM_SIZ_16b_LOAD_BLOCK;
                                D_800F956C_FA16C = G_IM_SIZ_16b_INCR;
                                D_801026D0_1032D0 = G_IM_SIZ_16b_BYTES;
                                D_800F60A4_F6CA4 = G_IM_SIZ_16b_LINE_BYTES;
                                D_800FDBD4_FE7D4 = G_IM_SIZ_16b_SHIFT;
                                break;
                            case G_IM_SIZ_8b:
                                D_800F92E0_F9EE0 = G_IM_SIZ_8b_LOAD_BLOCK;
                                D_800F956C_FA16C = G_IM_SIZ_8b_INCR;
                                D_801026D0_1032D0 = G_IM_SIZ_8b_BYTES;
                                D_800F60A4_F6CA4 = G_IM_SIZ_8b_LINE_BYTES;
                                D_800FDBD4_FE7D4 = G_IM_SIZ_8b_SHIFT;
                                break;
                            case G_IM_SIZ_4b:
                                D_800F92E0_F9EE0 = G_IM_SIZ_4b_LOAD_BLOCK;
                                D_800F956C_FA16C = G_IM_SIZ_4b_INCR;
                                D_801026D0_1032D0 = G_IM_SIZ_4b_BYTES;
                                D_800F60A4_F6CA4 = G_IM_SIZ_4b_LINE_BYTES;
                                D_800FDBD4_FE7D4 = G_IM_SIZ_4b_SHIFT;
                                break;
                            default:
                                D_800F92E0_F9EE0 = G_IM_SIZ_32b_LOAD_BLOCK;
                                D_800F956C_FA16C = G_IM_SIZ_32b_INCR;
                                D_801026D0_1032D0 = G_IM_SIZ_32b_BYTES;
                                D_800F60A4_F6CA4 = G_IM_SIZ_32b_LINE_BYTES;
                                D_800FDBD4_FE7D4 = G_IM_SIZ_32b_SHIFT;
                                break;
                        }

                        gDPSetTextureImage((*dlp)++, temp_a3->unk1C, D_800F92E0_F9EE0, 1, var_t0);
                        gDPSetTile((*dlp)++, temp_a3->unk1C, D_800F92E0_F9EE0, 0, 0x0000, G_TX_LOADTILE, 0,
                            temp_s4->unk02, INTEGER_LOG2(temp_a3->unk1F), G_TX_NOLOD,
                            temp_s4->unk01, INTEGER_LOG2(temp_a3->unk1E), G_TX_NOLOD);
                        gDPLoadSync((*dlp)++);
                        gDPLoadBlock((*dlp)++, G_TX_LOADTILE, 0, 0,
                            ((temp_a3->unk1E * temp_a3->unk1F + D_800F956C_FA16C) >> D_800FDBD4_FE7D4) - 1,
                            CALC_DXT(temp_a3->unk1E, D_801026D0_1032D0));
                        gDPPipeSync((*dlp)++);
                        gDPSetTile((*dlp)++, temp_a3->unk1C, temp_a3->unk1D,
                            (temp_a3->unk1E * D_800F60A4_F6CA4 + 7) >> 3, 0x0000, G_TX_RENDERTILE, 0,
                            temp_s4->unk02, INTEGER_LOG2(temp_a3->unk1F), G_TX_NOLOD,
                            temp_s4->unk01, INTEGER_LOG2(temp_a3->unk1E), G_TX_NOLOD);
                        gDPSetTileSize((*dlp)++, G_TX_RENDERTILE, 0, 0, (temp_a3->unk1E - 1) * 4, (temp_a3->unk1F - 1) * 4);
                    } else if (temp_a3->unk1E < 16) {
                        gDPLoadTextureTile_4b((*dlp)++, var_t0, temp_a3->unk1C, temp_a3->unk1E, temp_a3->unk1F,
                            0, 0, temp_a3->unk1E, temp_a3->unk1F, 0, temp_s4->unk01, temp_s4->unk02,
                            INTEGER_LOG2(temp_a3->unk1E), INTEGER_LOG2(temp_a3->unk1F), G_TX_NOLOD, G_TX_NOLOD);
                    } else {
                        gDPLoadTextureBlock_4b((*dlp)++, var_t0, temp_a3->unk1C, temp_a3->unk1E, temp_a3->unk1F, 0,
                            temp_s4->unk01, temp_s4->unk02, INTEGER_LOG2(temp_a3->unk1E), INTEGER_LOG2(temp_a3->unk1F),
                            G_TX_NOLOD, G_TX_NOLOD);
                    }
                } else {
                    if (temp_s4->unk04 != -1) {
                        var_a0 = (u16*) (temp_s4->unk04 << 24); /* a segmented address */
                        *arg1 |= 0x40000;
                        dlp = &D_800FDBCC_FE7CC;
                        D_80101502_102102 = 1;
                    } else {
                        var_a0 = temp_a3->unk30->unk28;
                        if (D_80101502_102102 == 0) {
                            dlp = &D_8010271C_10331C;
                            D_800F8C4C_F984C = D_800FC888_FD488;
                        } else {
                            dlp = &D_800FDBCC_FE7CC;
                        }
                    }

                    if (D_800DEFB4_DFBB4 != G_TT_RGBA16) {
                        D_800DEFB4_DFBB4 = G_TT_RGBA16;
                        gDPSetTextureLUT(D_800FDBCC_FE7CC++, G_TT_RGBA16);
                    }

                    if (temp_a3->unk30->unk1E < 17) {
                        gDPLoadTLUT_pal16((*dlp)++, 0, var_a0);

                        if (temp_a3->unk1E < 16) {
                            gDPLoadTextureTile_4b((*dlp)++, var_t0, temp_a3->unk1C, temp_a3->unk1E, temp_a3->unk1F,
                                0, 0, temp_a3->unk1E, temp_a3->unk1F, 0, temp_s4->unk01, temp_s4->unk02,
                                INTEGER_LOG2(temp_a3->unk1E), INTEGER_LOG2(temp_a3->unk1F), G_TX_NOLOD, G_TX_NOLOD);
                        } else {
                            gDPLoadTextureBlock_4b((*dlp)++, var_t0, temp_a3->unk1C, temp_a3->unk1E, temp_a3->unk1F, 0,
                                temp_s4->unk01, temp_s4->unk02, INTEGER_LOG2(temp_a3->unk1E), INTEGER_LOG2(temp_a3->unk1F),
                                G_TX_NOLOD, G_TX_NOLOD);
                        }
                    } else {
                        gDPLoadTLUT_pal256((*dlp)++, var_a0);

                        if (temp_a3->unk1E < 8) {
                            gDPLoadTextureTile((*dlp)++, var_t0, temp_a3->unk1C, G_IM_SIZ_8b, temp_a3->unk1E, temp_a3->unk1F,
                                0, 0, temp_a3->unk1E, temp_a3->unk1F, 0, temp_s4->unk01, temp_s4->unk02,
                                INTEGER_LOG2(temp_a3->unk1E), INTEGER_LOG2(temp_a3->unk1F), G_TX_NOLOD, G_TX_NOLOD);
                        } else {
                            gDPLoadTextureBlockYuv((*dlp)++, var_t0, temp_a3->unk1C, G_IM_SIZ_8b, temp_a3->unk1E, temp_a3->unk1F, 0,
                                temp_s4->unk01, temp_s4->unk02, INTEGER_LOG2(temp_a3->unk1E), INTEGER_LOG2(temp_a3->unk1F),
                                G_TX_NOLOD, G_TX_NOLOD);
                        }
                    }
                }
                D_80101502_102102 = 1;
            }
        }
    }

    if (D_800FA61C_FB21C - D_800FA1A6_FADA6 > 32) {
        gSPVertex(D_800FDBCC_FE7CC++, D_800FA1A6_FADA6 * 16 + 0x01000000, 32, 0);
        gSPVertex(D_800FDBCC_FE7CC++, (D_800FA1A6_FADA6 + 32) * 16 + 0x01000000, D_800FA61C_FB21C - D_800FA1A6_FADA6 - 32, 32);
    } else {
        gSPVertex(D_800FDBCC_FE7CC++, D_800FA1A6_FADA6 * 16 + 0x01000000, D_800FA61C_FB21C - D_800FA1A6_FADA6, 0);
    }

    for (i = 0; i < D_800FCE92_FDA92; i++) {
        temp_a1 = &D_800F9918_FA518[i];
        if (temp_a1->unk00 == 3) {
            D_800F8D24_F9924++;
            gSP1Triangle(D_800FDBCC_FE7CC++, temp_a1->unk02[0], temp_a1->unk02[1], temp_a1->unk02[2], 0);
        } else {
            D_800F8D24_F9924 += 2;
            gSP1Quadrangle(D_800FDBCC_FE7CC++, temp_a1->unk02[0], temp_a1->unk02[1], temp_a1->unk02[2], temp_a1->unk02[3], 0);
        }
    }

    D_800FA1A6_FADA6 = D_800FA61C_FB21C;
}
void func_80035C18_36818(HmfData* arg0, s16 arg1) {
    s16* p;

    gSPClearGeometryMode(D_800FDBCC_FE7CC++, G_LIGHTING);

    p = &D_80101170_101D70[D_800FA61C_FB21C++].unk00;
    *p++ = arg0->unk64[arg1].unk42;
    *p++ = arg0->unk64[arg1].unk44;
    *p = arg0->unk64[arg1].unk46;

    p = &D_80101170_101D70[D_800FA61C_FB21C++].unk00;
    *p++ = arg0->unk64[arg1].unk42;
    *p++ = arg0->unk64[arg1].unk4A;
    *p = arg0->unk64[arg1].unk46;

    p = &D_80101170_101D70[D_800FA61C_FB21C++].unk00;
    *p++ = arg0->unk64[arg1].unk48;
    *p++ = arg0->unk64[arg1].unk4A;
    *p = arg0->unk64[arg1].unk46;

    p = &D_80101170_101D70[D_800FA61C_FB21C++].unk00;
    *p++ = arg0->unk64[arg1].unk48;
    *p++ = arg0->unk64[arg1].unk44;
    *p = arg0->unk64[arg1].unk46;

    p = &D_80101170_101D70[D_800FA61C_FB21C++].unk00;
    *p++ = arg0->unk64[arg1].unk42;
    *p++ = arg0->unk64[arg1].unk44;
    *p = arg0->unk64[arg1].unk4C;

    p = &D_80101170_101D70[D_800FA61C_FB21C++].unk00;
    *p++ = arg0->unk64[arg1].unk42;
    *p++ = arg0->unk64[arg1].unk4A;
    *p = arg0->unk64[arg1].unk4C;

    p = &D_80101170_101D70[D_800FA61C_FB21C++].unk00;
    *p++ = arg0->unk64[arg1].unk48;
    *p++ = arg0->unk64[arg1].unk4A;
    *p = arg0->unk64[arg1].unk4C;

    p = &D_80101170_101D70[D_800FA61C_FB21C++].unk00;
    *p++ = arg0->unk64[arg1].unk48;
    *p++ = arg0->unk64[arg1].unk44;
    *p = arg0->unk64[arg1].unk4C;

    gSPVertex(D_800FDBCC_FE7CC++, D_800FA1A6_FADA6 * 16 + 0x01000000, D_800FA61C_FB21C - D_800FA1A6_FADA6, 0);

    D_800FA1A6_FADA6 = D_800FA61C_FB21C;

    gSPCullDisplayList(D_800FDBCC_FE7CC++, 0, 7);
}
/* MP1 func_80031054 (src/2C0C0.c, NON_MATCHING there too): combine and render modes for a material.
   Block layout only: GCC turns the 64-bit combine if/else pairs into default-then-override and
   shares the render-mode tails that retail keeps per arm (masked 119); every branch checked against the asm */
#ifdef NON_MATCHING
void func_80035FBC_36BBC(HmfMat* arg0, HmfTexRef* arg1, s32 arg2) {
    u64 cc;
    s64 rm;
    s32 flags;
    s32 zbuf;
    s16 zmode;
    s32 t;

    flags = arg0->unk0C;
    zbuf = 0;
    if ((D_800F64C4_F70C4 & 0x180) != 0x100) {
        zbuf = (u16) D_800F64C4_F70C4 & 0x180;
    }
    if (arg2 & 0x80000) {
        return;
    }
    if (D_800F64C4_F70C4 & 0x80000) {
        cc = 0xFCFFFFFFFFFFFFFFLL;
    } else if (D_800F64C4_F70C4 & 0x10000) {
        cc = 0xFC127E2455FDF2F9LL;
    } else if (arg2 & 0x200000) {
        cc = 0xFCFFFFFFFFFE793CLL;
    } else if (arg1 == (HmfTexRef*) -1) {
        if (arg0->unk0C & 1) {
            cc = 0xFC327E64FFFFF7FBLL;
        } else {
            if (!(flags & 4)) {
                gDPSetPrimColor(D_800FDBCC_FE7CC++, 0, 0, arg0->unk05[0], arg0->unk05[1], arg0->unk05[2], 1);
            }
            if (D_800FA60C_FB20C == 0) {
                cc = 0xFC327E64FFFFFDFELL;
            } else {
                cc = 0xFC327FFFFFFFFC38LL;
            }
        }
    } else if (arg1->unk0C->unk1C == 3) {
        if (D_800FA60C_FB20C == 0) {
            cc = 0xFC119623FF2FFFFFLL;
            flags |= 1;
        } else {
            cc = 0xFC1197FFFFFFFE38LL;
            flags |= 1;
        }
    } else if (arg1->unk0C->unk1C == 4) {
        if (D_800FA60C_FB20C == 0) {
            cc = 0xFCFF97FFFF2DFEFFLL;
            flags |= 1;
        } else {
            cc = 0xFCFF97FFFFFDFE38LL;
            flags |= 1;
        }
    } else if (arg1->unk0C->unk1D == 3) {
        if (D_800FA60C_FB20C == 0) {
            cc = 0xFC121624FF2FFFFFLL;
            flags |= 1;
        } else {
            cc = 0xFC1217FFFFFFFE38LL;
            flags |= 1;
        }
    } else if (flags & 1) {
        if (D_800FA60C_FB20C == 0) {
            cc = 0xFC121624FF2FFFFFLL;
        } else {
            cc = 0xFC1217FFFFFFFE38LL;
        }
    } else if (D_800FA60C_FB20C == 0) {
        cc = 0xFC127E24FFFFF3F9LL;
    } else {
        cc = 0xFC127FFFFFFFF238LL;
    }

    t = D_800F64C4_F70C4 & 0x60;
    if (t == 0x20) {
        zmode = 0x48;
    } else {
        zmode = (t == 0x40) ? 8 : 0;
    }
    if (D_800F64C4_F70C4 & 0x80000) {
        rm = 0x5553F0;
    } else if (arg2 & 0x8000) {
        gDPSetBlendColor(D_800FDBCC_FE7CC++, 0, 0, 0, 1);
        gDPSetAlphaCompare(D_800FDBCC_FE7CC++, G_AC_THRESHOLD);
        if (!(flags & 4)) {
            gDPSetPrimColor(D_800FDBCC_FE7CC++, 0, 0, arg0->unk05[0], arg0->unk05[1], arg0->unk05[2], arg0->unk0D);
        }
        rm = (arg1 == (HmfTexRef*) -1) ? 0x50007B : 0x50307B;
        D_800FA720_FB320 = 0;
    } else if (arg2 & 0x200000) {
        rm = 0x507858;
    } else if (arg2 < 0) {
        if (flags & 1) {
            gDPSetBlendColor(D_800FDBCC_FE7CC++, 0, 0, 0, 1);
            gDPSetAlphaCompare(D_800FDBCC_FE7CC++, G_AC_THRESHOLD);
            if (!(flags & 4)) {
                gDPSetPrimColor(D_800FDBCC_FE7CC++, 0, 0, arg0->unk05[0], arg0->unk05[1], arg0->unk05[2], arg0->unk0D);
            }
            if (D_800FA60C_FB20C == 0) {
                rm = 0x504DD8;
            } else {
                rm = (s32) 0xC8104DD8;
            }
        } else {
            gDPSetAlphaCompare(D_800FDBCC_FE7CC++, G_AC_NONE);
            if (D_800FA60C_FB20C == 0) {
                rm = zmode | 0x553D10;
            } else {
                rm = (s32) 0xC8113D10 | zmode;
            }
        }
        D_800DEFB0_DFBB0->unk00 = arg0->unk00;
    } else if (flags & 1) {
        gDPSetBlendColor(D_800FDBCC_FE7CC++, 0, 0, 0, 1);
        gDPSetAlphaCompare(D_800FDBCC_FE7CC++, G_AC_THRESHOLD);
        if (!(flags & 4)) {
            gDPSetPrimColor(D_800FDBCC_FE7CC++, 0, 0, arg0->unk05[0], arg0->unk05[1], arg0->unk05[2], arg0->unk0D);
        }
        if (zmode != 0) {
            zmode |= 0x180;
        } else {
            zmode |= 0x200;
        }
        if (zbuf != 0) {
            if (D_800FA60C_FB20C == 0) {
                rm = zmode | 0x504850;
            } else {
                rm = (s32) 0xC8104850 | zmode;
            }
        } else if (D_800FA60C_FB20C == 0) {
            rm = zmode | 0x504040;
        } else {
            rm = (s32) 0xC8104040 | zmode;
        }
        D_800DEFB0_DFBB0->unk00 = arg0->unk00;
    } else {
        gDPSetAlphaCompare(D_800FDBCC_FE7CC++, G_AC_NONE);
        if (arg1 == (HmfTexRef*) -1) {
            if (zmode == 0) {
                zmode |= 0x200;
            }
            if (zbuf != 0) {
                if (D_800FA60C_FB20C == 0) {
                    rm = zmode | 0x552030;
                } else {
                    rm = (s32) 0xC8112030 | zmode;
                }
            } else if (D_800FA60C_FB20C == 0) {
                rm = zmode | 0x552000;
            } else {
                rm = (s32) 0xC8112000 | zmode;
            }
        } else if (D_800F64C4_F70C4 & 0x20000) {
            if (zmode == 0) {
                zmode |= 0x200;
            }
            if (zbuf != 0) {
                if (D_800FA60C_FB20C == 0) {
                    rm = zmode | 0x552030;
                } else {
                    rm = (s32) 0xC8112030 | zmode;
                }
            } else if (D_800FA60C_FB20C == 0) {
                rm = zmode | 0x552000;
            } else {
                rm = (s32) 0xC8112000 | zmode;
            }
        } else if (zbuf != 0) {
            if (D_800FA60C_FB20C == 0) {
                rm = zmode | 0x553038;
            } else {
                rm = (s32) 0xC8113038 | zmode;
            }
        } else if (D_800FA60C_FB20C == 0) {
            rm = zmode | 0x0F0A7008;
        } else {
            rm = (s32) 0xCB027008 | zmode;
        }
    }

    if (D_800FD8A0_FE4A0 != cc || D_800FA720_FB320 != (u64) rm) {
        gDPPipeSync(D_800FDBCC_FE7CC++);
        if (D_800FD8A0_FE4A0 != cc) {
            D_800FD8A0_FE4A0 = cc;
            {
                Gfx* g = D_800FDBCC_FE7CC++;

                g->words.w0 = cc >> 32;
                g->words.w1 = cc;
            }
        }
        if (D_800FA720_FB320 != (u64) rm) {
            {
                Gfx* g = D_800FDBCC_FE7CC++;

                g->words.w0 = 0xE200001C;
                g->words.w1 = rm;
            }
            D_800FA720_FB320 = rm;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/30560", func_80035FBC_36BBC);
#endif
/* exact c: marioparty func_800318D0 (src/2C0C0.c) */
void func_800368B4_374B4(u16 arg0) {
    u8 temp_v1;

    temp_v1 = (arg0 >> 7) & 3;
    if (temp_v1 != D_800FD800_FE400) {
        D_800FD800_FE400 = temp_v1;
        gDPSetTextureFilter(D_800FDBCC_FE7CC++, G_TF_POINT | D_800CA090_CAC90[temp_v1]);
    }

    if (D_800FDC84_FE884 != D_800FDEA0_FEAA0) {
        D_800FDEA0_FEAA0 = D_800FDC84_FE884;
        if (D_800FDC84_FE884 == 0) {
            gSPSetGeometryMode(D_800FDBCC_FE7CC++, G_SHADING_SMOOTH);
        } else {
            gSPClearGeometryMode(D_800FDBCC_FE7CC++, G_SHADING_SMOOTH);
        }
    }

    temp_v1 = (arg0 >> 9) & 3;
    if (temp_v1 != D_800F94C0_FA0C0) {
        D_800F94C0_FA0C0 = temp_v1;
        switch (temp_v1) {
            case 0:
                gDPSetColorDither(D_800FDBCC_FE7CC++, G_CD_DISABLE);
                break;
            case 1:
                gDPSetColorDither(D_800FDBCC_FE7CC++, G_CD_NOISE);
                break;
            case 2:
                gDPSetColorDither(D_800FDBCC_FE7CC++, G_CD_BAYER);
                break;
            case 3:
                gDPSetColorDither(D_800FDBCC_FE7CC++, G_CD_MAGICSQ);
                break;
            }
    }

    if (D_800FA60C_FB20C != 0) {
        gSPFogFactor(D_800FDBCC_FE7CC++, 500 * 256 / (D_800F8C54_F9854 - D_801027FA_1033FA), (500 - D_801027FA_1033FA) * 256 / (D_800F8C54_F9854 - D_801027FA_1033FA));
        gDPSetFogColor(D_800FDBCC_FE7CC++, D_800FC9E9_FD5E9, D_8010002C_100C2C, D_800F9D2C_FA92C, 255);
    }
}

/* exact c: marioparty func_80031BB4 (src/2C0C0.c) */
void func_80036B98_37798(void) {
    gMoveWd(D_800FDBCC_FE7CC++, G_MW_CLIP, G_MWO_CLIP_RNX, *(D_800F8C48_F9848 * 2 + &D_800CA098_CAC98[0]));
    gMoveWd(D_800FDBCC_FE7CC++, G_MW_CLIP, G_MWO_CLIP_RNY, *(D_800F8C48_F9848 * 2 + &D_800CA098_CAC98[0]));
    gMoveWd(D_800FDBCC_FE7CC++, G_MW_CLIP, G_MWO_CLIP_RPX, *(D_800F8C48_F9848 * 2 + &D_800CA098_CAC98[1]));
    gMoveWd(D_800FDBCC_FE7CC++, G_MW_CLIP, G_MWO_CLIP_RPY, *(D_800F8C48_F9848 * 2 + &D_800CA098_CAC98[1]));
}

/* exact c: marioparty func_80031C60 (src/2C0C0.c) */
void func_80036C44_37844(HmfData* arg0, s32 arg1, s16 arg2) {
    if (D_800FD84C_FE44C != arg1 || arg1 & 0x0E000000) {
        D_800FD84C_FE44C = arg1;

        gSPDisplayList(D_800FDBCC_FE7CC++, D_800CA030_CAC30);

        if (arg1 & 0x2000) {
            gSPSetGeometryMode(D_800FDBCC_FE7CC++, G_CULL_BACK);
        }

        if (D_800FA60C_FB20C != 0) {
            gDPSetCycleType(D_800FDBCC_FE7CC++, G_CYC_2CYCLE);
            gSPSetGeometryMode(D_800FDBCC_FE7CC++, G_FOG);
        }

        if (arg1 & 0x06000000) {
            func_80037C7C_3887C(arg0, arg2);
        } else if (arg1 & 0x08000000) {
            func_80036D5C_3795C(arg0, arg2);
        }
    }
}

void func_80036EF8_37AF8(HmfTex*, s32, s32);

/* MP1 func_80031D78 (src/2C0C0.c): reflection mapping for a part */
void func_80036D5C_3795C(HmfData* arg0, s16 arg1) {
    Mtx sp30;
    HmfTex* var_a0;

    if (arg0->unk64[arg1].unk2E != 255) {
        gDPPipeSync(D_800FDBCC_FE7CC++);

        guLookAtReflect(&sp30, &D_800FA658_FB258->unk_40, 0, 40.0f, 200.0f, 0, 0, 0, 0, -1.0f, 0);

        gSPLookAt(D_800FDBCC_FE7CC++, &D_800FA658_FB258->unk_40);
        gSPTexture(D_800FDBCC_FE7CC++, 1984, 1984, 0, G_TX_RENDERTILE, G_ON);

        if (arg0->unkA0 == 0) {
            var_a0 = arg0->unk88[arg0->unk64[arg1].unk2E].unk0C;
        } else {
            var_a0 = arg0->unkA0;
        }

        func_80036EF8_37AF8(var_a0, 0, 0);

        gSPSetGeometryMode(D_800FDBCC_FE7CC++, G_LIGHTING | G_TEXTURE_GEN);
    }
}

/* same c: marioparty func_80031F14 (src/2C0C0.c) */
void func_80036EF8_37AF8(HmfTex* arg0, s32 arg1, s32 arg2) {
    if (arg0->unk1C != 2) {
        gDPSetTextureLUT(D_800FDBCC_FE7CC++, G_TT_NONE);

        switch (arg0->unk1D) {
            case G_IM_SIZ_16b:
                D_800F92E0_F9EE0 = G_IM_SIZ_16b_LOAD_BLOCK;
                D_800F956C_FA16C = G_IM_SIZ_16b_INCR;
                D_801026D0_1032D0 = G_IM_SIZ_16b_BYTES;
                D_800F60A4_F6CA4 = G_IM_SIZ_16b_LINE_BYTES;
                D_800FDBD4_FE7D4 = G_IM_SIZ_16b_SHIFT;
                break;
            case G_IM_SIZ_8b:
                D_800F92E0_F9EE0 = G_IM_SIZ_8b_LOAD_BLOCK;
                D_800F956C_FA16C = G_IM_SIZ_8b_INCR;
                D_801026D0_1032D0 = G_IM_SIZ_8b_BYTES;
                D_800F60A4_F6CA4 = G_IM_SIZ_8b_LINE_BYTES;
                D_800FDBD4_FE7D4 = G_IM_SIZ_8b_SHIFT;
                break;
            case G_IM_SIZ_4b:
                D_800F92E0_F9EE0 = G_IM_SIZ_4b_LOAD_BLOCK;
                D_800F956C_FA16C = G_IM_SIZ_4b_INCR;
                D_801026D0_1032D0 = G_IM_SIZ_4b_BYTES;
                D_800F60A4_F6CA4 = G_IM_SIZ_4b_LINE_BYTES;
                D_800FDBD4_FE7D4 = G_IM_SIZ_4b_SHIFT;
                break;
            default:
                D_800F92E0_F9EE0 = G_IM_SIZ_32b_LOAD_BLOCK;
                D_800F956C_FA16C = G_IM_SIZ_32b_INCR;
                D_801026D0_1032D0 = G_IM_SIZ_32b_BYTES;
                D_800F60A4_F6CA4 = G_IM_SIZ_32b_LINE_BYTES;
                D_800FDBD4_FE7D4 = G_IM_SIZ_32b_SHIFT;
                break;
        }

        gDPSetTextureImage(D_800FDBCC_FE7CC++, arg0->unk1C, D_800F92E0_F9EE0, 1, arg0->unk28);
        gDPSetTile(D_800FDBCC_FE7CC++, arg0->unk1C, D_800F92E0_F9EE0, 0, 0x0000, G_TX_LOADTILE, 0,
            arg2, INTEGER_LOG2(arg0->unk1F), G_TX_NOLOD, arg1, INTEGER_LOG2(arg0->unk1E), G_TX_NOLOD);
        gDPLoadSync(D_800FDBCC_FE7CC++);
        gDPLoadBlock(D_800FDBCC_FE7CC++, G_TX_LOADTILE, 0, 0,
            ((arg0->unk1E * arg0->unk1F + D_800F956C_FA16C) >> D_800FDBD4_FE7D4) - 1,
            CALC_DXT(arg0->unk1E, D_801026D0_1032D0));
        gDPPipeSync(D_800FDBCC_FE7CC++);
        gDPSetTile(D_800FDBCC_FE7CC++, arg0->unk1C, arg0->unk1D, (arg0->unk1E * D_800F60A4_F6CA4 + 7) >> 3, 0x0000, G_TX_RENDERTILE, 0,
            arg2, INTEGER_LOG2(arg0->unk1F), G_TX_NOLOD, arg1, INTEGER_LOG2(arg0->unk1E), G_TX_NOLOD);
        gDPSetTileSize(D_800FDBCC_FE7CC++, G_TX_RENDERTILE, 0, 0, (arg0->unk1E - 1) * 4, (arg0->unk1F - 1) * 4);
    } else {
        gDPSetTextureLUT(D_800FDBCC_FE7CC++, G_TT_RGBA16);

        if (arg0->unk30->unk1E < 17) {
            gDPLoadTLUT_pal16(D_800FDBCC_FE7CC++, 0, arg0->unk30->unk28);
            gDPLoadTextureBlock_4b(D_800FDBCC_FE7CC++, arg0->unk28, arg0->unk1C, arg0->unk1E, arg0->unk1F, 0,
                arg1, arg2, INTEGER_LOG2(arg0->unk1E), INTEGER_LOG2(arg0->unk1F), 0, 0);
        } else {
            gDPLoadTLUT_pal256(D_800FDBCC_FE7CC++, arg0->unk30->unk28);
            gDPLoadTextureBlockYuv(D_800FDBCC_FE7CC++, arg0->unk28, arg0->unk1C, G_IM_SIZ_8b, arg0->unk1E, arg0->unk1F, 0,
                arg1, arg2, INTEGER_LOG2(arg0->unk1E), INTEGER_LOG2(arg0->unk1F), 0, 0);
        }
    }
}

extern Gfx D_800CACC8_CB8C8[];
extern void* D_800CAD04_CB904[4]; /* highlight textures */
extern void* D_800FC888_FD488;
extern u64 D_800FA720_FB320;
extern u64 D_800FD8A0_FE4A0;

#define CAMERA(field) (((HuCamera*) D_800FD2A8_FDEA8)->field)

/* MP1 func_80032C98 (src/2C0C0.c): specular highlight for a part */
void func_80037C7C_3887C(HmfData* arg0, s16 arg1) {
    HmfMat* temp_a0;
    void* timg;
    Mtx sp50;

    gSPDisplayList(D_800FDBCC_FE7CC++, D_800CACC8_CB8C8);
    guLookAtHilite(&sp50, &D_800FA658_FB258->unk_40, &D_800FA658_FB258->unk_00,
        CAMERA(pos.x), CAMERA(pos.y), CAMERA(pos.z),
        CAMERA(at.x), CAMERA(at.y), CAMERA(at.z),
        CAMERA(up.x), CAMERA(up.y), CAMERA(up.z), 0, 0, 115.0f, 0, 0, 115.0f, 32, 32);
    gSPLookAt(D_800FDBCC_FE7CC++, &D_800FA658_FB258->unk_40);

    temp_a0 = &arg0->unk8C[arg0->unk64[arg1].unk54->unk30];
    gDPSetPrimColor(D_800FDBCC_FE7CC++, 0, 0, temp_a0->unk09[0], temp_a0->unk09[1], temp_a0->unk09[2], 255);
    gDPSetEnvColor(D_800FDBCC_FE7CC++, 64, 64, 64, 128);

    timg = D_800CAD04_CB904[((u32) arg0->unk64[arg1].unk50 >> 25) % 4];
    gDPLoadTextureBlock(D_800FDBCC_FE7CC++, timg, G_IM_FMT_IA, G_IM_SIZ_8b, 32, 32, 0,
        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPSetTileSize(D_800FDBCC_FE7CC++, G_TX_RENDERTILE, D_800FA658_FB258->unk_00.h.x1, D_800FA658_FB258->unk_00.h.y1,
        D_800FA658_FB258->unk_00.h.x1 + 124, D_800FA658_FB258->unk_00.h.y1 + 124);

    if (arg0->unk64[arg1].unk50 & 0x10000) {
        gDPSetRenderMode(D_800FDBCC_FE7CC++, G_RM_ZB_CLD_SURF, G_RM_ZB_CLD_SURF2);
    } else {
        gDPSetRenderMode(D_800FDBCC_FE7CC++, G_RM_ZB_OVL_SURF, G_RM_ZB_OVL_SURF2);
    }

    D_800FC888_FD488 = NULL;
    D_800FA720_FB320 = 0xFFFFFFFF;
    D_800FD8A0_FE4A0 = 0xFFFFFFFF;
}

/* same c: marioparty3 func_8002C4C0_2D0C0 (src/22EB0.c) */
s32 func_80038024_38C24(HmfData *arg0, s16 arg1, Matrix4f arg2, Matrix4f arg3) {
    if (!(arg0->unk64[arg1].unk50 & 0x70000000)) {
        return 0;
    }
    func_800260A4_26CA4(arg2, arg3);
    return 1;
}

/* same c: marioparty func_80033408 (src/2C0C0.c) */
void func_80038084_38C84(HmfData* arg0, s16 arg1, Matrix4f arg2) {
    D_800FD470_FE070 = 0;
    guMtxIdentF(D_801016D0_1022D0[0]);
    if (arg0->unk84 == (void*)-1 && arg0->unk68 != 0) {
        func_8003811C_38D1C(arg0, 0, arg1);
        func_80030CD4_318D4(arg2, D_801016D0_1022D0[D_800FD470_FE070]);
    }
}

s32 func_8003811C_38D1C(HmfData* arg0, s16 arg1, s16 arg2) {
    Matrix4f sp10;
    HitXform* node;
    s16 pushed;

    node = &arg0->unk6C[arg1];
    pushed = 0;
    guMtxIdentF(sp10);
    if (node->unk08.x != 0.0f || node->unk08.y != 0.0f || node->unk08.z != 0.0f) {
        func_80025770_26370(sp10, node->unk08.x, node->unk08.y, node->unk08.z);
        pushed = 1;
    }
    if (node->unk14.x != 0.0f || node->unk14.y != 0.0f || node->unk14.z != 0.0f) {
        arg0->unkD4(sp10, node->unk14.x, node->unk14.y, node->unk14.z);
        pushed = 1;
    }
    if (node->unk20.x != 1.0f || node->unk20.y != 1.0f || node->unk20.z != 1.0f) {
        func_80025830_26430(sp10, node->unk20.x, node->unk20.y, node->unk20.z);
        pushed = 1;
    }
    if (pushed != 0) {
        D_800FD470_FE070++;
        func_80025BA4_267A4(sp10, D_801016D0_1022D0[D_800FD470_FE070 - 1], D_801016D0_1022D0[D_800FD470_FE070]);
    }
    if (arg2 == arg1) {
        return 0;
    }
    if (node->unk04 != 0 && func_8003811C_38D1C(arg0, arg1 + node->unk04, arg2) == 0) {
        return 0;
    }
    if (pushed != 0) {
        D_800FD470_FE070--;
    }
    if (node->unk02 != 0 && func_8003811C_38D1C(arg0, arg1 + node->unk02, arg2) == 0) {
        return 0;
    }
    return 1;
}
s16 func_80038398_38F98(HmfData* arg0, char* arg1) {
    s16 temp_a1;
    s16 i;

    temp_a1 = func_8001F4AC_200AC(arg1);
    for (i = 0; i < arg0->unk10; i++) {
        if (arg0->unk64[i].unk08 == temp_a1 && func_800B0FD0_B1BD0(arg0->unk64[i].unk12, arg1) == 0) {
            break;
        }
    }

    if (i == arg0->unk10) {
        osSyncPrintf(D_800D2294_D2E94, arg1);
        return -1;
    }

    return i;
}
/* exact c: marioparty func_800337E4 (src/2C0C0.c) */
void func_8003847C_3907C(HmfData* arg0, char* arg1, HmfData* arg2) {
    s16 idx;

    idx = func_80038398_38F98(arg0, arg1);
    if (idx != -1) {
        func_800384C8_390C8(arg0, idx, arg2);
    }
}

void func_800384C8_390C8(HmfData* arg0, s16 arg1, HmfData* arg2) {
    s16 i;
    s16 j;
    s16 name;
    HitXform* node;

    name = arg0->unk64[arg1].unk08;
    for (i = 0; i < arg2->unk10; i++) {
        if (arg2->unk64[i].unk08 == name && func_800B0FD0_B1BD0(arg2->unk64[i].unk12, arg0->unk64[arg1].unk12) == 0) {
            break;
        }
    }
    if (i != arg2->unk10) {
        for (j = 0; j < arg0->unk68; j++) {
            node = &arg0->unk6C[j];
            if (node->unk00 == arg1) {
                node->unk48 = arg2;
                node->unk00 = i;
            }
        }
    }
}
void func_80038654_39254(HmfData* arg0) {
    if (arg0->unk14 != 0) {
        D_8010107C_101C7C = 0;
        D_800FD470_FE070 = 0;

        func_800B37C0_B43C0(D_801016D0_1022D0[0]);

        if (arg0->unk84 == (void*) -1) {
            if (arg0->unk68 != 0) {
                func_800386DC_392DC(arg0, 0);
            }
        } else if (arg0->unk16 != 0) {
            func_80038964_39564(arg0, 0);
        }
    }
}
/* MP1 func_800339E0 (src/2C0C0.c). MP2 scales in place only, yet still pops D_8010107C_101C7C
   when it scaled (retail behaviour, kept) */
void func_800386DC_392DC(HmfData* arg0, s16 arg1) {
    HitXform* temp_s1 = &arg0->unk6C[arg1];
    s16 var_s3 = 0;
    s16 var_s0 = 0;
    Matrix4f sp10;

    func_800B37C0_B43C0(sp10);

    if (arg0->unk90 == 0) {
        if (temp_s1->unk08.x != 0.0f || temp_s1->unk08.y != 0.0f || temp_s1->unk08.z != 0.0f) {
            func_80025770_26370(sp10, temp_s1->unk08.x, temp_s1->unk08.y, temp_s1->unk08.z);
            var_s0 = 1;
        }

        if (temp_s1->unk14.x != 0.0f || temp_s1->unk14.y != 0.0f || temp_s1->unk14.z != 0.0f) {
            arg0->unkD4(sp10, temp_s1->unk14.x, temp_s1->unk14.y, temp_s1->unk14.z);
            var_s0 = 1;
        }
    }

    if (temp_s1->unk20.x != 1.0f || temp_s1->unk20.y != 1.0f || temp_s1->unk20.z != 1.0f) {
        func_80025830_26430(sp10, temp_s1->unk20.x, temp_s1->unk20.y, temp_s1->unk20.z);
        var_s3 = 1;
        var_s0 = 1;
    }

    if (var_s0 != 0) {
        D_800FD470_FE070++;
        func_80025BA4_267A4(sp10, D_801016D0_1022D0[D_800FD470_FE070 - 1], D_801016D0_1022D0[D_800FD470_FE070]);
    }

    func_80030CD4_318D4(temp_s1->unk4C, D_801016D0_1022D0[D_800FD470_FE070]);

    if (temp_s1->unk04 != 0) {
        func_800386DC_392DC(arg0, arg1 + temp_s1->unk04);
    }

    if (var_s0) {
        D_800FD470_FE070--;
    }

    if (var_s3) {
        D_8010107C_101C7C--;
    }

    if (temp_s1->unk02 != 0) {
        func_800386DC_392DC(arg0, arg1 + temp_s1->unk02);
    }
}
/* MP1 func_80033CBC (src/2C0C0.c); as func_800386DC_392DC, a scale pops D_8010107C_101C7C unpushed */
void func_80038964_39564(HmfData* arg0, s16 arg1) {
    HmfMotionObj* temp_s1 = &arg0->unk84[arg1];
    s16 var_s5 = 0;
    s16 var_s2 = 0;
    s16 i;
    Matrix4f sp10;

    func_800B37C0_B43C0(sp10);

    if (temp_s1->unk04.x != 0.0f || temp_s1->unk04.y != 0.0f || temp_s1->unk04.z != 0.0f) {
        func_80025770_26370(sp10, temp_s1->unk04.x, temp_s1->unk04.y, temp_s1->unk04.z);
        var_s2 = 1;
    }

    if (temp_s1->unk10.x != 0.0f || temp_s1->unk10.y != 0.0f || temp_s1->unk10.z != 0.0f) {
        arg0->unkD4(sp10, temp_s1->unk10.x, temp_s1->unk10.y, temp_s1->unk10.z);
        var_s2 = 1;
    }

    if (temp_s1->unk1C.x != 1.0f || temp_s1->unk1C.y != 1.0f || temp_s1->unk1C.z != 1.0f) {
        func_80025830_26430(sp10, temp_s1->unk1C.x, temp_s1->unk1C.y, temp_s1->unk1C.z);
        var_s5 = 1;
        var_s2 = 1;
    }

    if (var_s2) {
        D_800FD470_FE070++;
        func_80025BA4_267A4(sp10, D_801016D0_1022D0[D_800FD470_FE070 - 1], D_801016D0_1022D0[D_800FD470_FE070]);
    }

    func_80030CD4_318D4(temp_s1->unk58, D_801016D0_1022D0[D_800FD470_FE070]);

    for (i = 0; i < temp_s1->unk00; i++) {
        if ((temp_s1->unk50[i] & 0x8000) && (temp_s1->unk50[i] != -1)) {
            func_80038964_39564(arg0, temp_s1->unk50[i] & ~0x8000);
        }
    }

    if (var_s2) {
        D_800FD470_FE070--;
    }

    if (var_s5) {
        D_8010107C_101C7C--;
    }
}
void func_80038C04_39804(Gfx** arg0, s16 arg1, s32 arg2) {
    switch (arg1) {
        case 0:
        case 1:
            gSPLightColor((*arg0)++, LIGHT_1, arg2);
            break;
        case 2:
            gSPLightColor((*arg0)++, LIGHT_2, arg2);
            break;
        case 3:
            gSPLightColor((*arg0)++, LIGHT_3, arg2);
            break;
        case 4:
            gSPLightColor((*arg0)++, LIGHT_4, arg2);
            break;
        case 5:
            gSPLightColor((*arg0)++, LIGHT_5, arg2);
            break;
        case 6:
            gSPLightColor((*arg0)++, LIGHT_6, arg2);
            break;
        case 7:
            gSPLightColor((*arg0)++, LIGHT_7, arg2);
            break;
        default:
            gSPLightColor((*arg0)++, LIGHT_8, arg2);
            break;
    }
}
extern s16 D_800FA6E4_FB2E4;
s32 func_80039110_39D10(HmfMotionSlot*, HmfData*);
extern u16 D_800DEFC0_DFBC0; /* key frame count */
extern u16 D_800DEFC2_DFBC2; /* key value count */
s16 func_8001DE08_1EA08(void*, s16);
u8* func_8001EA88_1F688(s32, void*, void*);
void* func_8001EB18_1F718(void*);
s32 func_800395F8_3A1F8(HmfMotionSlot*, s16, u8*);
s32 func_800398AC_3A4AC(HmfData*, s16, u8*);
/* A motion file loaded whole (MP1 unk34D80Struct40) */
typedef struct HmfMotionFile {
    /* 0x00 */ char unk00[9];
    /* 0x09 */ u8 unk09; /* track count */
    /* 0x0A */ s16 unk0A; /* length */
    /* 0x0C */ s32 unk0C; /* offsets from the file start: track kinds, */
    /* 0x10 */ s32 unk10; /* key frames, */
    /* 0x14 */ s32 unk14; /* key values, */
    /* 0x18 */ s32 unk18[1]; /* and each track (unk09 of them) */
} HmfMotionFile;
s32 func_80039A88_3A688(HmfMotionSlot*, HmfMotionFile*);
void func_80027274_27E74(s16);
s16 func_80038F30_39B30(HmfData* arg0, u8* arg1, s16 arg2);

/* MP1 func_80038A2C (src/388E0.c) */
void func_80038DD0_399D0(void) {
    s16 i;

    D_800F92B4_F9EB4 = HuMemAlloc(128 * sizeof(HmfMotionSlot));

    for (i = 0; i < 128; i++) {
        D_800F92B4_F9EB4[i].unk02 = -1;
    }
}

/* MP1 func_800341E8 (src/34D80.c) */
s16 func_80038E38_39A38(u8* arg0, HmfData* arg1) {
    s16 i;

    for (i = 0; i < 128; i++) {
        if (D_800F92B4_F9EB4[i].unk02 == -1) {
            break;
        }
    }

    if (i == 128) {
        return -1;
    }

    if (func_80038F30_39B30(arg1, arg0, i) != 0) {
        if (arg1 == NULL) {
            return i;
        }
        arg1->unkA4 = 0;
        return i;
    }

    return -1;
}

/* exact c: marioparty func_800342BC (src/34D80.c) */
s16 func_80038F0C_39B0C(u8* arg0) {
    return func_80038E38_39A38(arg0, NULL);
}

/* MP1 func_800342E0 (src/34D80.c) */
s16 func_80038F30_39B30(HmfData* arg0, u8* arg1, s16 arg2) {
    void* temp_v0;
    s32 temp_s0;
    s32* var_a1;

    var_a1 = (s32*) arg1;

    D_800FA6E4_FB2E4 = arg2 + 10356;
    D_800F92B4_F9EB4[arg2].unk00 = 0;

    if (arg0 != NULL) {
        return func_80039110_39D10(&D_800F92B4_F9EB4[arg2], arg0) != 0;
    }

    temp_s0 = var_a1[1] + 8;
    temp_v0 = func_80027154_27D54(temp_s0, D_800FA6E4_FB2E4);

    bcopy(arg1, temp_v0, temp_s0);
    func_80039A88_3A688(&D_800F92B4_F9EB4[arg2], temp_v0);

    return 1;
}

void func_80039018_39C18(s16 arg0) {
    if (arg0 != 0xFF) {
        func_80027274_27E74(arg0 + 10356);
        D_800F92B4_F9EB4[arg0].unk02 = -1;
    }
}
/* MP1 func_80034420 (src/34D80.c) */
void func_80039074_39C74(void) {
    s16 i;

    for (i = 0; i < 128; i++) {
        if (D_800F92B4_F9EB4[i].unk02 != -1) {
            func_80027274_27E74(i + 10356);
            D_800F92B4_F9EB4[i].unk02 = -1;
        }
    }
}

s32 func_80039110_39D10(HmfMotionSlot* arg0, HmfData* arg1) {
    HmfAnimTrack* temp_v0;
    HmfMotionTrack* sp14;
    s16 sp1E;
    s16 sp26;
    s16 sp2E;
    s16 sp36;
    s16 var_s0;
    s16 var_s5;
    s16 var_s6;
    s16 temp_a0;
    s16 temp_s3;
    f32* sp3C;
    s16* sp44;
    u8* var_s1;
    u8* var_s2;
    s16 i;

    var_s1 = arg1->unk34;
    var_s0 = 0;
    sp2E = 0;

    while (TRUE) {
        var_s1 = func_8001EA88_1F688(0x4D544E31, var_s1, arg1->unk30);
        if (var_s1 == NULL) {
            break;
        }

        temp_a0 = var_s1[2];
        if (temp_a0 == 78 || temp_a0 == 13 || temp_a0 == 8) {
            var_s0 += var_s1[10];
        }
        sp2E++;

        var_s1 = func_8001EB18_1F718(var_s1 + 4);
    }

    if (var_s0 == 0) {
        return 0;
    }

    arg0->unk08 = func_80027154_27D54(var_s0 * sizeof(HmfMotionTrack*), D_800FA6E4_FB2E4);
    arg0->unk0C = func_80027154_27D54(var_s0 * sizeof(u8), D_800FA6E4_FB2E4);
    sp44 = arg0->unk10 = func_80027154_27D54(4096 * sizeof(s16), D_800FA6E4_FB2E4);
    sp3C = arg0->unk14 = func_80027154_27D54(4096 * sizeof(f32), D_800FA6E4_FB2E4);

    D_800DEFC2_DFBC2 = 0;
    D_800DEFC0_DFBC0 = 0;
    sp36 = 0;

    var_s1 = arg1->unk34;
    for (var_s6 = var_s5 = sp1E = 0; sp1E < sp2E; sp1E++) {
        var_s2 = var_s1 = func_8001EA88_1F688(0x4D544E31, var_s1, arg1->unk30);
        sp26 = func_8001DE08_1EA08(arg1, (var_s2[8] << 8) + var_s2[9]);

        temp_s3 = var_s2[10];
        if (temp_s3 != 0) {
            if ((var_s2[11] << 8) + var_s2[12] > sp36) {
                sp36 = (var_s2[11] << 8) + var_s2[12];
            }

            var_s2 += 13;
            sp14 = func_80027154_27D54(temp_s3 * sizeof(HmfMotionTrack), D_800FA6E4_FB2E4);

            for (i = 0; i < temp_s3; i++) {
                temp_a0 = var_s2[2];

                arg0->unk0C[var_s5] = temp_a0;
                arg0->unk08[var_s5] = &sp14[i];

                switch (temp_a0) {
                    case 78:
                        if (func_800395F8_3A1F8(arg0, var_s5, var_s2 + 2) != 0) {
                            var_s5++;
                        }
                        break;
                    case 13:
                        if (func_800395F8_3A1F8(arg0, var_s5, var_s2 + 2) != 0) {
                            arg0->unk08[var_s5]->unk_08 = sp26;
                            if (sp26 == -1) {
                                arg0->unk0C[var_s5] = 78;
                            }
                            var_s5++;
                        }
                        break;
                    case 8:
                        if (var_s6 == 0) {
                            arg1->unk9C = func_80027154_27D54(sizeof(HmfAnim), arg1->unk0E + 1);
                        }
                        if (func_800398AC_3A4AC(arg1, var_s6, var_s2 + 4) != 0) {
                            var_s6++;
                        }
                        break;
                }

                var_s2 += (var_s2[0] << 8) + var_s2[1] + 2;
            }

            var_s1 = func_8001EB18_1F718(var_s1 + 4);
        }
    }

    if (var_s6 != 0) {
        arg1->unk9C->unk00 = var_s6;
        arg1->unk9C->unk08 = 0;

        for (sp1E = i = 0; i < var_s6; i++) {
            temp_v0 = &arg1->unk9C->unk0C[i];
            if (temp_v0->unk06 > sp1E) {
                sp1E = temp_v0->unk06;
            }
        }

        arg1->unk9C->unk04 = sp1E;
        arg1->unk9C->unk02 = 0;
    }

    arg0->unk10 = func_80027154_27D54(D_800DEFC0_DFBC0 * sizeof(s16), D_800FA6E4_FB2E4);
    bcopy(sp44, arg0->unk10, D_800DEFC0_DFBC0 * sizeof(s16));
    HuMemFree(sp44);

    arg0->unk14 = func_80027154_27D54(D_800DEFC2_DFBC2 * sizeof(f32), D_800FA6E4_FB2E4);
    bcopy(sp3C, arg0->unk14, D_800DEFC2_DFBC2 * sizeof(f32));
    HuMemFree(sp3C);

    arg0->unk02 = sp36;
    arg0->unk00 = var_s5;

    return 1;
}
/* MP1 func_80034974 (src/34D80.c; its decomp-permuter shape). Host hazard: kind 35's
   three key values are big-endian floats copied byte by byte */
s32 func_800395F8_3A1F8(HmfMotionSlot *arg0, s16 arg1, u8 *arg2)
{
  HmfMotionTrack *p;
  f32 scale;
  s16 i;
  f32 *var_a3;
  union 
  {
    s32 i;
    f32 f;
  } u;
  p = arg0->unk08[arg1];
  arg1 = *(arg2++);
  p->unk_00 = arg2[0];
  scale = 1.0f;
  p->unk_04 = (arg2[1] << 8) + arg2[2];
  p->unk_06 = (arg2[3] << 8) + arg2[4];
  p->unk_01 = arg2[5];
  if (arg1 == 78)
  {
    p->unk_08 = arg2[6];
    arg2++;
  }
  p->unk_02 = arg2[6];
  arg2 += 7;
  if ((*p).unk_02 == 73)
  {
    p->unk_03 = arg2[0];
    p->unk_0E = arg2[1];
    arg2 += 2;
    p->unk_0A = D_800DEFC0_DFBC0;
    p->unk_0C = D_800DEFC2_DFBC2;
    for (i = 0; i < p->unk_0E; i++)
    {
      arg0->unk10[D_800DEFC0_DFBC0++] = (arg2[0] << 8) + arg2[1];
      if (1)
      {
        u.i = (((arg2[2] << 24) + (arg2[3] << 16)) + (arg2[4] << 8)) + arg2[5];
        arg0->unk14[D_800DEFC2_DFBC2++] = scale * u.f;
      }
      arg2 += 6;
    }

  }
  else
    if (p->unk_02 == 35)
  {
    if (arg1)
    {
      arg2++;
      p->unk_0E = *(arg2++);
      p->unk_0A = D_800DEFC0_DFBC0;
      p->unk_0C = D_800DEFC2_DFBC2;
      var_a3 = &arg0->unk14[D_800DEFC2_DFBC2];
    }
    else
    {
      arg2++;
      p->unk_0E = *(arg2++);
      p->unk_0A = D_800DEFC0_DFBC0;
      p->unk_0C = D_800DEFC2_DFBC2;
      var_a3 = &arg0->unk14[D_800DEFC2_DFBC2];
    }
    for (i = 0; i < p->unk_0E; i++)
    {
      arg0->unk10[D_800DEFC0_DFBC0++] = (arg2[0] << 8) + arg2[1];
      ((u8 *) var_a3)[0] = arg2[2];
      ((u8 *) var_a3)[1] = arg2[3];
      ((u8 *) var_a3)[2] = arg2[4];
      ((u8 *) var_a3)[3] = arg2[5];
      ((u8 *) var_a3)[4] = arg2[6];
      ((u8 *) var_a3)[5] = arg2[7];
      ((u8 *) var_a3)[6] = arg2[8];
      ((u8 *) var_a3)[7] = arg2[9];
      ((u8 *) var_a3)[8] = arg2[10];
      ((u8 *) var_a3)[9] = arg2[11];
      ((u8 *) var_a3)[10] = arg2[12];
      ((u8 *) var_a3)[11] = arg2[13];
      var_a3[0] = scale * var_a3[0];
      var_a3 += 3;
      D_800DEFC2_DFBC2 += 3;
      arg2 += 14;
    }

  }
  return 1;
}
/* same c: marioparty func_80034C28 (src/34D80.c) */
s32 func_800398AC_3A4AC(HmfData* arg0, s16 arg1, u8* arg2) {
    HmfAnimTrack* temp_s3;
    s16 temp_s0;
    s16 var_a3;
    s16 i;

    temp_s3 = &arg0->unk9C->unk0C[arg1];

    temp_s3->unk04 = (arg2[0] << 8) + arg2[1];
    temp_s3->unk00 = (arg2[2] << 8) + arg2[3];

    arg0->unk8C[temp_s3->unk00].unk0C |= 5;

    temp_s0 = temp_s3->unk02 = (arg2[6] << 8) + arg2[7];
    temp_s3->unk08 = func_80027154_27D54(temp_s0 * sizeof(u16), arg0->unk0E + 1);
    temp_s3->unk0C = func_80027154_27D54(temp_s0 * sizeof(s32), arg0->unk0E + 1);

    arg2 += 8;

    for (var_a3 = i = 0; i < temp_s0; i++) {
        ((u8*) &temp_s3->unk0C[i])[0] = arg2[0];
        ((u8*) &temp_s3->unk0C[i])[1] = arg2[1];
        ((u8*) &temp_s3->unk0C[i])[2] = arg2[2];
        ((u8*) &temp_s3->unk0C[i])[3] = arg2[3];

        temp_s3->unk08[i] = (arg2[4] << 8) + arg2[5];
        var_a3 += temp_s3->unk08[i];

        arg2 += 6;
    }

    temp_s3->unk08[i - 1]++;
    temp_s3->unk06 = var_a3 + 1;

    return 1;
}

/* MP1 func_80034E04 (src/34D80.c): point a motion slot into a motion file loaded whole. Host
   hazard: the file's offsets are big-endian words, and its pointers are rebuilt from them */
s32 func_80039A88_3A688(HmfMotionSlot* arg0, HmfMotionFile* arg1) {
    HmfMotionTrack** tracks;
    HmfMotionTrack** var_v1;
    s32* var_a0;
    s16 temp_s3;
    s16 i;

    temp_s3 = arg0->unk00 = arg1->unk09;
    arg0->unk02 = arg1->unk0A;
    arg0->unk0C = (u8*) arg1 + arg1->unk0C;
    arg0->unk10 = (s16*) ((u8*) arg1 + arg1->unk10);
    arg0->unk14 = (f32*) ((u8*) arg1 + arg1->unk14);
    tracks = func_80027154_27D54(temp_s3 * sizeof(HmfMotionTrack*), D_800FA6E4_FB2E4);
    arg0->unk08 = tracks;

    var_a0 = arg1->unk18;
    var_v1 = tracks;
    for (i = 0; i < temp_s3; i++) {
        *var_v1 = (HmfMotionTrack*) ((u8*) arg1 + *var_a0);
        var_v1++;
        var_a0++;
    }

    return 1;
}
/* A Bezier key value (MP1 unk34D80Bezier) */
typedef struct HmfBezierKey {
    /* 0x00 */ f32 v;
    /* 0x04 */ f32 in;
    /* 0x08 */ f32 out;
} HmfBezierKey; /* size = 0xC */
f32 func_8003A154_3AD54(HmfMotionSlot*, HmfMotionTrack*, f32);
f32 func_8003A2B0_3AEB0(HmfMotionSlot*, HmfMotionTrack*, f32);

/* MP1 func_80034ED8 (src/34D80.c): apply a motion's tracks at frame arg1 */
void func_80039B54_3A754(HmfData* arg0, f32 arg1, HmfMotionSlot* arg2, s32 arg3) {
    HitXform* p40;
    HitXform* q;
    HmfMotionObj* p50;
    HmfMotionTrack* e;
    f32* dst;
    s16 i;
    s16 idx;
    s16 n;

    if (arg3 != 0) {
        if (arg0->unk84 == (void*) -1) {
            p40 = arg0->unk6C;
            idx = arg0->unk68;
            for (i = 0; i < idx; i++) {
                if (p40->unk44 != 0) {
                    p40->unk2C = p40->unk08;
                }
                if (p40->unk45 != 0) {
                    p40->unk38 = p40->unk14;
                }
                p40->unk44 = 0;
                p40->unk45 = 0;
                p40++;
            }
        } else {
            p50 = arg0->unk84;
            n = arg0->unk16;
            for (i = 0; i < n; i++) {
                if (p50->unk4C != 0) {
                    p50->unk28 = p50->unk04;
                }
                if (p50->unk4D != 0) {
                    p50->unk34 = p50->unk10;
                }
                if (p50->unk4E != 0) {
                    p50->unk40 = p50->unk1C;
                }
                p50->unk4E = 0;
                p50->unk4D = 0;
                p50->unk4C = 0;
                p50++;
            }
        }
    }

    if (arg2 != (HmfMotionSlot*) -1) {
        n = arg2->unk00;
        for (i = 0; i < n; i++) {
            e = arg2->unk08[i];
            if (e->unk_04 & 0x8000) {
                continue;
            }
            idx = e->unk_08 & 0x7FFF;
            if (idx == 0x7FFF) {
                idx = 0;
            }
            if (arg1 < arg2->unk10[e->unk_0A]) {
                continue;
            }
            switch (arg2->unk0C[i]) {
                case 78:
                    switch (e->unk_00) {
                        case 76:
                            q = &arg0->unk6C[idx];
                            dst = &q->unk38.x;
                            if (e->unk_01 != 'E') {
                                if (e->unk_01 == 'F') {
                                    dst = &q->unk38.y;
                                } else {
                                    dst += 2;
                                }
                            }
                            if (e->unk_02 == 'I') {
                                *dst = func_8003A154_3AD54(arg2, e, arg1);
                            } else {
                                *dst = func_8003A2B0_3AEB0(arg2, e, arg1);
                            }
                            arg0->unk6C[idx].unk45 = 0x80;
                            break;
                        case 79:
                            q = &arg0->unk6C[idx];
                            dst = &q->unk2C.x;
                            if (e->unk_01 != 'E') {
                                if (e->unk_01 == 'F') {
                                    dst = &q->unk2C.y;
                                } else {
                                    dst += 2;
                                }
                            }
                            if (e->unk_02 == 'I') {
                                *dst = func_8003A154_3AD54(arg2, e, arg1);
                            } else {
                                *dst = func_8003A2B0_3AEB0(arg2, e, arg1);
                            }
                            arg0->unk6C[idx].unk44 = 0x80;
                            break;
                        case 23:
                            dst = &arg0->unk6C[idx].unk2C.x;
                            if (e->unk_01 != 'E') {
                                if (e->unk_01 == 'F') {
                                    dst += 1;
                                } else {
                                    dst += 2;
                                }
                            }
                            if (e->unk_02 == 'I') {
                                *dst = func_8003A154_3AD54(arg2, e, arg1);
                            } else {
                                *dst = func_8003A2B0_3AEB0(arg2, e, arg1);
                            }
                            arg0->unk6C[idx].unk44 = 0x80;
                            break;
                    }
                    break;
                case 13:
                    p50 = &arg0->unk84[idx];
                    switch (e->unk_00) {
                        case 23:
                            dst = &p50->unk28.x;
                            if (e->unk_01 == 'F') {
                                dst = &p50->unk28.y;
                            } else if (e->unk_01 == 'G') {
                                dst += 2;
                            }
                            if (e->unk_02 == 'I') {
                                *dst = func_8003A154_3AD54(arg2, e, arg1);
                            } else {
                                *dst = func_8003A2B0_3AEB0(arg2, e, arg1);
                            }
                            p50->unk4C = 0x80;
                            break;
                        case 76:
                            dst = &p50->unk34.x;
                            if (e->unk_01 == 'F') {
                                dst = &p50->unk34.y;
                            } else if (e->unk_01 == 'G') {
                                dst += 2;
                            }
                            if (e->unk_02 == 'I') {
                                *dst = func_8003A154_3AD54(arg2, e, arg1);
                            } else {
                                *dst = func_8003A2B0_3AEB0(arg2, e, arg1);
                            }
                            p50->unk4D = 0x80;
                            break;
                        case 27:
                            dst = &p50->unk40.x;
                            if (e->unk_01 == 'F') {
                                dst = &p50->unk40.y;
                            } else if (e->unk_01 == 'G') {
                                dst += 2;
                            }
                            if (e->unk_02 == 'I') {
                                *dst = func_8003A154_3AD54(arg2, e, arg1);
                            } else {
                                *dst = func_8003A2B0_3AEB0(arg2, e, arg1);
                            }
                            p50->unk4E = 0x80;
                            break;
                    }
                    break;
            }
        }
    }
}

f32 func_8003A154_3AD54(HmfMotionSlot* arg0, HmfMotionTrack* arg1, f32 arg2) {
    f32* vals;
    s16* keys;
    s16 i;
    s16 j;
    s16 d;

    vals = &arg0->unk14[arg1->unk_0C];
    if (arg2 == 0.0f || arg1->unk_0E == 1) {
        return vals[0];
    }
    keys = &arg0->unk10[arg1->unk_0A];
    for (i = 0; i < arg1->unk_0E; i++) {
        if (arg2 < keys[i]) {
            break;
        }
    }
    if (i == arg1->unk_0E) {
        return vals[arg1->unk_0E - 1];
    }
    j = i - 1;
    d = keys[i] - keys[j];
    return (vals[i] - vals[j]) / d * (arg2 - keys[j]) + vals[j];
}
/* func_8003A2B0_3AEB0's doubles (named so the asm build emits them too) */
const f64 D_800D22D0_D2ED0 __attribute__((section(".rodata"))) = 1.0;
const f64 D_800D22D8_D2ED8 __attribute__((section(".rodata"))) = 3.0;

// addu operand order for &keys[i] (raw 1, masked 0; MP1 func_80035630 has the same residue)
#ifdef NON_MATCHING
/* Hermite interpolation of a track's keys (MP1 func_80035630 is a Bezier one). The tangents
   both come from the earlier key (retail) */
f32 func_8003A2B0_3AEB0(HmfMotionSlot* arg0, HmfMotionTrack* arg1, f32 arg2) {
    HmfBezierKey* vals;
    HmfBezierKey* cur;
    HmfBezierKey* prev;
    s16* keys;
    s16* kc;
    s16* kp;
    s16 n;
    s16 i;
    s16 j;
    s16 k0;
    f32 t;
    f32 r;
    f32 r2;
    f32 t2;
    f32 a;
    f32 b;
    f32 h1;
    f32 h2;

    vals = (HmfBezierKey*) &arg0->unk14[arg1->unk_0C];
    if (arg2 == 0.0f || arg1->unk_0E == 1) {
        return vals[0].v;
    }
    keys = &arg0->unk10[arg1->unk_0A];
    n = arg1->unk_0E;
    for (kp = keys, i = 0; i < n; i++) {
        if (arg2 < *kp++) {
            break;
        }
    }
    if (i == n) {
        return vals[arg1->unk_0E - 1].v;
    }
    cur = &vals[i];
    kc = &keys[i];
    j = i - 1;
    prev = &vals[j];
    k0 = keys[j];
    t = arg2 - k0;
    r = D_800D22D0_D2ED0 / (*kc - k0);
    r2 = r * r;
    t2 = t * t;
    a = t2 * r;
    b = t2 * t * r2;
    h1 = 2.0 * b * r;
    h2 = t2 * D_800D22D8_D2ED8 * r2;
    return (h1 - h2 + 1.0f) * prev->v + (-h1 + h2) * cur->v + (b - a - a + t) * prev->in + (b - a) * prev->out;
}
#else
INCLUDE_ASM("asm/nonmatchings/30560", func_8003A2B0_3AEB0);
#endif
/* MP1 func_8003589C (src/34D80.c): blend a second motion into the transforms. One load order
   differs (retail loads -180.0f before *dst in the second wrap test, GCC the reverse, plus a nop);
   everything else is identical */
#ifdef NON_MATCHING
void func_8003A4B8_3B0B8(HmfData* arg0, f32 arg1, f32 arg2) {
    HmfMotionSlot* anim;
    HmfMotionTrack* e;
    HitXform* p40;
    HmfMotionObj* p50;
    f32* dst;
    f32 time;
    f32 w;
    f32 inv;
    f32 val;
    s32 axis;
    u8 f;
    s16 idx;
    s16 i;

    time = arg1;
    w = arg2;
    anim = arg0->unk94;
    inv = 1.0f - w;
    for (i = 0; i < anim->unk00; i++) {
        e = anim->unk08[i];
        if (e->unk_04 & 0x8000) {
            continue;
        }
        idx = e->unk_08 & 0x7FFF;
        if (idx == 0x7FFF) {
            idx = 0;
        }
        if (time < anim->unk10[e->unk_0A]) {
            continue;
        }
        if (e->unk_01 != 'E') {
            axis = 2;
            if (e->unk_01 == 'F') {
                axis = 1;
            }
        } else {
            axis = 0;
        }
        switch (anim->unk0C[i]) {
            case 78:
                switch (e->unk_00) {
                    case 76:
                    dst = &(&arg0->unk6C[idx].unk38.x)[axis];
                    if (e->unk_02 == 'I') {
                        val = func_8003A154_3AD54(anim, e, time);
                    } else {
                        val = func_8003A2B0_3AEB0(anim, e, time);
                    }
                    if (val < -180.0f) {
                        val += 360.0f;
                    }
                    if (*dst < -180.0f) {
                        *dst += 360.0f;
                    }
                    if (val > 180.0f) {
                        val -= 360.0f;
                    }
                    if (*dst > 180.0f) {
                        *dst -= 360.0f;
                    }
                    *dst = inv * *dst + val * w;
                    arg0->unk6C[idx].unk45 |= (1 << axis) | 0x40;
                    break;
                    case 79:
                    dst = &(&arg0->unk6C[idx].unk2C.x)[axis];
                    if (e->unk_02 == 'I') {
                        val = func_8003A154_3AD54(anim, e, time);
                    } else {
                        val = func_8003A2B0_3AEB0(anim, e, time);
                    }
                    *dst = inv * *dst + val * w;
                    arg0->unk6C[idx].unk44 |= (1 << axis) | 0x40;
                    break;
                }
                break;
            case 13:
                switch (e->unk_00) {
                    case 23:
                    dst = &(&arg0->unk84[idx].unk28.x)[axis];
                    if (e->unk_02 == 'I') {
                        val = func_8003A154_3AD54(anim, e, time);
                    } else {
                        val = func_8003A2B0_3AEB0(anim, e, time);
                    }
                    *dst = inv * *dst + val * w;
                    arg0->unk84[idx].unk4C |= (1 << axis) | 0x40;
                    break;
                    case 76:
                    dst = &(&arg0->unk84[idx].unk34.x)[axis];
                    if (e->unk_02 == 'I') {
                        val = func_8003A154_3AD54(anim, e, time);
                    } else {
                        val = func_8003A2B0_3AEB0(anim, e, time);
                    }
                    if (val < 0.0f) {
                        val += 360.0f;
                    }
                    if (*dst < 0.0f) {
                        *dst += 360.0f;
                    }
                    if (val < 180.0f) {
                        if (val + 180.0f < *dst) {
                            *dst -= 360.0f;
                        }
                    } else if (*dst < val - 180.0f) {
                        val -= 360.0f;
                    }
                    *dst = inv * *dst + val * w;
                    arg0->unk84[idx].unk4D |= (1 << axis) | 0x40;
                    break;
                    case 27:
                    dst = &(&arg0->unk84[idx].unk40.x)[axis];
                    if (e->unk_02 == 'I') {
                        val = func_8003A154_3AD54(anim, e, time);
                    } else {
                        val = func_8003A2B0_3AEB0(anim, e, time);
                    }
                    *dst = inv * *dst + val * w;
                    arg0->unk84[idx].unk4E |= (1 << axis) | 0x40;
                    break;
                }
                break;
        }
    }

    if (arg0->unk84 == (void*) -1) {
        p40 = arg0->unk6C;
        idx = arg0->unk68;
        for (i = 0; i < idx; i++) {
            if (p40->unk44 != 0) {
            f = p40->unk44;
            dst = &p40->unk2C.x;
            if (!(f & 0x40)) {
                dst[0] = inv * dst[0] + w * p40->unk08.x;
                dst[1] = inv * dst[1] + w * p40->unk08.y;
                dst[2] = inv * dst[2] + w * p40->unk08.z;
            } else {
                if (!(f & 1)) {
                    dst[0] = inv * dst[0] + w * p40->unk08.x;
                }
                if (!(f & 2)) {
                    dst[1] = inv * dst[1] + w * p40->unk08.y;
                }
                if (!(f & 4)) {
                    dst[2] = inv * dst[2] + w * p40->unk08.z;
                }
            }
        }
            if (p40->unk45 != 0) {
            f = p40->unk45;
            dst = &p40->unk38.x;
            if (!(f & 0x40)) {
                dst[0] = inv * dst[0] + w * p40->unk14.x;
                dst[1] = inv * dst[1] + w * p40->unk14.y;
                dst[2] = inv * dst[2] + w * p40->unk14.z;
            } else {
                if (!(f & 1)) {
                    dst[0] = inv * dst[0] + w * p40->unk14.x;
                }
                if (!(f & 2)) {
                    dst[1] = inv * dst[1] + w * p40->unk14.y;
                }
                if (!(f & 4)) {
                    dst[2] = inv * dst[2] + w * p40->unk14.z;
                }
            }
        }
            p40++;
        }
    } else {
        for (i = 0; i < arg0->unk16; i++) {
            p50 = &arg0->unk84[i];
            if (p50->unk4C != 0) {
            f = p50->unk4C;
            dst = &p50->unk28.x;
            if (!(f & 0x40)) {
                dst[0] = inv * dst[0] + w * p50->unk04.x;
                dst[1] = inv * dst[1] + w * p50->unk04.y;
                dst[2] = inv * dst[2] + w * p50->unk04.z;
            } else {
                if (!(f & 1)) {
                    dst[0] = inv * dst[0] + w * p50->unk04.x;
                }
                if (!(f & 2)) {
                    dst[1] = inv * dst[1] + w * p50->unk04.y;
                }
                if (!(f & 4)) {
                    dst[2] = inv * dst[2] + w * p50->unk04.z;
                }
            }
        }
            if (p50->unk4D != 0) {
            f = p50->unk4D;
            dst = &p50->unk34.x;
            if (!(f & 0x40)) {
                dst[0] = inv * dst[0] + w * p50->unk10.x;
                dst[1] = inv * dst[1] + w * p50->unk10.y;
                dst[2] = inv * dst[2] + w * p50->unk10.z;
            } else {
                if (!(f & 1)) {
                    dst[0] = inv * dst[0] + w * p50->unk10.x;
                }
                if (!(f & 2)) {
                    dst[1] = inv * dst[1] + w * p50->unk10.y;
                }
                if (!(f & 4)) {
                    dst[2] = inv * dst[2] + w * p50->unk10.z;
                }
            }
        }
            if (p50->unk4E != 0) {
            f = p50->unk4E;
            dst = &p50->unk40.x;
            if (!(f & 0x40)) {
                dst[0] = inv * dst[0] + w * p50->unk1C.x;
                dst[1] = inv * dst[1] + w * p50->unk1C.y;
                dst[2] = inv * dst[2] + w * p50->unk1C.z;
            } else {
                if (!(f & 1)) {
                    dst[0] = inv * dst[0] + w * p50->unk1C.x;
                }
                if (!(f & 2)) {
                    dst[1] = inv * dst[1] + w * p50->unk1C.y;
                }
                if (!(f & 4)) {
                    dst[2] = inv * dst[2] + w * p50->unk1C.z;
                }
            }
        }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/30560", func_8003A4B8_3B0B8);
#endif
#define B4_DUR(p, k) (((s16*) (p)->unk08)[k])
#define B4_COL(p, k) ((u8*) (p)->unk0C + (k) * 4)

/* MP1 func_800363C8 (src/34D80.c): material colour animation */
s32 func_8003AFF4_3BBF4(HmfData* arg0) {
    HmfAnimTrack* p;
    s16 frame;
    s16 sum;
    s16 rem;
    s16 i;
    s16 j;
    s16 k;
    f32 d;

    for (i = 0; i < arg0->unk9C->unk00; i++) {
        p = &arg0->unk9C->unk0C[i];
        frame = arg0->unk9C->unk08;
        sum = 0;
        for (k = 0; k < p->unk02; k++) {
            sum += B4_DUR(p, k);
            if (sum >= frame) {
                break;
            }
        }
        if (k < p->unk02 - 1) {
            rem = frame - (sum - B4_DUR(p, k));
            d = B4_COL(p, k)[4] - B4_COL(p, k)[0];
            arg0->unk8C[p->unk00].unk05[0] = B4_COL(p, k)[0] + d / B4_DUR(p, k) * rem;
            d = B4_COL(p, k)[5] - B4_COL(p, k)[1];
            arg0->unk8C[p->unk00].unk05[1] = B4_COL(p, k)[1] + d / B4_DUR(p, k) * rem;
            d = B4_COL(p, k)[6] - B4_COL(p, k)[2];
            arg0->unk8C[p->unk00].unk05[2] = B4_COL(p, k)[2] + d / B4_DUR(p, k) * rem;
            d = B4_COL(p, k)[7] - B4_COL(p, k)[3];
            d = B4_COL(p, k)[3] + d / B4_DUR(p, k) * rem;
        } else {
            arg0->unk8C[p->unk00].unk05[0] = B4_COL(p, k)[0];
            arg0->unk8C[p->unk00].unk05[1] = B4_COL(p, k)[1];
            arg0->unk8C[p->unk00].unk05[2] = B4_COL(p, k)[2];
            d = B4_COL(p, k)[3];
        }
        for (j = 0; j < arg0->unk10; j++) {
            if (arg0->unk64[j].unk00 == p->unk00) {
                arg0->unk64[j].unk02 = d;
            }
        }
    }
    return 1;
}

/* same c: marioparty func_800368AC (src/34D80.c) */
void func_8003B4D8_3C0D8(HmfData* arg0, f32 arg1) {
    if (!(arg0->unk9C->unk02 & 1)) {
        arg0->unk9C->unk08 += arg1;
        if (arg0->unk9C->unk04 <= arg0->unk9C->unk08) {
            if (arg0->unk9C->unk02 & 2) {
                arg0->unk9C->unk08 = 0.0f;
            } else {
                arg0->unk9C->unk08 = arg0->unk9C->unk04;
            }
        }
    }
}

/* same c: marioparty func_80036930 (src/34D80.c) */
void func_8003B55C_3C15C(HmfData* arg0, f32 arg1) {
    arg0->unkA4 += arg1;
    if (((HmfMotionSlot*)arg0->unk90)->unk02 <= arg0->unkA4) {
        if (D_800CAD20_CB920 != 0) {
            arg0->unkA4 = 0.0f;
        } else {
            arg0->unkA4 = ((HmfMotionSlot*)arg0->unk90)->unk02;
        }
    }
}

/* same c: marioparty func_800369A0 (src/34D80.c) */
void func_8003B5CC_3C1CC(HmfData* arg0, f32 arg1) {
    arg0->unkA4 -= arg1;
    if (arg0->unkA4 < 0.0f) {
        if (D_800CAD20_CB920 != 0) {
            arg0->unkA4 = ((HmfMotionSlot*)arg0->unk90)->unk02;
        } else {
            arg0->unkA4 = 0.0f;
        }
    }
}

/* exact c: marioparty func_800369FC (src/34D80.c) */
f32 func_8003B628_3C228(HmfMotionSlot* arg0, s16 arg1, f32 arg2, f32 arg3, f32 arg4) {
    arg4 *= D_800CA028_CAC28;
    if (!(arg1 & 9)) {
        if (!(arg1 & 4)) {
            arg2 += arg4;
            if (arg0->unk02 <= arg2) {
                if (arg1 & 2) {
                    return arg3;
                }
                return arg0->unk02;
            }
        } else {
            arg2 -= arg4;
            if (arg2 < arg3) {
                if (arg1 & 2) {
                    return arg0->unk02 - arg4;
                }
                return arg3;
            }
        }
    }
    return arg2;
}

void func_8003B6E8_3C2E8(HmfData* arg0) {
    arg0->unkA4 = 0.0f;
}
/* same c: marioparty func_80036AC4 (src/34D80.c) */
void func_8003B6F0_3C2F0(HmfData* arg0) {
    arg0->unkA4 = ((HmfMotionSlot*)arg0->unk90)->unk02 - 1;
}

/* same c: marioparty func_80036AE4 (src/34D80.c) */
s16 func_8003B710_3C310(HmfData* arg0) {
    return arg0->unkA4;
}

/* Retail calls func_8003B7A8_3C3A8 unprototyped here (its flag argument arrives as the int
   -0x8000; its definition reads it as u16) */
void func_8003B72C_3C32C(s16 arg0, s16 arg1, char* arg2, s16 arg3, s16 arg4) {
    ((void (*)()) func_8003B7A8_3C3A8)(arg0, arg1, arg2, arg3, arg4, -0x8000);
}
void func_8003B76C_3C36C(s16 arg0, s16 arg1, char* arg2, s16 arg3, s16 arg4) {
    ((void (*)()) func_8003B7A8_3C3A8)(arg0, arg1, arg2, arg3, arg4, 0);
}
/* Set the off flag (0x8000) of model arg0's motion arg1 track for the motion object holding
   part arg2, channel arg3, axis arg4 */
void func_8003B7A8_3C3A8(s16 arg0, s16 arg1, char* arg2, s16 arg3, u16 arg4, u16 arg5) {
    HmfMotionSlot* slot;
    HmfData* hmf;
    HmfMotionTrack* e;
    s16 part;
    s16 i;
    s16 j;

    slot = &D_800F92B4_F9EB4[arg1];
    hmf = D_800FC834_FD434[arg0].hmf;
    part = func_80038398_38F98(hmf, arg2);

    for (i = 0; i < hmf->unk16; i++) {
        for (j = 0; j < hmf->unk84[i].unk00; j++) {
            if (hmf->unk84[i].unk50[j] == part) {
                break;
            }
        }
        if (j != hmf->unk84[i].unk00) {
            break;
        }
    }

    for (j = 0; j < slot->unk00; j++) {
        e = slot->unk08[j];
        if ((e->unk_08 & 0x7FFF) == i && e->unk_00 == arg3 && e->unk_01 == (s16) arg4) {
            e->unk_04 = arg5 | (e->unk_04 & 0x7FFF);
            return;
        }
    }
}
void func_8003B9D0_3C5D0(void) {
    s16 i;

    D_801016C4_1022C4 = HuMemAlloc(16 * sizeof(HmfTexAnimSlot));
    for (i = 0; i < 16; i++) {
        D_801016C4_1022C4[i].unk08 = NULL;
    }
}
s16 func_8003BA2C_3C62C(void* arg0, u8* arg1) {
    HmfTexAnimSlot* temp_a0;
    s16 i;

    for (i = 0; i < 16; i++) {
        if (D_801016C4_1022C4[i].unk08 == NULL) {
            break;
        }
    }
    if (i == 16) {
        return -1;
    }
    temp_a0 = &D_801016C4_1022C4[i];
    temp_a0->unk00 = arg0;
    temp_a0->unk04 = arg1;
    temp_a0->unk0C = (arg1[8] << 8) + arg1[9];
    temp_a0->unk0E = (arg1[10] << 8) + arg1[11];
    temp_a0->unk08 = arg1 + 12;
    return i;
}
void func_8003BAD8_3C6D8(s32 arg0) {
    D_801016C4_1022C4[arg0].unk08 = NULL;
}
void func_8003BAF0_3C6F0(void) {
    s16 i;

    for (i = 0; i < 16; i++) {
        if (D_801016C4_1022C4[i].unk08 != NULL) {
            func_8003BAD8_3C6D8(i);
        }
    }
}
void func_8003BB58_3C758(HmfData* arg0) {
    HmfVtxCopy* c;
    HmfVtx* v;
    ColVtx* pos;
    u8* col;
    s16 n;
    s16 i;

    if (arg0->unk5C != NULL) {
        c = arg0->unk5C;
        HuMemFree(c->unk04);
        HuMemFree(c->unk08);
        HuMemFree(c->unk0C);
        HuMemFree(c);
    }

    n = arg0->unk18;
    c = func_80027154_27D54(sizeof(HmfVtxCopy), D_800FA1AA_FADAA);
    arg0->unk5C = c;
    c->unk00 = n;
    pos = func_80027154_27D54(n * sizeof(ColVtx), D_800FA1AA_FADAA);
    c->unk04 = pos;
    col = func_80027154_27D54(n * 3, D_800FA1AA_FADAA);
    c->unk08 = col;
    c->unk0C = func_80027154_27D54((n + 7) / 8, D_800FA1AA_FADAA);

    v = arg0->unk40;
    for (i = 0; i < n; i++) {
        pos->x = v->unk00;
        pos->y = v->unk02;
        pos->z = v->unk04;
        col[0] = v->unk0C[0];
        col[1] = v->unk0C[1];
        col[2] = v->unk0C[2];
        v++;
        pos++;
        col += 3;
    }
}
void func_8003BCBC_3C8BC(HmfModel* arg0, f32 arg1) {
    HmfData* temp_a0 = arg0->hmf;

    if (temp_a0->unkB8 != NULL) {
        func_8003C6AC_3D2AC(temp_a0, arg1);
        return;
    }
    func_8003BD08_3C908(temp_a0, arg0->unk08, arg1);
}
/* Fresh (no MP1/MP3 C): decode model arg0's packed vertex animation (D_801016C4_1022C4 slot
   arg1) at time arg2 into its vertex copy (unk5C), then write this frame's vertex buffer. Per
   vertex entry: bits 0-11 the vertex, 14-15 the position delta (3 nibbles, 3 bytes, 3 absolute
   16-bit adds, none), 12-13 the colour delta. Retail advances the colour pointer of the final copy
   only past non-black colours (kept). Not matching yet: block layout and types of the nibble
   reader, the frame (retail 0x10, here 8) */
#ifdef NON_MATCHING
void func_8003BD08_3C908(HmfData* arg0, s16 arg1, f32 arg2) {
    HmfTexAnimSlot* slot;
    HmfVtxCopy* c;
    HmfVtx* v;
    ColVtx* pos;
    ColVtx* pv;
    s8* col;
    s8* pc;
    u8* q;
    u8* ent;
    u8* p;
    f32 frame;
    u16 e;
    u16 vi;
    s32 t;
    u16 sv;
    u8 by;
    u8 bit;
    u8 half;
    s16 rd;
    s16 n;
    s16 count;
    s16 f;
    s16 i;

    slot = &D_801016C4_1022C4[arg1];
    c = arg0->unk5C;
    frame = arg2 / slot->unk0E;
    if (slot->unk0C - 1 <= frame) {
        frame = slot->unk0C - 1;
    }
    f = frame;
    count = (slot->unk08[f * 4] << 8) + slot->unk08[f * 4 + 1];
    ent = slot->unk08 + slot->unk0C * 4;
    q = slot->unk08;
    for (i = 0; i < f; i++) {
        ent += ((q[0] << 8) + q[1]) * 2 + (q[2] << 8) + q[3];
        q += 4;
    }
    p = ent + count * 2;

    if (f != arg0->unk5C->unk02) {
        pos = c->unk04;
        col = (s8*) c->unk08;
        n = c->unk00;
        if (f == 0) {
            v = arg0->unk40;
            for (i = 0; i < n; i++) {
                pos->x = v->unk00;
                pos->y = v->unk02;
                pos->z = v->unk04;
                col[0] = v->unk0C[0];
                col[1] = v->unk0C[1];
                col[2] = v->unk0C[2];
                v++;
                pos++;
                col += 3;
            }
        }
        for (i = 0; i < (n + 7) / 8; i++) {
            c->unk0C[i] = 0;
        }
        pos = c->unk04;
        col = (s8*) c->unk08;
        half = 0;
        for (i = 0; i < count; i++) {
            e = (ent[0] << 8) + ent[1];
            vi = e & 0xFFF;
            sv = arg0->unk60[vi];
            bit = 1 << (sv & 7);
            by = sv >> 3;
            if (c->unk0C[by] & bit) {
                /* this vertex was already set this frame: skip its data */
                t = e & 0xC000;
                if (t != 0xC000) {
                    if (t == 0x8000) {
                        p = p + 1 + (half != 0);
                        half ^= 1;
                    } else if ((e & 0xC000) != 0x4000) {
                        p += 6;
                    } else {
                        p += 3;
                    }
                }
                t = e & 0x3000;
                if (t != 0x2000) {
                    if (t != 0x1000) {
                        p += 3;
                    } else {
                        p = p + 1 + (half != 0);
                        half ^= 1;
                    }
                }
            } else {
                c->unk0C[by] |= bit;
                pv = &pos[arg0->unk60[vi]];
                t = e & 0xC000;
                if (t != 0xC000) {
                    if (t == 0x8000) {
                        HMF_RD4(rd);
                        pv->x += HMF_S4(rd);
                        HMF_RD4(rd);
                        pv->y += HMF_S4(rd);
                        HMF_RD4(rd);
                        pv->z += HMF_S4(rd);
                    } else if (t == 0x4000) {
                        HMF_RD8(rd);
                        pv->x += HMF_S8(rd);
                        HMF_RD8(rd);
                        pv->y += HMF_S8(rd);
                        HMF_RD8(rd);
                        pv->z += HMF_S8(rd);
                    } else {
                        HMF_RD8(rd);
                        sv = rd << 8;
                        HMF_RD8(rd);
                        pv->x += (u16) (sv | rd);
                        HMF_RD8(rd);
                        sv = rd << 8;
                        HMF_RD8(rd);
                        pv->y += (u16) (sv | rd);
                        HMF_RD8(rd);
                        sv = rd << 8;
                        HMF_RD8(rd);
                        pv->z += (u16) (sv | rd);
                    }
                }
                pc = &col[arg0->unk60[vi] * 3];
                t = e & 0x3000;
                if (t != 0x2000) {
                    if (t == 0x1000) {
                        HMF_RD4(rd);
                        pc[0] += HMF_S4(rd);
                        HMF_RD4(rd);
                        pc[1] += HMF_S4(rd);
                        HMF_RD4(rd);
                        pc[2] += HMF_S4(rd);
                    } else {
                        HMF_RD8(rd);
                        pc[0] += rd;
                        HMF_RD8(rd);
                        pc[1] += rd;
                        HMF_RD8(rd);
                        pc[2] += rd;
                    }
                }
            }
            ent += 2;
        }
    } else {
        pos = c->unk04;
        col = (s8*) c->unk08;
    }

    v = arg0->unk44[D_800FDBE0_FE7E0];
    n = arg0->unk18;
    for (i = 0; i < n; i++) {
        v->unk00 = pos->x;
        v->unk02 = pos->y;
        v->unk04 = pos->z;
        if (col[0] != 0 || col[1] != 0 || col[2] != 0) {
            v->unk0C[0] = col[0];
            v->unk0C[1] = col[1];
            v->unk0C[2] = col[2];
            col += 3;
        }
        v++;
        pos++;
    }
    arg0->unk5C->unk02 = f;
}
#else
INCLUDE_ASM("asm/nonmatchings/30560", func_8003BD08_3C908);
#endif
// register allocation only (masked 0)
#ifdef NON_MATCHING
/* Apply the morph targets of the current frame arg1 to this frame's vertex buffer */
void func_8003C6AC_3D2AC(HmfData* arg0, f32 arg1) {
    HmfMorph* m;
    HmfVtx* dst;
    HmfVtx* src;
    HmfVtx* v;
    s16* idx;
    ColVtx* pos;
    s8* col;
    s16 n;
    s16 i;
    s16 j;

    if (arg0->unkB8 != NULL) {
        if (arg0->unkBC != NULL) {
            src = arg0->unk40;
            dst = arg0->unk44[D_800FDBE0_FE7E0];
            n = arg0->unk18;
            for (i = 0; i < n; i++) {
                *dst = *src;
                src++;
                dst++;
            }
            dst = arg0->unk44[D_800FDBE0_FE7E0];
            if (((HmfMorphAnim*) arg0->unkBC)->unk02 - 1 <= arg1) {
                arg1 = ((HmfMorphAnim*) arg0->unkBC)->unk02 - 1;
            }
            for (i = 0; i < arg0->unk22; i++) {
                m = &((HmfMorph*) arg0->unkB8)[((HmfMorphAnim*) arg0->unkBC)[i].unk04[(s16) arg1]];
                idx = m->unk28;
                pos = m->unk2C;
                col = (s8*) m->unk30;
                n = m->unk1C;
                for (j = 0; j < n; j++) {
                    v = &dst[arg0->unk60[*idx]];
                    v->unk00 = pos->x;
                    v->unk02 = pos->y;
                    v->unk04 = pos->z;
                    if (col[0] != 0 || col[1] != 0 || col[2] != 0) {
                        v->unk0C[0] = col[0];
                        v->unk0C[1] = col[1];
                        v->unk0C[2] = col[2];
                    }
                    idx++;
                    pos++;
                    col += 3;
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/30560", func_8003C6AC_3D2AC);
#endif
