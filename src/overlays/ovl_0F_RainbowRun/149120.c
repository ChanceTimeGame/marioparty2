#include "common.h"
#include "ovl_0F.h"

/* .data (0x14C1C0-0x14C250, 8010A830-8010A8C0). D_8010A87C (the used flag of spot 0) is an
   undefined_syms.txt alias; the splat labels D_8010A834/838 inside D_8010A830 have no users. */

Vec D_8010A830_14C1C0_RainbowRun[6] = {
    { -400.0f, -605.0f, 650.0f },
    { -400.0f, -605.0f, 150.0f },
    { 400.0f, -605.0f, 350.0f },
    { 400.0f, -605.0f, 650.0f },
    { 400.0f, -605.0f, 150.0f },
    { -400.0f, -605.0f, 350.0f },
};
RRSpot D_8010A878_14C208_RainbowRun[4] = { { 20.0f, 0 }, { 50.0f, 0 }, { 310.0f, 0 }, { 340.0f, 0 } };
s8 D_8010A898_14C228_RainbowRun[4] = { 0 };
s8 D_8010A89C_14C22C_RainbowRun[6][4] = {
    { 0, 1, 4, 3 }, { 1, 2, 5, 4 }, { 2, 0, 3, 5 }, { 3, 0, 1, 4 }, { 4, 1, 2, 5 }, { 5, 2, 0, 3 },
};

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
            RRTeamWork* t = RR_TEAM(RR_WORK(o));

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
                omVibrate(w->unk_59, 2, 2, 20);
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

/* A follower's update (MP1 func_800FCEDC_TightropeTreachery, rebuilt): flashes while stunned,
   sways, turns towards the stick at most 10 degrees a frame, plays its result motion and voice
   when the game ends, follows its path and throws its bomb with A. */
// float register allocation: retail keeps the stick angle in f20 (its zero initialisation survives) and shares the last angle store (masked ~40, all registers)
#ifdef NON_MATCHING
void func_80108814_14A1A4_RainbowRun(omObjData* obj) {
    RRTeamWork* t = RR_TEAM(RR_WORK(obj));
    f32 sx;
    f32 sy;
    f32 dir;
    f32 mag;
    f32 d;
    f32 r;
    f32 s;
    f32 c;
    s32 file;

    dir = sy = sx = 0.0f;
    t->noCtrl = 0;
    if (t->flash != 0) {
        if (t->flash & 1) {
            func_800298A4_2A4A4(obj->model[0], 4, 0);
            func_800298A4_2A4A4(obj->model[1], 4, 0);
        } else {
            func_800298A4_2A4A4(obj->model[0], 4, 4);
            func_800298A4_2A4A4(obj->model[1], 4, 4);
        }
        t->flash--;
        t->noCtrl = 1;
    } else {
        func_800298A4_2A4A4(obj->model[0], 4, 0);
        func_800298A4_2A4A4(obj->model[1], 4, 0);
    }
    if (t->swayDir == 1) {
        if (++t->sway >= 9) {
            t->swayDir = 0;
        }
    } else {
        if (--t->sway < -8) {
            t->swayDir = 1;
        }
    }
    if (D_800F8FD0_F9BD0 != 1) {
        t->noCtrl = 1;
    }
    if (D_8010A6F5_14C085_RainbowRun == 1) {
        t->noCtrl = 1;
    }
    if (t->noCtrl == 0) {
        sx = ContStkX[t->port];
        sy = ContStkY[t->port];
    }
    if (D_8010A702_14C092_RainbowRun == 0) {
        mag = sx * sx + sy * sy;
        if (mag > 100.0f) {
            dir = func_800B75A8_B81A8(sx, -sy);
            if (t->angle < 0.0f) {
                t->angle += 360.0f;
            } else if (t->angle >= 360.0f) {
                t->angle -= 360.0f;
            }
            if (dir < 0.0f) {
                dir += 360.0f;
            } else if (dir >= 360.0f) {
                dir -= 360.0f;
            }
            if (t->angle <= dir) {
                if (dir < t->angle + 180.0f) {
                    d = dir - t->angle;
                    if (d < 10.0f) {
                        t->angle = d + t->angle;
                    } else {
                        t->angle = t->angle + 10.0f;
                    }
                } else {
                    d = t->angle + 360.0f - dir;
                    if (d < 10.0f) {
                        t->angle = t->angle - d;
                    } else {
                        t->angle = t->angle - 10.0f;
                    }
                }
            } else if (t->angle - 180.0f < dir) {
                d = t->angle - dir;
                if (d < 10.0f) {
                    t->angle = t->angle - d;
                } else {
                    t->angle = t->angle - 10.0f;
                }
            } else {
                d = dir + 360.0f - t->angle;
                if (d < 10.0f) {
                    t->angle = d + t->angle;
                } else {
                    t->angle = t->angle + 10.0f;
                }
            }
        }
        if (t->angle < 0.0f) {
            t->angle += 360.0f;
        } else if (t->angle >= 360.0f) {
            t->angle -= 360.0f;
        }
    } else {
        t->angle = 0.0f;
    }
    obj->rot.y = t->angle;
    if (t->done != 1 && D_8010A6F2_14C082_RainbowRun == 1) {
        switch (D_8010A6F6_14C086_RainbowRun) {
        case 1:
            func_80029B80_2A780(obj->model[0], obj->motion[2]);
            func_800732B0_73EB0(D_800CD438_CE038[gPlayers[t->player].character].unk_04 | 0x51);
            ContStkX[t->port] = 0;
            ContStkY[t->port] = 0;
            t->angle = 0.0f;
            t->turn = 0.0f;
            t->done = 1;
            obj->rot.y = 0.0f;
            break;
        case 2:
            func_80029B80_2A780(obj->model[0], obj->motion[2]);
            func_800732B0_73EB0(D_800CD438_CE038[gPlayers[t->player].character].unk_04 | 0x51);
            ContStkX[t->port] = 0;
            ContStkY[t->port] = 0;
            t->angle = 0.0f;
            t->turn = 0.0f;
            t->done = 1;
            obj->rot.y = 0.0f;
            break;
        case 3:
            func_80029B80_2A780(obj->model[0], obj->motion[1]);
            switch ((u32)D_800CD438_CE038[gPlayers[t->player].character].unk_04) {
            case 0x20000:
                func_800732B0_73EB0(D_800CD438_CE038[gPlayers[t->player].character].unk_04 | 0x56);
                break;
            case 0x30000:
                func_800732B0_73EB0(D_800CD438_CE038[gPlayers[t->player].character].unk_04 | 0x57);
                break;
            case 0x40000:
                func_800732B0_73EB0(D_800CD438_CE038[gPlayers[t->player].character].unk_04 | 0x56);
                break;
            case 0x50000:
                func_800732B0_73EB0(D_800CD438_CE038[gPlayers[t->player].character].unk_04 | 0x59);
                break;
            case 0x60000:
                func_800732B0_73EB0(D_800CD438_CE038[gPlayers[t->player].character].unk_04 | 0x57);
                break;
            default:
                func_800732B0_73EB0(D_800CD438_CE038[gPlayers[t->player].character].unk_04 | 0x55);
                break;
            }
            ContStkX[t->port] = 0;
            ContStkY[t->port] = 0;
            t->angle = 0.0f;
            t->turn = 0.0f;
            t->done = 1;
            obj->rot.y = 0.0f;
            break;
        }
    }
    if (D_8010A702_14C092_RainbowRun == 1 || D_800FFFD8_100BD8[0]->trans.y <= -600.0f) {
        ContStkX[t->port] = 0;
        ContStkY[t->port] = 0;
        t->angle = 0.0f;
        t->turn = 0.0f;
        obj->rot.y = 0.0f;
    }
    r = obj->rot.y + t->turn;
    obj->rot.y = r - (s32)(r / 360.0f) * 360.0f;
    if (obj->rot.y < 0.0f) {
        obj->rot.y += 360.0f;
    }
    s = HuMathSin(obj->rot.y) * 30.0f;
    c = func_800B7890_B8490(obj->rot.y) * 30.0f;
    obj->trans.x = t->ofs.x + t->pos.x;
    obj->trans.y = t->ofs.y + t->pos.y + t->sway / 2.0f;
    obj->trans.z = t->ofs.z + t->pos.z;
    func_80029714_2A314(obj->model[1], s + obj->trans.x, obj->trans.y - 80.0f + t->sway / 2.0f, c + obj->trans.z);
    func_8002979C_2A39C(obj->model[0], obj->rot.x, obj->rot.y, obj->rot.z);
    func_8002979C_2A39C(obj->model[1], obj->rot.x, obj->rot.y, obj->rot.z);
    if (t->noCtrl == 0 && (ContBtnTrg[t->port] & 0x8000)) {
        if (D_8010AC20_14C5B0_RainbowRun[t->idx].active == 0) {
            D_8010AC20_14C5B0_RainbowRun[t->idx].active = 1;
            func_80029B80_2A780(obj->model[0], obj->motion[3]);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0F_RainbowRun/149120", func_80108814_14A1A4_RainbowRun);
#endif

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

/* A follower's path and CPU control (MP1 func_800FD70C_TightropeTreachery, rebuilt): it moves
   along its path while the runner runs; a CPU faces the runner (plus an aim error renewed every
   few frames) and throws when the runner strays more than 50 from the middle. */
// the off-centre flag: retail reloads trans.x for the second compare and builds the flag in v0 (2 instructions)
#ifdef NON_MATCHING
void func_80109534_14AEC4_RainbowRun(omObjData* obj) {
    RRTeamWork* t = RR_TEAM(RR_WORK(obj));
    Vec p;
    f32 dx;
    f32 dz;
    f32 a;
    f32 d;
    s32 off;

    p = func_80109240_14ABD0_RainbowRun(D_8010AC08_14C598_RainbowRun[t->idx] + D_8010ABF0_14C580_RainbowRun, t->seg, t->t);
    t->pos.x = p.x;
    t->pos.y = p.y;
    t->pos.z = p.z;
    if (D_8010A702_14C092_RainbowRun == 0 && D_800FFFD8_100BD8[0]->trans.y > -600.0f && D_8010A6F4_14C084_RainbowRun == 1 &&
        D_8010A750_14C0E0_RainbowRun == 0) {
        if (t->wait >= 46) {
            t->t += 1.5f;
        } else {
            t->wait++;
        }
        if (t->t > 240.0f) {
            t->t = 0.0f;
            t->wait = 0;
            t->seg += 1.0f;
            if (t->seg >= 4.0f) {
                t->seg = 0.0f;
            }
        }
    }
    *(s32*)&t->turn = 0; /* retail stores an integer zero, then copies the float: GCC must not know it */
    t->turn = t->turn;
    if (gPlayers[t->player].flags & 1) {
        t->btn = 0;
        dx = D_800FFFD8_100BD8[0]->trans.x - obj->trans.x;
        dz = D_800FFFD8_100BD8[0]->trans.z - obj->trans.z;
        a = func_800B75A8_B81A8(dz, dx);
        a = a - (s32)(a / 360.0f) * 360.0f;
        if (a < 0.0f) {
            a += 360.0f;
        }
        if (t->aimWait < t->aimTimer++) {
            t->aimWait = guRandom() % 30;
            switch (gPlayers[t->player].cpu_difficulty) {
            case 0:
                t->aim = guRandom() % 52 - 26;
                break;
            case 1:
                t->aim = guRandom() % 44 - 22;
                break;
            case 2:
                t->aim = guRandom() % 36 - 18;
                break;
            case 3:
                t->aim = guRandom() % 30 - 15;
                break;
            }
            t->aimTimer = 0;
        }
        if (D_8010A702_14C092_RainbowRun == 0) {
            d = a + t->turn + t->aim;
            d = d - (s32)(d / 360.0f) * 360.0f;
            if (d < 0.0f) {
                d += 360.0f;
            }
            t->target = d;
        } else {
            t->target = 0.0f;
        }
        off = obj->trans.x > 50.0f || obj->trans.x < -50.0f;
        if (off == 1 && t->throwWait < t->timer) {
            t->btn |= 0x8000;
            t->timer = 0;
            switch (gPlayers[t->player].cpu_difficulty) {
            case 0:
                t->throwWait = guRandom() % 160 + 160;
                break;
            case 1:
                t->throwWait = guRandom() % 120 + 120;
                break;
            case 2:
                t->throwWait = guRandom() % 100 + 100;
                break;
            case 3:
                t->throwWait = guRandom() % 60 + 60;
                break;
            }
        }
        t->timer++;
        if (ContBtn[t->port] & 0x1000) {
            t->btn |= 0x1000;
        }
        ContBtn[t->port] = t->btn;
        ContBtnTrg[t->port] = t->btn & (t->btn ^ t->prevBtn);
        t->prevBtn = t->btn;
        if (t->target < 0.0f) {
            ContStkX[t->port] = 0;
            ContStkY[t->port] = 0;
        } else {
            ContStkX[t->port] = func_800B7890_B8490(t->target) * 80.0f;
            ContStkY[t->port] = -HuMathSin(t->target) * 80.0f;
        }
    }
    func_80108814_14A1A4_RainbowRun(obj);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0F_RainbowRun/149120", func_80109534_14AEC4_RainbowRun);
#endif

/* A follower (main's player work; its own state in D_8010AA18_14C3A8_RainbowRun[idx]; MP1
   func_800FDCE8_TightropeTreachery). A CPU follower gets an aim error and a throw interval by
   difficulty. */
void func_80109CC4_14B654_RainbowRun(omObjData* obj, s32 dir, s32 file, u16 player, f32 x, f32 y, f32 z, u16 idx) {
    void* mem;
    RRPlayerWork* w;
    RRTeamWork* t;
    s16 i;

    mem = func_80027154_27D54(sizeof(RRPlayerWork), 0x7918);
    obj->unk_50 = mem;
    func_800B0EF0_B1AF0(mem, 0, sizeof(RRPlayerWork));
    w = obj->unk_50;
    t = w->unk_158 = &D_8010AA18_14C3A8_RainbowRun[idx];
    w->unk_52 = 0;
    w->unk_B4 = 1.0f;
    w->unk_D0 = 0xFFFF;
    w->unk_4C = 0.5f;
    w->unk_CC = 1.0f;
    w->unk_60 = 0.0f;
    func_8000BEB0_CAB0(obj, 70.0f);
    func_8000BEBC_CABC(obj, 150.0f);
    func_8000BEC8_CAC8(obj, 20.0f);
    func_8000BE74_CA74(obj, 1000.0f);
    t->port = gPlayers[player].port;
    t->player = player;
    t->push[0] = t->push[1] = 0.0f;
    t->idx = idx;
    t->sway = guRandom() % 8;
    t->swayDir = 1;
    t->noCtrl = 0;
    t->hasSpot = 0;
    t->spot = 0;
    t->timer = 0;
    t->aimed = 0;
    t->unk_70 = 0;
    t->done = 0;
    t->turn = 0.0f;
    t->seg = 0.0f;
    t->t = 0.0f;
    t->pos.x = 0.0f;
    t->pos.y = 0.0f;
    t->pos.z = 0.0f;
    t->aim = 0.0f;
    t->aimTimer = 0;
    t->aimWait = guRandom() % 30;
    if (gPlayers[t->player].flags & 1) {
        switch (gPlayers[t->player].cpu_difficulty) {
        case 0:
            t->aim = guRandom() % 52 - 26;
            break;
        case 1:
            t->aim = guRandom() % 44 - 22;
            break;
        case 2:
            t->aim = guRandom() % 36 - 18;
            break;
        case 3:
            t->aim = guRandom() % 30 - 15;
            break;
        }
        switch (gPlayers[t->player].cpu_difficulty) {
        case 0:
            t->throwWait = guRandom() % 180 + 200;
            break;
        case 1:
            t->throwWait = guRandom() % 160 + 180;
            break;
        case 2:
            t->throwWait = guRandom() % 120 + 160;
            break;
        case 3:
            t->throwWait = guRandom() % 100 + 140;
            break;
        }
    }
    t->hasSpot = 1;
    t->spot = D_8010AC08_14C598_RainbowRun[idx];
    D_8010A87C_14C20C_RainbowRun[t->spot][0] = 1;
    obj->model[0] = LoadFormFile(dir | file, 0x2B9);
    if (D_8010AA00_14C390_RainbowRun[0] < 0) {
        obj->model[1] = LoadFormFile(0x1F0001, 0x2B9);
        D_8010AA00_14C390_RainbowRun[0] = obj->model[1];
    } else {
        obj->model[1] = func_80027D3C_2893C(D_8010AA00_14C390_RainbowRun[0]);
    }
    func_80018CCC_198CC(obj, 0, dir | 0x5E);
    func_80018CCC_198CC(obj, 3, dir | 0x5F);
    func_80018CCC_198CC(obj, 2, dir | 0x51);
    switch ((u32)dir) {
    case 0x20000:
        func_80018CCC_198CC(obj, 1, dir | 0x56);
        break;
    case 0x30000:
        func_80018CCC_198CC(obj, 1, dir | 0x57);
        break;
    case 0x40000:
        func_80018CCC_198CC(obj, 1, dir | 0x56);
        break;
    case 0x50000:
        func_80018CCC_198CC(obj, 1, dir | 0x59);
        break;
    case 0x60000:
        func_80018CCC_198CC(obj, 1, dir | 0x57);
        break;
    default:
        func_80018CCC_198CC(obj, 1, dir | 0x55);
        break;
    }
    func_80029B80_2A780(obj->model[0], obj->motion[0]);
    func_80029E80_2AA80(obj->model[0], 2, 2);
    t->angle = 0.0f;
    t->unk_92 = 0;
    for (i = 0; i < 8; i++) {
        t->unk_80[i] = 0;
        t->unk_88[i] = 0;
    }
    t->target = -1.0f;
    t->btn = 0;
    t->prevBtn = 0;
    t->flash = 0;
    t->pos.x = x;
    t->pos.y = y;
    t->pos.z = z;
    t->ofs.x = 0.0f;
    t->ofs.y = 0.0f;
    t->ofs.z = 0.0f;
    t->wait = 0;
    obj->trans.x = x;
    obj->trans.y = y;
    obj->trans.z = z;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, z);
    func_80029714_2A314(obj->model[1], x, y + 80.0f, z + 30.0f);
    obj->func_ptr = func_80109534_14AEC4_RainbowRun;
}

/* The followers: player D_8010ACC0[1..3] starts at its path's first point. */
void func_8010A42C_14BDBC_RainbowRun(omObjData* obj) {
    u8 chr = gPlayers[D_8010ACC0_14C650_RainbowRun[1]].character;
    s32 dir = D_800CD438_CE038[chr].unk_04;
    s32 file = D_800CD438_CE038[chr].unk_08;

    func_80109CC4_14B654_RainbowRun(obj, dir, file, D_8010ACC0_14C650_RainbowRun[1],
                                    D_8010A830_14C1C0_RainbowRun[D_8010AC08_14C598_RainbowRun[0] + D_8010ABF0_14C580_RainbowRun].x,
                                    D_8010A830_14C1C0_RainbowRun[D_8010AC08_14C598_RainbowRun[0] + D_8010ABF0_14C580_RainbowRun].y,
                                    D_8010A830_14C1C0_RainbowRun[D_8010AC08_14C598_RainbowRun[0] + D_8010ABF0_14C580_RainbowRun].z, 0);
}

void func_8010A514_14BEA4_RainbowRun(omObjData* obj) {
    u8 chr = gPlayers[D_8010ACC0_14C650_RainbowRun[2]].character;
    s32 dir = D_800CD438_CE038[chr].unk_04;
    s32 file = D_800CD438_CE038[chr].unk_08;

    func_80109CC4_14B654_RainbowRun(obj, dir, file, D_8010ACC0_14C650_RainbowRun[2],
                                    D_8010A830_14C1C0_RainbowRun[D_8010AC08_14C598_RainbowRun[1] + D_8010ABF0_14C580_RainbowRun].x,
                                    D_8010A830_14C1C0_RainbowRun[D_8010AC08_14C598_RainbowRun[1] + D_8010ABF0_14C580_RainbowRun].y,
                                    D_8010A830_14C1C0_RainbowRun[D_8010AC08_14C598_RainbowRun[1] + D_8010ABF0_14C580_RainbowRun].z, 1);
}

void func_8010A600_14BF90_RainbowRun(omObjData* obj) {
    u8 chr = gPlayers[D_8010ACC0_14C650_RainbowRun[3]].character;
    s32 dir = D_800CD438_CE038[chr].unk_04;
    s32 file = D_800CD438_CE038[chr].unk_08;

    func_80109CC4_14B654_RainbowRun(obj, dir, file, D_8010ACC0_14C650_RainbowRun[3],
                                    D_8010A830_14C1C0_RainbowRun[D_8010AC08_14C598_RainbowRun[2] + D_8010ABF0_14C580_RainbowRun].x,
                                    D_8010A830_14C1C0_RainbowRun[D_8010AC08_14C598_RainbowRun[2] + D_8010ABF0_14C580_RainbowRun].y,
                                    D_8010A830_14C1C0_RainbowRun[D_8010AC08_14C598_RainbowRun[2] + D_8010ABF0_14C580_RainbowRun].z, 2);
}
