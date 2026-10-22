#include "common.h"
#include "ovl_45.h"

s16 func_80102830_2E0F60_name_45(void) {
    return D_80110D44_2EF474_name_45[GwSystem.star_spawn_indices[GwSystem.unk_0A]];
}

void func_8010285C_2E0F8C_name_45(void) {
    s32 i;
    s32 a;
    s32 b;
    s32 temp;
    GW_SYSTEM* gw = &GwSystem;

    for (i = 0; i < 60; i++) {
        a = (u8)(rand8() % 7);
        b = (u8)(rand8() % 7);
        if (a != b) {
            if (a >= D_80110D10_2EF440_name_45[b]) {
                if (b >= D_80110D10_2EF440_name_45[a]) {
                    temp = D_80110D00_2EF430_name_45[a];
                    D_80110D00_2EF430_name_45[a] = D_80110D00_2EF430_name_45[b];
                    D_80110D00_2EF430_name_45[b] = temp;

                    temp = D_80110D10_2EF440_name_45[a];
                    D_80110D10_2EF440_name_45[a] = D_80110D10_2EF440_name_45[b];
                    D_80110D10_2EF440_name_45[b] = temp;
                }
            }
        }
    }

    for (i = 0; i < 7; i++) {
        gw->star_spawn_indices[i] = D_80110D00_2EF430_name_45[i];
    }

    if (gw->unk_1C == -1) {
        temp = 0;
    retry:
        gw->unk_1C = gw->star_spawn_indices[6 - temp];
        for (i = 0; D_80110D20_2EF450_name_45[i] != -1; i++) {
            if (gw->unk_1C == D_80110D20_2EF450_name_45[i]) {
                temp++;
                goto retry;
            }
        }
    }
}

void func_80102A44_2E1174_name_45(void) {
    u8 order[16];
    s32 i;
    GW_SYSTEM* gw = &GwSystem;

    MBArrayShuffle(order, 6);
    gw->unk_0A = 0;
    for (i = 0; i < 7; i++) {
        gw->star_spawn_indices[i] = order[i];
    }
    gw->unk_1C = gw->star_spawn_indices[6];
}

void func_80102AB0_2E11E0_name_45(void) {
    s32 temp;
    GW_SYSTEM* gw = &GwSystem;

    gw->unk_1C = gw->star_spawn_indices[gw->unk_0A];
    if (++gw->unk_0A < 7) {
        return;
    }
    temp = gw->star_spawn_indices[6];
    gw->unk_0A = 0;
    _SetFlag(0x44);
    func_8010285C_2E0F8C_name_45();
    if (temp != gw->star_spawn_indices[0]) {
        return;
    }
    temp = gw->star_spawn_indices[0];
    gw->star_spawn_indices[0] = gw->star_spawn_indices[6];
    gw->star_spawn_indices[6] = temp;
}

void func_80102B54_2E1284_name_45(void) {
    s32 i;
    GW_SYSTEM* gw = &GwSystem;

    for (i = 0; i < 7; i++) {
        _SetFlag(D_80110D24_2EF454_name_45[i]);
    }
    BoardSpaceTypeSet(D_80110D34_2EF464_name_45[gw->star_spawn_indices[gw->unk_0A]], 0xE);
    _ClearFlag(D_80110D24_2EF454_name_45[gw->star_spawn_indices[gw->unk_0A]]);
    if (gw->unk_1C != -1) {
        BoardSpaceTypeSet(D_80110D34_2EF464_name_45[gw->unk_1C], 0xF);
        func_800509C4_515C4(D_80110D34_2EF464_name_45[gw->unk_1C]);
    }
}

#ifdef NON_MATCHING
s32 func_80102C3C_2E136C_name_45(s32 space) {
    s32 i;
    s32 j;
    s16* spaces;
    GW_SYSTEM* gw = &GwSystem;

    i = 0;
    spaces = D_80110D34_2EF464_name_45;
    space = (s16)space;
    do {
        if (space == spaces[i]) {
            if (i == gw->star_spawn_indices[gw->unk_0A]) {
                gw->unk_1A = D_80110D24_2EF454_name_45[i];
                return 1;
            }
            if (i == gw->unk_1C) {
                return 2;
            }
            if (_CheckFlag(0x44)) {
                space = 7;
            } else {
                space = gw->unk_0A;
            }
            for (j = 0; j < space; j++) {
                if (i == gw->star_spawn_indices[j]) {
                    return 3;
                }
            }
            return 0;
        }
        i++;
    } while (i < 7);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_45_name/2E0F30", func_80102C3C_2E136C_name_45);
#endif

void func_80102D28_2E1458_name_45(void) {
    SpaceData* space;
    MBModel* star;
    ModelEmitterWork* emitter;
    s32 i;
    f32 scale;
    f32 rot;

    space = HuPrcCurrentGet()->user_data;
    PlaySound(0x34E);
    star = func_80043510_44110(0x19, NULL);
    star->attr |= 4;
    func_80056754_57354(star);
    func_800B3170_B3D70(&star->pos, &space->coords);
    star->jumpY = 50.0f;
    emitter = func_80049ED4_4AAD4(star, 0);
    emitter->unk18 = 0.1f;
    scale = 0.0f;
    for (i = 0; i < 6; i++) {
        HuVecCopyXYZ(&star->scale, scale, scale, scale);
        scale += 0.5f;
        HuPrcVSleep();
    }
    for (i = 0; i < 3; i++) {
        HuVecCopyXYZ(&star->scale, scale, scale, scale);
        scale -= 0.4f;
        HuPrcVSleep();
    }
    HuPrcSleep(30);
    PlaySound(0x32C);
    rot = 0.0f;
    while (1) {
        func_800B39F0_B45F0(D_800FC834_FD434[star->obj->model[0]].mtx, rot);
        rot += 20.0f;
        scale -= 0.04f;
        if (scale < 0.0f) {
            break;
        }
        HuVecCopyXYZ(&star->scale, scale, scale, scale);
        star->jumpY -= 1.2f;
        HuPrcVSleep();
    }
    func_80049F90_4AB90(emitter);
    MBModelKill(star);
    D_80113000_2F1730_name_45 = NULL;
    omDelPrcObj(NULL);
}

void func_80102F4C_2E167C_name_45(UnkMBGuideData* guide) {
    MBModel* obj;

    obj = guide->obj;
    obj->jumpVel = 4.0f;
    obj->jumpAccel = -0.6f;
    HuPrcSleep(3);
    while (obj->jumpAccel != 0.0f) {
        HuPrcVSleep();
    }
    MBMotionSet(guide->obj, 0, 2);
    func_8005B338_5BF38(guide);
}

void func_80102FFC_2E172C_name_45(void) {
    UnkMBGuideData* guide;
    SpaceData* space;
    Process* proc;
    s32 mes;
    s32 pick;
    GW_SYSTEM* gw = &GwSystem;

    pick = 0;
    D_800CCC18_CD818 = 0;
    guide = func_80050304_50F04(D_800CC6A8_CD2A8[gw->current_board_index], 0);
    guide->obj->rot.x = HuMathSin(D_800CC6C4_CD2C4[gw->current_board_index]);
    guide->obj->rot.z = func_800B7890_B8490(D_800CC6C4_CD2C4[gw->current_board_index]);
    func_8005B338_5BF38(guide);
    PlayMusic(0x11);
    func_8005AB50_5B750(guide->obj, 2, 8, D_80110D54_2EF484_name_45);
    func_80067558_68158();
    InitFadeIn(2, 16);
    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    func_80051500_52100();
    func_80053608_54208(3.0f);
    func_80102F4C_2E167C_name_45(guide);
    if (gw->unk_0A == 0 && !_CheckFlag(0x44)) {
        mes = (D_800F8D12_F9912 != 0) ? 0x6B1 : 0x6AF;
    } else {
        mes = (D_800F8D12_F9912 != 0) ? 0x6B1 : 0x6B0;
    }
    func_800890CC_89CCC(guide->amount, mes, -1, -1);
    func_8008E2DC_8EEDC(guide->amount, 1);
    PlaySound(0x11E);
    func_80057DC0_589C0(guide->amount);
    MBMotionShiftSet(guide->obj, -1, 0, 6, 2);
    func_8005B338_5BF38(guide);
    func_8008E4D0_8F0D0(guide->amount, 1);
    func_8002D4A0_2E0A0(guide->obj->obj->model[0]);
    if (D_800F8D12_F9912 != 0 && (u8)(pick = rand8() & 1) == 0) {
        space = GetSpaceData(D_80110D44_2EF474_name_45[gw->unk_1C]);
    } else {
        space = GetSpaceData(D_80110D44_2EF474_name_45[gw->star_spawn_indices[gw->unk_0A]]);
    }
    MBDCameraPos3DSet(&space->coords);
    MBCameraSpeedSet(3.5f);
    HuPrcSleep(5);
    while (func_80053998_54598() != 0) {
        HuPrcVSleep();
    }
    HuPrcSleep(5);
    MBMotionSet(guide->obj, 0, 2);
    func_8005B338_5BF38(guide);
    if (D_800F8D12_F9912 == 0) {
        proc = omAddPrcObj(func_80102D28_2E1458_name_45, 0x4800, 0, 0);
        D_80113000_2F1730_name_45 = proc;
        proc->user_data = space;
        HuPrcSleep(30);
    } else {
        D_80113000_2F1730_name_45 = NULL;
    }
    D_800F920C_F9E0C[guide->amount].unk_20 = 1;
    HuPrcVSleep();
    func_8008E2DC_8EEDC(guide->amount, 1);
    func_80057DC0_589C0(guide->amount);
    MBMotionShiftSet(guide->obj, -1, 0, 6, 2);
    func_8005B338_5BF38(guide);
    func_8008E4D0_8F0D0(guide->amount, 1);
    func_8002D4A0_2E0A0(guide->obj->obj->model[0]);
    if (gw->unk_1C != -1) {
        while (D_80113000_2F1730_name_45 != NULL) {
            HuPrcVSleep();
        }
        if (D_800F8D12_F9912 != 0 && (u8)pick == 0) {
            space = GetSpaceData(D_80110D44_2EF474_name_45[gw->star_spawn_indices[gw->unk_0A]]);
        } else {
            space = GetSpaceData(D_80110D44_2EF474_name_45[gw->unk_1C]);
        }
        MBDCameraPos3DSet(&space->coords);
        MBCameraSpeedSet(3.5f);
        HuPrcSleep(5);
        while (func_80053998_54598() != 0) {
            HuPrcVSleep();
        }
        HuPrcSleep(5);
        MBMotionSet(guide->obj, 0, 2);
        func_80029FE4_2ABE4(guide->obj->obj->model[0], D_80110D5C_2EF48C_name_45[gw->current_board_index]);
        func_8005B338_5BF38(guide);
        func_8005AC6C_5B86C(guide->obj, D_80110D58_2EF488_name_45);
        D_800F920C_F9E0C[guide->amount].unk_20 = 1;
        HuPrcVSleep();
        func_8008E2DC_8EEDC(guide->amount, 1);
        func_80057DC0_589C0(guide->amount);
        func_8008E4D0_8F0D0(guide->amount, 1);
    }
    func_800794A8_7A0A8(90);
    HuPrcSleep(30);
    InitFadeOut(2, 16);
    HuPrcSleep(17);
    D_800CCC18_CD818 = 1;
    func_80067720_68320();
    func_8005057C_5117C(guide);
    func_80063178_63D78();
    omOvlReturnEx(1);
    omOvlKill();
    HuPrcVSleep();
}

void func_80103548_2E1C78_name_45(void) {
    Vec target;
    MBModel* parent;
    GW_PLAYER* player;
    MBModel* star;
    ModelEmitterWork* emitter;
    f32 scale;
    f32 rot;
    s32 i;

    parent = HuPrcCurrentGet()->user_data;
    player = BoardPlayerGet(-1);
    PlaySound(D_80110D80_2EF4B0_name_45 == 0 ? 0x355 : 0x34E);
    star = func_80043510_44110(D_80113004_2F1734_name_45 == 0 ? 0x19 : 0xD, NULL);
    star->attr |= 4;
    func_80056754_57354(star);
    HuVecCopyXYZ(&star->pos, parent->pos.x, parent->pos.y + 10.0f, parent->pos.z);
    HuVecCopyXYZ(&target, D_800C9B80_CA780->pos.x, D_800C9B80_CA780->pos.y, D_800C9B80_CA780->pos.z);
    star->jumpY = 15.0f;
    emitter = func_80049ED4_4AAD4(star, 0);
    emitter->unk18 = 0.1f;
    for (scale = 0.0f, i = 0; i < 6; i++) {
        HuVecCopyXYZ(&star->scale, scale, scale, scale);
        scale += 0.5f;
        HuPrcVSleep();
    }
    for (i = 0; i < 3; i++) {
        HuVecCopyXYZ(&star->scale, scale, scale, scale);
        scale -= 0.4f;
        HuPrcVSleep();
    }
    HuPrcSleep(20);
    PlaySound(0x32C);
    rot = 0.0f;
    HuVecCopyXYZ(&target, ((MBModel*)player->unk_24)->pos.x, ((MBModel*)player->unk_24)->pos.y - 10.0f,
                 ((MBModel*)player->unk_24)->pos.z);
    func_80056D80_57980(&star->pos, &target, &star->pos, 40);
    for (i = 0; i < 40; i++) {
        func_800B39F0_B45F0(D_800FC834_FD434[star->obj->model[0]].mtx, rot);
        rot += 20.0f;
        scale -= 0.05f;
        if (scale < 0.0f) {
            scale = 0.0f;
        }
        HuVecCopyXYZ(&star->scale, scale, scale, scale);
        HuPrcVSleep();
    }
    MBModelKill(star);
    func_80049F90_4AB90(emitter);
    func_8005670C_5730C(&((MBModel*)player->unk_24)->rot);
    if (D_80113004_2F1734_name_45 == 0) {
        MBPlayerVibrate(-1, 5);
        if (D_80110D80_2EF4B0_name_45 != 0) {
            func_80079428_7A028(0x5C);
        } else {
            PlayMusic(0x5C);
        }
        gPlayers[GwSystem.current_player_index].stars++;
        if (gPlayers[GwSystem.current_player_index].stars >= 100) {
            gPlayers[GwSystem.current_player_index].stars = 99;
        }
        MBPlayerMotionSet(-1, 6, 0);
        func_80079718_7A318(0xF5, gPlayers[GwSystem.current_player_index].character);
    } else {
        MBPlayerVibrate(-1, 5);
        func_80079428_7A028(0x5D);
        MBPlayerMotionSet(-1, 3, 0);
        func_80079718_7A318(0x111, gPlayers[GwSystem.current_player_index].character);
        HuPrcSleep(30);
    }
    HuPrcSleep(60);
    omDelPrcObj(NULL);
}

void func_80103968_2E2098_name_45(MBModel* parent) {
    Process* proc;

    D_800FC734_FD334 = 0;
    D_80113004_2F1734_name_45 = 0;
    proc = omAddPrcObj(func_80103548_2E1C78_name_45, 0x4800, 0, 0);
    proc->user_data = parent;
    HuPrcChildLink(HuPrcCurrentGet(), proc);
    HuPrcChildWatch();
    D_800FC734_FD334 = 1;
}

void func_801039E4_2E2114_name_45(MBModel* parent) {
    Process* proc;

    D_800FC734_FD334 = 0;
    D_80113004_2F1734_name_45 = 1;
    proc = omAddPrcObj(func_80103548_2E1C78_name_45, 0x4800, 0, 0);
    proc->user_data = parent;
    HuPrcChildLink(HuPrcCurrentGet(), proc);
    HuPrcChildWatch();
    D_800FC734_FD334 = 1;
}

void func_80103A64_2E2194_name_45(void) {
    D_800FA198_FAD98 = 1;
    D_800FC734_FD334 = 0;
    omPrcSetStatBit(HuPrcCurrentGet(), 0x80);
    func_80067C6C_6886C(gPlayers[GwSystem.current_player_index].port);
    omPrcResetStatBit(HuPrcCurrentGet(), 0x80);
    D_800FA198_FAD98 = 0;
    D_800FC734_FD334 = 1;
}

void func_80103AF4_2E2224_name_45(void) {
    D_800FA198_FAD98 = 1;
    D_800FC734_FD334 = 0;
    omPrcSetStatBit(HuPrcCurrentGet(), 0x80);
    func_80067C6C_6886C(gPlayers[GwSystem.current_player_index].port);
    D_800FA198_FAD98 = 0;
    D_800FC734_FD334 = 1;
}

s32 func_80103B70_2E22A0_name_45(void) {
    return rand8() / 256.0f * 100.0f;
}

void func_80103BC4_2E22F4_name_45(void) {
    while (func_80053998_54598() != 0) {
        HuPrcVSleep();
    }
    HuPrcVSleep();
    D_80113008_2F1738_name_45 = func_8004CC7C_4D87C(0, 0x92, 1);
    D_8011300C_2F173C_name_45 = func_8004CC7C_4D87C(1, 0xA0, 1);
    D_80113018_2F1748_name_45 = func_8004CC7C_4D87C(0xD, 0xAE, 1);
    D_80113010_2F1740_name_45 = func_8004CC7C_4D87C(3, 0xBC, 1);
    D_80113014_2F1744_name_45 = func_8004CC7C_4D87C(0xB, 0xCA, 1);
    HuPrcSleep(3);
    D_800FA198_FAD98 = 1;
    D_80101058_101C58 = 1;
}

void func_80103C94_2E23C4_name_45(void) {
    D_800FA198_FAD98 = 0;
    D_80101058_101C58 = 0;
    MBHelpWinKill(D_80113008_2F1738_name_45);
    MBHelpWinKill(D_8011300C_2F173C_name_45);
    MBHelpWinKill(D_80113018_2F1748_name_45);
    MBHelpWinKill(D_80113010_2F1740_name_45);
    MBHelpWinKill(D_80113014_2F1744_name_45);
}

__asm__(".section .rodata");
const u8 D_80112EC0_2F15F0_name_45[4] = { 1, 2, 4, 8 };

s32 func_80103CF4_2E2424_name_45(u8* items) {
    s32 count = 0;
    s16 sp18[4];
    u8 sp20[4];
    s32 i;
    s32 j;

    *(Unk4Bytes*)sp20 = *(Unk4Bytes*)D_80112EC0_2F15F0_name_45;
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            if (gPlayers[i].flags & 1) {
                count = func_80110908_2EF038_name_45();
                sp18[gPlayers[GwSystem.current_player_index].port] = 0x400;
            } else {
                func_8008D59C_8E19C(mbDlgWinId, sp20[gPlayers[i].port]);
                sp18[gPlayers[i].port] = -1;
            }
        } else {
            sp18[gPlayers[i].port] = 0;
        }
    }

    if (count != 0) {
        func_80089284_89E84(mbDlgWinId, 2, 2);
        for (j = 0; count != 0; j++) {
            if (--count == 0) {
                sp18[gPlayers[GwSystem.current_player_index].port] = -0x8000;
            }
            if (j == 0) {
                func_8008CFD0_8DBD0(sp18[0], sp18[1], sp18[2], sp18[3], func_80057718_58318());
            } else {
                func_8008CFD0_8DBD0(sp18[0], sp18[1], sp18[2], sp18[3], 16);
            }
        }
    } else {
        func_8008D07C_8DC7C(sp18[0], sp18[1], sp18[2], sp18[3]);
    }

    for (i = 0; i < 2; i++) {
        if (items[i] == 0) {
            func_8008D854_8E454(mbDlgWinId, i);
        }
    }

    for (i = 0;;) {
        i = func_8008BB48_8C748(mbDlgWinId, i, 0);
        if (i == -1) {
            return -1;
        }
        if (items[i] != 0) {
            return i;
        }
    }
}

s32 func_80103FB0_2E26E0_name_45(void) {
    s32 count = 0;
    s16 sp18[4];
    u8 sp20[4];
    s32 i;
    s32 j;

    *(Unk4Bytes*)sp20 = *(Unk4Bytes*)D_80112EC0_2F15F0_name_45;
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            if (gPlayers[i].flags & 1) {
                count = func_80110C84_2EF3B4_name_45();
                sp18[gPlayers[i].port] = 0x400;
            } else {
                func_8008D59C_8E19C(mbDlgWinId, sp20[gPlayers[i].port]);
                sp18[gPlayers[i].port] = -1;
            }
        } else {
            sp18[gPlayers[i].port] = 0;
        }
    }

    if (count != 0) {
        func_80089284_89E84(mbDlgWinId, 2, 2);
        for (j = 0; count != 0; j++) {
            if (--count == 0) {
                sp18[gPlayers[GwSystem.current_player_index].port] = -0x8000;
            }
            if (j == 0) {
                func_8008CFD0_8DBD0(sp18[0], sp18[1], sp18[2], sp18[3], func_80057718_58318());
            } else {
                func_8008CFD0_8DBD0(sp18[0], sp18[1], sp18[2], sp18[3], 16);
            }
        }
    } else {
        func_8008D07C_8DC7C(sp18[0], sp18[1], sp18[2], sp18[3]);
    }
    return func_8008BB48_8C748(mbDlgWinId, 0, 1);
}

s32 func_801041D4_2E2904_name_45(void) {
    s32 com = 0;
    s16 sp18[4];
    u8 sp20[4];
    s32 i;

    *(Unk4Bytes*)sp20 = *(Unk4Bytes*)D_80112EC0_2F15F0_name_45;
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            if (gPlayers[i].flags & 1) {
                com = 1;
                sp18[gPlayers[i].port] = -0x8000;
            } else {
                func_8008D59C_8E19C(mbDlgWinId, sp20[gPlayers[i].port]);
                sp18[gPlayers[i].port] = -1;
            }
        } else {
            sp18[gPlayers[i].port] = 0;
        }
    }

    if (com != 0) {
        func_80089284_89E84(mbDlgWinId, 2, 2);
        func_8008CFD0_8DBD0(sp18[0], sp18[1], sp18[2], sp18[3], func_80057718_58318());
    } else {
        func_8008D07C_8DC7C(sp18[0], sp18[1], sp18[2], sp18[3]);
    }
    return func_8008BB48_8C748(mbDlgWinId, 0, 1);
}

void func_80104380_2E2AB0_name_45(void) {
    s32 i;
    s32 turnBand;
    s32 coinBand;

    for (i = 0; i < 4; i++) {
        if (i != GwSystem.current_player_index && gPlayers[i].stars != 0) {
            break;
        }
    }
    if (i != 4 && gPlayers[GwSystem.current_player_index].coins >= 50) {
        if (GwSystem.total_turns == GwSystem.current_turn) {
            D_80113040_2F1770_name_45 = 1;
            return;
        }
        if (GwSystem.current_turn < 10) {
            turnBand = 0;
        } else if (GwSystem.current_turn < 30) {
            turnBand = 1;
        } else {
            turnBand = 2;
        }
        if (gPlayers[GwSystem.current_player_index].coins < 61) {
            coinBand = 0;
        } else if (gPlayers[GwSystem.current_player_index].coins < 71) {
            coinBand = 1;
        } else {
            coinBand = (gPlayers[GwSystem.current_player_index].coins < 101) ? 2 : 3;
        }
        if (func_80103B70_2E22A0_name_45() < D_80110D84_2EF4B4_name_45[turnBand][coinBand]) {
            D_80113040_2F1770_name_45 = 1;
        } else {
            goto coins;
        }
    }
    if (D_80113040_2F1770_name_45 == 1) {
        return;
    }
coins:
    for (i = 0; i < 4; i++) {
        if (i != GwSystem.current_player_index && gPlayers[i].coins != 0) {
            break;
        }
    }
    if (i != 4) {
        D_80113040_2F1770_name_45 = 0;
    } else {
        D_80113040_2F1770_name_45 = 2;
    }
}

s32 func_801045C0_2E2CF0_name_45(void) {
    s32 flags[4] = { 0, 0, 0, 0 };
    s32 i;
    s32 coins;
    s32 min;

    if (GwSystem.current_player_index != D_80113030_2F1760_name_45[0]) {
        coins = gPlayers[D_80113030_2F1760_name_45[0]].coins;
        i = 1;
        flags[0] = 1;
    } else {
        coins = gPlayers[D_80113030_2F1760_name_45[1]].coins;
        i = 2;
        flags[1] = 1;
    }
    for (; i < 4; i++) {
        if (GwSystem.current_player_index != D_80113030_2F1760_name_45[i]
            && gPlayers[D_80113030_2F1760_name_45[i]].coins + 5 >= coins) {
            flags[i] = 1;
        }
    }
    min = 4;
    for (i = 0; i < 4; i++) {
        if (flags[i] != 0 && func_80059FD0_5ABD0(D_80113030_2F1760_name_45[i]) < min) {
            min = func_80059FD0_5ABD0(D_80113030_2F1760_name_45[i]);
        }
    }
    return min;
}

#ifdef NON_MATCHING
void func_80104778_2E2EA8_name_45(void) {
    s32 cand[4];
    s32 count;
    s32 i;
    s32 r;

    r = func_80103B70_2E22A0_name_45();
    switch (D_80113040_2F1770_name_45) {
    case 1:
        if (GwSystem.total_turns < GwSystem.current_turn + 5) {
            switch (func_80059FD0_5ABD0(GwSystem.current_player_index)) {
            case 0:
                if (r >= 95 && gPlayers[D_80113020_2F1750_name_45[2]].stars < 2) {
                    if (gPlayers[D_80113020_2F1750_name_45[2]].stars != 0) {
                        D_80113048_2F1778_name_45 = 2;
                        break;
                    }
                }
                D_80113048_2F1778_name_45 = 1;
                break;
            case 1:
                if (r >= 95 && gPlayers[D_80113020_2F1750_name_45[2]].stars != 0) {
                    D_80113048_2F1778_name_45 = 2;
                } else {
                    D_80113048_2F1778_name_45 = 0;
                }
                break;
            case 2:
                if (r >= 95 && gPlayers[D_80113020_2F1750_name_45[1]].stars != 0) {
                    D_80113048_2F1778_name_45 = 1;
                } else {
                    D_80113048_2F1778_name_45 = 0;
                }
                break;
            case 3:
                if (r > 94 && gPlayers[D_80113020_2F1750_name_45[1]].stars != 0) {
                    D_80113048_2F1778_name_45 = 1;
                } else {
                    D_80113048_2F1778_name_45 = 0;
                }
                break;
            }
        } else {
            switch (func_80059FD0_5ABD0(GwSystem.current_player_index)) {
            case 0:
                if (r >= 80 && gPlayers[D_80113020_2F1750_name_45[2]].stars < 2) {
                    if (gPlayers[D_80113020_2F1750_name_45[2]].stars != 0) {
                        D_80113048_2F1778_name_45 = 2;
                        break;
                    }
                }
                D_80113048_2F1778_name_45 = 1;
                break;
            case 1:
                if (r >= 90 && gPlayers[D_80113020_2F1750_name_45[2]].stars != 0) {
                    D_80113048_2F1778_name_45 = 2;
                } else {
                    D_80113048_2F1778_name_45 = 0;
                }
                break;
            case 2:
                if (r >= 90 && gPlayers[D_80113020_2F1750_name_45[1]].stars != 0) {
                    D_80113048_2F1778_name_45 = 1;
                } else {
                    D_80113048_2F1778_name_45 = 0;
                }
                break;
            case 3:
                if (r >= 95 && gPlayers[D_80113020_2F1750_name_45[1]].stars != 0) {
                    D_80113048_2F1778_name_45 = 1;
                } else {
                    D_80113048_2F1778_name_45 = 0;
                }
                break;
            }
        }
        break;
    case 0:
        count = 0;
        for (i = 0; i < 4; i++) {
            cand[i] = 0;
        }
        if (count == 0 || GwSystem.total_turns == GwSystem.current_turn
            || (GwSystem.total_turns < GwSystem.current_turn + 5 && func_80103B70_2E22A0_name_45() < 80)
            || func_80103B70_2E22A0_name_45() < 40) {
            if (GwSystem.total_turns < GwSystem.current_turn + 5) {
                if (func_80059FD0_5ABD0(GwSystem.current_player_index) == 0) {
                    if (gPlayers[D_80113020_2F1750_name_45[1]].coins == 0) {
                        goto steal;
                    }
                    if (gPlayers[D_80113020_2F1750_name_45[0]].stars == gPlayers[D_80113020_2F1750_name_45[1]].stars) {
                        goto one;
                    }
                    if (r < 85) {
                        D_80113048_2F1778_name_45 = 1;
                        return;
                    }
                    goto steal;
                }
                if (gPlayers[D_80113020_2F1750_name_45[0]].coins == 0) {
                    goto steal;
                }
                if (gPlayers[D_80113020_2F1750_name_45[0]].stars - 1 <= gPlayers[D_80113020_2F1750_name_45[1]].stars) {
                    if (r < 80) {
                        goto zero;
                    }
                    goto steal;
                }
                if (gPlayers[D_80113020_2F1750_name_45[0]].stars - 2 == gPlayers[D_80113020_2F1750_name_45[1]].stars) {
                    if (r < 85) {
                        goto zero;
                    }
                    goto steal;
                }
                if (r < 95) {
                    goto zero;
                }
                goto steal;
            }
            if (func_80059FD0_5ABD0(GwSystem.current_player_index) == 0) {
                if (gPlayers[D_80113020_2F1750_name_45[1]].coins == 0) {
                    goto steal;
                }
                if (gPlayers[D_80113020_2F1750_name_45[0]].stars != gPlayers[D_80113020_2F1750_name_45[1]].stars
                    && r >= 35) {
                    goto steal;
                }
            one:
                D_80113048_2F1778_name_45 = 1;
                return;
            }
            if (gPlayers[D_80113020_2F1750_name_45[0]].coins == 0) {
                goto steal;
            }
            if (gPlayers[D_80113020_2F1750_name_45[0]].stars - 1 <= gPlayers[D_80113020_2F1750_name_45[1]].stars) {
                if (r < 60) {
                    goto zero;
                }
                goto steal;
            }
            if (gPlayers[D_80113020_2F1750_name_45[0]].stars - 2 == gPlayers[D_80113020_2F1750_name_45[1]].stars) {
                if (r < 75) {
                    goto zero;
                }
                goto steal;
            }
            if (r >= 80) {
                goto steal;
            }
        zero:
            D_80113048_2F1778_name_45 = 0;
            return;
        steal:
            D_80113048_2F1778_name_45 = func_801045C0_2E2CF0_name_45();
            return;
        }
        for (i = 0; i < 4; i++) {
            if (cand[D_80113020_2F1750_name_45[i]] != 0) {
                if (--count == 0) {
                    D_80113048_2F1778_name_45 = i;
                    return;
                }
            }
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_45_name/2E0F30", func_80104778_2E2EA8_name_45);
#endif

#ifdef NON_MATCHING
void func_80104F7C_2E36AC_name_45(void) {
    s32 starRankCount[4];
    s32 coinRankCount[4];
    s32 i;
    s32 j;
    s32 rank;
    s32 coinRank;

    for (i = 0; i < 4; i++) {
        starRankCount[i] = 0;
        coinRankCount[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        starRankCount[func_80059FD0_5ABD0(i)]++;
        coinRank = 0;
        for (j = 0; j < 4; j++) {
            if (i != j) {
                coinRank += gPlayers[i].coins < gPlayers[j].coins;
            }
        }
        coinRankCount[coinRank]++;
    }
    for (i = 0; i < 4; i++) {
        D_80113020_2F1750_name_45[i] = -1;
        D_80113030_2F1760_name_45[i] = -1;
    }
    for (i = 0; i < 4; i++) {
        rank = func_80059FD0_5ABD0(i);
    starSlot:
        if (D_80113020_2F1750_name_45[rank] != -1) {
            rank++;
            goto starSlot;
        }
        D_80113020_2F1750_name_45[rank] = i;
        coinRank = 0;
        for (j = 0; j < 4; j++) {
            if (i != j) {
                coinRank += gPlayers[i].coins < gPlayers[j].coins;
            }
        }
    coinSlot:
        if (D_80113030_2F1760_name_45[coinRank] != -1) {
            coinRank++;
            goto coinSlot;
        }
        D_80113030_2F1760_name_45[coinRank] = i;
    }
    D_80113040_2F1770_name_45 = D_80113044_2F1774_name_45 = D_80113048_2F1778_name_45 = -1;
    func_80104380_2E2AB0_name_45();
    if (D_80113048_2F1778_name_45 == -1) {
        func_80104778_2E2EA8_name_45();
    }
    while (starRankCount[D_80113048_2F1778_name_45] == 0) {
        D_80113048_2F1778_name_45--;
    }
    rank = func_80059FD0_5ABD0(GwSystem.current_player_index);
    if (rank == D_80113048_2F1778_name_45) {
        starRankCount[rank]--;
    }
    j = rand8() % starRankCount[D_80113048_2F1778_name_45];
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            continue;
        }
        if (D_80113048_2F1778_name_45 != func_80059FD0_5ABD0(i)) {
            continue;
        }
        if (j != 0) {
            j--;
            continue;
        }
        D_80113044_2F1774_name_45 = i;
        break;
    }
    if (D_80113040_2F1770_name_45 == 0 && gPlayers[D_80113044_2F1774_name_45].coins == 0) {
        for (i = 0; i < 4; i++) {
            if (i != GwSystem.current_player_index && gPlayers[i].coins != 0) {
                D_80113044_2F1774_name_45 = i;
                break;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_45_name/2E0F30", func_80104F7C_2E36AC_name_45);
#endif

s32 func_8010537C_2E3AAC_name_45(u8* items) {
    s32 count = 0;
    s16 sp18[4];
    u8 sp20[4];
    s32 i;
    s32 j;

    *(Unk4Bytes*)sp20 = *(Unk4Bytes*)D_80112EC0_2F15F0_name_45;
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            if (gPlayers[i].flags & 1) {
                func_80104F7C_2E36AC_name_45();
                count = D_80113040_2F1770_name_45 + 1;
                sp18[gPlayers[GwSystem.current_player_index].port] = 0x400;
            } else {
                func_8008D59C_8E19C(mbDlgWinId, sp20[gPlayers[i].port]);
                sp18[gPlayers[i].port] = -1;
            }
        } else {
            sp18[gPlayers[i].port] = 0;
        }
    }

    if (count != 0) {
        func_80089284_89E84(mbDlgWinId, 2, 2);
        for (j = 0; count != 0; j++) {
            if (--count == 0) {
                sp18[gPlayers[GwSystem.current_player_index].port] = -0x8000;
            }
            if (j == 0) {
                func_8008CFD0_8DBD0(sp18[0], sp18[1], sp18[2], sp18[3], func_80057718_58318());
            } else {
                func_8008CFD0_8DBD0(sp18[0], sp18[1], sp18[2], sp18[3], 16);
            }
        }
    } else {
        func_8008D07C_8DC7C(sp18[0], sp18[1], sp18[2], sp18[3]);
    }

    for (i = 0; i < 2; i++) {
        if (items[i] == 0) {
            func_8008D854_8E454(mbDlgWinId, i);
        }
    }

    i = 0;
    do {
        i = func_8008BB48_8C748(mbDlgWinId, i, 1);
    } while (items[i] == 0);
    return i;
}

s32 func_80105630_2E3D60_name_45(s32 arg0, u8* items) {
    s32 count = 0;
    s16 sp18[4];
    u8 sp20[4];
    s32 i;

    *(Unk4Bytes*)sp20 = *(Unk4Bytes*)D_80112EC0_2F15F0_name_45;
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            if (gPlayers[i].flags & 1) {
                count = D_80113044_2F1774_name_45;
                count += count < i;
                sp18[gPlayers[i].port] = 0x400;
            } else {
                func_8008D59C_8E19C(mbDlgWinId, sp20[gPlayers[i].port]);
                sp18[gPlayers[i].port] = -1;
            }
        } else {
            sp18[gPlayers[i].port] = 0;
        }
    }

    if (count != 0) {
        func_80089284_89E84(mbDlgWinId, 2, 2);
        while (count != 0) {
            if (--count == 0) {
                sp18[gPlayers[GwSystem.current_player_index].port] = -0x8000;
            }
            func_8008CFD0_8DBD0(sp18[0], sp18[1], sp18[2], sp18[3], 16);
        }
    } else {
        func_8008D07C_8DC7C(sp18[0], sp18[1], sp18[2], sp18[3]);
    }

    for (i = 0; i < 3; i++) {
        if (items[i] == 0) {
            func_8008D854_8E454(mbDlgWinId, i);
        }
    }

    for (i = 0;;) {
        i = func_8008BB48_8C748(mbDlgWinId, i, 0);
        if (i == -1) {
            return -1;
        }
        if (items[i] != 0) {
            return i;
        }
    }
}

void func_801058A4_2E3FD4_name_45(void) {
    GwSystem.current_board_index = 3;
    omInitObjMan(10, 0);
    omOvlGotoEx(0x3D, 0, 0x192);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_45_name/2E0F30", func_801058E0_2E4010_name_45);

void func_801059C4_2E40F4_name_45(void) {
    s32 i;
    SpaceData* from;
    Vec dir;

    omInitObjMan(0xA0, 0x28);
    func_80026DAC_279AC(1, 100, 100, 100);
    func_80026DAC_279AC(2, 200, 200, 200);
    func_80062E10_63A10(0x18, 0x43, 0x1D, 0);
    func_80055928_56528(D_80110D90_2EF4C0_name_45);
    func_80055980_56580(D_80110DA4_2EF4D4_name_45);
    from = GetSpaceData(2);
    func_80056658_57258(&from->coords, &GetSpaceData(111)->coords, &dir);
    MBMasuArrowAngleAdd(func_80042BE0_437E0(&dir) + 180.0f);
    from = GetSpaceData(3);
    func_80056658_57258(&from->coords, &GetSpaceData(110)->coords, &dir);
    MBMasuArrowAngleAdd(func_80042BE0_437E0(&dir) + 180.0f);
    from = GetSpaceData(7);
    func_80056658_57258(&from->coords, &GetSpaceData(109)->coords, &dir);
    MBMasuArrowAngleAdd(func_80042BE0_437E0(&dir) + 180.0f);
    func_8004D60C_4E20C(0, func_8010A724_2E8E54_name_45);
    func_8004D60C_4E20C(1, func_8010B3B4_2E9AE4_name_45);
    func_8004D60C_4E20C(8, func_8010B750_2E9E80_name_45);
    func_8004D60C_4E20C(2, func_8010B7C0_2E9EF0_name_45);
    func_8004D60C_4E20C(3, func_8010CB30_2EB260_name_45);
    func_8004D60C_4E20C(4, func_8010D0A8_2EB7D8_name_45);
    func_8004D60C_4E20C(5, func_8010D318_2EBA48_name_45);
    func_8004D60C_4E20C(6, func_8010BCA4_2EA3D4_name_45);
    func_8004D60C_4E20C(7, func_8010C6CC_2EADFC_name_45);
    func_8004D60C_4E20C(9, func_8010D54C_2EBC7C_name_45);
    func_8004D60C_4E20C(10, func_8010D860_2EBF90_name_45);
    func_8004D60C_4E20C(12, func_8010DED4_2EC604_name_45);
    func_8004D60C_4E20C(11, func_8010E108_2EC838_name_45);
    func_8004D60C_4E20C(13, func_8010E618_2ECD48_name_45);
    func_80044D98_45998(func_801106E4_2EEE14_name_45);
    for (i = 0; i < 7; i++) {
        func_800542E8_54EE8(i, D_80110D44_2EF474_name_45[i]);
    }
    if (_CheckFlag(0x4D)) {
        _ClearFlag(0x4D);
        if (D_800F8D12_F9912 != 0) {
            func_80102A44_2E1174_name_45();
        } else {
            func_80102AB0_2E11E0_name_45();
        }
    }
    func_80102B54_2E1284_name_45();
    func_80105EC4_2E45F4_name_45();
    func_80105E3C_2E456C_name_45();
    func_80106114_2E4844_name_45();
    func_801063DC_2E4B0C_name_45();
    func_801065A0_2E4CD0_name_45();
    func_8010676C_2E4E9C_name_45();
    func_801067E4_2E4F14_name_45();
    func_80106954_2E5084_name_45();
    func_80106A74_2E51A4_name_45();
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_45_name/2E0F30", func_80105CA4_2E43D4_name_45);

void func_80105D0C_2E443C_name_45(void) {
    func_80020070_20C70(1);
    func_801059C4_2E40F4_name_45();
    func_80066C34_67834(1);
}

void func_80105D38_2E4468_name_45(s16 arg0) {
    MBModel* obj;

    if (D_80113050_2F1780_name_45[arg0] == NULL) {
        if (D_8011304C_2F177C_name_45 == NULL) {
            obj = func_80043510_44110(0x17, NULL);
            func_80043DAC_449AC(obj);
            D_8011304C_2F177C_name_45 = obj;
        } else {
            obj = MBModelParamCreate(D_8011304C_2F177C_name_45);
        }
        D_80113050_2F1780_name_45[arg0] = obj;
        obj->attr |= 2;
        func_80056754_57354(obj);
        func_800B3170_B3D70(&obj->pos, &GetSpaceData(D_80110DF4_2EF524_name_45[arg0])->coords);
        func_80041AEC_426EC(6, obj, D_80110DB4_2EF4E4_name_45[arg0][0], D_80110DB4_2EF4E4_name_45[arg0][1]);
    }
}

void func_80105E3C_2E456C_name_45(void) {
    s32 i;

    D_8011304C_2F177C_name_45 = NULL;
    for (i = 0; i < 7; i++) {
        D_80113050_2F1780_name_45[i] = NULL;
        if (_CheckFlag(D_80110E04_2EF534_name_45[i]) == 0) {
            func_80105D38_2E4468_name_45(i);
        }
    }
}

void func_80105EC4_2E45F4_name_45(void) {
    MBModel* obj;
    GW_SYSTEM* gw = &GwSystem;

    if (gw->unk_1C != -1) {
        obj = func_80043510_44110(D_800F8D12_F9912 != 0 ? 0x17 : 0x1D, NULL);
        func_80043DAC_449AC(obj);
        D_800F64C8_F70C8 = obj;
        obj->attr |= 2;
        func_80056754_57354(obj);
        func_800B3170_B3D70(&obj->pos, &GetSpaceData(D_80110DF4_2EF524_name_45[gw->unk_1C])->coords);
        D_80110E14_2EF544_name_45 = func_80041AEC_426EC(0xB, obj, D_80110DB4_2EF4E4_name_45[gw->unk_1C][0],
                                                       D_80110DB4_2EF4E4_name_45[gw->unk_1C][1]);
    } else {
        D_800F64C8_F70C8 = NULL;
    }
}

void func_80105FAC_2E46DC_name_45(void) {
    if (D_800F64C8_F70C8 != NULL) {
        MBModelKill(D_800F64C8_F70C8);
    }
    if (D_80110E14_2EF544_name_45 != -1) {
        func_80041B40_42740(D_80110E14_2EF544_name_45);
    }
}

void func_80105FF4_2E4724_name_45(s16 arg0) {
    MBModel* obj;

    if (D_80113070_2F17A0_name_45[arg0] != NULL) {
        return;
    }
    if (D_8011306C_2F179C_name_45 == NULL) {
        obj = func_80043510_44110(8, NULL);
        func_8002D124_2DD24(obj->obj->model[0]);
        func_8002D124_2DD24(obj->shadow->model[0]);
        D_8011306C_2F179C_name_45 = obj;
    } else {
        obj = MBModelParamCreate(D_8011306C_2F179C_name_45);
    }
    MBModelDispOff(obj);
    D_80113070_2F17A0_name_45[arg0] = obj;
    obj->attr |= 2;
    obj->jumpY = 10.0f;
    func_800B3170_B3D70(&obj->pos, &GetSpaceData(D_80110E18_2EF548_name_45[arg0])->coords);
    func_80041AEC_426EC(8, obj, D_80110DD0_2EF500_name_45[arg0][0], D_80110DD0_2EF500_name_45[arg0][1]);
}

void func_80106114_2E4844_name_45(void) {
    s32 i;

    D_8011306C_2F179C_name_45 = NULL;
    for (i = 0; i < 2; i++) {
        D_80113070_2F17A0_name_45[i] = NULL;
        func_80105FF4_2E4724_name_45(i);
    }
}

void func_80106174_2E48A4_name_45(void) {
    s32 i;
    s32 j;
    s32 count;

    for (i = 0; i < 2; i++) {
        count = (D_800F8CE4_F98E4[0x1D] + 9) / 10;
        if (count > 5) {
            count = 5;
        }
        for (j = 0; j < count; j++) {
            MBModelDispOn(D_80113080_2F17B0_name_45[i * 5 + j]);
        }
        for (; j < 5; j++) {
            MBModelDispOff(D_80113080_2F17B0_name_45[i * 5 + j]);
        }
    }
}

void func_80106270_2E49A0_name_45(s16 arg0) {
    MBModel* coin;
    Vec* pos;
    s32 bank;
    s16 slot;

    if (D_80113080_2F17B0_name_45[arg0] == NULL) {
        if (D_80113078_2F17A8_name_45 == NULL) {
            coin = func_80043510_44110(0x6C, NULL);
            func_80043DAC_449AC(coin);
            D_80113078_2F17A8_name_45 = coin;
        } else {
            coin = MBModelParamCreate(D_80113078_2F17A8_name_45);
        }
        D_80113080_2F17B0_name_45[arg0] = coin;
        coin->attr |= 2;

        bank = arg0 / 5;
        pos = &coin->pos;
        func_800B3170_B3D70(pos, &GetSpaceData(D_80110E1C_2EF54C_name_45[bank])->coords);

        slot = arg0 % 5;
        HuVecAdd(pos, &D_80110E20_2EF550_name_45[slot], pos);
        coin->obj->rot.x = D_80110E5C_2EF58C_name_45[slot].x;
        coin->obj->rot.z = D_80110E5C_2EF58C_name_45[slot].z;
        MBModelDispOff(coin);
    }
}

void func_801063DC_2E4B0C_name_45(void) {
    s32 i;

    D_80113078_2F17A8_name_45 = NULL;
    for (i = 0; i < 10; i++) {
        D_80113080_2F17B0_name_45[i] = NULL;
        func_80106270_2E49A0_name_45(i);
    }
    func_80106174_2E48A4_name_45();
}

void func_80106444_2E4B74_name_45(s16 arg0) {
    MBModel* obj;
    SpaceData* space;
    char pad[4]; /* frame size, as MP3 func_80108748 (ChillyWaters) */

    if (D_801130AC_2F17DC_name_45[arg0] == NULL) {
        if (D_801130A8_2F17D8_name_45 == NULL) {
            /* D_80111AED[board * 2]: column 1 of a u8 [][2] table one byte before it */
            obj = func_80043510_44110(D_80110E9D_2EF5CD_name_45[GwSystem.current_board_index * 2], NULL);
            func_80043DAC_449AC(obj);
            D_801130A8_2F17D8_name_45 = obj;
        } else {
            obj = MBModelParamCreate(D_801130A8_2F17D8_name_45);
        }
        D_801130AC_2F17DC_name_45[arg0] = obj;
        obj->attr |= 2;
        func_80029E80_2AA80(obj->obj->model[0], 2, 1);
        func_800B3170_B3D70(&obj->pos, &GetSpaceData(D_80110E98_2EF5C8_name_45[arg0])->coords);
        space = GetSpaceData(D_80110DEC_2EF51C_name_45[arg0][0]);
        func_80056658_57258(&GetSpaceData(D_80110DEC_2EF51C_name_45[arg0][1])->coords, &space->coords, &obj->rot);
        func_80041AEC_426EC(0xC, obj, D_80110DE4_2EF514_name_45[arg0][0], D_80110DE4_2EF514_name_45[arg0][1]);
    }
}

void func_801065A0_2E4CD0_name_45(void) {
    s32 i;

    D_801130A8_2F17D8_name_45 = NULL;
    for (i = 0; i < 2; i++) {
        D_801130AC_2F17DC_name_45[i] = NULL;
        func_80106444_2E4B74_name_45(i);
    }
}

void func_80106600_2E4D30_name_45(void) {
    HuPrcSleep(D_80110EF0_2EF620_name_45[GwSystem.current_board_index]);
    PlaySound((s16)D_80110ECC_2EF5FC_name_45[GwSystem.current_board_index]);
    omDelPrcObj(NULL);
}

void func_8010665C_2E4D8C_name_45(s32 arg0) {
    func_80029E80_2AA80(D_801130AC_2F17DC_name_45[arg0]->obj->model[0], 5, 0);
    if (D_80110EA8_2EF5D8_name_45[GwSystem.current_board_index] != -1) {
        PlaySound((s16)D_80110EA8_2EF5D8_name_45[GwSystem.current_board_index]);
    }
    if (D_80110ECC_2EF5FC_name_45[GwSystem.current_board_index] != -1) {
        omAddPrcObj(func_80106600_2E4D30_name_45, 0x1000, 0, 0);
    }
}

void func_80106700_2E4E30_name_45(s32 arg0) {
    func_80029E80_2AA80(D_801130AC_2F17DC_name_45[arg0]->obj->model[0], 1, 4);
    if (D_80110F14_2EF644_name_45[GwSystem.current_board_index] != -1) {
        PlaySound((s16)D_80110F14_2EF644_name_45[GwSystem.current_board_index]);
    }
}

void func_8010676C_2E4E9C_name_45(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        func_80041B60_42760(10, &GetSpaceData(D_80110F38_2EF668_name_45[i])->coords, D_80110DD8_2EF508_name_45[i][0],
                            D_80110DD8_2EF508_name_45[i][1]);
    }
}

void func_801067E4_2E4F14_name_45(void) {
    func_80041B60_42760(9, &GetSpaceData(D_80110F3C_2EF66C_name_45)->coords, D_80110DE0_2EF510_name_45[0],
                        D_80110DE0_2EF510_name_45[1]);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_45_name/2E0F30", func_80106820_2E4F50_name_45);

void func_80106954_2E5084_name_45(void) {
    s32 i;

    D_801130B4_2F17E4_name_45 = NULL;
    for (i = 0; i < 2; i++) {
        D_801130B8_2F17E8_name_45[i] = NULL;
        if (D_800F8CE4_F98E4[i + 1] != 0) {
            func_80106820_2E4F50_name_45(i);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_45_name/2E0F30", func_801069D8_2E5108_name_45);

void func_80106A18_2E5148_name_45(void) {
    if (D_80110F4C_2EF67C_name_45 != NULL) {
        DataClose(D_80110F4C_2EF67C_name_45);
        D_80110F4C_2EF67C_name_45 = NULL;
    }
    if (D_80110F50_2EF680_name_45 != -1) {
        func_8003E964_3F564(D_80110F50_2EF680_name_45);
        D_80110F50_2EF680_name_45 = -1;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_45_name/2E0F30", func_80106A74_2E51A4_name_45);

void func_80106B58_2E5288_name_45(void) {
    struct unk_8003B8D4Struct* prompt;
    s32 dir;
    s32 i;
    s32 n;
    DecisionTreeNonLeafNode* tree;

    MBPlayerMotionSet(-1, -1, 2);
    HuPrcVSleep();
    func_80103BC4_2E22F4_name_45();
    prompt = func_80041A74_42674(GwSystem.current_player_index, D_80111428_2EFB58_name_45);
    func_800417EC_423EC(prompt, GwSystem.current_player_index, 0);
    if (PlayerIsCPU(-1) != 0) {
        if (GwSystem.current_player_index == 4) {
            tree = D_80111398_2EFAC8_name_45;
        } else {
            tree = D_80110F9C_2EF6CC_name_45;
        }
        n = func_80044800_45400(tree);
        for (i = 0; i < n; i++) {
            func_80041610_42210(prompt, -2);
        }
        func_80041610_42210(prompt, -4);
    }
    dir = DirectionPrompt(prompt);
    func_8004108C_41C8C(prompt);
    func_80103C94_2E23C4_name_45();
    if (dir == 0) {
        SetNextChainAndSpace(-1, 3, 0);
    } else {
        SetNextChainAndSpace(-1, 9, 0);
    }
    omDelPrcObj(NULL);
}

s32 func_80106C70_2E53A0_name_45(s32 arg0) {
    s32 count = 0;
    s16 sp18[4];
    u8 sp20[4];
    s32 i;
    s32 j;

    *(Unk4Bytes*)sp20 = *(Unk4Bytes*)D_80112EC0_2F15F0_name_45;
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            if (gPlayers[i].flags & 1) {
                count = 1;
                if (arg0 != 0) {
                    count = func_80044800_45400(D_80111484_2EFBB4_name_45) + 1;
                }
                sp18[gPlayers[i].port] = 0x400;
            } else {
                func_8008D59C_8E19C(mbDlgWinId, sp20[gPlayers[i].port]);
                sp18[gPlayers[i].port] = -1;
            }
        } else {
            sp18[gPlayers[i].port] = 0;
        }
    }

    if (count != 0) {
        func_80089284_89E84(mbDlgWinId, 2, 2);
        for (j = 0; count != 0; j++) {
            if (--count == 0) {
                sp18[gPlayers[GwSystem.current_player_index].port] = -0x8000;
            }
            if (j == 0) {
                func_8008CFD0_8DBD0(sp18[0], sp18[1], sp18[2], sp18[3], func_80057718_58318());
            } else {
                func_8008CFD0_8DBD0(sp18[0], sp18[1], sp18[2], sp18[3], 16);
            }
        }
    } else {
        func_8008D07C_8DC7C(sp18[0], sp18[1], sp18[2], sp18[3]);
    }
    return func_8008BB48_8C748(mbDlgWinId, 0, 1);
}

void func_80106EC8_2E55F8_name_45(void) {
    GW_SYSTEM* gw = &GwSystem;
    struct unk_8003B8D4Struct* prompt;
    void* cam;
    s32 choice;
    s32 dir;
    s32 i;
    s32 n;
    DecisionTreeNonLeafNode* tree;

    if (gPlayers[gw->current_player_index].item == 1) {
        func_80046D2C_4792C(gw->current_player_index);
        MBPlayerMotionSet(-1, -1, 2);
        func_80056C30_57830(-1, 8, 0x79);
        HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.6f));
        HuPrcChildWatch();
        MBPlayerVibrate(-1, 1);
    loop:
        MBDlgWinCreate(0x14, 0x13);
        choice = func_80106C70_2E53A0_name_45(0);
        MBDlgWinClose();
        func_80056168_56D68();
        switch (choice) {
        case 0:
            gPlayers[gw->current_player_index].item = -1;
            MBDlgWinExec(0x14, 0x14);
            func_8010665C_2E4D8C_name_45(0);
            cam = func_800672BC_67EBC(-1, 2, 5);
            HuPrcSleep(20);
            func_8006735C_67F5C(cam);
            func_80103BC4_2E22F4_name_45();
            prompt = func_80041A74_42674(GwSystem.current_player_index, D_80111440_2EFB70_name_45);
            func_800417EC_423EC(prompt, GwSystem.current_player_index, 0);
            if (PlayerIsCPU(-1) != 0) {
                if (GwSystem.current_player_index == 4) {
                    tree = D_80111374_2EFAA4_name_45;
                } else {
                    tree = D_80111068_2EF798_name_45;
                }
                n = func_80044800_45400(tree);
                for (i = 0; i < n; i++) {
                    func_80041610_42210(prompt, -2);
                }
                func_80041610_42210(prompt, -4);
            }
            dir = DirectionPrompt(prompt);
            func_8004108C_41C8C(prompt);
            func_80103C94_2E23C4_name_45();
            if (dir == 0) {
                SetNextChainAndSpace(-1, 11, 0);
            } else {
                SetNextChainAndSpace(-1, 5, 0);
                func_80106700_2E4E30_name_45(0);
            }
            break;
        case 1:
            MBDlgWinExec(0x14, 0x15);
            SetNextChainAndSpace(-1, 5, 0);
            break;
        case 2:
            func_80103A64_2E2194_name_45();
            goto loop;
        }
        func_8004655C_4715C(gw->current_player_index);
        HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.3f));
        HuPrcChildWatch();
    } else {
        SetNextChainAndSpace(-1, 5, 0);
    }
    omDelPrcObj(NULL);
}

void func_801071C0_2E58F0_name_45(void) {
    struct unk_8003B8D4Struct* prompt;
    s32 dir;
    s32 i;
    s32 n;
    DecisionTreeNonLeafNode* tree;

    MBPlayerMotionSet(-1, -1, 2);
    HuPrcVSleep();
    func_80103BC4_2E22F4_name_45();
    prompt = func_80041A74_42674(GwSystem.current_player_index, D_801114AC_2EFBDC_name_45);
    func_800417EC_423EC(prompt, GwSystem.current_player_index, 0);
    if (PlayerIsCPU(-1) != 0) {
        if (GwSystem.current_player_index == 4) {
            tree = D_801113D4_2EFB04_name_45;
        } else {
            tree = D_801110E0_2EF810_name_45;
        }
        n = func_80044800_45400(tree);
        for (i = 0; i < n; i++) {
            func_80041610_42210(prompt, -2);
        }
        func_80041610_42210(prompt, -4);
    }
    dir = DirectionPrompt(prompt);
    func_8004108C_41C8C(prompt);
    func_80103C94_2E23C4_name_45();
    if (dir == 0) {
        SetNextChainAndSpace(-1, 6, 0);
    } else {
        SetNextChainAndSpace(-1, 13, 0);
    }
    omDelPrcObj(NULL);
}

void func_801072D8_2E5A08_name_45(void) {
    GW_SYSTEM* gw = &GwSystem;
    struct unk_8003B8D4Struct* prompt;
    void* cam;
    s32 choice;
    s32 dir;
    s32 i;
    s32 n;
    DecisionTreeNonLeafNode* tree;

    if (gPlayers[gw->current_player_index].item == 1) {
        func_80046D2C_4792C(gw->current_player_index);
        MBPlayerMotionSet(-1, -1, 2);
        func_80056C30_57830(-1, 8, 0x7A);
        HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.6f));
        HuPrcChildWatch();
        MBPlayerVibrate(-1, 1);
    loop:
        MBDlgWinCreate(0x14, 0x13);
        choice = func_80106C70_2E53A0_name_45(1);
        MBDlgWinClose();
        func_80056168_56D68();
        switch (choice) {
        case 0:
            gPlayers[gw->current_player_index].item = -1;
            MBDlgWinExec(0x14, 0x14);
            func_8010665C_2E4D8C_name_45(1);
            cam = func_800672BC_67EBC(-1, 2, 5);
            HuPrcSleep(20);
            func_8006735C_67F5C(cam);
            func_80103BC4_2E22F4_name_45();
            prompt = func_80041A74_42674(GwSystem.current_player_index, D_801114C4_2EFBF4_name_45);
            func_800417EC_423EC(prompt, GwSystem.current_player_index, 0);
            if (PlayerIsCPU(-1) != 0) {
                if (GwSystem.current_player_index == 4) {
                    tree = D_80111374_2EFAA4_name_45;
                } else {
                    tree = D_80111110_2EF840_name_45;
                }
                n = func_80044800_45400(tree);
                for (i = 0; i < n; i++) {
                    func_80041610_42210(prompt, -2);
                }
                func_80041610_42210(prompt, -4);
            }
            dir = DirectionPrompt(prompt);
            func_8004108C_41C8C(prompt);
            func_80103C94_2E23C4_name_45();
            if (dir == 0) {
                SetNextChainAndSpace(-1, 16, 0);
            } else {
                SetNextChainAndSpace(-1, 19, 0);
                func_80106700_2E4E30_name_45(1);
            }
            break;
        case 1:
            MBDlgWinExec(0x14, 0x15);
            SetNextChainAndSpace(-1, 19, 0);
            break;
        case 2:
            func_80103A64_2E2194_name_45();
            goto loop;
        }
        func_8004655C_4715C(gw->current_player_index);
        HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.3f));
        HuPrcChildWatch();
    } else {
        SetNextChainAndSpace(-1, 19, 0);
    }
    omDelPrcObj(NULL);
}

void func_801075D0_2E5D00_name_45(void) {
    struct unk_8003B8D4Struct* prompt;
    s32 dir;
    s32 i;
    s32 n;
    DecisionTreeNonLeafNode* tree;

    MBPlayerMotionSet(-1, -1, 2);
    HuPrcVSleep();
    func_80103BC4_2E22F4_name_45();
    prompt = func_80041A74_42674(GwSystem.current_player_index, D_801114DC_2EFC0C_name_45);
    func_800417EC_423EC(prompt, GwSystem.current_player_index, 0);
    if (PlayerIsCPU(-1) != 0) {
        if (GwSystem.current_player_index == 4) {
            tree = D_80111404_2EFB34_name_45;
        } else {
            tree = D_8011117C_2EF8AC_name_45;
        }
        n = func_80044800_45400(tree);
        for (i = 0; i < n; i++) {
            func_80041610_42210(prompt, -2);
        }
        func_80041610_42210(prompt, -4);
    }
    dir = DirectionPrompt(prompt);
    func_8004108C_41C8C(prompt);
    func_80103C94_2E23C4_name_45();
    if (dir == 0) {
        SetNextChainAndSpace(-1, 1, 0);
    } else {
        SetNextChainAndSpace(-1, 18, 0);
    }
    omDelPrcObj(NULL);
}

void func_801076E8_2E5E18_name_45(void) {
    SetNextChainAndSpace(-1, 1, 4);
}

void func_8010770C_2E5E3C_name_45(void) {
    SetNextChainAndSpace(-1, 2, 0);
}

void func_80107730_2E5E60_name_45(void) {
    SetNextChainAndSpace(-1, 4, 0);
}

void func_80107754_2E5E84_name_45(void) {
    SetNextChainAndSpace(-1, 7, 0);
}

void func_80107778_2E5EA8_name_45(void) {
    SetNextChainAndSpace(-1, 2, 0);
}

void func_8010779C_2E5ECC_name_45(void) {
    SetNextChainAndSpace(-1, 17, 0);
}

void func_801077C0_2E5EF0_name_45(void) {
    SetNextChainAndSpace(-1, 3, 6);
}

void func_801077E4_2E5F14_name_45(void) {
    SetNextChainAndSpace(-1, 17, 0);
}

void func_80107808_2E5F38_name_45(void) {
    SetNextChainAndSpace(-1, 5, 2);
}

void func_8010782C_2E5F5C_name_45(void) {
    SetNextChainAndSpace(-1, 14, 0);
}

void func_80107850_2E5F80_name_45(void) {
    SetNextChainAndSpace(-1, 17, 0);
}

void func_80107874_2E5FA4_name_45(void) {
    SetNextChainAndSpace(-1, 14, 0);
}

void func_80107898_2E5FC8_name_45(void) {
    SetNextChainAndSpace(-1, 7, 0);
}

void func_801078BC_2E5FEC_name_45(void) {
    SetNextChainAndSpace(-1, 17, 0);
}

void func_801078E0_2E6010_name_45(void) {
    MBModel* obj;
    f32 scale;
    f32 rot;

    PlaySound(0x36C);
    obj = func_80043510_44110(0x6F, NULL);
    func_800B3170_B3D70(&obj->pos, &D_800F64C8_F70C8->pos);
    obj->pos.z += 20.0f;
    obj->pos.y += 30.0f;
    for (rot = 0.0f, scale = 1.0f; scale < 10.0f; rot += 20.0f, HuPrcVSleep(), scale += 1.0) {
        HuVecCopyXYZ(&obj->scale, scale, scale, scale);
        func_800B3B80_B4780(D_800FC834_FD434[obj->obj->model[0]].mtx, rot);
    }
    func_80105FAC_2E46DC_name_45();
    D_800F8D12_F9912 = 0;
    ChangeSpaceTextures(0);
    func_80105EC4_2E45F4_name_45();
    for (; scale >= 1.0f; rot += 20.0f, HuPrcVSleep(), scale -= 1.0) {
        HuVecCopyXYZ(&obj->scale, scale, scale, scale);
        func_800B3B80_B4780(D_800FC834_FD434[obj->obj->model[0]].mtx, rot);
    }
    MBModelKill(obj);
}

__asm__(".section .rodata");
const char D_80112EF8_2F1628_name_45[] = "%d";

#ifdef NON_MATCHING
void func_80107AE0_2E6210_name_45(void) {
    GW_SYSTEM* gw;
    s16 space;
    s32 bank;
    s32 choice;
    s32 roll;
    char buf[16];

    space = func_800558F4_564F4();
    gw = &GwSystem;
    bank = 0;
    if (gw->current_player_index != 4) {
        if ((s16)func_80102C3C_2E136C_name_45((s16)space) == 1) {
            func_80046D2C_4792C(gw->current_player_index);
            MBPlayerMotionSet(-1, -1, 2);
            func_80056C30_57830(-1, 8, func_80102830_2E0F60_name_45());
            HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.6f));
            HuPrcChildWatch();
            if (gPlayers[gw->current_player_index].turn_status != 0) {
                buf[0] = 0x18;
                buf[1] = gPlayers[gw->current_player_index].character;
                buf[2] = 0;
                func_80056368_56F68(3, 0x231, buf, 0, 0, 0, 0);
                func_80056458_57058();
                MBDlgWinClose();
                func_80056168_56D68();
            } else {
            intro:
                if (D_800F8D12_F9912 != 0) {
                    MBDlgWinExec(3, 0x22C);
                }
            }
            if (gPlayers[gw->current_player_index].stars >= 99) {
                PlaySound(0x120);
                MBDlgWinExec(3, 0x22B);
                if (D_800CCC16 != 0) {
                    func_800114E8_120E8(D_800F64B0_F70B0, 60);
                    D_800F64B0_F70B0 = -1;
                }
                goto end;
            }
            if (gPlayers[gw->current_player_index].coins >= 20) {
                PlaySound(0x11E);
            loop:
                MBDlgWinCreate(3, 0x227);
                choice = func_801041D4_2E2904_name_45();
                MBDlgWinClose();
                func_80056168_56D68();
                switch ((s16)choice) {
                case 0:
                    func_8004CA34_4D634(gw->current_player_index, -20);
                    func_800614B4_620B4(gw->current_player_index, -20);
                    HuPrcSleep(30);
                    if (bank == 0) {
                        MBDlgWinExec(3, 0x229);
                        if (D_800CCC16 != 0) {
                            func_80079464_7A064();
                            func_800114E8_120E8(D_800F64B0_F70B0, 60);
                            D_800F64B0_F70B0 = -1;
                        } else {
                            func_800794A8_7A0A8(90);
                        }
                        func_80103968_2E2098_name_45(D_8011304C_2F177C_name_45);
                        func_800573AC_57FAC();
                        func_8006706C_67C6C(2);
                        return;
                    }
                    MBDlgWinExec(3, 0x22D);
                    func_801078E0_2E6010_name_45();
                    HuPrcSleep(30);
                    func_801039E4_2E2114_name_45(D_800F64C8_F70C8);
                    MBDlgWinExec(5, 0x22E);
                    goto end;
                case 1:
                    if (D_800CCC16 != 0) {
                        func_800114E8_120E8(D_800F64B0_F70B0, 60);
                        D_800F64B0_F70B0 = -1;
                    }
                    MBDlgWinExec(3, 0x22A);
                    goto end;
                case 2:
                    func_80103A64_2E2194_name_45();
                    goto loop;
                }
            } else {
                PlaySound(0x120);
                MBDlgWinExec(3, 0x228);
                if (D_800CCC16 != 0) {
                    func_800114E8_120E8(D_800F64B0_F70B0, 60);
                    D_800F64B0_F70B0 = -1;
                }
                goto end;
            }
        } else if ((s16)func_80102C3C_2E136C_name_45((s16)space) == 2) {
            func_80046D2C_4792C(gw->current_player_index);
            MBPlayerMotionSet(-1, -1, 2);
            func_80056C30_57830(-1, 8, D_80110D44_2EF474_name_45[gw->unk_1C]);
            HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.6f));
            HuPrcChildWatch();
            if (D_800F8D12_F9912 == 0) {
                PlaySound(0x363);
            }
            if (gPlayers[gw->current_player_index].turn_status != 0) {
                if (D_800F8D12_F9912 != 0) {
                    MBDlgWinExec(3, 0x22F);
                    func_801078E0_2E6010_name_45();
                    HuPrcSleep(30);
                    MBDlgWinExec(5, 0x230);
                    func_8004CA34_4D634(gw->current_player_index, 20);
                    func_800614B4_620B4(gw->current_player_index, 20);
                } else if (D_800F8D18[0] == 0) {
                    MBDlgWinExec(5, 0x427);
                    func_8004CA34_4D634(gw->current_player_index, 20);
                    func_800614B4_620B4(gw->current_player_index, 20);
                } else {
                    sprintf(buf, D_80112EF8_2F1628_name_45, D_800F8D18[0]);
                    func_80056368_56F68(5, 0x426, buf, 0, 0, 0, 0);
                    func_80056458_57058();
                    MBDlgWinClose();
                    func_80056168_56D68();
                    func_8004CA34_4D634(gw->current_player_index, D_800F8D18[0]);
                    func_800614B4_620B4(gw->current_player_index, D_800F8D18[0]);
                    D_800F8D18[0] = 0;
                }
                HuPrcSleep(30);
            } else {
                bank = 1;
                if (D_800F8D12_F9912 != 0) {
                    goto intro;
                }
                if (gPlayers[gw->current_player_index].coins == 0) {
                    MBDlgWinExec(5, 0x422);
                } else {
                    MBDlgWinExec(5, 0x421);
                    func_80059120_59D20(D_800F64C8_F70C8, 2.0f, -0.5f);
                    func_80059158_59D58(D_800F64C8_F70C8);
                    func_80059120_59D20(D_800F64C8_F70C8, 2.0f, -0.5f);
                    func_80059158_59D58(D_800F64C8_F70C8);
                    roll = func_80103B70_2E22A0_name_45();
                    if (roll >= D_801115D4_2EFD04_name_45[func_80059FD0_5ABD0(gw->current_player_index)]) {
                        if (gPlayers[gw->current_player_index].coins >= 5) {
                            MBDlgWinExec(5, 0x423);
                            D_800F8D18[0] += 5;
                            func_8004CA34_4D634(gw->current_player_index, -5);
                            func_800614B4_620B4(gw->current_player_index, -5);
                        } else {
                            sprintf(buf, D_80112EF8_2F1628_name_45, gPlayers[gw->current_player_index].coins);
                            func_80056368_56F68(5, 0x425, buf, 0, 0, 0, 0);
                            MBDlgWinClose();
                            func_80056168_56D68();
                            D_800F8D18[0] += gPlayers[gw->current_player_index].coins;
                            func_8004CA34_4D634(gw->current_player_index, -gPlayers[gw->current_player_index].coins);
                            func_800614B4_620B4(gw->current_player_index, -gPlayers[gw->current_player_index].coins);
                        }
                        HuPrcSleep(30);
                    } else {
                        func_80056368_56F68(5, 0x424, NULL, 0, 0, 0, 0);
                        MBDlgWinClose();
                        func_8004CA34_4D634(gw->current_player_index, 5);
                        func_800614B4_620B4(gw->current_player_index, 5);
                        HuPrcSleep(30);
                        func_80056124_56D24();
                        func_80056458_57058();
                        MBDlgWinClose();
                        func_80056168_56D68();
                    }
                }
            }
        end:
            func_8004655C_4715C(gw->current_player_index);
            HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.3f));
            HuPrcChildWatch();
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_45_name/2E0F30", func_80107AE0_2E6210_name_45);
#endif

void func_80108320_2E6A50_name_45(void) {
    GW_SYSTEM* gw;
    s16 space;
    s16 coins;
    char buf[16];
    char buf2[16];

    space = func_800558F4_564F4();
    gw = &GwSystem;
    if (gw->current_player_index != 4) {
        if (func_80047DE8_489E8(gw->current_player_index) <= 0) {
            MBPlayerVibrate(-1, 3);
        }
        MBPlayerMotionSet(-1, -1, 2);
        switch (space) {
        case 12:
            func_80056C30_57830(-1, 8, 0x6C);
            break;
        case 34:
            func_80056C30_57830(-1, 8, 0x6B);
            break;
        }
        HuPrcSleep(8);
        PlaySound(0xE6);
        if (func_80047DE8_489E8(gw->current_player_index) > 0) {
            func_80046D2C_4792C(gw->current_player_index);
            coins = gPlayers[gw->current_player_index].coins;
            if ((coins != 0) & (coins < 5)) {
                sprintf(buf, D_80112EF8_2F1628_name_45, coins);
                sprintf(buf2, D_80112EF8_2F1628_name_45, D_800F8CE4_F98E4[0x1D] + gPlayers[gw->current_player_index].coins);
                func_80056368_56F68(2, 0x17, (s32)buf, (s32)buf2, 0, 0, 0);
                MBDlgWinClose();
                D_800F8CE4_F98E4[0x1D] += gPlayers[gw->current_player_index].coins;
                func_80106174_2E48A4_name_45();
                func_8004CA34_4D634(gw->current_player_index, -gPlayers[gw->current_player_index].coins);
                func_800614B4_620B4(gw->current_player_index, -gPlayers[gw->current_player_index].coins);
                HuPrcSleep(30);
                func_80056124_56D24();
            } else if (gPlayers[gw->current_player_index].coins == 0) {
                sprintf(buf, D_80112EF8_2F1628_name_45, D_800F8CE4_F98E4[0x1D]);
                func_80056368_56F68(2, 0x18, (s32)buf, 0, 0, 0, 0);
            } else {
                sprintf(buf, D_80112EF8_2F1628_name_45, D_800F8CE4_F98E4[0x1D] + 5);
                func_80056368_56F68(2, 0x16, (s32)buf, 0, 0, 0, 0);
                MBDlgWinClose();
                D_800F8CE4_F98E4[0x1D] += 5;
                func_80106174_2E48A4_name_45();
                func_8004CA34_4D634(gw->current_player_index, -5);
                func_800614B4_620B4(gw->current_player_index, -5);
                HuPrcSleep(30);
                func_80056124_56D24();
            }
            func_80056458_57058();
            MBDlgWinClose();
            func_80056168_56D68();
            func_8004655C_4715C(gw->current_player_index);
        } else if (D_800F8CE4_F98E4[0x1D] != 0) {
            sprintf(buf, D_80112EF8_2F1628_name_45, D_800F8CE4_F98E4[0x1D]);
            func_80056368_56F68(2, 0x19, (s32)buf, 0, 0, 0, 0);
            MBDlgWinClose();
            func_8004CA34_4D634(gw->current_player_index, D_800F8CE4_F98E4[0x1D]);
            func_800614B4_620B4(gw->current_player_index, D_800F8CE4_F98E4[0x1D]);
            D_800F8CE4_F98E4[0x1D] = 0;
            func_80106174_2E48A4_name_45();
            func_8005670C_5730C(&((MBModel*)BoardPlayerGet(-1)->unk_24)->rot);
            MBPlayerMotionSet(-1, 5, 0);
            func_80079718_7A318(0x103, gPlayers[gw->current_player_index].character);
            HuPrcSleep(30);
            func_80056124_56D24();
            func_80056458_57058();
            MBDlgWinClose();
            func_80056168_56D68();
        } else {
            MBDlgWinExec(2, 0x1A);
        }
    }
}

s32 func_80108754_2E6E84_name_45(s32 arg0) {
    s32 i;

    for (i = 0; i < 5; i++) {
        if (D_801130C8_2F17F8_name_45[i] != 0) {
            if (D_80111610_2EFD40_name_45[D_801130C4_2F17F4_name_45][i] == arg0) {
                return i;
            }
        }
    }
    return -1;
}

s32 func_801087C0_2E6EF0_name_45(void) {
    s32 i;

    for (i = 0; i < 5; i++) {
        if (D_80111610_2EFD40_name_45[D_801130C4_2F17F4_name_45][i] == -1) {
            break;
        }
    }
    return i;
}

#ifdef NON_MATCHING
void func_8010880C_2E6F3C_name_45(void) {
    u8 enabled[8];
    char names[5][4];
    Vec rot;
    GW_SYSTEM* gw = &GwSystem;
    GW_PLAYER* player;
    s8* item;
    void* data;
    s32 choice;
    s32 sel;
    s32 count;
    s32 band;
    s32 shop;
    s32 i;
    s16 spr;
    s16 anim;

    player = BoardPlayerGet(-1);
    if (gw->current_player_index != 4) {
        MBPlayerMotionSet(-1, -1, 2);
        func_80056C30_57830(-1, 8, 0x6F);
        HuPrcSleep(8);
        func_80046D2C_4792C(gw->current_player_index);
        PlaySound(0xE6);
        if (gw->current_turn == gw->total_turns) {
            MBDlgWinExec(1, 0x1F9);
        } else if (gPlayers[gw->current_player_index].item != -1) {
            MBDlgWinExec(1, 0x1F0);
        } else if (gPlayers[gw->current_player_index].coins < 10) {
            MBDlgWinExec(1, 0x1EF);
        } else {
        loop:
            MBDlgWinCreate(1, 0x1EE);
            choice = func_80103FB0_2E26E0_name_45();
            MBDlgWinClose();
            func_80056168_56D68();
            switch (choice) {
            case 0:
            shop:
                for (band = 0; band < 2; band++) {
                    if (gw->current_turn >= D_80111604_2EFD34_name_45[gw->current_game_length][band] &&
                        gw->current_turn < D_80111604_2EFD34_name_45[gw->current_game_length][band + 1]) {
                        break;
                    }
                }
                count = 0;
                shop = D_801115F8_2EFD28_name_45[band][func_80059FD0_5ABD0(gw->current_player_index)];
                for (i = 0; i < 5; i++) {
                    enabled[i] = 1;
                    names[i][0] = 0;
                    if (D_80111610_2EFD40_name_45[shop][i] != -1) {
                        if (D_800CC000[D_80111610_2EFD40_name_45[shop][i]] > gPlayers[gw->current_player_index].coins) {
                            enabled[i] = 0;
                            names[i][0] = 1;
                        }
                        names[i][1] = 0;
                        count++;
                    }
                }
                for (; i < 8; i++) {
                    enabled[i] = 1;
                }
                func_8008DAC0_8E6C0(0x28);
                func_80056524_57124(0x28);
                func_80056368_56F68(1, D_80111634_2EFD64_name_45[shop], names[0], (s32)names[1], (s32)names[2],
                                    (s32)names[3], (s32)names[4]);
                func_80056524_57124(0);
                D_801130C4_2F17F4_name_45 = shop;
                D_801130C8_2F17F8_name_45 = enabled;
                sel = func_80103CF4_2E2424_name_45(enabled);
                MBDlgWinClose();
                func_80056168_56D68();
                if (sel == count) {
                    D_800FC734_FD334 = 0;
                    MBItemDescExec(gw->current_player_index);
                    D_800FC734_FD334 = 1;
                    goto shop;
                }
                if ((sel == count + 1) | (sel == -1)) {
                    goto loop;
                }
                item = &D_80111610_2EFD40_name_45[shop][sel];
                func_8004CA34_4D634(gw->current_player_index, -D_800CC000[*item]);
                func_800614B4_620B4(gw->current_player_index, -D_800CC000[*item]);
                HuPrcSleep(30);
                gPlayers[gw->current_player_index].item = *item;
                spr = SprCreate(1, 5);
                data = DataRead(D_800CCBDC_CD7DC[*item]);
                anim = SprAnimRead(data);
                DataClose(data);
                SprAnimSet(spr, 0, anim, 0);
                SprPrioSet(spr, 0, 10);
                func_8008225C_82E5C(spr, 0, 0);
                SprAttrSet(spr, 0, 0x1000);
                SprPosSet(spr, 0, 160, 90);
                func_80082488_83088(spr, 0, 0);
                func_8005670C_5730C(&rot);
                func_80056B78_57778(&((MBModel*)player->unk_24)->rot, &rot, &((MBModel*)player->unk_24)->rot, 10);
                PlaySound(0x19);
                for (i = 0; i < 10; i++) {
                    func_80082488_83088(spr, 0, i * 25);
                    HuPrcVSleep();
                }
                func_80082488_83088(spr, 0, 0x100);
                MBPlayerMotionSet(-1, 5, 0);
                HuPrcSleep(5);
                func_80079718_7A318(0x103, gPlayers[gw->current_player_index].character);
                HuPrcSleep(45);
                MBPlayerMotionSet(-1, -1, 2);
                HuPrcSleep(10);
                SprAnimKill(anim);
                SprKill(spr);
                break;
            case 1:
                MBDlgWinExec(1, 0x1F1);
                break;
            case 2:
                func_80103A64_2E2194_name_45();
                goto loop;
            }
        }
        func_8004655C_4715C(gw->current_player_index);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_45_name/2E0F30", func_8010880C_2E6F3C_name_45);
#endif

void func_80108E18_2E7548_name_45(MBModel* model) {
    s32 i;

    MBModelDispOn(model);
    for (i = 0; i < 256; i += 12, HuPrcVSleep()) {
        func_8002D0A0_2DCA0(model->obj->model[0], i);
        func_8002D0A0_2DCA0(model->shadow->model[0], i);
    }
    func_8002D0A0_2DCA0(model->obj->model[0], 0xFF);
    func_8002D0A0_2DCA0(model->shadow->model[0], 0xFF);
}

void func_80108EB8_2E75E8_name_45(MBModel* model) {
    s32 i;

    for (i = 0xFF; i >= 0; i -= 0xC) {
        func_8002D0A0_2DCA0(model->obj->model[0], i);
        func_8002D0A0_2DCA0(model->shadow->model[0], i);
        HuPrcVSleep();
    }
    func_8002D0A0_2DCA0(model->obj->model[0], 0);
    func_8002D0A0_2DCA0(model->shadow->model[0], 0);
    MBModelDispOff(model);
}

#ifdef NON_MATCHING /* NON_MATCHING: float register allocation in the two sine loops (raw 58) */
/* A star flies out of the player's status window (player -1: of every other player that has
   one) and the player loses it. */
s32 func_80108F58_2E7688_name_45(s32 player) {
    s16 sprites[4];
    s32 sprite;
    void* data;
    s32 anim;
    s32 anim2;
    s32 k;
    s32 i;
    s32 j;
    s32 count;
    f32 y;

    if (player == -1) {
        data = DataRead(0xA000B);
        anim = SprAnimRead_s32(data);
        DataClose(data);
        for (i = 0; i < 4; i++) {
            if (i == GwSystem.current_player_index || gPlayers[i].stars == 0) {
                sprites[i] = -1;
            } else {
                SprAnimSet(sprites[i] = SprCreate_s32(1, 5), 0, anim, 0);
                SprPrioSet(sprites[i], 0, 10);
                func_8008225C_82E5C(sprites[i], 0, 0);
                SprAttrSet(sprites[i], 0, 0x1000);
                SprPosSet(sprites[i], 0, D_8011166C_2EFD9C_name_45[i].x, D_8011166C_2EFD9C_name_45[i].y);
                func_80082488_83088(sprites[i], 0, 0);
            }
        }
        PlaySound(0x377);
        for (j = 0; j < 17; j++) {
            for (i = 0; i < 4; i++) {
                if (sprites[i] != -1) {
                    SprPosSet(sprites[i], 0, j * D_8011168C_2EFDBC_name_45[i].x + D_8011166C_2EFD9C_name_45[i].x,
                              j * D_8011168C_2EFDBC_name_45[i].y + D_8011166C_2EFD9C_name_45[i].y);
                    func_80082488_83088(sprites[i], 0, j * 16);
                }
            }
            HuPrcVSleep();
        }
        count = 0;
        for (i = 0; i < 4; i++) {
            if (sprites[i] != -1) {
                func_80082488_83088(sprites[i], 0, 255);
                gPlayers[i].stars--;
                count++;
                MBPlayerVibrate(i, 5);
            }
        }
        PlaySound(0xE4);
        for (j = 0; j < 30; j++) {
            for (i = 0; i < 4; i++) {
                if (sprites[i] != -1) {
                    y = D_8011168C_2EFDBC_name_45[i].y * 16.0f + D_8011166C_2EFD9C_name_45[i].y;
                    SprPosSet(sprites[i], 0, D_8011168C_2EFDBC_name_45[i].x * 16.0f + D_8011166C_2EFD9C_name_45[i].x,
                              y + 2.0f * __sinf(j * 90 * (M_PI / 180.0)));
                }
            }
            HuPrcVSleep();
        }
        for (j = 16; j >= 0; j--) {
            for (i = 0; i < 4; i++) {
                if (sprites[i] != -1) {
                    SprPosSet(sprites[i], 0, j * D_8011168C_2EFDBC_name_45[i].x + D_8011166C_2EFD9C_name_45[i].x,
                              j * D_8011168C_2EFDBC_name_45[i].y + D_8011166C_2EFD9C_name_45[i].y);
                    func_80082488_83088(sprites[i], 0, j * 16);
                }
            }
            HuPrcVSleep();
        }
        for (i = 0; i < 4; i++) {
            if (sprites[i] != -1) {
                SprKill(sprites[i]);
            }
        }
        SprAnimKill(anim);
        return count;
    } else {
        sprite = SprCreate_s32(1, 5);
        data = DataRead(0xA000B);
        anim2 = SprAnimRead_s32(data);
        DataClose(data);
        SprAnimSet(sprite, 0, anim2, 0);
        SprPrioSet(sprite, 0, 10);
        func_8008225C_82E5C(sprite, 0, 0);
        SprAttrSet(sprite, 0, 0x1000);
        SprPosSet(sprite, 0, D_8011166C_2EFD9C_name_45[player].x, D_8011166C_2EFD9C_name_45[player].y);
        func_80082488_83088(sprite, 0, 0);
        PlaySound(0x377);
        for (k = 0; k < 17; k++) {
            SprPosSet(sprite, 0, k * D_8011168C_2EFDBC_name_45[player].x + D_8011166C_2EFD9C_name_45[player].x,
                      k * D_8011168C_2EFDBC_name_45[player].y + D_8011166C_2EFD9C_name_45[player].y);
            func_80082488_83088(sprite, 0, k * 16);
            HuPrcVSleep();
        }
        func_80082488_83088(sprite, 0, 255);
        gPlayers[player].stars--;
        MBPlayerVibrate(player, 5);
        PlaySound(0xE4);
        for (k = 0; k < 30; k++) {
            y = D_8011168C_2EFDBC_name_45[player].y * 16.0f + D_8011166C_2EFD9C_name_45[player].y;
            SprPosSet(sprite, 0, D_8011168C_2EFDBC_name_45[player].x * 16.0f + D_8011166C_2EFD9C_name_45[player].x,
                      y + 2.0f * __sinf(k * 90 * (M_PI / 180.0)));
            HuPrcVSleep();
        }
        for (k = 16; k >= 0; k--) {
            SprPosSet(sprite, 0, k * D_8011168C_2EFDBC_name_45[player].x + D_8011166C_2EFD9C_name_45[player].x,
                      k * D_8011168C_2EFDBC_name_45[player].y + D_8011166C_2EFD9C_name_45[player].y);
            func_80082488_83088(sprite, 0, k * 16);
            HuPrcVSleep();
        }
        SprKill(sprite);
        SprAnimKill(anim2);
        return 1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_45_name/2E0F30", func_80108F58_2E7688_name_45);
#endif

void func_80109834_2E7F64_name_45(void) {
    func_80055E60_56A60();
    omDelPrcObj(NULL);
}

#ifdef NON_MATCHING /* NON_MATCHING */
/* A star hangs above the player's status window for 150 frames while the player (or the CPU, by
   difficulty) presses A; then it returns to the window or leaves. Returns the price from the turn
   and press tables, or -1 when the player cannot pay it. */
s32 func_80109858_2E7F88_name_45(s32 player) {
    char msg[16];
    u16 star;
    u16 starAnim;
    u16 portrait;
    u16 portraitAnim;
    void* data;
    void* vib;
    s32 i;
    s32 state;
    s16 timer;
    s32 presses;
    s32 shown;
    s32 t;
    s32 frame;
    u16 alpha;
    f32 x;
    f32 y;
    f32 angle;
    s32 price;
    u32 j;

    star = SprCreate_s32(1, 5);
    data = DataRead(0xA000B);
    starAnim = SprAnimRead_s32(data);
    DataClose(data);
    SprAnimSet(star, 0, starAnim, 0);
    SprPrioSet(star, 0, 10);
    func_8008225C_82E5C(star, 0, 0);
    SprAttrSet(star, 0, 0x1000);
    SprPosSet(star, 0, D_8011166C_2EFD9C_name_45[player].x, D_8011166C_2EFD9C_name_45[player].y);
    func_80082488_83088(star, 0, 0);
    portrait = SprCreate_s32(1, 5);
    shown = 0;
    data = DataRead(D_801116AC_2EFDDC_name_45[gPlayers[player].character]);
    portraitAnim = SprAnimRead_s32(data);
    DataClose(data);
    SprAnimSet(portrait, 0, portraitAnim, 0);
    SprPrioSet(portrait, 0, 10);
    func_8008225C_82E5C(portrait, 0, 1);
    if (player & 1) {
        SprAttrSet(portrait, 0, 0x1001);
    } else {
        SprAttrSet(portrait, 0, 0x1000);
    }
    SprPosSet(portrait, 0, D_8011166C_2EFD9C_name_45[player].x - D_8011168C_2EFDBC_name_45[player].x * 16.0f - 8.0f,
              D_8011168C_2EFDBC_name_45[player].y * 16.0f + D_8011166C_2EFD9C_name_45[player].y);
    func_80082488_83088(portrait, 0, 0);
    for (i = 0; i < 17; i++) {
        SprPosSet(star, 0, i * D_8011168C_2EFDBC_name_45[player].x + D_8011166C_2EFD9C_name_45[player].x,
                  i * D_8011168C_2EFDBC_name_45[player].y + D_8011166C_2EFD9C_name_45[player].y);
        alpha = i * 16;
        func_80082488_83088(star, 0, alpha);
        func_80082488_83088(portrait, 0, alpha);
        HuPrcVSleep();
    }
    func_80082488_83088(star, 0, 255);
    func_80082488_83088(portrait, 0, 255);
    msg[0] = 0x18;
    msg[1] = gPlayers[player].character;
    msg[2] = 0;
    MBWinInsertOpen(0x6BA, msg, 0, 0, 0, 0);
    MBPlayerVibrate(player, 2);
    func_80055E3C_56A3C(player);
    presses = 0;
    state = 0;
    PlaySound(0x376);
    vib = func_800672BC_67EBC(player, 3, 5);
    timer = MBRand(10.0f) + 1;
    frame = 0;
    for (i = 0; i < 150; i++) {
        if (timer == 0) {
            PlaySound(0xE4);
            timer = MBRand(15.0f) + 30;
        }
        if (state >= 2) {
            state--;
        }
        if (state == 0) {
            y = D_8011168C_2EFDBC_name_45[player].y * 16.0f + D_8011166C_2EFD9C_name_45[player].y;
            SprPosSet(star, 0, D_8011168C_2EFDBC_name_45[player].x * 16.0f + D_8011166C_2EFD9C_name_45[player].x,
                      y + 2.0f * __sinf(i * 90 * (M_PI / 180.0)));
        } else if (state == 9) {
            x = D_8011168C_2EFDBC_name_45[player].x * 16.0f + D_8011166C_2EFD9C_name_45[player].x;
            angle = frame * 90 * (M_PI / 180.0);
            SprPosSet(star, 0, x + 2.0f * __sinf(angle),
                      D_8011168C_2EFDBC_name_45[player].y * 16.0f + D_8011166C_2EFD9C_name_45[player].y);
            x = D_8011166C_2EFD9C_name_45[player].x - 8.0f;
            SprPosSet(portrait, 0, x + 2.0f * __sinf(angle),
                      D_8011168C_2EFDBC_name_45[player].y * 16.0f + D_8011166C_2EFD9C_name_45[player].y);
            frame++;
        }
        if (gPlayers[player].flags & 1) {
            if (state == 0) {
                goto press;
            }
            if (gPlayers[player].cpu_difficulty2 == 0) {
                if (state < 7) {
                    goto press;
                }
            } else if (gPlayers[player].cpu_difficulty2 == 1) {
                if (state < 8) {
                    goto press;
                }
            } else if (state < 10) {
                goto press;
            }
        } else if (ContDStkTrg[gPlayers[player].port] & 0x8000) {
        press:
            presses++;
            state = 10;
            if (shown == 0) {
                func_800822A8_82EA8(portrait, 0, 1, 0);
                func_8008225C_82E5C(portrait, 0, 1);
                shown = 1;
                SprPosSet(portrait, 0, D_8011166C_2EFD9C_name_45[player].x - 8.0f,
                          D_8011168C_2EFDBC_name_45[player].y * 16.0f + D_8011166C_2EFD9C_name_45[player].y);
            }
        }
        if ((state == 0) & (t = (shown == 1))) {
            func_800822A8_82EA8(portrait, 0, 0, 0);
            func_8008225C_82E5C(portrait, 0, 1);
            shown = 0;
            SprPosSet(portrait, 0, D_8011166C_2EFD9C_name_45[player].x - D_8011168C_2EFDBC_name_45[player].x * 16.0f - 8.0f,
                      D_8011168C_2EFDBC_name_45[player].y * 16.0f + D_8011166C_2EFD9C_name_45[player].y);
        }
        HuPrcVSleep();
        timer--;
    }
    func_8006735C_67F5C(vib);
    omAddPrcObj(func_80109834_2E7F64_name_45, 0x1000, 0, 0);
    if (presses == 0) {
        for (i = 16; i >= 0; i -= 2) {
            SprPosSet(star, 0, i * D_8011168C_2EFDBC_name_45[player].x + D_8011166C_2EFD9C_name_45[player].x,
                      i * D_8011168C_2EFDBC_name_45[player].y + D_8011166C_2EFD9C_name_45[player].y);
            alpha = i * 16;
            func_80082488_83088(star, 0, alpha);
            func_80082488_83088(portrait, 0, alpha);
            HuPrcVSleep();
        }
    } else {
        for (i = 16; i >= -16; i -= 2) {
            SprPosSet(star, 0, i * D_8011168C_2EFDBC_name_45[player].x + D_8011166C_2EFD9C_name_45[player].x,
                      i * D_8011168C_2EFDBC_name_45[player].y + D_8011166C_2EFD9C_name_45[player].y);
            SprPosSet(portrait, 0,
                      (i - 16) * D_8011168C_2EFDBC_name_45[player].x + D_8011166C_2EFD9C_name_45[player].x - 8.0f,
                      i * D_8011168C_2EFDBC_name_45[player].y + D_8011166C_2EFD9C_name_45[player].y);
            HuPrcVSleep();
        }
        func_800822A8_82EA8(portrait, 0, 0, 0);
        func_8008225C_82E5C(portrait, 0, 1);
        for (i = 16; i >= 0; i -= 2) {
            func_80082488_83088(star, 0, i * 16);
            HuPrcVSleep();
        }
    }
    SprKill(star);
    SprAnimKill(starAnim);
    SprKill(portrait);
    SprAnimKill(portraitAnim);
    for (j = 0; j < 6; j++) {
        if (GwSystem.current_turn >= D_801116C4_2EFDF4_name_45[j].min && GwSystem.current_turn <= D_801116C4_2EFDF4_name_45[j].max) {
            break;
        }
    }
    price = D_801116C4_2EFDF4_name_45[j].value;
    for (j = 0; j < 14; j++) {
        if (presses >= D_801116D8_2EFE08_name_45[j].min && presses <= D_801116D8_2EFE08_name_45[j].max) {
            break;
        }
    }
    price -= D_801116D8_2EFE08_name_45[j].value;
    if (price >= gPlayers[player].coins) {
        price = -1;
    }
    return price;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_45_name/2E0F30", func_80109858_2E7F88_name_45);
#endif

void func_8010A594_2E8CC4_name_45(void) {
    MBModel* model;
    f32 angle;
    MBModel* parent;

    parent = HuPrcCurrentGet()->user_data;
    model = MBModelParamCreate(D_801130CC_2F17FC_name_45);
    func_800B3170_B3D70(&model->pos, &parent->pos);
    HuVecCopyXYZ(&model->scale, 2.0f, 2.0f, 2.0f);
    model->jumpY = parent->jumpY + 10.0f;
    MBModelDispOn(model);
    angle = MBRand(360.0f);
    while (1) {
        HuPrcVSleep();
        model->jumpY += 1.5;
        if ((parent->jumpY + 35.0f) <= model->jumpY) {
            break;
        }
        angle += 40.0f;
        func_800B39F0_B45F0(D_800FC834_FD434[model->obj->model[0]].mtx, angle);
    }
    MBModelKill(model);
    omDelPrcObj(NULL);
}

Process* func_8010A6E8_2E8E18_name_45(void* arg0) {
    Process* proc;

    proc = omAddPrcObj(func_8010A594_2E8CC4_name_45, 0x1000, 0, 0);
    proc->user_data = arg0;
    return proc;
}

#ifdef NON_MATCHING /* NON_MATCHING */
/* Boo: for 5 coins steal coins (a minigame decides how many) or, for 50, a star from another
   player. Boo is one of the two board Boos (spaces 0xAF, 0xB4) or, elsewhere, a temporary one. */
void func_8010A724_2E8E54_name_45(void) {
    char msgs[4][16];
    u8 items[4];
    s32 flag;
    s32 space;
    s32 boo;
    s16 cam;
    MBModel* model;
    SpaceData* spaceData;
    s16 choice;
    s16 sel;
    s32 i;
    s32 k;
    s32 amount;
    void* vib;
    f32 step;
    f32 acc;
    GW_SYSTEM* gw;

    space = func_800558F4_564F4();
    gw = &GwSystem;
    if (gw->current_player_index == 4) {
        return;
    }
    choice = 0;
    flag = func_80046D2C_4792C(gw->current_player_index);
    MBPlayerMotionSet(-1, -1, 2);
    switch ((s16)space) {
    case 9:
        boo = 0;
        cam = 0x82;
        break;
    case 5:
        boo = 1;
        cam = 0x83;
        break;
    default:
        boo = -1;
        cam = -1;
        model = MBModelParamCreate(D_8011306C_2F179C_name_45);
        MBModelDispOff(model);
        model->jumpY = 10.0f;
        spaceData = GetSpaceData(space);
        HuVecCopyXYZ(&model->pos, spaceData->coords.x, spaceData->coords.y + 10.0f, spaceData->coords.z);
        goto created;
    }
    model = D_80113070_2F17A0_name_45[boo];
created:
    PlaySound(0xEB);
    func_80108E18_2E7548_name_45(model);
    spaceData = GetSpaceData(space);
    if (cam != -1) {
        func_800446B4_452B4(model, &spaceData->coords, 10);
        func_80056C30_57830(-1, 8, cam);
        HuPrcSleep(10);
        HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.6f));
        HuPrcChildWatch();
    }
    if (gPlayers[gw->current_player_index].coins < 5) {
        MBDlgWinExec(7, 0x6B6);
    } else {
    menu:
        for (i = 0; i < 4; i++) {
            if (i != gw->current_player_index && gPlayers[i].coins != 0) {
                break;
            }
        }
        if (i == 4) {
            msgs[0][0] = 1;
            items[0] = 0;
        } else {
            msgs[0][0] = 8;
            items[0] = 1;
        }
        msgs[0][1] = 0;
        for (i = 0; i < 4; i++) {
            if (i != gw->current_player_index && gPlayers[i].stars != 0) {
                break;
            }
        }
        if (i == 4 || gPlayers[gw->current_player_index].coins < 50 || gPlayers[gw->current_player_index].stars >= 99) {
            msgs[1][0] = 1;
            items[1] = 0;
        } else {
            msgs[1][0] = 8;
            items[1] = 1;
        }
        msgs[1][1] = 0;
        items[2] = items[3] = 1;
        func_80056368_56F68(7, 0x6B5, (s32)msgs[0], (s32)msgs[1], 0, 0, 0);
        choice = func_8010537C_2E3AAC_name_45(items);
        MBDlgWinClose();
        func_80056168_56D68();
        switch (choice) {
        case 0:
        case 1:
        menu2:
            for (i = 0, k = 0; i < 4; i++) {
                if (i == gw->current_player_index) {
                    continue;
                }
                if (choice == 0) {
                    if (gPlayers[i].coins != 0) {
                        items[k] = 1;
                        goto available;
                    }
                    goto unavailable;
                } else if (gPlayers[i].stars == 0) {
                unavailable:
                    items[k] = 0;
                    msgs[k][0] = 1;
                } else {
                    items[k] = 1;
                available:
                    msgs[k][0] = 8;
                }
                msgs[k][1] = 0x18;
                msgs[k][2] = gPlayers[i].character;
                msgs[k][3] = 0;
                k++;
            }
            items[3] = 1;
            func_80056368_56F68(7, 0x6B8, (s32)msgs[0], (s32)msgs[1], (s32)msgs[2], 0, 0);
            sel = func_80105630_2E3D60_name_45(choice, items);
            MBDlgWinClose();
            func_80056168_56D68();
            if (sel == -1) {
                goto menu;
            }
            if (sel == 3) {
                if (boo == -1) {
                    func_80103AF4_2E2224_name_45();
                    D_800F851A_F911A = 1;
                    func_80078EC8_79AC8();
                } else {
                    func_80103A64_2E2194_name_45();
                }
                goto menu2;
            }
            if (choice == 0) {
                func_8004CA34_4D634(gw->current_player_index, -5);
                func_800614B4_620B4(gw->current_player_index, -5);
            } else {
                func_8004CA34_4D634(gw->current_player_index, -50);
                func_800614B4_620B4(gw->current_player_index, -50);
            }
            HuPrcSleep(30);
            func_80108EB8_2E75E8_name_45(model);
            if (choice == 0) {
                amount = func_80109858_2E7F88_name_45(D_80111660_2EFD90_name_45[gw->current_player_index][sel]);
                func_80108E18_2E7548_name_45(model);
                if (amount == -1) {
                    amount = gPlayers[D_80111660_2EFD90_name_45[gw->current_player_index][sel]].coins;
                    sprintf(msgs[0], "%d", amount);
                    func_80056368_56F68(7, 0x6BF, (s32)msgs[0], 0, 0, 0, 0);
                } else {
                    for (i = 0; i < sizeof(D_80111704_2EFE34_name_45) / sizeof(D_80111704_2EFE34_name_45[0]); i++) {
                        if (gw->current_turn >= D_80111704_2EFE34_name_45[i].turnMin
                            && gw->current_turn <= D_80111704_2EFE34_name_45[i].turnMax
                            && amount >= D_80111704_2EFE34_name_45[i].min && amount <= D_80111704_2EFE34_name_45[i].max) {
                            break;
                        }
                    }
                    sprintf(msgs[0], "%d", amount);
                    func_80056368_56F68(7, D_8011176E_2EFE9E_name_45[D_80111704_2EFE34_name_45[i].mess], (s32)msgs[0], 0,
                                        0, 0, 0);
                }
                MBDlgWinClose();
                func_80056168_56D68();
                step = amount / 90.0f;
                acc = 0.0f;
                D_801130CC_2F17FC_name_45 = func_80043510_44110(0x18, NULL);
                func_80043DAC_449AC(D_801130CC_2F17FC_name_45);
                MBModelDispOff(D_801130CC_2F17FC_name_45);
                vib = func_800672BC_67EBC(D_80111660_2EFD90_name_45[gw->current_player_index][sel], 3, 5);
                while (amount != 0) {
                    acc += step;
                    if (acc >= 1.0f) {
                        acc -= 1.0f;
                        func_8010A6E8_2E8E18_name_45(model);
                        func_800614B4_620B4(gw->current_player_index, 1);
                        func_8006135C_61F5C(D_80111660_2EFD90_name_45[gw->current_player_index][sel], -1, 0);
                        amount--;
                    }
                    HuPrcVSleep();
                }
                func_8006735C_67F5C(vib);
                HuPrcSleep(20);
                MBModelKill(D_801130CC_2F17FC_name_45);
                func_8005670C_5730C(&((MBModel*)BoardPlayerGet(-1)->unk_24)->rot);
                MBPlayerMotionSet(-1, 5, 0);
                HuPrcSleep(5);
                func_80079718_7A318(0x103, gPlayers[gw->current_player_index].character);
                HuPrcSleep(45);
            } else {
                func_80108F58_2E7688_name_45(D_80111660_2EFD90_name_45[gw->current_player_index][sel]);
                func_80108E18_2E7548_name_45(model);
                D_80110D80_2EF4B0_name_45 = 1;
                func_80103968_2E2098_name_45(model);
                D_80110D80_2EF4B0_name_45 = 0;
            }
            if (boo == -1) {
                MBPlayerMotionSet(-1, -1, 2);
            }
            break;
        case 2:
            func_80108EB8_2E75E8_name_45(model);
            MBDlgWinExec(7, 0x6B7);
            break;
        case 3:
            if (boo == -1) {
                func_80103AF4_2E2224_name_45();
                D_800F851A_F911A = 1;
                func_80078EC8_79AC8();
            } else {
                func_80103A64_2E2194_name_45();
            }
            goto menu;
        }
    }
    if (choice != 2) {
        func_80108EB8_2E75E8_name_45(model);
    }
    func_8005670C_5730C(&model->rot);
    if (boo == -1) {
        MBModelKill(model);
    }
    if (flag != 0) {
        func_8004655C_4715C(gw->current_player_index);
    }
    if (boo != -1) {
        HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.3f));
        HuPrcChildWatch();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_45_name/2E0F30", func_8010A724_2E8E54_name_45);
#endif

void func_8010B124_2E9854_name_45(void) {
    func_80106700_2E4E30_name_45(0);
}

void func_8010B140_2E9870_name_45(void) {
    func_80106700_2E4E30_name_45(1);
}

omObjData* func_8010B15C_2E988C_name_45(Vec* pos, f32 scaleSpeed, f32 fadeSpeed, s16 kill, Vec* vel) {
    MBModel* model;
    Unk3EParticle* work;
    omObjData* obj;

    obj = omAddObj(0x1F4, 0, 0, -1, func_8010B29C_2E99CC_name_45);
    work = obj->unk_50 = func_80027154_27D54(sizeof(Unk3EParticle), 0x7918);
    work->alpha = 255.0f;
    work->scaleSpeed = scaleSpeed;
    work->fadeSpeed = fadeSpeed;
    func_800B3170_B3D70(&work->vel, vel);
    model = MBModelFileCreate(0xA015C, 0, 1.0f, 0.0f, NULL);
    func_800297E8_2A3E8(model->obj->model[0], 0.0f, 0.0f, 0.0f);
    model->pos.x = pos->x;
    model->pos.y = pos->y;
    model->pos.z = pos->z;
    func_8002D124_2DD24(model->obj->model[0]);
    func_8002D0A0_2DCA0(model->obj->model[0], 0xFF);
    work->model = model;
    work->kill = kill;
    return obj;
}

void func_8010B29C_2E99CC_name_45(omObjData* obj) {
    MBModel* model;
    Unk3EParticle* work;
    f32 scale;

    work = obj->unk_50;
    model = work->model;
    HuVecAdd(&model->pos, &model->pos, &work->vel);
    scale = model->scale.z + work->scaleSpeed;
    model->scale.z = scale;
    model->scale.y = scale;
    model->scale.x = scale;
    work->alpha = work->alpha - work->fadeSpeed;
    if (work->alpha < 0.0f) {
        work->alpha = 0.0f;
        if (work->kill != 0) {
            MBModelKill(work->model);
            omDelObj(obj);
            return;
        }
        omSetStatBit(obj, 8);
    }
    func_8002D0A0_2DCA0(model->obj->model[0], work->alpha);
}

void func_8010B3B4_2E9AE4_name_45(void) {
    Vec pos;
    s16 chain;
    s16 index;
    GW_PLAYER* player;
    MBModel* lamp;
    void* vib;
    s32 angle;
    s32 i;
    GW_SYSTEM* system = &GwSystem;

    player = BoardPlayerGet(-1);
    func_8010C054_2EA784_name_45();
    lamp = func_80043510_44110(0x71, NULL);
    func_800297E8_2A3E8(lamp->obj->model[0], 0.0f, 0.0f, 0.0f);
    func_800B3170_B3D70(&lamp->pos, &((MBModel*)player->unk_24)->pos);
    for (lamp->pos.y = 100.0f; lamp->pos.y > 30.0f;) {
        lamp->pos.y -= 1.0f;
        HuPrcVSleep();
    }

    PlaySound(0x366);
    func_800114E8_120E8(D_800FA188_FAD88, 0xB4);
    vib = func_800672BC_67EBC(-1, 3, 5);

    angle = 0xB4;
    i = 0;
    while (angle < 0x438) {
        Vec particleDir[8] = {
            { 1.0f, 1.0f, 1.0f },
            { 1.0f, 2.0f, 1.0f },
            { 0.0f, 2.0f, 1.0f },
            { -1.0f, 1.0f, 1.0f },
            { -1.0f, -1.0f, 1.0f },
            { 0.0f, -1.0f, 1.0f },
            { -1.0f, 2.0f, 1.0f },
            { 1.0f, -1.0f, 1.0f },
        };

        lamp->pos.y = (2.0f * HuMathSin(angle)) + 30.0f;
        if (i & 1) {
            HuVecCopyXYZ(&pos, lamp->pos.x, lamp->pos.y, lamp->pos.z);
            pos.x -= 15.0f;
            pos.y += 15.0f;
            func_8010B15C_2E988C_name_45(&pos, 0.1f, 2.0f, 1, &particleDir[(i / 2) & 7]);
        }
        angle += 0x14;
        HuPrcVSleep();
        i++;
    }

    func_8006735C_67F5C(vib);
    func_8008F624_90224(0xFF, 0xFF, 0xFF);
    func_80054C78_55878(D_80110D34_2EF464_name_45[system->star_spawn_indices[system->unk_0A]], &chain, &index);
    player->cur_chain_index = chain;
    player->cur_space_index = index;
    player->next_chain_index = chain;
    player->next_space_index = index + 1;
    func_800650BC_65CBC();
    func_80078FF8_79BF8();

    while (1) {
        Vec particleDir2[8] = {
            { 1.0f, 1.0f, 1.0f },
            { 1.0f, 2.0f, 1.0f },
            { 0.0f, 2.0f, 1.0f },
            { -1.0f, 1.0f, 1.0f },
            { -1.0f, -1.0f, 1.0f },
            { 0.0f, -1.0f, 1.0f },
            { -1.0f, 2.0f, 1.0f },
            { 1.0f, -1.0f, 1.0f },
        };

        lamp->pos.y = (2.0f * HuMathSin(angle)) + 30.0f;
        if (i & 1) {
            HuVecCopyXYZ(&pos, lamp->pos.x, lamp->pos.y, lamp->pos.z);
            pos.x -= 15.0f;
            pos.y += 15.0f;
            func_8010B15C_2E988C_name_45(&pos, 0.1f, 2.0f, 1, &particleDir2[(i / 2) & 7]);
        }
        i++;
        HuPrcVSleep();
        angle += 0x14;
        if (angle == 0x500) {
            func_800115B4_121B4(0);
        }
    }
}

void func_8010B750_2E9E80_name_45(void) {
    GW_SYSTEM* gw = &GwSystem;

    D_800CCC16 = 1;
    func_800556F4_562F4(D_80110D34_2EF464_name_45[gw->star_spawn_indices[gw->unk_0A]], 1);
    D_800CCC16 = 0;
    if (func_800670B0_67CB0() >= 0) {
        HuPrcSleep(-1);
    }
}

void func_8010B7C0_2E9EF0_name_45(void) {
    s32 playerNo;
    GW_PLAYER* player;
    s16 space;

    playerNo = GwSystem.current_player_index;
    player = BoardPlayerGet(-1);
    func_8010C054_2EA784_name_45();
    func_80047A50_48650(playerNo);
    _SetFlag(4);
    func_80046F98_47B98(playerNo);
    func_80078FF8_79BF8();
    func_80064FF8_65BF8();
    HuPrcSleep(5);
    MBPlayerVibrate(-1, 3);
    HuPrcSleep(25);
    MBPlayerMotionSet(playerNo, 2, 0);
    func_80059120_59D20(gPlayers[playerNo].unk_24, 2.0f, -0.3f);
    HuPrcSleep(5);
    func_80047BB8_487B8(playerNo);
    func_8005DDEC_5E9EC(playerNo, -1, 0, 10, 2);
    HuPrcSleep(20);
    func_80053F7C_54B7C();
    func_8004CDE0_4D9E0();
    func_8004CE80_4DA80();
    func_8004D5B0_4E1B0();
    func_80053F54_54B54();
    _ClearFlag(4);
    func_80079848_7A448(func_80046F98_47B98(playerNo));
    func_80046EDC_47ADC(playerNo);
    func_80060210_60E10(0x19);
    while (func_800609D8_615D8()) {
        HuPrcVSleep();
    }
    MBStatusItemDispSetAll(0);
    func_80060210_60E10(0x1A);
    while (func_800609D8_615D8()) {
        HuPrcVSleep();
    }
    func_80047D78_48978(playerNo, -1);
    space = GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain_index, player->cur_space_index);
    func_800558E8_564E8(space);
    func_800556F4_562F4(space, 1);
    if (func_800670B0_67CB0() >= 0) {
        HuPrcSleep(-1);
    }
    func_80045650_46250(playerNo);
}

void func_8010B9AC_2EA0DC_name_45(void) {
    f32 x;
    f32 y;
    f32 dx;
    f32 dy;
    Unk3EWindowSlide* work;
    s32 i;

    i = 1;
    work = HuPrcCurrentGet()->user_data;
    dx = (f32)(work->x1 - work->x0) / work->frames;
    dy = (f32)(work->y1 - work->y0) / work->frames;
    func_8006296C_6356C(GwSystem.current_player_index, &x, &y);
    for (; i <= work->frames; i++) {
        if (work->sprite != -1) {
            SprPosSet(work->sprite, 0, work->x0 + dx * i, work->y0 + dy * i);
        }
        func_800629AC_635AC(GwSystem.current_player_index, dx * i + x, dy * i + y);
        HuPrcVSleep();
    }
    if (work->sprite != -1) {
        SprPosSet(work->sprite, 0, work->x1, work->y1);
    }
    func_800629AC_635AC(GwSystem.current_player_index, (work->x1 + x) - work->x0, (work->y1 + y) - work->y0);
    omDelPrcObj(NULL);
}

Process* func_8010BBF8_2EA328_name_45(s16 sprite, s16 x0, s16 y0, s16 x1, s16 y1, s16 frames) {
    Process* process;
    Unk3EWindowSlide* work;

    process = omAddPrcObj(func_8010B9AC_2EA0DC_name_45, 0x4001, 0, 0x40);
    work = process->user_data = HuMemMemoryAlloc(process->heap, sizeof(Unk3EWindowSlide));
    work->x0 = x0;
    work->y0 = y0;
    work->x1 = x1;
    work->y1 = y1;
    work->frames = frames;
    work->sprite = sprite;
    return process;
}

void func_8010BCA4_2EA3D4_name_45(void) {
    s32 sprite;
    void* data;
    s32 anim;
    s32 i;
    GW_SYSTEM* gw = &GwSystem;

    sprite = SprCreate_s32(1, 5);
    data = DataRead(D_801116AC_2EFDDC_name_45[gPlayers[gw->current_player_index].character]);
    anim = SprAnimRead_s32(data);
    DataClose(data);
    SprAnimSet(sprite, 0, anim, 0);
    SprPrioSet(sprite, 0, 10);
    func_8008225C_82E5C(sprite, 0, 1);
    if (gw->current_player_index & 1) {
        SprAttrSet(sprite, 0, 0x1001);
    } else {
        SprAttrSet(sprite, 0, 0x1000);
    }
    SprPosSet(sprite, 0, D_80111834_2EFF64_name_45[gw->current_player_index].x, D_80111834_2EFF64_name_45[gw->current_player_index].y);
    func_80082488_83088(sprite, 0, 0);
    for (i = 0; i < 17; i++) {
        func_80082488_83088(sprite, 0, i * 16);
        HuPrcVSleep();
    }
    func_80082488_83088(sprite, 0, 255);
    func_800822A8_82EA8(sprite, 0, 1, 0);
    func_8008225C_82E5C(sprite, 0, 1);
    HuPrcSleep(20);
    PlaySound(0x375);
    HuPrcChildLink(HuPrcCurrentGet(),
                   func_8010BBF8_2EA328_name_45(sprite, D_80111834_2EFF64_name_45[gw->current_player_index].x,
                                                D_80111834_2EFF64_name_45[gw->current_player_index].y,
                                                D_80111854_2EFF84_name_45[gw->current_player_index].x,
                                                D_80111854_2EFF84_name_45[gw->current_player_index].y, 30));
    HuPrcChildWatch();
    HuPrcSleep(10);
    func_800822A8_82EA8(sprite, 0, 0, 0);
    func_8008225C_82E5C(sprite, 0, 1);
    for (i = 1; i < 10; i++) {
        func_800629F0_635F0(gw->current_player_index, 255 - i * 25);
        func_800628C0_634C0(gw->current_player_index, 0, 2.0f);
        HuPrcVSleep();
    }
    func_800629F0_635F0(gw->current_player_index, 0);
    MBPlayerMotionSet(-1, 5, 0);
    func_80079718_7A318(0x103, gPlayers[gw->current_player_index].character);
    HuPrcSleep(50);
    MBPlayerMotionSet(-1, -1, 2);
    SprKill(sprite);
    SprAnimKill(anim);
}

void func_8010C054_2EA784_name_45(void) {
    s32 sprite;
    void* data;
    s32 anim;
    s32 i;
    s32 alpha;
    GW_SYSTEM* gw = &GwSystem;

    sprite = SprCreate_s32(1, 5);
    data = DataRead(D_801116AC_2EFDDC_name_45[gPlayers[gw->current_player_index].character]);
    anim = SprAnimRead_s32(data);
    DataClose(data);
    SprAnimSet(sprite, 0, anim, 0);
    SprPrioSet(sprite, 0, 10);
    func_8008225C_82E5C(sprite, 0, 1);
    if (gw->current_player_index & 1) {
        SprAttrSet(sprite, 0, 0x1001);
    } else {
        SprAttrSet(sprite, 0, 0x1000);
    }
    SprPosSet(sprite, 0, D_80111834_2EFF64_name_45[gw->current_player_index].x,
              D_80111834_2EFF64_name_45[gw->current_player_index].y);
    func_80082488_83088(sprite, 0, 0);
    for (i = 0; i < 17; i++) {
        func_80082488_83088(sprite, 0, i * 16);
        HuPrcVSleep();
    }
    func_80082488_83088(sprite, 0, 255);
    func_800822A8_82EA8(sprite, 0, 1, 0);
    func_8008225C_82E5C(sprite, 0, 1);
    HuPrcSleep(20);
    PlaySound(0x375);
    func_8010BBF8_2EA328_name_45(sprite, D_80111834_2EFF64_name_45[gw->current_player_index].x,
                                 D_80111834_2EFF64_name_45[gw->current_player_index].y,
                                 D_80111874_2EFFA4_name_45[gw->current_player_index].x,
                                 D_80111874_2EFFA4_name_45[gw->current_player_index].y, 30);
    HuPrcSleep(20);
    for (i = 1; i < 10; i++) {
        alpha = 255 - i * 25;
        func_800629F0_635F0(gw->current_player_index, alpha);
        func_80082488_83088(sprite, 0, alpha);
        HuPrcVSleep();
    }
    func_800629F0_635F0(gw->current_player_index, 0);
    func_80082488_83088(sprite, 0, 0);
    HuPrcSleep(2);
    SprKill(sprite);
    SprAnimKill(anim);
}

void func_8010C3A0_2EAAD0_name_45(void) {
    s32 sprite;
    void* data;
    s32 anim;
    s32 i;
    GW_SYSTEM* gw = &GwSystem;

    sprite = SprCreate_s32(1, 5);
    data = DataRead(D_801116AC_2EFDDC_name_45[gPlayers[gw->current_player_index].character]);
    anim = SprAnimRead_s32(data);
    DataClose(data);
    SprAnimSet(sprite, 0, anim, 0);
    SprPrioSet(sprite, 0, 10);
    func_8008225C_82E5C(sprite, 0, 1);
    if (gw->current_player_index & 1) {
        SprAttrSet(sprite, 0, 0x1001);
    } else {
        SprAttrSet(sprite, 0, 0x1000);
    }
    SprPosSet(sprite, 0, D_80111894_2EFFC4_name_45[gw->current_player_index].x, D_80111894_2EFFC4_name_45[gw->current_player_index].y);
    func_80082488_83088(sprite, 0, 0);
    for (i = 0; i < 17; i++) {
        func_80082488_83088(sprite, 0, i * 16);
        HuPrcVSleep();
    }
    func_80082488_83088(sprite, 0, 255);
    func_800822A8_82EA8(sprite, 0, 1, 0);
    func_8008225C_82E5C(sprite, 0, 1);
    HuPrcSleep(20);
    PlaySound(0x375);
    HuPrcChildLink(HuPrcCurrentGet(),
                   func_8010BBF8_2EA328_name_45(sprite, D_80111894_2EFFC4_name_45[gw->current_player_index].x,
                                                D_80111894_2EFFC4_name_45[gw->current_player_index].y,
                                                D_80111834_2EFF64_name_45[gw->current_player_index].x,
                                                D_80111834_2EFF64_name_45[gw->current_player_index].y, 30));
    HuPrcChildWatch();
    for (i = 1; i < 10; i++) {
        func_80082488_83088(sprite, 0, 255 - i * 25);
        HuPrcVSleep();
    }
    func_80082488_83088(sprite, 0, 0);
    SprKill(sprite);
    SprAnimKill(anim);
}

void func_8010C6CC_2EADFC_name_45(void) {
    s32 sprite;
    void* data;
    s32 anim;
    s32 i;
    s32 j;
    GW_SYSTEM* gw = &GwSystem;

    sprite = SprCreate_s32(1, 5);
    data = DataRead(D_801116AC_2EFDDC_name_45[gPlayers[gw->current_player_index].character]);
    anim = SprAnimRead_s32(data);
    DataClose(data);
    SprAnimSet(sprite, 0, anim, 0);
    SprPrioSet(sprite, 0, 10);
    func_8008225C_82E5C(sprite, 0, 1);
    if (gw->current_player_index & 1) {
        SprAttrSet(sprite, 0, 0x1001);
    } else {
        SprAttrSet(sprite, 0, 0x1000);
    }
    SprPosSet(sprite, 0, D_80111834_2EFF64_name_45[gw->current_player_index].x, D_80111834_2EFF64_name_45[gw->current_player_index].y);
    func_80082488_83088(sprite, 0, 0);
    for (i = 0; i < 17; i++) {
        func_80082488_83088(sprite, 0, i * 16);
        HuPrcVSleep();
    }
    func_80082488_83088(sprite, 0, 255);
    func_800822A8_82EA8(sprite, 0, 1, 0);
    func_8008225C_82E5C(sprite, 0, 1);
    HuPrcSleep(20);
    PlaySound(0x375);
    HuPrcChildLink(HuPrcCurrentGet(),
                   func_8010BBF8_2EA328_name_45(sprite, D_80111834_2EFF64_name_45[gw->current_player_index].x,
                                                D_80111834_2EFF64_name_45[gw->current_player_index].y,
                                                D_80111854_2EFF84_name_45[gw->current_player_index].x,
                                                D_80111854_2EFF84_name_45[gw->current_player_index].y, 30));
    HuPrcChildWatch();
    HuPrcSleep(10);
    func_800822A8_82EA8(sprite, 0, 0, 0);
    func_8008225C_82E5C(sprite, 0, 1);
    for (i = 1; i < 10; i++) {
        func_80082488_83088(sprite, 0, 255 - i * 25);
        HuPrcVSleep();
    }
    func_80082488_83088(sprite, 0, 0);
    if (gPlayers[gw->current_player_index].item == 7) {
        PlaySound(0x369);
    }
    i = 0;
    do {
        func_80062A28_63628(gw->current_player_index, HuMathSin(i) * 30.0f);
        i += 30;
        HuPrcVSleep();
    } while (i < 1081);
    for (j = 1; j < 10; j++) {
        func_800629F0_635F0(gw->current_player_index, 255 - j * 25);
        func_80062A28_63628(gw->current_player_index, HuMathSin(i) * 30.0f);
        i += 30;
        HuPrcVSleep();
    }
    func_800629F0_635F0(gw->current_player_index, 0);
    SprKill(sprite);
    SprAnimKill(anim);
}

#ifdef NON_MATCHING /* NON_MATCHING */
void func_8010CB30_2EB260_name_45(void) {
    s8 others[8];
    char str0[16];
    char str1[16];
    s32 count;
    s32 target;
    s32 i;
    MBModel* chest;
    f32 f;
    f32 x;
    f32 y;
    GW_SYSTEM* gw = &GwSystem;

    count = 0;
    func_8010C054_2EA784_name_45();
    HuPrcChildLink(HuPrcCurrentGet(),
                   func_8010BBF8_2EA328_name_45(-1, D_80111874_2EFFA4_name_45[gw->current_player_index].x,
                                                D_80111874_2EFFA4_name_45[gw->current_player_index].y,
                                                D_80111854_2EFF84_name_45[gw->current_player_index].x,
                                                D_80111854_2EFF84_name_45[gw->current_player_index].y, 1));
    HuPrcChildWatch();
    for (i = 0; i < 4; i++) {
        if (i != gw->current_player_index && gPlayers[i].item != -1) {
            others[count++] = i;
        }
    }
    chest = func_80043510_44110(0x6E, NULL);
    func_800297E8_2A3E8(chest->obj->model[0], 0, 0, 0);
    func_800B3170_B3D70(&chest->pos, &((MBModel*)BoardPlayerGet(-1)->unk_24)->pos);
    func_80029E80_2AA80(chest->obj->model[0], 2, 1);
    chest->jumpY = 100.0f;
    do {
        chest->jumpY -= 1.0f;
        HuPrcVSleep();
    } while (chest->jumpY > 30.0f);
    if (count != 0) {
        PlaySound(0x36B);
        for (i = 0; i < 1081; i += 30) {
            f = i;
            x = HuMathSin(f) / 2.0f + 1.0f;
            y = HuMathSin(f) / 2.0f + 1.0f;
            HuVecCopyXYZ(&chest->scale, x, y, HuMathSin(f) / 2.0f + 1.0f);
            HuPrcVSleep();
        }
    }
    func_80029E80_2AA80(chest->obj->model[0], 1, 0);
    HuPrcSleep(20);
    if (count == 0) {
        MBPlayerMotionSet(-1, 3, 0);
        HuPrcSleep(20);
        MBDlgResultWinExec(0x1E3);
        MBPlayerMotionSet(-1, -1, 2);
        MBModelKill(chest);
        gPlayers[gw->current_player_index].item = -1;
        return;
    }
    target = others[MBRand(count)];
    gPlayers[gw->current_player_index].item = gPlayers[target].item;
    gPlayers[target].item = -1;
    MBPlayerVibrate(target, 3);
    func_800629F0_635F0(target, 0);
    func_80062588_63188(gw->current_player_index);
    func_800629F0_635F0(gw->current_player_index, 0x100);
    PlaySound(0x19);
    HuPrcChildLink(HuPrcCurrentGet(),
                   func_8010BBF8_2EA328_name_45(-1, D_80111854_2EFF84_name_45[gw->current_player_index].x,
                                                D_80111854_2EFF84_name_45[gw->current_player_index].y,
                                                D_80111894_2EFFC4_name_45[gw->current_player_index].x,
                                                D_80111894_2EFFC4_name_45[gw->current_player_index].y, 5));
    HuPrcChildWatch();
    func_80079718_7A318(0xF5, gPlayers[gw->current_player_index].character);
    MBPlayerMotionSet(-1, 5, 0);
    HuPrcSleep(50);
    MBPlayerMotionSet(-1, -1, 2);
    MBModelKill(chest);
    str0[0] = 0x18;
    str0[1] = gPlayers[target].character;
    str0[2] = 0;
    str1[0] = 0x18;
    str1[1] = gPlayers[gw->current_player_index].character;
    str1[2] = 0;
    func_80056368_56F68(-1, 0x1E2, (s32)str0, (s32)str1, 0, 0, 0);
    MBDlgWinClose();
    func_80056168_56D68();
    func_8010C3A0_2EAAD0_name_45();
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_45_name/2E0F30", func_8010CB30_2EB260_name_45);
#endif

void func_8010D0A8_2EB7D8_name_45(void) {
    GW_PLAYER* player = BoardPlayerGet(-1);
    MBModel* obj;
    f32 scale;
    f32 rot;

    func_8005070C_5130C();
    MBModelDispOff(D_800CC1F0_CCDF0);
    D_800CC1F0_CCDF0->obj->scale.x = 0.0f;
    D_800CC1F0_CCDF0->obj->scale.y = 0.0f;
    D_800CC1F0_CCDF0->obj->scale.z = 0.0f;
    MBPlayerVibrate(-1, 3);
    PlaySound(0x36C);
    obj = func_80043510_44110(0x6F, NULL);
    func_800B3170_B3D70(&obj->pos, &((MBModel*)player->unk_24)->pos);
    obj->pos.z += 20.0f;
    obj->pos.y += 30.0f;

    for (rot = 0.0f, scale = 1.0f; scale < 10.0f; rot += 20.0f, HuPrcVSleep(), scale += 0.5) {
        HuVecCopyXYZ(&obj->scale, scale, scale, scale);
        func_800B3B80_B4780(D_800FC834_FD434[obj->obj->model[0]].mtx, rot);
    }

    MBModelDispOff(player->unk_24);
    MBModelDispOn(D_800CC1F0_CCDF0);

    for (; scale >= 1.0f; rot += 20.0f, HuPrcVSleep(), scale -= 0.5) {
        HuVecCopyXYZ(&obj->scale, scale, scale, scale);
        func_800B3B80_B4780(D_800FC834_FD434[obj->obj->model[0]].mtx, rot);
    }

    MBModelKill(obj);
    HuPrcSleep(20);
    MBKSuitMotionSet(5, 2);
    HuPrcSleep(40);
    MBKSuitMotionSet(-1, 2);
    MBDlgResultWinExec(0x1E6);
}

void func_8010D318_2EBA48_name_45(void) {
    GW_PLAYER* player = BoardPlayerGet(-1);
    Vec fwd;
    MBModel* obj;
    f32 scale;
    f32 rot;

    MBKSuitMotionSet(-1, 2);
    func_8005670C_5730C(&fwd);
    func_80056B78_57778(&((MBModel*)player->unk_24)->rot, &fwd, &((MBModel*)player->unk_24)->rot, 8);
    HuPrcSleep(8);
    PlaySound(0x36C);
    obj = func_80043510_44110(0x6F, NULL);
    func_800B3170_B3D70(&obj->pos, &((MBModel*)player->unk_24)->pos);
    obj->pos.z += 20.0f;
    obj->pos.y += 30.0f;

    for (rot = 0.0f, scale = 1.0f; scale < 10.0f; rot += 20.0f, HuPrcVSleep(), scale += 0.5) {
        HuVecCopyXYZ(&obj->scale, scale, scale, scale);
        func_800B3B80_B4780(D_800FC834_FD434[obj->obj->model[0]].mtx, rot);
    }

    MBModelDispOn(player->unk_24);
    func_80050860_51460();

    for (; scale >= 1.0f; rot += 20.0f, HuPrcVSleep(), scale -= 0.5) {
        HuVecCopyXYZ(&obj->scale, scale, scale, scale);
        func_800B3B80_B4780(D_800FC834_FD434[obj->obj->model[0]].mtx, rot);
    }
    MBModelKill(obj);
}

void func_8010D54C_2EBC7C_name_45(void) {
    s32 i;
    GW_SYSTEM* gw = &GwSystem;

    gPlayers[gw->current_player_index].item = 3;
    func_80060210_60E10(0x19);
    while (func_800609D8_615D8()) {
        HuPrcVSleep();
    }
    MBStatusItemDispSetAll(1);
    func_800629F0_635F0(gw->current_player_index, 0);
    func_80060210_60E10(0x1A);
    while (func_800609D8_615D8()) {
        HuPrcVSleep();
    }
    HuPrcChildLink(HuPrcCurrentGet(),
                   func_8010BBF8_2EA328_name_45(-1, D_80111834_2EFF64_name_45[gw->current_player_index].x,
                                                D_80111834_2EFF64_name_45[gw->current_player_index].y,
                                                D_80111854_2EFF84_name_45[gw->current_player_index].x,
                                                D_80111854_2EFF84_name_45[gw->current_player_index].y, 1));
    HuPrcChildWatch();
    PlaySound(0x19);
    for (i = 1; i < 10; i++) {
        func_800629F0_635F0(gw->current_player_index, i * 25);
        HuPrcVSleep();
    }
    func_800629F0_635F0(gw->current_player_index, 0x100);
    MBPlayerMotionSet(-1, 3, 0);
    HuPrcSleep(30);
    MBDlgResultWinExec(D_801118B4_2EFFE4_name_45[gw->current_board_index]);
    PlaySound(0x375);
    HuPrcChildLink(HuPrcCurrentGet(),
                   func_8010BBF8_2EA328_name_45(-1, D_80111854_2EFF84_name_45[gw->current_player_index].x,
                                                D_80111854_2EFF84_name_45[gw->current_player_index].y,
                                                D_80111834_2EFF64_name_45[gw->current_player_index].x,
                                                D_80111834_2EFF64_name_45[gw->current_player_index].y, 30));
    HuPrcChildWatch();
    HuPrcSleep(10);
    func_80060210_60E10(0x19);
    while (func_800609D8_615D8()) {
        HuPrcVSleep();
    }
    MBStatusItemDispSetAll(0);
    func_80060210_60E10(0x1A);
    while (func_800609D8_615D8()) {
        HuPrcVSleep();
    }
}

void func_8010D860_2EBF90_name_45(void) {
    Vec dir;
    GW_PLAYER* player;
    MBModel* obj;
    SpaceData* space;
    f32 scale;
    f32 rot;
    s32 i;
    s32 j;
    s32 cur;
    GW_SYSTEM* gw;

    player = BoardPlayerGet(-1);
    gw = &GwSystem;
    HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.3f));
    HuPrcChildWatch();
    for (i = 0; i < 4; i++) {
        if (gPlayers[i].item == 3) {
            func_80060210_60E10(0x19);
            while (func_800609D8_615D8()) {
                HuPrcVSleep();
            }
            MBStatusItemDispSetAll(1);
            func_800629F0_635F0(i, 0x100);
            func_80060210_60E10(0x1A);
            while (func_800609D8_615D8()) {
                HuPrcVSleep();
            }
            HuPrcSleep(20);
            func_800636F8_642F8(3);
            cur = gw->current_player_index;
            gw->current_player_index = i;
            PlaySound(0x375);
            HuPrcChildLink(HuPrcCurrentGet(),
                           func_8010BBF8_2EA328_name_45(-1, D_80111834_2EFF64_name_45[gw->current_player_index].x,
                                                        D_80111834_2EFF64_name_45[gw->current_player_index].y,
                                                        D_80111854_2EFF84_name_45[gw->current_player_index].x,
                                                        D_80111854_2EFF84_name_45[gw->current_player_index].y, 30));
            HuPrcChildWatch();
            HuPrcSleep(20);
            for (j = 1; j < 10; j++) {
                func_800629F0_635F0(i, 255 - j * 25);
                func_800628C0_634C0(i, 0.0f, 2.0f);
                HuPrcVSleep();
            }
            func_800629F0_635F0(i, 0);
            gPlayers[i].item = -1;
            gw->current_player_index = cur;
            func_800636F8_642F8(1);
            break;
        }
    }
    if (D_800F8D12_F9912 != 0) {
        func_801078E0_2E6010_name_45();
        HuPrcSleep(30);
    }
    MBPlayerVibrate(0, 4);
    MBPlayerVibrate(1, 4);
    MBPlayerVibrate(2, 4);
    MBPlayerVibrate(3, 4);
    PlaySound(0x36C);
    obj = func_80043510_44110(0x6F, NULL);
    func_800B3170_B3D70(&obj->pos, &D_800F64C8_F70C8->pos);
    obj->pos.z += 20.0f;
    obj->pos.y += 30.0f;

    for (rot = 0.0f, scale = 1.0f; scale < 10.0f; rot += 20.0f, HuPrcVSleep(), scale += 1.0) {
        HuVecCopyXYZ(&obj->scale, scale, scale, scale);
        func_800B3B80_B4780(D_800FC834_FD434[obj->obj->model[0]].mtx, rot);
    }

    func_800509FC_515FC();
    MBModelDispOff(D_800F64C8_F70C8);

    for (; scale >= 1.0f; rot += 20.0f, HuPrcVSleep(), scale -= 1.0) {
        HuVecCopyXYZ(&obj->scale, scale, scale, scale);
        func_800B3B80_B4780(D_800FC834_FD434[obj->obj->model[0]].mtx, rot);
    }
    MBModelKill(obj);
    func_80054C78_55878(D_80110D34_2EF464_name_45[gw->unk_1C], &player->cur_chain_index, &player->cur_space_index);
    player->next_chain_index = player->cur_chain_index;
    player->next_space_index = player->cur_space_index + 1;
    space = GetSpaceData(D_80110D34_2EF464_name_45[gw->unk_1C]);
    func_80056658_57258(&((MBModel*)player->unk_24)->pos, &space->coords, &dir);
    func_80056B78_57778(&((MBModel*)player->unk_24)->rot, &dir, &((MBModel*)player->unk_24)->rot, 8);
    HuPrcSleep(8);
    MBKSuitMotionSet(0, 2);
    func_80056D80_57980(&((MBModel*)player->unk_24)->pos, &space->coords, &((MBModel*)player->unk_24)->pos, 10);
    HuPrcSleep(10);
    MBKSuitMotionSet(-1, 2);
    if (func_8006286C_6346C(0)) {
        func_80060210_60E10(0x19);
        while (func_800609D8_615D8()) {
            HuPrcVSleep();
        }
        MBStatusItemDispSetAll(0);
        func_80060210_60E10(0x1A);
        while (func_800609D8_615D8()) {
            HuPrcVSleep();
        }
    }
    func_8005670C_5730C(&dir);
    func_80056B78_57778(&((MBModel*)player->unk_24)->rot, &dir, &((MBModel*)player->unk_24)->rot, 8);
    HuPrcSleep(8);
    MBKSuitMotionSet(5, 2);
    HuPrcSleep(30);
    PlaySound(0x123);
    MBDlgWinExec(D_801118CC_2EFFFC_name_45[gw->current_board_index], D_801118B4_2EFFE4_name_45[gw->current_board_index] + 1);
    MBKSuitMotionSet(-1, 2);
    HuPrcVSleep();
    func_800495D8_4A1D8(gw->current_player_index, 3);
}

void func_8010DED4_2EC604_name_45(void) {
    MBModel* obj;
    f32 scale;
    f32 rot;

    func_800794A8_7A0A8(60);
    PlaySound(0x36C);
    obj = func_80043510_44110(0x6F, NULL);
    func_800B3170_B3D70(&obj->pos, &D_800CC1F0_CCDF0->pos);
    obj->pos.z += 20.0f;
    obj->pos.y += 30.0f;

    for (rot = 0.0f, scale = 1.0f; scale < 10.0f; rot += 20.0f, HuPrcVSleep(), scale += 1.0) {
        HuVecCopyXYZ(&obj->scale, scale, scale, scale);
        func_800B3B80_B4780(D_800FC834_FD434[obj->obj->model[0]].mtx, rot);
    }

    func_800636F8_642F8(3);
    func_80050860_51460();

    for (; scale >= 1.0f; rot += 20.0f, HuPrcVSleep(), scale -= 1.0) {
        HuVecCopyXYZ(&obj->scale, scale, scale, scale);
        func_800B3B80_B4780(D_800FC834_FD434[obj->obj->model[0]].mtx, rot);
    }
    MBModelKill(obj);
    PlayMusic(func_800632FC_63EFC());
    MBDlgResultWinExec(D_801118B4_2EFFE4_name_45[GwSystem.current_board_index] + 8);
    D_800F8D16_F9916 = 0;
}

#ifdef NON_MATCHING /* NON_MATCHING */
void func_8010E108_2EC838_name_45(void) {
    s8 hit[8];
    Vec dir;
    char names[4][4];
    GW_PLAYER* player;
    GW_SYSTEM* gw;
    s32 cur;
    s32 count;
    s32 i;
    s32 total;
    s32 best;
    s32 max;
    s32 flag;

    cur = GwSystem.current_player_index;
    player = BoardPlayerGet(-1);
    gw = &GwSystem;
    count = 0;
    for (i = 0; i < 4; i++) {
        if (GetAbsSpaceIndexFromChainSpaceIndex(gPlayers[cur].cur_chain_index, gPlayers[cur].cur_space_index) ==
            GetAbsSpaceIndexFromChainSpaceIndex(gPlayers[i].cur_chain_index, gPlayers[i].cur_space_index)) {
            hit[count++] = i;
            MBPlayerVibrate(i, 4);
        }
    }
    if (count == 0) {
        return;
    }
    flag = func_80046D2C_4792C(cur);
    MBKSuitMotionSet(-1, 2);
    func_8005670C_5730C(&dir);
    func_80056B78_57778(&((MBModel*)player->unk_24)->rot, &dir, &((MBModel*)player->unk_24)->rot, 8);
    HuPrcSleep(8);
    PlaySound(0x123);
    total = 0;
    for (i = 0; i < count; i++) {
        total += gPlayers[hit[i]].coins;
    }
    if (total == 0) {
        if (count == 1) {
            names[0][0] = 0x18;
            names[0][1] = gPlayers[hit[0]].character;
            names[0][2] = 0;
            func_80056368_56F68(D_801118CC_2EFFFC_name_45[gw->current_board_index],
                                D_801118B4_2EFFE4_name_45[gw->current_board_index] + 6, (s32)names[0], 0, 0, 0, 0);
            func_80056458_57058();
            MBDlgWinClose();
            func_80056168_56D68();
        } else {
            MBDlgWinExec(D_801118CC_2EFFFC_name_45[gw->current_board_index],
                         D_801118B4_2EFFE4_name_45[gw->current_board_index] + 7);
        }
    } else {
        names[0][0] = names[1][0] = names[2][0] = names[3][0] = 0;
        for (i = 0; i < count; i++) {
            names[i][0] = 0x18;
            names[i][1] = gPlayers[hit[i]].character;
            names[i][2] = 0;
        }
        func_80056368_56F68(D_801118CC_2EFFFC_name_45[gw->current_board_index],
                            (count + 1) + D_801118B4_2EFFE4_name_45[gw->current_board_index], (s32)names[0],
                            (s32)names[1], (s32)names[2], (s32)names[3], 0);
        func_80056458_57058();
        if (gw->current_board_index == 4) {
            func_80056458_57058();
        }
        best = -1;
        MBDlgWinClose();
        func_80056168_56D68();
        max = 0;
        for (i = 0; i < count; i++) {
            if (max < gPlayers[hit[i]].coins) {
                best = hit[i];
                max = gPlayers[hit[i]].coins;
            }
        }
        for (i = 0; i < count; i++) {
            if (gPlayers[hit[i]].coins >= 5) {
                func_800797DC_7A3DC(0xFC, hit[i]);
            }
            MBPlayerVibrate(hit[i], 3);
            func_8004CA14_4D614(hit[i], -gPlayers[hit[i]].coins);
            if (best == hit[i]) {
                func_8006135C_61F5C(best, -gPlayers[best].coins, 1);
            } else {
                func_8006135C_61F5C(hit[i], -gPlayers[hit[i]].coins, 0);
            }
        }
        MBKSuitMotionSet(5, 2);
        HuPrcSleep(30);
    }
    if (flag != 0) {
        func_8004655C_4715C(GwSystem.current_player_index);
    }
    MBKSuitMotionSet(0, 2);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_45_name/2E0F30", func_8010E108_2EC838_name_45);
#endif

void func_8010E618_2ECD48_name_45(void) {
    s16 grp;
    s16 anim;
    void* data;
    s32 i;
    s32 pick;

    pick = MBRand(6.0f);
    if (pick >= 5) {
        pick = -1;
    }
    if (pick != -1) {
        grp = SprCreate(1, 5);
        data = DataRead(D_800CCBDC_CD7DC[D_800CAFD8[pick]]);
        anim = SprAnimRead(data);
        DataClose(data);
        SprAnimSet(grp, 0, anim, 0);
        SprPrioSet(grp, 0, 10);
        func_8008225C_82E5C(grp, 0, 0);
        SprAttrSet(grp, 0, 0x1000);
        SprPosSet(grp, 0, 160, 90);
        func_80082488_83088(grp, 0, 0);
        for (i = 0; i < 10; i++) {
            func_80082488_83088(grp, 0, i * 25);
            HuPrcVSleep();
        }
        func_80082488_83088(grp, 0, 0x100);
        MBPlayerMotionSet(-1, 5, 0);
        HuPrcSleep(50);
        MBPlayerMotionSet(-1, -1, 2);
        HuPrcSleep(10);
        SprAnimKill(anim);
        SprKill(grp);
        gPlayers[GwSystem.current_player_index].item = D_800CAFD8[pick];
    } else {
        MBPlayerMotionSet(-1, 3, 0);
        HuPrcSleep(50);
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_45_name/2E0F30", func_8010E828_2ECF58_name_45);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_45_name/2E0F30", func_8010E9D0_2ED100_name_45);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_45_name/2E0F30", func_8010EA40_2ED170_name_45);

s32 func_8010F680_2EDDB0_name_45(s32 arg0) {
    s32 count = 0;
    s16 sp18[4];
    u8 sp20[4];
    s32 i;
    s32 j;

    *(Unk4Bytes*)sp20 = *(Unk4Bytes*)D_80112EC0_2F15F0_name_45;
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            if (gPlayers[i].flags & 1) {
                count = func_80044800_45400(arg0 == 0 ? D_80111964_2F0094_name_45 : D_801119A0_2F00D0_name_45) + 1;
                sp18[gPlayers[i].port] = 0x400;
            } else {
                func_8008D59C_8E19C(mbDlgWinId, sp20[gPlayers[i].port]);
                sp18[gPlayers[i].port] = -1;
            }
        } else {
            sp18[gPlayers[i].port] = 0;
        }
    }

    if (count != 0) {
        func_80089284_89E84(mbDlgWinId, 2, 2);
        for (j = 0; count != 0; j++) {
            if (--count == 0) {
                sp18[gPlayers[GwSystem.current_player_index].port] = -0x8000;
            }
            if (j == 0) {
                func_8008CFD0_8DBD0(sp18[0], sp18[1], sp18[2], sp18[3], func_80057718_58318());
            } else {
                func_8008CFD0_8DBD0(sp18[0], sp18[1], sp18[2], sp18[3], 16);
            }
        }
    } else {
        func_8008D07C_8DC7C(sp18[0], sp18[1], sp18[2], sp18[3]);
    }
    return func_8008BB48_8C748(mbDlgWinId, 0, 1);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_45_name/2E0F30", func_8010F8E0_2EE010_name_45);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_45_name/2E0F30", func_8010FBD8_2EE308_name_45);

void func_8010FDCC_2EE4FC_name_45(s32 arg0) {
    Process* process;

    process = omAddPrcObj(func_8010FBD8_2EE308_name_45, 0xF000, 0, 0);
    process->user_data = (void*)arg0;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_45_name/2E0F30", func_8010FE08_2EE538_name_45);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_45_name/2E0F30", func_8011012C_2EE85C_name_45);

void func_80110658_2EED88_name_45(void) {
    func_8011012C_2EE85C_name_45(0);
}

void func_80110674_2EEDA4_name_45(void) {
    func_8011012C_2EE85C_name_45(1);
}

void func_80110690_2EEDC0_name_45(void) {
    func_80020070_20C70(2);
    CameraScissorSet(1, D_80111BFC_2F032C_name_45);
    func_801059C4_2E40F4_name_45();
    func_80066C34_67834(2);
    omAddPrcObj(func_80102FFC_2E172C_name_45, 0x1005, 0x1000, 0);
}

s32 func_801106E4_2EEE14_name_45(void) {
    s32 cur;
    s32 i;
    GW_SYSTEM* gw;

    cur = GetCurrentPlayerIndex();
    gw = &GwSystem;
    switch (gPlayers[cur].item) {
        case 0:
            if (gw->total_turns != gw->current_turn && !RNGPercentChance(80)) {
                return 0;
            }
            break;
        case -1:
        case 1:
        case 3:
            return 0;
        case 6:
            if (gw->total_turns != gw->current_turn && func_80044800_45400(D_80112770_2F0EA0_name_45) != 0) {
                return 0;
            }
            break;
        case 8:
            if (gw->total_turns != gw->current_turn && func_80044800_45400(D_801127D0_2F0F00_name_45) != 0) {
                return 0;
            }
            break;
        case 5:
            if (func_80044800_45400(D_80112B00_2F1230_name_45) != 0) {
                return 0;
            }
            break;
        case 2:
            for (i = 0; i < 4; i++) {
                if (i != cur && gPlayers[i].item != -1 && gPlayers[i].item != 3) {
                    break;
                }
            }
            if (i == 4) {
                return 0;
            }
            break;
        case 7:
            if (gPlayers[cur].coins < 5) {
                return 0;
            }
            break;
        case 9:
            if (func_80044800_45400(D_80112CE0_2F1410_name_45) != 0) {
                return 0;
            }
            if (gPlayers[cur].coins < 20) {
                return 0;
            }
            break;
        case 4:
            if (gPlayers[cur].coins < 10 && GwSystem.total_turns != GwSystem.current_turn) {
                return 0;
            }
            break;
    }
    return 1;
}

s32 func_80110908_2EF038_name_45(void) {
    GW_PLAYER* player;
    s32 slot;
    s32 i;
    s32 r;
    u8 item;
    GW_SYSTEM* gw = &GwSystem;

    player = BoardPlayerGet(-1);
    slot = -1;
    for (i = 0; i < D_80112EAC_2F15DC_name_45[player->character]; i++) {
        item = D_80112E34_2F1564_name_45[player->character][i];
        slot = func_80108754_2E6E84_name_45(item);
        if (slot == -1) {
            continue;
        }
        if (D_800CC000[item] + 20 > gPlayers[gw->current_player_index].coins) {
            continue;
        }
        if (RNGPercentChance(D_80112E94_2F15C4_name_45[player->character][i])) {
            break;
        }
    }
    if (i == D_80112EAC_2F15DC_name_45[player->character]) {
        slot = -1;
    }
    if (slot != -1) {
        if (func_80108754_2E6E84_name_45(9) == slot) {
            return slot + 1;
        }
        if (func_80108754_2E6E84_name_45(7) == slot && D_800CC000[7] + 50 <= gPlayers[gw->current_player_index].coins) {
            return slot + 1;
        }
    }
    if (func_80044800_45400(D_80112D40_2F1470_name_45) == 0 && gPlayers[gw->current_player_index].coins >= D_800CC000[1]) {
        r = func_80108754_2E6E84_name_45(1);
        if (r != -1) {
            return r + 1;
        }
    }
    if (slot != -1) {
        return slot + 1;
    }
    i = func_80044800_45400(D_80112D58_2F1488_name_45);
    if (i == 0) {
        for (; i < D_80112EAC_2F15DC_name_45[player->character]; i++) {
            item = D_80112E34_2F1564_name_45[player->character][i];
            slot = func_80108754_2E6E84_name_45(item);
            if (slot == -1) {
                continue;
            }
            if (D_800CC000[item] > gPlayers[gw->current_player_index].coins) {
                continue;
            }
            if (RNGPercentChance(D_80112E94_2F15C4_name_45[player->character][i])) {
                return slot + 1;
            }
        }
    }
    if (gw->current_board_index == 4) {
        D_80112DE8_2F1518_name_45 = 1;
        return func_801087C0_2E6EF0_name_45() + 2;
    }
    slot = func_80108754_2E6E84_name_45(0);
    if (slot != -1) {
        return slot + 1;
    }
    return 1;
}

s32 func_80110C84_2EF3B4_name_45(void) {
    if (D_80112DE8_2F1518_name_45 != 0) {
        D_80112DE8_2F1518_name_45 = 0;
        return 2;
    }
    return func_80044800_45400(D_80112DC4_2F14F4_name_45) + 1;
}
