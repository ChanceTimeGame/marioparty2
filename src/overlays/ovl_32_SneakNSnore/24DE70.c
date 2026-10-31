#include "ovl_32.h"

#define ABSDIFF(x) ((x) > 0.0f ? (x) : (0.0f - (x)))

void func_80102800_24DE70_SneakNSnore(void) {
    func_8002D4D0_2E0D0(0x20);
    func_8002F290_2FE90(D_800F9D30_FA930, 0x40);
    func_80020D20_21920(0x40);
    omInitObjMan(0x20, 0);
    func_80079128_79D28();
    D_800FA606_FB206 = 0;
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    omSetStatBit(omAddObj(1, 0, 0, -1, func_80102A54_24E0C4_SneakNSnore), 0xA0);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_80079E60_7AA60), 0xA0);
    func_8000C38C_CF8C();
    func_80026DAC_279AC(1, 0x40, 0x40, 0x40);
    func_80026E00_27A00(1, 0.0f, 0.0f, 100.0f);
    func_80102940_24DFB0_SneakNSnore();
    D_801084B0_253B20_SneakNSnore[0] = omAddObj(1, 0x18, 3, -1, func_80103B98_24F208_SneakNSnore);
    func_80106DE0_252450_SneakNSnore();
    func_80106010_251680_SneakNSnore();
    func_8002CA48_2D648(0x64, 0x64, 0x64);
    InitFadeIn(0, 0x10);
}

void func_80102940_24DFB0_SneakNSnore(void) {
    s32 cam;

    D_8010274C_10334C.x = 0.0f;
    D_8010274C_10334C.y = -100.0f;
    D_8010274C_10334C.z = -100.0f;
    D_800FD474_FE074.x = -25.0f;
    D_800FD474_FE074.y = 0.0f;
    D_800FD474_FE074.z = 0.0f;
    D_800FA610_FB210 = 1600.0f;
    func_80018E30_19A30(1);
    cam = func_80018E78_19A78();
    ScissorSet(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(cam, 30.0f, 80.0f, 8000.0f);
}

void func_80102A54_24E0C4_SneakNSnore(void) {
    Vec to;
    Vec from;
    Vec dir;
    MgWork* w;
    f32 end;
    s32 i;
    s32 dirFile;
    u32 r;

    switch (D_801082D5_253945_SneakNSnore) {
    case 0:
        if (D_801011FC_101DFC == 1) {
            func_80079868_7A468();
            if (!(D_800CD526_CE126 & 4)) {
                func_800794A8_7A0A8(0x28);
            } else {
                func_80079464_7A064();
            }
            InitFadeOut(0, 0x14);
            D_801082D5_253945_SneakNSnore = 1;
        }
        break;
    case 1:
        if (func_8008F618_90218() == 0 && !(D_800CD526_CE126 & 4)) {
            omOvlReturnEx(1);
            D_801082D5_253945_SneakNSnore = 2;
        }
        break;
    }
    func_8000C3C8_CFC8();
    switch (D_800F8FD0_F9BD0) {
    case 0:
        if (D_801082B8_253928_SneakNSnore == 60) {
            if (D_801082F0_253960_SneakNSnore[0] == 1) {
                func_800691FC_69DFC(0);
            }
        } else if ((u32)D_801082B8_253928_SneakNSnore > 60) {
            if (func_80069538_6A138() == 0 || (func_80069538_6A138() & 2)) {
                func_8000C3B8_CFB8();
            }
        }
        if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
            D_801082B8_253928_SneakNSnore++;
        }
        break;
    case 1:
        if (D_801082C0_253930_SneakNSnore == 0) {
            func_800691FC_69DFC(0xA, D_801082B0_253920_SneakNSnore, 0xA0, 0x20);
            if (func_80069538_6A138() != 0) {
                func_80069538_6A138();
            }
        } else if (D_801082C0_253930_SneakNSnore == D_801082B0_253920_SneakNSnore * 30) {
            func_8000C398_CF98();
        }
        if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
            D_801082C4_253934_SneakNSnore = (D_801082B0_253920_SneakNSnore * 30 - D_801082C0_253930_SneakNSnore) / 30;
            D_801082C0_253930_SneakNSnore++;
        }
        if (D_801082C4_253934_SneakNSnore < 0) {
            func_8000C398_CF98();
        } else {
            func_8006D4D0_6E0D0(D_801082C4_253934_SneakNSnore);
        }
        break;
    case 2:
        if (D_801082BC_25392C_SneakNSnore == 0) {
            if (D_800CD526_CE126 & 4) {
                D_800CD526_CE126 &= ~4;
                func_80079464_7A064();
            } else {
                func_800794A8_7A0A8(0x28);
            }
            func_8000C690_D290();
            func_8006D518_6E118();
        } else if (D_801082BC_25392C_SneakNSnore == 30) {
            if (D_801082D4_253944_SneakNSnore == 0) {
                func_800691FC_69DFC(3);
                D_801082D4_253944_SneakNSnore = 1;
            }
            if (_CheckFlag(0xC) != 0) {
                if (D_801082C4_253934_SneakNSnore <= 0) {
                    D_801082D1_253941_SneakNSnore = 3;
                } else {
                    for (i = 0; i < 4; i++) {
                        if (!(gPlayers[i].flags & 1)) {
                            if (D_800FFFD8_100BD8[i]->work[0] & 2) {
                                D_801082D1_253941_SneakNSnore = 3;
                                break;
                            }
                            if (D_800FFFD8_100BD8[i]->work[0] & 1) {
                                D_801082D1_253941_SneakNSnore = 2;
                                break;
                            }
                        } else if (D_800FFFD8_100BD8[i]->work[0] & 1) {
                            D_801082D1_253941_SneakNSnore = 2;
                            break;
                        }
                    }
                }
            } else if ((D_800FFFD8_100BD8[0]->work[0] & 2) && (D_800FFFD8_100BD8[1]->work[0] & 2) && (D_800FFFD8_100BD8[2]->work[0] & 2)
                       && (D_800FFFD8_100BD8[3]->work[0] & 2)) {
                D_801082D1_253941_SneakNSnore = 1;
            } else if (D_801082C4_253934_SneakNSnore <= 0) {
                D_801082D1_253941_SneakNSnore = 1;
            } else {
                D_801082D1_253941_SneakNSnore = 2;
            }
            if (D_801082D1_253941_SneakNSnore == 2) {
                D_801082D0_253940_SneakNSnore = 1;
                if (D_801082D2_253942_SneakNSnore == -1) {
                    do {
                        r = rand8() >> 6;
                    } while (!(D_800FFFD8_100BD8[r]->work[0] & 1));
                    D_801082D2_253942_SneakNSnore = r;
                }
            }
        } else if ((u32)D_801082BC_25392C_SneakNSnore > 30) {
            if ((func_80069538_6A138() == 0 || (func_80069538_6A138() & 2)) && (D_801082D1_253941_SneakNSnore == 3 || D_801082D1_253941_SneakNSnore == 1)
                && D_801082D3_253943_SneakNSnore == 0) {
                if (_CheckFlag(0xC) == 0) {
                    PlayMusic(0x57);
                    if (D_801082D4_253944_SneakNSnore == 1) {
                        func_800691FC_69DFC(0x13);
                        D_801082D4_253944_SneakNSnore = 2;
                    }
                }
                D_801082D3_253943_SneakNSnore = 1;
            }
        }
        if (D_801082D0_253940_SneakNSnore == 1) {
            if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
                D_800FD474_FE074.x += 1.0f;
                if (D_800FD474_FE074.x > 0.0f) {
                    D_800FD474_FE074.x = 0.0f;
                }
                D_800FA610_FB210 -= 30.0f;
                if (D_800FA610_FB210 < 700.0f) {
                    D_800FA610_FB210 = 700.0f;
                }
                if (D_800FFFD8_100BD8[D_801082D2_253942_SneakNSnore]->work[1] == 0) {
                    to.x = -225.0f;
                } else if (D_800FFFD8_100BD8[D_801082D2_253942_SneakNSnore]->work[1] == 1) {
                    to.x = -80.0f;
                } else if (D_800FFFD8_100BD8[D_801082D2_253942_SneakNSnore]->work[1] == 2) {
                    to.x = 80.0f;
                } else if (D_800FFFD8_100BD8[D_801082D2_253942_SneakNSnore]->work[1] == 3) {
                    to.x = 225.0f;
                }
                to.y = 85.0f;
                to.z = -700.0f;
                from.x = D_8010274C_10334C.x;
                from.y = D_8010274C_10334C.y;
                from.z = D_8010274C_10334C.z;
                func_80105F58_2515C8_SneakNSnore(&dir, &from, &to);
                D_8010274C_10334C.x += dir.x * 20.0f;
                if (dir.x > 0.0f && to.x < D_8010274C_10334C.x) {
                    D_8010274C_10334C.x = to.x;
                } else if (dir.x < 0.0f && D_8010274C_10334C.x < to.x) {
                    D_8010274C_10334C.x = to.x;
                }
                D_80102750_103350[0] += dir.y * 20.0f;
                if (dir.y > 0.0f && to.y < D_80102750_103350[0]) {
                    D_80102750_103350[0] = to.y;
                } else if (dir.y < 0.0f && D_80102750_103350[0] < to.y) {
                    D_80102750_103350[0] = to.y;
                }
                D_80102750_103350[1] += dir.z * 20.0f;
                if (D_80102750_103350[1] < to.z) {
                    D_80102750_103350[1] = to.z;
                }
            }
            if (D_800FA610_FB210 == 700.0f && D_80102750_103350[1] == -700.0f) {
                D_801082D0_253940_SneakNSnore = 2;
            }
        } else if (D_801082D0_253940_SneakNSnore == 2 && D_801082D1_253941_SneakNSnore == D_801082D0_253940_SneakNSnore) {
            if (D_801082D3_253943_SneakNSnore == 0) {
                if (_CheckFlag(0xC) == 0) {
                    PlayMusic(0x51);
                    if (D_801082D4_253944_SneakNSnore == 1) {
                        func_8006961C_6A21C(func_800691FC_69DFC(6, gPlayers[D_801082D2_253942_SneakNSnore].character), 160.0f, 160.0f);
                        D_801082D4_253944_SneakNSnore = 2;
                    }
                }
                D_801082D3_253943_SneakNSnore = 1;
            }
            w = D_800FFFD8_100BD8[D_801082D2_253942_SneakNSnore]->unk_50;
            if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
                D_80108410_253A80_SneakNSnore += 1.0f;
                func_8002AC10_2B810(D_800FFFD8_100BD8[D_801082D2_253942_SneakNSnore]->model[10], 0.5f, D_80108410_253A80_SneakNSnore, 2);
                func_800298A4_2A4A4(D_800FFFD8_100BD8[D_801082D2_253942_SneakNSnore]->model[0], 4, 4);
                func_800298A4_2A4A4(D_800FFFD8_100BD8[D_801082D2_253942_SneakNSnore]->model[9], 4, 0);
                func_80029714_2A314(D_800FFFD8_100BD8[D_801082D2_253942_SneakNSnore]->model[9], D_800FFFD8_100BD8[D_801082D2_253942_SneakNSnore]->trans.x,
                              D_800FFFD8_100BD8[D_801082D2_253942_SneakNSnore]->trans.y, D_800FFFD8_100BD8[D_801082D2_253942_SneakNSnore]->trans.z);
            }
            end = 118.0f;
            if (D_801082C8_253938_SneakNSnore == 0) {
                w->unk_5A[0] = D_800FFFD8_100BD8[D_801082D2_253942_SneakNSnore]->model[9];
                w->unk_5A[1] = 2;
                dirFile = D_800CD438_CE038[gPlayers[w->unk_59].character].unk_04;
                func_80025384_25F84((u8)w->unk_5A[0], 2, gPlayers[w->unk_59].character, dirFile | 0xE0);
                if (_CheckFlag(0xC) == 0) {
                    func_80029BF0_2A7F0(D_800FFFD8_100BD8[D_801082D2_253942_SneakNSnore]->model[9], func_80029E14_2AA14(D_800FFFD8_100BD8[D_801082D2_253942_SneakNSnore]->motion[13]), 0, 1,
                                  2);
                    if (((u32)dirFile >> 16) == 6) {
                        func_800732B0_73EB0(dirFile | 0x4F);
                    } else {
                        func_800732B0_73EB0(dirFile | 0x4E);
                    }
                } else {
                    func_80029BF0_2A7F0(D_800FFFD8_100BD8[D_801082D2_253942_SneakNSnore]->model[9], func_80029E14_2AA14(D_800FFFD8_100BD8[D_801082D2_253942_SneakNSnore]->motion[0]), 0, 1,
                                  2);
                }
                gPlayers[D_801082D2_253942_SneakNSnore].coins_mg_bonus += 10;
            } else if (_CheckFlag(0xC) == 0 && func_80029CE4_2A8E4(D_800FFFD8_100BD8[D_801082D2_253942_SneakNSnore]->model[9]) >= end) {
                func_80029E80_2AA80(D_800FFFD8_100BD8[D_801082D2_253942_SneakNSnore]->model[9], 1, 1);
            }
            if (D_801082D3_253943_SneakNSnore == 1 && _CheckFlag(0xC) == 0) {
                if (D_801082CC_25393C_SneakNSnore >= 90) {
                    InitFadeOut(0, 0x14);
                    func_8000C3A8_CFA8();
                }
                D_801082CC_25393C_SneakNSnore++;
            }
            if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
                D_801082C8_253938_SneakNSnore++;
            }
        }
        if (_CheckFlag(0xC) != 0 && D_801082BC_25392C_SneakNSnore == 90) {
            InitFadeOut(0, 0x14);
            func_8000C3A8_CFA8();
        }
        if (D_801082D1_253941_SneakNSnore == 1 && D_801082D3_253943_SneakNSnore == D_801082D1_253941_SneakNSnore && _CheckFlag(0xC) == 0) {
            if (D_801082CC_25393C_SneakNSnore >= 120) {
                InitFadeOut(0, 0x14);
                func_8000C3A8_CFA8();
            }
            D_801082CC_25393C_SneakNSnore++;
        }
        if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
            D_801082BC_25392C_SneakNSnore++;
        }
        break;
    case 3:
        if (func_8008F618_90218() == 0 && !(D_800CD526_CE126 & 4)) {
            omOvlReturnEx(1);
        }
        break;
    }
}

__asm__(".section .rodata");
const char D_801083D0_253A40_SneakNSnore[16] = "c165n_4_DEF";

s16 func_80103994_24F004_SneakNSnore(s16 mdl, s32 file) {
    void* data;
    s32 id;
    u16 frame;

    if (D_80108468_253AD8_SneakNSnore != 0xFF) {
        func_8003E888_3F488(D_80108468_253AD8_SneakNSnore);
        func_8003E888_3F488(D_80108469_253AD9_SneakNSnore);
    }
    data = DataRead(file);
    /* retail calls it unprototyped: the result is not re-extended */
    id = ((s32(*)(HmfData*, void*, s16, const char*))func_8003D8F0_3E4F0)(D_800FC834_FD434[mdl].hmf, data, 0, D_801083D0_253A40_SneakNSnore);
    D_80108469_253AD9_SneakNSnore = id;
    func_8003E4F4_3F0F4(id, 1, 1);
    DataClose(data);
    frame = D_800FD7F8_FE3F8[(s16)id].unk_00;
    D_80108468_253AD8_SneakNSnore = func_8003DBE8_3E7E8(D_800FC834_FD434[mdl].hmf, id, 0, (char*)D_801083D0_253A40_SneakNSnore);
    func_80029A8C_2A68C(mdl);
    return frame;
}

void func_80103AC8_24F138_SneakNSnore(s16 mdl, s16 frame) {
    SSTexAnim* slot;

    if (D_80108468_253AD8_SneakNSnore != 0xFF) {
        if (frame == -1) {
            func_8003EE44_3FA44(D_800FC834_FD434[mdl].hmf);
        } else {
            func_8003EEA4_3FAA4(D_800FC834_FD434[mdl].hmf);
            slot = &D_800FD7F8_FE3F8[D_80108468_253AD8_SneakNSnore];
            slot->unk_00 = frame;
            slot->unk_04 = 0;
            slot->unk_0A = 0;
            slot->unk_06 = 0;
            slot->unk_02 = 0;
        }
    }
}

void func_80103B98_24F208_SneakNSnore(omObjData* obj) {
    MgWork* w;
    SSMotion* mot;
    SSLink* prev;
    f32 s;
    f32 c;
    f32 y;
    f32 a;
    s32 attr;
    u32 dir;
    s32 i;
    s32 j;

    attr = 0xAC9;
    dir = 0x420000;
    D_80108468_253AD8_SneakNSnore = 0xFF;
    obj->func_ptr = func_80104218_24F888_SneakNSnore;
    obj->trans.x = 100.0f;
    obj->trans.y = 30.0f;
    obj->trans.z = 550.0f;
    obj->rot.x = 0.0f;
    obj->rot.y = 350.0f;
    obj->rot.z = 20.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 0.5f;
    obj->work[0] = 0;
    obj->model[0] = LoadFormFile(0x420015, 0xAC9);
    func_80029E80_2AA80(obj->model[0], 1, 2);
    obj->unk_50 = func_80027154_27D54(sizeof(MgWork), 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, sizeof(MgWork));
    w = obj->unk_50;
    w->unk_E8 = func_80027154_27D54(obj->mtncnt * sizeof(SSMotion), 0x7918);
    w->unk_5A[0] = obj->model[0];
    w->unk_5A[1] = 0;
    obj->model[1] = LoadFormFile(0xD, 0xAC9);
    func_80029714_2A314(obj->model[1], obj->trans.x, 30.0f, obj->trans.z);
    obj->model[2] = LoadFormFile(0x420014, 0xA09);
    func_80029714_2A314(obj->model[2], obj->trans.x, obj->trans.y + 20.0f, obj->trans.z);
    func_800297E8_2A3E8(obj->model[2], obj->scale.x, obj->scale.y, obj->scale.z);
    func_8002D1EC_2DDEC(obj->model[2], 1);
    func_8002D2B4_2DEB4(obj->model[2], 0.0f, 69.0f, 100.0f);
    func_8002D274_2DE74(obj->model[2], 0x20, 0x40, 0x40);
    obj->model[3] = LoadFormFile(0x42001A, 0xA0D);
    func_80029714_2A314(obj->model[3], obj->trans.x, obj->trans.y + 20.0f, obj->trans.z);
    func_800297E8_2A3E8(obj->model[3], 1.5f, 1.5f, 1.5f);
    func_80029E80_2AA80(obj->model[3], 1, 2);
    D_8010846A_253ADA_SneakNSnore = func_80025684_26284(0x420018);
    D_8010846C_253ADC_SneakNSnore = func_80025684_26284(0x420019);
    func_80018CCC_198CC(obj, 0, 0x420015);
    ((SSMotion*)w->unk_E8)[0].unk_04 = D_8010846A_253ADA_SneakNSnore;
    func_80018CCC_198CC(obj, 2, 0x420017);
    ((SSMotion*)w->unk_E8)[2].unk_04 = D_8010846A_253ADA_SneakNSnore;
    func_80018CCC_198CC(obj, 1, 0x420016);
    ((SSMotion*)w->unk_E8)[1].unk_04 = D_8010846C_253ADC_SneakNSnore;
    func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[1]), 0, 0x50, 2);
    func_80103994_24F004_SneakNSnore(obj->model[0], 0x420019);
    for (i = 4, j = 0; i < 14; i++, j++) {
        obj->model[i] = LoadFormFile(dir | 0x10, (u16)attr);
        func_800297E8_2A3E8(obj->model[i], obj->scale.x, obj->scale.y, obj->scale.z);
        D_80108440_253AB0_SneakNSnore[j] = func_80027154_27D54(sizeof(SSLink), 0x7918);
        obj->model[i + 10] = LoadFormFile(0xD, 0x2D9);
    }
    for (i = 0; i < 10; i++) {
        if (i == 0) {
            s = HuMathSin(obj->rot.y) * 50.0f;
            c = func_800B7890_B8490(obj->rot.y) * 50.0f;
            D_80108440_253AB0_SneakNSnore[i]->pos.x = D_80108440_253AB0_SneakNSnore[i]->prev.x = obj->trans.x - s;
            D_80108440_253AB0_SneakNSnore[i]->pos.y = D_80108440_253AB0_SneakNSnore[i]->prev.y = 60.0f;
            D_80108440_253AB0_SneakNSnore[i]->pos.z = D_80108440_253AB0_SneakNSnore[i]->prev.z = obj->trans.z - c;
            D_80108440_253AB0_SneakNSnore[i]->rot.x = obj->rot.x;
            D_80108440_253AB0_SneakNSnore[i]->rot.y = obj->rot.y;
            D_80108440_253AB0_SneakNSnore[i]->rot.z = obj->rot.z;
            D_80108440_253AB0_SneakNSnore[i]->reach = 880.0f;
        } else {
            prev = D_80108440_253AB0_SneakNSnore[i - 1];
            y = prev->pos.y - 20.0f;
            if (y > 30.0f) {
                D_80108440_253AB0_SneakNSnore[i]->pos.y = y;
            } else {
                D_80108440_253AB0_SneakNSnore[i]->pos.y = 30.0f;
            }
            a = i * 36 + 90;
            D_80108440_253AB0_SneakNSnore[i]->pos.x = HuMathSin(a) * 70.0f + -60.0f;
            D_80108440_253AB0_SneakNSnore[i]->pos.z = func_800B7890_B8490(a) * 70.0f + 450.0f;
            D_80108440_253AB0_SneakNSnore[i]->rot.y = func_800B75A8_B81A8(prev->pos.x - D_80108440_253AB0_SneakNSnore[i]->pos.x, prev->pos.z - D_80108440_253AB0_SneakNSnore[i]->pos.z);
            D_80108440_253AB0_SneakNSnore[i]->prev.x = D_80108440_253AB0_SneakNSnore[i]->pos.x;
            D_80108440_253AB0_SneakNSnore[i]->prev.y = D_80108440_253AB0_SneakNSnore[i]->pos.y;
            D_80108440_253AB0_SneakNSnore[i]->prev.z = D_80108440_253AB0_SneakNSnore[i]->pos.z;
            D_80108440_253AB0_SneakNSnore[i]->reach = (f32)(10 - i) * 80.0f;
        }
        func_80029714_2A314(obj->model[i + 4], D_80108440_253AB0_SneakNSnore[i]->pos.x, D_80108440_253AB0_SneakNSnore[i]->pos.y, D_80108440_253AB0_SneakNSnore[i]->pos.z);
        func_80029714_2A314(obj->model[i + 14], D_80108440_253AB0_SneakNSnore[i]->pos.x, 20.0f, D_80108440_253AB0_SneakNSnore[i]->pos.z);
        func_800297E8_2A3E8(obj->model[i + 14], 0.5f, 0.5f, 0.5f);
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_32_SneakNSnore/24DE70", func_80104218_24F888_SneakNSnore);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_32_SneakNSnore/24DE70", func_80105574_250BE4_SneakNSnore);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_32_SneakNSnore/24DE70", func_801055AC_250C1C_SneakNSnore);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_32_SneakNSnore/24DE70", func_80105D78_2513E8_SneakNSnore);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_32_SneakNSnore/24DE70", func_80105E18_251488_SneakNSnore);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_32_SneakNSnore/24DE70", func_80105F58_2515C8_SneakNSnore);
