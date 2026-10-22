#include "common.h"
#include "ovl_50.h"

void func_8010D360_34DBC0_name_50(void) {
    D_8010105C_101C5C = D_80101300_101F00 = 0.9f;
    func_8005E260_5EE60(D_8011275A_352FBA_name_50);
    func_80020D20_21920(0x1A);
    func_8010D614_34DE74_name_50();
    func_8010E164_34E9C4_name_50();
    func_8010E478_34ECD8_name_50();
    func_8010F1A8_34FA08_name_50();
    func_8010F79C_34FFFC_name_50();
    func_801100EC_35094C_name_50();
    func_8011039C_350BFC_name_50();
    D_8010105C_101C5C = D_80101300_101F00 = 1.0f;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/34DBC0", func_8010D3F4_34DC54_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/34DBC0", func_8010D614_34DE74_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/34DBC0", func_8010E164_34E9C4_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/34DBC0", func_8010E478_34ECD8_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/34DBC0", func_8010F1A8_34FA08_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/34DBC0", func_8010F79C_34FFFC_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/34DBC0", func_801100EC_35094C_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/34DBC0", func_8011039C_350BFC_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/34DBC0", func_8011099C_3511FC_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/34DBC0", func_80110B1C_35137C_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/34DBC0", func_80110E5C_3516BC_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/34DBC0", func_80110E9C_3516FC_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/34DBC0", func_80110EFC_35175C_name_50);

void func_80110F10_351770_name_50(void) {
    D_80112638_352E98_name_50->work[0] = 0;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/34DBC0", func_80110F20_351780_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/34DBC0", func_801112EC_351B4C_name_50);

void func_80111690_351EF0_name_50(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_80112640_352EA0_name_50[i][0] = NULL;
        D_801126C0_352F20_name_50[i][0] = NULL;
    }
}

omObjData* func_801116C8_351F28_name_50(void (*init)(omObjData*), void (*func)(omObjData*), s32 nvtx, s32 ngfx) {
    omObjData* obj;
    s16 slot;
    s32 i;

    obj = omAddObj(0x1F4, 1, 0, -1, func);
    for (slot = 0; slot < 4; slot++) {
        if (D_801126C0_352F20_name_50[slot][0] == NULL) {
            break;
        }
    }
    if (slot == 4) {
        return NULL;
    }
    obj->work[0] = 0;
    obj->work[1] = slot;
    for (i = 0; i < D_800FDBCA_FE7CA; i++) {
        D_80112640_352EA0_name_50[slot][i] = func_80027154_27D54(nvtx * sizeof(Vtx), 0x7918);
        D_801126C0_352F20_name_50[slot][i] = func_80027154_27D54(ngfx * sizeof(Gfx), 0x7918);
    }
    if (init != NULL) {
        init(obj);
    }
    obj->model[0] = func_80027FA4_28BA4(0x684, D_801126C0_352F20_name_50[slot][D_800FDBE0_FE7E0], 4);
    return obj;
}

void func_80111868_3520C8_name_50(omObjData* obj) {
    u8 slot = obj->work[1];
    s16 i;

    func_800283DC_28FDC(obj->model[0]);
    for (i = 0; i < D_800FDBCA_FE7CA; i++) {
        if (D_80112640_352EA0_name_50[slot][i] != NULL) {
            HuMemFree(D_80112640_352EA0_name_50[slot][i]);
            D_80112640_352EA0_name_50[slot][i] = NULL;
        }
        if (D_801126C0_352F20_name_50[slot][i] != NULL) {
            HuMemFree(D_801126C0_352F20_name_50[slot][i]);
            D_801126C0_352F20_name_50[slot][i] = NULL;
        }
    }
    omDelObj(obj);
}
