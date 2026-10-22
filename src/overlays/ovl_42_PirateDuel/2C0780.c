#include "ovl_42.h"


void func_80102800_2C0780_PirateDuel(void) {
    omInitObjMan(30, 15);
    func_80079128_79D28();
    func_80018E30_19A30(1);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_80050A30_51630(D_01164160);
    MBModelInit();
    func_8005E2B8_5EEB8();
    func_800593C0_59FC0();
    func_800581A0_58DA0();
    func_8010298C_2C090C_PirateDuel();
    func_80088640_89240();
    func_8005FE10_60A10();
    func_80060034_60C34(0, (u8)gPlayers[0].player_space_color);
    func_80060034_60C34(1, (u8)gPlayers[1].player_space_color);
    func_80060034_60C34(2, (u8)gPlayers[2].player_space_color);
    func_80060034_60C34(3, (u8)gPlayers[3].player_space_color);
    HidePlayerHUDVisibility(0, 1);
    HidePlayerHUDVisibility(1, 1);
    HidePlayerHUDVisibility(2, 1);
    HidePlayerHUDVisibility(3, 1);
    omAddPrcObj(func_80102CA0_2C0C20_PirateDuel, 0x5000, 0x2000, 0);
    omAddObj(1000, 0, 0, -1, func_80102BC0_2C0B40_PirateDuel);
}

void func_8010298C_2C090C_PirateDuel(void) {
    s32 bits;
    s32 i;

    D_80109D94_2C7D14_PirateDuel = -1;
    D_80109D88_2C7D08_PirateDuel = 0;
    D_8010A060_2C7FE0_PirateDuel = 0;
    if (_CheckFlag(0x17) == 0) {
        D_8010A060_2C7FE0_PirateDuel = 1;
    }
    bits = D_800F8D1A_F991A.attacker;
    if (_CheckFlag(0x19) != 0) {
        if (ContBtn[0] & 0x8000) {
            bits = 1;
            D_8010A060_2C7FE0_PirateDuel = 0;
        }
        if (ContBtn[0] & 0x4000) {
            bits = 1;
            D_8010A060_2C7FE0_PirateDuel = 1;
        }
    }
    D_80109D90_2C7D10_PirateDuel = 0;
    for (i = 0; bits != 0; i++) {
        bits >>= 1;
        if (bits == 0) {
            break;
        }
        D_80109D90_2C7D10_PirateDuel++;
    }
    D_80109DA8_2C7D28_PirateDuel = 1;
    D_80109D98_2C7D18_PirateDuel[i] = 1;
    bits = D_800F8D1A_F991A.targets;
    if (_CheckFlag(0x19) != 0) {
        if (ContBtn[0] & 0x8000) {
            bits = 0xE;
        }
        if (ContBtn[0] & 0x4000) {
            bits = 2;
        }
    }
    for (i = 0; i < 4; i++) {
        if ((bits >> i) & 1) {
            D_80109DA8_2C7D28_PirateDuel++;
            D_80109D98_2C7D18_PirateDuel[i] = 1;
        }
    }
    for (i = 0; i < 2; i++) {
        D_80109DE0_2C7D60_PirateDuel[i] = 0;
        D_8010A098_2C8018_PirateDuel[i] = 0;
    }
    if (D_80109DA8_2C7D28_PirateDuel == 2) {
        for (i = 0; i < 4; i++) {
            if (D_80109D98_2C7D18_PirateDuel[i] == 1 && i != D_80109D90_2C7D10_PirateDuel) {
                D_80109D94_2C7D14_PirateDuel = i;
                break;
            }
        }
    }
    D_80109DC4_2C7D44_PirateDuel = GwSystem.current_turn;
}

void func_80102BC0_2C0B40_PirateDuel(omObjData* obj) {
    if (D_801011FC_101DFC != 0) {
        MBDBackKill();
        func_80050AE0_516E0();
        func_80059400_5A000();
        func_80069770_6A370();
        func_8008CE5C_8DA5C();
        omOvlReturnEx(1);
    }
}

void func_80102C14_2C0B94_PirateDuel(void) {
    Vec pos;
    Vec rot;
    Vec up;

    pos.x = 0.0f;
    pos.y = 150.0f;
    pos.z = 1300.0f;
    rot.x = rot.z = pos.x;
    rot.y = 100.0f;
    up.x = pos.x;
    up.y = 1.0f;
    up.z = pos.x;
    Hu3DCamSetPositionOrientation(0, &pos, &rot, &up);
    Hu3DCamUpdateMtx(0);
}

__asm__(".section .rodata");
const u32 D_80109BC0_2C7B40_PirateDuel[3] = { 0x00000002, 0x000800A7, 0x000800AA };

__asm__(".section .rodata");
const u32 D_80109BCC_2C7B4C_PirateDuel[3] = { 0x000A01A8, 0x000A01A9, 0x000A01AA };

__asm__(".section .rodata");
const u32 D_80109BD8_2C7B58_PirateDuel[6] = { 0x00000023, 0x0000001E, 0x00000032, 0x00000023, 0x0000001E, 0x00000023 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_80102CA0_2C0C20_PirateDuel);

__asm__(".section .rodata");
const char D_80109BFC_2C7B7C_PirateDuel[] = "%d";

__asm__(".section .rodata");
const char D_80109C00_2C7B80_PirateDuel[] = "%c%c";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_80104B88_2C2B08_PirateDuel);

/* NON_MATCHING: registers (masked 14), as overlay 40's func_801041B4 and 3F's func_80104844: retail
   keeps arg6 in s0 and the narrowed window id in s1 */
#ifdef NON_MATCHING
s32 func_80104FB4_2C2F34_PirateDuel(s16 x, s16 y, s16 w, s16 h, s16 arg4, s16 arg5, s32 arg6) {
    s32 win;
    s16 mask;

    win = func_800888A8_894A8(x, y, w, h, arg4, arg5);
    func_80089284_89E84(win, 0x40, 0x40);
    func_80089A48_8A648(win, 0);
    func_8008D88C_8E48C(win);
    func_80089B2C_8A72C(win, arg6);
    if (D_80109D94_2C7D14_PirateDuel != -1) {
        mask = (1 << gPlayers[D_80109D90_2C7D10_PirateDuel].port) | (1 << gPlayers[D_80109D94_2C7D14_PirateDuel].port);
    } else {
        mask = 1 << gPlayers[D_80109D90_2C7D10_PirateDuel].port;
    }
    func_8008D59C_8E19C(win, mask);
    return (s16)win;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_80104FB4_2C2F34_PirateDuel);
#endif

u16 func_8010511C_2C309C_PirateDuel(void) {
    u16 btn;

    btn = 0;
    if (!(gPlayers[D_80109D90_2C7D10_PirateDuel].flags & 1)) {
        btn = ContDStkTrg[gPlayers[D_80109D90_2C7D10_PirateDuel].port];
    }
    if (D_80109D94_2C7D14_PirateDuel != -1 && btn == 0) {
        if (!(gPlayers[D_80109D94_2C7D14_PirateDuel].flags & 1)) {
            btn = ContDStkTrg[gPlayers[D_80109D94_2C7D14_PirateDuel].port];
        }
    }
    return btn;
}

void func_801051DC_2C315C_PirateDuel(s32 layout) {
    omObjData* obj;
    s32* work;
    BoardStatus* status;
    s32 slot;
    s32 i;
    s32 next;

    D_80109D70_2C7CF0_PirateDuel = 0;
    obj = omAddObj(0x12, 0, 0, -1, func_80105514_2C3494_PirateDuel);
    work = func_80027154_27D54(8, 0x7918);
    obj->unk_50 = work;
    *work = layout;
    next = 0;
    for (i = 0; i < 4; i++) {
        if (D_80109D98_2C7D18_PirateDuel[i] != 0) {
            status = &D_80101510_102110[i];
            slot = 3;
            if (i != D_80109D90_2C7D10_PirateDuel) {
                if (i == D_80109D94_2C7D14_PirateDuel) {
                    slot = 2;
                } else {
                    slot = next;
                    D_80109DB0_2C7D30_PirateDuel[slot] = i;
                    next = slot + 1;
                }
            }
            if (D_801098A0_2C7820_PirateDuel[layout].pos[slot][0] != -1) {
                status->xPos = D_801098A0_2C7820_PirateDuel[layout].pos[slot][0];
            }
            if (D_801098A0_2C7820_PirateDuel[layout].pos[slot][1] != -1) {
                status->yPos = D_801098A0_2C7820_PirateDuel[layout].pos[slot][1];
            }
            func_800600F8_60CF8(i, status->xPos, status->yPos);
            status->unk_0C = D_801098A0_2C7820_PirateDuel[layout].frames - 1;
            if (D_801098A0_2C7820_PirateDuel[layout].pos[slot][2] != -1) {
                status->unk_18 = D_801098A0_2C7820_PirateDuel[layout].pos[slot][2];
            }
            if (D_801098A0_2C7820_PirateDuel[layout].pos[slot][3] != -1) {
                status->unk_1C = D_801098A0_2C7820_PirateDuel[layout].pos[slot][3];
            }
            status->unk_20 = status->unk_28 = 2.0f * (status->unk_18 - status->xPos) / ((status->unk_0C + 1) * (status->unk_0C + 1));
            status->unk_24 = status->unk_2C = 2.0f * (status->unk_1C - status->yPos) / ((status->unk_0C + 1) * (status->unk_0C + 1));
        }
    }
    if (D_80109B10_2C7A90_PirateDuel == 1) {
        status = &D_80101510_102110[D_80109D90_2C7D10_PirateDuel];
        D_800FD854_FE454[0].unk_00 = D_800FC990_FD590[0].unk_00 = status->unk_28;
        D_800FD854_FE454[0].unk_04 = D_800FC990_FD590[0].unk_04 = status->unk_2C;
        D_800FA604_FB204 = D_801098A0_2C7820_PirateDuel[layout].frames - 1;
    }
}

void func_80105514_2C3494_PirateDuel(omObjData* obj) {
    BoardStatus* status;
    s32 done;
    s32 i;

    done = 0;
    for (i = 0; i < 4; i++) {
        if (D_80109D98_2C7D18_PirateDuel[i] != 0) {
            status = &D_80101510_102110[i];
            if (status->unk_0C == 0) {
                status->xPos = status->unk_18;
                status->yPos = status->unk_1C;
                done++;
            }
        }
    }
    if (done == D_80109DA8_2C7D28_PirateDuel) {
        D_80109D70_2C7CF0_PirateDuel = 1;
        omDelObj(obj);
    }
}

void func_801055AC_2C352C_PirateDuel(void) {
    func_80069764_6A364(60);
    omAddObj(0x10, 0, 0, -1, func_801055E8_2C3568_PirateDuel);
}

void func_801055E8_2C3568_PirateDuel(omObjData* obj) {
    if (func_800696E4_6A2E4() == 0) {
        InitFadeOut(0, 20);
        if (D_8010A060_2C7FE0_PirateDuel != 0) {
            func_80079614_7A214(20);
        }
        obj->func_ptr = func_80105640_2C35C0_PirateDuel;
    }
}

void func_80105640_2C35C0_PirateDuel(omObjData* obj) {
    if (func_8008F618_90218() == 0) {
        MBDBackKill();
        func_80050AE0_516E0();
        func_80059400_5A000();
        func_80069770_6A370();
        func_8008CE5C_8DA5C();
        omOvlReturnEx(1);
    }
}

void func_80105694_2C3614_PirateDuel(void) {
    omObjData* obj;
    PdShrink* work;

    obj = omAddObj(0x10, 0, 0, -1, func_80105724_2C36A4_PirateDuel);
    work = func_80027154_27D54(sizeof(PdShrink), 0x7918);
    obj->unk_50 = work;
    work->scaleSpeed = -0.06666667f;
    work->rotSpeed = -3.0f;
    work->unk10 = 0;
    work->unkC = 1.0f;
    work->timer = 15;
}

void func_80105724_2C36A4_PirateDuel(omObjData* obj) {
    PdShrink* work = obj->unk_50;

    D_8010A0B8_2C8038_PirateDuel->scale.x += work->scaleSpeed;
    D_8010A0B8_2C8038_PirateDuel->scale.y += work->scaleSpeed;
    D_8010A0B8_2C8038_PirateDuel->scale.z += work->scaleSpeed;
    D_8010A0B8_2C8038_PirateDuel->obj->rot.x += work->rotSpeed;
    if (--work->timer == 0) {
        MBModelDispOff(D_8010A0B8_2C8038_PirateDuel);
        omDelObj(obj);
    }
}

void func_801057B4_2C3734_PirateDuel(void) {
    s32 ys4[3] = { 32, 90, 148 };
    s32 ys3[2] = { 59, 121 };
    s32 ys[4];
    s16 size[2];
    s32* src;
    s32 win;
    s16 spr;
    u16 btn;
    s32 sel;
    s32 count;
    s32 i;

    func_8008DACC_8E6CC(1, size, 0x212);
    win = func_80104FB4_2C2F34_PirateDuel(70, 178, size[0], size[1], 0, 0, 200);
    func_8008AD44_8B944(win);
    func_800890CC_89CCC(win, 0x212, -1, -1);
    sel = 0;
    count = D_80109DA8_2C7D28_PirateDuel - 1;
    if (D_80109DA8_2C7D28_PirateDuel == 4) {
        src = ys4;
    } else {
        src = ys3;
    }
    for (i = 0; i < D_80109DA8_2C7D28_PirateDuel; i++) {
        ys[i] = *src++;
    }
    spr = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x42), 1, 1);
    espDispOn(spr);
    if (gPlayers[D_80109D90_2C7D10_PirateDuel].flags & 1) {
        func_801070F4_2C5074_PirateDuel(sel, 0, 2);
    }
    while (TRUE) {
        btn = func_8010511C_2C309C_PirateDuel();
        if (gPlayers[D_80109D90_2C7D10_PirateDuel].flags & 1) {
            btn = func_801078C4_2C5844_PirateDuel();
        }
        if ((btn & 0x8000) && BoardSpaceGet(D_80109DB0_2C7D30_PirateDuel[sel], 1) != 0) {
            PlaySound(2);
            D_80109D70_2C7CF0_PirateDuel = 1;
            D_80109D94_2C7D14_PirateDuel = D_80109DB0_2C7D30_PirateDuel[sel];
            espDispOff(spr);
            func_8008CCA8_8D8A8(win);
            omDelPrcObj(NULL);
        }
        if (btn & 0x400) {
            PlaySound(1);
            sel++;
            if (sel >= count) {
                sel = 0;
            }
        }
        if (btn & 0x800) {
            PlaySound(1);
            sel--;
            if (sel < 0) {
                sel = count - 1;
            }
        }
        espPosSet(spr, 184, ys[sel]);
        D_800F851A_F911A = 1;
        HuPrcVSleep();
    }
}

/* The stake (as 3F's func_80105054): the starting amount comes from the turn (turns[] bands) and
   the poorer player's coins (stakes[]); right/left add or take 1, up/down 10, A accepts. Both
   duelists pay the stake as it changes. Retail quirk: at the 999 cap a further raise still takes
   the coin from both players. */
#define PD_STAKE_SHOW(win, stake)                                           \
    sprintf(num, D_80109BFC_2C7B7C_PirateDuel, stake);                      \
    len = func_800A5610_A6210(num);                                         \
    for (j = 0; j < 3 - len; j++) {                                         \
        pad[j] = 0x1A;                                                      \
    }                                                                       \
    pad[j] = 0;                                                             \
    sprintf(buf, "%c%c%s%d", 0xF, 6, pad, stake);                           \
    func_800890CC_89CCC(win, (s32)buf, x, y)

void func_80105A80_2C3A00_PirateDuel(void) {
    s32 stakes[6] = { 1, 5, 10, 20, 30, 50 };
    s32 turns[4] = { 11, 21, 36, 46 };
    char buf[0x200];
    char mess[0x20];
    s16 size[2];
    char num[8];
    char pad[16];
    s32 win;
    s32 coins1;
    s32 coins2;
    u16 btn;
    s32 stake;
    s32 len;
    s32 turn;
    s32 y;
    s32 x;
    s32 i;
    s32 j;

    turn = D_80109DC4_2C7D44_PirateDuel;
    i = 0;
    while (turn >= turns[i]) {
        if (++i == 4) {
            break;
        }
    }
    coins1 = BoardPlayerGet(D_80109D90_2C7D10_PirateDuel)->coins;
    coins2 = BoardPlayerGet(D_80109D94_2C7D14_PirateDuel)->coins;
    D_80109DCC_2C7D4C_PirateDuel = coins1;
    if (coins2 < coins1) {
        D_80109DCC_2C7D4C_PirateDuel = coins2;
    }
    i++;
    while (D_80109DCC_2C7D4C_PirateDuel < stakes[i]) {
        if (--i == 0) {
            break;
        }
    }
    D_80109D74_2C7CF4_PirateDuel = D_80109DC0_2C7D40_PirateDuel = stakes[i];
    x = 0x2F;
    y = 0x2E;
    stake = D_80109DC0_2C7D40_PirateDuel;
    sprintf(mess, "", stake);
    func_8008D974_8E574(mess, 0);
    func_8008DACC_8E6CC(1, size, 0x213);
    win = func_80104FB4_2C2F34_PirateDuel(24, 72, size[0], size[1], 0, 0, 200);
    func_80089308_89F08(win, mess, 0);
    func_8008AD44_8B944(win);
    func_800890CC_89CCC(win, 0x213, -1, -1);
    HuPrcVSleep();
    func_80089284_89E84(win, 0x10004, 0x10004);
    PD_STAKE_SHOW(win, stake);
    func_80057730_58330(win, D_80109D90_2C7D10_PirateDuel);
    AdjustPlayerCoins(D_80109D90_2C7D10_PirateDuel, -D_80109D74_2C7CF4_PirateDuel);
    AdjustPlayerCoins(D_80109D94_2C7D14_PirateDuel, -D_80109D74_2C7CF4_PirateDuel);
    func_80089284_89E84(win, 4, 4);
    if (gPlayers[D_80109D90_2C7D10_PirateDuel].flags & 1) {
        func_801070F4_2C5074_PirateDuel(D_80109D74_2C7CF4_PirateDuel, D_80109DCC_2C7D4C_PirateDuel, 3);
    }
    while (TRUE) {
        D_80109D74_2C7CF4_PirateDuel = stake;
        btn = ContDStkTrg[gPlayers[D_80109D90_2C7D10_PirateDuel].port];
        if (gPlayers[D_80109D90_2C7D10_PirateDuel].flags & 1) {
            btn = func_801078C4_2C5844_PirateDuel();
        }
        if (btn & 0x8000) {
            PlaySound(2);
            D_800F851A_F911A = 0;
            func_8008CCA8_8D8A8(win);
            D_80109D70_2C7CF0_PirateDuel = 1;
            omDelPrcObj(NULL);
        } else if (btn & 0x800) {
            if (gPlayers[D_80109D90_2C7D10_PirateDuel].coins > 0 && gPlayers[D_80109D94_2C7D14_PirateDuel].coins > 0) {
                if (++stake >= 1000) {
                    stake = 999;
                } else {
                    PlaySound(0x37B);
                }
                PD_STAKE_SHOW(win, stake);
                AdjustPlayerCoins(D_80109D90_2C7D10_PirateDuel, -1);
                AdjustPlayerCoins(D_80109D94_2C7D14_PirateDuel, -1);
            }
        } else if (btn & 0x400) {
            if (D_80109DC0_2C7D40_PirateDuel < stake) {
                stake--;
                PlaySound(0x37C);
                PD_STAKE_SHOW(win, stake);
                AdjustPlayerCoins(D_80109D90_2C7D10_PirateDuel, 1);
                AdjustPlayerCoins(D_80109D94_2C7D14_PirateDuel, 1);
            }
        } else if (btn & 0x200) {
            if (stake - 10 >= D_80109DC0_2C7D40_PirateDuel) {
                stake -= 10;
                PlaySound(0x37C);
                PD_STAKE_SHOW(win, stake);
                AdjustPlayerCoins(D_80109D90_2C7D10_PirateDuel, 10);
                AdjustPlayerCoins(D_80109D94_2C7D14_PirateDuel, 10);
            }
        } else if (btn & 0x100) {
            if (gPlayers[D_80109D90_2C7D10_PirateDuel].coins >= 10 && gPlayers[D_80109D94_2C7D14_PirateDuel].coins >= 10) {
                stake += 10;
                if (stake >= 1000) {
                    stake = 999;
                } else {
                    PlaySound(0x37B);
                }
                PD_STAKE_SHOW(win, stake);
                AdjustPlayerCoins(D_80109D90_2C7D10_PirateDuel, -10);
                AdjustPlayerCoins(D_80109D94_2C7D14_PirateDuel, -10);
            }
        }
        HuPrcVSleep();
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_801062FC_2C427C_PirateDuel);

__asm__(".section .rodata");
const u32 D_80109C4C_2C7BCC_PirateDuel[3] = { 0x00008000, 0x00004000, 0x00002000 };

__asm__(".section .rodata");
const u32 D_80109C58_2C7BD8_PirateDuel[4] = { 0x00000004, 0x00000003, 0x00000002, 0x00000001 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_801064E8_2C4468_PirateDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_80106B5C_2C4ADC_PirateDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_80106E08_2C4D88_PirateDuel);

__asm__(".section .rodata");
const u32 D_80109C68_2C7BE8_PirateDuel[32] = { 0xFFFFFFFF, 0x00000001, 0x00000003, 0x00000002, 0x00000003, 0x00000003, 0x00000003, 0x00000003, 0x00000000, 0x00000001, 0xFFFFFFFF, 0x00000001, 0x00000001, 0x00000002, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000001, 0xFFFFFFFF, 0x00000001, 0x00000001, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000001, 0xFFFFFFFF, 0xFFFFFFFF };

__asm__(".section .rodata");
const u32 D_80109CE8_2C7C68_PirateDuel[4] = { 0x0000000A, 0x00000014, 0x00000014, 0x00000009 };

__asm__(".section .rodata");
const u32 D_80109CF8_2C7C78_PirateDuel[4] = { 0x0000005A, 0x0000003C, 0x00000014, 0x00000001 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_801070F4_2C5074_PirateDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_80107724_2C56A4_PirateDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_801078C4_2C5844_PirateDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_801078D0_2C5850_PirateDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_80107D00_2C5C80_PirateDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_80107E20_2C5DA0_PirateDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_80108000_2C5F80_PirateDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_80108384_2C6304_PirateDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_801086B0_2C6630_PirateDuel);

__asm__(".section .rodata");
const u32 D_80109D08_2C7C88_PirateDuel[6] = { 0x425C0000, 0x41F00000, 0x425C0000, 0x42480000, 0x41F00000, 0x41A00000 };

__asm__(".section .rodata");
const u32 D_80109D20_2C7CA0_PirateDuel[6] = { 0x428C0000, 0x42A00000, 0x42A00000, 0x42A00000, 0x428C0000, 0x42480000 };

__asm__(".section .rodata");
const u32 D_80109D38_2C7CB8_PirateDuel[6] = { 0x42200000, 0x41F00000, 0x00000000, 0x00000000, 0x00000000, 0xC1200000 };

__asm__(".section .rodata");
const u32 D_80109D50_2C7CD0_PirateDuel[6] = { 0x41200000, 0x41200000, 0x41200000, 0x00000000, 0x00000000, 0x00000000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_801088FC_2C687C_PirateDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_80108F98_2C6F18_PirateDuel);

__asm__(".section .rodata");
const u32 D_80109D68_2C7CE8_PirateDuel[2] = { 0x0058002E, 0x00E8002E };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_80109040_2C6FC0_PirateDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_8010913C_2C70BC_PirateDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_80109214_2C7194_PirateDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_80109344_2C72C4_PirateDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_801093D8_2C7358_PirateDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_801094D4_2C7454_PirateDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_80109648_2C75C8_PirateDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_42_PirateDuel/2C0780", func_80109780_2C7700_PirateDuel);
