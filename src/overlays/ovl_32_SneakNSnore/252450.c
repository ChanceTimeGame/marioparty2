#include "ovl_32.h"

void func_80106DE0_252450_SneakNSnore(void) {
    s32 i;

    D_801084A8_253B18_SneakNSnore = rand8() >> 6;
    func_8000C460_D060();
    D_800BF7A0_C03A0 = 0.5f;
    for (i = 0; i < 4; i++) {
        D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(2, 0xB, 0x3C, -1, func_80106EA4_252514_SneakNSnore);
        omSetStatBit(D_800FFFD8_100BD8[i], 0xA0);
    }
}

void func_80106EA4_252514_SneakNSnore(omObjData* obj) {
    MgWork* w;
    s32 lane;
    s8 chr;
    s32 attr;
    u32 base;
    u32 dir;
    s32 file;
    s32 mdl;
    s32 mot;

    attr = 0xA89;
    chr = gPlayers[D_80108344_2539B4_SneakNSnore[D_80108340_2539B0_SneakNSnore]].character;
    dir = D_800CD438_CE038[chr].unk_04;
    file = D_800CD438_CE038[chr].unk_0C;
    mdl = chr + 6;
    lane = D_80108384_2539F4_SneakNSnore[D_801084A8_253B18_SneakNSnore * 4 + D_80108340_2539B0_SneakNSnore];
    base = 0x420000;
    obj->trans.x = D_80108354_2539C4_SneakNSnore[lane].x;
    obj->trans.y = D_80108354_2539C4_SneakNSnore[lane].y;
    obj->trans.z = D_80108354_2539C4_SneakNSnore[lane].z;
    obj->work[0] = 0;
    if (obj->trans.x == -225.0f) {
        obj->work[1] = 0;
    } else if (obj->trans.x == -75.0f) {
        obj->work[1] = 1;
    } else if (obj->trans.x == 75.0f) {
        obj->work[1] = 2;
    } else if (obj->trans.x == 225.0f) {
        obj->work[1] = 3;
    }
    func_8000C578_D178(1);
    func_8000C6FC_D2FC(obj, base, mdl, (u16)D_80108344_2539B4_SneakNSnore[D_80108340_2539B0_SneakNSnore], (u16)attr, attr | 0x10);
    w = obj->unk_50;
    SS_FRICTION(w) = 0.5f;
    D_800BF7E4_C03E4[w->unk_59][0] = 0x2D2;
    D_800BF7E4_C03E4[w->unk_59][1] = 0x2D2;
    D_800BF7E4_C03E4[w->unk_59][2] = 0x2D2;
    obj->model[9] = LoadFormFile(dir | file, attr | 4);
    attr = 0xA89;
    switch (dir >> 16) {
    case 2:
        obj->model[10] = LoadFormFile(base, (u16)attr);
        break;
    case 3:
        obj->model[10] = LoadFormFile(base | 1, (u16)attr);
        break;
    case 7:
        obj->model[10] = LoadFormFile(base | 2, (u16)attr);
        break;
    case 4:
        obj->model[10] = LoadFormFile(base | 3, (u16)attr);
        break;
    case 5:
        obj->model[10] = LoadFormFile(base | 4, (u16)attr);
        break;
    case 6:
        obj->model[10] = LoadFormFile(base | 5, (u16)attr);
        break;
    }
    func_800298A4_2A4A4(obj->model[10], 0x4000, 0x4000);
    func_8002C628_2D228(obj->model[10], obj->model[0], "item_hook");
    HmfModelObjAttrSet(obj->model[10], 0x20000, 0x20000);
    func_80029A8C_2A68C(obj->model[10]);
    func_8002A00C_2AC0C(obj->model[10]);
    obj->func_ptr = func_801072E8_252958_SneakNSnore;
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800297E8_2A3E8(obj->model[1], 0.0f, 0.0f, 0.0f);
    mot = dir | 0x83;
    func_80019F0C_1AB0C(obj, 0, dir | 0x82, 1, 0);
    func_80019F0C_1AB0C(obj, 1, mot, 1, 0);
    func_80019F0C_1AB0C(obj, 2, mot, 1, 0);
    func_80019F0C_1AB0C(obj, 0x10, dir | 0x84, 1, 0x3C);
    func_80019F0C_1AB0C(obj, 0x26, dir | 0x85, 1, 0);
    if ((dir >> 16) == 6) {
        func_80018CCC_198CC(obj, 0xD, dir | 0x4F);
    } else {
        func_80018CCC_198CC(obj, 0xD, dir | 0x4E);
    }
    func_80019B9C_1A79C(obj, 0);
    func_8000C024_CC24(obj, 0, 2);
    func_8000C024_CC24(obj, 1, 2);
    D_80108340_2539B0_SneakNSnore++;
}

void func_801072E8_252958_SneakNSnore(omObjData* obj) {
    omObjData* chomp;
    MgWork* w;
    s32 i;

    if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        w = obj->unk_50;
        ContStkX[w->unk_57] = 0;
        if (gPlayers[w->unk_59].flags & 1) {
            func_8010807C_2536EC_SneakNSnore(obj);
        }
        if (D_800F8FD0_F9BD0 == 1 && D_80108394_253A04_SneakNSnore[w->unk_59] == 0 && func_80019000_19C00(obj) == 4) {
            D_80108394_253A04_SneakNSnore[w->unk_59] = 1;
        }
        if (D_80108394_253A04_SneakNSnore[w->unk_59] == 1) {
            if (func_80019000_19C00(obj) == 2) {
                if (D_801083C0_253A30_SneakNSnore[w->unk_59] == 0) {
                    D_801083C0_253A30_SneakNSnore[w->unk_59] = 1;
                } else if (D_801083C0_253A30_SneakNSnore[w->unk_59] == 1 && func_80029CE4_2A8E4(obj->model[0]) == 60.0f) {
                    func_80079798_7A398(0x2BF, w->unk_59);
                    D_801083C0_253A30_SneakNSnore[w->unk_59] = 2;
                }
            } else if (func_80019000_19C00(obj) == 4) {
                if (D_801083C0_253A30_SneakNSnore[w->unk_59] != 2 || !(func_80029CE4_2A8E4(obj->model[0]) >= 1.0f)
                    || func_80079798_7A398(0x2C1, w->unk_59) != -1) {
                    D_801083C0_253A30_SneakNSnore[w->unk_59] = 0;
                }
            }
        }
        if (D_801084B0_253B20_SneakNSnore[0]->work[0] & 1) {
            ContStkY[w->unk_57] = 0;
            w->unk_40 = 0.0f;
            if (D_801083A4_253A14_SneakNSnore[w->unk_59] == 0) {
                if (func_80019000_19C00(obj) == 2) {
                    D_80108478_253AE8_SneakNSnore[w->unk_59] = func_80029CE4_2A8E4(obj->model[0]);
                } else {
                    D_80108478_253AE8_SneakNSnore[w->unk_59] = 0.0f;
                }
                D_801083A4_253A14_SneakNSnore[w->unk_59] = 1;
                D_80108488_253AF8_SneakNSnore[w->unk_59][0] = obj->trans.x;
                D_80108488_253AF8_SneakNSnore[w->unk_59][1] = obj->trans.z;
            }
        } else {
            D_801083A4_253A14_SneakNSnore[w->unk_59] = 0;
        }
        if ((SS_WORD(obj) & 0x06000000) == 0x02000000) {
            chomp = D_801084B0_253B20_SneakNSnore[0];
            obj->trans.x = chomp->trans.x + 50.0f;
            obj->trans.y = chomp->trans.y + 50.0f;
            obj->trans.z = chomp->trans.z + 50.0f;
            obj->rot.z += 10.0f;
            if (obj->rot.z >= 90.0f) {
                obj->rot.z = 90.0f;
            }
            func_80029714_2A314(obj->model[1], obj->trans.x, 0.0f, obj->trans.z);
            if (D_801083A0_253A10_SneakNSnore[w->unk_59] == 1) {
                func_80019B9C_1A79C(obj, 0x26);
                omVibrate(w->unk_59, 0x14, 0, 0x14);
                D_801083A0_253A10_SneakNSnore[w->unk_59] = 2;
                func_800797DC_7A3DC(0x2C3, w->unk_59);
            }
            func_8000C024_CC24(obj, 0, 1);
            func_8000C024_CC24(obj, 1, 1);
        } else if (obj->work[0] & 4) {
            if (D_801083C4_253A34_SneakNSnore[w->unk_59] == 0) {
                func_800797DC_7A3DC(0x2CA, w->unk_59);
                D_801083C4_253A34_SneakNSnore[w->unk_59] = 1;
            }
            obj->trans.y -= 15.0f;
            obj->trans.x -= 10.0f;
            if (obj->trans.x < D_801084B0_253B20_SneakNSnore[0]->trans.x) {
                obj->trans.x = D_801084B0_253B20_SneakNSnore[0]->trans.x;
            }
            func_80029714_2A314(obj->model[1], obj->trans.x, 0.0f, obj->trans.z);
            obj->rot.z -= 30.0f;
            if (obj->rot.z < 0.0f) {
                obj->rot.z = 0.0f;
            }
            if (obj->trans.y < 0.0f) {
                obj->trans.y = 0.0f;
                func_800298A4_2A4A4(obj->model[0], 4, 4);
                func_800298A4_2A4A4(obj->model[1], 4, 4);
                func_800298A4_2A4A4(obj->model[10], 4, 4);
            } else if (D_801083C8_253A38_SneakNSnore[w->unk_59] == 0 && obj->trans.y < 50.0f && (s16)PlaySound(0x2D0) != -1) {
                D_801083C8_253A38_SneakNSnore[w->unk_59] = 1;
            }
        }
        if (D_800F8FD0_F9BD0 == 1) {
            if (w->unk_59 == 3) {
                for (i = 0; i < 4; i++) {
                    if (D_801082F0_253960_SneakNSnore[D_800FFFD8_100BD8[i]->work[1]] == 2 && D_800FFFD8_100BD8[i]->trans.z <= -430.0f) {
                        D_800FFFD8_100BD8[i]->trans.z = -450.0f;
                        D_800FFFD8_100BD8[i]->work[0] |= 1;
                        func_80029714_2A314(D_800FFFD8_100BD8[i]->model[1], D_800FFFD8_100BD8[i]->trans.x, D_800FFFD8_100BD8[i]->trans.y - 5.0f,
                                      D_800FFFD8_100BD8[i]->trans.z);
                        func_8000C024_CC24(D_800FFFD8_100BD8[i], 0, 1);
                        func_8000C024_CC24(D_800FFFD8_100BD8[i], 1, 1);
                    }
                }
                if ((D_800FFFD8_100BD8[0]->work[0] & 1) || (D_800FFFD8_100BD8[1]->work[0] & 1) || (D_800FFFD8_100BD8[2]->work[0] & 1)
                    || (D_800FFFD8_100BD8[3]->work[0] & 1)) {
                    func_8000C398_CF98();
                    for (i = 0; i < 4; i++) {
                        if (D_801083A0_253A10_SneakNSnore[i] == 1) {
                            func_80019E04_1AA04(D_800FFFD8_100BD8[i], 0, 0x10);
                            func_80019B9C_1A79C(D_800FFFD8_100BD8[i], 0);
                            D_801083A0_253A10_SneakNSnore[i] = 0;
                        }
                    }
                }
            }
        }
        if (D_800F8FD0_F9BD0 == 1) {
            SS_FRICTION(w) = 1.2f;
            w->unk_40 *= 0.7f;
        } else {
            ContStkY[w->unk_57] = 0;
            w->unk_40 = 0.0f;
        }
        if (ContStkY[w->unk_57] > 40) {
            D_801083AC_253A1C_SneakNSnore[w->unk_57] = 1;
            D_80108398_253A08_SneakNSnore[w->unk_57]++;
            if (D_80108398_253A08_SneakNSnore[w->unk_57] > 30) {
                D_80108398_253A08_SneakNSnore[w->unk_57] = 30;
            }
        } else if (ContStkY[w->unk_57] < -40) {
            D_801083AC_253A1C_SneakNSnore[w->unk_57] = -1;
            D_80108398_253A08_SneakNSnore[w->unk_57]++;
            if (D_80108398_253A08_SneakNSnore[w->unk_57] > 30) {
                D_80108398_253A08_SneakNSnore[w->unk_57] = 30;
            }
        } else if (D_80108398_253A08_SneakNSnore[w->unk_57] > 0) {
            if (D_801083AC_253A1C_SneakNSnore[w->unk_57] > 0) {
                ContStkY[w->unk_57] = 40;
            } else if (D_801083AC_253A1C_SneakNSnore[w->unk_57] < 0) {
                ContStkY[w->unk_57] = -40;
            }
            D_80108398_253A08_SneakNSnore[w->unk_57] -= 2;
            if (D_80108398_253A08_SneakNSnore[w->unk_57] < 0) {
                D_80108398_253A08_SneakNSnore[w->unk_57] = 0;
            }
        } else if (D_80108398_253A08_SneakNSnore[w->unk_57] == 0) {
            D_801083AC_253A1C_SneakNSnore[w->unk_57] = 0;
        }
        if ((u8)(D_801083A8_253A18_SneakNSnore[w->unk_57] + 40) > 80) {
            func_80029FE4_2ABE4(obj->model[0], 0.5f);
        } else {
            func_80029FE4_2ABE4(obj->model[0], 1.0f);
        }
        if (D_801083A4_253A14_SneakNSnore[w->unk_59] == 1) {
            ContStkY[w->unk_57] = 0;
            w->unk_40 = 0.0f;
        }
        func_80007790_8390(obj);
        if (obj->work[0] & 4) {
            D_801083B0_253A20_SneakNSnore[w->unk_59] -= 0.05f;
            if (D_801083B0_253A20_SneakNSnore[w->unk_59] < 0.3f) {
                D_801083B0_253A20_SneakNSnore[w->unk_59] = 0.3f;
            }
            obj->scale.x = obj->scale.y = obj->scale.z = D_801083B0_253A20_SneakNSnore[w->unk_59];
        } else if (((u32)D_800CD438_CE038[gPlayers[w->unk_59].character].unk_04 >> 16) == 4) {
            obj->scale.x = obj->scale.y = obj->scale.z = 0.95f;
            func_800297E8_2A3E8(obj->model[10], obj->scale.x, obj->scale.y, obj->scale.z);
        }
        if (D_80108394_253A04_SneakNSnore[w->unk_59] == 1) {
            if (func_80019000_19C00(obj) == 2 && D_800F8FD0_F9BD0 == 1) {
                func_80029FE4_2ABE4(obj->model[0], 2.0f);
            } else {
                func_80029FE4_2ABE4(obj->model[0], 1.0f);
            }
        }
        if (obj->work[0] == 0 && (D_801084B0_253B20_SneakNSnore[0]->work[0] & 1)) {
            obj->trans.x = D_80108488_253AF8_SneakNSnore[w->unk_59][0];
            obj->trans.z = D_80108488_253AF8_SneakNSnore[w->unk_59][1];
        }
        if (D_800F8FD0_F9BD0 == 0) {
            obj->trans.y -= 30.0f;
            if (obj->trans.y < 0.0f) {
                obj->trans.y = 0.0f;
            }
            func_80029714_2A314(obj->model[1], obj->trans.x, 0.0f, obj->trans.z);
            D_80108470_253AE0_SneakNSnore += 0.02f;
            if (D_80108470_253AE0_SneakNSnore > 1.0f) {
                D_80108470_253AE0_SneakNSnore = 1.0f;
            }
            func_800297E8_2A3E8(obj->model[1], D_80108470_253AE0_SneakNSnore, D_80108470_253AE0_SneakNSnore, D_80108470_253AE0_SneakNSnore);
        } else {
            if (D_800F8FD0_F9BD0 == 1) {
                if (D_801083A0_253A10_SneakNSnore[w->unk_59] == 0) {
                    func_80019E04_1AA04(obj, 0, 0x10);
                    func_80019B9C_1A79C(obj, 0);
                    D_801083A0_253A10_SneakNSnore[w->unk_59] = 1;
                }
            }
            w->unk_3C = 0.0f;
            func_800B2060_B2C60(D_800FC834_FD434[obj->model[0]].mtx, w->unk_3C, w->unk_3C, w->unk_3C);
            if (obj->work[0] == 0 && obj->trans.z > 200.0f) {
                if (D_801082F0_253960_SneakNSnore[obj->work[1]] != 2) {
                    func_80079798_7A398(0x2BD, w->unk_59);
                    PlaySound(0x2D3);
                }
                D_801082F0_253960_SneakNSnore[obj->work[1]] = 2;
            }
            if (func_80019000_19C00(obj) != 2) {
                D_801083A8_253A18_SneakNSnore[w->unk_57] = ContStkY[w->unk_57];
            }
        }
    }
}

void func_8010807C_2536EC_SneakNSnore(omObjData* obj) {
    MgWork* w;
    u32 chance;

    w = obj->unk_50;
    switch (gPlayers[w->unk_59].cpu_difficulty) {
    case 0:
        chance = 50;
        break;
    case 1:
        chance = 30;
        break;
    case 2:
        chance = 10;
        break;
    case 3:
        chance = 1;
        break;
    default:
        chance = 30;
        break;
    }
    if (D_801082B4_253924_SneakNSnore == 0) {
        D_801083CC_253A3C_SneakNSnore[w->unk_57] = (u32)(rand8() * 25) >> 6;
    }
    if (D_801082F0_253960_SneakNSnore[obj->work[1]] == 1) {
        if (D_801083CC_253A3C_SneakNSnore[w->unk_57] < chance) {
            ContStkY[w->unk_57] = -30;
        } else if (D_801082B4_253924_SneakNSnore == 0) {
            if (D_80108398_253A08_SneakNSnore[w->unk_57] > 25) {
                ContStkY[w->unk_57] = -40;
            } else {
                ContStkY[w->unk_57] = -60;
            }
        } else {
            ContStkY[w->unk_57] = 0;
        }
    } else if (D_801082F0_253960_SneakNSnore[obj->work[1]] == 2) {
        if (D_801083CC_253A3C_SneakNSnore[w->unk_57] < chance) {
            ContStkY[w->unk_57] = 30;
        } else if (D_801082B4_253924_SneakNSnore == 0) {
            if (D_80108398_253A08_SneakNSnore[w->unk_57] > 25) {
                ContStkY[w->unk_57] = 40;
            } else {
                ContStkY[w->unk_57] = 60;
            }
        } else {
            ContStkY[w->unk_57] = 0;
        }
    }
}
