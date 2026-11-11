#include "ovl_18.h"

/* .data (0x1906D0-0x190C80, 8010CA40-8010CFF0) */
s16 D_8010CA40_1906D0_ToadBandstand[4][2] = { { 120, 121 }, { 120, 121 }, { 120, 121 }, { 120, 121 } };
s32 D_8010CA50_1906E0_ToadBandstand[2][36] = { { 0 }, { 0 } };
u16 D_8010CB70_190800_ToadBandstand[2] = { 135, 120 };
f32 D_8010CB74_190804_ToadBandstand[2] = { 1.125f, 1.0f };
f32 D_8010CB7C_19080C_ToadBandstand[34] = { 11.25f, 10.0f };
u32 D_8010CC04_190894_ToadBandstand[15] = { 150, 60, 137, 136, 135, 134, 135, 134, 135, 200, 60, 168, 168, 120, 300 };
s32 D_8010CC40_1908D0_ToadBandstand[15] = { 150, 60, 121, 121, 120, 119, 120, 119, 120, 250, 60, 168, 168, 120, 300 };
f32 D_8010CC7C_19090C_ToadBandstand[6] = { -100.0f, 90.625f, -65.0f, 57.5f, -50.0f, 42.5f };
f32 D_8010CC94_190924_ToadBandstand[6] = { 0.0f, 16.25f, 32.5f, 48.75f, 65.0f, 65.0f };
f32 D_8010CCAC_19093C_ToadBandstand[6] = { 300.0f, 290.0f, 280.0f, 255.0f, 260.0f, 250.0f };
f32 D_8010CCC4_190954_ToadBandstand[7] = { 0.75f, 0.90625f, 0.8125f, 0.5390625f, 0.625f, 0.578125f, 0.0f };
Gfx D_8010CCE0_190970_ToadBandstand[] = {
    { { 0xE7000000, 0x00000000 } },
    { { 0xE3000A01, 0x00000000 } },
    { { 0xFCFFFFFF, 0xFFFCF279 } },
    { { 0xE200001C, 0x00504240 } },
    { { 0xE2001E01, 0x00000001 } },
    { { 0xE3000C00, 0x00000000 } },
    { { 0xE3001201, 0x00002000 } },
    { { 0xED000000, 0x005003C0 } },
    { { 0xF9000000, 0x00000080 } },
    { { 0xDF000000, 0x00000000 } },
};
Gfx D_8010CD30_1909C0_ToadBandstand[] = {
    { { 0xE7000000, 0x00000000 } },
    { { 0xE3000A01, 0x00000000 } },
    { { 0xFCFFFFFF, 0xFFFCF279 } },
    { { 0xE200001C, 0x00552048 } },
    { { 0xE2001E01, 0x00000000 } },
    { { 0xE3000C00, 0x00000000 } },
    { { 0xE3001201, 0x00002000 } },
    { { 0xED000000, 0x005003C0 } },
    { { 0xDF000000, 0x00000000 } },
    { { 0x00000000, 0x00000000 } },
};
u8 D_8010CD80_190A10_ToadBandstand[12] = { 0x82, 0x72, 0x82, 0x73, 0x82, 0x60, 0x82, 0x71, 0x82, 0x73, 0x00, 0x00 };
TSBytes4 D_8010CD8C_190A1C_ToadBandstand = { { 7, 10, 20, 30 } };
TSBytes4 D_8010CD90_190A20_ToadBandstand = { { 2, 1, 0, 0 } };
TSBeats D_8010CD94_190A24_ToadBandstand = { { { 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1 }, { 0, 1, 2, 3, 0, 0, 0, 4, 1, 5, 0, 0, 0, 6, 7, 8, 0, 6, 9, 0, 1, 8, 0, 0, 0, 4, 1, 10, 4, 7, 8, 0, 1, 8, 0, 0 } } };
TSBeats D_8010CDDC_190A6C_ToadBandstand = { { { 0, 1, 2, 0, 3, 0, 0, 4, 5, 0, 6, 7, 0, 0, 8, 0, 0, 9, 0, 0, 10, 0, 11, 12, 0, 13, 14, 0, 0, 15, 0, 16, 17, 18, 0, 19 }, { 0, 1, 2, 3, 0, 0, 0, 4, 5, 6, 0, 0, 0, 7, 8, 9, 0, 10, 11, 0, 12, 13, 0, 0, 0, 14, 15, 16, 17, 18, 19, 0, 20, 21, 0, 0 } } };
TSSteps D_8010CE24_190AB4_ToadBandstand = { { { 284, 295, 317, 351, 362, 385, 396, 564, 598, 631, 654, 665, 822, 833, 867, 889, 901, 912, 934, 65535, 0, 0, 0, 0, 0, 0, 0 }, { 284, 295, 306, 351, 362, 373, 553, 564, 575, 598, 609, 631, 643, 822, 833, 844, 856, 867, 878, 901, 912, 65535, 0, 0, 0, 0, 0 } } };
TSTimes D_8010CE90_190B20_ToadBandstand = { { { 251, 351, 520, 620, 789, 889 }, { 317, 418, 587, 687, 856, 956 } } };
TSBeats D_8010CEA8_190B38_ToadBandstand = { { { 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1 }, { 0, 11, 12, 6, 13, 2, 14, 6, 13, 9, 0, 0, 0, 13, 2, 4, 2, 13, 15, 0, 2, 9, 0, 0, 0, 4, 4, 16, 2, 4, 17, 18, 19, 8, 0, 0 } } };
TSBeats D_8010CEF0_190B80_ToadBandstand = { { { 0, 1, 0, 2, 0, 0, 0, 3, 0, 4, 0, 5, 0, 6, 0, 7, 0, 0, 0, 8, 0, 9, 10, 11, 0, 12, 0, 13, 0, 14, 0, 15, 0, 16, 17, 18 }, { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 10, 11, 12, 13, 14, 15, 0, 16, 17, 0, 0, 0, 18, 19, 20, 21, 22, 23, 24, 25, 26, 0, 0 } } };
TSSteps D_8010CF38_190BC8_ToadBandstand = { { { 252, 272, 312, 332, 352, 491, 511, 551, 571, 581, 591, 731, 751, 770, 790, 810, 820, 830, 65535, 0, 0, 0, 0, 0, 0, 0, 0 }, { 252, 262, 272, 282, 292, 302, 312, 322, 332, 491, 501, 511, 521, 531, 541, 561, 571, 731, 741, 751, 760, 770, 780, 790, 800, 810, 65535 } } };
TSTimes D_8010CFA4_190C34_ToadBandstand = { { { 222, 312, 461, 551, 701, 790 }, { 282, 372, 521, 611, 760, 850 } } };
TSPans D_8010CFBC_190C4C_ToadBandstand = { { 48, 48, 80, 80 } };
TSFloats4 D_8010CFC4_190C54_ToadBandstand = { { -100.0f, -200.0f, 100.0f, 200.0f } };
TSDirs D_8010CFD4_190C64_ToadBandstand = { { 2, 3, 7, 4, 5, 6, 0 } };

void func_80102800_186490_ToadBandstand(void) {
    u8 view;

    func_80020D20_21920(0x20);
    omInitObjMan(0x80, 0);
    func_80079128_79D28();
    func_80029708_2A308(1);
    func_80018E30_19A30(1);
    view = func_80018E78_19A78() & 0xFF;
    ScissorSet(view, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(view, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 50.0f, 200.0f, 5000.0f);
    func_80026D28_27928(1);
    func_80026E00_27A00(0, 0.0f, 0.0f, 90.0f);
    func_80026DAC_279AC(0, 0x80, 0x80, 0x80);
    func_80026E00_27A00(1, 0.0f, 30.0f, 60.0f);
    func_80026DAC_279AC(1, 0xFF, 0xFF, 0xFF);
    omAddObj(0, 0, 0, -1, func_80102AA4_186734_ToadBandstand);
    D_8010DA68_1916F8_ToadBandstand = omAddObj(8, 0x14, 0x14, -1, func_80105480_189110_ToadBandstand);
    omSetStatBit(D_8010DA68_1916F8_ToadBandstand, 0xA0);
    D_8010DA88_191718_ToadBandstand[0] = omAddObj(2, 0xF, 0xF, -1, func_801070F8_18AD88_ToadBandstand);
    D_8010DA88_191718_ToadBandstand[1] = omAddObj(2, 0xF, 0xF, -1, func_8010712C_18ADBC_ToadBandstand);
    D_8010DA88_191718_ToadBandstand[2] = omAddObj(2, 0xF, 0xF, -1, func_80107160_18ADF0_ToadBandstand);
    D_8010DA88_191718_ToadBandstand[3] = omAddObj(2, 0xF, 0xF, -1, func_80107194_18AE24_ToadBandstand);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_8010C804_190494_ToadBandstand), 0xA0);
    func_8007273C_7333C(D_8010CD80_190A10_ToadBandstand, 1);
    InitFadeIn(0, 0x10);
}

/* NON_MATCHING: class 4: operand order of one addu (retail addu a0,v0,v1); masked 0 */
// decomp-permuter
void func_80102A68_1866F8_ToadBandstand(s16 model, f32 arg1)
{
  s32 i = model;
  HmfModel *base = D_800FC834_FD434;
  HmfModel *m;
  if ((i + base)->unk04 != 0xFF)
  {
    (i + base)->unk4C = arg1;
  }
}

/* NON_MATCHING: class 4: register allocation and frame size (retail 0x60, one 8-byte slot unexplained); masked differs by the frame only */
#ifdef NON_MATCHING
void func_80102AA4_186734_ToadBandstand(omObjData* obj) {
    s8 miss[4];
    s8 spread[4];
    s32 i;
    s32 j;
    TSPlayer* pl;
    TSPlayer* q;
    u8* place;
    s8* mp;
    s8* sd;
    u8* order;

    D_8010DAA0_191730_ToadBandstand = 0;
    D_8010D8FC_19158C_ToadBandstand = 0;
    D_8010D980_191610_ToadBandstand = 0;
    D_8010D9BC_19164C_ToadBandstand = 0;
    D_8010D988_191618_ToadBandstand = 0;
    D_8010D860_1914F0_ToadBandstand[0] = D_8010D860_1914F0_ToadBandstand[1] = D_8010D860_1914F0_ToadBandstand[2] = D_8010D860_1914F0_ToadBandstand[3] = 0;
    D_8010D9B4_191644_ToadBandstand[0] = D_8010D9B4_191644_ToadBandstand[1] = D_8010D9B4_191644_ToadBandstand[2] = D_8010D9B4_191644_ToadBandstand[3] = 0;
    D_8010DAA8_191738_ToadBandstand[0] = 0;
    D_8010DAA8_191738_ToadBandstand[1] = 0;
    D_8010DAA6_191736_ToadBandstand = 0;
    D_8010DA42_1916D2_ToadBandstand[0] = 0;
    D_8010DA42_1916D2_ToadBandstand[1] = 0;
    D_8010D904_191594_ToadBandstand = rand8();
    D_8010D900_191590_ToadBandstand = 0;
    D_8010D984_191614_ToadBandstand = 0;
    D_8010D918_1915A8_ToadBandstand[0] = (u8)(rand8() % 30) * 2;
    D_8010D918_1915A8_ToadBandstand[1] = (u8)(rand8() % 30) * 2;
    D_8010D918_1915A8_ToadBandstand[2] = (u8)(rand8() % 30) * 2;
    D_8010D918_1915A8_ToadBandstand[3] = (u8)(rand8() % 30) * 2;
    D_8010DAAC_19173C_ToadBandstand = 0;
    D_8010DA40_1916D0_ToadBandstand = D_800FA656;
    D_8010D888_191518_ToadBandstand = 2.0f;
    if (D_8010DA40_1916D0_ToadBandstand == 0) {
        func_8010329C_186F2C_ToadBandstand();
    } else {
        func_80103780_187410_ToadBandstand();
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            D_8010D920_1915B0_ToadBandstand[i * 4 + j] = (D_8010DA28_1916B8_ToadBandstand[j][i * 2] - D_8010CB70_190800_ToadBandstand[D_8010DA40_1916D0_ToadBandstand]) + D_8010CB7C_19080C_ToadBandstand[D_8010DA40_1916D0_ToadBandstand];
            D_8010D920_1915B0_ToadBandstand[i * 4 + j + 2] = D_8010DA28_1916B8_ToadBandstand[j][i * 2];
        }
    }
    D_8010D920_1915B0_ToadBandstand[12] = (D_8010DA28_1916B8_ToadBandstand[0][4] + D_8010CB70_190800_ToadBandstand[D_8010DA40_1916D0_ToadBandstand]) + D_8010CB7C_19080C_ToadBandstand[D_8010DA40_1916D0_ToadBandstand];
    if (D_8010DA40_1916D0_ToadBandstand != 0) {
        for (i = 0; i < 15; i++) {
            D_8010CC04_190894_ToadBandstand[i] = D_8010CC40_1908D0_ToadBandstand[i];
        }
    }
    for (i = 0; i < 4; i++) {
        D_8010D848_1914D8_ToadBandstand[i] = &D_8010D710_1913A0_ToadBandstand[i];
        bzero(D_8010D848_1914D8_ToadBandstand[i], sizeof(TSPlayer));
    }
    for (i = 0; i < 4; i++) {
        D_8010D848_1914D8_ToadBandstand[i]->id = i;
        D_8010D848_1914D8_ToadBandstand[i]->port = gPlayers[i].port;
        D_8010D848_1914D8_ToadBandstand[i]->character = gPlayers[i].character;
        D_8010D848_1914D8_ToadBandstand[i]->group = gPlayers[i].group;
        D_8010DAA2_191732_ToadBandstand[D_8010D848_1914D8_ToadBandstand[i]->group] = i;
        D_8010D848_1914D8_ToadBandstand[i]->cpu = (gPlayers[D_8010D848_1914D8_ToadBandstand[i]->id].flags & 1) ? gPlayers[D_8010D848_1914D8_ToadBandstand[i]->id].cpu_difficulty : -1;
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 36; j++) {
            D_8010D848_1914D8_ToadBandstand[i]->press[j] = D_8010D848_1914D8_ToadBandstand[i]->timing[j] = 0;
        }
    }
    *(TSBytes4*)miss = D_8010CD8C_190A1C_ToadBandstand;
    *(TSBytes4*)spread = D_8010CD90_190A20_ToadBandstand;
    mp = miss;
    sd = spread;
    order = D_8010DAA2_191732_ToadBandstand;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 36; j++) {
            if ((j % 12) < 6) {
                place = order + i;
            } else {
                place = (order + 2) + i;
            }
            pl = D_8010D848_1914D8_ToadBandstand[*place];
            if (pl->cpu != -1) {
                /* fakematch: retail keeps pl + j, field offsets from there */
                if (D_8010D9C0_191650_ToadBandstand[i][j] == 0) {
                    q = (TSPlayer*)((s8*)pl + j);
                    q->press[0] = (s32)rand8() % mp[pl->cpu] == 0;
                } else {
                    q = (TSPlayer*)((s8*)pl + j);
                    q->press[0] = (s32)rand8() % mp[pl->cpu] != 0;
                }
                q->timing[0] = ((s32)rand8() % (sd[pl->cpu] * 2 + 1)) - sd[pl->cpu] - 1;
            }
        }
    }
    D_8010D908_191598_ToadBandstand[0] = D_8010D908_191598_ToadBandstand[1] = D_8010D908_191598_ToadBandstand[2] = D_8010D908_191598_ToadBandstand[3] = 0;
    D_8010DA98_191728_ToadBandstand[0] = D_8010DA98_191728_ToadBandstand[1] = D_8010DA98_191728_ToadBandstand[2] = D_8010DA98_191728_ToadBandstand[3] = -1;
    D_8010DAAD_19173D_ToadBandstand[0] = D_8010DAAD_19173D_ToadBandstand[1] = D_8010DAAD_19173D_ToadBandstand[2] = D_8010DAAD_19173D_ToadBandstand[3] = 0;
    D_8010D878_191508_ToadBandstand[0] = D_8010D878_191508_ToadBandstand[1] = D_8010D878_191508_ToadBandstand[2] = D_8010D878_191508_ToadBandstand[3] = 0;
    D_8010D868_1914F8_ToadBandstand[0] = D_8010D868_1914F8_ToadBandstand[1] = D_8010D868_1914F8_ToadBandstand[2] = D_8010D868_1914F8_ToadBandstand[3] = 0;
    func_8002838C_28F8C(0, func_80109388_18D018_ToadBandstand, 2);
    obj->func_ptr = func_80103C64_1878F4_ToadBandstand;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_18_ToadBandstand/186490", func_80102AA4_186734_ToadBandstand);
#endif

void func_8010329C_186F2C_ToadBandstand(void) {
    TSBeats beats;
    TSBeats want;
    TSSteps steps;
    TSTimes times;
    s16 i;
    s16 j;

    beats = D_8010CD94_190A24_ToadBandstand;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 36; j++) {
            D_8010CA50_1906E0_ToadBandstand[i][j] = beats.v[i][j] != 0 ? (i != 0 ? beats.v[i][j] + 0x48C : 0x4A0) : 0;
        }
    }
    want = D_8010CDDC_190A6C_ToadBandstand;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 36; j++) {
            D_8010D9C0_191650_ToadBandstand[i][j] = want.v[i][j];
        }
    }
    steps = D_8010CE24_190AB4_ToadBandstand;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 27; j++) {
            D_8010D890_191520_ToadBandstand[i][j] = steps.v[i][j];
        }
    }
    times = D_8010CE90_190B20_ToadBandstand;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 6; j++) {
            D_8010DA28_1916B8_ToadBandstand[i][j] = times.v[i][j];
        }
    }
}

void func_80103780_187410_ToadBandstand(void) {
    TSBeats beats;
    TSBeats want;
    TSSteps steps;
    TSTimes times;
    s16 i;
    s16 j;

    beats = D_8010CEA8_190B38_ToadBandstand;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 36; j++) {
            D_8010CA50_1906E0_ToadBandstand[i][j] = beats.v[i][j] != 0 ? (i != 0 ? beats.v[i][j] + 0x48C : 0x4A0) : 0;
        }
    }
    want = D_8010CEF0_190B80_ToadBandstand;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 36; j++) {
            D_8010D9C0_191650_ToadBandstand[i][j] = want.v[i][j];
        }
    }
    steps = D_8010CF38_190BC8_ToadBandstand;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 27; j++) {
            D_8010D890_191520_ToadBandstand[i][j] = steps.v[i][j];
        }
    }
    times = D_8010CFA4_190C34_ToadBandstand;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 6; j++) {
            D_8010DA28_1916B8_ToadBandstand[i][j] = times.v[i][j];
        }
    }
}

void func_80103C64_1878F4_ToadBandstand(omObjData* obj) {
    TSPans pans;
    TSFloats4 xs;
    TSDirs dirs;
    TSDirs dirs2;
    s16 i;
    u8 k;
    s32 mes;
    u8* team;
    f32 t;
    f32 v;
    f32 dx;
    f32 t2;
    f32 v2;
    f32 dx2;
    f32 dy2;
    u8 j;
    u8 n;
    TSPlayer* pl;
    omObjData** op;
    f32 dy;

    D_8010DA6C_1916FC_ToadBandstand = D_8010D980_191610_ToadBandstand;
    D_8010DA70_191700_ToadBandstand = D_8010D9BC_19164C_ToadBandstand;
    D_8010D9B0_191640_ToadBandstand = D_8010D988_191618_ToadBandstand;
    D_8010D980_191610_ToadBandstand++;
    D_8010D9BC_19164C_ToadBandstand++;
    D_8010D988_191618_ToadBandstand++;
    if (D_8010D980_191610_ToadBandstand >= D_8010CC04_190894_ToadBandstand[D_8010D8FC_19158C_ToadBandstand]) {
        D_8010D980_191610_ToadBandstand -= D_8010CC04_190894_ToadBandstand[D_8010D8FC_19158C_ToadBandstand];
        D_8010D8FC_19158C_ToadBandstand++;
        if (_CheckFlag(0xC) != 0 && D_8010D8FC_19158C_ToadBandstand == 11) {
            D_8010D8FC_19158C_ToadBandstand = 14;
            D_8010DAA6_191736_ToadBandstand = 3;
            if (D_8010DAA8_191738_ToadBandstand[0] != D_8010DAA8_191738_ToadBandstand[1] || D_8010DA42_1916D2_ToadBandstand[0] != 0 || D_8010DA42_1916D2_ToadBandstand[1] != 0) {
                if (D_8010DAA8_191738_ToadBandstand[0] > D_8010DAA8_191738_ToadBandstand[1] || (D_8010DAA8_191738_ToadBandstand[0] == D_8010DAA8_191738_ToadBandstand[1] && (rand8() & 1))) {
                    team = &D_8010DAA2_191732_ToadBandstand[0];
                } else {
                    team = &D_8010DAA2_191732_ToadBandstand[2];
                }
                gPlayers[team[0]].coins_mg_bonus += 10;
                gPlayers[team[1]].coins_mg_bonus += 10;
            }
        }
    }
    switch (D_8010D8FC_19158C_ToadBandstand) {
    case 0:
        if (D_8010D980_191610_ToadBandstand == 3) {
            PlaySound(0x4A1);
        }
        /* retail: never true, the timer is not negative */
        if (D_8010D980_191610_ToadBandstand < -135) {
            pans = D_8010CFBC_190C4C_ToadBandstand;
            for (i = 0; i < 4; i++) {
                if (--D_8010D918_1915A8_ToadBandstand[i] <= 0) {
                    func_800798F8_7A4F8(mes = func_80079798_7A398(i == 0 ? 0x4A0 : (u8)(rand8() % 20) + 0x48D, i), pans.v[i]);
                    func_800795D8_7A1D8(mes, (s8)(80 - (s16)(i % 2) * 20));
                    D_8010D918_1915A8_ToadBandstand[i] = (u8)(rand8() % 30) + 10;
                }
            }
        }
        break;
    case 1:
        if (D_8010D980_191610_ToadBandstand < D_8010DA6C_1916FC_ToadBandstand) {
            func_800691FC_69DFC(0);
        }
        if (D_80102708_103308 == 0) {
            D_80102708_103308 = 1;
        }
        break;
    case 2:
        if (D_8010D980_191610_ToadBandstand < D_8010DA6C_1916FC_ToadBandstand) {
            if (D_8010DAA0_191730_ToadBandstand == 0 && D_801011FC_101DFC == 0) {
                PlayMusic(D_8010DA40_1916D0_ToadBandstand != 0 ? 0x2D : 0x2C);
            }
            D_8010D988_191618_ToadBandstand = 0;
        }
        break;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        break;
    case 10:
        if (D_8010D980_191610_ToadBandstand < D_8010DA6C_1916FC_ToadBandstand) {
            func_800691FC_69DFC(3);
            for (k = 0; k < 4; k++) {
                op = &D_8010DA88_191718_ToadBandstand[k];
                func_8002D124_2DD24((*op)->model[11]);
                if (!(D_8010D848_1914D8_ToadBandstand[k]->group & 1)) {
                    func_8002D124_2DD24((*op)->model[7]);
                }
                func_80029BF0_2A7F0(D_8010DA88_191718_ToadBandstand[k]->model[0], func_80029E14_2AA14(D_8010DA88_191718_ToadBandstand[k]->model[1]), 0, 0x2D, 2);
            }
        }
        if (D_8010D980_191610_ToadBandstand < 15) {
            for (j = 0; j < 4; j++) {
                if (j % 2 == 0) {
                    func_8002D0A0_2DCA0(D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[j]]->model[7], 0xFF - (u32)(D_8010D980_191610_ToadBandstand / 15.0f * 255.0));
                }
                func_8002D0A0_2DCA0(D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[j]]->model[11], 0xFF - (u32)(D_8010D980_191610_ToadBandstand / 15.0f * 255.0));
            }
        }
        if (D_8010D980_191610_ToadBandstand == 15) {
            for (j = 0; j < 4; j++) {
                if (j % 2 == 0) {
                    func_800298A4_2A4A4(D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[j]]->model[7], 4, 4);
                }
                func_800298A4_2A4A4(D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[j]]->model[11], 4, 4);
            }
        }
        break;
    case 11:
        if (D_8010D980_191610_ToadBandstand < D_8010DA6C_1916FC_ToadBandstand) {
            if (D_8010DAA8_191738_ToadBandstand[0] == D_8010DAA8_191738_ToadBandstand[1] && D_8010DA42_1916D2_ToadBandstand[0] == 0 && D_8010DA42_1916D2_ToadBandstand[1] == 0) {
                D_8010D8FC_19158C_ToadBandstand = 13;
                D_8010DAA6_191736_ToadBandstand = 3;
                func_800691FC_69DFC(0x13);
                if (D_8010DAA0_191730_ToadBandstand == 0 && D_801011FC_101DFC == 0) {
                    PlayMusic(0x57);
                }
            } else {
                if (D_8010DAA8_191738_ToadBandstand[0] > D_8010DAA8_191738_ToadBandstand[1] || (D_8010DAA8_191738_ToadBandstand[0] == D_8010DAA8_191738_ToadBandstand[1] && (rand8() & 1))) {
                    D_8010DAA6_191736_ToadBandstand = 1;
                    gPlayers[D_8010DAA2_191732_ToadBandstand[0]].coins_mg_bonus += 10;
                    gPlayers[D_8010DAA2_191732_ToadBandstand[1]].coins_mg_bonus += 10;
                    func_80029E80_2AA80(D_8010DA68_1916F8_ToadBandstand->model[2], 3, 2);
                    func_80029E80_2AA80(D_8010DA68_1916F8_ToadBandstand->model[3], 1, 1);
                    func_80029E80_2AA80(D_8010DA68_1916F8_ToadBandstand->model[4], 3, 1);
                    func_800298A4_2A4A4(D_8010DA68_1916F8_ToadBandstand->model[6], 4, 0);
                    func_800691FC_69DFC(0x11, D_8010D848_1914D8_ToadBandstand[D_8010DAA2_191732_ToadBandstand[1]]->character, D_8010D848_1914D8_ToadBandstand[D_8010DAA2_191732_ToadBandstand[0]]->character);
                } else {
                    D_8010D8FC_19158C_ToadBandstand = 12;
                    D_8010DAA6_191736_ToadBandstand = 2;
                    gPlayers[D_8010DAA2_191732_ToadBandstand[2]].coins_mg_bonus += 10;
                    gPlayers[D_8010DAA2_191732_ToadBandstand[3]].coins_mg_bonus += 10;
                    func_80029E80_2AA80(D_8010DA68_1916F8_ToadBandstand->model[3], 3, 2);
                    func_80029E80_2AA80(D_8010DA68_1916F8_ToadBandstand->model[2], 1, 1);
                    func_80029E80_2AA80(D_8010DA68_1916F8_ToadBandstand->model[5], 3, 1);
                    func_80029714_2A314(D_8010DA68_1916F8_ToadBandstand->model[6], 162.5f, 282.5f, 190.0f);
                    func_800298A4_2A4A4(D_8010DA68_1916F8_ToadBandstand->model[6], 4, 0);
                    func_800691FC_69DFC(0x11, D_8010D848_1914D8_ToadBandstand[D_8010DAA2_191732_ToadBandstand[2]]->character, D_8010D848_1914D8_ToadBandstand[D_8010DAA2_191732_ToadBandstand[3]]->character);
                }
                if (D_8010DAA0_191730_ToadBandstand == 0 && D_801011FC_101DFC == 0) {
                    PlayMusic(0x52);
                }
            }
        }
        if (D_8010D980_191610_ToadBandstand < 16) {
            t = D_8010D980_191610_ToadBandstand / 15.0;
            dx = -13.0f;
            dy = 22.0f;
            xs = D_8010CFC4_190C54_ToadBandstand;
            func_80029C74_2A874(D_8010DA68_1916F8_ToadBandstand->model[4], t * 30.0);
            omSetTra(D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[0]], xs.v[0] + dx * TS_ARC(t), t * dy + 255.0, 140.0f);
            omSetTra(D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[1]], xs.v[1] + TS_ARC(t) * dx, t * dy + 255.0, 140.0f);
            func_80029714_2A314(D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[0]]->model[12], xs.v[0] + TS_ARC(t) * dx, (t * dy + 255.0) - (D_8010D848_1914D8_ToadBandstand[D_8010DAA2_191732_ToadBandstand[0]]->character == 2 ? 5.0 : 0.0), 140.0f);
            func_80029714_2A314(D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[1]]->model[12], xs.v[1] + 7.5 + dx * TS_ARC(t), (dy * t + 255.0) - (D_8010D848_1914D8_ToadBandstand[D_8010DAA2_191732_ToadBandstand[1]]->character == 2 ? 5.0 : 0.0), D_8010D848_1914D8_ToadBandstand[D_8010DAA2_191732_ToadBandstand[1]]->character == 5 ? 122.5f : 140.0f);
            func_80029714_2A314(D_8010DA68_1916F8_ToadBandstand->model[7], dx * TS_ARC(t) + -100.0, dy * t + 230.0, 145.0f);
        }
        if (D_8010D980_191610_ToadBandstand == 15) {
            dirs = D_8010CFD4_190C64_ToadBandstand;
            func_80029B80_2A780(D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[0]]->model[0], D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[0]]->model[5]);
            func_80029B80_2A780(D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[1]]->model[0], D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[1]]->model[5]);
            func_800732B0_73EB0(dirs.v[D_8010D848_1914D8_ToadBandstand[D_8010DAA2_191732_ToadBandstand[0]]->character] << 16 | (!(D_8010D904_191594_ToadBandstand & 1) ? 0x4E : 0x4F));
            func_800732B0_73EB0(dirs.v[D_8010D848_1914D8_ToadBandstand[D_8010DAA2_191732_ToadBandstand[1]]->character] << 16 | (!(D_8010D904_191594_ToadBandstand & 1) ? 0x4E : 0x4F));
            func_80029B80_2A780(D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[2]]->model[0], D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[2]]->model[6]);
            func_80029B80_2A780(D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[3]]->model[0], D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[3]]->model[6]);
        }
        if (D_8010D980_191610_ToadBandstand >= 15 && D_8010D980_191610_ToadBandstand <= 30) {
            v = 1.0 - (D_8010D980_191610_ToadBandstand - 15.0) / 15.0;
            func_8002D0A0_2DCA0(D_8010DA68_1916F8_ToadBandstand->model[6], (u32)((1.0 - v * v) * 255.0));
        }
        break;
    case 12:
        if (D_8010D980_191610_ToadBandstand < D_8010DA6C_1916FC_ToadBandstand) {
            D_8010D8FC_19158C_ToadBandstand = 14;
        } else {
            if (D_8010D980_191610_ToadBandstand < 16) {
                t2 = D_8010D980_191610_ToadBandstand / 15.0;
                dx2 = 13.0f;
                dy2 = 22.0f;
                xs = D_8010CFC4_190C54_ToadBandstand;
                func_80029C74_2A874(D_8010DA68_1916F8_ToadBandstand->model[5], t2 * 30.0);
                omSetTra(D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[2]], xs.v[2] + dx2 * TS_ARC(t2), t2 * dy2 + 255.0, 140.0f);
                omSetTra(D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[3]], xs.v[3] + TS_ARC(t2) * dx2, t2 * dy2 + 255.0, 140.0f);
                func_80029714_2A314(D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[2]]->model[12], xs.v[2] + TS_ARC(t2) * dx2 - (D_8010D848_1914D8_ToadBandstand[D_8010DAA2_191732_ToadBandstand[2]]->character == 2 ? 5.0 : 0.0), dy2 * t2 + 255.0, 140.0f);
                func_80029714_2A314(D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[3]]->model[12], xs.v[3] + 7.5 + dx2 * TS_ARC(t2), (dy2 * t2 + 255.0) - (D_8010D848_1914D8_ToadBandstand[D_8010DAA2_191732_ToadBandstand[3]]->character == 2 ? 5.0 : 0.0), D_8010D848_1914D8_ToadBandstand[D_8010DAA2_191732_ToadBandstand[3]]->character == 5 ? 122.5f : 140.0f);
                func_80029714_2A314(D_8010DA68_1916F8_ToadBandstand->model[8], dx2 * TS_ARC(t2) + 100.0, dy2 * t2 + 230.0, 145.0f);
            }
            if (D_8010D980_191610_ToadBandstand == 15) {
                dirs2 = D_8010CFD4_190C64_ToadBandstand;
                func_80029B80_2A780(D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[2]]->model[0], D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[2]]->model[5]);
                func_80029B80_2A780(D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[3]]->model[0], D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[3]]->model[5]);
                func_800732B0_73EB0(dirs2.v[D_8010D848_1914D8_ToadBandstand[D_8010DAA2_191732_ToadBandstand[2]]->character] << 16 | (!(D_8010D904_191594_ToadBandstand & 1) ? 0x4E : 0x4F));
                func_800732B0_73EB0(dirs2.v[D_8010D848_1914D8_ToadBandstand[D_8010DAA2_191732_ToadBandstand[3]]->character] << 16 | (!(D_8010D904_191594_ToadBandstand & 1) ? 0x4E : 0x4F));
                func_80029B80_2A780(D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[0]]->model[0], D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[0]]->model[6]);
                func_80029B80_2A780(D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[1]]->model[0], D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[1]]->model[6]);
            }
            if (D_8010D980_191610_ToadBandstand >= 15 && D_8010D980_191610_ToadBandstand <= 30) {
                v2 = 1.0 - (D_8010D980_191610_ToadBandstand - 15.0) / 15.0;
                func_8002D0A0_2DCA0(D_8010DA68_1916F8_ToadBandstand->model[6], (u32)((1.0 - v2 * v2) * 255.0));
            }
            break;
        }
    case 13:
        if (D_8010D980_191610_ToadBandstand < D_8010DA6C_1916FC_ToadBandstand) {
            D_8010D8FC_19158C_ToadBandstand = 14;
        } else if (D_8010D8FC_19158C_ToadBandstand == 13) {
            if (D_8010D980_191610_ToadBandstand == 15) {
                func_80029B80_2A780(D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[0]]->model[0], D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[0]]->model[6]);
                func_80029B80_2A780(D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[1]]->model[0], D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[1]]->model[6]);
                func_80029B80_2A780(D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[2]]->model[0], D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[2]]->model[6]);
                func_80029B80_2A780(D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[3]]->model[0], D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[3]]->model[6]);
            }
            break;
        }
    case 14:
        if (D_8010D980_191610_ToadBandstand < D_8010DA6C_1916FC_ToadBandstand) {
            InitFadeOut(0, 0x14);
        } else if (D_8010D980_191610_ToadBandstand >= 32) {
            D_8010DAA0_191730_ToadBandstand = 1;
        }
        break;
    }
    if (_CheckFlag(0x15) != 0 && D_801011FC_101DFC == 0 && D_8010DAAC_19173C_ToadBandstand == 0 && D_8010D8FC_19158C_ToadBandstand >= 2 && D_8010D8FC_19158C_ToadBandstand <= 9) {
        for (n = 0; n < 4; n++) {
            pl = D_8010D848_1914D8_ToadBandstand[n];
            if (pl->cpu == -1 && (ContBtnTrg[pl->port] & 0x10)) {
                D_8010DAAC_19173C_ToadBandstand = 1;
            }
        }
    }
    if (D_8010DAA0_191730_ToadBandstand != 0 || D_801011FC_101DFC != 0 || D_8010DAAC_19173C_ToadBandstand != 0) {
        if (D_801011FC_101DFC != 0 && D_8010DAAC_19173C_ToadBandstand == 0) {
            D_8010DAAC_19173C_ToadBandstand = 1;
        }
        if (D_8010DAAC_19173C_ToadBandstand != 0) {
            if (D_8010DAAC_19173C_ToadBandstand == 1) {
                InitFadeOut(0, 0x14);
                func_800794A8_7A0A8(0x14);
                func_80079614_7A214(0x14);
            }
            D_8010DAAC_19173C_ToadBandstand++;
            if (D_8010DAAC_19173C_ToadBandstand < 25) {
                return;
            }
        }
        func_800794A8_7A0A8(0x28);
        omOvlReturnEx(1);
    }
}


void func_80105480_189110_ToadBandstand(omObjData* obj) {
    s32 files[15] = { 0x280012, 0x280013, 0x280014, 0x280015, 0x280016, 0x280017, 0x280018, 0x280019,
                      0x28001A, 0x2A000B, 0x2A000C, 0x2A000D, 0x2A000E, 0x2A000F, 0x2A0010 };
    s16 i;

    for (i = 0; i < 15; i++) {
        D_8010D940_1915D0_ToadBandstand[i] = func_8001A2F8_1AEF8(files[i]);
        if (i < 9) {
            D_8010D990_191620_ToadBandstand[i] = func_8001AAAC_1B6AC(D_8010D940_1915D0_ToadBandstand[i], 0, 0);
            espDispOff(D_8010D990_191620_ToadBandstand[i]);
        } else {
            D_8010D990_191620_ToadBandstand[i] = SprCreate(1, 0);
            SprAnimSet(D_8010D990_191620_ToadBandstand[i], 0, D_8010D940_1915D0_ToadBandstand[i], 0);
            SprAttrReset(D_8010D990_191620_ToadBandstand[i], 0, 0xFFFF);
            SprAttrSet(D_8010D990_191620_ToadBandstand[i], 0, (i != 1 || i != 2) ? 0x9008 : 0x1008);
            SprPrioSet(D_8010D990_191620_ToadBandstand[i], 0, 0x1000 - i);
        }
    }
    SprPosSet(D_8010D990_191620_ToadBandstand[1], 0, 0x5B, 0xC8);
    SprPosSet(D_8010D990_191620_ToadBandstand[2], 0, 0xE5, 0xC8);
    func_80082488_83088(D_8010D990_191620_ToadBandstand[1], 0, 0xE0);
    func_80082488_83088(D_8010D990_191620_ToadBandstand[2], 0, 0xE0);
    for (i = 0; i < 4; i++) {
        SprAttrReset(D_8010D990_191620_ToadBandstand[9 + D_8010D848_1914D8_ToadBandstand[D_8010DAA2_191732_ToadBandstand[i]]->character], 0, 0xFFFF);
        SprAttrSet(D_8010D990_191620_ToadBandstand[9 + D_8010D848_1914D8_ToadBandstand[D_8010DAA2_191732_ToadBandstand[i]]->character], 0, 0x1008);
        SprPosSet(D_8010D990_191620_ToadBandstand[9 + D_8010D848_1914D8_ToadBandstand[D_8010DAA2_191732_ToadBandstand[i]]->character], 0, i >= 2 ? 0xAC : 0x22, (s16)(i % 2) * 0x17 + 0xBC);
        func_80082488_83088(D_8010D990_191620_ToadBandstand[9 + D_8010D848_1914D8_ToadBandstand[D_8010DAA2_191732_ToadBandstand[i]]->character], 0, 0);
    }
    obj->model[1] = LoadFormFile(0x80031, 0x4B9);
    HmfModelObjAttrSet(obj->model[1], 0x600, 0x400);
    func_80029714_2A314(obj->model[1], 0.0f, 120.0f, 135.0f);
    func_800297E8_2A3E8(obj->model[1], 0.85f, 0.85f, 0.85f);
    func_8002979C_2A39C(obj->model[1], 2.5f, 180.0f, 0.0f);
    obj->model[16] = LoadFormFile(0x80032, 0x4BD);
    obj->model[17] = LoadFormFile(0x80033, 0x4BD);
    obj->model[18] = LoadFormFile(0x80034, 0x4BD);
    obj->model[9] = LoadFormFile(0x280010, 0x4A9);
    HmfModelObjAttrSet(obj->model[9], 0x600, 0x400);
    func_800298A4_2A4A4(obj->model[9], 0x4000, 0x4000);
    func_8002C628_2D228(obj->model[9], obj->model[1], (char*)D_8010D17C_190E0C_ToadBandstand);
    func_80029B80_2A780(D_8010DA68_1916F8_ToadBandstand->model[1], D_8010DA68_1916F8_ToadBandstand->model[16]);
    func_80029E80_2AA80(D_8010DA68_1916F8_ToadBandstand->model[1], 2, 2);
    func_80029C74_2A874(D_8010DA68_1916F8_ToadBandstand->model[1], 80.0f);
    obj->model[19] = LoadFormFile(0xD, 0x889);
    func_80029714_2A314(obj->model[19], 2.5f, 110.0f, 100.0f);
    func_800297E8_2A3E8(obj->model[19], 0.75f, 0.75f, 0.75f);
    obj->model[0] = LoadFormFile(0x280002, 0x4B9);
    HmfModelObjAttrSet(obj->model[0], 0x600, 0x400);
    obj->model[2] = LoadFormFile(0x280000, 0x4D9);
    HmfModelObjAttrSet(obj->model[2], 0x600, 0x400);
    func_80029714_2A314(obj->model[2], -300.0f, 170.0f, 0.0f);
    func_80029E80_2AA80(obj->model[2], 1, 1);
    obj->model[3] = LoadFormFile(0x280001, 0x4D9);
    HmfModelObjAttrSet(obj->model[3], 0x600, 0x400);
    func_80029714_2A314(obj->model[3], 300.0f, 170.0f, 0.0f);
    func_80029E80_2AA80(obj->model[3], 1, 1);
    obj->model[4] = LoadFormFile(0x280003, 0x4D9);
    HmfModelObjAttrSet(obj->model[4], 0x600, 0x400);
    func_80029714_2A314(obj->model[4], -320.0f, 210.0f, 50.0f);
    func_80029E80_2AA80(obj->model[4], 1, 1);
    obj->model[5] = LoadFormFile(0x280004, 0x4D9);
    HmfModelObjAttrSet(obj->model[5], 0x600, 0x400);
    func_80029714_2A314(obj->model[5], 320.0f, 210.0f, 50.0f);
    func_80029E80_2AA80(obj->model[5], 1, 1);
    obj->model[10] = LoadFormFile(0x28000F, 0x4D9);
    obj->model[11] = LoadFormFile(0x28000E, 0x4D9);
    obj->model[12] = func_80027D3C_2893C(obj->model[11]);
    obj->model[13] = func_80027D3C_2893C(obj->model[10]);
    obj->model[14] = func_80027D3C_2893C(obj->model[11]);
    obj->model[15] = func_80027D3C_2893C(obj->model[11]);
    for (i = 0; i < 6; i++) {
        func_800298A4_2A4A4(obj->model[10 + i], 4, 0);
    }
    obj->model[6] = LoadFormFile(0x280005, 0x4AD);
    HmfModelObjAttrSet(obj->model[6], 0x600, 0);
    func_80029714_2A314(obj->model[6], -162.5f, 282.5f, 190.0f);
    func_8002D124_2DD24(obj->model[6]);
    obj->model[7] = LoadFormFile(0x280006, 0x4BD);
    HmfModelObjAttrSet(obj->model[7], 0x600, 0x400);
    func_80029714_2A314(obj->model[7], -100.0f, 230.0f, 145.0f);
    obj->model[8] = LoadFormFile(0x280007, 0x4BD);
    HmfModelObjAttrSet(obj->model[8], 0x600, 0x400);
    func_80029714_2A314(obj->model[8], 100.0f, 230.0f, 145.0f);
    obj->func_ptr = func_80105CB8_189948_ToadBandstand;
}

__asm__(".section .rodata");
const char D_8010D17C_190E0C_ToadBandstand[] = "item_hook";

/* NON_MATCHING: register allocation (masked 0, raw 60): the u8 counter i and the hoisted
   D_8010DA88 base swap s1/s2 in the i loops, and one f0/f2 temp in case 0's loop. Fixed: the
   store-flag (`b % 2 == 0`) and the first-segment float (`u`, not `t`); tried i declared before b. */
#ifdef NON_MATCHING
void func_80105CB8_189948_ToadBandstand(omObjData* obj) {
    TSFloats4 xs;
    s8 b;
    u8 i;
    f32 t;
    f32 u;
    f32 scale;
    f64 d;
    u32 limit;
    f32 a;
    f32 c;
    f32 g;
    f32 h;
    f32 cs;
    f64 p;
    s32 k;

    switch (D_8010D8FC_19158C_ToadBandstand) {
    case 0:
        if (D_8010D980_191610_ToadBandstand == 1) {
            for (i = 0; i < 4; i++) {
                func_800298A4_2A4A4(D_8010DA88_191718_ToadBandstand[i]->model[0], 4, 4);
                func_800298A4_2A4A4(D_8010DA88_191718_ToadBandstand[i]->model[11], 4, 4);
            }
        }
        if (D_8010D980_191610_ToadBandstand <= 90) {
            u = D_8010D980_191610_ToadBandstand / 90.0f;
        } else if (!(D_8010D980_191610_ToadBandstand >= 91 && D_8010D980_191610_ToadBandstand <= 120)) {
            if (D_8010D980_191610_ToadBandstand >= 121 && D_8010D980_191610_ToadBandstand <= 150) {
                u = (D_8010D980_191610_ToadBandstand - 0x78) / 30.0f + 1.0;
            } else {
                u = 2.0f;
            }
        } else {
            u = 1.0f;
        }
        D_8010D900_191590_ToadBandstand = u;
        if (D_8010D900_191590_ToadBandstand < 1.0) {
            for (i = 0; i < 6; i++) {
                d = D_8010D900_191590_ToadBandstand;
                if ((i != 5) ? (i / 9.0 <= d) : (0.5 <= d)) {
                    d = D_8010D900_191590_ToadBandstand;
                    if (i != 5) {
                        t = (d - i / 9.0) / 0.1111111111111111;
                    } else {
                        t = (d - 0.5) / 0.1111111111111111;
                    }
                } else {
                    t = 0.0f;
                }
                t = t * 0.25 + (t * t) * 0.75;
                if (t > 35.0) {
                    func_800298A4_2A4A4(obj->model[10 + i], 4, 4);
                } else {
                    u = t > 40.0 ? 40.0f : t;
                    p = u;
                    scale = p * 0.0625 + 0.875;
                    scale = scale * (1.0 - (k = i) * 0.0625);
                    func_80029714_2A314(obj->model[10 + k], D_8010CC7C_19090C_ToadBandstand[k] * (p * 0.5 + 1.0), D_8010CC94_190924_ToadBandstand[k] + (80.0 - k * 7.5) * (p * 0.0), D_8010CCAC_19093C_ToadBandstand[k]);
                    func_800297E8_2A3E8(obj->model[10 + k], D_8010CCC4_190954_ToadBandstand[k] * 1.125 * scale, scale * D_8010CCC4_190954_ToadBandstand[k], scale * D_8010CCC4_190954_ToadBandstand[k]);
                }
            }
        }
        if (D_8010D900_191590_ToadBandstand > 1.0 && D_8010D900_191590_ToadBandstand <= 1.5) {
            func_8002979C_2A39C(obj->model[1], 5.0 - (D_8010D900_191590_ToadBandstand - 1.0) * 10.0, 180.0f, 0.0f);
        }
        limit = D_8010CC04_190894_ToadBandstand[0] - 20;
        if ((u32)D_8010D980_191610_ToadBandstand >= limit) {
            if ((u32)D_8010DA6C_1916FC_ToadBandstand < limit) {
                for (i = 0; i < 6; i++) {
                    func_800298A4_2A4A4(obj->model[10 + i], 4, 4);
                }
                for (i = 0; i < 2; i++) {
                    func_800298A4_2A4A4(obj->model[7 + i], 4, 0);
                    func_80029C74_2A874(D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[i * 2]]->model[7], 20.0f);
                }
                for (i = 0; i < 4; i++) {
                    func_800298A4_2A4A4(D_8010DA88_191718_ToadBandstand[i]->model[0], 4, 0);
                    func_800298A4_2A4A4(D_8010DA88_191718_ToadBandstand[i]->model[11], 4, 0);
                    func_800298A4_2A4A4(D_8010DA88_191718_ToadBandstand[i]->model[12], 4, 0);
                    func_80029C74_2A874(D_8010DA88_191718_ToadBandstand[i]->model[0], 20.0f);
                }
            }
            if ((u32)D_8010D980_191610_ToadBandstand >= D_8010CC04_190894_ToadBandstand[0] - 20) {
                func_8002979C_2A39C(obj->model[1], D_8010D900_191590_ToadBandstand <= 1.5 ? 10.0 - (D_8010D900_191590_ToadBandstand - 1.0) * 20.0 : 0.0f, 180.0 - (u32)(k = D_8010D980_191610_ToadBandstand + 20, k - D_8010CC04_190894_ToadBandstand[0]) * 9.0, 0.0f);
            }
        }
        break;
    case 1:
        D_8010D900_191590_ToadBandstand = 2.0f;
        if (D_8010D980_191610_ToadBandstand < D_8010DA6C_1916FC_ToadBandstand) {
            func_80029B80_2A780(D_8010DA68_1916F8_ToadBandstand->model[1], D_8010DA68_1916F8_ToadBandstand->model[17]);
            func_80029E80_2AA80(D_8010DA68_1916F8_ToadBandstand->model[1], 3, 0);
            func_8002979C_2A39C(obj->model[1], 0.0f, 0.0f, 0.0f);
        }
        if (D_8010D980_191610_ToadBandstand == 0) {
            func_80029C74_2A874(D_8010DA68_1916F8_ToadBandstand->model[1], 0.0f);
        }
        break;
    case 2:
        if (D_8010D980_191610_ToadBandstand < D_8010DA6C_1916FC_ToadBandstand) {
            func_80029B80_2A780(D_8010DA68_1916F8_ToadBandstand->model[1], D_8010DA68_1916F8_ToadBandstand->model[18]);
        }
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        for (b = 0; b < 13; b++) {
            if (D_8010D988_191618_ToadBandstand >= D_8010D920_1915B0_ToadBandstand[b] && (f32)D_8010D988_191618_ToadBandstand <= (f32)D_8010D920_1915B0_ToadBandstand[b] + D_8010CB7C_19080C_ToadBandstand[D_8010DA40_1916D0_ToadBandstand]) {
                if (b != 0) {
                    g = -20.0f;
                    if (b & 1) {
                        g = 35.0f;
                    }
                } else {
                    g = 0.0f;
                }
                if (b != 12) {
                    h = 35.0f;
                    if (b & 1) {
                        h = -20.0f;
                    }
                } else {
                    h = 0.0f;
                }
                cs = func_800B7890_B8490((f32)(D_8010D988_191618_ToadBandstand - D_8010D920_1915B0_ToadBandstand[b]) / D_8010CB7C_19080C_ToadBandstand[D_8010DA40_1916D0_ToadBandstand] * 180.0) * -0.5 + 0.5;
                func_8002979C_2A39C(obj->model[1], 0.0f, g * (1.0 - cs) + h * cs, 0.0f);
            }
            if (D_8010D988_191618_ToadBandstand == D_8010D920_1915B0_ToadBandstand[b]) {
                if (b % 2 == 1 || b == 12) {
                    func_80029E80_2AA80(D_8010DA68_1916F8_ToadBandstand->model[2], 3, 1);
                } else {
                    func_80029E80_2AA80(D_8010DA68_1916F8_ToadBandstand->model[2], 3, 2);
                }
                if (b % 2 == 0 || b == 12) {
                    func_80029E80_2AA80(D_8010DA68_1916F8_ToadBandstand->model[3], 3, 1);
                } else {
                    func_80029E80_2AA80(D_8010DA68_1916F8_ToadBandstand->model[3], 3, 2);
                }
            }
            if (D_8010D988_191618_ToadBandstand >= D_8010D920_1915B0_ToadBandstand[b] && (f64)D_8010D988_191618_ToadBandstand <= D_8010D920_1915B0_ToadBandstand[b] + 15.0) {
                a = 0.0f;
                xs = D_8010CFC4_190C54_ToadBandstand;
                c = 0.0f;
                if (b == 2) {
                    c = (D_8010D988_191618_ToadBandstand - D_8010D920_1915B0_ToadBandstand[b]) / 15.0;
                } else if (b == 12) {
                    a = 1.0 - (D_8010D988_191618_ToadBandstand - D_8010D920_1915B0_ToadBandstand[b]) / 15.0;
                } else if (!(b & 3) && b > 0) {
                    a = 1.0 - (D_8010D988_191618_ToadBandstand - D_8010D920_1915B0_ToadBandstand[b]) / 15.0;
                } else if (b % 4 == 2) {
                    c = (D_8010D988_191618_ToadBandstand - D_8010D920_1915B0_ToadBandstand[b]) / 15.0;
                } else if (b % 4 == 3) {
                    d = (D_8010D988_191618_ToadBandstand - D_8010D920_1915B0_ToadBandstand[b]) / 15.0;
                    c = 1.0 - d;
                    a = d;
                }
                func_80029C74_2A874(D_8010DA68_1916F8_ToadBandstand->model[4], c * 30.0);
                omSetTra(D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[0]], xs.v[0] - TS_ARC(c) * 13.0, c * 22.0 + 255.0, 140.0f);
                func_80029714_2A314(D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[0]]->model[7], xs.v[0] - TS_ARC(c) * 13.0, c * 22.0 + 255.0, 140.0f);
                func_80029714_2A314(D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[0]]->model[12], xs.v[0] - TS_ARC(c) * 13.0, (c * 22.0 + 255.0) - (D_8010D848_1914D8_ToadBandstand[D_8010DAA2_191732_ToadBandstand[0]]->character == 2 ? 5.0 : 0.0), 140.0f);
                omSetTra(D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[1]], xs.v[1] - TS_ARC(c) * 13.0, c * 22.0 + 255.0, 140.0f);
                func_80029714_2A314(D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[1]]->model[12], xs.v[1] + 7.5 - TS_ARC(c) * 13.0, (c * 22.0 + 255.0) - (D_8010D848_1914D8_ToadBandstand[D_8010DAA2_191732_ToadBandstand[1]]->character == 2 ? 5.0 : 0.0), D_8010D848_1914D8_ToadBandstand[D_8010DAA2_191732_ToadBandstand[1]]->character == 5 ? 122.5f : 140.0f);
                func_80029714_2A314(D_8010DA68_1916F8_ToadBandstand->model[7], -100.0 - TS_ARC(c) * 13.0, c * 22.0 + 230.0, 145.0f);
                func_80029C74_2A874(D_8010DA68_1916F8_ToadBandstand->model[5], a * 30.0);
                omSetTra(D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[2]], xs.v[2] + TS_ARC(a) * 13.0, a * 22.0 + 255.0, 140.0f);
                func_80029714_2A314(D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[2]]->model[7], xs.v[2] + TS_ARC(a) * 13.0, a * 22.0 + 255.0, 140.0f);
                func_80029714_2A314(D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[2]]->model[12], xs.v[2] + TS_ARC(a) * 13.0, (a * 22.0 + 255.0) - (D_8010D848_1914D8_ToadBandstand[D_8010DAA2_191732_ToadBandstand[2]]->character == 2 ? 5.0 : 0.0), 140.0f);
                omSetTra(D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[3]], xs.v[3] + TS_ARC(a) * 13.0, a * 22.0 + 255.0, 140.0f);
                func_80029714_2A314(D_8010DA88_191718_ToadBandstand[D_8010DAA2_191732_ToadBandstand[3]]->model[12], xs.v[3] + 7.5 + TS_ARC(a) * 13.0, (a * 22.0 + 255.0) - (D_8010D848_1914D8_ToadBandstand[D_8010DAA2_191732_ToadBandstand[3]]->character == 2 ? 5.0 : 0.0), D_8010D848_1914D8_ToadBandstand[D_8010DAA2_191732_ToadBandstand[3]]->character == 5 ? 122.5f : 140.0f);
                func_80029714_2A314(D_8010DA68_1916F8_ToadBandstand->model[8], TS_ARC(a) * 13.0 + 100.0, a * 22.0 + 230.0, 145.0f);
            }
        }
        break;
    case 10:
        if (D_8010D980_191610_ToadBandstand < D_8010DA6C_1916FC_ToadBandstand) {
            func_80029B80_2A780(D_8010DA68_1916F8_ToadBandstand->model[1], D_8010DA68_1916F8_ToadBandstand->model[17]);
        }
        if (D_8010D980_191610_ToadBandstand < 20) {
            func_80029C74_2A874(D_8010DA68_1916F8_ToadBandstand->model[1], 0x4E - D_8010D980_191610_ToadBandstand * 2);
        }
        if (D_8010D980_191610_ToadBandstand == 20) {
            func_80029C74_2A874(D_8010DA68_1916F8_ToadBandstand->model[1], 0.0f);
        }
        if (D_8010D980_191610_ToadBandstand == 40) {
            func_80029B80_2A780(D_8010DA68_1916F8_ToadBandstand->model[1], D_8010DA68_1916F8_ToadBandstand->model[16]);
            func_80029E80_2AA80(D_8010DA68_1916F8_ToadBandstand->model[1], 3, 2);
        }
        break;
    }
    func_8010B710_18F3A0_ToadBandstand(D_8010D990_191620_ToadBandstand[0], 0.0f, 0.0f, 1.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_18_ToadBandstand/186490", func_80105CB8_189948_ToadBandstand);
#endif

__asm__(".section .rodata");
const char D_8010D290_190F20_ToadBandstand[] = "@*";

__asm__(".section .rodata");
const char D_8010D294_190F24_ToadBandstand[] = "";

__asm__(".section .rodata");
const char D_8010D298_190F28_ToadBandstand[] = "@6";

__asm__(".section .rodata");
const char D_8010D29C_190F2C_ToadBandstand[] = "";

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010D2A0_190F30_ToadBandstand[2] = { 0x40668000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010D2A8_190F38_ToadBandstand[2] = { 0xBFE00000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010D2B0_190F40_ToadBandstand[2] = { 0x3FF00000, 0x00000000 };

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_8010D2B8_190F48_ToadBandstand[8] = "@.";

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_8010D2C0_190F50_ToadBandstand[8] = "@.";

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010D2C8_190F58_ToadBandstand[2] = { 0x3FF00000, 0x00000000 };

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_8010D2D0_190F60_ToadBandstand[8] = "@.";

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_8010D2D8_190F68_ToadBandstand[8] = "@.";

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010D2E0_190F70_ToadBandstand[2] = { 0x3FF00000, 0x00000000 };

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_8010D2E8_190F78_ToadBandstand[8] = "@>";

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010D2F0_190F80_ToadBandstand[2] = { 0x406FE000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010D2F8_190F88_ToadBandstand[2] = { 0x40140000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010D300_190F90_ToadBandstand[2] = { 0x406FE000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010D308_190F98_ToadBandstand[2] = { 0x401E0000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010D310_190FA0_ToadBandstand[2] = { 0x40140000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010D318_190FA8_ToadBandstand[2] = { 0xC0590000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010D320_190FB0_ToadBandstand[2] = { 0x406CC000, 0x00000000 };

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_8010D328_190FB8_ToadBandstand[8] = "@>";

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010D330_190FC0_ToadBandstand[2] = { 0x406FE000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010D338_190FC8_ToadBandstand[2] = { 0x40140000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010D340_190FD0_ToadBandstand[2] = { 0x406FE000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010D348_190FD8_ToadBandstand[2] = { 0x401E0000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010D350_190FE0_ToadBandstand[2] = { 0x40140000, 0x00000000 };

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_8010D358_190FE8_ToadBandstand[8] = "@Y";

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010D360_190FF0_ToadBandstand[2] = { 0x406CC000, 0x00000000 };

void func_801070F8_18AD88_ToadBandstand(omObjData* obj) {
    func_801071C8_18AE58_ToadBandstand(obj, 0);
    obj->func_ptr = func_801077B8_18B448_ToadBandstand;
}

void func_8010712C_18ADBC_ToadBandstand(omObjData* obj) {
    func_801071C8_18AE58_ToadBandstand(obj, 1);
    obj->func_ptr = func_801077D4_18B464_ToadBandstand;
}

void func_80107160_18ADF0_ToadBandstand(omObjData* obj) {
    func_801071C8_18AE58_ToadBandstand(obj, 2);
    obj->func_ptr = func_801077F0_18B480_ToadBandstand;
}

void func_80107194_18AE24_ToadBandstand(omObjData* obj) {
    func_801071C8_18AE58_ToadBandstand(obj, 3);
    obj->func_ptr = func_8010780C_18B49C_ToadBandstand;
}

/* NON_MATCHING: class 4: retail keeps i (dies into pp) and its copy j in separate registers; GCC coalesces
   them (masked 26 with every later index through (s8)j; s8 j no change) */
#ifdef NON_MATCHING
void func_801071C8_18AE58_ToadBandstand(omObjData* obj, s32 i) {
    s32 j = i;
    TSFloats4 xs = D_8010CFC4_190C54_ToadBandstand;
    TSPlayer** pp;
    TSPlayer* p;
    s32 dir;
    s32 file;
    s8 group;

    pp = &D_8010D848_1914D8_ToadBandstand[(s8)i];
    dir = D_800CD438_CE038[(u16)(*pp)->character].dir;
    obj->model[0] = LoadFormFile(dir | 0xD2, 0x4A9);
    HmfModelObjAttrSet(obj->model[0], 0x600, 0x400);
    func_80029E80_2AA80(obj->model[0], 2, 2);
    omSetTra(obj, xs.v[(*pp)->group], 255.0f, 140.0f);
    omSetSca(obj, 0.75f, 0.75f, 0.75f);
    obj->model[1] = LoadFormFile(dir, 0x49D);
    func_80029E80_2AA80(obj->model[1], 2, 2);
    file = dir | 0xA9;
    if (!((*pp)->group & 1)) {
        file = dir | 0xA6;
    }
    obj->model[2] = LoadFormFile(file, 0x49D);
    func_80029B80_2A780(obj->model[0], obj->model[2]);
    func_80029E80_2AA80(obj->model[0], 2, 2);
    file = dir | 0xAA;
    if (!(D_8010D848_1914D8_ToadBandstand[(s8)j]->group & 1)) {
        file = dir | 0xA7;
    }
    obj->model[3] = LoadFormFile(file, 0x49D);
    file = dir | 0xAB;
    if (!(D_8010D848_1914D8_ToadBandstand[(s8)j]->group & 1)) {
        file = dir | 0xA8;
    }
    obj->model[4] = LoadFormFile(file, 0x49D);
    file = dir | 0x4F;
    if (!(D_8010D904_191594_ToadBandstand & 1)) {
        file = dir | 0x4E;
    }
    obj->model[5] = LoadFormFile(file, 0x49D);
    obj->model[6] = LoadFormFile(dir | 0x59, 0x49D);
    obj->model[12] = LoadFormFile(0xD, 0x88D);
    group = D_8010D848_1914D8_ToadBandstand[(s8)j]->group;
    func_80029714_2A314(obj->model[12],
                        xs.v[group] + (group % 2 == 1 ? 7.5 : 0.0),
                        D_8010D848_1914D8_ToadBandstand[D_8010DAA2_191732_ToadBandstand[(s8)j]]->character == 2 ? 250.0f : 255.0f,
                        140.0 - (((p = D_8010D848_1914D8_ToadBandstand[(s8)j])->group % 2 == 1 && p->character == 5) * 17.5));
    func_800297E8_2A3E8(obj->model[12], 0.75f, 0.75f, 0.75f);
    p = D_8010D848_1914D8_ToadBandstand[(s8)j];
    if (p->group & 1) {
        file = p->group < 2 ? 0x28000C : 0x28000D;
    } else {
        file = 0x28000B;
    }
    obj->model[11] = LoadFormFile(file, 0x4A9);
    HmfModelObjAttrSet(obj->model[11], 0x600, 0x400);
    func_800298A4_2A4A4(obj->model[11], 0x4000, 0x4000);
    func_8002C628_2D228(obj->model[11], obj->model[0], (char*)D_8010D17C_190E0C_ToadBandstand);
    pp = &D_8010D848_1914D8_ToadBandstand[(s8)j];
    if (!((*pp)->group & 1)) {
        obj->model[7] = LoadFormFile(0x280008, 0x4A9);
        HmfModelObjAttrSet(obj->model[7], 0x600, 0x400);
        func_80029E80_2AA80(obj->model[7], 2, 2);
        func_80029714_2A314(obj->model[7], xs.v[(*pp)->group], 255.0f, 140.0f);
        func_800297E8_2A3E8(obj->model[7], 0.75f, 0.75f, 0.75f);
        obj->model[8] = LoadFormFile(0x280008, 0x4BD);
        obj->model[9] = LoadFormFile(0x280009, 0x4BD);
        obj->model[10] = LoadFormFile(0x28000A, 0x4BD);
        func_80029B80_2A780(obj->model[7], obj->model[8]);
        func_80029E80_2AA80(obj->model[7], 2, 2);
    }
    obj->model[13] = LoadFormFile(0x280011, 0x4AD);
    func_8002D124_2DD24(obj->model[13]);
    func_800297E8_2A3E8(obj->model[13], 0.75f, 0.75f, 0.75f);
    obj->model[14] = LoadFormFile(0x280011, 0x4AD);
    func_8002D124_2DD24(obj->model[14]);
    func_800297E8_2A3E8(obj->model[14], 0.75f, 0.75f, 0.75f);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_18_ToadBandstand/186490", func_801071C8_18AE58_ToadBandstand);
#endif

void func_801077B8_18B448_ToadBandstand(omObjData* obj) {
    func_80107828_18B4B8_ToadBandstand(obj, 0);
}

void func_801077D4_18B464_ToadBandstand(omObjData* obj) {
    func_80107828_18B4B8_ToadBandstand(obj, 1);
}

void func_801077F0_18B480_ToadBandstand(omObjData* obj) {
    func_80107828_18B4B8_ToadBandstand(obj, 2);
}

void func_8010780C_18B49C_ToadBandstand(omObjData* obj) {
    func_80107828_18B4B8_ToadBandstand(obj, 3);
}

__asm__(".section .rodata");
const u32 D_8010D380_191010_ToadBandstand[2] = { 0xFFFEFFFE, 0xFFFEFFFE };

__asm__(".section .rodata");
const u32 D_8010D388_191018_ToadBandstand[2] = { 0 };

__asm__(".section .rodata");
const u32 D_8010D390_191020_ToadBandstand[6] = { 0xC1200000, 0x00000000, 0x40200000, 0xC0200000, 0xC0200000, 0x40A00000 };

__asm__(".section .rodata");
const u32 D_8010D3A8_191038_ToadBandstand[2] = { 0x00380028, 0x00480058 };

/* NON_MATCHING: class 3/4: same calls and stores, but GCC cross-jumps the two c[i]++ (retail keeps both, recomputing the address after the call; 1 sh fewer); loop hoisting, stack slots and one dead conversion differ */
#ifdef NON_MATCHING
void func_80107828_18B4B8_ToadBandstand(omObjData* obj, s8 idx) {
    s16 hit[4] = { -2, -2, -2, -2 };
    s16 press[4] = { 0, 0, 0, 0 };
    TSPans pans;
    s16 i;
    s16 j;
    s16 n;
    u8 b;
    s32 base;
    s32 t;
    f32 f;
    f32 w;
    f64 half;
    f32 frac;
    f32 q;
    f32* wp;
    TSPlayer* pl;
    TSPlayer* p;
    s16* c;
    s16* star;
    f32* sx;
    f32* sv;
    f32* sy;
    u16* sr;
    f32 a;
    f32 r;
    f32 x;
    f64 z;
    s32 alpha;
    s16 snd;

    wp = &D_8010CB7C_19080C_ToadBandstand[D_8010DA40_1916D0_ToadBandstand];
    for (i = 0; i < 4; i++) {
        pl = D_8010D848_1914D8_ToadBandstand[i];
        if (pl->cpu == -1) {
            press[i] = ContBtnTrg[pl->port] >> 15;
        } else {
            f = D_8010D980_191610_ToadBandstand / *wp + 0.5;
            if (D_8010D8FC_19158C_ToadBandstand == 4 || D_8010D8FC_19158C_ToadBandstand == 6 || D_8010D8FC_19158C_ToadBandstand == 8) {
                if (D_8010D8FC_19158C_ToadBandstand != 4) {
                    base = D_8010D8FC_19158C_ToadBandstand == 8 ? 24 : 0;
                    if (D_8010D8FC_19158C_ToadBandstand == 6) {
                        base = 12;
                    }
                } else {
                    base = 0;
                }
                n = f;
                if (n < 12) {
                    pl = D_8010D848_1914D8_ToadBandstand[i];
                    if (pl->press[n + base] != 0) {
                        w = *wp;
                        half = w / 2.0;
                        if (pl->timing[n + base] <= (f - n) * w - half) {
                            f = (D_8010D980_191610_ToadBandstand - 1) / w + 0.5;
                            n = f;
                            if ((f - n) * w - half < pl->timing[n + base]) {
                                press[i] = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    if (idx == 0) {
        if (D_8010D8FC_19158C_ToadBandstand == 4 || D_8010D8FC_19158C_ToadBandstand == 6 || D_8010D8FC_19158C_ToadBandstand == 8) {
            for (i = 0; i < 2; i++) {
                for (j = 0; j < 36; j++) {
                    b = D_8010D9C0_191650_ToadBandstand[i][j];
                    if (b != 0 && D_8010D890_191520_ToadBandstand[i][b - 1] - D_8010CB7C_19080C_ToadBandstand[D_8010DA40_1916D0_ToadBandstand] / 2.0 < D_8010D988_191618_ToadBandstand) {
                        hit[0] = hit[1] = hit[2] = hit[3] = j;
                    }
                }
            }
            for (i = 0; i < 2; i++) {
                for (j = 0; j < 36; j++) {
                    p = D_8010D848_1914D8_ToadBandstand[(s16)(j % 12) >= 6 ? D_8010DAA2_191732_ToadBandstand[i + 2] : D_8010DAA2_191732_ToadBandstand[i]];
                    b = D_8010D9C0_191650_ToadBandstand[i][j];
                    if (b != 0) {
                        t = D_8010D890_191520_ToadBandstand[i][b - 1];
                        if (D_8010D988_191618_ToadBandstand >= t - 4 && t + 4 >= D_8010D988_191618_ToadBandstand) {
                            hit[p->id] = -1;
                            if (j != D_8010DA98_191728_ToadBandstand[p->group]) {
                                if (press[p->id] != 0) {
                                    hit[p->id] = -1;
                                    D_8010DA42_1916D2_ToadBandstand[p->group / 2]++;
                                    D_8010DA98_191728_ToadBandstand[p->group] = j;
                                    D_8010D908_191598_ToadBandstand[p->group] = 0;
                                    D_8010DAAD_19173D_ToadBandstand[p->group] = 1;
                                    D_8010D878_191508_ToadBandstand[p->id] = D_8010D9BC_19164C_ToadBandstand;
                                    func_80029E80_2AA80(D_8010DA88_191718_ToadBandstand[p->id]->model[0], 3, 1);
                                    func_80029BF0_2A7F0(D_8010DA88_191718_ToadBandstand[p->id]->model[0], func_80029E14_2AA14(D_8010DA88_191718_ToadBandstand[p->id]->model[3]), 0, D_8010CB7C_19080C_ToadBandstand[D_8010DA40_1916D0_ToadBandstand] - 2.0, 2);
                                    if (D_8010CA50_1906E0_ToadBandstand[i][j] != 0) {
                                        pans = D_8010CFBC_190C4C_ToadBandstand;
                                        snd = func_80079798_7A398(D_8010CA50_1906E0_ToadBandstand[i][j], p->group);
                                        func_800798F8_7A4F8(snd, pans.v[p->group]);
                                        if (D_8010DA40_1916D0_ToadBandstand == 1 && i == 1 && j == 21) {
                                            func_800796F0_7A2F0(snd, -0xCD);
                                        }
                                    }
                                    if (!(p->group & 1)) {
                                        func_80029E80_2AA80(D_8010DA88_191718_ToadBandstand[p->id]->model[7], 3, 1);
                                        func_80029BF0_2A7F0(D_8010DA88_191718_ToadBandstand[p->id]->model[7], func_80029E14_2AA14(D_8010DA88_191718_ToadBandstand[p->id]->model[9]), 0, D_8010CB7C_19080C_ToadBandstand[D_8010DA40_1916D0_ToadBandstand] - 2.0, 2);
                                    }
                                }
                            } else if (press[p->id] != 0) {
                                hit[p->id] = -1;
                            }
                        } else {
                            t = D_8010D890_191520_ToadBandstand[i][D_8010D9C0_191650_ToadBandstand[i][j] - 1];
                            if (D_8010D9B0_191640_ToadBandstand >= t - 4 && t + 4 >= D_8010D9B0_191640_ToadBandstand) {
                                if (j != D_8010DA98_191728_ToadBandstand[p->group]) {
                                    /* the beat passed unplayed */
                                    D_8010DAA8_191738_ToadBandstand[p->group / 2]--;
                                    if (p->cpu == -1) {
                                        omVibrate(p->id, 10, 0, 10);
                                    }
                                    star = &D_8010CA40_1906D0_ToadBandstand[p->id][0];
                                    if (D_8010CA40_1906D0_ToadBandstand[p->id][0] < D_8010CA40_1906D0_ToadBandstand[p->id][1]) {
                                        star++;
                                    }
                                    *star = 0;
                                    D_8010D868_1914F8_ToadBandstand[p->id] = D_8010D9BC_19164C_ToadBandstand;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (idx == 0 && ((D_8010D988_191618_ToadBandstand >= D_8010DA28_1916B8_ToadBandstand[0][0] && D_8010DA28_1916B8_ToadBandstand[1][1] >= D_8010D988_191618_ToadBandstand)
                         || (D_8010D988_191618_ToadBandstand >= D_8010DA28_1916B8_ToadBandstand[0][2] && D_8010DA28_1916B8_ToadBandstand[1][3] >= D_8010D988_191618_ToadBandstand)
                         || (D_8010D988_191618_ToadBandstand >= D_8010DA28_1916B8_ToadBandstand[0][4] && D_8010DA28_1916B8_ToadBandstand[1][5] >= D_8010D988_191618_ToadBandstand))) {
            for (i = 0; i < 4; i++) {
                /* a press with no beat under it */
                if ((f32)(u32)(D_8010D9BC_19164C_ToadBandstand - D_8010D878_191508_ToadBandstand[i]) > 2.0f * D_8010CB7C_19080C_ToadBandstand[D_8010DA40_1916D0_ToadBandstand] / 3.0f + 1.0f
                    && (f32)(u32)(D_8010D9BC_19164C_ToadBandstand - D_8010D868_1914F8_ToadBandstand[i]) > D_8010CB7C_19080C_ToadBandstand[D_8010DA40_1916D0_ToadBandstand] / 2.0f + 1.0f) {
                    if (hit[i] != -1 && press[i] != 0) {
                        func_80029E80_2AA80(D_8010DA88_191718_ToadBandstand[i]->model[0], 3, 1);
                        func_80029BF0_2A7F0(D_8010DA88_191718_ToadBandstand[i]->model[0], func_80029E14_2AA14(D_8010DA88_191718_ToadBandstand[i]->model[4]), 0, D_8010CB7C_19080C_ToadBandstand[D_8010DA40_1916D0_ToadBandstand] - 4.0, 2);
                        if (D_8010D848_1914D8_ToadBandstand[i]->cpu == -1) {
                            omVibrate((s8)i, 10, 0, 10);
                        }
                        star = &D_8010CA40_1906D0_ToadBandstand[i][0];
                        if (D_8010CA40_1906D0_ToadBandstand[i][0] < D_8010CA40_1906D0_ToadBandstand[i][1]) {
                            star++;
                        }
                        *star = 0;
                        if (!(D_8010D848_1914D8_ToadBandstand[i]->group & 1)) {
                            func_80029E80_2AA80(D_8010DA88_191718_ToadBandstand[i]->model[7], 3, 1);
                            func_80029BF0_2A7F0(D_8010DA88_191718_ToadBandstand[i]->model[7], func_80029E14_2AA14(D_8010DA88_191718_ToadBandstand[i]->model[10]), 0, D_8010CB7C_19080C_ToadBandstand[D_8010DA40_1916D0_ToadBandstand] - 2.0, 2);
                        }
                        D_8010DA98_191728_ToadBandstand[D_8010D848_1914D8_ToadBandstand[i]->group] = hit[i];
                        D_8010D908_191598_ToadBandstand[D_8010D848_1914D8_ToadBandstand[i]->group] = 0;
                        D_8010DAAD_19173D_ToadBandstand[D_8010D848_1914D8_ToadBandstand[i]->group] = 2;
                        D_8010D878_191508_ToadBandstand[i] = D_8010D9BC_19164C_ToadBandstand;
                        D_8010DAA8_191738_ToadBandstand[D_8010D848_1914D8_ToadBandstand[i]->group / 2]--;
                    }
                }
            }
        }
    }
    if (D_8010D8FC_19158C_ToadBandstand >= 2 && D_8010D8FC_19158C_ToadBandstand <= 9) {
        p = D_8010D848_1914D8_ToadBandstand[idx];
        q = D_8010CB74_190804_ToadBandstand[D_8010DA40_1916D0_ToadBandstand];
        w = D_8010CB7C_19080C_ToadBandstand[D_8010DA40_1916D0_ToadBandstand];
        frac = (D_8010D988_191618_ToadBandstand / D_8010D888_191518_ToadBandstand + q) / w - (s16)((D_8010D988_191618_ToadBandstand / D_8010D888_191518_ToadBandstand + q) / w);
        if (w / 2.0 <= (u32)(D_8010D9BC_19164C_ToadBandstand - D_8010D878_191508_ToadBandstand[idx]) && (u32)(D_8010DA70_191700_ToadBandstand - D_8010D878_191508_ToadBandstand[idx]) < w / 2.0) {
            D_8010DAAD_19173D_ToadBandstand[D_8010D848_1914D8_ToadBandstand[idx]->group] = 0;
            func_80029E80_2AA80(obj->model[0], 3, 1);
            func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->model[2]), 0, D_8010CB7C_19080C_ToadBandstand[D_8010DA40_1916D0_ToadBandstand] - 2.0, 2);
            if (!(p->group & 1)) {
                func_80029E80_2AA80(obj->model[7], 3, 1);
                func_80029BF0_2A7F0(obj->model[7], func_80029E14_2AA14(obj->model[8]), 0, D_8010CB7C_19080C_ToadBandstand[D_8010DA40_1916D0_ToadBandstand] - 2.0, 2);
            }
        }
        /* the idle bob, and the frame of the step just played */
        if (w / 2.0 <= (u32)(D_8010D9BC_19164C_ToadBandstand - D_8010D878_191508_ToadBandstand[idx])) {
            if (D_800FC834_FD434[obj->model[0]].unk04 == 0xFF) {
                x = frac * 30.0;
                func_80029C74_2A874(obj->model[0], x);
                if (!(p->group & 1)) {
                    func_80029C74_2A874(obj->model[7], x);
                }
            } else {
                x = frac * 30.0;
                func_80102A68_1866F8_ToadBandstand(obj->model[0], x);
                if (!(p->group & 1)) {
                    func_80102A68_1866F8_ToadBandstand(obj->model[7], x);
                }
                func_80029C74_2A874(obj->model[0], (f32)(u32)(D_8010D9BC_19164C_ToadBandstand - D_8010D878_191508_ToadBandstand[idx]) / w * 30.0);
                if (!(p->group & 1)) {
                    func_80029C74_2A874(obj->model[7], (f32)(u32)(D_8010D9BC_19164C_ToadBandstand - D_8010D878_191508_ToadBandstand[idx]) / w * 30.0);
                }
            }
        } else if (D_800FC834_FD434[obj->model[0]].unk04 == 0xFF) {
            func_80029C74_2A874(obj->model[0], (f32)(u32)(D_8010D9BC_19164C_ToadBandstand - D_8010D878_191508_ToadBandstand[idx]) / w * 30.0);
            if (!(p->group & 1)) {
                func_80029C74_2A874(obj->model[7], (f32)(u32)(D_8010D9BC_19164C_ToadBandstand - D_8010D878_191508_ToadBandstand[idx]) / w * 30.0);
            }
        } else {
            func_80102A68_1866F8_ToadBandstand(obj->model[0], (f32)(u32)(D_8010D9BC_19164C_ToadBandstand - D_8010D878_191508_ToadBandstand[idx]) / w * 30.0);
            if (!(p->group & 1)) {
                func_80102A68_1866F8_ToadBandstand(obj->model[7], (f32)(u32)(D_8010D9BC_19164C_ToadBandstand - D_8010D878_191508_ToadBandstand[idx]) / w * 30.0);
            }
            x = frac * 30.0;
            func_80029C74_2A874(obj->model[0], x);
            if (!(p->group & 1)) {
                func_80029C74_2A874(obj->model[7], x);
            }
        }
        if (idx == 0 && D_8010D8FC_19158C_ToadBandstand >= 2 && D_8010D8FC_19158C_ToadBandstand <= 9) {
            func_80029C74_2A874(D_8010DA68_1916F8_ToadBandstand->model[1], frac * 60.0);
        }
        c = D_8010CA40_1906D0_ToadBandstand[idx];
        sx = D_8010DA08_191698_ToadBandstand[idx];
        sv = D_8010DAB8_191748_ToadBandstand[idx];
        sy = D_8010D960_1915F0_ToadBandstand[idx];
        sr = D_8010DA78_191708_ToadBandstand[idx];
        for (i = 0; i < 2; i++) {
            if (c[i] < 18) {
                f32 ox[6] = { -10.0f, 0.0f, 2.5f, -2.5f, -2.5f, 5.0f };

                if (c[i] == 0) {
                    func_800298A4_2A4A4(obj->model[13 + i], 4, 0);
                    sx[i] = D_800FC834_FD434[obj->model[0]].pos.x;
                    sv[i] = 0.0f;
                    sy[i] = D_800FC834_FD434[obj->model[0]].pos.y + 25.0 + ox[p->character] * 1.25;
                    sr[i] = rand8();
                }
                sy[i] += sv[i];
                sv[i] -= c[i] >= 7 ? 5.625 : 7.5;
                if (c[i] == 6) {
                    pans = *(TSPans*)D_8010D3A8_191038_ToadBandstand;
                    func_800798F8_7A4F8(PlaySound(0x1E5), pans.v[p->group]);
                    sv[i] *= -0.375;
                }
                a = (u16)(sr[i] % 360);
                r = ((u16)(sr[i] % 100) / 100.0 * 50.0 + 20.0) * ((c[i] - 6) / 6.0);
                x = HuMathSin(a) * r + sx[i];
                z = func_800B7890_B8490(a) * r * 0.0 + 140.0;
                func_80029714_2A314(obj->model[13 + i], x, sy[i] + 255.0, z - (c[i] >= 7 ? (c[i] - 6) / 12.0 * 50.0 : 0.0));
                alpha = 0xFF;
                if (c[i] >= 12) {
                    alpha = (u32)(255.0 - (c[i] - 11) / 6.0 * 255.0) & 0xFF;
                }
                func_8002D0A0_2DCA0(obj->model[13 + i], alpha);
                c[i]++;
            } else if (c[i] == 18) {
                func_800298A4_2A4A4(obj->model[13 + i], 4, 4);
                c[i]++;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_18_ToadBandstand/186490", func_80107828_18B4B8_ToadBandstand);
#endif

void func_80109344_18CFD4_ToadBandstand(s16 model, s16 frame) {
    HmfModel* m = &D_800FC834_FD434[model];

    m->hmf->unk9C->unk08 = frame;
}

/* NON_MATCHING: class 4: same calls and stores; register allocation and a few cross-jumped arms differ (masked 292, n 2641/2626). The macro arguments stay inline: the macro repeats them and retail shows each copy. S3-S: retail repeats the `j >= 6 ? a + 2 : a` band slot at each DA98/DAAD/D908 access (masked 426 -> 292); DAAD as a pointer select (`*(j >= 6 ? &D[a + 2] : &D[a])`) was worse. */
#ifdef NON_MATCHING
void func_80109388_18D018_ToadBandstand(Gfx** gfx, s32 arg1, s32 arg2) {
    HuSprite* spr[16];
    HuSprite_Unk84_Unk00_Struct* frame[16];
    f32 fade;
    s32 i;
    s32 k;
    u8 a;
    u8 j;
    u8 b;
    u8 ph;
    s32 c;
    s32 id;
    s32 x;
    s32 y;
    s32 st;
    s32 n;
    s32 t0;
    s32 p;
    s32 lo;
    s32 hi;
    f32 scale;
    u16* step;

    if (D_8010D8FC_19158C_ToadBandstand == 1 && (u32)D_8010D980_191610_ToadBandstand <= D_8010CC04_190894_ToadBandstand[1] - 35) {
        fade = 0.0f;
    } else if (D_8010D8FC_19158C_ToadBandstand != 0 && (D_8010D8FC_19158C_ToadBandstand != 9 || (u32)D_8010D980_191610_ToadBandstand < D_8010CC04_190894_ToadBandstand[9] - 5) && D_8010D8FC_19158C_ToadBandstand < 10) {
        if (D_8010D8FC_19158C_ToadBandstand == 1 && (u32)D_8010D980_191610_ToadBandstand >= D_8010CC04_190894_ToadBandstand[1] - 35 && (u32)D_8010D980_191610_ToadBandstand < D_8010CC04_190894_ToadBandstand[1] - 5) {
            fade = (f32)((u32)(D_8010D980_191610_ToadBandstand - D_8010CC04_190894_ToadBandstand[1]) + 35) / 30.0f;
        } else if (D_8010D8FC_19158C_ToadBandstand == 9 && (u32)D_8010D980_191610_ToadBandstand >= D_8010CC04_190894_ToadBandstand[9] - 35 && (u32)D_8010D980_191610_ToadBandstand < D_8010CC04_190894_ToadBandstand[9] - 5) {
            fade = 1.0 - (f32)((u32)(D_8010D980_191610_ToadBandstand - D_8010CC04_190894_ToadBandstand[9]) + 35) / 30.0f;
        } else {
            fade = 1.0f;
        }
    } else {
        fade = 0.0f;
    }
    gSPDisplayList(D_800FDBCC_FE7CC++, D_8010CCE0_190970_ToadBandstand);
    TS_GFX(0xFCFF97FF, 0xFF2CFE7F);
    TS_GFX(0xFA000000, ~0xFF | (u32)(fade * 224.0f));
    if (fade > 0.0) {
        for (i = 0; i < 4; i++) {
            func_80082488_83088(D_8010D990_191620_ToadBandstand[9 + D_8010D848_1914D8_ToadBandstand[D_8010DAA2_191732_ToadBandstand[i]]->character], 0, (u32)(fade * 256.0));
        }
    }
    if (fade > 0.0 && fade < 1.0) {
        TS_GFX(0xE3001801, 0x80);
    }
    TS_GFX(0xF9000000, 0);
    TS_GFX(0xE3001001, 0);
    for (i = 1; i < 3; i++) {
        spr[i] = func_80082550_83150(D_800F93FC_F9FFC[(s16)D_8010D990_191620_ToadBandstand[i]].unk_04, 0);
        frame[i] = &spr[i]->unk_84->unk00[spr[i]->unk_90];
        for (k = 0; k < 8; k++) {
            gDPLoadTextureTile(D_800FDBCC_FE7CC++, frame[i]->unk00, G_IM_FMT_RGBA, G_IM_SIZ_16b, 135, 48, 0, k * 6, 135, k * 6 + 6,
                               0, G_TX_MIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_CLAMP, 0, 0, 0, 0);
            if (fade > 0.0) {
                gSPScisTextureRectangle(D_800FDBCC_FE7CC++, i == 2 ? 162 * 4 : 24 * 4, (s32)((k * 6 + 0xB0) * 4.0), i == 2 ? 297 * 4 : 159 * 4, (s32)((k * 6 + 0xB6) * 4.0),
                                        G_TX_RENDERTILE, 0, k * 6 << 5, 0x400, 0x400);
            }
        }
    }
    TS_GFX(0xE7000000, 0);
    TS_GFX(0xF9000000, 0x80);
    TS_GFX(0xFCFFFFFF, 0xFFFCF279);
    TS_GFX(0xE3001001, 0);
    if (fade > 0.0) {
        TS_GFX(0xE3001801, 0xC0);
    }
    if (D_8010D8FC_19158C_ToadBandstand >= 3 && D_8010D8FC_19158C_ToadBandstand <= 8) {
        if (D_8010D8FC_19158C_ToadBandstand == 3 || D_8010D8FC_19158C_ToadBandstand == 5 || D_8010D8FC_19158C_ToadBandstand == 7) {
            /* the leader's turn: each note pops out on its beat */
            for (a = 0; a < 2; a++) {
                for (j = 0; j < 12; j++) {
                    k = j;
                    if (D_8010D8FC_19158C_ToadBandstand == 5) {
                        k = j + 12;
                    } else if (D_8010D8FC_19158C_ToadBandstand == 7) {
                        k = j + 24;
                    }
                    if ((u8)(j % 6) == 0) {
                        id = a == 0 ? (j < 6 ? 6 : 8) : (j >= 6 ? 7 : 5);
                        spr[id] = func_80082550_83150(D_800F93FC_F9FFC[(s16)D_8010D990_191620_ToadBandstand[id]].unk_04, 0);
                        frame[id] = &spr[id]->unk_84->unk00[spr[id]->unk_90];
                        gDPLoadTextureBlock(D_800FDBCC_FE7CC++, frame[id]->unk00, G_IM_FMT_RGBA, G_IM_SIZ_16b, 12, 16, 0, G_TX_CLAMP,
                                            G_TX_CLAMP, 0, 0, 0, 0);
                    }
                    b = D_8010D9C0_191650_ToadBandstand[a][(u8)k];
                    if (b != 0) {
                        step = &D_8010CB70_190800_ToadBandstand[D_8010DA40_1916D0_ToadBandstand];
                        if (D_8010D988_191618_ToadBandstand >= D_8010D890_191520_ToadBandstand[a][b - 1] - *step) {
                            /* retail reads the three low bytes by their own labels */
                            ph = (u8)D_8010D988_191618_ToadBandstand - ((u8)D_8010D890_191520_ToadBandstand[a][b - 1] - (u8)*step);
#define HX TS_PICK(ph, 10.5, 9.0, 6.0)
#define HY TS_PICK(ph, 14.0, 12.0, 8.0)
#define NX ((j >= 6 ? j * 16 + 0x5E : j * 16 + 0x34) + 8)
#define NY (a * 23 + 0xBC)
                            gSPScisTextureRectangle(D_800FDBCC_FE7CC++, (s32)((NX - HX) * 4.0 + 0.0), (s32)((NY - HY) * 4.0 - 0.0 + 0.0), (s32)((NX + HX) * 4.0 + 0.0), (s32)((NY + HY) * 4.0 + 0.0),
                                                    G_TX_RENDERTILE, ph != 0 ? (ph == 1 ? -0x10 : 0) : -0x14, ph != 0 ? (ph == 1 ? -0x10 : 0) : -0x14, TS_PICK(ph, 0x249, 0x2AB, 0x400), TS_PICK(ph, 0x249, 0x2AB, 0x400));
                        }
                    }
                }
            }
        } else {
            /* the players' turn: the note under the beat just hit swells */
            for (a = 0; a < 2; a++) {
                for (j = 0; j < 12; j++) {
                    k = j;
                    if (D_8010D8FC_19158C_ToadBandstand == 6) {
                        k = j + 12;
                    } else if (D_8010D8FC_19158C_ToadBandstand == 8) {
                        k = j + 24;
                    }
                    if ((u8)(j % 6) == 0) {
                        id = a == 0 ? (j < 6 ? 6 : 8) : (j >= 6 ? 7 : 5);
                        spr[id] = func_80082550_83150(D_800F93FC_F9FFC[(s16)D_8010D990_191620_ToadBandstand[id]].unk_04, 0);
                        frame[id] = &spr[id]->unk_84->unk00[spr[id]->unk_90];
                        gDPLoadTextureBlock(D_800FDBCC_FE7CC++, frame[id]->unk00, G_IM_FMT_RGBA, G_IM_SIZ_16b, 12, 16, 0, G_TX_CLAMP,
                                            G_TX_CLAMP, 0, 0, 0, 0);
                    }
                    if (D_8010D9C0_191650_ToadBandstand[a][(u8)k] != 0) {
                        x = j >= 6 ? j * 16 + 0x5E : j * 16 + 0x34;
                        y = a * 23 + 0xB4;
                        scale = 1.0f;
                        if (D_8010DA98_191728_ToadBandstand[j >= 6 ? a + 2 : a] == (u8)k && D_8010DAAD_19173D_ToadBandstand[j >= 6 ? a + 2 : a] == 1) {
                            if (D_8010D908_191598_ToadBandstand[j >= 6 ? a + 2 : a] != 0) {
                                scale = D_8010D908_191598_ToadBandstand[j >= 6 ? a + 2 : a] == 1 ? 1.5f : 1.0f;
                            } else {
                                scale = 1.75f;
                            }
                        }
                        st = (s32)((1.0 / scale - 1.0) * 48.0);
                        gSPScisTextureRectangle(D_800FDBCC_FE7CC++, (s32)((x + 8 - scale * 6.0) * 4.0 + 0.0), (s32)((y + 8 - scale * 8.0) * 4.0 - scale * 0.0 + 0.0),
                                                (s32)((x + 8 + scale * 6.0) * 4.0 + 0.0), (s32)((y + 8 + scale * 8.0) * 4.0 + 0.0), G_TX_RENDERTILE, st, st, (s32)(1.0 / scale * 1024.0 + 0.5), (s32)(1.0 / scale * 1024.0 + 0.5));
                    }
                }
            }
        }
    }
    if (D_8010D8FC_19158C_ToadBandstand >= 3 && D_8010D8FC_19158C_ToadBandstand <= 9) {
        /* the song's bars: a marker runs along whichever bar is playing */
        for (a = 0; a < 2; a++) {
            if (D_8010D988_191618_ToadBandstand >= D_8010DA28_1916B8_ToadBandstand[a][0] && D_8010DA28_1916B8_ToadBandstand[a][1] >= D_8010D988_191618_ToadBandstand) {
                n = 1;
            } else if (D_8010D988_191618_ToadBandstand >= D_8010DA28_1916B8_ToadBandstand[a][2] && D_8010DA28_1916B8_ToadBandstand[a][3] >= D_8010D988_191618_ToadBandstand) {
                n = 2;
            } else if (D_8010D988_191618_ToadBandstand >= D_8010DA28_1916B8_ToadBandstand[a][4] && D_8010DA28_1916B8_ToadBandstand[a][5] >= D_8010D988_191618_ToadBandstand) {
                n = 3;
            } else {
                n = 0;
            }
            if (n != 0) {
                id = a + 3;
                spr[id] = func_80082550_83150(D_800F93FC_F9FFC[(s16)D_8010D990_191620_ToadBandstand[id]].unk_04, 0);
                frame[id] = &spr[id]->unk_84->unk00[spr[id]->unk_90];
                gDPLoadTextureBlock(D_800FDBCC_FE7CC++, frame[id]->unk00, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 48, 0, G_TX_CLAMP,
                                    G_TX_CLAMP, 0, 0, 0, 0);
                t0 = D_8010DA28_1916B8_ToadBandstand[a][n * 2 - 2];
                p = a * 0x8A + (D_8010D988_191618_ToadBandstand - t0) * 0x90 / (D_8010DA28_1916B8_ToadBandstand[a][n * 2 - 1] - t0) + 0x16;
                lo = a * 0x8A + 0x2B;
                hi = a * 0x8A + 0x9C;
                gSPScisTextureRectangle(D_800FDBCC_FE7CC++, (s32)((p < lo ? lo : p) * 4.0), 0x2C0, (s32)((p + 16 > hi ? hi : p + 16) * 4.0), 0x37C, G_TX_RENDERTILE,
                                        p < lo ? (lo - p) << 5 : 0, 0, 0x400, 0x400);
            }
        }
    }
    TS_GFX(0xE200001C, 0x504240);
    TS_GFX(0xE2001E01, 0);
    TS_GFX(0xF9000000, 0);
    TS_GFX(0xFA000000, -1);
    D_8010D908_191598_ToadBandstand[0]++;
    D_8010D908_191598_ToadBandstand[1]++;
    D_8010D908_191598_ToadBandstand[2]++;
    D_8010D908_191598_ToadBandstand[3]++;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_18_ToadBandstand/186490", func_80109388_18D018_ToadBandstand);
#endif

__asm__(".section .rodata");
const u32 D_8010D560_1911F0_ToadBandstand[1] = { 0x40180000 };

__asm__(".section .rodata");
const char D_8010D564_1911F4_ToadBandstand[] = "";

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_8010D568_1911F8_ToadBandstand[8] = "@%";

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_8010D570_191200_ToadBandstand[8] = "@(";

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_8010D578_191208_ToadBandstand[8] = "@ ";

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_8010D580_191210_ToadBandstand[8] = "@,";

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_8010D588_191218_ToadBandstand[8] = "@\"";

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_8010D590_191220_ToadBandstand[8] = "@\"";

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_8010D598_191228_ToadBandstand[8] = "@\"";

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_8010D5A0_191230_ToadBandstand[8] = "@\"";

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_8010D5A8_191238_ToadBandstand[8] = "@\"";

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_8010D5B0_191240_ToadBandstand[8] = "@\"";

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_8010D5B8_191248_ToadBandstand[8] = "@\"";

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010D5C0_191250_ToadBandstand[2] = { 0x40100000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010D5C8_191258_ToadBandstand[2] = { 0x3FF00000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010D5D0_191260_ToadBandstand[2] = { 0x40900000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010D5D8_191268_ToadBandstand[2] = { 0x3FE00000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010D5E0_191270_ToadBandstand[2] = { 0x40180000, 0x00000000 };

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_8010D5E8_191278_ToadBandstand[8] = "@ ";

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_8010D5F0_191280_ToadBandstand[8] = "@H";

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010D5F8_191288_ToadBandstand[2] = { 0x40180000, 0x00000000 };

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_8010D600_191290_ToadBandstand[8] = "@ ";

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_8010D608_191298_ToadBandstand[8] = "@ ";

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010D610_1912A0_ToadBandstand[2] = { 0x40100000, 0x00000000 };

void func_8010B6E4_18F374_ToadBandstand(s16 group) {
    func_8010B710_18F3A0_ToadBandstand(group, 0.0f, 0.0f, 1.0f);
}

void func_8010B710_18F3A0_ToadBandstand(s16 spr, f32 x, f32 unused1, f32 unused2) {
    HuSprite* s;
    HuSprite_Unk84_Unk00_Struct* frame;
    f64 t;
    f32 scale;
    f32 y;
    s16 tx;
    s16 ty;
    f32 x0;
    f32 x1;
    f32 y0;
    f32 y1;

    if (D_8010D900_191590_ToadBandstand < 1.0) {
        scale = 6.196 / (2.0 * (1.0 - D_8010D900_191590_ToadBandstand) + 1.502060606060606);
        y = HuMathSin(220.0f) * 14.0 + -187.5 + (scale / 4.125) * (1.0 - D_8010D900_191590_ToadBandstand) * 262.0;
    } else {
        t = 2.0 - D_8010D900_191590_ToadBandstand;
        scale = t * 100.0 / 32.0 + 1.0;
        y = t * 100.0;
        y = HuMathSin(t * 220.0) * 14.0 + y * -1.875;
    }
    s = func_80082550_83150(D_800F93FC_F9FFC[spr].unk_04, 0);
    frame = &s->unk_84->unk00[s->unk_90];
    gSPDisplayList(D_800FDBCC_FE7CC++, D_8010CD30_1909C0_ToadBandstand);
    gDPSetTextureLUT(D_800FDBCC_FE7CC++, G_TT_RGBA16);
    gDPLoadTLUT_pal256(D_800FDBCC_FE7CC++, s->unk_84->unk0C);
    for (ty = 0; ty < 240; ty += 40) {
        for (tx = 0; tx < 320; tx += 40) {
            x0 = (f32)(tx - 160) * scale + 160.0f + x;
            x1 = (f32)(tx - 119) * scale + 160.0f + x;
            y0 = (f32)(ty - 120) * scale + 120.0f + y;
            y1 = (f32)(ty - 79) * scale + 120.0f + y;
            gDPLoadTextureTile(D_800FDBCC_FE7CC++, tx + ty * 320 + (u8*)frame->unk00, G_IM_FMT_CI, G_IM_SIZ_8b, 320, 240, 0, 0, 41,
                               41, 0, G_TX_MIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_CLAMP, 0, 0, 0, 0);
            gSPScisTextureRectangle(D_800FDBCC_FE7CC++, TS_FIX(x0), TS_FIX(y0), TS_FIX(x1), TS_FIX(y1),
                                    G_TX_RENDERTILE, 0, 0, TS_STEP(x1, x0), TS_STEP(y1, y0));
        }
    }
}

void func_8010C804_190494_ToadBandstand(void) {
    Vec pos;
    Vec at;
    Vec up;
    f32 fov;
    f32 zoom;
    f32 y;
    f32 zero;
    f64 d;
    f32 s;

    fov = 0.0f;
    zero = fov;
    if (D_8010D900_191590_ToadBandstand < 1.0) {
        zoom = 4.125f;
        d = 2.0 * (1.0 - D_8010D900_191590_ToadBandstand);
        y = -114.86f;
        fov = d;
    } else {
        s = HuMathSin((D_8010D900_191590_ToadBandstand - 1.0) * 180.0) * -0.125 + (2.0 - D_8010D900_191590_ToadBandstand);
        zoom = s * 100.0 / 32.0 + 1.0;
        y = s * 100.0;
        y = ((1.0 - (1.0 - y) * (1.0 - y)) * 0.0043 + y * 0.9957) * -2.0;
    }
    pos.x = 0.0f;
    pos.y = y + 1778.465;
    pos.z = zero + 4823.96;
    at.x = 0.0f;
    at.y = y + 228.595;
    at.z = 0.0f;
    up.x = 0.0f;
    up.y = 1.0f;
    up.z = 0.0f;
    Hu3DCamSetPerspective(0, 6.196 / zoom + fov, 4000.0f, 8000.0f);
    D_800FA5BC_FB1BC[0] = 0;
    D_800FA5BC_FB1BC[1] = 0;
    D_800FA5BC_FB1BC[-1] = 0;
    D_800FA5BC_FB1BC[2] = D_800C9B80_CA780->fov[0];
    D_800FA5BC_FB1BC[3] = D_80101078_101C78;
    D_800FA5BC_FB1BC[4] = D_800F8410_F9010;
    Hu3DCamSetPositionOrientation(0, &pos, &at, &up);
    Hu3DCamUpdateMtx(0);
}
