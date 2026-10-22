#include "ovl_30.h"

__asm__(".section .rodata");
const char D_8010FC50_245B30_SlotCarDerby[32] = "\202r\202s\202`\202q\202s\202f\202n\202`\202k\202v\202h\202m\201I";

void func_80102800_2386E0_SlotCarDerby(void) {
    omObjData* obj;
    u8 cam;

    D_801102DA_2461BA_SlotCarDerby = 0;
    D_801102D6_2461B6_SlotCarDerby = 0;
    D_801102D8_2461B8_SlotCarDerby = 0;
    D_801102DC_2461BC_SlotCarDerby = 0;
    D_801102DE_2461BE_SlotCarDerby = 0;
    D_801102E0_2461C0_SlotCarDerby = 0;
    func_8002D4D0_2E0D0(50);
    func_80020D20_21920(32);
    omInitObjMan(32, 0);
    func_80079128_79D28();
    D_801109D8_2468B8_SlotCarDerby = 0;
    D_801109D4_2468B4_SlotCarDerby = 0;
    D_801109D6_2468B6_SlotCarDerby = 0;
    if (_CheckFlag(0xC) != 0) {
        D_801109D6_2468B6_SlotCarDerby = 1;
    }
    obj = omAddObj(0x7FDA, 0, 0, -1, func_80079E60_7AA60);
    ((void (*)(omObjData*))func_80079E60_7AA60)(obj); /* declared (void) in functions.h */
    omSetStatBit(obj, 0xA0);
    func_80018E30_19A30(1);
    cam = func_80018E78_19A78();
    ScissorSet(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 45.0f, 80.0f, 4000.0f);
    D_800FA606_FB206 = 0;
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    D_8011023C_24611C_SlotCarDerby = D_800FA656;
    if (D_8011023C_24611C_SlotCarDerby < 0) {
        D_8011023C_24611C_SlotCarDerby = 0;
    } else if (D_8011023C_24611C_SlotCarDerby >= 3) {
        D_8011023C_24611C_SlotCarDerby = 2;
    }
    func_80026DAC_279AC(0, 0x88, 0x88, 0x88);
    func_80026DAC_279AC(1, 0xFF, 0xFF, 0xFF);
    func_80026E00_27A00(1, 0.0f, 2000.0f, 2000.0f);
    D_800F8FE0_F9BE0 = 0;
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(0, 0, 0, -1, func_80102BC0_238AA0_SlotCarDerby);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(1, 3, 0, -1, func_80107C40_23DB20_SlotCarDerby);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(4, 3, 2, -1, func_8010389C_23977C_SlotCarDerby);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(5, 3, 2, -1, func_801038B8_239798_SlotCarDerby);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(6, 3, 2, -1, func_801038D4_2397B4_SlotCarDerby);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(7, 3, 2, -1, func_801038F0_2397D0_SlotCarDerby);
    func_80109240_23F120_SlotCarDerby(D_8011023C_24611C_SlotCarDerby);
    func_8007273C_7333C((u8*)D_8010FC50_245B30_SlotCarDerby, 1);
}

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

/* NON_MATCHING: retail reloads both track pointers once after the .x store (6 instructions); logic as retail */
#ifdef NON_MATCHING
void func_80102C98_238B78_SlotCarDerby(void) {
    f32 dx;
    f32 dy;
    f32 dz;
    f32 total;
    s32 i;
    s32 j;
    Vec* mid;
    Vec* a;

    D_80110240_246120_SlotCarDerby = D_8010F41C_2452FC_SlotCarDerby[D_8011023C_24611C_SlotCarDerby];
    D_80110244_246124_SlotCarDerby = D_8010F428_245308_SlotCarDerby[D_8011023C_24611C_SlotCarDerby];
    D_80110248_246128_SlotCarDerby = func_80027154_27D54(D_80110244_246124_SlotCarDerby * sizeof(f32), 0x7918);
    D_8011024C_24612C_SlotCarDerby = func_80027154_27D54((D_80110244_246124_SlotCarDerby + 1) * sizeof(f32), 0x7918);
    D_80110254_246134_SlotCarDerby = func_80027154_27D54(D_80110244_246124_SlotCarDerby * sizeof(Vec), 0x7918);
    total = 0.0f;
    for (i = 0; i < D_80110244_246124_SlotCarDerby; i++) {
        j = (i + 1) % D_80110244_246124_SlotCarDerby;
        dx = D_80110240_246120_SlotCarDerby[j].x - D_80110240_246120_SlotCarDerby[i].x;
        dy = D_80110240_246120_SlotCarDerby[j].y - D_80110240_246120_SlotCarDerby[i].y;
        dz = D_80110240_246120_SlotCarDerby[j].z - D_80110240_246120_SlotCarDerby[i].z;
        D_80110248_246128_SlotCarDerby[i] = sqrtf(dx * dx + dy * dy + dz * dz);
        D_8011024C_24612C_SlotCarDerby[i] = total;
        total += D_80110248_246128_SlotCarDerby[i];
        D_80110254_246134_SlotCarDerby[i].x = D_80110240_246120_SlotCarDerby[i].x + dx * 0.5;
        mid = &D_80110254_246134_SlotCarDerby[i];
        a = &D_80110240_246120_SlotCarDerby[i];
        mid->y = a->y + dy * 0.5;
        mid->z = a->z + dz * 0.5;
    }
    D_8011024C_24612C_SlotCarDerby[i] = total;
    D_80110250_246130_SlotCarDerby = total;
    for (i = 0; i < 16; i++) {
        D_80110258_246138_SlotCarDerby[i] = 0;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_80102C98_238B78_SlotCarDerby);
#endif

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

void func_801030D4_238FB4_SlotCarDerby(SCDCar* car, s16 sound) {
    if (car->unk_74 >= 0) {
        func_80079848_7A448(car->unk_74);
    }
    car->unk_74 = -1;
    if (sound >= 0 && car->unk_76 == 0) {
        if (func_80079798_7A398(sound, car->unk_01) != -1) {
            car->unk_76 = 30;
        }
    }
}

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

s32 func_801032F8_2391D8_SlotCarDerby(void) {
    s8 hit[4];
    s16 lane[4];
    f32 dist[4];
    SCDCar* car;
    SCDCar* other;
    s16 n;
    s32 left;
    s32 i;
    s32 j;
    s32 k;
    f32 range;
    f32 d;

    n = 0;
    car = D_801102E8_2461C8_SlotCarDerby;
    for (i = 0; i < 4; i++, car++) {
        if ((car->unk_00 & 1) && (car->unk_02 == 1 || car->unk_02 == 2)) {
            hit[n] = 0;
            lane[n] = i;
            d = car->unk_48 + car->unk_4C;
            dist[n] = func_800B0D98_B1998(d, D_80110250_246130_SlotCarDerby);
            n++;
        }
    }
    if (n < 2) {
        return n;
    }
    range = (D_801102C8_2461A8_SlotCarDerby.unk_00 == 2) ? 15.0f : 30.0f;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            d = dist[j] - dist[i];
            if (d < 0.0) {
                d += D_80110250_246130_SlotCarDerby;
            }
            if (d > 40.0) {
                continue;
            }
            car = &D_801102E8_2461C8_SlotCarDerby[lane[i]];
            other = &D_801102E8_2461C8_SlotCarDerby[lane[j]];
            d = 0.0f;
            for (k = 0; k < 3; k++) {
                d += ((&car->unk_0C.x)[k] - (&other->unk_0C.x)[k]) * ((&car->unk_0C.x)[k] - (&other->unk_0C.x)[k]);
            }
            if (range < sqrtf(d)) {
                continue;
            }
            hit[j] = -1;
            if (hit[i] == 0) {
                hit[i] = 1;
            }
        }
    }
    left = n;
    for (i = 0; i < n; i++) {
        if (hit[i] != 0) {
            car = &D_801102E8_2461C8_SlotCarDerby[lane[i]];
            if (hit[i] > 0) {
                if (D_801102C8_2461A8_SlotCarDerby.unk_00 == 2) {
                    func_80103650_239530_SlotCarDerby(2, car);
                }
            } else if (D_801102C8_2461A8_SlotCarDerby.unk_00 != 2) {
                car->unk_50 = 13.65f;
            } else {
                car->unk_02 = 3;
                car->unk_64 = car->unk_66 = 0;
                left--;
            }
        }
    }
    return left;
}

void func_80103650_239530_SlotCarDerby(s16 kind, SCDCar* car) {
    f32 ahead[3] = { -8.0f, -10.0f, 10.0f };
    f32 rise[3] = { -0.0f, -5.0f, 0.0f };
    Vec pos;
    Vec dir;
    Vec angles;
    Matrix4f m;

    func_80105F5C_23BE3C_SlotCarDerby(car->unk_48, car->unk_4C, ahead[kind], &pos, &dir);
    dir.x = -dir.x;
    dir.y = -dir.y;
    dir.z = -dir.z;
    func_80106750_23C630_SlotCarDerby(&dir, &angles.x);
    if (kind < 2) {
        if (kind == 0) {
            func_80105F5C_23BE3C_SlotCarDerby(car->unk_48, car->unk_4C, car->unk_50, &pos, &dir);
            func_800B1F50_B2B50(m, pos.x, pos.y, pos.z);
        } else {
            func_800B1F50_B2B50(m, car->unk_0C.x, car->unk_0C.y, car->unk_0C.z);
        }
        func_80025884_26484(m, car->unk_24.x, car->unk_24.y, car->unk_24.z);
        func_801067D8_23C6B8_SlotCarDerby(m, 0.0f, 0.0f, ahead[kind], &pos.x);
    }
    pos.y += rise[kind];
    if (kind < 2) {
        func_8010AD94_240C74_SlotCarDerby(kind, &pos, &angles);
        if (kind == 1 && D_801102C8_2461A8_SlotCarDerby.unk_00 == 2) {
            func_80079798_7A398(0x2AF, car->unk_01);
        }
    } else {
        func_80108FF0_23EED0_SlotCarDerby(pos.x * 10.0, pos.y * 10.0, pos.z * 10.0);
    }
}

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

/* NON_MATCHING: registers only (the file id lands in v0, retail a0); masked 0 */
#ifdef NON_MATCHING
void func_8010390C_2397EC_SlotCarDerby(omObjData* obj, s16 player) {
    SCDPlayerWork* work;
    HmfMotionObj* head;
    u32 chr;
    s32 file;

    obj->func_ptr = func_80103D00_239BE0_SlotCarDerby;
    obj->work[0] = player;
    obj->unk_50 = func_80027154_27D54(sizeof(SCDPlayerWork), 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, sizeof(SCDPlayerWork));
    work = obj->unk_50;
    work->unk_E8 = func_80027154_27D54(obj->mtncnt * 12, 0x7918);
    func_800B0EF0_B1AF0(work->unk_E8, 0, obj->mtncnt * 12);
    chr = gPlayers[player].character;
    if ((D_801109D6_2468B6_SlotCarDerby == 2) & (player == 3)) {
        chr = 6;
    }
    if (chr < 6) {
        file = D_800CD438_CE038[chr].unk_04 | D_800CD438_CE038[chr].unk_0C;
    } else {
        chr = 6;
        file = 0x80000;
    }
    obj->model[1] = LoadFormFile(file, 0x6BD);
    obj->model[0] = LoadFormFile(D_8010F498_245378_SlotCarDerby[chr] | 0x400000, 0x6B9);
    obj->model[2] = LoadFormFile(0xC, 0x68D);
    func_800297E8_2A3E8(obj->model[2], 0.5f, 0.5f, 0.5f);
    func_80039018_39C18(D_800FC834_FD434[obj->model[1]].unk02);
    head = func_8002A9F4_2B5F4(obj->model[0], (char*)D_8010FD18_245BF8_SlotCarDerby);
    D_801104E8_2463C8_SlotCarDerby[obj->work[0]] = head;
    func_80023DAC_249AC(obj->model[1], D_8010F47C_24535C_SlotCarDerby[chr], obj->model[0], (char*)D_8010FD18_245BF8_SlotCarDerby);
    head->unk28.y += D_8010F4C4_2453A4_SlotCarDerby[chr][0];
    head->unk28.z += D_8010F4C4_2453A4_SlotCarDerby[chr][1];
    head->unk40.x = D_8010F4A8_245388_SlotCarDerby[chr];
    head->unk40.y = D_8010F4A8_245388_SlotCarDerby[chr];
    head->unk40.z = D_8010F4A8_245388_SlotCarDerby[chr];
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.4f;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    work->unk_D0 = 0xFFFF;
    func_80019E84_1AA84(obj, 0, 0x400014, 1, 0);
    D_800FC834_FD434[obj->model[0]].unk02 = 0;
    work->unk_57 = gPlayers[player].port;
    func_801032A0_239180_SlotCarDerby(obj);
    func_801032E0_2391C0_SlotCarDerby(obj)->unk_0A = chr;
    D_80110298_246178_SlotCarDerby[obj->work[1]] = 0;
    D_801102B8_246198_SlotCarDerby[obj->work[1]] = -30.0f;
    D_801102A8_246188_SlotCarDerby[obj->work[1]] = ((3 - obj->work[1]) * 10 + 100) * 40.0 + 6.0;
    func_8010D6DC_2435BC_SlotCarDerby(chr, obj->work[0]);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_8010390C_2397EC_SlotCarDerby);
#endif

void func_80103D00_239BE0_SlotCarDerby(omObjData* obj) {
    SCDCar* car;
    s32 throttle;

    if (D_801102DA_2461BA_SlotCarDerby == 0) {
        car = func_801032E0_2391C0_SlotCarDerby(obj);
        throttle = 0;
        if (D_801102C8_2461A8_SlotCarDerby.unk_00 == 2) {
            throttle = func_80103FE8_239EC8_SlotCarDerby(obj);
        }
        func_801048BC_23A79C_SlotCarDerby(obj, throttle);
        if (D_801102C8_2461A8_SlotCarDerby.unk_00 == 0) {
            switch (D_80110298_246178_SlotCarDerby[obj->work[1]]) {
            case 0:
                D_801102A8_246188_SlotCarDerby[obj->work[1]] -= 40.0;
                if (D_801102A8_246188_SlotCarDerby[obj->work[1]] <= 6.0) {
                    D_801102A8_246188_SlotCarDerby[obj->work[1]] = 6;
                    D_80110298_246178_SlotCarDerby[obj->work[1]]++;
                }
                break;
            case 1:
                D_801102B8_246198_SlotCarDerby[obj->work[1]] += 5.0f;
                D_801102A8_246188_SlotCarDerby[obj->work[1]] -= 1.0f;
                if (D_801102B8_246198_SlotCarDerby[obj->work[1]] >= 0.0) {
                    D_801102B8_246198_SlotCarDerby[obj->work[1]] = 0.0f;
                    D_801102A8_246188_SlotCarDerby[obj->work[1]] = 0;
                    D_80110298_246178_SlotCarDerby[obj->work[1]]++;
                }
                break;
            case 2:
                func_800191D4_19DD4(obj, 2, obj->trans.x - 20.0, obj->trans.y - 30.0, obj->trans.z, 0, 0);
                D_800FC834_FD434[obj->model[2]].unk44 *= 2.0;
                PlaySound(0x2B2);
                D_80110298_246178_SlotCarDerby[obj->work[1]]++;
                break;
            }
            obj->rot.x += D_801102B8_246198_SlotCarDerby[obj->work[1]];
            obj->trans.y += D_801102A8_246188_SlotCarDerby[obj->work[1]];
        }
        if (car->unk_76 != 0) {
            car->unk_76--;
        }
        func_80019378_19F78(obj);
        func_80019178_19D78(obj);
    }
}

/* Scheduling: retail computes lvl * 6 before the random term of unk_72 and the step's random
   term before lvl (masked 13); MP1 func_800F7A7C had the same residue. */
#ifdef NON_MATCHING
s32 func_80103FE8_239EC8_SlotCarDerby(omObjData* obj) {
    SCDCar* car;
    s32 throttle;
    u8 diff;
    s32 go;
    u8 lvl;
    u8 lvl2;
    s32 step;
    s32 k;
    s32 i;
    s32 lo;
    s32 hi;
    s32 t;
    s8 port;
    s8 x;
    s8 y;
    s32 pad[4]; /* unused: retail's frame is 16 bytes larger */

    car = func_801032E0_2391C0_SlotCarDerby(obj);
    car->unk_03 = 0;
    diff = gPlayers[obj->work[0]].cpu_difficulty & 3;
    lvl2 = diff + 1;
    lvl = 5 - diff;
    port = SCD_WORK(obj)->unk_57;
    if (!(gPlayers[obj->work[0]].flags & 1)) {
        x = ContStkX[port];
        y = ContStkY[port];
        i = func_800B1830_B2430(x * x + y * y) / 64.0f * 5.0f;
        if (i > 5) {
            i = 5;
        }
        throttle = D_8010F450_245330_SlotCarDerby[i];
        if (throttle != 0) {
            throttle += D_8010F46C_24534C_SlotCarDerby[car->unk_05];
        }
        if (throttle > 100) {
            throttle = 100;
        }
        car->unk_03 = 1;
        if (throttle < 10 || throttle > 90) {
            rand8();
            rand8();
        }
    } else if (D_801109D6_2468B6_SlotCarDerby == 0) {
        step = 1600 - lvl * 200;
        if (D_801102C8_2461A8_SlotCarDerby.unk_00 == 2) {
            throttle = car->unk_6C;
            go = 0;
            if (car->unk_6E == 0) {
                go = (s32)((u32)(((rand8() << 8) | rand8()) * 25) >> 14) < lvl * 8;
                car->unk_6A = (((rand8() << 8) | rand8()) * (lvl2 * 25 + 10)) >> 16;
            } else if (car->unk_06 == 0 && (car->unk_6E & 7) == 1) {
                go = 1;
            }
            if (go) {
                k = 10000 - (func_80105E60_23BD40_SlotCarDerby(car->unk_48 + car->unk_4C + 40.0) +
                             D_8010F46C_24534C_SlotCarDerby[car->unk_05]) * 100;
                if (k < 0) {
                    k = 0;
                }
                go = lvl + 1;
                if (go > 4) {
                    go = 4;
                }
                throttle = 9900 - ((((rand8() << 8) | rand8()) * 75) >> 14);
                throttle -= k * go / 4;
                throttle -= car->unk_6A;
            }
            if (car->unk_06 == 0) {
                t = ((rand8() << 8) | rand8()) * 6;
                car->unk_72 = lvl * 6 + ((t * lvl) >> 16) + car->unk_6A * 0.03;
            } else {
                if (car->unk_06 > lvl2 * 6 - car->unk_72) {
                    throttle = 0;
                    car->unk_6E = 0;
                }
                step = 4500 / (car->unk_72 + 1) - ((((rand8() << 8) | rand8()) * 100 * lvl) >> 16) - car->unk_6A * 0.5;
            }
            car->unk_6C = throttle;
        }
        if (car->unk_6C > car->unk_70) {
            car->unk_70 += step;
            hi = car->unk_70;
            t = car->unk_6C;
            lo = t;
        } else {
            car->unk_70 -= step;
            lo = car->unk_70;
            t = car->unk_6C;
            hi = t;
        }
        if (lo < hi) {
            car->unk_70 = t;
        }
        throttle = car->unk_70 * 0.01;
        car->unk_6E++;
    } else {
        if (car->unk_0A == 6) {
            lvl = 1;
            if (D_801109D8_2468B8_SlotCarDerby != 0 && car->unk_68 < car->unk_6A * 4 + 390) {
                lvl = 2;
            }
        } else {
            lvl = 3;
            if (D_801109D8_2468B8_SlotCarDerby != 0 && car->unk_68 > 600 - car->unk_6A * 2) {
                lvl = 5;
            }
        }
        if (D_801102C8_2461A8_SlotCarDerby.unk_00 == 2) {
            throttle = car->unk_6C;
            if (car->unk_06 == 0 && (car->unk_6E & 7) == 1) {
                throttle = 9800 - ((((rand8() << 8) | rand8()) * 35) >> 13);
                throttle -= lvl * 200;
                if (diff == 5) {
                    throttle -= car->unk_6A * 5;
                }
            }
            if (car->unk_68 == 0) {
                car->unk_6A = (((rand8() << 8) | rand8()) * (lvl2 * 25 + 10)) >> 16;
                if (D_801109D8_2468B8_SlotCarDerby != 0 && car->unk_0A == 6) {
                    throttle = 10000;
                }
            }
            if (car->unk_06 == 0) {
                car->unk_72 = lvl * 5 + (((((rand8() << 8) | rand8()) << 1) * lvl) >> 16) + car->unk_6A * 0.03;
            } else {
                if (car->unk_06 > lvl2 * 6 - car->unk_72) {
                    throttle = 0;
                    car->unk_6E = 0;
                }
                rand8();
                rand8();
            }
            car->unk_6C = throttle;
        }
        if (car->unk_6C > car->unk_70) {
            car->unk_70 += 1700 - lvl * 200;
            if (car->unk_70 > car->unk_6C) {
                car->unk_70 = car->unk_6C;
            }
        } else {
            car->unk_70 -= 1700 - lvl * 200;
            if (car->unk_70 < car->unk_6C) {
                car->unk_70 = car->unk_6C;
            }
        }
        throttle = car->unk_70 * 0.01;
        car->unk_6E++;
        car->unk_68++;
    }
    if (throttle < 0) {
        throttle = 0;
    } else if (throttle > 100) {
        throttle = 100;
    }
    return throttle;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_80103FE8_239EC8_SlotCarDerby);
#endif

void func_801048BC_23A79C_SlotCarDerby(omObjData* obj, s32 throttle) {
    Matrix4f m;
    Matrix4f rm;
    Vec angles;
    Vec v;
    f32 t;
    f32 a;
    f64 speed;
    SCDCar* car;
    HmfMotionObj* head;

    t = throttle * 0.01;
    car = func_801032E0_2391C0_SlotCarDerby(obj);
    if (car->unk_02 == 4) {
        if (D_801102C8_2461A8_SlotCarDerby.unk_00 == 2) {
            car->unk_02 = 1;
            car->unk_64 = car->unk_66 = 0;
        }
    }
    switch (car->unk_02) {
        case 0:
            func_8010DAD8_2439B8_SlotCarDerby(obj->work[0], -1.0f);
            break;
        case 1:
            func_80104F3C_23AE1C_SlotCarDerby(obj, t);
            break;
        case 2:
            func_801056FC_23B5DC_SlotCarDerby(obj);
            break;
        case 3:
            func_801059F0_23B8D0_SlotCarDerby(obj);
            break;
        case 4:
            func_80105DB4_23BC94_SlotCarDerby(obj);
            break;
    }
    car->unk_64++;
    if (car->unk_00 & 0x10) {
        if ((car->unk_58 -= 24.0) < 0.0) {
            /* unk_06 and unk_07 tested together (lhu): endian-neutral against 0 */
            if (*(u16*)&car->unk_06 != 0) {
                car->unk_58 += 360.0;
            } else {
                car->unk_58 = 0.0f;
            }
        }
        if (car->unk_07 != 0) {
            a = HuMathSin(car->unk_58) * 45.0;
        } else {
            a = car->unk_06;
            if (a > 20.0f) {
                a = 20.0f;
            }
            a = (a + 40.0f) * HuMathSin(car->unk_58);
        }
        func_800B37C0_B43C0(m);
        func_800B37C0_B43C0(rm);
        func_800B1CC0_B28C0(m, a + car->unk_5C, 0.0f, 1.0f, 0.0f);
        m[3][3] = 1.0f;
        func_80106750_23C630_SlotCarDerby(&car->unk_30, &angles.x);
        func_80025884_26484(rm, angles.x, angles.y, angles.z);
        func_800B6410_B7010(m, rm, m);
        func_80106874_23C754_SlotCarDerby(m, &car->unk_24);
        speed = car->unk_50 / 9.1 * 2.5;
        func_80103874_239754_SlotCarDerby(obj->model[0], speed);
        if ((((s16)car->unk_64 + car->unk_01) & 3) == 0 && car->unk_58 != 0.0f) {
            func_80103650_239530_SlotCarDerby(1, car);
        }
        head = D_801104E8_2463C8_SlotCarDerby[obj->work[0]];
        if (car->unk_02 == 2) {
            car->unk_62 = 0;
        }
        if (head != (HmfMotionObj*)-1 && car->unk_62 == 0) {
            head->unk34.x = car->unk_3C;
            head->unk34.z = car->unk_44;
            func_80105F5C_23BE3C_SlotCarDerby(car->unk_48, car->unk_4C, car->unk_50 * 12.0f + 1.0, &v, &angles);
            v.x -= car->unk_0C.x;
            v.y -= car->unk_0C.y;
            v.z -= car->unk_0C.z;
            func_80106750_23C630_SlotCarDerby(&v, &angles.x);
            a = angles.y - car->unk_24.y;
            if (a < 0.0) {
                a += 360.0;
            }
            if (a > 180.0) {
                a -= 360.0;
            }
            head->unk34.y = a * 0.75;
            func_800B1F50_B2B50(head->unk58, head->unk04.x, head->unk04.y, head->unk04.z);
            func_80025884_26484(head->unk58, head->unk34.x, head->unk34.y, head->unk34.z);
            func_80025830_26430(head->unk58, head->unk40.x, head->unk40.y, head->unk40.z);
        }
    }
    if (car->unk_08 != 0) {
        D_800FC834_FD434[obj->model[0]].unk18 ^= 4;
        if (--car->unk_08 == 0) {
            D_800FC834_FD434[obj->model[0]].unk18 |= 4;
            D_800FC834_FD434[obj->model[0]].unk03 |= 1;
            car->unk_02 = 0;
        }
    }
    obj->trans.x = car->unk_0C.x * 10.0;
    obj->trans.y = car->unk_0C.y * 10.0;
    obj->trans.z = car->unk_0C.z * 10.0;
    obj->rot.x = car->unk_24.x;
    obj->rot.y = car->unk_24.y;
    obj->rot.z = car->unk_24.z;
}

void func_80104E54_23AD34_SlotCarDerby(SCDCar* car, f32 ahead) {
    Vec a;
    Vec b;
    Vec c;
    f32 d;

    func_80105F5C_23BE3C_SlotCarDerby(car->unk_48, car->unk_4C, ahead, &a, &b);
    func_80106750_23C630_SlotCarDerby(&car->unk_30, &a.x);
    func_80106750_23C630_SlotCarDerby(&b, &c.x);
    car->unk_40 = a.y;
    d = c.y - a.y;
    if (d < 0.0f) {
        d += 360.0;
    }
    if (d > 180.0) {
        d -= 360.0;
    }
    car->unk_44 = d * 0.3;
}

/* One instruction: retail converts f to double again in the pitch's else arm (bc1fl delay slot)
   where GCC reuses the comparison's conversion. */
#ifdef NON_MATCHING
void func_80104F3C_23AE1C_SlotCarDerby(omObjData* obj, f32 throttle) {
    Vec pos;
    Vec dir;
    f32 accel[4] = { 0.060666665f, 0.075833336f, 0.101111114f, 0.15166667f }; /* 9.1 / 150, 120, 90, 60 */
    SCDCar* car;
    f32 target;
    f32 speed;
    f32 cur;
    f32 prev;
    f32 f;
    f64 d;
    s32 lim;

    car = func_801032E0_2391C0_SlotCarDerby(obj);
    if (car->unk_62 != 0) {
        throttle = 0.1f;
        car->unk_62--;
    }
    if (SCD_CAR_FRAMES0(car)) {
        car->unk_66 = 1;
        if (throttle != 0.0f) {
            car->unk_07 = 1;
            func_80079798_7A398(0x2AC, car->unk_01);
        }
    }
    target = throttle * 9.1;
    cur = car->unk_50;
    if (cur < target) {
        speed = cur + accel[car->unk_05];
        if (target < speed) {
            speed = target;
        }
    } else if (target < cur) {
        if (car->unk_60 != 0) {
            speed = cur - (f32)(20 - car->unk_60) / 10.0 * 0.546;
        } else {
            speed = car->unk_50 - 0.546;
        }
        if (speed < target) {
            speed = target;
        }
    } else {
        speed = car->unk_50;
    }
    car->unk_50 = speed;
    target = speed;
    if (D_801102C8_2461A8_SlotCarDerby.unk_00 == 2) {
        if (car->unk_74 < 0) {
            if (car->unk_76 == 0) {
                car->unk_74 = func_80079798_7A398(0x2AE, car->unk_01);
            }
        }
        if (car->unk_74 >= 0) {
            if (func_801030B0_238F90_SlotCarDerby(car->unk_74) == 0) {
                car->unk_74 = func_80079798_7A398(0x2AE, car->unk_01);
            }
            f = speed / 9.1 - 0.2;
            if (f >= 0.0) {
                d = f / 0.8 * 1000.0;
            } else {
                d = f / 0.2 * 1400.0;
            }
            f = d - 400.0;
            func_800796F0_7A2F0(car->unk_74, f);
        }
    }
    if (car->unk_07 != 0) {
        speed = 0.0f;
        car->unk_50 = speed;
        target = speed;
        if (++car->unk_07 >= 31) {
            car->unk_07 = 0;
        }
    }
    prev = car->unk_4C;
    car->unk_4C = func_80105F5C_23BE3C_SlotCarDerby(car->unk_48, prev, target, &car->unk_0C, &car->unk_30);
    if (car->unk_00 & 0x80) {
        if (D_801109D6_2468B6_SlotCarDerby == 0) {
            D_800FC834_FD434[obj->model[0]].unk18 ^= 4;
        }
    } else {
        if (D_80110250_246130_SlotCarDerby * 0.9 < prev && car->unk_4C < D_80110250_246130_SlotCarDerby * 0.1) {
            car->unk_00 |= 0x80;
            if (car->unk_04 == 0) {
                car->unk_04 = D_80110802_2466E2_SlotCarDerby++;
                if (car->unk_04 == 1) {
                    PlaySound(0x4AD);
                    D_801102DC_2461BC_SlotCarDerby = 1;
                    D_801109D4_2468B4_SlotCarDerby = 1;
                }
            }
            car->unk_06 = 0;
            D_801102D2_2461B2_SlotCarDerby = 60;
            D_801102DE_2461BE_SlotCarDerby += func_801091DC_23F0BC_SlotCarDerby(car->unk_01, 1);
        }
    }
    if (car->unk_62 != 0 && car->unk_50 < 1.82) {
        func_8010DAD8_2439B8_SlotCarDerby(obj->work[0], 0.0f);
    } else {
        func_8010DAD8_2439B8_SlotCarDerby(obj->work[0], car->unk_50 / 9.1);
    }
    lim = func_80105E60_23BD40_SlotCarDerby(car->unk_4C + car->unk_48) + D_8010F46C_24534C_SlotCarDerby[car->unk_05];
    if (lim > 100) {
        lim = 100;
    }
    speed = (f32)lim * 9.1 / 100.0;
    if (speed < target && (((car->unk_00 & 0x80) == 0) & (throttle != 0.0f))) {
        if (car->unk_06 == 0) {
            omVibrate(car->unk_01, 10, 0, 10);
        } else if (!(car->unk_06 & 3)) {
            omVibrate(car->unk_01, 2, 3, 10);
        }
        if (car->unk_06++ >= 26) {
            if (throttle > 0.0f) {
                car->unk_62 = 40;
                car->unk_5C = 0.0f;
            }
            car->unk_06 = 0;
            omVibrate(car->unk_01, 20, 0, 20);
            func_80079798_7A398(0x2AF, car->unk_01);
        }
    } else {
        car->unk_06 = 0;
    }
    if (car->unk_06 >= 8) {
        car->unk_60 = car->unk_06 - 6;
    }
    if (car->unk_60 != 0) {
        if (--car->unk_60 < 0) {
            car->unk_60 = 0;
        }
    }
    car->unk_00 |= 0x10;
    if (car->unk_62 == 0) {
        func_80104E54_23AD34_SlotCarDerby(car, -car->unk_50 * 16.0f);
        car->unk_5C = 0.0f;
    } else {
        car->unk_40 = 0.0f;
        if ((car->unk_5C += 27.0) > 360.0f) {
            car->unk_5C -= 360.0f;
        }
        if (!(car->unk_62 & 3)) {
            func_80103650_239530_SlotCarDerby(1, car);
        }
    }
    if (D_801102C8_2461A8_SlotCarDerby.unk_00 != 7 && D_801102C8_2461A8_SlotCarDerby.unk_00 != 8) {
        func_80106B74_23CA54_SlotCarDerby(&car->unk_0C.x, 0.15f);
    }
    func_80105F5C_23BE3C_SlotCarDerby(car->unk_48, car->unk_4C, 40.0f, &pos, &dir);
    if (D_801102C8_2461A8_SlotCarDerby.unk_00 != 7 && D_801102C8_2461A8_SlotCarDerby.unk_00 != 8) {
        if (car->unk_05 == 0) {
            pos.y -= 10.0;
            func_80106B74_23CA54_SlotCarDerby(&pos.x, 0.3f);
        } else {
            pos.y -= 10.0;
            func_80106B74_23CA54_SlotCarDerby(&pos.x, 0.15f);
        }
    }
    if (!(car->unk_64 & 0xF) && car->unk_50 >= 8.19) {
        func_80103650_239530_SlotCarDerby(0, car);
    }
}
#else
__asm__(".section .rodata");
const u32 D_8010FE18_245CF8_SlotCarDerby[4] = { 0x3D787D9C, 0x3D9B4E82, 0x3DCF1358, 0x3E1B4E82 };
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_80104F3C_23AE1C_SlotCarDerby);
#endif

__asm__(".section .rodata"); /* GCC thinks it is still in .rodata after the INCLUDE_ASM above */
void func_801056FC_23B5DC_SlotCarDerby(omObjData* obj) {
    Vec pos;
    Vec dir;
    Vec ang;
    Vec offs[3] = { { 20.0f, 0.0f, 0.0f }, { -20.0f, 0.0f, 0.0f }, { 0.0f, 20.0f, 0.0f } };
    SCDCar* car;
    s32 i;

    car = func_801032E0_2391C0_SlotCarDerby(obj);
    D_800FC834_FD434[obj->model[0]].unk18 &= ~4;
    car->unk_50 += 0.15166666666666667;
    if (car->unk_50 > 7.28) {
        car->unk_50 = 7.28f;
    }
    func_8010DAD8_2439B8_SlotCarDerby(obj->work[0], car->unk_50 / 9.1);
    if (car->unk_74 >= 0) {
        func_800799A4_7A5A4(car->unk_74, 20);
    }
    car->unk_74 = -1;
    car->unk_4C = func_80105F5C_23BE3C_SlotCarDerby(car->unk_48, car->unk_4C, car->unk_50, &car->unk_0C, &car->unk_30);
    func_80104E54_23AD34_SlotCarDerby(car, -car->unk_50 * 16.0f);
    car->unk_5C = 0.0f;
    if (car->unk_04 == 1) {
        func_80105F5C_23BE3C_SlotCarDerby(car->unk_48, car->unk_4C, car->unk_50 * 10.0f, &pos, &dir);
        func_80106750_23C630_SlotCarDerby(&car->unk_30, &pos.x);
        func_80106750_23C630_SlotCarDerby(&dir, &ang.x);
        car->unk_5C = ang.y - pos.y;
        if (D_801109D6_2468B6_SlotCarDerby == 0) {
            func_80106B74_23CA54_SlotCarDerby(&car->unk_0C.x, 0.5f);
        }
        func_80105F5C_23BE3C_SlotCarDerby(car->unk_48, car->unk_4C, car->unk_03 ? 80.0f : 20.0f, &pos, &dir);
        for (i = 0; i < 3; i++) {
            dir.x = pos.x + offs[i].x;
            dir.y = pos.y + offs[i].y;
            dir.z = pos.z + offs[i].z;
            if (D_801109D6_2468B6_SlotCarDerby == 0) {
                func_80106B74_23CA54_SlotCarDerby(&dir.x, 0.2f);
            }
        }
        if (!(car->unk_64 & 0xF)) {
            func_80103650_239530_SlotCarDerby(0, car);
        }
    }
    car->unk_00 |= 0x10;
}

void func_801059F0_23B8D0_SlotCarDerby(omObjData* obj) {
    Vec rot;
    Vec pos;
    f32 ground;
    SCDCar* car;
    s16 i;
    s16 j;
    s16 r;

    car = func_801032E0_2391C0_SlotCarDerby(obj);
    func_8010DAD8_2439B8_SlotCarDerby(obj->work[0], 0.0f);
    if (SCD_CAR_FRAMES0(car)) {
        func_801091DC_23F0BC_SlotCarDerby(car->unk_01, 0);
        car->unk_04 = 4;
        car->unk_00 |= 0x40;
        if (car->unk_74 >= 0) {
            func_80079848_7A448(car->unk_74);
        }
        func_80079798_7A398(0x2AD, car->unk_01);
        car->unk_74 = car->unk_78 = -1;
        omVibrate(car->unk_01, 30, 0, 30);
        func_800797DC_7A3DC(0x111, obj->work[0]);
        car->unk_18.x = car->unk_30.x * 8.0;
        car->unk_18.y = car->unk_30.y * 8.0 + 8.0;
        car->unk_18.z = car->unk_30.z * 8.0;
    }
    for (j = 0; j < 3; j++) {
        (&car->unk_0C.x)[j] += (&car->unk_18.x)[j];
        (&rot.x)[j] = -(&car->unk_18.x)[j];
    }
    car->unk_18.y -= 1.0;
    if (car->unk_18.y < -20.0) {
        car->unk_18.y = -20.0f;
    }
    if (car->unk_18.y < 0.0f) {
        r = func_801062B8_23C198_SlotCarDerby(&car->unk_0C, &ground);
        if (r != 0) {
            if (r > 0) {
                car->unk_0C.y = ground;
                car->unk_18.y = 8.0f;
                rot.x = 30.0f;
                rot.y = guRandom() % 90;
                rot.z = 0.0f;
                pos.y = car->unk_0C.y;
                for (i = 0; i < 3; i++) {
                    pos.x = car->unk_0C.x + func_800B7890_B8490(rot.y) * 20.0f * 0.5;
                    pos.z = car->unk_0C.z + HuMathSin(rot.y) * 20.0f * 0.5;
                    func_8010AD94_240C74_SlotCarDerby(1, &pos, &rot);
                    rot.y = func_800B0D98_B1998(rot.y + 120.0, 360.0);
                }
            }
        } else if (car->unk_08 == 0) {
            car->unk_08 = 30;
        }
    }
    car->unk_24.y = func_800B0D98_B1998(car->unk_24.y + 30.0, 360.0);
    car->unk_24.z = func_800B0D98_B1998(car->unk_24.z + 15.0, 360.0);
    car->unk_00 &= ~0x10;
    if (D_801102C8_2461A8_SlotCarDerby.unk_00 != 7 && D_801102C8_2461A8_SlotCarDerby.unk_00 != 8 && car->unk_08 == 0) {
        func_80106B74_23CA54_SlotCarDerby(&car->unk_0C.x, 0.2f);
    }
}

void func_80105DB4_23BC94_SlotCarDerby(omObjData* obj) {
    SCDCar* car = func_801032E0_2391C0_SlotCarDerby(obj);

    if (SCD_CAR_FRAMES0(car)) {
        func_80105F5C_23BE3C_SlotCarDerby(car->unk_48, 0.0f, 0.0f, &car->unk_0C, &car->unk_30);
        car->unk_00 |= 0x10;
    }
    car->unk_40 = car->unk_24.y;
    car->unk_3C = car->unk_44 = 0.0f;
    if (car->unk_74 < 0 && car->unk_76 <= 0) {
        car->unk_74 = func_80079798_7A398(0x2AE, car->unk_01);
        func_800796F0_7A2F0(car->unk_74, -1800);
    }
}

s32 func_80105E60_23BD40_SlotCarDerby(f32 dist) {
    u16(*p)[3];
    s32 cls;

    if (dist >= 0.0f) {
        dist = func_800B0D98_B1998(dist, D_80110250_246130_SlotCarDerby);
    } else {
        dist += D_80110250_246130_SlotCarDerby;
    }
    p = D_8010F864_245744_SlotCarDerby[D_8011023C_24611C_SlotCarDerby];
    cls = 6;
    for (; (*p)[0] != 0x400; p++) {
        if (D_8011024C_24612C_SlotCarDerby[(*p)[0]] <= dist && dist < D_8011024C_24612C_SlotCarDerby[(*p)[1]]) {
            cls = (*p)[2];
            break;
        }
    }
    return D_8010F450_245330_SlotCarDerby[cls] + 1;
}

/* NON_MATCHING: one FP register (the quotient lands in f12, retail f0); masked 0 */
#ifdef NON_MATCHING
f32 func_80105F5C_23BE3C_SlotCarDerby(f32 start, f32 dist, f32 step, Vec* pos, Vec* dir) {
    f32 d;
    f32 at;
    f32 sum;
    f32 prev;
    f32 t;
    f32 u;
    Vec* a;
    Vec* b;
    s16 i;
    s16 next;

    d = dist + step;
    if (d >= 0.0f) {
        d = func_800B0D98_B1998(d, D_80110250_246130_SlotCarDerby);
    } else {
        d += D_80110250_246130_SlotCarDerby;
    }
    at = start + d;
    if (at >= 0.0f) {
        at = func_800B0D98_B1998(at, D_80110250_246130_SlotCarDerby);
    } else {
        at += D_80110250_246130_SlotCarDerby;
    }
    sum = 0.0f;
    prev = sum;
    for (i = 0; i < D_80110244_246124_SlotCarDerby; i++) {
        sum += D_80110248_246128_SlotCarDerby[i];
        if (at <= sum) {
            break;
        }
        prev = sum;
    }
    if (i >= D_80110244_246124_SlotCarDerby) {
        i = 0;
        at -= D_80110250_246130_SlotCarDerby;
        prev = 0.0f;
    }
    at -= prev;
    step = at / D_80110248_246128_SlotCarDerby[i];
    t = fabsf(step);
    if (t >= 0.5) {
        t = t - 0.5;
    } else {
        t = t + 0.5;
        i = (i != 0) ? i - 1 : D_80110244_246124_SlotCarDerby - 1;
    }
    if (i < D_80110244_246124_SlotCarDerby - 1) {
        next = i + 1;
    } else {
        next = 0;
    }
    step = t;
    if (step < 0.5) {
        u = step * 2.0;
        a = &D_80110254_246134_SlotCarDerby[i];
        b = &D_80110240_246120_SlotCarDerby[next];
    } else {
        u = t - 0.5;
        u = u * 2.0;
        a = &D_80110240_246120_SlotCarDerby[next];
        b = &D_80110254_246134_SlotCarDerby[next];
    }
    pos->x = u * (b->x - a->x) + a->x;
    pos->y = u * (b->y - a->y) + a->y;
    pos->z = u * (b->z - a->z) + a->z;
    func_80106560_23C440_SlotCarDerby(step, &D_80110254_246134_SlotCarDerby[i], &D_80110240_246120_SlotCarDerby[next], &D_80110254_246134_SlotCarDerby[next], dir);
    return d;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_80105F5C_23BE3C_SlotCarDerby);
#endif

/* NON_MATCHING: retail advances the pos pointer once (addiu a0, 4) before reading y and z; logic as retail */
#ifdef NON_MATCHING
s32 func_801062B8_23C198_SlotCarDerby(Vec* pos, f32* groundY) {
    f32 best;
    Vec* mid;
    f32* len;
    f32* p;
    f32 x, y, z;
    f32 r;
    s32 i;
    s32 hit;

    best = 30000.0f;
    mid = D_80110254_246134_SlotCarDerby;
    len = D_80110248_246128_SlotCarDerby;
    p = (f32*)pos;
    x = *p++;
    y = p[0];
    z = p[1];
    hit = 0;
    for (i = 0; i < D_80110244_246124_SlotCarDerby; i++, mid++) {
        r = *len++ * 0.75;
        if (abs((s32)(mid->x - x)) < r && abs((s32)(mid->z - z)) < r) {
            hit = 1;
            if (y <= mid->y && mid->y < best) {
                best = mid->y;
            }
        }
    }
    if (hit == 0) {
        return 0;
    }
    if (best == 30000.0f) {
        return -1;
    }
    *groundY = best;
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_801062B8_23C198_SlotCarDerby);
#endif

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

void func_80106A00_23C8E0_SlotCarDerby(void) {
    f32* tbl[3] = { D_8010F870_245750_SlotCarDerby, D_8010F888_245768_SlotCarDerby, D_8010F8A0_245780_SlotCarDerby };
    f32* p;
    SCDCamera* cam;
    SCDCamPose* cur;
    f32 d;
    f32 sum;

    D_800C9B80_CA780->fov[0] = 45.0f;
    D_800C9B80_CA780->fov[1] = 80.0f;
    D_800C9B80_CA780->fov[2] = 16000.0f;
    D_800C9B80_CA780->up.x = D_800C9B80_CA780->up.z = 0.0f;
    D_800C9B80_CA780->up.y = 1.0f;
    cam = &D_80110910_2467F0_SlotCarDerby;
    p = tbl[D_8011023C_24611C_SlotCarDerby];
    cam->target.pos[0] = D_80110910_2467F0_SlotCarDerby.cur.pos[0] = *p++;
    D_80110914_2467F4_SlotCarDerby = D_80110910_2467F0_SlotCarDerby.cur.pos[1] = *p++;
    D_80110918_2467F8_SlotCarDerby = D_80110910_2467F0_SlotCarDerby.cur.pos[2] = *p++;
    D_8011091C_2467FC_SlotCarDerby = D_80110910_2467F0_SlotCarDerby.cur.view[0] = *p++;
    D_80110920_246800_SlotCarDerby = D_80110910_2467F0_SlotCarDerby.cur.view[1] = *p++;
    D_80110924_246804_SlotCarDerby = D_80110910_2467F0_SlotCarDerby.cur.view[2] = *p;
    cur = &cam->cur;
    d = cur->view[0] - cur->pos[0];
    sum = d * d;
    d = cur->view[1] - cur->pos[1];
    sum += d * d;
    d = cur->view[2] - cur->pos[2];
    sum += d * d;
    cam->target.zoom = cur->zoom = sqrtf(sum);
    D_80110808_2466E8_SlotCarDerby = 0;
}

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

/* Register allocation: GCC hoists the zoom loop's 1.0 into s2/s3 (two more saved registers and a
   larger frame), retail reloads it each pass; MP1 func_800FA3B4 had the same residue. Otherwise
   scheduling only (masked 80, mostly branch offsets). */
#ifdef NON_MATCHING
void func_80106C68_23CB48_SlotCarDerby(Vec* look) {
    f32 max[3];
    f32 min[3];
    Matrix4f mtx;
    f32 out[3];
    f32 up[3];
    SCDCamera* cam;
    SCDCamPose* cur;
    Vec* pt;
    s32 i;
    s32 j;
    s32 n;
    f64 t;
    f32 best;
    f32 ease;
    f32 lean;
    f32 d;
    f32* p;
    f32* pmax;
    f32* pmin;

    lean = 0.0f;
    cam = &D_80110910_2467F0_SlotCarDerby;
    D_8011091C_2467FC_SlotCarDerby = look->x;
    D_80110920_246800_SlotCarDerby = look->y;
    D_80110924_246804_SlotCarDerby = look->z;
    up[0] = up[2] = lean;
    up[1] = 1.0f;
    cur = &cam->cur;
    if (D_8010FAEC_2459CC_SlotCarDerby != 0) {
        D_8010FAEC_2459CC_SlotCarDerby = 0;
        D_80110238_246118_SlotCarDerby = D_80110234_246114_SlotCarDerby = lean;
        for (i = 0, pt = D_80110240_246120_SlotCarDerby; i < D_80110244_246124_SlotCarDerby; i++, pt++) {
            if (pt->z > D_80110234_246114_SlotCarDerby) {
                D_80110234_246114_SlotCarDerby = pt->z;
            }
            if (pt->z < D_80110238_246118_SlotCarDerby) {
                D_80110238_246118_SlotCarDerby = pt->z;
            }
        }
        D_80110230_246110_SlotCarDerby = fabsf(D_80110234_246114_SlotCarDerby - D_80110238_246118_SlotCarDerby);
    }
    ease = 0.0f;
    if (D_80110808_2466E8_SlotCarDerby != 0) {
        for (i = 0; i < 3; i++) {
            max[i] = -30000.0f;
            min[i] = 30000.0f;
        }
        for (i = 0; i < D_80110808_2466E8_SlotCarDerby; i++) {
            pmax = max;
            pmin = min;
            for (j = 0, p = &D_80110810_2466F0_SlotCarDerby[i].pos.x; j < 3; j++, pmax++, pmin++) {
                if (p[j] > *pmax) {
                    *pmax = p[j];
                }
                if (p[j] < *pmin) {
                    *pmin = p[j];
                }
            }
        }
        if (D_801102C8_2461A8_SlotCarDerby.unk_00 == 3) {
            cam->target.view[1] = 170.0 - cam->target.pos[2] / 1.5;
            lean = 0.3f;
        } else if (D_801102C8_2461A8_SlotCarDerby.unk_00 == 2) {
            cam->target.view[2] += cam->target.pos[2] * 0.5;
            lean = (cur->view[2] - D_80110234_246114_SlotCarDerby) / D_80110230_246110_SlotCarDerby;
        }
        for (i = 0; i < 3; i++) {
            cam->target.pos[i] = min[i] + (max[i] - min[i]) * 0.5;
            cam->target.view[i] -= cam->target.pos[i];
        }
        if (D_801102C8_2461A8_SlotCarDerby.unk_00 == 2) {
            cam->target.view[0] = 0.0f;
        }
        for (i = 0; i < D_80110808_2466E8_SlotCarDerby; i++) {
            for (j = 0, p = &D_80110810_2466F0_SlotCarDerby[i].pos.x; j < 3; j++) {
                p[j] -= cam->target.pos[j];
            }
        }
        func_800B1960_B2560(mtx, cam->target.view[0], cam->target.view[1], cam->target.view[2], 0.0f, 0.0f, 0.0f,
                            up[0], up[1], up[2]);
        best = mtx[3][0] = mtx[3][1] = mtx[3][2] = 0.0f;
        t = HuMathSin(D_800C9B80_CA780->fov[0] * 0.5) / func_800B7890_B8490(D_800C9B80_CA780->fov[0] * 0.5);
        for (i = 0; i < D_80110808_2466E8_SlotCarDerby; i++) {
            func_801067D8_23C6B8_SlotCarDerby(mtx, D_80110810_2466F0_SlotCarDerby[i].pos.x,
                                              D_80110810_2466F0_SlotCarDerby[i].pos.y,
                                              D_80110810_2466F0_SlotCarDerby[i].pos.z, out);
            max[0] = fabs(fabs(out[0]) / t) + out[2];
            max[1] = fabs(fabs(out[1]) / t) + out[2];
            d = (max[1] <= max[0]) ? max[0] : max[1];
            max[2] = d * (1.0 - d / 6000.0 * 0.3);
            if (best < max[2]) {
                best = max[2];
            }
        }
        best *= 1.5384615384615383;
        if (D_801102C8_2461A8_SlotCarDerby.unk_00 == 2) {
            if (D_8010FAF0_2459D0_SlotCarDerby < 5.0) {
                D_8010FAF0_2459D0_SlotCarDerby += 0.5;
            }
        } else if (D_8010FAF0_2459D0_SlotCarDerby > 0.0) {
            D_8010FAF0_2459D0_SlotCarDerby -= 0.5;
        }
        best += D_8010FAF0_2459D0_SlotCarDerby;
        switch (D_8011023C_24611C_SlotCarDerby) {
        case 0:
        case 1:
            if (best > 600.0) {
                best = 600.0f;
            }
            break;
        default:
            if (best > 700.0) {
                best = 700.0f;
            }
            break;
        }
        if (D_801102C8_2461A8_SlotCarDerby.unk_00 == 2) {
            if (best < 160.0) {
                best = 160.0f;
            }
        } else if (best < 40.0) {
            best = 40.0f;
        }
        cam->target.zoom = best;
        if (D_8010FAD4_2459B4_SlotCarDerby == NULL) {
            D_8010FAD4_2459B4_SlotCarDerby = func_80027154_27D54(5 * sizeof(f32), D_800FA1AA_FADAA);
            for (i = 0; i < 5; i++) {
                D_8010FAD4_2459B4_SlotCarDerby[i] = 160.0f;
            }
        } else {
            if (++D_8010FAD8_2459B8_SlotCarDerby >= 5) {
                D_8010FAD8_2459B8_SlotCarDerby = 0;
            }
            D_8010FAD4_2459B4_SlotCarDerby[D_8010FAD8_2459B8_SlotCarDerby] = best;
            if (D_801102C8_2461A8_SlotCarDerby.unk_00 == 3 && D_801102E0_2461C0_SlotCarDerby == 0 &&
                D_801102C8_2461A8_SlotCarDerby.unk_0A == 0) {
                D_801102E0_2461C0_SlotCarDerby = 1;
            } else if (D_801102E0_2461C0_SlotCarDerby != 0) {
                D_801102E0_2461C0_SlotCarDerby++;
            }
        }
    } else {
        p = D_8010FADC_2459BC_SlotCarDerby[D_8011023C_24611C_SlotCarDerby];
        cam->target.pos[0] = *p++;
        cam->target.pos[1] = *p++;
        cam->target.pos[2] = *p++;
        cam->target.view[0] = *p++;
        cam->target.view[1] = *p++;
        cam->target.view[2] = *p;
        ease = (cam->target.view[0] - cam->target.pos[0]) * (cam->target.view[0] - cam->target.pos[0]);
        ease += (cam->target.view[1] - cam->target.pos[1]) * (cam->target.view[1] - cam->target.pos[1]);
        ease += (cam->target.view[2] - cam->target.pos[2]) * (cam->target.view[2] - cam->target.pos[2]);
        cam->target.zoom = sqrtf(ease);
        D_8010FAE8_2459C8_SlotCarDerby += 0.002;
        if (D_8010FAE8_2459C8_SlotCarDerby > 0.075) {
            D_8010FAE8_2459C8_SlotCarDerby = 0.075f;
        }
        ease = D_8010FAE8_2459C8_SlotCarDerby;
    }
    n = 0;
    for (i = 0; i < D_80110808_2466E8_SlotCarDerby; i++) {
        if (D_80110810_2466F0_SlotCarDerby[i].weight != 0.0f) {
            ease += D_80110810_2466F0_SlotCarDerby[i].weight;
        }
        n++;
    }
    if (n != 0) {
        ease /= n;
    }
    for (i = 0; i < 3; i++) {
        cur->pos[i] = (cam->target.pos[i] - cur->pos[i]) * ease + cur->pos[i];
        cur->view[i] = (cam->target.view[i] - cur->view[i]) * ease + cur->view[i];
    }
    cur->zoom = (cam->target.zoom - cur->zoom) * ease + cur->zoom;
    D_800FA610_FB210 = cur->zoom * 10.0;
    func_80106750_23C630_SlotCarDerby((Vec*)cur->view, &D_800FD474_FE074.x);
    lean *= 2.0;
    D_800FD474_FE074.x -= lean * lean * lean * 17.0;
    D_8010274C_10334C.x = cur->pos[0] * 10.0;
    D_8010274C_10334C.y = cur->pos[1] * 10.0;
    D_8010274C_10334C.z = cur->pos[2] * 10.0;
    D_80110808_2466E8_SlotCarDerby = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_80106C68_23CB48_SlotCarDerby);
#endif

void func_80107708_23D5E8_SlotCarDerby(void) {
    SCDParticle* p;
    s32 i;
    s32 sprite;
    s32 group;
    void* data;

    for (i = 0; i < 16; i++) {
        D_801104F8_2463D8_SlotCarDerby[i].unk_00 = 0;
    }
    data = DataRead(0x400018);
    sprite = SprAnimRead(data);
    DataClose(data);
    group = SprCreate(16, 0);
    for (p = D_801104F8_2463D8_SlotCarDerby, i = 0; i < 16; i++, p++) {
        SprAnimSet(group, i, sprite, 0);
        func_8008225C_82E5C(group, i, 0);
        SprBankSet(group, i, i & 3);
        func_80082488_83088(group, i, 0xE8);
        SprAttrSet(group, i, 0x9008);
        p->unk_00 = -0x7FFF;
        p->unk_02 = sprite;
        p->unk_04 = group;
        p->unk_06 = i;
    }
}

void func_80107864_23D744_SlotCarDerby(void) {
    SCDParticle* p;
    s32 i;
    f32 s;

    for (p = D_801104F8_2463D8_SlotCarDerby, i = 0; i < 16; i++, p++) {
        if (p->unk_00 != 0) {
            p->unk_00 &= 1;
            p->unk_0C = 160.0 - (f32)(((((rand8() << 8) | rand8())) >> 8) - 128);
            p->unk_10 = 200.0 - (f32)(((((rand8() << 8) | rand8())) >> 10) - 32);
            p->unk_18 = -(f32)(((((rand8() << 8) | rand8()) * 75) >> 13) + 200) * 0.01;
            p->unk_24 = (f32)((((rand8() << 8) | rand8()) * 75) >> 14) * 0.01;
            s = (f32)((((rand8() << 8) | rand8()) * 15) >> 13) * 0.01 + 0.8;
            p->unk_1C = p->unk_20 = p->unk_28 = s;
            p->unk_08 = 0;
            p->unk_0A = (((rand8() << 8) | rand8()) * 45) >> 13;
            SprPosSet(p->unk_04, p->unk_06, p->unk_0C, p->unk_10);
            SprScaleSet(p->unk_04, p->unk_06, p->unk_1C, p->unk_20);
            SprAttrReset(p->unk_04, p->unk_06, 0x8000);
        }
    }
}

void func_80107AD4_23D9B4_SlotCarDerby(void) {
    SCDParticle* p;
    s32 i;

    for (p = D_801104F8_2463D8_SlotCarDerby, i = 0; i < 16; i++, p++) {
        if (p->unk_00 > 0) {
            p->unk_0C += HuMathSin(p->unk_0A) * p->unk_24;
            p->unk_10 += p->unk_18;
            p->unk_1C = p->unk_20 = p->unk_28;
            SprPosSet(p->unk_04, p->unk_06, p->unk_0C, p->unk_10);
            SprScaleSet(p->unk_04, p->unk_06, p->unk_1C, p->unk_20);
            p->unk_0A = (p->unk_0A + 2) % 360;
            if (p->unk_10 < -100.0) {
                p->unk_00 |= 0x8000;
                SprAttrSet(p->unk_04, p->unk_06, 0x8000);
            }
            p->unk_08++;
        }
    }
}

void func_80107C40_23DB20_SlotCarDerby(omObjData* obj) {
    s32 ids[3][2] = { { 6, 7 }, { 8, 9 }, { 10, 11 } };
    void* data;
    s16 sprite;
    s32 group;

    obj->func_ptr = NULL;
    data = DataRead(0x400017);
    sprite = SprAnimRead(data);
    DataClose(data);
    group = SprCreate(1, 0);
    SprAnimSet(group, 0, sprite, 0);
    SprPosSet(group, 0, 160, 120);
    SprAttrSet(group, 0, 0x4000);
    obj->model[0] = func_80018A30_19630(ids[D_8011023C_24611C_SlotCarDerby][0] | 0x400000, 0x2B9);
    obj->model[1] = func_80018A30_19630(ids[D_8011023C_24611C_SlotCarDerby][1] | 0x400000, 0x299);
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 2.0f;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    func_800297E8_2A3E8(obj->model[1], obj->scale.x, obj->scale.y, obj->scale.z);
}

void func_80107E0C_23DCEC_SlotCarDerby(void) {
    func_80109140_23F020_SlotCarDerby(5);
    D_801102C8_2461A8_SlotCarDerby.unk_00 = 0;
    D_801102C8_2461A8_SlotCarDerby.unk_06 = 0;
    D_801102C8_2461A8_SlotCarDerby.unk_08 = 9000;
    D_801102C8_2461A8_SlotCarDerby.unk_0C = 0;
    func_80109140_23F020_SlotCarDerby(0);
    func_80102C98_238B78_SlotCarDerby();
    func_80102F6C_238E4C_SlotCarDerby();
    func_80106A00_23C8E0_SlotCarDerby();
    func_80107708_23D5E8_SlotCarDerby();
    func_80107864_23D744_SlotCarDerby();
}

void func_80107E74_23DD54_SlotCarDerby(void) {
    SCDCar* car;
    SCDCar* other;
    s32 i;
    s32 j;
    s16 most = 0;

    if (!(D_801102CE_2461AE_SlotCarDerby & 0xF)) {
        for (car = D_801102E8_2461C8_SlotCarDerby, i = 0; i < 4; i++, car++) {
            car->unk_05 = 0;
            if ((car->unk_00 & 1) && car->unk_04 == 0) {
                for (other = D_801102E8_2461C8_SlotCarDerby, j = 0; j < 4; j++, other++) {
                    if ((other->unk_00 & 1) && other->unk_04 == 0 && car->unk_4C < other->unk_4C) {
                        car->unk_05++;
                    }
                }
            }
            if (car->unk_03 != 0) {
                s16 n = car->unk_05;

                if (most < n) {
                    most = n;
                }
            }
        }
        D_801102D4_2461B4_SlotCarDerby = most;
    }
}

/* Register allocation (two more saved registers) and base-register choices for the game state's
   fields (masked 97, mostly branch offsets); MP1 func_800FB2FC was NON_MATCHING too. Retail quirk
   kept: state 3 sets D_8010FAF6 to 48/36 and then to 1, so the voice step runs on the next frame. */
#ifdef NON_MATCHING
void func_80107F48_23DE28_SlotCarDerby(s32 x, s32 y, s32 z) {
    s16 unused[16]; /* retail stores [1] and [9] before func_80079718 and never reads them */
    Vec v;
    Vec ab[2];
    Vec* start;
    SCDCar* car;
    s32 c;
    s32 i;
    s32 j;
    s32 player;
    s32 lost;
    s16 alive;
    s16 winner;
    s32 mes;
    f32 t;

    v.x = x;
    v.y = y;
    v.z = z;
    start = &D_8010FAB0_245990_SlotCarDerby[D_8011023C_24611C_SlotCarDerby];
    c = D_8011023C_24611C_SlotCarDerby * 3;
    switch (D_801102C8_2461A8_SlotCarDerby.unk_00) {
        case 0:
            if (D_801102C8_2461A8_SlotCarDerby.unk_06 == 1) {
                D_801102C8_2461A8_SlotCarDerby.unk_0A = 0;
                D_8010FAF6_2459D6_SlotCarDerby = 0;
                PlayMusic(0x58);
                func_80108D6C_23EC4C_SlotCarDerby();
                InitFadeIn(0, 16);
            }
            if (D_8010FAF4_2459D4_SlotCarDerby < 0) {
                D_8010FAF4_2459D4_SlotCarDerby = PlaySound(0x4AC);
                D_801102DC_2461BC_SlotCarDerby = 0;
            }
            if (D_8010FAF8_2459D8_SlotCarDerby > 0.0) {
                if (D_801102C8_2461A8_SlotCarDerby.unk_06 >= 140) {
                    t = (D_801102C8_2461A8_SlotCarDerby.unk_06 - 140) / 29.0f;
                    if (t < 0.0) {
                        t = 0.0f;
                    } else if (t > 1.0) {
                        t = 1.0f;
                    }
                    func_80106B74_23CA54_SlotCarDerby(&D_8010F900_2457E0_SlotCarDerby[c].pos.x,
                                                      D_8010F900_2457E0_SlotCarDerby[c + 1].weight * D_8010FAF8_2459D8_SlotCarDerby * 0.7);
                    func_80106B74_23CA54_SlotCarDerby(&D_8010F900_2457E0_SlotCarDerby[c + 1].pos.x,
                                                      D_8010F900_2457E0_SlotCarDerby[c + 1].weight * D_8010FAF8_2459D8_SlotCarDerby * 0.7);
                    v.x = t * (D_8010F900_2457E0_SlotCarDerby[c + 2].pos.x - D_8010FA20_245900_SlotCarDerby[c + 2].pos.x) + D_8010FA20_245900_SlotCarDerby[c + 2].pos.x;
                    v.y = t * (D_8010F900_2457E0_SlotCarDerby[c + 2].pos.y - D_8010FA20_245900_SlotCarDerby[c + 2].pos.y) + D_8010FA20_245900_SlotCarDerby[c + 2].pos.y;
                    v.z = t * (D_8010F900_2457E0_SlotCarDerby[c + 2].pos.z - D_8010FA20_245900_SlotCarDerby[c + 2].pos.z) + D_8010FA20_245900_SlotCarDerby[c + 2].pos.z;
                } else {
                    if (D_801102C8_2461A8_SlotCarDerby.unk_06 >= 96) {
                        t = (D_801102C8_2461A8_SlotCarDerby.unk_06 - 95) / 45.0f;
                        if (t > 1.0) {
                            t = 1.0f;
                        }
                    } else {
                        t = 0.0f;
                    }
                    ab[0].x = t * start->x + D_8010FA20_245900_SlotCarDerby[c].pos.x;
                    ab[0].y = t * start->y + D_8010FA20_245900_SlotCarDerby[c].pos.y;
                    ab[0].z = t * start->z + D_8010FA20_245900_SlotCarDerby[c].pos.z;
                    ab[1].x = t * start->x + D_8010FA20_245900_SlotCarDerby[c + 1].pos.x;
                    ab[1].y = t * start->y + D_8010FA20_245900_SlotCarDerby[c + 1].pos.y;
                    ab[1].z = t * start->z + D_8010FA20_245900_SlotCarDerby[c + 1].pos.z;
                    func_80106B74_23CA54_SlotCarDerby(&ab[0].x, D_8010FA20_245900_SlotCarDerby[c].weight * D_8010FAF8_2459D8_SlotCarDerby);
                    func_80106B74_23CA54_SlotCarDerby(&ab[1].x, D_8010FA20_245900_SlotCarDerby[c + 1].weight * D_8010FAF8_2459D8_SlotCarDerby);
                    v.x = D_8010FA20_245900_SlotCarDerby[c + 2].pos.x;
                    v.y = D_8010FA20_245900_SlotCarDerby[c + 2].pos.y;
                    v.z = D_8010FA20_245900_SlotCarDerby[c + 2].pos.z;
                }
            } else {
                v.x = D_8010FA20_245900_SlotCarDerby[c + 2].pos.x;
                v.y = D_8010FA20_245900_SlotCarDerby[c + 2].pos.y;
                v.z = D_8010FA20_245900_SlotCarDerby[c + 2].pos.z;
            }
            if (D_801102C8_2461A8_SlotCarDerby.unk_06 == 60) {
                D_8010FAF8_2459D8_SlotCarDerby = 0.01f;
            } else if (D_801102C8_2461A8_SlotCarDerby.unk_06 >= 170) {
                D_801102C8_2461A8_SlotCarDerby.unk_00 = 1;
                D_801102C8_2461A8_SlotCarDerby.unk_06 = 0;
                D_801102C8_2461A8_SlotCarDerby.unk_04 = -1;
                D_801102C8_2461A8_SlotCarDerby.unk_02 = 3;
                func_80109140_23F020_SlotCarDerby(1);
            }
            break;
        case 1:
            func_80106B74_23CA54_SlotCarDerby(&D_8010F900_2457E0_SlotCarDerby[c].pos.x,
                                              D_8010F900_2457E0_SlotCarDerby[c].weight * D_8010FAF8_2459D8_SlotCarDerby);
            func_80106B74_23CA54_SlotCarDerby(&D_8010F900_2457E0_SlotCarDerby[c + 1].pos.x,
                                              D_8010F900_2457E0_SlotCarDerby[c + 1].weight * D_8010FAF8_2459D8_SlotCarDerby);
            v.x = D_8010F900_2457E0_SlotCarDerby[c + 2].pos.x;
            v.y = D_8010F900_2457E0_SlotCarDerby[c + 2].pos.y;
            v.z = D_8010F900_2457E0_SlotCarDerby[c + 2].pos.z;
            if (D_801102C8_2461A8_SlotCarDerby.unk_06 >= 31) {
                D_801102C8_2461A8_SlotCarDerby.unk_02--;
                D_801102C8_2461A8_SlotCarDerby.unk_06 = 0;
                if (D_801102C8_2461A8_SlotCarDerby.unk_02 == 0) {
                    D_801102C8_2461A8_SlotCarDerby.unk_00 = 2;
                    func_80109140_23F020_SlotCarDerby(2);
                    D_801102C8_2461A8_SlotCarDerby.unk_0A = 60;
                    D_801102C8_2461A8_SlotCarDerby.unk_0C = 0;
                    PlaySound(0x2AB);
                    PlayMusic(0x22);
                } else {
                    PlaySound(0x2AA);
                }
            }
            if (D_801102C8_2461A8_SlotCarDerby.unk_02 == 1 && D_801102C8_2461A8_SlotCarDerby.unk_06 == 0) {
                func_800691FC_69DFC(15);
            }
            break;
        case 2:
            if (D_801102D8_2461B8_SlotCarDerby == 0) {
                D_801102C8_2461A8_SlotCarDerby.unk_08--;
                if (D_801102C8_2461A8_SlotCarDerby.unk_0A != 0) {
                    for (i = 0; i < 3; i++) {
                        func_80106B74_23CA54_SlotCarDerby(&D_8010F900_2457E0_SlotCarDerby[i + 9].pos.x,
                                                          D_8010F900_2457E0_SlotCarDerby[i + 9].weight);
                    }
                    if (D_801109D6_2468B6_SlotCarDerby == 0) {
                        D_801102D2_2461B2_SlotCarDerby--;
                    }
                }
                i = 0;
                func_801032F8_2391D8_SlotCarDerby();
                func_80107E74_23DD54_SlotCarDerby();
                car = D_801102E8_2461C8_SlotCarDerby;
                lost = 0;
                alive = 0;
                winner = -1;
                for (; i < 4; i++, car++) {
                    if (!(car->unk_00 & 1)) {
                        continue;
                    }
                    if (car->unk_04 == 0 && !(car->unk_00 & 0x40)) {
                        alive++;
                        continue;
                    }
                    if (car->unk_04 == 1) {
                        winner = i;
                        continue;
                    }
                    if (D_801109D6_2468B6_SlotCarDerby != 0) {
                        if (gPlayers[car->unk_7C->work[0]].group == 0) {
                            lost = 1;
                            continue;
                        }
                    }
                }
                if (lost == 1) {
                    alive = 0;
                }
                if (winner >= 0) {
                    D_801102CC_2461AC_SlotCarDerby = winner;
                    for (i = 0, car = D_801102E8_2461C8_SlotCarDerby; i < 4; i++, car++) {
                        if ((car->unk_00 & 1) && car->unk_02 == 1) {
                            car->unk_02 = 2;
                            car->unk_06 = 0;
                            car->unk_64 = car->unk_66 = 0;
                            if (car->unk_04 == 1) {
                                gPlayers[car->unk_7C->work[0]].coins_mg_bonus += 10;
                            }
                        }
                    }
                    func_800794A8_7A0A8(75);
                    D_801102C8_2461A8_SlotCarDerby.unk_00 = 3;
                    D_801102C8_2461A8_SlotCarDerby.unk_06 = 0;
                    func_80109140_23F020_SlotCarDerby(3);
                } else if (D_801102C8_2461A8_SlotCarDerby.unk_08 <= 0 || alive == 0) {
                    func_800794A8_7A0A8(75);
                    D_801102C8_2461A8_SlotCarDerby.unk_06 = 0;
                    if (D_801109D6_2468B6_SlotCarDerby == 0) {
                        func_800691FC_69DFC(0x12);
                        D_801102C8_2461A8_SlotCarDerby.unk_00 = 8;
                    } else {
                        func_800691FC_69DFC(D_801102D0_2461B0_SlotCarDerby > 0 ? 3 : 0x12);
                        D_801102C8_2461A8_SlotCarDerby.unk_00 = 4;
                        D_8010FAFC_2459DC_SlotCarDerby = 60;
                    }
                    for (j = 0; j < 4; j++) {
                        func_801030D4_238FB4_SlotCarDerby(&D_801102E8_2461C8_SlotCarDerby[j], -1);
                        func_801091DC_23F0BC_SlotCarDerby(D_801102E8_2461C8_SlotCarDerby[j].unk_01, 0);
                    }
                }
            }
            break;
        case 3:
            if (D_801102D8_2461B8_SlotCarDerby == 0) {
                func_801032F8_2391D8_SlotCarDerby();
                if (D_801109D6_2468B6_SlotCarDerby != 0) {
                    if (D_801109D0_2468B0_SlotCarDerby != 0) {
                        D_801102C8_2461A8_SlotCarDerby.unk_00 = 4;
                        D_8010FAFC_2459DC_SlotCarDerby = 60;
                    }
                } else if (D_8010FAF6_2459D6_SlotCarDerby == 0) {
                    if ((func_80069538_6A138() == 0 || D_801102C8_2461A8_SlotCarDerby.unk_06 == 100) &&
                        D_801109D0_2468B0_SlotCarDerby != 0 && D_801102E0_2461C0_SlotCarDerby >= 11 &&
                        D_801102C8_2461A8_SlotCarDerby.unk_0A < 15) {
                        if (D_801102DE_2461BE_SlotCarDerby != 0) {
                            D_8010FAF6_2459D6_SlotCarDerby = 48;
                            mes = 0x55;
                        } else {
                            D_8010FAF6_2459D6_SlotCarDerby = 36;
                            mes = 0x51;
                        }
                        PlayMusic(mes);
                        for (j = 0; j < 4; j++) {
                            if (D_801102E8_2461C8_SlotCarDerby[j].unk_04 == 1) {
                                func_800691FC_69DFC(6, gPlayers[D_801102E8_2461C8_SlotCarDerby[j].unk_7C->work[0]].character);
                                break;
                            }
                        }
                        D_8010FAF6_2459D6_SlotCarDerby = 1;
                        D_801102C8_2461A8_SlotCarDerby.unk_06 = 101;
                    }
                } else if (--D_8010FAF6_2459D6_SlotCarDerby == 0) {
                    for (j = 0; j < 4; j++) {
                        if (D_801102E8_2461C8_SlotCarDerby[j].unk_04 == 1) {
                            break;
                        }
                    }
                    player = D_801102E8_2461C8_SlotCarDerby[j].unk_7C->work[0];
                    unused[1] = player;
                    unused[9] = j;
                    func_80079718_7A318(0x103, gPlayers[player].character);
                    D_801102C8_2461A8_SlotCarDerby.unk_00 = 4;
                    D_801102C8_2461A8_SlotCarDerby.unk_06 = 233;
                    D_801102C8_2461A8_SlotCarDerby.unk_00 = 4;
                    D_8010FAFC_2459DC_SlotCarDerby = (D_801102DE_2461BE_SlotCarDerby != 0) ? 162 : 120;
                }
                if (D_801102C8_2461A8_SlotCarDerby.unk_0A != 0) {
                    for (i = 0; i < 3; i++) {
                        func_80106B74_23CA54_SlotCarDerby(&D_8010F900_2457E0_SlotCarDerby[c + i + 9].pos.x,
                                                          D_8010F900_2457E0_SlotCarDerby[c + i + 9].weight);
                    }
                    D_801102C8_2461A8_SlotCarDerby.unk_0A--;
                }
            }
            break;
        case 7:
            func_801032F8_2391D8_SlotCarDerby();
            for (i = 0; i < 3; i++) {
                func_80106B74_23CA54_SlotCarDerby(&D_8010F900_2457E0_SlotCarDerby[i + 9].pos.x,
                                                  D_8010F900_2457E0_SlotCarDerby[i + 9].weight);
            }
            if ((D_801102C8_2461A8_SlotCarDerby.unk_06 < 300 && func_80069538_6A138() == 2) ||
                (D_801109D6_2468B6_SlotCarDerby != 0 && D_801102C8_2461A8_SlotCarDerby.unk_06 == 90)) {
                if (D_801109D6_2468B6_SlotCarDerby == 0) {
                    D_8010FAF6_2459D6_SlotCarDerby = 90;
                    PlayMusic(0x57);
                } else if (D_801102C8_2461A8_SlotCarDerby.unk_06 == 90) {
                    D_8010FAF6_2459D6_SlotCarDerby = 10;
                } else {
                    D_8010FAF6_2459D6_SlotCarDerby = 60;
                }
                D_801102C8_2461A8_SlotCarDerby.unk_06 = 300;
            }
            if (D_8010FAF6_2459D6_SlotCarDerby != 0) {
                if (--D_8010FAF6_2459D6_SlotCarDerby == 0) {
                    D_801102D6_2461B6_SlotCarDerby = 1;
                }
            }
            break;
        case 8:
            func_801032F8_2391D8_SlotCarDerby();
            for (i = 0; i < 3; i++) {
                func_80106B74_23CA54_SlotCarDerby(&D_8010F900_2457E0_SlotCarDerby[i + 9].pos.x,
                                                  D_8010F900_2457E0_SlotCarDerby[i + 9].weight);
            }
            if (func_80069538_6A138() == 0) {
                func_800691FC_69DFC(0x13);
                D_8010FAFC_2459DC_SlotCarDerby = 120;
                D_801102C8_2461A8_SlotCarDerby.unk_00 = 4;
                if (D_801109D6_2468B6_SlotCarDerby == 0) {
                    PlayMusic(0x57);
                }
            }
            break;
        case 4:
            if (D_8010FAFC_2459DC_SlotCarDerby <= 0) {
                D_801102D6_2461B6_SlotCarDerby = 1;
            } else {
                D_8010FAFC_2459DC_SlotCarDerby--;
            }
            break;
    }
    D_801102C8_2461A8_SlotCarDerby.unk_06++;
    if (D_8010FAF8_2459D8_SlotCarDerby > 0.0 && D_8010FAF8_2459D8_SlotCarDerby < 1.0) {
        D_8010FAF8_2459D8_SlotCarDerby += 0.05;
    }
    func_80106C68_23CB48_SlotCarDerby(&v);
    func_80107AD4_23D9B4_SlotCarDerby();
    if (D_801011FC_101DFC == 1) {
        D_801102D6_2461B6_SlotCarDerby = 1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_80107F48_23DE28_SlotCarDerby);
#endif

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_80108D48_23EC28_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_80108D6C_23EC4C_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_80108F14_23EDF4_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/2386E0", func_80108FF0_23EED0_SlotCarDerby);
