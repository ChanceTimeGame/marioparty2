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

void func_801069C8_29BC98_name_3E(void) {
    D_80113790_2A8A60_name_3E[D_801138B0_2A8B80_name_3E].x = D_80113784_2A8A54_name_3E->pos.x;
    D_80113790_2A8A60_name_3E[D_801138B0_2A8B80_name_3E].y = D_80113784_2A8A54_name_3E->pos.y;
    D_80113790_2A8A60_name_3E[D_801138B0_2A8B80_name_3E].z = D_80113784_2A8A54_name_3E->pos.z;
    D_80113820_2A8AF0_name_3E[D_801138B0_2A8B80_name_3E].x = D_80113784_2A8A54_name_3E->rot.x;
    D_80113820_2A8AF0_name_3E[D_801138B0_2A8B80_name_3E].y = D_80113784_2A8A54_name_3E->rot.y;
    D_80113820_2A8AF0_name_3E[D_801138B0_2A8B80_name_3E].z = D_80113784_2A8A54_name_3E->rot.z;
    if (++D_801138B0_2A8B80_name_3E >= 12) {
        D_801138B0_2A8B80_name_3E = 0;
    }
    HuVecCopyXYZ(&D_80113788_2A8A58_name_3E->pos, D_80113790_2A8A60_name_3E[D_801138B0_2A8B80_name_3E].x,
                 D_80113790_2A8A60_name_3E[D_801138B0_2A8B80_name_3E].y,
                 D_80113790_2A8A60_name_3E[D_801138B0_2A8B80_name_3E].z);
    HuVecCopyXYZ(&D_80113788_2A8A58_name_3E->rot, D_80113820_2A8AF0_name_3E[D_801138B0_2A8B80_name_3E].x,
                 D_80113820_2A8AF0_name_3E[D_801138B0_2A8B80_name_3E].y,
                 D_80113820_2A8AF0_name_3E[D_801138B0_2A8B80_name_3E].z);
}
void func_80106B08_29BDD8_name_3E(void) {
    D_80113790_2A8A60_name_3E[D_801138B0_2A8B80_name_3E].x = D_80113788_2A8A58_name_3E->pos.x;
    D_80113790_2A8A60_name_3E[D_801138B0_2A8B80_name_3E].y = D_80113788_2A8A58_name_3E->pos.y;
    D_80113790_2A8A60_name_3E[D_801138B0_2A8B80_name_3E].z = D_80113788_2A8A58_name_3E->pos.z;
    D_80113820_2A8AF0_name_3E[D_801138B0_2A8B80_name_3E].x = D_80113788_2A8A58_name_3E->rot.x;
    D_80113820_2A8AF0_name_3E[D_801138B0_2A8B80_name_3E].y = D_80113788_2A8A58_name_3E->rot.y;
    D_80113820_2A8AF0_name_3E[D_801138B0_2A8B80_name_3E].z = D_80113788_2A8A58_name_3E->rot.z;
    if (--D_801138B0_2A8B80_name_3E < 0) {
        D_801138B0_2A8B80_name_3E = 11;
    }
    HuVecCopyXYZ(&D_80113784_2A8A54_name_3E->pos, D_80113790_2A8A60_name_3E[D_801138B0_2A8B80_name_3E].x,
                 D_80113790_2A8A60_name_3E[D_801138B0_2A8B80_name_3E].y,
                 D_80113790_2A8A60_name_3E[D_801138B0_2A8B80_name_3E].z);
    HuVecCopyXYZ(&D_80113784_2A8A54_name_3E->rot, D_80113820_2A8AF0_name_3E[D_801138B0_2A8B80_name_3E].x,
                 D_80113820_2A8AF0_name_3E[D_801138B0_2A8B80_name_3E].y,
                 D_80113820_2A8AF0_name_3E[D_801138B0_2A8B80_name_3E].z);
}
void func_80106C44_29BF14_name_3E(void) {
    MBModel* model;
    SpaceData* from;
    SpaceData* to;

    model = func_80043510_44110(0x74, NULL);
    func_80043DAC_449AC(model);
    D_80113784_2A8A54_name_3E = model;
    model->attr |= 2;
    from = GetSpaceData(GetAbsSpaceIndexFromChainSpaceIndex(D_80111B90_2A6E60_name_3E[D_800F8CE4_F98E4[0]], 0));
    to = GetSpaceData(GetAbsSpaceIndexFromChainSpaceIndex(D_80111B90_2A6E60_name_3E[D_800F8CE4_F98E4[0]], 1));
    HuVecCopyXYZ(&model->rot, to->coords.x - from->coords.x, to->coords.y - from->coords.y,
                 to->coords.z - from->coords.z);
    func_800B3170_B3D70(&model->pos, &from->coords);
    model = func_80043510_44110(0x75, NULL);
    func_80043DAC_449AC(model);
    D_80113788_2A8A58_name_3E = model;
    model->attr |= 2;
    func_80106738_29BA08_name_3E();
    D_8011378C_2A8A5C_name_3E = 0;
}
/* a run-over player: hidden when the counter runs out */
void func_80106D78_29C048_name_3E(omObjData* obj) {
    GW_PLAYER* player = BoardPlayerGet(obj->work[0]);

    if (obj->work[1] == 0) {
        MBModelDispOff(player->unk_24);
        omDelObj(obj);
    }
    obj->work[1]--;
}
void func_80106DCC_29C09C_name_3E(s32 player, s32 arg1) {
    Vec dir;
    Vec rot;
    GW_PLAYER* p;
    omObjData* obj;
    MBModel* cart;

    p = BoardPlayerGet(player);
    func_80079798_7A398(0x3A8, player);
    func_80079798_7A398(0xA6, player);
    func_800797DC_7A3DC(0x111, player);
    MBPlayerVibrate(player, 3);
    obj = omAddObj(0x1000, 0, 0, -1, func_80106D78_29C048_name_3E);
    omSetStatBit(obj, 0xA0);
    obj->work[0] = player;
    obj->work[1] = 30;
    if (arg1 == 0) {
        cart = D_80113784_2A8A54_name_3E;
    } else {
        cart = D_80113788_2A8A58_name_3E;
    }
    func_80056658_57258(&cart->pos, &((MBModel*)p->unk_24)->pos, &dir);
    dir.y = 1.0f;
    HuVecMulScalar(&dir, 100.0f, &dir);
    HuVecAdd(&dir, &((MBModel*)p->unk_24)->pos, &dir);
    func_80056658_57258(&((MBModel*)p->unk_24)->pos, &dir, &rot);
    if (func_80042BE0_437E0(&rot) >= 300.0f || func_80042BE0_437E0(&rot) <= 60.0f) {
        dir.x = ((MBModel*)p->unk_24)->pos.x + 50.0f;
        dir.z = ((MBModel*)p->unk_24)->pos.z;
    }
    func_80056D80_57980(&((MBModel*)p->unk_24)->pos, &dir, &((MBModel*)p->unk_24)->pos, 30);
    p->cur_chain_index = 0;
    p->cur_space_index = 0;
    p->next_chain_index = 0;
    p->next_space_index = 1;
    ((MBModel*)p->unk_24)->attr |= 1;
    MBMotionSet(p->unk_24, 4, 2);
    if (GwSystem.current_player_index != -1) {
        MBPlayerMotionSet(GwSystem.current_player_index, 5, 0);
        MBPlayerVibrate(-1, 0);
    }
}
/* The minecart runs forward along its chain; returns the players it ran over (bits). */
s32 func_80106FE0_29C2B0_name_3E(void) {
    Vec dir;
    Vec delta;
    Vec pos;
    Unk3Halves counts;
    Vec fxPos;
    Vec fxVel;
    s32 count;
    s16* spaces;
    GW_PLAYER* player;
    Process* process;
    Process* child;
    SpaceData* from;
    SpaceData* to;
    f32 dist;
    f32 angle;
    f32 target;
    f32 step;
    s32 steps;
    s32 prev;
    s32 mask;
    s32 next;
    s32 i;
    s32 j;

    counts = D_801135A4_2A8874_name_3E;
    if (D_801119E0_2A6CB0_name_3E == 0) {
        D_801119E0_2A6CB0_name_3E = 1;
        spaces = D_80111BF4_2A6EC4_name_3E[D_800F8CE4_F98E4[0]];
        mask = 0;
        next = 0;
        count = counts.v[D_800F8CE4_F98E4[0]];
        PlaySound(0x398);
        for (i = 0; i < BoardGetChainLength(D_80111B90_2A6E60_name_3E[D_800F8CE4_F98E4[0]]) - 1; i++) {
            from = GetSpaceData(GetAbsSpaceIndexFromChainSpaceIndex(D_80111B90_2A6E60_name_3E[D_800F8CE4_F98E4[0]], i));
            to = GetSpaceData(GetAbsSpaceIndexFromChainSpaceIndex(D_80111B90_2A6E60_name_3E[D_800F8CE4_F98E4[0]], i + 1));
            process = HuPrcCurrentGet();
            func_800B3170_B3D70(&pos, &D_80113784_2A8A54_name_3E->pos);
            if (i == BoardGetChainLength(D_80111B90_2A6E60_name_3E[D_800F8CE4_F98E4[0]]) - 2) {
                child = func_80056FD4_57BD4(&pos, &to->coords, &D_80113784_2A8A54_name_3E->pos, 2.0f);
            } else {
                child = func_80057150_57D50(&pos, &to->coords, &D_80113784_2A8A54_name_3E->pos, 2.0f);
            }
            HuPrcChildLink(process, child);
            dist = func_800B1870_B2470(from->coords.x - to->coords.x, from->coords.y - to->coords.y,
                                       from->coords.z - to->coords.z);
            HuVecSubtract(&dir, &from->coords, &to->coords);
            MBVecNormalize(&dir);
            HuVecMulScalar(&dir, 2.0f, &dir);
            steps = dist / func_800B1870_B2470(dir.x, dir.y, dir.z);
            HuVecSubtract(&delta, &to->coords, &from->coords);
            angle = func_80042BE0_437E0(&D_80113784_2A8A54_name_3E->rot);
            target = func_80042BE0_437E0(&delta);
            if (target < angle && ABS_F(angle - target) > 180.0f) {
                target += 360.0f;
            }
            if (angle < target && ABS_F(angle - target) > 180.0f) {
                angle += 360.0f;
            }
            step = target - angle;
            step /= steps;
            PlaySound(0x399);
            fxVel = D_801135AC_2A887C_name_3E;
            func_800B3170_B3D70(&fxPos, &D_80113784_2A8A54_name_3E->pos);
            fxPos.x += HuMathSin(func_80042BE0_437E0(&D_80113784_2A8A54_name_3E->rot)) * 10.0f;
            fxPos.z += func_800B7890_B8490(func_80042BE0_437E0(&D_80113784_2A8A54_name_3E->rot)) * 10.0f;
            fxPos.y += 35.0f;
            func_8010C484_2A1754_name_3E(&fxPos, 0.3f, 8.0f, 1, &fxVel);
            while (process->oldest_child != NULL) {
                angle += step;
                D_80113784_2A8A54_name_3E->rot.x = HuMathSin(angle);
                D_80113784_2A8A54_name_3E->rot.y = 0.0f;
                D_80113784_2A8A54_name_3E->rot.z = func_800B7890_B8490(angle);
                func_801069C8_29BC98_name_3E();
                HuPrcVSleep();
                if (next < count) {
                    if (HuVecDistance(&GetSpaceData(spaces[next])->coords, &D_80113784_2A8A54_name_3E->pos) <= 20.0f) {
                        prev = mask;
                        for (j = 0; j < 4; j++) {
                            if (j != GwSystem.current_player_index) {
                                player = BoardPlayerGet(j);
                                if (GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain_index, player->cur_space_index) ==
                                    spaces[next]) {
                                    func_80106DCC_29C09C_name_3E(j, 0);
                                    mask |= 1 << j;
                                }
                            }
                        }
                        if (prev != mask) {
                            PlaySound(0x3A8);
                        }
                        next++;
                    }
                }
            }
        }
        PlaySound(0x39A);
        D_800F8CE4_F98E4[0] = (s16)(D_800F8CE4_F98E4[0] + 1) % 3;
        D_801119E0_2A6CB0_name_3E = 0;
        return mask;
    }
    return 0;
}
/* The minecart runs back along its chain; returns the players it ran over (bits).
   NON_MATCHING: one instruction, retail tests next >= 0 as slti/bnez where this gives bltz (masked 8). */
#ifdef NON_MATCHING
s32 func_801075F8_29C8C8_name_3E(void) {
    Vec dir;
    Vec delta;
    Vec pos;
    Vec dest;
    Unk3Halves counts;
    Vec fxPos;
    Vec fxVel;
    s16* spaces;
    GW_PLAYER* player;
    Process* process;
    Process* child;
    SpaceData* from;
    SpaceData* to;
    f32 dist;
    f32 angle;
    f32 target;
    f32 step;
    s32 steps;
    s32 prev;
    s32 mask;
    s32 next;
    s32 i;
    s32 j;

    counts = D_801135A4_2A8874_name_3E;
    if (D_801119E0_2A6CB0_name_3E == 0) {
        D_801119E0_2A6CB0_name_3E = 1;
        if (--D_800F8CE4_F98E4[0] < 0) {
            D_800F8CE4_F98E4[0] = 2;
        }
        spaces = D_80111BF4_2A6EC4_name_3E[D_800F8CE4_F98E4[0]];
        mask = 0;
        next = counts.v[D_800F8CE4_F98E4[0]] - 1;
        PlaySound(0x398);
        for (i = BoardGetChainLength(D_80111B90_2A6E60_name_3E[D_800F8CE4_F98E4[0]]) - 1; i > 0; i--) {
            from = GetSpaceData(GetAbsSpaceIndexFromChainSpaceIndex(D_80111B90_2A6E60_name_3E[D_800F8CE4_F98E4[0]], i));
            to = GetSpaceData(GetAbsSpaceIndexFromChainSpaceIndex(D_80111B90_2A6E60_name_3E[D_800F8CE4_F98E4[0]], i - 1));
            process = HuPrcCurrentGet();
            func_800B3170_B3D70(&pos, &D_80113788_2A8A58_name_3E->pos);
            func_800B3170_B3D70(&dest, &to->coords);
            if (i == 1) {
                dest.x += D_80111C00_2A6ED0_name_3E[D_800F8CE4_F98E4[0]].x;
                dest.y += D_80111C00_2A6ED0_name_3E[D_800F8CE4_F98E4[0]].y;
                dest.z += D_80111C00_2A6ED0_name_3E[D_800F8CE4_F98E4[0]].z;
                child = func_80056FD4_57BD4(&pos, &dest, &D_80113788_2A8A58_name_3E->pos, 2.0f);
            } else {
                child = func_80057150_57D50(&pos, &dest, &D_80113788_2A8A58_name_3E->pos, 2.0f);
            }
            HuPrcChildLink(process, child);
            dist = func_800B1870_B2470(from->coords.x - to->coords.x, from->coords.y - to->coords.y,
                                       from->coords.z - to->coords.z);
            HuVecSubtract(&dir, &from->coords, &to->coords);
            MBVecNormalize(&dir);
            HuVecMulScalar(&dir, 2.0f, &dir);
            steps = dist / func_800B1870_B2470(dir.x, dir.y, dir.z);
            HuVecSubtract(&delta, &to->coords, &from->coords);
            angle = func_80042BE0_437E0(&D_80113788_2A8A58_name_3E->rot);
            target = func_80042BE0_437E0(&delta) + 180.0f;
            while (target < angle && ABS_F(angle - target) > 180.0f) {
                target += 360.0f;
            }
            while (angle < target && ABS_F(angle - target) > 180.0f) {
                angle += 360.0f;
            }
            step = target - angle;
            step /= steps;
            PlaySound(0x399);
            fxVel = D_801135AC_2A887C_name_3E;
            func_800B3170_B3D70(&fxPos, &D_80113784_2A8A54_name_3E->pos);
            fxPos.x += HuMathSin(func_80042BE0_437E0(&D_80113784_2A8A54_name_3E->rot)) * 10.0f;
            fxPos.z += func_800B7890_B8490(func_80042BE0_437E0(&D_80113784_2A8A54_name_3E->rot)) * 10.0f;
            fxPos.y += 35.0f;
            func_8010C484_2A1754_name_3E(&fxPos, 0.3f, 8.0f, 1, &fxVel);
            while (process->oldest_child != NULL) {
                angle += step;
                D_80113788_2A8A58_name_3E->rot.x = HuMathSin(angle);
                D_80113788_2A8A58_name_3E->rot.y = 0.0f;
                D_80113788_2A8A58_name_3E->rot.z = func_800B7890_B8490(angle);
                func_80106B08_29BDD8_name_3E();
                HuPrcVSleep();
                if (next >= 0) {
                    if (HuVecDistance(&GetSpaceData(spaces[next])->coords, &D_80113788_2A8A58_name_3E->pos) <= 15.0f) {
                        prev = mask;
                        for (j = 0; j < 4; j++) {
                            if (j != GwSystem.current_player_index) {
                                player = BoardPlayerGet(j);
                                if (GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain_index, player->cur_space_index) ==
                                    spaces[next]) {
                                    func_80106DCC_29C09C_name_3E(j, 1);
                                    mask |= 1 << j;
                                }
                            }
                        }
                        if (prev != mask) {
                            PlaySound(0x3A8);
                        }
                        next--;
                    }
                }
            }
        }
        PlaySound(0x39A);
        D_801119E0_2A6CB0_name_3E = 0;
        return mask;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_801075F8_29C8C8_name_3E);
#endif
/* MP1 func_800F71B4_MariosRainbowCastle: a junction's direction prompt */
void func_80107C54_29CF24_name_3E(void) {
    struct unk_8003B8D4Struct* prompt;
    s32 dir;
    s32 i;
    s32 n;
    DecisionTreeNonLeafNode* tree;

    MBPlayerMotionSet(-1, -1, 2);
    HuPrcVSleep();
    func_80103BC4_298E94_name_3E();
    prompt = func_80041A74_42674(GwSystem.current_player_index, D_801120E0_2A73B0_name_3E);
    func_800417EC_423EC(prompt, GwSystem.current_player_index, 0);
    if (PlayerIsCPU(-1) != 0) {
        if (GwSystem.current_player_index == 4) {
            tree = D_80111F84_2A7254_name_3E;
        } else {
            tree = D_80111C3C_2A6F0C_name_3E;
        }
        n = func_80044800_45400(tree);
        for (i = 0; i < n; i++) {
            func_80041610_42210(prompt, -2);
        }
        func_80041610_42210(prompt, -4);
    }
    dir = DirectionPrompt(prompt);
    func_8004108C_41C8C(prompt);
    func_80103C94_298F64_name_3E();
    if (dir == 0) {
        SetNextChainAndSpace(-1, 2, 0);
    } else {
        SetNextChainAndSpace(-1, 8, 0);
    }
    omDelPrcObj(NULL);
}
/* MP1 func_800F71B4_MariosRainbowCastle: a junction's direction prompt */
void func_80107D6C_29D03C_name_3E(void) {
    struct unk_8003B8D4Struct* prompt;
    s32 dir;
    s32 i;
    s32 n;
    DecisionTreeNonLeafNode* tree;

    MBPlayerMotionSet(-1, -1, 2);
    HuPrcVSleep();
    func_80103BC4_298E94_name_3E();
    prompt = func_80041A74_42674(GwSystem.current_player_index, D_801120F8_2A73C8_name_3E);
    func_800417EC_423EC(prompt, GwSystem.current_player_index, 0);
    if (PlayerIsCPU(-1) != 0) {
        if (GwSystem.current_player_index == 4) {
            tree = D_80111FB4_2A7284_name_3E;
        } else {
            tree = D_80111C6C_2A6F3C_name_3E;
        }
        n = func_80044800_45400(tree);
        for (i = 0; i < n; i++) {
            func_80041610_42210(prompt, -2);
        }
        func_80041610_42210(prompt, -4);
    }
    dir = DirectionPrompt(prompt);
    func_8004108C_41C8C(prompt);
    func_80103C94_298F64_name_3E();
    if (dir == 0) {
        SetNextChainAndSpace(-1, 5, 0);
    } else {
        SetNextChainAndSpace(-1, 23, 0);
    }
    omDelPrcObj(NULL);
}
/* MP1 func_800F71B4_MariosRainbowCastle: a junction's direction prompt */
void func_80107E84_29D154_name_3E(void) {
    struct unk_8003B8D4Struct* prompt;
    s32 dir;
    s32 i;
    s32 n;
    DecisionTreeNonLeafNode* tree;

    MBPlayerMotionSet(-1, -1, 2);
    HuPrcVSleep();
    func_80103BC4_298E94_name_3E();
    prompt = func_80041A74_42674(GwSystem.current_player_index, D_80112110_2A73E0_name_3E);
    func_800417EC_423EC(prompt, GwSystem.current_player_index, 0);
    if (PlayerIsCPU(-1) != 0) {
        if (GwSystem.current_player_index == 4) {
            tree = D_80111FFC_2A72CC_name_3E;
        } else {
            tree = D_80111CA8_2A6F78_name_3E;
        }
        n = func_80044800_45400(tree);
        for (i = 0; i < n; i++) {
            func_80041610_42210(prompt, -2);
        }
        func_80041610_42210(prompt, -4);
    }
    dir = DirectionPrompt(prompt);
    func_8004108C_41C8C(prompt);
    func_80103C94_298F64_name_3E();
    if (dir == 0) {
        SetNextChainAndSpace(-1, 22, 0);
    } else {
        SetNextChainAndSpace(-1, 16, 0);
    }
    omDelPrcObj(NULL);
}
/* MP1 func_800F71B4_MariosRainbowCastle: a junction's direction prompt */
void func_80107F9C_29D26C_name_3E(void) {
    struct unk_8003B8D4Struct* prompt;
    s32 dir;
    s32 i;
    s32 n;
    DecisionTreeNonLeafNode* tree;

    MBPlayerMotionSet(-1, -1, 2);
    HuPrcVSleep();
    func_80103BC4_298E94_name_3E();
    prompt = func_80041A74_42674(GwSystem.current_player_index, D_80112128_2A73F8_name_3E);
    func_800417EC_423EC(prompt, GwSystem.current_player_index, 0);
    if (PlayerIsCPU(-1) != 0) {
        if (GwSystem.current_player_index == 4) {
            tree = D_80112044_2A7314_name_3E;
        } else {
            tree = D_80111D50_2A7020_name_3E;
        }
        n = func_80044800_45400(tree);
        for (i = 0; i < n; i++) {
            func_80041610_42210(prompt, -2);
        }
        func_80041610_42210(prompt, -4);
    }
    dir = DirectionPrompt(prompt);
    func_8004108C_41C8C(prompt);
    func_80103C94_298F64_name_3E();
    if (dir == 0) {
        SetNextChainAndSpace(-1, 9, 0);
    } else {
        SetNextChainAndSpace(-1, 11, 0);
    }
    omDelPrcObj(NULL);
}
/* MP1 func_800F71B4_MariosRainbowCastle: a junction's direction prompt */
void func_801080B4_29D384_name_3E(void) {
    struct unk_8003B8D4Struct* prompt;
    s32 dir;
    s32 i;
    s32 n;
    DecisionTreeNonLeafNode* tree;

    MBPlayerMotionSet(-1, -1, 2);
    HuPrcVSleep();
    func_80103BC4_298E94_name_3E();
    prompt = func_80041A74_42674(GwSystem.current_player_index, D_80112140_2A7410_name_3E);
    func_800417EC_423EC(prompt, GwSystem.current_player_index, 0);
    if (PlayerIsCPU(-1) != 0) {
        if (GwSystem.current_player_index == 4) {
            tree = D_801120A4_2A7374_name_3E;
        } else {
            tree = D_80111DEC_2A70BC_name_3E;
        }
        n = func_80044800_45400(tree);
        for (i = 0; i < n; i++) {
            func_80041610_42210(prompt, -2);
        }
        func_80041610_42210(prompt, -4);
    }
    dir = DirectionPrompt(prompt);
    func_8004108C_41C8C(prompt);
    func_80103C94_298F64_name_3E();
    if (dir == 0) {
        SetNextChainAndSpace(-1, 10, 0);
    } else {
        SetNextChainAndSpace(-1, 12, 0);
    }
    omDelPrcObj(NULL);
}
s32 func_801081CC_29D49C_name_3E(s32 arg0) {
    s32 count = 0;
    s16 sp18[4];
    u8 sp20[4];
    s32 i;
    s32 j;

    *(Unk4Bytes*)sp20 = *(Unk4Bytes*)D_80113590_2A8860_name_3E;
    for (i = 0; i < 4; i++) {
        if (i == GwSystem.current_player_index) {
            if (gPlayers[i].flags & 1) {
                count = 1;
                if (arg0 == 0) {
                    count = func_80044800_45400(D_80112178_2A7448_name_3E) + 1;
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
void func_80108424_29D6F4_name_3E(void) {
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
        func_80056C30_57830(-1, 8, 0x94);
        HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.6f));
        HuPrcChildWatch();
        MBPlayerVibrate(-1, 1);
    loop:
        MBDlgWinCreate(0x14, 0x13);
        choice = func_801081CC_29D49C_name_3E(0);
        MBDlgWinClose();
        func_80056168_56D68();
        switch (choice) {
        case 0:
            gPlayers[gw->current_player_index].item = -1;
            MBDlgWinExec(0x14, 0x14);
            func_80106574_29B844_name_3E(0);
            cam = func_800672BC_67EBC(-1, 2, 5);
            HuPrcSleep(20);
            func_8006735C_67F5C(cam);
            func_80103BC4_298E94_name_3E();
            prompt = func_80041A74_42674(GwSystem.current_player_index, D_80112158_2A7428_name_3E);
            func_800417EC_423EC(prompt, GwSystem.current_player_index, 0);
            if (PlayerIsCPU(-1) != 0) {
                if (GwSystem.current_player_index == 4) {
                    tree = D_80111F60_2A7230_name_3E;
                } else {
                    tree = D_80111E34_2A7104_name_3E;
                }
                n = func_80044800_45400(tree);
                for (i = 0; i < n; i++) {
                    func_80041610_42210(prompt, -2);
                }
                func_80041610_42210(prompt, -4);
            }
            dir = DirectionPrompt(prompt);
            func_8004108C_41C8C(prompt);
            func_80103C94_298F64_name_3E();
            if (dir == 0) {
                SetNextChainAndSpace(-1, 0xf, 0);
            } else {
                SetNextChainAndSpace(-1, 0xe, 0);
                func_80106618_29B8E8_name_3E(0);
            }
            break;
        case 1:
            MBDlgWinExec(0x14, 0x15);
            SetNextChainAndSpace(-1, 0xe, 0);
            break;
        case 2:
            func_80103A64_298D34_name_3E();
            goto loop;
        }
        func_8004655C_4715C(gw->current_player_index);
        HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.3f));
        HuPrcChildWatch();
    } else {
        SetNextChainAndSpace(-1, 0xe, 0);
    }
    omDelPrcObj(NULL);
}
/* A gate: open it with the key item (option 0) or turn back (1); option 2 runs func_80103A64 and asks again. */
void func_8010871C_29D9EC_name_3E(void) {
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
        func_80056C30_57830(-1, 8, 0x95);
        HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.6f));
        HuPrcChildWatch();
        MBPlayerVibrate(-1, 1);
    loop:
        MBDlgWinCreate(0x14, 0x13);
        choice = func_801081CC_29D49C_name_3E(1);
        MBDlgWinClose();
        func_80056168_56D68();
        switch (choice) {
        case 0:
            gPlayers[gw->current_player_index].item = -1;
            MBDlgWinExec(0x14, 0x14);
            func_80106574_29B844_name_3E(1);
            cam = func_800672BC_67EBC(-1, 2, 5);
            HuPrcSleep(20);
            func_8006735C_67F5C(cam);
            func_80103BC4_298E94_name_3E();
            prompt = func_80041A74_42674(GwSystem.current_player_index, D_801121AC_2A747C_name_3E);
            func_800417EC_423EC(prompt, GwSystem.current_player_index, 0);
            if (PlayerIsCPU(-1) != 0) {
                if (GwSystem.current_player_index == 4) {
                    tree = D_80111F60_2A7230_name_3E;
                } else {
                    tree = D_80111F0C_2A71DC_name_3E;
                }
                n = func_80044800_45400(tree);
                for (i = 0; i < n; i++) {
                    func_80041610_42210(prompt, -2);
                }
                func_80041610_42210(prompt, -4);
            }
            dir = DirectionPrompt(prompt);
            func_8004108C_41C8C(prompt);
            func_80103C94_298F64_name_3E();
            if (dir == 0) {
                SetNextChainAndSpace(-1, 0x12, 0);
            } else {
                SetNextChainAndSpace(-1, 0x11, 0);
                func_80106618_29B8E8_name_3E(1);
            }
            break;
        case 1:
            MBDlgWinExec(0x14, 0x15);
            SetNextChainAndSpace(-1, 0x11, 0);
            break;
        case 2:
            func_80103A64_298D34_name_3E();
            goto loop;
        }
        func_8004655C_4715C(gw->current_player_index);
        HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.3f));
        HuPrcChildWatch();
    } else {
        SetNextChainAndSpace(-1, 0x11, 0);
    }
    omDelPrcObj(NULL);
}
void func_80108A14_29DCE4_name_3E(void) {
    SetNextChainAndSpace(-1, 1, 0);
}
void func_80108A38_29DD08_name_3E(void) {
    SetNextChainAndSpace(-1, 3, 0);
}
void func_80108A5C_29DD2C_name_3E(void) {
    SetNextChainAndSpace(-1, 4, 0);
}
void func_80108A80_29DD50_name_3E(void) {
    SetNextChainAndSpace(-1, 6, 0);
}
void func_80108AA4_29DD74_name_3E(void) {
    SetNextChainAndSpace(-1, 7, 0);
}
void func_80108AC8_29DD98_name_3E(void) {
    SetNextChainAndSpace(-1, 1, 0);
}
void func_80108AEC_29DDBC_name_3E(void) {
    SetNextChainAndSpace(-1, 3, 0);
}
void func_80108B10_29DDE0_name_3E(void) {
    SetNextChainAndSpace(-1, 13, 0);
}
void func_80108B34_29DE04_name_3E(void) {
    SetNextChainAndSpace(-1, 13, 0);
}
void func_80108B58_29DE28_name_3E(void) {
    SetNextChainAndSpace(-1, 4, 0);
}
void func_80108B7C_29DE4C_name_3E(void) {
    SetNextChainAndSpace(-1, 23, 3);
}
void func_80108BA0_29DE70_name_3E(void) {
    SetNextChainAndSpace(-1, 6, 0);
}
void func_80108BC4_29DE94_name_3E(void) {
    SetNextChainAndSpace(-1, 22, 3);
}
void func_80108BE8_29DEB8_name_3E(void) {
    SetNextChainAndSpace(-1, 7, 0);
}
/* MP3 MB1Ev_KSuitEnd's shape: a puff grows over the marker model, the marker is rebuilt, the puff shrinks. */
#ifdef NON_MATCHING /* rodata-pending */
void func_80108C0C_29DEDC_name_3E(void) {
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
    func_80105EC4_29B194_name_3E();
    D_800F8D12_F9912 = 0;
    ChangeSpaceTextures(0);
    func_80105DDC_29B0AC_name_3E();
    for (; scale >= 1.0f; rot += 20.0f, HuPrcVSleep(), scale -= 1.0) {
        HuVecCopyXYZ(&obj->scale, scale, scale, scale);
        func_800B3B80_B4780(D_800FC834_FD434[obj->obj->model[0]].mtx, rot);
    }
    MBModelKill(obj);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80108C0C_29DEDC_name_3E);
#endif

/* A star space (func_80102C3C 1: buy a star for 20 coins) or the bank (2: passing pays out the
   bank, D_800F8D18; landing pays in up to 5 coins, or a lucky roll pays 5 out; with the star
   moved there, D_800F8D12, landing sells the star and moves it on).
   NON_MATCHING: GCC cross-jumps the two 20-coin payouts from MBDlgWinExec on where retail shares
   only the func_800614B4 call (6 instructions short), and the star-intro label lands before the
   D_800F8D12 load instead of after it (masked 61). */
#ifdef NON_MATCHING
void func_80108E0C_29E0DC_name_3E(void) {
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
        if ((s16)func_80102C3C_297F0C_name_3E((s16)space) == 1) {
            func_80046D2C_4792C(gw->current_player_index);
            MBPlayerMotionSet(-1, -1, 2);
            func_80056C30_57830(-1, 8, func_80102830_297B00_name_3E());
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
                choice = func_801041D4_2994A4_name_3E();
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
                        func_80103968_298C38_name_3E(D_8011371C_2A89EC_name_3E);
                        func_800573AC_57FAC();
                        func_8006706C_67C6C(2);
                        return;
                    }
                    MBDlgWinExec(3, 0x22D);
                    func_80108C0C_29DEDC_name_3E();
                    HuPrcSleep(30);
                    func_801039E4_298CB4_name_3E(D_800F64C8_F70C8);
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
                    func_80103A64_298D34_name_3E();
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
        } else if ((s16)func_80102C3C_297F0C_name_3E((s16)space) == 2) {
            func_80046D2C_4792C(gw->current_player_index);
            MBPlayerMotionSet(-1, -1, 2);
            func_80056C30_57830(-1, 8, D_80111994_2A6C64_name_3E[gw->unk_1C]);
            HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.6f));
            HuPrcChildWatch();
            if (D_800F8D12_F9912 == 0) {
                PlaySound(0x363);
            }
            if (gPlayers[gw->current_player_index].turn_status != 0) {
                if (D_800F8D12_F9912 != 0) {
                    MBDlgWinExec(3, 0x22F);
                    func_80108C0C_29DEDC_name_3E();
                    HuPrcSleep(30);
                    MBDlgWinExec(5, 0x230);
                    func_8004CA34_4D634(gw->current_player_index, 20);
                    func_800614B4_620B4(gw->current_player_index, 20);
                } else if (D_800F8D18[0] == 0) {
                    MBDlgWinExec(5, 0x427);
                    func_8004CA34_4D634(gw->current_player_index, 20);
                    func_800614B4_620B4(gw->current_player_index, 20);
                } else {
                    sprintf(buf, D_801135C8_2A8898_name_3E, D_800F8D18[0]);
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
                    roll = func_80103B70_298E40_name_3E();
                    if (roll >= D_801122A4_2A7574_name_3E[func_80059FD0_5ABD0(gw->current_player_index)]) {
                        if (gPlayers[gw->current_player_index].coins >= 5) {
                            MBDlgWinExec(5, 0x423);
                            D_800F8D18[0] += 5;
                            func_8004CA34_4D634(gw->current_player_index, -5);
                            func_800614B4_620B4(gw->current_player_index, -5);
                        } else {
                            sprintf(buf, D_801135C8_2A8898_name_3E, gPlayers[gw->current_player_index].coins);
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
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80108E0C_29E0DC_name_3E);
#endif
/* The coin-collecting space: landing pays the pot (D_800F8CE4[0x1D]) out, passing pays 5 coins in. */
void func_8010964C_29E91C_name_3E(void) {
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
        case 0x8A:
            func_80056C30_57830(-1, 8, 0x99);
            break;
        case 0x5E:
            func_80056C30_57830(-1, 8, 0x9B);
            break;
        }
        HuPrcSleep(8);
        PlaySound(0xE6);
        if (func_80047DE8_489E8(gw->current_player_index) > 0) {
            func_80046D2C_4792C(gw->current_player_index);
            coins = gPlayers[gw->current_player_index].coins;
            if ((coins != 0) & (coins < 5)) {
                sprintf(buf, D_801135C8_2A8898_name_3E, coins);
                sprintf(buf2, D_801135C8_2A8898_name_3E, D_800F8CE4_F98E4[0x1D] + gPlayers[gw->current_player_index].coins);
                func_80056368_56F68(2, 0x17, buf, (s32)buf2, 0, 0, 0);
                MBDlgWinClose();
                D_800F8CE4_F98E4[0x1D] += gPlayers[gw->current_player_index].coins;
                func_8010608C_29B35C_name_3E();
                func_8004CA34_4D634(gw->current_player_index, -gPlayers[gw->current_player_index].coins);
                func_800614B4_620B4(gw->current_player_index, -gPlayers[gw->current_player_index].coins);
                HuPrcSleep(30);
                func_80056124_56D24();
            } else if (gPlayers[gw->current_player_index].coins == 0) {
                sprintf(buf, D_801135C8_2A8898_name_3E, D_800F8CE4_F98E4[0x1D]);
                func_80056368_56F68(2, 0x18, buf, 0, 0, 0, 0);
            } else {
                sprintf(buf, D_801135C8_2A8898_name_3E, D_800F8CE4_F98E4[0x1D] + 5);
                func_80056368_56F68(2, 0x16, buf, 0, 0, 0, 0);
                MBDlgWinClose();
                D_800F8CE4_F98E4[0x1D] += 5;
                func_8010608C_29B35C_name_3E();
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
            sprintf(buf, D_801135C8_2A8898_name_3E, D_800F8CE4_F98E4[0x1D]);
            func_80056368_56F68(2, 0x19, buf, 0, 0, 0, 0);
            MBDlgWinClose();
            func_8004CA34_4D634(gw->current_player_index, D_800F8CE4_F98E4[0x1D]);
            func_800614B4_620B4(gw->current_player_index, D_800F8CE4_F98E4[0x1D]);
            D_800F8CE4_F98E4[0x1D] = 0;
            func_8010608C_29B35C_name_3E();
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
s32 func_80109A78_29ED48_name_3E(s32 arg0) {
    s32 i;

    for (i = 0; i < 5; i++) {
        if (D_801138B8_2A8B88_name_3E[i] != 0) {
            if (D_801122E0_2A75B0_name_3E[D_801138B4_2A8B84_name_3E][i] == arg0) {
                return i;
            }
        }
    }
    return -1;
}
s32 func_80109AE4_29EDB4_name_3E(void) {
    s32 i;

    for (i = 0; i < 5; i++) {
        if (D_801122E0_2A75B0_name_3E[D_801138B4_2A8B84_name_3E][i] == -1) {
            break;
        }
    }
    return i;
}
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80109B30_29EE00_name_3E);

/* MP3 func_8010C914_322484_ChillyWaters: fade a model in */
void func_8010A13C_29F40C_name_3E(MBModel* model) {
    s32 i;

    MBModelDispOn(model);
    for (i = 0; i < 256; i += 12, HuPrcVSleep()) {
        func_8002D0A0_2DCA0(model->obj->model[0], i);
        func_8002D0A0_2DCA0(model->shadow->model[0], i);
    }
    func_8002D0A0_2DCA0(model->obj->model[0], 0xFF);
    func_8002D0A0_2DCA0(model->shadow->model[0], 0xFF);
}
/* MP3 func_8010DD44_3A30C4_w06: fade a model out */
void func_8010A1DC_29F4AC_name_3E(MBModel* model) {
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
