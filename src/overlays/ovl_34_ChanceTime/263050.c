#include "common.h"
#include "ovl_34.h"

/* .data (0x267260-0x2672C0): block spin state and speeds, the chosen players, reel faces */
/* The reel's face names, in this unit's .rodata below. */
extern const char D_80110680_267780_ChanceTime[];
extern const char D_8011068C_26778C_ChanceTime[];
extern const char D_80110698_267798_ChanceTime[];
extern const char D_801106A4_2677A4_ChanceTime[];
s8 D_80110160_267260_ChanceTime[3] = {
    0, 0, 0,
};
s16 D_80110164_267264_ChanceTime[3] = {
    0, 0, 0,
};
s16 D_8011016C_26726C_ChanceTime[3] = {
    0, 0, 0,
};
s8 D_80110172_267272_ChanceTime = 0;
f32 D_80110174_267274_ChanceTime[2] = {
    10.0f, 18.0f,
};
f32 D_8011017C_26727C_ChanceTime = 30.0f;
u8 D_80110180_267280_ChanceTime = 0xFF;
u8 D_80110181_267281_ChanceTime = 0xFF;
u8 D_80110182_267282_ChanceTime = 0xFF;
char* D_80110184_267284_ChanceTime[4] = {
    D_801106A4_2677A4_ChanceTime, D_80110698_267798_ChanceTime,
    D_8011068C_26778C_ChanceTime, D_80110680_267780_ChanceTime,
};
s16 D_80110194_267294_ChanceTime = 0;
s16 D_80110198_267298_ChanceTime[3] = {
    0, 0, 0,
};
s16 D_801101A0_2672A0_ChanceTime[3] = {
    0, 0, 0,
};
s16 D_801101A8_2672A8_ChanceTime[3] = {
    0, 0, 0,
};
s8 D_801101B0_2672B0_ChanceTime[3] = {
    0, 0, 0,
};
s8 D_801101B4_2672B4_ChanceTime[3] = {
    0, 0, 0,
};
s8 D_801101B8_2672B8_ChanceTime[3] = {
    0, 0, 0,
};
s8 D_801101BC_2672BC_ChanceTime[3] = {
    0, 0, 0,
};

void func_8010BF50_263050_ChanceTime(void) {
    D_8011092C_267A2C_ChanceTime = func_80018A64_19664(0x440001, 0x28D);
}

void func_8010BF7C_26307C_ChanceTime(omObjData* obj) {
    func_8010C44C_26354C_ChanceTime(obj, 0);
}

void func_8010BF98_263098_ChanceTime(omObjData* obj) {
    func_8010CCF4_263DF4_ChanceTime(obj, 0);
}

void func_8010BFB4_2630B4_ChanceTime(omObjData* obj) {
    func_8010CCF4_263DF4_ChanceTime(obj, 1);
}

void func_8010BFD0_2630D0_ChanceTime(omObjData* obj) {
    func_8010C44C_26354C_ChanceTime(obj, 1);
}

void func_8010BFEC_2630EC_ChanceTime(omObjData* obj) {
    func_8010CCF4_263DF4_ChanceTime(obj, 2);
}

void func_8010C008_263108_ChanceTime(omObjData* obj) {
    func_8010C44C_26354C_ChanceTime(obj, 2);
}

void func_8010C024_263124_ChanceTime(omObjData* obj) {
    if ((s16)func_8010DFF8_2650F8_ChanceTime(obj, 80.0f, D_800FFFD8_100BD8[0]) != 0 &&
        D_80110194_267294_ChanceTime == 0) {
        D_80110194_267294_ChanceTime = 1;
    }
    D_80110150_267250_ChanceTime[2] = 1;
    D_80110181_267281_ChanceTime = 0;
}

void func_8010C080_263180_ChanceTime(omObjData* obj) {
    func_8010C44C_26354C_ChanceTime(obj, 3);
}

/* Fills the six outcome tables the block reel draws from (first variant: 20 entries, early /
   middle / late game; second variant: 10). */
void func_8010C09C_26319C_ChanceTime(void) {
    D_80110930_267A30_ChanceTime[0] = 0;
    D_80110930_267A30_ChanceTime[1] = 1;
    D_80110930_267A30_ChanceTime[2] = 2;
    D_80110930_267A30_ChanceTime[3] = 2;
    D_80110930_267A30_ChanceTime[4] = 3;
    D_80110930_267A30_ChanceTime[5] = 3;
    D_80110930_267A30_ChanceTime[6] = 4;
    D_80110930_267A30_ChanceTime[7] = 5;
    D_80110930_267A30_ChanceTime[8] = 6;
    D_80110930_267A30_ChanceTime[9] = 7;
    D_80110930_267A30_ChanceTime[10] = 8;
    D_80110930_267A30_ChanceTime[11] = 9;
    D_80110930_267A30_ChanceTime[12] = 2;
    D_80110930_267A30_ChanceTime[13] = 3;
    D_80110930_267A30_ChanceTime[14] = 4;
    D_80110930_267A30_ChanceTime[15] = 5;
    D_80110930_267A30_ChanceTime[16] = 6;
    D_80110930_267A30_ChanceTime[17] = 7;
    D_80110930_267A30_ChanceTime[18] = 9;
    D_80110930_267A30_ChanceTime[19] = 9;
    D_80110948_267A48_ChanceTime[0] = 2;
    D_80110948_267A48_ChanceTime[1] = 2;
    D_80110948_267A48_ChanceTime[2] = 3;
    D_80110948_267A48_ChanceTime[3] = 3;
    D_80110948_267A48_ChanceTime[4] = 4;
    D_80110948_267A48_ChanceTime[5] = 4;
    D_80110948_267A48_ChanceTime[6] = 5;
    D_80110948_267A48_ChanceTime[7] = 5;
    D_80110948_267A48_ChanceTime[8] = 6;
    D_80110948_267A48_ChanceTime[9] = 7;
    D_80110948_267A48_ChanceTime[10] = 8;
    D_80110948_267A48_ChanceTime[11] = 9;
    D_80110948_267A48_ChanceTime[12] = 10;
    D_80110948_267A48_ChanceTime[13] = 4;
    D_80110948_267A48_ChanceTime[14] = 5;
    D_80110948_267A48_ChanceTime[15] = 6;
    D_80110948_267A48_ChanceTime[16] = 7;
    D_80110948_267A48_ChanceTime[17] = 8;
    D_80110948_267A48_ChanceTime[18] = 9;
    D_80110948_267A48_ChanceTime[19] = 9;
    D_80110960_267A60_ChanceTime[0] = 2;
    D_80110960_267A60_ChanceTime[1] = 3;
    D_80110960_267A60_ChanceTime[2] = 4;
    D_80110960_267A60_ChanceTime[3] = 4;
    D_80110960_267A60_ChanceTime[4] = 5;
    D_80110960_267A60_ChanceTime[5] = 5;
    D_80110960_267A60_ChanceTime[6] = 6;
    D_80110960_267A60_ChanceTime[7] = 7;
    D_80110960_267A60_ChanceTime[8] = 8;
    D_80110960_267A60_ChanceTime[9] = 8;
    D_80110960_267A60_ChanceTime[10] = 9;
    D_80110960_267A60_ChanceTime[11] = 9;
    D_80110960_267A60_ChanceTime[12] = 10;
    D_80110960_267A60_ChanceTime[13] = 4;
    D_80110960_267A60_ChanceTime[14] = 5;
    D_80110960_267A60_ChanceTime[15] = 6;
    D_80110960_267A60_ChanceTime[16] = 7;
    D_80110960_267A60_ChanceTime[17] = 8;
    D_80110960_267A60_ChanceTime[18] = 9;
    D_80110960_267A60_ChanceTime[19] = 10;
    D_80110978_267A78_ChanceTime[0] = 0;
    D_80110978_267A78_ChanceTime[1] = 11;
    D_80110978_267A78_ChanceTime[2] = 2;
    D_80110978_267A78_ChanceTime[3] = 4;
    D_80110978_267A78_ChanceTime[4] = 0;
    D_80110978_267A78_ChanceTime[5] = 11;
    D_80110978_267A78_ChanceTime[6] = 2;
    D_80110978_267A78_ChanceTime[7] = 4;
    D_80110978_267A78_ChanceTime[8] = 11;
    D_80110978_267A78_ChanceTime[9] = 2;
    D_80110990_267A90_ChanceTime[0] = 0;
    D_80110990_267A90_ChanceTime[1] = 11;
    D_80110990_267A90_ChanceTime[2] = 2;
    D_80110990_267A90_ChanceTime[3] = 4;
    D_80110990_267A90_ChanceTime[4] = 12;
    D_80110990_267A90_ChanceTime[5] = 11;
    D_80110990_267A90_ChanceTime[6] = 2;
    D_80110990_267A90_ChanceTime[7] = 4;
    D_80110990_267A90_ChanceTime[8] = 2;
    D_80110990_267A90_ChanceTime[9] = 4;
    D_801109A8_267AA8_ChanceTime[0] = 11;
    D_801109A8_267AA8_ChanceTime[1] = 2;
    D_801109A8_267AA8_ChanceTime[2] = 4;
    D_801109A8_267AA8_ChanceTime[3] = 12;
    D_801109A8_267AA8_ChanceTime[4] = 2;
    D_801109A8_267AA8_ChanceTime[5] = 4;
    D_801109A8_267AA8_ChanceTime[6] = 12;
    D_801109A8_267AA8_ChanceTime[7] = 2;
    D_801109A8_267AA8_ChanceTime[8] = 4;
    D_801109A8_267AA8_ChanceTime[9] = 12;
}

s8* func_8010C268_263368_ChanceTime(omObjData* player) {
    s16 stage;
    s32 rank;

    stage = 0;
    switch (GwSystem.current_game_length) {
    case 0:
        if (GwSystem.current_turn < 6) {
            stage = 0;
        } else if (GwSystem.current_turn < 16) {
            stage = 1;
        } else {
            stage = 2;
        }
        break;
    case 1:
        if (GwSystem.current_turn < 11) {
            stage = 0;
        } else if (GwSystem.current_turn < 21) {
            stage = 1;
        } else {
            stage = 2;
        }
        break;
    case 2:
        if (GwSystem.current_turn < 16) {
            stage = 0;
        } else if (GwSystem.current_turn < 36) {
            stage = 1;
        } else {
            stage = 2;
        }
        break;
    }
    rank = func_80059FD0_5ABD0(CT_PWORK(D_800FFFD8_100BD8[0])->unk_59);
    switch (stage) {
    case 0:
        if (D_80110060_267160_ChanceTime != 0) {
            return D_80110978_267A78_ChanceTime;
        }
        return D_80110930_267A30_ChanceTime;
    case 1:
        if (D_80110060_267160_ChanceTime != 0) {
            if (rank == 1) {
                return D_801109A8_267AA8_ChanceTime;
            }
            if (rank == 4) {
                return D_80110978_267A78_ChanceTime;
            }
            return D_80110990_267A90_ChanceTime;
        }
        if (rank == 1) {
            return D_80110930_267A30_ChanceTime;
        }
        return D_80110948_267A48_ChanceTime;
    case 2:
        if (D_80110060_267160_ChanceTime != 0) {
            if (rank < 3) {
                return D_801109A8_267AA8_ChanceTime;
            }
            return D_80110990_267A90_ChanceTime;
        }
        return D_80110960_267A60_ChanceTime;
    default:
        if (D_80110060_267160_ChanceTime != 0) {
            return D_80110990_267A90_ChanceTime;
        }
        return D_80110948_267A48_ChanceTime;
    }
}

/* A panel (side 0 left, 1 the outcome reel, 2 right, 3 the fourth, blank): its reel of four
   sprite faces over the panel model, filled with the players' characters (0, 2: random start of
   0 or 2), the outcome table D_80110920 (1) or face 6 (3). (MP1 func_800FCC18 / func_800FD7DC) */
void func_8010C44C_26354C_ChanceTime(omObjData* obj, s8 side) {
    CTPanelWork* work;
    CTReel* r;
    void* data;
    s8 i;
    s8 rnd;
    s8 a;
    s8 b;

    func_8010C09C_26319C_ChanceTime();
    D_80110920_267A20_ChanceTime = func_8010C268_263368_ChanceTime(D_800FFFD8_100BD8[0]);
    obj->model[0] = func_80027D3C_2893C(D_8011092C_267A2C_ChanceTime);
    obj->model[1] = func_80018A64_19664(0x440001, 0x6A9);
    obj->model[2] = LoadFormFile(0xC, 0x2CD);
    switch (side) {
    case 0:
        obj->trans.x = -140.0f;
        break;
    case 1:
        obj->trans.x = 0.0f;
        break;
    case 2:
    case 3:
        obj->trans.x = 140.0f;
        break;
    }
    obj->trans.y = 240.0f;
    obj->trans.z = 1400.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.5f;
    obj->rot.x = obj->rot.y = obj->rot.z = 0.0f;
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800297E8_2A3E8(obj->model[1], 0.8f, 0.8f, 0.8f);
    func_8002979C_2A39C(obj->model[1], 90.0f, 0.0f, 0.0f);
    work = obj->unk_50 = func_80027154_27D54(sizeof(CTPanelWork), 0x7918);
    func_800B0EF0_B1AF0(work, 0, sizeof(CTPanelWork));
    work->unk_03 = 1;
    switch (side) {
    case 0:
        work->unk_04 = 2;
        break;
    case 1:
        work->unk_04 = 1;
        break;
    case 2:
    case 3:
        work->unk_04 = 3;
        break;
    }
    work->unk_B0 = func_80027154_27D54(sizeof(CTReel), 0x7918);
    func_800B0EF0_B1AF0(work->unk_B0, 0, sizeof(CTReel));
    r = work->unk_B0;
    switch (side) {
    case 0:
        data = DataRead(0x440002);
        D_80110D64_267E64_ChanceTime = r->unk_02[0] =
            func_8003D8F0_3E4F0(D_800FC834_FD434[obj->model[1]].hmf, data, 0, D_80110184_267284_ChanceTime[0]);
        func_8003E4F4_3F0F4(r->unk_02[0], 1, 1);
        HuMemMemoryFreePerm(data);
        break;
    case 1:
        data = DataRead(0x440003);
        r->unk_02[0] =
            func_8003D8F0_3E4F0(D_800FC834_FD434[obj->model[1]].hmf, data, 0, D_80110184_267284_ChanceTime[0]);
        HuMemMemoryFreePerm(data);
        break;
    }
    if (side != 3) {
        /* face 0 too: side 1 copies its own first face over it (retail) */
        for (i = 0; i < 4; i++) {
            if (side == 1) {
                r->unk_02[i] = func_8003DBE8_3E7E8(D_800FC834_FD434[obj->model[1]].hmf, r->unk_02[0], 0,
                                                   D_80110184_267284_ChanceTime[i]);
            } else {
                r->unk_02[i] = func_8003DBE8_3E7E8(D_800FC834_FD434[obj->model[1]].hmf,
                                                   D_80110D64_267E64_ChanceTime, 0, D_80110184_267284_ChanceTime[i]);
            }
            func_8003E4F4_3F0F4(r->unk_02[i], 1, 1);
        }
        func_80029A8C_2A68C(obj->model[1]);
        func_80029AFC_2A6FC(obj->model[1]);
        if (side == 1) {
            if (D_80110060_267160_ChanceTime == 0) {
                r->unk_36 = 20;
            } else {
                r->unk_36 = 10;
            }
            for (i = 0; i < r->unk_36; i++) {
                r->unk_0C[i] = D_80110920_267A20_ChanceTime[i];
            }
            r->unk_38 = 0.0f;
            r->unk_0A = 2;
            r->unk_00 = 2;
            rnd = a = 0;
            for (i = 0, b = 0; i < 4; i++) {
                if (a >= r->unk_36) {
                    a = 0;
                }
                b &= 3;
                func_8003E52C_3F12C(r->unk_02[b], (u8)r->unk_0C[a]);
                b--;
                a++;
            }
            D_800FC834_FD434[obj->model[1]].rot.x += rnd * 90;
            D_800FC834_FD434[obj->model[1]].rot.x = (s32)D_800FC834_FD434[obj->model[1]].rot.x % 360;
        } else {
            for (i = 0; i < 4; i++) {
                r->unk_0C[i] = gPlayers[i].character;
            }
            r->unk_38 = 0.0f;
            r->unk_36 = 4;
            r->unk_00 = 2;
            r->unk_0A = 2;
            if ((s32)((u32)(rand8() * 5) >> 7) < 5) {
                rnd = a = 2;
            } else {
                rnd = a = 0;
            }
            i = 0;
            b = rnd;
            do {
                a &= 3;
                b &= 3;
                func_8003E52C_3F12C(r->unk_02[b], (u8)r->unk_0C[a]);
                b--;
                i++;
                a++;
            } while (i < 4);
            r->unk_0A += rnd;
            if (r->unk_0A >= r->unk_36) {
                r->unk_0A -= r->unk_36;
            }
            r->unk_00 = (r->unk_00 - rnd) & 3;
            D_800FC834_FD434[obj->model[1]].rot.x += r->unk_0A * 90;
            D_800FC834_FD434[obj->model[1]].rot.x = (s32)D_800FC834_FD434[obj->model[1]].rot.x % 360;
        }
    } else {
        for (i = 0; i < 4; i++) {
            s16 spr = func_8003DBE8_3E7E8(D_800FC834_FD434[obj->model[1]].hmf, D_80110D64_267E64_ChanceTime, 0,
                                          D_80110184_267284_ChanceTime[i]);
            r->unk_02[i] = spr;
            func_8003E4F4_3F0F4(spr, 1, 1);
        }
        func_80029A8C_2A68C(obj->model[1]);
        func_80029AFC_2A6FC(obj->model[1]);
        for (i = 0; i < 4; i++) {
            func_8003E52C_3F12C(r->unk_02[i], 6);
        }
    }
    switch (side) {
    case 0:
        obj->func_ptr = func_8010BF98_263098_ChanceTime;
        break;
    case 1:
        obj->func_ptr = func_8010BFB4_2630B4_ChanceTime;
        break;
    case 2:
        obj->func_ptr = func_8010BFEC_2630EC_ChanceTime;
        break;
    case 3:
        obj->func_ptr = func_8010C024_263124_ChanceTime;
        break;
    }
}

/* Block `idx` (0..2; MP1 func_800FC3D0/FD0AC/FDDD4 in one): spin while D_80110156 is set; when
   the holder hits it from below (D_80110061), stop on the nearest face, take its entry (the
   two players for blocks 0 and 2, the outcome for block 1), bounce and wobble for 16 frames. */
void func_8010CCF4_263DF4_ChanceTime(omObjData* obj, s8 idx) {
    CTReel* r = CT_REEL(obj);
    omObjData* player = D_800FFFD8_100BD8[0];
    CTReel* r2;
    s16 i;
    s16 j;
    s16 k;

    func_8010C09C_26319C_ChanceTime();
    D_80110928_267A28_ChanceTime = func_8010C268_263368_ChanceTime_1(player);
    if (D_80110061_267161_ChanceTime == 1 && func_8010DFF8_2650F8_ChanceTime(obj, 80.0f, player) != 0 &&
        D_80110198_267298_ChanceTime[idx] == 0) {
        D_80110198_267298_ChanceTime[idx] = 1;
    }
    if (D_801101A8_2672A8_ChanceTime[idx] != 0) {
        return;
    }
    if (D_80110156_267256_ChanceTime == 1 && D_801101B8_2672B8_ChanceTime[idx] == 0) {
        switch (idx) {
        case 0:
        case 1:
            if (D_80110060_267160_ChanceTime != 0) {
                CT_MDL(obj).rot.x += D_8011017C_26727C_ChanceTime;
            } else {
                CT_MDL(obj).rot.x += D_80110174_267274_ChanceTime[D_80110172_267272_ChanceTime];
            }
            break;
        case 2:
            CT_MDL(obj).rot.x += D_80110174_267274_ChanceTime[D_80110172_267272_ChanceTime];
            break;
        }
        if (CT_MDL(obj).rot.x >= 360.0f) {
            CT_MDL(obj).rot.x -= 360.0f;
        }
        switch (idx) {
        case 0:
        case 1:
            if (D_80110060_267160_ChanceTime != 0) {
                r->unk_38 += D_8011017C_26727C_ChanceTime;
            } else {
                r->unk_38 += D_80110174_267274_ChanceTime[D_80110172_267272_ChanceTime];
            }
            break;
        case 2:
            r->unk_38 += D_80110174_267274_ChanceTime[D_80110172_267272_ChanceTime];
            break;
        }
        if (r->unk_38 >= 90.0f) {
            r->unk_00 = (r->unk_00 - 1) & 3;
            r->unk_38 -= 90.0f;
            if (++r->unk_0A >= r->unk_36) {
                r->unk_0A = 0;
            }
            func_8003E52C_3F12C(r->unk_02[r->unk_00], (u8)r->unk_0C[r->unk_0A]);
        }
        switch (idx) {
        case 0:
            if (D_80110160_267260_ChanceTime[0] == 0) {
                if (D_80110060_267160_ChanceTime != 0) {
                    D_80110164_267264_ChanceTime[0] = PlaySound(0x2E2);
                } else {
                    D_80110164_267264_ChanceTime[0] = PlaySound(0x2E0);
                }
                D_80110160_267260_ChanceTime[0] = 1;
                D_8011016C_26726C_ChanceTime[0] = 1;
            }
            break;
        case 2:
            if (D_80110160_267260_ChanceTime[2] == 0) {
                D_80110164_267264_ChanceTime[2] = PlaySound(0x2E0);
                D_80110160_267260_ChanceTime[2] = 1;
                D_8011016C_26726C_ChanceTime[2] = 1;
            }
            break;
        case 1:
            if (D_80110160_267260_ChanceTime[1] == 0) {
                if (D_80110060_267160_ChanceTime != 0) {
                    D_80110164_267264_ChanceTime[1] = PlaySound(0x2E2);
                } else {
                    D_80110164_267264_ChanceTime[1] = PlaySound(0x2E0);
                }
                D_80110160_267260_ChanceTime[1] = 1;
                D_8011016C_26726C_ChanceTime[1] = 1;
            }
            break;
        }
    }
    if (D_80110198_267298_ChanceTime[idx] == 1) {
        if (D_801101A0_2672A0_ChanceTime[idx] < 17) {
            CT_MDL(obj).pos.y = HuMathSin(D_801101A0_2672A0_ChanceTime[idx] / 16.0f * 180.0f) * 100.0f + 240.0f;
            if (D_801101B0_2672B0_ChanceTime[idx] == 0) {
                func_800191D4_19DD4(obj, 2, obj->trans.x, obj->trans.y - 100.0f, obj->trans.z, 0.0f, 0.0f);
                D_801101B0_2672B0_ChanceTime[idx] = 1;
                if (D_800FFFD8_100BD8[0]->trans.x < CT_MDL(obj).pos.x) {
                    D_80110924_267A24_ChanceTime = 0;
                } else {
                    D_80110924_267A24_ChanceTime = 1;
                }
            }
            if (D_801101A0_2672A0_ChanceTime[idx] >= 3) {
                switch (D_801101B4_2672B4_ChanceTime[idx]) {
                case 0:
                    if (D_80110924_267A24_ChanceTime == 0) {
                        CT_MDL(obj).rot.z += 5.0f;
                    } else {
                        CT_MDL(obj).rot.z -= 5.0f;
                    }
                    if (D_801101A0_2672A0_ChanceTime[idx] == 4) {
                        D_801101B4_2672B4_ChanceTime[idx]++;
                    }
                    break;
                case 1:
                    if (D_80110924_267A24_ChanceTime == 0) {
                        CT_MDL(obj).rot.z -= 5.0f;
                    } else {
                        CT_MDL(obj).rot.z += 5.0f;
                    }
                    if (D_801101A0_2672A0_ChanceTime[idx] == 12) {
                        D_801101B4_2672B4_ChanceTime[idx]++;
                    }
                    break;
                case 2:
                    if (D_80110924_267A24_ChanceTime == 0) {
                        CT_MDL(obj).rot.z += 5.0f;
                    } else {
                        CT_MDL(obj).rot.z -= 5.0f;
                    }
                    if (D_801101A0_2672A0_ChanceTime[idx] == 16) {
                        CT_MDL(obj).rot.z = 0.0f;
                        D_801101B4_2672B4_ChanceTime[idx]++;
                    }
                    break;
                }
            }
            if (D_801101B8_2672B8_ChanceTime[idx] == 0) {
                switch (idx) {
                case 0:
                    D_8011016C_26726C_ChanceTime[0] = 2;
                    break;
                case 1:
                    D_8011016C_26726C_ChanceTime[1] = 2;
                    break;
                case 2:
                    D_8011016C_26726C_ChanceTime[2] = 2;
                    break;
                }
                if (CT_MDL(obj).rot.x - (s32)(CT_MDL(obj).rot.x / 90.0f) * 90 >= 45.0f) {
                    CT_MDL(obj).rot.x = (s32)(CT_MDL(obj).rot.x / 90.0f + 1.0f) * 90;
                    r->unk_00 = (r->unk_00 - 1) & 3;
                    if (++r->unk_0A >= r->unk_36) {
                        r->unk_0A = 0;
                    }
                    func_8003E52C_3F12C(r->unk_02[r->unk_00], (u8)r->unk_0C[r->unk_0A]);
                }
                if (idx == 1) {
                    if ((r->unk_0A -= 2) < 0) {
                        r->unk_0A += r->unk_36;
                    }
                }
                switch (idx) {
                case 0:
                    D_80110180_267280_ChanceTime = r->unk_0C[r->unk_0A];
                    if (D_80110181_267281_ChanceTime == 0xFF) {
                        r2 = CT_REEL(D_80110D88_267E88_ChanceTime);
                        r2->unk_36 = 3;
                        if (r2->unk_0A >= 3) {
                            r2->unk_0A = 0;
                        }
                        for (j = 0, i = 0; i < 4; i++) {
                            if (D_80110180_267280_ChanceTime != gPlayers[i].character) {
                                r2->unk_0C[j++] = gPlayers[i].character;
                            }
                        }
                    }
                    for (i = 0; i < 4; i++) {
                        if (D_80110180_267280_ChanceTime == gPlayers[i].character) {
                            D_80110180_267280_ChanceTime = i;
                            break;
                        }
                    }
                    for (i = 0; i < 4; i++) {
                        if (D_80110180_267280_ChanceTime == D_80110D6A_267E6A_ChanceTime[i]) {
                            break;
                        }
                    }
                    D_80110D62_267E62_ChanceTime[0] = i;
                    omVibrate(D_80110180_267280_ChanceTime, 2, 2, 20);
                    if (D_80110060_267160_ChanceTime != 0) {
                        k = D_80110172_267272_ChanceTime + 1;
                    } else {
                        k = D_80110172_267272_ChanceTime;
                    }
                    switch (k) {
                    case 0:
                        if (D_80110060_267160_ChanceTime != 0) {
                            PlaySound(0x2E3);
                        } else {
                            PlaySound(0x2E6);
                        }
                        break;
                    case 1:
                        if (D_80110060_267160_ChanceTime != 0) {
                            PlaySound(0x2E4);
                        } else {
                            PlaySound(0x2E7);
                        }
                        break;
                    default:
                        if (D_80110060_267160_ChanceTime != 0) {
                            PlaySound(0x2E5);
                        } else {
                            PlaySound(0x2E8);
                        }
                        break;
                    }
                    break;
                case 2:
                    D_80110181_267281_ChanceTime = r->unk_0C[r->unk_0A];
                    if (D_80110180_267280_ChanceTime == 0xFF) {
                        r2 = CT_REEL(D_80110D80_267E80_ChanceTime[0]);
                        r2->unk_36 = 3;
                        if (r2->unk_0A >= 3) {
                            r2->unk_0A = 0;
                        }
                        for (j = 0, i = 0; i < 4; i++) {
                            if (D_80110181_267281_ChanceTime != gPlayers[i].character) {
                                r2->unk_0C[j++] = gPlayers[i].character;
                            }
                        }
                    }
                    for (i = 0; i < 4; i++) {
                        if (D_80110181_267281_ChanceTime == gPlayers[i].character) {
                            D_80110181_267281_ChanceTime = i;
                            break;
                        }
                    }
                    for (i = 0; i < 4; i++) {
                        if (D_80110181_267281_ChanceTime == D_80110D6A_267E6A_ChanceTime[i]) {
                            break;
                        }
                    }
                    D_80110D62_267E62_ChanceTime[1] = i;
                    omVibrate(D_80110181_267281_ChanceTime, 2, 2, 20);
                    switch (D_80110172_267272_ChanceTime) {
                    case 0:
                        if (D_80110060_267160_ChanceTime != 0) {
                            PlaySound(0x2E3);
                        } else {
                            PlaySound(0x2E6);
                        }
                        break;
                    case 1:
                        if (D_80110060_267160_ChanceTime != 0) {
                            PlaySound(0x2E4);
                        } else {
                            PlaySound(0x2E7);
                        }
                        break;
                    default:
                        if (D_80110060_267160_ChanceTime != 0) {
                            PlaySound(0x2E5);
                        } else {
                            PlaySound(0x2E8);
                        }
                        break;
                    }
                    break;
                case 1:
                    D_80110182_267282_ChanceTime = r->unk_0C[r->unk_0A];
                    if (D_80110060_267160_ChanceTime != 0) {
                        k = D_80110172_267272_ChanceTime + 1;
                    } else {
                        k = D_80110172_267272_ChanceTime;
                    }
                    switch (k) {
                    case 0:
                        if (D_80110060_267160_ChanceTime != 0) {
                            PlaySound(0x2E3);
                        } else {
                            PlaySound(0x2E6);
                        }
                        break;
                    case 1:
                        if (D_80110060_267160_ChanceTime != 0) {
                            PlaySound(0x2E4);
                        } else {
                            PlaySound(0x2E7);
                        }
                        break;
                    default:
                        if (D_80110060_267160_ChanceTime != 0) {
                            PlaySound(0x2E5);
                        } else {
                            PlaySound(0x2E8);
                        }
                        break;
                    }
                    if (D_80110182_267282_ChanceTime == 10) {
                        omVibrate(0, 2, 2, 20);
                        omVibrate(1, 2, 2, 20);
                        omVibrate(2, 2, 2, 20);
                        omVibrate(3, 2, 2, 20);
                    }
                    break;
                }
                D_801101B8_2672B8_ChanceTime[idx] = 1;
            }
        } else {
            CT_MDL(obj).pos.y = 240.0f;
        }
        CT_MDL(obj).rot.x = (s32)(CT_MDL(obj).rot.x / 90.0f) * 90;
        if (CT_MDL(obj).rot.x >= 360.0f) {
            CT_MDL(obj).rot.x -= 360.0f;
        }
        if (D_801101A0_2672A0_ChanceTime[idx] >= 17) {
            D_801101A8_2672A8_ChanceTime[idx] = 1;
            D_80110198_267298_ChanceTime[idx] = 0;
            D_80110061_267161_ChanceTime = 0;
            switch (idx) {
            case 0:
                if (D_8011016C_26726C_ChanceTime[1] != 1 && D_8011016C_26726C_ChanceTime[2] != 1) {
                    func_80079848_7A448(D_80110164_267264_ChanceTime[0]);
                } else if (D_80110060_267160_ChanceTime == 0) {
                    func_80079848_7A448(D_80110164_267264_ChanceTime[0]);
                    switch (D_80110172_267272_ChanceTime) {
                    case 0:
                        D_80110164_267264_ChanceTime[0] = PlaySound(0x2E1);
                        break;
                    case 1:
                        D_80110164_267264_ChanceTime[0] = PlaySound(0x2E2);
                        break;
                    }
                }
                D_80110150_267250_ChanceTime[0] = 1;
                break;
            case 2:
                if (D_8011016C_26726C_ChanceTime[0] != 1 && D_8011016C_26726C_ChanceTime[1] != 1) {
                    func_80079848_7A448(D_80110164_267264_ChanceTime[2]);
                } else {
                    func_80079848_7A448(D_80110164_267264_ChanceTime[2]);
                    switch (D_80110172_267272_ChanceTime) {
                    case 0:
                        D_80110164_267264_ChanceTime[2] = PlaySound(0x2E1);
                        break;
                    case 1:
                        D_80110164_267264_ChanceTime[2] = PlaySound(0x2E2);
                        break;
                    }
                }
                D_80110150_267250_ChanceTime[2] = 1;
                break;
            case 1:
                if (D_8011016C_26726C_ChanceTime[0] != 1 && D_8011016C_26726C_ChanceTime[2] != 1) {
                    func_80079848_7A448(D_80110164_267264_ChanceTime[1]);
                } else if (D_80110060_267160_ChanceTime == 0) {
                    func_80079848_7A448(D_80110164_267264_ChanceTime[1]);
                    switch (D_80110172_267272_ChanceTime) {
                    case 0:
                        D_80110164_267264_ChanceTime[1] = PlaySound(0x2E1);
                        break;
                    case 1:
                        D_80110164_267264_ChanceTime[1] = PlaySound(0x2E2);
                        break;
                    }
                }
                D_80110150_267250_ChanceTime[1] = 1;
                break;
            }
            D_80110172_267272_ChanceTime++;
        }
        D_801101A0_2672A0_ChanceTime[idx]++;
    }
}

s16 func_8010DFF8_2650F8_ChanceTime(omObjData* obj, f32 size, omObjData* other) {
    Vec d;
    CTPlayerWork* work = CT_PWORK(other);
    f32 half;

    d.x = other->trans.x - obj->trans.x;
    d.y = other->trans.y + work->unk_34 + 10.0f - obj->trans.y;
    d.z = other->trans.z - obj->trans.z;
    half = size / 2.0f;
    if (-half < d.x && d.x < half && -half < d.z && d.z < half && -half < d.y && d.y < half) {
        return 1;
    }
    return 0;
}

void func_8010E0D4_2651D4_ChanceTime(omObjData* obj) {
    obj->model[0] = func_80018A64_19664(0x440000, 0x2B9);
    obj->trans.x = -140.0f;
    obj->trans.y = 3.0f;
    obj->trans.z = 1400.0f;
    obj->scale.x = 1.0f;
    obj->scale.y = 1.0f;
    obj->scale.z = 1.0f;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    obj->model[1] = func_80027D3C_2893C(obj->model[0]);
    func_80029714_2A314(obj->model[1], 0.0f, obj->trans.y, obj->trans.z);
    func_800297E8_2A3E8(obj->model[1], obj->scale.x, obj->scale.y, obj->scale.z);
    obj->model[2] = func_80027D3C_2893C(obj->model[0]);
    func_80029714_2A314(obj->model[2], 140.0f, obj->trans.y, obj->trans.z);
    func_800297E8_2A3E8(obj->model[2], obj->scale.x, obj->scale.y, obj->scale.z);
    obj->func_ptr = func_8010E214_265314_ChanceTime;
}

void func_8010E214_265314_ChanceTime(omObjData* obj) {
    f32 s;

    if (D_801101BC_2672BC_ChanceTime[0] == 0 && D_80110198_267298_ChanceTime[0] == 1) {
        s = 1.0f - HuMathSin(D_801101A0_2672A0_ChanceTime[0] / 16.0f * 180.0f) * 0.5f;
        obj->scale.x = obj->scale.y = obj->scale.z = s;
        if (D_801101A0_2672A0_ChanceTime[0] == 16) {
            D_801101BC_2672BC_ChanceTime[0] = 1;
        }
    } else if (D_801101BC_2672BC_ChanceTime[1] == 0 && D_80110198_267298_ChanceTime[1] == 1) {
        s = 1.0f - HuMathSin(D_801101A0_2672A0_ChanceTime[1] / 16.0f * 180.0f) * 0.5f;
        func_800297E8_2A3E8(obj->model[1], s, s, s);
        if (D_801101A0_2672A0_ChanceTime[1] == 16) {
            D_801101BC_2672BC_ChanceTime[1] = 1;
        }
    } else if (D_801101BC_2672BC_ChanceTime[2] == 0 && D_80110198_267298_ChanceTime[2] == 1) {
        s = 1.0f - HuMathSin(D_801101A0_2672A0_ChanceTime[2] / 16.0f * 180.0f) * 0.5f;
        func_800297E8_2A3E8(obj->model[2], s, s, s);
        if (D_801101A0_2672A0_ChanceTime[2] == 16) {
            D_801101BC_2672BC_ChanceTime[1] = 1; /* retail sets [1], not [2] */
        }
    }
}

/* Read only by .data (the panels' texture-name table): this file's .rodata. */
const char D_80110680_267780_ChanceTime[] = "tex3_DEF";
const char D_8011068C_26778C_ChanceTime[] = "tex2_DEF";
const char D_80110698_267798_ChanceTime[] = "tex1_DEF";
const char D_801106A4_2677A4_ChanceTime[] = "tex0_DEF";
