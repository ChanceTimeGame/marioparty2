#include "ovl_5C.h"

/* Sets the camera to a view of D_801129F0_3A08B0_name_5C. */
void func_80107480_395340_name_5C(s16 view) {
    f32 a;

    a = D_801129F0_3A08B0_name_5C[view].rot.x;
    if (a >= 360.0f) {
        a -= 360.0f;
    } else if (a < 0.0f) {
        a += 360.0f;
    }
    D_800FD474_FE074.x = a;
    D_801129F4_3A08B4_name_5C.x = a;
    a = D_801129F0_3A08B0_name_5C[view].rot.y;
    if (a >= 360.0f) {
        a -= 360.0f;
    } else if (a < 0.0f) {
        a += 360.0f;
    }
    D_800FD474_FE074.y = a;
    D_801129F4_3A08B4_name_5C.y = a;
    a = D_801129F0_3A08B0_name_5C[view].rot.z;
    if (a >= 360.0f) {
        a -= 360.0f;
    } else if (a < 0.0f) {
        a += 360.0f;
    }
    D_800FD474_FE074.z = a;
    D_801129F4_3A08B4_name_5C.z = a;
    D_8010274C_10334C = D_801129F0_3A08B0_name_5C[view].at;
    D_800FA610_FB210 = D_801129F0_3A08B0_name_5C[view].zoom;
}

/* Moves the camera to a view over `time` frames; mode 1 eases out, 2 eases both ways, else
   linear. `cb` (-1 none) gets { frame, time } each frame. */
void func_80107660_395520_name_5C(s16 view, s16 time, s16 mode, void (*cb)(s16*)) {
    Vec dr;
    Vec da;
    Vec r0;
    Vec a0;
    s16 arg[2];
    Vec pad[3]; /* unused; retail's frame has it */
    void (*fn)(s16*);
    f32 d;
    f32 s;
    f32 a;
    f32 dz;
    f32 z0;
    s16 i;

    fn = cb;
    d = D_801129F0_3A08B0_name_5C[view].rot.x - D_800FD474_FE074.x;
    if (ABS(d) > 180.0f) {
        if (D_801129F0_3A08B0_name_5C[view].rot.x < D_800FD474_FE074.x) {
            dr.x = d + 360.0f;
        } else {
            dr.x = d - 360.0f;
        }
    } else {
        dr.x = d;
    }
    d = D_801129F0_3A08B0_name_5C[view].rot.y - D_800FD474_FE074.y;
    if (ABS(d) > 180.0f) {
        if (D_801129F0_3A08B0_name_5C[view].rot.y < D_800FD474_FE074.y) {
            dr.y = d + 360.0f;
        } else {
            dr.y = d - 360.0f;
        }
    } else {
        dr.y = d;
    }
    d = D_801129F0_3A08B0_name_5C[view].rot.z - D_800FD474_FE074.z;
    if (ABS(d) > 180.0f) {
        if (D_801129F0_3A08B0_name_5C[view].rot.z < D_800FD474_FE074.z) {
            dr.z = d + 360.0f;
        } else {
            dr.z = d - 360.0f;
        }
    } else {
        dr.z = d;
    }
    da.x = D_801129F0_3A08B0_name_5C[view].at.x - D_8010274C_10334C.x;
    da.y = D_801129F0_3A08B0_name_5C[view].at.y - D_8010274C_10334C.y;
    da.z = D_801129F0_3A08B0_name_5C[view].at.z - D_8010274C_10334C.z;
    dz = D_801129F0_3A08B0_name_5C[view].zoom - D_800FA610_FB210;
    a0 = D_8010274C_10334C;
    r0 = D_800FD474_FE074;
    z0 = D_800FA610_FB210;
    arg[1] = time;
    if (mode == 1 || mode == 2) {
        for (i = 0; i < time; i++) {
            if (mode != 2) {
                s = HuMathSin(i * 90.0f / time);
            } else if (i <= time / 2) {
                s = (1.0f - func_800B7890_B8490(i * 180.0f / time)) * 0.5f;
            } else {
                s = -func_800B7890_B8490(i * 180.0f / time) * 0.5f + 0.5f;
            }
            a = s * dr.x + r0.x;
            if (a >= 360.0f) {
                a -= 360.0f;
            } else if (a < 0.0f) {
                a += 360.0f;
            }
            D_800FD474_FE074.x = a;
            D_801129F4_3A08B4_name_5C.x = a;
            a = s * dr.y + r0.y;
            if (a >= 360.0f) {
                a -= 360.0f;
            } else if (a < 0.0f) {
                a += 360.0f;
            }
            D_800FD474_FE074.y = a;
            D_801129F4_3A08B4_name_5C.y = a;
            a = s * dr.z + r0.z;
            if (a >= 360.0f) {
                a -= 360.0f;
            } else if (a < 0.0f) {
                a += 360.0f;
            }
            D_800FD474_FE074.z = a;
            D_801129F4_3A08B4_name_5C.x = a; /* retail: .x, not .z */
            D_8010274C_10334C.x = s * da.x + a0.x;
            D_8010274C_10334C.y = s * da.y + a0.y;
            D_8010274C_10334C.z = s * da.z + a0.z;
            D_800FA610_FB210 = s * dz + z0;
            if (cb != (void*)-1) {
                arg[0] = i;
                fn(arg);
            }
            HuPrcVSleep();
        }
    } else {
        for (i = 0; i <= time; i++) {
            s = 1.0f / time * i;
            a = s * dr.x + r0.x;
            if (a >= 360.0f) {
                a -= 360.0f;
            } else if (a < 0.0f) {
                a += 360.0f;
            }
            D_800FD474_FE074.x = a;
            D_801129F4_3A08B4_name_5C.x = a;
            a = s * dr.y + r0.y;
            if (a >= 360.0f) {
                a -= 360.0f;
            } else if (a < 0.0f) {
                a += 360.0f;
            }
            D_800FD474_FE074.y = a;
            D_801129F4_3A08B4_name_5C.y = a;
            a = s * dr.z + r0.z;
            if (a >= 360.0f) {
                a -= 360.0f;
            } else if (a < 0.0f) {
                a += 360.0f;
            }
            D_800FD474_FE074.z = a;
            D_801129F4_3A08B4_name_5C.x = a; /* retail: .x, not .z */
            D_8010274C_10334C.x = s * da.x + a0.x;
            D_8010274C_10334C.y = s * da.y + a0.y;
            D_8010274C_10334C.z = s * da.z + a0.z;
            D_800FA610_FB210 = s * dz + z0;
            if (cb != (void*)-1) {
                arg[0] = i;
                fn(arg);
            }
            HuPrcVSleep();
        }
    }
    func_80107480_395340_name_5C(view);
}

/* Flies the camera along a path of views by Catmull-Rom over node times; `cb` (-1 none) gets
   (frames, node, frame). */
// register allocation: loop setup order and the tail pointers (masked 16)
#ifdef NON_MATCHING
void func_80107F28_395DE8_name_5C(Ovl5CCamNode* path, f32 speed, void (*cb)(s16, s16, s16)) {
    f32 p[4];
    f32 tm[4];
    void (*fn)(s16, s16, s16);
    Ovl5CCamNode* prev = NULL;
    Ovl5CCamNode* n;
    s16 i;
    s16 k;
    f32 t;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 d;
    f32 s;
    f32 end;

    fn = cb;
    t = 0.0f;
    i = 0;
    n = path;
    while (n->zoom != 0.0f) {
        s = HuMathSin(n->rot.y);
        s *= func_800B7890_B8490(n->rot.x);
        s *= n->zoom;
        s += n->at.x;
        n->eye.x = s;
        n->eye.y = -HuMathSin(n->rot.x) * n->zoom + n->at.y;
        s = func_800B7890_B8490(n->rot.y);
        s *= func_800B7890_B8490(n->rot.x);
        s *= n->zoom;
        s += n->at.z;
        n->eye.z = s;
        if (i > 0) {
            dx = prev->eye.x - n->eye.x;
            dy = prev->eye.y - n->eye.y;
            dz = prev->eye.z - s;
            d = func_800B1830_B2430(dx * dx + dy * dy + dz * dz);
            if (d == 0.0f) {
                d = speed * 10.0f;
            }
            t += d / speed;
            n->t = t;
        }
        prev = n;
        i++;
        n = &path[i];
    }
    end = t - 10.0f;
    k = 1;
    i = 10;
    if (i < end) {
        do {
            if (i > path[k + 1].t) {
                k++;
            }
            n = k + path;
            tm[0] = n[-1].t;
            tm[1] = n[0].t;
            tm[2] = n[1].t;
            tm[3] = n[2].t;
            p[0] = n[-1].at.x;
            p[1] = n[0].at.x;
            p[2] = n[1].at.x;
            p[3] = n[2].at.x;
            D_8010274C_10334C.x = func_8002662C_2722C(p, tm, i);
            p[0] = n[-1].at.y;
            p[1] = n[0].at.y;
            p[2] = n[1].at.y;
            p[3] = n[2].at.y;
            D_8010274C_10334C.y = func_8002662C_2722C(p, tm, i);
            p[0] = n[-1].at.z;
            p[1] = n[0].at.z;
            p[2] = n[1].at.z;
            p[3] = n[2].at.z;
            D_8010274C_10334C.z = func_8002662C_2722C(p, tm, i);
            p[0] = n[-1].rot.x;
            p[1] = n[0].rot.x;
            p[2] = n[1].rot.x;
            p[3] = n[2].rot.x;
            D_801129F4_3A08B4_name_5C.x = D_800FD474_FE074.x = func_8002662C_2722C(p, tm, i);
            p[0] = n[-1].rot.y;
            p[1] = n[0].rot.y;
            p[2] = n[1].rot.y;
            p[3] = n[2].rot.y;
            D_801129F4_3A08B4_name_5C.y = D_800FD474_FE074.y = func_8002662C_2722C(p, tm, i);
            p[0] = n[-1].rot.z;
            p[1] = n[0].rot.z;
            p[2] = n[1].rot.z;
            p[3] = n[2].rot.z;
            D_801129F4_3A08B4_name_5C.z = D_800FD474_FE074.z = func_8002662C_2722C(p, tm, i);
            p[0] = n[-1].zoom;
            p[1] = n[0].zoom;
            p[2] = n[1].zoom;
            p[3] = n[2].zoom;
            D_800FA610_FB210 = func_8002662C_2722C(p, tm, i);
            if (D_800FA610_FB210 >= 700.0f) {
                Hu3DCamSetPerspective(0, D_80111C40_39FB00_name_5C, D_80112F24_3A0DE4_name_5C, D_80112F54_3A0E14_name_5C);
            }
            if (cb != (void*)-1) {
                fn(end, k, i);
            }
            HuPrcVSleep();
            i++;
        } while (i < end);
    }
    n = &path[(s16)(k + 1)];
    D_800FD474_FE074.x = D_801129F4_3A08B4_name_5C.x = n->rot.x;
    D_800FD474_FE074.y = D_801129F4_3A08B4_name_5C.y = n->rot.y;
    D_800FD474_FE074.z = D_801129F4_3A08B4_name_5C.z = n->rot.z;
    D_800FA610_FB210 = n->zoom;
    D_8010274C_10334C.x = n->at.x;
    D_8010274C_10334C.y = n->at.y;
    D_8010274C_10334C.z = n->at.z;
    D_800F851A_F911A = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/395340", func_80107F28_395DE8_name_5C);
#endif

void func_801084C4_396384_name_5C(void) {
    s16 last = -1;
    s16 i;
    s16 x0;
    s16 dx;
    s16 y0;
    s16 dy;
    f32 s;
    s16* to;

    D_80112424_3A02E4_name_5C = 0;
    D_80112F38_3A0DF8_name_5C = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x900F8), 0, 1);
    func_8001A788_1B388(D_80112F38_3A0DF8_name_5C, 1);
    espPosSet(D_80112F38_3A0DF8_name_5C, 160, 120);
    espDispOff(D_80112F38_3A0DF8_name_5C);
    D_80112374_3A0234_name_5C = 160;
    D_80112376_3A0236_name_5C = 120;
    D_80112378_3A0238_name_5C = 10;
    omAddPrcObj(func_80108758_396618_name_5C, 0x3F00, 0x100, 0);
    while (1) {
        HuPrcVSleep();
        if (D_80112424_3A02E4_name_5C != 0) {
            if (last != D_8011237A_3A023A_name_5C && D_8011237A_3A023A_name_5C != -1) {
                x0 = D_80112374_3A0234_name_5C;
                y0 = D_80112376_3A0236_name_5C;
                to = D_80112370_3A0230_name_5C[D_8011237A_3A023A_name_5C];
                dx = to[0] - x0;
                dy = to[1] - y0;
                for (i = 1; i <= D_80112378_3A0238_name_5C; i++) {
                    s = HuMathSin(90.0f / D_80112378_3A0238_name_5C * i);
                    D_80112374_3A0234_name_5C = x0 + dx * s;
                    D_80112376_3A0236_name_5C = y0 + dy * s;
                    espPosSet(D_80112F38_3A0DF8_name_5C, D_80112374_3A0234_name_5C,
                              D_80112376_3A0236_name_5C);
                    HuPrcVSleep();
                }
                last = D_8011237A_3A023A_name_5C;
            }
        } else {
            last = D_8011237A_3A023A_name_5C;
        }
        espPosSet(D_80112F38_3A0DF8_name_5C, D_80112374_3A0234_name_5C, D_80112376_3A0236_name_5C);
    }
}

void func_80108758_396618_name_5C(void) {
    s16 shown;
    s16 i;

    shown = 0;
    while (1) {
        HuPrcVSleep();
        if (shown == D_80112424_3A02E4_name_5C) {
            continue;
        }
        if (D_80112424_3A02E4_name_5C != 0) {
            espDispOn(D_80112F38_3A0DF8_name_5C);
            for (i = 0; i < 5; i++) {
                func_8001A6BC_1B2BC(D_80112F38_3A0DF8_name_5C, i * 63.75f);
                HuPrcVSleep();
            }
        } else {
            for (i = 0; i < 5; i++) {
                func_8001A6BC_1B2BC(D_80112F38_3A0DF8_name_5C, 255.0f - i * 63.75f);
                HuPrcVSleep();
            }
            espDispOff(D_80112F38_3A0DF8_name_5C);
        }
        shown = D_80112424_3A02E4_name_5C;
    }
}

void func_801088A8_396768_name_5C(s16 n) {
    D_80112374_3A0234_name_5C = D_80112370_3A0230_name_5C[n][0];
    D_80112376_3A0236_name_5C = D_80112370_3A0230_name_5C[n][1];
    D_8011237A_3A023A_name_5C = n;
}

void func_801088E0_3967A0_name_5C(s16 (*slots)[2]) {
    D_80112370_3A0230_name_5C = slots;
}

void func_801088EC_3967AC_name_5C(s16 time) {
    D_80112378_3A0238_name_5C = time;
}

void func_801088F8_3967B8_name_5C(s16 slot) {
    D_8011237A_3A023A_name_5C = slot;
}

#ifdef NON_MATCHING
/* Same instruction count; differs in float register allocation (rx/spd swapped) and where the
   D_8010274C base is loaded in the 0x800/0x400 arms (retail cross-jumps the 0x800 arm into the
   0x400 arm at b *= spd, neg.s in the delay slot). masked 20 raw 62. Tried (S3-R13): += in the zoom
   arms (20), rx before spd (20), spd = -spd first (whole arm cross-jumped, 46), b *= spd = -spd (20). */
void func_80108904_3967C4_name_5C(void) {
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
    rx = D_801129F4_3A08B4_name_5C.x;
    ry = D_801129F4_3A08B4_name_5C.y;
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
    D_801129F4_3A08B4_name_5C.y = ry;
    rx += (s8)(ContStkY[1] / 30) * spd;
    if (rx >= 360.0f) {
        rx -= 360.0f;
    } else if (rx < 0.0f) {
        rx += 360.0f;
    }
    D_801129F4_3A08B4_name_5C.x = rx;
    D_800FD474_FE074.x = (s16)rx;
    D_800FD474_FE074.y = (s16)D_801129F4_3A08B4_name_5C.y;
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
        D_80111C40_39FB00_name_5C += 1.0f;
    }
    if (ContBtn[1] & 1) {
        D_80111C40_39FB00_name_5C -= 1.0f;
    }
    Hu3DCamSetPerspective(0, D_80111C40_39FB00_name_5C, D_80112F24_3A0DE4_name_5C, D_80112F54_3A0E14_name_5C);
    if (ContBtnTrg[1] & 0x4000) {
        osSyncPrintf("CRot   (%f,%f,%f)\n", D_800FD474_FE074.x, D_800FD474_FE074.y, D_800FD474_FE074.z);
        osSyncPrintf("Center (%f,%f,%f)\n", D_8010274C_10334C.x, D_8010274C_10334C.y, D_8010274C_10334C.z);
        osSyncPrintf("CZoom  %f CFovy %f\n", D_800FA610_FB210, D_80111C40_39FB00_name_5C);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/395340", func_80108904_3967C4_name_5C);
#endif

void func_80108F28_396DE8_name_5C(void) {
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
        if (D_80111C44_39FB04_name_5C == 0) {
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
            pos = D_80112FA0_3A0E60_name_5C;
            at = D_80112F2C_3A0DEC_name_5C;
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

void func_801094FC_3973BC_name_5C(Ovl5CModelDef* defs) {
    Ovl5CModelDef* def;
    s16 i;
    s16 model;

    def = defs;
    for (i = 0; def->file != -1; def++, i++) {
        model = LoadFormFile(def->file, def->attr | 0x288);
        D_80112F60_3A0E20_name_5C[i] = model;
        func_801095F0_3974B0_name_5C(defs, i, model);
        D_80112498_3A0358_name_5C[i] = func_80029E14_2AA14(model);
        if (D_80112498_3A0358_name_5C[i] != -1) {
            func_80029E80_2AA80(model, -1, def->unk0A);
        }
    }
}

void func_801095F0_3974B0_name_5C(Ovl5CModelDef* defs, s16 i, s16 model) {
    Ovl5CModelDef* def = &defs[i];

    func_80029714_2A314(model, def->pos.x * 5.0f * 0.5f, def->pos.y * 5.0f * 0.5f, def->pos.z * 5.0f * 0.5f);
    func_8002979C_2A39C(model, def->rot.x, def->rot.y, def->rot.z);
    func_800297E8_2A3E8(model, 0.5f, 0.5f, 0.5f);
}

/* Shows the models of one place (a list's `place` field) and hides the rest. */
void func_801096BC_39757C_name_5C(Ovl5CModelDef* defs, s16 place) {
    Ovl5CModelDef* def = defs;
    s16 i;

    for (i = 0; def->file != -1; def++, i++) {
        if (def->place == place && !(def->attr & 4) && D_800FC834_FD434[D_80112F60_3A0E20_name_5C[i]].hmf->unk14 != 0) {
            func_800298A4_2A4A4(D_80112F60_3A0E20_name_5C[i], 4, 0);
        } else {
            func_800298A4_2A4A4(D_80112F60_3A0E20_name_5C[i], 4, 4);
        }
    }
}

void func_801097A4_397664_name_5C(s16 model, Vec* out, f32 mtx[4][4]) {
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

void func_801098A4_397764_name_5C(s16 model, Vec2f* out, f32 mtx[4][4]) {
    Vec pos;

    func_801097A4_397664_name_5C(model, &pos, mtx);
    func_801098E4_3977A4_name_5C(0, &pos, out);
}

void func_801098E4_3977A4_name_5C(s16 unused, Vec* in, Vec2f* out) {
    f32 mtx[4][4];
    Vec pos;
    Vec at;
    Vec up;
    f32 rx;
    f32 ry;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 x;
    f32 y;
    f32 z;

    rx = D_800FD474_FE074.x;
    ry = D_800FD474_FE074.y;
    pos.x = D_8010274C_10334C.x + HuMathSin(ry) * func_800B7890_B8490(rx) * D_800FA610_FB210;
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
    x = dx * mtx[0][0] + dy * mtx[1][0] + dz * mtx[2][0];
    y = dx * mtx[0][1] + dy * mtx[1][1] + dz * mtx[2][1];
    z = dx * mtx[0][2] + dy * mtx[1][2] + dz * mtx[2][2];
    dx = HuMathSin(D_80111C40_39FB00_name_5C / 2.0f) / func_800B7890_B8490(D_80111C40_39FB00_name_5C / 2.0f) * z * 1.3333334f;
    dy = HuMathSin(D_80111C40_39FB00_name_5C / 2.0f) / func_800B7890_B8490(D_80111C40_39FB00_name_5C / 2.0f) * z;
    if (z < 0.0f) {
        out->unk_00 = x * (160.0f / -dx) + 160.0f;
        out->unk_04 = y * (120.0f / dy) + 120.0f;
    } else {
        out->unk_00 = out->unk_04 = -200.0f;
    }
}

void func_80109BEC_397AAC_name_5C(s16 view, f32 depth, Vec2f* scr, Vec* out) {
    f32 mtx[4][4];
    Vec pos;
    Vec at;
    Vec up;
    Ovl5CCamView* v;
    f32 rx;
    f32 ry;
    f32 zoom;
    f32 h;
    f32 w;
    f32 x;
    f32 y;
    f32 sx;
    f32 sy;

    v = &D_801129F0_3A08B0_name_5C[view];
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
    h = HuMathSin(D_80111C40_39FB00_name_5C / 2.0f) / func_800B7890_B8490(D_80111C40_39FB00_name_5C / 2.0f) * depth;
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

s16 func_80109EA4_397D64_name_5C(void) {
    s16 sprGrp;
    s16 i;

    D_8011237C_3A023C_name_5C = func_8001A2F8_1AEF8(0x900C9);
    sprGrp = func_8001AAAC_1B6AC(D_8011237C_3A023C_name_5C, 0, 1);
    D_8011237E_3A023E_name_5C = sprGrp;
    for (i = 0; i < 3; i++) {
        D_80112384_3A0244_name_5C[i] = func_80027154_27D54(0x6000, 0x7918);
    }
    D_80112390_3A0250_name_5C = func_80082550_83150(((Ovl5CEsprite*)D_800F93FC_F9FFC)[sprGrp].group, 0)->unk_84->unk00->unk00;
    D_80112380_3A0240_name_5C = 0;
    espDispOff(sprGrp);
    return sprGrp;
}

void func_80109F9C_397E5C_name_5C(s16 file) {
    void* sprData;
    void* palData;
    void* buf;

    sprData = DataRead(file | 0xB0000);
    palData = DataRead((file + 1) | 0xB0000);
    func_80096C10_97810(0xFF);
    func_80096708_97308(palData);
    buf = HuMemMemoryAllocPerm(0xC00);
    func_80096188_96D88(sprData, D_80112384_3A0244_name_5C[D_80112380_3A0240_name_5C], 0x80, buf);
    HuMemMemoryFreePerm(buf);
    DataClose(sprData);
    DataClose(palData);
    func_80082550_83150(((Ovl5CEsprite*)D_800F93FC_F9FFC)[D_8011237E_3A023E_name_5C].group, 0)->unk_84->unk00->unk00 =
        D_80112384_3A0244_name_5C[D_80112380_3A0240_name_5C];
    D_80112380_3A0240_name_5C++;
    if (D_80112380_3A0240_name_5C >= 3) {
        D_80112380_3A0240_name_5C = 0;
    }
    espDispOn(D_8011237E_3A023E_name_5C);
}

void func_8010A0D0_397F90_name_5C(void) {
    s16 i;

    func_80082550_83150(((Ovl5CEsprite*)D_800F93FC_F9FFC)[D_8011237E_3A023E_name_5C].group, 0)->unk_84->unk00->unk00 = D_80112390_3A0250_name_5C;
    func_8001AC44_1B844(D_8011237E_3A023E_name_5C);
    SprAnimKill(D_8011237C_3A023C_name_5C);
    for (i = 0; i < 3; i++) {
        HuMemFree(D_80112384_3A0244_name_5C[i]);
    }
}

/* .data (0x39FB00-0x39FB10, 80111C40-80111C50) */
f32 D_80111C40_39FB00_name_5C = 58.0f;
s8 D_80111C44_39FB04_name_5C = 0;
s8 D_80111C45_39FB05_name_5C = 0; /* padding */
s8 D_80111C46_39FB06_name_5C = 0;
s8 D_80111C47_39FB07_name_5C = 0;
s32 D_80111C48_39FB08_name_5C[2] = { 0, 0 };
