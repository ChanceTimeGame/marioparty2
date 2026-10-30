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
s32 func_80102CD4_1B4E24_SpeedHockey(SHObjWork* w, s32 n) {
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

#ifdef NON_MATCHING
/* masked 2: retail tests the second loop's guard as blez cnt and sets cnt before i; GCC here compares against best's zero register */
/* Move the puck against the walls 0..n-1: bounce off the nearest one it crossed (a paddle face
   adds the paddle's z motion as english and speed). Returns 1 on a bounce, else
   func_80102CD4's result. */
s32 func_8010308C_1B51DC_SpeedHockey(SHObjWork* w, s32 n) {
    f32 unused[2];
    s32 cnt;
    s32 i;
    s32 best;
    s32 idx;
    f32 min;
    f32 dx;
    f32 dz;
    f32 d;
    f32 move;
    f32 s;
    SHObjWork* pw;

    cnt = 0;
    for (i = 0; i < n; i++) {
        if (func_801028B8_1B4A08_SpeedHockey(&w->pos, D_80106774_1B88C4_SpeedHockey[i].p, &D_80106CF8_1B8E48_SpeedHockey[i]) != 0) {
            D_80106E30_1B8F80_SpeedHockey[cnt++] = i;
        }
    }
    if (cnt == 0) {
        return func_80102CD4_1B4E24_SpeedHockey(w, n);
    }
    best = 0;
    if (cnt >= 2) {
        min = 1e9f;
        for (i = 0; i < cnt; i++) {
            dx = w->prev.x - D_80106CF8_1B8E48_SpeedHockey[D_80106E30_1B8F80_SpeedHockey[i]].x;
            dz = w->prev.z - D_80106CF8_1B8E48_SpeedHockey[D_80106E30_1B8F80_SpeedHockey[i]].z;
            d = dx * dx + dz * dz;
            if (d < min) {
                min = d;
                best = i;
            }
        }
    }
    idx = D_80106E30_1B8F80_SpeedHockey[best];
    func_80102B04_1B4C54_SpeedHockey(w, &D_80106774_1B88C4_SpeedHockey[idx], &D_80106CF8_1B8E48_SpeedHockey[idx]);
    if (idx >= 10) {
        pw = SH_WORK(D_80106CA0_1B8DF0_SpeedHockey[D_80106774_1B88C4_SpeedHockey[idx].paddle]);
        move = pw->pos.z - pw->prev.z;
        d = D_80106774_1B88C4_SpeedHockey[idx].p[0].x - D_80106774_1B88C4_SpeedHockey[idx].p[1].x;
        if ((d < 0.0f ? -d : d) < 1.0f) {
            if ((w->dir.x < 0.0f ? -w->dir.x : w->dir.x) > 0.75f) {
                w->dir.z = move * 0.3f + w->dir.z;
                func_80106074_1B81C4_SpeedHockey(&w->dir);
            }
        }
        s = move * 0.12f + 1.0f;
        if (s < 1.025f) {
            s = 1.025f;
        }
        w->speed = s * w->speed;
        if (w->speed > 8.0f) {
            w->speed = 8.0f;
        }
        w->spin = move + w->spin;
        if (w->spin > 25.0f) {
            w->spin = 25.0f;
        } else if (w->spin < -25.0f) {
            w->spin = -25.0f;
        }
        pw->hit = 1;
    }
    w->spin *= -0.93f;
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B49A0", func_8010308C_1B51DC_SpeedHockey);
#endif

/* Rebuild walls 10.. from the paddle faces the puck can reach (by which of the nine cells
   around each paddle box its previous position is in), then bounce it until it crosses no
   wall (at most 21 bounces). Returns 1 when it is free, 0 when it gave up. */
s32 func_80103488_1B55D8_SpeedHockey(SHObjWork* w) {
    s32 tries = 0;
    s32 n;
    s32 i;
    s32 j;
    s32 r;
    SHObjWork* pw;

    while (1) {
        n = 10;
        for (i = 0, j = 0; i < 4; i++, j++) {
            pw = SH_WORK(D_80106CA0_1B8DF0_SpeedHockey[j]);
            D_80106CB8_1B8E08_SpeedHockey[i].xMin = D_80106764_1B88B4_SpeedHockey.xMin + pw->pos.x;
            D_80106CB8_1B8E08_SpeedHockey[i].xMax = D_80106764_1B88B4_SpeedHockey.xMax + pw->pos.x;
            D_80106CB8_1B8E08_SpeedHockey[i].zMin = D_80106764_1B88B4_SpeedHockey.zMin + pw->pos.z;
            D_80106CB8_1B8E08_SpeedHockey[i].zMax = D_80106764_1B88B4_SpeedHockey.zMax + pw->pos.z;
            switch (func_80102A88_1B4BD8_SpeedHockey(&w->prev, &D_80106CB8_1B8E08_SpeedHockey[i])) {
                case 0:
                    HuVecAdd(&D_80106774_1B88C4_SpeedHockey[n].p[0], &pw->pos, &D_801066F4_1B8844_SpeedHockey[0].p[0]);
                    HuVecAdd(&D_80106774_1B88C4_SpeedHockey[n].p[1], &pw->pos, &D_801066F4_1B8844_SpeedHockey[0].p[1]);
                    D_80106774_1B88C4_SpeedHockey[n++].paddle = j;
                    HuVecAdd(&D_80106774_1B88C4_SpeedHockey[n].p[0], &pw->pos, &D_801066F4_1B8844_SpeedHockey[2].p[0]);
                    HuVecAdd(&D_80106774_1B88C4_SpeedHockey[n].p[1], &pw->pos, &D_801066F4_1B8844_SpeedHockey[2].p[1]);
                    D_80106774_1B88C4_SpeedHockey[n++].paddle = j;
                    break;
                case 1:
                    HuVecAdd(&D_80106774_1B88C4_SpeedHockey[n].p[0], &pw->pos, &D_801066F4_1B8844_SpeedHockey[0].p[0]);
                    HuVecAdd(&D_80106774_1B88C4_SpeedHockey[n].p[1], &pw->pos, &D_801066F4_1B8844_SpeedHockey[0].p[1]);
                    D_80106774_1B88C4_SpeedHockey[n++].paddle = j;
                    break;
                case 2:
                    HuVecAdd(&D_80106774_1B88C4_SpeedHockey[n].p[0], &pw->pos, &D_801066F4_1B8844_SpeedHockey[0].p[0]);
                    HuVecAdd(&D_80106774_1B88C4_SpeedHockey[n].p[1], &pw->pos, &D_801066F4_1B8844_SpeedHockey[0].p[1]);
                    D_80106774_1B88C4_SpeedHockey[n++].paddle = j;
                    HuVecAdd(&D_80106774_1B88C4_SpeedHockey[n].p[0], &pw->pos, &D_801066F4_1B8844_SpeedHockey[3].p[0]);
                    HuVecAdd(&D_80106774_1B88C4_SpeedHockey[n].p[1], &pw->pos, &D_801066F4_1B8844_SpeedHockey[3].p[1]);
                    D_80106774_1B88C4_SpeedHockey[n++].paddle = j;
                    break;
                case 3:
                    HuVecAdd(&D_80106774_1B88C4_SpeedHockey[n].p[0], &pw->pos, &D_801066F4_1B8844_SpeedHockey[2].p[0]);
                    HuVecAdd(&D_80106774_1B88C4_SpeedHockey[n].p[1], &pw->pos, &D_801066F4_1B8844_SpeedHockey[2].p[1]);
                    D_80106774_1B88C4_SpeedHockey[n++].paddle = j;
                    break;
                case 4:
                    break;
                case 5:
                    HuVecAdd(&D_80106774_1B88C4_SpeedHockey[n].p[0], &pw->pos, &D_801066F4_1B8844_SpeedHockey[3].p[0]);
                    HuVecAdd(&D_80106774_1B88C4_SpeedHockey[n].p[1], &pw->pos, &D_801066F4_1B8844_SpeedHockey[3].p[1]);
                    D_80106774_1B88C4_SpeedHockey[n++].paddle = j;
                    break;
                case 6:
                    HuVecAdd(&D_80106774_1B88C4_SpeedHockey[n].p[0], &pw->pos, &D_801066F4_1B8844_SpeedHockey[1].p[0]);
                    HuVecAdd(&D_80106774_1B88C4_SpeedHockey[n].p[1], &pw->pos, &D_801066F4_1B8844_SpeedHockey[1].p[1]);
                    D_80106774_1B88C4_SpeedHockey[n++].paddle = j;
                    HuVecAdd(&D_80106774_1B88C4_SpeedHockey[n].p[0], &pw->pos, &D_801066F4_1B8844_SpeedHockey[2].p[0]);
                    HuVecAdd(&D_80106774_1B88C4_SpeedHockey[n].p[1], &pw->pos, &D_801066F4_1B8844_SpeedHockey[2].p[1]);
                    D_80106774_1B88C4_SpeedHockey[n++].paddle = j;
                    break;
                case 7:
                    HuVecAdd(&D_80106774_1B88C4_SpeedHockey[n].p[0], &pw->pos, &D_801066F4_1B8844_SpeedHockey[1].p[0]);
                    HuVecAdd(&D_80106774_1B88C4_SpeedHockey[n].p[1], &pw->pos, &D_801066F4_1B8844_SpeedHockey[1].p[1]);
                    D_80106774_1B88C4_SpeedHockey[n++].paddle = j;
                    break;
                case 8:
                    HuVecAdd(&D_80106774_1B88C4_SpeedHockey[n].p[0], &pw->pos, &D_801066F4_1B8844_SpeedHockey[1].p[0]);
                    HuVecAdd(&D_80106774_1B88C4_SpeedHockey[n].p[1], &pw->pos, &D_801066F4_1B8844_SpeedHockey[1].p[1]);
                    D_80106774_1B88C4_SpeedHockey[n++].paddle = j;
                    HuVecAdd(&D_80106774_1B88C4_SpeedHockey[n].p[0], &pw->pos, &D_801066F4_1B8844_SpeedHockey[3].p[0]);
                    HuVecAdd(&D_80106774_1B88C4_SpeedHockey[n].p[1], &pw->pos, &D_801066F4_1B8844_SpeedHockey[3].p[1]);
                    D_80106774_1B88C4_SpeedHockey[n++].paddle = j;
                    break;
                default:
                    while (1) {
                    }
            }
        }
        r = func_8010308C_1B51DC_SpeedHockey(w, n);
        if (r == 1) {
            tries++;
            if (tries >= 21) {
                return 0;
            }
        }
        if (r == 0) {
            return 1;
        }
    }
}

/* 2 or 3 once the puck is past a goal line (the goal it entered), else 0. */
s32 func_8010389C_1B59EC_SpeedHockey(Vec* p) {
    if (p->x < D_80106A7C_1B8BCC_SpeedHockey) {
        return 3;
    }
    if (p->x > D_80106A80_1B8BD0_SpeedHockey) {
        return 2;
    }
    return 0;
}

/* Puck state 0: wobble at the centre spot for 30 frames, then serve it at a random angle. */
void func_801038E8_1B5A38_SpeedHockey(omObjData* obj, SHObjWork* w) {
    f32 x;
    s32 z;

    if ((s16)w->timer++ < 30) {
        func_800B3170_B3D70(&w->prev, &w->pos);
        x = (f32)((u8)(rand8() % 20) - 10) * 0.1f;
        HuVecCopyXYZ(&w->pos, x, 0.0f, (f32)((u8)(rand8() % 20) - 10) * 0.1f + 0.0f);
        omSetTra(obj, w->pos.x, w->pos.y, w->pos.z);
        w->spin = (u8)(rand8() % 20) - 10;
        obj->rot.y += w->spin;
        if (obj->rot.y > 360.0f) {
            obj->rot.y -= 360.0f;
        }
        if (obj->rot.y < -360.0f) {
            obj->rot.y += 360.0f;
        }
    } else {
        w->state = 1;
        w->timer = 0;
        HuVecCopyXYZ(&w->pos, 0.0f, 0.0f, 0.0f);
        func_800B3170_B3D70(&w->prev, &w->pos);
        w->speed = 4.0f;
        z = (u8)(rand8() % 10) - 5;
        if (z == 0) {
            z = 1;
        }
        if (rand8() & 1) {
            HuVecCopyXYZ(&w->dir, -3.0f, 0.0f, z);
        } else {
            HuVecCopyXYZ(&w->dir, 3.0f, 0.0f, z);
        }
        func_80106074_1B81C4_SpeedHockey(&w->dir);
    }
}

/* Puck state 1: move, spin, score or bounce. */
void func_80103B94_1B5CE4_SpeedHockey(omObjData* obj, SHObjWork* w) {
    Vec v;

    func_800B3170_B3D70(&w->prev, &w->pos);
    HuVecMulScalar(&v, w->speed, &w->dir);
    HuVecAdd(&w->pos, &w->prev, &v);
    obj->rot.y += w->spin;
    if (obj->rot.y > 360.0f) {
        obj->rot.y -= 360.0f;
    }
    if (obj->rot.y < -360.0f) {
        obj->rot.y += 360.0f;
    }
    if ((w->goal = func_8010389C_1B59EC_SpeedHockey(&w->pos)) != 0) {
        w->state = 2;
        return;
    }
    if (func_80103488_1B55D8_SpeedHockey(w) == 0) {
        w->state = 3;
    }
    omSetTra(obj, w->pos.x, w->pos.y, w->pos.z);
}

#ifdef NON_MATCHING
/* masked 6: retail computes the sprite index team * 3 - 1 + score + 3 unfolded before scaling; GCC here folds -1 + 3 into the load offset */
/* Puck state 2: a goal for team goal - 2; the third ends the game. */
void func_80103CB0_1B5E00_SpeedHockey(omObjData* obj, SHObjWork* w) {
    s32 team = w->goal - 2;

    if (++w->score[team] >= 3) {
        func_80106580_1B86D0_SpeedHockey(team);
        func_80106554_1B86A4_SpeedHockey(3);
    } else {
        w->state = 3;
    }
    func_800B3170_B3D70(&w->pos, &w->prev);
    w->speed = 0.0f;
    if (team == 0) {
        func_800798F8_7A4F8(PlaySound(0x21D), 0x20);
    } else {
        func_800798F8_7A4F8(PlaySound(0x21D), 0x60);
    }
    espDispOn(D_80106CA4_1B8DF4_SpeedHockey[team * 3 - 1 + w->score[team] + 3]);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B49A0", func_80103CB0_1B5E00_SpeedHockey);
#endif

/* Puck state 3: back to the centre spot after 31 frames. */
void func_80103D9C_1B5EEC_SpeedHockey(omObjData* obj, SHObjWork* w) {
    if ((s16)w->timer++ >= 31) {
        PlaySound(0x21F);
        HuVecCopyXYZ(&w->pos, 0.0f, 0.0f, 0.0f);
        w->timer = 0;
        w->state = 0;
    }
}

void func_80103DFC_1B5F4C_SpeedHockey(omObjData* obj, SHObjWork* w) {
    if (D_80106A84_1B8BD4_SpeedHockey[w->state] != NULL) {
        D_80106A84_1B8BD4_SpeedHockey[w->state](obj, w);
    }
}

/* After the game: the puck coasts to a stop. */
void func_80103E34_1B5F84_SpeedHockey(omObjData* obj, SHObjWork* w) {
    Vec v;
    Vec* pos;

    func_800B3170_B3D70(&w->prev, &w->pos);
    HuVecMulScalar(&v, w->speed, &w->dir);
    HuVecAdd(&w->pos, &w->prev, &v);
    obj->rot.y += w->spin;
    if (obj->rot.y > 360.0f) {
        obj->rot.y -= 360.0f;
    }
    pos = &w->pos;
    if (obj->rot.y < -360.0f) {
        obj->rot.y += 360.0f;
    }
    if ((w->goal = func_8010389C_1B59EC_SpeedHockey(pos)) != 0) {
        func_800B3170_B3D70(pos, &w->prev);
        w->speed = 0.0f;
    } else {
        func_80103488_1B55D8_SpeedHockey(w);
        omSetTra(obj, w->pos.x, w->pos.y, w->pos.z);
    }
    w->speed *= 0.9f;
    w->spin *= 0.9f;
}

/* The puck object: clear the paddles' hit flags, then run the game state's handler. */
void func_80103F78_1B60C8_SpeedHockey(omObjData* obj) {
    s32 i;
    s32* hit;

    for (i = 0; i < 4; i++) {
        hit = &SH_WORK(D_80106CA0_1B8DF0_SpeedHockey[i])->hit;
        *hit = 0;
    }
    if (D_80106A94_1B8BE4_SpeedHockey[func_80106548_1B8698_SpeedHockey()] != NULL) {
        D_80106A94_1B8BE4_SpeedHockey[func_80106548_1B8698_SpeedHockey()](obj, obj->unk_50);
    }
}

/* A shadow: trail one step behind its target. */
void func_80104020_1B6170_SpeedHockey(omObjData* obj) {
    SHObjWork* w = obj->unk_50;
    SHObjWork* tw;

    if (w->target != NULL) {
        tw = w->target->unk_50;
        func_800B3170_B3D70(&w->prev, &w->pos);
        func_800B3170_B3D70(&w->pos, &tw->prev);
        omSetTra(obj, w->pos.x, w->pos.y, w->pos.z);
        omSetRot(obj, 0.0f, w->target->rot.y, 0.0f);
    }
}

/* A paddle: follow its player's x and z. */
void func_801040B0_1B6200_SpeedHockey(omObjData* obj) {
    SHObjWork* w = obj->unk_50;

    if (w->target != NULL) {
        omSetTra(obj, w->target->trans.x, 0.0f, w->target->trans.z);
        func_800B3170_B3D70(&w->prev, &w->pos);
        HuVecCopyXYZ(&w->pos, w->target->trans.x, 0.0f, w->target->trans.z);
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B49A0", func_8010411C_1B626C_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B49A0", func_8010443C_1B658C_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B49A0", func_80104540_1B6690_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B49A0", func_80104584_1B66D4_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B49A0", func_8010461C_1B676C_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B49A0", func_8010463C_1B678C_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B49A0", func_801046A0_1B67F0_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B49A0", func_801046EC_1B683C_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B49A0", func_8010472C_1B687C_SpeedHockey);
