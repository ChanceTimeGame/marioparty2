#include "common.h"
#include "ovl_5B.h"

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010A940_3875F0_name_5B);

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

s16 func_80110770_38D420_name_5B(s16 x, s16 y) {
    s16 win = func_800888A8_894A8(x, y, 200, 32, 0, 8);

    func_80089A7C_8A67C(win, 5);
    func_80089284_89E84(win, 32, 32);
    func_80089BBC_8A7BC(win, 0);
    func_80089B2C_8A72C(win, 0);
    func_8008D5D8_8E1D8(win);
    func_80089A48_8A648(win, 0);
    func_80089C78_8A878(win, 1);
    func_80089DA0_8A9A0(win, 192, 192, 192);
    func_800890CC_89CCC(win, 0x534, -2, -1);
    return win;
}

s16 func_8011083C_38D4EC_name_5B(s16 x, s16 y) {
    s16 win = func_800888A8_894A8(x, y, 200, 20, 0, 8);

    func_80089A7C_8A67C(win, 5);
    func_80089284_89E84(win, 32, 32);
    func_8008D5D8_8E1D8(win);
    func_80089BBC_8A7BC(win, 0);
    func_80089B2C_8A72C(win, 0);
    func_80089A48_8A648(win, 0);
    func_80089C78_8A878(win, 1);
    func_80089DA0_8A9A0(win, 192, 192, 192);
    func_800890CC_89CCC(win, 0x535, -2, -1);
    return win;
}


__asm__(".section .rodata");
const char D_801139F4_3906A4_name_5B[28] = "c168_000-atama";

void func_80110908_38D5B8_name_5B(void) {
    s16 model = (u16)D_80114758_391408_name_5B[0x20];
    s16 prev;
    HmfMotionObj* mot;

    while (1) {
        prev = D_80113492_390142_name_5B;
        HuPrcVSleep();
        if (D_80113898_390548_name_5B[0] != 0 && D_80114730_3913E0_name_5B[0] != 0) {
            if (D_801148A4_391554_name_5B == 6 && D_80114738_3913E8_name_5B == D_801148A4_391554_name_5B) {
                func_80029BF0_2A7F0(model, D_801147D0_391480_name_5B[0x22], 0, 10, 2);
            } else {
                func_80029BF0_2A7F0(model, D_801147D0_391480_name_5B[0x20], 0, 10, 2);
            }
        }
        if (prev == D_80113492_390142_name_5B) {
            continue;
        }
        if (D_80113492_390142_name_5B != 0) {
            func_80029BF0_2A7F0(model, D_801147D0_391480_name_5B[0x20], 0, 10, 2);
            func_80029E80_2AA80(model, 2, 2);
            func_8003B72C_3C32C(model, D_801147D0_391480_name_5B[0x20], D_801139F4_3906A4_name_5B, 0x4C, 0x45);
            func_8003B72C_3C32C(model, D_801147D0_391480_name_5B[0x20], D_801139F4_3906A4_name_5B, 0x4C, 0x46);
            mot = func_8002A9F4_2B5F4(model, D_801139F4_3906A4_name_5B);
            mot->unk10.y = 13.0f;
            mot->unk10.x = -10.0f;
        } else {
            func_8003B76C_3C36C(model, D_801147D0_391480_name_5B[0x20], D_801139F4_3906A4_name_5B, 0x4C, 0x45);
            func_8003B76C_3C36C(model, D_801147D0_391480_name_5B[0x20], D_801139F4_3906A4_name_5B, 0x4C, 0x46);
            func_80029BF0_2A7F0(model, D_801147D0_391480_name_5B[0x22], 0, 10, 2);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_80110AF8_38D7A8_name_5B);

void func_80112094_38ED44_name_5B(s32 jump) {
    u16 model = D_80114758_391408_name_5B[0x20];
    s16 i;
    Vec start;
    Vec end;
    Vec cur;

    func_800298A4_2A4A4(D_80114758_391408_name_5B[0x2A], 0x4004, 4);
    func_80029BF0_2A7F0(model, D_801147D0_391480_name_5B[0x22], 0, 5, 2);
    if (jump != 0) {
        func_8002C9C0_2D5C0(D_80114758_391408_name_5B[0xA], D_801147D0_391480_name_5B[0xB]);
        PlaySound(0xB7);
        start.x = D_800FC834_FD434[(s16)model].pos.x;
        start.y = D_800FC834_FD434[(s16)model].pos.y;
        start.z = D_800FC834_FD434[(s16)model].pos.z;
        end.x = D_80114718_3913C8_name_5B[0].x;
        end.y = D_80114718_3913C8_name_5B[0].y;
        end.z = D_80114718_3913C8_name_5B[0].z;
        for (i = 0; i < 6; i++) {
            cur.x = (end.x - start.x) / 5.0f * i + start.x;
            cur.y = (end.y - start.y) / 5.0f * i + start.y;
            cur.y += HuMathSin(i * 36.0f) * 10.0f;
            cur.z = (end.z - start.z) / 5.0f * i + start.z;
            func_80029714_2A314(model, cur.x, cur.y, cur.z);
            func_80029714_2A314(D_80114758_391408_name_5B[0x28], cur.x, 0.0f, cur.z);
            HuPrcVSleep();
        }
    }
    func_80108788_385438_name_5B(0x10, 10, 1, (void (*)(s16*))-1);
    D_80113838_3904E8_name_5B = 1;
    D_80113898_390548_name_5B[0] = 1;
    func_800298A4_2A4A4(D_80114758_391408_name_5B[0x29], 0x4004, 4);
    func_800298A4_2A4A4(D_80114758_391408_name_5B[0x16], 4, 0);
    func_80029E80_2AA80(D_80114758_391408_name_5B[0x15], 1, 0);
    func_80029E80_2AA80(D_80114758_391408_name_5B[0x16], 1, 0);
}

void func_80112304_38EFB4_name_5B(void) {
    s16 cat;
    s16 i;

    for (i = 0; i < 9; i++) {
        D_80113F40_390BF0_name_5B[i] = D_80113F58_390C08_name_5B[i] = D_80113F70_390C20_name_5B[i] = 0;
    }
    D_801144A0_391150_name_5B = 0;
    D_80113F86_390C36_name_5B = 0;
    D_80113F84_390C34_name_5B = 0;
    D_80113F82_390C32_name_5B = 0;
    for (i = 0; i < 72; i++) {
        if (D_800CAD90[i].unk_00 == 0 || i == 15) {
            continue;
        }
        if (i == 0x22) {
            continue;
        }
        cat = D_800CAD90[i].unk_04;
        if (func_80067F4C_68B4C(i) != 0) {
            if (func_80068040_68C40(i) != 0) {
                D_80113F90_390C40_name_5B[cat][D_80113F70_390C20_name_5B[cat]] = i;
                D_80113F70_390C20_name_5B[cat]++;
                D_80113F84_390C34_name_5B++;
            } else {
                D_80113A30_3906E0_name_5B[cat][D_80113F40_390BF0_name_5B[cat]] = i;
                D_80113F40_390BF0_name_5B[cat]++;
                D_80113F82_390C32_name_5B++;
            }
            D_801144A0_391150_name_5B++;
        }
        D_80113F86_390C36_name_5B++;
        D_80113F58_390C08_name_5B[cat]++;
    }
    if (func_80068040_68C40(15) != 0) {
        D_80113F90_390C40_name_5B[1][D_80113F70_390C20_name_5B[1]] = 15;
        D_80113F70_390C20_name_5B[1]++;
        D_80113F84_390C34_name_5B++;
        D_801144A0_391150_name_5B++;
        D_80113F86_390C36_name_5B++;
        D_80113F58_390C08_name_5B[1]++;
    }
    if (func_80068040_68C40(0x22) != 0) {
        D_80113F90_390C40_name_5B[2][D_80113F70_390C20_name_5B[2]] = 0x22;
        D_80113F70_390C20_name_5B[2]++;
        D_80113F84_390C34_name_5B++;
        D_801144A0_391150_name_5B++;
        D_80113F86_390C36_name_5B++;
        D_80113F58_390C08_name_5B[2]++;
    }
}
