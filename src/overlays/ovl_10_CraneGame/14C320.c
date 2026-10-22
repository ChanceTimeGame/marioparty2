#include "ovl_10.h"

void func_80102800_14C320_CraneGame(void) {
    s16 var_a0;
    u8 temp_s0;
    s16 i;

    func_8002D4D0_2E0D0(0x32);
    func_8002F290_2FE90(D_800F9D30_FA930, 0x40);
    func_80020D20_21920(0x20);
    omInitObjMan(0x32, 0);
    func_80079128_79D28();
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_80079E60_7AA60), 0xA0);
    func_80018E30_19A30(1);
    temp_s0 = func_80018E78_19A78();
    ScissorSet(temp_s0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(temp_s0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 30.0f, 1000.0f, 4000.0f);
    D_800FA606_FB206 = 0;
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    D_8010C174_155C94_CraneGame = 0;
    D_8010C176_155C96_CraneGame = 0;
    D_8010C17C_155C9C_CraneGame = 900;
    D_8010C17E_155C9E_CraneGame = 0x78;
    D_8010C17A_155C9A_CraneGame = 0;
    D_8010C178_155C98_CraneGame = 1;
    D_8010C182_155CA2_CraneGame = _CheckFlag(0xC);
    D_8010C180_155CA0_CraneGame = 0;
    D_8010C184_155CA4_CraneGame = 0;
    D_8010C258_155D78_CraneGame = 0;
    D_8010D234_156D54_CraneGame = 0;
    for (i = 0; i < ARRAY_COUNT(D_8010CE30_156950_CraneGame); i++) {
        D_8010CE30_156950_CraneGame[i] = 0;
    }
    D_8010D230_156D50_CraneGame = omAddObj(3, 0, 0, -1, func_80102CFC_14C81C_CraneGame);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0] = omAddObj(8, 1, 0, -1, func_80103974_14D494_CraneGame);
    omSetStatBit(D_800FC7B0_FD3B0[D_800F8FE0_F9BE0], 0xA0);
    D_800F8FE0_F9BE0++;
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(4, 2, 0x32, -1, func_80104854_14E374_CraneGame);

    for (i = 0; i < 6; i++) {
        D_800F9CE0_FA8E0[D_800FA606_FB206] = omAddObj(5, 1, 0, -1, func_80106F00_150A20_CraneGame);
        omSetStatBit(D_800F9CE0_FA8E0[D_800FA606_FB206], 0xA0);
        D_800FA606_FB206++;
    }

    for (i = 0; i < ARRAY_COUNT(D_8010C188_155CA8_CraneGame); i++) {
        D_8010C188_155CA8_CraneGame[i] = i;
    }

    for (i = 0; i < 36; i++) {
        u32 index1;
        u32 index2;
        s16 temp;

        index1 = (rand8() * 3);
        index1 = index1 >> 7;
        index2 = (rand8() * 3);

        temp = D_8010C188_155CA8_CraneGame[index1];
        index2 = index2 >> 7;

        D_8010C188_155CA8_CraneGame[index1] = D_8010C188_155CA8_CraneGame[index2];
        D_8010C188_155CA8_CraneGame[index2] = temp;
    }

    func_80026DAC_279AC(0, 0x80, 0x80, 0x80);
    func_80026DAC_279AC(1, 0xFF, 0xFF, 0xFF);
    func_80026E00_27A00(1, 0.0f, 64.0f, 192.0f);
    D_800FA610_FB210 = 2200.0f;
    D_800FD474_FE074.x = -35.0f;
    D_800FD474_FE074.y = 0.0f;
    D_800FD474_FE074.z = 0.0f;
    D_8010274C_10334C.x = 0.0f;
    D_8010274C_10334C.y = 420.0f;
    D_8010274C_10334C.z = 300.0f;
    func_80109A70_153590_CraneGame();
    func_80107F70_151A90_CraneGame();
    func_801082B8_151DD8_CraneGame(0.0f);
    for (i = 0, var_a0 = 0; i < 4; i++) {
        if (gPlayers[i].group == 0) {
            D_8010C194_155CB4_CraneGame = i;
        } else {
            D_8010C196_155CB6_CraneGame[var_a0++] = i;
        }
    }
    D_8010C1A0_155CC0_CraneGame = 0;
}

void func_80102CFC_14C81C_CraneGame(omObjData* obj) {
    obj->func_ptr = &func_80102D28_14C848_CraneGame;
    InitFadeIn(0, 0x10);
}

void func_80102D28_14C848_CraneGame(omObjData* obj) {
    s16 i;

    switch (D_8010C174_155C94_CraneGame) {
    case 0:
        if (D_8010C176_155C96_CraneGame != 0) {
            if (--D_8010C17E_155C9E_CraneGame == 0) {
                D_8010C174_155C94_CraneGame++;
                D_8010C17E_155C9E_CraneGame = 0x3C;
                func_800691FC_69DFC(0);
            }
        }
        if (D_8010C258_155D78_CraneGame >= 4 && D_8010B760_155280_CraneGame == 0) {
            PlayMusic(0x29);
            D_8010B760_155280_CraneGame++;
        }
        break;
    case 1:
        if (--D_8010C17E_155C9E_CraneGame == 0) {
            D_8010C174_155C94_CraneGame++;
            D_8010C178_155C98_CraneGame = 0;
            D_8010C170_155C90_CraneGame = omAddObj(7, 0, 0, -1, func_80103250_14CD70_CraneGame);
            D_8010C17E_155C9E_CraneGame = 0x10;
        }
        break;
    case 2:
        if (D_8010C178_155C98_CraneGame == 0 && D_8010C17C_155C9C_CraneGame != 0) {
            D_8010C17C_155C9C_CraneGame -= 1;
        }
        if (D_8010C17A_155C9A_CraneGame != 0) {
            D_8010C178_155C98_CraneGame = 1;
            if (--D_8010C17E_155C9E_CraneGame == 0) {
                if (D_8010C1A0_155CC0_CraneGame == 3) {
                    gPlayers[D_8010C194_155CB4_CraneGame].coins_mg_bonus += 10;
                } else {
                    for (i = 0; i < 3; i++) {
                        gPlayers[D_8010C196_155CB6_CraneGame[i]].coins_mg_bonus += 10;
                    }
                }
                if (D_8010C182_155CA2_CraneGame == 0) {
                    D_8010C174_155C94_CraneGame++;
                } else {
                    D_8010C174_155C94_CraneGame = 4;
                    D_8010C17E_155C9E_CraneGame = 0x3C;
                }
                func_800691FC_69DFC(3);
                func_800794A8_7A0A8(0x28);
            }
        }
        break;
    case 3:
        if (func_80069538_6A138() == 2) {
            D_8010C174_155C94_CraneGame++;
            if (D_8010C1A0_155CC0_CraneGame == 3) {
                func_800691FC_69DFC(6, gPlayers[D_8010C194_155CB4_CraneGame].character);
                PlayMusic(0x51);
                D_8010C17E_155C9E_CraneGame = 0x78;
                D_8010C184_155CA4_CraneGame = 1;
            } else {
                func_800691FC_69DFC(0x15, gPlayers[D_8010C196_155CB6_CraneGame[0]].character,
                                    gPlayers[D_8010C196_155CB6_CraneGame[1]].character,
                                    gPlayers[D_8010C196_155CB6_CraneGame[2]].character);
                PlayMusic(0x52);
                D_8010C17E_155C9E_CraneGame = 0xA8;
                D_8010C184_155CA4_CraneGame = 2;
            }
        }
        break;
    case 4:
        if (--D_8010C17E_155C9E_CraneGame == 0) {
            D_8010C174_155C94_CraneGame = -1;
            D_8010C17A_155C9A_CraneGame = -1;
            if (D_8010C182_155CA2_CraneGame == 0) {
                func_80079614_7A214(0x28);
                func_800794A8_7A0A8(0x28);
            }
            InitFadeOut(0, 0x14);
        }
        break;
    }
    if (D_8010C17A_155C9A_CraneGame >= 0 && D_801011FC_101DFC != 0) {
        D_8010C17A_155C9A_CraneGame = -1;
        D_8010C174_155C94_CraneGame = -1;
        InitFadeOut(0, 0x14);
        func_80079614_7A214(0x28);
        func_800794A8_7A0A8(0x28);
    }
    func_801031EC_14CD0C_CraneGame();
}

void func_801031B8_14CCD8_CraneGame(void) {
    SprAnimKill(D_8010C19E_155CBE_CraneGame);
    SprKill(D_8010C19C_155CBC_CraneGame);
    func_80103F38_14DA58_CraneGame();
}

void func_801031EC_14CD0C_CraneGame(void) {
    if (D_8010C17A_155C9A_CraneGame < 0 && func_8008F618_90218() == 0) {
        func_80109AA8_1535C8_CraneGame();
        func_80108038_151B58_CraneGame();
        func_80107EC0_1519E0_CraneGame();
        func_801031B8_14CCD8_CraneGame();
        func_80079464_7A064();
        omOvlReturnEx(1);
    }
}

void func_80103250_14CD70_CraneGame(omObjData* obj) {
    obj->work[0] = func_800691FC_69DFC(0xA, D_8010C17C_155C9C_CraneGame / 30, 0xA0, 0x18);
    obj->func_ptr = &func_801032C8_14CDE8_CraneGame;
}

void func_801032C8_14CDE8_CraneGame(omObjData* obj) {
    func_8006D4D0_6E0D0((D_8010C17C_155C9C_CraneGame + 29) / 30);
    if (D_8010C17A_155C9A_CraneGame != 0) {
        obj->func_ptr = NULL;
        func_8006D518_6E118();
    }
}

s32 func_80103338_14CE58_CraneGame(omObjData* obj) {
    f32 temp_f12;
    s32 var_s0;
    HmfMotionObj* temp_v0;

    temp_v0 = D_800FC834_FD434[D_8010C186_155CA6_CraneGame].hmf->unk84;
    temp_f12 = (temp_v0->unk04.x - obj->trans.x) * (temp_v0->unk04.x - obj->trans.x) +
               (temp_v0->unk04.z - obj->trans.z) * (temp_v0->unk04.z - obj->trans.z);
    var_s0 = 0;
    if (sqrtf(temp_f12) < 180.0) {
        var_s0 = 1;
    }
    return var_s0;
}

s16 func_801033E4_14CF04_CraneGame(f32 arg0) {
    f32 temp_f0;
    f32 var_f12;
    s16 var_s4;
    HmfData* temp_s2;
    HmfVtx* var_s0;
    HmfVtx* var_s1;
    s16 i;

    var_s4 = 0;
    temp_s2 = D_800FC834_FD434[D_8010C186_155CA6_CraneGame].hmf;
    var_s1 = temp_s2->unk40;
    var_s0 = temp_s2->unk44[D_800FDBE0_FE7E0];

    for (i = 0; i < temp_s2->unk18; i++) {
        var_f12 = (temp_s2->unk84->unk04.y + var_s0->unk02 - arg0) / 4.0;
        if (var_f12 < -90.0) {
            var_f12 = -90.0f;
        }
        if (var_f12 > 90.0) {
            var_f12 = 90.0f;
        }
        temp_f0 = func_800B7890_B8490(var_f12);
        if (temp_f0 != 0.0) {
            var_s4 = 1;
        }
        var_s0->unk00 = (var_s1->unk00 + (var_s1->unk00 * 0.8 * temp_f0));
        var_s0->unk04 = (var_s1->unk04 + (var_s1->unk04 * 0.8 * temp_f0));
        var_s1++;
        var_s0++;
    }

    return var_s4;
}

s16 func_801035C0_14D0E0_CraneGame(f32* x, f32* y, f32* z, f32 dx, f32 dy, f32 dz, f32 r, s16 mode) {
    Vec d;
    HmfData* m;
    f32 dist;
    f32 h;
    f32 f;
    s16 ret;

    ret = 0;
    if (mode != 2) {
        m = D_800FC834_FD434[D_8010C186_155CA6_CraneGame].hmf;
        d.x = m->unk84->unk04.x - *x;
        d.z = m->unk84->unk04.z - *z;
        dist = sqrtf(d.x * d.x + d.z * d.z);
        if (dist < r + 280.0) {
            h = *y - r;
            if (h < 300.0) {
                if (mode == 0 && h - dy >= 300.0) {
                    *y = r + 300.0;
                } else {
                    f = 300.0 - (*y - r);
                    if (r < f) {
                        f = r;
                    }
                    h = HuMathSin(f / r * 90.0) * r + 280.0;
                    if (dist != 0.0) {
                        d.x /= dist;
                        d.z /= dist;
                        *x = m->unk84->unk04.x + -d.x * h;
                        *z = m->unk84->unk04.z + -d.z * h;
                    }
                }
                ret = 2;
            }
        }
    }
    if (*x < -360.0) {
        *x = -360.0f;
        ret |= 1;
    }
    if (*x > 420.0) {
        *x = 420.0f;
        ret |= 1;
    }
    if (*z < -360.0) {
        *z = -360.0f;
        ret |= 1;
    }
    if (*z > 640.0) {
        *z = 640.0f;
        ret |= 1;
    }
    return ret;
}

void func_801038FC_14D41C_CraneGame(void) {
    D_8010C254_155D74_CraneGame = (rand8() * 0.5f / 256.0f - 0.25f) * 10.0;
}

void func_80103974_14D494_CraneGame(omObjData* obj) {
    HmfData* hmf;
    s32 i;

    obj->func_ptr = func_80103CB8_14D7D8_CraneGame;
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    obj->scale.z = 1.0f;
    obj->scale.y = 1.0f;
    obj->scale.x = 1.0f;
    obj->model[0] = D_8010C186_155CA6_CraneGame = func_80018A30_19630(0x200001, 0xA9);
    func_80029714_2A314(obj->model[0], 0.0f, 0.0f, 0.0f);
    func_8002979C_2A39C(obj->model[0], 0.0f, 0.0f, 0.0f);
    func_800297E8_2A3E8(obj->model[0], 1.0f, 1.0f, 1.0f);
    func_8002A00C_2AC0C(obj->model[0]);
    func_80108114_151C34_CraneGame(obj->model[0]);
    func_801082E8_151E08_CraneGame(1.75f);
    D_8010C19E_155CBE_CraneGame = func_8001A2F8_1AEF8(0x200011);
    D_8010C19C_155CBC_CraneGame = SprCreate(1, 0);
    SprAnimSet(D_8010C19C_155CBC_CraneGame, 0, D_8010C19E_155CBE_CraneGame, 0);
    SprAttrSet(D_8010C19C_155CBC_CraneGame, 0, 0x4000);
    SprPosSet(D_8010C19C_155CBC_CraneGame, 0, 0xA0, 0x78);
    for (i = 0; i < 7; i++) {
        obj->model[i + 1] = func_80018A30_19630(D_8010B7B8_1552D8_CraneGame[i], 0xA9);
        func_80029714_2A314(obj->model[i + 1], D_8010B764_155284_CraneGame[i].x, D_8010B764_155284_CraneGame[i].y, -600.0f);
        func_8002979C_2A39C(obj->model[i + 1], 0.0f, 0.0f, 0.0f);
        func_800297E8_2A3E8(obj->model[i + 1], D_8010B764_155284_CraneGame[i].scale, D_8010B764_155284_CraneGame[i].scale, 1.0f);
        D_8010C1A8_155CC8_CraneGame[i].a = D_8010B764_155284_CraneGame[i].x;
        D_8010C1A8_155CC8_CraneGame[i].b = 1000.0f;
        D_8010C1E0_155D00_CraneGame[i] = 1000.0f - D_8010B764_155284_CraneGame[i].y;
        D_8010C200_155D20_CraneGame[i].b = 0.0f;
        D_8010C200_155D20_CraneGame[i].a = 0.0f;
        D_8010C238_155D58_CraneGame[i] = 0.0f;
    }
    D_8010C1A4_155CC4_CraneGame = func_8002838C_28F8C(0x1080, func_80103FC8_14DAE8_CraneGame, 2);
    hmf = D_800FC834_FD434[D_8010C1A4_155CC4_CraneGame].hmf;
    for (i = 0; i < D_800FDBCA_FE7CA; i++) {
        hmf->unk44[i] = HuMemAlloc(0xE0);
    }
    D_8010C254_155D74_CraneGame = 0.0f;
}

void func_80103CB8_14D7D8_CraneGame(omObjData* obj) {
    HmfModel* m;
    f32 len;
    f32 dx;
    f32 dy;
    f32 d;
    f32 px;
    f32 py;
    s16 i;

    for (i = 0; i < 7; i++) {
        m = &D_800FC834_FD434[obj->model[i + 1]];
        len = D_8010C1E0_155D00_CraneGame[i];
        px = m->pos.x;
        py = m->pos.y;
        px += D_8010C200_155D20_CraneGame[i].a + D_8010C254_155D74_CraneGame;
        py += D_8010C200_155D20_CraneGame[i].b + -4.0;
        dx = px - D_8010C1A8_155CC8_CraneGame[i].a;
        dy = py - D_8010C1A8_155CC8_CraneGame[i].b;
        d = len / sqrtf(dx * dx + dy * dy);
        dx *= d;
        dy *= d;
        px = dx + D_8010C1A8_155CC8_CraneGame[i].a;
        py = dy + D_8010C1A8_155CC8_CraneGame[i].b;
        D_8010C200_155D20_CraneGame[i].a = px - m->pos.x;
        D_8010C200_155D20_CraneGame[i].b = py - m->pos.y;
        m->pos.x = px;
        m->pos.y = py;
        D_8010C238_155D58_CraneGame[i] = D_8010C200_155D20_CraneGame[i].a * 4.0f;
        if (m->rot.y != D_8010C238_155D58_CraneGame[i]) {
            if (D_8010C238_155D58_CraneGame[i] < m->rot.y) {
                m->rot.y -= 1.0f;
                if (m->rot.y < D_8010C238_155D58_CraneGame[i]) {
                    m->rot.y = D_8010C238_155D58_CraneGame[i];
                }
            } else {
                m->rot.y += 1.0f;
                if (D_8010C238_155D58_CraneGame[i] < m->rot.y) {
                    m->rot.y = D_8010C238_155D58_CraneGame[i];
                }
            }
        }
    }
    D_8010C254_155D74_CraneGame = 0.0f;
}

void func_80103F38_14DA58_CraneGame(void) {
    HmfData* hmf;
    s16 i;

    hmf = D_800FC834_FD434[D_8010C1A4_155CC4_CraneGame].hmf;
    for (i = 0; i < D_800FDBCA_FE7CA; i++) {
        HuMemFree(hmf->unk44[i]);
    }
}

void func_80103FC8_14DAE8_CraneGame(Gfx** gfx) {
    omObjData* bg;
    HmfData* hmf;
    HmfModel* m;
    HmfVtx* v;
    HmfVtx* vtx;
    s16 i;

    bg = D_800FC7B0_FD3B0[0];
    hmf = D_800FC834_FD434[D_800F9564_FA164].hmf;
    gSPDisplayList((*gfx)++, osVirtualToPhysical(D_8010B8E8_155408_CraneGame));
    func_800204C0_210C0(0, gfx);
    gSPDisplayList((*gfx)++, osVirtualToPhysical(D_8010B928_155448_CraneGame));
    v = vtx = hmf->unk44[D_800FDBE0_FE7E0];
    for (i = 0; i < 7; i++) {
        m = &D_800FC834_FD434[bg->model[i + 1]];
        v->unk00 = D_8010C1A8_155CC8_CraneGame[i].a;
        v->unk02 = D_8010C1A8_155CC8_CraneGame[i].b;
        v->unk04 = m->pos.z;
        v->unk08 = v->unk0A = 0;
        v->unk0C[0] = v->unk0C[1] = v->unk0C[2] = 0x20;
        v->unk0F = 0xFF;
        v++;
        v->unk00 = m->pos.x;
        v->unk02 = m->pos.y;
        v->unk04 = m->pos.z;
        v->unk08 = v->unk0A = 0;
        v->unk0C[0] = v->unk0C[1] = v->unk0C[2] = 0x20;
        v->unk0F = 0xFF;
        v++;
    }
    for (i = 0; i < 7; i++) {
        gSPVertex((*gfx)++, &vtx[i * 2], 2, 0);
        CG_SP_LINE3D_01((*gfx)++);
    }
    gDPPipeSync((*gfx)++);
}

s16 func_8010422C_14DD4C_CraneGame(f32 x, f32 y, f32 z, f32 r) {
    f32 dx;
    f32 dz;
    f32 d;
    f32 rad;
    f32 best;
    s16 sel;
    s16 i;
    omObjData* o;
    CGWork* w;

    sel = -1;
    best = 9999.0f;
    for (i = 0; i < D_800FA606_FB206; i++) {
        o = D_800F9CE0_FA8E0[i];
        w = o->unk_50;
        if (w->unk34 > w->unk38) {
            rad = w->unk34;
        } else {
            rad = w->unk38;
        }
        if (w->unk50 >= 0) {
            dx = o->trans.x - x;
            if (fabs(dx) < rad + r) {
                dz = o->trans.z - z;
                if (fabs(dz) < rad + r) {
                    d = sqrtf(dx * dx + dz * dz);
                    if (d < best && d < 120.0) {
                        best = d;
                        sel = i;
                    }
                }
            }
        }
    }
    return sel;
}

s16 func_801043D8_14DEF8_CraneGame(f32 arg0, f32 arg1, f32 arg2, s16 arg3) {
    f32 distanceSquared;
    f32 clampedDistance;
    s16 ret;
    omObjData* temp_v0;

    temp_v0 = D_800F9CE0_FA8E0[arg3];
    distanceSquared = ((temp_v0->trans.x - arg0) * (temp_v0->trans.x - arg0)) + ((temp_v0->trans.z - arg1) * (temp_v0->trans.z - arg1));
    clampedDistance = sqrtf(distanceSquared);

    clampedDistance -= arg2;
    if (clampedDistance < 0.0) {
        clampedDistance = 0.0f;
    }
    if (clampedDistance < 40.0) {
        ret = 0;
    } else if (clampedDistance < 80.0) {
        ret = 1;
    } else if (clampedDistance < 120.0) {
        ret = 2;
    } else {
        ret = -1;
    }
    return ret;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/14C320", func_801044E0_14E000_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/14C320", func_801046E8_14E208_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/14C320", func_80104854_14E374_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/14C320", func_80104CB0_14E7D0_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/14C320", func_80106268_14FD88_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/14C320", func_8010646C_14FF8C_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/14C320", func_80106568_150088_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/14C320", func_80106A28_150548_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/14C320", func_80106C98_1507B8_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/14C320", func_80106D58_150878_CraneGame);

__asm__(".section .rodata");
const u32 D_8010C000_155B20_CraneGame[18] = { 0x00020000, 0x000F000E, 0x00030000, 0x0010000C, 0x00040000, 0x0010000C, 0x00050000, 0x0010000C, 0x00060000, 0x00110010, 0x00070000, 0x00130013, 0x00080001, 0x0004000F, 0x00090001, 0x0004000F, 0x000A0001, 0x0004000F };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/14C320", func_80106F00_150A20_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/14C320", func_80107460_150F80_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/14C320", func_8010755C_15107C_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/14C320", func_80107DD4_1518F4_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/14C320", func_80107EC0_1519E0_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/14C320", func_80107F40_151A60_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/14C320", func_80107F70_151A90_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/14C320", func_80108038_151B58_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/14C320", func_80108114_151C34_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/14C320", func_801081C8_151CE8_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/14C320", func_80108238_151D58_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/14C320", func_801082B8_151DD8_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/14C320", func_801082D0_151DF0_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/14C320", func_801082E8_151E08_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/14C320", func_801082F4_151E14_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/14C320", func_8010887C_15239C_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/14C320", func_80108D18_152838_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/14C320", func_80109024_152B44_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/14C320", func_801091D4_152CF4_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/14C320", func_801093A0_152EC0_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/14C320", func_801095A4_1530C4_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/14C320", func_801097A0_1532C0_CraneGame);
