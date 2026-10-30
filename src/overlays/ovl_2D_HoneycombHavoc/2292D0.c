#include "ovl_2D.h"


void func_80102800_2292D0_HoneycombHavoc(void) {
    Vec eye;
    Vec at;

    omInitObjMan(0x3C, 0);
    func_80079128_79D28();
    func_80020D20_21920(0x14);
    D_801076D4_22E1A4_HoneycombHavoc = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x3D0000), 0, 1);
    espDispOff(D_801076D4_22E1A4_HoneycombHavoc);
    eye.x = 0.0f;
    eye.y = 410.0f;
    eye.z = 1200.0f;
    at.x = 0.0f;
    at.y = 400.0f;
    at.z = -100.0f;
    D_8010270C_10330C.x = 0.0f;
    D_8010270C_10330C.y = 0.0f;
    D_8010270C_10330C.z = 1.0f;
    func_8007A2CC_7AECC(0x7FDA, D_800F93FC_F9FFC[(s16)D_801076D4_22E1A4_HoneycombHavoc].unk_04, func_8007A7FC_7B3FC, 45.0f, &eye, &at);
    func_80076BD0_777D0(0, 4);
    D_801076D8_22E1A8_HoneycombHavoc = func_80076D80_77980(0);
    func_80076BD0_777D0(1, 0x21);
    D_801076DC_22E1AC_HoneycombHavoc = func_80076D80_77980(1);
    omAddObj(0, 0, 0, -1, func_80102B34_229604_HoneycombHavoc);
    omAddObj(0x14, 3, 8, 0, func_80102C5C_22972C_HoneycombHavoc);
    omAddObj(0x14, 3, 8, 0, func_80102C7C_22974C_HoneycombHavoc);
    omAddObj(0x14, 3, 8, 0, func_80102C9C_22976C_HoneycombHavoc);
    omAddObj(0x14, 3, 8, 0, func_80102CBC_22978C_HoneycombHavoc);
    func_80104924_22B3F4_HoneycombHavoc();
    func_80105844_22C314_HoneycombHavoc();
    D_80107704_22E1D4_HoneycombHavoc = omAddObj(0x14, 2, 2, -1, func_80102A7C_22954C_HoneycombHavoc);
    func_80104708_22B1D8_HoneycombHavoc();
    func_80105ACC_22C59C_HoneycombHavoc();
    func_80105C04_22C6D4_HoneycombHavoc();
    D_801076B2_22E182_HoneycombHavoc = LoadFormFile(0x3D000A, 0x6BD);
    func_801064A0_22CF70_HoneycombHavoc();
    omAddObj(0x2710, 0, 0, -1, func_801071E0_22DCB0_HoneycombHavoc);
    InitFadeIn(0, 0x10);
}

/* The coin sprite shown over a player who takes a coin. */
void func_80102A7C_22954C_HoneycombHavoc(omObjData* obj) {
    s16 model;
    s16 mdl;

    model = D_800F86D8_F92D8[(s16)(D_80107708_22E1D8_HoneycombHavoc = func_80018D64_19964(0x14, 0x289, 8))].unk00;
    mdl = model;
    HmfModelObjAttrSet(model, 0x70000000, 0x70000000);
    func_800298A4_2A4A4(model, 4, 4);
    func_80029E80_2AA80(model, 2, 0);
    obj->model[0] = mdl;
    obj->unk_50 = &D_80107708_22E1D8_HoneycombHavoc;
    obj->func_ptr = NULL;
}

void func_80102B34_229604_HoneycombHavoc(omObjData* obj) {
    D_801076A8_22E178_HoneycombHavoc = 0;
    D_80107700_22E1D0_HoneycombHavoc = NULL;
    D_801076FC_22E1CC_HoneycombHavoc = NULL;
    D_801074E0_22DFB0_HoneycombHavoc[0] = 0;
    D_801076AE_22E17E_HoneycombHavoc = -1;
    obj->func_ptr = func_80102B70_229640_HoneycombHavoc;
}

/* The game state: intro, play until a winner is set, then the ending. */
void func_80102B70_229640_HoneycombHavoc(omObjData* obj) {
    switch (D_801076A8_22E178_HoneycombHavoc) {
    case 0:
        if (D_801076FC_22E1CC_HoneycombHavoc == NULL) {
            D_801076AA_22E17A_HoneycombHavoc = 0;
            D_801076FC_22E1CC_HoneycombHavoc = omAddObj(4, 0, 0, -1, func_801069C8_22D498_HoneycombHavoc);
        }
        break;
    case 1:
        if (D_801076AE_22E17E_HoneycombHavoc != -1) {
            D_801076A8_22E178_HoneycombHavoc = 2;
        }
        break;
    case 2:
        if (D_80107700_22E1D0_HoneycombHavoc == NULL) {
            D_80107700_22E1D0_HoneycombHavoc = omAddObj(4, 0, 0, -1, func_80106AC4_22D594_HoneycombHavoc);
            D_801076AC_22E17C_HoneycombHavoc = 0;
        }
        break;
    }
}

void func_80102C5C_22972C_HoneycombHavoc(omObjData* obj) {
    func_80102CDC_2297AC_HoneycombHavoc(0, obj);
}

void func_80102C7C_22974C_HoneycombHavoc(omObjData* obj) {
    func_80102CDC_2297AC_HoneycombHavoc(1, obj);
}

void func_80102C9C_22976C_HoneycombHavoc(omObjData* obj) {
    func_80102CDC_2297AC_HoneycombHavoc(2, obj);
}

void func_80102CBC_22978C_HoneycombHavoc(omObjData* obj) {
    func_80102CDC_2297AC_HoneycombHavoc(3, obj);
}

__asm__(".section .rodata");
const char D_801074F0_22DFC0_HoneycombHavoc[16] = "item_hook";

/* A player's setup: model, motions, a free queue slot. */
void func_80102CDC_2297AC_HoneycombHavoc(s32 player, omObjData* obj) {
    HCPlayer* work;
    s32 dir;
    s32 mot;
    s32 slot;

    work = obj->unk_50 = func_80027154_27D54(sizeof(HCPlayer), 0x7918);
    dir = D_800CD438_CE038[(s8)gPlayers[player].character].unk_04;
    obj->model[0] = LoadFormFile(dir | D_800CD438_CE038[(s8)gPlayers[player].character].unk_10, 0x206B9);
    obj->model[1] = func_80018A64_19664(0xD, 0x689);
    obj->model[2] = func_80018A64_19664(0x3D000C, 0x699);
    func_800297E8_2A3E8(obj->model[1], 1.2f, 1.0f, 1.2f);
    func_80018CCC_198CC(obj, 0, dir);
    func_80018CCC_198CC(obj, 1, dir | 1);
    func_80018CCC_198CC(obj, 2, dir | 2);
    func_80018CCC_198CC(obj, 3, dir | 0xA5);
    if (rand8() & 1) {
        mot = dir | 0x4E;
    } else {
        mot = dir | 0x4F;
    }
    func_80018CCC_198CC(obj, 4, mot);
    D_801076B8_22E188_HoneycombHavoc[player] = mot;
    if (rand8() & 1) {
        func_80018CCC_198CC(obj, 5, dir | 0x55);
    } else {
        func_80018CCC_198CC(obj, 5, dir | 0x56);
    }
    func_80018CCC_198CC(obj, 6, dir | 0x13);
    func_80018CCC_198CC(obj, 7, dir | 0x6A);
    func_8002C628_2D228(obj->model[2], obj->model[0], D_801074F0_22DFC0_HoneycombHavoc);
    func_800298A4_2A4A4(obj->model[2], 0x4000, 0x4000);
    mot = func_80029E14_2AA14(obj->motion[6]);
    func_8002C524_2D124(obj->model[0], mot, 2);
    work->state = 0;
    do {
        slot = rand8() & 3;
    } while (D_801073A8_22DE78_HoneycombHavoc[slot] != 0);
    D_801073A8_22DE78_HoneycombHavoc[slot] = 1;
    work->slot = slot;
    work->player = player;
    work->cpuPick = -1;
    work->walking = 0;
    work->out = 0;
    work->limitOn = 0;
    work->limit = 0;
    omSetTra(obj, D_80107388_22DE58_HoneycombHavoc[slot], 0.0f, 0.0f);
    func_80029714_2A314(obj->model[1], obj->trans.x, 0.0f, obj->trans.z);
    func_80029B80_2A780(obj->model[0], obj->motion[2]);
    func_80029E80_2AA80(obj->model[0], 2, 2);
    obj->func_ptr = func_80102FB4_229A84_HoneycombHavoc;
}

/* A player: walk to the branch, spin the dial, catch what falls, and run from the bees. */
void func_80102FB4_229A84_HoneycombHavoc(omObjData* obj) {
    HCPlayer* work = obj->unk_50;
    omObjData* item;
    HCItem* itemWork;
    HCPlayer* other;
    u16 btn;
    s32 i;
    s32 n;
    u8 r;
    f32 dx;
    f32 ang;

    if (work->out == 1) {
        return;
    }
    switch (work->state) {
    case 0:
        dx = -15.6f;
        obj->trans.x += dx;
        obj->rot.y = -90.0f;
        if (obj->trans.x < D_80107398_22DE68_HoneycombHavoc[work->slot]) {
            obj->trans.x = D_80107398_22DE68_HoneycombHavoc[work->slot];
            if (work->slot != 0) {
                work->state = 2;
                func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[0]), 0, 8, 2);
            } else {
                work->state = 1;
                func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[1]), 0, 2, 2);
            }
        }
        break;
    case 1:
        obj->rot.y += 10.0f;
        if (obj->rot.y > 0.0f) {
            obj->rot.y = 0.0f;
            work->state = 4;
            func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[0]), 0, 2, 2);
            work->picked = 0;
            D_801076C8_22E198_HoneycombHavoc = D_80107358_22DE28_HoneycombHavoc[gPlayers[work->player].character];
            D_801076CC_22E19C_HoneycombHavoc = D_80107370_22DE40_HoneycombHavoc[gPlayers[work->player].character];
            if (D_801076A8_22E178_HoneycombHavoc == 1) {
                D_801076E4_22E1B4_HoneycombHavoc->work[0] = 1;
            } else if (D_801076A8_22E178_HoneycombHavoc == 0) {
                D_801076AA_22E17A_HoneycombHavoc = 1;
                work->state = 3;
            }
            if (D_801076A8_22E178_HoneycombHavoc != 0) {
                func_800691FC_69DFC(0xA, 0x3C, 0xA0, 0x18);
                func_8006D4D0_6E0D0(0xA);
                work->limit = 0x149;
            }
        }
        break;
    case 3:
        if (D_801076A8_22E178_HoneycombHavoc == 1) {
            func_800691FC_69DFC(0xA, 0x3C, 0xA0, 0x18);
            func_8006D4D0_6E0D0(0xA);
            work->limit = 0x149;
            work->state = 4;
        }
        break;
    case 4:
        if (work->limit > 0) {
            if (gPlayers[work->player].flags & 1) {
                if (work->cpuPick == -1) {
                    func_801044AC_22AF7C_HoneycombHavoc(obj);
                }
                btn = func_80104684_22B154_HoneycombHavoc(obj);
            } else {
                btn = ContBtnTrg[gPlayers[work->player].port];
            }
            if (D_801076A8_22E178_HoneycombHavoc != 1) {
                break;
            }
            work->limitOn = 1;
            if (!(btn & 0x8000)) {
                break;
            }
        }
        func_8002C570_2D170(obj->model[0]);
        func_80029B80_2A780(obj->model[0], obj->motion[3]);
        work->time = 0.0f;
        work->state = 5;
        work->cpuPick = -1;
        func_8006D518_6E118();
        work->limitOn = 0;
        break;
    case 5:
        work->time += 1.0f;
        if (work->time >= 10.0f && work->picked == 0) {
            PlaySound(0x297);
            func_80079798_7A398(0xBA, work->player);
            work->picked = 1;
            if (func_801047EC_22B2BC_HoneycombHavoc() == 1) {
                func_80105BD4_22C6A4_HoneycombHavoc(8, 8);
                n = (u8)(rand8() % 3) + 1;
                for (i = 0; i < n; i++) {
                    func_801065BC_22D08C_HoneycombHavoc((u8)(rand8() % 81) + -390.0f,
                                                        705.0f - (i * 10) + (rand8() % (i * 20 + 1)));
                }
                n = (u8)(rand8() % 3) + 1;
                for (i = 0; i < n; i++) {
                    func_801065BC_22D08C_HoneycombHavoc((u8)(rand8() % 81) + 345.0f,
                                                        510.0f - (i * 10) + (rand8() % (i * 20 + 1)));
                }
            } else {
                func_80105BD4_22C6A4_HoneycombHavoc(0xC, 0xA);
                n = (u8)(rand8() % 3) + 2;
                for (i = 0; i < n; i++) {
                    func_801065BC_22D08C_HoneycombHavoc((u8)(rand8() % 81) + -390.0f,
                                                        705.0f - (i * 10) + (rand8() % (i * 20 + 1)));
                }
                n = (u8)(rand8() % 3) + 2;
                for (i = 0; i < n; i++) {
                    func_801065BC_22D08C_HoneycombHavoc((u8)(rand8() % 81) + 345.0f,
                                                        510.0f - (i * 10) + (rand8() % (i * 20 + 1)));
                }
            }
        }
        if (work->time >= 20.0f) {
            obj->trans.y = 0.0f;
            work->state = 6;
            func_8002C524_2D124(obj->model[0], func_80029E14_2AA14(obj->motion[6]), 2);
            func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[0]), 0, 2, 2);
        }
        break;
    case 6:
        if (!func_80105BEC_22C6BC_HoneycombHavoc()) {
            r = rand8();
            ang = (u8)(r % 40) + 90.0f;
            func_801053BC_22BE8C_HoneycombHavoc(ang + 30.0f, 40.0f);
            work->state = 7;
            work->walking = 1;
            func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[2]), 0, 2, 2);
        }
        break;
    case 7:
        item = D_801076E0_22E1B0_HoneycombHavoc;
        itemWork = item->unk_50;
        if (item->trans.y < D_801076C8_22E198_HoneycombHavoc) {
            if (itemWork->type == 6) {
                omVibrate(work->player, 0x14, 0, 0x14);
                for (i = 0; i < 4; i++) {
                    other = D_801076D8_22E1A8_HoneycombHavoc[i]->unk_50;
                    other->state = 0xB;
                    other->walking = 0;
                    func_80029BF0_2A7F0(D_801076D8_22E1A8_HoneycombHavoc[i]->model[0],
                                        func_80029E14_2AA14(D_801076D8_22E1A8_HoneycombHavoc[i]->motion[0]), 0, 2, 2);
                }
            } else {
                omVibrate(work->player, 2, 3, 0xA);
                if (itemWork->type == 5) {
                    gPlayers[work->player].coins_mg++;
                    func_800298A4_2A4A4(D_80107704_22E1D4_HoneycombHavoc->model[0], 4, 0);
                    func_80029C74_2A874(D_80107704_22E1D4_HoneycombHavoc->model[0], 0.0f);
                    D_800F86D8_F92D8[*(s16*)D_80107704_22E1D4_HoneycombHavoc->unk_50].unk06 = 0;
                    D_800F86D8_F92D8[*(s16*)D_80107704_22E1D4_HoneycombHavoc->unk_50].unk04 = 0;
                    D_800F86D8_F92D8[*(s16*)D_80107704_22E1D4_HoneycombHavoc->unk_50].unk08 = 0;
                    func_80021198_21D98(*(s16*)D_80107704_22E1D4_HoneycombHavoc->unk_50, 0);
                    D_80107704_22E1D4_HoneycombHavoc->trans.x = HuMathSin(obj->rot.y) * 80.0f + obj->trans.x;
                    D_80107704_22E1D4_HoneycombHavoc->trans.y = obj->trans.y + 160.0f;
                    D_80107704_22E1D4_HoneycombHavoc->trans.z = func_800B7890_B8490(obj->rot.y) * 80.0f + obj->trans.z;
                    D_80107704_22E1D4_HoneycombHavoc->scale.x = D_80107704_22E1D4_HoneycombHavoc->scale.y = D_80107704_22E1D4_HoneycombHavoc->scale.z = 6.0f;
                    PlaySound(9);
                } else {
                    PlaySound(0x296);
                }
                if (D_801076E4_22E1B4_HoneycombHavoc->work[1] == 2) {
                    if (!func_801057AC_22C27C_HoneycombHavoc()) {
                        r = rand8();
                        ang = (u8)(r % 30) + 90.0f;
                        func_801053BC_22BE8C_HoneycombHavoc(ang + 40.0f, 45.0f);
                        work->state = 7;
                        work->walking = 1;
                        func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[2]), 0, 2, 2);
                        D_801076E4_22E1B4_HoneycombHavoc->work[1]--;
                    } else {
                        work->state = 8;
                        func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[0]), 0, 2, 2);
                    }
                } else {
                    work->state = 9;
                    work->walking = 0;
                }
            }
        } else {
            dx = (item->trans.x - (HuMathSin(obj->rot.y) * D_801076CC_22E19C_HoneycombHavoc + obj->trans.x)) * 0.15f;
            if (fabs(dx) < 2.0) {
                dx = 0.0f;
            }
            if (dx > 22.0f) {
                dx = 22.0f;
            }
            if (dx < -22.0f) {
                dx = -22.0f;
            }
            obj->trans.x += dx;
            if (dx != 0.0f) {
                if (dx < 0.0f) {
                    obj->rot.y = -90.0f;
                } else {
                    obj->rot.y = 90.0f;
                }
                if (work->walking == 0) {
                    func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[2]), 0, 2, 2);
                    work->walking = 1;
                }
            } else if (work->walking == 1) {
                func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[0]), 0, 2, 2);
                work->walking = 0;
            }
        }
        break;
    case 8:
        if (!func_801057AC_22C27C_HoneycombHavoc()) {
            r = rand8();
            ang = (u8)(r % 30) + 90.0f;
                        func_801053BC_22BE8C_HoneycombHavoc(ang + 40.0f, 45.0f);
            work->state = 7;
            work->walking = 1;
            func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[2]), 0, 2, 2);
            D_801076E4_22E1B4_HoneycombHavoc->work[1]--;
        }
        break;
    case 9:
        dx = -15.6f;
        obj->trans.x += dx;
        obj->rot.y = -90.0f;
        if (obj->trans.x < -750.0f) {
            work->state = 0;
            omSetTra(obj, D_80107388_22DE58_HoneycombHavoc[0], 0.0f, 0.0f);
            func_80104180_22AC50_HoneycombHavoc();
        }
        break;
    case 10:
        if (--work->wait == 0) {
            work->state = 0;
        }
        break;
    case 11:
        obj->rot.y = func_800B75A8_B81A8(D_801076EC_22E1BC_HoneycombHavoc->trans.y - obj->trans.y,
                                         D_801076EC_22E1BC_HoneycombHavoc->trans.x - obj->trans.x) + 90.0f;
        break;
    case 12:
        obj->rot.y += work->turnStep;
        if (--work->turnCnt == 0) {
            D_80107352_22DE22_HoneycombHavoc = func_800797DC_7A3DC(0x111, work->player);
            work->state = 0xD;
            func_8002C524_2D124(obj->model[0], func_80029E14_2AA14(obj->motion[7]), 2);
        }
        break;
    case 13:
        obj->trans.x -= 24.0f;
        obj->rot.y = -90.0f;
        break;
    case 16:
        obj->rot.y += work->turnStep;
        if (--work->turnCnt == 0) {
            work->state = 0x11;
            func_8002C524_2D124(obj->model[0], func_80029E14_2AA14(obj->motion[7]), 2);
        }
        break;
    case 17:
        obj->trans.x -= 24.0f;
        if (obj->trans.x < -800.0f) {
            func_801043A0_22AE70_HoneycombHavoc();
            obj->rot.y = -90.0f;
        }
        break;
    }
    func_80029714_2A314(obj->model[1], obj->trans.x, 0.0f, obj->trans.z);
    if (work->limitOn == 1) {
        func_8006D4D0_6E0D0(work->limit / 30);
        if (--work->limit < 0) {
            work->limit = 0;
        }
    }
}

/* Everyone still in moves up one queue slot; the front player goes to the back. */
void func_80104180_22AC50_HoneycombHavoc(void) {
    HCPlayer* work;
    s32 i;

    for (i = 0; i < 4; i++) {
        work = D_801076D8_22E1A8_HoneycombHavoc[i]->unk_50;
        if (work->out == 1) {
            continue;
        }
        if (--work->slot < 0) {
            work->slot = D_80107354_22DE24_HoneycombHavoc - 1;
        }
        func_80029BF0_2A7F0(D_801076D8_22E1A8_HoneycombHavoc[i]->model[0],
                            func_80029E14_2AA14(D_801076D8_22E1A8_HoneycombHavoc[i]->motion[2]), 0, 2, 2);
        work->state = 0;
    }
}

/* The players still queued turn to face the bees (state 12). */
void func_80104280_22AD50_HoneycombHavoc(void) {
    HCPlayer* works[4];
    omObjData* obj;
    f32 rot;
    s32 i;

    for (i = 0; i < 4; i++) {
        obj = D_801076D8_22E1A8_HoneycombHavoc[i];
        works[i] = obj->unk_50;
        if (works[i]->out == 1) {
            continue;
        }
        if (works[i]->slot != 0) {
            continue;
        }
        works[i]->state = 0xC;
        rot = obj->rot.y;
        rot += 360.0f;
        if (rot >= 360.0f) {
            rot -= 360.0f;
        }
        works[i]->turnCnt = 8;
        works[i]->turnStep = (270.0f - rot) / 8.0f;
        func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[2]), 0, 2, 2);
    }
}

/* After a round: the players still in go back to their queue slots; the stung one is hidden. */
void func_801043A0_22AE70_HoneycombHavoc(void) {
    omObjData* obj;
    HCPlayer* work;
    s32 i;

    for (i = 0; i < 4; i++) {
        obj = D_801076D8_22E1A8_HoneycombHavoc[i];
        work = obj->unk_50;
        if (work->out == 1) {
            func_800298A4_2A4A4(obj->model[0], 4, 4);
        } else {
            work->wait = 0x1E;
            work->state = 0xA;
            omSetTra(D_801076D8_22E1A8_HoneycombHavoc[i], D_80107388_22DE58_HoneycombHavoc[work->slot], 0.0f, 0.0f);
            func_8002C524_2D124(obj->model[0], func_80029E14_2AA14(obj->motion[6]), 2);
        }
    }
}

/* A CPU's dial target: one or two at random, two by difficulty to reach a coin or to leave a
   honeycomb to the next player, never two onto a honeycomb. */
void func_801044AC_22AF7C_HoneycombHavoc(omObjData* obj) {
    HCPlayer* work = obj->unk_50;
    u16 diff;

    work->cpuPick = (rand8() & 1) + 1;
    diff = gPlayers[work->player].cpu_difficulty;
    if (D_801076B0_22E180_HoneycombHavoc > 0) {
        if (*(u16*)D_801076DC_22E1AC_HoneycombHavoc[D_801076B0_22E180_HoneycombHavoc - 1]->unk_50 == 5) {
            switch (diff) {
            case 1:
                if (!(rand8() & 3)) {
                    work->cpuPick = 2;
                }
                break;
            case 2:
                if (rand8() & 1) {
                    work->cpuPick = 2;
                }
                break;
            case 3:
                work->cpuPick = 2;
                break;
            }
        }
    }
    if (D_801076B0_22E180_HoneycombHavoc >= 2) {
        if (*(u16*)D_801076DC_22E1AC_HoneycombHavoc[D_801076B0_22E180_HoneycombHavoc - 2]->unk_50 == 6) {
            switch (diff) {
            case 1:
                if (!(rand8() & 3)) {
                    work->cpuPick = 2;
                }
                break;
            case 2:
                if (rand8() & 1) {
                    work->cpuPick = 2;
                }
                break;
            case 3:
                work->cpuPick = 2;
                break;
            }
        }
    }
    if (D_801076B0_22E180_HoneycombHavoc > 0 &&
        *(u16*)D_801076DC_22E1AC_HoneycombHavoc[D_801076B0_22E180_HoneycombHavoc - 1]->unk_50 == 6) {
        work->cpuPick = 1;
    }
}

/* A CPU's A press: 0x8000 when the dial, ten frames ahead, shows its target. */
u16 func_80104684_22B154_HoneycombHavoc(omObjData* obj) {
    HCPlayer* work = obj->unk_50;
    s32 quarter;
    f32 angle;

    angle = D_801076E4_22E1B4_HoneycombHavoc->rot.x;
    angle += D_801076D0_22E1A0_HoneycombHavoc * 10.0f;
    if (angle >= 360.0f) {
        angle -= 360.0f;
    }
    return (func_8010488C_22B35C_HoneycombHavoc(angle, &quarter) == work->cpuPick) << 15;
}

/* The dial. */
void func_80104708_22B1D8_HoneycombHavoc(void) {
    D_801076E4_22E1B4_HoneycombHavoc = omAddObj(0xA, 1, 0, -1, func_8010479C_22B26C_HoneycombHavoc);
    D_801076E4_22E1B4_HoneycombHavoc->model[0] = LoadFormFile(0x3D0008, 0x206B9);
    omSetTra(D_801076E4_22E1B4_HoneycombHavoc, 0.0f, 250.0f, 0.0f);
    D_801076E4_22E1B4_HoneycombHavoc->work[0] = 0;
    D_801076D0_22E1A0_HoneycombHavoc = 3.0f;
}

void func_8010479C_22B26C_HoneycombHavoc(omObjData* obj) {
    if (obj->work[0] == 1) {
        obj->rot.x += D_801076D0_22E1A0_HoneycombHavoc;
        if (obj->rot.x >= 360.0f) {
            obj->rot.x -= 360.0f;
        }
    }
}

/* Stops the dial on the nearest quarter; returns its value (1 or 2; 1 for the last item). */
u8 func_801047EC_22B2BC_HoneycombHavoc(void) {
    s32 quarter;

    D_801076E4_22E1B4_HoneycombHavoc->work[0] = 0;
    D_801076E4_22E1B4_HoneycombHavoc->work[1] = func_8010488C_22B35C_HoneycombHavoc(D_801076E4_22E1B4_HoneycombHavoc->rot.x, &quarter);
    quarter *= 90;
    if (quarter >= 360) {
        quarter -= 360;
    }
    D_801076E4_22E1B4_HoneycombHavoc->rot.x = quarter;
    if (D_801076B0_22E180_HoneycombHavoc == 0) {
        D_801076E4_22E1B4_HoneycombHavoc->work[1] = 1;
    }
    return D_801076E4_22E1B4_HoneycombHavoc->work[1];
}

/* The dial value at an angle: the nearest quarter, odd quarters 2, even 1. */
u8 func_8010488C_22B35C_HoneycombHavoc(f32 angle, s32* quarter) {
    *quarter = (s32)angle / 90;
    if ((f32)func_800B0D98_B1998(angle, 90.0) >= 45.0f) {
        (*quarter)++;
    }
    return (*quarter & 1) + 1;
}




const s8 D_80107558_22E028_HoneycombHavoc[8][13] = {
    { 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 2, 3 },
    { 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 2, 3 },
    { 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 2, 3, 3 },
    { 0, 0, 1, 0, 1, 1, 0, 0, 0, 2, 3, 3, 3 },
    { 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 3 },
    { 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 2, 3 },
    { 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 2, 3 },
    { 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 2, 3, 3 },
};

const s8 D_801075C0_22E090_HoneycombHavoc[6][12] = {
    { 0, 0, 0, 0, 0, 0, 1, 1, 0, 2, 3, 3 },
    { 0, 0, 1, 0, 0, 0, 0, 1, 0, 2, 3, 3 },
    { 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 2, 3 },
    { 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 3, 3 },
    { 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 3, 3 },
    { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 2, 3 },
};

const s8 D_80107608_22E0D8_HoneycombHavoc[6][11] = {
    { 0, 0, 0, 0, 1, 0, 0, 0, 2, 3, 0 },
    { 0, 0, 0, 0, 0, 1, 0, 0, 2, 3, 0 },
    { 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 3 },
    { 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 3 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};

/* Picks a random branch layout (three pattern tables: 0 a random fruit, not the same as the one
   below it; 1 a coin; 2 a honeycomb; 3 the end), reverses it, and creates the items. */
#ifdef NON_MATCHING
/* masked residue: loop 1 hoists the item list address instead of the pattern table, the reverse
   loop computes cnt - (i + 1) differently, and mfhi lands in t2 instead of t3. Logic checked. */
void func_80104924_22B3F4_HoneycombHavoc(void) {
    s8 base[2];
    u32 r;
    s32 i;
    s32 end;
    s8 type;
    s32 rnd;
    u16 t;
    omObjData* obj;
    HCItem* work;
    s16 model;

    type = 0;
    for (i = 0; i < 33; i++) {
        D_80107710_22E1E0_HoneycombHavoc[i] = 0;
    }
    r = guRandom();
    if (r & 1) {
        base[0] = 0;
        base[1] = 0;
    } else {
        base[0] = 4;
        base[1] = 3;
    }
    r >>= 1;
    i = 0;
    D_80107770_22E240_HoneycombHavoc = 0;
    end = 0;
    for (;;) {
        switch (D_80107558_22E028_HoneycombHavoc[(r & 3) + base[0]][i]) {
        case 0:
            rnd = guRandom() % 5;
            type = rnd;
            if (D_80107770_22E240_HoneycombHavoc > 0 &&
                D_80107710_22E1E0_HoneycombHavoc[D_80107770_22E240_HoneycombHavoc - 1] == type) {
                type = (s8)(rnd + 1 + guRandom() % 4) % 5;
            }
            break;
        case 1:
            type = 5;
            break;
        case 2:
            type = 6;
            break;
        case 3:
            end = 1;
            break;
        }
        if (end == 1) {
            break;
        }
        D_80107710_22E1E0_HoneycombHavoc[D_80107770_22E240_HoneycombHavoc] = type;
        D_80107770_22E240_HoneycombHavoc++;
        i++;
    }
    r >>= 2;
    i = 0;
    end = 0;
    for (;;) {
        switch (D_801075C0_22E090_HoneycombHavoc[(s8)(r % 3) + base[1]][i]) {
        case 0:
            rnd = guRandom() % 5;
            type = rnd;
            if (D_80107770_22E240_HoneycombHavoc > 0 &&
                D_80107710_22E1E0_HoneycombHavoc[D_80107770_22E240_HoneycombHavoc - 1] == type) {
                type = (s8)(rnd + 1 + guRandom() % 4) % 5;
            }
            break;
        case 1:
            type = 5;
            break;
        case 2:
            type = 6;
            break;
        case 3:
            end = 1;
            break;
        }
        if (end == 1) {
            break;
        }
        D_80107710_22E1E0_HoneycombHavoc[D_80107770_22E240_HoneycombHavoc] = type;
        D_80107770_22E240_HoneycombHavoc++;
        i++;
    }
    r >>= 3;
    i = 0;
    end = 0;
    for (;;) {
        switch (D_80107608_22E0D8_HoneycombHavoc[r & 3][i]) {
        case 0:
            rnd = guRandom() % 5;
            type = rnd;
            if (D_80107770_22E240_HoneycombHavoc > 0 &&
                D_80107710_22E1E0_HoneycombHavoc[D_80107770_22E240_HoneycombHavoc - 1] == type) {
                type = (s8)(rnd + 1 + guRandom() % 4) % 5;
            }
            break;
        case 1:
            type = 5;
            break;
        case 2:
            type = 6;
            break;
        case 3:
            end = 1;
            break;
        }
        if (end == 1) {
            break;
        }
        D_80107710_22E1E0_HoneycombHavoc[D_80107770_22E240_HoneycombHavoc] = type;
        D_80107770_22E240_HoneycombHavoc++;
        i++;
    }
    for (i = 0; i < D_80107770_22E240_HoneycombHavoc / 2; i++) {
        t = D_80107710_22E1E0_HoneycombHavoc[i];
        D_80107710_22E1E0_HoneycombHavoc[i] = D_80107710_22E1E0_HoneycombHavoc[D_80107770_22E240_HoneycombHavoc - (i + 1)];
        D_80107710_22E1E0_HoneycombHavoc[D_80107770_22E240_HoneycombHavoc - (i + 1)] = t;
    }
    for (i = 0; i < 5; i++) {
        D_80107758_22E228_HoneycombHavoc[i] = LoadFormFile(D_801073B0_22DE80_HoneycombHavoc[i] | 0x3D0000, 0x6B9);
    }
    D_80107758_22E228_HoneycombHavoc[5] = 0xFFFF;
    for (i = 5; i < 7; i++) {
        D_80107758_22E228_HoneycombHavoc[i + 1] = LoadFormFile(D_801073B0_22DE80_HoneycombHavoc[i] | 0x3D0000, 0x6B9);
    }
    for (i = 0; i < 8; i++) {
        if (D_80107758_22E228_HoneycombHavoc[i] != 0xFFFF) {
            func_800298A4_2A4A4(D_80107758_22E228_HoneycombHavoc[i], 4, 4);
        }
    }
    for (i = 0; i < D_80107770_22E240_HoneycombHavoc; i++) {
        obj = omAddObj(0x1E, 1, 0, 1, func_80105230_22BD00_HoneycombHavoc);
        work = obj->unk_50 = func_80027154_27D54(sizeof(HCItem), 0x7918);
        work->type = D_80107710_22E1E0_HoneycombHavoc[i];
        work->slot = i - (D_80107770_22E240_HoneycombHavoc - 33);
        obj->work[0] = 0;
        if (D_80107758_22E228_HoneycombHavoc[D_80107710_22E1E0_HoneycombHavoc[i]] != 0xFFFF) {
            model = func_80027D3C_2893C(D_80107758_22E228_HoneycombHavoc[D_80107710_22E1E0_HoneycombHavoc[i]]);
        } else {
            model = D_800F86D8_F92D8[func_80018D64_19964(0xE, 0x289, 8)].unk00;
            HmfModelObjAttrSet(model, 0x70000000, 0x70000000);
        }
        obj->model[0] = model;
        if (D_80107758_22E228_HoneycombHavoc[D_80107710_22E1E0_HoneycombHavoc[i]] == 0xFFFF) {
            obj->scale.x = obj->scale.y = obj->scale.z = 2.5f;
            omSetTra(obj, D_801073C0_22DE90_HoneycombHavoc[i + 33 - D_80107770_22E240_HoneycombHavoc][0],
                     D_801073C0_22DE90_HoneycombHavoc[i + 33 - D_80107770_22E240_HoneycombHavoc][1] - 40.0f, -8.0f);
        } else {
            omSetTra(obj, D_801073C0_22DE90_HoneycombHavoc[i + 33 - D_80107770_22E240_HoneycombHavoc][0],
                     D_801073C0_22DE90_HoneycombHavoc[i + 33 - D_80107770_22E240_HoneycombHavoc][1], -8.0f);
        }
        if (D_80107710_22E1E0_HoneycombHavoc[i] == 6) {
            obj->scale.x = obj->scale.y = obj->scale.z = 1.2f;
        }
        func_800298A4_2A4A4(model, 4, 0);
        if (D_80107710_22E1E0_HoneycombHavoc[i] == 7) {
            work->sparkleMdl = LoadFormFile(0x3D000D, 0x6B9);
            func_80029E80_2AA80(work->sparkleMdl, 2, 2);
            func_80029E80_2AA80(obj->model[0], 2, 2);
            func_80029714_2A314(work->sparkleMdl, obj->trans.x, obj->trans.y, obj->trans.z);
        }
        obj->func_ptr = func_80105230_22BD00_HoneycombHavoc;
    }
    D_801076B0_22E180_HoneycombHavoc = D_80107770_22E240_HoneycombHavoc - 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2D_HoneycombHavoc/2292D0", func_80104924_22B3F4_HoneycombHavoc);
#endif

/* An item: moves along the branch (work[0] 1) toward its next slot. */
void func_80105230_22BD00_HoneycombHavoc(omObjData* obj) {
    HCItem* work = obj->unk_50;

    obj->trans.z = work->slot;
    if (work->slot < 18) {
        func_800298A4_2A4A4(obj->model[0], 4, 4);
    } else {
        func_800298A4_2A4A4(obj->model[0], 4, 0);
    }
    switch (obj->work[0]) {
    case 0:
        if (work->type == 7) {
            func_80029714_2A314(work->sparkleMdl, obj->trans.x, obj->trans.y, obj->trans.z);
        }
        break;
    case 1:
        if (work->type == 7) {
            func_80029714_2A314(work->sparkleMdl, obj->trans.x, obj->trans.y, obj->trans.z);
        }
        obj->trans.x += work->vx;
        obj->trans.y += work->vy;
        if (work->type != 7) {
            if (work->slot < 27) {
                obj->rot.z -= 12.0f;
            } else {
                obj->rot.z += 12.0f;
            }
        }
        if (obj->rot.z >= 360.0f) {
            obj->rot.z -= 360.0f;
        }
        if (--work->timer == 0) {
            obj->work[0] = 0;
        }
        break;
    }
}

/* Throws the lowest item toward the player (at angle, speed) and moves the rest down a slot. */
void func_801053BC_22BE8C_HoneycombHavoc(f32 angle, f32 speed) {
    omObjData* obj;
    HCItem* work;
    s32 i;

    obj = D_801076DC_22E1AC_HoneycombHavoc[D_801076B0_22E180_HoneycombHavoc];
    D_801076E0_22E1B0_HoneycombHavoc = obj;
    obj->func_ptr = func_801055EC_22C0BC_HoneycombHavoc;
    obj->work[0] = 2;
    work = obj->unk_50;
    work->unk_10 = (obj->trans.x - 200.0f) - (u8)(rand8() % 150);
    work->unk_14 = D_801076C8_22E198_HoneycombHavoc;
    work->angle = angle;
    work->speed = speed;
    work->x0 = obj->trans.x;
    work->y0 = obj->trans.y;
    work->timer = 0x78;
    work->sparkle = 6;
    D_801076B0_22E180_HoneycombHavoc--;
    if (work->type == 7) {
        func_800298A4_2A4A4(work->sparkleMdl, 4, 4);
    }
    for (i = 0; i <= D_801076B0_22E180_HoneycombHavoc; i++) {
        obj = D_801076DC_22E1AC_HoneycombHavoc[i];
        work = obj->unk_50;
        obj->work[0] = 1;
        work->vx = (D_801073C0_22DE90_HoneycombHavoc[work->slot + 1][0] - obj->trans.x) / 30.0f;
        if (work->type == 5) {
            work->vy = ((D_801073C0_22DE90_HoneycombHavoc[work->slot + 1][1] - 40.0f) - obj->trans.y) / 30.0f;
        } else {
            work->vy = (D_801073C0_22DE90_HoneycombHavoc[work->slot + 1][1] - obj->trans.y) / 30.0f;
        }
        work->timer = 0x1E;
        work->slot++;
        work->sparkle = 6;
    }
}

/* The thrown item's arc; a honeycomb near the catch height lets the bees out. */
void func_801055EC_22C0BC_HoneycombHavoc(omObjData* obj) {
    HCItem* work = obj->unk_50;
    f32 t;
    f32 dx;
    f32 dy;

    work->timer--;
    t = 0x78 - work->timer;
    dx = func_800B7890_B8490(work->angle) * (work->speed / 7.0f) * t;
    dy = HuMathSin(work->angle) * work->speed * t - t * 1.3f * t;
    if (work->sparkle != 0 && work->type == 7) {
        if (--work->sparkle == 0) {
            work->sparkle = 6;
            func_801059DC_22C4AC_HoneycombHavoc(obj->trans.x, obj->trans.y, obj->trans.z);
        }
    }
    obj->trans.x = dx + work->x0;
    obj->trans.y = dy + work->y0;
    obj->trans.z = 2.0f;
    if (obj->trans.y <= D_801076C8_22E198_HoneycombHavoc + 20.0f && work->type == 6) {
        func_801062A8_22CD78_HoneycombHavoc(obj->trans.x, 110.0f);
    }
    if (work->timer == 0 || obj->trans.y <= D_801076C8_22E198_HoneycombHavoc) {
        func_800298A4_2A4A4(obj->model[0], 4, 4);
        obj->func_ptr = NULL;
    }
}

/* Nonzero while the items are still moving down the branch. */
u16 func_801057AC_22C27C_HoneycombHavoc(void) {
    return D_801076DC_22E1AC_HoneycombHavoc[D_801076B0_22E180_HoneycombHavoc]->work[0] != 0;
}

/* Unused: whether item i's neighbour (or item i itself, arg2 1) has this type. */
/* NON_MATCHING: register residue only (the constant 1 of arg2 == 1 lives in v1 in retail). */
#ifdef NON_MATCHING
s32 func_801057D4_22C2A4_HoneycombHavoc(s32 i, s32 type, s32 arg2) {
    if (i > 0 && D_80107710_22E1E0_HoneycombHavoc[i - 1] == type) {
        return 1;
    }
    if (i < 32 && D_80107710_22E1E0_HoneycombHavoc[i + 1] == type) {
        return 1;
    }
    if (arg2 == 1) {
        return D_80107710_22E1E0_HoneycombHavoc[i] == type;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2D_HoneycombHavoc/2292D0", func_801057D4_22C2A4_HoneycombHavoc);
#endif

/* The sparkle pool. */
void func_80105844_22C314_HoneycombHavoc(void) {
    HCSparkles* work;
    s32 i;

    D_801076F4_22E1C4_HoneycombHavoc = omAddObj(0x28, 0, 0, -1, func_801058FC_22C3CC_HoneycombHavoc);
    work = D_801076F4_22E1C4_HoneycombHavoc->unk_50 = func_80027154_27D54(sizeof(HCSparkles), 0x7918);
    for (i = 0; i < 6; i++) {
        work->active[i] = 0;
        work->model[i] = LoadFormFile(0x3D000D, 0x6B9);
        func_800298A4_2A4A4(work->model[i], 4, 4);
    }
}

void func_801058FC_22C3CC_HoneycombHavoc(omObjData* obj) {
    HCSparkles* work = obj->unk_50;
    f32 time;
    s32 i;

    for (i = 0; i < 6; i++) {
        if (work->active[i] == 0) {
            continue;
        }
        time = func_80029CE4_2A8E4(work->model[i]);
        if (func_80029D0C_2A90C(work->model[i]) <= time) {
            work->active[i] = 0;
            func_800298A4_2A4A4(work->model[i], 4, 4);
        }
        work->pos[i].y += -3.0f;
        func_80029714_2A314(work->model[i], work->pos[i].x, work->pos[i].y, work->pos[i].z);
    }
}

void func_801059DC_22C4AC_HoneycombHavoc(f32 x, f32 y, f32 z) {
    HCSparkles* work = D_801076F4_22E1C4_HoneycombHavoc->unk_50;
    s32 i;

    for (i = 0; i < 6; i++) {
        if (work->active[i] == 0) {
            break;
        }
    }
    if (i != 6) {
        work->active[i] = 1;
        func_80029C74_2A874(work->model[i], 0.0f);
        func_800298A4_2A4A4(work->model[i], 4, 0);
        work->pos[i].x = x;
        work->pos[i].y = y;
        work->pos[i].z = z;
        func_80029714_2A314(work->model[i], x, y, z);
    }
}

/* The screen shake. */
void func_80105ACC_22C59C_HoneycombHavoc(void) {
    HCShake* work;

    D_801076E8_22E1B8_HoneycombHavoc = omAddObj(0x28, 0, 0, -1, func_80105B24_22C5F4_HoneycombHavoc);
    work = D_801076E8_22E1B8_HoneycombHavoc->unk_50 = func_80027154_27D54(sizeof(HCShake), 0x7918);
    work->count = 0;
}

void func_80105B24_22C5F4_HoneycombHavoc(omObjData* obj) {
    HCShake* work = obj->unk_50;

    if (work->count != 0) {
        D_8010274C_10334C.y = work->amp + 400.0f;
        D_801076F0_22E1C0_HoneycombHavoc->trans.x += work->amp;
        work->amp = -work->amp;
        if (--work->count == 0) {
            D_8010274C_10334C.y = 400.0f;
        }
        if (work->count == 2) {
            func_80106598_22D068_HoneycombHavoc();
        }
    }
}

void func_80105BD4_22C6A4_HoneycombHavoc(s16 count, s16 amp) {
    HCShake* work = D_801076E8_22E1B8_HoneycombHavoc->unk_50;

    work->count = count;
    work->amp = amp;
}

u16 func_80105BEC_22C6BC_HoneycombHavoc(void) {
    return ((HCShake*)D_801076E8_22E1B8_HoneycombHavoc->unk_50)->count != 0;
}

/* The bees. */
void func_80105C04_22C6D4_HoneycombHavoc(void) {
    HCBees* work;

    D_801076EC_22E1BC_HoneycombHavoc = omAddObj(0x28, 1, 0, -1, func_80105CB8_22C788_HoneycombHavoc);
    work = D_801076EC_22E1BC_HoneycombHavoc->unk_50 = func_80027154_27D54(sizeof(HCBees), 0x7918);
    work->hit = 0;
    D_801076EC_22E1BC_HoneycombHavoc->work[0] = 0;
    D_801076EC_22E1BC_HoneycombHavoc->model[0] = LoadFormFile(0x3D0009, 0x6B9);
    func_800298A4_2A4A4(D_801076EC_22E1BC_HoneycombHavoc->model[0], 4, 4);
    func_80029E80_2AA80(D_801076EC_22E1BC_HoneycombHavoc->model[0], 2, 2);
}

/* The bees: swarm out of the honeycomb (1-3), chase the queue off screen (4-5); the player at the
   front is out. With one player left (or, with flag 0xC, the human out) the game ends. */
/* NON_MATCHING: register residue only (v0/v1 swapped in the first players loop of state 5). */
#ifdef NON_MATCHING
void func_80105CB8_22C788_HoneycombHavoc(omObjData* obj) {
    HCBees* work = obj->unk_50;
    HCPlayer* pw;
    s32 i;
    s32 j;

    func_80106324_22CDF4_HoneycombHavoc();
    switch (obj->work[0]) {
    case 0:
        break;
    case 1:
        work->scale += 0.1f;
        omSetSca(obj, work->scale, work->scale, work->scale);
        if (work->scale >= 1.0f) {
            obj->work[0] = 2;
            work->angle = 270.0f;
            work->radius = 12.0f;
            obj->trans.z = 40.0f;
            work->dAngle = -15.0f;
        }
        break;
    case 2:
        obj->trans.x += func_800B7890_B8490(work->angle) * work->radius;
        obj->trans.y += HuMathSin(work->angle) * work->radius;
        work->radius += 1.0f;
        work->angle += work->dAngle;
        work->dAngle += 0.2f;
        if (work->angle < -90.0f) {
            obj->work[0] = 4;
            work->timer = 0xF;
            work->angle = 0.0f;
        }
        break;
    case 3:
        if (--work->timer == 0) {
            obj->work[0] = 4;
            work->angle = 70.0f;
            work->dAngle = -4.0f;
            work->radius = 30.0f;
            break;
        }
        obj->trans.y += HuMathSin(work->angle) * 5.0f;
        work->angle += 30.0f;
        if (work->angle >= 360.0f) {
            work->angle -= 360.0f;
        }
        break;
    case 4:
        if (work->hit == 0) {
            func_80104280_22AD50_HoneycombHavoc();
            work->hit = 1;
        }
        obj->work[0] = 5;
        work->angle = 0.0f;
        work->dAngle = 0.0f;
        work->radius = 0.0f;
        break;
    case 5:
        obj->trans.x -= 24.0f;
        obj->trans.y += HuMathSin(work->angle) * work->radius;
        work->angle += work->dAngle;
        if (work->angle >= 360.0f) {
            work->angle -= 360.0f;
        }
        if (obj->trans.x < -700.0f) {
            func_800799A4_7A5A4(D_80107350_22DE20_HoneycombHavoc, 5);
        }
        if (obj->trans.x < -850.0f) {
            func_800298A4_2A4A4(D_801076EC_22E1BC_HoneycombHavoc->model[0], 4, 4);
            obj->work[0] = 6;
            for (i = 0; i < 4; i++) {
                pw = D_801076D8_22E1A8_HoneycombHavoc[i]->unk_50;
                if (pw->slot == 0) {
                    pw->out = 1;
                }
            }
            D_80107354_22DE24_HoneycombHavoc--;
            func_80104180_22AC50_HoneycombHavoc();
            D_801074C8_22DF98_HoneycombHavoc = 0;
            if (!_CheckFlag(0xC)) {
                if (D_80107354_22DE24_HoneycombHavoc < 2) {
                    func_800794A8_7A0A8(0x28);
                    for (i = 0; i < 4; i++) {
                        pw = D_801076D8_22E1A8_HoneycombHavoc[i]->unk_50;
                        if (pw->out == 0) {
                            D_801076AE_22E17E_HoneycombHavoc = pw->player;
                            pw->state = 0xE;
                        } else {
                            pw->state = 0xF;
                        }
                    }
                }
            } else if (D_80107354_22DE24_HoneycombHavoc < 2) {
                func_800794A8_7A0A8(0x28);
                for (i = 0; i < 4; i++) {
                    pw = D_801076D8_22E1A8_HoneycombHavoc[i]->unk_50;
                    if (pw->out == 0) {
                        D_801076AE_22E17E_HoneycombHavoc = pw->player;
                        pw->state = 0xE;
                    } else {
                        pw->state = 0xF;
                    }
                }
            } else {
                for (i = 0; i < 4; i++) {
                    pw = D_801076D8_22E1A8_HoneycombHavoc[i]->unk_50;
                    if (gPlayers[pw->player].flags & 1) {
                        continue;
                    }
                    if (pw->out != 1) {
                        continue;
                    }
                    D_801076AE_22E17E_HoneycombHavoc = 5;
                    func_800794A8_7A0A8(0x28);
                    func_8006D518_6E118();
                    pw->limitOn = 0;
                    pw->state = 0xF;
                    for (j = 0; j < 4; j++) {
                        if (i != j) {
                            pw = D_801076D8_22E1A8_HoneycombHavoc[j]->unk_50;
                            pw->state = 0xE;
                        }
                    }
                    break;
                }
            }
            func_80079848_7A448(D_80107350_22DE20_HoneycombHavoc);
            D_80107350_22DE20_HoneycombHavoc = -1;
            work->hit = 0;
        }
        break;
    case 6:
        if (D_801074C8_22DF98_HoneycombHavoc++ >= 0x79) {
            obj->work[0] = 0;
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_2D_HoneycombHavoc/2292D0", func_80105CB8_22C788_HoneycombHavoc);
#endif

/* Lets the bees out at (x, y). */
void func_801062A8_22CD78_HoneycombHavoc(f32 x, f32 y) {
    HCBees* work = D_801076EC_22E1BC_HoneycombHavoc->unk_50;

    D_801076EC_22E1BC_HoneycombHavoc->work[0] = 1;
    omSetTra(D_801076EC_22E1BC_HoneycombHavoc, x, y, 30.0f);
    func_800298A4_2A4A4(D_801076EC_22E1BC_HoneycombHavoc->model[0], 4, 0);
    work->scale = 0.0f;
    D_80107350_22DE20_HoneycombHavoc = PlaySound(0x298);
    func_80106324_22CDF4_HoneycombHavoc();
}

/* The buzz volume follows the bees' x. */
void func_80106324_22CDF4_HoneycombHavoc(void) {
    omObjData* cam;
    f32 vol;

    cam = D_801076EC_22E1BC_HoneycombHavoc;
    if (D_80107350_22DE20_HoneycombHavoc != -1) {
        vol = ((cam->trans.x + 600.0f) / 1200.0f) * 64.0f + 32.0f;
        if (vol < 32.0f) {
            vol = 32.0f;
        }
        if (vol > 64.0f) {
            vol = 64.0f;
        }
        func_800798F8_7A4F8(D_80107350_22DE20_HoneycombHavoc, vol);
        if (D_80107352_22DE22_HoneycombHavoc != -1) {
            vol = ((D_801076EC_22E1BC_HoneycombHavoc->trans.x + 600.0f) / 1200.0f) * 64.0f + 32.0f;
            if (vol < 32.0f) {
                vol = 32.0f;
            }
            if (vol > 64.0f) {
                vol = 64.0f;
            }
            func_800798F8_7A4F8(D_80107352_22DE22_HoneycombHavoc, vol);
        }
    }
}

/* The tree. */
void func_801064A0_22CF70_HoneycombHavoc(void) {
    omObjData* obj;

    D_801076F0_22E1C0_HoneycombHavoc = obj = omAddObj(0x28, 1, 0, -1, func_80106540_22D010_HoneycombHavoc);
    obj->model[0] = LoadFormFile(0x3D000B, 0x6B9);
    omSetTra(obj, -50.0f, 40.0f, 0.0f);
    obj->work[0] = 0;
    obj->trans.y += 30.0f;
    obj->trans.z = 40.0f;
}

/* The tree shakes while work[1] counts down. */
void func_80106540_22D010_HoneycombHavoc(omObjData* obj) {
    f32 d;

    if (obj->work[0] != 0) {
        if (obj->work[1] & 1) {
            d = 12.0f;
        } else {
            d = -12.0f;
        }
        obj->trans.x = d + obj->trans.x;
        if (--obj->work[1] == 0) {
            obj->work[0] = 0;
        }
    }
}

void func_80106598_22D068_HoneycombHavoc(void) {
    D_801076F0_22E1C0_HoneycombHavoc->work[0] = 1;
    D_801076F0_22E1C0_HoneycombHavoc->work[1] = 0xE;
}

/* A falling leaf. */
void func_801065BC_22D08C_HoneycombHavoc(f32 x, f32 y) {
    omObjData* obj;
    HCLeaf* work;

    obj = omAddObj(0x28, 1, 0, -1, func_801067F4_22D2C4_HoneycombHavoc);
    work = obj->unk_50 = func_80027154_27D54(sizeof(HCLeaf), 0x7918);
    obj->trans.x = x;
    obj->trans.y = y;
    obj->trans.z = -50.0f;
    work->period = 0xF;
    work->angle = 0.0f;
    if (rand8() & 1) {
        work->angle += 180.0f;
    }
    work->dx = HuMathSin(work->angle) * 8.0f;
    work->dy = -HuMathSin(work->angle / 2.0f) * 8.0f;
    work->timer = work->period + (u16)((u8)(rand8() % 7) - 3);
    work->dAngle = 180.0f / work->timer;
    work->amp = (u8)(rand8() % 7) + 8;
    work->fall = ((u8)(rand8() % 20) + 10) / 10.0f;
    obj->model[0] = func_80027D3C_2893C(D_801076B2_22E182_HoneycombHavoc);
    func_800298A4_2A4A4(obj->model[0], 4, 0);
}

void func_801067F4_22D2C4_HoneycombHavoc(omObjData* obj) {
    HCLeaf* work = obj->unk_50;

    obj->trans.x += work->dx;
    obj->trans.y = (work->dy - work->fall) + obj->trans.y;
    work->angle += work->dAngle;
    if (work->angle >= 360.0f) {
        work->angle -= 360.0f;
    }
    work->dx = HuMathSin(work->angle) * work->amp;
    work->dy = -HuMathSin(work->angle / 2.0f) * 8.0f;
    if (--work->timer == 0) {
        work->amp = (u8)(rand8() % 7) + 8;
        work->timer = work->period + (u16)((u8)(rand8() % 7) - 3);
        work->dAngle = 180.0f / work->timer;
    }
    if (obj->trans.y < -100.0f) {
        func_800283DC_28FDC(obj->model[0]);
        omDelObj(obj);
    }
}

/* The intro: countdown, the start message, then play (state 1). */
void func_801069C8_22D498_HoneycombHavoc(omObjData* obj) {
    switch (D_801076AA_22E17A_HoneycombHavoc) {
    case 0:
        if (D_801074D0_22DFA0_HoneycombHavoc-- == 0x10) {
            PlaySound(0x4A6);
        }
        break;
    case 1:
        func_800691FC_69DFC(0);
        D_801076AA_22E17A_HoneycombHavoc = 2;
        break;
    case 2:
        if (D_801074CC_22DF9C_HoneycombHavoc++ >= 0x3D) {
            PlayMusic(0x47);
            D_801076A8_22E178_HoneycombHavoc = 1;
            omDelObj(obj);
            D_801076FC_22E1CC_HoneycombHavoc = NULL;
            D_801076E4_22E1B4_HoneycombHavoc->work[0] = 1;
        }
        break;
    }
}

/* The ending: everyone faces front, the hats shrink away, the winner (D_801076AE) gets 10 coins
   and the win motion, then fade out and return. */
void func_80106AC4_22D594_HoneycombHavoc(omObjData* obj) {
    omObjData* p;
    HmfMotionObj* hook;
    omObjData* cam;
    s32 i;
    s32 n;

    switch (D_801076AC_22E17C_HoneycombHavoc) {
    case 0:
        func_800691FC_69DFC(3);
        D_801076AC_22E17C_HoneycombHavoc = 1;
        break;
    case 1:
        for (i = 0; i < 4; i++) {
            p = D_801076D8_22E1A8_HoneycombHavoc[i];
            func_80029BF0_2A7F0(p->model[0], func_80029E14_2AA14(p->motion[1]), 0, 2, 2);
        }
        D_801076AC_22E17C_HoneycombHavoc = 2;
        cam = omAddObj(0x28, 0, 0, -1, func_80107038_22DB08_HoneycombHavoc);
        D_801076F8_22E1C8_HoneycombHavoc = cam;
        cam->work[0] = 0;
        D_801076F8_22E1C8_HoneycombHavoc->work[0] = 1;
        D_801076F8_22E1C8_HoneycombHavoc->work[1] = 0;
        break;
    case 2:
        n = 0;
        for (i = 0; i < 4; i++) {
            p = D_801076D8_22E1A8_HoneycombHavoc[i];
            if (p->rot.y >= 360.0f) {
                p->rot.y -= 360.0f;
            } else if (p->rot.y < 0.0f) {
                p->rot.y += 360.0f;
            }
            if (p->rot.y > 0.0f) {
                p->rot.y -= 10.0f;
            }
            if (p->rot.y < 0.0f) {
                p->rot.y = 0.0f;
            }
            if (p->rot.y == 0.0f) {
                n++;
            }
        }
        if (n == 4) {
            for (i = 0; i < 4; i++) {
                p = D_801076D8_22E1A8_HoneycombHavoc[i];
                func_80029BF0_2A7F0(p->model[0], func_80029E14_2AA14(p->motion[0]), 0, 2, 2);
            }
            D_801076A4_22E174_HoneycombHavoc = 1.0f;
            D_801076AC_22E17C_HoneycombHavoc = 4;
        }
        break;
    case 4:
        for (i = 0; i < 4; i++) {
            p = D_801076D8_22E1A8_HoneycombHavoc[i];
            hook = func_8002A9F4_2B5F4(p->model[0], (char*)D_801074F0_22DFC0_HoneycombHavoc);
            hook->unk40.x = D_801076A4_22E174_HoneycombHavoc;
            hook->unk40.y = D_801076A4_22E174_HoneycombHavoc;
            hook->unk40.z = D_801076A4_22E174_HoneycombHavoc;
        }
        D_801076A4_22E174_HoneycombHavoc -= 0.06f;
        if (D_801076A4_22E174_HoneycombHavoc <= 0.1f) {
            for (i = 0; i < 4; i++) {
                p = D_801076D8_22E1A8_HoneycombHavoc[i];
                func_800298A4_2A4A4(p->model[2], 0x4000, 0);
                func_8002C570_2D170(p->model[0]);
                func_800298A4_2A4A4(p->model[2], 4, 4);
            }
            D_801076AC_22E17C_HoneycombHavoc = 5;
        }
        break;
    case 5:
        D_801076AC_22E17C_HoneycombHavoc = 6;
        break;
    case 6:
        for (i = 0; i < 4; i++) {
            p = D_801076D8_22E1A8_HoneycombHavoc[i];
            if (i == D_801076AE_22E17E_HoneycombHavoc) {
                gPlayers[i].coins_mg_bonus += 10;
                if (!_CheckFlag(0xC)) {
                    func_80029BF0_2A7F0(p->model[0], func_80029E14_2AA14(p->motion[4]), 0, 2, 0);
                    func_800732B0_73EB0(D_801076B8_22E188_HoneycombHavoc[((HCPlayer*)p->unk_50)->player]);
                }
            } else if (!_CheckFlag(0xC)) {
                func_80029BF0_2A7F0(p->model[0], func_80029E14_2AA14(p->motion[5]), 0, 2, 0);
            }
        }
        if (!_CheckFlag(0xC)) {
            D_801076AC_22E17C_HoneycombHavoc = 7;
            PlayMusic(0x51);
            D_801076A0_22E170_HoneycombHavoc = 1;
        } else {
            D_801076AC_22E17C_HoneycombHavoc = 8;
            D_801076A0_22E170_HoneycombHavoc = 0x1E;
        }
        break;
    case 7:
        if (--D_801076A0_22E170_HoneycombHavoc == 0) {
            func_800691FC_69DFC(6, gPlayers[D_801076AE_22E17E_HoneycombHavoc].character);
            D_801076A0_22E170_HoneycombHavoc = 0x5A;
            D_801076AC_22E17C_HoneycombHavoc = 8;
        }
        break;
    case 8:
        if (--D_801076A0_22E170_HoneycombHavoc == 0) {
            InitFadeOut(0, 0x14);
            D_801076AC_22E17C_HoneycombHavoc = 9;
            func_800794A8_7A0A8(0x28);
        }
        break;
    case 9:
        if (!func_8008F618_90218()) {
            omOvlReturnEx(1);
        }
        break;
    }
}

/* The ending camera: 30 frames toward the players. */
void func_80107038_22DB08_HoneycombHavoc(omObjData* obj) {
    Vec eye;
    Vec at;

    if (obj->work[0] != 1) {
        eye.x = obj->work[1] * -3.3333333f + 0.0f;
        eye.y = obj->work[1] * -3.0f + 410.0f;
        eye.z = obj->work[1] * -10.0f + 1200.0f;
        at.x = obj->work[1] * -3.3333333f + 0.0f;
        at.y = obj->work[1] * -3.0f + 400.0f;
        at.z = obj->work[1] * 0.0f + -100.0f;
        func_8007B818_7C418(&eye, &at, &D_800FA610_FB210, &D_800FD474_FE074, &D_8010274C_10334C);
        if (++obj->work[1] >= 0x1E) {
            obj->work[0] = 1;
        }
    }
}

void func_801071B4_22DC84_HoneycombHavoc(omObjData* obj) {
    if (!func_8008F618_90218()) {
        omOvlReturnEx(1);
    }
}

/* Quit: fade out and return when asked (D_801074E0) or on main's reset flag. */
void func_801071E0_22DCB0_HoneycombHavoc(omObjData* obj) {
    if (D_801074E0_22DFB0_HoneycombHavoc[0] != 0 || D_801011FC_101DFC != 0) {
        func_800794A8_7A0A8(0x28);
        InitFadeOut(0, 0x14);
        obj->func_ptr = func_801071B4_22DC84_HoneycombHavoc;
    }
}
