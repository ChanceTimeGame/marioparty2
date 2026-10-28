#include "ovl_58.h"

/* Entry: camera, lights, the setup and its processes; the stage from the board index or the
   mode (D_800CD414: 0 free play, 3 uses the saved record). */
void func_80102800_36DF00_MinigameParkSetup(void) {
    func_80020070_20C70(1);
    func_8002D4D0_2E0D0(1);
    func_80020D20_21920(25);
    omInitObjMan(51, 25);
    func_80088640_89240();
    func_80079128_79D28();
    D_801135C0_37ECC0_MinigameParkSetup = 49.0f;
    D_80113E24_37F524_MinigameParkSetup = 80.0f;
    D_80113BF4_37F2F4_MinigameParkSetup = 8000.0f;
    Hu3DCamSetPerspective(0, 49.0f, 80.0f, 8000.0f);
    omAddObj(10000, 0, 0, -1, func_801109C8_37C0C8_MinigameParkSetup);
    func_80026D28_27928(3);
    func_80026DAC_279AC(2, 0, 0, 0);
    func_80026E00_27A00(2, 0.0f, 0.0f, 100.0f);
    func_80026DAC_279AC(3, 100, 100, 100);
    func_80026E00_27A00(3, 0.0f, 100.0f, 0.0f);
    omAddPrcObj(func_80102CAC_36E3AC_MinigameParkSetup, 0x3F00, 0x1800, 0);
    omPrcSetStatBit(omAddPrcObj(func_80111D8C_37D48C_MinigameParkSetup, 0x1100, 0x800, 0), 0xA0);
    InitFadeIn(255, 16);
    PlayMusic(7);
    func_80029708_2A308(1);
    func_8002CA48_2D648(0, 0, 0);
    D_80113870_37EF70_MinigameParkSetup = D_80112B4C_37E24C_MinigameParkSetup;
    D_8011381A_37EF1A_MinigameParkSetup = D_800FD80C_FE40C;
    if (D_800CD414_CE014 == 0) {
        D_80113814_37EF14_MinigameParkSetup = GwSystem.current_board_index;
        if (D_80113814_37EF14_MinigameParkSetup == 8) {
            D_80113814_37EF14_MinigameParkSetup = 7;
        }
    } else if (D_800CD414_CE014 == 3) {
        D_80113814_37EF14_MinigameParkSetup = 6;
        GwSystem.current_board_index = 7;
        func_8007E128_7ED28();
        func_8007E0F8_7ECF8(D_800FD420_FE020);
    } else {
        D_80113814_37EF14_MinigameParkSetup = 6;
        GwSystem.current_board_index = 0;
    }
    func_80112950_37E050_MinigameParkSetup();
    D_8011381E_37EF1E_MinigameParkSetup = 0x73;
    D_80113820_37EF20_MinigameParkSetup = 0;
    D_8011381C_37EF1C_MinigameParkSetup = 0;
    D_80113822_37EF22_MinigameParkSetup = 0;
    _ClearFlag(0xC);
    func_80075424_76024(4);
    func_8007550C_7610C(4);
}

/* Reset the setup: inserted pads first (in port order), then the free ports; each player
   starts as its own character. */
void func_80102A60_36E160_MinigameParkSetup(void) {
    s16 i;
    s16 j;
    s16 port;
    s16 n;

    D_80113784_37EE84_MinigameParkSetup = 0;
    D_80113780_37EE80_MinigameParkSetup = 0;
    D_80113782_37EE82_MinigameParkSetup = 0;
    D_80113786_37EE86_MinigameParkSetup = 0;
    D_80113788_37EE88_MinigameParkSetup = 0;
    for (i = 0; i < 4; i++) {
        D_80113958_37F058_MinigameParkSetup.port[i] = 0xFF;
    }
    for (i = 0, n = 0; i < 4; i++) {
        if (HuGetPadInserted(i) != 0) {
            D_80113958_37F058_MinigameParkSetup.port[n] = i;
            n++;
        }
        D_80113958_37F058_MinigameParkSetup.character[i] = i;
        D_80113958_37F058_MinigameParkSetup.cpuLevel[i] = 0xFF;
    }
    for (i = 0; i < 4; i++) {
        if (D_80113958_37F058_MinigameParkSetup.port[i] == 0xFF) {
            for (port = 0; port < 4; port++) {
                for (j = 0; j < 4; j++) {
                    if (D_80113958_37F058_MinigameParkSetup.port[j] == port) {
                        break;
                    }
                }
                if (j == 4) {
                    break;
                }
            }
            if (port == 4) {
                osSyncPrintf("pad Error\n");
            }
            D_80113958_37F058_MinigameParkSetup.port[i] = port;
        }
    }
    D_80113958_37F058_MinigameParkSetup.gameLength = 0;
    D_80113958_37F058_MinigameParkSetup.bonus = 0;
    D_80113958_37F058_MinigameParkSetup.padCount = n;
    D_8011381A_37EF1A_MinigameParkSetup = D_80113958_37F058_MinigameParkSetup.port[0];
    for (i = 0; i < 4; i++) {
        D_80113958_37F058_MinigameParkSetup.handicap[i] = 0;
    }
    D_80113816_37EF16_MinigameParkSetup = -1;
}

/* The setup process: scene, panels, then the mode's setup loop. */
void func_80102CAC_36E3AC_MinigameParkSetup(void) {
    s16 i;

    func_80102A60_36E160_MinigameParkSetup();
    D_80112BBC_37E2BC_MinigameParkSetup[0x50] = D_80113364_37EA64_MinigameParkSetup[D_80113814_37EF14_MinigameParkSetup];
    D_80112BBC_37E2BC_MinigameParkSetup[0x6E] = D_80113384_37EA84_MinigameParkSetup[D_80113814_37EF14_MinigameParkSetup];
    func_80112360_37DA60_MinigameParkSetup(D_80112BBC_37E2BC_MinigameParkSetup);
    func_80110AF0_37C1F0_MinigameParkSetup(0);
    omAddPrcObj(func_80111328_37CA28_MinigameParkSetup, 0x3F00, 0x800, 0);
    func_80111744_37CE44_MinigameParkSetup(&D_80113798_37EE98_MinigameParkSetup);
    D_80113800_37EF00_MinigameParkSetup = 0;
    for (i = 0; i < 5; i++) {
        D_801137B8_37EEB8_MinigameParkSetup[i] = omAddPrcObj(func_80106AF8_3721F8_MinigameParkSetup, 0x3F00, 0x800, 0);
    }
    D_80113802_37EF02_MinigameParkSetup = 0;
    for (i = 0; i < 6; i++) {
        omAddPrcObj(func_80107180_372880_MinigameParkSetup, 0x3F00, 0x800, 0);
    }
    omAddPrcObj(func_80108C0C_37430C_MinigameParkSetup, 0x3F00, 0x800, 0);
    omAddPrcObj(func_8010903C_37473C_MinigameParkSetup, 0x3F00, 0x800, 0);
    omAddPrcObj(func_8010F358_37AA58_MinigameParkSetup, 0x3F00, 0x400, 0);
    HuPrcSleep(20);
    D_80113790_37EE90_MinigameParkSetup = 0;
    omAddPrcObj(func_8010FB00_37B200_MinigameParkSetup, 0x3F00, 0x800, 0);
    while (D_80113790_37EE90_MinigameParkSetup == 0) {
        HuPrcVSleep();
    }
    if (GwSystem.current_board_index == 8) {
        func_8010395C_36F05C_MinigameParkSetup();
    }
    switch (D_800CD414_CE014) {
    case 0:
        func_80102F00_36E600_MinigameParkSetup();
        break;
    case 1:
        func_80103140_36E840_MinigameParkSetup();
        break;
    case 2:
        func_801033E0_36EAE0_MinigameParkSetup();
        break;
    case 3:
        func_80103ABC_36F1BC_MinigameParkSetup();
        break;
    }
}

/* Mode 0's setup steps: players, characters, CPU levels, handicaps, then length/bonus. */
void func_80102F00_36E600_MinigameParkSetup(void) {
    s16 ret;

    func_80110350_37BA50_MinigameParkSetup(0x52);
    func_801103A4_37BAA4_MinigameParkSetup();
    func_80111750_37CE50_MinigameParkSetup(5);
    while (1) {
        switch (D_80113780_37EE80_MinigameParkSetup) {
        case 0:
            func_80110350_37BA50_MinigameParkSetup(0x54);
            func_801103A4_37BAA4_MinigameParkSetup();
            if (func_80103F38_36F638_MinigameParkSetup() != 0) {
                D_80113780_37EE80_MinigameParkSetup++;
                D_80113782_37EE82_MinigameParkSetup = 0;
            } else {
                func_80110350_37BA50_MinigameParkSetup(0x53);
                if (func_801103A4_37BAA4_MinigameParkSetup() != 0) {
                    D_80113780_37EE80_MinigameParkSetup = 0;
                    D_80113782_37EE82_MinigameParkSetup = 0;
                } else {
                    func_8010ED54_37A454_MinigameParkSetup();
                }
            }
            break;
        case 1:
            func_80110350_37BA50_MinigameParkSetup(0x59);
            func_801103A4_37BAA4_MinigameParkSetup();
            if (func_801052B4_3709B4_MinigameParkSetup() != 0) {
                if (D_80113958_37F058_MinigameParkSetup.unk11 == 0) {
                    D_80113780_37EE80_MinigameParkSetup += 2;
                } else {
                    D_80113780_37EE80_MinigameParkSetup++;
                }
                D_80113782_37EE82_MinigameParkSetup = 0;
            } else {
                D_80113780_37EE80_MinigameParkSetup--;
                D_80113782_37EE82_MinigameParkSetup = 1;
            }
            break;
        case 2:
            if (func_80107644_372D44_MinigameParkSetup(3) != 0) {
                D_80113780_37EE80_MinigameParkSetup++;
                D_80113782_37EE82_MinigameParkSetup = 0;
            } else {
                D_80113780_37EE80_MinigameParkSetup--;
                D_80113782_37EE82_MinigameParkSetup = 1;
            }
            break;
        case 3:
            func_80110350_37BA50_MinigameParkSetup(0x69);
            func_801103A4_37BAA4_MinigameParkSetup();
            if (func_80109478_374B78_MinigameParkSetup() != 0) {
                D_80113780_37EE80_MinigameParkSetup++;
                D_80113782_37EE82_MinigameParkSetup = 0;
            } else {
                if (D_80113958_37F058_MinigameParkSetup.humans == 4) {
                    D_80113780_37EE80_MinigameParkSetup--;
                }
                D_80113780_37EE80_MinigameParkSetup--;
                D_80113782_37EE82_MinigameParkSetup = 1;
            }
            break;
        case 4:
            if (D_80113782_37EE82_MinigameParkSetup == 0) {
                func_80110350_37BA50_MinigameParkSetup(0x6D);
                func_801103A4_37BAA4_MinigameParkSetup();
            }
            ret = func_8010A1E8_3758E8_MinigameParkSetup();
            if (ret == 1) {
                func_8010F0A4_37A7A4_MinigameParkSetup();
            } else if (ret == -1) {
                D_80113780_37EE80_MinigameParkSetup--;
                D_80113782_37EE82_MinigameParkSetup = 1;
            } else if (D_80113782_37EE82_MinigameParkSetup == 0) {
                func_8010E460_379B60_MinigameParkSetup();
            }
            break;
        }
        HuPrcVSleep();
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80103140_36E840_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_801033E0_36EAE0_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010395C_36F05C_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80103A88_36F188_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80103ABC_36F1BC_MinigameParkSetup);




__asm__(".section .rodata");
const u32 D_80113618_37ED18_MinigameParkSetup[2] = { 0x00020000, 0x00030001 };

__asm__(".section .rodata");
const u32 D_80113620_37ED20_MinigameParkSetup[2] = { 0x00000001, 0x00020003 };

__asm__(".section .rodata");
const char D_80113628_37ED28_MinigameParkSetup[] = "p_panel";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80103F38_36F638_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_801051BC_3708BC_MinigameParkSetup);


__asm__(".section .rodata");
const char D_80113630_37ED30_MinigameParkSetup[] = "c_panel";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_801052B4_3709B4_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80106A00_372100_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80106AB4_3721B4_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80106AF8_3721F8_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80107014_372714_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80107030_372730_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_801070B0_3727B0_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_801070E0_3727E0_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_801070FC_3727FC_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80107118_372818_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80107134_372834_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80107180_372880_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_801074CC_372BCC_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_801075C8_372CC8_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80107604_372D04_MinigameParkSetup);










__asm__(".section .rodata");
const u32 D_80113638_37ED38_MinigameParkSetup[9] = { 0xC2700000, 0x42C30000, 0x41F00000, 0xC2700000, 0x42C30000, 0xC1A00000, 0xC2700000, 0x42C30000, 0xC28C0000 };

__asm__(".section .rodata");
const u32 D_8011365C_37ED5C_MinigameParkSetup[12] = { 0xC2700000, 0x42C30000, 0x428C0000, 0xC2700000, 0x42C30000, 0x41B80000, 0xC2700000, 0x42C30000, 0xC1B80000, 0xC2700000, 0x42C30000, 0xC28C0000 };

__asm__(".section .rodata");
const u32 D_8011368C_37ED8C_MinigameParkSetup[1] = { 0x18000000 };

__asm__(".section .rodata");
const char D_80113690_37ED90_MinigameParkSetup[] = "cl_panel";

__asm__(".section .rodata");
const char D_8011369C_37ED9C_MinigameParkSetup[] = "time30";

__asm__(".section .rodata");
const char D_801136A4_37EDA4_MinigameParkSetup[] = "time10";

__asm__(".section .rodata");
const char D_801136AC_37EDAC_MinigameParkSetup[] = "time50";

__asm__(".section .rodata");
const char D_801136B4_37EDB4_MinigameParkSetup[] = "time35";

__asm__(".section .rodata");
const char D_801136BC_37EDBC_MinigameParkSetup[] = "time20";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80107644_372D44_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80108BA8_3742A8_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80108C0C_37430C_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010903C_37473C_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80109478_374B78_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010A02C_37572C_MinigameParkSetup);


__asm__(".section .rodata");
const char D_801136E8_37EDE8_MinigameParkSetup[] = "bns_panel";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010A1E8_3758E8_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010B6B4_376DB4_MinigameParkSetup);


__asm__(".section .rodata");
const char D_801136F4_37EDF4_MinigameParkSetup[] = "mode_panel";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010B6E8_376DE8_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010C4B4_377BB4_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010C6C8_377DC8_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010D260_378960_MinigameParkSetup);

__asm__(".section .rodata");
const char D_8011370C_37EE0C_MinigameParkSetup[] = "%2d";


INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010E1F0_3798F0_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010E2B8_3799B8_MinigameParkSetup);


__asm__(".section .rodata");
const u32 D_80113710_37EE10_MinigameParkSetup[4] = { 0x0005000A, 0xFFFB0002, 0x0008FFFB, 0xFFFEFFFF };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010E460_379B60_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010ED54_37A454_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010EEF8_37A5F8_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010EF58_37A658_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010F0A4_37A7A4_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010F358_37AA58_MinigameParkSetup);



__asm__(".section .rodata");
const char D_80113720_37EE20_MinigameParkSetup[] = "c100_1-atama";

__asm__(".section .rodata");
const char D_80113730_37EE30_MinigameParkSetup[] = "c162_000-atama";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8010FB00_37B200_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80110278_37B978_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80110350_37BA50_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_801103A4_37BAA4_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8011042C_37BB2C_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_801104B4_37BBB4_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_801104DC_37BBDC_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_801104FC_37BBFC_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_801105B8_37BCB8_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8011060C_37BD0C_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80110678_37BD78_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_801109C8_37C0C8_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80110A28_37C128_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80110AF0_37C1F0_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80110B98_37C298_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80111328_37CA28_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_801115BC_37CCBC_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8011170C_37CE0C_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80111744_37CE44_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80111750_37CE50_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_8011175C_37CE5C_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80111768_37CE68_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80111D8C_37D48C_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80112360_37DA60_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80112454_37DB54_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80112810_37DF10_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80112910_37E010_MinigameParkSetup);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_58_MinigameParkSetup/36DF00", func_80112950_37E050_MinigameParkSetup);
