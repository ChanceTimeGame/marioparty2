#include "common.h"
#include "ovl_0F.h"

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
    if (w->speed > 0.0f) {
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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0F_RainbowRun/1479E0", func_80106838_1481C8_RainbowRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0F_RainbowRun/1479E0", func_80106CB8_148648_RainbowRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0F_RainbowRun/1479E0", func_80106D60_1486F0_RainbowRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0F_RainbowRun/1479E0", func_80106E70_148800_RainbowRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0F_RainbowRun/1479E0", func_80106E8C_14881C_RainbowRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0F_RainbowRun/1479E0", func_80107018_1489A8_RainbowRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0F_RainbowRun/1479E0", func_801075FC_148F8C_RainbowRun);
