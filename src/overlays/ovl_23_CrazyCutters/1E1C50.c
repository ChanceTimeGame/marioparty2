#include "ovl_23.h"

/* .data (0x1E84C0-0x1E8840, 80109070-801093F0) */

s32 D_80109070_1E84C0_CrazyCutters[4] = { 0x50, 0xF0, 0x50, 0xF0 };
s32 D_80109080_1E84D0_CrazyCutters[4] = { 0x3C, 0x3C, 0xB4, 0xB4 };
f32 D_80109090_1E84E0_CrazyCutters[4] = { -690.0f, 140.0f, -690.0f, 140.0f };
f32 D_801090A0_1E84F0_CrazyCutters[4] = { -530.0f, -530.0f, 95.0f, 95.0f };
s8 D_801090B0_1E8500_CrazyCutters[12] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0 };
s8 D_801090BC_1E850C_CrazyCutters[4] = { -1, 0, 0, 0 };
s32 D_801090C0_1E8510_CrazyCutters[6] = { 2, 3, 7, 4, 5, 6 };
s32 D_801090D8_1E8528_CrazyCutters[6] = { 0xD3, 0xD3, 0xD3, 0xD3, 0xD3, 0xD3 };
s32 D_801090F0_1E8540_CrazyCutters[6] = { 0, 0, 0, 0, 0, 0 };
s32 D_80109108_1E8558_CrazyCutters[6] = { 0x4E, 0x4E, 0x4E, 0x4E, 0x4E, 0x4E };
s32 D_80109120_1E8570_CrazyCutters[6] = { 0x4F, 0x4F, 0x4F, 0x4F, 0x4F, 0x4F };
s32 D_80109138_1E8588_CrazyCutters[6] = { 0x55, 0x55, 0x55, 0x55, 0x55, 0x55 };
s32 D_80109150_1E85A0_CrazyCutters[6] = { 0x56, 0x56, 0x56, 0x56, 0x56, 0x56 };
s32 D_80109168_1E85B8_CrazyCutters[6] = { 4, 4, 4, 4, 4, 4 };
s32 D_80109180_1E85D0_CrazyCutters[6] = { 0x2E, 0x2E, 0x2E, 0x2E, 0x2E, 0x2E };
s32 D_80109198_1E85E8_CrazyCutters[47] = {
    97, 30, 80, 27, 63, 31, 60, 34, 52, 41, 49, 46, 46, 53, 45, 63, 47, 73, 50, 78, 53, 84, 61, 91,
    73, 96, 84, 97, 90, 96, 100, 91, 106, 86, 111, 80, 114, 71, 114, 62, 114, 55, -3, -3, -2, -2, -1,
};
s32 D_80109254_1E86A4_CrazyCutters[49] = {
    97, 36, 87, 29, 74, 26, 56, 27, 46, 30, 44, 33, 43, 38, 44, 48, 48, 59, 52, 69, 56, 76, 64, 76, 76,
    84, 76, 97, 80, 96, 89, 87, 102, 84, 107, 77, 109, 66, 113, 56, 102, 55, 94, 43, -3, -3, -2, -2, -1,
};
s32 D_80109318_1E8768_CrazyCutters[51] = {
    89, 28, 84, 25, 76, 26, 68, 37, 61, 39, 49, 46, 43, 53, 42, 54, 48, 66, 47, 70, 47, 81, 55,
    92, 59, 91, 61, 89, 72, 95, 84, 95, 96, 94, 101, 91, 113, 97, 117, 92, 114, 69, 112, 55, 109, 47,
    -3, -3, -2, -2, -1,
};
s32 D_801093E4_1E8834_CrazyCutters[3] = { 15, 14, 13 };

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

// CPU character model file loaded before the directory, and table loads in v1 (masked 2)
#ifdef NON_MATCHING
/* {9, 10, 11}: a local initialiser here (unused) and in func_801065F4, which names it */
const s32 D_801094AC_1E88FC_CrazyCutters[3] = { 9, 10, 11 };
void func_80103508_1E2958_CrazyCutters(omObjData* obj, s32 player) {
    s32 px[30];
    s32 py[30];
    s32 motions[6] = { 0x23, 0x23, 0x23, 0x23, 0x23, 0x23 };
    Vec pos;
    s32 skip[4] = { 0x10, 8, 4, 2 };
    s32 chance[4] = { 0x18, 0x12, 0xC, 6 };
    s16 cur[2];
    s32 unused2[3] = { 9, 10, 11 };
    CCPlayer* st;
    s32* route;
    s32 i;
    s32 j;
    s32 q;
    s32 dir;
    s32 motion;
    s16 model;
    void* data;

    route = NULL;
    if (D_801098FC_1E8D4C_CrazyCutters == 0) {
        return;
    }
    D_80109A70_1E8EC0_CrazyCutters[player] = obj;
    obj->unk_50 = func_80027154_27D54(sizeof(CCPlayer), 0x7918);
    for (i = 0; i < 4; i++) {
        obj->work[i] = 0;
    }
    st = obj->unk_50;
    st->x = 620.0f;
    st->y = 0.0f;
    st->z = 180.0f;
    if ((u32)player >= 2) {
        st->z = 160.0f;
    }
    st->rotX = 290.0f;
    st->rotY = 0.0f;
    st->rotZ = 0.0f;
    st->velX = 0;
    st->angle = 0;
    st->unk28 = 0;
    st->unk448 = -1;
    st->unk44C = -1;
    st->player = player;
    st->unk2C = 0;
    st->unk568 = 1;
    for (i = 0; i < 60; i++) {
        st->trailX[i] = 0;
        st->trailY[i] = 0;
        st->visitedX[i] = 0;
        st->visitedY[i] = 0;
    }
    for (i = 0; i < 10; i++) {
        st->lastX[i] = 0;
        st->lastY[i] = 0;
    }
    st->visitedCount = 0;
    D_80109970_1E8DC0_CrazyCutters[player] = 0;
    D_80109950_1E8DA0_CrazyCutters[player] = 0;
    D_80109960_1E8DB0_CrazyCutters[player] = 0;
    st->state = 0;
    if (!(gPlayers[player].flags & 1)) {
        st->difficulty = 1;
    } else {
        switch (gPlayers[player].cpu_difficulty) {
            case 0:
                st->difficulty = 0;
                break;
            case 1:
                st->difficulty = 1;
                break;
            case 2:
                st->difficulty = 2;
                break;
            case 3:
                st->difficulty = 3;
                break;
        }
    }
    st->prevX = 0;
    st->prevZ = 0;
    st->unk450 = 0;
    q = func_8010882C_1E7C7C_CrazyCutters(player);
    D_80109908_1E8D58_CrazyCutters[q] = func_801065F4_1E5A44_CrazyCutters(q);
    st->startX = st->x;
    st->startZ = st->z;
    do {
        st->startX -= 1.0f;
        pos.x = D_80109090_1E84E0_CrazyCutters[q] + st->startX - 8.0f;
        pos.y = st->y + 10.0f;
        pos.z = D_801090A0_1E84F0_CrazyCutters[q] + st->z - 8.0f;
        func_8010585C_1E4CAC_CrazyCutters(&pos, cur, q);
    } while (D_80109938_1E8D88_CrazyCutters[q][cur[0] + cur[1] * D_80109930_1E8D80_CrazyCutters] == 0);
    st->startX -= 15.0f;
    if (D_80109918_1E8D68_CrazyCutters == 1) {
        st->startX -= 15.0f;
    }
    dir = D_801090C0_1E8510_CrazyCutters[(s8)gPlayers[player].character] << 16;
    obj->model[0] = LoadFormFile(dir | D_801090D8_1E8528_CrazyCutters[(s8)gPlayers[player].character], 0x699);
    omSetTra(obj, D_80109090_1E84E0_CrazyCutters[q] + st->x, st->y, D_801090A0_1E84F0_CrazyCutters[q] + st->z + -4.0f);
    omSetRot(obj, st->rotX, st->rotY, st->rotZ);
    func_80029714_2A314(obj->model[0], st->x, st->y, st->z);
    func_80018CCC_198CC(obj, 1, dir | motions[player]);
    func_80018CCC_198CC(obj, 0, dir | D_801090F0_1E8540_CrazyCutters[player]);
    if (rand8() & 1) {
        motion = dir | D_80109108_1E8558_CrazyCutters[player];
    } else {
        motion = dir | D_80109120_1E8570_CrazyCutters[player];
    }
    func_80018CCC_198CC(obj, 2, motion);
    D_80109A60_1E8EB0_CrazyCutters[player] = motion;
    if (rand8() & 1) {
        func_80018CCC_198CC(obj, 3, dir | D_80109138_1E8588_CrazyCutters[player]);
    } else {
        func_80018CCC_198CC(obj, 3, dir | D_80109150_1E85A0_CrazyCutters[player]);
    }
    func_80018CCC_198CC(obj, 4, dir | D_80109168_1E85B8_CrazyCutters[player]);
    func_80018CCC_198CC(obj, 5, dir | D_80109180_1E85D0_CrazyCutters[player]);
    func_80029B80_2A780(obj->model[0], obj->motion[0]);
    func_80029E80_2AA80(obj->model[0], 2, 2);

    obj->model[1] = LoadFormFile(0x33001E, 0x689);
    model = obj->model[1];
    func_80029714_2A314(model, D_80109090_1E84E0_CrazyCutters[q] + st->startX, st->y + 30.0f, D_801090A0_1E84F0_CrazyCutters[q] + st->startZ - 10.0f);
    func_8002979C_2A39C(obj->model[1], st->rotX, st->rotY, st->rotZ);
    func_800297E8_2A3E8(obj->model[1], 1.0f, 1.0f, 1.0f);
    data = DataRead(0x330002);
    st->unk468 = func_8003D8F0_3E4F0(D_800FC834_FD434[(u16)model].hmf, data, 0, "16mt000_DEF");
    func_80029A8C_2A68C(model);
    func_80029AFC_2A6FC(model);
    HuMemMemoryFreePerm(data);
    func_8003E4F4_3F0F4(st->unk468, 1, 1);

    obj->model[2] = LoadFormFile(0x33001E, 0x68D);
    model = obj->model[2];
    func_80029714_2A314(model, D_80109090_1E84E0_CrazyCutters[q] + st->startX, st->y + 20.0f, D_801090A0_1E84F0_CrazyCutters[q] + st->startZ + 10.0f);
    func_8002979C_2A39C(obj->model[2], st->rotX, st->rotY, st->rotZ);
    func_800297E8_2A3E8(obj->model[2], 1.5f, 1.0f, 1.5f);
    data = DataRead(0x330001);
    st->unk46A = func_8003D8F0_3E4F0(D_800FC834_FD434[(u16)model].hmf, data, 0, "16mt000_DEF");
    func_80029A8C_2A68C(model);
    func_80029AFC_2A6FC(model);
    HuMemMemoryFreePerm(data);
    func_8003E4F4_3F0F4(st->unk46A, 1, 1);

    st->moving = 0;
    st->target = 0;
    i = 0;
    switch (D_80109918_1E8D68_CrazyCutters) {
        case 0:
            route = D_80109198_1E85E8_CrazyCutters;
            D_80109A5A_1E8EAA_CrazyCutters = 6;
            break;
        case 1:
            route = D_80109254_1E86A4_CrazyCutters;
            D_80109A5A_1E8EAA_CrazyCutters = 6;
            break;
        case 2:
            route = D_80109318_1E8768_CrazyCutters;
            D_80109A5A_1E8EAA_CrazyCutters = 8;
            break;
    }
    /* CPU route: copy the shape's points, jittering each by up to 5 at a per-difficulty chance
       and skipping the next one at another; the marker pairs (<= 0) are copied unchanged. */
    while (*route != -1) {
        px[i] = *route++;
        py[i] = *route++;
        if (*route > 0) {
            if ((rand8() & 0x1F) < chance[st->difficulty]) {
                /* Retail quirk: the two x ranges cannot both hold, so this always jitters. */
                if ((px[i] < 89 || px[i] > 114) || (px[i] < 28 || px[i] > 55)) {
                    px[i] = px[i] - (5 - (u8)(rand8() % 11));
                    if (px[i] < 24) {
                        px[i] = 24;
                    }
                    if (px[i] > 132) {
                        px[i] = 132;
                    }
                    py[i] = py[i] - (5 - (u8)(rand8() % 11));
                    if (py[i] < 22) {
                        py[i] = 22;
                    }
                    if (py[i] > 112) {
                        py[i] = 112;
                    }
                }
            }
            if ((rand8() & 0x1F) < skip[st->difficulty]) {
                route += 2;
            }
        }
        i++;
    }
    route -= 2;
    px[i] = route[0];
    py[i] = route[0]; /* retail (and MP1): both from the x word */
    D_80109584_1E89D4_CrazyCutters = i - 1;
    if (rand8() & 1) {
        for (j = 0; j < i; j++) {
            st->pathX[j] = px[j];
            st->pathY[j] = py[j];
        }
    } else {
        for (j = 0; j < i - 2; j++) {
            st->pathX[j] = px[i - j - 3];
            st->pathY[j] = py[i - j - 3];
        }
        st->pathX[i - 2] = px[i - 2];
        st->pathY[i - 2] = py[i - 2];
        st->pathX[i - 1] = px[i - 1];
        st->pathY[i - 1] = py[i - 1];
    }
    func_80106D44_1E6194_CrazyCutters(st->player, 0x400, 1);
    st->timer = 1;
    func_80105B40_1E4F90_CrazyCutters(obj, player);
    D_80109588_1E89D8_CrazyCutters[st->player] = 0;
    D_801099D8_1E8E28_CrazyCutters[st->player] = 0;
    obj->func_ptr = func_801040F0_1E3540_CrazyCutters;
}
#else
__asm__(".section .rodata");
const u32 D_80109474_1E88C4_CrazyCutters[6] = { 0x00000023, 0x00000023, 0x00000023, 0x00000023, 0x00000023, 0x00000023 };
__asm__(".section .rodata");
const u32 D_8010948C_1E88DC_CrazyCutters[4] = { 0x00000010, 0x00000008, 0x00000004, 0x00000002 };
__asm__(".section .rodata");
const u32 D_8010949C_1E88EC_CrazyCutters[4] = { 0x00000018, 0x00000012, 0x0000000C, 0x00000006 };
__asm__(".section .rodata");
const s32 D_801094AC_1E88FC_CrazyCutters[3] = { 9, 10, 11 };
__asm__(".section .rodata");
const char D_801094B8_1E8908_CrazyCutters[] = "16mt000_DEF";
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80103508_1E2958_CrazyCutters);
#endif

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

void func_8010454C_1E399C_CrazyCutters(omObjData* obj) {
    CCPlayer* st = obj->unk_50;
    Vec pos;
    s16 cur[2];
    Vec2f screen;
    Vec2f to;
    s32 q;
    s32 sx;
    s32 hits;
    s32 lim;
    s32 total;
    s32 i;
    s32 gx;
    s32 gy;
    s8 port;
    s8 stickX;
    s8 stickY;
    f32 dist;
    f32 fx;
    f32 fy;
    f32 angle;
    f32 mag;
    f32 dx;
    f32 dz;

    q = func_8010882C_1E7C7C_CrazyCutters(st->player);
    omSetTra(obj, D_80109090_1E84E0_CrazyCutters[q] + st->x, st->y, D_801090A0_1E84F0_CrazyCutters[q] + st->z + st->unk2C + -4.0f);
    omSetRot(obj, st->rotX, st->rotY, st->rotZ);
    func_80029714_2A314(obj->model[1], D_80109090_1E84E0_CrazyCutters[q] + st->x, st->y + 30.0f, D_801090A0_1E84F0_CrazyCutters[q] + st->z + st->unk2C - 10.0f);
    func_8002979C_2A39C(obj->model[1], st->rotX, st->rotY, st->rotZ);
    func_80029714_2A314(obj->model[2], D_80109090_1E84E0_CrazyCutters[q] + st->x, st->y + 20.0f, D_801090A0_1E84F0_CrazyCutters[q] + st->z + st->unk2C - 12.0f);
    func_8002979C_2A39C(obj->model[2], st->rotX, st->rotY, st->rotZ);
    pos.x = D_80109090_1E84E0_CrazyCutters[q] + st->x - 8.0f;
    pos.y = st->y + 10.0f;
    pos.z = D_801090A0_1E84F0_CrazyCutters[q] + st->z - 8.0f;
    Hu3DCam3DToScreen(0, &pos, &screen);
    sx = screen.unk_00;
    cur[0] = sx;
    cur[1] = screen.unk_04;
    if (q & 1) {
        cur[0] = sx - 160;
    }
    if (q / 2) {
        cur[1] -= 120;
    }
    hits = func_80108A8C_1E7EDC_CrazyCutters(func_80107D74_1E71C4_CrazyCutters(D_801095B0_1E8A00_CrazyCutters[st->player]), 0, cur[0], cur[1], 3, 3, D_801090B0_1E8500_CrazyCutters);
    /* D_801099D8: frames the cutter has moved off the outline */
    if (st->moving != 0 && func_80104FF4_1E4444_CrazyCutters(st, cur, 0) == 0) {
        if (hits == 0) {
            D_801099D8_1E8E28_CrazyCutters[st->player]++;
        } else {
            D_801099D8_1E8E28_CrazyCutters[st->player] = 0;
        }
    }
    /* Off the outline, on fresh ground and moving: back near the start closes the loop (flag 1
       finished, with time short; 0x800 closed). */
    if (st->moving != 0 && hits == 0 && func_80104FF4_1E4444_CrazyCutters(st, cur, 0) == 0
        && func_80105098_1E44E8_CrazyCutters(st, cur) == 0) {
        screen.unk_00 = cur[0];
        screen.unk_04 = cur[1];
        to.unk_00 = st->startGX;
        to.unk_04 = st->startGY;
        dist = func_800B1830_B2430((to.unk_00 - screen.unk_00) * (to.unk_00 - screen.unk_00)
                                   + (to.unk_04 - screen.unk_04) * (to.unk_04 - screen.unk_04));
        lim = 5;
        if (dist < 5.0f) {
            lim = 3;
        }
        total = D_80109950_1E8DA0_CrazyCutters[st->player] + D_80109960_1E8DB0_CrazyCutters[st->player];
        if (D_8010957E_1E89CE_CrazyCutters < D_801093E4_1E8834_CrazyCutters[D_80109918_1E8D68_CrazyCutters]) {
            if (D_801099D8_1E8E28_CrazyCutters[st->player] >= lim) {
                if (dist < 30.0f) {
                    func_80106D44_1E6194_CrazyCutters(st->player, 1, 1);
                } else {
                    func_80106D44_1E6194_CrazyCutters(st->player, 0x800, 1);
                }
            }
        } else if (dist < 20.0f && total >= 11) {
            if (D_801099D8_1E8E28_CrazyCutters[st->player] >= lim) {
                func_80106D44_1E6194_CrazyCutters(st->player, 0x800, 1);
            }
        }
    }
    gx = cur[0] * 1.0f;
    gy = cur[1] * 1.0f;
    func_80106D44_1E6194_CrazyCutters(st->player, 0x40, 0);
    if (func_80106D28_1E6178_CrazyCutters(st->player, 0x8000) != 0) {
        if (func_80107BBC_1E700C_CrazyCutters(st) != 0 && func_80104FF4_1E4444_CrazyCutters(st, cur, 1) == 0) {
            D_80109950_1E8DA0_CrazyCutters[st->player]++;
            func_80106D44_1E6194_CrazyCutters(st->player, 0x40, 1);
        } else {
            D_80109960_1E8DB0_CrazyCutters[st->player]++;
        }
    }
    screen.unk_00 = cur[0];
    screen.unk_04 = cur[1];
    to.unk_00 = st->pathX[D_80109A5A_1E8EAA_CrazyCutters];
    to.unk_04 = st->pathY[D_80109A5A_1E8EAA_CrazyCutters];
    if (func_800B1830_B2430((to.unk_00 - screen.unk_00) * (to.unk_00 - screen.unk_00)
                            + (to.unk_04 - screen.unk_04) * (to.unk_04 - screen.unk_04)) < 30.0f) {
        func_80106D44_1E6194_CrazyCutters(st->player, 0x1000, 1);
    }
    if (gx >= st->pathX[D_801099FC_1E8E4C_CrazyCutters] - 3 && st->pathX[D_801099FC_1E8E4C_CrazyCutters] + 3 >= gx
        && gy >= st->pathY[D_801099FC_1E8E4C_CrazyCutters] - 3 && st->pathY[D_801099FC_1E8E4C_CrazyCutters] + 3 >= gy) {
        func_80106D44_1E6194_CrazyCutters(st->player, 0x2000, 1);
    }
    func_801050FC_1E454C_CrazyCutters(st, cur);
    /* D_80109588: bit i set once the cutter passed route point i */
    for (i = 0; i < D_80109584_1E89D4_CrazyCutters; i++) {
        if (gx >= st->pathX[i] - 1 && st->pathX[i] + 1 >= gx && gy >= st->pathY[i] - 1 && st->pathY[i] + 1 >= gy) {
            D_80109588_1E89D8_CrazyCutters[st->player] |= 1 << i;
        }
    }
    if (func_80106D28_1E6178_CrazyCutters(st->player, 1) != 0 || func_80106D28_1E6178_CrazyCutters(st->player, 0x800) != 0
        || D_8010957E_1E89CE_CrazyCutters == 0) {
        func_800283DC_28FDC(obj->model[1]);
        func_800298A4_2A4A4(obj->model[2], 4, 4);
        func_80029B80_2A780(obj->model[0], obj->motion[0]);
        func_80029E80_2AA80(obj->model[0], 2, 2);
        obj->func_ptr = func_80105254_1E46A4_CrazyCutters;
    }
    st->prevX = st->x;
    st->prevZ = st->z;
    port = gPlayers[st->player].port;
    stickX = 0;
    stickY = 0;
    if (!(gPlayers[st->player].flags & 1)) {
        if (D_80109948_1E8D98_CrazyCutters != 0) {
            stickX = ContStkX[port];
            stickY = ContStkY[port];
        }
        fx = stickX;
        fy = stickY;
        angle = func_800B75A8_B81A8(fy, fx) + 90.0f;
        if (angle < 0.0f) {
            angle += 360.0f;
        }
        mag = fabsf(fx * HuMathSin(angle));
        mag += fabsf(fy * func_800B7890_B8490(angle));
    } else if (D_80109948_1E8D98_CrazyCutters != 0) {
        angle = func_801056B8_1E4B08_CrazyCutters(st);
        mag = 40.0f;
    } else {
        angle = 0.0f;
        mag = 0.0f;
    }
    if (mag < 40.0f) {
        angle = st->angle;
    } else {
        func_80106D44_1E6194_CrazyCutters(st->player, 0x8000, 1);
        st->moving = 1;
        st->angle = angle;
    }
    if (--st->unk568 == 0) {
        omVibrate(st->player, 2, 3, 10);
        st->unk568 = 10;
    }
    dx = 0.0f;
    dz = 0.0f;
    if (st->moving != 0) {
        dx = HuMathSin(angle) * D_801099E8_1E8E38_CrazyCutters;
        dz = func_800B7890_B8490(angle) * D_801099E8_1E8E38_CrazyCutters;
    }
    st->x += dx;
    st->z += dz;
    pos.x = D_80109090_1E84E0_CrazyCutters[q] + st->x;
    pos.y = st->y;
    pos.z = D_801090A0_1E84F0_CrazyCutters[q] + st->z;
    Hu3DCam3DToScreen(0, &pos, &screen);
    if (st->x > 550.0f || st->x < 0.0f) {
        st->x -= dx;
    }
    if (st->z > 490.0f || st->z < 25.0f) {
        st->z -= dz;
    }
}

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

/* Marks the player's cut finished and records where the cutter stopped. [F98B4] */
void func_80105A74_1E4EC4_CrazyCutters(CCPlayer* st) {
    s32 q = func_8010882C_1E7C7C_CrazyCutters(st->player);

    D_80109920_1E8D70_CrazyCutters[st->player] = 1;
    D_80109A18_1E8E68_CrazyCutters[st->player] = D_80109090_1E84E0_CrazyCutters[q] + st->x;
    D_80109A28_1E8E78_CrazyCutters[st->player] = st->y;
    D_80109A38_1E8E88_CrazyCutters[st->player] = D_801090A0_1E84F0_CrazyCutters[q] + st->z + -4.0f;
    D_80109A96_1E8EE6_CrazyCutters = PlaySound(0x25E);
}

/* Drops the cut-out piece onto the player's quarter, with its shadow. [F9968] */
void func_80105B40_1E4F90_CrazyCutters(omObjData* parent, s32 player) {
    f32 xs[4] = { -400.0f, 400.0f, -400.0f, 400.0f };
    f32 zs[4] = { -250.0f, -250.0f, 350.0f, 350.0f };
    f32 sx[3] = { 4.2f, 4.5f, 4.0f };
    f32 sy[3] = { 4.2f, 4.5f, 4.0f };
    f32 sz[3] = { 4.2f, 4.5f, 4.0f };
    f32 zoff[3] = { -30.0f, 0.0f, -100.0f };
    s32 files[3] = { 0x330015, 0x330016, 0x330017 };
    omObjData* obj;
    CCPiece* st;
    s32 i;
    s32 q;

    obj = omAddObj(12, 5, 2, -1, func_80105FE4_1E5434_CrazyCutters);
    omSetStatBit(obj, 0xA0);
    obj->unk_50 = func_80027154_27D54(sizeof(CCPiece), 0x7918);
    for (i = 0; i < 4; i++) {
        obj->work[i] = 0;
    }
    q = func_8010882C_1E7C7C_CrazyCutters(player);
    st = obj->unk_50;
    st->x = xs[q];
    st->y = 0.0f;
    st->z = zs[q] + zoff[D_80109918_1E8D68_CrazyCutters];
    st->rotX = 270.0f;
    st->rotY = 0.0f;
    st->rotZ = 0.0f;
    st->scaleX = sx[D_80109918_1E8D68_CrazyCutters];
    st->scaleY = sy[D_80109918_1E8D68_CrazyCutters];
    st->scaleZ = sz[D_80109918_1E8D68_CrazyCutters];
    st->player = player;
    st->timer = 60;
    st->velY = 200.0f;
    st->state = 1;
    st->unk3C = 0;
    st->alpha = 0xFF;
    st->unk44 = 0;
    D_80109920_1E8D70_CrazyCutters[player] = 0;
    if (D_801099CC_1E8E1C_CrazyCutters != files[D_80109918_1E8D68_CrazyCutters]) {
        *obj->model = LoadFormFile(files[D_80109918_1E8D68_CrazyCutters], 0x68D);
        D_801099EC_1E8E3C_CrazyCutters = *obj->model;
        D_80109980_1E8DD0_CrazyCutters[st->player].model = LoadFormFile(0x33001D, 0x68D);
        D_801099EE_1E8E3E_CrazyCutters = (s16)D_80109980_1E8DD0_CrazyCutters[st->player].model;
        D_801099CC_1E8E1C_CrazyCutters = files[D_80109918_1E8D68_CrazyCutters];
    } else {
        *obj->model = func_80027D3C_2893C(D_801099EC_1E8E3C_CrazyCutters);
        D_80109980_1E8DD0_CrazyCutters[st->player].model = func_80027D3C_2893C(D_801099EE_1E8E3E_CrazyCutters);
    }
    func_8002D124_2DD24(*obj->model);
    omSetTra(obj, st->x, st->y, st->z);
    omSetRot(obj, st->rotX, st->rotY, st->rotZ);
    omSetSca(obj, st->scaleX, st->scaleY, st->scaleZ);
    HmfModelObjAttrSet(D_80109980_1E8DD0_CrazyCutters[st->player].model, 0x22000, 0x20000);
    func_80029A8C_2A68C(D_80109980_1E8DD0_CrazyCutters[st->player].model);
    func_8002A00C_2AC0C(D_80109980_1E8DD0_CrazyCutters[st->player].model);
    func_80029714_2A314(D_80109980_1E8DD0_CrazyCutters[st->player].model, st->x, st->y + 500.0f, st->z);
    func_8002979C_2A39C(D_80109980_1E8DD0_CrazyCutters[st->player].model, 270.0f, 0.0f, 0.0f);
    func_800297E8_2A3E8(D_80109980_1E8DD0_CrazyCutters[st->player].model, 5.0f, 5.0f, 5.0f);
    D_80109980_1E8DD0_CrazyCutters[st->player].scale = 0.1f;
    D_80109980_1E8DD0_CrazyCutters[st->player].unk8 = 2.0f;
}

/* The falling piece: fades, flies up (state 1) with its shadow growing, then falls back
   (state 2) and is removed. [F9D98] */
void func_80105FE4_1E5434_CrazyCutters(omObjData* obj) {
    Vec from;
    Vec to;
    s16 a[2];
    s16 b[2];
    s32 sprites[3] = { 0x12, 0x13, 0x14 };
    CCPiece* st = obj->unk_50;

    if (D_80109920_1E8D70_CrazyCutters[st->player] == 0) {
        return;
    }
    if (func_80078EA8_79AA8() + D_80102720_103320 != 0) {
        func_8002AC10_2B810(D_80109980_1E8DD0_CrazyCutters[st->player].model, D_80109980_1E8DD0_CrazyCutters[st->player].scale,
                            D_80109980_1E8DD0_CrazyCutters[st->player].unk8, 1);
        return;
    }
    func_8002D0A0_2DCA0(*obj->model, (u8)st->alpha);
    st->unk44 += 0.1f;
    st->alpha -= 4;
    st->unk3C++;
    if (st->alpha < 0) {
        st->alpha = 0;
    }
    switch (st->state) {
        case 1:
            if (D_80109920_1E8D70_CrazyCutters[st->player] == st->player * 2 + 2) {
                func_80107530_1E6980_CrazyCutters(sprites[D_80109918_1E8D68_CrazyCutters], st->player);
            }
            D_80109920_1E8D70_CrazyCutters[st->player]++;
            omSetTra(obj, st->x, st->y, st->z);
            omSetRot(obj, st->rotX, st->rotY, st->rotZ);
            func_800298A4_2A4A4(D_80109980_1E8DD0_CrazyCutters[st->player].model, 4, 0);
            func_800298A4_2A4A4(*obj->model, 4, 0);
            st->y += st->velY;
            st->velY += -2.0f;
            if (st->velY <= 0.0f) {
                st->state = 2;
                a[0] = D_80109A18_1E8E68_CrazyCutters[st->player];
                a[1] = D_80109A38_1E8E88_CrazyCutters[st->player];
                b[0] = st->x;
                b[1] = st->z;
                st->angle = func_80106EB0_1E6300_CrazyCutters(a, b, 1);
                from.x = D_80109A18_1E8E68_CrazyCutters[st->player];
                from.y = D_80109A28_1E8E78_CrazyCutters[st->player];
                from.z = D_80109A38_1E8E88_CrazyCutters[st->player];
                to.x = st->x;
                to.y = st->y;
                to.z = st->z;
                st->dist = func_80107204_1E6654_CrazyCutters(&from, &to, 0);
                from.y = to.y;
                st->angle = func_80107204_1E6654_CrazyCutters(&from, &to, 1);
                func_800283DC_28FDC(D_80109980_1E8DD0_CrazyCutters[st->player].model);
            }
            func_8002AC10_2B810(D_80109980_1E8DD0_CrazyCutters[st->player].model, D_80109980_1E8DD0_CrazyCutters[st->player].scale,
                                D_80109980_1E8DD0_CrazyCutters[st->player].unk8, 1);
            if (D_80109980_1E8DD0_CrazyCutters[st->player].scale < 1.0f) {
                D_80109980_1E8DD0_CrazyCutters[st->player].scale += 0.02f;
            }
            D_80109980_1E8DD0_CrazyCutters[st->player].unk8 += 0.4f;
            break;
        case 2:
            omSetTra(obj, st->x, st->y, st->z);
            st->y += st->velY;
            st->velY += -2.0f;
            if (st->y < 0.0f) {
                func_800283DC_28FDC(*obj->model);
                st->state = 0;
                func_80106D44_1E6194_CrazyCutters(st->player, 0x80, 0);
                omDelObj(obj);
            }
            break;
    }
    if (st->velY <= 0.0f) {
        st->state = 2;
        a[0] = D_80109A18_1E8E68_CrazyCutters[st->player];
        a[1] = D_80109A38_1E8E88_CrazyCutters[st->player];
        b[0] = st->x;
        b[1] = st->z;
        st->angle = func_80106EB0_1E6300_CrazyCutters(a, b, 1);
        from.x = D_80109A18_1E8E68_CrazyCutters[st->player];
        from.y = D_80109A28_1E8E78_CrazyCutters[st->player];
        from.z = D_80109A38_1E8E88_CrazyCutters[st->player];
        to.x = st->x;
        to.y = st->y;
        to.z = st->z;
        st->dist = func_80107204_1E6654_CrazyCutters(&from, &to, 0);
        from.y = to.y;
        st->angle = func_80107204_1E6654_CrazyCutters(&from, &to, 1);
    }
}

/* Loads the shape's outline sprite for a screen quarter, keeps its pixel mask in
   D_80109938[quarter] and returns the number of outline pixels. [FA38C] */
s32 func_801065F4_1E5A44_CrazyCutters(s32 quarter) {
    CCInt3 sprites = *(CCInt3*)D_801094AC_1E88FC_CrazyCutters;
    s8 sprite;
    s8 grp;
    u32 x;
    u32 y;

    sprite = func_8001A2F8_1AEF8(sprites.v[D_80109918_1E8D68_CrazyCutters] | 0x330000);
    grp = SprCreate(1, 0);
    func_80082488_83088(grp, 0, 0xFF);
    SprAttrReset(grp, 0, 0xFFFF);
    SprAttrSet(grp, 0, 0x9000);
    SprScaleSet(grp, 0, 1.0f, 1.0f);
    func_8008225C_82E5C(grp, 0, 1);
    SprAnimSet(grp, 0, sprite, 0);
    D_80109938_1E8D88_CrazyCutters[quarter] = func_80108870_1E7CC0_CrazyCutters(grp, 0, &D_80109930_1E8D80_CrazyCutters, &D_80109934_1E8D84_CrazyCutters);
    D_8010956C_1E89BC_CrazyCutters = 0;
    for (y = 0; y < D_80109934_1E8D84_CrazyCutters; y++) {
        for (x = 0; x < D_80109930_1E8D80_CrazyCutters; x++) {
            if (*(D_80109938_1E8D88_CrazyCutters[quarter] + y * D_80109930_1E8D80_CrazyCutters + x) != 0) {
                D_8010956C_1E89BC_CrazyCutters++;
            }
        }
    }
    SprKill(grp);
    return D_8010956C_1E89BC_CrazyCutters;
}

/* Time is up: the score is the share of the outline cut (hits over hits + misses, at least 500
   counted), CPUs scaled, 0..100; a player who did not finish the shape scores 0. */
// loop-invariant motion: retail keeps 0.5f in $f30 across the loop (masked 13)
#ifdef NON_MATCHING
void func_801067D4_1E5C24_CrazyCutters(omObjData* obj) {
    s32 i;
    s32 n;
    s32 total;
    f32 ratio;
    f32 rate;
    f32 lo;

    func_800691FC_69DFC(3);
    func_800794A8_7A0A8(0x2D);
    D_80109948_1E8D98_CrazyCutters = 0;
    for (i = 0; i < 4; i++) {
        n = D_80109588_1E89D8_CrazyCutters[i];
        while (n != 0) {
            n >>= 1;
        }
        total = D_80109950_1E8DA0_CrazyCutters[i] + D_80109960_1E8DB0_CrazyCutters[i];
        ratio = total / 500.0f;
        if (ratio > 1.0f) {
            ratio = 1.0f;
        }
        if (total != 0) {
            rate = D_80109950_1E8DA0_CrazyCutters[i] * ratio * 100.0f / total + 0.5f;
        } else {
            rate = 0.0f;
        }
        if (!(gPlayers[i].flags & 1)) {
            if (rate < 95.0f) {
                lo = rate;
                if (rate < 80.0f) {
                    lo = 80.0f;
                }
                rate *= (95.0f - lo) / 150.0f + 1.0f;
            }
        } else {
            rate *= 0.95f;
        }
        if (rate > 100.0f) {
            rate = 100.0f;
        }
        if (rate < 0.0f) {
            rate = 0.0f;
        }
        D_80109A52_1E8EA2_CrazyCutters[i] = rate;
        if (func_80106D28_1E6178_CrazyCutters(i, 1) == 0 || func_80106D28_1E6178_CrazyCutters(i, 0x1000) == 0) {
            D_80109A52_1E8EA2_CrazyCutters[i] = 0;
        }
    }
    obj->func_ptr = func_80106A5C_1E5EAC_CrazyCutters;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_801067D4_1E5C24_CrazyCutters);
#endif

/* Waits for the result message, then starts the end-of-game tile movement once. [FA808] */
void func_80106A5C_1E5EAC_CrazyCutters(omObjData* obj) {
    if (func_80069538_6A138() == 0 || func_80069538_6A138() & 2) {
        if (D_80109A50_1E8EA0_CrazyCutters == 0) {
            func_80107DA4_1E71F4_CrazyCutters();
            D_80109A50_1E8EA0_CrazyCutters += 1;
        }
        obj->func_ptr = func_80106AD4_1E5F24_CrazyCutters;
    }
}

/* Runs the screen shake to its end (MP1's "every player done" check is gone: the count is
   computed and dropped). [FA880] */
void func_80106AD4_1E5F24_CrazyCutters(omObjData* obj) {
    s32 i;
    s32 j;

    j = 0;
    for (i = 0; i < 4; i++) {
        j += func_80106D28_1E6178_CrazyCutters(i, 0x20);
    }
    if (D_801099F4_1E8E44_CrazyCutters > 0 && D_801099F4_1E8E44_CrazyCutters < 3) {
        if (--D_801099F8_1E8E48_CrazyCutters == 0 && D_801099F4_1E8E44_CrazyCutters == 2) {
            D_801099F4_1E8E44_CrazyCutters = 3;
        }
    }
}

/* Waits for the message to close, then fades out. [FA9D8] */
void func_80106B54_1E5FA4_CrazyCutters(omObjData* obj) {
    if (func_800696E4_6A2E4() == 0) {
        InitFadeOut(0, 20);
        obj->func_ptr = func_80106B94_1E5FE4_CrazyCutters;
    }
}

/* After the fade: ranks the players by score into gPlayers[].coins_mg_bonus (ties share a place;
   a score of 0 is last), then returns from the overlay. */
void func_80106B94_1E5FE4_CrazyCutters(omObjData* obj) {
    s32 done[4];
    s32 i;
    s32 rank;
    s32 best;
    s32 bestIdx;

    if (func_8008F618_90218() != 0) {
        return;
    }
    for (i = 0; i < 4; i++) {
        done[i] = 0;
    }
    rank = 0;
    do {
        bestIdx = 0;
        best = -1;
        for (i = 0; i < 4; i++) {
            if (done[i] == 0 && best < D_80109A52_1E8EA2_CrazyCutters[i]) {
                best = D_80109A52_1E8EA2_CrazyCutters[i];
                bestIdx = i;
            }
        }
        if (best == 0) {
            rank = 3;
        }
        gPlayers[bestIdx].coins_mg_bonus = rank;
        done[bestIdx] = 1;
        for (i = 0; i < 4; i++) {
            if (done[i] == 0 && D_80109A52_1E8EA2_CrazyCutters[i] == best) {
                gPlayers[i].coins_mg_bonus = rank;
                done[i] = 1;
            }
        }
        rank = 0;
        for (i = 0; i < 4; i++) {
            rank += done[i] == 1;
        }
    } while (rank < 4);
    func_800794A8_7A0A8(0x28);
    omOvlReturnEx(1);
    omDelObj(obj);
}

/* [FAAB0] */
s32 func_80106D28_1E6178_CrazyCutters(s32 player, s32 flag) {
    return (flag & D_80109970_1E8DC0_CrazyCutters[player]) != 0;
}

/* [FAACC] */
void func_80106D44_1E6194_CrazyCutters(s32 player, s32 flag, s32 on) {
    if (on) {
        D_80109970_1E8DC0_CrazyCutters[player] |= flag;
    } else {
        D_80109970_1E8DC0_CrazyCutters[player] &= ~flag;
    }
}

/* Arctangent in radians (continued fraction, |x| > 1 folded through 1/x). [FAB0C] */
// f32/f64 register allocation and the shared tail (masked 8; MP1 masked 4)
#ifdef NON_MATCHING
f32 func_80106D84_1E61D4_CrazyCutters(f32 x) {
    f32 a;
    f32 b;
    f32 sum;
    f64 base;
    f64 frac;
    s32 sign;
    s32 i;

    sign = 1;
    if (x > 1.0f) {
        x = 1.0f / x;
    } else {
        sign = -1;
        if (x < -1.0f) {
            x = 1.0f / x;
        } else {
            sign = 0;
        }
    }
    sum = 0.0f;
    i = 6;
    do {
        a = (f32)(i * i) * x * x;
        b = (f32)(i * 2 + 1) + sum;
        i--;
        sum = a / b;
    } while (i > 0);
    if (sign > 0) {
        base = 1.5707963267948966;
        frac = x / (sum + 1.0f);
        goto done;
    }
    if (sign >= 0) {
        return x / (sum + 1.0f);
    }
    frac = x / (sum + 1.0f);
    base = -1.5707963267948966;
done:
    return base - frac;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80106D84_1E61D4_CrazyCutters);
#endif

/* Direction (mode 0: yaw in degrees) or distance (else) from one 2D grid point to another, taken
   as (x, 0, z). [FAC38] */
// the 180.0f load is scheduled before the near-zero test, not into its delay slots (masked 21)
#ifdef NON_MATCHING
f32 func_80106EB0_1E6300_CrazyCutters(s16* from, s16* to, s32 mode) {
    Vec delta;
    Vec fromV;
    Vec toV;
    f32 horizontal;
    f32 pitch;
    f32 yaw;
    s32 nearPositive;
    s32 nearNegative;

    fromV.x = from[0];
    fromV.y = 0.0f;
    fromV.z = from[1];
    toV.x = to[0];
    toV.y = 0.0f;
    toV.z = to[1];
    delta.x = toV.x - fromV.x;
    delta.y = fromV.y;
    delta.z = toV.z - fromV.z;
    horizontal = sqrtf(delta.x * delta.x + delta.z * delta.z);
    nearPositive = horizontal <= 0.002f;
    nearNegative = horizontal >= -0.002f;
    if (nearPositive & nearNegative) {
        horizontal = 0.0f;
        yaw = horizontal;
        pitch = 180.0f;
        if (!(delta.y > 0.0001f) && delta.y < 0.0001f) {
            pitch = horizontal;
        }
    } else {
        yaw = func_80106D84_1E61D4_CrazyCutters(delta.x / delta.z) * 57.29577951308232;
        if (delta.z < 0.0f) {
            yaw -= 180.0f;
        }
        pitch = func_80106D84_1E61D4_CrazyCutters(delta.y / horizontal) * 57.29577951308232;
        yaw = yaw >= 360.0f ? yaw - 360.0f : yaw < 0.0f ? yaw + 360.0f : yaw;
        pitch = pitch + 90.0f >= 360.0f ? pitch + 90.0f - 360.0f : pitch + 90.0f < 0.0f ? pitch + 90.0f + 360.0f : pitch + 90.0f;
    }
    nearPositive = pitch <= 0.002f;
    nearNegative = pitch >= -0.002f;
    if (nearPositive & nearNegative) {
        pitch = 0.0f;
    }
    horizontal = sqrtf(delta.y * delta.y + horizontal * horizontal);
    if (mode == 0) {
        D_80109570_1E89C0_CrazyCutters = yaw;
    } else {
        D_80109570_1E89C0_CrazyCutters = horizontal;
    }
    return D_80109570_1E89C0_CrazyCutters;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80106EB0_1E6300_CrazyCutters);
#endif

/* As func_80106EB0_1E6300_CrazyCutters for two 3D points: yaw (mode 0) or distance. [FAF8C] */
// as func_80106EB0: the 180.0f load's scheduling (masked 21)
#ifdef NON_MATCHING
f32 func_80107204_1E6654_CrazyCutters(Vec* from, Vec* to, s32 mode) {
    Vec delta;
    Vec fromV;
    Vec toV;
    f32 horizontal;
    f32 pitch;
    f32 yaw;
    s32 nearPositive;
    s32 nearNegative;

    fromV.x = from->x;
    fromV.y = from->y;
    fromV.z = from->z;
    toV.x = to->x;
    toV.y = to->y;
    toV.z = to->z;
    delta.x = toV.x - fromV.x;
    delta.y = toV.y - fromV.y;
    delta.z = toV.z - fromV.z;
    horizontal = sqrtf(delta.x * delta.x + delta.z * delta.z);
    nearPositive = horizontal <= 0.002f;
    nearNegative = horizontal >= -0.002f;
    if (nearPositive & nearNegative) {
        horizontal = 0.0f;
        yaw = horizontal;
        pitch = 180.0f;
        if (!(delta.y > 0.0001f) && delta.y < 0.0001f) {
            pitch = horizontal;
        }
    } else {
        yaw = func_80106D84_1E61D4_CrazyCutters(delta.x / delta.z) * 57.29577951308232;
        if (delta.z < 0.0f) {
            yaw -= 180.0f;
        }
        pitch = func_80106D84_1E61D4_CrazyCutters(delta.y / horizontal) * 57.29577951308232;
        yaw = yaw >= 360.0f ? yaw - 360.0f : yaw < 0.0f ? yaw + 360.0f : yaw;
        pitch = pitch + 90.0f >= 360.0f ? pitch + 90.0f - 360.0f : pitch + 90.0f < 0.0f ? pitch + 90.0f + 360.0f : pitch + 90.0f;
    }
    nearPositive = pitch <= 0.002f;
    nearNegative = pitch >= -0.002f;
    if (nearPositive & nearNegative) {
        pitch = 0.0f;
    }
    horizontal = sqrtf(delta.y * delta.y + horizontal * horizontal);
    if (mode == 0) {
        D_80109574_1E89C4_CrazyCutters = yaw;
    } else {
        D_80109574_1E89C4_CrazyCutters = horizontal;
    }
    return D_80109574_1E89C4_CrazyCutters;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80107204_1E6654_CrazyCutters);
#endif

/* Cuts the piece out of the player's shape sprite: the whole mask at once for the shapes 9-11,
   else pixel by pixel. [FB2B8] */
void func_80107530_1E6980_CrazyCutters(s32 sprite, s32 player) {
    s32 x;
    s32 y;
    s32 px;

    func_801076B8_1E6B08_CrazyCutters(sprite);
    if ((sprite < 9 || sprite > 10) & (sprite != 11)) {
        func_80108A8C_1E7EDC_CrazyCutters(func_80107D74_1E71C4_CrazyCutters(D_801095B0_1E8A00_CrazyCutters[player]), 0, 0, 0,
                                          D_801099B8_1E8E08_CrazyCutters, D_801099BC_1E8E0C_CrazyCutters, D_801099B0_1E8E00_CrazyCutters);
        return;
    }
    for (y = 0; y < 120; y++) {
        for (x = 0; x < 160; x++) {
            px = (s32)(f32)x;
            if ((D_801099B0_1E8E00_CrazyCutters + (s32)(f32)y * D_801099B8_1E8E08_CrazyCutters)[px] != 0) {
                func_80108A8C_1E7EDC_CrazyCutters(func_80107D74_1E71C4_CrazyCutters(D_801095B0_1E8A00_CrazyCutters[player]), 0, x, y, 1, 1,
                                                  D_801090BC_1E850C_CrazyCutters);
            }
        }
    }
}

/* Loads sprite's pixel mask into D_801099B0 (once per sprite). [FB450] */
void func_801076B8_1E6B08_CrazyCutters(s32 sprite) {
    s8 spr;
    s8 grp;

    if (sprite != D_801099C8_1E8E18_CrazyCutters) {
        D_801099C8_1E8E18_CrazyCutters = sprite;
        spr = func_8001A2F8_1AEF8(sprite | 0x330000);
        grp = SprCreate(1, 0);
        func_80082488_83088(grp, 0, 0xFF);
        SprAttrReset(grp, 0, 0xFFFF);
        SprAttrSet(grp, 0, 0x9000);
        SprScaleSet(grp, 0, 1.0f, 1.0f);
        func_8008225C_82E5C(grp, 0, 1);
        SprAnimSet(grp, 0, spr, 0);
        D_801099B0_1E8E00_CrazyCutters = (s8*)func_80108870_1E7CC0_CrazyCutters(grp, 0, &D_801099B8_1E8E08_CrazyCutters, &D_801099BC_1E8E0C_CrazyCutters);
        SprKill(grp);
    }
}

/* As func_801076B8_1E6B08_CrazyCutters, into D_801099B4. [FB548] */
void func_801077B0_1E6C00_CrazyCutters(s32 sprite) {
    s8 spr;
    s8 grp;

    if (sprite != D_801099D0_1E8E20_CrazyCutters) {
        D_801099D0_1E8E20_CrazyCutters = sprite;
        spr = func_8001A2F8_1AEF8(sprite | 0x330000);
        grp = SprCreate(1, 0);
        func_80082488_83088(grp, 0, 0xFF);
        SprAttrReset(grp, 0, 0xFFFF);
        SprAttrSet(grp, 0, 0x9000);
        SprScaleSet(grp, 0, 1.0f, 1.0f);
        func_8008225C_82E5C(grp, 0, 1);
        SprAnimSet(grp, 0, spr, 0);
        D_801099B4_1E8E04_CrazyCutters = (s8*)func_80108870_1E7CC0_CrazyCutters(grp, 0, &D_801099C0_1E8E10_CrazyCutters, &D_801099C4_1E8E14_CrazyCutters);
        SprKill(grp);
    }
}

/* Starts the cut animation: one ring growing over sprite's mask, one shrinking over sprite2's.
   [FB640] */
// register allocation only (masked 0; MP1 the same)
#ifdef NON_MATCHING
void func_801078A8_1E6CF8_CrazyCutters(omObjData* parent, s32 sprite, s32 sprite2, s32 player) {
    omObjData* obj;
    CCRing* ring;

    func_801076B8_1E6B08_CrazyCutters(sprite);
    obj = omAddObj(13, 0, 0, -1, func_801079E0_1E6E30_CrazyCutters);
    obj->unk_50 = ring = func_80027154_27D54(sizeof(CCRing), 0x7918);
    ring->radius = 0;
    ring->step = 1.0f;
    ring->end = 80.0f;
    ring->mask = D_801099B0_1E8E00_CrazyCutters;
    ring->width = D_801099B8_1E8E08_CrazyCutters;
    ring->player = player;
    func_801077B0_1E6C00_CrazyCutters(sprite2);
    obj = omAddObj(13, 0, 0, -1, func_801079E0_1E6E30_CrazyCutters);
    obj->unk_50 = ring = func_80027154_27D54(sizeof(CCRing), 0x7918);
    ring->radius = 80.0f;
    ring->step = -1.0f;
    ring->end = 0;
    ring->mask = D_801099B4_1E8E04_CrazyCutters;
    ring->width = D_801099C0_1E8E10_CrazyCutters;
    ring->player = player;
    ring->frame = 0;
    D_80109A98_1E8EE8_CrazyCutters = -1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_801078A8_1E6CF8_CrazyCutters);
#endif

/* A cut ring: erases the shape sprite's pixels along a circle of the ring's radius where its mask
   is set (a sound on the first erased pixel), steps the radius, and ends at the end radius.
   [FB778] */
void func_801079E0_1E6E30_CrazyCutters(omObjData* obj) {
    CCRing* ring = obj->unk_50;
    f32 angle;
    f32 fx;
    f32 fy;
    s32 x;
    s32 y;

    for (angle = 0.0f; angle <= 360.0f; angle += 1.0f) {
        fx = HuMathSin(angle) * ring->radius;
        fy = func_800B7890_B8490(angle) * ring->radius;
        x = fx + 80.0f;
        y = fy + 68.0f;
        if (((u32)x < 160) & (y >= 0) && y < 120 && (ring->mask + y * ring->width)[x] != 0
            && func_80108A8C_1E7EDC_CrazyCutters(func_80107D74_1E71C4_CrazyCutters(D_801095B0_1E8A00_CrazyCutters[ring->player]), 0, x, y, 1, 1,
                                                 D_801090BC_1E850C_CrazyCutters) != 0
            && D_80109A98_1E8EE8_CrazyCutters == -1) {
            D_80109A98_1E8EE8_CrazyCutters = PlaySound(0x25D);
        }
    }
    ring->radius += ring->step;
    if (ring->radius == ring->end) {
        func_80106D44_1E6194_CrazyCutters(ring->player, 0x100, 1);
        omDelObj(obj);
    }
    ring->frame++;
}

/* With flag 0x8000: nonzero if the cutter's next step (0..D_801099E8 along its heading) crosses
   the outline. [FB944] */
s32 func_80107BBC_1E700C_CrazyCutters(CCPlayer* st) {
    Vec pos;
    s16 cur[2];
    f32 d;
    f32 fx;
    f32 fz;
    s32 q;
    s32 cx;

    if (func_80106D28_1E6178_CrazyCutters(st->player, 0x8000) == 0) {
        return 0;
    }
    D_80109578_1E89C8_CrazyCutters = 0;
    d = 0.0f;
    q = func_8010882C_1E7C7C_CrazyCutters(st->player);
    for (; d <= D_801099E8_1E8E38_CrazyCutters; d += 0.5f) {
        fx = d * HuMathSin(st->angle);
        fz = d * func_800B7890_B8490(st->angle);
        fx += st->prevX;
        fz += st->prevZ;
        pos.x = fx + D_80109090_1E84E0_CrazyCutters[q] - 8.0f;
        pos.y = st->y + 10.0f;
        pos.z = fz + D_801090A0_1E84F0_CrazyCutters[q] - 8.0f;
        func_8010585C_1E4CAC_CrazyCutters(&pos, cur, q);
        cx = cur[0];
        if ((D_80109938_1E8D88_CrazyCutters[q] + cur[1] * D_80109930_1E8D80_CrazyCutters)[cx] != 0) {
            D_80109578_1E89C8_CrazyCutters = 1;
            break;
        }
    }
    return D_80109578_1E89C8_CrazyCutters;
}

/* [FBAFC] */
// retail computes the index before loading D_800F93FC (masked 6; MP1 the same)
#ifdef NON_MATCHING
s16 func_80107D74_1E71C4_CrazyCutters(s32 idx) {
    return D_8010957C_1E89CC_CrazyCutters = D_800F93FC_F9FFC[idx].unk_04;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_23_CrazyCutters/1E1C50", func_80107D74_1E71C4_CrazyCutters);
#endif

/* Starts the score roulette. [FBB2C] */
void func_80107DA4_1E71F4_CrazyCutters(void) {
    omObjData* obj;
    s32* counter;

    obj = omAddObj(12, 0, 0, -1, func_80107DFC_1E724C_CrazyCutters);
    counter = func_80027154_27D54(sizeof(s32), 0x7918);
    obj->unk_50 = counter;
    *counter = 90;
}

/* The score roulette: random scores until frame 60, then the real ones; at the end the best
   score(s) win (flags 8, 0x80, 0x10000), the rest lose (0x4000 cleared). [FBB94] */
void func_80107DFC_1E724C_CrazyCutters(omObjData* obj) {
    s32* counter = obj->unk_50;
    s32 i;
    s16 r;
    s16 best;

    if (--*counter == 88) {
        D_80109A94_1E8EE4_CrazyCutters = PlaySound(0x260);
    }
    if (*counter == 60) {
        func_80079848_7A448(D_80109A94_1E8EE4_CrazyCutters);
        PlaySound(0x261);
    }
    if (*counter > 60) {
        r = (rand8() * 101) >> 8;
        for (i = 0; i < 4; i++) {
            func_801084FC_1E794C_CrazyCutters(D_80109A48_1E8E98_CrazyCutters[i], r);
        }
    } else if (*counter < 10) {
        for (i = 0; i < 4; i++) {
            func_801086BC_1E7B0C_CrazyCutters(D_80109A48_1E8E98_CrazyCutters[i], (s16)*counter);
        }
    } else if (*counter > 0) {
        for (i = 0; i < 4; i++) {
            func_801084FC_1E794C_CrazyCutters(D_80109A48_1E8E98_CrazyCutters[i], D_80109A52_1E8EA2_CrazyCutters[i]);
        }
    }
    if (*counter == 0) {
        D_801099F0_1E8E40_CrazyCutters = 0;
        best = 1;
        for (i = 0; i < 4; i++) {
            if (D_80109A52_1E8EA2_CrazyCutters[i] >= best) {
                best = D_80109A52_1E8EA2_CrazyCutters[i];
            }
        }
        for (i = 0; i < 4; i++) {
            if (D_80109A52_1E8EA2_CrazyCutters[i] == best) {
                func_80106D44_1E6194_CrazyCutters(i, 8, 1);
                func_80106D44_1E6194_CrazyCutters(i, 0x80, 1);
                func_80106D44_1E6194_CrazyCutters(i, 0x10000, 1);
                D_801099F0_1E8E40_CrazyCutters++;
            } else {
                func_80106D44_1E6194_CrazyCutters(i, 0x4000, 0);
            }
        }
        if (D_801099F0_1E8E40_CrazyCutters == 0) {
            omAddObj(12, 0, 0, -1, func_8010332C_1E277C_CrazyCutters);
        } else if (D_801099F4_1E8E44_CrazyCutters <= 0) {
            D_801099F4_1E8E44_CrazyCutters = 1;
            D_801099F8_1E8E48_CrazyCutters = 30;
            D_80109A90_1E8EE0_CrazyCutters = PlaySound(0x25C);
            for (i = 0; i < 4; i++) {
                ((CCPlayer*)D_80109A70_1E8EC0_CrazyCutters[i]->unk_50)->unk568 = 1;
            }
        }
        omDelObj(obj);
    }
}

/* Nonzero if the 3x3 squares 3 pixels left, right, above and below (x, y) are all still set:
   (x, y) lies inside the remaining shape. [FBEA8] */
s32 func_80108108_1E7558_CrazyCutters(s16 grpIdx, s32 idx, s32 x, s32 y) {
    s32 a;
    s32 b;
    s32 c;

    a = func_80108E2C_1E827C_CrazyCutters(grpIdx, 0, x + 3, y, 3, 3, D_801090B0_1E8500_CrazyCutters);
    b = func_80108E2C_1E827C_CrazyCutters(grpIdx, 0, x - 3, y, 3, 3, D_801090B0_1E8500_CrazyCutters);
    c = func_80108E2C_1E827C_CrazyCutters(grpIdx, 0, x, y + 3, 3, 3, D_801090B0_1E8500_CrazyCutters);
    return a + b + c + func_80108E2C_1E827C_CrazyCutters(grpIdx, 0, x, y - 3, 3, 3, D_801090B0_1E8500_CrazyCutters) >= 18;
}

/* Loads the score digit and percent sign animations. [FBFB4] */
void func_80108214_1E7664_CrazyCutters(void) {
    void* data;

    data = DataRead(0x3A);
    D_80109A80_1E8ED0_CrazyCutters = SprAnimRead(data);
    DataClose(data);
    data = DataRead(0x10017);
    D_80109A8C_1E8EDC_CrazyCutters = SprAnimRead(data);
    DataClose(data);
    D_80109A8A_1E8EDA_CrazyCutters = 0;
}

/* A score display at (x, y): three digits and a percent sign, hidden. [FC024] */
s16 func_80108284_1E76D4_CrazyCutters(s16 x, s16 y) {
    s16 grp;
    s16 i;
    s16 px;

    grp = D_80109A82_1E8ED2_CrazyCutters[D_80109A8A_1E8EDA_CrazyCutters] = SprCreate(4, 5);
    SprAnimSet(grp, 0, D_80109A80_1E8ED0_CrazyCutters, 0);
    SprAttrReset(grp, 0, 0xFFFF);
    SprAttrSet(grp, 0, 0x8000);
    SprPosSet(grp, 0, x - 16, y);
    px = 24;
    for (i = 1; i < 3; i++) {
        SprAnimSet(grp, i, D_80109A80_1E8ED0_CrazyCutters, 0);
        SprPosSet(grp, i, px, 0);
        SprAttrReset(grp, i, 0xFFFF);
        SprAttrSet(grp, i, 0x8000);
        px += 24;
    }
    SprAnimSet(grp, i, D_80109A8C_1E8EDC_CrazyCutters, 0);
    SprPosSet(grp, i, px - 4, 6);
    SprAttrReset(grp, i, 0xFFFF);
    SprAttrSet(grp, i, 0x8000);
    func_800824F4_830F4(grp, 1, 0);
    func_800824F4_830F4(grp, 2, 0);
    func_800824F4_830F4(grp, 3, 0);
    SprAttrReset(grp, 2, 0x8000);
    SprAttrReset(grp, 3, 0x8000);
    D_80109A8A_1E8EDA_CrazyCutters++;
    return grp;
}

/* Hides a score display. [FC240] */
void func_801084A0_1E78F0_CrazyCutters(s16 grp) {
    s16 i;

    for (i = 0; i < 4; i++) {
        SprAttrSet(grp, i, 0x8000);
    }
}

/* Shows value (0-100) on a score display, without leading zeros. [FC29C] */
void func_801084FC_1E794C_CrazyCutters(s16 grp, s16 value) {
    s16 hundreds;
    s16 tens;

    hundreds = 0;
    if (value >= 100) {
        SprAttrReset(grp, 0, 0x8000);
        func_800822A8_82EA8(grp, 0, 1, 0);
        func_8008225C_82E5C(grp, 0, 1);
        value -= 100;
        hundreds = 1;
    } else {
        SprAttrSet(grp, 0, 0x8000);
    }
    if (hundreds != 0 || (s16)(value / 10) != 0) {
        SprAttrReset(grp, 1, 0x8000);
        tens = value / 10;
        func_800822A8_82EA8(grp, 1, tens, 0);
        func_8008225C_82E5C(grp, 1, 1);
        value -= tens * 10;
    } else {
        SprAttrSet(grp, 1, 0x8000);
    }
    SprAttrReset(grp, 2, 0x8000);
    func_800822A8_82EA8(grp, 2, value, 0);
    func_8008225C_82E5C(grp, 2, 1);
    SprAttrReset(grp, 3, 0x8000);
}

/* Scales a score display by scale / 10. [FC45C] */
void func_801086BC_1E7B0C_CrazyCutters(s16 grp, s16 scale) {
    s16 i = 0;

    for (i = 0; i < 4; i++) {
        SprScaleSet(grp, i, scale / 10.0f, scale / 10.0f);
    }
}

/* Orders the screen quarters by team (gPlayers[].coins_mg_bonus holds the team here), then
   player: D_80109A08[quarter] = player. */
void func_8010874C_1E7B9C_CrazyCutters(void) {
    s32 key[4];
    s32 i;
    s32 j;
    s32 t;

    for (i = 0; i < 4; i++) {
        key[i] = gPlayers[i].coins_mg_bonus * 4 + i;
        D_80109A08_1E8E58_CrazyCutters[i] = i;
    }
    for (i = 0; i < 3; i++) {
        for (j = i; j < 4; j++) {
            if (key[i] > key[j]) {
                t = key[j];
                key[j] = key[i];
                key[i] = t;
                t = D_80109A08_1E8E58_CrazyCutters[j];
                D_80109A08_1E8E58_CrazyCutters[j] = D_80109A08_1E8E58_CrazyCutters[i];
                D_80109A08_1E8E58_CrazyCutters[i] = t;
            }
        }
    }
}

/* The screen quarter of a player. */
s32 func_8010882C_1E7C7C_CrazyCutters(s32 player) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (player == D_80109A08_1E8E58_CrazyCutters[i]) {
            break;
        }
    }
    return i;
}
