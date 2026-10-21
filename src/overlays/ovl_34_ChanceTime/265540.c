#include "common.h"
#include "ovl_34.h"

/* Retail starts a new file here (0x8010E440): the previous one is padded to 16 bytes. */

void func_8010E440_265540_ChanceTime(omObjData* obj) {
    CTBoxWork* work;
    s32 i;
    u16 attr = 0xAB9;

    work = func_80027154_27D54(sizeof(CTBoxWork), 0x7918);
    obj->unk_50 = work;
    func_800B0EF0_B1AF0(work, 0, sizeof(CTBoxWork));
    work->unk_03 = 1;
    work->unk_04 = 0;
    work->unk_08 = 0.5f;
    func_8000BF24_CB24(obj, 10.0f, -250.0f, 1320.0f, 250.0f, 1480.0f);
    func_8000BFF0_CBF0(obj);
    if (D_80110060_267160_ChanceTime != 0) {
        D_801109C2_267AC2_ChanceTime = func_8001A2F8_1AEF8(0x440005);
    } else {
        D_801109C2_267AC2_ChanceTime = func_8001A2F8_1AEF8(0x440004);
    }
    D_801109C0_267AC0_ChanceTime = func_8001AAAC_1B6AC(D_801109C2_267AC2_ChanceTime, 0, 1);
    func_8001A708_1B308(D_801109C0_267AC0_ChanceTime, 0x4000);
    func_8001A91C_1B51C(D_801109C0_267AC0_ChanceTime, 1.0f, 1.0f);
    espDispOn(D_801109C0_267AC0_ChanceTime);
    espPosSet(D_801109C0_267AC0_ChanceTime, 160, 120);
    for (i = 0; i < 3; i++) {
        if (D_80110060_267160_ChanceTime != 0) {
            obj->model[i] = func_80018A64_19664(0x440007, attr);
        } else {
            obj->model[i] = func_80018A64_19664(0x440006, attr);
        }
    }
    obj->trans.x = 0.0f;
    obj->trans.y = -120.0f;
    obj->trans.z = 500.0f;
    obj->scale.x = 1.0f;
    obj->scale.y = 1.0f;
    obj->scale.z = 0.0f;
    func_80029714_2A314(obj->model[1], -240.0f, obj->trans.y, obj->trans.z);
    func_80029714_2A314(obj->model[2], 240.0f, obj->trans.y, obj->trans.z);
    func_800297E8_2A3E8(obj->model[1], obj->scale.x, obj->scale.y, obj->scale.z);
    func_800297E8_2A3E8(obj->model[2], obj->scale.x, obj->scale.y, obj->scale.z);
    obj->func_ptr = func_8010E668_265768_ChanceTime;
}

void func_8010E668_265768_ChanceTime(omObjData* obj) {
    if (D_801101C0_2672C0_ChanceTime == 0) {
        if (obj->trans.x > -180.0f && obj->trans.x < 180.0f && D_80110068_267168_ChanceTime == 1) {
            func_8000BF24_CB24(obj, 10.0f, -2000.0f, -2000.0f, 2000.0f, 2000.0f);
            func_8000BFF0_CBF0(obj);
            D_801101C0_2672C0_ChanceTime = 1;
        }
    }
}
void func_8010E71C_26581C_ChanceTime(omObjData* obj) {
    CTBoxWork* work;

    work = func_80027154_27D54(sizeof(CTBoxWork), 0x7918);
    obj->unk_50 = work;
    func_800B0EF0_B1AF0(work, 0, sizeof(CTBoxWork));
    work->unk_03 = 1;
    work->unk_04 = 1;
    work->unk_08 = 0.5f;
    func_8000BF24_CB24(obj, 10.0f, -2000.0f, -2000.0f, 2000.0f, 2000.0f);
    func_8000BFF0_CBF0(obj);
    obj->func_ptr = NULL;
}
