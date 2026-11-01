#include "ovl_08.h"

void func_801046E0_115B60_LavaTileIsle(void) {
    s32 i;

    D_8010A4E3_11B963_LavaTileIsle = (rand8() * 3U) >> 5;
    func_8000C460_D060();
    D_800FC87A_FD47A = 0;
    for (i = 0; i < 4; i++) {
        omSetStatBit(D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(2, 0xD, 0x3C, -1, func_8010479C_115C1C_LavaTileIsle), 0xA0);
    }
}

void func_8010479C_115C1C_LavaTileIsle(omObjData* obj) {
    MgWork* w;
    s32 dir;
    s32 file;
    s32 i;
    s32 c;
    s32 attr;

    dir = D_800CD438_CE038[(s8)gPlayers[D_8010A200_11B680_LavaTileIsle[D_8010A4E2_11B962_LavaTileIsle]].character].unk_04;
    file = D_800CD438_CE038[(s8)gPlayers[D_8010A200_11B680_LavaTileIsle[D_8010A4E2_11B962_LavaTileIsle]].character].unk_08;
    c = D_8010A210_11B690_LavaTileIsle[D_8010A4E3_11B963_LavaTileIsle][D_8010A4E2_11B962_LavaTileIsle];
    obj->trans.x = D_8010A270_11B6F0_LavaTileIsle[c].x;
    obj->trans.y = D_8010A270_11B6F0_LavaTileIsle[c].y;
    obj->trans.z = D_8010A270_11B6F0_LavaTileIsle[c].z;
    obj->rot.x = obj->rot.y = obj->rot.z = 0.0f;
    obj->work[0] = 0;
    obj->work[1] = 0;
    func_8000C578_D178(1);
    func_8000C6FC_D2FC(obj, dir, file, (s16)D_8010A200_11B680_LavaTileIsle[D_8010A4E2_11B962_LavaTileIsle], 0x8D9, 0x8D9);
    w = obj->unk_50;
    func_8000E0C0_ECC0(w, 0, func_80108648_119AC8_LavaTileIsle);
    func_8000E0C0_ECC0(w, 6, func_80109E5C_11B2DC_LavaTileIsle);
    func_8000E0C0_ECC0(w, 7, func_80109E5C_11B2DC_LavaTileIsle);
    w->unk_3C = func_800B75A8_B81A8(-obj->trans.x, -obj->trans.z);
    attr = 0x88D;
    obj->model[3] = LoadFormFile(7, 0x88D);
    obj->model[4] = LoadFormFile(8, 0x88D);
    obj->model[6] = LoadFormFile(9, 0x88D);
    obj->model[5] = LoadFormFile(0xA, 0x88D);
    obj->model[7] = LoadFormFile(0xC, 0x88D);
    obj->model[8] = LoadFormFile(0xB, 0x88D);
    for (i = 0; i < 4; i++) {
        obj->model[9 + i] = LoadFormFile(0x180002, (u16)attr);
    }
    func_8002D1EC_2DDEC(obj->model[0], 1);
    func_8002D274_2DE74(obj->model[0], 0xFF, 0, 0);
    func_8002D2B4_2DEB4(obj->model[0], -10.0f, -17.0f, 69.0f);
    obj->func_ptr = func_80104C94_116114_LavaTileIsle;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
    func_8002979C_2A39C(obj->model[0], obj->rot.x, obj->rot.y, obj->rot.z);
    func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    func_8000C024_CC24(obj, 0, 2);
    func_8000C024_CC24(obj, 1, 2);
    func_80019F0C_1AB0C(obj, 0, dir, 1, 0);
    func_80019F0C_1AB0C(obj, 1, dir | 1, 1, 0);
    func_80019F0C_1AB0C(obj, 2, dir | 2, 1, 0);
    func_80019F0C_1AB0C(obj, 5, dir | 3, 0, 0);
    func_80019F0C_1AB0C(obj, 6, dir | 4, 1, 0x13);
    func_80019F0C_1AB0C(obj, 8, dir | 6, 1, 0x1D);
    func_80019F0C_1AB0C(obj, 0x12, dir | 0x10, 2, 0);
    func_80019F0C_1AB0C(obj, 0x13, dir | 0x11, 2, 0);
    func_80019F0C_1AB0C(obj, 0x11, dir | 0xF, 0, 0);
    func_80019F0C_1AB0C(obj, 0x15, dir | 0x2E, 0, 0);
    func_80019F0C_1AB0C(obj, 3, dir | 0x2C, 1, 0);
    func_80019F0C_1AB0C(obj, 4, dir | 0x2D, 1, 0);
    func_80019F0C_1AB0C(obj, 0x1E, dir | 0x2F, 0, 0);
    func_80019F0C_1AB0C(obj, 0x1F, dir | 0x30, 0, 0);
    func_80019E84_1AA84(obj, 0x20, dir | 0x31, 0, 0);
    func_80019F0C_1AB0C(obj, 0xD, dir | 0x4E, 1, 0x78);
    func_80019F0C_1AB0C(obj, 0xE, dir | 0x55, 1, 0x78);
    func_80019F0C_1AB0C(obj, 0x26, dir | 0x1C, 1, 0);
    func_80019B9C_1A79C(obj, 0);
    D_8010A4E2_11B962_LavaTileIsle++;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_80104C94_116114_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_801052A8_116728_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_80105400_116880_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_801057C0_116C40_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_80105E34_1172B4_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_80105E80_117300_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_80105F6C_1173EC_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_80106120_1175A0_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_80106444_1178C4_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_801066D4_117B54_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_801069D8_117E58_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_80106F2C_1183AC_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_80107414_118894_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_80107694_118B14_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_80107B24_118FA4_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_80107E3C_1192BC_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_801081C4_119644_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_80108204_119684_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_80108388_119808_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_80108494_119914_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_80108648_119AC8_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_801095BC_11AA3C_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_80109E5C_11B2DC_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_80109E70_11B2F0_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_80109F44_11B3C4_LavaTileIsle);
