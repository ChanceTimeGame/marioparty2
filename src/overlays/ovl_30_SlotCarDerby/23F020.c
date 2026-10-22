#include "ovl_30.h"
#include "game/malloc.h"
#include "game/data.h"

/* Retail calls SprBankSet with a signed bank (lh of the s32 table's low half). */
#define SCD_SPR_BANK_SET ((void (*)(s16, s16, s16))SprBankSet)

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
    SCD_SPR_BANK_SET((s16)D_80110974_246854_SlotCarDerby, 0, (s16)D_8010FB84_245A64_SlotCarDerby[0]);
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
        SCD_SPR_BANK_SET((s16)D_80110974_246854_SlotCarDerby, i, (s16)D_8010FB84_245A64_SlotCarDerby[i]);
        func_8008225C_82E5C((s16)D_80110974_246854_SlotCarDerby, i, 0);
        SprAttrSet((s16)D_80110974_246854_SlotCarDerby, i, 0x1000);
    }
    SCD_SPR_BANK_SET((s16)D_80110970_246850_SlotCarDerby, 5, (s16)D_8010FB84_245A64_SlotCarDerby[5]);
    SCD_SPR_BANK_SET((s16)D_80110970_246850_SlotCarDerby, 6, (s16)D_8010FB84_245A64_SlotCarDerby[6]);
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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/23F020", func_80109CDC_23FBBC_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/23F020", func_80109EC0_23FDA0_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/23F020", func_8010A190_240070_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/23F020", func_8010A55C_24043C_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/23F020", func_8010A8CC_2407AC_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/23F020", func_8010AC5C_240B3C_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/23F020", func_8010AD94_240C74_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/23F020", func_8010ADB0_240C90_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/23F020", func_8010B098_240F78_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/23F020", func_8010B0B8_240F98_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/23F020", func_8010B0E4_240FC4_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/23F020", func_8010B4D0_2413B0_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/23F020", func_8010B688_241568_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/23F020", func_8010C8D4_2427B4_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/23F020", func_8010C914_2427F4_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/23F020", func_8010C954_242834_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/23F020", func_8010C9A4_242884_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/23F020", func_8010C9F4_2428D4_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/23F020", func_8010CA44_242924_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/23F020", func_8010CA88_242968_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/23F020", func_8010CAD0_2429B0_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/23F020", func_8010CB1C_2429FC_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/23F020", func_8010CC3C_242B1C_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/23F020", func_8010D0B0_242F90_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/23F020", func_8010D590_243470_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/23F020", func_8010D644_243524_SlotCarDerby);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/23F020", func_8010D68C_24356C_SlotCarDerby);

__asm__(".section .rodata");
const u32 D_80110210_2460F0_SlotCarDerby[6] = { 0x00000028, 0x00000029, 0x0000002A, 0x0000002B, 0x0000002C, 0x0000002D };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/23F020", func_8010D6DC_2435BC_SlotCarDerby);

__asm__(".section .rodata");
const char D_80110228_246108_SlotCarDerby[] = "";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_30_SlotCarDerby/23F020", func_8010DAD8_2439B8_SlotCarDerby);
