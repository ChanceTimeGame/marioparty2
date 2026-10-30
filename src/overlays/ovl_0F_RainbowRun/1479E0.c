#include "common.h"
#include "ovl_0F.h"

/* .data (0x14C130-0x14C1C0, 8010A7A0-8010A830). D_8010A808 (inside D_8010A804) is an
   undefined_syms.txt alias. */

/* unreferenced: the word that starts this file's .data */
s32 D_8010A7A0_14C130_RainbowRun = 0;
s8 D_8010A7A4_14C134_RainbowRun = 0;
s16 D_8010A7A6_14C136_RainbowRun = 0;
s8 D_8010A7A8_14C138_RainbowRun = 1;
f32 D_8010A7AC_14C13C_RainbowRun[7] = { 45.0f, 90.0f, 135.0f, 225.0f, 270.0f, 315.0f, 0.0f };
s8 D_8010A7C8_14C158_RainbowRun = 6;
f32 D_8010A7CC_14C15C_RainbowRun = 0.0f;
f32 D_8010A7D0_14C160_RainbowRun = 0.0f;
f32 D_8010A7D4_14C164_RainbowRun = 0.0f;
f32 D_8010A7D8_14C168_RainbowRun = 0.0f;
f32 D_8010A7DC_14C16C_RainbowRun = 0.0f;
f32 D_8010A7E0_14C170_RainbowRun = 0.0f;
f32 D_8010A7E4_14C174_RainbowRun = 0.0f;
s8 D_8010A7E8_14C178_RainbowRun = 1;
s8 D_8010A7E9_14C179_RainbowRun = 0;
s8 D_8010A7EA_14C17A_RainbowRun = 0;
s8 D_8010A7EB_14C17B_RainbowRun = 0x7F;
s8 D_8010A7EC_14C17C_RainbowRun = 0;
s8 D_8010A7ED_14C17D_RainbowRun = 1;
s8 D_8010A7EE_14C17E_RainbowRun = 6;
s8 D_8010A7EF_14C17F_RainbowRun = 6;
s8 D_8010A7F0_14C180_RainbowRun = 0;
s32 D_8010A7F4_14C184_RainbowRun = 0;
s32 D_8010A7F8_14C188_RainbowRun = 0;
s32 D_8010A7FC_14C18C_RainbowRun = 0;
s32 D_8010A800_14C190_RainbowRun = 0;
f32 D_8010A804_14C194_RainbowRun[4][2] = { { 0.0f, 0.0f }, { 0.0f, 0.0f }, { 0.0f, 0.0f }, { 0.0f, 0.0f } };
s8 D_8010A824_14C1B4_RainbowRun = 0;

/* Keeps a copy of a model's collision vertices (the rainbow's base shape). */
void func_80106050_1479E0_RainbowRun(s16 model) {
    HmfData* m;
    ColVtx* src;
    s32 size;

    func_8002A00C_2AC0C(model);
    m = D_800FC834_FD434[model].hmf;
    src = m->unk54;
    size = m->unk14 * sizeof(ColVtx);
    D_8010A9C0_14C350_RainbowRun = func_80027154_27D54(size, 0x7918);
    bcopy(src, D_8010A9C0_14C350_RainbowRun, size);
}

/* The rainbow (MP1 func_800F9508_TightropeTreachery): sways, ripples under the running runner and
   bends with the wind; the course's middle follows it. */
void func_801060D8_147A68_RainbowRun(omObjData* obj) {
    RRPlayerWork* w = D_800FFFD8_100BD8[0]->unk_50;
    f32 amp;
    f32 dz;
    f32 x;
    f32 ox;
    HmfData* m;
    HmfVtx* src;
    HmfVtx* dst;
    s16 i;
    s16 n;

    if (D_8010A7E8_14C178_RainbowRun == 1) {
        if (func_80078EA8_79AA8() + D_80102720_103320 == 0 && D_8010A7A8_14C138_RainbowRun == 0) {
            D_8010A7E0_14C170_RainbowRun -= 0.6;
        }
        if (D_8010A7E0_14C170_RainbowRun <= -20.0f) {
            D_8010A7E8_14C178_RainbowRun = 0;
        }
    } else {
        if (func_80078EA8_79AA8() + D_80102720_103320 == 0 && D_8010A7A8_14C138_RainbowRun == 0) {
            D_8010A7E0_14C170_RainbowRun += 0.6;
        }
        if (D_8010A7E0_14C170_RainbowRun >= 20.0f) {
            D_8010A7E8_14C178_RainbowRun = 1;
        }
    }
    if (w->unk_40 > 0.0f) {
        amp = func_800B7890_B8490(D_8010A7E4_14C174_RainbowRun * 18.0) * 5.0f + 35.0f;
        if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
            D_8010A7E4_14C174_RainbowRun += 1.0f;
        }
        if (D_8010A7E4_14C174_RainbowRun >= 20.0f) {
            D_8010A7E4_14C174_RainbowRun = 0.0f;
        }
    } else {
        D_8010A7E4_14C174_RainbowRun = 0.0f;
        amp = 40.0f;
    }
    D_8010A7D4_14C164_RainbowRun = 0.0f;
    m = D_800FC834_FD434[obj->model[1]].hmf;
    src = m->unk40;
    dst = m->unk44[D_800FDBE0_FE7E0];
    for (i = 0, n = m->unk18; i < n; i++) {
        *dst = *src;
        if (D_800FFFD8_100BD8[0]->trans.y >= D_8010A7D4_14C164_RainbowRun + -50.0) {
            dz = src->unk04 - D_800FFFD8_100BD8[0]->trans.z;
            if ((dz > -500.0f) & (dz < 500.0f)) {
                dst->unk02 = src->unk02 + func_800B7890_B8490((dz + 500.0f) * 0.36f) * amp - amp;
            } else {
                dst->unk02 = src->unk02;
            }
        }
        dst->unk00 = src->unk00 + D_8010ABFC_14C58C_RainbowRun[0] * 70.0f * func_800B7890_B8490((src->unk04 + 2500) / 5000.0 * 90.0) +
                     D_8010A7E0_14C170_RainbowRun;
        dst->unk04 = src->unk04;
        dst->unk0C[0] = src->unk0C[0];
        dst->unk0C[1] = src->unk0C[1];
        dst->unk0C[2] = src->unk0C[2];
        src++;
        dst++;
    }
    ox = D_8010ABFC_14C58C_RainbowRun[0] * 70.0f * func_800B7890_B8490((D_800FFFD8_100BD8[0]->trans.z + 2500.0f) / 5000.0 * 90.0) +
         D_8010A7E0_14C170_RainbowRun;
    obj->trans.x = ox;
    obj->trans.y = 0.0f;
    obj->trans.z = D_800FFFD8_100BD8[0]->trans.z;
    func_80029714_2A314(obj->model[0], ox, 0.0f, D_800FFFD8_100BD8[0]->trans.z);
    if (D_800FFFD8_100BD8[0]->trans.z < -1150.0f && D_8010A7E9_14C179_RainbowRun == 0) {
        func_80019E04_1AA04(D_800FFFD8_100BD8[0], 0, 0x27);
        func_80019E04_1AA04(D_800FFFD8_100BD8[0], 1, 0x28);
        func_80019E04_1AA04(D_800FFFD8_100BD8[0], 2, 0x29);
        func_80019CA4_1A8A4(D_800FFFD8_100BD8[0], 1);
        func_8000C460_D060();
        w->unk_EC = NULL;
        D_8010A7E9_14C179_RainbowRun = 1;
    }
    x = D_8010ABFC_14C58C_RainbowRun[0] * 70.0f * func_800B7890_B8490((D_800FFFD8_100BD8[0]->trans.z - 500.0f + 2500.0f) * 90.0 / 5000.0) +
        D_8010A7E0_14C170_RainbowRun;
    D_8010A7D0_14C160_RainbowRun = x;
    D_8010A7DC_14C16C_RainbowRun = x - D_8010A7D8_14C168_RainbowRun;
    D_8010A7D8_14C168_RainbowRun = x;
    func_80029714_2A314(D_800FC7B0_FD3B0[0]->model[2], D_8010ABFC_14C58C_RainbowRun[0] * 70.0f * func_800B7890_B8490(15.3f) + D_8010A7E0_14C170_RainbowRun,
                        0.0f, -1150.0f);
    D_8010AC0C_14C59C_RainbowRun = D_8010A7E0_14C170_RainbowRun;
    if (D_800FFFD8_100BD8[0]->trans.y >= D_8010A7D4_14C164_RainbowRun + -100.0 && w->unk_38 != -1.0f) {
        D_800FFFD8_100BD8[0]->trans.x += D_8010A7DC_14C16C_RainbowRun;
    }
}

/* The wind (MP1 func_800F9BA0_TightropeTreachery): gusts in a random direction, with their sound;
   it stops once the goal is reached. */
void func_80106838_1481C8_RainbowRun(void) {
    if (D_8010A7A8_14C138_RainbowRun == 1) {
        D_8010A7EC_14C17C_RainbowRun = 0;
        D_8010A7ED_14C17D_RainbowRun = 0;
        D_8010A7EA_14C17A_RainbowRun = 1;
        D_8010A7F0_14C180_RainbowRun = 0;
    } else if (D_8010A7F0_14C180_RainbowRun == 0) {
        D_8010A7EC_14C17C_RainbowRun = 1;
        D_8010A7ED_14C17D_RainbowRun = 0;
        D_8010A7EA_14C17A_RainbowRun = 0;
        D_8010A7F4_14C184_RainbowRun = 0;
        D_8010A7F8_14C188_RainbowRun = 0;
        D_8010A7FC_14C18C_RainbowRun = 0;
        D_8010A7F0_14C180_RainbowRun = 1;
    }
    if (D_8010A7ED_14C17D_RainbowRun == 1) {
        if (D_8010A7FC_14C18C_RainbowRun++ > 90) {
            D_8010A7F8_14C188_RainbowRun = guRandom() % 120 / 2 + 30;
            D_8010A7C8_14C158_RainbowRun = D_8010A7EE_14C17E_RainbowRun = guRandom() % 5;
            D_8010A7F4_14C184_RainbowRun = 0;
            D_8010A7ED_14C17D_RainbowRun = 0;
            D_8010A7EC_14C17C_RainbowRun = 1;
        } else {
            D_8010A7C8_14C158_RainbowRun = D_8010A7EE_14C17E_RainbowRun = 6;
        }
    }
    if (D_8010A7EC_14C17C_RainbowRun == 1) {
        if (D_8010A7F4_14C184_RainbowRun++ < D_8010A7F8_14C188_RainbowRun) {
            if (D_8010A7A4_14C134_RainbowRun == 0) {
                D_8010A7A6_14C136_RainbowRun = PlaySound(0x18C);
                D_8010A7A4_14C134_RainbowRun = 1;
                D_8010A7EB_14C17B_RainbowRun = 0x60;
                func_800795D8_7A1D8(D_8010A7A6_14C136_RainbowRun, 0x60);
                D_8010A7EA_14C17A_RainbowRun = 0;
            }
            D_8010A7CC_14C15C_RainbowRun += 0.012f;
            if (D_8010A7CC_14C15C_RainbowRun > 0.4f) {
                D_8010A7CC_14C15C_RainbowRun = 0.4f;
            }
        } else {
            D_8010A7EC_14C17C_RainbowRun = 0;
            D_8010A7ED_14C17D_RainbowRun = 1;
            D_8010A7FC_14C18C_RainbowRun = 0;
            D_8010A7C8_14C158_RainbowRun = D_8010A7EE_14C17E_RainbowRun = 6;
            D_8010A7EA_14C17A_RainbowRun = 1;
        }
    }
    if (D_8010A7EA_14C17A_RainbowRun == 1 && D_8010A7A4_14C134_RainbowRun == 1) {
        D_8010A7EB_14C17B_RainbowRun -= 3;
        if (D_8010A7EB_14C17B_RainbowRun > 0) {
            func_800795D8_7A1D8(D_8010A7A6_14C136_RainbowRun, D_8010A7EB_14C17B_RainbowRun);
        } else {
            D_8010A7EB_14C17B_RainbowRun = 0x7F;
            func_80079848_7A448(D_8010A7A6_14C136_RainbowRun);
            D_8010A7A6_14C136_RainbowRun = -2;
            D_8010A7A4_14C134_RainbowRun = 0;
            D_8010A7EA_14C17A_RainbowRun = 0;
        }
    }
    D_8010A7CC_14C15C_RainbowRun -= 0.006666667f;
    if (D_8010A7CC_14C15C_RainbowRun < 0.0f) {
        D_8010A7CC_14C15C_RainbowRun = 0.0f;
    }
    if (D_8010A7EE_14C17E_RainbowRun != 6) {
        D_8010ABFC_14C58C_RainbowRun[0] = HuMathSin(D_8010A7AC_14C13C_RainbowRun[D_8010A7EE_14C17E_RainbowRun]) * D_8010A7CC_14C15C_RainbowRun * 5.0f;
        D_8010ABFC_14C58C_RainbowRun[1] = func_800B7890_B8490(D_8010A7AC_14C13C_RainbowRun[D_8010A7EE_14C17E_RainbowRun]) * D_8010A7CC_14C15C_RainbowRun * 5.0f;
        D_8010A7EF_14C17F_RainbowRun = D_8010A7EE_14C17E_RainbowRun;
    } else {
        D_8010ABFC_14C58C_RainbowRun[0] = HuMathSin(D_8010A7AC_14C13C_RainbowRun[D_8010A7EF_14C17F_RainbowRun]) * D_8010A7CC_14C15C_RainbowRun * 5.0f;
        D_8010ABFC_14C58C_RainbowRun[1] = func_800B7890_B8490(D_8010A7AC_14C13C_RainbowRun[D_8010A7EF_14C17F_RainbowRun]) * D_8010A7CC_14C15C_RainbowRun * 5.0f;
    }
}

/* The rainbow's update: the goal's model goes once the camera passes z 350; the wind and the
   camera run while the game is not paused. */
void func_80106CB8_148648_RainbowRun(omObjData* obj) {
    if (D_8010A800_14C190_RainbowRun == 0 && D_80102750_103350[1] < 350.0f) {
        D_8010A800_14C190_RainbowRun = 1;
        func_800298A4_2A4A4(obj->model[0], 4, 4);
    }
    if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        if (D_800F8FD0_F9BD0 == 1) {
            func_80106838_1481C8_RainbowRun();
        }
        func_80105870_147200_RainbowRun();
    }
}

/* The scenery (a ground object): the start and goal models. */
void func_80106D60_1486F0_RainbowRun(omObjData* obj) {
    RRGround* w = func_80027154_27D54(sizeof(RRGround), 0x7918);

    obj->unk_50 = w;
    func_800B0EF0_B1AF0(w, 0, sizeof(RRGround));
    w->unk_03 = 1;
    w->unk_04 = 0;
    obj->model[0] = -1;
    obj->model[1] = LoadFormFile(0x1F0003, 0x16B9);
    obj->model[2] = LoadFormFile(0x1F0004, 0x2B9);
    obj->trans.x = 0.0f;
    obj->trans.y = -1100.0f;
    obj->trans.z = 1450.0f;
    func_80029714_2A314(obj->model[1], 0.0f, -1100.0f, 1500.0f);
    func_80029714_2A314(obj->model[2], 0.0f, 50.0f, -1150.0f);
    func_80105ED4_147864_RainbowRun(obj, 0.0f);
    obj->func_ptr = func_80106CB8_148648_RainbowRun;
}

void func_80106E70_148800_RainbowRun(omObjData* obj) {
    func_801060D8_147A68_RainbowRun(obj);
}

/* The rainbow (a ground object; MP1 func_800FB170_TightropeTreachery's rope). */
void func_80106E8C_14881C_RainbowRun(omObjData* obj) {
    RRGround* w = func_80027154_27D54(sizeof(RRGround), 0x7918);

    obj->unk_50 = w;
    func_800B0EF0_B1AF0(w, 0, sizeof(RRGround));
    w->unk_03 = 1;
    w->unk_04 = 1;
    obj->model[0] = func_80018A30_19630(0x1F0005, 0x6B9);
    func_800298A4_2A4A4(obj->model[0], 4, 4);
    obj->model[1] = LoadFormFile(0x1F0000, 0x6B9);
    func_80106050_1479E0_RainbowRun(obj->model[1]);
    func_8000BEA4_CAA4(obj, 25.0f);
    func_8000BE8C_CA8C(obj, 0.5f);
    obj->trans.x = obj->trans.y = 0.0f;
    obj->trans.z = D_800FFFD8_100BD8[0]->trans.z;
    obj->scale.y = obj->scale.z = 0.0f;
    obj->scale.x = 1.2f;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80029714_2A314(obj->model[1], obj->trans.x, 50.0f, 0.0f);
    {
        RRHitGrid* g = &D_800FD2B8_FDEB8[D_800FC834_FD434[obj->model[0]].unk10];

        g->cw = 500.0f;
    }
    obj->func_ptr = func_80106E70_148800_RainbowRun;
}

/* The wind's clouds (four models, new in MP2): while a gust blows they appear upwind of the
   course in a spread group and drift with it, as opaque as the wind is strong. */
void func_80107018_1489A8_RainbowRun(omObjData* obj) {
    s16 i;
    f32 a;
    u8 alpha;

    if (D_8010A7C8_14C158_RainbowRun == 6) {
        if (D_8010A824_14C1B4_RainbowRun == 1) {
            for (i = 0; i < 4; i++) {
                func_800298A4_2A4A4(obj->model[i], 4, 4);
            }
            D_8010A824_14C1B4_RainbowRun = 0;
        }
        for (i = 0; i < 4; i++) {
            D_8010A804_14C194_RainbowRun[i][0] = D_8010A804_14C194_RainbowRun[i][1] = 0.0f;
        }
        return;
    }
    if (D_8010A824_14C1B4_RainbowRun == 0) {
        for (i = 0; i < 4; i++) {
            func_800298A4_2A4A4(obj->model[i], 4, 0);
        }
        D_8010A804_14C194_RainbowRun[0][0] = HuMathSin(D_8010A7AC_14C13C_RainbowRun[D_8010A7C8_14C158_RainbowRun]) * -1200.0f;
        D_8010A804_14C194_RainbowRun[0][1] = func_800B7890_B8490(D_8010A7AC_14C13C_RainbowRun[D_8010A7C8_14C158_RainbowRun]) * -1200.0f;
        for (i = 1; i < 4; i++) {
            D_8010A804_14C194_RainbowRun[i][0] =
                i * 800.0f * HuMathSin(D_8010A7AC_14C13C_RainbowRun[D_8010A7C8_14C158_RainbowRun]) + guRandom() % 600 - 300.0f;
            D_8010A804_14C194_RainbowRun[i][1] =
                i * 800.0f * func_800B7890_B8490(D_8010A7AC_14C13C_RainbowRun[D_8010A7C8_14C158_RainbowRun]) + guRandom() % 600 - 300.0f;
        }
        D_8010A824_14C1B4_RainbowRun = 1;
    }
    D_8010A804_14C194_RainbowRun[0][0] = HuMathSin(D_8010A7AC_14C13C_RainbowRun[D_8010A7C8_14C158_RainbowRun]) * 50.0f + D_8010A804_14C194_RainbowRun[0][0];
    D_8010A804_14C194_RainbowRun[0][1] = func_800B7890_B8490(D_8010A7AC_14C13C_RainbowRun[D_8010A7C8_14C158_RainbowRun]) * 50.0f + D_8010A804_14C194_RainbowRun[0][1];
    a = (RR_ABS(D_8010ABFC_14C58C_RainbowRun[0]) + RR_ABS(D_8010ABFC_14C58C_RainbowRun[1])) * 255.0f;
    a = (a >= 255.0f) ? 255.0f : a;
    alpha = a;
    for (i = 0; i < 4; i++) {
        func_8002D0A0_2DCA0(obj->model[i], alpha);
    }
    obj->trans.x = D_8010A804_14C194_RainbowRun[0][0];
    obj->trans.y = 200.0f;
    obj->trans.z = (D_8010AC04_14C594_RainbowRun + D_800FFFD8_100BD8[0]->trans.z) / 2.0f + D_8010A804_14C194_RainbowRun[0][1] + 100.0f;
    obj->rot.y = D_8010A7AC_14C13C_RainbowRun[D_8010A7C8_14C158_RainbowRun];
    for (i = 1; i < 4; i++) {
        func_80029714_2A314(obj->model[i], D_8010A804_14C194_RainbowRun[0][0] + D_8010A804_14C194_RainbowRun[i][0], 200.0f,
                            D_8010A804_14C194_RainbowRun[0][1] + D_8010A804_14C194_RainbowRun[i][1] +
                                (D_8010AC04_14C594_RainbowRun + D_800FFFD8_100BD8[0]->trans.z) / 2.0f + 100.0f);
        func_8002979C_2A39C(obj->model[i], obj->rot.x, obj->rot.y, obj->rot.z);
    }
}

/* The clouds' object: four copies of one model, hidden and transparent until a gust. */
void func_801075FC_148F8C_RainbowRun(omObjData* obj) {
    void* w = func_80027154_27D54(sizeof(RRItemWork), 0x7918);

    obj->unk_50 = w;
    func_800B0EF0_B1AF0(w, 0, sizeof(RRItemWork));
    obj->model[0] = func_80018A64_19664(0x1F0002, 0x1AA9);
    obj->model[1] = func_80027D3C_2893C(obj->model[0]);
    obj->model[2] = func_80027D3C_2893C(obj->model[0]);
    obj->model[3] = func_80027D3C_2893C(obj->model[0]);
    func_800298A4_2A4A4(obj->model[0], 4, 4);
    func_800298A4_2A4A4(obj->model[1], 4, 4);
    func_800298A4_2A4A4(obj->model[2], 4, 4);
    func_800298A4_2A4A4(obj->model[3], 4, 4);
    func_8002D124_2DD24(obj->model[0]);
    func_8002D124_2DD24(obj->model[1]);
    func_8002D124_2DD24(obj->model[2]);
    func_8002D124_2DD24(obj->model[3]);
    func_8002D0A0_2DCA0(obj->model[0], 0);
    func_8002D0A0_2DCA0(obj->model[1], 0);
    func_8002D0A0_2DCA0(obj->model[2], 0);
    func_8002D0A0_2DCA0(obj->model[3], 0);
    obj->trans.x = 0.0f;
    obj->trans.y = 200.0f;
    obj->trans.z = 0.0f;
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, 400.0f);
    obj->func_ptr = func_80107018_1489A8_RainbowRun;
}
