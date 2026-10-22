#include "common.h"
#include "ovl_72.h"

void func_80102800_415790_Credits(void) {
    omInitObjMan(30, 20);
    func_80088640_89240();
    func_80050A30_51630(D_01164160);
    func_80026D28_27928(2);
    func_80026DAC_279AC(0, 16, 16, 16);
    func_80026E00_27A00(1, 0.0f, -100.0f, 65.0f);
    func_80102A90_415A20_Credits();
    omAddPrcObj(func_80104D44_417CD4_Credits, 0x1001, 0x800, 0);
    omAddPrcObj(func_801028A8_415838_Credits, 0x1001, 0x800, 0);
    InitFadeIn(0, 90);
}

/* START on any controller ends the credits (once seen before, or after the roll). */
void func_801028A8_415838_Credits(void) {
    s32 i;

    while (TRUE) {
        if (_CheckFlag(0xB) != 0) {
            for (i = 0; i < 4; i++) {
                if (ContBtnTrg[i] & 0x1000) {
                    D_80104E8C_417E1C_Credits = 1;
                }
            }
        }
        if (D_80104E88_417E18_Credits != 0) {
            for (i = 0; i < 4; i++) {
                if (ContBtnTrg[i] & 0x1000) {
                    D_80104E8C_417E1C_Credits = 1;
                }
            }
        }
        if (D_80104E8C_417E1C_Credits != 0) {
            while (func_8008F618_90218() != 0) {
                HuPrcVSleep();
            }
            func_8008F624_90224(0, 0, 0);
            InitFadeOut(0, 30);
            func_800794A8_7A0A8(60);
            while (func_8008F618_90218() != 0) {
                HuPrcVSleep();
            }
            if (_CheckFlag(0xB) == 0) {
                _SetFlag(0xB);
                func_8007E224_7EE24();
            }
            func_8002CA48_2D648(0, 0, 0);
            MBDBackKill();
            func_80050AE0_516E0();
            SprAnimKill(D_80105C24_418BB4_Credits);
            SprAnimKill(D_80105C28_418BB8_Credits);
            func_80069698_6A298();
            func_8008CE5C_8DA5C();
            omOvlKill();
            if (_CheckFlag(0x1A) != 0) {
                omOvlReturnEx(1);
            } else {
                omovlhisidx = -1;
                omOvlCallEx(0x57, 0, 0x84);
            }
            while (TRUE) {
                HuPrcVSleep();
            }
        }
        HuPrcVSleep();
    }
}

void func_80102A90_415A20_Credits(void) {
    CreditsModelSlot* slot;
    void* data;
    s32 i;
    s32 j;

    func_80050E00_51A00(0x41);
    j = 0;
    func_8005321C_53E1C(10.0f, 5000.0f);
    data = DataRead(0xB00E3);
    D_80105C24_418BB4_Credits = SprAnimRead(data);
    DataClose(data);
    data = DataRead(0xB00E4);
    D_80105C28_418BB8_Credits = SprAnimRead(data);
    DataClose(data);
    D_80105AC0_418A50_Credits = func_80018A30_19630(0xA0227, 0xA9D);
    i = 0;
    func_80029C74_2A874(D_80105AC0_418A50_Credits, func_80029D0C_2A90C(D_80105AC0_418A50_Credits));
    D_80105AC4_418A54_Credits = func_80018A30_19630(0xA0228, 0xA9D);
    func_80029C74_2A874(D_80105AC4_418A54_Credits, func_80029D0C_2A90C(D_80105AC4_418A54_Credits));
    D_80105AC8_418A58_Credits = func_80018A30_19630(0xA0229, 0xA9D);
    func_80029C74_2A874(D_80105AC8_418A58_Credits, func_80029D0C_2A90C(D_80105AC8_418A58_Credits));
    while (D_80104EA0_417E30_Credits[j] != -1) {
        slot = &D_80105C30_418BC0_Credits[i++];
        if (i >= 20) {
            break;
        }
        slot->used = 1;
        slot->file = D_80104EA0_417E30_Credits[j];
        slot->model = func_80018A30_19630(slot->file, 0x16B9);
        func_800298A4_2A4A4(slot->model, 4, 4);
        j++;
    }
    func_8007273C_7333C(D_80105AB0_418A40_Credits, 0);
}

/* A preloaded model for `file` (shown), else a new one. */
s32 func_80102CBC_415C4C_Credits(s32 file, s32 arg1) {
    CreditsModelSlot* slot;
    s32 i;
    s32 model = -1;

    for (i = 0; i < 20; i++) {
        slot = &D_80105C30_418BC0_Credits[i];
        if (slot->file == file) {
            model = slot->model;
            func_800298A4_2A4A4(slot->model, 4, 0);
            break;
        }
    }
    if (i >= 20) {
        model = func_80018A30_19630(file, arg1);
    }
    return model;
}

/* A background model that reappears at random places when its motion ends. */
void func_80102D6C_415CFC_Credits(void) {
    s32* model = HuPrcCurrentGet()->user_data;
    f32 x;
    f32 scale;

    HuPrcSleep(300);
    while (TRUE) {
        while (func_80029CE4_2A8E4(*model) < func_80029D0C_2A90C(*model)) {
            HuPrcVSleep();
        }
        func_800298A4_2A4A4(*model, 4, 4);
        HuPrcSleep((rand8() & 0xF) + 30);
        x = (u8)(rand8() % 200) * 3 + -300.0f;
        func_80029714_2A314(*model, x, (rand8() & 0x7F) + 300.0f, -1000.0f);
        scale = 9.0f - 3.0f / ((rand8() & 0xF) + 1);
        func_800297E8_2A3E8(*model, scale, scale, scale);
        func_80029C74_2A874(*model, 0.0f);
        func_800298A4_2A4A4(*model, 4, 0);
        HuPrcVSleep();
    }
}

#ifdef NON_MATCHING
/* NON_MATCHING: register allocation (retail keeps y and 11000.0f in GPRs) and the motion-frame branch order */
/* The models walking across the stage, then the finale character. */
void func_80102F10_415EA0_Credits(void) {
    CreditsActor* actor;
    CreditsModelEntry* entry;
    f32 x;
    f32 end;
    f32 dist;
    f32 step;
    f32 y;
    f32 ystep;
    f32 frame;
    f32 z;
    f32 angle;
    f32 rx;
    f32 ry;
    f32 rz;
    f32 sx;
    f32 sy;
    s16 model;

    HuPrcSleep(1200);
    while (D_80104E90_417E20_Credits == 0) {
        HuPrcVSleep();
    }
    entry = D_80104EDC_417E6C_Credits;
    while (entry->file != -1) {
        actor = &D_80105AD0_418A60_Credits[D_80104E80_417E10_Credits];
        actor->model = model = func_80102CBC_415C4C_Credits(entry->file, 0x16B9);
        if (entry->file == 0x420015) {
            HmfModelObjAttrSet(model, 0x06000000, 0);
        }
        x = MBDBackMdlScaleGet() * 650.0f + entry->x;
        func_80029714_2A314(actor->model, x, 0.0f, MBDBackMdlScaleGet() * 11000.0f);
        func_8002979C_2A39C(actor->model, entry->rot.x, entry->rot.y, entry->rot.z);
        entry->scale *= 1.1f;
        sx = MBDBackMdlScaleGet() * entry->scale;
        sy = MBDBackMdlScaleGet() * entry->scale;
        func_800297E8_2A3E8(actor->model, sx, sy, MBDBackMdlScaleGet() * entry->scale);
        HuPrcVSleep();
        actor->mdlData = D_800FC834_FD434[(u16)actor->model].unk02;
        if (entry->motion != -1) {
            actor->motion = func_8002C8B8_2D4B8(DataRead(entry->motion), 0x1D);
        }
        HuPrcVSleep();
        if (entry->motion != -1) {
            func_8002C9C0_2D5C0(actor->model, actor->motion);
        }
        if (entry->frame != -2) {
            frame = 0.0f;
            if (entry->frame != -1) {
                frame = entry->frame;
            }
        } else {
            frame = func_80029D0C_2A90C(actor->model);
        }
        func_80029C74_2A874(actor->model, frame);
        func_80029E80_2AA80(actor->model, 0, 1);
        HuPrcVSleep();
        end = MBDBackMdlScaleGet() * -650.0f - entry->xEnd;
        if (end < 0.0f) {
            dist = x - end;
        } else {
            dist = x + end;
        }
        step = dist / 270.0f;
        y = MBDBackMdlScaleGet() * 150.0f;
        ystep = MBDBackMdlScaleGet() * 150.0f / 270.0f;
        x -= step;
        while (TRUE) {
            y += ystep;
            if (x <= end) {
                break;
            }
            func_80029714_2A314(actor->model, x, y, MBDBackMdlScaleGet() * 11000.0f);
            HuPrcVSleep();
            x -= step;
        }
        if (entry->motion != -1 && D_800FC834_FD434[(u16)actor->model].unk02 != (u16)actor->motion) {
            func_80039018_39C18(actor->motion);
        }
        entry++;
        func_800283DC_28FDC(actor->model);
        HuPrcSleep(9);
    }
    HuPrcSleep(60);
    actor = &D_80105AD0_418A60_Credits[D_80104E80_417E10_Credits];
    actor->model = func_80018A30_19630(0x80000, 0x16B9);
    actor->mdlData = D_800FC834_FD434[(u16)actor->model].unk02;
    actor->motion = func_8002C8B8_2D4B8(DataRead(0x80014), 0x1D);
    actor->motion2 = func_8002C8B8_2D4B8(DataRead(0x8002D), 0x1D);
    func_8002C9C0_2D5C0(actor->model, actor->motion);
    z = MBDBackMdlScaleGet() * 11000.0f;
    func_80029714_2A314(actor->model, 0.0f, 0.0f, z);
    sx = MBDBackMdlScaleGet();
    sy = MBDBackMdlScaleGet();
    func_800297E8_2A3E8(actor->model, sx, sy, MBDBackMdlScaleGet());
    func_80029E80_2AA80(actor->model, 0, 2);
    for (angle = 90.0f - 1.0f; !(angle <= 0.0f); angle -= 1.0f) {
        func_80029714_2A314(actor->model, 0.0f, 0.0f, z - (1.0f - func_800B7890_B8490(angle)) * 1100.0f);
        HuPrcVSleep();
    }
    func_80029714_2A314(actor->model, 0.0f, 0.0f, z);
    func_80029BF0_2A7F0(actor->model, actor->mdlData, 0, 10, 0);
    HuPrcSleep(30);
    func_80029BF0_2A7F0(actor->model, actor->motion2, 0, 10, 0);
    while (func_80029E3C_2AA3C(actor->model) != -1.0f) {
        HuPrcVSleep();
    }
    while (func_80029CE4_2A8E4(actor->model) < func_80029D0C_2A90C(actor->model)) {
        HuPrcVSleep();
    }
    actor->motion = func_8002C8B8_2D4B8(DataRead(0x80030), 0x1D);
    HuPrcSleep(30);
    func_80029BF0_2A7F0(actor->model, actor->motion, func_8002CA14_2D614(actor->motion), 10, 1);
    x = 0.0f;
    angle = 90.0f;
    rz = 0.0f;
    ry = 0.0f;
    rx = 0.0f;
    while (angle -= 0.4f, x -= 0.44444445f, !(angle <= 0.0f)) {
        func_80029714_2A314(actor->model, x, 0.0f + func_800B7890_B8490(angle) * 60.0f * 5.0f * MBDBackMdlScaleGet(), z);
        if (rx < 29.0f) {
            rx += 0.29f;
            ry += 0.12f;
            rz += 0.45f;
        } else {
            rx = 29.0f;
            ry = 12.0f;
            rz = 45.0f;
        }
        func_8002979C_2A39C(actor->model, rx, ry, rz);
        HuPrcVSleep();
    }
    while (TRUE) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_72_Credits/415790", func_80102F10_415EA0_Credits);
#endif

#ifdef NON_MATCHING
/* NON_MATCHING: register allocation of the arguments */
/* Creates a GAMEMES text for `str` (its first byte skipped), narrowed to 270 pixels; returns its
   index in D_80105DB0. */
s32 func_8010371C_4166AC_Credits(char* str, s16 x, s16 y, s16 arg3, s16 arg4) {
    s16 len;
    s16 idx;
    s16 i;
    s32 width;
    f32 scale;

    len = func_8010393C_4168CC_Credits(str);
    idx = func_8006A608_6B208(&D_80105DB0_418D40_Credits[D_80104ED8_417E68_Credits], str + 1, 0, arg3, arg4);
    D_80105DB0_418D40_Credits[D_80104ED8_417E68_Credits].unk08 = idx;
    width = len * 15;
    if (width >= 271) {
        scale = 270.0f / width;
        for (i = 0; i < len;) {
            i++;
            SprScaleSet(D_80105DB0_418D40_Credits[D_80104ED8_417E68_Credits].strGId[idx], i, scale, 1.0f);
        }
    }
    SprPosSet(D_80105DB0_418D40_Credits[D_80104ED8_417E68_Credits].strGId[idx], 0, x, y);
    return D_80104ED8_417E68_Credits++;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_72_Credits/415790", func_8010371C_4166AC_Credits);
#endif

void func_80103920_4168B0_Credits(GAMEMES* mes) {
    func_8006985C_6A45C(mes);
}

/* Characters after the first byte. */
s32 func_8010393C_4168CC_Credits(char* str) {
    s32 n = 0;

    while (*str != 0) {
        str++;
        n++;
    }
    return n - 1;
}

#ifdef NON_MATCHING
/* NON_MATCHING: retail has a 48-byte larger frame no code uses, and different loop rotation/allocation */
/* The logo, then each section title sliding in and out, then the closing message. */
void func_80103960_4168F0_Credits(void) {
    GAMEMES* mes;
    char* str;
    s32* done;
    s32 len;
    s32 alpha;
    s32 x0;
    s32 x;
    s32 idx;
    s32 k;
    s32 i;
    f32 angle;

    alpha = 0;
    done = HuPrcCurrentGet()->user_data;
    HuPrcSleep(30);
    str = func_80068CD4_698D4(0x6EA);
    len = func_8010393C_4168CC_Credits(str);
    idx = func_8010371C_4166AC_Credits(str, 160, 140, -1, -1);
    func_80068D24_69924(str);
    mes = &D_80105DB0_418D40_Credits[idx];
    SprPosSet(mes->strGId[mes->unk08], 0, 160, 140);
    for (i = 0; i < len;) {
        i++;
        func_80082488_83088(mes->strGId[mes->unk08], i, alpha);
    }
    while (TRUE) {
        alpha += 8;
        HuPrcVSleep();
        if (alpha >= 255) {
            break;
        }
        for (i = 0; i < len;) {
            i++;
            func_80082488_83088(mes->strGId[mes->unk08], i, alpha);
        }
    }
    for (i = 0; i < len;) {
        i++;
        func_80082488_83088(mes->strGId[mes->unk08], i, 255);
    }
    PlayMusic(6);
    HuPrcSleep(60);
    for (alpha -= 8; alpha > 0; alpha -= 8) {
        for (i = 0; i < len;) {
            i++;
            func_80082488_83088(mes->strGId[mes->unk08], i, alpha);
        }
        HuPrcVSleep();
    }
    for (i = 0; i < len;) {
        i++;
        func_80082488_83088(mes->strGId[mes->unk08], i, 0);
    }
    D_80104E90_417E20_Credits = 1;
    for (k = 0; D_80105994_418924_Credits[k].title != -1; k++) {
        str = func_80068CD4_698D4(D_80105994_418924_Credits[k].title);
        x0 = -(func_8010393C_4168CC_Credits(str) * 15 + 8);
        idx = func_8010371C_4166AC_Credits(str, x0, 140, 0, 0);
        func_80068D24_69924(str);
        mes = &D_80105DB0_418D40_Credits[idx];
        for (angle = 0.0f;; angle += 6.428571f) {
            if (angle >= 90.0f) {
                angle = 90.0f;
            }
            x = x0 + HuMathSin(angle) * (33 - x0);
            SprPosSet(mes->strGId[mes->unk08], 0, x, 140);
            if (angle >= 90.0f) {
                break;
            }
            HuPrcVSleep();
        }
        D_80104E84_417E14_Credits = 1;
        do {
            HuPrcVSleep();
        } while (D_80104E84_417E14_Credits != 0);
        HuPrcVSleep();
        for (angle = 0.0f;; angle += 6.428571f) {
            if (angle >= 90.0f) {
                angle = 90.0f;
            }
            SprPosSet(mes->strGId[mes->unk08], 0, x + (1.0f - func_800B7890_B8490(angle)) * (328 - x), 140);
            if (angle >= 90.0f) {
                break;
            }
            HuPrcVSleep();
        }
        func_80103920_4168B0_Credits(mes);
        HuPrcVSleep();
    }
    HuPrcSleep(180);
    str = func_80068CD4_698D4(0x6F9);
    len = func_8010393C_4168CC_Credits(str);
    idx = func_8010371C_4166AC_Credits(str, 160, 170, -1, -1);
    func_80068D24_69924(str);
    mes = &D_80105DB0_418D40_Credits[idx];
    SprPosSet(mes->strGId[mes->unk08], 0, 160, 170);
    alpha = 0;
    for (i = 0; i < len;) {
        i++;
        func_80082488_83088(mes->strGId[mes->unk08], i, alpha);
    }
    while (TRUE) {
        alpha += 8;
        HuPrcVSleep();
        if (alpha >= 255) {
            break;
        }
        for (i = 0; i < len;) {
            i++;
            func_80082488_83088(mes->strGId[mes->unk08], i, alpha);
        }
    }
    for (i = 0; i < len;) {
        i++;
        func_80082488_83088(mes->strGId[mes->unk08], i, 255);
    }
    *done = 1;
    while (TRUE) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_72_Credits/415790", func_80103960_4168F0_Credits);
#endif

#ifdef NON_MATCHING
/* NON_MATCHING: float register allocation and loop rotation */
/* A name scrolling up and fading in and out; lets the next one start once it has risen 15 pixels. */
void func_80103FA4_416F34_Credits(void) {
    CreditsLine* line;
    s32 alpha;
    s32 i;
    f32 x;
    f32 y;

    alpha = 0;
    line = HuPrcCurrentGet()->user_data;
    x = 295 - line->len * 10;
    y = line->y + 220.0f;
    SprPosSet(line->spr, 0, x, y);
    for (i = 0; i < line->len * 2;) {
        i++;
        func_80082488_83088(line->spr, i, alpha);
    }
    while (y -= 0.4f, !(y <= 170.0f)) {
        if (y > 210.0f) {
            alpha += 10.0f;
            if (alpha >= 255) {
                alpha = 255;
            }
        }
        if (y < 180.0f) {
            alpha -= 10.0f;
            if (alpha < 0) {
                alpha = 0;
            }
        }
        if (y < 205.0f) {
            line->y = y - (s32)y;
            line->next = 1;
        }
        for (i = 0; i < line->len * 2;) {
            i++;
            func_80082488_83088(line->spr, i, alpha);
        }
        SprPosSet(line->spr, 0, x, y);
        HuPrcVSleep();
    }
    line->done = 1;
    func_80104980_417910_Credits(line->spr);
    omDelPrcObj(NULL);
    while (TRUE) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_72_Credits/415790", func_80103FA4_416F34_Credits);
#endif

#ifdef NON_MATCHING
/* NON_MATCHING: float register allocation (retail hoists 6.428571f and 155.0f differently) */
/* A role title sliding in, waiting for its names, sliding out. */
void func_80104248_4171D8_Credits(void) {
    CreditsLine* line;
    f32 x0;
    f32 dist;
    f32 x;
    f32 y;
    f32 angle;

    line = HuPrcCurrentGet()->user_data;
    y = 155.0f;
    x0 = -(line->len * 10 + 8);
    dist = 33.0f - x0;
    for (angle = 0.0f;; angle += 6.428571f) {
        if (angle >= 90.0f) {
            angle = 90.0f;
        }
        x = x0 + HuMathSin(angle) * dist;
        SprPosSet(line->spr, 0, x, 155);
        if (angle >= 90.0f) {
            break;
        }
        HuPrcVSleep();
    }
    D_80104E94_417E24_Credits = 1;
    while (D_80104E98_417E28_Credits == 0) {
        HuPrcVSleep();
    }
    for (angle = 0.0f;; angle += 6.428571f) {
        if (angle >= 90.0f) {
            angle = 90.0f;
        }
        SprPosSet(line->spr, 0, x + (1.0f - func_800B7890_B8490(angle)) * (328.0f - x), y);
        if (angle >= 90.0f) {
            break;
        }
        HuPrcVSleep();
    }
    D_80104E9C_417E2C_Credits = 1;
    func_80104980_417910_Credits(line->spr);
    omDelPrcObj(NULL);
    while (TRUE) {
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_72_Credits/415790", func_80104248_4171D8_Credits);
#endif

#ifdef NON_MATCHING
/* NON_MATCHING: retail keeps arg3 and len * 10 (a mult) differently; frame 8 bytes larger */
/* A sprite-text line in the credits font, each character with a shadow: digits, capitals, space,
   '=' (frame 13) and anything else (frame 46). Colour 1 is the role colour. */
s16 func_80104480_417410_Credits(u8* str, s16 color, s16 x, s16 arg3) {
    s16 spr;
    s16 member;
    s16 len;
    s32 frame;
    s32 px;
    u8* p;

    p = str + 1;
    len = func_80089234_89E34(p);
    spr = SprCreate((u16)(len * 2 + 1), 5);
    px = -x;
    if (x == -1) {
        px = -((len * 10) >> 1) + 5;
    }
    member = 1;
    if (*p != 0) {
        do {
            if (*p >= '0' && *p <= '9') {
                frame = *p - '0';
            } else if (*p >= 'A' && *p <= 'Z') {
                frame = *p - 0x31;
            } else if (*p == 0x10 || *p == ' ') {
                frame = 0x2F;
            } else if (*p == 0x1A) {
                frame = 0x2F;
            } else if (*p == '=') {
                frame = 0xD;
            } else {
                frame = 0x2E;
            }
            SprAnimSet(spr, member, D_80105C24_418BB4_Credits, frame);
            SprPosSet(spr, member, px, 0);
            func_80082488_83088(spr, member, 255);
            if (color == 1) {
                func_80082450_83050(spr, member, 255, 255, 0);
            } else {
                func_80082450_83050(spr, member, 255, 255, 255);
            }
            SprPrioSet(spr, member, 5);
            SprAttrReset(spr, member, 0xFFFF);
            SprAttrSet(spr, member, 0x1008);
            func_800824F4_830F4(spr, member, 0);
            member++;
            SprAnimSet(spr, member, D_80105C24_418BB4_Credits, frame);
            SprPosSet(spr, member, px + 1, 1);
            func_80082488_83088(spr, member, 255);
            if (color == 1) {
                func_80082450_83050(spr, member, 255, 0x80, 0);
            } else {
                func_80082450_83050(spr, member, 0x28, 0xC8, 255);
            }
            SprPrioSet(spr, member, 6);
            SprAttrReset(spr, member, 0xFFFF);
            SprAttrSet(spr, member, 0x1008);
            func_800824F4_830F4(spr, member, 0);
            px += 10;
            p++;
            member++;
        } while (*p != 0);
    }
    SprAnimSet(spr, 0, D_80105C24_418BB4_Credits, 0);
    SprAttrSet(spr, 0, 0x8000);
    func_800824F4_830F4(spr, 0, -1);
    return spr;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_72_Credits/415790", func_80104480_417410_Credits);
#endif

#ifdef NON_MATCHING
/* NON_MATCHING: where the two negations are scheduled */
/* A blank (two-sprite) line. */
s16 func_801047E8_417778_Credits(s32 x, s32 y) {
    s16 spr;
    s16 px;
    s16 py;

    x *= -1;
    y *= -1;
    spr = SprCreate(3, 5);
    SprAnimSet(spr, 1, D_80105C28_418BB8_Credits, 0);
    px = x;
    py = y;
    SprPosSet(spr, 1, px, py);
    SprPrioSet(spr, 1, 5);
    func_80082488_83088(spr, 1, 255);
    SprAttrReset(spr, 1, 0xFFFF);
    SprAttrSet(spr, 1, 0x1008);
    func_800824F4_830F4(spr, 1, 0);
    SprAnimSet(spr, 2, D_80105C28_418BB8_Credits, 0);
    SprPosSet(spr, 2, px, py);
    SprPrioSet(spr, 2, 5);
    func_80082488_83088(spr, 2, 255);
    SprAttrReset(spr, 2, 0xFFFF);
    SprAttrSet(spr, 2, 0x1008);
    func_800824F4_830F4(spr, 2, 0);
    SprAnimSet(spr, 0, D_80105C28_418BB8_Credits, 0);
    SprAttrSet(spr, 0, 0x8000);
    func_800824F4_830F4(spr, 0, -1);
    return spr;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_72_Credits/415790", func_801047E8_417778_Credits);
#endif

void func_80104980_417910_Credits(s16 spr) {
    SprKill(spr);
}

/* The role/name roll: for each section, each role's title, then its names one after another. */
void func_801049A0_417930_Credits(void) {
    s16 sprs[8];
    s32 k;
    s32 n;
    CreditsRole* role;
    void* str;
    s16* name;
    CreditsLine* line;
    CreditsLine* title;
    f32 y;

    while (D_80104E90_417E20_Credits == 0) {
        HuPrcVSleep();
    }
    n = 0;
    for (k = 0; D_80105994_418924_Credits[k].title != -1; k++) {
        for (role = D_80105994_418924_Credits[k].roles; role->role != -1; role++) {
            s16 spr;

            D_80104E94_417E24_Credits = 0;
            D_80104E98_417E28_Credits = 0;
            D_80104E9C_417E2C_Credits = 0;
            if (role->role == -2) {
                spr = func_801047E8_417778_Credits(-29, -20);
            } else {
                str = func_80068CD4_698D4(role->role);
                spr = func_80104480_417410_Credits(str, 1, 0, 0);
            }
            omAddPrcObj(func_80104248_4171D8_Credits, 0x1001, 0x800, 0)->user_data = title = &D_80105DA0_418D30_Credits;
            if (role->role == -2) {
                title->len = 1;
            } else {
                title->len = func_8010393C_4168CC_Credits(str);
            }
            title->y = 0.0f;
            title->next = 0;
            title->done = 0;
            title->last = 0;
            title->spr = spr;
            if (role->role != -2) {
                func_80068D24_69924(str);
            }
            while (D_80104E94_417E24_Credits == 0) {
                HuPrcVSleep();
            }
            name = role->names;
            y = 0.0f;
            while (*name != -1) {
                if (*name == -2) {
                    sprs[n] = func_801047E8_417778_Credits(50, 0);
                } else {
                    str = func_80068CD4_698D4(*name);
                    sprs[n] = func_80104480_417410_Credits(str, 0, 0, 0);
                }
                omAddPrcObj(func_80103FA4_416F34_Credits, 0x1001, 0x800, 0)->user_data = line = &D_80105D20_418CB0_Credits[n];
                if (*name == -2) {
                    line->len = 1;
                } else {
                    line->len = func_8010393C_4168CC_Credits(str);
                }
                line->y = y;
                line->next = 0;
                line->done = 0;
                line->last = 0;
                line->spr = sprs[n];
                n++;
                if (n >= 8) {
                    n = 0;
                }
                if (*name != -2) {
                    func_80068D24_69924(str);
                }
                while (line->next == 0) {
                    HuPrcVSleep();
                }
                y = line->y;
                name++;
            }
            line->last = 1;
            while (line->done == 0) {
                HuPrcVSleep();
            }
            if (role[1].role == -1) {
                D_80104E84_417E14_Credits = 0;
            }
            D_80104E98_417E28_Credits = 1;
            while (D_80104E9C_417E2C_Credits == 0) {
                HuPrcVSleep();
            }
        }
        D_80104E84_417E14_Credits = 0;
    }
    while (TRUE) {
        HuPrcVSleep();
    }
}

void func_80104D44_417CD4_Credits(void) {
    s32 done = 0;

    D_80104E90_417E20_Credits = 0;
    omAddPrcObj(func_80102F10_415EA0_Credits, 0x1001, 0x800, 0);
    omAddPrcObj(func_80103960_4168F0_Credits, 0x1001, 0x1000, 0)->user_data = &done;
    omAddPrcObj(func_801049A0_417930_Credits, 0x1001, 0x1000, 0);
    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    omAddPrcObj(func_80102D6C_415CFC_Credits, 0x1001, 0x800, 0)->user_data = &D_80105AC0_418A50_Credits;
    omAddPrcObj(func_80102D6C_415CFC_Credits, 0x1001, 0x800, 0)->user_data = &D_80105AC4_418A54_Credits;
    omAddPrcObj(func_80102D6C_415CFC_Credits, 0x1001, 0x800, 0)->user_data = &D_80105AC8_418A58_Credits;
    while (done == 0) {
        HuPrcVSleep();
    }
    D_80104E88_417E18_Credits = 1;
    while (TRUE) {
        HuPrcVSleep();
    }
}
