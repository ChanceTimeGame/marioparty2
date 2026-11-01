#include "ovl_27.h"

#define ABSDIFF(x) ((x) > 0.0f ? (x) : (0.0f - (x)))

void func_80102800_1FEE60_AbandonShip(void) {
    omObjData* obj;

    func_8002D4D0_2E0D0(0x20);
    func_8002F290_2FE90(D_800F9D30_FA930, 0x40);
    func_80020D20_21920(0x40);
    omInitObjMan(0x20, 0);
    func_80079128_79D28();
    D_800FA606_FB206 = 0;
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    omSetStatBit(omAddObj(1, 0, 0, -1, func_80102A50_1FF0B0_AbandonShip), 0xA0);
    obj = omAddObj(0x7FDA, 0, 0, -1, func_80079E60_7AA60);
    omSetStatBit(obj, 0xA0);
    func_8000C38C_CF8C();
    func_80026DAC_279AC(1, 0x40, 0x40, 0x40);
    func_8010292C_1FEF8C_AbandonShip();
    ((void (*)(omObjData*))func_80079E60_7AA60)(obj);
    func_80106C40_2032A0_AbandonShip();
    func_80104350_2009B0_AbandonShip();
    func_80102EF8_1FF558_AbandonShip();
    func_801039B4_200014_AbandonShip();
    func_8002CA48_2D648(0x28, 0x2B, 0x82);
    InitFadeIn(0, 0x10);
}

void func_8010292C_1FEF8C_AbandonShip(void) {
    s32 cam;

    D_8010274C_10334C.x = 0.0f;
    D_8010274C_10334C.y = 200.0f;
    D_8010274C_10334C.z = -250.0f;
    D_800FD474_FE074.x = -10.0f;
    D_800FD474_FE074.y = 0.0f;
    D_800FD474_FE074.z = 0.0f;
    D_800FA610_FB210 = 2500.0f;
    func_80018E30_19A30(1);
    cam = func_80018E78_19A78();
    ScissorSet(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(cam, 30.0f, 80.0f, 8000.0f);
}

void func_80102A50_1FF0B0_AbandonShip(void) {
    switch (D_8010939E_2059FE_AbandonShip) {
    case 0:
        if (D_801011FC_101DFC == 1) {
            func_80079868_7A468();
            func_800794A8_7A0A8(0x28);
            InitFadeOut(0, 0x14);
            D_8010939E_2059FE_AbandonShip = 1;
        }
        break;
    case 1:
        if (func_8008F618_90218() == 0) {
            omOvlReturnEx(1);
            D_8010939E_2059FE_AbandonShip = 2;
        }
        break;
    }
    func_8000C3C8_CFC8();
    switch (D_800F8FD0_F9BD0) {
    case 0:
        if (D_80109398_2059F8_AbandonShip == 0x10) {
            D_80109540_205BA0_AbandonShip = PlaySound(0x4A2);
        }
        D_80109398_2059F8_AbandonShip++;
        if (D_801093C0_205A20_AbandonShip == 4) {
            if (D_8010939C_2059FC_AbandonShip == 0) {
                func_800799A4_7A5A4(D_80109540_205BA0_AbandonShip, 0x1E);
                func_800691FC_69DFC(0);
                D_8010939C_2059FC_AbandonShip++;
            }
            if (func_80069538_6A138() == 0 || (func_80069538_6A138() & 2)) {
                D_80109398_2059F8_AbandonShip = 0;
                D_801093C0_205A20_AbandonShip = 5;
                func_8000C3B8_CFB8();
            }
        }
        break;
    case 1:
        if (D_8010938C_2059EC_AbandonShip == 0) {
            func_800691FC_69DFC(0xA, D_80109384_2059E4_AbandonShip, 0xA0, 0x20);
            if (func_80069538_6A138() != 0) {
                func_80069538_6A138();
            }
        } else if (D_8010938C_2059EC_AbandonShip == D_80109384_2059E4_AbandonShip * 30) {
            func_8000C398_CF98();
        }
        if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
            D_80109394_2059F4_AbandonShip = (D_80109384_2059E4_AbandonShip * 30 - D_8010938C_2059EC_AbandonShip) / 30;
            D_8010938C_2059EC_AbandonShip++;
        }
        if (D_80109394_2059F4_AbandonShip < 0) {
            func_8000C398_CF98();
        } else {
            func_8006D4D0_6E0D0((s16)D_80109394_2059F4_AbandonShip);
        }
        break;
    case 2:
        if (D_80109390_2059F0_AbandonShip == 0) {
            func_800794A8_7A0A8(0x28);
            func_8000C690_D290();
            func_8006D518_6E118();
            if (D_8010939F_2059FF_AbandonShip == 0) {
                func_800691FC_69DFC(3);
                D_8010939F_2059FF_AbandonShip = 1;
            }
        } else if (D_80109390_2059F0_AbandonShip >= 10) {
            if (func_80069538_6A138() == 0 || (func_80069538_6A138() & 2)) {
                if (_CheckFlag(0xC) == 0) {
                    if (D_8010939D_2059FD_AbandonShip == 0) {
                        if (D_80109380_2059E0_AbandonShip == 0) {
                            PlayMusic(0x57);
                            func_800691FC_69DFC(0x13);
                            D_8010939D_2059FD_AbandonShip = 1;
                        } else if (D_80109440_205AA0_AbandonShip == 2) {
                            func_8006961C_6A21C(func_800691FC_69DFC(6, gPlayers[D_80109381_2059E1_AbandonShip].character), 160.0f, 160.0f);
                            D_8010939D_2059FD_AbandonShip = 1;
                        }
                    }
                } else if (D_80109390_2059F0_AbandonShip == 0x5A) {
                    InitFadeOut(0, 0x14);
                    func_8000C3A8_CFA8();
                }
            }
            if (D_8010939D_2059FD_AbandonShip == 1) {
                if (D_80109380_2059E0_AbandonShip == 0 && D_80109398_2059F8_AbandonShip == 0x78) {
                    InitFadeOut(0, 0x14);
                    func_8000C3A8_CFA8();
                }
                D_80109398_2059F8_AbandonShip++;
            }
        }
        if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
            D_80109390_2059F0_AbandonShip++;
        }
        break;
    case 3:
        if (func_8008F618_90218() == 0) {
            omOvlReturnEx(1);
        }
        break;
    }
}

void func_80102EF8_1FF558_AbandonShip(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        omSetStatBit(omAddObj(2, 2, 0, -1, func_80102F5C_1FF5BC_AbandonShip), 0xA0);
    }
}

/* NON_MATCHING: retail keeps 0x80000 in s1 for the 0x800C8 arm. */
#ifdef NON_MATCHING
void func_80102F5C_1FF5BC_AbandonShip(omObjData* obj) {
    s32 file;

    obj->func_ptr = func_80103070_1FF6D0_AbandonShip;
    obj->work[0] = D_80109388_2059E8_AbandonShip;
    obj->work[1] = 0;
    obj->model[0] = func_80018A30_19630(0x800C4, 0x2BD);
    if (D_80109388_2059E8_AbandonShip != 0) {
        file = 0x800C8;
    } else {
        file = 0x800C6;
    }
    obj->model[1] = func_80018A30_19630(file, 0x2BD);
    func_8002A00C_2AC0C(obj->model[0]);
    obj->scale.z = 1.0f;
    obj->scale.y = 1.0f;
    obj->scale.x = 1.0f;
    if (D_80109388_2059E8_AbandonShip == 0) {
        obj->trans.x = -900.0f;
    } else {
        obj->trans.x = 900.0f;
    }
    obj->trans.y = -100.0f;
    obj->trans.z = 900.0f;
    D_80109388_2059E8_AbandonShip++;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_AbandonShip/1FEE60", func_80102F5C_1FF5BC_AbandonShip);
#endif

/* NON_MATCHING: one register copy: retail 'move a2,s0' for the mast compare, here andi 0xFF (masked 1). */
#ifdef NON_MATCHING
void func_80103070_1FF6D0_AbandonShip(omObjData* obj) {
    omObjData* p;
    u8 s;
    s32 i;
    f32 dx;
    f32 dz;

    s = 0;
    if (D_801093C0_205A20_AbandonShip < 9) {
        if (D_801093C0_205A20_AbandonShip >= 5) {
            if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
                obj->trans.y = D_801093D4_205A34_AbandonShip / 2.0f + 0.0f - 100.0f;
            }
            func_8002A15C_2AD5C(obj->model[0], obj->model[1], D_801093A0_205A00_AbandonShip[obj->work[0]]);
            if (obj->work[1] == 0) {
                for (i = 0; i < 4; i++) {
                    if (D_800FFFD8_100BD8[i]->work[0] == 0) {
                        D_80109550_205BB0_AbandonShip[0] = D_800FFFD8_100BD8[i];
                    } else if (D_800FFFD8_100BD8[i]->work[0] == 3) {
                        D_80109550_205BB0_AbandonShip[1] = D_800FFFD8_100BD8[i];
                    } else if (D_800FFFD8_100BD8[i]->work[0] == 1) {
                        D_80109550_205BB0_AbandonShip[2] = D_800FFFD8_100BD8[i];
                    } else {
                        D_80109550_205BB0_AbandonShip[3] = D_800FFFD8_100BD8[i];
                    }
                }
                for (i = 0; i < 4; i++) {
                    p = D_80109550_205BB0_AbandonShip[i];
                    if (p->work[1] == 7) {
                        if (p->work[0] < 2 && obj->work[0] == 1) {
                            func_800298A4_2A4A4(obj->model[0], 4, 0);
                            if (p->work[0] == 0) {
                                obj->work[1] = 1;
                            } else if (p->work[0] == 1) {
                                obj->work[1] = 2;
                            }
                            if (p->work[2] != 0) {
                                D_80109568_205BC8_AbandonShip[obj->work[0]].x = p->trans.x + 200.0f;
                            } else {
                                D_80109568_205BC8_AbandonShip[obj->work[0]].x = p->trans.x;
                            }
                            D_80109568_205BC8_AbandonShip[obj->work[0]].y = p->trans.y;
                            D_80109568_205BC8_AbandonShip[obj->work[0]].z = p->trans.z - 50.0f;
                            break;
                        }
                        if (p->work[0] >= 2 && obj->work[0] == 0) {
                            func_800298A4_2A4A4(obj->model[0], 4, 0);
                            if (p->work[0] == 3) {
                                obj->work[1] = 1;
                            } else if (p->work[0] == 2) {
                                obj->work[1] = 2;
                            }
                            if (p->work[2] == 0) {
                                D_80109568_205BC8_AbandonShip[obj->work[0]].x = p->trans.x - 200.0f;
                            } else {
                                D_80109568_205BC8_AbandonShip[obj->work[0]].x = p->trans.x;
                            }
                            D_80109568_205BC8_AbandonShip[obj->work[0]].y = p->trans.y;
                            D_80109568_205BC8_AbandonShip[obj->work[0]].z = p->trans.z - 50.0f;
                            break;
                        }
                    }
                }
            } else if (obj->work[1] == 1 || obj->work[1] == 2) {
                if (obj->work[0] == 0) {
                    D_80109580_205BE0_AbandonShip.x = -900.0f;
                } else {
                    D_80109580_205BE0_AbandonShip.x = 900.0f;
                }
                D_80109584_205BE4_AbandonShip[0] = -100.0f;
                D_80109584_205BE4_AbandonShip[1] = 900.0f;
                func_80108DF0_205450_AbandonShip(&D_8010958C_205BEC_AbandonShip, (Vec*)(D_80109584_205BE4_AbandonShip - 1), &D_80109568_205BC8_AbandonShip[obj->work[0]]);
                if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
                    obj->trans.x += D_8010958C_205BEC_AbandonShip.x * 13.0f;
                    obj->trans.z += D_8010958C_205BEC_AbandonShip.z * 13.0f;
                }
                if (obj->work[0] == 0) {
                    if (obj->work[1] == 1) {
                        s = 3;
                    } else if (obj->work[1] == 2) {
                        s = 2;
                    }
                } else if (obj->work[0] == 1) {
                    if (obj->work[1] == 1) {
                        s = 0;
                    } else if (obj->work[1] == 2) {
                        s = 1;
                    }
                }
                for (i = 0; i < 4; i++) {
                    D_80109544_205BA4_AbandonShip[obj->work[0]] = D_800FFFD8_100BD8[i];
                    if (D_80109544_205BA4_AbandonShip[obj->work[0]]->work[0] == s) {
                        break;
                    }
                }
                if ((obj->work[0] == 0 && obj->trans.x >= D_80109568_205BC8_AbandonShip[0].x) ||
                    (obj->work[0] == 1 && obj->trans.x <= D_80109568_205BC8_AbandonShip[1].x)) {
                    obj->trans.z = D_80109568_205BC8_AbandonShip[obj->work[0]].z;
                    obj->work[1] = 3;
                    D_80109544_205BA4_AbandonShip[obj->work[0]]->work[1] = 8;
                }
            } else {
                if (obj->work[1] == 3) {
                    if (D_80109560_205BC0_AbandonShip[obj->work[0]] < 15) {
                        if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
                            D_801093A0_205A00_AbandonShip[obj->work[0]] -= 0.1f;
                        }
                        if (D_801093A0_205A00_AbandonShip[obj->work[0]] < 0.0f) {
                            D_801093A0_205A00_AbandonShip[obj->work[0]] = 0.0f;
                        }
                        if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
                            D_80109560_205BC0_AbandonShip[obj->work[0]]++;
                        }
                    } else {
                        obj->work[1] = 4;
                        D_80109560_205BC0_AbandonShip[obj->work[0]] = 0;
                    }
                    goto drop;
                } else if (obj->work[1] == 4) {
                    D_80109580_205BE0_AbandonShip.x = obj->trans.x;
                    D_80109580_205BE0_AbandonShip.y = obj->trans.y;
                    D_80109580_205BE0_AbandonShip.z = obj->trans.z;
                    if (obj->work[0] == 0) {
                        D_80109568_205BC8_AbandonShip[0].x = -900.0f;
                    } else if (obj->work[0] == 1) {
                        D_80109568_205BC8_AbandonShip[1].x = 900.0f;
                    }
                    D_80109568_205BC8_AbandonShip[obj->work[0]].y = -100.0f;
                    D_80109568_205BC8_AbandonShip[obj->work[0]].z = 900.0f;
                    func_80108DF0_205450_AbandonShip(&D_8010958C_205BEC_AbandonShip, &D_80109580_205BE0_AbandonShip, &D_80109568_205BC8_AbandonShip[obj->work[0]]);
                    if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
                        dx = D_8010958C_205BEC_AbandonShip.x * 13.0f;
                        dz = D_8010958C_205BEC_AbandonShip.z * 13.0f;
                        obj->trans.x += dx;
                        obj->trans.z += dz;
                        D_80109544_205BA4_AbandonShip[obj->work[0]]->trans.x += dx;
                        D_80109544_205BA4_AbandonShip[obj->work[0]]->trans.z += dz;
                    }
                    if ((obj->work[0] == 0 && obj->trans.x <= -900.0f) ||
                        (obj->work[0] == 1 && obj->trans.x >= 900.0f)) {
                        obj->work[1] = 0;
                        D_80109544_205BA4_AbandonShip[obj->work[0]]->work[1] = 10;
                        D_801093A0_205A00_AbandonShip[obj->work[0]] = 1.0f;
                    }
                drop:
                    if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
                        D_80109544_205BA4_AbandonShip[obj->work[0]]->trans.y -= 10.0f;
                    }
                    if (D_80109544_205BA4_AbandonShip[obj->work[0]]->trans.y < obj->trans.y) {
                        D_80109544_205BA4_AbandonShip[obj->work[0]]->trans.y = obj->trans.y;
                    }
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_AbandonShip/1FEE60", func_80103070_1FF6D0_AbandonShip);
#endif

void func_801039B4_200014_AbandonShip(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        omAddObj(2, 2, 2, -1, func_80103A0C_20006C_AbandonShip);
    }
}

/* NON_MATCHING: retail keeps 0x80000 and 0x370000 in s2 and s1 for its later file numbers. */
#ifdef NON_MATCHING
void func_80103A0C_20006C_AbandonShip(omObjData* obj) {
    obj->func_ptr = func_80103BDC_20023C_AbandonShip;
    obj->work[0] = D_80109389_2059E9_AbandonShip;
    obj->work[1] = 0;
    obj->model[0] = func_80018A30_19630(0x800CB, 0x2BD);
    obj->scale.z = 1.0f;
    obj->scale.y = 1.0f;
    obj->scale.x = 1.0f;
    obj->rot.x = 90.0f;
    obj->rot.y = 270.0f;
    obj->rot.z = 180.0f;
    if (D_80109389_2059E9_AbandonShip == 0) {
        obj->trans.x = -20.0f;
    } else {
        obj->trans.x = 700.0f;
    }
    obj->trans.y = 0.0f;
    obj->trans.z = 100.0f;
    obj->model[1] = func_80018A30_19630(0x370008, 0x2BD);
    func_80029E80_2AA80(obj->model[1], 1, 2);
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z + 50.0f);
    func_800297E8_2A3E8(obj->model[1], 2.0f, 2.0f, 2.0f);
    func_80018CCC_198CC(obj, 0, 0x800CB);
    func_80029BF0_2A7F0(obj->model[0], (s16)func_80029E14_2AA14(obj->motion[0]), 0, 0x1E, 2);
    func_80029E80_2AA80(obj->model[0], 1, 2);
    D_80109389_2059E9_AbandonShip++;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_AbandonShip/1FEE60", func_80103A0C_20006C_AbandonShip);
#endif

void func_80103BDC_20023C_AbandonShip(omObjData* obj) {
    Vec2f pos;
    Vec2f scr;
    Vec world;
    omObjData** pp;
    f32 t;
    f32 x;
    f32 y;
    f32 dy;
    f32 dx;
    s32 i;

    if (D_801093C0_205A20_AbandonShip < 9) {
        if (D_801093C0_205A20_AbandonShip >= 5) {
            if (D_8010959C_205BFC_AbandonShip[obj->work[0]] < 4) {
                if (D_801093D8_205A38_AbandonShip <= D_801093A8_205A08_AbandonShip[D_8010959C_205BFC_AbandonShip[obj->work[0]]]) {
                    obj->work[1] = 1;
                    D_8010959C_205BFC_AbandonShip[obj->work[0]]++;
                }
            }
            if (obj->work[1] != 0) {
                t = D_80109598_205BF8_AbandonShip[obj->work[0]] / 30.0f;
                if (D_80109598_205BF8_AbandonShip[obj->work[0]] < 15 ||
                    (D_80109598_205BF8_AbandonShip[obj->work[0]] >= 30 && D_80109598_205BF8_AbandonShip[obj->work[0]] < 45)) {
                    func_80029E80_2AA80(obj->model[1], 1, 2);
                    func_800298A4_2A4A4(obj->model[1], 4, 0);
                } else {
                    func_80029E80_2AA80(obj->model[1], 1, 1);
                    func_800298A4_2A4A4(obj->model[1], 4, 4);
                    func_80029C74_2A874(obj->model[1], 0);
                }
                y = D_801093D4_205A34_AbandonShip / 2.0f + 0.0f;
                if (D_80109598_205BF8_AbandonShip[obj->work[0]] == 0) {
                    if (AS_SIDE[obj->work[0]] == 0) {
                        if (obj->work[0] == 0) {
                            x = -20.0f;
                        } else {
                            x = 700.0f;
                        }
                    } else {
                        if (obj->work[0] == 0) {
                            x = -720.0f;
                        } else {
                            x = 0.0f;
                        }
                    }
                    func_80029714_2A314(obj->model[1], x, y, obj->trans.z + 50.0f);
                } else if (D_80109598_205BF8_AbandonShip[obj->work[0]] == 30) {
                    if (AS_SIDE[obj->work[0]] == 0) {
                        if (obj->work[0] == 0) {
                            x = -820.0f;
                        } else {
                            x = -100.0f;
                        }
                    } else {
                        if (obj->work[0] == 0) {
                            x = 80.0f;
                        } else {
                            x = 800.0f;
                        }
                    }
                    func_80029714_2A314(obj->model[1], x, y, obj->trans.z + 50.0f);
                }
                if (D_80109598_205BF8_AbandonShip[obj->work[0]] >= 55) {
                    D_80109598_205BF8_AbandonShip[obj->work[0]] = 0;
                    if (AS_SIDE[obj->work[0]] == 0) {
                        obj->rot.x = 90.0f;
                        obj->rot.y = 90.0f;
                        obj->rot.z = 180.0f;
                        if (obj->work[0] == 0) {
                            obj->trans.x = -720.0f;
                        } else {
                            obj->trans.x = 0.0f;
                        }
                    } else {
                        obj->rot.x = 90.0f;
                        obj->rot.y = 270.0f;
                        obj->rot.z = 180.0f;
                        if (obj->work[0] == 0) {
                            obj->trans.x = -20.0f;
                        } else {
                            obj->trans.x = 700.0f;
                        }
                    }
                    obj->trans.y = 0.0f;
                    func_800298A4_2A4A4(obj->model[0], 4, 4);
                    obj->work[1] = 0;
                    AS_SIDE[obj->work[0]] ^= 1;
                } else {
                    if (D_80109598_205BF8_AbandonShip[obj->work[0]] < 31) {
                        if (AS_REST[obj->work[0]] == 0) {
                            if (AS_SIDE[obj->work[0]] == 0) {
                                obj->trans.x -= 23.333334f;
                                obj->rot.z = t * 180.0f + 180.0f;
                            } else {
                                obj->trans.x += 23.333334f;
                                obj->rot.z = 180.0f - t * 180.0f;
                            }
                            obj->trans.y = HuMathSin(t * 180.0f) * 750.0f + 0.0f;
                        }
                        func_800298A4_2A4A4(obj->model[0], 4, 0);
                    } else {
                        if (AS_SIDE[obj->work[0]] == 0) {
                            obj->trans.x -= 10.0f;
                        } else {
                            obj->trans.x += 10.0f;
                        }
                        obj->trans.y -= 30.0f;
                    }
                    if (D_80109598_205BF8_AbandonShip[obj->work[0]] == 1) {
                        AS_REST[obj->work[0]]++;
                        if (AS_REST[obj->work[0]] >= 9) {
                            AS_REST[obj->work[0]] = 0;
                            if (obj->work[0] == 0) {
                                PlaySound(0x282);
                            }
                        }
                    }
                    if (AS_REST[obj->work[0]] == 0) {
                        D_80109598_205BF8_AbandonShip[obj->work[0]]++;
                    }
                }
                for (i = 0; i < 4; i++) {
                    if (D_800FFFD8_100BD8[i]->work[1] < 7) {
                        if (AS_SIDE[obj->work[0]] == 0) {
                            pos.unk_00 = obj->trans.x - HuMathSin(obj->rot.z + 45.0f) * 100.0f;
                            pos.unk_04 = func_800B7890_B8490(obj->rot.z + 45.0f) * 100.0f + obj->trans.y;
                        } else {
                            pos.unk_00 = obj->trans.x - HuMathSin(obj->rot.z - 45.0f) * 100.0f;
                            pos.unk_04 = func_800B7890_B8490(obj->rot.z - 45.0f) * 100.0f + obj->trans.y;
                        }
                        pp = &D_800FFFD8_100BD8[i];
                        dx = (*pp)->trans.x + 50.0f - pos.unk_00;
                        dy = (*pp)->trans.y + 50.0f - pos.unk_04;
                        if (func_800B1830_B2430(dx * dx + dy * dy) < 170.0f) {
                            world.x = obj->trans.x;
                            world.y = obj->trans.y;
                            world.z = obj->trans.z;
                            Hu3DCam3DToScreen(0, &world, &scr);
                            if (scr.unk_04 < 100.0f) {
                                if ((*pp)->work[3] != 2) {
                                    func_800797DC_7A3DC(0x111, i);
                                }
                                D_800FFFD8_100BD8[i]->work[3] = 2;
                            }
                        }
                    }
                }
            }
        }
    }
}

void func_80104350_2009B0_AbandonShip(void) {
    s32 i;

    D_801095D4_205C34_AbandonShip = func_80018A30_19630(0x370003, 0x2AD);
    D_801095D6_205C36_AbandonShip = func_80018A30_19630(0x370006, 0x2AD);
    func_8000C018_CC18(D_800F8FE0_F9BE0);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(1, 6, 0, -1, func_80105754_201DB4_AbandonShip);
    omSetStatBit(D_800FC7B0_FD3B0[0], 0xA0);
    omAddObj(1, 0, 0, -1, func_801044E0_200B40_AbandonShip);
    omAddObj(1, 1, 0, -1, func_80105508_201B68_AbandonShip);
    omSetStatBit(omAddObj(1, 2, 0, -1, func_80104A8C_2010EC_AbandonShip), 0xA0);
    D_801096B0_205D10_AbandonShip = (rand8() * 3) >> 8;
    for (i = 0; i < 4; i++) {
        D_801096D8_205D38_AbandonShip[i] = omAddObj(1, 0xF, 0, -1, func_80105F38_202598_AbandonShip);
    }
}

void func_801044E0_200B40_AbandonShip(omObjData* obj) {
    Vec pos;
    Vec2f scr;

    obj->func_ptr = func_80104678_200CD8_AbandonShip;
    SprAttrSet(D_801095D8_205C38_AbandonShip = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x37000B), 0, 1), 0, 0x4000);
    pos.x = 0.0f;
    pos.y = 400.0f;
    pos.z = -7700.0f;
    Hu3DCam3DToScreen(0, &pos, &scr);
    espPosSet(D_801095D8_205C38_AbandonShip, scr.unk_00, scr.unk_04);
    SprAttrSet(D_801095DA_205C3A_AbandonShip = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x370009), 0, 1), 0, 0x4000);
    espPosSet(D_801095DA_205C3A_AbandonShip, 0x5A, 0x1E);
    func_8001A91C_1B51C(D_801095DA_205C3A_AbandonShip, 0.5f, 0.5f);
    SprAttrSet(D_801095DC_205C3C_AbandonShip = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x37000A), 0, 1), 0, 0x4000);
    espPosSet(D_801095DA_205C3A_AbandonShip, 0x50, 0x28); /* retail: not the new sprite */
    func_8001A91C_1B51C(D_801095DC_205C3C_AbandonShip, 0.5f, 0.5f);
}

void func_80104678_200CD8_AbandonShip(void) {
    Vec2f scr;

    if (D_801093C0_205A20_AbandonShip < 2) {
        if (D_801093C0_205A20_AbandonShip >= 0) {
            D_801095A4_205C04_AbandonShip.x = 0.0f;
            D_801095A4_205C04_AbandonShip.y = 400.0f;
            D_801095A4_205C04_AbandonShip.z = -7700.0f;
            goto cam;
        }
    }
    if (D_80109440_205AA0_AbandonShip == 0) {
        D_801095A4_205C04_AbandonShip.x = 0.0f;
        D_801095A4_205C04_AbandonShip.y = -200.0f;
        D_801095A4_205C04_AbandonShip.z = -7700.0f;
    } else {
        if (D_800FFFD8_100BD8[D_80109381_2059E1_AbandonShip]->work[0] == 0) {
            D_801095B0_205C10_AbandonShip.x = 750.0f;
        } else if (D_800FFFD8_100BD8[D_80109381_2059E1_AbandonShip]->work[0] == 3) {
            D_801095B0_205C10_AbandonShip.x = -750.0f;
        } else {
            D_801095B0_205C10_AbandonShip.x = 0.0f;
        }
        D_801095B0_205C10_AbandonShip.y = -900.0f - D_800FFFD8_100BD8[D_80109381_2059E1_AbandonShip]->trans.y * 2.9f;
        D_801095B0_205C10_AbandonShip.z = -18000.0f;
        func_80108DF0_205450_AbandonShip(&D_801095BC_205C1C_AbandonShip, &D_801095A4_205C04_AbandonShip, &D_801095B0_205C10_AbandonShip);
        D_801095A4_205C04_AbandonShip.x += D_801095BC_205C1C_AbandonShip.x * 200.0f;
        if (D_800FFFD8_100BD8[D_80109381_2059E1_AbandonShip]->work[0] == 0) {
            if (D_801095B0_205C10_AbandonShip.x < D_801095A4_205C04_AbandonShip.x) {
                D_801095A4_205C04_AbandonShip.x = D_801095B0_205C10_AbandonShip.x;
            }
        } else if (D_800FFFD8_100BD8[D_80109381_2059E1_AbandonShip]->work[0] == 3) {
            if (D_801095A4_205C04_AbandonShip.x < D_801095B0_205C10_AbandonShip.x) {
                D_801095A4_205C04_AbandonShip.x = D_801095B0_205C10_AbandonShip.x;
            }
        }
        D_801095A4_205C04_AbandonShip.y += D_801095BC_205C1C_AbandonShip.y * 200.0f;
        if (D_801095A4_205C04_AbandonShip.y < D_801095B0_205C10_AbandonShip.y) {
            D_801095A4_205C04_AbandonShip.y = D_801095B0_205C10_AbandonShip.y;
        }
        D_801095A4_205C04_AbandonShip.z += D_801095BC_205C1C_AbandonShip.z * 200.0f;
        if (D_801095A4_205C04_AbandonShip.z < D_801095B0_205C10_AbandonShip.z) {
            D_801095A4_205C04_AbandonShip.z = D_801095B0_205C10_AbandonShip.z;
        }
    }
cam:
    Hu3DCam3DToScreen(0, &D_801095A4_205C04_AbandonShip, &scr);
    espPosSet(D_801095D8_205C38_AbandonShip, scr.unk_00, scr.unk_04);
    espPosSet(D_801095DA_205C3A_AbandonShip, HuMathSin(D_801095A0_205C00_AbandonShip) * 15.0f + 90.0f, 0x1E);
    espPosSet(D_801095DC_205C3C_AbandonShip, 80.0f - HuMathSin(D_801095A0_205C00_AbandonShip) * 15.0f, 0x28);
    D_801095A0_205C00_AbandonShip += 1.0f;
    if (D_801095A0_205C00_AbandonShip >= 180.0f) {
        D_801095A0_205C00_AbandonShip = 0.0f;
    }
}

void func_80104A8C_2010EC_AbandonShip(omObjData* obj) {
    obj->func_ptr = func_80104B54_2011B4_AbandonShip;
    obj->model[0] = func_80018A30_19630(0x370004, 0x2A9);
    obj->scale.x = 1.5f;
    obj->scale.z = 1.0f;
    obj->scale.y = 1.0f;
    obj->trans.x = 100.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 0.0f;
    obj->model[1] = func_80018A30_19630(0x370005, 0x2B9);
    func_80029714_2A314(obj->model[1], 600.0f, 0.0f, -200.0f);
    func_8002A00C_2AC0C(obj->model[0]);
    func_80104C5C_2012BC_AbandonShip(obj->model[0]);
}

void func_80104B54_2011B4_AbandonShip(omObjData* obj) {
    func_801050B8_201718_AbandonShip(obj->model[0], D_8010941C_205A7C_AbandonShip % 361, obj->model);
    if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        D_8010941C_205A7C_AbandonShip++;
        D_80109420_205A80_AbandonShip += 0.3f;
        D_80109424_205A84_AbandonShip += 0.3f;
    }
    if (D_801093C0_205A20_AbandonShip == 2) {
        obj->trans.y = 0.0f;
        func_800298A4_2A4A4(obj->model[1], 4, 4);
    }
}

void func_80104C5C_2012BC_AbandonShip(s16 model) {
    s16 xs[32];
    s16 zs[32];
    HmfData* m;
    HmfVtx* v;
    s16 nz;
    s16 nx;
    s16 i;
    s16 j;
    s16 n;

    m = D_800FC834_FD434[model].hmf;
    v = m->unk40;
    nz = 0;
    nx = 0;
    i = 0;
    n = m->unk18;
    for (i = 0; i < n; i++, v++) {
        for (j = 0; j < nx; j++) {
            if (xs[j] == v->unk00) {
                break;
            }
        }
        if (j >= nx) {
            xs[nx] = v->unk00;
            nx++;
        }
        for (j = 0; j < nz; j++) {
            if (zs[j] == v->unk04) {
                break;
            }
        }
        if (j >= nz) {
            zs[nz] = v->unk04;
            nz++;
        }
    }
    func_8010547C_201ADC_AbandonShip(xs, nx);
    func_8010547C_201ADC_AbandonShip(zs, nz);
    D_801095E0_205C40_AbandonShip = func_80027154_27D54(n * 6, 0x7918);
    for (i = 0; i < n; i++) {
        D_801095E0_205C40_AbandonShip[i].move = 1;
    }
    v = m->unk40;
    for (i = 0; i < n; i++, v++) {
        for (j = 0; j < nx; j++) {
            if (xs[j] == v->unk00) {
                break;
            }
        }
        if (j >= nx) {
            j = nx - 1;
        }
        D_801095E0_205C40_AbandonShip[i].col = j;
        if (j == 0 || j == nx - 1) {
            D_801095E0_205C40_AbandonShip[i].move = 0;
        }
    }
    v = m->unk40;
    for (i = 0; i < n; i++, v++) {
        for (j = 0; j < nz; j++) {
            if (zs[j] == v->unk04) {
                break;
            }
        }
        if (j >= nz) {
            j = nz - 1;
        }
        D_801095E0_205C40_AbandonShip[i].row = j;
        if (j == 0 || j == nz - 1) {
            D_801095E0_205C40_AbandonShip[i].move = 0;
        }
    }
    D_801095E4_205C44_AbandonShip[0] = abs(xs[0] - xs[1]);
    D_801095E4_205C44_AbandonShip[1] = abs(zs[0] - zs[1]);
}

void func_801050B8_201718_AbandonShip(s16 model, s32 angle, s16* unused) {
    HmfData* m;
    ASFlagVtx* map;
    HmfVtx* src;
    HmfVtx* dst;
    u16 n;
    s16 phase;
    u16 i;
    f32 a;
    f32 s1;
    f32 s2;
    f32 ax;
    f32 ay;
    f32 d;
    s32 pad[4];

    phase = 0;
    m = D_800FC834_FD434[model].hmf;
    map = D_801095E0_205C40_AbandonShip;
    src = m->unk40;
    dst = m->unk44[D_800FDBE0_FE7E0];
    n = m->unk18;
    a = angle;
    s1 = HuMathSin(a);
    s2 = HuMathSin(angle * 2);
    HuMathSin(a);
    ax = (f32)((u32)D_801095E4_205C44_AbandonShip[0] / 6) * D_800FC834_FD434[model].scale.x;
    ay = (f32)((u32)D_801095E4_205C44_AbandonShip[0] / 10) * D_800FC834_FD434[model].scale.y;
    if (angle == 0) {
        phase++;
    }
    for (i = 0; i < n; src++, dst++, i++, map++) {
        if (map->move != 0) {
            d = s1 * ax;
            if (map->row & 1) {
                dst->unk00 = src->unk00 + d;
            } else {
                dst->unk00 = src->unk00 - d;
            }
            if (phase & 1) {
                if ((map->col & 1) && (map->row & 1)) {
                    dst->unk02 = src->unk02 + s2 * ay;
                } else if ((map->col + map->row) & 1) {
                    dst->unk02 = src->unk02 - s2 * ay;
                } else {
                    dst->unk02 = src->unk02;
                }
            } else {
                if (!(map->col & 1) && !(map->row & 1)) {
                    dst->unk02 = src->unk02 + s2 * ay;
                } else if ((map->col & 1) && (map->row & 1)) {
                    dst->unk02 = src->unk02 - s2 * ay;
                } else {
                    dst->unk02 = src->unk02;
                }
            }
            if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
                D_801093D4_205A34_AbandonShip = dst->unk02;
            }
        } else {
            dst->unk00 = src->unk00;
            dst->unk02 = src->unk02;
            dst->unk04 = src->unk04;
        }
    }
}

void func_8010547C_201ADC_AbandonShip(s16* a, u16 n) {
    s32 i;
    s32 j;
    s16 t;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

void func_80105508_201B68_AbandonShip(omObjData* obj) {
    obj->func_ptr = func_801055EC_201C4C_AbandonShip;
    obj->model[0] = func_80018A30_19630(0x370000, 0x2B9);
    obj->scale.z = 1.0f;
    obj->scale.y = 1.0f;
    obj->scale.x = 1.0f;
    obj->trans.x = -1000.0f;
    obj->trans.y = -120.0f;
    obj->trans.z = -500.0f;
}

void func_80105590_201BF0_AbandonShip(s8* flag) {
    if (*flag == 0) {
        D_80102750_103350[0] += 20.0f;
    } else {
        D_80102750_103350[0] -= 20.0f;
    }
    *flag ^= 1;
}

void func_801055EC_201C4C_AbandonShip(omObjData* obj) {
    switch (D_801093C0_205A20_AbandonShip) {
    case 0:
        obj->trans.x += 10.0f;
        if (obj->trans.x > -150.0f) {
            obj->trans.x = -150.0f;
            D_801093C0_205A20_AbandonShip = 1;
        }
        obj->trans.y = D_801093D4_205A34_AbandonShip + -120.0f;
        break;
    case 1:
        if (D_801095C8_205C28_AbandonShip >= 11) {
            func_800298A4_2A4A4(obj->model[0], 4, 4);
            D_801093C0_205A20_AbandonShip = 2;
        } else if (D_801095C8_205C28_AbandonShip == 0) {
            PlaySound(0x27D);
        }
        func_80105590_201BF0_AbandonShip(&D_80109428_205A88_AbandonShip);
        D_801095C8_205C28_AbandonShip++;
        break;
    case 2:
        D_800FD474_FE074.x = -20.0f;
        D_80102750_103350[0] = 250.0f;
        D_801093C0_205A20_AbandonShip = 3;
        D_801095C8_205C28_AbandonShip = 0;
        PlaySound(0x280);
        PlayMusic(0x1E);
        break;
    case 3:
        func_80105590_201BF0_AbandonShip(&D_80109428_205A88_AbandonShip);
        break;
    case 4:
    case 5:
        break;
    }
}

void func_80105754_201DB4_AbandonShip(omObjData* obj) {
    GroundWork* w;
    s32 i;
    s32 j;
    s32 dir = 0x370000;
    s32 attr = 0x2B9;

    w = func_80027154_27D54(0xB4, 0x7918);
    obj->unk_50 = w;
    func_800B0EF0_B1AF0(w, 0, 0xB4);
    w->unk_03 = 1;
    w->unk_04 = 0;
    func_8000BEF8_CAF8(obj, 2, 5.0f);
    obj->func_ptr = func_80105A9C_2020FC_AbandonShip;
    obj->model[0] = func_80018A30_19630(0x370007, 0x2BD);
    obj->scale.z = 1.0f;
    obj->scale.y = 1.0f;
    obj->scale.x = 1.0f;
    obj->trans.x = 0.0f;
    obj->trans.y = 5.0f;
    obj->trans.z = 0.0f;
    j = 1;
    for (i = 0; i <= 0; i++) {
        obj->model[j] = func_80018A30_19630(dir | 2, (u16)(attr | 4));
        func_80029714_2A314(obj->model[j], obj->trans.x - 650.0f, obj->trans.y + 40.0f, obj->trans.z + 30.0f);
        func_8002979C_2A39C(obj->model[j], 0.0f, 90.0f, 0.0f);
        j++;
    }
    for (i = 0; i < 4; i++) {
        obj->model[j] = func_80018A30_19630(dir | 1, attr | 4);
        if (i == 0) {
            func_80029714_2A314(obj->model[j], obj->trans.x + 580.0f + 180.0f, obj->trans.y, obj->trans.z - 280.0f);
        } else if (i == 3) {
            D_801095EC_205C4C_AbandonShip.x = obj->trans.x + 1000.0f;
            D_801095EC_205C4C_AbandonShip.y = obj->trans.y + 200.0f;
            D_801095EC_205C4C_AbandonShip.z = obj->trans.z + 500.0f;
            func_80029714_2A314(obj->model[j], D_801095EC_205C4C_AbandonShip.x, D_801095EC_205C4C_AbandonShip.y, D_801095EC_205C4C_AbandonShip.z);
            func_8002979C_2A39C(obj->model[j], 90.0f, 0.0f, 0.0f);
        } else {
            func_80029714_2A314(obj->model[j], obj->trans.x + 580.0f + i * 120.0f, obj->trans.y, obj->trans.z - 400.0f);
        }
        j++;
    }
}

void func_80105A9C_2020FC_AbandonShip(omObjData* obj) {
    s32 i;

    switch (D_801093C0_205A20_AbandonShip) {
    case 1:
        break;
    case 2:
        for (i = 0; i < 6; i++) {
            func_800298A4_2A4A4(obj->model[i], 4, 0);
        }
        PlaySound(0x27E);
        break;
    case 3:
        if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
            D_801095EC_205C4C_AbandonShip.x -= 30.0f;
            D_8010942C_205A8C_AbandonShip += 20.0f;
        }
        func_80029714_2A314(obj->model[5], D_801095EC_205C4C_AbandonShip.x, D_801095EC_205C4C_AbandonShip.y, D_801095EC_205C4C_AbandonShip.z);
        func_8002979C_2A39C(obj->model[5], 90.0f, 0.0f, D_8010942C_205A8C_AbandonShip);
        if (D_801095EC_205C4C_AbandonShip.x < -800.0f) {
            D_801093C0_205A20_AbandonShip = 4;
        }
        break;
    case 4:
        func_800298A4_2A4A4(obj->model[5], 4, 4);
        break;
    case 5:
        func_80105C88_2022E8_AbandonShip(obj);
        if (D_80109430_205A90_AbandonShip == 0 && obj->trans.y < -45.0f) {
            PlaySound(0x27F);
            D_80109430_205A90_AbandonShip = 1;
        }
        break;
    case 6:
    case 7:
        if (D_80109380_2059E0_AbandonShip == 0) {
            func_80105C88_2022E8_AbandonShip(obj);
        }
        break;
    }
}

void func_80105C88_2022E8_AbandonShip(omObjData* obj) {
    s32 i;
    s32 j;
    s32 t;

    t = func_80078EA8_79AA8() + D_80102720_103320;
    j = 1;
    if (t == 0) {
        obj->trans.y -= 7.5f;
    }
    for (i = 0; i <= 0; i++) {
        func_80029714_2A314(obj->model[j], obj->trans.x - 650.0f, obj->trans.y + 40.0f, obj->trans.z + 30.0f);
        j++;
    }
    for (i = 0; i < 4; i++) {
        if (i == 0) {
            func_80029714_2A314(obj->model[j], obj->trans.x + 580.0f + 180.0f, obj->trans.y, obj->trans.z - 280.0f);
        } else if (i == 3) {
            D_801095EC_205C4C_AbandonShip.x = obj->trans.x + 1000.0f;
            D_801095EC_205C4C_AbandonShip.y = obj->trans.y + 200.0f;
            D_801095EC_205C4C_AbandonShip.z = obj->trans.z + 500.0f;
            func_80029714_2A314(obj->model[j], D_801095EC_205C4C_AbandonShip.x, D_801095EC_205C4C_AbandonShip.y, D_801095EC_205C4C_AbandonShip.z);
        } else {
            func_80029714_2A314(obj->model[j], obj->trans.x + 580.0f + i * 120.0f, obj->trans.y, obj->trans.z - 400.0f);
        }
        j++;
    }
}

void func_80105EC8_202528_AbandonShip(ASMastWork* w) {
    w->unk_7C = 0;
    w->unk_78 = 0;
    w->unk_3C = 0;
    w->unk_54 = 0;
    w->unk_44 = 0.1f;
    w->unk_48 = 30.0f;
    w->unk_34 = 500.0f;
    w->unk_40 = D_800BF7C8_C03C8;
    w->unk_38 = 0.0f;
    w->unk_4C = 0.5f;
    w->unk_50 = 0;
    w->unk_74 = 0.5f;
}

/* NON_MATCHING: same logic; retail hoists two table bases and reloads 100.0f in the coin loop. */
#ifdef NON_MATCHING
void func_80105F38_202598_AbandonShip(omObjData* obj) {
    ASMastWork* w;
    s8* rung;
    s8* tbl;
    u16* spr;
    f32 y;
    s32 i;
    s32 j;
    s32 idx;
    s32 attr = 0x2A9;

    obj->unk_50 = func_80027154_27D54(0xAC, 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, 0xAC);
    w = obj->unk_50;
    func_80105EC8_202528_AbandonShip(w);
    obj->func_ptr = func_8010642C_202A8C_AbandonShip;
    j = 1;
    obj->model[0] = func_80027D3C_2893C(D_801095D4_205C34_AbandonShip);
    obj->scale.z = 1.0f;
    obj->scale.y = 1.0f;
    obj->scale.x = 1.0f;
    obj->trans.x = D_801093C4_205A24_AbandonShip[D_801095D2_205C32_AbandonShip];
    obj->trans.y = 5.0f;
    obj->trans.z = 0.0f;
    obj->work[0] = D_801095D2_205C32_AbandonShip;
    for (i = 0; i < 8; i++) {
        obj->model[j] = func_80027D3C_2893C(D_801095D6_205C36_AbandonShip);
        y = D_801096B8_205D18_AbandonShip[i] = D_80109404_205A64_AbandonShip[D_801096B0_205D10_AbandonShip][i] * 145;
        func_80029714_2A314(obj->model[j], obj->trans.x, y, obj->trans.z);
        if (D_801093DC_205A3C_AbandonShip[D_801096B0_205D10_AbandonShip][i] == 1) {
            func_800297E8_2A3E8(obj->model[j], -1.0f, 1.0f, 1.0f);
            func_8002C3A0_2CFA0(obj->model[j]);
            func_80029A8C_2A68C(obj->model[j]);
        }
        j++;
    }
    j = 9;
    for (i = 0, tbl = (s8*)D_801093F4_205A54_AbandonShip; i < 5; i++) {
        obj->model[j] = D_800F86D8_F92D8[(s16)func_80018D64_19964(0xE, (u16)attr, 8)].unk00;
        func_800297E8_2A3E8(obj->model[j], 2.0f, 2.0f, 2.0f);
        D_80109610_205C70_AbandonShip[D_801095D2_205C32_AbandonShip][i].y = D_801096B8_205D18_AbandonShip[*(rung = D_801096B0_205D10_AbandonShip * 5 + tbl + i)] - 100.0f;
        if (D_801093DC_205A3C_AbandonShip[D_801096B0_205D10_AbandonShip][*rung] == 0) {
            D_80109610_205C70_AbandonShip[D_801095D2_205C32_AbandonShip][i].x = obj->trans.x - 80.0f;
        } else {
            D_80109610_205C70_AbandonShip[D_801095D2_205C32_AbandonShip][i].x = obj->trans.x + 80.0f;
        }
        func_80029714_2A314(obj->model[j], D_80109610_205C70_AbandonShip[D_801095D2_205C32_AbandonShip][i].x, D_80109610_205C70_AbandonShip[D_801095D2_205C32_AbandonShip][i].y, obj->trans.z);
        j++;
    }
    idx = (s16)func_80018D64_19964(0x14, (u16)attr, 8);
    obj->model[14] = D_800F86D8_F92D8[idx].unk00;
    func_800298A4_2A4A4(obj->model[14], 4, 4);
    HmfModelObjAttrSet(obj->model[14], 0x70000000, 0x70000000);
    func_800297E8_2A3E8(obj->model[14], 4.0f, 4.0f, 4.0f);
    func_80029714_2A314(obj->model[14], obj->trans.x, obj->trans.y, obj->trans.z);
    w->unk_21 = idx;
    func_80021250_21E50(w->unk_21, 0xFF, 0xFF, 0xBE);
    func_800211E8_21DE8(w->unk_21, 0xF0);
    spr = &D_801095F8_205C58_AbandonShip[D_801095D2_205C32_AbandonShip];
    *spr = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x37000C), 0, 1);
    func_8001A91C_1B51C(*spr, 1.0f, 1.0f);
    espDispOff(D_801095F8_205C58_AbandonShip[D_801095D2_205C32_AbandonShip]);
    D_801095D2_205C32_AbandonShip++;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_AbandonShip/1FEE60", func_80105F38_202598_AbandonShip);
#endif

/* NON_MATCHING: same code shape; retail keeps the coin's model slot in a saved register (register allocation only). */
#ifdef NON_MATCHING
void func_8010642C_202A8C_AbandonShip(omObjData* obj) {
    omObjData* p;
    omObjData* q;
    s32 k;
    ASMastWork* w;
    MgWork* m;
    s32 i;
    s32 j;

    switch (D_801093C0_205A20_AbandonShip) {
    case 3:
        for (i = 0; i < 9; i++) {
            func_800298A4_2A4A4(obj->model[i], 4, 0);
        }
        for (i = 0; i < 4; i++) {
            q = D_800FFFD8_100BD8[i];
            if (q->work[0] == obj->work[0]) {
                m = q->unk_50;
                obj->work[1] = m->unk_59;
            }
        }
        break;
    case 5:
        func_801068F8_202F58_AbandonShip(obj);
        D_801093D8_205A38_AbandonShip = obj->trans.y;
        p = D_800FFFD8_100BD8[obj->work[1]];
        if (p->work[0] == obj->work[0] && p->work[1] < 7) {
            j = 9;
            k = 14;
            for (i = 0; i < 5; i++, j++) {
                if (ABSDIFF(p->trans.x - D_80109610_205C70_AbandonShip[obj->work[0]][i].x) <= 70.0f &&
                    ABSDIFF(p->trans.y + 60.0f - D_80109610_205C70_AbandonShip[obj->work[0]][i].y) <= 70.0f) {
                    func_800298A4_2A4A4(obj->model[j], 4, 4);
                    if (i >= D_801095CE_205C2E_AbandonShip[obj->work[0]]) {
                        D_801095CE_205C2E_AbandonShip[obj->work[0]]++;
                        D_801095CA_205C2A_AbandonShip[obj->work[0]] = 1;
                    }
                    func_800298A4_2A4A4(obj->model[k], 4, 0);
                    func_80029714_2A314(obj->model[k], D_80109610_205C70_AbandonShip[obj->work[0]][i].x, D_80109610_205C70_AbandonShip[obj->work[0]][i].y, obj->trans.z + 100.0f);
                    break;
                }
            }
            w = obj->unk_50;
            if (D_801095CA_205C2A_AbandonShip[obj->work[0]] == 1) {
                if (w->unk_78 == 0) {
                    m = p->unk_50;
                    gPlayers[m->unk_59].coins_mg++;
                    func_80079798_7A398(9, m->unk_59);
                }
                func_80021198_21D98(w->unk_21, w->unk_78 % 8);
                if (++w->unk_78 >= 8) {
                    w->unk_78 = 0;
                    D_801095CA_205C2A_AbandonShip[obj->work[0]] = 0;
                }
            }
        }
        if (obj->trans.y < -4400.0f) {
            D_801093C0_205A20_AbandonShip = 6;
        }
        break;
    case 6:
    case 7:
    case 8:
        espDispOff(D_801095F8_205C58_AbandonShip[obj->work[0]]);
        if (D_80109380_2059E0_AbandonShip != 2) {
            if (D_80109380_2059E0_AbandonShip == 0) {
                func_801068F8_202F58_AbandonShip(obj);
            } else if (D_801093C0_205A20_AbandonShip != 6) {
                p = D_800FFFD8_100BD8[obj->work[1]];
                if (p->work[0] == obj->work[0] && p->work[1] < 11) {
                    func_801068F8_202F58_AbandonShip(obj);
                }
            }
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_AbandonShip/1FEE60", func_8010642C_202A8C_AbandonShip);
#endif

/* NON_MATCHING: masked 0; one addu's operand order (the rope table base). */
#ifdef NON_MATCHING
void func_801068F8_202F58_AbandonShip(omObjData* obj) {
    Vec pos;
    Vec2f scr;
    s8* rung;
    s8* tbl;
    f32 y;
    s32 i;
    s32 j;

    obj->trans.y -= 7.5f;
    j = 1;
    for (i = 0; i < 8; i++) {
        y = D_801096B8_205D18_AbandonShip[i] = D_80109404_205A64_AbandonShip[D_801096B0_205D10_AbandonShip][i] * 145 + obj->trans.y;
        func_80029714_2A314(obj->model[j], obj->trans.x, y, obj->trans.z);
        j++;
    }
    j = 9;
    for (i = 0, tbl = (s8*)D_801093F4_205A54_AbandonShip; i < 5; i++) {
        D_80109610_205C70_AbandonShip[obj->work[0]][i].y = D_801096B8_205D18_AbandonShip[*(rung = D_801096B0_205D10_AbandonShip * 5 + tbl + i)] - 100.0f;
        if (D_801093DC_205A3C_AbandonShip[D_801096B0_205D10_AbandonShip][*rung] == 0) {
            D_80109610_205C70_AbandonShip[obj->work[0]][i].x = obj->trans.x - 100.0f;
            func_80029714_2A314(obj->model[j], D_80109610_205C70_AbandonShip[obj->work[0]][i].x, D_80109610_205C70_AbandonShip[obj->work[0]][i].y, obj->trans.z);
        } else {
            D_80109610_205C70_AbandonShip[obj->work[0]][i].x = obj->trans.x + 100.0f;
            func_80029714_2A314(obj->model[j], D_80109610_205C70_AbandonShip[obj->work[0]][i].x, D_80109610_205C70_AbandonShip[obj->work[0]][i].y, obj->trans.z);
        }
        j++;
    }
    if (obj->trans.y > -4475.0f) {
        pos.x = obj->trans.x;
        pos.y = D_801093D4_205A34_AbandonShip / 2.0f + 50.0f;
        pos.z = obj->trans.z;
        Hu3DCam3DToScreen(0, &pos, &scr);
        espPosSet(D_801095F8_205C58_AbandonShip[obj->work[0]], scr.unk_00, scr.unk_04);
        espDispOn(D_801095F8_205C58_AbandonShip[obj->work[0]]);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_AbandonShip/1FEE60", func_801068F8_202F58_AbandonShip);
#endif

/* .data (0x2059E0-0x205B30, 80109380-801094D0) */
s8 D_80109380_2059E0_AbandonShip = 0;
s8 D_80109381_2059E1_AbandonShip = 0;
s32 D_80109384_2059E4_AbandonShip = 31;
s8 D_80109388_2059E8_AbandonShip = 0;
s32 D_8010938C_2059EC_AbandonShip = 0;
u32 D_80109390_2059F0_AbandonShip = 0;
s32 D_80109394_2059F4_AbandonShip = 0;
s32 D_80109398_2059F8_AbandonShip = 0;
s8 D_8010939C_2059FC_AbandonShip = 0;
s8 D_8010939D_2059FD_AbandonShip = 0;
s8 D_8010939E_2059FE_AbandonShip = 0;
s8 D_8010939F_2059FF_AbandonShip = 0;
f32 D_801093A0_205A00_AbandonShip[2] = { 1.0f, 1.0f };
f32 D_801093A8_205A08_AbandonShip[6] = { -1050.0f, -1650.0f, -2200.0f, -3000.0f, 0.0f, 0.0f };
s8 D_801093C0_205A20_AbandonShip = 0;
f32 D_801093C4_205A24_AbandonShip[4] = { 540.0f, 180.0f, -180.0f, -540.0f };
f32 D_801093D4_205A34_AbandonShip = 0.0f;
f32 D_801093D8_205A38_AbandonShip = 0.0f;
s8 D_801093DC_205A3C_AbandonShip[3][8] = {
    { 0, 1, 0, 0, 1, 0, 0, 0 },
    { 1, 0, 1, 1, 0, 0, 0, 1 },
    { 0, 0, 1, 0, 1, 0, 1, 1 },
};
s8 D_801093F4_205A54_AbandonShip[3][5] = {
    { 1, 3, 4, 6, 7 },
    { 2, 4, 5, 6, 7 },
    { 1, 3, 5, 6, 7 },
};
s8 D_80109404_205A64_AbandonShip[3][8] = {
    { 0x09, 0x0D, 0x10, 0x13, 0x16, 0x19, 0x1B, 0x1D },
    { 0x09, 0x0C, 0x0F, 0x11, 0x14, 0x16, 0x18, 0x1D },
    { 0x09, 0x0B, 0x0E, 0x11, 0x15, 0x18, 0x1B, 0x1D },
};
u16 D_8010941C_205A7C_AbandonShip = 0;
f32 D_80109420_205A80_AbandonShip = 0.0f;
f32 D_80109424_205A84_AbandonShip = 0.0f;
s8 D_80109428_205A88_AbandonShip = 0;
f32 D_8010942C_205A8C_AbandonShip = 90.0f;
s8 D_80109430_205A90_AbandonShip = 0;
static s8 D_80109431_205A91_AbandonShip[15] = { 0 }; /* unused rest of the 16-byte slot */
s8 D_80109440_205AA0_AbandonShip = 0;
s16 D_80109442_205AA2_AbandonShip = 0;
s32 D_80109444_205AA4_AbandonShip[4] = { 0, 1, 2, 3 };
Vec D_80109454_205AB4_AbandonShip[4] = {
    { -300.0f, 330.0f, -470.0f },
    { -400.0f, 330.0f, -470.0f },
    { -500.0f, 330.0f, -470.0f },
    { -600.0f, 330.0f, -470.0f },
};
u8 D_80109484_205AE4_AbandonShip[24] = {
    0, 1, 2, 3, 1, 2, 3, 0, 2, 3, 0, 1, 3, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0,
};
s32 D_8010949C_205AFC_AbandonShip[4] = { 0 };
s8 D_801094AC_205B0C_AbandonShip[4] = { 0 };
s8 D_801094B0_205B10_AbandonShip[4] = { 0 };
f32 D_801094B4_205B14_AbandonShip[4] = { 0 };
s8 D_801094C4_205B24_AbandonShip = 0;
static s8 D_801094C5_205B25_AbandonShip[11] = { 0 }; /* unused rest of the 12-byte slot */
