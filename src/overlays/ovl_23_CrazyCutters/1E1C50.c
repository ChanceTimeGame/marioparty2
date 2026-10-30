#include "ovl_23.h"

/* Per screen quarter: the shape sprite's centre (MP1 D_800FCFA8, .data there). */
const s16 D_801093F0_1E8840_CrazyCutters[4][2] = { { 0x38, 0x5A }, { 0xD8, 0x5A }, { 0x38, 0xD2 }, { 0xD8, 0xD2 } };
/* Unreferenced (MP1 D_800FCFB8, D_800FCFD0). */
const s32 D_80109400_1E8850_CrazyCutters[4] = { 0x29E, 0x29E, 0x23A, 0 };
const u8 D_80109410_1E8860_CrazyCutters[0x40] = {
    0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,
    0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0,
    0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x00,
};


void func_80102800_1E1C50_CrazyCutters(void) {
    s32 shapes[3] = { 2, 0, 1 };
    s32 i;
    s16 grp;

    func_8002D4D0_2E0D0(20);
    func_80020D20_21920(66);
    omInitObjMan(40, 0);
    func_80079128_79D28();
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_80079E60_7AA60), 0xA0);
    D_801098FC_1E8D4C_CrazyCutters = 0;
    D_801099F4_1E8E44_CrazyCutters = 0;
    func_80102B64_1E1FB4_CrazyCutters(7000.0f, 270.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
    func_80076BD0_777D0(4, 4);
    func_8010874C_1E7B9C_CrazyCutters();
    omAddObj(10, 0, 0, -1, func_801057D8_1E4C28_CrazyCutters);
    D_80109918_1E8D68_CrazyCutters = shapes[D_800FA656];
    D_801099E8_1E8E38_CrazyCutters = 2.0f;
    D_80109948_1E8D98_CrazyCutters = 0;
    D_801099C8_1E8E18_CrazyCutters = -1;
    D_801099CC_1E8E1C_CrazyCutters = -1;
    D_801099D0_1E8E20_CrazyCutters = -1;
    D_801098F8_1E8D48_CrazyCutters = 71;
    omAddObj(12, 0, 0, -1, func_80102C18_1E2068_CrazyCutters);
    D_80109900_1E8D50_CrazyCutters = 1;
    func_8002CA48_2D648(0, 0, 0);
    func_80108214_1E7664_CrazyCutters();
    for (i = 0; i < 4; i++) {
        s32 q = func_8010882C_1E7C7C_CrazyCutters(i);

        grp = func_80108284_1E76D4_CrazyCutters(*(*(D_801093F0_1E8840_CrazyCutters + q) + 0), *(*(D_801093F0_1E8840_CrazyCutters + q) + 1));
        D_80109A48_1E8E98_CrazyCutters[i] = grp;
        func_801084A0_1E78F0_CrazyCutters(grp);
    }
    D_80109A50_1E8EA0_CrazyCutters = 0;
    D_8010957E_1E89CE_CrazyCutters = 30;
    D_80109A00_1E8E50_CrazyCutters = _CheckFlag(0xC);
}

void func_80102A44_1E1E94_CrazyCutters(omObjData* obj) {
    if (--D_801098F8_1E8D48_CrazyCutters == 0) {
        D_801098F8_1E8D48_CrazyCutters = 28;
        D_80109A9A_1E8EEA_CrazyCutters = -1;
        func_800691FC_69DFC(0);
        obj->func_ptr = func_80102AA8_1E1EF8_CrazyCutters;
    }
}

void func_80102AA8_1E1EF8_CrazyCutters(omObjData* obj) {
    if (func_80069538_6A138() == 0 || func_80069538_6A138() & 2) {
        if (--D_801098F8_1E8D48_CrazyCutters == 0) {
            D_80109948_1E8D98_CrazyCutters = 1;
            func_8010593C_1E4D8C_CrazyCutters();
            obj->func_ptr = func_80105978_1E4DC8_CrazyCutters;
        }
    } else if (D_80109A9A_1E8EEA_CrazyCutters == -1) {
        if (--D_801098F8_1E8D48_CrazyCutters == 0) {
            D_80109A9A_1E8EEA_CrazyCutters = PlayMusic(0x21);
            D_801098F8_1E8D48_CrazyCutters = 20;
        }
    }
}

void func_80102B64_1E1FB4_CrazyCutters(f32 zoom, f32 rx, f32 ry, f32 rz, f32 cx, f32 cy, f32 cz) {
    func_80018E30_19A30(1);
    D_800FA610_FB210 = zoom;
    D_800FD474_FE074.x = rx;
    D_800FD474_FE074.y = ry;
    D_800FD474_FE074.z = rz;
    D_8010274C_10334C.x = cx;
    D_8010274C_10334C.y = cy;
    D_8010274C_10334C.z = cz;
    Hu3DCamSetPerspective(0, 10.0f, D_800C9B80_CA780->fov[1], D_800C9B80_CA780->fov[2]);
}

void func_80102C18_1E2068_CrazyCutters(omObjData* obj) {
    if (--D_80109900_1E8D50_CrazyCutters == 0) {
        D_801098FC_1E8D4C_CrazyCutters = 1;
        omAddObj(4, 10, 10, 4, func_80105648_1E4A98_CrazyCutters);
        omAddObj(4, 10, 10, 4, func_80105664_1E4AB4_CrazyCutters);
        omAddObj(4, 10, 10, 4, func_80105680_1E4AD0_CrazyCutters);
        omAddObj(4, 10, 10, 4, func_8010569C_1E4AEC_CrazyCutters);
        omAddObj(0, 0, 0, -1, func_80102A44_1E1E94_CrazyCutters);
        omAddObj(2, 1, 1, -1, func_80102D30_1E2180_CrazyCutters);
        InitFadeIn(0, 16);
        omDelObj(obj);
    }
}

__asm__(".section .rodata");
const u32 D_8010945C_1E88AC_CrazyCutters[3] = { 0x00000003, 0x00000004, 0x00000005 };

__asm__(".section .rodata");
const u32 D_80109468_1E88B8_CrazyCutters[3] = { 0x00000019, 0x0000001A, 0x0000001B };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80102D30_1E2180_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_801030B4_1E2504_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_8010332C_1E277C_CrazyCutters);

__asm__(".section .rodata");
const u32 D_80109474_1E88C4_CrazyCutters[6] = { 0x00000023, 0x00000023, 0x00000023, 0x00000023, 0x00000023, 0x00000023 };

__asm__(".section .rodata");
const u32 D_8010948C_1E88DC_CrazyCutters[4] = { 0x00000010, 0x00000008, 0x00000004, 0x00000002 };

__asm__(".section .rodata");
const u32 D_8010949C_1E88EC_CrazyCutters[4] = { 0x00000018, 0x00000012, 0x0000000C, 0x00000006 };

__asm__(".section .rodata");
const u32 D_801094AC_1E88FC_CrazyCutters[3] = { 0x00000009, 0x0000000A, 0x0000000B };

__asm__(".section .rodata");
const char D_801094B8_1E8908_CrazyCutters[] = "16mt000_DEF";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80103508_1E2958_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_801040F0_1E3540_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_8010454C_1E399C_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80104FF4_1E4444_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80105098_1E44E8_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_801050FC_1E454C_CrazyCutters);

__asm__(".section .rodata");
const u32 D_801094C4_1E8914_CrazyCutters[3] = { 0x0000000C, 0x0000000D, 0x0000000E };

__asm__(".section .rodata");
const u32 D_801094D0_1E8920_CrazyCutters[3] = { 0x0000000F, 0x00000010, 0x00000011 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80105254_1E46A4_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80105648_1E4A98_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80105664_1E4AB4_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80105680_1E4AD0_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_8010569C_1E4AEC_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_801056B8_1E4B08_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_801057D8_1E4C28_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80105830_1E4C80_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_8010585C_1E4CAC_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_8010593C_1E4D8C_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80105978_1E4DC8_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80105A74_1E4EC4_CrazyCutters);

__asm__(".section .rodata");
const u32 D_801094DC_1E892C_CrazyCutters[4] = { 0xC3C80000, 0x43C80000, 0xC3C80000, 0x43C80000 };

__asm__(".section .rodata");
const u32 D_801094EC_1E893C_CrazyCutters[4] = { 0xC37A0000, 0xC37A0000, 0x43AF0000, 0x43AF0000 };

__asm__(".section .rodata");
const u32 D_801094FC_1E894C_CrazyCutters[3] = { 0x40866666, 0x40900000, 0x40800000 };

__asm__(".section .rodata");
const u32 D_80109508_1E8958_CrazyCutters[3] = { 0xC1F00000, 0x00000000, 0xC2C80000 };

__asm__(".section .rodata");
const u32 D_80109514_1E8964_CrazyCutters[3] = { 0x00330015, 0x00330016, 0x00330017 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80105B40_1E4F90_CrazyCutters);

__asm__(".section .rodata");
const u32 D_80109520_1E8970_CrazyCutters[4] = { 0x00000012, 0x00000013, 0x00000014, 0x00000000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80105FE4_1E5434_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_801065F4_1E5A44_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_801067D4_1E5C24_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80106A5C_1E5EAC_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80106AD4_1E5F24_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80106B54_1E5FA4_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80106B94_1E5FE4_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80106D28_1E6178_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80106D44_1E6194_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80106D84_1E61D4_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80106EB0_1E6300_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80107204_1E6654_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80107530_1E6980_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_801076B8_1E6B08_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_801077B0_1E6C00_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_801078A8_1E6CF8_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_801079E0_1E6E30_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80107BBC_1E700C_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80107D74_1E71C4_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80107DA4_1E71F4_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80107DFC_1E724C_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80108108_1E7558_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80108214_1E7664_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80108284_1E76D4_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_801084A0_1E78F0_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_801084FC_1E794C_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_801086BC_1E7B0C_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_8010874C_1E7B9C_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_8010882C_1E7C7C_CrazyCutters);
