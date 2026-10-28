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

/* Opens the record book (model [12]): the cover ("hari") swings while the "record" part lifts
   towards the camera. */
void func_8010C5D4_389284_name_5B(void) {
    s16 model = D_80114758_391408_name_5B[12];
    s16 frame;
    HmfMotionObj* hari;
    HmfMotionObj* record;
    f32 hariY;
    f32 x, y, z;
    f32 dx, dy, dz;
    f32 t;
    f32 angle;
    s16 i;

    frame = func_80029E14_2AA14(model);
    func_80029E80_2AA80(model, 1, 1);
    func_8003B72C_3C32C(model, frame, D_801139A4_390654_name_5B, 0x4C, 0x47);
    hari = func_8002A9F4_2B5F4(model, D_801139AC_39065C_name_5B);
    record = func_8002A9F4_2B5F4(model, D_801139A4_390654_name_5B);
    hariY = hari->unk04.y;
    x = record->unk04.x;
    dx = 100.0f - x;
    y = record->unk04.y;
    dy = 140.0f - y;
    z = record->unk04.z;
    dz = -6.0f - z;
    PlaySound(D_800CD52C_CE12C == 1 ? 0xC2 : 0x370);
    for (i = 0; i < 11; i++) {
        t = i;
        angle = t * 9.0f;
        hari->unk28.y = hariY + HuMathSin(angle) * 10.0f;
        record->unk28.x = x + HuMathSin(angle) * dx;
        record->unk28.y = y + t / 10.0f * dy;
        record->unk28.z = z + HuMathSin(angle) * dz;
        if (i >= 4) {
            record->unk10.z = (i - 3) * 12.857142f;
        }
        HuPrcVSleep();
    }
}

/* Closes the record book (model [12]), the reverse of 8010C5D4. mode 0 restores the model's
   textures; otherwise its texture animation slot D_801144A8 is reset to frame D_801144AA (mode
   1) or D_801144A8 (mode 2). */
void func_8010C828_3894D8_name_5B(s16 mode) {
    u16 model = D_80114758_391408_name_5B[12];
    TexAnimSlot* slot;
    HmfMotionObj* hari;
    HmfMotionObj* record;
    f32 hariY;
    f32 x, y, z;
    f32 dx, dy, dz;
    f32 t;
    f32 angle;
    s16 i;

    if (mode == 0) {
        func_8003EE44_3FA44(D_800FC834_FD434[(s16)model].hmf);
    } else {
        func_8003EEA4_3FAA4(D_800FC834_FD434[(s16)model].hmf);
        slot = &D_800FD7F8_FE3F8[D_801144A8_391158_name_5B];
        if (mode == 1) {
            slot->unk_00 = D_801144AA_39115A_name_5B;
        } else {
            slot->unk_00 = D_801144A8_391158_name_5B;
        }
        slot->unk_04 = 0;
        slot->unk_0A = 0;
        slot->unk_06 = 0;
        slot->unk_02 = 0;
    }
    func_80029E14_2AA14(model);
    hari = func_8002A9F4_2B5F4(model, D_801139AC_39065C_name_5B);
    record = func_8002A9F4_2B5F4(model, D_801139A4_390654_name_5B);
    hariY = hari->unk04.y;
    x = record->unk04.x;
    dx = 100.0f - x;
    y = record->unk04.y;
    dy = 140.0f - y;
    z = record->unk04.z;
    dz = -6.0f - z;
    for (i = 0; i < 11; i++) {
        t = i;
        angle = t * 9.0f;
        record->unk28.x = x + func_800B7890_B8490(angle) * dx;
        record->unk28.y = y + (1.0f - t / 10.0f) * dy;
        record->unk28.z = z + func_800B7890_B8490(angle) * dz;
        if (i < 8) {
            record->unk10.z = 90.0f - t * 12.857142f;
        }
        HuPrcVSleep();
    }
    for (i = 0; i < 6; i++) {
        hari->unk28.y = hariY + func_800B7890_B8490(i * 18.0f) * 10.0f;
        HuPrcVSleep();
    }
    PlaySound(D_800CD52C_CE12C == 1 ? 0xC1 : 0x320);
    func_80029E80_2AA80(model, 1, 0);
    HuPrcSleep(10);
}

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
