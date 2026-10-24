#include "common.h"
#include "ovl_5F.h"

void func_80102830_3AB9D0_name_5F(void) {
    s32 temp_s0;
    s32 i;

    func_80102A14_3ABBB4_name_5F();
    if (GwSystem.unk_25 == 1) {
        func_801085A0_3B1740_name_5F(0);
        return;
    }
    switch (D_80114DC2_3BDF62_name_5F) {
    case 6:
    case 7:
        func_801085A0_3B1740_name_5F(0);
        return;
    }
    
    PlayMusic(0x16);
    omSetStatBit(omAddObj(0x7FDA, 0U, 0U, -1, func_80079E60_7AA60), 0xA0U);
    func_80018E30_19A30(1);
    temp_s0 = func_80018E78_19A78();
    ScissorSet(temp_s0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(temp_s0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 10.0f, 500.0f, 5000.0f);
    D_800FA610_FB210 = 2500.0f;
    D_800FD474_FE074.x = 0.0f;
    D_800FD474_FE074.y = 0.0f;
    D_800FD474_FE074.z = 0.0f;
    D_8010274C_10334C.x = 0.0f;
    D_8010274C_10334C.y = 0.0f;
    D_8010274C_10334C.z = 0.0f;
    func_80102AF0_3ABC90_name_5F();
    omAddPrcObj(&func_80105B94_3AED34_name_5F, 0x1001U, 0x800, 0);
    
    for (i = 0; i < 4; i++) {
        if (gPlayers[i].group == 0) {
            break;
        }
    }
    
    D_80114DC4_3BDF64_name_5F = D_80114F70_3BE110_name_5F = i;
    InitFadeIn(0, 0x10);
}

void func_80102A14_3ABBB4_name_5F(void) {
    func_80020070_20C70(1);
    func_8002D4D0_2E0D0(1);
    func_80020D20_21920(0x19);
    omInitObjMan(0x32, 0x14);
    func_80088640_89240();
    D_80102708_103308 = 1;
    D_800FC8A0_FD4A0 = 0;
    D_800F9910_FA510 = 0;
    D_80114E4A_3BDFEA_name_5F = 0;
    D_80114DC0_3BDF60_name_5F = D_80114F74_3BE114_name_5F = GwSystem.chosenMinigameIndex - 1;
    D_80114DC2_3BDF62_name_5F = D_80114F72_3BE112_name_5F = D_800CAD90[D_80114DC0_3BDF60_name_5F].unk_04;
    if (_CheckFlag(0xC) != 0) {
        func_801136C4_3BC864_name_5F(D_80114DC0_3BDF60_name_5F);
    } else {
        func_80108170_3B1310_name_5F();
        func_80108458_3B15F8_name_5F();
    }
}

/* NON_MATCHING: register allocation only (the first switch's value is in s1, retail s0 with an
   andi copy to s1). */
#ifdef NON_MATCHING
void func_80102AF0_3ABC90_name_5F(void) {
    void* file;
    s32 j;
    s32 i;

    D_80114E10_3BDFB0_name_5F = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0xB0011), 0, 0);
    espPosSet(D_80114E10_3BDFB0_name_5F, 160, 120);
    func_8001A708_1B308(D_80114E10_3BDFB0_name_5F, 0x4000);
    func_8001A6BC_1B2BC(D_80114E10_3BDFB0_name_5F, 0);
    D_80114DC8_3BDF68_name_5F[0] = func_80018A30_19630(0xB000E, 0xA8D);
    func_8002D124_2DD24(D_80114DC8_3BDF68_name_5F[0]);
    func_8002D0A0_2DCA0(D_80114DC8_3BDF68_name_5F[0], 0x80);
    j = 0;
    func_80029AFC_2A6FC(D_80114DC8_3BDF68_name_5F[0]);
    switch (D_80114DC2_3BDF62_name_5F) {
    case 3:
        j = 3;
        break;
    case 5:
        j = 4;
        break;
    case 4:
        j = 2;
        break;
    default:
        if (func_801050DC_3AE27C_name_5F(D_80114DC0_3BDF60_name_5F) != 0) {
            j = 1;
        }
        break;
    }
    D_80114DC8_3BDF68_name_5F[1] = func_80018A30_19630((u16)j | 0xB0000, 0xA8D);
    HmfModelObjAttrSet(D_80114DC8_3BDF68_name_5F[1], 0x20000, 0x20000);
    func_80029A8C_2A68C(D_80114DC8_3BDF68_name_5F[1]);
    func_8002A00C_2AC0C(D_80114DC8_3BDF68_name_5F[1]);
    func_80029AFC_2A6FC(D_80114DC8_3BDF68_name_5F[1]);
    D_80114DC8_3BDF68_name_5F[2] = func_80018A30_19630(((u16)j + 5) | 0xB0000, 0xA8D);
    HmfModelObjAttrSet(D_80114DC8_3BDF68_name_5F[2], 0x20000, 0x20000);
    func_80029A8C_2A68C(D_80114DC8_3BDF68_name_5F[2]);
    func_8002A00C_2AC0C(D_80114DC8_3BDF68_name_5F[2]);
    func_80029AFC_2A6FC(D_80114DC8_3BDF68_name_5F[2]);
    i = 0;
    D_80114E18_3BDFB8_name_5F = func_80018A30_19630(0xB000A, 0xA9D);
    func_80029E80_2AA80(D_80114E18_3BDFB8_name_5F, 0, 2);
    switch (D_80114DC2_3BDF62_name_5F) {
    case 3:
        i = 2;
        break;
    case 4:
        i = 1;
        break;
    }
    D_80114DC8_3BDF68_name_5F[3] = func_80018A30_19630(((u16)i + 0xB) | 0xB0000, 0xA8D);
    HmfModelObjAttrSet(D_80114DC8_3BDF68_name_5F[3], 0x20000, 0x20000);
    func_80029A8C_2A68C(D_80114DC8_3BDF68_name_5F[3]);
    func_8002A00C_2AC0C(D_80114DC8_3BDF68_name_5F[3]);
    func_80029AFC_2A6FC(D_80114DC8_3BDF68_name_5F[3]);
    D_80114DC8_3BDF68_name_5F[4] = func_80018A30_19630(0xB000B, 0xA8D);
    HmfModelObjAttrSet(D_80114DC8_3BDF68_name_5F[4], 0x20000, 0x20000);
    func_80029A8C_2A68C(D_80114DC8_3BDF68_name_5F[4]);
    func_8002A00C_2AC0C(D_80114DC8_3BDF68_name_5F[4]);
    func_80029AFC_2A6FC(D_80114DC8_3BDF68_name_5F[4]);
    if (D_80114DC2_3BDF62_name_5F < 3) {
        if (D_80114DC2_3BDF62_name_5F > 0) {
            if (D_80114DC0_3BDF60_name_5F != 0x21) {
                D_80114DC8_3BDF68_name_5F[5] = func_80018A30_19630(0xB000B, 0xA8D);
                HmfModelObjAttrSet(D_80114DC8_3BDF68_name_5F[5], 0x20000, 0x20000);
                func_80029A8C_2A68C(D_80114DC8_3BDF68_name_5F[5]);
                func_8002A00C_2AC0C(D_80114DC8_3BDF68_name_5F[5]);
                func_80029AFC_2A6FC(D_80114DC8_3BDF68_name_5F[5]);
            }
        }
    }
    switch (D_80114DC2_3BDF62_name_5F) {
    case 3:
        D_80114E1E_3BDFBE_name_5F = func_80018A30_19630(0x800A6, 0xAAD);
        D_80114E20_3BDFC0_name_5F[0] = D_800FC834_FD434[D_80114E1E_3BDFBE_name_5F].unk02;
        D_80114E20_3BDFC0_name_5F[1] = func_8002C8B8_2D4B8(DataRead(0x800AA), 0x1D);
        D_80114E20_3BDFC0_name_5F[2] = func_8002C8B8_2D4B8(DataRead(0x800AB), 0x1D);
        func_80029E80_2AA80(D_80114E1E_3BDFBE_name_5F, 0, 2);
        func_800297E8_2A3E8(D_80114E1E_3BDFBE_name_5F, 0.8f, 0.8f, 0.8f);
        file = DataRead(0x800AE);
        func_8003D8F0_3E4F0(D_800FC834_FD434[D_80114E1E_3BDFBE_name_5F].hmf, file, 0, "c164m_0_DEF");
        DataClose(file);
        func_80029A8C_2A68C(D_80114E1E_3BDFBE_name_5F);
        func_80029AFC_2A6FC(D_80114E1E_3BDFBE_name_5F);
        D_80114E2C_3BDFCC_name_5F = func_80018A30_19630(0xB0010, 0xA9D);
        func_8002979C_2A39C(D_80114E2C_3BDFCC_name_5F, 0.0f, 0.0f, 0.0f);
        func_800297E8_2A3E8(D_80114E2C_3BDFCC_name_5F, 0.8f, 0.8f, 0.8f);
        func_801049F4_3ADB94_name_5F();
        break;
    case 4:
        D_80114E1E_3BDFBE_name_5F = func_80018A30_19630(0x800A3, 0xAAD);
        D_80114E20_3BDFC0_name_5F[0] = D_800FC834_FD434[D_80114E1E_3BDFBE_name_5F].unk02;
        D_80114E20_3BDFC0_name_5F[1] = func_8002C8B8_2D4B8(DataRead(0x80093), 0x1D);
        D_80114E20_3BDFC0_name_5F[2] = func_8002C8B8_2D4B8(DataRead(0x80091), 0x1D);
        D_80114E20_3BDFC0_name_5F[3] = func_8002C8B8_2D4B8(DataRead(0x8008E), 0x1D);
        D_80114E20_3BDFC0_name_5F[4] = func_8002C8B8_2D4B8(DataRead(0x800A1), 0x1D);
        func_8002C9C0_2D5C0(D_80114E1E_3BDFBE_name_5F, D_80114E20_3BDFC0_name_5F[1]);
        func_80029E80_2AA80(D_80114E1E_3BDFBE_name_5F, 0, 2);
        func_800297E8_2A3E8(D_80114E1E_3BDFBE_name_5F, 0.8f, 0.8f, 0.8f);
        file = DataRead(0x800A4);
        func_8003D8F0_3E4F0(D_800FC834_FD434[D_80114E1E_3BDFBE_name_5F].hmf, file, 0, "c103m_0_DEF");
        DataClose(file);
        func_80029A8C_2A68C(D_80114E1E_3BDFBE_name_5F);
        func_80029AFC_2A6FC(D_80114E1E_3BDFBE_name_5F);
        break;
    default:
        if (_CheckFlag(0xC) != 0) {
            D_80114E1E_3BDFBE_name_5F = func_80018A30_19630(0x80035, 0xAAD);
        } else {
            D_80114E1E_3BDFBE_name_5F = func_80018A30_19630(0x80000, 0xAAD);
        }
        D_80114E20_3BDFC0_name_5F[0] = func_8002C8B8_2D4B8(DataRead(0x8002C), 0x1D);
        D_80114E20_3BDFC0_name_5F[1] = func_8002C8B8_2D4B8(DataRead(0x8002D), 0x1D);
        D_80114E20_3BDFC0_name_5F[2] = func_8002C8B8_2D4B8(DataRead(0x8002E), 0x1D);
        D_80114E20_3BDFC0_name_5F[3] = func_8002C8B8_2D4B8(DataRead(0x8002F), 0x1D);
        func_8002C9C0_2D5C0(D_80114E1E_3BDFBE_name_5F, D_80114E20_3BDFC0_name_5F[0]);
        func_80029E80_2AA80(D_80114E1E_3BDFBE_name_5F, 0, 2);
        func_800297E8_2A3E8(D_80114E1E_3BDFBE_name_5F, 0.8f, 0.8f, 0.8f);
        file = DataRead(0x80039);
        if (_CheckFlag(0xC) != 0) {
            func_8003D8F0_3E4F0(D_800FC834_FD434[D_80114E1E_3BDFBE_name_5F].hmf, file, 0, "c180n_0_DEF");
        } else {
            func_8003D8F0_3E4F0(D_800FC834_FD434[D_80114E1E_3BDFBE_name_5F].hmf, file, 0, "c160n_0_DEF");
        }
        DataClose(file);
        func_80029A8C_2A68C(D_80114E1E_3BDFBE_name_5F);
        func_80029AFC_2A6FC(D_80114E1E_3BDFBE_name_5F);
        if (func_801050DC_3AE27C_name_5F(D_80114DC0_3BDF60_name_5F) != 0) {
            D_80114E2C_3BDFCC_name_5F = func_80018A30_19630(0xB0012, 0xA9D);
        }
        break;
    }
    D_80114E2A_3BDFCA_name_5F = func_80018A30_19630(0xB000F, 0xA8D);
    i = D_800CAD90[D_80114DC0_3BDF60_name_5F].unk_06 & 0xFFF;
    if ((D_800CAD90[D_80114DC0_3BDF60_name_5F].unk_06 >> 15) == 1) {
        i += D_800FA656 * 2;
    }
    D_80114E4C_3BDFEC_name_5F = DataRead((u16)i | 0xB0000);
    D_80114E54_3BDFF4_name_5F = DataRead(((u16)i + 1) | 0xB0000);
    D_80114E50_3BDFF0_name_5F = DataRead(0xB0024);
    func_801072C8_3B0468_name_5F(D_80114E2A_3BDFCA_name_5F, D_80114E54_3BDFF4_name_5F, D_80114E4C_3BDFEC_name_5F, D_80114E50_3BDFF0_name_5F);
    D_80114E3C_3BDFDC_name_5F = func_8008DFC4_8EBC4(0x48, 0xBC, 4);
    func_80089674_8A274(D_80114E3C_3BDFDC_name_5F)->unk29 = 0;
    D_80114E3E_3BDFDE_name_5F[0] = func_80089404_8A004(D_80114E3C_3BDFDC_name_5F, 0xB0013, 0x37, -0x28, 0);
    D_80114E3E_3BDFDE_name_5F[1] = func_80089404_8A004(D_80114E3C_3BDFDC_name_5F, 0xB0017, 0x37, -0x28, 0);
    D_80114E3E_3BDFDE_name_5F[2] = func_80089404_8A004(D_80114E3C_3BDFDC_name_5F, 0xB0021, 0x82, -0x28, 0);
    if (func_80105A14_3AEBB4_name_5F() != 0) {
        D_80114E3E_3BDFDE_name_5F[3] = func_80089404_8A004(D_80114E3C_3BDFDC_name_5F, 0xB0022, 0xBE, -0x28, 0);
    }
    D_80114E12_3BDFB2_name_5F = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0xB001D), 0, 1);
    espDispOff(D_80114E12_3BDFB2_name_5F);
    D_80114E14_3BDFB4_name_5F = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0xB001E), 0, 1);
    func_8001A96C_1B56C(D_80114E14_3BDFB4_name_5F, 0, 0, 0x80);
    espDispOff(D_80114E14_3BDFB4_name_5F);
    D_80114E16_3BDFB6_name_5F = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0xB0021), 0, 1);
    espDispOff(D_80114E16_3BDFB6_name_5F);
    D_80114E1A_3BDFBA_name_5F = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x900FA), 0, 1);
    espDispOff(D_80114E1A_3BDFBA_name_5F);
    D_80114E1C_3BDFBC_name_5F = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80102AF0_3ABC90_name_5F);
#endif

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010352C_3AC6CC_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80103608_3AC7A8_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80103778_3AC918_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010382C_3AC9CC_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801038D4_3ACA74_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80103994_3ACB34_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80103B78_3ACD18_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80103C84_3ACE24_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801040D0_3AD270_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801041C4_3AD364_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80104280_3AD420_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010433C_3AD4DC_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80104490_3AD630_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010456C_3AD70C_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80104650_3AD7F0_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801046A4_3AD844_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801048F0_3ADA90_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801049F4_3ADB94_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80104D08_3ADEA8_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80104DA8_3ADF48_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80104E98_3AE038_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80104F18_3AE0B8_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80105008_3AE1A8_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801050DC_3AE27C_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80105110_3AE2B0_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80105258_3AE3F8_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801053F0_3AE590_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801054EC_3AE68C_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801056A8_3AE848_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010578C_3AE92C_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80105860_3AEA00_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80105A14_3AEBB4_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80105A54_3AEBF4_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80105AB8_3AEC58_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80105B94_3AED34_name_5F);

__asm__(".section .rodata");
const u32 D_801147D8_3BD978_name_5F[1] = { 0xFF000000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801072C8_3B0468_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80107C84_3B0E24_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80107F74_3B1114_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80107FE0_3B1180_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80108170_3B1310_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80108458_3B15F8_name_5F);

void func_801085A0_3B1740_name_5F(s32 arg0) {
    s16 minigameOverlayID;

    func_8008CE5C_8DA5C();
    func_800727F0_733F0();
    func_80067EF8_68AF8(-1);
    
    if (arg0 != 0) {
        DataClose(D_80114E54_3BDFF4_name_5F);
        DataClose(D_80114E4C_3BDFEC_name_5F);
        DataClose(D_80114E50_3BDFF0_name_5F);
        omOvlKill();
    }
    
    if (D_80114E4A_3BDFEA_name_5F != 0) {
        omOvlCallEx(D_800CAD90[D_80114DC0_3BDF60_name_5F].unk_00, 0, 0x14);
        minigameOverlayID = func_8003F6F0_402F0(GwSystem.chosenMinigameIndex);
        omOvlHisChg(1, minigameOverlayID, 0, 0x14);
        return;
    } 
    
    _ClearFlag(0x15);
    if ((_CheckFlag(0x13) != 0) || !(_CheckFlag(0xC) == 0)) {
        omOvlGotoEx(D_800CAD90[D_80114DC0_3BDF60_name_5F].unk_00, 0, 0x14);
        return;
    }
    
    switch (D_80114DC2_3BDF62_name_5F) {
        case 6:
        case 5:
        case 4:
            omOvlGotoEx(D_800CAD90[D_80114DC0_3BDF60_name_5F].unk_00, 0, 0x14);
            return;
        case 7:
            GwSystem.current_board_index = (u16) D_80114DC0_3BDF60_name_5F - 0x3A;
            D_800F8D18[2] = 1;
            D_800F8D18[1] = 0xE;
            omOvlGotoEx(D_800CAD90[D_80114DC0_3BDF60_name_5F].unk_00, 0, 0x12);
            return;
            
        case 3:
            omOvlCallEx(D_800CAD90[D_80114DC0_3BDF60_name_5F].unk_00, 0, 0x14);
            omOvlHisChg(1, 0x6F, 0, 0x14);
            return;
    }
    omOvlCallEx(D_800CAD90[D_80114DC0_3BDF60_name_5F].unk_00, 0, 0x14);
    omOvlHisChg(1, 0x70, 0, 0x14);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010879C_3B193C_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010881C_3B19BC_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80108AEC_3B1C8C_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80108B80_3B1D20_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80108C24_3B1DC4_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80108C8C_3B1E2C_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80108D50_3B1EF0_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80108DCC_3B1F6C_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80108E50_3B1FF0_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801092B0_3B2450_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010938C_3B252C_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801093D4_3B2574_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80109424_3B25C4_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010946C_3B260C_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801094B4_3B2654_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801094F4_3B2694_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801098FC_3B2A9C_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80109988_3B2B28_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80109A04_3B2BA4_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80109A80_3B2C20_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80109FA0_3B3140_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010A000_3B31A0_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010A038_3B31D8_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010A0C4_3B3264_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010A1A0_3B3340_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010A2B0_3B3450_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010A2EC_3B348C_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010A45C_3B35FC_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010A4F0_3B3690_name_5F);

__asm__(".section .rodata");
const char D_80114A1C_3BDBBC_name_5F[] = "c005_000-cyl1_1_3";

__asm__(".section .rodata");
const char D_80114A30_3BDBD0_name_5F[] = "Luigi1-karada_2_1_1";

__asm__(".section .rodata");
const char D_80114A44_3BDBE4_name_5F[] = "c003_000-yoshi_body_2_3";

__asm__(".section .rodata");
const char D_80114A5C_3BDBFC_name_5F[] = "C002_000b-cone7_1_1_1_1_1";

__asm__(".section .rodata");
const char D_80114A78_3BDC18_name_5F[] = "c001_000-karada_1";

__asm__(".section .rodata");
const char D_80114A8C_3BDC2C_name_5F[] = "karada_2_1_1_1";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010A628_3B37C8_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010A818_3B39B8_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010AAA0_3B3C40_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010AC44_3B3DE4_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010AEF8_3B4098_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010AF84_3B4124_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010B168_3B4308_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010B30C_3B44AC_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010B33C_3B44DC_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010B460_3B4600_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010B4F0_3B4690_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010B624_3B47C4_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010B798_3B4938_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010BA24_3B4BC4_name_5F);

__asm__(".section .rodata");
const char D_80114AD8_3BDC78_name_5F[] = "114_Bowring1-kaodamy_3";

__asm__(".section .rodata");
const char D_80114AF0_3BDC90_name_5F[] = "c005_000-bmerge1";

__asm__(".section .rodata");
const char D_80114B04_3BDCA4_name_5F[] = "114_Bowring1-kaodamy_1";

__asm__(".section .rodata");
const char D_80114B1C_3BDCBC_name_5F[] = "Luigi1-atama_1";

__asm__(".section .rodata");
const char D_80114B2C_3BDCCC_name_5F[] = "114_Bowring1-kaodamy_5";

__asm__(".section .rodata");
const char D_80114B44_3BDCE4_name_5F[] = "c003_000-head_1";

__asm__(".section .rodata");
const char D_80114B54_3BDCF4_name_5F[] = "114_Bowring1-kaodamy";

__asm__(".section .rodata");
const char D_80114B6C_3BDD0C_name_5F[] = "C002_000b-bmerge10_1";

__asm__(".section .rodata");
const char D_80114B84_3BDD24_name_5F[] = "114_Bowring1-kaodamy_2";

__asm__(".section .rodata");
const char D_80114B9C_3BDD3C_name_5F[] = "c001_000-atama_2";

__asm__(".section .rodata");
const char D_80114BB0_3BDD50_name_5F[] = "114_Bowring0-kaodamy_4";

__asm__(".section .rodata");
const char D_80114BC8_3BDD68_name_5F[] = "atama_2";

__asm__(".section .rodata");
const char D_80114BD0_3BDD70_name_5F[16] = "item_hook";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010BCF0_3B4E90_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010C2A8_3B5448_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010C40C_3B55AC_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010C61C_3B57BC_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010CD08_3B5EA8_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010CFB8_3B6158_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010D098_3B6238_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010D640_3B67E0_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010D798_3B6938_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010DC40_3B6DE0_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010DF10_3B70B0_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010E65C_3B77FC_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010E844_3B79E4_name_5F);

__asm__(".section .rodata");
const char D_80114C24_3BDDC4_name_5F[] = "c005l_0_DEF";

__asm__(".section .rodata");
const char D_80114C30_3BDDD0_name_5F[] = "c004l_0_DEF";

__asm__(".section .rodata");
const char D_80114C3C_3BDDDC_name_5F[] = "c003l_0_DEF";

__asm__(".section .rodata");
const char D_80114C48_3BDDE8_name_5F[] = "c002l_0_DEF";

__asm__(".section .rodata");
const char D_80114C54_3BDDF4_name_5F[] = "c001l_0_DEF";

__asm__(".section .rodata");
const char D_80114C60_3BDE00_name_5F[16] = "c000l_0_DEF";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010E920_3B7AC0_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010EEB4_3B8054_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010F0C8_3B8268_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010F1A4_3B8344_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010F488_3B8628_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010F578_3B8718_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010F668_3B8808_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010F8BC_3B8A5C_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8010FDD8_3B8F78_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80110050_3B91F0_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80110480_3B9620_name_5F);

__asm__(".section .rodata");
const char D_80114CB0_3BDE50_name_5F[] = "c005_000-bmerge6";

__asm__(".section .rodata");
const char D_80114CC4_3BDE64_name_5F[] = "Luigi1-migi-te1_1";

__asm__(".section .rodata");
const char D_80114CD8_3BDE78_name_5F[] = "c003_000-bmerge1_8";

__asm__(".section .rodata");
const char D_80114CEC_3BDE8C_name_5F[] = "C002_000b-bmerge16";

__asm__(".section .rodata");
const char D_80114D00_3BDEA0_name_5F[] = "c001_000-migi-te2_3";

__asm__(".section .rodata");
const char D_80114D14_3BDEB4_name_5F[20] = "migi-te3_2_1";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80110784_3B9924_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80110F2C_3BA0CC_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8011126C_3BA40C_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8011137C_3BA51C_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801116B0_3BA850_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801119A8_3BAB48_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80111A00_3BABA0_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80112080_3BB220_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8011238C_3BB52C_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_801123E4_3BB584_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80112A1C_3BBBBC_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80112B20_3BBCC0_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80112C64_3BBE04_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80112E68_3BC008_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80112FE8_3BC188_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80113004_3BC1A4_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_80113020_3BC1C0_name_5F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5F_name/3AB9D0", func_8011303C_3BC1DC_name_5F);
