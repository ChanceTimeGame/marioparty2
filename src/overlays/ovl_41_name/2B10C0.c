#include "common.h"
#include "ovl_41.h"

s16 func_80102830_2B10F0_name_41(void) {
    return D_80110AA4_2BF364_name_41[GwSystem.star_spawn_indices[GwSystem.unk_0A]];
}

void func_8010285C_2B111C_name_41(void) {
    s32 i;
    s32 a;
    s32 b;
    s32 temp;
    GW_SYSTEM* gw = &GwSystem;

    for (i = 0; i < 60; i++) {
        a = (u8)(rand8() % 7);
        b = (u8)(rand8() % 7);
        if (a != b) {
            if (a >= D_80110A70_2BF330_name_41[b]) {
                if (b >= D_80110A70_2BF330_name_41[a]) {
                    temp = D_80110A60_2BF320_name_41[a];
                    D_80110A60_2BF320_name_41[a] = D_80110A60_2BF320_name_41[b];
                    D_80110A60_2BF320_name_41[b] = temp;

                    temp = D_80110A70_2BF330_name_41[a];
                    D_80110A70_2BF330_name_41[a] = D_80110A70_2BF330_name_41[b];
                    D_80110A70_2BF330_name_41[b] = temp;
                }
            }
        }
    }

    for (i = 0; i < 7; i++) {
        gw->star_spawn_indices[i] = D_80110A60_2BF320_name_41[i];
    }

    if (gw->unk_1C == -1) {
        temp = 0;
    retry:
        gw->unk_1C = gw->star_spawn_indices[6 - temp];
        for (i = 0; D_80110A80_2BF340_name_41[i] != -1; i++) {
            if (gw->unk_1C == D_80110A80_2BF340_name_41[i]) {
                temp++;
                goto retry;
            }
        }
    }
}

void func_80102A44_2B1304_name_41(void) {
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

void func_80102AB0_2B1370_name_41(void) {
    s32 temp;
    GW_SYSTEM* gw = &GwSystem;

    gw->unk_1C = gw->star_spawn_indices[gw->unk_0A];
    if (++gw->unk_0A < 7) {
        return;
    }
    temp = gw->star_spawn_indices[6];
    gw->unk_0A = 0;
    _SetFlag(0x44);
    func_8010285C_2B111C_name_41();
    if (temp != gw->star_spawn_indices[0]) {
        return;
    }
    temp = gw->star_spawn_indices[0];
    gw->star_spawn_indices[0] = gw->star_spawn_indices[6];
    gw->star_spawn_indices[6] = temp;
}

void func_80102B54_2B1414_name_41(void) {
    s32 i;
    GW_SYSTEM* gw = &GwSystem;

    for (i = 0; i < 7; i++) {
        _SetFlag(D_80110A84_2BF344_name_41[i]);
    }
    BoardSpaceTypeSet(D_80110A94_2BF354_name_41[gw->star_spawn_indices[gw->unk_0A]], 0xE);
    _ClearFlag(D_80110A84_2BF344_name_41[gw->star_spawn_indices[gw->unk_0A]]);
    if (gw->unk_1C != -1) {
        BoardSpaceTypeSet(D_80110A94_2BF354_name_41[gw->unk_1C], 0xF);
        func_800509C4_515C4(D_80110A94_2BF354_name_41[gw->unk_1C]);
    }
}

/* D_80111974 address hoisted out of the loop (masked 10); logic matches */
#ifdef NON_MATCHING
s32 func_80102C3C_2B14FC_name_41(s32 space) {
    s32 i;
    s32 j;
    s16* spaces;
    GW_SYSTEM* gw = &GwSystem;

    i = 0;
    spaces = D_80110A94_2BF354_name_41;
    space = (s16)space;
    do {
        if (space == spaces[i]) {
            if (i == gw->star_spawn_indices[gw->unk_0A]) {
                gw->unk_1A = D_80110A84_2BF344_name_41[i];
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
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_80102C3C_2B14FC_name_41);
#endif

void func_80102D28_2B15E8_name_41(void) {
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
    D_80111EC0_2C0780_name_41 = NULL;
    omDelPrcObj(NULL);
}

void func_80102F4C_2B180C_name_41(UnkMBGuideData* guide) {
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

void func_80102FFC_2B18BC_name_41(void) {
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
    func_8005AB50_5B750(guide->obj, 2, 8, D_80110AB4_2BF374_name_41);
    func_80067558_68158();
    InitFadeIn(2, 16);
    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    func_80051500_52100();
    func_80053608_54208(3.0f);
    func_80102F4C_2B180C_name_41(guide);
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
        space = GetSpaceData(D_80110AA4_2BF364_name_41[gw->unk_1C]);
    } else {
        space = GetSpaceData(D_80110AA4_2BF364_name_41[gw->star_spawn_indices[gw->unk_0A]]);
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
        proc = omAddPrcObj(func_80102D28_2B15E8_name_41, 0x4800, 0, 0);
        D_80111EC0_2C0780_name_41 = proc;
        proc->user_data = space;
        HuPrcSleep(30);
    } else {
        D_80111EC0_2C0780_name_41 = NULL;
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
        while (D_80111EC0_2C0780_name_41 != NULL) {
            HuPrcVSleep();
        }
        if (D_800F8D12_F9912 != 0 && (u8)pick == 0) {
            space = GetSpaceData(D_80110AA4_2BF364_name_41[gw->star_spawn_indices[gw->unk_0A]]);
        } else {
            space = GetSpaceData(D_80110AA4_2BF364_name_41[gw->unk_1C]);
        }
        MBDCameraPos3DSet(&space->coords);
        MBCameraSpeedSet(3.5f);
        HuPrcSleep(5);
        while (func_80053998_54598() != 0) {
            HuPrcVSleep();
        }
        HuPrcSleep(5);
        MBMotionSet(guide->obj, 0, 2);
        func_80029FE4_2ABE4(guide->obj->obj->model[0], D_80110ABC_2BF37C_name_41[gw->current_board_index]);
        func_8005B338_5BF38(guide);
        func_8005AC6C_5B86C(guide->obj, D_80110AB8_2BF378_name_41);
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

void func_80103548_2B1E08_name_41(void) {
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
    PlaySound(D_80110AE0_2BF3A0_name_41 == 0 ? 0x355 : 0x34E);
    star = func_80043510_44110(D_80111EC4_2C0784_name_41 == 0 ? 0x19 : 0xD, NULL);
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
    if (D_80111EC4_2C0784_name_41 == 0) {
        MBPlayerVibrate(-1, 5);
        if (D_80110AE0_2BF3A0_name_41 != 0) {
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

void func_80103968_2B2228_name_41(MBModel* parent) {
    Process* proc;

    D_800FC734_FD334 = 0;
    D_80111EC4_2C0784_name_41 = 0;
    proc = omAddPrcObj(func_80103548_2B1E08_name_41, 0x4800, 0, 0);
    proc->user_data = parent;
    HuPrcChildLink(HuPrcCurrentGet(), proc);
    HuPrcChildWatch();
    D_800FC734_FD334 = 1;
}

void func_801039E4_2B22A4_name_41(MBModel* parent) {
    Process* proc;

    D_800FC734_FD334 = 0;
    D_80111EC4_2C0784_name_41 = 1;
    proc = omAddPrcObj(func_80103548_2B1E08_name_41, 0x4800, 0, 0);
    proc->user_data = parent;
    HuPrcChildLink(HuPrcCurrentGet(), proc);
    HuPrcChildWatch();
    D_800FC734_FD334 = 1;
}

void func_80103A64_2B2324_name_41(void) {
    D_800FA198_FAD98 = 1;
    D_800FC734_FD334 = 0;
    omPrcSetStatBit(HuPrcCurrentGet(), 0x80);
    func_80067C6C_6886C(gPlayers[GwSystem.current_player_index].port);
    omPrcResetStatBit(HuPrcCurrentGet(), 0x80);
    D_800FA198_FAD98 = 0;
    D_800FC734_FD334 = 1;
}

void func_80103AF4_2B23B4_name_41(void) {
    D_800FA198_FAD98 = 1;
    D_800FC734_FD334 = 0;
    omPrcSetStatBit(HuPrcCurrentGet(), 0x80);
    func_80067C6C_6886C(gPlayers[GwSystem.current_player_index].port);
    D_800FA198_FAD98 = 0;
    D_800FC734_FD334 = 1;
}

s32 func_80103B70_2B2430_name_41(void) {
    return rand8() / 256.0f * 100.0f;
}

void func_80103BC4_2B2484_name_41(void) {
    while (func_80053998_54598() != 0) {
        HuPrcVSleep();
    }
    HuPrcVSleep();
    D_80111EC8_2C0788_name_41 = func_8004CC7C_4D87C(0, 0x92, 1);
    D_80111ECC_2C078C_name_41 = func_8004CC7C_4D87C(1, 0xA0, 1);
    D_80111ED8_2C0798_name_41 = func_8004CC7C_4D87C(0xD, 0xAE, 1);
    D_80111ED0_2C0790_name_41 = func_8004CC7C_4D87C(3, 0xBC, 1);
    D_80111ED4_2C0794_name_41 = func_8004CC7C_4D87C(0xB, 0xCA, 1);
    HuPrcSleep(3);
    D_800FA198_FAD98 = 1;
    D_80101058_101C58 = 1;
}

void func_80103C94_2B2554_name_41(void) {
    D_800FA198_FAD98 = 0;
    D_80101058_101C58 = 0;
    MBHelpWinKill(D_80111EC8_2C0788_name_41);
    MBHelpWinKill(D_80111ECC_2C078C_name_41);
    MBHelpWinKill(D_80111ED8_2C0798_name_41);
    MBHelpWinKill(D_80111ED0_2C0790_name_41);
    MBHelpWinKill(D_80111ED4_2C0794_name_41);
}

__asm__(".section .rodata");
const u8 D_80111D60_2C0620_name_41[4] = { 1, 2, 4, 8 };

s32 func_80103CF4_2B25B4_name_41(u8* items) {
    s32 count = 0;
    s16 sp18[4];
    u8 sp20[4];
    s32 i;
    s32 j;

    *(Unk4Bytes*)sp20 = *(Unk4Bytes*)D_80111D60_2C0620_name_41;
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            if (gPlayers[i].flags & 1) {
                count = func_80110664_2BEF24_name_41();
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

s32 func_80103FB0_2B2870_name_41(void) {
    s32 count = 0;
    s16 sp18[4];
    u8 sp20[4];
    s32 i;
    s32 j;

    *(Unk4Bytes*)sp20 = *(Unk4Bytes*)D_80111D60_2C0620_name_41;
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            if (gPlayers[i].flags & 1) {
                count = func_801109E0_2BF2A0_name_41();
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

s32 func_801041D4_2B2A94_name_41(void) {
    s32 com = 0;
    s16 sp18[4];
    u8 sp20[4];
    s32 i;

    *(Unk4Bytes*)sp20 = *(Unk4Bytes*)D_80111D60_2C0620_name_41;
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

void func_80104380_2B2C40_name_41(void) {
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
            D_80111F00_2C07C0_name_41 = 1;
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
        if (func_80103B70_2B2430_name_41() < D_80110AE4_2BF3A4_name_41[turnBand][coinBand]) {
            D_80111F00_2C07C0_name_41 = 1;
        } else {
            goto coins;
        }
    }
    if (D_80111F00_2C07C0_name_41 == 1) {
        return;
    }
coins:
    for (i = 0; i < 4; i++) {
        if (i != GwSystem.current_player_index && gPlayers[i].coins != 0) {
            break;
        }
    }
    if (i != 4) {
        D_80111F00_2C07C0_name_41 = 0;
    } else {
        D_80111F00_2C07C0_name_41 = 2;
    }
}

s32 func_801045C0_2B2E80_name_41(void) {
    s32 flags[4] = { 0, 0, 0, 0 };
    s32 i;
    s32 coins;
    s32 min;

    if (GwSystem.current_player_index != D_80111EF0_2C07B0_name_41[0]) {
        coins = gPlayers[D_80111EF0_2C07B0_name_41[0]].coins;
        i = 1;
        flags[0] = 1;
    } else {
        coins = gPlayers[D_80111EF0_2C07B0_name_41[1]].coins;
        i = 2;
        flags[1] = 1;
    }
    for (; i < 4; i++) {
        if (GwSystem.current_player_index != D_80111EF0_2C07B0_name_41[i]
            && gPlayers[D_80111EF0_2C07B0_name_41[i]].coins + 5 >= coins) {
            flags[i] = 1;
        }
    }
    min = 4;
    for (i = 0; i < 4; i++) {
        if (flags[i] != 0 && func_80059FD0_5ABD0(D_80111EF0_2C07B0_name_41[i]) < min) {
            min = func_80059FD0_5ABD0(D_80111EF0_2C07B0_name_41[i]);
        }
    }
    return min;
}

/* MP1 func_800F6B3C (ovl_65) logic, checked case by case against this asm; retail keeps the
   duplicate cases apart and reloads stars between tests (masked 541) */
#ifdef NON_MATCHING
void func_80104778_2B3038_name_41(void) {
    s32 cand[4];
    s32 count;
    s32 i;
    s32 r;

    r = func_80103B70_2B2430_name_41();
    switch (D_80111F00_2C07C0_name_41) {
    case 1:
        if (GwSystem.total_turns < GwSystem.current_turn + 5) {
            switch (func_80059FD0_5ABD0(GwSystem.current_player_index)) {
            case 0:
                if (r >= 95 && gPlayers[D_80111EE0_2C07A0_name_41[2]].stars < 2) {
                    if (gPlayers[D_80111EE0_2C07A0_name_41[2]].stars != 0) {
                        D_80111F08_2C07C8_name_41 = 2;
                        break;
                    }
                }
                D_80111F08_2C07C8_name_41 = 1;
                break;
            case 1:
                if (r >= 95 && gPlayers[D_80111EE0_2C07A0_name_41[2]].stars != 0) {
                    D_80111F08_2C07C8_name_41 = 2;
                } else {
                    D_80111F08_2C07C8_name_41 = 0;
                }
                break;
            case 2:
                if (r >= 95 && gPlayers[D_80111EE0_2C07A0_name_41[1]].stars != 0) {
                    D_80111F08_2C07C8_name_41 = 1;
                } else {
                    D_80111F08_2C07C8_name_41 = 0;
                }
                break;
            case 3:
                if (r > 94 && gPlayers[D_80111EE0_2C07A0_name_41[1]].stars != 0) {
                    D_80111F08_2C07C8_name_41 = 1;
                } else {
                    D_80111F08_2C07C8_name_41 = 0;
                }
                break;
            }
        } else {
            switch (func_80059FD0_5ABD0(GwSystem.current_player_index)) {
            case 0:
                if (r >= 80 && gPlayers[D_80111EE0_2C07A0_name_41[2]].stars < 2) {
                    if (gPlayers[D_80111EE0_2C07A0_name_41[2]].stars != 0) {
                        D_80111F08_2C07C8_name_41 = 2;
                        break;
                    }
                }
                D_80111F08_2C07C8_name_41 = 1;
                break;
            case 1:
                if (r >= 90 && gPlayers[D_80111EE0_2C07A0_name_41[2]].stars != 0) {
                    D_80111F08_2C07C8_name_41 = 2;
                } else {
                    D_80111F08_2C07C8_name_41 = 0;
                }
                break;
            case 2:
                if (r >= 90 && gPlayers[D_80111EE0_2C07A0_name_41[1]].stars != 0) {
                    D_80111F08_2C07C8_name_41 = 1;
                } else {
                    D_80111F08_2C07C8_name_41 = 0;
                }
                break;
            case 3:
                if (r >= 95 && gPlayers[D_80111EE0_2C07A0_name_41[1]].stars != 0) {
                    D_80111F08_2C07C8_name_41 = 1;
                } else {
                    D_80111F08_2C07C8_name_41 = 0;
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
            || (GwSystem.total_turns < GwSystem.current_turn + 5 && func_80103B70_2B2430_name_41() < 80)
            || func_80103B70_2B2430_name_41() < 40) {
            if (GwSystem.total_turns < GwSystem.current_turn + 5) {
                if (func_80059FD0_5ABD0(GwSystem.current_player_index) == 0) {
                    if (gPlayers[D_80111EE0_2C07A0_name_41[1]].coins == 0) {
                        goto steal;
                    }
                    if (gPlayers[D_80111EE0_2C07A0_name_41[0]].stars == gPlayers[D_80111EE0_2C07A0_name_41[1]].stars) {
                        goto one;
                    }
                    if (r < 85) {
                        D_80111F08_2C07C8_name_41 = 1;
                        return;
                    }
                    goto steal;
                }
                if (gPlayers[D_80111EE0_2C07A0_name_41[0]].coins == 0) {
                    goto steal;
                }
                if (gPlayers[D_80111EE0_2C07A0_name_41[0]].stars - 1 <= gPlayers[D_80111EE0_2C07A0_name_41[1]].stars) {
                    if (r < 80) {
                        goto zero;
                    }
                    goto steal;
                }
                if (gPlayers[D_80111EE0_2C07A0_name_41[0]].stars - 2 == gPlayers[D_80111EE0_2C07A0_name_41[1]].stars) {
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
                if (gPlayers[D_80111EE0_2C07A0_name_41[1]].coins == 0) {
                    goto steal;
                }
                if (gPlayers[D_80111EE0_2C07A0_name_41[0]].stars != gPlayers[D_80111EE0_2C07A0_name_41[1]].stars
                    && r >= 35) {
                    goto steal;
                }
            one:
                D_80111F08_2C07C8_name_41 = 1;
                return;
            }
            if (gPlayers[D_80111EE0_2C07A0_name_41[0]].coins == 0) {
                goto steal;
            }
            if (gPlayers[D_80111EE0_2C07A0_name_41[0]].stars - 1 <= gPlayers[D_80111EE0_2C07A0_name_41[1]].stars) {
                if (r < 60) {
                    goto zero;
                }
                goto steal;
            }
            if (gPlayers[D_80111EE0_2C07A0_name_41[0]].stars - 2 == gPlayers[D_80111EE0_2C07A0_name_41[1]].stars) {
                if (r < 75) {
                    goto zero;
                }
                goto steal;
            }
            if (r >= 80) {
                goto steal;
            }
        zero:
            D_80111F08_2C07C8_name_41 = 0;
            return;
        steal:
            D_80111F08_2C07C8_name_41 = func_801045C0_2B2E80_name_41();
            return;
        }
        for (i = 0; i < 4; i++) {
            if (cand[D_80111EE0_2C07A0_name_41[i]] != 0) {
                if (--count == 0) {
                    D_80111F08_2C07C8_name_41 = i;
                    return;
                }
            }
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_80104778_2B3038_name_41);
#endif

/* register allocation: i/coin-rank/j registers rotated (masked 0), as in MP1 func_800F7278 */
#ifdef NON_MATCHING
void func_80104F7C_2B383C_name_41(void) {
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
        D_80111EE0_2C07A0_name_41[i] = -1;
        D_80111EF0_2C07B0_name_41[i] = -1;
    }
    for (i = 0; i < 4; i++) {
        rank = func_80059FD0_5ABD0(i);
    starSlot:
        if (D_80111EE0_2C07A0_name_41[rank] != -1) {
            rank++;
            goto starSlot;
        }
        D_80111EE0_2C07A0_name_41[rank] = i;
        coinRank = 0;
        for (j = 0; j < 4; j++) {
            if (i != j) {
                coinRank += gPlayers[i].coins < gPlayers[j].coins;
            }
        }
    coinSlot:
        if (D_80111EF0_2C07B0_name_41[coinRank] != -1) {
            coinRank++;
            goto coinSlot;
        }
        D_80111EF0_2C07B0_name_41[coinRank] = i;
    }
    D_80111F00_2C07C0_name_41 = D_80111F04_2C07C4_name_41 = D_80111F08_2C07C8_name_41 = -1;
    func_80104380_2B2C40_name_41();
    if (D_80111F08_2C07C8_name_41 == -1) {
        func_80104778_2B3038_name_41();
    }
    while (starRankCount[D_80111F08_2C07C8_name_41] == 0) {
        D_80111F08_2C07C8_name_41--;
    }
    rank = func_80059FD0_5ABD0(GwSystem.current_player_index);
    if (rank == D_80111F08_2C07C8_name_41) {
        starRankCount[rank]--;
    }
    j = rand8() % starRankCount[D_80111F08_2C07C8_name_41];
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            continue;
        }
        if (D_80111F08_2C07C8_name_41 != func_80059FD0_5ABD0(i)) {
            continue;
        }
        if (j != 0) {
            j--;
            continue;
        }
        D_80111F04_2C07C4_name_41 = i;
        break;
    }
    if (D_80111F00_2C07C0_name_41 == 0 && gPlayers[D_80111F04_2C07C4_name_41].coins == 0) {
        for (i = 0; i < 4; i++) {
            if (i != GwSystem.current_player_index && gPlayers[i].coins != 0) {
                D_80111F04_2C07C4_name_41 = i;
                break;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_80104F7C_2B383C_name_41);
#endif

s32 func_8010537C_2B3C3C_name_41(u8* items) {
    s32 count = 0;
    s16 sp18[4];
    u8 sp20[4];
    s32 i;
    s32 j;

    *(Unk4Bytes*)sp20 = *(Unk4Bytes*)D_80111D60_2C0620_name_41;
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            if (gPlayers[i].flags & 1) {
                func_80104F7C_2B383C_name_41();
                count = D_80111F00_2C07C0_name_41 + 1;
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

s32 func_80105630_2B3EF0_name_41(s32 arg0, u8* items) {
    s32 count = 0;
    s16 sp18[4];
    u8 sp20[4];
    s32 i;

    *(Unk4Bytes*)sp20 = *(Unk4Bytes*)D_80111D60_2C0620_name_41;
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            if (gPlayers[i].flags & 1) {
                count = D_80111F04_2C07C4_name_41;
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

void func_801058A4_2B4164_name_41(void) {
    GwSystem.current_board_index = 1;
    omInitObjMan(10, 0);
    omOvlGotoEx(0x3D, 0, 0x192);
}

void func_801058E0_2B41A0_name_41(void) {
    omInitObjMan(10, 0);
    SetPlayerOntoChain(0, 0, 0);
    SetPlayerOntoChain(1, 0, 0);
    SetPlayerOntoChain(2, 0, 0);
    SetPlayerOntoChain(3, 0, 0);
    _SetFlag(0x43);
    func_8010285C_2B111C_name_41();
    D_800F8CE4_F98E4[0] = 0;
    D_800F8CE4_F98E4[1] = 0;
    D_800F8CE4_F98E4[2] = 0;
    D_800F8CE4_F98E4[0x1E] = 0;
    D_800F8CE4_F98E4[0x1D] = 0;
    D_800F8CE4_F98E4[0x1A] = 0;
    D_800F8CE4_F98E4[0x19] = 0;
    D_800F8CE4_F98E4[0x17] = 0;
    omOvlReturnEx(1);
}

void func_80105980_2B4240_name_41(void) {
    s32 i;
    SpaceData* from;

    omInitObjMan(0xA0, 0x28);
    func_80026DAC_279AC(1, 100, 100, 100);
    func_80026DAC_279AC(2, 200, 200, 200);
    func_80062E10_63A10(10, 0x41, 15, 0);
    func_80055928_56528(D_80110AF0_2BF3B0_name_41);
    func_80055980_56580(D_80110AF4_2BF3B4_name_41);
    {
        Vec dir;

        from = GetSpaceData(0x73);
        func_80056658_57258(&from->coords, &GetSpaceData(0x60)->coords, &dir);
        MBMasuArrowAngleAdd(func_80042BE0_437E0(&dir) + 180.0f);
    }
    func_8004D60C_4E20C(0, func_8010A1B0_2B8A70_name_41);
    func_8004D60C_4E20C(1, func_8010AE1C_2B96DC_name_41);
    func_8004D60C_4E20C(8, func_8010B1B8_2B9A78_name_41);
    func_8004D60C_4E20C(2, func_8010B228_2B9AE8_name_41);
    func_8004D60C_4E20C(3, func_8010C598_2BAE58_name_41);
    func_8004D60C_4E20C(4, func_8010CB10_2BB3D0_name_41);
    func_8004D60C_4E20C(5, func_8010CD80_2BB640_name_41);
    func_8004D60C_4E20C(6, func_8010B70C_2B9FCC_name_41);
    func_8004D60C_4E20C(7, func_8010C134_2BA9F4_name_41);
    func_8004D60C_4E20C(9, func_8010CFB4_2BB874_name_41);
    func_8004D60C_4E20C(10, func_8010D2C8_2BBB88_name_41);
    func_8004D60C_4E20C(12, func_8010D93C_2BC1FC_name_41);
    func_8004D60C_4E20C(11, func_8010DB70_2BC430_name_41);
    func_8004D60C_4E20C(13, func_8010E080_2BC940_name_41);
    func_80044D98_45998(func_80110440_2BED00_name_41);
    for (i = 0; i < 7; i++) {
        func_800542E8_54EE8(i, D_80110AA4_2BF364_name_41[i]);
    }
    if (_CheckFlag(0x4D)) {
        _ClearFlag(0x4D);
        if (D_800F8D12_F9912 != 0) {
            func_80102A44_2B1304_name_41();
        } else {
            func_80102AB0_2B1370_name_41();
        }
    }
    func_80102B54_2B1414_name_41();
    func_80105E28_2B46E8_name_41();
    func_80105DA0_2B4660_name_41();
    func_80106078_2B4938_name_41();
    func_8010633C_2B4BFC_name_41();
    func_80106500_2B4DC0_name_41();
    func_801066CC_2B4F8C_name_41();
    func_80106744_2B5004_name_41();
    func_80106904_2B51C4_name_41();
}

void func_80105BE8_2B44A8_name_41(void) {
    PlayMusic(9);
    func_800632F0_63EF0(9);
    func_80020070_20C70(2);
    func_80105980_2B4240_name_41();
    omAddObj(1000, 0, 0, -1, func_80106964_2B5224_name_41);
    func_80053AA0_546A0(1);
    EventTableHydrate(D_80110FD8_2BF898_name_41);
    EventTableHydrate(D_80111398_2BFC58_name_41);
    EventTableHydrate(D_80111040_2BF900_name_41);
    func_80066C34_67834(0);
}

void func_80105C70_2B4530_name_41(void) {
    func_80020070_20C70(1);
    func_80105980_2B4240_name_41();
    func_80066C34_67834(1);
}

void func_80105C9C_2B455C_name_41(s16 arg0) {
    MBModel* obj;

    if (D_80111F10_2C07D0_name_41[arg0] == NULL) {
        if (D_80111F0C_2C07CC_name_41 == NULL) {
            obj = func_80043510_44110(0x17, NULL);
            func_80043DAC_449AC(obj);
            D_80111F0C_2C07CC_name_41 = obj;
        } else {
            obj = MBModelParamCreate(D_80111F0C_2C07CC_name_41);
        }
        D_80111F10_2C07D0_name_41[arg0] = obj;
        obj->attr |= 2;
        func_80056754_57354(obj);
        func_800B3170_B3D70(&obj->pos, &GetSpaceData(D_80110B40_2BF400_name_41[arg0])->coords);
        func_80041AEC_426EC(6, obj, D_80110B04_2BF3C4_name_41[arg0][0], D_80110B04_2BF3C4_name_41[arg0][1]);
    }
}

void func_80105DA0_2B4660_name_41(void) {
    s32 i;

    D_80111F0C_2C07CC_name_41 = NULL;
    for (i = 0; i < 7; i++) {
        D_80111F10_2C07D0_name_41[i] = NULL;
        if (_CheckFlag(D_80110B50_2BF410_name_41[i]) == 0) {
            func_80105C9C_2B455C_name_41(i);
        }
    }
}

void func_80105E28_2B46E8_name_41(void) {
    MBModel* obj;
    GW_SYSTEM* gw = &GwSystem;

    if (gw->unk_1C != -1) {
        obj = func_80043510_44110(D_800F8D12_F9912 != 0 ? 0x17 : 0x1D, NULL);
        func_80043DAC_449AC(obj);
        D_800F64C8_F70C8 = obj;
        obj->attr |= 2;
        func_80056754_57354(obj);
        func_800B3170_B3D70(&obj->pos, &GetSpaceData(D_80110B40_2BF400_name_41[gw->unk_1C])->coords);
        D_80110B60_2BF420_name_41 = func_80041AEC_426EC(0xB, obj, D_80110B04_2BF3C4_name_41[gw->unk_1C][0],
                                                       D_80110B04_2BF3C4_name_41[gw->unk_1C][1]);
    } else {
        D_800F64C8_F70C8 = NULL;
    }
}

void func_80105F10_2B47D0_name_41(void) {
    if (D_800F64C8_F70C8 != NULL) {
        MBModelKill(D_800F64C8_F70C8);
    }
    if (D_80110B60_2BF420_name_41 != -1) {
        func_80041B40_42740(D_80110B60_2BF420_name_41);
    }
}

void func_80105F58_2B4818_name_41(s16 arg0) {
    MBModel* obj;

    if (D_80111F30_2C07F0_name_41[arg0] != NULL) {
        return;
    }
    if (D_80111F2C_2C07EC_name_41 == NULL) {
        obj = func_80043510_44110(8, NULL);
        func_8002D124_2DD24(obj->obj->model[0]);
        func_8002D124_2DD24(obj->shadow->model[0]);
        D_80111F2C_2C07EC_name_41 = obj;
    } else {
        obj = MBModelParamCreate(D_80111F2C_2C07EC_name_41);
    }
    MBModelDispOff(obj);
    D_80111F30_2C07F0_name_41[arg0] = obj;
    obj->attr |= 2;
    obj->jumpY = 10.0f;
    func_800B3170_B3D70(&obj->pos, &GetSpaceData(D_80110B64_2BF424_name_41[arg0])->coords);
    func_80041AEC_426EC(8, obj, D_80110B20_2BF3E0_name_41[arg0][0], D_80110B20_2BF3E0_name_41[arg0][1]);
}

void func_80106078_2B4938_name_41(void) {
    s32 i;

    D_80111F2C_2C07EC_name_41 = NULL;
    for (i = 0; i < 1; i++) {
        D_80111F30_2C07F0_name_41[i] = NULL;
        func_80105F58_2B4818_name_41(i);
    }
}

void func_801060D4_2B4994_name_41(void) {
    s32 i;
    s32 j;
    s32 count;

    for (i = 0; i < 2; i++) {
        count = (D_800F8CE4_F98E4[0x1D] + 9) / 10;
        if (count > 5) {
            count = 5;
        }
        for (j = 0; j < count; j++) {
            MBModelDispOn(D_80111F38_2C07F8_name_41[i * 5 + j]);
        }
        for (; j < 5; j++) {
            MBModelDispOff(D_80111F38_2C07F8_name_41[i * 5 + j]);
        }
    }
}

void func_801061D0_2B4A90_name_41(s16 arg0) {
    MBModel* coin;
    Vec* pos;
    s32 bank;
    s16 slot;

    if (D_80111F38_2C07F8_name_41[arg0] == NULL) {
        if (D_80111F34_2C07F4_name_41 == NULL) {
            coin = func_80043510_44110(0x6C, NULL);
            func_80043DAC_449AC(coin);
            D_80111F34_2C07F4_name_41 = coin;
        } else {
            coin = MBModelParamCreate(D_80111F34_2C07F4_name_41);
        }
        D_80111F38_2C07F8_name_41[arg0] = coin;
        coin->attr |= 2;

        bank = arg0 / 5;
        pos = &coin->pos;
        func_800B3170_B3D70(pos, &GetSpaceData(D_80110B68_2BF428_name_41[bank])->coords);

        slot = arg0 % 5;
        HuVecAdd(pos, &D_80110B6C_2BF42C_name_41[slot], pos);
        coin->obj->rot.x = D_80110BA8_2BF468_name_41[slot].x;
        coin->obj->rot.z = D_80110BA8_2BF468_name_41[slot].z;
        MBModelDispOff(coin);
    }
}

void func_8010633C_2B4BFC_name_41(void) {
    s32 i;

    D_80111F34_2C07F4_name_41 = NULL;
    for (i = 0; i < 10; i++) {
        D_80111F38_2C07F8_name_41[i] = NULL;
        func_801061D0_2B4A90_name_41(i);
    }
    func_801060D4_2B4994_name_41();
}

void func_801063A4_2B4C64_name_41(s16 arg0) {
    MBModel* obj;
    SpaceData* space;
    char pad[4]; /* frame size, as MP3 func_80108748 (ChillyWaters) */

    if (D_80111F64_2C0824_name_41[arg0] == NULL) {
        if (D_80111F60_2C0820_name_41 == NULL) {
            /* D_80111AED[board * 2]: column 1 of a u8 [][2] table one byte before it */
            obj = func_80043510_44110(D_80110BE9_2BF4A9_name_41[GwSystem.current_board_index * 2], NULL);
            func_80043DAC_449AC(obj);
            D_80111F60_2C0820_name_41 = obj;
        } else {
            obj = MBModelParamCreate(D_80111F60_2C0820_name_41);
        }
        D_80111F64_2C0824_name_41[arg0] = obj;
        obj->attr |= 2;
        func_80029E80_2AA80(obj->obj->model[0], 2, 1);
        func_800B3170_B3D70(&obj->pos, &GetSpaceData(D_80110BE4_2BF4A4_name_41[arg0])->coords);
        space = GetSpaceData(D_80110B38_2BF3F8_name_41[arg0][0]);
        func_80056658_57258(&GetSpaceData(D_80110B38_2BF3F8_name_41[arg0][1])->coords, &space->coords, &obj->rot);
        func_80041AEC_426EC(0xC, obj, D_80110B30_2BF3F0_name_41[arg0][0], D_80110B30_2BF3F0_name_41[arg0][1]);
    }
}

void func_80106500_2B4DC0_name_41(void) {
    s32 i;

    D_80111F60_2C0820_name_41 = NULL;
    for (i = 0; i < 2; i++) {
        D_80111F64_2C0824_name_41[i] = NULL;
        func_801063A4_2B4C64_name_41(i);
    }
}

void func_80106560_2B4E20_name_41(void) {
    HuPrcSleep(D_80110C3C_2BF4FC_name_41[GwSystem.current_board_index]);
    PlaySound((s16)D_80110C18_2BF4D8_name_41[GwSystem.current_board_index]);
    omDelPrcObj(NULL);
}

void func_801065BC_2B4E7C_name_41(s32 arg0) {
    func_80029E80_2AA80(D_80111F64_2C0824_name_41[arg0]->obj->model[0], 5, 0);
    if (D_80110BF4_2BF4B4_name_41[GwSystem.current_board_index] != -1) {
        PlaySound((s16)D_80110BF4_2BF4B4_name_41[GwSystem.current_board_index]);
    }
    if (D_80110C18_2BF4D8_name_41[GwSystem.current_board_index] != -1) {
        omAddPrcObj(func_80106560_2B4E20_name_41, 0x1000, 0, 0);
    }
}

void func_80106660_2B4F20_name_41(s32 arg0) {
    func_80029E80_2AA80(D_80111F64_2C0824_name_41[arg0]->obj->model[0], 1, 4);
    if (D_80110C60_2BF520_name_41[GwSystem.current_board_index] != -1) {
        PlaySound((s16)D_80110C60_2BF520_name_41[GwSystem.current_board_index]);
    }
}

void func_801066CC_2B4F8C_name_41(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        func_80041B60_42760(10, &GetSpaceData(D_80110C84_2BF544_name_41[i])->coords, D_80110B24_2BF3E4_name_41[i][0],
                            D_80110B24_2BF3E4_name_41[i][1]);
    }
}

void func_80106744_2B5004_name_41(void) {
    func_80041B60_42760(9, &GetSpaceData(D_80110C88_2BF548_name_41)->coords, D_80110B2C_2BF3EC_name_41[0],
                        D_80110B2C_2BF3EC_name_41[1]);
}

void func_80106780_2B5040_name_41(s16 arg0) {
    MBModel* obj;
    f32 scale;
    SpaceData* from;
    s32 pad[2]; /* retail's frame has 8 unused bytes */

    if (D_80111F70_2C0830_name_41[arg0] != NULL) {
        return;
    }
    if (D_80111F6C_2C082C_name_41 == NULL) {
        obj = func_80043510_44110(0xB, NULL);
        func_80043DAC_449AC(obj);
        D_80111F6C_2C082C_name_41 = obj;
    } else {
        obj = MBModelParamCreate(D_80111F6C_2C082C_name_41);
    }
    MBModelDispOff(obj);
    D_80111F70_2C0830_name_41[arg0] = obj;
    obj->attr |= 2;
    scale = (D_800F8CE4_F98E4[arg0 + 1] + 50.0f) / 50.0f;
    if (scale > 2.0f) {
        scale = 2.0f;
    }
    HuVecCopyXYZ(&obj->scale, scale, scale, scale);
    func_800B3170_B3D70(&obj->pos, &GetSpaceData(D_80110C8C_2BF54C_name_41[arg0])->coords);
    from = GetSpaceData(D_80110C90_2BF550_name_41[arg0][0]);
    func_80056658_57258(&GetSpaceData(D_80110C90_2BF550_name_41[arg0][1])->coords, &from->coords, &obj->rot);
}

void func_80106904_2B51C4_name_41(void) {
    s32 i;

    D_80111F6C_2C082C_name_41 = NULL;
    for (i = 0; i < 2; i++) {
        D_80111F70_2C0830_name_41[i] = NULL;
        func_80106780_2B5040_name_41(i);
    }
}

void func_80106964_2B5224_name_41(void) {
    GW_PLAYER* player;

    player = BoardPlayerGet(-1);
    if (D_80110C98_2BF558_name_41 != 0) {
        func_800B3170_B3D70(&((MBModel*)player->unk_24)->pos, &D_80111F78_2C0838_name_41->pos);
        ((MBModel*)player->unk_24)->jumpY = D_80111F78_2C0838_name_41->jumpY + 7.0f;
        func_800B3170_B3D70(&((MBModel*)player->unk_24)->rot, &D_80111F78_2C0838_name_41->rot);
    }
}

s32 func_801069E8_2B52A8_name_41(s32 arg0) {
    s32 count = 0;
    s16 sp18[4];
    u8 sp20[4];
    s32 i;
    s32 j;

    *(Unk4Bytes*)sp20 = *(Unk4Bytes*)D_80111D60_2C0620_name_41;
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            if (gPlayers[i].flags & 1) {
                count = 1;
                if (arg0 == 0) {
                    count = func_80044800_45400(D_80110D28_2BF5E8_name_41) + 1;
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

/* A gate: open it with the key item (option 0) or turn back (1); option 2 runs func_80103A64 and asks again. */
void func_80106C40_2B5500_name_41(void) {
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
        func_80056C30_57830(-1, 8, 0x5D);
        HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.6f));
        HuPrcChildWatch();
        MBPlayerVibrate(-1, 1);
    loop:
        MBDlgWinCreate(0x14, 0x13);
        choice = func_801069E8_2B52A8_name_41(0);
        MBDlgWinClose();
        func_80056168_56D68();
        switch (choice) {
        case 0:
            gPlayers[gw->current_player_index].item = -1;
            MBDlgWinExec(0x14, 0x14);
            func_801065BC_2B4E7C_name_41(0);
            cam = func_800672BC_67EBC(-1, 2, 5);
            HuPrcSleep(20);
            func_8006735C_67F5C(cam);
            func_80103BC4_2B2484_name_41();
            prompt = func_80041A74_42674(GwSystem.current_player_index, D_80110D20_2BF5E0_name_41);
            func_800417EC_423EC(prompt, GwSystem.current_player_index, 0);
            if (PlayerIsCPU(-1) != 0) {
                if (GwSystem.current_player_index == 4) {
                    tree = D_80110D14_2BF5D4_name_41;
                } else {
                    tree = D_80110CCC_2BF58C_name_41;
                }
                n = func_80044800_45400(tree);
                for (i = 0; i < n; i++) {
                    func_80041610_42210(prompt, -2);
                }
                func_80041610_42210(prompt, -4);
            }
            dir = DirectionPrompt(prompt);
            func_8004108C_41C8C(prompt);
            func_80103C94_2B2554_name_41();
            if (dir == 0) {
                SetNextChainAndSpace(-1, 12, 0);
            } else {
                SetNextChainAndSpace(-1, 2, 0);
                func_80106660_2B4F20_name_41(0);
            }
            break;
        case 1:
            MBDlgWinExec(0x14, 0x15);
            SetNextChainAndSpace(-1, 2, 0);
            break;
        case 2:
            func_80103A64_2B2324_name_41();
            goto loop;
        }
        func_8004655C_4715C(gw->current_player_index);
        HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.3f));
        HuPrcChildWatch();
    } else {
        SetNextChainAndSpace(-1, 2, 0);
    }
    omDelPrcObj(NULL);
}

/* A gate: open it with the key item (option 0) or turn back (1); option 2 runs func_80103A64 and asks again. */
void func_80106F38_2B57F8_name_41(void) {
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
        func_80056C30_57830(-1, 8, 0x5E);
        HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.6f));
        HuPrcChildWatch();
        MBPlayerVibrate(-1, 1);
    loop:
        MBDlgWinCreate(0x14, 0x13);
        choice = func_801069E8_2B52A8_name_41(1);
        MBDlgWinClose();
        func_80056168_56D68();
        switch (choice) {
        case 0:
            gPlayers[gw->current_player_index].item = -1;
            MBDlgWinExec(0x14, 0x14);
            func_801065BC_2B4E7C_name_41(1);
            cam = func_800672BC_67EBC(-1, 2, 5);
            HuPrcSleep(20);
            func_8006735C_67F5C(cam);
            func_80103BC4_2B2484_name_41();
            prompt = func_80041A74_42674(GwSystem.current_player_index, D_80110D50_2BF610_name_41);
            func_800417EC_423EC(prompt, GwSystem.current_player_index, 0);
            if (PlayerIsCPU(-1) != 0) {
                if (GwSystem.current_player_index == 4) {
                    tree = D_80110D14_2BF5D4_name_41;
                } else {
                    tree = D_80110CFC_2BF5BC_name_41;
                }
                n = func_80044800_45400(tree);
                for (i = 0; i < n; i++) {
                    func_80041610_42210(prompt, -2);
                }
                func_80041610_42210(prompt, -4);
            }
            dir = DirectionPrompt(prompt);
            func_8004108C_41C8C(prompt);
            func_80103C94_2B2554_name_41();
            if (dir == 0) {
                SetNextChainAndSpace(-1, 8, 0);
            } else {
                SetNextChainAndSpace(-1, 4, 0);
                func_80106660_2B4F20_name_41(1);
            }
            break;
        case 1:
            MBDlgWinExec(0x14, 0x15);
            SetNextChainAndSpace(-1, 4, 0);
            break;
        case 2:
            func_80103A64_2B2324_name_41();
            goto loop;
        }
        func_8004655C_4715C(gw->current_player_index);
        HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.3f));
        HuPrcChildWatch();
    } else {
        SetNextChainAndSpace(-1, 4, 0);
    }
    omDelPrcObj(NULL);
}

void func_80107230_2B5AF0_name_41(void) {
    SetNextChainAndSpace(-1, 1, 0);
}

void func_80107254_2B5B14_name_41(void) {
    SetNextChainAndSpace(-1, 7, 0);
}

void func_80107278_2B5B38_name_41(void) {
    SetNextChainAndSpace(-1, 7, 0);
}

void func_8010729C_2B5B5C_name_41(void) {
    SetNextChainAndSpace(-1, 9, 0);
}

void func_801072C0_2B5B80_name_41(void) {
    SetNextChainAndSpace(-1, 9, 0);
}

void func_801072E4_2B5BA4_name_41(void) {
    SetNextChainAndSpace(-1, 11, 0);
}

void func_80107308_2B5BC8_name_41(void) {
    SetNextChainAndSpace(-1, 11, 0);
}

void func_8010732C_2B5BEC_name_41(void) {
    SetNextChainAndSpace(-1, 1, 0);
}

void func_80107350_2B5C10_name_41(void) {
    SetNextChainAndSpace(-1, 11, 13);
}

/* MP3 MB1Ev_KSuitEnd's shape: a puff grows over the marker model, the marker is rebuilt, the puff shrinks. */
void func_80107374_2B5C34_name_41(void) {
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
    func_80105F10_2B47D0_name_41();
    D_800F8D12_F9912 = 0;
    ChangeSpaceTextures(0);
    func_80105E28_2B46E8_name_41();
    for (; scale >= 1.0f; rot += 20.0f, HuPrcVSleep(), scale -= 1.0) {
        HuVecCopyXYZ(&obj->scale, scale, scale, scale);
        func_800B3B80_B4780(D_800FC834_FD434[obj->obj->model[0]].mtx, rot);
    }
    MBModelKill(obj);
}

__asm__(".section .rodata");
const char D_80111D88_2C0648_name_41[] = "%d";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_80107574_2B5E34_name_41);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_80107DB4_2B6674_name_41);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_801081E0_2B6AA0_name_41);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_8010824C_2B6B0C_name_41);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_80108298_2B6B58_name_41);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_801088A4_2B7164_name_41);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_80108944_2B7204_name_41);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_801089E4_2B72A4_name_41);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_801092C0_2B7B80_name_41);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_801092E4_2B7BA4_name_41);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_8010A020_2B88E0_name_41);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_8010A174_2B8A34_name_41);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_8010A1B0_2B8A70_name_41);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_8010AB8C_2B944C_name_41);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_8010ABA8_2B9468_name_41);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_8010ABC4_2B9484_name_41);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_8010AD04_2B95C4_name_41);

__asm__(".section .rodata");
const u32 D_80111DB8_2C0678_name_41[24] = { 0x3F800000, 0x3F800000, 0x3F800000, 0x3F800000, 0x40000000, 0x3F800000, 0x00000000, 0x40000000, 0x3F800000, 0xBF800000, 0x3F800000, 0x3F800000, 0xBF800000, 0xBF800000, 0x3F800000, 0x00000000, 0xBF800000, 0x3F800000, 0xBF800000, 0x40000000, 0x3F800000, 0x3F800000, 0xBF800000, 0x3F800000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_8010AE1C_2B96DC_name_41);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_8010B1B8_2B9A78_name_41);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_8010B228_2B9AE8_name_41);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_8010B414_2B9CD4_name_41);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_8010B660_2B9F20_name_41);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_8010B70C_2B9FCC_name_41);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_8010BABC_2BA37C_name_41);

/* The player's portrait fades in, slides back and fades out. */
void func_8010BE08_2BA6C8_name_41(void) {
    s32 sprite;
    void* data;
    s32 anim;
    s32 i;
    GW_SYSTEM* gw = &GwSystem;

    sprite = SprCreate_s32(1, 5);
    data = DataRead(D_80110ED0_2BF790_name_41[gPlayers[gw->current_player_index].character]);
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
    SprPosSet(sprite, 0, D_801110B0_2BF970_name_41[gw->current_player_index].x, D_801110B0_2BF970_name_41[gw->current_player_index].y);
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
                   func_8010B660_2B9F20_name_41(sprite, D_801110B0_2BF970_name_41[gw->current_player_index].x,
                                                D_801110B0_2BF970_name_41[gw->current_player_index].y,
                                                D_80111050_2BF910_name_41[gw->current_player_index].x,
                                                D_80111050_2BF910_name_41[gw->current_player_index].y, 30));
    HuPrcChildWatch();
    for (i = 1; i < 10; i++) {
        func_80082488_83088(sprite, 0, 255 - i * 25);
        HuPrcVSleep();
    }
    func_80082488_83088(sprite, 0, 0);
    SprKill(sprite);
    SprAnimKill(anim);
}

/* As func_8010CFCC, then the status window shakes while it fades. */
/* As func_8010CFCC, then the status window shakes while it fades. */
/* As func_8010CFCC, then the status window shakes while it fades. */
/* As func_8010CFCC, then the status window shakes while it fades. */
void func_8010C134_2BA9F4_name_41(void) {
    s32 sprite;
    void* data;
    s32 anim;
    s32 i;
    s32 j;
    GW_SYSTEM* gw = &GwSystem;

    sprite = SprCreate_s32(1, 5);
    data = DataRead(D_80110ED0_2BF790_name_41[gPlayers[gw->current_player_index].character]);
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
    SprPosSet(sprite, 0, D_80111050_2BF910_name_41[gw->current_player_index].x, D_80111050_2BF910_name_41[gw->current_player_index].y);
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
                   func_8010B660_2B9F20_name_41(sprite, D_80111050_2BF910_name_41[gw->current_player_index].x,
                                                D_80111050_2BF910_name_41[gw->current_player_index].y,
                                                D_80111070_2BF930_name_41[gw->current_player_index].x,
                                                D_80111070_2BF930_name_41[gw->current_player_index].y, 30));
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

/* Plunder chest (item event 3): take a random other player's item.
   register allocation only (masked 0): target and its gPlayers offset swap s0/s1. */
#ifdef NON_MATCHING /* NON_MATCHING */
void func_8010C598_2BAE58_name_41(void) {
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
    func_8010BABC_2BA37C_name_41();
    HuPrcChildLink(HuPrcCurrentGet(),
                   func_8010B660_2B9F20_name_41(-1, D_80111090_2BF950_name_41[gw->current_player_index].x,
                                                D_80111090_2BF950_name_41[gw->current_player_index].y,
                                                D_80111070_2BF930_name_41[gw->current_player_index].x,
                                                D_80111070_2BF930_name_41[gw->current_player_index].y, 1));
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
                   func_8010B660_2B9F20_name_41(-1, D_80111070_2BF930_name_41[gw->current_player_index].x,
                                                D_80111070_2BF930_name_41[gw->current_player_index].y,
                                                D_801110B0_2BF970_name_41[gw->current_player_index].x,
                                                D_801110B0_2BF970_name_41[gw->current_player_index].y, 5));
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
    func_8010BE08_2BA6C8_name_41();
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_8010C598_2BAE58_name_41);
#endif

/* 41-C: D_80111E18 (8010AE1C's end-of-table bound, the end of D_80111DB8) is the 0.5 literal
   func_8010CB10 emits: a label only, so the asm user still links. */
__asm__(".section .rodata\n\t.globl D_80111E18_2C06D8_name_41\nD_80111E18_2C06D8_name_41:\n\t.text");

/* Bowser suit start (item event 4); MP3 MB1Ev_KSuitStart. */
void func_8010CB10_2BB3D0_name_41(void) {
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

/* Bowser suit end (item event 5); MP3 MB1Ev_KSuitEnd. */
void func_8010CD80_2BB640_name_41(void) {
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

/* Board event 9: the current player gets item 3, shown in their status window. */
void func_8010CFB4_2BB874_name_41(void) {
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
                   func_8010B660_2B9F20_name_41(-1, D_80111050_2BF910_name_41[gw->current_player_index].x,
                                                D_80111050_2BF910_name_41[gw->current_player_index].y,
                                                D_80111070_2BF930_name_41[gw->current_player_index].x,
                                                D_80111070_2BF930_name_41[gw->current_player_index].y, 1));
    HuPrcChildWatch();
    PlaySound(0x19);
    for (i = 1; i < 10; i++) {
        func_800629F0_635F0(gw->current_player_index, i * 25);
        HuPrcVSleep();
    }
    func_800629F0_635F0(gw->current_player_index, 0x100);
    MBPlayerMotionSet(-1, 3, 0);
    HuPrcSleep(30);
    MBDlgResultWinExec(D_801110D0_2BF990_name_41[gw->current_board_index]);
    PlaySound(0x375);
    HuPrcChildLink(HuPrcCurrentGet(),
                   func_8010B660_2B9F20_name_41(-1, D_80111070_2BF930_name_41[gw->current_player_index].x,
                                                D_80111070_2BF930_name_41[gw->current_player_index].y,
                                                D_80111050_2BF910_name_41[gw->current_player_index].x,
                                                D_80111050_2BF910_name_41[gw->current_player_index].y, 30));
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

/* Board event 10 (Bowser suit, from the item marker): a player holding item 3 loses it, the
   suit appears on the marker and the current player walks to the star space. */
void func_8010D2C8_2BBB88_name_41(void) {
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
                           func_8010B660_2B9F20_name_41(-1, D_80111050_2BF910_name_41[gw->current_player_index].x,
                                                        D_80111050_2BF910_name_41[gw->current_player_index].y,
                                                        D_80111070_2BF930_name_41[gw->current_player_index].x,
                                                        D_80111070_2BF930_name_41[gw->current_player_index].y, 30));
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
        func_80107374_2B5C34_name_41();
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
    func_80054C78_55878(D_80110A94_2BF354_name_41[gw->unk_1C], &player->cur_chain_index, &player->cur_space_index);
    player->next_chain_index = player->cur_chain_index;
    player->next_space_index = player->cur_space_index + 1;
    space = GetSpaceData(D_80110A94_2BF354_name_41[gw->unk_1C]);
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
    MBDlgWinExec(D_801110E8_2BF9A8_name_41[gw->current_board_index], D_801110D0_2BF990_name_41[gw->current_board_index] + 1);
    MBKSuitMotionSet(-1, 2);
    HuPrcVSleep();
    func_800495D8_4A1D8(gw->current_player_index, 3);
}

/* Board event 12: the Bowser suit wears off (the current player is shown again). */
void func_8010D93C_2BC1FC_name_41(void) {
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
    MBDlgResultWinExec(D_801110D0_2BF990_name_41[GwSystem.current_board_index] + 8);
    D_800F8D16_F9916 = 0;
}

/* Board event 11 (Bowser suit passing players): every player on the current player's space is
   stomped and loses all their coins; the richest one's coins go to the current player.
   Differs only in the message index: retail adds count + 1 to the table entry, GCC here adds 1
   to the entry first (masked 2). */
#ifdef NON_MATCHING /* NON_MATCHING */
void func_8010DB70_2BC430_name_41(void) {
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
            func_80056368_56F68(D_801110E8_2BF9A8_name_41[gw->current_board_index],
                                D_801110D0_2BF990_name_41[gw->current_board_index] + 6, (s32)names[0], 0, 0, 0, 0);
            func_80056458_57058();
            MBDlgWinClose();
            func_80056168_56D68();
        } else {
            MBDlgWinExec(D_801110E8_2BF9A8_name_41[gw->current_board_index],
                         D_801110D0_2BF990_name_41[gw->current_board_index] + 7);
        }
    } else {
        names[0][0] = names[1][0] = names[2][0] = names[3][0] = 0;
        for (i = 0; i < count; i++) {
            names[i][0] = 0x18;
            names[i][1] = gPlayers[hit[i]].character;
            names[i][2] = 0;
        }
        func_80056368_56F68(D_801110E8_2BF9A8_name_41[gw->current_board_index],
                            (count + 1) + D_801110D0_2BF990_name_41[gw->current_board_index], (s32)names[0],
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
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_8010DB70_2BC430_name_41);
#endif

/* Board event 13: a random item (5 in 6), its picture faded in over the board. */
void func_8010E080_2BC940_name_41(void) {
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

/* CPU: how many coins to put in (board state counter D_800F8CE4[arg0]): a random 1-4 step by
   difficulty and how far the player's coins exceed the counter + 20 / + 40, capped at 999 and at
   the player's coins. */
s32 func_8010E290_2BCB50_name_41(s32 arg0) {
    GW_SYSTEM* gw = &GwSystem;
    s32 r;
    s32 n;

    r = MBRand(100.0f);
    if (D_800F8CE4_F98E4[arg0] + 40 < gPlayers[gw->current_player_index].coins) {
        if (gPlayers[gw->current_player_index].cpu_difficulty2 == 0) {
            if (r < 80) {
                n = 1;
            } else if (r < 95) {
                n = 2;
            } else {
                n = 3;
            }
        } else if (r < 60) {
            n = 1;
        } else if (r < 80) {
            n = 2;
        } else if (r < 90) {
            n = 3;
        } else {
            n = 4;
        }
    } else if (D_800F8CE4_F98E4[arg0] + 20 < gPlayers[gw->current_player_index].coins) {
        if (gPlayers[gw->current_player_index].cpu_difficulty2 == 0) {
            if (r < 80) {
                n = 1;
            } else if (r < 95) {
                n = 2;
            } else {
                n = 3;
            }
        } else if (r < 70) {
            n = 1;
        } else if (r < 90) {
            n = 2;
        } else {
            n = 3;
        }
    } else if (gPlayers[gw->current_player_index].cpu_difficulty2 == 0) {
        n = 1;
    } else if (r < 80) {
        n = 1;
    } else if (r < 95) {
        n = 2;
    } else {
        n = 3;
    }
    n += D_800F8CE4_F98E4[arg0];
    if (n >= 1000) {
        n = 999;
    }
    if (gPlayers[gw->current_player_index].coins < n) {
        n = gPlayers[gw->current_player_index].coins;
    }
    return n;
}

/* Whether space D_800F8CE4[arg0] + arg1 exists. */
s32 func_8010E474_2BCD34_name_41(s16 arg0, s16 arg1) {
    return BoardSpaceGet(-1, D_800F8CE4_F98E4[arg0] + arg1) != 0;
}

s32 func_8010E4B4_2BCD74_name_41(void) {
    return func_8010E474_2BCD34_name_41(1, 0x18);
}

s32 func_8010E4D4_2BCD94_name_41(void) {
    return func_8010E474_2BCD34_name_41(1, 0x14);
}

s32 func_8010E4F4_2BCDB4_name_41(void) {
    return func_8010E474_2BCD34_name_41(1, 0xA);
}

s32 func_8010E514_2BCDD4_name_41(void) {
    return func_8010E474_2BCD34_name_41(2, 0x1E);
}

s32 func_8010E534_2BCDF4_name_41(void) {
    return func_8010E474_2BCD34_name_41(2, 0x18);
}

s32 func_8010E554_2BCE14_name_41(void) {
    return func_8010E474_2BCD34_name_41(2, 0x14);
}

/* CPU: the menu row for decision tree D_80111190 (arg0 == 1) or D_80111268. */
s32 func_8010E574_2BCE34_name_41(s32 arg0) {
    s16 choice;

    if (arg0 == 1) {
        choice = func_80044800_45400(D_80111190_2BFA50_name_41);
    } else {
        choice = func_80044800_45400(D_80111268_2BFB28_name_41);
    }
    return choice + 1;
}

/* 3E's func_80103FB0 with the CPU's choice from func_8010E574(arg0). */
s32 func_8010E5B8_2BCE78_name_41(s32 arg0) {
    s32 count = 0;
    s16 sp18[4];
    u8 sp20[4];
    s32 i;
    s32 j;

    *(Unk4Bytes*)sp20 = *(Unk4Bytes*)D_80111D60_2C0620_name_41;
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            if (gPlayers[i].flags & 1) {
                count = func_8010E574_2BCE34_name_41(arg0);
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

/* Model D_80111F70[arg0] pops in: a wobble (decaying sine) around a size that grows with
   D_800F8CE4[arg0 + 1] (1 + n / 50, at most 2). */
void func_8010E7E8_2BD0A8_name_41(s32 arg0) {
    MBModel* model = D_80111F70_2C0830_name_41[arg0];
    f32 size;
    f32 amp;
    s32 angle;

    PlaySound(0x36D);
    size = (D_800F8CE4_F98E4[arg0 + 1] + 50.0f) / 50.0f;
    if (size > 2.0f) {
        size = 2.0f;
    }
    MBModelDispOn(model);
    HuVecCopyXYZ(&model->scale, 0.0f, 0.0f, 0.0f);
    for (angle = 0, amp = 1.0f; angle < 1081; angle += 45, amp -= 1.0f / 24) {
        HuVecCopyXYZ(&model->scale, (HuMathSin(angle) * amp + 1.0f) * size,
                     (HuMathSin(angle) * amp + 1.0f) * size, (HuMathSin(angle) * amp + 1.0f) * size);
        HuPrcVSleep();
    }
}

/* Model D_80111F70[arg0] shrinks away (a quarter sine, growing amplitude), then hides. */
void func_8010E960_2BD220_name_41(s32 arg0) {
    MBModel* model = D_80111F70_2C0830_name_41[arg0];
    f32 size;
    f32 amp;
    s32 angle;

    PlaySound(0x36E);
    size = (D_800F8CE4_F98E4[arg0 + 1] + 50.0f) / 50.0f;
    if (size > 2.0f) {
        size = 2.0f;
    }
    MBModelDispOn(model);
    HuVecCopyXYZ(&model->scale, 0.0f, 0.0f, 0.0f);
    for (angle = 180, amp = 0.0f; angle < 271; angle += 5, amp += 1.0f / 18) {
        HuVecCopyXYZ(&model->scale, (HuMathSin(angle) * amp + 1.0f) * size,
                     (HuMathSin(angle) * amp + 1.0f) * size, (HuMathSin(angle) * amp + 1.0f) * size);
        HuPrcVSleep();
    }
    MBModelDispOff(model);
}

__asm__(".section .rodata");
const char D_80111E58_2C0718_name_41[] = "%-3d";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_8010EADC_2BD39C_name_41);

void func_8010F318_2BDBD8_name_41(void) {
    func_8010E960_2BD220_name_41(0);
    omDelPrcObj(NULL);
}

void func_8010F33C_2BDBFC_name_41(void) {
    if (GwSystem.current_player_index != 4) {
        omAddPrcObj(func_8010F318_2BDBD8_name_41, 0x1005, 0, 0);
    }
}

void func_8010F378_2BDC38_name_41(void) {
    func_8010E960_2BD220_name_41(1);
    omDelPrcObj(NULL);
}

void func_8010F39C_2BDC5C_name_41(void) {
    if (GwSystem.current_player_index != 4) {
        omAddPrcObj(func_8010F378_2BDC38_name_41, 0x1005, 0, 0);
    }
}

/* Object func: bobs model D_80111F78 (jumpY = sin of a phase in rot.y, 2 degrees a frame). */
void func_8010F3D8_2BDC98_name_41(omObjData* obj) {
    D_80111F78_2C0838_name_41->jumpY = HuMathSin(obj->rot.y);
    obj->rot.y += 2.0f;
    if (obj->rot.y >= 360.0f) {
        obj->rot.y -= 360.0f;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_8010F448_2BDD08_name_41);

/* a run-over player: hidden when the counter runs out */
void func_8010FC00_2BE4C0_name_41(omObjData* obj) {
    GW_PLAYER* player = BoardPlayerGet(obj->work[0]);

    if (obj->work[1] == 0) {
        MBModelDispOff(player->unk_24);
        omDelObj(obj);
    }
    obj->work[1]--;
}

/* Knocks player `player` back (3E's func_80106DCC without the cart): sound, rumble, a 30-frame
   object (func_8010FC00), a jump toward pos + 100 * (1, 2, 0), back to the chain start. */
void func_8010FC54_2BE514_name_41(s32 player) {
    Vec dir;
    Vec rot;
    GW_PLAYER* p;
    omObjData* obj;

    p = BoardPlayerGet(player);
    func_800797DC_7A3DC(0x111, player);
    PlaySound(0x3AB);
    MBPlayerVibrate(player, 3);
    obj = omAddObj(0x1000, 0, 0, -1, func_8010FC00_2BE4C0_name_41);
    omSetStatBit(obj, 0xA0);
    obj->work[0] = player;
    obj->work[1] = 30;
    dir.x = 1.0f;
    dir.y = 2.0f;
    dir.z = 0.0f;
    HuVecMulScalar(&dir, 100.0f, &dir);
    HuVecAdd(&dir, &((MBModel*)p->unk_24)->pos, &dir);
    func_80056658_57258(&((MBModel*)p->unk_24)->pos, &dir, &rot);
    func_80056D80_57980(&((MBModel*)p->unk_24)->pos, &dir, &((MBModel*)p->unk_24)->pos, 30);
    p->cur_chain_index = 0;
    p->cur_space_index = 0;
    p->next_chain_index = 0;
    p->next_space_index = 1;
    ((MBModel*)p->unk_24)->attr |= 1;
    MBMotionSet(p->unk_24, 4, 2);
}

__asm__(".section .rodata");
const u32 D_80111E60_2C0720_name_41[12] = { 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0xBF800000, 0x00000000, 0x00000000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_41_name/2B10C0", func_8010FD98_2BE658_name_41);

void func_801103B4_2BEC74_name_41(void) {
    func_8010FD98_2BE658_name_41(0);
}

void func_801103D0_2BEC90_name_41(void) {
    func_8010FD98_2BE658_name_41(1);
}

/* Scene setup; MP3 func_8011A848_3AFBC8_w06. */
void func_801103EC_2BECAC_name_41(void) {
    func_80020070_20C70(2);
    CameraScissorSet(1, D_80111468_2BFD28_name_41);
    func_80105980_2B4240_name_41();
    func_80066C34_67834(2);
    omAddPrcObj(func_80102FFC_2B18BC_name_41, 0x1005, 0x1000, 0);
}

/* CPU item check (registered with func_80044D98): 1 = use the held item now. Several items are
   used on the last turn, or when their decision tree D_80112F24/80112F84/80113248/801133BC
   says so, or with enough coins. */
s32 func_80110440_2BED00_name_41(void) {
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
            if (gw->total_turns != gw->current_turn && func_80044800_45400(D_80111868_2C0128_name_41) != 0) {
                return 0;
            }
            break;
        case 8:
            if (gw->total_turns != gw->current_turn && func_80044800_45400(D_801118C8_2C0188_name_41) != 0) {
                return 0;
            }
            break;
        case 5:
            if (func_80044800_45400(D_80111A48_2C0308_name_41) != 0) {
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
            if (func_80044800_45400(D_80111B80_2C0440_name_41) != 0) {
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

/* CPU shop choice: the menu row (slot + 1) of an item to buy. Per character, D_80113510 lists
   items to try with D_80113570 percent chances (needing price + 20 coins); then items 9 and 7,
   decision trees D_8011341C (item 1) and D_80113434 (a second pass at plain price), else on
   board 4 func_80109AE4's row, else item 0's row or 1. */
s32 func_80110664_2BEF24_name_41(void) {
    GW_PLAYER* player;
    s32 slot;
    s32 i;
    s32 r;
    u8 item;
    GW_SYSTEM* gw = &GwSystem;

    player = BoardPlayerGet(-1);
    slot = -1;
    for (i = 0; i < D_80111D4C_2C060C_name_41[player->character]; i++) {
        item = D_80111CD4_2C0594_name_41[player->character][i];
        slot = func_801081E0_2B6AA0_name_41(item);
        if (slot == -1) {
            continue;
        }
        if (D_800CC000[item] + 20 > gPlayers[gw->current_player_index].coins) {
            continue;
        }
        if (RNGPercentChance(D_80111D34_2C05F4_name_41[player->character][i])) {
            break;
        }
    }
    if (i == D_80111D4C_2C060C_name_41[player->character]) {
        slot = -1;
    }
    if (slot != -1) {
        if (func_801081E0_2B6AA0_name_41(9) == slot) {
            return slot + 1;
        }
        if (func_801081E0_2B6AA0_name_41(7) == slot && D_800CC000[7] + 50 <= gPlayers[gw->current_player_index].coins) {
            return slot + 1;
        }
    }
    if (func_80044800_45400(D_80111BE0_2C04A0_name_41) == 0 && gPlayers[gw->current_player_index].coins >= D_800CC000[1]) {
        r = func_801081E0_2B6AA0_name_41(1);
        if (r != -1) {
            return r + 1;
        }
    }
    if (slot != -1) {
        return slot + 1;
    }
    i = func_80044800_45400(D_80111BF8_2C04B8_name_41);
    if (i == 0) {
        for (; i < D_80111D4C_2C060C_name_41[player->character]; i++) {
            item = D_80111CD4_2C0594_name_41[player->character][i];
            slot = func_801081E0_2B6AA0_name_41(item);
            if (slot == -1) {
                continue;
            }
            if (D_800CC000[item] > gPlayers[gw->current_player_index].coins) {
                continue;
            }
            if (RNGPercentChance(D_80111D34_2C05F4_name_41[player->character][i])) {
                return slot + 1;
            }
        }
    }
    if (gw->current_board_index == 4) {
        D_80111C88_2C0548_name_41 = 1;
        return func_8010824C_2B6B0C_name_41() + 2;
    }
    slot = func_801081E0_2B6AA0_name_41(0);
    if (slot != -1) {
        return slot + 1;
    }
    return 1;
}

/* The CPU's yes/no answer (1 or 2); MP3 func_8011D1F8_332D68_ChillyWaters. */
s32 func_801109E0_2BF2A0_name_41(void) {
    if (D_80111C88_2C0548_name_41 != 0) {
        D_80111C88_2C0548_name_41 = 0;
        return 2;
    }
    return func_80044800_45400(D_80111C64_2C0524_name_41) + 1;
}
