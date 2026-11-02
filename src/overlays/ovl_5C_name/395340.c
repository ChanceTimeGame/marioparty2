#include "ovl_5C.h"

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/395340", func_80107480_395340_name_5C);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/395340", func_80107660_395520_name_5C);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/395340", func_80107F28_395DE8_name_5C);

void func_801084C4_396384_name_5C(void) {
    s16 last = -1;
    s16 i;
    s16 x0;
    s16 dx;
    s16 y0;
    s16 dy;
    f32 s;
    s16* to;

    D_80112424_3A02E4_name_5C = 0;
    D_80112F38_3A0DF8_name_5C = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x900F8), 0, 1);
    func_8001A788_1B388(D_80112F38_3A0DF8_name_5C, 1);
    espPosSet(D_80112F38_3A0DF8_name_5C, 160, 120);
    espDispOff(D_80112F38_3A0DF8_name_5C);
    D_80112374_3A0234_name_5C = 160;
    D_80112376_3A0236_name_5C = 120;
    D_80112378_3A0238_name_5C = 10;
    omAddPrcObj(func_80108758_396618_name_5C, 0x3F00, 0x100, 0);
    while (1) {
        HuPrcVSleep();
        if (D_80112424_3A02E4_name_5C != 0) {
            if (last != D_8011237A_3A023A_name_5C && D_8011237A_3A023A_name_5C != -1) {
                x0 = D_80112374_3A0234_name_5C;
                y0 = D_80112376_3A0236_name_5C;
                to = D_80112370_3A0230_name_5C[D_8011237A_3A023A_name_5C];
                dx = to[0] - x0;
                dy = to[1] - y0;
                for (i = 1; i <= D_80112378_3A0238_name_5C; i++) {
                    s = HuMathSin(90.0f / D_80112378_3A0238_name_5C * i);
                    D_80112374_3A0234_name_5C = x0 + dx * s;
                    D_80112376_3A0236_name_5C = y0 + dy * s;
                    espPosSet(D_80112F38_3A0DF8_name_5C, D_80112374_3A0234_name_5C,
                              D_80112376_3A0236_name_5C);
                    HuPrcVSleep();
                }
                last = D_8011237A_3A023A_name_5C;
            }
        } else {
            last = D_8011237A_3A023A_name_5C;
        }
        espPosSet(D_80112F38_3A0DF8_name_5C, D_80112374_3A0234_name_5C, D_80112376_3A0236_name_5C);
    }
}

void func_80108758_396618_name_5C(void) {
    s16 shown;
    s16 i;

    shown = 0;
    while (1) {
        HuPrcVSleep();
        if (shown == D_80112424_3A02E4_name_5C) {
            continue;
        }
        if (D_80112424_3A02E4_name_5C != 0) {
            espDispOn(D_80112F38_3A0DF8_name_5C);
            for (i = 0; i < 5; i++) {
                func_8001A6BC_1B2BC(D_80112F38_3A0DF8_name_5C, i * 63.75f);
                HuPrcVSleep();
            }
        } else {
            for (i = 0; i < 5; i++) {
                func_8001A6BC_1B2BC(D_80112F38_3A0DF8_name_5C, 255.0f - i * 63.75f);
                HuPrcVSleep();
            }
            espDispOff(D_80112F38_3A0DF8_name_5C);
        }
        shown = D_80112424_3A02E4_name_5C;
    }
}

void func_801088A8_396768_name_5C(s16 n) {
    D_80112374_3A0234_name_5C = D_80112370_3A0230_name_5C[n][0];
    D_80112376_3A0236_name_5C = D_80112370_3A0230_name_5C[n][1];
    D_8011237A_3A023A_name_5C = n;
}

void func_801088E0_3967A0_name_5C(s16 (*slots)[2]) {
    D_80112370_3A0230_name_5C = slots;
}

void func_801088EC_3967AC_name_5C(s16 time) {
    D_80112378_3A0238_name_5C = time;
}

void func_801088F8_3967B8_name_5C(s16 slot) {
    D_8011237A_3A023A_name_5C = slot;
}

#ifdef NON_MATCHING
/* Same instruction count; differs in float register allocation (rx/spd swapped) and where the
   D_8010274C base is loaded in the 0x800/0x400 arms. */
void func_80108904_3967C4_name_5C(void) {
    f32 zoom;
    f32 spd;
    f32 rx;
    f32 ry;
    f32 b;
    f32 inv;

    if (ContBtn[1] & 0x20) {
        if (ContBtn[0] & 0x2000) {
            zoom = D_800FA610_FB210 + 30.0f;
        } else {
            zoom = D_800FA610_FB210 + 10.0f;
        }
        D_800FA610_FB210 = zoom;
    }
    if ((ContBtn[1] & 0x10) && D_800FA610_FB210 - 10.0f != 0.0f) {
        if (ContBtn[1] & 0x2000) {
            zoom = D_800FA610_FB210 - 30.0f;
        } else {
            zoom = D_800FA610_FB210 - 10.0f;
        }
        D_800FA610_FB210 = zoom;
    }
    rx = D_801129F4_3A08B4_name_5C.x;
    ry = D_801129F4_3A08B4_name_5C.y;
    if (ContBtn[1] & 0x2000) {
        spd = 5.0f;
    } else {
        spd = 2.0f;
    }
    ry += -ContStkX[1] / 30 * spd;
    if (ry >= 360.0f) {
        ry -= 360.0f;
    } else if (ry < 0.0f) {
        ry += 360.0f;
    }
    D_801129F4_3A08B4_name_5C.y = ry;
    rx += (s8)(ContStkY[1] / 30) * spd;
    if (rx >= 360.0f) {
        rx -= 360.0f;
    } else if (rx < 0.0f) {
        rx += 360.0f;
    }
    D_801129F4_3A08B4_name_5C.x = rx;
    D_800FD474_FE074.x = (s16)rx;
    D_800FD474_FE074.y = (s16)D_801129F4_3A08B4_name_5C.y;
    if (ContBtn[1] & 0x2000) {
        spd = 10.0f;
    } else {
        spd = 2.0f;
    }
    if (ContBtn[1] & 0x800) {
        b = HuMathSin(ry) * HuMathSin(rx);
        spd = -spd;
        b *= spd;
        D_8010274C_10334C.x += b;
        D_8010274C_10334C.y += func_800B7890_B8490(rx) * spd;
        D_8010274C_10334C.z += func_800B7890_B8490(ry) * HuMathSin(rx) * spd;
    } else if (ContBtn[1] & 0x400) {
        b = HuMathSin(ry) * HuMathSin(rx);
        b *= spd;
        D_8010274C_10334C.x += b;
        D_8010274C_10334C.y += func_800B7890_B8490(rx) * spd;
        D_8010274C_10334C.z += func_800B7890_B8490(ry) * HuMathSin(rx) * spd;
    } else if (ContBtn[1] & 0x200) {
        rx = D_800C9B80_CA780->pos.z - D_8010274C_10334C.z;
        b = -(D_800C9B80_CA780->pos.x - D_8010274C_10334C.x);
        inv = 1.0f / func_800B1830_B2430(rx * rx + b * b);
        D_8010274C_10334C.x += rx * inv * spd;
        D_8010274C_10334C.y += 0.0f;
        D_8010274C_10334C.z += b * inv * spd;
    } else if (ContBtn[1] & 0x100) {
        rx = -(D_800C9B80_CA780->pos.z - D_8010274C_10334C.z);
        b = D_800C9B80_CA780->pos.x - D_8010274C_10334C.x;
        inv = 1.0f / func_800B1830_B2430(rx * rx + b * b);
        D_8010274C_10334C.x += rx * inv * spd;
        D_8010274C_10334C.y += 0.0f;
        D_8010274C_10334C.z += b * inv * spd;
    }
    if (ContBtn[1] & 2) {
        D_80111C40_39FB00_name_5C += 1.0f;
    }
    if (ContBtn[1] & 1) {
        D_80111C40_39FB00_name_5C -= 1.0f;
    }
    Hu3DCamSetPerspective(0, D_80111C40_39FB00_name_5C, D_80112F24_3A0DE4_name_5C, D_80112F54_3A0E14_name_5C);
    if (ContBtnTrg[1] & 0x4000) {
        osSyncPrintf("CRot   (%f,%f,%f)\n", D_800FD474_FE074.x, D_800FD474_FE074.y, D_800FD474_FE074.z);
        osSyncPrintf("Center (%f,%f,%f)\n", D_8010274C_10334C.x, D_8010274C_10334C.y, D_8010274C_10334C.z);
        osSyncPrintf("CZoom  %f CFovy %f\n", D_800FA610_FB210, D_80111C40_39FB00_name_5C);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/395340", func_80108904_3967C4_name_5C);
#endif

void func_80108F28_396DE8_name_5C(void) {
    Vec pos;
    Vec at;
    Vec up;
    f32 rx;
    f32 ry;
    f32 rz;
    f32 ux;
    f32 uy;
    f32 uz;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 dist;

    while (1) {
        if (D_80111C44_39FB04_name_5C == 0) {
            rx = D_800FD474_FE074.x;
            ry = D_800FD474_FE074.y;
            rz = D_800FD474_FE074.z;
            pos.x = D_8010274C_10334C.x + HuMathSin(ry) * func_800B7890_B8490(rx) * D_800FA610_FB210;
            pos.y = D_8010274C_10334C.y + -HuMathSin(rx) * D_800FA610_FB210;
            pos.z = D_8010274C_10334C.z + func_800B7890_B8490(ry) * func_800B7890_B8490(rx) * D_800FA610_FB210;
            at.x = D_8010274C_10334C.x;
            at.y = D_8010274C_10334C.y;
            at.z = D_8010274C_10334C.z;
            ux = HuMathSin(ry) * HuMathSin(rx);
            uy = func_800B7890_B8490(rx);
            uz = func_800B7890_B8490(ry) * HuMathSin(rx);
            dx = at.x - pos.x;
            dy = at.y - pos.y;
            dz = at.z - pos.z;
            dist = func_800B1830_B2430(dx * dx + dy * dy + dz * dz);
            dx /= dist;
            dy /= dist;
            dz /= dist;
            up.x = ux * (dx * dx + (1.0f - dx * dx) * func_800B7890_B8490(rz))
                 + uy * (dx * dy * (1.0f - func_800B7890_B8490(rz)) - dz * HuMathSin(rz))
                 + uz * (dx * dz * (1.0f - func_800B7890_B8490(rz)) + dy * HuMathSin(rz));
            up.y = ux * (dx * dy * (1.0f - func_800B7890_B8490(rz)) + dz * HuMathSin(rz))
                 + uy * (dy * dy + (1.0f - dy * dy) * func_800B7890_B8490(rz))
                 + uz * (dy * dz * (1.0f - func_800B7890_B8490(rz)) - dx * HuMathSin(rz));
            up.z = ux * (dx * dz * (1.0f - func_800B7890_B8490(rz)) - dy * HuMathSin(rz))
                 + uy * (dy * dz * (1.0f - func_800B7890_B8490(rz)) + dx * HuMathSin(rz))
                 + uz * (dz * dz + (1.0f - dz * dz) * func_800B7890_B8490(rz));
        } else {
            pos = D_80112FA0_3A0E60_name_5C;
            at = D_80112F2C_3A0DEC_name_5C;
            up.x = 0.0f;
            up.y = 1.0f;
            up.z = 0.0f;
        }
        D_800FA5BC_FB1BC[0] = pos.x;
        D_800FA5BC_FB1BC[1] = pos.z;
        D_800FA5BC_FB1BC[-1] = D_800FD474_FE074.y;
        D_800FA5BC_FB1BC[2] = D_800C9B80_CA780->fov[0];
        D_800FA5BC_FB1BC[3] = D_80101078_101C78;
        D_800FA5BC_FB1BC[4] = D_800F8410_F9010;
        Hu3DCamSetPositionOrientation(0, &pos, &at, &up);
        Hu3DCamUpdateMtx(0);
        HuPrcVSleep();
    }
}

void func_801094FC_3973BC_name_5C(Ovl5CModelDef* defs) {
    Ovl5CModelDef* def;
    s16 i;
    s16 model;

    def = defs;
    for (i = 0; def->file != -1; def++, i++) {
        model = LoadFormFile(def->file, def->attr | 0x288);
        D_80112F60_3A0E20_name_5C[i] = model;
        func_801095F0_3974B0_name_5C(defs, i, model);
        D_80112498_3A0358_name_5C[i] = func_80029E14_2AA14(model);
        if (D_80112498_3A0358_name_5C[i] != -1) {
            func_80029E80_2AA80(model, -1, def->unk0A);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/395340", func_801095F0_3974B0_name_5C);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/395340", func_801096BC_39757C_name_5C);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/395340", func_801097A4_397664_name_5C);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/395340", func_801098A4_397764_name_5C);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/395340", func_801098E4_3977A4_name_5C);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/395340", func_80109BEC_397AAC_name_5C);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/395340", func_80109EA4_397D64_name_5C);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/395340", func_80109F9C_397E5C_name_5C);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5C_name/395340", func_8010A0D0_397F90_name_5C);
