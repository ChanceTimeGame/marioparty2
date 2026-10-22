#include "ovl_70.h"
#include "game/pad.h"

void func_80102800_40EC60_Results(void) {
    omInitObjMan(0x14, 0x14);
    func_8010492C_410D8C_Results();
    func_80104278_4106D8_Results();
    func_80104B90_410FF0_Results();
    func_80104D3C_41119C_Results();
    omAddPrcObj(&func_80103DB4_410214_Results, 0x300U, 0x3000, 0);
    PlayMusic(0x14);
    omAddObj(5, 0U, 0U, -1, &func_801041C8_410628_Results);
    omAddObj(5, 0U, 0U, -1, &func_801028A0_40ED00_Results);
}

void func_801028A0_40ED00_Results(void) {
    s8 i;

    if (D_801076A2_413B02_Results != 1) {
        for (i = 0; i < 4; i++) {
            if (!(gPlayers[i].flags & 1)) {
                if (ContBtn[gPlayers[i].port] & (A_BUTTON | START_BUTTON)) {
                    D_801076A1_413B01_Results = 1;
                }
            }
        }
    }
}

//related to creating(?) and moving the player sprites
__asm__(".section .rodata");
const char D_80107800_413C60_Results[] = "RESULTS";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_70_Results/40EC60", func_80102944_40EDA4_Results);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_70_Results/40EC60", func_801038A4_40FD04_Results);

void func_80103C6C_4100CC_Results(void) {
    s32 i;
    s32 var_s0_3;

    func_8006AE14_6BA14(&D_80107870_413CD0_Results);
    
    for (i = 0; i < 4; i++) {
        SprAnimKill(D_80107900_413D60_Results[i]);
    }

    for (i = 0; i < 4; i++) {
        SprAnimKill(D_801078E8_413D48_Results[i]);
    }

    SprKill(D_801078E4_413D44_Results);
    SprKill(D_801078F8_413D58_Results);
    SprAnimKill(D_80107CEC_41414C_Results);
    SprKill(D_80107CE8_414148_Results);
    SprAnimKill(D_80107914_413D74_Results);
    SprAnimKill(D_8010791C_413D7C_Results);
    SprKill(D_80107910_413D70_Results);
    SprKill(D_80107918_413D78_Results);
    SprKill(D_80107CE0_414140_Results);
    var_s0_3 = (_CheckFlag(0xD) != 0) * 4;

    for (; var_s0_3 < 8; var_s0_3++) {
        func_8006AE14_6BA14(&D_80107920_413D80_Results[var_s0_3]);
    }
    
    func_8008CE5C_8DA5C();
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_70_Results/40EC60", func_80103DB4_410214_Results);

void func_801041C8_410628_Results(void) {
    s32 i;

    if (D_801076A0_413B00_Results != 0 && func_8008F618_90218() == 0) {
        for (i = 0; i < MAX_PLAYERS; i++) {
            gPlayers[i].coins_mg = 0;
            gPlayers[i].coins_mg_bonus = 0;
        }
        func_80107544_4139A4_Results();
        func_80103C6C_4100CC_Results();
        func_8010438C_4107EC_Results();
        func_801042B4_410714_Results();
        func_80059CC8_5A8C8();
        func_80059400_5A000();
        func_80059704_5A304();
        omOvlReturnEx(1);
    }
}

void func_80104278_4106D8_Results(void) {
    MBModelInit();
    func_8005E2B8_5EEB8();
    func_80059C28_5A828();
    func_800593C0_59FC0();
    func_8005965C_5A25C();
}

void func_801042B4_410714_Results(void) {
    func_8004340C_4400C();
    func_8005E2FC_5EEFC();
}

void func_801042D8_410738_Results(void) {
    func_80018E30_19A30(1);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_80050A30_51630(D_01164160);
    func_80050E00_51A00(D_801077A8_413C08_Results[GwSystem.current_board_index]);
}

void func_8010438C_4107EC_Results(void) {
    MBDBackKill();
    func_80050AE0_516E0();
}

void func_801043B0_410810_Results(s16 grp, s16 idx, s16 dx, s16 dy) {
    HuSprite* spr = HuSprGrpData[grp]->members[idx];

    spr->unk_48 += dx;
    spr->unk_4C += dy;
}

void func_80104418_410878_Results(s16 grp, s16 idx, s16 x) {
    HuSprGrpData[grp]->members[idx]->unk_48 = x;
}

void func_80104458_4108B8_Results(s16 grp, s16 idx, s16 y) {
    HuSprGrpData[grp]->members[idx]->unk_4C = y;
}

void func_80104498_4108F8_Results(s16 grp, s16 idx, s32 mask) {
    HuSprite* spr = HuSprGrpData[grp]->members[idx];

    spr->unk_24 = spr->unk_5C &= mask;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_70_Results/40EC60", func_801044D0_410930_Results);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_70_Results/40EC60", func_801046DC_410B3C_Results);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_70_Results/40EC60", func_8010492C_410D8C_Results);

void func_80104B90_410FF0_Results(void) {
    s32 i;

    for (i = 0; i < MAX_PLAYERS; i++) {
        D_80107860_413CC0_Results[i] = gPlayers[i].coins;
        D_80107830_413C90_Results[i] =  gPlayers[i].coins_mg_bonus;
        D_80107838_413C98_Results[i] = gPlayers[i].coins_mg;
        if ((gPlayers[i].coins + D_80107830_413C90_Results[i] + D_80107838_413C98_Results[i]) > 999) {
            D_80107830_413C90_Results[i] = 999 - gPlayers[i].coins;
            D_80107838_413C98_Results[i] = 0;
        }
        if ((gPlayers[i].coins + D_80107830_413C90_Results[i] + D_80107838_413C98_Results[i] < 0)) {
            D_80107830_413C90_Results[i] = -gPlayers[i].coins;
            D_80107838_413C98_Results[i] = 0;
        }
        gPlayers[i].coins_total += gPlayers[i].coins_mg;
        gPlayers[i].coins_total += gPlayers[i].coins_mg_bonus;
        D_80107840_413CA0_Results[i] = gPlayers[i].coins_mg_bonus;
        D_80107848_413CA8_Results[i] = gPlayers[i].coins_mg;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_70_Results/40EC60", func_80104D3C_41119C_Results);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_70_Results/40EC60", func_80105AB8_411F18_Results);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_70_Results/40EC60", func_80105F50_4123B0_Results);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_70_Results/40EC60", func_801063E8_412848_Results);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_70_Results/40EC60", func_80107140_4135A0_Results);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_70_Results/40EC60", func_801072B0_413710_Results);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_70_Results/40EC60", func_80107544_4139A4_Results);
