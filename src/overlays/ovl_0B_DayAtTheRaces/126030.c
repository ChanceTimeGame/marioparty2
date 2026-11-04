#include "ovl_0B.h"

void func_80102850_126030_DayAtTheRaces(omObjData* obj) {
    DRObjWork* w = obj->unk_50;

    switch (w->state) {
        case 0:
            func_80029FE4_2ABE4(obj->model[0], 0.0f);
            w->state++;
            break;
        case 2:
            func_80029FE4_2ABE4(obj->model[0], 1.0f);
            PlaySound(0x16C);
            w->state++;
            break;
        case 3:
            break;
    }
}

void func_801028CC_1260AC_DayAtTheRaces(omObjData* obj) {
    DRObjWork* w = obj->unk_50;
    omObjData* other = D_8010AC10_12E3F0_DayAtTheRaces.objs[5];

    switch (w->state) {
        case 1:
            if (obj->trans.y < 0.0f) {
                obj->trans.y += 0.5f;
                other->trans.y += 0.5f;
            }
            break;
        case 2:
            obj->trans.y = 0.0f;
            break;
    }
}

void func_80102940_126120_DayAtTheRaces(omObjData* obj) {
    DRObjWork* w = obj->unk_50;

    switch (w->state) {
        case 0:
            func_80029E80_2AA80(obj->model[0], 2, 2);
            w->state++;
            break;
        case 2:
            func_80029BF0_2A7F0(obj->model[0], obj->motion[0], 0, 5, 0);
            w->state++;
            break;
    }
}

void func_801029C4_1261A4_DayAtTheRaces(omObjData* obj) {
    DRObjWork* w = obj->unk_50;
    f32 x;
    f32 y;

    switch (w->state) {
        case 0:
            func_80029E80_2AA80(obj->model[0], 2, 2);
            x = (u8)(rand8() % 20);
            x = x + obj->trans.x - 10.0f;
            y = obj->trans.y - (u8)(rand8() % 5);
            HuVecCopyXYZ(&w->pos, x, y, obj->trans.z - (u8)(rand8() % 5));
            w->state++;
            break;
        case 1:
            func_80029FE4_2ABE4(obj->model[0], (u8)(rand8() % 100) * 0.01f);
            w->phaseA += (u8)(rand8() % 10);
            if (w->phaseA > 360.0f) {
                w->phaseA -= 360.0f;
            }
            obj->trans.x = HuMathSin(w->phaseA) * 30.0f + w->pos.x;
            obj->trans.z = HuMathSin(w->phaseA) * 10.0f + w->pos.z;
            w->phaseB += (u8)(rand8() % 20);
            if (w->phaseB > 360.0f) {
                w->phaseB -= 360.0f;
            }
            obj->trans.y = HuMathSin(w->phaseB) * 10.0f + w->pos.y;
            break;
        case 2:
            func_80029FE4_2ABE4(obj->model[0], 0.0f);
            break;
    }
}

void func_80102D08_1264E8_DayAtTheRaces(Vec* pos, Vec* rot) {
    if (pos->y > 150.0f) {
        rot->x += (u8)(rand8() % 20) - 10.0f;
        rot->y += (u8)(rand8() % 20) - 10.0f;
        rot->z += (u8)(rand8() % 20) - 10.0f;
        if (rot->x > 360.0f) {
            rot->x -= 360.0f;
        }
        if (rot->x < -360.0f) {
            rot->x += 360.0f;
        }
        if (rot->y > 360.0f) {
            rot->y -= 360.0f;
        }
        if (rot->y < -360.0f) {
            rot->y += 360.0f;
        }
        if (rot->z > 360.0f) {
            rot->z -= 360.0f;
        }
        if (rot->z < -360.0f) {
            rot->z += 360.0f;
        }
        pos->x += (u8)(rand8() % 30) * 0.1f;
        pos->y -= (u8)(rand8() % 150) * 0.1f;
        pos->z += (u8)(rand8() % 30) * 0.1f;
        if (pos->x > 4000.0f) {
            pos->x = 4000.0f;
        }
        if (pos->x < -4000.0f) {
            pos->x = -4000.0f;
        }
        if (pos->y > 4000.0f) {
            pos->y = 4000.0f;
        }
        if (pos->y < -4000.0f) {
            pos->y = -4000.0f;
        }
        if (pos->z > 4000.0f) {
            pos->z = 4000.0f;
        }
        if (pos->z < -4000.0f) {
            pos->z = -4000.0f;
        }
    } else {
        pos->x -= 35.0f;
        if (pos->x > 4000.0f) {
            pos->x = 4000.0f;
        }
        if (pos->x < -4000.0f) {
            pos->x = -4000.0f;
        }
        pos->y += 300.0f;
        if (pos->y > 4000.0f) {
            pos->y = 4000.0f;
        }
        if (pos->y < -4000.0f) {
            pos->y = -4000.0f;
        }
    }
}

void func_801031EC_1269CC_DayAtTheRaces(omObjData* obj) {
    Vec pos;
    Vec rot;
    s32 i;

    if (((DRObjWork*)obj->unk_50)->state == 1) {
        HuVecCopyXYZ(&pos, obj->trans.x, obj->trans.y, obj->trans.z);
        HuVecCopyXYZ(&rot, obj->rot.x, obj->rot.y, obj->rot.z);
        func_80102D08_1264E8_DayAtTheRaces(&pos, &rot);
        omSetRot(obj, rot.x, rot.y, rot.z);
        omSetTra(obj, pos.x, pos.y, pos.z);
        for (i = 1; i < 22; i++) {
            HuVecCopyXYZ(&pos, D_800FC834_FD434[obj->model[i]].pos.x, D_800FC834_FD434[obj->model[i]].pos.y,
                         D_800FC834_FD434[obj->model[i]].pos.z);
            HuVecCopyXYZ(&rot, D_800FC834_FD434[obj->model[i]].rot.x, D_800FC834_FD434[obj->model[i]].rot.y,
                         D_800FC834_FD434[obj->model[i]].rot.z);
            func_80102D08_1264E8_DayAtTheRaces(&pos, &rot);
            func_8002979C_2A39C(obj->model[i], rot.x, rot.y, rot.z);
            func_80029714_2A314(obj->model[i], pos.x, pos.y, pos.z);
        }
    }
}

void func_80103368_126B48_DayAtTheRaces(void) {
    s32 i;
    s32 j;
    omObjData* obj;
    DRObjWork* w;

    func_80076BD0_777D0(1, 30);
    D_8010AC10_12E3F0_DayAtTheRaces.objs = func_80076D80_77980(1);
    for (i = 0; i < 30; i++) {
        obj = omAddObj(2, D_8010A060_12D840_DayAtTheRaces[i].count, 1, 1,
                       D_8010A498_12DC78_DayAtTheRaces[D_8010A060_12D840_DayAtTheRaces[i].func]);
        for (j = 0; j < D_8010A060_12D840_DayAtTheRaces[i].count; j++) {
            obj->model[j] = func_80018A30_19630(D_8010A060_12D840_DayAtTheRaces[i].file,
                                                D_8010A060_12D840_DayAtTheRaces[i].attr);
            if (D_8010A060_12D840_DayAtTheRaces[i].func == 1) {
                func_80029E80_2AA80(obj->model[j], 2, 2);
            }
        }
        if (D_8010A060_12D840_DayAtTheRaces[i].motion != 0) {
            obj->motion[0] = func_8002C8B8_2D4B8(DataRead(D_8010A060_12D840_DayAtTheRaces[i].motion), 0x18);
        }
        omSetTra(obj, D_8010A060_12D840_DayAtTheRaces[i].pos.x, D_8010A060_12D840_DayAtTheRaces[i].pos.y,
                 D_8010A060_12D840_DayAtTheRaces[i].pos.z);
        omSetSca(obj, D_8010A060_12D840_DayAtTheRaces[i].scale, D_8010A060_12D840_DayAtTheRaces[i].scale,
                 D_8010A060_12D840_DayAtTheRaces[i].scale);
        obj->rot.y = D_8010A060_12D840_DayAtTheRaces[i].rot;
        for (j = 0; j < D_8010A060_12D840_DayAtTheRaces[i].count; j++) {
            func_80029714_2A314(obj->model[j], D_8010A060_12D840_DayAtTheRaces[i].pos.x,
                                D_8010A060_12D840_DayAtTheRaces[i].pos.y, D_8010A060_12D840_DayAtTheRaces[i].pos.z);
            func_800297E8_2A3E8(obj->model[j], D_8010A060_12D840_DayAtTheRaces[i].scale,
                                D_8010A060_12D840_DayAtTheRaces[i].scale, D_8010A060_12D840_DayAtTheRaces[i].scale);
            func_8002979C_2A39C(obj->model[j], 0.0f, D_8010A060_12D840_DayAtTheRaces[i].rot, 0.0f);
        }
        w = func_80027154_27D54(sizeof(DRObjWork), 0x7918);
        if (w == NULL) {
            while (1) {
            }
        }
        func_800B0EF0_B1AF0(w, 0, sizeof(DRObjWork));
        D_8010AC10_12E3F0_DayAtTheRaces.objs[i]->unk_50 = w;
        D_8010AC10_12E3F0_DayAtTheRaces.objs[i] = obj;
    }
}

void func_80103688_126E68_DayAtTheRaces(void) {
    func_8002D4D0_2E0D0(0x28);
    func_80103368_126B48_DayAtTheRaces();
    func_8002CA48_2D648(0x54, 0x60, 0x80);
    func_80029708_2A308(1);
}

void func_801036C4_126EA4_DayAtTheRaces(void) {
    s32 i;

    for (i = 0; i < 30; i++) {
        omDelObj(func_80076D98_77998(1, i));
    }
    func_8002F1A4_2FDA4();
    func_8002CA48_2D648(0, 0, 0);
    func_80029708_2A308(1);
}

void func_80103728_126F08_DayAtTheRaces(void) {
    ((DRObjWork*)D_8010AC10_12E3F0_DayAtTheRaces.objs[5]->unk_50)->state++;
}

void func_80103748_126F28_DayAtTheRaces(void) {
    ((DRObjWork*)D_8010AC10_12E3F0_DayAtTheRaces.objs[4]->unk_50)->state++;
}

void func_80103768_126F48_DayAtTheRaces(void) {
    ((DRObjWork*)D_8010AC10_12E3F0_DayAtTheRaces.objs[2]->unk_50)->state++;
}

void func_80103788_126F68_DayAtTheRaces(void) {
    omObjData* a = D_8010AC10_12E3F0_DayAtTheRaces.objs[27];
    omObjData* b = D_8010AC10_12E3F0_DayAtTheRaces.objs[28];
    omObjData* c = D_8010AC10_12E3F0_DayAtTheRaces.objs[29];
    s32 i;
    f32 x;
    f32 y;

    omSetTra(a, 1330.0f - (u8)(rand8() % 250), rand8() % 300 + 300.0f, 100.0f);
    omSetTra(b, 1330.0f - (u8)(rand8() % 250), rand8() % 300 + 300.0f, 100.0f);
    omSetTra(c, 1330.0f - (u8)(rand8() % 250), rand8() % 300 + 300.0f, 100.0f);
    for (i = 0; i < 22; i++) {
        func_800298A4_2A4A4(a->model[i], 4, 0);
        func_800298A4_2A4A4(b->model[i], 4, 0);
        func_800298A4_2A4A4(c->model[i], 4, 0);
        x = (u8)(rand8() % 250);
        x = 1330.0f - x;
        y = rand8() % 300;
        y = y + 300.0f;
        func_80029714_2A314(a->model[i], x, y, (u8)(rand8() % 30) + 100.0f);
        x = (u8)(rand8() % 250);
        x = 1330.0f - x;
        y = rand8() % 300;
        y = y + 300.0f;
        func_80029714_2A314(b->model[i], x, y, (u8)(rand8() % 30) + 100.0f);
        x = (u8)(rand8() % 250);
        x = 1330.0f - x;
        y = rand8() % 300;
        y = y + 300.0f;
        func_80029714_2A314(c->model[i], x, y, (u8)(rand8() % 30) + 100.0f);
        ((DRObjWork*)a->unk_50)->state = 1;
        ((DRObjWork*)b->unk_50)->state = 1;
        ((DRObjWork*)c->unk_50)->state = 1;
    }
}

void func_80103D5C_12753C_DayAtTheRaces(void) {
    omObjData* a = D_8010AC10_12E3F0_DayAtTheRaces.objs[27];
    omObjData* b = D_8010AC10_12E3F0_DayAtTheRaces.objs[28];
    omObjData* c = D_8010AC10_12E3F0_DayAtTheRaces.objs[29];
    s32 i;

    omSetTra(a, 0.0f, 500.0f, 0.0f);
    omSetTra(b, 0.0f, 500.0f, 0.0f);
    omSetTra(c, 0.0f, 500.0f, 0.0f);
    for (i = 0; i < 22; i++) {
        func_800298A4_2A4A4(a->model[i], 4, 4);
        func_800298A4_2A4A4(b->model[i], 4, 4);
        func_800298A4_2A4A4(c->model[i], 4, 4);
        func_80029714_2A314(a->model[i], 0.0f, 500.0f, 0.0f);
        func_80029714_2A314(b->model[i], 0.0f, 500.0f, 0.0f);
        func_80029714_2A314(c->model[i], 0.0f, 500.0f, 0.0f);
    }
}

void func_80103EC4_1276A4_DayAtTheRaces(s32 stop) {
    s32 i;

    if (stop != 0) {
        func_80029FE4_2ABE4(D_8010AC10_12E3F0_DayAtTheRaces.objs[3]->model[0], 0.0f);
        ((DRObjWork*)D_8010AC10_12E3F0_DayAtTheRaces.objs[10]->unk_50)->state = 2;
        ((DRObjWork*)D_8010AC10_12E3F0_DayAtTheRaces.objs[11]->unk_50)->state = 2;
        for (i = 27; i < 30; i++) {
            if (((DRObjWork*)D_8010AC10_12E3F0_DayAtTheRaces.objs[i]->unk_50)->state != 0) {
                ((DRObjWork*)D_8010AC10_12E3F0_DayAtTheRaces.objs[i]->unk_50)->state = 2;
            }
        }
    } else {
        func_80029FE4_2ABE4(D_8010AC10_12E3F0_DayAtTheRaces.objs[3]->model[0], 1.0f);
        ((DRObjWork*)D_8010AC10_12E3F0_DayAtTheRaces.objs[10]->unk_50)->state = 1;
        ((DRObjWork*)D_8010AC10_12E3F0_DayAtTheRaces.objs[11]->unk_50)->state = 1;
        for (i = 27; i < 30; i++) {
            if (((DRObjWork*)D_8010AC10_12E3F0_DayAtTheRaces.objs[i]->unk_50)->state != 0) {
                ((DRObjWork*)D_8010AC10_12E3F0_DayAtTheRaces.objs[i]->unk_50)->state = 1;
            }
        }
    }
}

/* .data (0x12D840-0x12DCA0, 8010A060-8010A4C0) */
DRObjDef D_8010A060_12D840_DayAtTheRaces[30] = {
    { { 0.0f, 0.0f, 0.0f }, 0.0f, 0.25f, 0x1B0000, 0x699, 0x0, 0x1, 0x0 },
    { { 0.0f, 2.0f, 0.0f }, 0.0f, 0.25f, 0x1B0004, 0x699, 0x0, 0x1, 0x0 },
    { { 0.0f, 0.0f, 0.0f }, 0.0f, 0.25f, 0x1B0001, 0xA99, 0x2, 0x1, 0x0 },
    { { 0.0f, 0.0f, 0.0f }, 0.0f, 0.25f, 0x1B0002, 0xA99, 0x1, 0x1, 0x0 },
    { { 100.0f, -14.0f, -285.0f }, 0.0f, 0.25f, 0x1B0003, 0xA99, 0x3, 0x1, 0x0 },
    { { 100.0f, 18.0f, -285.0f }, 0.0f, 0.4f, 0x1B0015, 0xA99, 0x4, 0x1, 0x1B001C },
    { { -9.0f, 35.0f, -360.0f }, 0.0f, 0.25f, 0x1B0016, 0xA99, 0x5, 0x1, 0x0 },
    { { -9.0f, 35.0f, -360.0f }, 0.0f, 0.25f, 0x1B0017, 0xA99, 0x5, 0x1, 0x0 },
    { { 400.0f, 35.0f, -360.0f }, 0.0f, 0.25f, 0x1B0016, 0xA99, 0x5, 0x1, 0x0 },
    { { 400.0f, 35.0f, -360.0f }, 0.0f, 0.25f, 0x1B0017, 0xA99, 0x5, 0x1, 0x0 },
    { { 950.0f, 35.0f, -360.0f }, 0.0f, 0.25f, 0x1B0016, 0xA99, 0x5, 0x1, 0x0 },
    { { 950.0f, 35.0f, -360.0f }, 0.0f, 0.25f, 0x1B0017, 0xA99, 0x5, 0x1, 0x0 },
    { { -43.75f, 0.0f, -300.0f }, 0.0f, 0.25f, 0x1B0005, 0xA99, 0x0, 0x1, 0x0 },
    { { 356.25f, 0.0f, -300.0f }, 0.0f, 0.25f, 0x1B0005, 0xA99, 0x0, 0x1, 0x0 },
    { { 731.25f, 0.0f, -325.0f }, 0.0f, 0.25f, 0x1B0005, 0xA99, 0x0, 0x1, 0x0 },
    { { 893.75f, 0.0f, -325.0f }, 0.0f, 0.25f, 0x1B0005, 0xA99, 0x0, 0x1, 0x0 },
    { { 1437.5f, 0.0f, -300.0f }, 0.0f, 0.25f, 0x1B0005, 0xA99, 0x0, 0x1, 0x0 },
    { { 0.0f, 0.0f, -312.5f }, 0.0f, 0.25f, 0x1B0006, 0xA99, 0x0, 0x1, 0x0 },
    { { 400.0f, 0.0f, -312.5f }, 0.0f, 0.25f, 0x1B0006, 0xA99, 0x0, 0x1, 0x0 },
    { { 775.0f, 0.0f, -337.5f }, 0.0f, 0.25f, 0x1B0006, 0xA99, 0x0, 0x1, 0x0 },
    { { 937.5f, 0.0f, -337.5f }, 0.0f, 0.25f, 0x1B0006, 0xA99, 0x0, 0x1, 0x0 },
    { { 1481.25f, 0.0f, -312.0f }, 0.0f, 0.25f, 0x1B0006, 0xA99, 0x0, 0x1, 0x0 },
    { { 37.5f, 0.0f, -300.0f }, 0.0f, 0.25f, 0x1B0007, 0xA99, 0x0, 0x1, 0x0 },
    { { 437.5f, 0.0f, -300.0f }, 0.0f, 0.25f, 0x1B0007, 0xA99, 0x0, 0x1, 0x0 },
    { { 812.5f, 0.0f, -325.0f }, 0.0f, 0.25f, 0x1B0007, 0xA99, 0x0, 0x1, 0x0 },
    { { 975.0f, 0.0f, -325.0f }, 0.0f, 0.25f, 0x1B0007, 0xA99, 0x0, 0x1, 0x0 },
    { { 1518.75f, 0.0f, -300.0f }, 0.0f, 0.25f, 0x1B0007, 0xA99, 0x0, 0x1, 0x0 },
    { { 0.0f, 0.0f, 0.0f }, 0.0f, 0.25f, 0x1B0008, 0xA9D, 0x6, 0x16, 0x0 },
    { { 0.0f, 0.0f, 0.0f }, 0.0f, 0.25f, 0x1B0009, 0xA9D, 0x6, 0x16, 0x0 },
    { { 0.0f, 0.0f, 0.0f }, 0.0f, 0.25f, 0x1B000A, 0xA9D, 0x6, 0x16, 0x0 },
};
void* D_8010A498_12DC78_DayAtTheRaces[10] = {
    NULL, NULL, func_80102850_126030_DayAtTheRaces, func_801028CC_1260AC_DayAtTheRaces,
    func_80102940_126120_DayAtTheRaces, func_801029C4_1261A4_DayAtTheRaces,
    func_801031EC_1269CC_DayAtTheRaces, NULL, NULL, NULL,
};
