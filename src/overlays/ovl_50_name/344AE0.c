#include "common.h"
#include "ovl_50.h"

void func_80104280_344AE0_name_50(void) {
    D_8010105C_101C5C = D_80101300_101F00 = 0.85f;
    func_8005E260_5EE60(D_8011275A_352FBA_name_50);
    func_80020D20_21920(0x10);
    func_801044DC_344D3C_name_50();
    func_80105900_346160_name_50();
    func_80105E58_3466B8_name_50();
    func_80106A90_3472F0_name_50();
    func_80106CF8_347558_name_50();
    func_80106FDC_34783C_name_50();
    func_801077E0_348040_name_50();
    func_80107A3C_34829C_name_50();
    func_8010804C_3488AC_name_50();
    D_8010105C_101C5C = D_80101300_101F00 = 1.0f;
}

/* Board 2's setup: only the winner's player model, and the host's (D_8011274C). */
void func_80104324_344B84_name_50(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (i == D_8011275A_352FBA_name_50) {
            MBPlayerModelCreate(i, D_80111C88_3524E8_name_50[gPlayers[i].character], 2);
            func_8005ABC0_5B7C0(&gPlayers[i], 2, 0);
            func_80043DAC_449AC(OVL50_PLAYER_MODEL(i));
            gPlayers[i].flags |= 2;
            MBMotionSet(OVL50_PLAYER_MODEL(i), 0, 2);
            if (D_8011275A_352FBA_name_50 == i) {
                func_8002D1EC_2DDEC(*OVL50_PLAYER_MODEL(i)->obj->model, 1);
            }
            MBModelDispOff(OVL50_PLAYER_MODEL(i));
        }
    }
    D_8011274C_352FAC_name_50 = MBModelFileCreate(0x80028, 13, 0.8f, 0.8f, D_80111CA0_352500_name_50);
    func_8005AB50_5B750(D_8011274C_352FAC_name_50, 2, 8, D_80111D00_352560_name_50);
    func_8002D1EC_2DDEC(*D_8011274C_352FAC_name_50->obj->model, 1);
    MBModelDispOff(D_8011274C_352FAC_name_50);
}

__asm__(".section .rodata");
const char D_801124F0_352D50_name_50[16] = "item_hook";

__asm__(".section .rodata");
const char D_80112500_352D60_name_50[] = "c005_000-bmerge4";

__asm__(".section .rodata");
const char D_80112514_352D74_name_50[] = "Luigi1-migi-te1_2";

__asm__(".section .rodata");
const char D_80112528_352D88_name_50[] = "c003_000-bmerge1_13_1";

__asm__(".section .rodata");
const char D_80112540_352DA0_name_50[] = "C002_000b-bmerge14";

__asm__(".section .rodata");
const char D_80112554_352DB4_name_50[] = "c001_000-migi-te2_2";

__asm__(".section .rodata");
const char D_80112568_352DC8_name_50[16] = "migi-te2_4";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_801044DC_344D3C_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_80105900_346160_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_80105E58_3466B8_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_80106A90_3472F0_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_80106CF8_347558_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_80106FDC_34783C_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_801077E0_348040_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_80107A3C_34829C_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_8010804C_3488AC_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_80108290_348AF0_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_80108414_348C74_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_80108448_348CA8_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_801085FC_348E5C_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_80108630_348E90_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_801087FC_34905C_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_80108830_349090_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_801089CC_34922C_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_80108A00_349260_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_80108C6C_3494CC_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_80108F1C_34977C_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_80108F2C_34978C_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_80108F98_3497F8_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_80109070_3498D0_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_801090FC_34995C_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_80109290_349AF0_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_8010A2A4_34AB04_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_8010A580_34ADE0_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_8010A9B8_34B218_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_8010AB4C_34B3AC_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_8010B230_34BA90_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_8010CD24_34D584_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_8010CE28_34D688_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_8010CF08_34D768_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_8010CFE8_34D848_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_8010D198_34D9F8_name_50);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_50_name/344AE0", func_8010D320_34DB80_name_50);
