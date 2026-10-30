#include "ovl_1A.h"

/* A team's camera: starts behind its car (MP1 func_800FAF9C). */
void func_80109BC0_1A2950_HandcarHavoc(omObjData* obj, u16 team) {
    HHCam* c;
    HHCar* w;
    f32 ry;

    c = obj->unk_50 = func_80027154_27D54(sizeof(HHCam), 0x7918);
    c->cam = team;
    w = D_8010D820_1A65B0_HandcarHavoc[team]->unk_50;
    D_80102770_103370[team].x = c->rx = w->rot.x + w->rot.z - 25.0f;
    ry = w->rot.y;
    D_80102774_103374[team].x = c->ry = ry;
    D_801013B0_101FB0[team].x = D_8010D820_1A65B0_HandcarHavoc[team]->trans.x - HuMathSin(ry) * 300.0f;
    D_801013B4_101FB4[team].x = D_8010D820_1A65B0_HandcarHavoc[team]->trans.y;
    D_801013B8_101FB8[team].x =
        D_8010D820_1A65B0_HandcarHavoc[team]->trans.z - func_800B7890_B8490(D_80102774_103374[team].x) * 300.0f;
    obj->func_ptr = func_80109D10_1A2AA0_HandcarHavoc;
}

/* A team's camera: follows its car's heading and slope (MP1 func_800FB0EC). */
void func_80109D10_1A2AA0_HandcarHavoc(omObjData* obj) {
    HHCam* c;
    omObjData* car;
    HHCar* w;
    f32 dy;
    f32 dx;
    f32 pitch;
    f32 yaw;
    f32 ry;
    u16 cam;

    c = obj->unk_50;
    cam = c->cam;
    car = D_8010D820_1A65B0_HandcarHavoc[cam];
    w = car->unk_50;
    pitch = -func_8010A75C_1A34EC_HandcarHavoc(w->slope.y) - 25.0f;
    dx = pitch - c->rx;
    yaw = w->rot.y;
    if (yaw > 180.0f) {
        yaw -= 360.0f;
    }
    dy = yaw - c->ry;
    if (dx < 0.0f) {
        dx += 360.0f;
    }
    if (dx >= 360.0f) {
        dx -= 360.0f;
    }
    if (dy < 0.0f) {
        dy += 360.0f;
    }
    if (dy >= 360.0f) {
        dy -= 360.0f;
    }
    func_8010A6A4_1A3434_HandcarHavoc(&dy, func_800B0D98_B1998(fabs(w->rot.y - c->ry), 3.0) + 3.0);
    func_8010A6A4_1A3434_HandcarHavoc(&dx, 3.0f);
    D_80102770_103370[cam].x += dx;
    if (dx > 0.0f) {
        if (pitch < D_80102770_103370[cam].x) {
            D_80102770_103370[cam].x = pitch;
        }
    } else if (D_80102770_103370[cam].x < pitch) {
        D_80102770_103370[cam].x = pitch;
    }
    D_80102774_103374[cam].x += dy;
    ry = D_80102774_103374[cam].x;
    if (ry > 180.0f) {
        ry -= 360.0f;
    }
    if (dy > 0.0f) {
        if (yaw < ry) {
            D_80102774_103374[cam].x = yaw;
        }
    } else if (ry < yaw) {
        D_80102774_103374[cam].x = yaw;
    }
    if (D_80102770_103370[cam].x < 0.0f) {
        D_80102770_103370[cam].x += 360.0f;
    }
    if (D_80102770_103370[cam].x >= 360.0f) {
        D_80102770_103370[cam].x -= 360.0f;
    }
    if (D_80102774_103374[cam].x < 0.0f) {
        D_80102774_103374[cam].x += 360.0f;
    }
    if (D_80102774_103374[cam].x >= 360.0f) {
        D_80102774_103374[cam].x -= 360.0f;
    }
    c->rx = D_80102770_103370[cam].x;
    c->ry = D_80102774_103374[cam].x;
    D_801013B0_101FB0[cam].x = car->trans.x - HuMathSin(D_80102774_103374[cam].x) * 100.0f;
    D_801013B4_101FB4[cam].x = car->trans.y;
    D_801013B8_101FB8[cam].x = car->trans.z - func_800B7890_B8490(D_80102774_103374[cam].x) * 100.0f;
}

/* Turns a car's camera a quarter round to face the car (MP1 func_800FB5DC). */
void func_8010A200_1A2F90_HandcarHavoc(omObjData* obj) {
    omObjData* cam;
    u16 team;

    team = ((HHCar*)obj->unk_50)->team;
    cam = D_8010D7E0_1A6570_HandcarHavoc[team];
    D_800F94A8_FA0A8[team] = 2000.0f;
    if (obj->work[0] & 0x20) {
        D_80102774_103374[team].x -= 90.0f;
    } else {
        D_80102774_103374[team].x += 90.0f;
    }
    if (D_80102774_103374[team].x < 0.0f) {
        D_80102774_103374[team].x += 360.0f;
    }
    if (D_80102774_103374[team].x >= 360.0f) {
        D_80102774_103374[team].x -= 360.0f;
    }
    D_801013B0_101FB0[team].x = obj->trans.x - HuMathSin(D_80102774_103374[team].x) * 0.0f;
    D_801013B4_101FB4[team].x = obj->trans.y;
    D_801013B8_101FB8[team].x = obj->trans.z - func_800B7890_B8490(D_80102774_103374[team].x) * 0.0f;
    cam->func_ptr = func_8010A400_1A3190_HandcarHavoc;
}

void func_8010A400_1A3190_HandcarHavoc(void) {
}

/* Starts a car's camera circling it for 30 frames (MP1 func_800FB7E4). */
void func_8010A408_1A3198_HandcarHavoc(omObjData* obj) {
    omObjData* cam;

    cam = D_8010D7E0_1A6570_HandcarHavoc[((HHCar*)obj->unk_50)->team];
    ((HHCam*)cam->unk_50)->timer = 30;
    cam->func_ptr = func_8010A440_1A31D0_HandcarHavoc;
}

/* Circles the camera round its car while zooming out (MP1 func_800FB81C). */
void func_8010A440_1A31D0_HandcarHavoc(omObjData* obj) {
    HHCam* c;
    omObjData* car;
    u16 cam;

    c = obj->unk_50;
    cam = c->cam;
    car = D_8010D820_1A65B0_HandcarHavoc[cam];
    D_80102774_103374[cam].x += 6.0f;
    D_80102770_103370[cam].x += 0.16666667f;
    D_801013B0_101FB0[cam].x = car->trans.x - HuMathSin(D_80102774_103374[cam].x) * 300.0f;
    D_801013B4_101FB4[cam].x = car->trans.y;
    D_801013B8_101FB8[cam].x = car->trans.z - func_800B7890_B8490(D_80102774_103374[cam].x) * 300.0f;
    D_800F94A8_FA0A8[cam] += 6.6666665f;
    if (--c->timer == 0) {
        c->timer = 15;
        obj->func_ptr = NULL;
    }
}

/* Slides the camera sideways for its timer (MP1 func_800FB994). */
// NON_MATCHING: masked 2: the KMC mul fix puts a nop before the second mul.s (after a call with a filled delay slot); retail has none there
#ifdef NON_MATCHING
void func_8010A5B8_1A3348_HandcarHavoc(omObjData* obj) {
    HHCam* c;
    u16 cam;

    c = obj->unk_50;
    cam = c->cam;
    D_801013B0_101FB0[cam].x = HuMathSin(D_80102774_103374[cam].x - 90.0f) * 20.0f + D_801013B0_101FB0[cam].x;
    D_801013B8_101FB8[cam].x = func_800B7890_B8490(D_80102774_103374[cam].x - 90.0f) * 20.0f + D_801013B8_101FB8[cam].x;
    if (--c->timer == 0) {
        obj->func_ptr = NULL;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A2950", func_8010A5B8_1A3348_HandcarHavoc);
#endif

/* Clamps an angle step towards 0 to at most `step` either way (MP1 func_800FBFA0). */
void func_8010A6A4_1A3434_HandcarHavoc(f32* a, f32 step) {
    if (*a < 0.0f) {
        *a += 360.0f;
    }
    if (*a < 180.0f) {
        if (step < *a) {
            *a = step;
        }
    } else if (step < 360.0f - *a) {
        *a = -step;
    } else {
        *a = -(360.0f - *a);
    }
}

/* The slope's pitch in degrees: acos of the clamped y (MP1 func_800FC7E0). */
f32 func_8010A75C_1A34EC_HandcarHavoc(f32 x) {
    if (x > 1.0f) {
        x = 1.0f;
    } else if (x < -1.0f) {
        x = -1.0f;
    }
    return (f32)func_800B0750_B1350(x) / 3.141592653589793 * 180.0;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A2950", func_8010A7D8_1A3568_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A2950", func_8010A870_1A3600_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A2950", func_8010AA30_1A37C0_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A2950", func_8010ABC8_1A3958_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A2950", func_8010AD1C_1A3AAC_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A2950", func_8010AE30_1A3BC0_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A2950", func_8010B024_1A3DB4_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A2950", func_8010B0FC_1A3E8C_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/1A2950", func_8010B108_1A3E98_HandcarHavoc);
