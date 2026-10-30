#include "ovl_39.h"

void func_80102800_27F4F0_BowsersBigBlast(void) {
    func_80107840_284530_BowsersBigBlast();
}

void func_8010281C_27F50C_BowsersBigBlast(void) {
}

void func_80102824_27F514_BowsersBigBlast(omObjData* obj, s32 file, f32 x, f32 y, f32 z, s32 attr, u8 load) {
    GroundWork* w;
    if (load != 0) {
        obj->model[0] = LoadFormFile(file | 0x490000, attr);
    }
    obj->trans.x = x;
    obj->trans.y = y;
    obj->trans.z = z;
    obj->work[0] = load;
    w = func_80027154_27D54(0xB4, 0x7918);
    obj->unk_50 = w;
    func_800B0EF0_B1AF0(w, 0, 0xB4);
    w->unk_03 = 1;
    w->unk_04 = D_80107AD1_2847C1_BowsersBigBlast++;
    func_8000BE8C_CA8C(obj, 0.1f);
    func_8000BE98_CA98(obj, 10.0f);
    obj->func_ptr = func_8010281C_27F50C_BowsersBigBlast;
}

void func_8010290C_27F5FC_BowsersBigBlast(omObjData* obj) {
    s32 attr = 0x99;
    func_80102824_27F514_BowsersBigBlast(obj, 0, 0.0f, 0.0f, 0.0f, attr, 0);
    func_8000BF24_CB24(obj, 0.0f, -2000.0f, -1000.0f, 1000.0f, 1000.0f);
}

void func_80102974_27F664_BowsersBigBlast(omObjData* obj) {
    s32 attr = 0xB9;
    func_80102824_27F514_BowsersBigBlast(obj, 0, 0.0f, 0.0f, 0.0f, attr, 1);
    obj->model[1] = LoadFormFile(0x490009, 0xA9);
    BB_MODEL(obj->model[1])->pos.x = 0.0f;
    BB_MODEL(obj->model[1])->pos.y = 10.0f;
    BB_MODEL(obj->model[1])->pos.z = 375.0f;
    func_8002D124_2DD24(obj->model[1]);
    func_8002D0A0_2DCA0(obj->model[1], 0x96);
    func_8000BF54_CB54(obj, 150.0f, 150.0f, -450.0f, -125.0f, 450.0f, 125.0f);
}


void func_80102AA8_27F798_BowsersBigBlast(omObjData* obj) {
    u8 files[4] = { 2, 3, 4, 5 };
    s32 attr = 0x99;
    func_80102824_27F514_BowsersBigBlast(obj, 0xA, 0.0f, 0.0f, 0.0f, attr, files[D_80107AFC_2847EC_BowsersBigBlast++]);
    func_8000BF54_CB54(obj, 0.0f, 150.0f, -100.0f, -100.0f, 100.0f, 100.0f);
    func_800298A4_2A4A4(obj->model[0], 4, 4);
}

void func_80102B74_27F864_BowsersBigBlast(void) {
    u8 i;
    func_8000C018_CC18(D_800F8FE0_F9BE0);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(0x64, 0, 0, -1, func_8010290C_27F5FC_BowsersBigBlast);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(0x64, 2, 0, -1, func_80102974_27F664_BowsersBigBlast);
    for (i = 0; i < 4; i++) {
        D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(0x64, 1, 0, -1, func_80102AA8_27F798_BowsersBigBlast);
    }
}

void func_80102C94_27F984_BowsersBigBlast(void) {
    u8 i;
    HmfModel* m;
    s32 attr = 0x99;
    for (i = 0; i < 3; i++) {
        D_80107D6B_284A5B_BowsersBigBlast[i] = LoadFormFile(0x10013, attr);
        func_800298A4_2A4A4(D_80107D6B_284A5B_BowsersBigBlast[i], 4, 4);
        m = BB_MODEL(D_80107D6B_284A5B_BowsersBigBlast[i]);
        m->unk40 = 0.0f;
        m->unk44 = 0.0f;
        if (m->hmf->unk9C != NULL) {
            m->hmf->unk9C->unk08 = 0.0f;
        }
    }
}

void func_80102D50_27FA40_BowsersBigBlast(void) {
    u8 i;
    HmfModel* m;
    HmfAnim* a;
    for (i = 0; i < 3; i++) {
        m = BB_MODEL(D_80107D6B_284A5B_BowsersBigBlast[i]);
        if (func_80029D0C_2A90C(D_80107D6B_284A5B_BowsersBigBlast[i]) <= m->unk40) {
            func_800298A4_2A4A4(D_80107D6B_284A5B_BowsersBigBlast[i], 4, 4);
            m->unk40 = 0.0f;
            m->unk44 = 0.0f;
            a = m->hmf->unk9C;
            if (a != NULL) {
                a->unk08 = 0.0f;
            }
        }
    }
}

void func_80102E10_27FB00_BowsersBigBlast(f32 x, f32 y, f32 z, u8 size) {
    u8 i;
    HmfModel* m;
    f32 s;
    for (i = 0; i < 3; i++) {
        m = BB_MODEL(D_80107D6B_284A5B_BowsersBigBlast[i]);
        if (m->unk18 & 4) {
            s = D_80107B00_2847F0_BowsersBigBlast[size];
            func_800298A4_2A4A4(D_80107D6B_284A5B_BowsersBigBlast[i], 4, 0);
            func_80029714_2A314(D_80107D6B_284A5B_BowsersBigBlast[i], x, y, z);
            func_800297E8_2A3E8(D_80107D6B_284A5B_BowsersBigBlast[i], s, s, s);
            m->unk44 = 1.0f;
            break;
        }
    }
}

void func_80102F34_27FC24_BowsersBigBlast(void) {
    u8 i;
    BBFlash* f;
    for (i = 0; i < 2; i++) {
        f = &D_80107D2C_284A1C_BowsersBigBlast[i];
        f->anim = func_8001A2F8_1AEF8(0x490010);
        f->group = SprCreate(1, 0);
        SprAnimSet(f->group, 0, f->anim, 0);
        SprAttrSet(f->group, 0, 0x9000);
        SprPosSet(f->group, 0, 0, 0);
        func_800824B4_830B4(f->group, 0, 0xFF, 0xFF, 0xFF, 0xFF);
        SprScaleSet(f->group, 0, 1.0f, 1.0f);
        func_8008221C_82E1C(f->group, 0, 1.0f);
        SprPrioSet(f->group, 0, 0xFFF0);
        func_8008225C_82E5C(f->group, 0, 2);
    }
}

void func_80103060_27FD50_BowsersBigBlast(void) {
    u8 i;
    BBFlash* f;
    for (i = 0; i < 2; i++) {
        f = &D_80107D2C_284A1C_BowsersBigBlast[i];
        if (f->active == 0) {
            SprAnimSet(f->group, 0, f->anim, 0);
            SprAttrReset(f->group, 0, 0x8000);
            SprPos3DSet(f->group, 0, 0, 0.0f, 400.0f, 0.0f);
            func_800824B4_830B4(f->group, 0, 0xFF, 0xFF, 0xFF, 0xFF);
            SprScaleSet(f->group, 0, 1.0f, 1.0f);
            SprBankSet(f->group, 0, 0);
            func_8008221C_82E1C(f->group, 0, 1.0f);
            f->active = 1;
            f->timer = 0xE;
        }
    }
}

void func_8010319C_27FE8C_BowsersBigBlast(void) {
    u8 i;
    BBFlash* f;
    for (i = 0; i < 2; i++) {
        f = &D_80107D2C_284A1C_BowsersBigBlast[i];
        if (--f->timer < 0) {
            f->active = 0;
            f->timer = 0;
            SprAttrSet(f->group, 0, 0x9000);
        }
    }
}


void func_80103214_27FF04_BowsersBigBlast(omObjData* obj) {
    f32 t;
    f32 a;
    s16 x;
    s16 y;
    switch (D_80107D20_284A10_BowsersBigBlast->bowser) {
    case 1:
        if (D_80107B19_284809_BowsersBigBlast == 0) {
            PlaySound(0x301);
            D_80107B19_284809_BowsersBigBlast = 1;
        }
        t = D_80107B18_284808_BowsersBigBlast / 15.0f;
        a = t * 90.0f;
        x = (HuMathSin(a) * 100.0f) + 50.0f;
        y = (HuMathSin(a) * -100.0f) + 400.0f;
        SprPos3DSet(D_80107D2C_284A1C_BowsersBigBlast[0].group, 0, 0, x, y, 0.0f);
        x = (HuMathSin(a) * -100.0f) + -50.0f;
        y = (HuMathSin(a) * -100.0f) + 400.0f;
        SprPos3DSet(D_80107D2C_284A1C_BowsersBigBlast[1].group, 0, 0, x, y, 0.0f);
        if (++D_80107B18_284808_BowsersBigBlast > 15.0f) {
            D_80107B19_284809_BowsersBigBlast = 0;
            D_80107B18_284808_BowsersBigBlast = 0;
            D_80107D20_284A10_BowsersBigBlast->bowser = 0;
        }
        break;
    case 2:
        func_8002BED4_2CAD4(obj->model[0], 0.0f, D_80107B10_284800_BowsersBigBlast, 0x20, 0x50, "kbom-eye", 0);
        if (D_80107B19_284809_BowsersBigBlast == 0) {
            PlaySound(0x306);
            D_80107B19_284809_BowsersBigBlast = 1;
        }
        if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
            D_80107B10_284800_BowsersBigBlast -= D_80107B14_284804_BowsersBigBlast;
        }
        if (D_80107B10_284800_BowsersBigBlast < -(D_80107B0C_2847FC_BowsersBigBlast * 16.0f) && D_80107B14_284804_BowsersBigBlast > 0.0f) {
            if (D_80107B0D_2847FD_BowsersBigBlast == 0) {
                D_80107B14_284804_BowsersBigBlast = -1.0f;
                D_80107B0D_2847FD_BowsersBigBlast++;
            } else if (D_80107B0D_2847FD_BowsersBigBlast == 1) {
                D_80107B14_284804_BowsersBigBlast = -0.7f;
                D_80107B0D_2847FD_BowsersBigBlast++;
                switch (D_80107B0C_2847FC_BowsersBigBlast) {
                case 1:
                    PlaySound(0x302);
                    break;
                case 2:
                    PlaySound(0x303);
                    break;
                case 3:
                    PlaySound(0x304);
                    break;
                case 4:
                    PlaySound(0x305);
                    break;
                }
            } else if (D_80107B0D_2847FD_BowsersBigBlast == 2) {
                D_80107B14_284804_BowsersBigBlast = -0.4f;
                D_80107B0C_2847FC_BowsersBigBlast++;
                D_80107B0D_2847FD_BowsersBigBlast = 0;
                D_80107B19_284809_BowsersBigBlast = 0;
            }
        }
        if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
            D_80107B14_284804_BowsersBigBlast += 0.3f;
        }
        if (D_80107B0C_2847FC_BowsersBigBlast == 5 && D_80107B14_284804_BowsersBigBlast > 0.0f) {
            D_80107B19_284809_BowsersBigBlast = 0;
            D_80107B10_284800_BowsersBigBlast = 0.0f;
            D_80107B14_284804_BowsersBigBlast = 0.0f;
            D_80107B0C_2847FC_BowsersBigBlast = 1;
            D_80107B0D_2847FD_BowsersBigBlast = 0;
            D_80107B18_284808_BowsersBigBlast = 0;
            D_80107D20_284A10_BowsersBigBlast->bowser = 3;
            D_80107D20_284A10_BowsersBigBlast->shake = 1;
            func_80102E10_27FB00_BowsersBigBlast(obj->trans.x, obj->trans.y, obj->trans.z, 2);
            PlaySound(0x307);
        }
        break;
    case 3:
        if (func_80078EA8_79AA8() + D_80102720_103320 == 0 && !(D_80107B18_284808_BowsersBigBlast % 6) && D_80107B18_284808_BowsersBigBlast < 10.5f) {
            omVibrate(D_80107D69_284A59_BowsersBigBlast, 0x14, 0, 0x14);
        }
        t = D_80107B18_284808_BowsersBigBlast / 21.0f;
        func_8002AC10_2B810(obj->model[0], 0.0f, (t * 0.2f * 20.0f * 5.0f) + 1.0f, 2);
        if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
            D_800CA02C_CAC2C += 20.0;
            if (D_800CA02C_CAC2C >= 360.0) {
                D_800CA02C_CAC2C -= 360.0;
            }
            if (++D_80107B18_284808_BowsersBigBlast > 21.0f) {
                func_800298A4_2A4A4(obj->model[0], 4, 4);
                D_80107D20_284A10_BowsersBigBlast->bowser = 4;
                D_80107B18_284808_BowsersBigBlast = 0;
            }
        }
        break;
    case 4:
        if (++D_80107B18_284808_BowsersBigBlast < 4) {
            func_8002AC10_2B810(obj->model[0], 0.0f, 1.0f, 0);
            func_8002BED4_2CAD4(obj->model[0], 0.0f, 0.0f, 0x20, 0x50, "kbom-eye", 0);
        } else {
            D_80107B18_284808_BowsersBigBlast = 0;
            obj->trans.y = 1150.0f;
            func_800298A4_2A4A4(obj->model[0], 4, 0);
            D_80107D20_284A10_BowsersBigBlast->bowser = 0;
        }
        break;
    }
    func_80102D50_27FA40_BowsersBigBlast();
    func_8010319C_27FE8C_BowsersBigBlast();
}

void func_80103A54_280744_BowsersBigBlast(omObjData* obj) {
    obj->model[0] = LoadFormFile(0x490001, 0x2A9);
    obj->model[1] = LoadFormFile(0x490001, 0x2B9);
    HmfModelObjAttrSet(obj->model[0], 0x20000, 0x20000);
    func_80029A8C_2A68C(obj->model[0]);
    func_8002A00C_2AC0C(obj->model[0]);
    func_800298A4_2A4A4(obj->model[1], 4, 4);
    obj->trans.x = 0.0f;
    obj->trans.y = 1150.0f;
    obj->trans.z = -270.0f;
    BB_MODEL(obj->model[1])->pos.x = 0.0f;
    BB_MODEL(obj->model[1])->pos.y = 450.0f;
    BB_MODEL(obj->model[1])->pos.z = -270.0f;
    func_80102F34_27FC24_BowsersBigBlast();
    obj->func_ptr = func_80103214_27FF04_BowsersBigBlast;
}

void func_80103B84_280874_BowsersBigBlast(void) {
    omSetStatBit(D_80107D28_284A18_BowsersBigBlast = omAddObj(0x320, 3, 0, -1, func_80103A54_280744_BowsersBigBlast), 0xA0);
}

void func_80103BCC_2808BC_BowsersBigBlast(omObjData* obj) {
    HmfModel* m;
    switch (D_80107D20_284A10_BowsersBigBlast->hatch) {
    case 1:
        if (D_80107B1A_28480A_BowsersBigBlast == 0) {
            PlaySound(0x2FC);
            D_80107B1A_28480A_BowsersBigBlast = 1;
        }
        D_80107D68_284A58_BowsersBigBlast = 0;
        func_800298A4_2A4A4(obj->model[0], 4, 0);
        if (func_80107A08_2846F8_BowsersBigBlast(&obj->trans.y, &D_80107B1C_28480C_BowsersBigBlast, 1680.0f, 980.0f, 30.0f)) {
            D_80107D20_284A10_BowsersBigBlast->hatch = 2;
        }
        if (func_80107A08_2846F8_BowsersBigBlast(&D_80107D28_284A18_BowsersBigBlast->trans.y, &D_80107B1D_28480D_BowsersBigBlast, 1150.0f, 450.0f, 30.0f)) {
            PlaySound(0x2FD);
            D_80107B1A_28480A_BowsersBigBlast = 0;
        }
        break;
    case 2:
        if (++D_80107B1C_28480C_BowsersBigBlast >= 6) {
            D_80107D20_284A10_BowsersBigBlast->hatch = 3;
            D_80107B1C_28480C_BowsersBigBlast = 0;
        }
        break;
    case 3:
        if (D_80107B1C_28480C_BowsersBigBlast != 0 && D_80107B1A_28480A_BowsersBigBlast == 0) {
            func_800796F0_7A2F0(PlaySound(0x2FE), 0);
            D_80107B1A_28480A_BowsersBigBlast = 1;
        }
        if (func_80107A08_2846F8_BowsersBigBlast(&obj->rot.y, &D_80107B1C_28480C_BowsersBigBlast, 0.0f, 720.0f, 30.0f)) {
            D_80107D20_284A10_BowsersBigBlast->hatch = 4;
        }
        if (func_80107A08_2846F8_BowsersBigBlast(&D_80107D28_284A18_BowsersBigBlast->rot.y, &D_80107B1D_28480D_BowsersBigBlast, 0.0f, 720.0f, 30.0f)) {
            D_80107B1A_28480A_BowsersBigBlast = 0;
            D_80107D20_284A10_BowsersBigBlast->hatch = 4;
            func_800298A4_2A4A4(D_80107D28_284A18_BowsersBigBlast->model[1], 4, 0);
            func_800298A4_2A4A4(D_80107D28_284A18_BowsersBigBlast->model[0], 4, 4);
        }
        break;
    case 4:
        BB_MODEL(obj->model[0])->unk44 = 1.0f;
        m = BB_MODEL(obj->model[0]);
        if (func_80029D0C_2A90C(obj->model[0]) <= m->unk40) {
            D_80107D20_284A10_BowsersBigBlast->hatch = 5;
        }
        break;
    case 5:
        if (D_80107B1A_28480A_BowsersBigBlast == 0) {
            PlaySound(0x2FC);
            D_80107B1A_28480A_BowsersBigBlast = 1;
        }
        if (func_80107A08_2846F8_BowsersBigBlast(&obj->trans.y, &D_80107B1C_28480C_BowsersBigBlast, 980.0f, 1680.0f, 30.0f)) {
            func_800298A4_2A4A4(obj->model[0], 4, 4);
            BB_MODEL(obj->model[0])->unk40 = 0.0f;
            BB_MODEL(obj->model[0])->unk44 = 0.0f;
            D_80107D20_284A10_BowsersBigBlast->hatch = 0;
            if (D_80107B1B_28480B_BowsersBigBlast != 0) {
                D_80107D20_284A10_BowsersBigBlast->music = 1;
                D_80107D20_284A10_BowsersBigBlast->camera = 1;
                D_80107B1B_28480B_BowsersBigBlast = 0;
            }
            D_80107B1A_28480A_BowsersBigBlast = 0;
        }
        break;
    }
}

void func_80103F9C_280C8C_BowsersBigBlast(omObjData* obj) {
    obj->model[0] = LoadFormFile(0x490002, 0x99);
    BB_MODEL(obj->model[0])->unk40 = 0.0f;
    BB_MODEL(obj->model[0])->unk44 = 0.0f;
    obj->trans.x = 0.0f;
    obj->trans.y = 980.0f;
    obj->trans.z = -270.0f;
    obj->func_ptr = func_80103BCC_2808BC_BowsersBigBlast;
}

void func_80104044_280D34_BowsersBigBlast(void) {
    omAddObj(0x320, 1, 0, -1, func_80103F9C_280C8C_BowsersBigBlast);
}




void func_80104078_280D68_BowsersBigBlast(omObjData* obj) {
    f32 speed[6] = { 5.0f, 5.0f, 8.0f, 8.0f, 5.0f, 3.0f };
    u8 extra[6] = { 2, 2, 1, 1, 1, 2 };
    u8 lids[5] = { 4, 0, 3, 1, 2 };
    u8 i;
    u16 frame;
    f32 t;
    switch (D_80107D20_284A10_BowsersBigBlast->press) {
    case 1:
        frame = (u8)(extra[D_80107D42_284A32_BowsersBigBlast] + func_800211C0_21DC0(D_80107D30_284A20_BowsersBigBlast[D_80107D41_284A31_BowsersBigBlast]));
        if (frame < 8) {
            if (D_80107B1E_28480E_BowsersBigBlast++ > (s32)(frame * (speed[D_80107D42_284A32_BowsersBigBlast] / 8.0f))) {
                func_80021198_21D98(D_80107D30_284A20_BowsersBigBlast[D_80107D41_284A31_BowsersBigBlast], frame);
            }
        } else {
            if (D_80107D64_284A54_BowsersBigBlast == 2 && D_80107D41_284A31_BowsersBigBlast == D_80107D3A_284A2A_BowsersBigBlast) {
                D_80107D20_284A10_BowsersBigBlast->music = 3;
            } else {
                D_80107D20_284A10_BowsersBigBlast->music = 2;
            }
            PlaySound(0x2FF);
            D_80107B1E_28480E_BowsersBigBlast = 0;
            D_80107D20_284A10_BowsersBigBlast->press = 0;
        }
        break;
    case 2:
        for (i = 0; i < 5; i++) {
            func_80021198_21D98(D_80107D30_284A20_BowsersBigBlast[i], 0);
        }
        D_80107D20_284A10_BowsersBigBlast->press = 3;
        break;
    case 3:
        if (D_80107B1F_28480F_BowsersBigBlast == 0) {
            PlaySound(0x300);
            D_80107B1F_28480F_BowsersBigBlast = 1;
        }
        t = D_80107B1E_28480E_BowsersBigBlast / 24.0f;
        obj->trans.y = (t * 148.0) + 0.0;
        for (i = 0; i < 5; i++) {
            if (D_80107D3B_284A2B_BowsersBigBlast[i] != 0) {
                BB_MODEL(D_800F86D8_F92D8[D_80107D30_284A20_BowsersBigBlast[i]].unk00)->pos.y = (t * 205.0) + 0.0;
            }
        }
        if (++D_80107B1E_28480E_BowsersBigBlast > 24.0f) {
            D_80107B1E_28480E_BowsersBigBlast = 0;
            obj->trans.y = 148.0f;
            for (i = 0; i < 5; i++) {
                if (D_80107D3B_284A2B_BowsersBigBlast[i] != 0) {
                    D_80107D40_284A30_BowsersBigBlast++;
                    BB_MODEL(D_800F86D8_F92D8[D_80107D30_284A20_BowsersBigBlast[i]].unk00)->pos.y = 205.0f;
                }
            }
            D_80107D20_284A10_BowsersBigBlast->press = 0;
            D_80107D3A_284A2A_BowsersBigBlast = ((rand8() << 8) | rand8()) % 5;
            while (D_80107D3B_284A2B_BowsersBigBlast[D_80107D3A_284A2A_BowsersBigBlast] == 0) {
                D_80107D3A_284A2A_BowsersBigBlast = ((rand8() << 8) | rand8()) % 5;
            }
            func_80104F40_281C30_BowsersBigBlast();
            D_80107D66_284A56_BowsersBigBlast = 1;
            D_80107D68_284A58_BowsersBigBlast += 0x14;
            D_80107B1F_28480F_BowsersBigBlast = 0;
        }
        break;
    case 4:
        if (++D_80107B1E_28480E_BowsersBigBlast >= 0xB) {
            D_80107B1E_28480E_BowsersBigBlast = 0;
            D_80107D20_284A10_BowsersBigBlast->press = 5;
        }
        break;
    case 5:
        if (D_80107B1F_28480F_BowsersBigBlast == 0) {
            PlaySound(0x300);
            D_80107B1F_28480F_BowsersBigBlast = 1;
        }
        t = D_80107B1E_28480E_BowsersBigBlast / 24.0f;
        obj->trans.y = (t * -152.0) + 148.0;
        for (i = 0; i < 5; i++) {
            BB_MODEL(D_800F86D8_F92D8[D_80107D30_284A20_BowsersBigBlast[i]].unk00)->pos.y = (t * -95.0) + 205.0;
        }
        if (++D_80107B1E_28480E_BowsersBigBlast > 24.0f) {
            D_80107B1E_28480E_BowsersBigBlast = 0;
            obj->trans.y = 0.0f;
            if (D_80107D64_284A54_BowsersBigBlast != 0) {
                for (i = 0; i < D_80107D64_284A54_BowsersBigBlast; i++) {
                    func_800298A4_2A4A4(D_800F86D8_F92D8[D_80107D30_284A20_BowsersBigBlast[lids[i]]].unk00, 4, 4);
                    D_80107D20_284A10_BowsersBigBlast->fade = 1;
                    D_80107AEA_2847DA_BowsersBigBlast = lids[i];
                }
            }
            for (i = 0; i < 5; i++) {
                D_80107D3B_284A2B_BowsersBigBlast[i] = 0;
                BB_MODEL(D_800F86D8_F92D8[D_80107D30_284A20_BowsersBigBlast[i]].unk00)->pos.y = 0.0f;
                if (!(BB_MODEL(D_800F86D8_F92D8[D_80107D30_284A20_BowsersBigBlast[i]].unk00)->unk18 & 4)) {
                    D_80107D3B_284A2B_BowsersBigBlast[i] = 1;
                }
            }
            D_80107D20_284A10_BowsersBigBlast->press = 2;
            D_80107D40_284A30_BowsersBigBlast = 0;
            D_80107B1F_28480F_BowsersBigBlast = 0;
        }
        break;
    }
}


void func_801048C4_2815B4_BowsersBigBlast(omObjData* obj) {
    u8 i = 0;
    s32 attr = 0x299;
    u8 files[5] = { 0xF, 0xE, 0xD, 0xC, 0xB };
    u8 s;
    obj->model[0] = LoadFormFile(0x490003, attr);
    for (; i < 5; i++) {
        D_80107D30_284A20_BowsersBigBlast[i] = func_80018D64_19964(files[i] | 0x490000, attr, 8);
        s = D_80107D30_284A20_BowsersBigBlast[i];
        func_80029714_2A314(D_800F86D8_F92D8[s].unk00, D_80107AD4_2847C4_BowsersBigBlast[i], 0.0f, 125.0f);
        func_800297E8_2A3E8(D_800F86D8_F92D8[s].unk00, 4.0f, 3.5f, 1.0f);
        func_80021160_21D60(s, 1, 1);
        D_800F86D8_F92D8[s].unk06 = 0;
        D_80107D3B_284A2B_BowsersBigBlast[i] = 1;
    }
    obj->trans.x = 0.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 125.0f;
    obj->func_ptr = func_80104078_280D68_BowsersBigBlast;
}

void func_80104A5C_28174C_BowsersBigBlast(omObjData* obj) {
    if (D_80107D20_284A10_BowsersBigBlast->fade == 1) {
        func_8002D0A0_2DCA0(obj->model[4 - D_80107AEA_2847DA_BowsersBigBlast], D_80107B20_284810_BowsersBigBlast);
        D_80107B20_284810_BowsersBigBlast -= 0xA;
        if (D_80107B20_284810_BowsersBigBlast < 0xB) {
            D_80107D20_284A10_BowsersBigBlast->fade = 0;
            D_80107B20_284810_BowsersBigBlast = 0xFF;
            func_800298A4_2A4A4(obj->model[4 - D_80107AEA_2847DA_BowsersBigBlast], 4, 4);
        }
    }
}




void func_80104B28_281818_BowsersBigBlast(omObjData* obj) {
    u8 i = 0;
    s32 attr = 0x289;
    u8 files[5] = { 4, 5, 6, 7, 8 };
    f32 xs[5] = { -150.0f, -70.0f, 0.0f, 70.0f, 150.0f };
    f32 ys[5] = { 160.0f, 150.0f, 150.0f, 150.0f, 160.0f };
    for (; i < 5; i++) {
        obj->model[i] = LoadFormFile(files[i] | 0x490000, attr);
        func_8002D124_2DD24(obj->model[i]);
        func_8002D0A0_2DCA0(obj->model[i], 0xFF);
        BB_MODEL(obj->model[i])->pos.x = xs[i];
        BB_MODEL(obj->model[i])->pos.y = ys[i];
        BB_MODEL(obj->model[i])->pos.z = -80.0f;
    }
    obj->trans.x = xs[0];
    obj->trans.y = ys[0];
    obj->trans.z = -80.0f;
    obj->func_ptr = func_80104A5C_28174C_BowsersBigBlast;
}

void func_80104D10_281A00_BowsersBigBlast(void) {
    omAddObj(0xC8, 6, 0, -1, func_801048C4_2815B4_BowsersBigBlast);
    omAddObj(0xC8, 5, 0, -1, func_80104B28_281818_BowsersBigBlast);
}

void func_80104D64_281A54_BowsersBigBlast(omObjData* obj) {
    u8 pick;
    pick = D_80107D3A_284A2A_BowsersBigBlast;
    if ((u8)(((rand8() << 8) | rand8()) % 101) >= (u8)(obj->work[3]) + D_80107D68_284A58_BowsersBigBlast) {
        while (pick == D_80107D3A_284A2A_BowsersBigBlast || D_80107D3B_284A2B_BowsersBigBlast[pick] == 0) {
            pick = ((rand8() << 8) | rand8()) % 5;
        }
    }
    D_80107B24_284814_BowsersBigBlast[obj->work[0]] = pick;
}

void func_80104E98_281B88_BowsersBigBlast(omObjData* obj, BBPlayer* pl, u8 port) {
    if (pl->slot != D_80107B24_284814_BowsersBigBlast[obj->work[0]]) {
        if (pl->slot > D_80107B24_284814_BowsersBigBlast[obj->work[0]]) {
            ContStkX[port] = 0x46;
        } else {
            ContStkX[port] = -0x46;
        }
    } else {
        ContBtnTrg[port] = 0x8000;
    }
}

void func_80104F04_281BF4_BowsersBigBlast(u8 port) {
    ContStkX[port] = 0;
    ContStkY[port] = 0;
    ContBtn[port] = 0;
    ContBtnTrg[port] = 0;
}

void func_80104F40_281C30_BowsersBigBlast(void) {
    u8 i;
    u8 k;
    D_80107AE8_2847D8_BowsersBigBlast = 4;
    D_80107AE9_2847D9_BowsersBigBlast = 0;
    for (i = 0; i < 5; i++) {
        k = i;
        if (*(&D_80107D3F_284A2F_BowsersBigBlast - k) != 0 && 4 - k < D_80107AE8_2847D8_BowsersBigBlast) {
            D_80107AE8_2847D8_BowsersBigBlast = 4 - i;
        }
        if (D_80107D3B_284A2B_BowsersBigBlast[i] != 0 && i > D_80107AE9_2847D9_BowsersBigBlast) {
            D_80107AE9_2847D9_BowsersBigBlast = i;
        }
    }
}

u8 func_80104FE4_281CD4_BowsersBigBlast(BBPlayer* pl, s32 step) {
    u8 slot = pl->slot;
    do {
        slot = step + slot;
    } while (D_80107D3B_284A2B_BowsersBigBlast[slot] == 0);
    return slot;
}

void func_8010500C_281CFC_BowsersBigBlast(omObjData* obj, BBPlayer* pl, u8 port, f32 z) {
    if (pl->pressed != 0) {
        func_80104F04_281BF4_BowsersBigBlast(port);
    }
    if (gPlayers[obj->work[0]].flags & 1) {
        func_80104E98_281B88_BowsersBigBlast(obj, pl, port);
    }
    if (D_80107D20_284A10_BowsersBigBlast->timer < 0.0f) {
        ContBtnTrg[port] = 0x8000;
    }
    if (ContBtnTrg[port] & 0x8000) {
        pl->pressed = 1;
    }
    if (ContStkX[port] > 0 && pl->slot > D_80107AE8_2847D8_BowsersBigBlast) {
        pl->slot = func_80104FE4_281CD4_BowsersBigBlast(pl, -1);
        ((MgWork*)obj->unk_50)->unk_3C = 90.0f;
        pl->state = 2;
        ContStkX[port] = 0x3C;
        ContStkY[port] = 0;
    } else if (ContStkX[port] < 0 && pl->slot < D_80107AE9_2847D9_BowsersBigBlast) {
        pl->slot = func_80104FE4_281CD4_BowsersBigBlast(pl, 1);
        ((MgWork*)obj->unk_50)->unk_3C = -90.0f;
        pl->state = 3;
        ContStkX[port] = -0x3C;
        ContStkY[port] = 0;
    } else {
        func_80104F04_281BF4_BowsersBigBlast(port);
        obj->trans.x = D_80107AD4_2847C4_BowsersBigBlast[pl->slot];
        obj->trans.z = z + 5.0f;
        if (((MgWork*)obj->unk_50)->unk_3C != 0.0f) {
            pl->angle = ((MgWork*)obj->unk_50)->unk_3C;
            pl->state = 4;
        } else if (pl->pressed != 0) {
            pl->state = 7;
        }
    }
}

void func_80105248_281F38_BowsersBigBlast(omObjData* obj) {
    omObjData* lid = D_800FC7B0_FD3B0[obj->work[1]];
    if (obj->trans.z > 200.0f && obj->trans.z < 350.0f) {
        lid->trans.x = obj->trans.x;
        lid->trans.z = obj->trans.z;
        lid->trans.y = ((350.0f - obj->trans.z) / 150.0f) * 1.5f * 20.0f * 5.0f;
        func_8002979C_2A39C(obj->model[1], 45.0f, 0.0f, 0.0f);
        func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y + 10.0f, obj->trans.z);
    } else {
        if (obj->trans.z < 200.0f) {
            lid->trans.x = obj->trans.x;
            lid->trans.z = 200.0f;
            lid->trans.y = 150.0f;
        } else if (obj->trans.z > 350.0f) {
            lid->trans.x = obj->trans.x;
            lid->trans.z = 350.0f;
            lid->trans.y = 0.0f;
        }
        func_8002979C_2A39C(obj->model[1], 0.0f, 0.0f, 0.0f);
    }
}

void func_801053E0_2820D0_BowsersBigBlast(omObjData* obj) {
    BBPlayer* pl = &D_80107D48_284A38_BowsersBigBlast[obj->work[0]];
    u8 i = 0;
    if (pl->order == 0) {
        for (; i < 4; i++) {
            D_80107D48_284A38_BowsersBigBlast[i].order--;
        }
        if (pl->hit == 0) {
            pl->order = 3 - D_80107D64_284A54_BowsersBigBlast;
        }
        D_80107D4C_284A3C_BowsersBigBlast = 0;
    }
}

void func_80105470_282160_BowsersBigBlast(omObjData* obj) {
    D_80107D50_284A40_BowsersBigBlast[0] = 0.0f;
    D_80107D50_284A40_BowsersBigBlast[1] = obj->trans.x;
    D_80107D50_284A40_BowsersBigBlast[2] = obj->trans.y;
    D_80107D50_284A40_BowsersBigBlast[3] = obj->trans.z;
    D_80107D50_284A40_BowsersBigBlast[4] = obj->rot.x;
}

s32 func_801054A0_282190_BowsersBigBlast(omObjData* obj) {
    f32 t;
    f32 s;
    f32 ten;
    f32 top = D_80107D50_284A40_BowsersBigBlast[2] + 1400.0f;
    MgWork* w;
    if (D_80107D50_284A40_BowsersBigBlast[0] == 0.0f) {
        func_800797DC_7A3DC(0x111, obj->work[0]);
    }
    t = D_80107D50_284A40_BowsersBigBlast[0] / 45.0f;
    s = obj->work[2];
    ten = 10.0f;
    obj->work[2]--;
    s /= ten;
    if (obj->work[2] == 0) {
        func_800298A4_2A4A4(obj->model[1], 4, 4);
    }
    func_80029714_2A314(obj->model[1], obj->trans.x, 150.0f, obj->trans.z);
    func_800297E8_2A3E8(obj->model[1], s, 1.0f, s);
    func_80019B9C_1A79C(obj, 0x29);
    obj->trans.y = func_80107A80_284770_BowsersBigBlast(t, D_80107D50_284A40_BowsersBigBlast[2], top, D_80107D50_284A40_BowsersBigBlast[2]);
    obj->trans.z = ((2400.0f - D_80107D50_284A40_BowsersBigBlast[3]) * t) + D_80107D50_284A40_BowsersBigBlast[3];
    obj->rot.x = ((180.0f - D_80107D50_284A40_BowsersBigBlast[4]) * t) + D_80107D50_284A40_BowsersBigBlast[4];
    ((MgWork*)obj->unk_50)->unk_3C += 45.0f;
    w = obj->unk_50;
    if (w->unk_3C > 360.0f) {
        w->unk_3C -= 360.0f;
    }
    if ((D_80107D50_284A40_BowsersBigBlast[0] += 1.0f) > 45.0f) {
        return 1;
    }
    return 0;
}



void func_801056A8_282398_BowsersBigBlast(omObjData* obj, BBPlayer* pl) {
    f32 angles[5] = { -135.0f, -150.0f, 180.0f, 150.0f, 135.0f };
    f32 frames[6] = { 5.0f, 4.0f, 5.0f, 4.0f, 0.0f, 0.0f };
    MgWork* w;
    HmfModel* m;
    D_80107B29_284819_BowsersBigBlast++;
    switch (D_80107B28_284818_BowsersBigBlast) {
    case 0:
        func_80019B9C_1A79C(obj, 0x27);
        func_8006D518_6E118();
        D_80107D20_284A10_BowsersBigBlast->flow = 3;
        D_80107D20_284A10_BowsersBigBlast->timer = 300.0f;
        D_80107AD0_2847C0_BowsersBigBlast = 0;
        D_80107D41_284A31_BowsersBigBlast = pl->slot;
        D_80107D3B_284A2B_BowsersBigBlast[pl->slot] = 0;
        D_80107D40_284A30_BowsersBigBlast--;
        D_80107B28_284818_BowsersBigBlast = 1;
        D_80107D42_284A32_BowsersBigBlast = gPlayers[obj->work[0]].character;
        D_80107D69_284A59_BowsersBigBlast = obj->work[0];
        D_80107B29_284819_BowsersBigBlast = 0;
        break;
    case 1:
        if (BB_MODEL(obj->model[0])->unk40 > frames[D_80107D42_284A32_BowsersBigBlast]) {
            D_80107D20_284A10_BowsersBigBlast->press = 1;
            D_80107B28_284818_BowsersBigBlast = 2;
        }
        break;
    case 2:
        m = BB_MODEL(obj->model[0]);
        if (m->unk40 >= 16.0f) {
            m->unk44 = -1.0f;
            D_80107B28_284818_BowsersBigBlast = 3;
        }
        break;
    case 3:
        m = BB_MODEL(obj->model[0]);
        if (m->unk40 < 1.0f) {
            m->unk44 = 1.0f;
            D_80107B28_284818_BowsersBigBlast = 4;
            D_80107B29_284819_BowsersBigBlast = 0x15;
        }
        break;
    case 4:
        if (D_80107B29_284819_BowsersBigBlast > 21.0f) {
            func_80019B9C_1A79C(obj, 0x26);
            if (gPlayers[obj->work[0]].character == 5) {
                if (obj->trans.z < 0.0f) {
                    w = obj->unk_50;
                    ContStkY[w->unk_57] = 0x46;
                } else {
                    obj->trans.z = 0.0f;
                }
            }
            w = obj->unk_50;
            if (func_80107A08_2846F8_BowsersBigBlast(&w->unk_3C, &D_80107B2A_28481A_BowsersBigBlast, 0.0f, angles[pl->slot], 10.0f)) {
                func_80019B9C_1A79C(obj, 0);
                D_80107B28_284818_BowsersBigBlast = 5;
            }
        }
        break;
    case 5:
        if (D_80107B29_284819_BowsersBigBlast > 51.0f) {
            if (pl->slot != D_80107D3A_284A2A_BowsersBigBlast) {
                D_80107D20_284A10_BowsersBigBlast->music = 4;
                func_80103060_27FD50_BowsersBigBlast();
                D_80107D20_284A10_BowsersBigBlast->bowser = 1;
            } else {
                pl->hit = 1;
                func_800298A4_2A4A4(D_80107D28_284A18_BowsersBigBlast->model[0], 4, 0);
                func_800298A4_2A4A4(D_80107D28_284A18_BowsersBigBlast->model[1], 4, 4);
                D_80107D20_284A10_BowsersBigBlast->bowser = 2;
            }
            D_80107B28_284818_BowsersBigBlast = 7;
        }
        break;
    case 7:
        if (D_80107B29_284819_BowsersBigBlast > 60.0f) {
            if (pl->hit != 0) {
                func_80019B9C_1A79C(obj, 0x2B);
                D_80107D64_284A54_BowsersBigBlast++;
                D_80107B28_284818_BowsersBigBlast = 8;
                D_80107B29_284819_BowsersBigBlast = 0;
            } else {
                D_80107B28_284818_BowsersBigBlast = 6;
            }
        }
        break;
    case 6:
        func_80104F40_281C30_BowsersBigBlast();
        pl->state = 6;
        D_80107B28_284818_BowsersBigBlast = 0;
        if (D_80107D40_284A30_BowsersBigBlast == 1) {
            D_80107D20_284A10_BowsersBigBlast->press = 4;
        }
        break;
    case 8:
        if (D_80107B29_284819_BowsersBigBlast == 0xA) {
            func_80079718_7A318(0xFC, D_80107D42_284A32_BowsersBigBlast);
        }
        if (D_80107D20_284A10_BowsersBigBlast->bowser == 3) {
            if (D_80107D64_284A54_BowsersBigBlast == 3) {
                D_80107D20_284A10_BowsersBigBlast->flow = 4;
            }
            pl->state = 8;
            func_80105470_282160_BowsersBigBlast(obj);
            D_80107B28_284818_BowsersBigBlast = 0;
        }
        break;
    }
}

void func_80105C50_282940_BowsersBigBlast(omObjData* obj, u8 order, u8 port) {
    f32 z = 0.0f;
    BBPlayer* pl = &D_80107D48_284A38_BowsersBigBlast[obj->work[0]];
    if (gPlayers[obj->work[0]].character == 5) {
        z = 30.0f;
    }
    switch (pl->state) {
    case 5:
        func_80104F04_281BF4_BowsersBigBlast(port);
        if (obj->trans.z > z + 5.0f) {
            ContStkY[port] = 0x46;
            obj->trans.x = D_80107AEC_2847DC_BowsersBigBlast[order];
        } else {
            obj->trans.z = z + 5.0f;
            if (obj->trans.x > D_80107AD4_2847C4_BowsersBigBlast[D_80107AE8_2847D8_BowsersBigBlast]) {
                ContStkX[port] = -0x46;
            } else {
                obj->trans.x = D_80107AD4_2847C4_BowsersBigBlast[D_80107AE8_2847D8_BowsersBigBlast];
                pl->slot = D_80107AE8_2847D8_BowsersBigBlast;
                pl->state = 1;
                pl->angle = ((MgWork*)obj->unk_50)->unk_3C;
                pl->state = 4;
                if (gPlayers[obj->work[0]].flags & 1) {
                    func_80104D64_281A54_BowsersBigBlast(obj);
                }
            }
        }
        break;
    case 6:
        func_80104F04_281BF4_BowsersBigBlast(port);
        if (obj->trans.x > -360.0f) {
            ContStkX[port] = -0x46;
        } else {
            obj->trans.x = -360.0f;
            if (obj->trans.z < 400.0f) {
                ContStkY[port] = -0x46;
                func_801053E0_2820D0_BowsersBigBlast(obj);
            } else {
                obj->trans.z = 400.0f;
                pl->pressed = 0;
                pl->state = 0;
            }
        }
        break;
    case 1:
        if (D_80107D67_284A57_BowsersBigBlast == 0) {
            func_80104F04_281BF4_BowsersBigBlast(port);
        } else {
            func_8010500C_281CFC_BowsersBigBlast(obj, pl, port, z);
        }
        break;
    case 2:
        ContBtnTrg[port] = 0;
        ContBtn[port] = 0;
        ContStkY[port] = 0;
        if (obj->trans.x < D_80107AD4_2847C4_BowsersBigBlast[pl->slot]) {
            ContStkX[port] = 0x3C;
        } else {
            pl->state = 1;
            func_8010500C_281CFC_BowsersBigBlast(obj, pl, port, z);
        }
        break;
    case 3:
        ContBtnTrg[port] = 0;
        ContBtn[port] = 0;
        ContStkY[port] = 0;
        if (obj->trans.x > D_80107AD4_2847C4_BowsersBigBlast[pl->slot]) {
            ContStkX[port] = -0x3C;
        } else {
            pl->state = 1;
            func_8010500C_281CFC_BowsersBigBlast(obj, pl, port, z);
        }
        break;
    case 4:
        func_80104F04_281BF4_BowsersBigBlast(port);
        obj->trans.x = D_80107AD4_2847C4_BowsersBigBlast[pl->slot];
        obj->trans.z = z + 5.0f;
        if (func_80107A08_2846F8_BowsersBigBlast(&((MgWork*)obj->unk_50)->unk_3C, &D_80107B2B_28481B_BowsersBigBlast, pl->angle, 0.0f, 7.0f)) {
            ((MgWork*)obj->unk_50)->unk_40 = 0.0f;
            if (pl->pressed != 0) {
                pl->state = 7;
            } else {
                pl->state = 1;
            }
            if (D_80107D20_284A10_BowsersBigBlast->timer == -1.0f) {
                D_80107D20_284A10_BowsersBigBlast->flow = 1;
                D_80107D20_284A10_BowsersBigBlast->control = 3;
            }
            if (D_80107AD0_2847C0_BowsersBigBlast == 0) {
                func_800691FC_69DFC(0xA, 0xA0, 0x1C);
                D_80107D20_284A10_BowsersBigBlast->flow = 2;
                D_80107AD0_2847C0_BowsersBigBlast = 1;
            }
        }
        break;
    case 7:
        func_80104F04_281BF4_BowsersBigBlast(port);
        func_801056A8_282398_BowsersBigBlast(obj, pl);
        break;
    case 8:
        if (func_801054A0_282190_BowsersBigBlast(obj)) {
            func_800298A4_2A4A4(obj->model[0], 4, 4);
            gPlayers[obj->work[0]].coins_mg_bonus = D_80107D6A_284A5A_BowsersBigBlast--;
            pl->state = 0xA;
            func_801053E0_2820D0_BowsersBigBlast(obj);
            if (D_80107D64_284A54_BowsersBigBlast < 3) {
                D_80107D20_284A10_BowsersBigBlast->press = 5;
                D_80107D20_284A10_BowsersBigBlast->hatch = 1;
                D_80107D20_284A10_BowsersBigBlast->music = 5;
                D_80107D66_284A56_BowsersBigBlast = 0;
            }
        }
        break;
    case 9:
        if (D_80107B2B_28481B_BowsersBigBlast == 0) {
            D_80107D65_284A55_BowsersBigBlast = obj->work[0];
            func_80019B9C_1A79C(obj, 0xD);
            func_800732B0_73EB0(D_800CD438_CE038[gPlayers[obj->work[0]].character].unk_04 | 0x4E);
            D_80107D20_284A10_BowsersBigBlast->flow = 5;
            pl->angle = ((MgWork*)obj->unk_50)->unk_3C;
        }
        if (func_80107A08_2846F8_BowsersBigBlast(&((MgWork*)obj->unk_50)->unk_3C, &D_80107B2B_28481B_BowsersBigBlast, pl->angle, 0.0f, D_80107D24_284A14_BowsersBigBlast[1].time)) {
            D_80107D20_284A10_BowsersBigBlast->control = 0;
        }
        break;
    case 0:
        func_80104F04_281BF4_BowsersBigBlast(port);
        if (D_80107D66_284A56_BowsersBigBlast != 0) {
            if (order == 0) {
                if (D_80107D64_284A54_BowsersBigBlast < 3) {
                    if (D_80107D4C_284A3C_BowsersBigBlast != 0) {
                        pl->state = 5;
                    }
                    if (obj->trans.x < D_80107AEC_2847DC_BowsersBigBlast[order]) {
                        ContStkX[port] = 0x46;
                    } else {
                        obj->trans.x = D_80107AEC_2847DC_BowsersBigBlast[order];
                        D_80107D4C_284A3C_BowsersBigBlast = 1;
                    }
                } else {
                    pl->state = 9;
                }
            } else if (obj->trans.x < D_80107AEC_2847DC_BowsersBigBlast[order]) {
                ContStkX[port] = 0x46;
            } else {
                obj->trans.x = D_80107AEC_2847DC_BowsersBigBlast[order];
                ((MgWork*)obj->unk_50)->unk_40 -= 0.5f;
            }
            obj->trans.z = 400.0f;
        }
        break;
    }
}

void func_80106400_2830F0_BowsersBigBlast(omObjData* obj) {
    u8 order = D_80107D48_284A38_BowsersBigBlast[obj->work[0]].order;
    u8 port = ((MgWork*)obj->unk_50)->unk_57;
    switch (D_80107D20_284A10_BowsersBigBlast->control) {
    case 1:
        func_80104F04_281BF4_BowsersBigBlast(port);
        if (obj->trans.x < D_80107AEC_2847DC_BowsersBigBlast[order]) {
            ContStkX[port] = 0x46;
        } else {
            obj->trans.x = D_80107AEC_2847DC_BowsersBigBlast[order];
            if (order == 3) {
                D_80107D20_284A10_BowsersBigBlast->control = 2;
            }
        }
        break;
    case 2:
        func_80105C50_282940_BowsersBigBlast(obj, order, port);
        break;
    case 3:
        func_80104F04_281BF4_BowsersBigBlast(port);
        if (func_80069538_6A138() == 2) {
            D_80107D20_284A10_BowsersBigBlast->control = 2;
            func_800691FC_69DFC(0xA, 0xA0, 0x1C);
            D_80107D20_284A10_BowsersBigBlast->flow = 2;
        }
        break;
    case 0:
        func_80104F04_281BF4_BowsersBigBlast(port);
        break;
    }
    func_80007790_8390(obj);
    func_80019378_19F78(obj);
    func_80105248_281F38_BowsersBigBlast(obj);
}

void func_801065CC_2832BC_BowsersBigBlast(omObjData* obj) {
    u8 ids[4] = { 2, 3, 4, 5 };
    u32 dir;
    s32 file;
    BBPlayer* pl;
    MgWork* w;
    u8 i;
    dir = D_800CD438_CE038[gPlayers[D_800FC87A_FD47A].character].unk_04;
    file = D_800CD438_CE038[gPlayers[D_800FC87A_FD47A].character].unk_08;
    func_8000C6FC_D2FC(obj, dir, file, D_800FC87A_FD47A, 0x699, 0x699);
    func_80019E84_1AA84(obj, 0, dir, 1, 0);
    func_80019E84_1AA84(obj, 1, dir | 1, 1, 0);
    func_80019E84_1AA84(obj, 2, dir | 2, 1, 0);
    func_80019E84_1AA84(obj, 0xD, dir | 0x4E, 1, 0x3E7);
    func_80019E84_1AA84(obj, 0x29, dir | 0x25, 1, 0);
    func_80019E84_1AA84(obj, 0x26, dir | 1, 1, 0);
    func_80019E84_1AA84(obj, 0x27, dir | 0x15, 0, 0x63);
    func_80019E84_1AA84(obj, 0x28, dir | 0x40, 1, 0x64);
    func_80019E84_1AA84(obj, 0x2A, dir | 0x51, 0, 0x63);
    func_80019E84_1AA84(obj, 0x2B, dir | 0xC8, 1, 0x3E7);
    pl = &D_80107D48_284A38_BowsersBigBlast[D_800FC87A_FD47A];
    pl->state = 0;
    pl->order = D_80107D43_284A33_BowsersBigBlast[D_800FC87A_FD47A];
    obj->trans.x = D_80107AEC_2847DC_BowsersBigBlast[pl->order] - 1000.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 400.0f;
    w = obj->unk_50;
    w->unk_50 = 0x200;
    w->unk_3C = 0.0f;
    obj->work[0] = D_800FC87A_FD47A;
    obj->work[1] = ids[D_800FC87A_FD47A];
    obj->work[2] = 0xA;
    switch (gPlayers[D_800FC87A_FD47A].cpu_difficulty) {
    case 0:
        obj->work[3] = 0x28;
        break;
    case 1:
        obj->work[3] = 0x1E;
        break;
    case 2:
        obj->work[3] = 0x14;
        break;
    case 3:
        obj->work[3] = 0xA;
        break;
    }
    func_8000BEB0_CAB0(obj, 30.0f);
    func_80029714_2A314(obj->model[1], obj->trans.x, 1.0f, obj->trans.z);
    D_800FC87A_FD47A++;
    D_800F8FD0_F9BD0 = 1;
    ContStkX[w->unk_57] = 0;
    ContStkY[w->unk_57] = 0;
    ContBtn[w->unk_57] = 0;
    ContBtnTrg[w->unk_57] = 0;
    func_80007790_8390(obj);
    if (D_800F8FE0_F9BE0 != 0) {
        for (i = 0; i < D_800F8FE0_F9BE0; i++) {
            func_8000C024_CC24(obj, i, 2);
        }
    }
    for (i = 0; i < 4; i++) {
        if (obj->work[1] != ids[i]) {
            func_8000C024_CC24(obj, ids[i], 1);
        }
    }
    obj->func_ptr = func_80106400_2830F0_BowsersBigBlast;
}

void func_801069C8_2836B8_BowsersBigBlast(void) {
    u8 i;
    func_8000C460_D060();
    func_8000C578_D178(1);
    for (i = 0; i < 4; i++) {
        D_800FFFD8_100BD8[i] = omAddObj(0x1F4, 9, 0x2C, -1, func_801065CC_2832BC_BowsersBigBlast);
    }
}

void func_80106A50_283740_BowsersBigBlast(void) {
    u8 rnd[4];
    u8 i;
    u8 j;
    s8 place;
    D_80107D20_284A10_BowsersBigBlast = func_80027154_27D54(0x10, 0x7918);
    D_80107D20_284A10_BowsersBigBlast->timer = -1.0f;
    D_80107D20_284A10_BowsersBigBlast->shake = 0;
    D_80107D20_284A10_BowsersBigBlast->flow = 0;
    D_80107D20_284A10_BowsersBigBlast->music = 0;
    D_80107D20_284A10_BowsersBigBlast->camera = 0;
    D_80107D20_284A10_BowsersBigBlast->bowser = 0;
    D_80107D20_284A10_BowsersBigBlast->press = 0;
    D_80107D20_284A10_BowsersBigBlast->fade = 0;
    D_80107D20_284A10_BowsersBigBlast->hatch = 1;
    D_80107D20_284A10_BowsersBigBlast->control = 0;
    D_80107D2C_284A1C_BowsersBigBlast = func_80027154_27D54(8, 0x7918);
    func_800B0EF0_B1AF0(D_80107D2C_284A1C_BowsersBigBlast, 0, 8);
    D_80107D24_284A14_BowsersBigBlast = func_80027154_27D54(0x60, 0x7918);
    func_800B0EF0_B1AF0(D_80107D24_284A14_BowsersBigBlast, 0, 0x60);
    D_80107D48_284A38_BowsersBigBlast = func_80027154_27D54(0x30, 0x7918);
    func_800B0EF0_B1AF0(D_80107D48_284A38_BowsersBigBlast, 0, 0x30);
    D_80107D4C_284A3C_BowsersBigBlast = 0;
    D_80107D64_284A54_BowsersBigBlast = 0;
    D_80107D66_284A56_BowsersBigBlast = 1;
    D_80107D67_284A57_BowsersBigBlast = 0;
    D_80107D6A_284A5A_BowsersBigBlast = 3;
    D_80107D69_284A59_BowsersBigBlast = 0;
    for (i = 0; i < 4; i++) {
        rnd[i] = ((rand8() << 8) | rand8()) % 256;
        for (j = 0; j < 4;) {
            if (i != j && rnd[i] == rnd[j]) {
                rnd[i] = ((rand8() << 8) | rand8()) % 256;
                j = 0;
            } else {
                j++;
            }
        }
    }
    place = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (i != j) {
                if (func_80059FD0_5ABD0(i) > func_80059FD0_5ABD0(j)) {
                    place++;
                } else if (func_80059FD0_5ABD0(i) == func_80059FD0_5ABD0(j) && rnd[i] < rnd[j]) {
                    place++;
                }
            }
        }
        D_80107D43_284A33_BowsersBigBlast[i] = place;
        place = 0;
    }
}

void func_80106D64_283A54_BowsersBigBlast(void) {
    s32 sound;
    switch (D_80107D20_284A10_BowsersBigBlast->music) {
    case 1:
        func_800794F0_7A0F0(0x7F);
        PlayMusic(0x20);
        D_80107D20_284A10_BowsersBigBlast->music = 0;
        break;
    case 2:
        sound = 0x61;
        if (D_80107D41_284A31_BowsersBigBlast != D_80107D3A_284A2A_BowsersBigBlast) {
            sound = 0x5F;
        }
        D_80107B2C_28481C_BowsersBigBlast = func_80079428_7A028(sound);
        D_80107D20_284A10_BowsersBigBlast->music = 0;
        break;
    case 3:
        func_80079464_7A064();
        func_800794F0_7A0F0(0);
        D_80107D20_284A10_BowsersBigBlast->music = 0;
        break;
    case 4:
        if (++D_80107B30_284820_BowsersBigBlast < 0x15) {
            break;
        }
    case 5:
        D_80107B30_284820_BowsersBigBlast = 0;
        break;
    case 6:
        func_800794F0_7A0F0((D_80107B30_284820_BowsersBigBlast / 15.0f) * 127.0f);
        if (++D_80107B30_284820_BowsersBigBlast >= 0x10) {
            D_80107B30_284820_BowsersBigBlast = 0;
            D_80107D20_284A10_BowsersBigBlast->music = 0;
        }
        break;
    }
}

void func_80106EC4_283BB4_BowsersBigBlast(void) {
    switch (D_80107D20_284A10_BowsersBigBlast->flow) {
    case 1:
        if (D_80107D20_284A10_BowsersBigBlast->timer == -1.0f) {
            func_800691FC_69DFC(0);
            D_80107D20_284A10_BowsersBigBlast->timer = 300.0f;
        }
        break;
    case 2:
        D_80107D20_284A10_BowsersBigBlast->timer -= 1.0f;
        func_8006D4D0_6E0D0((D_80107D20_284A10_BowsersBigBlast->timer + 29.0f) / 30.0f);
        if (++D_80107B31_284821_BowsersBigBlast >= 0x10) {
            D_80107D67_284A57_BowsersBigBlast = 1;
        }
        break;
    case 3:
        D_80107D67_284A57_BowsersBigBlast = 0;
        D_80107B31_284821_BowsersBigBlast = 0;
        break;
    case 4:
        func_800691FC_69DFC(3);
        D_80107B31_284821_BowsersBigBlast = 0;
        D_80107D20_284A10_BowsersBigBlast->flow = 0;
        break;
    case 5:
        D_80107B31_284821_BowsersBigBlast++;
        if (D_80107B31_284821_BowsersBigBlast == 1) {
            PlayMusic(0x51);
        } else if (D_80107B31_284821_BowsersBigBlast != 0x14) {
            if (D_80107B31_284821_BowsersBigBlast == D_80107D24_284A14_BowsersBigBlast[1].time + 90.0f) {
                InitFadeOut(0, 0x14);
            } else if (func_8008F618_90218() == 0 && D_80107B31_284821_BowsersBigBlast > D_80107D24_284A14_BowsersBigBlast[1].time + 90.0f) {
                omOvlReturnEx(1);
            }
        }
        break;
    }
    func_80106D64_283A54_BowsersBigBlast();
    func_801074A8_284198_BowsersBigBlast();
}

void func_80107104_283DF4_BowsersBigBlast(void) {
    if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        if (D_80107B32_284822_BowsersBigBlast == 1) {
            func_800116B4_122B4(D_80107B2C_28481C_BowsersBigBlast, 0);
            D_80107B32_284822_BowsersBigBlast = 0;
        }
    } else if (D_80107B2C_28481C_BowsersBigBlast >= 0 && D_80107B32_284822_BowsersBigBlast == 0) {
        func_800115B4_121B4(D_80107B2C_28481C_BowsersBigBlast);
        D_80107B32_284822_BowsersBigBlast = 1;
        osSyncPrintf("CRESS STOP > %d \n", D_80107B2C_28481C_BowsersBigBlast);
    }
}

void func_801071B0_283EA0_BowsersBigBlast(omObjData* obj) {
    func_80106A50_283740_BowsersBigBlast();
    func_80102B74_27F864_BowsersBigBlast();
    func_80102C94_27F984_BowsersBigBlast();
    func_80103B84_280874_BowsersBigBlast();
    func_80104044_280D34_BowsersBigBlast();
    func_80104D10_281A00_BowsersBigBlast();
    func_801069C8_2836B8_BowsersBigBlast();
    InitFadeIn(0, 0x10);
    obj->func_ptr = func_80106EC4_283BB4_BowsersBigBlast;
}

void func_8010721C_283F0C_BowsersBigBlast(omObjData* obj) {
    osViBlack(0);
    omOvlReturnEx(1);
}

void func_80107240_283F30_BowsersBigBlast(omObjData* obj) {
    if (func_8008F618_90218() == 0) {
        obj->func_ptr = func_8010721C_283F0C_BowsersBigBlast;
    }
}

void func_80107278_283F68_BowsersBigBlast(omObjData* obj) {
    if (D_801011FC_101DFC == 1) {
        InitFadeOut(0, 0x14);
        obj->func_ptr = func_80107240_283F30_BowsersBigBlast;
    }
}

void func_801072C0_283FB0_BowsersBigBlast(void) {
    D_80107D24_284A14_BowsersBigBlast[0].time = 30.0f;
    D_80107D24_284A14_BowsersBigBlast[0].zoom = 1445.0f;
    D_80107D24_284A14_BowsersBigBlast[0].cx = 0.0f;
    D_80107D24_284A14_BowsersBigBlast[0].cy = 540.0f;
    D_80107D24_284A14_BowsersBigBlast[0].cz = -10.0f;
    D_80107D24_284A14_BowsersBigBlast[0].rx = 350.0f;
    D_80107D24_284A14_BowsersBigBlast[0].ry = 0.0f;
    D_80107D24_284A14_BowsersBigBlast[0].rz = 0.0f;
    D_80107D24_284A14_BowsersBigBlast[1].time = 30.0f;
    D_80107D24_284A14_BowsersBigBlast[1].zoom = 2460.0f;
    D_80107D24_284A14_BowsersBigBlast[1].cx = 0.0f;
    D_80107D24_284A14_BowsersBigBlast[1].cy = 207.0f;
    D_80107D24_284A14_BowsersBigBlast[1].cz = -270.0f;
    D_80107D24_284A14_BowsersBigBlast[1].rx = 346.0f;
    D_80107D24_284A14_BowsersBigBlast[1].ry = 0.0f;
    D_80107D24_284A14_BowsersBigBlast[1].rz = 0.0f;
    D_80107D24_284A14_BowsersBigBlast[2].time = 30.0f;
    D_80107D24_284A14_BowsersBigBlast[2].zoom = 1300.0f;
    D_80107D24_284A14_BowsersBigBlast[2].cx = 197.0f;
    D_80107D24_284A14_BowsersBigBlast[2].cy = -100.0f;
    D_80107D24_284A14_BowsersBigBlast[2].cz = -220.0f;
    D_80107D24_284A14_BowsersBigBlast[2].rx = 341.0f;
    D_80107D24_284A14_BowsersBigBlast[2].ry = 0.0f;
    D_80107D24_284A14_BowsersBigBlast[2].rz = 0.0f;
}

void func_801073E4_2840D4_BowsersBigBlast(BBCamKey* key, f32 t) {
    D_800F94A8_FA0A8[0] = (key[1].zoom - key[0].zoom) * t + key[0].zoom;
    D_801013B0_101FB0[0].x = (key[1].cx - key[0].cx) * t + key[0].cx;
    D_801013B0_101FB0[0].y = (key[1].cy - key[0].cy) * t + key[0].cy;
    D_801013B0_101FB0[0].z = (key[1].cz - key[0].cz) * t + key[0].cz;
    D_80102770_103370[0].x = (key[1].rx - key[0].rx) * t + key[0].rx;
    D_80102770_103370[0].y = (key[1].ry - key[0].ry) * t + key[0].ry;
    D_80102770_103370[0].z = (key[1].rz - key[0].rz) * t + key[0].rz;
}

void func_801074A8_284198_BowsersBigBlast(void) {
    if (D_80102770_103370[0].x > 360.0f) {
        D_80102770_103370[0].x -= 360.0f;
    } else if (D_80102770_103370[0].x < 0.0f) {
        D_80102770_103370[0].x += 360.0f;
    }
    if (D_80102774_103374[0].x > 360.0f) {
        D_80102774_103374[0].x -= 360.0f;
    } else if (D_80102774_103374[0].x < 0.0f) {
        D_80102774_103374[0].x += 360.0f;
    }
    switch (D_80107D20_284A10_BowsersBigBlast->camera) {
    case 0:
        func_801072C0_283FB0_BowsersBigBlast();
        D_800F94A8_FA0A8[0] = D_80107D24_284A14_BowsersBigBlast[0].zoom;
        D_801013B0_101FB0[0].x = D_80107D24_284A14_BowsersBigBlast[0].cx;
        D_801013B0_101FB0[0].y = D_80107D24_284A14_BowsersBigBlast[0].cy;
        D_801013B0_101FB0[0].z = D_80107D24_284A14_BowsersBigBlast[0].cz;
        D_80102770_103370[0].x = D_80107D24_284A14_BowsersBigBlast[0].rx;
        D_80102770_103370[0].y = D_80107D24_284A14_BowsersBigBlast[0].ry;
        D_80102770_103370[0].z = D_80107D24_284A14_BowsersBigBlast[0].rz;
        D_80107D20_284A10_BowsersBigBlast->camera = 4;
        break;
    case 1:
        D_80107B40_284830_BowsersBigBlast = D_80107B44_284834_BowsersBigBlast / D_80107D24_284A14_BowsersBigBlast[0].time;
        func_801073E4_2840D4_BowsersBigBlast(&D_80107D24_284A14_BowsersBigBlast[0], HuMathSin(D_80107B40_284830_BowsersBigBlast * 90.0f));
        if (D_80107D24_284A14_BowsersBigBlast[0].time <= (D_80107B44_284834_BowsersBigBlast += 1.0f)) {
            D_80107B40_284830_BowsersBigBlast = 0.0f;
            D_80107B44_284834_BowsersBigBlast = 0.0f;
            D_80107D20_284A10_BowsersBigBlast->camera = 2;
            D_80107D20_284A10_BowsersBigBlast->control = 1;
            D_80107D20_284A10_BowsersBigBlast->press = 2;
        }
        break;
    case 3:
        D_80107B40_284830_BowsersBigBlast = D_80107B44_284834_BowsersBigBlast / D_80107D24_284A14_BowsersBigBlast[1].time;
        func_801073E4_2840D4_BowsersBigBlast(&D_80107D24_284A14_BowsersBigBlast[1], HuMathSin(D_80107B40_284830_BowsersBigBlast * 90.0f));
        if (D_80107D24_284A14_BowsersBigBlast[1].time <= (D_80107B44_284834_BowsersBigBlast += 1.0f)) {
            D_80107B40_284830_BowsersBigBlast = 0.0f;
            D_80107B44_284834_BowsersBigBlast = 0.0f;
            D_80107D20_284A10_BowsersBigBlast->camera = 4;
        }
        break;
    case 2:
        if (D_80107D20_284A10_BowsersBigBlast->shake != 0) {
            if (D_80107B44_284834_BowsersBigBlast < 10.0f) {
                D_801013B4_101FB4[0].x = D_80107B34_284824_BowsersBigBlast[(s32)D_80107B44_284834_BowsersBigBlast++] + 207.0f;
            } else {
                D_80107B44_284834_BowsersBigBlast = 0.0f;
                D_80107D20_284A10_BowsersBigBlast->shake = 0;
            }
        } else {
            D_801013B4_101FB4[0].x = 207.0f;
        }
        break;
    }
}




void func_80107840_284530_BowsersBigBlast(void) {
    omObjData* obj;
    func_8002D4D0_2E0D0(0x32);
    func_80020D20_21920(0x20);
    omInitObjMan(0x32, 0);
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
    D_800FA606_FB206 = 0;
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    omAddObj(0x3E8, 0, 0, -1, func_801071B0_283EA0_BowsersBigBlast);
    omAddObj(0x3E8, 0, 0, -1, func_80107278_283F68_BowsersBigBlast);
    func_8007273C_7333C("\202r\202s\202`\202q\202s", 1);
    func_8007273C_7333C("\202e\202h\202m\202h\202r\202g", 1);
    func_8007273C_7333C("\202c\202q\202`\202v", 1);
}

u8 func_80107A08_2846F8_BowsersBigBlast(f32* out, u8* timer, f32 start, f32 end, f32 duration) {
    *out = start + (end - start) * (*timer / duration);
    if (++*timer > duration) {
        *timer = 0;
        *out = end;
        return 1;
    }
    return 0;
}

f32 func_80107A80_284770_BowsersBigBlast(f32 t, f32 p0, f32 p1, f32 p2) {
    f32 u = 1.0f - t;
    return u * u * p0 + 2.0f * u * t * p1 + u * u * p2;
}
