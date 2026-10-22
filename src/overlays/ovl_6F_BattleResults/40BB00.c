#include "ovl_6F.h"

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

/* A coin dropped from the carrier: waits, falls onto the target model, bursts. */
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
        work->vel = 1.0f;
        work->ofs = 0.0f;
        obj->work[0] = 2;
        break;
    case 2:
        work->ofs -= work->vel;
        work->vel += 0.05f;
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
    func_80029714_2A314(D_800F86D8_F92D8[coin].unk00, m->pos.x, m->pos.y + work->ofs, 800.0f);
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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_BattleResults/40BB00", func_80103518_40C818_BattleResults);

__asm__(".section .rodata");
const char D_8010591C_40EC1C_BattleResults[] = "item_hook";

void func_80103E60_40D160_BattleResults(s16 model, f32 dy) {
    HmfModel* m = &D_800FC834_FD434[model];

    func_80029714_2A314(model, m->pos.x, dy + m->pos.y, m->pos.z);
}

f32 func_80103EB4_40D1B4_BattleResults(s16 model) {
    HmfModel* m = &D_800FC834_FD434[model];

    return m->pos.y;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_BattleResults/40BB00", func_80103EDC_40D1DC_BattleResults);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_BattleResults/40BB00", func_80103FD8_40D2D8_BattleResults);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_BattleResults/40BB00", func_80104064_40D364_BattleResults);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_BattleResults/40BB00", func_801040F8_40D3F8_BattleResults);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_BattleResults/40BB00", func_801041C0_40D4C0_BattleResults);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_BattleResults/40BB00", func_801042B0_40D5B0_BattleResults);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_BattleResults/40BB00", func_801044AC_40D7AC_BattleResults);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_BattleResults/40BB00", func_80104770_40DA70_BattleResults);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_BattleResults/40BB00", func_801047C8_40DAC8_BattleResults);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_BattleResults/40BB00", func_80104960_40DC60_BattleResults);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_BattleResults/40BB00", func_80104BAC_40DEAC_BattleResults);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_BattleResults/40BB00", func_80104C14_40DF14_BattleResults);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_BattleResults/40BB00", func_80104D30_40E030_BattleResults);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6F_BattleResults/40BB00", func_801052D8_40E5D8_BattleResults);
