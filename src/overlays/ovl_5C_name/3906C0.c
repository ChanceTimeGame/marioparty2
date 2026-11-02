#include "ovl_5C.h"

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_80102800_3906C0_name_5C);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_80102AB0_390970_name_5C);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_80102B78_390A38_name_5C);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_80103770_391630_name_5C);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_801038A8_391768_name_5C);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_8010392C_3917EC_name_5C);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_801039A8_391868_name_5C);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_80103A10_3918D0_name_5C);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_80103A54_391914_name_5C);

__asm__(".section .rodata");
const u32 D_801121C8_3A0088_name_5C[3] = { 0x00020004, 0x00060008, 0x0009000A };

__asm__(".section .rodata");
const u32 D_801121D4_3A0094_name_5C[18] = { 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x424D8000, 0x43188000, 0x00000000, 0x424D8000, 0x43144000, 0x00000000, 0x424D8000, 0x42920000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_80103B30_3919F0_name_5C);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_80103D08_391BC8_name_5C);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_80103E1C_391CDC_name_5C);

__asm__(".section .rodata");
const u32 D_80112220_3A00E0_name_5C[2] = { 0x05256405, 0x00000000 };

__asm__(".section .rodata");
const u32 D_80112228_3A00E8_name_5C[2] = { 0x05253032, 0x64050000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_80104484_392344_name_5C);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_80104F88_392E48_name_5C);

s16 func_801054F0_3933B0_name_5C(s16 x, s16 y) {
    s16 win = func_800888A8_894A8(x, y, 200, 32, 0, 8);

    func_80089A7C_8A67C(win, 5);
    func_80089284_89E84(win, 32, 32);
    func_80089BBC_8A7BC(win, 0);
    func_80089B2C_8A72C(win, 0);
    func_8008D5D8_8E1D8(win);
    func_80089A48_8A648(win, 0);
    func_80089C78_8A878(win, 1);
    func_80089DA0_8A9A0(win, 192, 192, 192);
    func_800890CC_89CCC(win, (void*)0x3AF, -2, -1);
    return win;
}

s16 func_801055BC_39347C_name_5C(s16 x, s16 y) {
    s16 win = func_800888A8_894A8(x, y, 200, 20, 0, 8);

    func_80089A7C_8A67C(win, 5);
    func_80089284_89E84(win, 32, 32);
    func_8008D5D8_8E1D8(win);
    func_80089BBC_8A7BC(win, 0);
    func_80089B2C_8A72C(win, 0);
    func_80089A48_8A648(win, 0);
    func_80089C78_8A878(win, 1);
    func_80089DA0_8A9A0(win, 192, 192, 192);
    func_800890CC_89CCC(win, (void*)0x535, -2, -1);
    return win;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_80105688_393548_name_5C);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_80105DB0_393C70_name_5C);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_80105DD0_393C90_name_5C);

void func_801062AC_39416C_name_5C(s16 cursor, s8 active) {
    D_80112350_3A0210_name_5C[cursor]->active = active;
}

void func_801062C8_394188_name_5C(s16 cursor, s16 slot) {
    Ovl5CCursor* c = D_80112350_3A0210_name_5C[cursor];

    c->x = c->slots[slot][0];
    c->y = c->slots[slot][1];
    c->prevSel = slot;
    c->sel = slot;
    D_80112350_3A0210_name_5C[cursor]->done = 0;
    D_80112458_3A0318_name_5C[slot] = cursor;
}

void func_80106348_394208_name_5C(s16 cursor, s16 slot) {
    D_80112350_3A0210_name_5C[cursor]->sel = slot;
    D_80112458_3A0318_name_5C[slot] = cursor;
}

s16 func_80106378_394238_name_5C(s16 cursor) {
    return D_80112350_3A0210_name_5C[cursor]->done;
}

void func_80106394_394254_name_5C(s16 cursor, s16 done) {
    D_80112350_3A0210_name_5C[cursor]->done = done;
}

s16 func_801063B0_394270_name_5C(s16 cursor) {
    return D_80112350_3A0210_name_5C[cursor]->sel;
}

void func_801063CC_39428C_name_5C(s16 (*slots)[2], s8 count) {
    s16 i;

    for (i = 0; i < 5; i++) {
        D_80112350_3A0210_name_5C[i]->slots = slots;
        D_80112350_3A0210_name_5C[i]->count = count;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_80106418_3942D8_name_5C);

void func_801064D4_394394_name_5C(s32 mes) {
    func_800890CC_89CCC(D_8011236A_3A022A_name_5C, (void*)mes, -1, -1);
}

s32 func_80106500_3943C0_name_5C(void) {
    while (func_8008BA30_8C630(D_8011236A_3A022A_name_5C) != 0) {
        HuPrcVSleep();
    }
    if (D_800F920C_F9E0C[D_8011236A_3A022A_name_5C].unk_30 != 0) {
        return func_8008BB48_8C748(D_8011236A_3A022A_name_5C, 0, 0);
    }
    return 0;
}

void func_80106588_394448_name_5C(void) {
    func_8008E2DC_8EEDC(D_8011236A_3A022A_name_5C, 1);
}

void func_801065AC_39446C_name_5C(void) {
    func_8008E4D0_8F0D0(D_8011236A_3A022A_name_5C, 1);
}

void func_801065D0_394490_name_5C(char* str) {
    func_80089308_89F08(D_8011236A_3A022A_name_5C, str, 0);
}

void func_801065F8_3944B8_name_5C(void) {
    func_8008AD44_8B944(D_8011236A_3A022A_name_5C);
}

#ifdef NON_MATCHING
void func_80106618_3944D8_name_5C(s16 model, s32 spr, char* part) {
    f32 mtx[4][4];

    func_80023554_24154(model, func_80029CE4_2A8E4(model), part, mtx);
    func_801098A4_397764_name_5C(model, &D_80112A04_3A08C4_name_5C, mtx);
    espPosSet(spr, D_80112A04_3A08C4_name_5C.unk_00, D_80112A04_3A08C4_name_5C.unk_04);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_80106618_3944D8_name_5C);
#endif

#ifdef NON_MATCHING
void func_801066D4_394594_name_5C(s32 model, s32 spr, char* part) {
    void* obj;

    if (D_800FC834_FD434[(s16)model].hmf->unk84 != (void*)-1) {
        obj = func_8002A9F4_2B5F4(model, part);
        func_801098A4_397764_name_5C(model, &D_80112A04_3A08C4_name_5C, ((HmfMotionObj*)obj)->unk58);
    } else {
        obj = func_8002A9F4_2B5F4(model, part);
        func_801098A4_397764_name_5C(model, &D_80112A04_3A08C4_name_5C, ((HitXform*)obj)->unk4C);
    }
    espPosSet(spr, D_80112A04_3A08C4_name_5C.unk_00, D_80112A04_3A08C4_name_5C.unk_04);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_801066D4_394594_name_5C);
#endif

void func_801067BC_39467C_name_5C(s16 i, s16 esp, s32 dx, s32 dy) {
    D_80112FB0_3A0E70_name_5C[i].x = ((Ovl5CEsprite*)D_800F93FC_F9FFC)[esp].x + dx;
    D_80112FB0_3A0E70_name_5C[i].y = ((Ovl5CEsprite*)D_800F93FC_F9FFC)[esp].y + dy;
}

void func_80106810_3946D0_name_5C(s16 i, Vec2f* pos, s16 dx, s16 dy) {
    D_80112FB0_3A0E70_name_5C[i].x = dx + pos->unk_00;
    D_80112FB0_3A0E70_name_5C[i].y = dy + pos->unk_04;
}

void func_8010687C_39473C_name_5C(void) {
    s16 i;

    for (i = 0; i < 30; i++) {
        D_80112458_3A0318_name_5C[i] = -1;
    }
}

#ifdef NON_MATCHING
s16 func_801068BC_39477C_name_5C(s16 cur, s16 n, s16 dx, s16 dy) {
    Vec2f dir[30];
    f32 dist[30];
    f32 x;
    f32 y;
    f32 len;
    f32 ux;
    f32 uy;
    f32 best;
    s16 i;
    s16 found;

    for (i = 0; i < n; i++) {
        if (i == cur || D_80112458_3A0318_name_5C[i] != -1) {
            dist[i] = -1.0f;
        } else {
            x = D_80112FB0_3A0E70_name_5C[cur].x - D_80112FB0_3A0E70_name_5C[i].x;
            y = D_80112FB0_3A0E70_name_5C[cur].y - D_80112FB0_3A0E70_name_5C[i].y;
            dist[i] = len = func_800B1830_B2430(x * x + y * y);
            dir[i].unk_00 = x / len;
            dir[i].unk_04 = y / len;
        }
    }
    len = func_800B1830_B2430(dx * dx + dy * dy);
    ux = dx / len;
    uy = dy / len;
    for (i = 0; i < n; i++) {
        if (dist[i] < 0.0f) {
            continue;
        }
        x = ux - dir[i].unk_00;
        y = uy - dir[i].unk_04;
        if (func_800B1830_B2430(x * x + y * y) > 0.5f) {
            dist[i] = -1.0f;
        }
    }
    best = 100000.0f;
    found = -1;
    for (i = 0; i < n; i++) {
        if (dist[i] < 0.0f) {
            continue;
        }
        if (dist[i] < best) {
            best = dist[i];
            found = i;
        }
    }
    return found;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_801068BC_39477C_name_5C);
#endif

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_80106C0C_394ACC_name_5C);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_80106D70_394C30_name_5C);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_80106DE4_394CA4_name_5C);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_80106EB8_394D78_name_5C);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_80107058_394F18_name_5C);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/3906C0", func_801071E4_3950A4_name_5C);
