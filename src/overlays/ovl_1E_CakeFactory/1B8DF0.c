#include "ovl_1E.h"
f32 D_80107A30_1BE020_CakeFactory[3][7] = { { 0, 0, 0, 0, 0, 0, 3400.0f }, { 0, 0, 0, 0, 0, 0, 3400.0f }, { 0, 0, 0, 0, 0, 0, 3400.0f } };
CFPlayer D_80107A84_1BE074_CakeFactory[4] = {
    { -120.0f, 0.0f, -220.0f, 0.0f, 1.0f, 0.0f, 0, 2, 0 },
    { 120.0f, 0.0f, -220.0f, 180.0f, 1.0f, 0.0f, 1, 2, 0 },
    { -120.0f, 0.0f, 220.0f, 0.0f, 1.0f, 0.0f, 2, 2, 0 },
    { 120.0f, 0.0f, 220.0f, 180.0f, 1.0f, 0.0f, 3, 2, 0 },
};
f32 D_80107B14_1BE104_CakeFactory[2] = { 45.0f, 95.0f };
f32 D_80107B1C_1BE10C_CakeFactory[2] = { 4.0f, 6.0f };
f32 D_80107B24_1BE114_CakeFactory[6] = { 1.5f, 1.0f, 1.5f, 2.0f, 3.0f, 0.0f };
f32 D_80107B3C_1BE12C_CakeFactory[2] = { 35.0f, 35.0f };
CFBeltInit D_80107B44_1BE134_CakeFactory[4] = {
    { 4.0f, -1.0f, 540.0f, -100.0f, 0.0f, 0xB4, 8 },
    { 4.0f, 1.0f, -540.0f, -340.0f, 0.0f, 0xB4, 8 },
    { 4.0f, -1.0f, 540.0f, 340.0f, 0.0f, 0xB4, 8 },
    { 4.0f, 1.0f, -540.0f, 100.0f, 0.0f, 0xB4, 8 },
};
s32 D_80107BA4_1BE194_CakeFactory[4] = { 0x46, 0x50, 0x46, 0x50 };
s32 D_80107BB4_1BE1A4_CakeFactory[2] = { 0x3C, 0x3C };
s32 D_80107BBC_1BE1AC_CakeFactory[2] = { 0x54, 0xB0 };
s32 D_80107BC4_1BE1B4_CakeFactory[2] = { 0x28, 0x28 };
s32 D_80107BCC_1BE1BC_CakeFactory[4] = { 0x54, 0x54, 0xB0, 0xB0 };
s32 D_80107BDC_1BE1CC_CakeFactory[7] = { 0, 1, 2, 3, 0, 0, 0 };
s32 D_80107BF8_1BE1E8_CakeFactory = 0;
s32 D_80107BFC_1BE1EC_CakeFactory = 0;

void func_80102800_1B8DF0_CakeFactory(void) {
    func_8002D4D0_2E0D0(4);
    func_80020D20_21920(0x20);
    omInitObjMan(0x50, 0);
    func_80079128_79D28();
    func_8000C38C_CF8C();
    omAddObj(0xA, 0, 0, -1, func_80103114_1B9704_CakeFactory);
    func_8002CA48_2D648(0, 0, 0);
    func_80102F64_1B9554_CakeFactory();
    func_8000C460_D060();
    func_80026D28_27928(1);
    func_80026E00_27A00(0, 0.0f, 30.0f, 115.0f);
    func_80026DAC_279AC(0, 0xFF, 0xFF, 0xFF);
    func_80102978_1B8F68_CakeFactory();
    func_80105128_1BB718_CakeFactory();
    func_8010518C_1BB77C_CakeFactory();
    D_80107DA0_1BE390_CakeFactory[0] = omAddObj(6, 0xB, 0, -1, func_80104388_1BA978_CakeFactory);
    D_80107DA0_1BE390_CakeFactory[1] = omAddObj(6, 0xB, 0, -1, func_801043BC_1BA9AC_CakeFactory);
    D_80107DA0_1BE390_CakeFactory[2] = omAddObj(6, 0xB, 0, -1, func_801043F0_1BA9E0_CakeFactory);
    D_80107DA0_1BE390_CakeFactory[3] = omAddObj(6, 0xB, 0, -1, func_80104424_1BAA14_CakeFactory);
    func_801072F4_1BD8E4_CakeFactory();
    InitFadeIn(0, 0x10);
}

__asm__(".section .rodata");
const CFTable D_80107C00_1BE1F0_CakeFactory = { { 0, 0, 1, 1 } };

void func_80102978_1B8F68_CakeFactory(void) {
    CFTable teams = D_80107C00_1BE1F0_CakeFactory;
    s16 partner[4] = { 1, 0, 3, 2 };
    s32 i;
    s32 a;
    s32 b;

    b = 0;
    a = 0;
    if (_CheckFlag(0xC) != 0) {
        D_80107D90_1BE380_CakeFactory = 1;
    } else {
        D_80107D90_1BE380_CakeFactory = 0;
    }
    D_8010803C_1BE62C_CakeFactory[0] = 0;
    D_8010803C_1BE62C_CakeFactory[1] = 0;
    for (i = 0; i < 4; i++) {
        if (gPlayers[i].group == 0) {
            D_80107FB0_1BE5A0_CakeFactory[i] = a++;
        } else {
            D_80107FB0_1BE5A0_CakeFactory[i] = b++ + 2;
        }
        if (!(gPlayers[i].flags & 1)) {
            D_80107E10_1BE400_CakeFactory[i] = 1;
        } else {
            D_80107E10_1BE400_CakeFactory[i] = 0;
        }
    }
    for (i = 0; i < 4; i++) {
        D_80107E30_1BE420_CakeFactory[D_80107FB0_1BE5A0_CakeFactory[i]] = i;
        D_80108020_1BE610_CakeFactory[i] = 1.0f;
        D_80107DF0_1BE3E0_CakeFactory[i] = 1.0f;
    }
    for (i = 0; i < 4; i++) {
        if (D_80107D90_1BE380_CakeFactory != 0) {
            D_80107F56_1BE546_CakeFactory[i] = (s8)D_800FD8AC[0];
        } else {
            D_80107F56_1BE546_CakeFactory[i] = gPlayers[i].cpu_difficulty;
        }
    }
    for (i = 0; i < 4; i++) {
        if (D_80107E10_1BE400_CakeFactory[i] == 1) {
            D_80107F56_1BE546_CakeFactory[i] = 3;
            D_80107F56_1BE546_CakeFactory[D_80107E30_1BE420_CakeFactory[partner[D_80107FB0_1BE5A0_CakeFactory[i]]]] = 3;
        }
    }
    if (!(rand8() & 1)) {
        D_80107DB0_1BE3A0_CakeFactory[0] = 2;
        D_80107DB0_1BE3A0_CakeFactory[1] = 1;
    } else {
        D_80107DB0_1BE3A0_CakeFactory[1] = 2;
        D_80107DB0_1BE3A0_CakeFactory[0] = 1;
    }
    if (!(rand8() & 1)) {
        D_80107DB0_1BE3A0_CakeFactory[2] = 2;
        D_80107DB0_1BE3A0_CakeFactory[3] = 1;
    } else {
        D_80107DB0_1BE3A0_CakeFactory[3] = 2;
        D_80107DB0_1BE3A0_CakeFactory[2] = 1;
    }
    D_80107DC4_1BE3B4_CakeFactory = 30.0f;
    D_80107DC0_1BE3B0_CakeFactory = 30.0f;
    D_80107DE4_1BE3D4_CakeFactory[0] = PlaySound(0x227);
    D_80107DE4_1BE3D4_CakeFactory[1] = PlaySound(0x228);
    D_80107F88_1BE578_CakeFactory = 0;
    D_80107F50_1BE540_CakeFactory = 0;
}

/* The camera: as Handcar Havoc's func_801083B4, one camera. */
void func_80102CF8_1B92E8_CakeFactory(void) {
    Vec3f pos;
    Vec3f target;
    Vec3f up;
    f32 rx;
    f32 ry;
    s16 i;

    for (i = 0; i < 1; i++) {
        rx = D_80102770_103370[i].x;
        ry = D_80102770_103370[i].y;
        pos.x = HuMathSin(ry) * func_800B7890_B8490(rx) * D_800F94A8_FA0A8[i] + D_801013B0_101FB0[i].x;
        pos.y = -HuMathSin(rx) * D_800F94A8_FA0A8[i] + D_801013B0_101FB0[i].y;
        pos.z = func_800B7890_B8490(ry) * func_800B7890_B8490(rx) * D_800F94A8_FA0A8[i] + D_801013B0_101FB0[i].z;
        target.x = D_801013B0_101FB0[i].x;
        target.y = D_801013B0_101FB0[i].y;
        target.z = D_801013B0_101FB0[i].z;
        up.x = HuMathSin(ry) * HuMathSin(rx);
        up.y = func_800B7890_B8490(rx);
        up.z = func_800B7890_B8490(ry) * HuMathSin(rx);
        D_800FC8F8_FD4F8[i][1] = pos.x;
        D_800FC8F8_FD4F8[i][2] = pos.z;
        D_800FC8F8_FD4F8[i][0] = D_80102770_103370[i].y;
        D_800FC8F8_FD4F8[i][3] = D_800C9B80_CA780[i].fov[0];
        D_800FC8F8_FD4F8[i][4] = 2.0f;
        D_800FC8F8_FD4F8[i][5] = D_80100018_100C18[i];
        Hu3DCamSetPositionOrientation(i, &pos, &target, &up);
        Hu3DCamUpdateMtx(i);
    }
}

void func_80102F64_1B9554_CakeFactory(void) {
    s32 cam;

    D_8010274C_10334C.x = 0.0f;
    D_8010274C_10334C.y = 1680.0f;
    D_8010274C_10334C.z = 2300.0f;
    D_800FD474_FE074.x = -D_80107B3C_1BE12C_CakeFactory[0];
    D_800FD474_FE074.y = 0.0f;
    D_800FD474_FE074.z = 0.0f;
    D_800FA610_FB210 = 1000.0f;
    D_80107E18_1BE408_CakeFactory.x = 0.0f;
    D_80107E18_1BE408_CakeFactory.y = 50.0f;
    D_80107E18_1BE408_CakeFactory.z = 50.0f;
    D_80107E40_1BE430_CakeFactory.x = 0.0f;
    D_80107E40_1BE430_CakeFactory.y = 0.0f;
    D_80107E40_1BE430_CakeFactory.z = 500.0f;
    D_80107F8C_1BE57C_CakeFactory.x = 0.0f;
    D_80107F8C_1BE57C_CakeFactory.y = 1.0f;
    D_80107F8C_1BE57C_CakeFactory.z = 0.0f;
    func_80018E30_19A30(1);
    cam = func_80018E78_19A78();
    ScissorSet(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(cam, 10.0f, 80.0f, 8000.0f);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_80079E60_7AA60), 0xA0);
}

void func_80103114_1B9704_CakeFactory(omObjData* obj) {
    if (D_80107F50_1BE540_CakeFactory != 0) {
        if (func_8008F618_90218() == 0) {
            omOvlReturnEx(1);
        }
    } else if (D_801011FC_101DFC == 1) {
        func_80079614_7A214(0x3C);
        func_800794A8_7A0A8(0x3C);
        InitFadeOut(0, 0x14);
        D_80107F50_1BE540_CakeFactory = 1;
    }
}

void func_80103190_1B9780_CakeFactory(omObjData* obj, u16 lane) {
    s32 files[4] = { 0x2E0003, 0x2E0003, 0x2E0002, 0x2E0002 };
    u8 teams[4] = { 0, 0, 1, 1 };
    CFBelt* w;
    f32 zero;
    f32 one;
    f32 z;
    s32 file;
    s32 i;

    w = obj->unk_50 = func_80027154_27D54(sizeof(CFBelt), 0x7918);
    w->lane = lane;
    w->unk_A1 = 0;
    w->head = 0;
    w->unk_9C = D_80107B44_1BE134_CakeFactory[lane].unk_14;
    w->unk_9E = D_80107B44_1BE134_CakeFactory[lane].unk_16;
    w->speedBase = D_80107B44_1BE134_CakeFactory[lane].speed;
    w->dir = D_80107B44_1BE134_CakeFactory[lane].dir;
    w->count = 0;
    w->every = 0;
    w->team = teams[lane];
    w->phase = 0.0f;
    w->unk_98 = 0.0f;
    D_80107E50_1BE440_CakeFactory[lane].flags = 0;
    D_80107E50_1BE440_CakeFactory[lane].next = 0;
    D_80107E50_1BE440_CakeFactory[lane].taken = 0;
    D_80107E50_1BE440_CakeFactory[lane].cake = 0;
    obj->model[0] = LoadFormFile(files[lane], 0x689);
    w->kind = D_80107DB0_1BE3A0_CakeFactory[lane];
    func_8002A00C_2AC0C(obj->model[0]);
    file = (w->kind == 2) ? 0x2E0000 : 0x2E0001;
    for (i = 1; i < 12; i++) {
        obj->model[i] = LoadFormFile(file, 0x289);
        w->x[i] = 1000.0f;
        w->y[i] = 50.0f;
        w->z[i] = 1000.0f;
    }
    for (i = 0; i < 3; i++) {
        D_80107E50_1BE440_CakeFactory[lane].state[i] = 0;
        D_80107E50_1BE440_CakeFactory[lane].mdl[i] = obj->model[i + 8];
    }
    zero = 0.0f;
    w->x[0] = zero;
    obj->trans.x = zero;
    w->y[0] = zero;
    obj->trans.y = zero;
    z = D_80107B44_1BE134_CakeFactory[lane].z;
    w->z[0] = z;
    obj->trans.z = z;
    obj->rot.z = zero;
    obj->rot.y = zero;
    obj->rot.x = zero;
    obj->scale.x = 1.0f;
    obj->scale.z = 1.0f;
    obj->scale.y = 1.0f;
    one = 1.0f;
    func_800297E8_2A3E8(obj->model[0], obj->scale.x, one, obj->scale.z);
    func_8002979C_2A39C(obj->model[0], obj->rot.x, obj->rot.y, obj->rot.z);
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    for (i = 1; i < 12; i++) {
        func_800297E8_2A3E8(obj->model[i], one, one, one);
        func_80029714_2A314(obj->model[i], w->x[i], w->y[i], w->z[i]);
        func_8002979C_2A39C(obj->model[i], 0.0f, obj->rot.y, obj->rot.z);
        func_800298A4_2A4A4(obj->model[i], 0x70000000, 0x70000000);
    }
    for (i = 0; i < 3; i++) {
        func_800298A4_2A4A4(obj->model[i + 8], 4, 4);
        func_800298A4_2A4A4(obj->model[i + 8], 0x70000000, 0x70000000);
        func_80029714_2A314(obj->model[i + 8], D_80107A84_1BE074_CakeFactory[lane].x, 50.0f, D_80107B44_1BE134_CakeFactory[lane].z);
    }
    D_80107DCC_1BE3BC_CakeFactory[lane] = obj->model[8];
}

/* The world position of a part: its matrix times the model's. */
void func_801035E8_1B9BD8_CakeFactory(s16 model, Vec* out, f32 (*m)[4]) {
    f32 t[4][4];
    f32 r[4][4];
    HmfModel* mdl;

    mdl = &D_800FC834_FD434[model];
    func_800B1F50_B2B50(t, mdl->pos.x, mdl->pos.y, mdl->pos.z);
    func_80025884_26484(t, mdl->rot.x, mdl->rot.y, mdl->rot.z);
    func_80025830_26430(t, mdl->scale.x, mdl->scale.y, mdl->scale.z);
    func_80025BA4_267A4(m, t, r);
    out->x = r[0][0] + r[1][0] + r[2][0] + r[3][0];
    out->y = r[0][1] + r[1][1] + r[2][1] + r[3][1];
    out->z = r[0][2] + r[1][2] + r[2][2] + r[3][2];
}

__asm__(".section .rodata");
const CFTable D_80107C2C_1BE21C_CakeFactory = { { 0x20, 0x60, 0x20, 0x60 } };

/* NON_MATCHING: correct logic; GCC keeps i * 2 in a register across case 4, retail recomputes it (register residue only). */
#ifdef NON_MATCHING
void func_801036E8_1B9CD8_CakeFactory(omObjData* obj) {
    CFTable pans = D_80107C2C_1BE21C_CakeFactory;
    Vec pos;
    f32 m[4][4];
    CFBelt* w;
    CFTeam* team;
    f32 t;
    f32 inv;
    f32 sa;
    f32 sb;
    f32 rate;
    f32 step;
    f32 cx;
    f32 lo;
    f32 hi;
    f32 lo2;
    f32 hi2;
    f32 x;
    u8 drop;
    s32 i;
    s32 sfx;
    s32 k;
    s32 frame;

    w = obj->unk_50;
    team = D_80107DB4_1BE3A4_CakeFactory[w->team]->unk_50;
    t = (D_80107DC4_1BE3B4_CakeFactory - D_80107DC0_1BE3B0_CakeFactory) / D_80107DC4_1BE3B4_CakeFactory;
    sb = w->speedBase * D_80107B24_1BE114_CakeFactory[D_80108054_1BE644_CakeFactory];
    sa = w->speedBase * D_80107B24_1BE114_CakeFactory[D_80108054_1BE644_CakeFactory - 1];
    inv = 1.0f - t;
    step = sa * inv + sb * t;
    rate = step;
    team->speedMul = inv * D_80107B24_1BE114_CakeFactory[D_80108054_1BE644_CakeFactory - 1] + t * D_80107B24_1BE114_CakeFactory[D_80108054_1BE644_CakeFactory];
    step *= w->dir;
    w->speed = step;
    D_80108020_1BE610_CakeFactory[w->lane] = step;
    obj->trans.x += step;
    if (w->phase >= 180.0f) {
        w->phase = 0.0f;
    }
    drop = 0;
    if (w->phase == 0.0f) {
        if (w->kind == 2 && w->every == w->count) {
            w->every = D_80107F51_1BE541_CakeFactory;
            drop = 1;
            w->count = 0;
        } else if (w->kind == 1 && w->every == w->count) {
            w->every = D_80107E14_1BE404_CakeFactory;
            drop = 1;
            w->count = 0;
        } else {
            w->count++;
        }
    }
    if (drop && D_80107DBC_1BE3AC_CakeFactory >= 2) {
        w->x[w->head + 1] = D_80107B44_1BE134_CakeFactory[w->lane].x;
        w->z[w->head + 1] = D_80107B44_1BE134_CakeFactory[w->lane].z;
        w->head++;
        if (w->head + 1 >= 7) {
            w->head = 0;
        }
    }
    w->phase += rate;
    cx = D_80107A84_1BE074_CakeFactory[w->lane].x;
    lo = cx - 40.0f;
    hi = cx + 40.0f;
    switch (D_80107F56_1BE546_CakeFactory[D_80107E30_1BE420_CakeFactory[w->lane]]) {
    case 0:
        lo2 = D_80107A84_1BE074_CakeFactory[w->lane].x - step * 8.0f - 8.0f;
        hi2 = D_80107A84_1BE074_CakeFactory[w->lane].x - step * 8.0f;
        break;
    case 1:
        lo2 = D_80107A84_1BE074_CakeFactory[w->lane].x - step * 8.0f - 15.0f;
        hi2 = D_80107A84_1BE074_CakeFactory[w->lane].x - step * 8.0f;
        break;
    case 2:
        lo2 = D_80107A84_1BE074_CakeFactory[w->lane].x - step * 12.0f - 10.0f;
        hi2 = D_80107A84_1BE074_CakeFactory[w->lane].x - step * 12.0f;
        break;
    case 3:
        lo2 = D_80107A84_1BE074_CakeFactory[w->lane].x - step * 12.0f - 15.0f;
        hi2 = D_80107A84_1BE074_CakeFactory[w->lane].x - step * 12.0f;
        break;
    }
    D_80107E50_1BE440_CakeFactory[w->lane].flags2 &= ~0x20;
    D_80107E50_1BE440_CakeFactory[w->lane].flags2 &= ~0x80;
    if (D_80107E50_1BE440_CakeFactory[w->lane].flags & 4) {
        if (D_80107E50_1BE440_CakeFactory[w->lane].taken != 0) {
            w->x[D_80107E50_1BE440_CakeFactory[w->lane].taken] = 1000.0f;
            w->z[D_80107E50_1BE440_CakeFactory[w->lane].taken] = 1000.0f;
            D_80107E50_1BE440_CakeFactory[w->lane].taken = 0;
            D_80107E50_1BE440_CakeFactory[w->lane].cake = 0;
        }
        D_80107E50_1BE440_CakeFactory[w->lane].flags &= ~4;
    }
    for (i = 1; i < 7; i++) {
        if (w->x[i] >= -540.0f && w->x[i] <= 540.0f) {
            w->x[i] += step;
        } else {
            w->x[i] = 1000.0f;
            w->z[i] = 1000.0f;
        }
        x = w->x[i];
        if ((lo < x) & (x < hi)) {
            D_80107E50_1BE440_CakeFactory[w->lane].flags2 |= 0x20;
            D_80107E50_1BE440_CakeFactory[w->lane].cake = i;
            if (D_80107E50_1BE440_CakeFactory[w->lane].flags & 4) {
                w->x[i] = 1000.0f;
                w->z[i] = 1000.0f;
            }
        }
        if ((lo2 < x) & (x < hi2)) {
            D_80107E50_1BE440_CakeFactory[w->lane].flags2 |= 0x80;
        }
        func_80029714_2A314(obj->model[i], w->x[i], w->y[i], w->z[i]);
    }
    for (i = 0; i < 3; i++) {
        switch (D_80107E50_1BE440_CakeFactory[w->lane].state[i]) {
        case 3:
            frame = func_80029CE4_2A8E4(D_80107D92_1BE382_CakeFactory[D_80107E30_1BE420_CakeFactory[w->lane]]);
            func_80023554_24154(D_80107D92_1BE382_CakeFactory[D_80107E30_1BE420_CakeFactory[w->lane]], frame, "item_hook", m);
            func_801035E8_1B9BD8_CakeFactory(D_80107D92_1BE382_CakeFactory[D_80107E30_1BE420_CakeFactory[w->lane]], &pos, m);
            func_80029714_2A314(D_80107E50_1BE440_CakeFactory[w->lane].mdl[i], pos.x, pos.y - 20.0f, pos.z + 6.0f);
            break;
        case 4:
            D_80107E50_1BE440_CakeFactory[w->lane].state[i] = 5;
            k = team->slot[1] == D_80107DB0_1BE3A0_CakeFactory[w->lane];
            w->y[i + 8] = D_80107B14_1BE104_CakeFactory[k];
            w->z[i + 8] = D_80107A84_1BE074_CakeFactory[w->lane].z + D_80107B1C_1BE10C_CakeFactory[k];
            w->dropY = 120.0f;
            func_80029714_2A314(D_80107E50_1BE440_CakeFactory[w->lane].mdl[i], 0.0f, 120.0f, w->z[i + 8]);
            break;
        case 5:
            team->busy = 1;
            w->dropY -= 15.0f;
            if (w->dropY <= w->y[i + 8]) {
                w->dropY = w->y[i + 8];
                D_80107E50_1BE440_CakeFactory[w->lane].state[i] = 6;
                sfx = 0x224;
                if (D_80107DB0_1BE3A0_CakeFactory[w->lane] == 2) {
                    sfx = 0x223;
                }
                func_80015710_16310((s16)PlaySound(sfx), pans.v[w->lane]);
            }
            func_80029714_2A314(D_80107E50_1BE440_CakeFactory[w->lane].mdl[i], 0.0f, w->dropY, w->z[i + 8]);
            break;
        case 6:
            if (team->state == 3) {
                func_80029714_2A314(D_80107E50_1BE440_CakeFactory[w->lane].mdl[i], 0.0f, w->y[i + 8] + team->y, w->z[i + 8]);
                if (w->y[i + 8] + team->y < -80.0f) {
                    func_800298A4_2A4A4(D_80107E50_1BE440_CakeFactory[w->lane].mdl[i], 4, 4);
                }
            }
            if (team->state == 4) {
                func_800298A4_2A4A4(D_80107E50_1BE440_CakeFactory[w->lane].mdl[i], 4, 4);
                func_80029714_2A314(D_80107E50_1BE440_CakeFactory[w->lane].mdl[i], D_80107A84_1BE074_CakeFactory[D_80107FB0_1BE5A0_CakeFactory[w->lane]].x, 50.0f, D_80107B44_1BE134_CakeFactory[w->lane].z);
                D_80107E50_1BE440_CakeFactory[w->lane].state[i] = 0;
            }
            break;
        }
    }
    if (step > 0.0f) {
        if (obj->trans.x >= 48.0f) {
            obj->trans.x = 0.0f;
        }
    } else if (obj->trans.x <= 0.0f) {
        obj->trans.x = 48.0f;
    }
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1E_CakeFactory/1B8DF0", func_801036E8_1B9CD8_CakeFactory);
#endif

void func_80104388_1BA978_CakeFactory(omObjData* obj) {
    func_80103190_1B9780_CakeFactory(obj, 0);
    obj->func_ptr = func_801036E8_1B9CD8_CakeFactory;
}

void func_801043BC_1BA9AC_CakeFactory(omObjData* obj) {
    func_80103190_1B9780_CakeFactory(obj, 1);
    obj->func_ptr = func_801036E8_1B9CD8_CakeFactory;
}

void func_801043F0_1BA9E0_CakeFactory(omObjData* obj) {
    func_80103190_1B9780_CakeFactory(obj, 2);
    obj->func_ptr = func_801036E8_1B9CD8_CakeFactory;
}

void func_80104424_1BAA14_CakeFactory(omObjData* obj) {
    func_80103190_1B9780_CakeFactory(obj, 3);
    obj->func_ptr = func_801036E8_1B9CD8_CakeFactory;
}

void func_80104458_1BAA48_CakeFactory(void) {
    s32 i;

    if ((u16)func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        for (i = 0; i < 4; i++) {
            D_80107DF0_1BE3E0_CakeFactory[i] -= D_80108020_1BE610_CakeFactory[i] * 0.64f;
        }
    }
    for (i = 0; i < 4; i++) {
        func_8002BCA8_2C8A8(D_80107DA0_1BE390_CakeFactory[i]->model[0], D_80107DF0_1BE3E0_CakeFactory[i], 0.0f, 0x20, 0x40);
    }
}

void func_80104544_1BAB34_CakeFactory(omObjData* obj) {
    CFTable teams = D_80107C00_1BE1F0_CakeFactory;
    s16 win[2];
    CFTeam* a;
    CFTeam* b;
    s32 i;
    s32 p;
    s32 q;
    u8 tie;
    u8 waiting;
    s16 pitch;
    u8 vol;

    win[0] = 6;
    win[1] = 7;
    a = D_80107DB4_1BE3A4_CakeFactory[teams.v[0]]->unk_50;
    b = D_80107DB4_1BE3A4_CakeFactory[teams.v[2]]->unk_50;
    D_80107DCA_1BE3BA_CakeFactory--;
    if (D_80107DCA_1BE3BA_CakeFactory == 0) {
        D_80107DCA_1BE3BA_CakeFactory = 0x1E;
        if (D_80107DBC_1BE3AC_CakeFactory > 0) {
            D_80107DBC_1BE3AC_CakeFactory--;
        }
    }
    switch (D_80107F88_1BE578_CakeFactory) {
    case 1:
        for (i = 0; i < 4; i++) {
            D_80107F78_1BE568_CakeFactory[i] = 1;
            D_80108058_1BE648_CakeFactory[i] = 0;
        }
        D_80107F88_1BE578_CakeFactory = 2;
        break;
    case 2:
        func_8006D4D0_6E0D0((s16)D_80107DBC_1BE3AC_CakeFactory);
        if (D_80108054_1BE644_CakeFactory >= 5) {
            func_8006D518_6E118();
            func_80079614_7A214(0x5A);
            func_800794A8_7A0A8(0x28);
            func_800691FC_69DFC(3);
            D_80107F88_1BE578_CakeFactory = 3;
        }
        if (D_80107DBC_1BE3AC_CakeFactory == 0x16) {
            D_80107DC4_1BE3B4_CakeFactory = 30.0f;
            D_80107DC0_1BE3B0_CakeFactory = 30.0f;
            D_80108054_1BE644_CakeFactory = 2;
        }
        if (D_80107DBC_1BE3AC_CakeFactory == 0xE) {
            D_80107DC4_1BE3B4_CakeFactory = 30.0f;
            D_80107DC0_1BE3B0_CakeFactory = 30.0f;
            D_80108054_1BE644_CakeFactory = 3;
        }
        if (D_80107DBC_1BE3AC_CakeFactory == 7) {
            D_80107DC4_1BE3B4_CakeFactory = 30.0f;
            D_80107DC0_1BE3B0_CakeFactory = 30.0f;
            D_80108054_1BE644_CakeFactory = 4;
        }
        if (D_80107DBC_1BE3AC_CakeFactory == 0 && D_80108054_1BE644_CakeFactory == 4) {
            D_80107DC4_1BE3B4_CakeFactory = 60.0f;
            D_80107DC0_1BE3B0_CakeFactory = 60.0f;
            D_80108054_1BE644_CakeFactory = 5;
        }
        break;
    case 3:
        if (func_80069538_6A138() == 2) {
            D_80107FD4_1BE5C4_CakeFactory = 0xB4;
            D_80107F88_1BE578_CakeFactory = 4;
        }
        break;
    case 4:
        D_80107FD4_1BE5C4_CakeFactory--;
        waiting = 0;
        for (i = 0; i < 4; i++) {
            if (D_80108058_1BE648_CakeFactory[i] != 0xD) {
                waiting = 1;
            }
        }
        if (!waiting) {
            D_80107FD4_1BE5C4_CakeFactory = 0;
            if (D_80107D90_1BE380_CakeFactory == 1) {
                D_80107FD4_1BE5C4_CakeFactory = 0x4B;
                D_80107F88_1BE578_CakeFactory = 7;
            } else {
                D_80107FD4_1BE5C4_CakeFactory = 0x1E;
                D_80107F88_1BE578_CakeFactory = 5;
            }
        } else if (D_80107FD4_1BE5C4_CakeFactory == 0) {
            for (i = 0; i < 4; i++) {
                D_80108058_1BE648_CakeFactory[i] = 0xD;
                D_80107F78_1BE568_CakeFactory[i] = 1;
            }
            D_80107FD4_1BE5C4_CakeFactory = 0;
            if (D_80107D90_1BE380_CakeFactory == 1) {
                D_80107F88_1BE578_CakeFactory = 7;
            } else {
                D_80107F88_1BE578_CakeFactory = 5;
            }
        }
        break;
    case 5:
        a = D_80107DB4_1BE3A4_CakeFactory[teams.v[0]]->unk_50;
        b = D_80107DB4_1BE3A4_CakeFactory[teams.v[2]]->unk_50;
        tie = 0;
        q = -1;
        p = -1;
        if (a->score > b->score) {
            D_80108050_1BE640_CakeFactory[D_80107E30_1BE420_CakeFactory[0]] = 0;
            D_80108050_1BE640_CakeFactory[D_80107E30_1BE420_CakeFactory[1]] = 0;
            p = D_80107E30_1BE420_CakeFactory[0];
            q = D_80107E30_1BE420_CakeFactory[1];
        } else if (a->score < b->score) {
            D_80108050_1BE640_CakeFactory[D_80107E30_1BE420_CakeFactory[2]] = 0;
            D_80108050_1BE640_CakeFactory[D_80107E30_1BE420_CakeFactory[3]] = 0;
            p = D_80107E30_1BE420_CakeFactory[2];
            q = D_80107E30_1BE420_CakeFactory[3];
        } else {
            tie = 1;
        }
        for (i = 0; i < 4; i++) {
            if (D_80108050_1BE640_CakeFactory[i] == 0) {
                gPlayers[i].coins_mg_bonus += 10;
                func_800732B0_73EB0(D_80107F60_1BE550_CakeFactory[i]);
            }
            D_800FFFD8_100BD8[i]->rot.y = 0.0f;
            func_80029B80_2A780(D_800FFFD8_100BD8[i]->model[0], D_800FFFD8_100BD8[i]->motion[win[D_80108050_1BE640_CakeFactory[i]]]);
        }
        if (tie) {
            func_800691FC_69DFC(0x13);
            PlayMusic(0x57);
            D_80107FD4_1BE5C4_CakeFactory = 0x78;
        } else {
            func_800691FC_69DFC(0x11, gPlayers[p].character, gPlayers[q].character);
            PlayMusic(0x52);
            D_80107FD4_1BE5C4_CakeFactory = 0xA8;
        }
        D_80107F88_1BE578_CakeFactory = 8;
        break;
    case 6:
        if (func_80069538_6A138() == 2) {
            D_80107FD4_1BE5C4_CakeFactory = 0x5A;
            D_80107F88_1BE578_CakeFactory = 8;
        }
        break;
    case 7:
        a = D_80107DB4_1BE3A4_CakeFactory[teams.v[0]]->unk_50;
        b = D_80107DB4_1BE3A4_CakeFactory[teams.v[2]]->unk_50;
        if (a->score > b->score) {
            D_80108050_1BE640_CakeFactory[D_80107E30_1BE420_CakeFactory[0]] = 0;
            D_80108050_1BE640_CakeFactory[D_80107E30_1BE420_CakeFactory[1]] = 0;
        } else if (a->score < b->score) {
            D_80108050_1BE640_CakeFactory[D_80107E30_1BE420_CakeFactory[2]] = 0;
            D_80108050_1BE640_CakeFactory[D_80107E30_1BE420_CakeFactory[3]] = 0;
        }
        for (i = 0; i < 4; i++) {
            if (D_80108050_1BE640_CakeFactory[i] == 0) {
                gPlayers[i].coins_mg_bonus += 10;
            }
        }
        D_80107FD4_1BE5C4_CakeFactory = 0xF;
        D_80107F88_1BE578_CakeFactory = 8;
        break;
    case 8:
        if (--D_80107FD4_1BE5C4_CakeFactory < 0) {
            InitFadeOut(0, 0x14);
            D_80107F88_1BE578_CakeFactory = 9;
        }
        break;
    case 9:
        if (func_8008F618_90218() == 0) {
            omOvlReturnEx(1);
        }
        break;
    case 0:
        break;
    }
    D_80107F51_1BE541_CakeFactory = rand8() & 1;
    D_80107E14_1BE404_CakeFactory = rand8() & 1;
    if (a->score < 10) {
        SprBankSet((s16)D_80107DD4_1BE3C4_CakeFactory, 0, a->score);
    } else {
        SprAttrReset((s16)D_80107DD4_1BE3C4_CakeFactory, 1, 0x8000);
        SprBankSet((s16)D_80107DD4_1BE3C4_CakeFactory, 0, a->score / 10);
        SprBankSet((s16)D_80107DD4_1BE3C4_CakeFactory, 1, a->score % 10);
    }
    if (b->score < 10) {
        SprBankSet((s16)D_80107DD4_1BE3C4_CakeFactory, 2, b->score);
    } else {
        SprAttrReset((s16)D_80107DD4_1BE3C4_CakeFactory, 3, 0x8000);
        SprBankSet((s16)D_80107DD4_1BE3C4_CakeFactory, 2, b->score / 10);
        SprBankSet((s16)D_80107DD4_1BE3C4_CakeFactory, 3, b->score % 10);
    }
    if (a->scoreAngle > 0.0f) {
        a->scoreAngle += 20.0f;
        if (a->scoreAngle > 180.0f) {
            a->scoreAngle = 0.0f;
        }
        a->scoreScale = HuMathSin(a->scoreAngle) / 2.0f + 1.0f;
    } else {
        a->scoreScale = 1.0f;
        a->scoreAngle = 0.0f;
    }
    SprScaleSet((s16)D_80107DDC_1BE3CC_CakeFactory, 0, a->scoreScale, a->scoreScale);
    if (b->scoreAngle != 0.0f) {
        b->scoreAngle += 20.0f;
        if (b->scoreAngle > 180.0f) {
            b->scoreAngle = 0.0f;
        }
        b->scoreScale = HuMathSin(b->scoreAngle) / 2.0f + 1.0f;
    } else {
        b->scoreScale = 1.0f;
        b->scoreAngle = 0.0f;
    }
    SprScaleSet((s16)D_80107DE0_1BE3D0_CakeFactory, 0, b->scoreScale, b->scoreScale);
    pitch = (s16)a->speedMul * 150;
    if (pitch >= 301) {
        pitch = 300;
    }
    if (pitch <= 0) {
        pitch = 0;
        vol = 0;
    } else {
        vol = 0x7F;
    }
    func_800795D8_7A1D8(D_80107DE4_1BE3D4_CakeFactory[0], vol);
    func_800796F0_7A2F0(D_80107DE4_1BE3D4_CakeFactory[0], pitch);
    pitch = b->speedMul * 150.0f;
    if (pitch >= 301) {
        pitch = 300;
    }
    if (pitch <= 0) {
        pitch = 0;
        vol = 0;
    } else {
        vol = 0x7F;
    }
    func_800795D8_7A1D8(D_80107DE4_1BE3D4_CakeFactory[1], vol);
    func_800796F0_7A2F0(D_80107DE4_1BE3D4_CakeFactory[1], pitch);
    if (D_80107DC0_1BE3B0_CakeFactory != 0.0f) {
        D_80107DC0_1BE3B0_CakeFactory -= 1.0f;
    }
}

void func_80105074_1BB664_CakeFactory(omObjData* obj) {
    if (D_80107DC8_1BE3B8_CakeFactory != 0) {
        D_80107DC8_1BE3B8_CakeFactory--;
        if (D_80107DC8_1BE3B8_CakeFactory == 0) {
            func_800691FC_69DFC(0);
        }
        if (D_80107DC8_1BE3B8_CakeFactory == 0x37) {
            PlayMusic(0x21);
        }
    }
    if (func_80069538_6A138() == 2) {
        func_800691FC_69DFC(0xA, D_80107DBC_1BE3AC_CakeFactory, 0xA0, 0x1C);
        D_80107F88_1BE578_CakeFactory = 1;
        obj->func_ptr = func_80104544_1BAB34_CakeFactory;
    }
}

void func_80105128_1BB718_CakeFactory(void) {
    D_80107DBC_1BE3AC_CakeFactory = 0x1E;
    D_80107DCA_1BE3BA_CakeFactory = 0x1E;
    D_80107DC8_1BE3B8_CakeFactory = 0x3C;
    D_80108054_1BE644_CakeFactory = 1;
    omAddObj(0, 0, 0, -1, func_80105074_1BB664_CakeFactory);
}

void func_8010518C_1BB77C_CakeFactory(void) {
    u16 hud[8];
    void* data;
    s16 anim;
    s32 i;

    D_80107FA8_1BE598_CakeFactory = SprCreate(func_8001A2F8_1AEF8(0x2E0005) & 0xFFFF, 5);
    for (i = 0; i < 4; i++) {
        hud[i] = func_8001AAAC_1B6AC(D_80107FA8_1BE598_CakeFactory, 0, 1);
        func_8001A708_1B308(hud[i], 0x4008);
        espPosSet(hud[i], i * 0x50 + 0x28, 0x78);
        espDispOn(hud[i]);
        func_8001A91C_1B51C(hud[i], 1.0f, 1.0f);
    }
    D_80107DDC_1BE3CC_CakeFactory = SprCreate(1, 5);
    data = DataRead(0x2E0007);
    anim = SprAnimRead(data);
    DataClose(data);
    SprAnimSet((s16)D_80107DDC_1BE3CC_CakeFactory, 0, anim, 0);
    SprPosSet((s16)D_80107DDC_1BE3CC_CakeFactory, 0, D_80107BC6_1BE1B6_CakeFactory, D_80107BCE_1BE1BE_CakeFactory);
    SprAttrReset((s16)D_80107DDC_1BE3CC_CakeFactory, 0, 0xFFFF);
    SprAttrSet((s16)D_80107DDC_1BE3CC_CakeFactory, 0, 8);
    SprPrioSet((s16)D_80107DDC_1BE3CC_CakeFactory, 0, 0x7000);
    D_80107DE0_1BE3D0_CakeFactory = SprCreate(1, 5);
    data = DataRead(0x2E0006);
    anim = SprAnimRead(data);
    DataClose(data);
    SprAnimSet((s16)D_80107DE0_1BE3D0_CakeFactory, 0, anim, 0);
    SprPosSet((s16)D_80107DE0_1BE3D0_CakeFactory, 0, D_80107BCA_1BE1BA_CakeFactory, D_80107BD6_1BE1C6_CakeFactory);
    SprAttrReset((s16)D_80107DE0_1BE3D0_CakeFactory, 0, 0xFFFF);
    SprAttrSet((s16)D_80107DE0_1BE3D0_CakeFactory, 0, 8);
    SprPrioSet((s16)D_80107DE0_1BE3D0_CakeFactory, 0, 0x7000);
    data = DataRead(0x170010);
    anim = SprAnimRead(data);
    DataClose(data);
    D_80107DD8_1BE3C8_CakeFactory = SprCreate(2, 0);
    for (i = 0; i < 2; i++) {
        SprAnimSet((s16)D_80107DD8_1BE3C8_CakeFactory, i, anim, 0);
        SprPosSet((s16)D_80107DD8_1BE3C8_CakeFactory, i, (s16)D_80107BB4_1BE1A4_CakeFactory[i], (s16)D_80107BBC_1BE1AC_CakeFactory[i]);
        SprScaleSet((s16)D_80107DD8_1BE3C8_CakeFactory, i, 1.0f, 1.0f);
        func_80082488_83088((s16)D_80107DD8_1BE3C8_CakeFactory, i, 0x100);
        SprAttrSet((s16)D_80107DD8_1BE3C8_CakeFactory, i, 0x1000);
        func_8008225C_82E5C((s16)D_80107DD8_1BE3C8_CakeFactory, i, 0);
    }
    data = DataRead(0x43);
    anim = SprAnimRead(data);
    DataClose(data);
    D_80107DD4_1BE3C4_CakeFactory = SprCreate(4, 0);
    for (i = 0; i < 4; i++) {
        SprAnimSet((s16)D_80107DD4_1BE3C4_CakeFactory, i, anim, 0);
        SprPosSet((s16)D_80107DD4_1BE3C4_CakeFactory, i, (s16)D_80107BA4_1BE194_CakeFactory[i], (s16)D_80107BCC_1BE1BC_CakeFactory[i]);
        SprScaleSet((s16)D_80107DD4_1BE3C4_CakeFactory, i, 1.0f, 1.0f);
        func_80082488_83088((s16)D_80107DD4_1BE3C4_CakeFactory, i, 0x100);
        SprAttrSet((s16)D_80107DD4_1BE3C4_CakeFactory, i, 0x1000);
        func_8008225C_82E5C((s16)D_80107DD4_1BE3C4_CakeFactory, i, 0);
    }
    SprAttrSet((s16)D_80107DD4_1BE3C4_CakeFactory, 1, 0x8000);
    SprAttrSet((s16)D_80107DD4_1BE3C4_CakeFactory, 3, 0x8000);
    func_80105D40_1BC330_CakeFactory();
}

void func_801055EC_1BBBDC_CakeFactory(omObjData* obj) {
    f32 down[6] = { 10.0f, 10.0f, 12.0f, 14.0f, 14.0f, 14.0f };
    f32 up[7] = { 8.0f, 8.0f, 9.0f, 10.0f, 11.0f, 11.0f, 10.0f };
    s32 good[6] = { 15, 15, 8, 2, 5, 2 };
    s32 bad[6] = { 30, 30, 20, 10, 10, 2 };
    CFTeam* w;
    s32 n;
    s32 r;
    s32 req;

    w = obj->unk_50;
    switch (w->state) {
    case 0:
        n = w->count;
        r = 0;
        if (n == 0) {
            req = w->req[0];
            if (req & 2) {
                w->req[0] = req & ~2;
                w->slot[0] = 2;
                n = 1;
            } else if (req & 1) {
                if (n == 0) {
                    w->req[0] = req & ~1;
                    w->slot[0] = 1;
                    r = 1;
                    n = 1;
                }
            }
        } else if (w->req[0] & 1) {
            w->slot[n] = 1;
            w->req[0] &= ~1;
            n = 2;
            r = 2;
        } else if (w->req[0] & 2) {
            if (r == 0) {
                w->slot[n] = 2;
                w->req[0] &= ~2;
                n = 2;
                r = 1;
            }
        }
        w->count = n;
        if (r == 2) {
            w->timer = good[D_80108054_1BE644_CakeFactory];
            w->state = 1;
        } else if (r == 1) {
            w->timer = bad[D_80108054_1BE644_CakeFactory];
            w->state = 2;
        }
        break;
    case 1:
        if (w->busy == 0) {
            w->timer--;
        }
        w->busy = 0;
        if (w->timer == 0) {
            PlaySound(0x225);
            PlaySound(0x226);
            w->result = 1;
            w->state = 3;
            w->score++;
            w->scoreAngle = 1.0f;
        }
        break;
    case 2:
        if (w->busy == 0) {
            w->timer--;
        }
        w->busy = 0;
        if (w->timer == 0) {
            w->scoreAngle = 0.0f;
            PlaySound(0x229);
            PlaySound(0x225);
            w->result = 2;
            w->state = 3;
        }
        break;
    case 3:
        obj->trans.y = w->y;
        if (w->y < -80.0f) {
            func_800298A4_2A4A4(obj->model[0], 4, 4);
        }
        if (w->y <= -160.0f) {
            w->state = 4;
        }
        if (w->y > -160.0f) {
            w->y -= down[D_80108054_1BE644_CakeFactory];
        }
        break;
    case 4:
        w->y = -80.0f;
        w->state = 5;
        w->count = 0;
        w->slot[0] = 0;
        w->slot[1] = 0;
        break;
    case 5:
        obj->trans.y = w->y;
        if (w->y > -80.0f) {
            func_800298A4_2A4A4(obj->model[0], 4, 0);
        }
        if (w->y >= -10.0f) {
            w->y = -10.0f;
            w->count = 0;
            w->state = 0;
        }
        if (w->y <= -10.0f) {
            w->y += up[D_80108054_1BE644_CakeFactory];
        }
        break;
    case 6:
        break;
    }
}

void func_80105A80_1BC070_CakeFactory(omObjData* obj) {
    CFTeam* w;
    f32 zero;
    s32 i;

    w = obj->unk_50 = func_80027154_27D54(sizeof(CFTeam), 0x7918);
    w->scoreScale = 1.0f;
    w->scoreAngle = 0.0f;
    w->y = 0.0f;
    w->count = 0;
    w->state = 0;
    w->result = 0;
    w->score = 0;
    w->busy = 0;
    for (i = 0; i < 2; i++) {
        w->slot[i] = 0;
        w->req[i] = 0;
        w->unk_10[i] = 0;
    }
    obj->model[0] = LoadFormFile(0x2E0004, 0x689);
    obj->trans.x = 0.0f;
    obj->trans.y = -10.0f;
    obj->trans.z = D_80107A84_1BE074_CakeFactory[0].z;
    zero = 0.0f;
    obj->rot.z = zero;
    obj->rot.y = zero;
    obj->rot.x = zero;
    obj->scale.z = 1.3f;
    obj->scale.y = 1.3f;
    obj->scale.x = 1.3f;
    func_800298A4_2A4A4(obj->model[0], 0x40000000, 0x40000000);
    func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_8002979C_2A39C(obj->model[0], obj->rot.x, obj->rot.y, obj->rot.z);
    obj->func_ptr = func_801055EC_1BBBDC_CakeFactory;
}

void func_80105BE0_1BC1D0_CakeFactory(omObjData* obj) {
    CFTeam* w;
    f32 zero;
    s32 i;

    w = obj->unk_50 = func_80027154_27D54(sizeof(CFTeam), 0x7918);
    w->scoreScale = 1.0f;
    w->scoreAngle = 0.0f;
    w->y = 0.0f;
    w->count = 0;
    w->state = 0;
    w->result = 0;
    w->score = 0;
    w->busy = 0;
    for (i = 0; i < 2; i++) {
        w->slot[i] = 0;
        w->req[i] = 0;
        w->unk_10[i] = 0;
    }
    obj->model[0] = LoadFormFile(0x2E0004, 0x689);
    obj->trans.x = 0.0f;
    obj->trans.y = -10.0f;
    obj->trans.z = D_80107A84_1BE074_CakeFactory[2].z;
    zero = 0.0f;
    obj->rot.z = zero;
    obj->rot.y = zero;
    obj->rot.x = zero;
    obj->scale.z = 1.3f;
    obj->scale.y = 1.3f;
    obj->scale.x = 1.3f;
    func_800298A4_2A4A4(obj->model[0], 0x40000000, 0x40000000);
    func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_8002979C_2A39C(obj->model[0], obj->rot.x, obj->rot.y, obj->rot.z);
    obj->func_ptr = func_801055EC_1BBBDC_CakeFactory;
}

void func_80105D40_1BC330_CakeFactory(void) {
    D_80107DB4_1BE3A4_CakeFactory[0] = omAddObj(1, 4, 0, -1, func_80105A80_1BC070_CakeFactory);
    D_80107DB4_1BE3A4_CakeFactory[1] = omAddObj(1, 4, 0, -1, func_80105BE0_1BC1D0_CakeFactory);
}

/* A COM player's buttons: press A at the belt, then hold, by difficulty. */
void func_80105DAC_1BC39C_CakeFactory(s32 player) {
    CFTable teams = D_80107C00_1BE1F0_CakeFactory;
    s32 t1[4] = { 3, 5, 5, 50 };
    s32 t2[4] = { 30, 25, 18, 5 };
    s32 t3[4] = { 100, 120, 160, 200 };
    u8 partner[4] = { 1, 0, 3, 2 };
    CFTeam* team;
    s32 lane;
    s32 d;
    s32 s;
    s8 r;

    lane = D_80107FB0_1BE5A0_CakeFactory[player];
    team = D_80107DB4_1BE3A4_CakeFactory[teams.v[lane]]->unk_50;
    switch (D_80107F56_1BE546_CakeFactory[player]) {
    case 0:
        d = 0;
        break;
    case 1:
        d = 1;
        break;
    case 2:
        d = 2;
        break;
    case 3:
        d = 3;
        break;
    }
    switch (D_80108058_1BE648_CakeFactory[player]) {
    case 1:
        if ((D_80107E50_1BE440_CakeFactory[lane].flags2 & 0x80) && (rand8() % (t1[d] + 1)) != 0) {
            D_80108030_1BE620_CakeFactory[player] |= 0x8000;
        }
        break;
    case 7:
        D_80107E24_1BE414_CakeFactory[player] |= 0x8000;
        r = D_80107DB0_1BE3A0_CakeFactory[lane] == 2
                ? (team->count != 0
                       ? (D_80108058_1BE648_CakeFactory[D_80107FB0_1BE5A0_CakeFactory[partner[player]]] == 0xA
                              ? rand8() % (t2[d] + 1)
                              : (s = D_80108058_1BE648_CakeFactory[D_80107FB0_1BE5A0_CakeFactory[partner[player]]], (s == 7 || s == 1) ? rand8() % (t3[d] + 1) : 1))
                       : 0)
                : (team->count == 0
                       ? (D_80108058_1BE648_CakeFactory[D_80107FB0_1BE5A0_CakeFactory[partner[player]]] == 5
                              ? rand8() % (t1[d] + 1)
                              : (s = D_80108058_1BE648_CakeFactory[D_80107FB0_1BE5A0_CakeFactory[partner[player]]], (s == 7 || s == 1) ? rand8() % (t3[d] + 1) : 1))
                       : (rand8() % (t1[d] + 1)) == 0);
        if (r == 0) {
            D_80107E24_1BE414_CakeFactory[player] &= 0x7FFF;
            D_80107F98_1BE588_CakeFactory[player] = 0xA;
            D_80107FC0_1BE5B0_CakeFactory[player] &= ~1;
        }
        break;
    }
    if (D_80107F52_1BE542_CakeFactory[player] != 0) {
        D_80107F52_1BE542_CakeFactory[player]--;
    }
}

void func_8010633C_1BC92C_CakeFactory(s32 player) {
    D_80107E24_1BE414_CakeFactory[player] = 0;
    D_80108030_1BE620_CakeFactory[player] = 0;
    if (D_80107E10_1BE400_CakeFactory[player] == 1) {
        D_80107E24_1BE414_CakeFactory[player] = ContBtn[gPlayers[player].port];
        D_80108030_1BE620_CakeFactory[player] = ContBtnTrg[gPlayers[player].port];
    } else {
        func_80105DAC_1BC39C_CakeFactory(player);
    }
    if ((D_80108030_1BE620_CakeFactory[player] & 0x8000) && !(D_80107FC0_1BE5B0_CakeFactory[player] & 1) && D_80108058_1BE648_CakeFactory[player] == 1) {
        D_80107F78_1BE568_CakeFactory[player] = 1;
        D_80108058_1BE648_CakeFactory[player] = 3;
    }
    if (D_80107E24_1BE414_CakeFactory[player] & 0x8000) {
        D_80107FC0_1BE5B0_CakeFactory[player] |= 1;
    } else {
        D_80107FC0_1BE5B0_CakeFactory[player] &= ~1;
    }
}

/* NON_MATCHING: correct logic; retail recomputes lane * 4 for pans[] after PlaySound, GCC reuses a saved one (one instruction short). */
#ifdef NON_MATCHING
void func_801064A4_1BCA94_CakeFactory(omObjData* obj) {
    CFTable teams = D_80107C00_1BE1F0_CakeFactory;
    s32 rest[5] = { 30, 20, 15, 10, 5 };
    CFTable pans = D_80107C2C_1BE21C_CakeFactory;
    CFPlayer* w;
    CFTeam* team;
    s32 player;
    s32 lane;
    f32 frame;
    f32 end;
    s32 sfx;
    u16 mdl;

    w = obj->unk_50;
    player = w->player;
    lane = D_80107FB0_1BE5A0_CakeFactory[player];
    team = D_80107DB4_1BE3A4_CakeFactory[teams.v[lane]]->unk_50;
    if (D_80107DBC_1BE3AC_CakeFactory > 0) {
        func_8010633C_1BC92C_CakeFactory(player);
    } else {
        D_80107FC0_1BE5B0_CakeFactory[player] &= ~1;
    }
    frame = func_80029CE4_2A8E4(obj->model[0]);
    end = func_80029D0C_2A90C(obj->model[0]);
    func_80029E14_2AA14(obj->model[0]);
    switch (D_80108058_1BE648_CakeFactory[player]) {
    case 0:
        if (D_80107F78_1BE568_CakeFactory[player] != 0) {
            D_80107F78_1BE568_CakeFactory[player] = 0;
            func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[1]), 0, 0xF, 2);
            func_80029E80_2AA80(obj->model[0], 4, 0);
        }
        if (w->timer == 0) {
            D_80108058_1BE648_CakeFactory[player] = 1;
        }
        break;
    case 1:
        if (D_80107DBC_1BE3AC_CakeFactory <= 0) {
            D_80107F78_1BE568_CakeFactory[player] = 1;
            D_80108058_1BE648_CakeFactory[player] = 0xC;
        }
        break;
    case 3:
        func_80029E80_2AA80(obj->model[0], 6, 0);
        func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[3]), 0, 8, 0);
        func_80029E80_2AA80(obj->model[0], 6, 0);
        func_80029C74_2A874(obj->model[0], 0.0f);
        D_80107E50_1BE440_CakeFactory[lane].flags &= ~2;
        D_80108058_1BE648_CakeFactory[player] = 4;
        break;
    case 4:
        if (D_80107E50_1BE440_CakeFactory[lane].flags & 2) {
            if (D_80107E50_1BE440_CakeFactory[lane].flags2 & 0x20) {
                sfx = 0x222;
                if (D_80107DB0_1BE3A0_CakeFactory[lane] == 2) {
                    sfx = 0x221;
                }
                sfx = PlaySound(sfx);
                func_80015710_16310((s16)sfx, pans.v[lane]);
                D_80107DCC_1BE3BC_CakeFactory[lane] = mdl = D_80107E50_1BE440_CakeFactory[lane].mdl[D_80107E50_1BE440_CakeFactory[lane].next];
                func_800298A4_2A4A4(mdl, 4, 0);
                D_80107E50_1BE440_CakeFactory[lane].flags |= 4;
                D_80107E50_1BE440_CakeFactory[lane].state[D_80107E50_1BE440_CakeFactory[lane].next] = 3;
                D_80107E50_1BE440_CakeFactory[lane].flags |= 0x40;
                D_80107E50_1BE440_CakeFactory[lane].taken = D_80107E50_1BE440_CakeFactory[lane].cake;
                D_80107F52_1BE542_CakeFactory[player] = 0x78;
                D_80108058_1BE648_CakeFactory[player] = 7;
            } else {
                w->timer = 0x1E;
                D_80107F78_1BE568_CakeFactory[player] = 1;
                func_80029B80_2A780(obj->model[0], obj->motion[5]);
                D_80108058_1BE648_CakeFactory[player] = 5;
            }
        }
        if (frame == 24.0f) {
            D_80107E50_1BE440_CakeFactory[lane].flags |= 2;
        }
        break;
    case 5:
        if (frame == 8.0f) {
            func_80029E80_2AA80(obj->model[0], 1, 1);
            w->timer = rest[D_80108054_1BE644_CakeFactory - 1];
            D_80108058_1BE648_CakeFactory[player] = 6;
        }
        break;
    case 6:
        if (w->timer == 0) {
            func_80029E80_2AA80(obj->model[0], 1, 0);
        }
        if (frame == end) {
            w->timer = 4;
            D_80107F78_1BE568_CakeFactory[player] = 1;
            D_80108058_1BE648_CakeFactory[player] = 0;
        }
        break;
    case 7:
        if (frame == end) {
            D_80107E50_1BE440_CakeFactory[lane].flags &= ~0x40;
        }
        if (D_80107FC0_1BE5B0_CakeFactory[player] & 1) {
            D_80107F98_1BE588_CakeFactory[player] = 0;
        } else {
            D_80107F98_1BE588_CakeFactory[player]++;
        }
        if (D_80107F98_1BE588_CakeFactory[player] >= 3 && !(D_80107E50_1BE440_CakeFactory[lane].flags & 0x40) && team->state == 0) {
            team->req[0] |= D_80107DB0_1BE3A0_CakeFactory[lane];
            D_80108058_1BE648_CakeFactory[player] = 8;
        }
        break;
    case 8:
        if (!(D_80107DB0_1BE3A0_CakeFactory[lane] & team->req[0])) {
            D_80107E50_1BE440_CakeFactory[lane].flags &= ~0x40;
            D_80107F78_1BE568_CakeFactory[player] = 1;
            D_80108058_1BE648_CakeFactory[player] = 9;
        }
        break;
    case 9:
        if (D_80107F78_1BE568_CakeFactory[player] != 0) {
            D_80107F78_1BE568_CakeFactory[player] = 0;
            func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[4]), 0, 8, 0);
            func_80029E80_2AA80(obj->model[0], 6, 0);
            D_80107E50_1BE440_CakeFactory[lane].state[D_80107E50_1BE440_CakeFactory[lane].next] = 4;
            if (D_80107E50_1BE440_CakeFactory[lane].next < 2) {
                D_80107E50_1BE440_CakeFactory[lane].next++;
            } else {
                D_80107E50_1BE440_CakeFactory[lane].next = 0;
            }
            D_800FC834_FD434[obj->model[0]].unk44 = 2.0f;
        }
        if (frame == end) {
            w->timer = 4;
            D_800FC834_FD434[obj->model[0]].unk44 = 1.0f;
            D_80107FC0_1BE5B0_CakeFactory[player] &= ~1;
            D_80107F78_1BE568_CakeFactory[player] = 1;
            D_80108058_1BE648_CakeFactory[player] = 0;
        }
        break;
    case 10:
        if (frame == end) {
            w->timer = 4;
            D_80107FC0_1BE5B0_CakeFactory[player] &= ~1;
            D_80107F78_1BE568_CakeFactory[player] = 1;
            D_80108058_1BE648_CakeFactory[player] = 0;
        }
        break;
    case 12:
        if (D_80107F78_1BE568_CakeFactory[player] != 0) {
            D_80107F78_1BE568_CakeFactory[player] = 0;
            func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[0]), 0, 0xF, 2);
            w->timer = 0xF;
        }
        if (w->timer == 0) {
            D_80108058_1BE648_CakeFactory[player] = 0xD;
            D_80107F78_1BE568_CakeFactory[player] = 1;
        }
        break;
    case 13:
        if (D_80107F78_1BE568_CakeFactory[player] != 0) {
            D_80107F78_1BE568_CakeFactory[player] = 0;
            func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[0]), 0, 0xF, 2);
        }
        break;
    }
    if (team->result == 2 && ((team->count >= 2 && D_80107DB0_1BE3A0_CakeFactory[lane] == 2) || (team->count == 1 && D_80107DB0_1BE3A0_CakeFactory[lane] == 1))) {
        omVibrate(player, 2, 2, 0x14);
        team->result = 0;
    }
    if (w->timer > 0) {
        w->timer--;
    }
    if (w->unk_14 > 0.0f) {
        w->unk_14 -= 1.0f;
    }
}
#else
__asm__(".section .rodata");
const u32 D_80107D28_1BE318_CakeFactory[6] = { 0x0000001E, 0x00000014, 0x0000000F, 0x0000000A, 0x00000005, 0x00000000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1E_CakeFactory/1B8DF0", func_801064A4_1BCA94_CakeFactory);
#endif

void func_80106EE4_1BD4D4_CakeFactory(omObjData* obj) {
    u8 partner[4] = { 1, 0, 3, 2 };
    CFTable teams = D_80107C00_1BE1F0_CakeFactory;
    CFPlayer* w;
    f32 zero;
    s32 lane;
    s32 dir;
    s8 c;

    obj->unk_50 = func_80027154_27D54(sizeof(CFPlayer), 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, sizeof(CFPlayer));
    w = obj->unk_50;
    lane = D_80107FB0_1BE5A0_CakeFactory[D_80107BF8_1BE1E8_CakeFactory];
    D_80107BFC_1BE1EC_CakeFactory = lane;
    w->x = D_80107A84_1BE074_CakeFactory[lane].x;
    w->y = D_80107A84_1BE074_CakeFactory[lane].y;
    w->z = D_80107A84_1BE074_CakeFactory[lane].z;
    w->rotY = D_80107A84_1BE074_CakeFactory[lane].rotY;
    w->scale = D_80107A84_1BE074_CakeFactory[lane].scale;
    w->unk_14 = D_80107A84_1BE074_CakeFactory[D_80107BF8_1BE1E8_CakeFactory].unk_14;
    w->player = D_80107A84_1BE074_CakeFactory[D_80107BF8_1BE1E8_CakeFactory].player;
    w->state = D_80107A84_1BE074_CakeFactory[D_80107BF8_1BE1E8_CakeFactory].state;
    w->timer = 4;
    D_80107FC0_1BE5B0_CakeFactory[D_80107BF8_1BE1E8_CakeFactory] = 0;
    D_80108050_1BE640_CakeFactory[D_80107BF8_1BE1E8_CakeFactory] = 1;
    D_80107F52_1BE542_CakeFactory[D_80107BF8_1BE1E8_CakeFactory] = 0;
    c = gPlayers[D_80107BDC_1BE1CC_CakeFactory[D_80107BF8_1BE1E8_CakeFactory]].character;
    dir = D_800CD438_CE038[c].unk_04;
    D_80107D92_1BE382_CakeFactory[D_80107BF8_1BE1E8_CakeFactory] = obj->model[0] = LoadFormFile(dir | D_800CD438_CE038[c].unk_0C, 0x2D9);
    obj->model[1] = func_80018A64_19664(0xD, 0x2D9);
    obj->work[0] = 0;
    func_80018CCC_198CC(obj, 0, dir);
    func_80018CCC_198CC(obj, 1, dir | 0x5A);
    func_80018CCC_198CC(obj, 3, dir | 0x49);
    func_80018CCC_198CC(obj, 4, dir | 0x4A);
    func_80018CCC_198CC(obj, 5, dir | 0x6B);
    if (!(rand8() & 1)) {
        func_80018CCC_198CC(obj, 6, dir | 0x50);
        func_80018CCC_198CC(obj, 7, dir | 0x57);
    } else {
        func_80018CCC_198CC(obj, 6, dir | 0x50);
        func_80018CCC_198CC(obj, 7, dir | 0x59);
    }
    D_80107F60_1BE550_CakeFactory[D_80107BF8_1BE1E8_CakeFactory] = dir | 0x50;
    D_80108040_1BE630_CakeFactory[D_80107BF8_1BE1E8_CakeFactory] = obj->motion[3];
    obj->scale.x = w->scale;
    obj->scale.y = w->scale;
    obj->scale.z = w->scale;
    obj->trans.x = w->x;
    obj->trans.y = 0.0f;
    obj->trans.z = w->z;
    zero = 0.0f;
    obj->rot.z = zero;
    obj->rot.x = zero;
    obj->rot.y = w->rotY;
    func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_8002979C_2A39C(obj->model[0], obj->rot.x, obj->rot.y, obj->rot.z);
    func_800297E8_2A3E8(obj->model[1], obj->scale.x, obj->scale.y, obj->scale.z);
    func_80029714_2A314(obj->model[1], obj->trans.x, 1.0f, obj->trans.z);
    func_8002979C_2A39C(obj->model[1], obj->rot.x, obj->rot.y, obj->rot.z);
    func_80029B80_2A780(obj->model[0], obj->motion[0]);
    func_80029E80_2AA80(obj->model[0], 2, 2);
    D_80107BF8_1BE1E8_CakeFactory++;
    obj->func_ptr = func_801064A4_1BCA94_CakeFactory;
}

void func_801072F4_1BD8E4_CakeFactory(void) {
    s32 i;

    D_80107BF8_1BE1E8_CakeFactory = 0;
    D_800FC87A_FD47A = 0;
    for (i = 0; i < 4; i++) {
        D_80107EF0_1BE4E0_CakeFactory[i] = gPlayers[i].port;
        D_80108058_1BE648_CakeFactory[i] = D_80107A84_1BE074_CakeFactory[i].state;
        D_80107F78_1BE568_CakeFactory[i] = 1;
        D_800FFFD8_100BD8[i] = omAddObj(2, 2, 8, -1, func_80106EE4_1BD4D4_CakeFactory);
    }
}

/* Unused: func_80104544_1BAB34_CakeFactory's end flow on its own (no COM difficulty in the case numbers). */
void func_8010740C_1BD9FC_CakeFactory(omObjData* obj) {
    CFTable teams = D_80107C00_1BE1F0_CakeFactory;
    s16 win[2];
    CFTeam* a;
    CFTeam* b;
    s32 i;
    s32 p;
    s32 q;
    u8 tie;
    u8 waiting;

    win[0] = 6;
    win[1] = 7;
    switch (D_80108038_1BE628_CakeFactory) {
    case 2:
        D_80107FD4_1BE5C4_CakeFactory--;
        waiting = 0;
        for (i = 0; i < 4; i++) {
            if (D_80108058_1BE648_CakeFactory[i] != 0xD) {
                waiting = 1;
            }
        }
        if (!waiting) {
            D_80107FD4_1BE5C4_CakeFactory = 0;
            if (D_80107D90_1BE380_CakeFactory == 1) {
                D_80108038_1BE628_CakeFactory = 5;
            } else {
                D_80108038_1BE628_CakeFactory++;
            }
        } else if (D_80107FD4_1BE5C4_CakeFactory == 0) {
            for (i = 0; i < 4; i++) {
                D_80107F78_1BE568_CakeFactory[i] = 1;
                D_80108058_1BE648_CakeFactory[i] = 0xD;
            }
            D_80107FD4_1BE5C4_CakeFactory = 0;
            if (D_80107D90_1BE380_CakeFactory == 1) {
                D_80108038_1BE628_CakeFactory = 5;
            } else {
                D_80108038_1BE628_CakeFactory++;
            }
        }
        break;
    case 3:
        a = D_80107DB4_1BE3A4_CakeFactory[teams.v[0]]->unk_50;
        b = D_80107DB4_1BE3A4_CakeFactory[teams.v[2]]->unk_50;
        tie = 0;
        q = -1;
        p = -1;
        if (a->score > b->score) {
            D_80108050_1BE640_CakeFactory[D_80107E30_1BE420_CakeFactory[0]] = 0;
            D_80108050_1BE640_CakeFactory[D_80107E30_1BE420_CakeFactory[1]] = 0;
            p = D_80107E30_1BE420_CakeFactory[0];
            q = D_80107E30_1BE420_CakeFactory[1];
        } else if (a->score < b->score) {
            D_80108050_1BE640_CakeFactory[D_80107E30_1BE420_CakeFactory[2]] = 0;
            D_80108050_1BE640_CakeFactory[D_80107E30_1BE420_CakeFactory[3]] = 0;
            p = D_80107E30_1BE420_CakeFactory[2];
            q = D_80107E30_1BE420_CakeFactory[3];
        } else {
            tie = 1;
        }
        for (i = 0; i < 4; i++) {
            if (D_80108050_1BE640_CakeFactory[i] == 0) {
                gPlayers[i].coins_mg_bonus += 10;
                func_800732B0_73EB0(D_80107F60_1BE550_CakeFactory[i]);
            }
            D_800FFFD8_100BD8[i]->rot.y = 0.0f;
            func_80029B80_2A780(D_800FFFD8_100BD8[i]->model[0], D_800FFFD8_100BD8[i]->motion[win[D_80108050_1BE640_CakeFactory[i]]]);
        }
        if (tie) {
            func_800691FC_69DFC(0x13);
            PlayMusic(0x57);
            D_80107FD4_1BE5C4_CakeFactory = 0x78;
        } else {
            func_800691FC_69DFC(0x11, gPlayers[p].character, gPlayers[q].character);
            PlayMusic(0x52);
            D_80107FD4_1BE5C4_CakeFactory = 0x87;
        }
        D_80108038_1BE628_CakeFactory = 6;
        break;
    case 4:
        if (func_80069538_6A138() == 2) {
            D_80107FD4_1BE5C4_CakeFactory = 0x5A;
            D_80108038_1BE628_CakeFactory += 2;
        }
        break;
    case 5:
        a = D_80107DB4_1BE3A4_CakeFactory[teams.v[0]]->unk_50;
        b = D_80107DB4_1BE3A4_CakeFactory[teams.v[2]]->unk_50;
        if (a->score > b->score) {
            D_80108050_1BE640_CakeFactory[D_80107E30_1BE420_CakeFactory[0]] = 0;
            D_80108050_1BE640_CakeFactory[D_80107E30_1BE420_CakeFactory[1]] = 0;
        } else if (a->score < b->score) {
            D_80108050_1BE640_CakeFactory[D_80107E30_1BE420_CakeFactory[2]] = 0;
            D_80108050_1BE640_CakeFactory[D_80107E30_1BE420_CakeFactory[3]] = 0;
        }
        for (i = 0; i < 4; i++) {
            if (D_80108050_1BE640_CakeFactory[i] == 0) {
                gPlayers[i].coins_mg_bonus += 10;
            }
            D_800FFFD8_100BD8[i]->rot.y = 0.0f;
        }
        D_80107FD4_1BE5C4_CakeFactory = 0x3C;
        D_80108038_1BE628_CakeFactory++;
        break;
    case 6:
        if (--D_80107FD4_1BE5C4_CakeFactory < 0) {
            InitFadeOut(0, 0x14);
            D_80108038_1BE628_CakeFactory++;
        }
        break;
    case 7:
        if (func_8008F618_90218() == 0) {
            omOvlReturnEx(1);
        }
        break;
    }
    if (D_80107DC0_1BE3B0_CakeFactory != 0.0f) {
        D_80107DC0_1BE3B0_CakeFactory -= 1.0f;
    }
}
