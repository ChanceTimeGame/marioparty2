#include "ovl_30.h"
#include "game/malloc.h"
#include "game/data.h"

void func_80109140_23F020_SlotCarDerby(s16 state) {
    s32 i;

    D_8010FB00_2459E0_SlotCarDerby = state;
    if (state == 3) {
        for (i = 0; i < 4; i++) {
            func_8010DAD8_2439B8_SlotCarDerby(i, -1.0f);
        }
    } else if (D_8010FB00_2459E0_SlotCarDerby == 6) {
        func_8010D590_243470_SlotCarDerby();
        HuMemMemoryFreePerm(D_80110968_246848_SlotCarDerby);
        HuMemMemoryFreePerm(D_8011096C_24684C_SlotCarDerby);
        HuMemMemoryFreePerm(D_80110978_246858_SlotCarDerby);
    }
}

s32 func_801091DC_23F0BC_SlotCarDerby(u8 player, s16 crossed) {
    if (crossed != 0 && D_8010FB04_2459E4_SlotCarDerby == 0) {
        D_8010FB04_2459E4_SlotCarDerby = 1;
    }
    if (D_8010FB10_2459F0_SlotCarDerby < D_8010FB14_2459F4_SlotCarDerby && D_801109D4_2468B4_SlotCarDerby != 0) {
        D_8010FB18_2459F8_SlotCarDerby = 1;
    }
    return D_8010FB18_2459F8_SlotCarDerby;
}

void func_80109240_23F120_SlotCarDerby(s16 course) {
    s32 i;
    SCDObj* o;

    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(10, 5, 8, -1, func_80109468_23F348_SlotCarDerby);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(11, 4, 0, -1, func_801096D4_23F5B4_SlotCarDerby);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(12, 0, 0, -1, func_80109EC0_23FDA0_SlotCarDerby);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(13, 0, 0, -1, func_80109CDC_23FBBC_SlotCarDerby);
    D_80110968_246848_SlotCarDerby = HuMemMemoryAllocPerm(16 * sizeof(SCDObj));
    for (i = 0; i < 16; i++) {
        o = &D_80110968_246848_SlotCarDerby[i];
        o->unk_00 = 0;
        o->unk_02 = 0;
        o->unk_08 = 0;
        o->unk_0C = 0;
        o->unk_10.x = o->unk_10.y = o->unk_10.z = 0.0f;
        o->unk_1C.x = o->unk_1C.y = o->unk_1C.z = 0.0f;
        o->unk_28.x = o->unk_28.y = o->unk_28.z = 0.0f;
        o->unk_40[0] = o->unk_40[1] = o->unk_40[2] = o->unk_40[3] = 0;
        o->unk_40[4] = o->unk_40[5] = o->unk_40[6] = o->unk_40[7] = 0;
        o->unk_40[8] = o->unk_40[9] = o->unk_40[10] = o->unk_40[11] = 0;
        o->unk_40[12] = o->unk_40[13] = o->unk_40[14] = o->unk_40[15] = 0;
    }
    func_8010B4D0_2413B0_SlotCarDerby(53);
    func_8010D0B0_242F90_SlotCarDerby();
    D_8010FB0C_2459EC_SlotCarDerby = course;
    D_801109D0_2468B0_SlotCarDerby = 0;
    if (D_801109D6_2468B6_SlotCarDerby == 2) {
        D_8010FB1C_2459FC_SlotCarDerby = 1;
    }
}

void func_80109468_23F348_SlotCarDerby(omObjData* obj) {
    SCDPlayerWork* w;

    obj->func_ptr = func_8010A190_240070_SlotCarDerby;
    omSetStatBit(obj, 0xA0);
    if (D_8010FB1C_2459FC_SlotCarDerby == 0) {
        obj->model[0] = LoadFormFile(0x80000, 0x499);
        obj->model[1] = func_80018A30_19630(0x40000C, 0x489);
    } else {
        obj->model[0] = LoadFormFile(0x80000, 0x49D);
        obj->model[1] = func_80018A30_19630(0x40000C, 0x48D);
    }
    obj->model[2] = func_80018A30_19630(0x40000D, 0x49D);
    obj->model[3] = func_80018A30_19630(0x40000E, 0x49D);
    func_8002A00C_2AC0C(obj->model[1]);
    func_80029E80_2AA80(obj->model[1], 2, 2);
    obj->unk_50 = func_80027154_27D54(sizeof(SCDPlayerWork), 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, sizeof(SCDPlayerWork));
    w = SCD_WORK(obj);
    w->unk_E8 = func_80027154_27D54(obj->mtncnt * sizeof(SCDPlayerWork), 0x7918);
    func_800B0EF0_B1AF0(w->unk_E8, 0, obj->mtncnt * sizeof(SCDPlayerWork));
    w->unk_D0 = 0xFFFF;
    func_80019E84_1AA84(obj, 0, 0x80001, 1, 0);
    func_80019E84_1AA84(obj, 1, 0x80004, 1, 0);
    obj->trans.x = D_8010FB20_245A00_SlotCarDerby[D_8010FB0C_2459EC_SlotCarDerby].x * 10.0;
    obj->trans.y = D_8010FB20_245A00_SlotCarDerby[D_8010FB0C_2459EC_SlotCarDerby].y * 10.0;
    obj->trans.z = D_8010FB20_245A00_SlotCarDerby[D_8010FB0C_2459EC_SlotCarDerby].z * 10.0;
    obj->scale.x = obj->scale.y = obj->scale.z = 2.0f;
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800297E8_2A3E8(obj->model[1], obj->scale.x, obj->scale.y, obj->scale.z);
    func_8010B098_240F78_SlotCarDerby(obj, D_80110968_246848_SlotCarDerby);
}

void func_801096D4_23F5B4_SlotCarDerby(omObjData* obj) {
    SCDObj* rec;
    void* data;
    s32 digit;
    s32 colon;
    s32 t;
    s32 n;
    s32 i;

    obj->func_ptr = func_8010A55C_24043C_SlotCarDerby;
    rec = &D_80110968_246848_SlotCarDerby[1];
    func_8010B098_240F78_SlotCarDerby(obj, rec);
    t = func_800680D4_68CD4((s16)D_8010FBA0_245A80_SlotCarDerby[D_8010FB0C_2459EC_SlotCarDerby]);
    D_8010FB14_2459F4_SlotCarDerby = t;
    D_8010FB84_245A64_SlotCarDerby[4] = (t % 3) * 3;
    n = t / 3;
    D_8010FB84_245A64_SlotCarDerby[3] = n % 10;
    n /= 10;
    D_8010FB84_245A64_SlotCarDerby[2] = n % 10;
    n /= 10;
    D_8010FB84_245A64_SlotCarDerby[1] = n % 6;
    n /= 6;
    if (n >= 9) {
        D_8010FB84_245A64_SlotCarDerby[0] = 9;
    } else {
        D_8010FB84_245A64_SlotCarDerby[0] = n;
    }
    D_80110970_246850_SlotCarDerby = SprCreate(7, 5);
    data = DataRead(0x43);
    digit = SprAnimRead(data);
    DataClose(data);
    D_80110974_246854_SlotCarDerby = SprCreate(7, 5);
    data = DataRead(0x45);
    colon = SprAnimRead(data);
    DataClose(data);
    SprPosSet((s16)D_80110974_246854_SlotCarDerby, 0, 131, 28);
    SprAnimSet((s16)D_80110974_246854_SlotCarDerby, 0, colon, 0);
    func_8008225C_82E5C((s16)D_80110974_246854_SlotCarDerby, 0, 0);
    SprBankSet((s16)D_80110974_246854_SlotCarDerby, 0, (s16)D_8010FB84_245A64_SlotCarDerby[0]);
    SprAttrSet((s16)D_80110974_246854_SlotCarDerby, 0, 0x1000);
    SprPosSet((s16)D_80110970_246850_SlotCarDerby, 0, 131, 44);
    SprAnimSet((s16)D_80110970_246850_SlotCarDerby, 0, digit, 0);
    func_8008225C_82E5C((s16)D_80110970_246850_SlotCarDerby, 0, 0);
    SprAttrSet((s16)D_80110970_246850_SlotCarDerby, 0, 0x1000);
    for (i = 1; i < 7; i++) {
        SprAnimSet((s16)D_80110970_246850_SlotCarDerby, i, digit, 0);
        func_8008225C_82E5C((s16)D_80110970_246850_SlotCarDerby, i, 0);
        SprPosSet((s16)D_80110970_246850_SlotCarDerby, i, (s16)D_8010FB68_245A48_SlotCarDerby[i], 0);
        func_800824F4_830F4((s16)D_80110970_246850_SlotCarDerby, i, 0);
        SprAttrSet((s16)D_80110970_246850_SlotCarDerby, i, 0x1000);
        SprAnimSet((s16)D_80110974_246854_SlotCarDerby, i, colon, 0);
        SprPosSet((s16)D_80110974_246854_SlotCarDerby, i, (s16)D_8010FB68_245A48_SlotCarDerby[i], 0);
        func_800824F4_830F4((s16)D_80110974_246854_SlotCarDerby, i, 0);
        SprBankSet((s16)D_80110974_246854_SlotCarDerby, i, (s16)D_8010FB84_245A64_SlotCarDerby[i]);
        func_8008225C_82E5C((s16)D_80110974_246854_SlotCarDerby, i, 0);
        SprAttrSet((s16)D_80110974_246854_SlotCarDerby, i, 0x1000);
    }
    SprBankSet((s16)D_80110970_246850_SlotCarDerby, 5, (s16)D_8010FB84_245A64_SlotCarDerby[5]);
    SprBankSet((s16)D_80110970_246850_SlotCarDerby, 6, (s16)D_8010FB84_245A64_SlotCarDerby[6]);
    obj->model[0] = LoadFormFile(0x40000F, 0x499);
    obj->model[1] = LoadFormFile(0x400010, 0x499);
    obj->model[2] = LoadFormFile(0x400011, 0x499);
    obj->model[3] = LoadFormFile(0x400012, 0x499);
    for (i = 1; i < 4; i++) {
        func_800298A4_2A4A4(obj->model[i], 4, 4);
        D_800FC834_FD434[obj->model[i]].unk44 *= 0.5;
    }
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 2.0f;
    rec->unk_10.x = 77.1f;
    rec->unk_10.y = 1600.8f;
    rec->unk_10.z = 813.3f;
    obj->trans.x = rec->unk_10.x = D_8010FB44_245A24_SlotCarDerby[D_8010FB0C_2459EC_SlotCarDerby].x * 10.0;
    obj->trans.y = rec->unk_10.y = D_8010FB44_245A24_SlotCarDerby[D_8010FB0C_2459EC_SlotCarDerby].y * 10.0;
    obj->trans.z = rec->unk_10.z = D_8010FB44_245A24_SlotCarDerby[D_8010FB0C_2459EC_SlotCarDerby].z * 10.0;
    for (i = 0; i < 4; i++) {
        func_80029714_2A314(obj->model[i], rec->unk_10.x, rec->unk_10.y, rec->unk_10.z);
        func_800297E8_2A3E8(obj->model[i], obj->scale.x, obj->scale.y, obj->scale.z);
    }
}

void func_80109CDC_23FBBC_SlotCarDerby(omObjData* obj) {
    SCDFx* fx;
    HuSprite_Unk84_Struct* anim;
    void* data;
    s32 i;

    obj->func_ptr = func_8010A8CC_2407AC_SlotCarDerby;
    D_8011098C_24686C_SlotCarDerby = SprCreate(32, 0);
    data = DataRead(0x40001B);
    D_80110980_246860_SlotCarDerby[2] = SprAnimRead(data);
    DataClose(data);
    data = DataRead(0x40001A);
    D_80110980_246860_SlotCarDerby[0] = SprAnimRead(data);
    DataClose(data);
    data = DataRead(0x40001C);
    D_80110980_246860_SlotCarDerby[1] = SprAnimRead(data);
    DataClose(data);
    D_8011096C_24684C_SlotCarDerby = HuMemMemoryAllocPerm(32 * sizeof(SCDFx));
    for (i = 0; i < 32; i++) {
        fx = &D_8011096C_24684C_SlotCarDerby[i];
        fx->unk_01 = -1;
        fx->unk_02 = fx->unk_04 = 0;
        fx->unk_08.x = fx->unk_08.y = fx->unk_08.z = 0.0f;
        fx->unk_14.x = fx->unk_14.y = fx->unk_14.z = 0.0f;
        fx->unk_20 = fx->unk_24 = fx->unk_28 = 1.0f;
        fx->unk_2C.x = fx->unk_2C.y = fx->unk_2C.z = 0.0f;
        anim = SprAnimGet((s16)D_80110980_246860_SlotCarDerby[0]);
        anim->unk00->unk08 = 0;
        anim->unk00->unk0A = 27;
        fx->unk_00 = func_8010B688_241568_SlotCarDerby((s16)D_80110980_246860_SlotCarDerby[0], 0xB1);
        SprAttrSet((s16)D_8011098C_24686C_SlotCarDerby, i, 0x9008);
        func_8008225C_82E5C((s16)D_8011098C_24686C_SlotCarDerby, i, 0);
    }
    func_8010D0B0_242F90_SlotCarDerby();
}

/* Sets up the five floating billboards (MP2 only): random bob phase and speed. */
void func_80109EC0_23FDA0_SlotCarDerby(omObjData* obj) {
    SCDFloater* f;
    void* data;
    s16 id;
    s16 i;

    data = DataRead(0x400019);
    obj->work[0] = SprAnimRead(data);
    DataClose(data);
    f = D_80110978_246858_SlotCarDerby = HuMemMemoryAllocPerm(5 * sizeof(SCDFloater));
    func_800B0EF0_B1AF0(f, 0, 5 * sizeof(SCDFloater));
    for (i = 0; i < 5; i++, f++) {
        f->unk_00 = id = func_8010B688_241568_SlotCarDerby(obj->work[0], 0x11);
        if (id == -1) {
            continue;
        }
        f->unk_04 = ((rand8() << 8) | rand8()) % 360;
        f->unk_06 = 0;
        f->unk_0C.x = D_8010FBAC_245A8C_SlotCarDerby[i].x * 10.0;
        f->unk_0C.y = D_8010FBAC_245A8C_SlotCarDerby[i].y * 10.0;
        f->unk_0C.z = D_8010FBAC_245A8C_SlotCarDerby[i].z * 10.0;
        if (D_8010FB0C_2459EC_SlotCarDerby == 2 && i == 3) {
            f->unk_0C.z += 40.0;
        }
        f->unk_08 = ((f32)(u8)(rand8() % 100) * 0.01 * 3.0 + 3.0) * 0.5;
        func_8010C954_242834_SlotCarDerby(id, f->unk_0C.x, f->unk_0C.y, f->unk_0C.z);
        func_8010C9F4_2428D4_SlotCarDerby(id, 0.0f, 0.0f, 0.0f);
        func_8010C9A4_242884_SlotCarDerby(id, 10.0f, 10.0f, 1.0f);
        func_8010C8D4_2427B4_SlotCarDerby(id, 0);
        func_8010CAD0_2429B0_SlotCarDerby(id, 0xFF, 0xFF, 0xFF, 0xFF);
    }
    obj->func_ptr = func_8010AC5C_240B3C_SlotCarDerby;
}

void func_8010A190_240070_SlotCarDerby(omObjData* obj) {
    SCDObj* rec = func_8010B0B8_240F98_SlotCarDerby(obj);

    switch (D_8010FB00_2459E0_SlotCarDerby) {
        case 0:
        case 1:
        case 5:
            if (rec->unk_00 == 0) {
                D_80110960_246840_SlotCarDerby[0] = obj->model[2];
                D_80110960_246840_SlotCarDerby[1] = obj->model[3];
                func_80019B9C_1A79C(obj, 1);
                if (D_8010FB1C_2459FC_SlotCarDerby == 0) {
                    func_800298A4_2A4A4(obj->model[1], 4, 0);
                }
                D_800FC834_FD434[obj->model[0]].unk44 = 0.0f;
                D_800FC834_FD434[obj->model[1]].unk44 = 0.0f;
                rec->unk_02 = 4;
                rec->unk_40[0] = 0;
                rec->unk_40[1] = 0;
                rec->unk_00 = 1;
            }
            break;
        case 2:
            if (rec->unk_02 & 4) {
                if (rec->unk_08 != 0) {
                    if (rec->unk_08 >= 150) {
                        func_80019B9C_1A79C(obj, 0);
                        func_800298A4_2A4A4(obj->model[1], 4, 4);
                        rec->unk_02 = 2;
                        rec->unk_08 = 0;
                        rec->unk_00 = 0;
                        break;
                    }
                } else {
                    D_800FC834_FD434[obj->model[0]].unk44 = 1.0f;
                    D_800FC834_FD434[obj->model[1]].unk44 = 1.0f;
                    rec->unk_40[0] = 0;
                    rec->unk_40[1] = 0;
                }
                if ((func_80078EA8_79AA8() + D_80102720_103320) == 0 && D_8010FB04_2459E4_SlotCarDerby == 0) {
                    rec->unk_08++;
                }
            }
            if (D_8010FB04_2459E4_SlotCarDerby == 0) {
                break;
            }
        case 3:
        case 4:
            if (D_8010FBF4_245AD4_SlotCarDerby == 1) {
                if (func_80069538_6A138() == 0) {
                    func_800691FC_69DFC(14);
                    D_8010FBF4_245AD4_SlotCarDerby = 2;
                    D_801109D0_2468B0_SlotCarDerby = 1;
                }
            } else if (rec->unk_00 == 0) {
                rec->unk_02 = 4;
                func_80019B9C_1A79C(obj, 1);
                if (D_8010FB1C_2459FC_SlotCarDerby == 0) {
                    func_800298A4_2A4A4(obj->model[1], 4, 0);
                }
                func_80029C74_2A874(obj->model[0], 0.0f);
                func_80029C74_2A874(obj->model[1], 0.0f);
                rec->unk_08 = 0;
                rec->unk_40[0] = 0;
                rec->unk_40[1] = 0;
                rec->unk_00 = 1;
                if (D_8010FB18_2459F8_SlotCarDerby != 0) {
                    func_800691FC_69DFC(20);
                    D_8010FBF4_245AD4_SlotCarDerby = 1;
                    GWMgRecordSet((s16)D_8010FBE8_245AC8_SlotCarDerby[D_8010FB0C_2459EC_SlotCarDerby],
                                  (u16)D_8010FB10_2459F0_SlotCarDerby);
                } else {
                    func_800691FC_69DFC(20);
                    D_801109D0_2468B0_SlotCarDerby = 1;
                }
            }
            break;
        case 6:
            break;
    }
    if ((s16)rec->unk_02 == 4) {
        func_8002A15C_2AD5C(obj->model[1], (s16)D_80110960_246840_SlotCarDerby[rec->unk_40[0]],
                            1.0f - HuMathSin(rec->unk_40[1]));
        if ((func_80078EA8_79AA8() + D_80102720_103320) == 0) {
            rec->unk_40[1] += 6;
        }
        if (rec->unk_40[1] >= 180) {
            rec->unk_40[0] ^= 1;
            rec->unk_40[1] = 0;
        }
    }
    func_80019378_19F78(obj);
}

/* The time board: the start countdown lights (state 1), the race clock digits (state 2: one
   tick a frame, three ticks a tenth; the last digit flickers at random until 5:00), the final
   digit (states 3, 7, 8). */
// scheduling: one sll of the bank argument after the ternary's join (masked 1)
#ifdef NON_MATCHING
void func_8010A55C_24043C_SlotCarDerby(omObjData* obj) {
    SCDObj* rec = func_8010B0B8_240F98_SlotCarDerby(obj);
    s32 i;
    s32 d;

    switch (D_8010FB00_2459E0_SlotCarDerby) {
        case 1:
            if (++rec->unk_08 >= D_8010FBF8_245AD8_SlotCarDerby[rec->unk_00]) {
                if (rec->unk_00 >= 5) {
                    rec->unk_00 = 5;
                    rec->unk_08 = 0;
                } else {
                    rec->unk_08 = 0;
                    rec->unk_00++;
                    for (i = 0; i < 4; i++) {
                        func_800298A4_2A4A4(obj->model[i], 4, 4);
                    }
                    switch (rec->unk_00) {
                        case 1:
                            func_800298A4_2A4A4(obj->model[0], 4, 0);
                            break;
                        case 2:
                        case 3:
                            func_800298A4_2A4A4(obj->model[1], 4, 0);
                            break;
                        case 4:
                            func_800298A4_2A4A4(obj->model[2], 4, 0);
                            break;
                        case 5:
                        default:
                            func_800298A4_2A4A4(obj->model[3], 4, 0);
                            break;
                    }
                }
            }
            break;
        case 2:
            if (rec->unk_00 == 5) {
                rec->unk_00 = 0;
                rec->unk_08 = 0;
            }
            if (D_8010FB04_2459E4_SlotCarDerby == 0 && D_8010FC10_245AF0_SlotCarDerby[0] != 5) {
                D_8010FB10_2459F0_SlotCarDerby++;
                D_8010FC10_245AF0_SlotCarDerby[4]++;
            }
            i = 0;
            if (D_8010FC10_245AF0_SlotCarDerby[4] >= 3) {
                D_8010FC10_245AF0_SlotCarDerby[4] = 0;
                if (++D_8010FC10_245AF0_SlotCarDerby[3] >= 10) {
                    D_8010FC10_245AF0_SlotCarDerby[3] = 0;
                    if (++D_8010FC10_245AF0_SlotCarDerby[2] >= 10) {
                        D_8010FC10_245AF0_SlotCarDerby[2] = 0;
                        if (++D_8010FC10_245AF0_SlotCarDerby[1] >= 6) {
                            D_8010FC10_245AF0_SlotCarDerby[1] = 0;
                            D_8010FC10_245AF0_SlotCarDerby[0]++;
                        }
                    }
                }
            }
            do {
                if (i == 4) {
                    SprBankSet((s16)D_80110970_246850_SlotCarDerby, i,
                               d = D_8010FC10_245AF0_SlotCarDerby[0] == 5
                                       ? 0
                                       : (u8)(rand8() % 3) + D_8010FC10_245AF0_SlotCarDerby[4] * 3);
                } else {
                    SprBankSet((s16)D_80110970_246850_SlotCarDerby, i, (s16)D_8010FC10_245AF0_SlotCarDerby[i]);
                }
                i++;
            } while (i < 5);
            break;
        case 4:
        case 5:
        case 6:
            break;
        case 3:
        case 7:
        case 8:
            if (D_8010FB10_2459F0_SlotCarDerby == D_8010FB14_2459F4_SlotCarDerby) {
                SprBankSet((s16)D_80110970_246850_SlotCarDerby, 4, d = D_8010FC10_245AF0_SlotCarDerby[4] * 3 + 1);
            } else if (D_8010FB10_2459F0_SlotCarDerby < D_8010FB14_2459F4_SlotCarDerby) {
                SprBankSet((s16)D_80110970_246850_SlotCarDerby, 4, d = D_8010FC10_245AF0_SlotCarDerby[4] * 3);
            }
            break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/23F020", func_8010A55C_24043C_SlotCarDerby);
#endif

void func_8010A8CC_2407AC_SlotCarDerby(omObjData* obj) {
    Vec pos;
    Vec screen;
    SCDFx* fx;
    s32 i;

    D_8010FB08_2459E8_SlotCarDerby = (D_8010FB08_2459E8_SlotCarDerby + 1) % 3;
    if (D_8010FB00_2459E0_SlotCarDerby != 6) {
        for (i = 0; i < 32; i++) {
            fx = &D_8011096C_24684C_SlotCarDerby[i];
            if (fx->unk_01 == -1) {
                continue;
            }
            pos.x = fx->unk_08.x;
            pos.y = fx->unk_08.y + 80.0;
            pos.z = fx->unk_08.z;
            func_8010B0E4_240FC4_SlotCarDerby(0, &pos, &screen);
            switch (fx->unk_01) {
                case 0:
                    fx->unk_20 *= 0.8;
                    fx->unk_24 *= 0.8;
                    func_8010C9A4_242884_SlotCarDerby(fx->unk_00, fx->unk_20, fx->unk_24, fx->unk_28);
                    func_8010C8D4_2427B4_SlotCarDerby(fx->unk_00, fx->unk_02);
                    fx->unk_02++;
                    if ((s16)fx->unk_04 == 0) {
                        func_8010CA44_242924_SlotCarDerby(fx->unk_00, 0x20);
                        fx->unk_01 = -1;
                        fx->unk_02 = 0;
                        fx->unk_04 = 0;
                    }
                    break;
                case 1:
                    SprPosSet((s16)D_8011098C_24686C_SlotCarDerby, i, screen.x, screen.y);
                    screen.z = screen.z + (8 - (s16)fx->unk_04) * screen.z * 0.05;
                    SprScaleSet((s16)D_8011098C_24686C_SlotCarDerby, i, screen.z * fx->unk_20, screen.z * fx->unk_24);
                    SprBankSet((s16)D_8011098C_24686C_SlotCarDerby, i, fx->unk_02 + 4);
                    fx->unk_02++;
                    if ((s16)fx->unk_04 == 0) {
                        SprAttrSet((s16)D_8011098C_24686C_SlotCarDerby, i, 0x8000);
                        fx->unk_01 = -1;
                    }
                    break;
                case 2:
                    SprPosSet((s16)D_8011098C_24686C_SlotCarDerby, i, screen.x, screen.y);
                    screen.z = screen.z + (fx->unk_04 & 3) * screen.z * 0.25;
                    SprScaleSet((s16)D_8011098C_24686C_SlotCarDerby, i, screen.z * fx->unk_20, screen.z * fx->unk_24);
                    fx->unk_02 ^= 1;
                    SprBankSet((s16)D_8011098C_24686C_SlotCarDerby, i, fx->unk_02);
                    if ((s16)fx->unk_04 == 0) {
                        SprAttrSet((s16)D_8011098C_24686C_SlotCarDerby, i, 0x8000);
                        fx->unk_01 = -1;
                    }
                    break;
            }
            fx->unk_04--;
        }
        func_8010D0B0_242F90_SlotCarDerby();
    }
}

/* Bobs the five floating billboards: their scale swings with a sine of the bob angle. */
// 8 bytes more frame in retail, the angle wrap is not folded into one addiu, and retail has the KMC
// mul fix nop between its mul.d pair (the unit builds without the fix: 8010B0E4 lacks its after-call nops)
#ifdef NON_MATCHING
void func_8010AC5C_240B3C_SlotCarDerby(omObjData* obj) {
    SCDFloater* f = D_80110978_246858_SlotCarDerby;
    s16 id;
    s16 angle;
    f32 s;
    f32 c;
    s16 i;

    for (i = 0; i < 5; i++, f++) {
        if ((id = f->unk_00) == -1) {
            continue;
        }
        if (f->unk_02 == -1) {
            continue;
        }
        angle = f->unk_04 + 8;
        if (angle > 360) {
            angle -= 360;
        }
        s = HuMathSin(angle);
        c = -s;
        func_8010C9A4_242884_SlotCarDerby(id, (s * 10.0 * 0.15 + 10.0) * f->unk_08,
                                          (c * 10.0 * 0.15 + 10.0) * f->unk_08, 1.0f);
        f->unk_04 = angle;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/23F020", func_8010AC5C_240B3C_SlotCarDerby);
#endif

void func_8010AD94_240C74_SlotCarDerby(s32 type, Vec* pos, Vec* rot) {
    func_8010ADB0_240C90_SlotCarDerby(type, pos, rot);
}

void func_8010ADB0_240C90_SlotCarDerby(s32 type, Vec* pos, Vec* rot) {
    SCDFx* fx;
    s32 i;

    for (i = 0; i < 32; i++) {
        fx = &D_8011096C_24684C_SlotCarDerby[i];
        if (fx->unk_01 == -1) {
            break;
        }
    }
    if (i == 32) {
        return;
    }
    fx->unk_01 = type;
    fx->unk_04 = 0;
    fx->unk_02 = 0;
    fx->unk_08.x = pos->x * 10.0f;
    fx->unk_08.y = pos->y * 10.0f;
    fx->unk_08.z = pos->z * 10.0f;
    fx->unk_14.x = rot->x;
    fx->unk_14.y = rot->y;
    fx->unk_14.z = rot->z;
    switch (fx->unk_01) {
        case 0:
            func_8010CA88_242968_SlotCarDerby(fx->unk_00, 0x20);
            func_8010C954_242834_SlotCarDerby(fx->unk_00, fx->unk_08.x, fx->unk_08.y, fx->unk_08.z);
            func_8010C9F4_2428D4_SlotCarDerby(fx->unk_00, fx->unk_14.z, fx->unk_14.y - 90.0f, fx->unk_14.x);
            func_8010CAD0_2429B0_SlotCarDerby(fx->unk_00, 0xFF, 0x96, 0, 0xFF);
            fx->unk_20 = 60.0f;
            fx->unk_24 = 20.0f;
            fx->unk_28 = 1.0f;
            func_8010C9A4_242884_SlotCarDerby(fx->unk_00, fx->unk_20, fx->unk_24, fx->unk_28);
            func_8010C914_2427F4_SlotCarDerby(fx->unk_00, 4.0f);
            fx->unk_04 = 15;
            break;
        case 1:
            func_800824B4_830B4((s16)D_8011098C_24686C_SlotCarDerby, (s16)i, 0xFF, 0xFF, 0xFF, 0xFF);
            SprAnimSet((s16)D_8011098C_24686C_SlotCarDerby, i, (s16)D_80110980_246860_SlotCarDerby[fx->unk_01], 0);
            SprAttrReset((s16)D_8011098C_24686C_SlotCarDerby, i, 0x8000);
            fx->unk_20 = 2.5f;
            fx->unk_24 = 2.5f;
            fx->unk_28 = 1.0f;
            fx->unk_04 = 7;
            break;
        case 2:
            fx->unk_08.y += 160.0f;
            func_800824B4_830B4((s16)D_8011098C_24686C_SlotCarDerby, (s16)i, 0, 0, 0, 0xFF);
            SprAnimSet((s16)D_8011098C_24686C_SlotCarDerby, i, (s16)D_80110980_246860_SlotCarDerby[fx->unk_01], 0);
            fx->unk_20 = 10.0f;
            fx->unk_24 = 10.0f;
            fx->unk_28 = 1.0f;
            SprAttrReset((s16)D_8011098C_24686C_SlotCarDerby, i, 0x8000);
            fx->unk_04 = 7;
            break;
    }
}

/* Keeps rec's address in obj->work (big-endian bytes). Host: a pointer does not fit the four
   bytes on LP64 (MP1's port stores the record index there instead). */
void func_8010B098_240F78_SlotCarDerby(omObjData* obj, SCDObj* rec) {
    u32 v = (u32)rec;

    obj->work[0] = v >> 24;
    obj->work[1] = v >> 16;
    obj->work[2] = v >> 8;
    obj->work[3] = v;
}

SCDObj* func_8010B0B8_240F98_SlotCarDerby(omObjData* obj) {
    u32 v = (obj->work[0] << 24) | (obj->work[1] << 16) | (obj->work[2] << 8) | obj->work[3];

    return (SCDObj*)v;
}

/* Projects pos through camera cam's view into screen x, y and a perspective scale (z). */
// addu operand order of the first viewport address (raw 1, masked 0)
#ifdef NON_MATCHING
void func_8010B0E4_240FC4_SlotCarDerby(s32 cam, Vec* pos, Vec* screen) {
    Mtx look;
    Mtx mtx;
    Vec eye;
    Vec at;
    Vec up;
    HuCamera* c = &D_800C9B80_CA780[cam];
    Mtx* m = &mtx;
    HuCamera* vp;
    f32 rx;
    f32 ry;
    f32 sx;
    f32 sy;
    f32 sz;
    f32 sn;
    f32 dist;

    rx = D_800FD474_FE074.x;
    ry = D_800FD474_FE074.y;
    eye.x = D_8010274C_10334C.x + HuMathSin(ry) * func_800B7890_B8490(rx) * D_800FA610_FB210;
    eye.y = D_8010274C_10334C.y + -HuMathSin(rx) * D_800FA610_FB210;
    eye.z = D_8010274C_10334C.z + func_800B7890_B8490(ry) * func_800B7890_B8490(rx) * D_800FA610_FB210;
    at.x = D_8010274C_10334C.x;
    at.y = D_8010274C_10334C.y;
    at.z = D_8010274C_10334C.z;
    up.x = HuMathSin(ry) * HuMathSin(rx);
    up.y = func_800B7890_B8490(rx);
    up.z = func_800B7890_B8490(ry) * HuMathSin(rx);
    guLookAt(&look, eye.x, eye.y, eye.z, at.x, at.y, at.z, up.x, up.y, up.z);
    func_800B1FA0_B2BA0(m, pos->x, pos->y, pos->z);
    guMtxCatL(m, &look, m);
    sx = (s32)((((u16*)&mtx)[12] << 16) | ((u16*)&mtx)[28]) >> 16;
    sy = (s32)((((u16*)&mtx)[13] << 16) | ((u16*)&mtx)[29]) >> 16;
    sz = (s32)((((u16*)&mtx)[14] << 16) | ((u16*)&mtx)[30]) >> 16;
    sn = HuMathSin(D_800C9B80_CA780[cam].fov[0] / 2.0);
    dist = fabsf(sz * sn / func_800B7890_B8490(D_800C9B80_CA780[cam].fov[0] / 2.0));
    if (dist != 0.0) {
        /* c->viewports[D_800FFFD6], written through f32* (not Vec fields): retail reloads
           D_800FFFD6 after the store */
        ((f32*)screen)[0] =
            (s16)(((HuCamera*)((u8*)c + D_800FFFD6_100BD6 * 16))->viewports[0].vp.vscale[0] / 4.0 * sx / dist / 1.3333334f) +
            ((HuCamera*)((u8*)c + D_800FFFD6_100BD6 * 16))->viewports[0].vp.vtrans[0] / 4.0;
        vp = (HuCamera*)((u8*)c + D_800FFFD6_100BD6 * 16);
        ((f32*)screen)[1] = (s16)(vp->viewports[0].vp.vscale[1] / 4.0 * -sy / dist) + vp->viewports[0].vp.vtrans[1] / 4.0;
        ((f32*)screen)[2] = vp->viewports[0].vp.vscale[1] / 4.0 / dist;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/23F020", func_8010B0E4_240FC4_SlotCarDerby);
#endif

void func_8010B4D0_2413B0_SlotCarDerby(u8 count) {
    SCDBillboard* b;
    s16 i;

    D_80110990_246870_SlotCarDerby = count;
    for (i = 0; i < 3; i++) {
        D_80110994_246874_SlotCarDerby[i] = HuMemMemoryAllocPerm(D_80110990_246870_SlotCarDerby * 20 * sizeof(Gfx));
        D_801109A0_246880_SlotCarDerby[i] = HuMemMemoryAllocPerm(D_80110990_246870_SlotCarDerby * sizeof(Mtx));
    }
    D_801109AC_24688C_SlotCarDerby = func_80027FA4_28BA4(0x499, D_80110994_246874_SlotCarDerby[0], 4);
    D_8011097C_24685C_SlotCarDerby = HuMemMemoryAllocPerm(D_80110990_246870_SlotCarDerby * sizeof(SCDBillboard));
    for (i = 0; i < D_80110990_246870_SlotCarDerby; i++) {
        b = &D_8011097C_24685C_SlotCarDerby[i];
        b->unk_00 = (Gfx*)-1;
        b->unk_20 = 0;
        b->unk_28 = 0;
        b->unk_22 = 0;
        b->unk_29 = b->unk_2A = b->unk_2B = b->unk_2C = 0xFF;
        b->unk_30 = 0.0f;
        b->unk_24 = 0;
        b->unk_26 = 0;
        b->unk_34 = 1.0f;
        b->unk_38.x = b->unk_38.y = b->unk_38.z = 0.0f;
        b->unk_44.x = b->unk_44.y = b->unk_44.z = 1.0f;
        b->unk_50.x = b->unk_50.y = b->unk_50.z = 0.0f;
    }
}

/* gDPSetTile's mask for a texture dimension (as src/1EA70.c's TEX_MASK). */
#define SCD_TEX_MASK(x) \
    ((x) < 3 ? 1 : (x) < 5 ? 2 : (x) < 9 ? 3 : (x) < 17 ? 4 : (x) < 33 ? 5 : (x) < 65 ? 6 : (x) < 129 ? 7 : (x) < 257 ? 8 : 9)

/* Takes a free billboard for sprite and builds its display list (texture and quad), its
   per-frame vertex copies and its per-frame material lists. Returns its id, -1 if none is free. */
// register allocation: the vertex buffer copy and the frame width take t1/t2 in retail (masked 10, as MP1)
#ifdef NON_MATCHING
s16 func_8010B688_241568_SlotCarDerby(s16 sprite, u8 flags) {
    SCDBillboard* b;
    HuSprite_Unk84_Struct* anim;
    HuSprite_Unk84_Unk00_Struct* frame;
    Gfx* dl;
    Gfx* gfx;
    Vtx* vbuf;
    Vtx* v;
    s32 size;
    u16 w;
    u16 h;
    s16 x;
    s16 y;
    s16 nh;
    s16 i;
    s16 id;

    for (id = 0; id < D_80110990_246870_SlotCarDerby; id++) {
        if (D_8011097C_24685C_SlotCarDerby[id].unk_00 == (Gfx*)-1) {
            break;
        }
    }
    if (id == D_80110990_246870_SlotCarDerby) {
        return -1;
    }
    b = &D_8011097C_24685C_SlotCarDerby[id];
    b->unk_22 = sprite;
    b->unk_28 = flags;
    dl = HuMemMemoryAllocPerm(0x2000 * sizeof(Gfx)); /* 0x10000 bytes on the N64 */
    vbuf = v = HuMemMemoryAllocPerm(8 * sizeof(Vtx));
    gfx = dl;
    gDPPipeSync(gfx++);
    anim = D_800F60B0_F6CB0[b->unk_22];
    if (anim->unk18 & 0x8000) {
        gDPSetCombine(gfx++, 0xFF97FF, 0xFF2DFEFF);
        gDPSetRenderMode(gfx++, 0x4049D8, 0);
        gDPSetBlendColor(gfx++, 1, 1, 1, 1);
    } else if (b->unk_29 == 0xFF) {
        gDPSetRenderMode(gfx++, 0x443078, 0);
        gDPSetCombine(gfx++, 0xFFFFFF, 0xFFFCF279);
    } else {
        gDPSetBlendColor(gfx++, 0, 0, 0, 1);
        gDPSetRenderMode(gfx++, 0x5049D8, 0);
        gDPSetCombine(gfx++, 0x143228, 0xFF65FEFF);
    }
    frame = &anim->unk00[b->unk_24];
    w = frame->unk04;
    h = frame->unk06;
    if (anim->unk18 & 0x8000) {
        gDPLoadTextureBlock_4b(gfx++, 0x02000000, G_IM_FMT_I, (s16)w, (s16)h, 0, G_TX_CLAMP, G_TX_CLAMP,
                               SCD_TEX_MASK((s16)w), SCD_TEX_MASK((s16)h), G_TX_NOLOD, G_TX_NOLOD);
    } else if (anim->unk18 < 0x11) {
        gDPLoadTextureBlock_4b(gfx++, 0x02000000, G_IM_FMT_CI, (s16)w, (s16)h, 0, G_TX_CLAMP, G_TX_CLAMP,
                               SCD_TEX_MASK((s16)w), SCD_TEX_MASK((s16)h), G_TX_NOLOD, G_TX_NOLOD);
    } else {
        gDPLoadTextureBlock(gfx++, 0x02000000, G_IM_FMT_CI, G_IM_SIZ_8b, (s16)w, (s16)h, 0, G_TX_CLAMP, G_TX_CLAMP,
                            SCD_TEX_MASK((s16)w), SCD_TEX_MASK((s16)h), G_TX_NOLOD, G_TX_NOLOD);
    }
    gSPVertex(gfx++, 0x01000000, 4, 0);
    gSP1Quadrangle(gfx++, 0, 1, 2, 3, 0);
    gSPEndDisplayList(gfx++);
    nh = -h;
    x = -frame->unk08;
    y = frame->unk0A;
    v->v.ob[0] = x;
    v->v.ob[1] = y;
    v->v.ob[2] = 0;
    v->n.n[0] = v->n.n[1] = v->n.n[2] = -1;
    v->v.tc[0] = 0;
    v->v.tc[1] = 0;
    v->n.a = 0xFF;
    v++;
    v->v.ob[0] = x;
    v->v.ob[1] = nh + y;
    v->v.ob[2] = 0;
    v->n.n[0] = v->n.n[1] = v->n.n[2] = -1;
    v->v.tc[0] = 0;
    v->v.tc[1] = (-nh - 1) << 6;
    v->n.a = 0xFF;
    v++;
    v->v.ob[0] = (s16)w + x;
    v->v.ob[1] = nh + y;
    v->v.ob[2] = 0;
    v->n.n[0] = v->n.n[1] = v->n.n[2] = -1;
    v->v.tc[0] = ((s16)w - 1) << 6;
    v->v.tc[1] = (-nh - 1) << 6;
    v->n.a = 0xFF;
    v++;
    v->v.ob[0] = (s16)w + x;
    v->v.ob[1] = y;
    v->v.ob[2] = 0;
    v->n.n[0] = v->n.n[1] = v->n.n[2] = -1;
    v->v.tc[0] = ((s16)w - 1) << 6;
    v->v.tc[1] = 0;
    v->n.a = 0xFF;
    size = (u8*)gfx - (u8*)dl;
    for (i = 0; i < D_800FDBCA_FE7CA; i++) {
        b->unk_10[i] = HuMemMemoryAllocPerm(8 * sizeof(Vtx));
        bcopy(vbuf, b->unk_10[i], 8 * sizeof(Vtx));
    }
    b->unk_00 = HuMemMemoryAllocPerm(size);
    bcopy(dl, b->unk_00, size);
    HuMemMemoryFreePerm(dl);
    HuMemMemoryFreePerm(vbuf);
    dl = HuMemMemoryAllocPerm(0x2000 * sizeof(Gfx)); /* 0x10000 bytes on the N64 */
    gfx = dl;
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, b->unk_2A, b->unk_2B, b->unk_2C, b->unk_29);
    gDPSetTextureFilter(gfx++, D_8010FC28_245B08_SlotCarDerby[(b->unk_28 & 0x18) >> 3]);
    if (anim->unk18 & 0x8000) {
        gDPSetTextureLUT(gfx++, G_TT_NONE);
    } else {
        gDPSetTextureLUT(gfx++, G_TT_RGBA16);
        if (anim->unk18 < 0x11) {
            gDPLoadTLUT_pal16(gfx++, 0, anim->unk0C);
        } else {
            gDPLoadTLUT_pal256(gfx++, anim->unk0C);
        }
    }
    gSPSegment(gfx++, 2, osVirtualToPhysical(frame->unk00));
    gSPSegment(gfx++, 1, osVirtualToPhysical(b->unk_10[0]));
    gSPDisplayList(gfx++, b->unk_00);
    gSPEndDisplayList(gfx++);
    size = (u8*)gfx - (u8*)dl;
    for (i = 0; i < D_800FDBCA_FE7CA; i++) {
        b->unk_04[i] = HuMemMemoryAllocPerm(size);
        bcopy(dl, b->unk_04[i], size);
    }
    HuMemMemoryFreePerm(dl);
    return id;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/23F020", func_8010B688_241568_SlotCarDerby);
#endif

void func_8010C8D4_2427B4_SlotCarDerby(s16 id, s16 frame) {
    SCDBillboard* b;

    if (id != -1) {
        b = &D_8011097C_24685C_SlotCarDerby[id];
        b->unk_24 = frame;
        b->unk_30 = 0.0f;
    }
}

void func_8010C914_2427F4_SlotCarDerby(s16 id, f32 speed) {
    if (id != -1) {
        SCDBillboard* b = &D_8011097C_24685C_SlotCarDerby[id];

        b->unk_34 = speed;
    }
}

void func_8010C954_242834_SlotCarDerby(s16 id, f32 x, f32 y, f32 z) {
    SCDBillboard* b;

    if (id != -1) {
        b = &D_8011097C_24685C_SlotCarDerby[id];
        b->unk_38.x = x;
        b->unk_38.y = y;
        b->unk_38.z = z;
    }
}

void func_8010C9A4_242884_SlotCarDerby(s16 id, f32 x, f32 y, f32 z) {
    SCDBillboard* b;

    if (id != -1) {
        b = &D_8011097C_24685C_SlotCarDerby[id];
        b->unk_44.x = x;
        b->unk_44.y = y;
        b->unk_44.z = z;
    }
}

void func_8010C9F4_2428D4_SlotCarDerby(s16 id, f32 x, f32 y, f32 z) {
    SCDBillboard* b;

    if (id != -1) {
        b = &D_8011097C_24685C_SlotCarDerby[id];
        b->unk_50.x = x;
        b->unk_50.y = y;
        b->unk_50.z = z;
    }
}

void func_8010CA44_242924_SlotCarDerby(s16 id, u8 flags) {
    SCDBillboard* b;

    if (id != -1) {
        b = &D_8011097C_24685C_SlotCarDerby[id];
        b->unk_28 |= flags;
    }
}

void func_8010CA88_242968_SlotCarDerby(s16 id, u8 flags) {
    SCDBillboard* b;

    if (id != -1) {
        b = &D_8011097C_24685C_SlotCarDerby[id];
        b->unk_28 &= ~flags;
    }
}

void func_8010CAD0_2429B0_SlotCarDerby(s16 id, u8 r, u8 g, u8 b, s32 a) {
    SCDBillboard* bb;

    if (id != -1) {
        bb = &D_8011097C_24685C_SlotCarDerby[id];
        bb->unk_2A = r;
        bb->unk_2B = g;
        bb->unk_2C = b;
        bb->unk_29 = a;
    }
}

/* Frees a billboard's display lists and resets it. */
void func_8010CB1C_2429FC_SlotCarDerby(s16 id) {
    SCDBillboard* b;
    s32 i;

    if (id != -1) {
        b = &D_8011097C_24685C_SlotCarDerby[id];
        if (b->unk_00 != (Gfx*)-1) {
            for (i = 0; i < D_800FDBCA_FE7CA; i++) {
                HuMemMemoryFreePerm(b->unk_10[i]);
                HuMemMemoryFreePerm(b->unk_04[i]);
            }
            HuMemMemoryFreePerm(b->unk_00);
            b->unk_00 = (Gfx*)-1;
            b->unk_1C = 0;
            b->unk_20 = 0;
            b->unk_28 = 0;
            b->unk_22 = 0;
            b->unk_29 = b->unk_2A = b->unk_2B = b->unk_2C = 0xFF;
            b->unk_30 = 0.0f;
            b->unk_24 = 0;
            b->unk_26 = 0;
            b->unk_38.x = b->unk_38.y = b->unk_38.z = 0.0f;
            b->unk_34 = b->unk_44.x = b->unk_44.y = b->unk_44.z = 1.0f;
        }
    }
}

/* Rewrites each visible billboard's material list for this frame and advances its animation
   (two steps a frame; flags 4/0x40/2 hide, free or hold it at the end). */
void func_8010CC3C_242B1C_SlotCarDerby(void) {
    SCDBillboard* b;
    HuSprite_Unk84_Struct* anim;
    HuSprite_Unk84_Unk00_Struct* frame;
    Gfx* gfx;
    HuSprCelAnm* seq;
    s32 len;
    s32 count;
    s16 j;
    s16 i;

    for (i = 0; i < D_80110990_246870_SlotCarDerby; i++) {
        b = &D_8011097C_24685C_SlotCarDerby[i];
        if (b->unk_00 == (Gfx*)-1 || b->unk_20 != 0 || (b->unk_28 & 0x20)) {
            continue;
        }
        gfx = b->unk_04[D_800FDBE0_FE7E0];
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, b->unk_2A, b->unk_2B, b->unk_2C, b->unk_29);
        gDPSetTextureFilter(gfx++, D_8010FC28_245B08_SlotCarDerby[(b->unk_28 & 0x18) >> 3]);
        anim = D_800F60B0_F6CB0[b->unk_22];
        frame = &anim->unk00[b->unk_24];
        if (anim->unk18 & 0x8000) {
            gDPSetTextureLUT(gfx++, G_TT_NONE);
        } else {
            gDPSetTextureLUT(gfx++, G_TT_RGBA16);
            if (anim->unk18 < 0x11) {
                gDPLoadTLUT_pal16(gfx++, 0, anim->unk0C);
            } else {
                gDPLoadTLUT_pal256(gfx++, anim->unk0C);
            }
        }
        gSPSegment(gfx++, 2, osVirtualToPhysical(frame->unk00));
        gSPSegment(gfx++, 1, osVirtualToPhysical(b->unk_10[D_800FDBE0_FE7E0]));
        gSPDisplayList(gfx++, b->unk_00);
        gSPEndDisplayList(gfx++);
        if (b->unk_28 & 1) {
            continue;
        }
        if (anim->unk04 != NULL) {
            seq = *anim->unk04;
            len = (s16)seq->unk04[b->unk_24].unk02;
            count = seq->unk00;
        } else {
            len = 8;
            count = anim->unk10;
        }
        for (j = 0; j < 2; j++) {
            b->unk_30 += b->unk_34;
            if (b->unk_30 >= len) {
                b->unk_24++;
                b->unk_30 -= len;
                if (b->unk_24 + 1 >= count) {
                    if (b->unk_28 & 4) {
                        func_8010CA44_242924_SlotCarDerby(i, 0x20);
                        break;
                    }
                    if (b->unk_28 & 0x40) {
                        func_8010CB1C_2429FC_SlotCarDerby(i);
                        break;
                    }
                    if (b->unk_28 & 2) {
                        b->unk_24--;
                        break;
                    }
                    b->unk_24 = 0;
                }
            }
        }
    }
}

// scheduling: b->unk_1C is loaded before the frame index in retail (masked 2)
#ifdef NON_MATCHING
void func_8010D0B0_242F90_SlotCarDerby(void) {
    Mtx view;
    /* host: retail puts this stack matrix's address in the display list, drawn after the
       function returns (MP1's port makes it static) */
    Mtx proj;
    Matrix4f mf;
    Matrix4f tmp;
    Matrix4f sc;
    Vec eye;
    Vec at;
    Vec up;
    SCDBillboard* b;
    Gfx* gfx;
    Mtx* mtx;
    f32 rx;
    f32 ry;
    s32 i;

    func_8010CC3C_242B1C_SlotCarDerby();
    D_800FC834_FD434[D_801109AC_24688C_SlotCarDerby].hmf->unk3C = (HmfDisp*)&D_80110994_246874_SlotCarDerby[D_8010FB08_2459E8_SlotCarDerby];
    gfx = D_80110994_246874_SlotCarDerby[D_8010FB08_2459E8_SlotCarDerby];
    mtx = D_801109A0_246880_SlotCarDerby[D_8010FB08_2459E8_SlotCarDerby];
    proj = D_800C9B80_CA780->mtxs[D_800FFFD6_100BD6].lookAtMtx; /* the viewport's view matrix */
    rx = D_800FD474_FE074.x;
    ry = D_800FD474_FE074.y;
    eye.x = D_8010274C_10334C.x + HuMathSin(ry) * func_800B7890_B8490(rx) * D_800FA610_FB210;
    eye.y = D_8010274C_10334C.y + -HuMathSin(rx) * D_800FA610_FB210;
    eye.z = D_8010274C_10334C.z + func_800B7890_B8490(ry) * func_800B7890_B8490(rx) * D_800FA610_FB210;
    at.x = D_8010274C_10334C.x;
    at.y = D_8010274C_10334C.y;
    at.z = D_8010274C_10334C.z;
    up.x = HuMathSin(ry) * HuMathSin(rx);
    up.y = func_800B7890_B8490(rx);
    up.z = func_800B7890_B8490(ry) * HuMathSin(rx);
    guLookAt(&view, eye.x, eye.y, eye.z, at.x, at.y, at.z, up.x, up.y, up.z);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gfx++, G_LIGHTING | G_FOG | G_CULL_BOTH);
    gSPSetGeometryMode(gfx++, G_ZBUFFER | G_SHADE | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH);
    gDPSetBlendColor(gfx++, 0, 0, 0, 1);
    gDPSetAlphaCompare(gfx++, G_AC_THRESHOLD);
    gSPTexture(gfx++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    for (i = 0; i < D_80110990_246870_SlotCarDerby; i++) {
        b = &D_8011097C_24685C_SlotCarDerby[i];
        if (b->unk_00 == (Gfx*)-1 || (b->unk_28 & 0x20)) {
            continue;
        }
        guMtxL2F(mf, &view);
        func_80025770_26370(mf, b->unk_38.x, b->unk_38.y, b->unk_38.z);
        func_80025884_26484(mf, b->unk_50.x, b->unk_50.y, b->unk_50.z);
        func_80025830_26430(mf, b->unk_44.x, b->unk_44.y, b->unk_44.z);
        if (!(b->unk_28 & 0x80)) {
            sc[0][0] = b->unk_44.x;
            sc[1][1] = b->unk_44.y;
            sc[2][2] = b->unk_44.z;
            sc[3][3] = 1.0f;
            sc[0][1] = sc[0][2] = sc[0][3] = sc[1][0] = sc[1][2] = sc[1][3] = sc[2][0] = sc[2][1] = sc[2][3] =
                sc[3][0] = sc[3][1] = sc[3][2] = 0.0f;
            func_800260A4_26CA4(mf, tmp);
            func_80025BA4_267A4(sc, tmp, mf);
        }
        if (b->unk_20 != 0) {
            gSPSegment(gfx++, 1, osVirtualToPhysical(((Vtx**)b->unk_1C + 17)[D_800FDBE0_FE7E0]));
        }
        func_800B3040_B3C40(mf, mtx);
        gSPMatrix(gfx++, osVirtualToPhysical(mtx++), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gfx++, b->unk_04[D_800FDBE0_FE7E0]);
    }
    gSPMatrix(gfx++, osVirtualToPhysical(&proj), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPEndDisplayList(gfx++);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/23F020", func_8010D0B0_242F90_SlotCarDerby);
#endif

void func_8010D590_243470_SlotCarDerby(void) {
    s32 i;

    for (i = 0; i < D_80110990_246870_SlotCarDerby; i++) {
        func_8010CB1C_2429FC_SlotCarDerby(i);
    }
    HuMemMemoryFreePerm(D_8011097C_24685C_SlotCarDerby);
    for (i = 0; i < 3; i++) {
        HuMemMemoryFreePerm(D_80110994_246874_SlotCarDerby[i]);
        HuMemMemoryFreePerm(D_801109A0_246880_SlotCarDerby[i]);
    }
}

s16 func_8010D644_243524_SlotCarDerby(s32 file) {
    void* data = DataRead(file);
    s16 sprite = SprAnimRead(data);

    DataClose(data);
    return sprite;
}

/* Reads the speedometers' shared sprites: "MAX", digits, unit. */
void func_8010D68C_24356C_SlotCarDerby(void) {
    D_801109BA_24689A_SlotCarDerby[0] = func_8010D644_243524_SlotCarDerby(0x40001D);
    D_801109BA_24689A_SlotCarDerby[1] = func_8010D644_243524_SlotCarDerby(0x43);
    D_801109BA_24689A_SlotCarDerby[2] = func_8010D644_243524_SlotCarDerby(0x10015);
}

/* Sets up player's speedometer (sprite group D_801109C0[player]) in its screen corner: member 0
   the dial (sprite files[type]), 1-3 the digits, 4 the unit, 5 the "MAX" sign (hidden). Odd
   players' meters are mirrored. */
// the loop-invariant position terms are associated differently (x - (w + 6) kept whole in retail),
// so the hoisted values differ (masked 17)
#ifdef NON_MATCHING
void func_8010D6DC_2435BC_SlotCarDerby(s32 type, s32 player) {
    s32 files[6] = { 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D };
    HuSprite_Unk84_Struct* anim;
    s16 x;
    s16 y;
    s16 w;
    s16 h;
    s16 group;
    s16 i;

    if (D_8010FC40_245B20_SlotCarDerby == 0) {
        func_8010D68C_24356C_SlotCarDerby();
        D_8010FC40_245B20_SlotCarDerby = 1;
    }
    x = D_8010FC30_245B10_SlotCarDerby[player][0];
    y = D_8010FC30_245B10_SlotCarDerby[player][1];
    D_801109B0_246890_SlotCarDerby[player] = func_8010D644_243524_SlotCarDerby(files[type]);
    anim = SprAnimGet(D_801109B0_246890_SlotCarDerby[player]);
    if (player & 1) {
        anim->unk00->unk08 = anim->unk00->unk04;
    } else {
        anim->unk00->unk08 = 0;
    }
    anim = SprAnimGet(D_801109BA_24689A_SlotCarDerby[2]);
    w = anim->unk00->unk04;
    h = anim->unk00->unk08;
    group = D_801109C0_2468A0_SlotCarDerby[player] = SprCreate(6, 0);
    for (i = 0; i < 6; i++) {
        if (i == 0) {
            SprPosSet(group, 0, x, y);
            SprAnimSet(group, 0, D_801109B0_246890_SlotCarDerby[player], 0);
        } else if (i < 4) {
            SprAnimSet(group, i, D_801109BA_24689A_SlotCarDerby[1], 0);
            if (player & 1) {
                SprPosSet(group, i, x - w - 6 - (3 - i) * 12, y + 16);
            } else {
                SprPosSet(group, i, x + (i - 1) * 12 + 6, y + 16);
            }
        } else if (i == 4) {
            SprAnimSet(group, 4, D_801109BA_24689A_SlotCarDerby[2], 0);
            if (player & 1) {
                SprPosSet(group, 4, x - (w - h), y + 16);
            } else {
                SprPosSet(group, i, x + h + 36, y + 16);
            }
        } else {
            SprAnimSet(group, i, D_801109BA_24689A_SlotCarDerby[0], 0);
            if (player & 1) {
                SprPosSet(group, i, x - (w - h) - 32 + w / 2, y + 16);
            } else {
                SprPosSet(group, i, x + w / 2 + 18, y + 16);
            }
            SprAttrSet(group, i, 0x8000);
        }
        func_8008225C_82E5C(group, i, 0);
        SprBankSet(group, i, 0);
        SprAttrSet(group, i, 0x1000);
    }
    func_8008225C_82E5C(group, 5, 1);
    func_8008221C_82E1C(group, 5, 3.0f);
}
#else
__asm__(".section .rodata");
const u32 D_80110210_2460F0_SlotCarDerby[6] = { 0x00000028, 0x00000029, 0x0000002A, 0x0000002B, 0x0000002C, 0x0000002D };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/23F020", func_8010D6DC_2435BC_SlotCarDerby);
/* GCC still believes it is in .rodata (the const above) and emits the next function's local
   initialiser without a section switch: switch back for it */
__asm__(".section .rodata");
#endif

/* Shows player's speed (0..1 of the top speed; < 0 or a finished race hides the meter for good):
   in mph (200 at full speed, / 1.6093), "MAX" from 192. */
void func_8010DAD8_2439B8_SlotCarDerby(s32 player, f32 speed) {
    s16 digits[3] = { 0, 0, 0 };
    s16 group;
    s16 i;

    group = D_801109C0_2468A0_SlotCarDerby[player];
    if (group == -1) {
        return;
    }
    if (speed < 0.0 || D_8010FB00_2459E0_SlotCarDerby >= 3) {
        for (i = 0; i < 6; i++) {
            SprAttrSet(group, i, 0x8000);
        }
        D_801109C0_2468A0_SlotCarDerby[player] = -1;
        return;
    }
    if (speed > 1.0f) {
        speed = 1.0f;
    }
    if (speed < 0.1f) {
        speed = 0.0f;
    }
    speed *= 200.0f;
    if (speed >= 192.0f) {
        SprAttrSet(group, 1, 0x8000);
        SprAttrSet(group, 2, 0x8000);
        SprAttrSet(group, 3, 0x8000);
        SprAttrSet(group, 4, 0x8000);
        SprAttrReset(group, 5, 0x8000);
        return;
    }
    speed /= 1.6093f;
    while (speed >= 100.0f) {
        speed -= 100.0f;
        digits[0]++;
    }
    while (speed >= 10.0f) {
        speed -= 10.0f;
        digits[1]++;
    }
    digits[2] = speed;
    SprBankSet(group, 1, digits[0]);
    SprBankSet(group, 2, digits[1]);
    SprBankSet(group, 3, digits[2]);
    SprAttrReset(group, 1, 0x8000);
    SprAttrReset(group, 2, 0x8000);
    SprAttrReset(group, 3, 0x8000);
    SprAttrReset(group, 4, 0x8000);
    SprAttrSet(group, 5, 0x8000);
}
