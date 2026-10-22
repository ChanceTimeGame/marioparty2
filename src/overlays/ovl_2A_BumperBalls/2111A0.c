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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80102C5C_2115FC_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80102CB0_211650_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80102F98_211938_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80103414_211DB4_BumperBalls);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2A_BumperBalls/2111A0", func_80103430_211DD0_BumperBalls);

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
