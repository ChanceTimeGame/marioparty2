#include "ovl_16.h"

/* .data (0x180F10-0x181170, 80109160-801093C0) */
Vec D_80109160_180F10_FiletRelay[4] = {
    { -30.0f, -110.0f, 1250.0f },
    { 30.0f, -110.0f, 1250.0f },
    { 30.0f, -110.0f, 435.0f },
    { 30.0f, -110.0f, -385.0f },
};
FRCpu D_80109190_180F40_FiletRelay[4] = {
    { 3, 45, 4, 2, 2.2f, 2.0f }, { 3, 50, 4, 2, 2.4f, 1.0f }, { 2, 55, 3, 4, 2.6f, 2.0f },
    { 1, 60, 3, 3, 2.6f, 1.0f },
};
FRZone D_801091C0_180F70_FiletRelay[6] = {
    { 850.0f, 1200.0f, 64.0f, 0.0f, -1.0f, 1 }, { 600.0f, 850.0f, 0.0f, 1.0f, -1.0f, 1 },
    { 80.0f, 400.0f, 10.0f, 1.0f, -1.0f, 1 }, { -10.0f, 80.0f, 50.0f, 1.0f, 1.8f, 1 },
    { -120.0f, -10.0f, -5.0f, 1.0f, 1.8f, 1 }, { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0 },
};
u8 D_80109250_181000_FiletRelay[6][3] = {
    { 0, 1, 2 }, { 0, 2, 1 }, { 1, 0, 2 }, { 2, 0, 1 }, { 1, 2, 0 }, { 2, 1, 0 },
};
/* The goal z by order, from order -1: D_80109268 and D_80109270 are inside it. */
f32 D_80109264_181014_FiletRelay[4] = { -1140.0f, 500.0f, -300.0f, -1140.0f };
FRChar D_80109274_181024_FiletRelay[6] = {
    { 2490381, 2490381, 2490375, 12.0f }, { 2490382, 2490382, 2490376, 12.0f },
    { 2490383, 2490383, 2490377, 12.0f }, { 2490384, 2490384, 2490378, 12.0f },
    { 2490385, 2490385, 2490379, 12.0f }, { 2490386, 2490386, 2490380, 12.0f },
};
FRMotDef D_801092D4_181084_FiletRelay[12] = {
    { 0x260015, 0x0 }, { 0x260016, 0x0 }, { 0x260017, 0x0 }, { 0x260018, 0xFFFF },
    { 0x260019, 0xFFFF }, { 0x26001A, 0xFFFF }, { 0x26001B, 0xFFFF }, { 0x26001E, 0xFFFF },
    { 0x26001C, 0xFFFF }, { 0x26001D, 0xFFFF }, { 0x260020, 0x0 }, { 0x26001F, 0xFFFF },
};
Vec D_80109334_1810E4_FiletRelay = { 144.0f, -44.0f, 390.0f };
Vec D_80109340_1810F0_FiletRelay = { -40.0f, -6.3f, -268.0f };
Vec D_8010934C_1810FC_FiletRelay = { -25.0f, 125.0f, 0.0f };
Vec D_80109358_181108_FiletRelay = { -52.0f, -24.7f, 0.0f };
void (*D_80109364_181114_FiletRelay[7])(omObjData*, FRPlayer*) = {
    func_801052DC_17D08C_FiletRelay, func_80105384_17D134_FiletRelay, func_80105800_17D5B0_FiletRelay,
    func_80105A4C_17D7FC_FiletRelay, func_80105BA0_17D950_FiletRelay, func_80105CAC_17DA5C_FiletRelay,
    func_80105EEC_17DC9C_FiletRelay,
};
Vec D_80109380_181130_FiletRelay = { 51.0f, -60.0f, -1053.0f };
Vec D_8010938C_18113C_FiletRelay = { -13.3f, 14.5f, 0.0f };
void (*D_80109398_181148_FiletRelay[5])(omObjData*, FRPlayer*) = {
    func_801060A4_17DE54_FiletRelay, NULL, func_801060D4_17DE84_FiletRelay, func_80106314_17E0C4_FiletRelay, NULL,
};
s32 D_801093AC_18115C_FiletRelay[2] = { 0x260002, 0x260003 };

/* A fish: flies under gravity, bounces on the ice. */
void func_80104350_17C100_FiletRelay(omObjData* obj) {
    FRFish* w = obj->unk_50;

    if (w->flying == 1) {
        HuVecMulScalar(&w->vel, 0.984f, &w->vel);
        w->vel.y += -0.64f;
        HuVecAdd(&w->pos, &w->pos, &w->vel);
        if (w->pos.y < -108.0f) {
            w->vel.x *= 0.95f;
            w->vel.y *= -0.5f;
            w->vel.z *= 0.95f;
            w->pos.y = -108.0f;
        }
        HuVecMulScalar(&w->rotVel, 0.984f, &w->rotVel);
        HuVecAdd(&w->rot, &w->rot, &w->rotVel);
        omSetTra(obj, w->pos.x, w->pos.y, w->pos.z);
        omSetRot(obj, w->rot.x, w->rot.y, w->rot.z);
    }
}

/* Set up team i's fish for a throw. */
void func_80104488_17C238_FiletRelay(s32 i, Vec* pos, Vec* vel, Vec* rotVel) {
    FRFish* w = D_8010968C_18143C_FiletRelay.objs[i]->unk_50;

    func_800B3170_B3D70(&w->pos, pos);
    HuVecCopyXYZ(&w->rot, -90.0f, 180.0f, 0.0f);
    func_800B3170_B3D70(&w->vel, vel);
    func_800B3170_B3D70(&w->rotVel, rotVel);
}

/* Hang team i's fish on a model's hook. */
void func_80104508_17C2B8_FiletRelay(s32 i, s16 model) {
    omObjData* obj = D_8010968C_18143C_FiletRelay.objs[i];
    FRFish* w = obj->unk_50;

    func_8002C628_2D228(obj->model[0], model, "pengin-item_fook");
    func_800298A4_2A4A4(obj->model[0], 0x4000, 0x4000);
    w->flying = 0;
}

/* Let team i's fish fly. */
void func_80104578_17C328_FiletRelay(s32 i) {
    omObjData* obj = D_8010968C_18143C_FiletRelay.objs[i];
    FRFish* w = obj->unk_50;

    func_800298A4_2A4A4(obj->model[0], 0x4000, 0);
    w->flying = 1;
}

/* The penguin's map marker; the runner's pulses. */
void func_801045C8_17C378_FiletRelay(omObjData* obj) {
    FRPlayer* w = obj->unk_50;
    f32 s;
    s16 x;
    s16 y;

    x = obj->trans.x * 16.0f / 240.0f + 160.0f;
    y = obj->trans.z * 90.0f / 1260.0f + 130.0f;
    espPosSet(D_80109684_181434_FiletRelay[w->player], x, y);
    if (w->state == 1) {
        w->angle += 10.0f;
        if (w->angle > 360.0f) {
            w->angle -= 360.0f;
        }
        s = HuMathSin(w->angle) * 0.2f + 1.0f;
        func_8001A91C_1B51C(D_80109684_181434_FiletRelay[w->player], s, s);
    } else {
        func_8001A91C_1B51C(D_80109684_181434_FiletRelay[w->player], 1.0f, 1.0f);
    }
}

/* Change the penguin's motion; 1 if it changed. */
s32 func_8010474C_17C4FC_FiletRelay(omObjData* obj, s32 motion) {
    FRPlayer* w = obj->unk_50;

    if (w->motion != motion) {
        func_80029FE4_2ABE4(obj->model[0], 1.0f);
        if (w->motions[motion].loop < 0) {
            func_80029BF0_2A7F0(obj->model[0], obj->motion[motion], 0, 5, 0);
        } else {
            func_80029BF0_2A7F0(obj->model[0], obj->motion[motion], 0, 5, 2);
            func_80029FBC_2ABBC(obj->model[0], w->motions[motion].loop);
        }
        w->motion = motion;
        return 1;
    }
    return 0;
}

/* Has a play-once motion ended? */
s32 func_8010483C_17C5EC_FiletRelay(omObjData* obj) {
    FRPlayer* w = obj->unk_50;
    s32 frame;
    f32 f;

    if (w->motions[w->motion].loop < 0) {
        frame = func_80029E3C_2AA3C(obj->model[0]);
        if (frame == -1) {
            frame = func_80029CE4_2A8E4(obj->model[0]);
        }
        f = frame;
        if (w->motions[w->motion].length <= f) {
            w->motion = -1;
            return 1;
        }
    }
    return 0;
}

/* The walk motion's speed. */
void func_801048F8_17C6A8_FiletRelay(omObjData* obj, f32 speed) {
    if (((FRPlayer*)obj->unk_50)->motion == 1) {
        func_80029FE4_2ABE4(obj->model[0], speed);
    }
}

/* The penguin running against player, if any. */
FRPlayer* func_80104930_17C6E0_FiletRelay(s16 player) {
    FRPlayer* w;
    s32 i;

    for (i = 0; i < 4; i++) {
        w = D_80109680_181430_FiletRelay.objs[i]->unk_50;
        if (w->player != player) {
            if (w->state == 1 || w->state == 5 || w->state == 6) {
                return w;
            }
        }
    }
    return NULL;
}

FRPlayer* func_801049AC_17C75C_FiletRelay(s8 order) {
    FRPlayer* w;
    s32 i;

    for (i = 0; i < 4; i++) {
        w = D_80109680_181430_FiletRelay.objs[i]->unk_50;
        if (w->order == order) {
            return w;
        }
    }
    return NULL;
}

/* The nearest penguin 10 to 125 ahead of w. */
FRPlayer* func_801049FC_17C7AC_FiletRelay(FRPlayer* w) {
    FRPlayer* p;
    f32 best = 10000.0f;
    f32 d;
    s32 found = -1;
    s32 i;

    for (i = 0; i < 4; i++) {
        p = D_80109680_181430_FiletRelay.objs[i]->unk_50;
        if (p != w) {
            d = w->pos.z - p->pos.z;
            if ((d > 10.0f) & (d < 125.0f)) {
                if (d < best) {
                    best = d;
                    found = i;
                }
            }
        }
    }
    if (found < 0) {
        return NULL;
    }
    return D_80109680_181430_FiletRelay.objs[found]->unk_50;
}

/* The solo penguin bumps the relay penguins. */
// register allocation (masked 0, raw 4): retail sums the radii in f4, not f2. Tried: the comparison
// reversed (masked 6), the float locals reordered (same), `if (p == NULL) continue;` (same).
#ifdef NON_MATCHING
void func_80104AE0_17C890_FiletRelay(FRPlayer* w) {
    Vec d;
    FRPlayer* p;
    f32 sum;
    f32 k;
    f32 a;
    f32 b;
    s32 i;

    for (i = 0; i < 3; i++) {
        p = func_801049AC_17C75C_FiletRelay(i);
        if (p != NULL && HuVecDistance(&p->pos, &w->pos) < p->radius + w->radius) {
            sum = w->speed + p->speed;
            k = w->speed / sum;
            a = k * w->speed;
            b = p->speed / sum * p->speed;
            if (a < 2.4f) {
                a = k * 3.6000001f;
            }
            if (b < 2.4f) {
                b = p->speed / sum * 3.6000001f;
            }
            HuVecSubtract(&d, &p->pos, &w->pos);
            if (p->state != 1 && p->state != 5 && p->state != 6) {
                HuVecCopyXYZ(&d, 0.0f, 0.0f, -1.0f);
            }
            func_801080E0_17FE90_FiletRelay(&d);
            HuVecMulScalar(&w->vel, -a, &d);
            HuVecMulScalar(&p->vel, b, &d);
            omVibrate(w->player, 10, 0, 10);
            omVibrate(p->player, 10, 0, 10);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_16_FiletRelay/17C100", func_80104AE0_17C890_FiletRelay);
#endif

/* CPU: in a zone of the course, steer to its line. 0 outside them all. */
s32 func_80104CA0_17CA50_FiletRelay(FRCpu* cpu, FRPlayer* w) {
    s32 i;

    w->cpuSpeed = cpu->speed;
    for (i = 0; D_801091C0_180F70_FiletRelay[i].valid != 0; i++) {
        if (D_801091C0_180F70_FiletRelay[i].zMin < w->pos.z && w->pos.z < D_801091C0_180F70_FiletRelay[i].zMax) {
            w->cpuTarget = D_801091C0_180F70_FiletRelay[i].x;
            if (rand8() & 1) {
                w->cpuTarget -= D_801091C0_180F70_FiletRelay[i].jitter;
            } else {
                w->cpuTarget += D_801091C0_180F70_FiletRelay[i].jitter;
            }
            if (i == 0 && w->order == -1) {
                w->cpuTarget *= -0.91f;
            }
            if (FR_ABS(w->pos.x - w->cpuTarget) < cpu->margin) {
                w->cpuStick = 0;
            } else if (w->pos.x < w->cpuTarget) {
                w->cpuStick = cpu->stick;
            } else {
                w->cpuStick = -cpu->stick;
            }
            if (D_801091C0_180F70_FiletRelay[i].speed > 0.0f) {
                w->cpuSpeed = D_801091C0_180F70_FiletRelay[i].speed;
            }
            return 1;
        }
    }
    return 0;
}

/* CPU control: steer, then press A to keep the speed. */
void func_80104EC8_17CC78_FiletRelay(omObjData* obj, FRPlayer* w) {
    FRCpu* cpu;
    FRPlayer* p;
    s32 btn = 0;

    cpu = &D_80109190_180F40_FiletRelay[w->cpu];
    if (func_80104CA0_17CA50_FiletRelay(cpu, w) == 0) {
        p = func_80104930_17C6E0_FiletRelay(w->player);
        if (p == NULL) {
            w->cpuStick = 0;
        } else if (p->pos.z - w->pos.z > 80.0f) {
            if (FR_ABS(p->pos.x - w->pos.x) < 23.0f) {
                w->cpuStick = 0;
            } else if (rand8() % 10 < cpu->chance) {
                w->cpuStick = 0;
            } else if (p->pos.x < w->pos.x) {
                w->cpuStick = -cpu->stick;
            } else {
                w->cpuStick = cpu->stick;
            }
        } else if (FR_ABS(p->pos.z - w->pos.z) < 50.0f) {
            if (FR_ABS(p->pos.x - w->pos.x) < 20.0f) {
                if (p->pos.x < w->pos.x) {
                    w->cpuStick = cpu->stick / 2;
                } else {
                    w->cpuStick = -cpu->stick / 2;
                }
            } else {
                w->cpuStick = 0;
            }
        } else {
            w->cpuStick = 0;
        }
        if (w->order == -1) {
            p = func_801049FC_17C7AC_FiletRelay(w);
            if (p != NULL) {
                if (FR_ABS(p->pos.x - w->pos.x) < 30.0f) {
                    w->cpuStick = -cpu->stick;
                }
            }
        }
    }
    if (w->speed < w->cpuSpeed || rand8() % 25 < cpu->chance) {
        btn = 0x8000;
    }
    if (w->cpuTimer++ > cpu->hold) {
        btn = 0;
        w->cpuTimer = 0;
    }
    func_80108678_180428_FiletRelay(w->port, w->cpuStick, 0, btn, 0);
}

/* State 0: waiting for the fish, facing the runner. */
void func_801052DC_17D08C_FiletRelay(omObjData* obj, FRPlayer* w) {
    FRPlayer* p;
    f32 d;
    s32 order = w->order - 1;

    if (order >= 0) {
        p = func_801049AC_17C75C_FiletRelay(order);
        if (p == NULL) {
            while (1) {
            }
        }
        if (p->state == 1) {
            d = p->pos.z - w->pos.z;
            if (d < 200.0f) {
                obj->rot.y = func_800B75A8_B81A8(p->pos.x - w->pos.x, d);
            }
        }
        w->speed = 0.0f;
    }
}

/* State 1: running. Past the goal: hand over to the next, or win. */
// decomp-permuter
void func_80105384_17D134_FiletRelay(omObjData *obj, FRPlayer *w)
{
  Vec stick;
  FRPlayer *p;
  f32 a;
  f32 fall;
  f32 skid;
  f32 last;
  f32 now;
  float new_var;
  if (w->goal > obj->trans.z)
  {
    if (((u8) w->order) < 2)
    {
      w->sub = 0;
      w->state = 2;
      p = func_801049AC_17C75C_FiletRelay(w->order + 1);
      if (p == 0)
      {
        while (1)
        {
        }

      }
      p->sub = 0;
      p->state = 3;
    }
    else
    {
      func_801089C8_180778_FiletRelay(w->team);
      func_8010899C_18074C_FiletRelay(3);
    }
    return;
  }
  if (gPlayers[w->player].flags & 1)
  {
    func_80104EC8_17CC78_FiletRelay(obj, w);
  }
  HuVecMulScalar(&w->vel, 0.98f, &w->vel);
  a = 0.0f;
  if (ContBtnTrg[w->port] & 0x8000)
  {
    a = 0.4f;
  }
  new_var = ContStkX[w->port] * 0.001f;
  HuVecCopyXYZ(&stick, new_var, 0.0f, -(a -= w->normal.z * 0.17f));
  HuVecAdd(&stick, &w->acc, &stick);
  HuVecCopyXYZ(&w->acc, 0.0f, 0.0f, 0.0f);
  HuVecAdd(&w->vel, &w->vel, &stick);
  w->vel.y = 0.0f;
  if (w->order != (-1))
  {
    HuVecMulScalar(&w->vel, 1.016f, &w->vel);
    fall = 5.15f;
    skid = 4.45f;
  }
  else
  {
    fall = 4.2f;
    skid = 3.6f;
  }
  HuVecAdd(&w->next, &w->pos, &w->vel);
  w->speed = HuVecGetLength3F(&w->vel);
  p = func_80104930_17C6E0_FiletRelay(w->player);
  if ((p != 0) && (p->pos.z < w->pos.z))
  {
    fall += 0.5f;
    skid += 0.5f;
  }
  if ((fall < w->speed) && (w->slip >= 31))
  {
    w->slip = 0;
    w->sub = 0;
    w->state = 6;
    return;
  }
  if (skid < w->speed)
  {
    if (func_8010474C_17C4FC_FiletRelay(obj, 6) != 0)
    {
      func_800798F8_7A4F8(func_80079798_7A398(0x1D1, w->player), w->pan);
    }
    if (a == 0.0f)
    {
      HuVecMulScalar(&w->vel, 0.98f, &w->vel);
    }
    w->slip++;
    return;
  }
  if (w->speed > 0.001f)
  {
    if (func_8010474C_17C4FC_FiletRelay(obj, 1) != 0)
    {
      w->step = 0.0f;
    }
    func_801048F8_17C6A8_FiletRelay(obj, w->speed);
    for (last = w->step - 12.5f; last > 25.0f; last -= 25.0f)
    {
    }

    w->step += w->speed;
    for (now = w->step - 12.5f; now > 25.0f; now -= 25.0f)
    {
    }

    if (now < last)
    {
      func_800798F8_7A4F8(func_80079798_7A398(0x1D0, w->player), w->pan);
    }
  }
  else
  {
    func_8010474C_17C4FC_FiletRelay(obj, 0);
  }
  w->slip = 0;
}

/* State 2: throw the fish to the next penguin. */
void func_80105800_17D5B0_FiletRelay(omObjData* obj, FRPlayer* w) {
    Vec vel;
    Vec rotVel;
    Vec d;
    FRPlayer* p;
    Vec* pos;

    switch (w->sub) {
        case 0:
            p = func_801049AC_17C75C_FiletRelay(w->order + 1);
            if (p == NULL) {
                while (1) {
                }
            }
            obj->rot.y = func_800B75A8_B81A8(p->pos.x - w->pos.x, p->pos.z - w->pos.z);
            func_8010474C_17C4FC_FiletRelay(obj, 3);
            if (w->order == 1) {
                func_801088A4_180654_FiletRelay(w->cam, &D_80109340_1810F0_FiletRelay, &D_80109358_181108_FiletRelay,
                                                70.0f, 0.0f);
            } else {
                func_801088A4_180654_FiletRelay(w->cam, &D_80109334_1810E4_FiletRelay, &D_8010934C_1810FC_FiletRelay,
                                                59.0f, 0.0f);
            }
            w->sub++;
            break;
        case 1:
            if (func_8010483C_17C5EC_FiletRelay(obj) != 0) {
                w->sub++;
            }
            if (++w->timer == 11) {
                p = func_801049AC_17C75C_FiletRelay(w->order + 1);
                if (p == NULL) {
                    while (1) {
                    }
                }
                pos = &w->pos;
                HuVecSubtract(&d, &p->pos, pos);
                HuVecCopyXYZ(&vel, d.x * 0.05f, 7.0f, d.z * 0.05f);
                HuVecCopyXYZ(&rotVel, -18.0f, 0.0f, -18.0f);
                func_80104488_17C238_FiletRelay(w->team, pos, &vel, &rotVel);
                func_80104578_17C328_FiletRelay(w->team);
                func_800798F8_7A4F8(func_80079798_7A398(0x1D4, w->player), w->pan);
            }
            break;
        case 2:
            if (w->timer2++ >= 31) {
                w->sub++;
            }
            break;
        case 3:
            w->timer2 = 0;
            w->timer = 0;
            w->sub = 0;
            w->state = 4;
            break;
    }
    w->speed = 0.0f;
}

/* State 3: catch the fish; then run. */
void func_80105A4C_17D7FC_FiletRelay(omObjData* obj, FRPlayer* w) {
    switch (w->sub) {
        case 0:
            if (w->timer++ >= 21) {
                w->sub++;
            }
            break;
        case 1:
            func_8010474C_17C4FC_FiletRelay(obj, 4);
            w->sub++;
            break;
        case 2:
            if (func_8010483C_17C5EC_FiletRelay(obj) != 0) {
                w->sub++;
            }
            if (++w->timer2 == 11) {
                func_800798F8_7A4F8(func_80079798_7A398(0x1D3, w->player), w->pan);
                omVibrate(w->player, 10, 0, 10);
                func_80104508_17C2B8_FiletRelay(w->team, obj->model[0]);
            }
            break;
        case 3:
            obj->rot.y = 180.0f;
            w->timer2 = 0;
            w->timer = 0;
            w->sub = 0;
            HuVecCopyXYZ(&w->acc, 0.0f, 0.0f, -2.0f);
            w->state = 1;
            break;
    }
    w->speed = 0.0f;
}

/* State 4: after the throw: slide off the side. */
void func_80105BA0_17D950_FiletRelay(omObjData* obj, FRPlayer* w) {
    switch (w->sub) {
        case 0:
            if (w->flags & 1) {
                w->flags |= 4;
                w->next.x += 2.0f;
                w->sub++;
            } else {
                obj->rot.y = 180.0f;
                w->next.x += 2.0f;
                w->next.z -= 0.2f;
                func_8010474C_17C4FC_FiletRelay(obj, 5);
            }
            break;
        default:
            w->next.x += 2.0f;
            w->sub++;
            break;
        case 5:
            obj->rot.y = 0.0f;
            w->sub++;
            break;
        case 6:
            break;
    }
    w->speed = 0.0f;
}

/* State 5: hit by a thrown object: flattened, wobbles back. */
void func_80105CAC_17DA5C_FiletRelay(omObjData* obj, FRPlayer* w) {
    Vec d;
    f32 s = 1.0f;
    f32 v;

    switch (w->sub) {
        case 0:
            omVibrate(w->player, 10, 0, 10);
            HuVecSubtract(&d, &w->pos, &w->hitPos);
            func_801080E0_17FE90_FiletRelay(&d);
            v = w->speed;
            if (v < 2.4f) {
                v = 6.0f;
            }
            HuVecMulScalar(&w->vel, v * 0.8f, &d);
            HuVecCopyXYZ(&w->acc, 0.0f, 0.0f, 0.0f);
            s = 0.7f;
            w->angle = w->turn = 0.0f;
            w->wobbleGrow = 0.010000001f;
            w->sub++;
            break;
        case 1:
            if (w->timer++ >= 31) {
                w->sub++;
            }
            s = HuMathSin(w->angle) * w->turn + 0.7f;
            w->angle += w->turnStep;
            w->turn += w->wobbleGrow;
            break;
        case 2:
            w->timer = 0;
            s = 1.0f;
            w->sub = 0;
            w->angle = w->turn = w->turnStep = w->wobbleGrow = 0.0f;
            w->state = 1;
            break;
    }
    HuVecMulScalar(&w->vel, 0.98f, &w->vel);
    w->vel.y = 0.0f;
    HuVecAdd(&w->next, &w->pos, &w->vel);
    w->speed = HuVecGetLength3F(&w->vel);
    omSetSca(obj, 0.25f, s * 0.25f, 0.25f);
}

/* State 6: slipped: down and up again; off the end, the race is decided. */
void func_80105EEC_17DC9C_FiletRelay(omObjData* obj, FRPlayer* w) {
    if (w->goal > obj->trans.z) {
        if (w->order == -1 || w->order == 2) {
            func_8010474C_17C4FC_FiletRelay(obj, 9);
            func_801089C8_180778_FiletRelay(w->team);
            func_8010899C_18074C_FiletRelay(3);
        }
    }
    switch (w->sub) {
        case 0:
            func_800798F8_7A4F8(func_80079798_7A398(0x1D2, w->player), w->pan);
            omVibrate(w->player, 2, 2, 20);
            func_8010474C_17C4FC_FiletRelay(obj, 8);
            w->sub++;
            break;
        case 2:
            if (w->timer++ >= 31) {
                w->sub++;
            }
            break;
        case 3:
            func_8010474C_17C4FC_FiletRelay(obj, 9);
            w->sub++;
            break;
        case 1:
        case 4:
            if (func_8010483C_17C5EC_FiletRelay(obj) != 0) {
                w->sub++;
            }
            break;
        case 5:
            w->timer = 0;
            w->sub = 0;
            w->state = 1;
            break;
    }
    HuVecMulScalar(&w->vel, 0.88f, &w->vel);
    HuVecCopyXYZ(&w->acc, 0.0f, 0.0f, 0.0f);
    w->vel.y = 0.0f;
    w->vel.z += w->normal.z * 0.17f;
    HuVecAdd(&w->next, &w->pos, &w->vel);
    w->speed = HuVecGetLength3F(&w->vel);
}

/* Game state 0: the fish starts with the first runners. */
void func_801060A4_17DE54_FiletRelay(omObjData* obj, FRPlayer* w) {
    if (w->order <= 0) {
        func_80104508_17C2B8_FiletRelay(w->team, obj->model[0]);
    }
}

/* Game state 2: a penguin's frame. */
// decomp-permuter
void func_801060D4_17DE84_FiletRelay(omObjData *obj, FRPlayer *w)
{
  Vec a;
  Vec b;
  Vec c;
  Vec eye;
  if (w->order == (-1))
  {
    func_80104AE0_17C890_FiletRelay(w);
  }
  if ((w->state == 1) || (w->state == 6))
  {
    HuVecCopyXYZ(&a, w->pos.x, w->pos.y + w->radius, w->pos.z);
    switch (func_80103EE0_17BC90_FiletRelay(&a, w->radius, &w->hitPos))
    {
      case 1:
        w->state = 5;
        w->sub = 0;
        break;

      case 2:
        HuVecSubtract(&b, &w->pos, &w->hitPos);
 do { func_801080E0_17FE90_FiletRelay(&b); } while (0);
        HuVecMulScalar(&w->vel, -w->speed, &b);
        break;

    }

  }
  D_80109364_181114_FiletRelay[w->state](obj, w);
  w->flags &= ~1;
  if (w->next.z > 1300.0f)
  {
    w->next.z = 1300.0f;
  }
  if (!(w->flags & 4))
  {
    if (func_80104074_17BE24_FiletRelay(&w->pos, &w->next, &w->vel, &w->normal, &w->speed) != 0)
    {
      w->flags |= 1;
    }
  }
  func_800B3170_B3D70(&w->pos, &w->next);
  func_801045C8_17C378_FiletRelay(obj);
  if (((w->state == 1) || (w->state == 6)) || (w->state == 5))
  {
    func_801086B4_180464_FiletRelay(w->cam, &eye);
    eye.z = w->vel.x * (-1.5f);
    HuVecCopyXYZ(&c, w->pos.x, w->pos.y + 50.0f, w->pos.z + 60.0f);
    func_80108770_180520_FiletRelay(w->cam, &c, &eye, 0.0f, 0.0f);
  }
}

/* Game state 3: the end of the race. */
void func_80106314_17E0C4_FiletRelay(omObjData* obj, FRPlayer* w) {
    Vec vel;
    Vec rotVel;
    Vec a;
    Vec c;
    Vec eye;
    f32 d;

    switch (w->endState) {
        case 0:
            if (func_801089D4_180784_FiletRelay() == w->team) {
                func_801089E0_180790_FiletRelay(w->player);
            }
            func_8010474C_17C4FC_FiletRelay(obj, 1);
            if (_CheckFlag(0xC) == 0) {
                w->endState = 2;
                return;
            }
            w->endState++;
            return;
        case 1:
            if (w->speed < 0.4f) {
                w->endState = 100;
            }
            HuVecMulScalar(&w->vel, 0.91f, &w->vel);
            w->speed = HuVecGetLength3F(&w->vel);
            HuVecAdd(&w->next, &w->pos, &w->vel);
            func_80104074_17BE24_FiletRelay(&w->pos, &w->next, &w->vel, &w->normal, &w->speed);
            func_800B3170_B3D70(&w->pos, &w->next);
            omSetTra(obj, w->pos.x, w->pos.y, w->pos.z);
            func_801048F8_17C6A8_FiletRelay(obj, w->speed);
            return;
        case 2:
            HuVecMulScalar(&w->vel, 0.91f, &w->vel);
            if (func_801089D4_180784_FiletRelay() == w->team) {
                w->acc.y = w->acc.z = 0.0f;
                if (D_80109270_181020_FiletRelay - 60.0f < w->pos.z) {
                    w->acc.z = -0.1f;
                }
                if (w->pos.x < -5.0f) {
                    w->acc.x = 0.1f;
                } else if (w->pos.x > 5.0f) {
                    w->acc.x = -0.1f;
                } else {
                    w->endState++;
                }
                HuVecAdd(&w->vel, &w->acc, &w->vel);
            } else if (w->speed < 0.4f) {
                w->endState++;
            }
            w->speed = HuVecGetLength3F(&w->vel);
            HuVecAdd(&w->next, &w->pos, &w->vel);
            func_80104074_17BE24_FiletRelay(&w->pos, &w->next, &w->vel, &w->normal, &w->speed);
            func_800B3170_B3D70(&w->pos, &w->next);
            omSetTra(obj, w->pos.x, w->pos.y, w->pos.z);
            func_801048F8_17C6A8_FiletRelay(obj, w->speed);
            return;
        case 3:
            if (func_801089D4_180784_FiletRelay() < 0) {
                w->endState = 10;
                return;
            }
            if (func_801089D4_180784_FiletRelay() == w->team) {
                w->endState = 20;
                return;
            }
            w->endState = 50;
            return;
        case 10:
            if (w->sub++ >= 51) {
                w->endState = 50;
            }
            return;
        case 20:
            if (w->order == -1 || w->order == 2) {
                w->endState++;
                return;
            }
            w->endState = 25;
            return;
        case 21:
            obj->rot.y = func_800B75A8_B81A8(w->pos.x, -1300.0f - w->pos.z);
            func_8010474C_17C4FC_FiletRelay(obj, 3);
            func_801088A4_180654_FiletRelay(w->cam, &D_80109380_181130_FiletRelay, &D_8010938C_18113C_FiletRelay, 60.0f,
                                            0.0f);
            w->endState++;
            return;
        case 22:
            if (func_8010483C_17C5EC_FiletRelay(obj) != 0) {
                w->endState++;
            }
            if (++w->sub == 11) {
                a.x = 0.0f - w->pos.x;
                a.z = -1250.0f - w->pos.z;
                HuVecCopyXYZ(&vel, a.x * 0.028f, 7.0f, a.z * 0.028f);
                HuVecCopyXYZ(&rotVel, 0.0f, 0.0f, 0.0f);
                func_80104488_17C238_FiletRelay(w->team, &w->pos, &vel, &rotVel);
                func_80104578_17C328_FiletRelay(w->team);
                func_80103FF8_17BDA8_FiletRelay();
            }
            return;
        case 23:
            func_80108714_1804C4_FiletRelay(w->cam, &a);
            w->angle = func_800B75A8_B81A8(a.x - w->pos.x, a.z - w->pos.z) - 360.0f;
            w->endState++;
            return;
        case 24:
            w->turn = w->angle - obj->rot.y;
            if (FR_ABS(w->turn) > 1.0f) {
                w->turnStep = w->turn / 30.0f;
                if (w->turnStep < 0.0f) {
                    w->turnStep = -w->turnStep;
                }
                if (w->turnStep > 1.0f) {
                    w->turnStep = 1.0f;
                }
                if (w->turn <= 0.0f) {
                    w->turnStep = -w->turnStep;
                }
                obj->rot.y += w->turnStep * 30.0f;
                return;
            }
            obj->rot.y = w->angle;
            func_80079718_7A318(0x103, w->character);
            w->endState++;
            return;
        case 25:
            func_8010474C_17C4FC_FiletRelay(obj, 10);
            w->endState = 100;
            return;
        case 50:
            if (w->timer++ >= 31) {
                w->endState++;
            }
            return;
        case 51:
            func_8010474C_17C4FC_FiletRelay(obj, 11);
            if (w->order == -1 || w->order == 2) {
                w->endState++;
                return;
            }
            w->endState = 100;
            return;
        case 52:
            func_80108714_1804C4_FiletRelay(w->cam, &c);
            func_801086B4_180464_FiletRelay(w->cam, &eye);
            eye.x -= 0.12f;
            c.y += 0.8f;
            c.z += 0.8f;
            func_80108770_180520_FiletRelay(w->cam, &c, &eye, 0.0f, 0.0f);
            return;
        case 100:
            return;
    }
}

/* A penguin object: the game state's function, then place it and its shadow. */
void func_80106A2C_17E7DC_FiletRelay(omObjData* obj) {
    FRPlayer* w = obj->unk_50;

    if (D_80109398_181148_FiletRelay[func_80108990_180740_FiletRelay()] != NULL) {
        D_80109398_181148_FiletRelay[func_80108990_180740_FiletRelay()](obj, w);
    }
    omSetTra(obj, w->pos.x, w->pos.y, w->pos.z);
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
}

/* Set up player's penguin: model, shadow, motions, relay place, camera, map marker. */
void func_80106AD8_17E888_FiletRelay(omObjData* obj, s32 player) {
    s8 chr = gPlayers[player].character;
    FRPlayer* w;
    s32 i;
    s32 sprite;

    obj->model[0] = LoadFormFile(D_80109274_181024_FiletRelay[chr].model, 0xAD9);
    obj->model[1] = func_80018A64_19664(0xD, 0xAD9);
    func_8003C8E0_3D4E0(obj->model[1]);
    w = func_80027154_27D54(sizeof(FRPlayer), 0x7918);
    if (w == NULL) {
        while (1) {
        }
    }
    func_800B0EF0_B1AF0(w, 0, sizeof(FRPlayer));
    obj->unk_50 = w;
    for (i = 0; i < 12; i++) {
        obj->motion[i] = func_8002C8B8_2D4B8(DataRead(D_801092D4_181084_FiletRelay[i].file), 0x18);
        if (obj->motion[i] < 0) {
            while (1) {
            }
        }
        w->motions[i].length = func_8002CA14_2D614(obj->motion[i]);
        w->motions[i].loop = D_801092D4_181084_FiletRelay[i].loop;
    }
    w->player = player;
    w->port = gPlayers[player].port;
    w->team = gPlayers[player].group;
    if (w->team == 0) {
        w->order = -1;
        w->cam = 0;
        w->pan = 0x20;
    } else {
        w->order = D_80109250_181000_FiletRelay[D_80109690_181440_FiletRelay][D_80109694_181444_FiletRelay++];
        w->cam = 1;
        w->pan = 0x60;
    }
    if (w->order <= 0) {
        w->state = 1;
    } else {
        w->state = 0;
    }
    switch (gPlayers[player].cpu_difficulty) {
        case 1:
            w->cpu = 1;
            break;
        case 2:
            w->cpu = 2;
            break;
        case 3:
            w->cpu = 3;
            break;
        default:
            while (1) {
            }
        case 0:
            w->cpu = 0;
            break;
    }
    w->character = chr;
    w->radius = D_80109274_181024_FiletRelay[chr].radius;
    w->goal = D_80109268_181018_FiletRelay[w->order];
    i = w->order + 1;
    omSetTra(obj, D_80109160_180F10_FiletRelay[i].x, D_80109160_180F10_FiletRelay[i].y, D_80109160_180F10_FiletRelay[i].z);
    if (w->state == 1) {
        obj->rot.y = 180.0f;
        func_8010474C_17C4FC_FiletRelay(obj, 0);
    } else {
        func_8010474C_17C4FC_FiletRelay(obj, 2);
    }
    omSetSca(obj, 0.25f, 0.25f, 0.25f);
    func_80029714_2A314(obj->model[1], D_80109160_180F10_FiletRelay[i].x, D_80109160_180F10_FiletRelay[i].y,
                        D_80109160_180F10_FiletRelay[i].z);
    func_800297E8_2A3E8(obj->model[1], 0.25f, 0.25f, 0.25f);
    func_800B3170_B3D70(&w->pos, &D_80109160_180F10_FiletRelay[i]);
    func_800B3170_B3D70(&w->next, &D_80109160_180F10_FiletRelay[i]);
    HuVecCopyXYZ(&w->vel, 0.0f, 0.0f, 0.0f);
    HuVecCopyXYZ(&w->acc, 0.0f, 0.0f, 0.0f);
    w->unk_60 = -1;
    sprite = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(D_80109274_181024_FiletRelay[chr].sprite), 0, 0);
    if ((s16)sprite == -1) {
        while (1) {
        }
    }
    D_80109684_181434_FiletRelay[player] = sprite;
    func_801045C8_17C378_FiletRelay(obj);
}

void func_80106F38_17ECE8_FiletRelay(void) {
    s32 i;

    func_80076BD0_777D0(0, 4);
    D_80109680_181430_FiletRelay.objs = func_80076D80_77980(0);
    D_80109690_181440_FiletRelay = rand8() % 6;
    D_80109694_181444_FiletRelay = 0;
    for (i = 0; i < 4; i++) {
        D_80109680_181430_FiletRelay.objs[i] = omAddObj(3, 2, 0xC, 0, func_80106A2C_17E7DC_FiletRelay);
        func_80106AD8_17E888_FiletRelay(D_80109680_181430_FiletRelay.objs[i], i);
    }
}

void func_80107018_17EDC8_FiletRelay(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        omDelObj(func_80076D98_77998(0, i));
        func_8001AC44_1B844(D_80109684_181434_FiletRelay[i]);
    }
}

/* The two fish. */
void func_8010707C_17EE2C_FiletRelay(void) {
    omObjData* obj;
    FRFish* w;
    s32 i;

    func_80076BD0_777D0(2, 2);
    D_8010968C_18143C_FiletRelay.objs = func_80076D80_77980(2);
    for (i = 0; i < 2; i++) {
        obj = omAddObj(4, 1, 0, 2, func_80104350_17C100_FiletRelay);
        obj->model[0] = func_80018A30_19630(D_801093AC_18115C_FiletRelay[i], 0xAD9);
        omSetSca(obj, 0.25f, 0.25f, 0.25f);
        w = func_80027154_27D54(sizeof(FRFish), 0x7918);
        if (w == NULL) {
            while (1) {
            }
        }
        func_800B0EF0_B1AF0(w, 0, sizeof(FRFish));
        D_8010968C_18143C_FiletRelay.objs[i]->unk_50 = w;
        D_8010968C_18143C_FiletRelay.objs[i] = obj;
    }
}

void func_801071A8_17EF58_FiletRelay(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        omDelObj(func_80076D98_77998(2, i));
    }
}

