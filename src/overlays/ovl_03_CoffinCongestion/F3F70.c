#include "ovl_03.h"

/* .data (0xF7D10-0xF8410, 80106600-80106D00), all owned by this file. */

/* The room objects: 0-5 coffin bases, 6-11 lids, 12-17 lid fronts, 18-19 lamps, 20-24 item models
   (file set from the item at setup), 25 the host, 26 the sparkles. */
CCObjDef D_80106600_F7D10_CoffinCongestion[27] = {
    { { -400.0f, 0.0f, -250.0f }, 1.0f, 0x130000, 0x2A9, 0x1, 1, 0 },
    { { 0.0f, 0.0f, -250.0f }, 1.0f, 0x130000, 0x2A9, 0x1, 1, 0 },
    { { 400.0f, 0.0f, -250.0f }, 1.0f, 0x130000, 0x2A9, 0x1, 1, 0 },
    { { -400.0f, 0.0f, 250.0f }, 1.0f, 0x130000, 0x2A9, 0x1, 1, 0 },
    { { 0.0f, 0.0f, 250.0f }, 1.0f, 0x130000, 0x2A9, 0x1, 1, 0 },
    { { 400.0f, 0.0f, 250.0f }, 1.0f, 0x130000, 0x2A9, 0x1, 1, 0 },
    { { -400.0f, 0.0f, -250.0f }, 1.0f, 0x130001, 0xAA9, 0x2, 1, 0 },
    { { 0.0f, 0.0f, -250.0f }, 1.0f, 0x130001, 0xAA9, 0x2, 1, 0 },
    { { 400.0f, 0.0f, -250.0f }, 1.0f, 0x130001, 0xAA9, 0x2, 1, 0 },
    { { -400.0f, 0.0f, 250.0f }, 1.0f, 0x130001, 0xAA9, 0x2, 1, 0 },
    { { 0.0f, 0.0f, 250.0f }, 1.0f, 0x130001, 0xAA9, 0x2, 1, 0 },
    { { 400.0f, 0.0f, 250.0f }, 1.0f, 0x130001, 0xAA9, 0x2, 1, 0 },
    { { -400.0f, 0.0f, -250.0f }, 1.0f, 0x130002, 0x2A9, 0x3, 1, 0 },
    { { 0.0f, 0.0f, -250.0f }, 1.0f, 0x130002, 0x2A9, 0x3, 1, 0 },
    { { 400.0f, 0.0f, -250.0f }, 1.0f, 0x130002, 0x2A9, 0x3, 1, 0 },
    { { -400.0f, 0.0f, 250.0f }, 1.0f, 0x130002, 0x2A9, 0x3, 1, 0 },
    { { 0.0f, 0.0f, 250.0f }, 1.0f, 0x130002, 0x2A9, 0x3, 1, 0 },
    { { 400.0f, 0.0f, 250.0f }, 1.0f, 0x130002, 0x2A9, 0x3, 1, 0 },
    { { 314.993f, 239.367f, -471.552f }, 1.0f, 0x130003, 0x2A9, 0x4, 1, 0 },
    { { -314.993f, 239.367f, -471.552f }, 1.0f, 0x130003, 0x2A9, 0x4, 1, 0 },
    { { -400.0f, 0.0f, -250.0f }, 1.0f, 0x0, 0x6A9, 0x5, 1, 0 },
    { { 0.0f, 0.0f, -250.0f }, 1.0f, 0x0, 0x6A9, 0x5, 1, 0 },
    { { 400.0f, 0.0f, -250.0f }, 1.0f, 0x0, 0x6A9, 0x5, 1, 0 },
    { { -400.0f, 0.0f, 250.0f }, 1.0f, 0x0, 0x6A9, 0x5, 1, 0 },
    { { 0.0f, 0.0f, 250.0f }, 1.0f, 0x0, 0x6A9, 0x5, 1, 0 },
    { { 600.0f, 0.0f, 650.0f }, 0.9f, 0x13000F, 0x2B9, 0x6, 2, 5 },
    { { 0.0f, 1000.0f, 0.0f }, 1.0f, 0x1001F, 0x2B9, 0x7, 6, 0 },
};

/* Item model files, by item id. */
s32 D_801068F4_F8004_CoffinCongestion[10] = {
    0x130005, 0x130006, 0x130007, 0x130008, 0x130009, 0x13000A, 0x13000B, 0x13000C, 0x13000D,
    0x13000E,
};

CCMotion D_8010691C_F802C_CoffinCongestion[5] = {
    { 0x130010, 0, 0 }, { 0x130013, 0, 0 }, { 0x130011, 0, -1 }, { 0x130014, 0, -1 },
    { 0x130012, 0, 0 },
};

/* The six coffin slots. */
Vec D_80106944_F8054_CoffinCongestion[6] = {
    { -400.0f, 0.0f, -240.0f }, { 0.0f, 0.0f, -240.0f }, { 400.0f, 0.0f, -240.0f },
    { -400.0f, 0.0f, 260.0f }, { 0.0f, 0.0f, 260.0f }, { 400.0f, 0.0f, 260.0f },
};

/* Per-mode updates of the room objects, by kind (D_80106A0C). */
void (*D_8010698C_F809C_CoffinCongestion[8])(omObjData*, CCProp*) = {
    func_801029C0_F40D0_CoffinCongestion, NULL, NULL, func_80102A20_F4130_CoffinCongestion, NULL,
    NULL, func_80102B28_F4238_CoffinCongestion, NULL,
};

void (*D_801069AC_F80BC_CoffinCongestion[8])(omObjData*, CCProp*) = {
    func_80102C44_F4354_CoffinCongestion, func_80102C74_F4384_CoffinCongestion, NULL,
    func_80102C74_F4384_CoffinCongestion, func_80102E64_F4574_CoffinCongestion,
    func_80102EE0_F45F0_CoffinCongestion, func_80102F10_F4620_CoffinCongestion, NULL,
};

void (*D_801069CC_F80DC_CoffinCongestion[8])(omObjData*, CCProp*) = {
    NULL, func_801032B8_F49C8_CoffinCongestion, NULL, func_801032D8_F49E8_CoffinCongestion, NULL,
    NULL, func_80103578_F4C88_CoffinCongestion, NULL,
};

void (*D_801069EC_F80FC_CoffinCongestion[8])(omObjData*, CCProp*) = {
    NULL, func_80103938_F5048_CoffinCongestion, NULL, func_80103AB8_F51C8_CoffinCongestion, NULL,
    NULL, func_80103BD8_F52E8_CoffinCongestion, NULL,
};

void (*D_80106A0C_F811C_CoffinCongestion[9])(omObjData*) = {
    NULL, func_80102B90_F42A0_CoffinCongestion, func_80103080_F4790_CoffinCongestion,
    func_80103134_F4844_CoffinCongestion, func_801031AC_F48BC_CoffinCongestion,
    func_80103884_F4F94_CoffinCongestion, func_80103D50_F5460_CoffinCongestion,
    func_80103DE0_F54F0_CoffinCongestion, NULL,
};

Vec D_80106A30_F8140_CoffinCongestion = { 0.0f, 10.0f, 0.0f };

/* CPU walk targets: in front of each coffin slot, [6] the middle, [7] set at run time. */
CCCpuTarget D_80106A3C_F814C_CoffinCongestion[8] = {
    { { -400.0f, 0.0f, -70.0f }, 55.0f, 5 }, { { 0.0f, 0.0f, -70.0f }, 55.0f, 5 },
    { { 400.0f, 0.0f, -70.0f }, 55.0f, 5 }, { { -400.0f, 0.0f, 70.0f }, -55.0f, 5 },
    { { 0.0f, 0.0f, 70.0f }, -55.0f, 5 }, { { 400.0f, 0.0f, 70.0f }, -55.0f, 5 },
    { { 0.0f, 0.0f, 0.0f }, -55.0f, 10 }, { { 0.0f, 0.0f, 0.0f }, -55.0f, 0 },
};

/* By difficulty; [0] is the CPU wait. */
u8 D_80106ADC_F81EC_CoffinCongestion[4][4] = {
    { 12, 25, 6, 5 }, { 8, 30, 9, 8 }, { 6, 35, 5, 6 }, { 6, 40, 5, 6 },
};

CCMotionDef D_80106AEC_F81FC_CoffinCongestion[15] = {
    { 0x0, 0x0, 0x1, 0x0 }, { 0x1, 0x1, 0x1, 0x0 }, { 0x2, 0x2, 0x1, 0x0 }, { 0x3, 0x2C, 0x1, 0x0 },
    { 0x4, 0x2D, 0x1, 0x0 }, { 0x11, 0xF, 0x0, 0x0 }, { 0x20, 0x31, 0x0, 0x0 },
    { 0x5, 0x3, 0x0, 0x0 }, { 0x8, 0x6, 0x1, 0x1B }, { 0x6, 0x4, 0x1, 0x13 },
    { 0x15, 0x2E, 0x0, 0x0 }, { 0x12, 0x10, 0x0, 0x0 }, { 0xD, 0x54, 0x1, 0x78 },
    { 0xE, 0x55, 0x1, 0x78 }, { 0xF, 0x57, 0x1, 0x78 },
};

CCFile D_80106BA0_F82B0_CoffinCongestion[9] = {
    { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x0, 0x0 }, { 0x7, 0x28D }, { 0x8, 0x28D }, { 0x9, 0x68D },
    { 0x9, 0x28D }, { 0xB, 0x28D }, { 0xC, 0x28D },
};

void (*D_80106BE8_F82F8_CoffinCongestion[4])(omObjData*, MgWork*, CCCpu*) = {
    func_80104B60_F6270_CoffinCongestion, func_80104BA8_F62B8_CoffinCongestion,
    func_80104C30_F6340_CoffinCongestion, func_80104DD8_F64E8_CoffinCongestion,
};

void (*D_80106BF8_F8308_CoffinCongestion[10])(omObjData*, MgWork*, CCCpu*) = {
    NULL, NULL, NULL, NULL, func_80104E20_F6530_CoffinCongestion,
    func_80104E80_F6590_CoffinCongestion, func_80105074_F6784_CoffinCongestion, NULL, NULL, NULL,
};

CCCamera D_80106C20_F8330_CoffinCongestion[1] = {
    { { 0.0f, 3786.71509f, 2783.55493f }, { 0.0f, 312.5f, 100.0f }, 14.3330002f, { 640, 480, 640, 480 },
      { 0, 0, 320, 240 }, 0x130004, -1 },
};

CCLight D_80106C54_F8364_CoffinCongestion[2] = {
    { { 255, 255, 255 }, 0, { 100.0f, 100.0f, 50.0f } },
    { { 128, 255, 128 }, 0, { 100.0f, 100.0f, 50.0f } },
};

s16 D_80106C74_F8384_CoffinCongestion[6] = {
    10, 5, 10, 50, 5, 20,
};

s16 D_80106C80_F8390_CoffinCongestion[6] = {
    1, 0, 0, 0, 3, 0,
};

s32 D_80106C8C_F839C_CoffinCongestion = 0;

s16 D_80106C90_F83A0_CoffinCongestion[5][6] = {
    { 3, 8, 3, 8, 15, 4 }, { 2, 6, 2, 8, 10, 4 }, { 2, 4, 2, 8, 5, 4 }, { 1, 2, 1, 8, 2, 4 },
    { 1, 1, 1, 8, 1, 4 },
};

s16 D_80106CCC_F83DC_CoffinCongestion[6] = {
    0, 2, 0, 1, 0, 3,
};

void (*D_80106CD8_F83E8_CoffinCongestion[10])(omObjData*) = {
    func_80105884_F6F94_CoffinCongestion, func_801059A8_F70B8_CoffinCongestion,
    func_80105A98_F71A8_CoffinCongestion, func_80105AB4_F71C4_CoffinCongestion,
    func_80105C6C_F737C_CoffinCongestion, func_80105CF0_F7400_CoffinCongestion,
    func_80105D44_F7454_CoffinCongestion, func_80105EE0_F75F0_CoffinCongestion, NULL, NULL,
};

/* Starts host motion `mot` on the object (looping when its speed is negative); 1 if it changed. */
s32 func_80102860_F3F70_CoffinCongestion(omObjData* obj, s32 mot) {
    CCProp* p = obj->unk_50;

    if (p->unk_1C != mot) {
        p->unk_1C = mot;
        if (D_8010691C_F802C_CoffinCongestion[mot].speed < 0) {
            func_80029BF0_2A7F0(obj->model[0], obj->motion[mot], 0, 5, 0);
            return 1;
        }
        func_80029BF0_2A7F0(obj->model[0], obj->motion[mot], 0, 5, 2);
        func_80029FBC_2ABBC(obj->model[0], D_8010691C_F802C_CoffinCongestion[mot].speed);
        return 1;
    }
    return 0;
}

/* Puts coffin `p` in the next slot and moves `pos` there. */
void func_80102944_F4054_CoffinCongestion(CCProp* p, Vec* pos) {
    s32* idx = &D_80106DB8_F84C8_CoffinCongestion.idx;

    if (++*idx >= 6) {
        *idx -= 6;
    }
    D_80106DB8_F84C8_CoffinCongestion.slot[D_80106DB8_F84C8_CoffinCongestion.idx] = p;
    func_800B3170_B3D70(pos, &D_80106944_F8054_CoffinCongestion[D_80106DB8_F84C8_CoffinCongestion.idx]);
}

void func_801029C0_F40D0_CoffinCongestion(omObjData* obj, CCProp* p) {
    if (p->unk_18++ >= 46) {
        if (p->unk_0E < 6) {
            PlaySound(0x134);
        }
        p->unk_0E += 6;
    }
}

void func_80102A20_F4130_CoffinCongestion(omObjData* obj, CCProp* p) {
    f32 x;

    if (D_80106DB8_F84C8_CoffinCongestion.cur == 2) {
        x = (f32)((u8)(rand8() % 10) - 5) + p->pos.x;
        omSetTra(obj, x, p->pos.y, (f32)((u8)(rand8() % 10) - 5) + p->pos.z);
    } else {
        omSetTra(obj, p->pos.x, p->pos.y, p->pos.z);
    }
}

void func_80102B28_F4238_CoffinCongestion(omObjData* obj, CCProp* p) {
    if (p->unk_10 == 0) {
        if (p->unk_1A++ >= 61) {
            p->unk_1A = 0;
            p->unk_10++;
            PlaySound(0x138);
        }
    } else {
        p->unk_0E -= 6;
    }
}

/* Room object update: the per-mode hook of D_8010698C, then the alpha. */
void func_80102B90_F42A0_CoffinCongestion(omObjData* obj) {
    CCProp* p = ((CCGround*)obj->unk_50)->unk_B0;

    if (D_8010698C_F809C_CoffinCongestion[func_80106570_F7C80_CoffinCongestion()] != NULL) {
        D_8010698C_F809C_CoffinCongestion[func_80106570_F7C80_CoffinCongestion()](obj, p);
    }
    if (p->unk_0E < 0) {
        p->unk_0E = 0;
    }
    if (p->unk_0E >= 256) {
        p->unk_0E = 255;
    }
    func_8002D0A0_2DCA0(obj->model[0], p->unk_0E);
}

void func_80102C44_F4354_CoffinCongestion(omObjData* obj, CCProp* p) {
    if (p->unk_18++ >= 46) {
        p->unk_0E += 6;
    }
}

/* A coffin lid: down (1), shaking (2), up (3). */
void func_80102C74_F4384_CoffinCongestion(omObjData* obj, CCProp* p) {
    f32 x;

    switch (D_80106DB8_F84C8_CoffinCongestion.cur) {
        case 1:
            if (D_80106DB8_F84C8_CoffinCongestion.cur != D_80106DB8_F84C8_CoffinCongestion.prev) {
                PlaySound(0x135);
            }
            obj->trans.x -= 15.0f;
            if (obj->trans.x < p->pos.x - 150.0f) {
                obj->trans.x = p->pos.x - 150.0f;
            }
            break;
        case 2:
            if (D_80106DB8_F84C8_CoffinCongestion.cur != D_80106DB8_F84C8_CoffinCongestion.prev) {
                PlaySound(0x137);
            }
            x = (f32)((u8)(rand8() % 10) - 5) + p->pos.x;
            omSetTra(obj, x, p->pos.y, (f32)((u8)(rand8() % 10) - 5) + p->pos.z);
            break;
        case 3:
            if (D_80106DB8_F84C8_CoffinCongestion.cur != D_80106DB8_F84C8_CoffinCongestion.prev) {
                PlaySound(0x136);
            }
            obj->trans.x += 30.0f;
            if (p->pos.x < obj->trans.x) {
                obj->trans.x = p->pos.x;
            }
            break;
    }
}

/* The opened coffin: the player gets its item. */
void func_80102E64_F4574_CoffinCongestion(omObjData* obj, CCProp* p) {
    if (p->unk_1E == 1) {
        PlaySound(0x135);
        omVibrate(((MgWork*)p->unk_14->unk_50)->unk_59, 10, 0, 10);
        func_801065C0_F7CD0_CoffinCongestion(((MgWork*)p->unk_14->unk_50)->unk_59,
                                             D_80106DB8_F84C8_CoffinCongestion.slot[p->unk_0C - 6]->unk_12);
    }
}

void func_80102EE0_F45F0_CoffinCongestion(omObjData* obj, CCProp* p) {
    if (p->unk_1E == 1) {
        p->unk_0E -= 6;
        if (p->unk_0E < 0) {
            p->unk_0E = 0;
        }
    }
}

void func_80102F10_F4620_CoffinCongestion(omObjData* obj, CCProp* p) {
    if (p->unk_1E == 1) {
        p->unk_0E -= 6;
        if (p->unk_0E < 0) {
            p->unk_0E = 0;
        }
        return;
    }
    switch (p->unk_10) {
        case 0:
            if (p->unk_1A++ >= 31) {
                p->unk_1A = 0;
                if (func_801065EC_F7CFC_CoffinCongestion() < 0) {
                    p->unk_10 = 2;
                } else {
                    p->unk_10++;
                    PlaySound(0x135);
                }
            }
            break;
        case 1:
            obj->trans.x -= 15.0f;
            if (obj->trans.x < p->pos.x - 150.0f) {
                obj->trans.x = p->pos.x - 150.0f;
                p->unk_10++;
            }
            p->unk_1A++;
            break;
        case 2:
            if (p->unk_1A++ >= 31) {
                p->unk_1A = 0;
                p->unk_10++;
            }
            break;
        default:
            p->unk_0E -= 6;
            break;
    }
}

void func_80103080_F4790_CoffinCongestion(omObjData* obj) {
    CCProp* p = ((CCGround*)obj->unk_50)->unk_B0;

    if (D_801069AC_F80BC_CoffinCongestion[func_80106570_F7C80_CoffinCongestion()] != NULL) {
        D_801069AC_F80BC_CoffinCongestion[func_80106570_F7C80_CoffinCongestion()](obj, p);
    }
    if (p->unk_0E < 0) {
        p->unk_0E = 0;
    }
    if (p->unk_0E >= 256) {
        p->unk_0E = 255;
    }
    func_8002D0A0_2DCA0(obj->model[0], p->unk_0E);
}

/* An item model: follows the coffin six objects before it. */
void func_80103134_F4844_CoffinCongestion(omObjData* obj) {
    CCProp* p = ((CCGround*)obj->unk_50)->unk_B0;
    omObjData* coffin = D_80106DB0_F84C0_CoffinCongestion[p->unk_0C - 6];

    p->unk_0E = ((CCGround*)coffin->unk_50)->unk_B0->unk_0E;
    omSetTra(obj, coffin->trans.x, -3.0f, coffin->trans.z);
    func_8002D0A0_2DCA0(obj->model[0], p->unk_0E);
}

void func_801031AC_F48BC_CoffinCongestion(omObjData* obj) {
    CCProp* p = ((CCGround*)obj->unk_50)->unk_B0;

    obj->trans.x = (f32)((u8)(rand8() % 100) - 50) * 0.05f + p->pos.x;
    obj->trans.z = (f32)((u8)(rand8() % 100) - 50) * 0.05f + p->pos.z;
    func_8002D0A0_2DCA0(obj->model[0], rand8() & 0x3F);
}

void func_801032B8_F49C8_CoffinCongestion(omObjData* obj, CCProp* p) {
    if (p->unk_10 != 0) {
        p->unk_0E += 6;
    }
}

void func_801032D8_F49E8_CoffinCongestion(omObjData* obj, CCProp* p) {
    if (D_80106DB8_F84C8_CoffinCongestion.cur != 2) {
        p->unk_1A = 1;
    } else if (p->unk_1A == 1) {
        func_80102944_F4054_CoffinCongestion(p, &p->pos);
        omSetTra(obj, p->pos.x, p->pos.y, p->pos.z);
        p->unk_1A = 0;
    }
}

/* Smoke puff update: fades out, then frees its slot. */
void func_80103350_F4A60_CoffinCongestion(omObjData* obj) {
    CCProp* p = obj->unk_50;

    p->unk_0E -= 6;
    if (p->unk_0E < 0) {
        p->unk_0E = 0;
        p->unk_0C = 0;
    }
    func_8002D0A0_2DCA0(obj->model[0], p->unk_0E);
}

/* Creates the six smoke puffs (item model `item`) once. */
void func_80103398_F4AA8_CoffinCongestion(s32 item) {
    omObjData*** puffs = &D_80106DB4_F84C4_CoffinCongestion;
    omObjData* obj;
    CCProp* p;
    s32 i;

    if (*puffs == NULL) {
        func_80076BD0_777D0(2, 6);
        *puffs = func_80076D80_77980(2);
        for (i = 0; i < 6; i++) {
            obj = D_80106DB4_F84C4_CoffinCongestion[i] = omAddObj(4, 1, 0, 2, func_80103350_F4A60_CoffinCongestion);
            p = func_80027154_27D54(sizeof(CCProp), 0x7918);
            func_800B0EF0_B1AF0(p, 0, sizeof(CCProp));
            obj->unk_50 = p;
            obj->model[0] = func_80018A30_19630(D_801068F4_F8004_CoffinCongestion[item], 0x2A9);
            func_8002D124_2DD24(obj->model[0]);
            func_8002D0A0_2DCA0(obj->model[0], 0);
        }
    }
}

/* A free smoke puff, or NULL. */
omObjData* func_801034B0_F4BC0_CoffinCongestion(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        if (((CCProp*)D_80106DB4_F84C4_CoffinCongestion[i]->unk_50)->unk_0C == 0) {
            return D_80106DB4_F84C4_CoffinCongestion[i];
        }
    }
    return NULL;
}

void func_801034F8_F4C08_CoffinCongestion(f32 x, f32 y, f32 z) {
    omObjData* obj = func_801034B0_F4BC0_CoffinCongestion();
    CCProp* p;

    if (obj != NULL) {
        omSetTra(obj, x, y, z);
        p = obj->unk_50;
        p->unk_0E = 192;
        p->unk_0C = 1;
    }
}

/* The host (the boo that hides the items): rises (1), bobs and lays smoke (2), floats back to
   the middle (3), bobs (4). */
void func_80103578_F4C88_CoffinCongestion(omObjData* obj, CCProp* p) {
    Vec v;
    CCProp* q;

    if (p->unk_18++ >= 30) {
        if (p->unk_1E == 0) {
            p->unk_0E -= 6;
            return;
        }
        switch (p->unk_1C) {
            case 0:
                q = ((CCGround*)D_80106DB0_F84C0_CoffinCongestion[26]->unk_50)->unk_B0;
                q->unk_14 = obj;
                if (q->unk_10 == 0) {
                    q->unk_10++;
                }
                func_80103398_F4AA8_CoffinCongestion(p->unk_12);
                p->unk_1C++;
                break;
            case 1:
                obj->trans.y += 10.0f;
                if (obj->trans.y > 300.0f) {
                    p->unk_20 = obj->trans.y;
                    goto next;
                }
                goto puff;
            case 2:
                obj->trans.y = HuMathSin(p->unk_24) * 30.0f + p->unk_20;
                p->unk_24 += 12.0f;
                if (p->unk_24 > 360.0f) {
                    p->unk_24 -= 360.0f;
                }
                if (p->unk_18 >= 91) {
                    PlaySound(0x12E);
                    goto next;
                }
                goto puff;
            case 3:
                HuVecCopyXYZ(&v, -obj->trans.x, 0.0f, -obj->trans.z);
                if (HuVecGetLength3F(&v) > 16.0f) {
                    func_8010609C_F77AC_CoffinCongestion(&v);
                    HuVecMulScalar(&v, 16.0f, &v);
                    omSetTra(obj, obj->trans.x + v.x, obj->trans.y + v.y, obj->trans.z + v.z);
                    goto puff;
                }
            next:
                p->unk_1C++;
            puff:
                if ((s16)(p->unk_1A++ % 5) == 0) {
                    func_801034F8_F4C08_CoffinCongestion(obj->trans.x, obj->trans.y, obj->trans.z);
                }
                break;
            case 4:
                obj->trans.y = HuMathSin(p->unk_24) * 30.0f + p->unk_20;
                p->unk_24 += 12.0f;
                if (p->unk_24 > 360.0f) {
                    p->unk_24 -= 360.0f;
                }
                break;
        }
    }
}

void func_80103884_F4F94_CoffinCongestion(omObjData* obj) {
    CCProp* p = ((CCGround*)obj->unk_50)->unk_B0;

    if (D_801069CC_F80DC_CoffinCongestion[func_80106570_F7C80_CoffinCongestion()] != NULL) {
        D_801069CC_F80DC_CoffinCongestion[func_80106570_F7C80_CoffinCongestion()](obj, p);
    }
    if (p->unk_0E < 0) {
        p->unk_0E = 0;
    }
    if (p->unk_0E >= 256) {
        p->unk_0E = 255;
    }
    func_8002D0A0_2DCA0(obj->model[0], p->unk_0E);
}

/* The host's entrance: walks in (1), hops over (2), turns to face the player (3). */
void func_80103938_F5048_CoffinCongestion(omObjData* obj, CCProp* p) {
    switch (p->unk_10) {
        case 0:
        case 4:
            break;
        case 1:
            func_80102860_F3F70_CoffinCongestion(obj, 1);
            obj->rot.y = 180.0f;
            obj->trans.z -= 25.0f;
            if (obj->trans.z < 210.0f) {
                obj->rot.y = -90.0f;
                p->unk_20 = -10.0f;
                p->unk_10++;
            }
            break;
        case 2:
            func_80102860_F3F70_CoffinCongestion(obj, 2);
            obj->trans.x -= 8.6f;
            obj->trans.y = 200.0f - p->unk_20 * p->unk_20 * 2.2f;
            p->unk_20 += 1.0f;
            if (p->unk_20 > 10.0f) {
                obj->rot.y = -45.0f;
                p->unk_10++;
            }
            break;
        case 3:
            obj->rot.y = 0.0f;
            func_80102860_F3F70_CoffinCongestion(obj, 3);
            p->unk_10++;
            break;
    }
}

/* A coffin during the shuffle: picks a new slot while the lids are up, moves there on the
   shake. */
void func_80103AB8_F51C8_CoffinCongestion(omObjData* obj, CCProp* p) {
    if (D_80106DB8_F84C8_CoffinCongestion.cur != 2) {
        if (p->unk_18 == 0) {
            D_80106DB8_F84C8_CoffinCongestion.idx += (u8)(rand8() % 3) + 1;
            if (D_80106DB8_F84C8_CoffinCongestion.idx >= 6) {
                D_80106DB8_F84C8_CoffinCongestion.idx -= 6;
            }
            p->unk_18 = 1;
        }
    } else if (p->unk_18 == 1) {
        func_80102944_F4054_CoffinCongestion(p, &p->pos);
        if (p->pos.z < 0.0f) {
            p->pos.z = -290.0f;
        } else {
            p->pos.z = 210.0f;
        }
        omSetTra(obj, p->pos.x, p->pos.y, p->pos.z);
        p->unk_18 = 0;
    }
}

/* The host after the pick: cheers (opened) or leaves. */
void func_80103BD8_F52E8_CoffinCongestion(omObjData* obj, CCProp* p) {
    if (p->unk_1E == 1) {
        if (p->unk_10++ >= 120) {
            if (p->unk_10 == 121) {
                PlaySound(0x13C);
            }
            func_80102860_F3F70_CoffinCongestion(obj, 4);
        }
    } else if (p->unk_10++ >= 94) {
        switch (p->unk_1A) {
            case 0:
                func_80102860_F3F70_CoffinCongestion(obj, 1);
                if (obj->trans.x < func_801055EC_F6CFC_CoffinCongestion()) {
                    p->unk_20 = -5.0f;
                } else {
                    p->unk_20 = 5.0f;
                }
                p->unk_1A++;
                break;
            case 1:
                obj->trans.x += p->unk_20;
                p->unk_20 *= 0.98f;
                obj->trans.z += 10.0f;
                if (obj->trans.z > 1000.0f) {
                    p->unk_1A++;
                }
                break;
        }
    }
}

void func_80103D50_F5460_CoffinCongestion(omObjData* obj) {
    if (D_801069EC_F80FC_CoffinCongestion[func_80106570_F7C80_CoffinCongestion()] != NULL) {
        D_801069EC_F80FC_CoffinCongestion[func_80106570_F7C80_CoffinCongestion()](obj, ((CCGround*)obj->unk_50)->unk_B0);
    }
    func_80029714_2A314(obj->model[1], obj->trans.x, 3.0f, obj->trans.z);
}

/* Sparkles over the player who opened the coffin. */
void func_80103DE0_F54F0_CoffinCongestion(omObjData* obj) {
    CCProp* p = ((CCGround*)obj->unk_50)->unk_B0;

    switch (p->unk_10) {
        case 1:
            omSetTra(obj, p->unk_14->trans.x, p->unk_14->trans.y, p->unk_14->trans.z);
            func_80029714_2A314(obj->model[p->unk_18], p->unk_14->trans.x, p->unk_14->trans.y + 180.0f,
                                p->unk_14->trans.z);
            func_80029FE4_2ABE4(obj->model[p->unk_18], (u8)(rand8() % 50) * 0.1f + 1.0f);
            func_800298A4_2A4A4(obj->model[p->unk_18], 4, 0);
            if (++p->unk_18 >= 6) {
                p->unk_18 -= 6;
            }
            p->unk_10++;
            break;
        case 2:
        case 3:
            p->unk_10++;
            break;
        case 4:
            p->unk_10 = 1;
            break;
    }
}

/* Creates the 27 room objects (D_80106600); 20-24 are the coffins' item models, 25 the host,
   26 the sparkles. */
void func_80103F88_F5698_CoffinCongestion(void) {
    omObjData* obj;
    CCGround* ground;
    CCProp* p;
    s32 i;
    s32 j;

    func_80076BD0_777D0(1, 27);
    D_80106DB0_F84C0_CoffinCongestion = func_80076D80_77980(1);
    D_800F8FE0_F9BE0 = 0;
    for (i = 0; i < 27; i++) {
        obj = omAddObj(3, D_80106600_F7D10_CoffinCongestion[i].unk_1A, D_80106600_F7D10_CoffinCongestion[i].unk_1B, 1,
                       D_80106A0C_F811C_CoffinCongestion[D_80106600_F7D10_CoffinCongestion[i].func]);
        D_80106DB0_F84C0_CoffinCongestion[i] = obj;
        ground = func_80027154_27D54(sizeof(CCGround), 0x7918);
        func_800B0EF0_B1AF0(ground, 0, sizeof(CCGround));
        ground->unk_03 = 1;
        ground->unk_08 = 0.5f;
        ground->unk_10 = 20.0f;
        ground->unk_04 = i;
        obj->unk_50 = ground;
        D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = obj;
        p = func_80027154_27D54(sizeof(CCProp), 0x7918);
        func_800B0EF0_B1AF0(p, 0, sizeof(CCProp));
        ground->unk_B0 = p;
        if (i >= 20 && i < 25) {
            p->unk_12 = D_800CAFD8[i - 20];
            D_80106600_F7D10_CoffinCongestion[i].file = D_801068F4_F8004_CoffinCongestion[p->unk_12];
        } else {
            p->unk_12 = -1;
        }
        obj->model[0] = func_80018A30_19630(D_80106600_F7D10_CoffinCongestion[i].file, D_80106600_F7D10_CoffinCongestion[i].attr);
        if (D_80106600_F7D10_CoffinCongestion[i].attr == 0x2A9 || D_80106600_F7D10_CoffinCongestion[i].attr == 0x6A9
            || D_80106600_F7D10_CoffinCongestion[i].attr == 0xAA9) {
            func_8002D124_2DD24(obj->model[0]);
            func_8002D0A0_2DCA0(obj->model[0], 0);
        }
        omSetTra(obj, D_80106600_F7D10_CoffinCongestion[i].pos.x, D_80106600_F7D10_CoffinCongestion[i].pos.y,
                 D_80106600_F7D10_CoffinCongestion[i].pos.z);
        omSetSca(obj, D_80106600_F7D10_CoffinCongestion[i].scale, D_80106600_F7D10_CoffinCongestion[i].scale,
                 D_80106600_F7D10_CoffinCongestion[i].scale);
        func_800B3170_B3D70(&p->pos, &D_80106600_F7D10_CoffinCongestion[i].pos);
        p->unk_0C = i;
        if (i == 26) {
            omSetSca(obj, 1.2f, 1.2f, 0.0f);
            for (j = 1; j < 6; j++) {
                obj->model[j] = func_80018A30_19630(D_80106600_F7D10_CoffinCongestion[i].file, D_80106600_F7D10_CoffinCongestion[i].attr);
                func_800297E8_2A3E8(obj->model[j], 1.2f, 1.2f, 0.0f);
            }
            for (j = 0; j < 6; j++) {
                func_80029FE4_2ABE4(obj->model[j], 0.0f);
                func_80029E80_2AA80(obj->model[j], 2, 2);
                func_800298A4_2A4A4(obj->model[j], 4, 4);
            }
        }
        if (i == 25) {
            obj->model[1] = func_80018A64_19664(13, 0x2B9);
            func_80029714_2A314(obj->model[1], D_801068BC_F7FCC_CoffinCongestion, D_801068C0_F7FD0_CoffinCongestion,
                                D_801068C4_F7FD4_CoffinCongestion);
            func_800297E8_2A3E8(obj->model[1], D_801068C8_F7FD8_CoffinCongestion, D_801068C8_F7FD8_CoffinCongestion,
                                D_801068C8_F7FD8_CoffinCongestion);
            for (j = 0; j < 5; j++) {
                obj->motion[j] = func_8002C8B8_2D4B8(DataRead(D_8010691C_F802C_CoffinCongestion[j].file), 0x18);
                if (obj->motion[j] < 0) {
                    while (1) {}
                }
                D_8010691C_F802C_CoffinCongestion[j].len = func_8002CA14_2D614(obj->motion[j]);
            }
            func_80102860_F3F70_CoffinCongestion(obj, 0);
            p->unk_12 = 10;
        }
    }
    func_8000C018_CC18(0);
    func_8000BF24_CB24(D_80106DB0_F84C0_CoffinCongestion[0], 3.0f, -650.0f, -450.0f, 650.0f, 450.0f);
}

void func_80104478_F5B88_CoffinCongestion(void) {
    func_8002D4D0_2E0D0(0x25);
    func_8002F290_2FE90(D_800F9D30_FA930, 0xC0);
    func_80103F88_F5698_CoffinCongestion();
    D_80106DB4_F84C4_CoffinCongestion = NULL;
    func_8002CA48_2D648(0, 0, 0);
    func_80029708_2A308(1);
}

void func_801044CC_F5BDC_CoffinCongestion(void) {
    s32 i;

    for (i = 0; i < 27; i++) {
        omDelObj(func_80076D98_77998(1, i));
    }
    if (D_80106DB4_F84C4_CoffinCongestion != NULL) {
        for (i = 0; i < 6; i++) {
            omDelObj(func_80076D98_77998(2, i));
        }
        D_80106DB4_F84C4_CoffinCongestion = NULL;
    }
    func_8002F1A4_2FDA4();
    func_8002CA48_2D648(0, 0, 0);
    func_80029708_2A308(1);
}

void func_80104570_F5C80_CoffinCongestion(omObjData* obj) {
    s32 i;

    for (i = 0; i < 27; i++) {
        func_8000C024_CC24(obj, i, 1);
    }
    for (i = 6; i < 12; i++) {
        func_8000C024_CC24(obj, i, 2);
    }
    func_8000C024_CC24(obj, 0, 2);
}

void func_801045E8_F5CF8_CoffinCongestion(s16 phase) {
    D_80106DB8_F84C8_CoffinCongestion.prev = D_80106DB8_F84C8_CoffinCongestion.cur;
    D_80106DB8_F84C8_CoffinCongestion.cur = phase;
}

/* Starts the item models' hops (objects 20-24). */
void func_80104600_F5D10_CoffinCongestion(void) {
    s32 i;

    for (i = 20; i < 25; i++) {
        s16* state = &((CCGround*)D_80106DB0_F84C0_CoffinCongestion[i]->unk_50)->unk_B0->unk_10;

        if (*state == 0) {
            (*state)++;
        }
    }
}

/* Starts the host's entrance (object 25). */
void func_80104650_F5D60_CoffinCongestion(void) {
    CCProp* p = ((CCGround*)D_80106DB0_F84C0_CoffinCongestion[25]->unk_50)->unk_B0;

    if (p->unk_10 == 0) {
        p->unk_10++;
    }
}

/* The slot holding `item`, or -1. */
s32 func_80104684_F5D94_CoffinCongestion(s32 item) {
    s32 i;

    for (i = 0; i < 6; i++) {
        if (D_80106DB8_F84C8_CoffinCongestion.slot[i]->unk_12 == item) {
            return i;
        }
    }
    return -1;
}

/* The slot a CPU player opens: the boo's (item 10) by difficulty (30/20/10/5%), else an item
   drawn by main's chances (D_800CAFE4). */
s32 func_801046C8_F5DD8_CoffinCongestion(s32 player) {
    s32 r;
    s32 slot;
    s32 i;
    s32 sum;

    r = (u8)(rand8() % 100);
    slot = func_80104684_F5D94_CoffinCongestion(10);
    if (slot < 0) {
        while (1) {}
    }
    switch (gPlayers[player].cpu_difficulty) {
        case 0:
            if (r < 30) {
                return slot;
            }
            break;
        case 1:
            if (r < 20) {
                return slot;
            }
            break;
        case 2:
            if (r < 10) {
                return slot;
            }
            break;
        case 3:
            if (r < 5) {
                return slot;
            }
            break;
    }
    r = (u8)(rand8() % 100);
    sum = 0;
    for (i = 0; i < 5; i++) {
        sum += D_800CAFE4[i];
        if (r < sum) {
            break;
        }
    }
    slot = func_80104684_F5D94_CoffinCongestion(D_800CAFD8[i]);
    if (slot < 0) {
        while (1) {}
    }
    return slot;
}

/* Bumped into room object `other`: the player bounces back. */
void func_80104878_F5F88_CoffinCongestion(omObjData* obj, omObjData* other) {
    MgWork* work = obj->unk_50;

    func_80019B9C_1A79C(obj, 6);
    if (other->trans.x < obj->trans.x) {
        D_80106DB8_F84C8_CoffinCongestion.stickX = 60.0f;
        work->unk_3C = 90.0f;
    } else {
        D_80106DB8_F84C8_CoffinCongestion.stickX = -60.0f;
        work->unk_3C = -90.0f;
    }
    ((MgWork*)obj->unk_50)->unk_38 = -D_800BF7A4_C03A4 * 0.4f;
    func_800191D4_19DD4(obj, 5, obj->trans.x, obj->trans.y + 15.0f, obj->trans.z, 90.0f, 0.0f);
    func_80106534_F7C44_CoffinCongestion(((MgWork*)obj->unk_50)->unk_57, 0, 0, 0, 0);
}

/* Player touch hook 3 (a room object): bounce off anything but the floor. */
s32 func_8010499C_F60AC_CoffinCongestion(omObjData* obj, CCGround* ground) {
    if (ground->unk_04 != 0) {
        func_80104878_F5F88_CoffinCongestion(obj, D_80106DB0_F84C0_CoffinCongestion[ground->unk_04]);
        D_80106DB8_F84C8_CoffinCongestion.touched = ground->unk_04;
        return 1;
    }
    D_80106DB8_F84C8_CoffinCongestion.touched = 0;
    return 0;
}

/* Player touch hook 6: in the pick mode, touching a coffin opens it. */
s32 func_801049FC_F610C_CoffinCongestion(omObjData* obj, CCGround* ground) {
    CCProp* p;

    func_8010499C_F60AC_CoffinCongestion(obj, ground);
    if (func_80106570_F7C80_CoffinCongestion() == 4 && ground->unk_04 != 0) {
        p = ground->unk_B0;
        D_80106DB8_F84C8_CoffinCongestion.slot[p->unk_0C - 6]->unk_1E = p->unk_1E = 1;
        p->unk_14 = obj;
    }
    return 0;
}

/* Player hook 0: keeps the knock-back stick while bouncing. */
s32 func_80104A7C_F618C_CoffinCongestion(omObjData* obj) {
    if (D_80106DB8_F84C8_CoffinCongestion.touched > 0) {
        func_80106534_F7C44_CoffinCongestion(((MgWork*)obj->unk_50)->unk_57, D_80106DB8_F84C8_CoffinCongestion.stickX, 0, 0, 0);
    }
    return 0;
}

/* Player hook 1: in the pick mode, landing on a coffin opens it. */
s32 func_80104AD4_F61E4_CoffinCongestion(omObjData* obj) {
    MgWork* work = obj->unk_50;
    CCProp* p;

    if (func_80106570_F7C80_CoffinCongestion() == 4) {
        if ((s8)work->unk_55 > 0) {
            p = ((CCGround*)D_80106DB0_F84C0_CoffinCongestion[(s8)work->unk_55]->unk_50)->unk_B0;
            D_80106DB8_F84C8_CoffinCongestion.slot[p->unk_0C - 6]->unk_1E = p->unk_1E = 1;
            p->unk_14 = obj;
        }
        return 0;
    }
    return 0;
}

/* CPU action 0: wait. */
void func_80104B60_F6270_CoffinCongestion(omObjData* obj, MgWork* work, CCCpu* cpu) {
    if (cpu->unk_08-- < 0) {
        cpu->unk_00 = 1;
    }
    func_80106534_F7C44_CoffinCongestion(work->unk_57, 0, 0, 0, 0);
}

/* CPU action 1: choose a coffin (or stop once there). */
void func_80104BA8_F62B8_CoffinCongestion(omObjData* obj, MgWork* work, CCCpu* cpu) {
    if (cpu->unk_02 & 1) {
        cpu->unk_00 = 3;
    } else {
        cpu->unk_04 = &D_80106A3C_F814C_CoffinCongestion[func_801046C8_F5DD8_CoffinCongestion(work->unk_59)];
        cpu->unk_00 = 2;
    }
    func_80106534_F7C44_CoffinCongestion(work->unk_57, 0, 0, 0, 0);
}

/* CPU action 2: walk to the target. */
void func_80104C30_F6340_CoffinCongestion(omObjData* obj, MgWork* work, CCCpu* cpu) {
    Vec stick;
    Vec pos;
    Vec d;
    f32 len;
    f32 speed;

    HuVecCopyXYZ(&pos, obj->trans.x, cpu->unk_04->pos.y, obj->trans.z);
    HuVecSubtract(&d, &cpu->unk_04->pos, &pos);
    len = HuVecGetLength3F(&d);
    if (len < 55.0f) {
        if (cpu->unk_08-- < -cpu->unk_04->unk_10) {
            cpu->unk_02 |= 1;
            cpu->unk_00 = 0;
            cpu->unk_08 = D_80106ADC_F81EC_CoffinCongestion[cpu->unk_0A][0];
        }
        HuVecCopyXYZ(&stick, 0.0f, 0.0f, cpu->unk_04->unk_0C);
    } else {
        speed = (len < 110.0f) ? 35.0f : 55.0f;
        d.z = -d.z;
        func_8010609C_F77AC_CoffinCongestion(&d);
        HuVecMulScalar(&stick, speed, &d);
    }
    func_80106534_F7C44_CoffinCongestion(work->unk_57, stick.x, stick.z, 0, 0);
}

/* CPU action 3: press A. */
void func_80104DD8_F64E8_CoffinCongestion(omObjData* obj, MgWork* work, CCCpu* cpu) {
    cpu->unk_00 = 0;
    cpu->unk_08 = D_80106ADC_F81EC_CoffinCongestion[cpu->unk_0A][0];
    func_80106534_F7C44_CoffinCongestion(work->unk_57, 0, 0, 0x4000, 0);
}

void func_80104E20_F6530_CoffinCongestion(omObjData* obj, MgWork* work, CCCpu* cpu) {
    if (gPlayers[work->unk_59].flags & 1) {
        D_80106BE8_F82F8_CoffinCongestion[cpu->unk_00](obj, work, cpu);
    }
}

/* The player in the pick mode (CPU plan in the 10-13 states). */
#ifdef NON_MATCHING
/* Retail shares one jal between case 10's two HuVecCopyXYZ calls (cross-jumped); this
   compiles them as two calls. Logic equal. */
void func_80104E80_F6590_CoffinCongestion(omObjData* obj, MgWork* work, CCCpu* cpu) {
    switch (cpu->unk_0C) {
        case 0:
            if (work->unk_53 != 0) {
                break;
            }
            goto next;
        case 1:
            if (func_801065EC_F7CFC_CoffinCongestion() < 0) {
                goto next;
            }
            if (obj->trans.z > -70.0f && obj->trans.z < 70.0f) {
                cpu->unk_0C = 12;
            } else {
                cpu->unk_0C = 10;
            }
            break;
        case 2:
            if (cpu->unk_0E++ >= 6) {
                func_8010657C_F7C8C_CoffinCongestion(6);
            }
            func_80106534_F7C44_CoffinCongestion(work->unk_57, 0, -50, 0, 0);
            break;
        case 10:
            cpu->unk_00 = 2;
            cpu->unk_08 = 0;
            cpu->unk_04 = &D_80106A3C_F814C_CoffinCongestion[7];
            if (obj->trans.z < 0.0f) {
                HuVecCopyXYZ(&cpu->unk_04->pos, obj->trans.x, 0.0f, -70.0f);
            } else {
                HuVecCopyXYZ(&cpu->unk_04->pos, obj->trans.x, 0.0f, 70.0f);
            }
            goto next;
        case 11:
            func_80104C30_F6340_CoffinCongestion(obj, work, cpu);
            if (cpu->unk_00 != 0) {
                break;
            }
            goto next;
        case 12:
            cpu->unk_00 = 2;
            cpu->unk_08 = 0;
            cpu->unk_04 = &D_80106A3C_F814C_CoffinCongestion[6];
        next:
            cpu->unk_0C++;
            break;
        case 13:
            func_80104C30_F6340_CoffinCongestion(obj, work, cpu);
            if (cpu->unk_00 == 0) {
                func_8010657C_F7C8C_CoffinCongestion(6);
            }
            break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_03_CoffinCongestion/F3F70", func_80104E80_F6590_CoffinCongestion);
#endif

/* The player in the result mode: waits, then cheers or slumps. */
void func_80105074_F6784_CoffinCongestion(omObjData* obj, MgWork* work, CCCpu* cpu) {
    switch (cpu->unk_10) {
        case 0:
            if (cpu->unk_12++ >= 121) {
                cpu->unk_10++;
            }
            break;
        case 1:
            if (func_801065EC_F7CFC_CoffinCongestion() == 3) {
                func_80019B9C_1A79C(obj, 15);
                func_800732B0_73EB0(D_800CD438_CE038[cpu->unk_09].unk_04 | 0x57);
            } else if (func_801065EC_F7CFC_CoffinCongestion() < 0 || func_801065EC_F7CFC_CoffinCongestion() == 10) {
                func_80019B9C_1A79C(obj, 14);
                func_800732B0_73EB0(D_800CD438_CE038[cpu->unk_09].unk_04 | 0x55);
            } else {
                func_80019B9C_1A79C(obj, 13);
                func_800732B0_73EB0(D_800CD438_CE038[cpu->unk_09].unk_04 | 0x54);
            }
            cpu->unk_10++;
            break;
    }
}

/* Player object update. */
void func_801051C0_F68D0_CoffinCongestion(omObjData* obj) {
    MgWork* work = obj->unk_50;

    if (D_80106BF8_F8308_CoffinCongestion[func_80106570_F7C80_CoffinCongestion()] != NULL) {
        D_80106BF8_F8308_CoffinCongestion[func_80106570_F7C80_CoffinCongestion()](obj, work, work->unk_158);
    }
    func_80007790_8390(obj);
}

/* Sets up the player object for `player`. */
void func_8010524C_F695C_CoffinCongestion(omObjData* obj, s32 player) {
    s8 chr;
    s32 dir;
    s32 file;
    s32 i;
    MgWork* work;
    CCCpu* cpu;

    chr = gPlayers[player].character;
    dir = D_800CD438_CE038[chr].unk_04;
    file = D_800CD438_CE038[chr].unk_08;
    func_8000C578_D178(1);
    func_8000C6FC_D2FC(obj, dir, file, player, 0x299, 0x299);
    for (i = 2; i < 9; i++) {
        if (D_80106BA0_F82B0_CoffinCongestion[i].file != 0) {
            obj->model[i] = LoadFormFile(D_80106BA0_F82B0_CoffinCongestion[i].file, D_80106BA0_F82B0_CoffinCongestion[i].attr);
        }
    }
    for (i = 0; i < 15; i++) {
        func_80019F0C_1AB0C(obj, D_80106AEC_F81FC_CoffinCongestion[i].slot, dir | D_80106AEC_F81FC_CoffinCongestion[i].file,
                            D_80106AEC_F81FC_CoffinCongestion[i].unk_08, D_80106AEC_F81FC_CoffinCongestion[i].unk_0A);
    }
    func_80104570_F5C80_CoffinCongestion(obj);
    omSetTra(obj, D_80106A30_F8140_CoffinCongestion.x, D_80106A30_F8140_CoffinCongestion.y, D_80106A30_F8140_CoffinCongestion.z);
    work = obj->unk_50;
    func_8000E0C0_ECC0(work, 6, func_801049FC_F610C_CoffinCongestion);
    func_8000E0C0_ECC0(work, 1, func_80104AD4_F61E4_CoffinCongestion);
    func_8000E0C0_ECC0(work, 3, func_8010499C_F60AC_CoffinCongestion);
    func_8000E0C0_ECC0(work, 0, func_80104A7C_F618C_CoffinCongestion);
    cpu = func_80027154_27D54(sizeof(CCCpu), 0x7918);
    if (cpu == NULL) {
        while (1) {}
    }
    func_800B0EF0_B1AF0(cpu, 0, sizeof(CCCpu));
    work->unk_158 = cpu;
    switch (gPlayers[player].cpu_difficulty) {
        case 0:
            cpu->unk_0A = 0;
            break;
        case 1:
            cpu->unk_0A = 1;
            break;
        case 2:
            cpu->unk_0A = 2;
            break;
        case 3:
            cpu->unk_0A = 3;
            break;
    }
    cpu->unk_09 = chr;
}

/* Creates the player object for the first player in group 0. */
void func_801054C4_F6BD4_CoffinCongestion(void) {
    s32 i;

    func_8000C460_D060();
    func_80076BD0_777D0(0, 1);
    D_80106DE0_F84F0_CoffinCongestion[0] = func_80076D80_77980(0);
    D_800FC87A_FD47A = 0;
    for (i = 0; i < 4; i++) {
        if (gPlayers[i].group == 0) {
            break;
        }
    }
    D_80106DE0_F84F0_CoffinCongestion[0][0] = omAddObj(2, 9, 0x26, 0, NULL);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = D_80106DE0_F84F0_CoffinCongestion[0][0];
    func_8010524C_F695C_CoffinCongestion(D_80106DE0_F84F0_CoffinCongestion[0][0], i);
    D_80106DE0_F84F0_CoffinCongestion[0][0]->func_ptr = func_801051C0_F68D0_CoffinCongestion;
}

void func_801055C4_F6CD4_CoffinCongestion(void) {
    omDelObj(func_80076D98_77998(0, 0));
}

f32 func_801055EC_F6CFC_CoffinCongestion(void) {
    return D_80106DE0_F84F0_CoffinCongestion[0][0]->trans.x;
}

void func_80105600_F6D10_CoffinCongestion(void) {
    D_80106DF0_F8500_CoffinCongestion.mode = 0;
    D_80106DF0_F8500_CoffinCongestion.next = 0;
    D_80106DF0_F8500_CoffinCongestion.step = 0;
    D_80106DF0_F8500_CoffinCongestion.timer = 0;
    func_8000C3B8_CFB8();
    func_8000C3C8_CFC8();
}

/* Creates camera `idx`'s sprite from its file; returns the sprite's slot field 4. */
u16 func_80105638_F6D48_CoffinCongestion(s32 file, u32 idx) {
    if (idx >= 2) {
        while (1) {}
    }
    D_80106C20_F8330_CoffinCongestion[idx].spr = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(file), 0, 0);
    if (D_80106C20_F8330_CoffinCongestion[idx].spr == -1) {
        while (1) {}
    }
    espDispOff(D_80106C20_F8330_CoffinCongestion[idx].spr);
    return ((u16*)((u8*)D_800F93FC_F9FFC + D_80106C20_F8330_CoffinCongestion[idx].spr * 0x24))[2];
}

/* Saves the controller state. */
void func_80105710_F6E20_CoffinCongestion(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_80106E04_F8514_CoffinCongestion[i].stkX = ContStkX[i];
        D_80106E04_F8514_CoffinCongestion[i].stkY = ContStkY[i];
        D_80106E04_F8514_CoffinCongestion[i].btn = ContBtn[i];
        D_80106E04_F8514_CoffinCongestion[i].trg = ContBtnTrg[i];
    }
}

/* Restores it. */
void func_801057A0_F6EB0_CoffinCongestion(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        ContStkX[i] = D_80106E04_F8514_CoffinCongestion[i].stkX;
        ContStkY[i] = D_80106E04_F8514_CoffinCongestion[i].stkY;
        ContBtn[i] = D_80106E04_F8514_CoffinCongestion[i].btn;
        ContBtnTrg[i] = D_80106E04_F8514_CoffinCongestion[i].trg;
    }
}

/* Clears it (the players move only through func_80106534). */
void func_80105830_F6F40_CoffinCongestion(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        ContStkX[i] = ContStkY[i] = 0;
        ContBtnTrg[i] = ContBtn[i] = 0;
    }
}

/* Mode 0: fade in, music. */
void func_80105884_F6F94_CoffinCongestion(omObjData* obj) {
    switch (D_80106DF0_F8500_CoffinCongestion.step) {
        case 0:
            D_80106DF0_F8500_CoffinCongestion.unk_08 = 0;
            D_80106DF0_F8500_CoffinCongestion.time = 300;
            D_80106DF0_F8500_CoffinCongestion.frames = 0;
            D_80106DF0_F8500_CoffinCongestion.step = 1;
            D_80106DF0_F8500_CoffinCongestion.item = -1;
            D_80106DF0_F8500_CoffinCongestion.player = -1;
            gPlayers[0].coins_mg_bonus = -1;
            gPlayers[1].coins_mg_bonus = -1;
            gPlayers[2].coins_mg_bonus = -1;
            gPlayers[3].coins_mg_bonus = -1;
            InitFadeIn(0, 16);
            PlayMusic(0x28);
            break;
        case 1:
            if (func_8008F618_90218() == 0) {
                D_80106DF0_F8500_CoffinCongestion.timer = 76;
                D_80106DF0_F8500_CoffinCongestion.step++;
            }
            break;
        case 2:
            if (D_80106DF0_F8500_CoffinCongestion.timer-- < 0) {
                D_80106DF0_F8500_CoffinCongestion.step++;
            }
            break;
        case 3:
            func_8000C38C_CF8C();
            func_8010657C_F7C8C_CoffinCongestion(1);
            D_80106DF0_F8500_CoffinCongestion.timer = 0;
            break;
    }
}

/* Mode 1: the items show, hop into the coffins, the host comes in. */
void func_801059A8_F70B8_CoffinCongestion(omObjData* obj) {
    switch (D_80106DF0_F8500_CoffinCongestion.step) {
        case 0 ... 6:
            func_801045E8_F5CF8_CoffinCongestion(D_80106C80_F8390_CoffinCongestion[D_80106DF0_F8500_CoffinCongestion.step]);
            if (D_80106DF0_F8500_CoffinCongestion.step == 2) {
                func_80104600_F5D10_CoffinCongestion();
            } else if (D_80106DF0_F8500_CoffinCongestion.step == 3) {
                func_80104650_F5D60_CoffinCongestion();
            }
            if (D_80106DF0_F8500_CoffinCongestion.timer++ > D_80106C74_F8384_CoffinCongestion[D_80106DF0_F8500_CoffinCongestion.step]) {
                D_80106DF0_F8500_CoffinCongestion.timer = 0;
                D_80106DF0_F8500_CoffinCongestion.step++;
            }
            break;
        case 7:
            func_8010657C_F7C8C_CoffinCongestion(2);
            break;
    }
}

void func_80105A98_F71A8_CoffinCongestion(omObjData* obj) {
    func_8010657C_F7C8C_CoffinCongestion(3);
}

/* Mode 3: five rounds of lids down, shake (the coffins swap slots), lids up. */
void func_80105AB4_F71C4_CoffinCongestion(omObjData* obj) {
    switch (D_80106DF0_F8500_CoffinCongestion.step) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            func_801045E8_F5CF8_CoffinCongestion(D_80106CCC_F83DC_CoffinCongestion[D_80106DF0_F8500_CoffinCongestion.step]);
            if (D_80106DF0_F8500_CoffinCongestion.timer++
                > D_80106C90_F83A0_CoffinCongestion[D_80106C8C_F839C_CoffinCongestion][D_80106DF0_F8500_CoffinCongestion.step]) {
                D_80106DF0_F8500_CoffinCongestion.timer = 0;
                D_80106DF0_F8500_CoffinCongestion.step++;
            }
            break;
        case 5:
            func_801045E8_F5CF8_CoffinCongestion(D_80106CCC_F83DC_CoffinCongestion[D_80106DF0_F8500_CoffinCongestion.step]);
            if (D_80106DF0_F8500_CoffinCongestion.timer++
                > D_80106C90_F83A0_CoffinCongestion[D_80106C8C_F839C_CoffinCongestion][D_80106DF0_F8500_CoffinCongestion.step]) {
                D_80106DF0_F8500_CoffinCongestion.timer = 0;
                D_80106C8C_F839C_CoffinCongestion++;
                if (D_80106C8C_F839C_CoffinCongestion < 5) {
                    D_80106DF0_F8500_CoffinCongestion.step = 0;
                    break;
                }
                func_80079868_7A468();
                goto next;
            }
            break;
        case 6:
            func_800691FC_69DFC(0);
            goto next;
        case 7:
            if (func_80069538_6A138() != 0) {
                break;
            }
        next:
            D_80106DF0_F8500_CoffinCongestion.step++;
            break;
        case 8:
            func_800691FC_69DFC(10, 10, 160, 32);
            func_8010657C_F7C8C_CoffinCongestion(4);
            break;
    }
}

/* Mode 4: the pick, against the clock. */
void func_80105C6C_F737C_CoffinCongestion(omObjData* obj) {
    D_80106DF0_F8500_CoffinCongestion.time--;
    func_8006D4D0_6E0D0(D_80106DF0_F8500_CoffinCongestion.time / 30 + 1);
    if (D_80106DF0_F8500_CoffinCongestion.time < 0) {
        func_8006D4D0_6E0D0(0);
        func_8010657C_F7C8C_CoffinCongestion(5);
    }
}

/* Mode 5: time up / picked. */
void func_80105CF0_F7400_CoffinCongestion(omObjData* obj) {
    if (D_80106DF0_F8500_CoffinCongestion.step == 0) {
        func_800691FC_69DFC(3);
        func_8006D518_6E118();
        D_80106DF0_F8500_CoffinCongestion.step++;
        func_800794A8_7A0A8(60);
    }
}

/* Mode 6: result message and music; writes gPlayers[].coins_mg_bonus (the item, -1 none). */
void func_80105D44_F7454_CoffinCongestion(omObjData* obj) {
    switch (D_80106DF0_F8500_CoffinCongestion.step) {
        case 0:
            D_80106DF0_F8500_CoffinCongestion.timer = 120;
            D_80106DF0_F8500_CoffinCongestion.step++;
            break;
        case 2:
            if (D_80106DF0_F8500_CoffinCongestion.item < 0 || D_80106DF0_F8500_CoffinCongestion.item == 10) {
                PlayMusic(0x56);
                func_800691FC_69DFC(0x10);
                D_80106DF0_F8500_CoffinCongestion.timer = 0x84;
            } else if (D_80106DF0_F8500_CoffinCongestion.item != 3) {
                PlayMusic(0x53);
                func_800691FC_69DFC(0x17, D_80106DF0_F8500_CoffinCongestion.item);
                D_80106DF0_F8500_CoffinCongestion.timer = 0x87;
            } else {
                PlayMusic(0x54);
                func_800691FC_69DFC(0x18, D_80106DF0_F8500_CoffinCongestion.item);
                D_80106DF0_F8500_CoffinCongestion.timer = 0x90;
            }
            D_80106DF0_F8500_CoffinCongestion.step++;
            break;
        case 1:
        case 3:
            if (--D_80106DF0_F8500_CoffinCongestion.timer == -1) {
                D_80106DF0_F8500_CoffinCongestion.step++;
            }
            break;
        case 4:
            if (D_80106DF0_F8500_CoffinCongestion.item >= 0) {
                if (D_80106DF0_F8500_CoffinCongestion.item == 10) {
                    D_80106DF0_F8500_CoffinCongestion.item = -1;
                }
                gPlayers[D_80106DF0_F8500_CoffinCongestion.player].coins_mg_bonus = D_80106DF0_F8500_CoffinCongestion.item;
            }
            func_8010657C_F7C8C_CoffinCongestion(7);
            D_80106DF0_F8500_CoffinCongestion.step = 0;
            break;
    }
}

/* Mode 7: fade out and leave. */
void func_80105EE0_F75F0_CoffinCongestion(omObjData* obj) {
    switch (D_80106DF0_F8500_CoffinCongestion.step) {
        case 0:
            func_800794A8_7A0A8(40);
            InitFadeOut(0, 20);
            D_80106DF0_F8500_CoffinCongestion.step++;
            break;
        case 1:
            if (func_8008F618_90218() == 0) {
                D_80106DF0_F8500_CoffinCongestion.step++;
            }
            break;
        case 2:
            func_801055C4_F6CD4_CoffinCongestion();
            func_801044CC_F5BDC_CoffinCongestion();
            func_8002864C_2924C();
            func_80023124_23D24();
            omOvlReturnEx(1);
            break;
    }
}

/* Flow object: runs the current mode. */
void func_80105F9C_F76AC_CoffinCongestion(omObjData* obj) {
    if (D_801011FC_101DFC == 1 && D_80106DF0_F8500_CoffinCongestion.mode != 7) {
        func_8010657C_F7C8C_CoffinCongestion(7);
    }
    D_80106DF0_F8500_CoffinCongestion.mode = D_80106DF0_F8500_CoffinCongestion.next;
    if (D_80106DF0_F8500_CoffinCongestion.mode != 4) {
        func_80105710_F6E20_CoffinCongestion();
        func_80105830_F6F40_CoffinCongestion();
    }
    if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        D_80106CD8_F83E8_CoffinCongestion[D_80106DF0_F8500_CoffinCongestion.mode](obj);
    }
    D_80106DF0_F8500_CoffinCongestion.frames++;
}

/* Late object: gives the players their pads back. */
void func_8010606C_F777C_CoffinCongestion(omObjData* obj) {
    if (D_80106DF0_F8500_CoffinCongestion.mode != 4) {
        func_801057A0_F6EB0_CoffinCongestion();
    }
}

void func_8010609C_F77AC_CoffinCongestion(Vec* v) {
    if (!(HuVecGetLength3F(v) < 0.1f)) {
        func_800B33E0_B3FE0(v);
    }
}

void func_801060E8_F77F8_CoffinCongestion(void) {
    omInitObjMan(50, 0);
    func_80079128_79D28();
    func_80105600_F6D10_CoffinCongestion();
}

/* The camera: viewport, scissor, perspective and its sprite. */
void func_80106118_F7828_CoffinCongestion(void) {
    s32 pad[2];
    s32 i;
    u8 cam;

    func_80018E30_19A30(1);
    for (i = 0; i <= 0; i++) {
        cam = func_80018E78_19A78();
        ScissorSet(cam, D_80106C20_F8330_CoffinCongestion[i].sc[0], D_80106C20_F8330_CoffinCongestion[i].sc[1],
                   D_80106C20_F8330_CoffinCongestion[i].sc[2], D_80106C20_F8330_CoffinCongestion[i].sc[3]);
        ViewportSet(cam, D_80106C20_F8330_CoffinCongestion[i].vp[0], D_80106C20_F8330_CoffinCongestion[i].vp[1], 511.0f,
                    D_80106C20_F8330_CoffinCongestion[i].vp[2], D_80106C20_F8330_CoffinCongestion[i].vp[3], 511.0f);
    }
    D_80101078_101C78 = 6000.0f;
    D_800F8410_F9010 = 1500.0f;
    func_8007A27C_7AE7C(0x7FDA, (s16)func_80105638_F6D48_CoffinCongestion(D_80106C20_F8330_CoffinCongestion[0].file, 0),
                        func_8007A7FC_7B3FC, D_80106C20_F8330_CoffinCongestion[0].fov, &D_80106C20_F8330_CoffinCongestion[0].eye,
                        &D_80106C20_F8330_CoffinCongestion[0].at);
    Hu3DCamSetPerspective(0, D_80106C20_F8330_CoffinCongestion[0].fov, 3500.0f, 5000.0f);
}

void func_80106314_F7A24_CoffinCongestion(void) {
    s32 i;
    s16 l;

    func_80026D28_27928(2);
    for (i = 0; i < 2; i++) {
        l = i;
        func_80026E00_27A00(l, D_80106C54_F8364_CoffinCongestion[i].dir[0], D_80106C54_F8364_CoffinCongestion[i].dir[1],
                            D_80106C54_F8364_CoffinCongestion[i].dir[2]);
        func_80026DAC_279AC(l, (u8)D_80106C54_F8364_CoffinCongestion[i].col[0], (u8)D_80106C54_F8364_CoffinCongestion[i].col[1],
                            (u8)D_80106C54_F8364_CoffinCongestion[i].col[2]);
    }
}

void func_801064C8_F7BD8_CoffinCongestion(void) {
    omSetStatBit(omAddObj(0, 0, 0, -1, func_80105F9C_F76AC_CoffinCongestion), 0xA0);
    omSetStatBit(omAddObj(5, 0, 0, -1, func_8010606C_F777C_CoffinCongestion), 0xA0);
}

/* Drives port `port` as if from its controller. */
void func_80106534_F7C44_CoffinCongestion(s32 port, s8 stkX, s8 stkY, u16 trg, u16 btn) {
    ContStkX[port] = stkX;
    ContStkY[port] = stkY;
    ContBtn[port] = btn;
    ContBtnTrg[port] = trg;
}

u16 func_80106570_F7C80_CoffinCongestion(void) {
    return D_80106DF0_F8500_CoffinCongestion.mode;
}

void func_8010657C_F7C8C_CoffinCongestion(u16 mode) {
    if (mode >= 8) {
        while (1) {}
    }
    D_80106DF0_F8500_CoffinCongestion.next = mode;
    D_80106DF0_F8500_CoffinCongestion.step = 0;
}

s32 func_801065A8_F7CB8_CoffinCongestion(void) {
    return D_80106DF0_F8500_CoffinCongestion.frames;
}

s16 func_801065B4_F7CC4_CoffinCongestion(void) {
    return D_80106DF0_F8500_CoffinCongestion.unk_08;
}

/* Ends the pick: `player` won `item`. */
void func_801065C0_F7CD0_CoffinCongestion(s16 player, s16 item) {
    D_80106DF0_F8500_CoffinCongestion.item = item;
    D_80106DF0_F8500_CoffinCongestion.player = player;
    func_8010657C_F7C8C_CoffinCongestion(5);
}

s16 func_801065EC_F7CFC_CoffinCongestion(void) {
    return D_80106DF0_F8500_CoffinCongestion.item;
}

__asm__(".section .rodata\n\t.balign 16\n\t.text");
