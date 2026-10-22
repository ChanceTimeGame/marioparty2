#include "common.h"
#include "ovl_0F.h"

__asm__(".section .rodata");
const char D_8010A8C0_14C250_RainbowRun[16] = "\202r\202s\202`\202q\202s";

/* Minigame setup: the player of group 0 runs alone (D_8010ACC0[0]), the other three follow. */
void func_80102800_144190_RainbowRun(void) {
    s16 i;
    s16 j;
    s16 esp;
    omObjData* obj;

    for (i = 0; i < 4; i++) {
        if (gPlayers[i].group == 0) {
            break;
        }
    }
    switch (i) {
    case 1:
        D_8010ACC0_14C650_RainbowRun[0] = 1;
        break;
    case 2:
        D_8010ACC0_14C650_RainbowRun[0] = 2;
        break;
    case 3:
        D_8010ACC0_14C650_RainbowRun[0] = 3;
        break;
    case 0:
    default:
        D_8010ACC0_14C650_RainbowRun[0] = 0;
        break;
    }
    for (i = 1, j = 0; i < 4; i++) {
        if (D_8010ACC0_14C650_RainbowRun[0] == j) {
            j++;
        }
        D_8010ACC0_14C650_RainbowRun[i] = j;
        j++;
    }
    func_8002D4D0_2E0D0(10);
    func_8002F290_2FE90(D_800F9D30_FA930, 0x40);
    func_80020D20_21920(0x40);
    omInitObjMan(0x1E, 0);
    func_80079128_79D28();
    func_8000C460_D060();
    D_800BF7AC_C03AC = 100.0f;
    func_8000C578_D178(1);
    func_80020070_20C70(1);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_80079E60_7AA60), 0xA0);
    ScissorSet(0, 0.0f, 0.0f, 319.0f, 239.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 30.0f, 80.0f, 8000.0f);
    func_8002C59C_2D19C(0x800, 0x990, 0x40, 0x40, 0x40);
    func_8000C38C_CF8C();
    func_8000C3C8_CFC8();
    func_8007273C_7333C((u8*)D_8010A8C0_14C250_RainbowRun, 1);
    D_800FA606_FB206 = 0;
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(2, 0xC, 0x2E, -1, func_80103648_144FD8_RainbowRun);
    func_8000C018_CC18(D_800F8FE0_F9BE0);
    obj = D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(3, 6, 0, -1, func_80106D60_1486F0_RainbowRun);
    omSetStatBit(obj, 0xA0);
    obj = D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(3, 6, 0, -1, func_80106E8C_14881C_RainbowRun);
    omSetStatBit(obj, 0xA0);
    omAddObj(0, 0, 0, -1, func_80105978_147308_RainbowRun);
    omAddObj(0, 0, 0, -1, func_80104FB4_146944_RainbowRun);
    func_80107878_149208_RainbowRun();
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = D_8010AC14_14C5A4_RainbowRun[0] = omAddObj(4, 6, 10, -1, func_8010A42C_14BDBC_RainbowRun);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = D_8010AC14_14C5A4_RainbowRun[1] = omAddObj(4, 6, 10, -1, func_8010A514_14BEA4_RainbowRun);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = D_8010AC14_14C5A4_RainbowRun[2] = omAddObj(4, 6, 10, -1, func_8010A600_14BF90_RainbowRun);
    D_800F9CE0_FA8E0[D_800FA606_FB206++] = D_8010ACC4_14C654_RainbowRun[0] = omAddObj(0x14, 10, 0, -1, func_801087A8_14A138_RainbowRun);
    D_800F9CE0_FA8E0[D_800FA606_FB206++] = D_8010ACC4_14C654_RainbowRun[1] = omAddObj(0x14, 10, 0, -1, func_801087CC_14A15C_RainbowRun);
    D_800F9CE0_FA8E0[D_800FA606_FB206++] = D_8010ACC4_14C654_RainbowRun[2] = omAddObj(0x14, 10, 0, -1, func_801087F0_14A180_RainbowRun);
    omAddObj(0x1E, 10, 0, -1, func_801075FC_148F8C_RainbowRun);
    D_8010A99C_14C32C_RainbowRun.x = 0.0f;
    D_8010A99C_14C32C_RainbowRun.y = 320.0f;
    D_8010A99C_14C32C_RainbowRun.z = 299.0f;
    D_8010A990_14C320_RainbowRun.x = 0.0f;
    D_8010A990_14C320_RainbowRun.y = 2276.52f;
    D_8010A990_14C320_RainbowRun.z = 1835.286f;
    esp = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x1F0007), 0, 1);
    espDispOff(esp);
    func_8007A27C_7AE7C(0x7FDA, D_800F93FC_F9FFC[esp].unk_04, func_80102F3C_1448CC_RainbowRun, 30.0f,
                        &D_8010A990_14C320_RainbowRun, &D_8010A99C_14C32C_RainbowRun);
    Hu3DCamSetPerspective(0, 28.0f, 80.0f, 8000.0f);
    func_8002C59C_2D19C(0x800, 0x990, 0x40, 0x40, 0x40);
    func_801057F0_147180_RainbowRun(1900.0f, 370.0f, 0.0f, 0.0f, 0.0f, -590.0f, 1100.0f);
    func_80026DAC_279AC(1, 0x60, 0x40, 0x40);
    func_80026E00_27A00(1, 54.0f, -44.0f, 97.0f);
    InitFadeIn(0, 0x10);
}

/* The title camera's sprite draw (func_8007A27C_7AE7C's callback): main's func_8007A7FC_7B3FC
   with the sprite at the scroll position D_8010A704 (wrapped to the screen) and its strips wrapped
   back to the top at the camera's bottom edge instead of stopping there. */
void func_80102F3C_1448CC_RainbowRun(RRCamSprWork* work) {
    HuSprite* spr;
    HuCamera* cam;
    u16 w, h, rows;
    s16 left, top, right, bottom;
    f32 x0, y0, x1, y1;
    f32 step, next;
    s32 s;

    spr = func_80082550_83150(work->sprId, 0);
    w = spr->unk_84->unk14;
    h = spr->unk_84->unk16;
    gDPSetTextureLUT(D_800FDBCC_FE7CC++, G_TT_RGBA16);
    gDPLoadTLUT_pal256(D_800FDBCC_FE7CC++, spr->unk_84->unk0C);
    cam = work->cam;
    left = cam->screenLeft;
    top = cam->screenTop;
    right = cam->screenRight;
    bottom = cam->screenBottom;
    gDPSetScissor(D_800FDBCC_FE7CC++, G_SC_NON_INTERLACE, left, top, right, bottom);
    while (D_8010A704_14C094_RainbowRun[0] < 0) {
        D_8010A704_14C094_RainbowRun[0] += 320;
    }
    while (D_8010A704_14C094_RainbowRun[0] >= 320) {
        D_8010A704_14C094_RainbowRun[0] -= 320;
    }
    while (D_8010A704_14C094_RainbowRun[1] < 0) {
        D_8010A704_14C094_RainbowRun[1] += 240;
    }
    while (D_8010A704_14C094_RainbowRun[1] >= 240) {
        D_8010A704_14C094_RainbowRun[1] -= 240;
    }
    x0 = D_8010A704_14C094_RainbowRun[0] + 0.0f;
    y0 = D_8010A704_14C094_RainbowRun[1] + 0.0f;
    x1 = w + D_8010A704_14C094_RainbowRun[0];
    y1 = h + D_8010A704_14C094_RainbowRun[1];
    rows = 0x800 / w - 1;
    x1 -= 1.0f;
    y1 -= 1.0f;
    step = RR_ABS(y1 - y0) / (u16)(h / rows);
    for (s = 0; s < h - 1; s += rows) {
        next = y0 + step;
        if (s + rows >= h - 1) {
            rows = h - s - 1;
        }
        if (top <= next) {
            if (y1 < next) {
                step = y1 - y0;
            }
            gDPLoadTextureTile(D_800FDBCC_FE7CC++, spr->unk_84->unk08, G_IM_FMT_CI, G_IM_SIZ_8b, w, h, 0, s, w,
                               s + rows, 0, 0, 0, 0, 0, 0, 0);
            gSPScisTextureRectangle(D_800FDBCC_FE7CC++, (s32)(x0 * 4.0f), (s32)(y0 * 4.0f), (s32)(x1 * 4.0f),
                                    (s32)((y0 + step) * 4.0f), G_TX_RENDERTILE, 0, s << 5, 1024, 1024);
        }
        y0 += step;
        if (bottom <= y0) {
            y0 -= bottom;
        }
    }
}

void func_80103648_144FD8_RainbowRun(omObjData* obj) {
    u8 chr = gPlayers[D_8010ACC0_14C650_RainbowRun[0]].character;
    s32 dir = D_800CD438_CE038[chr].unk_04;
    s32 file = D_800CD438_CE038[chr].unk_10;

    func_8010393C_1452CC_RainbowRun(obj, dir, file, D_8010ACC0_14C650_RainbowRun[0], 0.0f, 0.0f, 1370.0f);
}

/* The runner's collision callback: a hit knocks it back and the object explodes. */
s32 func_801036CC_14505C_RainbowRun(omObjData* obj, omObjData* other) {
    RRPlayerWork* w = obj->unk_50;
    RRBomb* bomb = ((RRItemWork*)other->unk_50)->bomb;
    s16 i;

    if (w->unk_BE != 0) {
        return 1;
    }
    w->unk_BE = 60;
    w->unk_50 |= 0x200;
    if (D_8010A6F5_14C085_RainbowRun == 1) {
        return 1;
    }
    {
        f32 s = HuMathSin(w->angle);

        if (func_8000DA2C_E62C(s, func_800B7890_B8490(w->angle), other->trans.x - obj->trans.x,
                               other->trans.z - obj->trans.z) > 0.0f) {
            w->angle = func_800B75A8_B81A8(other->trans.x - obj->trans.x, other->trans.z - obj->trans.z);
            func_80019B9C_1A79C(obj, 9);
            if (D_8010A6F8_14C088_RainbowRun == 1) {
                w->speed = 0.0f;
            } else {
                w->speed = -4.55f;
            }
        } else {
            w->angle = func_800B75A8_B81A8(other->trans.x - obj->trans.x, other->trans.z - obj->trans.z);
            func_80019B9C_1A79C(obj, 10);
            if (D_8010A6F8_14C088_RainbowRun == 1) {
                w->speed = 0.0f;
            } else {
                w->speed = 4.55f;
            }
        }
    }
    omVibrate(w->player, 30, 0, 30);
    func_80079798_7A398(0x18B, bomb->sound);
    PlaySound(0x18D);
    bomb->active = 0;
    bomb->lit = 0;
    for (i = 0; i < 6; i++) {
        func_800298A4_2A4A4(other->model[i], 4, 4);
    }
    func_80021198_21D98(bomb->mdl, 0);
    func_800298A4_2A4A4(other->model[5], 4, 0);
    func_80029714_2A314(other->model[5], other->trans.x, other->trans.y - 50.0f, other->trans.z);
    other->trans.x = other->trans.y = other->trans.z = 1000.0f;
    return 1;
}

/* The runner's setup: motions, its sounds and the collision callback. */
void func_8010393C_1452CC_RainbowRun(omObjData* obj, s32 dir, s32 file, u16 player, f32 x, f32 y, f32 z) {
    RRPlayerWork* w;
    s16 i;

    func_8000C6FC_D2FC(obj, dir, file, player, 0x2A9, 0x2A9);
    w = obj->unk_50;
    w->angle = 180.0f;
    w->radius = 60.0f;
    D_800BF7E4_C03E4[w->player][0] = 0x2D2;
    D_800BF7E4_C03E4[w->player][1] = 0x2D2;
    D_800BF7E4_C03E4[w->player][2] = 0x2D2;
    D_800BF7E4_C03E4[w->player][3] = 0x2D2;
    D_800BF7E4_C03E4[w->player][4] = 0x2D2;
    D_800BF7E4_C03E4[w->player][5] = 0x2D2;
    D_800BF7E4_C03E4[w->player][6] = 0x2D2;
    D_800BF7E4_C03E4[w->player][7] = 0x2D2;
    D_800BF7E4_C03E4[w->player][8] = 0x2D2;
    D_800BF7E4_C03E4[w->player][9] = 0x2D2;
    D_800BF7E4_C03E4[w->player][10] = 0x2D2;
    D_800BF7E4_C03E4[w->player][11] = 0x2D2;
    D_800BF7E4_C03E4[w->player][12] = 0x2D2;
    D_800BF7E4_C03E4[w->player][13] = 0x2D2;
    obj->func_ptr = func_801041E4_145B74_RainbowRun;
    w->unk_EC = func_801036CC_14505C_RainbowRun;
    func_80019E84_1AA84(obj, 0, dir, 1, 0);
    func_80019E84_1AA84(obj, 1, dir | 1, 1, 0);
    func_80019E84_1AA84(obj, 2, dir | 1, 1, 0);
    func_80019E84_1AA84(obj, 0x26, dir | 0x21, 1, 0);
    func_80019F0C_1AB0C(obj, 6, dir | 4, 1, 0x13);
    func_80019F0C_1AB0C(obj, 0x27, dir | 0x39, 1, 0);
    func_80019F0C_1AB0C(obj, 0x28, dir | 0x20, 1, 0);
    func_80019F0C_1AB0C(obj, 0x29, dir | 0x20, 1, 0);
    func_80019F0C_1AB0C(obj, 9, dir | 7, 1, 0x27);
    func_80019F0C_1AB0C(obj, 0xA, dir | 0x12, 1, 0x27);
    func_80019F0C_1AB0C(obj, 0x10, dir | 0xE, 1, 0);
    func_80019F0C_1AB0C(obj, 0x12, dir | 0x10, 2, 0);
    func_80019F0C_1AB0C(obj, 0x13, dir | 0x11, 2, 0);
    func_80019F0C_1AB0C(obj, 0x16, dir | 0x13, 1, 0);
    func_80019E84_1AA84(obj, 0x15, dir | 0x2E, 0, 0);
    func_80019E84_1AA84(obj, 0x1E, dir | 0x2F, 0, 0);
    func_80019E84_1AA84(obj, 0x1F, dir | 0x30, 0, 0);
    func_80019E84_1AA84(obj, 0x21, dir | 0x32, 2, 0);
    func_80019E84_1AA84(obj, 0x22, dir | 0x33, 2, 0);
    func_80019E84_1AA84(obj, 0xE, dir | 0x56, 1, 0x78);
    func_8000CC74_D874(obj, obj->model[0], 1);
    func_8001A12C_1AD2C(obj, 0xD, dir | 0x4F, 1, 0x78, 1);
    func_8000C35C_CF5C(obj, x, y, z);
    func_80029714_2A314(obj->model[0], x, y, z);
    func_8000C024_CC24(obj, 0, 2);
    func_8000C024_CC24(obj, 1, 2);
    for (i = 2; i < 10; i++) {
        func_8000C024_CC24(obj, i, 1);
    }
}

/* A CPU runner: steer back to the middle, slow down near the thrown objects (MP1
   func_800F7450_TightropeTreachery). */
// register allocation as MP1's (switch operands copied), and retail's mul-fix nop after sqrtf (masked 43)
#ifdef NON_MATCHING
void func_80103E1C_1457AC_RainbowRun(omObjData* obj) {
    RRPlayerWork* w = obj->unk_50;
    s32 pace;
    s32 side;
    s8 near;
    s16 i;
    f32 rope;

    ContStkX[w->port] = 0;
    ContStkY[w->port] = 0;
    pace = 0;
    rope = D_8010A7D0_14C160_RainbowRun;
    if (rope + 40.0f <= obj->trans.x) {
        side = 1;
    } else if (rope + 15.0f <= obj->trans.x) {
        side = 2;
    } else if (rope + -15.0f <= obj->trans.x) {
        side = 0;
    } else if (rope + -40.0f <= obj->trans.x) {
        side = 4;
    } else {
        side = 3;
    }
    near = 0;
    for (i = 0; i < 3; i++) {
        omObjData* bomb = D_800F9CE0_FA8E0[i];
        f32 dx = bomb->trans.x;
        f32 dy = bomb->trans.y;
        f32 dz = bomb->trans.z;
        f32 d;

        dx -= obj->trans.x;
        dy -= obj->trans.y;
        dz -= obj->trans.z;
        d = sqrtf(dx * dx + dy * dy);
        if (d * d + dz * dz < 10000.0f) {
            near++;
        }
    }
    switch (near) {
    case 3:
        pace = 4;
        break;
    case 0:
        pace = 1;
        if ((side == 1) | (side == 3)) {
            pace = 2;
        }
        break;
    case 1:
        pace = 2;
        break;
    case 2:
        pace = 2;
        break;
    }
    switch (side) {
    case 1:
        ContStkX[w->port] = -80;
        break;
    case 2:
        ContStkX[w->port] = -40;
        break;
    case 3:
        ContStkX[w->port] = 80;
        break;
    case 4:
        ContStkX[w->port] = 40;
        break;
    default:
        ContStkX[w->port] = 0;
        break;
    }
    switch (pace) {
    case 1:
        ContStkY[w->port] = 80;
        break;
    case 2:
        ContStkY[w->port] = 40;
        break;
    case 3:
        ContStkY[w->port] = -80;
        break;
    case 4:
        ContStkY[w->port] = -40;
        break;
    default:
        ContStkY[w->port] = 0;
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0F_RainbowRun/144190", func_80103E1C_1457AC_RainbowRun);
#endif

/* The runner's update (MP1 func_800F7818_TightropeTreachery): run-in, the pace of the course
   scrolling, falling off, and the goal. */
void func_801041E4_145B74_RainbowRun(omObjData* obj) {
    RRPlayerWork* w;
    s16 i;

    D_8010A6FC_14C08C_RainbowRun = 0.0f;
    w = obj->unk_50;
    ContBtn[w->port] &= 0x7FFF;
    ContBtnTrg[w->port] &= 0x7FFF;
    D_800FD410_FE010[w->port] &= 0x7FFF;
    if (D_8010A70E_14C09E_RainbowRun == 1) {
        D_8010A6F0_14C080_RainbowRun = 1;
        D_8010A6F6_14C086_RainbowRun = 1;
        D_8010A6F7_14C087_RainbowRun = 1;
    }
    if (D_8010A6F3_14C083_RainbowRun == 1) {
        if (D_8010A6F0_14C080_RainbowRun != 1 && w->unk_BE == 0 &&
            obj->trans.y >= D_8010A7D4_14C164_RainbowRun + -50.0) {
            D_8010A70C_14C09C_RainbowRun = 0;
            if (obj->trans.x < D_8010A7D0_14C160_RainbowRun + -12.0f && w->angle < -45.0 && w->angle > -135.0f) {
                D_8010A70C_14C09C_RainbowRun = 1;
            }
            if (D_8010A7D0_14C160_RainbowRun + 12.0f < obj->trans.x && w->angle > 45.0f && w->angle < 135.0f) {
                D_8010A70C_14C09C_RainbowRun = 1;
            }
            if (D_8010A70D_14C09D_RainbowRun != D_8010A70C_14C09C_RainbowRun) {
                func_80019E04_1AA04(obj, 0, 0x26);
                func_80019CA4_1A8A4(obj, 0);
            }
            D_8010A70D_14C09D_RainbowRun = D_8010A70C_14C09C_RainbowRun;
        }
        if (D_8010A70E_14C09E_RainbowRun != 1 && D_8010A702_14C092_RainbowRun != 1) {
            if (D_8010A6F8_14C088_RainbowRun == 0) {
                if (obj->trans.z + 120.0f < D_8010A718_14C0A8_RainbowRun && D_8010A724_14C0B4_RainbowRun++ < 6) {
                    D_8010A718_14C0A8_RainbowRun -= 350.0f;
                    D_8010A6F8_14C088_RainbowRun = 1;
                    D_8010A71C_14C0AC_RainbowRun = 0;
                }
                if (D_8010A6F0_14C080_RainbowRun != 1) {
                    obj->trans.x += D_8010ABFC_14C58C_RainbowRun[0] / 8.0f;
                    obj->trans.z += D_8010ABFC_14C58C_RainbowRun[1] / 8.0f;
                }
            } else if (D_8010A71C_14C0AC_RainbowRun++ >= 15.0f) {
                func_80105ED4_147864_RainbowRun(D_800FC7B0_FD3B0[0], 350.0f);
                D_8010A6F8_14C088_RainbowRun = 0;
                D_8010A750_14C0E0_RainbowRun = 1;
                D_8010A71C_14C0AC_RainbowRun = 0;
                D_8010A720_14C0B0_RainbowRun = 5.0f;
            } else {
                D_8010AC04_14C594_RainbowRun -= 23.333334f;
                D_8010A6FC_14C08C_RainbowRun = 23.333334f;
                D_8010A704_14C094_RainbowRun[1] += 4;
            }
        }
        if (D_8010A750_14C0E0_RainbowRun == 1) {
            if (D_8010A71C_14C0AC_RainbowRun++ < 15.0f) {
                D_8010A720_14C0B0_RainbowRun -= 0.22222f;
                for (i = 0; i < 3; i++) {
                    if (D_8010AC14_14C5A4_RainbowRun[i] != NULL) {
                        RR_WORK(D_8010AC14_14C5A4_RainbowRun[i])->team->unk_38 -= D_8010A720_14C0B0_RainbowRun + 20.0f;
                    }
                }
            } else {
                D_8010A750_14C0E0_RainbowRun = 0;
            }
        }
        if (gPlayers[w->player].flags & 1) {
            func_80103E1C_1457AC_RainbowRun(obj);
        }
        if (D_8010A70E_14C09E_RainbowRun == 1) {
            func_80105E38_1477C8_RainbowRun(obj->unk_50);
        }
    } else {
        if (obj->trans.z < 1100.0f) {
            D_8010A6F4_14C084_RainbowRun = 1;
            ContStkY[w->port] = 0;
            func_8000C024_CC24(obj, 0, 2);
        } else {
            if (D_8010A714_14C0A4_RainbowRun == 0) {
                if (obj->trans.z <= 1310.0f && D_8010A715_14C0A5_RainbowRun < 10) {
                    ContBtn[w->port] |= 0x8000;
                    ContBtnTrg[w->port] |= 0x8000;
                    D_800FD410_FE010[w->port] |= 0x8000;
                    D_8010A715_14C0A5_RainbowRun++;
                }
                if (obj->trans.z <= 1180.0f) {
                    func_80019E04_1AA04(obj, 0, 0x27);
                    func_80019E04_1AA04(obj, 1, 0x28);
                    func_80019E04_1AA04(obj, 2, 0x29);
                    func_80019CA4_1A8A4(obj, 2);
                    D_800BF7BC_C03BC = 26.666666f;
                    D_800BF79C_C039C = 1.0f;
                    D_800BF7A4_C03A4 = 0.65333337f;
                    D_800BF7A8_C03A8 = 0.06666667f;
                    D_800BF7A0_C03A0 = 0.25f;
                    D_800BF7C0_C03C0 = 2.25f;
                    D_800BF7C4_C03C4 = 1.6875f;
                    D_800BF7C8_C03C8 = 1.125f;
                    D_800BF7CC_C03CC = 0.5625f;
                    D_800BF7B0_C03B0 = 30.0f;
                    D_8010A714_14C0A4_RainbowRun = 1;
                    D_8010A7A8_14C138_RainbowRun = 0;
                }
            }
            D_8010A6F5_14C085_RainbowRun = 1;
            ContStkY[w->port] = 50;
            func_8000C024_CC24(obj, 0, 1);
        }
        ContStkX[w->port] = 0;
    }
    if (D_8010A6F6_14C086_RainbowRun != 2 &&
        ((obj->trans.z <= -1100.0f && obj->trans.y >= D_8010A7D4_14C164_RainbowRun + -20.0 &&
          obj->trans.x < D_8010A7D0_14C160_RainbowRun + 60.0f && D_8010A7D0_14C160_RainbowRun + -60.0f < obj->trans.x) ||
         D_8010A702_14C092_RainbowRun == 1)) {
        if (D_8010A7A8_14C138_RainbowRun == 0) {
            if (D_8010A710_14C0A0_RainbowRun == 0) {
                func_800794A8_7A0A8(40);
                D_8010A710_14C0A0_RainbowRun = 1;
            }
            D_8010A6F7_14C087_RainbowRun = 1;
            D_8010A6F5_14C085_RainbowRun = 1;
            D_8010A702_14C092_RainbowRun = 1;
            func_800B75A8_B81A8(-50.0f, -obj->trans.x + D_8010A7D0_14C160_RainbowRun);
            ((void (*)(omObjData*, f32, f32, f32, f32, f32))func_8000BF24_CB24)(
                D_800FC7B0_FD3B0[1], D_8010A7D4_14C164_RainbowRun, -4000.0f, -4000.0f, 4000.0f, 4000.0f);
            func_8000BFF0_CBF0(D_800FC7B0_FD3B0[1]);
            func_8000C024_CC24(obj, 0, 1);
            func_8000C024_CC24(obj, 1, 2);
            D_800FC834_FD434[D_800FFFD8_100BD8[0]->model[1]].pos.x = D_8010A7D0_14C160_RainbowRun;
            ContStkX[w->port] = 0;
            ContStkY[w->port] = 0;
            D_8010A7A8_14C138_RainbowRun = 1;
        } else if (obj->trans.z > -1400.0f) {
            ContStkX[w->port] = 0;
            ContStkY[w->port] = 40;
            D_8010A6F7_14C087_RainbowRun = 1;
            D_8010A6F4_14C084_RainbowRun = 0;
        } else {
            ContStkX[w->port] = 0;
            ContStkY[w->port] = 0;
            w->angle = 0.0f;
            w->speed = 0.0f;
            D_8010A6F0_14C080_RainbowRun = 1;
            D_8010A6F6_14C086_RainbowRun = 3;
            if (D_8010A700_14C090_RainbowRun == 1) {
                if (D_8010A711_14C0A1_RainbowRun == 0) {
                    if (D_8010A712_14C0A2_RainbowRun == 0) {
                        D_8010A9A8_14C338_RainbowRun = 324.0f - D_8010AC10_14C5A0_RainbowRun;
                        D_8010A9AC_14C33C_RainbowRun = -580.0f - D_8010ABEC_14C57C_RainbowRun;
                        D_8010A9B0_14C340_RainbowRun = -2154.0f - D_8010AC04_14C594_RainbowRun;
                    }
                    if (D_8010A712_14C0A2_RainbowRun++ < 20) {
                        D_8010AC10_14C5A0_RainbowRun += D_8010A9A8_14C338_RainbowRun / 20.0f;
                        D_8010ABEC_14C57C_RainbowRun += D_8010A9AC_14C33C_RainbowRun / 20.0f;
                        D_8010AC04_14C594_RainbowRun += D_8010A9B0_14C340_RainbowRun / 20.0f;
                    } else {
                        D_8010A711_14C0A1_RainbowRun = 1;
                        D_8010A703_14C093_RainbowRun = 1;
                    }
                } else {
                    func_80019B9C_1A79C(D_800FFFD8_100BD8[0], 0xD);
                    func_80019378_19F78(D_800FFFD8_100BD8[0]);
                    func_800732B0_73EB0(D_800CD438_CE038[gPlayers[D_8010ACC0_14C650_RainbowRun[0]].character].unk_04 | 0x4F);
                    w->angle = 0.0f;
                    w->speed = 0.0f;
                }
            }
        }
    }
    if (w->unk_BE == 0) {
        if (w->speed >= D_800BF7C0_C03C0) {
            w->speed = D_800BF7C0_C03C0;
        }
    } else if (D_8010A702_14C092_RainbowRun != 1) {
        ContStkX[w->port] = 0;
    }
    func_80007790_8390(obj);
    func_800298A4_2A4A4(obj->model[1], 4, 4);
    if (D_8010A702_14C092_RainbowRun != 1 && obj->trans.y < D_8010A7D4_14C164_RainbowRun + -50.0) {
        if (D_8010A710_14C0A0_RainbowRun == 0) {
            func_800794A8_7A0A8(40);
            D_8010A710_14C0A0_RainbowRun = 1;
        }
        if (D_8010A713_14C0A3_RainbowRun == 0) {
            func_800797DC_7A3DC(0x111, D_8010ACC0_14C650_RainbowRun[0]);
            D_8010A70E_14C09E_RainbowRun = 1;
            D_8010A701_14C091_RainbowRun = 1;
            D_8010A6F7_14C087_RainbowRun = 1;
            D_8010A6F5_14C085_RainbowRun = 1;
            D_8010A713_14C0A3_RainbowRun = 1;
            D_800BF7AC_C03AC = 7.0f;
        }
        if (obj->trans.x > 0.0f) {
            ContStkX[w->port] = 60;
        } else {
            ContStkX[w->port] = -60;
        }
    }
    if (D_8010A70F_14C09F_RainbowRun == 0 && obj->trans.y <= -600.0f) {
        D_8010A6F6_14C086_RainbowRun = 1;
        D_8010A70F_14C09F_RainbowRun = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0F_RainbowRun/144190", func_80104FB4_146944_RainbowRun);

void func_801057F0_147180_RainbowRun(f32 zoom, f32 rx, f32 ry, f32 rz, f32 cx, f32 cy, f32 cz) {
    D_800FA610_FB210 = D_8010AA10_14C3A0_RainbowRun = zoom;
    D_800FD474_FE074.x = D_8010AC10_14C5A0_RainbowRun = rx;
    D_800FD474_FE074.y = D_8010ABF8_14C588_RainbowRun = ry;
    D_800FD474_FE074.z = D_8010ABF4_14C584_RainbowRun = rz;
    D_8010274C_10334C.x = D_8010ACBC_14C64C_RainbowRun = cx;
    D_8010274C_10334C.y = D_8010ABEC_14C57C_RainbowRun = cy;
    D_8010274C_10334C.z = D_8010AC04_14C594_RainbowRun = cz;
}

/* The camera: a short shake while D_8010A751 is set. */
void func_80105870_147200_RainbowRun(void) {
    if (D_8010A751_14C0E1_RainbowRun == 1) {
        f32 dx = D_8010A758_14C0E8_RainbowRun[(D_8010A752_14C0E2_RainbowRun & 3) * 2];
        f32 dy = D_8010A75C_14C0EC_RainbowRun[(D_8010A752_14C0E2_RainbowRun & 3) * 2];

        D_8010274C_10334C.x = dx + D_8010ACBC_14C64C_RainbowRun;
        D_8010274C_10334C.y = dy + D_8010ABEC_14C57C_RainbowRun;
        if (++D_8010A752_14C0E2_RainbowRun >= 11) {
            D_8010A751_14C0E1_RainbowRun = 0;
            D_8010A752_14C0E2_RainbowRun = 0;
        }
    } else {
        D_8010274C_10334C.x = D_8010ACBC_14C64C_RainbowRun;
        D_8010274C_10334C.y = D_8010ABEC_14C57C_RainbowRun;
    }
    D_800FA610_FB210 = D_8010AA10_14C3A0_RainbowRun;
    D_800FD474_FE074.x = D_8010AC10_14C5A0_RainbowRun;
    D_800FD474_FE074.y = D_8010ABF8_14C588_RainbowRun;
    D_800FD474_FE074.z = D_8010ABF4_14C584_RainbowRun;
    D_80102750_103350[1] = D_8010AC04_14C594_RainbowRun;
}

/* Ends the minigame once the result is in: fade out, then return. */
void func_80105978_147308_RainbowRun(omObjData* obj) {
    if (D_801011FC_101DFC == 1) {
        if (D_8010A778_14C108_RainbowRun == 0) {
            InitFadeOut(0, 0x14);
            D_8010A778_14C108_RainbowRun = 1;
        } else if (func_8008F618_90218() == 0) {
            func_800794A8_7A0A8(0x28);
            func_80069770_6A370();
            omOvlReturnEx(1);
        }
    }
}

/* The shadow: smaller the higher the object is. */
void func_801059F0_147380_RainbowRun(omObjData* obj) {
    f32 scale = 0.4f - obj->trans.y * 0.0015f;

    func_800297E8_2A3E8(obj->model[1], scale, 0.0f, scale);
    func_80029714_2A314(obj->model[1], obj->trans.x, 2.4f, obj->trans.z);
}

/* The stick direction of player 0's port, averaged over 8 frames (-1 near the centre). */
f32 func_80105A74_147404_RainbowRun(void) {
    s8 port = RR_WORK(D_800FFFD8_100BD8[0])->port;
    s8 y = ContStkY[port];
    s8 x = ContStkX[port];
    f32 sumX;
    f32 sumY;
    f32 angle;
    s16 i;

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
    D_8010A77C_14C10C_RainbowRun[D_8010A78C_14C11C_RainbowRun] = (f32)x;
    D_8010A784_14C114_RainbowRun[D_8010A78C_14C11C_RainbowRun] = (f32)y;
    D_8010A78C_14C11C_RainbowRun = (D_8010A78C_14C11C_RainbowRun + 1) & 7;
    sumX = sumY = 0.0f;
    for (i = 0; i < 8; i++) {
        sumX += D_8010A77C_14C10C_RainbowRun[i];
        sumY += D_8010A784_14C114_RainbowRun[i];
    }
    sumX /= 8.0f;
    sumY /= 8.0f;
    if (sumX * sumX + sumY * sumY > 100.0f) {
        angle = func_800B75A8_B81A8(sumX, -sumY) + 180.0f;
    } else {
        angle = -1.0f;
    }
    return angle;
}

/* Rotation of angle about axis, translated (retail uses pos->z where pos->x would be expected, as
   MP1's func_800F8F70_TightropeTreachery). */
void func_80105C40_1475D0_RainbowRun(Vec* pos, Vec* axis, f32 angle, Matrix4f m) {
    f32 s;
    f32 c;
    f32 t;
    f32 x;
    f32 y;
    f32 z;
    f32 xx;
    f32 yy;
    f32 zz;
    f32 xs;
    f32 ys;
    f32 zs;
    f32 xy;
    f32 xz;
    f32 yz;
    f32 py;
    f32 pz;
    f32 txy;
    f32 txz;
    f32 tyz;

    func_800B8070_B8C70(angle, &s, &c);
    t = 1.0f - c;
    pz = pos->z;
    py = pos->y;
    x = axis->x;
    y = axis->y;
    z = axis->z;
    xy = x * y;
    yz = y * z;
    xz = z * x;
    xx = x * x;
    yy = y * y;
    zz = z * z;
    xs = x * s;
    ys = y * s;
    zs = z * s;
    m[3][3] = 1.0f;
    m[0][3] = m[1][3] = m[2][3] = 0.0f;
    m[0][0] = t * xx + c;
    txy = t * xy;
    m[0][1] = txy + zs;
    txz = t * xz;
    m[0][2] = txz - ys;
    m[1][0] = txy - zs;
    m[1][1] = t * yy + c;
    tyz = t * yz;
    m[1][2] = tyz + xs;
    m[2][0] = txz + ys;
    m[2][1] = tyz - xs;
    m[2][2] = t * zz + c;
    m[3][0] = pz * t * (1.0f - xx) + py * (zs - txy) - pz * (txz + ys);
    m[3][1] = -pz * (txy + zs) + py * t * (1.0f - yy) + pz * (xs - tyz);
    m[3][2] = pz * (ys - txz) - py * (tyz + xs) + pz * t * (1.0f - zz);
}

/* A CPU player presses nothing but Z. */
void func_80105E38_1477C8_RainbowRun(RRPlayerWork* work) {
    u16 btn = 0;

    if (ContBtn[work->port] & 0x1000) {
        btn |= 0x1000;
    }
    ContBtnTrg[work->port] = ContBtn[work->port] = btn;
    ContBtnTrg[work->port] = btn & (btn ^ D_8010A78E_14C11E_RainbowRun);
    D_8010A78E_14C11E_RainbowRun = btn;
    ContStkX[work->port] = 0;
    ContStkY[work->port] = 0;
}

void func_80105ED4_147864_RainbowRun(omObjData* obj, f32 dist) {
    D_8010A754_14C0E4_RainbowRun -= dist;
    ((void (*)(omObjData*, f32, f32, f32, f32, f32))func_8000BF24_CB24)(obj, -4000.0f, -800.0f, -1200.0f, 800.0f, D_8010A754_14C0E4_RainbowRun + 1200.0f);
    func_8000BFF0_CBF0(obj);
}

/* Park-Miller minimal standard generator (Schrage's method). */
u32 func_80105F4C_1478DC_RainbowRun(u32 seed) {
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

u32 func_80106020_1479B0_RainbowRun(void) {
    return D_8010A790_14C120_RainbowRun = func_80105F4C_1478DC_RainbowRun(D_8010A790_14C120_RainbowRun);
}
