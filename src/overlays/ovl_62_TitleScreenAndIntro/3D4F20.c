#include "ovl_62.h"

s32 func_80102A00_3D4F20_TitleScreenAndIntro(void) {
    return 0;
}

void func_80102A08_3D4F28_TitleScreenAndIntro(void) {
    D_8011265C_3E4B7C_TitleScreenAndIntro = func_801059F0_3D7F10_TitleScreenAndIntro();
    D_80112668_3E4B88_TitleScreenAndIntro = func_80102A68_3D4F88_TitleScreenAndIntro();
}

void func_80102A38_3D4F58_TitleScreenAndIntro(void) {
    D_80112668_3E4B88_TitleScreenAndIntro = func_80102AF8_3D5018_TitleScreenAndIntro();
    D_8011265C_3E4B7C_TitleScreenAndIntro = func_8010D3C0_3DF8E0_TitleScreenAndIntro();
}

omObjData* func_80102A68_3D4F88_TitleScreenAndIntro(void) {
    omObjData* obj;

    obj = omAddObj(0x1001, 16, 0, -1, func_80102AB4_3D4FD4_TitleScreenAndIntro);
    func_80102AB4_3D4FD4_TitleScreenAndIntro(obj);
    return obj;
}

void func_80102AB4_3D4FD4_TitleScreenAndIntro(omObjData* obj) {
    func_80103054_3D5574_TitleScreenAndIntro(0x62, 0, 0x192);
    D_80111D40_3E4260_TitleScreenAndIntro = 0;
    obj->func_ptr = func_80102C28_3D5148_TitleScreenAndIntro;
}

omObjData* func_80102AF8_3D5018_TitleScreenAndIntro(void) {
    omObjData* obj;

    obj = omAddObj(0x1000, 16, 0, -1, func_80102B44_3D5064_TitleScreenAndIntro);
    func_80102B44_3D5064_TitleScreenAndIntro(obj);
    return obj;
}

void func_80102B44_3D5064_TitleScreenAndIntro(omObjData* obj) {
    func_80103054_3D5574_TitleScreenAndIntro(0x62, 1, 0x192);
    D_80111D40_3E4260_TitleScreenAndIntro = 0;
    obj->func_ptr = func_80102DC0_3D52E0_TitleScreenAndIntro;
}

/* START (main's flag) ends a scene that is waiting in state 3 or 4 */
void func_80102B88_3D50A8_TitleScreenAndIntro(void) {
    if (D_80111D40_3E4260_TitleScreenAndIntro < 5) {
        if (D_80111D40_3E4260_TitleScreenAndIntro >= 3) {
            if (D_801011FC_101DFC == 1) {
                func_80102BD0_3D50F0_TitleScreenAndIntro();
            }
        }
    }
}

void func_80102BD0_3D50F0_TitleScreenAndIntro(void) {
    if (D_80111D40_3E4260_TitleScreenAndIntro < 5) {
        if (D_80111D40_3E4260_TitleScreenAndIntro >= 3) {
            D_80111D40_3E4260_TitleScreenAndIntro = 5;
        }
    }
}

void func_80102BFC_3D511C_TitleScreenAndIntro(s32 state) {
    if (D_80111D40_3E4260_TitleScreenAndIntro < 5) {
        if (D_80111D40_3E4260_TitleScreenAndIntro >= 3) {
            D_80111D40_3E4260_TitleScreenAndIntro = state;
        }
    }
}

/* the opening's object: 3 waits for the script's end (5: back to the title) and START (4 -> 8:
   to the main menu) */
void func_80102C28_3D5148_TitleScreenAndIntro(omObjData* obj) {
    func_80102B88_3D50A8_TitleScreenAndIntro();
    switch (D_80111D40_3E4260_TitleScreenAndIntro) {
        case 0:
            D_80111D40_3E4260_TitleScreenAndIntro = 1;
            break;
        case 1:
            InitFadeIn(0, 16);
            D_80111D40_3E4260_TitleScreenAndIntro = 2;
            break;
        case 2:
            if (func_8008F618_90218() == 0) {
                D_80111D40_3E4260_TitleScreenAndIntro = 3;
            }
            break;
        case 3:
            if (func_80102FD8_3D54F8_TitleScreenAndIntro() != 0) {
                D_80111D40_3E4260_TitleScreenAndIntro = 5;
            }
            break;
        case 5:
            InitFadeOut(0, 20);
            func_800794A8_7A0A8(20);
            D_80111D40_3E4260_TitleScreenAndIntro = 6;
            break;
        case 6:
            if (func_8008F618_90218() == 0) {
                D_80111D40_3E4260_TitleScreenAndIntro = 7;
            }
            break;
        case 7:
            func_80102F64_3D5484_TitleScreenAndIntro(obj);
            func_80103070_3D5590_TitleScreenAndIntro();
            break;
        case 4:
            if (func_80102FD8_3D54F8_TitleScreenAndIntro() != 0) {
                D_80111D40_3E4260_TitleScreenAndIntro = 8;
            }
            break;
        case 8:
            InitFadeOut(0, 20);
            func_800794A8_7A0A8(20);
            D_80111D40_3E4260_TitleScreenAndIntro = 9;
            break;
        case 9:
            if (func_8008F618_90218() == 0) {
                D_80111D40_3E4260_TitleScreenAndIntro = 10;
            }
            break;
        case 10:
            func_80102F64_3D5484_TitleScreenAndIntro(obj);
            func_80103054_3D5574_TitleScreenAndIntro(0x5B, 0, 0x1081);
            func_801030A0_3D55C0_TitleScreenAndIntro();
            omOvlHisChg(1, 0x62, 0, 0x192);
            break;
    }
}

/* the title screen's object: 3 waits for START once the title is up (8010D484) -> 8 -> the main
   menu; 5 (80102BD0, the title timing out) fades to the boot logos' second entry */
void func_80102DC0_3D52E0_TitleScreenAndIntro(omObjData* obj) {
    func_80102B88_3D50A8_TitleScreenAndIntro();
    switch (D_80111D40_3E4260_TitleScreenAndIntro) {
        case 0:
            D_80111D40_3E4260_TitleScreenAndIntro = 1;
            func_8010D478_3DF998_TitleScreenAndIntro();
            break;
        case 1:
            InitFadeIn(0, 16);
            D_80111D40_3E4260_TitleScreenAndIntro = 2;
            break;
        case 2:
            if (func_8008F618_90218() == 0) {
                D_80111D40_3E4260_TitleScreenAndIntro = 3;
            }
            break;
        case 3:
            if (func_80102FD8_3D54F8_TitleScreenAndIntro() != 0 && func_8010D484_3DF9A4_TitleScreenAndIntro() != 0) {
                D_80111D40_3E4260_TitleScreenAndIntro = 8;
            }
            break;
        case 5:
            InitFadeOut(0, 20);
            func_800794A8_7A0A8(20);
            D_80111D40_3E4260_TitleScreenAndIntro = 6;
            break;
        case 6:
            if (func_8008F618_90218() == 0) {
                D_80111D40_3E4260_TitleScreenAndIntro = 7;
            }
            break;
        case 7:
            func_80102F64_3D5484_TitleScreenAndIntro(obj);
            func_80103054_3D5574_TitleScreenAndIntro(0x57, 1, 0x92);
            func_80103070_3D5590_TitleScreenAndIntro();
            break;
        case 8:
            InitFadeOut(0, 20);
            func_800794A8_7A0A8(20);
            D_80111D40_3E4260_TitleScreenAndIntro = 9;
            break;
        case 9:
            if (func_8008F618_90218() == 0) {
                D_80111D40_3E4260_TitleScreenAndIntro = 10;
            }
            break;
        case 10:
            func_80102F64_3D5484_TitleScreenAndIntro(obj);
            func_80103054_3D5574_TitleScreenAndIntro(0x5B, 0, 0x1081);
            func_801030A0_3D55C0_TitleScreenAndIntro();
            omOvlHisChg(1, 0x62, 0, 0x192);
            break;
    }
}

/* tear the scene down before leaving */
void func_80102F64_3D5484_TitleScreenAndIntro(omObjData* obj) {
    s32 i;

    func_8010DF90_3E04B0_TitleScreenAndIntro();
    func_80105234_3D7754_TitleScreenAndIntro();
    MBDBackKill();
    func_80050AE0_516E0();
    func_80047B78_48778();
    func_80059400_5A000();
    for (i = 0; i < 4; i++) {
        func_8005E260_5EE60(i);
    }
    func_8008CE5C_8DA5C();
    func_80079868_7A468();
}

/* START on controller 1 (once main allows input).
   NON_MATCHING: retail clears the result after the pad call (v0 in a delay slot); this keeps it in
   s0 across the call (masked 6). */
#ifdef NON_MATCHING
s32 func_80102FD8_3D54F8_TitleScreenAndIntro(void) {
    if (func_80068448_69048() == 0) {
        return 0;
    }
    return HuGetPadInserted(0) != 0 && (ContBtnTrg[0] & 0x1000) != 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80102FD8_3D54F8_TitleScreenAndIntro);
#endif

s32 func_80103028_3D5548_TitleScreenAndIntro(void) {
    return func_80068448_69048() != 0;
}

s32 func_80103048_3D5568_TitleScreenAndIntro(void) {
    return D_80111D40_3E4260_TitleScreenAndIntro;
}

void func_80103054_3D5574_TitleScreenAndIntro(s32 ovl, s16 event, u16 stat) {
    D_80111D44_3E4264_TitleScreenAndIntro = ovl;
    D_80111D48_3E4268_TitleScreenAndIntro = event;
    D_80111D4A_3E426A_TitleScreenAndIntro = stat;
}

void func_80103070_3D5590_TitleScreenAndIntro(void) {
    omOvlGotoEx(D_80111D44_3E4264_TitleScreenAndIntro, D_80111D48_3E4268_TitleScreenAndIntro, D_80111D4A_3E426A_TitleScreenAndIntro);
}

void func_801030A0_3D55C0_TitleScreenAndIntro(void) {
    omOvlCallEx(D_80111D44_3E4264_TitleScreenAndIntro, D_80111D48_3E4268_TitleScreenAndIntro, D_80111D4A_3E426A_TitleScreenAndIntro);
}

void func_801030D0_3D55F0_TitleScreenAndIntro(void) {
    func_80103498_3D59B8_TitleScreenAndIntro();
    func_801038DC_3D5DFC_TitleScreenAndIntro();
    D_80111D50_3E4270_TitleScreenAndIntro = -1;
}

void func_80103100_3D5620_TitleScreenAndIntro(void) {
    if (D_80112148_3E4668_TitleScreenAndIntro != NULL) {
        HuMemFree(D_80112148_3E4668_TitleScreenAndIntro);
    }
}

/* open a message window (MP1 OpeningScene func_800FC528) */
s32 func_8010312C_3D564C_TitleScreenAndIntro(s32 x, s32 y, s32 cols, s32 rows) {
    s16 temp_v0;
    s32 win;

    temp_v0 = func_800888A8_894A8(x, y, cols * 10 + 16, rows * 14 + 6, 0, 8);
    win = temp_v0;
    func_80089A48_8A648(win, 0);
    func_80089B2C_8A72C(win, 0);
    func_8008D88C_8E48C(temp_v0);
    return temp_v0;
}

/* show message mess in the scene's window (created on first use); wait -1: until it is closed,
   > 0: that many frames */
void func_801031D0_3D56F0_TitleScreenAndIntro(s32 mess, s32 wait) {
    TextWindow* window;

    if (D_80111D50_3E4270_TitleScreenAndIntro == -1) {
        D_80111D50_3E4270_TitleScreenAndIntro = func_8010312C_3D564C_TitleScreenAndIntro(
            D_80111030_3E3550_TitleScreenAndIntro.x, D_80111030_3E3550_TitleScreenAndIntro.y,
            D_80111030_3E3550_TitleScreenAndIntro.cols, D_80111030_3E3550_TitleScreenAndIntro.rows);
        func_80089CAC_8A8AC((s16)D_80111D50_3E4270_TitleScreenAndIntro, 2, 255, 0, 0);
        func_80089CAC_8A8AC((s16)D_80111D50_3E4270_TitleScreenAndIntro, 4, 0, 144, 0);
        func_80089CAC_8A8AC((s16)D_80111D50_3E4270_TitleScreenAndIntro, 5, 0, 176, 192);
        func_80089CAC_8A8AC((s16)D_80111D50_3E4270_TitleScreenAndIntro, 6, 255, 173, 0);
        func_80089DA0_8A9A0((s16)D_80111D50_3E4270_TitleScreenAndIntro, 192, 192, 192);
        func_8008D530_8E130((s16)D_80111D50_3E4270_TitleScreenAndIntro, 240, 240, 224);
        func_80089B2C_8A72C((s16)D_80111D50_3E4270_TitleScreenAndIntro, 255);
        func_80089C78_8A878((s16)D_80111D50_3E4270_TitleScreenAndIntro, 1);
        window = &D_800F920C_F9E0C[D_80111D50_3E4270_TitleScreenAndIntro];
        SprPrioSet(window->unk_6C, func_80089404_8A004((s16)D_80111D50_3E4270_TitleScreenAndIntro, 0xE0015, 131, 16, 0), 15000);
    }
    func_8008AD44_8B944((s16)D_80111D50_3E4270_TitleScreenAndIntro);
    func_80089DA0_8A9A0((s16)D_80111D50_3E4270_TitleScreenAndIntro, 192, 192, 192);
    func_8008D530_8E130((s16)D_80111D50_3E4270_TitleScreenAndIntro, 240, 240, 224);
    func_80089C78_8A878((s16)D_80111D50_3E4270_TitleScreenAndIntro, 1);
    func_80089B2C_8A72C((s16)D_80111D50_3E4270_TitleScreenAndIntro, 255);
    func_800890CC_89CCC((s16)D_80111D50_3E4270_TitleScreenAndIntro, mess, -1, -1);
    func_8008D6F0_8E2F0((s16)D_80111D50_3E4270_TitleScreenAndIntro);
    if (wait == -1) {
        while (func_8008BA30_8C630((s16)D_80111D50_3E4270_TitleScreenAndIntro) != 0) {
            HuPrcVSleep();
        }
    } else if (wait > 0) {
        HuPrcSleep(wait);
    }
}

/* show a message and close it after wait frames (0: when the player closes it); keep: leave it
   open and return at once (MP1 func_800FC6BC) */
void func_801033F8_3D5918_TitleScreenAndIntro(s32 mess, s32 wait, s32 keep) {
    if (keep != 0) {
        func_801031D0_3D56F0_TitleScreenAndIntro(mess, wait);
        return;
    }
    func_801031D0_3D56F0_TitleScreenAndIntro(mess, 0);
    if (wait == 0) {
        while (func_8008BA30_8C630((s16)D_80111D50_3E4270_TitleScreenAndIntro) != 0) {
            HuPrcVSleep();
        }
    } else {
        HuPrcSleep(wait);
    }
    func_8008D5D8_8E1D8((s16)D_80111D50_3E4270_TitleScreenAndIntro);
}

void func_80103478_3D5998_TitleScreenAndIntro(void) {
    func_8008D5D8_8E1D8((s16)D_80111D50_3E4270_TitleScreenAndIntro);
}

void func_80103498_3D59B8_TitleScreenAndIntro(void) {
    D_80111D60_3E4280_TitleScreenAndIntro = 0;
}

/* the full-screen fill (MP1 OpeningScene func_800FCAB0..func_800FCECC) */
void func_801034A4_3D59C4_TitleScreenAndIntro(u8 r, u8 g, u8 b, u8 a) {
    D_80111D5C_3E427C_TitleScreenAndIntro[0] = r;
    D_80111D5C_3E427C_TitleScreenAndIntro[1] = g;
    D_80111D5C_3E427C_TitleScreenAndIntro[2] = b;
    D_80111D5C_3E427C_TitleScreenAndIntro[3] = a;
}

/* fade in from black: rot.x counts down from rot.y */
void func_801034C0_3D59E0_TitleScreenAndIntro(omObjData* obj) {
    f32 temp_f20;
    f32 var_f2;

    temp_f20 = obj->rot.x;
    var_f2 = temp_f20 / obj->rot.y;
    if (var_f2 < 0.0f) {
        var_f2 = 0.0f;
    }
    func_801034A4_3D59C4_TitleScreenAndIntro(0, 0, 0, (u32)(var_f2 * 255.0f));
    temp_f20 -= 1.0f;
    if (temp_f20 < 0.0f) {
        temp_f20 = 0.0f;
    }
    obj->rot.x = temp_f20;
}

omObjData* func_801035AC_3D5ACC_TitleScreenAndIntro(s32 time) {
    f32 temp_f0;
    omObjData* temp_v0;
    s16 temp_s2;

    temp_s2 = func_801038A0_3D5DC0_TitleScreenAndIntro();
    func_801034A4_3D59C4_TitleScreenAndIntro(0, 0, 0, 255);
    temp_v0 = omAddObj(0x1000, 0, 0, -1, func_801034C0_3D59E0_TitleScreenAndIntro);
    temp_f0 = time;
    omSetRot(temp_v0, temp_f0, temp_f0, 0.0f);
    D_80111D60_3E4280_TitleScreenAndIntro = temp_s2;
    return temp_v0;
}

/* fade out to black: rot.x counts up to rot.y */
void func_8010364C_3D5B6C_TitleScreenAndIntro(omObjData* obj) {
    f32 temp_f20;
    f32 temp_f22;
    f32 var_f2;

    temp_f20 = obj->rot.x;
    temp_f22 = obj->rot.y;
    var_f2 = temp_f20 / temp_f22;
    if (temp_f22 < var_f2) {
        var_f2 = temp_f22;
    }
    func_801034A4_3D59C4_TitleScreenAndIntro(0, 0, 0, (u32)(var_f2 * 255.0f));
    temp_f20 += 1.0f;
    if (temp_f22 < temp_f20) {
        temp_f20 = temp_f22;
    }
    obj->rot.x = temp_f20;
}

omObjData* func_80103730_3D5C50_TitleScreenAndIntro(s32 time) {
    omObjData* temp_v0;
    s16 temp_s2;

    temp_s2 = func_801038A0_3D5DC0_TitleScreenAndIntro();
    func_801034A4_3D59C4_TitleScreenAndIntro(0, 0, 0, 255);
    temp_v0 = omAddObj(0x1000, 0, 0, -1, func_8010364C_3D5B6C_TitleScreenAndIntro);
    omSetRot(temp_v0, 0.0f, (f32)time, 0.0f);
    D_80111D60_3E4280_TitleScreenAndIntro = temp_s2;
    return temp_v0;
}

void func_801037D0_3D5CF0_TitleScreenAndIntro(Gfx** gfx) {
    gSPDisplayList((*gfx)++, D_80111040_3E3560_TitleScreenAndIntro);
    gDPSetRenderMode((*gfx)++, 0x5041C8, 0);
    gDPSetCombineMode((*gfx)++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetPrimColor((*gfx)++, 0, 0, D_80111D5C_3E427C_TitleScreenAndIntro[0], D_80111D5C_3E427C_TitleScreenAndIntro[1],
                    D_80111D5C_3E427C_TitleScreenAndIntro[2], D_80111D5C_3E427C_TitleScreenAndIntro[3]);
    gDPFillRectangle((*gfx)++, 0, 0, 320, 240);
}

s16 func_801038A0_3D5DC0_TitleScreenAndIntro(void) {
    return func_8002838C_28F8C(0, func_801037D0_3D5CF0_TitleScreenAndIntro, 2);
}

s32 func_801038D0_3D5DF0_TitleScreenAndIntro(void) {
    return D_800FDBE0_FE7E0;
}

/* set up the light mask: the default stamp image (file 0xE000F, big-endian header), three
   160x128 masks, all stamps off, black at 0x60 alpha */
void func_801038DC_3D5DFC_TitleScreenAndIntro(void) {
    Ovl62Stamp* stamp;
    u8* file;
    u8* img;
    s32 size;
    s32 i;

    file = DataRead(0xE000F);
    img = file + (file[2] << 8) + file[3];
    D_8011268C_3E4BAC_TitleScreenAndIntro.w = (img[4] << 8) + img[5];
    D_8011268C_3E4BAC_TitleScreenAndIntro.h = (img[6] << 8) + img[7];
    img = file + (img[2] << 8) + img[3];
    size = D_8011268C_3E4BAC_TitleScreenAndIntro.w * D_8011268C_3E4BAC_TitleScreenAndIntro.h;
    D_8011268C_3E4BAC_TitleScreenAndIntro.data = func_80027154_27D54(size, 0x7918);
    bcopy(img, D_8011268C_3E4BAC_TitleScreenAndIntro.data, size);
    DataClose(file);
    D_80111D54_3E4274_TitleScreenAndIntro = 160;
    D_80111D58_3E4278_TitleScreenAndIntro = 128;
    D_801138A0_3E5DC0_TitleScreenAndIntro = D_80112148_3E4668_TitleScreenAndIntro = func_80027154_27D54(160 * 128 * 3, 0x7918);
    func_8010415C_3D667C_TitleScreenAndIntro(255);
    for (i = 0; i < 8; i++) {
        stamp = &D_80112060_3E4580_TitleScreenAndIntro[i];
        stamp->y = 0;
        D_80112060_3E4580_TitleScreenAndIntro[i].x = 0;
        D_80112060_3E4580_TitleScreenAndIntro[i].data = NULL;
    }
    func_80103AC0_3D5FE0_TitleScreenAndIntro(0, 0, 0, 0x60);
    D_80111D62_3E4282_TitleScreenAndIntro = func_8010433C_3D685C_TitleScreenAndIntro();
}

void func_80103A54_3D5F74_TitleScreenAndIntro(void) {
    s32 i;

    func_800283DC_28FDC(D_80111D62_3E4282_TitleScreenAndIntro);
    for (i = 0; i < 8; i++) {
        D_80112060_3E4580_TitleScreenAndIntro[i].data = NULL;
    }
    func_80027340_27F40(D_8011268C_3E4BAC_TitleScreenAndIntro.data);
    func_80027340_27F40(D_80112148_3E4668_TitleScreenAndIntro);
    D_80112148_3E4668_TitleScreenAndIntro = NULL;
}

void func_80103AC0_3D5FE0_TitleScreenAndIntro(u8 r, u8 g, u8 b, u8 a) {
    D_80112060_3E4580_TitleScreenAndIntro[0].color[0] = r;
    D_80112060_3E4580_TitleScreenAndIntro[0].color[1] = g;
    D_80112060_3E4580_TitleScreenAndIntro[0].color[2] = b;
    D_80112060_3E4580_TitleScreenAndIntro[0].color[3] = a;
}

void func_80103ADC_3D5FFC_TitleScreenAndIntro(s32 i, s32 x, s32 y) {
    D_80112060_3E4580_TitleScreenAndIntro[i].x = x;
    D_80112060_3E4580_TitleScreenAndIntro[i].y = y;
}

/* place stamp i over screen point (x, y) (320x240 to the 160x128 mask, centred on a 32x32
   image); data NULL: the default image */
void func_80103B04_3D6024_TitleScreenAndIntro(s32 i, s32 x, s32 y, u8* data) {
    D_80112060_3E4580_TitleScreenAndIntro[i].w = D_8011268C_3E4BAC_TitleScreenAndIntro.w;
    D_80112060_3E4580_TitleScreenAndIntro[i].h = D_8011268C_3E4BAC_TitleScreenAndIntro.h;
    D_80112060_3E4580_TitleScreenAndIntro[i].x = x * (1.0 / 1.33f) - 16.0;
    D_80112060_3E4580_TitleScreenAndIntro[i].y = y * (1.0 / 1.33f) - 16.0 - 8.0;
    if (data == NULL) {
        D_80112060_3E4580_TitleScreenAndIntro[i].data = D_8011268C_3E4BAC_TitleScreenAndIntro.data;
    } else {
        D_80112060_3E4580_TitleScreenAndIntro[i].data = data;
    }
}

void func_80103BD4_3D60F4_TitleScreenAndIntro(s32 i) {
    D_80112060_3E4580_TitleScreenAndIntro[i].data = NULL;
}

/* draw the light mask: rebuild this frame buffer's mask from the active stamps, then draw it in
   32x32 tiles scaled to the screen (1.33 x 2) */
void func_80103BF0_3D6110_TitleScreenAndIntro(Gfx** gfx) {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
    u8* mask;
    u8* tex;
    s32 i;
    s32 x;
    s32 y;

    r = D_80112060_3E4580_TitleScreenAndIntro[0].color[0];
    g = D_80112060_3E4580_TitleScreenAndIntro[0].color[1];
    b = D_80112060_3E4580_TitleScreenAndIntro[0].color[2];
    a = D_80112060_3E4580_TitleScreenAndIntro[0].color[3];
    if (a == 0.0f) {
        return;
    }
    mask = D_801138A0_3E5DC0_TitleScreenAndIntro =
        D_80112148_3E4668_TitleScreenAndIntro + D_80111D58_3E4278_TitleScreenAndIntro * D_80111D54_3E4274_TitleScreenAndIntro * func_801038D0_3D5DF0_TitleScreenAndIntro();
    func_8010415C_3D667C_TitleScreenAndIntro(255);
    for (i = 0; i < 8; i++) {
        if (D_80112060_3E4580_TitleScreenAndIntro[i].data != NULL) {
            func_8010421C_3D673C_TitleScreenAndIntro(&D_80112060_3E4580_TitleScreenAndIntro[i], D_80112060_3E4580_TitleScreenAndIntro[i].x,
                                                     D_80112060_3E4580_TitleScreenAndIntro[i].y);
        }
    }
    gSPDisplayList((*gfx)++, D_80111090_3E35B0_TitleScreenAndIntro);
    gDPSetAlphaCompare((*gfx)++, G_AC_THRESHOLD);
    gDPSetBlendColor((*gfx)++, 0, 0, 0, 1);
    gDPSetScissor((*gfx)++, G_SC_NON_INTERLACE, 0, 0, 320, 240);
    gDPSetTextureFilter((*gfx)++, G_TF_BILERP);
    gDPSetRenderMode((*gfx)++, 0x504240, 0);
    gDPSetCombineLERP((*gfx)++, 0, 0, 0, PRIMITIVE, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, PRIMITIVE, PRIMITIVE, 0, TEXEL0, 0);
    gDPSetPrimColor((*gfx)++, 0, 0, r, g, b, a);
    for (y = 0; y < D_80111D58_3E4278_TitleScreenAndIntro; y += 32) {
        for (x = 0; x < D_80111D54_3E4274_TitleScreenAndIntro; x += 32) {
            tex = &mask[x + y * D_80111D54_3E4274_TitleScreenAndIntro];
            gDPLoadTextureTile((*gfx)++, tex, G_IM_FMT_I, G_IM_SIZ_8b,
                               D_80111D54_3E4274_TitleScreenAndIntro, D_80111D58_3E4278_TitleScreenAndIntro, 0, 0, 32, 32, 0,
                               G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            gSPScisTextureRectangle((*gfx)++, x * 8 * 1.33f, y * 8 * 1.33f, (x + 32) * 8 * 1.33f, (y + 32) * 8 * 1.33f,
                                    G_TX_RENDERTILE, 0, 0, 0x180, 0x180);
        }
    }
}

/* fill the current mask with value.
   NON_MATCHING: retail loads D_801138A0 after the size's operands (scheduling only, masked 0). */
#ifdef NON_MATCHING
void func_8010415C_3D667C_TitleScreenAndIntro(u8 value) {
    u32* p = (u32*)D_801138A0_3E5DC0_TitleScreenAndIntro;
    u32 n = D_80111D54_3E4274_TitleScreenAndIntro * D_80111D58_3E4278_TitleScreenAndIntro * 0.25;
    u32 i;

    for (i = 0; i < n; i++) {
        *p++ = (value << 24) | (value << 16) | (value << 8) | value;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010415C_3D667C_TitleScreenAndIntro);
#endif

/* darken the current mask with a stamp's image at (x, y): each texel on the mask takes the stamp's
   value where that is darker (lower).
   NON_MATCHING: retail keeps the off-mask default (0xFF) in the texel's register from the first
   test and masks the stamp value instead (masked 7). */
#ifdef NON_MATCHING
void func_8010421C_3D673C_TitleScreenAndIntro(Ovl62Stamp* stamp, s32 x, s32 y) {
    u8* mask = D_801138A0_3E5DC0_TitleScreenAndIntro;
    u8* data = stamp->data;
    s32 i;
    s32 j;
    s32 px;
    s32 py;
    u8 v;
    u8 cur;

    for (j = 0; j < stamp->h; j++) {
        for (i = 0; i < stamp->w; i++) {
            py = y + j;
            px = x + i;
            if (px < 0) {
                continue;
            }
            if (px >= D_80111D54_3E4274_TitleScreenAndIntro) {
                continue;
            }
            if (py < 0) {
                continue;
            }
            if (py >= D_80111D58_3E4278_TitleScreenAndIntro) {
                continue;
            }
            v = data[i + j * stamp->w];
            if (px < 0 || px >= D_80111D54_3E4274_TitleScreenAndIntro) {
                cur = 0xFF;
            } else if (py < 0 || py >= D_80111D58_3E4278_TitleScreenAndIntro) {
                cur = 0xFF;
            } else {
                cur = mask[px + py * D_80111D54_3E4274_TitleScreenAndIntro];
            }
            if (cur >= v) {
                mask[px + py * D_80111D54_3E4274_TitleScreenAndIntro] = v;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010421C_3D673C_TitleScreenAndIntro);
#endif

s16 func_8010433C_3D685C_TitleScreenAndIntro(void) {
    return func_8002838C_28F8C(0, func_80103BF0_3D6110_TitleScreenAndIntro, 2);
}

/* the curtain: model drawn blended between two named parts by t (0 at the start) */
void func_8010436C_3D688C_TitleScreenAndIntro(Ovl62Blend* blend, s16 model, char* part, s16 model2, char* part2) {
    f32 t;

    blend->model = model;
    blend->model2 = model2;
    blend->part = part;
    blend->part2 = part2;
    func_8002A00C_2AC0C(model);
    t = 0.0f;
    blend->t = t;
    func_8002A4E0_2B0E0(model, model2, t, part, part2, 0);
}

void func_8010440C_3D692C_TitleScreenAndIntro(Ovl62Blend* blend, f32 t) {
    blend->t = t;
    func_8002A4E0_2B0E0(blend->model, blend->model2, blend->t, blend->part, blend->part2, 0);
}

/* a one-member sprite group from an animation file, at (x, y), hidden priority 0x47F4 */
void func_80104448_3D6968_TitleScreenAndIntro(s32 file, s16 x, s16 y, Ovl62Sprite* spr) {
    void* data;

    spr->active = 1;
    spr->grp = SprCreate(5, 0);
    data = DataRead(file);
    spr->anim = SprAnimRead(data);
    DataClose(data);
    SprAnimSet(spr->grp, 0, spr->anim, 0);
    SprPrioSet(spr->grp, 0, 0x47F4);
    SprAttrSet(spr->grp, 0, 0xD000);
    SprPosSet(spr->grp, 0, x, y);
}

/* show */
void func_80104524_3D6A44_TitleScreenAndIntro(Ovl62Sprite* spr) {
    SprAttrReset(spr->grp, 0, 0x8000);
    SprAttrSet(spr->grp, 0, 0);
}

/* hide */
void func_80104564_3D6A84_TitleScreenAndIntro(Ovl62Sprite* spr) {
    SprAttrReset(spr->grp, 0, 0);
    SprAttrSet(spr->grp, 0, 0x8000);
}

void func_801045A4_3D6AC4_TitleScreenAndIntro(Ovl62Sprite* spr, s32 prio) {
    SprPrioSet(spr->grp, 0, prio + 0x47F4);
}

void func_801045CC_3D6AEC_TitleScreenAndIntro(Ovl62Sprite* spr, s32 alpha) {
    func_80082488_83088(spr->grp, 0, alpha);
}

void func_801045F0_3D6B10_TitleScreenAndIntro(Ovl62Sprite* spr) {
    SprAttrReset(spr->grp, 0, 0xFFFF);
}

void func_80104614_3D6B34_TitleScreenAndIntro(Ovl62Sprite* spr, s32 attr) {
    SprAttrSet(spr->grp, 0, attr);
}

void func_80104638_3D6B58_TitleScreenAndIntro(Ovl62Sprite* spr) {
    SprKill(spr->grp);
    SprAnimKill(spr->anim);
}

void func_80104668_3D6B88_TitleScreenAndIntro(Ovl62Sprite* dst, Ovl62Sprite* mask) {
    func_80104690_3D6BB0_TitleScreenAndIntro(dst->grp, 0, mask->grp, 0);
}

/* copy a sprite's I8 image into another's RGBA32 alpha bytes (MP1 PressStartScreen
   func_800F7844) */
void func_80104690_3D6BB0_TitleScreenAndIntro(s16 grp, s16 idx, s16 maskGrp, s16 maskIdx) {
    HuSprite* a = func_80082550_83150(grp, idx);
    HuSprite* b = func_80082550_83150(maskGrp, maskIdx);
    HuSprite_Unk84_Unk00_Struct* frame = a->unk_84->unk00;
    u16 w = frame->unk04;
    u16 h = frame->unk06;
    u8* dst = frame->unk00;
    u8* src = b->unk_84->unk00->unk00;
    s16 i;

    for (i = 0; i < (s16)w * (s16)h; i++) {
        dst[3] = *src;
        dst += 4;
        src++;
    }
}

/* draw the RGBA32 image D_801110E0 (80105280) at (28, 29) in 32x16 tiles; the last column and
   row take what is left */
void func_80104778_3D6C98_TitleScreenAndIntro(Gfx** gfx) {
    s32 x;
    s32 y;
    s32 w;
    s32 h;
    s32 x0;
    s32 y0;
    u8* tex;

    x0 = 28;
    y0 = 29;
    gSPDisplayList((*gfx)++, D_801110E8_3E3608_TitleScreenAndIntro);
    gDPSetScissor((*gfx)++, G_SC_NON_INTERLACE, 0, 0, 320, 240);
    gDPSetCombineMode((*gfx)++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode((*gfx)++, 0x504240, 0);
    gDPSetPrimColor((*gfx)++, 0, 0, 255, 255, 255, 255);
    gDPSetCycleType((*gfx)++, G_CYC_1CYCLE);
    gSPSegment((*gfx)++, 0, 0);
    for (y = 0; y < D_80111D68_3E4288_TitleScreenAndIntro - 16; y += 16) {
        for (x = 0; x < D_80111D64_3E4284_TitleScreenAndIntro - 32; x += 32) {
            tex = D_801110E0_3E3600_TitleScreenAndIntro + (x + y * D_80111D64_3E4284_TitleScreenAndIntro) * 4;
            gDPLoadTextureTile((*gfx)++, tex,
                               G_IM_FMT_RGBA, G_IM_SIZ_32b, D_80111D64_3E4284_TitleScreenAndIntro, D_80111D68_3E4288_TitleScreenAndIntro,
                               0, 0, 32, 16, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                               G_TX_NOLOD, G_TX_NOLOD);
            gSPScisTextureRectangle((*gfx)++, (x + x0) * 4, (y + y0) * 4, (x + x0 + 32) * 4, (y + y0 + 16) * 4, G_TX_RENDERTILE, 0, 0,
                                    0x400, 0x400);
        }
        tex = D_801110E0_3E3600_TitleScreenAndIntro + (x + y * D_80111D64_3E4284_TitleScreenAndIntro) * 4;
        w = D_80111D64_3E4284_TitleScreenAndIntro - x;
        gDPLoadTextureTile((*gfx)++, tex,
                           G_IM_FMT_RGBA, G_IM_SIZ_32b, D_80111D64_3E4284_TitleScreenAndIntro, D_80111D68_3E4288_TitleScreenAndIntro, 0,
                           0, w, 16, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                           G_TX_NOLOD);
        gSPScisTextureRectangle((*gfx)++, (x + x0) * 4, (y + y0) * 4, (x + x0 + w) * 4, (y + y0 + 16) * 4, G_TX_RENDERTILE, 0, 0, 0x400,
                                0x400);
    }
    h = D_80111D68_3E4288_TitleScreenAndIntro - y;
    for (x = 0; x < D_80111D64_3E4284_TitleScreenAndIntro - 32; x += 32) {
        tex = D_801110E0_3E3600_TitleScreenAndIntro + (x + y * D_80111D64_3E4284_TitleScreenAndIntro) * 4;
        gDPLoadTextureTile((*gfx)++, tex,
                           G_IM_FMT_RGBA, G_IM_SIZ_32b, D_80111D64_3E4284_TitleScreenAndIntro, D_80111D68_3E4288_TitleScreenAndIntro, 0,
                           0, 32, h, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                           G_TX_NOLOD);
        gSPScisTextureRectangle((*gfx)++, (x + x0) * 4, (y + y0) * 4, (x + x0 + 32) * 4, (y + y0 + h) * 4, G_TX_RENDERTILE, 0, 0, 0x400,
                                0x400);
    }
    tex = D_801110E0_3E3600_TitleScreenAndIntro + (x + y * D_80111D64_3E4284_TitleScreenAndIntro) * 4;
    w = D_80111D64_3E4284_TitleScreenAndIntro - x;
    gDPLoadTextureTile((*gfx)++, tex,
                       G_IM_FMT_RGBA, G_IM_SIZ_32b, D_80111D64_3E4284_TitleScreenAndIntro, D_80111D68_3E4288_TitleScreenAndIntro, 0, 0,
                       w, h, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                       G_TX_NOLOD);
    gSPScisTextureRectangle((*gfx)++, (x + x0) * 4, (y + y0) * 4, (x + x0 + w) * 4, (y + y0 + h) * 4, G_TX_RENDERTILE, 0, 0, 0x400,
                            0x400);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80105204_3D7724_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80105234_3D7754_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80105280_3D77A0_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_801053D8_3D78F8_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80105460_3D7980_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80105504_3D7A24_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_801055A0_3D7AC0_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_801055C8_3D7AE8_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_801055F0_3D7B10_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80105658_3D7B78_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80105668_3D7B88_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80105684_3D7BA4_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_801056CC_3D7BEC_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010571C_3D7C3C_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80105758_3D7C78_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_801057D4_3D7CF4_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80105818_3D7D38_TitleScreenAndIntro);

void func_80105824_3D7D44_TitleScreenAndIntro(void) {
}

void func_8010582C_3D7D4C_TitleScreenAndIntro(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80105834_3D7D54_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80105840_3D7D60_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80105880_3D7DA0_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_801059F0_3D7F10_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80105A1C_3D7F3C_TitleScreenAndIntro);

__asm__(".section .rodata");
const char D_80111BF0_3E4110_TitleScreenAndIntro[] = "17";

__asm__(".section .rodata");
const char D_80111BF4_3E4114_TitleScreenAndIntro[] = "16";

__asm__(".section .rodata");
const char D_80111BF8_3E4118_TitleScreenAndIntro[] = "15";

__asm__(".section .rodata");
const char D_80111BFC_3E411C_TitleScreenAndIntro[] = "14";

__asm__(".section .rodata");
const char D_80111C00_3E4120_TitleScreenAndIntro[] = "13";

__asm__(".section .rodata");
const char D_80111C04_3E4124_TitleScreenAndIntro[] = "12";

__asm__(".section .rodata");
const char D_80111C08_3E4128_TitleScreenAndIntro[] = "11";

__asm__(".section .rodata");
const char D_80111C0C_3E412C_TitleScreenAndIntro[] = "10";

__asm__(".section .rodata");
const u32 D_80111C10_3E4130_TitleScreenAndIntro[1] = { 0x39000000 };

__asm__(".section .rodata");
const u32 D_80111C14_3E4134_TitleScreenAndIntro[1] = { 0x38000000 };

__asm__(".section .rodata");
const u32 D_80111C18_3E4138_TitleScreenAndIntro[1] = { 0x37000000 };

__asm__(".section .rodata");
const u32 D_80111C1C_3E413C_TitleScreenAndIntro[1] = { 0x36000000 };

__asm__(".section .rodata");
const u32 D_80111C20_3E4140_TitleScreenAndIntro[1] = { 0x35000000 };

__asm__(".section .rodata");
const u32 D_80111C24_3E4144_TitleScreenAndIntro[1] = { 0x34000000 };

__asm__(".section .rodata");
const u32 D_80111C28_3E4148_TitleScreenAndIntro[1] = { 0x33000000 };

__asm__(".section .rodata");
const u32 D_80111C2C_3E414C_TitleScreenAndIntro[1] = { 0x32000000 };

__asm__(".section .rodata");
const u32 D_80111C30_3E4150_TitleScreenAndIntro[1] = { 0x31000000 };

__asm__(".section .rodata");
const u32 D_80111C34_3E4154_TitleScreenAndIntro[1] = { 0x30000000 };

__asm__(".section .rodata");
const char D_80111C38_3E4158_TitleScreenAndIntro[] = "";

__asm__(".section .rodata");
const u32 D_80111C3C_3E415C_TitleScreenAndIntro[1] = { 0x80000000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80105AB8_3D7FD8_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010D3C0_3DF8E0_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010D3EC_3DF90C_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010D478_3DF998_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010D484_3DF9A4_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010D490_3DF9B0_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010D684_3DFBA4_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010D778_3DFC98_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010D7C8_3DFCE8_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010D95C_3DFE7C_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010DA5C_3DFF7C_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010DB5C_3E007C_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010DCA4_3E01C4_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010DE00_3E0320_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010DEA0_3E03C0_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010DF30_3E0450_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010DF5C_3E047C_TitleScreenAndIntro);

void func_8010DF90_3E04B0_TitleScreenAndIntro(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010DF98_3E04B8_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010E008_3E0528_TitleScreenAndIntro);

__asm__(".section .rodata");
const char D_80111C58_3E4178_TitleScreenAndIntro[] = "C161_000-donchou";

__asm__(".section .rodata");
const char D_80111C6C_3E418C_TitleScreenAndIntro[] = "C161_000-donchou2";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010E0C4_3E05E4_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010E154_3E0674_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010E210_3E0730_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010E2A0_3E07C0_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010E320_3E0840_TitleScreenAndIntro);

__asm__(".section .rodata");
const char D_80111C80_3E41A0_TitleScreenAndIntro[] = "okstage1-right_c";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010E408_3E0928_TitleScreenAndIntro);

__asm__(".section .rodata");
const char D_80111CA8_3E41C8_TitleScreenAndIntro[] = "okstage1-light_c1";

__asm__(".section .rodata");
const char D_80111CBC_3E41DC_TitleScreenAndIntro[] = "okstage2-light_c1";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010E4C8_3E09E8_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010E5B0_3E0AD0_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010E670_3E0B90_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010E8C0_3E0DE0_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010EB08_3E1028_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010EB88_3E10A8_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010ED80_3E12A0_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010EFBC_3E14DC_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010F074_3E1594_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010F1D0_3E16F0_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010F328_3E1848_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010F3F4_3E1914_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010F540_3E1A60_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010F5AC_3E1ACC_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010F95C_3E1E7C_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010F988_3E1EA8_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010FAB4_3E1FD4_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010FAE0_3E2000_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010FB2C_3E204C_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010FBD4_3E20F4_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010FC98_3E21B8_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010FD28_3E2248_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010FE44_3E2364_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8010FE7C_3E239C_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_801100B0_3E25D0_TitleScreenAndIntro);

__asm__(".section .rodata");
const u32 D_80111D18_3E4238_TitleScreenAndIntro[3] = { 0x00000000, 0xC1A770A4, 0x42406666 };

__asm__(".section .rodata");
const u32 D_80111D24_3E4244_TitleScreenAndIntro[3] = { 0x00000000, 0x432F0000, 0x42C80000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80110238_3E2758_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80110354_3E2874_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_801103FC_3E291C_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_8011058C_3E2AAC_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80110708_3E2C28_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80110888_3E2DA8_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80110964_3E2E84_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_801109F4_3E2F14_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80110A58_3E2F78_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80110A7C_3E2F9C_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80110AE4_3E3004_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80110B18_3E3038_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80110B84_3E30A4_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80110BF0_3E3110_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80110C20_3E3140_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80110C50_3E3170_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80110CAC_3E31CC_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80110CCC_3E31EC_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80110D64_3E3284_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80110D8C_3E32AC_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80110DDC_3E32FC_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80110E30_3E3350_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80110E60_3E3380_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80110EEC_3E340C_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80110F68_3E3488_TitleScreenAndIntro);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_62_TitleScreenAndIntro/3D4F20", func_80110FBC_3E34DC_TitleScreenAndIntro);
