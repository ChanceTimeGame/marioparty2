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

/* A pin player back on its slot. */
void func_80108DCC_14315C_BowlOver(omObjData* obj) {
    BOPin* pin;
    u16* slot;

    pin = &D_80109E50_1441E0_BowlOver[obj->work[3]];
    slot = BO_WORK(obj)->unk_158;
    obj->trans.x = D_80109A54_143DE4_BowlOver[*slot].x;
    obj->trans.y = D_80109A54_143DE4_BowlOver[*slot].y;
    obj->trans.z = D_80109A54_143DE4_BowlOver[*slot].z;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    obj->rot.x = 0.0f;
    obj->rot.y = 0.0f;
    obj->rot.z = 0.0f;
    func_801064C8_140858_BowlOver(obj);
    if (pin->unk_17 == 1) {
        obj->func_ptr = NULL;
        func_800298A4_2A4A4(obj->model[3], 4, 4);
    }
}

const BOHead D_80109C30_143FC0_BowlOver[6] = {
    { 2, 11, "atama_2", "114_Bowring0-kaodamy_4" },
    { 3, 12, "c001_000-atama_2", "114_Bowring1-kaodamy_2" },
    { 4, 14, "c003_000-head_1", "114_Bowring1-kaodamy_5" },
    { 5, 15, "Luigi1-atama_1", "114_Bowring1-kaodamy_1" },
    { 6, 16, "c005_000-bmerge1", "114_Bowring1-kaodamy_3" },
    { 7, 13, "C002_000b-bmerge10_1", "114_Bowring1-kaodamy" },
};

/* The pin player's pin body per character. */
const s32 D_80109DE0_144170_BowlOver[6] = { 0x1E0012, 0x1E0013, 0x1E0015, 0x1E0016, 0x1E0017, 0x1E0014 };

/* A pin player: work, slot, models (the character with the bowling-pin head on). */
void func_80108ECC_14325C_BowlOver(omObjData* obj, s32 dir, s32 file, u16 player, u16 slot, u16 pin) {
    BOPlayerWork* w;
    u16* s;
    s16 i;
    u32 chr;

    obj->unk_50 = func_80027154_27D54(sizeof(BOPlayerWork), 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, sizeof(BOPlayerWork));
    w = obj->unk_50;
    w->unk_E8 = func_80027154_27D54(obj->mtncnt * 12, 0x7918);
    w->unk_158 = s = func_80027154_27D54(sizeof(u16), 0x7918);
    func_800B0EF0_B1AF0(s, 0, sizeof(u16));
    *s = slot;
    w->unk_57 = gPlayers[player].port;
    w->unk_59 = player;
    chr = (u32)dir >> 16;
    for (i = 0; i < 6; i++) {
        if ((u32)D_80109C30_143FC0_BowlOver[i].unk_00 == chr) {
            break;
        }
    }
    obj->model[0] = LoadFormFile(D_80109C30_143FC0_BowlOver[i].unk_04 | 0x1E0000, 0x206B9);
    obj->model[1] = func_80018A64_19664(0x1E0001, 0x6B9);
    obj->model[2] = LoadFormFile(dir | file, 0xA99);
    func_80023DAC_249AC(obj->model[2], (char*)D_80109C30_143FC0_BowlOver[i].unk_08, obj->model[0],
                        (char*)D_80109C30_143FC0_BowlOver[i].unk_28);
    obj->model[3] = LoadFormFile(D_80109DE0_144170_BowlOver[i], 0xA99);
    func_8002D1EC_2DDEC(obj->model[0], 1);
    func_8002D274_2DE74(obj->model[0], 0xFF, 0xA4, 0x1B);
    func_8002D2B4_2DEB4(obj->model[0], 42.0f, 90.0f, 51.0f);
    func_80029EDC_2AADC(obj->model[2], 0);
    func_80029EDC_2AADC(obj->model[0], 1);
    func_80029EDC_2AADC(obj->model[3], 2);
    obj->work[3] = pin;
    func_80108DCC_14315C_BowlOver(obj);
    obj->func_ptr = func_801087A0_142B30_BowlOver;
}

/* An empty pin slot's pin: it falls like the others; once down its ring bounces and fades. */
void func_80109148_1434D8_BowlOver(omObjData* obj) {
    BOPin* pin;
    HmfModel* m;
    f32 s;

    pin = &D_80109E50_1441E0_BowlOver[obj->work[3]];
    func_80107DB4_142144_BowlOver(obj);
    if (pin->unk_17 == 1) {
        func_800298A4_2A4A4(obj->model[7], 4, 0);
        func_800298A4_2A4A4(obj->model[8], 4, 0);
        if ((pin->unk_0C += pin->unk_10) < 0.0f) {
            pin->unk_10 = -(pin->unk_0C * 0.8f);
            pin->unk_0C = 0.0f;
        } else {
            pin->unk_10 -= 2.0f;
        }
        func_80029714_2A314(obj->model[7], obj->trans.x, pin->unk_0C + 10.0f, obj->trans.z);
        func_80029714_2A314(obj->model[8], obj->trans.x, 0.0f, obj->trans.z);
        s = pin->unk_0C / 200.0f;
        func_800297E8_2A3E8(obj->model[8], 1.0f - s, 1.0f - s, 0.5f - s);
    }
    if (pin->unk_17 == 0) {
        func_801064C8_140858_BowlOver(obj);
    }
    m = &D_800FC834_FD434[obj->model[0]];
    if (m->hmf != NULL) {
        if (m->unk18 & 4) {
            func_800298A4_2A4A4(obj->model[3], 4, 4);
        } else {
            func_800298A4_2A4A4(obj->model[3], 4, 0);
        }
    }
    func_80029714_2A314(obj->model[3], obj->trans.x, obj->trans.y, obj->trans.z);
    func_8002979C_2A39C(obj->model[3], obj->rot.x, obj->rot.y, obj->rot.z);
}

/* An empty pin slot's pin back on its slot. */
void func_80109354_1436E4_BowlOver(omObjData* obj) {
    BOPin* pin;
    u16* slot;

    pin = &D_80109E50_1441E0_BowlOver[obj->work[3]];
    slot = ((BOGround*)obj->unk_50)->unk_B0;
    obj->trans.x = D_80109A54_143DE4_BowlOver[*slot].x;
    obj->trans.y = D_80109A54_143DE4_BowlOver[*slot].y;
    obj->trans.z = D_80109A54_143DE4_BowlOver[*slot].z;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    obj->rot.x = 0.0f;
    obj->rot.y = 0.0f;
    obj->rot.z = 0.0f;
    func_800298A4_2A4A4(obj->model[7], 4, 4);
    func_800298A4_2A4A4(obj->model[8], 4, 4);
    func_801064C8_140858_BowlOver(obj);
    if (pin->unk_17 == 1) {
        obj->func_ptr = NULL;
        func_800298A4_2A4A4(obj->model[3], 4, 4);
    }
}

/* An empty pin slot: a plain pin, with a ring and a shadow. */
void func_8010947C_14380C_BowlOver(omObjData* obj, u16 slot, s8 pin) {
    BOGround* w;
    u16* s;

    obj->model[0] = LoadFormFile(0x1E0011, 0x206B9);
    obj->model[1] = func_80018A64_19664(0x1E0001, 0x6B9);
    obj->model[2] = -1;
    obj->model[3] = LoadFormFile(0x1E0018, 0xA99);
    func_80029EDC_2AADC(obj->model[0], 1);
    func_80029EDC_2AADC(obj->model[3], 2);
    obj->model[7] = D_800F86D8_F92D8[func_80018D64_19964(0xE, 0x289, 8)].unk00;
    HmfModelObjAttrSet(obj->model[7], 0x70000000, 0x70000000);
    func_800297E8_2A3E8(obj->model[7], 2.0f, 2.0f, 2.0f);
    func_800298A4_2A4A4(obj->model[7], 4, 4);
    obj->model[8] = func_80027D3C_2893C(obj->model[1]);
    func_800297E8_2A3E8(obj->model[8], 1.0f, 1.0f, 0.5f);
    func_800298A4_2A4A4(obj->model[8], 4, 4);
    func_8002D1EC_2DDEC(obj->model[0], 1);
    func_8002D274_2DE74(obj->model[0], 0xFF, 0xA4, 0x1B);
    func_8002D2B4_2DEB4(obj->model[0], 42.0f, 90.0f, 51.0f);
    obj->unk_50 = w = func_80027154_27D54(sizeof(BOGround), 0x7918);
    func_800B0EF0_B1AF0(w, 0, sizeof(BOGround));
    w->unk_03 = 1;
    w->unk_B0 = s = func_80027154_27D54(sizeof(u16), 0x7918);
    func_800B0EF0_B1AF0(s, 0, sizeof(u16));
    *s = slot;
    obj->work[3] = pin;
    func_80109354_1436E4_BowlOver(obj);
    obj->func_ptr = func_80109148_1434D8_BowlOver;
}

/* Shuffles the pin slots. */
void func_801096A0_143A30_BowlOver(void) {
    s16 i;
    u32 r;
    u32 a;
    u32 b;
    u16 t;

    for (i = 0; i < 6; i++) {
        D_80109E40_1441D0_BowlOver[i] = i;
    }
    for (i = 0; i < 10; i++) {
        r = guRandom();
        a = r & 7;
        if (a >= 6) {
            a = (r >> 3) & 3;
        }
        b = (r >> 5) & 7;
        if (b >= 6) {
            b = (r >> 8) & 3;
        }
        t = D_80109E40_1441D0_BowlOver[a];
        D_80109E40_1441D0_BowlOver[a] = D_80109E40_1441D0_BowlOver[b];
        D_80109E40_1441D0_BowlOver[b] = t;
    }
}

/* Pin player 1. */
void func_8010977C_143B0C_BowlOver(omObjData* obj) {
    s8 p;
    u8 chr;
    s32 dir;
    s32 file;

    p = D_8010A0AE_14443E_BowlOver[1];
    chr = gPlayers[p].character;
    dir = D_800CD438_CE038[chr].unk_04;
    file = D_800CD438_CE038[chr].unk_08;
    func_80108ECC_14325C_BowlOver(obj, dir, file, p, D_80109E40_1441D0_BowlOver[0], 0);
}

/* Pin player 2. */
void func_801097F4_143B84_BowlOver(omObjData* obj) {
    s8 p;
    u8 chr;
    s32 dir;
    s32 file;

    p = D_8010A0AE_14443E_BowlOver[2];
    chr = gPlayers[p].character;
    dir = D_800CD438_CE038[chr].unk_04;
    file = D_800CD438_CE038[chr].unk_08;
    func_80108ECC_14325C_BowlOver(obj, dir, file, p, D_80109E40_1441D0_BowlOver[1], 1);
}

/* Pin player 3. */
void func_80109870_143C00_BowlOver(omObjData* obj) {
    s8 p;
    u8 chr;
    s32 dir;
    s32 file;

    p = D_8010A0AE_14443E_BowlOver[3];
    chr = gPlayers[p].character;
    dir = D_800CD438_CE038[chr].unk_04;
    file = D_800CD438_CE038[chr].unk_08;
    func_80108ECC_14325C_BowlOver(obj, dir, file, p, D_80109E40_1441D0_BowlOver[2], 2);
}

void func_801098EC_143C7C_BowlOver(omObjData* obj) {
    func_8010947C_14380C_BowlOver(obj, D_80109E40_1441D0_BowlOver[3], 3);
}

void func_80109910_143CA0_BowlOver(omObjData* obj) {
    func_8010947C_14380C_BowlOver(obj, D_80109E40_1441D0_BowlOver[4], 4);
}

void func_80109934_143CC4_BowlOver(omObjData* obj) {
    func_8010947C_14380C_BowlOver(obj, D_80109E40_1441D0_BowlOver[5], 5);
}

/* retail pads the file's .rodata to 16 */
__asm__(".section .rodata\n\t.balign 16\n\t.text");
