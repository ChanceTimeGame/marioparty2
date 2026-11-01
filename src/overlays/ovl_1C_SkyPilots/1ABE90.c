#include "ovl_1C.h"

__asm__(".section .rodata");
const char D_8010B230_1B48C0_SkyPilots[] = "\202q\202d\202`\202c\202x\202f\202n\202v\202k\201I";

/* NON_MATCHING: register allocation */
#ifdef NON_MATCHING
void func_80102800_1ABE90_SkyPilots(void) {
    omObjData* obj;
    f32* p;

    func_8002D4D0_2E0D0(0x32);
    func_8002F290_2FE90(D_800F9D30_FA930, 0x40);
    func_80020D20_21920(0x20);
    omInitObjMan(0x32, 0);
    func_80079128_79D28();
    func_8000C38C_CF8C();
    func_80018E30_19A30(2);
    func_80018F58_19B58(2);
    func_80029708_2A308(0);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 115.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 240.0f, 511.0f);
    Hu3DCamSetPerspective(0, 80.0f, 80.0f, 5000.0f);
    ScissorSet(1, 0.0f, 124.0f, 320.0f, 232.0f);
    ViewportSet(1, 640.0f, 480.0f, 511.0f, 640.0f, 720.0f, 511.0f);
    Hu3DCamSetPerspective(1, 80.0f, 80.0f, 5000.0f);
    func_801063C4_1AFA54_SkyPilots();
    func_80106384_1AFA14_SkyPilots();
    func_8010677C_1AFE0C_SkyPilots();
    func_801065CC_1AFC5C_SkyPilots(0xF6, 0x18);
    func_8010641C_1AFAAC_SkyPilots(0xF6, 0x24);
    func_80106810_1AFEA0_SkyPilots(0, 0x20, 0x18);
    func_80106810_1AFEA0_SkyPilots(1, 0x20, 0x8C);
    func_8010608C_1AF71C_SkyPilots(1, func_800680D4_68CD4(3) & 0xFFFF);
    func_8010608C_1AF71C_SkyPilots(0, D_8010AF0C_1B459C_SkyPilots);
    func_80106A7C_1B010C_SkyPilots(0, 0);
    func_80106A7C_1B010C_SkyPilots(1, 0);
    D_800FA606_FB206 = 0;
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    func_8000C460_D060();
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(1, 0, 0, -1, func_80107EAC_1B153C_SkyPilots);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(1, 4, 0, -1, func_8010916C_1B27FC_SkyPilots);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(1, 8, 0, -1, func_801092F8_1B2988_SkyPilots);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(1, 6, 0, -1, func_80109878_1B2F08_SkyPilots);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(1, 0, 0, -1, func_80109BBC_1B324C_SkyPilots);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(1, 1, 0, -1, func_8010A024_1B36B4_SkyPilots);
    omAddObj(2, 4, 0x3C, -1, func_80106CD0_1B0360_SkyPilots);
    omAddObj(2, 4, 0x3C, -1, func_80106E98_1B0528_SkyPilots);
    omAddObj(2, 0xA, 0x3C, -1, func_8010A0BC_1B374C_SkyPilots);
    omAddObj(2, 0xA, 0x3C, -1, func_8010A154_1B37E4_SkyPilots);
    omAddObj(2, 0xA, 0x3C, -1, func_8010A1F4_1B3884_SkyPilots);
    omAddObj(2, 0xA, 0x3C, -1, func_8010A294_1B3924_SkyPilots);
    obj = omAddObj(0x7FDA, 0, 0, -1, func_80103E34_1AD4C4_SkyPilots);
    obj->work[0] = 2;
    omSetStatBit(obj, 0xA0);
    func_8002C59C_2D19C(0x3DE, 0x3E6, 0x78, 0xC8, 0xE6);
    func_8002CD6C_2D96C(4);
    func_8007273C_7333C((u8*)D_8010B230_1B48C0_SkyPilots, 1);
    func_80026DAC_279AC(0, 0x80, 0x80, 0xB0);
    func_80026DAC_279AC(1, 0xC8, 0xC8, 0xF0);
    func_80026E00_27A00(1, 0.0f, 62.0f, 102.0f);
    func_800794F0_7A0F0(0x7F);
    func_80079684_7A284(0x7F);
    p = D_800F94A8_FA0A8;
    p[0] = 700.0f;
    p[1] = 700.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_SkyPilots/1ABE90", func_80102800_1ABE90_SkyPilots);
#endif

void func_80102D3C_1AC3CC_SkyPilots(void) {
    if (func_8008F618_90218() == 0) {
        omOvlReturnEx(1);
    }
}

void func_80102D68_1AC3F8_SkyPilots(void) {
    s32 off[2];
    f32 best;
    s32 i;

    off[0] = -9;
    off[1] = -5;
    best = -1.0f;
    for (i = 0; i < 2; i++) {
        SPPlane* w = D_8010ADA4_1B4434_SkyPilots[i]->unk_50;
        s32 x = w->progress * 262.0f + 18.0f;

        if (x < 18) {
            x = 18;
        }
        if (x >= 0x119) {
            x = 0x118;
        }
        espPosSet(D_8010B2CC_1B495C_SkyPilots[i], x, off[i] + 0x78);
        espPosSet(w->icon[0], x, off[i] + 0x70);
        espPosSet(w->icon[1], x - 8, off[i] + 0x70);
        if (best < w->progress) {
            D_8010ADA1_1B4431_SkyPilots = i;
            best = w->progress;
        }
    }
}

void func_80102EF0_1AC580_SkyPilots(omObjData* obj) {

    if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        func_8000C3C8_CFC8();
        if (D_800F8FD0_F9BD0 == 1) {
            D_8010AF0C_1B459C_SkyPilots += 2;
            if (D_8010AF0C_1B459C_SkyPilots >= 0x4651) {
                D_8010AF0C_1B459C_SkyPilots = 0x4650;
                D_8010ADA0_1B4430_SkyPilots = -2;
            }
        }
        switch (D_800F8FD0_F9BD0) {
        case 0:
            if (D_8010AF10_1B45A0_SkyPilots == 5) {
                InitFadeIn(0, 0x10);
                PlaySound(0x4B0);
            }
            if (D_8010AF10_1B45A0_SkyPilots >= 6) {
                if (func_8008F618_90218() != 0) {
                    return;
                }
                if (D_8010AF28_1B45B8_SkyPilots == 0) {
                    D_8010AF28_1B45B8_SkyPilots = 1;
                }
                if (D_8010AF10_1B45A0_SkyPilots == 0x78) {
                    PlayMusic(0x24);
                }
                if (D_8010AF10_1B45A0_SkyPilots == 0x8C) {
                    func_800691FC_69DFC(0xF);
                }
                if (D_8010AF10_1B45A0_SkyPilots >= 0xB5) {
                    func_8010A340_1B39D0_SkyPilots();
                    func_8000C3B8_CFB8();
                }
            }
            D_8010AF10_1B45A0_SkyPilots++;
            break;
        case 1:
            if (D_8010AF0C_1B459C_SkyPilots == 0x4650) {
                D_8010ADA0_1B4430_SkyPilots = -2;
                func_8000C398_CF98();
            } else {
                D_8010AF14_1B45A4_SkyPilots -= 2;
            }
            break;
        case 2:
            if (D_8010AF18_1B45A8_SkyPilots == 0) {
                func_800794A8_7A0A8(0x5A);
                if (_CheckFlag(0xC) != 0) {
                    func_800691FC_69DFC(3);
                } else if (D_8010ADA0_1B4430_SkyPilots == -2) {
                    func_800691FC_69DFC(0x12);
                } else {
                    func_800691FC_69DFC(0x14);
                    func_800797DC_7A3DC(0x103, (s16)D_8010B2DC_1B496C_SkyPilots);
                    func_800797DC_7A3DC(0x103, (s16)D_8010B2E0_1B4970_SkyPilots);
                }
            } else {
                if (_CheckFlag(0xC) != 0) {
                    espDispOff(D_8010B2D0_1B4960_SkyPilots[0]);
                    espDispOff(D_8010B2D0_1B4960_SkyPilots[1]);
                    espDispOff(D_8010B2D4_1B4964_SkyPilots[0]);
                    espDispOff(D_8010B2D4_1B4964_SkyPilots[1]);
                    SprAttrSet(D_8010B350_1B49E0_SkyPilots[0], 0, 0x8000);
                    SprAttrSet(D_8010B350_1B49E0_SkyPilots[0], 1, 0x8000);
                    SprAttrSet(D_8010B350_1B49E0_SkyPilots[0], 2, 0x8000);
                    SprAttrSet(D_8010B350_1B49E0_SkyPilots[1], 0, 0x8000);
                    SprAttrSet(D_8010B350_1B49E0_SkyPilots[1], 1, 0x8000);
                    SprAttrSet(D_8010B350_1B49E0_SkyPilots[1], 2, 0x8000);
                    if (D_8010AF18_1B45A8_SkyPilots == 0x1E) {
                        if ((func_800680D4_68CD4(3) & 0xFFFF) > D_8010AF0C_1B459C_SkyPilots) {
                            func_800691FC_69DFC(0xE);
                            GWMgRecordSet(3, D_8010AF0C_1B459C_SkyPilots);
                            D_8010AF20_1B45B0_SkyPilots = 1;
                        }
                        if (D_8010B2DC_1B496C_SkyPilots == 0) {
                            gPlayers->coins_mg_bonus += 10;
                        }
                    }
                    if (D_8010AF20_1B45B0_SkyPilots == 0) {
                        if (D_8010AF18_1B45A8_SkyPilots == 0x3C) {
                            func_8000C3A8_CFA8();
                        }
                    } else if (D_8010AF18_1B45A8_SkyPilots == 0x5A) {
                        func_8000C3A8_CFA8();
                    }
                } else if (D_8010ADA0_1B4430_SkyPilots == -2) {
                    if (D_8010AF18_1B45A8_SkyPilots == 0x3C) {
                        func_800691FC_69DFC(0x13);
                        PlayMusic(0x57);
                    }
                    if (D_8010AF18_1B45A8_SkyPilots == 0xB4) {
                        func_8000C3A8_CFA8();
                    }
                } else {
                    espDispOff(D_8010B2D0_1B4960_SkyPilots[0]);
                    espDispOff(D_8010B2D0_1B4960_SkyPilots[1]);
                    espDispOff(D_8010B2D4_1B4964_SkyPilots[0]);
                    espDispOff(D_8010B2D4_1B4964_SkyPilots[1]);
                    SprAttrSet(D_8010B350_1B49E0_SkyPilots[0], 0, 0x8000);
                    SprAttrSet(D_8010B350_1B49E0_SkyPilots[0], 1, 0x8000);
                    SprAttrSet(D_8010B350_1B49E0_SkyPilots[0], 2, 0x8000);
                    SprAttrSet(D_8010B350_1B49E0_SkyPilots[1], 0, 0x8000);
                    SprAttrSet(D_8010B350_1B49E0_SkyPilots[1], 1, 0x8000);
                    SprAttrSet(D_8010B350_1B49E0_SkyPilots[1], 2, 0x8000);
                    if (D_8010AF18_1B45A8_SkyPilots == 0x1E) {
                        if ((func_800680D4_68CD4(3) & 0xFFFF) > D_8010AF0C_1B459C_SkyPilots) {
                            func_800691FC_69DFC(0xE);
                            _CheckFlag(0xC);
                            GWMgRecordSet(3, D_8010AF0C_1B459C_SkyPilots);
                            D_8010AF20_1B45B0_SkyPilots = 1;
                        }
                    }
                    if (D_8010AF20_1B45B0_SkyPilots == 0) {
                        if (D_8010AF18_1B45A8_SkyPilots == 0x3C) {
                            func_800691FC_69DFC(0x11, gPlayers[D_8010B2DC_1B496C_SkyPilots].character, gPlayers[D_8010B2E0_1B4970_SkyPilots].character);
                            gPlayers[D_8010B2DC_1B496C_SkyPilots].coins_mg_bonus += 10;
                            gPlayers[D_8010B2E0_1B4970_SkyPilots].coins_mg_bonus += 10;
                            PlayMusic(0x52);
                        }
                        if (D_8010AF18_1B45A8_SkyPilots == 0xE1) {
                            func_8000C3A8_CFA8();
                        }
                    } else {
                        if (D_8010AF18_1B45A8_SkyPilots == 0x5A) {
                            func_800691FC_69DFC(0x11, gPlayers[D_8010B2DC_1B496C_SkyPilots].character, gPlayers[D_8010B2E0_1B4970_SkyPilots].character);
                            gPlayers[D_8010B2DC_1B496C_SkyPilots].coins_mg_bonus += 10;
                            gPlayers[D_8010B2E0_1B4970_SkyPilots].coins_mg_bonus += 10;
                            PlayMusic(0x55);
                        }
                        if (D_8010AF18_1B45A8_SkyPilots == 0xFA) {
                            func_8000C3A8_CFA8();
                        }
                    }
                }
            }
            D_8010AF18_1B45A8_SkyPilots++;
            break;
        case 3:
            InitFadeOut(0, 0x14);
            func_800794A8_7A0A8(0x28);
            func_80079614_7A214(0x28);
            obj->func_ptr = func_80102D3C_1AC3CC_SkyPilots;
            D_8010AF1C_1B45AC_SkyPilots += 2;
            break;
        }
    }
    if (D_801011FC_101DFC == 1) {
        InitFadeOut(0, 0x14);
        func_800794A8_7A0A8(0x28);
        func_80079614_7A214(0x28);
        obj->func_ptr = func_80102D3C_1AC3CC_SkyPilots;
    }
    func_8010608C_1AF71C_SkyPilots(0, D_8010AF0C_1B459C_SkyPilots);
    func_801076E8_1B0D78_SkyPilots(obj);
    func_80102D68_1AC3F8_SkyPilots();
}

void func_8010369C_1ACD2C_SkyPilots(omObjData* obj) {
    SPPlane* w = obj->unk_50;
    u32 t;

    switch (w->spinKind) {
    case 1:
        t = w->timerA;
        if (t >= 11) {
            if (t >= 50) {
                t = 60 - t;
            } else {
                t = 10;
            }
        }
        if (++w->smoke >= 31) {
            w->smoke = 30;
        }
        w->spin += D_8010AF2C_1B45BC_SkyPilots[t];
        func_80029C74_2A874(obj->model[3], w->smoke);
        func_800298A4_2A4A4(obj->model[3], 4, 0);
        w->prop = func_8002D958_2E558(w->prop + D_8010AF2C_1B45BC_SkyPilots[t]);
        w->timerA++;
        if (w->spin > 1080.0f) {
            w->spinKind = 0;
            w->timerA = 0;
            w->spin = 0.0f;
            w->prop = 0.0f;
            w->smoke -= 10;
        }
        break;
    case 2:
        if (w->timerA != 0) {
            w->timerB = 60 - w->timerA;
            w->timerA = 0;
            w->spin = 0.0f;
            w->prop = 0.0f;
        }
        if (++w->smoke >= 31) {
            w->smoke = 30;
        }
        t = w->timerB;
        if (t >= 11) {
            if (t >= 80) {
                t = 90 - t;
            } else {
                t = 10;
            }
        }
        w->spin += D_8010AF2C_1B45BC_SkyPilots[t];
        func_80029C74_2A874(obj->model[3], w->smoke);
        func_800298A4_2A4A4(obj->model[3], 4, 0);
        w->prop = func_8002D958_2E558(w->prop + D_8010AF2C_1B45BC_SkyPilots[t]);
        w->timerB++;
        if (w->spin > 1440.0f) {
            w->spin = 0.0f;
            w->spinKind = 0;
            w->timerB = 0;
            w->prop = 0.0f;
            w->smoke -= 10;
        }
        break;
    default:
        func_80029C74_2A874(obj->model[3], w->smoke);
        w->smoke -= 5;
        if (w->smoke < 0) {
            w->smoke = 0;
            func_800298A4_2A4A4(obj->model[3], 4, 4);
        }
        break;
    }
}

void func_8010394C_1ACFDC_SkyPilots(omObjData* obj) {
    MgWork* p = obj->unk_50;
    omObjData* plane = D_8010ADA4_1B4434_SkyPilots[(gPlayers[p->unk_59].group >> 1) & 1];
    SPPlane* w = plane->unk_50;

    w->stickX = ContStkX[p->unk_57];
    w->stickY = ContStkY[p->unk_57];
    func_800B2060_B2C60(D_800FC834_FD434[obj->model[0]].mtx, 0.0f, 0.0f, -w->aileron - w->prop);
    obj->trans.x = plane->trans.x;
    obj->trans.y = plane->trans.y;
    obj->trans.z = plane->trans.z;
    obj->rot.x = plane->rot.x;
    obj->rot.y = plane->rot.y;
    obj->rot.z = plane->rot.z;
    func_80029C74_2A874(obj->model[0], *(f32*)&w->aileronFrame);
}

void func_80103A6C_1AD0FC_SkyPilots(omObjData* obj) {
    MgWork* p = obj->unk_50;
    omObjData* plane = D_8010ADA4_1B4434_SkyPilots[(gPlayers[p->unk_59].group >> 1) & 1];
    SPPlane* w = plane->unk_50;

    w->stickZ = ContStkY[p->unk_57];
    func_80029E80_2AA80(obj->model[0], 1, 1);
    if (func_80029E3C_2AA3C(obj->model[0]) == -1.0f) {
        func_80029CE4_2A8E4(obj->model[0]);
    }
    func_800B2060_B2C60(D_800FC834_FD434[obj->model[0]].mtx, 0.0f, 0.0f, -w->aileron - w->prop);
    obj->trans.x = plane->trans.x;
    obj->trans.y = plane->trans.y;
    obj->trans.z = plane->trans.z;
    obj->rot.x = plane->rot.x;
    obj->rot.y = plane->rot.y;
    obj->rot.z = plane->rot.z;
    func_80029C74_2A874(obj->model[0], *(f32*)&w->gunFrame);
}

void func_80103BC0_1AD250_SkyPilots(f32 m[4][4], Vec* at, Vec* axis, f32 angle) {
    f32 s;
    f32 c;
    f32 t;
    f32 x;
    f32 y;
    f32 z;
    f32 xy;
    f32 yz;
    f32 zx;
    f32 xx;
    f32 yy;
    f32 xs;
    f32 ys;
    f32 zs;
    f32 a;

    func_800B8070_B8C70(angle, &s, &c);
    t = 1.0f - c;
    x = axis->x;
    y = axis->y;
    z = axis->z;
    xy = x * y;
    yz = y * z;
    zx = z * x;
    xx = x * x;
    yy = y * y;
    xs = x * s;
    ys = y * s;
    zs = z * s;
    m[0][0] = t * xx + c;
    a = t * xy;
    m[0][1] = a + zs;
    m[0][2] = t * zx - ys;
    m[1][0] = a - zs;
    m[1][1] = t * yy + c;
    m[1][2] = t * yz + xs;
}

/* NON_MATCHING: register allocation */
#ifdef NON_MATCHING
void func_80103CA8_1AD338_SkyPilots(s32 team, f32 rx, f32 ry, f32 rz) {
    SPPlane* w = D_8010ADA4_1B4434_SkyPilots[team]->unk_50;
    f32 x = HuMathSin(ry) * func_800B7890_B8490(rx) * (D_800F94A8_FA0A8[team] - 200.0f) + D_801013B0_101FB0[team].x;
    f32 y = -HuMathSin(rx) * (D_800F94A8_FA0A8[team] - 200.0f) + D_801013B0_101FB0[team].y;
    f32 z = func_800B7890_B8490(ry) * func_800B7890_B8490(rx) * (D_800F94A8_FA0A8[team] - 200.0f) + D_801013B0_101FB0[team].z;

    func_80029714_2A314(D_8010B354_1B49E4_SkyPilots[team], x, y + w->pitch * 3.0f, z);
    func_8002979C_2A39C(D_8010B354_1B49E4_SkyPilots[team], 0.0f, D_80102770_103370[team].y, 0.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_SkyPilots/1ABE90", func_80103CA8_1AD338_SkyPilots);
#endif

/* NON_MATCHING: register allocation */
#ifdef NON_MATCHING
void func_80103E34_1AD4C4_SkyPilots(omObjData* obj) {
    Vec eye;
    Vec at;
    Vec3f up;
    f32 m[4][4];
    Vec3f dir;
    u8 i;
    f32 one = 1.0f;
    f32 zero = 0.0f;

    for (i = 0; i < obj->work[0]; i++) {
        f32 rx = D_80102770_103370[i].x;
        f32 ry = D_80102770_103370[i].y;

        func_80103CA8_1AD338_SkyPilots(i, rx, ry, D_80102770_103370[i].z);
        eye.x = HuMathSin(ry) * func_800B7890_B8490(rx) * D_800F94A8_FA0A8[i] + D_801013B0_101FB0[i].x;
        eye.y = -HuMathSin(rx) * D_800F94A8_FA0A8[i] + D_801013B0_101FB0[i].y;
        eye.z = func_800B7890_B8490(ry) * func_800B7890_B8490(rx) * D_800F94A8_FA0A8[i] + D_801013B0_101FB0[i].z;
        at.x = D_801013B0_101FB0[i].x;
        at.y = D_801013B0_101FB0[i].y;
        at.z = D_801013B0_101FB0[i].z;
        dir.x = at.x - eye.x;
        dir.y = at.y - eye.y;
        dir.z = at.z - eye.z;
        func_8002D9AC_2E5AC(&dir);
        func_80103BC0_1AD250_SkyPilots(m, &at, (Vec*)&dir, D_8010ADAC_1B443C_SkyPilots[i]);
        up.x = zero * m[0][0] + one * m[1][0];
        up.y = zero * m[0][1] + one * m[1][1];
        up.z = zero * m[0][2] + one * m[1][2];
        func_8002D9AC_2E5AC(&up);
        D_800FC8F8_FD4F8[i][1] = eye.x;
        D_800FC8F8_FD4F8[i][2] = eye.z;
        D_800FC8F8_FD4F8[i][0] = D_80102770_103370[i].y;
        D_800FC8F8_FD4F8[i][3] = 80.0f;
        D_800FC8F8_FD4F8[i][4] = 19000.0f;
        D_800FC8F8_FD4F8[i][5] = 2000.0f;
        Hu3DCamSetPositionOrientation(i, &eye, &at, (Vec*)&up);
        Hu3DCamUpdateMtx(i);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_SkyPilots/1ABE90", func_80103E34_1AD4C4_SkyPilots);
#endif

/* NON_MATCHING: register allocation */
#ifdef NON_MATCHING
void func_8010413C_1AD7CC_SkyPilots(omObjData* obj, f32 yawD, f32 yaw, f32 pitchD, f32 pitch) {
    SPPlane* w = obj->unk_50;
    s32 team = w->team;
    f32 lim;
    f32 v;

    if (yawD != 0.0f) {
        D_80102770_103370[team].y = yawD * 0.4f + D_80102770_103370[team].y;
    } else {
        v = D_80102770_103370[team].y;
        D_80102770_103370[team].y = (w->yaw + 180.0f - v) / 100.0f + v;
    }
    lim = w->yaw + 180.0f + 25.0f;
    if (lim < D_80102770_103370[team].y) {
        D_80102770_103370[team].y = lim;
    }
    lim = w->yaw + 180.0f - 25.0f;
    if (D_80102770_103370[team].y < lim) {
        D_80102770_103370[team].y = lim;
    }
    if (pitchD != 0.0f) {
        D_80102770_103370[team].x -= pitchD * 0.3f;
    } else {
        v = D_80102770_103370[team].x;
        D_80102770_103370[team].x = v - (v - -10.0f) / 100.0f;
    }
    if (D_80102770_103370[team].x > 0.0f) {
        D_80102770_103370[team].x = 0.0f;
    }
    if (D_80102770_103370[team].x < -20.0f) {
        D_80102770_103370[team].x = -20.0f;
    }
    D_801013B0_101FB0[team].x = obj->trans.x;
    D_801013B0_101FB0[team].y = obj->trans.y - (5.0f * D_80102770_103370[team].x - 20.0f);
    D_801013B0_101FB0[team].z = obj->trans.z;
    D_800F94A8_FA0A8[team] = w->speed * 5.0f + 500.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_SkyPilots/1ABE90", func_8010413C_1AD7CC_SkyPilots);
#endif

void func_80104454_1ADAE4_SkyPilots(f32 x, f32 y, f32 z, f32 d) {
    Vec3f v;

    v.x = x;
    v.y = y;
    v.z = z;
    func_8002D9AC_2E5AC(&v);
    D_8010B2C0_1B4950_SkyPilots += d * v.x;
    D_8010B2C0_1B4950_SkyPilots += d * v.y; /* sic: never pushes y */
    D_8010B2C8_1B4958_SkyPilots += d * v.z;
}

void func_801044D4_1ADB64_SkyPilots(omObjData* obj) {
    ((SPPlane*)obj->unk_50)->scale = 1.0f;
}

/* NON_MATCHING: register allocation */
#ifdef NON_MATCHING
void func_801044EC_1ADB7C_SkyPilots(omObjData* obj, f32 angle, f32 x, f32 y, f32 z) {
    SPPlane* w = obj->unk_50;
    s32 i = 0;

    if (D_800F8FD0_F9BD0 == 1) {
        f64 lim = 50.0;

        for (; i < 6; i++) {
            if (angle < D_8010ADF4_1B4484_SkyPilots[i].angle + 5.0f && D_8010ADF4_1B4484_SkyPilots[i].angle - 5.0f < angle) {
                Vec v;
                f32 vx;
                f32 vy;

                v.x = x;
                v.y = y;
                v.z = z;
                func_80104654_1ADCE4_SkyPilots(&v, i);
                vx = v.x;
                vy = v.y;
                if (fabs(v.z) < lim && func_800B1830_B2430(vx * vx + vy * vy) < 400.0f) {
                    if (w->spinKind == 0) {
                        w->timerA = 0;
                        w->lastGate = i;
                        w->spinKind = 1;
                    } else if (w->lastGate != i) {
                        w->timerB = 0;
                        w->lastGate = i;
                        w->spinKind = 2;
                    }
                    func_80079798_7A398(0x214, w->pilot);
                }
                return;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_SkyPilots/1ABE90", func_801044EC_1ADB7C_SkyPilots);
#endif

void func_80104654_1ADCE4_SkyPilots(Vec* v, s32 i) {
    f32 ang = D_8010ADF4_1B4484_SkyPilots[i].angle;
    f32 px = HuMathSin(ang) * (D_8010ADF4_1B4484_SkyPilots[i].radius + SP_RADIUS);
    f32 m = 0.0f;
    f32 pz = func_800B7890_B8490(ang) * (D_8010ADF4_1B4484_SkyPilots[i].radius + SP_RADIUS);
    f32 rot = D_8010ADF4_1B4484_SkyPilots[i].angle - 90.0f;
    f32 x = v->x;
    f32 y = v->y;
    f32 z = v->z;

    if (px != 0.0f || m != 0.0f || pz != 0.0f) {
        func_800B1F50_B2B50((f32*)D_8010B388_1B4A18_SkyPilots, px, m, pz);
    } else {
        func_800B37C0_B43C0((f32*)D_8010B388_1B4A18_SkyPilots);
    }
    if (rot != 0.0f) {
        func_80025884_26484(D_8010B388_1B4A18_SkyPilots, 0.0f, rot, 0.0f);
    }
    func_8001B170_1BD70(D_8010B388_1B4A18_SkyPilots, D_8010B3C8_1B4A58_SkyPilots);
    v->x = x * D_8010B3C8_1B4A58_SkyPilots[0][0] + y * D_8010B3C8_1B4A58_SkyPilots[1][0] + z * D_8010B3C8_1B4A58_SkyPilots[2][0] + D_8010B3C8_1B4A58_SkyPilots[3][0];
    v->y = x * D_8010B3C8_1B4A58_SkyPilots[0][1] + y * D_8010B3C8_1B4A58_SkyPilots[1][1] + z * D_8010B3C8_1B4A58_SkyPilots[2][1] + D_8010B3C8_1B4A58_SkyPilots[3][1];
    v->z = x * D_8010B3C8_1B4A58_SkyPilots[0][2] + y * D_8010B3C8_1B4A58_SkyPilots[1][2] + z * D_8010B3C8_1B4A58_SkyPilots[2][2] + D_8010B3C8_1B4A58_SkyPilots[3][2];
}

void func_8010489C_1ADF2C_SkyPilots(omObjData* obj, f32 angle, f32 x, f32 y, f32 z) {
    f32 d = func_800B1830_B2430(x * x + z * z);
    f32 r = 11532.405f;

    if (d < 11532.405f) {
        func_80104454_1ADAE4_SkyPilots(x, 0.0f, z, -(d - r));
        return;
    }
    r = 13932.405f;
    if (d > 13932.405f) {
        func_80104454_1ADAE4_SkyPilots(x, 0.0f, z, -(d - r));
    }
}

/* NON_MATCHING: register allocation */
#ifdef NON_MATCHING
void func_80104940_1ADFD0_SkyPilots(omObjData* obj, f32 x, f32 y, f32 z) {
    SPPlane* w = obj->unk_50;
    s32 k = w->team == 0;
    omObjData* other = D_8010ADA4_1B4434_SkyPilots[k];
    f32 dx;
    f32 dy;
    f32 dz;
    f32 d;

    dx = other->trans.x - x;
    dy = other->trans.y - y;
    dz = other->trans.z - z;
    d = func_800B1830_B2430(dx * dx + dy * dy + dz * dz);

    if (d < 200.0f) {
        func_80104454_1ADAE4_SkyPilots(dx, dy, dz, d - 200.0f);
        if (w->bump == 0) {
            omVibrate(w->pilot, 10, 0, 10);
            omVibrate(w->gunner, 10, 0, 10);
            w->bump = 20;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_SkyPilots/1ABE90", func_80104940_1ADFD0_SkyPilots);
#endif

/* NON_MATCHING: register allocation */
#ifdef NON_MATCHING
void func_80104A4C_1AE0DC_SkyPilots(omObjData* obj, f32 angle, f32 x, f32 y, f32 z) {
    SPPlane* w = obj->unk_50;
    s32 i;

    for (i = 0; i < 2; i++) {
        f32 a = D_8010ADDC_1B446C_SkyPilots[i].angle;

        if (angle < a + 5.0f && a - 5.0f < angle) {
            f32 px = HuMathSin(a) * (D_8010ADDC_1B446C_SkyPilots[i].radius + SP_RADIUS);
            f32 zero = 0.0f;
            f32 pz = func_800B7890_B8490(a) * (D_8010ADDC_1B446C_SkyPilots[i].radius + SP_RADIUS);
            f32 dx = px - x;
            f32 dz = pz - z;
            f32 r = D_8010ADDC_1B446C_SkyPilots[i].extra;
            f32 d = func_800B1830_B2430(dx * dx + dz * dz);

            r = r * 500.0f + 100.0f;
            if (d < r) {
                func_80104454_1ADAE4_SkyPilots(dx, zero, dz, d - r);
                if (w->bump == 0) {
                    omVibrate(w->pilot, 10, 0, 10);
                    omVibrate(w->gunner, 10, 0, 10);
                    w->bump = 20;
                }
            }
            return;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_SkyPilots/1ABE90", func_80104A4C_1AE0DC_SkyPilots);
#endif

void func_80104C10_1AE2A0_SkyPilots(omObjData* obj, f32 angle, f32 x, f32 y, f32 z) {
    SPPlane* w = obj->unk_50;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_8010AEA8_1B4538_SkyPilots[i] > 0) {
            f32 dx = D_8010AEDC_1B456C_SkyPilots[i].x;
            f32 dy = D_8010AEDC_1B456C_SkyPilots[i].y;
            f32 dz = D_8010AEDC_1B456C_SkyPilots[i].z;

            dx -= x;
            dy -= y;
            dz -= z;
            if (func_800B1830_B2430(dx * dx + dy * dy + dz * dz) < 150.0f) {
                func_8010890C_1B1F9C_SkyPilots(i);
                omVibrate(w->pilot, 2, 2, 20);
                omVibrate(w->gunner, 2, 2, 20);
                D_8010ADCC_1B445C_SkyPilots[w->team][i]++;
                w->hit = 1;
                w->hitSlow = 70.0f;
                w->hitSpin += 720.0f;
                if (D_800F8FD0_F9BD0 == 1) {
                    func_800797DC_7A3DC(0x111, w->pilot);
                    func_800797DC_7A3DC(0x111, w->gunner);
                }
                return;
            }
        }
    }
}

void func_80104DC0_1AE450_SkyPilots(omObjData* obj, f32 angle, f32 x, f32 y, f32 z) {
    SPPlane* w = obj->unk_50;
    s32 i;

    for (i = 0; i < 5; i++) {
        f32 a;

        if (D_8010ADD4_1B4464_SkyPilots[i] != 0) {
            continue;
        }
        a = D_8010AE6C_1B44FC_SkyPilots[i].angle;
        if (angle < a + 2.0f && a - 2.0f < angle) {
            f32 dx = HuMathSin(a) * (D_8010AE6C_1B44FC_SkyPilots[i].radius + SP_RADIUS);
            f32 dy = D_8010AE6C_1B44FC_SkyPilots[i].extra;
            f32 dz = func_800B7890_B8490(a) * (D_8010AE6C_1B44FC_SkyPilots[i].radius + SP_RADIUS);

            dx -= x;
            dy -= y;
            dz -= z;
            if (func_800B1830_B2430(dx * dx + dy * dy + dz * dz) < 300.0f) {
                func_80108A00_1B2090_SkyPilots(i);
                omVibrate(w->pilot, 2, 2, 20);
                omVibrate(w->gunner, 2, 2, 20);
                w->hit = 1;
                w->hitSlow = 70.0f;
                w->hitSpin += 720.0f;
                D_8010ADD4_1B4464_SkyPilots[i] = 1;
                if (D_800F8FD0_F9BD0 == 1) {
                    func_800797DC_7A3DC(0x111, w->pilot);
                    func_800797DC_7A3DC(0x111, w->gunner);
                }
                return;
            }
        }
    }
}

void func_80105018_1AE6A8_SkyPilots(omObjData* obj, f32 x, f32 y, f32 z) {
    SPPlane* w = obj->unk_50;
    f32 angle = func_800B75A8_B81A8(x, z);
    s32 i;

    if (angle < 0.0f) {
        angle += 360.0f;
    }
    D_8010B2C0_1B4950_SkyPilots = D_8010B2C4_1B4954_SkyPilots = D_8010B2C8_1B4958_SkyPilots = 0.0f;
    for (i = 0; i < 6; i++) {
        switch (i) {
        case 0:
            func_80104940_1ADFD0_SkyPilots(obj, x, y, z);
            break;
        case 1:
            func_8010489C_1ADF2C_SkyPilots(obj, angle, x, y, z);
            break;
        case 2:
            func_80104A4C_1AE0DC_SkyPilots(obj, angle, x, y, z);
            break;
        case 3:
            func_80104C10_1AE2A0_SkyPilots(obj, angle, x, y, z);
            break;
        case 4:
            func_801044EC_1ADB7C_SkyPilots(obj, angle, x, y, z);
            break;
        case 5:
            func_80104DC0_1AE450_SkyPilots(obj, angle, x, y, z);
            break;
        }
    }
    if (w->bump != 0) {
        w->bump--;
    }
}

f32 func_801051F0_1AE880_SkyPilots(SPPlane* w, f32 v) {
    f32 sum = 0.0f;
    u8 i;

    w->yawHist[w->yawPos++] = v;
    if (w->yawPos >= 20) {
        w->yawPos = 0;
    }
    for (i = 0; i < 20; i++) {
        sum += w->yawHist[i];
    }
    return sum / 20.0f;
}

f32 func_80105258_1AE8E8_SkyPilots(SPPlane* w, f32 v) {
    f32 sum = 0.0f;
    u8 i;

    w->pitchHist[w->pitchPos++] = v;
    if (w->pitchPos >= 20) {
        w->pitchPos = 0;
    }
    for (i = 0; i < 20; i++) {
        sum += w->pitchHist[i];
    }
    return sum / 20.0f;
}

void func_801052C0_1AE950_SkyPilots(omObjData* obj, f32 in) {
    SPPlane* w = obj->unk_50;
    f32 v = in * 10.0f;

    if (v > 10.0f) {
        v = 10.0f;
    }
    if (v < -10.0f) {
        v = -10.0f;
    }
    if (v != 0.0f) {
        w->aileron += v * 0.05f;
        if (w->aileron > 0.0f) {
            if (w->aileron > v) {
                w->aileron *= 0.9f;
            }
        } else if (w->aileron < v) {
            w->aileron *= 0.9f;
        }
    } else {
        w->aileron *= 0.9f;
    }
    *(f32*)&w->aileronFrame = 10.0f - w->aileron;
    func_80029C74_2A874(obj->model[1], *(f32*)&w->aileronFrame);
}

void func_80105400_1AEA90_SkyPilots(omObjData* obj, f32 in) {
    SPPlane* w = obj->unk_50;
    f32 v = in * 20.0f;

    if (v > 10.0f) {
        v = 10.0f;
    }
    if (v < -10.0f) {
        v = -10.0f;
    }
    if (v != 0.0f) {
        w->elevator += v * 0.05f;
        if (w->elevator > 0.0f) {
            if (w->elevator > v) {
                w->elevator *= 0.9f;
            }
        } else if (w->elevator < v) {
            w->elevator *= 0.9f;
        }
    } else {
        w->elevator *= 0.9f;
    }
    func_80029C74_2A874(obj->model[2], 10.0f - w->elevator);
}

void func_80105548_1AEBD8_SkyPilots(omObjData* obj, f32 in) {
    SPPlane* w = obj->unk_50;

    if (obj->trans.y > 600.0f) {
        obj->trans.y = 600.0f;
        w->pitch *= 0.9f;
    }
    if (obj->trans.y < -500.0f) {
        obj->trans.y = -500.0f;
        w->pitch *= 0.9f;
    }
    if (in == 0.0f) {
        w->pitch *= 0.95f;
    }
}

void func_8010560C_1AEC9C_SkyPilots(omObjData* obj) {
    SPPlane* w = obj->unk_50;
    f32 speed = w->speed;
    f32 in = w->stickZ / 60.0f;
    f32 frame;
    f32 d;

    if (in > 1.0f) {
        in = 1.0f;
    }
    if (in < -1.0f) {
        in = -1.0f;
    }
    w->pad[3] = w->pad[2];
    w->pad[2] = w->pad[1];
    w->pad[1] = w->pad[0];
    w->pad[0] = in;
    frame = func_80029CE4_2A8E4(obj->model[0]);
    d = (in + 1.0f) * 10.0f - frame;
    if (d > 1.0f) {
        frame += 1.5f;
        w->brake = 0.0f;
    } else if (d < -1.0f) {
        if (frame > 16.0f && D_800F8FD0_F9BD0 < 2U) {
            func_80079798_7A398(0x213, w->gunner);
        }
        frame -= 2.0f;
        speed += w->brake;
        w->brake += 0.3f;
    } else {
        w->brake = 0.0f;
    }
    if (frame < 0.0f) {
        frame = 0.0f;
    }
    if (frame > 20.0f) {
        frame = 20.0f;
    }
    *(f32*)&w->gunFrame = frame;
    func_80029C74_2A874(obj->model[0], frame);
    if (speed > 10.0f) {
        speed -= 0.25f;
    }
    if (speed > 30.0f) {
        speed *= 0.97f;
    }
    if (speed < 10.0f) {
        speed = 10.0f;
    }
    w->speed = speed;
}

void func_80105890_1AEF20_SkyPilots(omObjData* obj) {
    SPPlane* w = obj->unk_50;

    if (w->speed < 50.0f) {
        w->brake = 1.0f;
        w->speed += 1.0f;
        if (w->speed > 50.0f) {
            w->speed = 50.0f;
        }
    }
}

/* NON_MATCHING: register allocation */
#ifdef NON_MATCHING
void func_801058EC_1AEF7C_SkyPilots(omObjData* obj) {
    SPPlane* w = obj->unk_50;
    f32 yawIn;
    f32 pitchIn;
    f32 speed;
    f32 yawD;
    f32 pitchD;

    if (D_800F8FD0_F9BD0 == 1) {
        func_8010A8F4_1B3F84_SkyPilots(obj);
        func_8010AB84_1B4214_SkyPilots(obj);
    } else if (D_800F8FD0_F9BD0 - 2U < 2 && D_8010ADB4_1B4444_SkyPilots != w->team) {
        w->stickZ = 0;
        w->stickX = 0;
        w->stickY = 0;
    }
    if (w->hit == 1) {
        w->stickZ = 0;
        w->stickY = 0;
        w->stickX = 0;
    }
    if (w->spinKind == 0) {
        yawIn = -w->stickX / 60.0f;
        pitchIn = w->stickY / 120.0f;
        func_8010560C_1AEC9C_SkyPilots(obj);
    } else {
        func_80029C74_2A874(obj->model[0], 10.0f);
        func_80105890_1AEF20_SkyPilots(obj);
        pitchIn = 0.0f;
        yawIn = 0.0f;
    }
    speed = w->speed;
    if (w->hit == 1) {
        w->stickZ = 0;
        w->stickY = 0;
        w->stickX = 0;
        speed -= w->hitSlow;
        w->hitSlow -= 1.2f;
        w->hitSpin -= 14.4f;
        if (w->hitSpin < 0.0f) {
            w->hitSlow = 0.0f;
            w->hit = 0;
            w->hitSpin = 0.0f;
        }
    }
    func_801052C0_1AE950_SkyPilots(obj, yawIn);
    yawD = func_801051F0_1AE880_SkyPilots(w, yawIn);
    if (w->spinKind == 0) {
        w->yaw += yawD;
    }
    if (D_8010B430_1B4AC0_SkyPilots[w->team] + 90.0f + 30.0f < w->yaw) {
        w->yaw = D_8010B430_1B4AC0_SkyPilots[w->team] + 90.0f + 30.0f;
    }
    if (w->yaw < D_8010B430_1B4AC0_SkyPilots[w->team] + 90.0f - 30.0f) {
        w->yaw = D_8010B430_1B4AC0_SkyPilots[w->team] + 90.0f - 30.0f;
    }
    D_8010ADAC_1B443C_SkyPilots[w->team] = yawD * 3.0f;
    func_80105400_1AEA90_SkyPilots(obj, pitchIn);
    pitchD = func_80105258_1AE8E8_SkyPilots(w, pitchIn);
    if (w->spinKind == 0) {
        w->pitch += pitchD;
    }
    if (w->pitch > 20.0f) {
        w->pitch = 20.0f;
    }
    if (w->pitch < -10.0f) {
        w->pitch = -10.0f;
    }
    func_80105548_1AEBD8_SkyPilots(obj, pitchIn);
    func_8010369C_1ACD2C_SkyPilots(obj);
    obj->trans.x += HuMathSin(w->yaw) * speed;
    obj->trans.z += func_800B7890_B8490(w->yaw) * speed;
    obj->trans.y -= w->pitch * 0.5f;
    func_80105018_1AE6A8_SkyPilots(obj, obj->trans.x, obj->trans.y, obj->trans.z);
    obj->trans.x += D_8010B2C0_1B4950_SkyPilots;
    obj->trans.y += D_8010B2C4_1B4954_SkyPilots;
    obj->trans.z += D_8010B2C8_1B4958_SkyPilots;
    func_801044D4_1ADB64_SkyPilots(obj);
    obj->rot.y = w->yaw;
    obj->rot.x = w->pitch + obj->rot.y;
    func_800B2060_B2C60(D_800FC834_FD434[obj->model[0]].mtx, 0.0f, 0.0f, -w->aileron - w->prop);
    func_800B2060_B2C60(D_800FC834_FD434[obj->model[1]].mtx, 0.0f, 0.0f, -w->aileron - w->prop);
    func_800B2060_B2C60(D_800FC834_FD434[obj->model[2]].mtx, 0.0f, 0.0f, -w->aileron - w->prop);
    func_800B2060_B2C60(D_800FC834_FD434[obj->model[3]].mtx, 0.0f, 0.0f, -w->aileron - w->prop);
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
    func_8002979C_2A39C(obj->model[1], obj->rot.x, obj->rot.y, obj->rot.z);
    func_80029714_2A314(obj->model[2], obj->trans.x, obj->trans.y, obj->trans.z);
    func_8002979C_2A39C(obj->model[2], obj->rot.x, obj->rot.y, obj->rot.z);
    func_80029714_2A314(obj->model[3], obj->trans.x, obj->trans.y, obj->trans.z);
    func_8002979C_2A39C(obj->model[3], obj->rot.x, obj->rot.y, obj->rot.z);
    obj->scale.y = obj->scale.z = w->scale;
    func_800297E8_2A3E8(obj->model[1], obj->scale.x, obj->scale.y, obj->scale.z);
    func_800297E8_2A3E8(obj->model[2], obj->scale.x, obj->scale.y, obj->scale.z);
    D_8010B430_1B4AC0_SkyPilots[w->team] = func_800B75A8_B81A8(obj->trans.x, obj->trans.z);
    if (D_8010B430_1B4AC0_SkyPilots[w->team] < 0.0f) {
        D_8010B430_1B4AC0_SkyPilots[w->team] += 360.0f;
    }
    func_8010413C_1AD7CC_SkyPilots(obj, yawD, w->yaw, pitchD, w->pitch);
    if (D_8010ADA0_1B4430_SkyPilots != -3) {
        func_80106A7C_1B010C_SkyPilots(w->team, 2.0f * w->speed);
    }
    w->progress = (D_8010B430_1B4AC0_SkyPilots[w->team] - 30.0f) / 216.0f;
    if (D_800F8FD0_F9BD0 == 1 && D_8010B430_1B4AC0_SkyPilots[w->team] >= 246.0f && D_8010ADB4_1B4444_SkyPilots < 0) {
        D_8010B2DC_1B496C_SkyPilots = w->pilot;
        D_8010B2E0_1B4970_SkyPilots = w->gunner;
        D_8010ADB4_1B4444_SkyPilots = w->team;
        D_8010ADA0_1B4430_SkyPilots = -3;
        obj->func_ptr = func_8010A768_1B3DF8_SkyPilots;
        func_8000C398_CF98();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_SkyPilots/1ABE90", func_801058EC_1AEF7C_SkyPilots);
#endif

void func_8010608C_1AF71C_SkyPilots(idx, time)
s16 idx;
s16 time;
{
    s16 g;
    s16 d;
    s16 sec;
    s16 cs;

    g = D_8010B34C_1B49DC_SkyPilots[idx];
    SprAttrReset(g, 0, 0x8000);
    d = time / 3600;
    func_800822A8_82EA8(g, 0, d, 0);
    func_8008225C_82E5C(g, 0, 1);
    time -= d * 3600;
    SprAttrReset(g, 1, 0x8000);
    func_800822A8_82EA8(g, 1, 10, 0);
    func_8008225C_82E5C(g, 1, 1);
    SprAttrReset(g, 2, 0x8000);
    d = time / 600;
    func_800822A8_82EA8(g, 2, d, 0);
    func_8008225C_82E5C(g, 2, 1);
    time -= d * 600;
    sec = time / 60;
    SprAttrReset(g, 3, 0x8000);
    func_800822A8_82EA8(g, 3, sec, 0);
    func_8008225C_82E5C(g, 3, 1);
    cs = time * 100 / 60 - sec * 100;
    SprAttrReset(g, 4, 0x8000);
    func_800822A8_82EA8(g, 4, 11, 0);
    func_8008225C_82E5C(g, 4, 1);
    SprAttrReset(g, 5, 0x8000);
    func_800822A8_82EA8(g, 5, cs / 10, 0);
    func_8008225C_82E5C(g, 5, 1);
    cs %= 10;
    SprAttrReset(g, 6, 0x8000);
    func_800822A8_82EA8(g, 6, cs, 0);
    func_8008225C_82E5C(g, 6, 1);
}

void func_80106384_1AFA14_SkyPilots(void) {
    void* data;

    data = DataRead(0x43);
    D_8010B344_1B49D4_SkyPilots = SprAnimRead(data);
    DataClose(data);
}

void func_801063C4_1AFA54_SkyPilots(void) {
    void* data;

    data = DataRead(0x43);
    D_8010B346_1B49D6_SkyPilots = SprAnimRead(data);
    DataClose(data);
    func_8001A340_1AF40(D_8010B346_1B49D6_SkyPilots, 0.0f, 1.0f, 0.0f);
}

/* NON_MATCHING: register allocation */
#ifdef NON_MATCHING
s16 func_8010641C_1AFAAC_SkyPilots(s32 x, s16 y) {
    s16 i;
    s16 px;
    s16 win;

    win = SprCreate(7, 5);
    D_8010B34C_1B49DC_SkyPilots[0] = win;
    SprAnimSet(win, 0, D_8010B344_1B49D4_SkyPilots, 0);
    SprAttrReset(win, 0, 0xFFFF);
    SprAttrSet(win, 0, 0x8000);
    SprPosSet(win, 0, x - 0x10, y);
    SprPrioSet(win, 0, 1);
    px = 4;
    for (i = 1; i < 7; i++) {
        SprPrioSet(win, i, 1);
        SprAnimSet(win, i, D_8010B344_1B49D4_SkyPilots, 0);
        SprPosSet(win, i, px, 0);
        SprAttrReset(win, i, 0xFFFF);
        SprAttrSet(win, i, 0x8000);
        if (i == 3) {
            px += 8;
        } else {
            px += 12;
        }
        func_800824F4_830F4(win, i, 0);
    }
    SprAttrReset(win, 2, 0x8000);
    return win;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_SkyPilots/1ABE90", func_8010641C_1AFAAC_SkyPilots);
#endif

/* NON_MATCHING: register allocation */
#ifdef NON_MATCHING
s16 func_801065CC_1AFC5C_SkyPilots(s32 x, s16 y) {
    s16 i;
    s16 px;
    s16 win;

    win = SprCreate(7, 5);
    D_8010B34C_1B49DC_SkyPilots[1] = win;
    SprAnimSet(win, 0, D_8010B346_1B49D6_SkyPilots, 0);
    SprAttrReset(win, 0, 0xFFFF);
    SprAttrSet(win, 0, 0x8000);
    SprPosSet(win, 0, x - 0x10, y);
    SprPrioSet(win, 0, 1);
    px = 4;
    for (i = 1; i < 7; i++) {
        SprPrioSet(win, i, 1);
        SprAnimSet(win, i, D_8010B346_1B49D6_SkyPilots, 0);
        SprPosSet(win, i, px, 0);
        SprAttrReset(win, i, 0xFFFF);
        SprAttrSet(win, i, 0x8000);
        if (i == 3) {
            px += 8;
        } else {
            px += 12;
        }
        func_800824F4_830F4(win, i, 0);
    }
    SprAttrReset(win, 2, 0x8000);
    return win;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_SkyPilots/1ABE90", func_801065CC_1AFC5C_SkyPilots);
#endif

void func_8010677C_1AFE0C_SkyPilots(void) {
    void* data;

    data = DataRead(0x43);
    D_8010B348_1B49D8_SkyPilots[0] = SprAnimRead(data);
    DataClose(data);
    data = DataRead(0x43);
    D_8010B348_1B49D8_SkyPilots[1] = SprAnimRead(data);
    DataClose(data);
    D_8010B2D8_1B4968_SkyPilots = func_8001A2F8_1AEF8(0x10016);
    D_8010B2DA_1B496A_SkyPilots = func_8001A2F8_1AEF8(0x10015);
}

s16 func_80106810_1AFEA0_SkyPilots(s32 idx, s16 x, s16 y) {
    s16 i;
    s16 px;
    s16 win;

    win = D_8010B350_1B49E0_SkyPilots[idx] = SprCreate(3, 5);
    SprAnimSet(win, 0, D_8010B348_1B49D8_SkyPilots[idx], 0);
    SprAttrReset(win, 0, 0xFFFF);
    SprAttrSet(win, 0, 0x8000);
    SprPosSet(win, 0, x, y);
    SprPrioSet(win, 0, 6);
    px = 10;
    for (i = 1; i < 3; i++) {
        SprPrioSet(win, i, 6);
        SprAnimSet(win, i, D_8010B348_1B49D8_SkyPilots[idx], 0);
        SprPosSet(win, i, px, 0);
        SprAttrReset(win, i, 0xFFFF);
        SprAttrSet(win, i, 0x8000);
        px += 10;
        func_800824F4_830F4(win, i, 0);
    }
    SprAttrReset(win, 2, 0x8000);
    D_8010B2D0_1B4960_SkyPilots[idx] = func_8001AAAC_1B6AC(D_8010B2DA_1B496A_SkyPilots, 0, 1);
    espPosSet(D_8010B2D0_1B4960_SkyPilots[idx], px + 0x28, y);
    func_8001A788_1B388(D_8010B2D0_1B4960_SkyPilots[idx], 6);
    D_8010B2D4_1B4964_SkyPilots[idx] = func_8001AAAC_1B6AC(D_8010B2D8_1B4968_SkyPilots, 0, 1);
    espPosSet(D_8010B2D4_1B4964_SkyPilots[idx], px + 0x14, y);
    func_8001A788_1B388(D_8010B2D4_1B4964_SkyPilots[idx], 6);
    espDispOff(D_8010B2D4_1B4964_SkyPilots[idx]);
    return win;
}

/* NON_MATCHING: register allocation */
#ifdef NON_MATCHING
void func_80106A7C_1B010C_SkyPilots(s16 idx, s16 speed) {
    u16 g = D_8010B350_1B49E0_SkyPilots[idx];
    s32 n;

    if (speed == 100.0f) {
        espDispOn(D_8010B2D4_1B4964_SkyPilots[idx]);
        espDispOff(D_8010B2D0_1B4960_SkyPilots[idx]);
        SprAttrSet(g, 0, 0x8000);
        SprAttrSet(g, 1, 0x8000);
        SprAttrSet(g, 2, 0x8000);
        return;
    }
    n = speed / 1.6093f;
    espDispOff(D_8010B2D4_1B4964_SkyPilots[idx]);
    espDispOn(D_8010B2D0_1B4960_SkyPilots[idx]);
    SprAttrReset(g, 0, 0x8000);
    func_800822A8_82EA8(g, 0, n / 100, 0);
    func_8008225C_82E5C(g, 0, 1);
    SprAttrReset(g, 1, 0x8000);
    func_800822A8_82EA8(g, 1, (n % 100) / 10, 0);
    func_8008225C_82E5C(g, 1, 1);
    SprAttrReset(g, 2, 0x8000);
    func_800822A8_82EA8(g, 2, (n % 100) % 10, 0);
    func_8008225C_82E5C(g, 2, 1);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_SkyPilots/1ABE90", func_80106A7C_1B010C_SkyPilots);
#endif

void func_80106CD0_1B0360_SkyPilots(omObjData* obj) {
    SPPlane* w = func_80027154_27D54(sizeof(SPPlane), 0x7918);

    obj->unk_50 = w;
    func_800B0EF0_B1AF0(w, 0, sizeof(SPPlane));
    D_80101300_101F00 = 0.8f;
    D_8010105C_101C5C = 0.8f;
    obj->model[0] = LoadFormFile(0x2C0000, 0x208D9);
    obj->model[1] = LoadFormFile(0x2C0002, 0x208D9);
    obj->model[2] = LoadFormFile(0x2C0004, 0x208D9);
    obj->model[3] = LoadFormFile(0x2C0017, 0x208DD);
    obj->func_ptr = func_8010A6C0_1B3D50_SkyPilots;
    func_80029E80_2AA80(obj->model[0], 1, 1);
    func_80029E80_2AA80(obj->model[1], 2, 2);
    func_80029E80_2AA80(obj->model[2], 2, 2);
    func_80029E80_2AA80(obj->model[3], 1, 1);
    w->yaw = 90.0f;
    w->speed = 0.0f;
    w->pilot = 0;
    w->gunner = 0;
    w->pilotObj = NULL;
    w->gunnerObj = NULL;
    w->hit = 0;
    w->spinKind = 0;
    w->lastGate = 0;
    w->timerA = 0;
    w->team = 0;
    D_8010ADA4_1B4434_SkyPilots[0] = obj;
    obj->trans.x = HuMathSin(0.0f) * 12232.405f;
    obj->trans.y = 0.0f;
    obj->trans.z = func_800B7890_B8490(0.0f) * 12232.405f;
    D_80101300_101F00 = 1.0f;
    D_8010105C_101C5C = 1.0f;
}

/* NON_MATCHING: register allocation */
#ifdef NON_MATCHING
void func_80106E98_1B0528_SkyPilots(omObjData* obj) {
    SPPlane* w = func_80027154_27D54(sizeof(SPPlane), 0x7918);

    obj->unk_50 = w;
    func_800B0EF0_B1AF0(w, 0, sizeof(SPPlane));
    D_80101300_101F00 = 0.8f;
    D_8010105C_101C5C = 0.8f;
    obj->model[0] = LoadFormFile(0x2C0001, 0x208D9);
    obj->model[1] = LoadFormFile(0x2C0003, 0x208D9);
    obj->model[2] = LoadFormFile(0x2C0005, 0x208D9);
    obj->model[3] = LoadFormFile(0x2C0017, 0x208DD);
    obj->func_ptr = func_8010A6C0_1B3D50_SkyPilots;
    func_80029E80_2AA80(obj->model[0], 1, 1);
    func_80029E80_2AA80(obj->model[1], 2, 2);
    func_80029E80_2AA80(obj->model[2], 2, 2);
    func_80029E80_2AA80(obj->model[3], 1, 1);
    w->yaw = 90.0f;
    w->speed = 0.0f;
    w->pilot = 0;
    w->gunner = 0;
    w->pilotObj = NULL;
    w->gunnerObj = NULL;
    w->hit = 0;
    w->spinKind = 0;
    w->lastGate = 0;
    w->timerA = 0;
    w->team = 1;
    D_8010ADA4_1B4434_SkyPilots[1] = obj;
    obj->trans.x = HuMathSin(2.0f) * 13232.405f;
    obj->trans.y = 0.0f;
    obj->trans.z = func_800B7890_B8490(2.0f) * 13232.405f;
    D_80101300_101F00 = 1.0f;
    D_8010105C_101C5C = 1.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_SkyPilots/1ABE90", func_80106E98_1B0528_SkyPilots);
#endif

/* NON_MATCHING: register allocation */
#ifdef NON_MATCHING
void func_80107074_1B0704_SkyPilots(omObjData* obj, s32 dir, s32 file, s32 team, s32 player) {
    SPPlane* s = D_8010ADA4_1B4434_SkyPilots[team]->unk_50;
    MgWork* w;
    omObjData** sub;
    s32 i;
    s32 icon;

    for (i = 0; i < obj->mdlcnt; i++) {
        obj->model[i] = 0;
    }
    obj->unk_50 = func_80027154_27D54(sizeof(MgWork), 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, sizeof(MgWork));
    w = obj->unk_50;
    w->unk_E8 = func_80027154_27D54(obj->mtncnt * 12, 0x7918);
    D_80101300_101F00 = 0.8f;
    D_8010105C_101C5C = 0.8f;
    obj->model[0] = LoadFormFile(dir | file, 0x20A99);
    for (i = 0; i < obj->mtncnt; i++) {
        obj->motion[i] = -1;
    }
    for (i = 0; i < obj->mtncnt; i++) {
        ((MgMotion*)w->unk_E8)[i].unk_00 = 0;
        ((MgMotion*)w->unk_E8)[i].unk_02 = 0;
        ((MgMotion*)w->unk_E8)[i].unk_04 = -1;
        ((MgMotion*)w->unk_E8)[i].unk_08 = -1;
    }
    obj->func_ptr = func_8010394C_1ACFDC_SkyPilots;
    w->unk_52 = 0;
    w->unk_B4 = 1.0f;
    w->unk_D0 = 0xFFFF;
    w->unk_60 = 0.0f;
    w->unk_57 = gPlayers[player].port;
    func_8000BE74_CA74(obj, 1000.0f);
    w->unk_9C = w->unk_A0 = w->unk_A4 = 0.0f;
    w->unk_C4 = -1;
    w->unk_59 = player;
    s->pilot = player;
    s->pilotObj = obj;
    sub = &D_8010ADA4_1B4434_SkyPilots[team];
    obj->trans.x = (*sub)->trans.x;
    obj->trans.y = (*sub)->trans.y;
    obj->trans.z = (*sub)->trans.z;
    obj->rot.x = (*sub)->rot.x;
    obj->rot.y = (*sub)->rot.y;
    obj->rot.z = (*sub)->rot.z;
    switch (gPlayers[player].character) {
    case 0:
        icon = 0xD;
        break;
    case 1:
        icon = 0xE;
        break;
    case 2:
        icon = 0xF;
        break;
    case 3:
        icon = 0x10;
        break;
    case 4:
        icon = 0x11;
        break;
    case 5:
        icon = 0x12;
        break;
    }
    s->icon[0] = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(icon | 0x290000), 0, 1);
    func_8001A788_1B388(s->icon[0], 9 - team * 2);
    D_80101300_101F00 = 1.0f;
    D_8010105C_101C5C = 1.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_SkyPilots/1ABE90", func_80107074_1B0704_SkyPilots);
#endif

/* NON_MATCHING: register allocation */
#ifdef NON_MATCHING
void func_801073A8_1B0A38_SkyPilots(omObjData* obj, s32 dir, s32 file, s32 team, s32 player) {
    SPPlane* s = D_8010ADA4_1B4434_SkyPilots[team]->unk_50;
    MgWork* w;
    omObjData** sub;
    s32 i;
    s32 icon;

    for (i = 0; i < obj->mdlcnt; i++) {
        obj->model[i] = 0;
    }
    obj->unk_50 = func_80027154_27D54(sizeof(MgWork), 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, sizeof(MgWork));
    w = obj->unk_50;
    w->unk_E8 = func_80027154_27D54(obj->mtncnt * 12, 0x7918);
    D_80101300_101F00 = 0.8f;
    D_8010105C_101C5C = 0.8f;
    obj->model[0] = LoadFormFile(dir | file, 0x20A99);
    for (i = 0; i < obj->mtncnt; i++) {
        obj->motion[i] = -1;
    }
    for (i = 0; i < obj->mtncnt; i++) {
        ((MgMotion*)w->unk_E8)[i].unk_00 = 0;
        ((MgMotion*)w->unk_E8)[i].unk_02 = 0;
        ((MgMotion*)w->unk_E8)[i].unk_04 = -1;
        ((MgMotion*)w->unk_E8)[i].unk_08 = -1;
    }
    obj->func_ptr = func_80103A6C_1AD0FC_SkyPilots;
    w->unk_57 = gPlayers[player].port;
    w->unk_59 = player;
    w->unk_52 = 0;
    w->unk_B4 = 1.0f;
    w->unk_D0 = 0xFFFF;
    w->unk_60 = 0.0f;
    func_8000BE74_CA74(obj, 1000.0f);
    w->unk_9C = w->unk_A0 = w->unk_A4 = 0.0f;
    w->unk_C4 = -1;
    func_80019B9C_1A79C(obj, 0);
    s->gunnerObj = obj;
    s->gunner = player;
    sub = &D_8010ADA4_1B4434_SkyPilots[team];
    obj->trans.x = (*sub)->trans.x;
    obj->trans.y = (*sub)->trans.y;
    obj->trans.z = (*sub)->trans.z;
    obj->rot.x = (*sub)->rot.x;
    obj->rot.y = (*sub)->rot.y;
    obj->rot.z = (*sub)->rot.z;
    switch (gPlayers[player].character) {
    case 0:
        icon = 0xD;
        break;
    case 1:
        icon = 0xE;
        break;
    case 2:
        icon = 0xF;
        break;
    case 3:
        icon = 0x10;
        break;
    case 4:
        icon = 0x11;
        break;
    case 5:
        icon = 0x12;
        break;
    }
    s->icon[1] = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(icon | 0x290000), 0, 1);
    func_8001A788_1B388(s->icon[1], 9 - team * 2);
    D_80101300_101F00 = 1.0f;
    D_8010105C_101C5C = 1.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_SkyPilots/1ABE90", func_801073A8_1B0A38_SkyPilots);
#endif

/* NON_MATCHING: register allocation */
#ifdef NON_MATCHING
void func_801076E8_1B0D78_SkyPilots(omObjData* obj) {
    s32 team;
    s32 i;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 f;
    s32 tile;
    s32 base;

    for (team = 0; team < 2; team++) {
        a = 0;
        b = 0;
        c = 0;
        d = 0;
        e = 0;
        f = 0;
        tile = D_8010B430_1B4AC0_SkyPilots[team] / 7.0f;
        for (i = 0; i < 6; i++) {
            func_800298A4_2A4A4(D_8010B356_1B49E6_SkyPilots[team][i], 4, 4);
            func_800298A4_2A4A4(D_8010B362_1B49F2_SkyPilots[team][i], 4, 4);
        }
        for (i = 0; i < 3; i++) {
            func_800298A4_2A4A4(D_8010B36E_1B49FE_SkyPilots[team][i], 4, 4);
            func_800298A4_2A4A4(D_8010B374_1B4A04_SkyPilots[team][i], 4, 4);
        }
        for (i = 0; i < 2; i++) {
            func_800298A4_2A4A4(D_8010B37A_1B4A0A_SkyPilots[team][i], 4, 4);
            func_800298A4_2A4A4(D_8010B37E_1B4A0E_SkyPilots[team][i], 4, 4);
        }
        base = tile;
        if (tile >= 0x3C) {
            base = tile - 0x3C;
        }
        for (i = 0; i < 6; i++) {
            s32 t = base + i;

            if (t >= 0 && D_8010AF58_1B45E8_SkyPilots[t] != 0) {
                f32 sx = HuMathSin(D_8010AFD0_1B4660_SkyPilots[t] + D_8010B1B0_1B4840_SkyPilots) * 0.1f + 1.0f;
                f32 sy = HuMathSin(D_8010AFD0_1B4660_SkyPilots[t] + D_8010B1B0_1B4840_SkyPilots + 45.0f) * 0.2f + 1.0f;
                f32 ang = tile * 7 + i * 7;
                f32 x = HuMathSin(ang) * 11232.405f;
                f32 z = func_800B7890_B8490(ang) * 11232.405f;
                f32 y = func_800B7890_B8490(D_8010AFD0_1B4660_SkyPilots[t] + D_8010B1B0_1B4840_SkyPilots) * 60.0f;
                s16 mdl = D_8010B356_1B49E6_SkyPilots[team][a];

                func_800298A4_2A4A4(mdl, 4, 0);
                a++;
                func_800297E8_2A3E8(mdl, sx, sy, 1.0f);
                func_8002979C_2A39C(mdl, 0.0f, D_80102770_103370[team].y, 0.0f);
                func_80029714_2A314(mdl, x, y, z);
                if (D_8010AF58_1B45E8_SkyPilots[t] == 2) {
                    mdl = D_8010B36E_1B49FE_SkyPilots[team][b];
                    func_800298A4_2A4A4(mdl, 4, 0);
                    func_8002979C_2A39C(mdl, 0.0f, (tile * 7 + i * 7) - 90.0f, 0.0f);
                    b++;
                    func_80029714_2A314(mdl, x, y, z);
                } else if (D_8010AF58_1B45E8_SkyPilots[t] == 3) {
                    mdl = D_8010B37A_1B4A0A_SkyPilots[team][c];
                    func_800298A4_2A4A4(mdl, 4, 0);
                    func_8002979C_2A39C(mdl, 0.0f, (tile * 7 + i * 7) - 90.0f, 0.0f);
                    c++;
                    func_80029714_2A314(mdl, x, y, z);
                }
            }
        }
        for (i = 0; i < 6; i++) {
            s32 t = base + i;

            if (t >= 0 && D_8010AF94_1B4624_SkyPilots[t] != 0) {
                f32 sx = HuMathSin(D_8010B0C0_1B4750_SkyPilots[t] + D_8010B1B0_1B4840_SkyPilots) * 0.1f + 1.0f;
                f32 sy = func_800B7890_B8490(D_8010B0C0_1B4750_SkyPilots[t] + D_8010B1B0_1B4840_SkyPilots + 45.0f) * 0.2f + 1.0f;
                f32 ang = tile * 7 + i * 7;
                f32 x = HuMathSin(ang) * 14232.405f;
                f32 z = func_800B7890_B8490(ang) * 14232.405f;
                f32 y = HuMathSin(D_8010B0C0_1B4750_SkyPilots[t] + D_8010B1B0_1B4840_SkyPilots) * 60.0f;
                s16 mdl = D_8010B362_1B49F2_SkyPilots[team][d];

                func_800298A4_2A4A4(mdl, 4, 0);
                func_800297E8_2A3E8(mdl, sx, sy, 1.0f);
                func_8002979C_2A39C(mdl, 0.0f, D_80102770_103370[team].y, 0.0f);
                d++;
                func_80029714_2A314(mdl, x, y, z);
                if (D_8010AF94_1B4624_SkyPilots[t] == 2) {
                    mdl = D_8010B374_1B4A04_SkyPilots[team][e];
                    func_800298A4_2A4A4(mdl, 4, 0);
                    func_8002979C_2A39C(mdl, 0.0f, (tile * 7 + i * 7) - 90.0f, 0.0f);
                    e++;
                    func_80029714_2A314(mdl, x, y, z);
                } else if (D_8010AF94_1B4624_SkyPilots[t] == 3) {
                    mdl = D_8010B37E_1B4A0E_SkyPilots[team][f];
                    func_800298A4_2A4A4(mdl, 4, 0);
                    func_8002979C_2A39C(mdl, 0.0f, (tile * 7 + i * 7) - 90.0f, 0.0f);
                    f++;
                    func_80029714_2A314(mdl, x, y, z);
                }
            }
        }
    }
    D_8010B1B0_1B4840_SkyPilots = func_8002D958_2E558(D_8010B1B0_1B4840_SkyPilots + 5.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_SkyPilots/1ABE90", func_801076E8_1B0D78_SkyPilots);
#endif

/* NON_MATCHING: register allocation */
#ifdef NON_MATCHING
void func_80107EAC_1B153C_SkyPilots(omObjData* obj) {
    omObjData* self = obj;
    s32 m1 = -1;
    s32 m4 = -1;
    s32 m2 = -1;
    s32 m5 = -1;
    s32 m3 = -1;
    s32 team;
    s32 i;
    s32 x;
    s16 spr;
    s16 tmp;
    u16 id;

    D_8010B354_1B49E4_SkyPilots[0] = func_80018A30_19630(0x2C0014, 0x20239);
    D_8010B354_1B49E4_SkyPilots[1] = func_80027D3C_2893C(D_8010B354_1B49E4_SkyPilots[0]);
    func_80029EDC_2AADC(D_8010B354_1B49E4_SkyPilots[0], 1);
    func_80029EDC_2AADC(D_8010B354_1B49E4_SkyPilots[1], 2);
    for (team = 0; team < 2; team++) {
        for (i = 0; i < 6; i++) {
            if (m1 == -1) {
                m1 = func_80018A30_19630(0x2C000D, 0x8D9);
                D_8010B356_1B49E6_SkyPilots[team][0] = m1;
            } else {
                D_8010B356_1B49E6_SkyPilots[team][i] = func_80027D3C_2893C(m1);
            }
            func_80029EDC_2AADC(D_8010B356_1B49E6_SkyPilots[team][i], 1 << team);
        }
        for (i = 0; i < 3; i++) {
            if (m2 == -1) {
                m2 = func_80018A30_19630(0x2C000F, 0x8D9);
                D_8010B36E_1B49FE_SkyPilots[team][0] = m2;
            } else {
                D_8010B36E_1B49FE_SkyPilots[team][i] = func_80027D3C_2893C(m2);
            }
            func_80029EDC_2AADC(D_8010B36E_1B49FE_SkyPilots[team][i], 1 << team);
        }
        for (i = 0; i < 2; i++) {
            if (m3 == -1) {
                m3 = func_80018A30_19630(0x2C0011, 0x8D9);
                D_8010B37A_1B4A0A_SkyPilots[team][0] = m3;
            } else {
                D_8010B37A_1B4A0A_SkyPilots[team][i] = func_80027D3C_2893C(m3);
            }
            func_80029EDC_2AADC(D_8010B37A_1B4A0A_SkyPilots[team][i], 1 << team);
        }
        for (i = 0; i < 6; i++) {
            D_8010B362_1B49F2_SkyPilots[team][i] = func_80027D3C_2893C(m1);
            func_80029EDC_2AADC(D_8010B362_1B49F2_SkyPilots[team][i], 1 << team);
        }
        for (i = 0; i < 3; i++) {
            if (m4 == -1) {
                m4 = func_80018A30_19630(0x2C000E, 0x8D9);
                D_8010B374_1B4A04_SkyPilots[team][0] = m4;
            } else {
                D_8010B374_1B4A04_SkyPilots[team][i] = func_80027D3C_2893C(m4);
            }
            func_80029EDC_2AADC(D_8010B374_1B4A04_SkyPilots[team][i], 1 << team);
        }
        for (i = 0; i < 2; i++) {
            if (m5 == -1) {
                m5 = func_80018A30_19630(0x2C0010, 0x8D9);
                D_8010B37E_1B4A0E_SkyPilots[team][0] = m5;
            } else {
                D_8010B37E_1B4A0E_SkyPilots[team][i] = func_80027D3C_2893C(m5);
            }
            func_80029EDC_2AADC(D_8010B37E_1B4A0E_SkyPilots[team][i], 1 << team);
        }
    }
    spr = func_8001A2F8_1AEF8(0x2C0024);
    for (x = 8; x < 0x140; x += 0x20) {
        id = func_8001AAAC_1B6AC(spr, 0, 1);
        espPosSet(id, x, 0x78);
        func_8001A788_1B388(id, 0x10);
    }
    id = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x2C0025), 0, 1);
    espPosSet(id, 0x120, 0x71);
    func_8001A788_1B388(id, 5);
    D_8010B2CC_1B495C_SkyPilots[0] = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x2C0026), 0, 1);
    func_8001A91C_1B51C(D_8010B2CC_1B495C_SkyPilots[0], 1.0f, 1.0f);
    func_8001A788_1B388(D_8010B2CC_1B495C_SkyPilots[0], 8);
    D_8010B2CC_1B495C_SkyPilots[1] = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x2C0027), 0, 1);
    func_8001A91C_1B51C(D_8010B2CC_1B495C_SkyPilots[1], 1.0f, 1.0f);
    func_8001A788_1B388(D_8010B2CC_1B495C_SkyPilots[1], 6);
    espPosSet(D_8010B2CC_1B495C_SkyPilots[0], 0x12, 0x70);
    espPosSet(D_8010B2CC_1B495C_SkyPilots[1], 0x12, 0x74);
    self->func_ptr = func_80102EF0_1AC580_SkyPilots;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_SkyPilots/1ABE90", func_80107EAC_1B153C_SkyPilots);
#endif

void func_801083CC_1B1A5C_SkyPilots(omObjData* obj) {
    s32 i;

    for (i = 0; i < 2; i++) {
        f32 a = D_8010ADDC_1B446C_SkyPilots[i].angle;
        s32 mask = 0;
        s32 k;

        for (k = 0; k < 2; k++) {
            f32 h = D_8010B430_1B4AC0_SkyPilots[k];
            f32 lo = h - 5.0f;
            f32 hi = h + 25.0f;

            if ((lo < a) & (a < hi)) {
                mask |= 1 << k;
            }
        }
        func_80029EDC_2AADC(obj->model[i], mask);
    }
}

/* NON_MATCHING: register allocation */
#ifdef NON_MATCHING
void func_801084E4_1B1B74_SkyPilots(s32 i) {
    f32 best = 65535.0f;
    f32 px = HuMathSin(D_8010AE3C_1B44CC_SkyPilots[i].angle) * (D_8010AE3C_1B44CC_SkyPilots[i].radius + SP_RADIUS);
    f32 pz = func_800B7890_B8490(D_8010AE3C_1B44CC_SkyPilots[i].angle) * (D_8010AE3C_1B44CC_SkyPilots[i].radius + SP_RADIUS);
    f32 py = 0.0f;
    f32 tx = px;
    f32 ty = py;
    f32 tz = pz;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 d;
    f32 ang;
    s32 k;
    s32 near = 0;
    s32* mdl;

    for (k = 0; k < 2; k++) {
        omObjData* p = D_8010ADA4_1B4434_SkyPilots[k];
        dx = p->trans.x;
        dy = p->trans.y;
        dz = p->trans.z;
        dx -= px;
        dy -= py;
        dz -= pz;
        d = func_800B1830_B2430(dx * dx + dy * dy + dz * dz);

        if (d < best) {
            best = d;
            near = k;
            tx = dx;
            ty = dy;
            tz = dz;
        }
    }
    dy = ty / 25.0f;
    if (dy < 0.0f) {
        dy = 0.0f;
    }
    if (dy > 20.0f) {
        dy = 20.0f;
    }
    mdl = &D_8010B2E8_1B4978_SkyPilots[i];
    func_80029C74_2A874((s16)*mdl, dy);
    ang = func_800B75A8_B81A8(tx, tz);
    func_8002979C_2A39C((s16)*mdl, 0.0f, ang, 0.0f);
    if (D_8010AEA8_1B4538_SkyPilots[i] == 0 && D_8010ADCC_1B445C_SkyPilots[near][i] < 2 && D_800F8FD0_F9BD0 == 1 && best < 4000.0f
        && D_8010B430_1B4AC0_SkyPilots[near] < D_8010AE3C_1B44CC_SkyPilots[i].angle) {
        SPPlane* w = D_8010ADA4_1B4434_SkyPilots[near]->unk_50;
        Vec v;

        v.x = tx + HuMathSin(w->yaw) * w->speed * 30.0f;
        v.y = ty;
        v.z = tz + func_800B7890_B8490(w->yaw) * w->speed * 30.0f;
        func_8002D9AC_2E5AC((Vec3f*)&v);
        D_8010AEA8_1B4538_SkyPilots[i] = 1;
        D_8010AEAC_1B453C_SkyPilots[i].x = v.x;
        D_8010AEAC_1B453C_SkyPilots[i].y = v.y;
        D_8010AEAC_1B453C_SkyPilots[i].z = v.z;
        D_8010AEDC_1B456C_SkyPilots[i].x = px + HuMathSin(ang) * 150.0f;
        D_8010AEDC_1B456C_SkyPilots[i].y = py + 77.5;
        D_8010AEDC_1B456C_SkyPilots[i].z = pz + func_800B7890_B8490(ang) * 150.0f;
        PlaySound(0x212);
        func_800298A4_2A4A4((s16)D_8010B2F8_1B4988_SkyPilots[i], 4, 0);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_SkyPilots/1ABE90", func_801084E4_1B1B74_SkyPilots);
#endif

void func_8010890C_1B1F9C_SkyPilots(s32 i) {
    func_800298A4_2A4A4((s16)D_8010B2F8_1B4988_SkyPilots[i], 4, 4);
    func_800298A4_2A4A4((s16)D_8010B308_1B4998_SkyPilots[i], 4, 0);
    func_80029C74_2A874((s16)D_8010B308_1B4998_SkyPilots[i], 0.0f);
    D_800FC834_FD434[D_8010B308_1B4998_SkyPilots[i]].hmf->unk9C->unk08 = 0.0f;
    func_80029714_2A314((s16)D_8010B308_1B4998_SkyPilots[i], D_8010AEDC_1B456C_SkyPilots[i].x, D_8010AEDC_1B456C_SkyPilots[i].y, D_8010AEDC_1B456C_SkyPilots[i].z);
    D_8010AEA8_1B4538_SkyPilots[i] = -0x5A - i * 5;
    PlaySound(0x215);
}

void func_80108A00_1B2090_SkyPilots(s32 i) {
    func_800298A4_2A4A4((s16)D_8010B318_1B49A8_SkyPilots[i], 4, 4);
    func_800298A4_2A4A4((s16)D_8010B330_1B49C0_SkyPilots[i], 4, 0);
    func_80029C74_2A874((s16)D_8010B330_1B49C0_SkyPilots[i], 0.0f);
    D_800FC834_FD434[D_8010B330_1B49C0_SkyPilots[i]].hmf->unk9C->unk08 = 0.0f;
    PlaySound(0x215);
}
