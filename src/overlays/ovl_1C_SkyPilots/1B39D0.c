#include "ovl_1C.h"

/* NON_MATCHING: schedule: retail keeps D_8010ADA4_1B4434_SkyPilots and the hook in registers (masked 6) */
#ifdef NON_MATCHING
void func_8010A340_1B39D0_SkyPilots(void) {
    omObjData** p = D_8010ADA4_1B4434_SkyPilots;
    void* f = func_801058EC_1AEF7C_SkyPilots;

    p[0]->func_ptr = f;
    p[1]->func_ptr = f;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_SkyPilots/1B39D0", func_8010A340_1B39D0_SkyPilots);
#endif

void func_8010A364_1B39F4_SkyPilots(omObjData* obj) {
    SPPlane* w = obj->unk_50;
    s32 team = w->team;

    if (D_8010B200_1B4890_SkyPilots < 0x5A) {
        D_80102770_103370[team].y = w->yaw;
        D_8010B410_1B4AA0_SkyPilots[team] = w->yaw;
        D_8010B418_1B4AA8_SkyPilots[team] = -1.0f;
        D_80102770_103370[team].x = -1.0f;
        D_8010B420_1B4AB0_SkyPilots[team] = 320.0f;
    } else if (D_8010B200_1B4890_SkyPilots < 0x10E) {
        D_80102770_103370[team].y = D_8010B410_1B4AA0_SkyPilots[team];
        D_8010B410_1B4AA0_SkyPilots[team] += 2.0f;
        D_80102770_103370[team].x = D_8010B418_1B4AA8_SkyPilots[team];
        D_8010B418_1B4AA8_SkyPilots[team] -= 0.1f;
        D_8010B420_1B4AB0_SkyPilots[team] += 2.0f;
    }
    D_801013B0_101FB0[team].x = obj->trans.x;
    D_801013B0_101FB0[team].y = obj->trans.y - (5.0f * D_80102770_103370[team].x - 20.0f);
    D_801013B0_101FB0[team].z = obj->trans.z;
    D_800F94A8_FA0A8[team] = w->speed * 5.0f + D_8010B420_1B4AB0_SkyPilots[team];
    D_8010B200_1B4890_SkyPilots++;
}

void func_8010A53C_1B3BCC_SkyPilots(omObjData* obj) {
    SPPlane* w = obj->unk_50;
    s32 team = w->team;

    if (D_8010B204_1B4894_SkyPilots == 0) {
        D_8010B428_1B4AB8_SkyPilots = D_80102770_103370[team].y;
        D_8010B42C_1B4ABC_SkyPilots = D_800F94A8_FA0A8[team];
    }
    if (D_8010B204_1B4894_SkyPilots < 0xB4) {
        D_8010B208_1B4898_SkyPilots += 2.0f;
        D_8010B42C_1B4ABC_SkyPilots -= 10.0f;
        if (D_8010B42C_1B4ABC_SkyPilots < 400.0f) {
            D_8010B42C_1B4ABC_SkyPilots = 400.0f;
        }
    }
    D_80102770_103370[team].y = D_8010B428_1B4AB8_SkyPilots + D_8010B208_1B4898_SkyPilots;
    D_801013B0_101FB0[team].x = obj->trans.x;
    D_801013B0_101FB0[team].y = obj->trans.y - (5.0f * D_80102770_103370[team].x - 20.0f);
    D_801013B0_101FB0[team].z = obj->trans.z;
    D_800F94A8_FA0A8[team] = D_8010B42C_1B4ABC_SkyPilots;
    D_8010B204_1B4894_SkyPilots++;
}

void func_8010A6C0_1B3D50_SkyPilots(omObjData* obj) {
    SPPlane* w = obj->unk_50;
    s32 team = w->team;
    f32* base;
    f32* p;

    w->stickX = -8;
    w->stickY = 0;
    base = D_8010B20C_1B489C_SkyPilots;
    p = team + base;
    w->stickZ = HuMathSin(*p) * 60.0f;
    *p = func_8002D958_2E558(*p + 12.0f);
    func_801058EC_1AEF7C_SkyPilots(obj);
    func_8010A364_1B39F4_SkyPilots(obj);
}

/* NON_MATCHING: register allocation (masked 4) */
#ifdef NON_MATCHING
void func_8010A768_1B3DF8_SkyPilots(omObjData* obj) {
    SPPlane* w = obj->unk_50;
    s32 team = w->team;
    f32 x = HuMathSin(w->yaw) * 100.0f + obj->trans.x;
    f32 z = func_800B7890_B8490(w->yaw) * 100.0f + obj->trans.z;
    f32 d = (SP_RADIUS - func_800B1830_B2430(x * x + z * z)) * 0.1f;
    f32* base;
    f32* p;

    if (d > 64.0f) {
        d = 64.0f;
    }
    if (d < -64.0f) {
        d = -64.0f;
    }
    if (fabs(d) > 50.0) {
        w->stickX = d;
    }
    base = D_8010B214_1B48A4_SkyPilots;
    p = team + base;
    w->stickZ = HuMathSin(*p) * 60.0f;
    *p = func_8002D958_2E558(*p + 10.0f);
    func_801058EC_1AEF7C_SkyPilots(obj);
    func_8010A53C_1B3BCC_SkyPilots(obj);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_SkyPilots/1B39D0", func_8010A768_1B3DF8_SkyPilots);
#endif

/* NON_MATCHING: register allocation (masked 9) */
#ifdef NON_MATCHING
void func_8010A8F4_1B3F84_SkyPilots(omObjData* obj) {
    SPPlane* w = obj->unk_50;
    s32 p = w->pilot;

    if (gPlayers[p].flags & 1) {
        s32 lvl;
        s32 i;
        f32 x;
        f32 z;
        f32 d;

        w->stickX = 0;
        w->stickY = 0;
        lvl = gPlayers[p].cpu_difficulty;
        if (!(gPlayers[w->gunner].flags & 1)) {
            lvl++;
            if (lvl >= 4) {
                lvl = 3;
            }
        }
        switch (lvl) {
        case 0:
        case 1:
            break;
        case 2:
        case 3: {
            f32 h;
            f32* base;
            f32* q;

            i = 0;
            h = D_8010B430_1B4AC0_SkyPilots[w->team];
            base = D_8010B21C_1B48AC_SkyPilots;
            q = p + base;
            do {
                f32 a = D_8010AE3C_1B44CC_SkyPilots[i].angle;

                i++;
                if (a - 18.0f < h) {
                    if (h < a) {
                        w->stickY = HuMathSin(*q) * 70.0f;
                        *q = func_8002D958_2E558(*q + 1.0f);
                        break;
                    }
                }
            } while (i < 4);
            if (w->stickY == 0) {
                if (obj->trans.y > 100.0f) {
                    w->stickY = 0x3C;
                }
                if (obj->trans.y < -100.0f) {
                    w->stickY = -0x3C;
                }
            }
            break;
        }
        }
        x = obj->trans.x;
        z = obj->trans.z;
        d = (SP_RADIUS - func_800B1830_B2430(x * x + z * z)) * 0.1f;
        if (d > 64.0f) {
            d = 64.0f;
        }
        if (d < -64.0f) {
            d = -64.0f;
        }
        w->stickX = d;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1C_SkyPilots/1B39D0", func_8010A8F4_1B3F84_SkyPilots);
#endif

void func_8010AB84_1B4214_SkyPilots(omObjData* obj) {
    SPPlane* w = obj->unk_50;
    s32 p = w->gunner;

    if (gPlayers[p].flags & 1) {
        s32 lvl = gPlayers[p].cpu_difficulty;
        f32 amp;
        f32 rate;
        f32* base;
        f32* q;

        if (!(gPlayers[w->pilot].flags & 1)) {
            lvl++;
            if (lvl >= 4) {
                lvl = 3;
            }
        }
        switch (lvl) {
        case 0:
            amp = 70.0f;
            rate = rand8() >> 5;
            break;
        case 1:
            amp = 70.0f;
            rate = (u8)(rand8() / 34);
            break;
        case 2:
            amp = 65.0f;
            rate = (u8)(rand8() / 36);
            break;
        case 3:
            amp = 60.0f;
            rate = (u8)(rand8() / 37);
            break;
        }
        rate += 12.0f;
        base = D_8010B224_1B48B4_SkyPilots;
        q = p + base;
        w->stickZ = HuMathSin(*q) * amp;
        *q = func_8002D958_2E558(rate + *q);
    }
}
