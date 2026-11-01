#include "ovl_27.h"

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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_AbandonShip/1FEE60", func_80103BDC_20023C_AbandonShip);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_AbandonShip/1FEE60", func_80104350_2009B0_AbandonShip);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_AbandonShip/1FEE60", func_801044E0_200B40_AbandonShip);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_AbandonShip/1FEE60", func_80104678_200CD8_AbandonShip);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_AbandonShip/1FEE60", func_80104A8C_2010EC_AbandonShip);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_AbandonShip/1FEE60", func_80104B54_2011B4_AbandonShip);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_AbandonShip/1FEE60", func_80104C5C_2012BC_AbandonShip);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_AbandonShip/1FEE60", func_801050B8_201718_AbandonShip);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_AbandonShip/1FEE60", func_8010547C_201ADC_AbandonShip);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_AbandonShip/1FEE60", func_80105508_201B68_AbandonShip);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_AbandonShip/1FEE60", func_80105590_201BF0_AbandonShip);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_AbandonShip/1FEE60", func_801055EC_201C4C_AbandonShip);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_AbandonShip/1FEE60", func_80105754_201DB4_AbandonShip);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_AbandonShip/1FEE60", func_80105A9C_2020FC_AbandonShip);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_AbandonShip/1FEE60", func_80105C88_2022E8_AbandonShip);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_AbandonShip/1FEE60", func_80105EC8_202528_AbandonShip);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_AbandonShip/1FEE60", func_80105F38_202598_AbandonShip);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_AbandonShip/1FEE60", func_8010642C_202A8C_AbandonShip);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_AbandonShip/1FEE60", func_801068F8_202F58_AbandonShip);
