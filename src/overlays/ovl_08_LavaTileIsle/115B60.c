#include "ovl_08.h"

void func_801046E0_115B60_LavaTileIsle(void) {
    s32 i;

    D_8010A4E3_11B963_LavaTileIsle = (rand8() * 3U) >> 5;
    func_8000C460_D060();
    D_800FC87A_FD47A = 0;
    for (i = 0; i < 4; i++) {
        omSetStatBit(D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(2, 0xD, 0x3C, -1, func_8010479C_115C1C_LavaTileIsle), 0xA0);
    }
}

void func_8010479C_115C1C_LavaTileIsle(omObjData* obj) {
    MgWork* w;
    s32 dir;
    s32 file;
    s32 i;
    s32 c;
    s32 attr;

    dir = D_800CD438_CE038[(s8)gPlayers[D_8010A200_11B680_LavaTileIsle[D_8010A4E2_11B962_LavaTileIsle]].character].unk_04;
    file = D_800CD438_CE038[(s8)gPlayers[D_8010A200_11B680_LavaTileIsle[D_8010A4E2_11B962_LavaTileIsle]].character].unk_08;
    c = D_8010A210_11B690_LavaTileIsle[D_8010A4E3_11B963_LavaTileIsle][D_8010A4E2_11B962_LavaTileIsle];
    obj->trans.x = D_8010A270_11B6F0_LavaTileIsle[c].x;
    obj->trans.y = D_8010A270_11B6F0_LavaTileIsle[c].y;
    obj->trans.z = D_8010A270_11B6F0_LavaTileIsle[c].z;
    obj->rot.x = obj->rot.y = obj->rot.z = 0.0f;
    obj->work[0] = 0;
    obj->work[1] = 0;
    func_8000C578_D178(1);
    func_8000C6FC_D2FC(obj, dir, file, (s16)D_8010A200_11B680_LavaTileIsle[D_8010A4E2_11B962_LavaTileIsle], 0x8D9, 0x8D9);
    w = obj->unk_50;
    func_8000E0C0_ECC0(w, 0, func_80108648_119AC8_LavaTileIsle);
    func_8000E0C0_ECC0(w, 6, func_80109E5C_11B2DC_LavaTileIsle);
    func_8000E0C0_ECC0(w, 7, func_80109E5C_11B2DC_LavaTileIsle);
    w->unk_3C = func_800B75A8_B81A8(-obj->trans.x, -obj->trans.z);
    attr = 0x88D;
    obj->model[3] = LoadFormFile(7, 0x88D);
    obj->model[4] = LoadFormFile(8, 0x88D);
    obj->model[6] = LoadFormFile(9, 0x88D);
    obj->model[5] = LoadFormFile(0xA, 0x88D);
    obj->model[7] = LoadFormFile(0xC, 0x88D);
    obj->model[8] = LoadFormFile(0xB, 0x88D);
    for (i = 0; i < 4; i++) {
        obj->model[9 + i] = LoadFormFile(0x180002, (u16)attr);
    }
    func_8002D1EC_2DDEC(obj->model[0], 1);
    func_8002D274_2DE74(obj->model[0], 0xFF, 0, 0);
    func_8002D2B4_2DEB4(obj->model[0], -10.0f, -17.0f, 69.0f);
    obj->func_ptr = func_80104C94_116114_LavaTileIsle;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
    func_8002979C_2A39C(obj->model[0], obj->rot.x, obj->rot.y, obj->rot.z);
    func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    func_8000C024_CC24(obj, 0, 2);
    func_8000C024_CC24(obj, 1, 2);
    func_80019F0C_1AB0C(obj, 0, dir, 1, 0);
    func_80019F0C_1AB0C(obj, 1, dir | 1, 1, 0);
    func_80019F0C_1AB0C(obj, 2, dir | 2, 1, 0);
    func_80019F0C_1AB0C(obj, 5, dir | 3, 0, 0);
    func_80019F0C_1AB0C(obj, 6, dir | 4, 1, 0x13);
    func_80019F0C_1AB0C(obj, 8, dir | 6, 1, 0x1D);
    func_80019F0C_1AB0C(obj, 0x12, dir | 0x10, 2, 0);
    func_80019F0C_1AB0C(obj, 0x13, dir | 0x11, 2, 0);
    func_80019F0C_1AB0C(obj, 0x11, dir | 0xF, 0, 0);
    func_80019F0C_1AB0C(obj, 0x15, dir | 0x2E, 0, 0);
    func_80019F0C_1AB0C(obj, 3, dir | 0x2C, 1, 0);
    func_80019F0C_1AB0C(obj, 4, dir | 0x2D, 1, 0);
    func_80019F0C_1AB0C(obj, 0x1E, dir | 0x2F, 0, 0);
    func_80019F0C_1AB0C(obj, 0x1F, dir | 0x30, 0, 0);
    func_80019E84_1AA84(obj, 0x20, dir | 0x31, 0, 0);
    func_80019F0C_1AB0C(obj, 0xD, dir | 0x4E, 1, 0x78);
    func_80019F0C_1AB0C(obj, 0xE, dir | 0x55, 1, 0x78);
    func_80019F0C_1AB0C(obj, 0x26, dir | 0x1C, 1, 0);
    func_80019B9C_1A79C(obj, 0);
    D_8010A4E2_11B962_LavaTileIsle++;
}

/* Register/schedule (class 4, masked 2): retail schedules the sll/sra after the array base. */
#ifdef NON_MATCHING
void func_80104C94_116114_LavaTileIsle(omObjData* obj) {
    MgWork* w;
    s8 p;
    s8 k;
    s8 n = 0;
    f32 x;
    f32 z;
    f32* a;

    if (func_80078EA8_79AA8() + D_80102720_103320 != 0) {
        return;
    }
    w = obj->unk_50;
    if (D_800F8FD0_F9BD0 == 0) {
        k = w->unk_57;
        ContStkY[k] = 0;
        ContStkX[k] = 0;
        k = w->unk_57;
        ContBtnTrg[k] = 0;
        ContBtn[k] = 0;
        obj->rot.y = 0.0f;
        w->unk_3C = func_800B75A8_B81A8(-obj->trans.x, -obj->trans.z);
        func_800B2060_B2C60(D_800FC834_FD434[obj->model[0]].mtx, 0.0f, w->unk_3C, 0.0f);
        func_80019B9C_1A79C(obj, 0);
        return;
    }
    if (D_800F8FD0_F9BD0 == 2 || D_800F8FD0_F9BD0 == 3) {
        if (D_8010A2A0_11B720_LavaTileIsle > 60) {
            func_80109F44_11B3C4_LavaTileIsle(obj);
        }
        D_8010A2A0_11B720_LavaTileIsle++;
    }
    if (obj->work[1] == 0 && obj->trans.y == -600.0f) {
        obj->work[1] = 1;
        omVibrate(w->unk_59, 0x14, 0, 0x14);
        D_8010A2BC_11B73C_LavaTileIsle[w->unk_59] = func_800797DC_7A3DC(0x111, w->unk_59);
        D_8010A4E0_11B960_LavaTileIsle = func_80079574_7A174() + 5;
        func_8007954C_7A14C(D_8010A4E0_11B960_LavaTileIsle);
    }
    p = w->unk_59;
    if (obj->work[1] == 1) {
        if (D_8010A2BC_11B73C_LavaTileIsle[p] == -1) {
            D_8010A2BC_11B73C_LavaTileIsle[w->unk_59] = func_800797DC_7A3DC(0x111, p);
        }
        func_80019B9C_1A79C(obj, 0x26);
        x = obj->trans.x;
        z = obj->trans.z;
        if (x > 0.0f) {
            obj->trans.x += 12.5;
        } else {
            obj->trans.x -= 12.5;
        }
        if (z > -0.0f) {
            obj->trans.z += 12.5;
        } else {
            obj->trans.z -= 12.5;
        }
        w->unk_3C = func_800B75A8_B81A8(obj->trans.x - x, obj->trans.z - z);
        a = &D_8010A2A4_11B724_LavaTileIsle[p];
        *a += 5.0f;
        if (*a >= 180.0f) {
            *a = 0.0f;
        }
        func_801052A8_116728_LavaTileIsle(obj);
    }
    if ((gPlayers[w->unk_59].flags & 1) && D_800F8FD0_F9BD0 == 1) {
        func_80105400_116880_LavaTileIsle(obj);
    }
    if (obj->trans.y < 0.0f) {
        w->unk_40 = 0.0f;
        k = w->unk_57;
        ContBtnTrg[k] = 0;
        ContStkY[k] = 0;
        ContStkX[k] = 0;
        func_80029714_2A314(obj->model[1], obj->trans.x, -590.0f, obj->trans.z);
    } else {
        func_80029714_2A314(obj->model[1], obj->trans.x, 25.0f, obj->trans.z);
    }
    func_80007790_8390(obj);
    if (obj->work[1] == 1) {
        obj->trans.y = HuMathSin(D_8010A2A4_11B724_LavaTileIsle[p]) * 250.0f + -600.0f;
    }
    if (D_8010A2B4_11B734_LavaTileIsle[w->unk_59] == 0 && obj->work[0] != 0) {
        D_8010A2B4_11B734_LavaTileIsle[w->unk_59] = 1;
        omVibrate(w->unk_59, 2, 3, 0xA);
        D_8010A2B8_11B738_LavaTileIsle[w->unk_59]++;
    } else if (obj->work[0] == 0 || D_8010A2B8_11B738_LavaTileIsle[w->unk_59] >= 10) {
        D_8010A2B4_11B734_LavaTileIsle[w->unk_59] = 0;
        D_8010A2B8_11B738_LavaTileIsle[w->unk_59] = 0;
    }
    if (obj->work[0] == 1) {
        func_80109E70_11B2F0_LavaTileIsle(obj, 0);
    } else if (obj->work[0] == 2) {
        func_80109E70_11B2F0_LavaTileIsle(obj, 1);
    }
    if (D_800F8FD0_F9BD0 == 1) {
        if (D_800FFFD8_100BD8[0]->work[1] == 1) {
            n++;
        }
        if (D_800FFFD8_100BD8[1]->work[1] == 1) {
            n++;
        }
        if (D_800FFFD8_100BD8[2]->work[1] == 1) {
            n++;
        }
        if (D_800FFFD8_100BD8[3]->work[1] == 1) {
            n++;
        }
        if (n >= 3) {
            func_8000C398_CF98();
        }
        if (_CheckFlag(0xC) != 0 && obj->work[1] == 1 && !(gPlayers[w->unk_59].flags & 1)) {
            func_8000C398_CF98();
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_80104C94_116114_LavaTileIsle);
#endif

/* Register/schedule (class 4, masked 2): retail schedules the sll after the array base. */
#ifdef NON_MATCHING
void func_801052A8_116728_LavaTileIsle(omObjData* obj) {
    s32* t;
    s32 i;
    s32 p;
    f32 s;

    p = ((MgWork*)obj->unk_50)->unk_59;
    i = 0;
    t = D_8010A2C4_11B744_LavaTileIsle[p];
    for (; i < 4; i++) {
        if (t[i] >= 0) {
            if (t[i] == 0) {
                func_80029714_2A314(obj->model[9 + i], obj->trans.x, obj->trans.y + 30.0f, obj->trans.z);
                func_800298A4_2A4A4(obj->model[9 + i], 4, 0);
            }
            if (t[i] < 8) {
                s = D_8010A304_11B784_LavaTileIsle[t[i] / 2];
                func_800297E8_2A3E8(obj->model[9], s, s, 1.0f); /* retail: always the first puff */
            }
            if (t[i] >= 8) {
                t[i] = -1;
            }
        }
        t[i]++;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_801052A8_116728_LavaTileIsle);
#endif

/* Control flow (class 3): retail shares the three call blocks by branches; the frame has 8 more bytes. */
#ifdef NON_MATCHING
void func_80105400_116880_LavaTileIsle(omObjData* obj) {
    MgWork* w;
    LTCpu* c;
    s32 port;
    s8 q;
    s32 b;

    if (obj->trans.y < 0.0f) {
        return;
    }
    w = obj->unk_50;
    port = w->unk_57;
    q = port;
    c = &D_8010A4E8_11B968_LavaTileIsle[port];
    func_801057C0_116C40_LavaTileIsle(obj, c);
    func_80105E34_1172B4_LavaTileIsle(&D_8010A315_11B795_LavaTileIsle, c);
    D_8010A314_11B794_LavaTileIsle = func_80105E80_117300_LavaTileIsle(c);
    c->time = D_8010A4E8_11B968_LavaTileIsle[port].time + 1;
    b = func_80019000_19C00(obj);
    ContStkY[port] = 0;
    ContStkX[port] = 0;
    ContBtnTrg[port] = 0;
    switch (gPlayers[w->unk_59].cpu_difficulty) {
    case 0:
        break;
    case 1:
        if (D_8010A4E8_11B968_LavaTileIsle[q].tile < 4 && D_8010A4E8_11B968_LavaTileIsle[q].tile != 2) {
            if (D_8010A614_11BA94_LavaTileIsle->work[0] != 1) {
                func_80108204_119684_LavaTileIsle(obj);
            }
        } else if (D_8010A610_11BA90_LavaTileIsle->work[0] != 1) {
            func_80108204_119684_LavaTileIsle(obj);
        }
        break;
    case 2:
        if (D_8010A4E8_11B968_LavaTileIsle[q].tile < 4 && D_8010A4E8_11B968_LavaTileIsle[q].tile != 2) {
            if (D_8010A614_11BA94_LavaTileIsle->work[0] != 1) {
                if (!(b & 0x20)) {
                    if ((s32)((rand8() * 5U) >> 7) < 5) {
                        func_80108204_119684_LavaTileIsle(obj);
                    } else {
                        func_80108388_119808_LavaTileIsle(obj);
                    }
                }
            } else if (!(b & 0x20)) {
                func_80108388_119808_LavaTileIsle(obj);
            }
        } else {
            if (D_8010A610_11BA90_LavaTileIsle->work[0] != 1) {
                if (!(b & 0x20)) {
                    if ((s32)((rand8() * 5U) >> 7) < 5) {
                        func_80108204_119684_LavaTileIsle(obj);
                    } else {
                        func_80108388_119808_LavaTileIsle(obj);
                    }
                }
            } else if (!(b & 0x20)) {
                func_80108388_119808_LavaTileIsle(obj);
            }
        }
        break;
    case 3:
        if (D_8010A4E8_11B968_LavaTileIsle[q].tile < 4 && D_8010A4E8_11B968_LavaTileIsle[q].tile != 2) {
            if (D_8010A614_11BA94_LavaTileIsle->work[0] == 1) {
                if (!(b & 0x220)) {
                    func_80108388_119808_LavaTileIsle(obj);
                }
            } else if (w->unk_38 == 1000.0f) {
                if ((s32)((rand8() * 5U) >> 7) < 8) {
                    func_80108388_119808_LavaTileIsle(obj);
                } else {
                    func_80108494_119914_LavaTileIsle(obj);
                }
            } else if (!(w->unk_50 & 8)) {
                func_80108494_119914_LavaTileIsle(obj);
            }
        } else if (D_8010A610_11BA90_LavaTileIsle->work[0] == 1) {
            if (!(b & 0x220)) {
                func_80108388_119808_LavaTileIsle(obj);
            }
        } else if (w->unk_38 == 1000.0f) {
            if ((s32)((rand8() * 5U) >> 7) < 8) {
                func_80108388_119808_LavaTileIsle(obj);
            } else {
                func_80108494_119914_LavaTileIsle(obj);
            }
        } else if (!(w->unk_50 & 8)) {
            func_80108494_119914_LavaTileIsle(obj);
        }
        break;
    }
    func_80107E3C_1192BC_LavaTileIsle(D_8010A314_11B794_LavaTileIsle, obj, D_8010A4E8_11B968_LavaTileIsle[q].tile);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_80105400_116880_LavaTileIsle);
#endif

/* Which of the nine squares (0-8, row by row) the player stands on: the moving tiles' states
   a (3 tiles) and b (4 tiles) decide which side of a gap counts. */
/* Control flow (class 3): retail tests the same cases in another order and sets the tile in one store (363 instructions here 393). */
#ifdef NON_MATCHING
void func_801057C0_116C40_LavaTileIsle(omObjData* obj, LTCpu* c) {
    s8 a = D_8010A614_11BA94_LavaTileIsle->work[1];
    s8 b = D_8010A610_11BA90_LavaTileIsle->work[1];

    if (obj->trans.z < -120.0f) {
        if (obj->trans.x < -120.0f) {
            if (a != 1) {
                c->tile = 0;
            } else if (obj->trans.x >= -150.0f) {
                c->tile = 1;
            } else if (obj->trans.z >= -150.0f) {
                c->tile = 3;
            } else {
                c->tile = 0;
            }
        } else if (obj->trans.x >= -120.0f && obj->trans.x < 120.0f) {
            if (a != 2) {
                c->tile = 1;
            } else if (obj->trans.x <= -90.0f) {
                c->tile = 0;
            } else if (b != 4 && obj->trans.x >= 90.0f) {
                c->tile = 2;
            } else {
                c->tile = (obj->trans.z >= -150.0f) ? 4 : 1;
            }
        } else if (obj->trans.x >= 120.0f) {
            if (b != 4) {
                c->tile = 2;
            } else if (a != 2 && obj->trans.x <= 150.0f) {
                c->tile = 1;
            } else {
                c->tile = (obj->trans.z >= -150.0f) ? 5 : 2;
            }
        }
    } else if (obj->trans.z >= -120.0f && obj->trans.z < 120.0f) {
        if (obj->trans.x < -120.0f) {
            if (a != 0) {
                c->tile = 3;
            } else if (obj->trans.x >= -150.0f) {
                c->tile = 4;
            } else if (obj->trans.z <= -90.0f) {
                c->tile = 0;
            } else if (b == 3) {
                c->tile = 3;
            } else {
                c->tile = (obj->trans.z >= 90.0f) ? 6 : 3;
            }
        } else if (obj->trans.x >= -120.0f && obj->trans.x < 120.0f) {
            if (a != 3) {
                c->tile = 4;
            } else if (obj->trans.x <= -90.0f) {
                c->tile = 3;
            } else if (b != 0 && obj->trans.x >= 90.0f) {
                c->tile = 5;
            } else if (obj->trans.z <= -90.0f) {
                c->tile = 1;
            } else if (b == 2) {
                c->tile = 4;
            } else {
                c->tile = (obj->trans.z >= 90.0f) ? 7 : 4;
            }
        } else if (obj->trans.x >= 120.0f) {
            if (b != 0) {
                c->tile = 5;
            } else if (a != 3 && obj->trans.x <= 150.0f) {
                c->tile = 4;
            } else if (obj->trans.z <= -90.0f) {
                c->tile = 2;
            } else {
                c->tile = (obj->trans.z >= 90.0f) ? 8 : 5;
            }
        }
    } else if (obj->trans.z >= 120.0f) {
        if (obj->trans.x < -120.0f) {
            if (b != 3) {
                c->tile = 6;
            } else if (obj->trans.x >= -150.0f) {
                c->tile = 7;
            } else if (a == 0) {
                c->tile = 6;
            } else {
                c->tile = (obj->trans.z <= 90.0f) ? 3 : 6;
            }
        } else if (obj->trans.x >= -120.0f && obj->trans.x < 120.0f) {
            if (b != 2) {
                c->tile = 7;
            } else if (obj->trans.x <= -90.0f) {
                c->tile = 6;
            } else if (obj->trans.x >= 90.0f) {
                c->tile = 8;
            } else if ((s8)a == 3) {
                c->tile = 7;
            } else {
                c->tile = (obj->trans.z <= 150.0f) ? 4 : 7;
            }
        } else if (obj->trans.x >= 120.0f) {
            if (b != 1) {
                c->tile = 8;
            } else if (obj->trans.x <= 150.0f) {
                c->tile = 7;
            } else if (obj->trans.z <= 150.0f) {
                c->tile = 5;
            } else {
                c->tile = 8;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_801057C0_116C40_LavaTileIsle);
#endif

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_80105E34_1172B4_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_80105E80_117300_LavaTileIsle);

s32 func_80105F6C_1173EC_LavaTileIsle(s8 prev) {
    s8 a = D_8010A614_11BA94_LavaTileIsle->work[2];
    s8 s = D_8010A614_11BA94_LavaTileIsle->work[0];

    if (prev != 3 && ((a == 0 && s == 2) || (a == 1 && (s == 3 || s == 4)) || a == 2 || (a == 3 && (s == 0 || s == 1)))) {
        return 3;
    }
    if (prev != 1 && ((a == 0 && (s == 0 || s == 1)) || (a == 2 && (s == 3 || s == 4)) || a == 3)) {
        return 2;
    }
    if ((a == 0 && s == 2) || (a == 1 && (s == 3 || s == 4)) || a == 2 || (a == 3 && (s == 0 || s == 1))) {
        return 3;
    }
    if ((a == 0 && (s == 0 || s == 1)) || (a == 2 && (s == 3 || s == 4)) || a == 3) {
        return 2;
    }
    return 0;
}

s32 func_80106120_1175A0_LavaTileIsle(s8 prev) {
    s8 a = D_8010A614_11BA94_LavaTileIsle->work[2];
    s8 b = D_8010A610_11BA90_LavaTileIsle->work[2];
    s8 s = D_8010A614_11BA94_LavaTileIsle->work[0];
    s8 t = D_8010A610_11BA90_LavaTileIsle->work[0];

    if (prev != 0 && ((a == 0 && LT_01(s)) || (a == 1 && s == 2) || (a == 2 && LT_34(s)) || a == 3)) {
        return 1;
    }
    if (prev != 4 && (a == 0 || (a == 1 && LT_01(s)) || (a == 3 && LT_34(s)))) {
        return 3;
    }
    if (prev != 2 && ((a == 0 || (a == 1 && LT_01(s)) || (a == 2 && LT_34(s)) || a == 3) && (b < 6 || (b == 6 && LT_01(t)) || (b == 7 && LT_34(t))))) {
        return 2;
    }
    if ((a == 0 && LT_01(s)) || (a == 1 && s == 2) || (a == 2 && LT_34(s)) || a == 3) {
        return 1;
    }
    if (a == 0 || (a == 1 && LT_01(s)) || (a == 3 && LT_34(s))) {
        return 3;
    }
    if ((a == 0 || (a == 1 && LT_01(s)) || (a == 2 && LT_34(s)) || a == 3) && (b < 6 || (b == 6 && LT_01(t)) || (b == 7 && LT_34(t)))) {
        return 2;
    }
    return 0;
}

s32 func_80106444_1178C4_LavaTileIsle(s8 prev) {
    s8 a = D_8010A614_11BA94_LavaTileIsle->work[2];
    s8 b = D_8010A610_11BA90_LavaTileIsle->work[2];
    s8 s = D_8010A614_11BA94_LavaTileIsle->work[0];
    s8 t = D_8010A610_11BA90_LavaTileIsle->work[0];

    if (prev != 1 && ((a == 0 || (a == 1 && LT_01(s)) || (a == 2 && LT_34(s)) || a == 3) && (b < 6 || (b == 6 && LT_01(t)) || (b == 7 && LT_34(t))))) {
        return 1;
    }
    if (prev != 5 && ((b >= 1 && b <= 4) || (b == 0 && LT_34(t)) || (b == 5 && LT_01(t)) || (b == 6 && t == 2))) {
        return 3;
    }
    if ((a == 0 || (a == 1 && LT_01(s)) || (a == 2 && LT_34(s)) || a == 3) && (b < 6 || (b == 6 && LT_01(t)) || (b == 7 && LT_34(t)))) {
        return 1;
    }
    if ((b >= 1 && b <= 4) || (b == 0 && LT_34(t)) || (b == 5 && LT_01(t)) || (b == 6 && t == 2)) {
        return 3;
    }
    return 0;
}

s32 func_801066D4_117B54_LavaTileIsle(s8 prev) {
    s8 a = D_8010A614_11BA94_LavaTileIsle->work[2];
    s8 b = D_8010A610_11BA90_LavaTileIsle->work[2];
    s8 s = D_8010A614_11BA94_LavaTileIsle->work[0];
    s8 t = D_8010A610_11BA90_LavaTileIsle->work[0];

    if (prev != 6 && (((a == 0 && LT_34(s)) || a == 1 || a == 2 || (a == 3 && LT_01(s))) && (!(b == 2 || b == 3) || (b == 2 && LT_01(t)) || (b == 3 && LT_34(t))))) {
        return 3;
    }
    if (prev != 0 && ((a == 1 && LT_34(s)) || a == 2 || (a == 3 && LT_01(s)))) {
        return 4;
    }
    if (prev != 4 && ((a == 0 && LT_34(s)) || a == 1 || (a == 2 && LT_01(s)) || (a == 3 && s == 2))) {
        return 2;
    }
    if (((a == 0 && LT_34(s)) || a == 1 || a == 2 || (a == 3 && LT_01(s))) && (!(b == 2 || b == 3) || (b == 2 && LT_01(t)) || (b == 3 && LT_34(t)))) {
        return 3;
    }
    if ((a == 1 && LT_34(s)) || a == 2 || (a == 3 && LT_01(s))) {
        return 4;
    }
    if ((a == 0 && LT_34(s)) || a == 1 || (a == 2 && LT_01(s)) || (a == 3 && s == 2)) {
        return 2;
    }
    return 0;
}

s32 func_801069D8_117E58_LavaTileIsle(s8 prev) {
    s8 a = D_8010A614_11BA94_LavaTileIsle->work[2];
    s8 b = D_8010A610_11BA90_LavaTileIsle->work[2];
    s8 s = D_8010A614_11BA94_LavaTileIsle->work[0];
    s8 t = D_8010A610_11BA90_LavaTileIsle->work[0];

    if (prev != 3 && ((a == 0 && LT_34(s)) || a == 1 || (a == 2 && LT_01(s)))) {
        return 1;
    }
    if (prev != 1 && (a == 0 || (a == 1 && LT_01(s)) || (a == 2 && s == 2) || (a == 3 && LT_34(s)))) {
        return 4;
    }
    if (prev != 5 && ((a == 0 || a == 1 || (a == 2 && LT_01(s)) || (a == 3 && LT_34(s))) && ((b >= 1 && b <= 4) || (b == 0 && LT_34(t)) || (b == 5 && LT_01(t)) || (b == 6 && LT_34(t)) || (b == 7 && LT_01(t))))) {
        return 2;
    }
    if (prev != 7 && ((a == 0 || a == 1 || (a == 2 && LT_01(s)) || (a == 3 && LT_34(s))) && (b == 0 || b >= 5 || (b == 1 && LT_01(t)) || (b == 2 && LT_34(t)) || (b == 3 && LT_01(t)) || (b == 4 && LT_34(t))))) {
        return 3;
    }
    if ((a == 0 && LT_34(s)) || a == 1 || (a == 2 && LT_01(s))) {
        return 1;
    }
    if (a == 0 || (a == 1 && LT_01(s)) || (a == 2 && s == 2) || (a == 3 && LT_34(s))) {
        return 4;
    }
    if ((a == 0 || a == 1 || (a == 2 && LT_01(s)) || (a == 3 && LT_34(s))) && ((b >= 1 && b <= 4) || (b == 0 && LT_34(t)) || (b == 5 && LT_01(t)) || (b == 6 && LT_34(t)) || (b == 7 && LT_01(t)))) {
        return 2;
    }
    if ((a == 0 || a == 1 || (a == 2 && LT_01(s)) || (a == 3 && LT_34(s))) && (b == 0 || b >= 5 || (b == 1 && LT_01(t)) || (b == 2 && LT_34(t)) || (b == 3 && LT_01(t)) || (b == 4 && LT_34(t)))) {
        return 3;
    }
    return 0;
}

s32 func_80106F2C_1183AC_LavaTileIsle(s8 prev) {
    s8 a = D_8010A614_11BA94_LavaTileIsle->work[2];
    s8 b = D_8010A610_11BA90_LavaTileIsle->work[2];
    s8 s = D_8010A614_11BA94_LavaTileIsle->work[0];
    s8 t = D_8010A610_11BA90_LavaTileIsle->work[0];

    if (prev != 2 && (b > 0 || b < 5 /* retail: always true */ || (b == 0 && LT_34(t)) || (b == 5 && LT_01(t)) || (b == 6 && LT_34(t)) || (b == 7 && t == 2))) {
        return 4;
    }
    if (prev != 4 && ((a == 0 || a == 1 || (a == 2 && LT_01(s)) || (a == 3 && LT_34(s))) && (b > 0 || b < 5 || (b == 0 && LT_34(t)) || (b == 5 && LT_01(t)) || (b == 6 && LT_34(t)) || (b == 7 && LT_01(t))))) {
        return 1;
    }
    if (prev != 8 && (b == 2 || b == 3 || (b == 1 && LT_34(t)) || (b == 4 && LT_01(t)) || (b == 5 && t == 2) || (b == 6 && LT_34(t)) || (b == 7 && LT_01(t)))) {
        return 3;
    }
    if (b > 0 || b < 5 /* retail: always true */ || (b == 0 && LT_34(t)) || (b == 5 && LT_01(t)) || (b == 6 && LT_34(t)) || (b == 7 && t == 2)) {
        return 4;
    }
    if ((a == 0 || a == 1 || (a == 2 && LT_01(s)) || (a == 3 && LT_34(s))) && (b > 0 || b < 5 || (b == 0 && LT_34(t)) || (b == 5 && LT_01(t)) || (b == 6 && LT_34(t)) || (b == 7 && LT_01(t)))) {
        return 1;
    }
    if (b == 2 || b == 3 || (b == 1 && LT_34(t)) || (b == 4 && LT_01(t)) || (b == 5 && t == 2) || (b == 6 && LT_34(t)) || (b == 7 && LT_01(t))) {
        return 3;
    }
    return 0;
}

s32 func_80107414_118894_LavaTileIsle(s8 prev) {
    s8 a = D_8010A614_11BA94_LavaTileIsle->work[2];
    s8 b = D_8010A610_11BA90_LavaTileIsle->work[2];
    s8 s = D_8010A614_11BA94_LavaTileIsle->work[0];
    s8 t = D_8010A610_11BA90_LavaTileIsle->work[0];

    if (prev != 7 && (b == 0 || b >= 5 || (b == 1 && LT_01(t)) || (b == 2 && t == 2) || (b == 4 && LT_34(t)))) {
        return 2;
    }
    if (prev != 3 && (((a == 0 && LT_34(s)) || a == 1 || a == 2 || (a == 3 && LT_01(s))) && (!(b == 2 || b == 3) || (b == 2 && LT_01(t)) || (b == 3 && LT_34(t))))) {
        return 4;
    }
    if (b == 0 || b >= 5 || (b == 1 && LT_01(t)) || (b == 2 && t == 2) || (b == 4 && LT_34(t))) {
        return 2;
    }
    if (((a == 0 && LT_34(s)) || a == 1 || a == 2 || (a == 3 && LT_01(s))) && (!(b == 2 || b == 3) || (b == 2 && LT_01(t)) || (b == 3 && LT_34(t)))) {
        return 4;
    }
    return 0;
}

s32 func_80107694_118B14_LavaTileIsle(s8 prev) {
    s8 a = D_8010A614_11BA94_LavaTileIsle->work[2];
    s8 b = D_8010A610_11BA90_LavaTileIsle->work[2];
    s8 s = D_8010A614_11BA94_LavaTileIsle->work[0];
    s8 t = D_8010A610_11BA90_LavaTileIsle->work[0];

    if (prev != 8 && (b >= 6 || (b == 0 && LT_01(t)) || (b == 1 && t == 2) || (b == 2 && LT_34(t)) || (b == 3 && LT_01(t)) || (b == 5 && LT_34(t)))) {
        return 2;
    }
    if (prev != 4 && ((a == 0 || a == 1 || (a == 2 && LT_01(s)) || (a == 3 && LT_34(s))) && (b == 0 || b >= 5 || (b == 1 && LT_01(t)) || (b == 2 && LT_34(t)) || (b == 3 && LT_01(t)) || (b == 4 && LT_34(t))))) {
        return 4;
    }
    if (prev != 6 && (b == 0 || b >= 5 || (b == 1 && LT_01(t)) || (b == 3 && t == 2) || (b == 4 && LT_34(t)))) {
        return 1;
    }
    if (b >= 6 || (b == 0 && LT_01(t)) || (b == 1 && t == 2) || (b == 2 && LT_34(t)) || (b == 3 && LT_01(t)) || (b == 5 && LT_34(t))) {
        return 2;
    }
    if ((a == 0 || a == 1 || (a == 2 && LT_01(s)) || (a == 3 && LT_34(s))) && (b == 0 || b >= 5 || (b == 1 && LT_01(t)) || (b == 2 && LT_34(t)) || (b == 3 && LT_01(t)) || (b == 4 && LT_34(t)))) {
        return 4;
    }
    if (b == 0 || b >= 5 || (b == 1 && LT_01(t)) || (b == 3 && t == 2) || (b == 4 && LT_34(t))) {
        return 1;
    }
    return 0;
}

s32 func_80107B24_118FA4_LavaTileIsle(s8 prev) {
    s8 b = D_8010A610_11BA90_LavaTileIsle->work[2];
    s8 t = D_8010A610_11BA90_LavaTileIsle->work[0];

    if (prev != 5 && (b == 2 || b == 3 || (b == 0 && t == 2) || (b == 1 && LT_34(t)) || (b == 4 && LT_01(t)) || (b == 6 && LT_34(t)) || (b == 7 && LT_01(t)))) {
        return 4;
    }
    if (prev != 7 && (b >= 6 || (b == 0 && LT_01(t)) || (b == 2 && LT_34(t)) || (b == 3 && LT_01(t)) || (b == 4 && t == 2) || (b == 5 && LT_34(t)))) {
        return 1;
    }
    if (b == 2 || b == 3 || (b == 0 && t == 2) || (b == 1 && LT_34(t)) || (b == 4 && LT_01(t)) || (b == 6 && LT_34(t)) || (b == 7 && LT_01(t))) {
        return 4;
    }
    if (b >= 6 || (b == 0 && LT_01(t)) || (b == 2 && LT_34(t)) || (b == 3 && LT_01(t)) || (b == 4 && t == 2) || (b == 5 && LT_34(t))) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_80107E3C_1192BC_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_801081C4_119644_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_80108204_119684_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_80108388_119808_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_80108494_119914_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_80108648_119AC8_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_801095BC_11AA3C_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_80109E5C_11B2DC_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_80109E70_11B2F0_LavaTileIsle);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_08_LavaTileIsle/115B60", func_80109F44_11B3C4_LavaTileIsle);
