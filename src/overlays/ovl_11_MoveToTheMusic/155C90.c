#include "ovl_11.h"

__asm__(".section .rodata");
const char D_8010CE10_1602A0_MoveToTheMusic[] = "\202r\202s\202`\202q\202s";

void func_80102800_155C90_MoveToTheMusic(void) {
    omObjData* obj;
    u8 cam;

    func_80020D20_21920(0x20);
    omInitObjMan(0x80, 0);
    func_80079128_79D28();
    func_80029708_2A308(0);
    func_80018E30_19A30(1);
    cam = func_80018E78_19A78();
    ScissorSet(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 50.0f, 200.0f, 5000.0f);
    func_80026D28_27928(2);
    func_80026E00_27A00(0, 0.0f, 0.0f, 90.0f);
    func_80026DAC_279AC(0, 0x20, 0x20, 0x20);
    func_80026E00_27A00(1, -92.0f, -57.0f, 49.0f);
    func_80026DAC_279AC(1, 0, 0, 0);
    omAddObj(0, 0, 0, -1, func_80102B18_155FA8_MoveToTheMusic);
    D_8010D764_160BF4_MoveToTheMusic = obj = omAddObj(8, 0xC, 0xC, -1, func_80104DBC_15824C_MoveToTheMusic);
    omSetStatBit(obj, 0xA0);
    D_8010D780_160C10_MoveToTheMusic[0] = omAddObj(2, 0xE, 0xE, -1, func_80105594_158A24_MoveToTheMusic);
    D_8010D780_160C10_MoveToTheMusic[1] = omAddObj(2, 0xE, 0xE, -1, func_801055C8_158A58_MoveToTheMusic);
    D_8010D780_160C10_MoveToTheMusic[2] = omAddObj(2, 0xE, 0xE, -1, func_801055FC_158A8C_MoveToTheMusic);
    D_8010D780_160C10_MoveToTheMusic[3] = omAddObj(2, 0xE, 0xE, -1, func_80105630_158AC0_MoveToTheMusic);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_8010B7F0_15EC80_MoveToTheMusic), 0xA0);
    func_8007273C_7333C((u8*)D_8010CE10_1602A0_MoveToTheMusic, 1);
    InitFadeIn(0, 0x10);
}

s16 func_80102A68_155EF8_MoveToTheMusic(s32 file) {
    void* data;
    s16 tex;
    u16 id;

    data = DataRead(file);
    tex = func_8003DF08_3EB08(data);
    HuMemMemoryFreePerm(data);
    id = func_80020EBC_21ABC((void*)-1, 0x6B9, 8);
    D_800F86D8_F92D8[id].unk02 = tex;
    func_80021160_21D60(tex, 4, 4);
    HmfModelObjAttrSet(D_800F86D8_F92D8[id].unk00, 0x70000000, 0x70000000);
    return D_800F86D8_F92D8[id].unk00;
}

__asm__(".section .rodata");
const u32 D_8010CE1C_1602AC_MoveToTheMusic[8] = { 0x00010101, 0x01020203, 0x04040101, 0x01010102, 0x02020304, 0x01010101, 0x01020202, 0x02040101 };

__asm__(".section .rodata");
const u32 D_8010CE3C_1602CC_MoveToTheMusic[2] = { 0x01010202, 0x02020204 };

__asm__(".section .rodata");
const u32 D_8010CE44_1602D4_MoveToTheMusic[5] = { 0x01020401, 0x04020201, 0x04020401, 0x04010204, 0x02010000 };

__asm__(".section .rodata");
const u32 D_8010CE58_1602E8_MoveToTheMusic[8] = { 0x01020301, 0x02030102, 0x03010302, 0x01020302, 0x01030102, 0x03020301, 0x01020103, 0x02030000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_11_MoveToTheMusic/155C90", func_80102B18_155FA8_MoveToTheMusic);

__asm__(".section .rodata");
const u32 D_8010CE78_160308_MoveToTheMusic[6] = { 0x00000001, 0x01010000, 0x01000101, 0x00000101, 0x00010001, 0x00010001 };

__asm__(".section .rodata");
const u32 D_8010CE90_160320_MoveToTheMusic[3] = { 0x00140014, 0x000A0000, 0x00000000 };

__asm__(".section .rodata");
const u32 D_8010CE9C_16032C_MoveToTheMusic[3] = { 0x00140014, 0x000A0056, 0x0000004B };

__asm__(".section .rodata");
const u32 D_8010CEA8_160338_MoveToTheMusic[6] = { 0x00000002, 0x00000003, 0x00000007, 0x00000004, 0x00000005, 0x00000006 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_11_MoveToTheMusic/155C90", func_80103424_1568B4_MoveToTheMusic);

__asm__(".section .rodata");
const u32 D_8010CEF8_160388_MoveToTheMusic[9] = { 0x002A000B, 0x002A000C, 0x002A000D, 0x002A000E, 0x002A000F, 0x002A0010, 0x00210010, 0x00210010, 0x00210010 };

__asm__(".section .rodata");
const u32 D_8010CF1C_1603AC_MoveToTheMusic[11] = { 0x00210007, 0x00210006, 0x00210009, 0x0021000A, 0x0021000B, 0x0021000E, 0x0021000F, 0x0021000D, 0x0021000C, 0x00210010, 0x00210008 };

__asm__(".section .rodata");
const u32 D_8010CF48_1603D8_MoveToTheMusic[4] = { 0x00000000, 0xC3480000, 0x00000000, 0x43480000 };

__asm__(".section .rodata");
const u32 D_8010CF58_1603E8_MoveToTheMusic[4] = { 0x42500000, 0x40C00000, 0x40C00000, 0x40C00000 };

__asm__(".section .rodata");
const u32 D_8010CF68_1603F8_MoveToTheMusic[4] = { 0xC39D8000, 0x43848000, 0x43988000, 0x43848000 };

__asm__(".section .rodata");
const char D_8010CF78_160408_MoveToTheMusic[16] = "B8";

__asm__(".section .rodata");
const u32 D_8010CF88_160418_MoveToTheMusic[4] = { 0xC3A00000, 0x43820000, 0x43960000, 0x43820000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_11_MoveToTheMusic/155C90", func_80104DBC_15824C_MoveToTheMusic);

void func_80105568_1589F8_MoveToTheMusic(void) {
    func_8010A730_15DBC0_MoveToTheMusic(D_8010D7D4_160C64_MoveToTheMusic, 0.0f, 0.0f, 1.0f);
}

void func_80105594_158A24_MoveToTheMusic(omObjData* obj) {
    func_80105664_158AF4_MoveToTheMusic(obj, 0);
    obj->func_ptr = func_80105A20_158EB0_MoveToTheMusic;
}

void func_801055C8_158A58_MoveToTheMusic(omObjData* obj) {
    func_80105664_158AF4_MoveToTheMusic(obj, 1);
    obj->func_ptr = func_80105A3C_158ECC_MoveToTheMusic;
}

void func_801055FC_158A8C_MoveToTheMusic(omObjData* obj) {
    func_80105664_158AF4_MoveToTheMusic(obj, 2);
    obj->func_ptr = func_80105A58_158EE8_MoveToTheMusic;
}

void func_80105630_158AC0_MoveToTheMusic(omObjData* obj) {
    func_80105664_158AF4_MoveToTheMusic(obj, 3);
    obj->func_ptr = func_80105A74_158F04_MoveToTheMusic;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_11_MoveToTheMusic/155C90", func_80105664_158AF4_MoveToTheMusic);

void func_80105A20_158EB0_MoveToTheMusic(omObjData* obj) {
    func_80105A90_158F20_MoveToTheMusic(obj, 0);
}

void func_80105A3C_158ECC_MoveToTheMusic(omObjData* obj) {
    func_80105A90_158F20_MoveToTheMusic(obj, 1);
}

void func_80105A58_158EE8_MoveToTheMusic(omObjData* obj) {
    func_80105A90_158F20_MoveToTheMusic(obj, 2);
}

void func_80105A74_158F04_MoveToTheMusic(omObjData* obj) {
    func_80105A90_158F20_MoveToTheMusic(obj, 3);
}

__asm__(".section .rodata");
const u32 D_8010CFD0_160460_MoveToTheMusic[2] = { 0x00400020, 0x00400060 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_11_MoveToTheMusic/155C90", func_80105A90_158F20_MoveToTheMusic);

void func_80106E84_15A314_MoveToTheMusic(s16 mdl, s16 val) {
    HmfModel* m = &D_800FC834_FD434[mdl];
    m->hmf->unk9C->unk08 = val;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_11_MoveToTheMusic/155C90", func_80106EC8_15A358_MoveToTheMusic);

void func_8010A704_15DB94_MoveToTheMusic(s16 grp) {
    func_8010A730_15DBC0_MoveToTheMusic(grp, 0.0f, 0.0f, 1.0f);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_11_MoveToTheMusic/155C90", func_8010A730_15DBC0_MoveToTheMusic);

__asm__(".section .rodata");
const u32 D_8010D3A8_160838_MoveToTheMusic[5] = { 0x43E10000, 0x43898000, 0x43960000, 0x43898000, 0x43E88000 };

__asm__(".section .rodata");
const u32 D_8010D3BC_16084C_MoveToTheMusic[5] = { 0x447A0000, 0x43A28000, 0x4485C000, 0x43A28000, 0x447A0000 };

__asm__(".section .rodata");
const u32 D_8010D3D0_160860_MoveToTheMusic[5] = { 0x42AA0000, 0x42B40000, 0x41700000, 0x42B40000, 0xC2C80000 };

__asm__(".section .rodata");
const u32 D_8010D3E4_160874_MoveToTheMusic[5] = { 0x43020000, 0xC3FF0000, 0x43020000, 0xC3FF0000, 0x43020000 };

__asm__(".section .rodata");
const u32 D_8010D3F8_160888_MoveToTheMusic[5] = { 0x42480000, 0x42140000, 0x422C0000, 0x42140000, 0x41F80000 };

__asm__(".section .rodata");
const u32 D_8010D40C_16089C_MoveToTheMusic[7] = { 0x00010101, 0x01020202, 0x02010101, 0x01020202, 0x02000003, 0x00040000, 0x00000000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_11_MoveToTheMusic/155C90", func_8010B7F0_15EC80_MoveToTheMusic);
