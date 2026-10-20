#include "common.h"
#include "game/hmfman.h"

/* Minigame player helpers. Functions with C come from MP1 src/99E0.c and MP3
   src/overlays/minigame/B3CE0.c; MP2's work block is laid out differently (offsets below). */

/* omObjData::unk_50 work block (MP1 MgWork; MP2 offsets) */
typedef struct MgWork {
    /* 0x00 */ char unk_00[0x38];
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ char unk_44[8];
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ u16 unk_50; /* flags */
    /* 0x52 */ char unk_52[3];
    /* 0x55 */ u8 unk_55;
    /* 0x56 */ char unk_56;
    /* 0x57 */ s8 unk_57; /* controller port (MP1 0x56) */
    /* 0x58 */ u8 unk_58; /* stick sample index (MP1 0x57) */
    /* 0x59 */ s8 unk_59; /* player (MP1 0x58) */
    /* 0x5A */ char unk_5A[2];
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ char unk_64[0x10];
    /* 0x74 */ s32 unk_74[6]; /* packed (x << 16) | (y & 0xFFFF) stick samples (MP1 0x6C) */
    /* 0x8C */ char unk_8C[0x38];
    /* 0xC4 */ s8 unk_C4; /* MP1 0xB2 */
    /* 0xC5 */ s8 unk_C5; /* MP1 0xB3 */
} MgWork;

#define MG_WORK(obj) ((MgWork*)(obj)->unk_50)

typedef struct {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ char unk_02[0x22];
} unk_800ECDE0; // size 0x24

extern unk_800ECDE0* D_800F86D8_F92D8;
extern u16 D_800F8FE0_F9BE0;
extern omObjData* D_800FC7B0_FD3B0[];
extern u8 D_800BF794_C0394;
extern u16 D_800BF7E4_C03E4[][14];
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

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000BCE0_C8E0);

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

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000BE74_CA74);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000BE80_CA80);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000BE8C_CA8C);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000BE98_CA98);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000BEA4_CAA4);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000BEB0_CAB0);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000BEBC_CABC);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000BEC8_CAC8);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000BED4_CAD4);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000BEE0_CAE0);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000BEEC_CAEC);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000BEF8_CAF8);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000BF24_CB24);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000BF54_CB54);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000BF8C_CB8C);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000BFA8_CBA8);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000BFC8_CBC8);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000BFDC_CBDC);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000BFF0_CBF0);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000C004_CC04);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000C018_CC18);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000C024_CC24);

void func_8000C038_CC38(omObjData* obj, u8 idx, u8 on) {
    if (on == 0) {
        func_800298A4_2A4A4(obj->model[idx], 4, 4);
    } else {
        func_800298A4_2A4A4(obj->model[idx], 4, 0);
    }
}

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000C098_CC98);

void func_8000C11C_CD1C(omObjData* obj, s32 dir, s32 file, s32 arg3) {
    MgWork* work = MG_WORK(obj);

    work->unk_55 = func_80018D64_19964(dir, file, arg3);
    obj->model[0] = D_800F86D8_F92D8[work->unk_55].unk_00;
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

    obj->model[(u8)idx] = D_800F86D8_F92D8[(u8)img].unk_00;
    work += (u8)idx;
    work[0x21] = img;
    HmfModelObjAttrSet(D_800F86D8_F92D8[(u8)img].unk_00, 0x70000000, 0x70000000);
    func_80021160_21D60((u8)img, 4, 4);
}

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000C35C_CF5C);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000C36C_CF6C);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000C37C_CF7C);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000C38C_CF8C);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000C398_CF98);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000C3A8_CFA8);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000C3B8_CFB8);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000C3C8_CFC8);

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

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000C56C_D16C);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000C578_D178);

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

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000C6FC_D2FC);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000CC74_D874);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000CD28_D928);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000CDC8_D9C8);

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

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000D434_E034);

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

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000D81C_E41C);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000D900_E500);

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

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000DA98_E698);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000DB30_E730);

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000DC10_E810);

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

INCLUDE_ASM("asm/nonmatchings/C8E0", func_8000DF74_EB74);

void func_8000E030_EC30(omObjData* a, omObjData* b) {
    MgWork* bw = MG_WORK(b);

    func_8000DF74_EB74(MG_WORK(a), a->trans.x - b->trans.x, a->trans.z - b->trans.z);
    func_8000DF74_EB74(bw, b->trans.x - a->trans.x, b->trans.z - a->trans.z);
}
