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
    /* 0x01 */ char pad1[0xF];
} TWEntry; // size 0x10

typedef struct TextWindow {
    /* 0x000 */ char pad0[0x2D];
    /* 0x02D */ u8 unk_2D;
    /* 0x02E */ u8 unk_2E;
    /* 0x02F */ u8 unk_2F;
    /* 0x030 */ s8 unk_30;
    /* 0x031 */ s8 unk_31;
    /* 0x032 */ char pad32[6];
    /* 0x038 */ u32 unk_38;
    /* 0x03C */ u16 unk3C;
    /* 0x03E */ u16 unk3E;
    /* 0x040 */ char pad40[0x1E];
    /* 0x05E */ s16 unk5E;
    /* 0x060 */ char pad60[2];
    /* 0x062 */ s16 unk62;
    /* 0x064 */ s16 unk64;
    /* 0x066 */ char pad66[6];
    /* 0x06C */ s16 unk_6C;
    /* 0x06E */ s16 unk_6E[0xC];
    /* 0x086 */ char pad86[0x27];
    /* 0x0AD */ s8 usingStringIDBool[5];
    /* 0x0B2 */ s8 unk_B2[6];
    /* 0x0B8 */ void* unk_B8[4];
    /* 0x0C8 */ char padC8[0x2C];
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

INCLUDE_ASM("asm/nonmatchings/84FF0", PutSprite);

INCLUDE_ASM("asm/nonmatchings/84FF0", SprTexLoad);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_80086C08_87808);

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

INCLUDE_ASM("asm/nonmatchings/84FF0", func_80087150_87D50);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_80087160_87D60);

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

INCLUDE_ASM("asm/nonmatchings/84FF0", func_80087270_87E70);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008727C_87E7C);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_80087290_87E90);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008729C_87E9C);

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

INCLUDE_ASM("asm/nonmatchings/84FF0", func_800873D8_87FD8);

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
extern void* D_800FD8C4_FE4C4;
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

INCLUDE_ASM("asm/nonmatchings/84FF0", func_800888A8_894A8);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_80088F44_89B44);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_800890CC_89CCC);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_80089234_89E34);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008925C_89E5C);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_80089284_89E84);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_800892D8_89ED8);

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

s16 func_80089404_8A004(s16 win_id, u32 spriteMainFsPair, s16 arg2, s16 arg3, u16 arg4) {
    TextWindow* window = &D_800F920C_F9E0C[win_id];
    s16 spriteId;
    void* spriteBytes;
    s16 i;

    for (i = 4; i < ARRAY_COUNT(window->unk_6E); i++) {
        if (window->unk_6E[i] != -1) {
            continue;
        }
        break;
    }
    if (i >= ARRAY_COUNT(window->unk_6E)) {
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

INCLUDE_ASM("asm/nonmatchings/84FF0", func_800895C0_8A1C0);

TextWindow* func_80089674_8A274(s16 arg0) {
    return &D_800F920C_F9E0C[arg0];
}

INCLUDE_ASM("asm/nonmatchings/84FF0", func_800896A0_8A2A0);

void func_800896DC_8A2DC(s16 winId, s16 arg1, s16 arg2) {
    TextWindow* window;

    window = &D_800F920C_F9E0C[winId];

    SprPosSet(window->unk_6C, 0, arg1, arg2);
    window->unk3C = arg1;
    window->unk3E = arg2;
}

INCLUDE_ASM("asm/nonmatchings/84FF0", func_80089764_8A364);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008980C_8A40C);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_800898F0_8A4F0);

void func_800899F4_8A5F4(s16 winId, f32 arg1) {
    TextWindow* window;

    window = &D_800F920C_F9E0C[winId];
    SprRotSet(window->unk_6C, 0, arg1);
}

INCLUDE_ASM("asm/nonmatchings/84FF0", func_80089A48_8A648);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_80089A7C_8A67C);

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

INCLUDE_ASM("asm/nonmatchings/84FF0", func_80089BBC_8A7BC);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_80089C78_8A878);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_80089CAC_8A8AC);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_80089DA0_8A9A0);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_80089DDC_8A9DC);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008A6DC_8B2DC);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008A700_8B300);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008A7A0_8B3A0);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008A7E8_8B3E8);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008A834_8B434);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008A8C0_8B4C0);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008A960_8B560);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008AA44_8B644);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008AA90_8B690);

void func_8008AD44_8B944(s16 win_id) {
    func_8008A834_8B434(&D_800F920C_F9E0C[win_id]);
}

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008AD84_8B984);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008AD94_8B994);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008B154_8BD54);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008B3BC_8BFBC);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008B5AC_8C1AC);

void func_8008B62C_8C22C(s16 win_id) {
    func_8008B66C_8C26C(&D_800F920C_F9E0C[win_id]);
}

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008B66C_8C26C);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008B6F4_8C2F4);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008BA30_8C630);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008BB18_8C718);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008BB48_8C748);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008BCB8_8C8B8);

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

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008DCDC_8E8DC);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008DF9C_8EB9C);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008DFC4_8EBC4);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008E2DC_8EEDC);

void SprScaleSet(s16 grpIdx, s16 idx, f32 x, f32 y);
void func_80089284_89E84(s16 winId, s32 x, s32 y);

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

void func_80089A7C_8A67C(s16 winId, s16 prio);
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
