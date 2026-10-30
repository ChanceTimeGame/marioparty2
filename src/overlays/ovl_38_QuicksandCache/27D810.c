#include "ovl_38.h"

#ifdef NON_MATCHING
/* Logic complete; retail keeps the 0/1 index as a branch where GCC here folds it to a store-flag. */
void func_80105CE0_27D810_QuicksandCache(omObjData* obj, s32 file, f32 a2) {
    void* p;
    QCActor* a;
    s32 i;
    s32* slot;
    s16 m;

    p = func_80027154_27D54(sizeof(QCActor), 0x7918);
    obj->unk_50 = p;
    func_800B0EF0_B1AF0(p, 0, sizeof(QCActor));
    a = obj->unk_50;
    if (file != 0xE) {
        i = 1;
        goto have;
    }
    i = 0;
have:
    slot = &D_801077CC_27F2FC_QuicksandCache[i];
    if (*slot == -1) {
        func_8000C11C_CD1C(obj, file, 0xABD, 8);
        *slot = a->unk_55;
    } else {
        a->unk_55 = func_8002109C_21C9C((s16)D_801077CC_27F2FC_QuicksandCache[i], 8);
        obj->model[0] = D_800F86D8_F92D8[a->unk_55].unk00;
        HmfModelObjAttrSet(obj->model[0], 0x70000000, 0x70000000);
    }
    func_8000C2A0_CEA0(obj, 3, 0x14, 0xABD, 8);
    func_800211E8_21DE8(a->unk_24, 0xF0);
    func_80021250_21E50(a->unk_24, 0xFF, 0xFF, 0xBE);
    if (D_801077D4_27F304_QuicksandCache == -1) {
        m = func_80018A64_19664(0xD, 0x63D);
        obj->model[1] = m;
        D_801077D4_27F304_QuicksandCache = m;
        a->unk_44 = 0.0f;
    } else {
        obj->model[1] = func_80027D3C_2893C((s16)D_801077D4_27F304_QuicksandCache);
        a->unk_44 = 0.0f;
    }
    a->unk_48 = 20.0f;
    a->unk_34 = 50.0f;
    a->unk_3C = a2;
    a->unk_78 = 0;
    a->unk_52 = 3;
    a->unk_7C = 0x7D0;
    a->unk_50 = 0;
    a->unk_40 = 2.5f;
    a->unk_58 = 1.2f;
    a->unk_56 = D_801077C8_27F2F8_QuicksandCache++;
    a->unk_54 = 0;
    if (file == 0xE) {
        func_8000C37C_CF7C(obj, 2.0f, 2.0f, 2.0f);
    } else {
        func_8000C37C_CF7C(obj, 3.0f, 3.0f, 3.0f);
    }
    func_800297E8_2A3E8(obj->model[1], 0.2f, 0.2f, 0.2f);
    {
        s16 j;

        for (j = 0; j < 9; j++) {
            a->unk_84[j] = NULL;
        }
    }
    func_800298A4_2A4A4(obj->model[0], 4, 4);
    func_800298A4_2A4A4(obj->model[1], 4, 4);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_38_QuicksandCache/27D810", func_80105CE0_27D810_QuicksandCache);
#endif

void func_80105F9C_27DACC_QuicksandCache(omObjData* obj) {
    QCActor* a = obj->unk_50;
    f32 x = obj->trans.x;
    f32 z = obj->trans.z;

    a->unk_3C = -func_800B75A8_B81A8(x, -z);
    a->unk_40 = func_800B1830_B2430(x * x + z * z) / 750.0f * 6.0f;
    func_80000530_1130(obj);
}

void func_80106038_27DB68_QuicksandCache(void) {
}

void func_80106040_27DB70_QuicksandCache(omObjData* obj) {
    func_80105CE0_27D810_QuicksandCache(obj, 0xE, D_801077D8_27F308_QuicksandCache);
    D_801077D8_27F308_QuicksandCache += 35.0f;
    obj->func_ptr = func_80106038_27DB68_QuicksandCache;
}

void func_8010609C_27DBCC_QuicksandCache(omObjData* obj) {
    func_80105CE0_27D810_QuicksandCache(obj, 0x25, D_801077DC_27F30C_QuicksandCache);
    D_801077DC_27F30C_QuicksandCache += 35.0f;
    obj->func_ptr = func_80106038_27DB68_QuicksandCache;
}

#ifdef NON_MATCHING
/* Logic complete; register allocation only (full/i swapped). */
void func_801060F8_27DC28_QuicksandCache(void) {
    s32 full = 1;
    s8 i;
    omObjData* obj;
    QCActor* a;
    f32 ang;

    for (i = 0; i < 4; i++) {
        obj = D_800F9CE0_FA8E0[i];
        a = obj->unk_50;
        if (a->unk_54 != 1) {
            full = 0;
            break;
        }
    }
    if (full != 1) {
        func_8000C024_CC24(obj, 0, 2);
        func_8000C024_CC24(obj, 1, 1);
        ang = (f32)(guRandom() % 3600) / 10.0f;
        {
            f32 x = -HuMathSin(ang) * 750.0f;
            f32 z = func_800B7890_B8490(ang) * 750.0f;

            obj->trans.x = x;
            obj->trans.y = 1200.0f;
            obj->trans.z = z;
        }
        a->unk_54 = 1;
        a->unk_3C = ang - 180.0f;
        a->unk_52 = 3;
        a->unk_40 = 2.5f;
        a->unk_7C = 0x7D0;
        func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
        func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
        func_800298A4_2A4A4(obj->model[0], 4, 0);
        func_800298A4_2A4A4(obj->model[1], 4, 0);
        obj->func_ptr = func_80105F9C_27DACC_QuicksandCache;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_38_QuicksandCache/27D810", func_801060F8_27DC28_QuicksandCache);
#endif

void func_801062F0_27DE20_QuicksandCache(void) {
    omObjData* obj = D_800F9CE0_FA8E0[0];
    QCActor* a = obj->unk_50;
    f32 ang;
    f32 x;
    f32 z;

    func_8000C024_CC24(obj, 0, 2);
    func_8000C024_CC24(obj, 1, 1);
    ang = 210.0f;
    x = -HuMathSin(ang) * 350.0f;
    z = func_800B7890_B8490(ang) * 350.0f;
    obj->trans.x = x;
    obj->trans.y = 800.0f;
    obj->trans.z = z;
    a->unk_54 = 1;
    a->unk_3C = 30.0f;
    a->unk_52 = 3;
    a->unk_40 = 4.0f;
    a->unk_7C = 0x7D0;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800298A4_2A4A4(obj->model[0], 4, 0);
    func_800298A4_2A4A4(obj->model[1], 4, 0);
    obj->func_ptr = func_80105F9C_27DACC_QuicksandCache;
}

void func_80106440_27DF70_QuicksandCache(void) {
    omObjData* obj = D_800F9CE0_FA8E0[4];
    QCActor* a = obj->unk_50;
    f32 ang;
    f32 x;
    f32 z;

    if (D_801077C4_27F2F4_QuicksandCache > 0x70 && a->unk_54 == 0 && D_801077C0_27F2F0_QuicksandCache < 4) {
        D_801077C0_27F2F0_QuicksandCache++;
        D_801077C4_27F2F4_QuicksandCache = 0;
        func_8000C024_CC24(obj, 0, 2);
        func_8000C024_CC24(obj, 1, 1);
        ang = (f32)(guRandom() % 3600) / 10.0f;
        x = -HuMathSin(ang) * 750.0f;
        z = func_800B7890_B8490(ang) * 750.0f;
        obj->trans.x = x;
        obj->trans.y = 1200.0f;
        obj->trans.z = z;
        a->unk_54 = 1;
        a->unk_3C = ang - 180.0f;
        a->unk_52 = 6;
        a->unk_40 = 2.5f;
        a->unk_7C = 0x7D0;
        func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
        func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
        func_800298A4_2A4A4(obj->model[0], 4, 0);
        func_800298A4_2A4A4(obj->model[1], 4, 0);
        obj->func_ptr = func_80105F9C_27DACC_QuicksandCache;
    }
    D_801077C4_27F2F4_QuicksandCache++;
}

void func_80106648_27E178_QuicksandCache(void) {
    s8 i;
    omObjData* coin;
    QCActor* a;
    u8 id;
    u8 m;

    for (i = 0; i < 5; i++) {
        coin = D_800F9CE0_FA8E0[i];
        a = coin->unk_50;
        if (a->unk_54 == 1) {
            a->unk_54 = 0;
            a->unk_78 = 0;
            func_800298A4_2A4A4(coin->model[0], 4, 4);
            func_800298A4_2A4A4(coin->model[1], 4, 4);
            id = a->unk_24;
            m = coin->model[3];
            func_800298A4_2A4A4(m, 4, 0);
            func_80021198_21D98(id, 0);
            func_80021160_21D60(id, 4, 4);
            func_80029714_2A314(m, coin->trans.x, coin->trans.y, coin->trans.z);
            func_800297E8_2A3E8(m, 5.0f, 5.0f, 5.0f);
        }
    }
}
