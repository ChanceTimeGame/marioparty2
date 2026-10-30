#include "ovl_0E.h"

/* .data (0x143DD0-0x143E50, 80109A40-80109AC0) */

u8 D_80109A40_143DD0_BowlOver = 0;
s8 D_80109A41_143DD1_BowlOver = 2;
s8 D_80109A42_143DD2_BowlOver = 2;
s8 D_80109A43_143DD3_BowlOver = 0;
s8 D_80109A44_143DD4_BowlOver[12] = { 0 };
s16 D_80109A50_143DE0_BowlOver = 0;
/* unreferenced */
s16 D_80109A52_143DE2_BowlOver = 0;
Vec3f D_80109A54_143DE4_BowlOver[6] = {
    { 0.0f, 0.0f, -4750.0f },
    { -100.0f, 0.0f, -4950.0f },
    { 100.0f, 0.0f, -4950.0f },
    { -200.0f, 0.0f, -5150.0f },
    { 0.0f, 0.0f, -5150.0f },
    { 200.0f, 0.0f, -5150.0f },
};
/* unreferenced */
f32 D_80109A9C_143E2C_BowlOver[2] = { -300.0f, 0.0f };
f32 D_80109AA4_143E34_BowlOver[6] = { -5200.0f, 300.0f, 0.0f, -5200.0f, 0.0f, 0.0f };
f32 D_80109ABC_143E4C_BowlOver = -4700.0f;

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

/* A falling pin knocks down the standing pins its top (130 up the tilted pin) passes within 75 of. */
// register allocation only (masked 0): the pin table entry and its object swap a0/a1
#ifdef NON_MATCHING
void func_801079EC_141D7C_BowlOver(omObjData* obj) {
    omObjData* other;
    BOPin* pin;
    BOPin* hit;
    Vec3f v;
    Vec3f top;
    Vec3f d;
    f32 dir;
    f32 a;
    f32 t;
    s16 i;
    s16 snd;

    pin = &D_80109E50_1441E0_BowlOver[obj->work[3]];
    if (pin->unk_17 != 1) {
        return;
    }
    a = pin->unk_00;
    dir = 360.0f - pin->unk_04;
    t = a * 0.017453289f;
    v.x = 0.0f;
    v.y = __cosf(t) * 130.0f;
    v.z = __sinf(t) * 130.0f;
    t = dir * 0.017453289f;
    top.x = __sinf(t) * v.z;
    top.y = v.y;
    top.z = __cosf(t) * v.z;
    top.x += obj->trans.x;
    top.y += obj->trans.y;
    top.z += obj->trans.z;
    for (i = 0; i < 6; i++) {
        if (obj->work[3] == i) {
            continue;
        }
        other = D_8010A0B8_144448_BowlOver[i];
        hit = &D_80109E50_1441E0_BowlOver[other->work[3]];
        if (hit->unk_17 == 1) {
            continue;
        }
        d.x = other->trans.x - top.x;
        d.y = D_8010A0B8_144448_BowlOver[i]->trans.y - top.y;
        d.z = D_8010A0B8_144448_BowlOver[i]->trans.z - top.z;
        if (sqrtf(d.x * d.x + d.y * d.y + d.z * d.z) < 75.0f) {
            hit->unk_04 = pin->unk_04;
            hit->unk_00 = 40.0f;
            D_8010A0B8_144448_BowlOver[i]->trans.y += 30.0;
            func_80029EDC_2AADC(D_8010A0B8_144448_BowlOver[i]->model[1], 0);
            hit->unk_17 = 1;
            hit->unk_18 = 0;
            hit->unk_08 = 90.0f;
            pin->unk_08 = 90.0f;
            snd = 0x182;
            if (D_80109A50_143DE0_BowlOver != 0) {
                snd = 0x183;
                if (D_80109A50_143DE0_BowlOver != 1) {
                    snd = 0x184;
                }
            }
            PlaySound(snd);
            D_80109A50_143DE0_BowlOver++;
            if (D_8010A0B8_144448_BowlOver[0] == obj) {
                omVibrate(D_8010A0AE_14443E_BowlOver[1], 2, 2, 20);
            }
            if (D_8010A0B8_144448_BowlOver[1] == obj) {
                omVibrate(D_8010A0AE_14443E_BowlOver[2], 2, 2, 20);
            }
            if (D_8010A0B8_144448_BowlOver[2] == obj) {
                omVibrate(D_8010A0AE_14443E_BowlOver[3], 2, 2, 20);
            }
            func_80029C74_2A874(obj->model[5], 0.0f);
            func_80029714_2A314(obj->model[5], obj->trans.x, obj->trans.y, obj->trans.z);
            func_800297E8_2A3E8(obj->model[5], 5.0f, 5.0f, 5.0f);
            func_80029C74_2A874(obj->model[6], 0.0f);
            func_80029714_2A314(obj->model[6], obj->trans.x, obj->trans.y, obj->trans.z);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/141320", func_801079EC_141D7C_BowlOver);
#endif

/* A pin: the shell knocks it down when it passes within 88; a falling pin tilts to 90 degrees about
   its fall direction, knocks down the pins its top reaches, then blinks for 31 frames and vanishes. */
// float register allocation and load order (masked 20): the sqrt and angle temporaries and the
// shrink factor's registers differ (MP1's twin is NON_MATCHING too)
#ifdef NON_MATCHING
void func_80107DB4_142144_BowlOver(omObjData* obj) {
    BOPin* pin;
    HmfModel* mdl;
    Vec3f pos;
    Vec3f axis;
    f32 dx;
    f32 dz;
    f32 a;
    f32 b;
    f32 s;
    f32 dist;
    s16 snd;

    pin = &D_80109E50_1441E0_BowlOver[obj->work[3]];
    if (D_800F8FD0_F9BD0 != 1) {
        return;
    }
    mdl = &D_800FC834_FD434[obj->model[0]];
    if (pin->unk_17 == 0) {
        if (obj->trans.y <= 43.0f) {
            dx = D_8010A0A8_144438_BowlOver->trans.x - obj->trans.x;
            dz = D_8010A0A8_144438_BowlOver->trans.z - obj->trans.z;
            dist = sqrtf(dx * dx + dz * dz);
            if (dist < 88.0f) {
                pin->unk_04 = func_800B75A8_B81A8(dx, dz);
                pin->unk_00 = 30.0f;
                obj->trans.y += 30.0;
                func_80029EDC_2AADC(obj->model[1], 0);
                pin->unk_17 = 1;
                pin->unk_18 = 0;
                pin->unk_08 = 90.0f;
                if (D_80109A50_143DE0_BowlOver != 0) {
                    snd = 0x183;
                    if (D_80109A50_143DE0_BowlOver != 1) {
                        snd = 0x184;
                    }
                } else {
                    snd = 0x182;
                }
                PlaySound(snd);
                D_80109A50_143DE0_BowlOver++;
                if (D_8010A0B8_144448_BowlOver[0] == obj) {
                    omVibrate(D_8010A0AE_14443E_BowlOver[1], 2, 2, 20);
                }
                if (D_8010A0B8_144448_BowlOver[1] == obj) {
                    omVibrate(D_8010A0AE_14443E_BowlOver[2], 2, 2, 20);
                }
                if (D_8010A0B8_144448_BowlOver[2] == obj) {
                    omVibrate(D_8010A0AE_14443E_BowlOver[3], 2, 2, 20);
                }
            }
        }
    } else {
        b = pin->unk_04;
        a = b + obj->rot.y;
        a = 360.0f - (f32)(a - (s32)(a / 360.0f) * 360.0);
        pos.x = 0.0f;
        pos.y = 30.0f;
        pos.z = 0.0f;
        a *= 0.017453289f;
        axis.x = __cosf(a);
        axis.y = 0.0f;
        axis.z = -__sinf(a);
        if (pin->unk_00 < pin->unk_08) {
            func_8002979C_2A39C(obj->model[1], 0.0f, -b, 0.0f);
            s = 1.0000000149011612 / (pin->unk_00 / 45.0f + 1.0f);
            func_800297E8_2A3E8(obj->model[1], 1.0f, 1.0f, s);
            func_80029714_2A314(obj->model[1], obj->trans.x, 3.0f, obj->trans.z);
            pin->unk_00 += 8.0f;
        } else {
            pin->unk_00 = D_80109E50_1441E0_BowlOver[obj->work[3]].unk_08;
            s = 1.0000000149011612 / (pin->unk_00 / 45.0f + 1.0f);
            func_800297E8_2A3E8(obj->model[1], 1.0f, 1.0f, s);
            func_80029714_2A314(obj->model[1], obj->trans.x, 3.0f, obj->trans.z);
            if (pin->unk_18 != 1) {
                if (pin->unk_16++ >= 31) {
                    pin->unk_18 = 1;
                    func_80029EDC_2AADC(obj->model[0], 0);
                    func_80029EDC_2AADC(obj->model[1], 0);
                } else if (pin->unk_16 & 1) {
                    func_80029EDC_2AADC(obj->model[0], 0);
                    func_80029EDC_2AADC(obj->model[1], 0);
                } else {
                    func_80029EDC_2AADC(obj->model[0], 3);
                    func_80029EDC_2AADC(obj->model[1], 3);
                }
            }
        }
        func_80106C94_141024_BowlOver(&pos, &axis, pin->unk_00, (f32(*)[4])mdl->mtx);
        if (pin->unk_18 != 1 && pin->unk_16 == 0) {
            func_801079EC_141D7C_BowlOver(obj);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/141320", func_80107DB4_142144_BowlOver);
#endif

/* CPU pin player: picks a stick direction after landing. Usually keeps the last one while the shell is
   far (a square range by difficulty); otherwise a mode (re-rolled when it has not moved 30) steers
   away from the shell, by the alley's centre, at random or straight away; 1 in 4 jumps next. */
void func_801082B8_142648_BowlOver(omObjData* obj, BOJump* jump, u8* sx, u8* sy) {
    BOPlayerWork* w;
    f32 dx;
    f32 dz;
    f32 dist;
    f32 d;
    u32 r;
    s32 range;

    w = BO_WORK(obj);
    range = 0;
    if (jump->unk_18 != 1) {
        return;
    }
    dx = D_8010A0A8_144438_BowlOver->trans.x - obj->trans.x;
    dz = D_8010A0A8_144438_BowlOver->trans.z - obj->trans.z;
    dist = dx * dx + dz * dz;
    r = guRandom() & 3;
    switch (gPlayers[w->unk_59].cpu_difficulty) {
        case 1:
            range = 0x1324;
            break;
        case 0:
            range = 0x1900;
            break;
        case 2:
            range = 0xE10;
            break;
        case 3:
            range = 0x9C4;
            break;
    }
    if (r == 0 || dist <= range) {
        if (obj->trans.x < jump->unk_0C + 30.0f && jump->unk_0C - 30.0f < obj->trans.x &&
            obj->trans.z < jump->unk_10 + 30.0f && jump->unk_10 - 30.0f < obj->trans.z) {
            jump->unk_35 = guRandom() & 3;
        }
        r = guRandom();
        switch (jump->unk_35) {
            case 0:
                if (D_8010A0A8_144438_BowlOver->trans.z < obj->trans.z) {
                    *sy = (u8)jump->unk_34 - (r & 7);
                } else {
                    *sy = (u8)jump->unk_34 + ((r >> 3) & 7);
                }
                if (D_8010A0A8_144438_BowlOver->trans.x + 1000.0f < obj->trans.x + 1000.0f) {
                    *sx = (u8)jump->unk_33 - ((r >> 6) & 7);
                } else {
                    *sx = (u8)jump->unk_33 + ((r >> 9) & 7);
                }
                break;
            case 1:
                if (D_8010A0A8_144438_BowlOver->trans.z < obj->trans.z) {
                    *sy = (u8)jump->unk_34 - (r & 7);
                } else {
                    *sy = (u8)jump->unk_34 + ((r >> 3) & 7);
                }
                if (D_8010A0A8_144438_BowlOver->trans.x > 0.0f) {
                    *sx = (u8)jump->unk_33 - ((r >> 6) & 7);
                } else {
                    *sx = (u8)jump->unk_33 + ((r >> 9) & 7);
                }
                break;
            case 2:
                if (D_8010A0A8_144438_BowlOver->trans.z < obj->trans.z) {
                    *sy = -((r & 0x1F) + 0x14);
                } else {
                    *sy = ((r >> 5) & 0x1F) + 0x14;
                }
                if (D_8010A0A8_144438_BowlOver->trans.x + 1000.0f < obj->trans.x + 1000.0f) {
                    *sx = -(((r >> 10) & 0x1F) + 0x14);
                } else {
                    *sx = ((r >> 15) & 0x1F) + 0x14;
                }
                break;
            case 3:
                dx = obj->trans.x - D_8010A0A8_144438_BowlOver->trans.x;
                dz = -(obj->trans.z - D_8010A0A8_144438_BowlOver->trans.z);
                d = sqrtf(dx * dx + dz * dz);
                if (d != 0.0f) {
                    *sx = (s32)((dx / d) * 50.0f);
                    *sy = (s32)((dz / d) * -50.0f);
                } else {
                    *sx = r & 0x3F;
                    *sy = -((r >> 6) & 0x3F);
                }
                break;
        }
        jump->unk_0C = obj->trans.x;
        jump->unk_10 = obj->trans.z;
        jump->unk_33 = *sx;
        jump->unk_34 = *sy;
        if (!((r >> 20) & 3)) {
            jump->unk_31 = 1;
        }
    } else {
        *sx = (u8)jump->unk_33;
        *sy = (u8)jump->unk_34;
    }
}

/* A pin player: A (or the CPU) jumps and spins; on the ground the stick (averaged over 8 frames)
   turns and walks it; then its pin. */
// one instruction short (masked 23): GCC compares jump->unk_18 with a constant 1 where retail keeps
// the loaded value in a0 for the two later tests (as MP1's twin)
#ifdef NON_MATCHING
void func_801087A0_142B30_BowlOver(omObjData* obj) {
    BOPlayerWork* w;
    BOPin* pin;
    BOJump* jump;
    HmfModel* m;
    u8 sx;
    u8 sy;
    s32 keep;
    s16 slot;
    s16 i;
    f32 ax;
    f32 ay;

    w = BO_WORK(obj);
    pin = &D_80109E50_1441E0_BowlOver[obj->work[3]];
    if (pin->unk_17 == 0) {
        func_801064C8_140858_BowlOver(obj);
    }
    jump = &D_80109F48_1442D8_BowlOver[obj->work[3]];
    if (jump->unk_14 == 0) {
        if (D_800F8FD0_F9BD0 > 0 && D_80109960_143CF0_BowlOver != 1 && pin->unk_17 != 1) {
            if (!(gPlayers[w->unk_59].flags & 1)) {
                if (ContBtnTrg[w->unk_57] & 0x8000) {
                    jump->unk_00 = 40.0f;
                    jump->unk_14 = 1;
                    jump->unk_18 = 0;
                    jump->unk_16 = 0;
                    jump->unk_04 = 2.5f;
                    jump->unk_1C = -1;
                    func_80079798_7A398(0x185, w->unk_59);
                }
            } else if (jump->unk_31 == 1) {
                jump->unk_00 = 40.0f;
                jump->unk_14 = 1;
                jump->unk_18 = 0;
                jump->unk_16 = 0;
                jump->unk_04 = 2.5f;
                jump->unk_1C = -1;
                jump->unk_31 = 0;
                func_80079798_7A398(0x185, w->unk_59);
            }
        }
    } else if (jump->unk_18 == 1) {
        if (jump->unk_16 > 20) {
            jump->unk_1A = 0;
            jump->unk_14 = 0;
            obj->rot.x = 0.0f;
        } else {
            jump->unk_1A = 1;
            if (jump->unk_1C < 0) {
                if (obj->rot.x > 8.0f) {
                    jump->unk_04 = -4.1f;
                    jump->unk_1C = ~jump->unk_1C;
                }
            } else if (obj->rot.x < -8.0f) {
                jump->unk_04 = 4.1f;
                jump->unk_1C = ~jump->unk_1C;
            }
            obj->rot.x = obj->rot.x + jump->unk_04 / ((f32)jump->unk_16 / 5.0f + 1.0);
        }
        jump->unk_16++;
    }
    obj->trans.y += jump->unk_00;
    jump->unk_00 -= 9.8f;
    if (obj->trans.y < 0.0f) {
        jump->unk_18 = 1;
        jump->unk_00 = 0.0f;
        obj->trans.y = 0.0f;
    }
    if (jump->unk_1A == 0) {
        slot = jump->unk_20;
        sy = 0;
        sx = 0;
        keep = 1;
        if (D_800F8FD0_F9BD0 > 0 && jump->unk_18 == 1 && D_80109960_143CF0_BowlOver != jump->unk_18 &&
            pin->unk_17 != jump->unk_18) {
            if (!(gPlayers[w->unk_59].flags & 1)) {
                jump->unk_33 = sx = ContStkX[w->unk_57];
                jump->unk_34 = sy = ContStkY[w->unk_57];
            } else {
                func_801082B8_142648_BowlOver(obj, jump, &sx, &sy);
            }
            keep = 0;
        }
        if (keep == 1) {
            sx = jump->unk_33;
            sy = jump->unk_34;
        }
        if ((s8)sx > 60) {
            sx = 60;
        }
        if ((s8)sy > 60) {
            sy = 60;
        }
        if ((s8)sx < -60) {
            sx = -60;
        }
        if ((s8)sy < -60) {
            sy = -60;
        }
        jump->unk_21[slot] = sx;
        jump->unk_29[slot] = sy;
        ax = 0.0f;
        ay = 0.0f;
        for (i = 0; i < 8; i++) {
            ax += jump->unk_21[i];
            ay += jump->unk_29[i];
        }
        ax /= 8.0f;
        ay /= 8.0f;
        jump->unk_20 = (jump->unk_20 + 1) & 7;
        if (ax * ax + ay * ay > 100.0f) {
            obj->rot.y = jump->unk_08 = func_800B75A8_B81A8(ax, -ay);
        }
        if (jump->unk_14 == 1) {
            func_8010782C_141BBC_BowlOver(obj, ax / 40.0f, -ay / 40.0f);
        }
    }
    if (pin->unk_17 == 1) {
        obj->rot.y = jump->unk_08 = 180.0f;
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
    func_80107DB4_142144_BowlOver(obj);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/141320", func_801087A0_142B30_BowlOver);
#endif

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
