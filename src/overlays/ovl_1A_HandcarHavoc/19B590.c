#include "ovl_1A.h"

__asm__(".section .rodata");
const char D_8010B1F0_1A3F80_HandcarHavoc[] = "\202`\202a\202b";

void func_80102800_19B590_HandcarHavoc(void) {
    omObjData* obj;
    s32 i;

    omInitObjMan(25, 0);
    func_80079128_79D28();
    func_80020D20_21920(16);
    func_8002D4D0_2E0D0(4);
    func_8002F290_2FE90(D_800F9D30_FA930, 64);
    func_80018ED0_19AD0(2);
    func_80018F58_19B58(2);
    for (i = 0; i < 2; i++) {
        D_800F94A8_FA0A8[i] = 1100.0f;
        D_80102770_103370[i].x = -27.0f;
        D_80102770_103370[i].y = 0;
        D_80102770_103370[i].z = 0;
        D_801013B0_101FB0[i].x = 0;
        D_801013B0_101FB0[i].y = 0;
        D_801013B0_101FB0[i].z = 0;
        D_800C9B80_CA780[i].fov[0] = 45.0f;
        Hu3DCamSetPerspective(i, 45.0f, 80.0f, 20000.0f);
    }
    ScissorSet(0, 0.0f, 0.0f, 144.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 320.0f, 480.0f, 511.0f);
    ScissorSet(1, 176.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(1, 640.0f, 480.0f, 511.0f, 960.0f, 480.0f, 511.0f);
    func_80029708_2A308(1);
    func_8002CA48_2D648(200, 255, 255);
    func_8002C59C_2D19C(0x3C0, 0x3E8, 200, 255, 255);
    obj = omAddObj(300, 0, 0, -1, func_801083B4_1A1144_HandcarHavoc);
    omSetStatBit(obj, 0xA0);
    func_801083B4_1A1144_HandcarHavoc(obj);
    func_80026D28_27928(2);
    func_80026DAC_279AC(0, 0, 0, 0);
    func_80026DAC_279AC(1, 0, 0, 0);
    func_80026E00_27A00(1, 42.0f, -107.0f, 32.0f);
    D_8010B368_1A40F8_HandcarHavoc.x = -19;
    D_8010B368_1A40F8_HandcarHavoc.y = -114;
    D_8010B368_1A40F8_HandcarHavoc.z = 31;
    D_8010B374_1A4104_HandcarHavoc = 215;
    func_80026DAC_279AC(2, 209, 207, 206);
    func_80026E00_27A00(2, -67.0f, 37.0f, 91.0f);
    func_80026D50_27950(2, 1, 1);
    D_8010B362_1A40F2_HandcarHavoc = _CheckFlag(0xC);
    func_80076BD0_777D0(0, 2);
    D_8010D820_1A65B0_HandcarHavoc = func_80076D80_77980(0);
    func_80076BD0_777D0(1, 2);
    D_8010D7E0_1A6570_HandcarHavoc = func_80076D80_77980(1);
    omAddObj(100, 7, 15, 0, func_801033B0_19C140_HandcarHavoc);
    omAddObj(100, 7, 15, 0, func_801033EC_19C17C_HandcarHavoc);
    omAddObj(200, 0, 0, 1, func_80109B88_1A2918_HandcarHavoc);
    omAddObj(200, 0, 0, 1, func_80109BA4_1A2934_HandcarHavoc);
    D_8010D830_1A65C0_HandcarHavoc = omAddObj(150, 0, 0, -1, func_8010A870_1A3600_HandcarHavoc);
    D_8010D818_1A65A8_HandcarHavoc[0] = omAddObj(170, 0, 0, -1, func_8010AD1C_1A3AAC_HandcarHavoc);
    D_8010D818_1A65A8_HandcarHavoc[1] = omAddObj(170, 0, 0, -1, func_8010AD1C_1A3AAC_HandcarHavoc);
    D_8010D818_1A65A8_HandcarHavoc[1]->work[0] = 1;
    D_8010D804_1A6594_HandcarHavoc = omAddObj(600, 0, 0, -1, func_80107740_1A04D0_HandcarHavoc);
    omSetStatBit(omAddObj(1000, 0, 0, -1, func_80108360_1A10F0_HandcarHavoc), 0x80);
    omAddObj(0, 0, 0, -1, func_80102E40_19BBD0_HandcarHavoc);
    omSetStatBit(D_8010B3A8_1A4138_HandcarHavoc = omAddObj(50, 9, 0, -1, func_801030F4_19BE84_HandcarHavoc), 0xA0);
    omAddObj(10000, 0, 0, -1, func_8010A7D8_1A3568_HandcarHavoc);
    D_8010D802_1A6592_HandcarHavoc = func_8001A2F8_1AEF8(0x2A0009);
    D_8010D826_1A65B6_HandcarHavoc = func_8001A2F8_1AEF8(0x2A000A);
    D_8010D82A_1A65BA_HandcarHavoc = func_8001A2F8_1AEF8(0x2A0007);
    D_8010D876_1A6606_HandcarHavoc = func_8001A2F8_1AEF8(0x2A0008);
    D_8010D85C_1A65EC_HandcarHavoc = func_8001A2F8_1AEF8(0x43);
    D_8010D7E4_1A6574_HandcarHavoc = func_8001A2F8_1AEF8(0x43);
    D_8010D872_1A6602_HandcarHavoc = func_8001A2F8_1AEF8(0x10016);
    D_8010D874_1A6604_HandcarHavoc = func_8001A2F8_1AEF8(0x10015);
    func_8001A340_1AF40(D_8010D7E4_1A6574_HandcarHavoc, 0.0f, 1.0f, 0.0f);
    D_8010D878_1A6608_HandcarHavoc = func_8001A2F8_1AEF8(0x2A0013);
    D_8010D814_1A65A4_HandcarHavoc = func_8001A2F8_1AEF8(0x2A0011);
    D_8010D82C_1A65BC_HandcarHavoc = func_8001A2F8_1AEF8(0x2A0012);
    func_8007273C_7333C((u8*)D_8010B1F0_1A3F80_HandcarHavoc, 1);
    InitFadeIn(0, 16);
}

void func_80102E40_19BBD0_HandcarHavoc(omObjData* obj) {
    D_8010D800_1A6590_HandcarHavoc = 0;
    D_8010B3B0_1A4140_HandcarHavoc = NULL;
    D_8010B3AC_1A413C_HandcarHavoc = NULL;
    D_8010D870_1A6600_HandcarHavoc = 0;
    D_8010B180_1A3F10_HandcarHavoc = 0;
    D_8010D862_1A65F2_HandcarHavoc = -1;
    D_8010D860_1A65F0_HandcarHavoc = 0;
    D_8010D85E_1A65EE_HandcarHavoc = 0;
    D_8010B364_1A40F4_HandcarHavoc = 30;
    D_8010B366_1A40F6_HandcarHavoc = 300;
    obj->func_ptr = func_80102EAC_19BC3C_HandcarHavoc;
}

void func_80102EAC_19BC3C_HandcarHavoc(omObjData* obj) {
    omObjData* car;
    s32 i;

    switch (D_8010D800_1A6590_HandcarHavoc) {
        case 0:
            if (D_8010B3AC_1A413C_HandcarHavoc == NULL) {
                D_8010B3AC_1A413C_HandcarHavoc = omAddObj(40, 0, 0, -1, func_80106164_19EEF4_HandcarHavoc);
            }
            break;
        case 1:
            for (i = 0; i < 2; i++) {
                if (((HHCar*)D_8010D820_1A65B0_HandcarHavoc[i]->unk_50)->goal == 1) {
                    break;
                }
            }
            if (i != 2) {
                D_8010D800_1A6590_HandcarHavoc = 2;
                D_8010D824_1A65B4_HandcarHavoc = 0;
                D_8010D862_1A65F2_HandcarHavoc = func_80107AB0_1A0840_HandcarHavoc();
                func_801052B8_19E048_HandcarHavoc(D_8010D820_1A65B0_HandcarHavoc[0]);
                func_801052B8_19E048_HandcarHavoc(D_8010D820_1A65B0_HandcarHavoc[1]);
                func_8010A408_1A3198_HandcarHavoc(D_8010D820_1A65B0_HandcarHavoc[D_8010D862_1A65F2_HandcarHavoc]);
            }
            if (--D_8010B364_1A40F4_HandcarHavoc == 0) {
                if (--D_8010B366_1A40F6_HandcarHavoc == 0 && D_8010D800_1A6590_HandcarHavoc == 1) {
                    D_8010D800_1A6590_HandcarHavoc = 2;
                    D_8010D824_1A65B4_HandcarHavoc = 8;
                    func_8006D518_6E118();
                    D_8010B120_1A3EB0_HandcarHavoc = 1;
                    for (i = 0; i < 2; i++) {
                        car = D_8010D820_1A65B0_HandcarHavoc[i];
                        if (!HH_DONE(car)) {
                            func_801052B8_19E048_HandcarHavoc(car);
                        }
                    }
                }
                D_8010B364_1A40F4_HandcarHavoc = 30;
            }
            func_8006D4D0_6E0D0(D_8010B366_1A40F6_HandcarHavoc);
            break;
        case 2:
            if (D_8010B3B0_1A4140_HandcarHavoc == NULL) {
                D_8010B3B0_1A4140_HandcarHavoc = omAddObj(40, 0, 0, -1, func_8010625C_19EFEC_HandcarHavoc);
            }
            break;
    }
}

void func_801030F4_19BE84_HandcarHavoc(omObjData* obj) {
    s32 i;

    obj->model[0] = LoadFormFile(0x2A0000, 0x689);
    func_80029EDC_2AADC(obj->model[0], 1);
    obj->model[1] = func_80027D3C_2893C(obj->model[0]);
    func_80029EDC_2AADC(obj->model[1], 2);
    obj->model[2] = LoadFormFile(0x2A0006, 0x68D);
    func_80029EDC_2AADC(obj->model[2], 1);
    obj->model[3] = func_80027D3C_2893C(obj->model[2]);
    func_80029EDC_2AADC(obj->model[3], 2);
    D_8010B37A_1A410A_HandcarHavoc = LoadFormFile(0x2A0004, 0x80D);
    D_8010B37C_1A410C_HandcarHavoc = LoadFormFile(0x2A0005, 0x80D);
    D_8010B388_1A4118_HandcarHavoc = D_800FC834_FD434[D_8010B37A_1A410A_HandcarHavoc].hmf->unk54;
    D_8010B38C_1A411C_HandcarHavoc = D_800FC834_FD434[D_8010B37C_1A410C_HandcarHavoc].hmf->unk54;
    D_8010B394_1A4124_HandcarHavoc = D_800FC834_FD434[D_8010B37A_1A410A_HandcarHavoc].hmf->unk14;
    D_8010B396_1A4126_HandcarHavoc = D_800FC834_FD434[D_8010B37C_1A410C_HandcarHavoc].hmf->unk14;
    func_801067A0_19F530_HandcarHavoc();
    for (i = 0; i < 2; i++) {
        D_8010B376_1A4106_HandcarHavoc[i] = D_8010B37A_1A410A_HandcarHavoc;
        D_8010B380_1A4110_HandcarHavoc[i] = D_8010B388_1A4118_HandcarHavoc;
        D_8010B390_1A4120_HandcarHavoc[i] = D_8010B394_1A4124_HandcarHavoc;
        D_8010B398_1A4128_HandcarHavoc[i] = D_8010B3A0_1A4130_HandcarHavoc;
    }
    func_801032FC_19C08C_HandcarHavoc();
    D_8010B370_1A4100_HandcarHavoc = 0;
    omSetObjPrio(obj, 400);
    obj->func_ptr = func_801032F4_19C084_HandcarHavoc;
}

void func_801032F4_19C084_HandcarHavoc(void) {
}

void func_801032FC_19C08C_HandcarHavoc(void) {
    u16 spr;
    s32 i;

    for (i = 0; i < 16; i++) {
        spr = func_8001AAAC_1B6AC(D_8010D82A_1A65BA_HandcarHavoc, 0, 1);
        func_8001A708_1B308(spr, 8);
        espPosSet(spr, 160, i * 16);
        espDispOn(spr);
    }
    spr = func_8001AAAC_1B6AC(D_8010D876_1A6606_HandcarHavoc, 0, 1);
    func_8001A708_1B308(spr, 8);
    espPosSet(spr, 160, 24);
    espDispOn(spr);
}

void func_801033B0_19C140_HandcarHavoc(omObjData* obj) {
    func_80103428_19C1B8_HandcarHavoc(obj, 0, 9870.0f, 0, 12375.0f);
}

void func_801033EC_19C17C_HandcarHavoc(omObjData* obj) {
    func_80103428_19C1B8_HandcarHavoc(obj, 1, 9870.0f, 0, 12375.0f);
}

/* Builds a team's car and its two riders (MP1 func_800F7F04). */
// NON_MATCHING: one addu operand order (w->front[seat] in the second seat's branch)
#ifdef NON_MATCHING
void func_80103428_19C1B8_HandcarHavoc(omObjData* obj, u16 team, f32 x, s32 y, f32 z) {
    Vec pos;
    Vec rot;
    HHCar* w;
    u16 seat;
    u16 layer;
    u16 coms;
    s32 dir;
    s32 file;
    u8 chr;
    s32 i;

    seat = 0;
    if (team == 0) {
        layer = 1;
    } else {
        layer = 2;
    }
    w = obj->unk_50 = func_80027154_27D54(sizeof(HHCar), 0x7918);
    w->unk9A = 0x1A7;
    w->team = team;
    w->leanIn = 0;
    w->lean = 0;
    w->tilt = 0;
    w->unk00 = 0;
    w->pump = 0;
    w->seg[1] = 0;
    w->seg[0] = 0;
    w->progress = 0;
    w->goal = 0;
    w->sndOn = 0;
    w->sparkSndOn = 0;
    w->chips[0][0] = 0;
    w->chips[0][1] = 0;
    w->chips[1][0] = 0;
    w->chips[1][1] = 0;
    w->brake = 0;
    w->unk80 = w->tipTimer = w->skidTimer = 0.0f;
    w->cpuStickTime[1] = 0;
    w->cpuStickTime[0] = 0;
    w->cpuStick[1] = 0;
    w->cpuStick[0] = 0;
    w->cpuBrakeTime[1] = 0;
    w->cpuBrakeTime[0] = 0;
    w->cpuDelay[1] = 0;
    w->cpuDelay[0] = 0;
    w->unk9E = 0;
    w->unkEA = 0;
    w->unkEC = 0;
    w->unkEB = 0;
    w->unk98 = 0;
    obj->work[0] = 1;
    obj->work[1] = 0;
    w->unkED = 0;
    w->unkEE = 0;
    w->marker = func_8001AAAC_1B6AC(team == 0 ? D_8010D802_1A6592_HandcarHavoc : D_8010D826_1A65B6_HandcarHavoc, 0, 1);
    func_8001A708_1B308(w->marker, 8);
    espDispOn(w->marker);
    D_80101300_101F00 = 1.3f;
    if (team == 0) {
        obj->model[0] = LoadFormFile(0x2A0002, 0xA99);
        obj->model[1] = LoadFormFile(0x2A0001, 0x20A99);
        obj->model[5] = func_80018A64_19664(0xD, 0xA89);
        obj->model[6] = func_80027D3C_2893C(D_8010D820_1A65B0_HandcarHavoc[0]->model[5]);
        func_80029E80_2AA80(obj->model[0], 1, 1);
        func_80029E80_2AA80(obj->model[1], 1, 1);
        LoadFormFile(0x2A0003, 0x2068D);
        obj->model[2] = LoadFormFile(0x2A0001, 0x20A8D);
        func_8002BB4C_2C74C(obj->model[2], "130mt00_DEF", "130mt04_DEF");
        func_80029A8C_2A68C(obj->model[2]);
        func_80029AFC_2A6FC(obj->model[2]);
    } else {
        obj->model[0] = func_80027D3C_2893C(D_8010D820_1A65B0_HandcarHavoc[0]->model[0]);
        obj->model[1] = func_80027D3C_2893C(D_8010D820_1A65B0_HandcarHavoc[0]->model[1]);
        obj->model[5] = func_80027D3C_2893C(D_8010D820_1A65B0_HandcarHavoc[0]->model[5]);
        obj->model[6] = func_80027D3C_2893C(D_8010D820_1A65B0_HandcarHavoc[0]->model[5]);
        func_80029E80_2AA80(obj->model[0], 1, 1);
        func_80029E80_2AA80(obj->model[1], 1, 1);
        obj->model[2] = func_80027D3C_2893C(D_8010D820_1A65B0_HandcarHavoc[0]->model[2]);
    }
    func_80029E80_2AA80(obj->model[2], 1, 1);
    func_80029EDC_2AADC(obj->model[0], layer);
    func_80029EDC_2AADC(obj->model[1], layer);
    func_80029EDC_2AADC(obj->model[2], layer);
    func_80029EDC_2AADC(obj->model[5], layer);
    func_80029EDC_2AADC(obj->model[6], layer);
    w->speed = 0;
    w->maxSpeed = 203.70369f;
    w->lever1Dir = 0;
    w->leverDir = 0;
    coms = 0;
    if (D_8010B362_1A40F2_HandcarHavoc != 0) {
        for (i = 0; i < 4; i++) {
            if (gPlayers[i].flags & 1) {
                if (gPlayers[i].group == team) {
                    gPlayers[i].cpu_difficulty = 1;
                } else {
                    gPlayers[i].cpu_difficulty = D_800FD8AC[0];
                }
            }
        }
    }
    for (i = 0; i < 4; i++) {
        if (gPlayers[i].group == team) {
            if (gPlayers[i].flags & 1) {
                switch (gPlayers[i].cpu_difficulty) {
                    case 0:
                        w->maxSpeed -= 3.7037037037037037;
                        break;
                    case 1:
                        w->maxSpeed -= 2.7777777777777777;
                        break;
                    case 2:
                        w->maxSpeed -= 1.8518518518518519;
                        break;
                    case 3:
                        w->maxSpeed -= 0.9259259259259259;
                        break;
                }
                coms++;
            }
            w->player[seat] = i;
            chr = gPlayers[i].character;
            dir = D_800CD438_CE038[chr].dir;
            obj->model[3 + seat] = LoadFormFile(dir | D_800CD438_CE038[chr].model, 0xA99);
            func_80018CCC_198CC(obj, seat + 1, dir | 0x15);
            func_80018CCC_198CC(obj, seat + 5, dir);
            func_80018CCC_198CC(obj, seat + 9, dir | 1);
            func_80018CCC_198CC(obj, seat + 7, dir | 4);
            if (rand8() & 1) {
                func_80018CCC_198CC(obj, seat + 11, file = dir | 0x4E);
                w->cheerMot[seat] = file;
            } else {
                func_80018CCC_198CC(obj, seat + 11, file = dir | 0x4F);
                w->cheerMot[seat] = file;
            }
            if (rand8() & 1) {
                func_80018CCC_198CC(obj, seat + 13, file = dir | 0x55);
                w->loseMot[seat] = file;
            } else {
                func_80018CCC_198CC(obj, seat + 13, file = dir | 0x56);
                w->loseMot[seat] = file;
            }
            func_80029B80_2A780(obj->model[3 + seat], obj->motion[1 + seat]);
            func_80029E80_2AA80(obj->model[3 + seat], 1, 1);
            w->face[seat] = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(D_8010B124_1A3EB4_HandcarHavoc[chr]), 0, 1);
            espDispOn(w->face[seat]);
            w->seat[seat] = D_8010B14C_1A3EDC_HandcarHavoc[gPlayers[i].character];
            if (seat == 0) {
                w->front[0] = 1;
                func_8001A708_1B308(w->face[0], 8);
            } else {
                w->front[seat] = 0;
                func_8001A708_1B308(w->face[seat], 8);
                w->seat[seat] = -w->seat[seat];
            }
            func_80029EDC_2AADC(obj->model[3 + seat], layer);
            seat++;
        }
    }
    if (coms < 2) {
        w->maxSpeed = 203.70369f;
        w->cpu = 0;
    } else {
        w->cpu = 1;
    }
    func_801068CC_19F65C_HandcarHavoc(w->team, w->seg[1], &pos);
    omSetTra(obj, pos.x, pos.y, pos.z);
    rot.x = 0;
    rot.y = 90.0f;
    rot.z = 0;
    for (i = 0; i < 2; i++) {
        w->dist[i] = func_80106AD0_19F860_HandcarHavoc(w->team,
                                                       HuMathSin(rot.y) * D_8010B13C_1A3ECC_HandcarHavoc[i] + obj->trans.x,
                                                       obj->trans.y,
                                                       func_800B7890_B8490(rot.y) * D_8010B13C_1A3ECC_HandcarHavoc[i] + obj->trans.z,
                                                       w->seg[i]);
    }
    D_8010B398_1A4128_HandcarHavoc[w->team] -= w->dist[0];
    func_80106CA8_19FA38_HandcarHavoc(obj, &rot, &pos);
    w->prevRot.x = w->rot.x = rot.x;
    w->prevRot.y = w->rot.y = rot.y;
    w->prevRot.z = w->rot.z = rot.z;
    omSetTra(obj, pos.x, pos.y, pos.z);
    func_80104DE0_19DB70_HandcarHavoc(obj);
    w->prevSlope.x = w->slope.x;
    w->prevSlope.y = w->slope.y;
    w->prevSlope.z = w->slope.z;
    func_80108D5C_1A1AEC_HandcarHavoc(obj);
    func_80107634_1A03C4_HandcarHavoc(obj);
    func_80108FBC_1A1D4C_HandcarHavoc(team);
    D_80101300_101F00 = 1.0f;
    obj->func_ptr = func_80103DE4_19CB74_HandcarHavoc;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_80103428_19C1B8_HandcarHavoc);
#endif

void func_80103DE4_19CB74_HandcarHavoc(omObjData* obj) {
    Vec rot;
    Vec pos;
    HHPad pad[2];
    HHCar* w;
    u8* sign;
    f32 wait;
    f32 decel;
    u16 team;
    u16 seg;
    u16 port;
    u16 mode;
    s16 i;

    w = obj->unk_50;
    team = w->team;
    mode = 0;
    if (D_8010D800_1A6590_HandcarHavoc == 0) {
        return;
    }
    if (D_8010D800_1A6590_HandcarHavoc == 1) {
        seg = w->seg[0];
        if (D_8010B376_1A4106_HandcarHavoc[w->team] == D_8010B37A_1A410A_HandcarHavoc) {
            if (seg >= 0x74 && seg < 0x83) {
                mode = 1;
            } else if (seg >= 0xC1 && seg < 0xD0) {
                mode = 2;
            }
        }
        for (i = 0; i < 2; i++) {
            port = gPlayers[w->player[i]].port;
            if (!(gPlayers[w->player[i]].flags & 1)) {
                pad[i].stkX = ContStkX[port];
                pad[i].stkY = ContStkY[port];
                pad[i].trg = ContBtnTrg[port];
                pad[i].btn = ContBtn[port];
            } else {
                func_80107C64_1A09F4_HandcarHavoc(obj, &pad[i], i);
            }
        }
        w->leanIn = 0.0f;
        for (i = 0; i < 2; i++) {
            if ((pad[i].trg & 0x8000) && mode == 0) {
                w->pump += 0.3f;
                if (w->pump > 5.0f) {
                    w->pump = 5.0f;
                }
                w->speed -= 3.7f;
            }
            w->leanIn += func_801051E8_19DF78_HandcarHavoc(pad[i].stkX);
        }
        if (mode == 0) {
            w->speed = -w->slope.y * 5.0f + w->speed;
            decel = 0.2f;
            if (w->speed < 0.0f) {
                w->speed += decel;
                if (w->speed > 0.0f) {
                    w->speed = 0.0f;
                }
            } else {
                w->speed -= decel;
                if (w->speed < 0.0f) {
                    w->speed = 0.0f;
                }
            }
        } else if (mode == 2) {
            w->speed -= D_8010B164_1A3EF4_HandcarHavoc[w->team];
            D_8010B164_1A3EF4_HandcarHavoc[w->team] *= D_8010B164_1A3EF4_HandcarHavoc[w->team];
        }
        w->brake = 0;
        for (i = 0; i < 2; i++) {
            if (pad[i].btn & 0x4000) {
                if (mode == 0 && w->seg[0] != 0x73) {
                    w->speed *= 0.97f;
                }
                w->brake = 1;
            }
        }
    }
    if (w->speed > w->maxSpeed) {
        w->speed = w->maxSpeed;
    }
    if (w->speed < -w->maxSpeed) {
        w->speed = -w->maxSpeed;
    }
    if (w->speed != 0.0f && w->sndOn == 0) {
        w->snd = func_80079798_7A398(team + 0x204, team);
        w->sndOn = 1;
    }
    if (w->sndOn == 1) {
        func_800796F0_7A2F0(w->snd, fabs(w->speed) * 1.9636365175247192);
        if (fabs(w->speed) <= 0.5) {
            func_800796F0_7A2F0(w->snd, 0);
            func_80079848_7A448(w->snd);
            w->sndOn = 0;
        }
    }
    if (func_80106E70_19FC00_HandcarHavoc(obj) == 1 && D_8010D800_1A6590_HandcarHavoc != 2) {
        w->goal = 1;
    }
    func_80106CA8_19FA38_HandcarHavoc(obj, &rot, &pos);
    w->rot.x = rot.x;
    w->rot.y = rot.y;
    w->rot.z = rot.z;
    if (w->rot.x < 0.0f) {
        w->rot.x += 360.0f;
    }
    if (w->rot.x >= 360.0f) {
        w->rot.x -= 360.0f;
    }
    if (w->rot.y < 0.0f) {
        w->rot.y += 360.0f;
    }
    if (w->rot.y >= 360.0f) {
        w->rot.y -= 360.0f;
    }
    if (w->rot.z < 0.0f) {
        w->rot.z += 360.0f;
    }
    if (w->rot.z >= 360.0f) {
        w->rot.z -= 360.0f;
    }
    if (D_8010B376_1A4106_HandcarHavoc[w->team] == D_8010B37A_1A410A_HandcarHavoc) {
        seg = w->seg[0];
        if (seg >= 0x83 && w->unkEB == 0) {
            func_801074A8_1A0238_HandcarHavoc(obj, 0);
            func_801074A8_1A0238_HandcarHavoc(obj, 1);
            PlaySound(w->team + 0x208);
            func_8010B024_1A3DB4_HandcarHavoc(D_8010D818_1A65A8_HandcarHavoc[w->team], 1, 0x2D, 1, 6);
            w->unkEB = 1;
        } else if (seg >= 0xD0 && w->unkEC == 0) {
            func_801074A8_1A0238_HandcarHavoc(obj, 0);
            func_801074A8_1A0238_HandcarHavoc(obj, 1);
            PlaySound(w->team + 0x208);
            w->unkEC = 1;
        }
    }
    if (w->lean > w->leanIn) {
        w->lean -= 2.0f;
        if (w->lean < w->leanIn) {
            w->lean = w->leanIn;
        }
    } else if (w->lean < w->leanIn) {
        w->lean += 2.0f;
        if (w->leanIn < w->lean) {
            w->lean = w->leanIn;
        }
    }
    func_8010484C_19D5DC_HandcarHavoc(obj);
    omSetTra(obj, pos.x, pos.y, pos.z);
    func_80104DE0_19DB70_HandcarHavoc(obj);
    func_80107634_1A03C4_HandcarHavoc(obj);
    func_80108D5C_1A1AEC_HandcarHavoc(obj);
    if (w->pump >= 0.1f) {
        w->pump -= 0.06f;
    } else {
        w->pump = 0.0f;
    }
    for (i = 0; i < 3; i++) {
        (&w->prevSlope.x)[i] = (&w->slope.x)[i];
        (&w->prevRot.x)[i] = (&w->rot.x)[i];
    }
    func_8010986C_1A25FC_HandcarHavoc(w);
    if (w->seg[0] >= 0x6E && w->seg[0] < 0x74) {
        if (func_8010B0FC_1A3E8C_HandcarHavoc(D_8010D818_1A65A8_HandcarHavoc[w->team])) {
            func_8010B024_1A3DB4_HandcarHavoc(D_8010D818_1A65A8_HandcarHavoc[w->team], 0, 2, 6, 6);
        } else {
            func_8010B108_1A3E98_HandcarHavoc(D_8010D818_1A65A8_HandcarHavoc[w->team], 2);
            wait = func_80106AD0_19F860_HandcarHavoc(w->team, obj->trans.x, obj->trans.y, obj->trans.z, 0x73) / 400.0f;
            if (wait < 4.0f) {
                wait = 4.0f;
            }
            if (wait <= ++w->unkEE) {
                w->unkEE = 0;
                w->unkED ^= 1;
                sign = D_8010D818_1A65A8_HandcarHavoc[w->team]->unk_50;
                if (w->unkED == 1) {
                    espDispOff((sign + sign[0])[1]);
                } else {
                    espDispOn((sign + sign[0])[1]);
                }
            }
        }
    }
    if (D_8010B376_1A4106_HandcarHavoc[w->team] == D_8010B37C_1A410C_HandcarHavoc && w->seg[0] >= 0x78 && obj->work[1] == 0) {
        obj->work[1] = 1;
        func_8010B024_1A3DB4_HandcarHavoc(D_8010D818_1A65A8_HandcarHavoc[w->team], 2, 0x2D, 1, 1);
    }
}

void func_8010484C_19D5DC_HandcarHavoc(omObjData* obj) {
    HHCar* w;
    f32 d;

    w = obj->unk_50;
    if (w->tilt != 0.0f) {
        d = w->leanIn * 0.021f;
        if (w->tilt < 0.0f) {
            if (d > 0.0f) {
                w->tilt = d + w->tilt;
                if (w->tilt > 0.0f) {
                    w->tilt = 0.0f;
                }
            }
        } else if (d < 0.0f) {
            w->tilt = d + w->tilt;
            if (w->tilt < 0.0f) {
                w->tilt = 0.0f;
            }
        }
    }
    switch (func_80104C00_19D990_HandcarHavoc(obj)) {
        case 0:
            obj->work[0] &= 0x87;
            if (w->tilt > 0.0f) {
                w->tilt -= 2.0f;
                if (w->tilt < 0.0f) {
                    w->tilt = 0.0f;
                }
            } else {
                w->tilt += 2.0f;
                if (w->tilt > 0.0f) {
                    w->tilt = 0.0f;
                }
            }
            if (w->tipTimer != 0.0f) {
                w->tipTimer -= 1.0f;
            }
            if (w->skidTimer != 0.0f) {
                w->skidTimer -= 1.0f;
            }
            w->unk98 = 0;
            break;
        case 1:
            obj->work[0] |= 8;
            if (fabs(w->tilt) >= 21.0) {
                w->tipTimer += 1.0f;
                w->speed *= 0.5f;
            } else {
                w->tipTimer = 0;
            }
            if (w->unk98 == 0) {
                omVibrate(w->player[0], 3, 4, 7);
                omVibrate(w->player[1], 3, 4, 7);
                w->unk98++;
            } else {
                w->unk98++;
                if (w->unk98 >= 7) {
                    w->unk98 = 0;
                }
            }
            if (obj->work[0] & 0x20) {
                w->tilt += 1.25f;
                if (w->tilt >= 25.0f) {
                    w->tilt = 25.0f;
                }
            } else {
                w->tilt -= 1.25f;
                if (w->tilt <= -25.0f) {
                    w->tilt = -25.0f;
                }
            }
            if (w->tipTimer >= 15.0f) {
                w->tipTimer = 15.0f;
            }
            break;
        case 2:
            w->unk98 = 0;
            obj->work[0] |= 0x10;
            w->skidTimer += 1.0f;
            if (w->skidTimer >= 15.0f) {
                w->skidTimer = 0.0f;
            }
            break;
    }
}

/* 0: straight, 1: too fast into a bend (tipping); sets the lean side flags (MP1 F917C). */
// NON_MATCHING: float register allocation (lean/ad/d; masked 0)
#ifdef NON_MATCHING
u16 func_80104C00_19D990_HandcarHavoc(omObjData* obj) {
    HHCar* w;
    f32 lean;
    f32 ad;
    f32 d;

    w = obj->unk_50;
    if (w->speed == 0.0f) {
        return 0;
    }
    if (w->prevRot.y == w->rot.y) {
        return 0;
    }
    d = w->prevRot.y - w->rot.y;
    if (fabs(d) > 180.0) {
        if (d < 0.0f) {
            d += 360.0f;
        } else {
            d -= 360.0f;
        }
    }
    if (w->speed > 0.0f) {
        d = -d;
    }
    ad = fabsf(d);
    if (ad < 0.7f) {
        return 0;
    }
    if (d > 0.0f) {
        lean = w->lean;
    } else {
        lean = -w->lean;
    }
    if ((ad + lean * 0.55f) * 10.0f + fabs(w->speed) < 101.85184478759766) {
        return 0;
    }
    if (d > 0.0f) {
        func_801074A8_1A0238_HandcarHavoc(obj, 0);
        obj->work[0] = (obj->work[0] | 0x20) & ~0x40;
    } else {
        func_801074A8_1A0238_HandcarHavoc(obj, 1);
        obj->work[0] = (obj->work[0] | 0x40) & ~0x20;
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_80104C00_19D990_HandcarHavoc);
#endif

void func_80104DE0_19DB70_HandcarHavoc(omObjData* obj) {
    Vec seat;
    HHCar* w;
    f32 tx;
    f32 tz;
    f32 lx;
    f32 lz;

    w = obj->unk_50;
    tx = HuMathSin(w->rot.y) * w->tilt;
    tz = func_800B7890_B8490(w->rot.y) * w->tilt;
    lx = HuMathSin(w->rot.y) * w->lean + tx;
    lz = func_800B7890_B8490(w->rot.y) * w->lean + tz;
    omSetTra(obj, obj->trans.x, (f32)(fabs(HuMathSin(w->tilt)) * 75.0) + obj->trans.y, obj->trans.z);
    func_800B2060_B2C60(D_800FC834_FD434[obj->model[0]].mtx, 0.0f, w->rot.y, 0.0f);
    omSetRot(obj, tx + w->rot.x, 0.0f, tz + w->rot.z);
    if (w->brake == 0) {
        func_800298A4_2A4A4(obj->model[2], 4, 4);
        func_800298A4_2A4A4(obj->model[1], 4, 0);
        func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
        func_800B2060_B2C60(D_800FC834_FD434[obj->model[1]].mtx, 0.0f, w->rot.y, 0.0f);
        func_8002979C_2A39C(obj->model[1], lx + w->rot.x, 0.0f, lz + w->rot.z);
    } else {
        func_800298A4_2A4A4(obj->model[2], 4, 0);
        func_800298A4_2A4A4(obj->model[1], 4, 4);
        func_80029714_2A314(obj->model[2], obj->trans.x, obj->trans.y, obj->trans.z);
        func_800B2060_B2C60(D_800FC834_FD434[obj->model[2]].mtx, 0.0f, w->rot.y, 0.0f);
        func_8002979C_2A39C(obj->model[2], lx + w->rot.x, 0.0f, lz + w->rot.z);
    }
    func_80108730_1A14C0_HandcarHavoc(obj, 0, &seat);
    func_80029714_2A314(obj->model[3], seat.x, seat.y, seat.z);
    func_800B2060_B2C60(D_800FC834_FD434[obj->model[3]].mtx, 0.0f, w->rot.y + 180.0f, 0.0f);
    func_8002979C_2A39C(obj->model[3], lx + w->rot.x, 0.0f, lz + w->rot.z);
    func_80029714_2A314(obj->model[5], seat.x, seat.y, seat.z);
    func_8002979C_2A39C(obj->model[5], lx + w->rot.x, 0.0f, lz + w->rot.z);
    func_80108730_1A14C0_HandcarHavoc(obj, 1, &seat);
    func_80029714_2A314(obj->model[4], seat.x, seat.y, seat.z);
    func_800B2060_B2C60(D_800FC834_FD434[obj->model[4]].mtx, 0.0f, w->rot.y, 0.0f);
    func_8002979C_2A39C(obj->model[4], lx + w->rot.x, 0.0f, lz + w->rot.z);
    func_80029714_2A314(obj->model[6], seat.x, seat.y, seat.z);
    func_8002979C_2A39C(obj->model[6], lx + w->rot.x, 0.0f, lz + w->rot.z);
}

/* A rider's stick to a lean input: none, 4.5 or 9 (at 70 and more), against the stick. */
f32 func_801051E8_19DF78_HandcarHavoc(s8 stk) {
    s8 mag = stk;
    f32 dir;

    if (stk < 0.0f) {
        dir = 1.0f;
    } else {
        dir = -1.0f;
    }
    mag = fabs(mag);
    if (mag == 0.0f) {
        dir = dir * 0.0f;
    } else if (mag >= 70) {
        dir = dir * 9.0f;
    } else {
        dir = dir * 4.5f;
    }
    return dir;
}

void func_801052B8_19E048_HandcarHavoc(omObjData* obj) {
    HHCar* w;

    w = obj->unk_50;
    if (!HH_DONE(obj)) {
        if (fabs(w->speed) < 60.0 && w->team == D_8010D862_1A65F2_HandcarHavoc) {
            w->speed = -60.0f;
        }
        w->decel = fabs(w->speed) / 30.0;
        w->stopTimer = 30;
        w->leanIn = 0;
        if (w->team == D_8010D862_1A65F2_HandcarHavoc && w->speed > -46.2963f) {
            w->speed = -46.2963f;
        }
        obj->func_ptr = func_80105394_19E124_HandcarHavoc;
    }
}

void func_80105394_19E124_HandcarHavoc(omObjData* obj) {
    Vec pos;
    Vec rot;
    HHCar* w;
    f32 decel;
    s32 i;

    w = obj->unk_50;
    if (w->speed != 0.0f) {
        if (fabs(w->speed) >= 101.85184478759766) {
            decel = w->decel * 1.9f;
        } else {
            decel = w->decel;
        }
        if (w->speed < 0.0f) {
            w->speed += decel;
            if (w->speed >= 0.0f) {
                w->speed = 0.0f;
            }
        } else {
            w->speed -= decel;
            if (w->speed <= 0.0f) {
                w->speed = 0.0f;
            }
        }
    }
    func_80106E70_19FC00_HandcarHavoc(obj);
    if (w->speed != 0.0f && w->sndOn == 0) {
        w->snd = func_80079798_7A398(w->team + 0x204, w->team);
        w->sndOn = 1;
    }
    if (w->sndOn == 1) {
        func_800796F0_7A2F0(w->snd, fabs(w->speed) * 1.9636365175247192);
        if (fabs(w->speed) <= 0.5) {
            func_800796F0_7A2F0(w->snd, 0);
            func_80079848_7A448(w->snd);
            w->sndOn = 0;
        }
    }
    func_80106CA8_19FA38_HandcarHavoc(obj, &rot, &pos);
    w->rot.x = rot.x;
    w->rot.y = rot.y;
    w->rot.z = rot.z;
    if (w->rot.x < 0.0f) {
        w->rot.x += 360.0f;
    }
    if (w->rot.x >= 360.0f) {
        w->rot.x -= 360.0f;
    }
    if (w->rot.y < 0.0f) {
        w->rot.y += 360.0f;
    }
    if (w->rot.y >= 360.0f) {
        w->rot.y -= 360.0f;
    }
    if (w->rot.z < 0.0f) {
        w->rot.z += 360.0f;
    }
    if (w->rot.z >= 360.0f) {
        w->rot.z -= 360.0f;
    }
    if (w->lean > w->leanIn) {
        w->lean -= 2.0f;
        if (w->lean < w->leanIn) {
            w->lean = w->leanIn;
        }
    } else if (w->lean < w->leanIn) {
        w->lean += 2.0f;
        if (w->leanIn < w->lean) {
            w->lean = w->leanIn;
        }
    }
    if (w->tilt > 0.0f) {
        w->tilt -= 4.0f;
        if (w->tilt < 0.0f) {
            w->tilt = 0.0f;
        }
    } else {
        w->tilt += 4.0f;
        if (w->tilt > 0.0f) {
            w->tilt = 0.0f;
        }
    }
    omSetTra(obj, pos.x, pos.y, pos.z);
    func_80104DE0_19DB70_HandcarHavoc(obj);
    func_8010986C_1A25FC_HandcarHavoc(w);
    func_80107634_1A03C4_HandcarHavoc(obj);
    for (i = 0; i < 3; i++) {
        (&w->prevSlope.x)[i] = (&w->slope.x)[i];
        (&w->prevRot.x)[i] = (&w->rot.x)[i];
    }
    if (--w->stopTimer == 0) {
        w->speed = 0.0f;
        if (w->sndOn == 1) {
            func_800796F0_7A2F0(w->snd, 0);
            func_80079848_7A448(w->snd);
            w->sndOn = 0;
        }
        if (D_8010B362_1A40F2_HandcarHavoc == 0) {
            if (w->team == D_8010D862_1A65F2_HandcarHavoc) {
                for (i = 0; i < 2; i++) {
                    func_80029BF0_2A7F0(obj->model[3 + i], func_80029E14_2AA14(obj->motion[9 + i]), 0, 20, 0);
                    func_80029E80_2AA80(obj->model[3 + i], 3, 2);
                }
                obj->func_ptr = func_80105940_19E6D0_HandcarHavoc;
            } else {
                obj->func_ptr = NULL;
            }
        } else {
            obj->func_ptr = NULL;
            if ((u16)(D_8010D824_1A65B4_HandcarHavoc - 10) >= 2 && D_8010D824_1A65B4_HandcarHavoc != 7) {
                D_8010D824_1A65B4_HandcarHavoc = 2;
            }
        }
    } else if (w->team == D_8010D862_1A65F2_HandcarHavoc && fabs(w->speed) > 60.0) {
        func_801074A8_1A0238_HandcarHavoc(obj, 0);
        func_801074A8_1A0238_HandcarHavoc(obj, 1);
    }
}

/* The winners turn round and jump off the car (their shadows stay on the ground). */
/* NON_MATCHING: the KMC mul fix adds a nop after four calls whose delay slot GCC filled with a
   float op (retail's has none), and case 1 loads seat .y before the model (retail after it). */
#ifdef NON_MATCHING
void func_80105940_19E6D0_HandcarHavoc(omObjData* obj) {
    HHCar* w;
    f32 a;
    s32 i;

    w = obj->unk_50;
    func_8010986C_1A25FC_HandcarHavoc(w);
    switch (D_8010B16C_1A3EFC_HandcarHavoc) {
        case 0:
            a = D_8010B170_1A3F00_HandcarHavoc;
            for (i = 0; i < 2; i++) {
                if (i == 0) {
                    a = -a;
                }
                func_800B2060_B2C60(D_800FC834_FD434[obj->model[3 + i]].mtx, 0.0f, w->rot.y - a, 0.0f);
                if (D_8010B170_1A3F00_HandcarHavoc >= 90.0f) {
                    D_8010B16C_1A3EFC_HandcarHavoc = 1;
                    func_80029B80_2A780(obj->model[3 + i], obj->motion[7 + i]);
                    func_80108730_1A14C0_HandcarHavoc(obj, i, &D_8010B328_1A40B8_HandcarHavoc[i]);
                    D_8010B35C_1A40EC_HandcarHavoc = D_8010B328_1A40B8_HandcarHavoc[0].y;
                    D_8010B310_1A40A0_HandcarHavoc[i].x =
                        HuMathSin(w->rot.y - D_8010B170_1A3F00_HandcarHavoc) * 300.0f +
                        D_8010B328_1A40B8_HandcarHavoc[i].x;
                    D_8010B310_1A40A0_HandcarHavoc[i].y = obj->trans.y;
                    D_8010B310_1A40A0_HandcarHavoc[i].z =
                        func_800B7890_B8490(w->rot.y - D_8010B170_1A3F00_HandcarHavoc) * 300.0f +
                        D_8010B328_1A40B8_HandcarHavoc[i].z;
                    D_8010B350_1A40E0_HandcarHavoc[i] =
                        (D_8010B310_1A40A0_HandcarHavoc[i].y - D_8010B328_1A40B8_HandcarHavoc[i].y + 562.5f) /
                        (HuMathSin(70.0f) * 15.0f);
                    D_8010B340_1A40D0_HandcarHavoc[i] = HuMathSin(w->rot.y + 90.0f) * 300.0f / 15.0f;
                    D_8010B348_1A40D8_HandcarHavoc[i] = func_800B7890_B8490(w->rot.y + 90.0f) * 300.0f / 15.0f;
                    D_8010B358_1A40E8_HandcarHavoc = 0.0f;
                    D_8010D7E0_1A6570_HandcarHavoc[w->team]->func_ptr = func_8010A5B8_1A3348_HandcarHavoc;
                }
            }
            D_8010B170_1A3F00_HandcarHavoc += 9.0f;
            break;
        case 1:
            D_8010B358_1A40E8_HandcarHavoc += 1.0f;
            for (i = 0; i < 2; i++) {
                func_80029714_2A314(obj->model[3 + i],
                                    D_8010B340_1A40D0_HandcarHavoc[i] * D_8010B358_1A40E8_HandcarHavoc +
                                        D_8010B328_1A40B8_HandcarHavoc[i].x,
                                    HuMathSin(70.0f) * D_8010B350_1A40E0_HandcarHavoc[i] * D_8010B358_1A40E8_HandcarHavoc -
                                        D_8010B358_1A40E8_HandcarHavoc * 2.5f * D_8010B358_1A40E8_HandcarHavoc +
                                        D_8010B328_1A40B8_HandcarHavoc[i].y,
                                    D_8010B348_1A40D8_HandcarHavoc[i] * D_8010B358_1A40E8_HandcarHavoc +
                                        D_8010B328_1A40B8_HandcarHavoc[i].z);
                if (D_8010B358_1A40E8_HandcarHavoc > 3.0f) {
                    func_80029714_2A314(obj->model[5 + i],
                                        D_8010B340_1A40D0_HandcarHavoc[i] * D_8010B358_1A40E8_HandcarHavoc +
                                            D_8010B328_1A40B8_HandcarHavoc[i].x,
                                        obj->trans.y,
                                        D_8010B348_1A40D8_HandcarHavoc[i] * D_8010B358_1A40E8_HandcarHavoc +
                                            D_8010B328_1A40B8_HandcarHavoc[i].z);
                } else {
                    func_80029714_2A314(obj->model[5 + i],
                                        D_8010B340_1A40D0_HandcarHavoc[i] * D_8010B358_1A40E8_HandcarHavoc +
                                            D_8010B328_1A40B8_HandcarHavoc[i].x,
                                        D_8010B35C_1A40EC_HandcarHavoc,
                                        D_8010B348_1A40D8_HandcarHavoc[i] * D_8010B358_1A40E8_HandcarHavoc +
                                            D_8010B328_1A40B8_HandcarHavoc[i].z);
                }
            }
            if (D_8010B358_1A40E8_HandcarHavoc >= 15.0f) {
                for (i = 0; i < 2; i++) {
                    func_80029BF0_2A7F0(obj->model[3 + i], func_80029E14_2AA14(obj->motion[9 + i]), 0, 20, 0);
                    func_80029E80_2AA80(obj->model[3 + i], 3, 2);
                }
                D_8010B16C_1A3EFC_HandcarHavoc = 2;
                D_8010B170_1A3F00_HandcarHavoc = 90.0f;
            }
            break;
        case 2:
            a = D_8010B170_1A3F00_HandcarHavoc;
            for (i = 0; i < 2; i++) {
                if (i == 0) {
                    a = -a;
                }
                func_800B2060_B2C60(D_800FC834_FD434[obj->model[3 + i]].mtx, 0.0f, w->rot.y - a, 0.0f);
                if (D_8010B170_1A3F00_HandcarHavoc >= 180.0f) {
                    func_80029BF0_2A7F0(obj->model[3 + i], func_80029E14_2AA14(obj->motion[5 + i]), 0, 20, 0);
                    func_80029E80_2AA80(obj->model[3 + i], 3, 2);
                    D_8010D824_1A65B4_HandcarHavoc = 2;
                    obj->func_ptr = NULL;
                }
            }
            D_8010B170_1A3F00_HandcarHavoc += 18.0f;
            break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_80105940_19E6D0_HandcarHavoc);
#endif

/* The winning team cheers. */
void func_80105FEC_19ED7C_HandcarHavoc(omObjData* obj) {
    HHCar* w;
    s32 i;

    w = D_8010D820_1A65B0_HandcarHavoc[D_8010D862_1A65F2_HandcarHavoc]->unk_50;
    for (i = 0; i < 2; i++) {
        func_80029BF0_2A7F0(obj->model[3 + i], func_80029E14_2AA14(obj->motion[11 + i]), 0, 20, 0);
        func_800732B0_73EB0(w->cheerMot[i]);
    }
    obj->func_ptr = NULL;
}

/* The losing team despairs. */
void func_801060A4_19EE34_HandcarHavoc(omObjData* obj) {
    HHCar* w;
    s32 i;

    w = D_8010D820_1A65B0_HandcarHavoc[(s16)((u16)D_8010D862_1A65F2_HandcarHavoc ^ 1)]->unk_50;
    for (i = 0; i < 2; i++) {
        func_80029BF0_2A7F0(obj->model[3 + i], func_80029E14_2AA14(obj->motion[13 + i]), 0, 20, 0);
        func_800732B0_73EB0(w->loseMot[i]);
    }
    obj->func_ptr = NULL;
}

/* Intro: the instructions, then the race starts. */
void func_80106164_19EEF4_HandcarHavoc(omObjData* obj) {
    s32 i;

    switch (D_8010D870_1A6600_HandcarHavoc) {
        case 0:
            if (func_8008F618_90218() == 0) {
                D_8010D870_1A6600_HandcarHavoc = 1;
                func_800691FC_69DFC(15);
            }
            break;
        case 1:
            if (func_80069538_6A138() == 0 || (func_80069538_6A138() & 2)) {
                D_8010D800_1A6590_HandcarHavoc = 1;
                omDelObj(obj);
                D_8010B3AC_1A413C_HandcarHavoc = NULL;
                for (i = 0; i < 2; i++) {
                    D_8010D804_1A6594_HandcarHavoc->work[i] = 1;
                }
            }
            break;
    }
    if (D_8010B174_1A3F04_HandcarHavoc == 0) {
        PlayMusic(0x22);
    }
    D_8010B174_1A3F04_HandcarHavoc--;
}

/* The end: messages, coins, the teams' reactions, leaving. */
void func_8010625C_19EFEC_HandcarHavoc(omObjData* obj) {
    s32 pl[2];
    HHCar* w;
    s32 i;
    s32 j;

    switch (D_8010D824_1A65B4_HandcarHavoc) {
        case 0:
            D_8010D824_1A65B4_HandcarHavoc = 1;
            func_800794A8_7A0A8(180);
            PlaySound(15);
            func_800691FC_69DFC(D_8010B362_1A40F2_HandcarHavoc == 0 ? 20 : 3);
            D_8010D830_1A65C0_HandcarHavoc->work[0] = 1;
            break;
        case 2:
            if (func_80069538_6A138() == 0 || (func_80069538_6A138() & 2)) {
                w = D_8010D820_1A65B0_HandcarHavoc[D_8010D862_1A65F2_HandcarHavoc]->unk_50;
                for (i = 0; i < 2; i++) {
                    pl[i] = w->player[i];
                }
                if (D_8010D85E_1A65EE_HandcarHavoc == 1) {
                    func_8006961C_6A21C(func_800691FC_69DFC(14), 160.0f, 176.0f);
                    if (D_8010B362_1A40F2_HandcarHavoc == 1) {
                        D_8010B360_1A40F0_HandcarHavoc = 60;
                    } else {
                        D_8010B360_1A40F0_HandcarHavoc = 75;
                    }
                } else {
                    D_8010B360_1A40F0_HandcarHavoc = 1;
                }
                D_8010D824_1A65B4_HandcarHavoc = 5;
            }
            break;
        case 5:
            if (--D_8010B360_1A40F0_HandcarHavoc == 0) {
                w = D_8010D820_1A65B0_HandcarHavoc[D_8010D862_1A65F2_HandcarHavoc]->unk_50;
                for (i = 0; i < 2; i++) {
                    pl[i] = w->player[i];
                }
                gPlayers[pl[0]].coins_mg_bonus += 10;
                gPlayers[pl[1]].coins_mg_bonus += 10;
                w = D_8010D820_1A65B0_HandcarHavoc[(s16)((u16)D_8010D862_1A65F2_HandcarHavoc ^ 1)]->unk_50;
                D_8010B360_1A40F0_HandcarHavoc = 135;
                if (D_8010B362_1A40F2_HandcarHavoc == 0) {
                    D_8010D820_1A65B0_HandcarHavoc[D_8010D862_1A65F2_HandcarHavoc]->func_ptr =
                        func_80105FEC_19ED7C_HandcarHavoc;
                    D_8010D820_1A65B0_HandcarHavoc[(s16)((u16)D_8010D862_1A65F2_HandcarHavoc ^ 1)]->func_ptr =
                        func_801060A4_19EE34_HandcarHavoc;
                    func_800691FC_69DFC(17, gPlayers[pl[0]].character, gPlayers[pl[1]].character);
                    if (D_8010D85E_1A65EE_HandcarHavoc == 1) {
                        PlayMusic(0x55);
                    } else {
                        PlayMusic(0x52);
                    }
                    D_8010D824_1A65B4_HandcarHavoc = 4;
                } else {
                    if (D_8010D85E_1A65EE_HandcarHavoc == 1) {
                        D_8010B360_1A40F0_HandcarHavoc = 1;
                    } else {
                        D_8010B360_1A40F0_HandcarHavoc = 60;
                    }
                    D_8010D824_1A65B4_HandcarHavoc = 11;
                }
            }
            break;
        case 3:
            if (func_80069538_6A138() & 2) {
                PlayMusic(0x57);
                D_8010D824_1A65B4_HandcarHavoc = 4;
            }
            break;
        case 9:
            if (func_80069538_6A138() & 2) {
                D_8010D824_1A65B4_HandcarHavoc = 7;
            }
            break;
        case 6:
            if (func_8008F618_90218() == 0) {
                D_8010B180_1A3F10_HandcarHavoc = 1;
            }
            break;
        case 7:
            if (D_8010B362_1A40F2_HandcarHavoc == 0) {
                func_800691FC_69DFC(19);
                PlayMusic(0x57);
                D_8010B360_1A40F0_HandcarHavoc = 120;
                D_8010D824_1A65B4_HandcarHavoc = 3;
                for (i = 0; i < 2; i++) {
                    w = D_8010D820_1A65B0_HandcarHavoc[i]->unk_50;
                    for (j = 0; j < 2; j++) {
                        func_80029BF0_2A7F0(D_8010D820_1A65B0_HandcarHavoc[i]->model[3 + j],
                                            func_80029E14_2AA14(D_8010D820_1A65B0_HandcarHavoc[i]->motion[13 + j]), 0,
                                            20, 0);
                        func_800732B0_73EB0(w->loseMot[j]);
                    }
                    D_8010D820_1A65B0_HandcarHavoc[i]->func_ptr = NULL;
                }
            } else {
                func_800691FC_69DFC(3);
                D_8010B360_1A40F0_HandcarHavoc = 60;
                D_8010D824_1A65B4_HandcarHavoc = 11;
            }
            break;
        case 8:
            func_800794A8_7A0A8(180);
            if (D_8010B362_1A40F2_HandcarHavoc == 0) {
                func_800691FC_69DFC(18);
                D_8010B360_1A40F0_HandcarHavoc = 90;
                D_8010D824_1A65B4_HandcarHavoc = 9;
            } else {
                func_800691FC_69DFC(3);
                D_8010B360_1A40F0_HandcarHavoc = 60;
                D_8010D824_1A65B4_HandcarHavoc = 11;
            }
            break;
        case 10:
            func_800691FC_69DFC(3);
            D_8010B360_1A40F0_HandcarHavoc = 105;
            D_8010D824_1A65B4_HandcarHavoc = 11;
            break;
        case 4:
        case 11:
            if (--D_8010B360_1A40F0_HandcarHavoc == 0) {
                D_8010B180_1A3F10_HandcarHavoc = 1;
            }
            break;
    }
}

/* A team's track point i (MP1 func_800FC0C8, inlined in MP2). */
static inline void HHGetPoint(u16 team, u16 i, Vec* out) {
    ColVtx* p;

    p = &D_8010B380_1A4110_HandcarHavoc[team][i];
    out->x = p->x;
    out->y = p->y;
    out->z = p->z;
}

/* Both tracks' lengths (team 0's slot borrowed for each). */
void func_801067A0_19F530_HandcarHavoc(void) {
    s32 i;

    D_8010B3A0_1A4130_HandcarHavoc = 0.0f;
    D_8010B3A4_1A4134_HandcarHavoc = 0.0f;
    D_8010B376_1A4106_HandcarHavoc[0] = D_8010B37A_1A410A_HandcarHavoc;
    D_8010B380_1A4110_HandcarHavoc[0] = D_8010B388_1A4118_HandcarHavoc;
    D_8010B390_1A4120_HandcarHavoc[0] = D_8010B394_1A4124_HandcarHavoc;
    for (i = 0; i < D_8010B394_1A4124_HandcarHavoc - 1; i++) {
        D_8010B3A0_1A4130_HandcarHavoc += func_801069D8_19F768_HandcarHavoc(0, i);
    }
    D_8010B376_1A4106_HandcarHavoc[0] = D_8010B37C_1A410C_HandcarHavoc;
    D_8010B380_1A4110_HandcarHavoc[0] = D_8010B38C_1A411C_HandcarHavoc;
    D_8010B390_1A4120_HandcarHavoc[0] = D_8010B396_1A4126_HandcarHavoc;
    for (i = 0; i < D_8010B396_1A4126_HandcarHavoc - 1; i++) {
        D_8010B3A4_1A4134_HandcarHavoc += func_801069D8_19F768_HandcarHavoc(0, i);
    }
}

/* Midpoint of a team's track segment i. */
void func_801068CC_19F65C_HandcarHavoc(u16 team, u16 i, Vec* out) {
    Vec a;
    Vec b;

    HHGetPoint(team, i, &a);
    HHGetPoint(team, i + 1, &b);
    out->x = (a.x + b.x) * 0.5f;
    out->y = (a.y + b.y) * 0.5f;
    out->z = (a.z + b.z) * 0.5f;
}

/* Length of a team's track segment i. */
f32 func_801069D8_19F768_HandcarHavoc(u16 team, u16 i) {
    Vec a;
    Vec b;

    HHGetPoint(team, i, &a);
    HHGetPoint(team, i + 1, &b);
    return func_800B1830_B2430((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y) + (b.z - a.z) * (b.z - a.z));
}

/* Distance from (x, y, z) to a team's track point i. */
f32 func_80106AD0_19F860_HandcarHavoc(u16 team, f32 x, f32 y, f32 z, u16 i) {
    Vec a;

    HHGetPoint(team, i, &a);
    return func_800B1830_B2430((a.x - x) * (a.x - x) + (a.y - y) * (a.y - y) + (a.z - z) * (a.z - z));
}

/* Direction of a team's track segment i. */
void func_80106B84_19F914_HandcarHavoc(u16 team, u16 i, Vec* out) {
    Vec a;
    Vec b;
    f32 len;

    HHGetPoint(team, i, &a);
    HHGetPoint(team, i + 1, &b);
    len = func_801069D8_19F768_HandcarHavoc(team, i);
    out->x = (b.x - a.x) / len;
    out->y = (b.y - a.y) / len;
    out->z = (b.z - a.z) / len;
}

/* The car's position (between its axles) and rotation (from the axle line). */
void func_80106CA8_19FA38_HandcarHavoc(omObjData* obj, Vec* rot, Vec* pos) {
    Vec axle[2];
    Vec d;
    Vec p;
    HHCar* w;
    f32 dist;
    f32 a;
    u16 seg;
    s32 i;

    w = obj->unk_50;
    for (i = 0; i < 2; i++) {
        seg = w->seg[i];
        HHGetPoint(w->team, seg, &p);
        func_80106B84_19F914_HandcarHavoc(w->team, seg, &axle[i]);
        dist = w->dist[i];
        axle[i].x = dist * axle[i].x + p.x;
        axle[i].y = dist * axle[i].y + p.y;
        axle[i].z = dist * axle[i].z + p.z;
    }
    for (i = 0; i < 3; i++) {
        (&w->slope.x)[i] = (&d.x)[i] = ((&axle[1].x)[i] - (&axle[0].x)[i]) / 400.0f;
        (&pos->x)[i] = ((&axle[1].x)[i] + (&axle[0].x)[i]) / 2.0f;
    }
    rot->y = func_800B75A8_B81A8(d.x, d.z);
    a = func_8010A75C_1A34EC_HandcarHavoc(d.y);
    rot->x = a * -d.z;
    rot->z = a * d.x;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_80106E70_19FC00_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_801074A8_1A0238_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_80107634_1A03C4_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_80107740_1A04D0_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_801078B8_1A0648_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_80107900_1A0690_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_80107AB0_1A0840_HandcarHavoc);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1A_HandcarHavoc/19B590", func_80107C64_1A09F4_HandcarHavoc);
