#include "ovl_31.h"

#define SGS_MODEL(i) (&D_800FC834_FD434[i])
#define SGS_RUNNING() (func_80078EA8_79AA8() + D_80102720_103320 == 0)

void func_80102800_246110_ShyGuySays(void) {
    u8 cam;
    u8 hi;

    func_8002D4D0_2E0D0(50);
    omInitObjMan(50, 0);
    func_80079128_79D28();
    func_80020D20_21920(64);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_80079E60_7AA60), 0xA0);
    func_80026DAC_279AC(0, 0xFF, 0xFF, 0xFF);
    func_80026DAC_279AC(1, 0xFF, 0xFF, 0xFF);
    func_80026E00_27A00(1, -56.0f, 50.0f, 56.0f);
    func_80018E30_19A30(1);
    cam = func_80018E78_19A78();
    ScissorSet(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 30.0f, 80.0f, 4000.0f);
    func_801031AC_246ABC_ShyGuySays();
    hi = rand8();
    func_8010372C_24703C_ShyGuySays((hi << 8) | rand8());
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    D_800FA606_FB206 = 0;
    D_8010A588_24DE98_ShyGuySays = 0;
    D_8010A58A_24DE9A_ShyGuySays = 0;
    D_8010A58C_24DE9C_ShyGuySays = 0;
    D_8010A57C_24DE8C_ShyGuySays = 0;
    D_8010A584_24DE94_ShyGuySays = 0;
    D_8010A87A_24E18A_ShyGuySays = 0;
    D_8010A87C_24E18C_ShyGuySays = 0;
    D_8010A87E_24E18E_ShyGuySays = 0;
    D_8010A880_24E190_ShyGuySays = NULL;
    D_8010A578_24DE88_ShyGuySays = omAddObj(0x20, 0, 0, -1, func_80102A04_246314_ShyGuySays);
    func_8007273C_7333C("\x82\x72\x82\x73\x82\x60\x82\x71\x82\x73", 1);
}

void func_80102A04_246314_ShyGuySays(omObjData* obj) {
    obj->func_ptr = func_80102AFC_24640C_ShyGuySays;
    omSetStatBit(obj, 0xA0);
    func_8010361C_246F2C_ShyGuySays();
    D_8010A880_24E190_ShyGuySays = omAddObj(1, 0x20, 0, -1, func_80106690_249FA0_ShyGuySays);
    omSetStatBit(D_8010A880_24E190_ShyGuySays, 0xA0);
    func_801089A8_24C2B8_ShyGuySays();
    func_80108828_24C138_ShyGuySays();
    func_80103FC0_2478D0_ShyGuySays();
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0] = omAddObj(0, 0, 0, -1, func_80105E50_249760_ShyGuySays);
    D_800F8FE0_F9BE0++;
    func_8010629C_249BAC_ShyGuySays();
    func_801033E0_246CF0_ShyGuySays();
    D_8010A584_24DE94_ShyGuySays = 1;
    if (_CheckFlag(0xC) != 0) {
        D_8010A87C_24E18C_ShyGuySays = 1;
    }
}

void func_80102AFC_24640C_ShyGuySays(omObjData* obj) {
    func_80103104_246A14_ShyGuySays(obj);
    if (SGS_RUNNING()) {
        func_801034C0_246DD0_ShyGuySays();
        switch (D_80109DB4_24D6C4_ShyGuySays) {
        case 0:
            if (func_8008F618_90218() == 0) {
                func_800691FC_69DFC(0);
                PlayMusic(0x20);
                PlaySound(0x4B0);
                D_80109DB4_24D6C4_ShyGuySays = 1;
            }
            break;
        case 1:
            if (func_80069538_6A138() == 0) {
                D_8010A584_24DE94_ShyGuySays = 2;
                D_80109DB4_24D6C4_ShyGuySays = 2;
            }
            break;
        case 2:
            func_801063B4_249CC4_ShyGuySays();
            break;
        }
    }
}

void func_80102BE4_2464F4_ShyGuySays(void) {
    func_8010369C_246FAC_ShyGuySays();
    func_80106250_249B60_ShyGuySays();
    func_80079464_7A064();
    omOvlReturnEx(1);
}

__asm__(".section .rodata");
const u32 D_8010A20C_24DB1C_ShyGuySays[3] = { 0x01030104, 0x01050106, 0x01070108 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_ShyGuySays/246110", func_80102C18_246528_ShyGuySays);

void func_80102F7C_24688C_ShyGuySays(omObjData* obj) {
    SGSPlayer* p;

    func_80103104_246A14_ShyGuySays(obj);
    if (SGS_RUNNING()) {
        func_801034C0_246DD0_ShyGuySays();
        func_801063B4_249CC4_ShyGuySays();
        switch (D_80109DBE_24D6CE_ShyGuySays) {
        case 0:
            func_800691FC_69DFC(3);
            func_800794A8_7A0A8(0x28);
            p = &D_8010A5D0_24DEE0_ShyGuySays[D_8010A87E_24E18E_ShyGuySays];
            if (p->active != 0 && p->action != 0x200) {
                gPlayers[D_8010A87E_24E18E_ShyGuySays].coins_mg_bonus += 10;
            }
            D_80109DC0_24D6D0_ShyGuySays = 60;
            D_80109DBE_24D6CE_ShyGuySays++;
            break;
        case 1:
            if (D_80109DC0_24D6D0_ShyGuySays <= 0) {
                InitFadeOut(0, 20);
                func_800794A8_7A0A8(0x28);
                D_80109DBE_24D6CE_ShyGuySays++;
            } else {
                D_80109DC0_24D6D0_ShyGuySays--;
            }
            break;
        case 2:
            if (func_8008F618_90218() == 0) {
                obj->func_ptr = func_80102BE4_2464F4_ShyGuySays;
            }
            break;
        }
    }
}

void func_80103104_246A14_ShyGuySays(omObjData* obj) {
    if (D_80109DC4_24D6D4_ShyGuySays != 0) {
        if (D_80109DC4_24D6D4_ShyGuySays == 1) {
            obj->func_ptr = func_80102BE4_2464F4_ShyGuySays;
        }
        D_80109DC4_24D6D4_ShyGuySays--;
        return;
    }
    if (D_801011FC_101DFC == 1 && func_8008F618_90218() == 0) {
        D_80109DC4_24D6D4_ShyGuySays = 20;
        InitFadeOut(0, (s16)D_80109DC4_24D6D4_ShyGuySays);
        func_800794A8_7A0A8((s16)D_80109DC4_24D6D4_ShyGuySays);
        func_80079614_7A214((s16)D_80109DC4_24D6D4_ShyGuySays);
    }
}

void func_801031AC_246ABC_ShyGuySays(void) {
    D_800FD474_FE074.x = -14.5f;
    D_800FD474_FE074.y = 0.0f;
    D_800FD474_FE074.z = 0.0f;
    D_8010274C_10334C.x = 0.0f;
    D_8010274C_10334C.y = 241.2f;
    D_8010274C_10334C.z = 0.2f;
    D_800FA610_FB210 = 1069.0f;
}

void func_80103218_246B28_ShyGuySays(omObjData* obj, f32 t) {
    s16 spr = (D_800FC7B0_FD3B0[0]->work[0] << 8) | D_800FC7B0_FD3B0[0]->work[1];

    if (t == 0.0) {
        D_8010A560_24DE70_ShyGuySays.x = obj->trans.x;
        D_8010A560_24DE70_ShyGuySays.y = 100.0f;
        D_8010A560_24DE70_ShyGuySays.z = obj->trans.z;
        D_8010A56C_24DE7C_ShyGuySays.x = D_8010274C_10334C.x;
        D_8010A56C_24DE7C_ShyGuySays.y = D_8010274C_10334C.y;
        D_8010A56C_24DE7C_ShyGuySays.z = D_8010274C_10334C.z;
        return;
    }
    D_8010274C_10334C.x = D_8010A56C_24DE7C_ShyGuySays.x + (t * (D_8010A560_24DE70_ShyGuySays.x - D_8010A56C_24DE7C_ShyGuySays.x));
    D_8010274C_10334C.y = D_8010A56C_24DE7C_ShyGuySays.y + (t * (D_8010A560_24DE70_ShyGuySays.y - D_8010A56C_24DE7C_ShyGuySays.y));
    D_8010274C_10334C.z = D_8010A56C_24DE7C_ShyGuySays.z + (t * (D_8010A560_24DE70_ShyGuySays.z - D_8010A56C_24DE7C_ShyGuySays.z));
    D_800FA610_FB210 = (1069.0 - (t * 400.0));
    SprPosSet(spr, 0, (D_8010A8CC_24E1DC_ShyGuySays[2] * 320.0f), (60.0 - (t * 4.0) + 2.0 * HuMathSin(t * 180.0)));
}

void func_801033E0_246CF0_ShyGuySays(void) {
    s16 i;

    for (i = 0; i < 10; i++) {
        D_8010AA18_24E328_ShyGuySays[i].id = -1;
        (D_8010AA18_24E328_ShyGuySays + i)->player = 0;
        D_8010AA18_24E328_ShyGuySays[i].delay = 0;
    }
}

void func_80103448_246D58_ShyGuySays(s16 id, s16 delay, s16 player) {
    s16 i;

    for (i = 0; i < 10; i++) {
        if (D_8010AA18_24E328_ShyGuySays[i].id == -1) {
            D_8010AA18_24E328_ShyGuySays[i].id = id;
            D_8010AA18_24E328_ShyGuySays[i].delay = delay;
            D_8010AA18_24E328_ShyGuySays[i].player = player;
            return;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_ShyGuySays/246110", func_801034C0_246DD0_ShyGuySays);

void func_8010361C_246F2C_ShyGuySays(void) {
    u16 i;

    D_8010A8CC_24E1DC_ShyGuySays = HuMemMemoryAllocPerm(100 * sizeof(f32));
    D_8010A8CC_24E1DC_ShyGuySays[0] = 1.0f;
    for (i = 1; i < 100; i++) {
        D_8010A8CC_24E1DC_ShyGuySays[i] = 1.0 / (f32)i;
    }
}

void func_8010369C_246FAC_ShyGuySays(void) {
    HuMemMemoryFreePerm(D_8010A8CC_24E1DC_ShyGuySays);
}

u16 func_801036BC_246FCC_ShyGuySays(u16 range) {
    D_80109DB0_24D6C0_ShyGuySays = D_80109DB0_24D6C0_ShyGuySays * 0x19971204;
    D_80109DB0_24D6C0_ShyGuySays = (D_80109DB0_24D6C0_ShyGuySays + 0x19760831) >> 0x10;
    if (range == 0) {
        return D_80109DB0_24D6C0_ShyGuySays;
    } else {
        return (D_80109DB0_24D6C0_ShyGuySays % range);
    }
}

void func_8010372C_24703C_ShyGuySays(u16 seed) {
    D_80109DB0_24D6C0_ShyGuySays = seed + (seed * D_80109DB0_24D6C0_ShyGuySays);
}

f32 func_80103750_247060_ShyGuySays(f32 a, f32 b, f32 step) {
    f32 d;
    f32 x;
    f32 y;

    x = a;
    y = b;

    if (x >= 360.0) {
        x -= 360.0;
    } else if (x < 0.0) {
        x += 360.0;
    }

    if (y >= 360.0) {
        y -= 360.0;
    } else if (y < 0.0) {
        y += 360.0;
    }

    d = func_800B0D98_B1998(x - y + 360.0, 360.0);
    if (d < 180.0) {
        if (d <= step) {
            return d;
        } else {
            return step;
        }
    } else {
        if (360.0 - d <= step) {
            return -(360.0 - d);
        } else {
            return -step;
        }
    }
}

f32 func_801038B8_2471C8_ShyGuySays(f32 y, f32 x) {
    f32 a = func_800B75A8_B81A8(y, x);

    if (a > 360.0) {
        a -= 360.0;
    } else if (a < 0.0) {
        a += 360.0;
    }

    return a;
}

void func_80103930_247240_ShyGuySays(s16 model, SGSMot* mot, s16 dir) {
    SGS_MODEL(model)->unk02 = mot->id;
    SGS_MODEL(model)->unk44 = 1.0f;
    if (dir == 0) {
        SGS_MODEL(model)->unk03 = 0;
        SGS_MODEL(model)->unk40 = 0;
        SGS_MODEL(model)->unk48 = 0;
    } else if (dir > 0) {
        SGS_MODEL(model)->unk03 = 0;
        SGS_MODEL(model)->unk40 = 0;
        SGS_MODEL(model)->unk48 = mot->len;
    } else {
        SGS_MODEL(model)->unk03 = 4;
        SGS_MODEL(model)->unk40 = mot->len;
        SGS_MODEL(model)->unk48 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_ShyGuySays/246110", func_80103A3C_24734C_ShyGuySays);

void func_80103AB4_2473C4_ShyGuySays(s16 model) {
    HmfModel* m = SGS_MODEL(model);
    u8 mot;
    f32 frame;

    if (m->unk02 != 0xFF && m->unk04 != 0xFF) {
        mot = m->unk02;
        m->unk02 = m->unk04;
        m->unk04 = mot;
        frame = m->unk40;
        m->unk40 = m->unk4C;
        m->unk4C = frame;
        m->unk0E = m->unk0C - m->unk0E;
    }
}

s32 func_80103B28_247438_ShyGuySays(s16 model) {
    HmfModel* m = SGS_MODEL(model);

    if (m->unk02 == 0xFF || m->unk04 == 0xFF) {
        return 1;
    }
    return m->unk0E > (m->unk0C * 0.7f);
}

void func_80103BC0_2474D0_ShyGuySays(s16 model, omObjData* obj) {
    func_80029714_2A314(model, obj->trans.x, obj->trans.y, obj->trans.z);
    func_8002979C_2A39C(model, obj->rot.x, obj->rot.y, obj->rot.z);
    func_800297E8_2A3E8(model, obj->scale.x, obj->scale.y, obj->scale.z);
}

void func_80103C2C_24753C_ShyGuySays(omObjData* obj, SGSPlayer* p, u16 i, s32 file) {
    obj->motion[i] = func_80018ACC_196CC(file);
    p->mot[i].id = func_80029E14_2AA14(obj->motion[i]);
    p->mot[i].len = func_80029D0C_2A90C(obj->motion[i]);
}

__asm__(".section .rodata");
const char D_8010A2A8_24DBB8_ShyGuySays[] = "NONE OBJ %d \012";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_ShyGuySays/246110", func_80103CC4_2475D4_ShyGuySays);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_ShyGuySays/246110", func_80103EB0_2477C0_ShyGuySays);

void func_80103FC0_2478D0_ShyGuySays(void) {
    u16 i;
    omObjData* obj;

    for (i = 0; i < 5; i++) {
        D_8010A870_24E180_ShyGuySays[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        obj = D_800FFFD8_100BD8[D_800FC87A_FD47A] = omAddObj(3, 6, 6, -1, func_801040CC_2479DC_ShyGuySays);
        obj->work[0] = i;
        omSetStatBit(D_800FFFD8_100BD8[D_800FC87A_FD47A], 0xA0);
        D_800FC87A_FD47A++;
        D_8010A588_24DE98_ShyGuySays++;
        D_8010A58A_24DE9A_ShyGuySays++;
    }
}

void func_801040CC_2479DC_ShyGuySays(omObjData* obj) {
    u16 part[2];
    s32 player;
    s32 chr;
    s32 dir;
    s32 file;
    s32 file2;
    s32 i;
    SGSPlayer* p;
    s16 level;

    obj->func_ptr = func_80104564_247E74_ShyGuySays;
    player = 0;
    switch (obj->work[0]) {
    case 0:
        player = 0;
        break;
    case 1:
        player = 1;
        break;
    case 2:
        player = 2;
        break;
    case 3:
        player = 3;
        break;
    }
    D_8010A870_24E180_ShyGuySays[obj->work[0]] = chr = gPlayers[player].character;
    dir = D_800CD438_CE038[chr].unk_04;
    obj->model[0] = LoadFormFile(dir | D_800CD438_CE038[chr].unk_08, 0xABD);
    func_800298A4_2A4A4(obj->model[0], 4, 0);
    for (i = 1; i < 5; i++) {
        obj->model[i] = LoadFormFile(D_80109F48_24D858_ShyGuySays[chr][i - 1] | 0x410000, 0xABD);
    }
    part[0] = func_80103EB0_2477C0_ShyGuySays(obj->model[0], D_80109DC8_24D6D8_ShyGuySays[chr][0]);
    part[1] = func_80103EB0_2477C0_ShyGuySays(obj->model[0], D_80109DC8_24D6D8_ShyGuySays[chr][1]);
    func_80103CC4_2475D4_ShyGuySays(obj->model[1], obj->model[0], 0, part[0]);
    func_80103CC4_2475D4_ShyGuySays(obj->model[2], obj->model[0], 0, part[1]);
    func_8002A00C_2AC0C(obj->model[1]);
    func_8002A00C_2AC0C(obj->model[2]);
    obj->model[5] = LoadFormFile(D_80109FA8_24D8B8_ShyGuySays[chr] | 0x410000, 0x206A9);
    HmfModelObjAttrSet(obj->model[5], 0x22000, 0x20000);
    func_80029A8C_2A68C(obj->model[5]);
    func_8002A00C_2AC0C(obj->model[5]);
    p = &D_8010A5D0_24DEE0_ShyGuySays[obj->work[0]];
    func_80105974_249284_ShyGuySays(p, obj->work[0]);
    switch (gPlayers[player].cpu_difficulty) {
    case 0:
        level = 4;
        break;
    case 1:
        level = 3;
        break;
    case 2:
        level = 2;
        break;
    case 3:
        level = 1;
        break;
    default:
        level = 3;
        break;
    }
    p->level = level;
    p->port = gPlayers[player].port;
    if (gPlayers[player].flags & 1) {
        p->port = -1;
    }
    if (gPlayers[player].group == 0) {
        D_8010A87E_24E18E_ShyGuySays = player;
    }
    func_80103C2C_24753C_ShyGuySays(obj, p, 0, dir | 0x4C);
    func_80103C2C_24753C_ShyGuySays(obj, p, 1, dir | 0x4D);
    file = dir | 0x6C;
    func_80103C2C_24753C_ShyGuySays(obj, p, 2, file);
    D_8010A590_24DEA0_ShyGuySays[player].a = file;
    file2 = dir | 0x6D;
    func_80103C2C_24753C_ShyGuySays(obj, p, 3, file2);
    D_8010A590_24DEA0_ShyGuySays[player].b = file2;
    func_80103C2C_24753C_ShyGuySays(obj, p, 4, dir | 0x4B);
    func_80103930_247240_ShyGuySays(obj->model[0], &p->mot[4], 0);
    SGS_MODEL(obj->model[0])->unk40 = 0.0f;
    obj->work[1] = 1;
    obj->trans.x = p->baseX = obj->work[0] * 300.0 + -450.0;
    obj->trans.y = 0.0f;
    obj->trans.z = -1000.0f;
    obj->rot.x = obj->rot.y = obj->rot.z = 0.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
}

void func_80104564_247E74_ShyGuySays(omObjData* obj) {
    SGSPlayer* p = &D_8010A5D0_24DEE0_ShyGuySays[obj->work[0]];
    f32 s;

    if (SGS_RUNNING()) {
        p->glow += 10;
        if (p->glow >= 180) {
            p->glow -= 180;
        }
    }
    s = HuMathSin(p->glow);
    func_8002A15C_2AD5C(obj->model[1], obj->model[3], s);
    func_8002A15C_2AD5C(obj->model[2], obj->model[4], s);
    if (!(p->action & 0x200) && SGS_RUNNING()) {
        p->swayY += func_801036BC_246FCC_ShyGuySays(0) & 3;
        if (p->swayY >= 360) {
            p->swayX -= 360; /* retail: not swayY */
        }
        obj->trans.y = HuMathSin(p->swayY) * 20.0 + 0.0;
        p->swayX += func_801036BC_246FCC_ShyGuySays(0) & 7;
        if (p->swayX >= 360) {
            p->swayX -= 360;
        }
        obj->trans.x = p->baseX + HuMathSin(p->swayX) * 20.0;
    }
    func_80105B70_249480_ShyGuySays(obj);
    if (SGS_RUNNING() && p->active != 0) {
        if (p->action != 0x200 && D_8010A8C8_24E1D8_ShyGuySays != 0 && p->left == 1 && p->right == 1) {
            p->action = 0;
            if (p->port != -1) {
                if (ContBtnTrg[p->port] & B_BUTTON) {
                    func_80104D00_248610_ShyGuySays(obj, 1);
                    p->action = 1;
                } else if (ContBtnTrg[p->port] & A_BUTTON) {
                    func_80104D00_248610_ShyGuySays(obj, 2);
                    p->action = 2;
                }
            } else {
                func_80104990_2482A0_ShyGuySays(obj);
            }
        } else if (D_8010A8BC_24E1CC_ShyGuySays == 8) {
            func_80104D00_248610_ShyGuySays(obj, 6);
        }
        if ((p->action & 0x200) && p->timer != 0) {
            func_80104D00_248610_ShyGuySays(obj, 11);
            if (p->timer < 90.0) {
                obj->scale.x = obj->scale.y = obj->scale.z = obj->scale.x - 0.03333333333333333;
                obj->trans.y -= 24.0;
                if (obj->scale.x < 0.01) {
                    obj->scale.x = obj->scale.y = obj->scale.z = 0.01f;
                }
            }
            p->timer--;
            if (p->timer == 0) {
                func_800298A4_2A4A4(obj->model[0], 4, 4);
                p->active = 0;
            }
        } else if (D_8010A584_24DE94_ShyGuySays == 3 && D_8010A87A_24E18A_ShyGuySays == 1) {
            func_80104D00_248610_ShyGuySays(obj, 10);
        }
        func_80103A3C_24734C_ShyGuySays(obj->model[0]);
    }
}

void func_80104990_2482A0_ShyGuySays(omObjData* obj) {
    s16 chance;
    SGSPlayer* p = &D_8010A5D0_24DEE0_ShyGuySays[obj->work[0]];
    s32 n;

    if (p->cpuBusy == 0) {
        p->cpuBusy = 1;
        p->cpuCount = 0;
        if (D_8010A8C4_24E1D4_ShyGuySays > 20.0f) {
            n = 20;
        } else {
            n = D_8010A8C4_24E1D4_ShyGuySays;
        }
        p->timer = p->wait + func_801036BC_246FCC_ShyGuySays(n + 5);
    }
    switch (func_80108340_24BC50_ShyGuySays()) {
    case 0:
        break;
    case 1:
        if (D_8010A8BC_24E1CC_ShyGuySays < 5) {
            return;
        }
        if (D_8010A8BC_24E1CC_ShyGuySays == 5 && func_80108310_24BC20_ShyGuySays() < 20.0) {
            return;
        }
        if (++p->cpuCount < p->timer) {
            return;
        }
        chance = func_80105A2C_24933C_ShyGuySays(p);
        if (func_801036BC_246FCC_ShyGuySays(100) >= chance) {
            func_80104D00_248610_ShyGuySays(obj, 1);
            p->action = 1;
            p->cpuBusy = 0;
        } else {
            func_80104D00_248610_ShyGuySays(obj, 2);
            p->action = 2;
            p->cpuBusy = 0;
        }
        break;
    case 2:
        if (D_8010A8BC_24E1CC_ShyGuySays < 5) {
            return;
        }
        if (D_8010A8BC_24E1CC_ShyGuySays == 5 && func_80108310_24BC20_ShyGuySays() < 20.0) {
            return;
        }
        if (++p->cpuCount < p->timer) {
            return;
        }
        chance = func_80105A2C_24933C_ShyGuySays(p);
        if (func_801036BC_246FCC_ShyGuySays(100) < chance) {
            func_80104D00_248610_ShyGuySays(obj, 1);
            p->action = 1;
            p->cpuBusy = 0;
        } else {
            func_80104D00_248610_ShyGuySays(obj, 2);
            p->action = 2;
            p->cpuBusy = 0;
        }
        break;
    case 3:
        if (D_8010A8BC_24E1CC_ShyGuySays < 3 || D_8010A57C_24DE8C_ShyGuySays < 10) {
            return;
        }
        if (p->wait >= 4 && !(func_801036BC_246FCC_ShyGuySays(0) & 3) && p->level != 1) {
            if (func_801036BC_246FCC_ShyGuySays(0) & 1) {
                func_80104D00_248610_ShyGuySays(obj, 1);
                p->action = 1;
                p->cpuBusy = 0;
            } else {
                func_80104D00_248610_ShyGuySays(obj, 2);
                p->action = 2;
                p->cpuBusy = 0;
            }
        }
        break;
    }
    if (p->timer >= D_8010A8C4_24E1D4_ShyGuySays + 4.0f) {
        p->timer = D_8010A8C4_24E1D4_ShyGuySays + 4.0f;
    }
}

void func_80104D00_248610_ShyGuySays(omObjData* obj, s16 action) {
    HmfModel* m = SGS_MODEL(obj->model[0]);
    SGSPlayer* p = &D_8010A5D0_24DEE0_ShyGuySays[obj->work[0]];
    s16 ch;
    s32 voice;

    if (m->unk40 < m->unk48 && (action != 10 || action != 11)) {
        return;
    }
    switch (action) {
    case 1:
        if (p->left == 1 && p->right == 1) {
            ch = func_80079798_7A398(0x2B8, obj->work[0]);
            if (ch != -1) {
                func_800798F8_7A4F8(ch, D_80109FB4_24D8C4_ShyGuySays[obj->work[0]]);
            }
            p->left = 2;
            func_80029BF0_2A7F0(obj->model[0], p->mot[0].id, 0, 2, 0);
            m->unk54 = p->mot[0].len;
        }
        break;
    case 2:
        if (p->left == 1 && p->right == 1) {
            ch = func_80079798_7A398(0x2B9, obj->work[0]);
            if (ch != -1) {
                func_800798F8_7A4F8(ch, D_80109FB4_24D8C4_ShyGuySays[obj->work[0]]);
            }
            p->right = 2;
            func_80029BF0_2A7F0(obj->model[0], p->mot[1].id, 0, 2, 0);
            m->unk54 = p->mot[1].len;
        }
        break;
    case 6:
        if (p->left == 2 || p->right == 2) {
            p->right = 1;
            p->left = 1;
            func_80029BF0_2A7F0(obj->model[0], p->mot[4].id, 0, 20, 0);
        }
        break;
    case 10:
        if (m->unk04 == 0xFF) {
            if (m->unk02 != p->mot[2].id) {
                func_80029BF0_2A7F0(obj->model[0], p->mot[2].id, 0, 10, 0);
                m->unk54 = p->mot[2].len;
                voice = D_8010A590_24DEA0_ShyGuySays[obj->work[0]].a;
                if (voice != -1) {
                    func_800732B0_73EB0(voice);
                    D_8010A590_24DEA0_ShyGuySays[obj->work[0]].a = -1;
                }
            }
        }
        break;
    case 11:
        if (m->unk04 == 0xFF) {
            if (m->unk02 != p->mot[3].id) {
                func_80029BF0_2A7F0(obj->model[0], p->mot[3].id, 0, 10, 0);
            }
        }
        break;
    }
}

void func_80104FF4_248904_ShyGuySays(s32 answer) {
    u16 i;
    SGSPlayer* p = D_8010A5D0_24DEE0_ShyGuySays;
    omObjData* obj;
    u16 chance;

    for (i = 0; i < 4; i++, p++) {
        obj = D_800FFFD8_100BD8[i];
        if (p->active != 0 && p->action != 0x200 && p->port == -1 && p->left == 1 && p->right == 1) {
            chance = func_80105A2C_24933C_ShyGuySays(p);
            switch (answer) {
            case 2:
                if (func_801036BC_246FCC_ShyGuySays(100) < chance) {
                    func_80104D00_248610_ShyGuySays(obj, 2);
                    p->action = 2;
                } else {
                    func_80104D00_248610_ShyGuySays(obj, 1);
                    p->action = 1;
                }
                break;
            case 1:
                if (func_801036BC_246FCC_ShyGuySays(100) < chance) {
                    func_80104D00_248610_ShyGuySays(obj, 1);
                    p->action = 1;
                } else {
                    func_80104D00_248610_ShyGuySays(obj, 2);
                    p->action = 2;
                }
                break;
            }
            p->cpuBusy = 0;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_ShyGuySays/246110", func_80105154_248A64_ShyGuySays);

void func_80105278_248B88_ShyGuySays(void) {
    s16 i;
    HmfModel* m;
    SGSPlayer* p;

    for (i = 0; i < 4; i++) {
        m = SGS_MODEL(D_800FFFD8_100BD8[i]->model[0]);
        p = &D_8010A5D0_24DEE0_ShyGuySays[i];
        if (D_8010A5D0_24DEE0_ShyGuySays[i].active != 0 && D_8010A5D0_24DEE0_ShyGuySays[i].action != 0x200 && p->forced != 0) {
            m->unk44 = 0.0f;
            m->unk48 = m->unk40;
            p->action = 0;
            p->left = 1;
            p->right = 1;
        }
    }
}

s16 func_80105348_248C58_ShyGuySays(void) {
    SGSPlayer* p = D_8010A5D0_24DEE0_ShyGuySays;
    u16 i;

    for (i = 0; i < 4; i++, p++) {
        if (p->active == 0 || D_8010A5D0_24DEE0_ShyGuySays[i].action == 0x200) {
            continue;
        }
        if (p->left != 1 || p->right != 1) {
            return 0;
        }
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_ShyGuySays/246110", func_801053C8_248CD8_ShyGuySays);

void func_801054AC_248DBC_ShyGuySays(void) {
    s16 i;
    s16 model;
    HmfModel* m;

    for (i = 0; i < 4; i++) {
        model = D_800FFFD8_100BD8[i]->model[0];
        m = SGS_MODEL(model);
        if (D_8010A5D0_24DEE0_ShyGuySays[i].active != 0 && D_8010A5D0_24DEE0_ShyGuySays[i].action != 0x200 && m->unk44 == 0.0f) {
            func_80029BF0_2A7F0(model, D_8010A5D0_24DEE0_ShyGuySays[i].mot[4].id, 0, 10, 0);
            m->unk44 = 1.0f;
        }
    }
}

s16 func_801055D0_248EE0_ShyGuySays(void) {
    s16 i;

    for (i = 0; i < 4; i++) {
        if (D_8010A5D0_24DEE0_ShyGuySays[i].active != 0 && D_8010A5D0_24DEE0_ShyGuySays[i].action == 0x200) {
            if (D_8010A5D0_24DEE0_ShyGuySays[i].timer > 60.0) {
                return 0;
            }
        }
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_ShyGuySays/246110", func_8010568C_248F9C_ShyGuySays);

void func_80105740_249050_ShyGuySays(u16 i) {
    s16 voices[6] = { 0x111, 0x112, 0x113, 0x114, 0x115, 0x116 };
    SGSPlayer* p = &D_8010A5D0_24DEE0_ShyGuySays[i];

    if (p->action != 0x200) {
        p->timer = 120;
        p->action = 0x200;
        PlaySound(0x2B7);
        if (p->port != -1) {
            omVibrate(i, 2, 2, 20);
        }
        func_80103448_246D58_ShyGuySays(voices[D_8010A870_24E180_ShyGuySays[i]], 24, i);
    }
}

void func_80105844_249154_ShyGuySays(u16* out) {
    u16 i;

    if (--D_8010A58A_24DE9A_ShyGuySays > 0) {
        for (i = 0; i < 4; i++) {
            D_8010A5D0_24DEE0_ShyGuySays[i].rank -= D_8010A58A_24DE9A_ShyGuySays;
        }
    }
    for (i = 0; i < 4; i++) {
        out[i] = D_8010A5D0_24DEE0_ShyGuySays[i].rank;
    }
}

void func_80105908_249218_ShyGuySays(s16 rank) {
    u16 i;

    for (i = 0; i < 4; i++) {
        if (D_8010A5D0_24DEE0_ShyGuySays[i].active != 0 && D_8010A5D0_24DEE0_ShyGuySays[i].action != 0x200) {
            D_8010A5D0_24DEE0_ShyGuySays[i].rank = rank;
        }
    }
}

void func_80105974_249284_ShyGuySays(SGSPlayer* p, u16 i) {
    func_800B0EF0_B1AF0(p, 0, sizeof(SGSPlayer));
    p->active = 1;
    p->action = 0;
    p->port = -1;
    p->wait = -1;
    p->level = 0;
    p->rank = 4;
    p->left = 1;
    p->right = 1;
    p->fallTime = 0;
    p->wait = func_801036BC_246FCC_ShyGuySays(5) + 1;
    p->timer = p->wait + func_801036BC_246FCC_ShyGuySays(25);
    p->baseX = 0;
    p->swayX = func_801036BC_246FCC_ShyGuySays(360);
    p->swayY = func_801036BC_246FCC_ShyGuySays(360);
    p->cpuCount = 0;
    p->cpuBusy = 0;
    p->forced = 0;
    p->glow = 0;
    p->unk_A0 = 0;
}

s32 func_80105A2C_24933C_ShyGuySays(SGSPlayer* p) {
    s32 chance = 100 - p->level * (D_8010A58C_24DE9C_ShyGuySays - 4);
    s32 t;

    if (chance < 0) {
        chance = 0;
    } else if (chance > 100) {
        chance = 100;
    }
    if (D_8010A58C_24DE9C_ShyGuySays < 5) {
        chance = 100;
    }
    if (func_80105B10_249420_ShyGuySays() == 0) {
        if (D_8010A58C_24DE9C_ShyGuySays != D_80109FC0_24D8D0_ShyGuySays) {
            D_80109FC0_24D8D0_ShyGuySays = D_8010A58C_24DE9C_ShyGuySays;
            D_80109FBC_24D8CC_ShyGuySays++;
        }
        t = 100 - D_80109FBC_24D8CC_ShyGuySays * 20;
        t = t < 0 ? 0 : t;
        if (t < chance) {
            chance = t;
        }
    }
    return chance;
}

s32 func_80105B10_249420_ShyGuySays(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_8010A5D0_24DEE0_ShyGuySays[i].port != -1 && D_8010A5D0_24DEE0_ShyGuySays[i].active != 0) {
            return 1;
        }
    }
    return 0;
}

void func_80105B70_249480_ShyGuySays(omObjData* obj) {
    SGSPlayer* p = &D_8010A5D0_24DEE0_ShyGuySays[obj->work[0]];
    HmfModel* m = SGS_MODEL(obj->model[5]);
    s32 n;
    f32 t;
    f64 phase;

    if (!(p->action & 0x200)) {
        func_80029714_2A314(obj->model[5], obj->trans.x, D_80109FE8_24D8F8_ShyGuySays[D_8010A870_24E180_ShyGuySays[obj->work[0]]], obj->trans.z);
        return;
    }
    if (SGS_RUNNING()) {
        p->fallTime++;
    }
    if (p->fallTime < 16) {
        if (SGS_RUNNING() && ((u32)(p->fallTime - 1) < 2 || p->fallTime == 3)) {
            n = p->fallTime - 1;
            func_8008221C_82E1C(D_8010A8D8_24E1E8_ShyGuySays[func_801064B0_249DC0_ShyGuySays(m->pos.x + D_80109FC4_24D8D4_ShyGuySays[n].x, m->pos.y + D_80109FC4_24D8D4_ShyGuySays[n].y,
                                                         m->pos.z + D_80109FC4_24D8D4_ShyGuySays[n].z, 2, 3, 15)].sprite,
                                0, 1.0f);
        }
        t = (f32)p->fallTime / 15.0;
        if (t >= 1.0) {
            t = 1.0f;
        }
        func_8002AC10_2B810(obj->model[5], t, t * 10.0 + 1.0, 2);
        if (p->fallTime == 1) {
            D_800CA02C_CAC2C = 0.0f;
        }
        if (SGS_RUNNING()) {
            D_800CA02C_CAC2C += 20.0;
            phase = D_800CA02C_CAC2C;
            if (phase >= 360.0) {
                D_800CA02C_CAC2C = phase - 360.0;
            }
        }
    } else {
        func_800298A4_2A4A4(obj->model[5], 4, 4);
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_ShyGuySays/246110", func_80105E50_249760_ShyGuySays);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_ShyGuySays/246110", func_80106130_249A40_ShyGuySays);

void func_80106250_249B60_ShyGuySays(void) {
}

u16 func_80106258_249B68_ShyGuySays(s32 file) {
    void* data;
    u16 ret;

    data = DataRead(file);
    ret = SprAnimRead(data);
    DataClose(data);
    return ret;
}

void func_8010629C_249BAC_ShyGuySays(void) {
    SGSFx* fx;
    u16 i;

    D_8010A8D4_24E1E4_ShyGuySays = func_80106258_249B68_ShyGuySays(0x41002C);
    fx = D_8010A8D8_24E1E8_ShyGuySays;
    for (i = 0; i < 16; i++, fx++) {
        fx->used = 0;
        fx->sprite = SprCreate(1, 0);
        SprAnimSet(fx->sprite, 0, D_8010A8D4_24E1E4_ShyGuySays, 0);
        SprAttrSet(fx->sprite, 0, 0x9000);
        SprPosSet(fx->sprite, 0, 0, 0);
        SprScaleSet(fx->sprite, 0, 1.0f, 1.0f);
        SprPrioSet(fx->sprite, 0, i - 0x10);
        func_8008225C_82E5C(fx->sprite, 0, 0);
        fx->time = 0;
        fx->x = fx->y = fx->z = 0.0f;
        fx->flags = 0;
    }
}

void func_801063B4_249CC4_ShyGuySays(void) {
    SGSFx* fx;
    u16 i;

    fx = D_8010A8D8_24E1E8_ShyGuySays;
    for (i = 0; i < 16; i++, fx++) {
        if (fx->used != 0) {
            if (fx->flags & 1) {
                SprPos3DSet(fx->sprite, 0, 0, fx->x, fx->y, fx->z);
            } else {
                SprPosSet(fx->sprite, 0, fx->x, fx->y);
            }
            if (fx->time > 0) {
                if (--fx->time <= 0) {
                    SprAttrSet(fx->sprite, 0, 0x8000);
                    fx->flags = 0;
                    fx->time = 0;
                    fx->used = 0;
                }
            }
        }
    }
}

s16 func_801064B0_249DC0_ShyGuySays(f32 x, f32 y, f32 z, s16 anim, u16 flags, u16 time) {
    SGSFx* fx = D_8010A8D8_24E1E8_ShyGuySays;
    u16 i;

    for (i = 0; i < 16; i++, fx++) {
        if (fx->used == 0) {
            fx->used = 1;
            fx->x = x;
            fx->y = y;
            fx->z = z;
            fx->time = time;
            fx->flags = flags;
            SprAnimSet(fx->sprite, 0, D_8010A8D0_24E1E0_ShyGuySays[anim], 0);
            SprBankSet(fx->sprite, 0, 0);
            SprAttrReset(fx->sprite, 0, 0x8000);
            func_80082450_83050(fx->sprite, 0, 0xFF, 0xFF, 0xFF);
            if (flags & 1) {
                SprPos3DSet(fx->sprite, 0, 0, x, y, z);
            } else {
                SprPosSet(fx->sprite, 0, x, y);
            }
            if (flags & 2) {
                func_8008225C_82E5C(fx->sprite, 0, 2);
            } else if (flags & 4) {
                func_8008225C_82E5C(fx->sprite, 0, 3);
            } else if (flags & 8) {
                func_8008225C_82E5C(fx->sprite, 0, 1);
            } else {
                func_8008225C_82E5C(fx->sprite, 0, 0);
            }
            return i;
        }
    }
    return -1;
}

__asm__(".section .rodata");
const u32 D_8010A3C8_24DCD8_ShyGuySays[4] = { 0x001A001B, 0x001C001D, 0x001E001F, 0x00200000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_ShyGuySays/246110", func_80106690_249FA0_ShyGuySays);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_ShyGuySays/246110", func_80106A94_24A3A4_ShyGuySays);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_ShyGuySays/246110", func_8010794C_24B25C_ShyGuySays);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_ShyGuySays/246110", func_801081B8_24BAC8_ShyGuySays);

f32 func_80108310_24BC20_ShyGuySays(void) {
    HmfModel* m = SGS_MODEL(D_8010A880_24E190_ShyGuySays->model[0]);

    return m->unk40;
}

s16 func_80108340_24BC50_ShyGuySays(void) {
    if (D_8010A888_24E198_ShyGuySays[0] == 2 && D_8010A888_24E198_ShyGuySays[1] == 1) {
        return 1;
    }
    if (D_8010A888_24E198_ShyGuySays[0] == 1 && D_8010A888_24E198_ShyGuySays[1] == 2) {
        return 2;
    }
    if (D_8010A888_24E198_ShyGuySays[0] == 2 && D_8010A888_24E198_ShyGuySays[1] == 2) {
        return 3;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_ShyGuySays/246110", func_801083B4_24BCC4_ShyGuySays);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_ShyGuySays/246110", func_80108430_24BD40_ShyGuySays);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_ShyGuySays/246110", func_80108828_24C138_ShyGuySays);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_ShyGuySays/246110", func_801088EC_24C1FC_ShyGuySays);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_ShyGuySays/246110", func_801089A8_24C2B8_ShyGuySays);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_ShyGuySays/246110", func_80108A78_24C388_ShyGuySays);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_ShyGuySays/246110", func_80108DCC_24C6DC_ShyGuySays);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_ShyGuySays/246110", func_80108FD4_24C8E4_ShyGuySays);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_ShyGuySays/246110", func_80109170_24CA80_ShyGuySays);

s32 func_8010924C_24CB5C_ShyGuySays(void) {
    SGSShot* s = D_8010AA58_24E368_ShyGuySays;
    s32 i;

    for (i = 0; i < 4; i++, s++) {
        if (s->target != NULL) {
            return 0;
        }
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_ShyGuySays/246110", func_80109280_24CB90_ShyGuySays);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_ShyGuySays/246110", func_801092C8_24CBD8_ShyGuySays);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_ShyGuySays/246110", func_801099BC_24D2CC_ShyGuySays);
