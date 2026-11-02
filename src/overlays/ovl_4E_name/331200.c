#include "ovl_4E.h"

u32 func_80109840_331200_name_4E(u32 param) {
    s32 rand2, rand3;

    if (param == 0) {
        param = rand8();
        param = param ^ osGetCount();
        param ^= 0xD826BC89;
    }

    rand2 = param / 0x1F31D;
    rand3 = param - (rand2 * 0x1F31D);
    param = rand2 * 0xB14;
    param = param - rand3 * 0x41A7;
    return param;
}

s32 func_80109914_3312D4_name_4E(void) {
    return D_8010D79C_33515C_name_4E = func_80109840_331200_name_4E(D_8010D79C_33515C_name_4E);
}

u32 func_8010993C_3312FC_name_4E(u32 arg0) {
    u32 val;

    val = func_80109840_331200_name_4E(D_8010D79C_33515C_name_4E);
    D_8010D79C_33515C_name_4E = val;
    return val % arg0;
}

void func_80109988_331348_name_4E(void) {
    if (D_800FDC6C_FE86C >= (D_8010D7A0_335160_name_4E + 4)) {
        PlaySound(0x324);
        D_8010D7A0_335160_name_4E = D_800FDC6C_FE86C;
    }
}

/* The roulette: slides in (0), spins and stops on work[2] (1), then notes the pick in the recent
   lists and starts it (2). Scale x = speed, y = reversed once, z = phase. */
void func_801099D4_331394_name_4E(omObjData* obj) {
    s32 i;
    s16 base;
    Ovl4EMgSlot* p;

    switch (obj->work[0]) {
        case 0:
            obj->trans.y += 16.0f;
            for (i = 0; i < D_8010DC77_335637_name_4E; i++) {
                p = &D_8010DC30_3355F0_name_4E[i];
                func_800896DC_8A2DC(p->win, (s16)(p->x + p->w / 2), (s32)obj->trans.y + p->y + p->h / 2);
            }
            base = D_8010D77C_33513C_name_4E[D_8010DC77_335637_name_4E];
            SprPosSet(D_8010DC78_335638_name_4E, 0, 160, base + ((s32)obj->trans.y + D_8010DC30_3355F0_name_4E[0].y));
            if (obj->trans.y >= 218.0f) {
                func_80109988_331348_name_4E();
                obj->work[0] = 1;
                obj->scale.x = 1.0f;
                obj->scale.z = -1.0f;
                obj->scale.y = 0.0f;
                obj->work[1] = 0;
                obj->work[2] = MBRand(D_8010DC77_335637_name_4E);
                obj->work[3] = 0;
                func_8010A588_331F48_name_4E();
            }
            break;
        case 1:
            obj->scale.z += obj->scale.x;
            if (obj->scale.z >= 1.0f) {
                if (obj->work[3] != 0 && obj->scale.x <= 0.08f) {
                    obj->work[3]--;
                }
                obj->scale.z -= 1.0f;
                if (obj->scale.y == 0.0f) {
                    obj->work[1]++;
                    obj->work[1] %= D_8010DC77_335637_name_4E;
                } else {
                    obj->work[1]--;
                    if (obj->work[1] >= 128) {
                        obj->work[1] = D_8010DC77_335637_name_4E - 1;
                    }
                }
                func_80109988_331348_name_4E();
            }
            for (i = 0; i < D_8010DC77_335637_name_4E; i++) {
                p = &D_8010DC30_3355F0_name_4E[i];
                if (i == obj->work[1]) {
                    func_8008D530_8E130(p->win, 0, 200, 0);
                    func_80089B2C_8A72C(p->win, 0x100);
                    func_80089A7C_8A67C(p->win, 9000);
                } else {
                    func_8008D530_8E130(p->win, 0x40, 0x40, 0x80);
                    func_80089B2C_8A72C(p->win, 0);
                    func_80089A7C_8A67C(p->win, 10000);
                }
            }
            if (obj->work[1] == obj->work[2] || obj->scale.x < 1.0f) {
                obj->scale.x -= 0.02;
            }
            if (obj->scale.x <= 0.08f) {
                obj->scale.x = 0.08f;
                if (obj->work[1] == obj->work[2] && obj->work[3] == 0 && obj->scale.z + obj->scale.x >= 1.0f) {
                    if ((rand8() & 0xF) || obj->scale.y == 1.0f || obj->work[1] == 0) {
                        PlaySound(0x325);
                        obj->work[0] = 2;
                        obj->work[3] = 60;
                        func_8008AD84_8B984();
                        func_8008AD44_8B944(D_8010DC30_3355F0_name_4E[obj->work[1]].win);
                        func_800890CC_89CCC(D_8010DC30_3355F0_name_4E[obj->work[1]].win, D_8010DC70_335630_name_4E[obj->work[1]] + 0x3D8, -2, 4);
                        switch (D_8010DC70_335630_name_4E[obj->work[1]]) {
                            case 0x19:
                            case 0x24:
                            case 0x38:
                                func_80089C78_8A878(D_8010DC30_3355F0_name_4E[obj->work[1]].win, 4);
                                break;
                            default:
                                func_80089C78_8A878(D_8010DC30_3355F0_name_4E[obj->work[1]].win, 1);
                                break;
                        }
                        func_80089DA0_8A9A0(D_8010DC30_3355F0_name_4E[obj->work[1]].win, 0xA0, 0xA0, 0xA0);
                        func_8008D530_8E130(D_8010DC30_3355F0_name_4E[obj->work[1]].win, 0xFE, 0xFF, 0xD0);
                        func_80089A48_8A648(D_8010DC30_3355F0_name_4E[obj->work[1]].win, 0);
                    } else {
                        obj->scale.y = 1.0f;
                        obj->work[2]--;
                        if (obj->work[2] >= 128) {
                            obj->work[2] = D_8010DC77_335637_name_4E - 1;
                        }
                    }
                }
            }
            break;
        case 2:
            if (obj->work[3] != 0) {
                obj->work[3]--;
            } else {
                OVL4E_RECENT(D_8010DC76_335636_name_4E)[OVL4E_RECENT_IDX(D_8010DC76_335636_name_4E)] = D_8010DC70_335630_name_4E[obj->work[2]];
                OVL4E_RECENT_IDX(D_8010DC76_335636_name_4E)++;
                OVL4E_RECENT_IDX(D_8010DC76_335636_name_4E) %= D_8010DC77_335637_name_4E;
                func_80067E6C_68A6C(D_8010DC70_335630_name_4E[obj->work[2]]);
                func_8010A300_331CC0_name_4E();
            }
            obj->rot.z += 1.0f;
            if (obj->rot.z >= 13.0f) {
                obj->rot.z -= 13.0f;
            }
            break;
    }
    if (D_8010DC7C_33563C_name_4E != -1) {
        for (i = 0; !(obj->rot.z < (*(D_8010D794_335154_name_4E + i))[0]); i++) {
        }
        base = D_8010D784_335144_name_4E[D_8010DC77_335637_name_4E];
        SprPosSet(D_8010DC7C_33563C_name_4E, 0, D_8010D794_335154_name_4E[i][1] + 50, base + obj->work[1] * 20);
    }
}

void func_8010A244_331C04_name_4E(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 5; j++) {
            OVL4E_RECENT(i)[j] = -1;
        }
        OVL4E_RECENT_IDX(i) = 0;
    }
}

void func_8010A2A0_331C60_name_4E(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_8010DC30_3355F0_name_4E); i++) {
        D_8010DC30_3355F0_name_4E[i].win = -1;
    }

    D_8010DC6C_33562C_name_4E = 0;
    D_8010DC7A_33563A_name_4E = -1;
    D_8010DC78_335638_name_4E = -1;
    D_8010DC7E_33563E_name_4E = -1;
    D_8010DC7C_33563C_name_4E = -1;
}

void func_8010A300_331CC0_name_4E(void) {
    s32 i;
    Ovl4EMgSlot* p;

    for (i = 0; i < ARRAY_COUNT(D_8010DC30_3355F0_name_4E); i++) {
        p = &D_8010DC30_3355F0_name_4E[i];
        if (p->win != -1) {
            func_8008CCA8_8D8A8(p->win);
            p->win = -1;
        }
    }
    if (D_8010DC6C_33562C_name_4E != NULL) {
        omDelObj(D_8010DC6C_33562C_name_4E);
        D_8010DC6C_33562C_name_4E = NULL;
    }
    if (D_8010DC78_335638_name_4E != -1) {
        SprKill(D_8010DC78_335638_name_4E);
        D_8010DC78_335638_name_4E = -1;
    }
    if (D_8010DC7A_33563A_name_4E != -1) {
        SprAnimKill(D_8010DC7A_33563A_name_4E);
        D_8010DC7A_33563A_name_4E = -1;
    }
    if (D_8010DC7C_33563C_name_4E != -1) {
        SprKill(D_8010DC7C_33563C_name_4E);
        D_8010DC7C_33563C_name_4E = -1;
    }
    if (D_8010DC7E_33563E_name_4E != -1) {
        SprAnimKill(D_8010DC7E_33563E_name_4E);
        D_8010DC7E_33563E_name_4E = -1;
    }
}

void func_8010A438_331DF8_name_4E(s32 arg0) {
    void* temp_s0;

    if (D_8010DC78_335638_name_4E == -1) {
        D_8010DC78_335638_name_4E = SprCreate(1, 5);
        temp_s0 = DataRead(0xA0165);
        D_8010DC7A_33563A_name_4E = SprAnimRead(temp_s0);
        DataClose(temp_s0);
        SprAnimSet(D_8010DC78_335638_name_4E, 0, D_8010DC7A_33563A_name_4E, 0);
        SprPrioSet(D_8010DC78_335638_name_4E, 0, 0x3000);
        SprAttrSet(D_8010DC78_335638_name_4E, 0, 0x1000);
        SprPosSet(D_8010DC78_335638_name_4E, 0, 0xA0, D_8010D77C_33513C_name_4E[D_8010DC77_335637_name_4E] + D_8010DC30_3355F0_name_4E[0].y);
        if (arg0 != 0 && !(rand8() & 1)) {
            func_80082450_83050(D_8010DC78_335638_name_4E, 0, 0xAD, 0x71, 0xFE);
        } else {
            func_80082450_83050(D_8010DC78_335638_name_4E, 0, 0x35, 0x9D, 0xE6);
        }
    }
}

void func_8010A588_331F48_name_4E(void) {
    void* temp_s0;

    if (D_8010DC7C_33563C_name_4E == -1) {
        D_8010DC7C_33563C_name_4E = SprCreate(1, 5);
        temp_s0 = DataRead(0xA001B);
        D_8010DC7E_33563E_name_4E = SprAnimRead(temp_s0);
        DataClose(temp_s0);
        SprAnimSet(D_8010DC7C_33563C_name_4E, 0, D_8010DC7E_33563E_name_4E, 0);
        SprPrioSet(D_8010DC7C_33563C_name_4E, 0, 1);
        SprAttrSet(D_8010DC7C_33563C_name_4E, 0, 0x1000);
        SprPosSet(D_8010DC7C_33563C_name_4E, 0, 0x32, D_8010D784_335144_name_4E[D_8010DC77_335637_name_4E]);
    }
}

/* The roulette of category sel: fresh minigames first (the recent list only if too few), shuffled;
   the first slots go on screen. */
/* NON_MATCHING: register allocation (masked 0): retail keeps id in s1, i in s2, n in s3; three attempts at splitting variables swapped them */
#ifdef NON_MATCHING
void func_8010A660_332020_name_4E(u32 arg0) {
    s32 sel;
    s16 n;
    s16 cnt;
    s16* list;
    s16* p;
    Ovl4ERect* rects;
    s32 id;
    s32 i;
    s32 j;
    s32 k;
    Ovl4EMgSlot* slot;
    omObjData* obj;

    sel = (arg0 < 9) ? arg0 : 0;
    D_8010DC76_335636_name_4E = sel;
    func_8010CF6C_33492C_name_4E();
    n = D_8010DCA0_335660_name_4E[sel];
    D_8010DC77_335637_name_4E = D_8010D6B0_335070_name_4E[sel];
    if (sel == 0) {
        if (D_8010DC77_335637_name_4E > n) {
            D_8010DC77_335637_name_4E = 3;
        }
    } else if (sel == 7) {
        if (D_8010DC77_335637_name_4E > n) {
            D_8010DC77_335637_name_4E = 2;
        }
    }
    switch (D_8010DC77_335637_name_4E) {
        case 2:
            rects = D_8010D6C0_335080_name_4E;
            break;
        case 3:
            rects = D_8010D6D0_335090_name_4E;
            break;
        case 4:
        default:
            rects = D_8010D708_3350C8_name_4E;
            break;
    }
    list = HuMemMemoryAllocPerm(0x100);
    p = list;
    for (i = 0; i < 0x80; i++) {
        *p = -1;
        p++;
    }
    cnt = 0;
    p = list;
    for (i = 0; i < n; i++) {
        id = D_8010DCC0_335680_name_4E[sel][i];
        if (n > D_8010DC77_335637_name_4E) {
            for (j = 0; j < D_8010DC77_335637_name_4E; j++) {
                if (id == OVL4E_RECENT(sel)[j]) {
                    break;
                }
            }
            if (j < D_8010DC77_335637_name_4E) {
                continue;
            }
        }
        *p = id;
        p++;
        cnt++;
    }
    for (j = 0; cnt < D_8010DC77_335637_name_4E; j++) {
        if (j >= D_8010DC77_335637_name_4E) {
            break;
        }
        id = OVL4E_RECENT(sel)[j];
        if (id >= 0) {
            for (i = 0; i < cnt; i++) {
                if (list[i] == id) {
                    break;
                }
            }
            if (i >= cnt) {
                *p = id;
                p++;
                cnt++;
            }
        }
    }
    i = 8000;
    n = cnt;
    for (; i != 0; i--) {
        k = func_8010993C_3312FC_name_4E(n);
        id = list[k];
        j = func_8010993C_3312FC_name_4E(n);
        list[k] = list[j];
        list[j] = id;
    }
    for (i = 0; i < D_8010DC77_335637_name_4E; i++) {
        slot = &D_8010DC30_3355F0_name_4E[i];
        slot->x = rects[i].x;
        slot->y = rects[i].y;
        slot->w = rects[i].w;
        slot->h = rects[i].h;
        slot->win = func_800888A8_894A8(slot->x + slot->w / 2, slot->y + slot->h / 2, slot->w, slot->h, 0, 4);
        func_80089A7C_8A67C(slot->win, 9000);
        func_8008D88C_8E48C(slot->win);
        func_800898F0_8A4F0(slot->win, slot->w / 2, slot->h / 2);
        func_80089B2C_8A72C(slot->win, 0);
        D_8010DC70_335630_name_4E[i] = list[i];
        func_8008AD84_8B984();
        func_800890CC_89CCC(slot->win, D_8010DC70_335630_name_4E[i] + 0x3D8, -2, 4);
        func_80089C78_8A878(slot->win, D_800CBD77_CC977[D_8010DC70_335630_name_4E[i]]);
        func_80089A48_8A648(slot->win, 0);
    }
    HuMemMemoryFreePerm(list);
    obj = omAddObj(-0x8000, 0, 0, -1, func_801099D4_331394_name_4E);
    D_8010DC6C_33562C_name_4E = obj;
    obj->work[0] = 3;
    obj->trans.y = 0.0f;
    obj->rot.z = 0.0f;
    func_8010A438_331DF8_name_4E(1);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/331200", func_8010A660_332020_name_4E);
#endif

void func_8010AB48_332508_name_4E(void) {
    D_8010DC6C_33562C_name_4E->work[0] = 0;
}

s16 func_8010AB58_332518_name_4E(void) {
    return D_8010DC78_335638_name_4E;
}

/* The player's own choice from category 7's list. */
void func_8010AB64_332524_name_4E(void) {
    Ovl4ERect* rects;
    s32 i;
    Ovl4EMgSlot* slot;
    omObjData* obj;

    D_8010DC76_335636_name_4E = 7;
    func_8010CF6C_33492C_name_4E();
    D_8010DC77_335637_name_4E = (D_8010DCA0_335660_name_4E[D_8010DC76_335636_name_4E] < 7) ? D_8010DCA0_335660_name_4E[D_8010DC76_335636_name_4E] : 6;
    rects = D_8010D760_335120_name_4E[D_8010DC77_335637_name_4E];
    for (i = 0; i < D_8010DC77_335637_name_4E; i++) {
        slot = &D_8010DC30_3355F0_name_4E[i];
        slot->x = rects[i].x;
        slot->y = rects[i].y;
        slot->w = rects[i].w;
        slot->h = rects[i].h;
        slot->win = func_800888A8_894A8(slot->x + slot->w / 2, slot->y + slot->h / 2, slot->w, slot->h, 0, 4);
        func_80089A7C_8A67C(slot->win, 9000);
        func_8008D88C_8E48C(slot->win);
        func_800898F0_8A4F0(slot->win, slot->w / 2, slot->h / 2);
        func_80089B2C_8A72C(slot->win, 0);
        D_8010DC70_335630_name_4E[i] = D_8010DCC0_335680_name_4E[D_8010DC76_335636_name_4E][i];
        func_8008AD84_8B984();
        func_800890CC_89CCC(slot->win, D_8010DC70_335630_name_4E[i] + 0x3D8, -2, 4);
        func_80089C78_8A878(slot->win, D_800CBD77_CC977[D_8010DC70_335630_name_4E[i]]);
        func_80089A48_8A648(slot->win, 0);
    }
    obj = omAddObj(-0x8000, 0, 0, -1, func_8010ADE0_3327A0_name_4E);
    D_8010DC6C_33562C_name_4E = obj;
    obj->work[0] = 3;
    obj->trans.y = 0.0f;
    obj->rot.z = 0.0f;
    func_8010A438_331DF8_name_4E(0);
}

/* func_801099D4_331394_name_4E with the stick: state 1 moves the cursor (work[1]), A takes it, B leaves
   (unless D_800CD414 & 4); work[2] = stick repeat delay. */
void func_8010ADE0_3327A0_name_4E(omObjData* obj) {
    s32 i;
    s16 base;
    s16 x;
    s16 y;
    Ovl4EMgSlot* p;

    switch (obj->work[0]) {
        case 0:
            obj->trans.y += 16.0f;
            for (i = 0; i < D_8010DC77_335637_name_4E; i++) {
                p = &D_8010DC30_3355F0_name_4E[i];
                func_800896DC_8A2DC(p->win, (s16)(p->x + p->w / 2), (s32)obj->trans.y + p->y + p->h / 2);
            }
            base = D_8010D77C_33513C_name_4E[D_8010DC77_335637_name_4E];
            SprPosSet(D_8010DC78_335638_name_4E, 0, 160, base + ((s32)obj->trans.y + D_8010DC30_3355F0_name_4E[0].y));
            if (obj->trans.y >= 218.0f) {
                func_80109988_331348_name_4E();
                obj->work[0] = 1;
                obj->scale.x = 1.0f;
                obj->scale.z = -1.0f;
                obj->scale.y = 0.0f;
                obj->work[1] = 0;
                obj->work[2] = 0;
                obj->work[3] = 0;
                func_8010A588_331F48_name_4E();
            }
            break;
        case 1:
            y = 0;
            if (obj->work[2] == 0) {
                x = ContStkX[D_8010E5F4_335FB4_name_4E];
                y = ContStkY[D_8010E5F4_335FB4_name_4E];
            } else {
                obj->work[2]--;
                x = 0;
            }
            i = 0;
            if (ABS(x) > 30 || ABS(y) > 30) {
                obj->work[2] = 7;
                i++;
                if ((x < 0) | (y < 0)) {
                    obj->work[1]++;
                    if (obj->work[1] >= D_8010DC77_335637_name_4E) {
                        obj->work[1] = 0;
                    }
                } else {
                    obj->work[1]--;
                    if (obj->work[1] >= 128) {
                        obj->work[1] = D_8010DC77_335637_name_4E - 1;
                    }
                }
            }
            if (i != 0) {
                func_80109988_331348_name_4E();
            }
            for (i = 0; i < D_8010DC77_335637_name_4E; i++) {
                p = &D_8010DC30_3355F0_name_4E[i];
                if (i == obj->work[1]) {
                    func_8008D530_8E130(p->win, 0, 200, 0);
                    func_80089B2C_8A72C(p->win, 0x100);
                    func_80089A7C_8A67C(p->win, 9000);
                } else {
                    func_8008D530_8E130(p->win, 0x40, 0x40, 0x80);
                    func_80089B2C_8A72C(p->win, 0);
                    func_80089A7C_8A67C(p->win, 10000);
                }
            }
            if (ContBtnTrg[D_8010E5F4_335FB4_name_4E] & 0x8000) {
                PlaySound(0x325);
                obj->work[0] = 2;
                obj->work[3] = 60;
                func_8008AD84_8B984();
                func_8008AD44_8B944(D_8010DC30_3355F0_name_4E[obj->work[1]].win);
                func_800890CC_89CCC(D_8010DC30_3355F0_name_4E[obj->work[1]].win, D_8010DC70_335630_name_4E[obj->work[1]] + 0x3D8, -2, 4);
                func_80089C78_8A878(D_8010DC30_3355F0_name_4E[obj->work[1]].win, 1);
                func_80089DA0_8A9A0(D_8010DC30_3355F0_name_4E[obj->work[1]].win, 0xA0, 0xA0, 0xA0);
                func_8008D530_8E130(D_8010DC30_3355F0_name_4E[obj->work[1]].win, 0xFE, 0xFF, 0xD0);
                func_80089A48_8A648(D_8010DC30_3355F0_name_4E[obj->work[1]].win, 0);
            }
            if (!(D_800CD414_CE014 & 4) && (ContBtnTrg[D_8010E5F4_335FB4_name_4E] & 0x4000)) {
                func_80067E6C_68A6C(-1);
                func_8010A300_331CC0_name_4E();
            }
            break;
        case 2:
            if (obj->work[3] != 0) {
                obj->work[3]--;
            } else {
                func_80067E6C_68A6C(D_8010DC70_335630_name_4E[obj->work[1]]);
                func_8010A300_331CC0_name_4E();
            }
            obj->rot.z += 1.0f;
            if (obj->rot.z >= 13.0f) {
                obj->rot.z -= 13.0f;
            }
            break;
    }
    if (D_8010DC7C_33563C_name_4E != -1) {
        for (i = 0; !(obj->rot.z < (*(D_8010D794_335154_name_4E + i))[0]); i++) {
        }
        base = D_8010D784_335144_name_4E[D_8010DC77_335637_name_4E];
        SprPosSet(D_8010DC7C_33563C_name_4E, 0, D_8010D794_335154_name_4E[i][1] + 50, base + obj->work[1] * 20);
    }
}

void func_8010B480_332E40_name_4E(s16 arg0) {
    D_8010E5E4_335FA4_name_4E = D_800FD474_FE074 = D_8010E144_335B04_name_4E[arg0].pos;
    D_8010274C_10334C = D_8010E144_335B04_name_4E[arg0].unk0C;
    D_800FA610_FB210 = D_8010E144_335B04_name_4E[arg0].unk18;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/331200", func_8010B528_332EE8_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/331200", func_8010BCB8_333678_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/331200", func_8010C218_333BD8_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/331200", func_8010C4AC_333E6C_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/331200", func_8010C5BC_333F7C_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/331200", func_8010C5F4_333FB4_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/331200", func_8010C600_333FC0_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/331200", func_8010C60C_333FCC_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/331200", func_8010C618_333FD8_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/331200", func_8010C708_3340C8_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/331200", func_8010C7AC_33416C_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/331200", func_8010C86C_33422C_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/331200", func_8010C96C_33432C_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/331200", func_8010C9AC_33436C_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/331200", func_8010CCB4_334674_name_4E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4E_name/331200", func_8010CF6C_33492C_name_4E);
