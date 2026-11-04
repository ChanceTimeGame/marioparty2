#include "ovl_5D.h"

/* .data (0x3A9000-0x3A9010, 8010B610) */
f32 D_8010B610_3A9000_name_5D = 58.0f;
s8 D_8010B614_3A9004_name_5D = 0;
/* padding to the 16-byte end of the file's .data */
s8 D_8010B615_3A9005_name_5D = 0;
s8 D_8010B616_3A9006_name_5D = 0;
s8 D_8010B617_3A9007_name_5D = 0;
s32 D_8010B618_3A9008_name_5D[2] = { 0, 0 };

void func_801080C0_3A5AB0_name_5D(s16 view) {
    f32 a;

    a = D_8010CCE8_3AA6D8_name_5D[view].rot.x;
    if (a >= 360.0f) {
        a -= 360.0f;
    } else if (a < 0.0f) {
        a += 360.0f;
    }
    D_8010CDE8_3AA7D8_name_5D.x = D_800FD474_FE074.x = a;
    a = D_8010CCE8_3AA6D8_name_5D[view].rot.y;
    if (a >= 360.0f) {
        a -= 360.0f;
    } else if (a < 0.0f) {
        a += 360.0f;
    }
    D_8010CDE8_3AA7D8_name_5D.y = D_800FD474_FE074.y = a;
    a = D_8010CCE8_3AA6D8_name_5D[view].rot.z;
    if (a >= 360.0f) {
        a -= 360.0f;
    } else if (a < 0.0f) {
        a += 360.0f;
    }
    D_8010CDE8_3AA7D8_name_5D.z = D_800FD474_FE074.z = a;
    D_8010274C_10334C = D_8010CCE8_3AA6D8_name_5D[view].at;
    D_800FA610_FB210 = D_8010CCE8_3AA6D8_name_5D[view].zoom;
}

void func_801082A0_3A5C90_name_5D(s16 view, s16 frames, s16 mode, void (*cb)(s16*)) {
    Vec drot;
    Vec dat;
    Vec rot0;
    Vec at0;
    s16 arg[2];
    Vec pad[3]; /* unused; retail's frame has it */
    void (*fn)(s16*);
    f32 d;
    f32 t;
    f32 a;
    f32 dzoom;
    f32 zoom0;
    s16 i;

    fn = cb;
    d = D_8010CCE8_3AA6D8_name_5D[view].rot.x - D_800FD474_FE074.x;
    if (ABS(d) > 180.0f) {
        if (D_8010CCE8_3AA6D8_name_5D[view].rot.x < D_800FD474_FE074.x) {
            drot.x = d + 360.0f;
        } else {
            drot.x = d - 360.0f;
        }
    } else {
        drot.x = d;
    }
    d = D_8010CCE8_3AA6D8_name_5D[view].rot.y - D_800FD474_FE074.y;
    if (ABS(d) > 180.0f) {
        if (D_8010CCE8_3AA6D8_name_5D[view].rot.y < D_800FD474_FE074.y) {
            drot.y = d + 360.0f;
        } else {
            drot.y = d - 360.0f;
        }
    } else {
        drot.y = d;
    }
    d = D_8010CCE8_3AA6D8_name_5D[view].rot.z - D_800FD474_FE074.z;
    if (ABS(d) > 180.0f) {
        if (D_8010CCE8_3AA6D8_name_5D[view].rot.z < D_800FD474_FE074.z) {
            drot.z = d + 360.0f;
        } else {
            drot.z = d - 360.0f;
        }
    } else {
        drot.z = d;
    }
    dat.x = D_8010CCE8_3AA6D8_name_5D[view].at.x - D_8010274C_10334C.x;
    dat.y = D_8010CCE8_3AA6D8_name_5D[view].at.y - D_8010274C_10334C.y;
    dat.z = D_8010CCE8_3AA6D8_name_5D[view].at.z - D_8010274C_10334C.z;
    dzoom = D_8010CCE8_3AA6D8_name_5D[view].zoom - D_800FA610_FB210;
    at0 = D_8010274C_10334C;
    rot0 = D_800FD474_FE074;
    zoom0 = D_800FA610_FB210;
    arg[1] = frames;
    if (mode == 1 || mode == 2) {
        for (i = 0; i <= frames; i++) {
            if (mode != 2) {
                t = HuMathSin(i * 90.0f / frames);
            } else if (i <= frames / 2) {
                t = (1.0f - func_800B7890_B8490(i * 180.0f / frames)) * 0.5f;
            } else {
                t = -func_800B7890_B8490(i * 180.0f / frames) * 0.5f + 0.5f;
            }
            a = t * drot.x + rot0.x;
            if (a >= 360.0f) {
                a -= 360.0f;
            } else if (a < 0.0f) {
                a += 360.0f;
            }
            D_8010CDE8_3AA7D8_name_5D.x = D_800FD474_FE074.x = a;
            a = t * drot.y + rot0.y;
            if (a >= 360.0f) {
                a -= 360.0f;
            } else if (a < 0.0f) {
                a += 360.0f;
            }
            D_8010CDE8_3AA7D8_name_5D.y = D_800FD474_FE074.y = a;
            a = t * drot.z + rot0.z;
            if (a >= 360.0f) {
                a -= 360.0f;
            } else if (a < 0.0f) {
                a += 360.0f;
            }
            D_8010CDE8_3AA7D8_name_5D.x = D_800FD474_FE074.z = a; /* retail: .x, not .z */
            D_8010274C_10334C.x = t * dat.x + at0.x;
            D_8010274C_10334C.y = t * dat.y + at0.y;
            D_8010274C_10334C.z = t * dat.z + at0.z;
            D_800FA610_FB210 = t * dzoom + zoom0;
            if (cb != (void*)-1) {
                arg[0] = i;
                fn(arg);
            }
            HuPrcVSleep();
        }
    } else {
        for (i = 0; i <= frames; i++) {
            t = 1.0f / frames * i;
            a = t * drot.x + rot0.x;
            if (a >= 360.0f) {
                a -= 360.0f;
            } else if (a < 0.0f) {
                a += 360.0f;
            }
            D_8010CDE8_3AA7D8_name_5D.x = D_800FD474_FE074.x = a;
            a = t * drot.y + rot0.y;
            if (a >= 360.0f) {
                a -= 360.0f;
            } else if (a < 0.0f) {
                a += 360.0f;
            }
            D_8010CDE8_3AA7D8_name_5D.y = D_800FD474_FE074.y = a;
            a = t * drot.z + rot0.z;
            if (a >= 360.0f) {
                a -= 360.0f;
            } else if (a < 0.0f) {
                a += 360.0f;
            }
            D_8010CDE8_3AA7D8_name_5D.x = D_800FD474_FE074.z = a; /* retail: .x, not .z */
            D_8010274C_10334C.x = t * dat.x + at0.x;
            D_8010274C_10334C.y = t * dat.y + at0.y;
            D_8010274C_10334C.z = t * dat.z + at0.z;
            D_800FA610_FB210 = t * dzoom + zoom0;
            if (cb != (void*)-1) {
                arg[0] = i;
                fn(arg);
            }
            HuPrcVSleep();
        }
    }
    func_801080C0_3A5AB0_name_5D(view);
}

// register allocation (masked 18)
#ifdef NON_MATCHING
void func_80108B68_3A6558_name_5D(Ovl5DCamKey* path, f32 speed, void (*cb)(s32, s16, s16)) {
    f32 vals[4];
    f32 times[4];
    void (*fn)(s32, s16, s16);
    Ovl5DCamKey* prev;
    Ovl5DCamKey* k;
    f32 total;
    f32 end;
    f32 dx, dy, dz, d;
    f32 s;
    f32 ft;
    s16 i;
    s16 seg;

    prev = NULL;
    fn = cb;
    total = 0.0f;
    i = 0;
    if (path->zoom != 0.0f) {
    k = path;
    do {
        s = HuMathSin(k->rot.y);
        k->pos.x = s * func_800B7890_B8490(k->rot.x) * k->zoom + k->center.x;
        k->pos.y = -HuMathSin(k->rot.x) * k->zoom + k->center.y;
        k->pos.z = func_800B7890_B8490(k->rot.y) * func_800B7890_B8490(k->rot.x) * k->zoom + k->center.z;
        if (i > 0) {
            dx = prev->pos.x - k->pos.x;
            dy = prev->pos.y - k->pos.y;
            dz = prev->pos.z - k->pos.z;
            d = func_800B1830_B2430(dx * dx + dy * dy + dz * dz);
            if (d == 0.0f) {
                d = speed * 10.0f;
            }
            total += d / speed;
            k->time = total;
        }
        prev = k;
        i++;
        k = &path[i];
    } while (k->zoom != 0.0f);
    }
    end = total - 10.0f;
    seg = 1;
    for (i = 10; i < end; i++) {
        if (i > path[seg + 1].time) {
            seg++;
        }
        k = seg + path;
        times[0] = k[-1].time;
        times[1] = k[0].time;
        times[2] = k[1].time;
        times[3] = k[2].time;
        vals[0] = k[-1].center.x;
        vals[1] = k[0].center.x;
        vals[2] = k[1].center.x;
        vals[3] = k[2].center.x;
        ft = i;
        D_8010274C_10334C.x = func_8002662C_2722C(vals, times, ft);
        vals[0] = k[-1].center.y;
        vals[1] = k[0].center.y;
        vals[2] = k[1].center.y;
        vals[3] = k[2].center.y;
        D_8010274C_10334C.y = func_8002662C_2722C(vals, times, ft);
        vals[0] = k[-1].center.z;
        vals[1] = k[0].center.z;
        vals[2] = k[1].center.z;
        vals[3] = k[2].center.z;
        D_8010274C_10334C.z = func_8002662C_2722C(vals, times, ft);
        vals[0] = k[-1].rot.x;
        vals[1] = k[0].rot.x;
        vals[2] = k[1].rot.x;
        vals[3] = k[2].rot.x;
        D_8010CDE8_3AA7D8_name_5D.x = D_800FD474_FE074.x = func_8002662C_2722C(vals, times, ft);
        vals[0] = k[-1].rot.y;
        vals[1] = k[0].rot.y;
        vals[2] = k[1].rot.y;
        vals[3] = k[2].rot.y;
        D_8010CDE8_3AA7D8_name_5D.y = D_800FD474_FE074.y = func_8002662C_2722C(vals, times, ft);
        vals[0] = k[-1].rot.z;
        vals[1] = k[0].rot.z;
        vals[2] = k[1].rot.z;
        vals[3] = k[2].rot.z;
        D_8010CDE8_3AA7D8_name_5D.z = D_800FD474_FE074.z = func_8002662C_2722C(vals, times, ft);
        vals[0] = k[-1].zoom;
        vals[1] = k[0].zoom;
        vals[2] = k[1].zoom;
        vals[3] = k[2].zoom;
        D_800FA610_FB210 = func_8002662C_2722C(vals, times, ft);
        if (D_800FA610_FB210 >= 700.0f) {
            Hu3DCamSetPerspective(0, D_8010B610_3A9000_name_5D, D_8010CDD4_3AA7C4_name_5D, D_8010CDBC_3AA7AC_name_5D);
        }
        if (cb != (void*)-1) {
            fn((s16)end, seg, i);
        }
        HuPrcVSleep();
    }
    k = &path[(s16)(seg + 1)];
    D_8010CDE8_3AA7D8_name_5D.x = D_800FD474_FE074.x = k->rot.x;
    D_8010CDE8_3AA7D8_name_5D.y = D_800FD474_FE074.y = k->rot.y;
    D_8010CDE8_3AA7D8_name_5D.z = D_800FD474_FE074.z = k->rot.z;
    D_800FA610_FB210 = k->zoom;
    D_8010274C_10334C.x = k->center.x;
    D_8010274C_10334C.y = k->center.y;
    D_8010274C_10334C.z = k->center.z;
    D_800F851A_F911A = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5D_name/3A5AB0", func_80108B68_3A6558_name_5D);
#endif

void func_80109104_3A6AF4_name_5D(void) {
    s16 last = -1;
    s16 i;
    s16 x0;
    s16 dx;
    s16 y0;
    s16 dy;
    f32 s;
    s16* to;

    D_8010CDF6_3AA7E6_name_5D = 0;
    D_8010CCE4_3AA6D4_name_5D = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x900F8), 0, 1);
    func_8001A788_1B388(D_8010CCE4_3AA6D4_name_5D, 1);
    espPosSet(D_8010CCE4_3AA6D4_name_5D, 160, 120);
    espDispOff(D_8010CCE4_3AA6D4_name_5D);
    D_8010CCA4_3AA694_name_5D = 160;
    D_8010CCA6_3AA696_name_5D = 120;
    D_8010CCA8_3AA698_name_5D = 10;
    omAddPrcObj(func_80109398_3A6D88_name_5D, 0x3F00, 0x100, 0);
    while (1) {
        HuPrcVSleep();
        if (D_8010CDF6_3AA7E6_name_5D != 0) {
            if (last != D_8010CCAA_3AA69A_name_5D && D_8010CCAA_3AA69A_name_5D != -1) {
                x0 = D_8010CCA4_3AA694_name_5D;
                y0 = D_8010CCA6_3AA696_name_5D;
                to = D_8010CCA0_3AA690_name_5D[D_8010CCAA_3AA69A_name_5D];
                dx = to[0] - x0;
                dy = to[1] - y0;
                for (i = 1; i <= D_8010CCA8_3AA698_name_5D; i++) {
                    s = HuMathSin(90.0f / D_8010CCA8_3AA698_name_5D * i);
                    D_8010CCA4_3AA694_name_5D = x0 + dx * s;
                    D_8010CCA6_3AA696_name_5D = y0 + dy * s;
                    espPosSet(D_8010CCE4_3AA6D4_name_5D, D_8010CCA4_3AA694_name_5D, D_8010CCA6_3AA696_name_5D);
                    HuPrcVSleep();
                }
                last = D_8010CCAA_3AA69A_name_5D;
            }
        } else {
            last = D_8010CCAA_3AA69A_name_5D;
        }
        espPosSet(D_8010CCE4_3AA6D4_name_5D, D_8010CCA4_3AA694_name_5D, D_8010CCA6_3AA696_name_5D);
    }
}

void func_80109398_3A6D88_name_5D(void) {
    s16 shown;
    s16 i;

    shown = 0;
    while (1) {
        HuPrcVSleep();
        if (shown == D_8010CDF6_3AA7E6_name_5D) {
            continue;
        }
        if (D_8010CDF6_3AA7E6_name_5D != 0) {
            espDispOn(D_8010CCE4_3AA6D4_name_5D);
            for (i = 0; i < 5; i++) {
                func_8001A6BC_1B2BC(D_8010CCE4_3AA6D4_name_5D, i * 63.75f);
                HuPrcVSleep();
            }
        } else {
            for (i = 0; i < 5; i++) {
                func_8001A6BC_1B2BC(D_8010CCE4_3AA6D4_name_5D, 255.0f - i * 63.75f);
                HuPrcVSleep();
            }
            espDispOff(D_8010CCE4_3AA6D4_name_5D);
        }
        shown = D_8010CDF6_3AA7E6_name_5D;
    }
}

void func_801094E8_3A6ED8_name_5D(s16 n) {
    D_8010CCA4_3AA694_name_5D = D_8010CCA0_3AA690_name_5D[n][0];
    D_8010CCA6_3AA696_name_5D = D_8010CCA0_3AA690_name_5D[n][1];
    D_8010CCAA_3AA69A_name_5D = n;
}

void func_80109520_3A6F10_name_5D(s16 (*pos)[2]) {
    D_8010CCA0_3AA690_name_5D = pos;
}

void func_8010952C_3A6F1C_name_5D(s16 frames) {
    D_8010CCA8_3AA698_name_5D = frames;
}

void func_80109538_3A6F28_name_5D(s16 n) {
    D_8010CCAA_3AA69A_name_5D = n;
}

// register allocation, four instructions short: shared bump tail (0x800/0x400) merged by retail (masked 20)
#ifdef NON_MATCHING
void func_80109544_3A6F34_name_5D(void) {
    f32 zoom;
    f32 spd;
    f32 rx;
    f32 ry;
    f32 b;
    f32 inv;

    if (ContBtn[1] & 4) {
        if (ContBtn[0] & 0x2000) {
            zoom = D_800FA610_FB210 + 30.0f;
        } else {
            zoom = D_800FA610_FB210 + 10.0f;
        }
        D_800FA610_FB210 = zoom;
    }
    if ((ContBtn[1] & 8) && D_800FA610_FB210 - 10.0f != 0.0f) {
        if (ContBtn[1] & 0x2000) {
            zoom = D_800FA610_FB210 - 30.0f;
        } else {
            zoom = D_800FA610_FB210 - 10.0f;
        }
        D_800FA610_FB210 = zoom;
    }
    rx = D_8010CDE8_3AA7D8_name_5D.x;
    ry = D_8010CDE8_3AA7D8_name_5D.y;
    if (ContBtn[1] & 0x2000) {
        spd = 5.0f;
    } else {
        spd = 2.0f;
    }
    ry += -ContStkX[1] / 30 * spd;
    if (ry >= 360.0f) {
        ry -= 360.0f;
    } else if (ry < 0.0f) {
        ry += 360.0f;
    }
    D_8010CDE8_3AA7D8_name_5D.y = ry;
    rx += (s8)(ContStkY[1] / 30) * spd;
    if (rx >= 360.0f) {
        rx -= 360.0f;
    } else if (rx < 0.0f) {
        rx += 360.0f;
    }
    D_8010CDE8_3AA7D8_name_5D.x = rx;
    D_800FD474_FE074.x = (s16)rx;
    D_800FD474_FE074.y = (s16)D_8010CDE8_3AA7D8_name_5D.y;
    if (ContBtn[1] & 0x2000) {
        spd = 10.0f;
    } else {
        spd = 2.0f;
    }
    if (ContBtn[1] & 0x800) {
        b = HuMathSin(ry) * HuMathSin(rx);
        spd = -spd;
        b *= spd;
        D_8010274C_10334C.x += b;
        D_8010274C_10334C.y += func_800B7890_B8490(rx) * spd;
        D_8010274C_10334C.z += func_800B7890_B8490(ry) * HuMathSin(rx) * spd;
    } else if (ContBtn[1] & 0x400) {
        b = HuMathSin(ry) * HuMathSin(rx);
        b *= spd;
        D_8010274C_10334C.x += b;
        D_8010274C_10334C.y += func_800B7890_B8490(rx) * spd;
        D_8010274C_10334C.z += func_800B7890_B8490(ry) * HuMathSin(rx) * spd;
    } else if (ContBtn[1] & 0x200) {
        rx = D_800C9B80_CA780->pos.z - D_8010274C_10334C.z;
        b = -(D_800C9B80_CA780->pos.x - D_8010274C_10334C.x);
        inv = 1.0f / func_800B1830_B2430(rx * rx + b * b);
        D_8010274C_10334C.x += rx * inv * spd;
        D_8010274C_10334C.y += 0.0f;
        D_8010274C_10334C.z += b * inv * spd;
    } else if (ContBtn[1] & 0x100) {
        rx = -(D_800C9B80_CA780->pos.z - D_8010274C_10334C.z);
        b = D_800C9B80_CA780->pos.x - D_8010274C_10334C.x;
        inv = 1.0f / func_800B1830_B2430(rx * rx + b * b);
        D_8010274C_10334C.x += rx * inv * spd;
        D_8010274C_10334C.y += 0.0f;
        D_8010274C_10334C.z += b * inv * spd;
    }
    if (ContBtn[1] & 2) {
        D_8010B610_3A9000_name_5D += 1.0f;
    }
    if (ContBtn[1] & 1) {
        D_8010B610_3A9000_name_5D -= 1.0f;
    }
    Hu3DCamSetPerspective(0, D_8010B610_3A9000_name_5D, D_8010CDD4_3AA7C4_name_5D, D_8010CDBC_3AA7AC_name_5D);
    if (ContBtnTrg[1] & 0x4000) {
        osSyncPrintf("CRot   (%f,%f,%f)\n", (f64)D_800FD474_FE074.x, (f64)D_800FD474_FE074.y, (f64)D_800FD474_FE074.z);
        osSyncPrintf("Center (%f,%f,%f)\n", D_8010274C_10334C.x, D_8010274C_10334C.y, D_8010274C_10334C.z);
        osSyncPrintf("CZoom  %f CFovy %f\n", D_800FA610_FB210, D_8010B610_3A9000_name_5D);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5D_name/3A5AB0", func_80109544_3A6F34_name_5D);
#endif

void func_80109B68_3A7558_name_5D(void) {
    Vec pos;
    Vec at;
    Vec up;
    f32 rx;
    f32 ry;
    f32 rz;
    f32 ux;
    f32 uy;
    f32 uz;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 dist;

    while (1) {
        if (D_8010B614_3A9004_name_5D == 0) {
            rx = D_800FD474_FE074.x;
            ry = D_800FD474_FE074.y;
            rz = D_800FD474_FE074.z;
            pos.x = D_8010274C_10334C.x + HuMathSin(ry) * func_800B7890_B8490(rx) * D_800FA610_FB210;
            pos.y = D_8010274C_10334C.y + -HuMathSin(rx) * D_800FA610_FB210;
            pos.z = D_8010274C_10334C.z + func_800B7890_B8490(ry) * func_800B7890_B8490(rx) * D_800FA610_FB210;
            at.x = D_8010274C_10334C.x;
            at.y = D_8010274C_10334C.y;
            at.z = D_8010274C_10334C.z;
            ux = HuMathSin(ry) * HuMathSin(rx);
            uy = func_800B7890_B8490(rx);
            uz = func_800B7890_B8490(ry) * HuMathSin(rx);
            dx = at.x - pos.x;
            dy = at.y - pos.y;
            dz = at.z - pos.z;
            dist = func_800B1830_B2430(dx * dx + dy * dy + dz * dz);
            dx /= dist;
            dy /= dist;
            dz /= dist;
            up.x = ux * (dx * dx + (1.0f - dx * dx) * func_800B7890_B8490(rz))
                 + uy * (dx * dy * (1.0f - func_800B7890_B8490(rz)) - dz * HuMathSin(rz))
                 + uz * (dx * dz * (1.0f - func_800B7890_B8490(rz)) + dy * HuMathSin(rz));
            up.y = ux * (dx * dy * (1.0f - func_800B7890_B8490(rz)) + dz * HuMathSin(rz))
                 + uy * (dy * dy + (1.0f - dy * dy) * func_800B7890_B8490(rz))
                 + uz * (dy * dz * (1.0f - func_800B7890_B8490(rz)) - dx * HuMathSin(rz));
            up.z = ux * (dx * dz * (1.0f - func_800B7890_B8490(rz)) - dy * HuMathSin(rz))
                 + uy * (dy * dz * (1.0f - func_800B7890_B8490(rz)) + dx * HuMathSin(rz))
                 + uz * (dz * dz + (1.0f - dz * dz) * func_800B7890_B8490(rz));
        } else {
            pos = D_8010CE1C_3AA80C_name_5D;
            at = D_8010CDD8_3AA7C8_name_5D;
            up.x = 0.0f;
            up.y = 1.0f;
            up.z = 0.0f;
        }
        D_800FA5BC_FB1BC[0] = pos.x;
        D_800FA5BC_FB1BC[1] = pos.z;
        D_800FA5BC_FB1BC[-1] = D_800FD474_FE074.y;
        D_800FA5BC_FB1BC[2] = D_800C9B80_CA780->fov[0];
        D_800FA5BC_FB1BC[3] = D_80101078_101C78;
        D_800FA5BC_FB1BC[4] = D_800F8410_F9010;
        Hu3DCamSetPositionOrientation(0, &pos, &at, &up);
        Hu3DCamUpdateMtx(0);
        HuPrcVSleep();
    }
}

void func_8010A13C_3A7B2C_name_5D(Ovl5DModelDef* defs) {
    Ovl5DModelDef* def;
    s16 i;
    s16 model;

    def = defs;
    for (i = 0; def->file != -1; def++, i++) {
        model = LoadFormFile(def->file, def->attr | 0x288);
        D_8010CCD0_3AA6C0_name_5D[i] = model;
        func_8010A230_3A7C20_name_5D(defs, i, model);
        D_8010CDC0_3AA7B0_name_5D[i] = func_80029E14_2AA14(model);
        if (D_8010CDC0_3AA7B0_name_5D[i] != -1) {
            func_80029E80_2AA80(model, -1, def->unk0A);
        }
    }
}

void func_8010A230_3A7C20_name_5D(Ovl5DModelDef* defs, s16 i, s16 model) {
    Ovl5DModelDef* def = &defs[i];

    func_80029714_2A314(model, def->pos.x * 5.0f * 0.5f, def->pos.y * 5.0f * 0.5f, def->pos.z * 5.0f * 0.5f);
    func_8002979C_2A39C(model, def->rot.x, def->rot.y, def->rot.z);
    func_800297E8_2A3E8(model, 0.5f, 0.5f, 0.5f);
}

void func_8010A2FC_3A7CEC_name_5D(Ovl5DModelDef* def, s16 group) {
    s16 i;

    for (i = 0; def->file != -1; def++, i++) {
        if (def->group == group && (def->attr & 4) == 0 && D_800FC834_FD434[D_8010CCD0_3AA6C0_name_5D[i]].hmf->unk14 != 0) {
            func_800298A4_2A4A4(D_8010CCD0_3AA6C0_name_5D[i], 4, 0);
        } else {
            func_800298A4_2A4A4(D_8010CCD0_3AA6C0_name_5D[i], 4, 4);
        }
    }
}

void func_8010A3E4_3A7DD4_name_5D(s16 model, Vec* out, f32 mtx[4][4]) {
    f32 local[4][4];
    f32 world[4][4];
    HmfModel* m;

    m = &D_800FC834_FD434[model];
    func_800B1F50_B2B50(local, m->pos.x, m->pos.y, m->pos.z);
    func_80025884_26484(local, m->rot.x, m->rot.y, m->rot.z);
    func_80025830_26430(local, m->scale.x, m->scale.y, m->scale.z);
    func_80025BA4_267A4(mtx, local, world);
    out->x = world[0][0] + world[1][0] + world[2][0] + world[3][0];
    out->y = world[0][1] + world[1][1] + world[2][1] + world[3][1];
    out->z = world[0][2] + world[1][2] + world[2][2] + world[3][2];
}

void func_8010A4E4_3A7ED4_name_5D(s16 model, Vec2f* out, f32 mtx[4][4]) {
    Vec pos;

    func_8010A3E4_3A7DD4_name_5D(model, &pos, mtx);
    func_8010A524_3A7F14_name_5D(0, &pos, out);
}

// register allocation (masked 8)
#ifdef NON_MATCHING
void func_8010A524_3A7F14_name_5D(s16 cam, Vec* in, Vec2f* out) {
    f32 mtx[4][4];
    Vec pos;
    Vec at;
    Vec up;
    f32 rx;
    f32 ry;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 vx;
    f32 vy;
    f32 vz;

    rx = D_800FD474_FE074.x;
    ry = D_800FD474_FE074.y;
    pos.x = HuMathSin(ry) * func_800B7890_B8490(rx) * D_800FA610_FB210 + D_8010274C_10334C.x;
    pos.y = -HuMathSin(rx) * D_800FA610_FB210 + D_8010274C_10334C.y;
    pos.z = func_800B7890_B8490(ry) * func_800B7890_B8490(rx) * D_800FA610_FB210 + D_8010274C_10334C.z;
    at = D_8010274C_10334C;
    up.x = HuMathSin(ry) * HuMathSin(rx);
    up.y = func_800B7890_B8490(rx);
    up.z = func_800B7890_B8490(ry) * HuMathSin(rx);
    func_800B1960_B2560(mtx, pos.x, pos.y, pos.z, at.x, at.y, at.z, up.x, up.y, up.z);
    dx = in->x;
    dy = in->y;
    dz = in->z;
    dx -= pos.x;
    dy -= pos.y;
    dz -= pos.z;
    vx = dx * mtx[0][0] + dy * mtx[1][0] + dz * mtx[2][0];
    vy = dx * mtx[0][1] + dy * mtx[1][1] + dz * mtx[2][1];
    vz = dx * mtx[0][2] + dy * mtx[1][2] + dz * mtx[2][2];
    dx = HuMathSin(D_8010B610_3A9000_name_5D / 2.0f) / func_800B7890_B8490(D_8010B610_3A9000_name_5D / 2.0f) * vz * 1.3333334f;
    dy = HuMathSin(D_8010B610_3A9000_name_5D / 2.0f) / func_800B7890_B8490(D_8010B610_3A9000_name_5D / 2.0f) * vz;
    if (vz < 0.0f) {
        out->unk_00 = vx * (160.0f / -dx) + 160.0f;
        out->unk_04 = vy * (120.0f / dy) + 120.0f;
    } else {
        out->unk_04 = -200.0f;
        out->unk_00 = -200.0f;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5D_name/3A5AB0", func_8010A524_3A7F14_name_5D);
#endif

void func_8010A82C_3A821C_name_5D(s16 view, f32 depth, Vec2f* scr, Vec* out) {
    f32 mtx[4][4];
    Vec pos;
    Vec at;
    Vec up;
    Ovl5DCamView* v;
    f32 rx;
    f32 ry;
    f32 zoom;
    f32 h;
    f32 w;
    f32 x;
    f32 y;
    f32 sx;
    f32 sy;

    v = &D_8010CCE8_3AA6D8_name_5D[view];
    rx = v->rot.x;
    ry = v->rot.y;
    zoom = v->zoom;
    pos.x = HuMathSin(ry) * func_800B7890_B8490(rx) * zoom + v->at.x;
    pos.y = -HuMathSin(rx) * zoom + v->at.y;
    pos.z = func_800B7890_B8490(ry) * func_800B7890_B8490(rx) * zoom + v->at.z;
    at = v->at;
    up.x = HuMathSin(ry) * HuMathSin(rx);
    up.y = func_800B7890_B8490(rx);
    up.z = func_800B7890_B8490(ry) * HuMathSin(rx);
    depth = -depth;
    func_800B1960_B2560(mtx, pos.x, pos.y, pos.z, at.x, at.y, at.z, up.x, up.y, up.z);
    h = HuMathSin(D_8010B610_3A9000_name_5D / 2.0f) / func_800B7890_B8490(D_8010B610_3A9000_name_5D / 2.0f) * depth;
    w = h * 1.3333334f;
    x = 320.0f - scr->unk_00;
    y = 240.0f - scr->unk_04;
    sx = x / 320.0f;
    sy = (240.0f - y) / 240.0f;
    x = (w + w) * sx - w;
    y = (h + h) * sy - h;
    out->x = x * mtx[0][0] + y * mtx[0][1] + depth * mtx[0][2] + pos.x;
    out->y = x * mtx[1][0] + y * mtx[1][1] + depth * mtx[1][2] + pos.y;
    out->z = x * mtx[2][0] + y * mtx[2][1] + depth * mtx[2][2] + pos.z;
}

s16 func_8010AAE4_3A84D4_name_5D(void) {
    s16 spr;
    s16 i;

    D_8010CCAC_3AA69C_name_5D = func_8001A2F8_1AEF8(0x900C9);
    spr = func_8001AAAC_1B6AC(D_8010CCAC_3AA69C_name_5D, 0, 1);
    D_8010CCAE_3AA69E_name_5D = spr;
    for (i = 0; i < 3; i++) {
        D_8010CCB4_3AA6A4_name_5D[i] = func_80027154_27D54(0x6000, 0x7918);
    }
    D_8010CCC0_3AA6B0_name_5D = **(void***)func_80082550_83150(D_800F93FC_F9FFC[spr].grp, 0)->unk_84;
    D_8010CCB0_3AA6A0_name_5D = 0;
    espDispOff(spr);
    return spr;
}

void func_8010ABDC_3A85CC_name_5D(s16 file) {
    void* image;
    void* pal;
    u8* work;
    s16 n;

    image = DataRead(file | 0xB0000);
    pal = DataRead((file + 1) | 0xB0000);
    func_80096C10_97810(0xFF);
    func_80096708_97308(pal);
    work = HuMemMemoryAllocPerm(0xC00);
    func_80096188_96D88(image, D_8010CCB4_3AA6A4_name_5D[D_8010CCB0_3AA6A0_name_5D], 0x80, work);
    HuMemMemoryFreePerm(work);
    DataClose(image);
    DataClose(pal);
    **(void***)func_80082550_83150(D_800F93FC_F9FFC[D_8010CCAE_3AA69E_name_5D].grp, 0)->unk_84 = D_8010CCB4_3AA6A4_name_5D[n = D_8010CCB0_3AA6A0_name_5D];
    if ((D_8010CCB0_3AA6A0_name_5D = n + 1) >= 3) {
        D_8010CCB0_3AA6A0_name_5D = 0;
    }
    espDispOn(D_8010CCAE_3AA69E_name_5D);
}

void func_8010AD10_3A8700_name_5D(void) {
    s16 i;

    **(void***)func_80082550_83150(D_800F93FC_F9FFC[D_8010CCAE_3AA69E_name_5D].grp, 0)->unk_84 = D_8010CCC0_3AA6B0_name_5D;
    func_8001AC44_1B844(D_8010CCAE_3AA69E_name_5D);
    SprAnimKill(D_8010CCAC_3AA69C_name_5D);
    for (i = 0; i < 3; i++) {
        HuMemFree(D_8010CCB4_3AA6A4_name_5D[i]);
    }
}
