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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_52_name/358DE0", func_80105C48_35C228_name_52);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_52_name/358DE0", func_8010604C_35C62C_name_52);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_52_name/358DE0", func_8010670C_35CCEC_name_52);
