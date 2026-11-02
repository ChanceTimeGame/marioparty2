#include "ovl_22.h"

/* .data (1E11C0-1E1260, 8010CAE0-8010CB80) */
SSRect D_8010CAE0_1E11C0_ShellShocked[4] = {
    { 24.0f, 16.0f, 159.0f, 119.0f },
    { 161.0f, 16.0f, 296.0f, 119.0f },
    { 24.0f, 121.0f, 159.0f, 224.0f },
    { 161.0f, 121.0f, 296.0f, 224.0f },
};
SSView D_8010CB20_1E1200_ShellShocked[4] = {
    { 320.0f, 240.0f, 511.0f, 368.0f, 300.0f, 511.0f },
    { 320.0f, 240.0f, 511.0f, 912.0f, 300.0f, 511.0f },
    { 320.0f, 240.0f, 511.0f, 368.0f, 720.0f, 511.0f },
    { 320.0f, 240.0f, 511.0f, 912.0f, 720.0f, 511.0f },
};

// register allocation and float temporaries (masked 78, 1241 vs 1250: one extra saved float, $f30); rect fields read inline as retail does
#ifdef NON_MATCHING
/* The views' final rectangles as the winner's view opens: winner * 4 + view. */
const SSRect D_8010CFA0_1E1680_ShellShocked[16] = {
    { 24.0f, 16.0f, 294.0f, 222.0f }, { 296.0f, 16.0f, 296.0f, 224.0f }, { 24.0f, 224.0f, 296.0f, 224.0f }, { 296.0f, 224.0f, 296.0f, 224.0f },
    { 24.0f, 16.0f, 24.0f, 224.0f }, { 26.0f, 16.0f, 296.0f, 222.0f }, { 24.0f, 224.0f, 24.0f, 224.0f }, { 24.0f, 224.0f, 296.0f, 224.0f },
    { 24.0f, 16.0f, 296.0f, 16.0f }, { 296.0f, 16.0f, 296.0f, 16.0f }, { 24.0f, 18.0f, 296.0f, 222.0f }, { 296.0f, 16.0f, 296.0f, 224.0f },
    { 24.0f, 16.0f, 24.0f, 16.0f }, { 24.0f, 16.0f, 296.0f, 16.0f }, { 24.0f, 16.0f, 24.0f, 224.0f }, { 26.0f, 18.0f, 296.0f, 224.0f },
};

const f32 D_8010D0A0_1E1780_ShellShocked[6] = { 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f };

void func_80103B90_1D8270_ShellShocked(s32 i) {
    Vec center;
    Vec a;
    Vec b;
    Vec c;
    Vec d;
    Vec e;
    Vec h;
    Vec g;
    Vec f;
    SSCam* cam;
    SSTank* tank;
    Vec* pos;
    f32 angle;
    f32 s;
    f32 u;
    f32 frac;
    f32 w;
    f32 co;
    f32 t;
    f32 dx1;
    f32 dy1;
    f32 dx2;
    f32 dy2;
    s32 n;
    s32 who;

    cam = &D_8010D5E0_1E1CC0_ShellShocked[i];
    tank = &D_8010DA80_1E2160_ShellShocked[cam->index];
    switch (cam->state) {
    default:
        if (func_8010C1F0_1E08D0_ShellShocked(cam->index) != 0) {
            func_80105044_1D9724_ShellShocked(i, 5);
        }
        break;
    case 0:
    case 2:
    case 3:
    case 4:
    case 5:
    case 20:
    case 21:
    case 22:
        break;
    }
    switch (cam->state) {
    case 0:
        HuVecCopyXYZ(&cam->pos, 0.0f, 100.0f, 0.0f);
        HuVecCopyXYZ(&cam->at, 0.0f, 1.0f, -100.0f);
        HuVecCopyXYZ(&cam->up, 0.0f, 1.0f, 0.0f);
        Hu3DCamSetPerspective(i, 80.0f, 400.0f, 2000.0f);
        Hu3DCamSetPositionOrientation(i, &cam->pos, &cam->at, &cam->up);
        func_80105044_1D9724_ShellShocked(i, 2);
        break;
    case 6:
        HuVecCopyXYZ(&cam->at, center.x, center.y, center.z);
        HuVecCopyXYZ(&cam->pos, center.x + cam->off.x, center.y + cam->off.y, center.z + cam->off.z);
        Hu3DCamSetPerspective(i, cam->fov, cam->aspect, cam->far);
        Hu3DCamSetPositionOrientation(i, &cam->pos, &cam->at, &cam->up);
        break;
    case 5:
        u = tank->rot.y;
        s = cam->dist;
        u = u > 270.0f ? u - 270.0f : tank->rot.y + 90.0f;
        center.x = tank->pos.x;
        center.y = tank->pos.y + 100.0f;
        center.z = tank->pos.z;
        cam->off.x = s * func_800B7890_B8490(u);
        cam->off.y = cam->dist * 0.1f + 100.0f;
        cam->off.z = -s * HuMathSin(u);
        HuVecCopyXYZ(&cam->at, center.x, center.y, center.z);
        HuVecCopyXYZ(&cam->pos, center.x + cam->off.x, center.y + cam->off.y, center.z + cam->off.z);
        HuVecCopyXYZ(&cam->up, 0.0f, 1.0f, 0.0f);
        Hu3DCamSetPerspective(i, cam->fov, cam->aspect, cam->far);
        Hu3DCamSetPositionOrientation(i, &cam->pos, &cam->at, &cam->up);
        break;
    case 8:
        cam->orbit = tank->rot.y;
        cam->orbit = cam->orbit > 270.0f ? cam->orbit - 270.0f : cam->orbit + 90.0f;
        center.x = tank->pos.x;
        center.y = tank->pos.y + 100.0f;
        center.z = tank->pos.z;
        break;
    case 9:
        func_80105044_1D9724_ShellShocked(i, 9);
        t = cam->orbit + 0.5f;
        cam->orbit = t;
        if (t > 360.0f) {
            t -= 360.0f;
            cam->orbit = t;
        }
        cam->off.x = func_800B7890_B8490(t) * cam->dist;
        cam->off.y = cam->dist * 0.1f + 100.0f;
        pos = &cam->pos;
        cam->off.z = -cam->dist * HuMathSin(cam->orbit);
        HuVecCopyXYZ(pos, cam->at.x + cam->off.x, cam->at.y + cam->off.y, cam->at.z + cam->off.z);
        HuVecCopyXYZ(&cam->up, 0.0f, 1.0f, 0.0f);
        Hu3DCamSetPerspective(i, cam->fov, cam->aspect, cam->far);
        Hu3DCamSetPositionOrientation(i, &cam->pos, &cam->at, &cam->up);
        break;
    case 14:
        u = tank->rot.y;
        center.x = tank->pos.x;
        center.y = tank->pos.y + 100.0f;
        center.z = tank->pos.z;
        u = u > 270.0f ? u - 270.0f : tank->rot.y + 90.0f;
        s = HuMathSin(u);
        angle = func_800B7890_B8490(u);
        HuVecCopyXYZ(&cam->off, 0.0f, 900.0f, 0.0f);
        HuVecCopyXYZ(&cam->at, center.x, center.y, center.z);
        HuVecCopyXYZ(&cam->pos, center.x, center.y + cam->off.y, center.z);
        HuVecCopyXYZ(&cam->up, -angle, 0.0f, s);
        Hu3DCamSetPerspective(i, 80.0f, 400.0f, 2000.0f);
        Hu3DCamSetPositionOrientation(i, &cam->pos, &cam->at, &cam->up);
        break;
    case 17:
        func_80105044_1D9724_ShellShocked(i, 5);
        break;
    case 2:
        angle = tank->rot.y;
        angle = angle > 270.0f ? angle - 270.0f : tank->rot.y + 90.0f;
        if (angle > 360.0f) {
            angle -= 360.0f;
        }
        s = HuMathSin(angle);
        angle = func_800B7890_B8490(angle);
        HuVecCopyXYZ(&cam->at, tank->pos.x * 0.2f, 100.0f, tank->pos.z * 0.2f);
        HuVecCopyXYZ(&cam->pos, cam->at.x - angle * 200.0f, cam->at.y + 120.0f, s * 200.0f + cam->at.z);
        HuVecCopyXYZ(&cam->up, 0.0f, 1.0f, 0.0f);
        cam->timer = 0;
        Hu3DCamSetPerspective(i, cam->fov, cam->aspect, cam->far);
        Hu3DCamSetPositionOrientation(i, &cam->pos, &cam->at, &cam->up);
        func_80105044_1D9724_ShellShocked(i, 4);
        break;
    case 3:
        frac = (f32)cam->timer * 0.033333335f;
        if (cam->timer != 0x1E) {
            cam->timer++;
        } else {
            func_80105044_1D9724_ShellShocked(i, 5);
        }
        angle = tank->rot.y;
        angle = angle > 270.0f ? angle - 270.0f : tank->rot.y + 90.0f;
        w = HuMathSin(angle);
        u = func_800B7890_B8490(angle);
        HuVecCopyXYZ(&a, tank->pos.x * 0.2f, 100.0f, tank->pos.z * 0.2f);
        HuVecCopyXYZ(&b, tank->pos.x, 100.0f, tank->pos.z);
        c.x = (b.x - a.x) * frac + a.x;
        c.y = (b.y - a.y) * frac + a.y;
        c.z = (b.z - a.z) * frac + a.z;
        func_800B3170_B3D70(&cam->at, &c);
        HuVecCopyXYZ(&a, tank->pos.x * 0.2f - u * 200.0f, 220.0f, tank->pos.z * 0.2f + w * 200.0f);
        HuVecCopyXYZ(&b, u * 200.0f + tank->pos.x, 220.0f, tank->pos.z - w * 200.0f);
        d.x = (b.x - a.x) * frac + a.x;
        d.y = (b.y - a.y) * frac + a.y;
        d.z = (b.z - a.z) * frac + a.z;
        b.x = d.x - c.x;
        b.z = d.z - c.z;
        angle = (1.0f - frac) * 180.0f;
        w = HuMathSin(angle);
        co = func_800B7890_B8490(angle);
        a.x = co * b.x + c.x + w * b.z;
        a.z = (c.z - w * b.x) + co * b.z;
        HuVecCopyXYZ(&cam->pos, a.x, a.y, a.z);
        Hu3DCamSetPerspective(i, cam->fov, cam->aspect, cam->far);
        Hu3DCamSetPositionOrientation(i, &cam->pos, &cam->at, &cam->up);
        break;
    case 4:
        if (++cam->timer >= 0x51) {
            func_80105044_1D9724_ShellShocked(i, 5);
            cam->timer = 0;
        }
        u = 1.0f - (f32)cam->timer * 0.0125f;
        angle = tank->rot.y;
        angle = angle > 270.0f ? angle - 270.0f : tank->rot.y + 90.0f;
        s = HuMathSin(angle);
        e.x = func_800B7890_B8490(angle) * 200.0f;
        e.z = s * -200.0f;
        func_800B3170_B3D70(&d, &tank->pos);
        angle = u * 360.0f;
        s = HuMathSin(angle);
        co = func_800B7890_B8490(angle);
        f.x = co * e.x + s * e.z;
        f.z = -e.x * s + co * e.z;
        cam->at.x = d.x;
        angle = u * 180.0f;
        cam->at.y = (d.y + 100.0f) - HuMathSin(angle) * 60.0f;
        cam->at.z = d.z;
        cam->pos.x = cam->at.x + f.x;
        cam->pos.y = (d.y + 100.0f + 120.0f) - HuMathSin(angle) * 60.0f;
        cam->pos.z = cam->at.z + f.z;
        Hu3DCamSetPerspective(i, cam->fov, cam->aspect, cam->far);
        Hu3DCamSetPositionOrientation(i, &cam->pos, &cam->at, &cam->up);
        break;
    case 20:
        angle = tank->rot.y;
        angle = angle > 270.0f ? angle - 270.0f : tank->rot.y + 90.0f;
        if (angle > 360.0f) {
            angle -= 360.0f;
        }
        s = HuMathSin(angle);
        angle = func_800B7890_B8490(angle);
        HuVecCopyXYZ(&cam->at, tank->pos.x, 100.0f, tank->pos.z);
        HuVecCopyXYZ(&cam->pos, cam->at.x - angle * 200.0f, cam->at.y + 120.0f, s * 200.0f + cam->at.z);
        HuVecCopyXYZ(&cam->up, 0.0f, 1.0f, 0.0f);
        func_80105044_1D9724_ShellShocked(i, 0x15);
        cam->timer = 0;
        espDispOff(D_8010DA80_1E2160_ShellShocked[cam->index].hudSpr);
        break;
    case 21:
        n = func_801038F8_1D7FD8_ShellShocked();
        u = (f32)n * 0.0125f;
        if (n > 0x43) {
            u = 0.8375f;
        }
        angle = tank->rot.y;
        angle = angle > 270.0f ? angle - 270.0f : tank->rot.y + 90.0f;
        if (angle > 360.0f) {
            angle -= 360.0f;
        }
        s = HuMathSin(angle);
        h.x = func_800B7890_B8490(angle) * 200.0f;
        h.z = s * -200.0f;
        func_800B3170_B3D70(&e, &tank->pos);
        angle = u * 180.0f;
        s = HuMathSin(angle);
        co = func_800B7890_B8490(angle);
        g.x = co * h.x + s * h.z;
        g.z = -h.x * s + co * h.z;
        cam->at.x = e.x;
        cam->at.y = (e.y + 100.0f) - HuMathSin(angle) * 60.0f;
        cam->at.z = e.z;
        cam->pos.x = cam->at.x + g.x;
        cam->pos.y = (e.y + 100.0f + 120.0f) - HuMathSin(angle) * 60.0f;
        cam->pos.z = cam->at.z + g.z;
        who = func_801038B0_1D7F90_ShellShocked();
        t = func_801038F8_1D7FD8_ShellShocked();
        if (t < 60.0f) {
            angle = t * 0.016666668f;
        } else {
            angle = 1.0f;
        }
        who = who * 4 + i;
        dx1 = D_8010CFA0_1E1680_ShellShocked[who].x1 - D_8010CAE0_1E11C0_ShellShocked[i].x1;
        dy1 = D_8010CFA0_1E1680_ShellShocked[who].y1 - D_8010CAE0_1E11C0_ShellShocked[i].y1;
        dx2 = D_8010CFA0_1E1680_ShellShocked[who].x2 - D_8010CAE0_1E11C0_ShellShocked[i].x2;
        dy2 = D_8010CFA0_1E1680_ShellShocked[who].y2 - D_8010CAE0_1E11C0_ShellShocked[i].y2;
        who = i & 0xFF;
        ScissorSet(who, angle * dx1 + D_8010CAE0_1E11C0_ShellShocked[i].x1, angle * dy1 + D_8010CAE0_1E11C0_ShellShocked[i].y1,
                   angle * dx2 + D_8010CAE0_1E11C0_ShellShocked[i].x2, angle * dy2 + D_8010CAE0_1E11C0_ShellShocked[i].y2);
        ViewportSet(who, (D_8010D0A0_1E1780_ShellShocked[0] - D_8010CB20_1E1200_ShellShocked[i].v[0]) * angle + D_8010CB20_1E1200_ShellShocked[i].v[0],
                    (D_8010D0A0_1E1780_ShellShocked[1] - D_8010CB20_1E1200_ShellShocked[i].v[1]) * angle + D_8010CB20_1E1200_ShellShocked[i].v[1], D_8010CB20_1E1200_ShellShocked[i].v[2],
                    (D_8010D0A0_1E1780_ShellShocked[3] - D_8010CB20_1E1200_ShellShocked[i].v[3]) * angle + D_8010CB20_1E1200_ShellShocked[i].v[3],
                    (D_8010D0A0_1E1780_ShellShocked[4] - D_8010CB20_1E1200_ShellShocked[i].v[4]) * angle + D_8010CB20_1E1200_ShellShocked[i].v[4], D_8010CB20_1E1200_ShellShocked[i].v[5]);
        Hu3DCamSetPerspective(i, cam->fov, cam->aspect, cam->far);
        Hu3DCamSetPositionOrientation(i, &cam->pos, &cam->at, &cam->up);
        break;
    default:
        Hu3DCamSetPerspective(i, cam->fov, cam->aspect, cam->far);
        Hu3DCamSetPositionOrientation(i, &cam->pos, &cam->at, &cam->up);
        break;
    case 11:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_ShellShocked/1D8270", func_80103B90_1D8270_ShellShocked);
__asm__(".section .rodata");
const u32 D_8010CFAC_1E168C_ShellShocked[61] = { 0x435E0000, 0x43940000, 0x41800000, 0x43940000, 0x43600000, 0x41C00000, 0x43600000, 0x43940000, 0x43600000, 0x43940000, 0x43600000, 0x43940000, 0x43600000, 0x41C00000, 0x41800000, 0x41C00000, 0x43600000, 0x41D00000, 0x41800000, 0x43940000, 0x435E0000, 0x41C00000, 0x43600000, 0x41C00000, 0x43600000, 0x41C00000, 0x43600000, 0x43940000, 0x43600000, 0x41C00000, 0x41800000, 0x43940000, 0x41800000, 0x43940000, 0x41800000, 0x43940000, 0x41800000, 0x41C00000, 0x41900000, 0x43940000, 0x435E0000, 0x43940000, 0x41800000, 0x43940000, 0x43600000, 0x41C00000, 0x41800000, 0x41C00000, 0x41800000, 0x41C00000, 0x41800000, 0x43940000, 0x41800000, 0x41C00000, 0x41800000, 0x41C00000, 0x43600000, 0x41D00000, 0x41900000, 0x43940000, 0x43600000 };

__asm__(".section .rodata");
const u32 D_8010D0A0_1E1780_ShellShocked[6] = { 0x44200000, 0x43F00000, 0x43FF8000, 0x44200000, 0x43F00000, 0x43FF8000 };

__asm__(".section .rodata");
const u32 jtbl_8010D0B8_1E1798_ShellShocked[24] = { 0x80103C4C, 0x80103C34, 0x80103C4C, 0x80103C4C, 0x80103C4C, 0x80103C4C, 0x80103C34, 0x80103C34, 0x80103C34, 0x80103C34, 0x80103C34, 0x80103C34, 0x80103C34, 0x80103C34, 0x80103C34, 0x80103C34, 0x80103C34, 0x80103C34, 0x80103C34, 0x80103C34, 0x80103C4C, 0x80103C4C, 0x80103C4C, 0x00000000 };

__asm__(".section .rodata");
const u32 jtbl_8010D118_1E17F8_ShellShocked[30] = { 0x80103C70, 0x80104C70, 0x80104190, 0x801042F0, 0x801045CC, 0x80103D80, 0x80103CFC, 0x80104C70, 0x80103ECC, 0x80103F3C, 0x80104C70, 0x80104CA4, 0x80104C70, 0x80104C70, 0x80104060, 0x80104C70, 0x80104C70, 0x8010417C, 0x80104C70, 0x80104C70, 0x801047B4, 0x801048E0, 0x80104CA4, 0x80104CA4, 0x80104CA4, 0x80104CA4, 0x80104CA4, 0x80104CA4, 0x80104CA4, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010D190_1E1870_ShellShocked[2] = { 0x41F00000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010D198_1E1878_ShellShocked[2] = { 0x41F00000, 0x00000000 };
__asm__(".text");
#endif

void func_80104CE0_1D93C0_ShellShocked(omObjData* obj) {
    s32 i;

    for (i = 0; i < D_8010D730_1E1E10_ShellShocked; i++) {
        func_80103B90_1D8270_ShellShocked(i);
        Hu3DCamUpdateMtx(i);
    }
}

void func_80104D38_1D9418_ShellShocked(void) {
    s32 i;
    SSCam* cam;
    f32 x;

    func_801039F8_1D80D8_ShellShocked();
    D_800FA610_FB210 = 2200.0f;
    D_800FD474_FE074.x = -35.0f;
    D_800FD474_FE074.y = 0.0f;
    D_800FD474_FE074.z = 0.0f;
    D_8010274C_10334C.x = 0.0f;
    D_8010274C_10334C.y = 420.0f;
    D_8010274C_10334C.z = 300.0f;
    D_8010D730_1E1E10_ShellShocked = 4;
    for (i = 0; i < 4; i++) {
        cam = &D_8010D5E0_1E1CC0_ShellShocked[i];
        cam->index = i;
        x = ((f32)i * 10.0f + -20.0f) * 10.0f;
        HuVecCopyXYZ(&cam->pos, x, 600.0f, 1500.0f);
        HuVecCopyXYZ(&cam->at, x, 0.0f, -200.0f);
        HuVecCopyXYZ(&cam->up, 0.0f, 1.0f, 0.0f);
        cam->fov = 60.0f;
        cam->aspect = 80.0f;
        cam->far = 8000.0f;
        cam->dist = 200.0f;
        func_80105044_1D9724_ShellShocked(cam->index, 0);
        HuVecCopyXYZ(&cam->off, 0.0f, 0.0f, 0.0f);
        cam->off.y = cam->dist * 0.1f + 100.0f;
        cam->orbit = 0.0f;
        cam->timer = 0;
        cam->unk_48 = 0;
    }
    for (i = 0; i < 4; i++) {
        ScissorSet(i, D_8010CAE0_1E11C0_ShellShocked[i].x1, D_8010CAE0_1E11C0_ShellShocked[i].y1, D_8010CAE0_1E11C0_ShellShocked[i].x2, D_8010CAE0_1E11C0_ShellShocked[i].y2);
        ViewportSet(i, D_8010CB20_1E1200_ShellShocked[i].v[0], D_8010CB20_1E1200_ShellShocked[i].v[1], D_8010CB20_1E1200_ShellShocked[i].v[2], D_8010CB20_1E1200_ShellShocked[i].v[3],
                    D_8010CB20_1E1200_ShellShocked[i].v[4], D_8010CB20_1E1200_ShellShocked[i].v[5]);
    }
    func_80104CE0_1D93C0_ShellShocked(NULL);
}

void func_80105014_1D96F4_ShellShocked(omObjData* obj) {
    func_80104D38_1D9418_ShellShocked();
    obj->func_ptr = func_80104CE0_1D93C0_ShellShocked;
}

void func_80105044_1D9724_ShellShocked(s32 i, s32 state) {
    D_8010D5E0_1E1CC0_ShellShocked[i].state = state;
}

s32 func_80105068_1D9748_ShellShocked(s32 i) {
    u32 state;

    if (i < 0) {
        state = D_8010D5E0_1E1CC0_ShellShocked[0].state;
    } else {
        state = D_8010D5E0_1E1CC0_ShellShocked[i].state;
    }
    switch (state) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 6:
    case 20:
    case 21:
    case 22:
    case 26:
    case 27:
        return 1;
    case 5:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 23:
    case 24:
    case 25:
    default:
        return 0;
    }
}

// register allocation: the x conversion comes before the index (masked 6)
#ifdef NON_MATCHING
void func_801050D0_1D97B0_ShellShocked(s32 i, s32 x, s32 y) {
    ViewportSet(i, (f32)x + D_8010CB20_1E1200_ShellShocked[i].v[0], (f32)y + D_8010CB20_1E1200_ShellShocked[i].v[1], (f32)x + D_8010CB20_1E1200_ShellShocked[i].v[2],
                (f32)y + D_8010CB20_1E1200_ShellShocked[i].v[3], D_8010CB20_1E1200_ShellShocked[i].v[4], D_8010CB20_1E1200_ShellShocked[i].v[5]);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_ShellShocked/1D8270", func_801050D0_1D97B0_ShellShocked);
#endif
