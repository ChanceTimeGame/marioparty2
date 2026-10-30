#include "common.h"
#include "ovl_29.h"

/* .data (0x210BC0-0x210F84, 80106C70-80107034); 210B10.c has none. */

s32 D_80106C70_210BC0_TotemPolePound[6] = { 0x00020000, 0x00030000, 0x00070000, 0x00040000, 0x00050000, 0x00060000 };
u16 D_80106C88_210BD8_TotemPolePound[4] = { 0x4E, 0x4F, 0x55, 0x56 };
s32 D_80106C90_210BE0_TotemPolePound[4] = { 3, 4, 5, 6 };
f32 D_80106CA0_210BF0_TotemPolePound[4][3] = {
    { -375.0f, -600.0f, 0.0f }, { -125.0f, -600.0f, 0.0f }, { 125.0f, -600.0f, 0.0f }, { 375.0f, -600.0f, 0.0f },
};
f32 D_80106CD0_210C20_TotemPolePound[4][2] = { { 3.0f, 0.5f }, { 3.0f, 0.5f }, { 3.0f, 0.5f }, { 3.0f, 0.5f } };
f32 D_80106CF0_210C40_TotemPolePound[4][2] = { { 5.0f, 0.7f }, { 5.0f, 0.7f }, { 5.0f, 0.7f }, { 5.0f, 0.7f } };
f32 D_80106D10_210C60_TotemPolePound[3] = { 1.0f, 3.0f, 6.0f };
u32 D_80106D1C_210C6C_TotemPolePound[3] = { 0, 0, 0 };
u16 D_80106D28_210C78_TotemPolePound[4][2] = { { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 } };
s32 D_80106D38_210C88_TotemPolePound[6][8] = {
    { 0, 4, 6, 0x10, 0x2E, 0x4F, 0x55, 0x7D }, { 0, 4, 6, 0x10, 0x2E, 0x4F, 0x55, 0x7D },
    { 0, 4, 6, 0x10, 0x2E, 0x4F, 0x55, 0x7D }, { 0, 4, 6, 0x10, 0x2E, 0x4F, 0x55, 0x7D },
    { 0, 4, 6, 0x10, 0x2E, 0x4F, 0x55, 0x7D }, { 0, 4, 6, 0x10, 0x2E, 0x4F, 0x55, 0x7D },
};
f32 D_80106DF8_210D48_TotemPolePound[4][3] = {
    { -375.0f, 0.0f, 0.0f }, { -125.0f, 0.0f, 0.0f }, { 125.0f, 0.0f, 0.0f }, { 375.0f, 0.0f, 0.0f },
};
f32 D_80106E28_210D78_TotemPolePound[6][3] = {
    { -1.47f, 0.15f, 0.3f }, { -1.47f, 0.15f, 0.3f }, { -1.47f, 0.15f, 0.3f },
    { -1.47f, 0.15f, 0.3f }, { -1.47f, 0.15f, 0.3f }, { -1.47f, 0.15f, 0.3f },
};
f32 D_80106E70_210DC0_TotemPolePound[6][3] = {
    { 0.0f, 45.0f, 95.0f }, { 0.0f, 45.0f, 95.0f }, { 0.0f, 45.0f, 95.0f },
    { 0.0f, 45.0f, 95.0f }, { 0.0f, 45.0f, 95.0f }, { 0.0f, 45.0f, 95.0f },
};
f32 D_80106EB8_210E08_TotemPolePound[3] = { 40.0f, 80.0f, 120.0f };
f32 D_80106EC4_210E14_TotemPolePound[6][2] = {
    { -3.0f, -0.6f }, { -3.0f, -0.6f }, { -3.0f, -0.6f }, { -3.0f, -0.6f }, { -3.0f, -0.6f }, { -3.0f, -0.6f },
};
f32 D_80106EF4_210E44_TotemPolePound[6][2] = {
    { -3.0f, -0.6f }, { -3.0f, -0.6f }, { -3.0f, -0.6f }, { -3.0f, -0.6f }, { -3.0f, -0.6f }, { -3.0f, -0.6f },
};
f32 D_80106F24_210E74_TotemPolePound[6][2] = {
    { -3.0f, -0.6f }, { -3.0f, -0.6f }, { -3.0f, -0.6f }, { -3.0f, -0.6f }, { -3.0f, -0.6f }, { -3.0f, -0.6f },
};
f32 D_80106F54_210EA4_TotemPolePound[6][3] = {
    { 2.0f, 1.6f, 1.2f }, { 2.0f, 1.6f, 1.2f }, { 2.0f, 1.6f, 1.2f },
    { 2.0f, 1.6f, 1.2f }, { 2.0f, 1.6f, 1.2f }, { 2.0f, 1.6f, 1.2f },
};
u32 D_80106F9C_210EEC_TotemPolePound[3][3][3] = {
    { { 0x66, 0x19, 0x19 }, { 0x33, 0x4C, 0x19 }, { 0x19, 0x33, 0x4C } },
    { { 0x80, 0x19, 0x19 }, { 0x33, 0x66, 0x19 }, { 0x19, 0x33, 0x66 } },
    { { 0x19, 0x33, 0x66 }, { 0x19, 0x33, 0x80 }, { 0x0C, 0x19, 0x99 } },
};
u32 D_80107008_210F58_TotemPolePound[3] = { 0x4C, 0x33, 0x19 };
u32 D_80107014_210F64_TotemPolePound[3] = { 0x28, 0x14, 5 };
f32 D_80107020_210F70_TotemPolePound = 3.0f;
f32 D_80107024_210F74_TotemPolePound = 2.0f;
u32 D_80107028_210F78_TotemPolePound = 1;
u32 D_8010702C_210F7C_TotemPolePound = 2;
s16 D_80107030_210F80_TotemPolePound = 0;
u8 D_80107032_210F82_TotemPolePound = 0;

void func_80102800_20C750_TotemPolePound(void) {
    func_801069A0_2108F0_TotemPolePound();
}

void func_8010281C_20C76C_TotemPolePound(s32 player) {
    ContBtn[gPlayers[player].port] = 0;
    ContBtnTrg[gPlayers[player].port] = 0;
    ContStkX[gPlayers[player].port] = 0;
    ContStkY[gPlayers[player].port] = 0;
}

void func_8010289C_20C7EC_TotemPolePound(omObjData* obj, u32 motion) {
    if (motion < 8) {
        func_80029B80_2A780(obj->model[0], obj->motion[motion]);
    }
}

void func_801028D8_20C828_TotemPolePound(omObjData* obj, u16 motion, s16 arg2, s16 arg3) {
    if (motion < 8) {
        func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[motion]), arg2, arg3, 1);
    }
}

f32 func_8010295C_20C8AC_TotemPolePound(omObjData* obj) {
    u8 m = obj->model[0];
    f32 t = func_80029E3C_2AA3C(m);

    if (t == -1.0) {
        t = func_80029CE4_2A8E4(m);
    }
    return t;
}

void func_801029BC_20C90C_TotemPolePound(omObjData* obj, u8 i) {
    u8 m = obj->model[i];
    HmfAnim* a;
    f32 t;

    if (m != 0 && i < obj->mdlcnt) {
        t = func_80029CE4_2A8E4(m);
        if (func_80029D0C_2A90C(m) <= t) {
            a = D_800FC834_FD434[m].hmf->unk9C;
            if (a != NULL) {
                a->unk08 = 0.0f;
            }
            func_80029C74_2A874(m, 0.0f);
        }
        func_800298A4_2A4A4(m, 4, 0);
        func_80029714_2A314(m, obj->trans.x, obj->trans.y, obj->trans.z);
        func_8002979C_2A39C(m, obj->rot.x, obj->rot.y, 0.0f);
    }
}

void func_80102AC0_20CA10_TotemPolePound(s16 player, s16 sfx) {
    func_80079798_7A398(D_80108290_2121E0_TotemPolePound[player][sfx], player);
}

void func_80102B0C_20CA5C_TotemPolePound(s16 player, s32 kind) {
    switch (kind) {
    case 0:
        omVibrate(player, 2, 3, 10);
        break;
    case 1:
        omVibrate(player, 2, 2, 20);
        break;
    default:
        omVibrate(player, 30, 0, 30);
        break;
    }
}

f32 func_80102B78_20CAC8_TotemPolePound(f32 a, f32 b) {
    f32 x = a + b;

    if (x < 0.0) {
        x += 360.0;
    }
    if (x >= 360.0) {
        x -= 360.0;
    }
    return x;
}

void func_80102BDC_20CB2C_TotemPolePound(void) {
}

void func_80102BE4_20CB34_TotemPolePound(void) {
}

void func_80102BEC_20CB3C_TotemPolePound(void) {
}

void func_80102BF4_20CB44_TotemPolePound(omObjData* obj) {
    TPPFxWork* w = obj->unk_50;
    u32 i;
    s16 m;

    for (i = 0; i < 16; i++) {
        if (w->state[i] != 0) {
            m = (u16)D_800F86D8_F92D8[w->fx[i].id].unk00;
            func_800211E8_21DE8(w->fx[i].id, w->fx[i].alpha);
            if (D_800FC834_FD434[m].unk18 & 4) {
                w->state[i] = 0;
            }
        }
    }
}

/* NON_MATCHING: register choice only: the loop hoists the 0x390000 where retail hoists the table (masked 4). */
#ifdef NON_MATCHING
void func_80102CB4_20CC04_TotemPolePound(omObjData* obj) {
    TPPFxWork* w;
    s32* tbl;
    void* data;
    s16 tex;
    s16 id;
    u32 i;
    u32 j;
    u32 k;

    w = obj->unk_50 = func_80027154_27D54(0x150, 0x7918);
    tbl = D_80106C90_210BE0_TotemPolePound;
    for (i = 0; i < 4; i++) {
        data = DataRead(0x390000 | tbl[i]);
        tex = func_8003DF08_3EB08(data);
        HuMemMemoryFreePerm(data);
        for (j = 0; j < 4; j++) {
            k = i * 4 + j;
            w->fx[k].id = id = func_80020EBC_21ABC((void*)-1, 0x284, 8);
            func_80021250_21E50(id, 0xF0, 0xC8, 0x64);
            D_800F86D8_F92D8[id].unk02 = tex;
            func_80021160_21D60(id, 4, 4);
            w->state[k] = 0;
        }
    }
    obj->func_ptr = func_80102BF4_20CB44_TotemPolePound;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_29_TotemPolePound/20C750", func_80102CB4_20CC04_TotemPolePound);
#endif

void func_80102E10_20CD60_TotemPolePound(void) {
    D_80108100_212050_TotemPolePound = omAddObj(300, 0, 0, -1, func_80102CB4_20CC04_TotemPolePound);
}

void func_80102E4C_20CD9C_TotemPolePound(omObjData* obj, s16 n, s16 near) {
    TPPFxWork* w = D_80108100_212050_TotemPolePound->unk_50;
    u32 k = n * 4 + obj->work[1];
    TPPFx* fx;
    f32 x;
    f32 y;
    f32 z;
    s16 m;

    if (k < 16) {
        x = obj->trans.x;
        y = 30.0f;
        if (near == 0) {
            z = obj->trans.z + 130.0;
        } else {
            z = obj->trans.z + 100.0;
        }
        fx = &w->fx[k];
        m = (u16)D_800F86D8_F92D8[fx->id].unk00;
        fx->x = x;
        fx->y = y;
        fx->z = z;
        fx->alpha = 0xFF;
        w->state[k] = 2;
        func_800211E8_21DE8(fx->id, 0);
        func_800298A4_2A4A4(m, 4, 0);
        D_800F86D8_F92D8[fx->id].unk04 = 0;
        func_80029714_2A314(m, x, y, z);
        func_800297E8_2A3E8(m, 6.0f, 6.0f, 4.5f);
        func_80029EDC_2AADC(m, 2);
    }
}

void func_80102FBC_20CF0C_TotemPolePound(TPPPole* p) {
    omObjData* obj = p->obj;

    if (D_80106D1C_210C6C_TotemPolePound[p->power] < ++p->timer) {
        p->timer = 0;
        if (obj->trans.x < D_80106CA0_210BF0_TotemPolePound[obj->work[1]][0]) {
            obj->trans.x = D_80106CA0_210BF0_TotemPolePound[obj->work[1]][0] + D_80106D10_210C60_TotemPolePound[p->power];
        } else {
            obj->trans.x = D_80106CA0_210BF0_TotemPolePound[obj->work[1]][0] - D_80106D10_210C60_TotemPolePound[p->power];
        }
    }
}

s32 func_80103078_20CFC8_TotemPolePound(omObjData* obj) {
    s32 ret = 0;
    s32 pl = obj->work[1];
    TPPPole* p = &D_80108300_212250_TotemPolePound[pl];

    if (obj->trans.y == D_80106CA0_210BF0_TotemPolePound[pl][1]) {
        p->vel = D_80106CD0_210C20_TotemPolePound[pl][0];
        p->acc = D_80106CD0_210C20_TotemPolePound[pl][1];
        p->power = 2;
        p->spin = 0.0f;
        p->spinVel = D_80106CF0_210C40_TotemPolePound[pl][0];
        p->spinAcc = D_80106CF0_210C40_TotemPolePound[pl][1];
        func_80102E4C_20CD9C_TotemPolePound(obj, 0, 0);
    }
    obj->trans.y += p->vel;
    p->vel += p->acc;
    if (obj->trans.y >= 0.0) {
        obj->trans.y = 0.0f;
    }
    obj->rot.y = func_80102B78_20CAC8_TotemPolePound(obj->rot.y, p->spinVel);
    p->spin += p->spinVel;
    p->spinVel += p->spinAcc;
    if (p->spin >= 1080.0) {
        obj->rot.y = 0.0f;
    }
    func_80102FBC_20CF0C_TotemPolePound(p);
    if (obj->trans.y >= 0.0 && p->spin >= 1080.0) {
        obj->trans.x = D_80106CA0_210BF0_TotemPolePound[pl][0];
        ret = 2;
    }
    return ret;
}

s32 func_8010326C_20D1BC_TotemPolePound(omObjData* obj) {
    TPPPole* p = &D_80108300_212250_TotemPolePound[obj->work[1]];
    s32 ret;
    f32 d;

    obj->trans.y += p->vel;
    p->vel += p->acc;
    ret = 0;
    if (obj->trans.y <= p->floor) {
        func_8003E560_3F160(p->anim, 0);
        obj->trans.y = p->floor;
        obj->trans.x = D_80106CA0_210BF0_TotemPolePound[obj->work[1]][0];
        obj->rot.y = 0.0f;
        p->sunk += p->depth;
        ret = 2;
    } else if (obj->trans.y <= -600.0) {
        func_8003E560_3F160(p->anim, 0);
        obj->trans.y = -600.0f;
        obj->trans.x = D_80106CA0_210BF0_TotemPolePound[obj->work[1]][0];
        obj->rot.y = 0.0f;
        p->sunk = 15;
        ret = 2;
    } else {
        func_80102FBC_20CF0C_TotemPolePound(p);
        d = p->depth;
        if ((f32)(d * 20.0) + p->floor < obj->trans.y) {
            func_80102B0C_20CA5C_TotemPolePound(obj->work[1], p->power);
        }
    }
    return ret;
}

void func_80103424_20D374_TotemPolePound(omObjData* obj) {
    TPPPole* p = &D_80108300_212250_TotemPolePound[obj->work[1]];
    s32 next;

    switch (p->state) {
    case 1:
        next = func_80103078_20CFC8_TotemPolePound(obj);
        break;
    case 3:
        next = func_8010326C_20D1BC_TotemPolePound(obj);
        break;
    default:
        next = 0;
        break;
    }
    if (next != 0) {
        p->state = next;
    }
}

void func_801034A4_20D3F4_TotemPolePound(omObjData* obj) {
    TPPPole* p = &D_80108300_212250_TotemPolePound[obj->work[1]];
    void* data;

    obj->model[0] = LoadFormFile(0x390007, 0x6A9);
    data = DataRead(0x390002);
    p->anim = func_8003D8F0_3E4F0(D_800FC834_FD434[obj->model[0]].hmf, data, 0, "c171t000_DEF");
    func_80029A8C_2A68C(obj->model[0]);
    func_8003E4F4_3F0F4(p->anim, 1, 1);
    func_8003E560_3F160(p->anim, 0);
    func_80029AFC_2A6FC(obj->model[0]);
    HuMemMemoryFreePerm(data);
    p->state = 0;
    p->sunk = 0;
    p->vel = 0.0f;
    p->acc = 0.0f;
    p->power = 0;
    p->timer = 0;
    p->spin = 0.0f;
    p->spinVel = 0.0f;
    p->spinAcc = 0.0f;
    p->obj = obj;
    obj->trans.x = D_80106CA0_210BF0_TotemPolePound[obj->work[1]][0];
    obj->trans.y = D_80106CA0_210BF0_TotemPolePound[obj->work[1]][1];
    obj->trans.z = D_80106CA0_210BF0_TotemPolePound[obj->work[1]][2];
    func_80029EDC_2AADC(obj->model[0], 1);
    obj->func_ptr = func_80103424_20D374_TotemPolePound;
}

void func_8010363C_20D58C_TotemPolePound(void) {
    TPPObj* t;
    omObjData* o;
    u32 i;

    for (i = 0; i < 4; i++) {
        t = &D_801072F0_211240_TotemPolePound[(u16)(i + 5)];
        o = omAddObj(100, 1, 0, -1, func_801034A4_20D3F4_TotemPolePound);
        o->work[0] = i + 5;
        o->work[1] = i;
        t->player = i + 5;
        t->obj = o;
    }
}

/* NON_MATCHING: retail reloads nwin after the store and takes the base first (masked 2). */
#ifdef NON_MATCHING
void func_801036DC_20D62C_TotemPolePound(TPPPlayer* p) {
    TPPGame* g = &D_801072C8_211218_TotemPolePound;

    if (D_801072D8_211228_TotemPolePound < 4 && D_801072D4_211224_TotemPolePound == 0) {
        g->win[D_801072D8_211228_TotemPolePound] = p->obj->work[1];
        D_801072D8_211228_TotemPolePound++;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_29_TotemPolePound/20C750", func_801036DC_20D62C_TotemPolePound);
#endif

void func_80103734_20D684_TotemPolePound(TPPPlayer* p) {
    s32 r = (rand8() * 3) >> 8;

    switch (p->dif) {
    case 0:
        p->chance[0] = D_80106F9C_210EEC_TotemPolePound[0][r][0];
        p->chance[1] = D_80106F9C_210EEC_TotemPolePound[0][r][1];
        p->chance[2] = D_80106F9C_210EEC_TotemPolePound[0][r][2];
        break;
    case 1:
        p->chance[0] = D_80106F9C_210EEC_TotemPolePound[1][r][0];
        p->chance[1] = D_80106F9C_210EEC_TotemPolePound[1][r][1];
        p->chance[2] = D_80106F9C_210EEC_TotemPolePound[1][r][2];
        break;
    default:
        p->dif = 2;
        p->chance[0] = D_80106F9C_210EEC_TotemPolePound[2][r][0];
        p->chance[1] = D_80106F9C_210EEC_TotemPolePound[2][r][1];
        p->chance[2] = D_80106F9C_210EEC_TotemPolePound[2][r][2];
        break;
    }
    p->holdChance = D_80107008_210F58_TotemPolePound[p->dif];
    p->jumpChance = D_80107014_210F64_TotemPolePound[p->dif];
}

void func_80103870_20D7C0_TotemPolePound(TPPPlayer* p) {
    p->height = 0.0f;
    p->vel = D_80106E28_210D78_TotemPolePound[p->chr][0];
    p->grav = D_80106E28_210D78_TotemPolePound[p->chr][1];
    p->grav2 = D_80106E28_210D78_TotemPolePound[p->chr][2];
    p->released = 0;
    p->wait = 0;
    p->holding = 0;
}

f32 func_801038E4_20D834_TotemPolePound(TPPPlayer* p) {
    f32 v = p->vel;
    f32 k;

    if (v > 1.7f) {
        v = D_800BF7D4_C03D4;
    }
    if (v >= 0.0) {
        k = -35.0f;
    } else {
        k = 35.0f;
    }
    return v * v * k;
}

void func_80103950_20D8A0_TotemPolePound(TPPPlayer* p, f32 grav) {
    omObjData* obj = p->obj;
    f32 d = func_801038E4_20D834_TotemPolePound(p);

    obj->trans.y = d + obj->trans.y;
    p->height = d + p->height;
    p->vel += grav;
}

f32 func_801039B0_20D900_TotemPolePound(TPPPlayer* p) {
    f32 h;
    u32 i;

    func_80103870_20D7C0_TotemPolePound(p);
    h = 0.0f;
    i = 0;
    do {
        h += func_801038E4_20D834_TotemPolePound(p);
        p->vel += p->grav;
        if (p->vel > 0.0) {
            goto done;
        }
        if (i >= 101) {
            break;
        }
        i++;
    } while (1);
    h = 1.0f;
done:
    return h;
}

f32 func_80103A4C_20D99C_TotemPolePound(TPPPlayer* p) {
    f32 y = D_80108300_212250_TotemPolePound[p->obj->work[1]].obj->trans.y + 600.0;

    if (y < 0.0) {
        y = 0.0f;
    }
    return y;
}

f32 func_80103ABC_20DA0C_TotemPolePound(TPPPlayer* p) {
    return D_80108300_212250_TotemPolePound[p->obj->work[1]].obj->rot.y;
}

s32 func_80103AEC_20DA3C_TotemPolePound(TPPPlayer* p) {
    f32 y = p->obj->trans.y;

    return y <= func_80103A4C_20D99C_TotemPolePound(p);
}

s32 func_80103B2C_20DA7C_TotemPolePound(TPPPlayer* p) {
    s32 ret = 0;

    if (p->released == 0 && !(ContBtn[gPlayers[p->obj->work[1]].port] & 0x8000) && p->vel < 0.0) {
        p->released = 1;
        ret = 1;
    }
    return ret;
}

s32 func_80103BB4_20DB04_TotemPolePound(TPPPlayer* p) {
    f32 pct = p->height * 100.0 / p->best;
    s32 ret;

    if (pct > D_80106E78_210DC8_TotemPolePound[p->chr * 3]) {
        ret = 2;
    } else {
        if (pct > D_80106E74_210DC4_TotemPolePound[p->chr * 3]) {
            ret = 1;
        } else {
            ret = 0;
        }
    }
    return ret;
}

void func_80103C48_20DB98_TotemPolePound(TPPPlayer* p) {
    omObjData* obj = p->obj;
    f32 x = obj->trans.x;
    f32 y = func_80103A4C_20D99C_TotemPolePound(p);
    f32 z = obj->trans.z;
    f32 h = obj->trans.y - y;
    f32 f;
    f32 s;

    if (h > 0.0) {
        f = h / (2.0 * p->best);
        if (f > 0.5) {
            f = 0.5f;
        }
        s = 1.0 - f;
    } else {
        y -= 9.0;
        s = 1.0f;
    }
    func_80029714_2A314(obj->model[1], x, y, z);
    func_800297E8_2A3E8(obj->model[1], s, s, s);
}

void func_80103D64_20DCB4_TotemPolePound(TPPPlayer* p) {
    omObjData* obj = p->obj;
    f32 y = func_80103A4C_20D99C_TotemPolePound(p);
    u8 m;
    f32 t;

    m = obj->model[7];
    t = func_80029CE4_2A8E4(m);
    if (t < func_80029D0C_2A90C(m)) {
        func_80029714_2A314(m, obj->trans.x, y, obj->trans.z);
    }
    m = obj->model[8];
    t = func_80029CE4_2A8E4(m);
    if (t < func_80029D0C_2A90C(m)) {
        func_80029714_2A314(m, obj->trans.x, y, obj->trans.z);
    }
}

/* NON_MATCHING: register allocation only: anim and n swapped (s1/s2). */
#ifdef NON_MATCHING
void func_80103E24_20DD74_TotemPolePound(TPPPlayer* p) {
    TPPPole* q = &D_80108300_212250_TotemPolePound[p->obj->work[1]];
    s32 snd;
    s16 n;
    u8 anim;

    q->depth = p->power + 1;
    q->floor = q->obj->trans.y - D_80106EB8_210E08_TotemPolePound[p->power];
    switch (p->power) {
    case 0:
        q->vel = D_80106EC4_210E14_TotemPolePound[p->chr][0];
        q->acc = D_80106EC4_210E14_TotemPolePound[p->chr][1];
        snd = 0x284;
        anim = 0x10;
        n = 1;
        break;
    case 1:
        snd = 0x284;
        q->vel = D_80106EF4_210E44_TotemPolePound[p->chr][0];
        q->acc = D_80106EF4_210E44_TotemPolePound[p->chr][1];
        anim = 0x20;
        n = 2;
        break;
    default:
        snd = 0x284;
        anim = 0x30;
        q->vel = D_80106F24_210E74_TotemPolePound[p->chr][0];
        q->acc = D_80106F24_210E74_TotemPolePound[p->chr][1];
        n = 3;
        break;
    }
    q->power = p->power;
    q->timer = 0;
    q->state = 3;
    PlaySound(snd);
    func_8003E560_3F160(q->anim, anim);
    func_80102E4C_20CD9C_TotemPolePound(q->obj, n, 2);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_29_TotemPolePound/20C750", func_80103E24_20DD74_TotemPolePound);
#endif

void func_80103FAC_20DEFC_TotemPolePound(TPPPlayer* p) {
    p->mtnTime = 0.0f;
    p->mtnSpeed = D_80106F54_210EA4_TotemPolePound[p->chr][p->power];
}

s32 func_80103FE4_20DF34_TotemPolePound(TPPPlayer* p) {
    return D_80108300_212250_TotemPolePound[p->obj->work[1]].state == 2;
}

s32 func_80104018_20DF68_TotemPolePound(TPPPlayer* p) {
    return D_80108300_212250_TotemPolePound[p->obj->work[1]].sunk >= 15;
}

s32 func_8010404C_20DF9C_TotemPolePound(TPPPlayer* p) {
    s32 k = func_80103BB4_20DB04_TotemPolePound(p);

    return rand8() < p->chance[k];
}

u16 func_80104094_20DFE4_TotemPolePound(TPPPlayer* p) {
    u16 btn = 0;

    if (D_801072C8_211218_TotemPolePound.rate * 2 < ++p->wait || (u8)(rand8() % 5) == 0) {
        p->wait = 0;
        btn = 0x8000;
    }
    return btn;
}

u16 func_80104124_20E074_TotemPolePound(TPPPlayer* p) {
    u16 btn = 0x8000;

    if (p->holding != 0) {
        if (p->vel >= 0.0) {
            p->holding = 0;
        }
    } else if (func_8010404C_20DF9C_TotemPolePound(p) != 0) {
        btn = 0x2000;
    } else {
        if (rand8() < p->holdChance && p->vel < 0.0) {
            p->holding = 1;
        }
        if (rand8() < p->jumpChance) {
            btn = p->holding != 0 ? btn : 0;
        }
    }
    return btn;
}

void func_80104218_20E168_TotemPolePound(omObjData* obj) {
    TPPPlayer* p;
    u16 btn;

    func_8010281C_20C76C_TotemPolePound(obj->work[1]);
    p = &D_80108108_212058_TotemPolePound[obj->work[1]];
    btn = 0;
    switch (p->state) {
    case 9:
        if (p->sub != 3) {
            break;
        }
    case 5:
        btn = func_80104094_20DFE4_TotemPolePound(p);
        break;
    case 6:
        btn = func_80104124_20E074_TotemPolePound(p);
        break;
    }
    if (btn != 0) {
        ContBtn[gPlayers[obj->work[1]].port] = btn;
        ContBtnTrg[gPlayers[obj->work[1]].port] = btn;
    }
}

void func_80104334_20E284_TotemPolePound(omObjData* obj) {
    TPPPlayer* p = &D_80108108_212058_TotemPolePound[obj->work[1]];
    u32 next = 0;

    switch (p->state) {
    case 9:
        if (p->sub != 3) {
            break;
        }
    case 5:
        if (ContBtnTrg[gPlayers[obj->work[1]].port] & 0x8000) {
            func_80103870_20D7C0_TotemPolePound(p);
            func_80102AC0_20CA10_TotemPolePound(obj->work[1], 3);
            func_8010289C_20C7EC_TotemPolePound(obj, 1);
            next = 6;
        }
        break;
    case 6:
        if (ContBtnTrg[gPlayers[obj->work[1]].port] & 0x2000) {
            p->power = func_80103BB4_20DB04_TotemPolePound(p);
            p->vel = D_80106E28_210D78_TotemPolePound[p->chr][0] * 0.1f;
            func_80102AC0_20CA10_TotemPolePound(obj->work[1], 10);
            func_8010289C_20C7EC_TotemPolePound(obj, 2);
            next = 7;
        } else if (func_80103B2C_20DA7C_TotemPolePound(p) != 0) {
            p->vel = D_80106E28_210D78_TotemPolePound[p->chr][0] * 0.2f;
        }
        break;
    }
    if (next != 0) {
        p->state = next;
    }
}

s32 func_80104518_20E468_TotemPolePound(omObjData* obj) {
    func_8010289C_20C7EC_TotemPolePound(obj, 7);
    func_80029E80_2AA80(obj->model[0], 2, 2);
    return 2;
}

s32 func_80104558_20E4A8_TotemPolePound(omObjData* obj) {
    func_80102B0C_20CA5C_TotemPolePound(obj->work[1], 2);
    return 0;
}

s32 func_8010457C_20E4CC_TotemPolePound(omObjData* obj) {
    TPPPlayer* p = &D_80108108_212058_TotemPolePound[obj->work[1]];

    obj->trans.y = func_80103A4C_20D99C_TotemPolePound(p);
    obj->rot.y = func_80103ABC_20DA0C_TotemPolePound(p);
    return 0;
}

s32 func_801045DC_20E52C_TotemPolePound(omObjData* obj) {
    TPPPlayer* p = &D_80108108_212058_TotemPolePound[obj->work[1]];

    func_801028D8_20C828_TotemPolePound(obj, 0, 0, 30);
    p->sub = 1;
    return 9;
}

s32 func_80104630_20E580_TotemPolePound(omObjData* obj) {
    s32 ret = 0;
    TPPPlayer* p = &D_80108108_212058_TotemPolePound[obj->work[1]];

    func_80103950_20D8A0_TotemPolePound(p, p->grav);
    if (func_80103AEC_20DA3C_TotemPolePound(p) != 0) {
        obj->trans.y = func_80103A4C_20D99C_TotemPolePound(p);
        func_80102AC0_20CA10_TotemPolePound(obj->work[1], 4);
        func_8010289C_20C7EC_TotemPolePound(obj, 4);
        p->sub = 2;
        ret = 9;
    }
    return ret;
}

s32 func_801046D0_20E620_TotemPolePound(omObjData* obj) {
    s32 ret = 0;
    TPPPlayer* p = &D_80108108_212058_TotemPolePound[obj->work[1]];

    if (func_8010295C_20C8AC_TotemPolePound(obj) > 26.0) {
        func_80103950_20D8A0_TotemPolePound(p, p->grav2);
        if (func_80103AEC_20DA3C_TotemPolePound(p) != 0) {
            obj->trans.y = func_80103A4C_20D99C_TotemPolePound(p);
            func_80103E24_20DD74_TotemPolePound(p);
            func_801029BC_20C90C_TotemPolePound(obj, 7);
            func_801029BC_20C90C_TotemPolePound(obj, 8);
            func_80102AC0_20CA10_TotemPolePound(obj->work[1], 11);
            p->vel = D_80106E28_210D78_TotemPolePound[p->chr][0] * 0.6f;
            ret = 8;
        }
    }
    return ret;
}

s32 func_801047D4_20E724_TotemPolePound(omObjData* obj) {
    s32 ret = 0;
    TPPPlayer* p = &D_80108108_212058_TotemPolePound[obj->work[1]];

    func_80103D64_20DCB4_TotemPolePound(p);
    func_80103950_20D8A0_TotemPolePound(p, p->grav2);
    if (func_80103AEC_20DA3C_TotemPolePound(p) != 0) {
        obj->trans.y = func_80103A4C_20D99C_TotemPolePound(p);
        if (func_80103FE4_20DF34_TotemPolePound(p) != 0) {
            if (func_80104018_20DF68_TotemPolePound(p) != 0) {
                func_801036DC_20D62C_TotemPolePound(p);
                PlaySound(0x285);
            }
            func_80103FAC_20DEFC_TotemPolePound(p);
            func_8010289C_20C7EC_TotemPolePound(obj, 3);
            p->sub = 5;
            ret = 9;
        }
    }
    return ret;
}

s32 func_801048A8_20E7F8_TotemPolePound(omObjData* obj) {
    TPPPlayer* p = &D_80108108_212058_TotemPolePound[obj->work[1]];
    s32 next = 0;
    f32 t;
    f32 len;

    switch (p->sub) {
    case 1:
        if (func_80029E3C_2AA3C(obj->model[0]) == -1.0) {
            func_8010289C_20C7EC_TotemPolePound(obj, 0);
            func_80029E80_2AA80(obj->model[0], 2, 2);
            p->sub = 0;
            next = 11;
        }
        break;
    case 2:
        t = func_8010295C_20C8AC_TotemPolePound(obj);
        if (func_80029D0C_2A90C(obj->model[0]) <= t) {
            func_801028D8_20C828_TotemPolePound(obj, 0, 0, 20);
            p->sub = 3;
        }
        break;
    case 3:
        if (func_80029E3C_2AA3C(obj->model[0]) == -1.0) {
            func_8010289C_20C7EC_TotemPolePound(obj, 0);
            func_80029E80_2AA80(obj->model[0], 2, 2);
            p->sub = 0;
            next = 5;
        }
        break;
    case 5:
        t = func_8010295C_20C8AC_TotemPolePound(obj);
        len = func_80029D0C_2A90C(obj->model[0]);
        if (len <= t) {
            p->mtnTime = 0.0f;
            p->mtnSpeed = 0.0f;
            func_8010289C_20C7EC_TotemPolePound(obj, 0);
            func_80029E80_2AA80(obj->model[0], 2, 2);
            p->sub = 0;
            next = 5;
        } else {
            p->mtnTime += p->mtnSpeed;
            if (len < p->mtnTime) {
                p->mtnTime = len;
            }
            func_80029C74_2A874(obj->model[0], p->mtnTime);
        }
        break;
    default:
        next = 5;
        break;
    }
    return next;
}

s32 func_80104AB0_20EA00_TotemPolePound(omObjData* obj) {
    s32 mot;

    if (D_80108108_212058_TotemPolePound[obj->work[1]].won != 0) {
        func_800298A4_2A4A4(obj->model[0], 4, 4);
        func_800298A4_2A4A4(obj->model[9], 4, 0);
        obj->model[0] = obj->model[9];
        func_800732B0_73EB0(D_80106C70_210BC0_TotemPolePound[gPlayers[obj->work[1]].character] |
                            D_80106C88_210BD8_TotemPolePound[D_80107250_2111A0_TotemPolePound[obj->work[1]][0]]);
        mot = 5;
    } else {
        mot = 6;
    }
    func_8010289C_20C7EC_TotemPolePound(obj, mot);
    return 11;
}

void func_80104B98_20EAE8_TotemPolePound(omObjData* obj) {
    TPPPlayer* p = &D_80108108_212058_TotemPolePound[obj->work[1]];
    s32 next;

    switch (p->state) {
    case 1:
        next = func_80104518_20E468_TotemPolePound(obj);
        break;
    case 2:
        next = func_80104558_20E4A8_TotemPolePound(obj);
        break;
    case 3:
        next = func_8010457C_20E4CC_TotemPolePound(obj);
        break;
    case 4:
        next = func_801045DC_20E52C_TotemPolePound(obj);
        break;
    case 6:
        next = func_80104630_20E580_TotemPolePound(obj);
        break;
    case 7:
        next = func_801046D0_20E620_TotemPolePound(obj);
        break;
    case 8:
        next = func_801047D4_20E724_TotemPolePound(obj);
        break;
    case 9:
        next = func_801048A8_20E7F8_TotemPolePound(obj);
        break;
    case 10:
        next = func_80104AB0_20EA00_TotemPolePound(obj);
        break;
    default:
        next = 0;
        break;
    }
    if (next != 0) {
        p->state = next;
    }
    func_80103C48_20DB98_TotemPolePound(p);
}

void func_80104C9C_20EBEC_TotemPolePound(omObjData* obj) {
    if (D_801072C8_211218_TotemPolePound.over != 0) {
        func_8010281C_20C76C_TotemPolePound(obj->work[1]);
    } else if (D_80108108_212058_TotemPolePound[obj->work[1]].com != 0) {
        func_80104218_20E168_TotemPolePound(obj);
    }
    func_80104334_20E284_TotemPolePound(obj);
    func_80104B98_20EAE8_TotemPolePound(obj);
}

void func_80104D18_20EC68_TotemPolePound(omObjData* obj) {
    s32 pl = obj->work[1];
    TPPPlayer* p = &D_80108108_212058_TotemPolePound[pl];
    s32 chr = gPlayers[pl].character;
    s32 dir = D_800CD438_CE038[chr].dir;
    s32 model;

    model = D_800CD438_CE038[chr].model;
    obj->model[0] = LoadFormFile(dir | model, 0x6A9);
    func_80029A8C_2A68C(obj->model[0]);
    func_80029AFC_2A6FC(obj->model[0]);
    func_80018CCC_198CC(obj, 0, dir | D_80106D38_210C88_TotemPolePound[chr][0]);
    func_80018CCC_198CC(obj, 1, dir | D_80106D38_210C88_TotemPolePound[chr][1]);
    func_80018CCC_198CC(obj, 2, dir | D_80106D38_210C88_TotemPolePound[chr][2]);
    func_80018CCC_198CC(obj, 3, dir | D_80106D38_210C88_TotemPolePound[chr][3]);
    func_80018CCC_198CC(obj, 4, dir | D_80106D38_210C88_TotemPolePound[chr][4]);
    func_80018CCC_198CC(obj, 5, dir | D_80106D38_210C88_TotemPolePound[chr][5]);
    func_80018CCC_198CC(obj, 6, dir | D_80106D38_210C88_TotemPolePound[chr][6]);
    func_80018CCC_198CC(obj, 7, dir | D_80106D38_210C88_TotemPolePound[chr][7]);
    D_80107250_2111A0_TotemPolePound[obj->work[1]][0] = 1;
    dir = D_800CD438_CE038[chr].dir;
    model = D_800CD438_CE038[chr].model2;
    obj->model[9] = LoadFormFile(dir | model, 0x6A9);
    func_80029A8C_2A68C(obj->model[9]);
    func_80029AFC_2A6FC(obj->model[9]);
    func_800298A4_2A4A4(obj->model[9], 4, 4);
    obj->model[1] = func_80018A30_19630(1, 0x4A9);
    HmfModelObjAttrSet(obj->model[1], 0x80000000, 0);
    func_80029A8C_2A68C(obj->model[1]);
    func_80029AFC_2A6FC(obj->model[1]);
    func_800B1F50_B2B50(D_800FC834_FD434[obj->model[1]].mtx, 0.0f, 15.0f, 0.0f);
    obj->model[7] = LoadFormFile(0xC, 0x8AD);
    HmfModelObjAttrSet(obj->model[7], 0x80000000, 0);
    func_80029A8C_2A68C(obj->model[7]);
    func_80029AFC_2A6FC(obj->model[7]);
    func_800B1F50_B2B50(D_800FC834_FD434[obj->model[7]].mtx, 0.0f, 15.0f, 0.0f);
    obj->model[8] = LoadFormFile(0xB, 0x8AD);
    HmfModelObjAttrSet(obj->model[8], 0x80000000, 0);
    func_80029A8C_2A68C(obj->model[8]);
    func_80029AFC_2A6FC(obj->model[8]);
    func_800B1F50_B2B50(D_800FC834_FD434[obj->model[8]].mtx, 0.0f, 15.0f, 0.0f);
    p->state = 0;
    p->chr = chr;
    p->won = 0;
    p->best = func_801039B0_20D900_TotemPolePound(p);
    p->sub = 0;
    p->unk_2C = 0;
    p->mtnTime = 0.0f;
    p->mtnSpeed = 0.0f;
    p->obj = obj;
    if (gPlayers[pl].flags & 1) {
        p->com = 1;
        p->dif = gPlayers[pl].cpu_difficulty;
        func_80103734_20D684_TotemPolePound(p);
        p->holding = 0;
        p->wait = 0;
    } else {
        p->com = 0;
    }
    obj->trans.x = D_80106DF8_210D48_TotemPolePound[pl][0];
    obj->trans.y = D_80106DF8_210D48_TotemPolePound[pl][1];
    obj->trans.z = D_80106DF8_210D48_TotemPolePound[pl][2];
    func_8010289C_20C7EC_TotemPolePound(obj, 0);
    func_80029E80_2AA80(obj->model[0], 2, 2);
    D_80108290_2121E0_TotemPolePound[pl][3] = chr + 0x42;
    D_80108290_2121E0_TotemPolePound[pl][4] = chr + 0x50;
    D_80108290_2121E0_TotemPolePound[pl][10] = chr + 0x65;
    D_80108290_2121E0_TotemPolePound[pl][11] = chr + 0x6C;
    func_8010281C_20C76C_TotemPolePound(pl);
    func_80029EDC_2AADC(obj->model[0], 1);
    func_80029EDC_2AADC(obj->model[1], 1);
    func_80029EDC_2AADC(obj->model[7], 1);
    func_80029EDC_2AADC(obj->model[8], 1);
    obj->func_ptr = func_80104C9C_20EBEC_TotemPolePound;
}

void func_80105210_20F160_TotemPolePound(void) {
    TPPObj* t;
    omObjData* o;
    u16* e;
    u16 slot;
    u32 i;

    for (i = 0; i < 4; i++) {
        e = D_80106D28_210C78_TotemPolePound[i];
        slot = e[1];
        t = &D_801072F0_211240_TotemPolePound[slot];
        o = omAddObj(200, 10, 60, -1, func_80104D18_20EC68_TotemPolePound);
        o->work[0] = slot;
        o->work[1] = i;
        t->player = slot;
        t->obj = o;
    }
}

void func_801052C8_20F218_TotemPolePound(void) {
    u32 i;

    for (i = 0; i < 2; i++) {
        D_800F94A8_FA0A8[i] = 2100.0f;
        D_80102770_103370[i].x = 350.0f;
        D_80102770_103370[i].y = 0.0f;
        D_80102770_103370[i].z = 0.0f;
        D_801013B0_101FB0[i].x = 0.0f;
        D_801013B0_101FB0[i].y = 280.0f;
        D_801013B0_101FB0[i].z = 0.0f;
    }
}

/* NON_MATCHING: x and y swapped (f20/f22), with the scheduling that follows (masked 7). */
#ifdef NON_MATCHING
void func_80105368_20F2B8_TotemPolePound(omObjData* obj) {
    TPPObj* t = &D_801072F0_211240_TotemPolePound[4];
    f32 y;
    f32 x = 0.0f;
    f32 s;
    f32 dz;
    f32 ry;
    f32 rx;
    f32 sc;
    f64 z;

    dz = D_800F94A8_FA0A8[0] - 3300.0f;
    z = x;
    s = dz * -0.0004 + z;
    if (dz < z) {
        dz = -dz;
    }
    y = z + dz * -0.02;
    ry = D_80102770_103370[0].y;
    if (ry >= 180.0) {
        ry -= 360.0;
    }
    x = x + ry * 3.5555555555555554;
    rx = D_80102770_103370[0].x - 350.0;
    if (rx < 0.0) {
        rx += 360.0;
    }
    if (rx >= 180.0) {
        rx -= 360.0;
    }
    y = y + rx * 2.6666666666666665;
    sc = s + 1.0;
    SprScaleSet(t->spr, 0, sc, sc);
    SprPosSet(t->spr, 0, (s32)x + 160, (s32)y + 120);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_29_TotemPolePound/20C750", func_80105368_20F2B8_TotemPolePound);
#endif

void func_80105558_20F4A8_TotemPolePound(omObjData* obj) {
    GroundWork* gw;

    D_80107260_2111B0_TotemPolePound[0] = func_8001A2F8_1AEF8(0x390000);
    D_80107414_211364_TotemPolePound = SprCreate(1, 0);
    SprAttrReset(D_80107414_211364_TotemPolePound, 0, -1);
    SprScaleSet(D_80107414_211364_TotemPolePound, 0, 1.0f, 1.0f);
    SprAnimSet(D_80107414_211364_TotemPolePound, 0, D_80107260_2111B0_TotemPolePound[0], 0);
    SprBankSet(D_80107414_211364_TotemPolePound, 0, 0);
    SprAttrSet(D_80107414_211364_TotemPolePound, 0, 0x500C);
    SprPosSet(D_80107414_211364_TotemPolePound, 0, 160, 120);
    func_8008225C_82E5C(D_80107414_211364_TotemPolePound, 0, 0);
    SprPrioSet(D_80107414_211364_TotemPolePound, 0, 0xFFF0);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = obj;
    obj->unk_50 = gw = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(gw, 0, 0xB4);
    gw->unk_03 = 1;
    gw->unk_04 = 0;
    func_8000BEA4_CAA4(obj, 20.0f);
    func_8000BE8C_CA8C(obj, 1.0f);
    func_8000BF24_CB24(D_800FC7B0_FD3B0[0], 0.0f, -550.0f, -500.0f, 550.0f, 500.0f);
    obj->model[1] = LoadFormFile(0x390001, 0x6A9);
    HmfModelObjAttrSet(obj->model[1], 0x80000000, 0);
    func_80029A8C_2A68C(obj->model[1]);
    func_80029AFC_2A6FC(obj->model[1]);
    func_800B1F50_B2B50(D_800FC834_FD434[obj->model[1]].mtx, 0.0f, 0.0f, 0.0f);
    func_80029EDC_2AADC(obj->model[1], 1);
    obj->func_ptr = func_80105368_20F2B8_TotemPolePound;
}

void func_80105794_20F6E4_TotemPolePound(void) {
    func_8000C018_CC18(D_800F8FE0_F9BE0);
    D_801072F0_211240_TotemPolePound[4].obj = omAddObj(10, 4, 0, -1, func_80105558_20F4A8_TotemPolePound);
}

void func_801057DC_20F72C_TotemPolePound(TPPGame* g) {
    if (g->timer % D_80107028_210F78_TotemPolePound == 0) {
        if (D_801013B0_101FB0[0].x < 0.0f) {
            D_801013B0_101FB0[0].x = D_80107020_210F70_TotemPolePound + 0.0f;
        } else {
            D_801013B0_101FB0[0].x = 0.0f - D_80107020_210F70_TotemPolePound;
        }
    }
    if (g->timer % D_8010702C_210F7C_TotemPolePound == 0) {
        if (D_801013B0_101FB0[0].y < 280.0f) {
            D_801013B0_101FB0[0].y = D_80107024_210F74_TotemPolePound + 280.0f;
        } else {
            D_801013B0_101FB0[0].y = 280.0f - D_80107024_210F74_TotemPolePound;
        }
    }
}

void func_801058DC_20F82C_TotemPolePound(void) {
    f32 dy = D_801013B0_101FB0[0].y - 500.0f;
    f32 dz = D_800F94A8_FA0A8[0] - 3300.0f;

    if (TPP_ABS(dy) > 1.0f) {
        D_801013B0_101FB0[0].y -= dy * 0.15;
    } else {
        D_801013B0_101FB0[0].y = 500.0f;
    }
    if (TPP_ABS(dz) > 1.0f) {
        D_800F94A8_FA0A8[0] -= dz * 0.15;
    } else {
        D_800F94A8_FA0A8[0] = 3300.0f;
    }
}

void func_80105A64_20F9B4_TotemPolePound(TPPGame* g) {
    f32 max = 0.0f;
    TPPPole* q = D_80108300_212250_TotemPolePound;
    f32 dy;
    f32 dz;
    u32 i;

    for (i = 0; i < 4; i++, q++) {
        if (max < q->obj->trans.y - 0.0 + 600.0) {
            max = q->obj->trans.y - 0.0 + 600.0;
        }
    }
    max = 600.0 - max;
    dy = D_801013B0_101FB0[0].y - (500.0 - max * 200.0 / 600.0);
    dz = D_800F94A8_FA0A8[0] - (3300.0 - max * 1200.0 / 600.0);
    if (TPP_ABS(dy) > 20.0f) {
        D_801013B0_101FB0[0].y -= dy * 0.07;
    }
    if (TPP_ABS(dz) > 20.0f) {
        D_800F94A8_FA0A8[0] -= dz * 0.07;
    }
}

/* NON_MATCHING: retail loads the camera-centre base before the winner object (masked 4). */
#ifdef NON_MATCHING
void func_80105C64_20FBB4_TotemPolePound(TPPGame* g) {
    omObjData* o;
    f32 dx;
    f32 dy;
    f32 dz;

    if (g->nwin != 0) {
        o = D_80108108_212058_TotemPolePound[g->win[0]].obj;
        dx = D_801013B0_101FB0[0].x - o->trans.x;
        dy = D_801013B0_101FB0[0].y - o->trans.y - 30.0;
        dz = D_800F94A8_FA0A8[0] - 700.0f;
        if (TPP_ABS(dx) > 20.0f) {
            D_801013B0_101FB0[0].x -= dx * 0.07;
        }
        if (TPP_ABS(dy) > 50.0f) {
            D_801013B0_101FB0[0].y -= dy * 0.07;
        }
        if (TPP_ABS(dz) > 100.0f) {
            D_800F94A8_FA0A8[0] -= dz * 0.07;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_29_TotemPolePound/20C750", func_80105C64_20FBB4_TotemPolePound);
#endif

void func_80105E98_20FDE8_TotemPolePound(void) {
    D_800F94A8_FA0A8[1] = D_800F94A8_FA0A8[0];
    D_801013B0_101FB0[1].x = D_801013B0_101FB0[0].x;
    D_801013B0_101FB0[1].y = D_801013B0_101FB0[0].y;
    D_801013B0_101FB0[1].z = D_801013B0_101FB0[0].z;
    D_80102770_103370[1].x = D_80102770_103370[0].x;
    D_80102770_103370[1].y = D_80102770_103370[0].y;
    D_80102770_103370[1].z = D_80102770_103370[0].z;
}

void func_80105EEC_20FE3C_TotemPolePound(u32 state) {
    TPPPole* q;
    u32 i;

    if (state < 4) {
        q = D_80108300_212250_TotemPolePound;
        for (i = 0; i < 4; i++, q++) {
            q->state = state;
        }
    }
}

void func_80105F20_20FE70_TotemPolePound(u32 state) {
    TPPPlayer* p;
    u32 i;

    if (state < 12) {
        p = D_80108108_212058_TotemPolePound;
        for (i = 0; i < 4; i++, p++) {
            p->state = state;
        }
    }
}

s32 func_80105F54_20FEA4_TotemPolePound(void) {
    s32 ret;
    TPPPole* q;
    u32 i;

    ret = 1;
    q = D_80108300_212250_TotemPolePound;
    for (i = 0; i < 4; i++, q++) {
        if (q->state != 2) {
            ret = 0;
            break;
        }
    }
    return ret;
}

s32 func_80105F90_20FEE0_TotemPolePound(u32 state) {
    s32 ret;
    TPPPlayer* p;
    u32 i;

    ret = 1;
    p = D_80108108_212058_TotemPolePound;
    for (i = 0; i < 4; i++, p++) {
        if (p->state != state) {
            ret = 0;
            break;
        }
    }
    return ret;
}

void func_80105FC8_20FF18_TotemPolePound(TPPGame* g) {
    u32 i;
    u32 a;
    u32 b;
    s32 t;

    for (i = 0; i < 30; i++) {
        a = (rand8() * g->nwin) >> 8;
        b = (rand8() * g->nwin) >> 8;
        t = g->win[a];
        g->win[a] = g->win[b];
        g->win[b] = t;
    }
}

s32 func_80106064_20FFB4_TotemPolePound(TPPGame* g) {
    s32 ret;

    if (D_80107030_210F80_TotemPolePound == 0) {
        PlaySound(0x4B0);
        PlayMusic(0x1D);
        D_80107030_210F80_TotemPolePound = 1;
    }
    if (g->rate * 1.5 < ++g->timer) {
        g->timer = 0;
        PlaySound(0x283);
        ret = 2;
    } else {
        ret = 0;
    }
    return ret;
}

s32 func_8010610C_21005C_TotemPolePound(TPPGame* g) {
    if (g->rate * 2.5 < ++g->timer) {
        g->timer = 0;
        func_80105EEC_20FE3C_TotemPolePound(1);
        func_80105F20_20FE70_TotemPolePound(3);
        func_801052C8_20F218_TotemPolePound();
        PlaySound(0x286);
        return 3;
    }
    if (g->timer == g->rate * 0.5) {
        func_80105F20_20FE70_TotemPolePound(1);
    }
    func_801057DC_20F72C_TotemPolePound(g);
    return 0;
}

s32 func_801061FC_21014C_TotemPolePound(TPPGame* g) {
    s32 ret;

    func_801058DC_20F82C_TotemPolePound();
    ret = 0;
    if (D_800F94A8_FA0A8[0] == 3300.0f && D_801013B0_101FB0[0].y == 500.0f && func_80105F54_20FEA4_TotemPolePound() != 0) {
        func_80079868_7A468();
        PlaySound(0x287);
        ret = 4;
    }
    return ret;
}

s32 func_80106294_2101E4_TotemPolePound(TPPGame* g) {
    s32 ret = 0;

    if (g->rate * 0.5 < ++g->timer) {
        if (func_80105F90_20FEE0_TotemPolePound(11) != 0) {
            g->timer = 0;
            func_800691FC_69DFC(0);
            ret = 5;
        }
    } else if (g->timer == g->rate * 0.2) {
        func_80105F20_20FE70_TotemPolePound(4);
    }
    return ret;
}

s32 func_80106384_2102D4_TotemPolePound(TPPGame* g) {
    if (func_80069538_6A138() == 0) {
        func_800691FC_69DFC(10, g->time, 160, 28);
        func_80105F20_20FE70_TotemPolePound(5);
        return 6;
    }
    return 0;
}

s32 func_801063D0_210320_TotemPolePound(TPPGame* g) {
    s32 ret = 0;

    if (g->nwin != 0) {
        g->timer = 0;
        if (g->nwin != 1) {
            func_80105FC8_20FF18_TotemPolePound(g);
        }
        D_80108108_212058_TotemPolePound[g->win[0]].won = 1;
        func_8006D518_6E118();
        func_800691FC_69DFC(3);
        func_800794A8_7A0A8(40);
        g->over = 1;
        ret = 7;
    } else if (++g->timer > g->rate) {
        g->timer = 0;
        g->time--;
        func_8006D4D0_6E0D0(g->time);
        if (g->time == 0) {
            g->over = 1;
            func_8006D518_6E118();
            _CheckFlag(0xC);
            func_800691FC_69DFC(3);
            func_800794A8_7A0A8(40);
            ret = 7;
        }
    }
    func_80105A64_20F9B4_TotemPolePound(g);
    return ret;
}

/* NON_MATCHING: register allocation only: g and ret swapped (s0/s1). */
#ifdef NON_MATCHING
s32 func_801064CC_21041C_TotemPolePound(TPPGame* g) {
    TPPPlayer* p;
    s32 ret = 0;

    if (func_80069538_6A138() == 0 && func_80105F90_20FEE0_TotemPolePound(5) != 0) {
        if (_CheckFlag(0xC) != 0) {
            ret = 9;
            if (g->nwin != 0) {
                gPlayers[D_80108108_212058_TotemPolePound[g->win[0]].obj->work[1]].coins_mg_bonus = 10;
            }
        } else {
            if (g->nwin != 0) {
                p = &D_80108108_212058_TotemPolePound[g->win[0]];
                func_800691FC_69DFC(6, p->chr);
                PlayMusic(0x51);
                D_80107032_210F82_TotemPolePound = 1;
                gPlayers[p->obj->work[1]].coins_mg_bonus = 10;
            } else {
                func_800691FC_69DFC(0x13);
                PlayMusic(0x57);
                D_80107032_210F82_TotemPolePound = 0;
            }
            func_80105F20_20FE70_TotemPolePound(10);
            ret = 8;
        }
    }
    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_29_TotemPolePound/20C750", func_801064CC_21041C_TotemPolePound);
#endif

s32 func_8010661C_21056C_TotemPolePound(TPPGame* g) {
    s32 ret;

    if (_CheckFlag(0xC) != 0) {
        ret = 9;
        if (++g->timer > g->rate) {
            g->timer = 0;
        } else {
            ret = 0;
        }
    } else {
        if (D_80107032_210F82_TotemPolePound == 0) {
            if (g->rate * 4 < ++g->timer) {
                g->timer = 0;
                ret = 9;
            } else {
                ret = 0;
            }
        } else {
            if (g->rate * 4 < ++g->timer) {
                g->timer = 0;
                ret = 9;
            } else {
                ret = 0;
            }
        }
        func_80105C64_20FBB4_TotemPolePound(g);
    }
    return ret;
}

void func_801066EC_21063C_TotemPolePound(omObjData* obj) {
    osViBlack(0);
    omOvlReturnEx(1);
}

void func_80106710_210660_TotemPolePound(omObjData* obj) {
    if (func_8008F618_90218() == 0) {
        obj->func_ptr = func_801066EC_21063C_TotemPolePound;
    }
}

void func_80106748_210698_TotemPolePound(omObjData* obj) {
    if (D_801011FC_101DFC == 1) {
        InitFadeOut(0, 20);
        obj->func_ptr = func_80106710_210660_TotemPolePound;
        func_800794A8_7A0A8(40);
        func_80079614_7A214(40);
    }
}

void func_801067A0_2106F0_TotemPolePound(omObjData* obj) {
    TPPGame* g = &D_801072C8_211218_TotemPolePound;
    s32 next;

    switch (D_80108288_2121D8_TotemPolePound) {
    case 1:
        next = func_80106064_20FFB4_TotemPolePound(g);
        break;
    case 2:
        next = func_8010610C_21005C_TotemPolePound(g);
        break;
    case 3:
        next = func_801061FC_21014C_TotemPolePound(g);
        break;
    case 4:
        next = func_80106294_2101E4_TotemPolePound(g);
        break;
    case 5:
        next = func_80106384_2102D4_TotemPolePound(g);
        break;
    case 6:
        next = func_801063D0_210320_TotemPolePound(g);
        break;
    case 7:
        next = func_801064CC_21041C_TotemPolePound(g);
        break;
    case 8:
        next = func_8010661C_21056C_TotemPolePound(g);
        break;
    case 9:
        InitFadeOut(0, 20);
        obj->func_ptr = func_80106710_210660_TotemPolePound;
        next = 10;
        break;
    default:
        next = 0;
        break;
    }
    if (next != 0) {
        D_80108288_2121D8_TotemPolePound = next;
    }
    func_80105E98_20FDE8_TotemPolePound();
}

void func_801068B0_210800_TotemPolePound(omObjData* obj) {
    func_80106BC0_210B10_TotemPolePound();
    func_80106C44_210B94_TotemPolePound();
    /* Retail clears four times the size of D_80108300 (0x340) and D_80108108 (0x600): both run past
       the overlay's .bss (ends 801083D0). */
    func_800B0EF0_B1AF0(&D_801072C8_211218_TotemPolePound, 0, 0x24);
    func_800B0EF0_B1AF0(D_80108300_212250_TotemPolePound, 0, 0x340);
    func_800B0EF0_B1AF0(D_80108108_212058_TotemPolePound, 0, 0x600);
    func_800B0EF0_B1AF0(D_80108290_2121E0_TotemPolePound, 0, 0x70);
    func_80105794_20F6E4_TotemPolePound();
    func_80102E10_20CD60_TotemPolePound();
    func_8010363C_20D58C_TotemPolePound();
    func_80105210_20F160_TotemPolePound();
    *(s32*)&D_801072C8_211218_TotemPolePound = 30;
    D_801072CC_21121C_TotemPolePound = 30;
    D_801072D0_211220_TotemPolePound = 0;
    D_801072D4_211224_TotemPolePound = 0;
    D_801072D8_211228_TotemPolePound = 0;
    D_80108288_2121D8_TotemPolePound = 1;
    InitFadeIn(0, 16);
    obj->func_ptr = func_801067A0_2106F0_TotemPolePound;
    func_801052C8_20F218_TotemPolePound();
}

__asm__(".section .rodata");
const char D_80107244_211194_TotemPolePound[12] = "\202`\202a\202b";

void func_801069A0_2108F0_TotemPolePound(void) {
    omObjData* o;

    func_8002D4D0_2E0D0(50);
    func_80020D20_21920(50);
    omInitObjMan(50, 0);
    func_80079128_79D28();
    func_80026DAC_279AC(1, 0x40, 0x40, 0x60);
    func_80026E00_27A00(1, -20.0f, 64.0f, 99.0f);
    o = omAddObj(0x7FDA, 0, 0, -1, func_80079FF4_7ABF4);
    o->work[0] = 2;
    omSetStatBit(o, 0xA0);
    func_80018E30_19A30(2);
    func_80018F58_19B58(2);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 22.386f, 80.0f, 8000.0f);
    ScissorSet(1, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(1, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(1, 22.386f, 80.0f, 8000.0f);
    D_800FA606_FB206 = 0;
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    omAddObj(1000, 0, 0, -1, func_801068B0_210800_TotemPolePound);
    omAddObj(1000, 0, 0, -1, func_80106748_210698_TotemPolePound);
    func_8007273C_7333C((u8*)D_80107244_211194_TotemPolePound, 0);
    func_8007273C_7333C((u8*)D_80107244_211194_TotemPolePound, 1);
}
