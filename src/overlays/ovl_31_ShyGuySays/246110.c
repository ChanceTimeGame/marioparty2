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

void func_80102C18_246528_ShyGuySays(omObjData* obj) {
    s16 voices[6] = { 0x103, 0x104, 0x105, 0x106, 0x107, 0x108 };
    s16 ranks[4];
    f32 t;
    s16 i;
    s16 music;

    func_80103104_246A14_ShyGuySays(obj);
    if (SGS_RUNNING()) {
        func_801034C0_246DD0_ShyGuySays();
        func_801063B4_249CC4_ShyGuySays();
        if (D_80109DBA_24D6CA_ShyGuySays != 0) {
            if (D_8010A588_24DE98_ShyGuySays == 1) {
                t = (f32)D_80109DBC_24D6CC_ShyGuySays / 30.0;
                if (t > 1.0) {
                    t = 1.0f;
                    D_80109DBA_24D6CA_ShyGuySays = 0;
                }
                func_80105844_249154_ShyGuySays((u16*)ranks);
                for (i = 0; i < 4; i++) {
                    if (ranks[i] == 1) {
                        break;
                    }
                }
                func_80103218_246B28_ShyGuySays(D_800FFFD8_100BD8[i], t);
            }
            D_80109DBC_24D6CC_ShyGuySays++;
        }
        switch (D_80109DB6_24D6C6_ShyGuySays) {
        case 0:
            func_800691FC_69DFC(3);
            func_800794A8_7A0A8(0x28);
            D_80109DB8_24D6C8_ShyGuySays = 0;
            D_80109DB6_24D6C6_ShyGuySays++;
            break;
        case 1:
            if (func_80069538_6A138() == 2) {
                if (D_8010A588_24DE98_ShyGuySays != 0) {
                    func_80105844_249154_ShyGuySays((u16*)ranks);
                    for (i = 0; i < 4; i++) {
                        if (ranks[i] == 1) {
                            break;
                        }
                    }
                    PlaySound(voices[D_8010A870_24E180_ShyGuySays[i]]);
                    gPlayers[i].coins_mg_bonus += 10;
                    D_8010A87A_24E18A_ShyGuySays = 1;
                    func_800691FC_69DFC(6, D_8010A870_24E180_ShyGuySays[i]);
                    music = 0x51;
                } else {
                    func_800691FC_69DFC(0x13);
                    music = 0x57;
                }
                PlayMusic(music);
                D_80109DB8_24D6C8_ShyGuySays = 120;
                D_80109DB6_24D6C6_ShyGuySays++;
            }
            break;
        case 2:
            if (D_80109DB8_24D6C8_ShyGuySays <= 0) {
                InitFadeOut(0, 20);
                func_800794A8_7A0A8(0x28);
                D_80109DB6_24D6C6_ShyGuySays++;
            } else {
                D_80109DB8_24D6C8_ShyGuySays--;
            }
            break;
        case 3:
            if (func_8008F618_90218() == 0) {
                obj->func_ptr = func_80102BE4_2464F4_ShyGuySays;
            }
            break;
        }
    }
}

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

void func_801034C0_246DD0_ShyGuySays(void) {
    s16 i;
    s16 ch;
    s16 d;

    for (i = 0; i < 10; i++) {
        if (D_8010AA18_24E328_ShyGuySays[i].id != -1) {
            d = D_8010AA18_24E328_ShyGuySays[i].delay - 1;
            D_8010AA18_24E328_ShyGuySays[i].delay = d;
            if (d <= 0) {
                if (D_8010AA18_24E328_ShyGuySays[i].player < 0) {
                    ch = PlaySound(D_8010AA18_24E328_ShyGuySays[i].id);
                } else {
                    ch = func_80079798_7A398(D_8010AA18_24E328_ShyGuySays[i].id, D_8010AA18_24E328_ShyGuySays[i].player);
                }
                if (ch >= 0) {
                    D_8010AA18_24E328_ShyGuySays[i].delay = -1;
                    D_8010AA18_24E328_ShyGuySays[i].id = -1;
                } else {
                    D_8010AA18_24E328_ShyGuySays[i].delay++;
                }
            }
        }
    }
}

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

// decomp-permuter
void func_80103A3C_24734C_ShyGuySays(s16 model)
{
  HmfModel *m;
  u8 mot = (&D_800FC834_FD434[model])->unk02;
  if ((mot != 0xFF) && (D_800F92B4_F9EB4[mot].unk02 <= (&D_800FC834_FD434[model])->unk40))
  {
    (&D_800FC834_FD434[model])->unk40 = (&D_800FC834_FD434[model])->unk48;
  }
}

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

// register allocation: a1/a2 (masked 17, names only)
#ifdef NON_MATCHING
void func_80103CC4_2475D4_ShyGuySays(s16 dst, s16 src, s32 a, s32 b) {
    HmfData* from = SGS_MODEL(dst)->hmf;
    HmfData* to = SGS_MODEL(src)->hmf;
    HitXform* x;
    HmfMotionObj* o;
    s16 i;
    s16 j;

    if ((s16)a >= from->unk10) {
        osSyncPrintf("NONE OBJ %d \n", (u16)a);
        return;
    }
    if ((s16)b >= to->unk10) {
        osSyncPrintf("NONE OBJ %d \n", (u16)b);
        return;
    }
    if (to->unk84 == (HmfMotionObj*)-1) {
        for (i = 0; i < to->unk68; i++) {
            x = &to->unk6C[i];
            if (x->unk00 == (s16)b) {
                x->unk48 = from;
                x->unk00 = a;
                break;
            }
        }
    } else {
        for (i = 0; i < to->unk16; i++) {
            o = &to->unk84[i];
            for (j = 0; j < o->unk00; j++) {
                if (o->unk50[j] == (s16)b) {
                    o->unk54 = from;
                    o->unk50[j] = a;
                    break;
                }
            }
        }
    }
}
#else
__asm__(".section .rodata");
const char D_8010A2A8_24DBB8_ShyGuySays[] = "NONE OBJ %d \012";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_ShyGuySays/246110", func_80103CC4_2475D4_ShyGuySays);
#endif

const char D_8010A2B8_24DBC8_ShyGuySays[] __attribute__((section(".rodata"))) = "Hmf %d > Can't find ObjName %s\n";

s32 func_80103EB0_2477C0_ShyGuySays(s16 model, char* name) {
    HmfData* hmf = SGS_MODEL(model)->hmf;
    s16 hash = func_8001F4AC_200AC(name);
    s16 i;

    for (i = 0; i < hmf->unk10; i++) {
        if (hmf->unk64[i].unk08 == hash && func_800B0FD0_B1BD0(hmf->unk64[i].unk12, (const char*)&name) != 0) {
            break;
        }
    }
    if (i == hmf->unk10) {
        osSyncPrintf(D_8010A2B8_24DBC8_ShyGuySays, model, name);
        return -1;
    }
    return i;
}

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

// register pressure: retail keeps 0x200 out of the saved registers and reloads p->port for the
// button read (masked 14; split continue tests and an indexed &D[i] pointer tried, no better)
#ifdef NON_MATCHING
void func_80105154_248A64_ShyGuySays(void) {
    u16 i;
    SGSPlayer* p = D_8010A5D0_24DEE0_ShyGuySays;
    omObjData* obj;

    for (i = 0; i < 4; i++, p++) {
        obj = D_800FFFD8_100BD8[i];
        if (p->active != 0 && p->action != 0x200 && p->port != -1 && p->left == 1 && p->right == 1) {
            if (ContBtnTrg[p->port] & B_BUTTON) {
                func_80104D00_248610_ShyGuySays(obj, 1);
                p->action = 1;
            } else if (ContBtnTrg[p->port] & A_BUTTON) {
                func_80104D00_248610_ShyGuySays(obj, 2);
                p->action = 2;
            }
            p->forced = 1;
            p->cpuBusy = 0;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_ShyGuySays/246110", func_80105154_248A64_ShyGuySays);
#endif

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

s16 func_801053C8_248CD8_ShyGuySays(void) {
    s16 i;
    HmfModel* m;
    SGSPlayer* p;

    for (i = 0; i < 4; i++) {
        m = SGS_MODEL(D_800FFFD8_100BD8[i]->model[0]);
        p = &D_8010A5D0_24DEE0_ShyGuySays[i];
        if (D_8010A5D0_24DEE0_ShyGuySays[i].active != 0 && D_8010A5D0_24DEE0_ShyGuySays[i].action != 0x200 && m->unk02 != p->mot[4].id) {
            if (m->unk04 != 0xFF || m->unk40 != m->unk48) {
                return 0;
            }
        }
    }
    return 1;
}

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

/* Retail reads .action through the label D_8010A5D4_24DEE4 (= D_8010A5D0[n].action); the call's
   i & 0xFFFF (not a reused (u16)i) is what makes retail mask i again for the argument. */
s16 func_8010568C_248F9C_ShyGuySays(s32 i, s16 answer) {
    if (D_8010A5D0_24DEE0_ShyGuySays[(u16)i].active == 0 || D_8010A5D0_24DEE0_ShyGuySays[(u16)i].action == 0x200 || func_80109280_24CB90_ShyGuySays(i & 0xFFFF) != 0) {
        return 1;
    }
    return D_8010A5D0_24DEE0_ShyGuySays[(u16)i].action == answer;
}

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

// register allocation: the returned model passes through a second register (masked 4; the
// address diff in the check is layout noise). Tried: ret = a = f(), u8 ret, ret = f(); a = ret
#ifdef NON_MATCHING
void func_80105E50_249760_ShyGuySays(omObjData* obj) {
    SGSBack* b = D_8010AB38_24E448_ShyGuySays;
    s16 spr;
    s16 model;
    s32 a;
    s32 ret;
    s16 i;

    obj->func_ptr = func_80106130_249A40_ShyGuySays;
    D_8010A8D0_24E1E0_ShyGuySays[0] = func_80106258_249B68_ShyGuySays(0x410027);
    spr = SprCreate(1, 0);
    SprAnimSet(spr, 0, D_8010A8D0_24E1E0_ShyGuySays[0], 0);
    SprAttrSet(spr, 0, 0x4000);
    SprPosSet(spr, 0, 0xA0, 0x78);
    SprScaleSet(spr, 0, 1.0f, 1.0f);
    SprAttrSet(spr, 0, 0x503C);
    SprPrioSet(spr, 0, 0xFFFF);
    D_8010A8D0_24E1E0_ShyGuySays[0] = func_80106258_249B68_ShyGuySays(0x410028);
    a = func_801092C8_24CBD8_ShyGuySays(SprAnimGet(D_8010A8D0_24E1E0_ShyGuySays[0]), 1);
    ret = a;
    func_80029714_2A314(a, 0.0f, 149.0f, 149.0f);
    obj->work[0] = (u32)(a << 16) >> 24;
    obj->work[1] = ret;
    D_8010A8D0_24E1E0_ShyGuySays[0] = func_80106258_249B68_ShyGuySays(0x41002B);
    a = func_801092C8_24CBD8_ShyGuySays(SprAnimGet(D_8010A8D0_24E1E0_ShyGuySays[0]), 2);
    ret = a;
    func_80029714_2A314(a, 0.0f, 149.0f, 149.0f);
    obj->work[2] = (u32)(a << 16) >> 24;
    obj->work[3] = ret;
    D_8010A8D0_24E1E0_ShyGuySays[0] = func_80106258_249B68_ShyGuySays(0x410029);
    for (i = 0; i < 3; i++, b++) {
        model = func_801092C8_24CBD8_ShyGuySays(SprAnimGet(D_8010A8D0_24E1E0_ShyGuySays[0]), 0);
        b->model = model;
        if (model != -1) {
            b->angle = ((rand8() << 8) | rand8()) % 360;
            b->x = D_8010A000_24D910_ShyGuySays[i].x;
            b->y = D_8010A000_24D910_ShyGuySays[i].y;
            b->z = D_8010A000_24D910_ShyGuySays[i].z;
            b->scale = D_8010A024_24D934_ShyGuySays[i];
            func_80029714_2A314(model, b->x, b->y, b->z);
            func_800297E8_2A3E8(model, b->scale, b->scale, 1.0f);
        }
    }
    InitFadeIn(0, 16);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_ShyGuySays/246110", func_80105E50_249760_ShyGuySays);
#endif

// register allocation: the model id moves through a0 (masked 5)
#ifdef NON_MATCHING
void func_80106130_249A40_ShyGuySays(omObjData* obj) {
    SGSBack* b = D_8010AB38_24E448_ShyGuySays;
    s16 angle;
    s16 id;
    s16 t;
    f32 s;
    f32 c;
    s16 i;

    for (i = 0; i < 3; i++, b++) {
        if ((id = b->model) != -1) {
            angle = b->angle;
            t = angle + 4;
            angle = t;
            if (t > 360) {
                angle = t - 360;
            }
            s = HuMathSin(angle);
            c = -s;
            func_800297E8_2A3E8(id, (s * 0.0375 + 1.0) * b->scale, (c * 0.0375 + 1.0) * b->scale, 1.0f);
            b->angle = angle;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_ShyGuySays/246110", func_80106130_249A40_ShyGuySays);
#endif

void func_80106250_249B60_ShyGuySays(void) {
}

s32 func_80106258_249B68_ShyGuySays(s32 file) {
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

void func_80106690_249FA0_ShyGuySays(omObjData* obj) {
    u16 files[7] = { 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20 };
    s16 tmp2;
    HmfData* hmf;
    u16 i;

    obj->func_ptr = func_80106A94_24A3A4_ShyGuySays;
    obj->model[0] = func_80018A30_19630(files[0] | 0x410000, 0x14B9);
    obj->model[1] = func_80018ACC_196CC(files[1] | 0x410000);
    obj->model[2] = func_80018ACC_196CC(files[2] | 0x410000);
    obj->model[3] = func_80018A30_19630(files[3] | 0x410000, 0x14B9);
    obj->model[4] = func_80018A30_19630(files[4] | 0x410000, 0x14B9);
    obj->model[5] = func_80018A30_19630(files[5] | 0x410000, 0x14B9);
    obj->model[6] = func_80018A30_19630(files[6] | 0x410000, 0x14B9);
    for (i = 0; i < 7; i++) {
        if (i != 0) {
            func_800298A4_2A4A4(obj->model[i], 4, 4);
        }
        SGS_MODEL(obj->model[i])->unk44 = 0.0f;
        D_8010A8A0_24E1B0_ShyGuySays[i].id = func_80029E14_2AA14(obj->model[i]);
        D_8010A8A0_24E1B0_ShyGuySays[i].len = func_80029D0C_2A90C(obj->model[i]);
        if (i != 0) {
            SGS_MODEL(obj->model[i])->unk40 = D_8010A8A0_24E1B0_ShyGuySays[i].len;
            SGS_MODEL(obj->model[i])->unk48 = D_8010A8A0_24E1B0_ShyGuySays[i].len;
        } else {
            SGS_MODEL(obj->model[i])->unk40 = 0.0f;
            SGS_MODEL(obj->model[i])->unk48 = 0.0f;
        }
    }
    i = D_8010A8A0_24E1B0_ShyGuySays[1].id;
    tmp2 = D_8010A8A0_24E1B0_ShyGuySays[1].len;
    D_8010A8A0_24E1B0_ShyGuySays[1].id = D_8010A8A0_24E1B0_ShyGuySays[0].id;
    D_8010A8A0_24E1B0_ShyGuySays[1].len = D_8010A8A0_24E1B0_ShyGuySays[0].len;
    D_8010A8A0_24E1B0_ShyGuySays[0].id = i;
    D_8010A8A0_24E1B0_ShyGuySays[0].len = tmp2;
    obj->model[7] = func_80018A30_19630(0xD, 0x14B9);
    obj->model[8] = func_80018A30_19630(0x410018, 0x14B9);
    func_8002A00C_2AC0C(obj->model[0]);
    D_8010A888_24E198_ShyGuySays.left = D_8010A888_24E198_ShyGuySays.right = 1;
    D_8010A888_24E198_ShyGuySays.unk_08 = 1;
    D_8010A888_24E198_ShyGuySays.hold = 0;
    D_8010A888_24E198_ShyGuySays.cannon = 0;
    obj->trans.x = 0.0f;
    obj->trans.y = 100.0f;
    obj->trans.z = 100.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 0.8f;
    obj->rot.y = 180.0f;
    D_8010A8BC_24E1CC_ShyGuySays = 0;
    D_8010A8C8_24E1D8_ShyGuySays = 0;
    D_8010A8C4_24E1D4_ShyGuySays = 30.0f;
    obj->work[0] = 3;
    obj->work[1] = 4;
    obj->work[2] = 5;
    obj->work[3] = 6;
    hmf = SGS_MODEL(obj->model[0])->hmf;
    D_8010A8C0_24E1D0_ShyGuySays[0] = func_80038398_38F98(hmf, "h_b-hata_w");
    D_8010A8C0_24E1D0_ShyGuySays[1] = func_80038398_38F98(hmf, "h_b-hata_w1");
}

void func_80106A94_24A3A4_ShyGuySays(omObjData* obj) {
    u16 cmd = 0;
    u16 i;
    u32 w;
    s32 t;

    if (SGS_RUNNING()) {
        D_8010A034_24D944_ShyGuySays += 10;
        if (D_8010A034_24D944_ShyGuySays >= 360) {
            D_8010A034_24D944_ShyGuySays -= 360;
        }
    }
    func_80108430_24BD40_ShyGuySays(obj->model[0], D_8010A8C0_24E1D0_ShyGuySays[0], HuMathSin(D_8010A034_24D944_ShyGuySays), D_8010A048_24D958_ShyGuySays, D_8010A068_24D978_ShyGuySays, 0.0f, 0.2f, 0.3f);
    func_80108430_24BD40_ShyGuySays(obj->model[0], D_8010A8C0_24E1D0_ShyGuySays[1], func_800B7890_B8490(D_8010A034_24D944_ShyGuySays), D_8010A048_24D958_ShyGuySays, D_8010A068_24D978_ShyGuySays, 0.0f, 0.05f, 0.3f);
    if (SGS_RUNNING()) {
        if (D_8010A584_24DE94_ShyGuySays == 2) {
            switch (D_8010A8BC_24E1CC_ShyGuySays) {
            case 0:
                if ((D_8010A044_24D954_ShyGuySays <= D_8010A57C_24DE8C_ShyGuySays && func_801055D0_248EE0_ShyGuySays() != 0) || D_8010A58C_24DE9C_ShyGuySays == 0) {
                    D_8010A8C8_24E1D8_ShyGuySays = 1;
                    D_8010A580_24DE90_ShyGuySays = 0;
                    D_8010A57C_24DE8C_ShyGuySays = 0;
                    if (D_8010A58C_24DE9C_ShyGuySays < 0xFF) {
                        D_8010A58C_24DE9C_ShyGuySays++;
                    }
                    cmd = func_801036BC_246FCC_ShyGuySays(2);
                    obj->work[D_8010A58C_24DE9C_ShyGuySays % 4] = cmd;
                    w = *(u32*)obj->work;
                    if ((w >> 8) == (w & 0xFFFFFF)) {
                        if (cmd == 0) {
                            obj->work[D_8010A58C_24DE9C_ShyGuySays % 4] = 1;
                            cmd = 1;
                        } else {
                            obj->work[D_8010A58C_24DE9C_ShyGuySays % 4] = 0;
                            cmd = 0;
                        }
                    }
                    D_8010A044_24D954_ShyGuySays -= 5.0;
                    if (D_8010A044_24D954_ShyGuySays < 27.5) {
                        D_8010A044_24D954_ShyGuySays = 27.5f;
                    }
                    if (D_8010A8C4_24E1D4_ShyGuySays > 6.0) {
                        D_8010A8C4_24E1D4_ShyGuySays -= 3.0;
                    }
                    if (D_8010A58C_24DE9C_ShyGuySays >= 4 && func_801036BC_246FCC_ShyGuySays(3) == 0) {
                        cmd = 2;
                    }
                    PlaySound(0x2B3);
                    switch (cmd) {
                    case 0:
                        cmd = 1;
                        D_8010A8BC_24E1CC_ShyGuySays = 5;
                        break;
                    case 1:
                        cmd = 2;
                        D_8010A8BC_24E1CC_ShyGuySays = 5;
                        break;
                    default:
                        cmd = 3;
                        if (rand8() & 1) {
                            D_8010A8BC_24E1CC_ShyGuySays = 3;
                        } else {
                            D_8010A8BC_24E1CC_ShyGuySays = 1;
                        }
                        break;
                    }
                    D_8010A03C_24D94C_ShyGuySays = cmd;
                    D_8010A03E_24D94E_ShyGuySays = cmd;
                    if (D_8010A8BC_24E1CC_ShyGuySays == 1) {
                        D_8010A03E_24D94E_ShyGuySays = cmd + 1;
                    }
                }
                break;
            case 1:
                if (func_801081B8_24BAC8_ShyGuySays(obj) != 0) {
                    D_8010A57C_24DE8C_ShyGuySays = 0;
                    D_8010A8BC_24E1CC_ShyGuySays = 2;
                    cmd = obj->work[D_8010A58C_24DE9C_ShyGuySays % 4] == 0 ? 5 : 4;
                }
                break;
            case 2:
                if (func_80103B28_247438_ShyGuySays(obj->model[0]) != 0) {
                    func_80103AB4_2473C4_ShyGuySays(obj->model[0]);
                    D_8010A888_24E198_ShyGuySays.left = D_8010A888_24E198_ShyGuySays.right = 2;
                    D_8010A8BC_24E1CC_ShyGuySays = 3;
                }
                break;
            case 3:
                if (func_801081B8_24BAC8_ShyGuySays(obj) != 0) {
                    D_8010A57C_24DE8C_ShyGuySays = 0;
                    D_8010A8BC_24E1CC_ShyGuySays = 4;
                }
                break;
            case 4:
                if (D_8010A57C_24DE8C_ShyGuySays > 0) {
                    if (obj->work[D_8010A58C_24DE9C_ShyGuySays % 4] == 0) {
                        cmd = 4;
                        D_8010A03C_24D94C_ShyGuySays = 2;
                        obj->work[D_8010A58C_24DE9C_ShyGuySays % 4] = 1;
                    } else {
                        cmd = 5;
                        D_8010A03C_24D94C_ShyGuySays = 1;
                        obj->work[D_8010A58C_24DE9C_ShyGuySays % 4] = 0;
                    }
                    D_8010A57C_24DE8C_ShyGuySays = 0;
                    D_8010A8BC_24E1CC_ShyGuySays = 5;
                }
                break;
            case 5:
                if (func_801081B8_24BAC8_ShyGuySays(obj) != 0) {
                    D_8010A57C_24DE8C_ShyGuySays = 0;
                    D_8010A8BC_24E1CC_ShyGuySays = 6;
                }
                break;
            case 6:
                if (D_8010A8C4_24E1D4_ShyGuySays <= D_8010A57C_24DE8C_ShyGuySays) {
                    func_80104FF4_248904_ShyGuySays(D_8010A03C_24D94C_ShyGuySays);
                    D_8010A57C_24DE8C_ShyGuySays = 0;
                    D_8010A8BC_24E1CC_ShyGuySays = 7;
                    D_8010A8C8_24E1D8_ShyGuySays = 0;
                }
                break;
            case 7:
                if (D_8010A57C_24DE8C_ShyGuySays >= 8) {
                    func_80105278_248B88_ShyGuySays();
                    func_801054AC_248DBC_ShyGuySays();
                    for (i = 0; i < 4; i++) {
                        if (func_8010568C_248F9C_ShyGuySays(i, D_8010A03C_24D94C_ShyGuySays) == 0) {
                            break;
                        }
                    }
                    D_8010A57C_24DE8C_ShyGuySays = 0;
                    D_8010A8BC_24E1CC_ShyGuySays = 8;
                } else if (D_8010A57C_24DE8C_ShyGuySays < 4) {
                    cmd = 6;
                    func_80105154_248A64_ShyGuySays();
                }
                break;
            case 8:
                if (func_801081B8_24BAC8_ShyGuySays(obj) != 0 && func_80105348_248C58_ShyGuySays() != 0 && func_801053C8_248CD8_ShyGuySays() != 0) {
                    D_8010A57C_24DE8C_ShyGuySays = 0;
                    D_8010A8BC_24E1CC_ShyGuySays = 9;
                    D_8010A038_24D948_ShyGuySays = 0;
                }
                break;
            case 9:
                for (i = 0; i < 4; i++) {
                    if (func_8010568C_248F9C_ShyGuySays(i, D_8010A03C_24D94C_ShyGuySays) == 0) {
                        if (D_8010A888_24E198_ShyGuySays.cannon == 4) {
                            if (fabs(obj->rot.y - D_8010A088_24D998_ShyGuySays[i]) < 1.0 && func_801083B4_24BCC4_ShyGuySays() != 0) {
                                obj->rot.y = D_8010A088_24D998_ShyGuySays[i];
                                PlaySound(0x2B5);
                                D_8010A8BC_24E1CC_ShyGuySays = 15;
                                D_8010A57C_24DE8C_ShyGuySays = 0;
                                D_8010A040_24D950_ShyGuySays = i;
                                D_8010A038_24D948_ShyGuySays++;
                                i = 5;
                            } else {
                                if (D_8010A038_24D948_ShyGuySays == 0) {
                                    cmd = 13;
                                    obj->rot.y += func_80103750_247060_ShyGuySays(D_8010A088_24D998_ShyGuySays[i], obj->rot.y, 16.0f);
                                } else {
                                    obj->rot.y += func_80103750_247060_ShyGuySays(D_8010A088_24D998_ShyGuySays[i], obj->rot.y, 2.0f);
                                }
                                if (obj->rot.y > 360.0) {
                                    obj->rot.y -= 360.0;
                                } else if (obj->rot.y < 0.0) {
                                    obj->rot.y += 360.0;
                                }
                                D_8010A57C_24DE8C_ShyGuySays = 0;
                                i = 5;
                            }
                        } else {
                            cmd = 12;
                            D_8010A8BC_24E1CC_ShyGuySays = 10;
                            D_8010A57C_24DE8C_ShyGuySays = 0;
                            i = 5;
                        }
                    }
                }
                if (i == 4) {
                    if (D_8010A888_24E198_ShyGuySays.cannon != 0 || fabs(obj->rot.y - D_8010A098_24D9A8_ShyGuySays) > 1.0 || func_8010924C_24CB5C_ShyGuySays() == 0) {
                        D_8010A57C_24DE8C_ShyGuySays = 0;
                        cmd = 15;
                        obj->rot.y += func_80103750_247060_ShyGuySays(D_8010A098_24D9A8_ShyGuySays, obj->rot.y, 2.0f);
                        if (obj->rot.y > 360.0) {
                            obj->rot.y -= 360.0;
                        } else if (obj->rot.y < 0.0) {
                            obj->rot.y += 360.0;
                        }
                    } else {
                        if (D_8010A588_24DE98_ShyGuySays != 0) {
                            D_8010A58A_24DE9A_ShyGuySays = D_8010A588_24DE98_ShyGuySays;
                        }
                        func_80105908_249218_ShyGuySays(D_8010A58A_24DE9A_ShyGuySays);
                        if (D_8010A87C_24E18C_ShyGuySays == 0) {
                            if (D_8010A588_24DE98_ShyGuySays < 2) {
                                D_8010A584_24DE94_ShyGuySays = 3;
                                D_8010A578_24DE88_ShyGuySays->func_ptr = func_80102C18_246528_ShyGuySays;
                            }
                        } else if (D_8010A5D0_24DEE0_ShyGuySays[D_8010A87E_24E18E_ShyGuySays].active != 0 && D_8010A5D0_24DEE0_ShyGuySays[D_8010A87E_24E18E_ShyGuySays].action != 0x200) {
                            if (D_8010A588_24DE98_ShyGuySays < 2) {
                                D_8010A584_24DE94_ShyGuySays = 3;
                                D_8010A578_24DE88_ShyGuySays->func_ptr = func_80102F7C_24688C_ShyGuySays;
                            }
                        } else {
                            D_8010A584_24DE94_ShyGuySays = 3;
                            D_8010A578_24DE88_ShyGuySays->func_ptr = func_80102F7C_24688C_ShyGuySays;
                        }
                        obj->rot.y = D_8010A098_24D9A8_ShyGuySays;
                        D_8010A57C_24DE8C_ShyGuySays = 0;
                        D_8010A8BC_24E1CC_ShyGuySays = 0;
                    }
                }
                break;
            case 10:
                cmd = 12;
                if (D_8010A888_24E198_ShyGuySays.cannon == 4) {
                    D_8010A57C_24DE8C_ShyGuySays = 0;
                    D_8010A8BC_24E1CC_ShyGuySays = 9;
                }
                break;
            case 11:
                cmd = 13;
                if (func_801081B8_24BAC8_ShyGuySays(obj) != 0) {
                    D_8010A57C_24DE8C_ShyGuySays = 0;
                    D_8010A8BC_24E1CC_ShyGuySays = 16;
                }
                break;
            case 12:
                cmd = 14;
                if (D_8010A57C_24DE8C_ShyGuySays == 5) {
                    func_80108DCC_24C6DC_ShyGuySays(D_800FFFD8_100BD8[D_8010A040_24D950_ShyGuySays], obj->trans.x, obj->trans.y, obj->trans.z);
                } else if (func_801081B8_24BAC8_ShyGuySays(obj) != 0) {
                    D_8010A588_24DE98_ShyGuySays--;
                    cmd = 0;
                    D_8010A57C_24DE8C_ShyGuySays = 0;
                    D_8010A8BC_24E1CC_ShyGuySays = 9;
                }
                break;
            case 13:
                cmd = 15;
                if (func_801081B8_24BAC8_ShyGuySays(obj) != 0) {
                    cmd = 0;
                    D_8010A57C_24DE8C_ShyGuySays = 0;
                    D_8010A8BC_24E1CC_ShyGuySays = 9;
                }
                break;
            case 14:
                if (fabs(obj->rot.y - D_8010A098_24D9A8_ShyGuySays) < 5.0) {
                    obj->rot.y = D_8010A098_24D9A8_ShyGuySays;
                    D_8010A57C_24DE8C_ShyGuySays = 0;
                    D_8010A8BC_24E1CC_ShyGuySays = 11;
                    cmd = 13;
                } else {
                    obj->rot.y += func_80103750_247060_ShyGuySays(D_8010A098_24D9A8_ShyGuySays, obj->rot.y, 16.0f);
                    if (obj->rot.y > 360.0) {
                        obj->rot.y -= 360.0;
                    } else if (obj->rot.y < 0.0) {
                        obj->rot.y += 360.0;
                    }
                }
                break;
            case 15:
                if (D_8010A57C_24DE8C_ShyGuySays >= 11) {
                    cmd = 14;
                    D_8010A57C_24DE8C_ShyGuySays = 0;
                    D_8010A8BC_24E1CC_ShyGuySays = 12;
                }
                break;
            case 16:
                if (D_8010A57C_24DE8C_ShyGuySays >= 11) {
                    D_8010A57C_24DE8C_ShyGuySays = 0;
                    D_8010A8BC_24E1CC_ShyGuySays = 9;
                }
                break;
            }
            func_8010794C_24B25C_ShyGuySays(obj, cmd);
            D_8010A57C_24DE8C_ShyGuySays++;
            D_8010A580_24DE90_ShyGuySays++;
            if (D_8010A8C8_24E1D8_ShyGuySays != 0) {
                switch (D_8010A03E_24D94E_ShyGuySays) {
                case 1:
                    t = D_8010A8C4_24E1D4_ShyGuySays + 15.0f;
                    break;
                case 2:
                    t = D_8010A8C4_24E1D4_ShyGuySays + 15.0f;
                    break;
                case 3:
                    t = D_8010A8C4_24E1D4_ShyGuySays + 32.0f;
                    break;
                default:
                    t = D_8010A8C4_24E1D4_ShyGuySays + 50.0f;
                    break;
                }
                func_801088EC_24C1FC_ShyGuySays(t, D_8010A580_24DE90_ShyGuySays);
            } else {
                func_801088EC_24C1FC_ShyGuySays(-1, -1);
            }
        } else {
            func_8010794C_24B25C_ShyGuySays(obj, 0);
        }
        for (i = 0; i < 7; i++) {
            func_80103BC0_2474D0_ShyGuySays(obj->model[i], obj);
        }
        func_80103BC0_2474D0_ShyGuySays(obj->model[7], obj);
        func_80029714_2A314(obj->model[8], obj->trans.x, obj->trans.y, obj->trans.z);
        D_8010A030_24D940_ShyGuySays++;
        if (D_8010A044_24D954_ShyGuySays > 360.0f) {
            D_8010A030_24D940_ShyGuySays -= 360;
        }
        obj->trans.y = 100.0f;
    }
}

// register allocation: v0/v1 swap around the flag stores in cases 4 and 5 (masked 3)
#ifdef NON_MATCHING
void func_8010794C_24B25C_ShyGuySays(omObjData* obj, u16 cmd) {
    s16 m0 = obj->model[0];
    s16 m3 = obj->model[3];
    s16 m4 = obj->model[4];
    s16 m5 = obj->model[5];
    s16 m6 = obj->model[6];
    HmfModel* e0 = SGS_MODEL(m0);
    HmfModel* e3 = SGS_MODEL(m3);
    HmfModel* e4 = SGS_MODEL(m4);
    HmfModel* e5 = SGS_MODEL(m5);
    HmfModel* e6 = SGS_MODEL(m6);
    HmfModel* e;
    SGSMot* p;

    if (D_8010A888_24E198_ShyGuySays.cannon == 0) {
        if (D_8010A888_24E198_ShyGuySays.hold != 0) {
            if (--D_8010A888_24E198_ShyGuySays.hold == 0) {
                e0->unk03 = 0;
                e = SGS_MODEL(m0);
                e->unk40 = D_8010A8A0_24E1B0_ShyGuySays[1].len;
                e->unk48 = D_8010A8A0_24E1B0_ShyGuySays[1].len;
            }
        } else if (e0->unk40 == e0->unk48) {
            switch (cmd) {
            case 2:
                if (D_8010A888_24E198_ShyGuySays.left & 1) {
                    D_8010A888_24E198_ShyGuySays.left = 2;
                    func_80103930_247240_ShyGuySays(m0, &D_8010A8A0_24E1B0_ShyGuySays[0], 1);
                }
                break;
            case 5:
                if ((D_8010A888_24E198_ShyGuySays.left & 2) && (D_8010A888_24E198_ShyGuySays.right & 2)) {
                    D_8010A888_24E198_ShyGuySays.hold = D_8010A8A0_24E1B0_ShyGuySays[1].len * 0.5;
                    D_8010A888_24E198_ShyGuySays.left = 1;
                    D_8010A888_24E198_ShyGuySays.right = 2;
                    p = &D_8010A8A0_24E1B0_ShyGuySays[1];
                    goto anim;
                } else if (D_8010A888_24E198_ShyGuySays.left & 2) {
                    D_8010A888_24E198_ShyGuySays.left = 1;
                    func_80103930_247240_ShyGuySays(m0, &D_8010A8A0_24E1B0_ShyGuySays[0], -1);
                }
                break;
            case 1:
                if (D_8010A888_24E198_ShyGuySays.right & 1) {
                    D_8010A888_24E198_ShyGuySays.right = 2;
                    func_80103930_247240_ShyGuySays(m0, &D_8010A8A0_24E1B0_ShyGuySays[1], 1);
                }
                break;
            case 4:
                if (D_8010A888_24E198_ShyGuySays.left & 2) {
                    if (D_8010A888_24E198_ShyGuySays.right & 2) {
                        D_8010A888_24E198_ShyGuySays.hold = D_8010A8A0_24E1B0_ShyGuySays[0].len * 0.5;
                        D_8010A888_24E198_ShyGuySays.right = 1;
                        D_8010A888_24E198_ShyGuySays.left = 2;
                        p = &D_8010A8A0_24E1B0_ShyGuySays[0];
                    anim:
                        func_80029BF0_2A7F0(m0, p->id, p->len * 0.5, p->len * 0.5, 0);
                    }
                } else if (D_8010A888_24E198_ShyGuySays.right & 2) {
                    D_8010A888_24E198_ShyGuySays.right = 1;
                    func_80103930_247240_ShyGuySays(m0, &D_8010A8A0_24E1B0_ShyGuySays[1], -1);
                }
                break;
            case 3:
                if ((D_8010A888_24E198_ShyGuySays.left & 1) && (D_8010A888_24E198_ShyGuySays.right & 1)) {
                    D_8010A888_24E198_ShyGuySays.left = 2;
                    D_8010A888_24E198_ShyGuySays.right = 2;
                    func_80103930_247240_ShyGuySays(m0, &D_8010A8A0_24E1B0_ShyGuySays[2], 1);
                }
                break;
            case 6:
                if ((D_8010A888_24E198_ShyGuySays.left & 2) && (D_8010A888_24E198_ShyGuySays.right & 2)) {
                    D_8010A888_24E198_ShyGuySays.left = 1;
                    D_8010A888_24E198_ShyGuySays.right = 1;
                    func_80103930_247240_ShyGuySays(m0, &D_8010A8A0_24E1B0_ShyGuySays[2], -1);
                } else if (D_8010A888_24E198_ShyGuySays.left & 2) {
                    D_8010A888_24E198_ShyGuySays.left = 1;
                    func_80103930_247240_ShyGuySays(m0, &D_8010A8A0_24E1B0_ShyGuySays[0], -1);
                } else if (D_8010A888_24E198_ShyGuySays.right & 2) {
                    D_8010A888_24E198_ShyGuySays.right = 1;
                    func_80103930_247240_ShyGuySays(m0, &D_8010A8A0_24E1B0_ShyGuySays[1], -1);
                }
                break;
            case 7:
                if ((D_8010A888_24E198_ShyGuySays.left & 1) && (D_8010A888_24E198_ShyGuySays.right & 1)) {
                    D_8010A888_24E198_ShyGuySays.cannon = 1;
                    func_800298A4_2A4A4(m0, 4, 4);
                    func_800298A4_2A4A4(m3, 4, 0);
                    func_80103930_247240_ShyGuySays(m3, &D_8010A8A0_24E1B0_ShyGuySays[3], 1);
                }
                break;
            case 12:
                if ((D_8010A888_24E198_ShyGuySays.left & 1) && (D_8010A888_24E198_ShyGuySays.right & 1)) {
                    D_8010A888_24E198_ShyGuySays.cannon = 1;
                    func_800298A4_2A4A4(m0, 4, 4);
                    func_800298A4_2A4A4(m3, 4, 0);
                    func_80103930_247240_ShyGuySays(m3, &D_8010A8A0_24E1B0_ShyGuySays[3], 1);
                    e3->unk44 = 0.8f;
                }
                break;
            }
        }
    } else {
        switch (cmd) {
        case 12:
            switch (D_8010A888_24E198_ShyGuySays.cannon) {
            case 1:
                if (e3->unk40 >= 30.0) {
                    e3->unk40 = 30.0f;
                    e3->unk44 = 0.0f;
                    D_8010A888_24E198_ShyGuySays.cannon = 2;
                }
                break;
            case 2:
                if (obj->rot.y == 0.0) {
                    e3->unk44 = 0.8f;
                    D_8010A888_24E198_ShyGuySays.cannon = 3;
                    PlaySound(0x2B4);
                } else {
                    obj->rot.y += func_80103750_247060_ShyGuySays(0.0f, obj->rot.y, 20.0f);
                }
                break;
            case 3:
                if (D_8010A888_24E198_ShyGuySays.cannon != 4) {
                    if (e3->unk40 >= e3->unk48) {
                        D_8010A888_24E198_ShyGuySays.cannon = 4;
                    }
                }
                break;
            }
            break;
        case 13:
            if ((e4->unk18 & 4) && !(e3->unk18 & 4)) {
                func_800298A4_2A4A4(m3, 4, 4);
                func_800298A4_2A4A4(m4, 4, 0);
                func_80103930_247240_ShyGuySays(m4, &D_8010A8A0_24E1B0_ShyGuySays[4], 1);
            }
            break;
        case 14:
            if (e5->unk40 >= e5->unk48) {
                func_800298A4_2A4A4(m4, 4, 4);
                func_800298A4_2A4A4(m5, 4, 0);
                func_80103930_247240_ShyGuySays(m5, &D_8010A8A0_24E1B0_ShyGuySays[5], 1);
            }
            break;
        case 15:
            if ((e6->unk18 & 4) && !(e5->unk18 & 4)) {
                func_800298A4_2A4A4(m5, 4, 4);
                func_800298A4_2A4A4(m6, 4, 0);
                func_80103930_247240_ShyGuySays(m6, &D_8010A8A0_24E1B0_ShyGuySays[6], 1);
            } else if (e6->unk40 >= e6->unk48 && D_8010A888_24E198_ShyGuySays.cannon != 0) {
                func_800298A4_2A4A4(m0, 4, 0);
                func_800298A4_2A4A4(m6, 4, 4);
                D_8010A888_24E198_ShyGuySays.cannon = 0;
            }
            break;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_ShyGuySays/246110", func_8010794C_24B25C_ShyGuySays);
#endif

s16 func_801081B8_24BAC8_ShyGuySays(omObjData* obj) {
    HmfModel* a = SGS_MODEL(obj->model[0]);
    HmfModel* b = SGS_MODEL(obj->model[3]);
    HmfModel* c = SGS_MODEL(obj->model[4]);
    HmfModel* d = SGS_MODEL(obj->model[5]);
    HmfModel* e = SGS_MODEL(obj->model[6]);

    if (D_8010A888_24E198_ShyGuySays.hold == 0 && (a->unk40 == a->unk48 || (a->unk18 & 4)) && (b->unk40 == b->unk48 || (b->unk18 & 4)) &&
        (c->unk40 == c->unk48 || (c->unk18 & 4)) && (d->unk40 == d->unk48 || (d->unk18 & 4)) &&
        (e->unk40 == e->unk48 || (e->unk18 & 4))) {
        return 1;
    }
    return 0;
}

f32 func_80108310_24BC20_ShyGuySays(void) {
    HmfModel* m = SGS_MODEL(D_8010A880_24E190_ShyGuySays->model[0]);

    return m->unk40;
}

s16 func_80108340_24BC50_ShyGuySays(void) {
    if (D_8010A888_24E198_ShyGuySays.left == 2 && D_8010A888_24E198_ShyGuySays.right == 1) {
        return 1;
    }
    if (D_8010A888_24E198_ShyGuySays.left == 1 && D_8010A888_24E198_ShyGuySays.right == 2) {
        return 2;
    }
    if (D_8010A888_24E198_ShyGuySays.left == 2 && D_8010A888_24E198_ShyGuySays.right == 2) {
        return 3;
    }
    return 0;
}

s16 func_801083B4_24BCC4_ShyGuySays(void) {
    HmfModel* a = SGS_MODEL(D_8010A880_24E190_ShyGuySays->model[4]);
    HmfModel* b = SGS_MODEL(D_8010A880_24E190_ShyGuySays->model[5]);
    s32 f;

    if (!(a->unk18 & 4) && a->unk40 >= a->unk48) {
        return 1;
    }
    f = b->unk18 & 4;
    return f == 0;
}

void func_80108430_24BD40_ShyGuySays(s16 model, s16 part, f32 s, SGSFlagVtx* a, SGSFlagVtx* b, f32 wx, f32 wy, f32 wz) {
    HmfData* hmf;
    HmfVtx* src;
    HmfVtx* dst;
    HmfVtx* base;
    s16 sp[10][4];
    s16 n;
    s16 k;
    s16 i;
    s16 j;

    hmf = SGS_MODEL(model)->hmf;
    k = 0;
    src = &hmf->unk40[hmf->unk64[part].unk0A];
    dst = &hmf->unk44[D_800FDBE0_FE7E0][hmf->unk64[part].unk0A];
    n = hmf->unk64[part].unk0C;
    for (i = 0; i < n; src++, dst++, i++) {
        if (i == a->index) {
            dst->unk00 = src->unk00 + s * 20.0 * wx * a->weight;
            dst->unk02 = src->unk02 + s * 20.0 * wy * a->weight;
            dst->unk04 = src->unk04 - s * 20.0 * wz * a->weight;
            sp[k][0] = src->unk00;
            sp[k][1] = src->unk02;
            sp[k][2] = src->unk04;
            sp[k][3] = i;
            a++;
            k++;
        } else if (i == b->index) {
            dst->unk00 = src->unk00 + s * 20.0 * wx * b->weight;
            dst->unk02 = src->unk02 - s * 20.0 * wy * b->weight;
            dst->unk04 = src->unk04 + s * 20.0 * wz * b->weight;
            sp[k][0] = src->unk00;
            sp[k][1] = src->unk02;
            sp[k][2] = src->unk04;
            sp[k][3] = i;
            b++;
            k++;
        } else {
            dst->unk02 = src->unk02;
        }
    }
    for (j = 0; j < k; j++) {
        src = &hmf->unk40[hmf->unk64[part].unk0A];
        dst = &hmf->unk44[D_800FDBE0_FE7E0][hmf->unk64[part].unk0A];
        base = dst;
        for (i = 0; i < n; src++, dst++, i++) {
            if (sp[j][0] == src->unk00 && sp[j][1] == src->unk02 && sp[j][2] == src->unk04) {
                dst->unk00 = base[sp[j][3]].unk00;
                dst->unk02 = base[sp[j][3]].unk02;
                dst->unk04 = base[sp[j][3]].unk04;
            }
        }
    }
}

void func_80108828_24C138_ShyGuySays(void) {
    s32 anim = func_80106258_249B68_ShyGuySays(0x41002A) & 0xFFFF;
    s16 spr = SprCreate(1, 0);

    D_8010AB74_24E484_ShyGuySays = spr;
    SprAnimSet(spr, 0, anim, 0);
    SprAttrSet(spr, 0, 0xC000);
    SprPosSet(spr, 0, 0, 0x20);
    SprScaleSet(spr, 0, 0.6f, 0.6f);
    SprAttrSet(spr, 0, 0x503C);
    SprPrioSet(spr, 0, 0xFF80);
}

// decomp-permuter
void func_801088EC_24C1FC_ShyGuySays(s32 total, s32 now)
{
  f32 new_var;
  s32 spr = D_8010AB74_24E484_ShyGuySays;
  if ((total < 1) || (total < now))
  {
    SprAttrSet(spr, 0, 0x8000);
  }
  else
  {
    s16 id = spr;
    new_var = fabsf(((f32) now) / total);
    SprPosSet(id, 0, new_var * 320.0f, 0x20);
    SprAttrReset(id, 0, 0x8000);
  }
}

void func_801089A8_24C2B8_ShyGuySays(void) {
    SGSShot* s = D_8010AA58_24E368_ShyGuySays;
    s32 i;

    func_800B0EF0_B1AF0(D_8010AA58_24E368_ShyGuySays, 0, sizeof(D_8010AA58_24E368_ShyGuySays));
    for (i = 0; i < 4; i++, s++) {
        s->target = NULL;
        if (i != 0) {
            s->mdl = func_80027D3C_2893C(D_8010AA58_24E368_ShyGuySays[0].mdl);
        } else {
            s->mdl = func_80018A30_19630(0x410019, 0x149D);
        }
        func_800297E8_2A3E8(s->mdl, 2.0f, 2.0f, 2.0f);
    }
    omAddObj(2, 0, 0, -1, func_80108A78_24C388_ShyGuySays);
}

void func_80108A78_24C388_ShyGuySays(omObjData* obj) {
    SGSShot* s = D_8010AA58_24E368_ShyGuySays;
    Vec d;
    f32 pitch;
    f32 yaw;
    f32 sn;
    s32 n;
    s32 i;

    for (i = 0; i < 4; i++, s++) {
        if (s->target != NULL) {
            d.x = s->target->trans.x - s->pos.x;
            d.y = s->target->trans.y + 200.0 - s->pos.y;
            d.z = s->target->trans.z - s->pos.z;
            pitch = func_801038B8_2471C8_ShyGuySays(sqrtf(d.x * d.x + d.z * d.z), d.y);
            yaw = func_801038B8_2471C8_ShyGuySays(d.z, d.x);
            s->pitch += func_80103750_247060_ShyGuySays(pitch, s->pitch, 5.0f);
            s->yaw += func_80103750_247060_ShyGuySays(yaw, s->yaw, 5.0f);
            s->vel.x = func_800B7890_B8490(s->yaw) * s->speed;
            s->vel.y = func_800B7890_B8490(s->pitch) * s->speed;
            sn = HuMathSin(s->pitch);
            s->vel.z = sn * HuMathSin(s->yaw) * s->speed;
            if (func_80108FD4_24C8E4_ShyGuySays(s->target, s) != 0) {
                func_80105740_249050_ShyGuySays(s->target->work[0]);
                s->target = NULL;
                func_800298A4_2A4A4(s->mdl, 4, 4);
                continue;
            }
            s->pos.x += s->vel.x;
            s->pos.y += s->vel.y;
            s->pos.z += s->vel.z;
            if (fabs(s->pos.x) > 2500.0 || fabs(s->pos.y) > 2500.0 || fabs(s->pos.z) > 2500.0 || (SGS_MODEL(s->target->model[0])->unk18 & 4)) {
                s->target = NULL;
                func_800298A4_2A4A4(s->mdl, 4, 4);
            } else {
                func_80029714_2A314(s->mdl, s->pos.x, s->pos.y, s->pos.z);
                func_8002979C_2A39C(s->mdl, pitch + 90.0, func_801038B8_2471C8_ShyGuySays(d.x, d.z), 0.0f);
                n = s->spin + 30.0;
                s->spin = n;
                if (n > 360.0) {
                    s->spin -= 360.0;
                }
            }
        }
    }
}

void func_80108DCC_24C6DC_ShyGuySays(omObjData* target, f32 x, f32 y, f32 z) {
    SGSShot* s = D_8010AA58_24E368_ShyGuySays;
    Vec d;
    s32 i;

    for (i = 0; i < 4; i++, s++) {
        if (s->target == NULL) {
            PlaySound(0x2B6);
            s->target = target;
            s->spin = ((rand8() << 8) | rand8()) % 360;
            s->speed = 80.0f;
            s->radius = 200.0f;
            s->pos.x = x + 20.0;
            s->pos.y = y + 40.0;
            s->pos.z = z;
            s->vel.x = s->vel.y = s->vel.z = 0.0f;
            d.x = s->target->trans.x - s->pos.x;
            d.y = s->target->trans.y - s->pos.y;
            d.z = s->target->trans.z - s->pos.z;
            s->pitch = func_801038B8_2471C8_ShyGuySays(sqrtf(d.x * d.x + d.z * d.z), d.y);
            s->yaw = func_801038B8_2471C8_ShyGuySays(d.z, d.x);
            func_80029714_2A314(s->mdl, s->pos.x, s->pos.y, s->pos.z);
            func_8002979C_2A39C(s->mdl, s->pitch, s->yaw, s->unk_18);
            func_800298A4_2A4A4(s->mdl, 4, 0);
            return;
        }
    }
}

// register allocation (masked 0, raw 18): proj takes $f8 (retail $f6). Tried (S3-P05): proj = -proj
// as its own statement, the two early returns joined, d.x += proj + n.x; none moves it.
#ifdef NON_MATCHING
s32 func_80108FD4_24C8E4_ShyGuySays(omObjData* target, SGSShot* s) {
    f32 r = s->radius;
    Vec d;
    Vec n;
    f32 proj;
    f32 len;

    d.x = target->trans.x - s->pos.x;
    d.y = target->trans.y + 200.0 - s->pos.y;
    d.z = target->trans.z - s->pos.z;
    n.x = d.x + s->vel.x;
    n.y = d.y + s->vel.y;
    n.z = d.z + s->vel.z;
    if (n.x * n.x + n.y * n.y + n.z * n.z < r * r) {
        return 1;
    }
    len = func_80109170_24CA80_ShyGuySays(&s->vel, &n);
    proj = -(d.x * n.x + d.y * n.y + d.z * n.z);
    if (len < proj) {
        return 0;
    }
    if (proj < 0.0) {
        return 0;
    }
    d.x = proj + n.x + d.x;
    d.y = proj + n.y + d.y;
    d.z = proj + n.z + d.z;
    return d.x * d.x + d.y * d.y + d.z * d.z < r * r;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_ShyGuySays/246110", func_80108FD4_24C8E4_ShyGuySays);
#endif

f32 func_80109170_24CA80_ShyGuySays(Vec* in, Vec* out) {
    f32 len = in->x * in->x + in->y * in->y + in->z * in->z;
    f32 inv;

    len = sqrtf(len);
    if (len != 0.0) {
        inv = 1.0f / len;
        out->x = inv * in->x;
        out->y = inv * in->y;
        out->z = inv * in->z;
    } else {
        out->x = out->y = out->z = 0.0f;
    }
    return len;
}

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

s32 func_80109280_24CB90_ShyGuySays(s32 i) {
    SGSShot* s = D_8010AA58_24E368_ShyGuySays;
    s32 j;

    for (j = 0; j < 4; j++, s++) {
        if (s->target == D_800FFFD8_100BD8[i]) {
            return 1;
        }
    }
    return 0;
}

s32 func_801092C8_24CBD8_ShyGuySays(HuSprite_Unk84_Struct* spr, s32 kind) {
    HmfData* hmf;
    Gfx* buf;
    Gfx* gfx;
    u32 count;
    u32 i;
    s32 size;
    s32 idx;
    s32 file;

    buf = gfx = HuMemAlloc(0x10000);
    file = 0x1840;
    if (kind == 0) {
        file = 0xC0;
    }
    idx = func_80027FA4_28BA4(file, buf, 4);
    hmf = SGS_MODEL(idx)->hmf;
    hmf->unk64->unk50 |= 0x71010000;
    count = func_801099BC_24D2CC_ShyGuySays(spr, hmf, D_8010A1D0_24DAE0_ShyGuySays[kind], D_8010A1DC_24DAEC_ShyGuySays[kind].unk_00, D_8010A1DC_24DAEC_ShyGuySays[kind].unk_04);
    gSPDisplayList(gfx++, osVirtualToPhysical(D_8010A190_24DAA0_ShyGuySays));
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPPipeSync(gfx++);
    if (kind == 0) {
        gSPClearGeometryMode(gfx++, G_CULL_BOTH | G_LIGHTING);
        gSPSetGeometryMode(gfx++, G_ZBUFFER | G_SHADE | G_CULL_FRONT | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH);
    } else {
        gSPClearGeometryMode(gfx++, G_ZBUFFER | G_CULL_BOTH | G_LIGHTING);
        gSPSetGeometryMode(gfx++, G_SHADE | G_CULL_FRONT | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH);
    }
    gDPSetColorDither(gfx++, G_CD_NOISE);
    gDPSetTexturePersp(gfx++, G_TP_NONE);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gDPSetTextureConvert(gfx++, G_TC_FILT);
    gDPSetAlphaDither(gfx++, G_AD_PATTERN);
    gDPSetAlphaCompare(gfx++, G_AC_NONE);
    gDPSetBlendColor(gfx++, 0x01, 0x01, 0x01, 0x01);
    gDPPipeSync(gfx++);
    if (kind == 0) {
        gDPSetRenderMode(gfx++, G_RM_AA_ZB_XLU_SURF, G_RM_NOOP2);
    } else {
        gDPSetRenderMode(gfx++, G_RM_AA_XLU_SURF, G_RM_NOOP2);
    }
    gDPSetCombineLERP(gfx++, 0, 0, 0, TEXEL0, TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, SHADE, 0);
    gDPSetPrimColor(gfx++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    gDPPipeSync(gfx++);
    gSPTexture(gfx++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTexturePersp(gfx++, G_TP_PERSP);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);
    gDPLoadTLUT_pal256(gfx++, spr->unk0C);
    gDPPipeSync(gfx++);
    for (i = 0; i < count; i++) {
        gSPSegment(gfx++, 0x04, osVirtualToPhysical((u8*)spr->unk08 + 0x800 * i));
        gDPLoadTextureBlock(gfx++, 0x04000000, G_IM_FMT_CI, G_IM_SIZ_8b, (u16)spr->unk14, (u16)spr->unk16 / count, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
        gDPPipeSync(gfx++);
        gSPSegment(gfx++, 0x01, osVirtualToPhysical(&hmf->unk44[0][i * 4]));
        gSPVertex(gfx++, 0x01000000, 4, 0);
        gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    }
    gDPPipeSync(gfx++);
    gSPEndDisplayList(gfx++);
    size = (u32)gfx - (u32)buf;
    hmf->unk3C->unk00[0] = func_80027154_27D54(size, hmf->unk0E);
    bcopy(buf, hmf->unk3C->unk00[0], size);
    HuMemFree(buf);
    return idx;
}

s32 func_801099BC_24D2CC_ShyGuySays(HuSprite_Unk84_Struct* spr, HmfData* hmf, f32 scale, s16 x, s16 y) {
    Vtx* buf;
    Vtx* v;
    Vtx_t* to;
    Vtx_t* from;
    s32 tmem;
    s32 w;
    s32 h;
    s32 sw;
    s32 sh;
    s32 size;
    s32 count;
    s32 qh;
    s32 qsh;
    s32 n;
    s32 i;
    s32 j;

    if (spr->unk1A >= 2) {
        tmem = 0x800;
    } else {
        tmem = 0x1000;
    }
    w = (u16)spr->unk14;
    h = (u16)spr->unk16;
    sw = w * 20.0 * scale;
    sh = h * 20.0 * scale;
    if (spr->unk18 == 4) {
        size = ((w + 1) & 0xFFFE) * h * 4;
    } else {
        size = w * h * spr->unk18;
    }
    size = (size < 0) ? (size + 7) : size;
    size >>= 3;
    count = size / tmem;
    qh = h / count;
    qsh = sh / count;
    n = count * 4;
    buf = v = HuMemMemoryAllocPerm(n * sizeof(Vtx));
    func_800B0EF0_B1AF0(buf, 0, n * sizeof(Vtx));
    for (i = 0; i < count; i++, v += 4) {
        v[0].v.ob[0] = (s32)(sw * 0.5);
        v[0].v.ob[1] = (s32)(sh * 0.5 - qsh * i);
        v[0].v.tc[0] = (w - 1) * 64;
        v[0].v.tc[1] = 0;
        v[1].v.ob[0] = (s32)(sw * 0.5);
        v[1].v.ob[1] = (s32)(sh * 0.5 - qsh * (i + 1));
        v[1].v.tc[0] = (w - 1) * 64;
        v[1].v.tc[1] = (qh - 1) * 64;
        v[2].v.ob[0] = (s32) - (sw * 0.5);
        v[2].v.ob[1] = (s32)(sh * 0.5 - qsh * i);
        v[2].v.tc[0] = 0;
        v[2].v.tc[1] = 0;
        v[3].v.ob[0] = (s32) - (sw * 0.5);
        v[3].v.ob[1] = (s32)(sh * 0.5 - qsh * (i + 1));
        v[3].v.tc[0] = 0;
        v[3].v.tc[1] = (qh - 1) * 64;
        for (j = 0; j < 4; j++) {
            v[j].v.ob[0] += x;
            v[j].v.ob[1] += y;
            v[j].v.ob[2] = 0;
            v[j].v.flag = 0;
            v[j].v.cn[3] = 0xFF;
            v[j].v.cn[0] = v[j].v.cn[1] = v[j].v.cn[2] = 0;
        }
    }
    v = buf;
    for (i = 0; i < D_800FDBCA_FE7CA; i++) {
        hmf->unk44[i] = func_80027154_27D54(n * sizeof(Vtx), hmf->unk0E);
        to = (Vtx_t*)hmf->unk44[i];
        from = &v->v;
        for (j = 0; j < n; j++) {
            *(to++) = *(from++);
        }
    }
    HuMemMemoryFreePerm(buf);
    return count;
}

/* .data (0x24D6C0-0x24DB10, 80109DB0-8010A200) */
u32 D_80109DB0_24D6C0_ShyGuySays = 0x19971204;
u16 D_80109DB4_24D6C4_ShyGuySays = 0;
s16 D_80109DB6_24D6C6_ShyGuySays = 0;
s16 D_80109DB8_24D6C8_ShyGuySays = 0;
s16 D_80109DBA_24D6CA_ShyGuySays = 0;
s16 D_80109DBC_24D6CC_ShyGuySays = 0;
s16 D_80109DBE_24D6CE_ShyGuySays = 0;
s16 D_80109DC0_24D6D0_ShyGuySays = 0;
s16 D_80109DC2_24D6D2_ShyGuySays = 0;
s32 D_80109DC4_24D6D4_ShyGuySays = 0;
char D_80109DC8_24D6D8_ShyGuySays[6][2][0x20] = {
    { "migi-te2_4", "migi-te3_2_1" },
    { "c001_000-migi-te2_2", "c001_000-migi-te2_3" },
    { "C002_000b-bmerge14", "C002_000b-bmerge16" },
    { "c003_000-bmerge1_13_1", "c003_000-bmerge1_8" },
    { "Luigi1-migi-te1_2", "Luigi1-migi-te1_1" },
    { "c005_000-bmerge4", "c005_000-bmerge6" },
};
s32 D_80109F48_24D858_ShyGuySays[6][4] = {
    { 0, 2, 1, 3 },     { 4, 6, 5, 7 },     { 8, 10, 9, 11 },
    { 12, 14, 13, 15 }, { 16, 18, 17, 19 }, { 20, 22, 21, 23 },
};
u16 D_80109FA8_24D8B8_ShyGuySays[6] = { 0x21, 0x22, 0x23, 0x24, 0x25, 0x26 };
s16 D_80109FB4_24D8C4_ShyGuySays[4] = { 0x20, 0x2C, 0x58, 0x60 };
s32 D_80109FBC_24D8CC_ShyGuySays = 0;
s32 D_80109FC0_24D8D0_ShyGuySays = -1;
Vec D_80109FC4_24D8D4_ShyGuySays[3] = {
    { 140.0f, 0.0f, 0.0f },
    { -60.0f, -70.0f, 0.0f },
    { 40.0f, -140.0f, 0.0f },
};
f32 D_80109FE8_24D8F8_ShyGuySays[6] = { 200.0f, 200.0f, 200.0f, 200.0f, 200.0f, 170.0f };
Vec D_8010A000_24D910_ShyGuySays[3] = {
    { 600.0f, 70.0f, -1600.0f },
    { 200.0f, -230.0f, -1500.0f },
    { -500.0f, -130.0f, -1600.0f },
};
f32 D_8010A024_24D934_ShyGuySays[3] = { 3.0f, 4.0f, 3.0f };
u32 D_8010A030_24D940_ShyGuySays = 180;
u32 D_8010A034_24D944_ShyGuySays = 0;
s32 D_8010A038_24D948_ShyGuySays = 0;
u16 D_8010A03C_24D94C_ShyGuySays = 0;
u16 D_8010A03E_24D94E_ShyGuySays = 0;
u16 D_8010A040_24D950_ShyGuySays = 0;
u16 D_8010A042_24D952_ShyGuySays = 0;
f32 D_8010A044_24D954_ShyGuySays = 40.0f;
SGSFlagVtx D_8010A048_24D958_ShyGuySays[4] = {
    { 11, 0.3f }, { 17, 0.9f }, { 19, 0.6f }, { 0xFF, 0.0f },
};
SGSFlagVtx D_8010A068_24D978_ShyGuySays[4] = {
    { 8, 0.3f }, { 16, 0.6f }, { 18, 0.9f }, { 0xFF, 0.0f },
};
f32 D_8010A088_24D998_ShyGuySays[4] = { 200.0f, 190.0f, 170.0f, 160.0f };
f32 D_8010A098_24D9A8_ShyGuySays = 180.0f;
f32 D_8010A09C_24D9AC_ShyGuySays = 0.0f;
Gfx D_8010A0A0_24D9B0_ShyGuySays[] = {
    gsSPSegment(0x00, 0x00000000),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPPipelineMode(G_PM_1PRIMITIVE),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0, 0),
    gsDPSetTileSize(1, 0, 0, 0, 0),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0000, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetDepthSource(G_ZS_PIXEL),
    gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
    gsDPNoOp(),
    gsDPSetColorDither(G_CD_DISABLE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
Gfx D_8010A158_24DA68_ShyGuySays[] = {
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA),
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_OFF),
    gsSPSetGeometryMode(G_SHADE | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};
Gfx D_8010A178_24DA88_ShyGuySays[] = {
    gsSPDisplayList(D_8010A158_24DA68_ShyGuySays),
    gsSPDisplayList(D_8010A0A0_24D9B0_ShyGuySays),
    gsSPEndDisplayList(),
};
Gfx D_8010A190_24DAA0_ShyGuySays[] = {
    gsDPPipeSync(),
    gsSPDisplayList(D_8010A178_24DA88_ShyGuySays),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPSetGeometryMode(G_ZBUFFER | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsDPSetBlendColor(0x00, 0x00, 0x00, 0x00),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0xFF),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPEndDisplayList(),
};
f32 D_8010A1D0_24DAE0_ShyGuySays[3] = { 0.047f, 0.1f, 0.1f };
Vec2f D_8010A1DC_24DAEC_ShyGuySays[3] = { { 0.0f, 0.0f }, { -64.0f, 0.0f }, { 64.0f, 0.0f } };
