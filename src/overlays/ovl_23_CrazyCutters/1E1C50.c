#include "ovl_23.h"

/* Per screen quarter: the shape sprite's centre (MP1 D_800FCFA8, .data there). */
const s16 D_801093F0_1E8840_CrazyCutters[4][2] = { { 0x38, 0x5A }, { 0xD8, 0x5A }, { 0x38, 0xD2 }, { 0xD8, 0xD2 } };
/* Unreferenced (MP1 D_800FCFB8, D_800FCFD0). */
const s32 D_80109400_1E8850_CrazyCutters[4] = { 0x29E, 0x29E, 0x23A, 0 };
const u8 D_80109410_1E8860_CrazyCutters[0x40] = {
    0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,
    0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0,
    0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x00,
};


void func_80102800_1E1C50_CrazyCutters(void) {
    s32 shapes[3] = { 2, 0, 1 };
    s32 i;
    s16 grp;

    func_8002D4D0_2E0D0(20);
    func_80020D20_21920(66);
    omInitObjMan(40, 0);
    func_80079128_79D28();
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_80079E60_7AA60), 0xA0);
    D_801098FC_1E8D4C_CrazyCutters = 0;
    D_801099F4_1E8E44_CrazyCutters = 0;
    func_80102B64_1E1FB4_CrazyCutters(7000.0f, 270.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
    func_80076BD0_777D0(4, 4);
    func_8010874C_1E7B9C_CrazyCutters();
    omAddObj(10, 0, 0, -1, func_801057D8_1E4C28_CrazyCutters);
    D_80109918_1E8D68_CrazyCutters = shapes[D_800FA656];
    D_801099E8_1E8E38_CrazyCutters = 2.0f;
    D_80109948_1E8D98_CrazyCutters = 0;
    D_801099C8_1E8E18_CrazyCutters = -1;
    D_801099CC_1E8E1C_CrazyCutters = -1;
    D_801099D0_1E8E20_CrazyCutters = -1;
    D_801098F8_1E8D48_CrazyCutters = 71;
    omAddObj(12, 0, 0, -1, func_80102C18_1E2068_CrazyCutters);
    D_80109900_1E8D50_CrazyCutters = 1;
    func_8002CA48_2D648(0, 0, 0);
    func_80108214_1E7664_CrazyCutters();
    for (i = 0; i < 4; i++) {
        s32 q = func_8010882C_1E7C7C_CrazyCutters(i);

        grp = func_80108284_1E76D4_CrazyCutters(*(*(D_801093F0_1E8840_CrazyCutters + q) + 0), *(*(D_801093F0_1E8840_CrazyCutters + q) + 1));
        D_80109A48_1E8E98_CrazyCutters[i] = grp;
        func_801084A0_1E78F0_CrazyCutters(grp);
    }
    D_80109A50_1E8EA0_CrazyCutters = 0;
    D_8010957E_1E89CE_CrazyCutters = 30;
    D_80109A00_1E8E50_CrazyCutters = _CheckFlag(0xC);
}

void func_80102A44_1E1E94_CrazyCutters(omObjData* obj) {
    if (--D_801098F8_1E8D48_CrazyCutters == 0) {
        D_801098F8_1E8D48_CrazyCutters = 28;
        D_80109A9A_1E8EEA_CrazyCutters = -1;
        func_800691FC_69DFC(0);
        obj->func_ptr = func_80102AA8_1E1EF8_CrazyCutters;
    }
}

void func_80102AA8_1E1EF8_CrazyCutters(omObjData* obj) {
    if (func_80069538_6A138() == 0 || func_80069538_6A138() & 2) {
        if (--D_801098F8_1E8D48_CrazyCutters == 0) {
            D_80109948_1E8D98_CrazyCutters = 1;
            func_8010593C_1E4D8C_CrazyCutters();
            obj->func_ptr = func_80105978_1E4DC8_CrazyCutters;
        }
    } else if (D_80109A9A_1E8EEA_CrazyCutters == -1) {
        if (--D_801098F8_1E8D48_CrazyCutters == 0) {
            D_80109A9A_1E8EEA_CrazyCutters = PlayMusic(0x21);
            D_801098F8_1E8D48_CrazyCutters = 20;
        }
    }
}

void func_80102B64_1E1FB4_CrazyCutters(f32 zoom, f32 rx, f32 ry, f32 rz, f32 cx, f32 cy, f32 cz) {
    func_80018E30_19A30(1);
    D_800FA610_FB210 = zoom;
    D_800FD474_FE074.x = rx;
    D_800FD474_FE074.y = ry;
    D_800FD474_FE074.z = rz;
    D_8010274C_10334C.x = cx;
    D_8010274C_10334C.y = cy;
    D_8010274C_10334C.z = cz;
    Hu3DCamSetPerspective(0, 10.0f, D_800C9B80_CA780->fov[1], D_800C9B80_CA780->fov[2]);
}

void func_80102C18_1E2068_CrazyCutters(omObjData* obj) {
    if (--D_80109900_1E8D50_CrazyCutters == 0) {
        D_801098FC_1E8D4C_CrazyCutters = 1;
        omAddObj(4, 10, 10, 4, func_80105648_1E4A98_CrazyCutters);
        omAddObj(4, 10, 10, 4, func_80105664_1E4AB4_CrazyCutters);
        omAddObj(4, 10, 10, 4, func_80105680_1E4AD0_CrazyCutters);
        omAddObj(4, 10, 10, 4, func_8010569C_1E4AEC_CrazyCutters);
        omAddObj(0, 0, 0, -1, func_80102A44_1E1E94_CrazyCutters);
        omAddObj(2, 1, 1, -1, func_80102D30_1E2180_CrazyCutters);
        InitFadeIn(0, 16);
        omDelObj(obj);
    }
}

void func_80102D30_1E2180_CrazyCutters(omObjData* obj) {
    s32 shapes[3] = { 3, 4, 5 };
    s32 tiles[3] = { 0x19, 0x1A, 0x1B };
    s32 i;
    s32 x;
    s32 y;
    s16 sprite;

    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    sprite = func_8001A2F8_1AEF8(tiles[D_80109918_1E8D68_CrazyCutters] | 0x330000);
    i = 0;
    for (y = 0; y < 8; y++) {
        for (x = 0; x < 10; x++) {
            D_801095C8_1E8A18_CrazyCutters[i] = func_8001AAAC_1B6AC(sprite, 0, 1);
            func_8001A708_1B308(D_801095C8_1E8A18_CrazyCutters[i], 0x4008);
            D_80109670_1E8AC0_CrazyCutters[i] = x * 32 + 16;
            D_801097B0_1E8C00_CrazyCutters[i] = y * 32 + 16;
            espPosSet(D_801095C8_1E8A18_CrazyCutters[i], D_80109670_1E8AC0_CrazyCutters[i], D_801097B0_1E8C00_CrazyCutters[i]);
            espDispOn(D_801095C8_1E8A18_CrazyCutters[i]);
            func_8001A91C_1B51C(D_801095C8_1E8A18_CrazyCutters[i], 1.0f, 1.0f);
            i++;
        }
    }
    for (y = 0; y < 2; y++) {
        for (x = 0; x < 2; x++) {
            D_80109598_1E89E8_CrazyCutters[y * 2 + x] = func_8001A2F8_1AEF8(shapes[D_80109918_1E8D68_CrazyCutters] | 0x330000);
            D_801095B0_1E8A00_CrazyCutters[y * 2 + x] = func_8001AAAC_1B6AC(D_80109598_1E89E8_CrazyCutters[y * 2 + x], 0, 1);
            func_8001A708_1B308(D_801095B0_1E8A00_CrazyCutters[y * 2 + x], 0x4008);
            i = func_8010882C_1E7C7C_CrazyCutters(y * 2 + x);
            espPosSet(D_801095B0_1E8A00_CrazyCutters[y * 2 + x], D_80109070_1E84C0_CrazyCutters[i], D_80109080_1E84D0_CrazyCutters[i]);
            espDispOn(D_801095B0_1E8A00_CrazyCutters[y * 2 + x]);
            func_8001A91C_1B51C(D_801095B0_1E8A00_CrazyCutters[y * 2 + x], 1.0f, 1.0f);
        }
    }
    D_80109668_1E8AB8_CrazyCutters = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x330018), 0, 1);
    func_8001A708_1B308(D_80109668_1E8AB8_CrazyCutters, 0x4008);
    D_801098F0_1E8D40_CrazyCutters = 160;
    D_801098F4_1E8D44_CrazyCutters = 120;
    espPosSet(D_80109668_1E8AB8_CrazyCutters, D_801098F0_1E8D40_CrazyCutters, D_801098F4_1E8D44_CrazyCutters);
    espDispOn(D_80109668_1E8AB8_CrazyCutters);
    func_8001A91C_1B51C(D_80109668_1E8AB8_CrazyCutters, 1.0f, 1.0f);
    obj->func_ptr = func_801030B4_1E2504_CrazyCutters;
}

void func_801030B4_1E2504_CrazyCutters(omObjData* obj) {
    s32 i;

    if (D_801099F4_1E8E44_CrazyCutters == 1 || D_801099F4_1E8E44_CrazyCutters == 2) {
        if (D_801099F8_1E8E48_CrazyCutters & 1) {
            for (i = 0; i < 80; i++) {
                espPosSet(D_801095C8_1E8A18_CrazyCutters[i], D_80109670_1E8AC0_CrazyCutters[i],
                          D_801097B0_1E8C00_CrazyCutters[i] + (u16)D_801099F4_1E8E44_CrazyCutters);
            }
            for (i = 0; i < 4; i++) {
                s32 q = func_8010882C_1E7C7C_CrazyCutters(i);

                espPosSet(D_801095B0_1E8A00_CrazyCutters[i], D_80109070_1E84C0_CrazyCutters[q],
                          D_80109080_1E84D0_CrazyCutters[q] + (u16)D_801099F4_1E8E44_CrazyCutters);
            }
            espPosSet(D_80109668_1E8AB8_CrazyCutters, D_801098F0_1E8D40_CrazyCutters,
                      D_801098F4_1E8D44_CrazyCutters + (u16)D_801099F4_1E8E44_CrazyCutters);
        } else {
            for (i = 0; i < 80; i++) {
                espPosSet(D_801095C8_1E8A18_CrazyCutters[i], D_80109670_1E8AC0_CrazyCutters[i], D_801097B0_1E8C00_CrazyCutters[i]);
            }
            for (i = 0; i < 4; i++) {
                s32 q = func_8010882C_1E7C7C_CrazyCutters(i);

                espPosSet(D_801095B0_1E8A00_CrazyCutters[i], D_80109070_1E84C0_CrazyCutters[q], D_80109080_1E84D0_CrazyCutters[q]);
            }
            espPosSet(D_80109668_1E8AB8_CrazyCutters, D_801098F0_1E8D40_CrazyCutters, D_801098F4_1E8D44_CrazyCutters);
        }
    }
    if (D_801099F4_1E8E44_CrazyCutters == 3) {
        func_80079848_7A448(D_80109A90_1E8EE0_CrazyCutters);
        omAddObj(12, 0, 0, -1, func_8010332C_1E277C_CrazyCutters);
        D_801098F8_1E8D48_CrazyCutters = 0;
        omDelObj(obj);
    }
}

/* Retail quirk: with result kind 4 the object moves on at frame 30, so its frame-55 branch
   (MP1: end at frame 90) never runs. */
void func_8010332C_1E277C_CrazyCutters(omObjData* obj) {
    s32 i;

    if (D_80109A00_1E8E50_CrazyCutters == 0) {
        D_801098F8_1E8D48_CrazyCutters++;
        if (D_801099F0_1E8E40_CrazyCutters == 4) {
            if (D_801098F8_1E8D48_CrazyCutters == 15) {
                PlayMusic(0x52);
            }
            if (D_801098F8_1E8D48_CrazyCutters == 55) {
                for (i = 0; i < 4; i++) {
                    func_80106D44_1E6194_CrazyCutters(i, 2, 1);
                }
            }
            if (D_801098F8_1E8D48_CrazyCutters == 30) {
                obj->func_ptr = func_80106B54_1E5FA4_CrazyCutters;
            }
        } else if (D_801099F0_1E8E40_CrazyCutters == 0) {
            if (D_801098F8_1E8D48_CrazyCutters == 1) {
                PlayMusic(0x57);
                for (i = 0; i < 4; i++) {
                    func_80106D44_1E6194_CrazyCutters(i, 4, 1);
                }
            }
            if (D_801098F8_1E8D48_CrazyCutters == 120) {
                obj->func_ptr = func_80106B54_1E5FA4_CrazyCutters;
            }
        } else {
            if (D_801098F8_1E8D48_CrazyCutters == 55) {
                PlayMusic(D_801099F0_1E8E40_CrazyCutters == 1 ? 0x51 : 0x52);
                for (i = 0; i < 4; i++) {
                    if (func_80106D28_1E6178_CrazyCutters(i, 0x10000) != 0) {
                        func_80106D44_1E6194_CrazyCutters(i, 2, 1);
                    } else {
                        func_80106D44_1E6194_CrazyCutters(i, 4, 1);
                    }
                }
            }
            if (D_801099F0_1E8E40_CrazyCutters == 1) {
                if (D_801098F8_1E8D48_CrazyCutters == 85) {
                    obj->func_ptr = func_80106B54_1E5FA4_CrazyCutters;
                }
            }
            if (D_801099F0_1E8E40_CrazyCutters != 1) {
                if (D_801098F8_1E8D48_CrazyCutters == 133) {
                    obj->func_ptr = func_80106B54_1E5FA4_CrazyCutters;
                }
            }
        }
    } else {
        obj->func_ptr = func_80106B54_1E5FA4_CrazyCutters;
    }
}

__asm__(".section .rodata");
const u32 D_80109474_1E88C4_CrazyCutters[6] = { 0x00000023, 0x00000023, 0x00000023, 0x00000023, 0x00000023, 0x00000023 };

__asm__(".section .rodata");
const u32 D_8010948C_1E88DC_CrazyCutters[4] = { 0x00000010, 0x00000008, 0x00000004, 0x00000002 };

__asm__(".section .rodata");
const u32 D_8010949C_1E88EC_CrazyCutters[4] = { 0x00000018, 0x00000012, 0x0000000C, 0x00000006 };

__asm__(".section .rodata");
const u32 D_801094AC_1E88FC_CrazyCutters[3] = { 0x00000009, 0x0000000A, 0x0000000B };

__asm__(".section .rodata");
const char D_801094B8_1E8908_CrazyCutters[] = "16mt000_DEF";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80103508_1E2958_CrazyCutters);

void func_801040F0_1E3540_CrazyCutters(omObjData* obj) {
    CCPlayer* st = obj->unk_50;
    s16 cur[2];
    s16 next[2];
    Vec pos;
    s32 i;
    s32 q;

    q = func_8010882C_1E7C7C_CrazyCutters(st->player);
    if (func_80106D28_1E6178_CrazyCutters(st->player, 0x400) != 0) {
        if (--st->timer == 0) {
            func_80029B80_2A780(obj->model[0], obj->motion[4]);
            func_80106D44_1E6194_CrazyCutters(st->player, 0x400, 0);
            func_80106D44_1E6194_CrazyCutters(st->player, 0x200, 1);
            st->velZ = -7.0f;
            st->timer = 20;
            st->velX = (st->startX - st->x) / 30.0f;
            st->rotZ = 90.0f;
            omSetRot(obj, st->rotX, st->rotY, 90.0f);
            st->state = 4;
        }
    }
    if (func_80106D28_1E6178_CrazyCutters(st->player, 0x200) != 0) {
        st->x += st->velX;
        st->z += st->velZ;
        st->timer--;
        omSetTra(obj, D_80109090_1E84E0_CrazyCutters[q] + st->x, st->y, D_801090A0_1E84F0_CrazyCutters[q] + st->z + -4.0f);
        st->velZ += 0.49f;
        if (st->velZ >= 0.0f && st->state == 4) {
            func_80029B80_2A780(obj->model[0], obj->motion[5]);
            st->state = 5;
        }
        if (st->x <= st->startX + 40.0f) {
            st->x = st->startX;
            st->z = st->startZ;
            st->rotZ = 0.0f;
            func_80029B80_2A780(obj->model[0], obj->motion[1]);
            func_80029E80_2AA80(obj->model[0], 2, 2);
            omSetTra(obj, D_80109090_1E84E0_CrazyCutters[q] + st->x, st->y, D_801090A0_1E84F0_CrazyCutters[q] + st->z + -4.0f);
            omSetRot(obj, st->rotX, st->rotY, st->rotZ);
            func_80106D44_1E6194_CrazyCutters(st->player, 0x200, 0);
            func_8003E4F4_3F0F4(st->unk468, 1, 0);
            func_800298A4_2A4A4(obj->model[2], 4, 0);
            func_8003E4F4_3F0F4(st->unk46A, 1, 0);
            func_8003E4F4_3F0F4(st->unk46A, 2, 0);
            pos.x = D_80109090_1E84E0_CrazyCutters[q] + st->x - 8.0f;
            pos.y = st->y + 10.0f;
            pos.z = D_801090A0_1E84F0_CrazyCutters[q] + st->z - 8.0f;
            func_8010585C_1E4CAC_CrazyCutters(&pos, cur, q);
            i = 0;
            while (1) {
                if (st->pathX[i] == -3) {
                    break;
                }
                i++;
            }
            st->pathX[i] = cur[0];
            st->pathY[i] = cur[1];
            st->startGX = cur[0];
            st->startGY = cur[1];
            D_801099FC_1E8E4C_CrazyCutters = i;
            if (gPlayers[st->player].flags & 1) {
                next[0] = st->pathX[st->target];
                next[1] = st->pathY[st->target];
                st->angle = func_80106EB0_1E6300_CrazyCutters(cur, next, 0);
            }
            obj->func_ptr = func_8010454C_1E399C_CrazyCutters;
            if (st->player == 0) {
                D_80109A92_1E8EE2_CrazyCutters = PlaySound(0x25B);
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_8010454C_1E399C_CrazyCutters);

/* Whether cur is one of the cutter's last positions (crossing its own fresh cut): 20 for a CPU,
   else 10, or 60 when wide. */
s32 func_80104FF4_1E4444_CrazyCutters(CCPlayer* st, s16* cur, s32 wide) {
    s32 i;
    s32 n;

    D_80109560_1E89B0_CrazyCutters = 0;
    if (gPlayers[st->player].flags & 1) {
        n = 20;
    } else {
        n = 10;
        if (wide != 0) {
            n = 60;
        }
    }
    for (i = 1; i < n; i++) {
        if (cur[0] == st->trailX[i] && cur[1] == st->trailY[i]) {
            D_80109560_1E89B0_CrazyCutters = 1;
            break;
        }
    }
    return D_80109560_1E89B0_CrazyCutters;
}

/* Whether the cutter has stood on cur for the last 10 frames. */
s32 func_80105098_1E44E8_CrazyCutters(CCPlayer* st, s16* cur) {
    s32 i;

    D_80109564_1E89B4_CrazyCutters = 0;
    for (i = 0; i < 10; i++) {
        if (cur[0] != st->lastX[i] || cur[1] != st->lastY[i]) {
            break;
        }
    }
    if (i == 10) {
        D_80109564_1E89B4_CrazyCutters = 1;
    }
    return D_80109564_1E89B4_CrazyCutters;
}

void func_801050FC_1E454C_CrazyCutters(CCPlayer* st, s16* cur) {
    s32 i;
    s32 found;

    if (st->trailX[0] != cur[0] || st->trailY[0] != cur[1]) {
        for (i = 1; i < 60; i++) {
            st->trailX[60 - i] = st->trailX[59 - i];
            st->trailY[60 - i] = st->trailY[59 - i];
        }
        st->trailX[0] = cur[0];
        st->trailY[0] = cur[1];
    }
    found = 0;
    if (st->visitedCount < 30) {
        for (i = 0; i < 30; i++) {
            if (st->visitedX[i] == cur[0] && st->visitedY[i] == cur[1]) {
                found++;
                break;
            }
        }
        if (found == 0) {
            st->visitedX[st->visitedCount] = cur[0];
            st->visitedY[st->visitedCount] = cur[1];
            st->visitedCount++;
        }
    }
    for (i = 1; i < 10; i++) {
        st->lastX[10 - i] = st->lastX[9 - i];
        st->lastY[10 - i] = st->lastY[9 - i];
    }
    st->lastX[0] = cur[0];
    st->lastY[0] = cur[1];
}

void func_80105254_1E46A4_CrazyCutters(omObjData* obj) {
    s32 motions[3] = { 0xC, 0xD, 0xE };
    s32 sprites[3] = { 0xF, 0x10, 0x11 };
    CCPlayer* st = obj->unk_50;
    s32 q;
    s32 count;
    s32 i;
    f32 end;

    q = func_8010882C_1E7C7C_CrazyCutters(st->player);
    if (D_80109A00_1E8E50_CrazyCutters == 0) {
        if (func_80106D28_1E6178_CrazyCutters(st->player, 2) != 0) {
            func_80029B80_2A780(obj->model[0], obj->motion[2]);
            func_80106D44_1E6194_CrazyCutters(st->player, 0x10, 1);
            func_80106D44_1E6194_CrazyCutters(st->player, 2, 0);
            func_80073328_73F28(D_80109A60_1E8EB0_CrazyCutters[st->player], -1, 0x7A, st->player);
        }
        if (D_80109A00_1E8E50_CrazyCutters == 0) {
            if (func_80106D28_1E6178_CrazyCutters(st->player, 4) != 0) {
                /* MP1 waited here for every falling piece (flag 0x80); MP2 counts and ignores it */
                count = 0;
                for (i = 0; i < 4; i++) {
                    count += func_80106D28_1E6178_CrazyCutters(i, 0x80);
                }
                func_80029B80_2A780(obj->model[0], obj->motion[3]);
                func_80106D44_1E6194_CrazyCutters(st->player, 0x10, 1);
                func_80106D44_1E6194_CrazyCutters(st->player, 4, 0);
                if (D_80109A50_1E8EA0_CrazyCutters == 0) {
                    func_80107DA4_1E71F4_CrazyCutters();
                    D_80109A50_1E8EA0_CrazyCutters++;
                }
            }
        }
    }
    if (func_80106D28_1E6178_CrazyCutters(st->player, 8) != 0) {
        func_801078A8_1E6CF8_CrazyCutters(obj, sprites[D_80109918_1E8D68_CrazyCutters], motions[D_80109918_1E8D68_CrazyCutters], st->player);
        func_80106D44_1E6194_CrazyCutters(st->player, 8, 0);
    }
    if (func_80106D28_1E6178_CrazyCutters(st->player, 0x100) != 0 && D_801099F4_1E8E44_CrazyCutters < 2) {
        D_801099F4_1E8E44_CrazyCutters = 2;
        D_801099F8_1E8E48_CrazyCutters = 30;
    }
    if (D_801099F4_1E8E44_CrazyCutters > 0 && D_801099F4_1E8E44_CrazyCutters < 3) {
        if (--st->unk568 == 0) {
            omVibrate(st->player, 10, 0, 10);
            st->unk568 = 5;
        }
        if (D_801099F8_1E8E48_CrazyCutters & 1) {
            omSetTra(obj, D_80109090_1E84E0_CrazyCutters[q] + st->x, st->y,
                     D_801090A0_1E84F0_CrazyCutters[q] + st->z + st->unk2C + -4.0f + D_801099F4_1E8E44_CrazyCutters * 5.0f);
        } else {
            omSetTra(obj, D_80109090_1E84E0_CrazyCutters[q] + st->x, st->y,
                     D_801090A0_1E84F0_CrazyCutters[q] + st->z + st->unk2C + -4.0f);
        }
    }
    if (D_801099F4_1E8E44_CrazyCutters == 3 && func_80106D28_1E6178_CrazyCutters(st->player, 0x100) != 0) {
        func_80106D44_1E6194_CrazyCutters(st->player, 0x100, 0);
        func_80105A74_1E4EC4_CrazyCutters(st);
    }
    end = func_80029CE4_2A8E4(obj->model[0]);
    if (func_80029D0C_2A90C(obj->model[0]) <= end && func_80106D28_1E6178_CrazyCutters(st->player, 0x10) != 0) {
        func_80106D44_1E6194_CrazyCutters(st->player, 0x10, 0);
        func_80106D44_1E6194_CrazyCutters(st->player, 0x20, 1);
        omDelObj(obj);
    }
}

void func_80105648_1E4A98_CrazyCutters(omObjData* obj) {
    func_80103508_1E2958_CrazyCutters(obj, 0);
}

void func_80105664_1E4AB4_CrazyCutters(omObjData* obj) {
    func_80103508_1E2958_CrazyCutters(obj, 1);
}

void func_80105680_1E4AD0_CrazyCutters(omObjData* obj) {
    func_80103508_1E2958_CrazyCutters(obj, 2);
}

void func_8010569C_1E4AEC_CrazyCutters(omObjData* obj) {
    func_80103508_1E2958_CrazyCutters(obj, 3);
}

/* CPU steering: the angle from the cutter to its next route point. */
f32 func_801056B8_1E4B08_CrazyCutters(CCPlayer* st) {
    Vec pos;
    s16 cur[2];
    s16 next[2];
    s32 q;

    q = func_8010882C_1E7C7C_CrazyCutters(st->player);
    pos.x = D_80109090_1E84E0_CrazyCutters[q] + st->x - 8.0f;
    pos.y = st->y + 10.0f;
    pos.z = D_801090A0_1E84F0_CrazyCutters[q] + st->z - 8.0f;
    func_8010585C_1E4CAC_CrazyCutters(&pos, cur, q);
    if (cur[0] == st->pathX[st->target] && cur[1] == st->pathY[st->target]) {
        st->target++;
        if (st->pathX[st->target] == -2) {
            st->target = 0;
        }
    }
    next[0] = st->pathX[st->target];
    next[1] = st->pathY[st->target];
    D_80109568_1E89B8_CrazyCutters = func_80106EB0_1E6300_CrazyCutters(cur, next, 0);
    return D_80109568_1E89B8_CrazyCutters;
}

void func_801057D8_1E4C28_CrazyCutters(omObjData* obj) {
    if (D_801011FC_101DFC != 0) {
        InitFadeOut(0, 20);
        func_80079848_7A448(D_80109A92_1E8EE2_CrazyCutters);
        func_800794A8_7A0A8(40);
        obj->func_ptr = func_80105830_1E4C80_CrazyCutters;
    }
}

void func_80105830_1E4C80_CrazyCutters(omObjData* obj) {
    if (func_8008F618_90218() == 0) {
        omOvlReturnEx(1);
    }
}

/* World position -> grid cell of the cutter's screen quarter (MP1 scaled by 0.4; MP2 by 1). */
void func_8010585C_1E4CAC_CrazyCutters(Vec* pos, s16* out, s32 quarter) {
    Vec2f screen;

    Hu3DCam3DToScreen(0, pos, &screen);
    out[0] = screen.unk_00;
    out[1] = screen.unk_04;
    if (quarter & 1) {
        out[0] -= 160;
    }
    if (quarter / 2) {
        out[1] -= 120;
    }
    out[0] = out[0] * 1.0f;
    out[1] = out[1] * 1.0f;
}

void func_8010593C_1E4D8C_CrazyCutters(void) {
    D_8010957E_1E89CE_CrazyCutters = 30;
    D_80109580_1E89D0_CrazyCutters = 30;
    func_800691FC_69DFC(10, 30, 160, 32);
}

void func_80105978_1E4DC8_CrazyCutters(omObjData* obj) {
    s32 i;
    s32 done;

    D_80109580_1E89D0_CrazyCutters--;
    if (D_80109580_1E89D0_CrazyCutters == 0) {
        D_80109580_1E89D0_CrazyCutters = 30;
        D_8010957E_1E89CE_CrazyCutters--;
    }
    func_8006D4D0_6E0D0(D_8010957E_1E89CE_CrazyCutters);
    done = 0;
    for (i = 0; i < 4; i++) {
        done += func_80106D28_1E6178_CrazyCutters(i, 1) | func_80106D28_1E6178_CrazyCutters(i, 0x800);
    }
    if ((D_8010957E_1E89CE_CrazyCutters == 0) | (done == 4)) {
        func_8006D518_6E118();
        func_80079848_7A448(D_80109A92_1E8EE2_CrazyCutters);
        obj->func_ptr = func_801067D4_1E5C24_CrazyCutters;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80105A74_1E4EC4_CrazyCutters);

__asm__(".section .rodata");
const u32 D_801094DC_1E892C_CrazyCutters[4] = { 0xC3C80000, 0x43C80000, 0xC3C80000, 0x43C80000 };

__asm__(".section .rodata");
const u32 D_801094EC_1E893C_CrazyCutters[4] = { 0xC37A0000, 0xC37A0000, 0x43AF0000, 0x43AF0000 };

__asm__(".section .rodata");
const u32 D_801094FC_1E894C_CrazyCutters[3] = { 0x40866666, 0x40900000, 0x40800000 };

__asm__(".section .rodata");
const u32 D_80109508_1E8958_CrazyCutters[3] = { 0xC1F00000, 0x00000000, 0xC2C80000 };

__asm__(".section .rodata");
const u32 D_80109514_1E8964_CrazyCutters[3] = { 0x00330015, 0x00330016, 0x00330017 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80105B40_1E4F90_CrazyCutters);

__asm__(".section .rodata");
const u32 D_80109520_1E8970_CrazyCutters[4] = { 0x00000012, 0x00000013, 0x00000014, 0x00000000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80105FE4_1E5434_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_801065F4_1E5A44_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_801067D4_1E5C24_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80106A5C_1E5EAC_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80106AD4_1E5F24_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80106B54_1E5FA4_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80106B94_1E5FE4_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80106D28_1E6178_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80106D44_1E6194_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80106D84_1E61D4_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80106EB0_1E6300_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80107204_1E6654_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80107530_1E6980_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_801076B8_1E6B08_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_801077B0_1E6C00_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_801078A8_1E6CF8_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_801079E0_1E6E30_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80107BBC_1E700C_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80107D74_1E71C4_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80107DA4_1E71F4_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80107DFC_1E724C_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80108108_1E7558_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80108214_1E7664_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80108284_1E76D4_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_801084A0_1E78F0_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_801084FC_1E794C_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_801086BC_1E7B0C_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_8010874C_1E7B9C_CrazyCutters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_8010882C_1E7C7C_CrazyCutters);
