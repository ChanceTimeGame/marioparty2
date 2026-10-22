#include "ovl_52.h"

void func_80102800_358DE0_name_52(void) {
    D_80106B30_35D110_name_52 = GwSystem.current_board_index;
    omInitObjMan(0x50, 0x50);
    func_80079128_79D28();
    func_80020D20_21920(10);
    func_80105B8C_35C16C_name_52();
    func_80105674_35BC54_name_52();
    func_80050E00_51A00(D_8010680C_35CDEC_name_52[D_80106B30_35D110_name_52]);
    func_8005321C_53E1C(80.0f, 8000.0f);
    func_80088640_89240();
    omAddPrcObj(func_80103814_359DF4_name_52, 0x300, 0x4000, 0);
    omAddObj(0x1000, 0, 0, -1, func_80105640_35BC20_name_52);
}

/* "YOU ARE THE WINNER", in the font */
void func_801028C4_358EA4_name_52(void) {
    s32 mes;
    s32 i;

    mes = (s16)func_8006A608_s32(&D_80106B78_35D158_name_52, D_8010697C_35CF5C_name_52, 0, -1, -1);
    SprPosSet(D_80106B78_35D158_name_52.strGId[mes], 0, D_80106980_35CF60_name_52[0], D_80106980_35CF60_name_52[1]);
    for (i = 1; i < 19; i++) {
        SprScaleSet(D_80106B78_35D158_name_52.strGId[mes], i, 1.0f, 2.0f);
    }
}

void func_80102978_358F58_name_52(void) {
    func_8006AE14_6BA14(&D_80106B78_35D158_name_52);
}

__asm__(".section .rodata");
const char D_80106AA0_35D080_name_52[] = "YOU ARE THE WINNER";

/* Pulses a leader's digits: work[0] player, work[1] digit count. */
void func_80102998_358F78_name_52(omObjData* obj) {
    f32 s;
    s32 i;

    s = __sinf(obj->rot.x * DEG) * 0.3f + 1.0;
    for (i = 0; i < obj->work[1]; i++) {
        SprScaleSet((s16)D_80106B60_35D140_name_52[obj->work[0]], i, s, s);
    }
    if ((obj->rot.x += 30.0f) >= 360.0f) {
        obj->rot.x -= 360.0f;
    }
}

/* Each player's coins in digits over their head; the leaders' digits pulse. */
void func_80102AA0_359080_name_52(void) {
    s32 digits[3];
    Vec pos;
    Vec2f scr;
    void* file;
    s32 n;
    s32 cnt;
    s32 i;
    s32 j;
    s32 max;

    file = DataRead(0xA00D5);
    D_80106B70_35D150_name_52 = SprAnimRead(file);
    DataClose(file);
    for (i = 0; i < 4; i++) {
        D_80106B60_35D140_name_52[i] = SprCreate(3, 5);
        n = (s16)(u16)gPlayers[i].coins;
        if (n >= 100) {
            cnt = 3;
            digits[0] = n / 100;
            n %= 100;
            digits[1] = n / 10;
            n %= 10;
            digits[2] = n;
        } else if (n >= 10) {
            cnt = 2;
            n %= 100;
            digits[0] = n / 10;
            n %= 10;
            digits[1] = n;
        } else {
            cnt = 1;
            digits[0] = n;
        }
        for (j = 0; j < cnt; j++) {
            SprAnimSet((s16)D_80106B60_35D140_name_52[i], j, (s16)D_80106B70_35D150_name_52, 0);
            func_8008225C_82E5C((s16)D_80106B60_35D140_name_52[i], j, 1);
            func_800822A8_82EA8((s16)D_80106B60_35D140_name_52[i], j, digits[j], 0);
            SprPrioSet((s16)D_80106B60_35D140_name_52[i], j, 0x4790);
            SprAttrSet((s16)D_80106B60_35D140_name_52[i], j, 0x1000);
            func_80082450_83050((s16)D_80106B60_35D140_name_52[i], (s16)j, 0xFF, 0xFF, 0);
            if (j == 0) {
                pos.x = ((MBModel*)gPlayers[i].unk_24)->pos.x;
                pos.y = ((MBModel*)gPlayers[i].unk_24)->pos.y + 300.0f;
                pos.z = ((MBModel*)gPlayers[i].unk_24)->pos.z;
                MBDCamera3Dto2D(&pos, &scr);
                SprPosSet((s16)D_80106B60_35D140_name_52[i], 0, scr.unk_00 - (cnt - 1) * 7, scr.unk_04);
            } else {
                SprPosSet((s16)D_80106B60_35D140_name_52[i], j, j * 14, 0);
            }
        }
        max = gPlayers[i].coins;
        for (j = 0; j < 4; j++) {
            if (j != i && max < gPlayers[j].coins) {
                max = gPlayers[j].coins;
            }
        }
        if (max == gPlayers[i].coins) {
            D_801067FC_35CDDC_name_52[i] = omAddObj(0x1000, 0, 0, -1, func_80102998_358F78_name_52);
            D_801067FC_35CDDC_name_52[i]->work[0] = i;
            D_801067FC_35CDDC_name_52[i]->work[1] = cnt;
            D_801067FC_35CDDC_name_52[i]->rot.x = 0.0f;
        }
    }
}

void func_80102EDC_3594BC_name_52(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_801067FC_35CDDC_name_52[i] != NULL) {
            omDelObj(D_801067FC_35CDDC_name_52[i]);
            D_801067FC_35CDDC_name_52[i] = NULL;
        }
        SprKill((s16)D_80106B60_35D140_name_52[i]);
    }
    SprAnimKill((s16)D_80106B70_35D150_name_52);
    HuPrcVSleep();
}

/* Each player's stars in digits over their head; the leaders' digits pulse. */
void func_80102F78_359558_name_52(void) {
    s32 digits[2];
    Vec pos;
    Vec2f scr;
    void* file;
    s32 n;
    s32 cnt;
    s32 i;
    s32 j;
    s32 max;

    file = DataRead(0xA00D5);
    D_80106B70_35D150_name_52 = SprAnimRead(file);
    DataClose(file);
    for (i = 0; i < 4; i++) {
        D_80106B60_35D140_name_52[i] = SprCreate(2, 5);
        n = (s16)(u16)gPlayers[i].stars;
        if (n >= 10) {
            cnt = 2;
            n %= 100;
            digits[0] = n / 10;
            n %= 10;
            digits[1] = n;
        } else {
            cnt = 1;
            digits[0] = n;
        }
        for (j = 0; j < cnt; j++) {
            SprAnimSet((s16)D_80106B60_35D140_name_52[i], j, (s16)D_80106B70_35D150_name_52, 0);
            func_8008225C_82E5C((s16)D_80106B60_35D140_name_52[i], j, 1);
            func_800822A8_82EA8((s16)D_80106B60_35D140_name_52[i], j, digits[j], 0);
            SprPrioSet((s16)D_80106B60_35D140_name_52[i], j, 0x4790);
            SprAttrSet((s16)D_80106B60_35D140_name_52[i], j, 0x1000);
            func_80082450_83050((s16)D_80106B60_35D140_name_52[i], (s16)j, 0xFF, 0xFF, 0);
            if (j == 0) {
                pos.x = ((MBModel*)gPlayers[i].unk_24)->pos.x;
                pos.y = ((MBModel*)gPlayers[i].unk_24)->pos.y + 300.0f;
                pos.z = ((MBModel*)gPlayers[i].unk_24)->pos.z;
                MBDCamera3Dto2D(&pos, &scr);
                SprPosSet((s16)D_80106B60_35D140_name_52[i], 0, scr.unk_00 - (cnt - 1) * 7, scr.unk_04);
            } else {
                SprPosSet((s16)D_80106B60_35D140_name_52[i], j, j * 14, 0);
            }
        }
        max = gPlayers[i].stars;
        for (j = 0; j < 4; j++) {
            if (j != i && max < gPlayers[j].stars) {
                max = gPlayers[j].stars;
            }
        }
        if (max == gPlayers[i].stars) {
            D_801067FC_35CDDC_name_52[i] = omAddObj(0x1000, 0, 0, -1, func_80102998_358F78_name_52);
            D_801067FC_35CDDC_name_52[i]->work[0] = i;
            D_801067FC_35CDDC_name_52[i]->work[1] = cnt;
            D_801067FC_35CDDC_name_52[i]->rot.x = 0.0f;
        }
    }
}

void func_80103338_359918_name_52(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_801067FC_35CDDC_name_52[i] != NULL) {
            omDelObj(D_801067FC_35CDDC_name_52[i]);
            D_801067FC_35CDDC_name_52[i] = NULL;
        }
        SprKill((s16)D_80106B60_35D140_name_52[i]);
    }
    SprAnimKill((s16)D_80106B70_35D150_name_52);
    HuPrcVSleep();
}

/* A bonus star flies down to each flagged player (count: how many get one). */
/* NON_MATCHING: registers (masked 0): i, y and the model pointer take s1/s0/s2 where retail has s2/s1/s0 */
#ifdef NON_MATCHING
void func_801033D4_3599B4_name_52(s32 count, u8* flags) {
    s16 sounds[4] = { 0x34A, 0x34A, 0x34A, 0x34A };
    s32 n;
    s32 y;
    s32 i;
    s32 k;
    MBModel* m;
    s32 snd;

    n = 0;
    for (i = 0; i < 4; i++) {
        if (flags[i] != 0) {
            D_800F8CE4_F98E4[10 + i]++;
            func_800595E8_5A1E8(gPlayers[i].unk_24, 5, 0);
            snd = PlaySound(sounds[n++]);
            if (count != 1) {
                func_80015710_16310((s16)snd, D_80106978_35CF58_name_52[i]);
            }
            D_801067E0_35CDC0_name_52[i] = func_80049ED4_4AAD4(D_80106B40_35D120_name_52[i], 1);
            for (k = 0, y = 800; y >= 250; y -= 15, k++) {
                MBModelDispOn(D_80106B40_35D120_name_52[i]);
                HuVecCopyXYZ(&D_80106B40_35D120_name_52[i]->pos, ((MBModel*)gPlayers[i].unk_24)->pos.x,
                             y + ((MBModel*)gPlayers[i].unk_24)->pos.y, ((MBModel*)gPlayers[i].unk_24)->pos.z - 50.0f);
                m = D_80106B40_35D120_name_52[i];
                m->rot.x = __sinf((y * 2 - 160) * DEG);
                m = D_80106B40_35D120_name_52[i];
                m->rot.z = __cosf((y * 2 - 160) * DEG);
                if (k == 9) {
                    s16 h = func_800797DC_7A3DC(0x103, i);

                    if (count != 1) {
                        func_80015710_16310(h, D_80106978_35CF58_name_52[i]);
                    }
                }
                HuPrcVSleep();
            }
        }
    }
    for (i = 0; i < 4; i++) {
        if (flags[i] != 0) {
            func_80049F90_4AB90(D_801067E0_35CDC0_name_52[i]);
            D_801067E0_35CDC0_name_52[i] = NULL;
        }
    }
    for (y = 0; y < 4; y++) {
        if (flags[y] != 0) {
            func_80059618_5A218(gPlayers[y].unk_24);
        }
    }
    HuPrcSleep(10);
    do {
        for (i = 0; i < 4; i++) {
            D_80106B40_35D120_name_52[i]->scale.x -= 0.1f;
            D_80106B40_35D120_name_52[i]->scale.y -= 0.1f;
            D_80106B40_35D120_name_52[i]->scale.z -= 0.1f;
            D_80106B40_35D120_name_52[i]->pos.y -= 20.0f;
        }
        HuPrcVSleep();
    } while (!(D_80106B40_35D120_name_52[0]->scale.x <= 0.05f));
    for (i = 0; i < 4; i++) {
        MBModelDispOff(D_80106B40_35D120_name_52[i]);
        HuVecCopyXYZ(&D_80106B40_35D120_name_52[i]->scale, 0.75f, 0.75f, 0.75f);
    }
    for (y = 0; y < 4; y++) {
        if (flags[y] != 0) {
            func_800595E8_5A1E8(gPlayers[y].unk_24, 3, 2);
        }
    }
}
#else
__asm__(".section .rodata");
const u32 D_80106AC8_35D0A8_name_52[2] = { 0x034A034A, 0x034A034A };
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_52_name/358DE0", func_801033D4_3599B4_name_52);
#endif

__asm__(".section .rodata");
const u32 D_80106AD8_35D0B8_name_52[4] = { 0x000005F9, 0x000005FA, 0x000005FB, 0x000005FC };

__asm__(".section .rodata");
const u32 D_80106AE8_35D0C8_name_52[4] = { 0x000005FE, 0x000005FF, 0x00000600, 0x00000601 };

__asm__(".section .rodata");
const u32 D_80106AF8_35D0D8_name_52[4] = { 0x00000603, 0x00000604, 0x00000605, 0x00000606 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_52_name/358DE0", func_80103814_359DF4_name_52);

/* The scene's end: tear down, then the results overlay for the board. */
void func_80105574_35BB54_name_52(void) {
    if (func_8008F618_90218() == 0) {
        func_80105C24_35C204_name_52();
        func_80105A48_35C028_name_52();
        func_8008CE5C_8DA5C();
        if (D_80106B30_35D110_name_52 == 6) {
            func_80102978_358F58_name_52();
        }
        if (D_801011FC_101DFC != 0) {
            omOvlReturnEx(1);
            return;
        }
        switch (GwSystem.current_board_index) {
        case 0:
        case 1:
        case 3:
            omOvlGotoEx(0x4F, 0, 0x92);
            break;
        case 2:
        case 4:
        case 5:
            omOvlGotoEx(0x50, 0, 0x92);
            break;
        case 6:
            omOvlGotoEx(0x51, 0, 0x92);
            break;
        }
        D_800FD866_FE466 = 1;
    }
}

void func_80105640_35BC20_name_52(omObjData* obj) {
    if (D_801011FC_101DFC != 0 || D_801067F0_35CDD0_name_52 != 0) {
        obj->func_ptr = func_80105574_35BB54_name_52;
    }
}

/* The players at their places, the host, the bonus star models and their effects. */
void func_80105674_35BC54_name_52(void) {
    Vec target;
    s32 i;

    MBModelInit();
    func_8005E2B8_5EEB8();
    func_800593C0_59FC0();
    for (i = 0; i < 4; i++) {
        MBPlayerModelCreate(i, D_80106960_35CF40_name_52[gPlayers[i].character], 2);
        func_8005ABC0_5B7C0(&gPlayers[i], 2, 0);
        ((MBModel*)gPlayers[i].unk_24)->pos.x = D_80106828_35CE08_name_52[i].x;
        ((MBModel*)gPlayers[i].unk_24)->pos.y = D_80106828_35CE08_name_52[i].y;
        ((MBModel*)gPlayers[i].unk_24)->pos.z = D_80106828_35CE08_name_52[i].z;
        target.x = D_80106828_35CE08_name_52[i].x;
        target.y = D_80106828_35CE08_name_52[i].y;
        target.z = D_80106828_35CE08_name_52[i].z + 500.0f;
        gPlayers[i].flags |= 2;
        func_80056658_57258(&((MBModel*)gPlayers[i].unk_24)->pos, &target, &((MBModel*)gPlayers[i].unk_24)->rot);
    }
    D_80106B34_35D114_name_52 = MBModelFileCreate(D_80106984_35CF64_name_52[D_80106B30_35D110_name_52], 0xD, 0.8f, 0.8f,
                                                  D_801069A0_35CF80_name_52[D_80106B30_35D110_name_52]);
    MBMotionSet(D_80106B34_35D114_name_52, 0, 2);
    D_80106B34_35D114_name_52->pos.x = D_80106864_35CE44_name_52.x;
    D_80106B34_35D114_name_52->pos.y = D_80106864_35CE44_name_52.y;
    D_80106B34_35D114_name_52->pos.z = D_80106864_35CE44_name_52.z;
    target.x = 0.0f;
    target.y = 0.0f;
    target.z = 2900.0f;
    func_80056658_57258(&D_80106B34_35D114_name_52->pos, &target, &D_80106B34_35D114_name_52->rot);
    for (i = 0; i < 4; i++) {
        if (i == 0) {
            D_80106B40_35D120_name_52[0] = func_80043510_44110(0x19, NULL);
            MBModelDispOff(D_80106B40_35D120_name_52[0]);
            D_80106B50_35D130_name_52[0] = func_80059370_s32();
            func_8002D124_2DD24((s16)D_80106B50_35D130_name_52[0]);
            func_800298A4_2A4A4((s16)D_80106B50_35D130_name_52[0], 4, 4);
        } else {
            D_80106B40_35D120_name_52[i] = MBModelParamCreate(D_80106B40_35D120_name_52[0]);
            MBModelDispOff(D_80106B40_35D120_name_52[i]);
            D_80106B50_35D130_name_52[i] = func_80027D3C_s32((s16)D_80106B50_35D130_name_52[0]);
        }
        HuVecCopyXYZ(&D_80106B40_35D120_name_52[i]->pos, ((MBModel*)gPlayers[i].unk_24)->pos.x,
                     ((MBModel*)gPlayers[i].unk_24)->pos.y + 200.0f, ((MBModel*)gPlayers[i].unk_24)->pos.z);
        HuVecCopyXYZ(&D_80106B40_35D120_name_52[i]->scale, 0.75f, 0.75f, 0.75f);
        D_80106B40_35D120_name_52[i]->rot.x = 0.0f;
        D_80106B40_35D120_name_52[i]->rot.z = 1.0f;
        func_80029714_2A314((s16)D_80106B50_35D130_name_52[i], ((MBModel*)gPlayers[i].unk_24)->pos.x,
                            ((MBModel*)gPlayers[i].unk_24)->pos.y + 200.0f, ((MBModel*)gPlayers[i].unk_24)->pos.z);
        func_800297E8_2A3E8((s16)D_80106B50_35D130_name_52[i], 0.2f, 0.2f, 0.2f);
        func_8002979C_2A39C((s16)D_80106B50_35D130_name_52[i], 0.0f, 0.0f, 0.0f);
    }
}

void func_80105A48_35C028_name_52(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_8005E260_5EE60(i);
    }
    func_800592E4_59EE4();
    MBModelKill(D_80106B34_35D114_name_52);
    for (i = 0; i < 4; i++) {
        MBModelKill(D_80106B40_35D120_name_52[i]);
        func_800283DC_28FDC((s16)D_80106B50_35D130_name_52[i]);
        if (D_801067FC_35CDDC_name_52[i] != NULL) {
            omDelObj(D_801067FC_35CDDC_name_52[i]);
        }
        if (D_801067E0_35CDC0_name_52[i] != NULL) {
            func_80049F90_4AB90(D_801067E0_35CDC0_name_52[i]);
        }
    }
    if (D_801067F4_35CDD4_name_52 != -1) {
        func_800283DC_28FDC((s16)D_801067F4_35CDD4_name_52);
        D_801067F4_35CDD4_name_52 = -1;
    }
    if (D_801067F8_35CDD8_name_52 != NULL) {
        omDelObj(D_801067F8_35CDD8_name_52);
        D_801067F8_35CDD8_name_52 = NULL;
    }
    func_80059400_5A000();
}

void func_80105B8C_35C16C_name_52(void) {
    func_80018E30_19A30(1);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_80050A30_51630(D_01164160);
}

void func_80105C24_35C204_name_52(void) {
    MBDBackKill();
    func_80050AE0_516E0();
}

/* The ending: a character walks in and speaks, the host and the players face it, then everyone walks
   off along the exit paths while the screen fades. */
void func_80105C48_35C228_name_52(void) {
    Vec target;
    void* paths[4];
    s32 win;
    s32 i;
    s32 t;
    u16 done;

    D_80106B38_35D118_name_52 = MBModelFileCreate(0x800A3, 0xD, 1.0f, 1.3f, D_801069D8_35CFB8_name_52);
    func_8005AB50_5B750(D_80106B38_35D118_name_52, 2, 6, D_80106A04_35CFE4_name_52);
    func_80043DAC_449AC(D_80106B38_35D118_name_52);
    D_80106B38_35D118_name_52->pos.x = D_80106A68_35D048_name_52.x;
    D_80106B38_35D118_name_52->pos.y = D_80106A68_35D048_name_52.y;
    D_80106B38_35D118_name_52->pos.z = D_80106A68_35D048_name_52.z;
    HuPrcSleep(10);
    MBMotionSet(D_80106B38_35D118_name_52, 7, 2);
    t = 0;
    while (func_8005A5E8_5B1E8(D_80106B38_35D118_name_52, &D_80106A74_35D054_name_52, 20.0f) == 0) {
        for (i = 0; i < 4; i++) {
            func_8005A7E8_5B3E8(gPlayers[i].unk_24, &D_80106B38_35D118_name_52->pos, 5.0f);
        }
        func_8005A7E8_5B3E8(D_80106B34_35D114_name_52, &D_80106B38_35D118_name_52->pos, 8.0f);
        t++;
        HuPrcVSleep();
        if (t == 16) {
            func_8008DACC_8E6CC(1, D_80106B74_35D154_name_52, D_80106A80_35D060_name_52[D_80106B30_35D110_name_52]);
            win = func_8005AAC0_5B6C0(72, 50, D_80106B74_35D154_name_52[0], D_80106B74_35D154_name_52[1]);
            func_800890CC_89CCC(win, D_80106A80_35D060_name_52[D_80106B30_35D110_name_52], -1, -1);
            PlaySound(0xE6);
        }
    }
    MBMotionShiftSet(D_80106B38_35D118_name_52, 8, 0, 10, 2);
    target.x = 0.0f;
    target.y = 0.0f;
    target.z = 2050.0f;
    while (func_8005A7E8_5B3E8(D_80106B38_35D118_name_52, &target, 8.0f) == 0) {
        HuPrcVSleep();
    }
    HuPrcSleep(30);
    func_8005762C_5822C(win);
    func_800794A8_7A0A8(120);
    for (i = 0; i < 4; i++) {
        MBMotionShiftSet(gPlayers[i].unk_24, 7, 0, 5, 2);
        paths[i] = func_8005A718_5B318(gPlayers[i].unk_24, 15.0f, D_80106A50_35D030_name_52[i], D_80106A58_35D038_name_52[i]);
    }
    t = 0;
    while (TRUE) {
        done = 0;
        for (i = 0; i < 4; i++) {
            if (func_8005A778_5B378(paths[i]) != 0) {
                done++;
            }
        }
        if (done == 4) {
            break;
        }
        func_8005A7E8_5B3E8(D_80106B38_35D118_name_52, &((MBModel*)gPlayers[0].unk_24)->pos, 6.0f);
        func_8005A7E8_5B3E8(D_80106B34_35D114_name_52, &((MBModel*)gPlayers[0].unk_24)->pos, 6.0f);
        HuPrcVSleep();
        if (t == 40) {
            InitFadeOut(2, 20);
        }
        if (t == 60) {
            break;
        }
        t++;
    }
    for (i = 0; i < 4; i++) {
        HuMemMemoryFreePerm(paths[i]);
    }
    HuPrcSleep(20);
}

/* The winner (D_800F8CE4_F98E4[0]) is named, walks to the front and faces the camera; a star falls
   onto them in a burst, the character's fanfare plays and "YOU ARE THE WINNER" is shown until a
   human presses A or B (90 frames at most), then the fade. */
void func_8010604C_35C62C_name_52(void) {
    void* data;
    s16 form;
    MBModel* model;
    omObjData* star;
    omObjData* burst;
    s32 win;
    s32 i;
    s32 t;
    f32 s;

    data = DataRead(0xA01ED);
    form = func_8003DF08_3EB08(data);
    HuMemMemoryFreePerm(data);
    model = gPlayers[D_800F8CE4_F98E4[0]].unk_24;
    star = omAddObj(0x1F4, 1, 0, -1, NULL);
    star->model[0] = LoadFormFile(0xA0251, 0x6A9);
    omSetTra(star, model->pos.x, 600.0f, model->pos.z);
    star->rot.x = star->rot.z = 0.0f;
    omSetSca(star, 1.0f, 1.0f, 1.0f);
    burst = omAddObj(0x1F4, 2, 0, -1, NULL);
    burst->model[1] = func_80020EBC_21ABC((void*)-1, 0x68D, 8);
    D_800F86D8_F92D8[burst->model[1]].unk02 = form;
    func_80021160_21D60(burst->model[1], 6, 0);
    burst->model[0] = D_800F86D8_F92D8[burst->model[1]].unk00;
    HmfModelObjAttrSet(burst->model[0], 0x20000000, 0x20000000);
    func_80021250_21E50(burst->model[1], 0xFA, 0xFF, 0xFF);
    func_800211E8_21DE8(burst->model[1], 0x90);
    omSetSca(burst, 0.0f, 0.0f, 1.0f);
    burst->rot.y = burst->rot.x = burst->rot.z = 0.0f;
    func_8008D974_8E574(D_800CC5F8[gPlayers[D_800F8CE4_F98E4[0]].character], 0);
    func_8008DACC_8E6CC(1, D_80106B74_35D154_name_52, 0x6CB);
    win = func_8005AAC0_5B6C0(40, 45, D_80106B74_35D154_name_52[0], D_80106B74_35D154_name_52[1]);
    func_80089308_89F08(win, D_800CC5F8[gPlayers[D_800F8CE4_F98E4[0]].character], 0);
    func_800890CC_89CCC(win, 0x6CB, -1, -1);
    ShowTextWindow(win);
    func_80057DA4_589A4(win);
    func_8005762C_5822C(win);
    func_8005ACD0_5B8D0(&gPlayers[D_800F8CE4_F98E4[0]], 12);
    MBMotionShiftSet(model, 8, 0, 4, 0);
    HuPrcSleep(34);
    MBMotionShiftSet(model, -1, 0, 4, 0);
    func_800794A8_7A0A8(60);
    while (func_8005A7E8_5B3E8(model, &D_80106858_35CE38_name_52, 10.0f) == 0) {
        HuPrcVSleep();
    }
    MBMotionShiftSet(model, 6, 0, 4, 2);
    while (func_8005A5E8_5B1E8(model, &D_80106858_35CE38_name_52, 15.0f) == 0) {
        HuPrcVSleep();
    }
    star->trans.x = model->pos.x;
    star->trans.z = model->pos.z;
    while (func_8005A7E8_5B3E8(model, &((HuCamera*)D_800FD2A8_FDEA8)->pos, 10.0f) == 0) {
        HuPrcVSleep();
    }
    MBMotionShiftSet(model, -1, 0, 4, 0);
    for (t = 0, i = 0; i < 60; i++) {
        if (++t == 10) {
            PlayMusic(0x10);
        }
        star->trans.y += -6.1666665f;
        HuPrcVSleep();
    }
    omSetTra(burst, star->trans.x - 20.0f, star->trans.y + 80.0f, star->trans.z + 30.0f);
    func_800298A4_2A4A4(burst->model[0], 4, 0);
    for (i = 0; i < 10; i++) {
        if (i < 5) {
            s = burst->scale.x + 0.2f;
        } else {
            s = burst->scale.x - 0.2f;
        }
        burst->scale.x = s;
        burst->scale.y = s;
        HuPrcVSleep();
    }
    func_8002308C_23C8C(burst->model[1]);
    omDelObj(burst);
    omAddPrcObj(func_8010670C_35CCEC_name_52, 0x5010, 0x2000, 0)->user_data = star;
    func_8005ACD0_5B8D0(&gPlayers[D_800F8CE4_F98E4[0]], 12);
    MBMotionShiftSet(model, 5, 0, 4, 0);
    func_800732B0_73EB0(D_80106960_35CF40_name_52[gPlayers[D_800F8CE4_F98E4[0]].character][6]);
    HuPrcSleep(94);
    func_801028C4_358EA4_name_52();
    HuPrcSleep(60);
    for (i = 0; i < 4; i++) {
        if (!(gPlayers[i].flags & 1)) {
            break;
        }
    }
    if (i != 4) {
        for (t = 0; t < 90; t++) {
            for (i = 0; i < 4; i++) {
                if (!(gPlayers[i].flags & 1) && (ContBtnTrg[gPlayers[i].port] & 0xC000)) {
                    break;
                }
            }
            if (i != 4) {
                break;
            }
            HuPrcVSleep();
        }
    }
    InitFadeOut(0, 20);
    HuPrcSleep(20);
}

/* The star's process: it spins and bobs above the winner. */
void func_8010670C_35CCEC_name_52(void) {
    omObjData* obj = HuPrcCurrentGet()->user_data;
    f32 a = 180.0f;

    while (TRUE) {
        if ((obj->rot.y += 4.0f) >= 360.0f) {
            obj->rot.y -= 360.0f;
        }
        obj->trans.y = HuMathSin(a) * 10.0f + 230.0f;
        if ((a += 10.0f) >= 360.0f) {
            a -= 360.0f;
        }
        HuPrcVSleep();
    }
}
