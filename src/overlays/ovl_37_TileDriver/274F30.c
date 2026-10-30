#include "ovl_37.h"

/* .data (0x27A070-0x27A2E0, 80107940-80107BB0); 279FC0.c has none. */

f32 D_80107940_27A070_TileDriver[6][4] = {
    { 0.0f, 0.0f, 160.0f, 120.0f },
    { 160.0f, 0.0f, 320.0f, 120.0f },
    { 0.0f, 120.0f, 160.0f, 240.0f },
    { 160.0f, 120.0f, 320.0f, 240.0f },
    { 0.0f, 0.0f, 320.0f, 240.0f },
    { 0.0f, 0.0f, 320.0f, 240.0f },
};
f32 D_801079A0_27A0D0_TileDriver[6][6] = {
    { 320.0f, 240.0f, 511.5f, 320.0f, 240.0f, 511.5f },
    { 320.0f, 240.0f, 511.5f, 960.0f, 240.0f, 511.5f },
    { 320.0f, 240.0f, 511.5f, 320.0f, 720.0f, 511.5f },
    { 320.0f, 240.0f, 511.5f, 960.0f, 720.0f, 511.5f },
    { 640.0f, 480.0f, 511.5f, 640.0f, 480.0f, 511.5f },
    { 640.0f, 480.0f, 511.5f, 640.0f, 480.0f, 511.5f },
};
Vec D_80107A30_27A160_TileDriver[9] = {
    { -225.0f, -52.2f, -225.0f },
    { 0.0f, -52.2f, -225.0f },
    { 225.0f, -52.2f, -225.0f },
    { -225.0f, -51.0000038f, 0.0f },
    { 0.0f, -51.0000038f, 0.0f },
    { 225.0f, -51.0000038f, 0.0f },
    { -225.0f, -49.8000031f, 225.0f },
    { 0.0f, -49.8000031f, 225.0f },
    { 225.0f, -49.8000031f, 225.0f },
};
Vec D_80107A9C_27A1CC_TileDriver[9] = {
    { -225.0f, 0.0f, -225.0f },
    { 0.0f, 0.0f, -225.0f },
    { 225.0f, 0.0f, -225.0f },
    { -225.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f },
    { 225.0f, 0.0f, 0.0f },
    { -225.0f, 0.0f, 225.0f },
    { 0.0f, 0.0f, 225.0f },
    { 225.0f, 0.0f, 225.0f },
};
Vec D_80107B08_27A238_TileDriver[9] = {
    { -135.0f, -52.2f, -135.0f },
    { 0.0f, -52.2f, -135.0f },
    { 135.0f, -52.2f, -135.0f },
    { -135.0f, -51.0000038f, 0.0f },
    { 0.0f, -51.0000038f, 0.0f },
    { 135.0f, -51.0000038f, 0.0f },
    { -135.0f, -49.8000031f, 135.0f },
    { 0.0f, -49.8000031f, 135.0f },
    { 135.0f, -49.8000031f, 135.0f },
};
u16 D_80107B74_27A2A4_TileDriver[9] = { 4, 5, 6, 7, 8, 9, 10, 11, 12 };
u32 D_80107B88_27A2B8_TileDriver[6] = { 0x20000, 0x30000, 0x70000, 0x40000, 0x50000, 0x60000 };
u16 D_80107BA0_27A2D0_TileDriver[4] = { 0x4E, 0x4F, 0x55, 0x56 };
u8 D_80107BA8_27A2D8_TileDriver = 0;

void func_80102800_274F30_TileDriver(void) {
    func_80107168_279898_TileDriver();
}

void func_8010281C_274F4C_TileDriver(void) {
    s16 i;
    f32 f;
    f32 dx;
    f32 dz;
    f32 a;
    f32 b;
    f32 c;
    s32 n;
    TDObj* o;

    switch (D_80107C0C_27A33C_TileDriver) {
    case 0:
        for (i = 0; i < 4; i++) {
            D_800F94A8_FA0A8[i] = 1500.0f;
            D_80102770_103370[i].x = 315.0f;
            D_80102770_103370[i].y = 0.0f;
            D_80102770_103370[i].z = 0.0f;
            D_801013B0_101FB0[i].x = 0.0f;
            D_801013B0_101FB0[i].y = 0.0f;
            D_801013B0_101FB0[i].z = 50.0f;
        }
        if (D_80107C08_27A338_TileDriver >= 60) {
            D_800F94A8_FA0A8[4] = 1500.0f;
            D_80102770_103370[4].x = 315.0f;
            D_80102770_103370[4].y = 0.0f;
            D_80102770_103370[4].z = 0.0f;
        } else if (D_80107C08_27A338_TileDriver >= 30 && D_80107C08_27A338_TileDriver < 60) {
            b = 1.5f;
            D_800F94A8_FA0A8[4] = 1500.0f;
            D_80102770_103370[4].x = (f32)(D_80107C08_27A338_TileDriver - 30) * b + 270.0f;
            D_80102770_103370[4].y = 0.0f;
            D_80102770_103370[4].z = 0.0f;
        } else {
            D_800F94A8_FA0A8[4] = 1500.0f;
            D_80102770_103370[4].x = 270.0f;
            D_80102770_103370[4].y = 0.0f;
            D_80102770_103370[4].z = 0.0f;
        }
        break;
    case 3:
        if (_CheckFlag(0xC) != 0) {
            for (i = 0; i < 4; i++) {
                D_800F94A8_FA0A8[i] = 1500.0f;
                D_80102770_103370[i].x = 315.0f;
                D_80102770_103370[i].y = 0.0f;
                D_80102770_103370[i].z = 0.0f;
                D_801013B0_101FB0[i].x = 0.0f;
                D_801013B0_101FB0[i].y = 0.0f;
                D_801013B0_101FB0[i].z = 50.0f;
            }
        } else {
            a = 20.0f;
            b = 1.0f;
            c = 3.0f;
            if (D_80107C0A_27A33A_TileDriver > 0) {
            for (i = 0; i < 4; i++) {
                o = D_80107CF0_27A420_TileDriver + i;
                if (o->obj != NULL) {
                    dx = o->obj->trans.x / 30.0f;
                    dz = (o->obj->trans.z - 50.0f) / 30.0f;
                    D_800F94A8_FA0A8[i] = 1500.0f - a * (n = 30 - D_80107C0A_27A33A_TileDriver);
                    D_80102770_103370[i].x = b * n + 315.0f;
                    D_80102770_103370[i].y = 0.0f;
                    D_80102770_103370[i].z = 0.0f;
                    D_801013B0_101FB0[i].x = dx * n + 0.0f;
                    D_801013B0_101FB0[i].y = c * n + 0.0f;
                    D_801013B0_101FB0[i].z = dz * n + 50.0f;
                }
            }
            } else {
            for (i = 0; i < 4; i++) {
                o = D_80107CF0_27A420_TileDriver + i;
                if (o->obj != NULL) {
                    D_800F94A8_FA0A8[i] = 900.0f;
                    D_80102770_103370[i].x = 345.0f;
                    D_80102770_103370[i].y = 0.0f;
                    D_80102770_103370[i].z = 0.0f;
                    D_801013B0_101FB0[i].x = o->obj->trans.x;
                    D_801013B0_101FB0[i].y = 90.0f;
                    D_801013B0_101FB0[i].z = o->obj->trans.z;
                }
            }
            }
        }
        D_800F94A8_FA0A8[4] = 1500.0f;
        D_80102770_103370[4].x = 270.0f;
        D_80102770_103370[4].y = 0.0f;
        D_80102770_103370[4].z = 0.0f;
        break;
    case 4:
    case 5:
        if (_CheckFlag(0xC) != 0) {
            for (i = 0; i < 4; i++) {
                D_800F94A8_FA0A8[i] = 1500.0f;
                D_80102770_103370[i].x = 315.0f;
                D_80102770_103370[i].y = 0.0f;
                D_80102770_103370[i].z = 0.0f;
                D_801013B0_101FB0[i].x = 0.0f;
                D_801013B0_101FB0[i].y = 0.0f;
                D_801013B0_101FB0[i].z = 50.0f;
            }
        } else {
            for (i = 0; i < 4; i++) {
                o = D_80107CF0_27A420_TileDriver + i;
                if (o->obj != NULL) {
                    D_800F94A8_FA0A8[i] = 900.0f;
                    D_80102770_103370[i].x = 345.0f;
                    D_80102770_103370[i].y = 0.0f;
                    D_80102770_103370[i].z = 0.0f;
                    D_801013B0_101FB0[i].x = o->obj->trans.x;
                    D_801013B0_101FB0[i].y = 90.0f;
                    D_801013B0_101FB0[i].z = o->obj->trans.z;
                }
            }
        }
        D_800F94A8_FA0A8[4] = 1500.0f;
        D_80102770_103370[4].x = 270.0f;
        D_80102770_103370[4].y = 0.0f;
        D_80102770_103370[4].z = 0.0f;
        break;
    default:
        for (i = 0; i < 4; i++) {
            D_800F94A8_FA0A8[i] = 1500.0f;
            D_80102770_103370[i].x = 315.0f;
            D_80102770_103370[i].y = 0.0f;
            D_80102770_103370[i].z = 0.0f;
            D_801013B0_101FB0[i].x = 0.0f;
            D_801013B0_101FB0[i].y = 0.0f;
            D_801013B0_101FB0[i].z = 50.0f;
        }
        D_800F94A8_FA0A8[4] = 1500.0f;
        D_80102770_103370[4].x = 270.0f;
        D_80102770_103370[4].y = 0.0f;
        D_80102770_103370[4].z = 0.0f;
        break;
    }
    D_801013B0_101FB0[4].x = 0.0f;
    D_801013B0_101FB0[4].y = 0.0f;
    D_801013B0_101FB0[4].z = 0.0f;
}

void func_80102F84_2756B4_TileDriver(omObjData* obj) {
    SprPosSet(D_80107E14_27A544_TileDriver, 0, 160, 120);
}

void func_80102FB0_2756E0_TileDriver(omObjData* obj) {
    GroundWork* gw;
    f32 f;

    D_80107C80_27A3B0_TileDriver[0] = func_8001A2F8_1AEF8(0x470000);
    D_80107E14_27A544_TileDriver = SprCreate(1, 0);
    SprAttrReset(D_80107E14_27A544_TileDriver, 0, -1);
    SprScaleSet(D_80107E14_27A544_TileDriver, 0, 1.0f, 1.0f);
    SprAnimSet(D_80107E14_27A544_TileDriver, 0, D_80107C80_27A3B0_TileDriver[0], 0);
    SprBankSet(D_80107E14_27A544_TileDriver, 0, 0);
    SprAttrSet(D_80107E14_27A544_TileDriver, 0, 0x5000);
    SprPosSet(D_80107E14_27A544_TileDriver, 0, 160, 120);
    func_8008225C_82E5C(D_80107E14_27A544_TileDriver, 0, 0);
    SprPrioSet(D_80107E14_27A544_TileDriver, 0, 0xFFF0);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = obj;
    obj->unk_50 = gw = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(gw, 0, 0xB4);
    gw->unk_03 = 1;
    gw->unk_04 = 0;
    func_8000BEA4_CAA4(obj, 20.0f);
    func_8000BE8C_CA8C(obj, 0.5f);
    func_8000BE98_CA98(obj, D_800BF79C_C039C);
    f = 210.00002f;
    func_8000BF24_CB24(D_800FC7B0_FD3B0[0], 0.0f, -f, -f, f, f);
    obj->func_ptr = func_80102F84_2756B4_TileDriver;
}

void func_8010316C_27589C_TileDriver(void) {
    omSetStatBit(D_80107CF0_27A420_TileDriver[4].obj = omAddObj(10, 0, 0, -1, func_80102FB0_2756E0_TileDriver), 0xA0);
}

void func_801031B4_2758E4_TileDriver(omObjData* obj) {
    if (D_80107C0C_27A33C_TileDriver == 1) {
        obj->trans.y = 400.0f;
        obj->scale.x = obj->scale.y = 0.6f;
        func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
        func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    }
}

void func_8010323C_27596C_TileDriver(omObjData* obj) {
    obj->model[0] = func_80018A30_19630(0x470001, 0x2699);
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80029EDC_2AADC(obj->model[0], 0x10);
    obj->func_ptr = func_801031B4_2758E4_TileDriver;
}

void func_801032BC_2759EC_TileDriver(void) {
    omObjData* o = omAddObj(400, 1, 0, -1, func_8010323C_27596C_TileDriver);

    o->work[0] = 20;
    D_80107CF0_27A420_TileDriver[20].obj = o;
}

void func_80103300_275A30_TileDriver(omObjData* obj) {
    switch (D_80107C0C_27A33C_TileDriver) {
    case 0:
        if (D_80107C08_27A338_TileDriver < 45) {
            D_80107C0E_27A33E_TileDriver -= 5;
        }
        if (D_80107C0E_27A33E_TileDriver > 0) {
            func_8002D0A0_2DCA0(obj->model[0], (u8)D_80107C0E_27A33E_TileDriver);
            break;
        }
    case 1:
        func_800298A4_2A4A4(obj->model[0], 4, 4);
        break;
    }
}

void func_8010339C_275ACC_TileDriver(omObjData* obj) {
    obj->model[0] = func_80018A30_19630(0x470002, 0x26A9);
    func_8002D124_2DD24(obj->model[0]);
    obj->trans.x = obj->trans.z = 0.0f;
    D_80107C0E_27A33E_TileDriver = 150;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_8002D0A0_2DCA0(obj->model[0], (u8)D_80107C0E_27A33E_TileDriver);
    func_80029EDC_2AADC(obj->model[0], 0x10);
    obj->func_ptr = func_80103300_275A30_TileDriver;
}

void func_80103444_275B74_TileDriver(void) {
    omObjData* o = omAddObj(400, 1, 0, -1, func_8010339C_275ACC_TileDriver);

    o->work[0] = 20;
    D_80107CF0_27A420_TileDriver[20].obj = o;
}

void func_80103488_275BB8_TileDriver(u8 player) {
    ContBtn[gPlayers[player].port] = 0;
    ContBtnTrg[gPlayers[player].port] = 0;
    ContStkX[gPlayers[player].port] = 0;
    ContStkY[gPlayers[player].port] = 0;
}

void func_8010350C_275C3C_TileDriver(omObjData* obj) {
    TDObj* o = &D_80107CF0_27A420_TileDriver[obj->work[0]];
    MgWork* w = obj->unk_50;
    f32 half = 67.5f;
    Vec from;
    Vec to;
    Vec dir;
    s16 n;
    u8 k;
    s16 i;

    if (w->unk_38 == 1000.0f) {
        for (i = 0; i < 9; i++) {
            if (D_80107B08_27A238_TileDriver[i].x - half < obj->trans.x && obj->trans.x <= half + D_80107B08_27A238_TileDriver[i].x
                && D_80107B08_27A238_TileDriver[i].z - half < obj->trans.z && obj->trans.z <= half + D_80107B08_27A238_TileDriver[i].z) {
                break;
            }
        }
        if (i < 9) {
            if (D_80107C10_27A340_TileDriver[obj->work[0]][i] != D_80107C10_27A340_TileDriver[4][4]) {
                if ((u8)(rand8() % 20) < o->chance) {
                    goto jump;
                }
            } else {
                if ((((rand8() & 0xFF) << 8) | rand8()) % 500 < o->miss) {
                jump:
                    ContBtnTrg[w->unk_57] |= 0x8000;
                    o->stickX = 0;
                    o->stickY = 0;
                    o->walking = 0;
                    return;
                }
                if (o->walking == 1) {
                    ContStkX[w->unk_57] = (s8)o->stickX;
                    ContStkY[w->unk_57] = (s8)o->stickY;
                    return;
                }
                k = rand8() % 9;
                for (i = 0, n = k; i < 9; i++) {
                    n = n < 9 ? n : 0;
                    if (D_80107C10_27A340_TileDriver[obj->work[0]][n] != D_80107C10_27A340_TileDriver[4][4]) {
                        from.x = obj->trans.x;
                        from.y = 0.0f;
                        from.z = obj->trans.z;
                        to.x = D_80107B08_27A238_TileDriver[n].x;
                        to.y = 0.0f;
                        to.z = D_80107B08_27A238_TileDriver[n].z;
                        func_8010750C_279C3C_TileDriver(&from, &to, &dir);
                        o->stickX = HuMathSin(dir.z) * o->speed;
                        o->stickY = func_800B7890_B8490(dir.z) * -o->speed;
                        o->walking = 1;
                        return;
                    }
                    n++;
                }
            }
        }
    } else if (obj->trans.y > o->unk_38) {
        if ((u8)(rand8() % 10) < o->jump) {
            ContBtnTrg[w->unk_57] |= 0x2000;
        }
    } else {
        ContBtn[w->unk_57] |= 0x8000;
    }
}

/* NON_MATCHING: retail keeps the board index in $s3 and loads it apart from the slot index (register allocation, masked 44). */
#ifdef NON_MATCHING
void func_80103988_2760B8_TileDriver(omObjData* obj) {
    TDObj* o = &D_80107CF0_27A420_TileDriver[obj->work[0]];
    MgWork* w = obj->unk_50;
    f32 half = 67.5f;
    s16 board = obj->work[0] + 10;
    s16 i;
    TDObj* r;

    switch (D_80107C0C_27A33C_TileDriver) {
    case 0:
    case 1:
    case 5:
        func_80103488_275BB8_TileDriver(obj->work[0]);
        break;
    case 2:
        if (gPlayers[obj->work[0]].flags & 1) {
            func_80103488_275BB8_TileDriver(obj->work[0]);
            func_8010350C_275C3C_TileDriver(obj);
        }
        if (w->unk_5C & 0x200) {
            if (func_800B1830_B2430(obj->trans.x * obj->trans.x) < 185.0f
                && func_800B1830_B2430(obj->trans.z * obj->trans.z) < 185.0f) {
                D_800BF7A4_C03A4 = 2.5f;
                if ((w->unk_50 & 0x80) && o->punched == 0) {
                    if (!(gPlayers[obj->work[0]].flags & 1)) {
                        omVibrate(obj->work[0], 10, 0, 10);
                    }
                    for (i = 0; i < 9; i++) {
                        if (D_80107B08_27A238_TileDriver[i].x - half < obj->trans.x && obj->trans.x <= half + D_80107B08_27A238_TileDriver[i].x
                            && D_80107B08_27A238_TileDriver[i].z - half < obj->trans.z && obj->trans.z <= half + D_80107B08_27A238_TileDriver[i].z) {
                            D_80107C58_27A388_TileDriver[obj->work[0]][i] = 1;
                            o->punched = 1;
                            r = D_80107CF0_27A420_TileDriver + (u8)board;
                            if (r->obj != NULL) {
                                r->unk_38 = 360.0f;
                                r->unk_40 = (f32)D_80107C10_27A340_TileDriver[obj->work[0]][i] * 120.0f;
                                break;
                            }
                        }
                    }
                }
            }
        }
        break;
    case 3:
        func_80103488_275BB8_TileDriver(obj->work[0]);
        if ((w->unk_5C & 2) && w->unk_3C != 0.0f) {
            if (w->unk_3C < 0.0f) {
                if ((w->unk_3C += 30.0f) >= 0.0f) {
                    w->unk_3C = 0.0f;
                }
            } else {
                if ((w->unk_3C -= 30.0f) <= 0.0f) {
                    w->unk_3C = 0.0f;
                }
            }
        }
        break;
    case 4:
        func_80103488_275BB8_TileDriver(obj->work[0]);
        if (_CheckFlag(0xC) == 0 && o->posed == 0) {
            if (D_80107C46_27A376_TileDriver == 1 && obj->work[0] == D_80107C7C_27A3AC_TileDriver) {
                func_80019B9C_1A79C(obj, 0xD);
                func_800732B0_73EB0(D_80107BA0_27A2D0_TileDriver[D_80107C00_27A330_TileDriver[obj->work[0]][0]] | D_80107B88_27A2B8_TileDriver[gPlayers[obj->work[0]].character]);
            } else {
                func_80019B9C_1A79C(obj, 0xE);
            }
            o->posed = 1;
        }
        break;
    }
    func_80007790_8390(obj);
    D_800BF7A4_C03A4 = 1.3f;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_37_TileDriver/274F30", func_80103988_2760B8_TileDriver);
#endif

void func_80103E24_276554_TileDriver(omObjData* obj) {
    TDObj* o = &D_80107CF0_27A420_TileDriver[obj->work[0]];
    s32 attr = 0x226B9;
    s32 attr2 = 0x20A9;
    u8 chr = gPlayers[obj->work[0]].character;
    s32 dir = D_800CD438_CE038[chr].unk_04;
    s32 mdl = D_800CD438_CE038[chr].unk_10;
    MgWork* w;
    s16 mask;

    func_8000C460_D060();
    func_8000C6FC_D2FC(obj, dir, mdl, obj->work[0], attr, attr2);
    HmfModelObjAttrSet(obj->model[1], 0x80000000, 0);
    func_80029A8C_2A68C(obj->model[1]);
    func_80029AFC_2A6FC(obj->model[1]);
    w = obj->unk_50;
    w->unk_EC = NULL;
    obj->model[3] = LoadFormFile(7, 0x26BD);
    obj->model[4] = LoadFormFile(8, 0x26BD);
    obj->model[7] = LoadFormFile(0xC, 0x26BD);
    obj->model[8] = LoadFormFile(0xB, 0x26BD);
    func_80019F0C_1AB0C(obj, 0, dir, 1, 0);
    func_80019F0C_1AB0C(obj, 1, dir | 1, 1, 0);
    func_80019F0C_1AB0C(obj, 2, dir | 2, 1, 0);
    func_80019F0C_1AB0C(obj, 6, dir | 4, 1, 0x13);
    func_80019F0C_1AB0C(obj, 8, dir | 6, 1, 0x1B);
    func_80019F0C_1AB0C(obj, 0x11, dir | 0xF, 1, 0xF);
    func_80019F0C_1AB0C(obj, 0x12, dir | 0x10, 2, 0);
    func_80019F0C_1AB0C(obj, 0x15, dir | 0x2E, 0, 0);
    func_80019F0C_1AB0C(obj, 3, dir | 0x2C, 1, 0);
    func_80019F0C_1AB0C(obj, 4, dir | 0x2D, 1, 0);
    func_80019F0C_1AB0C(obj, 0x20, dir | 0x31, 0, 0);
    if ((rand8() & 0x7F) < 0x80U) {
        func_80019F0C_1AB0C(obj, 0xD, dir | 0x4E, 1, 0x78);
        D_80107C00_27A330_TileDriver[obj->work[0]][0] = 0;
    } else {
        func_80019F0C_1AB0C(obj, 0xD, dir | 0x4F, 1, 0x78);
        D_80107C00_27A330_TileDriver[obj->work[0]][0] = 1;
    }
    if ((rand8() & 0x7F) < 0x80U) {
        func_80019F0C_1AB0C(obj, 0xE, dir | 0x55, 1, 0x78);
        D_80107C00_27A330_TileDriver[obj->work[0]][1] = 2;
    } else {
        func_80019F0C_1AB0C(obj, 0xE, dir | 0x56, 1, 0x78);
        D_80107C00_27A330_TileDriver[obj->work[0]][1] = 3;
    }
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    if (gPlayers[obj->work[0]].flags & 1) {
        switch (gPlayers[obj->work[0]].cpu_difficulty) {
        case 0:
            o->chance = 3;
            o->jump = 2;
            o->miss = 4;
            o->speed = 55;
            o->unk_38 = 180.0f;
            D_80107C7D_27A3AD_TileDriver = 0;
            break;
        case 1:
            o->chance = 5;
            o->jump = 3;
            o->miss = 3;
            o->speed = 60;
            o->unk_38 = 160.0f;
            D_80107C7D_27A3AD_TileDriver = 1;
            break;
        case 2:
            o->chance = 7;
            o->jump = 4;
            o->miss = 2;
            o->speed = 65;
            o->unk_38 = 140.0f;
            D_80107C7D_27A3AD_TileDriver = 2;
            break;
        default:
            o->chance = 9;
            o->jump = 5;
            o->miss = 1;
            o->speed = 70;
            o->unk_38 = 120.0f;
            D_80107C7D_27A3AD_TileDriver = 3;
            break;
        }
    }
    func_8000C024_CC24(obj, 0, 2);
    func_80019B9C_1A79C(obj, 0);
    D_800F8FD0_F9BD0 = 1;
    func_80103488_275BB8_TileDriver(obj->work[0]);
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80029EDC_2AADC(obj->model[0], mask = 1 << obj->work[0]);
    func_80029EDC_2AADC(obj->model[1], mask);
    func_80029EDC_2AADC(obj->model[3], mask);
    func_80029EDC_2AADC(obj->model[4], mask);
    func_80029EDC_2AADC(obj->model[7], mask);
    func_80029EDC_2AADC(obj->model[8], mask);
    w->unk_50 |= 0x400;
    obj->func_ptr = func_80103988_2760B8_TileDriver;
}

void func_801043A4_276AD4_TileDriver(void) {
    s16 i;
    omObjData* o;
    TDObj* r;
    u8 n;

    for (i = 0; i < 4; i++) {
        r = D_80107CF0_27A420_TileDriver + i;
        o = omAddObj(200, 9, 60, -1, func_80103E24_276554_TileDriver);
        switch (i) {
        case 0:
            n = 0;
            break;
        case 1:
            n = 1;
            break;
        case 2:
            n = 2;
            break;
        case 3:
            n = 3;
            break;
        default:
            n = 0;
            break;
        }
        o->work[0] = n;
        r->obj = o;
        D_800FFFD8_100BD8[D_800FC87A_FD47A] = o;
        D_800FC87A_FD47A++;
    }
}

void func_801044C8_276BF8_TileDriver(omObjData* obj) {
    TDObj* o = &D_80107CF0_27A420_TileDriver[obj->work[0]];
    u8 p = obj->work[0] - 10;
    s16 i;
    s32 k;
    TDObj* r;
    f32 a;

    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    for (i = 0, k = 1; i < 9; i++, k++) {
        if (D_80107C58_27A388_TileDriver[p][i] == 1) {
            o->unk_38 -= 30.0f;
            o->unk_3C += HuMathSin(o->unk_38) * 10.0f;
            if (o->unk_38 <= 180.0f) {
                o->unk_40 = TD_WRAP(o->unk_40 + 20.0f);
            }
            if ((s32)o->unk_40 / 120 * 120 == (s32)o->unk_40 - 20) {
                func_80079798_7A398(0x2F5, p);
            }
            if (o->unk_38 <= 0.0f) {
                o->unk_38 = 0.0f;
                o->unk_3C = D_80107A30_27A160_TileDriver[i].y;
                if (D_80107C10_27A340_TileDriver[p][i] >= 2) {
                    D_80107C10_27A340_TileDriver[p][i] = 0;
                } else {
                    D_80107C10_27A340_TileDriver[p][i]++;
                }
                o->unk_40 = (f32)D_80107C10_27A340_TileDriver[p][i] * 120.0f;
                D_80107C58_27A388_TileDriver[p][i] = 0;
                func_80079798_7A398(0x2F6, p);
                r = D_80107CF0_27A420_TileDriver + p;
                if (r->obj != NULL) {
                    r->punched = 0;
                }
            }
            func_80029714_2A314(obj->model[(s16)k], D_80107B08_27A238_TileDriver[i].x, o->unk_3C, D_80107B08_27A238_TileDriver[i].z);
            func_8002979C_2A39C(obj->model[(s16)k], o->unk_40, obj->rot.y, obj->rot.z);
        } else {
            func_80029714_2A314(obj->model[(s16)k], D_80107B08_27A238_TileDriver[i].x, D_80107B08_27A238_TileDriver[i].y, D_80107B08_27A238_TileDriver[i].z);
            a = TD_WRAP((f32)D_80107C10_27A340_TileDriver[p][i] * 120.0f);
            func_8002979C_2A39C(obj->model[(s16)k], a, obj->rot.y, obj->rot.z);
        }
        func_800297E8_2A3E8(obj->model[(s16)k], obj->scale.x, obj->scale.y, obj->scale.z);
    }
}

void func_801049A0_2770D0_TileDriver(omObjData* obj) {
    TDObj* o = &D_80107CF0_27A420_TileDriver[obj->work[0]];
    s32 attr = 0x22299;
    s16 i;
    s16 j;
    u8 c;
    f32 a;
    s32 mask;

    obj->model[0] = LoadFormFile(0x470003, attr);
    for (i = 1; i < 10; i++) {
        obj->model[i] = LoadFormFile(D_80107B74_27A2A4_TileDriver[i - 1] | 0x470000, attr);
    }
    obj->trans.x = obj->trans.z = 0.0f;
    obj->trans.y = -48.600002f;
    obj->scale.x = obj->scale.y = obj->scale.z = 0.6f;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    for (i = 0; i < 9; i++) {
        if (obj->work[0] == 10) {
            c = rand8() % 3;
            if (D_80107C4B_27A37B_TileDriver[1][c] >= 4) {
                if (c == 2) {
                    c = D_80107C4B_27A37B_TileDriver[1][0] >= 4;
                } else {
                    c++;
                    if (D_80107C4B_27A37B_TileDriver[1][c] >= 4) {
                        if (c == 2) {
                            c = 0;
                        } else {
                            c++;
                        }
                    }
                }
            }
            D_80107C4B_27A37B_TileDriver[1][c]++;
            for (j = 0; j < 4; j++) {
                D_80107C10_27A340_TileDriver[j][i] = c;
            }
            a = TD_WRAP((f32)c * 120.0f);
        } else {
            a = TD_WRAP((f32)D_80107C10_27A340_TileDriver[obj->work[0] - 10][i] * 120.0f);
        }
        if (i == 0) {
            o->unk_3C = D_80107A30_27A160_TileDriver[0].y;
        }
        func_8002979C_2A39C(obj->model[i + 1], a, obj->rot.y, obj->rot.z);
        func_80029714_2A314(obj->model[i + 1], D_80107B08_27A238_TileDriver[i].x, D_80107B08_27A238_TileDriver[i].y, D_80107B08_27A238_TileDriver[i].z);
        func_800297E8_2A3E8(obj->model[i + 1], obj->scale.x, obj->scale.y, obj->scale.z);
    }
    mask = 1 << (obj->work[0] - 10);
    for (i = 0; i < 10; i++) {
        func_80029EDC_2AADC(obj->model[i], (s16)mask);
    }
    obj->func_ptr = func_801044C8_276BF8_TileDriver;
}

void func_80104E08_277538_TileDriver(void) {
    s16 i;
    omObjData* o;
    TDObj* r;

    for (i = 0; i < 4; i++) {
        r = &D_80107CF0_27A420_TileDriver[10] + i;
        o = omAddObj(300, 10, 0, -1, func_801049A0_2770D0_TileDriver);
        o->work[0] = i + 10;
        r->obj = o;
    }
}

void func_80104EA8_2775D8_TileDriver(omObjData* obj) {
    s16 i;
    f32 a;
    f32 k;
    f32 d;

    if (D_80107C08_27A338_TileDriver >= 60) {
        func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
        func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
        for (i = 0; i < 9; i++) {
            func_80029714_2A314(obj->model[i + 1], D_80107A9C_27A1CC_TileDriver[i].x * 0.15f + obj->trans.x,
                                D_80107A9C_27A1CC_TileDriver[i].y + obj->trans.y, D_80107A9C_27A1CC_TileDriver[i].z * 0.15f + obj->trans.z);
            func_800297E8_2A3E8(obj->model[i + 1], obj->scale.x, obj->scale.y, obj->scale.z);
        }
    } else if (D_80107C08_27A338_TileDriver >= 30 && D_80107C08_27A338_TileDriver < 60) {
        d = 0.0037500001f;
        obj->scale.x -= d;
        obj->scale.y -= d;
        obj->scale.z -= d;
        k = 1.5f;
        obj->trans.x = 0.0f;
        a = TD_WRAP(k * (f32)(D_80107C08_27A338_TileDriver - 30) + 270.0f);
        obj->trans.y = -(HuMathSin(a) * 1000.0f);
        a = TD_WRAP(k * (f32)(D_80107C08_27A338_TileDriver - 30) + 270.0f);
        obj->trans.z = func_800B7890_B8490(a) * 1000.0f;
        func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
        func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
        for (i = 0; i < 9; i++) {
            func_80029714_2A314(obj->model[i + 1], D_80107A9C_27A1CC_TileDriver[i].x * obj->scale.x + obj->trans.x,
                                D_80107A9C_27A1CC_TileDriver[i].y + obj->trans.y, D_80107A9C_27A1CC_TileDriver[i].z * obj->scale.z + obj->trans.z);
            func_800297E8_2A3E8(obj->model[i + 1], obj->scale.x, obj->scale.y, obj->scale.z);
        }
    } else {
        func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
        func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
        for (i = 0; i < 9; i++) {
            func_80029714_2A314(obj->model[i + 1], D_80107A9C_27A1CC_TileDriver[i].x * 0.0375f + obj->trans.x,
                                D_80107A9C_27A1CC_TileDriver[i].y + obj->trans.y, D_80107A9C_27A1CC_TileDriver[i].z * 0.0375f + obj->trans.z);
            func_800297E8_2A3E8(obj->model[i + 1], obj->scale.x, obj->scale.y, obj->scale.z);
        }
    }
}

void func_801053A4_277AD4_TileDriver(omObjData* obj) {
    f32 a;

    if (D_80107C08_27A338_TileDriver >= 130 && D_80107C08_27A338_TileDriver < 140) {
        a = TD_WRAP((f32)D_80107C10_27A340_TileDriver[4][4] * 120.0f + (f32)((140 - D_80107C08_27A338_TileDriver) * 12));
        func_8002979C_2A39C(obj->model[5], a, obj->rot.y, obj->rot.z);
        if (D_80107C08_27A338_TileDriver == 139) {
            PlaySound(0x2F5);
        }
    } else if (D_80107C08_27A338_TileDriver >= 120 && D_80107C08_27A338_TileDriver < 130) {
        a = TD_WRAP((f32)D_80107C10_27A340_TileDriver[4][4] * 120.0f + 120.0f);
        func_8002979C_2A39C(obj->model[5], a, obj->rot.y, obj->rot.z);
        if (D_80107C08_27A338_TileDriver == 129) {
            PlaySound(0x2F6);
        }
    } else if (D_80107C08_27A338_TileDriver >= 110 && D_80107C08_27A338_TileDriver < 120) {
        a = TD_WRAP((f32)D_80107C10_27A340_TileDriver[4][4] * 120.0f + 120.0f + (f32)((120 - D_80107C08_27A338_TileDriver) * 12));
        func_8002979C_2A39C(obj->model[5], a, obj->rot.y, obj->rot.z);
        if (D_80107C08_27A338_TileDriver == 119) {
            PlaySound(0x2F5);
        }
    } else if ((u16)D_80107C08_27A338_TileDriver - 100U < 10U) {
        if (D_80107C08_27A338_TileDriver == 109) {
            PlaySound(0x2F6);
        }
    } else if (D_80107C08_27A338_TileDriver >= 90 && D_80107C08_27A338_TileDriver < 100) {
        a = TD_WRAP((f32)D_80107C10_27A340_TileDriver[4][4] * 120.0f + 240.0f + (f32)((100 - D_80107C08_27A338_TileDriver) * 12));
        func_8002979C_2A39C(obj->model[5], a, obj->rot.y, obj->rot.z);
        if (D_80107C08_27A338_TileDriver == 99) {
            PlaySound(0x2F5);
        }
    } else {
        a = TD_WRAP((f32)D_80107C10_27A340_TileDriver[4][4] * 120.0f);
        func_8002979C_2A39C(obj->model[5], a, obj->rot.y, obj->rot.z);
        D_80107C3D_27A36D_TileDriver[4] = 1;
        if (D_80107C08_27A338_TileDriver == 89) {
            PlaySound(0x2F6);
        }
    }
}

void func_801059B4_2780E4_TileDriver(omObjData* obj) {
    s16 i;
    f32 a;

    if (D_80107C08_27A338_TileDriver >= 75 && D_80107C08_27A338_TileDriver < 90) {
        for (i = 0; i < 9; i++) {
            if (D_80107C3D_27A36D_TileDriver[i] == 0) {
                a = TD_WRAP((f32)D_80107C10_27A340_TileDriver[4][i] * 120.0f + (f32)((90 - D_80107C08_27A338_TileDriver) * 24));
                func_8002979C_2A39C(obj->model[i + 1], a, obj->rot.y, obj->rot.z);
                if (D_80107C08_27A338_TileDriver == 85 || D_80107C08_27A338_TileDriver == 80 || D_80107C08_27A338_TileDriver == 75) {
                    if (a / 120.0f == (f32)D_80107C10_27A340_TileDriver[4][4]) {
                        D_80107C10_27A340_TileDriver[4][i] = D_80107C10_27A340_TileDriver[4][4];
                        D_80107C3D_27A36D_TileDriver[i] = 1;
                    }
                }
            }
        }
        if (D_80107C08_27A338_TileDriver == 85 || D_80107C08_27A338_TileDriver == 80 || D_80107C08_27A338_TileDriver == 75) {
            PlaySound(0x2F6);
        } else if (D_80107C08_27A338_TileDriver == 89 || D_80107C08_27A338_TileDriver == 84 || D_80107C08_27A338_TileDriver == 79) {
            PlaySound(0x2F5);
        }
    }
    if (D_80107C08_27A338_TileDriver == 74) {
        switch (D_80107C10_27A340_TileDriver[4][4]) {
        case 0:
            PlaySound(0x2F8);
            break;
        case 1:
            PlaySound(0x2F7);
            break;
        default:
            PlaySound(0x2F9);
            break;
        }
    }
}

void func_80105C78_2783A8_TileDriver(omObjData* obj) {
    s16 i;

    switch (D_80107C0C_27A33C_TileDriver) {
    case 0:
        func_80104EA8_2775D8_TileDriver(obj);
        func_801053A4_277AD4_TileDriver(obj);
        func_801059B4_2780E4_TileDriver(obj);
        break;
    case 1:
        for (i = 0; i < 10; i++) {
            func_800298A4_2A4A4(obj->model[i], 4, 4);
        }
        func_80029714_2A314(obj->model[D_80107C10_27A340_TileDriver[4][4] + 10], obj->trans.x, obj->trans.y, obj->trans.z);
        func_8002979C_2A39C(obj->model[D_80107C10_27A340_TileDriver[4][4] + 10], obj->rot.x, obj->rot.y, obj->rot.z);
        func_800297E8_2A3E8(obj->model[D_80107C10_27A340_TileDriver[4][4] + 10], obj->scale.x, obj->scale.y, obj->scale.z);
        func_800298A4_2A4A4(obj->model[D_80107C10_27A340_TileDriver[4][4] + 10], 4, 0);
        break;
    }
}


void func_80105DB0_2784E0_TileDriver(omObjData* obj) {
    u16 files[3] = { 13, 14, 15 };
    s32 attr = 0x22299;
    s16 i;
    u8 c;
    f32 a;

    obj->model[0] = LoadFormFile(0x470003, attr);
    for (i = 1; i < 10; i++) {
        obj->model[i] = LoadFormFile(D_80107B74_27A2A4_TileDriver[i - 1] | 0x470000, attr | 0x400);
    }
    for (i = 10; i < 13; i++) {
        obj->model[i] = LoadFormFile(files[i - 10] | 0x470000, attr);
    }
    obj->trans.x = 0.0f;
    obj->trans.y = -(HuMathSin(315.0f) * 1000.0f);
    obj->trans.z = func_800B7890_B8490(315.0f) * 1000.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 0.15f;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_8002979C_2A39C(obj->model[0], obj->rot.x, obj->rot.y, obj->rot.z);
    func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    func_800297E8_2A3E8(obj->model[5], obj->scale.x, obj->scale.y, obj->scale.z);
    c = D_800FA656;
    D_80107C4B_27A37B_TileDriver[0][c]++;
    a = TD_WRAP((f32)c * 120.0f);
    func_8002979C_2A39C(obj->model[5], a, obj->rot.y, obj->rot.z);
    func_80029714_2A314(obj->model[5], D_80107A9C_27A1CC_TileDriver[5].x * 0.15f + obj->trans.x, D_80107A9C_27A1CC_TileDriver[5].y + obj->trans.y,
                        D_80107A9C_27A1CC_TileDriver[5].z * 0.15f + obj->trans.z);
    D_80107C10_27A340_TileDriver[4][4] = c;
    for (i = 0; i < 4; i++) {
        func_800297E8_2A3E8(obj->model[i + 1], obj->scale.x, obj->scale.y, obj->scale.z);
        c = rand8() % 3;
        if (D_80107C4B_27A37B_TileDriver[0][c] >= 4) {
            if (c == 2) {
                c = D_80107C4B_27A37B_TileDriver[0][0] >= 4;
            } else {
                c++;
                if (D_80107C4B_27A37B_TileDriver[0][c] >= 4) {
                    if (c == 2) {
                        c = 0;
                    } else {
                        c++;
                    }
                }
            }
        }
        D_80107C4B_27A37B_TileDriver[0][c]++;
        a = TD_WRAP((f32)c * 120.0f);
        func_8002979C_2A39C(obj->model[i + 1], a, obj->rot.y, obj->rot.z);
        func_80029714_2A314(obj->model[i + 1], D_80107A9C_27A1CC_TileDriver[i].x * 0.15f + obj->trans.x, D_80107A9C_27A1CC_TileDriver[i].y + obj->trans.y,
                            D_80107A9C_27A1CC_TileDriver[i].z * 0.15f + obj->trans.z);
        D_80107C10_27A340_TileDriver[4][i] = c;
    }
    for (i = 5; i < 9; i++) {
        func_800297E8_2A3E8(obj->model[i + 1], obj->scale.x, obj->scale.y, obj->scale.z);
        c = rand8() % 3;
        if (D_80107C4B_27A37B_TileDriver[0][c] >= 4) {
            if (c == 2) {
                c = D_80107C4B_27A37B_TileDriver[0][0] >= 4;
            } else {
                c++;
                if (D_80107C4B_27A37B_TileDriver[0][c] >= 4) {
                    if (c == 2) {
                        c = 0;
                    } else {
                        c++;
                    }
                }
            }
        }
        D_80107C4B_27A37B_TileDriver[0][c]++;
        a = TD_WRAP((f32)c * 120.0f);
        func_8002979C_2A39C(obj->model[i + 1], a, obj->rot.y, obj->rot.z);
        func_80029714_2A314(obj->model[i + 1], D_80107A9C_27A1CC_TileDriver[i].x * 0.15f + obj->trans.x, D_80107A9C_27A1CC_TileDriver[i].y + obj->trans.y,
                            D_80107A9C_27A1CC_TileDriver[i].z * 0.15f + obj->trans.z);
        D_80107C10_27A340_TileDriver[4][i] = c;
    }
    for (i = 10; i < 13; i++) {
        func_80029714_2A314(obj->model[i], obj->trans.x, obj->trans.y, obj->trans.z);
        func_8002979C_2A39C(obj->model[i], obj->rot.x, obj->rot.y, obj->rot.z);
        func_800297E8_2A3E8(obj->model[i], obj->scale.x, obj->scale.y, obj->scale.z);
        func_800298A4_2A4A4(obj->model[i], 4, 4);
    }
    for (i = 0; i < 10; i++) {
        func_80029EDC_2AADC(obj->model[i], 0x10);
    }
    obj->func_ptr = func_80105C78_2783A8_TileDriver;
}

void func_801065EC_278D1C_TileDriver(void) {
    omObjData* o = omAddObj(300, 13, 0, -1, func_80105DB0_2784E0_TileDriver);

    o->work[0] = 14;
    D_80107CF0_27A420_TileDriver[14].obj = o;
}

void func_80106630_278D60_TileDriver(void) {
    s16 i;

    for (i = 0; i < 4; i++) {
        if ((D_80107CF0_27A420_TileDriver + i)->obj != NULL) {
            if (D_80107C46_27A376_TileDriver == 1 && i == D_80107C7C_27A3AC_TileDriver) {
                gPlayers[i].coins_mg_bonus = 10;
            } else {
                gPlayers[i].coins_mg_bonus = 0;
            }
        }
    }
}

void func_801066F8_278E28_TileDriver(omObjData* obj) {
    if (_CheckFlag(0xC) != 0) {
        if (D_80107C08_27A338_TileDriver > 0) {
            D_80107C08_27A338_TileDriver--;
            if (D_80107C08_27A338_TileDriver == 30) {
                goto bonus;
            }
            goto end;
        }
    } else if (D_80107C08_27A338_TileDriver > 0) {
        D_80107C08_27A338_TileDriver--;
        if (D_80107C08_27A338_TileDriver == 60) {
        bonus:
            func_80106630_278D60_TileDriver();
            return;
        }
    end:
        if (D_80107C08_27A338_TileDriver == 0) {
            D_80107C0D_27A33D_TileDriver = 1;
            D_80107C08_27A338_TileDriver = 0;
        }
    }
}

/* NON_MATCHING: retail computes the gPlayers index in $v1 with the winner in $v0; GCC swaps them (register allocation only, masked 0). */
#ifdef NON_MATCHING
void func_801067B4_278EE4_TileDriver(omObjData* obj) {
    s16 m;

    if (D_80107C46_27A376_TileDriver == 0) {
        func_800691FC_69DFC(0x13);
        m = 0x57;
    } else {
        func_800691FC_69DFC(6, gPlayers[D_80107C7C_27A3AC_TileDriver].character);
        m = 0x51;
    }
    PlayMusic(m);
    D_80107C08_27A338_TileDriver = 120;
    obj->func_ptr = func_801066F8_278E28_TileDriver;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_37_TileDriver/274F30", func_801067B4_278EE4_TileDriver);
#endif

void func_80106844_278F74_TileDriver(omObjData* obj) {
    s16 i;
    omObjData* o;
    MgWork* w;

    if (_CheckFlag(0xC) != 0) {
        if (D_80107C08_27A338_TileDriver > 0) {
            D_80107C08_27A338_TileDriver--;
            if (D_80107C08_27A338_TileDriver == 135) {
                D_80107C0D_27A33D_TileDriver = 1;
                func_8006D518_6E118();
                obj->func_ptr = func_801066F8_278E28_TileDriver;
                D_80107C08_27A338_TileDriver = 60;
            }
        }
    } else if (func_80069538_6A138() == 0) {
        func_8006D518_6E118();
        for (i = 0; i < 4; i++) {
            o = (D_80107CF0_27A420_TileDriver + i)->obj;
            if (o != NULL) {
                w = o->unk_50;
                if (!(w->unk_5C & 2) || w->unk_3C != 0.0f) {
                    break;
                }
            }
        }
        if (i >= 4) {
            D_80107C0D_27A33D_TileDriver = 1;
            obj->func_ptr = func_801067B4_278EE4_TileDriver;
        }
    }
}

void func_80106984_2790B4_TileDriver(omObjData* obj) {
    if (D_80107C46_27A376_TileDriver == 1) {
        obj->func_ptr = func_80106844_278F74_TileDriver;
        D_80107C0D_27A33D_TileDriver = 1;
        func_800691FC_69DFC(3);
        func_8006D518_6E118();
    } else if (D_80107C08_27A338_TileDriver > 0) {
        D_80107C08_27A338_TileDriver--;
        func_8006D4D0_6E0D0((D_80107C08_27A338_TileDriver + 29) / 30);
        return;
    } else {
        obj->func_ptr = func_80106844_278F74_TileDriver;
        D_80107C0D_27A33D_TileDriver = 1;
        func_8006D4D0_6E0D0(0);
        func_800691FC_69DFC(3);
    }
    func_800794A8_7A0A8(40);
    D_80107C08_27A338_TileDriver = 150;
}

void func_80106A74_2791A4_TileDriver(omObjData* obj) {
    func_800691FC_69DFC(10, 60, 160, 28);
    D_80107C08_27A338_TileDriver = 1801;
    obj->func_ptr = func_80106984_2790B4_TileDriver;
}

void func_80106AC0_2791F0_TileDriver(omObjData* obj) {
    if (func_80069538_6A138() == 0) {
        D_80107C0D_27A33D_TileDriver = 1;
        D_80107C08_27A338_TileDriver = 0;
        obj->func_ptr = func_80106A74_2791A4_TileDriver;
    }
}

void func_80106B08_279238_TileDriver(omObjData* obj) {
    if (D_80107C0C_27A33C_TileDriver == 1) {
        func_800691FC_69DFC(0);
        obj->func_ptr = func_80106AC0_2791F0_TileDriver;
    } else if (D_80107C08_27A338_TileDriver > 0) {
        D_80107C08_27A338_TileDriver--;
    } else {
        D_80107C0D_27A33D_TileDriver = 1;
    }
}

void func_80106B7C_2792AC_TileDriver(void) {
    osViBlack(0);
    omOvlReturnEx(1);
}

void func_80106BA0_2792D0_TileDriver(omObjData* obj) {
    if (func_8008F618_90218() == 0) {
        obj->func_ptr = func_80106B7C_2792AC_TileDriver;
    }
}

void func_80106BD8_279308_TileDriver(omObjData* obj) {
    if (D_801011FC_101DFC == 1) {
        InitFadeOut(0, 20);
        obj->func_ptr = func_80106BA0_2792D0_TileDriver;
        func_800794A8_7A0A8(40);
        func_80079614_7A214(40);
    }
}

void func_80106C30_279360_TileDriver(void) {
    D_80107C0C_27A33C_TileDriver += D_80107C0D_27A33D_TileDriver;
    D_80107C0D_27A33D_TileDriver = 0;
}

void func_80106C58_279388_TileDriver(void) {
    u8 k;
    s16 j;
    s16 i;
    s16 n;

    if (D_80107C0C_27A33C_TileDriver < 4 && D_80107C46_27A376_TileDriver == 0) {
        for (i = 0; i < 4; i++) {
            if ((&D_80107CF0_27A420_TileDriver[10] + i)->obj != NULL) {
                for (j = 0; j < 9; j++) {
                    if (D_80107C10_27A340_TileDriver[4][4] != D_80107C10_27A340_TileDriver[i][j]) {
                        break;
                    }
                }
                if (j >= 9) {
                    D_80107C47_27A377_TileDriver[i] = 1;
                }
            }
        }
        k = rand8() & 3;
        for (i = 0, n = k; i < 4; i++) {
            n = n < 4 ? n : 0;
            k = D_80107C47_27A377_TileDriver[n];
            if (k == 1) {
                D_80107C46_27A376_TileDriver = 1;
                D_80107C7C_27A3AC_TileDriver = n;
                switch (D_80107C10_27A340_TileDriver[4][4]) {
                case 0:
                    PlaySound(0x2F8);
                    return;
                case 1:
                    PlaySound(0x2F7);
                    return;
                default:
                    PlaySound(0x2F9);
                    return;
                }
            }
            n++;
        }
    }
}

void func_80106E20_279550_TileDriver(omObjData* obj) {
    if (D_80107BA8_27A2D8_TileDriver == 0) {
        PlayMusic(0x1D);
        D_80107BA8_27A2D8_TileDriver = 1;
    }
    func_80106C30_279360_TileDriver();
    func_80106C58_279388_TileDriver();
    switch (D_80107C0C_27A33C_TileDriver) {
    case 2:
        break;
    case 3:
        if (D_80107C0A_27A33A_TileDriver > 0) {
            D_80107C0A_27A33A_TileDriver--;
        }
        break;
    case 4:
        break;
    case 5:
        InitFadeOut(0, 20);
        obj->func_ptr = func_80106BA0_2792D0_TileDriver;
        break;
    }
}

void func_80106ED8_279608_TileDriver(void) {
    s16 i;
    s16 j;

    D_80107C08_27A338_TileDriver = 150;
    D_80107C0A_27A33A_TileDriver = 30;
    D_80107C0D_27A33D_TileDriver = 0;
    D_80107C0C_27A33C_TileDriver = 0;
    D_80107C46_27A376_TileDriver = 0;
    D_80107C7C_27A3AC_TileDriver = 0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 9; j++) {
            D_80107C10_27A340_TileDriver[i][j] = 0;
        }
    }
    for (i = 0; i < 9; i++) {
        D_80107C3D_27A36D_TileDriver[i] = 0;
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            D_80107C4B_27A37B_TileDriver[i][j] = 0;
        }
    }
    for (i = 0; i < 4; i++) {
        D_80107C47_27A377_TileDriver[i] = 0;
        for (j = 0; j < 9; j++) {
            D_80107C58_27A388_TileDriver[i][j] = 0;
        }
    }
}

void func_801070A4_2797D4_TileDriver(omObjData* obj) {
    func_80107890_279FC0_TileDriver();
    func_80107914_27A044_TileDriver();
    func_80106ED8_279608_TileDriver();
    func_8010316C_27589C_TileDriver();
    func_801043A4_276AD4_TileDriver();
    func_80104E08_277538_TileDriver();
    func_801065EC_278D1C_TileDriver();
    func_801032BC_2759EC_TileDriver();
    func_80103444_275B74_TileDriver();
    InitFadeIn(0, 16);
    obj->func_ptr = func_80106E20_279550_TileDriver;
    omAddObj(50, 0, 0, -1, func_8010281C_274F4C_TileDriver);
    D_80107C0C_27A33C_TileDriver = 0;
    omAddObj(600, 0, 0, -1, func_80106B08_279238_TileDriver);
}

__asm__(".section .rodata");
const char D_80107BD0_27A300_TileDriver[] = "\202`\202a\202b";

void func_80107168_279898_TileDriver(void) {
    omObjData* o;
    u8 i;

    func_8002D4D0_2E0D0(30);
    func_80020D20_21920(30);
    omInitObjMan(30, 0);
    func_80079128_79D28();
    func_80018E30_19A30(5);
    func_80018F58_19B58(5);
    func_8010281C_274F4C_TileDriver();
    for (i = 0; i < 5; i++) {
        ScissorSet(i, D_80107940_27A070_TileDriver[i][0], D_80107940_27A070_TileDriver[i][1], D_80107940_27A070_TileDriver[i][2], D_80107940_27A070_TileDriver[i][3]);
        ViewportSet(i, D_801079A0_27A0D0_TileDriver[i][0], D_801079A0_27A0D0_TileDriver[i][1], D_801079A0_27A0D0_TileDriver[i][2], D_801079A0_27A0D0_TileDriver[i][3], D_801079A0_27A0D0_TileDriver[i][4],
                    D_801079A0_27A0D0_TileDriver[i][5]);
        Hu3DCamSetPerspective(i, 20.0f, 80.0f, 8000.0f);
    }
    o = omAddObj(0x7FDA, 0, 0, -1, func_80079FF4_7ABF4);
    o->work[0] = 5;
    omSetStatBit(o, 0xA0);
    func_80026D28_27928(1);
    func_80026E00_27A00(0, -20.0f, 40.0f, 100.0f);
    func_80026DAC_279AC(0, 0x90, 0x90, 0x90);
    func_80026E00_27A00(1, -20.0f, 40.0f, 100.0f);
    func_80026DAC_279AC(1, 0xFF, 0xFF, 0xFF);
    D_800FA606_FB206 = 0;
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    omAddObj(1000, 0, 0, -1, func_801070A4_2797D4_TileDriver);
    omAddObj(1000, 0, 0, -1, func_80106BD8_279308_TileDriver);
    func_8007273C_7333C(D_80107BD0_27A300_TileDriver, 0);
    func_8007273C_7333C(D_80107BD0_27A300_TileDriver, 1);
}

/* NON_MATCHING: retail keeps the quotient in $f2 and converts it in the delay slot (f64 register allocation, masked 8; twins in ovl_0A, ovl_23, MP1 are the same). */
#ifdef NON_MATCHING
f32 func_801073BC_279AEC_TileDriver(f32 x) {
    f32 a;
    f32 b;
    f32 sum;
    f64 frac;
    f64 base;
    s32 sign;
    s32 i;

    sign = 1;
    if (x > 1.0f) {
        x = 1.0f / x;
    } else {
        sign = -1;
        if (x < -1.0f) {
            x = 1.0f / x;
        } else {
            sign = 0;
        }
    }
    sum = 0.0f;
    i = 6;
    do {
        a = (f32)(i * i) * x * x;
        b = (f32)(i * 2 + 1) + sum;
        i--;
        sum = a / b;
    } while (i > 0);
    if (sum != -1.0f) {
        if (sign > 0) {
            base = 1.5707963267948966;
            frac = x / (sum + 1.0f);
            goto done;
        }
        if (sign < 0) {
            frac = x / (sum + 1.0f);
            base = -1.5707963267948966;
        done:
            return base - frac;
        }
        return x / (sum + 1.0f);
    }
    return 0.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_37_TileDriver/274F30", func_801073BC_279AEC_TileDriver);
#endif

/* NON_MATCHING: the 180.0f load is scheduled before the near-zero test (masked 29; same residue as ovl_0A and ovl_23). */
#ifdef NON_MATCHING
void func_8010750C_279C3C_TileDriver(Vec* from, Vec* to, Vec* out) {
    Vec delta;
    Vec fromV;
    Vec toV;
    f32 horizontal;
    f32 pitch;
    f32 yaw;
    s32 nearPositive;
    s32 nearNegative;

    fromV.x = from->x;
    fromV.y = from->y;
    fromV.z = from->z;
    toV.x = to->x;
    toV.y = to->y;
    toV.z = to->z;
    delta.x = toV.x - fromV.x;
    delta.y = toV.y - fromV.y;
    delta.z = toV.z - fromV.z;
    horizontal = func_800B1830_B2430(delta.x * delta.x + delta.z * delta.z);
    nearPositive = horizontal <= 0.002f;
    nearNegative = horizontal >= -0.002f;
    if (nearPositive & nearNegative) {
        horizontal = 0.0f;
        pitch = 180.0f;
        yaw = horizontal;
        if (!(delta.y > 0.0001f) && delta.y < 0.0001f) {
            pitch = horizontal;
        }
    } else {
        if (delta.x != 0.0f && delta.z != 0.0f) {
            yaw = func_801073BC_279AEC_TileDriver(delta.x / delta.z) * 57.29577951308232;
        } else if (delta.z == 0.0f) {
            if (delta.x >= 0.0f) {
                yaw = 90.0f;
            } else {
                yaw = 270.0f;
            }
        } else {
            yaw = 0.0f;
        }
        if (delta.z < 0.0f) {
            yaw -= 180.0f;
        }
        if (horizontal != 0.0f && delta.y != 0.0f) {
            pitch = func_801073BC_279AEC_TileDriver(delta.y / horizontal) * 57.29577951308232;
        } else {
            pitch = 0.0f;
        }
        yaw = yaw >= 360.0f ? yaw - 360.0f : yaw < 0.0f ? yaw + 360.0f : yaw;
        pitch = pitch + 90.0f >= 360.0f ? pitch + 90.0f - 360.0f : pitch + 90.0f < 0.0f ? pitch + 90.0f + 360.0f : pitch + 90.0f;
    }
    nearPositive = pitch <= 0.002f;
    nearNegative = pitch >= -0.002f;
    if (nearPositive & nearNegative) {
        pitch = 0.0f;
    }
    out->x = func_800B1830_B2430(delta.y * delta.y + horizontal * horizontal);
    out->z = yaw;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_37_TileDriver/274F30", func_8010750C_279C3C_TileDriver);
#endif
