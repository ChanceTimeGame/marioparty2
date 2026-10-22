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

__asm__(".section .rodata");
const u32 D_80106AC8_35D0A8_name_52[2] = { 0x034A034A, 0x034A034A };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_52_name/358DE0", func_801033D4_3599B4_name_52);

__asm__(".section .rodata");
const u32 D_80106AD8_35D0B8_name_52[4] = { 0x000005F9, 0x000005FA, 0x000005FB, 0x000005FC };

__asm__(".section .rodata");
const u32 D_80106AE8_35D0C8_name_52[4] = { 0x000005FE, 0x000005FF, 0x00000600, 0x00000601 };

__asm__(".section .rodata");
const u32 D_80106AF8_35D0D8_name_52[4] = { 0x00000603, 0x00000604, 0x00000605, 0x00000606 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_52_name/358DE0", func_80103814_359DF4_name_52);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_52_name/358DE0", func_80105574_35BB54_name_52);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_52_name/358DE0", func_80105640_35BC20_name_52);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_52_name/358DE0", func_80105674_35BC54_name_52);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_52_name/358DE0", func_80105A48_35C028_name_52);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_52_name/358DE0", func_80105B8C_35C16C_name_52);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_52_name/358DE0", func_80105C24_35C204_name_52);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_52_name/358DE0", func_80105C48_35C228_name_52);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_52_name/358DE0", func_8010604C_35C62C_name_52);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_52_name/358DE0", func_8010670C_35CCEC_name_52);
