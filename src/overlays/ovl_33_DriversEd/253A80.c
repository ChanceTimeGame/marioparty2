#include "ovl_33.h"

void func_80102800_253A80_DriversEd(void) {
    func_801075F0_258870_DriversEd();
}

__asm__(".section .rodata");
const char D_801085C0_259840_DriversEd[] = "signl_3x_DEF";

__asm__(".section .rodata");
const char D_801085D0_259850_DriversEd[] = "signl_2x_DEF";

__asm__(".section .rodata");
const char D_801085E0_259860_DriversEd[] = "signl_1x_DEF";

void func_8010281C_253A9C_DriversEd(void) {
    Vec from;
    Vec to;
    Vec out;
    omObjData* car;

    car = D_80108720_2599A0_DriversEd[0].obj;
    to.x = 1960.8251f;
    to.y = 0.0f;
    to.z = 2018.0901f;
    from.x = 52.649998f;
    from.y = 0.0f;
    from.z = -82.55f;
    func_801078D0_258B50_DriversEd(&from, &to, &out);
    Hu3DCamSetPerspective(0, 21.176f, 80.0f, 8000.0f);
    D_800FA610_FB210 = out.x;
    D_800FD474_FE074.x = 360.0 - out.z;
    D_800FD474_FE074.y = 0.0f;
    D_800FD474_FE074.z = 0.0f;
    D_8010274C_10334C.x = car->trans.x;
    D_8010274C_10334C.y = 0.0f;
    D_8010274C_10334C.z = car->trans.z;
}

void func_80102914_253B94_DriversEd(void) {
}

void func_8010291C_253B9C_DriversEd(void) {
    Vec from;
    Vec to;
    Vec out;

    to.x = 1960.8251f;
    to.y = 0.0f;
    to.z = 2018.0901f;
    from.x = 52.649998f;
    from.y = 0.0f;
    from.z = -82.55f;
    func_801078D0_258B50_DriversEd(&from, &to, &out);
    Hu3DCamSetPerspective(0, 21.176f, 80.0f, 8000.0f);
    D_800FA610_FB210 = out.x;
    D_800FD474_FE074.x = 360.0 - out.z;
    D_800FD474_FE074.y = 0.0f;
    D_800FD474_FE074.z = 0.0f;
    D_8010274C_10334C.x = 0.0f;
    D_8010274C_10334C.y = from.x;
    D_8010274C_10334C.z = from.z;
    omAddObj(0xC8, 0, 0, -1, func_80102914_253B94_DriversEd);
}

void func_80102A24_253CA4_DriversEd(void) {
}

void func_80102A2C_253CAC_DriversEd(omObjData* obj) {
    obj->model[0] = LoadFormFile(0x430000, 0x299);
    obj->trans.x = 0.0f;
    obj->trans.y = 0.0f;
    obj->trans.z = 0.0f;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    obj->func_ptr = func_80102A24_253CA4_DriversEd;
}

void func_80102A90_253D10_DriversEd(void) {
    D_80108720_2599A0_DriversEd[10].obj = omAddObj(0xA, 1, 0, -1, func_80102A2C_253CAC_DriversEd);
}

void func_80102ACC_253D4C_DriversEd(omObjData* obj) {
    DEFxWork* w;
    DEFx* fx;
    u16 m;
    s16 i;

    w = obj->unk_50;
    for (i = 0; i < 8; i++) {
        if (w->state[i] != 0) {
            fx = &w->fx[i];
            m = D_800F86D8_F92D8[fx->model].unk00;
            switch (w->state[i]) {
            case 1:
                break;
            case 2:
                fx->y += fx->vy;
                fx->vy += 0.3f;
                func_80029714_2A314(m, fx->x, fx->y, fx->z);
                break;
            }
            func_800211E8_21DE8(fx->model, fx->alpha);
            if (D_800FC834_FD434[(s16)m].unk18 & 4) {
                w->state[i] = 0;
            }
        }
    }
}

void func_80102C00_253E80_DriversEd(omObjData* obj) {
    DEFxWork* w;
    void* data;
    s16 tex;
    s16 i;
    s16 m;

    w = obj->unk_50 = func_80027154_27D54(sizeof(DEFxWork), 0x7918);
    data = DataRead(0x40001C);
    tex = func_8003DF08_3EB08(data);
    HuMemMemoryFreePerm(data);
    for (i = 0; i < 8; i++) {
        w->fx[i].model = m = func_80020EBC_21ABC((void*)-1, 0x284, 8);
        func_80021250_21E50(m, 0xFF, 0xFF, 0xFF);
        D_800F86D8_F92D8[m].unk02 = tex;
        func_80021160_21D60(m, 4, 4);
        w->state[i] = 0;
    }
    obj->func_ptr = func_80102ACC_253D4C_DriversEd;
}

void func_80102D20_253FA0_DriversEd(void) {
    D_80108688_259908_DriversEd = omAddObj(0x258, 0, 0, -1, func_80102C00_253E80_DriversEd);
}

void func_80102D5C_253FDC_DriversEd(s16 player, f32 x, f32 y, f32 z, u16 type) {
    DEFxWork* w;
    DEFx* fx;
    u16 m;
    s16 i;

    w = D_80108688_259908_DriversEd->unk_50;
    for (i = 0; i < 8; i++) {
        if (w->state[i] == 0) {
            break;
        }
    }
    if (i != 8) {
        fx = &w->fx[i];
        m = D_800F86D8_F92D8[fx->model].unk00;
        fx->x = x;
        fx->y = y + 30.0f;
        fx->z = z;
        fx->vy = 2.0f;
        fx->alpha = 0xFF;
        w->state[i] = type;
        fx->unk_02 = 1;
        func_800211E8_21DE8(fx->model, 0);
        func_800298A4_2A4A4(m, 4, 0);
        D_800F86D8_F92D8[fx->model].unk04 = 0;
        func_80029714_2A314(m, x, y, z);
        func_800297E8_2A3E8(m, 2.0f, 2.0f, 2.0f);
    }
}

void func_80102EE0_254160_DriversEd(omObjData* obj) {
    f32 s;

    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    if (obj->work[0] == D_801086BF_25993F_DriversEd) {
        if (obj->work[3] == 0) {
            func_80029E80_2AA80(obj->model[1], 1, 0);
            func_80029E80_2AA80(obj->model[1], 2, 2);
            if (D_801086BD_25993D_DriversEd == 0) {
                obj->work[3] = 1;
            }
        }
    } else {
        func_80029E80_2AA80(obj->model[1], 1, 1);
    }
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y + 190.0f, obj->trans.z);
    if (D_801086C0_259940_DriversEd[obj->work[0] - 11] == 1) {
        if (obj->work[2] >= 3) {
            if (D_801086BD_25993D_DriversEd == 0) {
                func_800298A4_2A4A4(obj->model[1], 4, 4);
            }
        } else if (D_801086BD_25993D_DriversEd == 0) {
            obj->work[2]++;
            s = (f32)obj->work[2] * 0.2f;
            func_800297E8_2A3E8(obj->model[1], s + obj->scale.x, s + obj->scale.y, s + obj->scale.z);
        }
    }
}

void func_80103074_2542F4_DriversEd(omObjData* obj) {
    void* data;

    obj->model[0] = LoadFormFile(0x430001, 0x299);
    obj->model[1] = LoadFormFile(0x430002, 0x2A9);
    data = DataRead(D_80108558_2597D8_DriversEd[obj->work[0] - 11] | 0x430000);
    D_801086D4_259954_DriversEd = func_8003D8F0_3E4F0(D_800FC834_FD434[obj->model[1]].hmf, data, 0, "20_DEF");
    func_8003E4F4_3F0F4(D_801086D4_259954_DriversEd, 1, 1);
    HuMemMemoryFreePerm(data);
    func_80029A8C_2A68C(obj->model[1]);
    func_80029AFC_2A6FC(obj->model[1]);
    func_80029E80_2AA80(obj->model[1], 1, 1);
    obj->trans.x = D_80107D88_259008_DriversEd[D_801086BC_25993C_DriversEd][obj->work[0] - 11].x;
    obj->trans.y = D_80107D88_259008_DriversEd[D_801086BC_25993C_DriversEd][obj->work[0] - 11].y;
    obj->trans.z = D_80107D88_259008_DriversEd[D_801086BC_25993C_DriversEd][obj->work[0] - 11].z;
    obj->rot.y = D_80107D88_259008_DriversEd[D_801086BC_25993C_DriversEd][obj->work[0] - 11].rot;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y + 190.0f, obj->trans.z);
    obj->func_ptr = func_80102EE0_254160_DriversEd;
}

void func_80103258_2544D8_DriversEd(void) {
    DEObj* p;
    omObjData* o;
    s16 i;

    for (i = 11; i < 31; i++) {
        p = &D_80108720_2599A0_DriversEd[i];
        o = omAddObj(0x190, 4, 1, -1, func_80103074_2542F4_DriversEd);
        o->work[0] = i;
        p->obj = o;
    }
}

void func_801032FC_25457C_DriversEd(void) {
    DEObj* p;
    s16 i;

    p = &D_80108720_2599A0_DriversEd[35];
    if (D_80108680_259900_DriversEd == 2) {
        if (D_80108682_259902_DriversEd >= 0x708) {
            D_801086D5_259955_DriversEd[0] = 1;
            D_801086D5_259955_DriversEd[4] = 0;
            D_801086D5_259955_DriversEd[3] = 0;
            D_801086D5_259955_DriversEd[2] = 0;
            D_801086D5_259955_DriversEd[1] = 0;
        } else {
            D_801086D5_259955_DriversEd[0] = 0;
            D_801086D5_259955_DriversEd[1] = D_80108682_259902_DriversEd / 300;
            D_801086D5_259955_DriversEd[2] = (D_80108682_259902_DriversEd - D_801086D5_259955_DriversEd[1] * 300) / 30;
            D_801086D5_259955_DriversEd[5] = (rand8() & 0xFF) % 3 + (D_80108682_259902_DriversEd - (D_801086D5_259955_DriversEd[1] * 300 + D_801086D5_259955_DriversEd[2] * 30)) * 335 / 100;
            D_801086D5_259955_DriversEd[3] = D_801086D5_259955_DriversEd[5] / 10;
            D_801086D5_259955_DriversEd[4] = D_801086D5_259955_DriversEd[5] % 10;
        }
    }
    for (i = 0; i < 5; i++) {
        SprBankSet(p->unk_80, i, D_801086D5_259955_DriversEd[i]);
        D_80108706_259986_DriversEd[i] = D_801086D5_259955_DriversEd[i];
    }
}

void func_80103538_2547B8_DriversEd(omObjData* obj) {
    DEObj* p;
    s16 i;
    u32 rec;

    p = &D_80108720_2599A0_DriversEd[35];
    p->unk_80 = SprCreate(7, 5);
    p->unk_70 = func_8001A2F8_1AEF8(0x43);
    SprPosSet(p->unk_80, 0, 0x83, 0x2C);
    SprAnimSet(p->unk_80, 0, p->unk_70, 0);
    func_8008225C_82E5C(p->unk_80, 0, 0);
    SprAttrSet(p->unk_80, 0, 0x1000);
    SprAttrSet(p->unk_80, 0, 0);
    for (i = 1; i < 7; i++) {
        func_800824F4_830F4(p->unk_80, i, 0);
        SprAnimSet(p->unk_80, i, p->unk_70, 0);
        func_8008225C_82E5C(p->unk_80, i, 0);
        SprPosSet(p->unk_80, i, D_80108594_259814_DriversEd[i], 0);
        SprAttrSet(p->unk_80, i, 0x1000);
        SprAttrSet(p->unk_80, i, 0);
    }
    SprBankSet(p->unk_80, 5, D_801085A4_259824_DriversEd[5]);
    SprBankSet(p->unk_80, 6, D_801085A4_259824_DriversEd[6]);
    rec = func_800680D4_68CD4(D_801086BC_25993C_DriversEd + 8);
    D_80108710_259990_DriversEd = rec;
    if (D_80108710_259990_DriversEd != 0) {
        D_801085A4_259824_DriversEd[0] = 0;
        D_801085A4_259824_DriversEd[1] = D_80108710_259990_DriversEd >> 12;
        D_801085A4_259824_DriversEd[2] = (rec >> 8) & 0xF;
        D_801085A4_259824_DriversEd[3] = (rec >> 4) & 0xF;
        D_801085A4_259824_DriversEd[4] = rec & 0xF;
    }
    p->unk_82 = SprCreate(7, 5);
    p->unk_72 = func_8001A2F8_1AEF8(0x45);
    SprPosSet(p->unk_82, 0, 0x83, 0x1C);
    SprAnimSet(p->unk_82, 0, p->unk_72, 0);
    func_8008225C_82E5C(p->unk_82, 0, 0);
    SprBankSet(p->unk_82, 0, D_801085A4_259824_DriversEd[0]);
    SprAttrSet(p->unk_82, 0, 0x1000);
    SprAttrSet(p->unk_82, 0, 0);
    for (i = 1; i < 7; i++) {
        func_800824F4_830F4(p->unk_82, i, 0);
        SprAnimSet(p->unk_82, i, p->unk_72, 0);
        SprPosSet(p->unk_82, i, D_80108594_259814_DriversEd[i], 0);
        SprBankSet(p->unk_82, i, D_801085A4_259824_DriversEd[i]);
        func_8008225C_82E5C(p->unk_82, i, 0);
        SprAttrSet(p->unk_82, i, 0x1000);
        SprAttrSet(p->unk_82, i, 0);
    }
    obj->func_ptr = func_801032FC_25457C_DriversEd;
}

void func_80103894_254B14_DriversEd(void) {
    D_80108720_2599A0_DriversEd[35].obj = omAddObj(0x320, 0, 0, -1, func_80103538_2547B8_DriversEd);
}

void func_801038D0_254B50_DriversEd(omObjData* obj) {
    DEObj* p;
    s16 i;

    p = &D_80108720_2599A0_DriversEd[5];
    switch (D_801086EE_25996E_DriversEd) {
    case 0:
        obj->trans.y -= 15.0f;
        p->unk_88 += 0.015;
        if (obj->trans.y <= 360.0f) {
            obj->trans.y = 360.0f;
            D_801086EE_25996E_DriversEd = 1;
        }
        func_800298A4_2A4A4(obj->model[0], 4, 0);
        func_800298A4_2A4A4(obj->model[1], 4, 0);
        func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
        func_800297E8_2A3E8(obj->model[1], p->unk_88, 0.0f, p->unk_88);
        func_80029714_2A314(obj->model[1], obj->trans.x, 8.0f, obj->trans.z);
        break;
    case 1:
        obj->trans.y = (f32)p->unk_80 * 0.1f + obj->trans.y;
        func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
        func_80029714_2A314(obj->model[1], obj->trans.x, 8.0f, obj->trans.z);
        func_800297E8_2A3E8(obj->model[1], 1.5f, 0.0f, 1.5f);
        func_800B1F50_B2B50(D_800FC834_FD434[obj->model[1]].mtx, 0.0f, 20.0f, 0.0f);
        if (p->unk_72 == 0) {
            if (++p->unk_80 > 10) {
                p->unk_72 ^= 1;
            }
        } else {
            if (--p->unk_80 < -10) {
                p->unk_72 ^= 1;
            }
        }
        if (p->unk_70 == 0) {
            for (i = 0; i < 3; i++) {
                func_8003E4F4_3F0F4(D_801086E8_259968_DriversEd[i], 1, 0);
            }
        } else if (p->unk_70 == 30) {
            PlaySound(0x2D9);
        } else if (p->unk_70 == 60) {
            D_80108681_259901_DriversEd = 1;
            PlaySound(0x2D9);
            PlayMusic(0x1C);
        } else if (p->unk_70 == 90) {
            PlaySound(0x2DA);
        }
        if (D_80108680_259900_DriversEd == 2) {
            D_801086EE_25996E_DriversEd = 3;
            p->unk_70 = 0;
        }
        p->unk_70++;
        break;
    case 2:
        p->unk_70++;
        if (p->unk_70 >= 10) {
            D_801086EE_25996E_DriversEd = 3;
        }
        break;
    case 3:
        obj->trans.y += 30.0f;
        p->unk_88 -= 0.05f;
        if (p->unk_88 <= 0.0f) {
            p->unk_88 = 0.0f;
            obj->trans.y = 2100.0f;
            func_800298A4_2A4A4(obj->model[0], 4, 4);
            func_800298A4_2A4A4(obj->model[1], 4, 4);
        }
        func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
        func_80029714_2A314(obj->model[1], obj->trans.x, 8.0f, obj->trans.z);
        func_800297E8_2A3E8(obj->model[1], p->unk_88, 0.0f, p->unk_88);
        break;
    case 4:
        func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
        func_80029714_2A314(obj->model[1], obj->trans.x, 8.0f, obj->trans.z);
        func_800297E8_2A3E8(obj->model[1], 0.7f, 0.0f, 0.7f);
        func_800298A4_2A4A4(obj->model[0], 4, 4);
        func_800298A4_2A4A4(obj->model[1], 4, 4);
        PlayMusic(0x39);
        break;
    }
}

void func_80103D74_254FF4_DriversEd(omObjData* obj) {
    omObjData* car;
    s16 i;

    obj->model[0] = LoadFormFile(0x190006, 0x2A9);
    for (i = 0; i < 3; i++) {
        D_801086DC_25995C_DriversEd[i] = DataRead(D_80108580_259800_DriversEd[i] | 0x190000);
        D_801086E8_259968_DriversEd[i] = func_8003D8F0_3E4F0(D_800FC834_FD434[obj->model[0]].hmf, D_801086DC_25995C_DriversEd[i], 0, D_80108588_259808_DriversEd[i]);
        func_8003E4F4_3F0F4(D_801086E8_259968_DriversEd[i], 1, 1);
        HuMemMemoryFreePerm(D_801086DC_25995C_DriversEd[i]);
    }
    func_80029A8C_2A68C(obj->model[0]);
    func_80029E80_2AA80(obj->model[0], 2, 2);
    func_80029AFC_2A6FC(obj->model[0]);
    obj->model[1] = func_80018A30_19630(1, 0x89);
    HmfModelObjAttrSet(obj->model[1], 0x80000000, 0);
    func_80029A8C_2A68C(obj->model[1]);
    func_80029AFC_2A6FC(obj->model[1]);
    func_800B1F50_B2B50(D_800FC834_FD434[obj->model[1]].mtx, 0.0f, 10.0f, 0.0f);
    car = D_80108720_2599A0_DriversEd[0].obj;
    obj->trans.x = car->trans.x + 300.0f;
    obj->trans.y = 1200.0f;
    obj->trans.z = car->trans.z;
    obj->rot.y = 345.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.3f;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80029714_2A314(obj->model[1], obj->trans.x, 8.0f, obj->trans.z);
    func_800297E8_2A3E8(obj->model[1], 0.7f, 0.0f, 0.7f);
    D_80108AA0_259D20_DriversEd = 0.7f;
    D_801086EE_25996E_DriversEd = 4;
    obj->func_ptr = func_801038D0_254B50_DriversEd;
}

void func_80104038_2552B8_DriversEd(void) {
    D_80108720_2599A0_DriversEd[5].obj = omAddObj(0x190, 2, 1, -1, func_80103D74_254FF4_DriversEd);
}

void func_80104074_2552F4_DriversEd(void) {
    if (D_80108684_259904_DriversEd > 0) {
        if (--D_80108684_259904_DriversEd == 0) {
            D_80108684_259904_DriversEd = 0;
            D_80108681_259901_DriversEd = 1;
        } else if (D_80108682_259902_DriversEd == 10) {
            func_80079614_7A214(40);
        }
    }
}

void func_801040E0_255360_DriversEd(omObjData* obj) {
    s16 best;
    s16 mine;
    s16 i;

    best = 0;
    mine = 0;
    if (D_80108684_259904_DriversEd > 0) {
        if (D_801086DB_25995B_DriversEd == 2) {
            if (D_80108684_259904_DriversEd == 130) {
                for (i = 0; i < 5; i++) {
                    best = best * 10 + D_801085A4_259824_DriversEd[i];
                    mine = mine * 10 + D_80108706_259986_DriversEd[i];
                }
                if (best > mine) {
                    func_800691FC_69DFC(14);
                    D_80108710_259990_DriversEd = 0;
                    for (i = 1; i < 5; i++) {
                        D_80108710_259990_DriversEd *= 16;
                        D_80108710_259990_DriversEd += D_80108706_259986_DriversEd[i];
                    }
                    GWMgRecordSet(*(s8*)&D_801086BC_25993C_DriversEd + 8, D_80108710_259990_DriversEd);
                    D_80108704_259984_DriversEd = 1;
                } else {
                    D_80108684_259904_DriversEd = 120;
                }
            }
        }
        D_80108684_259904_DriversEd--;
        if (D_801086DB_25995B_DriversEd == 2 && D_80108704_259984_DriversEd == 1) {
            if (D_80108684_259904_DriversEd == 90) {
                D_80108681_259901_DriversEd = 1;
                PlayMusic(0x55);
                D_80108684_259904_DriversEd = 162;
                obj->func_ptr = func_80104074_2552F4_DriversEd;
            }
        } else if (func_80069538_6A138() == 0) {
            if (D_801086DB_25995B_DriversEd == 2) {
                if (D_80108684_259904_DriversEd < 130) {
                    D_80108681_259901_DriversEd = 1;
                    PlayMusic(0x51);
                    D_80108684_259904_DriversEd = 120;
                    obj->func_ptr = func_80104074_2552F4_DriversEd;
                }
            } else {
                D_80108681_259901_DriversEd = 1;
                func_800691FC_69DFC(16);
                PlayMusic(0x56);
                D_80108684_259904_DriversEd = 132;
                obj->func_ptr = func_80104074_2552F4_DriversEd;
            }
        }
    }
}

void func_80104344_2555C4_DriversEd(omObjData* obj) {
    if (D_80108680_259900_DriversEd == 2) {
        if (++D_80108682_259902_DriversEd < 0x709) {
            if (D_801086BD_25993D_DriversEd == 1) {
                func_800691FC_69DFC(3);
                D_80108681_259901_DriversEd = 1;
                D_80108684_259904_DriversEd = 120;
                func_800794A8_7A0A8(40);
                obj->func_ptr = func_801040E0_255360_DriversEd;
            } else if (D_801086DB_25995B_DriversEd == 1) {
                D_801086DB_25995B_DriversEd = 2;
                D_80108681_259901_DriversEd = 1;
                D_80108684_259904_DriversEd = 180;
                func_800691FC_69DFC(20);
                func_800794A8_7A0A8(40);
                obj->func_ptr = func_801040E0_255360_DriversEd;
            }
        } else {
            func_800691FC_69DFC(18);
            D_80108681_259901_DriversEd = 1;
            D_80108684_259904_DriversEd = 150;
            func_800794A8_7A0A8(40);
            obj->func_ptr = func_801040E0_255360_DriversEd;
        }
    }
}

void func_8010443C_2556BC_DriversEd(omObjData* obj) {
    if (D_80108680_259900_DriversEd == 1) {
        if (++D_80108686_259906_DriversEd == 1) {
            func_800691FC_69DFC(15);
        } else if (D_80108686_259906_DriversEd == 31) {
            D_80108681_259901_DriversEd = 1;
            obj->func_ptr = func_80104344_2555C4_DriversEd;
            D_80108686_259906_DriversEd = 0;
        }
    }
}

void func_801044C4_255744_DriversEd(omObjData* obj) {
    DECar* c;
    DEObj* p;
    f32 t;
    f32 a;
    f32 zero;
    f32 u;
    f32 v;
    f32 s;
    f32 w;
    s16 n;

    p = &D_80108720_2599A0_DriversEd[0];
    c = &D_80108690_259910_DriversEd;
    if (p->unk_70 == 0) {
        c->steer = 0.0f;
        if (D_80108680_259900_DriversEd >= 4) {
            if (D_801086DB_25995B_DriversEd == 2 && D_80108682_259902_DriversEd < 0x709) {
                obj->rot.y = DE_WRAP(obj->rot.y - 15.0f);
                if (p->unk_7A == 0) {
                    t = HuMathSin(obj->rot.y + 180.0f) * 75.0f + obj->trans.x;
                    func_80102D5C_253FDC_DriversEd(obj->work[0], t, obj->trans.y, func_800B7890_B8490(obj->rot.y + 180.0f) * 75.0f + obj->trans.z, 2);
                    p->unk_7A++;
                } else if (p->unk_7A == 2) {
                    p->unk_7A = 0;
                } else {
                    p->unk_7A++;
                }
                c->unk_20++;
                if (D_80108680_259900_DriversEd != 5) {
                    if (D_801085B2_259832_DriversEd == 0) {
                        c->sndFwd = func_80079798_7A398(0x2D7, obj->work[0]);
                        D_801085B2_259832_DriversEd = 1;
                    }
                } else if (c->sndFwd != -1) {
                    func_80079848_7A448(c->sndFwd);
                    c->sndFwd = -1;
                }
            }
        } else {
            if (D_80108680_259900_DriversEd == 2) {
                goto drive;
            }
            if (D_80108680_259900_DriversEd == 3) {
            drive:
                obj->trans.x = HuMathSin(obj->rot.y) * c->speed + obj->trans.x;
                obj->trans.z = func_800B7890_B8490(obj->rot.y) * c->speed + obj->trans.z;
            }
        }
    } else {
        if ((f32)p->unk_70 * c->steer + obj->rot.y >= 360.0f) {
            a = (f32)p->unk_70 * c->steer + obj->rot.y - 360.0f;
        } else {
            w = (f32)p->unk_70 * c->steer;
            a = w + obj->rot.y;
            if (a < 0.0f) {
                a += 360.0f;
            }
        }
        obj->rot.y = a;
        s = c->speed;
        zero = 0.0f;
        if (s != zero) {
            c->speed = c->bounce + ((f32)p->unk_70 * 0.1) * ((f32)p->unk_70 * 0.1) * 4.0 - 18.0;
            if (c->speed <= zero) {
                c->speed = zero;
                p->unk_70 = 0;
            }
            obj->trans.x -= HuMathSin(c->dir) * c->speed;
            obj->trans.z -= func_800B7890_B8490(c->dir) * c->speed;
            n = p->unk_70 - 17;
            if (c->bounce > 14.0f || c->bounce < -14.0f) {
                if (n < 0) {
                    u = (f32)n * 0.6f;
                    obj->trans.y = obj->trans.y - u * c->bounce * u;
                } else {
                    v = (f32)n * 0.45f;
                    obj->trans.y = v * c->bounce * v + obj->trans.y;
                }
                if (obj->trans.y < 0.0f) {
                    obj->trans.y = 0.0f;
                }
            } else {
                obj->trans.y = 0.0f;
            }
        }
    }
}

void func_80104984_255C04_DriversEd(omObjData* obj) {
    Vec from;
    Vec to;
    Vec out;

    if (D_80108690_259910_DriversEd.speed == 0.0f) {
        if ((f32)ContStkX[gPlayers[obj->work[0]].port] > 0.0f) {
            obj->rot.y = DE_WRAP(obj->rot.y - 6.0f);
        } else if ((f32)ContStkX[gPlayers[obj->work[0]].port] < 0.0f) {
            obj->rot.y = DE_WRAP(obj->rot.y + 6.0f);
        }
    } else {
        from.x = 0.0f;
        from.y = 0.0f;
        from.z = 0.0f;
        to.x = ContStkX[gPlayers[obj->work[0]].port];
        to.y = 0.0f;
        to.z = ContStkY[gPlayers[obj->work[0]].port];
        func_801078D0_258B50_DriversEd(&from, &to, &out);
        if (out.z > 30.0f && out.z < 84.0f) {
            obj->rot.y = DE_WRAP(obj->rot.y - 6.0f);
        } else if (out.z > 276.0f && out.z < 330.0f) {
            obj->rot.y = DE_WRAP(obj->rot.y + 6.0f);
        } else if (out.z > 96.0f && out.z < 150.0f) {
            obj->rot.y = DE_WRAP(obj->rot.y + 6.0f);
        } else if (out.z > 210.0f && out.z < 264.0f) {
            obj->rot.y = DE_WRAP(obj->rot.y - 6.0f);
        }
    }
}

void func_80104D84_256004_DriversEd(omObjData* obj) {
    DECar* c;
    DEObj* p;
    f32 t;
    f32 u;

    p = &D_80108720_2599A0_DriversEd[0];
    c = &D_80108690_259910_DriversEd;
    if ((f32)ContStkY[gPlayers[obj->work[0]].port] > 20.0f) {
        c->speed = 24.0f;
        if (p->unk_74 == 0) {
            u = HuMathSin(obj->rot.y + 180.0f) * 75.0f * 0.5f;
            t = u + obj->trans.x;
            func_80102D5C_253FDC_DriversEd(obj->work[0], t, obj->trans.y, func_800B7890_B8490(obj->rot.y + 180.0f) * 75.0f * 0.5f + obj->trans.z, 2);
            p->unk_74++;
        } else if (p->unk_74 == 2) {
            p->unk_74 = 0;
        } else {
            p->unk_74++;
        }
        if (c->sndFwd == -1) {
            if (c->sndBack != c->sndFwd) {
                func_80079848_7A448(c->sndBack);
                c->sndBack = -1;
            }
            c->sndFwd = func_80079798_7A398(0x2D5, obj->work[0]);
            c->pitch = 200;
        }
    } else if ((f32)ContStkY[gPlayers[obj->work[0]].port] < -20.0f) {
        c->speed = -24.0f;
        if (p->unk_74 == 0) {
            t = obj->trans.x - HuMathSin(obj->rot.y + 180.0f) * 75.0f * 0.5f;
            func_80102D5C_253FDC_DriversEd(obj->work[0], t, obj->trans.y, obj->trans.z - func_800B7890_B8490(obj->rot.y + 180.0f) * 75.0f * 0.5f, 2);
            p->unk_74++;
        } else if (p->unk_74 == 2) {
            p->unk_74 = 0;
        } else {
            p->unk_74++;
        }
        if (c->sndBack == -1) {
            if (c->sndFwd != c->sndBack) {
                func_80079848_7A448(c->sndFwd);
                c->sndFwd = -1;
            }
            c->sndBack = func_80079798_7A398(0x2D6, obj->work[0]);
            c->pitch = 800;
        }
    } else {
        c->speed = 0.0f;
        p->unk_74 = 0;
        if (c->sndFwd != -1) {
            func_80079848_7A448(c->sndFwd);
            c->sndFwd = -1;
        }
        if (c->sndBack != -1) {
            func_80079848_7A448(c->sndBack);
            c->sndBack = -1;
        }
    }
    obj->trans.y = 0.0f;
}

void func_80105108_256388_DriversEd(omObjData* obj) {
    DECar* c;
    DEObj* p;

    p = &D_80108720_2599A0_DriversEd[0];
    c = &D_80108690_259910_DriversEd;
    switch (D_80108680_259900_DriversEd) {
    case 2:
        if (p->unk_70 == 0) {
            func_80104D84_256004_DriversEd(obj);
            func_80104984_255C04_DriversEd(obj);
        }
        break;
    case 3:
        if (c->speed > 0.0f) {
            c->speed -= 1.0f;
            c->pitch -= 100;
            if (c->sndFwd != -1) {
                func_800796F0_7A2F0(c->sndFwd, c->pitch);
            }
        } else if (c->speed < 0.0f) {
            c->speed += 1.0f;
            c->pitch -= 100;
            if (c->sndBack != -1) {
                func_800796F0_7A2F0(c->sndBack, c->pitch);
            }
        } else {
            c->speed = 0.0f;
            if (c->sndFwd != -1) {
                func_80079848_7A448(c->sndFwd);
                c->sndFwd = -1;
            }
            if (c->sndBack != -1) {
                func_80079848_7A448(c->sndBack);
                c->sndBack = -1;
            }
        }
        break;
    }
    func_801044C4_255744_DriversEd(obj);
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80029714_2A314(obj->model[2], obj->trans.x, obj->trans.y, obj->trans.z);
    func_8002979C_2A39C(obj->model[2], obj->rot.x, obj->rot.y, obj->rot.z);
    func_80029714_2A314(obj->model[1], obj->trans.x, 2.0f, obj->trans.z);
    func_800297E8_2A3E8(obj->model[1], 1.5f, obj->scale.y, 1.5f);
    if (p->unk_70 != 0) {
        p->unk_70--;
    } else {
        p->unk_70 = 0;
    }
    if (D_801086EE_25996E_DriversEd == 0 && (ContBtnTrg[gPlayers[obj->work[0]].port] & 0x2000)) {
        D_801086F8_259978_DriversEd ^= 1;
    }
    if ((s16)D_801086F8_259978_DriversEd == 1) {
        func_800298A4_2A4A4(obj->model[0], 4, 4);
        func_800298A4_2A4A4(obj->model[2], 4, 0);
    } else {
        func_800298A4_2A4A4(obj->model[0], 4, 0);
        func_800298A4_2A4A4(obj->model[2], 4, 4);
    }
}

void func_801053C8_256648_DriversEd(omObjData* obj) {
    s32 c;

    c = gPlayers[obj->work[0]].character;
    obj->model[0] = LoadFormFile(D_80107D70_258FF0_DriversEd[c] | 0x430000, 0x299);
    obj->model[1] = func_80018A30_19630(1, 0x89);
    HmfModelObjAttrSet(obj->model[1], 0x80000000, 0);
    func_80029A8C_2A68C(obj->model[1]);
    func_80029AFC_2A6FC(obj->model[1]);
    func_800B1F50_B2B50(D_800FC834_FD434[obj->model[1]].mtx, 0.0f, 10.0f, 0.0f);
    obj->model[2] = LoadFormFile(D_80107D7C_258FFC_DriversEd[c] | 0x190000, 0x299);
    func_800298A4_2A4A4(obj->model[2], 4, 4);
    switch (D_800FA656) {
    case 0:
        D_801086BC_25993C_DriversEd = 0;
        break;
    case 1:
        D_801086BC_25993C_DriversEd = 1;
        break;
    case 2:
        D_801086BC_25993C_DriversEd = 2;
        break;
    case 3:
        D_801086BC_25993C_DriversEd = 3;
        break;
    default:
        D_801086BC_25993C_DriversEd = 4;
        break;
    }
    obj->trans.x = D_801083C8_259648_DriversEd[D_801086BC_25993C_DriversEd].x;
    obj->trans.y = D_801083C8_259648_DriversEd[D_801086BC_25993C_DriversEd].y;
    obj->trans.z = D_801083C8_259648_DriversEd[D_801086BC_25993C_DriversEd].z;
    obj->rot.y = D_801083C8_259648_DriversEd[D_801086BC_25993C_DriversEd].rot;
    D_801086FC_25997C_DriversEd = obj->trans.x;
    D_80108700_259980_DriversEd = obj->trans.z;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_80029714_2A314(obj->model[2], obj->trans.x, obj->trans.y, obj->trans.z);
    func_8002979C_2A39C(obj->model[2], obj->rot.x, obj->rot.y, obj->rot.z);
    func_80029714_2A314(obj->model[1], obj->trans.x, 2.0f, obj->trans.z);
    func_800297E8_2A3E8(obj->model[1], 1.5f, obj->scale.y, 1.5f);
    obj->func_ptr = func_80105108_256388_DriversEd;
}

void func_80105634_2568B4_DriversEd(void) {
    omObjData* o;
    s16 i;
    u8 player;

    for (i = 0; i < 4; i++) {
        if (gPlayers[i].group == 0) {
            break;
        }
    }
    switch (i) {
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
    default:
        player = 0;
        break;
    }
    o = omAddObj(0x64, 2, 0, -1, func_801053C8_256648_DriversEd);
    o->work[0] = player;
    D_80108720_2599A0_DriversEd[0].obj = o;
}

void func_8010570C_25698C_DriversEd(void) {
    if (D_801086DB_25995B_DriversEd == 2 && D_80108682_259902_DriversEd < 0x709) {
        func_80107118_258398_DriversEd();
    } else {
        func_8010281C_253A9C_DriversEd();
    }
    osViBlack(0);
    omOvlReturnEx(1);
}

void func_80105770_2569F0_DriversEd(omObjData* obj) {
    if (D_801086DB_25995B_DriversEd == 2 && D_80108682_259902_DriversEd < 0x709) {
        func_80107118_258398_DriversEd();
    } else {
        func_8010281C_253A9C_DriversEd();
    }
    if (func_8008F618_90218() == 0) {
        obj->func_ptr = func_8010570C_25698C_DriversEd;
    }
}

void func_801057E8_256A68_DriversEd(omObjData* obj) {
    if (D_801011FC_101DFC == 1) {
        if (D_801086DB_25995B_DriversEd == 2 && D_80108682_259902_DriversEd < 0x709) {
            func_80107118_258398_DriversEd();
        } else {
            func_8010281C_253A9C_DriversEd();
        }
        InitFadeOut(0, 0x14);
        obj->func_ptr = func_80105770_2569F0_DriversEd;
        func_800794A8_7A0A8(40);
        func_80079614_7A214(40);
    }
}

void func_80105880_256B00_DriversEd(void) {
    D_80108680_259900_DriversEd += D_80108681_259901_DriversEd;
    D_80108681_259901_DriversEd = 0;
}

void func_801058A8_256B28_DriversEd(void) {
    DECar* c;
    DEObj* p;
    Vec from;
    Vec to;
    Vec out;
    omObjData* car;
    f32 b;
    f32 a;

    p = &D_80108720_2599A0_DriversEd[0];
    if (p->obj != NULL) {
        car = p->obj;
        c = &D_80108690_259910_DriversEd;
        D_801086AC_25992C_DriversEd = 0;
        D_801086AE_25992E_DriversEd = 0;
        if (car->trans.x > 2440.0f || car->trans.x < -2440.0f) {
            p->unk_86 = 3;
            c->wallX = 1;
        }
        if (car->trans.z < -2020.0f) {
            p->unk_86 = 3;
            c->wallZ = 1;
        } else if (car->trans.z > 2020.0f && car->trans.z < 2160.0f) {
            if (car->trans.x > 380.0f || car->trans.x < -380.0f) {
                p->unk_86 = 3;
                c->wallZ = 1;
            } else {
                from.x = car->trans.x;
                from.y = 0.0f;
                from.z = car->trans.z;
                if (car->trans.x < from.y) {
                    to.x = -380.0f;
                    to.y = from.y;
                } else {
                    to.x = 380.0f;
                    to.y = 0.0f;
                }
                to.z = 2160.0f;
                func_801078D0_258B50_DriversEd(&from, &to, &out);
                b = out.z;
                if (out.x < 140.0f) {
                    a = 180.0f;
                    a = b + a;
                    car->trans.x = HuMathSin(a) * 140.0f + to.x;
                    car->trans.z = func_800B7890_B8490(a) * 140.0f + to.z;
                }
            }
        } else if (car->trans.z > 2160.0f) {
            if (D_801086C0_259940_DriversEd[19] == 0) {
                if (D_801086BD_25993D_DriversEd == 0) {
                    PlaySound(0xD);
                }
                D_801086BD_25993D_DriversEd = 1;
            } else if (D_801086DB_25995B_DriversEd == 0) {
                D_801086DB_25995B_DriversEd = 1;
            }
            if (car->trans.x > 240.0f) {
                car->trans.x = 240.0f;
                p->unk_86 = 3;
            } else if (car->trans.x < -240.0f) {
                car->trans.x = -240.0f;
                p->unk_86 = 3;
            }
            if (car->trans.z > 2740.0f) {
                car->trans.z = 2740.0f;
                p->unk_86 = 3;
            }
        }
    }
}

/* NON_MATCHING: GCC moves the first sensor loop tail out of the loop and folds one reload of the next-sign byte, retail keeps both (logic complete, masked 129 is layout). */
#ifdef NON_MATCHING
void func_80105BE0_256E60_DriversEd(void) {
    DECar* c;
    DEObj* p;
    Vec from;
    Vec to;
    Vec out;
    omObjData* car;
    omObjData* o;
    f32 a;
    s16 i;
    s16 j;
    s16 one;

    p = &D_80108720_2599A0_DriversEd[0];
    if (p->obj != NULL) {
        car = p->obj;
        c = &D_80108690_259910_DriversEd;
        one = 1;
        D_801086A8_259928_DriversEd = 0;
        D_801086AA_25992A_DriversEd = 0;
        for (i = 11; i < 31; i++) {
            if (D_80108720_2599A0_DriversEd[i].obj != NULL) {
                o = D_80108720_2599A0_DriversEd[i].obj;
                from.x = car->trans.x;
                from.y = 0.0f;
                from.z = car->trans.z;
                to.x = HuMathSin(DE_WRAP(o->rot.y + 90.0f)) * 190.0f + o->trans.x;
                to.y = 0.0f;
                to.z = func_800B7890_B8490(DE_WRAP(o->rot.y + 90.0f)) * 190.0f + o->trans.z;
                func_801078D0_258B50_DriversEd(&from, &to, &out);
                if (out.x < 112.5f) {
                    p->unk_86 = 3;
                    c->hitSign = i;
                    c->hitSide = 0;
                }
                from.x = car->trans.x;
                from.y = 0.0f;
                from.z = car->trans.z;
                to.x = HuMathSin(DE_WRAP(o->rot.y + 270.0f)) * 190.0f + o->trans.x;
                to.y = 0.0f;
                to.z = func_800B7890_B8490(DE_WRAP(o->rot.y + 270.0f)) * 190.0f + o->trans.z;
                func_801078D0_258B50_DriversEd(&from, &to, &out);
                if (out.x < 112.5f) {
                    p->unk_86 = 3;
                    c->hitSign = i;
                    c->hitSide = one;
                }
                for (j = 0; j < 8; j++) {
                    if (D_801086C0_259940_DriversEd[i - 11] == 0) {
                        from.x = car->trans.x;
                        from.y = 0.0f;
                        from.z = car->trans.z;
                        to.x = HuMathSin(DE_WRAP(o->rot.y + 90.0f)) * ((f32)j * 15.0f) + o->trans.x;
                        to.y = 0.0f;
                        to.z = func_800B7890_B8490(DE_WRAP(o->rot.y + 90.0f)) * ((f32)j * 15.0f) + o->trans.z;
                        func_801078D0_258B50_DriversEd(&from, &to, &out);
                        if (out.x < 30.0f) {
                            if (D_801086BF_25993F_DriversEd < i) {
                                goto bad;
                            }
                            if (i == D_801086BF_25993F_DriversEd && i != D_801086BE_25993E_DriversEd) {
                                if (DE_WRAP(out.z - o->rot.y) < 90.0f) {
                                    goto good;
                                }
                                if (!(DE_WRAP(out.z - o->rot.y) > 270.0f)) {
                                    goto bad;
                                }
                                goto good;
                            }
                        }
                    }
                }
                for (j = 0; j < 8; j++) {
                    if (D_801086C0_259940_DriversEd[i - 11] == 0) {
                        from.x = car->trans.x;
                        from.y = 0.0f;
                        from.z = car->trans.z;
                        to.x = HuMathSin(DE_WRAP(o->rot.y + 270.0f)) * ((f32)j * 15.0f) + o->trans.x;
                        to.y = 0.0f;
                        to.z = func_800B7890_B8490(DE_WRAP(o->rot.y + 270.0f)) * ((f32)j * 15.0f) + o->trans.z;
                        func_801078D0_258B50_DriversEd(&from, &to, &out);
                        if (out.x < 30.0f) {
                            if (D_801086BF_25993F_DriversEd < i) {
                                goto bad;
                            }
                            if (i == D_801086BF_25993F_DriversEd && i != D_801086BE_25993E_DriversEd) {
                                if (DE_WRAP(out.z - o->rot.y) < 90.0f) {
                                    goto good;
                                }
                                if (DE_WRAP(out.z - o->rot.y) > 270.0f) {
                                good:
                                    if (D_801086BD_25993D_DriversEd == 0 && D_80108682_259902_DriversEd < 0x709) {
                                        D_801086BE_25993E_DriversEd = i;
                                        D_801086BF_25993F_DriversEd++;
                                        D_801086C0_259940_DriversEd[i - 11] = one;
                                        PlaySound(0x4BC);
                                        omVibrate(car->work[0], 2, 3, 10);
                                    }
                                    return;
                                }
                            bad:
                                if (D_801086BD_25993D_DriversEd == 0) {
                                    PlaySound(0xD);
                                }
                                D_801086BD_25993D_DriversEd = one;
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_33_DriversEd/253A80", func_80105BE0_256E60_DriversEd);
#endif

void func_8010644C_2576CC_DriversEd(void) {
    DECar* c;
    DEObj* p;
    Vec from;
    Vec to;
    Vec out;
    omObjData* car;
    omObjData* o;

    p = D_80108720_2599A0_DriversEd;
    if (p->obj != NULL) {
        c = &D_80108690_259910_DriversEd;
        car = p->obj;
        if (D_801086A8_259928_DriversEd != 0) {
            from.x = car->trans.x;
            from.y = 0.0f;
            from.z = car->trans.z;
            o = p[D_801086A8_259928_DriversEd].obj;
            if (D_801086AA_25992A_DriversEd == 0) {
                to.x = HuMathSin(DE_WRAP(o->rot.y + 90.0f)) * 190.0f + o->trans.x;
                to.y = 0.0f;
                to.z = func_800B7890_B8490(DE_WRAP(o->rot.y + 90.0f)) * 190.0f + o->trans.z;
            } else {
                to.x = HuMathSin(DE_WRAP(o->rot.y + 270.0f)) * 190.0f + o->trans.x;
                to.y = 0.0f;
                to.z = func_800B7890_B8490(DE_WRAP(o->rot.y + 270.0f)) * 190.0f + o->trans.z;
            }
            func_801078D0_258B50_DriversEd(&from, &to, &out);
            c->dir = out.z;
            car->trans.x = HuMathSin(c->dir + 180.0f) * 113.25f + to.x;
            car->trans.z = func_800B7890_B8490(c->dir + 180.0f) * 113.25f + to.z;
        }
        if (c->wallX == 1) {
            if (car->trans.x > 0.0f) {
                car->trans.x = 2440.0f;
            } else {
                car->trans.x = -2440.0f;
            }
        }
        if (c->wallZ == 1) {
            if (car->trans.z > 0.0f) {
                car->trans.z = 2020.0f;
            } else {
                car->trans.z = -2020.0f;
            }
        }
    }
}

void func_80106828_257AA8_DriversEd(void) {
    omObjData* car;

    car = D_80108720_2599A0_DriversEd[0].obj;
    if (car != NULL) {
        func_80029714_2A314(car->model[0], car->trans.x, car->trans.y, car->trans.z);
        func_80029714_2A314(car->model[2], car->trans.x, car->trans.y, car->trans.z);
        func_8002979C_2A39C(car->model[2], car->rot.x, car->rot.y, car->rot.z);
        func_80029714_2A314(car->model[1], car->trans.x, 2.0f, car->trans.z);
        func_800297E8_2A3E8(car->model[1], 1.7f, car->scale.y, 1.7f);
        D_80108728_2599A8_DriversEd = car->trans.x;
        D_8010872C_2599AC_DriversEd = car->trans.y;
        D_80108730_2599B0_DriversEd = car->trans.z;
    }
}

void func_801068F4_257B74_DriversEd(s16 course, s16 key) {
    f32 span;
    f32 dx;
    f32 dz;

    Hu3DCamSetPerspective(0, 21.176f, 80.0f, 32000.0f);
    D_800FA610_FB210 = D_80108418_259698_DriversEd[course][key].zoom;
    D_800FD474_FE074.x = 325.06723f;
    D_800FD474_FE074.y = 0.0f;
    D_800FD474_FE074.z = 0.0f;
    if (key == 0) {
        span = D_80108418_259698_DriversEd[course][0].time - 30.0f;
    } else {
        span = D_80108418_259698_DriversEd[course][key].time - D_80108418_259698_DriversEd[course][key - 1].time;
    }
    dx = (D_80108418_259698_DriversEd[course][key + 1].x - D_80108418_259698_DriversEd[course][key].x) / span;
    dz = (D_80108418_259698_DriversEd[course][key + 1].z - D_80108418_259698_DriversEd[course][key].z) / span;
    if (key == 0) {
        D_8010274C_10334C.x = dx * (f32)(D_80108684_259904_DriversEd - 30) + D_80108418_259698_DriversEd[course][0].x;
        D_8010274C_10334C.y = 0.0f;
        D_8010274C_10334C.z = dz * (f32)(D_80108684_259904_DriversEd - 30) + D_80108418_259698_DriversEd[course][0].z;
    } else {
        D_8010274C_10334C.x = D_80108418_259698_DriversEd[course][key].x + dx * ((f32)D_80108684_259904_DriversEd - D_80108418_259698_DriversEd[course][key - 1].time);
        D_8010274C_10334C.y = 0.0f;
        D_8010274C_10334C.z = D_80108418_259698_DriversEd[course][key].z + dz * ((f32)D_80108684_259904_DriversEd - D_80108418_259698_DriversEd[course][key - 1].time);
    }
}

void func_80106B58_257DD8_DriversEd(s16 course) {
    Vec from;
    Vec to;
    Vec out;
    omObjData* car;
    f32 span;
    f32 t;
    f32 z0;
    f32 x0;
    f32 dx;
    f32 dz;
    f32 d;
    f32 e;
    f32 a;

    car = D_80108720_2599A0_DriversEd[0].obj;
    to.x = 1960.8251f;
    to.y = 0.0f;
    to.z = 2018.0901f;
    from.x = 52.649998f;
    from.y = 0.0f;
    from.z = -82.55f;
    func_801078D0_258B50_DriversEd(&from, &to, &out);
    Hu3DCamSetPerspective(0, 21.176f, 80.0f, 8000.0f);
    span = D_80108418_259698_DriversEd[course][3].time;
    a = D_80108418_259698_DriversEd[course][2].time;
    span -= a;
    d = out.x;
    z0 = D_80108418_259698_DriversEd[course][3].zoom;
    d = (d - z0) / span;
    e = (360.0f - out.z - 325.0672187805176) / span;
    t = D_80108684_259904_DriversEd;
    D_800FA610_FB210 = d * (t - a) + z0;
    D_800FD474_FE074.x = e * (t - D_80108418_259698_DriversEd[course][2].time) + 325.0672187805176;
    D_800FD474_FE074.y = 0.0f;
    D_800FD474_FE074.z = 0.0f;
    dx = car->trans.x;
    x0 = D_80108418_259698_DriversEd[course][3].x;
    dx = (dx - x0) / span;
    dz = (car->trans.z - D_80108418_259698_DriversEd[course][3].z) / span;
    D_8010274C_10334C.x = dx * (t - D_80108418_259698_DriversEd[course][2].time) + x0;
    D_8010274C_10334C.y = 0.0f;
    D_8010274C_10334C.z = dz * (t - D_80108418_259698_DriversEd[course][2].time) + D_80108418_259698_DriversEd[course][3].z;
}

void func_80106D4C_257FCC_DriversEd(s16 course, s16 key) {
    Hu3DCamSetPerspective(0, 21.176f, 80.0f, 32000.0f);
    D_800FA610_FB210 = D_80108418_259698_DriversEd[course][key].zoom;
    D_800FD474_FE074.x = 325.06723f;
    D_800FD474_FE074.y = 0.0f;
    D_800FD474_FE074.z = 0.0f;
    D_8010274C_10334C.x = D_80108418_259698_DriversEd[course][key].x;
    D_8010274C_10334C.y = 0.0f;
    D_8010274C_10334C.z = D_80108418_259698_DriversEd[course][key].z;
}

void func_80106E08_258088_DriversEd(void) {
    if (D_801086EE_25996E_DriversEd == 4) {
        if (D_80108684_259904_DriversEd >= 30 && (ContBtn[gPlayers[0].port] & 0x8000)) {
            func_800794A8_7A0A8(120);
            D_80108684_259904_DriversEd = 351;
        }
        if (D_80108684_259904_DriversEd < 31) {
            func_80106D4C_257FCC_DriversEd(D_801086BC_25993C_DriversEd, 0);
        } else if ((f32)D_80108684_259904_DriversEd < D_80108418_259698_DriversEd[D_801086BC_25993C_DriversEd][0].time) {
            func_801068F4_257B74_DriversEd(D_801086BC_25993C_DriversEd, 0);
        } else if ((f32)D_80108684_259904_DriversEd == D_80108418_259698_DriversEd[D_801086BC_25993C_DriversEd][0].time) {
            func_80106D4C_257FCC_DriversEd(D_801086BC_25993C_DriversEd, 1);
        } else if ((f32)D_80108684_259904_DriversEd < D_80108418_259698_DriversEd[D_801086BC_25993C_DriversEd][1].time) {
            func_801068F4_257B74_DriversEd(D_801086BC_25993C_DriversEd, 1);
        } else if ((f32)D_80108684_259904_DriversEd == D_80108418_259698_DriversEd[D_801086BC_25993C_DriversEd][1].time) {
            func_80106D4C_257FCC_DriversEd(D_801086BC_25993C_DriversEd, 2);
        } else if ((f32)D_80108684_259904_DriversEd < D_80108418_259698_DriversEd[D_801086BC_25993C_DriversEd][2].time) {
            func_801068F4_257B74_DriversEd(D_801086BC_25993C_DriversEd, 2);
        } else if ((f32)D_80108684_259904_DriversEd == D_80108418_259698_DriversEd[D_801086BC_25993C_DriversEd][2].time) {
            func_80106D4C_257FCC_DriversEd(D_801086BC_25993C_DriversEd, 3);
        } else if ((f32)D_80108684_259904_DriversEd < D_80108418_259698_DriversEd[D_801086BC_25993C_DriversEd][3].time) {
            func_80106B58_257DD8_DriversEd(D_801086BC_25993C_DriversEd);
        } else if ((f32)D_80108684_259904_DriversEd >= D_80108418_259698_DriversEd[D_801086BC_25993C_DriversEd][3].time) {
            func_8010281C_253A9C_DriversEd();
            D_801086EE_25996E_DriversEd = 0;
            func_800794A8_7A0A8(120);
        }
        D_80108684_259904_DriversEd++;
        return;
    }
    func_8010281C_253A9C_DriversEd();
}

void func_80107118_258398_DriversEd(void) {
    Vec from;
    Vec to;
    Vec out;
    omObjData* car;
    f32 t;
    f32 d;

    car = D_80108720_2599A0_DriversEd[0].obj;
    if (D_80108686_259906_DriversEd < 60) {
        to.x = 1960.8251f;
        to.y = 0.0f;
        to.z = 2018.0901f;
        from.x = 52.649998f;
        from.y = 0.0f;
        from.z = -82.55f;
        func_801078D0_258B50_DriversEd(&from, &to, &out);
        Hu3DCamSetPerspective(0, 21.176f, 80.0f, 8000.0f);
        d = (1000.0f - out.x) / 60.0f;
        t = D_80108686_259906_DriversEd;
        D_800FA610_FB210 = d * t + out.x;
        D_800FD474_FE074.x = 360.0 - out.z;
        D_800FD474_FE074.y = 0.0f;
        D_800FD474_FE074.z = 0.0f;
        D_8010274C_10334C.x = car->trans.x;
        D_8010274C_10334C.y = 0.0f;
        D_8010274C_10334C.z = t * -1.5f + car->trans.z;
    } else {
        func_8010281C_253A9C_DriversEd();
        D_800FA610_FB210 = 1000.0f;
        D_8010274C_10334C.z = car->trans.z - 90.0f;
    }
    D_80108686_259906_DriversEd++;
}

void func_801072B8_258538_DriversEd(omObjData* obj) {
    func_80105880_256B00_DriversEd();
    if (D_80108680_259900_DriversEd == 5) {
        if (D_801086DB_25995B_DriversEd == 2 && D_80108682_259902_DriversEd < 0x709) {
            func_80107118_258398_DriversEd();
        } else {
            func_8010281C_253A9C_DriversEd();
        }
        InitFadeOut(0, 0x14);
        obj->func_ptr = func_80105770_2569F0_DriversEd;
        return;
    }
    func_801058A8_256B28_DriversEd();
    func_80105BE0_256E60_DriversEd();
    func_8010644C_2576CC_DriversEd();
    func_80106828_257AA8_DriversEd();
    switch (D_80108680_259900_DriversEd) {
    case 0:
        func_80106E08_258088_DriversEd();
        break;
    case 3:
    case 4:
    case 5:
        if (D_801086BD_25993D_DriversEd != 1 && D_801086DB_25995B_DriversEd == 2 && D_80108682_259902_DriversEd < 0x709) {
            func_80107118_258398_DriversEd();
            break;
        }
    default:
        func_8010281C_253A9C_DriversEd();
        break;
    }
}

void func_801073EC_25866C_DriversEd(void) {
    s16 i;

    D_801086F0_259970_DriversEd = 0;
    D_801086F4_259974_DriversEd = 0;
    D_80108704_259984_DriversEd = 0;
    D_801086BD_25993D_DriversEd = 0;
    D_801086BE_25993E_DriversEd = 0;
    D_801086BF_25993F_DriversEd = 11;
    D_801086DB_25995B_DriversEd = 0;
    D_801086F8_259978_DriversEd = 0;
    for (i = 0; i < 20; i++) {
        D_801086C0_259940_DriversEd[i] = 0;
    }
    D_80108682_259902_DriversEd = 0;
    D_80108684_259904_DriversEd = 0;
    D_80108686_259906_DriversEd = 0;
    D_80108681_259901_DriversEd = 0;
    for (i = 0; i < 6; i++) {
        D_801086D5_259955_DriversEd[i] = 0;
    }
    D_80108690_259910_DriversEd.dir = 0.0f;
    D_80108690_259910_DriversEd.unk_04 = 0;
    D_80108690_259910_DriversEd.steer = 0.0f;
    D_80108690_259910_DriversEd.speed = 0.0f;
    D_80108690_259910_DriversEd.bounce = 0.0f;
    D_80108690_259910_DriversEd.unk_14 = 0;
    D_80108690_259910_DriversEd.unk_20 = 0;
    D_80108690_259910_DriversEd.unk_22 = 0;
    D_80108690_259910_DriversEd.sndFwd = -1;
    D_80108690_259910_DriversEd.sndBack = -1;
    D_80108690_259910_DriversEd.pitch = -1;
    for (i = 0; i < 4; i++) {
        (&D_80108690_259910_DriversEd.hitSign)[i] = 0;
    }
}

void func_80107530_2587B0_DriversEd(omObjData* obj) {
    func_80107C50_258ED0_DriversEd();
    func_80107D44_258FC4_DriversEd();
    func_801073EC_25866C_DriversEd();
    func_80102A90_253D10_DriversEd();
    func_80102D20_253FA0_DriversEd();
    func_80105634_2568B4_DriversEd();
    func_80103894_254B14_DriversEd();
    func_80103258_2544D8_DriversEd();
    InitFadeIn(0, 0x10);
    obj->func_ptr = func_801072B8_258538_DriversEd;
    omAddObj(0xC8, 0, 0, -1, func_8010291C_253B9C_DriversEd);
    D_80108680_259900_DriversEd = 0;
    func_80104038_2552B8_DriversEd();
    omAddObj(0x258, 0, 0, -1, func_8010443C_2556BC_DriversEd);
}

__asm__(".section .rodata");
const char D_80108650_2598D0_DriversEd[] = "\202`\202a\202b";

void func_801075F0_258870_DriversEd(void) {
    s32 c;
    u8 cam;

    func_8002D4D0_2E0D0(0xA);
    func_80020D20_21920(0x50);
    omInitObjMan(0xA0, 0);
    func_80079128_79D28();
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_80079E60_7AA60), 0xA0);
    func_80018E30_19A30(1);
    c = func_80018E78_19A78();
    cam = c;
    ScissorSet(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(c, 21.176f, 80.0f, 8000.0f);
    D_800FA606_FB206 = 0;
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    omAddObj(0x3E8, 0, 0, -1, func_80107530_2587B0_DriversEd);
    omAddObj(0x3E8, 0, 0, -1, func_801057E8_256A68_DriversEd);
    func_8007273C_7333C((u8*)D_80108650_2598D0_DriversEd, 0);
    func_8007273C_7333C((u8*)D_80108650_2598D0_DriversEd, 1);
}

f32 func_80107780_258A00_DriversEd(f32 x) {
    f32 a;
    f32 b;
    f32 sum;
    s32 sign;
    s32 i;

    sign = 1;
    if (x > 1.0f) {
        x = 1.0f / x;
    } else {
        sign = -1;
        if (x < -1.0f) {
            x = 1.0f / x;
        } else {
            sign = 0;
        }
    }
    sum = 0.0f;
    i = 6;
    do {
        a = (f32)(i * i) * x * x;
        b = (f32)(i * 2 + 1) + sum;
        i--;
        sum = a / b;
    } while (i > 0);
    if (sum != -1.0f) {
        if (sign > 0) {
            return 1.5707963267948966 - (x / (sum + 1.0f));
        }
        if (sign < 0) {
            return -1.5707963267948966 - (x / (sum + 1.0f));
        }
        return x / (sum + 1.0f);
    }
    return 0.0f;
}

/* NON_MATCHING: the 180.0f load sits before the FP compare where retail has it after (two nops, masked 3). */
#ifdef NON_MATCHING
void func_801078D0_258B50_DriversEd(Vec* from, Vec* to, Vec* out) {
    Vec delta;
    Vec fromV;
    Vec toV;
    f32 horizontal;
    f32 pitch;
    f32 yaw;
    f32 y;
    f32 eps;
    s32 nearPositive;
    s32 nearNegative;

    fromV.x = from->x;
    fromV.y = from->y;
    fromV.z = from->z;
    toV.x = to->x;
    toV.y = to->y;
    toV.z = to->z;
    delta.x = toV.x - fromV.x;
    delta.y = toV.y - fromV.y;
    delta.z = toV.z - fromV.z;
    horizontal = func_800B1830_B2430(delta.x * delta.x + delta.z * delta.z);
    nearPositive = horizontal <= 0.002f;
    nearNegative = horizontal >= -0.002f;
    if (nearPositive & nearNegative) {
        horizontal = 0.0f;
        y = delta.y;
        eps = 0.0001f;
        pitch = 180.0f;
        yaw = horizontal;
        if (!(y > eps) && y < eps) {
            pitch = horizontal;
        }
    } else {
        if (delta.x != 0.0f && delta.z != 0.0f) {
            yaw = func_80107780_258A00_DriversEd(delta.x / delta.z) * 57.29577951308232;
        } else if (delta.z == 0.0f) {
            if (delta.x >= 0.0f) {
                yaw = 90.0f;
            } else {
                yaw = 270.0f;
            }
        } else {
            yaw = 0.0f;
        }
        if (delta.z < 0.0f) {
            yaw -= 180.0f;
        }
        if (horizontal != 0.0f && delta.y != 0.0f) {
            pitch = func_80107780_258A00_DriversEd(delta.y / horizontal) * 57.29577951308232;
        } else {
            pitch = 0.0f;
        }
        yaw = yaw >= 360.0f ? yaw - 360.0f : yaw < 0.0f ? yaw + 360.0f : yaw;
        pitch = pitch + 90.0f >= 360.0f ? pitch + 90.0f - 360.0f : pitch + 90.0f < 0.0f ? pitch + 90.0f + 360.0f : pitch + 90.0f;
    }
    nearPositive = pitch <= 0.002f;
    nearNegative = pitch >= -0.002f;
    if (nearPositive & nearNegative) {
        pitch = 0.0f;
    }
    horizontal = func_800B1830_B2430(delta.y * delta.y + horizontal * horizontal);
    out->z = yaw;
    out->x = horizontal;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_33_DriversEd/253A80", func_801078D0_258B50_DriversEd);
#endif
