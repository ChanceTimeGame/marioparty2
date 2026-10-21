#include "common.h"

#include "game/malloc.h"
#include "game/data.h"
#include "engine/siman.h"
#include "game/pad.h"
#include "game/si.h"
#include "game/sprite.h"

/* Window system, rumble and the queued-input ring (MP1 src/6C470.c, src/6D4E0.c, src/388E0.c, MP3
   src/window.c). MP2's TextWindow has MP3's layout (0x27C bytes). MP2's names are kept. */

typedef struct Unk6C470Part {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
    /* 0x0C */ f32 radius;
    /* 0x10 */ f32 angle;
    /* 0x14 */ f32 scale;
    /* 0x18 */ s16 state;
    /* 0x1A */ s16 timer;
} Unk6C470Part; // size 0x1C

typedef struct Unk6C470Work {
    /* 0x000 */ s32 unk0;
    /* 0x004 */ void (*func4)(void);
    /* 0x008 */ void (*func8)(omObjData*);
    /* 0x00C */ void (*funcC)(omObjData*);
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01C */ f32 unk1C;
    /* 0x020 */ s32 unk20;
    /* 0x024 */ Unk6C470Part parts[10];
    /* 0x13C */ Unk6C470Part parts2[10];
    /* 0x254 */ s16 sprites[23];
    /* 0x282 */ u16 unk282;
    /* 0x284 */ u16 unk284;
    /* 0x286 */ u16 unk286;
    /* 0x288 */ u16 unk288;
    /* 0x28A */ u16 unk28A;
    /* 0x28C */ u16 unk28C;
    /* 0x28E */ u16 unk28E;
} Unk6C470Work; // size 0x290

typedef struct RumbleState {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA;
} RumbleState; // size 0xC


typedef struct TWInput {
    /* 0x00 */ s16 v[4];
    /* 0x08 */ s16 count;
} TWInput; // size 0xA

typedef struct TWEntry {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ char unk1;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA;
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s16 unkE;
} TWEntry; // size 0x10 (MP1 SubTextWindow)

typedef struct TextWindow {
    /* 0x000 */ u16 unk_00[0x10]; /* palette (RGBA5551), copied from D_800CD874_CE474 */
    /* 0x020 */ u8 unk20;
    /* 0x021 */ s8 unk21;
    /* 0x022 */ u8 unk22; /* text colour */
    /* 0x023 */ s8 unk23;
    /* 0x024 */ u8 unk24; /* current unkE0 buffer */
    /* 0x025 */ u8 unk25;
    /* 0x026 */ u8 unk26;
    /* 0x027 */ u8 unk27;
    /* 0x028 */ u8 unk28;
    /* 0x029 */ u8 unk29;
    /* 0x02A */ u8 unk2A; /* line spacing */
    /* 0x02B */ char pad2B[2];
    /* 0x02D */ u8 unk_2D;
    /* 0x02E */ u8 unk_2E;
    /* 0x02F */ u8 unk_2F;
    /* 0x030 */ s8 unk_30;
    /* 0x031 */ s8 unk_31;
    /* 0x032 */ s8 unk32;
    /* 0x033 */ s8 unk33;
    /* 0x034 */ u8 unk34; /* character spacing */
    /* 0x035 */ u8 unk35; /* tab width */
    /* 0x036 */ char pad36[2];
    /* 0x038 */ u32 unk_38;
    /* 0x03C */ u16 unk3C; /* x */
    /* 0x03E */ u16 unk3E; /* y */
    /* 0x040 */ s16 unk40; /* width */
    /* 0x042 */ s16 unk42; /* height */
    /* 0x044 */ s16 unk44;
    /* 0x046 */ s16 unk46;
    /* 0x048 */ s16 unk48;
    /* 0x04A */ s16 unk4A;
    /* 0x04C */ s16 unk4C;
    /* 0x04E */ s16 unk4E;
    /* 0x050 */ s16 unk50;
    /* 0x052 */ s16 unk52;
    /* 0x054 */ s16 unk54;
    /* 0x056 */ s16 unk56;
    /* 0x058 */ s16 unk58;
    /* 0x05A */ s16 unk5A;
    /* 0x05C */ s16 unk5C;
    /* 0x05E */ s16 unk5E; /* -1 = free */
    /* 0x060 */ u16 unk60; /* sprite priority */
    /* 0x062 */ s16 unk62; /* previous window in the list */
    /* 0x064 */ s16 unk64; /* next window in the list */
    /* 0x066 */ s16 unk66;
    /* 0x068 */ s16 unk68;
    /* 0x06A */ s16 unk6A;
    /* 0x06C */ s16 unk_6C; /* sprite group */
    /* 0x06E */ s16 unk_6E[0x16];
    /* 0x09A */ s16 unk9A;
    /* 0x09C */ char pad9C[0xA];
    /* 0x0A6 */ s16 unkA6;
    /* 0x0A8 */ char padA8[2];
    /* 0x0AA */ s16 unkAA;
    /* 0x0AC */ s8 unkAC;
    /* 0x0AD */ s8 usingStringIDBool[5];
    /* 0x0B2 */ s8 unk_B2[6];
    /* 0x0B8 */ void* unk_B8[5];
    /* 0x0CC */ u8* unkCC; /* text being shown */
    /* 0x0D0 */ void* unkD0; /* text read from the message file, or NULL */
    /* 0x0D4 */ u8 unkD4; /* unkD0 must be freed */
    /* 0x0D5 */ char padD5[3];
    /* 0x0D8 */ u8* unkD8; /* where the text resumes after an inserted string */
    /* 0x0DC */ u8* unkDC; /* window image (4-bit) */
    /* 0x0E0 */ u8* unkE0[3]; /* triple-buffered text image (4-bit) */
    /* 0x0EC */ f32 unkEC;
    /* 0x0F0 */ f32 unkF0;
    /* 0x0F4 */ TWEntry unk_F4[0x18];
    /* 0x274 */ s16 unk274;
    /* 0x276 */ s16 unk276;
    /* 0x278 */ char pad278[4];
} TextWindow; // size 0x27C

extern s16 D_800ED6B0_EE2B0[4];
extern OSPfs D_800ED6C0_EE2C0[4];
extern RumbleState D_800ED860_EE460[4];
extern RumbleState D_800ED862_EE462[]; /* label for D_800ED860_EE460[0].unk2 */
extern functionListEntry D_800ED890_EE490;
extern functionListEntry D_800ED89C_EE49C;
extern s16 D_800ED8A8_EE4A8;
extern OSMesgQueue D_800FA5E0_FB1E0;
extern TextWindow* D_800F920C_F9E0C;
extern TWInput D_800FA048_FAC48[32];
extern TWInput D_800FA04A_FAC4A[]; /* labels for the fields of D_800FA048_FAC48[0] */
extern TWInput D_800FA04C_FAC4C[];
extern TWInput D_800FA04E_FAC4E[];
extern TWInput D_800FA050_FAC50[];
extern u8 D_800FD808_FE408;
extern u8 D_801026D4_1032D4;
extern u8 D_800CDA98_CE698[];
extern u8* D_800CDAB0_CE6B0[];
extern s8 D_800ED8E6_EE4E6;
extern s8 D_801013FA_101FFA;

void func_800873D8_87FD8(omObjData* obj);
s32 func_800877FC_883FC(omObjData* obj);
void func_80087D4C_8894C(omObjData* obj);
void func_80087F48_88B48(omObjData* obj);
void* func_80027154_27D54(s32 size, s32 tag);
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size);
void func_80029714_2A314(s16, f32, f32, f32);
void func_8002979C_2A39C(s16, f32, f32, f32);
void func_800297E8_2A3E8(s16, f32, f32, f32);
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029C74_2A874(s16, f32);
f32 func_80029CE4_2A8E4(s16);
f32 func_80029D0C_2A90C(s16);
s16 PlaySound(s16);
s32 __osMotorAccess(OSPfs* pfs, s32 flag);
s32 osMotorInit(OSMesgQueue*, OSPfs*, int);
void func_8007EB8C_7F78C(functionListEntry* entry, s16 type, void* func);
void func_80088540_89140(s16* arg0);
s32 func_800883B8_88FB8(s16* arg0);
void func_80068D24_69924(void* file);
void* func_80068CD4_698D4(s32 stringIndex);
s16 SprAnimRead(void*);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprPosSet(s16 group, s16 member, s16 x, s16 y);
void func_800824F4_830F4(s16 grpIdx, s16 idx, s16 arg2);
void SprAnimKill(s16);
s16 func_800896A0_8A2A0(s16, s16);
void SprRotSet(s16 grpIdx, s16 idx, f32 rot);
void SprAttrSet(s16 grpIdx, s16 idx, s32 flag);
f32 HuMathSin(f32);
void func_80089764_8A364(s16, f32, f32);
void func_8008D5D8_8E1D8(s16);
void SprAttrReset(s16 grpIdx, s16 idx, s32 flag);
void func_80082488_83088(s16 grpIdx, s16 idx, u16 a);
void func_80082450_83050(s16 grpIdx, s32 idx, s32 r, s32 g, u8 b);
void func_8008A834_8B434(TextWindow* arg0);
void func_8008B66C_8C26C(TextWindow* arg0);
void func_8008D0BC_8DCBC(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
u8 func_8008D3C8_8DFC8(u8* arg0);
void func_8008CCA8_8D8A8(s16);

void func_8008DCDC_8E8DC(s32);
extern u16 D_800ED8E8_EE4E8;
extern u8 D_800ED8E9_EE4E9;
extern u16 D_800ED8EA_EE4EA;
extern u8 D_8010106E_101C6E[5];

typedef struct SprPoint {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
} SprPoint; // size 0x8

/* HuSprite's unk_04, unk_08 (screen position) and unk_20 (rotation) hold floats, though the header
   types them s32 (as in 80230.c). */
#define SPR_F(s, f) (*(f32*)&(s)->f)

extern SprPoint D_800ED660_EE260[4]; /* corners of the sprite being checked */
f32 func_800B7890_B8490(f32); /* HuMathCos */
s32 DispCheck(SprPoint* p);

s32 SprDispCheck(HuSprite* obj) {
    HuSprite_Unk84_Unk00_Struct* cel;
    f32 s;
    f32 c;
    f32 x0;
    f32 y0;
    f32 x1;
    f32 y1;

    cel = &obj->unk_84->unk00[obj->unk_90];
    s = HuMathSin(SPR_F(obj, unk_20));
    c = func_800B7890_B8490(SPR_F(obj, unk_20));
    if (!(obj->unk_24 & 0x10000)) {
        x0 = -(u16)cel->unk08 * obj->unk_18;
        y0 = -(u16)cel->unk0A * obj->unk_1C;
        x1 = (cel->unk04 - (u16)cel->unk08) * obj->unk_18;
        y1 = (cel->unk06 - (u16)cel->unk0A) * obj->unk_1C;
    } else {
        x0 = obj->unk_3C;
        y0 = obj->unk_3E;
        x1 = (s16)obj->unk_40;
        y1 = (s16)obj->unk_42;
    }
    D_800ED660_EE260[0].x = c * x0 + s * y0 + SPR_F(obj, unk_04);
    D_800ED660_EE260[0].y = -s * x0 + c * y0 + SPR_F(obj, unk_08);
    D_800ED660_EE260[1].x = c * x1 + s * y0 + SPR_F(obj, unk_04);
    D_800ED660_EE260[1].y = -s * x1 + c * y0 + SPR_F(obj, unk_08);
    D_800ED660_EE260[2].x = c * x1 + s * y1 + SPR_F(obj, unk_04);
    D_800ED660_EE260[2].y = -s * x1 + c * y1 + SPR_F(obj, unk_08);
    D_800ED660_EE260[3].x = c * x0 + s * y1 + SPR_F(obj, unk_04);
    D_800ED660_EE260[3].y = -s * x0 + c * y1 + SPR_F(obj, unk_08);
    return DispCheck(D_800ED660_EE260);
}

/* 1 if any part of the quad p[0..3] is on the 320x240 screen */
s32 DispCheck(SprPoint* p) {
    s32 i;
    s32 j;
    f32 dx;
    f32 dy;
    f32 t;
    f32 v;
    f32 cx;
    f32 cy;

    for (i = 0; i < 4; i++) {
        if (p[i].x >= 0.0f && p[i].x < 320.0f && p[i].y >= 0.0f && p[i].y < 240.0f) {
            return 1;
        }
    }
    for (i = 0; i < 4; i++) {
        j = i + 1;
        if (j >= 4) {
            j = 0;
        }
        dx = p[j].x - p[i].x;
        dy = p[j].y - p[i].y;
        if (dy != 0.0f) {
            t = (0.0f - p[i].y) / dy;
            if ((0.0f <= t) & (t < 1.0f)) {
                v = p[i].x + t * dx;
                if ((0.0f <= v) & (v < 320.0f)) {
                    return 1;
                }
            }
            t = (240.0f - p[i].y) / dy;
            if ((0.0f <= t) & (t < 1.0f)) {
                v = p[i].x + t * dx;
                if ((0.0f <= v) & (v < 320.0f)) {
                    return 1;
                }
            }
        }
        if (dx != 0.0f) {
            t = (0.0f - p[i].x) / dx;
            if ((0.0f <= t) & (t < 1.0f)) {
                v = p[i].y + t * dy;
                if ((0.0f <= v) & (v < 240.0f)) {
                    return 1;
                }
            }
            t = (320.0f - p[i].x) / dx;
            if ((0.0f <= t) & (t < 1.0f)) {
                v = p[i].y + t * dy;
                if ((0.0f <= v) & (v < 240.0f)) {
                    return 1;
                }
            }
        }
    }
    for (i = 0; i < 4; i++) {
        j = (i + 1 < 4) ? i + 1 : 0;
        dx = p[j].x - p[i].x;
        dy = p[j].y - p[i].y;
        cx = 160.0f - p[j].x;
        cy = 120.0f - p[j].y;
        if (dx * cy - dy * cx < 0.0f) {
            return 0;
        }
    }
    return 1;
}

/* sprite texture-load state, set by SprDisp for PutSprite and SprTexLoad */
extern s32 D_800ED680_EE280; /* texture format (G_IM_FMT_*) */
extern s32 D_800ED684_EE284; /* texel size (G_IM_SIZ_*) */
extern s32 D_800ED688_EE288;
extern s32 D_800ED68C_EE28C;
extern s32 D_800ED690_EE290; /* texture-load strips */
extern s32 D_800ED694_EE294; /* rows per strip */
extern s32 D_800ED698_EE298; /* rows in the last strip */
extern s32 D_800ED6A0_EE2A0; /* drawn with a matrix */
extern s32 D_800CD5B0_CE1B0;
extern s32 D_800CD5B4_CE1B4[4]; /* other-mode shifts */
extern s32 D_800CD5C4_CE1C4[4];
extern s32 D_800CD5D0_CE1D0[4];
extern s16 D_800CD5E0_CE1E0[];
extern s16 D_800CD718_CE318[];
extern u8 D_800FDBE0_FE7E0;
extern Gfx* D_800F9294_F9E94; /* scratch display list for cached sprites */
extern Vtx* D_801016C0_1022C0;
void* HuMemAlloc(s32 size);
void func_8004075C_4135C(void* mtx, f64 x, f64 y, f64 rot);
void func_80025770_26370(f32 mtx[4][4], f32 x, f32 y, f32 z);
void func_80025830_26430(f32 mtx[4][4], f32 sx, f32 sy, f32 sz);
void func_800B3040_B3C40(f32 mtx[4][4], Mtx* m); /* guMtxF2L */
Gfx* PutSprite(Gfx* gfx, HuSprite* obj, Vtx* vtx, Mtx* mtx, void* cam);

/* unk_120 holds an index (0-2) into unk_128/unk_134, though the header types it void* */
#define SPR_BUF(s) (*(s32*)&(s)->unk_120)

void SprDisp(Gfx** gfx, HuSprite* obj, void* cam) {
    f32 mf[4][4];
    Gfx* g;
    f32 sx;
    f32 sy;
    f32 ox;
    f32 oy;
    HuSprite_Unk84_Unk00_Struct* cel;
    s32 w;
    s32 idx;
    s32 rm;
    u32 intensity;
    Vtx* vtx;
    Gfx* end;
    s32 size;

    g = *gfx;
    sx = obj->unk_18;
    sy = obj->unk_1C;
    if (obj->unk_84 == NULL) {
        return;
    }
    cel = &obj->unk_84->unk00[obj->unk_90];
    if ((sx <= 0.0f) | (sy <= 0.0f)) {
        return;
    }
    if (SprDispCheck(obj) == 0) {
        return;
    }
    switch (obj->unk_84->unk18) {
        case 4:
            D_800ED684_EE284 = G_IM_SIZ_4b;
            if (obj->unk_84->unk1A == 1) {
                D_800ED680_EE280 = G_IM_FMT_IA;
                gDPSetTextureLUT(g++, G_TT_NONE);
            } else {
                D_800ED680_EE280 = G_IM_FMT_CI;
                if (obj->unk_98 != NULL) {
                    gDPLoadTLUT_pal16(g++, 0, obj->unk_104);
                } else {
                    gDPLoadTLUT_pal16(g++, 0, obj->unk_84->unk0C);
                }
                gDPSetTextureLUT(g++, G_TT_RGBA16);
                D_800CD5B0_CE1B0 = 0x80;
            }
            D_800ED688_EE288 = 0;
            break;
        case 8:
            D_800ED684_EE284 = G_IM_SIZ_8b;
            if (obj->unk_84->unk1A == 1) {
                D_800ED680_EE280 = G_IM_FMT_IA;
                gDPSetTextureLUT(g++, G_TT_NONE);
            } else {
                D_800ED680_EE280 = G_IM_FMT_CI;
                if (obj->unk_98 != NULL) {
                    gDPLoadTLUT_pal256(g++, obj->unk_104);
                } else {
                    gDPLoadTLUT_pal256(g++, obj->unk_84->unk0C);
                }
                gDPSetTextureLUT(g++, G_TT_RGBA16);
                D_800CD5B0_CE1B0 = 0x80;
            }
            D_800ED688_EE288 = 2;
            break;
        case 0x10:
            D_800ED684_EE284 = G_IM_SIZ_16b;
            if (obj->unk_84->unk1A == 1) {
                D_800ED680_EE280 = G_IM_FMT_IA;
            } else {
                D_800ED680_EE280 = G_IM_FMT_RGBA;
            }
            gDPSetTextureLUT(g++, G_TT_NONE);
            D_800CD5B0_CE1B0 = 0x100;
            D_800ED688_EE288 = 2;
            break;
        case 0x20:
            D_800ED684_EE284 = G_IM_SIZ_32b;
            D_800ED680_EE280 = G_IM_FMT_RGBA;
            gDPSetTextureLUT(g++, G_TT_NONE);
            D_800CD5B0_CE1B0 = 0x100;
            D_800ED688_EE288 = 2;
            break;
        case 0x8004:
            D_800ED684_EE284 = G_IM_SIZ_4b;
            D_800ED680_EE280 = G_IM_FMT_I;
            gDPSetTextureLUT(g++, G_TT_NONE);
            D_800CD5B0_CE1B0 = 0x100;
            D_800ED688_EE288 = 0;
            break;
        case 0x8008:
            D_800ED684_EE284 = G_IM_SIZ_8b;
            D_800ED680_EE280 = G_IM_FMT_I;
            gDPSetTextureLUT(g++, G_TT_NONE);
            D_800CD5B0_CE1B0 = 0x100;
            D_800ED688_EE288 = 2;
            break;
    }
    w = (((cel->unk04 << D_800ED684_EE284) >> 4) << 4) >> D_800ED684_EE284;
    if (w < cel->unk04) {
        w += 16 >> D_800ED684_EE284;
    }
    switch (D_800ED680_EE280) {
        case G_IM_FMT_CI:
            if ((0x1000 >> D_800ED684_EE284) >= cel->unk06 * w) {
                D_800ED694_EE294 = cel->unk06;
            } else {
                D_800ED694_EE294 = (0x1000 >> D_800ED684_EE284) / w;
            }
            break;
        case G_IM_FMT_I:
            if (cel->unk06 * w <= 0x1000) {
                D_800ED694_EE294 = cel->unk06;
            } else {
                D_800ED694_EE294 = 0x1000 / w;
            }
            break;
        default:
            if ((0x2000 >> D_800ED684_EE284) >= cel->unk06 * w) {
                D_800ED694_EE294 = cel->unk06;
            } else {
                D_800ED694_EE294 = (0x2000 >> D_800ED684_EE284) / w;
            }
            break;
    }
    D_800ED690_EE290 = cel->unk06 / D_800ED694_EE294;
    D_800ED698_EE298 = cel->unk06 - D_800ED690_EE290 * D_800ED694_EE294;
    if (cel->unk04 % (16 >> D_800ED684_EE284) == 0 && ((cel->unk04 * D_800ED694_EE294) << D_800ED684_EE284) <= 0x1000) {
        idx = cel->unk04 >> D_800CD5D0_CE1D0[D_800ED684_EE284];
        if (D_800CD5E0_CE1E0[idx] >= D_800ED694_EE294 || D_800ED694_EE294 == D_800CD718_CE318[idx]) {
            D_800ED688_EE288++;
        }
    }
    gDPPipeSync(g++);
    gSPSetOtherMode(g++, G_SETOTHERMODE_H, D_800CD5B4_CE1B4[0], 2, (((u32)obj->unk_24 >> 2) & 3) << D_800CD5B4_CE1B4[0]);
    gSPSetOtherMode(g++, G_SETOTHERMODE_H, D_800CD5B4_CE1B4[1], 2, ((((u32)obj->unk_24 >> 4) ^ 3) & 3) << D_800CD5B4_CE1B4[1]);
    gSPSetOtherMode(g++, G_SETOTHERMODE_H, D_800CD5B4_CE1B4[2], 2, (((u32)obj->unk_24 >> 6) & 3) << D_800CD5B4_CE1B4[2]);
    gSPSetOtherMode(g++, G_SETOTHERMODE_L, D_800CD5B4_CE1B4[3], 2, D_800CD5C4_CE1C4[((u32)obj->unk_24 >> 22) & 3]);
    if (((u32)obj->unk_24 >> 6) & 2) {
        gDPSetRenderMode(g++, 0, 0);
        gDPSetCombine(g++, 0xFFFFFF, 0xFFFCF279);
        D_800ED68C_EE28C = 4;
    } else {
        intensity = obj->unk_84->unk18 >> 15;
        rm = (((u32)obj->unk_24 >> 26) & 1) ? 0x30 : 0;
        switch (((u32)obj->unk_24 >> 10) & 3) {
            case 0:
                if (obj->unk_24 & 0x1000) {
                    if (obj->unk_2C == 0x100 && intensity == 0) {
                        rm |= 0x0C087008;
                    } else {
                        rm |= 0x404240;
                    }
                } else {
                    rm |= 0x0C084000;
                }
                break;
            case 1:
                if (obj->unk_24 & 0x1000) {
                    if (obj->unk_2C == 0x100 && intensity == 0) {
                        rm |= 0x443048;
                    } else {
                        rm |= 0x4041C8;
                    }
                } else {
                    rm |= 0x442008;
                }
                break;
            case 2:
                if (obj->unk_24 & 0x1000) {
                    if (obj->unk_2C == 0x100 && intensity == 0) {
                        rm |= 0x443048;
                    } else {
                        rm |= 0x4041C8;
                    }
                } else {
                    rm |= 0x442048;
                }
                break;
        }
        gDPSetRenderMode(g++, rm, 0);
        if (intensity) {
            if (obj->unk_2C == 0x100) {
                gDPSetCombine(g++, 0xFFFFFF, 0xFFFDF2F9);
            } else {
                gDPSetCombine(g++, 0xFF97FF, 0xFF2DFEFF);
            }
        } else if (obj->unk_2C == 0x100) {
            if (obj->unk_24 & 0x2000000) {
                gDPSetCombine(g++, 0x60FEC1, 0x33FDF2F9);
            } else {
                gDPSetCombine(g++, 0xFFFFFF, 0xFFFCF279);
            }
        } else if (obj->unk_24 & 0x2000000) {
            gDPSetCombine(g++, 0x6096C1, 0x332DFEFF);
        } else {
            gDPSetCombine(g++, 0xFF97FF, 0xFF2CFE7F);
        }
        gDPSetPrimColor(g++, 0, 0, obj->unk_28[0], obj->unk_28[1], obj->unk_28[2], obj->unk_2C);
        D_800ED68C_EE28C = 1;
    }
    D_800ED6A0_EE2A0 = ((u32)obj->unk_24 >> 30) & 1;
    gSPSegment(g++, 2, osVirtualToPhysical(cel->unk00));
    if (D_800ED6A0_EE2A0 != 0) {
        if (obj->unk_24 & 0x10000) {
            ox = ((obj->unk_3C - (s16)obj->unk_40) * (u16)cel->unk08) / cel->unk04;
            oy = (((s16)obj->unk_42 - obj->unk_3E) * (u16)cel->unk0A) / cel->unk06;
            SPR_F(obj, unk_04) = obj->unk_3C + (((s16)obj->unk_40 - obj->unk_3C) * (u16)cel->unk08) / cel->unk04;
            SPR_F(obj, unk_08) = obj->unk_3E + (((s16)obj->unk_42 - obj->unk_3E) * (u16)cel->unk0A) / cel->unk06;
        } else {
            ox = -(u16)cel->unk08;
            oy = (u16)cel->unk0A;
        }
        mf[0][2] = mf[0][3] = mf[1][2] = mf[1][3] = mf[2][0] = mf[2][1] = mf[2][3] = mf[3][2] = 0.0f;
        mf[2][2] = mf[3][3] = 1.0f;
        func_8004075C_4135C(mf, SPR_F(obj, unk_04) - 160.0f, 120.0f - SPR_F(obj, unk_08), SPR_F(obj, unk_20));
        func_80025830_26430(mf, sx, sy, 1.0f);
        func_80025770_26370(mf, ox, oy, 0.0f);
        func_800B3040_B3C40(mf, &obj->unk_140[D_800FDBE0_FE7E0]);
        gSPMatrix(g++, osVirtualToPhysical(&obj->unk_140[D_800FDBE0_FE7E0]), G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    }
    if (obj->unk_24 & 0x08000000) {
        if (obj->unk_24 & 0x10000000) {
            if (D_800ED6A0_EE2A0 != 0) {
                end = PutSprite(D_800F9294_F9E94, obj, obj->unk_134[SPR_BUF(obj)], &obj->unk_140[D_800FDBE0_FE7E0], cam);
            } else {
                end = PutSprite(D_800F9294_F9E94, obj, NULL, NULL, cam);
            }
            gSPEndDisplayList(end++);
            size = (u8*)end - (u8*)D_800F9294_F9E94;
            obj->unk_128[SPR_BUF(obj)] = HuMemAlloc(size);
            bcopy(D_800F9294_F9E94, obj->unk_128[SPR_BUF(obj)], size);
            obj->unk_124 = obj->unk_128[SPR_BUF(obj)];
            if (++SPR_BUF(obj) >= 3) {
                SPR_BUF(obj) = 0;
            }
            obj->unk_24 &= ~0x10000000;
        }
        gSPDisplayList(g++, obj->unk_124);
    } else if (D_800ED6A0_EE2A0 != 0) {
        vtx = D_801016C0_1022C0;
        g = PutSprite(g, obj, vtx, &obj->unk_140[D_800FDBE0_FE7E0], cam);
        if (!(obj->unk_24 & 0x2000)) {
            D_801016C0_1022C0 = vtx + (D_800ED690_EE290 + 2) * 2;
        } else {
            D_801016C0_1022C0 = vtx + (D_800ED690_EE290 + 2) * 4;
        }
    } else {
        g = PutSprite(g, obj, NULL, NULL, cam);
    }
    *gfx = g;
}

extern s32 D_800ED69C_EE29C; /* texture-load strips drawn */
void SprTexLoad(Gfx** gfx, HuSprite* obj, u16 rows, u16 uls, u16 ult, u16 lrs, u16 lrt, u16 cms, u16 cmt,
                u16 masks, u16 maskt);

// register allocation (masked 87): tstep and sx swap f30/s8, the zero for the initialisers is
// f30 instead of f20; the code is otherwise retail's
#ifdef NON_MATCHING
Gfx* PutSprite(Gfx* gfx, HuSprite* obj, Vtx* vtx, Mtx* mtx, void* cam) {
    f32 s0;
    s32 shiftS;
    s32 shiftT;
    s32 maskS;
    s32 maskT;
    Vtx* vtxbase;
    f32 ystep;
    HuSprite_Unk84_Unk00_Struct* cel;
    f32 sx;
    f32 sy;
    f32 y;
    f32 tstep;
    f32 x0;
    f32 x1;
    f32 y0;
    f32 step;
    f32 t;
    f32 d;
    s32 flipS;
    s32 flipT;
    s32 i;
    s32 j;
    s32 rows;
    s32 n;
    s32 dy;

    tstep = s0 = 0.0f;
    cel = &obj->unk_84->unk00[obj->unk_90];
    sx = obj->unk_18;
    sy = obj->unk_1C;
    ystep = y = 0.0f;
    vtxbase = NULL;
    if (obj->unk_24 & 0x2000) {
        gDPSetCycleType(gfx++, G_CYC_2CYCLE);
        gDPPipeSync(gfx++);
        gDPSetCombine(gfx++, 0x2527FF, 0x1FFC9238);
        gDPSetRenderMode(gfx++, 0x0C1841C8, 0);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, obj->unk_2C);
        D_800ED690_EE290 *= 2;
        D_800ED694_EE294 >>= 1;
    }
    if ((obj->unk_24 & 0x30000) == 0x30000) {
        obj->unk_30 = (f32)((s16)obj->unk_40 - obj->unk_3C) / (cel->unk04 * sx);
        obj->unk_34 = (f32)((s16)obj->unk_42 - obj->unk_3E) / (cel->unk06 * sy);
    }
    if (obj->unk_24 & 0x04000000) {
        gDPSetDepthSource(gfx++, G_ZS_PRIM);
        gDPSetPrimDepth(gfx++, obj->unk_44, 0);
    }
    if (D_800ED698_EE298 != 0) {
        D_800ED69C_EE29C = D_800ED690_EE290 + 1;
    } else {
        D_800ED69C_EE29C = D_800ED690_EE290;
    }
    if (D_800ED6A0_EE2A0 != 0) {
        vtxbase = vtx;
        flipS = 0;
        if (obj->unk_24 & 1) {
            x1 = 0.0f;
            x0 = cel->unk04 * 63.999;
        } else {
            x0 = 0.0f;
            x1 = cel->unk04 * 63.999;
            flipS = 1;
        }
        if (obj->unk_24 & 2) {
            if (obj->unk_24 & 0x10000) {
                y0 = (f32)(obj->unk_3E - (s16)obj->unk_42) / obj->unk_34;
            } else {
                y0 = -cel->unk06;
            }
            flipT = -1;
        } else {
            y0 = 0.0f;
            flipT = 1;
        }
        t = 0.0f;
        rows = cel->unk06;
        for (i = 0; i < D_800ED690_EE290 + 2; i++) {
            if (rows < D_800ED694_EE294) {
            n = rows;
        } else {
            n = D_800ED694_EE294;
        }
            rows -= D_800ED694_EE294;
            if (obj->unk_24 & 0x10000) {
                vtx[0].v.ob[0] = 0;
                vtx[1].v.ob[0] = (f32)((s16)obj->unk_40 - obj->unk_3C) / obj->unk_30;
            } else {
                vtx[0].v.ob[0] = -cel->unk04 * (obj->unk_30 - 1.0f) * (flipS ^ 1);
                vtx[1].v.ob[0] = cel->unk04;
            }
            vtx[0].v.ob[1] = vtx[1].v.ob[1] = y0;
            vtx[0].v.tc[0] = x0;
            vtx[1].v.tc[0] = x1;
            vtx[0].v.tc[1] = vtx[1].v.tc[1] = t * 128.0f;
            for (j = 0; j < 2; j++) {
                vtx[j].v.ob[2] = -1;
                vtx[j].v.cn[0] = 0;
                vtx[j].v.cn[1] = 0;
                vtx[j].v.cn[2] = 0;
                vtx[j].v.cn[3] = 0xFF;
            }
            if ((obj->unk_24 & 0xC0000) && (u16)obj->unk_38 != 0) {
                vtx[1].v.ob[0] = vtx[1].v.ob[0] * obj->unk_30;
                vtx[0].v.tc[0] = vtx[0].v.tc[0] * obj->unk_30;
                vtx[1].v.tc[0] = vtx[1].v.tc[0] * obj->unk_30;
            }
            if ((obj->unk_24 & 0x300000) && (u16)obj->unk_3A != 0) {
                vtx[0].v.ob[1] = vtx[0].v.ob[1] * obj->unk_34;
                vtx[1].v.ob[1] = vtx[1].v.ob[1] * obj->unk_34;
                vtx[0].v.tc[1] = vtx[0].v.tc[1] * obj->unk_34;
                vtx[1].v.tc[1] = vtx[1].v.tc[1] * obj->unk_34;
            }
            y0 += (obj->unk_24 & 0x10000)
                      ? ((flipT < 0) ? (f32)(((s16)obj->unk_42 - obj->unk_3E) * n / D_800ED694_EE294) / obj->unk_34
                                     : (f32)((obj->unk_3E - (s16)obj->unk_42) * n / D_800ED694_EE294) / obj->unk_34)
                      : -flipT * n;
            vtx += 2;
            t += n;
        }
    } else {
        if (obj->unk_24 & 0x10000) {
            x0 = obj->unk_3C;
            x1 = (s16)obj->unk_40;
            y0 = obj->unk_3E;
            sx = (f32)((s16)obj->unk_40 - obj->unk_3C) / cel->unk04;
            dy = (s16)obj->unk_42 - obj->unk_3E;
            step = dy / D_800ED690_EE290;
            sy = (f32)dy / cel->unk06;
        } else {
            x0 = SPR_F(obj, unk_04) - (u16)cel->unk08 * sx;
            x1 = x0 + cel->unk04 * sx;
            y0 = SPR_F(obj, unk_08) - (u16)cel->unk0A * sy;
            step = D_800ED694_EE294 * sy;
        }
        flipS = -1;
        if (obj->unk_24 & 1) {
            s0 = cel->unk04;
        } else {
            s0 = 0.0f;
            flipS = 1;
        }
        flipT = -1;
        if (obj->unk_24 & 2) {
            y = y0 + step * (D_800ED690_EE290 - 1) + D_800ED698_EE298 * sy;
            ystep = -step;
            t = step / sy - 1.0f;
        } else {
            y = y0;
            ystep = step;
            flipT = 1;
            t = 0.0f;
        }
        tstep = step / sy;
    }
    if (obj->unk_24 & 0xC0000) {
        maskS = (u16)obj->unk_38;
        shiftS = (u32)obj->unk_24 >> 18;
        shiftS -= 1;
    } else {
        maskS = 0;
        shiftS = 0;
    }
    if (obj->unk_24 & 0x300000) {
        maskT = (u16)obj->unk_3A;
        shiftT = (u32)obj->unk_24 >> 20;
        shiftT -= 1;
    } else {
        maskT = 0;
        shiftT = 0;
    }
    rows = cel->unk06;
    for (i = 0; i < D_800ED69C_EE29C; i++) {
        if (rows < D_800ED694_EE294) {
            n = rows;
        } else {
            n = D_800ED694_EE294;
        }
        rows -= D_800ED694_EE294;
        SprTexLoad(&gfx, obj, n, 0, i * D_800ED694_EE294, cel->unk04 - 1, i * D_800ED694_EE294 + n - 1, shiftS,
                   shiftT, maskS, maskT);
        if (D_800ED6A0_EE2A0 != 0) {
            gSPVertex(gfx++, vtxbase + i * 2, 4, 0);
            gSP2Triangles(gfx++, 0, 2, 3, 0, 0, 3, 1, 0);
        } else {
            gSPScisTextureRectangle(gfx++, (s32)x0 * 4, (s16)(s32)y << 2, (s32)x1 * 4, (s32)(y + n * sy) * 4,
                                    G_TX_RENDERTILE, (s16)(s32)s0 << 5, (s16)(s32)t << 5,
                                    (s32)(D_800ED68C_EE28C / sx * 1024.0f * flipS),
                                    (s32)(1.0f / sy * 1024.0f * flipT));
            if (flipT < 0 && rows < D_800ED694_EE294) {
                ystep = -(f32)rows * sy;
                tstep = rows / sy;
            }
            t += tstep;
            y += ystep;
        }
    }
    gDPPipeSync(gfx++);
    return gfx;
}
#else
const f64 D_800D36A0_D42A0 __attribute__((section(".rodata"))) = 63.999;
const f64 D_800D36A8_D42A8 __attribute__((section(".rodata"))) = 63.999;
INCLUDE_ASM("asm/nonmatchings/84FF0", PutSprite);
#endif

void func_8003F710_40310(Gfx** gfx, s32 timg, s32 fmt, s32 siz, s32 width, s32 height, s32 uls, s32 ult,
                         s32 lrs, s32 lrt, s32 pal, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts,
                         s32 shiftt);
void func_8003FB9C_4079C(Gfx** gfx, s32 timg, s32 fmt, s32 siz, s32 width, s32 height, s32 uls, s32 ult,
                         s32 lrs, s32 lrt, s32 pal, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts,
                         s32 shiftt);
void func_8003FED8_40AD8(Gfx** gfx, s32 timg, s32 fmt, u32 width, s32 height, s32 uls, s32 ult, s32 lrs,
                         s32 lrt, s32 pal, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts, s32 shiftt);
void func_80086C08_87808(Gfx** gfx, HuSprite* obj, u16 rows, u16 uls, u16 ult, u16 lrs, u16 lrt, u16 cms,
                         u16 cmt, u16 masks, u16 maskt);

/* Loads one strip of the sprite's texture (segment 2) as SprDisp chose */
void SprTexLoad(Gfx** gfx, HuSprite* obj, u16 rows, u16 uls, u16 ult, u16 lrs, u16 lrt, u16 cms, u16 cmt,
                u16 masks, u16 maskt) {
    HuSprite_Unk84_Unk00_Struct* cel = &obj->unk_84->unk00[obj->unk_90];
    Gfx* g = *gfx;

    switch (D_800ED688_EE288) {
        case 0:
            gDPLoadTextureTile_4b(g++, 0x02000000, D_800ED680_EE280, cel->unk04, rows, uls, ult, lrs, lrt, 0, cms,
                                  cmt, masks, maskt, 0, 0);
            break;
        case 1:
            func_8003FED8_40AD8(&g, 0x02000000, D_800ED680_EE280, cel->unk04, rows, uls, ult, lrs, lrt, 0, cms, cmt,
                                masks, maskt, 0, 0);
            break;
        case 2:
            func_8003F710_40310(&g, 0x02000000, D_800ED680_EE280, D_800ED684_EE284, cel->unk04, cel->unk06, uls,
                                ult, lrs, lrt, 0, cms, cmt, masks, maskt, 0, 0);
            break;
        case 3:
            func_8003FB9C_4079C(&g, 0x02000000, D_800ED680_EE280, D_800ED684_EE284, cel->unk04, rows, uls, ult,
                                lrs, lrt, 0, cms, cmt, masks, maskt, 0, 0);
            break;
    }
    if (obj->unk_24 & 0x2000) {
        func_80086C08_87808(&g, obj, rows, uls, ult, lrs, lrt, cms, cmt, masks, maskt);
    }
    *gfx = g;
}

void func_8003F93C_4053C(Gfx** gfx, s32 timg, s32 fmt, s32 siz, s32 width, s32 height, s32 uls, s32 ult,
                         s32 lrs, s32 lrt, s32 pal, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts,
                         s32 shiftt, s32 rtile, s32 tmem);
void func_80040148_40D48(Gfx** gfx, s32 timg, s32 fmt, s32 siz, s32 width, s32 height, s32 uls, s32 ult,
                         s32 lrs, s32 lrt, s32 pal, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts,
                         s32 shiftt, s32 rtile, s32 tmem);
void func_800404B0_410B0(Gfx** gfx, s32 timg, s32 fmt, u32 width, s32 height, s32 uls, s32 ult, s32 lrs,
                         s32 lrt, s32 pal, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts, s32 shiftt,
                         s32 rtile, s32 tmem);

/* SprTexLoad's second texture (two-cycle sprites): the same strip into tile 1 at TMEM D_800CD5B0 */
void func_80086C08_87808(Gfx** gfx, HuSprite* obj, u16 rows, u16 uls, u16 ult, u16 lrs, u16 lrt, u16 cms,
                         u16 cmt, u16 masks, u16 maskt) {
    HuSprite_Unk84_Unk00_Struct* cel = &obj->unk_84->unk00[obj->unk_90];
    Gfx* g = *gfx;

    switch (D_800ED688_EE288) {
        case 0:
            gDPLoadMultiTile_4b(g++, 0x02000000, D_800CD5B0_CE1B0, 1, D_800ED680_EE280, cel->unk04, rows, uls, ult,
                                lrs, lrt, 0, cms, cmt, masks, maskt, 0, 0);
            break;
        case 1:
            func_800404B0_410B0(&g, 0x02000000, D_800ED680_EE280, cel->unk04, rows, uls, ult, lrs, lrt, 0, cms, cmt,
                                masks, maskt, 0, 0, 1, D_800CD5B0_CE1B0);
            break;
        case 2:
            func_8003F93C_4053C(&g, 0x02000000, D_800ED680_EE280, D_800ED684_EE284, cel->unk04, cel->unk06, uls,
                                ult, lrs, lrt, 0, cms, cmt, masks, maskt, 0, 0, 1, D_800CD5B0_CE1B0);
            break;
        case 3:
            func_80040148_40D48(&g, 0x02000000, D_800ED680_EE280, D_800ED684_EE284, cel->unk04, rows, uls, ult,
                                lrs, lrt, 0, cms, cmt, masks, maskt, 0, 0, 1, D_800CD5B0_CE1B0);
            break;
    }
    *gfx = g;
}

void func_80087010_87C10(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_800ED6B0_EE2B0[i] = -1;
    }
}

omObjData* func_80087044_87C44(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u16 arg4) {
    omObjData* obj;
    Unk6C470Work* w;
    s16* mdl;
    s32 i;

    obj = omAddObj(arg0, 0x17, 0, -1, func_800873D8_87FD8);
    mdl = obj->model;
    for (i = 0; i < 0x17; i++) {
        *mdl++ = -1;
    }
    w = func_80027154_27D54(sizeof(*w), 0x7918);
    obj->unk_50 = w;
    func_800B0EF0_B1AF0(w, 0, sizeof(*w));
    w->unk282 = arg1;
    w->unk284 = arg2;
    w->unk286 = arg3;
    w->unk288 = arg4;
    w->unk28A = 0x18;
    w->unk28C = 0x78;
    w->unk28E = 1;
    w->unk20 = 0;
    w->func4 = NULL;
    w->func8 = func_80087D4C_8894C;
    w->funcC = func_80087F48_88B48;
    return obj;
}

void func_80087150_87D50(omObjData* obj, f32 x, f32 y, f32 z) {
    obj->trans.x = x;
    obj->trans.y = y;
    obj->trans.z = z;
}

void func_80087160_87D60(omObjData* obj, f32 x, f32 y, f32 z) {
    obj->rot.x = x;
    obj->rot.y = y;
    obj->rot.z = z;
}

void func_80087170_87D70(omObjData* obj, f32 x, f32 y, f32 z) {
    Unk6C470Work* w = obj->unk_50;
    s16 mdl;
    f32 s;

    obj->scale.x = x;
    obj->scale.y = y;
    obj->scale.z = z;
    w->unk28C = y * 120.0f;
    w->unk28E = y;
    mdl = obj->model[2];
    if (mdl >= 0) {
        s = y * 3.0f;
        func_80029714_2A314(mdl, s, s, s);
    }
}

void func_80087270_87E70(omObjData* obj, f32 y) {
    ((Unk6C470Work*)obj->unk_50)->unk1C = y;
}

void func_8008727C_87E7C(omObjData* obj, f32 x, f32 y, f32 z) {
    Unk6C470Work* w = obj->unk_50;

    w->unk10 = x;
    w->unk14 = y;
    w->unk18 = z;
}

void func_80087290_87E90(omObjData* obj, s32 state) {
    ((Unk6C470Work*)obj->unk_50)->unk20 = state;
}

s32 func_8008729C_87E9C(omObjData* obj) {
    return ((Unk6C470Work*)obj->unk_50)->unk20;
}

void func_800872A8_87EA8(omObjData* obj, u16 mode) {
    s16 mdl = obj->model[0];
    Unk6C470Part* p;
    s16 i;

    if (mdl >= 0) {
        switch (mode) {
        case 0:
            func_80029C74_2A874(mdl, 0.0f);
            break;
        case 4:
            p = ((Unk6C470Work*)obj->unk_50)->parts;
            for (i = 10; i != 0; i--) {
                p->state = 0;
                p++;
            }
            p = ((Unk6C470Work*)obj->unk_50)->parts2;
            for (i = 10; i != 0; i--) {
                p->state = 0;
                p++;
            }
            break;
        }
        func_800298A4_2A4A4(mdl, 4, mode);
        func_800298A4_2A4A4(obj->model[1], 4, mode);
        for (i = 2; i < 0x17; i++) {
            func_800298A4_2A4A4(obj->model[i], 4, 4);
        }
    }
}

s16 LoadFormFile(s32, s32);
s16 func_80018A64_19664(s32, s32);
u16 func_80018D64_19964(s32, s32, s32);
s16 func_8002109C_21C9C(s16, s32);
void func_80021160_21D60(s16, s32, s32);
void func_800211E8_21DE8(s16 index, u8 arg1);
void func_80021250_21E50(s16 index, u8 arg1, u8 arg2, u8 arg3);
s16 func_80027D3C_2893C(s16);
void func_80029E80_2AA80(s16, s32, s32);
void HmfModelObjAttrSet(s16, s32, s32);
void func_80087794_88394(omObjData* obj);

// register allocation: obj and the loop counter j swap s5/s6 (masked 0; MP1 func_8006BC38 has the same)
#ifdef NON_MATCHING
/* MP1 func_8006BC38: loads the models and sprites (cached in D_800ED6B0) */
void func_800873D8_87FD8(omObjData* obj) {
    Unk6C470Work* w = obj->unk_50;
    u16 idx;
    s16 sprite;
    s32 i;
    s16 j;
    s16 k;

    if (D_800ED6B0_EE2B0[0] < 0) {
        idx = LoadFormFile(0x23, w->unk282);
        D_800ED6B0_EE2B0[0] = idx;
    } else {
        idx = func_80027D3C_2893C(D_800ED6B0_EE2B0[0]);
    }
    obj->model[0] = idx;
    func_80029E80_2AA80(idx, 1, 1);
    if (D_800ED6B0_EE2B0[1] < 0) {
        idx = func_80018A64_19664(w->unk288 == 0 ? 4 : 0xD, w->unk284);
        D_800ED6B0_EE2B0[1] = idx;
    } else {
        idx = func_80027D3C_2893C(D_800ED6B0_EE2B0[1]);
    }
    obj->model[1] = idx;
    if (D_800ED6B0_EE2B0[2] < 0) {
        sprite = func_80018D64_19964(0x14, w->unk286 | 4, 8);
        D_800ED6B0_EE2B0[2] = sprite;
    } else {
        sprite = func_8002109C_21C9C(D_800ED6B0_EE2B0[2], 8);
    }
    w->sprites[2] = sprite;
    idx = D_800F86D8_F92D8[sprite].unk00;
    obj->model[2] = idx;
    func_800298A4_2A4A4(idx, 4, 4);
    func_800211E8_21DE8(sprite, 0xC0);
    func_80021250_21E50(sprite, 0xFF, 0xFF, 0xBE);
    HmfModelObjAttrSet(idx, 0x70000000, 0x70000000);
    func_80021160_21D60(sprite, 4, 0);
    func_800297E8_2A3E8(idx, w->unk28E * 3.0f, w->unk28E * 3.0f, w->unk28E * 3.0f);
    for (j = 3, k = 13, i = 0; i < 10; i++, j++, k++) {
        if (D_800ED6B0_EE2B0[3] < 0) {
            sprite = func_80018D64_19964(0xE, w->unk286, 8);
            D_800ED6B0_EE2B0[3] = sprite;
        } else {
            sprite = func_8002109C_21C9C(D_800ED6B0_EE2B0[3], 8);
        }
        w->sprites[j] = sprite;
        idx = D_800F86D8_F92D8[sprite].unk00;
        obj->model[j] = idx;
        HmfModelObjAttrSet(idx, 0x70000000, 0x70000000);
        func_800297E8_2A3E8(idx, 2.0f, 2.0f, 2.0f);
        func_800298A4_2A4A4(idx, 4, 4);
        sprite = func_8002109C_21C9C(D_800ED6B0_EE2B0[3], 8);
        w->sprites[k] = sprite;
        idx = D_800F86D8_F92D8[sprite].unk00;
        obj->model[k] = idx;
        HmfModelObjAttrSet(idx, 0x70000000, 0x70000000);
        func_800297E8_2A3E8(idx, 2.0f, 2.0f, 2.0f);
        func_800298A4_2A4A4(idx, 4, 4);
        func_800211E8_21DE8(sprite, i * 15 + 0x60);
    }
    obj->func_ptr = func_80087794_88394;
}
#else
INCLUDE_ASM("asm/nonmatchings/84FF0", func_800873D8_87FD8);
#endif

void func_80087794_88394(omObjData* obj) {
    Unk6C470Work* w = obj->unk_50;

    if (w->func4 != NULL) {
        w->func4();
    }
    if (w->func8 != NULL) {
        w->func8(obj);
    }
    if (w->funcC != NULL) {
        w->funcC(obj);
    }
}

INCLUDE_ASM("asm/nonmatchings/84FF0", func_800877FC_883FC);

void func_80087D4C_8894C(omObjData* obj) {
    Unk6C470Work* w = obj->unk_50;
    Unk6C470Part* p;
    s16 mdl;
    s32 t;
    s32 i;
    f32 cur;

    if (w->unk20 > 0) {
        mdl = obj->model[0];
        switch (w->unk20) {
            case 1:
                func_80029E80_2AA80(mdl, 1, 0);
                w->unk20 = 2;
                PlaySound(0xBD);
                break;
            case 2:
                cur = func_80029CE4_2A8E4(mdl);
                if (func_80029D0C_2A90C(mdl) <= cur) {
                    w->unk20 = 3;
                    p = w->parts;
                    t = 0;
                    for (i = 0; i < 10; i++, p++) {
                        p->timer = t;
                        t += 2;
                        p->radius = w->unk28C;
                        p->angle = 180.0f;
                        p->scale = w->unk28E;
                        p->state = 1;
                        p->x = obj->trans.x;
                        p->y = obj->trans.y + p->radius;
                        p->z = obj->trans.z;
                    }
                    p = w->parts2;
                    t--;
                    for (i = 0; i < 10; i++, p++) {
                        p->timer = t;
                        t++;
                        p->radius = w->unk28C;
                        p->angle = 180.0f;
                        p->scale = w->unk28E;
                        p->state = 1;
                        p->x = obj->trans.x;
                        p->y = obj->trans.y + p->radius;
                        p->z = obj->trans.z;
                    }
                }
                break;
            case 3:
                if (func_800877FC_883FC(obj) == 0) {
                    w->unk20 = 0;
                }
                break;
        }
    }
}

void func_80087F48_88B48(omObjData* obj) {
    Unk6C470Work* w = obj->unk_50;
    s16 mdl = obj->model[1];
    f32 d;
    f32 s;

    func_80029714_2A314(mdl, obj->trans.x, w->unk1C, obj->trans.z);
    d = obj->trans.y - w->unk1C - obj->scale.y * 50.0f;
    if (!w->unk288) {
        s = obj->scale.y * 0.58f;
    } else {
        s = obj->scale.y * 1.2f;
    }
    if (d < 0.0f) {
        d = s;
    } else {
        d = s - (d * 0.002f);
        if (d < 0.00001f) {
            d = 0.00001f;
        }
    }
    func_800297E8_2A3E8(mdl, d, d, d);
    func_8002979C_2A39C(mdl, obj->rot.x, obj->rot.y, obj->rot.z);
}

void func_80088080_88C80(void) {
    s16 i;
    RumbleState* r;
    OSPfs* pfs;

    if (D_800ED8A8_EE4A8 == 0) {
        for (i = 0; i < 4; i++) {
            r = &D_800ED860_EE460[i];
            pfs = &D_800ED6C0_EE2C0[i];
            if (r->unk0 != 0 && r->unkA != 0) {
                r->unkA--;
                __osMotorAccess(pfs, 0);
            }
        }
        return;
    }
    for (i = 0; i < 4; i++) {
        r = &D_800ED860_EE460[i];
        pfs = &D_800ED6C0_EE2C0[i];
        switch (r->unk2) {
        case 1:
            if (--r->unkA == 0) {
                r->unk0 = 1;
                r->unk2 = 0;
            }
            __osMotorAccess(pfs, 0);
            break;
        case 2:
            __osMotorAccess(pfs, 1);
            r->unk0 = 2;
            r->unk2 = 0;
            break;
        case 3:
            if (r->unk8 <= 0) {
                switch (r->unk0) {
                case 1:
                    if (r->unk4 != 0) {
                        __osMotorAccess(pfs, 1);
                        r->unk0 = 2;
                        r->unk8 = r->unk4;
                    }
                    break;
                case 2:
                    if (r->unk6 != 0) {
                        __osMotorAccess(pfs, 0);
                        r->unk0 = 1;
                        r->unk8 = r->unk6;
                    }
                    break;
                }
            }
            r->unk8--;
            if (r->unkA != 0) {
                if (--r->unkA == 0) {
                    r->unk2 = 1;
                    r->unkA = 3;
                }
            }
            break;
        }
    }
}

void func_800882BC_88EBC(void) {
    s16 i;
    s16 sp10;

    D_800ED8A8_EE4A8 = 0;
    for (i = 0; i < 4; i++) {
        sp10 = i;
        func_80088540_89140(&sp10);
    }
}

s32 func_8008830C_88F0C(void) {
    s16 i;

    for (i = 0; i < 4; i++) {
        func_800883B8_88FB8(&i);
    }
    return 0;
}

void func_80088350_88F50(void) {
    unkMesg sp10;

    D_800ED8A8_EE4A8 = 1;
    func_8007EE0C_7FA0C((unkfunc_8007EE0C*)&sp10, (void*)func_8008830C_88F0C, (char*)0, 1);
    func_8007EB8C_7F78C(&D_800ED890_EE490, 0, func_80088080_88C80);
    func_8007EB8C_7F78C(&D_800ED89C_EE49C, 1, func_800882BC_88EBC);
}

s32 func_800883B8_88FB8(s16* arg0) {
    s32 ret = osMotorInit(&D_800FA5E0_FB1E0, &D_800ED6C0_EE2C0[*arg0], *arg0);

    if (ret == 0) {
        D_800ED860_EE460[*arg0].unk0 = 1;
        __osMotorAccess(&D_800ED6C0_EE2C0[*arg0], 0);
    } else {
        D_800ED860_EE460[*arg0].unk0 = 0;
    }
    D_800ED862_EE462[*arg0].unk0 = 0;
    return ret;
}

void func_800884AC_890AC(s16 arg0) {
    unkMesg sp10;
    s16 sp20 = arg0;

    func_8007EE0C_7FA0C((unkfunc_8007EE0C*)&sp10, (void*)func_800883B8_88FB8, (char*)&sp20, 1);
}

void func_800884DC_890DC(s16* arg0) {
    RumbleState* r = &D_800ED860_EE460[*arg0];

    if (r->unk0 != 0) {
        r->unk2 = 2;
    }
}

void func_80088510_89110(s16 arg0) {
    unkMesg sp10;
    s16 sp20 = arg0;

    func_8007EE0C_7FA0C((unkfunc_8007EE0C*)&sp10, (void*)func_800884DC_890DC, (char*)&sp20, 1);
}

void func_80088540_89140(s16* arg0) {
    RumbleState* r = &D_800ED860_EE460[*arg0];

    if (r->unk0 != 0) {
        r->unk2 = 1;
        r->unkA = 3;
    }
}

void func_8008857C_8917C(s16 arg0) {
    unkMesg sp10;
    s16 sp20 = arg0;

    func_8007EE0C_7FA0C((unkfunc_8007EE0C*)&sp10, (void*)func_80088540_89140, (char*)&sp20, 1);
}

void func_800885AC_891AC(s16* arg0) {
    RumbleState* r = &D_800ED860_EE460[arg0[0]];

    if (r->unk0 != 0) {
        r->unk0 = 1;
        r->unk2 = 3;
        r->unk4 = arg0[1];
        r->unk6 = arg0[2];
        r->unkA = arg0[3];
        r->unk8 = 0;
    }
}

void func_80088604_89204(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    unkMesg sp10;
    s16 sp20[4];

    sp20[0] = arg0;
    sp20[1] = arg1;
    sp20[2] = arg2;
    sp20[3] = arg3;
    func_8007EE0C_7FA0C((unkfunc_8007EE0C*)&sp10, (void*)func_800885AC_891AC, (char*)sp20, 1);
}

extern u8 D_800CD850_CE450;      /* window system initialised */
extern u8 D_800CD851_CE451;      /* MP3 gLanguageIndex */
extern s16 D_800ED8B0_EE4B0;
extern u8 D_01142DD0[];
typedef struct FontFile FontFile;
extern FontFile* D_800FD8C4_FE4C4; /* font */
extern Process* D_800FC87C_FD47C;
extern u8 D_800F9512_FA112;
extern u8 D_800F851A_F911A;
extern void* D_800FFDF4_1009F4;
extern void* D_800FA6F4_FB2F4;
extern s16 D_800ED8B8_EE4B8[0x16];
extern s16 D_800ED8E4_EE4E4;
void func_80068C14_69814(void*);
void func_8008B6F4_8C2F4(void);
void omPrcSetStatBit(Process* process, s32 bit);

/* MP3 func_8005A6B0_5B2B0 (window system init); MP2 fixes the language at 2 */
void func_80088640_89240(void) {
    Process* prc;
    void* data;
    s16 i;

    if (D_800CD850_CE450 == 0) {
        D_800F920C_F9E0C = HuMemMemoryAllocTemp(sizeof(TextWindow) * 14);

        for (i = 0; i < 14; i++) {
            D_800F920C_F9E0C[i].unk5E = -1;
        }

        D_800F920C_F9E0C[0].unk62 = -1;
        D_800F920C_F9E0C[0].unk64 = 1;
        D_800F920C_F9E0C[0].unk5E = 0;
        D_800F920C_F9E0C[1].unk62 = 0;
        D_800F920C_F9E0C[1].unk64 = -1;
        D_800F920C_F9E0C[1].unk5E = -0x218;
        D_801026D4_1032D4 = 0;
        D_800FD808_FE408 = 0;
        D_800ED8B0_EE4B0 = 0x2710;
        /* stored through the neighbouring flag: retail reloads the language for the switch */
        (&D_800CD850_CE450)[1] = 2;

        switch (D_800CD851_CE451) {
            case 1:
                func_80068C14_69814(D_01142DD0);
                D_800FD8C4_FE4C4 = DataReadTemp(0x35);
                break;
            case 2:
                func_80068C14_69814(D_01142DD0);
                D_800FD8C4_FE4C4 = DataReadTemp(0x34);
                break;
            case 3:
                D_800FD8C4_FE4C4 = DataReadTemp(0x36);
                break;
            case 4:
                D_800FD8C4_FE4C4 = DataReadTemp(0x36);
                break;
        }

        prc = omAddPrcObj(func_8008B6F4_8C2F4, 0x1001, 0x800, 0);
        D_800FC87C_FD47C = prc;
        omPrcSetStatBit(prc, 0xA0);

        D_800CD850_CE450 = 1;
        D_800F9512_FA112 = 0;
        D_800F851A_F911A = 0;
        D_800FFDF4_1009F4 = DataReadTemp(0x31);
        D_800FA6F4_FB2F4 = DataReadTemp(0x32);

        for (i = 0; i < 0x16; i++) {
            D_800ED8B8_EE4B8[i] = -1;
        }

        data = DataRead(0x5A);
        D_800ED8E4_EE4E4 = SprAnimRead(data);
        DataClose(data);

        for (i = 0; i < 5; i++) {
            D_8010106E_101C6E[i] = 0;
        }

        D_801013FA_101FFA = 0xC;
    }
}

typedef struct TWColor {
    u8 r, g, b;
} TWColor;

extern TWColor D_800CD854_CE454[];
extern u8 D_800CD874_CE474[0x20];
s16 SprCreate(s32 num, s32 attr);
void func_8008225C_82E5C(s16 group, s16 member, s32 arg2);
HuSprite* func_80082550_83150(s16 grpIdx, s16 idx);
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri);
void HuMemFree(void* data);
void SprScaleSet(s16 grpIdx, s16 idx, f32 x, f32 y);
void func_80088F44_89B44(u8* buf, s16 w, s16 h);

// register allocation (masked 29): retail keeps the flags in fp and (s16)w, (s16)h in s5/s4 across the
// HuMemAlloc and memset calls; this C keeps one register fewer
#ifdef NON_MATCHING
/* MP3 func_8005A968_5B568, MP1 func_8006D010: opens a window, returns its id or -1 */
s16 func_800888A8_894A8(s16 x, s16 y, s16 w, s16 h, s32 arg4, s16 flags) {
    TextWindow* tw;
    HuSprite* spr;
    s16 id;
    s16 i;
    s16 grp;
    s32 size;

    for (id = 2; id < 14; id++) {
        if (D_800F920C_F9E0C[id].unk5E == -1) {
            break;
        }
    }
    if (id == 14) {
        return -1;
    }
    if (w & 1) {
        w++;
    }
    tw = &D_800F920C_F9E0C[id];
    tw->unk64 = 1;
    tw->unk62 = D_800F920C_F9E0C[1].unk62;
    tw->unk5E = 0x7D00;
    D_800F920C_F9E0C[D_800F920C_F9E0C[1].unk62].unk64 = id;
    D_800F920C_F9E0C[1].unk62 = id;
    tw->unk40 = w;
    tw->unk42 = h;
    if (flags & 2) {
        tw->unk3C = (320 - w) / 2;
        tw->unk3E = (240 - h) / 2;
    } else if (!(flags & 4)) {
        if (x + w > 0x128) {
            tw->unk3C = 0x128 - w;
        } else {
            tw->unk3C = x;
        }
        if (y + h > 0xE0) {
            tw->unk3E = 0xE0 - h;
        } else {
            tw->unk3E = y;
        }
    } else {
        tw->unk3C = x;
        tw->unk3E = y;
    }
    tw->unk44 = (w + 0xF) & 0xFFF0;
    tw->unk46 = h + 0x10;
    tw->unkEC = tw->unkF0 = 1.0f;
    tw->unk4C = tw->unk4E = tw->unk54 = tw->unk56 = 4;
    tw->unk50 = w - 8;
    tw->unk52 = h - 8;
    tw->unk20 = 0;
    tw->unk23 = tw->unk33 = tw->unk22 = 7;
    tw->unk25 = tw->unk26 = 1;
    tw->unk27 = 10;
    tw->unk28 = 12;
    tw->unk29 = 0;
    tw->unk2A = 2;
    tw->unk58 = tw->unk40 - tw->unk27;
    tw->unk5A = tw->unk42 - tw->unk28;
    tw->unk48 = tw->unk4A = 0;
    tw->unk_2D = D_800CD854_CE454[0].r;
    tw->unk_2E = D_800CD854_CE454[0].g;
    tw->unk_2F = D_800CD854_CE454[0].b;
    tw->unk21 = 0xF;
    tw->unk32 = 0;
    tw->unk_31 = 0;
    tw->unk_38 = 0;
    tw->unkD0 = NULL;
    tw->unkA6 = 0;
    tw->unkAC = -1;
    tw->unk35 = 0xC;
    for (i = 0; i < 5; i++) {
        tw->unk_B8[i] = NULL;
        tw->unk_B2[i] = -1;
    }
    tw->unkE0[0] = NULL;
    tw->unk6A = -1;
    tw->unk24 = 0;
    for (i = 0; i < 0x16; i++) {
        tw->unk_6E[i] = (i >= 3) ? -1 : 0;
    }
    tw->unk9A = 0;
    tw->unk66 = SprAnimRead(D_800FFDF4_1009F4);
    tw->unk68 = SprAnimRead(D_800FA6F4_FB2F4);
    tw->unk_6C = grp = SprCreate(0x16, 5);
    func_80082488_83088(grp, 0, 0x100);
    SprAttrReset(grp, 0, 0xFFFF);
    SprAttrSet(grp, 0, 0x01009000);
    SprAnimSet(grp, 0, tw->unk66, 0);
    func_8008225C_82E5C(grp, 0, 0);
    func_800824F4_830F4(grp, 0, -1);
    SprPosSet(grp, 0, tw->unk3C, tw->unk3E);
    func_80082450_83050(tw->unk_6C, 0, 0x40, 0x40, 0x80);
    spr = func_80082550_83150(grp, 0);
    if (!(flags & 8)) {
        spr->unk_84->unk00->unk04 = w;
        spr->unk_84->unk00->unk06 = h;
        HuMemFree(spr->unk_84->unk00->unk00);
        size = (w * h) / 2;
        spr->unk_84->unk00->unk00 = tw->unkDC = HuMemAlloc(size);
        func_800B0EF0_B1AF0(tw->unkDC, 0xFF, size);
        if (!(flags & 1)) {
            func_80088F44_89B44(tw->unkDC, w, h);
        }
        func_80082488_83088(grp, 0, 100);
        SprAttrReset(grp, 0, 0x8000);
    } else {
        func_80082488_83088(grp, 0, 0);
        SprAttrSet(grp, 0, 0x8000);
    }
    func_8008225C_82E5C(grp, 0, 0);
    func_80082488_83088(grp, 1, 0x100);
    SprAttrReset(grp, 1, 0xFFFF);
    SprAttrSet(grp, 1, 0x01009000);
    SprAnimSet(grp, 1, tw->unk68, 0);
    func_8008225C_82E5C(grp, 1, 0);
    SprPosSet(grp, 1, 0, 0);
    func_800824F4_830F4(grp, 1, 0);
    bcopy(D_800CD874_CE474, tw, 0x20);
    for (i = 0; i < 0x16; i++) {
        SprPrioSet(grp, i, D_800ED8B0_EE4B0);
    }
    SprPrioSet(grp, 2, D_800ED8B0_EE4B0 - 1);
    tw->unk60 = D_800ED8B0_EE4B0;
    D_800ED8B0_EE4B0 -= 0x20;
    tw->unkAA = 0x32D;
    return id;
}
#else
INCLUDE_ASM("asm/nonmatchings/84FF0", func_800888A8_894A8);
#endif

INCLUDE_ASM("asm/nonmatchings/84FF0", func_80088F44_89B44);

s16 func_8008925C_89E5C(u8* str);

/* MP1 LoadStringIntoWindow: sets the window's text (a message id, or a pointer above 0x80000000)
   and its position (-2 = centred). Host: the id/pointer test assumes N64 addresses. */
void func_800890CC_89CCC(s16 win_id, u32 str, s16 x, s16 y) {
    TextWindow* tw = &D_800F920C_F9E0C[win_id];

    if (tw->unkD0 != NULL) {
        if (tw->unkD4 != 0) {
            func_80068D24_69924(tw->unkD0);
        }
    }
    tw->unk5C = 1;
    if (str > 0x80000000) {
        tw->unkD4 = 0;
        tw->unkCC = (u8*)str;
    } else {
        tw->unkD4 = 1;
        tw->unkCC = tw->unkD0 = func_80068CD4_698D4(str);
    }
    if (x >= 0) {
        tw->unk54 = x;
    } else if (x == -2) {
        tw->unk54 = (tw->unk40 - func_8008925C_89E5C(tw->unkCC)) / 2;
        tw->unk_38 |= 0x800;
    }
    if (y >= 0) {
        tw->unk56 = y;
    } else if (y == -2) {
        tw->unk56 = (tw->unk42 - 12) / 2;
        tw->unk_38 |= 0x1000;
    }
    tw->unk20 = 1;
    tw->unk_30 = 0;
}

/* MP1 func_8006D93C: string length */
s16 func_80089234_89E34(u8* str) {
    s16 len = 0;

    while (*str != 0) {
        str++;
        len++;
    }
    return len;
}

void func_8008DACC_8E6CC(s32 arg0, s16* out, u8* str);

/* text width of str */
s16 func_8008925C_89E5C(u8* str) {
    s16 size[2];

    func_8008DACC_8E6CC(1, size, str);
    return size[0];
}

/* clears the window flags in mask, then sets bits */
void func_80089284_89E84(s16 winId, s32 mask, s32 bits) {
    TextWindow* tw = &D_800F920C_F9E0C[winId];

    tw->unk_38 = bits | (~mask & tw->unk_38);
    if (bits & 0x20) {
        tw->unkAA = 0x12C;
    }
}

u32 func_800892D8_89ED8(s16 winId) {
    return D_800F920C_F9E0C[winId].unk_38;
}

void func_80089308_89F08(s16 win_id, u32 arg1, s8 arg2) {
    TextWindow* textWindow = &D_800F920C_F9E0C[win_id];

    if (textWindow->unk_B8[arg2] != 0) {
        if (textWindow->usingStringIDBool[arg2] != 0) {
            func_80068D24_69924(textWindow->unk_B8[arg2]);
        }
    }
    // pointer check
    if (0x80000000 < arg1) {
        textWindow->usingStringIDBool[arg2] = 0;
        textWindow->unk_B8[arg2] = (char*)arg1;
    } else {
        textWindow->usingStringIDBool[arg2] = 1;
        textWindow->unk_B8[arg2] = func_80068CD4_698D4(arg1);
    }
    textWindow->unk_B2[arg2] = -1;
}

s16 func_80089404_8A004(s16 win_id, u32 spriteMainFsPair, s16 arg2, s16 arg3, s16 arg4) {
    TextWindow* window = &D_800F920C_F9E0C[win_id];
    s16 spriteId;
    void* spriteBytes;
    s16 i;

    for (i = 4; i < 0xC; i++) {
        if (window->unk_6E[i] != -1) {
            continue;
        }
        break;
    }
    if (i >= 0xC) {
        return -1;
    }

    spriteBytes = DataRead(spriteMainFsPair);
    spriteId = SprAnimRead(spriteBytes);
    window->unk_6E[i] = spriteId;
    HuMemMemoryFreePerm(spriteBytes);
    SprAnimSet(window->unk_6C, i, spriteId, arg4);
    SprPosSet(window->unk_6C, i, arg2, arg3);
    func_800824F4_830F4(window->unk_6C, i, 0);
    return i;
}

void func_80089544_8A144(s16 arg0, s16 arg1) {
    SprAnimKill(func_800896A0_8A2A0(arg0, arg1));
    D_800F920C_F9E0C[arg0].unk_6E[arg1] = -1;
}

/* MP1 func_8006DC7C: adds a sprite to the window and records it as a text entry */
s16 func_800895C0_8A1C0(s16 winId, u32 file, s16 x, s16 y, s16 arg4) {
    TextWindow* tw = &D_800F920C_F9E0C[winId];
    TWEntry* e;
    s16 ret;

    ret = func_80089404_8A004(winId, file, x, y, arg4);
    e = &tw->unk_F4[tw->unk_30];
    e->unk2 = x;
    e->unk4 = y;
    e->unk6 = 0;
    e->unk8 = 0;
    e->unk0 = 1;
    tw->unk_30++;
    return ret;
}

TextWindow* func_80089674_8A274(s16 arg0) {
    return &D_800F920C_F9E0C[arg0];
}

s16 func_800896A0_8A2A0(s16 winId, s16 idx) {
    TextWindow* tw = &D_800F920C_F9E0C[winId];

    return tw->unk_6E[idx];
}

void func_800896DC_8A2DC(s16 winId, s16 arg1, s16 arg2) {
    TextWindow* window;

    window = &D_800F920C_F9E0C[winId];

    SprPosSet(window->unk_6C, 0, arg1, arg2);
    window->unk3C = arg1;
    window->unk3E = arg2;
}

/* MP1 func_8006DE20: window scale */
void func_80089764_8A364(s16 winId, f32 sx, f32 sy) {
    TextWindow* tw = &D_800F920C_F9E0C[winId];
    s16 i;

    tw->unkEC = sx;
    tw->unkF0 = sy;
    for (i = 0; i < 0x16; i++) {
        SprScaleSet(tw->unk_6C, i, sx, sy);
    }
}

/* func_80089764 without the window's own sprites 4-11 */
void func_8008980C_8A40C(s16 winId, f32 sx, f32 sy) {
    TextWindow* tw = &D_800F920C_F9E0C[winId];
    s16 i;

    tw->unkEC = sx;
    tw->unkF0 = sy;
    for (i = 0; i < 4; i++) {
        SprScaleSet(tw->unk_6C, i, sx, sy);
    }
    for (i = 12; i < 0x16; i++) {
        SprScaleSet(tw->unk_6C, i, sx, sy);
    }
}

/* MP1 func_8006DEC8: sets the frame and cursor sprites' cel offsets */
void func_800898F0_8A4F0(s16 winId, s16 x, s16 y) {
    TextWindow* tw = &D_800F920C_F9E0C[winId];
    HuSprite* spr;
    s16 i;

    tw->unk48 = x;
    tw->unk4A = y;
    spr = func_80082550_83150(tw->unk_6C, 0);
    spr->unk_84->unk00->unk08 = x;
    spr->unk_84->unk00->unk0A = y;
    spr = func_80082550_83150(tw->unk_6C, 1);
    for (i = 0; i < spr->unk_84->unk12; i++) {
        spr->unk_84->unk00[i].unk08 = x;
        spr->unk_84->unk00[i].unk0A = y;
    }
}

void func_800899F4_8A5F4(s16 winId, f32 arg1) {
    TextWindow* window;

    window = &D_800F920C_F9E0C[winId];
    SprRotSet(window->unk_6C, 0, arg1);
}

void func_80089A48_8A648(s16 winId, s8 arg1) {
    TextWindow* tw = &D_800F920C_F9E0C[winId];

    tw->unk25 = arg1;
    tw->unk26 = arg1;
}

/* MP1 func_8006E0A4: window sprite priority */
void func_80089A7C_8A67C(s16 winId, s16 prio) {
    TextWindow* tw = &D_800F920C_F9E0C[winId];
    s16 i;

    tw->unk60 = prio;
    for (i = 0; i < 0x16; i++) {
        SprPrioSet(tw->unk_6C, i, prio);
    }
    if (tw->unk6A != -1) {
        SprPrioSet(tw->unk_6C, 2, prio - 1);
    }
}

void func_80089B2C_8A72C(s16 winId, s16 arg1) {
    TextWindow* window;

    window = &D_800F920C_F9E0C[winId];

    if (arg1 == 0) {
        SprAttrSet(window->unk_6C, 0, 0x8000);
    } else {
        SprAttrReset(window->unk_6C, 0, 0x8000);
    }
    func_80082488_83088(window->unk_6C, 0, arg1 & 0xFFFF);
}

/* sets the alpha of the cursor and the added sprites */
void func_80089BBC_8A7BC(s16 winId, s32 alpha) {
    TextWindow* tw = &D_800F920C_F9E0C[winId];
    s16 i;

    func_80082488_83088(tw->unk_6C, 1, alpha);
    for (i = 12; i < 0x16; i++) {
        if (tw->unk_6E[i] != -1) {
            func_80082488_83088(tw->unk_6C, i, alpha);
        }
    }
}

void func_80089C78_8A878(s16 winId, s8 arg1) {
    TextWindow* tw = &D_800F920C_F9E0C[winId];

    tw->unk22 = arg1;
    tw->unk23 = arg1;
}

void func_80027340_27F40(void* ptr);

/* sets palette entry idx + 1 (RGBA5551) and gives the cursor sprite a fresh copy of the palette */
void func_80089CAC_8A8AC(s16 winId, u8 idx, u8 r, u8 g, u8 b) {
    TextWindow* tw = &D_800F920C_F9E0C[winId];
    HuSprite* spr = func_80082550_83150(tw->unk_6C, 1);
    void* pal;

    tw->unk_00[idx + 1] = ((r << 8) & 0xF800) | ((g << 3) & 0x7C0) | ((b >> 2) & 0x3E) | 1;
    pal = HuMemAlloc(0x20);
    bcopy(tw, pal, 0x20);
    func_80027340_27F40(spr->unk_84->unk0C);
    spr->unk_84->unk0C = pal;
}

void func_80089DA0_8A9A0(s16 winId, u8 r, u8 g, u8 b) {
    func_80089CAC_8A8AC(winId, 0, r, g, b);
}

s32 func_8008A6DC_8B2DC(TextWindow* tw);
s32 func_8008A700_8B300(TextWindow* tw, s16 w);
s32 func_8008A7A0_8B3A0(TextWindow* tw);
s32 func_8008A7E8_8B3E8(TextWindow* tw);
void func_8008A8C0_8B4C0(TextWindow* tw);
void func_8008A960_8B560(s16 winId);
s16 func_8008AA90_8B690(s16 winId, s16 idx);
void func_8008AD94_8B994(s16 winId, u8 c, u8 color, s16 x, s16 y);
void osSyncPrintf(const char* fmt, ...);

/* MP1 func_8006E318: prints the window's text up to the next stop; 0 when the text has ended */
s32 func_80089DDC_8A9DC(s16 winId) {
    TextWindow* tw = &D_800F920C_F9E0C[winId];
    TWEntry* e;
    u8* p;
    s16 n;
    s32 c;

    while (tw->unk5C >= tw->unk26) {
        while (*tw->unkCC < 0x21) {
            if (*tw->unkCC == 0) {
                if (tw->unkAC >= 0) {
                    if (tw->unk_B2[tw->unkAC] != -1) {
                        tw->unk22 = tw->unk_B2[5];
                    }
                    tw->unkAC = -1;
                    tw->unkCC = tw->unkD8;
                    continue;
                }
                if (tw->unkD4 != 0) {
                    func_80068D24_69924(tw->unkD0);
                }
                tw->unkD0 = NULL;
                tw->unk20 = 0;
                return 0;
            }
            if (*tw->unkCC < 9) {
                tw->unk22 = *tw->unkCC - 1;
            }
            c = *tw->unkCC - 0x11;
            if ((u8)c < 5) {
                tw->unkAC = c;
                if (tw->unk_B8[tw->unkAC] != NULL) {
                    tw->unkD8 = ++tw->unkCC;
                    tw->unkCC = tw->unk_B8[tw->unkAC];
                    if (tw->unk_B2[tw->unkAC] != -1) {
                        tw->unk_B2[5] = tw->unk22;
                        tw->unk22 = tw->unk_B2[tw->unkAC];
                    }
                    continue;
                }
                tw->unkAC = -1;
            }
            if ((tw->unk_38 & 4) && (*tw->unkCC == 0x10 || *tw->unkCC == 0x20 || *tw->unkCC == 0x1A)) {
                if (*tw->unkCC == 0x1A) {
                    *tw->unkCC = 0x60;
                } else {
                    *tw->unkCC = 0x40;
                }
                break;
            }
            switch (*tw->unkCC) {
                case 0x10:
                case 0x1A:
                case 0x20:
                    if (D_800CD851_CE451 == 1) {
                        tw->unk34 = 10;
                    } else if (*tw->unkCC == 0x1A) {
                        tw->unk34 = 10;
                    } else {
                        tw->unk34 = 4;
                    }
                    tw->unkCC++;
                    if (func_8008A6DC_8B2DC(tw) == 0) {
                        tw->unk20 = 6;
                        func_8008A960_8B560(winId);
                        return 1;
                    }
                    continue;
                case 10:
                    if (D_800F9512_FA112 == 0 && func_8008A7A0_8B3A0(tw) == 0) {
                        tw->unk20 = 6;
                        func_8008A960_8B560(winId);
                        tw->unkCC++;
                        return 1;
                    }
                    break;
                case 0x17:
                    if (D_800F9512_FA112 == 0 && func_8008A7E8_8B3E8(tw) == 0) {
                        tw->unkCC++;
                        return 1;
                    }
                    break;
                case 11:
                    if (tw->unk_38 & 4) {
                        func_8008A8C0_8B4C0(tw);
                    } else if (tw->unkAC < 0 && !(tw->unk_38 & 0x1800)) {
                        func_8008A834_8B434(tw);
                    }
                    break;
                case 12:
                    e = &tw->unk_F4[tw->unk_30];
                    e->unk2 = tw->unk54 - tw->unk48;
                    e->unk4 = tw->unk56 - tw->unk4A;
                    tw->unk26 = 0;
                    tw->unk5C = 0;
                    break;
                case 13:
                    e = &tw->unk_F4[tw->unk_30];
                    e->unk6 = tw->unk54 - e->unk2;
                    e->unk8 = (tw->unk56 - e->unk4) + tw->unk28;
                    e->unk0 = 0;
                    tw->unk26 = tw->unk25;
                    if (++tw->unk_30 >= 24) {
                        osSyncPrintf("Select Max Over!\n");
                        tw->unk_30--;
                    }
                    break;
                case 14:
                    n = ((s16)(tw->unk54 - tw->unk4C) + tw->unk35) / tw->unk35 * tw->unk35;
                    if (n < tw->unk50) {
                        tw->unk54 = n + tw->unk4C;
                    }
                    break;
                case 0x16:
                    tw->unk_38 &= ~0x80;
                    break;
                case 0x18:
                    p = tw->unkCC++;
                    if (func_8008A700_8B300(tw, tw->unk29 + func_8008AA90_8B690(winId, p[1] & 0xF)) == 0) {
                        tw->unk20 = 6;
                        func_8008A960_8B560(winId);
                        return 1;
                    }
                    break;
                case 0x19:
                    tw->unk22 = tw->unk23;
                    break;
            }
            tw->unkCC++;
        }
        if ((u32)(*tw->unkCC - 0x21) < 0xF) {
            n = tw->unk29 + func_8008AA90_8B690(winId, *tw->unkCC + 0xFFE9); /* retail adds 0xFFE9: -0x17 in 16 bits */
            tw->unkCC++;
            if (func_8008A700_8B300(tw, n) == 0) {
                tw->unk20 = 6;
                func_8008A960_8B560(winId);
                return 1;
            }
            continue;
        }
        if (*tw->unkCC == 0xFF) {
            tw->unk20 = 2;
            func_8008A960_8B560(winId);
            tw->unkCC++;
            return 1;
        }
        tw->unk5C -= tw->unk26;
        if (tw->unk56 + tw->unk28 > tw->unk4E + tw->unk52) {
            tw->unk20 = 6;
            func_8008A960_8B560(winId);
            return 1;
        }
        if (*tw->unkCC >= 0x30) {
            if ((tw->unk_38 & 0x10000) && *tw->unkCC >= '0' && *tw->unkCC <= '9') {
                *tw->unkCC += 0x70;
            }
            if (tw->unk_38 & 0x80) {
                if (tw->unk22 != 0) {
                    func_8008AD94_8B994(winId, *tw->unkCC, 0, tw->unk54 + 2, tw->unk56 + 1);
                }
                func_8008AD94_8B994(winId, *tw->unkCC, tw->unk22, tw->unk54, tw->unk56);
                func_8008AD94_8B994(winId, *tw->unkCC, tw->unk22, tw->unk54 + 1, tw->unk56);
            } else if (tw->unk_38 & 0x20000) {
                func_8008AD94_8B994(winId, *tw->unkCC, 0, tw->unk54, tw->unk56 - 1);
                func_8008AD94_8B994(winId, *tw->unkCC, 0, tw->unk54, tw->unk56 + 1);
                func_8008AD94_8B994(winId, *tw->unkCC, 0, tw->unk54 + 1, tw->unk56);
                func_8008AD94_8B994(winId, *tw->unkCC, 0, tw->unk54 - 1, tw->unk56);
                func_8008AD94_8B994(winId, *tw->unkCC, tw->unk22, tw->unk54, tw->unk56);
            } else {
                if (tw->unk22 != 0) {
                    func_8008AD94_8B994(winId, *tw->unkCC, 0, tw->unk54 + 1, tw->unk56 + 1);
                }
                func_8008AD94_8B994(winId, *tw->unkCC, tw->unk22, tw->unk54, tw->unk56);
            }
        }
        tw->unkCC++;
        if ((u8)(*tw->unkCC + 0x80) < 2) {
            if (tw->unk22 != 0) {
                func_8008AD94_8B994(winId, *tw->unkCC, 0, tw->unk27 + tw->unk54 - 2, tw->unk56);
            }
            func_8008AD94_8B994(winId, *tw->unkCC, tw->unk22, tw->unk27 + tw->unk54 - 3, tw->unk56 - 1);
            tw->unkCC++;
        }
        if (func_8008A6DC_8B2DC(tw) == 0) {
            return 1;
        }
    }
    tw->unk5C++;
    return 1;
}

/* MP1 func_8006E87C's caller: advances past one character */
s32 func_8008A6DC_8B2DC(TextWindow* tw) {
    return func_8008A700_8B300(tw, tw->unk34 + tw->unk29);
}

extern s32 D_800FDC80_FE880; /* last advance */
extern u8 D_800CD888_CE488[]; /* character widths */

/* MP1 func_8006E87C: advances the cursor by w; wraps the line when the next character does not fit */
s32 func_8008A700_8B300(TextWindow* tw, s16 w) {
    s32 cw;

    D_800FDC80_FE880 = w;
    tw->unk54 += w;
    if (D_800CD851_CE451 == 1) {
        cw = tw->unk27;
    } else {
        cw = D_800CD888_CE488[*tw->unkCC];
    }
    if (cw + tw->unk54 > tw->unk4C + tw->unk50) {
        if (*tw->unkCC >= 0x20) {
            return func_8008A7A0_8B3A0(tw);
        }
    }
    return 1;
}

/* MP1 func_8006E93C: new line; 0 when the window is full */
s32 func_8008A7A0_8B3A0(TextWindow* tw) {
    tw->unk54 = tw->unk4C;
    tw->unk56 = tw->unk56 + (tw->unk28 + tw->unk2A);
    return (tw->unk56 + tw->unk28 > tw->unk4E + tw->unk52) ^ 1;
}

/* func_8008A7A0 with a quarter-height line */
s32 func_8008A7E8_8B3E8(TextWindow* tw) {
    tw->unk54 = tw->unk4C;
    tw->unk56 = tw->unk56 + ((tw->unk28 >> 2) + tw->unk2A);
    return (tw->unk56 + tw->unk28 > tw->unk4E + tw->unk52) ^ 1;
}

u8* func_8008B3BC_8BFBC(s16 winId);

/* clears the window's text */
void func_8008A834_8B434(TextWindow* tw) {
    u8* buf;

    func_8008B66C_8C26C(tw);
    buf = func_8008B3BC_8BFBC(((u8*)tw - (u8*)D_800F920C_F9E0C) / sizeof(TextWindow));
    if (tw->unkE0[0] != NULL) {
        func_800B0EF0_B1AF0(buf, 0, (tw->unk44 * tw->unk46) / 2);
    }
    func_8008A8C0_8B4C0(tw);
}

/* resets the text cursor and removes the added sprites */
void func_8008A8C0_8B4C0(TextWindow* tw) {
    s16 i;

    tw->unk54 = tw->unk4C;
    tw->unk56 = tw->unk4E;
    tw->unk_30 = 0;
    tw->unk9A = 0;
    for (i = 12; i < 0x16; i++) {
        if (tw->unk_6E[i] != -1) {
            SprAttrSet(tw->unk_6C, i, 0x8000);
            tw->unk_6E[i] = -1;
        }
    }
}

/* shows the "more text" cursor (sprite 3) at the end of the text */
void func_8008A960_8B560(s16 winId) {
    TextWindow* tw = &D_800F920C_F9E0C[winId];

    SprAnimSet(tw->unk_6C, 3, D_800ED8E4_EE4E4, 0);
    SprAttrReset(tw->unk_6C, 3, 0xFFFF);
    SprAttrSet(tw->unk_6C, 3, 0x01000000);
    SprPrioSet(tw->unk_6C, 3, tw->unk60 - 1);
    SprPosSet(tw->unk_6C, 3, tw->unk58 - tw->unk48, tw->unk5A - tw->unk4A);
    if (tw->unk_38 & 8) {
        SprAttrSet(tw->unk_6C, 3, 0x8000);
    }
}

void func_8008AA44_8B644(s16 winId) {
    TextWindow* tw = &D_800F920C_F9E0C[winId];

    SprAttrSet(tw->unk_6C, 3, 0x8000);
}

typedef struct TWIcon {
    /* 0x00 */ s32 file2; /* used when the window flag 0x2000 is set */
    /* 0x04 */ s32 file;
    /* 0x08 */ u8 anim;
    /* 0x09 */ u8 width;
} TWIcon; // size 0xC

extern TWIcon D_800CD988_CE588[];

/* places icon idx (a sprite, cached in D_800ED8B8) at the text cursor; returns its width */
s16 func_8008AA90_8B690(s16 winId, s16 idx) {
    TextWindow* tw = &D_800F920C_F9E0C[winId];
    s16 anim;
    s16 i;
    void* data;

    anim = D_800ED8B8_EE4B8[idx];
    if (anim == -1) {
        if (tw->unk_38 & 0x2000) {
            data = DataRead(D_800CD988_CE588[idx].file2);
        } else {
            data = DataRead(D_800CD988_CE588[idx].file);
        }
        D_800ED8B8_EE4B8[idx] = anim = SprAnimRead(data);
        HuMemMemoryFreePerm(data);
    }
    for (i = 12; i < 0x16; i++) {
        if (tw->unk_6E[i] == -1) {
            break;
        }
    }
    if (i >= 0x16) {
        return 0;
    }
    tw->unk_6E[i] = anim;
    SprAttrSet(tw->unk_6C, i, 0x1000);
    SprAnimSet(tw->unk_6C, i, anim, D_800CD988_CE588[idx].anim);
    SprPosSet(tw->unk_6C, i, tw->unk54 - tw->unk48, tw->unk56 - tw->unk4A);
    func_800824F4_830F4(tw->unk_6C, i, 0);
    if (tw->unk22 == 0) {
        func_80082450_83050(tw->unk_6C, i, 0, 0, 0);
    } else if (tw->unk_38 & 0x2000) {
        func_80082450_83050(tw->unk_6C, i, 0x61, 0x61, 0xF8);
    } else {
        func_80082450_83050(tw->unk_6C, i, 0x38, 0xF8, 0x25);
    }
    if (tw->unk_38 & 8) {
        SprAttrSet(tw->unk_6C, i, 0x8000);
    } else {
        SprAttrReset(tw->unk_6C, i, 0x8000);
    }
    return D_800CD988_CE588[idx].width;
}

void func_8008AD44_8B944(s16 win_id) {
    func_8008A834_8B434(&D_800F920C_F9E0C[win_id]);
}

void func_8008AD84_8B984(void) {
    D_800F9512_FA112 = 1;
}

struct FontFile {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8; /* offset of the 4-bit glyphs */
};

void func_8008B62C_8C22C(s16 win_id);
void func_8008B154_8BD54(s16 winId, s16 x, s16 y, s16 w, s16 h);

// register allocation (masked 0): c & 0xFF in a0 instead of a3, one addu operand order
#ifdef NON_MATCHING
/* MP1 func_8006EEB8: draws character c (a 10x12 4-bit glyph) into the window image in colour color */
void func_8008AD94_8B994(s16 winId, u8 c, u8 color, s16 x, s16 y) {
    TextWindow* tw = &D_800F920C_F9E0C[winId];
    u8* buf;
    u8* src;
    u8* dst;
    s16 row;
    s16 i;
    s16 w;
    s16 h;
    s16 stride;
    s16 srcStride;

    func_8008B62C_8C22C(winId);
    y = (y < 0) ? 0 : y;
    x = (x < 0) ? 0 : x;
    buf = func_8008B3BC_8BFBC(winId);
    src = (u8*)D_800FD8C4_FE4C4 + D_800FD8C4_FE4C4->unk8 + (c - 0x30) * 60;
    w = 10;
    if (D_800CD851_CE451 != 1) {
        w = D_800CD888_CE488[c];
    }
    h = 12;
    srcStride = 5;
    tw->unk34 = w;
    if ((tw->unk_38 & 4) && c != 0x80 && c != 0x81 && color == 0) {
        func_8008B154_8BD54(winId, x - 1, y - 2, tw->unk29 + 3 + w, 14);
    }
    dst = &buf[(x + y * tw->unk44) / 2];
    stride = tw->unk44 / 2;
    color++;
    if (x & 1) {
        for (row = 0; row < h; row++) {
            for (i = 0; i < w / 2; i++) {
                if ((*src & 0xF0) == 0xF0) {
                    dst[i] = color | (dst[i] & 0xF0);
                }
                if ((*src & 0xF) == 0xF) {
                    dst[i + 1] = (dst[i + 1] & 0xF) | (color << 4);
                }
                src++;
            }
            src += srcStride - i;
            dst += stride;
        }
    } else {
        w >>= 1;
        for (row = 0; row < h; row++) {
            for (i = 0; i < w; i++) {
                if ((*src & 0xF0) == 0xF0) {
                    *dst = (*dst & 0xF) | (color << 4);
                }
                if ((*src & 0xF) == 0xF) {
                    *dst = color | (*dst & 0xF0);
                }
                src++;
                dst++;
            }
            src += srcStride - i;
            dst += stride - i;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008AD94_8B994);
#endif

/* MP1 func_8006F3BC: clears a w x h box of the text image */
void func_8008B154_8BD54(s16 winId, s16 x, s16 y, s16 w, s16 h) {
    TextWindow* tw = &D_800F920C_F9E0C[winId];
    u8* dst;
    s16 row;
    s16 col;

    func_8008B62C_8C22C(winId);
    y = (y < 0) ? 0 : y;
    x = (x < 0) ? 0 : x;
    if (tw->unkE0[0] != NULL) {
        dst = func_8008B3BC_8BFBC(winId) + (x + y * tw->unk44) / 2;
        if (x & 1) {
            for (row = 0; row < h; row++) {
                for (col = 0; col < w / 2; col++) {
                    dst[col] &= 0xF0;
                    dst[col + 1] &= 0xF;
                }
                dst += tw->unk44 / 2;
            }
        } else {
            for (row = 0; row < h; row++) {
                for (col = 0; col < w / 2; col++) {
                    dst[col] = 0;
                }
                dst += tw->unk44 / 2;
            }
        }
    }
}

/* MP1 func_8006F718: the current text image, allocating the three buffers on first use */
u8* func_8008B3BC_8BFBC(s16 winId) {
    TextWindow* tw = &D_800F920C_F9E0C[winId];
    s16 grp = tw->unk_6C;
    HuSprite* spr;
    s16 i;
    s16 w;
    s16 h;

    if (tw->unkE0[0] != NULL) {
        return func_80082550_83150(grp, 1)->unk_84->unk00[tw->unk24].unk00;
    }
    w = tw->unk44;
    h = tw->unk46;
    spr = func_80082550_83150(grp, 1);
    for (i = 0; i < 3; i++) {
        HuMemFree(spr->unk_84->unk00[i].unk00);
        spr->unk_84->unk00[i].unk04 = w;
        spr->unk_84->unk00[i].unk06 = tw->unk42;
        spr->unk_84->unk00[i].unk00 = tw->unkE0[i] = HuMemAlloc((w * h) / 2);
        func_800B0EF0_B1AF0(tw->unkE0[i], 0, (w * h) / 2);
    }
    HuMemFree(spr->unk_84->unk0C);
    spr->unk_84->unk0C = HuMemAlloc(0x20);
    bcopy(tw, spr->unk_84->unk0C, 0x20);
    if (!(tw->unk_38 & 8)) {
        SprAttrReset(grp, 1, 0x8000);
    }
    return spr->unk_84->unk00[tw->unk24].unk00;
}

void SprBankSet(s16 grpIdx, s16 idx, u16 bank);

/* shows the current text image and moves to the next buffer */
void func_8008B5AC_8C1AC(s16 winId) {
    TextWindow* tw = &D_800F920C_F9E0C[winId];

    SprBankSet(tw->unk_6C, 1, tw->unk24);
    tw->unk24++;
    if (tw->unk24 >= 3) {
        tw->unk24 = 0;
    }
    tw->unk_38 &= ~0x100;
}

void func_8008B62C_8C22C(s16 win_id) {
    func_8008B66C_8C26C(&D_800F920C_F9E0C[win_id]);
}

/* starts a new text image from a copy of the previous one (once per frame) */
void func_8008B66C_8C26C(TextWindow* tw) {
    u8 prev = 2;

    if (tw->unk24 != 0) {
        prev = tw->unk24 - 1;
    }
    if (!(tw->unk_38 & 0x100)) {
        tw->unk_38 |= 0x100;
        if (tw->unkE0[0] != NULL) {
            bcopy(tw->unkE0[prev], tw->unkE0[tw->unk24], (tw->unk44 * tw->unk46) / 2);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008B6F4_8C2F4);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008BA30_8C630);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008BB18_8C718);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008BB48_8C748);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008BCB8_8C8B8);

/* func_8008C828_8D428's jump table, defined here while it is asm */
const u32 jtbl_800D3728_D4328[] __attribute__((aligned(8), section(".rodata"))) = {
    0x8008C8A8, 0x8008C8C0, 0x8008CA50, 0x8008C914, 0x8008CAC0, 0x8008CB50,
};

/* Shift-JIS character rows, 16 characters each, pointed to by D_800CDAB0_CE6B0 (in .data) */
const u8 D_800D3740_D4340[] __attribute__((aligned(4), section(".rodata"))) = {
    0x83, 0x7E, 0x83, 0x80, 0x83, 0x81, 0x83, 0x82, 0x83, 0x84, 0x83, 0x86, 0x83, 0x88, 0x83, 0x89,
    0x83, 0x8A, 0x83, 0x8B, 0x83, 0x8C, 0x83, 0x8D, 0x83, 0x8F, 0x83, 0x93, 0x81, 0x63, 0x81, 0xA5, 0x00,
};
const u8 D_800D3764_D4364[] __attribute__((aligned(4), section(".rodata"))) = {
    0x83, 0x5E, 0x83, 0x60, 0x83, 0x63, 0x83, 0x65, 0x83, 0x67, 0x83, 0x69, 0x83, 0x6A, 0x83, 0x6B,
    0x83, 0x6C, 0x83, 0x6D, 0x83, 0x6E, 0x83, 0x71, 0x83, 0x74, 0x83, 0x77, 0x83, 0x7A, 0x83, 0x7D, 0x00,
};
const u8 D_800D3788_D4388[] __attribute__((aligned(4), section(".rodata"))) = {
    0x81, 0xA6, 0x83, 0x41, 0x83, 0x43, 0x83, 0x45, 0x83, 0x47, 0x83, 0x49, 0x83, 0x4A, 0x83, 0x4C,
    0x83, 0x4E, 0x83, 0x50, 0x83, 0x52, 0x83, 0x54, 0x83, 0x56, 0x83, 0x58, 0x83, 0x5A, 0x83, 0x5C, 0x00,
};
const u8 D_800D37AC_D43AC[] __attribute__((aligned(4), section(".rodata"))) = {
    0x81, 0x75, 0x81, 0x76, 0x81, 0x49, 0x81, 0x48, 0x81, 0xF2, 0x81, 0xF3, 0x83, 0x92, 0x83, 0x40,
    0x83, 0x42, 0x83, 0x44, 0x83, 0x46, 0x83, 0x48, 0x83, 0x83, 0x83, 0x85, 0x83, 0x87, 0x83, 0x62, 0x00,
};
const u8 D_800D37D0_D43D0[] __attribute__((aligned(4), section(".rodata"))) = {
    0x82, 0xDD, 0x82, 0xDE, 0x82, 0xDF, 0x82, 0xE0, 0x82, 0xE2, 0x82, 0xE4, 0x82, 0xE6, 0x82, 0xE7,
    0x82, 0xE8, 0x82, 0xE9, 0x82, 0xEA, 0x82, 0xEB, 0x82, 0xED, 0x82, 0xF1, 0x81, 0xA6, 0x81, 0xA6, 0x00,
};
const u8 D_800D37F4_D43F4[] __attribute__((aligned(4), section(".rodata"))) = {
    0x82, 0xBD, 0x82, 0xBF, 0x82, 0xC2, 0x82, 0xC4, 0x82, 0xC6, 0x82, 0xC8, 0x82, 0xC9, 0x82, 0xCA,
    0x82, 0xCB, 0x82, 0xCC, 0x82, 0xCD, 0x82, 0xD0, 0x82, 0xD3, 0x82, 0xD6, 0x82, 0xD9, 0x82, 0xDC, 0x00,
};
const u8 D_800D3818_D4418[] __attribute__((aligned(4), section(".rodata"))) = {
    0x81, 0xA6, 0x82, 0xA0, 0x82, 0xA2, 0x82, 0xA4, 0x82, 0xA6, 0x82, 0xA8, 0x82, 0xA9, 0x82, 0xAB,
    0x82, 0xAD, 0x82, 0xAF, 0x82, 0xB1, 0x82, 0xB3, 0x82, 0xB5, 0x82, 0xB7, 0x82, 0xB9, 0x82, 0xBB, 0x00,
};
const u8 D_800D383C_D443C[] __attribute__((aligned(4), section(".rodata"))) = {
    0x81, 0x4A, 0x81, 0x4B, 0x81, 0x41, 0x81, 0x42, 0x81, 0x5B, 0x81, 0x44, 0x82, 0xF0, 0x82, 0x9F,
    0x82, 0xA1, 0x82, 0xA3, 0x82, 0xA5, 0x82, 0xA7, 0x82, 0xE1, 0x82, 0xE3, 0x82, 0xE5, 0x82, 0xC1, 0x00,
};
const u8 D_800D3860_D4460[] __attribute__((aligned(4), section(".rodata"))) = {
    0x82, 0x90, 0x82, 0x91, 0x82, 0x92, 0x82, 0x93, 0x82, 0x94, 0x82, 0x95, 0x82, 0x96, 0x82, 0x97,
    0x82, 0x98, 0x82, 0x99, 0x82, 0x9A, 0x81, 0x46, 0x81, 0x93, 0x81, 0x45, 0x81, 0xA6, 0x81, 0xA6, 0x00,
};
const u8 D_800D3884_D4484[] __attribute__((aligned(4), section(".rodata"))) = {
    0x81, 0xA6, 0x82, 0x81, 0x82, 0x82, 0x82, 0x83, 0x82, 0x84, 0x82, 0x85, 0x82, 0x86, 0x82, 0x87,
    0x82, 0x88, 0x82, 0x89, 0x82, 0x8A, 0x82, 0x8B, 0x82, 0x8C, 0x82, 0x8D, 0x82, 0x8E, 0x82, 0x8F, 0x00,
};
const u8 D_800D38A8_D44A8[] __attribute__((aligned(4), section(".rodata"))) = {
    0x82, 0x6F, 0x82, 0x70, 0x82, 0x71, 0x82, 0x72, 0x82, 0x73, 0x82, 0x74, 0x82, 0x75, 0x82, 0x76,
    0x82, 0x77, 0x82, 0x78, 0x82, 0x79, 0x81, 0x68, 0x81, 0x66, 0x81, 0x69, 0x81, 0x6A, 0x81, 0x5E, 0x00,
};
const u8 D_800D38CC_D44CC[] __attribute__((aligned(4), section(".rodata"))) = {
    0x81, 0xA6, 0x82, 0x60, 0x82, 0x61, 0x82, 0x62, 0x82, 0x63, 0x82, 0x64, 0x82, 0x65, 0x82, 0x66,
    0x82, 0x67, 0x82, 0x68, 0x82, 0x69, 0x82, 0x6A, 0x82, 0x6B, 0x82, 0x6C, 0x82, 0x6D, 0x82, 0x6E, 0x00,
};
const u8 D_800D38F0_D44F0[] __attribute__((aligned(4), section(".rodata"))) = {
    0x82, 0x4F, 0x82, 0x50, 0x82, 0x51, 0x82, 0x52, 0x82, 0x53, 0x82, 0x54, 0x82, 0x55, 0x82, 0x56,
    0x82, 0x57, 0x82, 0x58, 0x81, 0x9B, 0x81, 0x99, 0x81, 0x7B, 0x81, 0x7C, 0x81, 0x7E, 0x81, 0xA8, 0x00,
};
const u8 D_800D3914_D4514[] __attribute__((aligned(4), section(".rodata"))) = {
    0x81, 0xA6, 0x83, 0xBF, 0x83, 0xC0, 0x87, 0x85, 0x87, 0x89, 0x87, 0x88, 0x87, 0x87, 0x83, 0xA4,
    0x81, 0xA7, 0x81, 0x9C, 0x81, 0x9A, 0x8E, 0x6E, 0x89, 0x45, 0x81, 0xA6, 0x81, 0xA6, 0x81, 0xA6, 0x00,
};
const u8 D_800D3938_D4538[] __attribute__((aligned(4), section(".rodata"))) = {
    0x81, 0x40, 0x87, 0x40, 0x87, 0x41, 0x87, 0x42, 0x87, 0x43, 0x87, 0x44, 0x81, 0x6E, 0x94, 0xBC,
    0x93, 0xC1, 0x8A, 0xEE, 0x81, 0xA6, 0x81, 0xA6, 0x81, 0xA6, 0x81, 0xA6, 0x81, 0xA6, 0x81, 0xA6, 0x00,
};
const u8 D_800D395C_D455C[] __attribute__((aligned(4), section(".rodata"))) = {
    0x8F, 0x49, 0x8D, 0x95, 0x90, 0xC2, 0x90, 0xD4, 0x8E, 0x87, 0x97, 0xCE, 0x90, 0x85, 0x89, 0xA9,
    0x94, 0x92, 0x81, 0xA6, 0x8D, 0x73, 0x95, 0xC5, 0x81, 0x83, 0x81, 0x84, 0x8A, 0xD4, 0x81, 0x6D, 0x00,
};

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008C828_8D428);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008CCA8_8D8A8);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008CE5C_8DA5C);

void func_8008CFD0_8DBD0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4) {
    func_8008D0BC_8DCBC(-(~arg0 == 0), -(~arg1 == 0), -(~arg2 == 0), -(~arg3 == 0), arg4);
    func_8008D0BC_8DCBC(arg0, arg1, arg2, arg3, 1);
}

void func_8008D07C_8DC7C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_8008D0BC_8DCBC(arg0, arg1, arg2, arg3, 1);
}

void func_8008D0BC_8DCBC(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    D_800FA048_FAC48[D_800FD808_FE408].v[0] = arg0;
    D_800FA04A_FAC4A[D_800FD808_FE408].v[0] = arg1;
    D_800FA04C_FAC4C[D_800FD808_FE408].v[0] = arg2;
    D_800FA04E_FAC4E[D_800FD808_FE408].v[0] = arg3;
    D_800FA050_FAC50[D_800FD808_FE408].v[0] = arg4;
    D_800FD808_FE408 = (D_800FD808_FE408 + 1) & 0x1F;
}

void func_8008D12C_8DD2C(s16* arg0) {
    s16 i;

    if (D_801026D4_1032D4 == D_800FD808_FE408) {
        arg0[0] = arg0[1] = arg0[2] = arg0[3] = 0;
        return;
    }
    for (i = 0; i < 4; i++) {
        arg0[i] = (D_800FA048_FAC48 + D_801026D4_1032D4)->v[i];
        if (arg0[i] == -1) {
            arg0[i] = D_800FC9E0_FD5E0[i];
        }
    }
    D_800FA050_FAC50[D_801026D4_1032D4].v[0]--;
    if (D_800FA050_FAC50[D_801026D4_1032D4].v[0] == 0) {
        D_801026D4_1032D4 = (D_801026D4_1032D4 + 1) & 0x1F;
    }
}

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008D23C_8DE3C);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008D250_8DE50);

u8 func_8008D3C8_8DFC8(u8* arg0) {
    s16 i, j;

    for (i = 0; i < 10; i += 2) {
        if (D_800CDA98_CE698[i] == arg0[0] && D_800CDA98_CE698[i + 1] == arg0[1]) {
            return i / 2;
        }
    }
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 32; j += 2) {
            if (D_800CDAB0_CE6B0[i][j] == arg0[0] && D_800CDAB0_CE6B0[i][j + 1] == arg0[1]) {
                return i * 16 + j / 2;
            }
        }
    }
    return 16;
}

void func_8008D4DC_8E0DC(u8* arg0, u8* arg1) {
    for (; *arg1 != 0; arg0++, arg1 += 2) {
        *arg0 = func_8008D3C8_8DFC8(arg1);
    }
    *arg0 = 0;
}

void func_8008D530_8E130(s16 arg0, u8 arg1, u8 arg2, u8 arg3) {
    TextWindow* textWindow = &D_800F920C_F9E0C[arg0];

    textWindow->unk_2D = arg1;
    textWindow->unk_2E = arg2;
    textWindow->unk_2F = arg3;
    func_80082450_83050(textWindow->unk_6C, 0, arg1, arg2, arg3);
}

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008D59C_8E19C);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008D5D8_8E1D8);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008D6F0_8E2F0);

void func_8008D808_8E408(s16 winId, s32 arg1) {
    TextWindow* window;

    window = &D_800F920C_F9E0C[winId];
    if (arg1 != 0) {
        window->unk_38 |= 0x10;
    } else {
        window->unk_38 &= ~0x10;
    }
}

void func_8008D854_8E454(s32 arg0, s16 arg1) {
    TextWindow* textWindow = &D_800F920C_F9E0C[arg0];
    textWindow->unk_F4[arg1].unk0 = 2;
}

void func_8008D88C_8E48C(void) {
}

s16 func_8008D894_8E494(s32 winId) {
    return D_800F920C_F9E0C[winId].unk_31;
}

void func_8008D8BC_8E4BC(u8* arg0, u8* arg1) {
    while (*arg0 != 0) {
        if (*arg0 == 10) {
            arg0++;
        } else {
            *arg1++ = *arg0++;
        }
    }
    *arg1 = *arg0;
}

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008D904_8E504);

void func_8008D974_8E574(s32 arg0, s16 arg1) {
    D_800ED8E6_EE4E6 = 1;
    D_800ED8EA_EE4EA = 0;
    D_800ED8E8_EE4E8 = 0;
    func_8008DCDC_8E8DC(arg0);
    D_8010106E_101C6E[arg1] = D_800ED8E9_EE4E9;
}

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008D9D0_8E5D0);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008DA84_8E684);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008DAC0_8E6C0);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008DACC_8E6CC);

void func_8008DBE0_8E7E0(s16* arg0, s16 arg1, s16 arg2) {
    u32 i;

    if (arg2 < arg1) {
        arg0[1] = 0x64;
        arg0[0] = 0x64;
        return;
    }

    D_800ED8E6_EE4E6 = 0;
    D_800ED8EA_EE4EA = 0;
    D_800ED8E8_EE4E8 = 0;

    for (i = arg1; arg2 >= i; i++) {
        func_8008DCDC_8E8DC(i);
    }

    for (i = 0; i < ARRAY_COUNT(D_8010106E_101C6E); i++) {
        D_8010106E_101C6E[i] = 0;
    }

    D_801013FA_101FFA = 0xC;
    arg0[0] = D_800ED8E8_EE4E8 + 10;
    arg0[1] = D_800ED8EA_EE4EA + 6;
}

/* func_8008DCDC_8E8DC's jump table, defined here while it is asm */
const u32 jtbl_800D3980_D4580[] __attribute__((aligned(8), section(".rodata"))) = {
    0x8008DDD0, 0x8008DE24, 0x8008DDE0, 0x8008DDE0, 0x8008DE90, 0x8008DDE0,
    0x8008DDB4, 0x8008DF10, 0x8008DF10, 0x8008DF10, 0x8008DF10, 0x8008DF10,
    0x8008DDE0, 0x8008DE1C, 0x8008DEE8, 0x8008DDE0, 0x8008DDB4, 0x8008DF20,
    0x8008DF20, 0x8008DF20, 0x8008DF20, 0x8008DF20, 0x8008DDB4,
};

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008DCDC_8E8DC);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008DF9C_8EB9C);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008DFC4_8EBC4);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008E2DC_8EEDC);


/* MP1 func_80071DE0; MP2 scales one sprite and the window */
void func_8008E434_8F034(s32 arg0) {
    TextWindow* tw = &D_800F920C_F9E0C[arg0];

    func_8008D808_8E408(arg0, 1);
    SprScaleSet(tw->unk_6C, tw->unk274, 1.0f, 1.0f);
    func_80089764_8A364(arg0, 1.0f, 1.0f);
    func_8008D808_8E408(arg0, 0);
    func_80089284_89E84(arg0, 0x4000, 0x4000);
}

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008E4D0_8F0D0);

/* MP1 func_80071FF4; MP2 has one sprite */
void func_8008E644_8F244(s32 arg0, u8 arg1) {
    TextWindow* tw = &D_800F920C_F9E0C[arg0];

    SprAttrSet(tw->unk_6C, tw->unk274, 0x1000);
    func_80082488_83088(tw->unk_6C, tw->unk274, arg1);
}

void func_8008E6AC_8F2AC(s16 arg0) {
    func_8008CCA8_8D8A8(arg0);
}

void SprPrioSet(s16 grpIdx, s16 idx, u16 prio);

/* MP1 func_80072108; MP2 has one sprite */
void func_8008E6CC_8F2CC(s16 arg0, s16 arg1) {
    TextWindow* tw = &D_800F920C_F9E0C[arg0];

    func_80089A7C_8A67C(arg0, arg1);
    SprPrioSet(tw->unk_6C, tw->unk274, arg1 + 1);
}

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008E73C_8F33C);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008E978_8F578);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008EBE4_8F7E4);


/* MP3 func_80061A5C_6265C; MP2 has no extra sleep and always ends with the close */
void func_8008EED8_8FAD8(s16 arg0, s16 arg1) {
    s16 i;

    if (arg1 == 0) {
        func_8008AD44_8B944(arg0);

        for (i = 0; i < 5; i++) {
            func_80089764_8A364(arg0, 1.0f, 1.0f - HuMathSin(i * 18.0f));
            HuPrcVSleep();
        }
    }
    func_8008D5D8_8E1D8(arg0);
}
