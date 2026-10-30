#include "ovl_1D.h"

void func_801057B0_1B7900_SpeedHockey(void) {
    D_80106EB0_1B9000_SpeedHockey.state = 0;
    D_80106EB0_1B9000_SpeedHockey.next = 0;
    D_80106EB0_1B9000_SpeedHockey.sub = 0;
    D_80106EB0_1B9000_SpeedHockey.timer = 0;
}

/* Create camera cam's sprite from file (hidden); returns its esprite's graphic. */
u16 func_801057CC_1B791C_SpeedHockey(s32 file, u32 cam) {
    if (cam >= 2) {
        while (1) {
        }
    }
    D_80106BD0_1B8D20_SpeedHockey[cam].sprite = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(file), 0, 0);
    if (D_80106BD0_1B8D20_SpeedHockey[cam].sprite == -1) {
        while (1) {
        }
    }
    espDispOff(D_80106BD0_1B8D20_SpeedHockey[cam].sprite);
    return D_800F93FC_F9FFC[D_80106BD0_1B8D20_SpeedHockey[cam].sprite].unk04;
}

/* Save the pads. */
void func_801058A4_1B79F4_SpeedHockey(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_80106EB0_1B9000_SpeedHockey.pad[i].stkX = ContStkX[i];
        D_80106EB0_1B9000_SpeedHockey.pad[i].stkY = ContStkY[i];
        D_80106EB0_1B9000_SpeedHockey.pad[i].btn = ContBtn[i];
        D_80106EB0_1B9000_SpeedHockey.pad[i].trg = ContBtnTrg[i];
    }
}

/* Restore the pads. */
void func_80105934_1B7A84_SpeedHockey(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        ContStkX[i] = D_80106EB0_1B9000_SpeedHockey.pad[i].stkX;
        ContStkY[i] = D_80106EB0_1B9000_SpeedHockey.pad[i].stkY;
        ContBtn[i] = D_80106EB0_1B9000_SpeedHockey.pad[i].btn;
        ContBtnTrg[i] = D_80106EB0_1B9000_SpeedHockey.pad[i].trg;
    }
}

/* Clear the pads. */
void func_801059C4_1B7B14_SpeedHockey(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        ContStkX[i] = ContStkY[i] = 0;
        ContBtnTrg[i] = ContBtn[i] = 0;
    }
}

/* Game state 0: fade in, music, title message. */
void func_80105A18_1B7B68_SpeedHockey(omObjData* obj) {
    switch (D_80106EB0_1B9000_SpeedHockey.sub) {
        case 0:
            D_80106EB0_1B9000_SpeedHockey.countdown = 1;
            D_80106EB0_1B9000_SpeedHockey.time = 1800;
            D_80106EB0_1B9000_SpeedHockey.frame = 0;
            D_80106EB0_1B9000_SpeedHockey.sub = 1;
            D_80106EB0_1B9000_SpeedHockey.winner[0] = -1;
            D_80106EB0_1B9000_SpeedHockey.winner[1] = -1;
            D_80106EB0_1B9000_SpeedHockey.winnerCount = 0;
            D_80106EB0_1B9000_SpeedHockey.winTeam = -1;
            InitFadeIn(0, 16);
            break;
        case 1:
            if (func_8008F618_90218() == 0) {
                D_80106EB0_1B9000_SpeedHockey.sub++;
            }
            break;
        case 2:
            PlayMusic(0x1D);
            func_800691FC_69DFC(0);
            D_80106EB0_1B9000_SpeedHockey.sub++;
            break;
        case 3:
            if (func_80069538_6A138() == 0) {
                D_80106EB0_1B9000_SpeedHockey.sub++;
            }
            break;
        case 4:
            func_80106554_1B86A4_SpeedHockey(1);
            D_80106EB0_1B9000_SpeedHockey.sub = 0;
            break;
    }
}

/* Game state 1: the start countdown. */
void func_80105B00_1B7C50_SpeedHockey(omObjData* obj) {
    if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        if (--D_80106EB0_1B9000_SpeedHockey.countdown < 0) {
            func_800691FC_69DFC(10, 60, 160, 32);
            func_80106554_1B86A4_SpeedHockey(2);
        }
    }
}

/* Game state 2: play; the clock runs down, then the leading team wins. */
void func_80105B6C_1B7CBC_SpeedHockey(omObjData* obj) {
    s32 team;

    if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        func_8006D4D0_6E0D0(--D_80106EB0_1B9000_SpeedHockey.time / 30 + 1);
        if (D_80106EB0_1B9000_SpeedHockey.time < 0) {
            func_8006D4D0_6E0D0(0);
            team = func_801046EC_1B683C_SpeedHockey();
            if (team != -1) {
                func_80106580_1B86D0_SpeedHockey(team);
            }
            func_80106554_1B86A4_SpeedHockey(3);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B7900", func_80105C28_1B7D78_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B7900", func_80105ED4_1B8024_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B7900", func_80105F90_1B80E0_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B7900", func_80106044_1B8194_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B7900", func_80106074_1B81C4_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B7900", func_801060C0_1B8210_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B7900", func_801060F8_1B8248_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B7900", func_801062EC_1B843C_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B7900", func_801064A0_1B85F0_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B7900", func_8010650C_1B865C_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B7900", func_80106548_1B8698_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B7900", func_80106554_1B86A4_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B7900", func_80106580_1B86D0_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B7900", func_8010658C_1B86DC_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B7900", func_80106598_1B86E8_SpeedHockey);
