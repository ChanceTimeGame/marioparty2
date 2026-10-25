#include "common.h"
#include "game/hmfman.h"
#include "game/sprite.h"

/* Minigame player helpers. Functions with C come from MP1 src/99E0.c and MP3
   src/overlays/minigame/B3CE0.c; MP2's work block is laid out differently (offsets below). */

/* omObjData::unk_50 work block (MP1 MgWork; MP2 offsets) */
typedef struct MgWork {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ u8 unk_04; /* player id (MP1 0x05) */
    /* 0x05 */ char unk_05;
    /* 0x06 */ u16 unk_06; /* flags (MP1 u8 0x01) */
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ char unk_0C[4];
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14; /* also an s32 (func_8000BF24_CB24) */
    /* 0x18 */ char unk_18[0x1C];
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ char unk_44[4];
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50; /* flags */
    /* 0x52 */ u8 unk_52;
    /* 0x53 */ char unk_53[2];
    /* 0x55 */ u8 unk_55;
    /* 0x56 */ char unk_56;
    /* 0x57 */ s8 unk_57; /* controller port (MP1 0x56) */
    /* 0x58 */ u8 unk_58; /* stick sample index (MP1 0x57) */
    /* 0x59 */ s8 unk_59; /* player (MP1 0x58) */
    /* 0x5A */ u8 unk_5A; /* model of the last motion (func_8000CC74_D874) */
    /* 0x5B */ u8 unk_5B; /* that motion */
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ f32 unk_68;
    /* 0x6C */ f32 unk_6C;
    /* 0x70 */ f32 unk_70;
    /* 0x74 */ s32 unk_74[6]; /* packed (x << 16) | (y & 0xFFFF) stick samples (MP1 0x6C) */
    /* 0x8C */ f32 unk_8C;
    /* 0x90 */ char unk_90[0xC];
    /* 0x9C */ f32 unk_9C;
    /* 0xA0 */ f32 unk_A0;
    /* 0xA4 */ f32 unk_A4;
    /* 0xA8 */ f32 unk_A8;
    /* 0xAC */ f32 unk_AC;
    /* 0xB0 */ f32 unk_B0;
    /* 0xB4 */ f32 unk_B4;
    /* 0xB8 */ char unk_B8[0xB];
    /* 0xC3 */ s8 unk_C3;
    /* 0xC4 */ s8 unk_C4; /* MP1 0xB2 */
    /* 0xC5 */ s8 unk_C5; /* MP1 0xB3 */
    /* 0xC6 */ char unk_C6[2];
    /* 0xC8 */ omObjData* unk_C8; /* held item (MP1 0xB8) */
    /* 0xCC */ f32 unk_CC;
    /* 0xD0 */ u16 unk_D0;
    /* 0xD2 */ char unk_D2[0x16];
    /* 0xE8 */ struct MgMotion* unk_E8;
    /* 0xEC */ s32 (*unk_EC)(omObjData* obj, omObjData* actor); /* actor touch hook (game/collision.h) */
    /* 0xF0 */ u16 unk_F0;
    /* 0xF2 */ char unk_F2[0x12];
    /* 0x104 */ union {
        s32 (*words[21])(); /* the minigame's override hooks (game/collision.h) */
        struct {
            s32 (*unk_00[19])();
            /* 0x150 */ s32 (*drop)(omObjData* obj, omObjData* item); /* may refuse a drop (returns 1) */
            s32 (*unk_4C)();
        } s;
    } unk_104;
    /* 0x158 */ char unk_158[4];
} MgWork; // size 0x15C

typedef struct MgMotion {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x08 */ s32 unk_08;
} MgMotion; // size 0xC

#define MG_WORK(obj) ((MgWork*)(obj)->unk_50)
/* With MgWork::unk_06 & 0x80 two matrices are kept at 0x18 and 0x58 (func_8000D434_E034). */
#define MG_MTX(w, off) ((f32(*)[4])((u8*)(w) + (off)))

typedef f32 Matrix4f[4][4];

/* Work block of an item a player can carry (MgWork::unk_C8; MP1 MgItemWork). */
typedef struct MgItemWork {
    /* 0x00 */ char unk_00[0x50];
    /* 0x50 */ u16 unk_50; /* flags: 0x10 carried, 0x20 can be picked up, 0x40 passed to the holder */
    /* 0x52 */ char unk_52[0x22];
    /* 0x74 */ f32 unk_74; /* holder's unk_B4 while carried */
    /* 0x78 */ char unk_78[8];
    /* 0x80 */ omObjData* unk_80; /* carrier */
} MgItemWork;

/* XZ bounds of a collision model. */
typedef struct MgColBounds {
    /* 0x00 */ char unk_00[0x42];
    /* 0x42 */ s16 minX;
    /* 0x44 */ s16 minY;
    /* 0x46 */ s16 minZ;
    /* 0x48 */ s16 maxX;
    /* 0x4A */ s16 maxY;
    /* 0x4C */ s16 maxZ;
} MgColBounds;

/* Per-character data (D_800CD438_CE038, 0x18 bytes each). */
typedef struct MgCharData {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 unk_04; /* the character's file directory */
    /* 0x08 */ char unk_08[0x10];
} MgCharData;

extern MgCharData D_800CD438_CE038[];
extern s32 D_800BF860_C0460[]; /* per character */
s16 func_80025384_25F84(s16 arg0, s16 arg1, s16 arg2, s32 arg3);
void func_80025554_26154(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
s32 func_80025718_26318(s16 arg0, s16 arg1, s16 arg2);
void func_80030CD4_318D4(Matrix4f dst, Matrix4f src);
void func_800B1F50_B2B50(Matrix4f m, f32 x, f32 y, f32 z);
void func_800B37C0_B43C0(Matrix4f m);
void func_80025884_26484(Matrix4f m, f32 x, f32 y, f32 z);
void func_8001B170_1BD70(Matrix4f src, Matrix4f dst);
void guMtxCatF(float m[4][4], float n[4][4], float r[4][4]);
void func_80001F44_2B44(omObjData* obj, omObjData* item);
void func_8002C628_2D228(s16 arg0, s16 arg1, char* arg2);
void func_8000C584_D184(void* arg0, s32 arg1);

extern u16 D_800F8FE0_F9BE0;
extern omObjData* D_800FC7B0_FD3B0[];
extern u8 D_800BF794_C0394;
/* .data head (0xC03E0-0xC0480; objects' .data start 16-aligned, so 1130's debug-menu row is the
   first variable here, not the last of 1130's); the rest of C8E0's map range (the fault-screen font from 0xC0480,
   7D1D0's tables) stays in the blob. Overlay asm names each element of row 0 (undefined_syms.txt). */
s8 D_800BF7E0_C03E0 = 0; /* 1130's debug menu: row */
u16 D_800BF7E4_C03E4[4][14] = {
    { 0x34, 0x3B, 0x49, 0x42, 0x50, 0x57, 0x5E, 0xA4, 0xA5, 0xA6, 0x65, 0x6C, 0xAA, 0xAC },
    { 0x35, 0x3C, 0x4A, 0x43, 0x51, 0x58, 0x5F, 0xA4, 0xA5, 0xA6, 0x66, 0x6D, 0xAA, 0xAC },
    { 0x36, 0x3D, 0x4B, 0x44, 0x52, 0x59, 0x60, 0xA4, 0xA5, 0xA6, 0x67, 0x6E, 0xAA, 0xAC },
    { 0x37, 0x3E, 0x4C, 0x45, 0x53, 0x5A, 0x61, 0xA4, 0xA5, 0xA6, 0x68, 0x6F, 0xAA, 0xAC },
};
s32 D_800BF854_C0454[3] = { 0, 0, 0 }; /* unreferenced */
s32 D_800BF860_C0460[8] = {
    0x000200DE, 0x000300DE, 0x000700DE, 0x000400DE, 0x000500DE, 0x000600DE, 0, 0,
};
extern u16 D_800F6090_F6C90[];
extern u16 D_800FC87A_FD47A;
extern omObjData* D_800FFFD8_100BD8[];
extern u16 D_800F64B8_F70B8[];
extern u8 D_800F8C50_F9850[];
extern s8 D_800FA6F0_FB2F0[];
extern s8 D_800FC898_FD498[];
extern s16 D_800FD86A_FE46A[];
extern u8 D_80102704_103304[];
extern f32 D_800BF7A4_C03A4;
extern f32 D_800BF7C0_C03C0;
extern s8 ContStkX[];
extern s8 ContStkY[];

extern u8 D_800BF795_C0395;
extern u8 D_800BF79A_C039A;
extern f32 D_800BF79C_C039C;
extern f32 D_800BF7A0_C03A0;
extern f32 D_800BF7A4_C03A4;
extern f32 D_800BF7A8_C03A8;
extern f32 D_800BF7AC_C03AC;
extern f32 D_800BF7B0_C03B0;
extern f32 D_800BF7BC_C03BC;
extern f32 D_800BF7C0_C03C0;
extern f32 D_800BF7C4_C03C4;
extern f32 D_800BF7C8_C03C8;
extern f32 D_800BF7CC_C03CC;
extern s32 D_800BF7D0_C03D0;
extern f32 D_800BF7D4_C03D4;
extern f32 D_800BF7D8_C03D8;
extern f32 D_800BF7DC_C03DC;

s16 LoadFormFile(s32, s32);
void func_8002CB0C_2D70C(s16 arg0, s16 arg1, f32 arg2);
f32 func_8002D958_2E558(f32);
void func_800298A4_2A4A4(s16, s32, s32);
u16 func_80018D64_19964(s32, s32, s32);
void HmfModelObjAttrSet(s16, s32, s32);
s16 func_80018A64_19664(s32, s32);
u8 func_80018DC0_199C0(void* arg0, s32 arg1, char* arg2);
void func_80029A8C_2A68C(s16);
void func_8003E4F4_3F0F4(s16 arg0, u8 arg1, u8 arg2);
void func_800297E8_2A3E8(s16 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_80021160_21D60(s16, s32, s32);
void func_800B0EF0_B1AF0(void*, s32, s32);
s8 func_80079798_7A398(s16, s8);
void func_80079848_7A448(s8);
f32 func_800B1830_B2430(f32);
void func_8002D9AC_2E5AC(Vec*);
f32 func_800B75A8_B81A8(f32, f32);
void func_8002C570_2D170(s16);
f32 func_800B3500_B4100(Vec*, Vec*);
void func_80019B9C_1A79C(omObjData*, s32);
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32);
void func_8000CE80_DA80(s16* x, s16* y);
s32 func_8000CDC8_D9C8(omObjData* obj, s16 x, s16 y);
f32 func_8000DA2C_E62C(f32 x1, f32 z1, f32 x2, f32 z2);
void func_8000DF74_EB74(MgWork*, f32, f32);
int abs(int);
void* func_80027154_27D54(s32 size, s32 tag); /* HuMemAllocTag */
void func_8000BCE0_C8E0(omObjData* obj, u16 idx, u16 player, s32 file, s32 flags, f32 arg5);
void func_8000BE74_CA74(omObjData* obj, f32 arg1);
void func_8000BEB0_CAB0(omObjData* obj, f32 arg1);
void func_8000BEBC_CABC(omObjData* obj, f32 arg1);
void func_8000BEC8_CAC8(omObjData* obj, f32 arg1);
void func_8000BED4_CAD4(omObjData* obj, f32 arg1);
void func_8000BEE0_CAE0(omObjData* obj, f32 arg1);
void func_8000BEEC_CAEC(omObjData* obj, f32 arg1);
void func_8003C8E0_3D4E0(s16);
void func_80007790_8390(omObjData* obj);
extern u8 D_800BF799_C0399;
extern s32 D_800BF790_C0390; /* scene state, copied to D_800F8FD0_F9BD0 */
extern s32 D_800F8FD0_F9BD0;

/* Loads player `player`'s character model into slot idx (MP1 func_80008DE0's shape). */
void func_8000BCE0_C8E0(omObjData* obj, u16 idx, u16 player, s32 file, s32 flags, f32 arg5) {
    s32 dir = D_800BF860_C0460[gPlayers[player].character];
    s16 mot;

    obj->model[idx] = LoadFormFile(file, flags & ~0x11);
    mot = func_80025384_25F84(obj->model[idx], 0, gPlayers[player].character, dir);
    func_80025554_26154(obj->model[idx], 0, gPlayers[player].character, mot);
}

void func_8000BDC4_C9C4(omObjData* obj, u16 idx, s32 dir, s32 file, f32 arg4) {
    s16 mdl = LoadFormFile(dir, file);

    obj->model[idx] = mdl;
    func_8002CB0C_2D70C(obj->model[0], mdl, arg4);
}

void func_8000BE38_CA38(omObjData* obj, f32 angle) {
    MgWork* work = MG_WORK(obj);

    work->unk_3C = func_8002D958_2E558(angle);
}

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000BE68_CA68);

void func_8000BE74_CA74(omObjData* obj, f32 arg1) {
    MG_WORK(obj)->unk_38 = arg1;
}

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000BE80_CA80);

void func_8000BE8C_CA8C(omObjData* obj, f32 arg1) {
    MG_WORK(obj)->unk_08 = arg1;
}

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000BE98_CA98);

void func_8000BEA4_CAA4(omObjData* obj, f32 arg1) {
    MG_WORK(obj)->unk_10 = arg1;
}

void func_8000BEB0_CAB0(omObjData* obj, f32 arg1) {
    MG_WORK(obj)->unk_48 = arg1;
}

void func_8000BEBC_CABC(omObjData* obj, f32 arg1) {
    MG_WORK(obj)->unk_34 = arg1;
}

void func_8000BEC8_CAC8(omObjData* obj, f32 arg1) {
    MG_WORK(obj)->unk_64 = arg1;
}

void func_8000BED4_CAD4(omObjData* obj, f32 arg1) {
    MG_WORK(obj)->unk_68 = arg1;
}

void func_8000BEE0_CAE0(omObjData* obj, f32 arg1) {
    MG_WORK(obj)->unk_6C = arg1;
}

void func_8000BEEC_CAEC(omObjData* obj, f32 arg1) {
    MG_WORK(obj)->unk_70 = arg1;
}

void func_8000BEF8_CAF8(omObjData* obj, s32 flags, f32 arg2) {
    MgWork* work = MG_WORK(obj);

    work->unk_06 = (u8)flags | work->unk_06;
    if (flags & 2) {
        work->unk_14 = arg2;
    }
}

/* Hit box: radius and XZ bounds (callers pass arg1 as a float). */
void func_8000BF24_CB24(omObjData* obj, f32 arg1, f32 minX, f32 minZ, f32 maxX, f32 maxZ) {
    MgWork* work = MG_WORK(obj);

    work->unk_06 |= 8;
    work->unk_14 = arg1;
    work->unk_A0 = minX;
    work->unk_A4 = minZ;
    work->unk_A8 = maxX;
    work->unk_AC = maxZ;
}

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000BF54_CB54);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000BF8C_CB8C);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000BFA8_CBA8);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000BFC8_CBC8);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000BFDC_CBDC);

void func_8000BFF0_CBF0(omObjData* obj) {
    MG_WORK(obj)->unk_06 |= 0x200;
}

void func_8000C004_CC04(omObjData* obj) {
    MG_WORK(obj)->unk_06 |= 0x400;
}

void func_8000C018_CC18(u16 arg0) {
    D_800BF794_C0394 = arg0;
}

void func_8000C024_CC24(omObjData* obj, u8 idx, u8 val) {
    u8* work = obj->unk_50;

    work[idx] = val;
}

void func_8000C038_CC38(omObjData* obj, u8 idx, u8 on) {
    if (on == 0) {
        func_800298A4_2A4A4(obj->model[idx], 4, 4);
    } else {
        func_800298A4_2A4A4(obj->model[idx], 4, 0);
    }
}

/* MP1 func_80009138: 0 when player `id`'s object has flag 0x200 (or id < 0). */
s32 func_8000C098_CC98(s8 id) {
    s32 i;
    MgWork* work;

    if (id < 0) {
        return 0;
    }
    for (i = 0; i < D_800F8FE0_F9BE0; i++) {
        work = MG_WORK(D_800FC7B0_FD3B0[i]);
        if (work->unk_04 == id) {
            if (work->unk_06 & 0x200) {
                return 0;
            }
            break;
        }
    }
    return 1;
}

void func_8000C11C_CD1C(omObjData* obj, s32 dir, s32 file, s32 arg3) {
    MgWork* work = MG_WORK(obj);

    work->unk_55 = func_80018D64_19964(dir, file, arg3);
    obj->model[0] = D_800F86D8_F92D8[work->unk_55].unk00;
    HmfModelObjAttrSet(obj->model[0], 0x70000000, 0x70000000);
}

void func_8000C198_CD98(omObjData* obj, u8 idx, s32 dir, s32 arg3, char* arg4, s32 arg5) {
    u8* work = obj->unk_50;
    HmfModel* m;
    u8 r;

    obj->model[idx] = func_80018A64_19664(dir, arg5);
    m = &D_800FC834_FD434[obj->model[idx]];
    r = func_80018DC0_199C0(m->hmf, arg3, arg4);
    (work + idx)[0x21] = r;
    func_80029A8C_2A68C(obj->model[idx]);
    func_8003E4F4_3F0F4(r, 1, 1);
    func_8003E4F4_3F0F4(r, 2, 2);
    func_800297E8_2A3E8(obj->model[idx], 2.0f, 2.0f, 2.0f);
}

void func_8000C2A0_CEA0(omObjData* obj, s32 idx, s32 dir, s32 file, s32 arg4) {
    u8* work = obj->unk_50;
    u16 img = func_80018D64_19964(dir, file, arg4);

    obj->model[(u8)idx] = D_800F86D8_F92D8[(u8)img].unk00;
    work += (u8)idx;
    work[0x21] = img;
    HmfModelObjAttrSet(D_800F86D8_F92D8[(u8)img].unk00, 0x70000000, 0x70000000);
    func_80021160_21D60((u8)img, 4, 4);
}

void func_8000C35C_CF5C(omObjData* obj, f32 x, f32 y, f32 z) {
    obj->trans.x = x;
    obj->trans.y = y;
    obj->trans.z = z;
}

void func_8000C36C_CF6C(omObjData* obj, f32 x, f32 y, f32 z) {
    obj->rot.x = x;
    obj->rot.y = y;
    obj->rot.z = z;
}

void func_8000C37C_CF7C(omObjData* obj, f32 x, f32 y, f32 z) {
    obj->scale.x = x;
    obj->scale.y = y;
    obj->scale.z = z;
}

void func_8000C38C_CF8C(void) {
    D_800BF790_C0390 = 0;
}

void func_8000C398_CF98(void) {
    D_800BF790_C0390 = 2;
}

void func_8000C3A8_CFA8(void) {
    D_800BF790_C0390 = 3;
}

void func_8000C3B8_CFB8(void) {
    D_800BF790_C0390 = 1;
}

void func_8000C3C8_CFC8(void) {
    D_800F8FD0_F9BD0 = D_800BF790_C0390;
}

s32 func_8000C3DC_CFDC(s32 id) {
    s32 i;

    for (i = 0; i < D_800F8FE0_F9BE0; i++) {
        if (((u8*)D_800FC7B0_FD3B0[i])[0x53] == id) {
            return i;
        }
    }
    return D_800BF794_C0394;
}

void func_8000C43C_D03C(void) {
    s32 buf;

    func_800B0EF0_B1AF0(&buf, 0, 1);
}

void func_8000C460_D060(void) {
    D_800BF79C_C039C = 15.0f;
    D_800BF7A0_C03A0 = 0.5f;
    D_800BF7A4_C03A4 = 1.45f;
    D_800BF7A8_C03A8 = 0.15f;
    D_800BF7AC_C03AC = 7.0f;
    D_800BF7B0_C03B0 = 30.0f;
    D_800BF7D8_C03D8 = 0.5f;
    D_800BF7BC_C03BC = 3.3333333f;
    D_800BF7C0_C03C0 = 18.0f;
    D_800BF7C4_C03C4 = 13.5f;
    D_800BF7C8_C03C8 = 9.0f;
    D_800BF7CC_C03CC = 4.5f;
    D_800BF7D0_C03D0 = 0;
    D_800BF7D4_C03D4 = 1.6f;
    D_800BF7DC_C03DC = 0.14500001f;
    D_800BF795_C0395 = 1;
    D_800BF79A_C039A = 0;
}

void func_8000C56C_D16C(s32 arg0) {
    D_800BF79A_C039A = arg0;
}

void func_8000C578_D178(s32 arg0) {
    D_800BF799_C0399 = arg0;
}

void func_8000C584_D184(void* arg0, s32 arg1) {
    MgWork* work = (MgWork*)arg0;
    s8 player = work->unk_59;
    u16 id = D_800BF7E4_C03E4[player][arg1];

    if (work->unk_C4 != arg1) {
        work->unk_C5 = func_80079798_7A398(id, player);
        work->unk_C4 = arg1;
        D_800F6090_F6C90[work->unk_59] = id;
    }
}

void func_8000C610_D210(MgWork* work, s32 arg1) {
    s8 player = work->unk_59;
    s16 id = D_800BF7E4_C03E4[player][arg1];

    work->unk_C5 = func_80079798_7A398(id, player);
    work->unk_C4 = arg1;
    D_800F6090_F6C90[work->unk_59] = id;
}

void func_8000C690_D290(void) {
    s32 i;

    for (i = 0; i < D_800FC87A_FD47A; i++) {
        func_80079848_7A448(MG_WORK(D_800FFFD8_100BD8[i])->unk_C5);
    }
}

/* MP3 func_800E1BA8_B4728_minigame (src/overlays/minigame/B3CE0.c) with MP2's motion table. */
void func_8000C6FC_D2FC(omObjData* obj, u32 arg1, s32 arg2, u16 arg3, s32 arg4, s32 arg5) {
    MgWork* work;
    s32 i;

    for (i = 0; i < obj->mdlcnt; i++) {
        obj->model[i] = 0;
    }
    obj->unk_50 = func_80027154_27D54(sizeof(MgWork), 31000);
    func_800B0EF0_B1AF0(obj->unk_50, 0, sizeof(MgWork));
    work = obj->unk_50;
    work->unk_E8 = func_80027154_27D54(obj->mtncnt * sizeof(MgMotion), 31000);
    if (D_800BF79A_C039A == 1) {
        func_8000BCE0_C8E0(obj, 0, arg3, arg1 | arg2, arg4, 750.0f);
    } else {
        obj->model[0] = LoadFormFile(arg1 | arg2, arg4);
    }
    obj->model[1] = func_80018A64_19664((D_800BF799_C0399 != 0) ? 13 : 1, arg5);
    func_8003C8E0_3D4E0(obj->model[1]);
    for (i = 0; i < obj->mtncnt; i++) {
        obj->motion[i] = -1;
    }
    for (i = 0; i < 21; i++) {
        work->unk_104.words[i] = NULL;
    }
    for (i = 0; i < obj->mtncnt; i++) {
        work->unk_E8[i].unk_00 = 0;
        work->unk_E8[i].unk_02 = 0;
        work->unk_E8[i].unk_04 = -1;
        work->unk_E8[i].unk_08 = -1;
    }
    work->unk_57 = gPlayers[arg3].port;
    obj->func_ptr = func_80007790_8390;
    work->unk_52 = 0;
    work->unk_B4 = 1.0f;
    work->unk_8C = 65536.0f;
    work->unk_D0 = 0xFFFF;
    work->unk_4C = 0.5f;
    work->unk_CC = 1.0f;
    work->unk_60 = 0;
    func_8000BEB0_CAB0(obj, 60.0f);
    func_8000BEBC_CABC(obj, 150.0f);
    func_8000BEC8_CAC8(obj, 20.0f);
    func_8000BED4_CAD4(obj, 30.0f);
    func_8000BEE0_CAE0(obj, 50.0f);
    func_8000BEEC_CAEC(obj, 40.0f);
    func_8000BE74_CA74(obj, 1000.0f);
    work->unk_9C = work->unk_A0 = work->unk_A4 = 0.0f;
    work->unk_59 = (s8) arg3;
    work->unk_C3 = -1;
    work->unk_C4 = -1;
    work->unk_B0 = 1.0f;
    switch (arg1 >> 16) {
        case 6:
            work->unk_AC = 0.7f;
            break;
        case 4:
            work->unk_AC = 0.9f;
            break;
        case 5:
            work->unk_AC = 0.8f;
            break;
        default:
            work->unk_AC = 1.0f;
            break;
    }
    i = gPlayers[arg3].character + 1;
    D_800BF7E4_C03E4[work->unk_59][0] = i + 0x33;
    D_800BF7E4_C03E4[work->unk_59][1] = i + 0x3A;
    D_800BF7E4_C03E4[work->unk_59][2] = i + 0x48;
    D_800BF7E4_C03E4[work->unk_59][3] = i + 0x41;
    D_800BF7E4_C03E4[work->unk_59][4] = i + 0x4F;
    D_800BF7E4_C03E4[work->unk_59][5] = i + 0x56;
    D_800BF7E4_C03E4[work->unk_59][6] = i + 0x5D;
    D_800BF7E4_C03E4[work->unk_59][7] = 0xA4;
    D_800BF7E4_C03E4[work->unk_59][8] = 0xA5;
    D_800BF7E4_C03E4[work->unk_59][9] = 0xA6;
    D_800BF7E4_C03E4[work->unk_59][10] = i + 0x64;
    D_800BF7E4_C03E4[work->unk_59][11] = i + 0x6B;
    D_800BF7E4_C03E4[work->unk_59][12] = 0xAA;
    D_800BF7E4_C03E4[work->unk_59][13] = 0xAC;
}

/* Plays motion `motion` of the player's character on model `model`. */
void func_8000CC74_D874(omObjData* obj, s16 model, s16 motion) {
    MgWork* work = MG_WORK(obj);
    s32 chr;
    s32 dir;

    work->unk_5A = model;
    work->unk_5B = motion;
    chr = gPlayers[work->unk_59].character;
    dir = D_800CD438_CE038[chr].unk_04;
    func_80025384_25F84(model, motion, chr, dir | func_80025718_26318(chr, motion, 0));
}

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000CD28_D928);

// register allocation: retail builds the packed sample in a0 (masked 2)
#ifdef NON_MATCHING
/* Averages the last six stick samples (MP1 func_80009C90). */
s32 func_8000CDC8_D9C8(omObjData* obj, s16 x, s16 y) {
    MgWork* work = MG_WORK(obj);
    s32 v;
    s16 sy;
    s16 sx;
    u8 i;

    v = (x << 16) | (y & 0xFFFF);
    work->unk_74[work->unk_58++] = v;
    if (work->unk_58 >= 6) {
        work->unk_58 = 0;
    }
    sy = 0;
    sx = 0;
    for (i = 0; i < 6; i++) {
        sx += work->unk_74[i] >> 16;
        sy += (u16)work->unk_74[i];
    }
    return ((sx / 6) << 16) | ((sy / 6) & 0xFFFF);
}
#else
INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000CDC8_D9C8);
#endif

void func_8000CE80_DA80(s16* x, s16* y) {
    Vec v;
    f32 fx = *x;
    f32 fy = *y;

    if (func_800B1830_B2430(fx * fx + fy * fy) > 60.0f) {
        v.x = fx;
        v.y = 0.0f;
        v.z = fy;
        func_8002D9AC_2E5AC(&v);
        *x = v.x * 60.0f;
        *y = v.z * 60.0f;
    }
}

void func_8000CF58_DB58(omObjData* obj) {
    MgWork* work = MG_WORK(obj);
    s32 i;

    for (i = 0; i < 6; i++) {
        work->unk_74[i] = 0;
    }
}

s16 func_8000CF84_DB84(s16 player, s16 limit, s8 x, s8 y) {
    s16 mult = 1;
    s16 quad;
    s16 d;
    s8 dir;

    if ((x == 0) & (y == 0)) {
        return 0;
    }
    quad = func_800B75A8_B81A8(y, x);
    if (quad < 0) {
        quad += 360;
    }
    quad /= 90;
    if (quad == D_800F8C50_F9850[player]) {
        if (++D_800FC898_FD498[player] > limit) {
            D_800FC898_FD498[player] = limit;
            D_800FA6F0_FB2F0[player] = 0;
            D_80102704_103304[player] = quad;
            D_800F64B8_F70B8[player] = 0;
            return 0;
        }
        D_800F64B8_F70B8[player]++;
        return D_800FA6F0_FB2F0[player];
    }
    D_800F64B8_F70B8[player]++;
    D_800FC898_FD498[player] = 0;
    if (D_80102704_103304[player] == quad) {
        mult = 2;
        D_800FD86A_FE46A[player] = D_800F64B8_F70B8[player];
        D_800F64B8_F70B8[player] = 0;
    }
    d = quad - D_800F8C50_F9850[player];
    if ((d < 0 ? -d : d) == 3) {
        d = -d;
    }
    dir = (d >> 31) | 1;
    if (dir != 0 && dir != D_800FA6F0_FB2F0[player]) {
        D_800FA6F0_FB2F0[player] = dir;
        D_800F8C50_F9850[player] = quad;
        D_800FC898_FD498[player] = 0;
        D_80102704_103304[player] = quad;
        D_800F64B8_F70B8[player] = 0;
        return 0;
    }
    D_800F64B8_F70B8[player]++;
    if (((D_800F8C50_F9850[player] + D_800FA6F0_FB2F0[player]) & 3) == quad) {
        D_800F8C50_F9850[player] = quad;
        return D_800FA6F0_FB2F0[player] * mult;
    }
    D_800FA6F0_FB2F0[player] = dir;
    D_800F8C50_F9850[player] = quad;
    D_800FC898_FD498[player] = 0;
    D_800F64B8_F70B8[player] = 0;
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000D2F8_DEF8);

/* Transforms p by obj's translation and rotation (or by the matrices stored in its work when
   flag 0x80 is set); m is scratch, out receives the matrix. MP1 func_8000A1C0 grown. */
void func_8000D434_E034(Matrix4f m, Matrix4f out, Vec* p, omObjData* obj) {
    MgWork* work = MG_WORK(obj);
    s32 mdl = obj->model[0];
    f32 rx = obj->rot.x;
    f32 ry = obj->rot.y;
    f32 rz = obj->rot.z;
    f32 tx = obj->trans.x;
    f32 ty = obj->trans.y;
    f32 tz = obj->trans.z;
    f32 x = p->x;
    f32 y = p->y;
    f32 z = p->z;

    if (work->unk_06 & 0x80) {
        func_80030CD4_318D4(m, MG_MTX(work, 0x18));
        func_80030CD4_318D4(out, MG_MTX(work, 0x58));
    } else {
        if (((tx != 0.0f) | (ty != 0.0f)) || tz != 0.0f) {
            func_800B1F50_B2B50(m, tx, ty, tz);
        } else {
            func_800B37C0_B43C0(m);
        }
        if (((rx != 0.0f) | (ry != 0.0f)) || rz != 0.0f) {
            func_80025884_26484(m, rx, ry, rz);
        }
        if (work->unk_06 & 0x100) {
            guMtxCatF((f32(*)[4])D_800FC834_FD434[mdl].mtx, m, m);
        }
        func_8001B170_1BD70(m, out);
    }
    p->x = x * out[0][0] + y * out[1][0] + z * out[2][0] + out[3][0];
    p->y = x * out[0][1] + y * out[1][1] + z * out[2][1] + out[3][1];
    p->z = x * out[0][2] + y * out[1][2] + z * out[2][2] + out[3][2];
}

void func_8000D6D0_E2D0(f32 m[4][4], Vec* v) {
    f32 x = v->x;
    f32 y = v->y;
    f32 z = v->z;

    v->x = x * m[0][0] + y * m[1][0] + z * m[2][0];
    v->y = x * m[0][1] + y * m[1][1] + z * m[2][1];
    v->z = x * m[0][2] + y * m[1][2] + z * m[2][2];
}

void func_8000D74C_E34C(f32 m[4][4], Vec* v) {
    f32 x = v->x;
    f32 y = v->y;
    f32 z = v->z;

    v->x = x * m[0][0] + y * m[1][0] + z * m[2][0] + m[3][0];
    v->y = x * m[0][1] + y * m[1][1] + z * m[2][1] + m[3][1];
    v->z = x * m[0][2] + y * m[1][2] + z * m[2][2] + m[3][2];
}

void func_8000D7E0_E3E0(f32 m[4][4], Vec* v) {
    f32 x = v->x;
    f32 y = v->y;
    f32 z = v->z;

    v->y = x * m[0][1] + y * m[1][1] + z * m[2][1] + m[3][1];
}

/* Drops the held item unless the holder's callback refuses (MP1 func_8000A534's flags). */
void func_8000D81C_E41C(omObjData* obj, f32 arg1) {
    MgWork* work = MG_WORK(obj);
    omObjData* item;
    MgItemWork* itemWork;

    if (work->unk_50 & 0x10) {
        item = work->unk_C8;
        itemWork = item->unk_50;
        if (work->unk_104.s.drop != NULL && work->unk_104.s.drop(obj, item) == 1) {
            return;
        }
        work->unk_50 &= ~0x150;
        itemWork->unk_50 &= ~0x10;
        func_800298A4_2A4A4(item->model[0], 0x4000, 0);
        func_8002C570_2D170(obj->model[0]);
        if (item->model[1] != 0) {
            func_800298A4_2A4A4(item->model[1], 4, 0);
        }
        func_80001F44_2B44(obj, item);
        work->unk_C8 = NULL;
        work->unk_B4 = 1.0f;
    }
}

/* Picks up `item` (MP1 func_8000A634). */
s32 func_8000D900_E500(omObjData* obj, omObjData* item) {
    MgWork* work = MG_WORK(obj);
    MgItemWork* itemWork = item->unk_50;

    if (!(itemWork->unk_50 & 0x20)) {
        return 0;
    }
    if (itemWork->unk_50 & 0x10) {
        return 0;
    }
    if (work->unk_50 & 0x10) {
        return 0;
    }
    work->unk_50 |= 0x110;
    itemWork->unk_50 |= 0x10;
    if (itemWork->unk_50 & 0x40) {
        work->unk_50 |= 0x40;
    }
    work->unk_C8 = item;
    itemWork->unk_80 = obj;
    func_8002C628_2D228(item->model[0], obj->model[0], "item_hook");
    func_800298A4_2A4A4(item->model[0], 0x4000, 0x4000);
    work->unk_B4 = itemWork->unk_74;
    if (item->model[1] != 0) {
        func_800298A4_2A4A4(item->model[1], 4, 4);
    }
    return 1;
}

void func_8000D9F4_E5F4(omObjData* obj) {
    MgWork* work = MG_WORK(obj);

    func_8002C570_2D170(obj->model[0]);
    work->unk_50 &= ~0x100;
}

f32 func_8000DA2C_E62C(f32 x1, f32 z1, f32 x2, f32 z2) {
    Vec a;
    Vec b;

    a.x = x1;
    a.y = 0.0f;
    a.z = z1;
    func_8002D9AC_2E5AC(&a);
    b.x = x2;
    b.y = 0.0f;
    b.z = z2;
    func_8002D9AC_2E5AC(&b);
    return func_800B3500_B4100(&b, &a);
}

s32 func_8000DA98_E698(MgColBounds* b, Vec* p) {
    f32 minX = b->minX;
    f32 minZ = b->minZ;
    f32 maxX = b->maxX;
    f32 maxZ = b->maxZ;

    if (minX <= p->x && minZ <= p->z && p->x <= maxX && p->z <= maxZ) {
        return 1;
    }
    return 0;
}

s32 func_8000DB30_E730(MgColBounds* b, Vec* p, f32 r) {
    f32 x = p->x;
    f32 z = p->z;
    f32 minX = b->minX - r;
    f32 maxZ;
    f32 maxX;
    f32 minZ = b->minZ - r;

    maxX = b->maxX + r;
    maxZ = b->maxZ + r;

    if ((minX <= x) & (minZ <= z)) {
        if ((x <= maxX) & (z <= maxZ)) {
            return 1;
        }
    }
    return 0;
}

/* Whether p is inside g's play area: a box (flag 0x10) or a circle (flag 0x40). */
s32 func_8000DC10_E810(Vec* p, MgWork* g) {
    f32 x;
    f32 z;

    if (!(g->unk_06 & 0x50)) {
        return 1;
    }
    x = p->x;
    z = p->z;
    if (g->unk_06 & 0x10) {
        if (g->unk_A0 <= x && x <= g->unk_A8 && g->unk_A4 <= z && z <= g->unk_AC) {
            return 1;
        }
    } else if (func_800B1830_B2430(x * x + z * z) <= g->unk_9C) {
        return 1;
    }
    return 0;
}

void func_8000DCD4_E8D4(omObjData* obj, f32 dx, f32 dz) {
    MgWork* work = MG_WORK(obj);
    s16 stick[2];
    s32 avg;

    if (work->unk_5C & 0x200) {
        work->unk_4C = 0.7f;
    } else {
        work->unk_4C = 0.6f;
    }
    func_80019B9C_1A79C(obj, 6);
    if (abs(ContStkX[work->unk_57]) >= 9 || abs(ContStkY[work->unk_57]) >= 9) {
        s32 sx = ContStkX[work->unk_57];
        s32 sy;

        stick[0] = sx;
        sy = ContStkY[work->unk_57];
        stick[1] = sy;
        if (sx > 60) {
            stick[0] = 60;
        }
        if (stick[1] > 60) {
            stick[1] = 60;
        }
        if (stick[0] < -60) {
            stick[0] = -60;
        }
        if (stick[1] < -60) {
            stick[1] = -60;
        }
        func_8000CE80_DA80(&stick[0], &stick[1]);
        func_8000CDC8_D9C8(obj, stick[0], stick[1]);
        func_8000CDC8_D9C8(obj, stick[0], stick[1]);
        func_8000CDC8_D9C8(obj, stick[0], stick[1]);
        func_8000CDC8_D9C8(obj, stick[0], stick[1]);
        func_8000CDC8_D9C8(obj, stick[0], stick[1]);
        avg = func_8000CDC8_D9C8(obj, stick[0], stick[1]);
        stick[0] = avg >> 16;
        stick[1] = avg;
        work->unk_3C = func_800B75A8_B81A8(stick[0], -stick[1]) + work->unk_60;
        work->unk_40 = D_800BF7C0_C03C0;
    } else if (func_8000DA2C_E62C(HuMathSin(work->unk_3C), func_800B7890_B8490(work->unk_3C), dx, dz) < 0.0f) {
        work->unk_40 = D_800BF7C0_C03C0;
    } else {
        work->unk_40 = -D_800BF7C0_C03C0;
    }
    work->unk_38 = -D_800BF7A4_C03A4 * 0.9f;
    work->unk_50 |= 0x8;
}

void func_8000DF74_EB74(MgWork* work, f32 dx, f32 dz) {
    f32 s = HuMathSin(work->unk_3C);

    if (func_8000DA2C_E62C(s, func_800B7890_B8490(work->unk_3C), dx, dz) >= 0.0f) {
        work->unk_40 = D_800BF7C4_C03C4;
    } else {
        work->unk_40 = -D_800BF7C4_C03C4;
    }
    work->unk_50 |= 8;
    func_8000C584_D184(work, 7);
}

void func_8000E030_EC30(omObjData* a, omObjData* b) {
    MgWork* bw = MG_WORK(b);

    func_8000DF74_EB74(MG_WORK(a), a->trans.x - b->trans.x, a->trans.z - b->trans.z);
    func_8000DF74_EB74(bw, b->trans.x - a->trans.x, b->trans.z - a->trans.z);
}
