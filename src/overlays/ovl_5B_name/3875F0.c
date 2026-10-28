#include "common.h"
#include "ovl_5B.h"

/* Sets up the scene's extra models and processes: 8010DCAC and 80110908, the screen-wide sprite
   D_801144A6, model [0x14] attached to [0x11]'s matrix, the c167/c168 textures on [0x17]/[0x20],
   [0xC]'s motion (D_80114860 picks the second one) and its "rc_ban" texture animation. */
void func_8010A940_3875F0_name_5B(void) {
    void* data;

    omAddPrcObj(func_8010DCAC_38A95C_name_5B, 0x3F00, 0x800, 0);
    omAddPrcObj(func_80110908_38D5B8_name_5B, 0x3F00, 0x800, 0);
    func_80029FE4_2ABE4(D_80114758_391408_name_5B[7], 0.5f);
    D_801144A4_391154_name_5B = func_8001A2F8_1AEF8(0x900FD);
    D_801144A6_391156_name_5B = func_8001AAAC_1B6AC(D_801144A4_391154_name_5B, 0, 1);
    espPosSet(D_801144A6_391156_name_5B, 160, 120);
    espDispOff(D_801144A6_391156_name_5B);
    func_8001A6BC_1B2BC(D_801144A6_391156_name_5B, 256);
    func_800B1F50_B2B50((f32(*)[4])D_800FC834_FD434[D_80114758_391408_name_5B[0x14]].mtx, 30.0f, -8.0f, 0.0f);
    func_80025830_26430((f32(*)[4])D_800FC834_FD434[D_80114758_391408_name_5B[0x14]].mtx, 1.1f, 1.1f, 1.1f);
    func_80030CD4_318D4((f32(*)[4])D_800FC834_FD434[D_80114758_391408_name_5B[0x11]].mtx,
                        (f32(*)[4])D_800FC834_FD434[D_80114758_391408_name_5B[0x14]].mtx);
    HmfModelObjAttrSet(D_80114758_391408_name_5B[0x14], 0x80000000, 0x80000000);
    func_80029A8C_2A68C(D_80114758_391408_name_5B[0x14]);
    func_80029AFC_2A6FC(D_80114758_391408_name_5B[0x14]);
    HmfModelObjAttrSet(D_80114758_391408_name_5B[0x11], 0x80000000, 0x80000000);
    func_80029A8C_2A68C(D_80114758_391408_name_5B[0x11]);
    func_80029AFC_2A6FC(D_80114758_391408_name_5B[0x11]);
    data = DataRead(0x90064);
    func_8003D8F0_3E4F0(D_800FC834_FD434[D_80114758_391408_name_5B[0x17]].hmf, data, 0, "c167n_0_DEF");
    DataClose(data);
    func_80029A8C_2A68C(D_80114758_391408_name_5B[0x17]);
    func_80029AFC_2A6FC(D_80114758_391408_name_5B[0x17]);
    data = DataRead(0x9006D);
    func_8003D8F0_3E4F0(D_800FC834_FD434[D_80114758_391408_name_5B[0x20]].hmf, data, 0, "c168n_0_DEF");
    DataClose(data);
    func_80029A8C_2A68C(D_80114758_391408_name_5B[0x20]);
    func_80029AFC_2A6FC(D_80114758_391408_name_5B[0x20]);
    if (D_80114860_391510_name_5B == 0) {
        func_8002C9C0_2D5C0(D_80114758_391408_name_5B[0xC], D_801147D0_391480_name_5B[0xC]);
    } else {
        func_8002C9C0_2D5C0(D_80114758_391408_name_5B[0xC], D_801147D0_391480_name_5B[0xD]);
    }
    func_80029E80_2AA80(D_80114758_391408_name_5B[0xC], 2, 2);
    data = DataRead(0x90051);
    D_801144A8_391158_name_5B = func_8003D8F0_3E4F0(D_800FC834_FD434[D_80114758_391408_name_5B[0xC]].hmf, data, 0, "rc_ban_DEF");
    DataClose(data);
    func_80029A8C_2A68C(D_80114758_391408_name_5B[0xC]);
    func_80029AFC_2A6FC(D_80114758_391408_name_5B[0xC]);
    data = DataRead(0x90050);
    D_801144AA_39115A_name_5B = func_8003DF08_3EB08(data);
    DataClose(data);
    func_8003EE44_3FA44(D_800FC834_FD434[D_80114758_391408_name_5B[0xC]].hmf);
    D_80114730_3913E0_name_5B[0] = 0;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010ACBC_38796C_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010B5A8_388258_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010B654_388304_name_5B);



__asm__(".section .rodata");
const char D_801139A4_390654_name_5B[] = "record";

__asm__(".section .rodata");
const char D_801139AC_39065C_name_5B[] = "hari";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010C5D4_389284_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010C828_3894D8_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010CB88_389838_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010D6E8_38A398_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010D8B0_38A560_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010DA34_38A6E4_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010DCAC_38A95C_name_5B);


__asm__(".section .rodata");
const char D_801139B4_390664_name_5B[] = "item_hook";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010DF24_38ABD4_name_5B);


__asm__(".section .rodata");
const char D_801139C0_390670_name_5B[] = "%d";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010E618_38B2C8_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010ED80_38BA30_name_5B);



__asm__(".section .rodata");
const u32 D_801139C8_390678_name_5B[2] = { 0x05256405, 0x00000000 };

__asm__(".section .rodata");
const u32 D_801139D0_390680_name_5B[2] = { 0x05253032, 0x64050000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010F734_38C3E4_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_801101E8_38CE98_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_80110770_38D420_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8011083C_38D4EC_name_5B);


__asm__(".section .rodata");
const char D_801139F4_3906A4_name_5B[28] = "c168_000-atama";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_80110908_38D5B8_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_80110AF8_38D7A8_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_80112094_38ED44_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_80112304_38EFB4_name_5B);
