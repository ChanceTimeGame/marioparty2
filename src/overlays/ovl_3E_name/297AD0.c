#include "common.h"
#include "ovl_3E.h"

/* Matches, but retail pads it to 16 bytes: it is the overlay entry point, its own file in retail
   (as ovl_3D_entrypoint.c, with D_80111920 as that file's .data). Needs a
   [0x297AD0, c, ovl_3E_entrypoint] split before the C can replace the asm. */
#ifdef NON_MATCHING
void func_80102800_297AD0_name_3E(void) {
    ExecBoardScene(D_80111920_2A6BF0_name_3E, D_800CD414_CE014);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80102800_297AD0_name_3E);
#endif
s16 func_80102830_297B00_name_3E(void) {
    return D_80111994_2A6C64_name_3E[GwSystem.star_spawn_indices[GwSystem.unk_0A]];
}
void func_8010285C_297B2C_name_3E(void) {
    s32 i;
    s32 a;
    s32 b;
    s32 temp;
    GW_SYSTEM* gw = &GwSystem;

    for (i = 0; i < 60; i++) {
        a = (u8)(rand8() % 7);
        b = (u8)(rand8() % 7);
        if (a != b) {
            if (a >= D_80111960_2A6C30_name_3E[b]) {
                if (b >= D_80111960_2A6C30_name_3E[a]) {
                    temp = D_80111950_2A6C20_name_3E[a];
                    D_80111950_2A6C20_name_3E[a] = D_80111950_2A6C20_name_3E[b];
                    D_80111950_2A6C20_name_3E[b] = temp;

                    temp = D_80111960_2A6C30_name_3E[a];
                    D_80111960_2A6C30_name_3E[a] = D_80111960_2A6C30_name_3E[b];
                    D_80111960_2A6C30_name_3E[b] = temp;
                }
            }
        }
    }

    for (i = 0; i < 7; i++) {
        gw->star_spawn_indices[i] = D_80111950_2A6C20_name_3E[i];
    }

    if (gw->unk_1C == -1) {
        temp = 0;
    retry:
        gw->unk_1C = gw->star_spawn_indices[6 - temp];
        for (i = 0; D_80111970_2A6C40_name_3E[i] != -1; i++) {
            if (gw->unk_1C == D_80111970_2A6C40_name_3E[i]) {
                temp++;
                goto retry;
            }
        }
    }
}
void func_80102A44_297D14_name_3E(void) {
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
void func_80102AB0_297D80_name_3E(void) {
    s32 temp;
    GW_SYSTEM* gw = &GwSystem;

    gw->unk_1C = gw->star_spawn_indices[gw->unk_0A];
    if (++gw->unk_0A < 7) {
        return;
    }
    temp = gw->star_spawn_indices[6];
    gw->unk_0A = 0;
    _SetFlag(0x44);
    func_8010285C_297B2C_name_3E();
    if (temp != gw->star_spawn_indices[0]) {
        return;
    }
    temp = gw->star_spawn_indices[0];
    gw->star_spawn_indices[0] = gw->star_spawn_indices[6];
    gw->star_spawn_indices[6] = temp;
}

void func_80102B54_297E24_name_3E(void) {
    s32 i;
    GW_SYSTEM* gw = &GwSystem;

    for (i = 0; i < 7; i++) {
        _SetFlag(D_80111974_2A6C44_name_3E[i]);
    }
    BoardSpaceTypeSet(D_80111984_2A6C54_name_3E[gw->star_spawn_indices[gw->unk_0A]], 0xE);
    _ClearFlag(D_80111974_2A6C44_name_3E[gw->star_spawn_indices[gw->unk_0A]]);
    if (gw->unk_1C != -1) {
        BoardSpaceTypeSet(D_80111984_2A6C54_name_3E[gw->unk_1C], 0xF);
        func_800509C4_515C4(D_80111984_2A6C54_name_3E[gw->unk_1C]);
    }
}
/* D_80111974 address hoisted out of the loop (masked 10); logic matches */
#ifdef NON_MATCHING
s32 func_80102C3C_297F0C_name_3E(s32 space) {
    s32 i;
    s32 j;
    s16* spaces;
    GW_SYSTEM* gw = &GwSystem;

    i = 0;
    spaces = D_80111984_2A6C54_name_3E;
    space = (s16)space;
    do {
        if (space == spaces[i]) {
            if (i == gw->star_spawn_indices[gw->unk_0A]) {
                gw->unk_1A = D_80111974_2A6C44_name_3E[i];
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
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80102C3C_297F0C_name_3E);
#endif
void func_80102D28_297FF8_name_3E(void) {
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
    D_801136D0_2A89A0_name_3E = NULL;
    omDelPrcObj(NULL);
}
void func_80102F4C_29821C_name_3E(UnkMBGuideData* guide) {
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
void func_80102FFC_2982CC_name_3E(void) {
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
    func_8005AB50_5B750(guide->obj, 2, 8, D_801119A4_2A6C74_name_3E);
    func_80067558_68158();
    InitFadeIn(2, 16);
    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    func_80051500_52100();
    func_80053608_54208(3.0f);
    func_80102F4C_29821C_name_3E(guide);
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
        space = GetSpaceData(D_80111994_2A6C64_name_3E[gw->unk_1C]);
    } else {
        space = GetSpaceData(D_80111994_2A6C64_name_3E[gw->star_spawn_indices[gw->unk_0A]]);
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
        proc = omAddPrcObj(func_80102D28_297FF8_name_3E, 0x4800, 0, 0);
        D_801136D0_2A89A0_name_3E = proc;
        proc->user_data = space;
        HuPrcSleep(30);
    } else {
        D_801136D0_2A89A0_name_3E = NULL;
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
        while (D_801136D0_2A89A0_name_3E != NULL) {
            HuPrcVSleep();
        }
        if (D_800F8D12_F9912 != 0 && (u8)pick == 0) {
            space = GetSpaceData(D_80111994_2A6C64_name_3E[gw->star_spawn_indices[gw->unk_0A]]);
        } else {
            space = GetSpaceData(D_80111994_2A6C64_name_3E[gw->unk_1C]);
        }
        MBDCameraPos3DSet(&space->coords);
        MBCameraSpeedSet(3.5f);
        HuPrcSleep(5);
        while (func_80053998_54598() != 0) {
            HuPrcVSleep();
        }
        HuPrcSleep(5);
        MBMotionSet(guide->obj, 0, 2);
        func_80029FE4_2ABE4(guide->obj->obj->model[0], D_801119AC_2A6C7C_name_3E[gw->current_board_index]);
        func_8005B338_5BF38(guide);
        func_8005AC6C_5B86C(guide->obj, D_801119A8_2A6C78_name_3E);
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
void func_80103548_298818_name_3E(void) {
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
    PlaySound(D_801119D0_2A6CA0_name_3E == 0 ? 0x355 : 0x34E);
    star = func_80043510_44110(D_801136D4_2A89A4_name_3E == 0 ? 0x19 : 0xD, NULL);
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
    if (D_801136D4_2A89A4_name_3E == 0) {
        MBPlayerVibrate(-1, 5);
        if (D_801119D0_2A6CA0_name_3E != 0) {
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

void func_80103968_298C38_name_3E(MBModel* parent) {
    Process* proc;

    D_800FC734_FD334 = 0;
    D_801136D4_2A89A4_name_3E = 0;
    proc = omAddPrcObj(func_80103548_298818_name_3E, 0x4800, 0, 0);
    proc->user_data = parent;
    HuPrcChildLink(HuPrcCurrentGet(), proc);
    HuPrcChildWatch();
    D_800FC734_FD334 = 1;
}

void func_801039E4_298CB4_name_3E(MBModel* parent) {
    Process* proc;

    D_800FC734_FD334 = 0;
    D_801136D4_2A89A4_name_3E = 1;
    proc = omAddPrcObj(func_80103548_298818_name_3E, 0x4800, 0, 0);
    proc->user_data = parent;
    HuPrcChildLink(HuPrcCurrentGet(), proc);
    HuPrcChildWatch();
    D_800FC734_FD334 = 1;
}

void func_80103A64_298D34_name_3E(void) {
    D_800FA198_FAD98 = 1;
    D_800FC734_FD334 = 0;
    omPrcSetStatBit(HuPrcCurrentGet(), 0x80);
    func_80067C6C_6886C(gPlayers[GwSystem.current_player_index].port);
    omPrcResetStatBit(HuPrcCurrentGet(), 0x80);
    D_800FA198_FAD98 = 0;
    D_800FC734_FD334 = 1;
}

void func_80103AF4_298DC4_name_3E(void) {
    D_800FA198_FAD98 = 1;
    D_800FC734_FD334 = 0;
    omPrcSetStatBit(HuPrcCurrentGet(), 0x80);
    func_80067C6C_6886C(gPlayers[GwSystem.current_player_index].port);
    D_800FA198_FAD98 = 0;
    D_800FC734_FD334 = 1;
}

s32 func_80103B70_298E40_name_3E(void) {
    return rand8() / 256.0f * 100.0f;
}

void func_80103BC4_298E94_name_3E(void) {
    while (func_80053998_54598() != 0) {
        HuPrcVSleep();
    }
    HuPrcVSleep();
    D_801136D8_2A89A8_name_3E = func_8004CC7C_4D87C(0, 0x92, 1);
    D_801136DC_2A89AC_name_3E = func_8004CC7C_4D87C(1, 0xA0, 1);
    D_801136E8_2A89B8_name_3E = func_8004CC7C_4D87C(0xD, 0xAE, 1);
    D_801136E0_2A89B0_name_3E = func_8004CC7C_4D87C(3, 0xBC, 1);
    D_801136E4_2A89B4_name_3E = func_8004CC7C_4D87C(0xB, 0xCA, 1);
    HuPrcSleep(3);
    D_800FA198_FAD98 = 1;
    D_80101058_101C58 = 1;
}

void func_80103C94_298F64_name_3E(void) {
    D_800FA198_FAD98 = 0;
    D_80101058_101C58 = 0;
    MBHelpWinKill(D_801136D8_2A89A8_name_3E);
    MBHelpWinKill(D_801136DC_2A89AC_name_3E);
    MBHelpWinKill(D_801136E8_2A89B8_name_3E);
    MBHelpWinKill(D_801136E0_2A89B0_name_3E);
    MBHelpWinKill(D_801136E4_2A89B4_name_3E);
}

s32 func_80103CF4_298FC4_name_3E(u8* items) {
    s32 count = 0;
    s16 sp18[4];
    u8 sp20[4];
    s32 i;
    s32 j;

    *(Unk4Bytes*)sp20 = *(Unk4Bytes*)D_80113590_2A8860_name_3E;
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            if (gPlayers[i].flags & 1) {
                count = func_8011155C_2A682C_name_3E();
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

s32 func_80103FB0_299280_name_3E(void) {
    s32 count = 0;
    s16 sp18[4];
    u8 sp20[4];
    s32 i;
    s32 j;

    *(Unk4Bytes*)sp20 = *(Unk4Bytes*)D_80113590_2A8860_name_3E;
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            if (gPlayers[i].flags & 1) {
                count = func_801118D8_2A6BA8_name_3E();
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

s32 func_801041D4_2994A4_name_3E(void) {
    s32 com = 0;
    s16 sp18[4];
    u8 sp20[4];
    s32 i;

    *(Unk4Bytes*)sp20 = *(Unk4Bytes*)D_80113590_2A8860_name_3E;
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

void func_80104380_299650_name_3E(void) {
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
            D_80113710_2A89E0_name_3E = 1;
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
        if (func_80103B70_298E40_name_3E() < D_801119D4_2A6CA4_name_3E[turnBand][coinBand]) {
            D_80113710_2A89E0_name_3E = 1;
        } else {
            goto coins;
        }
    }
    if (D_80113710_2A89E0_name_3E == 1) {
        return;
    }
coins:
    for (i = 0; i < 4; i++) {
        if (i != GwSystem.current_player_index && gPlayers[i].coins != 0) {
            break;
        }
    }
    if (i != 4) {
        D_80113710_2A89E0_name_3E = 0;
    } else {
        D_80113710_2A89E0_name_3E = 2;
    }
}

#ifdef NON_MATCHING /* rodata-pending */
s32 func_801045C0_299890_name_3E(void) {
    s32 flags[4] = { 0, 0, 0, 0 };
    s32 i;
    s32 coins;
    s32 min;

    if (GwSystem.current_player_index != D_80113700_2A89D0_name_3E[0]) {
        coins = gPlayers[D_80113700_2A89D0_name_3E[0]].coins;
        i = 1;
        flags[0] = 1;
    } else {
        coins = gPlayers[D_80113700_2A89D0_name_3E[1]].coins;
        i = 2;
        flags[1] = 1;
    }
    for (; i < 4; i++) {
        if (GwSystem.current_player_index != D_80113700_2A89D0_name_3E[i]
            && gPlayers[D_80113700_2A89D0_name_3E[i]].coins + 5 >= coins) {
            flags[i] = 1;
        }
    }
    min = 4;
    for (i = 0; i < 4; i++) {
        if (flags[i] != 0 && func_80059FD0_5ABD0(D_80113700_2A89D0_name_3E[i]) < min) {
            min = func_80059FD0_5ABD0(D_80113700_2A89D0_name_3E[i]);
        }
    }
    return min;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_801045C0_299890_name_3E);
#endif

/* MP1 func_800F6B3C (ovl_65) logic, checked case by case against this asm; retail keeps the
   duplicate cases apart and reloads stars between tests (masked 541) */
#ifdef NON_MATCHING
void func_80104778_299A48_name_3E(void) {
    s32 cand[4];
    s32 count;
    s32 i;
    s32 r;

    r = func_80103B70_298E40_name_3E();
    switch (D_80113710_2A89E0_name_3E) {
    case 1:
        if (GwSystem.total_turns < GwSystem.current_turn + 5) {
            switch (func_80059FD0_5ABD0(GwSystem.current_player_index)) {
            case 0:
                if (r >= 95 && gPlayers[D_801136F0_2A89C0_name_3E[2]].stars < 2) {
                    if (gPlayers[D_801136F0_2A89C0_name_3E[2]].stars != 0) {
                        D_80113718_2A89E8_name_3E = 2;
                        break;
                    }
                }
                D_80113718_2A89E8_name_3E = 1;
                break;
            case 1:
                if (r >= 95 && gPlayers[D_801136F0_2A89C0_name_3E[2]].stars != 0) {
                    D_80113718_2A89E8_name_3E = 2;
                } else {
                    D_80113718_2A89E8_name_3E = 0;
                }
                break;
            case 2:
                if (r >= 95 && gPlayers[D_801136F0_2A89C0_name_3E[1]].stars != 0) {
                    D_80113718_2A89E8_name_3E = 1;
                } else {
                    D_80113718_2A89E8_name_3E = 0;
                }
                break;
            case 3:
                if (r > 94 && gPlayers[D_801136F0_2A89C0_name_3E[1]].stars != 0) {
                    D_80113718_2A89E8_name_3E = 1;
                } else {
                    D_80113718_2A89E8_name_3E = 0;
                }
                break;
            }
        } else {
            switch (func_80059FD0_5ABD0(GwSystem.current_player_index)) {
            case 0:
                if (r >= 80 && gPlayers[D_801136F0_2A89C0_name_3E[2]].stars < 2) {
                    if (gPlayers[D_801136F0_2A89C0_name_3E[2]].stars != 0) {
                        D_80113718_2A89E8_name_3E = 2;
                        break;
                    }
                }
                D_80113718_2A89E8_name_3E = 1;
                break;
            case 1:
                if (r >= 90 && gPlayers[D_801136F0_2A89C0_name_3E[2]].stars != 0) {
                    D_80113718_2A89E8_name_3E = 2;
                } else {
                    D_80113718_2A89E8_name_3E = 0;
                }
                break;
            case 2:
                if (r >= 90 && gPlayers[D_801136F0_2A89C0_name_3E[1]].stars != 0) {
                    D_80113718_2A89E8_name_3E = 1;
                } else {
                    D_80113718_2A89E8_name_3E = 0;
                }
                break;
            case 3:
                if (r >= 95 && gPlayers[D_801136F0_2A89C0_name_3E[1]].stars != 0) {
                    D_80113718_2A89E8_name_3E = 1;
                } else {
                    D_80113718_2A89E8_name_3E = 0;
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
            || (GwSystem.total_turns < GwSystem.current_turn + 5 && func_80103B70_298E40_name_3E() < 80)
            || func_80103B70_298E40_name_3E() < 40) {
            if (GwSystem.total_turns < GwSystem.current_turn + 5) {
                if (func_80059FD0_5ABD0(GwSystem.current_player_index) == 0) {
                    if (gPlayers[D_801136F0_2A89C0_name_3E[1]].coins == 0) {
                        goto steal;
                    }
                    if (gPlayers[D_801136F0_2A89C0_name_3E[0]].stars == gPlayers[D_801136F0_2A89C0_name_3E[1]].stars) {
                        goto one;
                    }
                    if (r < 85) {
                        D_80113718_2A89E8_name_3E = 1;
                        return;
                    }
                    goto steal;
                }
                if (gPlayers[D_801136F0_2A89C0_name_3E[0]].coins == 0) {
                    goto steal;
                }
                if (gPlayers[D_801136F0_2A89C0_name_3E[0]].stars - 1 <= gPlayers[D_801136F0_2A89C0_name_3E[1]].stars) {
                    if (r < 80) {
                        goto zero;
                    }
                    goto steal;
                }
                if (gPlayers[D_801136F0_2A89C0_name_3E[0]].stars - 2 == gPlayers[D_801136F0_2A89C0_name_3E[1]].stars) {
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
                if (gPlayers[D_801136F0_2A89C0_name_3E[1]].coins == 0) {
                    goto steal;
                }
                if (gPlayers[D_801136F0_2A89C0_name_3E[0]].stars != gPlayers[D_801136F0_2A89C0_name_3E[1]].stars
                    && r >= 35) {
                    goto steal;
                }
            one:
                D_80113718_2A89E8_name_3E = 1;
                return;
            }
            if (gPlayers[D_801136F0_2A89C0_name_3E[0]].coins == 0) {
                goto steal;
            }
            if (gPlayers[D_801136F0_2A89C0_name_3E[0]].stars - 1 <= gPlayers[D_801136F0_2A89C0_name_3E[1]].stars) {
                if (r < 60) {
                    goto zero;
                }
                goto steal;
            }
            if (gPlayers[D_801136F0_2A89C0_name_3E[0]].stars - 2 == gPlayers[D_801136F0_2A89C0_name_3E[1]].stars) {
                if (r < 75) {
                    goto zero;
                }
                goto steal;
            }
            if (r >= 80) {
                goto steal;
            }
        zero:
            D_80113718_2A89E8_name_3E = 0;
            return;
        steal:
            D_80113718_2A89E8_name_3E = func_801045C0_299890_name_3E();
            return;
        }
        for (i = 0; i < 4; i++) {
            if (cand[D_801136F0_2A89C0_name_3E[i]] != 0) {
                if (--count == 0) {
                    D_80113718_2A89E8_name_3E = i;
                    return;
                }
            }
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80104778_299A48_name_3E);
#endif

/* register allocation: i/coin-rank/j registers rotated (masked 0), as in MP1 func_800F7278 */
#ifdef NON_MATCHING
void func_80104F7C_29A24C_name_3E(void) {
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
        D_801136F0_2A89C0_name_3E[i] = -1;
        D_80113700_2A89D0_name_3E[i] = -1;
    }
    for (i = 0; i < 4; i++) {
        rank = func_80059FD0_5ABD0(i);
    starSlot:
        if (D_801136F0_2A89C0_name_3E[rank] != -1) {
            rank++;
            goto starSlot;
        }
        D_801136F0_2A89C0_name_3E[rank] = i;
        coinRank = 0;
        for (j = 0; j < 4; j++) {
            if (i != j) {
                coinRank += gPlayers[i].coins < gPlayers[j].coins;
            }
        }
    coinSlot:
        if (D_80113700_2A89D0_name_3E[coinRank] != -1) {
            coinRank++;
            goto coinSlot;
        }
        D_80113700_2A89D0_name_3E[coinRank] = i;
    }
    D_80113710_2A89E0_name_3E = D_80113714_2A89E4_name_3E = D_80113718_2A89E8_name_3E = -1;
    func_80104380_299650_name_3E();
    if (D_80113718_2A89E8_name_3E == -1) {
        func_80104778_299A48_name_3E();
    }
    while (starRankCount[D_80113718_2A89E8_name_3E] == 0) {
        D_80113718_2A89E8_name_3E--;
    }
    rank = func_80059FD0_5ABD0(GwSystem.current_player_index);
    if (rank == D_80113718_2A89E8_name_3E) {
        starRankCount[rank]--;
    }
    j = rand8() % starRankCount[D_80113718_2A89E8_name_3E];
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            continue;
        }
        if (D_80113718_2A89E8_name_3E != func_80059FD0_5ABD0(i)) {
            continue;
        }
        if (j != 0) {
            j--;
            continue;
        }
        D_80113714_2A89E4_name_3E = i;
        break;
    }
    if (D_80113710_2A89E0_name_3E == 0 && gPlayers[D_80113714_2A89E4_name_3E].coins == 0) {
        for (i = 0; i < 4; i++) {
            if (i != GwSystem.current_player_index && gPlayers[i].coins != 0) {
                D_80113714_2A89E4_name_3E = i;
                break;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80104F7C_29A24C_name_3E);
#endif

s32 func_8010537C_29A64C_name_3E(u8* items) {
    s32 count = 0;
    s16 sp18[4];
    u8 sp20[4];
    s32 i;
    s32 j;

    *(Unk4Bytes*)sp20 = *(Unk4Bytes*)D_80113590_2A8860_name_3E;
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            if (gPlayers[i].flags & 1) {
                func_80104F7C_29A24C_name_3E();
                count = D_80113710_2A89E0_name_3E + 1;
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

s32 func_80105630_29A900_name_3E(s32 arg0, u8* items) {
    s32 count = 0;
    s16 sp18[4];
    u8 sp20[4];
    s32 i;

    *(Unk4Bytes*)sp20 = *(Unk4Bytes*)D_80113590_2A8860_name_3E;
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            if (gPlayers[i].flags & 1) {
                count = D_80113714_2A89E4_name_3E;
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

void func_801058A4_29AB74_name_3E(void) {
    GW_SYSTEM* gw = &GwSystem;

    gw->current_board_index = 0;
    omInitObjMan(10, 0);
    omOvlGotoEx(0x3D, 0, 0x192);
}

void func_801058DC_29ABAC_name_3E(void) {
    omInitObjMan(10, 0);
    SetPlayerOntoChain(0, 0, 0);
    SetPlayerOntoChain(1, 0, 0);
    SetPlayerOntoChain(2, 0, 0);
    SetPlayerOntoChain(3, 0, 0);
    _SetFlag(0x43);
    func_8010285C_297B2C_name_3E();
    D_800F8CE4_F98E4[0] = 0;
    D_800F8CE4_F98E4[0x1E] = 0;
    D_800F8CE4_F98E4[0x1D] = 0;
    D_800F8CE4_F98E4[0x1A] = 0;
    D_800F8CE4_F98E4[0x19] = 0;
    D_800F8CE4_F98E4[0x17] = 0;
    omOvlReturnEx(1);
}

void func_80105974_29AC44_name_3E(void) {
    s32 i;

    omInitObjMan(0xA0, 0x28);
    func_80026DAC_279AC(1, 100, 100, 100);
    func_80026DAC_279AC(2, 200, 200, 200);
    func_80062E10_63A10(2, 0x40, 8, 0);
    func_80055928_56528(D_801119E4_2A6CB4_name_3E);
    func_80055980_56580(D_801119F4_2A6CC4_name_3E);
    func_8004D60C_4E20C(0, func_8010BA48_2A0D18_name_3E);
    func_8004D60C_4E20C(1, func_8010C6DC_2A19AC_name_3E);
    func_8004D60C_4E20C(8, func_8010CA78_2A1D48_name_3E);
    func_8004D60C_4E20C(2, func_8010CAE8_2A1DB8_name_3E);
    func_8004D60C_4E20C(3, func_8010DE58_2A3128_name_3E);
    func_8004D60C_4E20C(4, func_8010E3D0_2A36A0_name_3E);
    func_8004D60C_4E20C(5, func_8010E640_2A3910_name_3E);
    func_8004D60C_4E20C(6, func_8010CFCC_2A229C_name_3E);
    func_8004D60C_4E20C(7, func_8010D9F4_2A2CC4_name_3E);
    func_8004D60C_4E20C(9, func_8010E874_2A3B44_name_3E);
    func_8004D60C_4E20C(10, func_8010EB88_2A3E58_name_3E);
    func_8004D60C_4E20C(12, func_8010F1FC_2A44CC_name_3E);
    func_8004D60C_4E20C(11, func_8010F430_2A4700_name_3E);
    func_8004D60C_4E20C(13, func_8010F940_2A4C10_name_3E);
    func_80044D98_45998(func_80111338_2A6608_name_3E);
    for (i = 0; i < 7; i++) {
        func_800542E8_54EE8(i, D_80111994_2A6C64_name_3E[i]);
    }
    if (_CheckFlag(0x4D)) {
        _ClearFlag(0x4D);
        if (D_800F8D12_F9912 != 0) {
            func_80102A44_297D14_name_3E();
        } else {
            func_80102AB0_297D80_name_3E();
        }
    }
    func_80102B54_297E24_name_3E();
    func_80105DDC_29B0AC_name_3E();
    func_80105D54_29B024_name_3E();
    func_8010602C_29B2FC_name_3E();
    func_801062F4_29B5C4_name_3E();
    func_801064B8_29B788_name_3E();
    func_80106684_29B954_name_3E();
    func_801066FC_29B9CC_name_3E();
    func_80106C44_29BF14_name_3E();
}

void func_80105B9C_29AE6C_name_3E(void) {
    PlayMusic(8);
    func_800632F0_63EF0(8);
    func_80020070_20C70(2);
    func_80105974_29AC44_name_3E();
    omAddObj(1000, 0, 0, -1, func_80106944_29BC14_name_3E);
    func_80053AA0_546A0(0);
    EventTableHydrate(D_80112484_2A7754_name_3E);
    EventTableHydrate(D_8011280C_2A7ADC_name_3E);
    EventTableHydrate(D_801124EC_2A77BC_name_3E);
    func_80066C34_67834(0);
}

void func_80105C24_29AEF4_name_3E(void) {
    func_80020070_20C70(1);
    func_80105974_29AC44_name_3E();
    func_80066C34_67834(1);
}

void func_80105C50_29AF20_name_3E(s16 arg0) {
    MBModel* obj;

    if (D_80113720_2A89F0_name_3E[arg0] == NULL) {
        if (D_8011371C_2A89EC_name_3E == NULL) {
            obj = func_80043510_44110(0x17, NULL);
            func_80043DAC_449AC(obj);
            D_8011371C_2A89EC_name_3E = obj;
        } else {
            obj = MBModelParamCreate(D_8011371C_2A89EC_name_3E);
        }
        D_80113720_2A89F0_name_3E[arg0] = obj;
        obj->attr |= 2;
        func_80056754_57354(obj);
        func_800B3170_B3D70(&obj->pos, &GetSpaceData(D_80111A44_2A6D14_name_3E[arg0])->coords);
        func_80041AEC_426EC(6, obj, D_80111A04_2A6CD4_name_3E[arg0][0], D_80111A04_2A6CD4_name_3E[arg0][1]);
    }
}

void func_80105D54_29B024_name_3E(void) {
    s32 i;

    D_8011371C_2A89EC_name_3E = NULL;
    for (i = 0; i < 7; i++) {
        D_80113720_2A89F0_name_3E[i] = NULL;
        if (_CheckFlag(D_80111A54_2A6D24_name_3E[i]) == 0) {
            func_80105C50_29AF20_name_3E(i);
        }
    }
}

void func_80105DDC_29B0AC_name_3E(void) {
    MBModel* obj;
    GW_SYSTEM* gw = &GwSystem;

    if (gw->unk_1C != -1) {
        obj = func_80043510_44110(D_800F8D12_F9912 != 0 ? 0x17 : 0x1D, NULL);
        func_80043DAC_449AC(obj);
        D_800F64C8_F70C8 = obj;
        obj->attr |= 2;
        func_80056754_57354(obj);
        func_800B3170_B3D70(&obj->pos, &GetSpaceData(D_80111A44_2A6D14_name_3E[gw->unk_1C])->coords);
        D_80111A64_2A6D34_name_3E = func_80041AEC_426EC(0xB, obj, D_80111A04_2A6CD4_name_3E[gw->unk_1C][0],
                                                       D_80111A04_2A6CD4_name_3E[gw->unk_1C][1]);
    } else {
        D_800F64C8_F70C8 = NULL;
    }
}

void func_80105EC4_29B194_name_3E(void) {
    if (D_800F64C8_F70C8 != NULL) {
        MBModelKill(D_800F64C8_F70C8);
    }
    if (D_80111A64_2A6D34_name_3E != -1) {
        func_80041B40_42740(D_80111A64_2A6D34_name_3E);
    }
}

void func_80105F0C_29B1DC_name_3E(s16 arg0) {
    MBModel* obj;

    if (D_80113740_2A8A10_name_3E[arg0] != NULL) {
        return;
    }
    if (D_8011373C_2A8A0C_name_3E == NULL) {
        obj = func_80043510_44110(8, NULL);
        func_8002D124_2DD24(obj->obj->model[0]);
        func_8002D124_2DD24(obj->shadow->model[0]);
        D_8011373C_2A8A0C_name_3E = obj;
    } else {
        obj = MBModelParamCreate(D_8011373C_2A8A0C_name_3E);
    }
    MBModelDispOff(obj);
    D_80113740_2A8A10_name_3E[arg0] = obj;
    obj->attr |= 2;
    obj->jumpY = 10.0f;
    func_800B3170_B3D70(&obj->pos, &GetSpaceData(D_80111A68_2A6D38_name_3E[arg0])->coords);
    func_80041AEC_426EC(8, obj, D_80111A20_2A6CF0_name_3E[arg0][0], D_80111A20_2A6CF0_name_3E[arg0][1]);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010602C_29B2FC_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010608C_29B35C_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80106188_29B458_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_801062F4_29B5C4_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010635C_29B62C_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_801064B8_29B788_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80106518_29B7E8_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80106574_29B844_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80106618_29B8E8_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80106684_29B954_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_801066FC_29B9CC_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80106738_29BA08_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80106944_29BC14_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_801069C8_29BC98_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80106B08_29BDD8_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80106C44_29BF14_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80106D78_29C048_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80106DCC_29C09C_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80106FE0_29C2B0_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_801075F8_29C8C8_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80107C54_29CF24_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80107D6C_29D03C_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80107E84_29D154_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80107F9C_29D26C_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_801080B4_29D384_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_801081CC_29D49C_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80108424_29D6F4_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010871C_29D9EC_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80108A14_29DCE4_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80108A38_29DD08_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80108A5C_29DD2C_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80108A80_29DD50_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80108AA4_29DD74_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80108AC8_29DD98_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80108AEC_29DDBC_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80108B10_29DDE0_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80108B34_29DE04_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80108B58_29DE28_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80108B7C_29DE4C_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80108BA0_29DE70_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80108BC4_29DE94_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80108BE8_29DEB8_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80108C0C_29DEDC_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80108E0C_29E0DC_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010964C_29E91C_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80109A78_29ED48_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80109AE4_29EDB4_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80109B30_29EE00_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010A13C_29F40C_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010A1DC_29F4AC_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010A27C_29F54C_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010AB58_29FE28_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010AB7C_29FE4C_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010B8B8_2A0B88_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010BA0C_2A0CDC_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010BA48_2A0D18_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010C44C_2A171C_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010C468_2A1738_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010C484_2A1754_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010C5C4_2A1894_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010C6DC_2A19AC_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010CA78_2A1D48_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010CAE8_2A1DB8_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010CCD4_2A1FA4_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010CF20_2A21F0_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010CFCC_2A229C_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010D37C_2A264C_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010D6C8_2A2998_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010D9F4_2A2CC4_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010DE58_2A3128_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010E3D0_2A36A0_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010E640_2A3910_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010E874_2A3B44_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010EB88_2A3E58_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010F1FC_2A44CC_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010F430_2A4700_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010F940_2A4C10_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010FB50_2A4E20_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010FD84_2A5054_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_801104E0_2A57B0_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80110794_2A5A64_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80110F78_2A6248_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_801112E4_2A65B4_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80111338_2A6608_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8011155C_2A682C_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_801118D8_2A6BA8_name_3E);
