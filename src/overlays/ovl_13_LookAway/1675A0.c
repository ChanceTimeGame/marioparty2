#include "common.h"
#include "ovl_13.h"

void func_80102800_1675A0_LookAway(void) {
    func_8010640C_16B1AC_LookAway();
}

void func_8010281C_1675BC_LookAway(u8 player) {
    ContBtn[gPlayers[player].port] = 0;
    ContBtnTrg[gPlayers[player].port] = 0;
    ContStkX[gPlayers[player].port] = 0;
    ContStkY[gPlayers[player].port] = 0;
}

u8 func_801028A0_167640_LookAway(u8 n, u64* used) {
    u64 m;
    u8 k;
    u8 i;

    m = *used;
    i = n;
    while (m != 0) {
        if (m & 1) {
            i--;
        }
        m >>= 1;
    }
    k = rand8() % i;
    m = *used;
    for (i = 0; i < n; i++) {
        if (m & 1) {
        } else if (k-- == 0) {
            break;
        }
        m >>= 1;
    }
    i = (i < n) ? i : 0;
    *used |= 1 << i;
    return i;
}

void func_801029F0_167790_LookAway(void) {
    s32 i;

    if (D_80106744_16B4E4_LookAway == 0) {
        D_80106744_16B4E4_LookAway = 1;
        for (i = 0; i < 2; i++) {
            Hu3DCamSetPerspective(i, 20.0f, 80.0f, 8000.0f);
            D_800F94A8_FA0A8[i] = 1000.0f;
            D_80102770_103370[i].x = 360.0f;
            D_80102770_103370[i].y = 0.0f;
            D_80102770_103370[i].z = 0.0f;
            D_801013B0_101FB0[i].x = 0.0f;
            D_801013B0_101FB0[i].y = 0.0f;
            D_801013B0_101FB0[i].z = 0.0f;
        }
    }
}

void func_80102AE0_167880_LookAway(omObjData* obj) {
    LAObj* st = &D_80106CD0_16BA70_LookAway[4];
    f32 s;

    if (D_801069A0_16B740_LookAway >= 3) {
        if (D_80106E28_16BBC8_LookAway <= 4.2f) {
            if (D_80106E2C_16BBCC_LookAway <= 0.14f) {
                D_80106E2C_16BBCC_LookAway += 0.02f;
            }
            st->unk_38 += st->unk_3C;
            s = st->unk_38 + 0.8f;
            func_800297E8_2A3E8(obj->model[1], s, s, s);
        }
    } else if (D_801069AE_16B74E_LookAway & 0x10) {
        func_80029E80_2AA80(obj->model[1], 1, 0);
        D_800FC834_FD434[obj->model[1]].rot.z += 1.0f;
        if (st->state != 0) {
            st->unk_38 -= 0.01f;
            if (st->unk_38 <= 0.0f) {
                st->unk_38 = 0.0f;
                st->state ^= 1;
            }
        } else {
            st->unk_38 += 0.01f;
            if (st->unk_38 >= 0.4f) {
                st->unk_38 = 0.4f;
                st->state ^= 1;
            }
        }
        s = st->unk_38 + 0.8f;
        func_800297E8_2A3E8(obj->model[1], s, s, s);
    } else if (D_801069AE_16B74E_LookAway & 0x20) {
        func_80029E80_2AA80(obj->model[1], 1, 1);
    }
}

void func_80102CE8_167A88_LookAway(omObjData* obj) {
    GroundWork* gw;

    D_80106C68_16BA08_LookAway[0] = func_8001A2F8_1AEF8(0x230000);
    D_80106DF4_16BB94_LookAway = SprCreate(1, 0);
    SprAttrReset(D_80106DF4_16BB94_LookAway, 0, -1);
    SprScaleSet(D_80106DF4_16BB94_LookAway, 0, 1.0f, 1.0f);
    SprAnimSet(D_80106DF4_16BB94_LookAway, 0, D_80106C68_16BA08_LookAway[0], 0);
    SprBankSet(D_80106DF4_16BB94_LookAway, 0, 0);
    SprAttrSet(D_80106DF4_16BB94_LookAway, 0, 0x5000);
    SprPosSet(D_80106DF4_16BB94_LookAway, 0, 160, 120);
    func_8008225C_82E5C(D_80106DF4_16BB94_LookAway, 0, 0);
    SprPrioSet(D_80106DF4_16BB94_LookAway, 0, 0xFFF0);
    obj->model[0] = LoadFormFile(0x230002, 0x2B9);
    obj->model[1] = LoadFormFile(0x230003, 0x2B9);
    func_80029E80_2AA80(obj->model[0], 2, 2);
    func_80029E80_2AA80(obj->model[1], 2, 2);
    func_80029E80_2AA80(obj->model[1], 1, 1);
    func_800297E8_2A3E8(obj->model[1], 1.0f, 1.0f, 1.0f);
    func_80029714_2A314(obj->model[1], 0.0f, 0.0f, 0.0f);
    obj->trans.y = -10.0f;
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = obj;
    obj->unk_50 = gw = func_80027154_27D54(0xB4, 0x7918);
    func_800B0EF0_B1AF0(gw, 0, 0xB4);
    gw->unk_03 = 1;
    gw->unk_04 = 0;
    func_8000BEA4_CAA4(obj, 20.0f);
    func_8000BE8C_CA8C(obj, 1.0f);
    func_8000BF24_CB24(D_800FC7B0_FD3B0[0], 0.0f, -550.0f, -500.0f, 550.0f, 500.0f);
    func_80029EDC_2AADC(obj->model[0], 2);
    func_80029EDC_2AADC(obj->model[1], 1);
    D_80106E28_16BBC8_LookAway = 0.2f;
    D_80106E2C_16BBCC_LookAway = -0.1f;
    obj->func_ptr = func_80102AE0_167880_LookAway;
}

void func_80102F90_167D30_LookAway(void) {
    func_8000C018_CC18(D_800F8FE0_F9BE0);
    D_80106CD0_16BA70_LookAway[4].obj = omAddObj(10, 2, 2, -1, func_80102CE8_167A88_LookAway);
}

void func_80102FD8_167D78_LookAway(Gfx** gfxp) {
    Gfx* gfx = *gfxp;
    s32 y;

    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gfx++, G_SHADE | G_SHADING_SMOOTH | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR |
                                    G_CULL_BOTH | G_FOG | G_LOD);
    gSPSetGeometryMode(gfx++, G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetTexturePersp(gfx++, G_TP_NONE);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gDPSetRenderMode(gfx++, G_RM_AA_TEX_EDGE, G_RM_AA_TEX_EDGE2);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);
    gDPLoadTLUT_pal256(gfx++, D_80106A64_16B804_LookAway->unk0C);
    for (y = 0; y < 48; y += 4) {
        gDPLoadTextureTile(gfx++, D_80106A64_16B804_LookAway->unk08, G_IM_FMT_RGBA, G_IM_SIZ_8b, 320, 48, 0, y, 319,
                           y + 4, 0, G_TX_WRAP, G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gDPSetTileSize(gfx++, G_TX_RENDERTILE, 0, 0, 320 << 2, 4 << 2);
        gSPTextureRectangle(gfx++, 0, (y + 96) << 2, 320 << 2, (y + 100) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10,
                            1 << 10);
    }
    *gfxp = gfx;
}

void func_801032FC_16809C_LookAway(void) {
}

void func_80103304_1680A4_LookAway(omObjData* obj) {
    D_80106C68_16BA08_LookAway[1] = func_8001A2F8_1AEF8(0x230001);
    D_80106A64_16B804_LookAway = SprAnimGet(D_80106C68_16BA08_LookAway[1]);
    func_80029EDC_2AADC(func_8002838C_28F8C(0, func_80102FD8_167D78_LookAway, 2), 1);
    obj->func_ptr = func_801032FC_16809C_LookAway;
}

void func_8010337C_16811C_LookAway(void) {
    D_80106CD0_16BA70_LookAway[5].obj = omAddObj(10, 0, 0, -1, func_80103304_1680A4_LookAway);
}

void func_801033B8_168158_LookAway(omObjData* obj) {
    if (D_801069A0_16B740_LookAway == 2 && D_801069AC_16B74C_LookAway != 0) {
        D_801069AC_16B74C_LookAway--;
    }
}

void func_801033F8_168198_LookAway(omObjData* obj) {
    D_801069AC_16B74C_LookAway = 150;
    obj->func_ptr = func_801033B8_168158_LookAway;
}

void func_80103414_1681B4_LookAway(void) {
    D_80106CD0_16BA70_LookAway[6].obj = omAddObj(100, 0, 0, -1, func_801033F8_168198_LookAway);
}

void func_80103450_1681F0_LookAway(LAObj* o, s16 member, u16 anim, s32 x, s32 y) {
    D_80106C68_16BA08_LookAway[(u16)(member + 5)] = anim;
    SprAnimSet(o->spr, member, anim, 0);
    SprAttrSet(o->spr, member, 0x100C);
    SprPosSet(o->spr, member, x, y);
    SprPrioSet(o->spr, member, 0xFFF4);
}

void func_80103508_1682A8_LookAway(omObjData* obj) {
    LAObj* o = &D_80106CD0_16BA70_LookAway[7];
    s16 i;

    for (i = 0; i < 15; i++) {
        LAMark* m = &D_801069B0_16B750_LookAway[i];
        s16 show = 0;
        f32 s;

        switch (m->state) {
        case 0:
            if (D_801069AC_16B74C_LookAway < 41 && !(D_801069AE_16B74E_LookAway & 1)) {
                if (i == 8 || i == 9) {
                    show = 1;
                    if (i == 9) {
                        D_801069AE_16B74E_LookAway |= 1;
                    }
                }
            } else if (D_801069AC_16B74C_LookAway < 26 && !(D_801069AE_16B74E_LookAway & 2)) {
                if (i == 7 || i == 10) {
                    show = 1;
                    if (i == 10) {
                        D_801069AE_16B74E_LookAway |= 2;
                    }
                }
            } else if (D_801069AC_16B74C_LookAway < 11 && !(D_801069AE_16B74E_LookAway & 4)) {
                if (i == 6 || i == 11) {
                    show = 1;
                    if (i == 11) {
                        D_801069AE_16B74E_LookAway |= 4;
                    }
                }
            }
            if (show) {
                SprAttrReset(o->spr, i, 0x8000);
                m->state = 1;
            }
            break;
        case 1:
            m->t += 20.0f;
            if (m->t > 180.0f) {
                m->t = 0.0f;
                m->state = 0;
                SprAttrSet(o->spr, i, 0x8000);
            }
            s = m->scale + func_800B80D0_B8CD0(m->t) / 2.0;
            SprScaleSet(o->spr, i, s, s);
            break;
        case 2:
            if (m->flags & 1) {
                SprAttrReset(o->spr, i, 0x8000);
                m->state = 3;
            }
            break;
        }
    }
}



void func_801037B0_168550_LookAway(omObjData* obj) {
    LAObj* o = &D_80106CD0_16BA70_LookAway[7];
    LAMark* m = D_801069B0_16B750_LookAway;
    u16 files[6] = { 4, 5, 6, 7, 8, 9 };
    u8 order[12] = { 0, 2, 4, 4, 2, 0, 1, 3, 5, 5, 3, 1 };
    s16 i;
    s16 anim;

    D_80106ECC_16BC6C_LookAway = SprCreate(15, 0);
    for (i = 0; i < 12; i++, m++) {
        func_80103450_1681F0_LookAway(o, i, func_8001A2F8_1AEF8(files[order[i]] | 0x230000),
                                      D_80106720_16B4C0_LookAway[i % 6][0], D_80106720_16B4C0_LookAway[i % 6][1]);
        m->scale = 1.0f;
        SprScaleSet(o->spr, i, 1.0f, 1.0f);
        if (i >= 6) {
            SprAttrSet(o->spr, i, 0x8000);
        }
    }
    anim = func_8001A2F8_1AEF8(0x23000A);
    for (; i < 15; i++, m++) {
        func_80103450_1681F0_LookAway(o, i, anim, D_80106720_16B4C0_LookAway[i - 6][0], D_80106720_16B4C0_LookAway[i - 6][1]);
        m->scale = 1.0f;
        SprScaleSet(o->spr, i, 1.0f, 1.0f);
        SprAttrSet(o->spr, i, 0x8000);
        m->state = 2;
    }
    obj->func_ptr = func_80103508_1682A8_LookAway;
}

void func_80103A48_1687E8_LookAway(void) {
    func_800B0EF0_B1AF0(D_801069B0_16B750_LookAway, 0, sizeof(D_801069B0_16B750_LookAway));
    D_80106CD0_16BA70_LookAway[7].obj = omAddObj(150, 0, 0, -1, func_801037B0_168550_LookAway);
}

void func_80103A98_168838_LookAway(omObjData* obj) {
    LALight* l = D_80106A68_16B808_LookAway;
    s16 i;

    for (i = 0; i < 10; i++, l++) {
        switch (l->state) {
        case 0:
            if (D_801069AE_16B74E_LookAway & 0x10) {
                func_80021160_21D60(l->id, 1, 0);
                func_80021160_21D60(l->id, 2, 0);
                func_800212A4_21EA4(l->id);
                l->state = 1;
            }
            if (D_801069A6_16B746_LookAway != 5) {
                if (D_801069A6_16B746_LookAway == 0 || D_801069A6_16B746_LookAway == i ||
                    D_801069A6_16B746_LookAway + 5 == i) {
                    l->alpha = 250.0f;
                    l->state = 2;
                    PlaySound(0x1B7);
                }
            }
            break;
        case 1:
            if (D_801069AE_16B74E_LookAway & 0x20) {
                func_80021160_21D60(l->id, 2, 2);
                l->state = 0;
            }
            break;
        case 2:
            l->alpha -= 25.0f;
            l->scale -= 0.1f;
            func_800297E8_2A3E8(D_800F86D8_F92D8[l->id].unk00, 1.0f, l->scale, 1.0f);
            func_800211E8_21DE8(l->id, l->alpha);
            if (l->scale <= 0.0f) {
                l->state = 3;
                func_800298A4_2A4A4(D_800F86D8_F92D8[l->id].unk00, 4, 4);
            }
            break;
        }
    }
}


void func_80103D04_168AA4_LookAway(omObjData* obj) {
    Vec pos[10] = {
        { -70.0f, 10.0f, 300.0f }, { -35.0f, 15.0f, 300.0f }, { 0.0f, 16.0f, 300.0f },
        { 35.0f, 15.0f, 300.0f },  { 70.0f, 10.0f, 300.0f },  { -70.0f, 10.0f, 290.0f },
        { -35.0f, 15.0f, 290.0f }, { 0.0f, 16.0f, 290.0f },   { 35.0f, 15.0f, 290.0f },
        { 70.0f, 10.0f, 290.0f },
    };
    LALight* l = D_80106A68_16B808_LookAway;
    void* data;
    s16 black;
    s16 white;
    s16 i;
    s16 id;

    func_800B0EF0_B1AF0(D_80106A68_16B808_LookAway, 0, sizeof(D_80106A68_16B808_LookAway));
    data = DataRead(0x23000B);
    black = func_8003DF08_3EB08(data);
    HuMemMemoryFreePerm(data);
    data = DataRead(0x23000C);
    white = func_8003DF08_3EB08(data);
    HuMemMemoryFreePerm(data);
    for (i = 0; i < 10; i++, l++) {
        if (i < 5) {
            id = func_80020EBC_21ABC((void*)-1, 0x2A4, 0x10);
            func_80021250_21E50(id, 0xFF, 0xFF, 0xFF);
            D_800F86D8_F92D8[id].unk02 = white;
        } else {
            id = func_80020EBC_21ABC((void*)-1, 0x2A4, 0x10);
            func_80021250_21E50(id, 0, 0, 0);
            D_800F86D8_F92D8[id].unk02 = black;
        }
        func_800298A4_2A4A4(D_800F86D8_F92D8[id].unk00, 4, 0);
        func_80029714_2A314(D_800F86D8_F92D8[id].unk00, pos[i].x, pos[i].y, pos[i].z);
        func_80029EDC_2AADC(D_800F86D8_F92D8[id].unk00, 2);
        l->scale = 1.0f;
        l->alpha = 1.0f;
        func_800297E8_2A3E8(D_800F86D8_F92D8[id].unk00, 1.0f, 1.0f, 1.0f);
        func_80021160_21D60(id, 1, 1);
        l->id = id;
    }
    obj->func_ptr = func_80103A98_168838_LookAway;
}

__asm__(".section .rodata");
const char D_80106858_16B5F8_LookAway[] = "c005l_0_DEF";

__asm__(".section .rodata");
const char D_80106864_16B604_LookAway[] = "c004l_0_DEF";

__asm__(".section .rodata");
const char D_80106870_16B610_LookAway[] = "c003l_0_DEF";

__asm__(".section .rodata");
const char D_8010687C_16B61C_LookAway[] = "c002l_0_DEF";

__asm__(".section .rodata");
const char D_80106888_16B628_LookAway[] = "c001l_0_DEF";

__asm__(".section .rodata");
const char D_80106894_16B634_LookAway[] = "c000l_0_DEF";

void func_80103FB0_168D50_LookAway(void) {
    D_80106CD0_16BA70_LookAway[8].obj = omAddObj(110, 0, 0, -1, func_80103D04_168AA4_LookAway);
}

u8 func_80103FEC_168D8C_LookAway(s8 x, s8 y) {
    s32 dir;

    if ((x != 0) | (y != 0)) {
        if (abs(x) >= abs(y)) {
            dir = (x > 0) ? 2 : 4;
        } else {
            dir = (y > 0) ? 1 : 3;
        }
    } else {
        dir = 0;
    }
    return dir;
}

void func_80104060_168E00_LookAway(LADir* d, u8 axis, f32* val, f32 target) {
    LAAxis* a = &d->axis[axis];
    u8 done = 0;

    d->done = 0;
    if (*val == target) {
        goto set;
    }
    if (d->dir != d->prev) {
        goto turn;
    }
    *val += a->vel;
    a->vel += a->acc;
    if (a->vel > 0.0f) {
        if (a->vel > 25.0f) {
            a->vel = 25.0f;
            a->acc = a->jerk = 0.0f;
        }
    } else if (a->vel < -25.0f) {
        a->vel = -25.0f;
        a->acc = a->jerk = 0.0f;
    }
    a->acc += a->jerk;
    if (a->vel > 0.0f) {
        if (!(target <= *val)) {
            goto check;
        }
        goto set;
    } else {
        if (!(*val <= target)) {
            goto check;
        }
        goto set;
    }
turn:
    if (target < *val) {
        a->vel = -6.0f;
        a->acc = 0.0f;
        a->jerk = -4.0f;
    } else {
        a->vel = 6.0f;
        a->acc = 0.0f;
        a->jerk = 4.0f;
    }
    goto check;
set:
    done = 1;
check:
    if (done) {
        *val = target;
        a->vel = a->acc = a->jerk = 0.0f;
        d->done = 1;
    }
}


/* NON_MATCHING: register allocation only (v0/v1 swapped in the table address). */
#ifdef NON_MATCHING
void func_80104238_168FD8_LookAway(omObjData* obj, LADir* d) {
    f32 rot[5][2] = { { 0.0f, 0.0f }, { 0.0f, -45.0f }, { 90.0f, 0.0f }, { 0.0f, 45.0f }, { -90.0f, 0.0f } };
    f32* r = rot[d->dir];
    f32 y = r[0];
    f32 x = r[1];

    if (obj->work[1] == 0) {
        x += 10.0f;
    }
    func_80104060_168E00_LookAway(d, 0, &obj->rot.y, y);
    func_80104060_168E00_LookAway(d, 1, &obj->rot.x, x);
}
#else
__asm__(".section .rodata");
const f32 D_801068A0_16B640_LookAway[5][2] = { { 0.0f, 0.0f }, { 0.0f, -45.0f }, { 90.0f, 0.0f }, { 0.0f, 45.0f }, { -90.0f, 0.0f } };
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_13_LookAway/1675A0", func_80104238_168FD8_LookAway);
#endif

void func_80104318_1690B8_LookAway(omObjData* obj) {
    LAObj* p = &D_80106CD0_16BA70_LookAway[obj->work[1]];

    if (p->unk_22 != 0) {
        obj->rot.z += 3.5f;
        if (obj->rot.z >= 22.5) {
            obj->rot.z = 22.5f;
            p->unk_22 ^= 1;
        }
    } else {
        obj->rot.z -= 3.5f;
        if (obj->rot.z <= -22.5) {
            obj->rot.z = -22.5f;
            p->unk_22 ^= 1;
        }
    }
}

u8 func_801043E0_169180_LookAway(omObjData* obj) {
    f32 prev;
    f32 cur;
    u8 done = 0;

    if (obj->rot.z != 0.0f) {
        prev = obj->rot.z;
        func_80104318_1690B8_LookAway(obj);
        cur = obj->rot.z;
        if ((prev > 0.0f) & (cur < 0.0f)) {
            obj->rot.z = 0.0f;
            done = 1;
        } else if ((prev < 0.0f) & (cur > 0.0f)) {
            obj->rot.z = 0.0f;
            done = 1;
        }
    } else {
        done = 1;
    }
    return done;
}

u8 func_801044E0_169280_LookAway(void) {
    u8 busy = 0;
    u8 i;

    for (i = 0; i < 4; i++) {
        if (D_80106BE8_16B988_LookAway[0].done == 0) {
            busy = 1;
        }
    }
    return busy;
}

void func_80104514_1692B4_LookAway(omObjData* obj, u8 motion) {
    s8 chr = gPlayers[obj->work[0]].character;

    func_8003E888_3F488(D_80106BE0_16B980_LookAway[obj->work[1]]);
    D_80106BE0_16B980_LookAway[obj->work[1]] =
        func_8003D8F0_3E4F0(D_800FC834_FD434[obj->model[0]].hmf, D_80106AE0_16B880_LookAway[obj->work[1]][motion], 0,
                            D_801067A0_16B540_LookAway[chr]);
}



u16 func_801045FC_16939C_LookAway(omObjData* obj) {
    u16 base[4] = { 20, 11, 7, 4 };
    u16 range[4] = { 10, 8, 5, 4 };
    u8 d = gPlayers[obj->work[0]].cpu_difficulty;

    return rand8() % range[d] + base[d];
}







void func_801046E4_169484_LookAway(omObjData* obj) {
    s16 pan[3] = { 32, 64, 96 };
    LAObj* p = &D_80106CD0_16BA70_LookAway[obj->work[1]];
    LADir* d = &D_80106BE8_16B988_LookAway[obj->work[1]];
    s8 idle[3] = { 0, 14, 15 };
    s8 missMot[5] = { 4, 4, 4, 4, 4 };
    s8 safeMot[5] = { 1, 1, 1, 1, 1 };
    f32 shrink[5] = { 0.8f, 0.6f, 0.4f, 0.2f, 0.1f };
    u8 chance[4] = { 0, 10, 20, 20 };
    u64 used;
    LAObj* q;
    omObjData* qo;
    LAMark* mk;
    s8 n = 0; /* catches this round, or "a choice was made" */
    u8 camDir;
    u8 mot;
    u8 k;
    u8 port;
    f32 s;

    switch (p->state) {
    case 0:
        if (D_801069A0_16B740_LookAway == 2) {
            if (obj->work[1] == 0) {
                D_801069AC_16B74C_LookAway = 150;
                D_801069AE_16B74E_LookAway = 0;
                PlayMusic(0x31);
                func_80079518_7A118(0x7F);
                D_801069AE_16B74E_LookAway |= 0x10;
            }
            p->state = 1;
        }
        break;
    case 1:
        func_80104318_1690B8_LookAway(obj);
        if (D_801069AC_16B74C_LookAway < 46) {
            p->state = 2;
            p->unk_24 = 0;
            p->unk_26 = func_801045FC_16939C_LookAway(obj);
            p->timer = 10;
        }
        break;
    case 2:
        if (obj->work[1] == 0 && D_801069AC_16B74C_LookAway == 0 && (D_801069AE_16B74E_LookAway & 0x10)) {
            D_801069AE_16B74E_LookAway = (D_801069AE_16B74E_LookAway ^ 0x10) | 0x20;
        }
        if (func_801043E0_169180_LookAway(obj)) {
            d->prev = d->dir;
            if (p->com != 0) {
                if (D_801069AA_16B74A_LookAway < 2 && D_801069AC_16B74C_LookAway == 0 && p->timer == 0 &&
                    (u8)(rand8() % 100) < chance[gPlayers[obj->work[0]].cpu_difficulty]) {
                    n = 1;
                    if (obj->work[1] != 0) {
                        if (D_80106BE8_16B988_LookAway[0].dir == d->dir) {
                            used = 1 << D_80106BE8_16B988_LookAway[0].dir;
                            d->dir = func_801028A0_167640_LookAway(5, &used);
                        }
                    } else {
                        mk = D_80106A40_16B7E0_LookAway;
                        used = 0;
                        for (k = 0; k < 3; k++, mk++) {
                            if (mk->flags & 1) {
                                used |= 1 << k;
                            }
                        }
                        if (used != 7) {
                            d->dir = D_80106C04_16B9A4_LookAway[func_801028A0_167640_LookAway(3, &used)].dir;
                        }
                    }
                }
                if (!n) {
                    if (p->unk_26 != 0) {
                        p->unk_26--;
                    } else {
                        p->unk_26 = func_801045FC_16939C_LookAway(obj);
                        d->dir = rand8() % 5;
                    }
                }
            } else {
                port = gPlayers[obj->work[0]].port;
                d->dir = func_80103FEC_168D8C_LookAway(ContStkX[port], ContStkY[port]);
            }
            func_80104238_168FD8_LookAway(obj, d);
            if (D_801069AC_16B74C_LookAway == 0) {
                if (p->timer == 0) {
                    p->state = 3;
                    if (obj->work[1] == 0) {
                        func_800794A8_7A0A8(40);
                    }
                } else {
                    p->timer--;
                }
            }
        }
        break;
    case 3:
        d->prev = d->dir;
        func_80104238_168FD8_LookAway(obj, d);
        if (!func_801044E0_169280_LookAway()) {
            if (++p->timer > 20) {
                d->shown = d->dir;
                p->state = 4;
                p->timer = 0;
                d->dir = 0;
            }
        }
        break;
    case 4:
        func_80104238_168FD8_LookAway(obj, d);
        d->prev = d->dir;
        if (!func_801044E0_169280_LookAway() && obj->work[1] == 0) {
            if (++p->timer > 10) {
                camDir = D_80106BE8_16B988_LookAway[0].shown;
                for (k = 1; k < 4; k++) {
                    q = &D_80106CD0_16BA70_LookAway[k];
                    qo = q->obj;
                    mk = &D_80106A34_16B7D4_LookAway[qo->work[1]];
                    if (camDir == D_80106BE8_16B988_LookAway[k].shown) {
                        q->state = 6;
                        q->timer = 0;
                        if (mk->flags & 1) {
                            func_80104514_1692B4_LookAway(qo, 5);
                        } else {
                            q->timer = (n != 0) ? n * 30 : 1;
                            D_801069AA_16B74A_LookAway++;
                            n++;
                        }
                    } else {
                        q->state = 5;
                        q->timer = 0;
                    }
                }
                if (n != 0) {
                    func_80104514_1692B4_LookAway(obj, 1);
                    D_801069A8_16B748_LookAway = 0;
                } else {
                    func_80104514_1692B4_LookAway(obj, missMot[D_801069A8_16B748_LookAway]);
                    for (k = 1; k < 4; k++) {
                        q = &D_80106CD0_16BA70_LookAway[k];
                        qo = q->obj;
                        mk = &D_80106A34_16B7D4_LookAway[qo->work[1]];
                        if (mk->flags & 1) {
                            func_80104514_1692B4_LookAway(qo, 2);
                        } else {
                            func_80104514_1692B4_LookAway(qo, safeMot[D_801069A8_16B748_LookAway]);
                            func_800798F8_7A4F8(func_800797DC_7A3DC(0x103, qo->work[0]), pan[qo->work[1] - 1]);
                        }
                    }
                    D_801069A8_16B748_LookAway++;
                    if (p->com == 0) {
                        omVibrate(obj->work[0], 10, 0, 10);
                    }
                }
                p->state = 5;
                p->timer = 30;
            }
        }
        break;
    case 5:
        if (obj->work[1] != 0) {
            p->state = D_80106CD0_16BA70_LookAway[0].state;
            if (p->unk_24 == 0 && (D_801069AE_16B74E_LookAway & 0x100)) {
                func_80104514_1692B4_LookAway(obj, (D_80106A34_16B7D4_LookAway[obj->work[1]].flags & 1) ? 5 : 2);
                p->unk_24 = 1;
            }
        } else {
            for (k = 1; k < 4; k++) {
                q = &D_80106CD0_16BA70_LookAway[k];
                if (q->state == 6) {
                    n = 1;
                }
            }
            if (n == 0) {
                if (p->timer == 0) {
                    D_801069A6_16B746_LookAway--;
                    if (D_801069AA_16B74A_LookAway >= 3 || D_801069A6_16B746_LookAway == 0) {
                        p->state = 8;
                        D_801069A6_16B746_LookAway = 0;
                    } else {
                        p->state = 7;
                    }
                } else {
                    p->timer--;
                }
            }
        }
        break;
    case 6:
        if (p->timer != 0) {
            if (--p->timer == 0) {
                func_80104514_1692B4_LookAway(obj, 5);
                func_800798F8_7A4F8(func_800797DC_7A3DC(0x111, obj->work[0]), pan[obj->work[1] - 1]);
                PlaySound(0x1B4);
                D_801069AE_16B74E_LookAway |= 0x100;
            } else if (p->unk_24 == 0 && (D_801069AE_16B74E_LookAway & 0x100)) {
                func_80104514_1692B4_LookAway(obj, 2);
                p->unk_24 = 1;
            }
        } else {
            mk = &D_80106A34_16B7D4_LookAway[obj->work[1]];
            s = shrink[mk->count];
            obj->scale.x -= 0.1f;
            obj->scale.y -= 0.1f;
            obj->scale.z -= 0.1f;
            if (obj->scale.x <= s) {
                mk->flags |= 1;
                obj->scale.x = obj->scale.y = obj->scale.z = s;
                p->state = 5;
                mk->count++;
                if (p->com == 0) {
                    omVibrate(obj->work[0], 10, 0, 10);
                }
            }
        }
        break;
    case 7:
        if (p->timer++ > 60) {
            p->state = 0;
            p->unk_22 = 0;
            p->timer = 0;
            if (obj->work[1] != 0) {
                if (D_80106A34_16B7D4_LookAway[obj->work[1]].flags & 1) {
                    func_80104514_1692B4_LookAway(obj, 13);
                    break;
                }
                used = 0;
                mot = 0;
                for (k = 1; k < 4; k++) {
                    mk = &D_80106A34_16B7D4_LookAway[k];
                    if (mk->flags & 1) {
                        used |= 1 << (k - 1);
                    }
                }
                if (used != 0) {
                    switch (obj->work[1]) {
                    case 1:
                        if (used & 2) {
                            mot = 14;
                            n = 1;
                        }
                        break;
                    case 3:
                        if (used & 2) {
                            mot = 15;
                            n = 1;
                        }
                        break;
                    case 2:
                        n = 1;
                        if (used == 1) {
                            mot = 15;
                        } else if (used == 4) {
                            mot = 14;
                        } else {
                            mot = (rand8() & 1) ? 15 : 14;
                        }
                        break;
                    }
                }
                if (!n) {
                    mot = idle[(u8)(rand8() % 3)];
                }
                func_80104514_1692B4_LookAway(obj, mot);
            } else {
                func_80104514_1692B4_LookAway(obj, idle[(u8)(rand8() % 3)]);
            }
        }
        break;
    case 8:
        if (_CheckFlag(0xC) == 0 && (D_801069AE_16B74E_LookAway & 0xC0)) {
            s32 lost = (obj->work[1] != 0) ? (D_801069AE_16B74E_LookAway & 0x40) : (D_801069AE_16B74E_LookAway & 0x80);

            mot = 12;
            if (lost) {
                mot = 7;
            }
            if (mot == 7) {
                p->state = 10;
                p->unk_38 = (rand8() & 1) ? 15.0f : -15.0f;
                p->unk_3C = obj->scale.x;
                if (p->com == 0) {
                    omVibrate(obj->work[0], 10, 0, 10);
                }
            } else {
                p->state = 9;
                p->unk_22 = 0;
                p->timer = 0;
                p->unk_38 = obj->trans.y;
                p->unk_3C = 0.0f;
                p->unk_40 = obj->trans.x;
                p->unk_44 = 0.0f;
                if (obj->work[1] == 0) {
                    func_800797DC_7A3DC(0x103, obj->work[0]);
                } else {
                    func_800798F8_7A4F8(func_800797DC_7A3DC(0x103, obj->work[0]), pan[obj->work[1] - 1]);
                }
            }
            func_80104514_1692B4_LookAway(obj, mot);
        }
        break;
    case 9:
        if (p->timer != 0) {
            p->timer--;
            break;
        }
        switch (p->unk_22) {
        case 0:
            obj->rot.z += 3.5f;
            if (obj->rot.z >= 22.5f) {
                obj->rot.z = 22.5f;
            }
            p->unk_44 -= 10.0f;
            if (p->unk_44 <= -90.0f) {
                p->unk_44 = -90.0f;
            }
            break;
        case 1:
            obj->rot.z -= 3.5f;
            if (obj->rot.z <= 0.0f) {
                obj->rot.z = 0.0f;
            }
            p->unk_44 += 10.0f;
            if (p->unk_44 >= 0.0f) {
                p->unk_44 = 0.0f;
            }
            break;
        case 2:
            obj->rot.z -= 3.5f;
            if (obj->rot.z <= -22.5f) {
                obj->rot.z = -22.5f;
            }
            p->unk_44 += 10.0f;
            if (p->unk_44 >= 90.0f) {
                p->unk_44 = 90.0f;
            }
            break;
        case 3:
            obj->rot.z += 3.5f;
            if (obj->rot.z >= 0.0f) {
                obj->rot.z = 0.0f;
            }
            p->unk_44 -= 10.0f;
            if (p->unk_44 <= 0.0f) {
                p->unk_44 = 0.0f;
            }
            break;
        }
        obj->trans.x = p->unk_40 + func_800B80D0_B8CD0(p->unk_44) * 5.0;
        p->unk_3C += 20.0f;
        if (p->unk_3C > 180.0f) {
            p->unk_3C = 0.0f;
            p->timer = 1;
            p->unk_22 = (p->unk_22 + 1) & 3;
        }
        obj->trans.y = p->unk_38 + func_800B80D0_B8CD0(p->unk_3C) * 5.0;
        break;
    case 10:
        obj->rot.z += p->unk_38;
        p->unk_3C -= 0.0125f;
        if (p->unk_3C < 0.0f) {
            p->unk_3C = 0.0f;
            p->state = 11;
        }
        obj->scale.x = obj->scale.y = obj->scale.z = p->unk_3C;
        obj->trans.y += 0.3f;
        break;
    case 11:
        break;
    }
}


void func_8010580C_16A5AC_LookAway(omObjData* obj) {
    LAObj* p = &D_80106CD0_16BA70_LookAway[obj->work[1]];
    f32 yofs[6] = { 0.0f, 5.0f, 5.0f, 15.0f, 15.0f, 18.0f };
    s8 chr = gPlayers[obj->work[0]].character;
    s16 i;
    f32* pos;
    s32 dir;

    obj->model[0] = LoadFormFile(D_80106748_16B4E8_LookAway[chr] | 0x230000, 0x2A9);
    for (i = 0; i < 16; i++) {
        if (i < 13) {
            dir = D_80106754_16B4F4_LookAway[chr] << 16;
            D_80106AE0_16B880_LookAway[obj->work[1]][i] = DataRead(dir | D_80106760_16B500_LookAway[i]);
        } else {
            dir = 0x230000;
            D_80106AE0_16B880_LookAway[obj->work[1]][i] = DataRead(D_8010677C_16B51C_LookAway[(i - 13) * 6 + chr] | dir);
        }
    }
    D_80106BE0_16B980_LookAway[obj->work[1]] =
        func_8003D8F0_3E4F0(D_800FC834_FD434[obj->model[0]].hmf, D_80106AE0_16B880_LookAway[obj->work[1]][0], 0,
                            D_801067A0_16B540_LookAway[chr]);
    func_80029A8C_2A68C(obj->model[0]);
    func_80029AFC_2A6FC(obj->model[0]);
    pos = D_801066F0_16B490_LookAway[obj->work[1]];
    obj->trans.x = pos[0];
    obj->trans.y = pos[1];
    obj->trans.z = pos[2];
    if (obj->work[1] == 0) {
        obj->trans.y += yofs[chr];
    }
    obj->scale.x = obj->scale.y = obj->scale.z = 1.25f;
    if (obj->work[1] == 0) {
        obj->rot.x = 10.0f;
    }
    func_8010281C_1675BC_LookAway(obj->work[0]);
    p->com = gPlayers[obj->work[0]].flags & 1;
    func_80029EDC_2AADC(obj->model[0], 2);
    obj->func_ptr = func_801046E4_169484_LookAway;
}

void func_80105B4C_16A8EC_LookAway(void) {
    LAObj* base = D_80106CD0_16BA70_LookAway;
    omObjData* o;
    LAObj* p;
    s16 i;
    u16 player;
    u8 slot = 0;

    for (i = 0; i < 4; i++) {
        if (gPlayers[i].group == 0) {
            break;
        }
    }
    switch (i) {
    case 1:
        player = 1;
        break;
    case 2:
        player = 2;
        break;
    case 3:
        player = 3;
        break;
    case 0:
    default:
        player = 0;
        break;
    }
    o = omAddObj(200, 1, 0, -1, func_8010580C_16A5AC_LookAway);
    base->player = player;
    o->work[0] = player;
    o->work[1] = slot;
    base->obj = o;
    slot++;
    for (i = 0; i < 4; i++) {
        if (base->player == i) {
            continue;
        }
        p = &D_80106CD0_16BA70_LookAway[slot];
        o = omAddObj(300, 1, 0, -1, func_8010580C_16A5AC_LookAway);
        switch (i) {
        case 1:
            player = 1;
            break;
        case 2:
            player = 2;
            break;
        case 3:
            player = 3;
            break;
        case 0:
        default:
            player = 0;
            break;
        }
        p->player = player;
        o->work[0] = player;
        o->work[1] = slot;
        p->obj = o;
        slot++;
    }
}

void func_80105D3C_16AADC_LookAway(omObjData* obj) {
    if (D_801069A4_16B744_LookAway != 0) {
        D_801069A4_16B744_LookAway--;
    }
}

void func_80105D64_16AB04_LookAway(omObjData* obj) {
    if (D_801069A0_16B740_LookAway == 3) {
        D_801069A4_16B744_LookAway = 60;
        func_800691FC_69DFC(3);
        obj->func_ptr = func_80105D3C_16AADC_LookAway;
        func_800794A8_7A0A8(40);
    }
}

void func_80105DBC_16AB5C_LookAway(omObjData* obj) {
    switch (D_801069A0_16B740_LookAway) {
    case 1:
        if (*(s16*)&D_801069A2_16B742_LookAway == 0) {
            func_800691FC_69DFC(0);
            D_801069A2_16B742_LookAway++;
        }
        break;
    case 2:
        obj->func_ptr = func_80105D64_16AB04_LookAway;
        break;
    }
}

void func_80105E30_16ABD0_LookAway(void) {
    LAObj* tbl;
    omObjData* o;
    s16 win;
    s16 i;

    i = 0;
    tbl = D_80106CD0_16BA70_LookAway;
    for (; i < 4; i++) {
        o = tbl[i].obj;
        if (o != NULL) {
            win = 0;
            if (D_801069AE_16B74E_LookAway & 0x40) {
                win = gPlayers[o->work[0]].group == 0;
            } else if (gPlayers[o->work[0]].group != 0) {
                win = 1;
            }
            if (win) {
                gPlayers[o->work[0]].coins_mg_bonus = 10;
            }
        }
    }
}

void func_80105F28_16ACC8_LookAway(omObjData* obj) {
    osViBlack(0);
    omOvlReturnEx(1);
}

void func_80105F4C_16ACEC_LookAway(omObjData* obj) {
    s16 i;
    s16 j;

    if (func_8008F618_90218() == 0) {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 16; j++) {
                DataClose(D_80106AE0_16B880_LookAway[i][j]);
            }
        }
        obj->func_ptr = func_80105F28_16ACC8_LookAway;
    }
}

void func_80106008_16ADA8_LookAway(omObjData* obj) {
    if (D_801011FC_101DFC == 1) {
        InitFadeOut(0, 20);
        func_800794A8_7A0A8(40);
        func_80079614_7A214(40);
        obj->func_ptr = func_80105F4C_16ACEC_LookAway;
    }
}

void func_80106060_16AE00_LookAway(omObjData* obj) {
    LAObj* tbl;
    u8 chars[4];
    s16 i;
    s16 k;
    s32 t;

    switch (D_801069A0_16B740_LookAway) {
    case 0:
        if ((s16)D_801069A2_16B742_LookAway++ >= 31) {
            D_801069A0_16B740_LookAway = 1;
            D_801069A2_16B742_LookAway = 0;
        }
        break;
    case 1:
        if (func_80069538_6A138() == 0) {
            D_801069A0_16B740_LookAway = 2;
        }
        break;
    case 2:
        if (D_801069A6_16B746_LookAway == 0) {
            D_801069A0_16B740_LookAway = 3;
            D_801069A2_16B742_LookAway = 0;
        }
        break;
    case 3:
        if (func_80069538_6A138() == 0) {
            if ((s16)D_801069A2_16B742_LookAway < 20 && (s16)++D_801069A2_16B742_LookAway < 20) {
                break;
            }
            D_801069A0_16B740_LookAway = 4;
            D_801069A2_16B742_LookAway = 0;
            D_801069AE_16B74E_LookAway |= (D_801069AA_16B74A_LookAway < 3) ? 0x80 : 0x40;
            if (_CheckFlag(0xC) == 0) {
                k = 0;
                if (D_801069AE_16B74E_LookAway & 0x40) {
                    chars[0] = gPlayers[D_80106CD0_16BA70_LookAway[0].obj->work[0]].character;
                    func_800691FC_69DFC(6, chars[0], 0);
                    PlayMusic(0x51);
                    D_801069A2_16B742_LookAway = 120;
                } else {
                    i = 1;
                    tbl = D_80106CD0_16BA70_LookAway;
                    for (; i < 4; i++, k++) {
                        chars[k] = gPlayers[tbl[i].obj->work[0]].character;
                    }
                    func_800691FC_69DFC(0x15, chars[0], chars[1], chars[2]);
                    PlayMusic(0x52);
                    D_801069A2_16B742_LookAway = 168;
                }
            }
            func_80105E30_16ABD0_LookAway();
        }
        break;
    case 4:
        if (_CheckFlag(0xC) != 0) {
            t = D_801069A4_16B744_LookAway;
        } else {
            t = --D_801069A2_16B742_LookAway;
        }
        if (t == 0) {
            D_801069A0_16B740_LookAway = 5;
        }
        break;
    case 5:
        InitFadeOut(0, 20);
        obj->func_ptr = func_80105F4C_16ACEC_LookAway;
        break;
    }
    func_801029F0_167790_LookAway();
}

void func_80106328_16B0C8_LookAway(omObjData* obj) {
    func_80106640_16B3E0_LookAway();
    func_801066C4_16B464_LookAway();
    func_80102F90_167D30_LookAway();
    func_8010337C_16811C_LookAway();
    func_80103414_1681B4_LookAway();
    func_80103FB0_168D50_LookAway();
    func_80103A48_1687E8_LookAway();
    func_80105B4C_16A8EC_LookAway();
    InitFadeIn(0, 16);
    obj->func_ptr = func_80106060_16AE00_LookAway;
    D_801069A0_16B740_LookAway = 0;
    D_801069A2_16B742_LookAway = 0;
    D_801069A4_16B744_LookAway = 0;
    D_801069A6_16B746_LookAway = 5;
    D_801069A8_16B748_LookAway = 0;
    D_801069AA_16B74A_LookAway = 0;
    D_801069AE_16B74E_LookAway = 0;
    func_800B0EF0_B1AF0(D_80106BE8_16B988_LookAway, 0, sizeof(D_80106BE8_16B988_LookAway));
    omAddObj(900, 0, 0, -1, func_80105DBC_16AB5C_LookAway);
}

__asm__(".section .rodata");
const char D_80106990_16B730_LookAway[16] = "\202`\202a\202b";

void func_8010640C_16B1AC_LookAway(void) {
    omObjData* o;

    func_8002D4D0_2E0D0(50);
    func_80020D20_21920(32);
    omInitObjMan(50, 0);
    func_80079128_79D28();
    func_80026DAC_279AC(0, 0, 0, 0);
    func_80026DAC_279AC(1, 0x40, 0x40, 0x60);
    func_80026E00_27A00(1, 0.0f, 10.0f, 100.0f);
    o = omAddObj(0x7FDA, 0, 0, -1, func_80079FF4_7ABF4);
    o->work[0] = 2;
    omSetStatBit(o, 0xA0);
    func_80018E30_19A30(2);
    func_80018F58_19B58(2);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 26.2f, 80.0f, 8000.0f);
    ScissorSet(1, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(1, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(1, 26.2f, 80.0f, 8000.0f);
    D_800FA606_FB206 = 0;
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    omAddObj(1000, 0, 0, -1, func_80106328_16B0C8_LookAway);
    omAddObj(1000, 0, 0, -1, func_80106008_16ADA8_LookAway);
    func_8007273C_7333C(D_80106990_16B730_LookAway, 0);
    func_8007273C_7333C(D_80106990_16B730_LookAway, 1);
}
