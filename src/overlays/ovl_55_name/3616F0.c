#include "ovl_55.h"

void func_80102800_3616F0_name_55(void) {
    omObjData* obj;

    omInitObjMan(40, 12);
    func_80079128_79D28();
    D_8010C570_36B460_name_55 = 0;
    func_80018E30_19A30(1);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_80050A30_51630(D_01164160);
    MBModelInit();
    func_8005E2B8_5EEB8();
    func_800593C0_59FC0();
    func_800581A0_58DA0();
    func_8005965C_5A25C();
    func_80046238_46E38();
    func_80079464_7A064();
    func_80088640_89240();
    omAddPrcObj(func_80102968_361858_name_55, 0x5000, 0x2000, 0);
    omAddObj(1000, 0, 0, -1, func_80102AB4_3619A4_name_55);
    obj = omAddObj(900, 0, 0, -1, func_801029F4_3618E4_name_55);
    D_8010C568_36B458_name_55 = obj;
    obj->work[0] = 0;
    D_8010C58A_36B47A_name_55 = GwSystem.current_board_index;
}

void func_80102968_361858_name_55(void) {
    func_80102B58_361A48_name_55();
    if (D_8010C58A_36B47A_name_55 != 6) {
        func_80103D08_362BF8_name_55();
    }
    func_80103D94_362C84_name_55();
    func_80104B1C_363A0C_name_55();
    func_80105074_363F64_name_55();
    func_800794A8_7A0A8(40);
    InitFadeOut(0, 20);
    HuPrcSleep(20);
    func_80102AE0_3619D0_name_55();
    omOvlKill();
    while (TRUE) {
        HuPrcVSleep();
    }
}

void func_801029F4_3618E4_name_55(omObjData* obj) {
    s32 i;

    if (_CheckFlag(D_8010B764_36A654_name_55[D_8010C58A_36B47A_name_55]) && D_8010B762_36A652_name_55 != 0) {
        for (i = 0; i < 4; i++) {
            if (!(gPlayers[i].flags & 1) && (ContBtnTrg[gPlayers[i].port] & 0x1000)) {
                obj->work[0] = 1;
            }
        }
    }
}

void func_80102AB4_3619A4_name_55(omObjData* obj) {
    if (D_801011FC_101DFC != 0) {
        func_80102AE0_3619D0_name_55();
    }
}

void func_80102AE0_3619D0_name_55(void) {
    MBDBackKill();
    func_80050AE0_516E0();
    func_80047B78_48778();
    if (D_8010C58A_36B47A_name_55 == 5) {
        func_8010B3B4_36A2A4_name_55();
    }
    func_80059400_5A000();
    func_8008CE5C_8DA5C();
    if (D_8010B750_36A640_name_55 != 0) {
        func_8005FF9C_60B9C();
    }
    omOvlReturnEx(1);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3616F0", func_80102B58_361A48_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3616F0", func_80102F34_361E24_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3616F0", func_8010308C_361F7C_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3616F0", func_801036B4_3625A4_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3616F0", func_8010390C_3627FC_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3616F0", func_80103D08_362BF8_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3616F0", func_80103D94_362C84_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3616F0", func_80104B1C_363A0C_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3616F0", func_80105074_363F64_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3616F0", func_80105284_364174_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3616F0", func_80105328_364218_name_55);

__asm__(".section .rodata");
const u32 D_8010C4F0_36B3E0_name_55[3] = { 0x3F800000, 0x00000000, 0x00000000 };

__asm__(".section .rodata");
const u32 D_8010C4FC_36B3EC_name_55[3] = { 0x00000000, 0x42C80000, 0x44FA0000 };

__asm__(".section .rodata");
const u32 D_8010C508_36B3F8_name_55[6] = { 0x00000000, 0x42C80000, 0xC4610000, 0x00000000, 0x00000000, 0x00000000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3616F0", func_801053B0_3642A0_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3616F0", func_801054B4_3643A4_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3616F0", func_801055A4_364494_name_55);
