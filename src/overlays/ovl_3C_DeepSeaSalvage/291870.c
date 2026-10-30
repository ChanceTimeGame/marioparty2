#include "ovl_3C.h"

#define DSS_ABS(x) ((x) < 0 ? -(x) : (x))


void func_80102800_291870_DeepSeaSalvage(void) {
    omObjData* obj;
    s16 i;
    u8 cam;

    func_8002D4D0_2E0D0(1);
    func_80020D20_21920(0x60);
    omInitObjMan(0x40, 0);
    func_80079128_79D28();
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_80079E60_7AA60), 0xA0);
    func_80018E30_19A30(1);
    cam = func_80018E78_19A78();
    ScissorSet(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 10.0f, 2000.0f, 32000.0f);
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    D_80108820_297890_DeepSeaSalvage = 0;
    D_80108822_297892_DeepSeaSalvage = 65;
    D_80108826_297896_DeepSeaSalvage = 0;
    D_80108824_297894_DeepSeaSalvage = 1;
    D_80108828_297898_DeepSeaSalvage = 900;
    D_8010882A_29789A_DeepSeaSalvage = _CheckFlag(0xC);
    D_80108832_2978A2_DeepSeaSalvage = 0;
    D_80108830_2978A0_DeepSeaSalvage = 0;
    D_8010882E_29789E_DeepSeaSalvage = 0;
    D_8010882C_29789C_DeepSeaSalvage = 0;
    func_80105EB0_294F20_DeepSeaSalvage();
    func_80106F08_295F78_DeepSeaSalvage();
    func_80105F14_294F84_DeepSeaSalvage();
    D_8010A7E0_299850_DeepSeaSalvage = omAddObj(10, 0, 0, -1, func_80102B48_291BB8_DeepSeaSalvage);
    obj = omAddObj(0, 3, 0, -1, func_80102FBC_29202C_DeepSeaSalvage);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = obj;
    omSetStatBit(obj, 0xA0);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(1, 6, 0, -1, func_80103180_2921F0_DeepSeaSalvage);
    for (i = 0; i < 4; i++) {
        D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(3, 2, 50, -1, func_801031CC_29223C_DeepSeaSalvage);
    }
    D_80109CD0_298D40_DeepSeaSalvage = omAddObj(4, 2, 3, -1, func_80103DCC_292E3C_DeepSeaSalvage);
    func_801043A4_293414_DeepSeaSalvage();
    func_80026DAC_279AC(0, 128, 128, 128);
    func_80026DAC_279AC(1, 255, 255, 255);
    func_80026E00_27A00(1, 0.0f, 128.0f, 128.0f);
    omAddObj(9, 0, 0, -1, func_801058A0_294910_DeepSeaSalvage);
}

void func_80102B48_291BB8_DeepSeaSalvage(omObjData* obj) {
    obj->func_ptr = func_80102B74_291BE4_DeepSeaSalvage;
    InitFadeIn(0, 16);
}

void func_80102B74_291BE4_DeepSeaSalvage(omObjData* obj) {
    s16 n;
    s16 i;

    switch (D_80108820_297890_DeepSeaSalvage) {
    case 0:
        if (--D_80108822_297892_DeepSeaSalvage == 0) {
            D_80108820_297890_DeepSeaSalvage = 2;
            D_80108822_297892_DeepSeaSalvage = 60;
            func_800691FC_69DFC(0);
        }
        if (func_8008F618_90218() == 0 && D_80108420_297490_DeepSeaSalvage == 0) {
            PlayMusic(0x2A);
            D_80108420_297490_DeepSeaSalvage++;
        }
        break;
    case 2:
        if (--D_80108822_297892_DeepSeaSalvage == 0) {
            D_80108820_297890_DeepSeaSalvage++;
            D_80108824_297894_DeepSeaSalvage = 0;
            D_80108834_2978A4_DeepSeaSalvage = omAddObj(0, 0, 0, -1, func_80102EC8_291F38_DeepSeaSalvage);
        }
        break;
    case 3:
        if (--D_80108828_297898_DeepSeaSalvage == 0) {
            D_80108826_297896_DeepSeaSalvage = 1;
            D_80108824_297894_DeepSeaSalvage = 1;
            if (D_8010882A_29789A_DeepSeaSalvage == 0) {
                D_80108820_297890_DeepSeaSalvage = 4;
            } else {
                D_80108820_297890_DeepSeaSalvage = 5;
                D_80108822_297892_DeepSeaSalvage = 60;
            }
            func_800691FC_69DFC(3);
            func_800794A8_7A0A8(0x2D);
        }
        break;
    case 4:
        if (func_80069538_6A138() == 2) {
            D_80108820_297890_DeepSeaSalvage++;
            n = 0;
            for (i = 0; i < 4; i++) {
                if (D_801088BE_29792E_DeepSeaSalvage[i] != 0) {
                    n++;
                }
            }
            if (n != 0) {
                if (n != 1) {
                    PlayMusic(0x52);
                    D_80108822_297892_DeepSeaSalvage = 168;
                } else {
                    PlayMusic(0x51);
                    D_80108822_297892_DeepSeaSalvage = 120;
                }
            } else {
                PlayMusic(0x56);
                D_80108822_297892_DeepSeaSalvage = 133;
            }
        }
        break;
    case 5:
        if (--D_80108822_297892_DeepSeaSalvage == 0) {
            D_80108820_297890_DeepSeaSalvage = -1;
            D_80108826_297896_DeepSeaSalvage = -1;
            func_80079614_7A214(40);
            InitFadeOut(0, 20);
        }
        break;
    }
    if (D_80108826_297896_DeepSeaSalvage >= 0 && D_801011FC_101DFC != 0) {
        D_80108826_297896_DeepSeaSalvage = -1;
        D_80108820_297890_DeepSeaSalvage = -1;
        InitFadeOut(0, 20);
        func_80079614_7A214(40);
        func_800794A8_7A0A8(40);
    }
    func_80105258_2942C8_DeepSeaSalvage();
    func_80107318_296388_DeepSeaSalvage();
    func_80102E7C_291EEC_DeepSeaSalvage();
}

void func_80102E7C_291EEC_DeepSeaSalvage(void) {
    if (D_80108826_297896_DeepSeaSalvage < 0 && func_8008F618_90218() == 0) {
        func_80106048_2950B8_DeepSeaSalvage();
        func_80079464_7A064();
        omOvlReturnEx(1);
    }
}

void func_80102EC8_291F38_DeepSeaSalvage(omObjData* obj) {
    func_800691FC_69DFC(10, (s16)(D_80108828_297898_DeepSeaSalvage / 30), 160, 24);
    obj->func_ptr = func_80102F3C_291FAC_DeepSeaSalvage;
}

void func_80102F3C_291FAC_DeepSeaSalvage(omObjData* obj) {
    func_8006D4D0_6E0D0((s16)((D_80108828_297898_DeepSeaSalvage + 29) / 30));
    if (D_80108828_297898_DeepSeaSalvage == 0 || D_80108826_297896_DeepSeaSalvage != 0) {
        obj->func_ptr = NULL;
        func_8006D518_6E118();
    }
}

/* The backdrop: two models from D_80108424 placed by D_8010842C (the first through the object).
   NON_MATCHING: GCC keeps &D_8010842C in a register for the first model's six reads, retail
   addresses each by %hi/%lo (masked 35, addressing and registers only). */
#ifdef NON_MATCHING
void func_80102FBC_29202C_DeepSeaSalvage(omObjData* obj) {
    s16 i;

    for (i = 0; (u16)i < 2; i++) {
        obj->model[i] = func_80018A30_19630(D_80108424_297494_DeepSeaSalvage[i], 0x2D9);
        if (i == 0) {
            obj->trans.x = D_8010842C_29749C_DeepSeaSalvage[0][0];
            obj->trans.y = D_8010842C_29749C_DeepSeaSalvage[0][1];
            obj->trans.z = D_8010842C_29749C_DeepSeaSalvage[0][2];
            obj->scale.x = D_8010842C_29749C_DeepSeaSalvage[0][3];
            obj->scale.y = D_8010842C_29749C_DeepSeaSalvage[0][4];
            obj->scale.z = D_8010842C_29749C_DeepSeaSalvage[0][5];
        } else {
            func_80029714_2A314(obj->model[i], D_8010842C_29749C_DeepSeaSalvage[i][0],
                                D_8010842C_29749C_DeepSeaSalvage[i][1], D_8010842C_29749C_DeepSeaSalvage[i][2]);
            func_800297E8_2A3E8(obj->model[i], D_8010842C_29749C_DeepSeaSalvage[i][3],
                                D_8010842C_29749C_DeepSeaSalvage[i][4], D_8010842C_29749C_DeepSeaSalvage[i][5]);
        }
    }
    func_8010819C_29720C_DeepSeaSalvage(obj);
    obj->func_ptr = func_80103164_2921D4_DeepSeaSalvage;
    D_801088C8_297938_DeepSeaSalvage.x = D_801088C8_297938_DeepSeaSalvage.y = D_801088C8_297938_DeepSeaSalvage.z = 0.0f;
    D_801088D4_297944_DeepSeaSalvage.x = D_801088D4_297944_DeepSeaSalvage.y = D_801088D4_297944_DeepSeaSalvage.z = 1.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_80102FBC_29202C_DeepSeaSalvage);
#endif

void func_80103164_2921D4_DeepSeaSalvage(omObjData* obj) {
    func_801081EC_29725C_DeepSeaSalvage(obj);
}

void func_80103180_2921F0_DeepSeaSalvage(omObjData* obj) {
    obj->model[0] = LoadFormFile(0x4C000C, 0x299);
    func_801074E0_296550_DeepSeaSalvage(obj);
    obj->func_ptr = func_80107A10_296A80_DeepSeaSalvage;
}

__asm__(".section .rodata");
const char D_80108678_2976E8_DeepSeaSalvage[] = "c005_000-bmerge1";

__asm__(".section .rodata");
const char D_8010868C_2976FC_DeepSeaSalvage[] = "Luigi1-atama_1";

__asm__(".section .rodata");
const char D_8010869C_29770C_DeepSeaSalvage[] = "c003_000-head_1";

__asm__(".section .rodata");
const char D_801086AC_29771C_DeepSeaSalvage[] = "C002_000b-bmerge10_1";

__asm__(".section .rodata");
const char D_801086C4_297734_DeepSeaSalvage[] = "c001_000-atama_2";

__asm__(".section .rodata");
const char D_801086D8_297748_DeepSeaSalvage[] = "atama_2";

void func_801031CC_29223C_DeepSeaSalvage(omObjData* obj) {
    MgWork* w;
    DSSDiver* d;
    u8 chr;
    s32 dir;
    f32 zero;

    chr = gPlayers[D_8010882C_29789C_DeepSeaSalvage].character;
    dir = D_800CD438_CE038[chr].unk_04;
    obj->model[0] = LoadFormFile(D_80108474_2974E4_DeepSeaSalvage[chr] | 0x4C0000, 0x2B9);
    obj->model[1] = LoadFormFile(dir | D_800CD438_CE038[chr].unk_0C, 0x2BD);
    func_80023DAC_249AC(obj->model[1], D_8010845C_2974CC_DeepSeaSalvage[chr], obj->model[0], "kubi");
    func_80029E80_2AA80(obj->model[0], 2, 2);
    func_80029FE4_2ABE4(obj->model[0], 0.0f);
    obj->trans.x = D_80108480_2974F0_DeepSeaSalvage[D_8010882C_29789C_DeepSeaSalvage];
    obj->trans.y = 0.0f;
    obj->trans.z = -200.0f;
    obj->rot.y = 90.0f;
    zero = 0.0f;
    obj->rot.z = zero;
    obj->rot.x = zero;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_8002979C_2A39C(obj->model[0], obj->rot.x, obj->rot.y, obj->rot.z);
    func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    w = obj->unk_50 = func_80027154_27D54(0x15C, 0x7918);
    func_800B0EF0_B1AF0(w, 0, 0x15C);
    w->unk_50 = 0;
    w->unk_52 = 0;
    w->unk_59 = (u8)D_8010882C_29789C_DeepSeaSalvage;
    w->unk_57 = gPlayers[D_8010882C_29789C_DeepSeaSalvage].port;
    w->unk_D0 = 0xFFFF;
    obj->func_ptr = func_80103508_292578_DeepSeaSalvage;
    d = DSS_OBJ_WORK(obj) = func_80027154_27D54(sizeof(DSSDiver), 0x7918);
    d->x = obj->trans.x;
    d->y = obj->trans.y;
    d->z = obj->trans.z;
    d->vx = d->vy = d->unk14 = zero;
    d->state = 0;
    d->kick = zero;
    d->kickWait = 8;
    d->timer = 46;
    d->idle = 0;
    d->player = D_8010882C_29789C_DeepSeaSalvage;
    d->target = -1;
    d->stun = 0;
    d->blink = 0;
    D_8010882C_29789C_DeepSeaSalvage++;
}

s16 func_80103480_2924F0_DeepSeaSalvage(s16 sfx, u8 player) {
    s16 ret;

    ret = func_80079798_7A398(gPlayers[player].character + sfx, (s16)D_80108490_297500_DeepSeaSalvage);
    if (++D_80108490_297500_DeepSeaSalvage >= 3) {
        D_80108490_297500_DeepSeaSalvage = 1;
    }
    return ret;
}

/* A diver: input (pad, or the CPU swimming to a treasure), swimming, picking treasure up. */
void func_80103508_292578_DeepSeaSalvage(omObjData* obj) {
    f32 ox;
    f32 oy;
    DSSDiver* d;
    MgWork* w;
    DSSTreasure* t;
    u16 btn;
    s16 stk;
    s16 idx;

    btn = 0;
    d = DSS_OBJ_WORK(obj);
    w = obj->unk_50;
    stk = 0;
    switch (d->state) {
    case 0:
        if (--d->timer == 0) {
            d->state++;
            d->timer = 40;
        }
        break;
    case 1:
        if (--d->timer == 0) {
            d->state++;
        }
        if (d->timer & 1) {
            btn |= 0x8000;
        }
        break;
    case 2:
        if (D_80108824_297894_DeepSeaSalvage != 0) {
            break;
        }
    default:
        if (d->stun != 0) {
            break;
        }
        if (!(gPlayers[d->player].flags & 1)) {
            stk = ContStkX[w->unk_57];
            btn = ContBtnTrg[w->unk_57];
            break;
        }
        if (d->target < 0) {
            if (D_801088B8_297928_DeepSeaSalvage != 0) {
                d->target = D_80108890_297900_DeepSeaSalvage[func_80106100_295170_DeepSeaSalvage(D_801088B8_297928_DeepSeaSalvage)];
            }
            if (d->target < 0) {
                break;
            }
        }
        t = (DSSTreasure*)DSS_OBJ_WORK(D_80108EB8_297F28_DeepSeaSalvage) + d->target;
        if (t->taken != 0 || t->flags == 0) {
            d->target = -1;
            break;
        }
        if (fabs(t->x - d->x) > 30.0f - gPlayers[d->player].cpu_difficulty * 5.0f) {
            stk = 5;
            if (t->x < d->x) {
                stk = -5;
            }
        }
        if (d->y < t->y) {
            if ((gPlayers[d->player].cpu_difficulty + 1) * 4 > func_80106100_295170_DeepSeaSalvage(6)) {
                btn |= 0x8000;
            }
        }
        break;
    }
    if (DSS_ABS(stk) >= 5) {
        if (stk < 0) {
            d->vx -= 1.0f;
            if (d->vx < -8.0f) {
                d->vx = -8.0f;
            }
        } else {
            d->vx += 1.0f;
            if (d->vx > 8.0f) {
                d->vx = 8.0f;
            }
        }
    }
    if (btn & 0x8000) {
        d->vy += 8.0f;
        d->kick += 0.5f;
        d->kickWait = 8;
    } else if (d->kickWait != 0) {
        d->kickWait--;
    } else {
        d->idle++;
    }
    if (D_80108826_297896_DeepSeaSalvage == 0) {
        d->vy -= 0.5f;
    }
    if (d->vy > 10.0f) {
        d->vy = 10.0f;
    }
    if (d->vy < -10.0f) {
        d->vy = -10.0f;
    }
    if (D_80108826_297896_DeepSeaSalvage == 0) {
        d->x += d->vx;
        d->y += d->vy;
    }
    func_80106D5C_295DCC_DeepSeaSalvage(obj, d->vx, d->vy);
    ox = oy = 0.0f;
    func_80106518_295588_DeepSeaSalvage(&d->x, &d->y, 90, 0, &ox, &oy);
    func_80106134_2951A4_DeepSeaSalvage(&d->x, &d->y, &d->z);
    if (d->stun == 0) {
        if (d->blink == 0) {
            idx = func_80106CC4_295D34_DeepSeaSalvage(d->x, d->y);
            if (idx >= 0) {
                t = (DSSTreasure*)DSS_OBJ_WORK(D_80108EB8_297F28_DeepSeaSalvage) + idx;
                t->taken = 1;
                switch (t->kind) {
                case 0:
                    PlaySound(9);
                    gPlayers[d->player].coins_mg++;
                    func_80105E84_294EF4_DeepSeaSalvage(d->player, 1);
                    D_801088BE_29792E_DeepSeaSalvage[d->player]++;
                    break;
                case 1:
                    PlaySound(0x15);
                    gPlayers[d->player].coins_mg += 5;
                    func_80105E84_294EF4_DeepSeaSalvage(d->player, 5);
                    D_801088BE_29792E_DeepSeaSalvage[d->player]++;
                    break;
                case 2:
                    omVibrate(d->player, 20, 0, 20);
                    func_80103480_2924F0_DeepSeaSalvage(0x111, d->player);
                    d->vx = d->vy = d->unk14 = 0.0f;
                    d->stun = 32;
                    break;
                }
            }
        }
        if (d->vx < 0.0f) {
            obj->rot.y -= 11.25f;
            if (obj->rot.y < -90.0f) {
                obj->rot.y = -90.0f;
            }
        } else {
            obj->rot.y += 11.25f;
            if (obj->rot.y > 90.0f) {
                obj->rot.y = 90.0f;
            }
        }
        d->kick -= 0.05f;
        if (d->kick > 2.0f) {
            d->kick = 2.0f;
        } else if (d->kick < 0.0f) {
            d->kick = 0.0f;
        }
        func_80029FE4_2ABE4(obj->model[0], d->kick);
    }
    if ((d->kickWait == 0) & ((d->idle & 7) == 0)) {
        func_801070D0_296140_DeepSeaSalvage(0, HuMathSin(obj->rot.y) * -70.0f + obj->trans.x, obj->trans.y,
                                            obj->trans.z, 0);
    }
    if (d->blink != 0) {
        D_800FC834_FD434[obj->model[0]].unk18 ^= 4;
        if (--d->blink == 0) {
            D_800FC834_FD434[obj->model[0]].unk18 &= ~4;
        }
    }
    if (d->stun != 0) {
        obj->trans.x = (f32)(d->stun & 1) * 40.0f - 20.0f + d->x;
        obj->rot.x += 11.25;
        if (--d->stun == 0) {
            d->blink = 45;
        }
    } else {
        obj->trans.x = d->x;
    }
    obj->trans.y = d->y;
    obj->trans.z = d->z;
}

/* The boat: the thrower at the surface (work[0] throw countdown, [1] wait, [2] throws made,
   [3] sway phase). */
void func_80103DCC_292E3C_DeepSeaSalvage(omObjData* obj) {
    MgWork* w;

    w = obj->unk_50 = func_80027154_27D54(sizeof(MgWork), 0x7918);
    func_800B0EF0_B1AF0(w, 0, sizeof(MgWork));
    w->unk_50 = 0;
    w->unk_52 = 0;
    w->unk_D0 = 0xFFFF;
    obj->model[0] = LoadFormFile(0x4C0000, 0x2B9);
    obj->model[1] = LoadFormFile(0x4C0009, 0x2B9);
    w->unk_E8 = func_80027154_27D54(obj->mtncnt * sizeof(MgWork), 0x7918);
    func_800B0EF0_B1AF0(w->unk_E8, 0, obj->mtncnt * sizeof(MgWork));
    func_80019E84_1AA84(obj, 0, 0x4C0000, 1, 0);
    func_80019E84_1AA84(obj, 1, 0x4C0001, 1, 0);
    func_80019E84_1AA84(obj, 2, 0x4C0002, 0, 0);
    func_80019B9C_1A79C(obj, 0);
    func_80029E80_2AA80(obj->model[1], 2, 2);
    obj->trans.x = 0.0f;
    obj->trans.y = 570.0f;
    obj->trans.z = -300.0f;
    obj->rot.y = obj->rot.x = obj->rot.z = 0.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_8002979C_2A39C(obj->model[0], obj->rot.x, obj->rot.y, obj->rot.z);
    func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    func_80029714_2A314(obj->model[1], obj->trans.x + 50.0, obj->trans.y + 6.0, obj->trans.z + 100.0);
    func_8002979C_2A39C(obj->model[1], obj->rot.x, obj->rot.y, obj->rot.z);
    func_800297E8_2A3E8(obj->model[1], obj->scale.x, obj->scale.y, obj->scale.z);
    obj->func_ptr = func_80104070_2930E0_DeepSeaSalvage;
    obj->work[0] = 0;
    obj->work[1] = 1;
    obj->work[2] = 0;
    obj->work[3] = 0x40;
}

void func_80104070_2930E0_DeepSeaSalvage(omObjData* obj) {
    f64 phase;
    f32 sway;
    MgWork* w;
    s16 i;

    sway = 0.0f;
    if (D_80108824_297894_DeepSeaSalvage == 0) {
        w = obj->unk_50;
        phase = (f32)obj->work[3] * 1.40625;
        obj->work[3]++;
        sway = HuMathSin(phase) * 16.0f;
        if (sway > 8.0f) {
            sway = 8.0f;
        } else if (sway < -8.0f) {
            sway = -8.0f;
        }
        obj->trans.x += sway;
        if (--obj->work[1] == 0) {
            if (obj->work[2] < 23) {
                obj->work[0] = 16;
                func_80019B9C_1A79C(obj, 2);
                func_80029FE4_2ABE4(obj->model[0], 2.0f);
            }
            obj->work[1] = 47 - obj->work[2];
        }
        if (obj->work[0] != 0) {
            if (--obj->work[0] == 0) {
                for (i = 0; i < 4; i++) {
                    if ((D_80108870_2978E0_DeepSeaSalvage[obj->work[2]] >> i) & 1) {
                        func_801052E8_294358_DeepSeaSalvage(
                            obj, D_80108838_2978A8_DeepSeaSalvage[i][D_80108888_2978F8_DeepSeaSalvage[i]++], i);
                    }
                }
                obj->work[2]++;
            }
        }
        if (w->unk_DA == 2 && w->unk_D0 == 0xFFFF) {
            func_80019B9C_1A79C(obj, 0);
            func_80029FE4_2ABE4(obj->model[0], 1.0f);
        }
    }
    func_80029FE4_2ABE4(obj->model[1], fabsf(sway / 2.0f));
    obj->trans.y += -HuMathSin((D_80108494_297504_DeepSeaSalvage & 0x3F) * 5.625) * 0.5f;
    D_80108494_297504_DeepSeaSalvage++;
    func_80029714_2A314(obj->model[1], obj->trans.x + 50.0, obj->trans.y + 6.0, obj->trans.z + 100.0);
    func_80019378_19F78(obj);
}

void func_801043A4_293414_DeepSeaSalvage(void) {
    D_801088E0_297950_DeepSeaSalvage[0] = func_80018D64_19964(0xE, 0x28D, 8);
    D_801088E0_297950_DeepSeaSalvage[1] = func_80018D64_19964(0x25, 0x28D, 8);
    D_801088E0_297950_DeepSeaSalvage[2] = func_80018D64_19964(0x4C000E, 0x28D, 8);
    D_801088E0_297950_DeepSeaSalvage[3] = func_80018D64_19964(0x14, 0x28D, 8);
    D_801088E0_297950_DeepSeaSalvage[4] = func_80018D64_19964(0x3B0011, 0x28D, 8);
    D_80108EB8_297F28_DeepSeaSalvage = omAddObj(4, 20, 0, -1, func_80104944_2939B4_DeepSeaSalvage);
    func_801044A8_293518_DeepSeaSalvage();
    D_80108888_2978F8_DeepSeaSalvage[0] = D_80108888_2978F8_DeepSeaSalvage[1] = D_80108888_2978F8_DeepSeaSalvage[2] =
        D_80108888_2978F8_DeepSeaSalvage[3] = 0;
    D_801088B8_297928_DeepSeaSalvage = 0;
    D_801088BA_29792A_DeepSeaSalvage[0] = D_801088BA_29792A_DeepSeaSalvage[1] = 0;
    D_801088BE_29792E_DeepSeaSalvage[0] = D_801088BE_29792E_DeepSeaSalvage[1] = D_801088BE_29792E_DeepSeaSalvage[2] =
        D_801088BE_29792E_DeepSeaSalvage[3] = 0;
}

/* The throw plan: each lane's 13 drops shuffled (D_80108838), then 23 throws (D_80108870, lane
   bits): pattern 0 throws in all four lanes, 1 in two lanes (a pair from a[]), 2 in one lane. */
void func_801044A8_293518_DeepSeaSalvage(void) {
    u8 pairs[8] = { 3, 5, 6, 9, 10, 12, 0, 0 };
    u8 ones[8] = { 1, 2, 4, 8, 1, 2, 4, 8 };
    u8 pat[23];
    s16 i;
    s16 j;
    s16 k;
    s16 k2;
    s16 oi;
    u8 tmp;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 13; j++) {
            D_80108838_2978A8_DeepSeaSalvage[i][j] = D_80108498_297508_DeepSeaSalvage[j];
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 100; j++) {
            k = func_80106100_295170_DeepSeaSalvage(13);
            k2 = func_80106100_295170_DeepSeaSalvage(13);
            tmp = D_80108838_2978A8_DeepSeaSalvage[i][k];
            D_80108838_2978A8_DeepSeaSalvage[i][k] = D_80108838_2978A8_DeepSeaSalvage[i][k2];
            D_80108838_2978A8_DeepSeaSalvage[i][k2] = tmp;
        }
    }
    for (j = 0; j < 21; j += 3) {
        if (j == 0) {
            k = func_80106100_295170_DeepSeaSalvage(2);
        } else {
            k = func_80106100_295170_DeepSeaSalvage(6);
        }
        pat[j] = D_801084A8_297518_DeepSeaSalvage[k][0];
        pat[j + 1] = D_801084A8_297518_DeepSeaSalvage[k][1];
        pat[j + 2] = D_801084A8_297518_DeepSeaSalvage[k][2];
    }
    if (func_80106100_295170_DeepSeaSalvage(2)) {
        pat[j] = 1;
        pat[j + 1] = 2;
    } else {
        pat[j] = 2;
        pat[j + 1] = 1;
    }
    switch (func_80106100_295170_DeepSeaSalvage(3)) {
    case 0:
        pairs[6] = 3;
        pairs[7] = 12;
        break;
    case 1:
        pairs[6] = 5;
        pairs[7] = 10;
        break;
    case 2:
        pairs[6] = 6;
        pairs[7] = 9;
        break;
    }
    for (j = 0; j < 100; j++) {
        k = func_80106100_295170_DeepSeaSalvage(8);
        k2 = func_80106100_295170_DeepSeaSalvage(8);
        tmp = pairs[k];
        pairs[k] = pairs[k2];
        pairs[k2] = tmp;
    }
    for (j = 0; j < 100; j++) {
        k = func_80106100_295170_DeepSeaSalvage(8);
        k2 = func_80106100_295170_DeepSeaSalvage(8);
        tmp = ones[k];
        ones[k] = ones[k2];
        ones[k2] = tmp;
    }
    oi = 0;
    k = 0;
    for (j = 0; j < 23; j++) {
        switch (pat[j]) {
        case 0:
            D_80108870_2978E0_DeepSeaSalvage[j] = 15;
            break;
        case 1:
            D_80108870_2978E0_DeepSeaSalvage[j] = pairs[k++];
            break;
        case 2:
            D_80108870_2978E0_DeepSeaSalvage[j] = ones[oi++];
            break;
        }
    }
}

/* The treasure object: 20 treasures, each a sprite model (obj->model[i]). */
void func_80104944_2939B4_DeepSeaSalvage(omObjData* obj) {
    void* w;
    DSSTreasure* t;
    s16 i;

    w = obj->unk_50 = func_80027154_27D54(0xAC, 0x7918);
    func_800B0EF0_B1AF0(w, 0, 0xAC);
    t = func_80027154_27D54(20 * sizeof(DSSTreasure), 0x7918);
    DSS_OBJ_WORK(obj) = t;
    obj->func_ptr = func_80104A70_293AE0_DeepSeaSalvage;
    for (i = 0; i < 20; i++, t++) {
        t->sprite = func_8002109C_21C9C(D_801088E0_297950_DeepSeaSalvage[0], 0);
        obj->model[i] = D_800F86D8_F92D8[t->sprite].unk00;
        if (i == 0) {
            obj->scale.x = obj->scale.y = obj->scale.z = 2.5f;
        }
        func_800297E8_2A3E8(obj->model[i], 2.5f, 2.5f, 2.5f);
        t->flags = 0;
    }
}

/* The treasures: a new one (flags 1, from func_801052E8) is thrown in an arc from the boat to a
   point in its lane, then sinks to the sea floor or below the screen; a diver's touch (taken)
   collects it with a sparkle (or a shine for the hazard). */
void func_80104A70_293AE0_DeepSeaSalvage(omObjData* obj) {
    DSSTreasure* t;
    f32 vy;
    f32 s;
    f32 time;
    s16 i;

    t = DSS_OBJ_WORK(obj);
    for (i = 0; i < 20; i++, t++) {
        if (t->flags == 0) {
            continue;
        }
        if (t->flags >= 0) {
            t->flags |= 0x8000;
            t->taken = 0;
            t->state = 0;
            D_800FC834_FD434[obj->model[i]].unk18 &= ~4;
            t->sx = t->sy = t->sz = D_801084C8_297538_DeepSeaSalvage[t->kind];
            t->vz = 0.0f;
            t->vy = vy = func_80106100_295170_DeepSeaSalvage(8) + 32.0f;
            time = -vy;
            s = sqrtf(vy * vy - -(530.0f - t->y) * -4.0);
            time = (time - s) / -2.0f;
            switch (t->lane) {
            case 0:
                if (D_801088BA_29792A_DeepSeaSalvage[0] != 0) {
                    t->tx = (t->lane - 2) * 356.0f + 311.5f + func_80106100_295170_DeepSeaSalvage(44);
                    break;
                }
            case 3:
                if (D_801088BA_29792A_DeepSeaSalvage[1] != 0) {
                    t->tx = (t->lane - 2) * 356.0f + func_80106100_295170_DeepSeaSalvage(44);
                    break;
                }
            default:
                t->tx = (t->lane - 2) * 356.0f + 44.5f + func_80106100_295170_DeepSeaSalvage(267);
                break;
            }
            t->vx = (t->tx - t->x) / time;
            t->floor = func_801069E4_295A54_DeepSeaSalvage(t->tx, t->y);
            if (t->floor > -372.0f) {
                t->flags |= 0x80;
                t->floor += 20.0f;
                if (t->tx < 0.0f) {
                    D_801088BA_29792A_DeepSeaSalvage[0] = 1;
                } else {
                    D_801088BA_29792A_DeepSeaSalvage[1] = 1;
                }
            }
            D_800F86D8_F92D8[t->sprite].unk06 = D_800F86D8_F92D8[t->sprite].unk04 =
                D_800F86D8_F92D8[t->sprite].unk08 = D_800F86D8_F92D8[t->sprite].unk0A = 0;
            D_800F86D8_F92D8[t->sprite].unk12 = D_800F86D8_F92D8[t->sprite].unk13 =
                D_800F86D8_F92D8[t->sprite].unk14 = D_800F86D8_F92D8[t->sprite].unk15 = 0xFF;
            func_800211E8_21DE8(t->sprite, 0xFF);
            D_800F86D8_F92D8[t->sprite].unk02 = D_800F86D8_F92D8[D_801088E0_297950_DeepSeaSalvage[t->kind]].unk02;
            goto place;
        }
        switch (t->state) {
        case 0:
            if (t->y <= 530.0f) {
                t->state++;
                t->x = t->tx;
                t->vx = 0.0f;
                func_801070D0_296140_DeepSeaSalvage(1, t->x, 0.0f, t->z, 0);
            }
            t->vy -= 2.0f;
            break;
        case 1:
            if (t->y <= -572.0f) {
                t->flags = 0;
                D_800FC834_FD434[obj->model[i]].unk18 |= 4;
            }
            t->vy -= 0.5f;
            if (t->vy < D_801084BC_29752C_DeepSeaSalvage[t->kind]) {
                t->vy = D_801084BC_29752C_DeepSeaSalvage[t->kind];
            }
            if (t->taken != 0 || D_80108828_297898_DeepSeaSalvage == 0) {
                t->state++;
                t->vx = t->vy = t->vz = 0.0f;
                t->timer = 16;
                if (t->flags & 0x80) {
                    if (t->tx < 0.0f) {
                        D_801088BA_29792A_DeepSeaSalvage[0] = 0;
                    } else {
                        D_801088BA_29792A_DeepSeaSalvage[1] = 0;
                    }
                }
                D_800F86D8_F92D8[t->sprite].unk06 = D_800F86D8_F92D8[t->sprite].unk04 =
                    D_800F86D8_F92D8[t->sprite].unk08 = D_800F86D8_F92D8[t->sprite].unk0A = 0;
                if (t->kind != 2) {
                    D_800F86D8_F92D8[t->sprite].unk02 = D_800F86D8_F92D8[D_801088E0_297950_DeepSeaSalvage[3]].unk02;
                    func_800211E8_21DE8(t->sprite, 0xC0);
                    func_80021250_21E50(t->sprite, 0xFF, 0xFF, 0xBE);
                    t->sz = t->sy = t->sx = 8.0f;
                } else {
                    D_800F86D8_F92D8[t->sprite].unk02 = D_800F86D8_F92D8[D_801088E0_297950_DeepSeaSalvage[4]].unk02;
                    func_80021250_21E50(t->sprite, 0xFF, 0xFF, 0xFF);
                    t->sx = t->sy = t->sz = 6.0f;
                    PlaySound(0x313);
                }
            }
            break;
        case 2:
            if (--t->timer == 0) {
                t->flags = 0;
                D_800FC834_FD434[obj->model[i]].unk18 |= 4;
            }
            break;
        }
        t->x += t->vx;
        t->y += t->vy;
        t->z += t->vz;
        if ((t->flags & 0x80) && t->y < t->floor) {
            t->y = t->floor;
            if (t->kind == 2) {
                t->taken = 1;
            }
        }
    place:
        if (i == 0) {
            obj->trans.x = t->x;
            obj->trans.y = t->y;
            obj->trans.z = t->z;
            obj->scale.x = t->sx;
            obj->scale.y = t->sy;
            obj->scale.z = t->sz;
        } else {
            func_80029714_2A314(obj->model[i], t->x, t->y, t->z);
            func_800297E8_2A3E8(obj->model[i], t->sx, t->sy, t->sz);
        }
    }
}

/* The treasures a CPU may aim at: placed, untouched, still in the water. */
void func_80105258_2942C8_DeepSeaSalvage(void) {
    DSSTreasure* t;
    s16 i;

    t = DSS_OBJ_WORK(D_80108EB8_297F28_DeepSeaSalvage);
    D_801088B8_297928_DeepSeaSalvage = 0;
    for (i = 0; i < 20; i++, t++) {
        if (t->flags < 0 && t->taken == 0 && t->state < 2) {
            D_80108890_297900_DeepSeaSalvage[D_801088B8_297928_DeepSeaSalvage++] = i;
        }
    }
}

/* A new treasure of a kind for a lane, thrown from the boat; its index, -1 if all 20 are out. */
s16 func_801052E8_294358_DeepSeaSalvage(omObjData* boat, s16 kind, s16 lane) {
    DSSTreasure* t;
    s16 i;

    t = DSS_OBJ_WORK(D_80108EB8_297F28_DeepSeaSalvage);
    for (i = 0; i < 20; i++, t++) {
        if (t->flags == 0) {
            t->flags = 1;
            t->kind = kind;
            t->lane = lane;
            t->x = boat->trans.x;
            t->y = boat->trans.y + 80.0f;
            t->z = -100.0f;
            return i;
        }
    }
    return -1;
}

/* Effect 0: a bubble rising and wobbling (MP1 func_800FA62C). */
void func_8010536C_2943DC_DeepSeaSalvage(s16 idx) {
    if (D_80109CE0_298D50_DeepSeaSalvage[idx].flags >= 0) {
        D_80109CE0_298D50_DeepSeaSalvage[idx].flags |= 0x8000;
        SprAttrSet(D_80109CE0_298D50_DeepSeaSalvage[idx].sprite, 0, func_801060C8_295138_DeepSeaSalvage() & 1);
        SprAnimSet(D_80109CE0_298D50_DeepSeaSalvage[idx].sprite, 0, D_80108EA0_297F10_DeepSeaSalvage, 0);
        func_8008225C_82E5C(D_80109CE0_298D50_DeepSeaSalvage[idx].sprite, 0, 0);
        SprBankSet(D_80109CE0_298D50_DeepSeaSalvage[idx].sprite, 0, func_801060C8_295138_DeepSeaSalvage() & 3);
        D_80109CE0_298D50_DeepSeaSalvage[idx].life = 32;
        SprScaleSet(D_80109CE0_298D50_DeepSeaSalvage[idx].sprite, 0, 4.0f, 4.0f);
    }
    D_80109CE0_298D50_DeepSeaSalvage[idx].x += HuMathSin((D_80109CE0_298D50_DeepSeaSalvage[idx].timer * 4) % 360) * 5.0;
    D_80109CE0_298D50_DeepSeaSalvage[idx].y += 5.0;
    D_80109CE0_298D50_DeepSeaSalvage[idx].sy = HuMathSin((D_80109CE0_298D50_DeepSeaSalvage[idx].timer << 5) % 360) * 0.125 + 0.875;
    D_80109CE0_298D50_DeepSeaSalvage[idx].timer++;
    if (D_80109CE0_298D50_DeepSeaSalvage[idx].fade != 0) {
        if (--D_80109CE0_298D50_DeepSeaSalvage[idx].fade == 0) {
            func_801072C0_296330_DeepSeaSalvage(idx);
        }
        func_80082488_83088(D_80109CE0_298D50_DeepSeaSalvage[idx].sprite, 0, D_80109CE0_298D50_DeepSeaSalvage[idx].fade << 5);
    } else if (--D_80109CE0_298D50_DeepSeaSalvage[idx].life == 0 || D_80109CE0_298D50_DeepSeaSalvage[idx].y >= 370.0) {
        D_80109CE0_298D50_DeepSeaSalvage[idx].fade = 8;
    }
}

/* Effect 1: a splash on the surface (MP1 TreasureDivers func_800F9580). */
void func_801056FC_29476C_DeepSeaSalvage(s16 idx) {
    if (D_80109CE0_298D50_DeepSeaSalvage[idx].flags >= 0) {
        D_80109CE0_298D50_DeepSeaSalvage[idx].flags |= 0x8000;
        D_80109CE0_298D50_DeepSeaSalvage[idx].y = 538.0f;
        SprAnimSet(D_80109CE0_298D50_DeepSeaSalvage[idx].sprite, 0, D_80108E98_297F08_DeepSeaSalvage[0], 0);
        SprScaleSet(D_80109CE0_298D50_DeepSeaSalvage[idx].sprite, 0, 3.0f, 2.0f);
        PlaySound(0x88);
        return;
    }
    if (func_80082314_82F14(D_80109CE0_298D50_DeepSeaSalvage[idx].sprite, 0) & 2) {
        func_801072C0_296330_DeepSeaSalvage(idx);
    }
}

void func_80105804_294874_DeepSeaSalvage(DSSHud* hud, s16 member, u16 anim, u16 x, s32 y) {
    SprAnimSet(hud->group, member, anim, 0);
    SprAttrSet(hud->group, member, 0x1000);
    SprPosSet(hud->group, member, x, y);
    SprPrioSet(hud->group, member, 0xFFF4);
}

/* The HUD: four faces, four coin icons, four "x" signs and three digits per player. */
/* NON_MATCHING: retail stores the group by its address (%hi/%lo of D_80108EC0+4) although
   hud holds &D_80108EC0; GCC stores through hud (masked 11, addressing and registers only). */
#ifdef NON_MATCHING
void func_801058A0_294910_DeepSeaSalvage(omObjData* obj) {
    s16 i;
    s16 j;
    u16 anim;
    DSSHud* hud;

    hud = &D_80108EC0_297F30_DeepSeaSalvage;
    func_800B0EF0_B1AF0(hud, 0, sizeof(DSSHud));
    func_800B0EF0_B1AF0(D_8010ABF8_299C68_DeepSeaSalvage, 0, 0x30);
    D_80108EC0_297F30_DeepSeaSalvage.group = SprCreate(24, 0);
    for (i = 0; i < 4; i++) {
        func_80105804_294874_DeepSeaSalvage(hud, i,
                                            func_8001A2F8_1AEF8(D_80108514_297584_DeepSeaSalvage[gPlayers[i].character]),
                                            D_801084D4_297544_DeepSeaSalvage[i][0], D_801084D4_297544_DeepSeaSalvage[i][1]);
    }
    anim = func_8001A2F8_1AEF8(0x480006);
    for (; i < 8; i++) {
        func_80105804_294874_DeepSeaSalvage(hud, i, anim, D_801084D4_297544_DeepSeaSalvage[i][0],
                                            D_801084D4_297544_DeepSeaSalvage[i][1]);
    }
    anim = func_8001A2F8_1AEF8(0x170010);
    for (; i < 12; i++) {
        func_80105804_294874_DeepSeaSalvage(hud, i, anim, D_801084D4_297544_DeepSeaSalvage[i][0],
                                            D_801084D4_297544_DeepSeaSalvage[i][1]);
    }
    anim = func_8001A2F8_1AEF8(0x43);
    for (j = i; j < 16; j++) {
        func_80105804_294874_DeepSeaSalvage(hud, i++, anim, D_801084D4_297544_DeepSeaSalvage[j][0],
                                            D_801084D4_297544_DeepSeaSalvage[j][1]);
        func_80105804_294874_DeepSeaSalvage(hud, i, anim, D_801084D4_297544_DeepSeaSalvage[j][0] + 12,
                                            D_801084D4_297544_DeepSeaSalvage[j][1]);
        SprAttrSet(hud->group, i++, 0x8000);
        func_80105804_294874_DeepSeaSalvage(hud, i, anim, D_801084D4_297544_DeepSeaSalvage[j][0] + 24,
                                            D_801084D4_297544_DeepSeaSalvage[j][1]);
        SprAttrSet(hud->group, i++, 0x8000);
    }
    obj->func_ptr = func_80105BB8_294C28_DeepSeaSalvage;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_801058A0_294910_DeepSeaSalvage);
#endif

/* The scores: count the shown number one step towards the score (left-aligned digits), then
   pop it. */
/* NON_MATCHING: retail tests d and lead with two branches; GCC folds the || into flag
   arithmetic (masked 23, that test's shape only). */
#ifdef NON_MATCHING
void func_80105BB8_294C28_DeepSeaSalvage(omObjData* obj) {
    DSSHud* hud;
    DSSScore* sc;
    f32 s;
    s16 i;
    s16 m;
    s16 lead;
    u16 n;
    u16 d;

    hud = &D_80108EC0_297F30_DeepSeaSalvage;
    for (i = 0; i < 4; i++) {
        sc = &D_8010ABF8_299C68_DeepSeaSalvage[i];
        switch (sc->state) {
        case 0:
            if (sc->shown != sc->coins) {
                if (sc->shown < sc->coins) {
                    n = sc->shown + 1;
                } else {
                    n = sc->shown - 1;
                }
                lead = 0;
                m = i * 3 + 12;
                d = n / 100;
                if (d != 0) {
                    SprBankSet(hud->group, m++, d);
                    lead = 1;
                } else {
                    SprAttrSet(hud->group, m + 2, 0x8000);
                }
                d = (u16)(n % 100) / 10;
                if (d != 0 || lead != 0) {
                    SprBankSet(hud->group, m++, d);
                } else {
                    SprAttrSet(hud->group, m + 1, 0x8000);
                }
                SprBankSet(hud->group, m, n % 10);
                SprAttrReset(hud->group, m, 0x8000);
                sc->shown = n;
                sc->state = 1;
            }
            break;
        case 1:
            m = i + 4;
            sc->angle += 40.0f;
            if (sc->angle > 180.0f) {
                sc->angle = 0.0f;
                sc->state = 0;
            }
            s = func_800B80D0_B8CD0(sc->angle) + 1.0;
            SprScaleSet(hud->group, m, s, s);
            break;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3C_DeepSeaSalvage/291870", func_80105BB8_294C28_DeepSeaSalvage);
#endif

void func_80105E84_294EF4_DeepSeaSalvage(s32 player, s16 coins) {
    DSSScore* sc = &D_8010ABF8_299C68_DeepSeaSalvage[player];

    sc->coins += coins;
}
