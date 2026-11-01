#include "ovl_0B.h"

void func_80108670_12BE50_DayAtTheRaces(void) {
    D_8010AE70_12E650_DayAtTheRaces.state = 0;
    D_8010AE70_12E650_DayAtTheRaces.next = 0;
    D_8010AE70_12E650_DayAtTheRaces.sub = 0;
    D_8010AE70_12E650_DayAtTheRaces.timer = 0;
}

/* NON_MATCHING: control flow (masked 16): each pair's arms keep an andi before the ori that no source form here reproduced */
#ifdef NON_MATCHING
u16 func_8010868C_12BE6C_DayAtTheRaces(s8 x, s8 y) {
    s32 b = 0;

    if (DR_ABS(x) >= 31) {
        if (x < 0) {
            b = (u16)b | 0x200;
        } else {
            b = (u16)b | 0x100;
        }
    }
    if (DR_ABS(y) >= 31) {
        if (y < 0) {
            b = (u16)b | 0x400;
        } else {
            b = (u16)b | 0x800;
        }
    }
    return b;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0B_DayAtTheRaces/12BE50", func_8010868C_12BE6C_DayAtTheRaces);
#endif

void func_8010873C_12BF1C_DayAtTheRaces(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_8010AE70_12E650_DayAtTheRaces.pad[i].dirPrev = D_8010AE70_12E650_DayAtTheRaces.pad[i].dir;
        D_8010AE70_12E650_DayAtTheRaces.pad[i].dir = func_8010868C_12BE6C_DayAtTheRaces(ContStkX[i], ContStkY[i]);
        D_8010AE70_12E650_DayAtTheRaces.pad[i].dirTrg =
            D_8010AE70_12E650_DayAtTheRaces.pad[i].dir
            & (D_8010AE70_12E650_DayAtTheRaces.pad[i].dir ^ D_8010AE70_12E650_DayAtTheRaces.pad[i].dirPrev);
    }
}

void func_801087E0_12BFC0_DayAtTheRaces(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_8010AE70_12E650_DayAtTheRaces.pad[i].stkX = ContStkX[i];
        D_8010AE70_12E650_DayAtTheRaces.pad[i].stkY = ContStkY[i];
        D_8010AE70_12E650_DayAtTheRaces.pad[i].btn = ContBtn[i];
        D_8010AE70_12E650_DayAtTheRaces.pad[i].trg = ContBtnTrg[i];
    }
}

void func_80108870_12C050_DayAtTheRaces(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        ContStkX[i] = D_8010AE70_12E650_DayAtTheRaces.pad[i].stkX;
        ContStkY[i] = D_8010AE70_12E650_DayAtTheRaces.pad[i].stkY;
        ContBtn[i] = D_8010AE70_12E650_DayAtTheRaces.pad[i].btn;
        ContBtnTrg[i] = D_8010AE70_12E650_DayAtTheRaces.pad[i].trg;
    }
}

void func_80108900_12C0E0_DayAtTheRaces(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        ContStkX[i] = ContStkY[i] = 0;
        ContBtnTrg[i] = ContBtn[i] = 0;
    }
}

void func_80108954_12C134_DayAtTheRaces(DRCam* w) {
    func_800B3170_B3D70(&w->eye, &D_8010AA60_12E240_DayAtTheRaces[w->cam].eye);
    w->fov = 26.0f;
    w->aspect = 1.3333334f;
}

void func_801089BC_12C19C_DayAtTheRaces(DRCamPath* p, DRCamKey* out) {
    DRCamKey* b = &p->keys[p->seg];
    DRCamKey* a;
    f32 t;

    if (p->seg - 1 < 0) {
        a = b;
    } else {
        a = &p->keys[p->seg - 1];
    }
    t = (f32)(p->frame - a->frame) / (f32)(b->frame - a->frame);
    HuVecSubtract(&out->pos, &b->pos, &a->pos);
    HuVecMulScalar(&out->pos, t, &out->pos);
    HuVecAdd(&out->pos, &out->pos, &a->pos);
    HuVecSubtract(&out->target, &b->target, &a->target);
    HuVecMulScalar(&out->target, t, &out->target);
    HuVecAdd(&out->target, &out->target, &a->target);
    out->fov = (b->fov - a->fov) * t + a->fov;
}

void func_80108AF4_12C2D4_DayAtTheRaces(DRCam* w) {
    DRCamPath* p = w->path;
    DRCamKey view;

    if (p == NULL) {
        while (1) {
        }
    }
    func_801089BC_12C19C_DayAtTheRaces(p, &view);
    func_80109C98_12D478_DayAtTheRaces(w->cam, &view.pos, &view.target, view.fov, 0.0f);
    if (++p->frame >= p->keys[p->seg].frame) {
        p->seg++;
    }
    if (p->frame >= p->keys[p->last].frame) {
        w->mode = 0;
    }
}

/* NON_MATCHING: schedule (masked 6): the translation row loads in[3][n] between out's loads, as Filet Relay's twin */
#ifdef NON_MATCHING
void func_80108BB0_12C390_DayAtTheRaces(Matrix4f in, Matrix4f out) {
    f32 a, b, c, d, e, f, g, h, i;
    f32 det;
    f32 x, y, z;

    det = (in[0][0] * in[1][1] * in[2][2] + in[0][1] * in[1][2] * in[2][0] + in[0][2] * in[1][0] * in[2][1])
        - (in[0][2] * in[1][1] * in[2][0] + in[0][1] * in[1][0] * in[2][2] + in[0][0] * in[1][2] * in[2][1]);
    if (det == 0.0f) {
        det = 1.0f;
    } else {
        det = 1.0f / det;
    }
    out[0][0] = ((e = in[1][1]) * (i = in[2][2]) - (f = in[1][2]) * (h = in[2][1])) * det;
    out[0][1] = -(((b = in[0][1]) * i - (c = in[0][2]) * h) * det);
    out[0][2] = (b * f - c * e) * det;
    out[0][3] = in[0][3];
    out[1][0] = -(((d = in[1][0]) * i - f * (g = in[2][0])) * det);
    out[1][1] = ((a = in[0][0]) * i - c * g) * det;
    out[1][2] = -((a * f - c * d) * det);
    out[1][3] = in[1][3];
    out[2][0] = (d * h - e * g) * det;
    out[2][1] = -((a * h - b * g) * det);
    out[2][2] = (a * e - b * d) * det;
    out[2][3] = in[2][3];
    x = in[3][0];
    y = in[3][1];
    z = in[3][2];
    out[3][0] = -(out[0][0] * x + out[1][0] * y + out[2][0] * z);
    out[3][1] = -(out[0][1] * x + out[1][1] * y + out[2][1] * z);
    out[3][2] = -(out[0][2] * x + out[1][2] * y + out[2][2] * z);
    out[3][3] = in[3][3];
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0B_DayAtTheRaces/12BE50", func_80108BB0_12C390_DayAtTheRaces);
#endif

void func_80108E20_12C600_DayAtTheRaces(omObjData* obj) {
    DRCam* w = obj->unk_50;
    HuCamera* cam = &D_800C9B80_CA780[w->cam];
    HuCamMtxs* m = &cam->mtxs[D_800FFFD6_100BD6];

    if (D_8010AAD0_12E2B0_DayAtTheRaces[w->mode] != NULL) {
        D_8010AAD0_12E2B0_DayAtTheRaces[w->mode](w);
    }
    Hu3DCamSetPerspective(w->cam, w->fov, w->nearZ, w->farZ);
    func_800B1C70_B2870(&m->perspMtx, &cam->perspNorm, cam->fov[0], w->aspect, cam->fov[1], cam->fov[2], 1.0f);
    func_800B2400_B3000(w->view, w->eye.x, w->eye.y, w->eye.z, 1.0f, w->target.x, w->target.y, w->target.z);
    func_80108BB0_12C390_DayAtTheRaces(w->view, w->inv);
    func_800B3040_B3C40(w->inv, &m->lookAtMtx);
    D_800FC8F8_FD4F8[w->cam][1] = w->target.x;
    D_800FC8F8_FD4F8[w->cam][2] = w->target.z;
    D_800FC8F8_FD4F8[w->cam][0] = w->eye.y;
    D_800FC8F8_FD4F8[w->cam][3] = 5000.0f;
}

void func_80108FE4_12C7C4_DayAtTheRaces(omObjData* obj) {
    DRSprMdl* m;
    s16 sprite;

    for (m = D_8010AEC8_12E6A8_DayAtTheRaces.next; m != NULL; m = m->next) {
        if (m->func != NULL && !(m->flags & 1)) {
            m->func(m);
            sprite = D_800F86D8_F92D8[m->sprite].unk00;
            func_80029714_2A314(sprite, m->pos.x, m->pos.y, m->pos.z);
            func_800297E8_2A3E8(sprite, m->scale, m->scale, m->scale);
            func_800211E8_21DE8(m->sprite, m->alpha);
        }
    }
}

void func_8010909C_12C87C_DayAtTheRaces(s16 n) {
    func_80020D20_21920(n);
    D_8010AEBC_12E69C_DayAtTheRaces = omAddObj(6, 0, 0, -1, func_80108FE4_12C7C4_DayAtTheRaces);
    D_8010AEC8_12E6A8_DayAtTheRaces.flags = 1;
    D_8010AEC8_12E6A8_DayAtTheRaces.next = NULL;
    D_8010AEC8_12E6A8_DayAtTheRaces.prev = NULL;
    D_8010AF04_12E6E4_DayAtTheRaces = &D_8010AEC8_12E6A8_DayAtTheRaces;
}

void func_80109104_12C8E4_DayAtTheRaces(void) {
    func_80109FC4_12D7A4_DayAtTheRaces();
    omDelObj(D_8010AEBC_12E69C_DayAtTheRaces);
    func_80023124_23D24();
}

void func_80109134_12C914_DayAtTheRaces(omObjData* obj) {
    switch (D_8010AE70_12E650_DayAtTheRaces.sub) {
        case 0:
            D_8010AE70_12E650_DayAtTheRaces.unk_04 = 0;
            D_8010AE70_12E650_DayAtTheRaces.time = 0;
            D_8010AE70_12E650_DayAtTheRaces.frame = 0;
            D_8010AE70_12E650_DayAtTheRaces.sub = 1;
            D_8010AE70_12E650_DayAtTheRaces.count = 0;
            do {
                D_8010AE70_12E650_DayAtTheRaces.rank[D_8010AE70_12E650_DayAtTheRaces.count] = -1;
                D_8010AE70_12E650_DayAtTheRaces.count++;
            } while (D_8010AE70_12E650_DayAtTheRaces.count < 4);
            D_8010AE70_12E650_DayAtTheRaces.count = 0;
            func_80109AFC_12D2DC_DayAtTheRaces(rand8());
            InitFadeIn(0, 16);
            break;
        case 1:
            if (func_8008F618_90218() == 0) {
                D_8010AE70_12E650_DayAtTheRaces.sub++;
            }
            break;
        case 2:
            PlayMusic(0x58);
            D_8010AE70_12E650_DayAtTheRaces.sub++;
            break;
    }
}

void func_80109240_12CA20_DayAtTheRaces(omObjData* obj) {
}

void func_80109248_12CA28_DayAtTheRaces(omObjData* obj) {
    if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        if (D_8010AE70_12E650_DayAtTheRaces.time >= 0) {
            if (++D_8010AE70_12E650_DayAtTheRaces.time == 30) {
                func_800691FC_69DFC(0xF);
            }
            if (D_8010AE70_12E650_DayAtTheRaces.time >= 31) {
                if (func_80069538_6A138() == 0) {
                    D_8010AE70_12E650_DayAtTheRaces.time = -1;
                }
            }
        }
    }
}

void func_801092E4_12CAC4_DayAtTheRaces(omObjData* obj) {
}

void func_801092EC_12CACC_DayAtTheRaces(omObjData* obj) {
    switch (D_8010AE70_12E650_DayAtTheRaces.sub) {
        case 0:
            if (func_80069538_6A138() == 0) {
                D_8010AE70_12E650_DayAtTheRaces.sub++;
                D_8010AE70_12E650_DayAtTheRaces.timer = 60;
            }
            break;
        case 1:
            if (--D_8010AE70_12E650_DayAtTheRaces.timer == 0xFF) {
                D_8010AE70_12E650_DayAtTheRaces.sub++;
            }
            break;
        case 2:
            gPlayers[0].coins_mg_bonus = func_80109DE4_12D5C4_DayAtTheRaces(0);
            gPlayers[1].coins_mg_bonus = func_80109DE4_12D5C4_DayAtTheRaces(1);
            gPlayers[2].coins_mg_bonus = func_80109DE4_12D5C4_DayAtTheRaces(2);
            gPlayers[3].coins_mg_bonus = func_80109DE4_12D5C4_DayAtTheRaces(3);
            func_80109DAC_12D58C_DayAtTheRaces(5);
            break;
    }
}

void func_801093E8_12CBC8_DayAtTheRaces(omObjData* obj) {
    switch (D_8010AE70_12E650_DayAtTheRaces.sub) {
        case 0:
            func_80079614_7A214(20);
            func_800794A8_7A0A8(20);
            InitFadeOut(0, 20);
            D_8010AE70_12E650_DayAtTheRaces.sub++;
            break;
        case 1:
            if (func_8008F618_90218() == 0) {
                D_8010AE70_12E650_DayAtTheRaces.sub++;
            }
            break;
        case 2:
            func_80108414_12BBF4_DayAtTheRaces();
            func_801036C4_126EA4_DayAtTheRaces();
            func_80109104_12C8E4_DayAtTheRaces();
            func_8002864C_2924C();
            omOvlReturnEx(1);
            break;
    }
}

void func_801094AC_12CC8C_DayAtTheRaces(omObjData* obj) {
    if (D_801011FC_101DFC == 1 && D_8010AE70_12E650_DayAtTheRaces.state != 5) {
        func_80109DAC_12D58C_DayAtTheRaces(5);
    }
    D_8010AE70_12E650_DayAtTheRaces.state = D_8010AE70_12E650_DayAtTheRaces.next;
    if (D_8010AE70_12E650_DayAtTheRaces.state == 1 || D_8010AE70_12E650_DayAtTheRaces.state == 2) {
        func_8010873C_12BF1C_DayAtTheRaces();
    } else {
        func_801087E0_12BFC0_DayAtTheRaces();
        func_80108900_12C0E0_DayAtTheRaces();
    }
    D_8010AADC_12E2BC_DayAtTheRaces[D_8010AE70_12E650_DayAtTheRaces.state](obj);
    D_8010AE70_12E650_DayAtTheRaces.frame++;
}

void func_80109570_12CD50_DayAtTheRaces(omObjData* obj) {
    if (D_8010AE70_12E650_DayAtTheRaces.state != 1 && D_8010AE70_12E650_DayAtTheRaces.state != 2) {
        func_80108870_12C050_DayAtTheRaces();
    }
}

void func_801095A4_12CD84_DayAtTheRaces(Vec* v) {
    if (!(HuVecGetLength3F(v) < 0.001f)) {
        func_800B33E0_B3FE0(v);
    }
}

void func_801095F0_12CDD0_DayAtTheRaces(void) {
    omInitObjMan(0x32, 0);
    func_80079128_79D28();
    func_80108670_12BE50_DayAtTheRaces();
    func_8010909C_12C87C_DayAtTheRaces(0x1E);
}

void func_80109628_12CE08_DayAtTheRaces(void) {
    s32 i;
    DRCam* w;
    u8 id;

    func_80020070_20C70(2);
    for (i = 0; i < 2; i++) {
        func_80020718_21318(i, func_8002EDA8_2F9A8, D_800FC8F8_FD4F8[i]);
        id = i;
        ViewportSet(id, D_8010AA60_12E240_DayAtTheRaces[i].vp[0], D_8010AA60_12E240_DayAtTheRaces[i].vp[1], 511.0f,
                    D_8010AA60_12E240_DayAtTheRaces[i].vp[2], D_8010AA60_12E240_DayAtTheRaces[i].vp[3], 511.0f);
        ScissorSet(id, D_8010AA60_12E240_DayAtTheRaces[i].scissor[0], D_8010AA60_12E240_DayAtTheRaces[i].scissor[1],
                   D_8010AA60_12E240_DayAtTheRaces[i].scissor[2], D_8010AA60_12E240_DayAtTheRaces[i].scissor[3]);
        omSetStatBit(D_8010AEB4_12E694_DayAtTheRaces[i] = omAddObj(0x7FDA, 0, 0, -1, func_80108E20_12C600_DayAtTheRaces), 0xA0);
        w = func_80027154_27D54(sizeof(DRCam), 0x7918);
        if (w == NULL) {
            while (1) {
            }
        }
        func_800B0EF0_B1AF0(w, 0, sizeof(DRCam));
        func_800B3170_B3D70(&w->target, &D_8010AA60_12E240_DayAtTheRaces[i].start);
        func_800B3170_B3D70(&w->eye, &D_8010AA60_12E240_DayAtTheRaces[i].eye);
        w->cam = i;
        w->fov = 26.0f;
        w->nearZ = 250.0f;
        w->farZ = 1500.0f;
        w->aspect = 1.3333334f;
        w->mode = 0;
        D_8010AEB4_12E694_DayAtTheRaces[i]->unk_50 = w;
    }
}

void func_801098DC_12D0BC_DayAtTheRaces(void) {
    s32 i;

    func_80026D28_27928(2);
    for (i = 0; i < 2; i++) {
        func_80026E00_27A00(i, D_8010AAB0_12E290_DayAtTheRaces[i].dir[0], D_8010AAB0_12E290_DayAtTheRaces[i].dir[1],
                            D_8010AAB0_12E290_DayAtTheRaces[i].dir[2]);
        func_80026DAC_279AC(i, D_8010AAB0_12E290_DayAtTheRaces[i].color[0], D_8010AAB0_12E290_DayAtTheRaces[i].color[1],
                            D_8010AAB0_12E290_DayAtTheRaces[i].color[2]);
    }
}

void func_80109A90_12D270_DayAtTheRaces(void) {
    omSetStatBit(omAddObj(0, 0, 0, -1, func_801094AC_12CC8C_DayAtTheRaces), 0xA0);
    omSetStatBit(omAddObj(7, 0, 0, -1, func_80109570_12CD50_DayAtTheRaces), 0xA0);
}

void func_80109AFC_12D2DC_DayAtTheRaces(s32 seed) {
    D_8010AEC0_12E6A0_DayAtTheRaces = seed % 0x8000;
}

s32 func_80109B20_12D300_DayAtTheRaces(void) {
    return D_8010AEC0_12E6A0_DayAtTheRaces;
}

s32 func_80109B2C_12D30C_DayAtTheRaces(s32 n) {
    D_8010AEC0_12E6A0_DayAtTheRaces = (D_8010AEC0_12E6A0_DayAtTheRaces * 149 + 0x529) % 0x8000;
    return D_8010AEC0_12E6A0_DayAtTheRaces % n;
}

void func_80109BA4_12D384_DayAtTheRaces(s32 port, s8 stkX, s8 stkY, u16 trg, u16 btn) {
    ContStkX[port] = stkX;
    ContStkY[port] = stkY;
    ContBtn[port] = btn;
    ContBtnTrg[port] = trg;
}

u16 func_80109BE0_12D3C0_DayAtTheRaces(s32 port) {
    return D_8010AE70_12E650_DayAtTheRaces.pad[port].dirTrg;
}

void func_80109BFC_12D3DC_DayAtTheRaces(s32 cam, Vec* out) {
    DRCam* w = D_8010AEB4_12E694_DayAtTheRaces[cam]->unk_50;

    if (w->mode == 1) {
        func_80108954_12C134_DayAtTheRaces(w);
    }
    if (out != NULL) {
        func_800B3170_B3D70(out, &w->eye);
    }
}

void func_80109C5C_12D43C_DayAtTheRaces(s32 cam, Vec* v) {
    DRCam* w = D_8010AEB4_12E694_DayAtTheRaces[cam]->unk_50;

    if (v != NULL) {
        func_800B3170_B3D70(v, &w->target);
    }
}

void func_80109C98_12D478_DayAtTheRaces(s32 cam, Vec* target, Vec* eye, f32 fov, f32 aspect) {
    DRCam* w = D_8010AEB4_12E694_DayAtTheRaces[cam]->unk_50;

    if (target != NULL) {
        func_800B3170_B3D70(&w->target, target);
    }
    if (eye != NULL) {
        func_800B3170_B3D70(&w->eye, eye);
    }
    if (fov != 0.0f) {
        w->fov = fov;
    }
    if (aspect != 0.0f) {
        w->aspect = aspect;
    }
}

void func_80109D40_12D520_DayAtTheRaces(s32 cam, DRCamPath* path) {
    DRCam* w = D_8010AEB4_12E694_DayAtTheRaces[cam]->unk_50;

    if (path == NULL) {
        while (1) {
        }
    }
    w->path = path;
    path->seg = 1;
    path->frame = 0;
    w->mode = 2;
}

s32 func_80109D7C_12D55C_DayAtTheRaces(s32 cam) {
    return ((DRCam*)D_8010AEB4_12E694_DayAtTheRaces[cam]->unk_50)->mode != 2;
}

u8 func_80109DA0_12D580_DayAtTheRaces(void) {
    return D_8010AE70_12E650_DayAtTheRaces.state;
}

void func_80109DAC_12D58C_DayAtTheRaces(u8 state) {
    if (state >= 6) {
        while (1) {
        }
    }
    D_8010AE70_12E650_DayAtTheRaces.next = state;
    D_8010AE70_12E650_DayAtTheRaces.sub = 0;
}

u16 func_80109DD8_12D5B8_DayAtTheRaces(void) {
    return D_8010AE70_12E650_DayAtTheRaces.frame;
}

s16 func_80109DE4_12D5C4_DayAtTheRaces(s16 i) {
    return D_8010AE70_12E650_DayAtTheRaces.rank[i];
}

void func_80109DFC_12D5DC_DayAtTheRaces(s16 i, s16 v) {
    D_8010AE70_12E650_DayAtTheRaces.rank[i] = v;
}

DRSprMdl* func_80109E14_12D5F4_DayAtTheRaces(s16 flags, s16 unk, void* func) {
    DRSprMdl* m = func_80027154_27D54(sizeof(DRSprMdl), 0x7918);

    if (m == NULL) {
        return NULL;
    }
    m->flags = flags;
    m->sprite = func_80020EBC_21ABC((void*)-1, 0x684, 8);
    if (m->sprite == -1) {
        HuMemFree(m);
        return NULL;
    }
    D_800F86D8_F92D8[m->sprite].unk02 = unk;
    func_80021160_21D60(m->sprite, 4, 4);
    func_80021250_21E50(m->sprite, 0xFF, 0xFF, 0xFF);
    func_800212A4_21EA4(m->sprite);
    m->func = func;
    m->alpha = 0xFF;
    m->scale = 1.0f;
    HuVecCopyXYZ(&m->pos, 0.0f, 0.0f, 0.0f);
    HuVecCopyXYZ(&m->vel, 0.0f, 0.0f, 0.0f);
    HuVecCopyXYZ(&m->unk_20, 0.0f, 0.0f, 0.0f);
    m->next = NULL;
    m->prev = D_8010AF04_12E6E4_DayAtTheRaces;
    D_8010AF04_12E6E4_DayAtTheRaces->next = m;
    D_8010AF04_12E6E4_DayAtTheRaces = m;
    return m;
}

void func_80109F64_12D744_DayAtTheRaces(DRSprMdl* m) {
    func_8002308C_23C8C(m->sprite);
    m->prev->next = m->next;
    if (m->next != NULL) {
        m->next->prev = m->prev;
    } else {
        D_8010AF04_12E6E4_DayAtTheRaces = m->prev;
    }
    HuMemFree(m);
}

void func_80109FC4_12D7A4_DayAtTheRaces(void) {
    DRSprMdl* m;

    for (m = D_8010AF04_12E6E4_DayAtTheRaces; m != &D_8010AEC8_12E6A8_DayAtTheRaces; m = D_8010AF04_12E6E4_DayAtTheRaces) {
        func_80109F64_12D744_DayAtTheRaces(m);
    }
}

s16 func_8010A018_12D7F8_DayAtTheRaces(s32 file) {
    void* data = DataReadTemp(file);
    s16 sprite = func_8003DF08_3EB08(data);

    DataCloseTemp(data);
    return sprite;
}
