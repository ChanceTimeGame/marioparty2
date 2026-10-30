#include "ovl_1D.h"

s32 func_80102850_1B49A0_SpeedHockey(Vec* p, SHBox* box) {
    s32 ret = 0;

    if (p->x >= box->xMin && p->x <= box->xMax && p->z >= box->zMin && p->z <= box->zMax) {
        ret = 1;
    }
    return ret;
}

/* Where segment a crosses segment b, on the table plane; 0 if they do not cross. */
s32 func_801028B8_1B4A08_SpeedHockey(Vec* a, Vec* b, Vec* out) {
    f32 ax0 = a[0].x;
    f32 az0 = a[0].z;
    f32 ax1 = a[1].x;
    f32 az1 = a[1].z;
    f32 bx0 = b[0].x;
    f32 bz0 = b[0].z;
    f32 bx1 = b[1].x;
    f32 bz1 = b[1].z;
    f32 d = (ax1 - ax0) * (bz1 - bz0) - (az1 - az0) * (bx1 - bx0);
    f32 inv;
    f32 t;
    f32 u;

    if (d < 0.000001f && d > -0.000001f) {
        return 0;
    }
    inv = 1.0f / d;
    t = ((az0 - bz0) * (ax1 - ax0) - (ax0 - bx0) * (az1 - az0)) * inv;
    u = ((az0 - bz0) * (bx1 - bx0) - (ax0 - bx0) * (bz1 - bz0)) * inv;
    if (t < 0.0f || t > 1.0f) {
        return 0;
    }
    if (u < 0.0f || u > 1.0f) {
        return 0;
    }
    out->x = (ax1 - ax0) * u + ax0;
    out->y = 0.0f;
    out->z = (az1 - az0) * u + az0;
    return 1;
}

/* Which of the nine cells around the box p is in: 0-2 below zMin, 3-5 inside, 6-8 above zMax;
   x: +0 left, +1 inside, +2 right (4 = inside the box). */
s32 func_80102A88_1B4BD8_SpeedHockey(Vec* p, SHBox* box) {
    s32 cell;

    if (p->z > box->zMax) {
        cell = 6;
    } else if (p->z < box->zMin) {
        cell = 0;
    } else {
        cell = 3;
    }
    if (p->x > box->xMax) {
        return cell + 2;
    }
    if (!(p->x < box->xMin)) {
        cell += 1;
    }
    return cell;
}

/* Bounce the puck off a wall it crossed at hit: reflect its direction and position, and move
   it a hair off the wall. */
void func_80102B04_1B4C54_SpeedHockey(SHObjWork* w, SHWall* wall, Vec* hit) {
    Vec v;
    f32 d;
    Vec* pos;

    d = wall->p[0].x - wall->p[1].x;
    pos = &w->pos;
    if ((d < 0.0f ? -d : d) < 1.0f) {
        w->dir.x = -w->dir.x;
        pos->x = 2.0f * (hit->x - pos->x) + pos->x;
    } else {
        w->dir.z = -w->dir.z;
        pos->z = 2.0f * (hit->z - pos->z) + pos->z;
    }
    HuVecSubtract(&v, pos, hit);
    if (HuVecGetLength3F(&v) != 0.0f) {
        func_800B33E0_B3FE0(&v);
        HuVecMulScalar(&v, 0.001f, &v);
    } else {
        HuVecSubtract(&v, &w->prev, hit);
        if (HuVecGetLength3F(&v) != 0.0f) {
            func_800B33E0_B3FE0(&v);
            HuVecMulScalar(&v, 0.001f, &v);
        } else {
            while (1) {
            }
        }
        HuVecAdd(&w->pos, hit, &v);
    }
    HuVecAdd(&w->prev, hit, &v);
    if (wall->paddle < 0) {
        PlaySound(0x21C);
    } else {
        PlaySound(0x220);
    }
}

#ifdef NON_MATCHING
/* masked 0; raw: retail keeps the box centre x in f10 and xMin in f8 (swapped) */
/* The puck crossed no wall: if it is off the table or inside a paddle, push it back out and
   reverse it. Returns 0. */
s32 func_80102CD4_1B4E24_SpeedHockey(SHObjWork* w) {
    f32 unused[8];
    s32 hit = -1;
    s32 outside = 0;
    s32 i;
    f32 dz;
    f32 dx;
    f32 cz;
    f32 cx;

    if (!func_80102850_1B49A0_SpeedHockey(&w->pos, &D_80106A4C_1B8B9C_SpeedHockey) &&
        !func_80102850_1B49A0_SpeedHockey(&w->pos, &D_80106A5C_1B8BAC_SpeedHockey)) {
        outside = !func_80102850_1B49A0_SpeedHockey(&w->pos, &D_80106A6C_1B8BBC_SpeedHockey);
    }
    for (i = 0; i < 4; i++) {
        if (func_80102850_1B49A0_SpeedHockey(&w->pos, &D_80106CB8_1B8E08_SpeedHockey[i]) == 1) {
            hit = i;
        }
    }
    if (hit == -1 && outside == 0) {
        return 0;
    }
    if (outside != 0) {
        if (w->pos.x < -83.65f) {
            w->pos.x = -83.649f;
        } else if (w->pos.x > 83.65f) {
            w->pos.x = 83.649f;
        }
        if (w->pos.z < -54.65f) {
            w->pos.z = -54.649002f;
        } else if (w->pos.z > 54.65f) {
            w->pos.z = 54.649002f;
        }
    }
    if (hit != -1) {
        cx = (D_80106CB8_1B8E08_SpeedHockey[hit].xMin + D_80106CB8_1B8E08_SpeedHockey[hit].xMax) * 0.5f;
        cz = (D_80106CB8_1B8E08_SpeedHockey[hit].zMin + D_80106CB8_1B8E08_SpeedHockey[hit].zMax) * 0.5f;
        if (w->pos.x < cx) {
            dx = w->pos.x - D_80106CB8_1B8E08_SpeedHockey[hit].xMin;
        } else {
            dx = w->pos.x - D_80106CB8_1B8E08_SpeedHockey[hit].xMax;
        }
        if (dx < 0.0f) {
            dx = -dx;
        }
        if (w->pos.z < cz) {
            dz = w->pos.z - D_80106CB8_1B8E08_SpeedHockey[hit].zMin;
        } else {
            dz = w->pos.z - D_80106CB8_1B8E08_SpeedHockey[hit].zMax;
        }
        if (dz < 0.0f) {
            dz = -dz;
        }
        if (dx < dz) {
            if (w->pos.x < cx) {
                w->pos.x = D_80106CB8_1B8E08_SpeedHockey[hit].xMin - 0.001f;
            } else {
                w->pos.x = D_80106CB8_1B8E08_SpeedHockey[hit].xMax + 0.001f;
            }
        } else {
            if (w->pos.z < cz) {
                w->pos.z = D_80106CB8_1B8E08_SpeedHockey[hit].zMin - 0.001f;
            } else {
                w->pos.z = D_80106CB8_1B8E08_SpeedHockey[hit].zMax + 0.001f;
            }
        }
    }
    HuVecMulScalar(&w->dir, -1.0f, &w->dir);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B49A0", func_80102CD4_1B4E24_SpeedHockey);
#endif

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B49A0", func_8010308C_1B51DC_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B49A0", func_80103488_1B55D8_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B49A0", func_8010389C_1B59EC_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B49A0", func_801038E8_1B5A38_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B49A0", func_80103B94_1B5CE4_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B49A0", func_80103CB0_1B5E00_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B49A0", func_80103D9C_1B5EEC_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B49A0", func_80103DFC_1B5F4C_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B49A0", func_80103E34_1B5F84_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B49A0", func_80103F78_1B60C8_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B49A0", func_80104020_1B6170_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B49A0", func_801040B0_1B6200_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B49A0", func_8010411C_1B626C_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B49A0", func_8010443C_1B658C_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B49A0", func_80104540_1B6690_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B49A0", func_80104584_1B66D4_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B49A0", func_8010461C_1B676C_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B49A0", func_8010463C_1B678C_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B49A0", func_801046A0_1B67F0_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B49A0", func_801046EC_1B683C_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B49A0", func_8010472C_1B687C_SpeedHockey);
