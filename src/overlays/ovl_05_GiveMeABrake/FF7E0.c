#include "ovl_05.h"

/* .data (0x105790-0x105830, 801087B0-80108850) */
s32 D_801087B0_105790_GiveMeABrake[6] = { 2, 3, 7, 4, 5, 6 };
s32 D_801087C8_1057A8_GiveMeABrake[11] = {
    0x00140009, 0x0014000A, 0x0014000C, 0x0014000D, 0x0014000E, 0x0014000F,
    0x00140010, 0x00140011, 0x00140012, 0x00140013, 0x00140008,
};
f32 D_801087F4_1057D4_GiveMeABrake[3] = { 135.0f, -22.0f, 4.0f };
Gfx D_80108800_1057E0_GiveMeABrake[] = {
    { { 0xE7000000, 0x00000000 } }, { { 0xE3000A01, 0x00000000 } },
    { { 0xFCFFFFFF, 0xFFFCF279 } }, { { 0xE200001C, 0x0F0A4000 } },
    { { 0xE2001E01, 0x00000000 } }, { { 0xE3000C00, 0x00000000 } },
    { { 0xE3001201, 0x00002000 } }, { { 0xED000000, 0x005003C0 } },
    { { 0xDF000000, 0x00000000 } }, { { 0x00000000, 0x00000000 } },
};

__asm__(".section .rodata");
const char D_80108850_105830_GiveMeABrake[] = "\202r\202s\202`\202q\202s";

/* The minigame's set-up. */
void func_80102800_FF7E0_GiveMeABrake(void) {
    u8 cam;

    func_80020D20_21920(0x20);
    omInitObjMan(0x80, 0);
    func_80079128_79D28();
    func_80029708_2A308(0);
    func_80018E30_19A30(1);
    cam = func_80018E78_19A78();
    ScissorSet(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 3.158f, 9000.0f, 22000.0f);
    func_80026D28_27928(2);
    func_80026E00_27A00(0, 0.0f, 0.0f, 90.0f);
    func_80026DAC_279AC(0, 0x90, 0x90, 0x90);
    func_80026E00_27A00(1, 0.0f, 65.0f, 90.0f);
    func_80026DAC_279AC(1, 0xFF, 0xFF, 0xFF);
    D_8010274C_10334C.x = -11.0f;
    D_8010274C_10334C.y = 230.0f;
    D_8010274C_10334C.z = 0.0f;
    D_800FD474_FE074.x = 0.0f;
    D_800FD474_FE074.y = 0.0f;
    D_800FD474_FE074.z = 0.0f;
    D_800FA610_FB210 = 2140.0f;
    omAddObj(0, 0, 0, -1, func_80102A70_FFA50_GiveMeABrake);
    omSetStatBit(omAddObj(8, 0, 0, -1, func_801032D4_1002B4_GiveMeABrake), 0xA0);
    D_80109024_106004_GiveMeABrake = omAddObj(3, 0x11, 0x10, -1, func_80103564_100544_GiveMeABrake);
    D_801090B0_106090_GiveMeABrake = omAddObj(3, 0xA, 0xA, -1, func_80103AB0_100A90_GiveMeABrake);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_801086C8_1056A8_GiveMeABrake), 0xA0);
    func_801086C8_1056A8_GiveMeABrake(NULL);
    func_8007273C_7333C(D_80108850_105830_GiveMeABrake, 1);
}

/* Picks the player, the items on the panels and, for a CPU, how long it rides. */
void func_80102A70_FFA50_GiveMeABrake(omObjData* obj) {
    s32 i;
    s16 r;

    D_80109014_105FF4_GiveMeABrake = 0;
    D_80109028_106008_GiveMeABrake = 0;
    D_80109064_106044_GiveMeABrake = 0;
    D_80109010_105FF0_GiveMeABrake = 0;
    D_80109008_105FE8_GiveMeABrake = 0x7FFFFFFF;
    D_80109004_105FE4_GiveMeABrake = 0;
    D_80109038_106018_GiveMeABrake = 90;
    D_8010903B_10601B_GiveMeABrake = 0;
    D_801090B4_106094_GiveMeABrake = 1;
    D_80109018_105FF8_GiveMeABrake = 0.0f;
    D_8010903A_10601A_GiveMeABrake = 0;
    D_80109074_106054_GiveMeABrake = 0.0f;
    for (i = 0; i < 5; i++) {
        D_8010903C_10601C_GiveMeABrake[i + 1] = D_800CAFD8[i];
    }
    D_80109020_106000_GiveMeABrake = -1;
    D_80109000_105FE0_GiveMeABrake = 0;
    bzero(&D_80108FE0_105FC0_GiveMeABrake, 0x18);
    for (i = 0; i < 4; i++) {
        if (gPlayers[i].group == 0) {
            D_80108FE0_105FC0_GiveMeABrake.player = i;
            D_80108FE0_105FC0_GiveMeABrake.port = gPlayers[i].port;
            D_80108FE0_105FC0_GiveMeABrake.character = gPlayers[i].character;
            break;
        }
    }
    D_80108FE0_105FC0_GiveMeABrake.result = -2;
    D_80108FE0_105FC0_GiveMeABrake.cpu = (gPlayers[D_80108FE0_105FC0_GiveMeABrake.player].flags & 1)
        ? gPlayers[D_80108FE0_105FC0_GiveMeABrake.player].cpu_difficulty : -1;
    if (D_80108FE0_105FC0_GiveMeABrake.cpu != -1) {
        s16 odds[4] = { 30, 20, 10, 5 };

        if ((u8)(rand8() % 100) < odds[D_80108FE0_105FC0_GiveMeABrake.cpu]) {
            D_80108FE0_105FC0_GiveMeABrake.cpuTimer = 14;
        } else {
            r = (u8)(rand8() % 100);
            for (i = 0; i < 5; i++) {
                if (r < D_800CAFE4[i]) {
                    D_80108FE0_105FC0_GiveMeABrake.cpuTimer = i + 15;
                    break;
                }
                r -= D_800CAFE4[i];
            }
            if (i == 5) {
                D_80108FE0_105FC0_GiveMeABrake.cpuTimer = 14;
            }
        }
    }
    obj->func_ptr = func_80102D88_FFD68_GiveMeABrake;
}

/* The minigame's state machine: 0 intro, 1 ride, 2 press, 3 brake, 5 jump off, 6 item, 7 coin
   item, 8 empty/time out, 9 fade out. */
void func_80102D88_FFD68_GiveMeABrake(omObjData* obj) {
    D_80109010_105FF0_GiveMeABrake++;
    switch (D_80109028_106008_GiveMeABrake) {
    case 0:
        if (D_80109064_106044_GiveMeABrake == 0 && D_80109014_105FF4_GiveMeABrake == 0 && D_801011FC_101DFC == 0) {
            PlayMusic(0x28);
        }
        if (D_80109064_106044_GiveMeABrake == 1) {
            InitFadeIn(0, 0x10);
        }
        if (D_80109064_106044_GiveMeABrake == 0x87) {
            func_800691FC_69DFC(0);
        }
        if (D_80109064_106044_GiveMeABrake == 0xB4) {
            func_800691FC_69DFC(0xA, 0xA, 0xA0, 0x20);
        }
        if (D_80109064_106044_GiveMeABrake != 0xC3) {
            break;
        }
        D_80109028_106008_GiveMeABrake = 1;
        D_80109064_106044_GiveMeABrake = 0;
    case 1:
        if (D_80109064_106044_GiveMeABrake % 30 == 0 && D_80109064_106044_GiveMeABrake != 0) {
            func_8006D4D0_6E0D0(10 - D_80109064_106044_GiveMeABrake / 30);
        }
        break;
    case 2:
        if (D_80109064_106044_GiveMeABrake == 0) {
            func_8006D518_6E118();
        }
        if (D_80109064_106044_GiveMeABrake == 0x31) {
            D_80109028_106008_GiveMeABrake = 3;
            D_80109064_106044_GiveMeABrake = 0;
        }
        break;
    case 3:
        if (D_80109064_106044_GiveMeABrake != D_80109038_106018_GiveMeABrake + 1) {
            break;
        }
        D_80109028_106008_GiveMeABrake = 5;
        D_80109064_106044_GiveMeABrake = 0;
    case 5:
        if (D_80109064_106044_GiveMeABrake == 0) {
            func_800794A8_7A0A8(100);
            func_800691FC_69DFC(3);
        }
        if (D_80109064_106044_GiveMeABrake == (D_80108FE0_105FC0_GiveMeABrake.result == 3 ? 0x33 : 0x29)) {
            if ((u8)(D_80108FE0_105FC0_GiveMeABrake.result + 1) < 2) {
                D_80109028_106008_GiveMeABrake = 8;
            } else if (D_8010903C_10601C_GiveMeABrake[D_80108FE0_105FC0_GiveMeABrake.result] == 3) {
                D_80109028_106008_GiveMeABrake = 7;
            } else {
                D_80109028_106008_GiveMeABrake = 6;
            }
            D_80109064_106044_GiveMeABrake = 0;
            if (D_80109028_106008_GiveMeABrake != 8) {
                gPlayers[D_80108FE0_105FC0_GiveMeABrake.player].coins_mg_bonus = (u16)D_8010903C_10601C_GiveMeABrake[D_80108FE0_105FC0_GiveMeABrake.result];
            } else {
                gPlayers[D_80108FE0_105FC0_GiveMeABrake.player].coins_mg_bonus = -1;
            }
            if (_CheckFlag(0xC) != 0) {
                D_80109028_106008_GiveMeABrake = 9;
            }
        }
        break;
    case 8:
        if (D_80109064_106044_GiveMeABrake == 1) {
            func_800691FC_69DFC(0x10);
        }
        if (D_80109064_106044_GiveMeABrake == 1 && D_80109014_105FF4_GiveMeABrake == 0 && D_801011FC_101DFC == 0) {
            PlayMusic(0x56);
            func_80079518_7A118(0x7F);
        }
        if (D_80109064_106044_GiveMeABrake == 0x85) {
            D_80109028_106008_GiveMeABrake = 9;
            D_80109064_106044_GiveMeABrake = 0;
        }
        break;
    case 7:
        if (D_80109064_106044_GiveMeABrake == 1) {
            func_800691FC_69DFC(0x18);
        }
        if (D_80109064_106044_GiveMeABrake == 1 && D_80109014_105FF4_GiveMeABrake == 0 && D_801011FC_101DFC == 0) {
            PlayMusic(0x54);
            func_80079518_7A118(0x7F);
        }
        if (D_80109064_106044_GiveMeABrake == 0x90) {
            D_80109028_106008_GiveMeABrake = 9;
            D_80109064_106044_GiveMeABrake = 0;
        }
        break;
    case 6:
        if (D_80109064_106044_GiveMeABrake == 1) {
            func_800691FC_69DFC(0x17);
        }
        if (D_80109064_106044_GiveMeABrake == 1 && D_80109014_105FF4_GiveMeABrake == 0 && D_801011FC_101DFC == 0) {
            PlayMusic(0x53);
            func_80079518_7A118(0x7F);
        }
        if (D_80109064_106044_GiveMeABrake == 0x87) {
            D_80109028_106008_GiveMeABrake = 9;
            D_80109064_106044_GiveMeABrake = 0;
        }
        break;
    case 9:
        if (D_80109064_106044_GiveMeABrake == 1) {
            InitFadeOut(0, 0x14);
        } else if (D_80109064_106044_GiveMeABrake >= 25) {
            D_80109014_105FF4_GiveMeABrake = 1;
        }
        break;
    }
    D_80109064_106044_GiveMeABrake++;
    if (D_80109014_105FF4_GiveMeABrake != 0 || D_801011FC_101DFC != 0) {
        if (D_801011FC_101DFC != 0) {
            if (D_80109000_105FE0_GiveMeABrake == 0) {
                InitFadeOut(0, 0x14);
                func_800794A8_7A0A8(0x14);
                func_80079614_7A214(0x14);
            }
            D_80109000_105FE0_GiveMeABrake++;
            if (D_80109000_105FE0_GiveMeABrake < 25) {
                return;
            }
        }
        func_800794A8_7A0A8(0x28);
        omOvlReturnEx(1);
    }
}

/* The backdrop sprite and the item sprites on the panels. */
void func_801032D4_1002B4_GiveMeABrake(omObjData* obj) {
    s16 anim[10];
    s16 i;
    f32 angle;

    D_80109090_106070_GiveMeABrake = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x150003), 0, 0);
    espDispOff(D_80109090_106070_GiveMeABrake);
    for (i = 0; i < 5; i++) {
        anim[i] = func_8001A2F8_1AEF8(D_801087C8_1057A8_GiveMeABrake[D_8010903C_10601C_GiveMeABrake[i + 1]]);
        D_80109098_106078_GiveMeABrake[i] = SprCreate(1, 0);
        SprAnimSet(D_80109098_106078_GiveMeABrake[i], 0, anim[i], 0);
        SprAttrReset(D_80109098_106078_GiveMeABrake[i], 0, 0xFFFF);
        SprAttrSet(D_80109098_106078_GiveMeABrake[i], 0, 0x04005828);
        angle = (4 - i) * 60.0 + 60.0;
        SprPos3DSet(D_80109098_106078_GiveMeABrake[i], 0, 0, -HuMathSin(angle) * 350.0, 105.0f, func_800B7890_B8490(angle) * 350.0);
    }
    obj->func_ptr = func_801034C8_1004A8_GiveMeABrake;
}

/* Draws the backdrop; its shake alternates sign each frame and decays. */
void func_801034C8_1004A8_GiveMeABrake(omObjData* obj) {
    func_80107608_1045E8_GiveMeABrake(D_80109090_106070_GiveMeABrake, 0.0f, D_801090B4_106094_GiveMeABrake * D_8010903B_10601B_GiveMeABrake, 1.0f);
    D_801090B4_106094_GiveMeABrake = -D_801090B4_106094_GiveMeABrake;
    D_8010903B_10601B_GiveMeABrake -= D_801090B4_106094_GiveMeABrake == 1 && D_8010903B_10601B_GiveMeABrake > 0;
}

/* Loads every model. */
void func_80103564_100544_GiveMeABrake(omObjData* obj) {
    s32 tbl[10][6] = {
        { 0xD1, 0xD1, 0xD1, 0xD1, 0xD1, 0xD1 },
        { 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F },
        { 0, 0, 0, 0, 0, 0 },
        { 0x57, 0x57, 0x57, 0x57, 0x57, 0x57 },
        { 0x56, 0x56, 0x56, 0x56, 0x56, 0x56 },
        { 0x54, 0x54, 0x54, 0x54, 0x54, 0x54 },
        { 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0 },
    };
    u8 chr;
    s32 dir;
    f32 x;

    chr = gPlayers[D_80108FE0_105FC0_GiveMeABrake.player].character;
    dir = D_800CD438_CE038[chr].unk_04;
    obj->model[0] = LoadFormFile(dir | tbl[0][chr], 0x4A9);
    HmfModelObjAttrSet(obj->model[0], 0x600, 0x400);
    func_80029E80_2AA80(obj->model[0], 2, 2);
    D_80109078_106058_GiveMeABrake = func_80025384_25F84(obj->model[0], 2, D_80108FE0_105FC0_GiveMeABrake.character, func_80025718_26318(D_80108FE0_105FC0_GiveMeABrake.character, 2, 0) | D_800CD438_CE038[D_80108FE0_105FC0_GiveMeABrake.character].unk_04);
    func_80025554_26154(obj->model[0], 2, D_80108FE0_105FC0_GiveMeABrake.character, (s16)D_80109078_106058_GiveMeABrake);
    omSetTra(obj, 0.0f, 55.0f, 0.0f);
    D_80109088_106068_GiveMeABrake = 0;
    obj->model[9] = LoadFormFile(dir | tbl[0][chr], 0x4AD);
    HmfModelObjAttrSet(obj->model[9], 0x600, 0x400);
    func_80029714_2A314(obj->model[9], 0.0f, 55.0f, 0.0f);
    obj->model[10] = LoadFormFile(dir | tbl[0][chr], 0x4AD);
    HmfModelObjAttrSet(obj->model[10], 0x600, 0x400);
    func_80029714_2A314(obj->model[10], 0.0f, 55.0f, 0.0f);
    obj->model[1] = LoadFormFile(dir | tbl[1][chr], 0x49D);
    obj->model[2] = LoadFormFile(dir | tbl[2][chr], 0x49D);
    func_80029E80_2AA80(obj->model[2], 2, 2);
    obj->model[3] = LoadFormFile(dir | tbl[3][chr], 0x49D);
    obj->model[4] = LoadFormFile(dir | tbl[4][chr], 0x49D);
    obj->model[5] = LoadFormFile(dir | tbl[5][chr], 0x49D);
    obj->model[6] = LoadFormFile(0x150000, 0x6A9);
    HmfModelObjAttrSet(obj->model[6], 0x600, 0x400);
    func_80029E80_2AA80(obj->model[6], 1, 1);
    func_8002979C_2A39C(obj->model[6], 0.0f, 29.0f, 0.0f);
    obj->model[7] = LoadFormFile(0x150001, 0x6A9);
    HmfModelObjAttrSet(obj->model[7], 0x600, 0x400);
    func_80029E80_2AA80(obj->model[7], 2, 2);
    func_8002979C_2A39C(obj->model[7], 0.0f, 29.0f, 0.0f);
    obj->model[8] = LoadFormFile(0x150002, 0x6A9);
    HmfModelObjAttrSet(obj->model[8], 0x600, 0x400);
    func_80029E80_2AA80(obj->model[8], 1, 1);
    func_8002D1EC_2DDEC(obj->model[8], 1);
    func_8002D274_2DE74(obj->model[8], 0x50, 0x50, 0x50);
    func_8002D2B4_2DEB4(obj->model[8], 0.0f, 0.0f, 90.0f);
    obj->model[11] = LoadFormFile(0x800B0, 0x4B9);
    HmfModelObjAttrSet(obj->model[11], 0x600, 0x400);
    func_80029E80_2AA80(obj->model[11], 2, 2);
    x = -HuMathSin(-9.0f) * 350.0;
    func_80029714_2A314(obj->model[11], x, 135.0f, func_800B7890_B8490(-9.0f) * 350.0);
    func_8002979C_2A39C(obj->model[11], 0.0f, 81.0f, 0.0f);
    obj->model[16] = LoadFormFile(0xD, 0x489);
    HmfModelObjAttrSet(obj->model[16], 0x600, 0x400);
    func_800297E8_2A3E8(obj->model[16], 1.0f, 1.0f, 1.0f);
    func_8002D124_2DD24(obj->model[16]);
    obj->model[12] = LoadFormFile(0x800B0, 0x49D);
    obj->model[13] = LoadFormFile(0x800B3, 0x49D);
    obj->model[14] = LoadFormFile(0x800B2, 0x49D);
    obj->model[15] = LoadFormFile(0x800B1, 0x49D);
    obj->func_ptr = func_80103BE8_100BC8_GiveMeABrake;
}

/* Ten spark models. */
void func_80103AB0_100A90_GiveMeABrake(omObjData* obj) {
    s16 i;

    for (i = 0; i < 10; i++) {
        obj->model[i] = LoadFormFile(0x1001F, 0x49D);
        HmfModelObjAttrSet(obj->model[i], 0x600, 0x400);
        if (i == 0) {
            omSetTra(obj, 0.0f, 100.0f, 0.0f);
            omSetSca(obj, 0.65f, 0.65f, 0.65f);
        } else {
            func_80029714_2A314(obj->model[i], 0.0f, 100.0f, 0.0f);
            func_800297E8_2A3E8(obj->model[i], 0.65f, 0.65f, 0.65f);
        }
    }
    obj->func_ptr = NULL;
}

/* The player and the turntable, per state, then the wheel, the jump, the item and the shadow. */
void func_80103BE8_100BC8_GiveMeABrake(omObjData* obj) {
    f32 shadow;
    s32 press;
    f32 px;
    f32 py;
    f32 pz;
    f32 v;
    f64 d;
    s16 i;

    if (D_800FC834_FD434[obj->model[11]].pos.y >= 135.0) {
        shadow = 135.0f;
    } else {
        shadow = 0.0f;
    }
    press = 0;
    if (D_80109028_106008_GiveMeABrake != 0 || D_80109064_106044_GiveMeABrake >= 2) {
        switch (D_80109028_106008_GiveMeABrake) {
        case 0:
            if (D_80109064_106044_GiveMeABrake > 45 && D_80109064_106044_GiveMeABrake < 136) {
                D_801090A8_106088_GiveMeABrake = (f32)(D_80109064_106044_GiveMeABrake - 45) / 90.0f * 6.0;
                if (D_80109020_106000_GiveMeABrake != -1) {
                    func_800796F0_7A2F0(D_80109020_106000_GiveMeABrake, D_801090A8_106088_GiveMeABrake * 100.0 - 300.0);
                }
            }
            if (D_80109064_106044_GiveMeABrake == 2) {
                func_80029B80_2A780(obj->model[11], obj->model[13]);
                func_80029E80_2AA80(obj->model[11], 2, 2);
            }
            if (D_80109064_106044_GiveMeABrake >= 2 && D_80109064_106044_GiveMeABrake < 27) {
                func_8002979C_2A39C(obj->model[11], 0.0f, -81.0f, 0.0f);
                func_80029714_2A314(obj->model[11], (1.0 - D_80109064_106044_GiveMeABrake / 26.0f) * 370.0 + 230.0, 0.0f, 345.65158f);
            }
            if (D_80109064_106044_GiveMeABrake == 27) {
                func_80029BF0_2A7F0(obj->model[11], func_80029E14_2AA14(obj->model[14]), 0, 1, 1);
            }
            if (D_80109064_106044_GiveMeABrake == 30) {
                D_8010900C_105FEC_GiveMeABrake = 50.0f;
                D_80109060_106040_GiveMeABrake = 0.0f;
                func_80029BF0_2A7F0(obj->model[11], func_80029E14_2AA14(obj->model[15]), 10, 6, 1);
            }
            if (D_80109064_106044_GiveMeABrake >= 30 && D_80109064_106044_GiveMeABrake < 61 && (D_80109060_106040_GiveMeABrake >= 135.0 || D_8010900C_105FEC_GiveMeABrake > 0.0)) {
                D_8010900C_105FEC_GiveMeABrake -= 5.25;
                D_80109060_106040_GiveMeABrake += D_8010900C_105FEC_GiveMeABrake;
                func_80029714_2A314(obj->model[11], (1.0 - (D_80109064_106044_GiveMeABrake - 30) / 15.0f) * 145.0 + 55.0, D_80109060_106040_GiveMeABrake, 345.65158f);
                if (D_8010900C_105FEC_GiveMeABrake < 0.0) {
                    shadow = 135.0f;
                } else {
                    shadow = 0.0f;
                }
            }
            if (D_80109064_106044_GiveMeABrake == 43) {
                func_80029BF0_2A7F0(obj->model[11], func_80029E14_2AA14(obj->model[14]), 0, 3, 1);
            }
            if (D_80109064_106044_GiveMeABrake == 44) {
                func_80029714_2A314(obj->model[11], 55.0f, 135.0f, 345.65158f);
            }
            if (D_80109064_106044_GiveMeABrake == 47) {
                func_80029BF0_2A7F0(obj->model[11], func_80029E14_2AA14(obj->model[12]), 0, 30, 2);
                D_80109020_106000_GiveMeABrake = PlaySound(0x13E);
                func_800796F0_7A2F0(D_80109020_106000_GiveMeABrake, -300);
            }
            if (D_80108FE0_105FC0_GiveMeABrake.cpu != -1 && (s32)(D_80109018_105FF8_GiveMeABrake / 60.0f) != (s32)((D_80109018_105FF8_GiveMeABrake + D_801090A8_106088_GiveMeABrake) / 60.0f)) {
                D_80108FE0_105FC0_GiveMeABrake.cpuTimer--;
            }
            if (D_80109064_106044_GiveMeABrake >= 45) {
                D_80109018_105FF8_GiveMeABrake += D_801090A8_106088_GiveMeABrake;
                D_80109018_105FF8_GiveMeABrake -= D_80109018_105FF8_GiveMeABrake > 360.0 ? 360.0 : 0.0;
                D_80109074_106054_GiveMeABrake += D_801090A8_106088_GiveMeABrake;
            }
            break;
        case 1:
            if (D_80108FE0_105FC0_GiveMeABrake.cpu != -1) {
                if (D_80108FE0_105FC0_GiveMeABrake.cpuTimer > 0) {
                    if ((s32)(D_80109018_105FF8_GiveMeABrake / 60.0f) != (s32)((D_80109018_105FF8_GiveMeABrake + D_801090A8_106088_GiveMeABrake) / 60.0f)) {
                        D_80108FE0_105FC0_GiveMeABrake.cpuTimer--;
                        if (D_80108FE0_105FC0_GiveMeABrake.cpuTimer == 0) {
                            press = 0x8000;
                        }
                    }
                }
            } else {
                press = ContBtnTrg[D_80108FE0_105FC0_GiveMeABrake.port] & 0x8000;
            }
            D_80109018_105FF8_GiveMeABrake += D_801090A8_106088_GiveMeABrake;
            D_80109018_105FF8_GiveMeABrake -= D_80109018_105FF8_GiveMeABrake > 360.0 ? 360.0 : 0.0;
            D_80109074_106054_GiveMeABrake += D_801090A8_106088_GiveMeABrake;
            if (press != 0 && D_80108FE0_105FC0_GiveMeABrake.result == -2) {
                D_80109028_106008_GiveMeABrake = 2;
                D_80109064_106044_GiveMeABrake = 0;
                D_80109008_105FE8_GiveMeABrake = D_80109010_105FF0_GiveMeABrake;
                func_800298A4_2A4A4(obj->model[D_80109088_106068_GiveMeABrake], 4, 4);
                func_800298A4_2A4A4(obj->model[9], 4, 0);
                D_80109088_106068_GiveMeABrake = 9;
                if (D_80108FE0_105FC0_GiveMeABrake.character == 3) {
                    D_8010907C_10605C_GiveMeABrake = func_80025384_25F84(obj->model[9], 2, D_80108FE0_105FC0_GiveMeABrake.character, func_80025718_26318(3, 2, 3) | D_800CD438_CE038[D_80108FE0_105FC0_GiveMeABrake.character].unk_04);
                    func_80025554_26154(obj->model[9], 2, D_80108FE0_105FC0_GiveMeABrake.character, (s16)D_8010907C_10605C_GiveMeABrake);
                }
                func_80029B80_2A780(obj->model[D_80109088_106068_GiveMeABrake], obj->model[1]);
                func_80029E80_2AA80(obj->model[8], 3, 0);
            }
            if (D_80109064_106044_GiveMeABrake == 300) {
                D_80109028_106008_GiveMeABrake = 2;
                D_80109064_106044_GiveMeABrake = 10;
                D_80109008_105FE8_GiveMeABrake = D_80109010_105FF0_GiveMeABrake;
                func_80029E80_2AA80(obj->model[8], 3, 0);
                D_80108FE0_105FC0_GiveMeABrake.result = -1;
                func_8006D4D0_6E0D0(0);
                func_8006D518_6E118();
            }
            break;
        case 2:
            D_80109018_105FF8_GiveMeABrake += D_801090A8_106088_GiveMeABrake;
            D_80109018_105FF8_GiveMeABrake -= D_80109018_105FF8_GiveMeABrake > 360.0 ? 360.0 : 0.0;
            D_80109074_106054_GiveMeABrake += D_801090A8_106088_GiveMeABrake;
            if (D_80109010_105FF0_GiveMeABrake == D_80109008_105FE8_GiveMeABrake + 45) {
                PlaySound(0x13D);
            }
            break;
        case 3:
            if (D_80109064_106044_GiveMeABrake == 1) {
                D_801090A8_106088_GiveMeABrake = D_80109018_105FF8_GiveMeABrake;
                if (D_80108FE0_105FC0_GiveMeABrake.result == -1) {
                    D_801090AC_10608C_GiveMeABrake = 360.0f - D_80109018_105FF8_GiveMeABrake;
                } else {
                    D_80108FE0_105FC0_GiveMeABrake.result = (s32)((D_80109018_105FF8_GiveMeABrake + 30.0) / 60.0) + 5;
                    if ((u8)(rand8() % 10) < 3) {
                        if (rand8() & 1) {
                            D_80109038_106018_GiveMeABrake += 30;
                            D_80108FE0_105FC0_GiveMeABrake.result++;
                        } else {
                            D_80109038_106018_GiveMeABrake -= 15;
                            D_80108FE0_105FC0_GiveMeABrake.result--;
                        }
                    }
                    D_801090AC_10608C_GiveMeABrake = D_80108FE0_105FC0_GiveMeABrake.result * 60 - D_80109018_105FF8_GiveMeABrake;
                    D_80108FE0_105FC0_GiveMeABrake.result %= 6;
                }
            }
            if (D_80109010_105FF0_GiveMeABrake == D_80109008_105FE8_GiveMeABrake + 82) {
                if (D_80108FE0_105FC0_GiveMeABrake.result != -1) {
                    if (D_80108FE0_105FC0_GiveMeABrake.character == 3) {
                        D_80109080_106060_GiveMeABrake = func_80025384_25F84(obj->model[0], 2, D_80108FE0_105FC0_GiveMeABrake.character, func_80025718_26318(3, 2, 0) | D_800CD438_CE038[D_80108FE0_105FC0_GiveMeABrake.character].unk_04);
                        func_80025554_26154(obj->model[0], 2, D_80108FE0_105FC0_GiveMeABrake.character, (s16)D_80109080_106060_GiveMeABrake);
                    }
                    func_800298A4_2A4A4(obj->model[D_80109088_106068_GiveMeABrake], 4, 4);
                    func_800298A4_2A4A4(obj->model[10], 4, 0);
                    D_80109088_106068_GiveMeABrake = 10;
                    func_80029B80_2A780(obj->model[10], obj->model[2]);
                    func_80029E80_2AA80(obj->model[D_80109088_106068_GiveMeABrake], 3, 2);
                }
                D_80108FE0_105FC0_GiveMeABrake.result = D_80108FE0_105FC0_GiveMeABrake.result == -1 ? 0 : D_80108FE0_105FC0_GiveMeABrake.result;
            }
            D_80109018_105FF8_GiveMeABrake = D_801090A8_106088_GiveMeABrake + (1.0 - (1.0 - D_80109064_106044_GiveMeABrake / (f32)D_80109038_106018_GiveMeABrake) * (1.0 - D_80109064_106044_GiveMeABrake / (f32)D_80109038_106018_GiveMeABrake)) * D_801090AC_10608C_GiveMeABrake;
            D_80109018_105FF8_GiveMeABrake -= D_80109018_105FF8_GiveMeABrake > 360.0 ? 360.0 : 0.0;
            D_80109074_106054_GiveMeABrake -= (1.0 - (1.0 - (D_80109064_106044_GiveMeABrake - 1) / (f32)D_80109038_106018_GiveMeABrake) * (1.0 - (D_80109064_106044_GiveMeABrake - 1) / (f32)D_80109038_106018_GiveMeABrake)) * D_801090AC_10608C_GiveMeABrake
                - (1.0 - (1.0 - D_80109064_106044_GiveMeABrake / (f32)D_80109038_106018_GiveMeABrake) * (1.0 - D_80109064_106044_GiveMeABrake / (f32)D_80109038_106018_GiveMeABrake)) * D_801090AC_10608C_GiveMeABrake;
            func_800796F0_7A2F0(D_80109020_106000_GiveMeABrake, D_80109064_106044_GiveMeABrake / (f32)D_80109038_106018_GiveMeABrake * -600.0 + 300.0);
            break;
        case 5:
            shadow = 0.0f;
            if (D_80109064_106044_GiveMeABrake == 1) {
                if (D_80108FE0_105FC0_GiveMeABrake.cpu == -1) {
                    omVibrate(D_80108FE0_105FC0_GiveMeABrake.player, 2, 2, 20);
                }
                func_80079848_7A448(D_80109020_106000_GiveMeABrake);
            }
            if (D_80109088_106068_GiveMeABrake != 10) {
                if (D_80108FE0_105FC0_GiveMeABrake.character == 3) {
                    D_80109080_106060_GiveMeABrake = func_80025384_25F84(obj->model[0], 2, D_80108FE0_105FC0_GiveMeABrake.character, func_80025718_26318(3, 2, 0) | D_800CD438_CE038[D_80108FE0_105FC0_GiveMeABrake.character].unk_04);
                    func_80025554_26154(obj->model[0], 2, D_80108FE0_105FC0_GiveMeABrake.character, (s16)D_80109080_106060_GiveMeABrake);
                }
                func_800298A4_2A4A4(obj->model[D_80109088_106068_GiveMeABrake], 4, 4);
                func_800298A4_2A4A4(obj->model[10], 4, 0);
                D_80109088_106068_GiveMeABrake = 10;
                func_80029B80_2A780(obj->model[10], obj->model[2]);
                func_80029E80_2AA80(obj->model[D_80109088_106068_GiveMeABrake], 3, 2);
            }
            if (D_80108FE0_105FC0_GiveMeABrake.result >= -1 || D_80108FE0_105FC0_GiveMeABrake.result == 0) {
                f32 rot0[7] = { -90.0f, -63.0f, -78.0f, -279.0f, -288.0f, -306.0f, -293.0f };
                f32 dist[7] = { 270.0f, 155.0f, 165.0f, 225.0f, 215.0f, 200.0f, 275.0f };
                f32 rot1[7] = { -0.0f, -102.0f, -78.0f, -293.0f, -270.0f, -270.0f, -293.0f };

                if (D_80109064_106044_GiveMeABrake == 2) {
                    D_8010908C_10606C_GiveMeABrake = -HuMathSin(D_80108FE0_105FC0_GiveMeABrake.result * 60.0 - 9.0) * 350.0;
                    D_80109060_106040_GiveMeABrake = 135.0f;
                    D_8010901C_105FFC_GiveMeABrake = func_800B7890_B8490(D_80108FE0_105FC0_GiveMeABrake.result * 60.0 - 9.0) * 350.0;
                    D_8010900C_105FEC_GiveMeABrake = 36.5f;
                    shadow = 135.0f;
                    func_80029BF0_2A7F0(obj->model[11], func_80029E14_2AA14(obj->model[14]), 0, 5, 1);
                }
                if (D_80109064_106044_GiveMeABrake == 10 && (u8)(D_80108FE0_105FC0_GiveMeABrake.result + 1) >= 2) {
                    PlaySound(0x12E);
                }
                if (D_80109064_106044_GiveMeABrake == 1 && D_80108FE0_105FC0_GiveMeABrake.result == 0) {
                    PlaySound(0x13C);
                }
                if (D_80109064_106044_GiveMeABrake >= 2 && D_80109064_106044_GiveMeABrake < 7) {
                    func_8002979C_2A39C(obj->model[11], 0.0f, (-D_80108FE0_105FC0_GiveMeABrake.result * 60.0 - 81.0) * (1.0 - (D_80109064_106044_GiveMeABrake - 1.0) / 10.0) + rot0[D_80108FE0_105FC0_GiveMeABrake.result] * ((D_80109064_106044_GiveMeABrake - 1.0) / 10.0), 0.0f);
                    shadow = 135.0f;
                }
                if (D_80109064_106044_GiveMeABrake == 7) {
                    func_8002979C_2A39C(obj->model[11], 0.0f, rot0[D_80108FE0_105FC0_GiveMeABrake.result], 0.0f);
                    func_80029BF0_2A7F0(obj->model[11], func_80029E14_2AA14(obj->model[15]), 10, 8, 1);
                    shadow = 135.0f;
                }
                if (D_80109064_106044_GiveMeABrake >= 7 && D_80109064_106044_GiveMeABrake < 23) {
                    D_8010900C_105FEC_GiveMeABrake -= 5.25;
                    D_80109060_106040_GiveMeABrake += D_8010900C_105FEC_GiveMeABrake;
                    func_80029714_2A314(obj->model[11], D_8010908C_10606C_GiveMeABrake + HuMathSin(rot0[D_80108FE0_105FC0_GiveMeABrake.result]) * dist[D_80108FE0_105FC0_GiveMeABrake.result] * ((D_80109064_106044_GiveMeABrake - 7.0) / 15.0), D_80109060_106040_GiveMeABrake, D_8010901C_105FFC_GiveMeABrake + func_800B7890_B8490(rot0[D_80108FE0_105FC0_GiveMeABrake.result]) * dist[D_80108FE0_105FC0_GiveMeABrake.result] * ((D_80109064_106044_GiveMeABrake - 7.0) / 15.0));
                    if (D_8010900C_105FEC_GiveMeABrake > 0.0) {
                        shadow = 135.0f;
                    } else {
                        shadow = 0.0f;
                    }
                }
                if (D_80109064_106044_GiveMeABrake == 20) {
                    func_80029BF0_2A7F0(obj->model[11], func_80029E14_2AA14(obj->model[14]), 0, 4, 1);
                }
                if (D_80109064_106044_GiveMeABrake == 22) {
                    D_8010908C_10606C_GiveMeABrake += HuMathSin(rot0[D_80108FE0_105FC0_GiveMeABrake.result]) * dist[D_80108FE0_105FC0_GiveMeABrake.result] * ((D_80109064_106044_GiveMeABrake - 7.0) / 15.0);
                    D_8010901C_105FFC_GiveMeABrake += func_800B7890_B8490(rot0[D_80108FE0_105FC0_GiveMeABrake.result]) * dist[D_80108FE0_105FC0_GiveMeABrake.result] * ((D_80109064_106044_GiveMeABrake - 7.0) / 15.0);
                }
                if (D_80108FE0_105FC0_GiveMeABrake.result == 3) {
                    if (D_80109064_106044_GiveMeABrake >= 26 && D_80109064_106044_GiveMeABrake < 31) {
                        func_8002979C_2A39C(obj->model[11], 0.0f, rot0[3] * (1.0 - (D_80109064_106044_GiveMeABrake - 1.0 - 24.0) / 10.0) + rot0[6] * ((D_80109064_106044_GiveMeABrake - 1.0 - 24.0) / 10.0), 0.0f);
                    }
                    if (D_80109064_106044_GiveMeABrake == 31) {
                        D_8010900C_105FEC_GiveMeABrake = 45.8125f;
                        func_8002979C_2A39C(obj->model[11], 0.0f, rot0[6], 0.0f);
                        func_80029BF0_2A7F0(obj->model[11], func_80029E14_2AA14(obj->model[15]), 10, 8, 1);
                    }
                    if (D_80109064_106044_GiveMeABrake >= 31 && D_80109064_106044_GiveMeABrake < 47) {
                        D_8010900C_105FEC_GiveMeABrake -= 5.25;
                        D_80109060_106040_GiveMeABrake += D_8010900C_105FEC_GiveMeABrake;
                        func_80029714_2A314(obj->model[11], D_8010908C_10606C_GiveMeABrake + HuMathSin(rot0[6]) * dist[6] * ((D_80109064_106044_GiveMeABrake - 7.0 - 24.0) / 15.0), D_80109060_106040_GiveMeABrake, D_8010901C_105FFC_GiveMeABrake + func_800B7890_B8490(rot0[6]) * dist[6] * ((D_80109064_106044_GiveMeABrake - 7.0 - 24.0) / 15.0));
                    }
                    if (D_80109064_106044_GiveMeABrake == 44) {
                        func_80029BF0_2A7F0(obj->model[11], func_80029E14_2AA14(obj->model[14]), 0, 4, 1);
                    }
                    if (D_80109064_106044_GiveMeABrake == 46) {
                        D_8010908C_10606C_GiveMeABrake += HuMathSin(rot0[6]) * dist[6] * ((D_80109064_106044_GiveMeABrake - 7.0 - 24.0) / 15.0);
                        D_8010901C_105FFC_GiveMeABrake += func_800B7890_B8490(rot0[6]) * dist[6] * ((D_80109064_106044_GiveMeABrake - 7.0 - 24.0) / 15.0);
                    }
                    if (D_80109064_106044_GiveMeABrake == 48) {
                        D_8010900C_105FEC_GiveMeABrake = 0.0f;
                        D_80109060_106040_GiveMeABrake = 0.0f;
                        func_80029BF0_2A7F0(obj->model[11], func_80029E14_2AA14(obj->model[13]), 0, 10, 2);
                    }
                    if (D_80109064_106044_GiveMeABrake >= 48) {
                        D_8010900C_105FEC_GiveMeABrake += D_8010900C_105FEC_GiveMeABrake < 18.0 ? 3.0 : 0.0;
                        D_80109060_106040_GiveMeABrake += D_8010900C_105FEC_GiveMeABrake;
                        func_8002979C_2A39C(obj->model[11], 0.0f, rot0[6] * (1.0 - D_8010900C_105FEC_GiveMeABrake / 18.0) + rot1[6] * (D_8010900C_105FEC_GiveMeABrake / 18.0), 0.0f);
                        func_80029714_2A314(obj->model[11], HuMathSin(rot1[6]) * D_80109060_106040_GiveMeABrake + D_8010908C_10606C_GiveMeABrake, 0.0f, func_800B7890_B8490(rot1[6]) * D_80109060_106040_GiveMeABrake + D_8010901C_105FFC_GiveMeABrake);
                    }
                } else if (D_80108FE0_105FC0_GiveMeABrake.result == 0) {
                    if (D_80109064_106044_GiveMeABrake == 24) {
                        D_8010900C_105FEC_GiveMeABrake = 0.0f;
                        D_80109060_106040_GiveMeABrake = 0.0f;
                        func_80029BF0_2A7F0(obj->model[11], func_80029E14_2AA14(obj->model[13]), 0, 8, 2);
                    }
                    if (D_80109064_106044_GiveMeABrake >= 24) {
                        if (D_8010900C_105FEC_GiveMeABrake == 16.0) {
                            func_80029BF0_2A7F0(obj->model[11], func_80029E14_2AA14(obj->model[12]), 0, 8, 2);
                        }
                        D_8010900C_105FEC_GiveMeABrake += D_8010900C_105FEC_GiveMeABrake < 18.0 ? 2.0 : 0.0;
                        func_8002979C_2A39C(obj->model[11], 0.0f, rot0[D_80108FE0_105FC0_GiveMeABrake.result] * (1.0 - D_8010900C_105FEC_GiveMeABrake / 18.0) + rot1[D_80108FE0_105FC0_GiveMeABrake.result] * (D_8010900C_105FEC_GiveMeABrake / 18.0), 0.0f);
                        func_80029714_2A314(obj->model[11], HuMathSin(rot1[D_80108FE0_105FC0_GiveMeABrake.result]) * D_80109060_106040_GiveMeABrake + D_8010908C_10606C_GiveMeABrake, 0.0f, func_800B7890_B8490(rot1[D_80108FE0_105FC0_GiveMeABrake.result]) * D_80109060_106040_GiveMeABrake + D_8010901C_105FFC_GiveMeABrake);
                    }
                } else {
                    if (D_80109064_106044_GiveMeABrake == 24) {
                        D_8010900C_105FEC_GiveMeABrake = 0.0f;
                        D_80109060_106040_GiveMeABrake = 0.0f;
                        func_80029BF0_2A7F0(obj->model[11], func_80029E14_2AA14(obj->model[13]), 0, 10, 2);
                    }
                    if (D_80109064_106044_GiveMeABrake >= 24) {
                        D_8010900C_105FEC_GiveMeABrake += D_8010900C_105FEC_GiveMeABrake < 18.0 ? 3.0 : 0.0;
                        D_80109060_106040_GiveMeABrake += D_8010900C_105FEC_GiveMeABrake;
                        func_8002979C_2A39C(obj->model[11], 0.0f, rot0[D_80108FE0_105FC0_GiveMeABrake.result] * (1.0 - D_8010900C_105FEC_GiveMeABrake / 18.0) + rot1[D_80108FE0_105FC0_GiveMeABrake.result] * (D_8010900C_105FEC_GiveMeABrake / 18.0), 0.0f);
                        func_80029714_2A314(obj->model[11], HuMathSin(rot1[D_80108FE0_105FC0_GiveMeABrake.result]) * D_80109060_106040_GiveMeABrake + D_8010908C_10606C_GiveMeABrake, 0.0f, func_800B7890_B8490(rot1[D_80108FE0_105FC0_GiveMeABrake.result]) * D_80109060_106040_GiveMeABrake + D_8010901C_105FFC_GiveMeABrake);
                    }
                }
            }
            if (D_80109064_106044_GiveMeABrake == 10 && D_80108FE0_105FC0_GiveMeABrake.result > 0) {
                D_80109004_105FE4_GiveMeABrake = 1;
            }
            break;
        case 8:
            {
                if (D_80109064_106044_GiveMeABrake == 15 && D_80108FE0_105FC0_GiveMeABrake.result == 0) {
                    func_80029BF0_2A7F0(obj->model[11], func_80029E14_2AA14(obj->model[14]), 0, 8, 2);
                }
                if (D_80109064_106044_GiveMeABrake == 1) {
                    func_80029B80_2A780(obj->model[D_80109088_106068_GiveMeABrake], obj->model[3]);
                }
                {
                s32 unused[6] = { 7, 1, 1, 1, 26, 8 };
                s32 face[6] = { 2, 8, 2, 2, 5, 2 };

                if (func_80073014_73C14((D_801087B0_105790_GiveMeABrake[D_80108FE0_105FC0_GiveMeABrake.character] << 16) | 0x57, 0) / 2 + 1 == D_80109064_106044_GiveMeABrake) {
                    D_80109084_106064_GiveMeABrake = func_80025384_25F84(obj->model[D_80109088_106068_GiveMeABrake], 2, D_80108FE0_105FC0_GiveMeABrake.character, func_80025718_26318(D_80108FE0_105FC0_GiveMeABrake.character, 2, face[D_80108FE0_105FC0_GiveMeABrake.character]) | D_800CD438_CE038[D_80108FE0_105FC0_GiveMeABrake.character].unk_04);
                    func_80025554_26154(obj->model[D_80109088_106068_GiveMeABrake], 2, D_80108FE0_105FC0_GiveMeABrake.character, (s16)D_80109084_106064_GiveMeABrake);
                }
                if (D_80109064_106044_GiveMeABrake == 1) {
                    func_800732B0_73EB0((D_801087B0_105790_GiveMeABrake[D_80108FE0_105FC0_GiveMeABrake.character] << 16) | 0x57);
                }
                }
            }
            break;
        case 7:
            {
                if (D_80109064_106044_GiveMeABrake == 1) {
                    func_80029B80_2A780(obj->model[D_80109088_106068_GiveMeABrake], obj->model[4]);
                }
                {
                s32 unused[6] = { 18, 1, 1, 1, 1, 1 };
                s32 pad[1][6]; /* unused: fixes the stack layout */
                s32 face[6] = { 8, 5, 5, 2, 5, 5 };

                if (0) pad[0][0] = 0;
                if (func_80073014_73C14((D_801087B0_105790_GiveMeABrake[D_80108FE0_105FC0_GiveMeABrake.character] << 16) | 0x56, 0) / 2 + 1 == D_80109064_106044_GiveMeABrake) {
                    D_80109084_106064_GiveMeABrake = func_80025384_25F84(obj->model[D_80109088_106068_GiveMeABrake], 2, D_80108FE0_105FC0_GiveMeABrake.character, func_80025718_26318(D_80108FE0_105FC0_GiveMeABrake.character, 2, face[D_80108FE0_105FC0_GiveMeABrake.character]) | D_800CD438_CE038[D_80108FE0_105FC0_GiveMeABrake.character].unk_04);
                    func_80025554_26154(obj->model[D_80109088_106068_GiveMeABrake], 2, D_80108FE0_105FC0_GiveMeABrake.character, (s16)D_80109084_106064_GiveMeABrake);
                }
                if (D_80109064_106044_GiveMeABrake == 1) {
                    func_800732B0_73EB0((D_801087B0_105790_GiveMeABrake[D_80108FE0_105FC0_GiveMeABrake.character] << 16) | 0x56);
                }
                }
            }
            break;
        case 6:
            {
                if (D_80109064_106044_GiveMeABrake == 1) {
                    func_80029B80_2A780(obj->model[D_80109088_106068_GiveMeABrake], obj->model[5]);
                }
                {
                s32 unused[6] = { 58, 36, 255, 45, 19, 255 };
                s32 pad[1][6];
                s32 pad2[1][6];
                s32 unused2[6] = { 60, 32, 57, 45, 19, 54 };
                s32 n;

                if (0) pad[0][0] = pad2[0][0] = unused2[0] = 0;
                n = func_80073014_73C14((D_801087B0_105790_GiveMeABrake[D_80108FE0_105FC0_GiveMeABrake.character] << 16) | 0x54, 0) / 2 + 1;
                if ((D_80108FE0_105FC0_GiveMeABrake.character == 0 ? n + 7 : n) == D_80109064_106044_GiveMeABrake) {
                    D_80109084_106064_GiveMeABrake = func_80025384_25F84(obj->model[D_80109088_106068_GiveMeABrake], 2, D_80108FE0_105FC0_GiveMeABrake.character, func_80025718_26318(D_80108FE0_105FC0_GiveMeABrake.character, 2, 1) | D_800CD438_CE038[D_80108FE0_105FC0_GiveMeABrake.character].unk_04);
                    func_80025554_26154(obj->model[D_80109088_106068_GiveMeABrake], 2, D_80108FE0_105FC0_GiveMeABrake.character, (s16)D_80109084_106064_GiveMeABrake);
                }
                if (D_80109064_106044_GiveMeABrake == (D_80108FE0_105FC0_GiveMeABrake.character == 0 ? 8 : 1)) {
                    func_800732B0_73EB0((D_801087B0_105790_GiveMeABrake[D_80108FE0_105FC0_GiveMeABrake.character] << 16) | 0x54);
                }
                }
            }
            break;
        }
        func_8002979C_2A39C(obj->model[6], 0.0f, -D_80109018_105FF8_GiveMeABrake + 29.0, 0.0f);
        func_8002979C_2A39C(obj->model[7], 0.0f, -D_80109018_105FF8_GiveMeABrake + 29.0, 0.0f);
        D_80109074_106054_GiveMeABrake = D_80109074_106054_GiveMeABrake - (s32)(D_80109074_106054_GiveMeABrake / 15.0) * 15.0;
        if (D_80109074_106054_GiveMeABrake < 0.0) {
            D_80109074_106054_GiveMeABrake = 0.0f;
        }
        func_80029C74_2A874(obj->model[6], D_80109074_106054_GiveMeABrake);
        if ((D_80109028_106008_GiveMeABrake != 0 || D_80109064_106044_GiveMeABrake >= 45) && D_80109028_106008_GiveMeABrake != 5 && D_80109028_106008_GiveMeABrake != 8 && D_80109028_106008_GiveMeABrake != 6 && D_80109028_106008_GiveMeABrake != 7 && D_80109028_106008_GiveMeABrake != 9) {
            func_80029714_2A314(obj->model[11], -HuMathSin(D_80109018_105FF8_GiveMeABrake - 9.0) * 350.0, 135.0f, func_800B7890_B8490(D_80109018_105FF8_GiveMeABrake - 9.0) * 350.0);
            func_8002979C_2A39C(obj->model[11], 0.0f, -D_80109018_105FF8_GiveMeABrake - 81.0, 0.0f);
        } else if (D_80109028_106008_GiveMeABrake == 8 || D_80109028_106008_GiveMeABrake == 6 || D_80109028_106008_GiveMeABrake == 7 || D_80109028_106008_GiveMeABrake == 9) {
            s32 pad[18];
            f32 h;
            f32 rot0[7] = { -90.0f, -63.0f, -78.0f, -279.0f, -288.0f, -306.0f, -293.0f };
            f32 rot1[7] = { 0.0f, -102.0f, -78.0f, -293.0f, -270.0f, -270.0f, -293.0f };

            if (0) pad[0] = 0;
            D_8010900C_105FEC_GiveMeABrake += D_8010900C_105FEC_GiveMeABrake < 18.0 ? 3.0 : 0.0;
            if (D_80108FE0_105FC0_GiveMeABrake.result == 0) {
                h = D_80109060_106040_GiveMeABrake + D_8010900C_105FEC_GiveMeABrake * 0.0f;
            } else {
                h = D_80109060_106040_GiveMeABrake + D_8010900C_105FEC_GiveMeABrake;
            }
            D_80109060_106040_GiveMeABrake = h;
            func_8002979C_2A39C(obj->model[11], 0.0f, rot0[D_80108FE0_105FC0_GiveMeABrake.result != 3 ? D_80108FE0_105FC0_GiveMeABrake.result : 6] * (1.0 - D_8010900C_105FEC_GiveMeABrake / 18.0) + rot1[D_80108FE0_105FC0_GiveMeABrake.result != 3 ? D_80108FE0_105FC0_GiveMeABrake.result : 6] * (D_8010900C_105FEC_GiveMeABrake / 18.0), 0.0f);
            func_80029714_2A314(obj->model[11], HuMathSin(rot1[D_80108FE0_105FC0_GiveMeABrake.result != 3 ? D_80108FE0_105FC0_GiveMeABrake.result : 6]) * D_80109060_106040_GiveMeABrake + D_8010908C_10606C_GiveMeABrake, 0.0f, func_800B7890_B8490(rot1[D_80108FE0_105FC0_GiveMeABrake.result != 3 ? D_80108FE0_105FC0_GiveMeABrake.result : 6]) * D_80109060_106040_GiveMeABrake + D_8010901C_105FFC_GiveMeABrake);
        }
        if (0) { /* retail's dead debug print: only its string survives, after the local tables */
            osSyncPrintf("px=%f py=%f pz=%f\n", px, py, pz);
        }
        if (D_80109004_105FE4_GiveMeABrake == 0) {
            s16 j;

            for (j = 0; j < 5; j++) {
                SprPos3DSet(D_80109098_106078_GiveMeABrake[j], 0, 0, -HuMathSin(D_80109018_105FF8_GiveMeABrake - 0.0 + (4 - j) * 60.0 + 60.0) * 350.0, 105.0f, func_800B7890_B8490(D_80109018_105FF8_GiveMeABrake - 0.0 + (4 - j) * 60.0 + 60.0) * 350.0);
            }
        } else {
            if (D_80109004_105FE4_GiveMeABrake < 31) {
                f32 x1;
                f32 y1;
                f32 z1;
                f64 t = D_80109004_105FE4_GiveMeABrake / 30.0f;
                f64 u = 1.0 - t;
                f64 w;

                w = t * 0.0 * t * t;
                x1 = 0.0f;
                y1 = u * 105.0 * u * u + t * 1650.0 * u * u + t * 2040.0 * t * u + t * 400.0 * t * t;
                z1 = u * 350.0 * u * u + t * 750.0 * u * u + t * 300.0 * t * u + w;
                if (D_80109004_105FE4_GiveMeABrake == 1) {
                    s16 anim[8];

                    for (i = 0; i < 5; i++) {
                        SprPrioSet(D_80109098_106078_GiveMeABrake[i], 0, 1);
                    }
                    for (i = 0; i < 3; i++) {
                        anim[i + 5] = func_8001A2F8_1AEF8(D_801087C8_1057A8_GiveMeABrake[D_8010903C_10601C_GiveMeABrake[D_80108FE0_105FC0_GiveMeABrake.result]]);
                        D_80109098_106078_GiveMeABrake[i + 5] = SprCreate(1, 0);
                        SprAnimSet(D_80109098_106078_GiveMeABrake[i + 5], 0, anim[i + 5], 0);
                        SprAttrReset(D_80109098_106078_GiveMeABrake[i + 5], 0, 0xFFFF);
                        SprAttrSet(D_80109098_106078_GiveMeABrake[i + 5], 0, 0x04001828);
                        SprPrioSet(D_80109098_106078_GiveMeABrake[i + 5], 0, i + 0x1002);
                    }
                    D_8010902C_10600C_GiveMeABrake[0] = D_8010902C_10600C_GiveMeABrake[1] = D_8010902C_10600C_GiveMeABrake[2] = x1;
                    D_80109054_106034_GiveMeABrake[0] = D_80109054_106034_GiveMeABrake[1] = D_80109054_106034_GiveMeABrake[2] = y1;
                    D_80109068_106048_GiveMeABrake[0] = D_80109068_106048_GiveMeABrake[1] = D_80109068_106048_GiveMeABrake[2] = z1;
                }
                SprPos3DSet((D_80109098_106078_GiveMeABrake - 1)[D_80108FE0_105FC0_GiveMeABrake.result], 0, 0, x1, y1, z1);
                SprPos3DSet((D_80109098_106078_GiveMeABrake - 1)[6], 0, 0, D_8010902C_10600C_GiveMeABrake[0], D_80109054_106034_GiveMeABrake[0], D_80109068_106048_GiveMeABrake[0]);
                SprPos3DSet((D_80109098_106078_GiveMeABrake - 1)[7], 0, 0, D_8010902C_10600C_GiveMeABrake[1], D_80109054_106034_GiveMeABrake[1], D_80109068_106048_GiveMeABrake[1]);
                SprPos3DSet((D_80109098_106078_GiveMeABrake - 1)[8], 0, 0, D_8010902C_10600C_GiveMeABrake[2], D_80109054_106034_GiveMeABrake[2], D_80109068_106048_GiveMeABrake[2]);
                func_800824B4_830B4((D_80109098_106078_GiveMeABrake - 1)[6], 0, 0xFF, 0xFF, 0xFF, D_80109004_105FE4_GiveMeABrake >= 15 ? (u8)((1.0 - 2.0 * ((D_80109004_105FE4_GiveMeABrake - 15) / 30.0f)) * 192.0) : 192);
                func_800824B4_830B4(D_80109098_106078_GiveMeABrake[6], 0, 0xFF, 0xFF, 0xFF, D_80109004_105FE4_GiveMeABrake >= 15 ? (u8)((1.0 - 2.0 * ((D_80109004_105FE4_GiveMeABrake - 15) / 30.0f)) * 128.0) : 128);
                func_800824B4_830B4(D_80109098_106078_GiveMeABrake[7], 0, 0xFF, 0xFF, 0xFF, D_80109004_105FE4_GiveMeABrake >= 15 ? (u8)((1.0 - 2.0 * ((D_80109004_105FE4_GiveMeABrake - 15) / 30.0f)) * 64.0) : 64);
                D_8010902C_10600C_GiveMeABrake[2] = D_8010902C_10600C_GiveMeABrake[1];
                D_8010902C_10600C_GiveMeABrake[1] = D_8010902C_10600C_GiveMeABrake[0];
                D_8010902C_10600C_GiveMeABrake[0] = x1;
                D_80109054_106034_GiveMeABrake[2] = D_80109054_106034_GiveMeABrake[1];
                D_80109054_106034_GiveMeABrake[1] = D_80109054_106034_GiveMeABrake[0];
                D_80109054_106034_GiveMeABrake[0] = y1;
                D_80109068_106048_GiveMeABrake[2] = D_80109068_106048_GiveMeABrake[1];
                D_80109068_106048_GiveMeABrake[1] = D_80109068_106048_GiveMeABrake[0];
                D_80109068_106048_GiveMeABrake[0] = z1;
                if (D_80109004_105FE4_GiveMeABrake % 3 == 1) {
                    func_800298A4_2A4A4(D_801090B0_106090_GiveMeABrake->model[D_8010903A_10601A_GiveMeABrake], 4, 0);
                    func_80029C74_2A874(D_801090B0_106090_GiveMeABrake->model[D_8010903A_10601A_GiveMeABrake], 27.0f);
                    func_80107598_104578_GiveMeABrake(D_801090B0_106090_GiveMeABrake->model[D_8010903A_10601A_GiveMeABrake], 27);
                    if (D_8010903A_10601A_GiveMeABrake == 0) {
                        omSetTra(D_801090B0_106090_GiveMeABrake, x1 - 18.0, y1 - 30.0, z1 - 30.0);
                    } else {
                        func_80029714_2A314(D_801090B0_106090_GiveMeABrake->model[D_8010903A_10601A_GiveMeABrake], x1 - 15.0, y1 - 30.0, z1 - 30.0);
                    }
                    D_8010903A_10601A_GiveMeABrake++;
                    D_8010903A_10601A_GiveMeABrake %= 10;
                }
            } else {
                f32 x2;
                f32 y2;
                f32 z2;
                f64 w;

                x2 = 0.0f;
                w = HuMathSin((D_80109004_105FE4_GiveMeABrake % 60) * 6.0 + 0.0);
                y2 = w * (D_80109004_105FE4_GiveMeABrake < 90 ? (1.0 - D_80109004_105FE4_GiveMeABrake / 90.0f) * 70.0 + 40.0 : 40.0) + 400.0;
                z2 = 0.0f;
                if (D_80109004_105FE4_GiveMeABrake == 31) {
                    SprAttrSet(D_80109098_106078_GiveMeABrake[5], 0, 0x04009828);
                    SprAttrSet(D_80109098_106078_GiveMeABrake[6], 0, 0x04009828);
                    SprAttrSet(D_80109098_106078_GiveMeABrake[7], 0, 0x04009828);
                }
                SprPos3DSet((D_80109098_106078_GiveMeABrake - 1)[D_80108FE0_105FC0_GiveMeABrake.result], 0, 0, x2, y2, z2);
                if (D_80109004_105FE4_GiveMeABrake % 10 == 1) {
                    func_800298A4_2A4A4(D_801090B0_106090_GiveMeABrake->model[D_8010903A_10601A_GiveMeABrake], 4, 0);
                    func_80029C74_2A874(D_801090B0_106090_GiveMeABrake->model[D_8010903A_10601A_GiveMeABrake], 27.0f);
                    func_80107598_104578_GiveMeABrake(D_801090B0_106090_GiveMeABrake->model[D_8010903A_10601A_GiveMeABrake], 27);
                    if (D_8010903A_10601A_GiveMeABrake == 0) {
                        omSetTra(D_801090B0_106090_GiveMeABrake, x2 - 18.0, y2 - 30.0, z2 - 30.0);
                    } else {
                        func_80029714_2A314(D_801090B0_106090_GiveMeABrake->model[D_8010903A_10601A_GiveMeABrake], x2 - 15.0, y2 - 30.0, z2 - 30.0);
                    }
                    D_8010903A_10601A_GiveMeABrake++;
                    D_8010903A_10601A_GiveMeABrake %= 8;
                }
            }
            D_80109004_105FE4_GiveMeABrake++;
        }
        func_80029714_2A314(obj->model[16], D_800FC834_FD434[obj->model[11]].pos.x, shadow >= 100.0 ? 140.0f : 0.0f, D_800FC834_FD434[obj->model[11]].pos.z);
        v = D_800FC834_FD434[obj->model[11]].pos.y - (shadow > 100.0 ? 135.0 : 0.0);
        v = v > 80.0 ? 0.0f : v >= 0.0 ? (d = v / 80.0, 1.0 - d * d) : 1.0f;
        func_8002D0A0_2DCA0(obj->model[16], v * 255.0);
        if (D_80109028_106008_GiveMeABrake >= 5 && shadow < 100.0) {
            v *= 1.1;
        } else if (D_80109028_106008_GiveMeABrake >= 0 && D_800FC834_FD434[obj->model[11]].pos.y != 0.0 && D_800FC834_FD434[obj->model[11]].pos.y != 135.0) {
            v *= 0.85;
        }
        func_800297E8_2A3E8(obj->model[16], v, v, v);
    }
}

/* Sets a model's motion frame directly. */
void func_80107598_104578_GiveMeABrake(s16 model, s16 frame) {
    s32 off = model * sizeof(HmfModel);
    HmfModel* m = (HmfModel*)(off + (u8*)D_800FC834_FD434);

    m->hmf->unk9C->unk08 = frame;
}

void func_801075DC_1045BC_GiveMeABrake(s16 sprite) {
    func_80107608_1045E8_GiveMeABrake(sprite, 0.0f, 0.0f, 1.0f);
}

#ifdef NON_MATCHING
/* Draws a 320x240 CI8 esp image by hand in 40x40 tiles, at offset (x, y), scaled about the screen centre. */
void func_80107608_1045E8_GiveMeABrake(s16 sprite, f32 x, f32 y, f32 scale) {
    HuSprite* spr;
    HuSprite_Unk84_Unk00_Struct* frame;
    s16 tx;
    s16 ty;
    f32 x0;
    f32 x1;
    f32 y0;
    f32 y1;

    if (scale < 1.0f) {
        scale = 1.0f;
    }
    spr = func_80082550_83150(D_800F93FC_F9FFC[sprite].unk_04, 0);
    frame = &spr->unk_84->unk00[spr->unk_90];
    gSPDisplayList(D_800FDBCC_FE7CC++, D_80108800_1057E0_GiveMeABrake);
    gDPSetTextureLUT(D_800FDBCC_FE7CC++, G_TT_RGBA16);
    gDPLoadTLUT_pal256(D_800FDBCC_FE7CC++, spr->unk_84->unk0C);
    for (ty = 0; ty < 240; ty += 40) {
        for (tx = 0; tx < 320; tx += 40) {
            x0 = (f32)(tx - 160) * scale + 160.0f + x;
            x1 = (f32)(tx - 119) * scale + 160.0f + x;
            y0 = (f32)(ty - 120) * scale + 120.0f + y;
            y1 = (f32)(ty - 79) * scale + 120.0f + y;
            gDPLoadTextureTile(D_800FDBCC_FE7CC++, frame->unk00, G_IM_FMT_CI, G_IM_SIZ_8b, 320, 240, tx, ty, tx + 41,
                               ty + 41, 0, G_TX_MIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_CLAMP, 0, 0, 0, 0);
            gSPScisTextureRectangle(D_800FDBCC_FE7CC++, GB_FIX(x0), GB_FIX(y0), GB_FIX(x1), GB_FIX(y1),
                                    G_TX_RENDERTILE, tx << 5, ty << 5, GB_STEP(x0, x1), GB_STEP(y0, y1));
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_GiveMeABrake/FF7E0", func_80107608_1045E8_GiveMeABrake);
#endif

/* The fixed camera. */
void func_801086C8_1056A8_GiveMeABrake(omObjData* obj) {
    Vec pos;
    Vec at;
    Vec up;

    pos.x = 0.0f;
    pos.y = 10173.787f;
    pos.z = 10896.917f;
    at.x = 0.0f;
    at.y = 8200.832f;
    at.z = 8764.1875f;
    up.x = 0.0f;
    up.y = 1.0f;
    up.z = 0.0f;
    D_800FA5BC_FB1BC[0] = pos.x;
    D_800FA5BC_FB1BC[1] = pos.z;
    D_800FA5BC_FB1BC[-1] = pos.x;
    D_800FA5BC_FB1BC[2] = D_800C9B80_CA780->fov[0];
    D_800FA5BC_FB1BC[3] = D_80101078_101C78;
    D_800FA5BC_FB1BC[4] = D_800F8410_F9010;
    Hu3DCamSetPositionOrientation(0, &pos, &at, &up);
    Hu3DCamUpdateMtx(0);
}
