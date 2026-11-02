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
        MMOrder orders;
        MMPick picks;
        s32 r;
        u8 idx;
        u8* q;

        orders = D_8010CE44_1602D4_MoveToTheMusic;
        picks = D_8010CE58_1602E8_MoveToTheMusic;
        idx = rand8() % 6;
        q = orders.v[idx];
        order[0] = q[0];
        order[1] = q[1];
        order[2] = q[2];
        r = rand8();
        idx = D_8010D7CE_160C5E_MoveToTheMusic != 0 ? r % 5 : r % 4;
        for (i = 0; i < 6; i++) {
            D_8010D722_160BB2_MoveToTheMusic[i] = order[picks.v[idx][i] - 1];
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

const MMOrder D_8010CE44_1602D4_MoveToTheMusic = { { { 1, 2, 4 }, { 1, 4, 2 }, { 2, 1, 4 }, { 2, 4, 1 }, { 4, 1, 2 }, { 4, 2, 1 } } };
const MMPick D_8010CE58_1602E8_MoveToTheMusic = { { { 1, 2, 3, 1, 2, 3 }, { 1, 2, 3, 1, 3, 2 }, { 1, 2, 3, 2, 1, 3 }, { 1, 2, 3, 2, 3, 1 }, { 1, 2, 1, 3, 2, 3 } } };


void func_80103424_1568B4_MoveToTheMusic(void) {
    SeqChlInfo info;
    u8 i;
    s16 j;
    s16 l;
    s16 m;
    u8 o;
    s32 n;
    s16 v;
    f32 t;

    D_8010D75C_160BEC_MoveToTheMusic = D_8010D798_160C28_MoveToTheMusic;
    D_8010D760_160BF0_MoveToTheMusic = D_8010D7E8_160C78_MoveToTheMusic;
    D_8010D798_160C28_MoveToTheMusic++;
    D_8010D7E8_160C78_MoveToTheMusic++;
    n = D_8010D796_160C26_MoveToTheMusic;
    if (n < 0x80) {
        v = n + 1;
    } else {
        v = n;
    }
    D_8010D796_160C26_MoveToTheMusic = v;
    if (v < 14 && D_8010D7D0_160C60_MoveToTheMusic > 0 && (v - 1) * D_8010D7D0_160C60_MoveToTheMusic / 15 != v * D_8010D7D0_160C60_MoveToTheMusic / 15) {
        D_8010D798_160C28_MoveToTheMusic++;
        D_8010D7E8_160C78_MoveToTheMusic++;
    }
    func_80011738_12338(D_800FA188_FAD88, D_8010D7CE_160C5E_MoveToTheMusic + 0xE, &info);
    if (D_8010D720_160BB0_MoveToTheMusic != info.vol && info.vol < 0x7F) {
        if (((D_8010D798_160C28_MoveToTheMusic + 5) % 30 < 15 && (D_8010D798_160C28_MoveToTheMusic - 2) % 15 != 0) || (u32)((D_8010D798_160C28_MoveToTheMusic - 2) % 15 + 1) >= 3U) {
            D_8010D7D0_160C60_MoveToTheMusic = 7 - (D_8010D798_160C28_MoveToTheMusic + 3) % 15;
            D_8010D796_160C26_MoveToTheMusic = 0;
        }
        D_8010D720_160BB0_MoveToTheMusic = info.vol;
    }
    if ((u32)D_8010D798_160C28_MoveToTheMusic >= D_8010CBD0_160060_MoveToTheMusic[D_8010D7CC_160C5C_MoveToTheMusic]) {
        D_8010D798_160C28_MoveToTheMusic -= D_8010CBD0_160060_MoveToTheMusic[D_8010D7CC_160C5C_MoveToTheMusic];
        if (D_8010D7CC_160C5C_MoveToTheMusic == 3 && ((D_8010D741_160BD1_MoveToTheMusic[0] != 0 && D_8010D741_160BD1_MoveToTheMusic[1] != 0 && D_8010D741_160BD1_MoveToTheMusic[2] != 0) || (_CheckFlag(0xC) != 0 && D_8010D741_160BD1_MoveToTheMusic[0] != 0 && D_8010D708_160B98_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[1]]->cpu == -1))) {
            D_8010D7CC_160C5C_MoveToTheMusic = 8;
            func_800794A8_7A0A8(0x1E);
        } else if (_CheckFlag(0xC) != 0 && D_8010D7CC_160C5C_MoveToTheMusic == 8) {
            D_8010D7CC_160C5C_MoveToTheMusic = 0xB;
            if (D_8010D741_160BD1_MoveToTheMusic[0] != 0) {
                gPlayers[D_8010D7C8_160C58_MoveToTheMusic[0]].coins_mg_bonus += 10;
            } else {
                gPlayers[D_8010D7C8_160C58_MoveToTheMusic[1]].coins_mg_bonus += 10;
                gPlayers[D_8010D7C8_160C58_MoveToTheMusic[2]].coins_mg_bonus += 10;
                gPlayers[D_8010D7C8_160C58_MoveToTheMusic[3]].coins_mg_bonus += 10;
            }
        } else {
            D_8010D7CC_160C5C_MoveToTheMusic = (u16)D_8010D7CC_160C5C_MoveToTheMusic + 1;
        }
    }
    switch (D_8010D7CC_160C5C_MoveToTheMusic) {
    case 0:
        if (D_8010D798_160C28_MoveToTheMusic == 3) {
            PlaySound(0x4A3);
        }
        if (D_8010D798_160C28_MoveToTheMusic >= 25 && D_8010D75C_160BEC_MoveToTheMusic < 25) {
            func_800691FC_69DFC(0);
        }
        if (D_8010D798_160C28_MoveToTheMusic >= 25 && D_8010D75C_160BEC_MoveToTheMusic < 25 && D_8010D80C_160C9C_MoveToTheMusic == 0 && D_801011FC_101DFC == 0) {
            PlayMusic(D_8010D7CE_160C5E_MoveToTheMusic != 0 ? 0x2F : 0x2E);
        }
        D_80102708_103308 = 1;
        break;
    case 4:
        if (D_8010D798_160C28_MoveToTheMusic < D_8010D75C_160BEC_MoveToTheMusic) {
            u8 order[3];
            MMOrder orders;
            MMPick picks;
            u8 k;
            u8 w;

            for (i = 0; i < 6; i++) {
                D_8010D806_160C96_MoveToTheMusic[i] = D_8010CC06_160096_MoveToTheMusic[i];
            }
            switch ((D_8010D741_160BD1_MoveToTheMusic[0] != 0) + (D_8010D741_160BD1_MoveToTheMusic[1] != 0) + (D_8010D741_160BD1_MoveToTheMusic[2] != 0)) {
            case 0: {
                u8* q;

                orders = D_8010CE44_1602D4_MoveToTheMusic;
                picks = D_8010CE58_1602E8_MoveToTheMusic;
                w = rand8() % 6;
                q = orders.v[w];
                order[0] = q[0];
                order[1] = q[1];
                order[2] = q[2];
                w = rand8() % 5;
                for (i = 0; i < 6; i++) {
                    D_8010D722_160BB2_MoveToTheMusic[i] = order[picks.v[w][i] - 1];
                }
                D_8010D722_160BB2_MoveToTheMusic[5] = 7;
                if (D_8010D7CE_160C5E_MoveToTheMusic == 1) {
                    D_8010D722_160BB2_MoveToTheMusic[2] = 7;
                }
                break;
            }
            case 1: {
                u8 tbl[4][6] = { { 0, 0, 0, 1, 1, 1 }, { 0, 0, 1, 0, 1, 1 }, { 0, 0, 1, 1, 0, 1 }, { 0, 1, 0, 1, 0, 1 } };
                u8 row;

                row = (u8)(rand8() % 10) / 3;
                orders.v[0][0] = D_8010D741_160BD1_MoveToTheMusic[0] == 0 ? 1 : 2;
                orders.v[0][1] = D_8010D741_160BD1_MoveToTheMusic[2] == 0 ? 4 : 2;
                for (i = 0, k = rand8() % 6; i < 6; i++) {
                    k %= 6;
                    D_8010D722_160BB2_MoveToTheMusic[i] = orders.v[0][tbl[row][k]];
                    k++;
                }
                D_8010D722_160BB2_MoveToTheMusic[5] = orders.v[0][0] + orders.v[0][1];
                if (D_8010D7CE_160C5E_MoveToTheMusic == 1) {
                    D_8010D722_160BB2_MoveToTheMusic[2] = orders.v[0][0] + orders.v[0][1];
                }
                break;
            }
            case 2: {
                if (D_8010D741_160BD1_MoveToTheMusic[0] != 0) {
                    k = 4;
                    if (D_8010D741_160BD1_MoveToTheMusic[1] == 0) {
                        k = 2;
                    }
                } else {
                    k = 1;
                }
                for (i = 0; i < 6; i++) {
                    D_8010D722_160BB2_MoveToTheMusic[i] = k;
                }
                break;
            }
            }
        }
        break;
    case 8:
        if (D_8010D798_160C28_MoveToTheMusic < D_8010D75C_160BEC_MoveToTheMusic) {
            for (j = 0; j < 4; j++) {
                func_80029BF0_2A7F0(D_8010D780_160C10_MoveToTheMusic[j]->model[D_8010D7D8_160C68_MoveToTheMusic[j]], func_80029E14_2AA14(D_8010D780_160C10_MoveToTheMusic[j]->model[2]), 0, 0x1E, 2);
            }
        }
        if (D_8010D798_160C28_MoveToTheMusic >= 6 && D_8010D75C_160BEC_MoveToTheMusic < 6) {
            func_800691FC_69DFC(3);
        }
        break;
    case 9:
        if (D_8010D798_160C28_MoveToTheMusic < D_8010D75C_160BEC_MoveToTheMusic) {
            func_800283DC_28FDC(D_8010D780_160C10_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[0]]->model[3]);
            func_800283DC_28FDC(D_8010D780_160C10_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[1]]->model[3]);
            func_800283DC_28FDC(D_8010D780_160C10_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[2]]->model[3]);
            func_800283DC_28FDC(D_8010D780_160C10_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[3]]->model[3]);
            if ((D_8010D741_160BD1_MoveToTheMusic[0] != 0) + (D_8010D741_160BD1_MoveToTheMusic[1] != 0) + (D_8010D741_160BD1_MoveToTheMusic[2] != 0) == 3) {
                D_8010D758_160BE8_MoveToTheMusic = 1;
                gPlayers[D_8010D7C8_160C58_MoveToTheMusic[0]].coins_mg_bonus += 10;
                func_800691FC_69DFC(6, D_8010D708_160B98_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[0]]->character);
                if (D_8010D80C_160C9C_MoveToTheMusic == 0 && D_801011FC_101DFC == 0) {
                    PlayMusic(0x51);
                }
                func_800298A4_2A4A4(D_8010D764_160BF4_MoveToTheMusic->model[5], 4, 0);
                func_800297E8_2A3E8(D_8010D764_160BF4_MoveToTheMusic->model[5], 0.0f, 5.6875f, 0.0f);
                D_8010D7B8_160C48_MoveToTheMusic[0] = func_80025384_25F84(D_8010D780_160C10_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[0]]->model[1], 1, D_8010D708_160B98_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[0]]->character,
                                               func_80025718_26318(D_8010D708_160B98_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[0]]->character, 1, 1) | D_800CD438_CE038[D_8010D708_160B98_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[0]]->character].dir);
                func_80025554_26154(D_8010D780_160C10_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[0]]->model[1], 1, D_8010D708_160B98_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[0]]->character, D_8010D7B8_160C48_MoveToTheMusic[0]);
            } else {
                D_8010D7CC_160C5C_MoveToTheMusic = 10;
                D_8010D758_160BE8_MoveToTheMusic = 2;
                gPlayers[D_8010D7C8_160C58_MoveToTheMusic[1]].coins_mg_bonus += 10;
                gPlayers[D_8010D7C8_160C58_MoveToTheMusic[2]].coins_mg_bonus += 10;
                gPlayers[D_8010D7C8_160C58_MoveToTheMusic[3]].coins_mg_bonus += 10;
                func_800691FC_69DFC(0x15, D_8010D708_160B98_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[3]]->character, D_8010D708_160B98_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[1]]->character, D_8010D708_160B98_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[2]]->character);
                func_800298A4_2A4A4(D_8010D780_160C10_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[0]]->model[0], 4, 0);
                func_800298A4_2A4A4(D_8010D780_160C10_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[0]]->model[1], 4, 4);
                D_8010D7D8_160C68_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[0]] = 0;
                func_80029B80_2A780(D_8010D780_160C10_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[0]]->model[0], D_8010D780_160C10_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[0]]->model[2]);
                func_80029E80_2AA80(D_8010D780_160C10_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[0]]->model[0], 3, 2);
                func_80029AFC_2A6FC(D_8010D780_160C10_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[0]]->model[1]);
                for (l = 1; l < 4; l++) {
                    func_800298A4_2A4A4(D_8010D764_160BF4_MoveToTheMusic->model[5 + l], 4, 0);
                    func_800297E8_2A3E8(D_8010D764_160BF4_MoveToTheMusic->model[5 + l], 0.0f, 5.6875f, 0.0f);
                }
            }
        }
        if (D_8010D7CC_160C5C_MoveToTheMusic == 9) {
            s16 a[6] = { 0x14, 0x14, 0xA, 0, 0, 0 };
            s16 b[6] = { 0x14, 0x14, 0xA, 0x56, 0, 0x4B };
        }
        if (D_8010D798_160C28_MoveToTheMusic >= 2 && D_8010D75C_160BEC_MoveToTheMusic < 2) {
            s32 files[6] = { 2, 3, 7, 4, 5, 6 };

            func_800298A4_2A4A4(D_8010D780_160C10_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[0]]->model[1], 4, 0);
            func_800298A4_2A4A4(D_8010D780_160C10_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[0]]->model[0], 4, 4);
            D_8010D7D8_160C68_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[0]] = 1;
            func_80018CCC_198CC(D_8010D780_160C10_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[0]], 0xC, D_800CD438_CE038[D_8010D708_160B98_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[0]]->character].dir | 0x4E);
            func_80029B80_2A780(D_8010D780_160C10_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[0]]->model[D_8010D7D8_160C68_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[0]]], D_8010D780_160C10_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[0]]->motion[0xC]);
            func_80029E80_2AA80(D_8010D780_160C10_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[0]]->model[D_8010D7D8_160C68_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[0]]], 2, 0);
            func_800732B0_73EB0((files[D_8010D708_160B98_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[0]]->character] << 0x10) | 0x4E);
        }
        break;
    case 10:
        if (D_8010D798_160C28_MoveToTheMusic > 0 && (D_8010D75C_160BEC_MoveToTheMusic <= 0 || D_8010D798_160C28_MoveToTheMusic < D_8010D75C_160BEC_MoveToTheMusic)) {
            for (j = 1; j < 4; j++) {
                D_8010D780_160C10_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[j]]->model[1] = LoadFormFile(D_800CD438_CE038[D_8010D708_160B98_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[j]]->character].dir | 0xD2, 0x6AD);
                HmfModelObjAttrSet(D_8010D780_160C10_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[j]]->model[1], 0x600, 0x400);
                func_80029E80_2AA80(D_8010D780_160C10_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[j]]->model[1], 2, 2);
                func_80029714_2A314(D_8010D780_160C10_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[j]]->model[1], D_8010D780_160C10_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[j]]->trans.x, D_8010D780_160C10_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[j]]->trans.y, D_8010D780_160C10_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[j]]->trans.z);
                func_8002D1EC_2DDEC(D_8010D780_160C10_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[j]]->model[1], 1);
                func_8002D274_2DE74(D_8010D780_160C10_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[j]]->model[1], 0xFF, 0xF4, 0xE9);
                func_8002D2B4_2DEB4(D_8010D780_160C10_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[j]]->model[1], 0.0f, -90.0f, 90.0f);
                D_8010D7B8_160C48_MoveToTheMusic[j] = func_80025384_25F84(D_8010D780_160C10_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[j]]->model[1], 1, D_8010D708_160B98_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[j]]->character,
                                               func_80025718_26318(D_8010D708_160B98_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[j]]->character, 1, 1) | D_800CD438_CE038[D_8010D708_160B98_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[j]]->character].dir);
                func_80025554_26154(D_8010D780_160C10_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[j]]->model[1], 1, D_8010D708_160B98_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[j]]->character, D_8010D7B8_160C48_MoveToTheMusic[j]);
            }
            if (D_8010D80C_160C9C_MoveToTheMusic == 0 && D_801011FC_101DFC == 0) {
                PlayMusic(0x52);
            }
        }
        if (D_8010D798_160C28_MoveToTheMusic >= 15 && D_8010D75C_160BEC_MoveToTheMusic < 15) {
            for (j = 1; j < 4; j++) {
                s32 files[6] = { 2, 3, 7, 4, 5, 6 };

                func_800298A4_2A4A4(D_8010D780_160C10_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[j]]->model[1], 4, 0);
                func_800298A4_2A4A4(D_8010D780_160C10_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[j]]->model[0], 4, 4);
                D_8010D7D8_160C68_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[j]] = 1;
                func_80018CCC_198CC(D_8010D780_160C10_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[j]], 0xC, D_800CD438_CE038[D_8010D708_160B98_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[j]]->character].dir | 0x4F);
                func_80029B80_2A780(D_8010D780_160C10_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[j]]->model[D_8010D7D8_160C68_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[j]]], D_8010D780_160C10_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[j]]->motion[0xC]);
                func_80029E80_2AA80(D_8010D780_160C10_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[j]]->model[D_8010D7D8_160C68_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[j]]], 2, 0);
                func_800732B0_73EB0((files[D_8010D708_160B98_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[j]]->character] << 0x10) | 0x4F);
            }
        }
        if (D_8010D798_160C28_MoveToTheMusic < D_8010D75C_160BEC_MoveToTheMusic) {
            D_8010D7CC_160C5C_MoveToTheMusic = 0xB;
        } else {
            break;
        }
    case 11:
        if (D_8010D798_160C28_MoveToTheMusic < D_8010D75C_160BEC_MoveToTheMusic) {
            InitFadeOut(0, 0x14);
        } else if (D_8010D798_160C28_MoveToTheMusic >= 0x20) {
            D_8010D80C_160C9C_MoveToTheMusic = 1;
        }
        break;
    }
    if ((D_8010D7CC_160C5C_MoveToTheMusic == 9 || D_8010D7CC_160C5C_MoveToTheMusic == 10) && D_8010D798_160C28_MoveToTheMusic <= 60) {
        t = 1.0 - (f32)D_8010D798_160C28_MoveToTheMusic / 60.0f;
        t = 1.0 - t * t;
        for (m = 0; m < 4; m++) {
            func_800297E8_2A3E8(D_8010D764_160BF4_MoveToTheMusic->model[5 + m], t, m == 0 ? 5.6875f : 2.5625f, 0.0f);
        }
    }
    if (_CheckFlag(0x15) != 0 && D_801011FC_101DFC == 0 && D_8010D740_160BD0_MoveToTheMusic == 0) {
        if ((D_8010D7CC_160C5C_MoveToTheMusic > 0 || D_8010D798_160C28_MoveToTheMusic >= 0x5B) && D_8010D7CC_160C5C_MoveToTheMusic < 8) {
            for (o = 0; o < 4; o++) {
                if (D_8010D708_160B98_MoveToTheMusic[o]->cpu == -1 && (ContBtnTrg[D_8010D708_160B98_MoveToTheMusic[o]->port] & 0x10)) {
                    D_8010D740_160BD0_MoveToTheMusic = 1;
                }
            }
        }
    }
    if (D_8010D80C_160C9C_MoveToTheMusic != 0 || D_801011FC_101DFC != 0 || D_8010D740_160BD0_MoveToTheMusic != 0) {
        if (D_801011FC_101DFC != 0 && D_8010D740_160BD0_MoveToTheMusic == 0) {
            D_8010D740_160BD0_MoveToTheMusic = 1;
        }
        if (D_8010D740_160BD0_MoveToTheMusic != 0) {
            if (D_8010D740_160BD0_MoveToTheMusic == 1) {
                InitFadeOut(0, 0x14);
                func_800794A8_7A0A8(0x14);
                func_80079614_7A214(0x14);
            }
            D_8010D740_160BD0_MoveToTheMusic++;
            if (D_8010D740_160BD0_MoveToTheMusic < 25) {
                return;
            }
        }
        func_800794A8_7A0A8(0x28);
        omOvlReturnEx(1);
    }
}

__asm__(".section .rodata");
const MMFiles9 D_8010CEF8_160388_MoveToTheMusic = { { 0x2A000B, 0x2A000C, 0x2A000D, 0x2A000E, 0x2A000F, 0x2A0010, 0x210010, 0x210010, 0x210010 } };
const MMFiles11 D_8010CF1C_1603AC_MoveToTheMusic = { { 0x210007, 0x210006, 0x210009, 0x21000A, 0x21000B, 0x21000E, 0x21000F, 0x21000D, 0x21000C, 0x210010, 0x210008 } };
const MMVec4 D_8010CF48_1603D8_MoveToTheMusic = { { 0.0f, -200.0f, 0.0f, 200.0f } };
const MMVec4 D_8010CF58_1603E8_MoveToTheMusic = { { 52.0f, 6.0f, 6.0f, 6.0f } };
const MMVec4 D_8010CF68_1603F8_MoveToTheMusic = { { -315.0f, 265.0f, 305.0f, 265.0f } };
const MMVec4 D_8010CF78_160408_MoveToTheMusic = { { 46.0f, 0.0f, 0.0f, 0.0f } };
const MMVec4 D_8010CF88_160418_MoveToTheMusic = { { -320.0f, 260.0f, 300.0f, 260.0f } };

void func_80104DBC_15824C_MoveToTheMusic(omObjData* obj) {
    s16 data[8];
    s16 esp[16];
    MMFiles9 charFile = D_8010CEF8_160388_MoveToTheMusic;
    MMFiles11 digitFile = D_8010CF1C_1603AC_MoveToTheMusic;
    s32 file;
    s16 i;

    D_8010D7D4_160C64_MoveToTheMusic = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x210003), 0, 0);
    espDispOff(D_8010D7D4_160C64_MoveToTheMusic);
    for (i = 1; i < 8; i++) {
        data[i] = func_8001A2F8_1AEF8(i != 0 ? (i < 5 ? charFile.v[D_8010D708_160B98_MoveToTheMusic[D_8010D7C8_160C58_MoveToTheMusic[i - 1]]->character] : 0x210010) : 0x210004);
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
        esp[i] = func_8001A2F8_1AEF8(digitFile.v[i]);
        D_8010D7F0_160C80_MoveToTheMusic[i] = func_8001AAAC_1B6AC(esp[i], 0, 0);
        espDispOff(D_8010D7F0_160C80_MoveToTheMusic[i]);
    }
    data[0] = func_8001A2F8_1AEF8(0x210004);
    D_8010D748_160BD8_MoveToTheMusic[0] = func_8001AAAC_1B6AC(data[0], 0, 0);
    espDispOff(D_8010D748_160BD8_MoveToTheMusic[0]);
    for (i = 0; i < 3; i++) {
        MMVec4 x = D_8010CF48_1603D8_MoveToTheMusic;
        MMVec4 y = D_8010CF58_1603E8_MoveToTheMusic;
        MMVec4 z = D_8010CF68_1603F8_MoveToTheMusic;

        obj->model[9 + i] = func_80102A68_155EF8_MoveToTheMusic(0x210011);
        func_800298A4_2A4A4(obj->model[9 + i], 4, 4);
        HmfModelObjAttrSet(obj->model[9 + i], 0x70000000, 0x70000000);
        func_80029714_2A314(obj->model[9 + i], x.v[i + 1] + 50.0, y.v[i + 1] + 150.0, z.v[i + 1]);
        func_800297E8_2A3E8(obj->model[9 + i], 3.5f, 3.5f, 3.5f);
    }
    obj->model[0] = LoadFormFile(0x210000, 0x204D9);
    HmfModelObjAttrSet(obj->model[0], 0x600, 0x400);
    func_8002D1EC_2DDEC(obj->model[0], 1);
    func_8002D274_2DE74(obj->model[0], 0xFF, 0xFF, 0xFF);
    func_8002D2B4_2DEB4(obj->model[0], 10.0f, 90.0f, 30.0f);
    for (i = 0; i < 4; i++) {
        MMVec4 x = D_8010CF48_1603D8_MoveToTheMusic;
        MMVec4 y = D_8010CF78_160408_MoveToTheMusic;
        MMVec4 z = D_8010CF88_160418_MoveToTheMusic;

        if (i == 0) {
            obj->model[5] = LoadFormFile(0x440006, 0x49D);
        } else {
            obj->model[5 + i] = func_80027D3C_2893C(obj->model[5]);
        }
        HmfModelObjAttrSet(obj->model[5 + i], 0x600, 0x400);
        func_80029714_2A314(obj->model[5 + i], x.v[i], y.v[i] - (i == 0 ? 2745.0 : 1095.0),
                            z.v[i] - (i == 0 ? 200.0 : i == 2 ? 170.0 : 110.0));
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

#ifdef NON_MATCHING
/* register allocation (masked 6): retail has `li $t0, 0x204; ori $a1, $t0, 0x4A9` for the constant 0x6AD, the
   spill register reload uses for a pseudo with a constant equivalent; no plain C found that leaves it unfolded */
void func_80105664_158AF4_MoveToTheMusic(omObjData* obj, s8 player) {
    s32 dir;
    s32 file;

    dir = D_800CD438_CE038[gPlayers[player].character].dir;
    obj->model[0] = LoadFormFile(dir | 0xD3, 0x6A9);
    HmfModelObjAttrSet(obj->model[0], 0x600, 0x400);
    func_80029E80_2AA80(obj->model[0], 2, 2);
    D_8010D7D8_160C68_MoveToTheMusic[player] = 0;
    func_8002D1EC_2DDEC(obj->model[0], 1);
    func_8002D274_2DE74(obj->model[0], 0xFF, 0xD4, 0x46);
    func_8002D2B4_2DEB4(obj->model[0], 0.0f, -90.0f, 90.0f);
    {
        MMVec4 x = D_8010CF48_1603D8_MoveToTheMusic;
        MMVec4 y = D_8010CF58_1603E8_MoveToTheMusic;
        MMVec4 z = D_8010CF68_1603F8_MoveToTheMusic;
        s32 cell = D_8010D708_160B98_MoveToTheMusic[player]->cell;

        omSetTra(obj, x.v[cell], y.v[cell], z.v[cell]);
    }
    if (D_8010D708_160B98_MoveToTheMusic[player]->cell == 0) {
        obj->model[1] = LoadFormFile(dir | 0xD1, 0x6AD);
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
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_11_MoveToTheMusic/155C90", func_80105664_158AF4_MoveToTheMusic);
#endif

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

#ifdef NON_MATCHING
/* register/schedule and frame (masked ~140; logic checked against the asm): retail's frame is 0x20 smaller and it
   has branch-likely forms of `if (x > 0) x--` that this form turns into flag arithmetic. `unused` is retail: the
   same pan table is copied there and never read */
void func_80105A90_158F20_MoveToTheMusic(omObjData* obj, s8 player) {
    MMPlayer* pl;
    s16* p;
    s16* m;
    s8* o;
    s32 mdl;
    s32 v;
    s32 d;
    s32 frame;
    s32 prev;
    s32 beat;
    s32 btn;
    s32 dirx;
    s32 diry;
    s16 flickx;
    s16 flicky;
    s32 b;
    s16 s;
    s32 t;
    f32 f;

    pl = D_8010D708_160B98_MoveToTheMusic[player];
    frame = D_8010D798_160C28_MoveToTheMusic;
    prev = D_8010D75C_160BEC_MoveToTheMusic;
    btn = 0;
    if (D_8010D7CC_160C5C_MoveToTheMusic == 0 || D_8010D7CC_160C5C_MoveToTheMusic == 2 || D_8010D7CC_160C5C_MoveToTheMusic == 4 || D_8010D7CC_160C5C_MoveToTheMusic == 6) {
        frame = D_8010D798_160C28_MoveToTheMusic - D_8010CBD0_160060_MoveToTheMusic[D_8010D7CC_160C5C_MoveToTheMusic];
    }
    beat = (frame + 15) / 30;
    if (D_8010D7CC_160C5C_MoveToTheMusic != 8 && D_8010D7CC_160C5C_MoveToTheMusic != 9 && D_8010D7CC_160C5C_MoveToTheMusic != 10 && D_8010D7CC_160C5C_MoveToTheMusic != 11) {
        if ((u16)D_8010D7CC_160C5C_MoveToTheMusic == 0) {
            if (D_8010D798_160C28_MoveToTheMusic >= 30) {
                if (D_8010D75C_160BEC_MoveToTheMusic < 30) {
                    func_80029BF0_2A7F0(obj->model[D_8010D7D8_160C68_MoveToTheMusic[player]], func_80029E14_2AA14(obj->model[3]), 15, 15, 2);
                    m = obj->model;
                    if (D_8010D7D8_160C68_MoveToTheMusic[player] == 0) {
                        m++;
                    }
                    func_80029B80_2A780(*m, obj->model[3]);
                    func_80029E80_2AA80(obj->model[D_8010D7D8_160C68_MoveToTheMusic[player]], 2, 2);
                }
                if (D_8010D798_160C28_MoveToTheMusic >= 30) {
                    goto update;
                }
            }
        } else {
        update:
            if (D_8010D768_160BF8_MoveToTheMusic[player] > 0 && D_8010D768_160BF8_MoveToTheMusic[player] - (s16)((u16)D_8010D7E8_160C78_MoveToTheMusic - (u16)D_8010D760_160BF0_MoveToTheMusic) * 2 <= 0) {
                D_8010D768_160BF8_MoveToTheMusic[player] = 0;
                if (D_8010D708_160B98_MoveToTheMusic[player]->cell > 0 && D_8010D741_160BD1_MoveToTheMusic[D_8010D708_160B98_MoveToTheMusic[player]->cell - 1] != 0) {
                    func_80029B80_2A780(obj->model[D_8010D7D8_160C68_MoveToTheMusic[player]], obj->motion[0xD]);
                    func_80029E80_2AA80(obj->model[D_8010D7D8_160C68_MoveToTheMusic[player]], 3, 0);
                } else {
                    func_80029B80_2A780(obj->model[D_8010D7D8_160C68_MoveToTheMusic[player]], obj->model[3]);
                    func_80029E80_2AA80(obj->model[D_8010D7D8_160C68_MoveToTheMusic[player]], 2, 2);
                }
                if (pl->cell != 0) {
                    func_800298A4_2A4A4(D_8010D764_160BF4_MoveToTheMusic->model[8 + pl->cell], 4, 4);
                }
            }
            D_8010D768_160BF8_MoveToTheMusic[player] = D_8010D768_160BF8_MoveToTheMusic[player] <= 0 ? D_8010D768_160BF8_MoveToTheMusic[player] : D_8010D768_160BF8_MoveToTheMusic[player] - (D_8010D7E8_160C78_MoveToTheMusic - D_8010D760_160BF0_MoveToTheMusic) * 2;
            if (D_8010D708_160B98_MoveToTheMusic[player]->cell == 0 || D_8010D741_160BD1_MoveToTheMusic[D_8010D708_160B98_MoveToTheMusic[player]->cell - 1] == 0) {
                mdl = obj->model[D_8010D7D8_160C68_MoveToTheMusic[player]];
                if (D_8010D768_160BF8_MoveToTheMusic[player] > 0) {
                    f = (f32)(D_8010D738_160BC8_MoveToTheMusic[player] - D_8010D768_160BF8_MoveToTheMusic[player]) / 30.0f;
                } else {
                    f = (f32)((D_8010D798_160C28_MoveToTheMusic + 7) % 15) / 15.0f;
                }
                func_80029C74_2A874(mdl, f * 30.0);
            }
        }
        if (pl->cell == 0 && D_8010D798_160C28_MoveToTheMusic < D_8010D75C_160BEC_MoveToTheMusic && D_8010D7CC_160C5C_MoveToTheMusic == 4) {
            D_8010D728_160BB8_MoveToTheMusic[0] = -1;
        }
        if (pl->cell != 0 && D_8010D798_160C28_MoveToTheMusic < D_8010D75C_160BEC_MoveToTheMusic && (D_8010D7CC_160C5C_MoveToTheMusic == 2 || D_8010D7CC_160C5C_MoveToTheMusic == 6)) {
            D_8010D728_160BB8_MoveToTheMusic[pl->cell] = -1;
        }
        if (pl->cpu != -1) {
            if (pl->cpu >= -1) {
                if (pl->cpu < 4) {
                    if (D_8010D7CC_160C5C_MoveToTheMusic == 1 || D_8010D7CC_160C5C_MoveToTheMusic == 5) {
                        if (D_8010D728_160BB8_MoveToTheMusic[pl->cell] < beat) {
                            if (((D_8010D7CC_160C5C_MoveToTheMusic >= 5 ? pl->step[1] : pl->step[0])[beat] != 0 & beat >= 0) && beat < 6 && D_8010D806_160C96_MoveToTheMusic[beat] != 0) {
                                d = (frame + 110) % 30 - 20;
                                o = pl->offs[0];
                                if (D_8010D7CC_160C5C_MoveToTheMusic >= 4) {
                                    o = pl->offs[1];
                                }
                                if (d >= o[beat]) {
                                    btn = (D_8010D7CC_160C5C_MoveToTheMusic >= 5 ? pl->step[1] : pl->step[0])[beat];
                                }
                            }
                        }
                    } else if ((D_8010D7CC_160C5C_MoveToTheMusic == 3 || D_8010D7CC_160C5C_MoveToTheMusic == 7) && D_8010D728_160BB8_MoveToTheMusic[pl->cell] < beat) {
                            if (((D_8010D7CC_160C5C_MoveToTheMusic >= 5 ? pl->step[1] : pl->step[0])[beat] != 0 & beat >= 0) && beat < 6 && D_8010D806_160C96_MoveToTheMusic[beat] != 0) {
                                d = (frame + 95) % 30 - 5;
                                o = pl->offs[0];
                                if (D_8010D7CC_160C5C_MoveToTheMusic >= 4) {
                                    o = pl->offs[1];
                                }
                                if (d >= o[beat]) {
                                    t = (D_8010D7CC_160C5C_MoveToTheMusic >= 5 ? pl->step[1] : pl->step[0])[beat];
                                    if (t == 1) {
                                        if (D_8010D806_160C96_MoveToTheMusic[beat] == t) {
                                            btn = (u8)(rand8() % 7) + 2;
                                        } else {
                                            btn = D_8010D806_160C96_MoveToTheMusic[beat];
                                        }
                                    } else {
                                        btn = (D_8010D806_160C96_MoveToTheMusic[beat] == 2 ? 3 : 0) | 2;
                                    }
                                }
                            }
                    }
                }
            }
        } else {
            v = ContStkX[pl->port];
            t = v > 0;
            if (v < 0) {
                t = -1;
            }
            dirx = t;
            if (fabs(ContStkX[pl->port]) <= fabs(ContStkY[pl->port])) {
                dirx = 0;
            }
            v = ContStkY[pl->port];
            t = v > 0;
            if (v < 0) {
                t = -1;
            }
            diry = t;
            if (fabs(ContStkX[pl->port]) > fabs(ContStkY[pl->port])) {
                diry = 0;
            }
            if ((s16)dirx >= 0 || ContStkX[pl->port] >= D_8010D79C_160C2C_MoveToTheMusic[player]) {
                flickx = 0;
                if ((s16)dirx > 0) {
                    flickx = D_8010D79C_160C2C_MoveToTheMusic[player] < ContStkX[pl->port];
                }
            } else {
                flickx = -1;
            }
            if ((s16)diry >= 0 || ContStkY[pl->port] >= D_8010D7A4_160C34_MoveToTheMusic[player]) {
                flicky = 0;
                if ((s16)diry > 0) {
                    flicky = D_8010D7A4_160C34_MoveToTheMusic[player] < ContStkY[pl->port];
                }
            } else {
                flicky = -1;
            }
            D_8010D79C_160C2C_MoveToTheMusic[player] = ContStkX[pl->port];
            D_8010D7A4_160C34_MoveToTheMusic[player] = ContStkY[pl->port];
            b = ContBtnTrg[pl->port];
            if (!(b & 0x8000)) {
                if (!(b & 0x4000)) {
                    b = (b & 0x2000) ? 3 : 0;
                } else {
                    b = 2;
                }
            } else {
                b = 1;
            }
            if (flicky != 1) {
                if (flicky != -1) {
                    btn = 8;
                    if (flickx != 1) {
                        if (flickx != -1) {
                            v = b;
                            if (v > 0) {
                                btn = v + 1;
                            } else {
                                btn = 0;
                            }
                        } else {
                            btn = 7;
                        }
                    }
                } else {
                    btn = 6;
                }
            } else {
                btn = 5;
            }
        }
        switch (D_8010D7CC_160C5C_MoveToTheMusic) {
        case 0:
        case 1:
        case 4:
        case 5:
            if (pl->cell == 0) {
                if (((frame + 7) % 30 < 15 & frame >= -14) && (u32)beat < 6 && (D_8010D806_160C96_MoveToTheMusic[beat] == 1 & btn != 0)) {
                    D_8010D806_160C96_MoveToTheMusic[beat] = btn;
                    D_8010D770_160C00_MoveToTheMusic[0] = 7;
                    D_8010D728_160BB8_MoveToTheMusic[0] = beat;
                    func_80029B80_2A780(obj->model[D_8010D7D8_160C68_MoveToTheMusic[player]], obj->motion[btn + 3]);
                    func_80029E80_2AA80(obj->model[D_8010D7D8_160C68_MoveToTheMusic[player]], 2, 2);
                    t = func_80029D0C_2A90C(obj->motion[btn + 3]);
                    D_8010D738_160BC8_MoveToTheMusic[player] = t;
                    D_8010D768_160BF8_MoveToTheMusic[player] = t;
                    D_8010D7AC_160C3C_MoveToTheMusic[0] = btn - 2;
                    D_8010D80E_160C9E_MoveToTheMusic[0] = (u16)D_8010CCB4_160144_MoveToTheMusic[pl->character][btn - 2];
                }
            }
            break;
        case 2:
        case 3:
        case 6:
        case 7:
            if (pl->cell != 0 && D_8010D768_160BF8_MoveToTheMusic[player] < 0x15 && D_8010D741_160BD1_MoveToTheMusic[pl->cell - 1] == 0 && ((D_8010D722_160BB2_MoveToTheMusic[beat] >> (pl->cell - 1)) & 1)) {
                s16 unused[4] = { 0x40, 0x20, 0x40, 0x60 };

                if (((frame + 95) % 30 < 10 & frame >= -14) && (u32)beat < 6 && (v = D_8010D806_160C96_MoveToTheMusic[beat]) != 0 && D_8010D728_160BB8_MoveToTheMusic[pl->cell] != beat && (btn == v || (v == 1 & btn != 0))) {
                    D_8010D770_160C00_MoveToTheMusic[pl->cell] = 7;
                    D_8010D728_160BB8_MoveToTheMusic[pl->cell] = beat;
                    func_80029B80_2A780(obj->model[D_8010D7D8_160C68_MoveToTheMusic[player]], obj->motion[btn + 3]);
                    func_80029E80_2AA80(obj->model[D_8010D7D8_160C68_MoveToTheMusic[player]], 2, 2);
                    D_8010D768_160BF8_MoveToTheMusic[player] = D_8010D738_160BC8_MoveToTheMusic[player] = func_80029D0C_2A90C(obj->motion[btn + 3]) / 30.0 * 30.0;
                    if ((frame + 2) % 30 < 5) {
                        D_8010D75A_160BEA_MoveToTheMusic = D_8010D75A_160BEA_MoveToTheMusic < 100 ? D_8010D75A_160BEA_MoveToTheMusic + 1 : D_8010D75A_160BEA_MoveToTheMusic;
                    }
                    D_8010D7AC_160C3C_MoveToTheMusic[pl->cell] = btn - 2;
                    D_8010D80E_160C9E_MoveToTheMusic[pl->cell] = (u16)D_8010CCB4_160144_MoveToTheMusic[pl->character][btn - 2];
                } else if (frame >= -14) {
                    if ((D_8010D728_160BB8_MoveToTheMusic[pl->cell] != beat & beat >= 0) && beat < 6) {
                        v = D_8010D806_160C96_MoveToTheMusic[beat];
                        if (btn != v && (v != 1 | btn == 0) && btn != 0) {
                            if ((D_8010D722_160BB2_MoveToTheMusic[beat] >> (pl->cell - 1)) & 1) {
                                D_8010D741_160BD1_MoveToTheMusic[pl->cell - 1] = 1;
                            }
                            D_8010D770_160C00_MoveToTheMusic[pl->cell] = 7;
                            D_8010D728_160BB8_MoveToTheMusic[pl->cell] = beat;
                            func_80029B80_2A780(obj->model[D_8010D7D8_160C68_MoveToTheMusic[player]], obj->motion[4]);
                            if (pl->cell != 0) {
                                func_800298A4_2A4A4(D_8010D764_160BF4_MoveToTheMusic->model[8 + pl->cell], 4, 0);
                            }
                            if (pl->cpu == -1) {
                                omVibrate(pl->player, 10, 0, 10);
                            }
                            D_8010D768_160BF8_MoveToTheMusic[player] = D_8010D738_160BC8_MoveToTheMusic[player] = func_80029D0C_2A90C(obj->motion[4]) / 30.0 * 30.0;
                            t = D_8010D75A_160BEA_MoveToTheMusic;
                            if (t > 0) {
                                t--;
                            }
                            D_8010D75A_160BEA_MoveToTheMusic = t;
                            D_8010D7AC_160C3C_MoveToTheMusic[pl->cell] = 7;
                            D_8010D80E_160C9E_MoveToTheMusic[pl->cell] = (u16)D_8010CCB4_160144_MoveToTheMusic[pl->character][7];
                        }
                    }
                }
                if ((frame + 95) % 30 >= 10 && ((prev + 95) % 30 < 10 & frame >= -14) && (u32)beat < 6 && D_8010D806_160C96_MoveToTheMusic[beat] != 0) {
                    if (D_8010D728_160BB8_MoveToTheMusic[pl->cell] != beat) {
                        if ((D_8010D722_160BB2_MoveToTheMusic[beat] >> (pl->cell - 1)) & 1) {
                            D_8010D741_160BD1_MoveToTheMusic[pl->cell - 1] = 1;
                        }
                        func_80029B80_2A780(obj->model[D_8010D7D8_160C68_MoveToTheMusic[player]], obj->motion[4]);
                        if (pl->cell != 0) {
                            func_800298A4_2A4A4(D_8010D764_160BF4_MoveToTheMusic->model[8 + pl->cell], 4, 0);
                        }
                        if (pl->cpu == -1) {
                            omVibrate(pl->player, 10, 0, 10);
                        }
                        D_8010D768_160BF8_MoveToTheMusic[player] = D_8010D738_160BC8_MoveToTheMusic[player] = func_80029D0C_2A90C(obj->motion[4]) / 30.0 * 30.0;
                        t = D_8010D75A_160BEA_MoveToTheMusic;
                        if (t > 0) {
                            t--;
                        }
                        D_8010D75A_160BEA_MoveToTheMusic = t;
                        D_8010D7AC_160C3C_MoveToTheMusic[pl->cell] = 7;
                        D_8010D80E_160C9E_MoveToTheMusic[pl->cell] = (u16)D_8010CCB4_160144_MoveToTheMusic[pl->character][7];
                    }
                }
            }
            break;
        }
        if (D_8010D80E_160C9E_MoveToTheMusic[pl->cell] == 0) {
            s16 pan[4] = { 0x40, 0x20, 0x40, 0x60 };

            if (D_8010D7AC_160C3C_MoveToTheMusic[pl->cell] == 7) {
                s = func_800797DC_7A3DC(0xFC, player);
            } else {
                s = func_80079798_7A398(D_8010CC0C_16009C_MoveToTheMusic[pl->character][D_8010D7AC_160C3C_MoveToTheMusic[pl->cell]], pl->cell);
            }
            func_800798F8_7A4F8(s, pan[pl->cell]);
            if (pl->cell != 0) {
                func_800795D8_7A1D8(s, 0x7A);
            }
        }
        p = &D_8010D80E_160C9E_MoveToTheMusic[pl->cell];
        t = *p;
        if (t >= 0) {
            t--;
        }
        *p = t;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_11_MoveToTheMusic/155C90", func_80105A90_158F20_MoveToTheMusic);
#endif

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
