#include "ovl_3C.h"

void func_80105EB0_294F20_DeepSeaSalvage(void) {
    D_800FA610_FB210 = 8000.0f;
    D_800FD474_FE074.x = 2.9249f;
    D_800FD474_FE074.y = 0.0f;
    D_800FD474_FE074.z = 0.0f;
    D_8010274C_10334C.x = 0.0f;
    D_8010274C_10334C.y = 200.0f;
    D_8010274C_10334C.z = -110.0f;
}

void func_80105F14_294F84_DeepSeaSalvage(void) {
    s16 i;

    D_80108E90_297F00_DeepSeaSalvage = 0;
    for (i = 0; i < 256; i++) {
        D_8010A7F0_299860_DeepSeaSalvage[i] = NULL;
    }
}

/* An extra work block for obj; retail packs its address into obj->work[0..3] (a host pointer
   does not fit there). */
DSSWork* func_80105F5C_294FCC_DeepSeaSalvage(omObjData* obj) {
    DSSWork* w;

    w = HuMemMemoryAllocPerm(sizeof(DSSWork));
    D_8010A7F0_299860_DeepSeaSalvage[D_80108E90_297F00_DeepSeaSalvage] = w;
    obj->work[0] = (u32)w >> 24;
    obj->work[1] = (u32)w >> 16;
    obj->work[2] = (u32)w >> 8;
    obj->work[3] = (u32)w;
    w->unk0 = 0;
    w->unk2 = 0;
    w->unk8 = 0;
    w->unkA = D_80108E90_297F00_DeepSeaSalvage;
    w->unkC = w->unk10 = w->unk14 = 0.0f;
    w->unk18 = w->unk1C = w->unk20 = 0.0f;
    w->unk24 = w->unk28 = w->unk2C = 0.0f;
    w->unk3C = w->unk3E = w->unk40 = w->unk42 = 0;
    w->unk44 = w->unk46 = w->unk48 = w->unk4A = 0;
    w->unk4C = w->unk4E = w->unk50 = w->unk52 = 0;
    w->unk54 = w->unk56 = w->unk58 = w->unk5A = 0;
    D_80108E90_297F00_DeepSeaSalvage++;
    return w;
}

void func_80106048_2950B8_DeepSeaSalvage(void) {
    s16 i;

    for (i = 0; i < D_80108E90_297F00_DeepSeaSalvage; i++) {
        if (D_8010A7F0_299860_DeepSeaSalvage[i] != NULL) {
            HuMemMemoryFreePerm(D_8010A7F0_299860_DeepSeaSalvage[i]);
        }
    }
}

u32 func_801060C8_295138_DeepSeaSalvage(void) {
    u8 hi = rand8();

    return (hi << 8) | rand8();
}

u16 func_80106100_295170_DeepSeaSalvage(u16 n) {
    return (func_801060C8_295138_DeepSeaSalvage() * n) >> 16;
}

/* Keep a point inside the play area. */
void func_80106134_2951A4_DeepSeaSalvage(f32* x, f32* y, f32* z) {
    if (*x < -712.0f) {
        *x = -712.0f;
    }
    if (*x > 712.0f) {
        *x = 712.0f;
    }
    if (*y > 380.0f) {
        *y = 380.0f;
    }
    if (*y < -372.0f) {
        *y = -372.0f;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/294F20", func_801061CC_29523C_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/294F20", func_80106518_295588_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/294F20", func_801069E4_295A54_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/294F20", func_80106CC4_295D34_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/294F20", func_80106D5C_295DCC_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/294F20", func_80106EC4_295F34_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/294F20", func_80106F08_295F78_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/294F20", func_801070D0_296140_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/294F20", func_801072C0_296330_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/294F20", func_80107318_296388_DeepSeaSalvage);
