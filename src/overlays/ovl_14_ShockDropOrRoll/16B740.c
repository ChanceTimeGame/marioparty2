#include "common.h"
#include "ovl_14.h"

/* .data (0x16FE10-0x16FEA0, 80106ED0-80106F60). */
s8 D_80106ED0_16FE10_ShockDropOrRoll = 0;
s8 D_80106ED1_16FE11_ShockDropOrRoll = 0;
s8 D_80106ED2_16FE12_ShockDropOrRoll = 0;
s8 D_80106ED3_16FE13_ShockDropOrRoll = 0;
s8 D_80106ED4_16FE14_ShockDropOrRoll = 1; /* no C user */
s8 D_80106ED5_16FE15_ShockDropOrRoll = -1;
s8 D_80106ED6_16FE16_ShockDropOrRoll = 0; /* no C user */
u8 D_80106ED7_16FE17_ShockDropOrRoll = 0;
s8 D_80106ED8_16FE18_ShockDropOrRoll = 0;
s8 D_80106ED9_16FE19_ShockDropOrRoll = 0;
s8 D_80106EDA_16FE1A_ShockDropOrRoll = 0;
f32 D_80106EDC_16FE1C_ShockDropOrRoll[8] = { 30.0f, 30.0f, 30.0f, 30.0f, 30.0f, 30.0f, 30.0f, 30.0f };
u32 D_80106EFC_16FE3C_ShockDropOrRoll = 0;
u32 D_80106F00_16FE40_ShockDropOrRoll = 0;
u32 D_80106F04_16FE44_ShockDropOrRoll = 0;
s8 D_80106F08_16FE48_ShockDropOrRoll = 0;
s8 D_80106F09_16FE49_ShockDropOrRoll = 0;
f32 D_80106F0C_16FE4C_ShockDropOrRoll = 30.0f;
s8 D_80106F10_16FE50_ShockDropOrRoll = 0;
u32 D_80106F14_16FE54_ShockDropOrRoll = 929;
f32 D_80106F18_16FE58_ShockDropOrRoll[16] = { 0.0f };
s8 D_80106F58_16FE98_ShockDropOrRoll = 0;
s16 D_80106F5A_16FE9A_ShockDropOrRoll = 0;

__asm__(".section .rodata");
const char D_80106F90_16FED0_ShockDropOrRoll[] = "\202r\202s\202`\202q\202s";

/* The entry: picks the solo player (the one in group 0) and the order of the others, shuffles
   the CPU level rows, sets up the scene and adds the objects. */
void func_80102800_16B740_ShockDropOrRoll(void) {
    s16 i;
    s16 k;
    s8 a;
    s8 b;
    s8 tmp;

    for (i = 0; i < 4; i++) {
        if (gPlayers[i].group == 0) {
            break;
        }
    }
    switch (i) {
    case 1:
        D_801072B8_1701F8_ShockDropOrRoll[0] = 1;
        break;
    case 2:
        D_801072B8_1701F8_ShockDropOrRoll[0] = 2;
        break;
    case 3:
        D_801072B8_1701F8_ShockDropOrRoll[0] = 3;
        break;
    case 0:
    default:
        D_801072B8_1701F8_ShockDropOrRoll[0] = 0;
        break;
    }
    for (i = 1, k = 0; i < 4; i++, k++) {
        if (D_801072B8_1701F8_ShockDropOrRoll[0] == k) {
            k++;
        }
        D_801072B8_1701F8_ShockDropOrRoll[i] = k;
    }
    for (i = 0; i < 10; i++) {
        a = guRandom() % 3 + 1;
        b = guRandom() % 3 + 1;
        tmp = D_801072B8_1701F8_ShockDropOrRoll[a];
        D_801072B8_1701F8_ShockDropOrRoll[a] = D_801072B8_1701F8_ShockDropOrRoll[b];
        D_801072B8_1701F8_ShockDropOrRoll[b] = tmp;
    }
    func_8002D4D0_2E0D0(0xA);
    func_8002F290_2FE90(D_800F9D30_FA930, 0x40);
    func_80020D20_21920(0x40);
    omInitObjMan(0x1E, 0);
    func_80079128_79D28();
    func_8000C460_D060();
    func_8000C578_D178(1);
    func_80020070_20C70(1);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_80079E60_7AA60), 0xA0);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 30.0f, 80.0f, 8000.0f);
    func_8002C59C_2D19C(0x800, 0x990, 0x40, 0x40, 0x40);
    func_80105E90_16EDD0_ShockDropOrRoll(1000.0f, 329.0f, -50.0f, 0.0f, -777.0f, 570.0f, 847.0f);
    func_80026DAC_279AC(1, 0x60, 0x40, 0x40);
    func_80026E00_27A00(1, 0.0f, 93.0f, 74.0f);
    func_8000C38C_CF8C();
    func_8000C3C8_CFC8();
    func_8007273C_7333C((u8*)D_80106F90_16FED0_ShockDropOrRoll, 1);
    D_800FA606_FB206 = 0;
    D_800FC87A_FD47A = 0;
    for (i = 0; i < 5; i++) {
        D_801072BC_1701FC_ShockDropOrRoll[i] = i;
    }
    for (i = 0; i < 10; i++) {
        a = guRandom() % 5;
        b = guRandom() % 5;
        tmp = D_801072BC_1701FC_ShockDropOrRoll[a];
        D_801072BC_1701FC_ShockDropOrRoll[a] = D_801072BC_1701FC_ShockDropOrRoll[b];
        D_801072BC_1701FC_ShockDropOrRoll[b] = tmp;
    }
    D_801072B4_1701F4_ShockDropOrRoll = omAddObj(2, 0xC, 0x2D, -1, func_80102EC8_16BE08_ShockDropOrRoll);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(5, 0xC, 0x2D, -1, func_80102F54_16BE94_ShockDropOrRoll);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(5, 0xC, 0x2D, -1, func_80102FE4_16BF24_ShockDropOrRoll);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(5, 0xC, 0x2D, -1, func_8010306C_16BFAC_ShockDropOrRoll);
    D_800F8FE0_F9BE0 = 0;
    func_8000C018_CC18(0);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(3, 6, 0, -1, func_80106394_16F2D4_ShockDropOrRoll);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(3, 6, 0, -1, func_801064B0_16F3F0_ShockDropOrRoll);
    D_801072C8_170208_ShockDropOrRoll = omAddObj(3, 0x16, 0, -1, func_80106790_16F6D0_ShockDropOrRoll);
    omAddObj(0, 0, 0, -1, func_80105ED0_16EE10_ShockDropOrRoll);
    omAddObj(0x14, 0, 0, -1, func_80104E24_16DD64_ShockDropOrRoll);
    omAddObj(0x32, 0, 0, -1, func_80105920_16E860_ShockDropOrRoll);
    InitFadeIn(0, 0x10);
}

/* The solo player's object. */
void func_80102EC8_16BE08_ShockDropOrRoll(omObjData* obj) {
    u8 chr = gPlayers[D_801072B8_1701F8_ShockDropOrRoll[0]].character;
    s32 dir = D_800CD438_CE038[chr].unk_04;
    s32 file = D_800CD438_CE038[chr].unk_08;

    func_80104B98_16DAD8_ShockDropOrRoll(obj, dir, file, D_801072B8_1701F8_ShockDropOrRoll[0], 0.0f, 200.0f, 600.0f);
}

/* Roller player 1's object. */
void func_80102F54_16BE94_ShockDropOrRoll(omObjData* obj) {
    u8 chr = gPlayers[D_801072B8_1701F8_ShockDropOrRoll[1]].character;
    s32 dir = D_800CD438_CE038[chr].unk_04;
    s32 file = D_800CD438_CE038[chr].unk_08;

    func_80103FE8_16CF28_ShockDropOrRoll(obj, dir, file, D_801072B8_1701F8_ShockDropOrRoll[1], -200.0f,
                                         450.0f, 0.0f, 0);
}

/* Roller player 2's object. */
void func_80102FE4_16BF24_ShockDropOrRoll(omObjData* obj) {
    u8 chr = gPlayers[D_801072B8_1701F8_ShockDropOrRoll[2]].character;
    s32 dir = D_800CD438_CE038[chr].unk_04;
    s32 file = D_800CD438_CE038[chr].unk_08;

    func_80103FE8_16CF28_ShockDropOrRoll(obj, dir, file, D_801072B8_1701F8_ShockDropOrRoll[2], 0.0f,
                                         450.0f, 0.0f, 1);
}

/* Roller player 3's object. */
void func_8010306C_16BFAC_ShockDropOrRoll(omObjData* obj) {
    u8 chr = gPlayers[D_801072B8_1701F8_ShockDropOrRoll[3]].character;
    s32 dir = D_800CD438_CE038[chr].unk_04;
    s32 file = D_800CD438_CE038[chr].unk_08;

    func_80103FE8_16CF28_ShockDropOrRoll(obj, dir, file, D_801072B8_1701F8_ShockDropOrRoll[3], 200.0f,
                                         450.0f, 0.0f, 2);
}

/* A roller player's update (after func_801038C4's CPU input): the stick X runs it along the
   roller (stick Y), the roller carries it, the intro runs it on its own; a player whose y reaches
   0 has fallen: it drops through, bounces on the floor and leaves under a spinning marker. At the
   end the survivors cheer or sulk and face the camera. */
void func_80103100_16C040_ShockDropOrRoll(omObjData* obj) {
    MgWork* w = obj->unk_50;
    SDPlayer* p = w->unk_158;

    if (D_80106ED7_16FE17_ShockDropOrRoll >= 5 && D_80106ED7_16FE17_ShockDropOrRoll < 9) {
        ContStkY[w->unk_57] = -ContStkX[w->unk_57];
    } else {
        ContStkY[w->unk_57] = 0;
        ContBtn[w->unk_57] = 0;
    }
    ContStkX[w->unk_57] = 0;
    if (p->fell == 0 && obj->trans.y <= 0.0f) {
        p->fell = 1;
    }
    if (p->fell == 1) {
        ContStkY[w->unk_57] = 0;
        ContBtnTrg[w->unk_57] = 0;
        ContBtn[w->unk_57] = 0;
    }
    if (D_80106ED0_16FE10_ShockDropOrRoll == 0 && w->unk_38 == 1000.0f && p->fell == 0) {
        obj->trans.z += D_801072C4_170204_ShockDropOrRoll;
    }
    p->pos[0] = obj->trans.x;
    p->pos[1] = obj->trans.y;
    p->pos[2] = obj->trans.z;
    if (D_80106ED1_16FE11_ShockDropOrRoll == 1 && D_80106ED3_16FE13_ShockDropOrRoll == 0) {
        ContBtn[w->unk_57] = 0xFFFF;
        ContBtnTrg[w->unk_57] = 0;
        if ((obj->trans.z > 0.0f ? obj->trans.z : -obj->trans.z) >= 100.0f) {
            if (obj->trans.z < 0.0f) {
                ContStkY[w->unk_57] = -60;
            } else {
                ContStkY[w->unk_57] = 60;
            }
        } else if (obj->trans.z < 0.0f) {
            ContStkY[w->unk_57] = -45;
        } else {
            ContStkY[w->unk_57] = 45;
        }
        if ((obj->trans.z > 0.0f ? obj->trans.z : -obj->trans.z) >= 175.0f) {
            if (p->jumpWait >= 30) {
                ContBtn[w->unk_57] = 0x7FFF;
                ContBtnTrg[w->unk_57] = 0x8000;
                p->jumpWait = 0;
            }
        }
        p->jumpWait++;
    }
    if (p->dropped == 0) {
        func_80007790_8390(obj);
    } else {
        func_800298A4_2A4A4(obj->model[1], 4, 4);
    }
    if (p->fell == 1 && (D_80106ED5_16FE15_ShockDropOrRoll != 0 || p->dropped == 1)) {
        if (p->dropped == 0) {
            func_8000C024_CC24(obj, 0, 1);
            func_8000C024_CC24(obj, 1, 1);
            if (p->voiced == 0) {
                func_800797DC_7A3DC(0x111, w->unk_59);
                p->voiced = 1;
            }
            func_80029B80_2A780(obj->model[0], obj->motion[0x26]);
            func_800B2060_B2C60(D_800FC834_FD434[obj->model[0]].mtx, 0.0f, 0.0f, 0.0f);
            obj->rot.y = -90.0f;
            p->dropped = 1;
        } else if (obj->trans.x > -1000.0f) {
            if (obj->trans.y < -250.0f) {
                obj->trans.y = -250.0f;
                p->fallVel = 50.0f;
                func_80079798_7A398(0x1C9, w->unk_59);
                omVibrate(w->unk_59, 20, 0, 20);
            }
            obj->trans.y += p->fallVel;
            p->fallVel -= 3.5f;
            obj->trans.x -= 20.0f;
        } else {
            obj->trans.x = -2300.0f;
            obj->trans.y = 500.0f;
            func_800298A4_2A4A4(obj->model[0], 4, 4);
        }
        if (obj->trans.z < 0.0f) {
            if (obj->trans.z > -325.0f) {
                obj->trans.z -= 10.0f;
                if (obj->trans.z < -325.0f) {
                    obj->trans.z = -325.0f;
                }
            }
        } else if (obj->trans.z < 325.0f) {
            obj->trans.z += 10.0f;
            if (obj->trans.z > 325.0f) {
                obj->trans.z = 325.0f;
            }
        }
        func_800298A4_2A4A4(p->mark, 4, 0);
        func_80029714_2A314(p->mark, obj->trans.x, obj->trans.y + 75.0f, obj->trans.z);
        func_8002979C_2A39C(p->mark, p->rot[0], p->rot[1], p->rot[2]);
        p->rot[0] += 23.0f;
        p->rot[1] += 33.0f;
    }
    if (D_80106ED0_16FE10_ShockDropOrRoll == 1 && p->dropped == 0) {
        if (w->unk_38 == 1000.0f && D_80106EDA_16FE1A_ShockDropOrRoll == 1 && p->cheered == 0) {
            if (_CheckFlag(0xC) == 0) {
                if (D_80106ED5_16FE15_ShockDropOrRoll == 0) {
                    func_80019B9C_1A79C(obj, 0xD);
                    func_800732B0_73EB0(D_800CD438_CE038[gPlayers[w->unk_59].character].unk_04 | 0x4F);
                } else {
                    func_80019B9C_1A79C(obj, 0xE);
                    func_800732B0_73EB0(D_800CD438_CE038[gPlayers[w->unk_59].character].unk_04 | 0x56);
                }
            }
            p->cheered = 1;
        }
        w->unk_3C = -func_800B75A8_B81A8(obj->trans.x - D_8010274C_10334C.x, -(obj->trans.z - D_8010274C_10334C.z));
    }
}

/* A roller player's CPU input: runs against the roller (aiming at a random offset scaled by the
   roller speed), dashes when the roller speeds up, jumps near the edges; the input goes through
   a delay ring (2-8 frames by difficulty). Then func_80103100. */
void func_801038C4_16C804_ShockDropOrRoll(omObjData* obj) {
    MgWork* w = obj->unk_50;
    SDPlayer* p = w->unk_158;
    u8 lv = p->level;
    s32 delay = 0;
    s16 stk;
    s16 btn;
    u16 trg;
    s16 i;
    f32 aim;
    f32 jumpZ;

    if (D_80106ED3_16FE13_ShockDropOrRoll == 1 && D_80106ED0_16FE10_ShockDropOrRoll == 0) {
        btn = 0;
        if (gPlayers[w->unk_59].flags & 1) {
            stk = 0;
            ContStkY[w->unk_57] = 0;
            trg = 0;
            if (p->aimWait++ >= 11) {
                p->aim = guRandom() % D_80106FD8_16FF18_ShockDropOrRoll[gPlayers[w->unk_59].cpu_difficulty];
                p->aim -= D_80106FD8_16FF18_ShockDropOrRoll[gPlayers[w->unk_59].cpu_difficulty];
                p->aimWait = 0;
            }
            aim = p->aim;
            aim *= D_801072C4_170204_ShockDropOrRoll / 89.0f;
            if ((obj->trans.z > 0.0f ? obj->trans.z : -obj->trans.z) >= 30.0f) {
                if ((obj->trans.z > 0.0f ? aim + obj->trans.z : -obj->trans.z + aim) >= D_80106F9C_16FEDC_ShockDropOrRoll[lv].aimNear) {
                    if (aim + obj->trans.z < 0.0f) {
                        stk = (s8)D_80106F9C_16FEDC_ShockDropOrRoll[lv].stkFar;
                    } else {
                        stk = -(s8)D_80106F9C_16FEDC_ShockDropOrRoll[lv].stkFar;
                    }
                } else if (aim + obj->trans.z < 0.0f) {
                    stk = (s8)D_80106F9C_16FEDC_ShockDropOrRoll[lv].stkNear;
                } else {
                    stk = -(s8)D_80106F9C_16FEDC_ShockDropOrRoll[lv].stkNear;
                }
                if (p->dash == 0 && guRandom() % 100 < D_80106FE8_16FF28_ShockDropOrRoll[gPlayers[w->unk_59].cpu_difficulty]) {
                    if (p->spin < 0.0f && p->spin < D_80106F70_16FEB0_ShockDropOrRoll) {
                        p->dash = 1;
                    }
                    if (p->spin > 0.0f && D_80106F70_16FEB0_ShockDropOrRoll < p->spin) {
                        p->dash = 1;
                    }
                }
            }
            if (p->dash == 1) {
                if (p->aimWait++ < 10) {
                    if (obj->trans.z < 0.0f) {
                        stk = -(s8)D_80106F9C_16FEDC_ShockDropOrRoll[lv].stkFar;
                    } else {
                        stk = (s8)D_80106F9C_16FEDC_ShockDropOrRoll[lv].stkFar;
                    }
                } else {
                    p->aimWait = 0;
                    p->dash = 0;
                }
            }
            jumpZ = D_80106F9C_16FEDC_ShockDropOrRoll[lv].jumpZ;
            if (jumpZ <= (obj->trans.z > 0.0f ? obj->trans.z : -obj->trans.z)) {
                if (p->jumpWait >= D_80106F9C_16FEDC_ShockDropOrRoll[lv].jumpWait) {
                    btn = 0x7FFF;
                    trg = 0x8000;
                    p->jumpWait = 0;
                }
            }
            p->jumpWait++;
            if (p->spinWait++ >= 11) {
                p->spin = D_80106F70_16FEB0_ShockDropOrRoll;
                p->spinWait = 0;
            }
            p->stk[p->hist] = stk;
            p->btn[p->hist] = btn;
            p->trg[p->hist] = trg;
            switch (gPlayers[w->unk_59].cpu_difficulty) {
            case 0:
                delay = 8;
                break;
            case 1:
                delay = 5;
                break;
            case 2:
                delay = 3;
                break;
            case 3:
                delay = 2;
                break;
            }
            i = p->hist - delay;
            if (i < 0) {
                i += 32;
            }
            ContStkX[w->unk_57] = p->stk[i];
            ContBtn[w->unk_57] = p->btn[i];
            ContBtnTrg[w->unk_57] = p->trg[i];
            p->hist++;
            if (p->hist >= 32) {
                p->hist = 0;
            }
        }
    }
    func_80103100_16C040_ShockDropOrRoll(obj);
}

__asm__(".section .rodata");
const SDLevel D_80106F9C_16FEDC_ShockDropOrRoll[5] = {
    { 100.0f, 175.0f, 30, 50, 35 },
    { 120.0f, 125.0f, 30, 50, 30 },
    { 100.0f, 325.0f, 30, 50, 35 },
    { 150.0f, 175.0f, 30, 50, 35 },
    { 100.0f, 50.0f, 30, 60, 40 },
};
const s32 D_80106FD8_16FF18_ShockDropOrRoll[4] = { 100, 50, 25, 10 }; /* aim range by difficulty */
const s16 D_80106FE8_16FF28_ShockDropOrRoll[4] = { 10, 8, 6, 4 };     /* dash chance (%) by difficulty */

/* A roller player's setup: its SDPlayer, marker, sounds, models and motions. */
void func_80103FE8_16CF28_ShockDropOrRoll(omObjData* obj, s32 dir, s32 file, u16 player, f32 x, f32 y, f32 z, u16 slot) {
    MgWork* w;
    SDPlayer* p;
    s8 i;

    func_8000C6FC_D2FC(obj, dir, file, player, 0xAB9, 0xAB9);
    w = obj->unk_50;
    w->unk_158 = func_80027154_27D54(sizeof(SDPlayer), 0x7918);
    func_800B0EF0_B1AF0(w->unk_158, 0, sizeof(SDPlayer));
    p = w->unk_158;
    p->fell = 0;
    p->dropped = 0;
    p->cheered = 0;
    p->mark = D_801072C8_170208_ShockDropOrRoll->model[slot + 0x11];
    p->fallVel = -50.0f;
    p->jumpWait = 30;
    p->level = D_801072BC_1701FC_ShockDropOrRoll[slot];
    p->aimWait = 0;
    p->aim = 0.0f;
    p->spinWait = 0;
    p->spin = 0.0f;
    p->dash = 0;
    p->voiced = 0;
    for (i = 0; i < 3; i++) {
        p->pos[i] = 0.0f;
        p->rot[i] = 0.0f;
    }
    p->hist = 0;
    for (i = 0; i < 32; i++) {
        p->stk[i] = 0;
        p->btn[i] = 0;
        p->trg[i] = 0;
    }
    w->unk_3C = 0.0f;
    D_800BF7E4_C03E4[w->unk_59][4] = 0x2D2;
    D_800BF7E4_C03E4[w->unk_59][9] = 0x2D2;
    D_800BF7E4_C03E4[w->unk_59][7] = 0x2D2;
    obj->model[3] = LoadFormFile(7, 0x88D);
    obj->model[4] = LoadFormFile(8, 0x88D);
    obj->model[6] = LoadFormFile(9, 0x88D);
    obj->model[5] = LoadFormFile(0xA, 0x88D);
    obj->model[7] = LoadFormFile(0xC, 0x88D);
    obj->model[8] = LoadFormFile(0xB, 0x88D);
    func_8001A12C_1AD2C(obj, 0, dir, 1, 0, 0);
    func_8001A12C_1AD2C(obj, 1, dir | 1, 1, 0, 2);
    func_8001A12C_1AD2C(obj, 2, dir | 2, 1, 0, 3);
    func_80019F0C_1AB0C(obj, 6, dir | 4, 1, 0x13);
    func_80019F0C_1AB0C(obj, 9, dir | 7, 1, 0x27);
    func_80019F0C_1AB0C(obj, 0x10, dir | 0xE, 1, 0);
    func_80019F0C_1AB0C(obj, 0x11, dir | 0xF, 1, 0xF);
    func_80019F0C_1AB0C(obj, 0x12, dir | 0x10, 2, 0);
    func_80019F0C_1AB0C(obj, 0x13, dir | 0x11, 2, 0);
    func_80019F0C_1AB0C(obj, 0xA, dir | 0x12, 1, 0x27);
    func_80019E84_1AA84(obj, 0x15, dir | 0x2E, 0, 0);
    func_80019E84_1AA84(obj, 3, dir | 0x2C, 1, 0);
    func_80019E84_1AA84(obj, 4, dir | 0x2D, 1, 0);
    func_80019E84_1AA84(obj, 0x1E, dir | 0x2F, 2, 0);
    func_80019E84_1AA84(obj, 0x1F, dir | 0x30, 2, 0);
    func_80019E84_1AA84(obj, 0x20, dir | 0x31, 0, 0);
    func_80019E84_1AA84(obj, 0x21, dir | 0x32, 2, 0);
    func_80019E84_1AA84(obj, 0x22, dir | 0x33, 2, 0);
    func_80019E84_1AA84(obj, 0x26, dir | 0x1C, 1, 0);
    func_80019E84_1AA84(obj, 0xD, dir | 0x4F, 1, 0x78);
    func_80019E84_1AA84(obj, 0xE, dir | 0x56, 1, 0x78);
    func_8000C004_CC04(obj);
    func_8000C35C_CF5C(obj, x, y, z);
    func_80029714_2A314(obj->model[0], x, y, z);
    func_8000C024_CC24(obj, 0, 2);
    func_8000C024_CC24(obj, 1, 2);
    obj->func_ptr = func_801038C4_16C804_ShockDropOrRoll;
}

__asm__(".section .rodata");
const s8 D_80106FF0_16FF30_ShockDropOrRoll[8] = { 20, 40, 40, 40, 40, 40, 40, 40 };     /* intro spin step lengths */
const s8 D_80106FF8_16FF38_ShockDropOrRoll[8] = { -45, 45, -45, 45, -45, 45, -45, 45 }; /* intro spin steps */

/* The solo player's crank: the stick X (clamped to -45..45) is the roller input D_801072B0;
   during the intro it rocks the roller back and forth. The crank motion speed follows the input
   averaged over 8 frames. */
void func_801044BC_16D3FC_ShockDropOrRoll(omObjData* obj) {
    MgWork* w = obj->unk_50;
    s32 unused[1];
    s8 stk;
    s8 i;
    f32 speed;

    if (D_80106ED1_16FE11_ShockDropOrRoll == 1 && D_80106ED2_16FE12_ShockDropOrRoll == 0) {
        if (D_80106F00_16FE40_ShockDropOrRoll++ > D_80106FF0_16FF30_ShockDropOrRoll[D_80106F04_16FE44_ShockDropOrRoll]) {
            D_80106F00_16FE40_ShockDropOrRoll = 0;
            D_80106F04_16FE44_ShockDropOrRoll++;
        }
        D_801072B0_1701F0_ShockDropOrRoll = D_80106FF8_16FF38_ShockDropOrRoll[D_80106F04_16FE44_ShockDropOrRoll];
        if (++D_80106EFC_16FE3C_ShockDropOrRoll >= 0x60) {
            D_80106ED2_16FE12_ShockDropOrRoll = 1;
        }
    }
    if (D_80106ED7_16FE17_ShockDropOrRoll >= 5 && D_80106ED7_16FE17_ShockDropOrRoll < 9) {
        stk = ContStkX[w->unk_57];
        if (stk < -45) {
            stk = -45;
        } else if (stk >= 46) {
            stk = 45;
        }
        D_801072B0_1701F0_ShockDropOrRoll = stk;
    } else if (D_80106ED2_16FE12_ShockDropOrRoll == 1) {
        D_801072B0_1701F0_ShockDropOrRoll = 0;
    }
    speed = (D_801072B0_1701F0_ShockDropOrRoll + 45) / 90.0f * 60.0f;
    D_80106EDC_16FE1C_ShockDropOrRoll[D_80106F08_16FE48_ShockDropOrRoll] = speed;
    D_80106F08_16FE48_ShockDropOrRoll = (D_80106F08_16FE48_ShockDropOrRoll + 1) & 7;
    speed = 0.0f;
    for (i = 0; i < 8; i++) {
        speed += D_80106EDC_16FE1C_ShockDropOrRoll[i];
    }
    speed /= 8.0f;
    if (speed < 30.0f && D_80106F09_16FE49_ShockDropOrRoll != 1) {
        PlaySound(0x1C8);
        D_80106F09_16FE49_ShockDropOrRoll = 1;
    }
    if (speed > 30.0f && D_80106F09_16FE49_ShockDropOrRoll != 2) {
        PlaySound(0x1C8);
        D_80106F09_16FE49_ShockDropOrRoll = 2;
    }
    D_80106F0C_16FE4C_ShockDropOrRoll = speed;
    if ((u32)(D_80106ED7_16FE17_ShockDropOrRoll - 1) < 8) {
        func_80029C74_2A874(obj->model[0], speed);
        func_80029C74_2A874(obj->model[2], speed);
    }
}

__asm__(".section .rodata");
/* solo CPU: frames between turns by difficulty */
const s16 D_80107000_16FF40_ShockDropOrRoll[4][8] = {
    { 50, 100, 150, 50, 120, 50, 100, 50 },
    { 50, 150, 40, 150, 40, 30, 150, 50 },
    { 40, 150, 40, 30, 40, 30, 150, 40 },
    { 30, 200, 20, 100, 20, 20, 30, 200 },
};

/* The solo player's update: a CPU turns the crank one way at full stick and flips the direction
   at random intervals (the first player still on the roller is the one it checks; the "near the
   middle" test can never reach its far-edge case, so it always flips). Then func_801044BC. */
void func_80104784_16D6C4_ShockDropOrRoll(omObjData* obj) {
    SDWorkPair wk;
    MgWork* w = obj->unk_50;
    s8 i;

    for (i = 0; i < 3; i++) {
        wk.w[i] = D_800FFFD8_100BD8[i]->unk_50;
        wk.p[i] = wk.w[i]->unk_158;
    }
    if (D_80106F10_16FE50_ShockDropOrRoll == 0) {
        if (guRandom() & 1) {
            D_80107250_170190_ShockDropOrRoll = 1;
        } else {
            D_80107250_170190_ShockDropOrRoll = -1;
        }
        D_80107252_170192_ShockDropOrRoll = 0;
        D_80107254_170194_ShockDropOrRoll = 0;
        D_80107256_170196_ShockDropOrRoll = D_80107000_16FF40_ShockDropOrRoll[gPlayers[w->unk_59].cpu_difficulty][0];
        D_80106F10_16FE50_ShockDropOrRoll = 1;
    }
    if (D_80106ED3_16FE13_ShockDropOrRoll == 1 && D_80106ED0_16FE10_ShockDropOrRoll == 0) {
        if (gPlayers[w->unk_59].flags & 1) {
            ContBtn[w->unk_57] = 0;
            ContStkX[w->unk_57] = 0;
            ContStkY[w->unk_57] = 0;
            ContBtnTrg[w->unk_57] = 0;
            for (i = 0; i < 3; i++) {
                if (wk.p[i]->fell != 1) {
                    if (D_80107254_170194_ShockDropOrRoll++ > D_80107256_170196_ShockDropOrRoll) {
                        if ((D_800FFFD8_100BD8[i]->trans.z > 0.0f ? D_800FFFD8_100BD8[i]->trans.z : -D_800FFFD8_100BD8[i]->trans.z) < 25.0f) {
                            if (D_80107252_170192_ShockDropOrRoll++ < 3) {
                                if ((D_800FFFD8_100BD8[i]->trans.z > 0.0f ? D_800FFFD8_100BD8[i]->trans.z : -D_800FFFD8_100BD8[i]->trans.z) > 175.0f) {
                                    if (D_800FFFD8_100BD8[i]->trans.z < 0.0f) {
                                        D_80107250_170190_ShockDropOrRoll = -1;
                                    } else {
                                        D_80107250_170190_ShockDropOrRoll = 1;
                                    }
                                } else {
                                    D_80107250_170190_ShockDropOrRoll *= -1;
                                }
                            } else {
                                D_80107250_170190_ShockDropOrRoll *= -1;
                            }
                        } else {
                            D_80107250_170190_ShockDropOrRoll *= -1;
                            D_80107252_170192_ShockDropOrRoll = 0;
                        }
                        D_80107256_170196_ShockDropOrRoll = D_80107000_16FF40_ShockDropOrRoll[gPlayers[w->unk_59].cpu_difficulty][guRandom() & 7];
                        D_80107254_170194_ShockDropOrRoll = 0;
                        break;
                    }
                }
            }
            if (D_80107250_170190_ShockDropOrRoll < 0) {
                ContStkX[w->unk_57] = -60;
            } else {
                ContStkX[w->unk_57] = 60;
            }
        }
    }
    func_801044BC_16D3FC_ShockDropOrRoll(obj);
}

/* The solo player's setup: it stands at the crank (model 0x240006 beside it). */
void func_80104B98_16DAD8_ShockDropOrRoll(omObjData* obj, s32 dir, s32 file, u16 player, f32 x, f32 y, f32 z) {
    MgWork* w;

    obj->unk_50 = func_80027154_27D54(sizeof(MgWork), 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, sizeof(MgWork));
    w = obj->unk_50;
    w->unk_57 = gPlayers[player].port;
    obj->model[0] = LoadFormFile(dir | file, 0xAB9);
    obj->model[1] = LoadFormFile(1, 0xAB9);
    obj->model[2] = LoadFormFile(0x240006, 0xAB9);
    w->unk_59 = player;
    w->unk_52 = 0;
    w->unk_B4 = 1.0f;
    w->unk_D0 = 0xFFFF;
    w->unk_38 = 1000.0f;
    w->unk_50 = 0;
    func_8000BEB0_CAB0(obj, 60.0f);
    func_8000BEBC_CABC(obj, 150.0f);
    func_8000BEC8_CAC8(obj, 20.0f);
    func_8000C024_CC24(obj, 0, 1);
    func_80018CCC_198CC(obj, 0, dir);
    func_80018CCC_198CC(obj, 0xD, dir | 0x4F);
    func_80018CCC_198CC(obj, 0xE, dir | 0x56);
    func_80018CCC_198CC(obj, 0x26, dir | 0x80);
    func_8000C35C_CF5C(obj, x, y, z);
    func_80029714_2A314(obj->model[0], x, y, z);
    func_8000C36C_CF6C(obj, 0.0f, 180.0f, 0.0f);
    func_80029714_2A314(obj->model[1], x, y, z);
    func_80029714_2A314(obj->model[2], x, y, z);
    func_80029B80_2A780(obj->model[0], obj->motion[0x26]);
    func_80029E80_2AA80(obj->model[0], 1, 1);
    func_80029E80_2AA80(obj->model[2], 1, 1);
    func_80029C74_2A874(obj->model[0], 30.0f);
    func_80029C74_2A874(obj->model[2], 30.0f);
    obj->func_ptr = func_80104784_16D6C4_ShockDropOrRoll;
}

/* The game flow (D_80106ED7): 0-1 the intro (music at frame 10, the roller starts at 31),
   2 until the intro spin ends, 3 the players drift back to the middle and "START", 4 the timer
   (30) once the message closes, 5 play (929 frames; time up: the three win; all three fallen:
   the solo player wins; 1P: a human falling ends it, survivors paid), 6 the result camera,
   7-8 the result message, motions and coins, 9-11 fade out and return; 12-13 the 1P result. */
// float register allocation around the two func_800B75A8_B81A8 (atan2) calls (8 lines)
#ifdef NON_MATCHING
void func_80104E24_16DD64_ShockDropOrRoll(omObjData* obj) {
    SDWorkPair wk;
    MgWork* w;
    s8 i;
    s8 n;

    func_8000C3C8_CFC8();
    w = D_801072B4_1701F4_ShockDropOrRoll->unk_50;
    for (i = 0; i < 3; i++) {
        wk.w[i] = D_800FFFD8_100BD8[i]->unk_50;
        wk.p[i] = wk.w[i]->unk_158;
    }
    switch ((s8)D_80106ED7_16FE17_ShockDropOrRoll) {
    case 0:
        func_8000C38C_CF8C();
        D_80107258_170198_ShockDropOrRoll = 0;
        D_80106ED7_16FE17_ShockDropOrRoll++;
        break;
    case 1:
        if (D_80107258_170198_ShockDropOrRoll == 10) {
            PlayMusic(0x1D);
        }
        if (D_80107258_170198_ShockDropOrRoll++ >= 31) {
            D_80106ED1_16FE11_ShockDropOrRoll = 1;
            func_8000C3B8_CFB8();
            D_80106ED7_16FE17_ShockDropOrRoll++;
        }
        break;
    case 2:
        if (D_80106ED2_16FE12_ShockDropOrRoll == 1) {
            D_80107258_170198_ShockDropOrRoll = 0;
            D_80106F70_16FEB0_ShockDropOrRoll = 0.0f;
            D_80106ED7_16FE17_ShockDropOrRoll++;
        }
        break;
    case 3:
        if (D_80107258_170198_ShockDropOrRoll++ >= 31) {
            func_800691FC_69DFC(0);
            D_80106ED3_16FE13_ShockDropOrRoll = 1;
            D_80106ED7_16FE17_ShockDropOrRoll++;
            break;
        }
        for (i = 0; i < 3; i++) {
            if (D_800FFFD8_100BD8[i]->trans.z != 0.0f) {
                if (D_800FFFD8_100BD8[i]->trans.z < 0.0f) {
                    D_800FFFD8_100BD8[i]->trans.z += 5.0f;
                    if (D_800FFFD8_100BD8[i]->trans.z > 0.0f) {
                        D_800FFFD8_100BD8[i]->trans.z = 0.0f;
                    }
                } else {
                    D_800FFFD8_100BD8[i]->trans.z -= 5.0f;
                    if (D_800FFFD8_100BD8[i]->trans.z < 0.0f) {
                        D_800FFFD8_100BD8[i]->trans.z = 0.0f;
                    }
                }
            }
        }
        break;
    case 4:
        for (i = 0; i < 3; i++) {
            wk.w[i]->unk_3C = 0.0f;
        }
        if (func_80069538_6A138() == 0 || (func_80069538_6A138() & 2)) {
            func_800691FC_69DFC(10, 30, 160, 24);
            func_8006D4D0_6E0D0(30);
            PlayMusic(0x1D);
            D_80106ED7_16FE17_ShockDropOrRoll++;
        }
        break;
    case 5:
        if (D_80106ED0_16FE10_ShockDropOrRoll == 1) {
            func_800794A8_7A0A8(0x3C);
            func_8000C398_CF98();
            D_80106ED7_16FE17_ShockDropOrRoll++;
            break;
        }
        func_8006D4D0_6E0D0(D_80106F14_16FE54_ShockDropOrRoll / 30);
        if (D_80106F14_16FE54_ShockDropOrRoll == 0) {
            D_80106ED0_16FE10_ShockDropOrRoll = 1;
            D_80106ED5_16FE15_ShockDropOrRoll = 0;
            func_8006D518_6E118();
        } else {
            D_80106F14_16FE54_ShockDropOrRoll--;
        }
        if (_CheckFlag(0xC) != 0) {
            for (i = 0; i < 3; i++) {
                if (!(gPlayers[wk.w[i]->unk_59].flags & 1) && wk.p[i]->fell == 1) {
                    D_80106ED0_16FE10_ShockDropOrRoll = 1;
                    D_80106ED5_16FE15_ShockDropOrRoll = 1;
                    func_8006D518_6E118();
                }
            }
        } else {
            n = 0;
            for (i = 0; i < 3; i++) {
                if (wk.p[i]->fell == 1) {
                    n++;
                }
            }
            if (n >= 3) {
                D_80106ED0_16FE10_ShockDropOrRoll = 1;
                D_80106ED5_16FE15_ShockDropOrRoll = 1;
                func_8006D518_6E118();
            }
        }
        break;
    case 6:
        D_80106ED8_16FE18_ShockDropOrRoll = 1;
        if (D_80106ED9_16FE19_ShockDropOrRoll == 1) {
            D_80106ED7_16FE17_ShockDropOrRoll++;
        }
        break;
    case 7:
        func_800691FC_69DFC(3);
        D_80106ED7_16FE17_ShockDropOrRoll = (_CheckFlag(0xC) != 0) ? 12 : D_80106ED7_16FE17_ShockDropOrRoll + 1;
        break;
    case 8:
        if (func_80069538_6A138() == 0 || (func_80069538_6A138() & 2)) {
            func_8000C3A8_CFA8();
            D_80106EDA_16FE1A_ShockDropOrRoll = 1;
            switch (D_80106ED5_16FE15_ShockDropOrRoll) {
            case 0:
                PlayMusic(0x52);
                func_800691FC_69DFC(0x15, gPlayers[D_801072B8_1701F8_ShockDropOrRoll[1]].character,
                                    gPlayers[D_801072B8_1701F8_ShockDropOrRoll[2]].character,
                                    gPlayers[D_801072B8_1701F8_ShockDropOrRoll[3]].character);
                func_80029B80_2A780(D_801072B4_1701F4_ShockDropOrRoll->model[0], D_801072B4_1701F4_ShockDropOrRoll->motion[0xE]);
                func_800732B0_73EB0(D_800CD438_CE038[gPlayers[D_801072B8_1701F8_ShockDropOrRoll[0]].character].unk_04 | 0x56);
                gPlayers[D_801072B8_1701F8_ShockDropOrRoll[1]].coins_mg_bonus += 10;
                gPlayers[D_801072B8_1701F8_ShockDropOrRoll[2]].coins_mg_bonus += 10;
                gPlayers[D_801072B8_1701F8_ShockDropOrRoll[3]].coins_mg_bonus += 10;
                D_80107260_1701A0_ShockDropOrRoll = 168;
                break;
            case 1:
                PlayMusic(0x51);
                func_800691FC_69DFC(6, gPlayers[D_801072B8_1701F8_ShockDropOrRoll[0]].character);
                func_80029B80_2A780(D_801072B4_1701F4_ShockDropOrRoll->model[0], D_801072B4_1701F4_ShockDropOrRoll->motion[0xD]);
                func_800732B0_73EB0(D_800CD438_CE038[gPlayers[D_801072B8_1701F8_ShockDropOrRoll[0]].character].unk_04 | 0x4F);
                gPlayers[D_801072B8_1701F8_ShockDropOrRoll[0]].coins_mg_bonus += 10;
                w->unk_3C = -func_800B75A8_B81A8(D_801072B4_1701F4_ShockDropOrRoll->trans.x - D_8010274C_10334C.x,
                                                -(D_801072B4_1701F4_ShockDropOrRoll->trans.z - D_8010274C_10334C.z));
                D_801072B4_1701F4_ShockDropOrRoll->rot.y = w->unk_3C;
                D_80107260_1701A0_ShockDropOrRoll = 120;
                break;
            }
            D_8010725E_17019E_ShockDropOrRoll = 0;
            D_80106ED7_16FE17_ShockDropOrRoll++;
        }
        break;
    case 9:
        if (D_8010725E_17019E_ShockDropOrRoll++ > D_80107260_1701A0_ShockDropOrRoll) {
            func_800794A8_7A0A8(0x28);
            InitFadeOut(0, 0x14);
            func_80079868_7A468();
            func_8000C398_CF98();
            D_80106ED7_16FE17_ShockDropOrRoll = 11;
        }
        break;
    case 10:
        func_800794A8_7A0A8(0x28);
        InitFadeOut(0, 0x14);
        func_80079868_7A468();
        func_8000C398_CF98();
        D_80106ED7_16FE17_ShockDropOrRoll++;
        break;
    case 11:
        if (func_8008F618_90218() == 0) {
            func_80069770_6A370();
            omOvlReturnEx(1);
        }
        break;
    case 12:
        func_8000C3A8_CFA8();
        D_80106EDA_16FE1A_ShockDropOrRoll = 1;
        switch (D_80106ED5_16FE15_ShockDropOrRoll) {
        case 0:
            func_80029B80_2A780(D_801072B4_1701F4_ShockDropOrRoll->model[0], D_801072B4_1701F4_ShockDropOrRoll->motion[0]);
            for (i = 0; i < 3; i++) {
                if (wk.p[i]->fell == 0) {
                    gPlayers[D_801072B8_1701F8_ShockDropOrRoll[i + 1]].coins_mg_bonus += 10;
                }
            }
            break;
        case 1:
            func_80029B80_2A780(D_801072B4_1701F4_ShockDropOrRoll->model[0], D_801072B4_1701F4_ShockDropOrRoll->motion[0]);
            gPlayers[D_801072B8_1701F8_ShockDropOrRoll[0]].coins_mg_bonus += 10;
            for (i = 0; i < 3; i++) {
                if (wk.p[i]->fell == 0) {
                    gPlayers[D_801072B8_1701F8_ShockDropOrRoll[i + 1]].coins_mg_bonus += 10;
                }
            }
            w->unk_3C = -func_800B75A8_B81A8(D_801072B4_1701F4_ShockDropOrRoll->trans.x - D_8010274C_10334C.x,
                                            -(D_801072B4_1701F4_ShockDropOrRoll->trans.z - D_8010274C_10334C.z));
            D_801072B4_1701F4_ShockDropOrRoll->rot.y = w->unk_3C;
            break;
        }
        D_8010725C_17019C_ShockDropOrRoll = 60;
        D_80106ED7_16FE17_ShockDropOrRoll++;
        break;
    case 13:
        if (D_8010725C_17019C_ShockDropOrRoll-- < 0) {
            D_80106ED7_16FE17_ShockDropOrRoll = 10;
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_ShockDropOrRoll/16B740", func_80104E24_16DD64_ShockDropOrRoll);
#endif

__asm__(".section .rodata");
/* The roller camera's keys: [zoom, rot x/y/z, center x/y/z][3], picked by D_801070CC. */
const f32 D_80107078_16FFB8_ShockDropOrRoll[7][3] = {
    { 1000.0f, 1000.0f, 1000.0f }, { 329.0f, 329.0f, 329.0f }, { -141.0f, -90.0f, -50.0f },
    { 0.0f, 0.0f, 0.0f },          { -594.0f, -865.0f, -777.0f }, { 570.0f, 570.0f, 570.0f },
    { -585.0f, 240.0f, 847.0f },
};
const s8 D_801070CC_17000C_ShockDropOrRoll[8] = { 2, 0, 1, 2, 0, 1, 0, 0 }; /* key -> column */
const f32 D_801070D4_170014_ShockDropOrRoll[6] = { 0.0f, 60.0f, 90.0f, 120.0f, 180.0f, 210.0f }; /* key times */

/* The camera: during play it follows the mean z of the players still on the roller (averaged over
   16 frames) along a spline through D_80107078's keys; at the end it moves to the winner's shot in
   60 frames. */
#ifdef NON_MATCHING
/* The result camera: [0] the solo player won, [1] the three won. */
const SDCamera D_801070EC_17002C_ShockDropOrRoll[2] = {
    { 174.0f, { 326.0f, -142.0f, 0.0f }, { -557.0f, 790.0f, -33.0f } },
    { 174.0f, { 321.0f, -93.0f, 0.0f }, { -1317.0f, 1060.0f, -53.0f } },
};
#endif

// float register allocation of the spline time, the loop-invariant t - 60.0f and the result camera
// switch (GCC folds it to xori/sltu); logic checked against the asm
#ifdef NON_MATCHING
void func_80105920_16E860_ShockDropOrRoll(omObjData* obj) {
    SDWorkPair wk;
    s8 i;
    s8 k;
    s8 a;
    s32 c = 0;
    f32 sum;
    f32 n;
    f32 mean;
    f32 total;
    f32 t;

    for (i = 0; i < 3; i++) {
        wk.w[i] = D_800FFFD8_100BD8[i]->unk_50;
        wk.p[i] = wk.w[i]->unk_158;
    }
    if (D_80106ED8_16FE18_ShockDropOrRoll == 0) {
        sum = 0.0f;
        n = 0.0f;
        for (i = 0; i < 3; i++) {
            if (wk.p[i]->fell == 0) {
                if (D_800FFFD8_100BD8[i]->trans.z < -225.0f) {
                    sum -= 225.0f;
                } else if (D_800FFFD8_100BD8[i]->trans.z > 225.0f) {
                    sum += 225.0f;
                } else {
                    sum += D_800FFFD8_100BD8[i]->trans.z;
                }
                n += 1.0f;
            }
        }
        if (n != 0.0f) {
            sum = sum / n;
        } else {
            sum = 0.0f;
        }
        D_80106F18_16FE58_ShockDropOrRoll[D_80106F58_16FE98_ShockDropOrRoll++] = sum;
        D_80106F58_16FE98_ShockDropOrRoll &= 0xF;
        sum = 0.0f;
        for (i = 0; i < 16; i++) {
            sum += D_80106F18_16FE58_ShockDropOrRoll[i];
        }
        sum /= 16.0f;
        t = (sum + 225.0f) / 450.0f * 60.0f + 60.0f;
        for (i = 0; i < 6; i++) {
            k = i;
            if (t - 60.0f < D_801070D4_170014_ShockDropOrRoll[i]) {
                break;
            }
        }
        for (i = 0; i < 7; i++) {
            for (a = 0; a < 4; a++) {
                D_80107268_1701A8_ShockDropOrRoll[a] = D_80107078_16FFB8_ShockDropOrRoll[i][D_801070CC_17000C_ShockDropOrRoll[a + k]];
            }
            D_80107278_1701B8_ShockDropOrRoll[i] = func_8002662C_2722C(D_80107268_1701A8_ShockDropOrRoll, (f32*)&D_801070D4_170014_ShockDropOrRoll[k], t);
        }
        D_800FA610_FB210 = D_80107278_1701B8_ShockDropOrRoll[0];
        D_800FD474_FE074.x = D_80107278_1701B8_ShockDropOrRoll[1];
        D_800FD474_FE074.y = D_80107278_1701B8_ShockDropOrRoll[2];
        D_800FD474_FE074.z = D_80107278_1701B8_ShockDropOrRoll[3];
        D_8010274C_10334C.x = D_80107278_1701B8_ShockDropOrRoll[4];
        D_8010274C_10334C.y = D_80107278_1701B8_ShockDropOrRoll[5];
        D_8010274C_10334C.z = D_80107278_1701B8_ShockDropOrRoll[6];
    } else if (++D_80106F5A_16FE9A_ShockDropOrRoll < 60) {
        switch (D_80106ED5_16FE15_ShockDropOrRoll) {
        case 1:
            c = 0;
            break;
        case 0:
            c = 1;
            break;
        }
        D_800FA610_FB210 += (D_801070EC_17002C_ShockDropOrRoll[c].zoom - D_80107278_1701B8_ShockDropOrRoll[0]) / 60.0f;
        D_800FD474_FE074.x += (D_801070EC_17002C_ShockDropOrRoll[c].rot.x - D_80107278_1701B8_ShockDropOrRoll[1]) / 60.0f;
        D_800FD474_FE074.y += (D_801070EC_17002C_ShockDropOrRoll[c].rot.y - D_80107278_1701B8_ShockDropOrRoll[2]) / 60.0f;
        D_800FD474_FE074.z += (D_801070EC_17002C_ShockDropOrRoll[c].rot.z - D_80107278_1701B8_ShockDropOrRoll[3]) / 60.0f;
        D_8010274C_10334C.x += (D_801070EC_17002C_ShockDropOrRoll[c].center.x - D_80107278_1701B8_ShockDropOrRoll[4]) / 60.0f;
        D_8010274C_10334C.y += (D_801070EC_17002C_ShockDropOrRoll[c].center.y - D_80107278_1701B8_ShockDropOrRoll[5]) / 60.0f;
        D_8010274C_10334C.z += (D_801070EC_17002C_ShockDropOrRoll[c].center.z - D_80107278_1701B8_ShockDropOrRoll[6]) / 60.0f;
        D_80106ED9_16FE19_ShockDropOrRoll = 1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_ShockDropOrRoll/16B740", func_80105920_16E860_ShockDropOrRoll);
/* the asm defines D_801070EC_17002C up to its [0].center.z; the rest (and the file's rodata pad) */
__asm__(".section .rodata");
const u32 D_80107104_170044_ShockDropOrRoll[11] = { 0xC2040000, 0x432E0000, 0x43A08000, 0xC2BA0000, 0x00000000, 0xC4A4A000, 0x44848000, 0xC2540000, 0x00000000, 0x00000000, 0x00000000 };
#endif
