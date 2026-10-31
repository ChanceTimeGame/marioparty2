#include "common.h"
#include "ovl_06.h"

__asm__(".section .rodata");
const u32 D_801085B0_10BD70_MalletGoRound[11] = { 0x00140008, 0x00140009, 0x0014000A, 0x0014000C, 0x0014000D, 0x0014000E, 0x0014000F, 0x00140010, 0x00140011, 0x00140012, 0x00140013 };

__asm__(".section .rodata");
const u32 D_801085DC_10BD9C_MalletGoRound[13] = { 0x00000000, 0x42700000, 0x42F00000, 0x43340000, 0x43700000, 0x43960000, 0x00000000, 0x42700000, 0x42F00000, 0x43340000, 0x43700000, 0x43960000, 0x00000000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_MalletGoRound/108DF0", func_80105630_108DF0_MalletGoRound);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_MalletGoRound/108DF0", func_80105EEC_1096AC_MalletGoRound);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_MalletGoRound/108DF0", func_801062EC_109AAC_MalletGoRound);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_MalletGoRound/108DF0", func_80106C7C_10A43C_MalletGoRound);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_MalletGoRound/108DF0", func_801079EC_10B1AC_MalletGoRound);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_MalletGoRound/108DF0", func_80107F50_10B710_MalletGoRound);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_MalletGoRound/108DF0", func_801082A8_10BA68_MalletGoRound);

void func_801083D8_10BB98_MalletGoRound(void) {
    D_801086B4_10BE74_MalletGoRound = 0;
    D_801084B8_10BC78_MalletGoRound = 0;
    D_801084BC_10BC7C_MalletGoRound = 1;
}

void func_801083F8_10BBB8_MalletGoRound(void) {
    D_801084BC_10BC7C_MalletGoRound = 0;
}

void func_80108404_10BBC4_MalletGoRound(s16 model, s16 arg1) {
    HmfModel* m = &D_800FC834_FD434[model];

    m->hmf->unk9C->unk08 = arg1;
}
