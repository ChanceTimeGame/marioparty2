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

void func_8010602C_29B2FC_name_3E(void) {
    s32 i;

    D_8011373C_2A8A0C_name_3E = NULL;
    for (i = 0; i < 2; i++) {
        D_80113740_2A8A10_name_3E[i] = NULL;
        func_80105F0C_29B1DC_name_3E(i);
    }
}

void func_8010608C_29B35C_name_3E(void) {
    s32 i;
    s32 j;
    s32 count;

    for (i = 0; i < 2; i++) {
        count = (D_800F8CE4_F98E4[0x1D] + 9) / 10;
        if (count > 5) {
            count = 5;
        }
        for (j = 0; j < count; j++) {
            MBModelDispOn(D_80113750_2A8A20_name_3E[i * 5 + j]);
        }
        for (; j < 5; j++) {
            MBModelDispOff(D_80113750_2A8A20_name_3E[i * 5 + j]);
        }
    }
}

void func_80106188_29B458_name_3E(s16 arg0) {
    MBModel* coin;
    Vec* pos;
    s32 bank;
    s16 slot;

    if (D_80113750_2A8A20_name_3E[arg0] == NULL) {
        if (D_80113748_2A8A18_name_3E == NULL) {
            coin = func_80043510_44110(0x6C, NULL);
            func_80043DAC_449AC(coin);
            D_80113748_2A8A18_name_3E = coin;
        } else {
            coin = MBModelParamCreate(D_80113748_2A8A18_name_3E);
        }
        D_80113750_2A8A20_name_3E[arg0] = coin;
        coin->attr |= 2;

        bank = arg0 / 5;
        pos = &coin->pos;
        func_800B3170_B3D70(pos, &GetSpaceData(D_80111A6C_2A6D3C_name_3E[bank])->coords);

        slot = arg0 % 5;
        HuVecAdd(pos, &D_80111A70_2A6D40_name_3E[slot], pos);
        coin->obj->rot.x = D_80111AAC_2A6D7C_name_3E[slot].x;
        coin->obj->rot.z = D_80111AAC_2A6D7C_name_3E[slot].z;
        MBModelDispOff(coin);
    }
}

void func_801062F4_29B5C4_name_3E(void) {
    s32 i;

    D_80113748_2A8A18_name_3E = NULL;
    for (i = 0; i < 10; i++) {
        D_80113750_2A8A20_name_3E[i] = NULL;
        func_80106188_29B458_name_3E(i);
    }
    func_8010608C_29B35C_name_3E();
}

void func_8010635C_29B62C_name_3E(s16 arg0) {
    MBModel* obj;
    SpaceData* space;
    char pad[4]; /* frame size, as MP3 func_80108748 (ChillyWaters) */

    if (D_8011377C_2A8A4C_name_3E[arg0] == NULL) {
        if (D_80113778_2A8A48_name_3E == NULL) {
            /* D_80111AED[board * 2]: column 1 of a u8 [][2] table one byte before it */
            obj = func_80043510_44110(D_80111AED_2A6DBD_name_3E[GwSystem.current_board_index * 2], NULL);
            func_80043DAC_449AC(obj);
            D_80113778_2A8A48_name_3E = obj;
        } else {
            obj = MBModelParamCreate(D_80113778_2A8A48_name_3E);
        }
        D_8011377C_2A8A4C_name_3E[arg0] = obj;
        obj->attr |= 2;
        func_80029E80_2AA80(obj->obj->model[0], 2, 1);
        func_800B3170_B3D70(&obj->pos, &GetSpaceData(D_80111AE8_2A6DB8_name_3E[arg0])->coords);
        space = GetSpaceData(D_80111A3C_2A6D0C_name_3E[arg0][0]);
        func_80056658_57258(&GetSpaceData(D_80111A3C_2A6D0C_name_3E[arg0][1])->coords, &space->coords, &obj->rot);
        func_80041AEC_426EC(0xC, obj, D_80111A34_2A6D04_name_3E[arg0][0], D_80111A34_2A6D04_name_3E[arg0][1]);
    }
}

void func_801064B8_29B788_name_3E(void) {
    s32 i;

    D_80113778_2A8A48_name_3E = NULL;
    for (i = 0; i < 2; i++) {
        D_8011377C_2A8A4C_name_3E[i] = NULL;
        func_8010635C_29B62C_name_3E(i);
    }
}

void func_80106518_29B7E8_name_3E(void) {
    HuPrcSleep(D_80111B40_2A6E10_name_3E[GwSystem.current_board_index]);
    PlaySound((s16)D_80111B1C_2A6DEC_name_3E[GwSystem.current_board_index]);
    omDelPrcObj(NULL);
}

void func_80106574_29B844_name_3E(s32 arg0) {
    func_80029E80_2AA80(D_8011377C_2A8A4C_name_3E[arg0]->obj->model[0], 5, 0);
    if (D_80111AF8_2A6DC8_name_3E[GwSystem.current_board_index] != -1) {
        PlaySound((s16)D_80111AF8_2A6DC8_name_3E[GwSystem.current_board_index]);
    }
    if (D_80111B1C_2A6DEC_name_3E[GwSystem.current_board_index] != -1) {
        omAddPrcObj(func_80106518_29B7E8_name_3E, 0x1000, 0, 0);
    }
}

void func_80106618_29B8E8_name_3E(s32 arg0) {
    func_80029E80_2AA80(D_8011377C_2A8A4C_name_3E[arg0]->obj->model[0], 1, 4);
    if (D_80111B64_2A6E34_name_3E[GwSystem.current_board_index] != -1) {
        PlaySound((s16)D_80111B64_2A6E34_name_3E[GwSystem.current_board_index]);
    }
}

void func_80106684_29B954_name_3E(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        func_80041B60_42760(10, &GetSpaceData(D_80111B88_2A6E58_name_3E[i])->coords, D_80111A28_2A6CF8_name_3E[i][0],
                            D_80111A28_2A6CF8_name_3E[i][1]);
    }
}

void func_801066FC_29B9CC_name_3E(void) {
    func_80041B60_42760(9, &GetSpaceData(D_80111B8C_2A6E5C_name_3E)->coords, D_80111A30_2A6D00_name_3E[0],
                        D_80111A30_2A6D00_name_3E[1]);
}

void func_80106738_29BA08_name_3E(void) {
    Vec pos;
    Vec start;
    f32 angle;
    s32 i;

    func_800B3170_B3D70(&pos, &D_80113784_2A8A54_name_3E->pos);
    angle = func_80042BE0_437E0(&D_80113784_2A8A54_name_3E->rot) + 180.0f;
    start.x = HuMathSin(angle) * 24.0f + pos.x;
    start.y = pos.y;
    start.z = func_800B7890_B8490(angle) * 24.0f + pos.z;
    pos.x = (pos.x - start.x) / 12.0f;
    pos.y = (pos.y - start.y) / 12.0f;
    pos.z = (pos.z - start.z) / 12.0f;
    for (i = 0; i < 12; i++) {
        HuVecCopyXYZ(&D_80113790_2A8A60_name_3E[i], i * pos.x + start.x, i * pos.y + start.y, i * pos.z + start.z);
        func_800B3170_B3D70(&D_80113820_2A8AF0_name_3E[i], &D_80113784_2A8A54_name_3E->rot);
    }
    D_801138B0_2A8B80_name_3E = 0;
    HuVecCopyXYZ(&D_80113788_2A8A58_name_3E->pos, D_80113790_2A8A60_name_3E[D_801138B0_2A8B80_name_3E].x,
                 D_80113790_2A8A60_name_3E[D_801138B0_2A8B80_name_3E].y,
                 D_80113790_2A8A60_name_3E[D_801138B0_2A8B80_name_3E].z);
    HuVecCopyXYZ(&D_80113788_2A8A58_name_3E->rot, D_80113820_2A8AF0_name_3E[D_801138B0_2A8B80_name_3E].x,
                 D_80113820_2A8AF0_name_3E[D_801138B0_2A8B80_name_3E].y,
                 D_80113820_2A8AF0_name_3E[D_801138B0_2A8B80_name_3E].z);
}

void func_80106944_29BC14_name_3E(void) {
    GW_PLAYER* player;

    player = BoardPlayerGet(-1);
    if (D_8011378C_2A8A5C_name_3E != 0) {
        func_800B3170_B3D70(&((MBModel*)player->unk_24)->pos, &D_80113788_2A8A58_name_3E->pos);
        ((MBModel*)player->unk_24)->pos.y += 7.0f;
        func_800B3170_B3D70(&((MBModel*)player->unk_24)->rot, &D_80113788_2A8A58_name_3E->rot);
    }
}

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

/* Plunder chest (item event 3): take a random other player's item.
   register allocation only (masked 0): target and its gPlayers offset swap s0/s1. */
#ifdef NON_MATCHING /* NON_MATCHING */
void func_8010DE58_2A3128_name_3E(void) {
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
    func_8010D37C_2A264C_name_3E();
    HuPrcChildLink(HuPrcCurrentGet(),
                   func_8010CF20_2A21F0_name_3E(-1, D_80112544_2A7814_name_3E[gw->current_player_index].x,
                                                D_80112544_2A7814_name_3E[gw->current_player_index].y,
                                                D_80112524_2A77F4_name_3E[gw->current_player_index].x,
                                                D_80112524_2A77F4_name_3E[gw->current_player_index].y, 1));
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
                   func_8010CF20_2A21F0_name_3E(-1, D_80112524_2A77F4_name_3E[gw->current_player_index].x,
                                                D_80112524_2A77F4_name_3E[gw->current_player_index].y,
                                                D_80112564_2A7834_name_3E[gw->current_player_index].x,
                                                D_80112564_2A7834_name_3E[gw->current_player_index].y, 5));
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
    func_8010D6C8_2A2998_name_3E();
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010DE58_2A3128_name_3E);
#endif

/* Bowser suit start (item event 4); MP3 MB1Ev_KSuitStart. */
#ifdef NON_MATCHING /* rodata-pending */
void func_8010E3D0_2A36A0_name_3E(void) {
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
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010E3D0_2A36A0_name_3E);
#endif

/* Bowser suit end (item event 5); MP3 MB1Ev_KSuitEnd. */
#ifdef NON_MATCHING /* rodata-pending */
void func_8010E640_2A3910_name_3E(void) {
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
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010E640_2A3910_name_3E);
#endif

/* Board event 9: the current player gets item 3, shown in their status window. */
void func_8010E874_2A3B44_name_3E(void) {
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
                   func_8010CF20_2A21F0_name_3E(-1, D_80112504_2A77D4_name_3E[gw->current_player_index].x,
                                                D_80112504_2A77D4_name_3E[gw->current_player_index].y,
                                                D_80112524_2A77F4_name_3E[gw->current_player_index].x,
                                                D_80112524_2A77F4_name_3E[gw->current_player_index].y, 1));
    HuPrcChildWatch();
    PlaySound(0x19);
    for (i = 1; i < 10; i++) {
        func_800629F0_635F0(gw->current_player_index, i * 25);
        HuPrcVSleep();
    }
    func_800629F0_635F0(gw->current_player_index, 0x100);
    MBPlayerMotionSet(-1, 3, 0);
    HuPrcSleep(30);
    MBDlgResultWinExec(D_80112584_2A7854_name_3E[gw->current_board_index]);
    PlaySound(0x375);
    HuPrcChildLink(HuPrcCurrentGet(),
                   func_8010CF20_2A21F0_name_3E(-1, D_80112524_2A77F4_name_3E[gw->current_player_index].x,
                                                D_80112524_2A77F4_name_3E[gw->current_player_index].y,
                                                D_80112504_2A77D4_name_3E[gw->current_player_index].x,
                                                D_80112504_2A77D4_name_3E[gw->current_player_index].y, 30));
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
#ifdef NON_MATCHING /* rodata-pending */
void func_8010EB88_2A3E58_name_3E(void) {
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
                           func_8010CF20_2A21F0_name_3E(-1, D_80112504_2A77D4_name_3E[gw->current_player_index].x,
                                                        D_80112504_2A77D4_name_3E[gw->current_player_index].y,
                                                        D_80112524_2A77F4_name_3E[gw->current_player_index].x,
                                                        D_80112524_2A77F4_name_3E[gw->current_player_index].y, 30));
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
        func_80108C0C_29DEDC_name_3E();
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

    for (rot = 0.0f, scale = 1.0f; scale < 10.0f; rot += 20.0f, HuPrcVSleep(), scale += 0.5) {
        HuVecCopyXYZ(&obj->scale, scale, scale, scale);
        func_800B3B80_B4780(D_800FC834_FD434[obj->obj->model[0]].mtx, rot);
    }

    func_800509FC_515FC();
    MBModelDispOff(D_800F64C8_F70C8);

    for (; scale >= 1.0f; rot += 20.0f, HuPrcVSleep(), scale -= 0.5) {
        HuVecCopyXYZ(&obj->scale, scale, scale, scale);
        func_800B3B80_B4780(D_800FC834_FD434[obj->obj->model[0]].mtx, rot);
    }
    MBModelKill(obj);
    func_80054C78_55878(D_80111984_2A6C54_name_3E[gw->unk_1C], &player->cur_chain_index, &player->cur_space_index);
    player->next_chain_index = player->cur_chain_index;
    player->next_space_index = player->cur_space_index + 1;
    space = GetSpaceData(D_80111984_2A6C54_name_3E[gw->unk_1C]);
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
    MBDlgWinExec(D_8011259C_2A786C_name_3E[gw->current_board_index], D_80112584_2A7854_name_3E[gw->current_board_index] + 1);
    MBKSuitMotionSet(-1, 2);
    HuPrcVSleep();
    func_800495D8_4A1D8(gw->current_player_index, 3);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010EB88_2A3E58_name_3E);
#endif

/* Board event 12: the Bowser suit wears off (the current player is shown again). */
#ifdef NON_MATCHING /* rodata-pending */
void func_8010F1FC_2A44CC_name_3E(void) {
    MBModel* obj;
    f32 scale;
    f32 rot;

    func_800794A8_7A0A8(60);
    PlaySound(0x36C);
    obj = func_80043510_44110(0x6F, NULL);
    func_800B3170_B3D70(&obj->pos, &D_800CC1F0_CCDF0->pos);
    obj->pos.z += 20.0f;
    obj->pos.y += 30.0f;

    for (rot = 0.0f, scale = 1.0f; scale < 10.0f; rot += 20.0f, HuPrcVSleep(), scale += 0.5) {
        HuVecCopyXYZ(&obj->scale, scale, scale, scale);
        func_800B3B80_B4780(D_800FC834_FD434[obj->obj->model[0]].mtx, rot);
    }

    func_800636F8_642F8(3);
    func_80050860_51460();

    for (; scale >= 1.0f; rot += 20.0f, HuPrcVSleep(), scale -= 0.5) {
        HuVecCopyXYZ(&obj->scale, scale, scale, scale);
        func_800B3B80_B4780(D_800FC834_FD434[obj->obj->model[0]].mtx, rot);
    }
    MBModelKill(obj);
    PlayMusic(func_800632FC_63EFC());
    MBDlgResultWinExec(D_80112584_2A7854_name_3E[GwSystem.current_board_index] + 8);
    D_800F8D16_F9916 = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010F1FC_2A44CC_name_3E);
#endif

/* Board event 11 (Bowser suit passing players): every player on the current player's space is
   stomped and loses all their coins; the richest one's coins go to the current player.
   Differs only in the message index: retail adds count + 1 to the table entry, GCC here adds 1
   to the entry first (masked 2). */
#ifdef NON_MATCHING /* NON_MATCHING */
void func_8010F430_2A4700_name_3E(void) {
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
            func_80056368_56F68(D_8011259C_2A786C_name_3E[gw->current_board_index],
                                D_80112584_2A7854_name_3E[gw->current_board_index] + 6, (s32)names[0], 0, 0, 0, 0);
            func_80056458_57058();
            MBDlgWinClose();
            func_80056168_56D68();
        } else {
            MBDlgWinExec(D_8011259C_2A786C_name_3E[gw->current_board_index],
                         D_80112584_2A7854_name_3E[gw->current_board_index] + 7);
        }
    } else {
        names[0][0] = names[1][0] = names[2][0] = names[3][0] = 0;
        for (i = 0; i < count; i++) {
            names[i][0] = 0x18;
            names[i][1] = gPlayers[hit[i]].character;
            names[i][2] = 0;
        }
        func_80056368_56F68(D_8011259C_2A786C_name_3E[gw->current_board_index],
                            (count + 1) + D_80112584_2A7854_name_3E[gw->current_board_index], (s32)names[0],
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
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010F430_2A4700_name_3E);
#endif

/* Board event 13: a random item (5 in 6), its picture faded in over the board. */
void func_8010F940_2A4C10_name_3E(void) {
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

/* Yes/no choice (as func_80103FB0, with the CPU's answer from the decision tree D_801126BC);
   MP3 func_80106F58_39C2D8_w06. */
s32 func_8010FB50_2A4E20_name_3E(void) {
    s32 count = 0;
    s16 sp18[4];
    u8 sp20[4];
    s32 i;
    s32 j;

    *(Unk4Bytes*)sp20 = *(Unk4Bytes*)D_80113590_2A8860_name_3E;
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            if (gPlayers[i].flags & 1) {
                count = func_80044800_45400(D_801126BC_2A798C_name_3E) + 1;
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

/* Board event: for 20 coins the current player calls everyone to the space D_8011273C and the
   other players are moved up to them (message 0xEF asks, 0xF0 too few coins, 0xF1 declined). */
void func_8010FD84_2A5054_name_3E(void) {
    char name[16];
    Vec pos[4];
    GW_PLAYER* player;
    SpaceData* space;
    void* sp;
    s32 choice;
    s32 i;
    s32 k;
    s16 spaceIdx;
    GW_SYSTEM* gw;

    spaceIdx = func_800558F4_564F4();
    gw = &GwSystem;
    if (gw->current_player_index == 4) {
        return;
    }
    func_80046D2C_4792C(gw->current_player_index);
    MBPlayerMotionSet(-1, -1, 2);
    func_80056C30_57830(-1, 8, 0x98);
    HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.6f));
    HuPrcChildWatch();
    if (gPlayers[gw->current_player_index].coins < 20) {
        MBDlgWinExec(0x16, 0xF0);
    } else {
    ask:
        name[0] = 0x18;
        name[1] = gPlayers[gw->current_player_index].character;
        name[2] = 0;
        func_80056368_56F68(0x16, 0xEF, (s32)name, 0, 0, 0, 0);
        choice = func_8010FB50_2A4E20_name_3E();
        MBDlgWinClose();
        func_80056168_56D68();
        switch (choice) {
            case 0:
                func_8004CA34_4D634(gw->current_player_index, -20);
                func_800614B4_620B4(gw->current_player_index, -20);
                HuPrcSleep(30);
                for (i = 0; i < 4; i++) {
                    if (i != gw->current_player_index) {
                        MBModelDispOff(BoardPlayerGet(i)->unk_24);
                        MBModelDispOff(BoardPlayerGet(i)->unk_24);
                    }
                }
                MBDlgWinExec(0x16, 0xF2);
                space = GetSpaceData(D_8011273C_2A7A0C_name_3E);
                for (i = 0, k = 1; i < 4; i++) {
                    if (i != gw->current_player_index) {
                        HuVecCopyXYZ(&((MBModel*)BoardPlayerGet(i)->unk_24)->pos,
                                     space->coords.x + D_8011271C_2A79EC_name_3E[k].x, space->coords.y,
                                     space->coords.z + D_8011271C_2A79EC_name_3E[k].y);
                        MBModelDispOn(BoardPlayerGet(i)->unk_24);
                        k++;
                    }
                }
                func_800636F8_642F8(3);
                space = GetSpaceData(spaceIdx);
                for (i = 0, k = 1; i < 4; i++) {
                    player = BoardPlayerGet(i);
                    if (i == gw->current_player_index) {
                        func_800B3170_B3D70(&pos[i], &((MBModel*)player->unk_24)->pos);
                        pos[i].x += D_8011271C_2A79EC_name_3E[0].x;
                        pos[i].z += D_8011271C_2A79EC_name_3E[0].y;
                        func_80056658_57258(&((MBModel*)player->unk_24)->pos, &pos[i], &((MBModel*)player->unk_24)->rot);
                        func_80056D80_57980(&((MBModel*)player->unk_24)->pos, &pos[i], &((MBModel*)player->unk_24)->pos, 10);
                    } else {
                        func_800B3170_B3D70(&pos[i], &space->coords);
                        pos[i].x += D_8011271C_2A79EC_name_3E[k].x;
                        pos[i].z += D_8011271C_2A79EC_name_3E[k].y;
                        func_80056658_57258(&((MBModel*)player->unk_24)->pos, &pos[i], &((MBModel*)player->unk_24)->rot);
                        func_80056D80_57980(&((MBModel*)player->unk_24)->pos, &pos[i], &((MBModel*)player->unk_24)->pos, 60);
                        k++;
                    }
                    if (i == gw->current_player_index) {
                        MBPlayerMotionSet(i, 0, 2);
                    } else {
                        MBMotionSet(player->unk_24, 0, 2);
                    }
                }
                HuPrcSleep(10);
                player = BoardPlayerGet(gw->current_player_index);
                func_8005670C_5730C(&pos[0]);
                func_80056B78_57778(&((MBModel*)player->unk_24)->rot, &pos[0], &((MBModel*)player->unk_24)->rot, 8);
                MBPlayerMotionSet(gw->current_player_index, -1, 2);
                HuPrcSleep(50);
                for (i = 0; i < 4; i++) {
                    if (i != gw->current_player_index) {
                        player = BoardPlayerGet(i);
                        func_8005670C_5730C(&pos[i]);
                        func_80056B78_57778(&((MBModel*)player->unk_24)->rot, &pos[i], &((MBModel*)player->unk_24)->rot, 8);
                        MBMotionSet(player->unk_24, -1, 2);
                    }
                }
                HuPrcSleep(8);
                MBDlgWinExec(0x16, 0xF3);
                for (i = 0; i < 4; i++) {
                    if (i == gw->current_player_index) {
                        MBPlayerMotionSet(i, 5, 2);
                    } else {
                        MBMotionSet(BoardPlayerGet(i)->unk_24, 5, 2);
                    }
                    func_800797DC_7A3DC(0x103, i);
                }
                HuPrcSleep(60);
                InitFadeOut(1, 16);
                while (func_8008F618_90218()) {
                    HuPrcVSleep();
                }
                func_800636F8_642F8(1);
                for (i = 0; i < 4; i++) {
                    player = BoardPlayerGet(i);
                    if (i != gw->current_player_index) {
                        player->cur_chain_index = BoardPlayerGet(-1)->cur_chain_index;
                        player->cur_space_index = BoardPlayerGet(-1)->cur_space_index - 1;
                        player->next_chain_index = BoardPlayerGet(-1)->cur_chain_index;
                        player->next_space_index = BoardPlayerGet(-1)->cur_space_index;
                    }
                    MBMotionSet(player->unk_24, -1, 2);
                }
                HuPrcVSleep();
                for (i = 0; i < 4; i++) {
                    func_80063C40_64840(i, 1);
                    func_8002D4A0_2E0A0(((MBModel*)BoardPlayerGet(i)->unk_24)->obj->model[0]);
                }
                MBPlayerMotionSet(gw->current_player_index, 4, 2);
                HuPrcSleep(15);
                InitFadeIn(1, 16);
                while (func_8008F618_90218()) {
                    HuPrcVSleep();
                }
                func_800797DC_7A3DC(0xFC, gw->current_player_index);
                sp = func_800672BC_67EBC(-1, 2, 5);
                HuPrcSleep(60);
                func_8006735C_67F5C(sp);
                func_8005DDEC_5E9EC(gw->current_player_index, -1, 0, 10, 2);
                HuPrcSleep(15);
                break;
            case 1:
                MBDlgWinExec(0x16, 0xF1);
                break;
            case 2:
                func_80103A64_298D34_name_3E();
                goto ask;
        }
    }
    func_8004655C_4715C(gw->current_player_index);
    HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.3f));
    HuPrcChildWatch();
}

/* Choice like func_8010FB50; a CPU player with 25 coins or more answers from one of three
   decision trees chosen by D_800F8CE4_F98E4[0], else takes option 2. */
s32 func_801104E0_2A57B0_name_3E(void) {
    s32 count = 0;
    s16 sp18[4];
    u8 sp20[4];
    s32 i;
    s32 j;

    *(Unk4Bytes*)sp20 = *(Unk4Bytes*)D_80113590_2A8860_name_3E;
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            if (gPlayers[i].flags & 1) {
                count = 2;
                if (gPlayers[i].coins >= 25) {
                    switch (D_800F8CE4_F98E4[0]) {
                        case 0:
                            count = func_80044800_45400(D_80112780_2A7A50_name_3E) + 1;
                            break;
                        case 1:
                            count = func_80044800_45400(D_801127A4_2A7A74_name_3E) + 1;
                            break;
                        case 2:
                            count = func_80044800_45400(D_801127C8_2A7A98_name_3E) + 1;
                            break;
                    }
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

/* Board event on spaces 0xAE/0xB0/0xB2 (each live in one D_800F8CE4_F98E4[0] state): for 5 coins
   the current player rides D_80113788 into a minigame-like choice (func_80106FE0/801075F8 by
   func_80047E70); the players in its result mask are brought back, then the current player
   jumps on to the chain space for the state. */
void func_80110794_2A5A64_name_3E(void) {
    char name[16];
    Vec pos[4];
    GW_PLAYER* player;
    SpaceData* space;
    s32 param;
    s32 choice;
    s32 helpWin;
    s32 kind;
    s32 mask;
    s32 i;
    s16 spaceIdx;
    s16 absIdx;
    GW_SYSTEM* gw;

    spaceIdx = func_800558F4_564F4();
    gw = &GwSystem;
    if (gw->current_player_index == 4) {
        return;
    }
    param = 0;
    switch (spaceIdx) {
        case 0xAE:
            if (D_800F8CE4_F98E4[0] != 0) {
                return;
            }
            param = 0x1D;
            break;
        case 0xB0:
            if (D_800F8CE4_F98E4[0] != 1) {
                return;
            }
            param = 4;
            break;
        case 0xB2:
            if (D_800F8CE4_F98E4[0] != 2) {
                return;
            }
            param = 13;
            break;
    }
    func_80046D2C_4792C(gw->current_player_index);
    MBPlayerMotionSet(-1, -1, 2);
    func_80056C30_57830(-1, 8, param);
    HuPrcSleep(8);
    if (gPlayers[gw->current_player_index].coins < 5) {
        name[0] = 0x18;
        name[1] = gPlayers[gw->current_player_index].character;
        name[2] = 0;
        func_80056368_56F68(8, 0x675, (s32)name, 0, 0, 0, 0);
        MBDlgWinClose();
        func_80056168_56D68();
    } else {
    ask:
        name[0] = 0x18;
        name[1] = gPlayers[gw->current_player_index].character;
        name[2] = 0;
        func_80056368_56F68(8, 0x66F, (s32)name, 0, 0, 0, 0);
        choice = func_801104E0_2A57B0_name_3E();
        MBDlgWinClose();
        func_80056168_56D68();
        switch (choice) {
            case 0:
                func_8004CA34_4D634(gw->current_player_index, -5);
                func_800614B4_620B4(gw->current_player_index, -5);
                HuPrcSleep(30);
                player = BoardPlayerGet(-1);
                MBPlayerMotionSet(-1, 2, 0);
                func_8005670C_5730C(&pos[0]);
                func_80056B78_57778(&((MBModel*)player->unk_24)->rot, &pos[0], &((MBModel*)player->unk_24)->rot, 20);
                func_800B3170_B3D70(&pos[1], &D_80113788_2A8A58_name_3E->pos);
                pos[1].y += 7.0f;
                func_80056D80_57980(&((MBModel*)player->unk_24)->pos, &pos[1], &((MBModel*)player->unk_24)->pos, 20);
                ((MBModel*)player->unk_24)->jumpVel = 5.5f;
                ((MBModel*)player->unk_24)->jumpAccel = -0.5f;
                func_800797DC_7A3DC(0x42, gw->current_player_index);
                HuPrcSleep(20);
                MBPlayerMotionSet(-1, -1, 2);
                HuPrcSleep(10);
                func_80056368_56F68(8, 0x671, (s32)name, 0, 0, 0, 0);
                MBDlgWinClose();
                func_80056168_56D68();
                func_80061518_62118();
                helpWin = func_8004CC7C_4D87C(0x13, 0xA0, 1);
                HuPrcChildLink(HuPrcCurrentGet(), func_80048A48_49648(gw->current_player_index));
                HuPrcChildWatch();
                HuPrcSleep(10);
                MBHelpWinKill(helpWin);
                kind = func_80047E70_48A70(gw->current_player_index);
                if (kind != 0) {
                    MBDlgWinExec(8, 0x672);
                } else {
                    MBDlgWinExec(8, 0x673);
                }
                func_80046D2C_4792C(gw->current_player_index);
                func_800495A8_4A1A8(0);
                D_8011378C_2A8A5C_name_3E = 1;
                if (kind != 0) {
                    mask = func_80106FE0_29C2B0_name_3E();
                } else {
                    mask = func_801075F8_29C8C8_name_3E();
                }
                D_8011378C_2A8A5C_name_3E = 0;
                if (mask != 0) {
                    InitFadeOut(1, 16);
                    while (func_8008F618_90218()) {
                        HuPrcVSleep();
                    }
                    func_800636F8_642F8(2);
                    space = GetSpaceData(GetAbsSpaceIndexFromChainSpaceIndex(0, 0));
                    func_80063710_64310(&space->coords);
                    HuPrcSleep(5);
                    InitFadeIn(1, 16);
                    while (func_8008F618_90218()) {
                        HuPrcVSleep();
                    }
                    for (i = 0; i < 4; i++) {
                        if (mask & (1 << i)) {
                            MBPlayerForwardSet(i);
                            player = BoardPlayerGet(i);
                            MBModelDispOn(player->unk_24);
                            ((MBModel*)player->unk_24)->attr &= ~1;
                            HuVecCopyXYZ(&((MBModel*)player->unk_24)->pos, space->coords.x + D_80112760_2A7A30_name_3E[i].x,
                                         120.0f, space->coords.z + D_80112760_2A7A30_name_3E[i].y);
                            HuVecCopyXYZ(&pos[i], ((MBModel*)player->unk_24)->pos.x, 0.0f,
                                         ((MBModel*)player->unk_24)->pos.z);
                            func_80056D80_57980(&((MBModel*)player->unk_24)->pos, &pos[i], &((MBModel*)player->unk_24)->pos, 10);
                        }
                    }
                    for (i = 0; i < 4; i++) {
                        if (mask & (1 << i)) {
                            func_800797DC_7A3DC(0xFC, i);
                        }
                    }
                    HuPrcSleep(60);
                    InitFadeOut(1, 16);
                    while (func_8008F618_90218()) {
                        HuPrcVSleep();
                    }
                    func_800636F8_642F8(1);
                    HuPrcSleep(5);
                    InitFadeIn(1, 16);
                    while (func_8008F618_90218()) {
                        HuPrcVSleep();
                    }
                    MBDlgWinExec(8, 0x674);
                }
                func_80061584_62184();
                absIdx = GetAbsSpaceIndexFromChainSpaceIndex(D_80112750_2A7A20_name_3E[D_800F8CE4_F98E4[0]],
                                                             D_80112758_2A7A28_name_3E[D_800F8CE4_F98E4[0]]);
                space = GetSpaceData(absIdx);
                player = BoardPlayerGet(-1);
                MBPlayerMotionSet(-1, 2, 0);
                func_80056658_57258(&((MBModel*)player->unk_24)->pos, &space->coords, &pos[0]);
                func_80056B78_57778(&((MBModel*)player->unk_24)->rot, &pos[0], &((MBModel*)player->unk_24)->rot, 20);
                func_80056D80_57980(&((MBModel*)player->unk_24)->pos, &space->coords, &((MBModel*)player->unk_24)->pos, 20);
                ((MBModel*)player->unk_24)->jumpVel = 5.5f;
                ((MBModel*)player->unk_24)->jumpAccel = -0.5f;
                func_800797DC_7A3DC(0x42, gw->current_player_index);
                HuPrcSleep(20);
                MBPlayerMotionSet(-1, -1, 2);
                func_800558E8_564E8(absIdx);
                SetPlayerOntoChain(-1, D_80112750_2A7A20_name_3E[D_800F8CE4_F98E4[0]],
                                   D_80112758_2A7A28_name_3E[D_800F8CE4_F98E4[0]]);
                func_80054D3C_5593C(absIdx, &player->next_chain_index, &player->next_space_index);
                break;
            case 1:
                func_80056368_56F68(8, 0x670, (s32)name, 0, 0, 0, 0);
                MBDlgWinClose();
                func_80056168_56D68();
                break;
            case 2:
                func_80103A64_298D34_name_3E();
                goto ask;
        }
    }
    func_8004655C_4715C(gw->current_player_index);
}

/* Process: from the D_80113784 view, run func_80106FE0 for nobody (current player -1); the
   players in its result mask are brought back to the start space. Deletes itself. */
void func_80110F78_2A6248_name_3E(void) {
    Vec pos[4];
    GW_PLAYER* player;
    SpaceData* space;
    s32 mask;
    s32 i;
    s16 cur;
    GW_SYSTEM* gw = &GwSystem;

    InitFadeOut(4, 16);
    while (func_8008F618_90218()) {
        HuPrcVSleep();
    }
    func_800636F8_642F8(4);
    func_80063734_64334(&D_80113784_2A8A54_name_3E->pos);
    HuPrcSleep(5);
    func_80061518_62118();
    InitFadeIn(4, 16);
    while (func_8008F618_90218()) {
        HuPrcVSleep();
    }
    cur = gw->current_player_index;
    gw->current_player_index = -1;
    mask = func_80106FE0_29C2B0_name_3E();
    gw->current_player_index = cur;
    InitFadeOut(4, 16);
    while (func_8008F618_90218()) {
        HuPrcVSleep();
    }
    if (mask != 0) {
        func_800636F8_642F8(2);
        space = GetSpaceData(GetAbsSpaceIndexFromChainSpaceIndex(0, 0));
        func_80063710_64310(&space->coords);
        HuPrcSleep(5);
        func_80061584_62184();
        InitFadeIn(4, 16);
        while (func_8008F618_90218()) {
            HuPrcVSleep();
        }
        for (i = 0; i < 4; i++) {
            if (mask & (1 << i)) {
                MBPlayerForwardSet(i);
                player = BoardPlayerGet(i);
                MBModelDispOn(player->unk_24);
                ((MBModel*)player->unk_24)->attr &= ~1;
                HuVecCopyXYZ(&((MBModel*)player->unk_24)->pos, space->coords.x + D_80112760_2A7A30_name_3E[i].x,
                             120.0f, space->coords.z + D_80112760_2A7A30_name_3E[i].y);
                HuVecCopyXYZ(&pos[i], ((MBModel*)player->unk_24)->pos.x, 0.0f, ((MBModel*)player->unk_24)->pos.z);
                func_80056D80_57980(&((MBModel*)player->unk_24)->pos, &pos[i], &((MBModel*)player->unk_24)->pos, 10);
            }
        }
        for (i = 0; i < 4; i++) {
            if (mask & (1 << i)) {
                func_800797DC_7A3DC(0xFC, i);
            }
        }
        HuPrcSleep(60);
        if (!(mask & (1 << gw->current_player_index))) {
            InitFadeOut(4, 16);
            while (func_8008F618_90218()) {
                HuPrcVSleep();
            }
            func_800636F8_642F8(1);
            HuPrcSleep(5);
            InitFadeIn(4, 16);
            while (func_8008F618_90218()) {
                HuPrcVSleep();
            }
        }
    } else {
        func_800636F8_642F8(1);
        HuPrcSleep(5);
        func_80061584_62184();
        InitFadeIn(4, 16);
        while (func_8008F618_90218()) {
            HuPrcVSleep();
        }
    }
    omDelPrcObj(NULL);
}

/* Scene setup; MP3 func_8011A848_3AFBC8_w06. */
void func_801112E4_2A65B4_name_3E(void) {
    func_80020070_20C70(2);
    CameraScissorSet(1, D_80112914_2A7BE4_name_3E);
    func_80105974_29AC44_name_3E();
    func_80066C34_67834(2);
    omAddPrcObj(func_80102FFC_2982CC_name_3E, 0x1005, 0x1000, 0);
}

/* CPU item check (registered with func_80044D98): 1 = use the held item now. Several items are
   used on the last turn, or when their decision tree D_80112F24/80112F84/80113248/801133BC
   says so, or with enough coins. */
#ifdef NON_MATCHING /* rodata-pending */
s32 func_80111338_2A6608_name_3E(void) {
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
            if (gw->total_turns != gw->current_turn && func_80044800_45400(D_80112F24_2A81F4_name_3E) != 0) {
                return 0;
            }
            break;
        case 8:
            if (gw->total_turns != gw->current_turn && func_80044800_45400(D_80112F84_2A8254_name_3E) != 0) {
                return 0;
            }
            break;
        case 5:
            if (func_80044800_45400(D_80113248_2A8518_name_3E) != 0) {
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
            if (func_80044800_45400(D_801133BC_2A868C_name_3E) != 0) {
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
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80111338_2A6608_name_3E);
#endif

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8011155C_2A682C_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_801118D8_2A6BA8_name_3E);
