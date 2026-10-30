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

/* Game state 3: the result: message, winners' cheer, +10 coins each to the winning pair. */
void func_80105C28_1B7D78_SpeedHockey(omObjData* obj) {
    switch (D_80106EB0_1B9000_SpeedHockey.sub) {
        case 0:
            func_800794A8_7A0A8(60);
            func_800691FC_69DFC(3);
            func_8006D518_6E118();
            D_80106EB0_1B9000_SpeedHockey.timer = 60;
            D_80106EB0_1B9000_SpeedHockey.sub++;
            break;
        case 1:
            if (_CheckFlag(0xC)) {
                if (--D_80106EB0_1B9000_SpeedHockey.timer == -1) {
                    if (D_80106EB0_1B9000_SpeedHockey.winTeam >= 0) {
                        gPlayers[D_80106EB0_1B9000_SpeedHockey.winner[0]].coins_mg_bonus += 10;
                        gPlayers[D_80106EB0_1B9000_SpeedHockey.winner[1]].coins_mg_bonus += 10;
                    }
                    func_80106554_1B86A4_SpeedHockey(4);
                }
            } else if (func_80069538_6A138() == 0) {
                D_80106EB0_1B9000_SpeedHockey.timer = 15;
                D_80106EB0_1B9000_SpeedHockey.sub++;
            }
            break;
        case 3:
            if (D_80106EB0_1B9000_SpeedHockey.winTeam < 0) {
                PlayMusic(0x57);
                func_800691FC_69DFC(0x13);
                D_80106EB0_1B9000_SpeedHockey.timer = 120;
            } else {
                PlayMusic(0x52);
                func_800691FC_69DFC(0x11, gPlayers[D_80106EB0_1B9000_SpeedHockey.winner[0]].character,
                                    gPlayers[D_80106EB0_1B9000_SpeedHockey.winner[1]].character);
                D_80106EB0_1B9000_SpeedHockey.timer = 168;
            }
            D_80106EB0_1B9000_SpeedHockey.sub++;
            break;
        case 2:
        case 4:
            if (--D_80106EB0_1B9000_SpeedHockey.timer == -1) {
                D_80106EB0_1B9000_SpeedHockey.sub++;
            }
            break;
        case 5:
            if (D_80106EB0_1B9000_SpeedHockey.winTeam >= 0) {
                gPlayers[D_80106EB0_1B9000_SpeedHockey.winner[0]].coins_mg_bonus += 10;
                gPlayers[D_80106EB0_1B9000_SpeedHockey.winner[1]].coins_mg_bonus += 10;
            }
            func_80106554_1B86A4_SpeedHockey(4);
            D_80106EB0_1B9000_SpeedHockey.sub = 0;
            break;
    }
}

/* Game state 4: fade out and leave. */
void func_80105ED4_1B8024_SpeedHockey(omObjData* obj) {
    switch (D_80106EB0_1B9000_SpeedHockey.sub) {
        case 0:
            func_800794A8_7A0A8(40);
            InitFadeOut(0, 20);
            D_80106EB0_1B9000_SpeedHockey.sub++;
            break;
        case 1:
            if (func_8008F618_90218() == 0) {
                D_80106EB0_1B9000_SpeedHockey.sub++;
            }
            break;
        case 2:
            func_80105768_1B78B8_SpeedHockey();
            func_80104584_1B66D4_SpeedHockey();
            func_8002864C_2924C();
            func_80023124_23D24();
            omOvlReturnEx(1);
            break;
    }
}

/* The game object (before the players): run the state; outside play the pads are saved and
   cleared, so the objects see no input. */
void func_80105F90_1B80E0_SpeedHockey(omObjData* obj) {
    if (D_801011FC_101DFC == 1 && D_80106EB0_1B9000_SpeedHockey.state != 4) {
        func_80106554_1B86A4_SpeedHockey(4);
    }
    D_80106EB0_1B9000_SpeedHockey.state = D_80106EB0_1B9000_SpeedHockey.next;
    if (D_80106EB0_1B9000_SpeedHockey.state != 2) {
        func_801058A4_1B79F4_SpeedHockey();
        func_801059C4_1B7B14_SpeedHockey();
    }
    D_80106C24_1B8D74_SpeedHockey[D_80106EB0_1B9000_SpeedHockey.state](obj);
    D_80106EB0_1B9000_SpeedHockey.frame++;
}

/* After the objects: give the pads back. */
void func_80106044_1B8194_SpeedHockey(omObjData* obj) {
    if (D_80106EB0_1B9000_SpeedHockey.state != 2) {
        func_80105934_1B7A84_SpeedHockey();
    }
}

void func_80106074_1B81C4_SpeedHockey(Vec* v) {
    if (!(HuVecGetLength3F(v) < 0.001f)) {
        func_800B33E0_B3FE0(v);
    }
}

void func_801060C0_1B8210_SpeedHockey(void) {
    omInitObjMan(0x32, 0);
    func_80079128_79D28();
    func_801057B0_1B7900_SpeedHockey();
    func_80020D20_21920(0x1E);
}

/* The camera: viewport, scissor, sprite camera and perspective. */
void func_801060F8_1B8248_SpeedHockey(void) {
    s32 i;
    u8 id;

    func_80018E30_19A30(1);
    for (i = 0; i < 1; i++) {
        id = func_80018E78_19A78();
        ScissorSet(id, D_80106BD0_1B8D20_SpeedHockey[i].scissor[0], D_80106BD0_1B8D20_SpeedHockey[i].scissor[1],
                   D_80106BD0_1B8D20_SpeedHockey[i].scissor[2], D_80106BD0_1B8D20_SpeedHockey[i].scissor[3]);
        ViewportSet(id, D_80106BD0_1B8D20_SpeedHockey[i].vp[0], D_80106BD0_1B8D20_SpeedHockey[i].vp[1], 511.0f,
                    D_80106BD0_1B8D20_SpeedHockey[i].vp[2], D_80106BD0_1B8D20_SpeedHockey[i].vp[3], 511.0f);
    }
    D_80101078_101C78 = 5000.0f;
    D_800F8410_F9010 = 1000.0f;
    func_8007A27C_7AE7C(0x7FDA, (s16)func_801057CC_1B791C_SpeedHockey(D_80106BD0_1B8D20_SpeedHockey[0].file, 0),
                        func_8007A7FC_7B3FC, D_80106BD0_1B8D20_SpeedHockey[0].fov, &D_80106BD0_1B8D20_SpeedHockey[0].eye,
                        &D_80106BD0_1B8D20_SpeedHockey[0].at);
    Hu3DCamSetPerspective(0, D_80106BD0_1B8D20_SpeedHockey[0].fov, 2000.0f, 5000.0f);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B7900", func_801062EC_1B843C_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B7900", func_801064A0_1B85F0_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B7900", func_8010650C_1B865C_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B7900", func_80106548_1B8698_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B7900", func_80106554_1B86A4_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B7900", func_80106580_1B86D0_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B7900", func_8010658C_1B86DC_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B7900", func_80106598_1B86E8_SpeedHockey);
