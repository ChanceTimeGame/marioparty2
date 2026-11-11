#include "ovl_22.h"

/* .data (1E1260-1E1360, 8010CB80-8010CC80) */
f32 D_8010CB80_1E1260_ShellShocked[4] = { 0.75f, 0.970000029f, 1.0f, 1.10000002f };
f32 D_8010CB90_1E1270_ShellShocked[4] = { 1.5f, 1.10000002f, 1.0f, 0.800000012f };
f32 D_8010CBA0_1E1280_ShellShocked[4] = { 0.699999988f, 0.300000012f, 0.00999999978f, 0.0f };
s32 D_8010CBB0_1E1290_ShellShocked[3][4] = {
    { 20, 12, 10, 6 },
    { 35, 30, 20, 20 },
    { 25, 20, 20, 15 },
};
s32 D_8010CBE0_1E12C0_ShellShocked[4] = { 3, 4, 6, 8 };
s32 D_8010CBF0_1E12D0_ShellShocked[4] = { 3, 5, 7, 9 };
s32 D_8010CC00_1E12E0_ShellShocked[4] = { 8, 6, 5, 5 };
s32 D_8010CC10_1E12F0_ShellShocked[4] = { 56, 63, 67, 70 };
f32 D_8010CC20_1E1300_ShellShocked[2][4] = {
    { 0.99000001f, 0.995000005f, 0.998899996f, 0.999199986f },
    { 1.10000002f, 1.10000002f, 1.10000002f, 1.10000002f },
};
f32 D_8010CC40_1E1320_ShellShocked[4] = { 2.70000005f, 2.70000005f, 2.70000005f, 2.70000005f };
f32 D_8010CC50_1E1330_ShellShocked[4] = { 0.99000001f, 0.995000005f, 0.998899996f, 0.999199986f };
f32 D_8010CC60_1E1340_ShellShocked[8] = { 120.0f, 100.0f, 90.0f, 80.0f, 0.0299999993f, 0.0399999991f, 0.0500000007f, 0.0500000007f };

void func_80105190_1D9870_ShellShocked(void) {
    s32 i;
    s32 j;
    s32 level;
    s32 r;
    SSCom* com;

    for (i = 0; i < 4; i++) {
        com = &D_8010D740_1E1E20_ShellShocked[i];
        com->state = 0;
        com->timer = 0;
        com->count = 0;
        for (j = 0; j < 4; j++) {
            com->unk_10[j] = 0;
        }
        level = func_80103998_1D8078_ShellShocked(i);
        switch (level) {
        case 0:
            level = 0;
            break;
        case 1:
            level = 1;
            break;
        case 2:
            level = 2;
            break;
        default:
            level = 3;
            break;
        }
        r = func_8010CAA4_1E1184_ShellShocked() * 3.0f;
        r += r == i;
        func_80107AB8_1DC198_ShellShocked(i, D_8010DA80_1E2160_ShellShocked[r].pos.x, D_8010DA80_1E2160_ShellShocked[r].pos.z, D_8010CBB0_1E1290_ShellShocked[D_8010DFDC_1E26BC_ShellShocked][level]);
        com->cellY = -1;
        com->cellX = -1;
        com->stuck = 0;
    }
}

void func_80105304_1D99E4_ShellShocked(void) {
    SSCom* com;
    s32 i;
    s32 j;

    for (i = 0; i < 4; i++) {
        com = &D_8010D740_1E1E20_ShellShocked[i];
        for (j = 0; j < 4; j++) {
            com->unk_10[j] = 0;
        }
    }
}

void func_80105360_1D9A40_ShellShocked(s32 i) {
    SSCom* com;
    s32 t;

    com = &D_8010D740_1E1E20_ShellShocked[i];
    if (com->timer == 0) {
        com->timer = 0x1E;
    }
    com->timer--;
    if (com->timer == 0 && !(rand8() & 1)) {
        com->state = 1;
        t = rand8();
        com->timer = t;
        if ((f32)t < 0.0f) {
            com->timer = -t;
        }
    } else {
        func_80108100_1DC7E0_ShellShocked(i);
    }
}

/* NON_MATCHING: register allocation (masked 1, raw 8): the tank array's base lands in a0 (retail a1),
   so t needs a move into a0 for the call. Tried: com->target read directly, tank before com, t
   declared first. */
#ifdef NON_MATCHING
void func_80105428_1D9B08_ShellShocked(s32 i) {
    Vec a;
    Vec b;
    Vec c;
    Vec d;
    Vec e;
    SSCom* com;
    SSTank* tank;
    SSTank* q;
    s32 t;
    f32 speed;
    f32 l;

    com = &D_8010D740_1E1E20_ShellShocked[i];
    tank = &D_8010DA80_1E2160_ShellShocked[i];
    t = com->target;
    q = &D_8010DA80_1E2160_ShellShocked[t];
    if (t != -1 && func_8010C1F0_1E08D0_ShellShocked(t) == 0) {
        if (com->timer == 0) {
            com->timer = 0xA;
        }
        func_800B3170_B3D70(&a, &tank->pos);
        func_800B3170_B3D70(&b, &q->pos);
        speed = D_8010CB80_1E1260_ShellShocked[tank->level] * 70.0f;
        e.x = b.x - a.x;
        e.z = b.z - a.z;
        l = 1.0f / func_800B1830_B2430(e.x * e.x + e.z * e.z);
        e.x = l * e.x;
        e.z = l * e.z;
        c.x = e.x;
        c.z = e.z;
        d.x = HuMathSin(tank->rot.y);
        d.z = func_800B7890_B8490(tank->rot.y);
        e.x = speed * (c.x * d.x + c.z * d.z);
        e.z = -speed * (c.x * d.z - c.z * d.x);
        func_8010B08C_1DF76C_ShellShocked(i, e.z, -e.x);
        com->timer--;
        com->count++;
        if (com->timer <= 0) {
            com->timer = 0;
            func_80108100_1DC7E0_ShellShocked(i);
        }
    } else {
        func_80108100_1DC7E0_ShellShocked(i);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_ShellShocked/1D9870", func_80105428_1D9B08_ShellShocked);
#endif

void func_80105648_1D9D28_ShellShocked(s32 i) {
    SSCom* com;
    s32 r;
    s32 who;

    com = func_80107714_1DBDF4_ShellShocked(i);
    if (com->a.i != 0) {
        r = func_801083C4_1DCAA4_ShellShocked(i, com->goal.x, com->goal.z);
    } else {
        r = func_8010856C_1DCC4C_ShellShocked(i, com->goal.x, com->goal.z);
    }
    if (r == 0) {
        goto done;
    }
    if (com->timer >= com->limit) {
        func_80108100_1DC7E0_ShellShocked(i);
        return;
    }
    func_801087F8_1DCED8_ShellShocked(i, &who);
    if (who != -1 && func_801087F8_1DCED8_ShellShocked(i, &who) < D_8010DFD0_1E26B0_ShellShocked * D_8010DFD0_1E26B0_ShellShocked) {
done:
        func_80107A90_1DC170_ShellShocked(i);
    } else {
        com->timer++;
    }
}

void func_80105758_1D9E38_ShellShocked(s32 i) {
    Vec a;
    Vec b;
    Vec c;
    Vec d;
    Vec e;
    SSCom* com;
    SSTank* tank;
    SSTank* other;
    f32 speed;
    f32 l;

    com = &D_8010D740_1E1E20_ShellShocked[i];
    tank = &D_8010DA80_1E2160_ShellShocked[i];
    other = &D_8010DA80_1E2160_ShellShocked[com->target];
    if (com->target == -1) {
        goto done;
    }
    func_800B3170_B3D70(&a, &tank->pos);
    func_800B3170_B3D70(&b, &other->pos);
    speed = D_8010CB80_1E1260_ShellShocked[tank->level] * 70.0f;
    e.x = b.x - a.x;
    e.z = b.z - a.z;
    l = 1.0f / func_800B1830_B2430(e.x * e.x + e.z * e.z);
    e.x = l * e.x;
    e.z = l * e.z;
    c.x = e.x;
    c.z = e.z;
    d.x = HuMathSin(tank->rot.y);
    d.z = func_800B7890_B8490(tank->rot.y);
    e.x = speed * (c.x * d.z - c.z * d.x);
    e.z = speed * (c.x * d.x + c.z * d.z);
    func_8010B0B4_1DF794_ShellShocked(i, e.z, -e.x);
    if (com->timer >= com->limit || func_8010C1F0_1E08D0_ShellShocked(com->target) != 0) {
done:
        func_80107A90_1DC170_ShellShocked(i);
    } else {
        com->timer++;
    }
}

void func_80105960_1DA040_ShellShocked(s32 i) {
    Vec a;
    Vec b;
    Vec c;
    Vec d;
    Vec e;
    f32 dist[4];
    s32 sees[4];
    Vec f;
    Vec g;
    Vec h;
    Vec k;
    Vec m;
    Vec n;
    SSTank* tank;
    SSTank* p;
    SSCom* com;
    Vec* v;
    s32 j;
    s32 idx;
    s32 tgt;
    s32 best;
    s32 t;
    f32 yaw;
    f32 near;
    f32 l;
    f32 speed;
    f32 dot;
    f32 len;

    tank = &D_8010DA80_1E2160_ShellShocked[i];
    func_80103884_1D7F64_ShellShocked(2);
    func_800B3170_B3D70(&b, &tank->pos);
    yaw = tank->rot.y;
    c.x = HuMathSin(yaw);
    c.z = func_800B7890_B8490(yaw);
    d.x = c.x * 100.0f + b.x;
    d.z = c.z * 100.0f + b.z;
    for (j = 0; j < 4; j++) {
        p = &D_8010DA80_1E2160_ShellShocked[j];
        e.x = p->pos.x - tank->pos.x;
        e.z = p->pos.z - tank->pos.z;
        dist[j] = e.x * e.x + e.z * e.z;
    }
    near = 3.4028235e38f;
    for (j = 0, idx = -1; j < 4; j++) {
        sees[j] = -1;
        if (j != i && func_8010C1F0_1E08D0_ShellShocked(j) == 0) {
            if (dist[j] < near) {
                near = dist[j];
                idx = j;
            }
            sees[j] = func_801072FC_1DB9DC_ShellShocked(i, j);
        }
    }
    tgt = idx;
    if (tgt != -1) {
        best = sees[tgt];
        if (best != -1) {
            for (j = 0; j < 4; j++) {
                if (j != i && func_8010C1F0_1E08D0_ShellShocked(j) == 0) {
                    if (sees[j] != -1) {
                        if (best != 1) {
                            best = 0;
                            tgt = j;
                        }
                    }
                }
            }
            if (func_80103938_1D8018_ShellShocked() != 0) {
                if (tgt > 0) {
                    tgt = 0;
                }
            }
        }
        v = &D_8010DA80_1E2160_ShellShocked[tgt].pos;
        a.x = v->x;
        a.z = v->z;
        e.x = a.x - tank->pos.x;
        e.z = a.z - tank->pos.z;
        l = 1.0f / func_800B1830_B2430(e.x * e.x + e.z * e.z);
        e.x = l * e.x;
        e.z = l * e.z;
        k.x = e.x;
        k.z = e.z;
        h.x = e.x * 10.0f * 10.0f + tank->pos.x;
        h.z = e.z * 10.0f * 10.0f + tank->pos.z;
        for (j = 0; j < D_8010DFE0_1E26C0_ShellShocked->count; j++) {
            v = &D_8010DFE0_1E26C0_ShellShocked->pillars[j];
            k.x = v->x - tank->pos.x;
            k.z = v->z - tank->pos.z;
            len = k.x * k.x + k.z * k.z;
            if (len < 10000.0f) {
                m.x = a.z - tank->pos.z;
                m.z = -a.x - tank->pos.x;
                n.x = v->x - tank->pos.x;
                n.z = v->z - tank->pos.z;
                dot = m.x * n.x + m.z * n.z;
                len = 1.0f / func_800B1830_B2430(n.x * n.x + n.z * n.z);
                if (dot < 0.0f) {
                    e.x = len * n.z;
                    e.z = -n.x * len;
                } else {
                    e.x = -n.z * len;
                    e.z = n.x * len;
                }
                break;
            }
        }
        f.x = e.x;
        f.z = e.z;
        g.x = HuMathSin(tank->rot.y);
        g.z = func_800B7890_B8490(tank->rot.y);
        speed = D_8010CC10_1E12F0_ShellShocked[tank->level];
        e.x = speed * (f.x * g.x + f.z * g.z);
        e.z = -speed * (f.x * g.z - f.z * g.x);
        if (tank->shell[0].state == 4) {
            e.x = -e.x;
            func_80107EF8_1DC5D8_ShellShocked(i, tgt, D_8010CBE0_1E12C0_ShellShocked[D_8010DA80_1E2160_ShellShocked[i].level] + (rand8() & 7));
        }
        if (func_8010B08C_1DF76C_ShellShocked(i, e.z, e.x) != 4) {
            yaw = func_80107044_1DB724_ShellShocked(i, tgt);
        } else {
            yaw = tank->rot.y;
        }
        best = func_801072FC_1DB9DC_ShellShocked(i, tgt);
        switch (best) {
        case -1:
            break;
        case 0:
            func_8010B494_1DFB74_ShellShocked(i, 0);
            func_80107EF8_1DC5D8_ShellShocked(i, tgt, D_8010CBF0_1E12D0_ShellShocked[D_8010DA80_1E2160_ShellShocked[i].level] + (rand8() & 3));
            com = func_80107714_1DBDF4_ShellShocked(i);
            com->hits = 0;
            com->lastTarget = -1;
            func_80107C04_1DC2E4_ShellShocked(tgt);
            break;
        case 1:
            func_8010B494_1DFB74_ShellShocked(i, 1);
            t = (rand8() & 7) + 4;
            func_80107EF8_1DC5D8_ShellShocked(i, tgt, t);
            com = func_80107714_1DBDF4_ShellShocked(i);
            if (com->lastTarget == tgt) {
                com->hits++;
            } else {
                com->hits = 0;
            }
            com->lastTarget = tgt;
            if (com->hits >= 4) {
                func_80107FB4_1DC694_ShellShocked(i, tgt, t);
            }
            break;
        }
        if (dist[tgt] < D_8010DFD0_1E26B0_ShellShocked * D_8010DFD0_1E26B0_ShellShocked * 0.82f) {
            func_80107EF8_1DC5D8_ShellShocked(i, tgt, D_8010CC00_1E12E0_ShellShocked[D_8010DA80_1E2160_ShellShocked[i].level] + (rand8() & 3));
        }
    }
    tank->rot.y = yaw;
}

// register allocation (masked 31, 473 vs 472): retail loads rot.y into yaw (f26) and copies it to f20 before
// sin/cos; i and com swap s2/s3. S3-S tried: near = yaw before the calls (coalesced), near declared first.
#ifdef NON_MATCHING
void func_801060D0_1DA7B0_ShellShocked(s32 i) {
    Vec a;
    Vec b;
    Vec c;
    Vec d;
    Vec e;
    Vec f;
    Vec g;
    Vec h;
    Vec k;
    SSTank* tank;
    SSCom* com;
    s32 t;
    s32 j;
    s32 r;
    f32 speed;
    f32 yaw;
    f32 near;
    f32 l;
    f32 len;

    tank = &D_8010DA80_1E2160_ShellShocked[i];
    com = func_80107714_1DBDF4_ShellShocked(i);
    speed = D_8010CB80_1E1260_ShellShocked[tank->level] * 70.0f;
    func_80103884_1D7F64_ShellShocked(2);
    func_800B3170_B3D70(&a, &tank->pos);
    near = tank->rot.y;
    b.x = HuMathSin(near);
    b.z = func_800B7890_B8490(near);
    yaw = near;
    c.x = b.x * 100.0f + a.x;
    c.z = b.z * 100.0f + a.z;
    t = com->target;
    if (t == -1 || func_8010C1F0_1E08D0_ShellShocked(t) != 0) {
        func_80107A90_1DC170_ShellShocked(i);
        return;
    }
    f.x = D_8010DA80_1E2160_ShellShocked[t].pos.x - a.x;
    f.z = D_8010DA80_1E2160_ShellShocked[t].pos.z - a.z;
    near = f.x * f.x + f.z * f.z;
    for (j = 0; j < 4; j++) {
        if (j != i) {
        if (j != t) {
        if (func_8010C1F0_1E08D0_ShellShocked(j) == 0) {
            d.x = D_8010DA80_1E2160_ShellShocked[j].pos.x;
            d.z = D_8010DA80_1E2160_ShellShocked[j].pos.z;
            e.x = d.x - a.x;
            e.z = d.z - a.z;
            if (e.x * f.x + e.z * f.z > 0.7f) {
                len = e.x * e.x + e.z * e.z;
                if (len < near) {
                    t = j;
                    near = len;
                }
            }
        }
        }
        }
    }
    if (func_80103938_1D8018_ShellShocked() != 0 && func_8010CAA4_1E1184_ShellShocked() * 100.0f < 90.0f) {
        t = 0;
    }
    j = 4;
    d.x = D_8010DA80_1E2160_ShellShocked[t].pos.x;
    d.z = D_8010DA80_1E2160_ShellShocked[t].pos.z;
    e.x = d.x - a.x;
    e.z = d.z - a.z;
    g.x = e.x;
    g.z = e.z;
    l = 1.0f / func_800B1830_B2430(e.x * e.x + e.z * e.z);
    g.x = l * g.x;
    g.z = l * g.z;
    h.x = b.x;
    h.z = b.z;
    k.x = speed * (g.x * b.x + g.z * b.z);
    k.z = -speed * (g.x * b.z - g.z * b.x);
    if (func_8010B08C_1DF76C_ShellShocked(i, k.z, k.x) != j) {
        tank->pos.x = a.x;
        tank->pos.z = a.z;
        tank->rot.y = yaw;
        j = func_8010895C_1DD03C_ShellShocked(t);
        com->a.i = 9;
        if (j == 6) {
            func_8010B0B4_1DF794_ShellShocked(i, -k.x, k.z);
            com->a.i = j;
        } else if (j == 7) {
            func_8010B0B4_1DF794_ShellShocked(i, k.x, -k.z);
            com->a.i = j;
        } else {
            func_8010B08C_1DF76C_ShellShocked(i, k.z, k.x);
        }
    }
    func_800B3170_B3D70(&a, &tank->pos);
    a.x = tank->pos.x;
    a.z = tank->pos.z;
    b.x = HuMathSin(tank->rot.y);
    b.z = func_800B7890_B8490(tank->rot.y);
    c.x = b.x * 100.0f + a.x;
    c.z = b.z * 100.0f + a.z;
    switch (func_801072FC_1DB9DC_ShellShocked(i, t)) {
    case -1:
        break;
    case 0:
        func_8010B494_1DFB74_ShellShocked(i, 0);
        com->hits = 0;
        com->lastTarget = -1;
        func_80107C04_1DC2E4_ShellShocked(t);
        break;
    case 1:
        func_8010B494_1DFB74_ShellShocked(i, 1);
        if (com->lastTarget == t) {
            com->hits++;
        } else {
            com->hits = 0;
        }
        com->lastTarget = t;
        if (com->hits >= 4) {
            j = rand8() & 0x11;
            r = func_8010CAA4_1E1184_ShellShocked() * 20.0f + 20.0f;
            if (j != 0) {
                func_801080C0_1DC7A0_ShellShocked(i, t, 500.0f, 1000.0f, r);
                com->hits = 0;
                return;
            }
            func_80107FB4_1DC694_ShellShocked(i, t, r);
            com->hits = 0;
            return;
        }
        break;
    }
    d.x = D_8010DA80_1E2160_ShellShocked[t].pos.x - a.x;
    d.z = D_8010DA80_1E2160_ShellShocked[t].pos.z - a.z;
    if (func_800B1830_B2430(d.x * d.x + d.z * d.z) < com->b.f) {
        func_801080C0_1DC7A0_ShellShocked(i, t, 500.0f, 1000.0f, 0x28);
        return;
    }
    if (com->limit < ++com->timer) {
        func_80108100_1DC7E0_ShellShocked(i);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_ShellShocked/1D9870", func_801060D0_1DA7B0_ShellShocked);
#endif

// register allocation (masked 0): i and com swap s2/s3. Retail stores cmd.state (cmd is otherwise unused),
// nests the loop's three tests, and its switch dispatch has the lower-bound test that case -1 brings.
// S3-R tried: com declared before tank (no change).
#ifdef NON_MATCHING
void func_80106770_1DAE50_ShellShocked(s32 i) {
    SSCom cmd;
    Vec a;
    Vec b;
    Vec c;
    Vec d;
    Vec e;
    Vec f;
    Vec g;
    Vec h;
    Vec k;
    SSTank* tank;
    SSCom* com;
    s32 t;
    s32 j;
    s32 r;
    s32 time;
    f32 speed;
    f32 near;
    f32 l;
    f32 len;

    cmd.state = 0x11;
    tank = &D_8010DA80_1E2160_ShellShocked[i];
    com = func_80107714_1DBDF4_ShellShocked(i);
    speed = D_8010CB80_1E1260_ShellShocked[tank->level] * 70.0f;
    func_80103884_1D7F64_ShellShocked(2);
    func_800B3170_B3D70(&a, &tank->pos);
    near = tank->rot.y;
    b.x = HuMathSin(near);
    b.z = func_800B7890_B8490(near);
    c.x = b.x * 100.0f + a.x;
    c.z = b.z * 100.0f + a.z;
    t = com->target;
    if (t != -1 && func_8010C1F0_1E08D0_ShellShocked(t) == 0) {
        f.x = D_8010DA80_1E2160_ShellShocked[t].pos.x - a.x;
        f.z = D_8010DA80_1E2160_ShellShocked[t].pos.z - a.z;
        near = f.x * f.x + f.z * f.z;
        for (j = 0; j < 4; j++) {
            if (j != i) {
                if (j != t) {
                    if (func_8010C1F0_1E08D0_ShellShocked(j) == 0) {
                        d.x = D_8010DA80_1E2160_ShellShocked[j].pos.x;
                        d.z = D_8010DA80_1E2160_ShellShocked[j].pos.z;
                        e.x = d.x - a.x;
                        e.z = d.z - a.z;
                        if (e.x * f.x + e.z * f.z > 0.7f) {
                            len = e.x * e.x + e.z * e.z;
                            if (len < near) {
                                t = j;
                                near = len;
                            }
                        }
                    }
                }
            }
        }
        if (func_80103938_1D8018_ShellShocked() != 0) {
            if (func_8010CAA4_1E1184_ShellShocked() * 100.0f < 90.0f) {
                t = 0;
            }
        }
        d.x = D_8010DA80_1E2160_ShellShocked[t].pos.x;
        d.z = D_8010DA80_1E2160_ShellShocked[t].pos.z;
        e.x = d.x - a.x;
        e.z = d.z - a.z;
        g.x = e.x;
        g.z = e.z;
        l = 1.0f / func_800B1830_B2430(e.x * e.x + e.z * e.z);
        g.x = l * g.x;
        g.z = l * g.z;
        h.x = b.x;
        h.z = b.z;
        k.x = speed * (g.x * b.x + g.z * b.z);
        k.z = -speed * (g.x * b.z - g.z * b.x);
        len = func_800B1830_B2430(e.x * e.x + e.z * e.z);
        if (com->b.f < len) {
            func_80108034_1DC714_ShellShocked(i, t, 500.0f, 0x14);
            return;
        }
        if (len < com->a.f) {
            func_8010B0B4_1DF794_ShellShocked(i, -k.z, -k.x);
        } else {
            tank->rot.y = func_80107044_1DB724_ShellShocked(i, t);
        }
        func_800B3170_B3D70(&a, &tank->pos);
        a.x = tank->pos.x;
        a.z = tank->pos.z;
        b.x = HuMathSin(tank->rot.y);
        b.z = func_800B7890_B8490(tank->rot.y);
        c.x = b.x * 100.0f + a.x;
        c.z = b.z * 100.0f + a.z;
        switch (func_801072FC_1DB9DC_ShellShocked(i, t)) {
        case -1:
            break;
        case 0:
            func_8010B494_1DFB74_ShellShocked(i, 0);
            com->hits = 0;
            com->lastTarget = -1;
            if (func_8010CAA4_1E1184_ShellShocked() * 16.0f > 1.0f) {
                func_80107C04_1DC2E4_ShellShocked(t);
            }
            break;
        case 1:
            if (func_8010CAA4_1E1184_ShellShocked() * 16.0f == 0.0f) {
                func_80107C04_1DC2E4_ShellShocked(t);
            }
            func_8010B494_1DFB74_ShellShocked(i, 1);
            if (com->lastTarget == t) {
                com->hits++;
            } else {
                com->hits = 0;
            }
            com->lastTarget = t;
            if (com->hits >= 4) {
                r = rand8() & 0x11;
                time = func_8010CAA4_1E1184_ShellShocked() * 20.0f + 20.0f;
                if (r != 0) {
                    func_801080C0_1DC7A0_ShellShocked(i, t, 500.0f, 1000.0f, time);
                    com->hits = 0;
                    return;
                }
                func_80107FB4_1DC694_ShellShocked(i, t, time);
                com->hits = 0;
                return;
            }
            break;
        }
        if (com->limit < ++com->timer) {
            func_80108100_1DC7E0_ShellShocked(i);
        }
    } else {
        func_80108100_1DC7E0_ShellShocked(i);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_ShellShocked/1D9870", func_80106770_1DAE50_ShellShocked);
#endif

void func_80106D84_1DB464_ShellShocked(s32 i) {
    SSCom* com;

    com = func_80107714_1DBDF4_ShellShocked(i);
    func_80106E4C_1DB52C_ShellShocked(i);
    switch (com->state) {
    case 1:
        func_80105360_1D9A40_ShellShocked(i);
        break;
    case 15:
        func_80105428_1D9B08_ShellShocked(i);
        break;
    case 9:
        func_80105648_1D9D28_ShellShocked(i);
        break;
    case 10:
        func_80105758_1D9E38_ShellShocked(i);
        break;
    case 11:
        func_801060D0_1DA7B0_ShellShocked(i);
        break;
    case 12:
        func_80106770_1DAE50_ShellShocked(i);
        break;
    default:
        func_80105960_1DA040_ShellShocked(i);
        break;
    case 16:
        break;
    }
}

s32 func_80106E4C_1DB52C_ShellShocked(s32 i) {
    f32 cx;
    f32 cz;
    SSCom* com;
    s32 x;
    s32 z;
    s32 limit;
    f32 angle;
    f32 r;

    com = func_80107714_1DBDF4_ShellShocked(i);
    func_8010913C_1DD81C_ShellShocked(D_8010DA80_1E2160_ShellShocked[i].pos.x, D_8010DA80_1E2160_ShellShocked[i].pos.z, &cx, &cz);
    x = cx;
    z = cz;
    if (com->cellX == x && com->cellY == z) {
        com->stuck++;
    } else {
        com->cellX = x;
        com->cellY = z;
    }
    if ((f32)com->stuck > func_8010CAA4_1E1184_ShellShocked() * 120.0f + 180.0f) {
        angle = func_8010CAA4_1E1184_ShellShocked() * 360.0f;
        r = (func_8010CAA4_1E1184_ShellShocked() * 10.0f + 5.0f) * 10.0f;
        limit = func_8010CAA4_1E1184_ShellShocked() * 20.0f + 10.0f;
        cx = D_8010DA80_1E2160_ShellShocked[i].pos.x + r * HuMathSin(angle);
        cz = r * func_800B7890_B8490(angle) + D_8010DA80_1E2160_ShellShocked[i].pos.z;
        func_80107AB8_1DC198_ShellShocked(i, cx, cz, limit);
        com->stuck = 0;
    }
    if (com->state == 0) {
        com->state = 1;
    }
    return 0;
}

f32 func_80107044_1DB724_ShellShocked(s32 i, s32 target) {
    Vec a;
    Vec b;
    Vec c;
    SSTank* p;
    SSTank* q;
    f32 s;
    f32 co;
    f32 cross;
    f32 dot;
    f32 len;
    f32 yaw;
    f32 k;
    f32 f;
    f32 r;

    if (i == target) {
        return D_8010DA80_1E2160_ShellShocked[i].rot.y;
    }
    p = &D_8010DA80_1E2160_ShellShocked[i];
    q = &D_8010DA80_1E2160_ShellShocked[target];
    b.x = q->pos.x - p->pos.x;
    b.z = q->pos.z - p->pos.z;
    a.x = b.z;
    a.z = -b.x;
    s = HuMathSin(p->rot.y);
    co = func_800B7890_B8490(p->rot.y);
    cross = co * a.z + s * a.x;
    dot = co * b.z + s * b.x;
    len = a.x * a.x + a.z * a.z;
    yaw = p->rot.y;
    r = D_8010CC20_1E1300_ShellShocked[0][D_8010DA80_1E2160_ShellShocked[i].level];
    if (dot * dot < len * r * r) {
        k = D_8010CC20_1E1300_ShellShocked[1][D_8010DA80_1E2160_ShellShocked[i].level];
        if (cross < 0.0f) {
            yaw += k;
            if (yaw > 360.0f) {
                yaw -= 360.0f;
            }
        } else {
            yaw -= k;
            if (yaw < 0.0f) {
                yaw += 360.0f;
            }
        }
    } else {
        k = D_8010CC40_1E1320_ShellShocked[D_8010DA80_1E2160_ShellShocked[i].level];
        f = 1.0f - func_800B1830_B2430(dot * dot / len);
        if (cross < 0.0f) {
            yaw += k * f;
        } else {
            yaw += -k * f;
        }
    }
    c.x = HuMathSin(p->rot.y) * 100.0f + p->pos.x;
    c.z = func_800B7890_B8490(p->rot.y) * 100.0f + p->pos.z;
    if (func_8010C218_1E08F8_ShellShocked(i, &p->pos, yaw) != 0) {
        return p->rot.y;
    }
    return yaw;
}

// FPR allocation (masked 16, 274 = 274): retail keeps dot in f6 / cos in f8 and loads a.x, a.z before
// the dot product; the pillar loop's t sits in f12 there. S3-R tried: ABS(len) through t, t for x*x + z*z,
// storing c directly (273).
#ifdef NON_MATCHING
s32 func_801072FC_1DB9DC_ShellShocked(s32 i, s32 target) {
    Vec a;
    Vec b;
    Vec c;
    Vec d;
    Vec e;
    SSTank* p;
    SSTank* q;
    Vec* v;
    s32 j;
    s32 shot;
    s32 ok;
    f32 s;
    f32 co;
    f32 dot;
    f32 len;
    f32 k;
    f32 t;
    f32 x;
    f32 z;

    shot = -1;
    ok = 0;
    if (i == target) {
        return -1;
    }
    if (func_80103938_1D8018_ShellShocked() != 0 && target != 0) {
        return -1;
    }
    p = &D_8010DA80_1E2160_ShellShocked[i];
    q = &D_8010DA80_1E2160_ShellShocked[target];
    if (p->shell[0].active == 1) {
        return -1;
    }
    k = D_8010CBA0_1E1280_ShellShocked[D_8010DA80_1E2160_ShellShocked[i].level];
    if (func_8010CAA4_1E1184_ShellShocked() < k) {
        return -1;
    }
    b.x = q->pos.x - p->pos.x;
    b.z = q->pos.z - p->pos.z;
    a.x = b.z;
    a.z = -b.x;
    s = HuMathSin(p->rot.y);
    co = func_800B7890_B8490(p->rot.y);
    dot = co * b.z + s * b.x;
    len = a.x * a.x + a.z * a.z;
    if (dot < 0.3f) {
        return -1;
    }
    d.x = s;
    if (len * D_8010CC50_1E1330_ShellShocked[D_8010DA80_1E2160_ShellShocked[i].level] * D_8010CC50_1E1330_ShellShocked[D_8010DA80_1E2160_ShellShocked[i].level] < dot * dot) {
        shot = 0;
        ok = 1;
    }
    d.z = co;
    e.x = co;
    e.z = -s;
    for (j = 0; j < D_8010DFE0_1E26C0_ShellShocked->count; j++) {
        v = &D_8010DFE0_1E26C0_ShellShocked->pillars[j];
        c.z = v->z - p->pos.z;
        c.x = v->x - p->pos.x;
        t = func_800B1830_B2430(ABS(len)) + 100.0f;
        if (!(t * t < c.x * c.x + c.z * c.z)) {
            t = -(d.x * c.z - d.z * c.x);
            x = t * d.x;
            z = t * d.z;
            c.x = x;
            c.z = z;
            if (x * x + z * z < 9604.0f) {
                shot = -1;
            }
        }
    }
    if ((ok != 0) & (~shot == 0)) {
        k = D_8010CC60_1E1340_ShellShocked[D_8010DA80_1E2160_ShellShocked[i].level];
        t = b.x * b.x + b.z * b.z;
        t = func_800B1830_B2430(ABS(t));
        x = D_8010DFD0_1E26B0_ShellShocked * 0.95f;
        if (t - k <= x && x <= t + k) {
            shot = (rand8() & 3) != 0;
        }
    }
    return shot;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_ShellShocked/1D9870", func_801072FC_1DB9DC_ShellShocked);
#endif

SSCom* func_80107714_1DBDF4_ShellShocked(s32 i) {
    return &D_8010D740_1E1E20_ShellShocked[i];
}

void func_80107738_1DBE18_ShellShocked(s32 i, s32 force, SSCom* cmd) {
    if (force == 0) {
        switch (cmd->state) {
        case 2:
        case 8:
            D_8010D740_1E1E20_ShellShocked[i].state = cmd->state;
            break;
        case 15:
            D_8010D740_1E1E20_ShellShocked[i].state = 0xF;
            D_8010D740_1E1E20_ShellShocked[i].target = cmd->target;
            D_8010D740_1E1E20_ShellShocked[i].timer = cmd->timer;
            D_8010D740_1E1E20_ShellShocked[i].count = 0;
            break;
        case 9:
            if (D_8010D740_1E1E20_ShellShocked[i].state != 9 || D_8010D740_1E1E20_ShellShocked[i].timer >= 5) {
                D_8010D740_1E1E20_ShellShocked[i].state = 9;
                D_8010D740_1E1E20_ShellShocked[i].timer = 0;
                D_8010D740_1E1E20_ShellShocked[i].limit = cmd->limit;
                D_8010D740_1E1E20_ShellShocked[i].a.i = cmd->a.i;
                D_8010D740_1E1E20_ShellShocked[i].b.v.x = D_8010DA80_1E2160_ShellShocked[i].pos.x;
                D_8010D740_1E1E20_ShellShocked[i].b.v.z = D_8010DA80_1E2160_ShellShocked[i].pos.z;
                D_8010D740_1E1E20_ShellShocked[i].goal.x = cmd->goal.x;
                D_8010D740_1E1E20_ShellShocked[i].goal.z = cmd->goal.z;
            }
            break;
        case 10:
            D_8010D740_1E1E20_ShellShocked[i].state = 0xA;
            D_8010D740_1E1E20_ShellShocked[i].timer = 0;
            D_8010D740_1E1E20_ShellShocked[i].target = cmd->target;
            D_8010D740_1E1E20_ShellShocked[i].limit = cmd->limit;
            func_800B3170_B3D70(&D_8010D740_1E1E20_ShellShocked[i].b.v, &D_8010DA80_1E2160_ShellShocked[i].pos);
            break;
        case 11:
            D_8010D740_1E1E20_ShellShocked[i].state = 0xB;
            D_8010D740_1E1E20_ShellShocked[i].timer = 0;
            D_8010D740_1E1E20_ShellShocked[i].target = cmd->target;
            D_8010D740_1E1E20_ShellShocked[i].limit = cmd->limit;
            D_8010D740_1E1E20_ShellShocked[i].b.f = cmd->b.f;
            break;
        case 12:
            D_8010D740_1E1E20_ShellShocked[i].state = 0xC;
            D_8010D740_1E1E20_ShellShocked[i].timer = 0;
            D_8010D740_1E1E20_ShellShocked[i].target = cmd->target;
            D_8010D740_1E1E20_ShellShocked[i].a.f = cmd->a.f;
            D_8010D740_1E1E20_ShellShocked[i].b.f = cmd->b.f;
            D_8010D740_1E1E20_ShellShocked[i].limit = cmd->limit;
            break;
        }
    }
    D_8010D740_1E1E20_ShellShocked[i].player = D_8010DFD8_1E26B8_ShellShocked;
}

void func_80107A90_1DC170_ShellShocked(s32 i) {
    SSCom cmd;

    cmd.state = 8;
    func_80107738_1DBE18_ShellShocked(i, 0, &cmd);
}

void func_80107AB8_1DC198_ShellShocked(s32 i, f32 x, f32 z, s32 limit) {
    SSCom cmd;

    cmd.state = 9;
    cmd.timer = 0;
    cmd.a.i = 1;
    cmd.target = -1;
    cmd.limit = limit;
    func_800B3170_B3D70(&cmd.b.v, &D_8010DA80_1E2160_ShellShocked[i].pos);
    HuVecCopyXYZ(&cmd.goal, x, 0.0f, z);
    func_80107738_1DBE18_ShellShocked(i, 0, &cmd);
}

void func_80107B60_1DC240_ShellShocked(s32 i, f32 x, f32 z, s32 limit) {
    SSCom cmd;

    cmd.state = 9;
    cmd.timer = 0;
    cmd.a.i = 0;
    cmd.target = -1;
    cmd.limit = limit;
    func_800B3170_B3D70(&cmd.b.v, &D_8010DA80_1E2160_ShellShocked[i].pos);
    HuVecCopyXYZ(&cmd.goal, x, 0.0f, z);
    func_80107738_1DBE18_ShellShocked(i, 0, &cmd);
}

void func_80107C04_1DC2E4_ShellShocked(s32 i) {
    SSCom cmd;
    Vec a;
    Vec b;
    Vec c;
    Vec d;
    s32 t;
    s32 limit;
    s32 r;
    f32 k;

    if (D_8010DFD8_1E26B8_ShellShocked == D_8010D740_1E1E20_ShellShocked[i].player && func_8010CAA4_1E1184_ShellShocked() * 100.0f > 95.0f) {
        return;
    }
    if (func_80103938_1D8018_ShellShocked() != 0 && func_8010CAA4_1E1184_ShellShocked() * 100.0f > 97.0f) {
        return;
    }
    t = D_8010DFD8_1E26B8_ShellShocked;
    if (func_80108E68_1DD548_ShellShocked(i, t, 5.0f, 1) == 9 && func_8010CAA4_1E1184_ShellShocked() * 100.0f > 95.0f) {
        func_801080C0_1DC7A0_ShellShocked(i, t, 500.0f, 1000.0f, func_8010CAA4_1E1184_ShellShocked() * 20.0f + 10.0f);
        return;
    }
    cmd.state = 9;
    cmd.timer = 0;
    cmd.a.i = 1;
    cmd.target = -1;
    cmd.limit = 0x28;
    func_800B3170_B3D70(&a, &D_8010DA80_1E2160_ShellShocked[i].pos);
    func_800B3170_B3D70(&b, &D_8010DA80_1E2160_ShellShocked[D_8010DFD8_1E26B8_ShellShocked].pos);
    HuVecSubtract(&c, &b, &a);
    d.x = c.z;
    d.z = -c.x;
    k = 1000.0f / func_800B1830_B2430(c.z * c.z + d.z * d.z);
    limit = func_8010CAA4_1E1184_ShellShocked() * 25.0f + 25.0f;
    r = func_8010895C_1DD03C_ShellShocked(i);
    switch (r) {
        case 7:
            func_80107B60_1DC240_ShellShocked(i, k * d.x, k * d.z, limit);
            break;
        case 6:
            func_80107B60_1DC240_ShellShocked(i, -d.x * k, -d.z * k, limit);
            break;
        default:
            func_80107B60_1DC240_ShellShocked(i, -c.x * k, -c.z * k, limit);
            break;
    }
}

void func_80107EF8_1DC5D8_ShellShocked(s32 i, s32 target, s32 time) {
    SSCom cmd;
    s32 level;

    cmd.state = 0xF;
    cmd.target = target;
    level = D_8010DA80_1E2160_ShellShocked[target].level;
    if (time <= 0) {
        cmd.timer = func_8010CAA4_1E1184_ShellShocked() * 30.0f * D_8010CB90_1E1270_ShellShocked[level] + 20.0f;
        cmd.a.i = 0;
    } else {
        cmd.timer = time;
        cmd.a.i = 0;
    }
    func_80107738_1DBE18_ShellShocked(i, 0, &cmd);
}

void func_80107FB4_1DC694_ShellShocked(s32 i, s32 target, s32 time) {
    SSCom cmd;

    cmd.state = 0xA;
    cmd.target = target;
    cmd.timer = time;
    if (time <= 0) {
        cmd.limit = func_8010CAA4_1E1184_ShellShocked() * 30.0f + 20.0f;
    } else {
        cmd.limit = time;
    }
    func_80107738_1DBE18_ShellShocked(i, 0, &cmd);
}

void func_80108034_1DC714_ShellShocked(s32 i, s32 target, f32 dist, s32 time) {
    SSCom cmd;

    cmd.state = 0xB;
    cmd.target = target;
    cmd.a.i = 9;
    cmd.b.f = dist;
    cmd.timer = 0;
    if (time <= 0) {
        cmd.limit = func_8010CAA4_1E1184_ShellShocked() * 30.0f + 20.0f;
    } else {
        cmd.limit = time;
    }
    func_80107738_1DBE18_ShellShocked(i, 0, &cmd);
}

void func_801080C0_1DC7A0_ShellShocked(s32 i, s32 target, f32 a, f32 b, s32 limit) {
    SSCom cmd;

    cmd.state = 0xC;
    cmd.timer = 0;
    cmd.target = target;
    cmd.a.f = a;
    cmd.b.f = b;
    cmd.limit = limit;
    func_80107738_1DBE18_ShellShocked(i, 0, &cmd);
}

void func_80108100_1DC7E0_ShellShocked(s32 i) {
    SSCom cmd;
    s32 t;

    t = func_80108714_1DCDF4_ShellShocked(i);
    if (t == -1) {
        cmd.state = 0x10;
        func_80107738_1DBE18_ShellShocked(i, 0, &cmd);
        return;
    }
    func_80108034_1DC714_ShellShocked(i, t, 500.0f, func_8010CAA4_1E1184_ShellShocked() * 80.0f + 80.0f);
}

void func_80108190_1DC870_ShellShocked(s32 i) {
    Vec v;
    s32 j;

    if (func_80103938_1D8018_ShellShocked() != 0 && func_8010CAA4_1E1184_ShellShocked() * 100.0f > 95.0f) {
        return;
    }
    for (j = 0; j < 4; j++) {
        if (j != i && func_8010C1F0_1E08D0_ShellShocked(j) == 0) {
            HuVecSubtract(&v, &D_8010DA80_1E2160_ShellShocked[j].pos, &D_8010DA80_1E2160_ShellShocked[i].pos);
            if (v.x * v.x + v.z * v.z < 122500.0f) {
                func_80107A90_1DC170_ShellShocked(j);
                return;
            }
        }
    }
    if ((u32)(D_8010DA80_1E2160_ShellShocked[i].shell[0].state - 1) < 2) {
        for (j = 0; j < 4; j++) {
            if (j != i && func_8010C1F0_1E08D0_ShellShocked(j) == 0 && func_80108E68_1DD548_ShellShocked(i, j, 5.0f, 1) == 9) {
                if (func_8010C100_1E07E0_ShellShocked(i) == 1) {
                    if (func_8010C100_1E07E0_ShellShocked(j) >= 2) {
                        if (func_8010CAA4_1E1184_ShellShocked() * 100.0f > 10.0f) {
                            continue;
                        }
                    } else {
                        if (func_8010CAA4_1E1184_ShellShocked() * 100.0f > 20.0f) {
                            continue;
                        }
                    }
                }
                func_80107C04_1DC2E4_ShellShocked(j);
            }
        }
    }
}

s32 func_801083C4_1DCAA4_ShellShocked(s32 i, s32 x, s32 z) {
    Vec a;
    Vec b;
    Vec c;
    Vec d;
    Vec e;
    SSTank* tank;
    f32 speed;
    f32 l;

    tank = &D_8010DA80_1E2160_ShellShocked[i];
    speed = D_8010CB80_1E1260_ShellShocked[tank->level] * 70.0f;
    func_800B3170_B3D70(&a, &tank->pos);
    HuVecCopyXYZ(&b, x, 0.0f, z);
    c.x = b.x - a.x;
    c.z = b.z - a.z;
    l = 1.0f / func_800B1830_B2430(c.x * c.x + c.z * c.z);
    d.x = l * c.x;
    d.z = l * c.z;
    e.x = HuMathSin(tank->rot.y);
    e.z = func_800B7890_B8490(tank->rot.y);
    c.x = speed * (d.x * e.x + d.z * e.z);
    c.z = -speed * (d.x * e.z - d.z * e.x);
    return func_8010B08C_1DF76C_ShellShocked(i, c.z, c.x);
}

s32 func_8010856C_1DCC4C_ShellShocked(s32 i, s32 x, s32 z) {
    Vec a;
    Vec b;
    Vec c;
    Vec d;
    Vec e;
    SSTank* tank;
    f32 speed;
    f32 l;

    tank = &D_8010DA80_1E2160_ShellShocked[i];
    speed = D_8010CB80_1E1260_ShellShocked[tank->level] * 70.0f;
    func_800B3170_B3D70(&a, &tank->pos);
    HuVecCopyXYZ(&b, x, 0.0f, z);
    c.x = b.x - a.x;
    c.z = b.z - a.z;
    l = 1.0f / func_800B1830_B2430(c.x * c.x + c.z * c.z);
    d.x = l * c.x;
    d.z = l * c.z;
    e.x = HuMathSin(tank->rot.y);
    e.z = func_800B7890_B8490(tank->rot.y);
    c.x = speed * (d.x * e.x + d.z * e.z);
    c.z = -speed * (d.x * e.z - d.z * e.x);
    return func_8010B0B4_1DF794_ShellShocked(i, c.z, c.x);
}

s32 func_80108714_1DCDF4_ShellShocked(s32 i) {
    s32 j;
    s32 n;
    s32 r;

    for (j = 0, n = 0; j < 4; j++) {
        if (i != j) {
            n += func_8010C1F0_1E08D0_ShellShocked(j) == 0;
        }
    }
    r = (f32)n * func_8010CAA4_1E1184_ShellShocked();
    for (j = 0, n = 0; j < 4; j++) {
        if (i != j && func_8010C1F0_1E08D0_ShellShocked(j) == 0) {
            if (n == r) {
                break;
            }
            n++;
        }
    }
    if (func_80103938_1D8018_ShellShocked() != 0) {
        return 0;
    }
    return j == 4 ? -1 : j;
}

/* Retail: the comparison starts from FLT_MAX and looks for a larger distance, so *who stays -1
   unless the boss rule sets it. */
f32 func_801087F8_1DCED8_ShellShocked(s32 i, s32* who) {
    Vec d;
    SSTank* tank;
    SSTank* p;
    s32 j;
    f32 best;
    f32 x;

    tank = &D_8010DA80_1E2160_ShellShocked[i];
    *who = -1;
    best = 3.4028235e38f;
    for (j = 0; j < 4; j++) {
        if (j != i && func_8010C1F0_1E08D0_ShellShocked(j) == 0) {
            p = &D_8010DA80_1E2160_ShellShocked[j];
            d.x = p->pos.x - tank->pos.x;
            d.z = p->pos.z - tank->pos.z;
            x = d.x * d.x + d.z * d.z;
            if (best < x) {
                best = x;
                *who = j;
            }
        }
    }
    if (func_80103938_1D8018_ShellShocked() != 0) {
        *who = 0;
        d.x = D_8010DA80_1E2160_ShellShocked->pos.x - tank->pos.x;
        d.z = D_8010DA80_1E2160_ShellShocked->pos.z - tank->pos.z;
        best = d.x * d.x + d.z * d.z;
    }
    return best;
}

/* l first holds each side test's cross product, then the inverse length. */
s32 func_8010895C_1DD03C_ShellShocked(s32 i) {
    Vec a;
    Vec b;
    Vec c;
    Vec* pos;
    Vec* v;
    s32 j;
    s32 n;
    f32 left;
    f32 right;
    f32 d;
    f32 l;

    pos = &D_8010DA80_1E2160_ShellShocked[i].pos;
    a.x = D_8010DA80_1E2160_ShellShocked[D_8010DFD8_1E26B8_ShellShocked].pos.x - pos->x;
    a.z = -(D_8010DA80_1E2160_ShellShocked[D_8010DFD8_1E26B8_ShellShocked].pos.z - pos->z);
    n = D_8010DFE0_1E26C0_ShellShocked->count;
    right = 3.4028235e38f;
    left = 3.4028235e38f;
    for (j = 0; j < n; j++) {
        v = &D_8010DFE0_1E26C0_ShellShocked->pillars[j];
        b.x = v->x - pos->x;
        b.z = v->z - pos->z;
        d = func_800B1830_B2430(b.x * b.x + b.z * b.z);
        l = b.x * a.z + b.z * a.x;
        if (l < 0.0f) {
            if (d < left) {
                left = d;
            }
        } else {
            if (d < right) {
                right = d;
            }
        }
    }
    if (func_80103938_1D8018_ShellShocked() == 0) {
        for (j = 0; j < 4; j++) {
            if (j != i && func_8010C1F0_1E08D0_ShellShocked(j) == 0) {
                HuVecSubtract(&b, &D_8010DA80_1E2160_ShellShocked[j].pos, pos);
                d = func_800B1830_B2430(b.x * b.x + b.z * b.z);
                l = b.x * a.z + b.z * a.x;
                if (l < 0.0f) {
                    if (d < left) {
                        left = d;
                    }
                } else {
                    if (d < right) {
                        right = d;
                    }
                }
            }
        }
    } else if (j != 0 && func_8010C1F0_1E08D0_ShellShocked(0) == 0) {
        HuVecSubtract(&b, &D_8010DA80_1E2160_ShellShocked[0].pos, pos);
        d = func_800B1830_B2430(b.x * b.x + b.z * b.z);
        l = b.x * a.z + b.z * a.x;
        if (l < 0.0f) {
            if (d < left) {
                left = d;
            }
        } else if (d < right) {
            right = d;
        }
    }
    l = 1.0f / func_800B1830_B2430(a.x * a.x + a.z * a.z);
    if (left < right) {
        c.x = left * a.x * l + pos->x;
        c.z = left * a.z * l + pos->z;
        if (c.x < -760.0f || c.x > 760.0f || c.z < -760.0f || c.z > 760.0f) {
            right = left * 0.5f;
        }
    } else {
        c.x = -left * a.x * l + pos->x;
        c.z = -left * a.z * l + pos->z;
        if (c.x < -760.0f || c.x > 760.0f || c.z < -760.0f || c.z > 760.0f) {
            left = right * 0.5f;
        }
    }
    d = left;
    if (left < right) {
        d = right;
    }
    if (d < 100.0f) {
        return 0xA;
    }
    return right < left ? 6 : 7;
}

s32 func_80108E68_1DD548_ShellShocked(s32 i, s32 target, f32 angle, s32 pillars) {
    Vec a;
    Vec b;
    Vec d;
    Vec e;
    Vec f;
    Vec g;
    Vec c;
    s32 j;
    f32 k;
    f32 dot;
    f32 len;

    k = func_800B7890_B8490(angle);
    func_800B3170_B3D70(&a, &D_8010DA80_1E2160_ShellShocked[i].pos);
    func_800B3170_B3D70(&b, &D_8010DA80_1E2160_ShellShocked[target].pos);
    HuVecSubtract(&f, &b, &a);
    e.x = HuMathSin(D_8010DA80_1E2160_ShellShocked[i].rot.y);
    e.z = func_800B7890_B8490(D_8010DA80_1E2160_ShellShocked[i].rot.y);
    dot = e.x * f.x + e.z * f.z;
    if (dot < 0.0f) {
        return 0xA;
    }
    if (dot * dot < (f.x * f.x + f.z * f.z) * k * k) {
        dot = e.z * f.x - e.x * f.z;
        if (dot > 0.0f) {
            return 7;
        }
        return 6;
    }
    if (pillars != 0) {
        len = f.x * f.x + f.z * f.z;
        c.x = e.z;
        c.z = -e.x;
        for (j = 0; j < D_8010DFE0_1E26C0_ShellShocked->count; j++) {
            d.x = D_8010DFE0_1E26C0_ShellShocked->pillars[j].x;
            d.z = D_8010DFE0_1E26C0_ShellShocked->pillars[j].z;
            g.x = d.x - a.x;
            g.z = d.z - a.z;
            if (g.x * e.x + g.z * e.z <= 0.0f) {
                continue;
            }
            dot = g.x * g.x + g.z * g.z;
            if (len < dot) {
                continue;
            }
            dot = g.x * c.x + g.z * c.z;
            if (dot * dot < 10000.0f) {
                return 0xB;
            }
        }
    }
    return 9;
}

s32 func_8010913C_1DD81C_ShellShocked(f32 x, f32 z, f32* cx, f32* cz) {
    f32 t;
    s32 r;

    *cx = (x + 800.0f) * 0.0125f;
    t = (z + 800.0f) * 0.0125f;
    *cz = t;
    r = 1;
    if (*cx >= 0.0f) {
        if (*cx < 20.0f) {
            if (t >= 0.0f) {
                if (t < 20.0f) {
                    r = 0;
                }
            }
        }
    }
    return r;
}

__asm__(".section .rodata\n\t.balign 16\n\t.text");
