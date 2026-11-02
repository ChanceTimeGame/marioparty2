#include "ovl_22.h"

void func_801091E0_1DD8C0_ShellShocked(omObjData* obj) {
    obj->func_ptr = func_8010281C_1D6EFC_ShellShocked;
}

void func_801091F0_1DD8D0_ShellShocked(omObjData* obj) {
    s32 v;
    s32 i;
    s32 j;
    s32 chr;
    SSShell* s;
    s16 m;
    s32 k;

    obj->func_ptr = func_8010281C_1D6EFC_ShellShocked;
    v = D_800FA656;
    if (v >= 3) {
        v = 2;
    }
    if (func_80103938_1D8018_ShellShocked() != 0) {
        v = 2;
        D_8010DFDC_1E26BC_ShellShocked = v;
        D_8010DFE0_1E26C0_ShellShocked = &D_8010CEFC_1E15DC_ShellShocked[2];
        D_8010DFD4_1E26B4_ShellShocked = &D_8010CE3C_1E151C_ShellShocked[2];
    } else {
        D_8010DFDC_1E26BC_ShellShocked = v;
        D_8010DFE0_1E26C0_ShellShocked = &D_8010CEFC_1E15DC_ShellShocked[v];
        D_8010DFD4_1E26B4_ShellShocked = &D_8010CE3C_1E151C_ShellShocked[v];
    }
    obj->model[0] = LoadFormFile(0x320000, 0x209);
    omSetTra(obj, 0.0f, 0.0f, 0.0f);
    omSetSca(obj, 1.0f, 2.0f, 1.0f);
    omSetRot(obj, 0.0f, 0.0f, 0.0f);
    func_80029714_2A314(obj->model[0], 0.0f, 0.0f, 0.0f);
    func_8002979C_2A39C(obj->model[0], 0.0f, 0.0f, 0.0f);
    func_800297E8_2A3E8(obj->model[0], 1.0f, 1.0f, 1.0f);
    func_800298A4_2A4A4(obj->model[0], 4, 0);
    func_80029EDC_2AADC(obj->model[0], 0xF);
    for (i = 0; i < 4; i++) {
        k = i + 1;
        chr = func_80103950_1D8030_ShellShocked(i);
        obj->model[k] = LoadFormFile(D_8010CC80_1E1360_ShellShocked[chr], 0x299);
        func_80029714_2A314(obj->model[k], 0.0f, 0.0f, 0.0f);
        func_8002979C_2A39C(obj->model[k], 0.0f, 0.0f, 0.0f);
        func_800297E8_2A3E8(obj->model[k], 1.0f, 1.0f, 1.0f);
        func_80029F2C_2AB2C(obj->model[k], 0x800);
        func_800298A4_2A4A4(obj->model[k], 4, 0);
        func_80029EDC_2AADC(obj->model[k], 0xF);
        func_80029FE4_2ABE4(obj->model[k], 0.0f);
        D_8010DA80_1E2160_ShellShocked[i].motBody = func_8002A9F4_2B5F4(obj->model[k], D_8010CCA0_1E1380_ShellShocked[chr].body);
        D_8010DA80_1E2160_ShellShocked[i].motTurret = func_8002A9F4_2B5F4(obj->model[k], D_8010CCA0_1E1380_ShellShocked[chr].turret);
        D_8010DA80_1E2160_ShellShocked[i].motGun = func_8002A9F4_2B5F4(obj->model[k], D_8010CCA0_1E1380_ShellShocked[chr].gun);
        D_8010DA80_1E2160_ShellShocked[i].motA = func_8002A9F4_2B5F4(obj->model[k], D_8010CCA0_1E1380_ShellShocked[chr].motB);
        D_8010DA80_1E2160_ShellShocked[i].motB = func_8002A9F4_2B5F4(obj->model[k], D_8010CCA0_1E1380_ShellShocked[chr].head);
        D_8010DA80_1E2160_ShellShocked[i].motGun->unk34.x = 0.0f;
        D_8010DA80_1E2160_ShellShocked[i].motGun->unk34.y = 0.0f;
        D_8010DA80_1E2160_ShellShocked[i].motGun->unk34.z = 0.0f;
        D_8010DA80_1E2160_ShellShocked[i].recoil = 0.0f;
        for (j = 0; j < 1; j++) {
            s = &D_8010DA80_1E2160_ShellShocked[i].shell[j];
            HuVecCopyXYZ(&s->pos, 0.0f, 0.0f, 0.0f);
            HuVecCopyXYZ(&s->vel, 0.0f, 0.0f, 0.0f);
            s->state = 0;
            s->active = 0;
            s->mdl = LoadFormFile(D_8010CD9C_1E147C_ShellShocked[chr], 0x299);
            s->mot = func_8002A9F4_2B5F4(s->mdl, D_8010CCA0_1E1380_ShellShocked[chr].shell);
            func_80029714_2A314(s->mdl, 0.0f, 0.0f, 0.0f);
            func_8002979C_2A39C(s->mdl, 0.0f, 0.0f, 0.0f);
            func_800297E8_2A3E8(s->mdl, 1.0f, 1.0f, 1.0f);
            func_80029F2C_2AB2C(s->mdl, 0x800);
            func_800298A4_2A4A4(s->mdl, 4, 4);
            func_80029EDC_2AADC(s->mdl, 0xF);
            s->blast = LoadFormFile(0x32000B, 0x299);
            func_80029714_2A314(s->blast, 0.0f, 100.0f, 0.0f);
            func_8002979C_2A39C(s->blast, 0.0f, 0.0f, 0.0f);
            func_800297E8_2A3E8(s->blast, 10.0f, 10.0f, 10.0f);
            func_80029F2C_2AB2C(s->blast, 0x800);
            func_800298A4_2A4A4(s->blast, 4, 4);
            func_80029EDC_2AADC(s->blast, 0xF);
        }
        m = func_8001A2F8_1AEF8(0x320014);
        D_8010DA80_1E2160_ShellShocked[i].hudGrp = m;
        D_8010DA80_1E2160_ShellShocked[i].hudSpr = func_8001AAAC_1B6AC(m, 0, 1);
        D_8010DA80_1E2160_ShellShocked[i].hudHold = 0;
        espPosSet(D_8010DA80_1E2160_ShellShocked[i].hudSpr, D_8010CF20_1E1600_ShellShocked[i].x, D_8010CF20_1E1600_ShellShocked[i].y);
        espDispOn(D_8010DA80_1E2160_ShellShocked[i].hudSpr);
        func_8001A854_1B454(D_8010DA80_1E2160_ShellShocked[i].hudSpr, (func_80103950_1D8030_ShellShocked(i) * 4 + 1) & 0xFFFF, 0);
    }
    obj->model[5] = LoadFormFile(D_8010DFE0_1E26C0_ShellShocked->file, 0x299);
    func_80029714_2A314(obj->model[5], 0.0f, 0.0f, 0.0f);
    func_8002979C_2A39C(obj->model[5], 0.0f, 0.0f, 0.0f);
    func_800297E8_2A3E8(obj->model[5], 1.0f, 1.0f, 1.0f);
    func_80029F2C_2AB2C(obj->model[5], 0x400);
    func_800298A4_2A4A4(obj->model[5], 4, 0);
    func_80029EDC_2AADC(obj->model[5], 0xF);
}

__asm__(".section .rodata");
const char D_8010D2A0_1E1980_ShellShocked[] = "143-grid2_1_1_17";

__asm__(".section .rodata");
const char D_8010D2B4_1E1994_ShellShocked[] = "143tank_kuppa-shadow";

__asm__(".section .rodata");
const char D_8010D2CC_1E19AC_ShellShocked[] = "143tank_kuppa-pipe";

__asm__(".section .rodata");
const char D_8010D2E0_1E19C0_ShellShocked[] = "143tank_kuppa-b_tire";

__asm__(".section .rodata");
const char D_8010D2F8_1E19D8_ShellShocked[] = "143tank_kuppa-f_tire";

__asm__(".section .rodata");
const char D_8010D310_1E19F0_ShellShocked[] = "143tank_kuppa-kat";

__asm__(".section .rodata");
const char D_8010D324_1E1A04_ShellShocked[] = "143tank_kuppa-body";

__asm__(".section .rodata");
const char D_8010D338_1E1A18_ShellShocked[] = "143tank_kuppa-horn";

__asm__(".section .rodata");
const char D_8010D34C_1E1A2C_ShellShocked[] = "c005_000-bmerge1";

__asm__(".section .rodata");
const char D_8010D360_1E1A40_ShellShocked[] = "143-grid2_1_1_1_3";

__asm__(".section .rodata");
const char D_8010D374_1E1A54_ShellShocked[] = "143tank-d_head";

__asm__(".section .rodata");
const char D_8010D384_1E1A64_ShellShocked[] = "Luigi1-atama_1";

__asm__(".section .rodata");
const char D_8010D394_1E1A74_ShellShocked[] = "143-grid2_1_1_3_3";

__asm__(".section .rodata");
const char D_8010D3A8_1E1A88_ShellShocked[] = "143tank-w_head";

__asm__(".section .rodata");
const char D_8010D3B8_1E1A98_ShellShocked[] = "c003_000-head_1";

__asm__(".section .rodata");
const char D_8010D3C8_1E1AA8_ShellShocked[] = "143-grid2_1_1_2_3";

__asm__(".section .rodata");
const char D_8010D3DC_1E1ABC_ShellShocked[] = "143tank-y_head";

__asm__(".section .rodata");
const char D_8010D3EC_1E1ACC_ShellShocked[] = "p_head";

__asm__(".section .rodata");
const char D_8010D3F4_1E1AD4_ShellShocked[] = "143-grid2_1_1_4_3";

__asm__(".section .rodata");
const char D_8010D408_1E1AE8_ShellShocked[] = "143tank-p_head";

__asm__(".section .rodata");
const char D_8010D418_1E1AF8_ShellShocked[] = "c001_000-atama_2";

__asm__(".section .rodata");
const char D_8010D42C_1E1B0C_ShellShocked[] = "143-grid2_1_1_23";

__asm__(".section .rodata");
const char D_8010D440_1E1B20_ShellShocked[] = "143tank-l_head";

__asm__(".section .rodata");
const char D_8010D450_1E1B30_ShellShocked[] = "atama_2";

__asm__(".section .rodata");
const char D_8010D458_1E1B38_ShellShocked[] = "143-grid2_1_1_5_3";

__asm__(".section .rodata");
const char D_8010D46C_1E1B4C_ShellShocked[] = "143tank-shadow";

__asm__(".section .rodata");
const char D_8010D47C_1E1B5C_ShellShocked[] = "143tank-bmerge2";

__asm__(".section .rodata");
const char D_8010D48C_1E1B6C_ShellShocked[] = "143tank-obj3_1";

__asm__(".section .rodata");
const char D_8010D49C_1E1B7C_ShellShocked[] = "143tank-obj2_1";

__asm__(".section .rodata");
const char D_8010D4AC_1E1B8C_ShellShocked[] = "143tank-cube8";

__asm__(".section .rodata");
const char D_8010D4BC_1E1B9C_ShellShocked[] = "143tank-bmerge1_3_1";

__asm__(".section .rodata");
const char D_8010D4D0_1E1BB0_ShellShocked[] = "143tank-m_head";

// delay-slot schedule (masked 12, 313 vs 312: where "move a0,i" lands around the shake offsets); call set fixed: A1E4/B0DC take (i, tank)
#ifdef NON_MATCHING
void func_8010991C_1DDFFC_ShellShocked(s32 i) {
    SSTank* tank;
    omObjData* obj;
    s32 mask;
    s32 x;
    s32 y;
    s32 chr;
    s32 hp;
    f32 t;

    tank = &D_8010DA80_1E2160_ShellShocked[i];
    obj = func_80103884_1D7F64_ShellShocked(2);
    switch (D_8010DA80_1E2160_ShellShocked[i].state) {
    case 2:
        if (func_80103898_1D7F78_ShellShocked() == 4) {
            if (tank->cooldown == 0) {
                if (gPlayers[i].flags & 1) {
                    func_80106D84_1DB464_ShellShocked(i);
                } else {
                    func_8010A1E4_1DE8C4_ShellShocked(i, tank);
                }
            } else {
                func_80029FE4_2ABE4(obj->model[i + 1], 0.0f);
                func_8010C66C_1E0D4C_ShellShocked(i);
            }
        }
        break;
    case 3:
        func_8010B0DC_1DF7BC_ShellShocked(i, tank);
        func_80029FE4_2ABE4(obj->model[i + 1], 0.0f);
        func_8010C66C_1E0D4C_ShellShocked(i);
        break;
    case 4:
        func_8010B0E4_1DF7C4_ShellShocked(i);
        func_8010C66C_1E0D4C_ShellShocked(i);
        break;
    case 5:
        func_8010B3EC_1DFACC_ShellShocked(i);
        func_8010C66C_1E0D4C_ShellShocked(i);
        break;
    }
    func_8010B618_1DFCF8_ShellShocked(i);
    if (tank->cooldown > 0) {
        tank->cooldown--;
    } else {
        tank->cooldown = 0;
    }
    if (tank->flash > 0) {
        tank->flash--;
    } else {
        tank->flash = 0;
    }
    if (tank->flash != 0 && func_8010C1F0_1E08D0_ShellShocked(i) == 0) {
        mask = 4;
        if (tank->flash < 0x14) {
            mask = 2;
        }
        if ((mask & tank->flash) || tank->flash < 8) {
            func_800298A4_2A4A4(obj->model[i + 1], 4, 0);
        } else {
            func_800298A4_2A4A4(obj->model[i + 1], 4, 4);
        }
        if (tank->flash >= 0x1F) {
            if (tank->flash & 1) {
                x = -4;
                y = 8;
            } else {
                x = 4;
                y = -8;
            }
        } else {
            x = 0;
            y = 0;
        }
        func_801050D0_1D97B0_ShellShocked(i, x, y);
    }
    if (tank->flash >= 0x1E) {
        t = (tank->flash - 0x1E) * 0.1 - 0.5;
        t = (-t * t + 0.25) * 6.0 + 1.0;
        func_8001A91C_1B51C(D_8010DA80_1E2160_ShellShocked[i].hudSpr, t, t);
        if (tank->flash == 0x1E && func_8010C1F0_1E08D0_ShellShocked(i) != 0) {
            espDispOff(D_8010DA80_1E2160_ShellShocked[i].hudSpr);
        }
    }
    if (D_8010DA80_1E2160_ShellShocked[i].hudHold != 0) {
        D_8010DA80_1E2160_ShellShocked[i].hudHold--;
        return;
    }
    chr = func_80103950_1D8030_ShellShocked(i);
    hp = func_8010C100_1E07E0_ShellShocked(i);
    if (hp > 0) {
        func_8001A854_1B454(D_8010DA80_1E2160_ShellShocked[i].hudSpr, (chr * 4 + hp - 1) & 0xFFFF, 0);
        func_8008225C_82E5C(D_8010DA80_1E2160_ShellShocked[i].hudSpr, 0, 1);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_ShellShocked/1DD8C0", func_8010991C_1DDFFC_ShellShocked);
#endif

void func_80109D08_1DE3E8_ShellShocked(void) {
    s32 i;
    s32 place;
    s32* order;
    SSTank* tank;
    s16 m;

    order = func_801039F8_1D80D8_ShellShocked();
    for (i = 0; i < 4; i++) {
        tank = &D_8010DA80_1E2160_ShellShocked[i];
        place = order[i];
        func_800B3170_B3D70(&tank->pos, &D_8010DFD4_1E26B4_ShellShocked->pos[place]);
        HuVecCopyXYZ(&tank->rot, 0.0f, D_8010DFD4_1E26B4_ShellShocked->rot[place], 0.0f);
        HuVecCopyXYZ(&tank->scale, 1.0f, 1.0f, 1.0f);
        tank->chr = func_80103950_1D8030_ShellShocked(i);
        tank->unk_44 = 1.0f;
        tank->unk_48 = 40.0f;
        tank->state = 2;
        tank->unk_50 = 0;
        tank->blowTimer = 0;
        tank->cooldown = 0;
        func_8010C0A0_1E0780_ShellShocked(i, 2);
        m = LoadFormFile(0x32000B, 0x299);
        tank->blow.mdl = m;
        func_80029714_2A314(m, 0.0f, 200.0f, (f32)i * 100.0f);
        func_8002979C_2A39C(m, 0.0f, 0.0f, 0.0f);
        func_800297E8_2A3E8(m, 1.0f, 1.0f, 1.0f);
        func_80029F2C_2AB2C(m, 0x800);
        func_800298A4_2A4A4(m, 4, 4);
        func_80029EDC_2AADC(m, 0xF);
        switch (func_80103998_1D8078_ShellShocked(i)) {
        case 0:
            tank->level = 0;
            break;
        case 2:
            tank->level = 2;
            break;
        case 1:
            tank->level = 1;
            break;
        default:
            tank->level = 3;
            break;
        }
        tank->engineOn = 0;
        tank->sndEnable = 0;
    }
}

void func_80109F4C_1DE62C_ShellShocked(void) {
    omObjData* obj;
    s32 i;
    s32 state;
    s32 j;

    obj = func_80103884_1D7F64_ShellShocked(2);
    func_80105304_1D99E4_ShellShocked();
    func_8010BEB4_1E0594_ShellShocked();
    for (i = 0; i < 4; i++) {
        D_8010DFD8_1E26B8_ShellShocked = i;
        func_8010991C_1DDFFC_ShellShocked(i);
        j = i + 1;
        func_80029714_2A314(obj->model[j], D_8010DA80_1E2160_ShellShocked[i].pos.x, D_8010DA80_1E2160_ShellShocked[i].pos.y, D_8010DA80_1E2160_ShellShocked[i].pos.z);
        func_8002979C_2A39C(obj->model[j], D_8010DA80_1E2160_ShellShocked[i].rot.x, D_8010DA80_1E2160_ShellShocked[i].rot.y, D_8010DA80_1E2160_ShellShocked[i].rot.z);
        func_80029E80_2AA80(obj->model[j], 2, 2);
        state = func_80103898_1D7F78_ShellShocked();
        switch (state) {
        case 4:
        case 5:
        case 6:
        case 7:
            if (D_8010DA80_1E2160_ShellShocked[i].alive != 0) {
                if (func_8010C100_1E07E0_ShellShocked(i) <= 0) {
                    D_8010DA80_1E2160_ShellShocked[i].alive = 0;
                    D_8010DA80_1E2160_ShellShocked[i].state = 4;
                    D_8010DA80_1E2160_ShellShocked[i].blowTimer = 0x1E;
                    func_800298A4_2A4A4(D_8010DA80_1E2160_ShellShocked[i].blow.mdl, 4, 0);
                    func_800B3170_B3D70(&D_8010DA80_1E2160_ShellShocked[i].blow.pos, &D_8010DA80_1E2160_ShellShocked[i].pos);
                    func_8010C66C_1E0D4C_ShellShocked(i);
                    func_8010C5C0_1E0CA0_ShellShocked(i);
                    func_8010C7E4_1E0EC4_ShellShocked(i);
                    func_8010C808_1E0EE8_ShellShocked(i);
                }
            } else {
                func_8010C66C_1E0D4C_ShellShocked(i);
            }
            if (func_80103898_1D7F78_ShellShocked() == 5) {
                func_80029FE4_2ABE4(obj->model[i + 1], 0.0f);
                func_8010C66C_1E0D4C_ShellShocked(i);
            }
            if (func_80103898_1D7F78_ShellShocked() == 6) {
                func_80029FE4_2ABE4(obj->model[i + 1], 0.0f);
                func_8010C66C_1E0D4C_ShellShocked(i);
            }
            break;
        }
    }
}

void func_8010A19C_1DE87C_ShellShocked(omObjData* obj) {
    func_80109D08_1DE3E8_ShellShocked();
    func_80105190_1D9870_ShellShocked();
    D_8010DFD0_1E26B0_ShellShocked = func_8010C000_1E06E0_ShellShocked();
    obj->func_ptr = func_80109F4C_1DE62C_ShellShocked;
}

void func_8010A1E4_1DE8C4_ShellShocked(s32 i, SSTank* tank) {
    s32 port;
    f32 x;
    f32 y;

    port = gPlayers[i].port;
    func_80108190_1DC870_ShellShocked(i);
    if (ContBtnTrg[port] & 0x8000) {
        if (D_8010DA80_1E2160_ShellShocked[i].shell[0].active == 0) {
            func_8010B494_1DFB74_ShellShocked(i, 0);
            omVibrate(i, 0xA, 0, 0xA);
        }
    } else if (ContBtnTrg[port] & 0x4000) {
        func_8010B494_1DFB74_ShellShocked(i, 1);
    }
    x = ContStkX[port];
    y = ContStkY[port];
    if (ContBtn[port] & 0x2000) {
        func_8010A954_1DF034_ShellShocked(i, x, y);
    } else {
        func_8010A368_1DEA48_ShellShocked(i, x, y);
    }
}

// control flow (masked 44, 409 vs 410 instructions)
#ifdef NON_MATCHING
s32 func_8010A368_1DEA48_ShellShocked(s32 i, s16 x, s16 y) {
    Vec p;
    Vec q;
    SSTank* tank;
    omObjData* obj;
    f32 yaw;
    f32 s;
    f32 co;
    f32 k;
    f32 l;
    s32 n;
    s32 speed;

    tank = &D_8010DA80_1E2160_ShellShocked[i];
    func_800B3170_B3D70(&p, &tank->pos);
    yaw = tank->rot.y - (f32)x * 0.05f;
    if (yaw < 0.0f) {
        yaw += 360.0f;
    } else if (yaw > 360.0f) {
        yaw -= 360.0f;
    }
    s = HuMathSin(yaw);
    co = func_800B7890_B8490(yaw);
    k = (f32)y * 0.3f;
    p.x = s * k * 0.25f + p.x;
    p.z = co * k * 0.25f + p.z;
    q.x = s * 100.0f + p.x;
    q.z = co * 100.0f + p.z;
    l = func_800B1830_B2430(x * x + y * y);
    obj = func_80103884_1D7F64_ShellShocked(2);
    speed = l * 500.0f * 0.01f;
    if (func_80103898_1D7F78_ShellShocked() != 4) {
        func_80029FE4_2ABE4(obj->model[i + 1], 0.0f);
        func_8010C66C_1E0D4C_ShellShocked(i);
    } else {
        func_80029FE4_2ABE4(obj->model[i + 1], l * 0.03);
        if ((s16)speed != 0) {
            func_8010C6C4_1E0DA4_ShellShocked(i, (s16)speed);
        } else {
            func_8010C66C_1E0D4C_ShellShocked(i);
        }
    }
    if (y < 0) {
        tank->motTurret->unk34.y = 180.0f;
    } else {
        tank->motTurret->unk34.y = 0.0f;
    }
    if (func_8010C218_1E08F8_ShellShocked(i, &p, yaw) == 0) {
        func_800B3170_B3D70(&tank->pos, &p);
        tank->rot.y = yaw;
        return 4;
    }
    func_800B3170_B3D70(&p, &tank->pos);
    for (n = 1; n < 4; n++) {
        yaw = (tank->rot.y - (f32)x * 0.05f) + (f32)n * 30.0f;
        if (yaw < 0.0f) {
            yaw += 360.0f;
        } else if (yaw > 360.0f) {
            yaw -= 360.0f;
        }
        s = HuMathSin(yaw);
        k = (f32)y * 0.2f;
        co = k * func_800B7890_B8490(yaw);
        p.x += s * k * 0.25f;
        p.z += co * 0.25f;
        q.x = HuMathSin(tank->rot.y) * 100.0f + p.x;
        q.z = func_800B7890_B8490(tank->rot.y) * 100.0f + p.z;
        if (func_8010C218_1E08F8_ShellShocked(i, &p, tank->rot.y) == 0) {
            func_800B3170_B3D70(&tank->pos, &p);
            return 5;
        }
        func_800B3170_B3D70(&p, &tank->pos);
        yaw = (tank->rot.y - (f32)x * 0.05f) - (f32)n * 30.0f;
        if (yaw < 0.0f) {
            yaw += 360.0f;
        } else if (yaw > 360.0f) {
            yaw -= 360.0f;
        }
        s = HuMathSin(yaw);
        k = (f32)y * 0.2f;
        co = k * func_800B7890_B8490(yaw);
        p.x += s * k * 0.25f;
        p.z += co * 0.25f;
        q.x = HuMathSin(tank->rot.y) * 100.0f + p.x;
        q.z = func_800B7890_B8490(tank->rot.y) * 100.0f + p.z;
        if (func_8010C218_1E08F8_ShellShocked(i, &p, tank->rot.y) == 0) {
            func_800B3170_B3D70(&tank->pos, &p);
            return 5;
        }
        func_800B3170_B3D70(&p, &tank->pos);
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_ShellShocked/1DD8C0", func_8010A368_1DEA48_ShellShocked);
#endif


// control flow (masked 131, 491 vs 498 instructions)
#ifdef NON_MATCHING
s32 func_8010A954_1DF034_ShellShocked(s32 i, s16 x, s16 y) {
    Vec p;
    Vec q;
    SSTank* tank;
    omObjData* obj;
    f32 yaw;
    f32 s;
    f32 co;
    f32 fy;
    f32 l;
    f32 fx;
    s32 speed;

    tank = &D_8010DA80_1E2160_ShellShocked[i];
    func_800B3170_B3D70(&p, &tank->pos);
    yaw = tank->rot.y;
    s = HuMathSin(yaw);
    co = func_800B7890_B8490(yaw);
    fy = y;
    p.x += ((f32)-x * co + fy * s) * 0.3f * 0.25f;
    p.z += ((f32)x * s + fy * co) * 0.3f * 0.25f;
    q.x = HuMathSin(yaw) * 100.0f + p.x;
    q.z = func_800B7890_B8490(yaw) * 100.0f + p.z;
    l = func_800B1830_B2430(x * x + y * y);
    obj = func_80103884_1D7F64_ShellShocked(2);
    speed = l * 500.0f * 0.01f;
    if (func_80103898_1D7F78_ShellShocked() != 4) {
        func_80029FE4_2ABE4(obj->model[i + 1], 0.0f);
        func_8010C66C_1E0D4C_ShellShocked(i);
    } else {
        func_80029FE4_2ABE4(obj->model[i + 1], l * 0.03);
        if ((s16)speed != 0) {
            func_8010C6C4_1E0DA4_ShellShocked(i, (s16)speed);
        } else {
            func_8010C66C_1E0D4C_ShellShocked(i);
        }
    }
    if (l < 1.0f) {
        yaw = 0.0f;
    } else {
        fy = y;
        if (fy != 0.0f) {
            fx = x;
            if (fx != 0.0f) {
                yaw = func_800B75A8_B81A8(fy, fx) + 270.0f;
                if (yaw > 360.0f) {
                    yaw -= 360.0f;
                }
                goto done;
            }
        }
        if ((f32)y == 0.0f) {
            yaw = 270.0f;
            if ((f32)x < 0.0f) {
                yaw = 90.0f;
            }
        } else {
            yaw = 0.0f;
            if ((f32)y < 0.0f) {
                yaw = 180.0f;
            }
        }
    }
done:
    tank->motTurret->unk34.y = yaw;
    if (func_8010C218_1E08F8_ShellShocked(i, &p, tank->rot.y) == 0) {
        func_800B3170_B3D70(&tank->pos, &p);
        return 4;
    }
    func_800B3170_B3D70(&p, &tank->pos);
    func_800B1830_B2430(x * x + y * y);
    if (tank->rot.y + 60.0f > 360.0f) {
        yaw = tank->rot.y - 300.0f;
    } else {
        yaw = tank->rot.y + 60.0f;
    }
    s = HuMathSin(yaw);
    co = func_800B7890_B8490(yaw);
    fy = y;
    p.x += ((f32)-x * co + fy * s) * 0.2f * 0.25f;
    p.z += ((f32)x * s + fy * co) * 0.2f * 0.25f;
    q.x = HuMathSin(tank->rot.y) * 100.0f + p.x;
    q.y = 50.0f;
    q.z = func_800B7890_B8490(tank->rot.y) * 100.0f + p.z;
    if (func_8010C218_1E08F8_ShellShocked(i, &p, tank->rot.y) != 0) {
        func_800B3170_B3D70(&p, &tank->pos);
        if (tank->rot.y - 60.0f < 360.0f) {
            yaw = tank->rot.y + 300.0f;
        } else {
            yaw = tank->rot.y - 60.0f;
        }
        s = HuMathSin(yaw);
        co = func_800B7890_B8490(yaw);
        fy = y;
        p.x += ((f32)-x * co + fy * s) * 0.2f * 0.25f;
        p.z += ((f32)x * s + fy * co) * 0.2f * 0.25f;
        q.x = HuMathSin(tank->rot.y) * 100.0f + p.x;
        q.y = 50.0f;
        q.z = func_800B7890_B8490(tank->rot.y) * 100.0f + p.z;
        if (func_8010C218_1E08F8_ShellShocked(i, &p, tank->rot.y) != 0) {
            func_800B3170_B3D70(&p, &tank->pos);
            return 0;
        }
    }
    func_800B3170_B3D70(&tank->pos, &p);
    return 5;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_ShellShocked/1DD8C0", func_8010A954_1DF034_ShellShocked);
__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010D510_1E1BF0_ShellShocked[2] = { 0x3F9EB851, 0xEB851EB8 };
__asm__(".text");
#endif

__asm__(".section .rodata");
/* Unreferenced: file-scope constants, folded into their users (70, 30, 32, 4.8, 0.98, 100, 50, 90, 80). */
const u32 D_8010D518_1E1BF8_ShellShocked[9] = { 0x428C0000, 0x41F00000, 0x42000000, 0x4099999A, 0x3F7AE148, 0x42C80000, 0x42480000, 0x42B40000, 0x42A00000 };
__asm__(".text");

s32 func_8010B08C_1DF76C_ShellShocked(s32 i, s16 x, s16 y) {
    return func_8010A368_1DEA48_ShellShocked(i, x, y);
}

s32 func_8010B0B4_1DF794_ShellShocked(s32 i, s16 x, s16 y) {
    return func_8010A954_1DF034_ShellShocked(i, x, y);
}

void func_8010B0DC_1DF7BC_ShellShocked(s32 i, SSTank* tank) {
}

// control flow (masked 11, 202 vs 201 instructions)
#ifdef NON_MATCHING
void func_8010B0E4_1DF7C4_ShellShocked(s32 i) {
    SSTank* tank;
    HmfMotionObj* m;
    s16 mdl;
    s16 blow;
    f32 t;
    f32 a;

    tank = &D_8010DA80_1E2160_ShellShocked[i];
    mdl = func_80103884_1D7F64_ShellShocked(2)->model[i + 1];
    blow = tank->blow.mdl;
    if (tank->blowTimer != 0) {
        tank->blowTimer--;
        t = (10.0f - (f32)tank->blowTimer) * 0.1f;
        sqrtf(ABS(t));
        func_80029714_2A314(blow, tank->blow.pos.x, tank->blow.pos.y, tank->blow.pos.z);
        func_8002979C_2A39C(blow, 0.0f, 0.0f, 0.0f);
        func_800297E8_2A3E8(blow, 1.0f, 1.0f, 1.0f);
        tank->motA->unk34.x += 40.0f;
        m = tank->motA;
        if (m->unk34.x > 360.0f) {
            m->unk34.x -= 360.0f;
        }
        tank->motA->unk34.y += 70.0f;
        m = tank->motA;
        if (m->unk34.y > 360.0f) {
            m->unk34.y -= 360.0f;
        }
        tank->motA->unk34.z += 11.0f;
        m = tank->motA;
        if (m->unk34.z > 360.0f) {
            m->unk34.z -= 360.0f;
        }
        t = (f32)tank->blowTimer * 0.03f + 0.1f;
        HuVecCopyXYZ(&tank->motB->unk40, t, t, t);
        a = tank->blowTimer;
        tank->motA->unk28.y = (900.0f - a * a) * 0.9f;
    } else {
        tank->blowTimer = 0;
        tank->state = 5;
        func_800297E8_2A3E8(mdl, 1.0f, 1.0f, 1.0f);
        func_800298A4_2A4A4(mdl, 4, 4);
    }
    t = func_80029CE4_2A8E4(blow);
    if (func_80029D0C_2A90C(blow) <= t) {
        func_800298A4_2A4A4(blow, 4, 4);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_ShellShocked/1DD8C0", func_8010B0E4_1DF7C4_ShellShocked);
#endif

void func_8010B3EC_1DFACC_ShellShocked(s32 i) {
    s16 m;
    f32 t;

    m = D_8010DA80_1E2160_ShellShocked[i].blow.mdl;
    t = func_80029CE4_2A8E4(m);
    if (func_80029D0C_2A90C(m) <= t) {
        func_800298A4_2A4A4(m, 4, 4);
    }
    D_8010DA80_1E2160_ShellShocked[i].state = 3;
}

// register allocation (masked 4, 105 vs 105 instructions)
#ifdef NON_MATCHING
void func_8010B494_1DFB74_ShellShocked(s32 i, s32 kind) {
    SSTank* tank;
    SSShell* s;
    f32 a;
    f32 co;
    f32 z;

    tank = &D_8010DA80_1E2160_ShellShocked[i];
    s = tank->shell;
    if (tank->shell[0].active == 0 || ((tank->shell[0].state == 2) & (kind == 0))) {
        a = HuMathSin(tank->rot.y);
        co = func_800B7890_B8490(tank->rot.y);
        s->active = 1;
        if (kind == 0) {
            s->state = 4;
            s->vel.x = a * 70.0f;
            s->vel.y = 0.0f;
            s->vel.z = co * 70.0f;
            z = 0.0f;
            tank->motGun->unk34.x = tank->recoil = z;
            s->pos.x = a * 100.0f + tank->pos.x;
            s->pos.y = tank->pos.y + 50.0f;
            s->pos.z = co * 100.0f + tank->pos.z;
            func_800298A4_2A4A4(s->mdl, 4, 0);
            tank->cooldown = 0xA;
            func_8010C848_1E0F28_ShellShocked(i);
        } else if (kind == 1) {
            z = 0.0f;
            tank->motGun->unk34.x = tank->recoil = z;
            s->state = 2;
            func_8010C86C_1E0F4C_ShellShocked(i);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_ShellShocked/1DD8C0", func_8010B494_1DFB74_ShellShocked);
#endif

void func_8010B618_1DFCF8_ShellShocked(s32 i) {
    SSTank* tank;
    SSShell* s;
    f32 t;
    f32 a;
    f32 b;
    f32 c;
    f32 d;

    tank = &D_8010DA80_1E2160_ShellShocked[i];
    s = tank->shell;
    if (tank->shell[0].state != 2) {
        if (tank->recoil < 0.0f) {
            tank->recoil += 5.0f;
        } else {
            tank->recoil = 0.0f;
        }
        tank->motGun->unk34.x = tank->recoil;
    }
    switch (s->state) {
    case 3:
        s->pos.x += s->vel.x;
        s->pos.y += s->vel.y;
        s->pos.z += s->vel.z;
        s->vel.x *= 0.98f;
        s->vel.y -= 4.8f;
        s->vel.z *= 0.98f;
        if (func_8010BB0C_1E01EC_ShellShocked(i, s) != 0) {
            s->state = 5;
        }
        if (16900.0f < func_8010CA68_1E1148_ShellShocked(&s->pos, &tank->pos)) {
            func_800298A4_2A4A4(s->mdl, 4, 0);
        }
        break;
    case 4:
        s->pos.x += s->vel.x;
        s->pos.z += s->vel.z;
        s->vel.x *= 0.98f;
        s->vel.z *= 0.98f;
        if (func_8010BB0C_1E01EC_ShellShocked(i, s) != 0) {
            s->state = 5;
        }
        if (25600.0f < func_8010CA68_1E1148_ShellShocked(&s->pos, &tank->pos)) {
            func_800298A4_2A4A4(s->mdl, 4, 0);
        }
        break;
    case 5:
        s->state = 6;
        func_800298A4_2A4A4(s->mdl, 4, 4);
        func_800297E8_2A3E8(s->mdl, 1.0f, 1.0f, 1.0f);
        s->timer = 0x14;
        func_800298A4_2A4A4(s->blast, 4, 0);
        func_80029714_2A314(s->blast, s->pos.x, 0.0f, s->pos.z);
        func_8002979C_2A39C(s->blast, 0.0f, 0.0f, 0.0f);
        func_800297E8_2A3E8(s->blast, 1.0f, 1.0f, 1.0f);
        func_8010C890_1E0F70_ShellShocked();
        func_80029FE4_2ABE4(s->blast, 2.5f);
        func_80029C74_2A874(s->blast, 0.0f);
        break;
    case 6:
        t = func_80029CE4_2A8E4(s->blast);
        if (func_80029D0C_2A90C(s->blast) <= t) {
            func_800298A4_2A4A4(s->blast, 4, 4);
            if (s->timer <= 0) {
                s->state = 0;
            }
        }
        if (s->timer > 0) {
            s->timer--;
        }
        break;
    case 0:
        func_800298A4_2A4A4(s->blast, 4, 4);
        func_800297E8_2A3E8(s->blast, 1.0f, 1.0f, 1.0f);
        s->state = 1;
        s->timer = 0;
        s->active = 0;
        break;
    case 2:
        if (tank->recoil > -45.0f) {
            tank->recoil -= 8.0f;
        } else {
            s->state = 3;
            a = HuMathSin(tank->rot.y);
            b = func_800B7890_B8490(tank->rot.y);
            c = (0.5f - func_8010CAA4_1E1184_ShellShocked()) * 0.3f;
            d = (0.5f - func_8010CAA4_1E1184_ShellShocked()) * 2.9999998f;
            s->pos.x = a * 90.0f + tank->pos.x;
            s->pos.y = tank->pos.y + 80.0f;
            s->pos.z = b * 90.0f + tank->pos.z;
            s->vel.x = (c + 30.0f) * a;
            s->vel.y = 32.0f;
            s->vel.z = (d + 30.0f) * b;
            tank->cooldown = 0xA;
            func_8010C848_1E0F28_ShellShocked(i);
            omVibrate(i, 0xA, 0, 0xA);
        }
        break;
    }
    tank->motGun->unk34.x = tank->recoil;
    func_80029714_2A314(s->mdl, s->pos.x, -80.0f, s->pos.z);
    func_80029714_2A314(s->blast, s->pos.x, s->pos.y, s->pos.z);
    s->mot->unk58[3][1] = s->pos.y + 80.0f;
}

s32 func_8010BB0C_1E01EC_ShellShocked(s32 i, SSShell* s) {
    s32 hit;
    s32 j;
    Vec d;
    SSTank* tank;
    Vec* v;
    f32 x;
    f32 z;

    hit = 0;
    for (j = 0; j < 4; j++) {
        if (j != i && func_8010C1F0_1E08D0_ShellShocked(j) == 0) {
            tank = &D_8010DA80_1E2160_ShellShocked[j];
            d.x = tank->pos.x - s->pos.x;
            d.z = tank->pos.z - s->pos.z;
            if ((f64)(d.x * d.x + d.z * d.z) < 3600.0 && s->pos.y < 150.0f) {
                hit = 1;
                if (func_8010C124_1E0804_ShellShocked(j, i) != 0) {
                    omVibrate(j, 0x14, 0, 0x14);
                    D_8010DA80_1E2160_ShellShocked[j].hudHold = 0xA;
                }
            }
        }
    }
    if (hit == 1) {
        return 1;
    }
    for (j = 0; j < D_8010DFE0_1E26C0_ShellShocked->count; j++) {
        v = &D_8010DFE0_1E26C0_ShellShocked->pillars[j];
        d.x = v->x - s->pos.x;
        d.z = v->z - s->pos.z;
        if (d.x * d.x + d.z * d.z < 10000.0f && s->pos.y < 150.0f) {
            return 1;
        }
    }
    if (!(s->pos.x < -780.0f) && !(s->pos.x > 780.0f) && !(s->pos.z < -780.0f) && !(s->pos.z > 780.0f)) {
        goto height;
    }
    if (!(!(s->pos.x > -820.0f) && !(s->pos.x < 820.0f) && !(s->pos.z > -820.0f) && !(s->pos.z < 820.0f)) &&
        s->pos.y < 100.0f) {
        return 1;
    }
    if (s->pos.x < -1000.0f || s->pos.x > 1000.0f || s->pos.z < -1000.0f || s->pos.z > 1000.0f) {
        return 1;
    }
height:
    if (s->pos.y < 16.0f || s->pos.y > 1000.0f) {
        return 1;
    }
    return 0;
}

s32 func_8010BEB4_1E0594_ShellShocked(void) {
    Vec d;
    s32 i;
    s32 j;
    s32 hit;
    SSShell* a;
    SSShell* b;

    hit = 0;
    for (i = 0; i < 4; i++) {
        a = D_8010DA80_1E2160_ShellShocked[i].shell;
        switch (a->state) {
        case 3:
        case 4:
        case 5:
            for (j = 0; j < 4; j++) {
                if (i != j) {
                    b = D_8010DA80_1E2160_ShellShocked[j].shell;
                    switch (b->state) {
                    case 3:
                    case 4:
                    case 5:
                        HuVecSubtract(&d, &a->pos, &b->pos);
                        if (d.x * d.x + d.y * d.y + d.z * d.z < 1600.0f) {
                            b->state = 5;
                            a->state = 5;
                            hit = 1;
                        }
                        break;
                    }
                }
            }
            break;
        }
    }
    return hit;
}

/* How far a lobbed shell flies: the same arc as func_8010B618_1DFCF8_ShellShocked's state 3. */
f32 func_8010C000_1E06E0_ShellShocked(void) {
    Vec a;
    Vec b;

    HuVecCopyXYZ(&b, 30.0f, 32.0f, 0.0f);
    HuVecCopyXYZ(&a, 90.0f, 80.0f, 0.0f);
    while (1) {
        if (a.y < 0.0f) {
            break;
        }
        a.x += b.x;
        a.y += b.y;
        b.x *= 0.98f;
        b.y -= 4.8f;
    }
    return a.x;
}

void func_8010C0A0_1E0780_ShellShocked(s32 i, s32 hp) {
    D_8010DA80_1E2160_ShellShocked[i].hp = hp;
    if (hp < 0) {
        D_8010DA80_1E2160_ShellShocked[i].alive = 0;
    } else {
        D_8010DA80_1E2160_ShellShocked[i].alive = 1;
    }
}

s32 func_8010C100_1E07E0_ShellShocked(s32 i) {
    return D_8010DA80_1E2160_ShellShocked[i].hp;
}

s32 func_8010C124_1E0804_ShellShocked(s32 i, s32 by) {
    SSCom cmd;

    func_80103998_1D8078_ShellShocked(i);
    if (D_8010DA80_1E2160_ShellShocked[i].flash == 0) {
        if (D_8010DA80_1E2160_ShellShocked[i].state == 2) {
            D_8010DA80_1E2160_ShellShocked[i].hp--;
            D_8010DA80_1E2160_ShellShocked[i].flash = 0x28;
            cmd.state = 0xF;
            cmd.target = by;
            cmd.timer = (rand8() & 7) + 0xA;
            func_80107738_1DBE18_ShellShocked(i, 0, &cmd);
        }
        return 1;
    }
    return 0;
}

s32 func_8010C1F0_1E08D0_ShellShocked(s32 i) {
    return D_8010DA80_1E2160_ShellShocked[i].hp < 1;
}

s32 func_8010C218_1E08F8_ShellShocked(s32 i, Vec* pos, f32 angle) {
    SSTank* tank;
    Vec* v;
    s32 j;
    f32 x;
    f32 z;
    f32 hx;
    f32 hz;
    f32 dx;
    f32 dz;
    f32 tx;
    f32 tz;

    x = pos->x;
    z = pos->z;
    hx = x + HuMathSin(angle) * 100.0f;
    hz = z + func_800B7890_B8490(angle) * 100.0f;
    for (j = 0; j < D_8010DFE0_1E26C0_ShellShocked->count; j++) {
        v = &D_8010DFE0_1E26C0_ShellShocked->pillars[j];
        dx = x - v->x;
        dz = z - v->z;
        if (dx * dx + dz * dz < 14400.0f) {
            return 1;
        }
        dx = hx - v->x;
        dz = hz - v->z;
        if (dx * dx + dz * dz < 10000.0f) {
            return 1;
        }
    }
    if ((x < -760.0f) | (x > 760.0f)) {
        return 1;
    }
    if ((z < -760.0f) | (z > 760.0f)) {
        return 1;
    }
    for (j = 0; j < 4; j++) {
        if (i != j && func_8010C1F0_1E08D0_ShellShocked(j) == 0) {
            tank = &D_8010DA80_1E2160_ShellShocked[j];
            dx = tank->pos.x - x;
            dz = tank->pos.z - z;
            if (dx * dx + dz * dz < 10000.0f) {
                return 1;
            }
            dx = hx - tank->pos.x;
            dz = hz - tank->pos.z;
            if (dx * dx + dz * dz < 2500.0f) {
                return 1;
            }
            tx = HuMathSin(tank->rot.y) * 100.0f + tank->pos.x;
            tz = func_800B7890_B8490(tank->rot.y) * 100.0f + tank->pos.z;
            dx = tx - x;
            dz = tz - z;
            if (dx * dx + dz * dz < 2500.0f) {
                return 1;
            }
            dx = tx - hx;
            dz = tz - hz;
            if (dx * dx + dz * dz < 2500.0f) {
                return 1;
            }
        }
    }
    return 0;
}

void func_8010C57C_1E0C5C_ShellShocked(void) {
    SSTank* tank;
    s32 i;

    for (i = 0; i < 4; i++) {
        tank = &D_8010DA80_1E2160_ShellShocked[i];
        tank->sndEnable = 1;
    }
}

void func_8010C5C0_1E0CA0_ShellShocked(s32 i) {
    SSTank* tank;

    tank = &D_8010DA80_1E2160_ShellShocked[i];
    func_8010C66C_1E0D4C_ShellShocked(i);
    tank->sndEnable = 0;
}

void func_8010C604_1E0CE4_ShellShocked(void) {
    SSTank* tank;
    s32 i;

    for (i = 0; i < 4; i++) {
        tank = &D_8010DA80_1E2160_ShellShocked[i];
        func_8010C66C_1E0D4C_ShellShocked(i);
        tank->sndEnable = 0;
    }
}

void func_8010C66C_1E0D4C_ShellShocked(s32 i) {
    SSTank* tank;

    tank = &D_8010DA80_1E2160_ShellShocked[i];
    if (tank->engineOn != 0 && tank->sndEnable != 0) {
        tank->engineOn = 0;
        func_80079848_7A448((s16)tank->engineSe);
    }
}

void func_8010C6C4_1E0DA4_ShellShocked(s32 i, s32 speed) {
    SSTank* tank;

    tank = &D_8010DA80_1E2160_ShellShocked[i];
    if (func_80103898_1D7F78_ShellShocked() != 4) {
        func_8010C66C_1E0D4C_ShellShocked(i);
        return;
    }
    if (tank->engineOn != 0 && tank->sndEnable != 0) {
        if (speed > 500) {
            speed = 500;
        } else if (speed < 0) {
            speed = 0;
        }
        func_800796F0_7A2F0((s16)tank->engineSe, speed);
    } else {
        tank->engineOn = 1;
        tank->engineSe = func_80079798_7A398(0x257, i);
        func_800796F0_7A2F0((s16)tank->engineSe, 0);
    }
}

void func_8010C7AC_1E0E8C_ShellShocked(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_8010C66C_1E0D4C_ShellShocked(i);
    }
}

void func_8010C7E4_1E0EC4_ShellShocked(s32 i) {
    func_80079798_7A398(0x258, i);
}

void func_8010C808_1E0EE8_ShellShocked(s32 i) {
    if (func_80103938_1D8018_ShellShocked() == 0 || i == 0) {
        func_800797DC_7A3DC(0x111, i);
    }
}

void func_8010C848_1E0F28_ShellShocked(s32 i) {
    func_80079798_7A398(0x255, i);
}

void func_8010C86C_1E0F4C_ShellShocked(s32 i) {
    func_80079798_7A398(0x259, i);
}

void func_8010C890_1E0F70_ShellShocked(void) {
    PlaySound(0x256);
}

// register allocation: b->x/b->z float registers (masked 2)
#ifdef NON_MATCHING
s32 func_8010C8AC_1E0F8C_ShellShocked(Vec* a, Vec* b, f32* m) {
    Vec q;
    Vec p;
    f32 dot;
    f32 len;
    f32 k;
    f32 c;
    f32 s;

    dot = a->x * b->x + a->z * b->z;
    len = b->x * b->x + b->z * b->z;
    if (len == 0.0f) {
        if (b->z * a->x - b->x * a->z < 0.0f) {
            c = -1.0f;
        } else {
            c = 1.0f;
        }
        m[10] = c;
        m[0] = c;
        m[8] = m[2] = 0.0f;
        return 1;
    }
    k = dot / len;
    p.x = k * b->x;
    p.z = k * b->z;
    q.x = a->x - p.x;
    q.z = a->z - p.z;
    s = func_800B1830_B2430(q.x * q.x + q.z * q.z);
    if (b->z * a->x - b->x * a->z < 0.0f) {
        s = -s;
    }
    m[10] = dot;
    m[0] = dot;
    m[8] = s;
    m[2] = -s;
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_ShellShocked/1DD8C0", func_8010C8AC_1E0F8C_ShellShocked);
#endif

// register allocation (masked 2)
#ifdef NON_MATCHING
void func_8010CA20_1E1100_ShellShocked(Vec* a, Vec* b, Vec* out) {
    f32 ax;
    f32 bx;
    f32 az;
    f32 k;

    ax = a->x;
    bx = b->x;
    az = a->z;
    k = (ax * bx + az * b->z) / (ax * ax + az * az);
    out->x = k * bx;
    out->z = k * b->z;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_22_ShellShocked/1DD8C0", func_8010CA20_1E1100_ShellShocked);
#endif

f32 func_8010CA68_1E1148_ShellShocked(Vec* a, Vec* b) {
    Vec d;

    d.x = b->x - a->x;
    d.z = b->z - a->z;
    return d.x * d.x + d.z * d.z;
}

f32 func_8010CAA4_1E1184_ShellShocked(void) {
    return rand8() * 0.00390625f;
}

__asm__(".section .rodata\n\t.balign 16\n\t.text");

/* .data (1E1360-1E1630, 8010CC80-8010CF50) */
s32 D_8010CC80_1E1360_ShellShocked[8] = { 0x00320005, 0x00320006, 0x00320007, 0x00320008, 0x00320009, 0x0032000A, 0x00320012, 0xFFFFFFFF };
SSChrParts D_8010CCA0_1E1380_ShellShocked[7] = {
    { (char*)D_8010D4D0_1E1BB0_ShellShocked, (char*)D_8010D4BC_1E1B9C_ShellShocked, (char*)D_8010D4AC_1E1B8C_ShellShocked, { (char*)D_8010D49C_1E1B7C_ShellShocked, (char*)D_8010D48C_1E1B6C_ShellShocked }, (char*)D_8010D47C_1E1B5C_ShellShocked, (char*)D_8010D46C_1E1B4C_ShellShocked, (char*)D_8010D458_1E1B38_ShellShocked, (char*)D_8010D450_1E1B30_ShellShocked },
    { (char*)D_8010D440_1E1B20_ShellShocked, (char*)D_8010D4BC_1E1B9C_ShellShocked, (char*)D_8010D4AC_1E1B8C_ShellShocked, { (char*)D_8010D49C_1E1B7C_ShellShocked, (char*)D_8010D48C_1E1B6C_ShellShocked }, (char*)D_8010D47C_1E1B5C_ShellShocked, (char*)D_8010D46C_1E1B4C_ShellShocked, (char*)D_8010D42C_1E1B0C_ShellShocked, (char*)D_8010D418_1E1AF8_ShellShocked },
    { (char*)D_8010D408_1E1AE8_ShellShocked, (char*)D_8010D4BC_1E1B9C_ShellShocked, (char*)D_8010D4AC_1E1B8C_ShellShocked, { (char*)D_8010D49C_1E1B7C_ShellShocked, (char*)D_8010D48C_1E1B6C_ShellShocked }, (char*)D_8010D47C_1E1B5C_ShellShocked, (char*)D_8010D46C_1E1B4C_ShellShocked, (char*)D_8010D3F4_1E1AD4_ShellShocked, (char*)D_8010D3EC_1E1ACC_ShellShocked },
    { (char*)D_8010D3DC_1E1ABC_ShellShocked, (char*)D_8010D4BC_1E1B9C_ShellShocked, (char*)D_8010D4AC_1E1B8C_ShellShocked, { (char*)D_8010D49C_1E1B7C_ShellShocked, (char*)D_8010D48C_1E1B6C_ShellShocked }, (char*)D_8010D47C_1E1B5C_ShellShocked, (char*)D_8010D46C_1E1B4C_ShellShocked, (char*)D_8010D3C8_1E1AA8_ShellShocked, (char*)D_8010D3B8_1E1A98_ShellShocked },
    { (char*)D_8010D3A8_1E1A88_ShellShocked, (char*)D_8010D4BC_1E1B9C_ShellShocked, (char*)D_8010D4AC_1E1B8C_ShellShocked, { (char*)D_8010D49C_1E1B7C_ShellShocked, (char*)D_8010D48C_1E1B6C_ShellShocked }, (char*)D_8010D47C_1E1B5C_ShellShocked, (char*)D_8010D46C_1E1B4C_ShellShocked, (char*)D_8010D394_1E1A74_ShellShocked, (char*)D_8010D384_1E1A64_ShellShocked },
    { (char*)D_8010D374_1E1A54_ShellShocked, (char*)D_8010D4BC_1E1B9C_ShellShocked, (char*)D_8010D4AC_1E1B8C_ShellShocked, { (char*)D_8010D49C_1E1B7C_ShellShocked, (char*)D_8010D48C_1E1B6C_ShellShocked }, (char*)D_8010D47C_1E1B5C_ShellShocked, (char*)D_8010D46C_1E1B4C_ShellShocked, (char*)D_8010D360_1E1A40_ShellShocked, (char*)D_8010D34C_1E1A2C_ShellShocked },
    { (char*)D_8010D338_1E1A18_ShellShocked, (char*)D_8010D324_1E1A04_ShellShocked, (char*)D_8010D310_1E19F0_ShellShocked, { (char*)D_8010D2F8_1E19D8_ShellShocked, (char*)D_8010D2E0_1E19C0_ShellShocked }, (char*)D_8010D2CC_1E19AC_ShellShocked, (char*)D_8010D2B4_1E1994_ShellShocked, (char*)D_8010D2A0_1E1980_ShellShocked, (char*)D_8010D338_1E1A18_ShellShocked },
};
s32 D_8010CD9C_1E147C_ShellShocked[8] = { 0x0032000C, 0x0032000D, 0x0032000E, 0x0032000F, 0x00320010, 0x00320011, 0x00320013, 0x00000000 };
f32 D_8010CDBC_1E149C_ShellShocked[4] = { -135.0f, 135.0f, 45.0f, -45.0f };
Vec D_8010CDCC_1E14AC_ShellShocked[4] = {
    { 600.0f, 0.0f, 600.0f },
    { -600.0f, 0.0f, 600.0f },
    { -600.0f, 0.0f, -600.0f },
    { 600.0f, 0.0f, -600.0f },
};
f32 D_8010CDFC_1E14DC_ShellShocked[4] = { 45.0f, -45.0f, -135.0f, 135.0f };
Vec D_8010CE0C_1E14EC_ShellShocked[4] = {
    { 250.0f, 0.0f, 250.0f },
    { -250.0f, 0.0f, 250.0f },
    { -250.0f, 0.0f, -250.0f },
    { 250.0f, 0.0f, -250.0f },
};
SSStart D_8010CE3C_1E151C_ShellShocked[3] = {
    { D_8010CDFC_1E14DC_ShellShocked, D_8010CE0C_1E14EC_ShellShocked },
    { D_8010CDBC_1E149C_ShellShocked, D_8010CDCC_1E14AC_ShellShocked },
    { D_8010CDBC_1E149C_ShellShocked, D_8010CDCC_1E14AC_ShellShocked },
};
Vec D_8010CE54_1E1534_ShellShocked[9] = {
    { 0.0f, 0.0f, 600.0f },
    { 400.0f, 0.0f, 400.0f },
    { 600.0f, 0.0f, 0.0f },
    { 400.0f, 0.0f, -400.0f },
    { 0.0f, 0.0f, -600.0f },
    { -400.0f, 0.0f, -400.0f },
    { -600.0f, 0.0f, 0.0f },
    { -400.0f, 0.0f, 400.0f },
    { 0.0f, 0.0f, 0.0f },
};
Vec D_8010CEC0_1E15A0_ShellShocked = { 0.0f, 0.0f, 0.0f };
Vec D_8010CECC_1E15AC_ShellShocked[4] = {
    { 0.0f, 0.0f, -600.0f },
    { 0.0f, 0.0f, 600.0f },
    { -600.0f, 0.0f, 0.0f },
    { 600.0f, 0.0f, 0.0f },
};
SSMap D_8010CEFC_1E15DC_ShellShocked[3] = {
    { 0x320002, 1, &D_8010CEC0_1E15A0_ShellShocked },
    { 0x320003, 4, D_8010CECC_1E15AC_ShellShocked },
    { 0x320001, 9, D_8010CE54_1E1534_ShellShocked },
};
Vec D_8010CF20_1E1600_ShellShocked[4] = {
    { 40.0f, 112.0f, 0.0f },
    { 284.0f, 112.0f, 0.0f },
    { 40.0f, 216.0f, 0.0f },
    { 284.0f, 216.0f, 0.0f },
};
