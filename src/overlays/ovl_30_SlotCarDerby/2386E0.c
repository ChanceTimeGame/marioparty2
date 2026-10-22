#include "ovl_30.h"

__asm__(".section .rodata");
const char D_8010FC50_245B30_SlotCarDerby[32] = "\202r\202s\202`\202q\202s\202f\202n\202`\202k\202v\202h\202m\201I";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_80102800_2386E0_SlotCarDerby);

void func_80102BC0_238AA0_SlotCarDerby(omObjData* obj) {
    obj->func_ptr = func_80102BE4_238AC4_SlotCarDerby;
    func_80107E0C_23DCEC_SlotCarDerby();
}

void func_80102BE4_238AC4_SlotCarDerby(omObjData* obj) {
    if (D_801102D6_2461B6_SlotCarDerby != 0 && D_801102D8_2461B8_SlotCarDerby == 0) {
        InitFadeOut(0, 20);
        D_801102D8_2461B8_SlotCarDerby = 1;
        func_80079614_7A214(40);
    } else if (D_801102D8_2461B8_SlotCarDerby != 0 && D_801102DA_2461BA_SlotCarDerby == 0 && func_8008F618_90218() == 0) {
        D_801102DA_2461BA_SlotCarDerby = 1;
        func_80108D48_23EC28_SlotCarDerby();
        omOvlReturnEx(1);
        return;
    }
    func_80107F48_23DE28_SlotCarDerby(0, 270, 400);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_80102C98_238B78_SlotCarDerby);

void func_80102F6C_238E4C_SlotCarDerby(void) {
    s32 i;
    s32 j;
    s32 t;

    for (i = 0; i < 4; i++) {
        func_800B0EF0_B1AF0(&D_801102E8_2461C8_SlotCarDerby[i], 0, sizeof(SCDCar));
    }
    for (i = 0; i < 4; i++) {
        D_801107FA_2466DA_SlotCarDerby[i] = i;
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (i != j && ((((rand8() << 8) | rand8()) * 125) >> 13) < 500) {
                t = D_801107FA_2466DA_SlotCarDerby[i];
                D_801107FA_2466DA_SlotCarDerby[i] = D_801107FA_2466DA_SlotCarDerby[j];
                D_801107FA_2466DA_SlotCarDerby[j] = t;
            }
        }
    }
    D_801107F8_2466D8_SlotCarDerby = 0;
    D_80110802_2466E2_SlotCarDerby = 1;
    D_80110804_2466E4_SlotCarDerby = 1;
}

s32 func_801030B0_238F90_SlotCarDerby(s16 slot) {
    return func_80015388_15F88(slot) != 0;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_801030D4_238FB4_SlotCarDerby);

/* NON_MATCHING: registers only (retail copies n before the increment) */
#ifdef NON_MATCHING
void func_80103154_239034_SlotCarDerby(omObjData* obj) {
    SCDCar* car;
    s16 n;
    s32 lane;
    s32 i;

    n = D_801107F8_2466D8_SlotCarDerby;
    if (n < 4) {
        D_801107F8_2466D8_SlotCarDerby = n + 1;
        lane = D_801107FA_2466DA_SlotCarDerby[n];
        D_80110804_2466E4_SlotCarDerby = n + 1;
        car = &D_801102E8_2461C8_SlotCarDerby[lane];
        car->unk_00 = 1;
        car->unk_02 = 4;
        car->unk_01 = n;
        car->unk_78 = -1;
        car->unk_74 = -1;
        car->unk_60 = 0;
        car->unk_7C = obj;
        obj->work[1] = lane;
        for (i = 0; i < D_8010F430_245310_SlotCarDerby[D_8011023C_24611C_SlotCarDerby][lane]; i++) {
            car->unk_48 += D_80110248_246128_SlotCarDerby[i];
        }
        car->unk_48 += D_8010F448_245328_SlotCarDerby[D_8011023C_24611C_SlotCarDerby];
        func_80103874_239754_SlotCarDerby(obj->model[0], 0.0f);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_80103154_239034_SlotCarDerby);
#endif

void func_801032A0_239180_SlotCarDerby(omObjData* obj) {
    func_80103154_239034_SlotCarDerby(obj);
    func_80019B9C_1A79C(obj, 0);
    func_80103874_239754_SlotCarDerby(obj->model[0], 0.0f);
}

SCDCar* func_801032E0_2391C0_SlotCarDerby(omObjData* obj) {
    return &D_801102E8_2461C8_SlotCarDerby[obj->work[1]];
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_801032F8_2391D8_SlotCarDerby);

__asm__(".section .rodata");
const u32 D_8010FC80_245B60_SlotCarDerby[3] = { 0xC1000000, 0xC1200000, 0x41200000 };

__asm__(".section .rodata");
const u32 D_8010FC8C_245B6C_SlotCarDerby[3] = { 0x80000000, 0xC0A00000, 0x00000000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_80103650_239530_SlotCarDerby);

__asm__(".section .rodata");
const char D_8010FCA0_245B80_SlotCarDerby[] = "c100_1-atama";

__asm__(".section .rodata");
const char D_8010FCB0_245B90_SlotCarDerby[] = "c005_000-bmerge1";

__asm__(".section .rodata");
const char D_8010FCC4_245BA4_SlotCarDerby[] = "Luigi1-atama_1";

__asm__(".section .rodata");
const char D_8010FCD4_245BB4_SlotCarDerby[] = "c003_000-head_1";

__asm__(".section .rodata");
const char D_8010FCE4_245BC4_SlotCarDerby[] = "C002_000b-bmerge10_1";

__asm__(".section .rodata");
const char D_8010FCFC_245BDC_SlotCarDerby[] = "c001_000-atama_2";

__asm__(".section .rodata");
const char D_8010FD10_245BF0_SlotCarDerby[] = "atama_2";

void func_80103874_239754_SlotCarDerby(s16 model, f32 speed) {
    HmfModel* m = &D_800FC834_FD434[model];

    m->unk44 = speed;
}

void func_8010389C_23977C_SlotCarDerby(omObjData* obj) {
    func_8010390C_2397EC_SlotCarDerby(obj, 0);
}

void func_801038B8_239798_SlotCarDerby(omObjData* obj) {
    func_8010390C_2397EC_SlotCarDerby(obj, 1);
}

void func_801038D4_2397B4_SlotCarDerby(omObjData* obj) {
    func_8010390C_2397EC_SlotCarDerby(obj, 2);
}

void func_801038F0_2397D0_SlotCarDerby(omObjData* obj) {
    func_8010390C_2397EC_SlotCarDerby(obj, 3);
}

__asm__(".section .rodata");
const char D_8010FD18_245BF8_SlotCarDerby[] = "head";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_8010390C_2397EC_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_80103D00_239BE0_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_80103FE8_239EC8_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_801048BC_23A79C_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_80104E54_23AD34_SlotCarDerby);

__asm__(".section .rodata");
const u32 D_8010FE18_245CF8_SlotCarDerby[4] = { 0x3D787D9C, 0x3D9B4E82, 0x3DCF1358, 0x3E1B4E82 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_80104F3C_23AE1C_SlotCarDerby);

__asm__(".section .rodata");
const u32 D_8010FED0_245DB0_SlotCarDerby[10] = { 0x41A00000, 0x00000000, 0x00000000, 0xC1A00000, 0x00000000, 0x00000000, 0x00000000, 0x41A00000, 0x00000000, 0x00000000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_801056FC_23B5DC_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_801059F0_23B8D0_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_80105DB4_23BC94_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_80105E60_23BD40_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_80105F5C_23BE3C_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_801062B8_23C198_SlotCarDerby);

f32 func_8010640C_23C2EC_SlotCarDerby(f32 t, f32 a, f32 b, f32 c) {
    f32 u = 1.0 - t;

    return u * u * a + 2.0 * (u * t * b) + t * t * c;
}

void func_8010646C_23C34C_SlotCarDerby(f32 t, Vec* a, Vec* b, Vec* c, Vec* out) {
    f32* pa = (f32*)a;
    f32* pb = (f32*)b;
    f32* pc = (f32*)c;
    f32* po = (f32*)out;
    s32 i;

    for (i = 0; i < 3; i++) {
        *po++ = func_8010640C_23C2EC_SlotCarDerby(t, *pa++, *pb++, *pc++);
    }
}

f32 func_80106508_23C3E8_SlotCarDerby(f32 t, f32 a, f32 b, f32 c) {
    return 2.0 * ((t - 1.0) * a + (1.0 - 2.0 * t) * b + t * c);
}

void func_80106560_23C440_SlotCarDerby(f32 t, Vec* a, Vec* b, Vec* c, Vec* out) {
    f32 d[3];
    f32* pa = (f32*)a;
    f32* pb = (f32*)b;
    f32* pc = (f32*)c;
    f32* po = (f32*)out;
    f32 len;
    s32 i;

    for (i = 0; i < 3; i++) {
        d[i] = func_80106508_23C3E8_SlotCarDerby(t, *pa++, *pb++, *pc++);
    }
    len = sqrtf(d[0] * d[0] + d[1] * d[1] + d[2] * d[2]);
    if (len != 0.0f) {
        for (i = 0; i < 3; i++) {
            *po++ = (f32)(1.0 / len) * d[i];
        }
        return;
    }
    *po++ = 0.0f;
    *po++ = 0.0f;
    *po = 1.0f;
}

f32 func_801066D0_23C5B0_SlotCarDerby(f32 x, f32 y) {
    f32 a = func_800B75A8_B81A8(y, x);

    if (a < 0.0) {
        a += 360.0;
    } else if (a >= 360.0) {
        a -= 360.0;
    }
    return a;
}

void func_80106750_23C630_SlotCarDerby(Vec* dir, f32* angles) {
    f32 h = sqrtf(dir->x * dir->x + dir->z * dir->z);

    *angles++ = func_801066D0_23C5B0_SlotCarDerby(h, -dir->y);
    *angles++ = func_801066D0_23C5B0_SlotCarDerby(dir->z, dir->x);
    *angles = 0.0f;
}

void func_801067D8_23C6B8_SlotCarDerby(Matrix4f m, f32 x, f32 y, f32 z, f32* o) {
    *o++ = x * m[0][0] + y * m[1][0] + z * m[2][0] + m[3][0];
    *o++ = x * m[0][1] + y * m[1][1] + z * m[2][1] + m[3][1];
    *o = x * m[0][2] + y * m[1][2] + z * m[2][2] + m[3][2];
}

void func_80106874_23C754_SlotCarDerby(Matrix4f m, Vec* angles) {
    f32 s;
    f32 c;
    f64 t;

    angles->x = func_801066D0_23C5B0_SlotCarDerby(m[2][2], m[1][2]);
    angles->z = func_801066D0_23C5B0_SlotCarDerby(m[0][0], m[0][1]);
    s = -m[0][2];
    t = 1.0 - s * s;
    if (t < 0.0) {
        t = -t;
    }
    c = sqrtf(t);
    if (angles->x > 90.0 && angles->x < 270.0 && angles->z > 90.0 && angles->z < 270.0) {
        angles->x = func_800B0D98_B1998(angles->x + 180.0, 360.0);
        angles->z = func_800B0D98_B1998(angles->z + 180.0, 360.0);
        c = -c;
    }
    angles->y = func_801066D0_23C5B0_SlotCarDerby(c, s);
}

__asm__(".section .rodata");
const u32 D_8010FFD8_245EB8_SlotCarDerby[4] = { 0x8010F870, 0x8010F888, 0x8010F8A0, 0x00000000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_80106A00_23C8E0_SlotCarDerby);

void func_80106B74_23CA54_SlotCarDerby(f32* pos, f32 weight) {
    if (D_80110808_2466E8_SlotCarDerby < 16) {
        D_80110810_2466F0_SlotCarDerby[D_80110808_2466E8_SlotCarDerby].pos.x = *pos++;
        D_80110810_2466F0_SlotCarDerby[D_80110808_2466E8_SlotCarDerby].pos.y = *pos++;
        D_80110810_2466F0_SlotCarDerby[D_80110808_2466E8_SlotCarDerby].pos.z = *pos;
        D_80110810_2466F0_SlotCarDerby[D_80110808_2466E8_SlotCarDerby].weight = weight;
        D_80110808_2466E8_SlotCarDerby++;
    }
}

void func_80106BE0_23CAC0_SlotCarDerby(s32 x, s32 y, s32 z, s32 weight) {
    Vec v;

    v.x = x * 0.01;
    v.y = y * 0.01;
    v.z = z * 0.01;
    func_80106B74_23CA54_SlotCarDerby(&v.x, weight * 0.01);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_80106C68_23CB48_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_80107708_23D5E8_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_80107864_23D744_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_80107AD4_23D9B4_SlotCarDerby);

__asm__(".section .rodata");
const u32 D_801100B8_245F98_SlotCarDerby[6] = { 0x00000006, 0x00000007, 0x00000008, 0x00000009, 0x0000000A, 0x0000000B };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_80107C40_23DB20_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_80107E0C_23DCEC_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_80107E74_23DD54_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_80107F48_23DE28_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_80108D48_23EC28_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_80108D6C_23EC4C_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_80108F14_23EDF4_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_80108FF0_23EED0_SlotCarDerby);
