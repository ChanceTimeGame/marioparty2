#include "ovl_0E.h"

__asm__(".section .rodata");
const char D_80109AC0_143E50_BowlOver[16] = "\202r\202s\202`\202q\202s";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/13CB90", func_80102800_13CB90_BowlOver);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/13CB90", func_80102E04_13D194_BowlOver);

void func_801040A0_13E430_BowlOver(omObjData* obj) {
    f32 x;
    u8 chr;
    s32 dir;
    s32 file;
    s32 file2;

    x = 0.0f;
    chr = gPlayers[D_8010A0AE_14443E_BowlOver[0]].character;
    dir = D_800CD438_CE038[chr].unk_04;
    file = D_800CD438_CE038[chr].unk_08;
    file2 = D_800CD438_CE038[chr].unk_10;
    switch (D_80109A40_143DD0_BowlOver) {
    case 0:
        x = 35.0f;
        break;
    case 1:
        x = -200.0f;
        break;
    case 2:
        x = -235.0f;
        break;
    }
    func_80104D78_13F108_BowlOver(obj, dir, file, file2, D_8010A0AE_14443E_BowlOver[0], x, 0.0f, 300.0f);
    D_8010A09C_14442C_BowlOver.x = x;
    D_8010A09C_14442C_BowlOver.y = 0.0f;
    D_8010A09C_14442C_BowlOver.z = 300.0f;
}

void func_801041CC_13E55C_BowlOver(omObjData* obj) {
    f32 s;

    s = 0.0f;
    switch ((u16)(D_800CD438_CE038[gPlayers[D_8010A0AE_14443E_BowlOver[0]].character].unk_04 >> 16)) {
    case 3:
    case 6:
        s = 0.6f;
        break;
    case 2:
    case 4:
    case 5:
    case 7:
        s = 0.5f;
        break;
    }
    func_800297E8_2A3E8(obj->model[1], s * 4.0f, 1.0f, s * 4.0f);
    func_800297E8_2A3E8(obj->model[3], s * 4.0f, 1.0f, s * 4.0f);
    func_80029714_2A314(obj->model[1], obj->trans.x, 2.0f, obj->trans.z);
    func_80029714_2A314(obj->model[3], obj->trans.x, 2.0f, obj->trans.z);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/13CB90", func_801042F0_13E680_BowlOver);

__asm__(".section .rodata");
const u32 D_80109B5C_143EEC_BowlOver[5] = { 0x43020000, 0xC3480000, 0xC2A00000, 0xC37A0000, 0xC2F00000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/13CB90", func_8010487C_13EC0C_BowlOver);

void func_80104D78_13F108_BowlOver(omObjData* obj, s32 dir, s32 file, s32 file2, u16 player, f32 x, f32 y, f32 z) {
    BOPlayerWork* w;
    u32 chr;

    obj->unk_50 = func_80027154_27D54(sizeof(BOPlayerWork), 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, sizeof(BOPlayerWork));
    w = BO_WORK(obj);
    w->unk_E8 = func_80027154_27D54(obj->mtncnt * 0xC, 0x7918);
    w->port = gPlayers[player].port;
    obj->model[0] = LoadFormFile(dir | file, 0x6B9);
    obj->model[1] = LoadFormFile(1, 0x6B9);
    obj->model[2] = LoadFormFile(dir | file2, 0x6B9);
    obj->model[3] = func_80027D3C_2893C(obj->model[1]);
    func_80018CCC_198CC(obj, 0, dir | 0x55);
    func_80018CCC_198CC(obj, 1, dir | 0x4E);
    func_80018CCC_198CC(obj, 2, dir | 0x36);
    func_80018CCC_198CC(obj, 3, dir | 0x34);
    func_80018CCC_198CC(obj, 4, dir);
    func_8002D1EC_2DDEC(obj->model[0], 1);
    func_8002D274_2DE74(obj->model[0], 0xFF, 0xA4, 0x1B);
    chr = (u32)dir >> 16;
    func_8002D2B4_2DEB4(obj->model[0], 42.0f, 90.0f, 51.0f);
    func_8002D1EC_2DDEC(obj->model[2], 1);
    func_8002D274_2DE74(obj->model[2], 0xFF, 0xA4, 0x1B);
    func_8002D2B4_2DEB4(obj->model[2], 42.0f, 90.0f, 51.0f);
    func_80029EDC_2AADC(obj->model[0], 2);
    func_80029EDC_2AADC(obj->model[2], 0);
    func_80029EDC_2AADC(obj->model[3], 0);
    func_8000C35C_CF5C(obj, x, y, z);
    func_80029714_2A314(obj->model[0], x, y, z);
    func_8000C36C_CF6C(obj, 0.0f, 180.0f, 0.0f);
    obj->scale.x = 1.5f;
    obj->scale.y = 1.5f;
    obj->scale.z = 1.5f;
    func_80029714_2A314(obj->model[2], x, y, z);
    func_800297E8_2A3E8(obj->model[2], 1.5f, 1.5f, 1.5f);
    func_800297E8_2A3E8(obj->model[1], 4.0f, 1.0f, 4.0f);
    obj->func_ptr = func_8010487C_13EC0C_BowlOver;
    w->unk_52 = 0;
    w->unk_B4 = 1.0f;
    w->unk_D0 = 0xFFFF;
    w->unk_38 = 1000.0f;
    w->unk_50 = 0;
    func_8000BEB0_CAB0(obj, 60.0f);
    func_8000BEBC_CABC(obj, 150.0f);
    func_8000BEC8_CAC8(obj, 20.0f);
    func_8000C024_CC24(obj, 0, 2);
    switch (chr) {
    case 6:
        w->unk_AC = 0.7f;
        break;
    case 4:
        w->unk_AC = 0.9f;
        break;
    case 5:
        w->unk_AC = 0.8f;
        break;
    default:
        w->unk_AC = 1.0f;
        break;
    }
    w->player = player;
    func_80029B80_2A780(obj->model[0], obj->motion[2]);
    func_80029E80_2AA80(obj->model[0], 1, 1);
    func_80029B80_2A780(obj->model[2], obj->motion[2]);
    func_80029E80_2AA80(obj->model[2], 1, 1);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/13CB90", func_801051B4_13F544_BowlOver);

void func_80105974_13FD04_BowlOver(omObjData* obj) {
    BOBallWork* w;

    obj->unk_50 = w = func_80027154_27D54(sizeof(BOBallWork), 0x7918);
    func_800B0EF0_B1AF0(w, 0, sizeof(BOBallWork));
    obj->model[0] = func_80018A64_19664(5, 0x6B9);
    obj->model[1] = func_80018A64_19664(0x1E0001, 0x6B9);
    func_8002D1EC_2DDEC(obj->model[0], 1);
    func_8002D274_2DE74(obj->model[0], 0xFF, 0xA4, 0x1B);
    func_8002D2B4_2DEB4(obj->model[0], 42.0f, 90.0f, 51.0f);
    w->unk_7C = 0;
    w->unk_54 = 1;
    w->unk_44 = 0.1f;
    w->unk_48 = 30.0f;
    w->unk_34 = 50.0f;
    w->unk_3C = 0.0f;
    w->unk_78 = 0;
    w->unk_38 = 1000.0f;
    w->unk_52 = 3;
    w->unk_74 = 0.5f;
    w->unk_50 = 0x20;
    obj->trans.x = 0.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 0.0f;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80029EDC_2AADC(obj->model[1], 0);
    func_800297E8_2A3E8(obj->model[1], 0.0f, 0.0f, 0.0f);
    obj->func_ptr = func_801051B4_13F544_BowlOver;
}

void func_80105AFC_13FE8C_BowlOver(void) {
    omObjData* obj;
    s16 i;

    func_80020070_20C70(2);
    obj = omAddObj(0x7FDA, 0, 0, -1, func_80105D14_1400A4_BowlOver);
    omSetStatBit(obj, 0xA0);
    for (i = 0; i < 2; i++) {
        Hu3DCamSetPerspective(i, 53.0f, 80.0f, 8000.0f);
        CameraViewportSet(i, &D_801099C4_143D54_BowlOver[i], &D_801099DC_143D6C_BowlOver[i]);
        CameraScissorSet(i, &D_801099F4_143D84_BowlOver[i]);
    }
    func_801063D0_140760_BowlOver(0, 939.0f, 326.0f, 0.0f, 0.0f, 0.0f, -86.8f, -4828.6f);
    func_801063D0_140760_BowlOver(1, 1900.0f, 360.5f, 0.0f, 0.0f, 0.0f, 350.0f, -860.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    ViewportSet(1, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_80105D14_1400A4_BowlOver(obj);
}

void func_80105D14_1400A4_BowlOver(omObjData* obj) {
    Vec eye;
    Vec at;
    Vec up;
    f32 rx;
    f32 ry;
    s16 i;

    for (i = 0; i < 2; i++) {
        rx = D_80102770_103370[i].x;
        ry = D_80102770_103370[i].y;
        eye.x = HuMathSin(ry) * func_800B7890_B8490(rx) * D_800F94A8_FA0A8[i] + D_801013B0_101FB0[i].x;
        eye.y = -HuMathSin(rx) * D_800F94A8_FA0A8[i] + D_801013B0_101FB0[i].y;
        eye.z = func_800B7890_B8490(ry) * func_800B7890_B8490(rx) * D_800F94A8_FA0A8[i] + D_801013B0_101FB0[i].z;
        at.x = D_801013B0_101FB0[i].x;
        at.y = D_801013B0_101FB0[i].y;
        at.z = D_801013B0_101FB0[i].z;
        up.x = HuMathSin(ry) * HuMathSin(rx);
        up.y = func_800B7890_B8490(rx);
        up.z = func_800B7890_B8490(ry) * HuMathSin(rx);
        Hu3DCamSetPositionOrientation(i, &eye, &at, &up);
        Hu3DCamUpdateMtx(i);
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/13CB90", func_80105EE4_140274_BowlOver);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/13CB90", func_801063D0_140760_BowlOver);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/13CB90", func_80106450_1407E0_BowlOver);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/13CB90", func_801064C8_140858_BowlOver);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/13CB90", func_8010655C_1408EC_BowlOver);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/13CB90", func_80106648_1409D8_BowlOver);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/13CB90", func_80106704_140A94_BowlOver);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/13CB90", func_801068D0_140C60_BowlOver);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/13CB90", func_801069D0_140D60_BowlOver);

__asm__(".section .rodata");
const u32 D_80109BB4_143F44_BowlOver[7] = { 0x43B8FFBF, 0xC3A28000, 0x43DAA6B9, 0xC3E11429, 0x43A115D2, 0x00000000, 0x00000000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/13CB90", func_80106C94_141024_BowlOver);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/13CB90", func_80106E8C_14121C_BowlOver);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0E_BowlOver/13CB90", func_80106F60_1412F0_BowlOver);
