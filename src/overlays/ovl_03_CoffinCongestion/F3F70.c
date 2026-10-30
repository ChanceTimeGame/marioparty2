#include "ovl_03.h"

/* Starts host motion `mot` on the object (looping when its speed is negative); 1 if it changed. */
s32 func_80102860_F3F70_CoffinCongestion(omObjData* obj, s32 mot) {
    CCProp* p = obj->unk_50;

    if (p->unk_1C != mot) {
        p->unk_1C = mot;
        if (D_8010691C_F802C_CoffinCongestion[mot].speed < 0) {
            func_80029BF0_2A7F0(obj->model[0], obj->motion[mot], 0, 5, 0);
            return 1;
        }
        func_80029BF0_2A7F0(obj->model[0], obj->motion[mot], 0, 5, 2);
        func_80029FBC_2ABBC(obj->model[0], D_8010691C_F802C_CoffinCongestion[mot].speed);
        return 1;
    }
    return 0;
}

/* Puts coffin `p` in the next slot and moves `pos` there. */
void func_80102944_F4054_CoffinCongestion(CCProp* p, Vec* pos) {
    s32* idx = &D_80106DB8_F84C8_CoffinCongestion.idx;

    if (++*idx >= 6) {
        *idx -= 6;
    }
    D_80106DB8_F84C8_CoffinCongestion.slot[D_80106DB8_F84C8_CoffinCongestion.idx] = p;
    func_800B3170_B3D70(pos, &D_80106944_F8054_CoffinCongestion[D_80106DB8_F84C8_CoffinCongestion.idx]);
}

void func_801029C0_F40D0_CoffinCongestion(omObjData* obj, CCProp* p) {
    if (p->unk_18++ >= 46) {
        if (p->unk_0E < 6) {
            PlaySound(0x134);
        }
        p->unk_0E += 6;
    }
}

void func_80102A20_F4130_CoffinCongestion(omObjData* obj, CCProp* p) {
    f32 x;

    if (D_80106DB8_F84C8_CoffinCongestion.cur == 2) {
        x = (f32)((u8)(rand8() % 10) - 5) + p->pos.x;
        omSetTra(obj, x, p->pos.y, (f32)((u8)(rand8() % 10) - 5) + p->pos.z);
    } else {
        omSetTra(obj, p->pos.x, p->pos.y, p->pos.z);
    }
}

void func_80102B28_F4238_CoffinCongestion(omObjData* obj, CCProp* p) {
    if (p->unk_10 == 0) {
        if (p->unk_1A++ >= 61) {
            p->unk_1A = 0;
            p->unk_10++;
            PlaySound(0x138);
        }
    } else {
        p->unk_0E -= 6;
    }
}

/* Room object update: the per-mode hook of D_8010698C, then the alpha. */
void func_80102B90_F42A0_CoffinCongestion(omObjData* obj) {
    CCProp* p = ((CCGround*)obj->unk_50)->unk_B0;

    if (D_8010698C_F809C_CoffinCongestion[func_80106570_F7C80_CoffinCongestion()] != NULL) {
        D_8010698C_F809C_CoffinCongestion[func_80106570_F7C80_CoffinCongestion()](obj, p);
    }
    if (p->unk_0E < 0) {
        p->unk_0E = 0;
    }
    if (p->unk_0E >= 256) {
        p->unk_0E = 255;
    }
    func_8002D0A0_2DCA0(obj->model[0], p->unk_0E);
}

void func_80102C44_F4354_CoffinCongestion(omObjData* obj, CCProp* p) {
    if (p->unk_18++ >= 46) {
        p->unk_0E += 6;
    }
}

/* A coffin lid: down (1), shaking (2), up (3). */
void func_80102C74_F4384_CoffinCongestion(omObjData* obj, CCProp* p) {
    f32 x;

    switch (D_80106DB8_F84C8_CoffinCongestion.cur) {
        case 1:
            if (D_80106DB8_F84C8_CoffinCongestion.cur != D_80106DB8_F84C8_CoffinCongestion.prev) {
                PlaySound(0x135);
            }
            obj->trans.x -= 15.0f;
            if (obj->trans.x < p->pos.x - 150.0f) {
                obj->trans.x = p->pos.x - 150.0f;
            }
            break;
        case 2:
            if (D_80106DB8_F84C8_CoffinCongestion.cur != D_80106DB8_F84C8_CoffinCongestion.prev) {
                PlaySound(0x137);
            }
            x = (f32)((u8)(rand8() % 10) - 5) + p->pos.x;
            omSetTra(obj, x, p->pos.y, (f32)((u8)(rand8() % 10) - 5) + p->pos.z);
            break;
        case 3:
            if (D_80106DB8_F84C8_CoffinCongestion.cur != D_80106DB8_F84C8_CoffinCongestion.prev) {
                PlaySound(0x136);
            }
            obj->trans.x += 30.0f;
            if (p->pos.x < obj->trans.x) {
                obj->trans.x = p->pos.x;
            }
            break;
    }
}

/* The opened coffin: the player gets its item. */
void func_80102E64_F4574_CoffinCongestion(omObjData* obj, CCProp* p) {
    if (p->unk_1E == 1) {
        PlaySound(0x135);
        omVibrate(((MgWork*)p->unk_14->unk_50)->unk_59, 10, 0, 10);
        func_801065C0_F7CD0_CoffinCongestion(((MgWork*)p->unk_14->unk_50)->unk_59,
                                             D_80106DB8_F84C8_CoffinCongestion.slot[p->unk_0C - 6]->unk_12);
    }
}

void func_80102EE0_F45F0_CoffinCongestion(omObjData* obj, CCProp* p) {
    if (p->unk_1E == 1) {
        p->unk_0E -= 6;
        if (p->unk_0E < 0) {
            p->unk_0E = 0;
        }
    }
}

void func_80102F10_F4620_CoffinCongestion(omObjData* obj, CCProp* p) {
    if (p->unk_1E == 1) {
        p->unk_0E -= 6;
        if (p->unk_0E < 0) {
            p->unk_0E = 0;
        }
        return;
    }
    switch (p->unk_10) {
        case 0:
            if (p->unk_1A++ >= 31) {
                p->unk_1A = 0;
                if (func_801065EC_F7CFC_CoffinCongestion() < 0) {
                    p->unk_10 = 2;
                } else {
                    p->unk_10++;
                    PlaySound(0x135);
                }
            }
            break;
        case 1:
            obj->trans.x -= 15.0f;
            if (obj->trans.x < p->pos.x - 150.0f) {
                obj->trans.x = p->pos.x - 150.0f;
                p->unk_10++;
            }
            p->unk_1A++;
            break;
        case 2:
            if (p->unk_1A++ >= 31) {
                p->unk_1A = 0;
                p->unk_10++;
            }
            break;
        default:
            p->unk_0E -= 6;
            break;
    }
}

void func_80103080_F4790_CoffinCongestion(omObjData* obj) {
    CCProp* p = ((CCGround*)obj->unk_50)->unk_B0;

    if (D_801069AC_F80BC_CoffinCongestion[func_80106570_F7C80_CoffinCongestion()] != NULL) {
        D_801069AC_F80BC_CoffinCongestion[func_80106570_F7C80_CoffinCongestion()](obj, p);
    }
    if (p->unk_0E < 0) {
        p->unk_0E = 0;
    }
    if (p->unk_0E >= 256) {
        p->unk_0E = 255;
    }
    func_8002D0A0_2DCA0(obj->model[0], p->unk_0E);
}

/* An item model: follows the coffin six objects before it. */
void func_80103134_F4844_CoffinCongestion(omObjData* obj) {
    CCProp* p = ((CCGround*)obj->unk_50)->unk_B0;
    omObjData* coffin = D_80106DB0_F84C0_CoffinCongestion[p->unk_0C - 6];

    p->unk_0E = ((CCGround*)coffin->unk_50)->unk_B0->unk_0E;
    omSetTra(obj, coffin->trans.x, -3.0f, coffin->trans.z);
    func_8002D0A0_2DCA0(obj->model[0], p->unk_0E);
}

void func_801031AC_F48BC_CoffinCongestion(omObjData* obj) {
    CCProp* p = ((CCGround*)obj->unk_50)->unk_B0;

    obj->trans.x = (f32)((u8)(rand8() % 100) - 50) * 0.05f + p->pos.x;
    obj->trans.z = (f32)((u8)(rand8() % 100) - 50) * 0.05f + p->pos.z;
    func_8002D0A0_2DCA0(obj->model[0], rand8() & 0x3F);
}

void func_801032B8_F49C8_CoffinCongestion(omObjData* obj, CCProp* p) {
    if (p->unk_10 != 0) {
        p->unk_0E += 6;
    }
}

void func_801032D8_F49E8_CoffinCongestion(omObjData* obj, CCProp* p) {
    if (D_80106DB8_F84C8_CoffinCongestion.cur != 2) {
        p->unk_1A = 1;
    } else if (p->unk_1A == 1) {
        func_80102944_F4054_CoffinCongestion(p, &p->pos);
        omSetTra(obj, p->pos.x, p->pos.y, p->pos.z);
        p->unk_1A = 0;
    }
}

/* Smoke puff update: fades out, then frees its slot. */
void func_80103350_F4A60_CoffinCongestion(omObjData* obj) {
    CCProp* p = obj->unk_50;

    p->unk_0E -= 6;
    if (p->unk_0E < 0) {
        p->unk_0E = 0;
        p->unk_0C = 0;
    }
    func_8002D0A0_2DCA0(obj->model[0], p->unk_0E);
}

/* Creates the six smoke puffs (item model `item`) once. */
void func_80103398_F4AA8_CoffinCongestion(s32 item) {
    omObjData*** puffs = &D_80106DB4_F84C4_CoffinCongestion;
    omObjData* obj;
    CCProp* p;
    s32 i;

    if (*puffs == NULL) {
        func_80076BD0_777D0(2, 6);
        *puffs = func_80076D80_77980(2);
        for (i = 0; i < 6; i++) {
            obj = D_80106DB4_F84C4_CoffinCongestion[i] = omAddObj(4, 1, 0, 2, func_80103350_F4A60_CoffinCongestion);
            p = func_80027154_27D54(sizeof(CCProp), 0x7918);
            func_800B0EF0_B1AF0(p, 0, sizeof(CCProp));
            obj->unk_50 = p;
            obj->model[0] = func_80018A30_19630(D_801068F4_F8004_CoffinCongestion[item], 0x2A9);
            func_8002D124_2DD24(obj->model[0]);
            func_8002D0A0_2DCA0(obj->model[0], 0);
        }
    }
}

/* A free smoke puff, or NULL. */
omObjData* func_801034B0_F4BC0_CoffinCongestion(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        if (((CCProp*)D_80106DB4_F84C4_CoffinCongestion[i]->unk_50)->unk_0C == 0) {
            return D_80106DB4_F84C4_CoffinCongestion[i];
        }
    }
    return NULL;
}

void func_801034F8_F4C08_CoffinCongestion(f32 x, f32 y, f32 z) {
    omObjData* obj = func_801034B0_F4BC0_CoffinCongestion();
    CCProp* p;

    if (obj != NULL) {
        omSetTra(obj, x, y, z);
        p = obj->unk_50;
        p->unk_0E = 192;
        p->unk_0C = 1;
    }
}

/* The host (the boo that hides the items): rises (1), bobs and lays smoke (2), floats back to
   the middle (3), bobs (4). */
void func_80103578_F4C88_CoffinCongestion(omObjData* obj, CCProp* p) {
    Vec v;
    CCProp* q;

    if (p->unk_18++ >= 30) {
        if (p->unk_1E == 0) {
            p->unk_0E -= 6;
            return;
        }
        switch (p->unk_1C) {
            case 0:
                q = ((CCGround*)D_80106DB0_F84C0_CoffinCongestion[26]->unk_50)->unk_B0;
                q->unk_14 = obj;
                if (q->unk_10 == 0) {
                    q->unk_10++;
                }
                func_80103398_F4AA8_CoffinCongestion(p->unk_12);
                p->unk_1C++;
                break;
            case 1:
                obj->trans.y += 10.0f;
                if (obj->trans.y > 300.0f) {
                    p->unk_20 = obj->trans.y;
                    goto next;
                }
                goto puff;
            case 2:
                obj->trans.y = HuMathSin(p->unk_24) * 30.0f + p->unk_20;
                p->unk_24 += 12.0f;
                if (p->unk_24 > 360.0f) {
                    p->unk_24 -= 360.0f;
                }
                if (p->unk_18 >= 91) {
                    PlaySound(0x12E);
                    goto next;
                }
                goto puff;
            case 3:
                HuVecCopyXYZ(&v, -obj->trans.x, 0.0f, -obj->trans.z);
                if (HuVecGetLength3F(&v) > 16.0f) {
                    func_8010609C_F77AC_CoffinCongestion(&v);
                    HuVecMulScalar(&v, 16.0f, &v);
                    omSetTra(obj, obj->trans.x + v.x, obj->trans.y + v.y, obj->trans.z + v.z);
                    goto puff;
                }
            next:
                p->unk_1C++;
            puff:
                if ((s16)(p->unk_1A++ % 5) == 0) {
                    func_801034F8_F4C08_CoffinCongestion(obj->trans.x, obj->trans.y, obj->trans.z);
                }
                break;
            case 4:
                obj->trans.y = HuMathSin(p->unk_24) * 30.0f + p->unk_20;
                p->unk_24 += 12.0f;
                if (p->unk_24 > 360.0f) {
                    p->unk_24 -= 360.0f;
                }
                break;
        }
    }
}

void func_80103884_F4F94_CoffinCongestion(omObjData* obj) {
    CCProp* p = ((CCGround*)obj->unk_50)->unk_B0;

    if (D_801069CC_F80DC_CoffinCongestion[func_80106570_F7C80_CoffinCongestion()] != NULL) {
        D_801069CC_F80DC_CoffinCongestion[func_80106570_F7C80_CoffinCongestion()](obj, p);
    }
    if (p->unk_0E < 0) {
        p->unk_0E = 0;
    }
    if (p->unk_0E >= 256) {
        p->unk_0E = 255;
    }
    func_8002D0A0_2DCA0(obj->model[0], p->unk_0E);
}

/* The host's entrance: walks in (1), hops over (2), turns to face the player (3). */
void func_80103938_F5048_CoffinCongestion(omObjData* obj, CCProp* p) {
    switch (p->unk_10) {
        case 0:
        case 4:
            break;
        case 1:
            func_80102860_F3F70_CoffinCongestion(obj, 1);
            obj->rot.y = 180.0f;
            obj->trans.z -= 25.0f;
            if (obj->trans.z < 210.0f) {
                obj->rot.y = -90.0f;
                p->unk_20 = -10.0f;
                p->unk_10++;
            }
            break;
        case 2:
            func_80102860_F3F70_CoffinCongestion(obj, 2);
            obj->trans.x -= 8.6f;
            obj->trans.y = 200.0f - p->unk_20 * p->unk_20 * 2.2f;
            p->unk_20 += 1.0f;
            if (p->unk_20 > 10.0f) {
                obj->rot.y = -45.0f;
                p->unk_10++;
            }
            break;
        case 3:
            obj->rot.y = 0.0f;
            func_80102860_F3F70_CoffinCongestion(obj, 3);
            p->unk_10++;
            break;
    }
}

/* A coffin during the shuffle: picks a new slot while the lids are up, moves there on the
   shake. */
void func_80103AB8_F51C8_CoffinCongestion(omObjData* obj, CCProp* p) {
    if (D_80106DB8_F84C8_CoffinCongestion.cur != 2) {
        if (p->unk_18 == 0) {
            D_80106DB8_F84C8_CoffinCongestion.idx += (u8)(rand8() % 3) + 1;
            if (D_80106DB8_F84C8_CoffinCongestion.idx >= 6) {
                D_80106DB8_F84C8_CoffinCongestion.idx -= 6;
            }
            p->unk_18 = 1;
        }
    } else if (p->unk_18 == 1) {
        func_80102944_F4054_CoffinCongestion(p, &p->pos);
        if (p->pos.z < 0.0f) {
            p->pos.z = -290.0f;
        } else {
            p->pos.z = 210.0f;
        }
        omSetTra(obj, p->pos.x, p->pos.y, p->pos.z);
        p->unk_18 = 0;
    }
}

/* The host after the pick: cheers (opened) or leaves. */
void func_80103BD8_F52E8_CoffinCongestion(omObjData* obj, CCProp* p) {
    if (p->unk_1E == 1) {
        if (p->unk_10++ >= 120) {
            if (p->unk_10 == 121) {
                PlaySound(0x13C);
            }
            func_80102860_F3F70_CoffinCongestion(obj, 4);
        }
    } else if (p->unk_10++ >= 94) {
        switch (p->unk_1A) {
            case 0:
                func_80102860_F3F70_CoffinCongestion(obj, 1);
                if (obj->trans.x < func_801055EC_F6CFC_CoffinCongestion()) {
                    p->unk_20 = -5.0f;
                } else {
                    p->unk_20 = 5.0f;
                }
                p->unk_1A++;
                break;
            case 1:
                obj->trans.x += p->unk_20;
                p->unk_20 *= 0.98f;
                obj->trans.z += 10.0f;
                if (obj->trans.z > 1000.0f) {
                    p->unk_1A++;
                }
                break;
        }
    }
}

void func_80103D50_F5460_CoffinCongestion(omObjData* obj) {
    if (D_801069EC_F80FC_CoffinCongestion[func_80106570_F7C80_CoffinCongestion()] != NULL) {
        D_801069EC_F80FC_CoffinCongestion[func_80106570_F7C80_CoffinCongestion()](obj, ((CCGround*)obj->unk_50)->unk_B0);
    }
    func_80029714_2A314(obj->model[1], obj->trans.x, 3.0f, obj->trans.z);
}

/* Sparkles over the player who opened the coffin. */
void func_80103DE0_F54F0_CoffinCongestion(omObjData* obj) {
    CCProp* p = ((CCGround*)obj->unk_50)->unk_B0;

    switch (p->unk_10) {
        case 1:
            omSetTra(obj, p->unk_14->trans.x, p->unk_14->trans.y, p->unk_14->trans.z);
            func_80029714_2A314(obj->model[p->unk_18], p->unk_14->trans.x, p->unk_14->trans.y + 180.0f,
                                p->unk_14->trans.z);
            func_80029FE4_2ABE4(obj->model[p->unk_18], (u8)(rand8() % 50) * 0.1f + 1.0f);
            func_800298A4_2A4A4(obj->model[p->unk_18], 4, 0);
            if (++p->unk_18 >= 6) {
                p->unk_18 -= 6;
            }
            p->unk_10++;
            break;
        case 2:
        case 3:
            p->unk_10++;
            break;
        case 4:
            p->unk_10 = 1;
            break;
    }
}

/* Creates the 27 room objects (D_80106600); 20-24 are the coffins' item models, 25 the host,
   26 the sparkles. */
void func_80103F88_F5698_CoffinCongestion(void) {
    omObjData* obj;
    CCGround* ground;
    CCProp* p;
    s32 i;
    s32 j;

    func_80076BD0_777D0(1, 27);
    D_80106DB0_F84C0_CoffinCongestion = func_80076D80_77980(1);
    D_800F8FE0_F9BE0 = 0;
    for (i = 0; i < 27; i++) {
        obj = omAddObj(3, D_80106600_F7D10_CoffinCongestion[i].unk_1A, D_80106600_F7D10_CoffinCongestion[i].unk_1B, 1,
                       D_80106A0C_F811C_CoffinCongestion[D_80106600_F7D10_CoffinCongestion[i].func]);
        D_80106DB0_F84C0_CoffinCongestion[i] = obj;
        ground = func_80027154_27D54(sizeof(CCGround), 0x7918);
        func_800B0EF0_B1AF0(ground, 0, sizeof(CCGround));
        ground->unk_03 = 1;
        ground->unk_08 = 0.5f;
        ground->unk_10 = 20.0f;
        ground->unk_04 = i;
        obj->unk_50 = ground;
        D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = obj;
        p = func_80027154_27D54(sizeof(CCProp), 0x7918);
        func_800B0EF0_B1AF0(p, 0, sizeof(CCProp));
        ground->unk_B0 = p;
        if (i >= 20 && i < 25) {
            p->unk_12 = D_800CAFD8[i - 20];
            D_80106600_F7D10_CoffinCongestion[i].file = D_801068F4_F8004_CoffinCongestion[p->unk_12];
        } else {
            p->unk_12 = -1;
        }
        obj->model[0] = func_80018A30_19630(D_80106600_F7D10_CoffinCongestion[i].file, D_80106600_F7D10_CoffinCongestion[i].attr);
        if (D_80106600_F7D10_CoffinCongestion[i].attr == 0x2A9 || D_80106600_F7D10_CoffinCongestion[i].attr == 0x6A9
            || D_80106600_F7D10_CoffinCongestion[i].attr == 0xAA9) {
            func_8002D124_2DD24(obj->model[0]);
            func_8002D0A0_2DCA0(obj->model[0], 0);
        }
        omSetTra(obj, D_80106600_F7D10_CoffinCongestion[i].pos.x, D_80106600_F7D10_CoffinCongestion[i].pos.y,
                 D_80106600_F7D10_CoffinCongestion[i].pos.z);
        omSetSca(obj, D_80106600_F7D10_CoffinCongestion[i].scale, D_80106600_F7D10_CoffinCongestion[i].scale,
                 D_80106600_F7D10_CoffinCongestion[i].scale);
        func_800B3170_B3D70(&p->pos, &D_80106600_F7D10_CoffinCongestion[i].pos);
        p->unk_0C = i;
        if (i == 26) {
            omSetSca(obj, 1.2f, 1.2f, 0.0f);
            for (j = 1; j < 6; j++) {
                obj->model[j] = func_80018A30_19630(D_80106600_F7D10_CoffinCongestion[i].file, D_80106600_F7D10_CoffinCongestion[i].attr);
                func_800297E8_2A3E8(obj->model[j], 1.2f, 1.2f, 0.0f);
            }
            for (j = 0; j < 6; j++) {
                func_80029FE4_2ABE4(obj->model[j], 0.0f);
                func_80029E80_2AA80(obj->model[j], 2, 2);
                func_800298A4_2A4A4(obj->model[j], 4, 4);
            }
        }
        if (i == 25) {
            obj->model[1] = func_80018A64_19664(13, 0x2B9);
            func_80029714_2A314(obj->model[1], D_801068BC_F7FCC_CoffinCongestion, D_801068C0_F7FD0_CoffinCongestion,
                                D_801068C4_F7FD4_CoffinCongestion);
            func_800297E8_2A3E8(obj->model[1], D_801068C8_F7FD8_CoffinCongestion, D_801068C8_F7FD8_CoffinCongestion,
                                D_801068C8_F7FD8_CoffinCongestion);
            for (j = 0; j < 5; j++) {
                obj->motion[j] = func_8002C8B8_2D4B8(DataRead(D_8010691C_F802C_CoffinCongestion[j].file), 0x18);
                if (obj->motion[j] < 0) {
                    while (1) {}
                }
                D_8010691C_F802C_CoffinCongestion[j].len = func_8002CA14_2D614(obj->motion[j]);
            }
            func_80102860_F3F70_CoffinCongestion(obj, 0);
            p->unk_12 = 10;
        }
    }
    func_8000C018_CC18(0);
    func_8000BF24_CB24(D_80106DB0_F84C0_CoffinCongestion[0], 3.0f, -650.0f, -450.0f, 650.0f, 450.0f);
}

void func_80104478_F5B88_CoffinCongestion(void) {
    func_8002D4D0_2E0D0(0x25);
    func_8002F290_2FE90(D_800F9D30_FA930, 0xC0);
    func_80103F88_F5698_CoffinCongestion();
    D_80106DB4_F84C4_CoffinCongestion = NULL;
    func_8002CA48_2D648(0, 0, 0);
    func_80029708_2A308(1);
}

void func_801044CC_F5BDC_CoffinCongestion(void) {
    s32 i;

    for (i = 0; i < 27; i++) {
        omDelObj(func_80076D98_77998(1, i));
    }
    if (D_80106DB4_F84C4_CoffinCongestion != NULL) {
        for (i = 0; i < 6; i++) {
            omDelObj(func_80076D98_77998(2, i));
        }
        D_80106DB4_F84C4_CoffinCongestion = NULL;
    }
    func_8002F1A4_2FDA4();
    func_8002CA48_2D648(0, 0, 0);
    func_80029708_2A308(1);
}

void func_80104570_F5C80_CoffinCongestion(omObjData* obj) {
    s32 i;

    for (i = 0; i < 27; i++) {
        func_8000C024_CC24(obj, i, 1);
    }
    for (i = 6; i < 12; i++) {
        func_8000C024_CC24(obj, i, 2);
    }
    func_8000C024_CC24(obj, 0, 2);
}

void func_801045E8_F5CF8_CoffinCongestion(s16 phase) {
    D_80106DB8_F84C8_CoffinCongestion.prev = D_80106DB8_F84C8_CoffinCongestion.cur;
    D_80106DB8_F84C8_CoffinCongestion.cur = phase;
}

/* Starts the item models' hops (objects 20-24). */
void func_80104600_F5D10_CoffinCongestion(void) {
    s32 i;

    for (i = 20; i < 25; i++) {
        s16* state = &((CCGround*)D_80106DB0_F84C0_CoffinCongestion[i]->unk_50)->unk_B0->unk_10;

        if (*state == 0) {
            (*state)++;
        }
    }
}

/* Starts the host's entrance (object 25). */
void func_80104650_F5D60_CoffinCongestion(void) {
    CCProp* p = ((CCGround*)D_80106DB0_F84C0_CoffinCongestion[25]->unk_50)->unk_B0;

    if (p->unk_10 == 0) {
        p->unk_10++;
    }
}

/* The slot holding `item`, or -1. */
s32 func_80104684_F5D94_CoffinCongestion(s32 item) {
    s32 i;

    for (i = 0; i < 6; i++) {
        if (D_80106DB8_F84C8_CoffinCongestion.slot[i]->unk_12 == item) {
            return i;
        }
    }
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_801046C8_F5DD8_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_80104878_F5F88_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_8010499C_F60AC_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_801049FC_F610C_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_80104A7C_F618C_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_80104AD4_F61E4_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_80104B60_F6270_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_80104BA8_F62B8_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_80104C30_F6340_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_80104DD8_F64E8_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_80104E20_F6530_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_80104E80_F6590_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_80105074_F6784_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_801051C0_F68D0_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_8010524C_F695C_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_801054C4_F6BD4_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_801055C4_F6CD4_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_801055EC_F6CFC_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_80105600_F6D10_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_80105638_F6D48_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_80105710_F6E20_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_801057A0_F6EB0_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_80105830_F6F40_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_80105884_F6F94_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_801059A8_F70B8_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_80105A98_F71A8_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_80105AB4_F71C4_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_80105C6C_F737C_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_80105CF0_F7400_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_80105D44_F7454_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_80105EE0_F75F0_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_80105F9C_F76AC_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_8010606C_F777C_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_8010609C_F77AC_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_801060E8_F77F8_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_80106118_F7828_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_80106314_F7A24_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_801064C8_F7BD8_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_80106534_F7C44_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_80106570_F7C80_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_8010657C_F7C8C_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_801065A8_F7CB8_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_801065B4_F7CC4_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_801065C0_F7CD0_CoffinCongestion);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_801065EC_F7CFC_CoffinCongestion);

__asm__(".section .rodata\n\t.balign 16\n\t.text");
