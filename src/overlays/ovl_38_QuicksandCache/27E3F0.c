#include "ovl_38.h"

__asm__(".section .rodata");
const f32 D_80107910_27F440_QuicksandCache[3] = { 0.5f, 0.7f, 0.8f };

__asm__(".section .rodata");
const f32 D_8010791C_27F44C_QuicksandCache[3] = { 2.0f, 4.0f, 7.0f };

void func_801068C0_27E3F0_QuicksandCache(omObjData* obj) {
    QCSand* s = obj->unk_50;
    s8 i;
    f32 t;

    func_8002BED4_2CAD4(obj->model[2], 0.0f, -s->unk_0C[0], 0x40, 0x40, "178-m175_01_2", 0);
    func_8002BED4_2CAD4(obj->model[3], 0.0f, -s->unk_0C[1], 0x40, 0x40, "178-m175_02_1_1", 0);
    func_8002BED4_2CAD4(obj->model[4], 0.0f, -s->unk_0C[2], 0x40, 0x40, "178-m175_03_1_1", 0);
    if (D_801077F0_27F320_QuicksandCache == 0 && D_80107777_27F2A7_QuicksandCache == 1) {
        D_801079D0_27F500_QuicksandCache =
            func_80079798_7A398(0x2FB, ((MgWork*)D_80108020_27FB50_QuicksandCache->unk_50)->unk_59);
        D_801077F0_27F320_QuicksandCache = 1;
    }
    if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        for (i = 0; i < 3; i++) {
            s->unk_0C[i] += D_80107910_27F440_QuicksandCache[i];
            if (s->unk_0C[i] > 32.0f) {
                s->unk_0C[i] -= 32.0f;
            }
        }
        for (i = 0; i < 3; i++) {
            if (D_80107776_27F2A6_QuicksandCache >= 5) {
                s->unk_18[i] -= D_8010791C_27F44C_QuicksandCache[i] * s->unk_24 / 15.0f;
            }
            s->unk_18[i] *= 0.98f;
            if (s->unk_18[i] < -D_8010791C_27F44C_QuicksandCache[i]) {
                s->unk_18[i] = -D_8010791C_27F44C_QuicksandCache[i];
            } else if (s->unk_18[i] > D_8010791C_27F44C_QuicksandCache[i]) {
                s->unk_18[i] = D_8010791C_27F44C_QuicksandCache[i];
            }
            s->unk_00[i] += s->unk_18[i];
            if (s->unk_00[i] >= 360.0f) {
                s->unk_00[i] -= 360.0f;
            } else if (s->unk_00[i] < 0.0f) {
                s->unk_00[i] += 360.0f;
            }
        }
        if (D_80107777_27F2A7_QuicksandCache == 1) {
            t = s->unk_18[2] / D_8010791C_27F44C_QuicksandCache[2] > 0.0f
                    ? s->unk_18[2] / D_8010791C_27F44C_QuicksandCache[2]
                    : -s->unk_18[2] / D_8010791C_27F44C_QuicksandCache[2];
            func_800796F0_7A2F0(D_801079D0_27F500_QuicksandCache, t * 600.0f);
            func_800795D8_7A1D8(D_801079D0_27F500_QuicksandCache, t * 127.0f);
        }
        func_8002979C_2A39C(obj->model[2], 0.0f, s->unk_00[0], 0.0f);
        func_8002979C_2A39C(obj->model[3], 0.0f, s->unk_00[1], 0.0f);
        func_8002979C_2A39C(obj->model[4], 0.0f, s->unk_00[2], 0.0f);
    }
}

#ifdef NON_MATCHING
/* Logic complete; register allocation only (obj/s swapped). */
void func_80106CC0_27E7F0_QuicksandCache(omObjData* obj) {
    s8 i;
    QCSand* s;

    obj->unk_50 = s = func_80027154_27D54(sizeof(QCSand), 0x7918);
    func_800B0EF0_B1AF0(s, 0, sizeof(QCSand));
    for (i = 0; i < 3; i++) {
        s->unk_00[i] = 0.0f;
        s->unk_0C[i] = 0.0f;
        s->unk_18[i] = 0.0f;
    }
    s->unk_24 = 0.0f;
    obj->model[0] = -1;
    obj->model[1] = LoadFormFile(0x480001, 0x2B9);
    obj->model[2] = LoadFormFile(0x480002, 0x202B9);
    obj->model[3] = LoadFormFile(0x480003, 0x202B9);
    obj->model[4] = LoadFormFile(0x480004, 0x202B9);
    obj->model[5] = LoadFormFile(0x480005, 0x2B9);
    func_8002A00C_2AC0C(obj->model[2]);
    func_8002A00C_2AC0C(obj->model[3]);
    func_8002A00C_2AC0C(obj->model[4]);
    func_80029714_2A314(obj->model[1], 0.0f, 0.0f, 0.0f);
    func_80029714_2A314(obj->model[2], 0.0f, 0.0f, 0.0f);
    func_80029714_2A314(obj->model[3], 0.0f, 0.0f, 0.0f);
    func_80029714_2A314(obj->model[4], 0.0f, 0.0f, 0.0f);
    obj->func_ptr = func_801068C0_27E3F0_QuicksandCache;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_38_QuicksandCache/27E3F0", func_80106CC0_27E7F0_QuicksandCache);
#endif

void func_80106E68_27E998_QuicksandCache(omObjData* obj) {
    GroundWork* g = func_80027154_27D54(0xB4, 0x7918);

    obj->unk_50 = g;
    func_800B0EF0_B1AF0(g, 0, 0xB4);
    g->unk_03 = 1;
    g->unk_04 = 0;
    obj->model[0] = func_80018A30_19630(0x480000, 0x202B9);
    obj->trans.x = 0.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 0.0f;
    func_8000BEA4_CAA4(obj, 1.0f);
    func_8000BE8C_CA8C(obj, 0.5f);
    func_800298A4_2A4A4(obj->model[0], 4, 4);
    obj->func_ptr = NULL;
}

void func_80106F14_27EA44_QuicksandCache(omObjData* obj) {
    GroundWork* g = func_80027154_27D54(0xB4, 0x7918);

    obj->unk_50 = g;
    func_800B0EF0_B1AF0(g, 0, 0xB4);
    g->unk_03 = 1;
    g->unk_04 = 1;
    obj->model[0] = -1;
    obj->trans.x = 0.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 0.0f;
    func_8000BEA4_CAA4(obj, 1.0f);
    func_8000BE8C_CA8C(obj, 0.5f);
    func_800298A4_2A4A4(obj->model[0], 4, 4);
    func_8000BF8C_CB8C(obj, 0, 700.0f);
    obj->func_ptr = NULL;
}

void func_80106FC4_27EAF4_QuicksandCache(void) {
    QCSpr* p = D_801079E0_27F510_QuicksandCache;
    u32 i;

    for (i = 0; i < 20; i++) {
        p->unk_00 = 0;
        p->unk_04 = 0;
        p->unk_08[0] = 0;
        p->unk_08[1] = 0;
        p->unk_08[2] = 0;
        p->unk_08[3] = 0;
        p->unk_08[4] = 0;
        p->unk_08[5] = 0;
        p->unk_20[0] = 0;
        p->unk_20[1] = 0;
        p->unk_20[2] = 0;
        p->unk_20[3] = 0;
        p->unk_20[4] = 0;
        p->unk_20[5] = 0;
        p->unk_20[6] = 0;
        p->unk_20[7] = 0;
        p->unk_20[8] = 0;
        p->unk_20[9] = 0;
        p->unk_20[10] = 0;
        p->unk_20[11] = 0;
        p->unk_38[0] = 0;
        p->unk_38[1] = 0;
        p->unk_38[2] = 0;
        p->unk_38[3] = 0;
        p++;
    }
}

void func_80107048_27EB78_QuicksandCache(void) {
    s16* p = D_80107F80_27FAB0_QuicksandCache;
    u32 i;

    for (i = 0; i < 50; i++) {
        *p++ = -1;
    }
}

void func_80107074_27EBA4_QuicksandCache(QCSpr* spr, s16 idx, u16 anim, u16 x, u16 y) {
    D_80107F80_27FAB0_QuicksandCache[(u16)(idx + 10)] = anim;
    SprAnimSet(spr->unk_04, idx, anim, 0);
    SprAttrSet(spr->unk_04, idx, 0x1000);
    SprPosSet(spr->unk_04, idx, x, y);
    SprPrioSet(spr->unk_04, idx, 0xFFF4);
}

#ifdef NON_MATCHING
/* Logic complete; digit slot arithmetic is scheduled differently. */
void func_8010712C_27EC5C_QuicksandCache(omObjData* obj) {
    s16 i;
    QCScore* s;
    QCSpr* spr = D_801079E0_27F510_QuicksandCache;
    u16 v;
    s16 slot;
    s32 d;
    s32 shown;
    f32 sc;

    for (i = 0; i < 4; i++) {
        s = &D_80107FE8_27FB18_QuicksandCache[i];
        s->unk_00 = gPlayers[i].coins_mg;
        switch (s->unk_04) {
        case 0:
            if (s->unk_02 != s->unk_00) {
                if (s->unk_02 < s->unk_00) {
                    v = s->unk_02 + 1;
                } else {
                    v = s->unk_02 - 1;
                }
                shown = 0;
                slot = i * 3 + 0xC;
                d = v / 100;
                if ((u16)d != 0) {
                    SprBankSet(spr->unk_04, slot++, d);
                    shown = 1;
                } else {
                    SprAttrSet(spr->unk_04, slot + 2, 0x8000);
                }
                d = (u16)(v % 100) / 10;
                if ((u16)d == 0) {
                    if (shown != 0) {
                        goto bank;
                    }
                    SprAttrSet(spr->unk_04, slot + 1, 0x8000);
                } else {
                bank:
                    SprBankSet(spr->unk_04, slot++, d);
                }
                SprBankSet(spr->unk_04, slot, v % 10);
                SprAttrReset(spr->unk_04, slot, 0x8000);
                s->unk_02 = v;
                s->unk_04 = 1;
            }
            break;
        case 1:
            slot = i + 4;
            s->unk_08 += 40.0f;
            if (s->unk_08 > 180.0f) {
                s->unk_08 = 0.0f;
                s->unk_04 = 0;
            }
            sc = func_800B80D0_B8CD0(s->unk_08) + 1.0;
            SprScaleSet(spr->unk_04, slot, sc, sc);
            break;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_38_QuicksandCache/27E3F0", func_8010712C_27EC5C_QuicksandCache);
#endif

__asm__(".section .rodata");
const s32 D_80107960_27F490_QuicksandCache[6] = { 0x00000028, 0x00000029, 0x0000002A, 0x0000002B, 0x0000002C, 0x0000002D };

__asm__(".section .rodata");
const u16 D_80107978_27F4A8_QuicksandCache[4][2] = { { 0x3C, 0x18 }, { 0x104, 0x18 }, { 0x3C, 0xCC }, { 0x104, 0xCC } };

__asm__(".section .rodata");
const u16 D_80107988_27F4B8_QuicksandCache[4][2] = { { 0x28, 0x24 }, { 0xF0, 0x24 }, { 0x28, 0xD8 }, { 0xF0, 0xD8 } };

__asm__(".section .rodata");
const u16 D_80107998_27F4C8_QuicksandCache[4][2] = { { 0x34, 0x24 }, { 0xFC, 0x24 }, { 0x34, 0xD8 }, { 0xFC, 0xD8 } };

__asm__(".section .rodata");
const u16 D_801079A8_27F4D8_QuicksandCache[4][2] = { { 0x40, 0x24 }, { 0x108, 0x24 }, { 0x40, 0xD8 }, { 0x108, 0xD8 } };

__asm__(".section .rodata");
const s8 D_801079B8_27F4E8_QuicksandCache[8] = { 0, 1, 2, 3, 0, 0, 0, 0 };

#ifdef NON_MATCHING
/* Logic complete; register allocation only (i/slot, next/last). */
void func_80107410_27EF40_QuicksandCache(omObjData* obj) {
    s16 i;
    QCSpr* spr = D_801079E0_27F510_QuicksandCache;
    u16 anim;
    s16 slot = 0;
    u16 x;
    u16 y;
    s16 next;
    s16 last;

    func_80106FC4_27EAF4_QuicksandCache();
    func_80107048_27EB78_QuicksandCache();
    func_800B0EF0_B1AF0(D_80107FE8_27FB18_QuicksandCache, 0, 0x30);
    spr->unk_04 = SprCreate(0x18, 0);
    for (i = 0; i < 4; i++) {
        func_80107074_27EBA4_QuicksandCache(spr, slot,
                                            func_8001A2F8_1AEF8(D_80107960_27F490_QuicksandCache[gPlayers[i].character]),
                                            D_80107978_27F4A8_QuicksandCache[D_801079B8_27F4E8_QuicksandCache[i]][0],
                                            D_80107978_27F4A8_QuicksandCache[D_801079B8_27F4E8_QuicksandCache[i]][1]);
        slot++;
    }
    anim = func_8001A2F8_1AEF8(0x480006);
    for (i = 0; i < 4; i++) {
        func_80107074_27EBA4_QuicksandCache(spr, slot, anim,
                                            D_80107988_27F4B8_QuicksandCache[D_801079B8_27F4E8_QuicksandCache[i]][0],
                                            D_80107988_27F4B8_QuicksandCache[D_801079B8_27F4E8_QuicksandCache[i]][1]);
        slot++;
    }
    anim = func_8001A2F8_1AEF8(0x170010);
    for (i = 0; i < 4; i++) {
        func_80107074_27EBA4_QuicksandCache(spr, slot, anim,
                                            D_80107998_27F4C8_QuicksandCache[D_801079B8_27F4E8_QuicksandCache[i]][0],
                                            D_80107998_27F4C8_QuicksandCache[D_801079B8_27F4E8_QuicksandCache[i]][1]);
        slot++;
    }
    anim = func_8001A2F8_1AEF8(0x43);
    for (i = 0; i < 4; i++) {
        next = slot + 1;
        y = D_801079A8_27F4D8_QuicksandCache[D_801079B8_27F4E8_QuicksandCache[i]][1];
        func_80107074_27EBA4_QuicksandCache(spr, slot, anim, D_801079A8_27F4D8_QuicksandCache[D_801079B8_27F4E8_QuicksandCache[i]][0], y);
        x = D_801079A8_27F4D8_QuicksandCache[D_801079B8_27F4E8_QuicksandCache[i]][0];
        func_80107074_27EBA4_QuicksandCache(spr, next, anim, x + 0xC, y);
        last = next + 1;
        SprAttrSet(spr->unk_04, next, 0x8000);
        func_80107074_27EBA4_QuicksandCache(spr, last, anim, x + 0x18, y);
        slot = next + 2;
        SprAttrSet(spr->unk_04, last, 0x8000);
    }
    obj->func_ptr = func_8010712C_27EC5C_QuicksandCache;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_38_QuicksandCache/27E3F0", func_80107410_27EF40_QuicksandCache);
#endif

void func_8010773C_27F26C_QuicksandCache(void) {
    omAddObj(0x19, 0, 0, -1, func_80107410_27EF40_QuicksandCache);
}
