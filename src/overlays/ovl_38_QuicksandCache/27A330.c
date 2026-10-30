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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_38_QuicksandCache/27A330", func_80103FF4_27BB24_QuicksandCache);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_38_QuicksandCache/27A330", func_80104498_27BFC8_QuicksandCache);

__asm__(".section .rodata");
const u32 D_80107818_27F348_QuicksandCache[12] = { 0x001E0019, 0x001E0019, 0x0023001E, 0x00140019, 0x00140019, 0x0014001E, 0x000A0019, 0x0014000F, 0x000A0014, 0x000A0014, 0x000F000A, 0x000A000F };

__asm__(".section .rodata");
const u32 D_80107848_27F378_QuicksandCache[6] = { 0x01000002, 0x01000102, 0x01000200, 0x02010201, 0x02000102, 0x01010202 };

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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_38_QuicksandCache/27A330", func_80104848_27C378_QuicksandCache);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_38_QuicksandCache/27A330", func_80104B90_27C6C0_QuicksandCache);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_38_QuicksandCache/27A330", func_80104EA8_27C9D8_QuicksandCache);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_38_QuicksandCache/27A330", func_8010568C_27D1BC_QuicksandCache);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_38_QuicksandCache/27A330", func_801057BC_27D2EC_QuicksandCache);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_38_QuicksandCache/27A330", func_80105BC4_27D6F4_QuicksandCache);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_38_QuicksandCache/27A330", func_80105CA8_27D7D8_QuicksandCache);
