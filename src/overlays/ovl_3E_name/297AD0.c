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
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80103548_298818_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80103968_298C38_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_801039E4_298CB4_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80103A64_298D34_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80103AF4_298DC4_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80103B70_298E40_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80103BC4_298E94_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80103C94_298F64_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80103CF4_298FC4_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80103FB0_299280_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_801041D4_2994A4_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80104380_299650_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_801045C0_299890_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80104778_299A48_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80104F7C_29A24C_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_8010537C_29A64C_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80105630_29A900_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_801058A4_29AB74_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_801058DC_29ABAC_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80105974_29AC44_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80105B9C_29AE6C_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80105C24_29AEF4_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80105C50_29AF20_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80105D54_29B024_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80105DDC_29B0AC_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80105EC4_29B194_name_3E);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3E_name/297AD0", func_80105F0C_29B1DC_name_3E);

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
