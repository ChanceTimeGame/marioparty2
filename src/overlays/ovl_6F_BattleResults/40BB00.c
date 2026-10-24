#include "ovl_6F.h"

/* .data (0x40EA00-0x40EBB0) */
s32 D_80105700_40EA00_BattleResults[4] = {
    32, 48, 72, 96,
};
Vec D_80105710_40EA10_BattleResults[4] = {
    { -158.0f, -275.0f, 800.0f },
    { -52.0f, -275.0f, 800.0f },
    { 54.0f, -275.0f, 800.0f },
    { 160.0f, -275.0f, 800.0f },
};
f32 D_80105740_40EA40_BattleResults[4] = {
    -8.0f, -4.0f, 6.0f, 10.0f,
};
s32 D_80105750_40EA50_BattleResults[8][4] = {
    { 0, 1, 2, 3 },
    { 0, 0, 2, 3 },
    { 0, 0, 2, 2 },
    { 0, 0, 0, 3 },
    { 0, 1, 1, 3 },
    { 0, 1, 1, 1 },
    { 0, 1, 2, 2 },
    { 0, 0, 0, 0 },
};
s32 D_801057D0_40EAD0_BattleResults[8][4] = {
    { 70, 30, 0, 0 },
    { 50, 50, 0, 0 },
    { 50, 0, 0, 0 },
    { 33, 0, 0, 0 },
    { 60, 20, 0, 0 },
    { 70, 10, 0, 0 },
    { 70, 30, 0, 0 },
    { 25, 0, 0, 0 },
};
s32 D_80105850_40EB50_BattleResults[6] = {
    0x4E, 0x4E, 0x4E, 0x4E, 0x4E, 0x4E,
};
s32 D_80105868_40EB68_BattleResults[6] = {
    0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
};
s32 D_80105880_40EB80_BattleResults = 0x80;
s32 D_80105884_40EB84_BattleResults = 0x80;
s32 D_80105888_40EB88_BattleResults[4] = {
    50, 0x6E, 0xAF, 0xF0,
};
s32 D_80105898_40EB98_BattleResults[4] = {
    80, 95, 0x6E, 0x7D,
};

/* Scene setup: camera, the scene object, the result process. */
void func_80102800_40BB00_BattleResults(void) {
    u8 cam;

    func_80020D20_21920(0x40);
    omInitObjMan(30, 10);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_80079E60_7AA60), 0xA0);
    func_80018E30_19A30(1);
    cam = func_80018E78_19A78();
    ScissorSet(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 15.0f, 500.0f, 5000.0f);
    D_800FA610_FB210 = 2300.0f;
    D_800FD474_FE074.x = 0.0f;
    D_800FD474_FE074.y = 0.0f;
    D_800FD474_FE074.z = 0.0f;
    D_8010274C_10334C.x = 0.0f;
    D_8010274C_10334C.y = 0.0f;
    D_8010274C_10334C.z = 0.0f;
    func_80026D28_27928(2);
    func_80026DAC_279AC(0, 16, 16, 16);
    omAddObj(10, 0, 0, -1, func_80103518_40C818_BattleResults);
    omAddPrcObj(func_801052D8_40E5D8_BattleResults, 0x1001, 0x800, 0);
    PlayMusic(0x15);
    InitFadeIn(0, 16);
}

#ifdef NON_MATCHING
/* NON_MATCHING: register allocation only (the sort index and the rank-array base swap t1/t2). */
/* Ranks the players by placement (coins_mg_bonus holds it after a battle), finds the matching
   payout pattern and splits the pot; the remainder goes to a random player (D_80105A6C). */
void func_8010299C_40BC9C_BattleResults(void) {
    s32 order[4];
    s32 score[4];
    s32 i;
    s32 j;
    s32 k;
    s32 t;
    s32 tmp;
    s32 sum;

    for (i = 0; i < 4; i++) {
        score[i] = 10 - gPlayers[i].coins_mg_bonus;
    }
    for (i = 0; i < 4; i++) {
        order[i] = i;
    }
    for (i = 4; i >= 2; i--) {
        for (j = 1, k = 0; j < i; j++, k++) {
            if (score[order[k]] < score[order[j]]) {
                tmp = order[k];
                order[k] = order[j];
                order[j] = tmp;
            }
        }
    }
    D_801059F8_40ECF8_BattleResults[order[0]] = 0;
    for (i = 0, j = 1, k = 0, t = 1; i < 3; i++, j++) {
        if (score[order[i]] > score[order[j]]) {
            k += t;
            D_801059F8_40ECF8_BattleResults[order[j]] = k;
            t = 1;
        } else {
            D_801059F8_40ECF8_BattleResults[order[j]] = k;
            t++;
        }
    }
    for (i = 0, k = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (D_801059F8_40ECF8_BattleResults[j] == i) {
                D_80105A08_40ED08_BattleResults[k++] = j;
            }
        }
    }
    if (k >= 5) {
        osSyncPrintf("mresult.c: ranking error\n");
        while (1) {
        }
    }
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
            if (D_80105750_40EA50_BattleResults[i][j] != D_801059F8_40ECF8_BattleResults[D_80105A08_40ED08_BattleResults[j]]) {
                break;
            }
        }
        if (j >= 4) {
            break;
        }
    }
    if (i >= 8) {
        osSyncPrintf("mresult.c: ranking error3\n");
        while (1) {
        }
    }
    for (j = 0; j < 4; j++) {
        if (i == 3) {
            if (D_801057D0_40EAD0_BattleResults[i][j] == 33) {
                D_80105A58_40ED58_BattleResults[j] = D_800F9208_F9E08 / 3;
            } else {
                D_80105A58_40ED58_BattleResults[j] = 0;
            }
        } else {
            D_80105A58_40ED58_BattleResults[j] = D_800F9208_F9E08 * D_801057D0_40EAD0_BattleResults[i][j] / 100;
        }
    }
    for (sum = 0, j = 0; j < 4; j++) {
        sum += D_80105A58_40ED58_BattleResults[D_801059F8_40ECF8_BattleResults[j]];
    }
    if (D_800F9208_F9E08 < sum) {
        osSyncPrintf("mresult.c: coin error\n");
        while (1) {
        }
    }
    D_80105A58_40ED58_BattleResults[4] = D_800F9208_F9E08 - sum;
    if (D_80105A58_40ED58_BattleResults[4] > 0) {
        D_80105A6C_40ED6C_BattleResults = rand8() & 3;
    }
    for (j = 0; j < 4; j++) {
        gPlayers[j].coins_mg = 0;
        gPlayers[j].coins_mg_bonus = D_80105A58_40ED58_BattleResults[D_801059F8_40ECF8_BattleResults[j]];
        if (D_80105A6C_40ED6C_BattleResults == j) {
            gPlayers[j].coins_mg_bonus += D_80105A58_40ED58_BattleResults[4];
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_BattleResults/40BB00", func_8010299C_40BC9C_BattleResults);
#endif

void func_80102E3C_40C13C_BattleResults(s32 rank, f32 x, f32 y) {
    D_801059C8_40ECC8_BattleResults[rank].x = x;
    D_801059C8_40ECC8_BattleResults[rank].y = y;
}

void func_80102E64_40C164_BattleResults(s32 rank, f32 dx, f32 dy) {
    D_801059C8_40ECC8_BattleResults[rank].x += dx;
    D_801059C8_40ECC8_BattleResults[rank].y += dy;
}

/* The rank position of a player. */
s32 func_80102EBC_40C1BC_BattleResults(s32 player) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_80105A08_40ED08_BattleResults[i] == player) {
            break;
        }
    }
    if (i >= 4) {
        osSyncPrintf("mresult.c: ranking error2\n");
        while (1) {
        }
    }
    return i;
}

/* Places each character and its pedestal piece over its rank's pedestal. */
void func_80102F24_40C224_BattleResults(void) {
    HmfModel* m;
    s32 i;
    s32 pos;

    for (i = 0; i < 4; i++) {
        pos = func_80102EBC_40C1BC_BattleResults(i);
        m = &D_800FC834_FD434[D_80105960_40EC60_BattleResults[pos]];
        func_80029714_2A314((s16)D_80105980_40EC80_BattleResults[i],
                            m->pos.x + D_80105740_40EA40_BattleResults[pos] + D_801059C8_40ECC8_BattleResults[i].x,
                            m->pos.y + 17.0f + D_801059C8_40ECC8_BattleResults[i].y - D_801059F8_40ECF8_BattleResults[i] * 2.0f,
                            m->pos.z - 100.0f + D_801059C8_40ECC8_BattleResults[i].z);
        func_80029714_2A314((s16)D_80105990_40EC90_BattleResults[i],
                            m->pos.x + D_80105740_40EA40_BattleResults[pos] + D_801059C8_40ECC8_BattleResults[i].x + (50.0f - i * 4.0f),
                            m->pos.y + 36.0f + D_801059C8_40ECC8_BattleResults[i].y,
                            m->pos.z - 200.0f + D_801059C8_40ECC8_BattleResults[i].z);
    }
}

/* A coin dropped from the carrier: waits, falls onto the pedestal, bursts. */
void func_80103138_40C438_BattleResults(omObjData* obj) {
    BRFallWork* work = obj->unk_50;
    s32 coin = obj->work[1];
    s32 burst = obj->work[3];
    HmfModel* m = &D_800FC834_FD434[D_800F86D8_F92D8[coin].unk00];
    HmfModel* carrier;

    switch (obj->work[0]) {
    case 0:
        if (--obj->work[2] == 0xFF) {
            obj->work[0] = 1;
        }
        break;
    case 1:
        carrier = &D_800FC834_FD434[D_801059B0_40ECB0_BattleResults];
        func_80029714_2A314(D_800F86D8_F92D8[coin].unk00, carrier->pos.x + 50.0f, carrier->pos.y, carrier->pos.z - 10.0f);
        func_800298A4_2A4A4(D_800F86D8_F92D8[coin].unk00, 4, 0);
        work->accel = 1.0f;
        work->vy = 0.0f;
        obj->work[0] = 2;
        break;
    case 2:
        work->vy -= work->accel;
        work->accel += 0.05f;
        if (m->pos.y < work->floor) {
            obj->work[0] = 3;
        }
        break;
    case 3:
        PlaySound(9);
        func_800212A4_21EA4(burst);
        func_80021160_21D60(burst, 4, 4);
        func_80021250_21E50(burst, 0xFF, 0xFF, 0xBE);
        func_80029714_2A314(D_800F86D8_F92D8[burst].unk00, m->pos.x, m->pos.y, m->pos.z);
        func_800297E8_2A3E8(D_800F86D8_F92D8[burst].unk00, 2.5f, 2.5f, 2.5f);
        if (work->vibrate != 0) {
            omVibrate((s16)work->player, 5, 0, 5);
        }
        func_800298A4_2A4A4(D_800F86D8_F92D8[coin].unk00, 4, 4);
        omDelObj(obj);
        return;
    }
    func_80029714_2A314(D_800F86D8_F92D8[coin].unk00, m->pos.x, m->pos.y + work->vy, 800.0f);
}

/* Starts a coin drop after a delay; vibrate/player: rumble that player's pad on landing. */
s32 func_8010342C_40C72C_BattleResults(s32 delay, f32 floor, s32 vibrate, s32 player) {
    omObjData* obj;
    BRFallWork* work;
    s32 coin;
    s32 burst;

    coin = func_8002109C_21C9C((s16)D_801059BC_40ECBC_BattleResults, 8);
    burst = func_8002109C_21C9C((s16)D_801059C0_40ECC0_BattleResults, 8);
    obj = omAddObj(200, 0, 0, -1, func_80103138_40C438_BattleResults);
    obj->unk_50 = func_80027154_27D54(sizeof(BRFallWork), 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, sizeof(BRFallWork));
    work = obj->unk_50;
    work->floor = floor;
    work->vibrate = vibrate;
    work->player = player;
    obj->work[0] = 0;
    obj->work[1] = coin;
    obj->work[2] = delay;
    obj->work[3] = burst;
    return coin;
}

#ifdef NON_MATCHING
/* NON_MATCHING: register allocation in the sprite loop only (s0/s1/s4/s5 swaps). */
/* Scene object: ranks the players, builds the pedestals, the characters, the carrier with its
   two hooks, the coin models and the coin-count sprites, then deletes itself. */
void func_80103518_40C818_BattleResults(omObjData* obj) {
    s32 i;
    s32 j;
    s32 k;
    s32 esp;
    s32 file;
    void* data;
    HmfData* hmf;
    s32 anim0;
    s16 anim1;
    s32 grp;

    for (i = 0; i < 4; i++) {
        D_801059C8_40ECC8_BattleResults[i].x = 0.0f;
        D_801059C8_40ECC8_BattleResults[i].y = 0.0f;
        D_801059C8_40ECC8_BattleResults[i].z = 0.0f;
    }
    D_80105A6C_40ED6C_BattleResults = -1;
    func_8010299C_40BC9C_BattleResults();
    esp = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0xC0009), 0, 0);
    espPosSet(esp, 160, 120);
    func_8001A708_1B308(esp, 0x4000);
    SprAttrReset(D_800F93FC_F9FFC[esp].unk04, 0, 0x1000);
    esp = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0xC000A), 0, 0);
    espPosSet(esp, 160, 225);
    SprAttrReset(D_800F93FC_F9FFC[esp].unk04, 0, 0x1000);
    for (i = 0; i < 4; i++) {
        D_80105960_40EC60_BattleResults[i] = func_80018A30_19630(
            (D_801059F8_40ECF8_BattleResults[D_80105A08_40ED08_BattleResults[i]] + 2) | 0xC0000, 0x299);
        func_80029714_2A314((s16)D_80105960_40EC60_BattleResults[i], D_80105710_40EA10_BattleResults[i].x,
                            D_80105710_40EA10_BattleResults[i].y, D_80105710_40EA10_BattleResults[i].z);
        D_80105970_40EC70_BattleResults[i] = func_80018A30_19630(0xC000C, 0x299);
        func_8002A00C_2AC0C((s16)D_80105970_40EC70_BattleResults[i]);
        func_80029714_2A314((s16)D_80105970_40EC70_BattleResults[i], D_80105710_40EA10_BattleResults[i].x,
                            D_80105710_40EA10_BattleResults[i].y, D_80105710_40EA10_BattleResults[i].z - 100.0f);
    }
    for (i = 0; i < 4; i++) {
        D_80105980_40EC80_BattleResults[i] = func_80018A30_19630(
            D_800CD438_CE038[gPlayers[i].character].unk_04 | D_800CD438_CE038[gPlayers[i].character].unk_08, 0x299);
        func_80029E80_2AA80((s16)D_80105980_40EC80_BattleResults[i], 0, 2);
        if (D_80105A58_40ED58_BattleResults[D_801059F8_40ECF8_BattleResults[i]] > 0 || D_80105A6C_40ED6C_BattleResults == i) {
            file = D_80105850_40EB50_BattleResults[gPlayers[i].character];
            D_80105A38_40ED38_BattleResults[i] = 0x103;
        } else {
            file = D_80105868_40EB68_BattleResults[gPlayers[i].character];
            D_80105A38_40ED38_BattleResults[i] = -1;
        }
        D_80105A28_40ED28_BattleResults[i] = func_8002C8B8_2D4B8(DataRead(file | D_800CD438_CE038[gPlayers[i].character].unk_04), 0x18);
        func_800297E8_2A3E8((s16)D_80105980_40EC80_BattleResults[i], 0.5f, 0.5f, 0.5f);
        func_80102E3C_40C13C_BattleResults(i, 0.0f, 0.0f);
        if (D_80105880_40EB80_BattleResults == 0x80) {
            D_80105880_40EB80_BattleResults = D_80105990_40EC90_BattleResults[i] = func_80018A30_19630(0xC000B, 0x29D);
        } else {
            D_80105990_40EC90_BattleResults[i] = func_80027D3C_2893C((s16)D_80105880_40EB80_BattleResults);
        }
    }
    D_801059B0_40ECB0_BattleResults = func_80018A30_19630(0x800A6, 0x299);
    D_80105A18_40ED18_BattleResults = func_8002C8B8_2D4B8(DataRead(0x800A8), 0x18);
    D_80105A1C_40ED1C_BattleResults = func_8002C8B8_2D4B8(DataRead(0x800A9), 0x18);
    D_80105A20_40ED20_BattleResults = D_800FC834_FD434[D_801059B0_40ECB0_BattleResults].unk02;
    func_8002C9C0_2D5C0((s16)D_801059B0_40ECB0_BattleResults, (s16)D_80105A18_40ED18_BattleResults);
    func_80029E80_2AA80((s16)D_801059B0_40ECB0_BattleResults, 0, 2);
    func_800297E8_2A3E8((s16)D_801059B0_40ECB0_BattleResults, 0.5f, 0.5f, 0.5f);
    func_8002979C_2A39C((s16)D_801059B0_40ECB0_BattleResults, 0.0f, -90.0f, 0.0f);
    func_80029714_2A314((s16)D_801059B0_40ECB0_BattleResults, 300.0f, 125.0f, 700.0f);
    D_801059B4_40ECB4_BattleResults = func_80018A30_19630(0xC0006, 0x299);
    func_8002C628_2D228((s16)D_801059B4_40ECB4_BattleResults, (s16)D_801059B0_40ECB0_BattleResults, "item_hook");
    func_800298A4_2A4A4((s16)D_801059B4_40ECB4_BattleResults, 0x4000, 0x4000);
    D_801059B8_40ECB8_BattleResults = func_80018A30_19630(0xC0007, 0x29D);
    func_8002C628_2D228((s16)D_801059B8_40ECB8_BattleResults, (s16)D_801059B0_40ECB0_BattleResults, "item_hook");
    data = DataRead(0xE);
    D_801059BC_40ECBC_BattleResults = func_80020EBC_21ABC(data, 0x29D, 8);
    DataClose(data);
    HmfModelObjAttrSet(D_800F86D8_F92D8[D_801059BC_40ECBC_BattleResults].unk00, 0x70000000, 0x70000000);
    func_800297E8_2A3E8(D_800F86D8_F92D8[D_801059BC_40ECBC_BattleResults].unk00, 1.0f, 1.0f, 1.0f);
    data = DataRead(0x14);
    D_801059C0_40ECC0_BattleResults = func_80020EBC_21ABC(data, 0x29D, 8);
    DataClose(data);
    HmfModelObjAttrSet(D_800F86D8_F92D8[D_801059C0_40ECC0_BattleResults].unk00, 0x70000000, 0x70000000);
    for (i = 0; i < 4; i++) {
        if (D_80105A58_40ED58_BattleResults[D_801059F8_40ECF8_BattleResults[i]] > 0 || D_80105A6C_40ED6C_BattleResults == i) {
            D_80105884_40EB84_BattleResults = D_801059A0_40ECA0_BattleResults[i] = func_80018A30_19630(0xC0008, 0x28D);
            HmfModelObjAttrSet((s16)D_801059A0_40ECA0_BattleResults[i], 0x10000, 0x10000);
            hmf = D_800FC834_FD434[D_801059A0_40ECA0_BattleResults[i]].hmf;
            for (k = 0; k < hmf->unk1E; k++) {
                hmf->unk8C[k].unk0C |= 5;
                hmf->unk8C[k].unk0D = 0;
            }
            func_80029A8C_2A68C((s16)D_801059A0_40ECA0_BattleResults[i]);
            func_80029AFC_2A6FC((s16)D_801059A0_40ECA0_BattleResults[i]);
        } else {
            D_801059A0_40ECA0_BattleResults[i] = -1;
        }
    }
    anim0 = func_8001A2F8_1AEF8(0xC0000);
    anim1 = func_8001A2F8_1AEF8(0xC000D);
    for (i = 0; i < 4; i++) {
        grp = SprCreate(5, 5);
        D_80105A48_40ED48_BattleResults[i] = grp;
        SprAnimSet(grp, 0, anim0, 0);
        func_800824F4_830F4(grp, 0, -1);
        SprAttrSet(grp, 0, 0x9000);
        for (j = 0; j < 4; j++) {
            SprAnimSet(grp, j + 1, anim1, 0);
            func_800824F4_830F4(grp, j + 1, 0);
            func_8008225C_82E5C(grp, j + 1, 1);
            func_8008221C_82E1C(grp, j + 1, 0.0f);
            SprAttrSet(grp, j + 1, 0x9000);
        }
    }
    omDelObj(obj);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_BattleResults/40BB00", func_80103518_40C818_BattleResults);
__asm__(".section .rodata");
const char D_8010591C_40EC1C_BattleResults[] = "item_hook";
#endif

void func_80103E60_40D160_BattleResults(s16 model, f32 dy) {
    HmfModel* m = &D_800FC834_FD434[model];

    func_80029714_2A314(model, m->pos.x, dy + m->pos.y, m->pos.z);
}

f32 func_80103EB4_40D1B4_BattleResults(s16 model) {
    HmfModel* m = &D_800FC834_FD434[model];

    return m->pos.y;
}

/* Bobs a rank's pedestal and its shadow (work[0] rank, work[1] frames, work[2] height step). */
void func_80103EDC_40D1DC_BattleResults(omObjData* obj) {
    f32 dy = 0.0f;
    u8 t;

    switch (obj->work[2]) {
    case 0:
        dy = 7.0f;
        break;
    case 1:
        dy = 5.0f;
        break;
    case 2:
        dy = 3.0f;
        break;
    case 3:
        dy = 1.0f;
        break;
    }
    func_80103E60_40D160_BattleResults((s16)D_80105960_40EC60_BattleResults[obj->work[0]], dy);
    func_80103E60_40D160_BattleResults((s16)D_80105970_40EC70_BattleResults[obj->work[0]], dy);
    t = obj->work[1];
    obj->work[1] = t + 0xFF; /* t - 1; retail adds 0xFF */
    if (t == 0) {
        omDelObj(obj);
    }
}

/* Raises every character by work[3] / work[2] a frame for work[1] frames. */
void func_80103FD8_40D2D8_BattleResults(omObjData* obj) {
    s32 i;
    u8 t;

    for (i = 0; i < 4; i++) {
        func_80102E64_40C164_BattleResults(i, 0.0f, (f32)obj->work[3] / (f32)obj->work[2]);
    }
    t = obj->work[1];
    obj->work[1] = t + 0xFF; /* t - 1; retail adds 0xFF */
    if (t == 0) {
        omDelObj(obj);
    }
}

/* The carrier lets its coins go: swap the hooks, play the release motion. */
void func_80104064_40D364_BattleResults(void) {
    func_800298A4_2A4A4((s16)D_801059B4_40ECB4_BattleResults, 4, 4);
    func_800298A4_2A4A4((s16)D_801059B4_40ECB4_BattleResults, 0x4000, 0);
    func_800298A4_2A4A4((s16)D_801059B8_40ECB8_BattleResults, 0x4000, 0x4000);
    func_800298A4_2A4A4((s16)D_801059B8_40ECB8_BattleResults, 4, 0);
    func_8002C9C0_2D5C0((s16)D_801059B0_40ECB0_BattleResults, (s16)D_80105A1C_40ED1C_BattleResults);
    func_80029E80_2AA80((s16)D_801059B0_40ECB0_BattleResults, 0, 2);
}

/* Drops n coins (5, 3 or 1) onto a pedestal at height y; the last one rumbles the player's pad. */
void func_801040F8_40D3F8_BattleResults(s32 n, f32 y, s32 player) {
    f32 floor = y + 250.0f;

    switch (n) {
    case 5:
        func_8010342C_40C72C_BattleResults(0, floor, 0, player);
        func_8010342C_40C72C_BattleResults(8, floor, 0, player);
    case 3:
        func_8010342C_40C72C_BattleResults(2, floor, 0, player);
        func_8010342C_40C72C_BattleResults(6, floor, 0, player);
    case 1:
        func_8010342C_40C72C_BattleResults(4, floor, 1, player);
        break;
    }
}

/* The carrier passes rank position pos: drop that player's coins if they won any. */
void func_801041C0_40D4C0_BattleResults(omObjData* obj, s32 pos) {
    s32 player = D_80105A08_40ED08_BattleResults[pos];
    s32 n;

    if (D_80105A58_40ED58_BattleResults[D_801059F8_40ECF8_BattleResults[player]] > 0) {
        /* Retail counts in work[pos], which overlaps the carrier's speed and state bytes. */
        if (++obj->work[pos] == 1) {
            func_80104064_40D364_BattleResults();
        }
        switch (D_801059F8_40ECF8_BattleResults[D_80105A08_40ED08_BattleResults[pos]]) {
        case 0:
            n = 5;
            break;
        case 1:
            n = 3;
            break;
        default:
            n = 1;
            break;
        }
        func_801040F8_40D3F8_BattleResults(n, func_80103EB4_40D1B4_BattleResults((s16)D_80105960_40EC60_BattleResults[pos]), player);
    }
}

/* The carrier flies right to left over the pedestals, dropping each player's coins in turn;
   work[1] is its speed, work[2] its state, work[0] = 100 when it has left. */
void func_801042B0_40D5B0_BattleResults(omObjData* obj) {
    HmfModel* m = &D_800FC834_FD434[D_801059B0_40ECB0_BattleResults];

    func_80029714_2A314((s16)D_801059B0_40ECB0_BattleResults, m->pos.x - obj->work[1], m->pos.y, m->pos.z);
    switch (obj->work[2]) {
    case 0:
        PlaySound(0xE8);
        obj->work[2] = 1;
        break;
    case 1:
        if (m->pos.x < D_80105710_40EA10_BattleResults[3].x + 10.0f) {
            func_801041C0_40D4C0_BattleResults(obj, 3);
            obj->work[2] = 2;
        }
        break;
    case 2:
        if (m->pos.x < D_80105710_40EA10_BattleResults[2].x + 10.0f) {
            func_801041C0_40D4C0_BattleResults(obj, 2);
            obj->work[2] = 3;
        }
        break;
    case 3:
        if (m->pos.x < D_80105710_40EA10_BattleResults[1].x + 10.0f) {
            func_801041C0_40D4C0_BattleResults(obj, 1);
            obj->work[2] = 4;
        }
        break;
    case 4:
        if (m->pos.x < D_80105710_40EA10_BattleResults[0].x + 10.0f) {
            func_801041C0_40D4C0_BattleResults(obj, 0);
            obj->work[2] = 5;
        }
        break;
    }
    if (m->pos.x < -330.0f) {
        func_800298A4_2A4A4((s16)D_801059B0_40ECB0_BattleResults, 4, 4);
        func_800298A4_2A4A4((s16)D_801059B8_40ECB8_BattleResults, 4, 4);
        obj->work[0] = 100;
    }
}

/* The remainder coin: thrown from the carrier along an arc onto its player's pedestal. */
void func_801044AC_40D7AC_BattleResults(omObjData* obj) {
    BRFallWork* work = obj->unk_50;
    s32 coin = obj->work[1];
    s32 burst = obj->work[2];
    HmfModel* m = &D_800FC834_FD434[D_800F86D8_F92D8[coin].unk00];
    HmfModel* carrier;

    switch (obj->work[0]) {
    case 0:
        carrier = &D_800FC834_FD434[D_801059B0_40ECB0_BattleResults];
        func_80029714_2A314(D_800F86D8_F92D8[coin].unk00, carrier->pos.x + 50.0f, carrier->pos.y, carrier->pos.z - 10.0f);
        func_800298A4_2A4A4(D_800F86D8_F92D8[coin].unk00, 4, 0);
        obj->work[0] = 1;
        break;
    case 1:
        work->vy -= work->accel;
        work->accel += 0.05f;
        if (m->pos.y < work->floor) {
            obj->work[0] = 2;
        }
        break;
    case 2:
        PlaySound(9);
        func_800212A4_21EA4(burst);
        func_80021160_21D60(burst, 4, 4);
        func_80021250_21E50(burst, 0xFF, 0xFF, 0xBE);
        func_80029714_2A314(D_800F86D8_F92D8[burst].unk00, m->pos.x, m->pos.y, m->pos.z);
        func_800297E8_2A3E8(D_800F86D8_F92D8[burst].unk00, 2.5f, 2.5f, 2.5f);
        omVibrate(obj->work[3], 5, 0, 5);
        func_800298A4_2A4A4(D_800F86D8_F92D8[coin].unk00, 4, 4);
        D_80105A70_40ED70_BattleResults = 1;
        omDelObj(obj);
        return;
    }
    func_80029714_2A314(D_800F86D8_F92D8[coin].unk00, m->pos.x + work->dx, m->pos.y + work->vy, 800.0f);
}

#ifdef NON_MATCHING
/* NON_MATCHING: the two float parameters are moved to FPRs in the other order */
/* Frames a coin dropped from height y with this work takes to fall below floor. */
s32 func_80104770_40DA70_BattleResults(BRFallWork* work, f32 y, f32 floor) {
    f32 vy = work->vy;
    f32 accel = work->accel;
    s32 n = 0;

    while (floor < y) {
        vy -= accel;
        accel += 0.05f;
        y += vy;
        n++;
    }
    return n;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_BattleResults/40BB00", func_80104770_40DA70_BattleResults);
#endif

#ifdef NON_MATCHING
/* NON_MATCHING: scheduling and registers around the pedestal pointer and the model base load */
/* Throws the remainder coin from the carrier to the player's pedestal. */
s32 func_801047C8_40DAC8_BattleResults(s32 player) {
    HmfModel* carrier = &D_800FC834_FD434[D_801059B0_40ECB0_BattleResults];
    omObjData* obj;
    BRFallWork* work;
    s32* ped;
    s32 coin;
    s32 burst;

    coin = func_8002109C_21C9C((s16)D_801059BC_40ECBC_BattleResults, 8);
    burst = func_8002109C_21C9C((s16)D_801059C0_40ECC0_BattleResults, 8);
    obj = omAddObj(200, 0, 0, -1, func_801044AC_40D7AC_BattleResults);
    obj->unk_50 = func_80027154_27D54(sizeof(BRFallWork), 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, sizeof(BRFallWork));
    work = obj->unk_50;
    ped = &D_80105960_40EC60_BattleResults[func_80102EBC_40C1BC_BattleResults(player)];
    work->floor = func_80103EB4_40D1B4_BattleResults((s16)*ped) + 250.0f;
    work->accel = 0.0f;
    work->vy = 5.0f;
    work->dx = (D_800FC834_FD434[*ped].pos.x - (carrier->pos.x + 50.0f)) /
               func_80104770_40DA70_BattleResults(work, carrier->pos.y, work->floor);
    obj->work[0] = 0;
    obj->work[1] = coin;
    obj->work[2] = burst;
    obj->work[3] = player;
    return coin;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_BattleResults/40BB00", func_801047C8_40DAC8_BattleResults);
#endif

/* The carrier comes back for the remainder: flies in, turns, throws the coin, turns, leaves. */
void func_80104960_40DC60_BattleResults(omObjData* obj) {
    HmfModel* m = &D_800FC834_FD434[D_801059B0_40ECB0_BattleResults];

    switch (obj->work[1]) {
    case 0:
        func_800298A4_2A4A4((s16)D_801059B0_40ECB0_BattleResults, 4, 0);
        func_8002979C_2A39C((s16)D_801059B0_40ECB0_BattleResults, 0.0f, 90.0f, 0.0f);
        func_8002C9C0_2D5C0((s16)D_801059B0_40ECB0_BattleResults, (s16)D_80105A18_40ED18_BattleResults);
        func_80029E80_2AA80((s16)D_801059B0_40ECB0_BattleResults, 0, 2);
        PlaySound(0xE8);
        obj->work[1] = 1;
        break;
    case 1:
        func_80029714_2A314((s16)D_801059B0_40ECB0_BattleResults, m->pos.x + 10.0f, m->pos.y, m->pos.z);
        if (D_80105710_40EA10_BattleResults[0].x < m->pos.x) {
            func_8002C9C0_2D5C0((s16)D_801059B0_40ECB0_BattleResults, (s16)D_80105A20_40ED20_BattleResults);
            func_80029E80_2AA80((s16)D_801059B0_40ECB0_BattleResults, 0, 2);
            obj->work[1] = 2;
            obj->work[2] = 0;
        }
        break;
    case 2:
        func_8002979C_2A39C((s16)D_801059B0_40ECB0_BattleResults, 0.0f, 0.0f, 0.0f);
        if (obj->work[2]++ >= 5) {
            func_801047C8_40DAC8_BattleResults(D_80105A6C_40ED6C_BattleResults);
            obj->work[1] = 3;
            obj->work[2] = 0;
        }
        break;
    case 3:
        if (obj->work[2]++ >= 7) {
            func_8002979C_2A39C((s16)D_801059B0_40ECB0_BattleResults, 0.0f, -90.0f, 0.0f);
            func_8002C9C0_2D5C0((s16)D_801059B0_40ECB0_BattleResults, (s16)D_80105A18_40ED18_BattleResults);
            func_80029E80_2AA80((s16)D_801059B0_40ECB0_BattleResults, 0, 2);
            obj->work[1] = 4;
        }
        break;
    case 4:
        func_80029714_2A314((s16)D_801059B0_40ECB0_BattleResults, m->pos.x - 10.0f, m->pos.y, m->pos.z);
        if (m->pos.x < -330.0f) {
            func_800298A4_2A4A4((s16)D_801059B0_40ECB0_BattleResults, 4, 4);
            obj->work[0] = 100;
        }
        break;
    }
}

/* Puts a coin bag above a player's character. */
/* Old-style definition: retail's caller passes the model id unnarrowed (lw, not lh). */
void func_80104BAC_40DEAC_BattleResults(model, player)
    s16 model;
    s32 player;
{
    HmfModel* m = &D_800FC834_FD434[D_80105980_40EC80_BattleResults[player]];

    func_80029714_2A314(model, m->pos.x, m->pos.y, m->pos.z + 50.0f);
}

/* Fades a player's coin bag in over work[0] frames (work[1] the player). */
void func_80104C14_40DF14_BattleResults(omObjData* obj) {
    s32 model = D_801059A0_40ECA0_BattleResults[obj->work[1]];
    HmfData* hmf = D_800FC834_FD434[model].hmf;
    s32 i;

    func_800298A4_2A4A4(model, 4, 0);
    for (i = 0; i < hmf->unk10; i++) {
        hmf->unk64[i].unk02 += 15;
    }
    if (--obj->work[0] == 0xFF) {
        for (i = 0; i < hmf->unk10; i++) {
            hmf->unk64[i].unk02 = 0x99;
        }
        omDelObj(obj);
    }
}

#ifdef NON_MATCHING
/* NON_MATCHING: loop-invariant hoisting differs (retail keeps D_801059F8 in fp; this keeps another table base), so registers and a few address loads differ. */
/* Draws each rank's coin count (sign and up to three digits) at the given scale; 0 hides it. */
void func_80104D30_40E030_BattleResults(f32 scale) {
    s32 i;
    s32 coins;
    s32 grp;
    s16 x;
    s32 d;
    s32 y;

    for (i = 0; i < 4; i++) {
        coins = D_80105A58_40ED58_BattleResults[D_801059F8_40ECF8_BattleResults[D_80105A08_40ED08_BattleResults[i]]];
        if (D_80105A6C_40ED6C_BattleResults == D_80105A08_40ED08_BattleResults[i]) {
            coins += D_80105A58_40ED58_BattleResults[4];
        }
        grp = D_80105A48_40ED48_BattleResults[i];
        if (scale != 0.0f) {
            SprAttrReset(grp, 0, 0x8000);
        } else {
            SprAttrSet(grp, 0, 0x8000);
        }
        SprBankSet(grp, 0, 0);
        SprScaleSet(grp, 0, scale, scale);
        SprPosSet(grp, 0, (s16)D_80105888_40EB88_BattleResults[i],
                  (s16)D_80105898_40EB98_BattleResults[D_801059F8_40ECF8_BattleResults[D_80105A08_40ED08_BattleResults[i]]]);
        if ((coins >= 0) ? (coins < 100) : (-coins < 100)) {
            x = 8;
        } else {
            x = 12;
        }
        y = -2;
        if (scale != 0.0f) {
            SprAttrReset(grp, 1, 0x8000);
        } else {
            SprAttrSet(grp, 1, 0x8000);
        }
        if (coins >= 0) {
            d = coins % 10;
        } else {
            d = -coins % 10;
        }
        func_800822A8_82EA8(grp, 1, d, 0);
        SprScaleSet(grp, 1, scale, scale);
        SprPosSet(grp, 1, x, y);
        x -= 8;
        if ((coins >= 0) ? (coins >= 10) : (-coins >= 10)) {
            if (scale != 0.0f) {
                SprAttrReset(grp, 2, 0x8000);
            } else {
                SprAttrSet(grp, 2, 0x8000);
            }
            if (coins >= 0) {
                d = coins % 100 / 10;
            } else {
                d = -coins % 100 / 10;
            }
            if (d >= 10) {
                d = 9;
            }
            func_800822A8_82EA8(grp, 2, d, 0);
            SprScaleSet(grp, 2, scale, scale);
            SprPosSet(grp, 2, x, y);
            x -= 8;
        }
        if ((coins >= 0) ? (coins >= 100) : (-coins >= 100)) {
            if (scale != 0.0f) {
                SprAttrReset(grp, 3, 0x8000);
            } else {
                SprAttrSet(grp, 3, 0x8000);
            }
            if (coins >= 0) {
                d = coins / 100;
            } else {
                d = -coins / 100;
            }
            if (d >= 10) {
                d = 9;
            }
            func_800822A8_82EA8(grp, 3, d, 0);
            SprScaleSet(grp, 3, scale, scale);
            SprPosSet(grp, 3, x, y);
            x -= 8;
        }
        if (scale != 0.0f) {
            SprAttrReset(grp, 4, 0x8000);
        } else {
            SprAttrSet(grp, 4, 0x8000);
        }
        /* Retail: frame 11 for a gain, 1 for a loss (a loss cannot happen here). */
        if (coins >= 0) {
            func_800822A8_82EA8(grp, 4, 11, 0);
        } else {
            func_800822A8_82EA8(grp, 4, 1, 0);
        }
        SprScaleSet(grp, 4, scale, scale);
        SprPosSet(grp, 4, x, y);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_BattleResults/40BB00", func_80104D30_40E030_BattleResults);
#endif

/* The result process: pedestals rise, the carrier drops everyone's coins (and comes back with
   the remainder), the counts zoom in and out, the coin bags fade in, each character plays its
   result motion and message, then fade out and return to the board. */
void func_801052D8_40E5D8_BattleResults(void) {
    omObjData* obj;
    s32 i;
    s32 player;
    f32 scale;

    for (i = 0; i < 4; i++) {
        obj = omAddObj(100, 0, 0, -1, func_80103EDC_40D1DC_BattleResults);
        obj->work[0] = i;
        obj->work[1] = 10;
        obj->work[2] = D_801059F8_40ECF8_BattleResults[D_80105A08_40ED08_BattleResults[i]];
    }
    obj = omAddObj(200, 0, 0, -1, func_80103FD8_40D2D8_BattleResults);
    obj->work[1] = 15;
    obj->work[2] = 15;
    obj->work[3] = 150;
    for (i = 0; i < 15; i++) {
        func_80102F24_40C224_BattleResults();
        HuPrcVSleep();
    }
    obj = omAddObj(200, 0, 0, -1, func_801042B0_40D5B0_BattleResults);
    obj->work[1] = 10;
    obj->work[2] = 0;
    obj->work[3] = 0;
    while (obj->work[0] != 100) {
        func_80102F24_40C224_BattleResults();
        HuPrcVSleep();
    }
    omDelObj(obj);
    HuPrcVSleep();
    if (D_80105A6C_40ED6C_BattleResults != -1) {
        D_80105A70_40ED70_BattleResults = 0;
        obj = omAddObj(200, 0, 0, -1, func_80104960_40DC60_BattleResults);
        obj->work[1] = 0;
        while (D_80105A70_40ED70_BattleResults == 0) {
            func_80102F24_40C224_BattleResults();
            HuPrcVSleep();
        }
        omDelObj(obj);
        HuPrcVSleep();
    }
    for (scale = 0.0f; scale < 1.0f; scale += 1.0f / 15.0f) {
        func_80104D30_40E030_BattleResults(scale);
        HuPrcVSleep();
    }
    func_80104D30_40E030_BattleResults(1.0f);
    HuPrcSleep(30);
    for (scale = 1.0f; scale > 0.0f; scale -= 0.1f) {
        func_80104D30_40E030_BattleResults(scale);
        HuPrcVSleep();
    }
    func_80104D30_40E030_BattleResults(0.0f);
    for (i = 0; i < 4; i++) {
        player = D_80105A08_40ED08_BattleResults[i];
        if (D_801059A0_40ECA0_BattleResults[player] != -1) {
            obj = omAddObj(300, 0, 0, -1, func_80104C14_40DF14_BattleResults);
            obj->work[0] = 10;
            obj->work[1] = player;
            func_80104BAC_40DEAC_BattleResults(D_801059A0_40ECA0_BattleResults[player], player);
        }
        func_8002C9C0_2D5C0((s16)D_80105980_40EC80_BattleResults[player], (s16)D_80105A28_40ED28_BattleResults[player]);
        if (D_80105A38_40ED38_BattleResults[player] != -1) {
            func_800798F8_7A4F8(func_800797DC_7A3DC((s16)D_80105A38_40ED38_BattleResults[player], player),
                                (s16)D_80105700_40EA00_BattleResults[i]);
        }
    }
    HuPrcSleep(90);
    func_800794A8_7A0A8(40);
    InitFadeOut(0, 20);
    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    func_8002CA48_2D648(0, 0, 0);
    omOvlKill();
    omOvlReturnEx(1);
    while (1) {
        HuPrcVSleep();
    }
}
