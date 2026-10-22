#include "common.h"
#include "ovl_01.h"

/* Scene setup: camera, lights, the reel/sprite work buffers and the flow object. */
void func_80102800_DA290_BowserSlots(void) {
    u8 cam;

    func_8002D4D0_2E0D0(50);
    omInitObjMan(50, 0);
    func_80079128_79D28();
    func_80020D20_21920(64);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_80079E60_7AA60), 0xA0);
    func_80026DAC_279AC(0, 255, 255, 255);
    func_80026DAC_279AC(1, 255, 255, 255);
    func_80026E00_27A00(1, -56.0f, 50.0f, 56.0f);
    func_80018E30_19A30(1);
    cam = func_80018E78_19A78();
    ScissorSet(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 30.0f, 80.0f, 4000.0f);
    func_80103000_DAA90_BowserSlots();
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    D_800FA606_FB206 = 0;
    D_8010C058_E3AE8_BowserSlots = 0;
    D_8010C05A_E3AEA_BowserSlots = 0;
    D_8010C040_E3AD0_BowserSlots = 0;
    D_8010C0D0_E3B60_BowserSlots = func_80027154_27D54(0xB4, D_800FA1AA_FADAA);
    func_800B0EF0_B1AF0(D_8010C0D0_E3B60_BowserSlots, 0, 0xB4);
    D_8010C174_E3C04_BowserSlots = func_80027154_27D54(0x1B0, D_800FA1AA_FADAA);
    func_800B0EF0_B1AF0(D_8010C174_E3C04_BowserSlots, 0, 0x1B0);
    D_8010C170_E3C00_BowserSlots = func_80027154_27D54(0x300, D_800FA1AA_FADAA);
    func_800B0EF0_B1AF0(D_8010C170_E3C00_BowserSlots, 0, 0x300);
    D_8010C17E_E3C0E_BowserSlots = 1;
    D_8010C180_E3C10_BowserSlots = -1;
    D_8010C18E_E3C1E_BowserSlots = -1;
    D_800F8FD0_F9BD0 = 0;
    D_8010C030_E3AC0_BowserSlots = omAddObj(0x20, 0, 0, -1, func_80102A70_DA500_BowserSlots);
    func_8007273C_7333C("\x82\x72\x82\x73\x82\x60\x82\x71\x82\x73", 1); /* SJIS "START" */
    func_8007273C_7333C("\x82\x65\x82\x68\x82\x6D\x82\x68\x82\x72\x82\x67", 1); /* SJIS "FINISH" */
    func_8007273C_7333C("\x82\x68\x82\x73\x82\x64\x82\x6C\x82\x66\x82\x64\x82\x73\x81\x49\x81\x48", 1); /* SJIS "ITEMGET!?" */
}

void func_80102A70_DA500_BowserSlots(omObjData* obj) {
    obj->func_ptr = func_80102ACC_DA55C_BowserSlots;
    func_8010A0B8_E1B48_BowserSlots();
    func_80103D84_DB814_BowserSlots();
    func_8010475C_DC1EC_BowserSlots();
    func_8010A1F4_E1C84_BowserSlots();
    if (_CheckFlag(0xC) != 0) {
        D_8010C058_E3AE8_BowserSlots = 1;
    }
    PlayMusic(0x28);
}

/* The flow: start message, wait for the three reels, the result (item won or not), fade out. */
void func_80102ACC_DA55C_BowserSlots(omObjData* obj) {
    func_80102F58_DA9E8_BowserSlots(obj);
    func_8010A53C_E1FCC_BowserSlots();
    switch (D_8010B7BC_E324C_BowserSlots) {
        case 0:
            if (func_8008F618_90218() == 0) {
                func_80106084_DDB14_BowserSlots();
                D_8010B7BC_E324C_BowserSlots++;
            }
            break;
        case 1:
            if (func_801067A4_DE234_BowserSlots() != 0) {
                func_800691FC_69DFC(0);
                D_8010B7BC_E324C_BowserSlots++;
            }
            break;
        case 2:
            if (func_80069538_6A138() == 0) {
                D_800F8FD0_F9BD0 = 1;
                D_8010B7BC_E324C_BowserSlots++;
            }
            break;
        case 3:
            if (func_801067DC_DE26C_BowserSlots() != 0) {
                D_800F8FD0_F9BD0 = 0;
                func_800691FC_69DFC(3);
                func_800794A8_7A0A8(40);
                D_8010B7BC_E324C_BowserSlots++;
            } else if (func_800153CC_15FCC(0x127) == -1) {
                D_8010C18E_E3C1E_BowserSlots = func_80079798_7A398(0x127, 0);
            }
            break;
        case 4:
            if (func_80069538_6A138() == 0) {
                if (D_8010C0E0_E3B70_BowserSlots != -1) {
                    func_801060A4_DDB34_BowserSlots();
                }
                D_8010B7C0_E3250_BowserSlots = 0;
                D_8010B7BC_E324C_BowserSlots++;
            }
            break;
        case 5:
            if (D_8010B7C0_E3250_BowserSlots >= 3) {
                if (D_8010C0E0_E3B70_BowserSlots != -1) {
                    gPlayers[D_8010C05C_E3AEC_BowserSlots].coins_mg_bonus = func_8010770C_DF19C_BowserSlots(D_8010C0E0_E3B70_BowserSlots);
                    func_801076EC_DF17C_BowserSlots();
                } else {
                    gPlayers[D_8010C05C_E3AEC_BowserSlots].coins_mg_bonus = -1;
                    func_801060A4_DDB34_BowserSlots();
                }
                D_8010B7C0_E3250_BowserSlots = 0;
                D_8010B7BC_E324C_BowserSlots++;
            }
            break;
        case 6:
            if (D_8010C0E0_E3B70_BowserSlots != -1) {
                if (func_8010770C_DF19C_BowserSlots(D_8010C0E0_E3B70_BowserSlots) != 3) {
                    if (D_8010B7C0_E3250_BowserSlots >= 60) {
                        D_8010C190_E3C20_BowserSlots = 0x26;
                        func_80025384_25F84(D_800FFFD8_100BD8[0]->model[0], 1, D_8010C062_E3AF2_BowserSlots, D_8010B78C_E321C_BowserSlots[D_8010C060_E3AF0_BowserSlots]);
                        PlayMusic(0x53);
                        func_800732B0_73EB0(D_8010C048_E3AD8_BowserSlots[0]);
                        func_800691FC_69DFC(0x17);
                        D_8010B7C0_E3250_BowserSlots = 0;
                        D_8010B7BC_E324C_BowserSlots++;
                        D_8010B7C4_E3254_BowserSlots = 135;
                    }
                } else if (D_8010B7C0_E3250_BowserSlots >= 75.0) {
                    D_8010C190_E3C20_BowserSlots = 0x28;
                    func_80025384_25F84(D_800FFFD8_100BD8[0]->model[0], 1, D_8010C062_E3AF2_BowserSlots, D_8010B7A4_E3234_BowserSlots[D_8010C060_E3AF0_BowserSlots]);
                    PlayMusic(0x54);
                    func_800691FC_69DFC(0x18);
                    D_8010B7C0_E3250_BowserSlots = 0;
                    D_8010B7BC_E324C_BowserSlots++;
                    D_8010B7C4_E3254_BowserSlots = 144;
                }
            } else if (D_8010B7C0_E3250_BowserSlots >= 3) {
                D_8010C190_E3C20_BowserSlots = 0x29;
                func_80025384_25F84(D_800FFFD8_100BD8[0]->model[0], 1, D_8010C062_E3AF2_BowserSlots, D_8010B7A4_E3234_BowserSlots[D_8010C060_E3AF0_BowserSlots]);
                PlayMusic(0x56);
                func_80106110_DDBA0_BowserSlots();
                func_800691FC_69DFC(0x10);
                D_8010B7C0_E3250_BowserSlots = 0;
                D_8010B7BC_E324C_BowserSlots++;
                D_8010B7C4_E3254_BowserSlots = 132;
            }
            break;
        case 7:
            if (D_8010B7C4_E3254_BowserSlots <= 0) {
                InitFadeOut(0, 20);
                D_8010B7BC_E324C_BowserSlots++;
            } else {
                D_8010B7C4_E3254_BowserSlots--;
            }
            break;
        case 8:
            if (func_8008F618_90218() == 0) {
                obj->func_ptr = func_80102F34_DA9C4_BowserSlots;
                D_8010B7BC_E324C_BowserSlots++;
            }
            break;
    }
    D_8010B7C0_E3250_BowserSlots = (D_8010B7C0_E3250_BowserSlots + 1) & 0x7FFF;
    D_8010C040_E3AD0_BowserSlots = (D_8010C040_E3AD0_BowserSlots + 1) & 0x7FFF;
}

void func_80102F34_DA9C4_BowserSlots(omObjData* obj) {
    func_80079464_7A064();
    omOvlReturnEx(1);
}

/* Debug exit (D_801011FC == 1): fade out and return. */
void func_80102F58_DA9E8_BowserSlots(omObjData* obj) {
    if (D_8010B7C8_E3258_BowserSlots != 0) {
        if (D_8010B7C8_E3258_BowserSlots == 1) {
            obj->func_ptr = func_80102F34_DA9C4_BowserSlots;
        }
        D_8010B7C8_E3258_BowserSlots--;
        return;
    }
    if (D_801011FC_101DFC == 1 && func_8008F618_90218() == 0) {
        D_8010B7C8_E3258_BowserSlots = 20;
        InitFadeOut(0, (s16)D_8010B7C8_E3258_BowserSlots);
        func_800794A8_7A0A8((s16)D_8010B7C8_E3258_BowserSlots);
        func_80079614_7A214((s16)D_8010B7C8_E3258_BowserSlots);
    }
}

/* Camera start position; the blend object 801038FC. */
void func_80103000_DAA90_BowserSlots(void) {
    D_8010274C_10334C.x = 0.0f;
    D_8010274C_10334C.y = 427.2f;
    D_8010274C_10334C.z = 14.2f;
    D_800FD474_FE074.x = 2.25f;
    D_800FD474_FE074.y = 0.0f;
    D_800FD474_FE074.z = 0.0f;
    D_800FA610_FB210 = 1890.0f;
    func_8010B1D4_E2C64_BowserSlots(&D_800FD474_FE074);
    func_80103A9C_DB52C_BowserSlots(0);
    func_80103A9C_DB52C_BowserSlots(1);
    D_8010C0C4_E3B54_BowserSlots = 0;
    D_8010C0C0_E3B50_BowserSlots = 0;
    omAddObj(0x1F, 0, 0, -1, func_801038FC_DB38C_BowserSlots);
}

__asm__(".section .rodata");
const u32 D_8010BAE0_E3570_BowserSlots[9] = { 0 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_801030C0_DAB50_BowserSlots);

__asm__(".section .rodata");
const char D_8010BB18_E35A8_BowserSlots[] = " CENTER X>%3.3f Y>%3.3f Z>%3.3f ";

__asm__(".section .rodata");
const char D_8010BB3C_E35CC_BowserSlots[] = " ROT    X>%3.3f Y>%3.3f Z>%3.3f ";

__asm__(".section .rodata");
const char D_8010BB60_E35F0_BowserSlots[] = " ZOOM   %3.3f ";

__asm__(".section .rodata");
const char D_8010BB70_E3600_BowserSlots[] = "CAMERA TEST_MODE ";

__asm__(".section .rodata");
const char D_8010BB84_E3614_BowserSlots[] = "CAMERA TEST_MODE \012";

__asm__(".section .rodata");
const char D_8010BB98_E3628_BowserSlots[] = " CENTER X>%3.3f Y>%3.3f Z>%3.3f \012";

__asm__(".section .rodata");
const char D_8010BBBC_E364C_BowserSlots[] = " ROT    X>%3.3f Y>%3.3f Z>%3.3f \012";

__asm__(".section .rodata");
const char D_8010BBE0_E3670_BowserSlots[] = " ZOOM   %3.3f \012\012";

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010BBF8_E3688_BowserSlots[2] = { 0x3FC00000, 0x00000000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_801038FC_DB38C_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80103A9C_DB52C_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80103B4C_DB5DC_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80103D84_DB814_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80103DEC_DB87C_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80104460_DBEF0_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80104520_DBFB0_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_8010475C_DC1EC_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80104834_DC2C4_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80104914_DC3A4_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80104BAC_DC63C_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80104DDC_DC86C_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80105034_DCAC4_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80105088_DCB18_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_801054E8_DCF78_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80105568_DCFF8_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80105AE4_DD574_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80105C28_DD6B8_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80105D5C_DD7EC_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80106084_DDB14_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_801060A4_DDB34_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_801060F0_DDB80_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80106110_DDBA0_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80106148_DDBD8_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80106254_DDCE4_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_801063CC_DDE5C_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_8010648C_DDF1C_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80106524_DDFB4_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_801065D8_DE068_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80106638_DE0C8_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80106750_DE1E0_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_801067A4_DE234_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_801067DC_DE26C_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80106820_DE2B0_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80106B30_DE5C0_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_801076EC_DF17C_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_8010770C_DF19C_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80107740_DF1D0_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_801078F0_DF380_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_801079B8_DF448_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80107BCC_DF65C_BowserSlots);

__asm__(".section .rodata");
const u32 D_8010BE08_E3898_BowserSlots[8] = { 0x00000001, 0x00000001, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80107D68_DF7F8_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_8010879C_E022C_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80108EE4_E0974_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80109AF8_E1588_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80109BC8_E1658_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_80109C5C_E16EC_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_8010A074_E1B04_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_8010A0B8_E1B48_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_8010A0EC_E1B7C_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_8010A138_E1BC8_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_8010A1F4_E1C84_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_8010A3CC_E1E5C_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_8010A53C_E1FCC_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_8010B148_E2BD8_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_8010B1D4_E2C64_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_8010B2FC_E2D8C_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_8010B38C_E2E1C_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_8010B43C_E2ECC_BowserSlots);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_01_BowserSlots/DA290", func_8010B60C_E309C_BowserSlots);
