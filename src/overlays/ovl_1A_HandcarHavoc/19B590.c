#include "ovl_1A.h"

__asm__(".section .rodata");
const char D_8010B1F0_1A3F80_HandcarHavoc[] = "\202`\202a\202b";

void func_80102800_19B590_HandcarHavoc(void) {
    omObjData* obj;
    s32 i;

    omInitObjMan(25, 0);
    func_80079128_79D28();
    func_80020D20_21920(16);
    func_8002D4D0_2E0D0(4);
    func_8002F290_2FE90(D_800F9D30_FA930, 64);
    func_80018ED0_19AD0(2);
    func_80018F58_19B58(2);
    for (i = 0; i < 2; i++) {
        D_800F94A8_FA0A8[i] = 1100.0f;
        D_80102770_103370[i].x = -27.0f;
        D_80102770_103370[i].y = 0;
        D_80102770_103370[i].z = 0;
        D_801013B0_101FB0[i].x = 0;
        D_801013B0_101FB0[i].y = 0;
        D_801013B0_101FB0[i].z = 0;
        D_800C9B80_CA780[i].fov[0] = 45.0f;
        Hu3DCamSetPerspective(i, 45.0f, 80.0f, 20000.0f);
    }
    ScissorSet(0, 0.0f, 0.0f, 144.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 320.0f, 480.0f, 511.0f);
    ScissorSet(1, 176.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(1, 640.0f, 480.0f, 511.0f, 960.0f, 480.0f, 511.0f);
    func_80029708_2A308(1);
    func_8002CA48_2D648(200, 255, 255);
    func_8002C59C_2D19C(0x3C0, 0x3E8, 200, 255, 255);
    obj = omAddObj(300, 0, 0, -1, func_801083B4_1A1144_HandcarHavoc);
    omSetStatBit(obj, 0xA0);
    func_801083B4_1A1144_HandcarHavoc(obj);
    func_80026D28_27928(2);
    func_80026DAC_279AC(0, 0, 0, 0);
    func_80026DAC_279AC(1, 0, 0, 0);
    func_80026E00_27A00(1, 42.0f, -107.0f, 32.0f);
    D_8010B368_1A40F8_HandcarHavoc.x = -19;
    D_8010B368_1A40F8_HandcarHavoc.y = -114;
    D_8010B368_1A40F8_HandcarHavoc.z = 31;
    D_8010B374_1A4104_HandcarHavoc = 215;
    func_80026DAC_279AC(2, 209, 207, 206);
    func_80026E00_27A00(2, -67.0f, 37.0f, 91.0f);
    func_80026D50_27950(2, 1, 1);
    D_8010B362_1A40F2_HandcarHavoc = _CheckFlag(0xC);
    func_80076BD0_777D0(0, 2);
    D_8010D820_1A65B0_HandcarHavoc = func_80076D80_77980(0);
    func_80076BD0_777D0(1, 2);
    D_8010D7E0_1A6570_HandcarHavoc = func_80076D80_77980(1);
    omAddObj(100, 7, 15, 0, func_801033B0_19C140_HandcarHavoc);
    omAddObj(100, 7, 15, 0, func_801033EC_19C17C_HandcarHavoc);
    omAddObj(200, 0, 0, 1, func_80109B88_1A2918_HandcarHavoc);
    omAddObj(200, 0, 0, 1, func_80109BA4_1A2934_HandcarHavoc);
    D_8010D830_1A65C0_HandcarHavoc = omAddObj(150, 0, 0, -1, func_8010A870_1A3600_HandcarHavoc);
    D_8010D818_1A65A8_HandcarHavoc[0] = omAddObj(170, 0, 0, -1, func_8010AD1C_1A3AAC_HandcarHavoc);
    D_8010D818_1A65A8_HandcarHavoc[1] = omAddObj(170, 0, 0, -1, func_8010AD1C_1A3AAC_HandcarHavoc);
    D_8010D818_1A65A8_HandcarHavoc[1]->work[0] = 1;
    D_8010D804_1A6594_HandcarHavoc = omAddObj(600, 0, 0, -1, func_80107740_1A04D0_HandcarHavoc);
    omSetStatBit(omAddObj(1000, 0, 0, -1, func_80108360_1A10F0_HandcarHavoc), 0x80);
    omAddObj(0, 0, 0, -1, func_80102E40_19BBD0_HandcarHavoc);
    omSetStatBit(D_8010B3A8_1A4138_HandcarHavoc = omAddObj(50, 9, 0, -1, func_801030F4_19BE84_HandcarHavoc), 0xA0);
    omAddObj(10000, 0, 0, -1, func_8010A7D8_1A3568_HandcarHavoc);
    D_8010D802_1A6592_HandcarHavoc = func_8001A2F8_1AEF8(0x2A0009);
    D_8010D826_1A65B6_HandcarHavoc = func_8001A2F8_1AEF8(0x2A000A);
    D_8010D82A_1A65BA_HandcarHavoc = func_8001A2F8_1AEF8(0x2A0007);
    D_8010D876_1A6606_HandcarHavoc = func_8001A2F8_1AEF8(0x2A0008);
    D_8010D85C_1A65EC_HandcarHavoc = func_8001A2F8_1AEF8(0x43);
    D_8010D7E4_1A6574_HandcarHavoc = func_8001A2F8_1AEF8(0x43);
    D_8010D872_1A6602_HandcarHavoc = func_8001A2F8_1AEF8(0x10016);
    D_8010D874_1A6604_HandcarHavoc = func_8001A2F8_1AEF8(0x10015);
    func_8001A340_1AF40(D_8010D7E4_1A6574_HandcarHavoc, 0.0f, 1.0f, 0.0f);
    D_8010D878_1A6608_HandcarHavoc = func_8001A2F8_1AEF8(0x2A0013);
    D_8010D814_1A65A4_HandcarHavoc = func_8001A2F8_1AEF8(0x2A0011);
    D_8010D82C_1A65BC_HandcarHavoc = func_8001A2F8_1AEF8(0x2A0012);
    func_8007273C_7333C((u8*)D_8010B1F0_1A3F80_HandcarHavoc, 1);
    InitFadeIn(0, 16);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_80102E40_19BBD0_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_80102EAC_19BC3C_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_801030F4_19BE84_HandcarHavoc);

void func_801032F4_19C084_HandcarHavoc(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_801032FC_19C08C_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_801033B0_19C140_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_801033EC_19C17C_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_80103428_19C1B8_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_80103DE4_19CB74_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_8010484C_19D5DC_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_80104C00_19D990_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_80104DE0_19DB70_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_801051E8_19DF78_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_801052B8_19E048_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_80105394_19E124_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_80105940_19E6D0_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_80105FEC_19ED7C_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_801060A4_19EE34_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_80106164_19EEF4_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_8010625C_19EFEC_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_801067A0_19F530_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_801068CC_19F65C_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_801069D8_19F768_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_80106AD0_19F860_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_80106B84_19F914_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_80106CA8_19FA38_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_80106E70_19FC00_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_801074A8_1A0238_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_80107634_1A03C4_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_80107740_1A04D0_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_801078B8_1A0648_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_80107900_1A0690_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_80107AB0_1A0840_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_80107C64_1A09F4_HandcarHavoc);
