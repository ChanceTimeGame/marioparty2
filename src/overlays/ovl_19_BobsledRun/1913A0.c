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

/* Bumping into the other sled: always returns 0. */
// the bump test's delay slots: retail fills both branch-likelies with mov.s (as in MP1)
#ifdef NON_MATCHING
s32 func_801038C4_192464_BobsledRun(omObjData* obj, f32 x, f32 y, f32 z) {
    BRWork* work;
    BRWork* ow;
    omObjData* o;
    f32 speed;
    f32 f;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 dx2;
    f32 dz2;
    f32 d2;
    f32 d;
    u16 i;

    work = obj->unk_50;
    speed = work->unk_40;
    if (work->unk_50 & 6) {
        speed *= 0.6f;
    }
    speed = speed * (work->unk_38 != 1000.0f ? work->unk_4C * work->unk_B4 : work->unk_B4);
    x += HuMathSin(work->unk_3C) * speed;
    z += func_800B7890_B8490(work->unk_3C) * speed;
    y += work->unk_48;
    for (i = 0; i < 2; i++) {
        o = D_800FFFD8_100BD8[i];
        ow = o->unk_50;
        if (work != ow) {
            dx = o->trans.x - (x + D_800F94A0_FA0A0);
            dy = (o->trans.y + ow->unk_48) - y;
            dz = o->trans.z - (z + D_80101308_101F08);
            dx2 = dx * dx;
            dz2 = dz * dz;
            func_800B1830_B2430(dx2 + dz2);
            d2 = dx2 + dy * dy + dz2;
            func_800B1830_B2430(d2);
            d = func_800B1830_B2430(d2) - (ow->unk_48 + work->unk_48);
            if (d < 0.0f) {
                if (ow->unk_38 == 1000.0f || work->unk_38 != 1000.0f) {
                    func_80009684_A284(dx, dz, d);
                    func_80102D78_191918_BobsledRun(work, x, z, o->trans.x, o->trans.z);
                    work->unk_54 = i;
                }
            }
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_801038C4_192464_BobsledRun);
#endif

/* Creates a sled or rider's work (MP1 func_800FA244). */
void func_80103B4C_1926EC_BobsledRun(omObjData* obj, s32 dir, s32 file, u16 team, u16 flags, u16 motFile) {
    BRWork* work;
    s32 i;

    for (i = 0; i < obj->mdlcnt; i++) {
        obj->model[i] = 0;
    }
    obj->unk_50 = func_80027154_27D54(sizeof(BRWork), 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, sizeof(BRWork));
    work = obj->unk_50;
    work->unk_E8 = func_80027154_27D54(obj->mtncnt * sizeof(BRMotion), 0x7918);
    obj->model[0] = LoadFormFile(dir | file, flags);
    obj->model[1] = func_80018A64_19664(D_800BF799_C0399 == 0 ? 1 : 0xD, motFile);
    func_8003C8E0_3D4E0(obj->model[1]);
    for (i = 0; i < obj->mtncnt; i++) {
        obj->motion[i] = -1;
    }
    for (i = 0; i < obj->mtncnt; i++) {
        work->unk_E8[i].unk_00 = 0;
        work->unk_E8[i].unk_02 = 0;
        work->unk_E8[i].unk_04 = -1;
        work->unk_E8[i].unk_08 = -1;
    }
    work->unk_57 = gPlayers[D_8010C048_19ABE8_BobsledRun[team].player[0]].port;
    obj->func_ptr = func_80007790_8390;
    work->unk_52 = 0;
    work->unk_B4 = 1.0f;
    work->unk_D0 = 0xFFFF;
    work->unk_4C = 0.5f;
    work->unk_CC = 1.0f;
    work->unk_60 = 0.0f;
    func_8000BEB0_CAB0(obj, 60.0f);
    func_8000BEBC_CABC(obj, 150.0f);
    func_8000BEC8_CAC8(obj, 20.0f);
    func_8000BED4_CAD4(obj, 30.0f);
    func_8000BE74_CA74(obj, 1000.0f);
    work->unk_9C = work->unk_A0 = work->unk_A4 = 0.0f;
    work->unk_59 = team;
    work->unk_C4 = work->unk_C3 = -1;
}

/* The three background models: spin and pulse their alpha. */
void func_80103DDC_19297C_BobsledRun(void) {
    s32 i;

    for (i = 0; i < 3; i++) {
        D_8010C000_19ABA0_BobsledRun[i] = func_8002D958_2E558(D_8010C000_19ABA0_BobsledRun[i] + D_8010C00C_19ABAC_BobsledRun[i]);
        func_8002979C_2A39C(D_8010CB42_19B6E2_BobsledRun[i], 0.0f, D_8010C000_19ABA0_BobsledRun[i], 0.0f);
        D_8010BFF8_19AB98_BobsledRun[i] += D_8010BFFC_19AB9C_BobsledRun[i];
        if (D_8010BFF8_19AB98_BobsledRun[i] > 160) {
            D_8010BFFC_19AB9C_BobsledRun[i] = 0xFC;
        }
        if (D_8010BFF8_19AB98_BobsledRun[i] < 96) {
            D_8010BFFC_19AB9C_BobsledRun[i] = 4;
        }
        func_8002D0A0_2DCA0(D_8010CB42_19B6E2_BobsledRun[i], D_8010BFF8_19AB98_BobsledRun[i]);
    }
}

/* The course object (D_800FC7B0_FD3B0[0], MP1 func_800FA890). */
void func_80103F24_192AC4_BobsledRun(omObjData* obj) {
    BRGround* w;

    D_8010105C_101C5C = 0.8f;
    D_80101300_101F00 = 0.8f;
    obj->model[0] = -1;
    obj->trans.x = 0.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 0.0f;
    obj->unk_50 = w = func_80027154_27D54(sizeof(BRGround), 0x7918);
    func_800B0EF0_B1AF0(w, 0, sizeof(BRGround));
    obj->func_ptr = func_80103DDC_19297C_BobsledRun;
    w->unk_03 = 1;
    func_8000BEF8_CAF8(obj, 2, -18000.0f);
    w->unk_04 = 0;
    D_8010CB42_19B6E2_BobsledRun[0] = func_80018A30_19630(0x290009, 0xAC9);
    func_8002D124_2DD24(D_8010CB42_19B6E2_BobsledRun[0]);
    func_8002D0A0_2DCA0(D_8010CB42_19B6E2_BobsledRun[0], 0x80);
    D_8010CB42_19B6E2_BobsledRun[1] = func_80027D3C_2893C(D_8010CB42_19B6E2_BobsledRun[0]);
    D_8010CB42_19B6E2_BobsledRun[2] = func_80027D3C_2893C(D_8010CB42_19B6E2_BobsledRun[0]);
    func_80029EDC_2AADC(D_8010CB42_19B6E2_BobsledRun[0], 3);
    func_80029EDC_2AADC(D_8010CB42_19B6E2_BobsledRun[1], 3);
    func_80029EDC_2AADC(D_8010CB42_19B6E2_BobsledRun[2], 3);
    func_80029714_2A314(D_8010CB42_19B6E2_BobsledRun[0], D_8010C018_19ABB8_BobsledRun[0].x, D_8010C018_19ABB8_BobsledRun[0].y, D_8010C018_19ABB8_BobsledRun[0].z);
    func_80029714_2A314(D_8010CB42_19B6E2_BobsledRun[1], D_8010C018_19ABB8_BobsledRun[1].x, D_8010C018_19ABB8_BobsledRun[1].y, D_8010C018_19ABB8_BobsledRun[1].z);
    func_80029714_2A314(D_8010CB42_19B6E2_BobsledRun[2], D_8010C018_19ABB8_BobsledRun[2].x, D_8010C018_19ABB8_BobsledRun[2].y, D_8010C018_19ABB8_BobsledRun[2].z);
}

/* The track (D_800FC7B0_FD3B0[1]): runs the game controller; cameras and the progress bar. */
// register allocation: retail keeps the sprite in s0 and x in s1 (as in MP1)
#ifdef NON_MATCHING
void func_80104084_192C24_BobsledRun(omObjData* obj) {
    s16 x;
    s16 spr;
    BRGround* w;

    D_8010105C_101C5C = 0.8f;
    D_80101300_101F00 = 0.8f;
    obj->model[0] = func_80018A30_19630(0x290007, 0x220D9);
    D_8010105C_101C5C = 1.0f;
    D_80101300_101F00 = 1.0f;
    obj->trans.x = 0.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 0.0f;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    obj->unk_50 = w = func_80027154_27D54(sizeof(BRGround), 0x7918);
    func_800B0EF0_B1AF0(w, 0, sizeof(BRGround));
    obj->func_ptr = func_80102EE0_191A80_BobsledRun;
    w->unk_03 = 1;
    func_8000C004_CC04(obj);
    func_8000BE8C_CA8C(obj, 0.2f);
    func_8000BEA4_CAA4(obj, 25.0f);
    w->unk_04 = 1;
    D_801013B0_101FB0[0].x = -200.0f;
    D_801013B0_101FB0[0].y = 13500.0f;
    D_801013B0_101FB0[0].z = -1000.0f;
    D_80102770_103370[0].x = D_8010BFF0_19AB90_BobsledRun;
    D_800F94A8_FA0A8[0] = 600.0f;
    D_801013B0_101FB0[1].x = 200.0f;
    D_801013B0_101FB0[1].y = 13500.0f;
    D_801013B0_101FB0[1].z = -1000.0f;
    D_80102770_103370[1].x = D_8010BFF0_19AB90_BobsledRun;
    D_800F94A8_FA0A8[1] = 600.0f;
    omSetStatBit(obj, 0xA0);
    func_80029EDC_2AADC(obj->model[0], 3);
    spr = func_8001A2F8_1AEF8(0x29000A);
    x = 8;
    do {
        D_8010C9F0_19B590_BobsledRun = func_8001AAAC_1B6AC(spr, 0, 1);
        espPosSet(D_8010C9F0_19B590_BobsledRun, x, 120);
        func_8001A788_1B388(D_8010C9F0_19B590_BobsledRun, 16);
        x += 16;
    } while (x < 0x120);
    D_8010C9F0_19B590_BobsledRun = func_8001AAAC_1B6AC(spr, 0, 1);
    espPosSet(D_8010C9F0_19B590_BobsledRun, 0x130, 120);
    func_8001A788_1B388(D_8010C9F0_19B590_BobsledRun, 16);
    D_8010C9F2_19B592_BobsledRun = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x29000B), 0, 1);
    espPosSet(D_8010C9F2_19B592_BobsledRun, 0x120, 120);
    func_8001A788_1B388(D_8010C9F2_19B592_BobsledRun, 16);
    D_8010C9F4_19B594_BobsledRun = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x29000C), 0, 1);
    espPosSet(D_8010C9F4_19B594_BobsledRun, 0x120, 104);
    func_8001A788_1B388(D_8010C9F4_19B594_BobsledRun, 16);
    D_8010CC3E_19B7DE_BobsledRun = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x290013), 0, 1);
    func_8001A91C_1B51C(D_8010CC3E_19B7DE_BobsledRun, 1.0f, 1.0f);
    func_8001A788_1B388(D_8010CC3E_19B7DE_BobsledRun, 8);
    D_8010CB40_19B6E0_BobsledRun = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x290014), 0, 1);
    func_8001A91C_1B51C(D_8010CB40_19B6E0_BobsledRun, 1.0f, 1.0f);
    func_8001A788_1B388(D_8010CB40_19B6E0_BobsledRun, 6);
    espPosSet(D_8010CC3E_19B7DE_BobsledRun, 0x12, 112);
    espPosSet(D_8010CB40_19B6E0_BobsledRun, 0x12, 116);
    D_8010CC3C_19B7DC_BobsledRun = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x290015), 0, 1);
    func_8001A91C_1B51C(D_8010CC3C_19B7DC_BobsledRun, 40.0f, 14.0f);
    func_8001A788_1B388(D_8010CC3C_19B7DC_BobsledRun, 32);
    espDispOff(D_8010CC3C_19B7DC_BobsledRun);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_80104084_192C24_BobsledRun);
#endif

void func_80104490_193030_BobsledRun(omObjData* obj) {
    BRGround* w;

    D_8010105C_101C5C = 0.8f;
    D_80101300_101F00 = 0.8f;
    obj->model[0] = func_80018A30_19630(0x290004, 0x220D9);
    obj->trans.x = 0.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 0.0f;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    obj->unk_50 = w = func_80027154_27D54(sizeof(BRGround), 0x7918);
    func_800B0EF0_B1AF0(w, 0, sizeof(BRGround));
    obj->func_ptr = NULL;
    w->unk_03 = 1;
    func_8000C004_CC04(obj);
    func_8000BE8C_CA8C(obj, 0.1f);
    func_8000BEA4_CAA4(obj, 25.0f);
    w->unk_04 = 2;
    func_8000BFF0_CBF0(obj);
}

void func_80104578_193118_BobsledRun(omObjData* obj) {
    BRGround* w;

    D_8010105C_101C5C = 0.8f;
    D_80101300_101F00 = 0.8f;
    obj->model[0] = func_80018A30_19630(0x290005, 0x220D9);
    obj->trans.x = 0.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 0.0f;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    obj->unk_50 = w = func_80027154_27D54(sizeof(BRGround), 0x7918);
    func_800B0EF0_B1AF0(w, 0, sizeof(BRGround));
    obj->func_ptr = NULL;
    w->unk_03 = 1;
    func_8000C004_CC04(obj);
    func_8000BE8C_CA8C(obj, 0.1f);
    func_8000BEA4_CAA4(obj, 25.0f);
    w->unk_04 = 3;
    func_8000BFF0_CBF0(obj);
}

void func_80104660_193200_BobsledRun(omObjData* obj) {
    BRGround* w;

    D_8010105C_101C5C = 0.8f;
    D_80101300_101F00 = 0.8f;
    obj->model[0] = func_80018A30_19630(0x290006, 0x220D9);
    obj->trans.x = 0.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 0.0f;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    obj->unk_50 = w = func_80027154_27D54(sizeof(BRGround), 0x7918);
    func_800B0EF0_B1AF0(w, 0, sizeof(BRGround));
    obj->func_ptr = NULL;
    w->unk_03 = 1;
    func_8000C004_CC04(obj);
    func_8000BE8C_CA8C(obj, 0.1f);
    func_8000BEA4_CAA4(obj, 25.0f);
    w->unk_04 = 4;
    func_8000BFF0_CBF0(obj);
}

void func_80104748_1932E8_BobsledRun(omObjData* obj) {
    BRGround* w;

    D_8010105C_101C5C = 0.8f;
    D_80101300_101F00 = 0.8f;
    obj->model[0] = func_80018A30_19630(0x290008, 0x99);
    obj->trans.x = 0.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 0.0f;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    obj->unk_50 = w = func_80027154_27D54(sizeof(BRGround), 0x7918);
    func_800B0EF0_B1AF0(w, 0, sizeof(BRGround));
    obj->func_ptr = NULL;
    w->unk_03 = 1;
    func_8000C004_CC04(obj);
    func_8000BE8C_CA8C(obj, 0.5f);
    func_8000BEA4_CAA4(obj, 25.0f);
    w->unk_04 = 5;
}

/* A bobsled for team, with its front rider (dir: the character's file directory). */
void func_80104820_1933C0_BobsledRun(omObjData* obj, s32 dir, s32 file, u16 team, s32 chrArg) {
    BRWork* work;
    s32 sled;
    s32 mot;
    s32 spr;
    s32 chr;
    s32 motFile;
    s32 file4E;
    s16 mdl;

    motFile = 0x22A99;
    switch ((u32)dir >> 16) {
        case 2:
            sled = 0x17;
            mot = 0x1D;
            spr = 0xD;
            chr = 0;
            break;
        case 3:
            sled = 0x18;
            mot = 0x22;
            spr = 0xE;
            chr = 1;
            break;
        case 7:
            sled = 0x19;
            mot = 0x27;
            spr = 0xF;
            chr = 2;
            break;
        case 4:
            sled = 0x1A;
            mot = 0x2C;
            spr = 0x10;
            chr = 3;
            break;
        case 5:
            sled = 0x1B;
            mot = 0x31;
            spr = 0x11;
            chr = 4;
            break;
        default:
            sled = 0x1C;
            mot = 0x36;
            spr = 0x12;
            chr = 5;
            break;
    }
    D_8010105C_101C5C = 0.8f;
    D_80101300_101F00 = 0.8f;
    func_80103B4C_1926EC_BobsledRun(obj, 0x290000, sled, team, motFile | 4, motFile);
    work = obj->unk_50;
    D_8010C048_19ABE8_BobsledRun[team].mdl[1] = obj->model[0];
    func_800297E8_2A3E8(obj->model[1], 2.0f, 2.0f, 2.0f);
    obj->model[0] = mdl = LoadFormFile(dir | file, 0x2AC9);
    D_8010C048_19ABE8_BobsledRun[team].mdl[0] = mdl;
    work->unk_5A = mdl;
    work->unk_5B = 2;
    func_80025384_25F84(D_8010C048_19ABE8_BobsledRun[team].mdl[0], 2, chr, dir | func_80025718_26318(chr, 2, 0));
    D_8010105C_101C5C = 0.8f;
    D_80101300_101F00 = 0.8f;
    work->unk_59 = D_8010C048_19ABE8_BobsledRun[team].player[0];
    func_80019F0C_1AB0C(obj, 0x26, mot | 0x290000, 1, 0);
    func_80019F0C_1AB0C(obj, 0x27, dir | 4, 1, 0x13);
    func_80019F0C_1AB0C(obj, 6, dir | 0x3A, 0, 0);
    func_80019F0C_1AB0C(obj, 0, dir | 0x3B, 1, 0);
    func_80019F0C_1AB0C(obj, 1, dir | 0x3C, 0, 0);
    func_80019F0C_1AB0C(obj, 0x15, dir | 0x2E, 2, 0);
    file4E = dir | 0x4E;
    func_8001A12C_1AD2C(obj, 0xD, file4E, 1, 0x78, 1);
    D_8010CB30_19B6D0_BobsledRun[work->unk_59] = file4E;
    work->unk_59 = team;
    obj->func_ptr = func_8010A3AC_198F4C_BobsledRun;
    func_8000BEB0_CAB0(obj, 100.0f);
    work->unk_3C = 0.0f;
    func_8000C024_CC24(obj, 0, 2);
    func_8000C024_CC24(obj, 1, 2);
    func_8000C024_CC24(obj, 2, 2);
    func_8000C024_CC24(obj, 3, 2);
    func_8000C024_CC24(obj, 4, 2);
    func_8000C024_CC24(obj, 5, 2);
    func_80105720_1942C0_BobsledRun();
    obj->model[3] = mdl = LoadFormFile(0x290016, 0x889);
    D_8010C048_19ABE8_BobsledRun[team].mdl[6] = mdl;
    D_8010C048_19ABE8_BobsledRun[team].sprite = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(spr | 0x290000), 0, 1);
}

/* The back rider of team (player). */
void func_80104BE0_193780_BobsledRun(omObjData* obj, s32 dir, s32 file, u16 player, u16 team) {
    BRWork* work;
    s32 body;
    s32 mot;
    s32 spr;
    s32 chr;
    s32 flags;
    s32 file4E;
    s16 mdl;

    flags = 0x22A99;
    switch ((u32)dir >> 16) {
        case 2:
            body = 0x17;
            mot = 0x1D;
            spr = 0xD;
            break;
        case 3:
            body = 0x18;
            mot = 0x22;
            spr = 0xE;
            break;
        case 7:
            body = 0x19;
            mot = 0x27;
            spr = 0xF;
            break;
        case 4:
            body = 0x1A;
            mot = 0x2C;
            spr = 0x10;
            break;
        case 5:
            body = 0x1B;
            mot = 0x31;
            spr = 0x11;
            break;
        default:
            body = 0x1C;
            mot = 0x36;
            spr = 0x12;
            break;
    }
    D_8010105C_101C5C = 0.8f;
    D_80101300_101F00 = 0.8f;
    func_8000C6FC_D2FC(obj, 0x290000, body, player, flags | 4, flags | 4);
    D_8010C048_19ABE8_BobsledRun[team].mdl[3] = obj->model[0];
    work = obj->unk_50;
    obj->model[0] = mdl = LoadFormFile(dir | file, 0x2AC9);
    D_8010C048_19ABE8_BobsledRun[team].mdl[2] = mdl;
    chr = gPlayers[player].character;
    work->unk_5A = mdl;
    work->unk_5B = 2;
    func_80025384_25F84(D_8010C048_19ABE8_BobsledRun[team].mdl[2], 2, chr, dir | func_80025718_26318(chr, 2, 0));
    func_80019F0C_1AB0C(obj, 0x26, mot | 0x290000, 1, 0);
    func_80019F0C_1AB0C(obj, 0x27, dir | 4, 1, 0x13);
    func_80019F0C_1AB0C(obj, 6, dir | 0x3A, 2, 0);
    func_80019F0C_1AB0C(obj, 0, dir | 0x3B, 1, 0);
    func_80019F0C_1AB0C(obj, 1, dir | 0x3C, 0, 0);
    file4E = dir | 0x4E;
    func_8001A12C_1AD2C(obj, 0xD, file4E, 1, 0x78, 1);
    D_8010CB30_19B6D0_BobsledRun[player] = file4E;
    obj->func_ptr = func_8010982C_1983CC_BobsledRun;
    work->unk_59 = team;
    D_8010C048_19ABE8_BobsledRun[team].sprite2 = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(spr | 0x290000), 0, 1);
}

/* Draw layers of a sled by distance to the other team's camera (1: top screen only, 2: bottom,
   3: both); close up (or while the other team's riders do anim 5) its effect model shows. */
// register allocation: retail keeps obj in s1 and moves the layer into s0 for the last three calls
#ifdef NON_MATCHING
void func_80104EAC_193A4C_BobsledRun(omObjData* obj) {
    s8* t; /* &D_8010C048_19ABE8_BobsledRun[other].anim: retail's base register */
    s32 layer;
    s32 layer2;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 d;

    layer = 2;
    if (BR_WORK(obj)->unk_59 == 0) {
        layer = 1;
        layer2 = 1;
        dx = obj->trans.x - D_801013B0_101FB0[1].x;
        dy = obj->trans.y - D_801013B0_101FB0[1].y;
        dz = obj->trans.z - D_801013B0_101FB0[1].z;
        d = func_800B1830_B2430(dx * dx + dy * dy + dz * dz);
        if (d < 5000.0f) {
            layer = 3;
            if (d < 1350.0f) {
                layer2 = 3;
                func_800298A4_2A4A4(obj->model[6], 4, 4);
            } else {
                func_800298A4_2A4A4(obj->model[6], 4, 0);
            }
        }
        t = &D_8010C048_19ABE8_BobsledRun[1].anim;
    } else {
        layer2 = 2;
        dx = obj->trans.x - D_801013B0_101FB0[0].x;
        dy = obj->trans.y - D_801013B0_101FB0[0].y;
        dz = obj->trans.z - D_801013B0_101FB0[0].z;
        d = func_800B1830_B2430(dx * dx + dy * dy + dz * dz);
        if (d < 5000.0f) {
            layer = 3;
            if (d < 1350.0f) {
                layer2 = 3;
                func_800298A4_2A4A4(obj->model[6], 4, 4);
            } else {
                func_800298A4_2A4A4(obj->model[6], 4, 0);
            }
        }
        t = &D_8010C048_19ABE8_BobsledRun[0].anim;
    }
    if (t[0] == 5) { /* anim */
        func_800298A4_2A4A4(obj->model[6], 4, 4);
        func_800298A4_2A4A4(t[10], 4, 4); /* mdl[5] */
    }
    func_80029EDC_2AADC(obj->model[0], layer);
    func_80029EDC_2AADC(obj->model[1], layer);
    func_80029EDC_2AADC(obj->model[5], layer2);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_80104EAC_193A4C_BobsledRun);
#endif

/* Draw layer of a rider by distance to the other team's camera. */
// float register allocation of the distance (as in MP1)
#ifdef NON_MATCHING
void func_801050F8_193C98_BobsledRun(omObjData* obj) {
    Vec3f* c;
    s32 layer;
    f32 dx;
    f32 dy;
    f32 dz;

    layer = 2;
    if (BR_WORK(obj)->unk_59 == 0) {
        c = &D_801013B0_101FB0[1];
        layer = 1;
    } else {
        c = &D_801013B0_101FB0[0];
    }
    dx = obj->trans.x - c->x;
    dy = obj->trans.y - c->y;
    dz = obj->trans.z - c->z;
    if (func_800B1830_B2430(dx * dx + dy * dy + dz * dz) < 5000.0f) {
        layer = 3;
    }
    func_80029EDC_2AADC(obj->model[0], layer);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_801050F8_193C98_BobsledRun);
#endif

/* Team 0's sled object (D_800FFFD8_100BD8[0]). */
void func_801051BC_193D5C_BobsledRun(omObjData* obj) {
    s32 chr;
    s32 file;
    s32 dir;
    s16 mdl;

    chr = gPlayers[D_8010C048_19ABE8_BobsledRun[0].player[0]].character;
    file = D_800CD438_CE038[chr].unk_0C;
    dir = D_800CD438_CE038[chr].unk_04;
    func_80104820_1933C0_BobsledRun(obj, dir, file, 0, chr);
    obj->model[5] = mdl = LoadFormFile(0x290000, 0x2C9);
    D_8010C048_19ABE8_BobsledRun[0].mdl[4] = mdl;
    D_8010105C_101C5C = 0.7f;
    D_80101300_101F00 = 0.7f;
    obj->model[6] = mdl = LoadFormFile(0x290002, 0xAC9);
    D_8010C048_19ABE8_BobsledRun[0].mdl[5] = mdl;
    func_80019B9C_1A79C(obj, 0);
    obj->trans.x = -200.0f;
    obj->trans.y = 13500.0f;
    obj->trans.z = -1000.0f;
    func_80029714_2A314(obj->model[5], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80029714_2A314(obj->model[6], obj->trans.x, obj->trans.y, obj->trans.z);
    func_8001A788_1B388(D_8010C048_19ABE8_BobsledRun[0].sprite, 9);
    espPosSet(D_8010C048_19ABE8_BobsledRun[0].sprite, 0x20, 0x5A);
    func_80029EDC_2AADC(obj->model[6], 2);
    func_80029E80_2AA80(obj->model[5], 2, 2);
}

/* Team 1's sled object (D_800FFFD8_100BD8[1]). */
void func_80105344_193EE4_BobsledRun(omObjData* obj) {
    s32 chr;
    s32 file;
    s32 dir;
    s16 mdl;

    chr = gPlayers[D_8010C048_19ABE8_BobsledRun[1].player[0]].character;
    file = D_800CD438_CE038[chr].unk_0C;
    dir = D_800CD438_CE038[chr].unk_04;
    func_80104820_1933C0_BobsledRun(obj, dir, file, 1, chr);
    obj->model[5] = mdl = LoadFormFile(0x290001, 0x2C9);
    D_8010C048_19ABE8_BobsledRun[1].mdl[4] = mdl;
    D_8010105C_101C5C = 0.7f;
    D_80101300_101F00 = 0.7f;
    obj->model[6] = mdl = LoadFormFile(0x290003, 0xAC9);
    D_8010C048_19ABE8_BobsledRun[1].mdl[5] = mdl;
    func_80019B9C_1A79C(obj, 0);
    obj->trans.x = 200.0f;
    obj->trans.y = 13500.0f;
    obj->trans.z = -1000.0f;
    func_80029714_2A314(obj->model[5], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80029714_2A314(obj->model[6], obj->trans.x, obj->trans.y, obj->trans.z);
    func_8001A788_1B388(D_8010C048_19ABE8_BobsledRun[1].sprite, 7);
    espPosSet(D_8010C048_19ABE8_BobsledRun[1].sprite, 0x20, 0x5E);
    func_80029EDC_2AADC(obj->model[6], 1);
    func_80029E80_2AA80(obj->model[5], 2, 2);
}

/* Team 0's back rider. */
void func_801054D0_194070_BobsledRun(omObjData* obj) {
    s8 p = D_8010C048_19ABE8_BobsledRun[0].player[1];
    s32 file = D_800CD438_CE038[gPlayers[p].character].unk_0C;
    s32 dir = D_800CD438_CE038[gPlayers[p].character].unk_04;

    func_80104BE0_193780_BobsledRun(obj, dir, file, p, 0);
    func_80019B9C_1A79C(obj, 0);
    func_8001A788_1B388(D_8010C048_19ABE8_BobsledRun[0].sprite2, 9);
    espPosSet(D_8010C048_19ABE8_BobsledRun[0].sprite2, 0x16, 0x5A);
}

/* Team 1's back rider. */
void func_8010557C_19411C_BobsledRun(omObjData* obj) {
    s8 p = D_8010C048_19ABE8_BobsledRun[1].player[1];
    s32 file = D_800CD438_CE038[gPlayers[p].character].unk_0C;
    s32 dir = D_800CD438_CE038[gPlayers[p].character].unk_04;

    func_80104BE0_193780_BobsledRun(obj, dir, file, p, 1);
    func_80019B9C_1A79C(obj, 0);
    func_8001A788_1B388(D_8010C048_19ABE8_BobsledRun[1].sprite2, 7);
    espPosSet(D_8010C048_19ABE8_BobsledRun[1].sprite2, 0x16, 0x5E);
}

/* Teams from the players' groups. */
void func_8010562C_1941CC_BobsledRun(void) {
    s32 t;
    s32 i;

    for (t = 0; t < 2; t++) {
        for (i = 0; i < 4; i++) {
            if (t == gPlayers[i].group) {
                if (D_8010C048_19ABE8_BobsledRun[t].player[0] < 0) {
                    D_8010C048_19ABE8_BobsledRun[t].player[0] = i;
                    D_8010C048_19ABE8_BobsledRun[t].port[0] = gPlayers[i].port;
                } else if (D_8010C048_19ABE8_BobsledRun[t].player[1] < 0) {
                    D_8010C048_19ABE8_BobsledRun[t].player[1] = i;
                    D_8010C048_19ABE8_BobsledRun[t].port[1] = gPlayers[i].port;
                }
                D_8010C03C_19ABDC_BobsledRun[i] = t;
            }
        }
    }
}

void func_80105720_1942C0_BobsledRun(void) {
    s32 i;

    D_8010CA38_19B5D8_BobsledRun.idx = 0;
    D_8010CB48_19B6E8_BobsledRun.idx = 0;
    for (i = 0; i < 20; i++) {
        D_8010CADC_19B67C_BobsledRun[i] = D_8010CBEC_19B78C_BobsledRun[i] = 0.0f;
    }
}

/* Which track sections each team's camera draws (by progress), and which background models
   (by the sleds' heights). */
void func_80105770_194310_BobsledRun(void) {
    s32 bits[2];
    omObjData* g;
    omObjData* sled;
    f32 lo;
    f32 hi;
    f32 p;
    s32 i;
    s32 t;
    s16 mask;

    bits[0] = 1;
    bits[1] = 2;
    for (i = 0; i < 6; i++) {
        g = D_800FC7B0_FD3B0[i];
        mask = 0;
        lo = D_8010C0E8_19AC88_BobsledRun[i];
        hi = D_8010C100_19ACA0_BobsledRun[i];
        for (t = 0; t < 2; t++) {
            sled = D_800FFFD8_100BD8[t];
            p = D_8010C048_19ABE8_BobsledRun[t].progress;
            if ((lo <= p) & (p < hi)) {
                if (D_8010C048_19ABE8_BobsledRun[t].progress < 50.0f) {
                    func_8000C024_CC24(sled, i, 2);
                    mask |= bits[t];
                }
            } else {
                func_8000C024_CC24(sled, i, 1);
            }
        }
        func_80029EDC_2AADC(g->model[0], mask);
    }
    for (i = 0; i < 3; i++) {
        mask = 0;
        for (t = 0; t < 2; t++) {
            sled = D_800FFFD8_100BD8[t];
            p = sled->trans.y;
            if (D_8010C048_19ABE8_BobsledRun[t].anim != 5) {
                if (D_8010C018_19ABB8_BobsledRun[i].y - 100.0f <= p && p < D_8010C018_19ABB8_BobsledRun[i].y + 500.0f) {
                    mask |= bits[t];
                }
            }
        }
        func_80029EDC_2AADC(D_8010CB42_19B6E2_BobsledRun[i], mask);
    }
}

/* Time display m:ss"cc (frames at 60 per second) in group idx. */
void func_801059F8_194598_BobsledRun(s16 idx, s16 time) {
    s16 g;
    s16 d;
    s16 sec;
    s16 cs;

    g = D_8010C9FA_19B59A_BobsledRun[idx];
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

void func_80105CF0_194890_BobsledRun(void) {
    void* data;

    data = DataRead(0x43);
    D_8010C9F6_19B596_BobsledRun = SprAnimRead(data);
    DataClose(data);
}

void func_80105D30_1948D0_BobsledRun(void) {
    void* data;

    data = DataRead(0x43);
    D_8010C9F8_19B598_BobsledRun = SprAnimRead(data);
    DataClose(data);
    func_8001A340_1AF40(D_8010C9F8_19B598_BobsledRun, 0.0f, 1.0f, 0.0f);
}

/* Time display group 0 (the race time) at (x, y). */
// register allocation: retail stores the group id before copying it to s5, x in s1 (as in MP1 MinigameHouse func_800F8364)
#ifdef NON_MATCHING
s16 func_80105D88_194928_BobsledRun(s32 x, s16 y) {
    s16 i;
    s16 px;
    s16 g;

    g = SprCreate(7, 5);
    D_8010C9FA_19B59A_BobsledRun[0] = g;
    SprAnimSet(g, 0, D_8010C9F6_19B596_BobsledRun, 0);
    SprAttrReset(g, 0, 0xFFFF);
    SprAttrSet(g, 0, 0x8000);
    SprPosSet(g, 0, x - 16, y);
    SprPrioSet(g, 0, 1);
    px = 4;
    for (i = 1; i < 7; i++) {
        SprPrioSet(g, i, 1);
        SprAnimSet(g, i, D_8010C9F6_19B596_BobsledRun, 0);
        SprPosSet(g, i, px, 0);
        SprAttrReset(g, i, 0xFFFF);
        SprAttrSet(g, i, 0x8000);
        if (i == 3) {
            px += 8;
        } else {
            px += 12;
        }
        func_800824F4_830F4(g, i, 0);
    }
    SprAttrReset(g, 2, 0x8000);
    return g;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_80105D88_194928_BobsledRun);
#endif

/* Time display group 1 (the record) at (x, y). */
// register allocation, as func_80105D88
#ifdef NON_MATCHING
s16 func_80105F38_194AD8_BobsledRun(s32 x, s16 y) {
    s16 i;
    s16 px;
    s16 g;

    g = SprCreate(7, 5);
    D_8010C9FA_19B59A_BobsledRun[1] = g;
    SprAnimSet(g, 0, D_8010C9F8_19B598_BobsledRun, 0);
    SprAttrReset(g, 0, 0xFFFF);
    SprAttrSet(g, 0, 0x8000);
    SprPosSet(g, 0, x - 16, y);
    SprPrioSet(g, 0, 1);
    px = 4;
    for (i = 1; i < 7; i++) {
        SprPrioSet(g, i, 1);
        SprAnimSet(g, i, D_8010C9F8_19B598_BobsledRun, 0);
        SprPosSet(g, i, px, 0);
        SprAttrReset(g, i, 0xFFFF);
        SprAttrSet(g, i, 0x8000);
        if (i == 3) {
            px += 8;
        } else {
            px += 12;
        }
        func_800824F4_830F4(g, i, 0);
    }
    SprAttrReset(g, 2, 0x8000);
    return g;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_80105F38_194AD8_BobsledRun);
#endif

/* Snow spray from the runners (model[3]) and its sliding sound. */
void func_801060E8_194C88_BobsledRun(omObjData* obj, s16 force, f32 minSpeed, f32 rot, f32 x, f32 y, f32 z) {
    BRWork* work;
    s32 mdl;
    f32 s;
    f32 a;
    HmfAnim* anim;

    work = obj->unk_50;
    mdl = obj->model[3];
    if (force >= 21 && minSpeed < work->unk_40) {
        x += D_8010CA20_19B5C0_BobsledRun[work->unk_59].x * 220.0f;
        y += D_8010CA20_19B5C0_BobsledRun[work->unk_59].y * 220.0f;
        z += D_8010CA20_19B5C0_BobsledRun[work->unk_59].z * 220.0f;
        s = work->unk_40 / 100.0f * 0.6f;
        if (s > 1.0f) {
            s = 1.0f;
        }
        a = (2.0f * force) / 60.0f;
        if (a > 2.0f) {
            a = 2.0f;
        }
        D_800FC834_FD434[mdl].unk44 = a;
        func_800298A4_2A4A4(mdl, 4, 0);
        func_80029714_2A314(mdl, x, y + 30.0f, z);
        func_8002979C_2A39C(mdl, 0.0f, rot, 0.0f);
        func_800297E8_2A3E8(mdl, s, s, s);
        if (work->unk_59 == 0) {
            if (D_8010C0E0_19AC80_BobsledRun == -1) {
                D_8010C0E0_19AC80_BobsledRun = func_80079798_7A398(0x1F9, D_8010C048_19ABE8_BobsledRun[work->unk_59].player[0]);
            }
        } else if (D_8010C0E4_19AC84_BobsledRun == -1) {
            D_8010C0E4_19AC84_BobsledRun = func_80079798_7A398(0x1F9, D_8010C048_19ABE8_BobsledRun[work->unk_59].player[0]);
        }
    } else {
        if (func_80029CE4_2A8E4(mdl) > 32.0f) {
            func_800298A4_2A4A4(mdl, 4, 4);
            func_80029C74_2A874(mdl, 0.0f);
            anim = D_800FC834_FD434[mdl].hmf->unk9C;
            if (anim != NULL) {
                anim->unk08 = 0.0f;
            }
        }
        if (work->unk_59 == 0) {
            if (D_8010C0E0_19AC80_BobsledRun != -1) {
                func_80079848_7A448((s16)D_8010C0E0_19AC80_BobsledRun);
                D_8010C0E0_19AC80_BobsledRun = -1;
            }
        } else if (D_8010C0E4_19AC84_BobsledRun != -1) {
            func_80079848_7A448((s16)D_8010C0E4_19AC84_BobsledRun);
            D_8010C0E4_19AC84_BobsledRun = -1;
        }
    }
}

/* Loop the spray animation (model mdl) back to frame 32. */
void func_80106438_194FD8_BobsledRun(s32 team, u8 mdl) {
    f32 cur;
    HmfAnim* anim;

    if (mdl != 0) {
        cur = func_80029CE4_2A8E4(mdl);
        if (func_80029D0C_2A90C(mdl) <= cur) {
            func_80029C74_2A874(mdl, 32.0f);
            anim = D_800FC834_FD434[mdl].hmf->unk9C;
            if (anim != NULL) {
                anim->unk08 = anim->unk04 * 0.6f;
            }
        }
    }
}

/* The bobsled after the crash zone or the goal: the winner slides to a stop (then, without
   _CheckFlag(0xC), the riders climb out and the sled drops away), the loser spins out. */
// register allocation (spin s5/s6, the ground height f2/f20, camera distance f20/f22) and the team*0x44 index schedule; logic follows retail
#ifdef NON_MATCHING
void func_801064F0_195090_BobsledRun(omObjData* obj) {
    BRWork* work;
    omObjData* o;
    s32 team;
    f32 x;
    f32 y;
    f32 z;
    f32 x2;
    f32 y2;
    f32 z2;
    f32 spin;
    f32 speed;
    f32 h;
    f32 sp;
    f32 cy;
    f32 d;
    f32 v;
    f32 vv;
    f32 f;

    work = obj->unk_50;
    team = work->unk_59;
    x2 = x = obj->trans.x;
    y = obj->trans.y;
    z2 = z = obj->trans.z;
    spin = D_800F94A0_FA0A0 = D_80101308_101F08 = 0.0f;
    y2 = y;
    if (D_8010BFF4_19AB94_BobsledRun == team) {
        speed = work->unk_40;
        switch (D_8010C048_19ABE8_BobsledRun[team].anim) {
            case 6:
                if (work->unk_38 == 1000.0f) {
                    work->unk_38 = -D_800BF7A4_C03A4 * 0.8f;
                }
                if (_CheckFlag(0xC) == 0) {
                    v = work->unk_38;
                    if (D_800BF7D4_C03D4 < v) {
                        v = D_800BF7D4_C03D4;
                    }
                    vv = v * v;
                    if (work->unk_38 >= 0.0f) {
                        f = vv * -35.0f;
                    } else {
                        f = vv * 35.0f;
                    }
                    y2 += f;
                    work->unk_3C += -10.0f;
                    if (work->unk_3C < 120.0f) {
                        work->unk_3C = 120.0f;
                    }
                    work->unk_38 = D_800BF7A8_C03A8 * 1.5f + work->unk_38;
                    if (y2 < -8315.0f) {
                        y2 = -8315.0f;
                        D_8010C048_19ABE8_BobsledRun[team].anim = 7;
                        work->unk_3C = 120.0f;
                    }
                    x2 += HuMathSin(D_80102770_103370[team].y) * 6.0f;
                    z2 += func_800B7890_B8490(D_80102770_103370[team].y) * 6.0f;
                }
                func_8000C35C_CF5C(obj, x2, y2, z2);
            case 7:
                if (_CheckFlag(0xC) == 0) {
                    func_80019B9C_1A79C(obj, 0xD);
                    func_800732B0_73EB0(D_8010CB30_19B6D0_BobsledRun[D_8010C048_19ABE8_BobsledRun[team].player[0]]);
                    D_8010CB30_19B6D0_BobsledRun[D_8010C048_19ABE8_BobsledRun[team].player[0]] = -1;
                }
            default:
                spin = -D_8010C048_19ABE8_BobsledRun[team].roll * 3.0f;
                if (speed != D_800BF7D0_C03D0) {
                    speed -= D_8010C048_19ABE8_BobsledRun[team].roll * 0.08f;
                    if (speed < 1.0f) {
                        work->unk_40 = D_800BF7D0_C03D0;
                        speed = D_800BF7D0_C03D0;
                        D_8010C048_19ABE8_BobsledRun[team].anim = 6;
                        if (_CheckFlag(0xC) == 0) {
                            func_800298A4_2A4A4(D_8010C048_19ABE8_BobsledRun[team].mdl[1], 4, 4);
                            func_800298A4_2A4A4(D_8010C048_19ABE8_BobsledRun[team].mdl[0], 4, 0);
                            obj->model[0] = D_8010C048_19ABE8_BobsledRun[team].mdl[0];
                            func_80019E04_1AA04(obj, 0x27, 6);
                            func_80019B9C_1A79C(obj, 6);
                            func_800298A4_2A4A4(D_8010C048_19ABE8_BobsledRun[team].mdl[3], 4, 4);
                            func_800298A4_2A4A4(D_8010C048_19ABE8_BobsledRun[team].mdl[2], 4, 0);
                            y2 += 10.0f;
                        }
                    }
                    work->unk_40 = speed;
                    HuMathSin(work->unk_3C);
                    func_800B7890_B8490(work->unk_3C);
                    x += HuMathSin(work->unk_3C) * speed;
                    z += func_800B7890_B8490(work->unk_3C) * speed;
                    h = func_8000312C_3D2C(obj, work->unk_3C, x, y, z);
                    if (h != 65536.0f) {
                        y = h;
                        func_801060E8_194C88_BobsledRun(obj, 100, 60.0f, spin + work->unk_3C, x, y, z);
                    }
                    x += D_800F94A0_FA0A0;
                    z += D_80101308_101F08;
                    func_8000C35C_CF5C(obj, x, y2, z);
                    func_80029714_2A314(obj->model[5], x, y, z);
                    func_80029714_2A314(obj->model[6], x, y, z);
                }
                cy = y + (200.0f - (D_8010C048_19ABE8_BobsledRun[team].roll * 5.0f + (sp = work->unk_40)));
                D_8010C134_19ACD4_BobsledRun += 0.5f;
                d = 2.0f * sp;
                if (D_8010C134_19ACD4_BobsledRun < 25.0f) {
                    D_8010C134_19ACD4_BobsledRun = 25;
                }
                D_80102770_103370[team].y = work->unk_3C + D_8010C048_19ABE8_BobsledRun[team].roll + 180.0f;
                D_801013B0_101FB0[team].x = x - HuMathSin(work->unk_3C) * d;
                D_801013B0_101FB0[team].z = z - func_800B7890_B8490(work->unk_3C) * d;
                if (d != 0.0f) {
                    D_801013B0_101FB0[team].y = cy + D_8010C134_19ACD4_BobsledRun;
                    D_800F94A8_FA0A8[team] = work->unk_40 + 350.0f + D_8010C048_19ABE8_BobsledRun[team].roll;
                }
                func_800B2060_B2C60(D_800FC834_FD434[obj->model[5]].mtx, 0.0f, spin + work->unk_3C, 0.0f);
                func_800B2060_B2C60(D_800FC834_FD434[obj->model[6]].mtx, 0.0f, spin + work->unk_3C, 0.0f);
                func_8002979C_2A39C(obj->model[5], obj->rot.x, obj->rot.y, obj->rot.z);
                func_8002979C_2A39C(obj->model[6], obj->rot.x, obj->rot.y, obj->rot.z);
                break;
        }
        func_800B2060_B2C60(D_800FC834_FD434[obj->model[0]].mtx, 0.0f, spin + work->unk_3C, 0.0f);
        D_8010CA20_19B5C0_BobsledRun[team].x = HuMathSin(work->unk_3C + 180.0f - spin);
        D_8010CA20_19B5C0_BobsledRun[team].y = 0.0f;
        D_8010CA20_19B5C0_BobsledRun[team].z = func_800B7890_B8490(work->unk_3C + 180.0f - spin);
        func_8002D9AC_2E5AC(&D_8010CA20_19B5C0_BobsledRun[team]);
        D_8010C048_19ABE8_BobsledRun[team].roll *= 1.15f;
        if (D_8010C048_19ABE8_BobsledRun[team].roll > 30.0f) {
            D_8010C048_19ABE8_BobsledRun[team].roll = 30.0f;
        }
    } else {
        speed = work->unk_40;
        switch (D_8010C048_19ABE8_BobsledRun[team].anim) {
            case 8:
                v = work->unk_38;
                if (D_800BF7D4_C03D4 < v) {
                    v = D_800BF7D4_C03D4;
                }
                vv = v * v;
                if (work->unk_38 >= 0.0f) {
                    f = vv * -35.0f;
                } else {
                    f = vv * 35.0f;
                }
                y += f;
                work->unk_40 = speed * 0.98f;
                work->unk_38 = 2.0f * D_800BF7A8_C03A8 + work->unk_38;
                if (y < -9500.0f) {
                    y = -9500.0f;
                }
            default:
                spin = -D_8010C048_19ABE8_BobsledRun[team].roll;
                if (speed != D_800BF7D0_C03D0) {
                    if (D_8010C048_19ABE8_BobsledRun[team].roll < 8.0f) {
                        if (D_8010BFF4_19AB94_BobsledRun != -1) {
                            o = D_800FFFD8_100BD8[D_8010BFF4_19AB94_BobsledRun];
                        } else if (team != 0) {
                            o = D_800FFFD8_100BD8[0];
                        } else {
                            o = D_800FFFD8_100BD8[1];
                        }
                        if (o->trans.z < obj->trans.z) {
                            work->unk_3C = work->unk_3C + D_8010C048_19ABE8_BobsledRun[team].roll;
                        } else {
                            work->unk_3C = work->unk_3C - D_8010C048_19ABE8_BobsledRun[team].roll;
                        }
                    }
                    speed -= D_8010C048_19ABE8_BobsledRun[team].roll * 0.02f;
                    if (speed < 1.0f) {
                        work->unk_40 = D_800BF7D0_C03D0;
                        speed = D_800BF7D0_C03D0;
                    }
                    work->unk_40 = speed;
                }
                h = func_8000312C_3D2C(obj, work->unk_3C, x, y, z);
                if (h != 65536.0f) {
                    y = h;
                } else if (work->unk_38 != 1000.0f && D_8010BFF4_19AB94_BobsledRun != work->unk_59) {
                    func_800298A4_2A4A4((s8)obj->model[0], 4, 4);
                    func_800298A4_2A4A4((s8)obj->model[1], 4, 4);
                    obj->model[0] = D_8010C048_19ABE8_BobsledRun[team].mdl[0];
                    func_800298A4_2A4A4((s8)obj->model[0], 4, 0);
                    work->unk_38 = -D_800BF7A4_C03A4 * 0.4f;
                    D_8010C048_19ABE8_BobsledRun[team].anim = 8;
                    func_80019E04_1AA04(obj, 0x27, 6);
                }
                break;
            case 9:
                break;
        }
        func_801060E8_194C88_BobsledRun(obj, 30, 50.0f, work->unk_3C - spin, x, y, z);
        x = x + (HuMathSin(work->unk_3C) * speed + D_800F94A0_FA0A0);
        z = z + (func_800B7890_B8490(work->unk_3C) * speed + D_80101308_101F08);
        func_800B2060_B2C60(D_800FC834_FD434[obj->model[0]].mtx, 0.0f, work->unk_3C, 0.0f);
        D_8010CA20_19B5C0_BobsledRun[team].x = HuMathSin(work->unk_3C + 180.0f);
        D_8010CA20_19B5C0_BobsledRun[team].y = 0.0f;
        D_8010CA20_19B5C0_BobsledRun[team].z = func_800B7890_B8490(work->unk_3C + 180.0f);
        func_8002D9AC_2E5AC(&D_8010CA20_19B5C0_BobsledRun[team]);
        func_8000C35C_CF5C(obj, x, y, z);
        if (D_8010C048_19ABE8_BobsledRun[team].anim == 4) {
            func_800B2060_B2C60(D_800FC834_FD434[obj->model[5]].mtx, 0.0f, work->unk_3C, 0.0f);
            func_8002979C_2A39C(obj->model[5], obj->rot.x, obj->rot.y, obj->rot.z);
            func_80029714_2A314(obj->model[5], x, y, z);
            func_800B2060_B2C60(D_800FC834_FD434[obj->model[6]].mtx, 0.0f, work->unk_3C, 0.0f);
            func_8002979C_2A39C(obj->model[6], obj->rot.x, obj->rot.y, obj->rot.z);
            func_80029714_2A314(obj->model[6], x, y, z);
            cy = 200.0f - (D_8010C048_19ABE8_BobsledRun[team].roll * 3.0f + (sp = work->unk_40)) + obj->trans.y;
            D_80102770_103370[team].y = work->unk_3C + 180.0f;
            d = 2.0f * sp;
            D_801013B0_101FB0[team].x = obj->trans.x - HuMathSin(work->unk_3C) * d;
            D_801013B0_101FB0[team].z = obj->trans.z - func_800B7890_B8490(work->unk_3C) * d;
            if (d != 0.0f) {
                D_801013B0_101FB0[team].y = cy;
                D_800F94A8_FA0A8[team] = work->unk_40 + 300.0f + D_8010C048_19ABE8_BobsledRun[team].roll * 3.0f;
            }
        } else if (D_8010C048_19ABE8_BobsledRun[team].anim == 8) {
            func_80029714_2A314(obj->model[5], x, y, z);
            func_80029714_2A314(obj->model[6], x, y, z);
        }
        D_8010C048_19ABE8_BobsledRun[team].roll = D_8010C048_19ABE8_BobsledRun[team].roll * 1.07;
        if (D_8010C048_19ABE8_BobsledRun[team].roll > 40.0f) {
            D_8010C048_19ABE8_BobsledRun[team].roll = 40.0f;
        }
    }
    func_8010BD18_19A8B8_BobsledRun(obj, D_8010C048_19ABE8_BobsledRun[work->unk_59].player[0]);
    func_80106438_194FD8_BobsledRun(team, obj->model[3]);
    func_80104EAC_193A4C_BobsledRun(obj);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_801064F0_195090_BobsledRun);
#endif

/* Running mean of the last 20 values (the camera roll). */
f32 func_80107550_1960F0_BobsledRun(s32 team, f32 value) {
    BRHist* h;
    f32 sum;
    s32 i;

    h = &D_8010CA38_19B5D8_BobsledRun;
    if (team == 0) {
        h = &D_8010CB48_19B6E8_BobsledRun;
    }
    h->samples[h->idx++] = value;
    if (h->idx >= 20) {
        h->idx = 0;
    }
    sum = 0.0f;
    for (i = 0; i < 20; i++) {
        sum += h->samples[i];
    }
    return sum / 20.0f;
}

/* The team's race state from the ground under the sled: 1 start, 5 out of the course, past 40
   frames on the goal ground the team finishes (first one wins, a second one makes it a tie). */
void func_801075C8_196168_BobsledRun(omObjData* obj) {
    BRWork* work;

    work = obj->unk_50;
    if (work->unk_53 == 1) {
        D_8010C048_19ABE8_BobsledRun[work->unk_59].state = 0;
    } else if (work->unk_53 == 5) {
        D_8010C048_19ABE8_BobsledRun[work->unk_59].state = 2;
    } else if (D_8010C048_19ABE8_BobsledRun[work->unk_59].timer > 40) {
        D_8010C048_19ABE8_BobsledRun[work->unk_59].state = 3;
        if (D_8010BFF5_19AB95_BobsledRun == -1) {
            D_8010BFF5_19AB95_BobsledRun = work->unk_59;
        } else {
            D_8010BFF5_19AB95_BobsledRun = -2;
        }
        func_80079798_7A398(0x1FE, D_8010C048_19ABE8_BobsledRun[work->unk_59].player[1]);
        func_800797DC_7A3DC(0x111, D_8010C048_19ABE8_BobsledRun[work->unk_59].player[0]);
        func_800797DC_7A3DC(0x111, D_8010C048_19ABE8_BobsledRun[work->unk_59].player[1]);
    } else {
        D_8010C048_19ABE8_BobsledRun[work->unk_59].state = 1;
    }
}

/* Mean of the last six stick samples, packed (x << 16) | y. */
// register allocation (x/i swapped), as in MP1
#ifdef NON_MATCHING
s32 func_80107720_1962C0_BobsledRun(omObjData* obj) {
    s32 x;
    s32 y;
    u8 i;
    BRWork* work = obj->unk_50;

    y = 0;
    x = 0;
    for (i = 0; i < 6; i++) {
        /* host: the two halves of each sample are read by address (big-endian order) */
        x += ((s16*)&work->unk_74[i])[0];
        y += ((u16*)&work->unk_74[i])[1];
    }
    return (((s16)x / 6) << 16) | (((s16)y / 6) & 0xFFFF);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_80107720_1962C0_BobsledRun);
#endif

/* Boost rings: passing within 125 of one (at its height +-100) starts a 150-frame boost.
   Retail quirk kept: x and z are overwritten by the distance to each ring tested. */
void func_801077A4_196344_BobsledRun(omObjData* obj) {
    BRWork* work;
    f32 x;
    f32 y;
    f32 z;
    s32 i;

    work = obj->unk_50;
    x = obj->trans.x;
    y = obj->trans.y;
    z = obj->trans.z;
    for (i = 0; i < 3; i++) {
        if (D_8010C018_19ABB8_BobsledRun[i].y - 100.0f < y && y < D_8010C018_19ABB8_BobsledRun[i].y + 100.0f) {
            x = D_8010C018_19ABB8_BobsledRun[i].x - x;
            z = D_8010C018_19ABB8_BobsledRun[i].z - z;
            if (func_800B1830_B2430(x * x + z * z) < work->unk_48 + 125.0f) {
                if (D_8010C048_19ABE8_BobsledRun[work->unk_59].boost == 0) {
                    D_8010C048_19ABE8_BobsledRun[work->unk_59].boost = 150;
                    func_80079798_7A398(0x1FD, D_8010C048_19ABE8_BobsledRun[work->unk_59].player[1]);
                    break;
                }
            }
        }
    }
}

/* Speed limit, radius and field of view: boosted, or catching up when behind. */
// scheduling: retail computes both team offsets before the first progress load
#ifdef NON_MATCHING
void func_80107920_1964C0_BobsledRun(omObjData* obj) {
    BRWork* work;
    f32 add;
    f32 f;
    f32 mine;
    f32 other;
    s32 team;
    s32 o;

    work = obj->unk_50;
    add = 0.0f;
    func_801077A4_196344_BobsledRun(obj);
    o = work->unk_59 == 0;
    if ((mine = D_8010C048_19ABE8_BobsledRun[work->unk_59].progress) < (other = D_8010C048_19ABE8_BobsledRun[o].progress)
        && other - mine > 0.001f) {
        add = 5.0f;
    }
    team = work->unk_59;
    if (D_8010C048_19ABE8_BobsledRun[team].boost != 0) {
        f = 150 - D_8010C048_19ABE8_BobsledRun[team].boost;
        D_800BF7C0_C03C0 = f + 80.0f;
        work->unk_48 = f + 100.0f;
        D_8010C048_19ABE8_BobsledRun[work->unk_59].boost--;
        if (D_800BF7C0_C03C0 > 100.0f) {
            D_800BF7C0_C03C0 = 100.0f;
        }
        D_8010C040_19ABE0_BobsledRun[team] = work->unk_40;
        if (D_8010C040_19ABE0_BobsledRun[team] > 100.0f) {
            D_8010C040_19ABE0_BobsledRun[team] = 100.0f;
        }
        if (D_8010C040_19ABE0_BobsledRun[team] < 90.0f) {
            D_8010C040_19ABE0_BobsledRun[team] = 90.0f;
        }
        if (work->unk_48 > 120.0f) {
            work->unk_48 = 120.0f;
        }
        D_8010C048_19ABE8_BobsledRun[work->unk_59].unk32 = 1;
    } else {
        D_800BF7C0_C03C0 = (add + 80.0f < work->unk_40) ? work->unk_40 * 0.98f : add + 80.0f;
        if (work->unk_48 > 100.0f) {
            work->unk_48 = work->unk_48 * 0.98f;
        }
        if (work->unk_48 < add + 100.0f) {
            work->unk_48 = add + 100.0f;
        }
        D_8010C048_19ABE8_BobsledRun[work->unk_59].unk32 = 0;
        D_8010C040_19ABE0_BobsledRun[team] = D_8010C040_19ABE0_BobsledRun[team] * 0.9995f;
        if (D_8010C040_19ABE0_BobsledRun[team] < 90.0f) {
            D_8010C040_19ABE0_BobsledRun[team] = 90.0f;
        }
    }
    Hu3DCamSetPerspective(team, D_8010C040_19ABE0_BobsledRun[team], 20.0f, 12000.0f);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_80107920_1964C0_BobsledRun);
#endif

/* The sled's spray effect runs while boosted or in the air. */
void func_80107C6C_19680C_BobsledRun(omObjData* obj) {
    BRWork* work;

    work = obj->unk_50;
    if (D_8010C048_19ABE8_BobsledRun[work->unk_59].boost != 0 || work->unk_38 != 1000.0f) {
        func_80029E80_2AA80(obj->model[5], 2, 2);
    } else {
        func_80029E80_2AA80(obj->model[5], 2, 0);
    }
}

/* Turn by turn, glancing off walls the sled faces into. */
void func_80107CF4_196894_BobsledRun(omObjData* obj, Vec3f* normal, f32 turn) {
    BRWork* work;
    s32 team;
    f32 a;
    f32 s;

    work = obj->unk_50;
    team = work->unk_59;
    work->unk_3C = turn + work->unk_3C;
    a = work->unk_3C - 90.0f;
    s = HuMathSin(a);
    a = func_8000DA2C_E62C(normal->x, normal->z, s, func_800B7890_B8490(a)); /* the wall's dot */
    if (a > 0.7f) {
        turn += 1.0f;
        work->unk_3C = work->unk_3C - turn;
    } else if (a < -0.7f) {
        turn = fabs(turn) + 1.0;
        work->unk_3C = turn + work->unk_3C;
    }
    work->unk_3C = func_8002D958_2E558(work->unk_3C);
    D_8010C048_19ABE8_BobsledRun[team].unk08 = a;
}

BRGround* func_80107E38_1969D8_BobsledRun(BRWork* work) {
    BRGround* g;
    s32 i;

    if (work->unk_53 >= 0) {
        for (i = 0; i < D_800F8FE0_F9BE0; i++) {
            g = D_800FC7B0_FD3B0[i]->unk_50;
            if (work->unk_53 == g->unk_04) {
                return g;
            }
        }
    }
    return NULL;
}

/* The bobsled (D_800FFFD8[team]): steering, jumps, bumps, boosts and the team's camera. */
// register allocation (trans.y lives in a GPR in retail, z here), as MP1's func_800F78F4; calls, constants and fields checked against the asm
#ifdef NON_MATCHING
void func_80107EA4_196A44_BobsledRun(omObjData* obj) {
    s16 stkX;
    s16 stkY;
    BRWork* work;
    BRGround* gw;
    f32 x;
    f32 z;
    f32 accel;
    f32 turn;
    f32 dy;
    f32 v;
    f32 f;
    f32 r;
    f32 s2;
    f32 speed;
    f32 nx;
    f32 nz;
    f32 push;
    f32 sp;
    f32 roll;
    f32 cy;
    f32 back;
    f32 p;
    f32 t;
    s32 stick;
    s32 hit;
    u16 trg;
    u16 mdl0;
    u8 p0;
    u8 p1;
    s16 ground0;
    s32 a;
    u32 ust;
    u32 hi;
    f32 ny;
    f32 y;
    s16 ah;
    s8 team;

    accel = 0.0f;
    work = obj->unk_50;
    team = work->unk_59;
    x = obj->trans.x;
    y = obj->trans.y;
    z = obj->trans.z;
    func_8000776C_836C(obj);
    mdl0 = obj->model[0];
    D_80101308_101F08 = 0.0f;
    D_800F94A0_FA0A0 = 0.0f;
    D_800FD7FC_FE3FC = 0;
    stkX = stkY = 0;
    p0 = D_8010C048_19ABE8_BobsledRun[work->unk_59].port[0];
    p1 = D_8010C048_19ABE8_BobsledRun[work->unk_59].port[1];
    ground0 = work->unk_53;
    turn = 0.0f;
    if (D_800F8FD0_F9BD0 == 1 && !(work->unk_50 & 1)) {
        stick = (ContStkX[(s8)p0] + ContStkX[(s8)p1]) / 2;
        stkX = stick;
        stkY = (ContStkY[(s8)p0] + ContStkY[(s8)p1]) / 2;
        if (stick > 60) {
            stkX = 60;
        }
        if (stkY > 60) {
            stkY = 60;
        }
        if (stkX < -60) {
            stkX = -60;
        }
        if (stkY < -60) {
            stkY = -60;
        }
        func_8000CE80_DA80(&stkX, &stkY);
        if (!(work->unk_50 & 6)) {
            trg = ContBtnTrg[(s8)p1] | ContBtnTrg[(s8)p0];
        } else {
            trg = 0;
        }
    } else {
        stkX = stkY = 0;
        trg = 0;
    }
    func_80107920_1964C0_BobsledRun(obj);
    func_80107C6C_19680C_BobsledRun(obj);
    if (work->unk_38 != 1000.0f) {
        v = work->unk_38;
        if (D_800BF7D4_C03D4 < v) {
            v = D_800BF7D4_C03D4;
        }
        if (work->unk_38 >= 0.0f) {
            f = -35.0f;
        } else {
            f = 35.0f;
        }
        dy = v * v * f;
        ny = y + dy;
        if (!(work->unk_50 & 0x80)) {
            work->unk_38 += D_800BF7A8_C03A8;
            if (D_800BF7C0_C03C0 * 0.6f < work->unk_40) {
                work->unk_40 += -1.6f;
            }
        } else {
            work->unk_38 += 2.0f * D_800BF7A8_C03A8;
        }
        a = stkX;
        if (a < 0) {
            a = -a;
        }
        if (a >= 9) {
            if (work->unk_40 < D_800BF7C0_C03C0 / 3.0f) {
                turn = -(f32)stkX;
                f = 20.0f;
            } else if (work->unk_40 < D_800BF7C0_C03C0 / 2.0f) {
                turn = -(f32)stkX;
                f = 30.0f;
            } else {
                turn = -(f32)stkX;
                f = 40.0f;
            }
            turn = turn / f;
        }
        work->unk_3C = turn + work->unk_3C;
        s2 = work->unk_40 * work->unk_40;
        r = func_800B1830_B2430(s2);
        r = r / func_800B1830_B2430(s2 + dy * dy);
        if (r != 0.0f) {
            work->unk_4C = r * 0.9f;
        }
        y = func_8010B630_19A1D0_BobsledRun(obj, x, ny, z, y);
        func_801060E8_194C88_BobsledRun(obj, 0, 24.0f, work->unk_3C, x, y, z);
        if (work->unk_38 == 1000.0f) {
            if (!(work->unk_50 & 0x80)) {
                work->unk_38 = -D_800BF7A4_C03A4 * 0.5f;
                work->unk_50 |= 0x80;
            } else {
                work->unk_50 &= 0xFF7F;
                func_80019B9C_1A79C(obj, 0);
            }
            D_8010C048_19ABE8_BobsledRun[work->unk_59].timer = 0;
            PlaySound(0x1FB);
            omVibrate(D_8010C048_19ABE8_BobsledRun[work->unk_59].player[0], 2, 2, 20);
            omVibrate(D_8010C048_19ABE8_BobsledRun[work->unk_59].player[1], 2, 2, 20);
            work->unk_C6 = 0;
        } else {
            D_8010C048_19ABE8_BobsledRun[work->unk_59].timer++;
            work->unk_C6 = 0;
        }
    } else {
        work->unk_4C = 1.0f;
        stick = func_80019000_19C00(obj);
        D_8010C048_19ABE8_BobsledRun[work->unk_59].anim = 0;
        if (stick & 0x20) {
            D_8010C048_19ABE8_BobsledRun[work->unk_59].anim = 2;
            t = func_80029E3C_2AA3C(mdl0);
            if (t == -1.0f) {
                t = func_80029CE4_2A8E4(mdl0);
            }
            if (t > 44.0f) {
                func_800298A4_2A4A4(obj->model[0], 4, 4);
                obj->model[0] = D_8010C048_19ABE8_BobsledRun[work->unk_59].mdl[1];
                func_80019E04_1AA04(obj, 0x26, 0);
                func_80019B9C_1A79C(obj, 0);
                func_800298A4_2A4A4(obj->model[0], 4, 0);
                D_8010C048_19ABE8_BobsledRun[work->unk_59].anim = 3;
                func_80079798_7A398(0x1FF, D_8010C048_19ABE8_BobsledRun[work->unk_59].player[0]);
            }
        }
        ust = func_8000CDC8_D9C8(obj, stkX, stkY);
        hi = ust >> 16;
        if (D_8010CA20_19B5C0_BobsledRun[work->unk_59].y >= 0.0f) {
            if (D_8010C048_19ABE8_BobsledRun[work->unk_59].boost != 0) {
                work->unk_40 = 4.0f * D_8010CA20_19B5C0_BobsledRun[work->unk_59].y + work->unk_40;
            } else {
                work->unk_40 = work->unk_40 + D_8010CA20_19B5C0_BobsledRun[work->unk_59].y;
            }
        } else {
            work->unk_40 = D_8010CA20_19B5C0_BobsledRun[work->unk_59].y * 4.0f + work->unk_40;
        }
        if (D_8010C048_19ABE8_BobsledRun[work->unk_59].state == 0) {
            if (trg & 0x8000) {
                accel = 1.0f;
                if (func_80019B9C_1A79C(obj, 1) == 1) {
                    func_8000C610_D210(work, 1);
                }
                D_8010C048_19ABE8_BobsledRun[work->unk_59].anim = 1;
            }
        } else {
            if ((s16)ust >= 9) {
                accel = (s16)ust / 60.0f;
            } else if ((s16)ust < -8) {
                accel = (s16)ust / 48.0f;
            }
            if (D_8010C048_19ABE8_BobsledRun[work->unk_59].anim == 0) {
                D_8010C048_19ABE8_BobsledRun[work->unk_59].anim = 4;
            }
        }
        gw = func_80107E38_1969D8_BobsledRun(work);
        if (gw != NULL) {
            accel -= gw->unk_08;
        }
        work->unk_40 = accel + work->unk_40;
        if (D_800BF7C0_C03C0 < work->unk_40) {
            work->unk_40 = D_800BF7C0_C03C0;
        }
        if (work->unk_40 < 0.0f) {
            work->unk_40 = 0.0f;
        }
        if (D_8010C048_19ABE8_BobsledRun[work->unk_59].state != 0 &&
            D_8010C048_19ABE8_BobsledRun[work->unk_59].progress >= 0.005f) {
            if (work->unk_40 < D_800BF7C0_C03C0 / 3.0f) {
                turn = -(f32)(s16)hi;
                f = 15.0f;
            } else if (work->unk_40 < D_800BF7C0_C03C0 / 2.0f) {
                turn = -(f32)(s16)hi;
                f = 20.0f;
            } else {
                turn = -(f32)(s16)hi;
                f = 30.0f;
            }
            turn = turn / f;
            if (D_8010C048_19ABE8_BobsledRun[work->unk_59].state == 1 && D_8010BFF4_19AB94_BobsledRun == -1 &&
                work->unk_40 != 0.0f && D_800F8FD0_F9BD0 == D_8010C048_19ABE8_BobsledRun[work->unk_59].state) {
                if (D_8010C048_19ABE8_BobsledRun[work->unk_59].sound == -1) {
                    D_8010C048_19ABE8_BobsledRun[work->unk_59].sound = PlaySound(work->unk_59 + 0x202);
                }
                func_800796F0_7A2F0(D_8010C048_19ABE8_BobsledRun[work->unk_59].sound, work->unk_40 * 6.0f);
            }
        }
        func_80107CF4_196894_BobsledRun(obj, &work->unk_90, turn);
        t = func_8010AF5C_199AFC_BobsledRun(obj, work->unk_3C, x, y, z);
        if (t != 65536.0f) {
            y = t;
            ah = hi;
            if (ah < 0) {
                ah = -ah;
            }
            func_801060E8_194C88_BobsledRun(obj, ah, 24.0f, work->unk_3C, x, t, z);
            if ((ground0 != work->unk_53) & (ground0 == 1)) {
                func_80019CA4_1A8A4(obj, 6);
                D_8010C048_19ABE8_BobsledRun[work->unk_59].anim = 2;
                func_8000C584_D184(work, 3);
            }
        } else {
            work->unk_50 &= 0xFF7F;
            func_80079848_7A448(D_8010C048_19ABE8_BobsledRun[work->unk_59].sound);
            D_8010C048_19ABE8_BobsledRun[work->unk_59].sound = -1;
        }
    }
    speed = work->unk_40;
    if (work->unk_38 != 1000.0f) {
        speed = speed * work->unk_4C;
    }
    nx = x + (HuMathSin(work->unk_3C) * speed + D_800F94A0_FA0A0);
    nz = z + (func_800B7890_B8490(work->unk_3C) * speed + D_80101308_101F08);
    func_800B2060_B2C60(D_800FC834_FD434[obj->model[0]].mtx, 0.0f, work->unk_3C, 0.0f);
    func_800B2060_B2C60(D_800FC834_FD434[obj->model[5]].mtx, 0.0f, work->unk_3C, 0.0f);
    func_8002979C_2A39C(obj->model[5], obj->rot.x, obj->rot.y, obj->rot.z);
    func_800B2060_B2C60(D_800FC834_FD434[obj->model[6]].mtx, 0.0f, work->unk_3C, 0.0f);
    func_8002979C_2A39C(obj->model[6], obj->rot.x, obj->rot.y, obj->rot.z);
    if (work->unk_40 == D_800BF7D0_C03D0 || work->unk_38 != 1000.0f) {
        D_8010CA20_19B5C0_BobsledRun[work->unk_59].x = D_8010CA20_19B5C0_BobsledRun[work->unk_59].y =
            D_8010CA20_19B5C0_BobsledRun[work->unk_59].z = 0.0f;
    } else {
        D_8010CA20_19B5C0_BobsledRun[work->unk_59].x = obj->trans.x - nx;
        D_8010CA20_19B5C0_BobsledRun[work->unk_59].y = obj->trans.y - y;
        D_8010CA20_19B5C0_BobsledRun[work->unk_59].z = obj->trans.z - nz;
        func_8002D9AC_2E5AC(&D_8010CA20_19B5C0_BobsledRun[work->unk_59]);
    }
    func_8000C35C_CF5C(obj, nx, y, nz);
    func_80029714_2A314(obj->model[5], nx, y, nz);
    func_80029714_2A314(obj->model[6], nx, y, nz);
    push = func_800B1830_B2430(D_800F94A0_FA0A0 * D_800F94A0_FA0A0 + D_80101308_101F08 * D_80101308_101F08);
    if (push != 0.0f) {
        sp = work->unk_40;
        hit = 0;
        if (push < sp * 0.4f) {
            work->unk_40 = -push * 0.1f + sp;
        } else {
            hit = 1;
            if (push < sp * 0.8f) {
                work->unk_40 = -push * 0.15f + sp;
            } else {
                work->unk_40 = -push * 0.2f + work->unk_40;
                hit = 2;
            }
        }
        if (D_800F8FD0_F9BD0 == 1 && D_8010C048_19ABE8_BobsledRun[work->unk_59].unk41 == 0) {
            PlaySound(0x1FC);
            if (hit != 0) {
                if (hit == 1) {
                    goto shake;
                }
            } else {
                omVibrate(D_8010C048_19ABE8_BobsledRun[work->unk_59].player[0], 5, 0, 5);
                omVibrate(D_8010C048_19ABE8_BobsledRun[work->unk_59].player[1], 5, 0, 5);
            shake:
                omVibrate(D_8010C048_19ABE8_BobsledRun[work->unk_59].player[0], 2, 3, 10);
                omVibrate(D_8010C048_19ABE8_BobsledRun[work->unk_59].player[1], 2, 3, 10);
            }
            omVibrate(D_8010C048_19ABE8_BobsledRun[work->unk_59].player[0], 10, 0, 10);
            omVibrate(D_8010C048_19ABE8_BobsledRun[work->unk_59].player[1], 10, 0, 10);
        }
        D_8010C048_19ABE8_BobsledRun[work->unk_59].unk41++;
        if (D_8010C048_19ABE8_BobsledRun[work->unk_59].unk41 > 10) {
            D_8010C048_19ABE8_BobsledRun[work->unk_59].unk41 = 0;
        }
    } else {
        D_8010C048_19ABE8_BobsledRun[work->unk_59].unk41 = 0;
    }
    if (work->unk_59 == 0) {
        if (D_8010C0D0_19AC70_BobsledRun < push) {
            D_8010C0D0_19AC70_BobsledRun = push;
        }
    } else if (D_8010C0D4_19AC74_BobsledRun < push) {
        D_8010C0D4_19AC74_BobsledRun = push;
    }
    roll = func_80107550_1960F0_BobsledRun(work->unk_59, (f32)(func_80107720_1962C0_BobsledRun(obj) >> 16) / 60.0f * 15.0f *
                                                           (work->unk_40 / (D_800BF7C0_C03C0 * 0.7)));
    if (D_8010C048_19ABE8_BobsledRun[work->unk_59].timer < 30) {
        D_80102770_103370[work->unk_59].y = roll + work->unk_3C + 180.0f;
        D_8010C144_19ACE4_BobsledRun[work->unk_59] = roll * work->unk_40 * -0.003f;
        cy = 200.0f - (sp = work->unk_40);
        back = 2.0f * sp - D_8010C048_19ABE8_BobsledRun[work->unk_59].roll;
        D_801013B0_101FB0[work->unk_59].x = obj->trans.x - HuMathSin(roll + work->unk_3C) * back;
        D_801013B0_101FB0[work->unk_59].y = cy + obj->trans.y + 2.0f * D_8010C048_19ABE8_BobsledRun[work->unk_59].roll;
        D_801013B0_101FB0[work->unk_59].z = obj->trans.z - func_800B7890_B8490(roll + work->unk_3C) * back;
        D_800F94A8_FA0A8[work->unk_59] = work->unk_40 + 300.0f;
        r = D_8010C048_19ABE8_BobsledRun[work->unk_59].roll;
        if (r != 0.0f) {
            D_80102770_103370[work->unk_59].y = D_80102770_103370[work->unk_59].y + r;
            if (D_8010C048_19ABE8_BobsledRun[work->unk_59].state != 0) {
                D_8010C048_19ABE8_BobsledRun[work->unk_59].roll = D_8010C048_19ABE8_BobsledRun[work->unk_59].roll * 0.98f;
            }
        }
        if (work->unk_38 != 1000.0f) {
            D_80102770_103370[work->unk_59].x = 2.0f * work->unk_38 + D_80102770_103370[work->unk_59].x;
            if (D_80102770_103370[work->unk_59].x < 320.0f) {
                D_80102770_103370[work->unk_59].x = 320.0f;
            }
            if (D_80102770_103370[work->unk_59].x > 350.0f) {
                D_80102770_103370[work->unk_59].x = 350.0f;
            }
            D_801013B0_101FB0[work->unk_59].y = (200.0f - work->unk_40 * work->unk_38) + obj->trans.y;
        }
        p = 1.0 - (y + 8315.0f) / 21815.0f;
        if (D_8010C048_19ABE8_BobsledRun[work->unk_59].progress < p) {
            D_8010C048_19ABE8_BobsledRun[work->unk_59].progress = p;
        }
    } else if (D_8010C048_19ABE8_BobsledRun[work->unk_59].timer > 40) {
        obj->func_ptr = NULL;
        func_8001AA08_1B608(work->unk_59 != 0 ? D_8010CB40_19B6E0_BobsledRun : D_8010CC3E_19B7DE_BobsledRun, 0, 255, -5);
        func_8001AA08_1B608(D_8010C048_19ABE8_BobsledRun[team].sprite, 0, 255, -5);
        func_8001AA08_1B608(D_8010C048_19ABE8_BobsledRun[team].sprite2, 0, 255, -5);
        func_800298A4_2A4A4(D_8010C048_19ABE8_BobsledRun[team].mdl[0], 4, 4);
        func_800298A4_2A4A4(D_8010C048_19ABE8_BobsledRun[team].mdl[2], 4, 4);
        func_800298A4_2A4A4(D_8010C048_19ABE8_BobsledRun[team].mdl[1], 4, 4);
        func_800298A4_2A4A4(D_8010C048_19ABE8_BobsledRun[team].mdl[3], 4, 4);
        func_800298A4_2A4A4(obj->model[5], 4, 4);
        func_800298A4_2A4A4(obj->model[6], 4, 4);
        func_800298A4_2A4A4(obj->model[1], 4, 4);
        func_800298A4_2A4A4(obj->model[3], 4, 4);
        obj->model[3] = 0;
        D_8010C048_19ABE8_BobsledRun[work->unk_59].anim = 5;
        if (D_8010C0D8_19AC78_BobsledRun == 0) {
            espDispOn(D_8010CC3C_19B7DC_BobsledRun);
            func_8001A6BC_1B2BC(D_8010CC3C_19B7DC_BobsledRun, 2);
            func_8001AA08_1B608(D_8010CC3C_19B7DC_BobsledRun, 255, 0, 8);
            if (work->unk_59 == 0) {
                espPosSet(D_8010CC3C_19B7DC_BobsledRun, 0, 0);
            } else {
                espPosSet(D_8010CC3C_19B7DC_BobsledRun, 0, 120);
            }
            D_8010C0D8_19AC78_BobsledRun++;
        }
    }
    func_801075C8_196168_BobsledRun(obj);
    if (D_8010C048_19ABE8_BobsledRun[work->unk_59].state == 2) {
        work->unk_3C = 270.0f;
        obj->func_ptr = func_801064F0_195090_BobsledRun;
        D_8010C048_19ABE8_BobsledRun[work->unk_59].roll = 1.0f;
    }
    if (obj->func_ptr != NULL) {
        func_8010BD18_19A8B8_BobsledRun(obj, D_8010C048_19ABE8_BobsledRun[work->unk_59].player[0]);
        func_80106438_194FD8_BobsledRun(work->unk_59, obj->model[3]);
        func_80104EAC_193A4C_BobsledRun(obj);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_19_BobsledRun/1913A0", func_80107EA4_196A44_BobsledRun);
#endif

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
