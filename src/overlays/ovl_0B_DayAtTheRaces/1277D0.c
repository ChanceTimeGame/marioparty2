#include "ovl_0B.h"

void func_80103FF0_1277D0_DayAtTheRaces(omObjData* obj, s32 idx, f32 y, f32 rot, f32 scale, f32 speed) {
    s16 m = obj->model[idx];

    if (func_80029CE4_2A8E4(m) >= func_80029D0C_2A90C(m)) {
        HmfData* hmf = D_800FC834_FD434[m].hmf;
        if (hmf->unk9C != NULL) {
            hmf->unk9C->unk08 = speed;
        }
        func_80029C74_2A874(m, speed);
    }
    func_800298A4_2A4A4(m, 4, 0);
    func_80029714_2A314(m, obj->trans.x, y, obj->trans.z);
    func_8002979C_2A39C(m, 0.0f, rot, 0.0f);
    func_800297E8_2A3E8(m, scale, scale, scale);
}

void func_80104128_127908_DayAtTheRaces(omObjData* obj) {
    s32 i;
    s16 m;

    for (i = 2; i < 4; i++) {
        m = obj->model[i];
        if (func_80029CE4_2A8E4(m) >= func_80029D0C_2A90C(m)) {
            func_800298A4_2A4A4(m, 4, 4);
        }
    }
}

void func_801041B8_127998_DayAtTheRaces(omObjData* obj, DRPlayer* w) {
    switch (w->state) {
        case 0:
            w->baseX = obj->trans.z;
            w->phase = 0.0f;
            w->baseRot = obj->rot.y;
            w->timer = func_80109DA0_12D580_DayAtTheRaces() == 2 ? (s16)PlaySound(0x168) : -1;
            w->state++;
            break;
        case 1:
            w->phase += 15.0f;
            if (w->phase > 360.0f) {
                w->phase -= 360.0f;
            }
            w->last = obj->trans.z;
            obj->trans.z = HuMathSin(w->phase) * 10.0f + w->baseX;
            obj->rot.y = func_800B75A8_B81A8(w->speed, obj->trans.z - w->last);
            break;
        case 200:
            if (w->timer != -1) {
                func_80079848_7A448((s16)w->timer);
            }
            obj->trans.z = w->baseX;
            obj->rot.y = w->baseRot;
            break;
    }
}

void func_8010430C_127AEC_DayAtTheRaces(omObjData* obj, DRPlayer* w) {
    if (w->state == 0) {
        if (func_80109DA0_12D580_DayAtTheRaces() == 2) {
            PlaySound(0x167);
            w->state++;
        }
    }
}

void func_80104364_127B44_DayAtTheRaces(omObjData* obj, DRPlayer* w) {
    if (w->alpha < 255) {
        w->alpha += 16;
    }
    if (w->alpha >= 256) {
        w->alpha = 255;
    }
    func_8002D0A0_2DCA0(obj->model[0], w->alpha);
}

void func_801043B4_127B94_DayAtTheRaces(omObjData* obj, DRPlayer* w) {
    if (w->alpha < 132) {
        w->timer = 2;
    } else if (w->alpha >= 251) {
        w->timer = -2;
    }
    w->alpha += w->timer;
    if (w->alpha >= 256) {
        w->alpha = 255;
    }
    func_8002D0A0_2DCA0(obj->model[0], w->alpha);
}

void func_80104424_127C04_DayAtTheRaces(omObjData* obj, DRPlayer* w) {
    if (w->alpha < 132) {
        w->timer = 16;
    } else if (w->alpha >= 251) {
        w->timer = -16;
    }
    w->alpha += w->timer;
    if (w->alpha >= 256) {
        w->alpha = 255;
    }
    func_8002D0A0_2DCA0(obj->model[0], w->alpha);
}

void func_80104494_127C74_DayAtTheRaces(omObjData* obj, DRPlayer* w) {
    func_80104364_127B44_DayAtTheRaces(obj, w);
    switch (w->state) {
        case 0:
            w->baseX = obj->trans.y;
            w->phase = 0.0f;
            w->state++;
            break;
        case 1:
            w->phase += 10.0f;
            if (w->phase > 360.0f) {
                w->phase -= 360.0f;
            }
            obj->trans.y = HuMathSin(w->phase) * 15.0f + w->baseX;
            obj->rot.z = HuMathSin(w->phase) * 10.0f - 5.0f;
            break;
        case 200:
            obj->trans.y = w->baseX;
            obj->rot.z = 0.0f;
            break;
    }
}

void func_801045B4_127D94_DayAtTheRaces(omObjData* obj, DRPlayer* w) {
    switch (w->state) {
        case 0:
            w->timer = 0;
            w->baseX = 0.0f;
            w->busy = 1;
            w->lock = 1;
            w->state++;
            obj->rot.z = 0.0f;
            return;
        case 1:
            w->alpha -= 15;
            if (w->alpha < 0) {
                w->alpha = 0;
                w->state++;
            }
            w->baseX += 8.0f;
            break;
        case 2:
            w->x += w->baseX;
            obj->trans.x = w->x;
            if (func_80109DA0_12D580_DayAtTheRaces() == 2) {
                PlaySound(0x169);
            }
            w->state++;
            return;
        case 3:
            w->alpha += 15;
            if (w->alpha >= 256) {
                w->alpha = 255;
                w->busy = 0;
                w->lock = 0;
                w->state++;
            }
            break;
        case 4:
            if (w->timer++ >= 16) {
                w->state = 0;
            }
            return;
        case 200:
            w->alpha = 255;
            w->busy = 0;
            w->lock = 0;
            break;
        default:
            return;
    }
    func_8002D0A0_2DCA0(obj->model[0], w->alpha);
}

void func_80104744_127F24_DayAtTheRaces(omObjData* obj, DRPlayer* w) {
    w->busy = 1;
}

void func_80104750_127F30_DayAtTheRaces(omObjData* obj, DRPlayer* w) {
    Vec v;

    switch (w->state) {
        case 0:
            w->timer2 = 0;
            w->timer = 0;
            w->baseX = 0.0f;
            w->phase = -90.0f;
            w->lock = 1;
            w->busy = 1;
            w->state++;
            obj->rot.z = 0.0f;
            break;
        case 1:
            obj->trans.y += 1.8f;
            if (obj->trans.y > 50.0f) {
                w->state++;
            }
            goto scale;
        case 2:
            if (w->timer++ >= 16) {
                w->state++;
            }
            break;
        case 3:
            obj->trans.y -= w->baseX;
            if (obj->trans.y < 0.0f) {
                obj->trans.y = 0.0f;
                w->lock = 0;
                func_80103FF0_1277D0_DayAtTheRaces(obj, 3, 0.05f, 0.0f, 0.5f, 4.0f);
                if (func_80109DA0_12D580_DayAtTheRaces() == 2) {
                    PlaySound(0x16A);
                }
                w->state++;
            }
            w->baseX += 4.2f;
        scale:
            HuVecMulScalar(&v, 0.85f - obj->trans.y / 50.0f * 0.15f, &D_8010A538_12DD18_DayAtTheRaces[w->index].shadow);
            func_800297E8_2A3E8(obj->model[1], v.x, v.y, v.z);
            break;
        case 4:
            w->phase += 90.0f;
            if (w->phase > 270.0f) {
                w->state++;
            }
            obj->trans.y = HuMathSin(w->phase) * 2.5f + 2.5f;
            break;
        case 5:
            if (w->timer2++ >= 16) {
                w->state = 0;
            }
            break;
        case 200:
            w->lock = 0;
            w->busy = 0;
            break;
    }
}

void func_80104A40_128220_DayAtTheRaces(omObjData* obj, DRPlayer* w) {
    Vec v;

    switch (w->state) {
        case 0:
            w->timer2 = 0;
            w->timer = 0;
            w->baseX = 0.0f;
            w->phase = -90.0f;
            w->lock = 1;
            w->busy = 1;
            w->state++;
            break;
        case 1:
            obj->trans.y += 12.0f;
            if (obj->trans.y > 50.0f) {
                w->state++;
            }
            goto scale;
        case 2:
            if (w->timer++ >= 6) {
                w->state++;
            }
            break;
        case 3:
            obj->trans.y -= w->baseX;
            if (obj->trans.y < 0.0f) {
                obj->trans.y = 0.0f;
                w->lock = 0;
                func_80103FF0_1277D0_DayAtTheRaces(obj, 3, 0.05f, 0.0f, 0.5f, 4.0f);
                if (func_80109DA0_12D580_DayAtTheRaces() == 2) {
                    PlaySound(0x16A);
                }
                w->state++;
            }
            w->baseX += 4.2f;
        scale:
            HuVecMulScalar(&v, 0.85f - obj->trans.y / 50.0f * 0.15f, &D_8010A538_12DD18_DayAtTheRaces[w->index].shadow);
            func_800297E8_2A3E8(obj->model[1], v.x, v.y, v.z);
            break;
        case 4:
            w->phase += 60.0f;
            if (w->phase > 270.0f) {
                w->state++;
            }
            obj->trans.y = HuMathSin(w->phase) * 5.0f + 5.0f;
            break;
        case 5:
            if (w->timer2++ >= 16) {
                w->state = 0;
            }
            break;
        case 200:
            w->lock = 0;
            w->busy = 0;
            break;
    }
}

void func_80104D1C_1284FC_DayAtTheRaces(omObjData* obj, DRPlayer* w) {
    Vec v;

    switch (w->state) {
        case 0:
            w->timer2 = 0;
            w->timer = 0;
            w->baseX = 0.0f;
            w->phase = -90.0f;
            w->lock = 1;
            w->busy = 1;
            w->state++;
            break;
        case 1:
            obj->trans.y += 8.0f;
            if (obj->trans.y > 50.0f) {
                w->state++;
            }
            goto scale;
        case 2:
            if (w->timer++ >= 31) {
                w->state++;
            }
            w->x += w->accel * 1.8f + 0.4f;
            obj->trans.x = w->x;
            break;
        case 3:
            obj->trans.y -= w->baseX;
            if (obj->trans.y < 0.0f) {
                obj->trans.y = 0.0f;
                w->lock = 0;
                func_80103FF0_1277D0_DayAtTheRaces(obj, 3, 0.05f, 0.0f, 0.5f, 4.0f);
                if (func_80109DA0_12D580_DayAtTheRaces() == 2) {
                    PlaySound(0x16A);
                }
                w->state++;
            }
            w->baseX += 4.2f;
        scale:
            HuVecMulScalar(&v, 0.85f - obj->trans.y / 50.0f * 0.15f, &D_8010A538_12DD18_DayAtTheRaces[w->index].shadow);
            func_800297E8_2A3E8(obj->model[1], v.x, v.y, v.z);
            break;
        case 4:
            w->phase += 90.0f;
            if (w->phase > 270.0f) {
                w->state++;
            }
            obj->trans.y = HuMathSin(w->phase) * 2.5f + 2.5f;
            break;
        case 5:
            if (w->timer2++ >= 16) {
                w->state = 0;
            }
            break;
        case 200:
            w->lock = 0;
            w->busy = 0;
            break;
    }
}

void func_80105040_128820_DayAtTheRaces(omObjData* obj, DRPlayer* w) {
    Vec v;

    switch (w->state) {
        case 0:
            w->timer2 = 0;
            w->timer = 0;
            w->baseX = 0.0f;
            w->phase = -90.0f;
            w->lock = 1;
            w->busy = 1;
            w->state++;
            break;
        case 1:
            obj->trans.y += 12.0f;
            if (obj->trans.y > 50.0f) {
                w->state++;
            }
            goto scale;
        case 2:
            if (w->timer++ >= 31) {
                w->baseX = 0.0f;
                w->state++;
            }
            w->baseX += 6.0f;
            obj->rot.z = HuMathSin(w->baseX) * -20.0f;
            w->x += 6.8f;
            obj->trans.x = w->x;
            break;
        case 3:
            obj->trans.y -= w->baseX;
            if (obj->trans.y < 0.0f) {
                obj->trans.y = 0.0f;
                w->lock = 0;
                func_80103FF0_1277D0_DayAtTheRaces(obj, 3, 0.05f, 0.0f, 0.5f, 4.0f);
                if (func_80109DA0_12D580_DayAtTheRaces() == 2) {
                    PlaySound(0x16A);
                }
                w->state++;
            }
            w->baseX += 4.2f;
        scale:
            HuVecMulScalar(&v, 0.85f - obj->trans.y / 50.0f * 0.15f, &D_8010A538_12DD18_DayAtTheRaces[w->index].shadow);
            func_800297E8_2A3E8(obj->model[1], v.x, v.y, v.z);
            break;
        case 4:
            w->phase += 60.0f;
            if (w->phase > 270.0f) {
                w->state++;
            }
            obj->trans.y = HuMathSin(w->phase) * 5.0f + 5.0f;
            break;
        case 5:
            if (w->timer2++ >= 16) {
                w->state = 0;
            }
            break;
        case 200:
            w->lock = 0;
            w->busy = 0;
            break;
    }
}

void func_8010537C_128B5C_DayAtTheRaces(omObjData* obj, DRPlayer* w) {
    if (++w->state == 6) {
        if (func_80109DA0_12D580_DayAtTheRaces() == 2) {
            PlaySound(0x16B);
        }
    }
}

s32 func_801053D0_128BB0_DayAtTheRaces(omObjData* obj, s32 mot) {
    DRPlayer* w = obj->unk_50;

    if (w->motion == mot) {
        return 0;
    }
    if (w->lock != 0) {
        return 0;
    }
    w->state = 200;
    if (w->motion >= 0 && D_8010A638_12DE18_DayAtTheRaces[w->index][w->motion].func != NULL) {
        D_8010A638_12DE18_DayAtTheRaces[w->index][w->motion].func(obj, w);
    }
    w->motion = mot;
    w->state = 0;
    if (D_8010A638_12DE18_DayAtTheRaces[w->index][mot].loop == 1) {
        mot = 0;
    }
    func_80029FE4_2ABE4(obj->model[0], 1.0f);
    if (D_8010A638_12DE18_DayAtTheRaces[w->index][mot].start < 0) {
        func_80029BF0_2A7F0(obj->model[0], obj->motion[mot], 0, 5, 0);
    } else {
        func_80029BF0_2A7F0(obj->model[0], obj->motion[mot], 0, 5, 2);
        func_80029FBC_2ABBC(obj->model[0], D_8010A638_12DE18_DayAtTheRaces[w->index][mot].start);
    }
    func_80029FE4_2ABE4(obj->model[0], D_8010A638_12DE18_DayAtTheRaces[w->index][mot].speed);
    return 1;
}

void func_801055E4_128DC4_DayAtTheRaces(omObjData* obj, s32 mot, f32 t) {
    DRPlayer* w = obj->unk_50;

    if (mot >= 0 && D_8010A638_12DE18_DayAtTheRaces[w->index][mot].loop != 1) {
        w->state = 0;
        func_80029FE4_2ABE4(obj->model[0], 1.0f);
        if (D_8010A638_12DE18_DayAtTheRaces[w->index][mot].start < 0) {
            func_80029BF0_2A7F0(obj->model[0], obj->motion[mot], 0, 1, 0);
        } else {
            func_80029BF0_2A7F0(obj->model[0], obj->motion[mot], 0, 5, 2);
            func_80029FBC_2ABBC(obj->model[0], D_8010A638_12DE18_DayAtTheRaces[w->index][mot].start);
        }
        func_80029FE4_2ABE4(obj->model[0], D_8010A638_12DE18_DayAtTheRaces[w->index][mot].speed);
        func_80029C74_2A874(obj->model[0], t);
    }
}

s32 func_801057AC_128F8C_DayAtTheRaces(omObjData* obj) {
    DRPlayer* w = obj->unk_50;
    s32 t;

    if (D_8010A638_12DE18_DayAtTheRaces[w->index][w->motion].start < 0) {
        t = func_80029E3C_2AA3C(obj->model[0]);
        if (t == -1) {
            t = func_80029CE4_2A8E4(obj->model[0]);
        }
        if (t < D_8010A638_12DE18_DayAtTheRaces[w->index][w->motion].end) {
            return 0;
        }
        w->motion = -1;
        return 1;
    }
    return 0;
}

void func_80105894_129074_DayAtTheRaces(omObjData* obj, f32 speed) {
    func_80029FE4_2ABE4(obj->model[0], speed);
}

void func_801058B4_129094_DayAtTheRaces(void) {
    DRSave* p = &D_8010AC50_12E430_DayAtTheRaces;
    s32 i;

    if (p->flag != 1) {
        p->frame = func_80109DD8_12D5B8_DayAtTheRaces();
        p->seed = func_80109B20_12D300_DayAtTheRaces();
        for (i = 0; i < 4; i++) {
            D_8010AC68_12E448_DayAtTheRaces[i] = D_8010AC3C_12E41C_DayAtTheRaces[i];
            D_8010AC6C_12E44C_DayAtTheRaces[i] = *(DRPlayer*)D_8010AC20_12E400_DayAtTheRaces.objs[i]->unk_50;
            D_8010AE1C_12E5FC_DayAtTheRaces[i] = D_8010AC20_12E400_DayAtTheRaces.objs[i]->trans.y;
            D_8010AE0C_12E5EC_DayAtTheRaces[i] = func_80029CE4_2A8E4(D_8010AC20_12E400_DayAtTheRaces.objs[i]->model[0]);
        }
        for (i = 0; i < 4; i++) {
            D_8010AC60_12E440_DayAtTheRaces[i] = ((DRMark*)D_8010AC24_12E404_DayAtTheRaces.objs[i]->unk_50)->value;
        }
        D_8010AC50_12E430_DayAtTheRaces.flag = 1;
        for (i = 0; i < 9; i++) {
            D_8010AE30_12E610_DayAtTheRaces[i] = D_8010A524_12DD04_DayAtTheRaces[i];
        }
    }
}

void func_80105A94_129274_DayAtTheRaces(void) {
    s32 i;
    omObjData* obj;
    DRPlayer* w;
    s16 mot;

    func_80109AFC_12D2DC_DayAtTheRaces(D_8010AC50_12E430_DayAtTheRaces.seed);
    for (i = 0; i < 4; i++) {
        obj = D_8010AC20_12E400_DayAtTheRaces.objs[i];
        D_8010AC3C_12E41C_DayAtTheRaces[i] = D_8010AC68_12E448_DayAtTheRaces[i];
        D_8010AC40_12E420_DayAtTheRaces[i] = D_8010AC68_12E448_DayAtTheRaces[i];
        mot = ((DRPlayer*)obj->unk_50)->motion;
        *(DRPlayer*)obj->unk_50 = D_8010AC6C_12E44C_DayAtTheRaces[i];
        obj->trans.x = ((DRPlayer*)obj->unk_50)->x;
        obj->trans.y = D_8010AE1C_12E5FC_DayAtTheRaces[i];
        if (((DRPlayer*)obj->unk_50)->motion != mot) {
            func_801055E4_128DC4_DayAtTheRaces(obj, ((DRPlayer*)obj->unk_50)->motion, D_8010AE0C_12E5EC_DayAtTheRaces[i]);
        }
        if (((DRPlayer*)obj->unk_50)->index == 1) {
            func_8002D0A0_2DCA0(obj->model[0], ((DRPlayer*)obj->unk_50)->alpha);
        }
    }
    for (i = 0; i < 4; i++) {
        ((DRMark*)D_8010AC24_12E404_DayAtTheRaces.objs[i]->unk_50)->value = D_8010AC60_12E440_DayAtTheRaces[i];
    }
    for (i = 0; i < 9; i++) {
        D_8010A524_12DD04_DayAtTheRaces[i] = D_8010AE30_12E610_DayAtTheRaces[i];
    }
}

void func_80105C84_129464_DayAtTheRaces(void) {
    s32 i;
    s32 j;
    DRPlayer* a;
    DRPlayer* b;
    s32 t;

    for (i = 0; i < 4; i++) {
        D_8010AE48_12E628_DayAtTheRaces[i] = i;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            a = D_8010AC20_12E400_DayAtTheRaces.objs[D_8010AE48_12E628_DayAtTheRaces[j]]->unk_50;
            b = D_8010AC20_12E400_DayAtTheRaces.objs[D_8010AE48_12E628_DayAtTheRaces[j + 1]]->unk_50;
            if (a->gear < b->gear || (a->gear == b->gear && (rand8() & 1))) {
                t = D_8010AE48_12E628_DayAtTheRaces[j];
                D_8010AE48_12E628_DayAtTheRaces[j] = D_8010AE48_12E628_DayAtTheRaces[j + 1];
                D_8010AE48_12E628_DayAtTheRaces[j + 1] = t;
            }
        }
    }
}

omObjData* func_80105D9C_12957C_DayAtTheRaces(s32 i) {
    return D_8010AC20_12E400_DayAtTheRaces.objs[D_8010AE48_12E628_DayAtTheRaces[i]];
}

void func_80105DC4_1295A4_DayAtTheRaces(void) {
    s32 i;
    s32 j;
    s32 a;
    s32 b;

    for (i = 0; i < 4; i++) {
        D_8010AE58_12E638_DayAtTheRaces[i] = i;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            a = D_8010AE58_12E638_DayAtTheRaces[j];
            b = D_8010AE58_12E638_DayAtTheRaces[j + 1];
            if (D_8010AC20_12E400_DayAtTheRaces.objs[a]->trans.x < D_8010AC20_12E400_DayAtTheRaces.objs[b]->trans.x) {
                D_8010AE58_12E638_DayAtTheRaces[j] = b;
                D_8010AE58_12E638_DayAtTheRaces[j + 1] = a;
            }
        }
    }
}

omObjData* func_80105E80_129660_DayAtTheRaces(s32 i) {
    return D_8010AC20_12E400_DayAtTheRaces.objs[D_8010AE58_12E638_DayAtTheRaces[i]];
}

s32 func_80105EA8_129688_DayAtTheRaces(f32 x) {
    s32 i;

    for (i = 0; i < 9; i++) {
        if (x < D_8010A500_12DCE0_DayAtTheRaces[i]) {
            return i - 1;
        }
    }
    return 0;
}

f32 func_80105EF0_1296D0_DayAtTheRaces(DRPlayer* w) {
    s32 i;
    f32 min = 10000.0f;
    DRPlayer* o;
    f32 d;

    for (i = 0; i < 4; i++) {
        o = D_8010AC20_12E400_DayAtTheRaces.objs[i]->unk_50;
        if (w != o) {
            d = o->x - w->x;
            if (d < 0.0f) {
                d = -d;
            }
            if (d < min) {
                min = d;
            }
        }
    }
    return min;
}

void func_80105F70_129750_DayAtTheRaces(omObjData* obj, DRPlayer* w) {
    switch (w->unk_54) {
        case 0:
            w->sub = 0;
            w->unk_54++;
            break;
        case 1:
            if (w->sub++ >= 86) {
                w->unk_54++;
            }
            break;
        case 2:
            w->mode = 1;
            w->unk_54 = 0;
            w->unk_50 = 0;
            w->wait = 0;
            w->sub = 0;
            break;
    }
}

void func_80105FE8_1297C8_DayAtTheRaces(omObjData* obj, DRPlayer* w) {
    func_801053D0_128BB0_DayAtTheRaces(obj, 3);
    if (w->speed < w->accel) {
        w->boost = 0.8f;
    }
}

void func_8010603C_12981C_DayAtTheRaces(omObjData* obj, DRPlayer* w) {
    func_801053D0_128BB0_DayAtTheRaces(obj, 4);
    if (w->speed < 3.2f) {
        w->boost = 0.8f;
        if (w->index == 0) {
            func_80103FF0_1277D0_DayAtTheRaces(obj, 2, 0.05f, obj->rot.y - 90.0f, 0.36f, 0.0f);
        } else if (w->index == 3) {
            func_80103FF0_1277D0_DayAtTheRaces(obj, 2, 0.05f, obj->rot.y - 90.0f, 0.22f, 0.0f);
        }
    }
}

void func_80106128_129908_DayAtTheRaces(omObjData* obj, DRPlayer* w) {
    w->speed *= 0.92f;
    switch (w->sub) {
        case 0:
            if (func_801053D0_128BB0_DayAtTheRaces(obj, 5) == 1) {
                if (w->index == 3) {
                    func_80103FF0_1277D0_DayAtTheRaces(obj, 3, 0.05f, 0.0f, 1.5f, 0.0f);
                    func_80029714_2A314(obj->model[3], obj->trans.x + 30.0f, 0.05f, obj->trans.z);
                }
                omVibrate(w->port, 10, 0, 10);
                w->sub++;
            }
            break;
        case 1:
            if (func_801057AC_128F8C_DayAtTheRaces(obj) != 0) {
                w->wait = 45;
                w->sub++;
            }
            break;
        case 2:
            func_801053D0_128BB0_DayAtTheRaces(obj, 6);
            if (w->wait-- < 0) {
                w->sub++;
            }
            break;
        case 3:
            func_801053D0_128BB0_DayAtTheRaces(obj, 7);
            w->sub++;
            break;
        case 4:
            if (func_801057AC_128F8C_DayAtTheRaces(obj) != 0) {
                w->sub++;
            }
            break;
        case 5:
            w->mode = 2;
            w->wait = 0;
            w->sub = 0;
            break;
    }
}

void func_801062A8_129A88_DayAtTheRaces(omObjData* obj, DRPlayer* w) {
    if (w->gear < 0) {
        w->gear = D_8010A4E0_12DCC0_DayAtTheRaces[w->index][rand8() & 7];
        switch (w->gear) {
            case 0:
                func_801053D0_128BB0_DayAtTheRaces(obj, 1);
                w->accel = 2.2f;
                break;
            case 1:
                func_801053D0_128BB0_DayAtTheRaces(obj, 0);
                w->accel = 2.4f;
                break;
            case 2:
                func_801053D0_128BB0_DayAtTheRaces(obj, 2);
                w->accel = 2.6f;
                break;
            default:
                while (1) {
                }
        }
        w->accel += rand8() % 150 * 0.001f - 0.1f;
        if (w->index == 0) {
            w->accel += 0.2f;
        }
    }
}

void func_80106454_129C34_DayAtTheRaces(omObjData* obj, DRPlayer* w) {
    switch (w->sub) {
        case 1:
            if (func_801053D0_128BB0_DayAtTheRaces(obj, 8) == 1) {
                w->sub++;
            }
            break;
        case 2:
            if (func_801057AC_128F8C_DayAtTheRaces(obj) != 0) {
                w->sub++;
            }
            break;
        case 3:
            if (DRF_ABS(obj->rot.y - 90.0f) < 5.0f) {
                obj->rot.y = 90.0f;
                w->sub++;
            } else {
                obj->rot.y += 15.0f;
            }
            break;
        case 4:
            if (obj->trans.x > D_8010A500_12DCE0_DayAtTheRaces[0]) {
                if (w->index == 2 && w->state == 2) {
                    w->state = 3;
                }
                w->speed = 0.0f;
                w->x = D_8010A500_12DCE0_DayAtTheRaces[0];
                w->sub++;
            } else {
                w->boost = 0.8f;
                if (w->speed > 2.4f) {
                    w->speed = 2.4f;
                }
                func_801053D0_128BB0_DayAtTheRaces(obj, 3);
            }
            break;
        case 5:
            switch (w->gear) {
                case 0:
                    if (func_801053D0_128BB0_DayAtTheRaces(obj, 1) == 1) {
                        w->sub++;
                    }
                    break;
                case 1:
                    if (func_801053D0_128BB0_DayAtTheRaces(obj, 0) == 1) {
                        w->sub++;
                    }
                    break;
                case 2:
                    if (func_801053D0_128BB0_DayAtTheRaces(obj, 2) == 1) {
                        w->sub++;
                    }
                    break;
            }
            break;
        case 6:
            D_8010AC35_12E415_DayAtTheRaces++;
            w->sub++;
            break;
    }
}

void func_801066CC_129EAC_DayAtTheRaces(omObjData* obj, DRPlayer* w) {
    if (D_8010A908_12E0E8_DayAtTheRaces[w->mode] != NULL) {
        D_8010A908_12E0E8_DayAtTheRaces[w->mode](obj, w);
    }
}

void func_80106704_129EE4_DayAtTheRaces(omObjData* obj, DRPlayer* w) {
    func_801053D0_128BB0_DayAtTheRaces(obj, 3);
    if (w->speed < 2.4f) {
        w->boost = 0.8f;
    }
}

void func_80106764_129F44_DayAtTheRaces(omObjData* obj) {
    DRPlayer* w = obj->unk_50;

    if (D_8010A918_12E0F8_DayAtTheRaces[func_80109DA0_12D580_DayAtTheRaces()] != NULL) {
        D_8010A918_12E0F8_DayAtTheRaces[func_80109DA0_12D580_DayAtTheRaces()](obj, w);
    }
    if (D_8010AC3A_12E41A_DayAtTheRaces == 1) {
        func_80105894_129074_DayAtTheRaces(obj, 0.0f);
        func_80029FE4_2ABE4(obj->model[2], 0.0f);
        func_80029FE4_2ABE4(obj->model[3], 0.0f);
        func_80103EC4_1276A4_DayAtTheRaces(1);
    } else {
        func_80105894_129074_DayAtTheRaces(obj, 1.0f);
        func_80029FE4_2ABE4(obj->model[2], 1.0f);
        func_80029FE4_2ABE4(obj->model[3], 1.0f);
        func_80103EC4_1276A4_DayAtTheRaces(0);
        if (w->motion >= 0 && D_8010A638_12DE18_DayAtTheRaces[w->index][w->motion].func != NULL) {
            D_8010A638_12DE18_DayAtTheRaces[w->index][w->motion].func(obj, w);
        }
        func_80104128_127908_DayAtTheRaces(obj);
        if ((u16)(w->motion - 3) < 5) {
            w->anim = D_8010A5E8_12DDC8_DayAtTheRaces[w->index][w->motion - 3] * D_8010A538_12DD18_DayAtTheRaces[w->index].scale;
        } else {
            w->anim = 0.0f;
        }
        if (w->busy == 0) {
            w->speed *= 0.98f;
            w->speed += w->boost;
            w->boost = 0.0f;
            w->x += w->speed;
            obj->trans.x = w->x;
        }
        if (obj->model[1] >= 0) {
            func_80029714_2A314(obj->model[1], obj->trans.x, 0.05f, obj->trans.z);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0B_DayAtTheRaces/1277D0", func_80106990_12A170_DayAtTheRaces);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0B_DayAtTheRaces/1277D0", func_80106D5C_12A53C_DayAtTheRaces);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0B_DayAtTheRaces/1277D0", func_80106DE4_12A5C4_DayAtTheRaces);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0B_DayAtTheRaces/1277D0", func_80107368_12AB48_DayAtTheRaces);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0B_DayAtTheRaces/1277D0", func_80107400_12ABE0_DayAtTheRaces);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0B_DayAtTheRaces/1277D0", func_801074A0_12AC80_DayAtTheRaces);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0B_DayAtTheRaces/1277D0", func_80107520_12AD00_DayAtTheRaces);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0B_DayAtTheRaces/1277D0", func_801076AC_12AE8C_DayAtTheRaces);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0B_DayAtTheRaces/1277D0", func_80107788_12AF68_DayAtTheRaces);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0B_DayAtTheRaces/1277D0", func_80107894_12B074_DayAtTheRaces);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0B_DayAtTheRaces/1277D0", func_801078B0_12B090_DayAtTheRaces);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0B_DayAtTheRaces/1277D0", func_8010796C_12B14C_DayAtTheRaces);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0B_DayAtTheRaces/1277D0", func_80107A44_12B224_DayAtTheRaces);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0B_DayAtTheRaces/1277D0", func_80107B20_12B300_DayAtTheRaces);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0B_DayAtTheRaces/1277D0", func_80107C5C_12B43C_DayAtTheRaces);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0B_DayAtTheRaces/1277D0", func_80107D10_12B4F0_DayAtTheRaces);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0B_DayAtTheRaces/1277D0", func_80107FF8_12B7D8_DayAtTheRaces);

__asm__(".section .rodata");
const char D_8010ABD0_12E3B0_DayAtTheRaces[] = "\202q\202d\202o\202k\202`\202x";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0B_DayAtTheRaces/1277D0", func_80108034_12B814_DayAtTheRaces);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0B_DayAtTheRaces/1277D0", func_80108304_12BAE4_DayAtTheRaces);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0B_DayAtTheRaces/1277D0", func_80108374_12BB54_DayAtTheRaces);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0B_DayAtTheRaces/1277D0", func_80108414_12BBF4_DayAtTheRaces);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0B_DayAtTheRaces/1277D0", func_80108458_12BC38_DayAtTheRaces);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0B_DayAtTheRaces/1277D0", func_80108614_12BDF4_DayAtTheRaces);
