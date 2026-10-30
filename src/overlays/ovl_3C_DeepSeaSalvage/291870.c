#include "ovl_3C.h"

void func_80102800_291870_DeepSeaSalvage(void) {
    omObjData* obj;
    s16 i;
    u8 cam;

    func_8002D4D0_2E0D0(1);
    func_80020D20_21920(0x60);
    omInitObjMan(0x40, 0);
    func_80079128_79D28();
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_80079E60_7AA60), 0xA0);
    func_80018E30_19A30(1);
    cam = func_80018E78_19A78();
    ScissorSet(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 10.0f, 2000.0f, 32000.0f);
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    D_80108820_297890_DeepSeaSalvage = 0;
    D_80108822_297892_DeepSeaSalvage = 65;
    D_80108826_297896_DeepSeaSalvage = 0;
    D_80108824_297894_DeepSeaSalvage = 1;
    D_80108828_297898_DeepSeaSalvage = 900;
    D_8010882A_29789A_DeepSeaSalvage = _CheckFlag(0xC);
    D_80108832_2978A2_DeepSeaSalvage = 0;
    D_80108830_2978A0_DeepSeaSalvage = 0;
    D_8010882E_29789E_DeepSeaSalvage = 0;
    D_8010882C_29789C_DeepSeaSalvage = 0;
    func_80105EB0_294F20_DeepSeaSalvage();
    func_80106F08_295F78_DeepSeaSalvage();
    func_80105F14_294F84_DeepSeaSalvage();
    D_8010A7E0_299850_DeepSeaSalvage = omAddObj(10, 0, 0, -1, func_80102B48_291BB8_DeepSeaSalvage);
    obj = omAddObj(0, 3, 0, -1, func_80102FBC_29202C_DeepSeaSalvage);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = obj;
    omSetStatBit(obj, 0xA0);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(1, 6, 0, -1, func_80103180_2921F0_DeepSeaSalvage);
    for (i = 0; i < 4; i++) {
        D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(3, 2, 50, -1, func_801031CC_29223C_DeepSeaSalvage);
    }
    D_80109CD0_298D40_DeepSeaSalvage = omAddObj(4, 2, 3, -1, func_80103DCC_292E3C_DeepSeaSalvage);
    func_801043A4_293414_DeepSeaSalvage();
    func_80026DAC_279AC(0, 128, 128, 128);
    func_80026DAC_279AC(1, 255, 255, 255);
    func_80026E00_27A00(1, 0.0f, 128.0f, 128.0f);
    omAddObj(9, 0, 0, -1, func_801058A0_294910_DeepSeaSalvage);
}

void func_80102B48_291BB8_DeepSeaSalvage(omObjData* obj) {
    obj->func_ptr = func_80102B74_291BE4_DeepSeaSalvage;
    InitFadeIn(0, 16);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_80102B74_291BE4_DeepSeaSalvage);

void func_80102E7C_291EEC_DeepSeaSalvage(void) {
    if (D_80108826_297896_DeepSeaSalvage < 0 && func_8008F618_90218() == 0) {
        func_80106048_2950B8_DeepSeaSalvage();
        func_80079464_7A064();
        omOvlReturnEx(1);
    }
}

void func_80102EC8_291F38_DeepSeaSalvage(omObjData* obj) {
    func_800691FC_69DFC(10, (s16)(D_80108828_297898_DeepSeaSalvage / 30), 160, 24);
    obj->func_ptr = func_80102F3C_291FAC_DeepSeaSalvage;
}

void func_80102F3C_291FAC_DeepSeaSalvage(omObjData* obj) {
    func_8006D4D0_6E0D0((s16)((D_80108828_297898_DeepSeaSalvage + 29) / 30));
    if (D_80108828_297898_DeepSeaSalvage == 0 || D_80108826_297896_DeepSeaSalvage != 0) {
        obj->func_ptr = NULL;
        func_8006D518_6E118();
    }
}

/* The backdrop: two models from D_80108424 placed by D_8010842C (the first through the object).
   NON_MATCHING: GCC keeps &D_8010842C in a register for the first model's six reads, retail
   addresses each by %hi/%lo (masked 35, addressing and registers only). */
#ifdef NON_MATCHING
void func_80102FBC_29202C_DeepSeaSalvage(omObjData* obj) {
    s16 i;

    for (i = 0; (u16)i < 2; i++) {
        obj->model[i] = func_80018A30_19630(D_80108424_297494_DeepSeaSalvage[i], 0x2D9);
        if (i == 0) {
            obj->trans.x = D_8010842C_29749C_DeepSeaSalvage[0][0];
            obj->trans.y = D_8010842C_29749C_DeepSeaSalvage[0][1];
            obj->trans.z = D_8010842C_29749C_DeepSeaSalvage[0][2];
            obj->scale.x = D_8010842C_29749C_DeepSeaSalvage[0][3];
            obj->scale.y = D_8010842C_29749C_DeepSeaSalvage[0][4];
            obj->scale.z = D_8010842C_29749C_DeepSeaSalvage[0][5];
        } else {
            func_80029714_2A314(obj->model[i], D_8010842C_29749C_DeepSeaSalvage[i][0],
                                D_8010842C_29749C_DeepSeaSalvage[i][1], D_8010842C_29749C_DeepSeaSalvage[i][2]);
            func_800297E8_2A3E8(obj->model[i], D_8010842C_29749C_DeepSeaSalvage[i][3],
                                D_8010842C_29749C_DeepSeaSalvage[i][4], D_8010842C_29749C_DeepSeaSalvage[i][5]);
        }
    }
    func_8010819C_29720C_DeepSeaSalvage(obj);
    obj->func_ptr = func_80103164_2921D4_DeepSeaSalvage;
    D_801088C8_297938_DeepSeaSalvage.x = D_801088C8_297938_DeepSeaSalvage.y = D_801088C8_297938_DeepSeaSalvage.z = 0.0f;
    D_801088D4_297944_DeepSeaSalvage.x = D_801088D4_297944_DeepSeaSalvage.y = D_801088D4_297944_DeepSeaSalvage.z = 1.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_80102FBC_29202C_DeepSeaSalvage);
#endif

void func_80103164_2921D4_DeepSeaSalvage(omObjData* obj) {
    func_801081EC_29725C_DeepSeaSalvage(obj);
}

void func_80103180_2921F0_DeepSeaSalvage(omObjData* obj) {
    obj->model[0] = LoadFormFile(0x4C000C, 0x299);
    func_801074E0_296550_DeepSeaSalvage(obj);
    obj->func_ptr = func_80107A10_296A80_DeepSeaSalvage;
}

__asm__(".section .rodata");
const char D_80108678_2976E8_DeepSeaSalvage[] = "c005_000-bmerge1";

__asm__(".section .rodata");
const char D_8010868C_2976FC_DeepSeaSalvage[] = "Luigi1-atama_1";

__asm__(".section .rodata");
const char D_8010869C_29770C_DeepSeaSalvage[] = "c003_000-head_1";

__asm__(".section .rodata");
const char D_801086AC_29771C_DeepSeaSalvage[] = "C002_000b-bmerge10_1";

__asm__(".section .rodata");
const char D_801086C4_297734_DeepSeaSalvage[] = "c001_000-atama_2";

__asm__(".section .rodata");
const char D_801086D8_297748_DeepSeaSalvage[] = "atama_2";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_801031CC_29223C_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_80103480_2924F0_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_80103508_292578_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_80103DCC_292E3C_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_80104070_2930E0_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_801043A4_293414_DeepSeaSalvage);

__asm__(".section .rodata");
const u32 D_80108730_2977A0_DeepSeaSalvage[2] = { 0x03050609, 0x0A0C0000 };

__asm__(".section .rodata");
const u32 D_80108738_2977A8_DeepSeaSalvage[2] = { 0x01020408, 0x01020408 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_801044A8_293518_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_80104944_2939B4_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_80104A70_293AE0_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_80105258_2942C8_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_801052E8_294358_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_8010536C_2943DC_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_801056FC_29476C_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_80105804_294874_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_801058A0_294910_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_80105BB8_294C28_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_80105E84_294EF4_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_80105EB0_294F20_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_80105F14_294F84_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_80105F5C_294FCC_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_80106048_2950B8_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_801060C8_295138_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_80106100_295170_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_80106134_2951A4_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_801061CC_29523C_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_80106518_295588_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_801069E4_295A54_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_80106CC4_295D34_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_80106D5C_295DCC_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_80106EC4_295F34_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_80106F08_295F78_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_801070D0_296140_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_801072C0_296330_DeepSeaSalvage);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_80107318_296388_DeepSeaSalvage);
