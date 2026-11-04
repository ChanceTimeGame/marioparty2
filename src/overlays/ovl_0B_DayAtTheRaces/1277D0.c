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
    s32 i;

    if (D_8010AC50_12E430_DayAtTheRaces.flag != 1) {
        D_8010AC50_12E430_DayAtTheRaces.frame = func_80109DD8_12D5B8_DayAtTheRaces();
        D_8010AC50_12E430_DayAtTheRaces.seed = func_80109B20_12D300_DayAtTheRaces();
        for (i = 0; i < 4; i++) {
            D_8010AC68_12E448_DayAtTheRaces[i] = D_8010AC34_12E414_DayAtTheRaces.mark[i];
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

/* NON_MATCHING: register allocation (masked 17): retail keeps D_8010AE0C in a saved register across the loop */
#ifdef NON_MATCHING
void func_80105A94_129274_DayAtTheRaces(void) {
    s32 i;
    omObjData* obj;
    s32 mot;

    func_80109AFC_12D2DC_DayAtTheRaces(D_8010AC50_12E430_DayAtTheRaces.seed);
    for (i = 0; i < 4; i++) {
        obj = D_8010AC20_12E400_DayAtTheRaces.objs[i];
        D_8010AC34_12E414_DayAtTheRaces.mark[i] = D_8010AC68_12E448_DayAtTheRaces[i];
        D_8010AC34_12E414_DayAtTheRaces.prev[i] = D_8010AC68_12E448_DayAtTheRaces[i];
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
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0B_DayAtTheRaces/1277D0", func_80105A94_129274_DayAtTheRaces);
#endif

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
    omObjData* x;
    omObjData* y;

    for (i = 0; i < 4; i++) {
        D_8010AE58_12E638_DayAtTheRaces[i] = i;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            x = D_8010AC20_12E400_DayAtTheRaces.objs[D_8010AE58_12E638_DayAtTheRaces[j]];
            y = D_8010AC20_12E400_DayAtTheRaces.objs[D_8010AE58_12E638_DayAtTheRaces[j + 1]];
            if (x->trans.x < y->trans.x) {
                a = D_8010AE58_12E638_DayAtTheRaces[j];
                D_8010AE58_12E638_DayAtTheRaces[j] = D_8010AE58_12E638_DayAtTheRaces[j + 1];
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
    s32 i = 0;
    f32 min = 10000.0f;
    DRPlayer* o;
    f32 d;

    for (; i < 4; i++) {
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
    s32 r;

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
                w->accel = 2.6000001f;
                break;
            default:
                while (1) {
                }
        }
        r = rand8();
        w->accel += r % 300 * 0.001f - 0.1f;
        if (w->index == 0) {
            w->accel += 0.2f;
        }
    }
}

void func_80106454_129C34_DayAtTheRaces(omObjData* obj, DRPlayer* w) {
    switch (w->sub) {
        case 0:
        case 7:
            break;
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
            D_8010AC34_12E414_DayAtTheRaces.done++;
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
    if (D_8010AC34_12E414_DayAtTheRaces.replay == 1) {
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

/* NON_MATCHING: control flow (masked 15): retail branches on idx < 2 for the file; GCC here folds it to store-flag arithmetic */
#ifdef NON_MATCHING
void func_80106990_12A170_DayAtTheRaces(omObjData* obj, s32 idx) {
    DRPlayer* w;
    s32 i;

    obj->model[0] = LoadFormFile(D_8010A538_12DD18_DayAtTheRaces[idx].file, D_8010A538_12DD18_DayAtTheRaces[idx].attr);
    if (D_8010A538_12DD18_DayAtTheRaces[idx].shadowFile != 0) {
        if (D_8010A538_12DD18_DayAtTheRaces[idx].attr == 0xAC9) {
            obj->model[1] = LoadFormFile(D_8010A538_12DD18_DayAtTheRaces[idx].shadowFile, 0x649);
        } else {
            obj->model[1] = LoadFormFile(D_8010A538_12DD18_DayAtTheRaces[idx].shadowFile, 0x659);
        }
    } else {
        obj->model[1] = -1;
    }
    obj->model[2] = LoadFormFile(idx >= 2 ? 0x1B0019 : 0x1B0018, 0xA8D);
    obj->model[3] = LoadFormFile(0x1B001A, 0xA8D);
    if (D_8010A538_12DD18_DayAtTheRaces[idx].attr == 0xAC9) {
        func_8002D124_2DD24(obj->model[0]);
        func_8002D124_2DD24(obj->model[1]);
        func_8002D0A0_2DCA0(obj->model[0], 0xFF);
        func_8002D0A0_2DCA0(obj->model[1], 0xFF);
    }
    w = func_80027154_27D54(sizeof(DRPlayer), 0x7918);
    if (w == NULL) {
        while (1) {
        }
    }
    func_800B0EF0_B1AF0(w, 0, sizeof(DRPlayer));
    obj->unk_50 = w;
    for (i = 0; i < 9; i++) {
        if (D_8010A638_12DE18_DayAtTheRaces[idx][i].loop != 1) {
            obj->motion[i] = func_8002C8B8_2D4B8(DataRead(D_8010A638_12DE18_DayAtTheRaces[idx][i].file), 0x18);
            if (obj->motion[i] < 0) {
                while (1) {
                }
            }
            D_8010A638_12DE18_DayAtTheRaces[idx][i].end = func_8002CA14_2D614(obj->motion[i]);
        }
    }
    func_80029FE4_2ABE4(obj->model[0], 0.0f);
    w->index = idx;
    omSetTra(obj, D_8010A538_12DD18_DayAtTheRaces[idx].pos.x, D_8010A538_12DD18_DayAtTheRaces[idx].pos.y, D_8010A538_12DD18_DayAtTheRaces[idx].pos.z);
    omSetSca(obj, D_8010A538_12DD18_DayAtTheRaces[idx].scale, D_8010A538_12DD18_DayAtTheRaces[idx].scale, D_8010A538_12DD18_DayAtTheRaces[idx].scale);
    omSetRot(obj, 0.0f, -90.0f, 0.0f);
    if (obj->model[1] >= 0) {
        func_80029714_2A314(obj->model[1], D_8010A538_12DD18_DayAtTheRaces[idx].pos.x, 0.05f, D_8010A538_12DD18_DayAtTheRaces[idx].pos.z);
        func_800297E8_2A3E8(obj->model[1], D_8010A538_12DD18_DayAtTheRaces[idx].shadow.x, D_8010A538_12DD18_DayAtTheRaces[idx].shadow.y, D_8010A538_12DD18_DayAtTheRaces[idx].shadow.z);
    }
    w->x = D_8010A538_12DD18_DayAtTheRaces[idx].pos.x;
    w->alpha = 0xFF;
    w->height = D_8010A538_12DD18_DayAtTheRaces[idx].height;
    w->motion = -1;
    w->gear = w->rank = -1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0B_DayAtTheRaces/1277D0", func_80106990_12A170_DayAtTheRaces);
#endif

s16 func_80106D5C_12A53C_DayAtTheRaces(DRBet* w, s32 dir) {
    s16 i = w->cursor + dir;

    if (dir == 0) {
        dir = 1;
    }
    while (D_8010AC30_12E410_DayAtTheRaces[i] != -1) {
        i += dir;
        if (i < 0) {
            i = 3;
        }
        i = i < 4 ? i : 0;
    }
    return i;
}

/* NON_MATCHING: register allocation (masked 0, raw 97): only s0/s1 swapped (retail keeps w in s1, the button mask
   and &D_8010AC34 in s0). Tried: btn init/declaration order (no change), case 0 without t (fixed the t temp). */
#ifdef NON_MATCHING
void func_80106DE4_12A5C4_DayAtTheRaces(omObjData* obj, DRBet* w) {
    s32 btn = 0;
    omObjData* t;
    DRPlayer* r;

    switch (w->state) {
        case 0:
            if (D_8010AC2C_12E40C_DayAtTheRaces[D_8010AC34_12E414_DayAtTheRaces.pick] == w->player) {
                w->cursor = func_80106D5C_12A53C_DayAtTheRaces(w, 0);
                omSetTra(obj, D_8010AC20_12E400_DayAtTheRaces.objs[w->cursor]->trans.x + 60.0f,
                         D_8010AC20_12E400_DayAtTheRaces.objs[w->cursor]->trans.y + ((DRPlayer*)D_8010AC20_12E400_DayAtTheRaces.objs[w->cursor]->unk_50)->height,
                         D_8010AC20_12E400_DayAtTheRaces.objs[w->cursor]->trans.z - 15.0f);
                if (D_8010AC34_12E414_DayAtTheRaces.pick == 3) {
                    D_8010AC30_12E410_DayAtTheRaces[w->cursor] = D_8010AC34_12E414_DayAtTheRaces.pick;
                    w->target = D_8010AC20_12E400_DayAtTheRaces.objs[w->cursor];
                    r = w->target->unk_50;
                    func_800797DC_7A3DC(0x103, w->player);
                    r->sub++;
                    w->state = 4;
                } else {
                    w->state++;
                }
            }
            break;
        case 1:
            D_8010AC34_12E414_DayAtTheRaces.time = 300;
            func_800691FC_69DFC(10, 10, 160, 32);
            w->state++;
            break;
        case 2:
            if (w->alpha < 255) {
                w->alpha += 16;
                if (w->alpha >= 256) {
                    w->alpha = 255;
                }
            } else {
                w->alpha = 255;
                w->timer = 0;
                w->state++;
            }
            func_8002D0A0_2DCA0(obj->model[0], w->alpha);
            break;
        case 3:
            if (gPlayers[w->player].flags & 1) {
                switch (rand8() & 0x1F) {
                    case 0:
                        btn |= 0x8000;
                        break;
                    case 1:
                        btn |= 0x100;
                        break;
                    case 2:
                        btn |= 0x200;
                        break;
                    default:
                        btn = 0;
                        break;
                }
            } else {
                btn = func_80109BE0_12D3C0_DayAtTheRaces(w->port) | ContBtnTrg[w->port];
            }
            if (--D_8010AC34_12E414_DayAtTheRaces.time < 0) {
                func_8006D4D0_6E0D0(0);
                btn |= 0x8000;
            } else {
                func_8006D4D0_6E0D0(D_8010AC34_12E414_DayAtTheRaces.time / 30 + 1);
            }
            if (btn & 0x100) {
                w->cursor = func_80106D5C_12A53C_DayAtTheRaces(w, -1);
            } else if (btn & 0x200) {
                w->cursor = func_80106D5C_12A53C_DayAtTheRaces(w, 1);
            }
            if (w->cursor < 0) {
                while (1) {
                }
            }
            if (w->cursor >= 4) {
                while (1) {
                }
            }
            t = D_8010AC20_12E400_DayAtTheRaces.objs[w->cursor];
            omSetTra(obj, t->trans.x + 60.0f, t->trans.y + ((DRPlayer*)t->unk_50)->height, t->trans.z - 15.0f);
            if (btn & 0x8000) {
                D_8010AC30_12E410_DayAtTheRaces[w->cursor] = D_8010AC34_12E414_DayAtTheRaces.pick;
                w->target = D_8010AC20_12E400_DayAtTheRaces.objs[w->cursor];
                r = w->target->unk_50;
                func_800797DC_7A3DC(0x103, w->player);
                r->sub++;
                w->state++;
            }
            break;
        case 4:
            func_8006D518_6E118();
            ((DRPlayer*)w->target->unk_50)->port = w->player;
            w->state++;
            break;
        case 5:
            if (w->timer++ >= 31) {
                w->timer = 0;
                w->alpha = 0;
                w->state++;
            } else {
                r = w->target->unk_50;
                w->alpha -= 5;
                func_8002D0A0_2DCA0(obj->model[0], w->alpha);
                t = w->target;
                omSetTra(obj, t->trans.x + 60.0f, t->trans.y + r->height, t->trans.z - 15.0f);
            }
            break;
        case 6:
            if (((DRPlayer*)w->target->unk_50)->sub >= 3) {
                if (++D_8010AC34_12E414_DayAtTheRaces.pick >= 4) {
                    func_800794A8_7A0A8(60);
                }
                w->state++;
            }
            break;
        case 7:
            if (D_8010AC34_12E414_DayAtTheRaces.pick >= 4) {
                func_8002D0A0_2DCA0(obj->model[0], ((DRPlayer*)w->target->unk_50)->alpha);
                t = w->target;
                omSetTra(obj, t->trans.x - 60.0f, t->trans.y + ((DRPlayer*)t->unk_50)->height, t->trans.z - 5.0f);
            } else {
                t = w->target;
                omSetTra(obj, t->trans.x + 60.0f, t->trans.y + ((DRPlayer*)t->unk_50)->height, t->trans.z - 15.0f);
            }
            break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0B_DayAtTheRaces/1277D0", func_80106DE4_12A5C4_DayAtTheRaces);
#endif

void func_80107368_12AB48_DayAtTheRaces(omObjData* obj, DRBet* w) {
    DRPlayer* r = w->target->unk_50;
    omObjData* t;

    r->unk_06 = 0;
    func_8002D0A0_2DCA0(obj->model[0], r->alpha);
    t = w->target;
    omSetTra(obj, t->trans.x - 60.0f, t->trans.y + r->height, t->trans.z - 5.0f);
}

void func_80107400_12ABE0_DayAtTheRaces(omObjData* obj, DRBet* w) {
    DRPlayer* r = w->target->unk_50;
    omObjData* t;

    func_80109DFC_12D5DC_DayAtTheRaces(w->player, r->rank);
    func_8002D0A0_2DCA0(obj->model[0], r->alpha);
    t = w->target;
    omSetTra(obj, t->trans.x - 50.0f, t->trans.y + r->height, t->trans.z - 5.0f);
}

void func_801074A0_12AC80_DayAtTheRaces(omObjData* obj) {
    DRBet* w = obj->unk_50;

    if (D_8010A930_12E110_DayAtTheRaces[func_80109DA0_12D580_DayAtTheRaces()] != NULL) {
        D_8010A930_12E110_DayAtTheRaces[func_80109DA0_12D580_DayAtTheRaces()](obj, w);
    }
}

void func_80107520_12AD00_DayAtTheRaces(omObjData* obj, s32 i) {
    DRBet* w;

    obj->model[0] = func_80018A64_19664(D_8010A4C0_12DCA0_DayAtTheRaces[gPlayers[i].character], 0xA09);
    func_8002D124_2DD24(obj->model[0]);
    func_8002D0A0_2DCA0(obj->model[0], 0);
    w = func_80027154_27D54(sizeof(DRBet), 0x7918);
    if (w == NULL) {
        while (1) {
        }
    }
    func_800B0EF0_B1AF0(w, 0, sizeof(DRBet));
    obj->unk_50 = w;
    omSetSca(obj, 0.5f, 0.5f, 0.5f);
    w->player = i;
    w->port = gPlayers[i].port;
    switch (gPlayers[i].cpu_difficulty) {
        case 0:
            w->delay = D_8010A4D8_12DCB8_DayAtTheRaces[0];
            break;
        case 1:
            w->delay = D_8010A4D8_12DCB8_DayAtTheRaces[1];
            break;
        case 2:
            w->delay = D_8010A4D8_12DCB8_DayAtTheRaces[2];
            break;
        case 3:
            w->delay = D_8010A4D8_12DCB8_DayAtTheRaces[3];
            break;
        default:
            while (1) {
            }
    }
}

void func_801076AC_12AE8C_DayAtTheRaces(void) {
    switch (func_80109B2C_12D30C_DayAtTheRaces(10)) {
        case 0:
        case 1:
        case 2:
        case 3:
            if (((DRPlayer*)func_80105D9C_12957C_DayAtTheRaces(0)->unk_50)->mode != 3) {
                ((DRPlayer*)func_80105D9C_12957C_DayAtTheRaces(0)->unk_50)->mode = 2;
            }
            break;
        case 4:
            ((DRPlayer*)func_80105D9C_12957C_DayAtTheRaces(1)->unk_50)->mode = 3;
            ((DRPlayer*)func_80105D9C_12957C_DayAtTheRaces(2)->unk_50)->mode = 3;
            ((DRPlayer*)func_80105D9C_12957C_DayAtTheRaces(3)->unk_50)->mode = 3;
            break;
        case 5:
        case 6:
            ((DRPlayer*)func_80105D9C_12957C_DayAtTheRaces(2)->unk_50)->mode = 3;
            ((DRPlayer*)func_80105D9C_12957C_DayAtTheRaces(3)->unk_50)->mode = 3;
            break;
        case 7:
        case 8:
        case 9:
            ((DRPlayer*)func_80105D9C_12957C_DayAtTheRaces(3)->unk_50)->mode = 3;
            break;
    }
}

void func_80107788_12AF68_DayAtTheRaces(void) {
    switch (func_80109B2C_12D30C_DayAtTheRaces(20)) {
        case 0:
        case 1:
        case 2:
        case 3:
            ((DRPlayer*)func_80105E80_129660_DayAtTheRaces(0)->unk_50)->mode = 3;
            break;
        case 4:
        case 5:
            ((DRPlayer*)func_80105E80_129660_DayAtTheRaces(1)->unk_50)->mode = 3;
            break;
        case 6:
            ((DRPlayer*)func_80105E80_129660_DayAtTheRaces(2)->unk_50)->mode = 3;
            break;
        case 7:
        case 8:
        case 9:
        case 10:
            ((DRPlayer*)func_80105E80_129660_DayAtTheRaces(0)->unk_50)->mode = 3;
            ((DRPlayer*)func_80105E80_129660_DayAtTheRaces(1)->unk_50)->mode = 3;
            break;
        case 16:
        case 17:
        case 18:
        case 19:
            if (((DRPlayer*)func_80105D9C_12957C_DayAtTheRaces(2)->unk_50)->mode != 3) {
                ((DRPlayer*)func_80105E80_129660_DayAtTheRaces(2)->unk_50)->mode = 2;
            }
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
            if (((DRPlayer*)func_80105D9C_12957C_DayAtTheRaces(3)->unk_50)->mode != 3) {
                ((DRPlayer*)func_80105E80_129660_DayAtTheRaces(3)->unk_50)->mode = 2;
            }
            break;
    }
}

void func_80107894_12B074_DayAtTheRaces(void) {
    func_801058B4_129094_DayAtTheRaces();
}

void func_801078B0_12B090_DayAtTheRaces(void) {
    s32 i;
    DRPlayer* w;
    s32 k;

    for (i = 0; i < 4; i++) {
        w = D_8010AC20_12E400_DayAtTheRaces.objs[i]->unk_50;
        k = D_8010A948_12E128_DayAtTheRaces[i];
        switch (w->gear) {
            case 0:
                k--;
                break;
            case 2:
                k++;
                break;
        }
        if (func_80109B2C_12D30C_DayAtTheRaces(10) < k) {
            if (w->mode != 3) {
                w->mode = 2;
            }
        }
    }
}

/* NON_MATCHING: schedule (masked 2): case 2's two stores come off D_8010AC48 in the other order */
#ifdef NON_MATCHING
void func_8010796C_12B14C_DayAtTheRaces(omObjData* obj) {
    switch (D_8010AC34_12E414_DayAtTheRaces.sub) {
        case 0:
            if (D_8010AC34_12E414_DayAtTheRaces.timer++ >= 22) {
                func_80109D40_12D520_DayAtTheRaces(0, &D_8010A9FC_12E1DC_DayAtTheRaces);
                D_8010AC34_12E414_DayAtTheRaces.sub++;
            }
            break;
        case 1:
            if (func_80109D7C_12D55C_DayAtTheRaces(0) == 1) {
                D_8010AC34_12E414_DayAtTheRaces.sub++;
            }
            break;
        case 2:
            D_8010AC34_12E414_DayAtTheRaces.timer = 0;
            D_8010AC34_12E414_DayAtTheRaces.sub = 0;
            func_80109DAC_12D58C_DayAtTheRaces(1);
            break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0B_DayAtTheRaces/1277D0", func_8010796C_12B14C_DayAtTheRaces);
#endif

void func_80107A44_12B224_DayAtTheRaces(omObjData* obj) {
    if (++D_8010AA20_12E200_DayAtTheRaces == 16) {
        PlayMusic(0x39);
    }
    if (D_8010AC34_12E414_DayAtTheRaces.pick == 4) {
        func_80109C98_12D478_DayAtTheRaces(0, &D_8010AA08_12E1E8_DayAtTheRaces, &D_8010AA14_12E1F4_DayAtTheRaces, 0.0f, 0.0f);
        if (D_8010AA24_12E204_DayAtTheRaces == -1) {
            D_8010AA24_12E204_DayAtTheRaces = PlaySound(0x4A9);
        }
    }
    if (D_8010AC34_12E414_DayAtTheRaces.done >= 4) {
        D_8010AC34_12E414_DayAtTheRaces.done = 0;
        D_8010AC34_12E414_DayAtTheRaces.sub = 0;
        D_8010AC34_12E414_DayAtTheRaces.timer = 0;
        D_8010AC34_12E414_DayAtTheRaces.camX = 110.0f;
        D_8010AC50_12E430_DayAtTheRaces.flag = 0;
        func_80105C84_129464_DayAtTheRaces();
        func_80109DAC_12D58C_DayAtTheRaces(2);
    }
}

void func_80107B20_12B300_DayAtTheRaces(s32 i) {
    DRPlayer* w = D_8010AC20_12E400_DayAtTheRaces.objs[i]->unk_50;

    w->rank = D_8010AC34_12E414_DayAtTheRaces.done++;
    if (func_80105EF0_1296D0_DayAtTheRaces(w) < 64.0f) {
        D_8010AC50_12E430_DayAtTheRaces.list[D_8010AC50_12E430_DayAtTheRaces.count++] = func_80109DD8_12D5B8_DayAtTheRaces();
        D_8010AC34_12E414_DayAtTheRaces.photo = 1;
    }
    if (D_8010AC34_12E414_DayAtTheRaces.done == 1) {
        PlaySound(0xF);
        PlaySound(0x4A9);
        func_80103788_126F68_DayAtTheRaces();
    }
    if (D_8010AC34_12E414_DayAtTheRaces.done == 3) {
        for (i = 0; i < 4; i++) {
            if (((DRPlayer*)D_8010AC20_12E400_DayAtTheRaces.objs[i]->unk_50)->rank == -1) {
                break;
            }
        }
        w = D_8010AC20_12E400_DayAtTheRaces.objs[i]->unk_50;
        w->rank = D_8010AC34_12E414_DayAtTheRaces.done;
    }
}

void func_80107C5C_12B43C_DayAtTheRaces(void) {
    switch (++D_8010AC34_12E414_DayAtTheRaces.timer) {
        case 10:
            func_80103748_126F28_DayAtTheRaces();
            break;
        case 70:
            func_80103728_126F08_DayAtTheRaces();
            break;
        case 85:
            PlayMusic(0x22);
            func_800799A4_7A5A4(D_8010AA24_12E204_DayAtTheRaces, 0x2A);
            func_80103768_126F48_DayAtTheRaces();
            D_8010AC34_12E414_DayAtTheRaces.sub++;
            break;
    }
}

void func_80107D10_12B4F0_DayAtTheRaces(omObjData* obj) {
    Vec v;
    omObjData* lead;
    f32 d;
    s32 i;
    void (*f)(void);
    s32 k;

    func_80105DC4_1295A4_DayAtTheRaces();
    lead = func_80105E80_129660_DayAtTheRaces(0);
    func_80109C5C_12D43C_DayAtTheRaces(0, &v);
    d = lead->trans.x - v.x + D_8010AC34_12E414_DayAtTheRaces.camX;
    if (d < 4.8f) {
        v.x = d + v.x;
    } else {
        v.x = v.x + 4.8f;
    }
    d = D_8010A500_12DCE0_DayAtTheRaces[7] + D_8010AC34_12E414_DayAtTheRaces.camX;
    if (v.x > d) {
        v.x = d;
    }
    func_80109C98_12D478_DayAtTheRaces(0, &v, NULL, 0.0f, 0.0f);
    if (lead->trans.x >= D_8010A500_12DCE0_DayAtTheRaces[5]) {
        func_80107894_12B074_DayAtTheRaces();
    }
    for (i = 0; i < 4; i++) {
        DRPlayer* w = D_8010AC20_12E400_DayAtTheRaces.objs[i]->unk_50;

        D_8010AC34_12E414_DayAtTheRaces.prev[i] = D_8010AC34_12E414_DayAtTheRaces.mark[i];
        D_8010AC34_12E414_DayAtTheRaces.mark[i] = func_80105EA8_129688_DayAtTheRaces(D_8010AC20_12E400_DayAtTheRaces.objs[i]->trans.x + w->anim);
        if (D_8010AC34_12E414_DayAtTheRaces.mark[i] < D_8010AC34_12E414_DayAtTheRaces.prev[i]) {
            D_8010AC34_12E414_DayAtTheRaces.mark[i] = D_8010AC34_12E414_DayAtTheRaces.prev[i];
        }
        if (D_8010AC34_12E414_DayAtTheRaces.mark[i] != D_8010AC34_12E414_DayAtTheRaces.prev[i]) {
            if (D_8010AC34_12E414_DayAtTheRaces.mark[i] == 7) {
                func_80107B20_12B300_DayAtTheRaces(i);
            }
            if (D_8010AC20_12E400_DayAtTheRaces.objs[i] == lead) {
                f = D_8010A958_12E138_DayAtTheRaces[D_8010AC34_12E414_DayAtTheRaces.mark[i]];
                if (f != NULL && D_8010A524_12DD04_DayAtTheRaces[D_8010AC34_12E414_DayAtTheRaces.mark[i]] == 0) {
                    f();
                    D_8010A524_12DD04_DayAtTheRaces[D_8010AC34_12E414_DayAtTheRaces.mark[i]] = 1;
                }
            }
        }
    }
    if (D_8010AC34_12E414_DayAtTheRaces.done != 0) {
        if (D_8010AA28_12E208_DayAtTheRaces.mes == 0) {
            func_800691FC_69DFC(0x14);
            D_8010AA28_12E208_DayAtTheRaces.mes = 1;
        }
    }
    if (D_8010AC34_12E414_DayAtTheRaces.done >= 3) {
        if (D_8010AA28_12E208_DayAtTheRaces.end == 0) {
            D_8010AA28_12E208_DayAtTheRaces.end = 1;
            if (D_8010AC34_12E414_DayAtTheRaces.photo == 1) {
                D_8010AC34_12E414_DayAtTheRaces.timer = 0;
                D_8010AC34_12E414_DayAtTheRaces.sub = 0;
                k = 3;
            } else {
                k = 4;
            }
            func_80109DAC_12D58C_DayAtTheRaces(k);
        }
    }
}

void func_80107FF8_12B7D8_DayAtTheRaces(omObjData* obj) {
    if (D_8010AC34_12E414_DayAtTheRaces.sub == 0) {
        func_80107C5C_12B43C_DayAtTheRaces();
    } else {
        func_80107D10_12B4F0_DayAtTheRaces(obj);
    }
}

__asm__(".section .rodata");
const char D_8010ABD0_12E3B0_DayAtTheRaces[] = "\202q\202d\202o\202k\202`\202x";

void func_80108034_12B814_DayAtTheRaces(omObjData* obj) {
    s32 i;
    s32 k;
    s32 j;

    if (D_8010AC34_12E414_DayAtTheRaces.sub >= 4) {
        D_8010AC34_12E414_DayAtTheRaces.timer++;
        D_8010AC34_12E414_DayAtTheRaces.replay = 0;
        for (i = 0; i < D_8010AC50_12E430_DayAtTheRaces.count; i++) {
            k = D_8010AC50_12E430_DayAtTheRaces.list[i];
            if (k - 30 < D_8010AC50_12E430_DayAtTheRaces.frame) {
                k += 15;
                if (D_8010AC50_12E430_DayAtTheRaces.frame < k) {
                    if (D_8010AC34_12E414_DayAtTheRaces.timer % 5 != 0) {
                        D_8010AC34_12E414_DayAtTheRaces.replay = 1;
                    }
                }
            }
        }
        if (D_8010AC34_12E414_DayAtTheRaces.replay == 0) {
            D_8010AC50_12E430_DayAtTheRaces.frame++;
        }
    }
    func_80107D10_12B4F0_DayAtTheRaces(obj);
    switch (D_8010AC34_12E414_DayAtTheRaces.sub) {
        case 0:
            if (D_8010AC34_12E414_DayAtTheRaces.timer++ >= 61) {
                D_8010AC34_12E414_DayAtTheRaces.sub++;
            }
            break;
        case 1:
            func_80079614_7A214(20);
            func_800794A8_7A0A8(40);
            InitFadeOut(11, 20);
            D_8010AC34_12E414_DayAtTheRaces.sub++;
            break;
        case 3:
            func_80109C98_12D478_DayAtTheRaces(0, &D_8010AA2C_12E20C_DayAtTheRaces, &D_8010AA38_12E218_DayAtTheRaces, 0.0f, 0.0f);
            D_8010AC34_12E414_DayAtTheRaces.done = 0;
            for (j = 0; j < 4; j++) {
                ((DRPlayer*)D_8010AC20_12E400_DayAtTheRaces.objs[j]->unk_50)->rank = -1;
            }
            D_8010AC34_12E414_DayAtTheRaces.timer = 0;
            func_80103D5C_12753C_DayAtTheRaces();
            func_80105A94_129274_DayAtTheRaces();
            D_8010AC34_12E414_DayAtTheRaces.camX = 0.0f;
            PlayMusic(0x48);
            func_800794F0_7A0F0(0x60);
            D_8010AC34_12E414_DayAtTheRaces.sub++;
            break;
        case 4:
            InitFadeIn(11, 16);
            D_8010AC34_12E414_DayAtTheRaces.sub++;
            break;
        case 2:
        case 5:
            if (func_8008F618_90218() == 0) {
                D_8010AC34_12E414_DayAtTheRaces.sub++;
            }
            break;
        case 6:
            if (func_80069538_6A138() == 0) {
                func_800691FC_69DFC(8, D_8010ABD0_12E3B0_DayAtTheRaces, 0x48, 0x1A, 1.0, 1.0, 0);
            }
            if (D_8010AC34_12E414_DayAtTheRaces.done >= 3) {
                if (D_8010AC50_12E430_DayAtTheRaces.frame > D_8010AC50_12E430_DayAtTheRaces.list[0] + 60) {
                    D_8010AC34_12E414_DayAtTheRaces.replay = 0;
                    func_80109DAC_12D58C_DayAtTheRaces(4);
                }
            }
            break;
    }
}

void func_80108304_12BAE4_DayAtTheRaces(omObjData* obj) {
    if (D_8010AA44_12E224_DayAtTheRaces[func_80109DA0_12D580_DayAtTheRaces()] != NULL) {
        D_8010AA44_12E224_DayAtTheRaces[func_80109DA0_12D580_DayAtTheRaces()](obj);
    }
}

void func_80108374_12BB54_DayAtTheRaces(void) {
    s32 i;

    func_80076BD0_777D0(0, 4);
    D_8010AC20_12E400_DayAtTheRaces.objs = func_80076D80_77980(0);
    for (i = 0; i < 4; i++) {
        D_8010AC20_12E400_DayAtTheRaces.objs[i] = omAddObj(3, 4, 9, 0, func_80106764_129F44_DayAtTheRaces);
        func_80106990_12A170_DayAtTheRaces(D_8010AC20_12E400_DayAtTheRaces.objs[i], i);
    }
}

void func_80108414_12BBF4_DayAtTheRaces(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        omDelObj(func_80076D98_77998(0, i));
    }
}

void func_80108458_12BC38_DayAtTheRaces(void) {
    s8* p;
    s32 s[4];
    s32 i;
    s32 j;
    s32 k;

    func_80076BD0_777D0(2, 4);
    D_8010AC24_12E404_DayAtTheRaces.objs = func_80076D80_77980(2);
    for (i = 0; i < 4; i++) {
        D_8010AC24_12E404_DayAtTheRaces.objs[i] = omAddObj(4, 1, 0, 2, func_801074A0_12AC80_DayAtTheRaces);
        func_80107520_12AD00_DayAtTheRaces(D_8010AC24_12E404_DayAtTheRaces.objs[i], i);
        D_8010AC30_12E410_DayAtTheRaces[i] = -1;
    }
    if (_CheckFlag(0x13)) {
        for (i = 0; i < 4; i++) {
            s[i] = rand8() & 3;
        }
    } else {
        for (i = 0; i < 4; i++) {
            s[i] = func_80059FD0_5ABD0(i);
        }
    }
    i = 0;
    k = 3;
    for (; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (s[j] == i) {
                p = &D_8010AC2C_12E40C_DayAtTheRaces[k];
                *p = j;
                k--;
            }
        }
    }
    D_8010AC34_12E414_DayAtTheRaces.pick = 0;
    if (k < -1) {
        while (1) {
        }
    }
    D_8010AC28_12E408_DayAtTheRaces = omAddObj(5, 0, 0, -1, func_80108304_12BAE4_DayAtTheRaces);
}

void func_80108614_12BDF4_DayAtTheRaces(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        omDelObj(func_80076D98_77998(2, i));
    }
    omDelObj(D_8010AC28_12E408_DayAtTheRaces);
}

/* .data (8010A4C0-8010AA60) */
s32 D_8010A4C0_12DCA0_DayAtTheRaces[6] = {
    0x1B000B, 0x1B000C, 0x1B000D, 0x1B000E, 0x1B000F, 0x1B0010,
};
u16 D_8010A4D8_12DCB8_DayAtTheRaces[4] = {
    0xA, 0x8, 0x6, 0x4,
};
u8 D_8010A4E0_12DCC0_DayAtTheRaces[4][8] = {
    { 0, 1, 2, 1, 0, 1, 2, 1 },
    { 1, 0, 2, 1, 1, 2, 0, 0 },
    { 0, 1, 1, 1, 1, 1, 0, 2 },
    { 0, 1, 1, 2, 1, 2, 1, 2 },
};
f32 D_8010A500_12DCE0_DayAtTheRaces[9] = {
    -30.0f, 250.0f, 500.0f, 750.0f, 1000.0f, 1100.0f, 1150.0f, 1242.0f, 1500.0f,
};
s16 D_8010A524_12DD04_DayAtTheRaces[10] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};
DRChar D_8010A538_12DD18_DayAtTheRaces[4] = {
    { { -200.0f, 0.0f, 75.0f }, 0.36f, { 0.3f, 1.0f, 0.3f }, 50.0f, 0x1B0011, 0xD, 0xAD9 },
    { { -200.0f, 50.0f, 12.5f }, 0.24f, { 0.6f, 1.0f, 0.6f }, 50.0f, 0x1B0014, 0xD, 0xAC9 },
    { { -200.0f, 0.0f, -56.25f }, 0.24f, { 0.6f, 1.0f, 0.6f }, 70.0f, 0x1B0013, 0xA015A, 0xAD9 },
    { { -200.0f, 10.0f, -143.75f }, 0.22f, { 0.8f, 1.0f, 1.3f }, 100.0f, 0x1B0012, 0x0, 0xAD9 },
};
f32 D_8010A5E8_12DDC8_DayAtTheRaces[4][5] = {
    { 40.0f, 40.0f, 40.0f, 40.0f, 40.0f },
    { 100.0f, 100.0f, 100.0f, 100.0f, 100.0f },
    { 75.0f, 75.0f, 75.0f, 75.0f, 75.0f },
    { 115.0f, 155.0f, 195.0f, 195.0f, 195.0f },
};
DRMotion D_8010A638_12DE18_DayAtTheRaces[4][9] = {
    {
        { 0x1B001D, NULL, 0, 0, 0, 1.0f },
        { 0x1B001E, NULL, 0, 0, 0, 1.0f },
        { 0x1B001F, NULL, 0, 0, 0, 1.0f },
        { 0x1B0020, NULL, 0, 0, 0, 1.0f },
        { 0x1B0021, func_801041B8_127998_DayAtTheRaces, 0, 0, 0, 1.0f },
        { 0x1B0023, func_8010430C_127AEC_DayAtTheRaces, 0, -1, 0, 1.0f },
        { 0x1B0024, NULL, 0, 0, 0, 1.0f },
        { 0x1B0025, NULL, 0, -1, 0, 1.0f },
        { 0x1B0022, NULL, 0, -1, 0, 1.0f },
    },
    {
        { 0x1B0035, func_801043B4_127B94_DayAtTheRaces, 0, 0, 0, 1.0f },
        { 0x1B0036, func_80104364_127B44_DayAtTheRaces, 0, 0, 0, 1.0f },
        { 0x1B0035, func_80104424_127C04_DayAtTheRaces, 0, 0, 1, 1.0f },
        { 0x1B0035, func_80104494_127C74_DayAtTheRaces, 0, 0, 1, 1.0f },
        { 0x1B0035, func_801045B4_127D94_DayAtTheRaces, 0, 0, 1, 1.0f },
        { 0x1B0038, func_80104364_127B44_DayAtTheRaces, 0, -1, 0, 1.0f },
        { 0x1B0039, func_80104364_127B44_DayAtTheRaces, 0, 0, 0, 1.0f },
        { 0x1B003A, func_80104364_127B44_DayAtTheRaces, 0, -1, 0, 1.0f },
        { 0x1B0037, func_80104364_127B44_DayAtTheRaces, 0, -1, 0, 1.0f },
    },
    {
        { 0x1B002F, func_80104750_127F30_DayAtTheRaces, 0, 0, 0, 1.0f },
        { 0x1B0030, func_80104744_127F24_DayAtTheRaces, 0, 0, 0, 1.0f },
        { 0x1B002F, func_80104A40_128220_DayAtTheRaces, 0, 0, 1, 1.0f },
        { 0x1B002F, func_80104D1C_1284FC_DayAtTheRaces, 0, 0, 1, 1.0f },
        { 0x1B002F, func_80105040_128820_DayAtTheRaces, 0, 0, 1, 1.0f },
        { 0x1B0032, NULL, 0, -1, 0, 1.0f },
        { 0x1B0033, func_80104744_127F24_DayAtTheRaces, 0, 0, 0, 1.0f },
        { 0x1B0034, func_80104744_127F24_DayAtTheRaces, 0, -1, 0, 1.0f },
        { 0x1B0031, NULL, 0, -1, 0, 1.0f },
    },
    {
        { 0x1B0026, NULL, 0, 0, 0, 0.5f },
        { 0x1B0027, NULL, 0, 0, 0, 1.0f },
        { 0x1B0028, NULL, 0, 0, 0, 1.0f },
        { 0x1B0029, NULL, 0, 0, 0, 1.0f },
        { 0x1B002A, NULL, 0, 0, 0, 1.0f },
        { 0x1B002C, func_8010537C_128B5C_DayAtTheRaces, 0, -1, 0, 1.0f },
        { 0x1B002D, NULL, 0, 0, 0, 1.0f },
        { 0x1B002E, NULL, 0, -1, 0, 1.0f },
        { 0x1B002B, NULL, 0, -1, 0, 1.0f },
    },
};
void (*D_8010A908_12E0E8_DayAtTheRaces[4])(omObjData*, DRPlayer*) = {
    func_80105F70_129750_DayAtTheRaces, func_80105FE8_1297C8_DayAtTheRaces,
    func_8010603C_12981C_DayAtTheRaces, func_80106128_129908_DayAtTheRaces,
};
void (*D_8010A918_12E0F8_DayAtTheRaces[6])(omObjData*, DRPlayer*) = {
    func_801062A8_129A88_DayAtTheRaces, func_80106454_129C34_DayAtTheRaces,
    func_801066CC_129EAC_DayAtTheRaces, func_801066CC_129EAC_DayAtTheRaces,
    func_80106704_129EE4_DayAtTheRaces, NULL,
};
void (*D_8010A930_12E110_DayAtTheRaces[6])(omObjData*, DRBet*) = {
    NULL, func_80106DE4_12A5C4_DayAtTheRaces, func_80107368_12AB48_DayAtTheRaces,
    func_80107368_12AB48_DayAtTheRaces, func_80107400_12ABE0_DayAtTheRaces, NULL,
};
s32 D_8010A948_12E128_DayAtTheRaces[4] = {
    4, 5, 2, 3,
};
void (*D_8010A958_12E138_DayAtTheRaces[9])(void) = {
    func_801076AC_12AE8C_DayAtTheRaces, func_80107788_12AF68_DayAtTheRaces,
    func_80107788_12AF68_DayAtTheRaces, func_80107788_12AF68_DayAtTheRaces,
    func_80107788_12AF68_DayAtTheRaces, func_80107894_12B074_DayAtTheRaces,
    func_801078B0_12B090_DayAtTheRaces, NULL, NULL,
};
DRCamKey D_8010A97C_12E15C_DayAtTheRaces[4] = {
    { { -560.0f, 200.0f, -143.75f }, { -20.6f, -90.0f, 0.0f }, 26.0f, 0x0 },
    { { -560.0f, 200.0f, 75.0f }, { -20.6f, -90.0f, 0.0f }, 26.0f, 0x5A },
    { { -550.0f, 450.0f, -56.0f }, { -45.0f, -90.0f, 0.0f }, 35.0f, 0x6E },
    { { -550.0f, 450.0f, -56.0f }, { -45.0f, -90.0f, 0.0f }, 35.0f, 0x8C },
};
DRCamPath D_8010A9FC_12E1DC_DayAtTheRaces = { 0, 3, 1, D_8010A97C_12E15C_DayAtTheRaces };
Vec D_8010AA08_12E1E8_DayAtTheRaces = { 80.0f, 450.0f, 366.0f };
Vec D_8010AA14_12E1F4_DayAtTheRaces = { -43.0f, 17.0f, 0.0f };
s32 D_8010AA20_12E200_DayAtTheRaces = 0;
s16 D_8010AA24_12E204_DayAtTheRaces = -1;
s16 D_8010AA26_12E206_DayAtTheRaces = 0;
DRDone D_8010AA28_12E208_DayAtTheRaces = { 0, 0 };
Vec D_8010AA2C_12E20C_DayAtTheRaces = { 1100.0f, 350.0f, 388.0f };
Vec D_8010AA38_12E218_DayAtTheRaces = { -38.0f, 0.0f, 0.0f };
void (*D_8010AA44_12E224_DayAtTheRaces[7])(omObjData*) = {
    func_8010796C_12B14C_DayAtTheRaces, func_80107A44_12B224_DayAtTheRaces,
    func_80107FF8_12B7D8_DayAtTheRaces, func_80108034_12B814_DayAtTheRaces, NULL, NULL, NULL,
};
