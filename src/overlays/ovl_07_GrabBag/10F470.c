#include "ovl_07.h"

void func_80105E60_10F470_GrabBag(void) {
    s32 i;

    D_8010A7E0_113DF0_GrabBag = rand8() & 3;
    i = 0;
    func_8000C460_D060();
    D_800BF7A0_C03A0 = 0.2f;
    D_800FC87A_FD47A = 0;
    do {
        D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(2, 11, 50, -1, func_80105F4C_10F55C_GrabBag);
        omSetStatBit(D_800FFFD8_100BD8[i], 0xA0);
        i++;
    } while (i < 4);
    omAddObj(2, 0, 0, -1, func_80109940_112F50_GrabBag);
}

__asm__(".section .rodata");
const char D_8010A570_113B80_GrabBag[] = "karada_2_1_1_1";

__asm__(".section .rodata");
const char D_8010A580_113B90_GrabBag[] = "c001_000-karada_1";

__asm__(".section .rodata");
const char D_8010A594_113BA4_GrabBag[] = "C002_000b-cone7_1_1_1_1_1";

__asm__(".section .rodata");
const char D_8010A5B0_113BC0_GrabBag[] = "c003_000-yoshi_body_2_3";

__asm__(".section .rodata");
const char D_8010A5C8_113BD8_GrabBag[] = "Luigi1-karada_2_1_1";

__asm__(".section .rodata");
const char D_8010A5DC_113BEC_GrabBag[] = "c005_000-cyl1_1_3";

void func_80105F4C_10F55C_GrabBag(omObjData* obj) {
    s32 dir;
    s8 chr;
    s32 file;
    s32 flags;
    s32 corner;

    chr = gPlayers[D_8010A474_113A84_GrabBag[D_8010A470_113A80_GrabBag]].character;
    dir = D_800CD438_CE038[chr].unk_04;
    file = D_800CD438_CE038[chr].unk_08;
    corner = D_8010A484_113A94_GrabBag[D_8010A7E0_113DF0_GrabBag * 4 + D_8010A470_113A80_GrabBag];
    obj->trans.x = D_8010A494_113AA4_GrabBag[corner].x;
    obj->trans.y = D_8010A494_113AA4_GrabBag[corner].y;
    obj->trans.z = D_8010A494_113AA4_GrabBag[corner].z;
    func_8000C578_D178(1);
    func_80106624_10FC34_GrabBag(obj, dir, file, (u16)D_8010A474_113A84_GrabBag[D_8010A470_113A80_GrabBag], 0x2D9);
    ((GBPlayer*)obj->unk_50)->unk_15C = corner;
    obj->rot.y = func_800B75A8_B81A8(-obj->trans.x, -obj->trans.z);
    if (obj->rot.y < 0.0f) {
        obj->rot.y += 360.0f;
    } else if (obj->rot.y > 360.0f) {
        obj->rot.y -= 360.0f;
    }
    obj->model[3] = LoadFormFile(7, 0x2DD);
    obj->model[4] = LoadFormFile(8, 0x2DD);
    obj->model[6] = LoadFormFile(9, 0x2DD);
    obj->model[5] = LoadFormFile(0xA, 0x2DD);
    obj->model[7] = LoadFormFile(0xC, 0x2DD);
    obj->model[8] = LoadFormFile(0xB, 0x2DD);
    flags = 0x2D9;
    switch ((u32)dir >> 16) {
    case 2:
        obj->model[9] = LoadFormFile(0x170000, (u16)flags);
        obj->model[10] = LoadFormFile(0x170001, flags | 4);
        break;
    case 3:
        obj->model[9] = LoadFormFile(0x170002, (u16)flags);
        obj->model[10] = LoadFormFile(0x170003, flags | 4);
        break;
    case 7:
        obj->model[9] = LoadFormFile(0x170004, (u16)flags);
        obj->model[10] = LoadFormFile(0x170005, flags | 4);
        break;
    case 4:
        obj->model[9] = LoadFormFile(0x170006, (u16)flags);
        obj->model[10] = LoadFormFile(0x170007, flags | 4);
        break;
    case 5:
        obj->model[9] = LoadFormFile(0x170008, (u16)flags);
        obj->model[10] = LoadFormFile(0x170009, flags | 4);
        break;
    case 6:
        obj->model[9] = LoadFormFile(0x17000A, (u16)flags);
        obj->model[10] = LoadFormFile(0x17000B, flags | 4);
        break;
    }
    func_8002A00C_2AC0C(obj->model[9]);
    func_800298A4_2A4A4(obj->model[9], 0x4000, 0x4000);
    func_800298A4_2A4A4(obj->model[10], 0x4000, 0x4000);
    switch ((u32)dir >> 16) {
    case 2:
        func_8002C628_2D228(obj->model[9], obj->model[0], D_8010A570_113B80_GrabBag);
        func_8002C628_2D228(obj->model[10], obj->model[0], D_8010A570_113B80_GrabBag);
        break;
    case 3:
        func_8002C628_2D228(obj->model[9], obj->model[0], D_8010A580_113B90_GrabBag);
        func_8002C628_2D228(obj->model[10], obj->model[0], D_8010A580_113B90_GrabBag);
        break;
    case 7:
        func_8002C628_2D228(obj->model[9], obj->model[0], D_8010A594_113BA4_GrabBag);
        func_8002C628_2D228(obj->model[10], obj->model[0], D_8010A594_113BA4_GrabBag);
        break;
    case 4:
        func_8002C628_2D228(obj->model[9], obj->model[0], D_8010A5B0_113BC0_GrabBag);
        func_8002C628_2D228(obj->model[10], obj->model[0], D_8010A5B0_113BC0_GrabBag);
        break;
    case 5:
        func_8002C628_2D228(obj->model[9], obj->model[0], D_8010A5C8_113BD8_GrabBag);
        func_8002C628_2D228(obj->model[10], obj->model[0], D_8010A5C8_113BD8_GrabBag);
        break;
    case 6:
        func_8002C628_2D228(obj->model[9], obj->model[0], D_8010A5DC_113BEC_GrabBag);
        func_8002C628_2D228(obj->model[10], obj->model[0], D_8010A5DC_113BEC_GrabBag);
        break;
    }
    obj->func_ptr = func_80106C40_110250_GrabBag;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
    func_8002979C_2A39C(obj->model[0], obj->rot.x, obj->rot.y, obj->rot.z);
    func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    func_8000C024_CC24(obj, 0, 2);
    func_8000C024_CC24(obj, 1, 2);
    func_80019F0C_1AB0C(obj, 0, dir, 1, 0);
    func_80019F0C_1AB0C(obj, 1, dir | 1, 1, 0);
    func_80019F0C_1AB0C(obj, 2, dir | 2, 1, 0);
    func_80019F0C_1AB0C(obj, 5, dir | 3, 0, 0);
    func_80019F0C_1AB0C(obj, 6, dir | 4, 1, 0x13);
    func_80019F0C_1AB0C(obj, 0x11, dir | 0xF, 0, 0);
    func_80019F0C_1AB0C(obj, 0x15, dir | 0x2E, 0, 0);
    func_80019F0C_1AB0C(obj, 0x1E, dir | 0x2F, 0, 0);
    func_80019F0C_1AB0C(obj, 0x1F, dir | 0x30, 0, 0);
    func_80019E84_1AA84(obj, 0x20, dir | 0x31, 0, 0);
    func_80019F0C_1AB0C(obj, 9, dir | 0x51, 0, 0);
    func_80019F0C_1AB0C(obj, 0xC, dir | 0x58, 0, 0);
    func_80019F0C_1AB0C(obj, 0xD, dir | 0x4E, 1, 0x78);
    func_80019F0C_1AB0C(obj, 0xE, dir | 0x55, 1, 0x78);
    func_80019F0C_1AB0C(obj, 0x17, dir | 0x38, 1, 0);
    func_80019F0C_1AB0C(obj, 0x1D, dir | 0x24, 1, 0);
    func_80019B9C_1A79C(obj, 0);
    D_8010A470_113A80_GrabBag++;
}

/* NON_MATCHING: scheduling (class 4): two stores and a load swap places (masked 2) */
#ifdef NON_MATCHING
void func_80106624_10FC34_GrabBag(omObjData* obj, u32 dir, s32 file, u16 player, u16 flags) {
    GBPlayer* w;
    s32 i;
    s16 t;

    for (i = 0; i < obj->mdlcnt; i++) {
        obj->model[i] = 0;
    }
    obj->unk_50 = func_80027154_27D54(sizeof(GBPlayer), 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, sizeof(GBPlayer));
    w = obj->unk_50;
    w->w.unk_E8 = func_80027154_27D54(obj->mtncnt * 0xC, 0x7918);
    func_800B0EF0_B1AF0(w->w.unk_E8, 0, obj->mtncnt * 0xC);
    obj->model[0] = LoadFormFile(dir | file, flags);
    obj->model[1] = func_80018A64_19664(0xD, flags);
    func_8003C8E0_3D4E0(obj->model[1]);
    for (i = 0; i < obj->mtncnt; i++) {
        obj->motion[i] = -1;
    }
    for (i = 0; i < obj->mtncnt; i++) {
        ((s16(*)[6])w->w.unk_E8)[i][0] = ((s16(*)[6])w->w.unk_E8)[i][1] = 0;
    }
    w->w.unk_57 = gPlayers[D_8010A474_113A84_GrabBag[D_8010A470_113A80_GrabBag]].port;
    if (gPlayers[D_8010A474_113A84_GrabBag[D_8010A470_113A80_GrabBag]].flags & 1) {
        w->unk_15D = -1;
    } else if (!(gPlayers[D_8010A474_113A84_GrabBag[D_8010A470_113A80_GrabBag]].flags & 1)) {
        w->unk_15D = 1;
    }
    w->w.unk_52 = 0;
    w->w.unk_B4 = 1.0f;
    w->w.unk_D0 = 0xFFFF;
    w->w.unk_4C = 0.5f;
    w->w.unk_CC = 1.0f;
    w->w.unk_A0 = w->w.unk_9C = w->w.unk_A4 = 0.0f;
    w->w.unk_59 = player;
    w->w.unk_3C = func_800B75A8_B81A8(-obj->trans.x, -obj->trans.z);
    w->unk_15E = w->unk_165 = w->unk_163 = 0;
    w->unk_15F = -1;
    w->unk_176 = 0;
    func_8000BEB0_CAB0(obj, 60.0f);
    func_8000BEBC_CABC(obj, 150.0f);
    func_8000BEC8_CAC8(obj, 20.0f);
    func_8000BE74_CA74(obj, 1000.0f);
    w->unk_170 = w->unk_168 = 5;
    if (D_8010A82F_113E3F_GrabBag == w->w.unk_59) {
        w->unk_16A = 1;
        t = w->unk_168 + 2;
    } else {
        w->unk_16A = 0;
        t = w->unk_168;
    }
    w->unk_16E = w->unk_174 = t;
    w->unk_172 = w->unk_16C = gPlayers[D_8010A474_113A84_GrabBag[D_8010A470_113A80_GrabBag]].coins;
    if (w->unk_168 < D_8010A82A_113E3A_GrabBag) {
        func_8010A2CC_1138DC_GrabBag(w->w.unk_59, w->unk_168);
    } else {
        func_8010A2CC_1138DC_GrabBag(w->w.unk_59, D_8010A82A_113E3A_GrabBag);
    }
    w->unk_160 = w->unk_161 = w->unk_162 = w->unk_166 = w->unk_164 = 0;
    switch (dir >> 16) {
    case 6:
        w->w.unk_AC = 0.7f;
        break;
    case 4:
        w->w.unk_AC = 0.9f;
        break;
    case 5:
        w->w.unk_AC = 0.8f;
        break;
    default:
        w->w.unk_AC = 1.0f;
        break;
    }
    i = (dir >> 16) - 1;
    D_800BF7E4_C03E4[w->w.unk_59][0] = i + 0x33;
    D_800BF7E4_C03E4[w->w.unk_59][1] = i + 0x3A;
    D_800BF7E4_C03E4[w->w.unk_59][2] = i + 0x48;
    D_800BF7E4_C03E4[w->w.unk_59][3] = i + 0x41;
    D_800BF7E4_C03E4[w->w.unk_59][4] = i + 0x4F;
    D_800BF7E4_C03E4[w->w.unk_59][5] = i + 0x56;
    D_800BF7E4_C03E4[w->w.unk_59][6] = i + 0x5D;
    D_800BF7E4_C03E4[w->w.unk_59][7] = 0xA4;
    D_800BF7E4_C03E4[w->w.unk_59][8] = 0xA5;
    D_800BF7E4_C03E4[w->w.unk_59][9] = 0xA6;
    D_800BF7E4_C03E4[w->w.unk_59][10] = i + 0x64;
    D_800BF7E4_C03E4[w->w.unk_59][11] = i + 0x6B;
    D_800BF7E4_C03E4[w->w.unk_59][12] = 0xAA;
    D_800BF7E4_C03E4[w->w.unk_59][13] = 0xAC;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_07_GrabBag/10F470", func_80106624_10FC34_GrabBag);
#endif

/* NON_MATCHING: register allocation (class 4): retail loads D_8010A82F into a0 before the compare (masked 8) */
#ifdef NON_MATCHING
void func_80106C40_110250_GrabBag(omObjData* obj) {
    GBPlayer* w = obj->unk_50;
    s32 p;

    func_8010946C_112A7C_GrabBag(obj);
    if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        if (D_800F8FD0_F9BD0 == 0) {
            func_8010A1EC_1137FC_GrabBag();
            func_80019B9C_1A79C(obj, 0);
            func_80019378_19F78(obj);
            return;
        }
        if ((u32)(D_800F8FD0_F9BD0 - 2) < 2) {
            if (w->unk_16E - w->unk_16A * 2 < D_8010A82A_113E3A_GrabBag) {
                p = D_8010A82F_113E3F_GrabBag;
                if (p == w->w.unk_59) {
                    func_8010A2CC_1138DC_GrabBag(p, w->unk_168 + 2);
                } else {
                    func_8010A2CC_1138DC_GrabBag(w->w.unk_59, w->unk_168);
                }
            } else {
                p = D_8010A82F_113E3F_GrabBag;
                if (p == w->w.unk_59 && D_8010A82A_113E3A_GrabBag > 0) {
                    func_8010A2CC_1138DC_GrabBag(p, D_8010A82A_113E3A_GrabBag + 2);
                } else {
                    func_8010A2CC_1138DC_GrabBag(w->w.unk_59, D_8010A82A_113E3A_GrabBag);
                }
            }
            func_8010A108_113718_GrabBag();
            if (func_80069538_6A138() == 0 || (func_80069538_6A138() & 2)) {
                func_80106F00_110510_GrabBag(obj);
            }
            func_80007790_8390(obj);
        } else if (D_800F8FD0_F9BD0 == 1) {
            obj->rot.y = 0.0f;
            func_80107F10_111520_GrabBag(obj);
        } else {
            return;
        }
        if (w->w.unk_57 == 3) {
            func_801077E8_110DF8_GrabBag();
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_07_GrabBag/10F470", func_80106C40_110250_GrabBag);
#endif

void func_80106DD0_1103E0_GrabBag(void) {
    s32 n = 0;
    s32 i;

    for (i = 0; i < 4; i++) {
        n += gPlayers[i].coins_mg_bonus == 0;
    }
    if (n == 1) {
        D_8010A84C_113E5C_GrabBag = 0;
    } else {
        D_8010A84C_113E5C_GrabBag = 1;
    }
}

/* NON_MATCHING: register allocation (class 4): a2/a3 swap (masked 0) */
#ifdef NON_MATCHING
s8 func_80106E38_110448_GrabBag(s8 p) {
    s32 t[4];
    s32 i;
    s32 n;
    GBPlayer* w;

    for (i = 0; i < 4; i++) {
        w = D_800FFFD8_100BD8[i]->unk_50;
        t[i] = w->unk_16E;
    }
    if (t[0] == t[1] && t[0] == t[2] && t[0] == t[3]) {
        return 3;
    }
    w = D_800FFFD8_100BD8[p]->unk_50;
    n = 0;
    for (i = 0; i < 4; i++) {
        if (i != p) {
            n += w->unk_16E < t[i];
        }
    }
    return n;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_07_GrabBag/10F470", func_80106E38_110448_GrabBag);
#endif

/* NON_MATCHING: control flow (class 3): the ending music's tests branch differently and s3 is cleared at the top in retail (masked 42; calls agree) */
#ifdef NON_MATCHING
void func_80106F00_110510_GrabBag(omObjData* obj) {
    GBPlayer* w;
    s32 hit = 0;
    s32 i;
    f32 len;
    f32 x, z;
    f32 dx, dz;
    f32 r;
    omObjData* o;
    s32 best;
    s32 t;

    if (D_8010A4E8_113AF8_GrabBag == 0) {
        PlayMusic(0x39);
        D_8010A4E8_113AF8_GrabBag = 1;
    }
    w = obj->unk_50;
    func_800298A4_2A4A4(D_800F9CE0_FA8E0[D_8010A830_113E40_GrabBag]->model[0], 4, 4);
    func_800298A4_2A4A4(D_800F9CE0_FA8E0[D_8010A830_113E40_GrabBag]->model[1], 4, 4);
    if (obj->trans.y > 2.0f) {
        obj->trans.y -= 25.0f;
        if (obj->trans.y < 2.0f) {
            obj->trans.y = 2.0f;
        }
        return;
    }
    switch (D_8010A4E4_113AF4_GrabBag[w->w.unk_59]) {
    case 0:
        w->w.unk_40 = 0.0f;
        func_80019B9C_1A79C(obj, 0);
        D_8010A4E4_113AF4_GrabBag[w->w.unk_59] = 1;
        break;
    case 1:
        D_8010A7C0_113DD0_GrabBag.x = D_8010A494_113AA4_GrabBag[w->unk_15C].x - obj->trans.x;
        D_8010A7C0_113DD0_GrabBag.z = D_8010A494_113AA4_GrabBag[w->unk_15C].z - obj->trans.z;
        len = func_800B1830_B2430(D_8010A7C0_113DD0_GrabBag.x * D_8010A7C0_113DD0_GrabBag.x + D_8010A7C0_113DD0_GrabBag.z * D_8010A7C0_113DD0_GrabBag.z);
        if (len == 0.0f) {
            D_8010A4E4_113AF4_GrabBag[w->w.unk_59]++;
            break;
        }
        D_8010A7C0_113DD0_GrabBag.x /= len;
        D_8010A7C0_113DD0_GrabBag.z /= len;
        func_801076A0_110CB0_GrabBag(w, D_8010A7C0_113DD0_GrabBag.x, D_8010A7C0_113DD0_GrabBag.z, 20.0f);
        break;
    case 2:
        func_80019B9C_1A79C(obj, 2);
        D_8010A4E4_113AF4_GrabBag[w->w.unk_59] = 3;
        break;
    case 3:
        D_8010A7C0_113DD0_GrabBag.x = D_8010A494_113AA4_GrabBag[w->unk_15C].x - obj->trans.x;
        D_8010A7C0_113DD0_GrabBag.z = D_8010A494_113AA4_GrabBag[w->unk_15C].z - obj->trans.z;
        len = func_800B1830_B2430(D_8010A7C0_113DD0_GrabBag.x * D_8010A7C0_113DD0_GrabBag.x + D_8010A7C0_113DD0_GrabBag.z * D_8010A7C0_113DD0_GrabBag.z);
        if (w->w.unk_40 + 5.0f < len) {
            D_8010A7C0_113DD0_GrabBag.x /= len;
            D_8010A7C0_113DD0_GrabBag.z /= len;
            x = 2.0f * (HuMathSin(w->w.unk_3C) * w->w.unk_48) + obj->trans.x;
            z = 2.0f * (func_800B7890_B8490(w->w.unk_3C) * w->w.unk_48) + obj->trans.z;
            for (i = 0; i < 4; i++) {
                o = D_800FFFD8_100BD8[i];
                if (o != obj) {
                    dx = o->trans.x - x;
                    dz = o->trans.z - z;
                    r = 2.0f * w->w.unk_48;
                    if (func_800B1830_B2430(dx * dx + dz * dz) <= r) {
                        hit = 1;
                        break;
                    }
                }
            }
            if (hit == 1) {
                w->w.unk_3C = w->w.unk_3C + 2.0f;
            } else {
                w->w.unk_3C = func_801096E0_112CF0_GrabBag(w->w.unk_3C, D_8010A7C0_113DD0_GrabBag.x, D_8010A7C0_113DD0_GrabBag.z, 20.0f);
            }
            w->w.unk_40 = 5.0f;
            obj->trans.x += HuMathSin(w->w.unk_3C) * w->w.unk_40;
            obj->trans.z += func_800B7890_B8490(w->w.unk_3C) * w->w.unk_40;
            func_800B2060_B2C60(D_800FC834_FD434[obj->model[0]].mtx, 0.0f, w->w.unk_3C, 0.0f);
            func_8000C35C_CF5C(obj, obj->trans.x, obj->trans.y, obj->trans.z);
            func_80019378_19F78(obj);
        } else {
            w->w.unk_40 = 0.0f;
            func_80019B9C_1A79C(obj, 0);
            func_80019378_19F78(obj);
            D_8010A4E4_113AF4_GrabBag[w->w.unk_59] = 4;
        }
        if (D_8010A4EC_113AFC_GrabBag >= 0x3C0) {
            w->w.unk_40 = 0.0f;
            func_80019B9C_1A79C(obj, 0);
            func_80019378_19F78(obj);
            D_8010A4E4_113AF4_GrabBag[w->w.unk_59] = 4;
        }
        D_8010A4EC_113AFC_GrabBag += 1;
        break;
    case 4:
        func_801076A0_110CB0_GrabBag(w, -obj->trans.x, -obj->trans.z, 20.0f);
        break;
    case 5:
        if (D_8010A4E4_113AF4_GrabBag[0] == 5 && D_8010A4E4_113AF4_GrabBag[1] == D_8010A4E4_113AF4_GrabBag[0] &&
            D_8010A4E4_113AF4_GrabBag[2] == D_8010A4E4_113AF4_GrabBag[1] && D_8010A4E4_113AF4_GrabBag[3] == D_8010A4E4_113AF4_GrabBag[2]) {
            D_8010A4E4_113AF4_GrabBag[0] = D_8010A4E4_113AF4_GrabBag[1] = D_8010A4E4_113AF4_GrabBag[2] = D_8010A4E4_113AF4_GrabBag[3] = 6;
            D_8010A820_113E30_GrabBag = 1;
        }
        break;
    case 6:
        if (D_8010A834_113E44_GrabBag != 0) {
            D_8010A4E4_113AF4_GrabBag[w->w.unk_59] = 7;
        }
        break;
    case 7:
        if (_CheckFlag(0xC) == 0) {
            best = 0;
            for (i = 0; i < 4; i++) {
                t = ((GBPlayer*)D_800FFFD8_100BD8[i]->unk_50)->unk_16E;
                if (best < t) {
                    best = t;
                }
            }
            if (best == w->unk_16E) {
                func_80019B9C_1A79C(obj, 0xD);
                func_800732B0_73EB0(D_800CD438_CE038[gPlayers[w->w.unk_59].character].unk_04 | 0x4E);
            } else {
                func_80019B9C_1A79C(obj, 0xE);
            }
        }
        D_8010A4E4_113AF4_GrabBag[w->w.unk_59] = 8;
        break;
    case 8:
        if (_CheckFlag(0xC) == 0) {
            func_80019378_19F78(obj);
        }
        D_8010A82B_113E3B_GrabBag = 1;
        if (D_8010A7CC_113DDC_GrabBag == 0) {
            for (i = 0; i < 4; i++) {
                gPlayers[i].coins_mg_bonus = func_80106E38_110448_GrabBag(i);
            }
            func_80106DD0_1103E0_GrabBag();
            i = D_8010A4E8_113AF8_GrabBag;
            if (i == 1 && _CheckFlag(0xC) == 0) {
                if (D_8010A84C_113E5C_GrabBag == 0) {
                    PlayMusic(0x51);
                } else if (D_8010A84C_113E5C_GrabBag == i) {
                    PlayMusic(0x52);
                }
                D_8010A4E8_113AF8_GrabBag = 2;
            }
            D_8010A7CC_113DDC_GrabBag = 1;
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_07_GrabBag/10F470", func_80106F00_110510_GrabBag);
#endif

void func_801076A0_110CB0_GrabBag(GBPlayer* w, f32 x, f32 z, f32 step) {
    f32 a;
    f32 d;
    f32 lim;

    a = func_800B75A8_B81A8(x, z);
    d = w->w.unk_3C - a;
    if (d > 360.0f) {
        d -= 360.0f;
    } else if (d < 0.0f) {
        d += 360.0f;
    }
    lim = step + 10.0f;
    if (d > 0.0f) {
        if (lim < d) {
            goto turn;
        }
        goto done;
    }
    if (!(lim < 0.0f - d)) {
        goto done;
    }
turn:
    if (d > 180.0f) {
        w->w.unk_3C = step + w->w.unk_3C;
    } else {
        w->w.unk_3C = w->w.unk_3C - step;
    }
    return;
done:
    w->w.unk_3C = a;
    D_8010A4E4_113AF4_GrabBag[w->w.unk_59]++;
}

/* NON_MATCHING: control flow (class 3): retail gives the arms their own first clamp test, and hoists 60.0f (masked 86; calls agree) */
#ifdef NON_MATCHING
void func_801077E8_110DF8_GrabBag(void) {
    HuCamera* c = D_800C9B80_CA780;
    Vec pos;
    GBVec2 scr;
    GBVec2 mid;
    GBVec2 lo;
    GBVec2 hi;
    GBVec2 dir;
    s32 i;
    s32 state;
    f32 k, l, a, b, len;

    if ((u32)(D_800F8FD0_F9BD0 - 2) < 2) {
        D_8010A824_113E34_GrabBag -= 0.01f;
        if (D_8010A824_113E34_GrabBag < 1.0f) {
            D_8010A824_113E34_GrabBag = 1.0f;
        }
        dir.x = 640.0f - c->screenPos.x;
        dir.y = 480.0f - c->screenPos.y;
        len = func_800B1830_B2430(dir.x * dir.x + dir.y * dir.y);
        if (len <= 0.0f) {
            return;
        }
        dir.x /= len;
        dir.y /= len;
        k = D_8010A824_113E34_GrabBag - 1.0f;
        l = k * 420.0f;
        a = 640.0f - l;
        b = l + 640.0f;
        c->screenPos.x = dir.x * 8.0f * k + c->screenPos.x;
        if (c->screenPos.x < a) {
            c->screenPos.x = a;
        } else if (b < c->screenPos.x) {
            c->screenPos.x = b;
        }
        k = D_8010A824_113E34_GrabBag - 1.0f;
        l = k * 480.0f;
        a = 480.0f - l;
        b = l + 480.0f;
        c->screenPos.y = dir.y * 8.0f * k + c->screenPos.y;
    } else {
        for (i = 0; i < 4; i++) {
            pos.x = D_800FFFD8_100BD8[i]->trans.x;
            pos.y = D_800FFFD8_100BD8[i]->trans.y;
            pos.z = D_800FFFD8_100BD8[i]->trans.z;
            func_800209C4_215C4(0, &pos, &scr);
            state = 0;
            l = D_8010A824_113E34_GrabBag * 60.0f;
            if (scr.x < l || 320.0f - l < scr.x) {
                break;
            }
            l = D_8010A824_113E34_GrabBag * 45.0f;
            if (scr.y < l || 240.0f - l < scr.y) {
                break;
            }
            state = 2;
            l = D_8010A824_113E34_GrabBag * 64.0f;
            if (l < scr.x) {
                if (scr.x < 320.0f - l) {
                    l = D_8010A824_113E34_GrabBag * 48.0f;
                    if (l < scr.y) {
                        if (scr.y < 240.0f - l) {
                            state = 1;
                            continue;
                        }
                    }
                }
            }
            break;
        }
        if (state == 1) {
            D_8010A824_113E34_GrabBag += 0.01f;
            if (D_8010A824_113E34_GrabBag > 2.5f) {
                D_8010A824_113E34_GrabBag = 2.5f;
            }
        } else if (state == 0) {
            D_8010A824_113E34_GrabBag -= 0.01f;
            if (D_8010A824_113E34_GrabBag < 1.0f) {
                D_8010A824_113E34_GrabBag = 1.0f;
            }
        }
        mid.x = mid.y = 0.0f;
        lo.x = lo.y = 128000.0f;
        hi.x = hi.y = 0.0f;
        for (i = 0; i < 4; i++) {
            pos.x = D_800FFFD8_100BD8[i]->trans.x;
            pos.y = D_800FFFD8_100BD8[i]->trans.y;
            pos.z = D_800FFFD8_100BD8[i]->trans.z;
            func_800209C4_215C4(0, &pos, &scr);
            if (scr.x < lo.x) {
                lo.x = scr.x;
            }
            if (scr.y < lo.y) {
                lo.y = scr.y;
            }
            if (hi.x < scr.x) {
                hi.x = scr.x;
            }
            if (hi.y < scr.y) {
                hi.y = scr.y;
            }
        }
        mid.x = (lo.x + hi.x) / 2.0f;
        mid.y = (lo.y + hi.y) / 2.0f;
        k = D_8010A824_113E34_GrabBag - 1.0f;
        l = k * 420.0f;
        a = 640.0f - l;
        b = l + 640.0f;
        if (mid.x < 150.0f) {
            c->screenPos.x = k * 8.0f + c->screenPos.x;
        } else if (mid.x > 170.0f) {
            c->screenPos.x = c->screenPos.x - (D_8010A824_113E34_GrabBag - 1.0f) * 8.0f;
        }
        if (c->screenPos.x < a) {
            c->screenPos.x = a;
        } else if (b < c->screenPos.x) {
            c->screenPos.x = b;
        }
        k = D_8010A824_113E34_GrabBag - 1.0f;
        l = k * 480.0f;
        a = 480.0f - l;
        b = l + 480.0f;
        if (mid.y < 130.0f) {
            c->screenPos.y = k * 8.0f + c->screenPos.y;
        } else if (mid.y > 150.0f) {
            c->screenPos.y = c->screenPos.y - (D_8010A824_113E34_GrabBag - 1.0f) * 8.0f;
        }
    }
    if (c->screenPos.y < a) {
        c->screenPos.y = a;
    } else if (b < c->screenPos.y) {
        c->screenPos.y = b;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_07_GrabBag/10F470", func_801077E8_110DF8_GrabBag);
#endif

/* NON_MATCHING: control flow (class 3): retail tests unk_164 == 1 through a set-compare (masked 29, one branch and its effects; calls agree) */
#ifdef NON_MATCHING
void func_80107F10_111520_GrabBag(omObjData* obj) {
    GBPlayer* w0;
    GBPlayer* w1;
    GBPlayer* grabber;
    GBPlayer* grabbed;
    omObjData* o;
    s32 i;
    f32 dist, lim, dot;
    f32 a, b, c;
    f32 angle;

    w0 = obj->unk_50;
    for (i = 0; i < 4; i++) {
        o = D_800FFFD8_100BD8[i];
        w1 = o->unk_50;
        if (w0 == w1) {
            continue;
        }
        if (w0->unk_15D == -1) {
            ContBtnTrg[w0->w.unk_57] &= 0x7FFF;
            ContBtnTrg[w0->w.unk_57] &= 0xFFDF;
            dist = func_801086F8_111D08_GrabBag(obj, o);
            lim = w1->w.unk_48 + w1->w.unk_64 + 50.0f;
            a = HuMathSin(w0->w.unk_3C);
            b = func_800B7890_B8490(w0->w.unk_3C);
            c = HuMathSin(w1->w.unk_3C);
            dot = func_8000DA2C_E62C(a, b, c, func_800B7890_B8490(w1->w.unk_3C));
            if (dist < lim && obj->trans.y <= 2.0f && ((o->trans.y <= 2.0f) & (dot > 0.5f))) {
                ContBtnTrg[w0->w.unk_57] |= 0x4000;
            } else {
                ContBtnTrg[w0->w.unk_57] &= 0xBFFF;
            }
        }
        func_80108C38_112248_GrabBag(obj, o);
        if (w0->unk_162 == 1) {
            ContBtnTrg[w0->w.unk_57] &= 0x7FFF;
        }
        if (w1->unk_162 == 1) {
            ContBtnTrg[w1->w.unk_57] &= 0x7FFF;
        }
        if (w0->unk_15E == 1 && w1->unk_15E == 2) {
            grabber = w0;
            grabbed = w1;
            if (w1->unk_164 < 60 || w0->unk_164 < 60) {
                func_801095B8_112BC8_GrabBag(obj);
                func_801095B8_112BC8_GrabBag(o);
            }
        } else if (w0->unk_15E == 2 && w1->unk_15E == 1) {
            if (w0->unk_162 == 1 && w1->unk_162 == w0->unk_162 && (w0->unk_164 < 60 || w1->unk_164 < 60)) {
                func_801095B8_112BC8_GrabBag(obj);
                func_801095B8_112BC8_GrabBag(o);
            }
            continue;
        } else if (w0->unk_15D == -1 && w0->unk_15E == 0 && w1->unk_15E == 0) {
            if (w0->unk_176 > 60) {
                angle = func_801089DC_111FEC_GrabBag(obj);
            } else {
                angle = func_801087B8_111DC8_GrabBag(obj);
            }
            if (func_801086F8_111D08_GrabBag(obj, o) > 300.0f) {
                ContStkX[w0->w.unk_57] = HuMathSin(angle) * 60.0f;
                ContStkY[w0->w.unk_57] = -func_800B7890_B8490(angle) * 60.0f;
            } else {
                ContStkX[w0->w.unk_57] = HuMathSin(angle) * 32.0f;
                ContStkY[w0->w.unk_57] = -func_800B7890_B8490(angle) * 32.0f;
            }
            continue;
        } else {
            continue;
        }
        if (w0->unk_164 == w1->unk_164 && w0->unk_162 == 1 && w1->unk_162 == w0->unk_162 &&
            w0->unk_15F == w1->w.unk_59) {
            if (grabbed->unk_164 < 60 || grabber->unk_164 < 60) {
                func_801095B8_112BC8_GrabBag(obj);
                func_801095B8_112BC8_GrabBag(o);
            }
            if ((grabber->unk_164 < 30 || grabbed->unk_164 < 30) && (u8)(grabber->unk_164 % 10) == 0) {
                if (grabber == w0) {
                    omVibrate(w0->w.unk_59, 2, 3, 10);
                } else if (grabber == w1) {
                    omVibrate(w1->w.unk_59, 2, 3, 10);
                }
            }
            if (w0->unk_164 == 1) {
                if (grabber == w0) {
                    w0->w.unk_40 = 0.0f;
                    func_80029714_2A314(obj->model[0], obj->trans.x, 2.0f, obj->trans.z);
                    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
                }
                if (grabbed == w1) {
                    w1->w.unk_40 = 0.0f;
                    /* Retail places the grabber's model here again, not the other player's. */
                    func_80029714_2A314(obj->model[0], obj->trans.x, 2.0f, obj->trans.z);
                    func_80029714_2A314(o->model[1], o->trans.x, o->trans.y, o->trans.z);
                }
                func_800191D4_19DD4(obj, 7, (obj->trans.x + o->trans.x) / 2.0f, obj->trans.y,
                                    (obj->trans.z + o->trans.z) / 2.0f, 0.0f, 0.0f);
                func_800795D8_7A1D8(func_80079798_7A398(0x148, grabbed->w.unk_59), 0x7F);
            }
            if (w0->unk_164 != 0 && grabbed->unk_164 < 30) {
                if (grabber == w0) {
                    func_80019B9C_1A79C(obj, 0x17);
                }
                if (grabbed == w1) {
                    func_80019B9C_1A79C(o, 0x1D);
                }
            }
            if (w0->unk_164 != 0 && w1->unk_164 != 0) {
                if (w0->unk_164 < 30) {
                    func_80108E94_1124A4_GrabBag(obj, o);
                }
                if (grabbed->unk_164 == 30) {
                    func_80108F7C_11258C_GrabBag(obj, o);
                } else {
                    func_8010866C_111C7C_GrabBag(grabber, 0x4000);
                    func_8010866C_111C7C_GrabBag(grabbed, 0x4000);
                }
            }
            if (grabbed->unk_164 >= 75 || grabber->unk_164 >= 75) {
                grabber->unk_164 = grabbed->unk_164 = 0;
                grabber->unk_162 = grabbed->unk_162 = 0;
                grabber->unk_160 = grabbed->unk_160 = 0;
                grabber->unk_161 = grabbed->unk_161 = 0;
                w0->unk_15F = w1->unk_15F = -1;
                w0->w.unk_50 &= ~0x200;
                w1->w.unk_50 &= ~0x200;
            } else {
                w0->unk_164++;
                w1->unk_164++;
            }
        }
    }
    func_80007790_8390(obj);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_07_GrabBag/10F470", func_80107F10_111520_GrabBag);
#endif

void func_8010866C_111C7C_GrabBag(GBPlayer* w, s32 btn) {
    D_8010A7CE_113DDE_GrabBag[w->w.unk_57] = ContBtn[w->w.unk_57] & ~D_8010A4F0_113B00_GrabBag[w->w.unk_57];
    D_8010A4F0_113B00_GrabBag[w->w.unk_57] = ContBtn[w->w.unk_57];
    if (D_8010A7CE_113DDE_GrabBag[w->w.unk_57] & btn) {
        w->unk_163++;
    }
}

f32 func_801086F8_111D08_GrabBag(omObjData* a, omObjData* b) {
    GBPlayer* w0;
    GBPlayer* w1;
    f32 r, x, y, z, dx, dy, dz;

    w0 = a->unk_50;
    w1 = b->unk_50;
    r = w0->w.unk_48 + w0->w.unk_64;
    x = b->trans.x - HuMathSin(w1->w.unk_3C) * r;
    y = b->trans.y;
    z = b->trans.z - func_800B7890_B8490(w1->w.unk_3C) * r;
    dx = a->trans.x - x;
    dy = a->trans.y - y;
    dz = a->trans.z - z;
    return func_800B1830_B2430(dx * dx + dy * dy + dz * dz);
}

f32 func_801087B8_111DC8_GrabBag(omObjData* obj) {
    GBPlayer* self;
    GBPlayer* w;
    omObjData* o;
    f32 tx, tz, angle, dist, a, b, c;
    u8 best;
    s32 i;

    tz = 0.0f;
    tx = 0.0f;
    self = obj->unk_50;
    best = 0;
    for (i = 0; i < 4; i++) {
        o = D_800FFFD8_100BD8[i];
        w = o->unk_50;
        if (obj == o) {
            continue;
        }
        if (w->unk_15E != 0) {
            continue;
        }
        if (best < w->unk_16E) {
            best = w->unk_16E;
            tx = o->trans.x - HuMathSin(w->w.unk_3C) * 60.0f;
            tz = o->trans.z - func_800B7890_B8490(w->w.unk_3C) * 60.0f;
        }
    }
    angle = func_801096E0_112CF0_GrabBag(self->w.unk_3C, tx - obj->trans.x, tz - obj->trans.z, 15.0f);
    dist = func_801086F8_111D08_GrabBag(obj, o);
    a = HuMathSin(w->w.unk_3C);
    b = func_800B7890_B8490(w->w.unk_3C);
    c = HuMathSin(self->w.unk_3C);
    if (func_8000DA2C_E62C(a, b, c, func_800B7890_B8490(self->w.unk_3C)) > 0.5f && dist < w->w.unk_48 + w->w.unk_64) {
        angle += 45.0f;
    }
    if (angle > 360.0f) {
        angle -= 360.0f;
    } else if (angle < 0.0f) {
        angle += 360.0f;
    }
    return angle;
}

/* NON_MATCHING: register allocation (class 4): float temporaries (masked 0), as MP1's func_800F9A1C */
#ifdef NON_MATCHING
f32 func_801089DC_111FEC_GrabBag(omObjData* obj) {
    GBPlayer* self;
    GBPlayer* w;
    omObjData* o;
    f32 tx, tz, best, d, dx, dz, angle, a, b, c;
    s32 i;

    tz = 0.0f;
    tx = 0.0f;
    self = obj->unk_50;
    best = 128000.0f;
    for (i = 0; i < 4; i++) {
        o = D_800FFFD8_100BD8[i];
        w = o->unk_50;
        if (obj != o && w->unk_15E == 0) {
            dx = obj->trans.x - o->trans.x;
            dz = obj->trans.z - o->trans.z;
            d = dx * dx + dz * dz;
            if (d < best) {
                best = d;
                tx = o->trans.x - HuMathSin(w->w.unk_3C) * 60.0f;
                tz = o->trans.z - func_800B7890_B8490(w->w.unk_3C) * 60.0f;
            }
        }
    }
    angle = func_801096E0_112CF0_GrabBag(self->w.unk_3C, tx - obj->trans.x, tz - obj->trans.z, 15.0f);
    best = func_801086F8_111D08_GrabBag(obj, o);
    a = HuMathSin(w->w.unk_3C);
    b = func_800B7890_B8490(w->w.unk_3C);
    c = HuMathSin(self->w.unk_3C);
    if (func_8000DA2C_E62C(a, b, c, func_800B7890_B8490(self->w.unk_3C)) > 0.5f && best < w->w.unk_48 + w->w.unk_64) {
        angle += 45.0f;
    }
    angle += 180.0f;
    if (angle > 360.0f) {
        angle -= 360.0f;
    } else if (angle < 0.0f) {
        angle += 360.0f;
    }
    return angle;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_07_GrabBag/10F470", func_801089DC_111FEC_GrabBag);
#endif

void func_80108C38_112248_GrabBag(omObjData* a, omObjData* b) {
    GBPlayer* w0;
    GBPlayer* w1;
    f32 p, q, r, dot;
    s32 btn;

    w0 = a->unk_50;
    w1 = b->unk_50;
    if (w0->unk_162 == 1) {
        w0->w.unk_50 |= 0x200;
    } else {
        w0->w.unk_50 &= ~0x200;
    }
    if (w1->unk_162 == 1) {
        w1->w.unk_50 |= 0x200;
    } else {
        w1->w.unk_50 &= ~0x200;
    }
    if (w0->unk_162 == 1 || w1->unk_162 == 1) {
        return;
    }
    p = HuMathSin(w0->w.unk_3C);
    q = func_800B7890_B8490(w0->w.unk_3C);
    r = HuMathSin(w1->w.unk_3C);
    dot = func_8000DA2C_E62C(p, q, r, func_800B7890_B8490(w1->w.unk_3C));
    if (((func_801086F8_111D08_GrabBag(a, b) < w0->w.unk_48 + w0->w.unk_64 + 50.0f) & (dot > 0.5f)) &&
        !(w0->w.unk_5C & 0x20) && !(w1->w.unk_5C & 0x20) && w0->unk_15F == -1 && w1->unk_15F == w0->unk_15F) {
        if (w0->unk_164 == 0 && w1->unk_164 == 0) {
            btn = ContBtnTrg[w0->w.unk_57];
            if (!(btn & 0x4000)) {
                return;
            }
            if (btn & 0x8000) {
                return;
            }
            w1->unk_162 = 1;
            w0->unk_162 = 1;
            w0->unk_15F = w1->w.unk_59;
            w1->unk_15F = w0->w.unk_59;
            w0->unk_164++;
            w1->unk_164++;
            w0->unk_15E = 1;
            w1->unk_15E = 2;
            w1->unk_176 = 0;
            w0->unk_176 = 0;
        }
    } else {
        w1->unk_15E = 0;
        w0->unk_15E = 0;
        w1->unk_15F = -1;
        w0->unk_15F = -1;
        w1->unk_164 = 0;
        w0->unk_164 = 0;
    }
}

void func_80108E94_1124A4_GrabBag(omObjData* a, omObjData* b) {
    GBPlayer* w0;
    GBPlayer* w1;
    f32 dx, dz, base, d, lim;

    w0 = a->unk_50;
    w1 = b->unk_50;
    HuMathSin(w1->w.unk_3C);
    func_800B7890_B8490(w1->w.unk_3C);
    base = a->trans.z;
    dx = b->trans.x - a->trans.x;
    dz = b->trans.z - base;
    d = dx * dx + dz * dz;
    lim = D_800BF7C4_C03C4 * D_800BF7C4_C03C4;
    if (lim < d) {
        w1->w.unk_3C = func_800B75A8_B81A8(dx, dz);
        w1->w.unk_40 = -D_800BF7C4_C03C4;
    }
    w0->w.unk_3C = w1->w.unk_3C;
    w1->w.unk_38 = 1000.0f;
    w0->w.unk_38 = 1000.0f;
    func_80029714_2A314(b->model[0], b->trans.x, 2.0f, b->trans.z);
}

/* NON_MATCHING: register allocation (class 4): w0/w1 in s3/s2, as MP1's func_800F9ED0 (masked 0) */
#ifdef NON_MATCHING
void func_80108F7C_11258C_GrabBag(omObjData* a, omObjData* b) {
    GBPlayer* w0;
    GBPlayer* w1;

    w0 = a->unk_50;
    w1 = b->unk_50;
    func_800191D4_19DD4(a, 8, (a->trans.x + b->trans.x) / 2.0f, (a->trans.y + b->trans.y) / 2.0f,
                        (a->trans.z + b->trans.z) / 2.0f, 0.0f, 0.0f);
    if (func_80109210_112820_GrabBag(a, b) == 1) {
        w1->unk_161 = 1;
        w0->unk_161 = 1;
        w1->w.unk_40 = D_800BF7C8_C03C8;
        func_80019B9C_1A79C(b, 0xC);
        w0->w.unk_40 = -D_800BF7C8_C03C8;
        func_80029714_2A314(a->model[1], a->trans.x, a->trans.y, a->trans.z);
        func_80019B9C_1A79C(a, 9);
        D_8010A830_113E40_GrabBag = func_80109388_112998_GrabBag(a, b);
        D_8010A7D8_113DE8_GrabBag = D_800F9CE0_FA8E0[D_8010A830_113E40_GrabBag]->unk_50;
        D_8010A7D8_113DE8_GrabBag->unk_AC = w0->unk_15F;
        D_8010A7D8_113DE8_GrabBag->unk_AD = w0->w.unk_59;
        if (D_8010A830_113E40_GrabBag % 2 == 0) {
            D_8010A7D8_113DE8_GrabBag->unk_AE = 0;
        } else if (D_8010A830_113E40_GrabBag % 2 == 1) {
            D_8010A7D8_113DE8_GrabBag->unk_AE = 1;
            func_800797DC_7A3DC(0x111, w1->w.unk_59);
        }
        D_800F9CE0_FA8E0[D_8010A830_113E40_GrabBag]->trans.x = b->trans.x;
        D_800F9CE0_FA8E0[D_8010A830_113E40_GrabBag]->trans.y = b->trans.y;
        D_800F9CE0_FA8E0[D_8010A830_113E40_GrabBag]->trans.z = b->trans.z;
        func_800298A4_2A4A4(D_800F9CE0_FA8E0[D_8010A830_113E40_GrabBag]->model[0], 4, 0);
        func_800298A4_2A4A4(D_800F9CE0_FA8E0[D_8010A830_113E40_GrabBag]->model[1], 4, 0);
        func_801032E0_10C8F0_GrabBag(D_800F9CE0_FA8E0[D_8010A830_113E40_GrabBag]);
        w1->unk_163 = 0;
    } else {
        w0->w.unk_40 = -D_800BF7C8_C03C8;
        func_80019B9C_1A79C(a, 0x1E);
        w1->w.unk_40 = D_800BF7C8_C03C8;
        func_80019B9C_1A79C(b, 0x1F);
        w1->unk_163 = 0;
    }
    w0->unk_163 = 0;
    w1->unk_160 = 1;
    w0->unk_160 = 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_07_GrabBag/10F470", func_80108F7C_11258C_GrabBag);
#endif

s32 func_80109210_112820_GrabBag(omObjData* a, omObjData* b) {
    GBPlayer* w0;
    GBPlayer* w1;

    w0 = a->unk_50;
    w1 = b->unk_50;
    if (w1->unk_16E <= 0) {
        return -1;
    }
    if (w0->unk_15D == -1) {
        if (gPlayers[w0->w.unk_59].cpu_difficulty == 0) {
            if (rand8() >> 6) {
                return -1;
            }
            return 1;
        }
        if (gPlayers[w0->w.unk_59].cpu_difficulty == 1) {
            if (rand8() >> 7) {
                return -1;
            }
            return 1;
        }
        if (gPlayers[w0->w.unk_59].cpu_difficulty == 2) {
            if ((s32)((u32)(rand8() * 5) >> 7) < 8) {
                return 1;
            }
            return -1;
        }
        if (gPlayers[w0->w.unk_59].cpu_difficulty == 3) {
            if ((rand8() * 255) >> 8 < 0xFE) {
                return 1;
            }
            return -1;
        }
    }
    if (w0->unk_163 < w1->unk_163) {
        return -1;
    }
    return 1;
}

/* NON_MATCHING: register allocation (class 4): the model table load takes a0 where retail keeps the object (masked 7) */
#ifdef NON_MATCHING
s32 func_80109388_112998_GrabBag(omObjData* a, omObjData* b) {
    GBPlayer* w0;
    GBPlayer* w1;
    omObjData* o;
    u8 k;

    w0 = a->unk_50;
    w1 = b->unk_50;
    k = 1;
    if (w1->unk_16A > 0) {
        w0->unk_16A++;
        w1->unk_16A--;
        w0->unk_16E += 3;
        w1->unk_16E -= 3;
        D_8010A82F_113E3F_GrabBag = w0->w.unk_59;
    } else {
        k = 0;
        w0->unk_16E++;
        w1->unk_16E--;
    }
    w0->unk_168++;
    w1->unk_168--;
    o = D_800F9CE0_FA8E0[k];
    if (!(D_800FC834_FD434[o->model[0]].unk18 & 4) || ((GBItem*)o->unk_50)->unk_78 != 0) {
        k += 2;
    }
    return k;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_07_GrabBag/10F470", func_80109388_112998_GrabBag);
#endif

void func_8010946C_112A7C_GrabBag(omObjData* obj) {
    GBPlayer* w = obj->unk_50;

    if (w->unk_161 == 1 && D_800F8FD0_F9BD0 == w->unk_161 && w->unk_164 != 0 &&
        (w->unk_16E == 0 || w->unk_16E == 1 || w->unk_16E == 4)) {
        if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
            D_8010A7DC_113DEC_GrabBag = HuMathSin(w->unk_164 * 10);
        }
        if (D_8010A7DC_113DEC_GrabBag < 0.0f) {
            D_8010A7DC_113DEC_GrabBag = -D_8010A7DC_113DEC_GrabBag;
        }
    } else if (w->unk_16E <= 0) {
        D_8010A7DC_113DEC_GrabBag = 1.0f;
    } else if (w->unk_16E >= 4) {
        D_8010A7DC_113DEC_GrabBag = 0.0f;
    } else if (w->unk_16E > 0) {
        D_8010A7DC_113DEC_GrabBag = 0.5f;
    }
    func_8002A15C_2AD5C(obj->model[9], obj->model[10], D_8010A7DC_113DEC_GrabBag);
}

void func_801095B8_112BC8_GrabBag(omObjData* obj) {
    GBPlayer* w;
    f32 angle;

    w = obj->unk_50;
    if (w->unk_164 < 30) {
        ContStkX[w->w.unk_57] = ContStkY[w->w.unk_57] = 0;
    } else if (w->unk_15D == -1) {
        if (w->unk_176 > 60) {
            angle = func_801089DC_111FEC_GrabBag(obj);
        } else {
            angle = func_801087B8_111DC8_GrabBag(obj);
        }
        ContStkX[w->w.unk_57] = HuMathSin(angle) * 32.0f;
        ContStkY[w->w.unk_57] = -func_800B7890_B8490(angle) * 32.0f;
    }
    ContBtnTrg[w->w.unk_57] &= 0x7FFF;
    ContBtnTrg[w->w.unk_57] &= 0xBFFF;
}

/* NON_MATCHING: register allocation (class 4): float register at the shared return, as MP1's func_800FA780 (masked 3) */
#ifdef NON_MATCHING
f32 func_801096E0_112CF0_GrabBag(f32 a, f32 x, f32 z, f32 step) {
    f32 t;
    f32 d;

    t = func_800B75A8_B81A8(x, z);
    while (t < 0.0f) {
        t += 360.0f;
    }
    while (t >= 360.0f) {
        t -= 360.0f;
    }
    while (a < 0.0f) {
        a += 360.0f;
    }
    while (a >= 360.0f) {
        a -= 360.0f;
    }
    d = t - a;
    if ((-step < d) & (d < step)) {
        return t;
    }
    if (d <= -180.0f) {
        return a + step;
    }
    if ((d <= 180.0f) & (d >= 0.0f)) {
        return a + step;
    }
    if (d > 180.0f) {
        return a - step;
    }
    if ((d > -180.0f) & (d < 0.0f)) {
        return a - step;
    }
    return t;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_07_GrabBag/10F470", func_801096E0_112CF0_GrabBag);
#endif



void func_80109940_112F50_GrabBag(omObjData* obj) {
    GBPos face[4] = { { 56, 24 }, { 264, 24 }, { 56, 202 }, { 264, 202 } };
    GBPos bag[4] = { { 35, 38 }, { 243, 38 }, { 35, 216 }, { 243, 216 } };
    s16 i;
    s16 s;

    for (i = 0; i < 4; i++) {
        D_8010A810_113E20_GrabBag[i] = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(gPlayers[i].character + 0x28), 0, 1);
        espPosSet(D_8010A810_113E20_GrabBag[i], face[i].x, face[i].y);
    }
    s = func_8001A2F8_1AEF8(0x17000F);
    for (i = 0; i < 4; i++) {
        D_8010A7E8_113DF8_GrabBag[i] = func_8001AAAC_1B6AC(s, 0, 1);
        espPosSet(D_8010A7E8_113DF8_GrabBag[i], bag[i].x, bag[i].y);
    }
    s = func_8001A2F8_1AEF8(0x170010);
    for (i = 0; i < 4; i++) {
        D_8010A7F0_113E00_GrabBag[i] = func_8001AAAC_1B6AC(s, 0, 1);
        espPosSet(D_8010A7F0_113E00_GrabBag[i], bag[i].x + 12, bag[i].y);
    }
    s = func_8001A2F8_1AEF8(0x43);
    for (i = 0; i < 4; i++) {
        D_8010A7F8_113E08_GrabBag[i][0] = func_8001AAAC_1B6AC(s, 0, 1);
        espPosSet(D_8010A7F8_113E08_GrabBag[i][0], D_8010A4C4_113AD4_GrabBag[i].x, D_8010A4C4_113AD4_GrabBag[i].y);
        D_8010A7F8_113E08_GrabBag[i][1] = func_8001AAAC_1B6AC(s, 0, 1);
        espPosSet(D_8010A7F8_113E08_GrabBag[i][1], D_8010A4C4_113AD4_GrabBag[i].x + 12, D_8010A4C4_113AD4_GrabBag[i].y);
        D_8010A7F8_113E08_GrabBag[i][2] = func_8001AAAC_1B6AC(s, 0, 1);
        espPosSet(D_8010A7F8_113E08_GrabBag[i][2], D_8010A4C4_113AD4_GrabBag[i].x + 24, D_8010A4C4_113AD4_GrabBag[i].y);
    }
    obj->work[1] = 0;
    D_8010A7E4_113DF4_GrabBag = obj;
    obj->func_ptr = func_80109CE8_1132F8_GrabBag;
}

void func_80109CE8_1132F8_GrabBag(omObjData* obj) {
    s32 i;
    s32 score;
    s32 digit;
    s32 x;

    switch (obj->work[1]) {
    case 0:
        break;
    case 1:
        for (i = 0; i < 4; i++) {
            score = D_8010A4D4_113AE4_GrabBag[i];
            if (score >= 1000) {
                score = 999;
            }
            x = 0;
            espDispOn(D_8010A7F8_113E08_GrabBag[i][2]);
            digit = score / 100;
            if (digit == 0) {
                espDispOff(D_8010A7F8_113E08_GrabBag[i][2]);
            }
            func_8001A810_1B410(D_8010A7F8_113E08_GrabBag[i][2], digit);
            espPosSet(D_8010A7F8_113E08_GrabBag[i][2], D_8010A4C4_113AD4_GrabBag[i].x + x, D_8010A4C4_113AD4_GrabBag[i].y);
            if (digit != 0) {
                x += 12;
            }
            espDispOn(D_8010A7F8_113E08_GrabBag[i][1]);
            digit = (score % 100) / 10;
            if (digit == 0 && score / 100 == 0) {
                espDispOff(D_8010A7F8_113E08_GrabBag[i][1]);
            }
            func_8001A810_1B410(D_8010A7F8_113E08_GrabBag[i][1], digit);
            espPosSet(D_8010A7F8_113E08_GrabBag[i][1], D_8010A4C4_113AD4_GrabBag[i].x + x, D_8010A4C4_113AD4_GrabBag[i].y);
            if (digit != 0) {
                x += 12;
            } else if (score / 100 != 0) {
                x += 12;
            }
            func_8001A810_1B410(D_8010A7F8_113E08_GrabBag[i][0], score % 10);
            espPosSet(D_8010A7F8_113E08_GrabBag[i][0], D_8010A4C4_113AD4_GrabBag[i].x + x, D_8010A4C4_113AD4_GrabBag[i].y);
            if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
                if (D_8010A4D4_113AE4_GrabBag[i] != D_8010A4F8_113B08_GrabBag[i] || D_8010A508_113B18_GrabBag[i] != 0.0f) {
                    D_8010A508_113B18_GrabBag[i] += 20.0f;
                    if (D_8010A508_113B18_GrabBag[i] > 180.0f) {
                        D_8010A508_113B18_GrabBag[i] = 0.0f;
                    }
                    D_8010A518_113B28_GrabBag[i] = HuMathSin(D_8010A508_113B18_GrabBag[i]) + 1.0f;
                } else {
                    D_8010A518_113B28_GrabBag[i] = 1.0f;
                    D_8010A508_113B18_GrabBag[i] = 0.0f;
                }
                func_8001A91C_1B51C(D_8010A7E8_113DF8_GrabBag[i], D_8010A518_113B28_GrabBag[i], D_8010A518_113B28_GrabBag[i]);
            }
            D_8010A4F8_113B08_GrabBag[i] = D_8010A4D4_113AE4_GrabBag[i];
        }
        break;
    }
}

void func_8010A108_113718_GrabBag(void) {
    s32 i;

    D_8010A7E4_113DF4_GrabBag->work[1] = 1;
    for (i = 0; i < 4; i++) {
        espDispOn(D_8010A7F8_113E08_GrabBag[i][0]);
        espDispOn(D_8010A7F8_113E08_GrabBag[i][1]);
        espDispOn(D_8010A7F8_113E08_GrabBag[i][2]);
        espDispOn(D_8010A7E8_113DF8_GrabBag[i]);
        espDispOn(D_8010A7F0_113E00_GrabBag[i]);
        espDispOn(D_8010A810_113E20_GrabBag[i]);
    }
}

void func_8010A1EC_1137FC_GrabBag(void) {
    s32 i;

    D_8010A7E4_113DF4_GrabBag->work[1] = 0;
    for (i = 0; i < 4; i++) {
        espDispOff(D_8010A7F8_113E08_GrabBag[i][0]);
        espDispOff(D_8010A7F8_113E08_GrabBag[i][1]);
        espDispOff(D_8010A7F8_113E08_GrabBag[i][2]);
        espDispOff(D_8010A7E8_113DF8_GrabBag[i]);
        espDispOff(D_8010A7F0_113E00_GrabBag[i]);
        espDispOff(D_8010A810_113E20_GrabBag[i]);
    }
}

void func_8010A2CC_1138DC_GrabBag(s32 p, s32 n) {
    n = n < 0 ? 0 : n;
    if (n >= 1000) {
        n = 999;
    }
    D_8010A4D4_113AE4_GrabBag[p] = n;
}

