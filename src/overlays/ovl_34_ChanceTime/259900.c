#include "common.h"
#include "ovl_34.h"

/* The second variant's holder: models, motions, placed at path[1]. (MP1 func_800FC1C8) */


void func_80102800_259900_ChanceTime(void) {
    Vec pos;
    Vec rot;
    Vec up;
    s16 i;
    s16 n;
    s32 j;

    for (i = 0; i < 4; i++) {
        if (gPlayers[i].group == 0) {
            break;
        }
    }
    switch (i) {
    case 1:
        D_80110D6A_267E6A_ChanceTime[0] = 1;
        break;
    case 2:
        D_80110D6A_267E6A_ChanceTime[0] = 2;
        break;
    case 3:
        D_80110D6A_267E6A_ChanceTime[0] = 3;
        break;
    case 0:
    default:
        D_80110D6A_267E6A_ChanceTime[0] = 0;
        break;
    }
    for (i = 1, n = 0; i < 4; i++, n++) {
        if (D_80110D6A_267E6A_ChanceTime[0] == n) {
            n++;
        }
        D_80110D6A_267E6A_ChanceTime[i] = n;
    }
    func_8002D4D0_2E0D0(10);
    func_8002F290_2FE90(D_800F9D30_FA930, 0x40);
    func_80020D20_21920(60);
    omInitObjMan(40, 60);
    func_80088640_89240();
    func_80079128_79D28();
    func_800615FC_621FC_unproto(-1, -1);
    func_80018E30_19A30(1);
    D_80102708_103308 = 1;
    D_80110060_267160_ChanceTime = _CheckFlag(0x45);
    func_80026DAC_279AC(1, 0x40, 0x40, 0x40);
    func_80026E00_27A00(1, 13.0f, -100.0f, 64.0f);
    ScissorSet(0, 0.0f, 0.0f, 319.0f, 239.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 20.0f, 80.0f, 8000.0f);
    pos.x = 0.0f;
    pos.y = 250.0f;
    pos.z = 2800.0f;
    rot.x = 0.0f;
    rot.y = 0.0f;
    rot.z = 0.0f;
    up.x = 0.0f;
    up.y = 1.0f;
    up.z = 0.0f;
    for (j = 0; j < D_800FDBCA_FE7CA; j++) {
        func_800B3820_B4420(&D_800C9B80_CA780->mtxs[j].perspMtx);
        func_800B3820_B4420(&D_800C9B80_CA780->mtxs[j].lookAtMtx);
    }
    Hu3DCamSetPositionOrientation(0, &pos, &rot, &up);
    func_8000C38C_CF8C();
    func_8000C3C8_CFC8();
    D_80110914_267A14_ChanceTime = func_80018A64_19664(0x440009, 0xABD);
    D_80110916_267A16_ChanceTime = func_80018A64_19664(0x44000A, 0xABD);
    D_80110918_267A18_ChanceTime = func_80018A64_19664(0x44000B, 0xABD);
    func_8000C460_D060();
    func_8000C578_D178(1);
    func_8007273C_7333C(D_80110060_267160_ChanceTime != 0 ? D_80110230_267330_ChanceTime : D_80110248_267348_ChanceTime, 1);
    D_800FA606_FB206 = 0;
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    if (D_80110060_267160_ChanceTime != 0) {
        omAddObj(1, 10, 10, -1, func_8010B02C_26212C_ChanceTime);
    } else {
        D_8011090C_267A0C_ChanceTime = omAddObj(1, 16, 4, -1, func_80103714_25A814_ChanceTime);
        D_80110910_267A10_ChanceTime = omAddObj(1, 16, 4, -1, func_80103398_25A498_ChanceTime);
    }
    func_8000C018_CC18(D_800F8FE0_F9BE0);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(2, 3, 0, -1, func_8010E440_265540_ChanceTime);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(12, 0, 0, -1, func_8010E71C_26581C_ChanceTime);
    func_8010BF50_263050_ChanceTime();
    D_80110D80_267E80_ChanceTime[0] = omAddObj(12, 3, 0, -1, func_8010BF7C_26307C_ChanceTime);
    D_80110D80_267E80_ChanceTime[1] = omAddObj(12, 3, 0, -1, func_8010BFD0_2630D0_ChanceTime);
    if (D_80110060_267160_ChanceTime != 0) {
        /* retail: D_80110D88 through the D_80110D80 base (s0 + 8), as in MP1 */
        D_80110D80_267E80_ChanceTime[2] = omAddObj(12, 3, 0, -1, func_8010C080_263180_ChanceTime);
    } else {
        D_80110D88_267E88_ChanceTime = omAddObj(12, 3, 0, -1, func_8010C008_263108_ChanceTime);
    }
    omAddObj(5, 3, 0, -1, func_8010E0D4_2651D4_ChanceTime);
    omAddObj(1, 0, 0, -1, func_80102E4C_259F4C_ChanceTime);
    D_80110908_267A08_ChanceTime = omAddObj(5, 33, 0, -1, func_801077D8_25E8D8_ChanceTime);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(10, 2, 60, -1, func_8010EED0_265FD0_ChanceTime);
    omAddObj(1, 0, 0, -1, func_8010BF28_263028_ChanceTime);
    InitFadeIn(D_80110060_267160_ChanceTime != 0 ? 3 : 5, 16);
}

/* NON_MATCHING: one delay slot (the else arm of the title message call fills it with `li v0,1`,
 * GCC here with the shared `sw zero,16(sp)`); every later branch target shifts by 4. */
#ifdef NON_MATCHING
void func_80102E4C_259F4C_ChanceTime(omObjData* obj) {
    CTPlayerWork* work;

    func_8000C3C8_CFC8();
    work = CT_PWORK(D_800FFFD8_100BD8[0]);
    switch (D_800F8FD0_F9BD0) {
    case 0:
        if (D_801100F0_2671F0_ChanceTime == 0) {
            PlayMusic(0x23);
            if (D_80110060_267160_ChanceTime == 0) {
                PlaySound(0x4A3);
            }
            D_80110062_267162_ChanceTime = 1;
            D_80110063_267163_ChanceTime = 1;
            D_801100F0_2671F0_ChanceTime++;
        }
        if (D_80110064_267164_ChanceTime != 1) {
            break;
        }
        if (D_801100F0_2671F0_ChanceTime == 10) {
            /* "ＣＨＡＮＣＥ　ＴＩＭＥ♪" / "ＣＨＡＮＣＥ　ＴＩＭＥ" */
            if (D_80110060_267160_ChanceTime != 0) {
                D_801106B0_2677B0_ChanceTime = func_800691FC_69DFC(9, "\x82\x62\x82\x67\x82\x60\x82\x6D\x82\x62\x82\x64\x81\x40\x82\x73\x82\x68\x82\x6C\x82\x64\x81\xF3",
                                                                   0xA0, 0x64, 0, 0, 0, 0, 1);
            } else {
                D_801106B0_2677B0_ChanceTime = func_800691FC_69DFC(9, "\x82\x62\x82\x67\x82\x60\x82\x6D\x82\x62\x82\x64\x81\x40\x82\x73\x82\x68\x82\x6C\x82\x64",
                                                                   0xA0, 0x64, 0, 0, 0, 0, 1);
            }
            D_80110108_267208_ChanceTime = &D_800F9570_FA170[D_801106B0_2677B0_ChanceTime];
            D_80110100_267200_ChanceTime = 0.0f;
        }
        if (D_801100F0_2671F0_ChanceTime >= 11 && func_80069538_6A138() != 0 && !(func_80069538_6A138() & 2)) {
            if (D_801100FB_2671FB_ChanceTime == 0) {
                if (D_80110060_267160_ChanceTime != 0) {
                    PlaySound(0xF3);
                } else {
                    PlaySound(0xF2);
                }
                D_801100FB_2671FB_ChanceTime = 1;
            }
            if (D_80110108_267208_ChanceTime->unk04 + 40 < D_80110108_267208_ChanceTime->unk06) {
                if (D_801100FC_2671FC_ChanceTime == 0) {
                    D_80110108_267208_ChanceTime->unk68 += 0.3f;
                    D_80110108_267208_ChanceTime->unk6C += 0.3f;
                    if (D_80110108_267208_ChanceTime->unk68 > 1.2) {
                        D_80110108_267208_ChanceTime->unk68 += 1.0f;
                        D_80110108_267208_ChanceTime->unk6C += 1.0f;
                        D_801100FC_2671FC_ChanceTime = 1;
                    }
                } else {
                    D_80110108_267208_ChanceTime->unk68 = func_800B7890_B8490(D_80110100_267200_ChanceTime) * 0.3f + 1.0f;
                    D_80110108_267208_ChanceTime->unk6C = func_800B7890_B8490(D_80110100_267200_ChanceTime) * 0.3f + 1.0f;
                    D_80110100_267200_ChanceTime += 60.0f;
                }
            } else if (D_80110108_267208_ChanceTime->unk04 + 20 > D_80110108_267208_ChanceTime->unk06) {
                D_80110108_267208_ChanceTime->unk68 = 1.0f;
                D_80110108_267208_ChanceTime->unk6C = 1.0f;
                D_80110108_267208_ChanceTime->unk03 = (u8)D_80110104_267204_ChanceTime;
                D_80110104_267204_ChanceTime -= 12;
                if (D_80110104_267204_ChanceTime < 0) {
                    D_80110104_267204_ChanceTime = 0;
                }
            } else {
                D_80110108_267208_ChanceTime->unk68 = 1.0f;
                D_80110108_267208_ChanceTime->unk6C = 1.0f;
            }
        }
        D_801100F0_2671F0_ChanceTime++;
        break;
    case 1:
        if (D_80110150_267250_ChanceTime[0] != 0 && D_80110150_267250_ChanceTime[1] != 0 &&
            D_80110150_267250_ChanceTime[2] != 0 && D_801100F8_2671F8_ChanceTime == 0) {
            if (work->unk_38 == 1000.0f && (work->unk_5C & 6) && D_801100F4_2671F4_ChanceTime == 0) {
                D_80110068_267168_ChanceTime = 1;
                func_8000C690_D290();
                work->unk_3C = work->unk_40 = 0.0f;
                D_801100F4_2671F4_ChanceTime = 1;
            }
            if (D_801100F4_2671F4_ChanceTime != 0) {
                D_80110062_267162_ChanceTime = 2;
                D_80110063_267163_ChanceTime = 2;
                D_801100F8_2671F8_ChanceTime = 1;
            }
        }
        break;
    case 2:
        func_8000C3A8_CFA8();
        break;
    case 3:
        func_8000C690_D290();
        if (D_801100FA_2671FA_ChanceTime == 0) {
            D_801100FA_2671FA_ChanceTime = 1;
        } else if (D_801100F9_2671F9_ChanceTime == 0) {
            InitFadeOut(D_80110060_267160_ChanceTime != 0 ? 3 : 5, 16);
            func_800794A8_7A0A8(40);
            D_801100F9_2671F9_ChanceTime = 1;
        } else if (func_8008F618_90218() == 0) {
            func_80069770_6A370();
            func_8008CE5C_8DA5C();
            func_800616C4_622C4();
            omOvlReturnEx(1);
        }
        break;
    }
}
#else
/* The title strings (rodata) the asm reads: "ＣＨＡＮＣＥ　ＴＩＭＥ♪" and "ＣＨＡＮＣＥ　ＴＩＭＥ" */
const u32 D_80110260_267360_ChanceTime[] = { 0x82628267, 0x8260826D, 0x82628264, 0x81408273, 0x8268826C, 0x826481F3, 0x00000000 };
const u32 D_8011027C_26737C_ChanceTime[] = { 0x82628267, 0x8260826D, 0x82628264, 0x81408273, 0x8268826C, 0x82640000, 0x00000000 };
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_80102E4C_259F4C_ChanceTime);
/* GCC thinks it is still in .rodata after the strings above; INCLUDE_ASM switched to .text. */
__asm__(".section .rodata");
#endif

/* The left block holder (second variant of the scene off): a model with a hook node holding a
   block (0x440008), ten random copies of the three scenery models around it. */
void func_80103398_25A498_ChanceTime(omObjData* obj) {
    CTPlayerWork* work;
    s32 i;
    CTMotion* motionSlot;
    s16 motion;
    s32 dir = 0x80000; /* file directory 8 */

    obj->model[0] = LoadFormFile(0x80000, 0x8A9);
    func_8002D1EC_2DDEC(obj->model[0], 1);
    func_8002D2B4_2DEB4(obj->model[0], 0.0f, -69.0f, 100.0f);
    func_8002D274_2DE74(obj->model[0], 0xFF, 0xFF, 0x20);
    obj->unk_50 = func_80027154_27D54(sizeof(CTPlayerWork), 31000);
    func_800B0EF0_B1AF0(obj->unk_50, 0, sizeof(CTPlayerWork));
    work = obj->unk_50;
    work->unk_E8 = func_80027154_27D54(obj->mtncnt * sizeof(CTMotion), 31000);
    work->unk_5A = obj->model[0];
    work->unk_5B = 0;
    func_80025384_25F84(obj->model[0], 0, 8, 0x80039);
    obj->model[1] = LoadFormFile(0xD, 0x8A9);
    obj->model[2] = LoadFormFile(0x440008, 0x8A9);
    func_800298A4_2A4A4(obj->model[2], 0x4000, 0x4000);
    func_8002C628_2D228(obj->model[2], obj->model[0], "item_hook");
    obj->model[3] = LoadFormFile(8, 0x2CD);
    for (i = 4; i < 14; i++) {
        switch ((rand8() * 3) >> 8) {
        case 0:
            obj->model[i] = func_80027D3C_2893C(D_80110914_267A14_ChanceTime);
            break;
        case 1:
            obj->model[i] = func_80027D3C_2893C(D_80110916_267A16_ChanceTime);
            break;
        default:
            obj->model[i] = func_80027D3C_2893C(D_80110918_267A18_ChanceTime);
            break;
        }
    }
    func_80018CCC_198CC(obj, 0, dir | 1);
    motionSlot = work->unk_E8;
    motionSlot->unk_04 = motion = func_80025684_26284(dir | 0x3A);
    func_80018CCC_198CC(obj, 1, dir | 2);
    work->unk_E8[1].unk_04 = motion;
    func_80018CCC_198CC(obj, 2, dir | 2);
    work->unk_E8[2].unk_04 = motion;
    func_80018CCC_198CC(obj, 3, dir | 0xF);
    work->unk_E8[3].unk_04 = motion;
    func_80029E80_2AA80(obj->model[0], 2, 2);
    obj->trans.x = -D_8011008C_26718C_ChanceTime[0].x;
    obj->trans.y = D_8011008C_26718C_ChanceTime[0].y;
    obj->trans.z = D_8011008C_26718C_ChanceTime[0].z;
    obj->rot.y = 0.0f;
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->rot.y, obj->trans.z);
    obj->scale.x = obj->scale.y = obj->scale.z = 0.9f;
    for (i = 4; i < 14; i++) {
        func_80029714_2A314(obj->model[i], obj->trans.x - 50.0f, obj->trans.y + 50.0f, obj->trans.z);
    }
    obj->func_ptr = func_801036C4_25A7C4_ChanceTime;
}

void func_801036C4_25A7C4_ChanceTime(omObjData* obj) {
    if (D_80110062_267162_ChanceTime == 1) {
        func_80103ADC_25ABDC_ChanceTime(obj, 1);
    }
    func_80029714_2A314(obj->model[1], obj->trans.x, 5.0f, obj->trans.z);
}


/* The right block holder: func_80103398 mirrored (scale.x -0.9). */
void func_80103714_25A814_ChanceTime(omObjData* obj) {
    CTPlayerWork* work;
    s32 i;
    CTMotion* motionSlot;
    s16 motion;
    s32 dir = 0x80000; /* file directory 8 */

    obj->model[0] = LoadFormFile(0x80000, 0x8A9);
    func_8002D1EC_2DDEC(obj->model[0], 1);
    func_8002D2B4_2DEB4(obj->model[0], 0.0f, -69.0f, 100.0f);
    func_8002D274_2DE74(obj->model[0], 0xFF, 0xFF, 0x20);
    obj->unk_50 = func_80027154_27D54(sizeof(CTPlayerWork), 31000);
    func_800B0EF0_B1AF0(obj->unk_50, 0, sizeof(CTPlayerWork));
    work = obj->unk_50;
    work->unk_E8 = func_80027154_27D54(obj->mtncnt * sizeof(CTMotion), 31000);
    work->unk_5A = obj->model[0];
    work->unk_5B = 0;
    func_80025384_25F84(obj->model[0], 0, 8, 0x8003A);
    obj->model[1] = LoadFormFile(0xD, 0x8A9);
    obj->model[2] = LoadFormFile(0x440008, 0x8B9);
    func_800298A4_2A4A4(obj->model[2], 0x4000, 0x4000);
    func_8002C628_2D228(obj->model[2], obj->model[0], "item_hook");
    obj->model[3] = LoadFormFile(8, 0x8AD);
    for (i = 4; i < 14; i++) {
        switch ((rand8() * 3) >> 8) {
        case 0:
            obj->model[i] = func_80027D3C_2893C(D_80110914_267A14_ChanceTime);
            break;
        case 1:
            obj->model[i] = func_80027D3C_2893C(D_80110916_267A16_ChanceTime);
            break;
        default:
            obj->model[i] = func_80027D3C_2893C(D_80110918_267A18_ChanceTime);
            break;
        }
    }
    func_80018CCC_198CC(obj, 0, dir | 1);
    motionSlot = work->unk_E8;
    motionSlot->unk_04 = motion = func_80025684_26284(dir | 0x3A);
    func_80018CCC_198CC(obj, 1, dir | 2);
    work->unk_E8[1].unk_04 = motion;
    func_80018CCC_198CC(obj, 2, dir | 2);
    work->unk_E8[2].unk_04 = motion;
    func_80018CCC_198CC(obj, 3, dir | 0xF);
    work->unk_E8[3].unk_04 = motion;
    func_80029E80_2AA80(obj->model[0], 2, 2);
    obj->scale.x = -0.9f;
    obj->scale.y = obj->scale.z = 0.9f;
    func_8002C3A0_2CFA0(obj->model[0]);
    func_80029A8C_2A68C(obj->model[0]);
    obj->trans.x = D_8011008C_26718C_ChanceTime[0].x;
    obj->trans.y = D_8011008C_26718C_ChanceTime[0].y;
    obj->trans.z = D_8011008C_26718C_ChanceTime[0].z;
    obj->rot.y = 0.0f;
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->rot.y, obj->trans.z);
    for (i = 4; i < 14; i++) {
        func_80029714_2A314(obj->model[i], obj->trans.x + 50.0f, obj->trans.y + 50.0f, obj->trans.z);
    }
    obj->func_ptr = func_80103A64_25AB64_ChanceTime;
}

void func_80103A64_25AB64_ChanceTime(omObjData* obj) {
    switch (D_80110062_267162_ChanceTime) {
    case 1:
        func_80103ADC_25ABDC_ChanceTime(obj, 0);
        break;
    case 2:
        func_801052B4_25C3B4_ChanceTime(obj);
        break;
    }
    func_80029714_2A314(obj->model[1], obj->trans.x, 5.0f, obj->trans.z);
}


/* The holders' opening: in the first variant (D_80110060 == 0) both block holders (side 0 =
   D_8011090C, side 1 = D_80110910; side 1 advances the shared state D_8011010C) walk in, turn,
   throw the block up while the ten scenery copies burst out and drift, then walk back; in the
   second variant the one holder (obj) plays its motions. */
void func_80103ADC_25ABDC_ChanceTime(omObjData* obj, s8 side) {
    Vec dirs[16] = {
        { 0.89443f, 0.44721f, 0.0f },  { 0.81923f, 0.57346f, 0.0f },  { 0.7071f, 0.7071f, 0.0f },
        { 0.57346f, 0.81923f, 0.0f },  { 0.44721f, 0.89443f, 0.0f },  { 0.89443f, 0.44721f, 1.0f },
        { 0.81923f, 0.57346f, 1.0f },  { 0.7071f, 0.7071f, 1.0f },    { 0.57346f, 0.81923f, 1.0f },
        { 0.44721f, 0.89443f, 1.0f },  { 0.89443f, 0.44721f, -1.0f }, { 0.81923f, 0.57346f, -1.0f },
        { 0.7071f, 0.7071f, -1.0f },   { 0.57346f, 0.81923f, -1.0f }, { 0.44721f, 0.89443f, -1.0f },
        { 0.89443f, 0.44721f, 0.5f },
    };
    omObjData* holder;
    f32 rot;
    s16 motion;
    s32 i;

    if (D_80110060_267160_ChanceTime != 0) {
        switch (D_8011010C_26720C_ChanceTime) {
        case 0:
            func_800298A4_2A4A4(obj->model[0], 4, 0);
            func_800298A4_2A4A4(obj->model[1], 4, 0);
            D_80110114_267214_ChanceTime = 0;
            obj->rot.y = 0.0f;
            D_8011010C_26720C_ChanceTime++;
            break;
        case 1:
            if (D_80110114_267214_ChanceTime >= 11) {
                D_80110114_267214_ChanceTime = 0;
                D_8011010C_26720C_ChanceTime++;
            } else {
                D_80110114_267214_ChanceTime++;
            }
            break;
        case 2:
            D_80110064_267164_ChanceTime = 1;
            D_8011010C_26720C_ChanceTime++;
            break;
        case 3:
            if (D_80110114_267214_ChanceTime >= 61) {
                func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[3]), 0, 30, 2);
                PlaySound(0x125);
                omAddPrcObj(func_8010B328_262428_ChanceTime, 0x3F00, 0x800, 0);
                D_80110114_267214_ChanceTime = 0;
                D_8011010C_26720C_ChanceTime++;
            } else {
                D_80110114_267214_ChanceTime++;
            }
            break;
        case 4:
            if (D_80110114_267214_ChanceTime >= 31) {
                func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[0]), 0, 30, 2);
                D_80110114_267214_ChanceTime = 0;
                D_8011010C_26720C_ChanceTime++;
            } else {
                D_80110114_267214_ChanceTime++;
            }
            break;
        case 5:
            if (D_801100BC_2671BC_ChanceTime == 1) {
                D_8011010C_26720C_ChanceTime++;
            }
            break;
        case 6:
            if (obj->rot.y < 90.0f) {
                obj->rot.y += 6.0f;
                if (obj->rot.y >= 90.0f) {
                    obj->rot.y = 90.0f;
                    D_8011010C_26720C_ChanceTime++;
                }
            }
            break;
        case 7:
            func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[1]), 0, 30, 2);
            D_80110114_267214_ChanceTime = 0;
            D_8011010C_26720C_ChanceTime++;
            break;
        case 8:
            if (D_80110114_267214_ChanceTime < 30) {
                D_80110114_267214_ChanceTime++;
                obj->trans.x -= (D_80110070_267170_ChanceTime.path[1].x - D_80110070_267170_ChanceTime.path[0].x) / 30.0f;
                obj->trans.y -= (D_80110070_267170_ChanceTime.path[1].y - D_80110070_267170_ChanceTime.path[0].y) / 30.0f;
                obj->trans.z -= (D_80110070_267170_ChanceTime.path[1].z - D_80110070_267170_ChanceTime.path[0].z) / 30.0f;
            } else {
                func_800298A4_2A4A4(obj->model[0], 4, 4);
                func_800298A4_2A4A4(obj->model[1], 4, 4);
                D_8011010C_26720C_ChanceTime++;
            }
            break;
        case 9:
            D_80110156_267256_ChanceTime = 1;
            D_80110114_267214_ChanceTime = 0;
            D_8011010C_26720C_ChanceTime++;
            break;
        case 10:
            if (D_80110114_267214_ChanceTime == 0) {
                D_8011011C_26721C_ChanceTime = (rand8() >> 6) * 3;
            }
            if (D_80110114_267214_ChanceTime >= D_8011011C_26721C_ChanceTime) {
                func_8000C3B8_CFB8();
                D_8011010C_26720C_ChanceTime = 0;
                D_80110114_267214_ChanceTime = 0;
                D_80110063_267163_ChanceTime = 0;
            }
            /* retail: the counter is stepped after the reset too (it restarts at 1) */
            D_80110114_267214_ChanceTime++;
            break;
        }
    } else {
        switch (D_8011010C_26720C_ChanceTime) {
        case 0:
            if (side == 0) {
                func_800298A4_2A4A4(HOLDER0->model[0], 4, 0);
                func_800298A4_2A4A4(HOLDER0->model[1], 4, 0);
                func_80029B80_2A780(HOLDER0->model[0], HOLDER0->motion[2]);
                func_80029E80_2AA80(HOLDER0->model[0], 2, 2);
                HOLDER0->rot.y = 90.0f;
            } else if (side == 1) {
                func_800298A4_2A4A4(HOLDER1->model[0], 4, 0);
                func_800298A4_2A4A4(HOLDER1->model[1], 4, 0);
                func_80029B80_2A780(HOLDER1->model[0], HOLDER0->motion[2]);
                func_80029E80_2AA80(HOLDER1->model[0], 2, 2);
                HOLDER1->rot.y = 270.0f;
            } else {
                break;
            }
            if (side == 1) {
                D_8011010C_26720C_ChanceTime++;
            }
            break;
        case 1:
            if (D_80110114_267214_ChanceTime < 32) {
                D_80110114_267214_ChanceTime++;
                if (side == 0) {
                    holder = HOLDER0;
                    holder->trans.x = (D_8011008C_26718C_ChanceTime[1].x - D_8011008C_26718C_ChanceTime[0].x) / 16.0f + holder->trans.x;
                    holder->trans.y = (D_8011008C_26718C_ChanceTime[1].y - D_8011008C_26718C_ChanceTime[0].y) / 16.0f + holder->trans.y;
                    holder->trans.z = (D_8011008C_26718C_ChanceTime[1].z - D_8011008C_26718C_ChanceTime[0].z) / 16.0f + holder->trans.z;
                } else if (side == 1) {
                    holder = HOLDER1;
                    holder->trans.x = (-D_8011008C_26718C_ChanceTime[1].x + D_8011008C_26718C_ChanceTime[0].x) / 16.0f + holder->trans.x;
                    holder->trans.y = (D_8011008C_26718C_ChanceTime[1].y - D_8011008C_26718C_ChanceTime[0].y) / 16.0f + holder->trans.y;
                    holder->trans.z = (D_8011008C_26718C_ChanceTime[1].z - D_8011008C_26718C_ChanceTime[0].z) / 16.0f + holder->trans.z;
                }
            } else if (side == 1) {
                D_8011010C_26720C_ChanceTime++;
                D_80110114_267214_ChanceTime = 0;
            }
            break;
        case 2:
            if (side == 0) {
                if (HOLDER0->rot.y > 14.0f) {
                    HOLDER0->rot.y -= 6.0f;
                } else {
                    HOLDER0->rot.y = 14.0f;
                    if (side == 1) {
                        D_8011010C_26720C_ChanceTime++;
                    }
                }
            } else {
                /* retail: side 1 also waits on side 0's angle */
                if (HOLDER0->rot.y > 14.0f) {
                    HOLDER1->rot.y += 6.0f;
                } else {
                    HOLDER1->rot.y = 346.0f;
                    if (side == 1) {
                        D_8011010C_26720C_ChanceTime++;
                    }
                }
            }
            break;
        case 3:
            if (side == 0) {
                func_80079848_7A448(D_801106B2_2677B2_ChanceTime);
                func_80029B80_2A780(HOLDER0->model[0], HOLDER0->motion[0]);
                func_80029E80_2AA80(HOLDER0->model[0], 2, 2);
                HOLDER0->rot.y = 14.0f;
            } else {
                func_80029B80_2A780(HOLDER1->model[0], HOLDER0->motion[0]);
                func_80029E80_2AA80(HOLDER1->model[0], 2, 2);
                HOLDER1->rot.y = 346.0f;
            }
            if (side == 1) {
                D_8011010C_26720C_ChanceTime++;
            }
            break;
        case 4:
            if (D_80110114_267214_ChanceTime >= 201) {
                D_80110114_267214_ChanceTime = 0;
                motion = func_80025684_26284(0x8003A);
                func_80025554_26154(HOLDER0->model[0], 0, 8, motion);
                func_80025554_26154(HOLDER1->model[0], 0, 8, motion);
                for (i = 4; i < 14; i++) {
                    func_800298A4_2A4A4(HOLDER0->model[i], 4, 4);
                    func_800298A4_2A4A4(HOLDER1->model[i], 4, 4);
                }
                if (side == 1) {
                    D_8011010C_26720C_ChanceTime++;
                }
                break;
            }
            if (D_80110114_267214_ChanceTime == 0) {
                func_80029B80_2A780(HOLDER0->model[0], HOLDER0->motion[3]);
                func_80029B80_2A780(HOLDER1->model[0], HOLDER0->motion[3]);
                for (i = 4; i < 14; i++) {
                    D_801106C0_2677C0_ChanceTime[i - 4].x = HOLDER0->trans.x + 50.0f;
                    D_801106C0_2677C0_ChanceTime[i - 4].y = 50.0f;
                    D_801106C0_2677C0_ChanceTime[i - 4].z = HOLDER0->trans.z;
                    D_80110738_267838_ChanceTime[i - 4].x = D_80110738_267838_ChanceTime[i - 4].z = 0.0f;
                    D_80110738_267838_ChanceTime[i - 4].y = (rand8() * 45) >> 6;
                }
                D_801106B8_2677B8_ChanceTime = 0.0f;
            } else if (D_80110114_267214_ChanceTime == 15) {
                PlaySound(0x2DD);
            } else if (D_80110114_267214_ChanceTime == func_80029D0C_2A90C(HOLDER0->model[0])) {
                func_80029B80_2A780(HOLDER0->model[0], HOLDER0->motion[0]);
                func_80029E80_2AA80(HOLDER0->model[0], 2, 2);
                func_80029B80_2A780(HOLDER1->model[0], HOLDER0->motion[0]);
                func_80029E80_2AA80(HOLDER1->model[0], 2, 2);
            } else if (D_80110114_267214_ChanceTime == 28) {
                func_800191D4_19DD4(HOLDER0, 3, HOLDER0->trans.x + 50.0f, HOLDER0->trans.y + 50.0f, HOLDER0->trans.z, 0.0f, 0.0f);
                func_800191D4_19DD4(HOLDER1, 3, HOLDER1->trans.x - 50.0f, HOLDER1->trans.y + 50.0f, HOLDER1->trans.z, 0.0f, 0.0f);
                for (i = 4; i < 14; i++) {
                    func_800298A4_2A4A4(HOLDER0->model[i], 4, 0);
                    func_800298A4_2A4A4(HOLDER1->model[i], 4, 0);
                    func_800297E8_2A3E8(HOLDER0->model[i], 2.0f, 2.0f, 2.0f);
                    func_800297E8_2A3E8(HOLDER1->model[i], 2.0f, 2.0f, 2.0f);
                }
            } else if (D_80110114_267214_ChanceTime >= 29 && D_80110114_267214_ChanceTime < 58) {
                if (D_80110114_267214_ChanceTime == 32) {
                    D_80110064_267164_ChanceTime = 1;
                }
                for (i = 4; i < 14; i++) {
                    if (D_80110114_267214_ChanceTime < 46) {
                        D_801106C0_2677C0_ChanceTime[i - 4].x += dirs[i - 4].x * ((s32)((u32)(rand8() * 5) >> 7) + 8.0f);
                        D_801106C0_2677C0_ChanceTime[i - 4].y += dirs[i - 4].y * ((s32)((u32)(rand8() * 5) >> 5) + 1.0f);
                        D_801106C0_2677C0_ChanceTime[i - 4].z += dirs[i - 4].z * ((s32)((u32)(rand8() * 5) >> 7) + 8.0f);
                    } else {
                        D_801106C0_2677C0_ChanceTime[i - 4].x += dirs[i - 4].x * ((s32)((u32)(rand8() * 5) >> 6) + 4.0f);
                        D_801106C0_2677C0_ChanceTime[i - 4].y += dirs[i - 4].y * (((rand8() * 5) >> 8) + 4.0f);
                        D_801106C0_2677C0_ChanceTime[i - 4].z += dirs[i - 4].z * (((rand8() * 5) >> 8) + 4.0f);
                    }
                    func_8002979C_2A39C(HOLDER0->model[i], D_80110738_267838_ChanceTime[i - 4].x, D_80110738_267838_ChanceTime[i - 4].y += 15.0f, D_80110738_267838_ChanceTime[i - 4].z);
                    func_80029714_2A314(HOLDER0->model[i], D_801106C0_2677C0_ChanceTime[i - 4].x, D_801106C0_2677C0_ChanceTime[i - 4].y, D_801106C0_2677C0_ChanceTime[i - 4].z);
                    func_8002979C_2A39C(HOLDER1->model[i], D_80110738_267838_ChanceTime[i - 4].x, D_80110738_267838_ChanceTime[i - 4].y += 15.0f, D_80110738_267838_ChanceTime[i - 4].z);
                    func_80029714_2A314(HOLDER1->model[i], -D_801106C0_2677C0_ChanceTime[i - 4].x, D_801106C0_2677C0_ChanceTime[i - 4].y, D_801106C0_2677C0_ChanceTime[i - 4].z);
                }
            } else if (D_80110114_267214_ChanceTime >= 58) {
                if ((D_80110114_267214_ChanceTime >= 118) & (side == 1)) {
                    switch (D_80110110_267210_ChanceTime) {
                    case 0:
                        if (HOLDER1->rot.y < 90.0f) {
                            rot = HOLDER1->rot.y + 6.0f;
                            HOLDER1->rot.y = rot;
                            /* retail: > 0, so this keeps wrapping and never reaches 90 from 346 */
                            if (rot > 0.0f) {
                                HOLDER1->rot.y = rot - 360.0f;
                            }
                        } else {
                            HOLDER1->rot.y = 90.0f;
                            D_80110110_267210_ChanceTime++;
                        }
                        break;
                    case 1:
                        func_80029B80_2A780(HOLDER1->model[0], HOLDER0->motion[2]);
                        func_80029E80_2AA80(HOLDER1->model[0], 2, 2);
                        HOLDER1->rot.y = 90.0f;
                        D_80110110_267210_ChanceTime++;
                        break;
                    case 2:
                        if (D_80110118_267218_ChanceTime < 32) {
                            D_80110118_267218_ChanceTime++;
                            HOLDER1->trans.x -= (-D_8011008C_26718C_ChanceTime[1].x + D_8011008C_26718C_ChanceTime[0].x) / 16.0f;
                            HOLDER1->trans.y -= (D_8011008C_26718C_ChanceTime[1].y - D_8011008C_26718C_ChanceTime[0].y) / 16.0f;
                            HOLDER1->trans.z -= (D_8011008C_26718C_ChanceTime[1].z - D_8011008C_26718C_ChanceTime[0].z) / 16.0f;
                        } else {
                            func_80079848_7A448(D_801106B2_2677B2_ChanceTime);
                            func_800298A4_2A4A4(HOLDER1->model[0], 4, 4);
                            func_800298A4_2A4A4(HOLDER1->model[1], 4, 4);
                            func_800298A4_2A4A4(HOLDER1->model[2], 4, 4);
                            func_800298A4_2A4A4(HOLDER1->model[2], 0x4000, 0);
                            D_80110118_267218_ChanceTime = 0;
                            D_80110110_267210_ChanceTime++;
                        }
                        break;
                    }
                }
                for (i = 4; i < 14; i++) {
                    if (!(i & 1)) {
                        D_801106C0_2677C0_ChanceTime[i - 4].x += HuMathSin(D_801106B4_2677B4_ChanceTime) * (5.0f - D_801106B8_2677B8_ChanceTime);
                    } else {
                        D_801106C0_2677C0_ChanceTime[i - 4].x -= HuMathSin(D_801106B4_2677B4_ChanceTime) * (5.0f - D_801106B8_2677B8_ChanceTime);
                    }
                    D_801106C0_2677C0_ChanceTime[i - 4].y -= 3.0f;
                    if (rand8() >> 7) {
                        func_8002979C_2A39C(HOLDER0->model[i], D_80110738_267838_ChanceTime[i - 4].x, D_80110738_267838_ChanceTime[i - 4].y += 15.0f, 0.0f);
                        func_8002979C_2A39C(HOLDER1->model[i], D_80110738_267838_ChanceTime[i - 4].x, D_80110738_267838_ChanceTime[i - 4].y += 15.0f, 0.0f);
                    } else {
                        func_8002979C_2A39C(HOLDER0->model[i], D_80110738_267838_ChanceTime[i - 4].x -= 10.0f, D_80110738_267838_ChanceTime[i - 4].y += 15.0f, 0.0f);
                        func_8002979C_2A39C(HOLDER1->model[i], D_80110738_267838_ChanceTime[i - 4].x -= 10.0f, D_80110738_267838_ChanceTime[i - 4].y += 15.0f, 0.0f);
                    }
                    func_80029714_2A314(HOLDER0->model[i], D_801106C0_2677C0_ChanceTime[i - 4].x, D_801106C0_2677C0_ChanceTime[i - 4].y, D_801106C0_2677C0_ChanceTime[i - 4].z);
                    func_80029714_2A314(HOLDER1->model[i], -D_801106C0_2677C0_ChanceTime[i - 4].x, D_801106C0_2677C0_ChanceTime[i - 4].y, D_801106C0_2677C0_ChanceTime[i - 4].z);
                }
                D_801106B4_2677B4_ChanceTime += 5.0f;
                D_801106B8_2677B8_ChanceTime += 0.05f;
            }
            if ((D_80110114_267214_ChanceTime == 180) & (side == 0)) {
                omAddPrcObj(func_8010B28C_26238C_ChanceTime, 0x3F00, 0x800, 0);
            }
            D_80110114_267214_ChanceTime++;
            break;
        case 5:
            if (side == 0 && D_801100BC_2671BC_ChanceTime == 1) {
                D_80110114_267214_ChanceTime = 0;
                D_8011010C_26720C_ChanceTime++;
            }
            break;
        case 6:
            if (side == 0) {
                if (HOLDER0->rot.y < 270.0f) {
                    rot = HOLDER0->rot.y - 6.0f;
                    HOLDER0->rot.y = rot;
                    if (rot < 0.0f) {
                        HOLDER0->rot.y = rot + 360.0f;
                    }
                } else {
                    HOLDER0->rot.y = 270.0f;
                    D_8011010C_26720C_ChanceTime++;
                }
            }
            break;
        case 7:
            if (side == 0) {
                func_80029B80_2A780(HOLDER0->model[0], HOLDER0->motion[2]);
                func_80029E80_2AA80(HOLDER0->model[0], 2, 2);
                HOLDER0->rot.y = 270.0f;
                D_8011010C_26720C_ChanceTime++;
            }
            break;
        case 8:
            if (side == 0) {
                if (D_80110114_267214_ChanceTime < 16) {
                    D_80110114_267214_ChanceTime++;
                    HOLDER0->trans.x -= (D_8011008C_26718C_ChanceTime[1].x - D_8011008C_26718C_ChanceTime[0].x) / 16.0f;
                    HOLDER0->trans.y -= (D_8011008C_26718C_ChanceTime[1].y - D_8011008C_26718C_ChanceTime[0].y) / 16.0f;
                    HOLDER0->trans.z -= (D_8011008C_26718C_ChanceTime[1].z - D_8011008C_26718C_ChanceTime[0].z) / 16.0f;
                } else {
                    func_80079848_7A448(D_801106B2_2677B2_ChanceTime);
                    func_800298A4_2A4A4(HOLDER0->model[0], 4, 4);
                    func_800298A4_2A4A4(HOLDER0->model[1], 4, 4);
                    func_800298A4_2A4A4(HOLDER0->model[2], 4, 4);
                    func_800298A4_2A4A4(HOLDER0->model[2], 0x4000, 0);
                    D_8011010C_26720C_ChanceTime++;
                }
            }
            break;
        case 9:
            if (side == 0) {
                D_80110062_267162_ChanceTime = 0;
                D_8011010C_26720C_ChanceTime = 0;
                D_80110114_267214_ChanceTime = 0;
                D_80110156_267256_ChanceTime = 1;
                func_8000C3B8_CFB8();
            }
            break;
        }
    }
}


/* The block holder after the three blocks stopped (state D_80110120): in the first variant it
   turns, starts the swap/exchange processes and, when the two chosen players
   (D_80110180/D_80110181) are not the first in the order, walks the two player objects
   (D_80110D62[0..1]) to their places by driving their CPU sticks; in the second variant it
   plays its motions and starts the result processes. */
void func_801052B4_25C3B4_ChanceTime(omObjData* obj) {
    CTPlayerWork* work;
    f32 dx;
    f32 dz;
    f32 angle;
    f32 rot;

    switch (D_80110120_267220_ChanceTime) {
    case 0:
        func_800298A4_2A4A4(obj->model[0], 4, 0);
        func_800298A4_2A4A4(obj->model[1], 4, 0);
        if (D_80110060_267160_ChanceTime != 0) {
            func_80029B80_2A780(obj->model[0], obj->motion[1]);
            obj->rot.y = -90.0f;
            if (D_80110180_267280_ChanceTime == 0) {
                func_80061720_62320(0, 1);
            } else {
                func_80061720_62320(D_80110180_267280_ChanceTime, 0);
            }
            func_80061584_62184();
            omAddPrcObj(func_8010FF1C_26701C_ChanceTime, 0x3F00, 0x800, 0);
        } else {
            func_80029B80_2A780(obj->model[0], obj->motion[2]);
            obj->rot.y = 90.0f;
            omAddPrcObj(func_8010FC18_266D18_ChanceTime, 0x3F00, 0x800, 0);
        }
        func_80029E80_2AA80(obj->model[0], 2, 2);
        D_80110124_267224_ChanceTime = 0;
        D_80110120_267220_ChanceTime++;
        break;
    case 1:
        if (D_80110060_267160_ChanceTime != 0) {
            if (D_80110124_267224_ChanceTime >= 31) {
                D_80110124_267224_ChanceTime = 0;
                D_80110120_267220_ChanceTime++;
            }
            D_80110124_267224_ChanceTime++;
        } else if (D_80110124_267224_ChanceTime < 16) {
            D_80110124_267224_ChanceTime++;
            obj->trans.x = (D_8011008C_26718C_ChanceTime[1].x - D_8011008C_26718C_ChanceTime[0].x) / 16.0f + obj->trans.x;
            obj->trans.y = (D_8011008C_26718C_ChanceTime[1].y - D_8011008C_26718C_ChanceTime[0].y) / 16.0f + obj->trans.y;
            obj->trans.z = (D_8011008C_26718C_ChanceTime[1].z - D_8011008C_26718C_ChanceTime[0].z) / 16.0f + obj->trans.z;
        } else {
            D_80110120_267220_ChanceTime++;
        }
        break;
    case 2:
        if (D_80110060_267160_ChanceTime != 0) {
            if (D_80110124_267224_ChanceTime < 30) {
                D_80110124_267224_ChanceTime++;
                obj->trans.x = (D_80110070_267170_ChanceTime.path[1].x - D_80110070_267170_ChanceTime.path[0].x) / 30.0f + obj->trans.x;
                obj->trans.y = (D_80110070_267170_ChanceTime.path[1].y - D_80110070_267170_ChanceTime.path[0].y) / 30.0f + obj->trans.y;
                obj->trans.z = (D_80110070_267170_ChanceTime.path[1].z - D_80110070_267170_ChanceTime.path[0].z) / 30.0f + obj->trans.z;
            } else {
                D_80110120_267220_ChanceTime++;
            }
        } else if (obj->rot.y > 14.0f) {
            obj->rot.y -= 6.0f;
        } else {
            obj->rot.y = 14.0f;
            D_80110120_267220_ChanceTime++;
        }
        break;
    case 3:
        if (D_80110060_267160_ChanceTime != 0) {
            if (obj->rot.y < 0.0f) {
                obj->rot.y += 6.0f;
                if (obj->rot.y >= 0.0f) {
                    obj->rot.y = 0.0f;
                    D_80110120_267220_ChanceTime++;
                }
            }
        } else {
            func_80079848_7A448(D_801107B0_2678B0_ChanceTime);
            func_80029B80_2A780(obj->model[0], obj->motion[0]);
            func_80029E80_2AA80(obj->model[0], 2, 2);
            obj->rot.y = 14.0f;
            D_80110120_267220_ChanceTime++;
        }
        break;
    case 4:
        if (D_80110060_267160_ChanceTime != 0) {
            func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[0]), 0, 30, 2);
            func_80061734_62334();
        } else {
            omAddPrcObj(func_8010B7F8_2628F8_ChanceTime, 0x3F00, 0x800, 0);
        }
        D_80110120_267220_ChanceTime++;
        break;
    case 5:
        if (D_80110060_267160_ChanceTime != 0) {
            omAddPrcObj(func_8010BB74_262C74_ChanceTime, 0x3F00, 0x800, 0);
            PlaySound(0x123);
            D_80110120_267220_ChanceTime++;
        } else if (D_801100BC_2671BC_ChanceTime == 1) {
            D_80110120_267220_ChanceTime++;
            D_80110124_267224_ChanceTime = 0;
        }
        break;
    case 6:
        if (D_80110060_267160_ChanceTime != 0) {
            if (D_801100BC_2671BC_ChanceTime == 1) {
                D_80110120_267220_ChanceTime++;
                D_80110124_267224_ChanceTime = 0;
            }
        } else {
            if (D_80110180_267280_ChanceTime != D_80110D6A_267E6A_ChanceTime[0] &&
                D_80110181_267281_ChanceTime != D_80110D6A_267E6A_ChanceTime[0]) {
                omAddPrcObj(func_8010FD28_266E28_ChanceTime, 0x3F00, 0x800, 0);
            }
            D_80110120_267220_ChanceTime++;
        }
        break;
    case 7:
        if (D_80110060_267160_ChanceTime != 0) {
            PlaySound(0x122);
            func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[3]), 0, 30, 2);
            D_80110124_267224_ChanceTime = 0;
            D_80110120_267220_ChanceTime++;
        } else if (obj->rot.y < 270.0f) {
            rot = obj->rot.y - 6.0f;
            obj->rot.y = rot;
            if (rot < 0.0f) {
                obj->rot.y = rot + 360.0f;
            }
        } else {
            obj->rot.y = 270.0f;
            D_80110120_267220_ChanceTime++;
        }
        break;
    case 8:
        if (D_80110060_267160_ChanceTime != 0) {
            if (++D_80110124_267224_ChanceTime >= 31) {
                D_80110120_267220_ChanceTime++;
            }
        } else {
            func_80029B80_2A780(obj->model[0], obj->motion[2]);
            func_80029E80_2AA80(obj->model[0], 2, 2);
            obj->rot.y = 270.0f;
            D_80110124_267224_ChanceTime = 0;
            D_80110120_267220_ChanceTime++;
        }
        break;
    case 9:
        if (D_80110060_267160_ChanceTime != 0) {
            D_80110063_267163_ChanceTime = 0;
            D_80110120_267220_ChanceTime = 0;
            D_80110124_267224_ChanceTime = 0;
            func_8000C398_CF98();
        } else if (D_80110124_267224_ChanceTime < 16) {
            D_80110124_267224_ChanceTime++;
            obj->trans.x -= (D_8011008C_26718C_ChanceTime[1].x - D_8011008C_26718C_ChanceTime[0].x) / 16.0f;
            obj->trans.y -= (D_8011008C_26718C_ChanceTime[1].y - D_8011008C_26718C_ChanceTime[0].y) / 16.0f;
            obj->trans.z -= (D_8011008C_26718C_ChanceTime[1].z - D_8011008C_26718C_ChanceTime[0].z) / 16.0f;
        } else {
            func_80079848_7A448(D_801107B0_2678B0_ChanceTime);
            func_800298A4_2A4A4(obj->model[0], 4, 4);
            func_800298A4_2A4A4(obj->model[1], 4, 4);
            if (D_80110180_267280_ChanceTime != D_80110D6A_267E6A_ChanceTime[0] &&
                D_80110181_267281_ChanceTime != D_80110D6A_267E6A_ChanceTime[0]) {
                D_80110124_267224_ChanceTime = 0;
            } else {
                D_80110124_267224_ChanceTime = 30;
            }
            D_80110120_267220_ChanceTime++;
        }
        break;
    case 10:
        if (D_80110060_267160_ChanceTime == 0) {
            if (++D_80110124_267224_ChanceTime >= 21) {
                if (D_80110D62_267E62_ChanceTime[0] != 0) {
                    func_8010FE50_266F50_ChanceTime(D_80110D62_267E62_ChanceTime[0]);
                }
                D_80110120_267220_ChanceTime++;
            }
        }
        break;
    case 11:
        D_80110120_267220_ChanceTime++;
        break;
    case 12:
        if (D_80110060_267160_ChanceTime == 0) {
            if (D_80110D62_267E62_ChanceTime[1] != 0) {
                func_8010FE50_266F50_ChanceTime(D_80110D62_267E62_ChanceTime[1]);
            }
            D_80110124_267224_ChanceTime = 0;
            D_80110120_267220_ChanceTime++;
        }
        break;
    case 13:
        if (D_80110060_267160_ChanceTime == 0) {
            if (++D_80110124_267224_ChanceTime > 0) {
                func_80061720_62320(D_80110180_267280_ChanceTime, D_80110181_267281_ChanceTime);
                func_80061584_62184();
                if (D_80110D62_267E62_ChanceTime[0] != 0) {
                    D_800FFFD8_100BD8[D_80110D62_267E62_ChanceTime[0]]->trans.x = D_801100A4_2671A4_ChanceTime.x;
                    D_800FFFD8_100BD8[D_80110D62_267E62_ChanceTime[0]]->trans.y = D_801100A4_2671A4_ChanceTime.y;
                    D_800FFFD8_100BD8[D_80110D62_267E62_ChanceTime[0]]->trans.z = D_801100A4_2671A4_ChanceTime.z;
                    func_8000C024_CC24(D_800FFFD8_100BD8[D_80110D62_267E62_ChanceTime[0]], 0, 2);
                    func_8000C024_CC24(D_800FFFD8_100BD8[D_80110D62_267E62_ChanceTime[0]], 1, 1);
                    func_800298A4_2A4A4(D_800FFFD8_100BD8[D_80110D62_267E62_ChanceTime[0]]->model[0], 4, 0);
                }
                if (D_80110D62_267E62_ChanceTime[1] != 0) {
                    D_800FFFD8_100BD8[D_80110D62_267E62_ChanceTime[1]]->trans.x = -D_801100A4_2671A4_ChanceTime.x;
                    D_800FFFD8_100BD8[D_80110D62_267E62_ChanceTime[1]]->trans.y = D_801100A4_2671A4_ChanceTime.y;
                    D_800FFFD8_100BD8[D_80110D62_267E62_ChanceTime[1]]->trans.z = D_801100A4_2671A4_ChanceTime.z;
                    func_8000C024_CC24(D_800FFFD8_100BD8[D_80110D62_267E62_ChanceTime[1]], 0, 2);
                    func_8000C024_CC24(D_800FFFD8_100BD8[D_80110D62_267E62_ChanceTime[1]], 1, 1);
                    func_800298A4_2A4A4(D_800FFFD8_100BD8[D_80110D62_267E62_ChanceTime[1]]->model[0], 4, 0);
                }
                D_80110120_267220_ChanceTime++;
            }
        }
        break;
    case 14:
        if (D_80110060_267160_ChanceTime == 0) {
            /* block-scope player: retail's register choice */
            {
                omObjData* player = D_800FFFD8_100BD8[D_80110D62_267E62_ChanceTime[0]];
                work = CT_PWORK(player);
                dx = D_801100B0_2671B0_ChanceTime.x - player->trans.x;
                dz = D_801100B0_2671B0_ChanceTime.z - player->trans.z;
            }
            if (dx * dx + dz * dz > 400.0f) {
                angle = func_800B75A8_B81A8(dz, dx);
                D_80110D56_267E56_ChanceTime[work->unk_57] = func_800B7890_B8490(angle) * 60.0f;
                D_80110D6E_267E6E_ChanceTime[work->unk_57] = -HuMathSin(angle) * 60.0f;
                D_80110D72_267E72_ChanceTime[work->unk_57] = 0;
                D_80110B14_267C14_ChanceTime[work->unk_57] = 0;
            } else {
                D_80110D56_267E56_ChanceTime[work->unk_57] = 0;
                D_80110D6E_267E6E_ChanceTime[work->unk_57] = 0;
                D_80110D72_267E72_ChanceTime[work->unk_57] = 0;
                D_80110B14_267C14_ChanceTime[work->unk_57] = 0;
                work->unk_40 = 0.0f;
                work->unk_3C = 30.0f;
                if (D_80110128_267228_ChanceTime == 0) {
                    func_80061734_62334();
                    D_80110128_267228_ChanceTime = 1;
                }
            }
            /* block-scope player: retail's register choice */
            {
                omObjData* player = D_800FFFD8_100BD8[D_80110D62_267E62_ChanceTime[1]];
                work = CT_PWORK(player);
                dx = -D_801100B0_2671B0_ChanceTime.x - player->trans.x;
                dz = D_801100B0_2671B0_ChanceTime.z - player->trans.z;
            }
            if (dx * dx + dz * dz > 400.0f) {
                angle = func_800B75A8_B81A8(dz, dx);
                D_80110D56_267E56_ChanceTime[work->unk_57] = func_800B7890_B8490(angle) * 60.0f;
                D_80110D6E_267E6E_ChanceTime[work->unk_57] = -HuMathSin(angle) * 60.0f;
                D_80110D72_267E72_ChanceTime[work->unk_57] = 0;
                D_80110B14_267C14_ChanceTime[work->unk_57] = 0;
            } else {
                D_80110D56_267E56_ChanceTime[work->unk_57] = 0;
                D_80110D6E_267E6E_ChanceTime[work->unk_57] = 0;
                D_80110D72_267E72_ChanceTime[work->unk_57] = 0;
                D_80110B14_267C14_ChanceTime[work->unk_57] = 0;
                work->unk_40 = 0.0f;
                work->unk_3C = 330.0f;
                if (D_80110129_267229_ChanceTime == 0) {
                    func_80061750_62350();
                    D_80110129_267229_ChanceTime = 1;
                }
            }
            if (D_80110128_267228_ChanceTime == 1 && D_80110129_267229_ChanceTime == D_80110128_267228_ChanceTime) {
                D_80110124_267224_ChanceTime = 0;
                D_80110120_267220_ChanceTime++;
            }
        }
        break;
    case 15:
        if (D_80110060_267160_ChanceTime == 0) {
            work = CT_PWORK(D_800FFFD8_100BD8[D_80110D62_267E62_ChanceTime[0]]);
            D_80110D56_267E56_ChanceTime[work->unk_57] = 0;
            D_80110D6E_267E6E_ChanceTime[work->unk_57] = 0;
            D_80110D72_267E72_ChanceTime[work->unk_57] = 0;
            D_80110B14_267C14_ChanceTime[work->unk_57] = 0;
            work->unk_3C = 30.0f;
            work->unk_40 = 0.0f;
            work = CT_PWORK(D_800FFFD8_100BD8[D_80110D62_267E62_ChanceTime[1]]);
            D_80110D56_267E56_ChanceTime[work->unk_57] = 0;
            D_80110D6E_267E6E_ChanceTime[work->unk_57] = 0;
            D_80110D72_267E72_ChanceTime[work->unk_57] = 0;
            D_80110B14_267C14_ChanceTime[work->unk_57] = 0;
            work->unk_3C = 330.0f;
            work->unk_40 = 0.0f;
            if (D_80110124_267224_ChanceTime++ >= 21) {
                D_80110124_267224_ChanceTime = 0;
                D_80110120_267220_ChanceTime++;
            }
        }
        break;
    case 16:
        if (D_80110060_267160_ChanceTime == 0) {
            D_80110065_267165_ChanceTime = 1;
            D_80110120_267220_ChanceTime++;
        }
        break;
    case 17:
        if (D_80110060_267160_ChanceTime == 0 && D_80110066_267166_ChanceTime == 1) {
            D_80110120_267220_ChanceTime++;
        }
        break;
    case 18:
        if (D_80110060_267160_ChanceTime == 0) {
            D_80110062_267162_ChanceTime = 0;
            D_80110120_267220_ChanceTime = 0;
            D_80110124_267224_ChanceTime = 0;
            func_8000C398_CF98();
        }
        break;
    }
}

/* "%d" (also read by the asm of 8010B7F8 and 8010BB74) */
const char D_80110414_267514_ChanceTime[] = "%d";

/* Process: the outcome window. Message 0x46/0x3C with the two players' names, what moves
   (D_80110067: 0 nothing, 1 stars, else stars and coins?) and the amount for outcome
   D_80110182; it stays open (D_80110066 = 1) until the process is killed. */
void func_801060E0_25D1E0_ChanceTime(void) {
    s16 win;

    win = func_80057480_58080(0x46, 0x3C, 0x10, 4);
    ShowTextWindow(win);
    if (D_80110850_267950_ChanceTime == 0) {
        sprintf(D_801107C8_2678C8_ChanceTime, D_801100C8_2671C8_ChanceTime[gPlayers[D_80110180_267280_ChanceTime].character]);
        sprintf(D_801107D8_2678D8_ChanceTime, D_801100C8_2671C8_ChanceTime[gPlayers[D_80110181_267281_ChanceTime].character]);
    } else {
        sprintf(D_801107C8_2678C8_ChanceTime, D_801100C8_2671C8_ChanceTime[gPlayers[D_80110181_267281_ChanceTime].character]);
        sprintf(D_801107D8_2678D8_ChanceTime, D_801100C8_2671C8_ChanceTime[gPlayers[D_80110180_267280_ChanceTime].character]);
    }
    if (D_80110067_267167_ChanceTime == 0) {
        func_8008D4DC_8E0DC(D_801107B8_2678B8_ChanceTime, D_80110224_267324_ChanceTime);
    } else if (D_80110067_267167_ChanceTime == 1) {
        func_8008D4DC_8E0DC(D_801107B8_2678B8_ChanceTime, D_80110228_267328_ChanceTime);
    } else {
        func_8008D4DC_8E0DC(D_801107B8_2678B8_ChanceTime, D_80110214_267314_ChanceTime);
    }
    func_80089308_89F08(win, D_801107C8_2678C8_ChanceTime, 0);
    func_80089308_89F08(win, D_801107D8_2678D8_ChanceTime, 1);
    switch (D_80110182_267282_ChanceTime) {
    case 0:
    case 1:
        sprintf(D_801107B8_2678B8_ChanceTime, D_80110414_267514_ChanceTime, 3);
        break;
    case 2:
    case 3:
        sprintf(D_801107B8_2678B8_ChanceTime, D_80110414_267514_ChanceTime, 20);
        break;
    case 4:
    case 5:
        sprintf(D_801107B8_2678B8_ChanceTime, D_80110414_267514_ChanceTime, 30);
        break;
    case 11:
        sprintf(D_801107B8_2678B8_ChanceTime, D_80110414_267514_ChanceTime, 10);
        break;
    case 12:
        sprintf(D_801107B8_2678B8_ChanceTime, D_80110414_267514_ChanceTime, 40);
        break;
    }
    func_80089308_89F08(win, D_801107B8_2678B8_ChanceTime, 2);
    switch (D_80110182_267282_ChanceTime) {
    case 8:
        func_800890CC_89CCC(win, 14, -1, -1);
        break;
    case 9:
        func_800890CC_89CCC(win, 16, -1, -1);
        break;
    case 6:
    case 7:
        func_800890CC_89CCC(win, 12, -1, -1);
        break;
    case 10:
        func_800890CC_89CCC(win, 18, -1, -1);
        break;
    case 0:
    case 1:
        func_800890CC_89CCC(win, 8, -1, -1);
        break;
    default:
        func_800890CC_89CCC(win, 10, -1, -1);
        break;
    }
    func_80089A48_8A648(win, 0);
    func_80057730_58330(win, D_80110D6A_267E6A_ChanceTime[0]);
    func_8005762C_5822C(win);
    D_80110066_267166_ChanceTime = 1;
    while (TRUE) {
        HuPrcVSleep();
    }
}


INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_80106434_25D534_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_80106548_25D648_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_80106604_25D704_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_80106B5C_25DC5C_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_80107594_25E694_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_801077D8_25E8D8_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_80107B00_25EC00_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_80109718_260818_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_801097F8_2608F8_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010985C_26095C_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_80109CC4_260DC4_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_80109D84_260E84_ChanceTime);

void func_8010B02C_26212C_ChanceTime(omObjData* obj) {
    obj->model[0] = LoadFormFile(0xA0067, 0x6A9);
    func_8002D1EC_2DDEC(obj->model[0], 1);
    func_8002D2B4_2DEB4(obj->model[0], 0.0f, -69.0f, 100.0f);
    func_8002D274_2DE74(obj->model[0], 0x20, 0xFF, 0xFF);
    obj->model[1] = func_80018A64_19664(0xD, 0x2B9);
    func_800297E8_2A3E8(obj->model[1], 2.6999998f, 1.0f, 2.6999998f);
    func_80018CCC_198CC(obj, 0, 0xA0067);
    func_80018CCC_198CC(obj, 2, 0xA0068);
    func_80018CCC_198CC(obj, 3, 0xA0069);
    func_80018CCC_198CC(obj, 4, 0xA006A);
    func_80018CCC_198CC(obj, 5, 0xA006B);
    func_80018CCC_198CC(obj, 6, 0xA006C);
    func_80018CCC_198CC(obj, 1, 0xA006D);
    func_80018CCC_198CC(obj, 7, 0xA006E);
    func_80029E80_2AA80(obj->model[0], 2, 2);
    func_800298A4_2A4A4(obj->model[0], 4, 4);
    func_800298A4_2A4A4(obj->model[1], 4, 4);
    obj->trans.x = D_80110070_267170_ChanceTime.path[1].x;
    obj->trans.y = D_80110070_267170_ChanceTime.path[1].y;
    obj->trans.z = D_80110070_267170_ChanceTime.path[1].z;
    obj->rot.y = 0.0f;
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->rot.y, obj->trans.z);
    obj->scale.x = obj->scale.y = obj->scale.z = 1.3499999f;
    obj->func_ptr = func_8010B214_262314_ChanceTime;
}
void func_8010B214_262314_ChanceTime(omObjData* obj) {
    switch (D_80110063_267163_ChanceTime) {
    case 1:
        func_80103ADC_25ABDC_ChanceTime(obj, -1);
        break;
    case 2:
        func_801052B4_25C3B4_ChanceTime(obj);
        break;
    }
    func_80029714_2A314(obj->model[1], obj->trans.x, 3.0f, obj->trans.z);
}
void func_8010B28C_26238C_ChanceTime(void) {
    s16 win;

    D_801100BC_2671BC_ChanceTime = 0;
    win = func_80057480_58080(100, 140, 17, 4);
    ShowTextWindow(win);
    func_800890CC_89CCC(win, 6, -1, -1);
    func_80089A48_8A648(win, 0);
    func_80057730_58330(win, D_80110D6A_267E6A_ChanceTime[0]);
    D_801100BC_2671BC_ChanceTime = 1;
    func_8005762C_5822C(win);
    while (1) {
        HuPrcVSleep();
    }
}
void func_8010B328_262428_ChanceTime(void) {
    s16 win;

    D_801100BC_2671BC_ChanceTime = 0;
    win = func_80057480_58080(30, 60, 18, 4);
    ShowTextWindow(win);
    func_800890CC_89CCC(win, 0, -1, -1);
    func_80089A48_8A648(win, 0);
    func_80057730_58330(win, D_80110D6A_267E6A_ChanceTime[0]);
    D_801100BC_2671BC_ChanceTime = 1;
    func_8005762C_5822C(win);
    while (1) {
        HuPrcVSleep();
    }
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010B3C4_2624C4_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010B7F8_2628F8_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010BB0C_262C0C_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010BB74_262C74_ChanceTime);

/* Matches, but retail pads it with three nops to 0x8010BF50, where its second file (MP1's
   DAF90.c, from func_800FC390) begins: C here would shift everything after it until the unit is
   split at 0x263050. */
#ifdef NON_MATCHING
void func_8010BF28_263028_ChanceTime(omObjData* obj) {
    Hu3DCamUpdateMtx(0);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010BF28_263028_ChanceTime);
#endif

void func_8010BF50_263050_ChanceTime(void) {
    D_8011092C_267A2C_ChanceTime = func_80018A64_19664(0x440001, 0x28D);
}
void func_8010BF7C_26307C_ChanceTime(omObjData* obj) {
    func_8010C44C_26354C_ChanceTime(obj, 0);
}
void func_8010BF98_263098_ChanceTime(omObjData* obj) {
    func_8010CCF4_263DF4_ChanceTime(obj, 0);
}
void func_8010BFB4_2630B4_ChanceTime(omObjData* obj) {
    func_8010CCF4_263DF4_ChanceTime(obj, 1);
}
void func_8010BFD0_2630D0_ChanceTime(omObjData* obj) {
    func_8010C44C_26354C_ChanceTime(obj, 1);
}
void func_8010BFEC_2630EC_ChanceTime(omObjData* obj) {
    func_8010CCF4_263DF4_ChanceTime(obj, 2);
}
void func_8010C008_263108_ChanceTime(omObjData* obj) {
    func_8010C44C_26354C_ChanceTime(obj, 2);
}
void func_8010C024_263124_ChanceTime(omObjData* obj) {
    if ((s16)func_8010DFF8_2650F8_ChanceTime(obj, 80.0f, D_800FFFD8_100BD8[0]) != 0 &&
        D_80110194_267294_ChanceTime == 0) {
        D_80110194_267294_ChanceTime = 1;
    }
    D_80110150_267250_ChanceTime[2] = 1;
    D_80110181_267281_ChanceTime = 0;
}
void func_8010C080_263180_ChanceTime(omObjData* obj) {
    func_8010C44C_26354C_ChanceTime(obj, 3);
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010C09C_26319C_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010C268_263368_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010C44C_26354C_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010CCF4_263DF4_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010DFF8_2650F8_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010E0D4_2651D4_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010E214_265314_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010E440_265540_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010E668_265768_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010E71C_26581C_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010E7C0_2658C0_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010EED0_265FD0_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010EF84_266084_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010F304_266404_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010F4B4_2665B4_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010F760_266860_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010F82C_26692C_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010F8F8_2669F8_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010F9C4_266AC4_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010FC18_266D18_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010FD28_266E28_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010FE50_266F50_ChanceTime);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_34_ChanceTime/259900", func_8010FF1C_26701C_ChanceTime);

/* GCC still thinks it is in .rodata after the previous const, but INCLUDE_ASM switched to
 * .text: switch back by hand (harmless once a C function precedes this). */
__asm__(".section .rodata");
/* Read only by .data (a texture-name table): rodata order is source order. */
const char D_80110680_267780_ChanceTime[] = "tex3_DEF";
const char D_8011068C_26778C_ChanceTime[] = "tex2_DEF";
const char D_80110698_267798_ChanceTime[] = "tex1_DEF";
const char D_801106A4_2677A4_ChanceTime[] = "tex0_DEF";
