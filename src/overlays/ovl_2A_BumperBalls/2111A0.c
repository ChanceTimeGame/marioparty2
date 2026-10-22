#include "common.h"
#include "ovl_2A.h"

__asm__(".section .rodata");
const char D_8010A0A0_218A40_BumperBalls[] = "152_01f_DEF";

__asm__(".section .rodata");
const char D_8010A0AC_218A4C_BumperBalls[] = "152_01e_DEF";

__asm__(".section .rodata");
const char D_8010A0B8_218A58_BumperBalls[] = "152_01d_DEF";

__asm__(".section .rodata");
const char D_8010A0C4_218A64_BumperBalls[] = "152_01c_DEF";

__asm__(".section .rodata");
const char D_8010A0D0_218A70_BumperBalls[] = "152_01b_DEF";

__asm__(".section .rodata");
const char D_8010A0DC_218A7C_BumperBalls[] = "152_01a_DEF";

__asm__(".section .rodata");
const char D_8010A0E8_218A88_BumperBalls[] = "\202`\202a\202b";

void func_80102800_2111A0_BumperBalls(void) {
    void* data;
    s32 i;

    omInitObjMan(32, 0);
    func_80079128_79D28();
    D_8010A26E_218C0E_BumperBalls = 4;
    for (i = 0; i < 4; i++) {
        if (gPlayers[i].flags & 1) {
            D_8010A26E_218C0E_BumperBalls--;
        }
    }
    D_8010A272_218C12_BumperBalls = D_800FA656;
    func_8002D4D0_2E0D0(2);
    func_80020D20_21920(24);
    func_8002F290_2FE90(D_800F9D30_FA930, 64);
    func_8002CA48_2D648(0, 32, 128);
    func_80029708_2A308(1);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_80020718_21318(0, &func_8002E544_2F144, &D_800FA5B8_FB1B8);
    func_80026D28_27928(3);
    func_80026DAC_279AC(0, 44, 44, 64);
    func_80076BD0_777D0(0, 4);
    D_8010A29C_218C3C_BumperBalls = func_80076D80_77980(0);
    func_80076BD0_777D0(1, 4);
    D_8010A2A0_218C40_BumperBalls = func_80076D80_77980(1);
    omSetStatBit(omAddObj(100, 0, 0, -1, &func_801084C8_216E68_BumperBalls), 160);
    if ((D_8010A262_218C02_BumperBalls = _CheckFlag(0xC)) != 0) {
        for (i = 0; i < 4; i++) {
            if (gPlayers[i].flags & 1) {
                gPlayers[i].cpu_difficulty = D_800FD8AC[0];
            }
        }
    }
    omAddObj(20, 13, 7, 0, &func_8010351C_211EBC_BumperBalls);
    omAddObj(20, 13, 7, 0, &func_80103558_211EF8_BumperBalls);
    omAddObj(20, 13, 7, 0, &func_80103574_211F14_BumperBalls);
    omAddObj(20, 13, 7, 0, &func_80103590_211F30_BumperBalls);
    if (D_8010A272_218C12_BumperBalls == 2) {
        omAddObj(10, 7, 0, 1, &func_80105690_214030_BumperBalls);
        omAddObj(10, 7, 0, 1, &func_801056AC_21404C_BumperBalls);
        omAddObj(10, 7, 0, 1, &func_801056C8_214068_BumperBalls);
        omAddObj(10, 7, 0, 1, &func_801056E4_214084_BumperBalls);
    }
    omAddObj(0, 0, 0, -1, &func_80102C5C_2115FC_BumperBalls);
    D_8010A290_218C30_BumperBalls = omAddObj(6, 3, 0, -1, &func_80102F98_211938_BumperBalls);
    omAddObj(0x2710, 0, 0, -1, &func_80106730_2150D0_BumperBalls);
    D_8010A268_218C08_BumperBalls = func_8001A2F8_1AEF8(0x2F);
    data = DataRead(0x10);
    D_8010A26A_218C0A_BumperBalls = func_8003DF08_3EB08(data);
    HuMemMemoryFreePerm(data);
    data = DataRead(0xF);
    D_8010A26C_218C0C_BumperBalls = func_8003DF08_3EB08(data);
    HuMemMemoryFreePerm(data);
    func_8007273C_7333C((u8*)D_8010A0E8_218A88_BumperBalls, 1);
    D_8010A564_218F04_BumperBalls = 0;
    InitFadeIn(0, 16);
    if (D_8010A272_218C12_BumperBalls == 0) {
        D_8010A274_218C14_BumperBalls = PlaySound(0x4AF);
    }
}

void func_80102C5C_2115FC_BumperBalls(omObjData* arg0) {
    D_8010A562_218F02_BumperBalls = 0;
    D_8010A298_218C38_BumperBalls = NULL;
    D_8010A294_218C34_BumperBalls = NULL;
    D_8010A266_218C06_BumperBalls = 60;
    D_8010A264_218C04_BumperBalls = 30;
    D_8010A25E_218BFE_BumperBalls = 0;
    D_8010A260_218C00_BumperBalls = 4;
    arg0->func_ptr = &func_80102CB0_211650_BumperBalls;
}

void func_80102CB0_211650_BumperBalls(omObjData* arg0) {
    BumperBallsWork* work;
    s32 i;

    func_8006D4D0_6E0D0(D_8010A266_218C06_BumperBalls);
    switch (D_8010A562_218F02_BumperBalls) {
    case 0:
        if (D_8010A294_218C34_BumperBalls == NULL) {
            D_8010A294_218C34_BumperBalls = omAddObj(4, 0, 0, -1, &func_80105EBC_21485C_BumperBalls);
        }
        break;
    case 1:
        if (D_8010A260_218C00_BumperBalls >= 2) {
            D_8010A264_218C04_BumperBalls--;
        }
        if (D_8010A264_218C04_BumperBalls == 0) {
            if (D_8010A266_218C06_BumperBalls != 0) {
                D_8010A266_218C06_BumperBalls--;
            }
            D_8010A264_218C04_BumperBalls = 30;
        }
        if (D_8010A260_218C00_BumperBalls < 2 || D_8010A266_218C06_BumperBalls == 0) {
            if (func_80107204_215BA4_BumperBalls() == 1) {
                if (D_8010A260_218C00_BumperBalls == 0) {
                    D_8010A562_218F02_BumperBalls = 2;
                    D_8010A560_218F00_BumperBalls = 13;
                } else {
                    D_8010A562_218F02_BumperBalls = 2;
                    if (D_8010A260_218C00_BumperBalls == 1) {
                        D_8010A560_218F00_BumperBalls = 10;
                    } else {
                        D_8010A560_218F00_BumperBalls = 13;
                    }
                    for (i = 0; i < 4; i++) {
                        work = D_8010A29C_218C3C_BumperBalls[i]->unk_50;
                        if (work->unk_00 != 3 && work->unk_00 != 4 && work->unk_00 != 5) {
                            work->unk_00 = 6;
                        }
                    }
                }
            }
        }
        if (D_8010A262_218C02_BumperBalls != 0 && func_80107204_215BA4_BumperBalls() == 1) {
            work = D_8010A29C_218C3C_BumperBalls[0]->unk_50;
            if (work->player == 0 && (work->unk_00 == 3 || work->unk_00 == 4 || work->unk_00 == 5)) {
                D_8010A562_218F02_BumperBalls = 2;
                D_8010A560_218F00_BumperBalls = 10;
                for (i = 1; i < 4; i++) {
                    work = D_8010A29C_218C3C_BumperBalls[i]->unk_50;
                    if (work->unk_00 != 3 && work->unk_00 != 4 && work->unk_00 != 5) {
                        work->unk_00 = 6;
                    }
                }
            }
        }
        break;
    case 2:
        if (D_8010A298_218C38_BumperBalls == NULL) {
            D_8010A298_218C38_BumperBalls = omAddObj(4, 0, 0, -1, &func_80105FB0_214950_BumperBalls);
        }
        break;
    }
}

void func_80102F98_211938_BumperBalls(omObjData* arg0) {
    Vec eye;
    Vec at;
    s32 attr;

    attr = 0x2A9;
    if (D_8010A272_218C12_BumperBalls != 1) {
        attr |= 0x20000;
    }
    if (D_8010A272_218C12_BumperBalls == 0) {
        D_8010105C_101C5C = D_80101300_101F00 = 0.6f;
    }
    arg0->model[0] = LoadFormFile(D_8010A028_2189C8_BumperBalls[D_8010A272_218C12_BumperBalls], attr);
    if (D_8010A272_218C12_BumperBalls == 0) {
        D_8010105C_101C5C = D_80101300_101F00 = 1.0f;
    }
    eye.x = 0.0f;
    eye.y = 1589.7578f;
    eye.z = 2404.1443f;
    at.x = 0.0f;
    at.y = 0.0f;
    at.z = -140.0f;
    switch (D_8010A272_218C12_BumperBalls) {
    case 0:
        D_8010A278_218C18_BumperBalls = D_8010A27C_218C1C_BumperBalls = 0.0f;
        arg0->model[1] = LoadFormFile(0x3A000C, 0x689);
        func_8003EAF0_3F6F0("152_yougan2_IA44", &D_8010A280_218C20_BumperBalls);
        func_8003EAF0_3F6F0("152_yougan1_DEF", &D_8010A284_218C24_BumperBalls);
        func_8002A00C_2AC0C(arg0->model[1]);
        func_80029714_2A314(arg0->model[1], 0.0f, 0.0f, -500.0f);
        func_8002D1EC_2DDEC(arg0->model[1], 1);
        func_8002D274_2DE74(arg0->model[1], 255, 255, 255);
        func_8002D2B4_2DEB4(arg0->model[1], 0.0f, -127.0f, 0.0f);
        func_80026D50_27950(1, 1, 1);
        func_80026D50_27950(2, 1, 1);
        func_80026E00_27A00(1, -2.0f, 119.0f, -6.0f);
        func_80026DAC_279AC(2, 255, 95, 0);
        func_80026E00_27A00(2, 7.0f, -119.0f, 12.0f);
        func_8007A27C_7AE7C(0x7FDA, 0, NULL, 20.0f, &eye, &at);
        arg0->func_ptr = &func_80103430_211DD0_BumperBalls;
        omSetStatBit(arg0, 0xA0);
        break;
    case 1:
        func_80026DAC_279AC(1, 40, 40, 255);
        func_80026E00_27A00(1, 23.0f, 117.0f, 10.0f);
        func_80026DAC_279AC(2, 80, 60, 255);
        func_80026E00_27A00(2, -73.0f, 94.0f, 2.0f);
        func_80026DAC_279AC(3, 35, 30, 255);
        func_80026E00_27A00(3, 105.0f, 28.0f, 49.0f);
        D_8010A270_218C10_BumperBalls = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x3A000B), 0, 1);
        espDispOff(D_8010A270_218C10_BumperBalls);
        func_8007A27C_7AE7C(0x7FDA, D_800F93FC_F9FFC[(s16)D_8010A270_218C10_BumperBalls].unk_04, &func_8007A7FC_7B3FC, 20.0f, &eye, &at);
        arg0->func_ptr = NULL;
        break;
    case 2:
        func_80026DAC_279AC(1, 96, 96, 16);
        func_80026E00_27A00(1, 100.0f, 80.0f, 100.0f);
        func_80026DAC_279AC(2, 0, 0, 0);
        func_80026E00_27A00(2, 100.0f, 80.0f, 100.0f);
        func_80026DAC_279AC(3, 0, 0, 0);
        func_80026E00_27A00(3, 100.0f, 80.0f, 100.0f);
        arg0->model[1] = LoadFormFile(0x10002, 0x48D);
        arg0->model[2] = LoadFormFile(0x10003, 0x48D);
        func_8010851C_216EBC_BumperBalls("47mt003_DEF", "47mt002_IA44", 0);
        func_8007A27C_7AE7C(0x7FDA, 0, NULL, 20.0f, &eye, &at);
        arg0->func_ptr = &func_80103414_211DB4_BumperBalls;
        break;
    }
}

void func_80103414_211DB4_BumperBalls(omObjData* arg0) {
    func_80109868_218208_BumperBalls();
}

void func_80103430_211DD0_BumperBalls(omObjData* arg0) {
    if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        D_8010A278_218C18_BumperBalls += 0.1f;
        D_8010A27C_218C1C_BumperBalls -= 0.1f;
    }
    func_8002BED4_2CAD4(arg0->model[1], 0.0f, D_8010A278_218C18_BumperBalls, D_8010A280_218C20_BumperBalls.unk_00, D_8010A280_218C20_BumperBalls.unk_02, "152_02map-grid6_1", 0);
    func_8002BED4_2CAD4(arg0->model[1], 0.0f, D_8010A27C_218C1C_BumperBalls, D_8010A284_218C24_BumperBalls.unk_00, D_8010A284_218C24_BumperBalls.unk_02, "152_02map-grid6_1_1", 0);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_8010351C_211EBC_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80103558_211EF8_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80103574_211F14_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80103590_211F30_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_801035AC_211F4C_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80103D68_212708_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_801046B8_213058_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80104950_2132F0_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80104B70_213510_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80104E04_2137A4_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_8010515C_213AFC_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80105244_213BE4_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_8010545C_213DFC_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_801054DC_213E7C_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80105604_213FA4_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80105690_214030_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_801056AC_21404C_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_801056C8_214068_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_801056E4_214084_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80105700_2140A0_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80105948_2142E8_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80105EBC_21485C_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80105FB0_214950_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80106730_2150D0_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_801067D8_215178_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80106AD8_215478_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80106C88_215628_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80106E94_215834_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80106FCC_21596C_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80106FEC_21598C_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80107204_215BA4_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80107254_215BF4_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_801076A0_216040_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_801076D4_216074_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80107868_216208_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_801078FC_21629C_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80107C3C_2165DC_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80107DD4_216774_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80108074_216A14_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80108384_216D24_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80108410_216DB0_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_801084C8_216E68_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80108500_216EA0_BumperBalls);

__asm__(".section .rodata");
const char D_8010A220_218BC0_BumperBalls[] = "47mt003_DEF";

__asm__(".section .rodata");
const char D_8010A22C_218BCC_BumperBalls[] = "47mt002_IA44";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_8010851C_216EBC_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80108C70_217610_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80109868_218208_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80109D80_218720_BumperBalls);
