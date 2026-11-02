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

void func_80102B18_155FA8_MoveToTheMusic(omObjData* obj) {
    s32 i;
    s32 k;

    D_8010D80C_160C9C_MoveToTheMusic = 0;
    D_8010D7CC_160C5C_MoveToTheMusic = 0;
    D_8010D798_160C28_MoveToTheMusic = 0;
    D_8010D7E8_160C78_MoveToTheMusic = 0;
    D_8010D7D0_160C60_MoveToTheMusic = 0;
    D_8010D796_160C26_MoveToTheMusic = 0;
    D_8010D79C_160C2C_MoveToTheMusic[0] = D_8010D79C_160C2C_MoveToTheMusic[1] = D_8010D79C_160C2C_MoveToTheMusic[2] = D_8010D79C_160C2C_MoveToTheMusic[3] = 0;
    D_8010D7A4_160C34_MoveToTheMusic[0] = D_8010D7A4_160C34_MoveToTheMusic[1] = D_8010D7A4_160C34_MoveToTheMusic[2] = D_8010D7A4_160C34_MoveToTheMusic[3] = 0;
    D_8010D768_160BF8_MoveToTheMusic[0] = D_8010D768_160BF8_MoveToTheMusic[1] = D_8010D768_160BF8_MoveToTheMusic[2] = D_8010D768_160BF8_MoveToTheMusic[3] = 0;
    D_8010D738_160BC8_MoveToTheMusic[0] = D_8010D738_160BC8_MoveToTheMusic[1] = D_8010D738_160BC8_MoveToTheMusic[2] = D_8010D738_160BC8_MoveToTheMusic[3] = 0;
    D_8010D741_160BD1_MoveToTheMusic[0] = D_8010D741_160BD1_MoveToTheMusic[1] = D_8010D741_160BD1_MoveToTheMusic[2] = D_8010D738_160BC8_MoveToTheMusic[3] = 0;
    D_8010D75A_160BEA_MoveToTheMusic = 100;
    D_8010D758_160BE8_MoveToTheMusic = 0;
    D_8010D720_160BB0_MoveToTheMusic = -1;
    D_8010D7CE_160C5E_MoveToTheMusic = D_800FA656;
    D_8010D740_160BD0_MoveToTheMusic = 0;
    if (D_8010D7CE_160C5E_MoveToTheMusic != 0) {
        D_8010CC00_160090_MoveToTheMusic[0][5] = 1;
    }
    for (i = 0; i < 4; i++) {
        D_8010D708_160B98_MoveToTheMusic[i] = &D_8010D690_160B20_MoveToTheMusic[i];
        bzero(D_8010D708_160B98_MoveToTheMusic[i], sizeof(MMPlayer));
    }
    for (i = 0, k = 1; i < 4; i++) {
        D_8010D708_160B98_MoveToTheMusic[i]->player = i;
        D_8010D708_160B98_MoveToTheMusic[i]->port = gPlayers[i].port;
        D_8010D708_160B98_MoveToTheMusic[i]->character = gPlayers[i].character;
        D_8010D708_160B98_MoveToTheMusic[i]->cell = gPlayers[i].group != 0 ? k : 0;
        D_8010D7C8_160C58_MoveToTheMusic[D_8010D708_160B98_MoveToTheMusic[i]->cell] = i;
        k += gPlayers[i].group != 0;
        D_8010D708_160B98_MoveToTheMusic[i]->cpu = gPlayers[D_8010D708_160B98_MoveToTheMusic[i]->player].flags & 1 ? gPlayers[D_8010D708_160B98_MoveToTheMusic[i]->player].cpu_difficulty : -1;
    }
    for (i = 0; i < 4; i++) {
        s16 row = 0;
        s16 col = 0;
        u8 pick[4][10] = { { 0, 1, 1, 1, 1, 2, 2, 3, 4, 4 }, { 1, 1, 1, 1, 1, 2, 2, 2, 3, 4 },
                           { 1, 1, 1, 1, 1, 2, 2, 2, 2, 4 }, { 1, 1, 1, 1, 2, 2, 2, 2, 2, 4 } };
        s16 n;
        s8 cpu;
        s32 t;

        cpu = D_8010D708_160B98_MoveToTheMusic[i]->cpu;
        if (cpu < 4) if (cpu >= 0) {
            for (n = 0; n < 12; n++) {
                if (D_8010CC00_160090_MoveToTheMusic[row][col] == 0) {
                    n--;
                    D_8010D708_160B98_MoveToTheMusic[i]->step[row][col] = 0;
                    D_8010D708_160B98_MoveToTheMusic[i]->offs[row][col] = 0;
                } else {
                    s16 v = (s8)pick[D_8010D708_160B98_MoveToTheMusic[i]->cpu][rand8() % 10];

                    if (D_8010D708_160B98_MoveToTheMusic[i]->cell == 0) {
                        D_8010D708_160B98_MoveToTheMusic[i]->step[row][col] = v == 0 ? 0 : rand8() % 7 + 2;
                        D_8010D708_160B98_MoveToTheMusic[i]->offs[row][col] = rand8() % 5 - 2;
                    } else {
                        D_8010D708_160B98_MoveToTheMusic[i]->step[row][col] = (v + 1) / 2;
                        D_8010D708_160B98_MoveToTheMusic[i]->offs[row][col] = (v & 1) ? (rand8() & 1) * 5 - 2 : 0;
                    }
                }
                col++;
                t = row;
                if (col >= 12) {
                    row = t + 1;
                } else {
                    row = t;
                }
                col %= 12;
            }
        }
    }
    D_8010D770_160C00_MoveToTheMusic[0] = D_8010D770_160C00_MoveToTheMusic[1] = D_8010D770_160C00_MoveToTheMusic[2] = D_8010D770_160C00_MoveToTheMusic[3] = 0;
    D_8010D728_160BB8_MoveToTheMusic[0] = D_8010D728_160BB8_MoveToTheMusic[1] = D_8010D728_160BB8_MoveToTheMusic[2] = D_8010D728_160BB8_MoveToTheMusic[3] = -1;
    D_8010D80E_160C9E_MoveToTheMusic[0] = D_8010D80E_160C9E_MoveToTheMusic[1] = D_8010D80E_160C9E_MoveToTheMusic[2] = D_8010D80E_160C9E_MoveToTheMusic[3] = -1;
    D_8010D7AC_160C3C_MoveToTheMusic[0] = D_8010D7AC_160C3C_MoveToTheMusic[1] = D_8010D7AC_160C3C_MoveToTheMusic[2] = D_8010D7AC_160C3C_MoveToTheMusic[3] = 0;
    for (i = 0; i < 6; i++) {
        D_8010D806_160C96_MoveToTheMusic[i] = D_8010CC00_160090_MoveToTheMusic[0][i];
    }
    {
        u8 order[3];
        u8 orders[6][3] = { { 1, 2, 4 }, { 1, 4, 2 }, { 2, 1, 4 }, { 2, 4, 1 }, { 4, 1, 2 }, { 4, 2, 1 } };
        u8 picks[5][6] = { { 1, 2, 3, 1, 2, 3 }, { 1, 2, 3, 1, 3, 2 }, { 1, 2, 3, 2, 1, 3 }, { 1, 2, 3, 2, 3, 1 }, { 1, 2, 1, 3, 2, 3 } };
        s32 r;
        u8 idx;
        u8* q;

        q = (u8*)orders + (u8)(rand8() % 6) * 3;
        order[0] = q[0];
        order[1] = q[1];
        order[2] = q[2];
        r = rand8();
        idx = D_8010D7CE_160C5E_MoveToTheMusic != 0 ? r % 5 : r % 4;
        for (i = 0; i < 6; i++) {
            D_8010D722_160BB2_MoveToTheMusic[i] = order[picks[idx][i] - 1];
        }
    }
    if (D_8010D7CE_160C5E_MoveToTheMusic == 0) {
        D_8010D722_160BB2_MoveToTheMusic[4] = 7;
        D_8010D722_160BB2_MoveToTheMusic[5] = 0;
    } else {
        D_8010D722_160BB2_MoveToTheMusic[5] = 7;
    }
    D_8010D722_160BB2_MoveToTheMusic[3] = 0;
    func_8002838C_28F8C(0, func_80106EC8_15A358_MoveToTheMusic, 2);
    obj->func_ptr = func_80103424_1568B4_MoveToTheMusic;
}

__asm__(".section .rodata");
const u32 D_8010CE78_160308_MoveToTheMusic[6] = { 0x00000001, 0x01010000, 0x01000101, 0x00000101, 0x00010001, 0x00010001 };

__asm__(".section .rodata");
const u32 D_8010CE90_160320_MoveToTheMusic[3] = { 0x00140014, 0x000A0000, 0x00000000 };

__asm__(".section .rodata");
const u32 D_8010CE9C_16032C_MoveToTheMusic[3] = { 0x00140014, 0x000A0056, 0x0000004B };

__asm__(".section .rodata");
const u32 D_8010CEA8_160338_MoveToTheMusic[6] = { 0x00000002, 0x00000003, 0x00000007, 0x00000004, 0x00000005, 0x00000006 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_11_MoveToTheMusic/155C90", func_80103424_1568B4_MoveToTheMusic);

__asm__(".section .rodata"); /* TEMP */
void func_80104DBC_15824C_MoveToTheMusic(omObjData* obj) {
    s16 data[8];
    s16 esp[16];
    s32 charFile[9] = { 0x2A000B, 0x2A000C, 0x2A000D, 0x2A000E, 0x2A000F, 0x2A0010, 0x210010, 0x210010, 0x210010 };
    s32 digitFile[11] = { 0x210007, 0x210006, 0x210009, 0x21000A, 0x21000B, 0x21000E, 0x21000F, 0x21000D, 0x21000C,
                          0x210010, 0x210008 };
    s32 file;
    s16 i;

    D_8010D7D4_160C64_MoveToTheMusic = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x210003), 0, 0);
    espDispOff(D_8010D7D4_160C64_MoveToTheMusic);
    for (i = 1; i < 8; i++) {
        data[i] = func_8001A2F8_1AEF8(i != 0 ? (i < 5 ? charFile[D_8010D708_160B98_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[i - 1]]->character] : 0x210010) : 0x210004);
        D_8010D748_160BD8_MoveToTheMusic[i] = SprCreate(1, 0);
        SprAnimSet(D_8010D748_160BD8_MoveToTheMusic[i], 0, data[i], 0);
        SprAttrReset(D_8010D748_160BD8_MoveToTheMusic[i], 0, 0xFFFF);
        SprAttrSet(D_8010D748_160BD8_MoveToTheMusic[i], 0, (i == 0 ? 0x04001008 : 0) | 0x1008);
        SprPrioSet(D_8010D748_160BD8_MoveToTheMusic[i], 0, 0x1000 - i);
    }
    SprPosSet(D_8010D748_160BD8_MoveToTheMusic[1], 0, 0x21, 0xC8);
    SprPosSet(D_8010D748_160BD8_MoveToTheMusic[2], 0, 0x21, 0xB8);
    SprPosSet(D_8010D748_160BD8_MoveToTheMusic[3], 0, 0x21, 0xC8);
    SprPosSet(D_8010D748_160BD8_MoveToTheMusic[4], 0, 0x21, 0xD8);
    SprPosSet(D_8010D748_160BD8_MoveToTheMusic[5], 0, 0x21, 0xB8);
    SprPosSet(D_8010D748_160BD8_MoveToTheMusic[6], 0, 0x21, 0xC8);
    SprPosSet(D_8010D748_160BD8_MoveToTheMusic[7], 0, 0x21, 0xD8);
    func_80082488_83088(D_8010D748_160BD8_MoveToTheMusic[2], 0, 0);
    func_80082488_83088(D_8010D748_160BD8_MoveToTheMusic[3], 0, 0);
    func_80082488_83088(D_8010D748_160BD8_MoveToTheMusic[4], 0, 0);
    func_80082488_83088(D_8010D748_160BD8_MoveToTheMusic[5], 0, 0);
    func_80082488_83088(D_8010D748_160BD8_MoveToTheMusic[6], 0, 0);
    func_80082488_83088(D_8010D748_160BD8_MoveToTheMusic[7], 0, 0);
    for (i = 0; i < 11; i++) {
        esp[i] = func_8001A2F8_1AEF8(digitFile[i]);
        D_8010D7F0_160C80_MoveToTheMusic[i] = func_8001AAAC_1B6AC(esp[i], 0, 0);
        espDispOff(D_8010D7F0_160C80_MoveToTheMusic[i]);
    }
    data[0] = func_8001A2F8_1AEF8(0x210004);
    D_8010D748_160BD8_MoveToTheMusic[0] = func_8001AAAC_1B6AC(data[0], 0, 0);
    espDispOff(D_8010D748_160BD8_MoveToTheMusic[0]);
    for (i = 0; i < 3; i++) {
        f32 x[4] = { 0.0f, -200.0f, 0.0f, 200.0f };
        f32 y[4] = { 52.0f, 6.0f, 6.0f, 6.0f };
        f32 z[4] = { -315.0f, 265.0f, 305.0f, 265.0f };

        obj->model[9 + i] = func_80102A68_155EF8_MoveToTheMusic(0x210011);
        func_800298A4_2A4A4(obj->model[9 + i], 4, 4);
        HmfModelObjAttrSet(obj->model[9 + i], 0x70000000, 0x70000000);
        func_80029714_2A314(obj->model[9 + i], x[i + 1] + 50.0, y[i + 1] + 150.0, z[i + 1]);
        func_800297E8_2A3E8(obj->model[9 + i], 3.5f, 3.5f, 3.5f);
    }
    obj->model[0] = LoadFormFile(0x210000, 0x204D9);
    HmfModelObjAttrSet(obj->model[0], 0x600, 0x400);
    func_8002D1EC_2DDEC(obj->model[0], 1);
    func_8002D274_2DE74(obj->model[0], 0xFF, 0xFF, 0xFF);
    func_8002D2B4_2DEB4(obj->model[0], 10.0f, 90.0f, 30.0f);
    for (i = 0; i < 4; i++) {
        f32 x[4] = { 0.0f, -200.0f, 0.0f, 200.0f };
        f32 y[4] = { 46.0f, 0.0f, 0.0f, 0.0f };
        f32 z[4] = { -320.0f, 260.0f, 300.0f, 260.0f };

        if (i == 0) {
            obj->model[5] = LoadFormFile(0x440006, 0x49D);
        } else {
            obj->model[5 + i] = func_80027D3C_2893C(obj->model[5]);
        }
        HmfModelObjAttrSet(obj->model[5 + i], 0x600, 0x400);
        func_80029714_2A314(obj->model[5 + i], x[i], y[i] - (i == 0 ? 2745.0 : 1095.0),
                            z[i] - (i == 0 ? 200.0 : i == 2 ? 170.0 : 110.0));
        func_800297E8_2A3E8(obj->model[5 + i], 1.0f, i == 0 ? 5.6875f : 2.5625f, 1.0f);
    }
    obj->func_ptr = func_80105568_1589F8_MoveToTheMusic;
}

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

void func_80105664_158AF4_MoveToTheMusic(omObjData* obj, s8 player) {
    s32 dir;
    s32 file;
    s32 attr = 0x204;

    dir = D_800CD438_CE038[gPlayers[player].character].dir;
    obj->model[0] = LoadFormFile(dir | 0xD3, 0x6A9);
    HmfModelObjAttrSet(obj->model[0], 0x600, 0x400);
    func_80029E80_2AA80(obj->model[0], 2, 2);
    D_8010D7D8_160C68_MoveToTheMusic[player] = 0;
    func_8002D1EC_2DDEC(obj->model[0], 1);
    func_8002D274_2DE74(obj->model[0], 0xFF, 0xD4, 0x46);
    func_8002D2B4_2DEB4(obj->model[0], 0.0f, -90.0f, 90.0f);
    {
        f32 x[4] = { 0.0f, -200.0f, 0.0f, 200.0f };
        f32 y[4] = { 52.0f, 6.0f, 6.0f, 6.0f };
        f32 z[4] = { -315.0f, 265.0f, 305.0f, 265.0f };
        s32 cell = D_8010D708_160B98_MoveToTheMusic[player]->cell;

        omSetTra(obj, x[cell], y[cell], z[cell]);
    }
    if (D_8010D708_160B98_MoveToTheMusic[player]->cell == 0) {
        obj->model[1] = LoadFormFile(dir | 0xD1, (D_8010D708_160B98_MoveToTheMusic[player]->cell == 0 ? 0x204 : 0) | 0x4A9);
        HmfModelObjAttrSet(obj->model[1], 0x600, 0x400);
        func_80029E80_2AA80(obj->model[1], 2, 2);
        func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
        func_8002D1EC_2DDEC(obj->model[1], 1);
        func_8002D274_2DE74(obj->model[1], 0xFF, 0xF4, 0xE9);
        func_8002D2B4_2DEB4(obj->model[1], 0.0f, -90.0f, 90.0f);
    }
    obj->model[2] = LoadFormFile(dir, 0x49D);
    func_80029E80_2AA80(obj->model[2], 2, 2);
    obj->model[3] = LoadFormFile(dir | 0x74, 0x49D);
    func_80029E80_2AA80(obj->model[3], 2, 2);
    if (D_8010D708_160B98_MoveToTheMusic[player]->cell != 0) {
        func_80018CCC_198CC(obj, 4, dir | 0x75);
    }
    func_80018CCC_198CC(obj, 5, dir | 0x7A);
    func_80018CCC_198CC(obj, 6, dir | 0x7B);
    func_80018CCC_198CC(obj, 7, dir | 0x7C);
    func_80018CCC_198CC(obj, 8, dir | 0x76);
    func_80018CCC_198CC(obj, 9, dir | 0x77);
    func_80018CCC_198CC(obj, 0xA, dir | 0x79);
    func_80018CCC_198CC(obj, 0xB, dir | 0x78);
    if (D_8010D708_160B98_MoveToTheMusic[player]->cell != 0) {
        file = dir | 0x59;
        if ((s8)((s8)(u8)D_8010D708_160B98_MoveToTheMusic[player]->character % 3) == 1) {
            file = dir | 0x58;
        }
        func_80018CCC_198CC(obj, 0xD, file);
    }
}

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
