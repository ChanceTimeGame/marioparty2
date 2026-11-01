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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_27_AbandonShip/2032A0", func_80106F5C_2035BC_AbandonShip);

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

void func_80108AB0_205110_AbandonShip(void) {
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
    len = func_800B1830_B2430(out->x * out->x + out->y * out->y + out->z * out->z);
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
