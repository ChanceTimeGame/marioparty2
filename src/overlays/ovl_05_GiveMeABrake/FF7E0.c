#include "ovl_05.h"

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

/* The hand sprite and the items on the panels. */
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

/* The shake: alternates sign each frame, and decays. */
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

__asm__(".section .rodata");
const u32 D_80108998_105978_GiveMeABrake[7] = { 0xC2B40000, 0xC27C0000, 0xC29C0000, 0xC38B8000, 0xC3900000, 0xC3990000, 0xC3928000 };

__asm__(".section .rodata");
const u32 D_801089B4_105994_GiveMeABrake[7] = { 0x43870000, 0x431B0000, 0x43250000, 0x43610000, 0x43570000, 0x43480000, 0x43898000 };

__asm__(".section .rodata");
const u32 D_801089D0_1059B0_GiveMeABrake[7] = { 0x80000000, 0xC2CC0000, 0xC29C0000, 0xC3928000, 0xC3870000, 0xC3870000, 0xC3928000 };

__asm__(".section .rodata");
const u32 D_801089EC_1059CC_GiveMeABrake[6] = { 0x00000007, 0x00000001, 0x00000001, 0x00000001, 0x0000001A, 0x00000008 };

__asm__(".section .rodata");
const u32 D_80108A04_1059E4_GiveMeABrake[6] = { 0x00000002, 0x00000008, 0x00000002, 0x00000002, 0x00000005, 0x00000002 };

__asm__(".section .rodata");
const u32 D_80108A1C_1059FC_GiveMeABrake[6] = { 0x00000012, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001 };

__asm__(".section .rodata");
const u32 D_80108A34_105A14_GiveMeABrake[6] = { 0x00000008, 0x00000005, 0x00000005, 0x00000002, 0x00000005, 0x00000005 };

__asm__(".section .rodata");
const u32 D_80108A4C_105A2C_GiveMeABrake[6] = { 0x0000003A, 0x00000024, 0x000000FF, 0x0000002D, 0x00000013, 0x000000FF };

__asm__(".section .rodata");
const u32 D_80108A64_105A44_GiveMeABrake[6] = { 0x0000003C, 0x00000020, 0x00000039, 0x0000002D, 0x00000013, 0x00000036 };

__asm__(".section .rodata");
const u32 D_80108A7C_105A5C_GiveMeABrake[13] = { 0x00000000, 0xC2CC0000, 0xC29C0000, 0xC3928000, 0xC3870000, 0xC3870000, 0xC3928000, 0x70783D25, 0x66207079, 0x3D256620, 0x707A3D25, 0x660A0000, 0x00000000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_GiveMeABrake/FF7E0", func_80103BE8_100BC8_GiveMeABrake);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_GiveMeABrake/FF7E0", func_80107598_104578_GiveMeABrake);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_GiveMeABrake/FF7E0", func_801075DC_1045BC_GiveMeABrake);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_GiveMeABrake/FF7E0", func_80107608_1045E8_GiveMeABrake);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_05_GiveMeABrake/FF7E0", func_801086C8_1056A8_GiveMeABrake);
