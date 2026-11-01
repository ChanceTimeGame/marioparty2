#include "ovl_27.h"

#define ABSDIFF(x) ((x) > 0.0f ? (x) : (0.0f - (x)))

void func_80106C40_2032A0_AbandonShip(void) {
    s32 i;

    D_8010960C_205C6C_AbandonShip = rand8() >> 6;
    func_8000C460_D060();
    D_800BF7A0_C03A0 = 0.5f;
    for (i = 0; i < 4; i++) {
        D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(2, 2, 0x3C, -1, func_80106D04_203364_AbandonShip);
        omSetStatBit(D_800FFFD8_100BD8[i], 0xA0);
    }
}

void func_80106D04_203364_AbandonShip(omObjData* obj) {
    u32 dir;
    s32 file;
    s32 chr;
    s32 lane;

    chr = *(s8*)&gPlayers[D_80109444_205AA4_AbandonShip[D_80109442_205AA2_AbandonShip]].character;
    dir = D_800CD438_CE038[chr].unk_04;
    file = D_800CD438_CE038[chr].unk_08;
    lane = D_80109484_205AE4_AbandonShip[D_8010960C_205C6C_AbandonShip * 4 + D_80109442_205AA2_AbandonShip];
    obj->work[0] = lane;
    obj->trans.x = D_80109454_205AB4_AbandonShip[lane].x;
    obj->trans.y = D_80109454_205AB4_AbandonShip[lane].y;
    obj->trans.z = D_80109454_205AB4_AbandonShip[lane].z;
    obj->rot.y = 90.0f;
    func_8000C578_D178(1);
    func_8000C6FC_D2FC(obj, dir, file, (u16)D_80109444_205AA4_AbandonShip[D_80109442_205AA2_AbandonShip], 0x2A9, 0x2B9);
    obj->func_ptr = func_80106F5C_2035BC_AbandonShip;
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800297E8_2A3E8(obj->model[1], obj->scale.x, obj->scale.y, obj->scale.z);
    func_80018CCC_198CC(obj, 0, dir);
    func_80018CCC_198CC(obj, 0xD, dir | 0x4E);
    func_80018CCC_198CC(obj, 6, dir | 4);
    func_80018CCC_198CC(obj, 0x10, dir | 0xE);
    func_80018CCC_198CC(obj, 0xF, dir | 0xA);
    func_80018CCC_198CC(obj, 0x26, dir | 0xA4);
    func_80018CCC_198CC(obj, 0x27, dir | 0x8C);
    func_80018CCC_198CC(obj, 0x28, dir | 0x8B);
    func_80029BF0_2A7F0(obj->model[0], (s16)func_80029E14_2AA14(obj->motion[0]), 0, 0x1E, 2);
    obj->work[1] = 0;
    obj->work[2] = 1;
    obj->work[3] = 0;
    func_8000C024_CC24(obj, 0, 2);
    D_80109442_205AA2_AbandonShip++;
}

void func_80106F5C_2035BC_AbandonShip(omObjData* obj) {
    Vec pos;
    Vec2f scr;
    MgWork* w;
    omObjData* o;
    f32 f;
    f32 speed;
    f32 s;
    s32 grab;
    s32 t;
    s32 i;
    s8 n;
    u32 r;

    if (func_80078EA8_79AA8() + D_80102720_103320 != 0) {
        return;
    }
    func_80029714_2A314(obj->model[1], obj->trans.x, D_801093D8_205A38_AbandonShip, obj->trans.z);
    w = obj->unk_50;
    switch (D_801093C0_205A20_AbandonShip) {
    case 0:
        obj->trans.x += 10.0f;
        obj->trans.y = D_801093D4_205A34_AbandonShip + 330.0f;
        break;
    case 1:
        if (D_8010949C_205AFC_AbandonShip[w->unk_59] < 5) {
            obj->trans.y += 30.0f;
            if (D_8010949C_205AFC_AbandonShip[w->unk_59] == 0) {
                omVibrate(w->unk_59, 2, 2, 0x14);
            }
        } else {
            obj->trans.y -= 30.0f;
        }
        D_8010949C_205AFC_AbandonShip[w->unk_59]++;
        break;
    case 2:
        D_8010949C_205AFC_AbandonShip[w->unk_59] = 0;
        obj->trans.x += 800.0f;
        obj->trans.y = 35.0f;
        obj->trans.z = 50.0f;
        obj->rot.y = 240.0f;
        break;
    case 3:
        obj->trans.x -= 30.0f;
        if (obj->work[1] == 0) {
            func_80029BF0_2A7F0(obj->model[0], (s16)func_80029E14_2AA14(obj->motion[0x26]), 0, 0x1E, 2);
            func_800797DC_7A3DC(0x111, w->unk_59);
            obj->work[1] = 1;
        }
        f = D_801093C4_205A24_AbandonShip[obj->work[0]] + 40.0f;
        if (obj->trans.x < f) {
            obj->trans.x = f;
            if (obj->work[1] == 1) {
                obj->work[1] = 2;
            } else if (obj->work[1] == 2) {
                func_80029BF0_2A7F0(obj->model[0], (s16)func_80029E14_2AA14(obj->motion[0x28]), 0, 0x1E, 2);
                func_80029E80_2AA80(obj->model[0], 1, 1);
                obj->work[1] = 3;
            }
        }
        break;
    case 4:
        obj->work[1] = 4;
        break;
    }
    if (D_800F8FD0_F9BD0 == 1) {
        s = 1.0f - -D_801093D8_205A38_AbandonShip / 100.0f;
        if (s < 0.0f) {
            s = 0.0f;
        }
        func_800297E8_2A3E8(obj->model[1], s, s, s);
        if (D_801093D8_205A38_AbandonShip < -30.0f && w->unk_59 == 0 && D_800FFFD8_100BD8[0]->trans.y < 0.0f &&
            D_800FFFD8_100BD8[1]->trans.y < 0.0f && D_800FFFD8_100BD8[2]->trans.y < 0.0f &&
            D_800FFFD8_100BD8[3]->trans.y < 0.0f) {
            D_801093C0_205A20_AbandonShip = 6;
            D_80109380_2059E0_AbandonShip = 0;
            func_8000C398_CF98();
        }
        if (obj->trans.y < 0.0f && obj->work[1] < 7) {
            func_80029BF0_2A7F0(obj->model[0], (s16)func_80029E14_2AA14(obj->motion[0x10]), 0, 0x1E, 2);
            omVibrate(w->unk_59, 0x14, 0, 0x14);
            func_80079798_7A398(0x9D, w->unk_59);
            func_800797DC_7A3DC(0x111, w->unk_59);
            func_800298A4_2A4A4(obj->model[0], 4, 0);
            func_800298A4_2A4A4(obj->model[1], 4, 4);
            obj->work[1] = 7;
            return;
        }
        if (obj->work[1] == 7) {
            func_801089A4_205004_AbandonShip(obj, 1.0f);
            if (obj->work[2] == 1) {
                obj->trans.x += 20.0f;
                if (D_801093C4_205A24_AbandonShip[obj->work[0]] + 150.0f < obj->trans.x) {
                    obj->trans.x = D_801093C4_205A24_AbandonShip[obj->work[0]] + 150.0f;
                }
            } else {
                obj->trans.x -= 20.0f;
                if (obj->trans.x < D_801093C4_205A24_AbandonShip[obj->work[0]] - 150.0f) {
                    obj->trans.x = D_801093C4_205A24_AbandonShip[obj->work[0]] - 150.0f;
                }
            }
            obj->trans.y = D_801093D4_205A34_AbandonShip / 2.0f + 0.0f;
            if (_CheckFlag(0xC) != 0 && !(gPlayers[w->unk_59].flags & 1) && D_801093D8_205A38_AbandonShip < -100.0f) {
                D_801093C0_205A20_AbandonShip = 6;
                D_80109380_2059E0_AbandonShip = 2;
                func_8000C398_CF98();
            }
        } else if (obj->work[1] == 8) {
            D_8010949C_205AFC_AbandonShip[w->unk_59] = 0;
            func_80029BF0_2A7F0(obj->model[0], (s16)func_80029E14_2AA14(obj->motion[0xF]), 0, 0x1E, 2);
            obj->work[1] = 9;
        } else if (obj->work[1] != 9) {
            if (obj->work[1] == 10) {
                func_800298A4_2A4A4(obj->model[0], 4, 4);
                return;
            }
            if (D_801093D8_205A38_AbandonShip + 4475.0f <= obj->trans.y) {
                D_8010949C_205AFC_AbandonShip[0] = D_8010949C_205AFC_AbandonShip[1] = D_8010949C_205AFC_AbandonShip[2] = D_8010949C_205AFC_AbandonShip[3] = 0;
                D_801093C0_205A20_AbandonShip = 6;
                D_80109380_2059E0_AbandonShip = 1;
                func_8000C398_CF98();
                return;
            }
            if (gPlayers[w->unk_59].flags & 1) {
                func_80108EA0_205500_AbandonShip(obj);
            }
            D_80109600_205C60_AbandonShip[w->unk_57] = ContBtnTrg[w->unk_57];
            n = 0;
            for (i = 0; i < 8; i++) {
                if (D_801096B8_205D18_AbandonShip[i] - 50.0f <= obj->trans.y) {
                    n++;
                }
                if (ABSDIFF(obj->trans.y + 60.0f - D_801096B8_205D18_AbandonShip[i]) < 110.0f) {
                    ContStkX[w->unk_57] = 0;
                }
                if (ABSDIFF(obj->trans.y + 120.0f - D_801096B8_205D18_AbandonShip[i]) <= 50.0f) {
                    if (obj->work[2] == 0 && D_801093DC_205A3C_AbandonShip[D_801096B0_205D10_AbandonShip][i] == 0) {
                        obj->work[3] = 1;
                    } else if (obj->work[2] == 1 && D_801093DC_205A3C_AbandonShip[D_801096B0_205D10_AbandonShip][i] == 1) {
                        obj->work[3] = 1;
                    }
                    break;
                }
            }
            grab = 0;
            if (obj->work[3] == 1 || obj->work[3] == 2) {
                D_80109600_205C60_AbandonShip[w->unk_57] &= 0x7FFF;
                ContStkX[w->unk_57] = 0;
                for (i = 0; i < n; i++) {
                    if (obj->trans.y + 120.0f <= D_801096B8_205D18_AbandonShip[i] - 50.0f) {
                        break;
                    }
                    if (D_801096B8_205D18_AbandonShip[i] - 100.0f <= obj->trans.y) {
                        if (ABSDIFF(obj->trans.y - D_801096B8_205D18_AbandonShip[i]) <= 100.0f) {
                            if (obj->work[2] == 0 && D_801093DC_205A3C_AbandonShip[D_801096B0_205D10_AbandonShip][i] == 0) {
                                obj->trans.y = D_801096B8_205D18_AbandonShip[i] + 100.0f;
                                grab = 1;
                            } else if (obj->work[2] == 1 && D_801093DC_205A3C_AbandonShip[D_801096B0_205D10_AbandonShip][i] == 1) {
                                obj->trans.y = D_801096B8_205D18_AbandonShip[i] + 100.0f;
                                grab = 1;
                            }
                            break;
                        }
                    }
                }
                t = obj->work[1] == 4;
                if (t & (grab ^ 1)) {
                    obj->trans.y -= 9.0f;
                }
                if (D_801094AC_205B0C_AbandonShip[w->unk_59] == 0) {
                    func_800298A4_2A4A4(obj->model[0], 4, 4);
                } else {
                    func_800298A4_2A4A4(obj->model[0], 4, 0);
                }
                D_801094AC_205B0C_AbandonShip[w->unk_59] ^= 1;
                if (D_8010949C_205AFC_AbandonShip[w->unk_59] == 0 && obj->work[1] < 7) {
                    omVibrate(w->unk_59, 0xA, 0, 0xA);
                }
                D_8010949C_205AFC_AbandonShip[w->unk_59]++;
                if (D_8010949C_205AFC_AbandonShip[w->unk_59] >= 16) {
                    D_8010949C_205AFC_AbandonShip[w->unk_59] = 0;
                    obj->work[3] = 0;
                    func_800298A4_2A4A4(obj->model[0], 4, 0);
                } else if (obj->trans.y <= 0.0f) {
                    func_800298A4_2A4A4(obj->model[0], 4, 0);
                }
            }
            if (ContStkX[w->unk_57] != 0) {
                if (ContStkX[w->unk_57] < 0 && obj->work[1] == 4 && obj->work[2] != 0) {
                    obj->work[1] = 5;
                } else if (ContStkX[w->unk_57] > 0 && obj->work[1] == 4 && obj->work[2] != 1) {
                    obj->work[1] = 6;
                }
            }
            if (obj->work[1] == 5 || obj->work[1] == 6) {
                D_80109600_205C60_AbandonShip[w->unk_57] &= 0x7FFF;
                D_801094B4_205B14_AbandonShip[w->unk_59] = 0.0f;
                if (D_801094B0_205B10_AbandonShip[w->unk_59] >= 16) {
                    if (obj->work[1] == 5) {
                        obj->work[2] = 0;
                    } else if (obj->work[1] == 6) {
                        obj->work[2] = 1;
                    }
                    D_801094B0_205B10_AbandonShip[w->unk_59] = 0;
                    obj->work[1] = 4;
                } else {
                    D_801094B0_205B10_AbandonShip[w->unk_59]++;
                }
            }
            switch (obj->work[1]) {
            case 5:
                if (obj->work[2] != 0) {
                    obj->rot.y = 270.0f - D_801094B0_205B10_AbandonShip[w->unk_59] * 150.0f / 15.0f;
                    obj->trans.x = D_801093C4_205A24_AbandonShip[obj->work[0]] + 75.0f - D_801094B0_205B10_AbandonShip[w->unk_59] * 100.0f / 15.0f;
                }
                break;
            case 6:
                if (obj->work[2] != 1) {
                    obj->rot.y = D_801094B0_205B10_AbandonShip[w->unk_59] * 150.0f / 15.0f + 90.0f;
                    obj->trans.x = D_801093C4_205A24_AbandonShip[obj->work[0]] - 75.0f + D_801094B0_205B10_AbandonShip[w->unk_59] * 100.0f / 15.0f;
                }
                break;
            }
            if (D_80109600_205C60_AbandonShip[w->unk_57] & 0x8000) {
                if (func_80029CE4_2A8E4(obj->model[0]) == 0.0f) {
                    func_80079798_7A398(0x281, w->unk_59);
                }
                pos.x = obj->trans.x;
                pos.y = obj->trans.y;
                pos.z = obj->trans.z;
                Hu3DCam3DToScreen(0, &pos, &scr);
                if (scr.unk_04 <= 75.0f) {
                    speed = 1.0f;
                    if (func_80029CE4_2A8E4(obj->model[0]) == 0.0f) {
                        func_80029FE4_2ABE4(obj->model[0], speed);
                    }
                } else {
                    speed = 3.0f;
                    if (func_80029CE4_2A8E4(obj->model[0]) == 0.0f) {
                        func_80029FE4_2ABE4(obj->model[0], 2.0f);
                    }
                }
            } else {
                speed = 0.0f;
                if (func_80029CE4_2A8E4(obj->model[0]) == 0.0f) {
                    func_80029FE4_2ABE4(obj->model[0], speed);
                }
            }
            if (speed < D_801094B4_205B14_AbandonShip[w->unk_59]) {
                D_801094B4_205B14_AbandonShip[w->unk_59] -= 0.5f;
                if (D_801094B4_205B14_AbandonShip[w->unk_59] < speed) {
                    D_801094B4_205B14_AbandonShip[w->unk_59] = speed;
                }
            } else if (D_801094B4_205B14_AbandonShip[w->unk_59] < speed) {
                D_801094B4_205B14_AbandonShip[w->unk_59] += 3.0f;
                if (speed < D_801094B4_205B14_AbandonShip[w->unk_59]) {
                    D_801094B4_205B14_AbandonShip[w->unk_59] = speed;
                }
            }
            if (obj->work[3] == 0) {
                obj->trans.y += D_801094B4_205B14_AbandonShip[w->unk_59] * 7.5f;
            }
            for (i = 0; i < 8; i++) {
                if (speed == 0.0f) {
                    break;
                }
                if (obj->trans.y < D_801096B8_205D18_AbandonShip[i] - 100.0f) {
                    if (ABSDIFF(obj->trans.y + 120.0f - D_801096B8_205D18_AbandonShip[i]) <= 50.0f) {
                        if (obj->work[2] == 0 && D_801093DC_205A3C_AbandonShip[D_801096B0_205D10_AbandonShip][i] == 0) {
                            obj->trans.y = D_801096B8_205D18_AbandonShip[i] - 50.0f - 120.0f;
                            D_801094B4_205B14_AbandonShip[w->unk_59] = 0.0f;
                        } else if (obj->work[2] == 1 && D_801093DC_205A3C_AbandonShip[D_801096B0_205D10_AbandonShip][i] == 1) {
                            obj->trans.y = D_801096B8_205D18_AbandonShip[i] - 50.0f - 120.0f;
                            D_801094B4_205B14_AbandonShip[w->unk_59] = 0.0f;
                        }
                        break;
                    }
                }
            }
            func_80029E80_2AA80(obj->model[0], 1, 2);
            obj->trans.y -= 7.5f;
        }
    } else if (D_800F8FD0_F9BD0 == 2 || D_800F8FD0_F9BD0 == 3) {
        func_80029FE4_2ABE4(obj->model[0], 1.0f);
        if (obj->work[1] == 10) {
            func_800298A4_2A4A4(obj->model[0], 4, 4);
        } else {
            func_800298A4_2A4A4(obj->model[0], 4, 0);
        }
        switch (D_801093C0_205A20_AbandonShip) {
        case 6:
            if (D_80109380_2059E0_AbandonShip == 2) {
                if (obj->work[1] < 7) {
                    func_80029E80_2AA80(obj->model[0], 1, 1);
                }
            } else if (D_80109380_2059E0_AbandonShip == 0) {
                if (w->unk_59 == 3) {
                    D_801093C0_205A20_AbandonShip = 7;
                }
            } else {
                if (obj->work[1] < 7) {
                    func_80029E80_2AA80(obj->model[0], 1, 1);
                }
                if (w->unk_59 == 0) {
                    while (1) {
                        r = rand8() >> 6;
                        o = D_800FFFD8_100BD8[r];
                        if (D_801093D8_205A38_AbandonShip + 4475.0f <= o->trans.y) {
                            o->work[1] = 11;
                            D_80109381_2059E1_AbandonShip = r;
                            break;
                        }
                    }
                } else if (w->unk_59 == 3) {
                    D_801093C0_205A20_AbandonShip = 7;
                    D_8010949C_205AFC_AbandonShip[0] = D_8010949C_205AFC_AbandonShip[1] = D_8010949C_205AFC_AbandonShip[2] = D_8010949C_205AFC_AbandonShip[3] = 0;
                }
            }
            break;
        case 7:
        case 8:
            if (D_80109380_2059E0_AbandonShip == 0 || D_80109380_2059E0_AbandonShip == 2) {
                if (obj->work[1] < 7) {
                    func_80029E80_2AA80(obj->model[0], 1, 1);
                } else if (obj->work[1] == 7) {
                    func_801089A4_205004_AbandonShip(obj, 1.0f);
                    if (obj->work[2] == 1) {
                        obj->trans.x += 20.0f;
                        if (D_801093C4_205A24_AbandonShip[obj->work[0]] + 150.0f < obj->trans.x) {
                            obj->trans.x = D_801093C4_205A24_AbandonShip[obj->work[0]] + 150.0f;
                        }
                    } else {
                        obj->trans.x -= 20.0f;
                        if (obj->trans.x < D_801093C4_205A24_AbandonShip[obj->work[0]] - 150.0f) {
                            obj->trans.x = D_801093C4_205A24_AbandonShip[obj->work[0]] - 150.0f;
                        }
                    }
                    obj->trans.y = D_801093D4_205A34_AbandonShip / 2.0f + 0.0f;
                }
            } else if (obj->work[1] == 11) {
                if (D_80109440_205AA0_AbandonShip == 0) {
                    func_80029BF0_2A7F0(obj->model[0], (s16)func_80029E14_2AA14(obj->motion[6]), 0, 0x1E, 2);
                    D_80109440_205AA0_AbandonShip = 1;
                } else {
                    if (func_80029CE4_2A8E4(obj->model[0]) >= 13.0f) {
                        func_80029BF0_2A7F0(obj->model[0], (s16)func_80029E14_2AA14(obj->motion[0]), 0, 0x1E, 2);
                        obj->work[1] = 12;
                    }
                    if (D_80109440_205AA0_AbandonShip == 1) {
                        func_80108AB0_205110_AbandonShip(obj);
                    }
                }
                D_8010949C_205AFC_AbandonShip[w->unk_59]++;
            } else if (obj->work[1] == 12) {
                if (D_80109440_205AA0_AbandonShip == 1) {
                    func_80108AB0_205110_AbandonShip(obj);
                }
                func_801089A4_205004_AbandonShip(obj, 10.0f);
                if (obj->work[2] == 0) {
                    obj->trans.x += 20.0f;
                    if (D_801093C4_205A24_AbandonShip[obj->work[0]] < obj->trans.x) {
                        obj->trans.x = D_801093C4_205A24_AbandonShip[obj->work[0]];
                    }
                } else {
                    obj->trans.x -= 20.0f;
                    if (obj->trans.x < D_801093C4_205A24_AbandonShip[obj->work[0]]) {
                        obj->trans.x = D_801093C4_205A24_AbandonShip[obj->work[0]];
                    }
                }
                if (D_80109440_205AA0_AbandonShip == 2) {
                    if (D_801094C4_205B24_AbandonShip[0] == 0) {
                        if (_CheckFlag(0xC) == 0) {
                            func_80029BF0_2A7F0(obj->model[0], (s16)func_80029E14_2AA14(obj->motion[0xD]), 0, 0x1E, 2);
                            PlayMusic(0x51);
                            func_800732B0_73EB0(D_800CD438_CE038[gPlayers[w->unk_59].character].unk_04 | 0x4E);
                        }
                        gPlayers[D_80109381_2059E1_AbandonShip].coins_mg_bonus += 10;
                        D_801094C4_205B24_AbandonShip[0] = 1;
                        D_8010949C_205AFC_AbandonShip[w->unk_59] = 0;
                    } else if (_CheckFlag(0xC) == 0) {
                        if (D_8010949C_205AFC_AbandonShip[w->unk_59] == 0x78) {
                            InitFadeOut(0, 0x14);
                            func_8000C3A8_CFA8();
                        } else if (D_8010949C_205AFC_AbandonShip[w->unk_59] >= 0x3B) {
                            func_80029E80_2AA80(obj->model[0], 1, 1);
                            D_801093C0_205A20_AbandonShip = 8;
                        }
                    }
                }
                D_8010949C_205AFC_AbandonShip[w->unk_59]++;
            } else {
                if (obj->trans.y < 0.0f && obj->work[1] < 7) {
                    func_80029BF0_2A7F0(obj->model[0], (s16)func_80029E14_2AA14(obj->motion[0x10]), 0, 0x1E, 2);
                    obj->work[1] = 7;
                    return;
                }
                if (obj->work[1] == 7) {
                    func_801089A4_205004_AbandonShip(obj, 1.0f);
                    if (obj->work[2] == 1) {
                        obj->trans.x += 20.0f;
                        if (D_801093C4_205A24_AbandonShip[obj->work[0]] + 150.0f < obj->trans.x) {
                            obj->trans.x = D_801093C4_205A24_AbandonShip[obj->work[0]] + 150.0f;
                        }
                    } else {
                        obj->trans.x -= 20.0f;
                        if (obj->trans.x < D_801093C4_205A24_AbandonShip[obj->work[0]] - 150.0f) {
                            obj->trans.x = D_801093C4_205A24_AbandonShip[obj->work[0]] - 150.0f;
                        }
                    }
                    obj->trans.y = D_801093D4_205A34_AbandonShip / 2.0f + 0.0f;
                } else if (obj->work[1] == 8) {
                    func_80029BF0_2A7F0(obj->model[0], (s16)func_80029E14_2AA14(obj->motion[0xF]), 0, 0x1E, 2);
                    obj->work[1] = 9;
                } else if (obj->work[1] != 9) {
                    obj->trans.y -= 7.5f;
                }
            }
        }
    }
}

void func_801089A4_205004_AbandonShip(omObjData* obj, f32 step) {
    while (obj->rot.y < 0.0f) {
        obj->rot.y += 360.0f;
    }
    while (obj->rot.y > 360.0f) {
        obj->rot.y -= 360.0f;
    }
    if (step < obj->rot.y && obj->rot.y < 180.0f) {
        obj->rot.y -= step;
    } else if (obj->rot.y >= 180.0f && obj->rot.y < 360.0f - step) {
        obj->rot.y += step;
    } else {
        obj->rot.y = 0.0f;
    }
}

void func_80108AB0_205110_AbandonShip(omObjData* obj) {
    Vec to;
    Vec from;
    Vec dir;

    if (D_800FFFD8_100BD8[D_80109381_2059E1_AbandonShip]->work[0] == 0) {
        to.x = 530.0f;
    } else if (D_800FFFD8_100BD8[D_80109381_2059E1_AbandonShip]->work[0] == 1) {
        to.x = 190.0f;
    } else if (D_800FFFD8_100BD8[D_80109381_2059E1_AbandonShip]->work[0] == 2) {
        to.x = -190.0f;
    } else if (D_800FFFD8_100BD8[D_80109381_2059E1_AbandonShip]->work[0] == 3) {
        to.x = -530.0f;
    }
    to.y = (2.0f * D_800FFFD8_100BD8[D_80109381_2059E1_AbandonShip]->trans.y) / 3.0f;
    to.z = -700.0f;
    from.x = D_8010274C_10334C.x;
    from.y = D_8010274C_10334C.y;
    from.z = D_8010274C_10334C.z;
    func_80108DF0_205450_AbandonShip(&dir, &from, &to);
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
    D_800FA610_FB210 -= 10.0f;
    if (D_800FA610_FB210 < 2000.0f) {
        D_800FA610_FB210 = 2000.0f;
        D_80109440_205AA0_AbandonShip = 2;
    }
}

void func_80108DF0_205450_AbandonShip(Vec* out, Vec* from, Vec* to) {
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

void func_80108EA0_205500_AbandonShip(omObjData* obj) {
    MgWork* w = obj->unk_50;

    ContStkX[w->unk_57] = ContStkY[w->unk_57] = 0;
    ContBtnTrg[w->unk_57] = 0;
    if (D_80109608_205C68_AbandonShip[w->unk_57] != 0) {
        ContBtnTrg[w->unk_57] |= 0x8000;
    }
    switch (gPlayers[w->unk_59].cpu_difficulty) {
    case 0:
        if (rand8() * 100U / 256 < 50) {
            goto toggle;
        }
        break;
    case 1:
        if (rand8() * 100U / 256 < 70) {
            goto toggle;
        }
        break;
    case 2:
        if (rand8() * 100U / 256 < 95) {
            goto toggle;
        }
        break;
    case 3:
        if (rand8()) {
        toggle:
            D_80109608_205C68_AbandonShip[w->unk_57] ^= 1;
            func_80109064_2056C4_AbandonShip(obj);
        }
        break;
    }
}

/* NON_MATCHING: register allocation (masked 6): retail reuses a0 for the rung pointer. */
#ifdef NON_MATCHING
void func_80109064_2056C4_AbandonShip(omObjData* obj) {
    MgWork* w;
    s32 k;
    s32 i;

    if (D_801093D8_205A38_AbandonShip > -500.0f) {
        return;
    }
    w = obj->unk_50;
    for (i = 0; i < 8; i++) {
        if (D_801096B8_205D18_AbandonShip[i] + 100.0f < obj->trans.y) {
            continue;
        }
        if (obj->work[2] == 0 && D_801093DC_205A3C_AbandonShip[D_801096B0_205D10_AbandonShip][i] == 0) {
            ContStkX[w->unk_57] = 0x3C;
        } else if (obj->work[2] == 1 && D_801093DC_205A3C_AbandonShip[D_801096B0_205D10_AbandonShip][i] == 1) {
            ContStkX[w->unk_57] = -0x3C;
        }
        break;
    }
    k = i;
    for (i = 0; i < 5; i++) {
        if (obj->trans.y > D_80109610_205C70_AbandonShip[0][i].y) {
            continue;
        }
        if (D_800FC834_FD434[D_801096D8_205D38_AbandonShip[obj->work[0]]->model[i + 9]].unk18 & 4) {
            continue;
        }
        if (ABSDIFF(D_80109610_205C70_AbandonShip[0][i].y - D_801096B8_205D18_AbandonShip[k]) <= 100.0f) {
            if (D_801093DC_205A3C_AbandonShip[D_801096B0_205D10_AbandonShip][D_801093F4_205A54_AbandonShip[D_801096B0_205D10_AbandonShip][i]] == 0) {
                if (ContStkX[w->unk_57] > 0 || obj->work[2] == 1 || obj->work[1] == 6) {
                    ContStkX[w->unk_57] = -0x3C;
                }
            } else if (D_801093DC_205A3C_AbandonShip[D_801096B0_205D10_AbandonShip][D_801093F4_205A54_AbandonShip[D_801096B0_205D10_AbandonShip][i]] == 1) {
                if (ContStkX[w->unk_57] < 0 || obj->work[2] == 0 || obj->work[1] == 5) {
                    ContStkX[w->unk_57] = 0x3C;
                }
            }
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_AbandonShip/2032A0", func_80109064_2056C4_AbandonShip);
#endif
