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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0F_RainbowRun/149120", func_80107C5C_1495EC_RainbowRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0F_RainbowRun/149120", func_80108094_149A24_RainbowRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0F_RainbowRun/149120", func_8010815C_149AEC_RainbowRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0F_RainbowRun/149120", func_801087A8_14A138_RainbowRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0F_RainbowRun/149120", func_801087CC_14A15C_RainbowRun);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0F_RainbowRun/149120", func_801087F0_14A180_RainbowRun);

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
