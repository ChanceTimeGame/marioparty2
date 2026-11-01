#include "ovl_28.h"

void func_80102800_205BA0_PlatformPeril(void) {
    func_80107EEC_20B28C_PlatformPeril();
}

void func_8010281C_205BBC_PlatformPeril(PPCloud* c, u8 index, f32 w, f32 h) {
    f32 x[5] = { 200.0f, 80.0f, 120.0f, 180.0f, 230.0f };
    f32 y[5] = { 100.0f, 60.0f, 180.0f, 220.0f, 30.0f };
    f32 amp[5] = { 0.08f, 0.08f, 0.08f, 0.08f, 0.08f };
    f32 rate[5] = { 6.0f, 6.0f, 6.0f, 6.0f, 6.0f };
    f32 drift[5] = { 3.0f, 2.0f, 1.0f, 2.5f, 1.5f };

    c->index = index;
    c->phase = 0.0f;
    c->x = x[D_80109044_20C3E4_PlatformPeril - 1];
    c->y = y[D_80109044_20C3E4_PlatformPeril - 1];
    c->amp = amp[D_80109044_20C3E4_PlatformPeril - 1];
    c->rate = rate[D_80109044_20C3E4_PlatformPeril - 1];
    c->drift = drift[D_80109044_20C3E4_PlatformPeril - 1];
    c->w = w;
    c->h = h;
}

void func_80102970_205D10_PlatformPeril(void) {
    PPCloud* c;
    f32 s;
    f32 sx;
    f32 sy;
    u8 i;

    for (i = 0; i < D_80109044_20C3E4_PlatformPeril; i++) {
        c = &D_801093BC_20C75C_PlatformPeril[i];
        s = HuMathSin(c->phase) * c->amp;
        sx = s + 1.0f;
        sy = 1.0f - s;
        c->x -= c->drift;
        c->y += c->drift;
        if (c->x < 0.0f - c->w / 2.0f || c->h / 2.0f + 240.0f < c->y) {
            if ((PP_RAND() & 1) || D_8010912A_20C4CA_PlatformPeril >= 2) {
                D_8010912A_20C4CA_PlatformPeril = 0;
                c->x = PP_RANGE(c->w / 2.0f + 40.0f, c->w / 2.0f + 320.0f);
                c->y = -(c->y / 2.0f);
            } else {
                D_8010912A_20C4CA_PlatformPeril += 1;
                c->x = c->w / 2.0f + 320.0f;
                c->y = PP_RANGE(-(c->h / 2.0f), 200.0f - c->h / 2.0f);
            }
        }
        SprPosSet(c->sprite, 0, (s32)c->x, (s32)c->y);
        SprScaleSet(c->sprite, 0, sx, sy);
        SprRotSet(c->sprite, 0, 360.0f);
        c->phase += c->rate;
        if (c->phase > 360.0f) {
            c->phase -= 360.0f;
        }
    }
}

s32 func_80102CC8_206068_PlatformPeril(s32 file, s32 prio, s32 attr, s32 alpha) {
    s16 anim = func_8001A2F8_1AEF8(file | 0x380000);
    s16 r = SprCreate(1, 0);

    SprAttrReset((u8)r, 0, -1);
    SprScaleSet((u8)r, 0, 1.0f, 1.0f);
    SprAnimSet((u8)r, 0, (u8)anim, 0);
    SprBankSet((u8)r, 0, 0);
    SprAttrSet((u8)r, 0, attr);
    func_8008225C_82E5C((u8)r, 0, 0);
    SprPrioSet((u8)r, 0, prio);
    func_80082488_83088((u8)r, 0, alpha);
    return (u8)r;
}

void func_80102DC8_206168_PlatformPeril(omObjData* obj) {
    s32 attr = 0x583C;
    s32 file[5] = { 13, 14, 15, 13, 14 };
    u16 alpha[5] = { 230, 150, 70, 200, 100 };
    u16 prio[5] = { 0, 10, 20, 5, 15 };
    f32 w[5] = { 192.0f, 160.0f, 128.0f, 192.0f, 160.0f };
    f32 h[5] = { 128.0f, 96.0f, 64.0f, 128.0f, 96.0f };
    PPCloud* c;
    u8 g;
    u8 i;

    g = func_80102CC8_206068_PlatformPeril(12, 0xFFF0, 0x4008, 0x100);
    SprPosSet(g, 0, 160, 120);
    SprScaleSet(g, 0, 2.0f, 2.0f);
    for (i = 0; i < 5; i++) {
        c = &D_801093BC_20C75C_PlatformPeril[D_80109044_20C3E4_PlatformPeril++];
        c->sprite = func_80102CC8_206068_PlatformPeril(file[i], prio[i], attr, alpha[i]);
        func_8010281C_205BBC_PlatformPeril(c, i, w[i], h[i]);
    }
    obj->func_ptr = func_80102970_205D10_PlatformPeril;
}

void func_80102FE4_206384_PlatformPeril(void) {
    omAddObj(100, 0, 0, -1, func_80102DC8_206168_PlatformPeril);
}

void func_80103018_2063B8_PlatformPeril(omObjData* obj, PPPlat* p) {
    u8 i;
    u32 t;

    if (func_80078EA8_79AA8() + D_80102720_103320 != 0) {
        return;
    }
    switch (p->state) {
    case 3:
        p->timer++;
        t = p->timer;
        if (t >= 26) {
            if (!(t & 3)) {
                for (i = 0; i < 4; i++) {
                    if (((MgWork*)D_800FFFD8_100BD8[i]->unk_50)->unk_53 == ((GroundWork*)obj->unk_50)->unk_04) {
                        omVibrate(i, 5, 0, 5);
                    }
                }
            }
            obj->rot.x = PP_RAND1();
            obj->rot.y = PP_RAND1();
            obj->rot.z = PP_RAND1();
        }
        if (p->timer >= 51) {
            p->state = 4;
        }
        break;
    case 4:
        p->timer++;
        p->speed += 5;
        obj->trans.y -= p->speed;
        if (obj->trans.y < -2600.0f) {
            obj->trans.z = 0.0f;
            p->state = 2;
            p->speed = 5;
            p->timer = 0;
        }
        break;
    }
}

void func_801032D8_206678_PlatformPeril(omObjData* obj) {
    GroundWork* g = obj->unk_50;
    PPPlat* p = &D_801093F0_20C790_PlatformPeril[g->unk_04];
    omObjData* pl;
    f32 x;
    s32 d;
    u8 i;

    switch (obj->work[0]) {
    case 8:
        if (D_80109124_20C4C4_PlatformPeril != 0) {
            D_8010912C_20C4CC_PlatformPeril += 1.0f;
            obj->trans.z += D_8010912C_20C4CC_PlatformPeril;
        }
        break;
    case 2:
        for (i = 0; i < 4; i++) {
            pl = D_800FFFD8_100BD8[i];
            if (((MgWork*)pl->unk_50)->unk_53 == g->unk_04) {
                pl->trans.x = (f32)(p->dir * 100) / 60.0f + pl->trans.x;
            }
        }
        x = (f32)(p->dir * 100) / 60.0f + obj->trans.x;
        obj->trans.x = x;
        if (abs((s32)x) > 100) {
            d = p->dir;
            p->dir = -d;
        }
        break;
    case 4:
        if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
            for (i = 0; i < 4; i++) {
                pl = D_800FFFD8_100BD8[i];
                if (((MgWork*)pl->unk_50)->unk_53 == g->unk_04) {
                    pl->trans.z += 7.5f;
                }
            }
        }
        func_8002BCA8_2C8A8(obj->model[0], 0.0f, D_80109134_20C4D4_PlatformPeril[p->tex], 0x40, 0x20);
        if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
            D_80109134_20C4D4_PlatformPeril[p->tex] += 0.6f;
        }
        break;
    case 5:
        if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
            for (i = 0; i < 4; i++) {
                pl = D_800FFFD8_100BD8[i];
                if (((MgWork*)pl->unk_50)->unk_53 == g->unk_04) {
                    pl->trans.z -= 7.5f;
                }
            }
        }
        func_8002BCA8_2C8A8(obj->model[0], 0.0f, D_80109130_20C4D0_PlatformPeril[p->tex], 0x40, 0x20);
        if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
            D_80109130_20C4D0_PlatformPeril[p->tex] -= 0.6f;
        }
        break;
    case 6:
        if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
            for (i = 0; i < 4; i++) {
                pl = D_800FFFD8_100BD8[i];
                if (((MgWork*)pl->unk_50)->unk_53 == g->unk_04) {
                    pl->trans.z += 7.5f;
                }
            }
        }
        func_8002BCA8_2C8A8(obj->model[0], 0.0f, D_8010913C_20C4DC_PlatformPeril[p->tex], 0x40, 0x20);
        if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
            D_8010913C_20C4DC_PlatformPeril[p->tex] += 0.6f;
        }
        break;
    case 7:
        if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
            for (i = 0; i < 4; i++) {
                pl = D_800FFFD8_100BD8[i];
                if (((MgWork*)pl->unk_50)->unk_53 == g->unk_04) {
                    pl->trans.z -= 7.5f;
                }
            }
        }
        func_8002BCA8_2C8A8(obj->model[0], 0.0f, D_80109138_20C4D8_PlatformPeril[p->tex], 0x40, 0x20);
        if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
            D_80109138_20C4D8_PlatformPeril[p->tex] -= 0.6f;
        }
        break;
    }
    func_80103018_2063B8_PlatformPeril(obj, p);
}

#ifdef NON_MATCHING
void func_801037F0_206B90_PlatformPeril(omObjData* obj) {
    GroundWork* g = obj->unk_50;
    PPSeq* seq;
    PPPlat* p;
    omObjData* pl;
    f32 cz;
    f32 dx;
    f32 dz;
    f32 d;
    s32 k;
    u8 i;

    switch (obj->work[1]) {
    case 0:
        cz = PP_CENTERZ - 100.0f;
        if ((cz - obj->trans.z < 1800.0f && obj->trans.z - cz < 1150.0) ||
            (obj->work[0] == 8 && PP_CENTERZ - 100.0f - obj->trans.z < 3200.0f &&
             obj->trans.z - (PP_CENTERZ - 100.0f) < 1150.0)) {
            func_800298A4_2A4A4(obj->model[0], 4, 0);
            obj->work[1] = 1;
        }
        break;
    case 1:
        seq = &D_80109048_20C3E8_PlatformPeril[obj->work[0]];
        func_801032D8_206678_PlatformPeril(obj);
        p = &D_801093F0_20C790_PlatformPeril[g->unk_04];
        if (obj->trans.z - (PP_CENTERZ - 100.0f) > 1150.0) {
            func_800298A4_2A4A4(obj->model[0], 4, 4);
            obj->work[1] = 0;
            k = seq->rows[seq->next];
            if (k != 0) {
                obj->trans.z = -(k * 100);
                obj->trans.y = 0.0f;
                p->z = obj->trans.z;
                p->state = 2;
                p->timer = 0;
                if (obj->work[0] == 8) {
                    D_80109124_20C4C4_PlatformPeril = 0;
                    p->goal = 1;
                } else {
                    if (obj->work[0] == 2) {
                        obj->trans.x = D_801090CC_20C46C_PlatformPeril[seq->next];
                    }
                    p->speed = 5;
                }
                seq->next++;
            }
        } else {
            for (i = 0; i < 4; i++) {
                pl = D_800FFFD8_100BD8[i];
                if (!(obj->trans.z < pl->trans.z - 100.0f)) {
                    continue;
                }
                if (((MgWork*)pl->unk_50)->unk_53 == g->unk_04) {
                    continue;
                }
                if (((MgWork*)pl->unk_50)->unk_53 == -1) {
                    continue;
                }
                dx = pl->trans.x - obj->trans.x;
                dz = pl->trans.z - obj->trans.z;
                d = func_800B1830_B2430(dx * dx + dz * dz);
                if (d < D_80109550_20C8F0_PlatformPeril[i].dist) {
                    D_80109550_20C8F0_PlatformPeril[i].obj = obj;
                    D_80109550_20C8F0_PlatformPeril[i].dist = d;
                    D_80109550_20C8F0_PlatformPeril[i].kind = obj->work[0];
                    D_80109550_20C8F0_PlatformPeril[i].plat = g->unk_04;
                }
            }
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_28_PlatformPeril/205BA0", func_801037F0_206B90_PlatformPeril);
#endif

void func_80103B7C_206F1C_PlatformPeril(omObjData* obj, omObjData* src, s32 file, f32 x, f32 y, f32 z, u8 clone) {
    GroundWork* g;

    obj->func_ptr = func_801037F0_206B90_PlatformPeril;
    if (clone == 0) {
        obj->model[0] = LoadFormFile(file | 0x380000, 0x99);
    } else {
        obj->model[0] = func_80027D3C_2893C(src->model[0]);
    }
    D_800FC834_FD434[obj->model[0]].unk18 |= 4;
    obj->trans.x = x;
    obj->trans.y = y;
    obj->trans.z = z;
    obj->unk_50 = g = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(g, 0, 0xB4);
    g->unk_03 = 1;
    g->unk_04 = D_80109045_20C3E5_PlatformPeril++;
    D_801093F0_20C790_PlatformPeril[g->unk_04].state = 2;
    D_801093F0_20C790_PlatformPeril[g->unk_04].timer = 0;
    D_801093F0_20C790_PlatformPeril[g->unk_04].speed = 5;
    D_801093F0_20C790_PlatformPeril[g->unk_04].goal = 0;
    D_801093F0_20C790_PlatformPeril[g->unk_04].z = obj->trans.z;
    func_8000BE8C_CA8C(obj, 0.5f);
}

void func_80103D00_2070A0_PlatformPeril(omObjData* obj) {
    GroundWork* g;

    func_80103B7C_206F1C_PlatformPeril(obj, NULL, 11, 0.0f, -1000.0f, 0.0f, 0);
    func_8000BF54_CB54(obj, -3000.0f, -3000.0f, -400.0f, -14000.0f, 400.0f, 0.0f);
    g = obj->unk_50;
    D_801093F0_20C790_PlatformPeril[g->unk_04].kind = 11;
    obj->work[0] = 11;
    obj->work[1] = 11;
    D_801093F0_20C790_PlatformPeril[g->unk_04].speed = 0;
    D_801093F0_20C790_PlatformPeril[g->unk_04].depth = 0.0f;
    func_8000C018_CC18(0);
}

void func_80103DDC_20717C_PlatformPeril(omObjData* obj) {
    GroundWork* g;

    func_80103B7C_206F1C_PlatformPeril(obj, NULL, 0, 0.0f, 0.0f, -(D_801090B2_20C452_PlatformPeril[D_801090B1_20C451_PlatformPeril] * 100), 0);
    func_8000BF54_CB54(obj, 0.0f, 0.0f, -400.0f, 0.0f, 400.0f, 1700.0f);
    g = obj->unk_50;
    D_801093F0_20C790_PlatformPeril[g->unk_04].kind = 8;
    obj->work[0] = 8;
    obj->work[1] = 0;
    D_801093F0_20C790_PlatformPeril[g->unk_04].speed = 0;
    D_801093F0_20C790_PlatformPeril[g->unk_04].depth = 0.0f;
    D_80109122_20C4C2_PlatformPeril = g->unk_04;
    D_801090B1_20C451_PlatformPeril++;
}

void func_80103EF8_207298_PlatformPeril(omObjData* obj) {
    GroundWork* g;
    PPSeq* s = &D_80109048_20C3E8_PlatformPeril[0];

    if (s->next == 0) {
        func_80103B7C_206F1C_PlatformPeril(obj, NULL, 1, 0.0f, 0.0f, -(s->rows[s->next] * 100), 0);
    } else {
        func_80103B7C_206F1C_PlatformPeril(obj, D_800FC7B0_FD3B0[s->master], 0, 0.0f, 0.0f, -(s->rows[s->next] * 100), 1);
    }
    func_8000BF54_CB54(obj, 0.0f, 300.0f, -420.0f, -250.0f, 420.0f, 250.0f);
    g = obj->unk_50;
    D_801093F0_20C790_PlatformPeril[g->unk_04].kind = 0;
    obj->work[0] = 0;
    obj->work[1] = 0;
    D_801093F0_20C790_PlatformPeril[g->unk_04].depth = 200.0f;
    s->next++;
}

void func_80104070_207410_PlatformPeril(omObjData* obj) {
    GroundWork* g;
    PPSeq* s = &D_80109048_20C3E8_PlatformPeril[1];

    if (s->next == 0) {
        func_80103B7C_206F1C_PlatformPeril(obj, NULL, 2, 0.0f, 0.0f, -(s->rows[s->next] * 100), 0);
    } else {
        func_80103B7C_206F1C_PlatformPeril(obj, D_800FC7B0_FD3B0[s->master], 0, 0.0f, 0.0f, -(s->rows[s->next] * 100), 1);
    }
    func_8000BF54_CB54(obj, 0.0f, 300.0f, -420.0f, -150.0f, 420.0f, 150.0f);
    g = obj->unk_50;
    D_801093F0_20C790_PlatformPeril[g->unk_04].kind = 1;
    obj->work[0] = 1;
    obj->work[1] = 0;
    D_801093F0_20C790_PlatformPeril[g->unk_04].depth = 100.0f;
    s->next++;
}

void func_801041EC_20758C_PlatformPeril(omObjData* obj) {
    GroundWork* g;
    PPSeq* s = &D_80109048_20C3E8_PlatformPeril[2];

    if (s->next == 0) {
        func_80103B7C_206F1C_PlatformPeril(obj, NULL, 4, D_801090CC_20C46C_PlatformPeril[0], 0.0f, -(s->rows[s->next] * 100), 0);
    } else {
        func_80103B7C_206F1C_PlatformPeril(obj, D_800FC7B0_FD3B0[s->master], 0, D_801090CC_20C46C_PlatformPeril[s->next], 0.0f, -(s->rows[s->next] * 100), 1);
    }
    func_8000BF54_CB54(obj, 0.0f, 300.0f, -320.0f, -150.0f, 320.0f, 150.0f);
    g = obj->unk_50;
    D_801093F0_20C790_PlatformPeril[g->unk_04].kind = 2;
    obj->work[0] = 2;
    obj->work[1] = 0;
    if (D_801090CC_20C46C_PlatformPeril[s->next] == 100.0f) {
        D_801093F0_20C790_PlatformPeril[g->unk_04].dir = -1;
    } else {
        D_801093F0_20C790_PlatformPeril[g->unk_04].dir = 1;
    }
    D_801093F0_20C790_PlatformPeril[g->unk_04].depth = 100.0f;
    s->next++;
}

void func_801043DC_20777C_PlatformPeril(omObjData* obj) {
    f32 xs[6] = { -250.0f, 250.0f, -250.0f, 250.0f, -250.0f, 250.0f };
    GroundWork* g;
    PPSeq* s = &D_80109048_20C3E8_PlatformPeril[3];

    if (s->next == 0) {
        func_80103B7C_206F1C_PlatformPeril(obj, NULL, 3, xs[0], 0.0f, -(s->rows[s->next] * 100), 0);
    } else {
        func_80103B7C_206F1C_PlatformPeril(obj, D_800FC7B0_FD3B0[s->master], 0, xs[s->next], 0.0f, -(s->rows[s->next] * 100), 1);
    }
    func_8000BF54_CB54(obj, 0.0f, 300.0f, -170.0f, -150.0f, 170.0f, 150.0f);
    g = obj->unk_50;
    D_801093F0_20C790_PlatformPeril[g->unk_04].kind = 3;
    obj->work[0] = 3;
    obj->work[1] = 0;
    D_801093F0_20C790_PlatformPeril[g->unk_04].depth = 100.0f;
    s->next++;
}

void func_801045A4_207944_PlatformPeril(omObjData* obj) {
    GroundWork* g;
    PPSeq* s = &D_80109048_20C3E8_PlatformPeril[5];

    if (s->next == 0) {
        func_80103B7C_206F1C_PlatformPeril(obj, NULL, 6, 0.0f, 0.0f, -(s->rows[s->next] * 100), 0);
    } else {
        func_80103B7C_206F1C_PlatformPeril(obj, D_800FC7B0_FD3B0[s->master], 0, 0.0f, 0.0f, -(s->rows[s->next] * 100), 1);
    }
    func_8002A00C_2AC0C(obj->model[0]);
    func_8000BF54_CB54(obj, 0.0f, 300.0f, -420.0f, -150.0f, 420.0f, 150.0f);
    g = obj->unk_50;
    D_801093F0_20C790_PlatformPeril[g->unk_04].kind = 5;
    obj->work[0] = 5;
    obj->work[1] = 0;
    obj->work[2] = s->next;
    D_801093F0_20C790_PlatformPeril[g->unk_04].depth = 100.0f;
    s->next++;
}

void func_80104734_207AD4_PlatformPeril(omObjData* obj) {
    GroundWork* g;
    PPSeq* s = &D_80109048_20C3E8_PlatformPeril[4];

    if (s->next == 0) {
        func_80103B7C_206F1C_PlatformPeril(obj, NULL, 5, 0.0f, 0.0f, -(s->rows[s->next] * 100), 0);
    } else {
        func_80103B7C_206F1C_PlatformPeril(obj, D_800FC7B0_FD3B0[s->master], 0, 0.0f, 0.0f, -(s->rows[s->next] * 100), 1);
    }
    func_8002A00C_2AC0C(obj->model[0]);
    func_8000BF54_CB54(obj, 0.0f, 300.0f, -420.0f, -150.0f, 420.0f, 150.0f);
    g = obj->unk_50;
    D_801093F0_20C790_PlatformPeril[g->unk_04].kind = 4;
    obj->work[0] = 4;
    obj->work[1] = 0;
    obj->work[2] = s->next;
    D_801093F0_20C790_PlatformPeril[g->unk_04].depth = 100.0f;
    s->next++;
}

void func_801048C4_207C64_PlatformPeril(omObjData* obj) {
    GroundWork* g;
    PPSeq* s = &D_80109048_20C3E8_PlatformPeril[7];

    if (s->next == 0) {
        func_80103B7C_206F1C_PlatformPeril(obj, NULL, 8, 0.0f, 0.0f, -(s->rows[s->next] * 100), 0);
    } else {
        func_80103B7C_206F1C_PlatformPeril(obj, D_800FC7B0_FD3B0[s->master], 0, 0.0f, 0.0f, -(s->rows[s->next] * 100), 1);
    }
    func_8002A00C_2AC0C(obj->model[0]);
    func_8000BF54_CB54(obj, 0.0f, 300.0f, -420.0f, -250.0f, 420.0f, 250.0f);
    g = obj->unk_50;
    D_801093F0_20C790_PlatformPeril[g->unk_04].kind = 7;
    obj->work[0] = 7;
    obj->work[1] = 0;
    obj->work[2] = s->next;
    D_801093F0_20C790_PlatformPeril[g->unk_04].depth = 200.0f;
    s->next++;
}

void func_80104A54_207DF4_PlatformPeril(omObjData* obj) {
    GroundWork* g;
    PPSeq* s = &D_80109048_20C3E8_PlatformPeril[6];

    if (s->next == 0) {
        func_80103B7C_206F1C_PlatformPeril(obj, NULL, 7, 0.0f, 0.0f, -(s->rows[s->next] * 100), 0);
    } else {
        func_80103B7C_206F1C_PlatformPeril(obj, D_800FC7B0_FD3B0[s->master], 0, 0.0f, 0.0f, -(s->rows[s->next] * 100), 1);
    }
    func_8002A00C_2AC0C(obj->model[0]);
    func_8000BF54_CB54(obj, 0.0f, 300.0f, -420.0f, -250.0f, 420.0f, 250.0f);
    g = obj->unk_50;
    D_801093F0_20C790_PlatformPeril[g->unk_04].kind = 6;
    obj->work[0] = 6;
    obj->work[1] = 0;
    obj->work[2] = s->next;
    D_801093F0_20C790_PlatformPeril[g->unk_04].depth = 200.0f;
    s->next++;
}

void func_80104BE4_207F84_PlatformPeril(void) {
    u8 i;

    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(300, 1, 0, -1, func_80103D00_2070A0_PlatformPeril);
    D_80109048_20C3E8_PlatformPeril[8].master = D_800F8FE0_F9BE0;
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(300, 1, 0, -1, func_80103DDC_20717C_PlatformPeril);
    D_80109048_20C3E8_PlatformPeril[0].master = D_800F8FE0_F9BE0;
    for (i = 0; i < 4; i++) {
        D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(300, 1, 0, -1, func_80103EF8_207298_PlatformPeril);
    }
    D_80109048_20C3E8_PlatformPeril[1].master = D_800F8FE0_F9BE0;
    for (i = 0; i < 4; i++) {
        D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(300, 1, 0, -1, func_80104070_207410_PlatformPeril);
    }
    D_80109048_20C3E8_PlatformPeril[2].master = D_800F8FE0_F9BE0;
    for (i = 0; i < 2; i++) {
        D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(300, 1, 0, -1, func_801041EC_20758C_PlatformPeril);
    }
    D_80109048_20C3E8_PlatformPeril[3].master = D_800F8FE0_F9BE0;
    for (i = 0; i < 6; i++) {
        D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(300, 1, 0, -1, func_801043DC_20777C_PlatformPeril);
    }
    D_80109048_20C3E8_PlatformPeril[5].master = D_800F8FE0_F9BE0;
    for (i = 0; i < 1; i++) {
        D_800FC7B0_FD3B0[D_800F8FE0_F9BE0] = omAddObj(300, 1, 0, -1, func_801045A4_207944_PlatformPeril);
        omSetStatBit(D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++], 0xA0);
    }
    D_80109048_20C3E8_PlatformPeril[4].master = D_800F8FE0_F9BE0;
    for (i = 0; i < 1; i++) {
        D_800FC7B0_FD3B0[D_800F8FE0_F9BE0] = omAddObj(300, 1, 0, -1, func_80104734_207AD4_PlatformPeril);
        omSetStatBit(D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++], 0xA0);
    }
    D_80109048_20C3E8_PlatformPeril[5].master = D_800F8FE0_F9BE0;
    for (i = 0; i < 1; i++) {
        D_800FC7B0_FD3B0[D_800F8FE0_F9BE0] = omAddObj(300, 1, 0, -1, func_801048C4_207C64_PlatformPeril);
        omSetStatBit(D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++], 0xA0);
    }
    D_80109048_20C3E8_PlatformPeril[4].master = D_800F8FE0_F9BE0;
    for (i = 0; i < 1; i++) {
        D_800FC7B0_FD3B0[D_800F8FE0_F9BE0] = omAddObj(300, 1, 0, -1, func_80104A54_207DF4_PlatformPeril);
        omSetStatBit(D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++], 0xA0);
    }
}

#ifdef NON_MATCHING
void func_80105088_208428_PlatformPeril(omObjData* obj) {
    omObjData* pl;
    f32 half;
    f32 x;
    f32 xl;
    f32 xr;
    f32 zl;
    f32 zr;
    f32 w;
    f32 dx;
    f32 a;
    f32 b;
    u8 i;

    xl = obj->trans.x - 100.0f;
    xr = obj->trans.x + 100.0f;
    half = obj->work[2] * 50;
    zl = obj->trans.z - half;
    zr = half + obj->trans.z;
    for (i = 0; i < 4; i++) {
        pl = D_800FFFD8_100BD8[i];
        x = pl->trans.x;
        if (xl < x) {
            if (x < xr) {
                if (zl < pl->trans.z) {
                    if (pl->trans.z < zr) {
                        if (pl->trans.y < 200.0f) {
            w = xr - xl;
            dx = x - xl;
            a = (zl - zr) / w * dx + zr - pl->trans.z;
            b = (zr - zl) / w * dx + zl - pl->trans.z;
            if (a > 0.0f) {
                if (b > 0.0f) {
                    pl->trans.z = zl;
                } else {
                    pl->trans.x = xl;
                }
            } else if (b > 0.0f) {
                pl->trans.x = xr;
            } else {
                pl->trans.z = zr;
            }
                        }
                    }
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_28_PlatformPeril/205BA0", func_80105088_208428_PlatformPeril);
#endif

void func_80105204_2085A4_PlatformPeril(omObjData* obj) {
    switch (D_801093F0_20C790_PlatformPeril[obj->work[3]].state) {
    case 3:
        if (D_801093F0_20C790_PlatformPeril[obj->work[3]].timer >= 31) {
            obj->rot.x = PP_RAND1();
            obj->rot.y = PP_RAND1();
            obj->rot.z = PP_RAND1();
        }
        break;
    case 4:
        obj->trans.y -= D_801093F0_20C790_PlatformPeril[obj->work[3]].speed;
        if (obj->trans.y < -2500.0f) {
            func_800298A4_2A4A4(obj->model[0], 4, 4);
            obj->trans.z = 0.0f;
        }
        break;
    }
}

void func_80105434_2087D4_PlatformPeril(omObjData* obj) {
    PPStrip* s;
    omObjData* other;
    f32 cz;
    u8 i;

    switch (obj->work[1]) {
    case 0:
        cz = PP_CENTERZ - 100.0f;
        if (cz - obj->trans.z < 1600.0f && obj->trans.z - cz < 850.0) {
            func_800298A4_2A4A4(obj->model[0], 4, 0);
            obj->work[1] = 1;
            for (i = 1; i < D_800F8FE0_F9BE0; i++) {
                other = D_800FC7B0_FD3B0[i];
                if (obj->trans.z == other->trans.z) {
                    obj->work[3] = ((GroundWork*)other->unk_50)->unk_04;
                }
            }
        }
        break;
    case 1:
        s = &D_801090D8_20C478_PlatformPeril[obj->work[0]];
        func_80105088_208428_PlatformPeril(obj);
        func_80105204_2085A4_PlatformPeril(obj);
        if (obj->trans.z - (PP_CENTERZ - 100.0f) > 950.0) {
            func_800298A4_2A4A4(obj->model[0], 4, 4);
            obj->work[1] = 0;
            if (s->z[s->next] != 0) {
                obj->trans.x = s->x[s->next] * 100;
                obj->trans.y = 0.0f;
                obj->trans.z = -(s->z[s->next] * 100);
                s->next++;
            }
        }
        break;
    }
}

void func_80105660_208A00_PlatformPeril(omObjData* obj, omObjData* src, s32 file, f32 x, f32 y, f32 z, u8 clone) {
    obj->func_ptr = func_80105434_2087D4_PlatformPeril;
    if (clone == 0) {
        obj->model[0] = LoadFormFile(file | 0x380000, 0x99);
    } else {
        obj->model[0] = func_80027D3C_2893C(src->model[0]);
    }
    D_800FC834_FD434[obj->model[0]].unk18 |= 4;
    obj->trans.x = x;
    obj->trans.y = y;
    obj->trans.z = z;
}

#ifdef NON_MATCHING
void func_8010571C_208ABC_PlatformPeril(omObjData* obj) {
    PPStrip* s = &D_801090D8_20C478_PlatformPeril[0];

    if (s->next == 0) {
        func_80105660_208A00_PlatformPeril(obj, NULL, 10, s->x[0] * 100, 0.0f, -(s->z[s->next] * 100), 0);
        s->obj = obj;
    } else {
        func_80105660_208A00_PlatformPeril(obj, s->obj, 0, s->x[s->next] * 100, 0.0f, -(s->z[s->next] * 100), 1);
    }
    obj->work[0] = 0;
    obj->work[1] = 0;
    obj->work[2] = 2;
    obj->work[3] = 0;
    s->next++;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_28_PlatformPeril/205BA0", func_8010571C_208ABC_PlatformPeril);
#endif

#ifdef NON_MATCHING
void func_8010587C_208C1C_PlatformPeril(omObjData* obj) {
    PPStrip* s = &D_801090D8_20C478_PlatformPeril[1];

    if (s->next == 0) {
        func_80105660_208A00_PlatformPeril(obj, NULL, 9, s->x[0] * 100, 0.0f, -(s->z[s->next] * 100), 0);
        s->obj = obj;
    } else {
        func_80105660_208A00_PlatformPeril(obj, s->obj, 0, s->x[s->next] * 100, 0.0f, -(s->z[s->next] * 100), 1);
    }
    obj->work[0] = 1;
    obj->work[1] = 0;
    obj->work[2] = 4;
    obj->work[3] = 0;
    s->next++;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_28_PlatformPeril/205BA0", func_8010587C_208C1C_PlatformPeril);
#endif

void func_801059E0_208D80_PlatformPeril(void) {
    u8 i;

    for (i = 0; i < 2; i++) {
        omAddObj(350, 1, 0, -1, func_8010571C_208ABC_PlatformPeril);
    }
    for (i = 0; i < 1; i++) {
        omAddObj(350, 1, 0, -1, func_8010587C_208C1C_PlatformPeril);
    }
}

void func_80105A70_208E10_PlatformPeril(omObjData* obj) {
    f32 s;

    switch (D_801093F0_20C790_PlatformPeril[obj->work[1]].state) {
    case 3:
        if (D_801093F0_20C790_PlatformPeril[obj->work[1]].timer >= 31) {
            D_800FC834_FD434[obj->model[1]].rot.x = PP_RAND1();
            D_800FC834_FD434[obj->model[1]].rot.y = PP_RAND1();
            D_800FC834_FD434[obj->model[1]].rot.z = PP_RAND1();
        }
        break;
    case 4:
        D_800FC834_FD434[obj->model[1]].pos.y -= D_801093F0_20C790_PlatformPeril[obj->work[1]].speed;
        s = 1.0f - (f32)(D_801093F0_20C790_PlatformPeril[obj->work[1]].timer - 50) / 10.0f;
        func_800297E8_2A3E8(obj->model[1], s, s, s);
        if (s < 0.0f) {
            func_800298A4_2A4A4(obj->model[1], 4, 4);
        }
        break;
    }
}

#ifdef NON_MATCHING
void func_80105D74_209114_PlatformPeril(omObjData* obj) {
    omObjData* other;
    u8 i;
    u8 n = 0;

    switch (obj->work[0]) {
    case 0:
        if (PP_CENTERZ - 100.0f - obj->trans.z < 1300.0f) {
            ((ColActorWork*)obj->unk_50)->unk_54 = 1;
            func_800298A4_2A4A4(obj->model[0], 4, 0);
            func_800298A4_2A4A4(obj->model[1], 4, 0);
            obj->work[0] = 1;
            for (i = 1; i < D_800F8FE0_F9BE0; i++) {
                other = D_800FC7B0_FD3B0[i];
                if (abs((s32)(obj->trans.z - other->trans.z)) < 100) {
                    if (n == 0 || (other = D_800FC7B0_FD3B0[i], abs((s32)(obj->trans.x - other->trans.x)) < 200)) {
                        obj->work[1] = ((GroundWork*)other->unk_50)->unk_04;
                    }
                    n++;
                }
            }
        }
        break;
    case 1:
        func_80105A70_208E10_PlatformPeril(obj);
        if (obj->trans.z - (PP_CENTERZ - 100.0f) > 1150.0) {
            func_800298A4_2A4A4(obj->model[0], 4, 4);
            func_800298A4_2A4A4(obj->model[1], 4, 4);
            if (D_80109120_20C4C0_PlatformPeril < 20) {
                obj->trans.x = D_801090F8_20C498_PlatformPeril[D_80109120_20C4C0_PlatformPeril] * 100;
                obj->trans.z = -(D_8010910C_20C4AC_PlatformPeril[D_80109120_20C4C0_PlatformPeril++] * 100);
                func_80029714_2A314(obj->model[1], obj->trans.x, 12.0f, obj->trans.z);
                func_800297E8_2A3E8(obj->model[1], 1.0f, 1.0f, 1.0f);
                obj->work[0] = 0;
            }
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_28_PlatformPeril/205BA0", func_80105D74_209114_PlatformPeril);
#endif

void func_80106040_2093E0_PlatformPeril(omObjData* obj) {
    ColActorWork* w;

    obj->unk_50 = func_80027154_27D54(sizeof(ColActorWork), 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, sizeof(ColActorWork));
    w = obj->unk_50;
    if (D_80109120_20C4C0_PlatformPeril == 0) {
        w->unk_55[0] = func_80018D64_19964(14, 0x299, 8);
        obj->model[0] = D_800F86D8_F92D8[(u8)w->unk_55[0]].unk00;
        D_801093B0_20C750_PlatformPeril = w->unk_55[0];
    } else {
        w->unk_55[0] = func_8002109C_21C9C(D_801093B0_20C750_PlatformPeril, 8);
        obj->model[0] = D_800F86D8_F92D8[(u8)w->unk_55[0]].unk00;
    }
    obj->model[1] = LoadFormFile(1, 0x689);
    HmfModelObjAttrSet(obj->model[1], 0x80000000, 0);
    func_80029A8C_2A68C(obj->model[1]);
    func_8000C2A0_CEA0(obj, 3, 20, 0x28D, 8);
    func_800211E8_21DE8(w->unk_24, 0xF0);
    func_80021250_21E50(w->unk_24, 0xFF, 0xFF, 0xBE);
    HmfModelObjAttrSet(obj->model[0], 0x70000000, 0x70000000);
    obj->trans.x = D_801090F8_20C498_PlatformPeril[D_80109120_20C4C0_PlatformPeril] * 100;
    obj->trans.y = 200.0f;
    obj->trans.z = -(D_8010910C_20C4AC_PlatformPeril[D_80109120_20C4C0_PlatformPeril++] * 100);
    func_80029714_2A314(obj->model[1], obj->trans.x, 12.0f, obj->trans.z);
    obj->work[0] = 0;
    w->unk_44 = 0.0f;
    w->unk_48 = 40.0f;
    w->unk_34 = 100.0f;
    w->unk_78 = 0;
    w->unk_52 = 3;
    w->unk_7C = 2000;
    w->unk_50 = 0;
    w->unk_40 = 1.2f;
    *(u16*)&w->unk_55[1] = 0;
    w->unk_54 = 0;
    func_8000C37C_CF7C(obj, 2.5f, 2.5f, 2.5f);
    func_800297E8_2A3E8(obj->model[3], 2.0f, 2.0f, 2.0f);
    func_800298A4_2A4A4(obj->model[0], 4, 4);
    func_800298A4_2A4A4(obj->model[1], 4, 4);
    obj->func_ptr = func_80105D74_209114_PlatformPeril;
}

void func_80106314_2096B4_PlatformPeril(void) {
    u8 i;

    for (i = 0; i < 8; i++) {
        D_800F9CE0_FA8E0[D_800FA606_FB206++] = omAddObj(400, 5, 5, -1, func_80106040_2093E0_PlatformPeril);
    }
}

void func_801063A0_209740_PlatformPeril(u8 port) {
    f32 x = ContStkX[port];
    f32 y = ContStkY[port];
    f32 mag = func_800B1830_B2430(x * x + y * y);
    f32 a;

    if (func_800B75A8_B81A8(x, y) - D_80102770_103370[0].y < -180.0f) {
        a = 180.0f;
    } else {
        a = func_800B75A8_B81A8(x, y) - D_80102770_103370[0].y;
    }
    ContStkX[port] = mag * HuMathSin(a);
    ContStkY[port] = mag * func_800B7890_B8490(a);
}

#ifdef NON_MATCHING
void func_801064C4_209864_PlatformPeril(omObjData* obj) {
    MgWork* w = obj->unk_50;
    f32 t;

    if (D_801093F0_20C790_PlatformPeril[D_80109122_20C4C2_PlatformPeril].goal != 0) {
        if (abs((s32)obj->trans.x) > 350.0) {
            if (obj->trans.z < D_801093F0_20C790_PlatformPeril[D_80109122_20C4C2_PlatformPeril].z + 1700.0f + 20.0f) {
                obj->trans.z = D_801093F0_20C790_PlatformPeril[D_80109122_20C4C2_PlatformPeril].z + 1700.0f + 20.0f;
            }
        }
    if (w->unk_53 == D_80109122_20C4C2_PlatformPeril) {
        if (D_801093F0_20C790_PlatformPeril[w->unk_53].z + 1700.0f - 10.0f < obj->trans.z) {
            func_80108130_20B4D0_PlatformPeril(w->unk_57);
            obj->trans.z = D_801093F0_20C790_PlatformPeril[D_80109122_20C4C2_PlatformPeril].z + 1700.0f + 5.0f;
        }
    }
    if (D_801093F0_20C790_PlatformPeril[D_80109122_20C4C2_PlatformPeril].z + 1700.0f >= obj->trans.z + 10.0f && obj->trans.y > -1.0f) {
        obj->work[1] = 6;
        if (D_80109121_20C4C1_PlatformPeril == obj->work[0]) {
            if (D_80109142_20C4E2_PlatformPeril.b == 0) {
                t = obj->trans.x;
                if (t > 200.0f) {
                    D_80109140_20C4E0_PlatformPeril.b = 30;
                } else if (t < -300.0f) {
                    D_80109140_20C4E0_PlatformPeril.b = 60;
                } else {
                    D_80109140_20C4E0_PlatformPeril.b = 45;
                }
                D_80109142_20C4E2_PlatformPeril.b = 1;
            }
            D_80109140_20C4E0_PlatformPeril.a--;
            if (D_80109140_20C4E0_PlatformPeril.a != 0) {
                ContStkX[w->unk_57] = HuMathSin(D_80109140_20C4E0_PlatformPeril.b) * D_80109140_20C4E0_PlatformPeril.a;
                ContStkY[w->unk_57] = func_800B7890_B8490(D_80109140_20C4E0_PlatformPeril.b) * D_80109140_20C4E0_PlatformPeril.a;
            } else {
                D_80109142_20C4E2_PlatformPeril.a = 1;
                D_80109140_20C4E0_PlatformPeril.a = 1;
                func_80108130_20B4D0_PlatformPeril(w->unk_57);
                if (D_801093B2_20C752_PlatformPeril.state != 5 && D_801093B2_20C752_PlatformPeril.state != 6) {
                    if (D_80109126_20C4C6_PlatformPeril == 0) {
                        D_801093B2_20C752_PlatformPeril.state = 4;
                    } else {
                        D_801093B2_20C752_PlatformPeril.state = 6;
                    }
                }
            }
        }
        if (obj->trans.x > 300.0) {
            obj->trans.x = 300.0f;
        } else if (obj->trans.x < -300.0) {
            obj->trans.x = -300.0f;
        }
    }
    if (D_80109142_20C4E2_PlatformPeril.a != 0) {
        func_80108130_20B4D0_PlatformPeril(w->unk_57);
    }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_28_PlatformPeril/205BA0", func_801064C4_209864_PlatformPeril);
#endif

void func_801068B4_209C54_PlatformPeril(omObjData* obj) {
    MgWork* w = obj->unk_50;

    func_80108130_20B4D0_PlatformPeril(w->unk_57);
    ContStkX[w->unk_57] = 45;
    ContStkY[w->unk_57] = 45;
    if (obj->trans.z < 100.0f) {
        if (obj->trans.z > -200.0f) {
            D_80109124_20C4C4_PlatformPeril = 1;
            ContBtn[w->unk_57] |= 0x8000;
            ContBtnTrg[w->unk_57] |= 0x8000;
            return;
        }
    }
    if (obj->trans.z < -200.0f) {
        obj->work[1] = 2;
    }
}

void func_801069BC_209D5C_PlatformPeril(omObjData* obj) {
    u8 i;

    if (obj->work[1] != 5 && obj->trans.y < -500.0f) {
        if (obj->work[3] == 0) {
            func_800797DC_7A3DC(0x111, obj->work[0]);
            obj->work[3] = 1;
            for (i = 1; i < D_800F8FE0_F9BE0; i++) {
                func_8000C024_CC24(obj, i, 1);
            }
        } else {
            obj->work[3]++;
        }
        if (obj->trans.y < -2300.0f) {
            obj->work[1] = 5;
            D_80109123_20C4C3_PlatformPeril++;
            obj->trans.y = -2300.0f;
            func_800298A4_2A4A4(obj->model[0], 4, 4);
            func_800298A4_2A4A4(obj->model[1], 4, 4);
            if (D_80109126_20C4C6_PlatformPeril != 0 && D_80109128_20C4C8_PlatformPeril == obj->work[0]) {
                D_801093B2_20C752_PlatformPeril.state = 8;
            }
        }
    }
}

void func_80106B24_209EC4_PlatformPeril(omObjData* obj) {
    MgWork* w = obj->unk_50;
    PPPlat* p;
    f32 z;

    if (obj->work[1] == 1) {
        func_801068B4_209C54_PlatformPeril(obj);
        func_801063A0_209740_PlatformPeril(w->unk_57);
        D_80109550_20C8F0_PlatformPeril[obj->work[0]].dist = 9999.0f;
        func_80007790_8390(obj);
        func_80019378_19F78(obj);
    } else if (obj->work[1] != 0) {
        if (gPlayers[obj->work[0]].flags & 1) {
            func_80108E78_20C218_PlatformPeril(obj);
        }
        if (obj->work[1] == 6) {
            func_80108130_20B4D0_PlatformPeril(w->unk_57);
        }
        func_801064C4_209864_PlatformPeril(obj);
        func_801063A0_209740_PlatformPeril(w->unk_57);
        D_80109550_20C8F0_PlatformPeril[obj->work[0]].dist = 9999.0f;
        if (obj->work[1] != 5) {
            func_80007790_8390(obj);
            func_80019378_19F78(obj);
        }
    }
    p = &D_801093F0_20C790_PlatformPeril[w->unk_53];
    if (p->speed != 0 && p->state == 2 && p->timer == 0) {
        p->state = 3;
    }
    func_801069BC_209D5C_PlatformPeril(obj);
    z = obj->trans.z + 200.0f;
    if (z < D_80109040_20C3E0_PlatformPeril) {
        D_80109040_20C3E0_PlatformPeril = z;
    }
}

void func_80106CBC_20A05C_PlatformPeril(omObjData* obj) {
    s32 attr = 0x699;
    f32 lanes[4] = { -300.0f, -100.0f, 100.0f, 300.0f };
    MgWork* w;
    s32 dir;
    s32 file;
    s32 mot;
    u8 i;

    obj->work[0] = D_800FC87A_FD47A;
    dir = D_800CD438_CE038[gPlayers[D_800FC87A_FD47A].character].unk_04;
    file = D_800CD438_CE038[gPlayers[D_800FC87A_FD47A].character].unk_08;
    mot = D_800CD438_CE038[gPlayers[D_800FC87A_FD47A].character].unk_10;
    func_8000C6FC_D2FC(obj, dir, file, D_800FC87A_FD47A, attr, attr);
    func_8000BDC4_C9C4(obj, 9, dir | mot, attr, 2600.0f);
    func_80019E84_1AA84(obj, 0, dir, 1, 0);
    func_80019E84_1AA84(obj, 1, dir | 1, 1, 0);
    func_80019E84_1AA84(obj, 2, dir | 2, 1, 0);
    func_80019E84_1AA84(obj, 6, dir | 4, 1, 99);
    func_80019E84_1AA84(obj, 21, dir | 0x2E, 0, 0);
    func_80019E84_1AA84(obj, 13, dir | 0xC7, 1, 999);
    func_80019E84_1AA84(obj, 14, dir | 0xC8, 1, 999);
    obj->trans.x = lanes[D_801093C0_20C760_PlatformPeril[D_800FC87A_FD47A]];
    obj->trans.y = 1.0f;
    obj->trans.z = 300.0f;
    obj->work[1] = 0;
    obj->work[2] = 0;
    obj->work[3] = 0;
    func_8010816C_20B50C_PlatformPeril(gPlayers[obj->work[0]].cpu_difficulty, obj->work[0]);
    w = obj->unk_50;
    w->unk_50 = 0x200;
    w->unk_3C = 180.0f;
    func_8000BEB0_CAB0(obj, 30.0f);
    func_80029714_2A314(obj->model[1], obj->trans.x, 1.0f, obj->trans.z);
    for (i = 0; i < D_800F8FE0_F9BE0; i++) {
        func_8000C024_CC24(obj, i, 2);
    }
    obj->func_ptr = func_80106B24_209EC4_PlatformPeril;
    D_800FC87A_FD47A++;
    D_800F8FD0_F9BD0 = 1;
    ContStkX[w->unk_57] = 0;
    ContStkY[w->unk_57] = 0;
    ContBtn[w->unk_57] = 0;
    ContBtnTrg[w->unk_57] = 0;
    func_80007790_8390(obj);
}

void func_80106FEC_20A38C_PlatformPeril(void) {
    u8 i;

    func_8000C460_D060();
    func_8000C578_D178(0);
    D_800BF795_C0395 = 0;
    for (i = 0; i < 4; i++) {
        D_800FFFD8_100BD8[i] = omAddObj(500, 10, 60, -1, func_80106CBC_20A05C_PlatformPeril);
    }
}

#ifdef NON_MATCHING
void func_8010707C_20A41C_PlatformPeril(void) {
    u8 list[4];
    u8 n = 0;
    u8 i;

    switch (D_801093B2_20C752_PlatformPeril.state) {
    case 0:
        if (func_8008F618_90218() == 0 && D_80109145_20C4E5_PlatformPeril == 0) {
            PlaySound(0x4B0);
            D_80109145_20C4E5_PlatformPeril = 1;
        }
        break;
    case 1:
        func_800691FC_69DFC(0);
        D_801093B2_20C752_PlatformPeril.state = 2;
        break;
    case 2:
        D_801093B2_20C752_PlatformPeril.timer++;
        if (D_801093B2_20C752_PlatformPeril.timer == 30) {
            for (i = 0; i < 4; i++) {
                D_800FFFD8_100BD8[i]->work[1] = 1;
            }
            D_801093B2_20C752_PlatformPeril.state = 3;
            D_801093B2_20C752_PlatformPeril.timer = 0;
        }
        break;
    case 3:
        if (D_80109144_20C4E4_PlatformPeril == 0) {
            for (i = 0; i < 4; i++) {
                if (D_800FFFD8_100BD8[i]->work[1] == 6) {
                    list[n++] = i;
                }
            }
            if (n != 0) {
                D_80109121_20C4C1_PlatformPeril = list[PP_RAND() % n];
                func_800794A8_7A0A8(120);
                func_800691FC_69DFC(3);
                D_80109144_20C4E4_PlatformPeril = 1;
            }
            if (D_80109123_20C4C3_PlatformPeril == 4) {
                D_801093B2_20C752_PlatformPeril.state = 7;
            }
        }
        break;
    case 7:
        if (D_801093B2_20C752_PlatformPeril.timer == 10) {
            func_800794A8_7A0A8(75);
            func_800691FC_69DFC(3);
        } else if (func_80069538_6A138() == 2 && D_801093B2_20C752_PlatformPeril.timer >= 11 && D_801093B2_20C752_PlatformPeril.timer < 60) {
            func_800691FC_69DFC(19);
            PlayMusic(0x57);
        } else if (D_801093B2_20C752_PlatformPeril.timer == 150) {
            InitFadeOut(0, 20);
        } else if (func_8008F618_90218() == 0 && D_801093B2_20C752_PlatformPeril.timer >= 151) {
            omOvlReturnEx(1);
        }
        D_801093B2_20C752_PlatformPeril.timer++;
        break;
    case 6:
        if (D_80109126_20C4C6_PlatformPeril == 0) {
            switch (D_801093B2_20C752_PlatformPeril.timer) {
            case 0:
                PlayMusic(0x51);
                for (i = 0; i < 4; i++) {
                    if (i == D_80109121_20C4C1_PlatformPeril) {
                        func_80019B9C_1A79C(D_800FFFD8_100BD8[i], 13);
                        gPlayers[i].coins_mg_bonus += 10;
                    } else {
                        func_80019B9C_1A79C(D_800FFFD8_100BD8[i], 14);
                    }
                }
                func_800691FC_69DFC(6, gPlayers[D_80109121_20C4C1_PlatformPeril].character);
                break;
            case 10:
                func_800732B0_73EB0(D_800CD438_CE038[gPlayers[D_80109121_20C4C1_PlatformPeril].character].unk_04 | 0xC7);
                break;
            case 120:
                InitFadeOut(0, 20);
                break;
            default:
                if (func_8008F618_90218() == 0 && D_801093B2_20C752_PlatformPeril.timer >= 121) {
                    omOvlReturnEx(1);
                }
                break;
            }
        } else if (D_801093B2_20C752_PlatformPeril.timer == 15) {
            InitFadeOut(0, 20);
            gPlayers[D_80109121_20C4C1_PlatformPeril].coins_mg_bonus += 10;
        } else if (func_8008F618_90218() == 0 && D_801093B2_20C752_PlatformPeril.timer >= 16) {
            omOvlReturnEx(1);
        }
        D_801093B2_20C752_PlatformPeril.timer++;
        break;
    case 8:
        if (D_801093B2_20C752_PlatformPeril.timer == 0) {
            if (D_80109121_20C4C1_PlatformPeril == -1) {
                func_800794A8_7A0A8(75);
                func_800691FC_69DFC(3);
            }
        } else if (func_80069538_6A138() == 2 && D_801093B2_20C752_PlatformPeril.timer < 60) {
            InitFadeOut(0, 20);
        } else if (func_8008F618_90218() == 0 && D_801093B2_20C752_PlatformPeril.timer >= 61) {
            omOvlReturnEx(1);
        }
        D_801093B2_20C752_PlatformPeril.timer++;
        break;
    }
    func_8010796C_20AD0C_PlatformPeril();
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_28_PlatformPeril/205BA0", func_8010707C_20A41C_PlatformPeril);
#endif

void func_801075D0_20A970_PlatformPeril(omObjData* obj) {
    func_80102FE4_206384_PlatformPeril();
    func_80104BE4_207F84_PlatformPeril();
    func_801059E0_208D80_PlatformPeril();
    func_80106314_2096B4_PlatformPeril();
    func_80106FEC_20A38C_PlatformPeril();
    InitFadeIn(0, 16);
    obj->func_ptr = func_8010707C_20A41C_PlatformPeril;
}

void func_8010762C_20A9CC_PlatformPeril(void) {
    osViBlack(0);
    omOvlReturnEx(1);
}

void func_80107650_20A9F0_PlatformPeril(omObjData* obj) {
    if (func_8008F618_90218() == 0) {
        obj->func_ptr = func_8010762C_20A9CC_PlatformPeril;
    }
}

void func_80107688_20AA28_PlatformPeril(omObjData* obj) {
    if (D_801011FC_101DFC == 1) {
        InitFadeOut(0, 20);
        obj->func_ptr = func_80107650_20A9F0_PlatformPeril;
    }
}

#ifdef NON_MATCHING
void func_801076D0_20AA70_PlatformPeril(PPCamKey* k) {
    omObjData** winner;

    k->time = 45.0f;
    k->zoom = (s32)D_800F94A8_FA0A8[0];
    k->center.x = D_801013B0_101FB0[0].x;
    k->center.y = D_801013B0_101FB0[0].y;
    k->center.z = D_801013B0_101FB0[0].z;
    k->rot.x = D_80102770_103370[0].x;
    k->rot.y = D_80102770_103370[0].y;
    k->rot.z = D_80102770_103370[0].z;
    k++;
    k->time = 0.0f;
    k->zoom = 550;
    winner = &D_800FFFD8_100BD8[D_80109121_20C4C1_PlatformPeril];
    k->center.x = (*winner)->trans.x + 15.0f;
    k->center.y = (*winner)->trans.y + 100.0f;
    k->center.z = (*winner)->trans.z - 50.0f;
    k->rot.x = 340.0f;
    k->rot.y = 160.0f;
    k->rot.z = 0.0f;
    k++;
    k->time = 0.0f;
    k->zoom = 0;
    k->center.x = 0.0f;
    k->center.y = 0.0f;
    k->center.z = 0.0f;
    k->rot.x = 0.0f;
    if (k->rot.x < ((MgWork*)(*winner)->unk_50)->unk_3C) {
        k->rot.y = ((MgWork*)(*winner)->unk_50)->unk_3C;
    } else {
        k->rot.y = -((MgWork*)D_800FFFD8_100BD8[D_80109121_20C4C1_PlatformPeril]->unk_50)->unk_3C;
    }
    k->rot.z = 0.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_28_PlatformPeril/205BA0", func_801076D0_20AA70_PlatformPeril);
#endif

void func_80107844_20ABE4_PlatformPeril(PPCamKey* k, f32 t) {
    D_800F94A8_FA0A8[0] = (f32)k[0].zoom + ((f32)k[1].zoom - (f32)k[0].zoom) * t;
    D_801013B0_101FB0[0].x = (k[1].center.x - k[0].center.x) * t + k[0].center.x;
    D_801013B0_101FB0[0].y = (k[1].center.y - k[0].center.y) * t + k[0].center.y;
    D_801013B0_101FB0[0].z = (k[1].center.z - k[0].center.z) * t + k[0].center.z;
    D_80102770_103370[0].x = (k[1].rot.x - k[0].rot.x) * t + k[0].rot.x;
    D_80102770_103370[0].y = (k[1].rot.y - k[0].rot.y) * t + k[0].rot.y;
    D_80102770_103370[0].z = (k[1].rot.z - k[0].rot.z) * t + k[0].rot.z;
}

#ifdef NON_MATCHING
void func_8010796C_20AD0C_PlatformPeril(void) {
    PPCamKey* k;
    f32 s;

    if (D_80102770_103370[0].x > 360.0f) {
        D_80102770_103370[0].x -= 360.0f;
    } else if (D_80102770_103370[0].x < 0.0f) {
        D_80102770_103370[0].x += 360.0f;
    }
    if (D_80102770_103370[0].y > 360.0f) {
        D_80102770_103370[0].y -= 360.0f;
    } else if (D_80102770_103370[0].y < 0.0f) {
        D_80102770_103370[0].y += 360.0f;
    }
    switch ((enum PPFlowState)D_801093B2_20C752_PlatformPeril.state) {
    case 0:
        D_801091C8_20C568_PlatformPeril = (f32)D_801091CC_20C56C_PlatformPeril.b / D_80109148_20C4E8_PlatformPeril[D_801091CC_20C56C_PlatformPeril.a].time;
        s = HuMathSin(D_801091C8_20C568_PlatformPeril * 90.0);
        func_80107844_20ABE4_PlatformPeril(&D_80109148_20C4E8_PlatformPeril[D_801091CC_20C56C_PlatformPeril.a], s * HuMathSin(D_801091C8_20C568_PlatformPeril * 90.0));
        if ((f32)++D_801091CC_20C56C_PlatformPeril.b >= D_80109148_20C4E8_PlatformPeril[D_801091CC_20C56C_PlatformPeril.a].time) {
            D_801091CC_20C56C_PlatformPeril.b = 0;
            if (++D_801091CC_20C56C_PlatformPeril.a >= 3) {
                D_801091C8_20C568_PlatformPeril = 0.0f;
                D_801093B2_20C752_PlatformPeril.state = 1;
            }
            if (D_801091CC_20C56C_PlatformPeril.b == 0 && D_801091CC_20C56C_PlatformPeril.a == 2) {
                PlayMusic(0x24);
            }
        }
        break;
    case 3:
        D_801013B0_101FB0[0].z = D_80109040_20C3E0_PlatformPeril;
        break;
    case 4:
        func_801076D0_20AA70_PlatformPeril(D_801093B8_20C758_PlatformPeril);
        D_801091C8_20C568_PlatformPeril = 0.0f;
        D_801091CC_20C56C_PlatformPeril.a = 0;
        D_801093B2_20C752_PlatformPeril.state = 5;
        break;
    case 5:
        D_801091C8_20C568_PlatformPeril = (f32)D_801091CC_20C56C_PlatformPeril.b / D_801093B8_20C758_PlatformPeril[D_801091CC_20C56C_PlatformPeril.a].time;
        s = HuMathSin(D_801091C8_20C568_PlatformPeril * 90.0);
        func_80107844_20ABE4_PlatformPeril(&D_801093B8_20C758_PlatformPeril[D_801091CC_20C56C_PlatformPeril.a], s * HuMathSin(D_801091C8_20C568_PlatformPeril * 90.0));
        s = HuMathSin(D_801091C8_20C568_PlatformPeril * 90.0);
        k = &D_801093B8_20C758_PlatformPeril[D_801091CC_20C56C_PlatformPeril.a];
        ((MgWork*)D_800FFFD8_100BD8[D_80109121_20C4C1_PlatformPeril]->unk_50)->unk_3C =
            (k[1].rot.y - k[2].rot.y) * s * HuMathSin(D_801091C8_20C568_PlatformPeril * 90.0) + k[2].rot.y;
        if ((f32)++D_801091CC_20C56C_PlatformPeril.b >= k->time) {
            D_801091CC_20C56C_PlatformPeril.b = 0;
            if (++D_801091CC_20C56C_PlatformPeril.a != 0) {
                D_801093B2_20C752_PlatformPeril.state = 6;
            }
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_28_PlatformPeril/205BA0", func_8010796C_20AD0C_PlatformPeril);
#endif

#ifdef NON_MATCHING
void func_80107DA0_20B140_PlatformPeril(void) {
    PPFlow* f;
    u8 i;
    u8 j;

    f = &D_801093B2_20C752_PlatformPeril;
    f->state = 0;
    f->timer = 0;
    for (i = 0; i < 3; i++) {
        D_80109550_20C8F0_PlatformPeril[i].kind = 0;
        D_80109550_20C8F0_PlatformPeril[i].dist = 9999.0f;
    }
    for (i = 0; i < 4; i++) {
        D_801093C0_20C760_PlatformPeril[i] = PP_RAND() % 4;
        for (j = 0; j < i; j++) {
            if (D_801093C0_20C760_PlatformPeril[j] == D_801093C0_20C760_PlatformPeril[i]) {
                i--;
                break;
            }
        }
    }
    D_801093BC_20C75C_PlatformPeril = func_80027154_27D54(5 * sizeof(PPCloud), 0x7918);
    D_801093B8_20C758_PlatformPeril = func_80027154_27D54(3 * sizeof(PPCamKey), 0x7918);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_28_PlatformPeril/205BA0", func_80107DA0_20B140_PlatformPeril);
#endif

const char D_80109378_20C718_PlatformPeril[] = "\202r\202s\202`\202q\202s";
const char D_80109384_20C724_PlatformPeril[] = "\202e\202h\202m\202h\202r\202g";
const char D_80109394_20C734_PlatformPeril[] = "\202c\202q\202`\202v";

void func_80107EEC_20B28C_PlatformPeril(void) {
    omObjData* obj;
    u8 i = 0;

    func_8002D4D0_2E0D0(50);
    func_80020D20_21920(32);
    omInitObjMan(50, 0);
    func_80079128_79D28();
    func_80026DAC_279AC(0, 0x40, 0x40, 0x40);
    func_80026DAC_279AC(1, 0x40, 0x40, 0x60);
    func_80026E00_27A00(1, 0.0f, 100.0f, 100.0f);
    obj = omAddObj(0x7FDA, 0, 0, -1, func_80079FF4_7ABF4);
    obj->work[0] = 1;
    omSetStatBit(obj, 0xA0);
    func_80018E30_19A30(1);
    func_80018F58_19B58(1);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 26.2f, 80.0f, 8000.0f);
    if (_CheckFlag(0xC) != 0) {
        D_80109126_20C4C6_PlatformPeril = 1;
        for (; i < 4; i++) {
            if (!(gPlayers[i].flags & 1)) {
                D_80109128_20C4C8_PlatformPeril = i;
            }
        }
    }
    D_800FA606_FB206 = 0;
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    func_80107DA0_20B140_PlatformPeril();
    omAddObj(1000, 0, 0, -1, func_801075D0_20A970_PlatformPeril);
    omAddObj(1000, 0, 0, -1, func_80107688_20AA28_PlatformPeril);
    func_8007273C_7333C((char*)D_80109378_20C718_PlatformPeril, 1);
    func_8007273C_7333C((char*)D_80109384_20C724_PlatformPeril, 1);
    func_8007273C_7333C((char*)D_80109394_20C734_PlatformPeril, 1);
}

