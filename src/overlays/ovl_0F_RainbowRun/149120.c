#include "common.h"
#include "ovl_0F.h"

/* A bomb that reaches a follower stuns it (D_8010AC14 entries other than `obj`; MP1
   func_800FBCD0_TightropeTreachery). */
s8 func_80107790_149120_RainbowRun(omObjData* obj) {
    s8 hit = 0;
    s8 i;

    for (i = 0; i < 3; i++) {
        omObjData* o = D_8010AC14_14C5A4_RainbowRun[i];
        f32 dx;
        f32 dy;
        f32 dz;

        if (o == obj) {
            continue;
        }
        if (o == NULL) {
            continue;
        }
        dx = obj->trans.x - o->trans.x;
        dy = obj->trans.y - o->trans.y;
        dz = obj->trans.z - o->trans.z;
        if (dx * dx + dy * dy + dz * dz < 12100.0f) {
            RRTeamWork* t = RR_WORK(o)->team;

            t->flash = 50;
            omVibrate(t->player, 30, 0, 30);
            hit = 1;
            break;
        }
    }
    return hit;
}

/* Bombs, model caches and the followers' paths (MP1 func_800FBDB8_TightropeTreachery). */
void func_80107878_149208_RainbowRun(void) {
    s16 i;
    u32 r;
    s16 a;
    s16 b;
    u8 tmp;

    for (i = 0; i < 3; i++) {
        D_8010AC20_14C5B0_RainbowRun[i].active = 0;
    }
    for (i = 0; i < 8; i++) {
        D_8010A9F0_14C380_RainbowRun[i] = -1;
    }
    for (i = 0; i < 3; i++) {
        D_8010AA00_14C390_RainbowRun[i] = -1;
    }
    func_80106020_1479B0_RainbowRun();
    func_80106020_1479B0_RainbowRun();
    for (i = 0; i < 3; i++) {
        D_8010AC08_14C598_RainbowRun[i] = i;
    }
    /* shuffles the paths */
    for (i = 0; i < 10; i++) {
        r = func_80106020_1479B0_RainbowRun();
        b = r % 3;
        a = (r >> 16) % 3;
        tmp = D_8010AC08_14C598_RainbowRun[a];
        D_8010AC08_14C598_RainbowRun[a] = D_8010AC08_14C598_RainbowRun[b];
        D_8010AC08_14C598_RainbowRun[b] = tmp;
    }
    if (func_80106020_1479B0_RainbowRun() & 1) {
        D_8010ABF0_14C580_RainbowRun = 0;
    } else {
        D_8010ABF0_14C580_RainbowRun = 3;
    }
}

/* A bomb is thrown: it flies from its follower along its facing (MP1
   func_800FBF38_TightropeTreachery). */
void func_80107A68_1493F8_RainbowRun(omObjData* obj) {
    RRBomb* b = ((RRItemWork*)obj->unk_50)->bomb;
    omObjData* thrower = D_8010AC14_14C5A4_RainbowRun[b->idx];
    s16 i;
    f32 dx;
    f32 dz;

    for (i = 0; i < 3; i++) {
        if (obj != NULL) {
            func_800298A4_2A4A4(obj->model[i], 4, 0);
            func_800298A4_2A4A4(obj->model[1], 4, 4);
        }
    }
    b->vy = 0.0f;
    b->timer = 0;
    b->ang = thrower->rot.y;
    b->dir[0] = HuMathSin(b->ang);
    b->dir[1] = 0.0f;
    b->dir[2] = func_800B7890_B8490(b->ang);
    b->pos[0] = thrower->trans.x;
    b->pos[1] = thrower->trans.y;
    b->pos[2] = thrower->trans.z;
    b->pos[0] = b->dir[0] * 50.0f + b->pos[0];
    b->pos[1] = b->pos[1] + 80.0f;
    b->pos[2] = b->dir[2] * 50.0f + b->pos[2];
    obj->trans.x = b->pos[0];
    obj->trans.y = b->pos[1];
    obj->trans.z = b->pos[2];
    dx = b->pos[0] - D_800FFFD8_100BD8[0]->trans.x;
    dz = b->pos[2] - D_800FFFD8_100BD8[0]->trans.z;
    b->speed = sqrtf(dx * dx + dz * dz) / 16.0f;
    func_80021198_21D98(b->mdl[0], 0);
    func_800298A4_2A4A4(obj->model[3], 4, 0);
    func_80029714_2A314(obj->model[3], obj->trans.x, obj->trans.y, obj->trans.z);
    b->lit = 1;
}

/* A thrown bomb's flight: falls off the course, or explodes on the rainbow or a follower (MP1
   func_800FC180_TightropeTreachery). */
// the rope-hit flag: retail copies it to v0/v1 before each compare (2 instructions; MP1's twin is NON_MATCHING the same way)
#ifdef NON_MATCHING
void func_80107C5C_1495EC_RainbowRun(omObjData* obj) {
    RRPlayerWork* w = D_800FFFD8_100BD8[0]->unk_50;
    RRBomb* b = ((RRItemWork*)obj->unk_50)->bomb;
    s16 i;
    s32 rope;
    f32 rx;

    if (b != NULL) {
        for (i = 0; i < 3; i++) {
            b->pos[i] = b->dir[i] * b->speed + b->pos[i];
        }
    }
    b->pos[1] = b->vy + 108.0f + b->pos[1];
    obj->trans.x = b->pos[0];
    obj->trans.y = b->pos[1];
    obj->trans.z = b->pos[2];
    b->vy = b->vy - 10.0f;
    for (i = 0; i < 3; i++) {
        func_80029714_2A314(obj->model[i], b->pos[0], b->pos[1], b->pos[2]);
    }
    rope = 0;
    if (obj->trans.y < -650.0f) {
        func_80079798_7A398(0x18B, b->sound);
        PlaySound(0x18D);
        b->active = 0;
        b->lit = 0;
        b->timer = 0;
        for (i = 0; i < 6; i++) {
            func_800298A4_2A4A4(obj->model[i], 4, 4);
        }
        func_80021198_21D98(b->mdl[2], 0);
        func_800298A4_2A4A4(obj->model[5], 4, 0);
        rope = 0;
        func_80029714_2A314(obj->model[5], obj->trans.x, obj->trans.y, obj->trans.z);
        obj->trans.x = obj->trans.y = obj->trans.z = 1000.0f;
    }
    rx = D_8010ABFC_14C58C_RainbowRun[0] * 70.0f * func_800B7890_B8490((obj->trans.z - -1100.0f + 2500.0f) * 90.0 / 5000.0) +
         D_8010AC0C_14C59C_RainbowRun;
    if (obj->trans.x < rx + 75.0f && rx + -75.0f < obj->trans.x) {
        if (obj->trans.y < -30.0f) {
            if (obj->trans.y > -125.0) {
                rope = 1;
            }
        }
    }
    if (rope == 1 || func_80107790_149120_RainbowRun(obj) == 1) {
        func_80079798_7A398(0x18B, b->sound);
        PlaySound(0x18D);
        b->active = 0;
        b->lit = 0;
        b->timer = 0;
        for (i = 0; i < 6; i++) {
            func_800298A4_2A4A4(obj->model[i], 4, 4);
        }
        func_80021198_21D98(b->mdl[2], 0);
        func_800298A4_2A4A4(obj->model[5], 4, 0);
        func_80029714_2A314(obj->model[5], obj->trans.x, obj->trans.y, obj->trans.z);
        if (rope == 1) {
            if (D_8010A701_14C091_RainbowRun == 0) {
                omVibrate(w->player, 2, 2, 20);
            }
            D_8010A751_14C0E1_RainbowRun = 1;
            D_8010A752_14C0E2_RainbowRun = 0;
        }
        obj->trans.x = obj->trans.y = obj->trans.z = 1000.0f;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0F_RainbowRun/149120", func_80107C5C_1495EC_RainbowRun);
#endif

/* A bomb object's update: waits 15 frames after a throw, then flies when its follower throws
   (MP1 func_800FC598_TightropeTreachery). */
void func_80108094_149A24_RainbowRun(omObjData* obj) {
    RRBomb* b = ((RRItemWork*)obj->unk_50)->bomb;
    s32 idx = b->idx;

    if (b->active == 1) {
        if (b->lit == 0) {
            if (b->timer >= 15) {
                D_8010A898_14C228_RainbowRun[idx] = 0;
                func_80107A68_1493F8_RainbowRun(obj);
                return;
            }
        } else {
            if (D_8010A898_14C228_RainbowRun[b->idx] == 0) {
                func_80079798_7A398(0x18A, b->sound);
                D_8010A898_14C228_RainbowRun[b->idx] = 1;
            }
            func_80107C5C_1495EC_RainbowRun(obj);
        }
        b->timer++;
    }
}

/* A bomb object: the bomb, its shadow and three 3D sprites (fuse, splash, explosion; MP1
   func_800FC65C_TightropeTreachery). `idx` is the follower, `sound` the fuse sound's owner. */
void func_8010815C_149AEC_RainbowRun(omObjData* obj, s16 idx, s16 sound) {
    RRItemWork* w;
    void* data;
    u16 ids[3];
    u16 id;
    s16 i;

    obj->unk_50 = func_80027154_27D54(sizeof(RRItemWork), 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, sizeof(RRItemWork));
    w = obj->unk_50;
    if (D_8010A9F0_14C380_RainbowRun[0] < 0) {
        obj->model[0] = func_80018A30_19630(0x1F0006, 0x2B9);
        D_8010A9F0_14C380_RainbowRun[0] = obj->model[0];
        obj->model[1] = func_80018A64_19664(1, 0x6B9);
        D_8010A9F0_14C380_RainbowRun[1] = obj->model[1];
        func_800298A4_2A4A4(obj->model[1], 4, 4);
    } else {
        obj->model[0] = func_80027D3C_2893C(D_8010A9F0_14C380_RainbowRun[0]);
        obj->model[1] = func_80027D3C_2893C(D_8010A9F0_14C380_RainbowRun[1]);
    }
    HmfModelObjAttrSet(obj->model[0], 0x70000000, 0x70000000);
    func_8000C2A0_CEA0(obj, 2, 0x10, 0x289, 8);
    if (D_8010A9F0_14C380_RainbowRun[2] < 0) {
        data = DataRead(0x11);
        id = func_80020EBC_21ABC(data, 0x1EB9, 8);
        HuMemMemoryFreePerm(data);
        obj->model[3] = D_800F86D8_F92D8[id].unk00;
        ids[0] = id;
        D_8010A9F0_14C380_RainbowRun[2] = id;
    } else {
        id = func_80020EBC_21ABC((void*)-1, 0x1EB9, 8);
        D_800F86D8_F92D8[id].unk02 = D_800F86D8_F92D8[D_8010A9F0_14C380_RainbowRun[2]].unk02;
        obj->model[3] = D_800F86D8_F92D8[id].unk00;
        ids[0] = id;
    }
    HmfModelObjAttrSet(obj->model[3], 0x70000000, 0x70000000);
    func_80021160_21D60(ids[0], 4, 4);
    func_800297E8_2A3E8(obj->model[3], 3.5f, 3.5f, 3.5f);
    func_800298A4_2A4A4(obj->model[3], 4, 4);
    if (D_8010A9F0_14C380_RainbowRun[3] < 0) {
        data = DataRead(0x10);
        id = func_80020EBC_21ABC(data, 0x1EB9, 8);
        HuMemMemoryFreePerm(data);
        func_800211E8_21DE8(id, 0x96);
        obj->model[4] = D_800F86D8_F92D8[id].unk00;
        ids[1] = id;
        D_8010A9F0_14C380_RainbowRun[3] = id;
    } else {
        id = func_80020EBC_21ABC((void*)-1, 0x1EB9, 8);
        func_800211E8_21DE8(id, 0x96);
        D_800F86D8_F92D8[id].unk02 = D_800F86D8_F92D8[D_8010A9F0_14C380_RainbowRun[3]].unk02;
        obj->model[4] = D_800F86D8_F92D8[id].unk00;
        ids[1] = id;
    }
    HmfModelObjAttrSet(obj->model[4], 0x70000000, 0x70000000);
    func_80021160_21D60(ids[1], 4, 4);
    func_800297E8_2A3E8(obj->model[4], 11.0f, 11.0f, 11.0f);
    func_800298A4_2A4A4(obj->model[4], 4, 4);
    if (D_8010A9F0_14C380_RainbowRun[4] < 0) {
        data = DataRead(0x11);
        id = func_80020EBC_21ABC(data, 0x1EB9, 8);
        HuMemMemoryFreePerm(data);
        obj->model[5] = D_800F86D8_F92D8[id].unk00;
        ids[2] = id;
        D_8010A9F0_14C380_RainbowRun[4] = id;
    } else {
        id = func_80020EBC_21ABC((void*)-1, 0x1EB9, 8);
        D_800F86D8_F92D8[id].unk02 = D_800F86D8_F92D8[D_8010A9F0_14C380_RainbowRun[4]].unk02;
        obj->model[5] = D_800F86D8_F92D8[id].unk00;
        ids[2] = id;
    }
    HmfModelObjAttrSet(obj->model[5], 0x70000000, 0x70000000);
    func_80021160_21D60(ids[2], 4, 4);
    func_800297E8_2A3E8(obj->model[5], 5.0f, 5.0f, 5.0f);
    func_800298A4_2A4A4(obj->model[5], 4, 4);
    for (i = 0; i < 6; i++) {
        func_800298A4_2A4A4(obj->model[i], 4, 4);
        obj->trans.x = obj->trans.y = obj->trans.z = 1000.0f;
    }
    w->unk_44 = 0.1f;
    w->unk_48 = 18.0f;
    w->unk_34 = 50.0f;
    w->unk_3C = 0;
    w->unk_52 = 7;
    w->unk_78 = 0;
    w->unk_7C = 0;
    w->unk_54 = 1;
    D_8010AC20_14C5B0_RainbowRun[idx].active = 0;
    D_8010AC20_14C5B0_RainbowRun[idx].idx = idx;
    D_8010AC20_14C5B0_RainbowRun[idx].sound = sound;
    D_8010AC20_14C5B0_RainbowRun[idx].lit = 0;
    D_8010AC20_14C5B0_RainbowRun[idx].timer = 0;
    for (i = 0; i < 3; i++) {
        D_8010AC20_14C5B0_RainbowRun[idx].mdl[i] = ids[i];
    }
    w->bomb = &D_8010AC20_14C5B0_RainbowRun[idx];
    obj->func_ptr = func_80108094_149A24_RainbowRun;
}

void func_801087A8_14A138_RainbowRun(omObjData* obj) {
    func_8010815C_149AEC_RainbowRun(obj, 0, D_8010ACC0_14C650_RainbowRun[1]);
}

void func_801087CC_14A15C_RainbowRun(omObjData* obj) {
    func_8010815C_149AEC_RainbowRun(obj, 1, D_8010ACC0_14C650_RainbowRun[2]);
}

void func_801087F0_14A180_RainbowRun(omObjData* obj) {
    func_8010815C_149AEC_RainbowRun(obj, 2, D_8010ACC0_14C650_RainbowRun[3]);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0F_RainbowRun/149120", func_80108814_14A1A4_RainbowRun);

/* A point on follower path `path` (D_8010A89C's four points, a closed spline): segment `seg`,
   `t` 0..240 into it. */
Vec func_80109240_14ABD0_RainbowRun(s8 path, s16 seg, f32 t) {
    s16 idx[4];
    Vec v;
    s8 i;

    idx[0] = (seg - 1 >= 0) ? seg - 1 : seg + 3;
    idx[1] = seg;
    idx[2] = (seg + 1 < 4) ? seg + 1 : seg - 3;
    idx[3] = (seg + 2 < 4) ? seg + 2 : seg - 2;
    D_8010A9E0_14C370_RainbowRun[0] = 0.0f;
    D_8010A9E0_14C370_RainbowRun[1] = 240.0f;
    D_8010A9E0_14C370_RainbowRun[2] = 480.0f;
    D_8010A9E0_14C370_RainbowRun[3] = 720.0f;
    for (i = 0; i < 4; i++) {
        D_8010A9D0_14C360_RainbowRun[i] = D_8010A830_14C1C0_RainbowRun[D_8010A89C_14C22C_RainbowRun[path][idx[i]]].x;
    }
    v.x = func_8002662C_2722C(D_8010A9D0_14C360_RainbowRun, D_8010A9E0_14C370_RainbowRun, t + 240.0f);
    for (i = 0; i < 4; i++) {
        D_8010A9D0_14C360_RainbowRun[i] = D_8010A830_14C1C0_RainbowRun[D_8010A89C_14C22C_RainbowRun[path][idx[i]]].y;
    }
    v.y = func_8002662C_2722C(D_8010A9D0_14C360_RainbowRun, D_8010A9E0_14C370_RainbowRun, t + 240.0f);
    for (i = 0; i < 4; i++) {
        D_8010A9D0_14C360_RainbowRun[i] = D_8010A830_14C1C0_RainbowRun[D_8010A89C_14C22C_RainbowRun[path][idx[i]]].z;
    }
    v.z = func_8002662C_2722C(D_8010A9D0_14C360_RainbowRun, D_8010A9E0_14C370_RainbowRun, t + 240.0f);
    return v;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0F_RainbowRun/149120", func_80109534_14AEC4_RainbowRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0F_RainbowRun/149120", func_80109CC4_14B654_RainbowRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0F_RainbowRun/149120", func_8010A42C_14BDBC_RainbowRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0F_RainbowRun/149120", func_8010A514_14BEA4_RainbowRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0F_RainbowRun/149120", func_8010A600_14BF90_RainbowRun);
