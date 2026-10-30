#include "common.h"
#include "ovl_1F.h"

void func_80102800_1BE380_DungeonDash(void) {
    s16 i;
    s16 j;
    s32 slot;

    func_8002D4D0_2E0D0(0x32);
    func_8002F290_2FE90(D_800F9D30_FA930, 0x40);
    func_80020D20_21920(0x20);
    omInitObjMan(0x32, 0);
    func_80079128_79D28();
    D_8010B04C_1C6BCC_DungeonDash = omAddObj(0x7FDA, 0, 0, -1, func_80079FF4_7ABF4);
    omSetStatBit(D_8010B04C_1C6BCC_DungeonDash, 0xA0);
    D_8010B04C_1C6BCC_DungeonDash->work[0] = 2;
    func_80018ED0_19AD0(2);
    func_80018F58_19B58(2);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    ScissorSet(1, 320.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(1, 640.0f, 480.0f, 511.0f, 960.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 70.0f, 80.0f, 8000.0f);
    Hu3DCamSetPerspective(1, 70.0f, 80.0f, 8000.0f);
    D_8010B100_1C6C80_DungeonDash = 0;
    D_8010B102_1C6C82_DungeonDash = 3600;
    D_800F8FD0_F9BD0 = 1;
    D_8010B124_1C6CA4_DungeonDash = _CheckFlag(0xC);
    D_8010B120_1C6CA0_DungeonDash = 0;
    D_8010B134_1C6CB4_DungeonDash = 0;
    D_8010B130_1C6CB0_DungeonDash = 0;
    func_801068E8_1C2468_DungeonDash();
    D_8010B144_1C6CC4_DungeonDash = 0;
    D_8010B138_1C6CB8_DungeonDash = 0;
    for (i = 0; i < 4; i++) {
        D_8010B058_1C6BD8_DungeonDash[i] = 0;
    }
    D_800FA606_FB206 = 0;
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    func_8000C018_CC18(0);
    D_8010B048_1C6BC8_DungeonDash = omAddObj(1, 0, 0, -1, func_80102CF8_1BE878_DungeonDash);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(2, 0, 0, -1, func_801071C0_1C2D40_DungeonDash);
    omAddObj(2, 0, 0, -1, func_80102D94_1BE914_DungeonDash);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(3, 10, 60, -1, func_80103100_1BEC80_DungeonDash);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(3, 10, 60, -1, func_80103134_1BECB4_DungeonDash);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(3, 10, 60, -1, func_80103168_1BECE8_DungeonDash);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(3, 10, 60, -1, func_8010319C_1BED1C_DungeonDash);
    for (i = 0; i < 4; i++) {
        D_8010B110_1C6C90_DungeonDash[i] = -1;
    }
    for (i = 0; i < 4; i++) {
        slot = gPlayers[i].group * 2 + (rand8() & 1);
        for (j = 0; j < 4; j++) {
            if (D_8010B110_1C6C90_DungeonDash[j] == slot) {
                slot ^= 1;
            }
        }
        D_8010B110_1C6C90_DungeonDash[i] = slot;
    }
    D_8010B128_1C6CA8_DungeonDash[0] = D_8010B128_1C6CA8_DungeonDash[1] = 0;
    InitFadeIn(0, 0x10);
}

void func_80102CF8_1BE878_DungeonDash(omObjData* obj) {
    obj->func_ptr = func_801036B0_1BF230_DungeonDash;
    func_80106C3C_1C27BC_DungeonDash(0, 269.75f, 0.0f, 500.0f, -4025.0f, 17.25f, 0.0f, 0.0f);
    func_80106C3C_1C27BC_DungeonDash(1, 269.75f, 0.0f, 500.0f, -4025.0f, 17.25f, 0.0f, 0.0f);
}

void func_80102D94_1BE914_DungeonDash(omObjData* obj) {
    u8 files[2];
    s32 anim0;
    s32 anim1;
    s32 i;
    void* data;
    DDTeam* team;

    files[0] = 7;
    files[1] = 6;
    obj->func_ptr = func_801041F0_1BFD70_DungeonDash;
    data = DataRead(0x2F000B);
    anim0 = SprAnimRead(data);
    DataClose(data);
    D_8010B104_1C6C84_DungeonDash = SprCreate(2, 0);
    data = DataRead(0x2F000C);
    anim1 = SprAnimRead(data);
    DataClose(data);
    D_8010B108_1C6C88_DungeonDash = SprCreate(2, 0);
    for (i = 0; i < 2; i++) {
        team = &D_8010B068_1C6BE8_DungeonDash[i];
        team->unk14 = 0;
        team->unk1A = 0;
        team->unk8 = 0;
        team->unkE = func_80018A30_19630(files[i] | 0x2F0000, 0x2D9);
        team->unk10 = func_80027D3C_2893C(team->unkE);
        team->unk12 = func_80018A64_19664(0x2F0004, 0x6D9);
        SprAnimSet((s16)D_8010B104_1C6C84_DungeonDash, i, anim0, 0);
        func_8008225C_82E5C((s16)D_8010B104_1C6C84_DungeonDash, i, 0);
        SprAttrSet((s16)D_8010B104_1C6C84_DungeonDash, i, 0x9800);
        SprAnimSet((s16)D_8010B108_1C6C88_DungeonDash, i, anim1, 0);
        func_8008225C_82E5C((s16)D_8010B108_1C6C88_DungeonDash, i, 0);
        SprAttrSet((s16)D_8010B108_1C6C88_DungeonDash, i, 0x9000);
        func_800824B4_830B4((s16)D_8010B108_1C6C88_DungeonDash, (s16)i, 200, 0, 0, 0x100);
        SprScaleSet((s16)D_8010B108_1C6C88_DungeonDash, i, 1.2f, 1.2f);
    }
    func_80029714_2A314(D_8010B068_1C6BE8_DungeonDash[0].unkE, -250.0f, 0.0f, -625.0f);
    func_80029714_2A314(D_8010B068_1C6BE8_DungeonDash[0].unk10, -310.0f, 0.0f, -625.0f);
    func_80029714_2A314(D_8010B068_1C6BE8_DungeonDash[1].unkE, 310.0f, 0.0f, -625.0f);
    func_80029714_2A314(D_8010B068_1C6BE8_DungeonDash[1].unk10, 250.0f, 0.0f, -625.0f);
    func_800297E8_2A3E8(D_8010B068_1C6BE8_DungeonDash[0].unkE, 1.2f, 1.0f, 1.0f);
    func_800297E8_2A3E8(D_8010B068_1C6BE8_DungeonDash[0].unk10, 1.2f, 1.0f, 1.0f);
    func_800297E8_2A3E8(D_8010B068_1C6BE8_DungeonDash[1].unkE, 1.2f, 1.0f, 1.0f);
    func_800297E8_2A3E8(D_8010B068_1C6BE8_DungeonDash[1].unk10, 1.2f, 1.0f, 1.0f);
    func_80029714_2A314(D_8010B068_1C6BE8_DungeonDash[0].unk12, -280.0f, 16.0f, -700.0f);
    func_8002979C_2A39C(D_8010B068_1C6BE8_DungeonDash[0].unk12, 0.0f, 180.0f, 0.0f);
    func_80029714_2A314(D_8010B068_1C6BE8_DungeonDash[1].unk12, 280.0f, 16.0f, -700.0f);
    func_8002979C_2A39C(D_8010B068_1C6BE8_DungeonDash[1].unk12, 0.0f, 180.0f, 0.0f);
}

void func_801030CC_1BEC4C_DungeonDash(omObjData* obj) {
    if (func_8008F618_90218() == 0) {
        func_801060DC_1C1C5C_DungeonDash();
        omOvlReturnEx(1);
    }
}

void func_80103100_1BEC80_DungeonDash(omObjData* obj) {
    func_801031D0_1BED50_DungeonDash(obj, 0);
    func_80103354_1BEED4_DungeonDash(obj, 0);
}

void func_80103134_1BECB4_DungeonDash(omObjData* obj) {
    func_801031D0_1BED50_DungeonDash(obj, 1);
    func_80103354_1BEED4_DungeonDash(obj, 1);
}

void func_80103168_1BECE8_DungeonDash(omObjData* obj) {
    func_801031D0_1BED50_DungeonDash(obj, 2);
    func_80103354_1BEED4_DungeonDash(obj, 2);
}

void func_8010319C_1BED1C_DungeonDash(omObjData* obj) {
    func_801031D0_1BED50_DungeonDash(obj, 3);
    func_80103354_1BEED4_DungeonDash(obj, 3);
}

/* Puts the player into its team slot (D_8010B110) and at its start position. */
void func_801031D0_1BED50_DungeonDash(omObjData* obj, s32 player) {
    s32 member;
    s32 t;
    DDTeam* team;

    member = D_8010B110_1C6C90_DungeonDash[player];
    t = member >> 1;
    member &= 1;
    team = &D_8010B068_1C6BE8_DungeonDash[t];
    func_801060F8_1C1C78_DungeonDash(obj, team);
    team->obj[member] = obj;
    D_8010B068_1C6BE8_DungeonDash[t].player[member] = player;
    D_8010B068_1C6BE8_DungeonDash[t].unkB[member] = (u8)D_800CD438_CE038[gPlayers[player].character].unk_00;
    switch (D_8010B110_1C6C90_DungeonDash[player]) {
        case 0:
            func_8000C35C_CF5C(obj, -280.0f, 0.0f, -700.0f);
            break;
        case 1:
            func_8000C35C_CF5C(obj, -280.0f, 0.0f, -550.0f);
            break;
        case 2:
            func_8000C35C_CF5C(obj, 280.0f, 0.0f, -700.0f);
            break;
        case 3:
            func_8000C35C_CF5C(obj, 280.0f, 0.0f, -550.0f);
            break;
    }
}

void func_80103354_1BEED4_DungeonDash(omObjData* obj, s32 player) {
    s32 idle[2] = { 0x4E, 0x4F };
    s32 win[3] = { 0x55, 0x56, 0x57 };
    s32 dir;
    s32 r;
    MgWork* work;
    u8 chr;

    chr = gPlayers[player].character;
    dir = D_800CD438_CE038[chr].dir;
    obj->model[0] = LoadFormFile(dir | D_800CD438_CE038[chr].unk_10, 0x2C9);
    func_80029EDC_2AADC(obj->model[0], 1);
    obj->func_ptr = func_80105618_1C1198_DungeonDash;
    obj->rot.x = 0.0f;
    obj->rot.y = 180.0f;
    obj->rot.z = 0.0f;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
    func_80029714_2A314(obj->model[0], obj->trans.x, obj->trans.y, obj->trans.z);
    func_800297E8_2A3E8(obj->model[0], obj->scale.x, obj->scale.y, obj->scale.z);
    obj->unk_50 = func_80027154_27D54(sizeof(MgWork), 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, sizeof(MgWork));
    work = obj->unk_50;
    work->unk_E8 = func_80027154_27D54(obj->mtncnt * sizeof(MgWork), 0x7918);
    func_800B0EF0_B1AF0(work->unk_E8, 0, obj->mtncnt * sizeof(MgWork));
    work->unk_57 = gPlayers[player].port;
    work->unk_59 = player;
    work->unk_D0 = 0xFFFF;
    obj->model[8] = LoadFormFile(0xB, 0x68D);
    func_800297E8_2A3E8(obj->model[8], 1.0f, 1.0f, 2.0f);
    func_80019E84_1AA84(obj, 0, dir, 1, 0);
    func_80019E84_1AA84(obj, 1, dir | 0x29, 0, 0);
    func_80019E84_1AA84(obj, 2, dir | 0x2A, 0, 0);
    func_80019E84_1AA84(obj, 6, dir | 0x12, 1, 0x27);
    func_80019E84_1AA84(obj, 8, dir | 0x33, 2, 0);
    r = rand8() & 1;
    func_80019E84_1AA84(obj, 3, dir | idle[r], 1, 999);
    D_8010B148_1C6CC8_DungeonDash[player][0] = dir | idle[r];
    r = rand8() & 1;
    func_80019E84_1AA84(obj, 4, dir | win[0], 1, 999);
    D_8010B148_1C6CC8_DungeonDash[player][1] = dir | win[r];
    func_80019E84_1AA84(obj, 0x26, dir | 0x1C, 1, 0);
    func_80019B9C_1A79C(obj, 0);
    obj->model[1] = LoadFormFile(0xD, 0x6DD);
}

/* The game flow: intro camera, the split-screen wipe, start message, the race against the clock,
   the results (coins_mg_bonus +10 for the winners, -10 for the losers) and the fade-out. */
void func_801036B0_1BF230_DungeonDash(omObjData* obj) {
    s32 i;
    s32 w;
    f32 fw;
    DDTeam* team;

    D_8010B050_1C6BD0_DungeonDash = (D_8010B050_1C6BD0_DungeonDash + 1) % 3;
    if (D_8010A718_1C6298_DungeonDash != 0) {
        if (D_8010A718_1C6298_DungeonDash == 1) {
            obj->func_ptr = func_801030CC_1BEC4C_DungeonDash;
        }
        D_8010A718_1C6298_DungeonDash--;
    } else if (D_801011FC_101DFC == 1 && func_8008F618_90218() == 0) {
        D_8010A718_1C6298_DungeonDash = 20;
        InitFadeOut(0, (s16)D_8010A718_1C6298_DungeonDash);
        func_800794A8_7A0A8((s16)D_8010A718_1C6298_DungeonDash);
        func_80079614_7A214((s16)D_8010A718_1C6298_DungeonDash);
    }
    switch (D_8010A6E0_1C6260_DungeonDash) {
        case 0:
            func_80108308_1C3E88_DungeonDash(0, D_801013B0_101FB0[0].z);
            func_80108308_1C3E88_DungeonDash(1, D_801013B0_101FB0[1].z);
            func_80107358_1C2ED8_DungeonDash(320);
            if (func_8008F618_90218() != 0) {
                return;
            }
            if (D_8010A700_1C6280_DungeonDash == 0) {
                func_80106D2C_1C28AC_DungeonDash(0, 269.75f, 0.0f, 300.0f, -2012.5f, 0.0f, 0.0f, 0.0f, 60);
                func_80106D2C_1C28AC_DungeonDash(1, 269.75f, 0.0f, 300.0f, -2012.5f, 0.0f, 0.0f, 0.0f, 60);
                PlaySound(0x242);
            } else if (D_8010A700_1C6280_DungeonDash == 59) {
                func_80106D2C_1C28AC_DungeonDash(0, 539.5f, -280.0f, 280.0f, -700.0f, -17.25f, 0.0f, 0.0f, 20);
                func_80106D2C_1C28AC_DungeonDash(1, 539.5f, 280.0f, 280.0f, -700.0f, -17.25f, 0.0f, 0.0f, 20);
                D_8010A6E0_1C6260_DungeonDash = 1;
                D_8010A700_1C6280_DungeonDash = 19;
                for (i = 0; i < D_800FC87A_FD47A; i++) {
                    func_80029EDC_2AADC(D_800FFFD8_100BD8[i]->model[0], 3);
                }
            }
            D_8010A700_1C6280_DungeonDash++;
            break;
        case 1:
            func_80108308_1C3E88_DungeonDash(0, D_801013B0_101FB0[0].z);
            func_80108308_1C3E88_DungeonDash(1, D_801013B0_101FB0[1].z);
            if (D_8010A700_1C6280_DungeonDash == 0) {
                PlayMusic(0x26);
                D_8010A6E0_1C6260_DungeonDash = 2;
                break;
            }
            w = (D_8010A700_1C6280_DungeonDash - 1) * 160.0 / 20.0 + 160.0;
            fw = w;
            ScissorSet(0, 0.0f, 0.0f, fw, 240.0f);
            ViewportSet(0, 640.0f, 480.0f, 511.0f, w * 2, 480.0f, 511.0f);
            ScissorSet(1, fw, 0.0f, 320.0f, 240.0f);
            func_80107358_1C2ED8_DungeonDash(w);
            D_8010A700_1C6280_DungeonDash--;
            break;
        case 2:
            if (D_8010A700_1C6280_DungeonDash == 0) {
                func_800691FC_69DFC(0);
                D_8010A700_1C6280_DungeonDash = -1;
            } else if (func_80069538_6A138() == 0) {
                D_8010A6E0_1C6260_DungeonDash = 3;
            }
            break;
        case 3:
            if (--D_8010A714_1C6294_DungeonDash == 900) {
                func_800691FC_69DFC(10, 31, 160, 32);
                D_8010A708_1C6288_DungeonDash = 1;
            } else if (D_8010A714_1C6294_DungeonDash < 900 && D_8010A714_1C6294_DungeonDash != 0) {
                func_8006D4D0_6E0D0(D_8010A714_1C6294_DungeonDash / 30 + 1);
            } else if (D_8010A714_1C6294_DungeonDash == 0) {
                func_8006D4D0_6E0D0(0);
                func_8006D518_6E118();
                D_8010A708_1C6288_DungeonDash = 0;
                D_8010B144_1C6CC4_DungeonDash = 1;
                D_8010A6E0_1C6260_DungeonDash = 4;
            }
            break;
        case 4:
            switch (D_8010B120_1C6CA0_DungeonDash) {
                case 0:
                    func_800794A8_7A0A8(40);
                    func_800691FC_69DFC(0x12);
                    D_8010B120_1C6CA0_DungeonDash++;
                    break;
                case 1:
                    if (func_80069538_6A138() == 0) {
                        func_800691FC_69DFC(0x13);
                        PlayMusic(0x57);
                        D_8010B134_1C6CB4_DungeonDash = 120;
                        D_8010B130_1C6CB0_DungeonDash = 1;
                        D_8010A6E0_1C6260_DungeonDash = 7;
                    }
                    break;
            }
            break;
        case 5:
            if (D_8010A708_1C6288_DungeonDash != 0) {
                func_8006D518_6E118();
                D_8010A708_1C6288_DungeonDash = 0;
            }
            if (D_8010B120_1C6CA0_DungeonDash == 0) {
                for (i = 0; i < 2; i++) {
                    team = &D_8010B068_1C6BE8_DungeonDash[i];
                    if (team->unk14 == 13) {
                        gPlayers[team->player[0]].coins_mg_bonus += 10;
                        gPlayers[team->player[1]].coins_mg_bonus += 10;
                    } else {
                        if (gPlayers[team->player[0]].coins_mg_bonus >= 10) {
                            gPlayers[team->player[0]].coins_mg_bonus -= 10;
                        } else {
                            gPlayers[team->player[0]].coins_mg_bonus = 0;
                        }
                        if (gPlayers[team->player[1]].coins_mg_bonus >= 10) {
                            gPlayers[team->player[1]].coins_mg_bonus -= 10;
                        } else {
                            gPlayers[team->player[1]].coins_mg_bonus = 0;
                        }
                    }
                }
                D_8010B120_1C6CA0_DungeonDash++;
                D_8010A710_1C6290_DungeonDash = 120;
            } else if (func_80107484_1C3004_DungeonDash() != 0) {
                func_800691FC_69DFC(3);
                func_800794A8_7A0A8(40);
                D_8010B138_1C6CB8_DungeonDash = 40;
                func_801074BC_1C303C_DungeonDash();
                if (D_8010B124_1C6CA4_DungeonDash == 0) {
                    D_8010A6E0_1C6260_DungeonDash = 6;
                }
                func_8010676C_1C22EC_DungeonDash();
            }
            if (D_8010B124_1C6CA4_DungeonDash != 0) {
                if (++D_8010B120_1C6CA0_DungeonDash >= 60) {
                    D_8010A6E0_1C6260_DungeonDash = 8;
                }
            }
            break;
        case 6:
            if (D_8010B068_1C6BE8_DungeonDash[0].unk14 == 13) {
                ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
                ScissorSet(1, 320.0f, 240.0f, 320.0f, 240.0f);
                ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
            } else if (D_8010B068_1C6BE8_DungeonDash[1].unk14 == 13) {
                ScissorSet(0, 320.0f, 240.0f, 320.0f, 240.0f);
                ScissorSet(1, 0.0f, 0.0f, 320.0f, 240.0f);
                ViewportSet(1, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
            }
            Hu3DCamSetPerspective(0, 45.0f, 40.0f, 8000.0f);
            Hu3DCamSetPerspective(1, 45.0f, 40.0f, 8000.0f);
            func_8002C59C_2D19C(2000, 2500, 255, 255, 255);
            func_80107494_1C3014_DungeonDash();
            if (D_8010A71C_1C629C_DungeonDash != 0) {
                D_8010A71C_1C629C_DungeonDash = 0;
            }
            break;
        case 7:
            if (D_8010A71C_1C629C_DungeonDash == 0) {
                for (i = 0; i < 2; i++) {
                    team = &D_8010B068_1C6BE8_DungeonDash[i];
                    if (team->unk14 == 13) {
                        func_800691FC_69DFC(0x11, team->unkB[0], team->unkB[1]);
                        break;
                    }
                }
                D_8010A71C_1C629C_DungeonDash = 1;
                D_8010B134_1C6CB4_DungeonDash = 168;
            }
            if (D_8010B134_1C6CB4_DungeonDash <= 0) {
                if (D_8010B130_1C6CB0_DungeonDash != 0 && D_8010A71C_1C629C_DungeonDash != 0) {
                    D_8010A6E0_1C6260_DungeonDash = 8;
                }
            } else {
                D_8010B134_1C6CB4_DungeonDash--;
            }
            break;
        case 8:
            InitFadeOut(0, 20);
            func_80079614_7A214(D_8010B124_1C6CA4_DungeonDash != 0 ? 40 : 90);
            D_8010B100_1C6C80_DungeonDash = -1;
            obj->func_ptr = func_801030CC_1BEC4C_DungeonDash;
            break;
    }
    func_80106A28_1C25A8_DungeonDash();
    D_8010A704_1C6284_DungeonDash = func_80106F80_1C2B00_DungeonDash(obj, 2);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80104190_1BFD10_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_801041F0_1BFD70_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80105464_1C0FE4_DungeonDash);

__asm__(".section .rodata");
const u32 D_8010AD38_1C68B8_DungeonDash[4] = { 0 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80105618_1C1198_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80105E50_1C19D0_DungeonDash);

void func_801060DC_1C1C5C_DungeonDash(void) {
    func_80107350_1C2ED0_DungeonDash();
}

/* The player object keeps its team in work[0..3], the pointer big-endian (host hazard: a pointer in
   a 32-bit slot; MP1's port keeps the team index there instead). */
void func_801060F8_1C1C78_DungeonDash(omObjData* obj, DDTeam* team) {
    obj->work[0] = (u32)team >> 24;
    obj->work[1] = (u32)team >> 16;
    obj->work[2] = (u32)team >> 8;
    obj->work[3] = (u32)team;
}

DDTeam* func_80106118_1C1C98_DungeonDash(omObjData* obj) {
    return (DDTeam*)((obj->work[0] << 24) | (obj->work[1] << 16) | (obj->work[2] << 8) | obj->work[3]);
}

void func_80106144_1C1CC4_DungeonDash(omObjData* obj, s32 motion, f32 speed) {
    HmfModel* m;

    func_80019B9C_1A79C(obj, (u16)motion);
    m = &D_800FC834_FD434[obj->model[0]];
    m->unk44 = speed;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_801061A0_1C1D20_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_8010676C_1C22EC_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80106810_1C2390_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_801068E8_1C2468_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80106A28_1C25A8_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80106B6C_1C26EC_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80106C3C_1C27BC_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80106D2C_1C28AC_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80106E08_1C2988_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80106EC4_1C2A44_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80106F80_1C2B00_DungeonDash);
