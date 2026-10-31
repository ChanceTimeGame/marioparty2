#include "common.h"
#include "ovl_06.h"

__asm__(".section .rodata");
const u32 D_80108510_10BCD0_MalletGoRound[18] = { 0x82728273, 0x82608271, 0x82738268, 0x82738264, 0x826C8266, 0x82648273, 0x81498148, 0x00000000, 0x82688273, 0x8264826C, 0x81408266, 0x82648273, 0x81480000, 0x82688273, 0x8264826C, 0x81408266, 0x82648273, 0x81490000 };

void func_80102800_105FC0_MalletGoRound(void) {
    s16 i;
    s16 spr;
    omObjData* obj;

    for (i = 0; i < 4; i++) {
        if (gPlayers[i].group == 0) {
            break;
        }
    }
    switch (i) {
    case 1:
        D_801087A5_10BF65_MalletGoRound = 1;
        break;
    case 2:
        D_801087A5_10BF65_MalletGoRound = 2;
        break;
    case 3:
        D_801087A5_10BF65_MalletGoRound = 3;
        break;
    case 0:
    default:
        D_801087A5_10BF65_MalletGoRound = 0;
        break;
    }
    func_8002D4D0_2E0D0(5);
    func_8002F290_2FE90(D_800F9D30_FA930, 0x40);
    func_80020D20_21920(0x40);
    omInitObjMan(0x14, 0);
    func_80079128_79D28();
    func_8000C460_D060();
    func_8000C578_D178(1);
    func_80020070_20C70(1);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 2.865f, 80.0f, 8000.0f);
    func_8002C59C_2D19C(0x800, 0x990, 0x40, 0x40, 0x40);
    D_80108650_10BE10_MalletGoRound.x = -1377.9f;
    D_80108650_10BE10_MalletGoRound.y = 1228.16f;
    D_80108650_10BE10_MalletGoRound.z = -1393.0f;
    D_8010865C_10BE1C_MalletGoRound.x = -10.054f;
    D_8010865C_10BE1C_MalletGoRound.y = 44.302f;
    D_8010865C_10BE1C_MalletGoRound.z = -22.851f;
    spr = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x160000), 0, 1);
    espDispOff(spr);
    func_8007A27C_7AE7C(100, (s16)D_800F93FC_F9FFC[spr].unk_04, func_80104BC8_108388_MalletGoRound, 28.65f,
                        &D_80108650_10BE10_MalletGoRound, &D_8010865C_10BE1C_MalletGoRound);
    func_8000C38C_CF8C();
    func_8000C3C8_CFC8();
    func_8007273C_7333C((u8*)D_80108510_10BCD0_MalletGoRound, 1);
    D_800FA606_FB206 = 0;
    D_800FC87A_FD47A = 0;
    D_801087A0_10BF60_MalletGoRound = obj = omAddObj(6, 5, 0x2E, -1, func_80102C14_1063D4_MalletGoRound);
    omSetStatBit(obj, 0xA0);
    D_80108794_10BF54_MalletGoRound = omAddObj(0x10, 2, 0, -1, func_80103E7C_10763C_MalletGoRound);
    D_80108798_10BF58_MalletGoRound = omAddObj(8, 0xB, 0xB, -1, func_801082A8_10BA68_MalletGoRound);
    D_8010879C_10BF5C_MalletGoRound = omAddObj(9, 0x14, 5, -1, func_801079EC_10B1AC_MalletGoRound);
    D_801087A8_10BF68_MalletGoRound = omAddObj(0xA, 0x1E, 0, -1, func_80105EEC_1096AC_MalletGoRound);
    omAddObj(0, 0, 0, -1, func_801050F0_1088B0_MalletGoRound);
    omAddObj(0xF, 0, 0, -1, func_801042D4_107A94_MalletGoRound);
    InitFadeIn(0, 0x10);
}

void func_80102C14_1063D4_MalletGoRound(omObjData* obj) {
    u8 chr = gPlayers[D_801087A5_10BF65_MalletGoRound].character;
    s32 dir = D_800CD438_CE038[chr].unk_04;
    s32 file = D_800CD438_CE038[chr].unk_08;

    func_80103F78_107738_MalletGoRound(obj, dir, file, D_801087A5_10BF65_MalletGoRound, -80.0f, -115.0f, -900.0f);
}

void func_80102CAC_10646C_MalletGoRound(omObjData* obj) {
    MgWork* w = obj->unk_50;
    s16* spr = w->unk_158;
    s16* mdl;
    f32 frame;
    f32 angle;
    s8 n;
    s8 i;

    if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        if (D_80108461_10BC21_MalletGoRound == 1) {
            D_80108460_10BC20_MalletGoRound = 0;
        }
        if (D_80108460_10BC20_MalletGoRound == 1) {
            if (D_80108464_10BC24_MalletGoRound == 0) {
                D_80108668_10BE28_MalletGoRound = D_801084B0_10BC70_MalletGoRound;
                angle = D_80108668_10BE28_MalletGoRound;
                if (angle < 0.0f) {
                    angle += 360.0f;
                }
                D_80108668_10BE28_MalletGoRound = angle;
                if (D_80108457_10BC17_MalletGoRound == 0) {
                    D_80108668_10BE28_MalletGoRound += 60.0f;
                    if (D_80108668_10BE28_MalletGoRound >= 360.0f) {
                        D_80108668_10BE28_MalletGoRound -= 360.0f;
                    }
                } else if (D_80108668_10BE28_MalletGoRound < 0.0f) {
                    D_80108668_10BE28_MalletGoRound += 360.0f;
                }
                D_801087A4_10BF64_MalletGoRound = n = (s8)(D_80108668_10BE28_MalletGoRound / 60.0f) % 6;
                D_80108456_10BC16_MalletGoRound = 1;
                if (D_801086D0_10BE90_MalletGoRound[n].hits > 0) {
                    D_801086D0_10BE90_MalletGoRound[n].timer = 40;
                    D_801086D0_10BE90_MalletGoRound[n].falling = 1;
                }
                if (D_801086D0_10BE90_MalletGoRound[n].hits < 2 && D_80108453_10BC13_MalletGoRound == -1) {
                    D_80108455_10BC15_MalletGoRound = D_801086D0_10BE90_MalletGoRound[n].item;
                    D_8010845A_10BC1A_MalletGoRound = 1;
                    if (D_80108455_10BC15_MalletGoRound == 0) {
                        D_80108453_10BC13_MalletGoRound = 0;
                    } else if (D_80108455_10BC15_MalletGoRound == 4) {
                        D_80108453_10BC13_MalletGoRound = 1;
                    } else {
                        D_80108453_10BC13_MalletGoRound = 2;
                    }
                }
            }
            if (D_80108464_10BC24_MalletGoRound == 20) {
                PlaySound(0x142);
            }
            if (D_80108464_10BC24_MalletGoRound == 30) {
                PlaySound(0x143);
                if (D_801087A4_10BF64_MalletGoRound == 0) {
                    PlaySound(0x140);
                }
                if (D_80108453_10BC13_MalletGoRound != -1 && D_8010845B_10BC1B_MalletGoRound == 0) {
                    func_800794A8_7A0A8(0x3C);
                    D_8010845B_10BC1B_MalletGoRound = 1;
                }
                func_80021198_21D98(*spr, 0);
                func_800298A4_2A4A4(obj->model[2], 4, 0);
                if (D_801086D0_10BE90_MalletGoRound[D_801087A4_10BF64_MalletGoRound].hits < 2) {
                    omVibrate(w->unk_59, 2, 2, 0x14);
                }
                func_80029714_2A314(obj->model[2], obj->trans.x - 200.0f, obj->trans.y + 40.0f, obj->trans.z);
                D_8010866C_10BE2C_MalletGoRound = 0.0f;
                D_80108670_10BE30_MalletGoRound = 1.0f;
                if (D_801086D0_10BE90_MalletGoRound[D_801087A4_10BF64_MalletGoRound].hits == 2) {
                    func_800298A4_2A4A4(D_801087A8_10BF68_MalletGoRound->model[D_801087A4_10BF64_MalletGoRound + 1], 4, 4);
                    func_80029A8C_2A68C(D_801087A8_10BF68_MalletGoRound->model[13]);
                    func_8002A00C_2AC0C(D_801087A8_10BF68_MalletGoRound->model[13]);
                    func_800298A4_2A4A4(D_801087A8_10BF68_MalletGoRound->model[13], 4, 0);
                } else if (D_801086D0_10BE90_MalletGoRound[D_801087A4_10BF64_MalletGoRound].hits == 1) {
                    if (D_801087A4_10BF64_MalletGoRound != 0) {
                        func_800298A4_2A4A4(D_801087A8_10BF68_MalletGoRound->model[D_801087A4_10BF64_MalletGoRound + 7], 4, 4);
                        func_80029A8C_2A68C(D_801087A8_10BF68_MalletGoRound->model[14]);
                        func_8002A00C_2AC0C(D_801087A8_10BF68_MalletGoRound->model[14]);
                        func_800298A4_2A4A4(D_801087A8_10BF68_MalletGoRound->model[14], 4, 0);
                    } else {
                        func_800298A4_2A4A4(D_801087A8_10BF68_MalletGoRound->model[D_801087A4_10BF64_MalletGoRound + 1], 4, 4);
                        func_80029A8C_2A68C(D_801087A8_10BF68_MalletGoRound->model[13]);
                        func_8002A00C_2AC0C(D_801087A8_10BF68_MalletGoRound->model[13]);
                        func_800298A4_2A4A4(D_801087A8_10BF68_MalletGoRound->model[13], 4, 0);
                    }
                }
            }
            if (D_801086D0_10BE90_MalletGoRound[D_801087A4_10BF64_MalletGoRound].hits == 2) {
                func_8002AC10_2B810(D_801087A8_10BF68_MalletGoRound->model[13], D_8010866C_10BE2C_MalletGoRound, D_80108670_10BE30_MalletGoRound, 1);
                mdl = D_801087A8_10BF68_MalletGoRound->model;
                func_80029714_2A314(mdl[13], D_800FC834_FD434[mdl[D_801087A4_10BF64_MalletGoRound + 1]].pos.x, D_800FC834_FD434[mdl[D_801087A4_10BF64_MalletGoRound + 1]].pos.y, D_800FC834_FD434[mdl[D_801087A4_10BF64_MalletGoRound + 1]].pos.z);
            } else if (D_801086D0_10BE90_MalletGoRound[D_801087A4_10BF64_MalletGoRound].hits == 1) {
                if (D_801087A4_10BF64_MalletGoRound != 0) {
                    func_8002AC10_2B810(D_801087A8_10BF68_MalletGoRound->model[14], D_8010866C_10BE2C_MalletGoRound, D_80108670_10BE30_MalletGoRound, 1);
                    mdl = D_801087A8_10BF68_MalletGoRound->model;
                    func_80029714_2A314(mdl[14], D_800FC834_FD434[mdl[D_801087A4_10BF64_MalletGoRound + 7]].pos.x, D_800FC834_FD434[mdl[D_801087A4_10BF64_MalletGoRound + 7]].pos.y, D_800FC834_FD434[mdl[D_801087A4_10BF64_MalletGoRound + 7]].pos.z);
                } else {
                    func_8002AC10_2B810(D_801087A8_10BF68_MalletGoRound->model[13], D_8010866C_10BE2C_MalletGoRound, D_80108670_10BE30_MalletGoRound, 1);
                    mdl = D_801087A8_10BF68_MalletGoRound->model;
                    func_80029714_2A314(mdl[13], D_800FC834_FD434[mdl[D_801087A4_10BF64_MalletGoRound + 1]].pos.x, D_800FC834_FD434[mdl[D_801087A4_10BF64_MalletGoRound + 1]].pos.y, D_800FC834_FD434[mdl[D_801087A4_10BF64_MalletGoRound + 1]].pos.z);
                }
            }
            D_8010866C_10BE2C_MalletGoRound += 0.05f;
            if (D_8010866C_10BE2C_MalletGoRound >= 0.5f) {
                func_800298A4_2A4A4(D_801087A8_10BF68_MalletGoRound->model[13], 4, 4);
                func_800298A4_2A4A4(D_801087A8_10BF68_MalletGoRound->model[14], 4, 4);
                D_8010866C_10BE2C_MalletGoRound = 0.5f;
            } else {
                D_80108670_10BE30_MalletGoRound += 0.3f;
            }
            if (D_80108453_10BC13_MalletGoRound != 0 && D_80108455_10BC15_MalletGoRound == -1) {
                switch (D_80108462_10BC22_MalletGoRound) {
                case 0:
                    frame = func_80029CE4_2A8E4(D_801087A0_10BF60_MalletGoRound->model[0]);
                    if (func_80029D0C_2A90C(D_801087A0_10BF60_MalletGoRound->model[0]) <= frame) {
                        func_80029B80_2A780(D_801087A0_10BF60_MalletGoRound->model[0], D_801087A0_10BF60_MalletGoRound->motion[40]);
                        func_80029E80_2AA80(D_801087A0_10BF60_MalletGoRound->model[0], 2, 0);
                        func_8002C570_2D170(D_801087A0_10BF60_MalletGoRound->model[0]);
                        D_80108462_10BC22_MalletGoRound++;
                    }
                    break;
                case 1:
                    frame = func_80029CE4_2A8E4(D_801087A0_10BF60_MalletGoRound->model[0]);
                    if (func_80029D0C_2A90C(D_801087A0_10BF60_MalletGoRound->model[0]) <= frame) {
                        D_80108460_10BC20_MalletGoRound = 0;
                        if (D_80108455_10BC15_MalletGoRound != -1) {
                            D_80108461_10BC21_MalletGoRound = 1;
                        }
                        func_80029B80_2A780(D_801087A0_10BF60_MalletGoRound->model[0], D_801087A0_10BF60_MalletGoRound->motion[0]);
                        func_80029E80_2AA80(D_801087A0_10BF60_MalletGoRound->model[0], 2, 0);
                        func_8002C570_2D170(D_801087A0_10BF60_MalletGoRound->model[0]);
                        D_80108462_10BC22_MalletGoRound = 0;
                    }
                    break;
                }
            }
            D_80108464_10BC24_MalletGoRound++;
        } else if (D_801084B4_10BC74_MalletGoRound == 0 && D_80108454_10BC14_MalletGoRound == 5 && (ContBtnTrg[w->unk_57] & 0x8000)) {
            func_80029B80_2A780(obj->model[0], obj->motion[38]);
            func_80029E80_2AA80(D_801087A0_10BF60_MalletGoRound->model[0], 2, 0);
            func_8002C570_2D170(obj->model[0]);
            D_80108464_10BC24_MalletGoRound = 0;
            D_80108460_10BC20_MalletGoRound = 1;
        }
        for (i = 0; i < 6; i++) {
            if (D_801086D0_10BE90_MalletGoRound[i].falling == 1) {
                if (D_801086D0_10BE90_MalletGoRound[i].timer-- == 0) {
                    if (D_801086D0_10BE90_MalletGoRound[i].hits-- < 0) {
                        D_801086D0_10BE90_MalletGoRound[i].hits = 0;
                    }
                    D_801086D0_10BE90_MalletGoRound[i].falling = 0;
                }
            }
        }
    } else if (D_80108460_10BC20_MalletGoRound == 1) {
        if (D_801086D0_10BE90_MalletGoRound[D_801087A4_10BF64_MalletGoRound].hits == 2) {
            func_8002AC10_2B810(D_801087A8_10BF68_MalletGoRound->model[13], D_8010866C_10BE2C_MalletGoRound, D_80108670_10BE30_MalletGoRound, 1);
            mdl = D_801087A8_10BF68_MalletGoRound->model;
            func_80029714_2A314(mdl[13], D_800FC834_FD434[mdl[D_801087A4_10BF64_MalletGoRound + 1]].pos.x, D_800FC834_FD434[mdl[D_801087A4_10BF64_MalletGoRound + 1]].pos.y, D_800FC834_FD434[mdl[D_801087A4_10BF64_MalletGoRound + 1]].pos.z);
        } else if (D_801086D0_10BE90_MalletGoRound[D_801087A4_10BF64_MalletGoRound].hits == 1) {
            if (D_801087A4_10BF64_MalletGoRound != 0) {
                func_8002AC10_2B810(D_801087A8_10BF68_MalletGoRound->model[14], D_8010866C_10BE2C_MalletGoRound, D_80108670_10BE30_MalletGoRound, 1);
                mdl = D_801087A8_10BF68_MalletGoRound->model;
                func_80029714_2A314(mdl[14], D_800FC834_FD434[mdl[D_801087A4_10BF64_MalletGoRound + 7]].pos.x, D_800FC834_FD434[mdl[D_801087A4_10BF64_MalletGoRound + 7]].pos.y, D_800FC834_FD434[mdl[D_801087A4_10BF64_MalletGoRound + 7]].pos.z);
            } else {
                func_8002AC10_2B810(D_801087A8_10BF68_MalletGoRound->model[13], D_8010866C_10BE2C_MalletGoRound, D_80108670_10BE30_MalletGoRound, 1);
                mdl = D_801087A8_10BF68_MalletGoRound->model;
                func_80029714_2A314(mdl[13], D_800FC834_FD434[mdl[D_801087A4_10BF64_MalletGoRound + 1]].pos.x, D_800FC834_FD434[mdl[D_801087A4_10BF64_MalletGoRound + 1]].pos.y, D_800FC834_FD434[mdl[D_801087A4_10BF64_MalletGoRound + 1]].pos.z);
            }
        }
    }
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z + D_8010845C_10BC1C_MalletGoRound);
}

/* The player's main: a CPU picks a slot by its difficulty and presses A when the wheel lines up. */
void func_801037B0_106F70_MalletGoRound(omObjData* obj) {
    MgWork* w = obj->unk_50;
    f32 angle;
    s8 t;
    s8 i;

    if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        if (D_80108468_10BC28_MalletGoRound == 0) {
            D_8010867D_10BE3D_MalletGoRound = 1;
            D_80108676_10BE36_MalletGoRound = 0;
            D_80108678_10BE38_MalletGoRound = guRandom() % 101;
            for (i = 0; i < 5; i++) {
                D_80108676_10BE36_MalletGoRound += D_800CAFE4[i];
                if (D_80108676_10BE36_MalletGoRound >= D_80108678_10BE38_MalletGoRound) {
                    D_8010867D_10BE3D_MalletGoRound = i + 1;
                    break;
                }
            }
            D_80108674_10BE34_MalletGoRound = guRandom() % 100;
            D_80108468_10BC28_MalletGoRound = 1;
        }
        if (D_80108469_10BC29_MalletGoRound == 0) {
            switch (gPlayers[w->unk_59].cpu_difficulty) {
            case 0:
                if (D_80108674_10BE34_MalletGoRound >= 30) {
                    D_8010867C_10BE3C_MalletGoRound = t = (s8)(D_8010867D_10BE3D_MalletGoRound + guRandom() % 3 - 2) % 5;
                    if (t == 0) {
                        D_8010867C_10BE3C_MalletGoRound = guRandom() % 3 + 1;
                    }
                } else {
                    D_8010867C_10BE3C_MalletGoRound = 0;
                }
                break;
            case 1:
                if (D_80108674_10BE34_MalletGoRound >= 20) {
                    D_8010867C_10BE3C_MalletGoRound = t = (s8)(D_8010867D_10BE3D_MalletGoRound + guRandom() % 2 - 1) % 5;
                    if (t == 0) {
                        D_8010867C_10BE3C_MalletGoRound = guRandom() % 3 + 1;
                    }
                } else {
                    D_8010867C_10BE3C_MalletGoRound = 0;
                }
                break;
            case 2:
                if (D_80108674_10BE34_MalletGoRound >= 10) {
                    D_8010867C_10BE3C_MalletGoRound = t = (s8)(D_8010867D_10BE3D_MalletGoRound + guRandom() % 1) % 5;
                    if (t == 0) {
                        D_8010867C_10BE3C_MalletGoRound = guRandom() % 3 + 1;
                    }
                } else {
                    D_8010867C_10BE3C_MalletGoRound = 0;
                }
                break;
            case 3:
                if (D_80108674_10BE34_MalletGoRound >= 5) {
                    D_8010867C_10BE3C_MalletGoRound = D_8010867D_10BE3D_MalletGoRound;
                } else {
                    D_8010867C_10BE3C_MalletGoRound = 0;
                }
                break;
            }
            D_80108469_10BC29_MalletGoRound = 1;
        }
        if (D_80108454_10BC14_MalletGoRound == 5 && (gPlayers[w->unk_59].flags & 1)) {
            D_80108680_10BE40_MalletGoRound = D_801084B0_10BC70_MalletGoRound;
            angle = D_80108680_10BE40_MalletGoRound;
            if (angle < 0.0f) {
                angle += 360.0f;
            }
            D_80108680_10BE40_MalletGoRound = angle;
            if (D_80108457_10BC17_MalletGoRound == 0) {
                D_80108680_10BE40_MalletGoRound += 60.0f;
                if (D_80108680_10BE40_MalletGoRound >= 360.0f) {
                    D_80108680_10BE40_MalletGoRound -= 360.0f;
                }
            } else if (D_80108680_10BE40_MalletGoRound < 0.0f) {
                D_80108680_10BE40_MalletGoRound += 360.0f;
            }
            t = (s8)(D_80108680_10BE40_MalletGoRound / 60.0f) % 6;
            if (D_8010846C_10BC2C_MalletGoRound++ > 20) {
                if (D_8010867C_10BE3C_MalletGoRound == t) {
                    ContBtnTrg[w->unk_57] = 0x8000;
                    D_80108469_10BC29_MalletGoRound = 0;
                    D_8010846C_10BC2C_MalletGoRound = 0;
                } else {
                    ContBtnTrg[w->unk_57] = 0;
                }
            }
            ContBtn[w->unk_57] = 0;
            ContStkX[w->unk_57] = 0;
            ContStkY[w->unk_57] = 0;
        }
    }
    func_80102CAC_10646C_MalletGoRound(obj);
}

void func_80103DB4_107574_MalletGoRound(omObjData* obj) {
    if (D_80108458_10BC18_MalletGoRound == 1) {
        if (obj->trans.y > -50.0f) {
            obj->rot.x -= 12.0f;
            if (obj->rot.x < 0.0f) {
                obj->rot.x += 360.0f;
            }
            obj->trans.z -= 10.0f;
            obj->trans.y += D_80108470_10BC30_MalletGoRound;
            D_80108470_10BC30_MalletGoRound -= 8.0f;
        } else {
            obj->trans.y = -50.0f;
        }
    }
}

void func_80103E7C_10763C_MalletGoRound(omObjData* obj) {
    ColActorWork* w;

    obj->unk_50 = w = func_80027154_27D54(sizeof(ColActorWork), 0x7918);
    func_800B0EF0_B1AF0(w, 0, sizeof(ColActorWork));
    w->unk_7C = 0;
    w->unk_54 = 1;
    w->unk_44 = 0.1f;
    w->unk_48 = 30.0f;
    w->unk_34 = 50.0f;
    w->unk_3C = 0.0f;
    w->unk_78 = 0;
    w->unk_38 = 1000.0f;
    w->unk_52 = 3;
    *(f32*)&w->unk_74 = 0.5f;
    w->unk_50 = 0x20;
    obj->model[0] = func_80018A64_19664(0x160003, 0x2B9);
    func_80105168_108928_MalletGoRound(D_801087A0_10BF60_MalletGoRound, D_80108794_10BF54_MalletGoRound);
    obj->func_ptr = func_80103DB4_107574_MalletGoRound;
}

void func_80103F78_107738_MalletGoRound(omObjData* obj, s32 dir, s32 file, u16 player, f32 x, f32 y, f32 z) {
    MgWork* w;
    s16* state;
    s16* spr;
    void* data;
    u16 id;

    obj->unk_50 = func_80027154_27D54(sizeof(MgWork), 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, sizeof(MgWork));
    w = obj->unk_50;
    spr = w->unk_158 = func_80027154_27D54(2, 0x7918);
    func_800B0EF0_B1AF0(spr, 0, 2);
    state = w->unk_158;
    obj->model[0] = LoadFormFile(dir | file, 0x2B9);
    obj->model[1] = LoadFormFile(0xD, 0x6B9);
    data = DataRead(0x11);
    id = func_80020EBC_21ABC(data, 0xAB9, 8);
    HuMemMemoryFreePerm(data);
    obj->model[2] = D_800F86D8_F92D8[id].unk00;
    *state = id;
    w->unk_59 = player;
    w->unk_57 = gPlayers[player].port;
    w->unk_52 = 0;
    w->unk_B4 = 1.0f;
    w->unk_D0 = 0xFFFF;
    w->unk_38 = 1000.0f;
    w->unk_50 = 0;
    func_8000BEB0_CAB0(obj, 60.0f);
    func_8000BEBC_CABC(obj, 150.0f);
    func_8000BEC8_CAC8(obj, 20.0f);
    func_80018CCC_198CC(obj, 0, dir | 0xAF);
    func_80018CCC_198CC(obj, 1, dir | 1);
    func_80018CCC_198CC(obj, 0xD, dir | 0x54);
    func_80018CCC_198CC(obj, 0xE, dir | 0x57);
    func_80018CCC_198CC(obj, 0x26, dir | 0xB0);
    func_80018CCC_198CC(obj, 0x27, dir | 0x19);
    func_80018CCC_198CC(obj, 0x28, dir | 0xB1);
    func_80018CCC_198CC(obj, 0x29, dir | 0x56);
    obj->motion[39] = func_80029E14_2AA14(obj->motion[39]);
    func_8000C35C_CF5C(obj, x, y, z);
    func_80029714_2A314(obj->model[0], x, y, z);
    func_8000C36C_CF6C(obj, 0.0f, 0.0f, 0.0f);
    func_800298A4_2A4A4(obj->model[2], 4, 4);
    HmfModelObjAttrSet(obj->model[2], 0x70000000, 0x70000000);
    func_80029714_2A314(obj->model[2], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800297E8_2A3E8(obj->model[2], 6.0f, 6.0f, 6.0f);
    func_80029B80_2A780(obj->model[0], obj->motion[1]);
    func_80029E80_2AA80(obj->model[0], 2, 2);
    func_8002C524_2D124(obj->model[0], obj->motion[39], 2);
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
    obj->func_ptr = func_801037B0_106F70_MalletGoRound;
}

__asm__(".section .rodata");
const u32 D_80108558_10BD18_MalletGoRound[4] = { 0xFF000102, 0x03040506, 0x07080900, 0x00000000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_MalletGoRound/105FC0", func_801042D4_107A94_MalletGoRound);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_MalletGoRound/105FC0", func_80104BC8_108388_MalletGoRound);

void func_801050B0_108870_MalletGoRound(f32 fov, f32 x, f32 y, f32 z, f32 rx, f32 ry, f32 rz) {
    D_800FA610_FB210 = fov;
    D_800FD474_FE074.x = x;
    D_800FD474_FE074.y = y;
    D_800FD474_FE074.z = z;
    D_8010274C_10334C.x = rx;
    D_8010274C_10334C.y = ry;
    D_8010274C_10334C.z = rz;
}

/* The skip object: START while the framework says so (D_801011FC) fades out and leaves. */
void func_801050F0_1088B0_MalletGoRound(void) {
    if (D_801011FC_101DFC == 1) {
        if (D_80108490_10BC50_MalletGoRound == 0) {
            InitFadeOut(0, 0x14);
            D_80108490_10BC50_MalletGoRound = 1;
        } else if (func_8008F618_90218() == 0) {
            func_800794A8_7A0A8(0x28);
            func_80069770_6A370();
            omOvlReturnEx(1);
        }
    }
}

/* Puts the item in the player's hand. */
s32 func_80105168_108928_MalletGoRound(omObjData* obj, omObjData* item) {
    MgWork* w;
    ColActorWork* iw;
    u16 f;

    w = obj->unk_50;
    iw = item->unk_50;

    if (iw->unk_50 & 0x20) {
        if (!(((volatile ColActorWork*)iw)->unk_50 & 0x10)) { /* retail reloads the flags */
            f = w->unk_50;
            if (f & 0x10) {
                return 0;
            }
            w->unk_50 = f | 0x10;
            iw->unk_50 |= 0x10;
            w->unk_C8 = item;
            func_8002C628_2D228(item->model[0], obj->model[0], "item_hook");
            func_800298A4_2A4A4(item->model[0], 0x4000, 0x4000);
            w->unk_B4 = *(f32*)&iw->unk_74;
            return 1;
        }
    }
    return 0;
}

/* Lets the item go. */
s32 func_80105224_1089E4_MalletGoRound(omObjData* obj, omObjData* item) {
    MgWork* w = obj->unk_50;
    ColActorWork* iw = item->unk_50;

    if (!(iw->unk_50 & 0x20)) {
        return 0;
    }
    w->unk_50 &= 0xFFEF;
    iw->unk_50 &= 0xFFEF;
    w->unk_C8 = NULL;
    func_800298A4_2A4A4(item->model[0], 0x4000, 0);
    return 1;
}

void func_80105284_108A44_MalletGoRound(omObjData* obj) {
    f32 scale = 0.4f - obj->trans.y * 0.0015f;

    func_800297E8_2A3E8(obj->model[1], scale, 0.0f, scale);
    func_80029714_2A314(obj->model[1], obj->trans.x, 2.4f, obj->trans.z);
}

f32 func_80105308_108AC8_MalletGoRound(void) {
    s8 x;
    s8 y;
    s8 port;
    f32 ret;
    s16 i;
    f32 sx;
    f32 sy;

    port = ((MgWork*)D_800FFFD8_100BD8[0]->unk_50)->unk_57;
    y = ContStkY[port];
    x = ContStkX[port];
    if (x > 60) {
        x = 60;
    }
    if (y > 60) {
        y = 60;
    }
    if (x < -60) {
        x = -60;
    }
    if (y < -60) {
        y = -60;
    }
    D_80108494_10BC54_MalletGoRound[D_801084A4_10BC64_MalletGoRound] = (f32)x;
    D_8010849C_10BC5C_MalletGoRound[D_801084A4_10BC64_MalletGoRound] = (f32)y;
    D_801084A4_10BC64_MalletGoRound = ((u8)D_801084A4_10BC64_MalletGoRound + 1) & 7;
    sx = 0.0f;
    sy = 0.0f;
    for (i = 0; i < 8; i++) {
        sx += D_80108494_10BC54_MalletGoRound[i];
        sy += D_8010849C_10BC5C_MalletGoRound[i];
    }
    sx /= 8.0f;
    sy /= 8.0f;
    if (sx * sx + sy * sy > 100.0f) {
        ret = func_800B75A8_B81A8(sx, -sy) + 180.0f;
    } else {
        ret = -1.0f;
    }
    return ret;
}

/* Park-Miller step (16807 mod 2^31 - 1); a zero seed is re-seeded. */
u32 func_801054D4_108C94_MalletGoRound(u32 seed) {
    s32 hi;
    s32 lo;

    if (seed == 0) {
        seed = rand8();
        seed = seed ^ guRandom();
        seed ^= 0xD826BC89;
    }
    hi = seed / 127773;
    lo = seed - hi * 127773;
    seed = hi * 2836;
    seed = seed - lo * 16807;
    return seed;
}

u32 func_801055A8_108D68_MalletGoRound(void) {
    return D_801084A8_10BC68_MalletGoRound = func_801054D4_108C94_MalletGoRound(D_801084A8_10BC68_MalletGoRound);
}

u16 func_801055D0_108D90_MalletGoRound(s32 file, s32 attr, u8 arg2) {
    void* data = DataRead(file);
    u16 id = func_80020EBC_21ABC(data, attr, arg2);

    HuMemMemoryFreePerm(data);
    return id;
}

__asm__(".section .rodata\n\t.balign 16\n\t.text");
