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

void func_80104218_24F888_SneakNSnore(omObjData* obj) {
    s16 minWait;
    s32 maxWait;
    s8 n;
    s32 i;
    s32 k;
    s32 t;
    f32 best;
    f32 d;
    f32 z;
    f32 z2;
    f32 y2;
    f32 target;

    func_80029714_2A314(obj->model[1], obj->trans.x, 30.0f, obj->trans.z);
    n = func_80105574_250BE4_SneakNSnore();
    switch (n) {
    case 0:
        minWait = 60;
        maxWait = 150;
        break;
    case 1:
    case 2:
        minWait = 50;
        maxWait = 120;
        break;
    default:
        minWait = 30;
        maxWait = 90;
        break;
    }
    if (D_80108418_253A88_SneakNSnore == 0.0f) {
        if (D_80108420_253A90_SneakNSnore >= minWait - 180) {
            D_8010841C_253A8C_SneakNSnore = 5.0f;
        } else {
            D_8010841C_253A8C_SneakNSnore = ((rand8() * 5) >> 8) + 1;
        }
    }
    if (D_800F8FD0_F9BD0 == 1 && D_801082DD_25394D_SneakNSnore == 0) {
        if (D_80108420_253A90_SneakNSnore >= D_801082D8_253948_SneakNSnore && D_80108418_253A88_SneakNSnore == 90.0f && D_8010841C_253A8C_SneakNSnore == 5.0f) {
            D_801082DD_25394D_SneakNSnore = 1;
            D_8010843B_253AAB_SneakNSnore = rand8() >> 7;
        }
    }
    if (D_801082DD_25394D_SneakNSnore != 0) {
        func_800297E8_2A3E8(obj->model[2], 0.0f, 0.0f, 0.0f);
        t = func_80029D0C_2A90C(obj->model[3]);
        if (D_80108424_253A94_SneakNSnore == 0) {
            D_801082B4_253924_SneakNSnore = 1;
            func_80029714_2A314(obj->model[3], obj->trans.x, obj->trans.y + 20.0f, obj->trans.z);
            func_800298A4_2A4A4(obj->model[3], 4, 0);
            func_80029E80_2AA80(obj->model[3], 1, 2);
            PlaySound(0x2D1);
            func_80079428_7A028(0x5A);
            D_800CD526_CE126 |= 4;
        } else if (D_80108424_253A94_SneakNSnore == t / 2) {
            func_800298A4_2A4A4(obj->model[3], 4, 4);
            func_80029E80_2AA80(obj->model[3], 1, 1);
            func_80029C74_2A874(obj->model[0], 0.0f);
            func_80103AC8_24F138_SneakNSnore(obj->model[0], D_8010846A_253ADA_SneakNSnore);
        } else if (D_80108424_253A94_SneakNSnore == 30) {
            D_800CD526_CE126 &= ~4;
        } else if (D_80108424_253A94_SneakNSnore >= 36) {
            obj->work[0] |= 1;
            D_80108424_253A94_SneakNSnore = 0;
            D_80108420_253A90_SneakNSnore = 0;
            D_80108418_253A88_SneakNSnore = 0.0f;
            D_801082D8_253948_SneakNSnore = (maxWait * rand8()) >> 8;
            if (D_801082D8_253948_SneakNSnore < minWait) {
                D_801082D8_253948_SneakNSnore = minWait;
            }
            D_801082DD_25394D_SneakNSnore = 0;
            D_801082B4_253924_SneakNSnore = 0;
        }
        if (D_801082DD_25394D_SneakNSnore != 0) {
            D_80108424_253A94_SneakNSnore++;
        }
    } else {
        if (obj->work[0] == 0 && (u32)D_800F8FD0_F9BD0 < 2) {
            if (D_80108418_253A88_SneakNSnore == 0.0f) {
                PlaySound(0x2BA);
            } else if (D_80108418_253A88_SneakNSnore == 90.0f) {
                PlaySound(0x2BB);
            }
        }
        D_80108414_253A84_SneakNSnore = HuMathSin(D_80108418_253A88_SneakNSnore) * D_8010841C_253A8C_SneakNSnore / 5.0f + 0.5f;
        D_80108414_253A84_SneakNSnore *= obj->scale.x;
        func_800297E8_2A3E8(obj->model[2], D_80108414_253A84_SneakNSnore, D_80108414_253A84_SneakNSnore, D_80108414_253A84_SneakNSnore);
        func_80029714_2A314(obj->model[2], obj->trans.x, obj->trans.y + 20.0f, obj->trans.z);
    }
    if (obj->work[0] == 0) {
        if (D_800F8FD0_F9BD0 == 1) {
            D_80108420_253A90_SneakNSnore++;
        }
        if (D_80108418_253A88_SneakNSnore == 0.0f) {
            D_80108439_253AA9_SneakNSnore = (rand8() * 3) >> 8;
            if (D_80108439_253AA9_SneakNSnore == D_8010843A_253AAA_SneakNSnore) {
                if (D_80108439_253AA9_SneakNSnore == 0) {
                    D_80108439_253AA9_SneakNSnore = 1;
                } else if (D_80108439_253AA9_SneakNSnore == 1) {
                    D_80108439_253AA9_SneakNSnore = 2;
                } else {
                    D_80108439_253AA9_SneakNSnore = 0;
                }
            }
        }
        switch (D_80108439_253AA9_SneakNSnore) {
        case 0:
            D_80108418_253A88_SneakNSnore += 2.0f;
            D_8010843A_253AAA_SneakNSnore = 0;
            break;
        case 1:
            D_80108418_253A88_SneakNSnore += 3.0f;
            D_8010843A_253AAA_SneakNSnore = 1;
            break;
        case 2:
            D_80108418_253A88_SneakNSnore += 5.0f;
            D_8010843A_253AAA_SneakNSnore = 2;
            break;
        }
        if (D_80108418_253A88_SneakNSnore >= 180.0f) {
            D_80108418_253A88_SneakNSnore = 0.0f;
        }
    }
    if (D_800F8FD0_F9BD0 != 1 && D_801082E0_253950_SneakNSnore[0] == -1 && D_801082E0_253950_SneakNSnore[1] == D_801082E0_253950_SneakNSnore[0] && D_801082E0_253950_SneakNSnore[2] == D_801082E0_253950_SneakNSnore[1]
        && D_801082E0_253950_SneakNSnore[3] == D_801082E0_253950_SneakNSnore[2]) {
        obj->work[0] = 0;
    }
    if (obj->work[0] == 1) {
        for (i = 0; i < 4; i++) {
            if (D_800FFFD8_100BD8[i]->work[0] == 0) {
                if (D_80108394_253A04_SneakNSnore[i] == 0 || func_80019000_19C00(D_800FFFD8_100BD8[i]) != 2) {
                    D_801082E0_253950_SneakNSnore[i] = ((MgWork*)D_800FFFD8_100BD8[i]->unk_50)->unk_59;
                } else if (func_80029CE4_2A8E4(D_800FFFD8_100BD8[i]->model[0]) <= 36.0f) {
                    D_801082E0_253950_SneakNSnore[i] = ((MgWork*)D_800FFFD8_100BD8[i]->unk_50)->unk_59;
                }
                if (D_800FFFD8_100BD8[i]->trans.z <= -450.0f) {
                    D_801082E0_253950_SneakNSnore[i] = -1;
                }
            }
        }
    }
    for (i = 0; i < 4; i++) {
        if (D_801082E0_253950_SneakNSnore[i] != -1) {
            if (func_80029CE4_2A8E4(D_800FFFD8_100BD8[i]->model[0]) >= 36.0f) {
                func_80029C74_2A874(D_800FFFD8_100BD8[i]->model[0], 36.0f);
            }
        }
    }
    if (D_801082E0_253950_SneakNSnore[0] == -1 && D_801082E0_253950_SneakNSnore[1] == D_801082E0_253950_SneakNSnore[0] && D_801082E0_253950_SneakNSnore[2] == D_801082E0_253950_SneakNSnore[1]
        && D_801082E0_253950_SneakNSnore[3] == D_801082E0_253950_SneakNSnore[2]) {
        obj->rot.y = func_80105D78_2513E8_SneakNSnore(obj->rot.y);
        if (ABSDIFF(350.0f - obj->rot.y) > 20.0f) {
            obj->rot.y = func_80105E18_251488_SneakNSnore(obj->rot.y, 350.0f, 20.0f);
        } else {
            obj->rot.y = 350.0f;
        }
        if (D_80108428_253A98_SneakNSnore >= 61) {
            obj->work[0] = 0;
            func_80103AC8_24F138_SneakNSnore(obj->model[0], D_8010846C_253ADC_SneakNSnore);
            D_80108428_253A98_SneakNSnore = 0;
        } else {
            D_80108428_253A98_SneakNSnore++;
        }
        if (obj->work[0] != 0) {
            func_800297E8_2A3E8(obj->model[2], 0.0f, 0.0f, 0.0f);
            func_80103AC8_24F138_SneakNSnore(obj->model[0], D_8010846A_253ADA_SneakNSnore);
        }
        if (_CheckFlag(0xC) != 0) {
            for (k = 0; k < 4; k++) {
                if (D_800F8FD0_F9BD0 == 1 && !(gPlayers[k].flags & 1) && (D_800FFFD8_100BD8[k]->work[0] & 4)) {
                    func_8000C398_CF98();
                    break;
                }
            }
        }
        if (D_800F8FD0_F9BD0 == 1 && (D_800FFFD8_100BD8[0]->work[0] & 4) && (D_800FFFD8_100BD8[1]->work[0] & 4)
            && (D_800FFFD8_100BD8[2]->work[0] & 4) && (D_800FFFD8_100BD8[3]->work[0] & 4)) {
            func_8000C398_CF98();
        }
        if ((D_800FFFD8_100BD8[0]->work[0] & 4) || (D_800FFFD8_100BD8[1]->work[0] & 4) || (D_800FFFD8_100BD8[2]->work[0] & 4)
            || (D_800FFFD8_100BD8[3]->work[0] & 4)) {
            func_801055AC_250C1C_SneakNSnore(obj);
        }
    } else {
        if (obj->work[0] != 0) {
            func_800297E8_2A3E8(obj->model[2], 0.0f, 0.0f, 0.0f);
            func_80103AC8_24F138_SneakNSnore(obj->model[0], D_8010846A_253ADA_SneakNSnore);
        }
        best = 1500000.0f;
        for (i = 0; i < 4; i++) {
            if (D_801082E0_253950_SneakNSnore[i] != -1) {
                f32 x2;
                f32 z3;

                x2 = D_800FFFD8_100BD8[i]->trans.x - obj->trans.x;
                x2 *= x2;
                z3 = D_800FFFD8_100BD8[i]->trans.z - obj->trans.z;
                z3 *= z3;
                d = x2 + z3;
                if (d < best) {
                    best = d;
                    D_80108438_253AA8_SneakNSnore = i;
                }
            }
        }
        if (obj->work[0] == 1) {
            if (D_801082DC_25394C_SneakNSnore == 0) {
                D_8010842C_253A9C_SneakNSnore.x = D_800FFFD8_100BD8[D_80108438_253AA8_SneakNSnore]->trans.x;
                D_8010842C_253A9C_SneakNSnore.z = D_800FFFD8_100BD8[D_80108438_253AA8_SneakNSnore]->trans.z;
                D_801082DC_25394C_SneakNSnore = 1;
            }
            target = func_80105D78_2513E8_SneakNSnore(func_800B75A8_B81A8(D_8010842C_253A9C_SneakNSnore.x - obj->trans.x, D_8010842C_253A9C_SneakNSnore.z - obj->trans.z));
            obj->rot.y = func_80105D78_2513E8_SneakNSnore(obj->rot.y);
            if (ABSDIFF(target - obj->rot.y) > 10.0f) {
                if (D_8010843B_253AAB_SneakNSnore == 0) {
                    obj->rot.y = func_80105E18_251488_SneakNSnore(obj->rot.y, target, 10.0f);
                } else {
                    obj->rot.y = func_80105E18_251488_SneakNSnore(obj->rot.y, target, 20.0f);
                }
            } else {
                f32 zb;

                d = D_8010842C_253A9C_SneakNSnore.x - obj->trans.x;
                d *= d;
                zb = D_8010842C_253A9C_SneakNSnore.z - obj->trans.z;
                zb *= zb;
                d += zb;
                if (d <= 900.0f) {
                    D_800FFFD8_100BD8[D_80108438_253AA8_SneakNSnore]->work[0] |= 2;
                    obj->work[0] |= 2;
                    PlaySound(0x2C0);
                } else {
                    obj->trans.x += HuMathSin(obj->rot.y) * 30.0f;
                    obj->trans.z += func_800B7890_B8490(obj->rot.y) * 30.0f;
                }
                func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[2]), 0, 0x32, 2);
            }
        } else if (obj->work[0] & 2) {
            D_8010842C_253A9C_SneakNSnore.x = 250.0f;
            D_8010842C_253A9C_SneakNSnore.y = 150.0f;
            D_8010842C_253A9C_SneakNSnore.z = 450.0f;
            target = func_80105D78_2513E8_SneakNSnore(func_800B75A8_B81A8(250.0f - obj->trans.x, 450.0f - obj->trans.z));
            obj->rot.y = func_80105D78_2513E8_SneakNSnore(obj->rot.y);
            if (ABSDIFF(target - obj->rot.y) > 20.0f && obj->trans.z < 450.0f) {
                obj->rot.y = func_80105E18_251488_SneakNSnore(obj->rot.y, target, 20.0f);
            } else {
                d = D_8010842C_253A9C_SneakNSnore.x - obj->trans.x;
                d *= d;
                z2 = D_8010842C_253A9C_SneakNSnore.z - obj->trans.z;
                z2 *= z2;
                y2 = D_8010842C_253A9C_SneakNSnore.y - obj->trans.y;
                y2 *= y2;
                obj->rot.x = func_800B75A8_B81A8(y2, d + z2);
                if (obj->trans.z >= 450.0f) {
                    obj->rot.y = 0.0f;
                    obj->work[0] = (obj->work[0] | 4) & 0xFD;
                } else {
                    obj->trans.x += HuMathSin(obj->rot.y) * 30.0f;
                    if (obj->trans.x > 250.0f) {
                        obj->trans.x = 250.0f;
                    }
                    obj->trans.y += HuMathSin(obj->rot.x) * 30.0f;
                    if (obj->trans.y > 150.0f) {
                        obj->trans.y = 150.0f;
                    }
                    obj->trans.z += func_800B7890_B8490(obj->rot.y) * 30.0f;
                }
            }
        } else if (obj->work[0] & 4) {
            D_800FFFD8_100BD8[D_80108438_253AA8_SneakNSnore]->work[0] |= 4;
            if (D_800FFFD8_100BD8[D_80108438_253AA8_SneakNSnore]->trans.y <= 0.0f) {
                obj->work[0] = (obj->work[0] | 8) & 0xFB;
                func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[0]), 0, 0x31, 2);
            }
        } else if (obj->work[0] & 8) {
            D_8010842C_253A9C_SneakNSnore.x = 100.0f;
            D_8010842C_253A9C_SneakNSnore.y = 30.0f;
            D_8010842C_253A9C_SneakNSnore.z = 550.0f;
            d = D_8010842C_253A9C_SneakNSnore.x - obj->trans.x;
            d *= d;
            z = D_8010842C_253A9C_SneakNSnore.z - obj->trans.z;
            z *= z;
            d += z;
            if (d <= D_8010842C_253A9C_SneakNSnore.x) {
                obj->rot.x = func_80105E18_251488_SneakNSnore(obj->rot.x, 0.0f, 10.0f);
                if (obj->rot.x == 0.0f && obj->rot.z == 20.0f) {
                    D_801082E0_253950_SneakNSnore[D_80108438_253AA8_SneakNSnore] = -1;
                    D_801082DC_25394C_SneakNSnore = 0;
                    if (!(D_801082E0_253950_SneakNSnore[0] == -1 && D_801082E0_253950_SneakNSnore[1] == D_801082E0_253950_SneakNSnore[0] && D_801082E0_253950_SneakNSnore[2] == D_801082E0_253950_SneakNSnore[1]
                          && D_801082E0_253950_SneakNSnore[3] == D_801082E0_253950_SneakNSnore[2])) {
                        obj->work[0] = 1;
                    }
                }
                if (D_801082E0_253950_SneakNSnore[0] == -1 && D_801082E0_253950_SneakNSnore[1] == D_801082E0_253950_SneakNSnore[0] && D_801082E0_253950_SneakNSnore[2] == D_801082E0_253950_SneakNSnore[1]
                    && D_801082E0_253950_SneakNSnore[3] == D_801082E0_253950_SneakNSnore[2]) {
                    obj->rot.y = func_80105E18_251488_SneakNSnore(obj->rot.y, 350.0f, 20.0f);
                    func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[1]), 0, 0x50, 2);
                }
            } else {
                target = func_80105D78_2513E8_SneakNSnore(func_800B75A8_B81A8(D_8010842C_253A9C_SneakNSnore.x - obj->trans.x, D_8010842C_253A9C_SneakNSnore.z - obj->trans.z));
                obj->rot.y = func_80105D78_2513E8_SneakNSnore(obj->rot.y);
                obj->rot.y = func_80105E18_251488_SneakNSnore(obj->rot.y, target, 20.0f);
                {
                    f32 y3;

                    y3 = D_8010842C_253A9C_SneakNSnore.y - obj->trans.y;
                    y3 *= y3;
                    obj->rot.x = func_800B75A8_B81A8(y3, d);
                }
                obj->trans.x += HuMathSin(obj->rot.y) * 10.0f;
                obj->trans.y -= HuMathSin(obj->rot.x) * 10.0f;
                obj->trans.z += func_800B7890_B8490(obj->rot.y) * 10.0f;
            }
        }
        func_801055AC_250C1C_SneakNSnore(obj);
    }
}

s8 func_80105574_250BE4_SneakNSnore(void) {
    s8 n;
    s32 i;

    n = 0;
    for (i = 0; i < 4; i++) {
        if (D_801082F0_253960_SneakNSnore[i] == 2) {
            n++;
        }
    }
    return n;
}

#ifdef NON_MATCHING /* the one shift retail recomputes (sll before D_80108440_253AB0_SneakNSnore[i]), s5/s6 labels and f2/f4 in one square: masked 23 */
void func_801055AC_250C1C_SneakNSnore(omObjData* obj) {
    SSLink* a;
    SSLink* b;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 y1;
    f32 z1;
    f32 x3;
    f32 y3;
    f32 z3;
    f32 step;
    f32 r;
    f32 t;
    f32 angle;
    Vec from;
    Vec to;
    Vec dir;
    s32 i;

    step = D_80108440_253AB0_SneakNSnore[0]->prev.x - D_80108440_253AB0_SneakNSnore[0]->pos.x;
    step *= step;
    y1 = D_80108440_253AB0_SneakNSnore[0]->prev.y - D_80108440_253AB0_SneakNSnore[0]->pos.y;
    y1 *= y1;
    step += y1;
    z1 = D_80108440_253AB0_SneakNSnore[0]->prev.z - D_80108440_253AB0_SneakNSnore[0]->pos.z;
    z1 *= z1;
    step = func_800B1830_B2430(step + z1);
    D_801082E4_253954_SneakNSnore += step;
    for (i = 0; i < 10; i++) {
        dx = 0.0f - D_80108440_253AB0_SneakNSnore[i]->pos.x;
        dx *= dx;
        dy = 20.0f - D_80108440_253AB0_SneakNSnore[i]->pos.y;
        dy *= dy;
        dx += dy;
        dz = 500.0f - D_80108440_253AB0_SneakNSnore[i]->pos.z;
        dz *= dz;
        r = func_800B1830_B2430(dx + dz);
        if (i == 0) {
            if (D_801082E4_253954_SneakNSnore >= 80.0f) {
                D_80108440_253AB0_SneakNSnore[0]->prev.x = D_80108440_253AB0_SneakNSnore[0]->pos.x;
                D_80108440_253AB0_SneakNSnore[0]->prev.y = D_80108440_253AB0_SneakNSnore[0]->pos.y;
                D_80108440_253AB0_SneakNSnore[0]->prev.z = D_80108440_253AB0_SneakNSnore[0]->pos.z;
            }
            D_80108440_253AB0_SneakNSnore[0]->rot.x = obj->rot.x;
            D_80108440_253AB0_SneakNSnore[0]->rot.y = obj->rot.y;
            D_80108440_253AB0_SneakNSnore[0]->pos.x = obj->trans.x - HuMathSin(obj->rot.y) * 10.0f;
            D_80108440_253AB0_SneakNSnore[0]->pos.y = obj->trans.y - HuMathSin(obj->rot.x) * 10.0f;
            {
                SSLink* l = D_80108440_253AB0_SneakNSnore[i];
                f32 y = l->pos.y;

                if (y < 30.0f) {
                    l->pos.y = 30.0f;
                }
            }
            D_80108440_253AB0_SneakNSnore[0]->pos.z = obj->trans.z - func_800B7890_B8490(obj->rot.y) * 10.0f;
        } else {
            if (D_801082E4_253954_SneakNSnore >= 80.0f) {
                D_80108440_253AB0_SneakNSnore[i]->prev.x = D_80108440_253AB0_SneakNSnore[i]->pos.x;
                D_80108440_253AB0_SneakNSnore[i]->prev.y = D_80108440_253AB0_SneakNSnore[i]->pos.y;
                D_80108440_253AB0_SneakNSnore[i]->prev.z = D_80108440_253AB0_SneakNSnore[i]->pos.z;
                if (i == 9 && D_801082E4_253954_SneakNSnore >= 80.0f) {
                    D_801082E4_253954_SneakNSnore -= 80.0f;
                }
            }
            a = D_80108440_253AB0_SneakNSnore[i - 1];
            if (D_80108440_253AB0_SneakNSnore[i]->reach <= r) {
                from.x = D_80108440_253AB0_SneakNSnore[i]->pos.x;
                from.y = D_80108440_253AB0_SneakNSnore[i]->pos.y;
                from.z = D_80108440_253AB0_SneakNSnore[i]->pos.z;
                x3 = a->prev.x - D_80108440_253AB0_SneakNSnore[i]->pos.x;
                x3 *= x3;
                y3 = a->prev.y - D_80108440_253AB0_SneakNSnore[i]->pos.y;
                y3 *= y3;
                x3 += y3;
                z3 = a->prev.z - D_80108440_253AB0_SneakNSnore[i]->pos.z;
                z3 *= z3;
                if (func_800B1830_B2430(x3 + z3) > 80.0f) {
                    angle = func_800B75A8_B81A8(a->prev.x - 0.0f, a->prev.z - 500.0f);
                    to.x = HuMathSin(angle) * D_80108440_253AB0_SneakNSnore[i]->reach + 0.0f;
                    to.y = a->pos.y;
                    to.z = func_800B7890_B8490(angle) * D_80108440_253AB0_SneakNSnore[i]->reach + 500.0f;
                } else {
                    to.x = (0.0f - obj->trans.x) * (t = i) / 10.0f + obj->trans.x;
                    to.y = (20.0f - obj->trans.y) * t / 10.0f + obj->trans.y;
                    to.z = (500.0f - obj->trans.z) * t / 10.0f + obj->trans.z;
                }
            } else {
                from.x = D_80108440_253AB0_SneakNSnore[i]->pos.x;
                from.y = D_80108440_253AB0_SneakNSnore[i]->pos.y;
                from.z = D_80108440_253AB0_SneakNSnore[i]->pos.z;
                to.x = a->prev.x;
                to.y = a->prev.y;
                to.z = a->prev.z;
            }
            func_80105F58_2515C8_SneakNSnore(&dir, &from, &to);
            D_80108440_253AB0_SneakNSnore[i]->pos.x += step * dir.x;
            D_80108440_253AB0_SneakNSnore[i]->pos.z += step * dir.z;
            if (dir.x > 0.0f && D_80108440_253AB0_SneakNSnore[i]->pos.x > to.x) {
                D_80108440_253AB0_SneakNSnore[i]->pos.x = to.x;
            } else if (dir.x < 0.0f && D_80108440_253AB0_SneakNSnore[i]->pos.x < to.x) {
                D_80108440_253AB0_SneakNSnore[i]->pos.x = to.x;
            }
            if (dir.y > 0.0f && D_80108440_253AB0_SneakNSnore[i]->pos.y > to.y) {
                D_80108440_253AB0_SneakNSnore[i]->pos.y = to.y;
            } else if (dir.y < 0.0f && D_80108440_253AB0_SneakNSnore[i]->pos.y < to.y) {
                D_80108440_253AB0_SneakNSnore[i]->pos.y = to.y;
            }
            if (dir.z > 0.0f && D_80108440_253AB0_SneakNSnore[i]->pos.z > to.z) {
                D_80108440_253AB0_SneakNSnore[i]->pos.z = to.z;
            } else if (dir.z < 0.0f && D_80108440_253AB0_SneakNSnore[i]->pos.z < to.z) {
                D_80108440_253AB0_SneakNSnore[i]->pos.z = to.z;
            }
            D_80108440_253AB0_SneakNSnore[i]->pos.y += step * dir.y;
        }
        func_80029714_2A314(obj->model[i + 4], D_80108440_253AB0_SneakNSnore[i]->pos.x, D_80108440_253AB0_SneakNSnore[i]->pos.y, D_80108440_253AB0_SneakNSnore[i]->pos.z);
        func_80029714_2A314(obj->model[i + 14], D_80108440_253AB0_SneakNSnore[i]->pos.x, 20.0f, D_80108440_253AB0_SneakNSnore[i]->pos.z);
    }
    for (i = 1; i < 9; i++) {
        a = D_80108440_253AB0_SneakNSnore[i - 1];
        b = D_80108440_253AB0_SneakNSnore[i + 1];
        if (obj->work[0] != 0) {
            D_80108440_253AB0_SneakNSnore[i]->pos.x = (a->prev.x + b->pos.x) / 2.0f;
            D_80108440_253AB0_SneakNSnore[i]->pos.y = (a->prev.y + b->pos.y) / 2.0f;
            D_80108440_253AB0_SneakNSnore[i]->pos.z = (a->prev.z + b->pos.z) / 2.0f;
        }
        if ((obj->work[0] & 8) || obj->work[0] == 0) {
            D_80108440_253AB0_SneakNSnore[i]->pos.y -= 8.0f;
        }
        if (D_80108440_253AB0_SneakNSnore[i]->pos.y < 30.0f) {
            D_80108440_253AB0_SneakNSnore[i]->pos.y = 30.0f;
        }
        func_80029714_2A314(obj->model[i + 4], D_80108440_253AB0_SneakNSnore[i]->pos.x, D_80108440_253AB0_SneakNSnore[i]->pos.y, D_80108440_253AB0_SneakNSnore[i]->pos.z);
        func_80029714_2A314(obj->model[i + 14], D_80108440_253AB0_SneakNSnore[i]->pos.x, 20.0f, D_80108440_253AB0_SneakNSnore[i]->pos.z);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_32_SneakNSnore/24DE70", func_801055AC_250C1C_SneakNSnore);
#endif

f32 func_80105D78_2513E8_SneakNSnore(f32 a) {
    if (a < 0.0f) {
        while (a < 0.0f) {
            a += 360.0f;
        }
    } else if (a >= 360.0f) {
        while (a >= 360.0f) {
            a -= 360.0f;
        }
    }
    return a;
}

#ifdef NON_MATCHING /* retail keeps a in f4 and step in f12; last return shape differs: masked 11 */
f32 func_80105E18_251488_SneakNSnore(f32 a, f32 target, f32 step) {
    f32 d = target - a;
    f32 s = step;

    if ((-s < d) & (d < s)) {
        return target;
    }
    if (d <= -180.0f) {
        return a + s;
    }
    if ((d <= 180.0f) & (d >= 0.0f)) {
        return a + s;
    }
    if (d > 180.0f) {
        return a - s;
    }
    if (!((d > -180.0f) & (d < 0.0f))) {
        return target;
    }
    return a - s;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_32_SneakNSnore/24DE70", func_80105E18_251488_SneakNSnore);
#endif

void func_80105F58_2515C8_SneakNSnore(Vec* out, Vec* from, Vec* to) {
    f32 len;

    out->x = to->x - from->x;
    out->y = to->y - from->y;
    out->z = to->z - from->z;
    len = out->x * out->x + out->y * out->y + out->z * out->z;
    len = func_800B1830_B2430(len);
    if (len != 0.0f) {
        out->x /= len;
        out->y /= len;
        out->z /= len;
    }
}
