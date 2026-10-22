#include "ovl_61.h"

void func_80102800_3D0050_name_61(void) {
    TextWindow* win;

    omInitObjMan(0x14, 0xA);
    func_80079128_79D28();
    func_80020D20_21920(0x1A);
    D_801074F8_3D4D48_name_61 = 0;
    func_80088640_89240();
    D_80107500_3D4D50_name_61 = func_800888A8_894A8(0x24, 0xC4, 0x102, 0x22, 0, 0);
    func_80089B2C_8A72C(D_80107500_3D4D50_name_61, 0);
    func_80089A48_8A648(D_80107500_3D4D50_name_61, 0);
    func_80089C78_8A878(D_80107500_3D4D50_name_61, 1);
    func_80089DA0_8A9A0(D_80107500_3D4D50_name_61, 0xC0, 0xC0, 0xC0);
    func_8008D530_8E130(D_80107500_3D4D50_name_61, 0, 0, 0);
    win = &D_800F920C_F9E0C[D_80107500_3D4D50_name_61];
    SprPrioSet(win->unk_6C, func_80089404_8A004(D_80107500_3D4D50_name_61, 0xE0015, 0x7B, 0x10, 0), 15000);
    func_8008D5D8_8E1D8(D_80107500_3D4D50_name_61);
    func_80018E30_19A30(1);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_80088640_89240();
    omAddPrcObj(func_80102B50_3D03A0_name_61, 0x5000, 0x2000, 0);
    func_8010492C_3D217C_name_61();
    omAddObj(0x7FDA, 0, 0, -1, func_8010544C_3D2C9C_name_61);
    omAddObj(0x2000, 0, 0, -1, func_80102A10_3D0260_name_61);
    func_801062B8_3D3B08_name_61();
}

void func_80102A10_3D0260_name_61(void) {
    s32 i;

    if (D_801011FC_101DFC != 0 || D_801074F8_3D4D48_name_61 != 0) {
        for (i = 0; i < 8; i++) {
            omDelObj(D_801074D8_3D4D28_name_61[i]);
        }
        func_8008CE5C_8DA5C();
        func_801064A0_3D3CF0_name_61();
        if (D_801011FC_101DFC == 0) {
            omOvlGotoEx(0x72, 0, 0x94);
        } else {
            func_800794A8_7A0A8(0xA);
            func_80015950_16550(0xA);
            omOvlReturnEx(1);
        }
    }
}

void func_80102AC8_3D0318_name_61(void) {
    s32 i;

    if (_CheckFlag(0x1A) != 0) {
        for (i = 0; i < 4; i++) {
            if (HuGetPadInserted(i) != 0 && (ContBtnTrg[i] & 0x1000)) {
                D_801011FC_101DFC = 1;
            }
        }
    }
}

void func_80102B50_3D03A0_name_61(void) {
    func_80102BC0_3D0410_name_61();
    func_80102F74_3D07C4_name_61();
    func_80103EA0_3D16F0_name_61();
    HuPrcSleep(150);
    func_800794A8_7A0A8(120);
    func_80079614_7A214(120);
    HuPrcSleep(60);
    D_801074F8_3D4D48_name_61 = 1;
    omDelPrcObj(NULL);
    while (1) {
        HuPrcVSleep();
    }
}

void func_80102BC0_3D0410_name_61(void) {
    s16 model;
    s32 i;

    func_801053AC_3D2BFC_name_61(0xE0011);
    model = LoadFormFile(0xF003B, 0x699);
    func_80029714_2A314(model, D_80107198_3D49E8_name_61.x, D_80107198_3D49E8_name_61.y, D_80107198_3D49E8_name_61.z);
    func_801054A0_3D2CF0_name_61();
    for (i = 0; i < 6; i++) {
        func_8010568C_3D2EDC_name_61(i, D_801071EC_3D4A3C_name_61[i]);
        func_80029E80_2AA80(D_801074D8_3D4D28_name_61[i]->model[0], 3, 2);
    }
    func_8010568C_3D2EDC_name_61(7, &D_80107204_3D4A54_name_61);
    func_801057D4_3D3024_name_61(7, 0, 2, 2);
    D_801074D8_3D4D28_name_61[7]->rot.y = 300.0f;
    func_801058F0_3D3140_name_61(7, 1);
    func_8010568C_3D2EDC_name_61(6, &D_8010720C_3D4A5C_name_61);
    func_801057D4_3D3024_name_61(6, 0, 2, 2);
    InitFadeIn(0, 0x10);
    HuPrcSleep(0x10);
    if (_CheckFlag(0x1A) != 0) {
        PlayMusic(0x3F);
        omAddObj(0x4E20, 0, 0, -1, func_80102AC8_3D0318_name_61);
    }
    PlaySound(0x4B2);
    HuPrcSleep(14);
    for (i = 0; i < 6; i++) {
        func_80105858_3D30A8_name_61(i, 1, 0, 2, 0);
    }
    HuPrcSleep(50);
    for (i = 0; i < 6; i++) {
        func_80105858_3D30A8_name_61(i, 0, 0, 15, 2);
    }
    HuPrcSleep(20);
    func_8008DACC_8E6CC(1, D_801074FA_3D4D4A_name_61, 0xAB);
    func_8010624C_3D3A9C_name_61(D_80107500_3D4D50_name_61, 0xAB, -1, -1);
    HuPrcSleep(100);
    func_8010622C_3D3A7C_name_61(D_80107500_3D4D50_name_61);
    func_8008DACC_8E6CC(1, D_801074FA_3D4D4A_name_61, 0xAC);
    func_8010624C_3D3A9C_name_61(D_80107500_3D4D50_name_61, 0xAC, -1, -1);
    HuPrcSleep(100);
    func_80105858_3D30A8_name_61(6, 4, 0, 4, 2);
    func_8008DACC_8E6CC(1, D_801074FA_3D4D4A_name_61, 0xAD);
    func_8010624C_3D3A9C_name_61(D_80107500_3D4D50_name_61, 0xAD, -1, -1);
    HuPrcSleep(25);
    func_80105858_3D30A8_name_61(6, 0, 0, 4, 2);
    HuPrcSleep(5);
    func_80106EE0_3D4730_name_61(180, 0.0f, 0.0f, 0.0f, 0.7111111f);
    func_80104A90_3D22E0_name_61(180.0f);
    func_80106EAC_3D46FC_name_61(0, 0, 0, 0x80);
    func_8010622C_3D3A7C_name_61(D_80107500_3D4D50_name_61);
    func_801053AC_3D2BFC_name_61(0xF003C);
    for (i = 0; i < 6; i++) {
        func_800298A4_2A4A4(D_801074D8_3D4D28_name_61[i]->model[0], 4, 4);
    }
    func_800298A4_2A4A4(D_801074D8_3D4D28_name_61[7]->model[0], 4, 4);
    func_800283DC_28FDC(model);
}

__asm__(".section .rodata");
const u32 D_80107470_3D4CC0_name_61[6] = { 0x00000000, 0x0000003A, 0x00000026, 0x0000002D, 0x0000001E, 0x0000001E };

__asm__(".section .rodata");
const u32 D_80107488_3D4CD8_name_61[6] = { 0x000000F5, 0x000000F5, 0x0000010A, 0x00000103, 0x000000F5, 0x000000F5 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_80102F74_3D07C4_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_80103EA0_3D16F0_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_801046E0_3D1F30_name_61);

void func_8010492C_3D217C_name_61(void) {
    Ovl61CurtainWork* work;
    f32 y;

    D_801074D0_3D4D20_name_61 = omAddObj(0x1F4, 5, 0, -1, func_80104A88_3D22D8_name_61);
    work = D_801074D0_3D4D20_name_61->unk_50 = func_80027154_27D54(sizeof(Ovl61CurtainWork), 0x7918);
    work->anim = -1;
    work->esp = -1;
    y = -1.1f;
    work->y = y;
    D_801074D0_3D4D20_name_61->model[0] = LoadFormFile(0xE0000, 0x689);
    omSetTra(D_801074D0_3D4D20_name_61, 0.0f, 0.0f, 0.0f);
    omSetRot(D_801074D0_3D4D20_name_61, 0.0f, 0.0f, 0.0f);
    omSetSca(D_801074D0_3D4D20_name_61, 1.0f, 1.0f, 1.0f);
    D_801074D0_3D4D20_name_61->model[4] = LoadFormFile(0xE0001, 0x689);
    func_80029714_2A314(D_801074D0_3D4D20_name_61->model[4], 0.0f, y, 0.0f);
    func_8002979C_2A39C(D_801074D0_3D4D20_name_61->model[4], 0.0f, 0.0f, 0.0f);
    func_800297E8_2A3E8(D_801074D0_3D4D20_name_61->model[4], 1.0f, 1.0f, 1.0f);
}

void func_80104A88_3D22D8_name_61(void) {
}

void func_80104A90_3D22E0_name_61(f32 time) {
    f32 t;
    s32 i;

    t = 0.0f;
    D_801074D0_3D4D20_name_61->model[1] = LoadFormFile(0xE0004, 0x689);
    D_801074D0_3D4D20_name_61->model[2] = LoadFormFile(0xE0005, 0x68D);
    func_8002A00C_2AC0C(D_801074D0_3D4D20_name_61->model[1]);
    func_8002A4E0_2B0E0(D_801074D0_3D4D20_name_61->model[1], D_801074D0_3D4D20_name_61->model[2], 0.0f, "C161_000-donchou", "C161_000-donchou2", 0);
    for (i = 0; i < time + 3.0f; i++) {
        t += 1.0f / time;
        if (t > 1.0f) {
            t = 1.0f;
        }
        func_8002A4E0_2B0E0(D_801074D0_3D4D20_name_61->model[1], D_801074D0_3D4D20_name_61->model[2], t, "C161_000-donchou", "C161_000-donchou2", 0);
        HuPrcVSleep();
    }
}

void func_80104C14_3D2464_name_61(void) {
    f32 time;
    f32 t;
    s32 i;

    t = 0.0f;
    time = 180.0f;
    D_80107506_3D4D56_name_61 = 0;
    D_801074D0_3D4D20_name_61->model[1] = LoadFormFile(0xE0004, 0x689);
    D_801074D0_3D4D20_name_61->model[2] = LoadFormFile(0xE0005, 0x68D);
    func_8002A00C_2AC0C(D_801074D0_3D4D20_name_61->model[1]);
    func_8002A4E0_2B0E0(D_801074D0_3D4D20_name_61->model[1], D_801074D0_3D4D20_name_61->model[2], 0.0f, "C161_000-donchou", "C161_000-donchou2", 0);
    for (i = 0; i < time + 3.0f; i++) {
        t += 1.0f / time;
        if (t > 1.0f) {
            t = 1.0f;
        }
        func_8002A4E0_2B0E0(D_801074D0_3D4D20_name_61->model[1], D_801074D0_3D4D20_name_61->model[2], t, "C161_000-donchou", "C161_000-donchou2", 0);
        HuPrcVSleep();
    }
    D_80107506_3D4D56_name_61 = 1;
    omDelPrcObj(NULL);
    while (1) {
        HuPrcVSleep();
    }
}

void func_80104DA8_3D25F8_name_61(f32 time) {
    f32 t;
    s32 i;

    t = 1.0f;
    D_801074D0_3D4D20_name_61->model[3] = LoadFormFile(0xE000E, 0x68D);
    for (i = 0; i < time; i++) {
        t -= 1.0f / time;
        if (t < 0.0f) {
            t = 0.0f;
        }
        func_8002A4E0_2B0E0(D_801074D0_3D4D20_name_61->model[1], D_801074D0_3D4D20_name_61->model[2], t, "C161_000-donchou", "C161_000-donchou2", 0);
        HuPrcVSleep();
    }
    func_80029B80_2A780(D_801074D0_3D4D20_name_61->model[1], D_801074D0_3D4D20_name_61->model[3]);
    HuPrcSleep(10);
    func_800283DC_28FDC(D_801074D0_3D4D20_name_61->model[1]);
    func_800283DC_28FDC(D_801074D0_3D4D20_name_61->model[2]);
    func_800283DC_28FDC(D_801074D0_3D4D20_name_61->model[3]);
    HuPrcSleep(3);
}

void func_80104F24_3D2774_name_61(void) {
    f32 time;
    f32 t;
    s32 i;

    time = 180.0f;
    t = 1.0f;
    D_801074D0_3D4D20_name_61->model[3] = LoadFormFile(0xE000E, 0x68D);
    for (i = 0; i < time; i++) {
        t -= 1.0f / time;
        if (t < 0.0f) {
            t = 0.0f;
        }
        func_8002A4E0_2B0E0(D_801074D0_3D4D20_name_61->model[1], D_801074D0_3D4D20_name_61->model[2], t, "C161_000-donchou", "C161_000-donchou2", 0);
        HuPrcVSleep();
    }
    func_80029B80_2A780(D_801074D0_3D4D20_name_61->model[1], D_801074D0_3D4D20_name_61->model[3]);
    HuPrcSleep(10);
    func_800283DC_28FDC(D_801074D0_3D4D20_name_61->model[1]);
    func_800283DC_28FDC(D_801074D0_3D4D20_name_61->model[2]);
    func_800283DC_28FDC(D_801074D0_3D4D20_name_61->model[3]);
    HuPrcSleep(3);
    omDelPrcObj(NULL);
    while (1) {
        HuPrcVSleep();
    }
}

void func_8010509C_3D28EC_name_61(f32 y, u16 time) {
    Ovl61CurtainWork* work = D_801074D0_3D4D20_name_61->unk_50;
    f32 step = y / time;

    while (1) {
        work->y += step;
        if (work->y < y) {
            work->y = y;
        }
        func_80029714_2A314(D_801074D0_3D4D20_name_61->model[4], 0.0f, work->y, 0.0f);
        if (work->y == y) {
            break;
        }
        HuPrcVSleep();
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_80105160_3D29B0_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_80105398_3D2BE8_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_801053AC_3D2BFC_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_8010544C_3D2C9C_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_801054A0_3D2CF0_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_8010568C_3D2EDC_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_80105744_3D2F94_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_801057D4_3D3024_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_80105858_3D30A8_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_801058B0_3D3100_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_801058F0_3D3140_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_801059B0_3D3200_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_80105ABC_3D330C_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_80105C6C_3D34BC_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_80105DEC_3D363C_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_80106168_3D39B8_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_801061A8_3D39F8_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_80106208_3D3A58_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_8010621C_3D3A6C_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_8010622C_3D3A7C_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_8010624C_3D3A9C_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_801062B8_3D3B08_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_801064A0_3D3CF0_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_8010652C_3D3D7C_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_801066B8_3D3F08_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_80106A04_3D4254_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_80106D18_3D4568_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_80106D54_3D45A4_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_80106E88_3D46D8_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_80106EAC_3D46FC_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_80106EE0_3D4730_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_80106F44_3D4794_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_80106F64_3D47B4_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_80106F84_3D47D4_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_80107030_3D4880_name_61);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_80107054_3D48A4_name_61);
