#include "common.h"
#include "game/data.h"
#include "game/malloc.h"
#include "game/sprite.h"
#include "game/hmfman.h"

/* Sprite-model slots and the coin-sparkle effect. Functions with C come from MP1 src/1EA70.c
   (and two one-liners from MP1 ovl_15/ovl_28); the rest is asm. */

typedef f32 Matrix4f[4][4];

typedef struct unk1EA70StructC {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16* unk_04;
    /* 0x08 */ Matrix4f* unk_08;
} unk1EA70StructC; // sizeof 0xC

/* HmfData.unk84 entries (0x98 bytes; MP1 unk2C0C0Struct50); 30560's local HmfMotionObj. */
typedef struct HmfMotionObj {
    /* 0x00 */ s16 unk_00; /* child count */
    /* 0x02 */ char unk_02[2];
    /* 0x04 */ Vec unk_04;
    /* 0x10 */ Vec unk_10;
    /* 0x1C */ Vec unk_1C;
    /* 0x28 */ Vec unk_28;
    /* 0x34 */ Vec unk_34;
    /* 0x40 */ Vec unk_40;
    /* 0x4C */ u8 unk_4C;
    /* 0x4D */ u8 unk_4D;
    /* 0x4E */ u8 unk_4E;
    /* 0x4F */ char unk_4F;
    /* 0x50 */ s16* unk_50; /* children: part index, or 0x8000 | motion object index; -1 ends a leaf */
    /* 0x54 */ struct HmfData* unk_54;
    /* 0x58 */ f32 unk_58[4][4];
} HmfMotionObj; /* size = 0x98 */

typedef struct unk1EA70Struct20 {
    /* 0x00 */ char unk_00[2];
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ char unk_14[4];
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ char unk_1E[2];
} unk1EA70Struct20; // sizeof 0x20

typedef struct unk1EA70Struct1C {
    /* 0x00 */ unk1EA70Struct20* unk_00;
    /* 0x04 */ u8* unk_04;
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ u8 unk_09;
    /* 0x0A */ u8 unk_0A;
    /* 0x0B */ char unk_0B;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ u16 unk_18;
    /* 0x1A */ char unk_1A[2];
} unk1EA70Struct1C; // sizeof 0x1C

/* 3D6A0's sprite bank and its frames and animations (unk388E0StructC0/CC/C8/C4 there, local to
   that unit); same layouts. */
typedef struct SprBankFrame {
    /* 0x00 */ s16 unk_00; /* width */
    /* 0x02 */ s16 unk_02; /* height */
    /* 0x04 */ s16 unk_04; /* x origin */
    /* 0x06 */ s16 unk_06; /* y origin */
    /* 0x08 */ u16 unk_08; /* palette size */
    /* 0x0A */ char unk_0A[2];
    /* 0x0C */ u16* unk_0C; /* palette */
    /* 0x10 */ void* unk_10; /* image */
} SprBankFrame; // sizeof 0x14

typedef struct SprBankStep {
    /* 0x00 */ s16 unk_00; /* frame */
    /* 0x02 */ s16 unk_02; /* duration, -1 to hold */
    /* 0x04 */ char unk_04[4];
} SprBankStep; // sizeof 8

typedef struct SprBankAnim {
    /* 0x00 */ s16 unk_00; /* step count */
    /* 0x02 */ s16 unk_02; /* total duration */
    /* 0x04 */ SprBankStep* unk_04;
} SprBankAnim; // sizeof 8

typedef struct SprBank {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04; /* 0: intensity image (flag 0x8000: 4-bit), else colour-index bits */
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08; /* reference count */
    /* 0x0A */ char unk_0A[2];
    /* 0x0C */ SprBankFrame* unk_0C;
    /* 0x10 */ SprBankAnim* unk_10;
    /* 0x14 */ u16* unk_14; /* palette */
} SprBank; // sizeof 0x18

#define TEX_MASK(x) ((x) < 3 ? 1 : (x) < 5 ? 2 : (x) < 9 ? 3 : (x) < 17 ? 4 : (x) < 33 ? 5 : (x) < 65 ? 6 : (x) < 129 ? 7 : (x) < 257 ? 8 : 9)

extern SprBank* D_800FFDFC_1009FC;
extern s16 D_800C9C54_CA854[]; /* texture filter by slot flags 0x18 */
extern u8 D_800C9C50_CA850;
extern u8 D_800C9D00_CA900[], D_800C9D14_CA914[], D_800C9D28_CA928[], D_800C9D3C_CA93C[], D_800C9D50_CA950[];
extern void* D_800F8C20_F9820;
extern unk1EA70Struct1C* D_800F904C_F9C4C;
extern u16 D_800FA18C_FAD8C;
extern Vtx* D_800FA194_FAD94;
extern void* D_800FD448_FE048;
extern Gfx* D_800FD804_FE404;
extern u8 D_800FDBCA_FE7CA;
extern u8 D_800FDBE0_FE7E0;

void* func_80027154_27D54(s32, s32);
void HuMemFree(void*);
void func_800273A8_27FA8(s16);
void HmfModelObjAttrSet(s16, s32, s32);
void func_800298A4_2A4A4(s16, s32, s32);
void func_80021160_21D60(s16, s32, s32);
void func_8003E8E4_3F4E4(s16);
void func_800283DC_28FDC(s16);
s16 func_8003DF08_3EB08(void*);
u16 func_80020EBC_21ABC(void*, s32, u8);
s16 func_80027FA4_28BA4(u32, void*, u8);
void func_800247EC_253EC(unk1EA70Struct1C*, f32, f32, f32);
s32 func_80024AB4_256B4(s16, s16, s16);
s16 func_8003D8F0_3E4F0(HmfData*, void*, s16, char*);
void func_80029A8C_2A68C(s16);

extern s16 D_800C9C5C_CA85C[6]; /* per character: data directory */
extern char* D_800C9C68_CA868[3 * 6]; /* per set (x6) and character: texture-animation name */
extern s16 D_800C9CB0_CA8B0[13 * 3]; /* data file by animation (x3) and set */
extern u8 D_800FDCA0_FE8A0[13][3];
extern s16 D_800FFE00_100A00[6][3][13]; /* loaded texture animations, -1 none */
extern u8 D_801026FC_1032FC[6]; /* set while a character has one loaded */
extern char* D_800C9D64_CA964[3 * 13]; /* per set (x13) and animation: texture-animation name */
extern s16 D_800C9E00_CAA00[13 * 3];
extern u8 D_80101658_102258[13][3];

/* 3D6A0's texture-animation slot (unk388E0Struct40 there). */
typedef struct TexAnimSlot {
    /* 0x00 */ s16 unk_00; /* frame */
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ char unk_08[2];
    /* 0x0A */ u8 unk_0A;
    /* 0x0B */ u8 unk_0B;
} TexAnimSlot; //sizeof 0xC

extern TexAnimSlot* D_800FD7F8_FE3F8;
s32 func_80025718_26318(s16, s16, s16);
s16 func_8003DBE8_3E7E8(HmfData*, u16, s16, char*);
void func_8003E888_3F488(s16);
void func_8003E4F4_3F0F4(s16, u8, u8);
void func_8003EE44_3FA44(HmfData*);
void func_8003EEA4_3FAA4(HmfData*);
s16 func_800244F4_250F4(unk1EA70Struct1C*, s16, f32, f32, f32, u16);
void func_80029F2C_2AB2C(s16, s32);
void func_80020E70_21A70(void);
void func_8002308C_23C8C(s32 index);
void func_80021424_22024(s16 index, u32 arg1);
void func_800246F8_252F8(unk1EA70Struct1C* arg0, s16 arg1, s16 arg2);
unk1EA70Struct1C* func_800240C8_24CC8(s32 arg0, s16 arg1);
void func_800242BC_24EBC(unk1EA70Struct1C*);
void func_80024D58_25958(void);
s16 func_80038398_38F98(HmfData*, char*);
void func_80039B54_3A754(HmfData*, f32, HmfMotionSlot*, s32);
void func_80023434_24034(s16 arg0, s16 arg1, unk1EA70StructC* arg2, s16 arg3);
void func_80023680_24280(HmfData* arg0, s16 arg1, s16 arg2);
void func_800B37C0_B43C0(Matrix4f); /* guMtxIdentF */
void func_80025770_26370(Matrix4f, f32, f32, f32); /* MP1 MtxTranslate */
void func_80025884_26484(Matrix4f, f32, f32, f32); /* MP1 MtxRotate */
void func_80025830_26430(Matrix4f, f32, f32, f32); /* MP1 MtxScale */
void func_80025BA4_267A4(Matrix4f, Matrix4f, Matrix4f); /* MP1 MtxMult */
void func_80030CD4_318D4(Matrix4f, Matrix4f); /* MP1 func_8002C37C */
void guMtxIdentF(float mf[4][4]);
void guMtxCatF(float m[4][4], float n[4][4], float r[4][4]);

extern Matrix4f* D_800FD43C_FE03C; /* matrix table being filled */
extern s16* D_800FC8F0_FD4F0; /* per matrix: its motion object */
extern s16 D_800F93D0_F9FD0; /* matrices written */
extern s16 D_800FD470_FE070; /* matrix stack depth */
extern Matrix4f D_801016D0_1022D0[]; /* matrix stack */
void func_80029714_2A314(s16, f32, f32, f32); /* model position (MP1 func_80025798) */
void func_800211E8_21DE8(s16 index, u8 arg1);
void func_80021250_21E50(s16 index, u8 arg1, u8 arg2, u8 arg3);
void func_800297E8_2A3E8(s16, f32, f32, f32); /* model scale (MP1 func_80025830) */
void func_80029EDC_2AADC(s16, s16); /* model layer mask (MP1 func_80025F10) */
s16 func_8001F4AC_200AC(char*); /* name hash */
s32 func_800B0FD0_B1BD0(char*, char**); /* strcmp; retail passes the address of the name */

/* The unit's .rodata in retail order, defined here (before any INCLUDE_ASM, so GCC keeps them in
   .rodata): the names are referenced by asm .data tables and by the asm switch of
   func_800252C4_25EC4. */
const char D_800D20E8_D2CE8[] = "Mtx Made Over\n";
const char D_800D20F8_D2CF8[] = "Can't find ObjName %s\n";
const char D_800D2110_D2D10[] = "c005n_0_DEF";
const char D_800D211C_D2D1C[] = "c004n_0_DEF";
const char D_800D2128_D2D28[] = "c003n_0_DEF";
const char D_800D2134_D2D34[] = "c002n_0_DEF";
const char D_800D2140_D2D40[] = "c001n_0_DEF";
const char D_800D214C_D2D4C[] = "c000n_0_DEF";
const char D_800D2158_D2D58[] = "c005l_0_DEF";
const char D_800D2164_D2D64[] = "c004l_0_DEF";
const char D_800D2170_D2D70[] = "c003l_0_DEF";
const char D_800D217C_D2D7C[] = "c002l_0_DEF";
const char D_800D2188_D2D88[] = "c001l_0_DEF";
const char D_800D2194_D2D94[] = "c000l_0_DEF";
/* func_800252C4_25EC4's jump table (case bodies of the asm function) */
const u32 jtbl_800D21A0_D2DA0[] = { 0x80025320, 0x80025318, 0x80025308, 0x80025300, 0x800252F8, 0x80025310 };
const char D_800D21B8_D2DB8[] = "c164m_0_DEF";
const char D_800D21C4_D2DC4[] = "c162n_0_DEF";
const char D_800D21D0_D2DD0[] = "c161n_0_DEF";
const char D_800D21DC_D2DDC[] = "c160n_0_DEF";
const char D_800D21E8_D2DE8[] = "c103m_0_DEF";

void func_80020D20_21920(s16 arg0) {
    s16 i;
    unk_800ECDE0* temp_v1;

    D_800FA18C_FAD8C = arg0;
    for (i = 0; i < D_800FDBCA_FE7CA; i++) {
        *(&D_800F8C20_F9820 + i) = func_80027154_27D54(arg0 << 7, 0x7530);
        *(&D_800FD448_FE048 + i) = func_80027154_27D54(arg0 << 8, 0x7530);
    }
    D_800F86D8_F92D8 = func_80027154_27D54(arg0 * sizeof(*D_800F86D8_F92D8), 0x7530);
    for (i = 0; i < arg0; i++) {
        temp_v1 = &D_800F86D8_F92D8[i];
        temp_v1->unk00 = -1;
    }
    D_800C9C50_CA850 = 1;
    func_80020E70_21A70();
}

void func_80020E70_21A70() {
    u8 temp_v0;

    if (D_800C9C50_CA850 != 0) {
        temp_v0 = D_800FDBE0_FE7E0;
        D_800FA194_FAD94 = *(&D_800F8C20_F9820 + temp_v0);
        D_800FD804_FE404 = *(&D_800FD448_FE048 + temp_v0);
    }
}

// register allocation only (masked 0): retail keeps the slot offset in s1 and temp in s2
#ifdef NON_MATCHING
u16 func_80020EBC_21ABC(void* arg0, s32 arg1, u8 arg2) {
    s16 temp;
    s16 i;
    unk_800ECDE0* p2;

    for (i = 0; i < D_800FA18C_FAD8C; i++) {
        if (D_800F86D8_F92D8[i].unk00 == -1) {
            break;
        }
    }
    if (i == D_800FA18C_FAD8C || (temp = func_80027FA4_28BA4(arg1, 0, 4)) == -1) {
        return 0xFFFF;
    }
    D_800F86D8_F92D8[i].unk00 = temp;
    if (arg0 != (void*) -1) {
        temp = func_8003DF08_3EB08(arg0);
        D_800FFDFC_1009FC[temp].unk_08 = 1;
        if (temp == -1) {
            func_800283DC_28FDC(D_800F86D8_F92D8[i].unk00);
            D_800F86D8_F92D8[i].unk00 = -1;
        }
    } else {
        temp = -1;
    }
    D_800F86D8_F92D8[i].unk02 = temp;
    D_800F86D8_F92D8[i].unk10 = arg2;
    D_800F86D8_F92D8[i].unk12 = D_800F86D8_F92D8[i].unk13 = D_800F86D8_F92D8[i].unk14 = D_800F86D8_F92D8[i].unk15 = 0xFF;
    p2 = &D_800F86D8_F92D8[i];
    p2->unk0A = 0;
    p2->unk08 = 0;
    p2->unk04 = 0;
    p2->unk06 = 0;
    p2->unk20 = 0;
    return i;
}
#else
INCLUDE_ASM("asm/nonmatchings/21920", func_80020EBC_21ABC);
#endif

/* Copies slot index's model into a new slot sharing its sprite bank (one more reference). */
u16 func_8002109C_21C9C(s16 index, s32 arg1) {
    s16 temp_v0;

    temp_v0 = func_80020EBC_21ABC((void*) -1, D_800FC834_FD434[D_800F86D8_F92D8[index].unk00].unk18, arg1);
    D_800F86D8_F92D8[temp_v0].unk02 = D_800F86D8_F92D8[index].unk02;
    D_800FFDFC_1009FC[D_800F86D8_F92D8[temp_v0].unk02].unk_08++;
    return temp_v0;
}

void func_80021160_21D60(s16 index, s32 arg1, s32 arg2) {
    unk_800ECDE0* temp_v1;

    temp_v1 = &D_800F86D8_F92D8[index];
    temp_v1->unk10 = temp_v1->unk10 & ~arg1;
    temp_v1->unk10 = arg2 | temp_v1->unk10;
}

void func_80021198_21D98(s16 index, u16 arg1) {
    D_800F86D8_F92D8[index].unk04 = arg1;
}

u16 func_800211C0_21DC0(s16 index) {
    return D_800F86D8_F92D8[index].unk04;
}

void func_800211E8_21DE8(s16 index, u8 arg1) {
    s32 unk_var;

    if (index != -1) {
        D_800F86D8_F92D8[index].unk12 = arg1;
        unk_var = (arg1 != 0xFF) << 0x10;
        HmfModelObjAttrSet(D_800F86D8_F92D8[index].unk00, 0x10000, unk_var);
    }
}

void func_80021250_21E50(s16 index, u8 arg1, u8 arg2, u8 arg3) {
    if (index != -1) {
        D_800F86D8_F92D8[index].unk13 = arg1;
        D_800F86D8_F92D8[index].unk14 = arg2;
        D_800F86D8_F92D8[index].unk15 = arg3;
    }
}

void func_800212A4_21EA4(s16 index) {
    unk_800ECDE0* temp_v1;

    temp_v1 = &D_800F86D8_F92D8[index];
    temp_v1->unk0A = 0;
    temp_v1->unk04 = 0;
    temp_v1->unk10 = temp_v1->unk10 & 0xFF7F;
    func_800298A4_2A4A4(temp_v1->unk00, 4, 0);
}

void func_800212FC_21EFC(s16 index, s8 arg1, s8 arg2, s8 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8) {
    if (index != -1) {
        func_80021160_21D60(index, 0x40, 0x40);
        D_800F86D8_F92D8[index].unk16 = arg1;
        D_800F86D8_F92D8[index].unk17 = arg2;
        D_800F86D8_F92D8[index].unk18 = arg3;
        D_800F86D8_F92D8[index].unk19 = arg4;
        D_800F86D8_F92D8[index].unk1A = arg5;
        D_800F86D8_F92D8[index].unk1B = arg6;
        D_800F86D8_F92D8[index].unk1C = arg7;
        D_800F86D8_F92D8[index].unk1D = arg8;
    }
}

void func_80021424_22024(s16 index, u32 arg1) {
    if (index != -1) {
        func_80021160_21D60(index, 0x40, 0x40);
        D_800F86D8_F92D8[index].unk20 = arg1;
        D_800F86D8_F92D8[index].unk0E = 0;
        D_800F86D8_F92D8[index].unk0C = 0;
    }
}

/* Draws every live sprite-model slot into its model's display list and advances its animation
   by arg0 ticks (MP1 func_8001E5A0). */
void func_80021490_22090(s32 arg0) {
    unk_800ECDE0* spr;
    HmfData* model;
    SprBank* info;
    SprBankAnim* anim;
    SprBankFrame* frame;
    u8* key;
    u16 end;
    u8* prev;
    f32 t;
    s16 pos;
    s16 len;
    u16 w;
    u16 h;
    s16 x;
    s16 y;
    s16 j;
    s16 i;
    s16 nh;

    if (D_800C9C50_CA850 == 0) {
        return;
    }
    for (i = 0; i < D_800FA18C_FAD8C; i++) {
        if (D_800F86D8_F92D8[i].unk00 == -1) {
            continue;
        }
        spr = &D_800F86D8_F92D8[i];
        if (D_800FC834_FD434[spr->unk00].unk18 & 4) {
            continue;
        }
        if ((u16) spr->unk02 == 0xFFFF) {
            continue;
        }
        if (spr->unk10 & 0x80) {
            func_800298A4_2A4A4(spr->unk00, 4, 4);
            spr->unk10 &= ~0x80;
            continue;
        }
        model = D_800FC834_FD434[spr->unk00].hmf;
        *(Gfx**) model->unk3C = D_800FD804_FE404; /* unk3C is a single Gfx* list here */
        info = &D_800FFDFC_1009FC[(u16) spr->unk02];
        anim = &info->unk_10[spr->unk06];
        gDPSetCycleType(D_800FD804_FE404++, G_CYC_1CYCLE);
        if (spr->unk10 & 0x40) {
            if (spr->unk20 != 0) {
                key = (u8*) spr->unk20;
                while (*key != 0xFF) {
                    if (spr->unk0A < *key) {
                        break;
                    }
                    key += 5;
                }
                if (*key == 0xFF) {
                    end = anim->unk_02;
                } else {
                    end = *key;
                }
                prev = key - 5;
                pos = spr->unk0A - prev[0];
                len = end - prev[0];
                t = (f32) pos / (f32) len;
                spr->unk13 = prev[1] + (key[1] - prev[1]) * t;
                spr->unk14 = prev[2] + (key[2] - prev[2]) * t;
                spr->unk15 = prev[3] + (key[3] - prev[3]) * t;
                spr->unk12 = prev[4] + (key[4] - prev[4]) * t;
            } else {
                t = (f32) spr->unk0A / (f32) anim->unk_02;
                spr->unk13 = (u8) spr->unk16 + (spr->unk1A - (u8) spr->unk16) * t;
                spr->unk14 = (u8) spr->unk17 + (spr->unk1B - (u8) spr->unk17) * t;
                spr->unk15 = (u8) spr->unk18 + (spr->unk1C - (u8) spr->unk18) * t;
                spr->unk12 = spr->unk19 + (spr->unk1D - spr->unk19) * t;
            }
        }
        if (info->unk_04 == 0) {
            if (info->unk_06 & 0x8000) {
                gDPSetCombine(D_800FD804_FE404++, 0xFF97FF, 0xFF2DFEFF);
            } else {
                gDPSetCombine(D_800FD804_FE404++, 0x119623, 0xFF2FFFFF);
            }
            model->unk64->unk50 |= 0x10000;
            if (spr->unk10 & 0x100) {
                gDPSetRenderMode(D_800FD804_FE404++, 0x5041C8, 0);
            } else {
                gDPSetRenderMode(D_800FD804_FE404++, 0x5049D8, 0);
            }
            gDPSetAlphaCompare(D_800FD804_FE404++, G_AC_THRESHOLD);
            gDPSetBlendColor(D_800FD804_FE404++, 0, 0, 0, 1);
            gDPSetPrimColor(D_800FD804_FE404++, 0, 0, spr->unk13, spr->unk14, spr->unk15, spr->unk12);
        } else if (spr->unk12 == 0xFF) {
            if (spr->unk10 & 0x100) {
                gDPSetRenderMode(D_800FD804_FE404++, 0x553048, 0);
            } else {
                gDPSetRenderMode(D_800FD804_FE404++, 0x553078, 0);
            }
            gDPSetCombine(D_800FD804_FE404++, 0xFFFFFF, 0xFFFCF279);
        } else {
            model->unk64->unk50 |= 0x10000;
            gDPSetAlphaCompare(D_800FD804_FE404++, G_AC_THRESHOLD);
            gDPSetBlendColor(D_800FD804_FE404++, 0, 0, 0, 1);
            gDPSetPrimColor(D_800FD804_FE404++, 0, 0, 0, 0, 0, spr->unk12);
            if (spr->unk10 & 0x100) {
                gDPSetRenderMode(D_800FD804_FE404++, 0x5041C8, 0);
            } else {
                gDPSetRenderMode(D_800FD804_FE404++, 0x5049D8, 0);
            }
            gDPSetCombine(D_800FD804_FE404++, 0x121624, 0xFF2FFFFF);
        }
        gDPSetTextureFilter(D_800FD804_FE404++, D_800C9C54_CA854[(spr->unk10 & 0x18) >> 3]);
        gSPClearGeometryMode(D_800FD804_FE404++, G_LIGHTING | G_CULL_BACK);
        gSPSetGeometryMode(D_800FD804_FE404++, G_ZBUFFER);
        frame = &info->unk_0C[anim->unk_04[(s16) spr->unk04].unk_00];
        w = frame->unk_00;
        h = frame->unk_02;
        if (info->unk_04 == 0) {
            gDPSetTextureLUT(D_800FD804_FE404++, G_TT_NONE);
            if (info->unk_06 & 0x8000) {
                gDPLoadTextureBlock_4b(D_800FD804_FE404++, frame->unk_10, G_IM_FMT_I, (s16) w, (s16) h, 0, G_TX_CLAMP, G_TX_CLAMP,
                                       TEX_MASK(frame->unk_00), TEX_MASK(frame->unk_02), G_TX_NOLOD, G_TX_NOLOD);
            } else {
                gDPLoadTextureBlock(D_800FD804_FE404++, frame->unk_10, G_IM_FMT_IA, G_IM_SIZ_8b, (s16) w, (s16) h, 0, G_TX_CLAMP,
                                    G_TX_CLAMP, TEX_MASK(frame->unk_00), TEX_MASK(frame->unk_02), G_TX_NOLOD, G_TX_NOLOD);
            }
        } else {
            gDPSetTextureLUT(D_800FD804_FE404++, G_TT_RGBA16);
            if (info->unk_04 < 0x11) {
                gDPLoadTLUT_pal16(D_800FD804_FE404++, 0, info->unk_14);
                gDPLoadTextureBlock_4b(D_800FD804_FE404++, frame->unk_10, G_IM_FMT_CI, (s16) w, (s16) h, 0, G_TX_CLAMP, G_TX_CLAMP,
                                       TEX_MASK(frame->unk_00), TEX_MASK(frame->unk_02), G_TX_NOLOD, G_TX_NOLOD);
            } else {
                gDPLoadTLUT_pal256(D_800FD804_FE404++, info->unk_14);
                gDPLoadTextureBlock(D_800FD804_FE404++, frame->unk_10, G_IM_FMT_CI, G_IM_SIZ_8b, (s16) w, (s16) h, 0, G_TX_CLAMP,
                                    G_TX_CLAMP, TEX_MASK(frame->unk_00), TEX_MASK(frame->unk_02), G_TX_NOLOD, G_TX_NOLOD);
            }
        }
        gSPVertex(D_800FD804_FE404++, osVirtualToPhysical(D_800FA194_FAD94), 4, 0);
        gSP1Quadrangle(D_800FD804_FE404++, 0, 1, 2, 3, 0);
        nh = -h;
        x = -frame->unk_04;
        y = frame->unk_06;
        D_800FA194_FAD94->v.ob[0] = x;
        D_800FA194_FAD94->v.ob[1] = y;
        D_800FA194_FAD94->v.ob[2] = 0;
        D_800FA194_FAD94->n.n[0] = D_800FA194_FAD94->n.n[1] = D_800FA194_FAD94->n.n[2] = -1;
        D_800FA194_FAD94->v.tc[0] = 0;
        D_800FA194_FAD94->v.tc[1] = 0;
        D_800FA194_FAD94->n.a = 0xFF;
        D_800FA194_FAD94++;
        D_800FA194_FAD94->v.ob[0] = x;
        D_800FA194_FAD94->v.ob[1] = nh + y;
        D_800FA194_FAD94->v.ob[2] = 0;
        D_800FA194_FAD94->n.n[0] = D_800FA194_FAD94->n.n[1] = D_800FA194_FAD94->n.n[2] = -1;
        D_800FA194_FAD94->v.tc[0] = 0;
        D_800FA194_FAD94->v.tc[1] = (-nh - 1) << 5;
        D_800FA194_FAD94->n.a = 0xFF;
        D_800FA194_FAD94++;
        D_800FA194_FAD94->v.ob[0] = (s16) w + x;
        D_800FA194_FAD94->v.ob[1] = nh + y;
        D_800FA194_FAD94->v.ob[2] = 0;
        D_800FA194_FAD94->n.n[0] = D_800FA194_FAD94->n.n[1] = D_800FA194_FAD94->n.n[2] = -1;
        D_800FA194_FAD94->v.tc[0] = ((s16) w - 1) << 5;
        D_800FA194_FAD94->v.tc[1] = (-nh - 1) << 5;
        D_800FA194_FAD94->n.a = 0xFF;
        D_800FA194_FAD94++;
        D_800FA194_FAD94->v.ob[0] = (s16) w + x;
        D_800FA194_FAD94->v.ob[1] = y;
        D_800FA194_FAD94->v.ob[2] = 0;
        D_800FA194_FAD94->n.n[0] = D_800FA194_FAD94->n.n[1] = D_800FA194_FAD94->n.n[2] = -1;
        D_800FA194_FAD94->v.tc[0] = ((s16) w - 1) << 5;
        D_800FA194_FAD94->v.tc[1] = 0;
        D_800FA194_FAD94->n.a = 0xFF;
        D_800FA194_FAD94++;
        gSPEndDisplayList(D_800FD804_FE404++);
        if (!(spr->unk10 & 1) && (D_800FDC9C_FE89C == 0 || (D_800FC834_FD434[spr->unk00].unk18 & 0x8000))) {
            for (j = 0; j < arg0; j++) {
                spr->unk08++;
                spr->unk0A++;
                if (spr->unk08 >= anim->unk_04[(s16) spr->unk04].unk_02) {
                    spr->unk04++;
                    spr->unk08 = 0;
                    if (anim->unk_00 <= (s16) spr->unk04) {
                        if (spr->unk10 & 4) {
                            spr->unk10 |= 0x80;
                        }
                        if ((spr->unk10 & 2) || anim->unk_04[(s16) spr->unk04 - 1].unk_02 != -1) {
                            spr->unk04--;
                            spr->unk0A--;
                            break;
                        }
                        spr->unk04 = 0;
                        spr->unk0A = 0;
                    }
                }
            }
        }
    }
}

void func_8002308C_23C8C(s32 index) {
    if (D_800C9C50_CA850 != 0) {
        if ((u16) D_800F86D8_F92D8[index].unk02 != 0xFFFF) {
            func_8003E8E4_3F4E4(D_800F86D8_F92D8[index].unk02);
        }
        func_800283DC_28FDC(D_800F86D8_F92D8[index].unk00);
        D_800F86D8_F92D8[index].unk00 = -1;
    }
}

void func_80023124_23D24() {
    s16 i;

    if (D_800C9C50_CA850 != 0) {
        for (i = 0; i < D_800FA18C_FAD8C; i++) {
            if (D_800F86D8_F92D8[i].unk00 != -1) {
                func_8003E8E4_3F4E4(D_800F86D8_F92D8[i].unk02);
            }
        }
        func_800273A8_27FA8(0x7530);
        D_800C9C50_CA850 = 0;
    }
}

/* Bakes model arg0's motion into a matrix table, one set of part matrices every arg1 frames
   (MP1 func_800202E8). */
unk1EA70StructC* func_800231D8_23DD8(s16 arg0, s16 arg1) {
    HmfData* model;
    HmfMotionSlot* anim;
    unk1EA70StructC* ret;

    model = D_800FC834_FD434[arg0].hmf;
    anim = &D_800F92B4_F9EB4[D_800FC834_FD434[arg0].unk02];
    ret = HuMemMemoryAllocPerm(sizeof(unk1EA70StructC));
    ret->unk_08 = HuMemMemoryAllocPerm(((anim->unk02 + arg1) / arg1) * (model->unk16 << 6));
    ret->unk_04 = HuMemMemoryAllocPerm(model->unk16 * 2);
    ret->unk_00 = anim->unk02;
    ret->unk_02 = arg1;
    func_80023434_24034(arg0, arg1, ret, -1);
    return ret;
}

/* The same for the one part named arg2 (MP1 func_8002040C). */
unk1EA70StructC* func_800232FC_23EFC(s16 arg0, s16 arg1, char* arg2) {
    HmfData* model;
    HmfMotionSlot* anim;
    unk1EA70StructC* ret;
    s16 temp;

    model = D_800FC834_FD434[arg0].hmf;
    anim = &D_800F92B4_F9EB4[D_800FC834_FD434[arg0].unk02];
    temp = func_80038398_38F98(model, arg2);
    ret = HuMemMemoryAllocPerm(sizeof(unk1EA70StructC));
    ret->unk_08 = HuMemMemoryAllocPerm(((anim->unk02 + arg1) / arg1) << 6);
    ret->unk_04 = HuMemMemoryAllocPerm(model->unk16 * 2);
    ret->unk_00 = anim->unk02;
    ret->unk_02 = arg1;
    func_80023434_24034(arg0, arg1, ret, temp);
    return ret;
}

/* MP1 func_80020544. */
void func_80023434_24034(s16 arg0, s16 arg1, unk1EA70StructC* arg2, s16 arg3) {
    HmfData* model;
    HmfMotionSlot* anim;
    s16 i;

    model = D_800FC834_FD434[arg0].hmf;
    anim = &D_800F92B4_F9EB4[D_800FC834_FD434[arg0].unk02];
    D_800FD43C_FE03C = arg2->unk_08;
    D_800FC8F0_FD4F0 = arg2->unk_04;
    D_800F93D0_F9FD0 = 0;
    guMtxIdentF(D_801016D0_1022D0[0]);
    for (i = 0; i < anim->unk02; i += arg1) {
        func_80039B54_3A754(model, i, anim, 1);
        D_800FD470_FE070 = 0;
        func_80023680_24280(model, 0, arg3);
    }
}

/* Writes the matrix of model arg0's part arg2 at motion frame arg1 to arg3 (no MP1 equivalent). */
void func_80023554_24154(s16 arg0, s16 arg1, char* arg2, Matrix4f* arg3) {
    HmfData* model;
    HmfMotionSlot* anim;
    s16 temp;
    s16 parts[4]; /* retail's frame leaves 8 bytes here; one entry per matching part */

    model = D_800FC834_FD434[arg0].hmf;
    temp = func_80038398_38F98(model, arg2);
    anim = &D_800F92B4_F9EB4[D_800FC834_FD434[arg0].unk02];
    D_800FD43C_FE03C = arg3;
    D_800FC8F0_FD4F0 = parts;
    D_800F93D0_F9FD0 = 0;
    guMtxIdentF(D_801016D0_1022D0[0]);
    func_80039B54_3A754(model, arg1, anim, 1);
    D_800FD470_FE070 = 0;
    func_80023680_24280(model, 0, temp);
    if (D_800F93D0_F9FD0 >= 2) {
        osSyncPrintf(D_800D20E8_D2CE8); /* "Mtx Made Over\n" */
    }
}

/* Walks the motion-object tree from node arg1, storing each part's matrix (all parts when arg2
   is -1, else only part arg2) and its node in the tables func_80023434_24034 set up
   (MP1 func_80020654, reshaped). */
void func_80023680_24280(HmfData* arg0, s16 arg1, s16 arg2) {
    Matrix4f sp10;
    HmfMotionObj* node;
    s16 pushed;
    s16 i;

    node = &((HmfMotionObj*) arg0->unk84)[arg1];
    pushed = 0;
    func_800B37C0_B43C0(sp10);
    if (node->unk_28.x != 0.0f || node->unk_28.y != 0.0f || node->unk_28.z != 0.0f) {
        func_80025770_26370(sp10, node->unk_28.x, node->unk_28.y, node->unk_28.z);
        pushed = 1;
    }
    if (node->unk_34.x != 0.0f || node->unk_34.y != 0.0f || node->unk_34.z != 0.0f) {
        func_80025884_26484(sp10, node->unk_34.x, node->unk_34.y, node->unk_34.z);
        pushed = 1;
    }
    if (node->unk_40.x != 1.0f || node->unk_40.y != 1.0f || node->unk_40.z != 1.0f) {
        func_80025830_26430(sp10, node->unk_40.x, node->unk_40.y, node->unk_40.z);
        pushed = 1;
    }
    if (pushed != 0) {
        D_800FD470_FE070++;
        func_80025BA4_267A4(sp10, D_801016D0_1022D0[D_800FD470_FE070 - 1], D_801016D0_1022D0[D_800FD470_FE070]);
    }
    for (i = 0; i < node->unk_00; i++) {
        if (node->unk_50[i] & 0x8000) {
            if (node->unk_50[i] == -1) {
                if ((D_800F93D0_F9FD0 < arg0->unk16) & (arg2 == -1)) {
                    D_800FC8F0_FD4F0[D_800F93D0_F9FD0] = arg1;
                    func_80030CD4_318D4(D_800FD43C_FE03C[D_800F93D0_F9FD0++], D_801016D0_1022D0[D_800FD470_FE070]);
                }
            } else {
                func_80023680_24280(arg0, node->unk_50[i] & 0x7FFF, arg2);
            }
        } else if (arg2 == -1 || arg2 == (node->unk_50[i] & 0x7FFF)) {
            if (D_800F93D0_F9FD0 < arg0->unk16) {
                D_800FC8F0_FD4F0[D_800F93D0_F9FD0] = arg1;
            }
            func_80030CD4_318D4(D_800FD43C_FE03C[D_800F93D0_F9FD0++], D_801016D0_1022D0[D_800FD470_FE070]);
        }
    }
    if (pushed != 0) {
        D_800FD470_FE070--;
    }
}

/* Poses model arg0 from baked frame arg2 of arg1 and stops its own motion (MP1 func_80020958). */
void func_80023A08_24608(s16 arg0, unk1EA70StructC* arg1, s16 arg2) {
    HmfData* model;
    s16 i;
    s16 frame;

    if (arg2 >= arg1->unk_00) {
        arg2 = arg1->unk_00 - 1;
    }
    if (arg2 < 0) {
        arg2 = 0;
    }
    model = D_800FC834_FD434[arg0].hmf;
    D_800FC834_FD434[arg0].unk02 = 0xFF;
    frame = model->unk16 * (arg2 / arg1->unk_02);
    D_800F93D0_F9FD0 = 0;
    D_800FD43C_FE03C = &arg1->unk_08[frame];
    for (i = 0; i < model->unk16; i++) {
        func_80030CD4_318D4(((HmfMotionObj*) model->unk84)[i].unk_58, D_800FD43C_FE03C[arg1->unk_04[i]]);
    }
}

/* Model arg0's world matrix times baked frame arg3 of arg1, into arg2 (MP1 func_80020ACC). */
void func_80023B7C_2477C(s16 arg0, unk1EA70StructC* arg1, Matrix4f arg2, s16 arg3) {
    HmfModel* obj;

    obj = &D_800FC834_FD434[arg0];
    if (arg3 >= arg1->unk_00) {
        arg3 = arg1->unk_00 - 1;
    }
    if (arg3 < 0) {
        arg3 = 0;
    }
    func_800B37C0_B43C0(arg2);
    if (obj->pos.x != 0.0f || obj->pos.y != 0.0f || obj->pos.z != 0.0f) {
        func_80025770_26370(arg2, obj->pos.x, obj->pos.y, obj->pos.z);
    }
    if (obj->rot.x != 0.0f || obj->rot.y != 0.0f || obj->rot.z != 0.0f) {
        func_80025884_26484(arg2, obj->rot.x, obj->rot.y, obj->rot.z);
    }
    if (obj->scale.x != 1.0f || obj->scale.y != 1.0f || obj->scale.z != 1.0f) {
        func_80025830_26430(arg2, obj->scale.x, obj->scale.y, obj->scale.z);
    }
    guMtxCatF(arg1->unk_08[arg3 / arg1->unk_02], arg2, arg2);
}

void func_80023D74_24974(unk1EA70StructC* arg0) {
    HuMemMemoryFreePerm(arg0->unk_08);
    HuMemMemoryFreePerm(arg0->unk_04);
    HuMemMemoryFreePerm(arg0);
}

/* Hangs model arg0's part arg1 onto model arg2's part arg3 (MP1 func_80020EA0). Retail compares
   each name against the address of the name argument (&arg1, &arg3), as MP1 does. */
void func_80023DAC_249AC(s16 arg0, char* arg1, s16 arg2, char* arg3) {
    HmfData* src;
    HmfData* dst;
    HitXform* obj40;
    HmfMotionObj* obj50;
    s16 hash;
    s16 i;
    s16 j;
    s16 k;
    s16 l;

    src = D_800FC834_FD434[arg0].hmf;
    dst = D_800FC834_FD434[arg2].hmf;
    hash = func_8001F4AC_200AC(arg1);
    for (i = 0; i < src->unk10; i++) {
        if (src->unk64[i].unk08 == hash && func_800B0FD0_B1BD0(dst->unk64[i].unk12, &arg1) != 0) {
            break;
        }
    }
    if (i == src->unk10) {
        osSyncPrintf(D_800D20F8_D2CF8, arg1); /* "Can't find ObjName %s\n" */
        return;
    }
    hash = func_8001F4AC_200AC(arg3);
    for (j = 0; j < dst->unk10; j++) {
        if (dst->unk64[j].unk08 == hash && func_800B0FD0_B1BD0(dst->unk64[j].unk12, &arg3) != 0) {
            break;
        }
    }
    if (j == dst->unk10) {
        osSyncPrintf(D_800D20F8_D2CF8, arg3);
        return;
    }
    if (dst->unk84 == (void*) -1) {
        for (k = 0; k < dst->unk68; k++) {
            obj40 = &dst->unk6C[k];
            if (obj40->unk00 == j) {
                obj40->unk48 = src;
                obj40->unk00 = i;
                return;
            }
        }
    } else {
        for (k = 0; k < dst->unk16; k++) {
            obj50 = &((HmfMotionObj*) dst->unk84)[k];
            for (l = 0; l < obj50->unk_00; l++) {
                if (obj50->unk_50[l] == j) {
                    obj50->unk_54 = src;
                    obj50->unk_50[l] = i;
                    break;
                }
            }
        }
    }
}

unk1EA70Struct1C* func_800240C8_24CC8(s32 arg0, s16 arg1) {
    unk1EA70Struct1C* ret;
    void* file;
    s16 sprite;
    s16 i;
    u16 idx;

    ret = func_80027154_27D54(sizeof(unk1EA70Struct1C), 0x7918);
    ret->unk_18 = arg1;
    ret->unk_00 = func_80027154_27D54(arg1 * sizeof(unk1EA70Struct20), 0x7918);
    ret->unk_04 = func_80027154_27D54(arg1, 0x7918);
    file = DataReadTemp(arg0);
    sprite = func_8003DF08_3EB08(file);
    DataCloseTemp(file);
    for (i = 0; i < arg1; i++) {
        idx = func_80020EBC_21ABC((void*) -1, 0x284, 8);
        ret->unk_00[i].unk_1C = idx;
        D_800F86D8_F92D8[(s16) idx].unk02 = sprite;
        func_80021160_21D60(idx, 4, 4);
        ret->unk_04[i] = 0;
    }
    ret->unk_14 = 1.0f;
    ret->unk_10 = 1.0f;
    ret->unk_0C = 1.0f;
    ret->unk_0A = 0xFF;
    ret->unk_09 = 0xFF;
    ret->unk_08 = 0xFF;
    return ret;
}

void func_80024234_24E34(unk1EA70Struct1C* arg0) {
    s16 i;

    for (i = 0; i < arg0->unk_18; i++) {
        func_8002308C_23C8C(arg0->unk_00[i].unk_1C);
    }
    HuMemFree(arg0->unk_04);
    HuMemFree(arg0->unk_00);
    HuMemFree(arg0);
}

/* Steps every live particle of arg0: delay, fade (alpha falls by 0xF a tick) and fall
   (MP1 func_800214FC, without its sprite-kind test). */
void func_800242BC_24EBC(unk1EA70Struct1C* arg0) {
    unk1EA70Struct20* e;
    s16 i;
    s16 obj;

    for (i = 0; i < arg0->unk_18; i++) {
        if (arg0->unk_04[i] == 0) {
            continue;
        }
        e = &arg0->unk_00[i];
        obj = D_800F86D8_F92D8[e->unk_1C].unk00;
        if (e->unk_06 != 0) {
            if (--e->unk_06 != 0) {
                continue;
            }
            func_800298A4_2A4A4(obj, 4, 0);
            D_800F86D8_F92D8[arg0->unk_00[i].unk_1C].unk04 = 0;
        }
        switch (arg0->unk_04[i]) {
            case 1:
                func_800211E8_21DE8(e->unk_1C, ~e->unk_04);
                break;
            case 2:
                e->unk_0C += e->unk_18;
                e->unk_18 -= 0.3f;
                func_80029714_2A314(obj, e->unk_08, e->unk_0C, e->unk_10);
                func_800211E8_21DE8(e->unk_1C, ~e->unk_04);
                break;
            case 3:
                e->unk_0C += e->unk_18;
                e->unk_18 -= 0.3f;
                func_80029714_2A314(obj, e->unk_08, e->unk_0C, e->unk_10);
                break;
        }
        e->unk_04 += 0xF;
        if (D_800FC834_FD434[obj].unk18 & 4) {
            arg0->unk_04[i] = 0;
        }
    }
}

/* Starts a free particle of arg0 at (arg2, arg3, arg4) in mode arg5, on model layer arg1;
   returns its index or -1 (MP1 func_80021794, always opaque here). */
s16 func_800244F4_250F4(unk1EA70Struct1C* arg0, s16 arg1, f32 arg2, f32 arg3, f32 arg4, u16 arg5) {
    s16 i;
    s16 obj;
    unk_800ECDE0* spr;

    for (i = 0; i < arg0->unk_18; i++) {
        if (arg0->unk_04[i] == 0) {
            break;
        }
    }
    if (i == arg0->unk_18) {
        return -1;
    }
    obj = D_800F86D8_F92D8[arg0->unk_00[i].unk_1C].unk00;
    arg0->unk_00[i].unk_08 = arg2;
    arg0->unk_00[i].unk_0C = arg3;
    arg0->unk_00[i].unk_10 = arg4;
    arg0->unk_00[i].unk_18 = 0.0f;
    arg0->unk_00[i].unk_04 = 0;
    arg0->unk_04[i] = arg5;
    arg0->unk_00[i].unk_02 = arg1;
    arg0->unk_00[i].unk_06 = 0;
    func_800211E8_21DE8(arg0->unk_00[i].unk_1C, 0xFF);
    func_800298A4_2A4A4(obj, 4, 0);
    spr = &D_800F86D8_F92D8[arg0->unk_00[i].unk_1C];
    spr->unk0A = 0;
    spr->unk04 = 0;
    func_80021250_21E50(arg0->unk_00[i].unk_1C, arg0->unk_08, arg0->unk_09, arg0->unk_0A);
    func_80029714_2A314(obj, arg2, arg3, arg4);
    func_800297E8_2A3E8(obj, arg0->unk_0C, arg0->unk_10, arg0->unk_14);
    func_80029EDC_2AADC(obj, (s16) (1 << arg1));
    return i;
}

void func_800246F8_252F8(unk1EA70Struct1C* arg0, s16 arg1, s16 arg2) {
    s16 obj;

    if (arg1 == -1) {
        return;
    }
    obj = D_800F86D8_F92D8[arg0->unk_00[arg1].unk_1C].unk00;
    if (arg2 == 0) {
        func_800298A4_2A4A4(obj, 4, 0);
        D_800F86D8_F92D8[arg0->unk_00[arg1].unk_1C].unk04 = 0;
        arg0->unk_00[arg1].unk_06 = 0;
    } else {
        func_800298A4_2A4A4(obj, 4, 4);
        arg0->unk_00[arg1].unk_06 = arg2;
    }
}

void func_800247EC_253EC(unk1EA70Struct1C* arg0, f32 arg1, f32 arg2, f32 arg3) {
    arg0->unk_0C = arg1;
    arg0->unk_10 = arg2;
    arg0->unk_14 = arg3;
}

void func_800247FC_253FC(unk1EA70Struct1C* arg0, u8 arg1, u8 arg2, u8 arg3) {
    arg0->unk_08 = arg1;
    arg0->unk_09 = arg2;
    arg0->unk_0A = arg3;
}

/* Clears the per-character texture-animation slots (6 characters, 3 sets, 13 each) and the 13
   colours (cf. MP1 func_80021B14's slot reset). */
// register allocation only (masked 0): retail keeps i in t0, j in a2
#ifdef NON_MATCHING
void func_8002480C_2540C(void) {
    s16 k;
    s16 j;
    s16 i;

    for (i = 0; i < 6; i++) {
        D_801026FC_1032FC[i] = 0;
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 13; k++) {
                D_800FFE00_100A00[i][j][k] = -1;
            }
        }
    }
    for (i = 0; i < 13; i++) {
        D_800FDCA0_FE8A0[i][0] = D_800FDCA0_FE8A0[i][1] = D_800FDCA0_FE8A0[i][2] = 0xFF;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/21920", func_8002480C_2540C);
#endif

/* Loads texture animation arg2 & 0xF of set (arg2 & 0xC0) for character arg1 onto model arg0
   (MP1 func_80021B14/func_80021CDC). */
// retail copies arg2 to v1 and masks idx from it after the switch (masked 3, same logic)
#ifdef NON_MATCHING
void func_80024938_25538(s16 arg0, s16 arg1, s32 arg2) {
    void* file;
    u8 flag;
    s16 idx;
    s32 dataNum;

    D_801026FC_1032FC[arg1] = 1;
    flag = 0;
    idx = arg2 & 0xF;
    switch (arg2 & 0xC0) {
        case 0x40:
            flag = 1;
            break;
        case 0x80:
            flag = 0;
            break;
        case 0:
            flag = 2;
            break;
    }
    dataNum = func_80024AB4_256B4(arg1, flag, idx);
    if (dataNum != -1) {
        file = DataRead(dataNum);
        D_800FFE00_100A00[arg1][flag][idx] = func_8003D8F0_3E4F0(D_800FC834_FD434[arg0].hmf, file, 0, D_800C9C68_CA868[flag * 6 + arg1]);
        DataClose(file);
        func_80029A8C_2A68C(arg0);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/21920", func_80024938_25538);
#endif

/* Data number of character arg0's texture animation arg2 in set arg1 (MP1 func_80021C50). */
s32 func_80024AB4_256B4(s16 arg0, s16 arg1, s16 arg2) {
    return (D_800C9C5C_CA85C[arg0] << 16) | D_800C9CB0_CA8B0[arg2 * 3 + arg1];
}

/* Loads, or reloads in place, texture animation arg2 & 0xF of set (arg2 & 0xC0) for character
   arg1 on model arg0 (MP1 func_80021CDC). */
// as func_80024938_25538: retail copies arg2 and masks the index from the copy (masked 10, same logic)
#ifdef NON_MATCHING
void func_80024B00_25700(s16 arg0, s16 arg1, s32 arg2) {
    void* file;
    u8 flag;
    s16 idx;
    u16 old;
    s32 dataNum;

    flag = 0;
    switch (arg2 & 0xC0) {
        case 0x40:
            flag = 1;
            break;
        case 0x80:
            flag = 0;
            break;
        case 0:
            flag = 2;
            break;
    }
    idx = arg2 & 0xF;
    if (D_800FFE00_100A00[arg1][flag][idx] == -1) {
        dataNum = func_80025718_26318(arg1, flag, idx);
        if (dataNum != -1) {
            file = DataRead(dataNum);
            D_800FFE00_100A00[arg1][flag][idx] = func_8003D8F0_3E4F0(D_800FC834_FD434[arg0].hmf, file, 0, D_800C9C68_CA868[flag * 6 + arg1]);
            DataClose(file);
        }
    } else {
        old = D_800FFE00_100A00[arg1][flag][idx];
        D_800FFE00_100A00[arg1][flag][idx] = func_8003DBE8_3E7E8(D_800FC834_FD434[arg0].hmf, old, 0, D_800C9C68_CA868[flag * 6 + arg1]);
        func_8003E888_3F488(old);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/21920", func_80024B00_25700);
#endif

void func_80024D10_25910(void) {
    omAddObj(0x7F76, 0, 0, -1, func_80024D58_25958);
    D_800F904C_F9C4C = func_800240C8_24CC8(0x13, 10);
}

void func_80024D58_25958(void) {
    func_800242BC_24EBC(D_800F904C_F9C4C);
}

void func_80024D78_25978(s16 arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 x;
    f32 y;
    f32 z;
    f32 scale;
    s16 i;
    s16 slot;
    s16 idx;
    s32 spr;
    s32 pad[2];

    if (arg0 == 0) {
        func_800247EC_253EC(D_800F904C_F9C4C, 12.0f, 12.0f, 12.0f);
        idx = D_800F904C_F9C4C->unk_00[func_800244F4_250F4(D_800F904C_F9C4C, 0, arg1, arg2, arg3, 4)].unk_1C;
        HmfModelObjAttrSet(D_800F86D8_F92D8[idx].unk00, 0x70000000, 0x70000000);
        func_80029F2C_2AB2C(D_800F86D8_F92D8[idx].unk00, 0x1400);
        func_80021424_22024(idx, (u32) D_800C9D14_CA914);
        D_800F86D8_F92D8[idx].unk10 |= 0x100;
    } else if (arg0 == 1) {
        func_800247EC_253EC(D_800F904C_F9C4C, 12.0f, 12.0f, 12.0f);
        idx = D_800F904C_F9C4C->unk_00[func_800244F4_250F4(D_800F904C_F9C4C, 0, arg1, arg2, arg3, 4)].unk_1C;
        HmfModelObjAttrSet(D_800F86D8_F92D8[idx].unk00, 0x70000000, 0x70000000);
        func_80029F2C_2AB2C(D_800F86D8_F92D8[idx].unk00, 0x1400);
        func_80021424_22024(idx, (u32) D_800C9D50_CA950);
        D_800F86D8_F92D8[idx].unk10 |= 0x100;
    } else {
        for (i = 0; i < 4; i++) {
            if ((i == 0) | (i == 3)) {
                x = arg1;
                y = arg2;
                z = arg3;
            } else {
                x = arg1 + ((rand8() & 0x1F) - 0x10) * 12.0f;
                y = arg2 + ((rand8() & 0x1F) - 0x10) * 12.0f;
                z = arg3 + ((rand8() & 0x1F) - 0x10) * 1.2f;
            }
            scale = (s16) (i * 2.4f + 12.0f);
            func_800247EC_253EC(D_800F904C_F9C4C, scale, scale, scale);
            slot = func_800244F4_250F4(D_800F904C_F9C4C, 0, x, y, z, 4);
            if (slot == -1) {
                break;
            }
            spr = (u16) D_800F904C_F9C4C->unk_00[slot].unk_1C;
            idx = D_800F904C_F9C4C->unk_00[slot].unk_1C;
            HmfModelObjAttrSet(D_800F86D8_F92D8[idx].unk00, 0x70000000, 0x70000000);
            func_80029F2C_2AB2C(D_800F86D8_F92D8[idx].unk00, 0x1400);
            switch (i) {
                case 0:
                    func_80021424_22024(spr, (u32) D_800C9D00_CA900);
                    break;
                case 1:
                    func_80021424_22024(spr, (u32) D_800C9D14_CA914);
                    break;
                case 2:
                    func_80021424_22024(spr, (u32) D_800C9D28_CA928);
                    break;
                case 3:
                    func_80021424_22024(spr, (u32) D_800C9D3C_CA93C);
                    break;
            }
            func_800246F8_252F8(D_800F904C_F9C4C, slot, i * 4);
            D_800F86D8_F92D8[(s16) spr].unk10 |= 0x100;
        }
    }
}

/* Sets model arg0's colour word in the model, its data and its motion slot. */
void func_8002523C_25E3C(s16 arg0, s32 arg1) {
    HmfModel* obj;

    obj = &D_800FC834_FD434[arg0];
    obj->unkB8 = arg1;
    if (obj->hmf != NULL) {
        obj->hmf->unkDC = arg1;
    }
    if (obj->unk02 != 0xFF) {
        D_800F92B4_F9EB4[obj->unk02].unk18 = arg1;
    }
}

/* MP1's neighbour in src/1EA70.c (func_8001E2D0) reads a field of a table by index the same way. */
void func_8002529C_25E9C(s16 index, s32 arg1) {
    D_800F92B4_F9EB4[index].unk18 = arg1;
}

/* Maps a data number (directory 2-7, file 0xD1-0xD3) to a texture-animation key, -1 if none. */
// retail re-extends a copy of arg0 for the 0xD1 test (masked 6, same logic)
#ifdef NON_MATCHING
s16 func_800252C4_25EC4(s32 arg0) {
    s16 ret;

    ret = -1;
    switch ((s16) (arg0 >> 16)) {
        case 6:
            ret = 0x500;
            break;
        case 5:
            ret = 0x400;
            break;
        case 4:
            ret = 0x300;
            break;
        case 7:
            ret = 0x200;
            break;
        case 3:
            ret = 0x100;
            break;
        case 2:
            ret = 0;
            break;
    }
    if (ret == -1) {
        return -1;
    }
    if ((s16) arg0 != 0xD3) {
        if ((s16) arg0 == 0xD2) {
            ret |= 1;
        } else if ((s16) arg0 == 0xD1) {
            ret |= 2;
        }
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/21920", func_800252C4_25EC4);
#endif

/* Replaces texture animation arg2 of set arg1 on model arg0 with data file arg3; returns the
   new animation's first frame. */
s16 func_80025384_25F84(s16 arg0, s16 arg1, s16 arg2, s32 arg3) {
    void* file;
    s16 slot;
    u16 ret;

    if (D_800FDCA0_FE8A0[arg2][arg1] != 0xFF) {
        func_8003E888_3F488(D_800FDCA0_FE8A0[arg2][arg1]);
        func_8003E888_3F488(D_80101658_102258[arg2][arg1]);
    }
    file = DataRead(arg3);
    slot = func_8003D8F0_3E4F0(D_800FC834_FD434[arg0].hmf, file, 0, D_800C9D64_CA964[arg2 + arg1 * 13]);
    D_80101658_102258[arg2][arg1] = slot;
    func_8003E4F4_3F0F4(slot, 1, 1);
    DataClose(file);
    ret = D_800FD7F8_FE3F8[slot].unk_00;
    D_800FDCA0_FE8A0[arg2][arg1] = func_8003DBE8_3E7E8(D_800FC834_FD434[arg0].hmf, slot, 0, D_800C9D64_CA964[arg2 + arg1 * 13]);
    func_80029A8C_2A68C(arg0);
    return ret;
}

/* Pauses (arg3 -1) or restarts at frame arg3 the texture animation arg2 of set arg1 on model arg0. */
void func_80025554_26154(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    TexAnimSlot* p;

    if (D_800FDCA0_FE8A0[arg2][arg1] != 0xFF) {
        if (arg3 == -1) {
            func_8003EE44_3FA44(D_800FC834_FD434[arg0].hmf);
            return;
        }
        func_8003EEA4_3FAA4(D_800FC834_FD434[arg0].hmf);
        p = &D_800FD7F8_FE3F8[D_800FDCA0_FE8A0[arg2][arg1]];
        p->unk_00 = arg3;
        p->unk_04 = 0;
        p->unk_0A = 0;
        p->unk_06 = 0;
        p->unk_02 = 0;
    }
}

s16 func_80025684_26284(s32 id) {
    void* file;
    s16 sprite;

    file = DataRead(id);
    sprite = func_8003DF08_3EB08(file);
    DataClose(file);
    return sprite;
}

void func_800256CC_262CC(s16 arg0, s16 arg1, s32 arg2, s32 arg3) {
    func_8003E4F4_3F0F4(D_800FDCA0_FE8A0[arg1][arg0], arg2, arg3);
}

/* func_80024AB4_256B4 for reloads: its own file table. */
s32 func_80025718_26318(s16 arg0, s16 arg1, s16 arg2) {
    return (D_800C9C5C_CA85C[arg0] << 16) | D_800C9E00_CAA00[arg2 * 3 + arg1];
}
