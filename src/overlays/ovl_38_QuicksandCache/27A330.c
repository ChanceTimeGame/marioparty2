#include "ovl_38.h"

__asm__(".section .rodata");
const char D_80107800_27F330_QuicksandCache[16] = "\202r\202s\202`\202q\202s";

void func_80102800_27A330_QuicksandCache(void) {
    s16 i;
    s16 j;
    s8 a;
    s8 b;
    s8 t;

    for (i = 0; i < 4; i++) {
        if (gPlayers[i].group == 0) {
            break;
        }
    }
    switch (i) {
    case 1:
        D_80108024_27FB54_QuicksandCache[0] = 1;
        break;
    case 2:
        D_80108024_27FB54_QuicksandCache[0] = 2;
        break;
    case 3:
        D_80108024_27FB54_QuicksandCache[0] = 3;
        break;
    case 0:
    default:
        D_80108024_27FB54_QuicksandCache[0] = 0;
        break;
    }
    i = 1;
    j = 0;
    for (; i < 4; i++) {
        if (D_80108024_27FB54_QuicksandCache[0] == j) {
            j++;
        }
        D_80108024_27FB54_QuicksandCache[i] = j;
        j++;
    }
    for (i = 0; i < 10; i++) {
        a = guRandom() % 3 + 1;
        b = guRandom() % 3 + 1;
        t = D_80108024_27FB54_QuicksandCache[a];
        D_80108024_27FB54_QuicksandCache[a] = D_80108024_27FB54_QuicksandCache[b];
        D_80108024_27FB54_QuicksandCache[b] = t;
    }
    func_8002D4D0_2E0D0(0xA);
    func_8002F290_2FE90(D_800F9D30_FA930, 0x40);
    func_80020D20_21920(0x40);
    omInitObjMan(0x1E, 0);
    i = 0;
    func_80079128_79D28();
    func_8000C460_D060();
    func_8000C578_D178(1);
    func_80020070_20C70(1);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_80079E60_7AA60), 0xA0);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 22.2f, 80.0f, 8000.0f);
    func_8002C59C_2D19C(0x800, 0x990, 0x40, 0x40, 0x40);
    func_80106780_27E2B0_QuicksandCache(1000.0f, -58.0f, 0.0f, 0.0f, 0.0f, 2180.0f, 1200.0f);
    func_80026DAC_279AC(1, 0x60, 0x40, 0x40);
    func_80026E00_27A00(1, -8.0f, -36.0f, 114.0f);
    func_8000C38C_CF8C();
    func_8000C3C8_CFC8();
    func_8007273C_7333C((u8*)D_80107800_27F330_QuicksandCache, 1);
    D_800F8FE0_F9BE0 = 0;
    func_8000C018_CC18(0);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(5, 2, 0, -1, func_80106E68_27E998_QuicksandCache);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(5, 2, 0, -1, func_80106F14_27EA44_QuicksandCache);
    D_80108034_27FB64_QuicksandCache = omAddObj(4, 6, 0, -1, func_80106CC0_27E7F0_QuicksandCache);
    omSetStatBit(D_80108034_27FB64_QuicksandCache, 0xA0);
    D_800FC87A_FD47A = 0;
    D_80108020_27FB50_QuicksandCache = omAddObj(4, 5, 0x27, -1, func_80102EB4_27A9E4_QuicksandCache);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(5, 9, 0x27, -1, func_80102F28_27AA58_QuicksandCache);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(5, 9, 0x27, -1, func_80103028_27AB58_QuicksandCache);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(5, 9, 0x27, -1, func_80103134_27AC64_QuicksandCache);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = D_80108020_27FB50_QuicksandCache;
    D_800FA606_FB206 = 0;
    do {
        D_800F9CE0_FA8E0[D_800FA606_FB206++] = omAddObj(2, 4, 2, -1, func_80106040_27DB70_QuicksandCache);
        i++;
    } while (i < 4);
    D_800F9CE0_FA8E0[D_800FA606_FB206++] = omAddObj(2, 4, 2, -1, func_8010609C_27DBCC_QuicksandCache);
    omAddObj(4, 6, 6, -1, func_8010568C_27D1BC_QuicksandCache);
    func_8010773C_27F26C_QuicksandCache();
    omAddObj(0, 0, 0, -1, func_801067C0_27E2F0_QuicksandCache);
    omAddObj(0x14, 0, 0, -1, func_80104EA8_27C9D8_QuicksandCache);
    InitFadeIn(0, 0x10);
}

void func_80102EB4_27A9E4_QuicksandCache(omObjData* obj) {
    s32 c = gPlayers[D_80108024_27FB54_QuicksandCache[0]].character;
    s32 dir = D_800CD438_CE038[c].unk_04;
    s32 file = D_800CD438_CE038[c].unk_08;

    func_80104B90_27C6C0_QuicksandCache(obj, dir, file, D_80108024_27FB54_QuicksandCache[0], 0.0f, 0.0f, 0.0f);
}

void func_80102F28_27AA58_QuicksandCache(omObjData* obj) {
    s32 c = gPlayers[D_80108024_27FB54_QuicksandCache[1]].character;
    s32 dir = D_800CD438_CE038[c].unk_04;
    s32 file = D_800CD438_CE038[c].unk_08;
    f32 x = HuMathSin(0.0f) * -500.0f;

    func_80103FF4_27BB24_QuicksandCache(obj, dir, file, D_80108024_27FB54_QuicksandCache[1], x, 2000.0f,
                                        func_800B7890_B8490(0.0f) * 500.0f, 0);
}

void func_80103028_27AB58_QuicksandCache(omObjData* obj) {
    s32 c = gPlayers[D_80108024_27FB54_QuicksandCache[2]].character;
    s32 dir = D_800CD438_CE038[c].unk_04;
    s32 file = D_800CD438_CE038[c].unk_08;
    f32 x = HuMathSin(120.0f) * -500.0f;

    func_80103FF4_27BB24_QuicksandCache(obj, dir, file, D_80108024_27FB54_QuicksandCache[2], x, 2000.0f,
                                        func_800B7890_B8490(120.0f) * 500.0f, 1);
}

void func_80103134_27AC64_QuicksandCache(omObjData* obj) {
    s32 c = gPlayers[D_80108024_27FB54_QuicksandCache[3]].character;
    s32 dir = D_800CD438_CE038[c].unk_04;
    s32 file = D_800CD438_CE038[c].unk_08;
    f32 x = HuMathSin(240.0f) * -500.0f;

    func_80103FF4_27BB24_QuicksandCache(obj, dir, file, D_80108024_27FB54_QuicksandCache[3], x, 2000.0f,
                                        func_800B7890_B8490(240.0f) * 500.0f, 2);
}

void func_80103240_27AD70_QuicksandCache(omObjData* obj) {
    MgWork* w = obj->unk_50;
    QCWork* q = w->unk_158;

    if (q->unk_00 == 0) {
        q->unk_00 = 1;
        func_800797DC_7A3DC(0x111, w->unk_59);
        func_80029B80_2A780(obj->model[0], obj->motion[0x26]);
        func_80029E80_2AA80(obj->model[0], 2, 2);
        func_800298A4_2A4A4(obj->model[1], 4, 4);
    }
    obj->trans.y -= 4.0f;
    obj->rot.y += 20.0f;
    if (obj->trans.y < -300.0f) {
        func_800298A4_2A4A4(obj->model[0], 4, 4);
        obj->func_ptr = NULL;
    }
}

void func_80103328_27AE58_QuicksandCache(omObjData* obj) {
    MgWork* w = obj->unk_50;
    QCWork* q = w->unk_158;
    QCSand* sand = D_80108034_27FB64_QuicksandCache->unk_50;
    f32 x = obj->trans.x;
    f32 z = obj->trans.z;
    f32 dist = q->unk_28;
    s8 ring = q->unk_34;
    f32 ang;
    f32 c;
    f32 s;
    f32 div;
    f32 limit;
    f32 t;
    f32 u;
    f32* m;

    ContBtn[w->unk_57] = 0;
    ContBtnTrg[w->unk_57] = 0;
    if (w->unk_38 == 1000.0f) {
        ang = -sand->unk_18[ring];
        c = func_800B7890_B8490(ang);
        c = c * obj->trans.x + -HuMathSin(ang) * obj->trans.z;
        s = HuMathSin(ang);
        s = s * obj->trans.x + func_800B7890_B8490(ang) * obj->trans.z;
        obj->trans.x = c;
        obj->trans.z = s;
        w->unk_3C -= ang;
        if (w->unk_3C < 0.0f) {
            w->unk_3C += 360.0f;
        } else if (w->unk_3C >= 360.0f) {
            w->unk_3C -= 360.0f;
        }
        div = dist / 700.0f;
        u = div;
        if (div > 1.0f) {
            u = 1.0f;
        }
        div = (1.0f - u) * 5.0f;
        if (div < 1.0f) {
            div = 1.0f;
        }
        if (gPlayers[w->unk_59].flags & 1) {
            switch (gPlayers[w->unk_59].cpu_difficulty) {
            case 0:
                limit = 2.1000001f;
                break;
            case 1:
                limit = 1.9999999f;
                break;
            case 2:
                limit = 1.8f;
                break;
            case 3:
                limit = 1.6f;
                break;
            }
            if (limit < div) {
                div = limit;
            }
        }
        ContStkX[w->unk_57] = ContStkX[w->unk_57] / (div + 0.5);
        ContStkY[w->unk_57] = ContStkY[w->unk_57] / (div + 0.5);
        q->unk_1C.y -= 2.0f;
        t = 1.0f - dist / 700.0f;
        t = t < 0.0f ? 0.0f : t;
        if (q->unk_1C.y < t * -100.0f) {
            q->unk_1C.y = t * -100.0f;
        }
        if (D_80107776_27F2A6_QuicksandCache == 5) {
            t = 1.0f - dist / 700.0f;
            t = t < 0.0f ? 0.0f : t;
            obj->trans.x -= x / dist * 2.9f * t;
            obj->trans.z -= z / dist * 2.9f * t;
        }
        q->unk_2C = (1.0f - t) * 1.2f;
        if (D_80107776_27F2A6_QuicksandCache == 5) {
            if (dist < 210.0f) {
                omVibrate(w->unk_59, 0x14, 0, 0x14);
                obj->func_ptr = func_80103240_27AD70_QuicksandCache;
                return;
            }
        }
    } else {
        q->unk_1C.y = 0.0f;
    }
    D_800BF7A4_C03A4 = q->unk_2C;
    if (D_80107777_27F2A7_QuicksandCache == 1) {
        func_80007790_8390(obj);
        m = (f32*)D_800FC834_FD434[obj->model[0]].mtx;
        func_800B6340_B6F40((void*)m, &q->unk_1C, (void*)m);
    } else {
        func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
        func_800B3E20_B4A20(D_800FC834_FD434[obj->model[0]].mtx, &q->unk_1C);
    }
}

#ifdef NON_MATCHING
/* Logic complete; retail keeps w in s1 and goal in s2, and loads unk_30 before the -30.0f. */
void func_801038D0_27B400_QuicksandCache(omObjData* obj) {
    MgWork* w = obj->unk_50;
    QCWork* q = w->unk_158;
    QCSand* sand = D_80108034_27FB64_QuicksandCache->unk_50;
    f32 x = obj->trans.x;
    f32 z = obj->trans.z;
    f32 dist;
    s8 ring;
    u8 s32_;
    u8 s31_;
    u16 s38;
    u16 s3A;
    u16 s3C;
    u16 s48;
    f32 margin;
    f32 range;
    f32 best6;
    f32 best3;
    s8 i6;
    s8 i3;
    s8 i;
    s8 goal;
    s8 target;
    omObjData* other;
    QCActor* a;
    f32 dx;
    f32 dz;
    f32 d2;
    f32 len;
    f32 stop;
    s8 side;
    s32 has3;
    s32 has6;
    f32 ang;
    f32 c;
    f32 s;

    dist = func_800B1830_B2430(x * x + z * z);
    q->unk_28 = dist;
    if (dist > 420.0f) {
        ring = 0;
    } else {
        ring = 0;
        if (dist > 260.0f) {
            ring = 1;
        }
    }
    s32_ = q->unk_32;
    s38 = q->unk_38;
    s3A = q->unk_3A;
    s31_ = q->unk_31;
    s3C = q->unk_3C;
    s48 = q->unk_48;
    if ((gPlayers[w->unk_59].flags & 1) && D_80107776_27F2A6_QuicksandCache == 5) {
        ContStkX[w->unk_57] = 0;
        ContStkY[w->unk_57] = 0;
        ContBtn[w->unk_57] = 0;
        ContBtnTrg[w->unk_57] = 0;
        switch (gPlayers[w->unk_59].cpu_difficulty) {
        case 0:
            margin = 70.0f;
            range = 200.0f;
            break;
        case 1:
            margin = 50.0f;
            range = 300.0f;
            break;
        case 2:
            margin = 40.0f;
            range = 500.0f;
            break;
        case 3:
            margin = 30.0f;
            range = 1000.0f;
            break;
        default:
            margin = 0.0f;
            range = 0.0f;
            break;
        }
        best3 = 490000.0f;
        best6 = 490000.0f;
        i6 = -1;
        i3 = -1;
        for (i = 0; i < 5; i++) {
            other = D_800F9CE0_FA8E0[i];
            a = other->unk_50;
            if (a->unk_54 == 1) {
                dx = other->trans.x - x;
                dz = other->trans.z - z;
                d2 = dx * dx + dz * dz;
                if (!(range * range < d2) && !(z * other->trans.x + -x * other->trans.z < 0.0f)) {
                    if (a->unk_52 == 6) {
                        if (d2 <= best6) {
                            if (other->trans.x * other->trans.x + other->trans.z * other->trans.z >
                                (margin + 260.0f) * (margin + 260.0f)) {
                                i6 = i;
                                best6 = d2;
                            }
                        }
                    } else {
                        if (d2 <= best3) {
                            dx = other->trans.x;
                            dz = other->trans.z;
                            if (dx * dx + dz * dz > (margin + 310.0f) * (margin + 310.0f)) {
                                i3 = i;
                                best3 = d2;
                            }
                        }
                    }
                }
            }
        }
        if (dist < margin + 260.0f) {
            goal = 4;
            if (guRandom() & 1) {
                q->unk_30 = 0;
            } else {
                q->unk_30 = 1;
            }
        } else {
            has3 = i3 > 0;
            has6 = i6 > 0;
            if (has3 | has6) {
                if (has3 & has6) {
                    target = i6;
                    if (best6 < best3) {
                        goto chase;
                    }
                    goal = 1;
                    if (best3 < 40000.0f) {
                        target = i3;
                    }
                } else {
                    target = i3;
                    if (i6 > 0) {
                        target = i6;
                    }
                chase:
                    goal = 1;
                }
            } else {
                goal = 3;
            }
        }
        switch (goal) {
        case 3:
            side = q->unk_30;
            ang = -30.0f;
            if (side == 0) {
                ang = 30.0f;
            }
            ang -= sand->unk_18[ring];
            c = func_800B7890_B8490(ang);
            dx = x * c + z * -HuMathSin(ang);
            s = HuMathSin(ang);
            dz = x * s + z * func_800B7890_B8490(ang);
            len = func_800B1830_B2430(dx * dx + dz * dz);
            if (len > 0.0f) {
                dx /= len;
                dz /= len;
                dx *= 620.0f;
                dz *= 620.0f;
            }
            dx -= x;
            dz -= z;
            d2 = func_800B1830_B2430(dx * dx + dz * dz);
            stop = 20.0f;
            goto steer;
        case 4:
            if (dist > 0.0f) {
                dx = x / dist;
                dz = z / dist;
                goto set;
            }
            break;
        case 1:
            other = D_800F9CE0_FA8E0[target];
            dx = other->trans.x - x;
            dz = other->trans.z - z;
            d2 = func_800B1830_B2430(dx * dx + dz * dz);
            stop = 0.0f;
        steer:
            if (stop < d2) {
                dx /= d2;
                dz /= d2;
            set:
                q->unk_35 = dx * 70.0f;
                q->unk_36 = -dz * 70.0f;
            }
            break;
        case 0:
        default:
            break;
        }
        q->unk_32 = s32_;
        q->unk_33 = goal;
        q->unk_38 = s38;
        q->unk_34 = ring;
        q->unk_31 = s31_;
        q->unk_3A = s3A;
        q->unk_3C = s3C;
        q->unk_48 = s48;
        ContStkX[w->unk_57] = q->unk_35;
        ContStkY[w->unk_57] = q->unk_36;
    }
    func_80103328_27AE58_QuicksandCache(obj);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_38_QuicksandCache/27A330", func_801038D0_27B400_QuicksandCache);
#endif

void func_80103FF4_27BB24_QuicksandCache(omObjData* obj, s32 dir, s32 file, u16 player, f32 x, f32 y, f32 z, s32 unused) {
    MgWork* w;
    void* p;
    QCWork* q;
    s8 i;

    func_8000C6FC_D2FC(obj, dir, file, player, 0x20AB9, 0x63D);
    w = obj->unk_50;
    p = func_80027154_27D54(0x5C, 0x7918);
    w->unk_158 = p;
    func_800B0EF0_B1AF0(p, 0, 0x5C);
    q = w->unk_158;
    q->unk_00 = 0;
    q->unk_01 = 0;
    q->unk_02 = 0;
    q->unk_1C.x = 0.0f;
    q->unk_1C.y = 0.0f;
    q->unk_1C.z = 0.0f;
    q->unk_28 = 0.0f;
    q->unk_2C = 1.47f;
    if (guRandom() & 1) {
        q->unk_30 = 0;
    } else {
        q->unk_30 = 1;
    }
    q->unk_32 = 0;
    q->unk_33 = 0;
    q->unk_38 = 0;
    q->unk_31 = 0;
    q->unk_3A = 0;
    q->unk_3C = 0;
    q->unk_34 = 0;
    q->unk_35 = 0;
    q->unk_36 = 0;
    q->unk_40 = 0;
    q->unk_44 = 0;
    q->unk_48 = 0;
    for (i = 0; i < 4; i++) {
        q->unk_4A[i] = 0;
        q->unk_52[i] = 0;
    }
    for (i = 0; i < 3; i++) {
        q->unk_10[i] = 0;
        q->unk_04[i] = 0;
    }
    w->unk_3C = 0.0f;
    D_800BF7EC_C03EC[w->unk_59][0] = 0x2D2;
    obj->model[3] = LoadFormFile(7, 0x88D);
    obj->model[4] = LoadFormFile(8, 0x88D);
    obj->model[6] = LoadFormFile(9, 0x88D);
    obj->model[5] = LoadFormFile(0xA, 0x88D);
    obj->model[7] = LoadFormFile(0xC, 0x88D);
    obj->model[8] = LoadFormFile(0xB, 0x88D);
    func_8001A12C_1AD2C(obj, 0, dir, 1, 0, 0);
    func_8001A12C_1AD2C(obj, 1, dir | 1, 1, 0, 2);
    func_8001A12C_1AD2C(obj, 2, dir | 2, 1, 0, 3);
    func_80019F0C_1AB0C(obj, 6, dir | 4, 1, 0x13);
    func_80019F0C_1AB0C(obj, 9, dir | 7, 1, 0x27);
    func_80019F0C_1AB0C(obj, 0x10, dir | 0xE, 1, 0);
    func_80019F0C_1AB0C(obj, 0x11, dir | 0xF, 1, 0xF);
    func_80019F0C_1AB0C(obj, 0x12, dir | 0x10, 2, 0);
    func_80019F0C_1AB0C(obj, 0x13, dir | 0x11, 2, 0);
    func_80019F0C_1AB0C(obj, 0xA, dir | 0x12, 1, 0x27);
    func_80019E84_1AA84(obj, 0x15, dir | 0x2E, 0, 0);
    func_80019E84_1AA84(obj, 3, dir | 0x2C, 1, 0);
    func_80019E84_1AA84(obj, 4, dir | 0x2D, 1, 0);
    func_80019E84_1AA84(obj, 0x1E, dir | 0x2F, 2, 0);
    func_80019E84_1AA84(obj, 0x1F, dir | 0x30, 2, 0);
    func_80019E84_1AA84(obj, 0x20, dir | 0x31, 0, 0);
    func_80019E84_1AA84(obj, 0x21, dir | 0x32, 2, 0);
    func_80019E84_1AA84(obj, 0x22, dir | 0x33, 2, 0);
    func_80019E84_1AA84(obj, 0xD, dir | 0x4F, 0, 0);
    func_80019E84_1AA84(obj, 0xE, dir | 0x56, 0, 0);
    func_80019E84_1AA84(obj, 0x26, dir | 0x7D, 0, 0);
    func_8000C004_CC04(obj);
    func_8000C35C_CF5C(obj, x, y, z);
    func_80029714_2A314(obj->model[0], x, y, z);
    func_8000C024_CC24(obj, 0, 2);
    func_8000C024_CC24(obj, 1, 2);
    obj->func_ptr = func_801038D0_27B400_QuicksandCache;
}

void func_80104498_27BFC8_QuicksandCache(omObjData* obj) {
    MgWork* w = obj->unk_50;
    QCSand* sand = D_80108034_27FB64_QuicksandCache->unk_50;
    f32 stick = ContStkX[w->unk_57];
    s8 i;
    omObjData* coin;
    QCActor* a;
    u8 id;
    u8 m;
    f32 x;
    f32 z;

    if (stick < 10.0f) {
        if (stick > -10.0f) {
            stick = 0.0f;
        }
    }
    if (stick < -60.0f) {
        stick = -60.0f;
    } else if (stick > 60.0f) {
        stick = 60.0f;
    }
    stick /= 60.0f;
    if (D_80107776_27F2A6_QuicksandCache == 5) {
        sand->unk_24 = stick;
        if (stick != 0.0f) {
            if (stick < 0.0f) {
                D_8010777C_27F2AC_QuicksandCache = 1;
            } else {
                D_8010777C_27F2AC_QuicksandCache = 2;
            }
        }
        if (D_8010777C_27F2AC_QuicksandCache != 0 &&
            D_8010777C_27F2AC_QuicksandCache != D_8010777D_27F2AD_QuicksandCache) {
            func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[0x26]), 0, 0xA, 0);
        }
        D_8010777D_27F2AD_QuicksandCache = D_8010777C_27F2AC_QuicksandCache;
    } else {
        sand->unk_24 = 0.0f;
    }
    if (D_80107772_27F2A2_QuicksandCache == 1) {
        for (i = 0; i < 5; i++) {
            coin = D_800F9CE0_FA8E0[i];
            a = coin->unk_50;
            if (a->unk_54 == 1 && a->unk_78 != 0) {
                x = coin->trans.x;
                z = coin->trans.z;
                if (func_800B1830_B2430(x * x + z * z) < 190.0f) {
                    a->unk_54 = 0;
                    a->unk_78 = 0;
                    func_800298A4_2A4A4(coin->model[0], 4, 4);
                    func_800298A4_2A4A4(coin->model[1], 4, 4);
                    id = a->unk_24;
                    m = coin->model[3];
                    func_800298A4_2A4A4(m, 4, 0);
                    func_80021198_21D98(id, 0);
                    func_80021160_21D60(id, 4, 4);
                    func_80029714_2A314(m, coin->trans.x, coin->trans.y, coin->trans.z);
                    func_800297E8_2A3E8(m, 5.0f, 5.0f, 5.0f);
                    switch (a->unk_52) {
                    case 3:
                        gPlayers[w->unk_59].coins_mg++;
                        PlaySound(9);
                        break;
                    case 6:
                        gPlayers[w->unk_59].coins_mg += 5;
                        PlaySound(0x15);
                        omVibrate(w->unk_59, 2, 3, 0xA);
                        break;
                    }
                }
            }
        }
    }
}

__asm__(".section .rodata");
const s16 D_80107818_27F348_QuicksandCache[4][6] = { { 0x1E, 0x19, 0x1E, 0x19, 0x23, 0x1E }, { 0x14, 0x19, 0x14, 0x19, 0x14, 0x1E }, { 0xA, 0x19, 0x14, 0xF, 0xA, 0x14 }, { 0xA, 0x14, 0xF, 0xA, 0xA, 0xF } };

__asm__(".section .rodata");
const s8 D_80107848_27F378_QuicksandCache[4][6] = { { 1, 0, 0, 2, 1, 0 }, { 1, 2, 1, 0, 2, 0 }, { 2, 1, 2, 1, 2, 0 }, { 1, 2, 1, 1, 2, 2 } };

__asm__(".section .rodata");
const char D_80107860_27F390_QuicksandCache[] = "C002_000b-bmerge10_1";

__asm__(".section .rodata");
const char D_80107878_27F3A8_QuicksandCache[] = "c005_000-bmerge1";

__asm__(".section .rodata");
const char D_8010788C_27F3BC_QuicksandCache[] = "Luigi1-atama_1";

__asm__(".section .rodata");
const char D_8010789C_27F3CC_QuicksandCache[] = "c003_000-head_1";

__asm__(".section .rodata");
const char D_801078AC_27F3DC_QuicksandCache[] = "c001_000-atama_2";

__asm__(".section .rodata");
const char D_801078C0_27F3F0_QuicksandCache[] = "atama_2";

__asm__(".section .rodata");
const char D_801078C8_27F3F8_QuicksandCache[] = "21_kimoti_1b-atama_3";

void func_80104848_27C378_QuicksandCache(omObjData* obj) {
    MgWork* w = obj->unk_50;
    MgWork* ws[4];
    QCWork* qs[4];
    s8 i;
    s8 n;

    for (i = 0; i < 3; i++) {
        ws[i] = D_800FFFD8_100BD8[i]->unk_50;
        qs[i] = ws[i]->unk_158;
    }
    D_801079C0_27F4F0_QuicksandCache = gPlayers[w->unk_59].cpu_difficulty;
    if (D_8010777E_27F2AE_QuicksandCache == 0) {
        D_80107784_27F2B4_QuicksandCache = guRandom() % 6;
        D_801079C1_27F4F1_QuicksandCache = D_80107848_27F378_QuicksandCache[D_801079C0_27F4F0_QuicksandCache][D_80107784_27F2B4_QuicksandCache];
        D_8010778C_27F2BC_QuicksandCache = D_80107818_27F348_QuicksandCache[D_801079C0_27F4F0_QuicksandCache][D_80107784_27F2B4_QuicksandCache];
        D_80107788_27F2B8_QuicksandCache = 0;
        D_8010777E_27F2AE_QuicksandCache = 1;
    }
    if (gPlayers[w->unk_59].flags & 1) {
        ContStkX[w->unk_57] = 0;
        ContStkY[w->unk_57] = 0;
        if (D_80107788_27F2B8_QuicksandCache > D_8010778C_27F2BC_QuicksandCache) {
            D_80107780_27F2B0_QuicksandCache = D_8010777F_27F2AF_QuicksandCache;
            D_80107784_27F2B4_QuicksandCache = guRandom() % 6;
            D_8010777F_27F2AF_QuicksandCache = D_80107848_27F378_QuicksandCache[D_801079C0_27F4F0_QuicksandCache][D_80107784_27F2B4_QuicksandCache];
            D_8010778C_27F2BC_QuicksandCache = D_80107818_27F348_QuicksandCache[D_801079C0_27F4F0_QuicksandCache][D_80107784_27F2B4_QuicksandCache];
            D_80107788_27F2B8_QuicksandCache = 0;
        }
        n = 0;
        for (i = 0; i < 3; i++) {
            if (qs[i]->unk_00 == 1) {
                n++;
            }
        }
        if (n < 3 && D_8010777F_27F2AF_QuicksandCache != 0) {
            if (D_8010777F_27F2AF_QuicksandCache == 2) {
                if (D_80107780_27F2B0_QuicksandCache == D_8010777F_27F2AF_QuicksandCache) {
                    ContStkX[w->unk_57] = -0x46;
                } else {
                    ContStkX[w->unk_57] = 0x46;
                }
            } else {
                if (D_80107780_27F2B0_QuicksandCache != D_8010777F_27F2AF_QuicksandCache) {
                    ContStkX[w->unk_57] = -0x46;
                } else {
                    ContStkX[w->unk_57] = 0x46;
                }
            }
        }
        D_80107788_27F2B8_QuicksandCache++;
    }
    func_80104498_27BFC8_QuicksandCache(obj);
}

void func_80104B90_27C6C0_QuicksandCache(omObjData* obj, u32 dir, s32 file, u16 player, f32 x, f32 y, f32 z) {
    MgWork* w;
    void* p;

    p = func_80027154_27D54(sizeof(MgWork), 0x7918);
    obj->unk_50 = p;
    func_800B0EF0_B1AF0(p, 0, sizeof(MgWork));
    w = obj->unk_50;
    w->unk_57 = gPlayers[player].port;
    obj->model[0] = LoadFormFile(0x80081, 0x20AB9);
    obj->model[1] = LoadFormFile(1, 0x20AB9);
    obj->model[2] = LoadFormFile(dir | file, 0x20AB9);
    dir >>= 16;
    dir -= 2;
    func_80023DAC_249AC(obj->model[2], D_80107790_27F2C0_QuicksandCache[dir], obj->model[0],
                        D_801077A8_27F2D8_QuicksandCache);
    func_800298A4_2A4A4(obj->model[2], 4, 4);
    w->unk_59 = player;
    w->unk_52 = 7;
    w->unk_B4 = 1.0f;
    w->unk_D0 = 0xFFFF;
    w->unk_38 = 1000.0f;
    w->unk_50 = 0;
    w->unk_48 = 180.0f;
    func_8000BEB0_CAB0(obj, 60.0f);
    func_8000BEBC_CABC(obj, 150.0f);
    func_8000BEC8_CAC8(obj, 20.0f);
    func_8000C024_CC24(obj, 0, 1);
    func_80018CCC_198CC(obj, 0, 0x80083);
    func_80018CCC_198CC(obj, 0xD, 0x80087);
    func_80018CCC_198CC(obj, 0xE, 0x80088);
    func_80018CCC_198CC(obj, 0x26, 0x8008A);
    func_8000C35C_CF5C(obj, x, y, z);
    func_80029714_2A314(obj->model[0], x, y, z);
    func_80029714_2A314(obj->model[1], x, y, z);
    func_80029714_2A314(obj->model[2], x, y, z);
    func_80029B80_2A780(obj->model[0], obj->motion[0]);
    func_80029E80_2AA80(obj->model[0], 2, 2);
    obj->scale.x = obj->scale.y = obj->scale.z = 1.333333f;
    obj->rot.x = 330.0f;
    guTranslateF(D_800FC834_FD434[obj->model[0]].mtx, 0.0f, -80.0f, 0.0f);
    obj->func_ptr = func_80104848_27C378_QuicksandCache;
}

void func_80104EA8_27C9D8_QuicksandCache(omObjData* obj) {
    MgWork* ws[4];
    QCWork* qs[4];
    s8 i;
    s8 n;
    MgWork* w;

    func_8000C3C8_CFC8();
    for (i = 0; i < 3; i++) {
        ws[i] = D_800FFFD8_100BD8[i]->unk_50;
        qs[i] = ws[i]->unk_158;
    }
    switch (D_80107776_27F2A6_QuicksandCache) {
    case 0:
        func_8000C38C_CF8C();
        D_801079CA_27F4FA_QuicksandCache = PlaySound(0x2FA);
        D_801079C4_27F4F4_QuicksandCache = 0;
        D_80107776_27F2A6_QuicksandCache++;
        break;
    case 1:
        if (D_801079C4_27F4F4_QuicksandCache++ >= 0x1F) {
            D_80107771_27F2A1_QuicksandCache = 1;
            D_80107776_27F2A6_QuicksandCache++;
        }
        break;
    case 2:
        if (D_80107772_27F2A2_QuicksandCache == 1) {
            func_800794A8_7A0A8(0x5A);
            D_801079C4_27F4F4_QuicksandCache = 0;
            PlayMusic(0x29);
            D_80107776_27F2A6_QuicksandCache++;
        }
        break;
    case 3:
        if (D_801079C4_27F4F4_QuicksandCache++ >= 0x1F) {
            func_800691FC_69DFC(0);
            D_80107776_27F2A6_QuicksandCache++;
        }
        break;
    case 4:
        if (func_80069538_6A138() == 0 || func_80069538_6A138() & 2) {
            func_800691FC_69DFC(0xA, 0x1E, 0xA0, 0x18);
            func_8006D4D0_6E0D0(0x1E);
            func_8000C3B8_CFB8();
            D_80107776_27F2A6_QuicksandCache++;
        }
        break;
    case 5:
        if (D_80107770_27F2A0_QuicksandCache == 1) {
            func_800794A8_7A0A8(0x3C);
            func_8000C398_CF98();
            D_80107776_27F2A6_QuicksandCache++;
            break;
        }
        func_8006D4D0_6E0D0(D_80107778_27F2A8_QuicksandCache / 30);
        if (D_80107778_27F2A8_QuicksandCache == 0) {
            D_80107770_27F2A0_QuicksandCache = 1;
            D_80107774_27F2A4_QuicksandCache = 0;
            func_8006D518_6E118();
        } else {
            D_80107778_27F2A8_QuicksandCache--;
        }
        func_801060F8_27DC28_QuicksandCache();
        func_80106440_27DF70_QuicksandCache();
        if (_CheckFlag(0xC) != 0) {
            for (i = 0; i < 3; i++) {
                if (qs[i]->unk_00 == 1 && !(gPlayers[ws[i]->unk_59].flags & 1)) {
                    D_80107770_27F2A0_QuicksandCache = 1;
                    D_80107774_27F2A4_QuicksandCache = 1;
                    func_8006D518_6E118();
                }
            }
        }
        break;
    case 6:
        func_80106648_27E178_QuicksandCache();
        func_800691FC_69DFC(3);
        func_800799A4_7A5A4(D_801079CA_27F4FA_QuicksandCache, 0x3C);
        D_80107776_27F2A6_QuicksandCache++;
        break;
    case 7:
        if (func_80069538_6A138() == 0 || func_80069538_6A138() & 2) {
            func_8000C3A8_CFA8();
            if (_CheckFlag(0xC) == 0) {
                n = 0;
                for (i = 0; i < 4; i++) {
                    if (gPlayers[D_80108024_27FB54_QuicksandCache[i]].coins_mg > 0) {
                        n++;
                    }
                }
                PlayMusic(n >= 2 ? 0x52 : 0x51);
                D_801079C8_27F4F8_QuicksandCache = 0xA8;
            } else {
                D_801079C8_27F4F8_QuicksandCache = 0x3C;
            }
            D_80107777_27F2A7_QuicksandCache = 0;
            if (_CheckFlag(0xC) == 0) {
                if (gPlayers[D_80108024_27FB54_QuicksandCache[0]].coins_mg == 0) {
                    func_80029B80_2A780(D_80108020_27FB50_QuicksandCache->model[0], D_80108020_27FB50_QuicksandCache->motion[0xE]);
                    func_800797DC_7A3DC(0xFC, D_80108024_27FB54_QuicksandCache[0]);
                } else {
                    func_80029B80_2A780(D_80108020_27FB50_QuicksandCache->model[0], D_80108020_27FB50_QuicksandCache->motion[0xD]);
                    func_800797DC_7A3DC(0x103, D_80108024_27FB54_QuicksandCache[0]);
                }
                D_80108020_27FB50_QuicksandCache->rot.x = 300.0f;
            }
            if (_CheckFlag(0xC) == 0) {
                for (i = 0; i < 3; i++) {
                    if (qs[i]->unk_00 == 0) {
                        if (gPlayers[D_80108024_27FB54_QuicksandCache[i + 1]].coins_mg == 0) {
                            func_80029B80_2A780(D_800FFFD8_100BD8[i]->model[0], D_800FFFD8_100BD8[i]->motion[0xE]);
                            func_800732FC_73EFC(D_800CD438_CE038[gPlayers[D_80108024_27FB54_QuicksandCache[i + 1]].character].unk_04 | 0x56, -1, D_80108024_27FB54_QuicksandCache[i + 1]);
                        } else {
                            func_80029B80_2A780(D_800FFFD8_100BD8[i]->model[0], D_800FFFD8_100BD8[i]->motion[0xD]);
                            func_800732FC_73EFC(D_800CD438_CE038[gPlayers[D_80108024_27FB54_QuicksandCache[i + 1]].character].unk_04 | 0x4F, -1, D_80108024_27FB54_QuicksandCache[i + 1]);
                        }
                        w = ws[i];
                        w->unk_3C = 0.0f;
                        func_800B2060_B2C60(D_800FC834_FD434[D_800FFFD8_100BD8[i]->model[0]].mtx, w->unk_3C, w->unk_3C, w->unk_3C);
                        func_800B6340_B6F40(D_800FC834_FD434[D_800FFFD8_100BD8[i]->model[0]].mtx, &qs[i]->unk_1C,
                                            D_800FC834_FD434[D_800FFFD8_100BD8[i]->model[0]].mtx);
                    }
                }
            } else {
                for (i = 0; i < 3; i++) {
                    if (qs[i]->unk_00 == 0) {
                        ws[i]->unk_3C = 0.0f;
                        func_800B2060_B2C60(D_800FC834_FD434[D_800FFFD8_100BD8[i]->model[0]].mtx, 0.0f, 0.0f, 0.0f);
                        func_800B6340_B6F40(D_800FC834_FD434[D_800FFFD8_100BD8[i]->model[0]].mtx, &qs[i]->unk_1C,
                                            D_800FC834_FD434[D_800FFFD8_100BD8[i]->model[0]].mtx);
                    }
                }
            }
            D_80107776_27F2A6_QuicksandCache++;
        }
        break;
    case 8:
        if (D_801079C8_27F4F8_QuicksandCache-- <= 0) {
            func_800794A8_7A0A8(0x28);
            InitFadeOut(0, 0x14);
            func_80079868_7A468();
            func_8000C398_CF98();
            D_80107776_27F2A6_QuicksandCache++;
        }
        break;
    case 9:
        if (func_8008F618_90218() == 0) {
            func_80069770_6A370();
            omOvlReturnEx(1);
        }
        break;
    }
}

void func_8010568C_27D1BC_QuicksandCache(omObjData* obj) {
    obj->model[0] = LoadFormFile(0x800B0, 0x20AB9);
    obj->model[1] = LoadFormFile(0xD, 0x63D);
    func_80018CCC_198CC(obj, 0, 0x800B0);
    func_80018CCC_198CC(obj, 1, 0x800B1);
    func_80018CCC_198CC(obj, 2, 0x800B2);
    func_80018CCC_198CC(obj, 3, 0x800B3);
    func_80029B80_2A780(obj->model[0], obj->motion[0]);
    func_80029E80_2AA80(obj->model[0], 2, 2);
    obj->trans.x = 310.0f;
    obj->trans.y = 900.0f;
    obj->trans.z = -350.0f;
    func_800298A4_2A4A4(obj->model[1], 4, 0);
    func_800297E8_2A3E8(obj->model[1], 1.5f, 1.5f, 1.5f);
    obj->func_ptr = func_801057BC_27D2EC_QuicksandCache;
}

void func_801057BC_27D2EC_QuicksandCache(omObjData* obj) {
    f32 t;
    omObjData* coin;
    QCActor* a;
    u8 id;
    u8 m;

    if (D_80107771_27F2A1_QuicksandCache == 0) {
        return;
    }
    if (D_801077B0_27F2E0_QuicksandCache == 0) {
        func_801062F0_27DE20_QuicksandCache();
    }
    if (D_801077B0_27F2E0_QuicksandCache++ < 0x46) {
        return;
    }
    if (D_801077AE_27F2DE_QuicksandCache == 0) {
        PlaySound(0x364);
        D_801077AE_27F2DE_QuicksandCache = 1;
    }
    obj->rot.y = -func_800B75A8_B81A8(obj->trans.x, -obj->trans.z);
    if (obj->trans.y >= 300.0f) {
        func_80029714_2A314(obj->model[1], obj->trans.x, 300.0f, obj->trans.z);
        t = obj->trans.y;
        if (t <= 800.0f) {
            t = (t - 300.0f) / 500.0f;
            t = 1.0f - t;
            t = t < 0.0f ? 0.0f : t;
            t *= 1.5f;
            t = t >= 1.5f ? 1.5f : t;
            func_800297E8_2A3E8(obj->model[1], t, 1.5f, t);
            func_800298A4_2A4A4(obj->model[1], 4, 0);
        } else {
            func_800298A4_2A4A4(obj->model[1], 4, 4);
        }
    } else {
        func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
        func_800297E8_2A3E8(obj->model[1], 1.5f, 1.5f, 1.5f);
        func_800298A4_2A4A4(obj->model[1], 4, 0);
    }
    if (D_801077B0_27F2E0_QuicksandCache < 0x50) {
        obj->trans.y -= 60.0f;
        return;
    }
    if (D_801077AC_27F2DC_QuicksandCache == 0) {
        D_80108028_27FB58_QuicksandCache.x = (100.0f - obj->trans.x) / 17.0f;
        D_80108028_27FB58_QuicksandCache.y = (90.0f - obj->trans.y) / 17.0f;
        D_80108028_27FB58_QuicksandCache.z = (-190.0f - obj->trans.z) / 17.0f;
        func_80029B80_2A780(obj->model[0], obj->motion[3]);
        func_80029E80_2AA80(obj->model[0], 2, 2);
        D_801077AC_27F2DC_QuicksandCache = 1;
    }
    obj->trans.x += D_80108028_27FB58_QuicksandCache.x;
    obj->trans.y += D_80108028_27FB58_QuicksandCache.y;
    obj->trans.z += D_80108028_27FB58_QuicksandCache.z;
    if (D_801077AD_27F2DD_QuicksandCache == 0) {
        if (D_801077B0_27F2E0_QuicksandCache >= 0x62) {
            coin = D_800F9CE0_FA8E0[0];
            a = coin->unk_50;
            a->unk_54 = 0;
            a->unk_78 = 0;
            func_800298A4_2A4A4(coin->model[0], 4, 4);
            func_800298A4_2A4A4(coin->model[1], 4, 4);
            id = a->unk_24;
            m = coin->model[3];
            func_800298A4_2A4A4(m, 4, 0);
            func_80021198_21D98(id, 0);
            func_80021160_21D60(id, 4, 4);
            func_80029714_2A314(m, coin->trans.x, coin->trans.y, coin->trans.z);
            func_800297E8_2A3E8(m, 5.0f, 5.0f, 5.0f);
            PlaySound(9);
            D_801077AD_27F2DD_QuicksandCache = 1;
            goto done;
        }
    } else {
    done:
        if (D_801077B0_27F2E0_QuicksandCache >= 0x62) {
            obj->func_ptr = func_80105BC4_27D6F4_QuicksandCache;
        }
    }
}

void func_80105BC4_27D6F4_QuicksandCache(omObjData* obj) {
    if (D_801077B2_27F2E2_QuicksandCache == 0) {
        func_80029B80_2A780(obj->model[0], 2);
        func_800298A4_2A4A4(obj->model[1], 4, 4);
        PlaySound(0x363);
        D_801077B2_27F2E2_QuicksandCache = 1;
    }
    obj->trans.y -= 4.0f;
    obj->rot.y += 20.0f;
    if (++D_801077B4_27F2E4_QuicksandCache >= 0x1F) {
        func_800298A4_2A4A4(obj->model[0], 4, 4);
        obj->func_ptr = func_80105CA8_27D7D8_QuicksandCache;
        D_80107777_27F2A7_QuicksandCache = 1;
    }
}

void func_80105CA8_27D7D8_QuicksandCache(omObjData* obj) {
    if (D_801077B8_27F2E8_QuicksandCache++ >= 2) {
        D_80107772_27F2A2_QuicksandCache = 1;
        obj->func_ptr = NULL;
    }
}
