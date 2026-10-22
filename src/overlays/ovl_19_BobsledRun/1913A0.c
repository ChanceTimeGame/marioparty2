#include "ovl_19.h"


void func_80102800_1913A0_BobsledRun(void) {
    omObjData* obj;

    func_8002D4D0_2E0D0(50);
    func_8002F290_2FE90(D_800F9D30_FA930, 64);
    func_80020D20_21920(32);
    omInitObjMan(50, 0);
    func_80079128_79D28();
    func_8000C38C_CF8C();
    func_80018E30_19A30(2);
    func_80018F58_19B58(2);
    func_80029708_2A308(1);
    func_8002CA48_2D648(0, 0, 50);
    ScissorSet(0, 8.0f, 8.0f, 312.0f, 112.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 240.0f, 511.0f);
    Hu3DCamSetPerspective(0, D_8010C040_19ABE0_BobsledRun[0], 20.0f, 12000.0f);
    ScissorSet(1, 8.0f, 128.0f, 312.0f, 232.0f);
    ViewportSet(1, 640.0f, 480.0f, 511.0f, 640.0f, 720.0f, 511.0f);
    Hu3DCamSetPerspective(1, D_8010C040_19ABE0_BobsledRun[1], 20.0f, 12000.0f);
    D_800FA606_FB206 = 0;
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    func_8000C460_D060();
    func_8000C018_CC18(D_800F8FE0_F9BE0);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(1, 5, 0, -1, func_80103F24_192AC4_BobsledRun);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(1, 1, 0, -1, func_80104084_192C24_BobsledRun);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(1, 1, 0, -1, func_80104490_193030_BobsledRun);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(1, 1, 0, -1, func_80104578_193118_BobsledRun);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(1, 1, 0, -1, func_80104660_193200_BobsledRun);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(1, 1, 0, -1, func_80104748_1932E8_BobsledRun);

    func_8010562C_1941CC_BobsledRun();
    func_80105D30_1948D0_BobsledRun();
    func_80105CF0_194890_BobsledRun();
    func_80105F38_194AD8_BobsledRun(0xF6, 0x18);
    func_80105D88_194928_BobsledRun(0xF6, 0x24);
    func_801059F8_194598_BobsledRun(1, func_800680D4_68CD4(1));
    func_801059F8_194598_BobsledRun(0, D_8010C0DC_19AC7C_BobsledRun);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(2, 10, 60, -1, func_801051BC_193D5C_BobsledRun);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(2, 10, 60, -1, func_80105344_193EE4_BobsledRun);
    omAddObj(2, 10, 60, -1, func_801054D0_194070_BobsledRun);
    omAddObj(2, 10, 60, -1, func_8010557C_19411C_BobsledRun);
    obj = omAddObj(0x7FDA, 0, 0, -1, func_8010A840_1993E0_BobsledRun);
    obj->work[0] = 2;
    omSetStatBit(obj, 0xA0);
    D_800BF79C_C039C = 10.0f;
    D_800BF7A8_C03A8 = 0.06f;
    D_800BF7AC_C03AC = 5.0f;
    D_800BF7C0_C03C0 = 80.0f;
    func_8002C59C_2D19C(990, 997, 0, 0, 50);
    func_8002CD6C_2D96C(4);
    func_8007273C_7333C((u8*)"\x82\x71\x82\x64\x82\x60\x82\x63\x82\x78\x82\x66\x82\x6E\x82\x76\x82\x6B\x81\x49", 1);
    func_80026DAC_279AC(0, 128, 128, 176);
    func_80026DAC_279AC(1, 128, 128, 200);
    func_800794F0_7A0F0(0x7F);
    func_80079684_7A284(0x7F);
}

void func_80102D4C_1918EC_BobsledRun(void) {
    if (func_8008F618_90218() == 0) {
        omOvlReturnEx(1);
    }
}

/* Speed change from a bump against the other sled at (ox, oz). */
void func_80102D78_191918_BobsledRun(BRWork* work, f32 x, f32 z, f32 ox, f32 oz) {
    f32 dx;
    f32 dz;
    f32 s;
    f32 dist;
    f32 rot;

    dx = x - ox;
    dz = z - oz;
    dist = func_800B1830_B2430(dx * dx + dz * dz);
    rot = work->unk_3C;
    s = HuMathSin(rot);
    rot = func_8000DA2C_E62C(dx, dz, s, func_800B7890_B8490(rot));
    if (dist != 0.0f) {
        if (dist < work->unk_40 * 0.4f) {
            dist *= 0.05f;
        } else if (dist < work->unk_40 * 0.8f) {
            dist *= 0.1f;
        } else {
            dist *= 0.02f;
        }
        work->unk_40 = dist * rot + work->unk_40;
    }
}

/* The game controller (D_800FC7B0_FD3B0[0]): start, race, results. */
// the photo-finish branch: retail reads D_800FFFD8_100BD8[0]/[1] through a base register (&[0] / &[1], then [1] / [-1]); GCC folds the addresses (as in MP1)
#ifdef NON_MATCHING
void func_80102EE0_191A80_BobsledRun(omObjData* obj) {
    f32 x0;
    f32 x1;
    BRWork* w;
    omObjData* o;
    omObjData** p;
    f32 spd;
    s16 st0;
    s16 st1;
    s32 a;
    s32 b;

    if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        func_8000C3C8_CFC8();
        if (D_800F8FD0_F9BD0 == 1) {
            D_8010C0DC_19AC7C_BobsledRun += 2;
            if (D_8010C0DC_19AC7C_BobsledRun > 18000) {
                D_8010C0DC_19AC7C_BobsledRun = 18000;
            }
        }
        switch (D_800F8FD0_F9BD0) {
            case 0:
                if (D_8010C118_19ACB8_BobsledRun == 5) {
                    InitFadeIn(0, 16);
                }
                if (D_8010C118_19ACB8_BobsledRun >= 6) {
                    if (func_8008F618_90218() != 0) {
                        return;
                    }
                    if (D_8010C130_19ACD0_BobsledRun == 0) {
                        PlayMusic(0x24);
                        D_8010C130_19ACD0_BobsledRun++;
                    }
                    if (D_8010C118_19ACB8_BobsledRun == 30) {
                        func_800691FC_69DFC(15);
                    }
                    if (D_8010C118_19ACB8_BobsledRun > 80) {
                        func_8000C3B8_CFB8();
                    }
                }
                D_8010C118_19ACB8_BobsledRun++;
                break;
            case 1:
                st0 = D_8010C048_19ABE8_BobsledRun[0].state;
                st1 = D_8010C048_19ABE8_BobsledRun[1].state;
                if (D_8010C0DC_19AC7C_BobsledRun == 18000) {
                    D_8010BFF5_19AB95_BobsledRun = -3;
                    func_8000C398_CF98();
                } else if (D_8010BFF4_19AB94_BobsledRun == -1 && D_8010BFF5_19AB95_BobsledRun != -2) {
                    a = st0 == 2;
                    b = st1 == 2;
                    if (a | b) {
                        if (a & b) {
                            if (D_800FFFD8_100BD8[0]->trans.x < D_800FFFD8_100BD8[1]->trans.x) {
                                p = D_800FFFD8_100BD8;
                                w = p[0]->unk_50;
                                w->unk_40 = spd = D_800BF7C0_C03C0;
                                D_8010BFF4_19AB94_BobsledRun = w->unk_59;
                                o = p[1];
                            } else {
                                p = &D_800FFFD8_100BD8[1];
                                w = p[0]->unk_50;
                                w->unk_40 = spd = D_800BF7C0_C03C0;
                                D_8010BFF4_19AB94_BobsledRun = w->unk_59;
                                o = p[-1];
                            }
                            BR_WORK(o)->unk_40 = spd * 0.8f;
                        } else {
                            if (st0 == 2) {
                                o = D_800FFFD8_100BD8[0];
                            } else if (st1 == 2) {
                                o = D_800FFFD8_100BD8[1];
                            } else {
                                goto done;
                            }
                            w = o->unk_50;
                            w->unk_40 = D_800BF7C0_C03C0;
                            D_8010BFF4_19AB94_BobsledRun = w->unk_59;
                        }
                    done:
                        func_8000C398_CF98();
                    }
                    if (_CheckFlag(0xC) != 0 && D_8010C048_19ABE8_BobsledRun[0].state == 3) {
                        D_8010BFF4_19AB94_BobsledRun = BR_WORK(D_800FFFD8_100BD8[1])->unk_59;
                        func_8000C398_CF98();
                    }
                } else {
                    func_8000C398_CF98();
                }
                D_8010C11C_19ACBC_BobsledRun -= 2;
                break;
            case 2:
                if (D_8010C120_19ACC0_BobsledRun == 0) {
                    func_800794A8_7A0A8(60);
                    if (D_8010C0E0_19AC80_BobsledRun != -1) {
                        func_80079848_7A448((s16)D_8010C0E0_19AC80_BobsledRun);
                    }
                    if (D_8010C0E4_19AC84_BobsledRun != -1) {
                        func_80079848_7A448((s16)D_8010C0E4_19AC84_BobsledRun);
                    }
                    if (D_8010C048_19ABE8_BobsledRun[0].sound != -1) {
                        func_80079848_7A448(D_8010C048_19ABE8_BobsledRun[0].sound);
                    }
                    if (D_8010C048_19ABE8_BobsledRun[1].sound != -1) {
                        func_80079848_7A448(D_8010C048_19ABE8_BobsledRun[1].sound);
                    }
                    if (_CheckFlag(0xC) != 0) {
                        func_800691FC_69DFC(3);
                    } else if (D_8010BFF5_19AB95_BobsledRun == -2) {
                        func_800691FC_69DFC(3);
                    } else if (D_8010BFF5_19AB95_BobsledRun == -3) {
                        func_800691FC_69DFC(0x12);
                    } else {
                        func_800691FC_69DFC(0x14);
                    }
                }
                if (D_8010C128_19ACC8_BobsledRun == 0) {
                    if (func_80069538_6A138() == 0 || (func_80069538_6A138() & 2)) {
                        if (D_8010BFF5_19AB95_BobsledRun >= -1) {
                            gPlayers[D_8010C048_19ABE8_BobsledRun[D_8010BFF4_19AB94_BobsledRun].player[0]].coins_mg_bonus += 10;
                            gPlayers[D_8010C048_19ABE8_BobsledRun[D_8010BFF4_19AB94_BobsledRun].player[1]].coins_mg_bonus += 10;
                            if (func_800680D4_68CD4(1) > D_8010C0DC_19AC7C_BobsledRun) {
                                if (_CheckFlag(0xC) == 0 || D_8010C048_19ABE8_BobsledRun[0].state != 3) {
                                    GWMgRecordSet(1, D_8010C0DC_19AC7C_BobsledRun);
                                }
                            } else {
                                D_8010C12C_19ACCC_BobsledRun = 1;
                            }
                        } else {
                            D_8010C12C_19ACCC_BobsledRun = 2;
                            if (_CheckFlag(0xC) == 0) {
                                func_800691FC_69DFC(0x13);
                                D_8010C12C_19ACCC_BobsledRun = 3;
                                PlayMusic(0x57);
                            }
                        }
                        D_8010C128_19ACC8_BobsledRun++;
                    }
                } else {
                    if (_CheckFlag(0xC) != 0) {
                        if (D_8010C12C_19ACCC_BobsledRun == 0) {
                            if (D_8010C128_19ACC8_BobsledRun == 10) {
                                if (D_8010C048_19ABE8_BobsledRun[0].state != 3) {
                                    func_800691FC_69DFC(0xE);
                                }
                            }
                            if (D_8010C128_19ACC8_BobsledRun == 70) {
                                func_8000C3A8_CFA8();
                            }
                        } else if (D_8010C128_19ACC8_BobsledRun == 30) {
                            func_8000C3A8_CFA8();
                        }
                    } else {
                        switch (D_8010C12C_19ACCC_BobsledRun) {
                            case 0:
                                if (D_8010C128_19ACC8_BobsledRun == 30) {
                                    func_800691FC_69DFC(0xE);
                                }
                                if (D_8010C128_19ACC8_BobsledRun == 90) {
                                    func_800691FC_69DFC(0x11,
                                        gPlayers[D_8010C048_19ABE8_BobsledRun[D_8010BFF4_19AB94_BobsledRun].player[0]].character,
                                        gPlayers[D_8010C048_19ABE8_BobsledRun[D_8010BFF4_19AB94_BobsledRun].player[1]].character);
                                    PlayMusic(0x55);
                                }
                                if (D_8010C128_19ACC8_BobsledRun == 250) {
                                    func_8000C3A8_CFA8();
                                }
                                break;
                            case 1:
                                if (D_8010C128_19ACC8_BobsledRun == 30) {
                                    func_800691FC_69DFC(0x11,
                                        gPlayers[D_8010C048_19ABE8_BobsledRun[D_8010BFF4_19AB94_BobsledRun].player[0]].character,
                                        gPlayers[D_8010C048_19ABE8_BobsledRun[D_8010BFF4_19AB94_BobsledRun].player[1]].character);
                                    PlayMusic(0x52);
                                }
                                if (D_8010C128_19ACC8_BobsledRun == 195) {
                                    func_8000C3A8_CFA8();
                                }
                                break;
                            case 2:
                                if (D_8010C128_19ACC8_BobsledRun == 120) {
                                    func_8000C3A8_CFA8();
                                }
                                break;
                            case 3:
                                if (D_8010C128_19ACC8_BobsledRun == 120) {
                                    func_8000C3A8_CFA8();
                                }
                                break;
                        }
                    }
                    D_8010C128_19ACC8_BobsledRun++;
                }
                D_8010C120_19ACC0_BobsledRun += 2;
                break;
            case 3:
                InitFadeOut(0, 20);
                func_800794A8_7A0A8(40);
                func_80079614_7A214(40);
                obj->func_ptr = func_80102D4C_1918EC_BobsledRun;
                D_8010C124_19ACC4_BobsledRun += 2;
                break;
        }
    }
    x0 = D_8010C048_19ABE8_BobsledRun[0].progress * 262.0f + 20.0f;
    x1 = D_8010C048_19ABE8_BobsledRun[1].progress * 262.0f + 20.0f;
    espPosSet(D_8010CC3E_19B7DE_BobsledRun, x0 - 2.0f, 111);
    espPosSet(D_8010CB40_19B6E0_BobsledRun, x1 - 2.0f, 115);
    espPosSet(D_8010C048_19ABE8_BobsledRun[0].sprite, x0 - 2.0f, 97);
    espPosSet(D_8010C048_19ABE8_BobsledRun[1].sprite, x1 - 2.0f, 101);
    espPosSet(D_8010C048_19ABE8_BobsledRun[0].sprite2, x0 - 12.0f, 97);
    espPosSet(D_8010C048_19ABE8_BobsledRun[1].sprite2, x1 - 12.0f, 101);
    if (D_8010C048_19ABE8_BobsledRun[0].progress > D_8010C048_19ABE8_BobsledRun[1].progress) {
        D_8010C048_19ABE8_BobsledRun[0].path = 1;
        D_8010C048_19ABE8_BobsledRun[1].path = 0;
    } else {
        D_8010C048_19ABE8_BobsledRun[0].path = 0;
        D_8010C048_19ABE8_BobsledRun[1].path = 1;
    }
    func_801059F8_194598_BobsledRun(0, D_8010C0DC_19AC7C_BobsledRun);
    func_80105770_194310_BobsledRun();
    if (D_801011FC_101DFC == 1) {
        InitFadeOut(0, 20);
        func_800794A8_7A0A8(40);
        func_80079614_7A214(40);
        obj->func_ptr = func_80102D4C_1918EC_BobsledRun;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_80102EE0_191A80_BobsledRun);
#endif

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_801038C4_192464_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_80103B4C_1926EC_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_80103DDC_19297C_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_80103F24_192AC4_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_80104084_192C24_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_80104490_193030_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_80104578_193118_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_80104660_193200_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_80104748_1932E8_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_80104820_1933C0_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_80104BE0_193780_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_80104EAC_193A4C_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_801050F8_193C98_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_801051BC_193D5C_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_80105344_193EE4_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_801054D0_194070_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_8010557C_19411C_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_8010562C_1941CC_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_80105720_1942C0_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_80105770_194310_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_801059F8_194598_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_80105CF0_194890_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_80105D30_1948D0_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_80105D88_194928_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_80105F38_194AD8_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_801060E8_194C88_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_80106438_194FD8_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_801064F0_195090_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_80107550_1960F0_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_801075C8_196168_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_80107720_1962C0_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_801077A4_196344_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_80107920_1964C0_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_80107C6C_19680C_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_80107CF4_196894_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_80107E38_1969D8_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_80107EA4_196A44_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_8010982C_1983CC_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_80109D94_198934_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_80109F78_198B18_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_8010A3AC_198F4C_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_8010A648_1991E8_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_8010A840_1993E0_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_8010AB30_1996D0_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_8010AC18_1997B8_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_8010ADD8_199978_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_8010AF5C_199AFC_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_8010B630_19A1D0_BobsledRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_8010BD18_19A8B8_BobsledRun);
