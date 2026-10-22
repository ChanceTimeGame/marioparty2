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
    func_8010568C_3D2EDC_name_61(7, D_80107204_3D4A54_name_61);
    func_801057D4_3D3024_name_61(7, 0, 2, 2);
    D_801074D8_3D4D28_name_61[7]->rot.y = 300.0f;
    func_801058F0_3D3140_name_61(7, 1);
    func_8010568C_3D2EDC_name_61(6, D_8010720C_3D4A5C_name_61);
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

void func_80103EA0_3D16F0_name_61(void) {
    Vec pos;
    Vec2f scr;
    f32 scale;
    s16 hole;
    s32 i;

    for (i = 0; i < 8; i++) {
        if (i != 6) {
            omSetTra(D_801074D8_3D4D28_name_61[i], D_801072F8_3D4B48_name_61[i].x, D_801072F8_3D4B48_name_61[i].y, D_801072F8_3D4B48_name_61[i].z);
            if (i != 7) {
                func_8010568C_3D2EDC_name_61(i, D_80107388_3D4BD8_name_61[i]);
                func_801057D4_3D3024_name_61(i, 0, 2, 2);
            }
            func_800298A4_2A4A4(D_801074D8_3D4D28_name_61[i]->model[0], 4, 0);
            func_80056658_57258(&D_801072F8_3D4B48_name_61[i], OVL61_CAM_POS, D_801074D8_3D4D28_name_61[i]->unk_50);
            func_801058B0_3D3100_name_61(i);
            func_801058F0_3D3140_name_61(i, 5);
        }
    }
    func_801057D4_3D3024_name_61(7, 0, 2, 2);
    HuPrcSleep(70);
    PlaySound(0x4B3);
    func_8008DACC_8E6CC(1, D_801074FA_3D4D4A_name_61, 0xB4);
    func_8010624C_3D3A9C_name_61(D_80107500_3D4D50_name_61, 0xB4, -1, -1);
    func_80106EE0_3D4730_name_61(180, 0.0f, 0.0f, 0.0f, -0.7111111f);
    func_80104DA8_3D25F8_name_61(180.0f);
    func_80106EAC_3D46FC_name_61(0, 0, 0, 0);
    func_8010622C_3D3A7C_name_61(D_80107500_3D4D50_name_61);
    func_80106E88_3D46D8_name_61(D_80107504_3D4D54_name_61);
    HuPrcSleep(45);
    for (i = 0; i < 8; i++) {
        if (i != 6) {
            func_80029E80_2AA80(D_801074D8_3D4D28_name_61[i]->model[0], 1, 1);
            func_800256CC_262CC(2, D_801070A4_3D48F4_name_61[i], 1, 1);
        }
    }
    func_80079A70_7A670(5);
    func_80106EE0_3D4730_name_61(4, 0.0f, 0.0f, 0.0f, 25.6f);
    pos.x = D_801074D8_3D4D28_name_61[6]->trans.x;
    pos.y = D_801074D8_3D4D28_name_61[6]->trans.y + 65.0f;
    pos.z = D_801074D8_3D4D28_name_61[6]->trans.z;
    func_800209C4_215C4(0, &pos, &scr);
    func_80106F84_3D47D4_name_61(&scr);
    hole = func_80106D54_3D45A4_name_61(scr.unk_00, scr.unk_04, 3.5f, 3.5f);
    scale = 3.5f;
    for (i = 6; i >= 2; i--) {
        scale -= 0.5f;
        func_80106F64_3D47B4_name_61(hole, scale, scale);
        HuPrcVSleep();
    }
    func_80106EAC_3D46FC_name_61(0, 0, 0, 0x80);
    HuPrcSleep(30);
    func_80105858_3D30A8_name_61(6, 3, 0, 4, 2);
    while (func_80105ABC_3D330C_name_61(6, &D_801073A0_3D4BF0_name_61, 12.0f) == 0) {
        HuPrcVSleep();
    }
    while (func_801059B0_3D3200_name_61(6, &D_801073A0_3D4BF0_name_61, 18.0f) == 0) {
        pos.x = D_801074D8_3D4D28_name_61[6]->trans.x;
        pos.y = D_801074D8_3D4D28_name_61[6]->trans.y + 65.0f;
        pos.z = D_801074D8_3D4D28_name_61[6]->trans.z;
        func_800209C4_215C4(0, &pos, &scr);
        func_80106F84_3D47D4_name_61(&scr);
        func_80106F44_3D4794_name_61(hole, scr.unk_00, scr.unk_04);
        HuPrcVSleep();
    }
    while (func_80105ABC_3D330C_name_61(6, OVL61_CAM_POS, 12.0f) == 0) {
        HuPrcVSleep();
    }
    func_80105858_3D30A8_name_61(6, 0, 0, 4, 2);
    func_8008DACC_8E6CC(1, D_801074FA_3D4D4A_name_61, 0xB5);
    func_8010624C_3D3A9C_name_61(D_80107500_3D4D50_name_61, 0xB5, -1, -1);
    HuPrcSleep(60);
    func_8010622C_3D3A7C_name_61(D_80107500_3D4D50_name_61);
    func_8008DACC_8E6CC(1, D_801074FA_3D4D4A_name_61, 0xB6);
    func_8010624C_3D3A9C_name_61(D_80107500_3D4D50_name_61, 0xB6, -1, -1);
    HuPrcSleep(60);
    func_8010622C_3D3A7C_name_61(D_80107500_3D4D50_name_61);
    func_80105858_3D30A8_name_61(6, 4, 0, 4, 2);
    func_8008DACC_8E6CC(1, D_801074FA_3D4D4A_name_61, 0xB7);
    func_8010624C_3D3A9C_name_61(D_80107500_3D4D50_name_61, 0xB7, -1, -1);
    HuPrcSleep(25);
    func_80105858_3D30A8_name_61(6, 0, 0, 4, 2);
    HuPrcSleep(24);
    func_8010622C_3D3A7C_name_61(D_80107500_3D4D50_name_61);
    func_80105858_3D30A8_name_61(6, 3, 0, 4, 2);
    while (func_80105ABC_3D330C_name_61(6, &D_801073AC_3D4BFC_name_61, 12.0f) == 0) {
        HuPrcVSleep();
    }
    while (func_801059B0_3D3200_name_61(6, &D_801073AC_3D4BFC_name_61, 18.0f) == 0) {
        pos.x = D_801074D8_3D4D28_name_61[6]->trans.x;
        pos.y = D_801074D8_3D4D28_name_61[6]->trans.y + 65.0f;
        pos.z = D_801074D8_3D4D28_name_61[6]->trans.z;
        func_800209C4_215C4(0, &pos, &scr);
        func_80106F84_3D47D4_name_61(&scr);
        func_80106F44_3D4794_name_61(hole, scr.unk_00, scr.unk_04);
        HuPrcVSleep();
    }
    while (func_80105ABC_3D330C_name_61(6, OVL61_CAM_POS, 12.0f) == 0) {
        HuPrcVSleep();
    }
    func_80105858_3D30A8_name_61(6, 0, 0, 4, 2);
    HuPrcSleep(30);
    func_80106E88_3D46D8_name_61(hole);
    func_80106EE0_3D4730_name_61(4, 0.0f, 0.0f, 0.0f, -25.6f);
    HuPrcSleep(5);
    func_80106EAC_3D46FC_name_61(0, 0, 0, 0);
    for (i = 0; i < 8; i++) {
        func_80029E80_2AA80(D_801074D8_3D4D28_name_61[i]->model[0], 1, 0);
        func_800256CC_262CC(2, D_801070A4_3D48F4_name_61[i], 1, 0);
    }
    func_80079B88_7A788();
    HuPrcSleep(20);
    D_80107194_3D49E4_name_61 = 1;
    omAddPrcObj(func_801046E0_3D1F30_name_61, 0x5000, 0x2000, 0);
    HuPrcSleep(15);
    func_80105858_3D30A8_name_61(6, 1, 0, 4, 2);
    func_8008DACC_8E6CC(1, D_801074FA_3D4D4A_name_61, 0xB8);
    func_8010624C_3D3A9C_name_61(D_80107500_3D4D50_name_61, 0xB8, -1, -1);
    HuPrcSleep(30);
    omAddPrcObj(func_80104C14_3D2464_name_61, 0x5000, 0x2000, 0);
    HuPrcSleep(30);
    InitFadeOut(0, 210);
}

#ifdef NON_MATCHING
/* Control flow: retail keeps the bounce loop unoptimised (33.0f, 5.0f and 0.0f reloaded, the
   landing store duplicated); same logic. */
void func_801046E0_3D1F30_name_61(void) {
    Vec pos;
    Vec2f scr;
    f32 vel;
    s32 i;

    func_80105858_3D30A8_name_61(6, 2, 0, 2, 0);
    for (i = 0; i < D_80107194_3D49E4_name_61; i++) {
        D_801074D8_3D4D28_name_61[6]->trans.y += 33.0f;
        vel = 28.0f;
        if (D_801074D8_3D4D28_name_61[6]->trans.y <= 0.0f) {
            D_801074D8_3D4D28_name_61[6]->trans.y = 0.0f;
        } else {
            do {
                pos.x = D_801074D8_3D4D28_name_61[6]->trans.x;
                pos.y = D_801074D8_3D4D28_name_61[6]->trans.y + 65.0f;
                pos.z = D_801074D8_3D4D28_name_61[6]->trans.z;
                func_800209C4_215C4(0, &pos, &scr);
                func_80106F84_3D47D4_name_61(&scr);
                func_80106F44_3D4794_name_61(D_80107504_3D4D54_name_61, scr.unk_00, scr.unk_04);
                HuPrcVSleep();
                D_801074D8_3D4D28_name_61[6]->trans.y = vel + D_801074D8_3D4D28_name_61[6]->trans.y;
                vel -= 5.0f;
            } while (!(D_801074D8_3D4D28_name_61[6]->trans.y <= 0.0f));
            D_801074D8_3D4D28_name_61[6]->trans.y = 0.0f;
        }
        pos.x = D_801074D8_3D4D28_name_61[6]->trans.x;
        pos.y = D_801074D8_3D4D28_name_61[6]->trans.y + 65.0f;
        pos.z = D_801074D8_3D4D28_name_61[6]->trans.z;
        func_800209C4_215C4(0, &pos, &scr);
        func_80106F84_3D47D4_name_61(&scr);
        func_80106F44_3D4794_name_61(D_80107504_3D4D54_name_61, scr.unk_00, scr.unk_04);
        HuPrcVSleep();
    }
    func_80105858_3D30A8_name_61(6, 0, 0, 2, 2);
    omDelPrcObj(NULL);
    while (1) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_801046E0_3D1F30_name_61);
#endif

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

void func_80105160_3D29B0_name_61(u16 time) {
    Vec pos;
    Vec2f scr;
    Ovl61CurtainWork* work;
    f32 step;
    s32 i;

    i = 0;
    work = D_801074D0_3D4D20_name_61->unk_50;
    step = (-1.1f - work->y) / time;
    D_80107502_3D4D52_name_61 = func_80106D54_3D45A4_name_61(0, work->y + 150.0f, 2.5f, 2.5f);
    while (1) {
        if (++i == 30) {
            func_8008DACC_8E6CC(1, D_801074FA_3D4D4A_name_61, 0xB3);
            func_8010624C_3D3A9C_name_61(D_80107500_3D4D50_name_61, 0xB3, -1, -1);
            D_80107194_3D49E4_name_61 = 2;
            omAddPrcObj(func_801046E0_3D1F30_name_61, 0x5000, 0x2000, 0);
            PlaySound(0x4B3);
            PlaySound(0x123);
        }
        work->y += step;
        if (-1.1f < work->y) {
            work->y = -1.1f;
        }
        func_80029714_2A314(D_801074D0_3D4D20_name_61->model[4], 0.0f, work->y, 0.0f);
        omSetTra(D_801074D8_3D4D28_name_61[7], 0.0f, work->y, -180.0f);
        pos.x = D_801074D8_3D4D28_name_61[7]->trans.x;
        pos.y = D_801074D8_3D4D28_name_61[7]->trans.y + 150.0f;
        pos.z = D_801074D8_3D4D28_name_61[7]->trans.z;
        func_800209C4_215C4(0, &pos, &scr);
        func_80106F84_3D47D4_name_61(&scr);
        func_80106F44_3D4794_name_61(D_80107502_3D4D52_name_61, scr.unk_00, scr.unk_04);
        if (work->y == -1.1f) {
            break;
        }
        HuPrcVSleep();
    }
}

void func_80105398_3D2BE8_name_61(f32 y) {
    ((Ovl61CurtainWork*)D_801074D0_3D4D20_name_61->unk_50)->y = y;
}

void func_801053AC_3D2BFC_name_61(s32 file) {
    Ovl61CurtainWork* work = D_801074D0_3D4D20_name_61->unk_50;

    if (work->anim != -1) {
        func_8001AC44_1B844(work->esp);
        SprAnimKill(work->anim);
        work->esp = -1;
        work->anim = -1;
    }
    work->anim = func_8001A2F8_1AEF8(file);
    work->esp = func_8001AAAC_1B6AC(work->anim, 0, 1);
    espPosSet(work->esp, 160, 110);
    func_8001A708_1B308(work->esp, 0x4000);
}

void func_8010544C_3D2C9C_name_61(void) {
    Hu3DCamSetPerspective(0, 17.0f, 80.0f, 20000.0f);
    Hu3DCamSetPositionOrientation(0, &D_80107080_3D48D0_name_61, &D_8010708C_3D48DC_name_61, &D_80107098_3D48E8_name_61);
    Hu3DCamUpdateMtx(0);
}

#ifdef NON_MATCHING
/* Register allocation: i*4 and &D_801074D8[i] swap s1/s2 after omSetSca. */
void func_801054A0_3D2CF0_name_61(void) {
    Ovl61ChrWork* work;
    s32 i;

    for (i = 0; i < 8; i++) {
        D_801074D8_3D4D28_name_61[i] = omAddObj(0x1F4, 1, 0, -1, NULL);
        D_801074D8_3D4D28_name_61[i]->unk_50 = func_80027154_27D54(sizeof(Ovl61ChrWork), 0x7918);
        D_801074D8_3D4D28_name_61[i]->model[0] = LoadFormFile(D_801073B8_3D4C08_name_61[i], 0x20689);
        omSetTra(D_801074D8_3D4D28_name_61[i], D_801073D8_3D4C28_name_61[i].x, D_801073D8_3D4C28_name_61[i].y, D_801073D8_3D4C28_name_61[i].z);
        omSetRot(D_801074D8_3D4D28_name_61[i], 0.0f, 0.0f, 0.0f);
        if (i != 6) {
            omSetSca(D_801074D8_3D4D28_name_61[i], 1.0f, 1.0f, 1.0f);
        } else {
            omSetSca(D_801074D8_3D4D28_name_61[i], 0.7f, 0.7f, 0.7f);
        }
        work = D_801074D8_3D4D28_name_61[i]->unk_50;
        work->dir.x = work->dir.y = 0.0f;
        work->dir.z = 1.0f;
        func_801058B0_3D3100_name_61(i);
        work->snd = func_80025384_25F84(D_801074D8_3D4D28_name_61[i]->model[0], 2, D_801070A4_3D48F4_name_61[i], D_80107174_3D49C4_name_61[i][1]);
        work->mode = 1;
        func_80029AFC_2A6FC(D_801074D8_3D4D28_name_61[i]->model[0]);
        func_80029E80_2AA80(D_801074D8_3D4D28_name_61[i]->model[0], 2, 2);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_801054A0_3D2CF0_name_61);
#endif

void func_8010568C_3D2EDC_name_61(s32 idx, s32* list) {
    omObjData* obj = D_801074D8_3D4D28_name_61[idx];
    s32 j;
    s32 i;

    func_80105744_3D2F94_name_61(idx);
    obj->mtncnt = list[0];
    obj->motion = HuMemMemoryAllocTemp(list[0] * 2);
    j = 1;
    for (i = 0; i < obj->mtncnt; i++) {
        obj->motion[i] = func_8002C8B8_2D4B8(DataRead(list[j++]), 0x18);
    }
}

void func_80105744_3D2F94_name_61(s32 idx) {
    omObjData* obj = D_801074D8_3D4D28_name_61[idx];
    s32 i;

    func_80029E80_2AA80(obj->model[0], 1, 1);
    if (obj->mtncnt != 0) {
        for (i = 0; i < obj->mtncnt; i++) {
            func_80039018_39C18(obj->motion[i]);
        }
        HuMemMemoryFreeTemp(obj->motion);
        obj->mtncnt = 0;
    }
}

void func_801057D4_3D3024_name_61(s32 idx, s32 mot, s16 arg2, s16 arg3) {
    omObjData** base = D_801074D8_3D4D28_name_61;
    omObjData** obj = &base[idx];

    func_8002C9C0_2D5C0((*obj)->model[0], (*obj)->motion[mot]);
    func_80029E80_2AA80((*obj)->model[0], arg2, arg3);
}

void func_80105858_3D30A8_name_61(s32 idx, s32 mot, s16 arg2, s16 arg3, s16 arg4) {
    omObjData* obj = D_801074D8_3D4D28_name_61[idx];

    func_80029BF0_2A7F0(obj->model[0], obj->motion[mot], arg2, arg3, arg4);
}

void func_801058B0_3D3100_name_61(s32 idx) {
    omObjData** base = D_801074D8_3D4D28_name_61;
    omObjData** obj = &base[idx];

    (*obj)->rot.y = func_80042BE0_437E0((*obj)->unk_50);
}

void func_801058F0_3D3140_name_61(s32 idx, s32 mode) {
    omObjData** base = D_801074D8_3D4D28_name_61;
    omObjData** obj = &base[idx];
    Ovl61ChrWork* work = (*obj)->unk_50;
    s32* list;
    s16 snd;

    if (work->mode != mode) {
        work->mode = mode;
        list = D_80107174_3D49C4_name_61[idx];
        func_8003E888_3F488(work->snd);
        work->snd = snd = func_80025684_26284(list[mode]);
        func_80025554_26154((*obj)->model[0], 2, D_801070A4_3D48F4_name_61[idx], snd);
    }
}

s16 func_801059B0_3D3200_name_61(s32 idx, Vec* target, f32 speed) {
    Vec pos;
    Vec dir;
    omObjData* obj = D_801074D8_3D4D28_name_61[idx];
    f32 dist;

    pos.x = obj->trans.x;
    pos.y = obj->trans.y;
    pos.z = obj->trans.z;
    dist = HuVecDistance(&pos, target);
    if (dist == 0.0f) {
        return 1;
    }
    func_80056658_57258(&pos, target, &dir);
    if (speed <= dist) {
        obj->trans.x += speed * dir.x;
        obj->trans.y += speed * dir.y;
        obj->trans.z += speed * dir.z;
        return 0;
    }
    obj->trans.x = target->x;
    obj->trans.y = target->y;
    obj->trans.z = target->z;
    return 1;
}

s32 func_80105ABC_3D330C_name_61(s32 idx, Vec* target, f32 step) {
    Vec dir;
    Vec pos;
    Ovl61ChrWork* work;
    f32 goal;
    f32 angle;
    f32 diff;

    work = D_801074D8_3D4D28_name_61[idx]->unk_50;
    pos.x = D_801074D8_3D4D28_name_61[idx]->trans.x;
    pos.y = D_801074D8_3D4D28_name_61[idx]->trans.y;
    pos.z = D_801074D8_3D4D28_name_61[idx]->trans.z;
    func_80056658_57258(&pos, target, &dir);
    goal = func_80042BE0_437E0(&dir);
    angle = func_80042BE0_437E0(&work->dir);
    diff = goal - angle;
    if (fabs(diff) > step) {
        if (diff < 0.0f) {
            diff += 360.0f;
        }
        if (diff < 180.0f) {
            if (step < diff) {
                angle += step;
            } else {
                angle += diff;
            }
        } else if (step < 360.0f - diff) {
            angle -= step;
        } else {
            angle -= 360.0f - diff;
        }
    } else {
        angle = goal;
    }
    dir.x = HuMathSin(angle);
    dir.z = func_800B7890_B8490(angle);
    work->dir = dir;
    func_801058B0_3D3100_name_61(idx);
    if (angle == goal) {
        return 1;
    }
    return 0;
}

void func_80105C6C_3D34BC_name_61(void) {
    Ovl61SparkWork* work;
    void* data;
    s32 i;

    D_80107508_3D4D58_name_61 = omAddObj(0x1F4, 0, 0, -1, func_80105DEC_3D363C_name_61);
    work = D_80107508_3D4D58_name_61->unk_50 = func_80027154_27D54(sizeof(Ovl61SparkWork), 0x7918);
    data = DataRead(0xA0226);
    work->tex = func_8003DF08_3EB08(data);
    HuMemMemoryFreePerm(data);
    for (i = 0; i < 16; i++) {
        work->slot[i] = func_80020EBC_21ABC((void*)-1, 0x68D, 8);
        D_800F86D8_F92D8[work->slot[i]].unk02 = work->tex;
        func_80021160_21D60(work->slot[i], 6, 0);
        work->model[i] = D_800F86D8_F92D8[work->slot[i]].unk00;
        func_80021250_21E50(work->slot[i], 0xFF, 0x40, 8);
        func_800211E8_21DE8(work->slot[i], 200);
        HmfModelObjAttrSet(work->model[i], 0x70000000, 0x70000000);
    }
    for (i = 0; i < 16; i++) {
        work->active[i] = 0;
    }
    D_80107508_3D4D58_name_61->work[0] = 0;
    work->delay = 0;
}

void func_80105DEC_3D363C_name_61(omObjData* obj) {
    Vec dir;
    Ovl61SparkWork* work = obj->unk_50;
    s32 i;

    for (i = 0; i < 16; i++) {
        if (work->active[i] != 0) {
            work->pos[i].x += work->vel[i].x;
            work->pos[i].y += work->vel[i].y;
            work->pos[i].z += work->vel[i].z;
            if (work->pos[i].y < 30.0f) {
                work->pos[i].y = 30.0f;
            }
            func_80029714_2A314(work->model[i], work->pos[i].x, work->pos[i].y, work->pos[i].z);
            work->life[i] -= 25.0f;
            if (work->life[i] <= 0.0f) {
                work->active[i] = 0;
                func_800298A4_2A4A4(work->model[i], 4, 4);
            }
            work->scale[i] += 0.12f;
            if (3.0f <= work->scale[i]) {
                work->scale[i] = 3.0f;
            }
            func_800297E8_2A3E8(work->model[i], work->scale[i], work->scale[i], work->scale[i]);
        }
    }
    if (obj->work[0] == 1) {
        if (work->delay == 0) {
            for (i = 0; i < 16; i++) {
                if (work->active[i] == 0) {
                    break;
                }
            }
            if (i != 16) {
                work->active[i] = 1;
                work->delay = 1;
                dir.x = HuMathSin(D_801074D8_3D4D28_name_61[7]->rot.y);
                dir.y = 0.0f;
                dir.z = func_800B7890_B8490(D_801074D8_3D4D28_name_61[7]->rot.y);
                work->vel[i].x = dir.x;
                work->vel[i].y = -0.8f;
                work->vel[i].z = dir.z;
                MBVecNormalize(&work->vel[i]);
                work->vel[i].x *= 25.0f;
                work->vel[i].y *= 25.0f;
                work->vel[i].z *= 25.0f;
                work->pos[i].x = D_801074D8_3D4D28_name_61[7]->trans.x + dir.x * 200.0f;
                work->pos[i].z = D_801074D8_3D4D28_name_61[7]->trans.z + dir.z * 200.0f;
                work->pos[i].y = D_801074D8_3D4D28_name_61[7]->trans.y + 150.0f;
                work->life[i] = 400.0f;
                work->scale[i] = 1.2f;
                func_800298A4_2A4A4(work->model[i], 4, 0);
                func_80029714_2A314(work->model[i], work->pos[i].x, work->pos[i].y, work->pos[i].z);
                func_800297E8_2A3E8(work->model[i], work->scale[i], work->scale[i], work->scale[i]);
            }
        } else {
            work->delay--;
        }
    }
}

s16 func_80106168_3D39B8_name_61(void) {
    Ovl61SparkWork* work = D_80107508_3D4D58_name_61->unk_50;
    s32 i;

    for (i = 0; i < 16; i++) {
        if (work->active[i] != 0) {
            return 1;
        }
    }
    return 0;
}

void func_801061A8_3D39F8_name_61(void) {
    Ovl61SparkWork* work = D_80107508_3D4D58_name_61->unk_50;
    s32 i;

    for (i = 0; i < 16; i++) {
        func_8002308C_23C8C(work->slot[i]);
    }
    omDelObj(D_80107508_3D4D58_name_61);
}

void func_80106208_3D3A58_name_61(void) {
    D_80107508_3D4D58_name_61->work[0] = 1;
}

void func_8010621C_3D3A6C_name_61(void) {
    D_80107508_3D4D58_name_61->work[0] = 0;
}

void func_8010622C_3D3A7C_name_61(s16 win) {
    func_8008D5D8_8E1D8(win);
}

void func_8010624C_3D3A9C_name_61(s16 win, s32 mess, s16 arg2, s16 arg3) {
    func_8008D6F0_8E2F0(win);
    func_800890CC_89CCC(win, mess, arg2, arg3);
}

void func_801062B8_3D3B08_name_61(void) {
    HuSprite* sprite;
    Ovl61Iris* iris;
    s32* p;
    s32 j;
    s32 i;

    D_80107534_3D4D84_name_61 = func_8001A2F8_1AEF8(0x15);
    D_80107536_3D4D86_name_61 = func_8001AAAC_1B6AC(D_80107534_3D4D84_name_61, 0, 1);
    D_80107538_3D4D88_name_61 = D_800F93FC_F9FFC[D_80107536_3D4D86_name_61].grp;
    espDispOff(D_80107536_3D4D86_name_61);
    sprite = func_80082550_83150(D_80107538_3D4D88_name_61, 0);
    D_8010753A_3D4D8A_name_61 = sprite->unk_84->unk14;
    D_8010753C_3D4D8C_name_61 = sprite->unk_84->unk16;
    D_80107540_3D4D90_name_61 = sprite->unk_84->unk08;
    for (i = 0; i < 3; i++) {
        p = D_8010750C_3D4D5C_name_61[i] = func_80027154_27D54(320 * 240, 0x7918);
        for (j = 0; j < 320 * 240 / 4; j++) {
            *p++ = -1;
        }
        D_80107518_3D4D68_name_61[i] = func_80027154_27D54(0x1000, 0x7918);
        func_801066B8_3D3F08_name_61(i, 1);
    }
    iris = D_80107544_3D4D94_name_61 = func_80027154_27D54(sizeof(Ovl61Iris), 0x7918);
    iris->count = 0;
    for (i = 0; i < 4; i++) {
        iris->flags[i] = 0;
        iris->sx[i] = iris->sy[i] = 1.0f;
    }
    iris->fadeTime = 0;
    D_80107524_3D4D74_name_61 = 0;
    D_80107528_3D4D78_name_61 = 0;
    D_8010752C_3D4D7C_name_61 = 0;
    D_80107530_3D4D80_name_61 = 0;
    func_8002838C_28F8C(0, func_8010652C_3D3D7C_name_61, 2);
}

void func_801064A0_3D3CF0_name_61(void) {
    s32 i;

    for (i = 0; i < 3; i++) {
        func_80027340_27F40(D_8010750C_3D4D5C_name_61[i]);
        func_80027340_27F40(D_80107518_3D4D68_name_61[i]);
    }
    func_8001AC44_1B844(D_80107536_3D4D86_name_61);
    SprAnimKill(D_80107534_3D4D84_name_61);
}

void func_8010652C_3D3D7C_name_61(Gfx** gfx, s32 arg1, s32 arg2) {
    s32 i;

    if (D_80107544_3D4D94_name_61->fadeTime != 0) {
        D_80107544_3D4D94_name_61->col[0] += D_80107544_3D4D94_name_61->colStep[0];
        D_80107524_3D4D74_name_61 = D_80107544_3D4D94_name_61->col[0];
        D_80107544_3D4D94_name_61->col[1] += D_80107544_3D4D94_name_61->colStep[1];
        D_80107528_3D4D78_name_61 = D_80107544_3D4D94_name_61->col[1];
        D_80107544_3D4D94_name_61->col[2] += D_80107544_3D4D94_name_61->colStep[2];
        D_8010752C_3D4D7C_name_61 = D_80107544_3D4D94_name_61->col[2];
        D_80107544_3D4D94_name_61->col[3] += D_80107544_3D4D94_name_61->colStep[3];
        D_80107530_3D4D80_name_61 = D_80107544_3D4D94_name_61->col[3];
        D_80107544_3D4D94_name_61->fadeTime--;
    }
    func_80106D18_3D4568_name_61(D_800FDBE0_FE7E0);
    for (i = 0; i < 4; i++) {
        if (D_80107544_3D4D94_name_61->flags[i] & 2) {
            D_80107544_3D4D94_name_61->count--;
            D_80107544_3D4D94_name_61->flags[i] = 0;
        }
    }
    for (i = 0; i < 4; i++) {
        if ((D_80107544_3D4D94_name_61->flags[i] & 1) && !(D_80107544_3D4D94_name_61->flags[i] & 4)) {
            func_80106A04_3D4254_name_61(D_800FDBE0_FE7E0, i);
        }
    }
    func_801066B8_3D3F08_name_61(D_800FDBE0_FE7E0, 1);
    gSPDisplayList((*gfx)++, D_80107518_3D4D68_name_61[D_800FDBE0_FE7E0]);
}

void func_801066B8_3D3F08_name_61(s32 fb, s16 build) {
    Gfx* gfx = D_80107518_3D4D68_name_61[fb];
    s32 row;

    if (build != 0) {
        gDPPipeSync(gfx++);
        gDPSetAlphaDither(gfx++, G_AD_DISABLE);
        gSPClearGeometryMode(gfx++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
        gSPSetGeometryMode(gfx++, G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
        gDPSetCycleType(gfx++, G_CYC_1CYCLE);
        gDPSetRenderMode(gfx++, 0x504240, 0);
        gDPSetPrimColor(gfx++, 0, 0, D_80107524_3D4D74_name_61, D_80107528_3D4D78_name_61, D_8010752C_3D4D7C_name_61, D_80107530_3D4D80_name_61);
        gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);
        gDPSetBlendColor(gfx++, 0, 0, 0, 1);
        gDPSetAlphaCompare(gfx++, G_AC_THRESHOLD);
        gDPSetTextureFilter(gfx++, G_TF_BILERP);
        gDPSetTexturePersp(gfx++, G_TP_NONE);
        gDPSetTextureLUT(gfx++, G_TT_NONE);
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 0, 0, 320, 240);
        for (row = 0; row < 240; row += 6) {
            gDPLoadTextureTile(gfx++, D_8010750C_3D4D5C_name_61[fb], G_IM_FMT_I, G_IM_SIZ_8b, 320, 240, 0, row, 320, row + 6, 0,
                               G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(gfx++, 0, row << 2, (320 << 2) - 1, ((row + 6) << 2) - 1, G_TX_RENDERTILE, 0, row << 5, 1 << 10, 1 << 10);
        }
    }
    gSPEndDisplayList(gfx++);
}

#ifdef NON_MATCHING
/* Float register allocation (invSy f16, u0 f14) and the pixel sum: retail subtracts 0xFF from
   *p after loading the texel. */
void func_80106A04_3D4254_name_61(s32 fb, s32 hole) {
    f32 invSx;
    f32 invSy;
    f32 hw;
    f32 hh;
    f32 u0;
    f32 u;
    f32 v;
    f32 base;
    s32 x0;
    s32 x1;
    s32 y0;
    s32 y1;
    s32 x;
    s32 y;
    s32 c;
    u8* row;
    u8* p;

    v = 0.0f;
    invSx = 1.0f / D_80107544_3D4D94_name_61->sx[hole];
    invSy = 1.0f / D_80107544_3D4D94_name_61->sy[hole];
    hw = (D_8010753A_3D4D8A_name_61 / 2.0f) * D_80107544_3D4D94_name_61->sx[hole];
    hh = (D_8010753C_3D4D8C_name_61 / 2.0f) * D_80107544_3D4D94_name_61->sy[hole];
    x0 = D_80107544_3D4D94_name_61->x[hole] - hw;
    x1 = D_80107544_3D4D94_name_61->x[hole] + hw;
    y0 = D_80107544_3D4D94_name_61->y[hole] - hh;
    y1 = D_80107544_3D4D94_name_61->y[hole] + hh;
    u0 = 0.0f;
    if (x0 < 0) {
        u0 = -x0 * invSx;
        x0 = 0;
    }
    if (x1 > 320) {
        x1 = 320;
    }
    if (y0 < 0) {
        v = -y0 * invSy;
        y0 = 0;
    }
    if (y1 > 240) {
        y1 = 240;
    }
    row = D_8010750C_3D4D5C_name_61[fb] + x0 + y0 * 320;
    if (D_80107544_3D4D94_name_61->count >= 2) {
        for (y = y0; y < y1; y++) {
            p = row;
            base = D_8010753A_3D4D8A_name_61 * (s32)v;
            u = u0;
            for (x = x0; x < x1; x++) {
                c = *p - 0xFF;
                c = D_80107540_3D4D90_name_61[(s32)(base + u)] + c;
                *p = c & (~c >> 31);
                p++;
                u += invSx;
            }
            v += invSy;
            row += 320;
        }
    } else {
        for (y = y0; y < y1; y++) {
            p = row;
            base = D_8010753A_3D4D8A_name_61 * (s32)v;
            u = u0;
            for (x = x0; x < x1; x++) {
                *p = D_80107540_3D4D90_name_61[(s32)(base + u)];
                p++;
                u += invSx;
            }
            v += invSy;
            row += 320;
        }
    }
    D_80107544_3D4D94_name_61->fbX[fb][hole] = D_80107544_3D4D94_name_61->x[hole];
    D_80107544_3D4D94_name_61->fbY[fb][hole] = D_80107544_3D4D94_name_61->y[hole];
    D_80107544_3D4D94_name_61->fbSx[fb][hole] = D_80107544_3D4D94_name_61->sx[hole];
    D_80107544_3D4D94_name_61->fbSy[fb][hole] = D_80107544_3D4D94_name_61->sy[hole];
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_61_name/3D0050", func_80106A04_3D4254_name_61);
#endif

void func_80106D18_3D4568_name_61(s32 fb) {
    s32* p = (s32*)D_8010750C_3D4D5C_name_61[fb];
    s32 i;

    for (i = 0; i < 320 * 240; i += 4) {
        *p++ = -1;
    }
}

s16 func_80106D54_3D45A4_name_61(s32 x, s32 y, f32 sx, f32 sy) {
    s16 i;
    s16 j;

    for (i = 0; i < 4; i++) {
        if (D_80107544_3D4D94_name_61->flags[i] == 0) {
            break;
        }
    }
    if (i == 4) {
        return -1;
    }
    D_80107544_3D4D94_name_61->count++;
    D_80107544_3D4D94_name_61->flags[i] |= 1;
    for (j = 0; j < 3; j++) {
        D_80107544_3D4D94_name_61->fbX[j][i] = D_80107544_3D4D94_name_61->x[i] = x;
        D_80107544_3D4D94_name_61->fbY[j][i] = D_80107544_3D4D94_name_61->y[i] = y;
        D_80107544_3D4D94_name_61->fbSx[j][i] = D_80107544_3D4D94_name_61->sx[i] = sx;
        D_80107544_3D4D94_name_61->fbSy[j][i] = D_80107544_3D4D94_name_61->sy[i] = sy;
    }
    return i;
}

void func_80106E88_3D46D8_name_61(s16 hole) {
    D_80107544_3D4D94_name_61->flags[hole] |= 2;
}

void func_80106EAC_3D46FC_name_61(u8 r, u8 g, u8 b, u8 a) {
    D_80107524_3D4D74_name_61 = r;
    D_80107528_3D4D78_name_61 = g;
    D_8010752C_3D4D7C_name_61 = b;
    D_80107530_3D4D80_name_61 = a;
}

void func_80106EE0_3D4730_name_61(s16 time, f32 dr, f32 dg, f32 db, f32 da) {
    D_80107544_3D4D94_name_61->fadeTime = time;
    D_80107544_3D4D94_name_61->colStep[0] = dr;
    D_80107544_3D4D94_name_61->colStep[1] = dg;
    D_80107544_3D4D94_name_61->colStep[2] = db;
    D_80107544_3D4D94_name_61->colStep[3] = da;
    D_80107544_3D4D94_name_61->col[0] = D_80107524_3D4D74_name_61;
    D_80107544_3D4D94_name_61->col[1] = D_80107528_3D4D78_name_61;
    D_80107544_3D4D94_name_61->col[2] = D_8010752C_3D4D7C_name_61;
    D_80107544_3D4D94_name_61->col[3] = D_80107530_3D4D80_name_61;
}

void func_80106F44_3D4794_name_61(s16 hole, s16 x, s16 y) {
    D_80107544_3D4D94_name_61->x[hole] = x;
    D_80107544_3D4D94_name_61->y[hole] = y;
}

void func_80106F64_3D47B4_name_61(s16 hole, f32 sx, f32 sy) {
    D_80107544_3D4D94_name_61->sx[hole] = sx;
    D_80107544_3D4D94_name_61->sy[hole] = sy;
}

void func_80106F84_3D47D4_name_61(Vec2f* pos) {
    f32 x = pos->unk_00;
    f32 y = pos->unk_04;
    s32 ix = x;
    s32 iy = y;
    f32 fx = ix;
    f32 dx = x - fx;
    f32 dy = y - (f32)iy;

    if (dx >= 0.5f) {
        pos->unk_00 = fx + 1.0f;
    }
    if (dy >= 0.5f) {
        pos->unk_04 = (f32)iy + 1.0f;
    }
}

void func_80107030_3D4880_name_61(s16 hole) {
    D_80107544_3D4D94_name_61->flags[hole] |= 4;
}

void func_80107054_3D48A4_name_61(s16 hole) {
    D_80107544_3D4D94_name_61->flags[hole] &= ~4;
}
