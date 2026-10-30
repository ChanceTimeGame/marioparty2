#include "ovl_3C.h"

/* The fish object's models: five copies of the fish, two of them drawn with attribute 4 (MP1
   func_800FEA00). */
void func_801074E0_296550_DeepSeaSalvage(omObjData* obj) {
    s16 i;

    for (i = 0; i < 5; i++) {
        obj->model[i + 1] = func_80027D3C_2893C(obj->model[0]);
    }
    func_800298A4_2A4A4(obj->model[2], 4, 4);
    func_800298A4_2A4A4(obj->model[5], 4, 4);
    for (i = 0; i < 2; i++) {
        func_80107864_2968D4_DeepSeaSalvage(obj, i);
    }
    D_80108E70_297EE0_DeepSeaSalvage = 0;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/296550", func_801075A4_296614_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/296550", func_80107864_2968D4_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/296550", func_80107A10_296A80_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/296550", func_8010819C_29720C_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/296550", func_801081EC_29725C_DeepSeaSalvage);
