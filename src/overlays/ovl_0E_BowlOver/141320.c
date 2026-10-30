#include "ovl_0E.h"

/* Fades out the shell icon of each shell thrown. */
void func_80106F90_141320_BowlOver(omObjData* obj) {
    s8 i;

    if (D_80109A42_143DD2_BowlOver > D_80109A41_143DD1_BowlOver) {
        func_8001AA08_1B608(D_8010A098_144428_BowlOver[D_80109A43_143DD3_BowlOver], 0, 0xFF, -16);
        D_80109A44_143DD4_BowlOver[D_80109A43_143DD3_BowlOver] = 1;
        D_80109E30_1441C0_BowlOver[D_80109A43_143DD3_BowlOver] = 0xFF;
        D_80109A43_143DD3_BowlOver++;
    }
    D_80109A42_143DD2_BowlOver = D_80109A41_143DD1_BowlOver;
    for (i = 0; i < 2; i++) {
        if (D_80109A44_143DD4_BowlOver[i] == 1) {
            if ((s16)(D_80109E30_1441C0_BowlOver[i] -= 16) < 0) {
                D_80109A44_143DD4_BowlOver[i] = 0;
                espDispOff(D_8010A098_144428_BowlOver[i]);
            }
        }
    }
}

/* The alley's model, collision and backdrop files per alley. */
const s32 D_80109BD0_143F60_BowlOver[3] = { 0x1E0003, 0x1E0004, 0x1E0005 };
const s32 D_80109BDC_143F6C_BowlOver[3] = { 0x1E0000, 0x1E0002, 0x1E0000 };
const s32 D_80109BE8_143F78_BowlOver[3] = { 0x1E0006, 0x1E0007, 0x1E0008 };
/* Three unreferenced zero words before the next literal (retail's 0x80109C00). */
const s32 D_80109BF4_143F84_BowlOver[3] = { 0, 0, 0 };

/* The alley: its models, and the two shell icons. */
void func_801070DC_14146C_BowlOver(omObjData* obj) {
    BOGround* w;
    s8 i;

    obj->unk_50 = w = func_80027154_27D54(sizeof(BOGround), 0x7918);
    func_800B0EF0_B1AF0(w, 0, sizeof(BOGround));
    w->unk_03 = 1;
    w->unk_04 = 0;
    obj->model[0] = func_80018A30_19630(D_80109BD0_143F60_BowlOver[D_80109A40_143DD0_BowlOver], 0x20699);
    obj->model[1] = LoadFormFile(D_80109BDC_143F6C_BowlOver[D_80109A40_143DD0_BowlOver], 0x20699);
    func_80029EDC_2AADC(obj->model[1], 2);
    obj->model[2] = LoadFormFile(D_80109BE8_143F78_BowlOver[D_80109A40_143DD0_BowlOver], 0x699);
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
    for (i = 0; i < 2; i++) {
        D_8010A098_144428_BowlOver[i] = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x1E001A), 0, 1);
        func_8001A91C_1B51C(D_8010A098_144428_BowlOver[i], 1.0f, 1.0f);
        func_8001A788_1B388(D_8010A098_144428_BowlOver[i], 8);
        espPosSet(D_8010A098_144428_BowlOver[i], 270 - (1 - i) * 24, 48);
    }
    obj->func_ptr = func_80106F90_141320_BowlOver;
}

/* The pin deck's collision box. */
void func_801072F0_141680_BowlOver(omObjData* obj) {
    BOGround* w;

    obj->unk_50 = w = func_80027154_27D54(sizeof(BOGround), 0x7918);
    func_800B0EF0_B1AF0(w, 0, sizeof(BOGround));
    w->unk_03 = 1;
    w->unk_04 = 1;
    obj->model[0] = -1;
    func_8000BF24_CB24(obj, 0.0f, -250.0f, -5000.0f, 250.0f, 500.0f);
    obj->func_ptr = NULL;
}

void func_80107390_141720_BowlOver(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 6; i++) {
        D_80109E50_1441E0_BowlOver[i].unk_17 = 0;
        D_80109E50_1441E0_BowlOver[i].unk_18 = 0;
        D_80109E50_1441E0_BowlOver[i].unk_16 = 0;
        D_80109E50_1441E0_BowlOver[i].unk_0C = 0.0f;
        D_80109E50_1441E0_BowlOver[i].unk_10 = 30.0f;
        D_80109E50_1441E0_BowlOver[i].unk_14 = 0;
        D_80109E50_1441E0_BowlOver[i].unk_00 = 30.0f;
        D_80109E50_1441E0_BowlOver[i].unk_04 = 0.0f;
        D_80109E50_1441E0_BowlOver[i].unk_08 = 90.0f;
    }
    for (i = 0; i < 6; i++) {
        D_80109F48_1442D8_BowlOver[i].unk_00 = 0.0f;
        D_80109F48_1442D8_BowlOver[i].unk_08 = 0.0f;
        D_80109F48_1442D8_BowlOver[i].unk_14 = 0;
        D_80109F48_1442D8_BowlOver[i].unk_16 = 0;
        D_80109F48_1442D8_BowlOver[i].unk_18 = 0;
        D_80109F48_1442D8_BowlOver[i].unk_1A = 0;
        D_80109F48_1442D8_BowlOver[i].unk_20 = 0;
        D_80109F48_1442D8_BowlOver[i].unk_04 = 0.0f;
        D_80109F48_1442D8_BowlOver[i].unk_1C = -1;
        D_80109F48_1442D8_BowlOver[i].unk_04 = 0.0f;
        for (j = 0; j < 8; j++) {
            D_80109F48_1442D8_BowlOver[i].unk_21[j] = 0;
            D_80109F48_1442D8_BowlOver[i].unk_29[j] = 0;
        }
        D_80109F48_1442D8_BowlOver[i].unk_31 = 0;
        D_80109F48_1442D8_BowlOver[i].unk_35 = 0;
        D_80109F48_1442D8_BowlOver[i].unk_0C = 0.0f;
        D_80109F48_1442D8_BowlOver[i].unk_10 = 0.0f;
        D_80109F48_1442D8_BowlOver[i].unk_33 = 0;
        D_80109F48_1442D8_BowlOver[i].unk_34 = -50;
    }
}

/* As func_80107390_141720_BowlOver, keeping the pins' knocked-down state. */
void func_80107570_141900_BowlOver(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 6; i++) {
        D_80109E50_1441E0_BowlOver[i].unk_16 = 0;
        D_80109E50_1441E0_BowlOver[i].unk_0C = 0.0f;
        D_80109E50_1441E0_BowlOver[i].unk_10 = 30.0f;
        D_80109E50_1441E0_BowlOver[i].unk_14 = 0;
        D_80109E50_1441E0_BowlOver[i].unk_00 = 30.0f;
        D_80109E50_1441E0_BowlOver[i].unk_04 = 0.0f;
        D_80109E50_1441E0_BowlOver[i].unk_08 = 90.0f;
    }
    for (i = 0; i < 6; i++) {
        D_80109F48_1442D8_BowlOver[i].unk_00 = 0.0f;
        D_80109F48_1442D8_BowlOver[i].unk_08 = 0.0f;
        D_80109F48_1442D8_BowlOver[i].unk_14 = 0;
        D_80109F48_1442D8_BowlOver[i].unk_16 = 0;
        D_80109F48_1442D8_BowlOver[i].unk_18 = 0;
        D_80109F48_1442D8_BowlOver[i].unk_1A = 0;
        D_80109F48_1442D8_BowlOver[i].unk_20 = 0;
        D_80109F48_1442D8_BowlOver[i].unk_04 = 0.0f;
        D_80109F48_1442D8_BowlOver[i].unk_1C = -1;
        D_80109F48_1442D8_BowlOver[i].unk_04 = 0.0f;
        for (j = 0; j < 8; j++) {
            D_80109F48_1442D8_BowlOver[i].unk_21[j] = 0;
            D_80109F48_1442D8_BowlOver[i].unk_29[j] = 0;
        }
        D_80109F48_1442D8_BowlOver[i].unk_31 = 0;
        D_80109F48_1442D8_BowlOver[i].unk_35 = 0;
        D_80109F48_1442D8_BowlOver[i].unk_0C = 0.0f;
        D_80109F48_1442D8_BowlOver[i].unk_10 = 0.0f;
        D_80109F48_1442D8_BowlOver[i].unk_33 = 0;
        D_80109F48_1442D8_BowlOver[i].unk_34 = -50;
    }
}

/* Keeps a pin player's step (dx, dz) on the pin deck: between its back and front, and inside the
   deck's trapezoid (half as wide as the distance from the front). */
// float register allocation (x and vz swap f6/f8) and the lim subtraction scheduled after the x test (as MP1)
#ifdef NON_MATCHING
void func_80107738_141AC8_BowlOver(omObjData* obj, f32* dx, f32* dz) {
    f32 vx;
    f32 vz;
    f32 x;
    f32 z;
    f32 lim;

    vx = *dx;
    vz = *dz;
    x = vx + obj->trans.x;
    z = vz + obj->trans.z;
    if (z < D_80109AA4_143E34_BowlOver[0]) {
        vz = 0.0f;
        obj->trans.z = D_80109AA4_143E34_BowlOver[0];
    } else if (D_80109ABC_143E4C_BowlOver - 50.0f < z) {
        vz = 0.0f;
        obj->trans.z = D_80109ABC_143E4C_BowlOver - 50.0f;
    }
    lim = (vz + obj->trans.z) - D_80109ABC_143E4C_BowlOver;
    if (!(x < 0.0f)) {
        lim = -lim / 2.0f;
        if (lim <= x) {
            vx = 0.0f;
            obj->trans.x = lim;
        }
    } else {
        lim = lim / 2.0f;
        if (x <= lim) {
            vx = 0.0f;
            obj->trans.x = lim;
        }
    }
    *dx = vx;
    *dz = vz;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/141320", func_80107738_141AC8_BowlOver);
#endif

/* Moves a pin player by (dx, dz), pushed out of the other standing pin players (radius 90). */
// GCC keeps 0.0f in a saved register across the loop; retail rematerialises it (as MP1)
#ifdef NON_MATCHING
void func_8010782C_141BBC_BowlOver(omObjData* obj, f32 dx, f32 dz) {
    omObjData* other;
    f32 ex;
    f32 ez;
    f32 d;
    f32 push;
    s16 i;

    func_80107738_141AC8_BowlOver(obj, &dx, &dz);
    for (i = 0; i < 6; i++) {
        other = D_8010A0B8_144448_BowlOver[i];
        if (obj == other) {
            continue;
        }
        if (D_80109E50_1441E0_BowlOver[other->work[3]].unk_17 != 1) {
            ex = (obj->trans.x + dx) - other->trans.x;
            ez = (obj->trans.z + dz) - other->trans.z;
            d = sqrtf(ex * ex + ez * ez);
            if (d < 90.0f) {
                if (d == 0.0f) {
                    dx = 0.0f;
                    dz = 0.0f;
                } else {
                    push = 90.0f - d;
                    obj->trans.x = (dx - (dx - (ex / d) * push)) + obj->trans.x;
                    obj->trans.z = (dz - (dz - (ez / d) * push)) + obj->trans.z;
                }
                continue;
            }
        }
        obj->trans.x += dx;
        obj->trans.z += dz;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/141320", func_8010782C_141BBC_BowlOver);
#endif

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/141320", func_801079EC_141D7C_BowlOver);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/141320", func_80107DB4_142144_BowlOver);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/141320", func_801082B8_142648_BowlOver);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/141320", func_801087A0_142B30_BowlOver);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/141320", func_80108DCC_14315C_BowlOver);

__asm__(".section .rodata");
const u32 D_80109C30_143FC0_BowlOver[1] = { 0x00000002 };

__asm__(".section .rodata");
const u32 D_80109C34_143FC4_BowlOver[1] = { 0x0000000B };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/141320", func_80108ECC_14325C_BowlOver);

__asm__(".section .rodata");
const u32 D_80109DE0_144170_BowlOver[8] = { 0x001E0012, 0x001E0013, 0x001E0015, 0x001E0016, 0x001E0017, 0x001E0014, 0x00000000, 0x00000000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/141320", func_80109148_1434D8_BowlOver);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/141320", func_80109354_1436E4_BowlOver);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/141320", func_8010947C_14380C_BowlOver);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/141320", func_801096A0_143A30_BowlOver);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/141320", func_8010977C_143B0C_BowlOver);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/141320", func_801097F4_143B84_BowlOver);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/141320", func_80109870_143C00_BowlOver);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/141320", func_801098EC_143C7C_BowlOver);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/141320", func_80109910_143CA0_BowlOver);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/141320", func_80109934_143CC4_BowlOver);
