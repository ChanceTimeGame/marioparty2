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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_39_BowsersBigBlast/27F4F0", func_80104D64_281A54_BowsersBigBlast);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_39_BowsersBigBlast/27F4F0", func_80104E98_281B88_BowsersBigBlast);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_39_BowsersBigBlast/27F4F0", func_80104F04_281BF4_BowsersBigBlast);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_39_BowsersBigBlast/27F4F0", func_80104F40_281C30_BowsersBigBlast);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_39_BowsersBigBlast/27F4F0", func_80104FE4_281CD4_BowsersBigBlast);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_39_BowsersBigBlast/27F4F0", func_8010500C_281CFC_BowsersBigBlast);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_39_BowsersBigBlast/27F4F0", func_80105248_281F38_BowsersBigBlast);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_39_BowsersBigBlast/27F4F0", func_801053E0_2820D0_BowsersBigBlast);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_39_BowsersBigBlast/27F4F0", func_80105470_282160_BowsersBigBlast);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_39_BowsersBigBlast/27F4F0", func_801054A0_282190_BowsersBigBlast);

__asm__(".section .rodata");
const u32 D_80107C30_284920_BowsersBigBlast[5] = { 0xC3070000, 0xC3160000, 0x43340000, 0x43160000, 0x43070000 };

__asm__(".section .rodata");
const u32 D_80107C44_284934_BowsersBigBlast[7] = { 0x40A00000, 0x40800000, 0x40A00000, 0x40800000, 0x00000000, 0x00000000, 0x00000000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_39_BowsersBigBlast/27F4F0", func_801056A8_282398_BowsersBigBlast);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_39_BowsersBigBlast/27F4F0", func_80105C50_282940_BowsersBigBlast);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_39_BowsersBigBlast/27F4F0", func_80106400_2830F0_BowsersBigBlast);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_39_BowsersBigBlast/27F4F0", func_801065CC_2832BC_BowsersBigBlast);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_39_BowsersBigBlast/27F4F0", func_801069C8_2836B8_BowsersBigBlast);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_39_BowsersBigBlast/27F4F0", func_80106A50_283740_BowsersBigBlast);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_39_BowsersBigBlast/27F4F0", func_80106D64_283A54_BowsersBigBlast);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_39_BowsersBigBlast/27F4F0", func_80106EC4_283BB4_BowsersBigBlast);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_39_BowsersBigBlast/27F4F0", func_80107104_283DF4_BowsersBigBlast);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_39_BowsersBigBlast/27F4F0", func_801071B0_283EA0_BowsersBigBlast);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_39_BowsersBigBlast/27F4F0", func_8010721C_283F0C_BowsersBigBlast);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_39_BowsersBigBlast/27F4F0", func_80107240_283F30_BowsersBigBlast);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_39_BowsersBigBlast/27F4F0", func_80107278_283F68_BowsersBigBlast);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_39_BowsersBigBlast/27F4F0", func_801072C0_283FB0_BowsersBigBlast);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_39_BowsersBigBlast/27F4F0", func_801073E4_2840D4_BowsersBigBlast);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_39_BowsersBigBlast/27F4F0", func_801074A8_284198_BowsersBigBlast);

__asm__(".section .rodata");
const char D_80107CF0_2849E0_BowsersBigBlast[] = "\202r\202s\202`\202q\202s";

__asm__(".section .rodata");
const char D_80107CFC_2849EC_BowsersBigBlast[] = "\202e\202h\202m\202h\202r\202g";

__asm__(".section .rodata");
const char D_80107D0C_2849FC_BowsersBigBlast[20] = "\202c\202q\202`\202v";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_39_BowsersBigBlast/27F4F0", func_80107840_284530_BowsersBigBlast);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_39_BowsersBigBlast/27F4F0", func_80107A08_2846F8_BowsersBigBlast);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_39_BowsersBigBlast/27F4F0", func_80107A80_284770_BowsersBigBlast);
