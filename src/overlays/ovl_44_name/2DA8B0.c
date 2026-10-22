#include "ovl_44.h"

void func_80102800_2DA8B0_name_44(void) {
    omInitObjMan(40, 40);
    func_80079128_79D28();
    func_80018E30_19A30(1);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_80050A30_51630(D_01164160);
    MBModelInit();
    func_8005E2B8_5EEB8();
    func_800593C0_59FC0();
    func_800581A0_58DA0();
    func_8010298C_2DAA3C_name_44();
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
    omAddPrcObj(func_80102D00_2DADB0_name_44, 0x5000, 0x2000, 0);
    omAddObj(1000, 0, 0, -1, func_80102C20_2DACD0_name_44);
}

void func_8010298C_2DAA3C_name_44(void) {
    s32 bits;
    s32 i;

    D_80108EA4_2E0F54_name_44 = -1;
    D_80108E98_2E0F48_name_44 = 0;
    D_80108FE4_2E1094_name_44 = 0;
    if (_CheckFlag(0x17) == 0) {
        D_80108FE4_2E1094_name_44 = 1;
    }
    bits = D_800F8D1A_F991A.attacker;
    if (_CheckFlag(0x19) != 0) {
        if (ContBtn[0] & 0x8000) {
            bits = 1;
            D_80108FE4_2E1094_name_44 = 0;
        }
        if (ContBtn[0] & 0x4000) {
            bits = 1;
            D_80108FE4_2E1094_name_44 = 1;
        }
    }
    D_80108EA0_2E0F50_name_44 = 0;
    for (i = 0; bits != 0; i++) {
        bits >>= 1;
        if (bits == 0) {
            break;
        }
        D_80108EA0_2E0F50_name_44++;
    }
    D_80108EB8_2E0F68_name_44 = 1;
    D_80108EA8_2E0F58_name_44[i] = 1;
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
            D_80108EB8_2E0F68_name_44++;
            D_80108EA8_2E0F58_name_44[i] = 1;
        }
    }
    for (i = 0; i < 2; i++) {
        D_80108EE0_2E0F90_name_44[i] = 0;
    }
    if (D_80108EB8_2E0F68_name_44 == 2) {
        for (i = 0; i < 4; i++) {
            if (D_80108EA8_2E0F58_name_44[i] == 1 && i != D_80108EA0_2E0F50_name_44) {
                D_80108EA4_2E0F54_name_44 = i;
                break;
            }
        }
    }
    func_801079E4_2DFA94_name_44();
    for (i = 0; i < 2; i++) {
        D_80108FB8_2E1068_name_44[i] = 0;
        D_80108FC8_2E1078_name_44[i] = NULL;
        D_80108FD0_2E1080_name_44[i] = NULL;
        D_80108FD8_2E1088_name_44[i] = 0;
    }
    D_80108FE0_2E1090_name_44 = 0;
    D_800FC880_FD480 = 0;
    D_800F8C5C_F985C = 0;
    D_80108ED4_2E0F84_name_44 = GwSystem.current_turn;
}

void func_80102C20_2DACD0_name_44(omObjData* obj) {
    if (D_801011FC_101DFC != 0) {
        MBDBackKill();
        func_80050AE0_516E0();
        func_80059400_5A000();
        func_80069770_6A370();
        func_8008CE5C_8DA5C();
        omOvlReturnEx(1);
    }
}

void func_80102C74_2DAD24_name_44(void) {
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
const u32 D_80108C80_2E0D30_name_44[3] = { 0x00000002, 0x000800A7, 0x000800AA };

__asm__(".section .rodata");
const u32 D_80108C8C_2E0D3C_name_44[6] = { 0x00000023, 0x0000001E, 0x00000032, 0x00000023, 0x0000001E, 0x00000023 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_44_name/2DA8B0", func_80102D00_2DADB0_name_44);

/* With func_80102D00 as INCLUDE_ASM, GCC still believes it is in .rodata here (the asm switched to
   .text): switch for real, so the string literals below land in .rodata. */
__asm__(".section .rodata");

void func_80105158_2DD208_name_44(void) {
    s16 size[2];
    char num[0x100];
    char name[0x100];
    s32 win;
    u16 btn;

    if (D_80108E90_2E0F40_name_44 == 3) {
        sprintf(num, "%d", D_80108E84_2E0F34_name_44);
        func_8008D974_8E574(num, 0);
    }
    if (D_80108E90_2E0F40_name_44 == 4) {
        sprintf(num, "%d", D_80108E84_2E0F34_name_44);
        sprintf(name, "%c%c", 0x18, gPlayers[D_80108E9C_2E0F4C_name_44].character);
        func_8008D974_8E574(name, 0);
        func_8008D974_8E574(num, 1);
        func_8008D974_8E574(name, 2);
    }
    if (D_80108E90_2E0F40_name_44 == 5) {
        sprintf(num, "%c%c", 0x18, gPlayers[D_80108E9C_2E0F4C_name_44].character);
        func_8008D974_8E574(num, 0);
    }
    func_8008DACC_8E6CC(1, size, D_80108E94_2E0F44_name_44);
    win = func_80105584_2DD634_name_44((s16)D_80108E88_2E0F38_name_44, (s16)D_80108E8C_2E0F3C_name_44, size[0], size[1], 0, 0, 200);
    if (D_80108E98_2E0F48_name_44 & 1) {
        ShowTextWindow((s16)win);
    }
    if (D_80108E90_2E0F40_name_44 == 3 || D_80108E90_2E0F40_name_44 == 5) {
        func_80089308_89F08(win, num, 0);
    }
    if (D_80108E90_2E0F40_name_44 == 4) {
        func_80089308_89F08(win, name, 0);
        func_80089308_89F08(win, num, 1);
        func_80089308_89F08(win, name, 2);
    }
    func_8008AD44_8B944(win);
    func_800890CC_89CCC(win, D_80108E94_2E0F44_name_44, -1, -1);
    func_80057A78_58678((s16)win, D_80108EA0_2E0F50_name_44, D_80108EA4_2E0F54_name_44);
    if (D_80108E90_2E0F40_name_44 == 1 && (gPlayers[D_80108EA0_2E0F50_name_44].flags & 1) && (gPlayers[D_80108EA4_2E0F54_name_44].flags & 1)) {
        func_80107208_2DF2B8_name_44(0, 0, 0);
    }
    while (TRUE) {
        switch (D_80108E90_2E0F40_name_44) {
            case 1:
                if ((gPlayers[D_80108EA0_2E0F50_name_44].flags & 1) && (gPlayers[D_80108EA4_2E0F54_name_44].flags & 1)) {
                    btn = func_801079D8_2DFA88_name_44();
                } else {
                    btn = func_801056EC_2DD79C_name_44();
                }
                if (btn & 0x1000) {
                    PlaySound(2);
                    D_80108E80_2E0F30_name_44 = 1;
                    func_8008CCA8_8D8A8(win);
                    omDelPrcObj(NULL);
                }
                break;
            case 2:
            case 3:
            case 4:
            case 5:
                if (D_80108E98_2E0F48_name_44 & 1) {
                    func_8005762C_5822C((s16)win);
                } else {
                    func_8008CCA8_8D8A8(win);
                }
                D_80108E80_2E0F30_name_44 = 1;
                omDelPrcObj(NULL);
                break;
        }
        HuPrcVSleep();
    }
}

#ifdef NON_MATCHING
s32 func_80105584_2DD634_name_44(s16 x, s16 y, s16 w, s16 h, s16 arg4, s16 arg5, s32 arg6) {
    s32 win;
    s16 mask;

    win = func_800888A8_894A8(x, y, w, h, arg4, arg5);
    func_80089284_89E84(win, 0x40, 0x40);
    func_80089A48_8A648(win, 0);
    func_8008D88C_8E48C(win);
    func_80089B2C_8A72C(win, arg6);
    if (D_80108EA4_2E0F54_name_44 != -1) {
        mask = (1 << gPlayers[D_80108EA0_2E0F50_name_44].port) | (1 << gPlayers[D_80108EA4_2E0F54_name_44].port);
    } else {
        mask = 1 << gPlayers[D_80108EA0_2E0F50_name_44].port;
    }
    func_8008D59C_8E19C(win, mask);
    return (s16)win;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_44_name/2DA8B0", func_80105584_2DD634_name_44);
#endif

u16 func_801056EC_2DD79C_name_44(void) {
    u16 btn;

    btn = 0;
    if (!(gPlayers[D_80108EA0_2E0F50_name_44].flags & 1)) {
        btn = ContDStkTrg[gPlayers[D_80108EA0_2E0F50_name_44].port];
    }
    if (D_80108EA4_2E0F54_name_44 != -1 && btn == 0) {
        if (!(gPlayers[D_80108EA4_2E0F54_name_44].flags & 1)) {
            btn = ContDStkTrg[gPlayers[D_80108EA4_2E0F54_name_44].port];
        }
    }
    return btn;
}

void func_801057AC_2DD85C_name_44(s32 layout) {
    omObjData* obj;
    s32* work;
    BoardStatus* status;
    s32 slot;
    s32 i;
    s32 next;

    D_80108E80_2E0F30_name_44 = 0;
    obj = omAddObj(0x12, 0, 0, -1, func_80105AE4_2DDB94_name_44);
    work = func_80027154_27D54(8, 0x7918);
    obj->unk_50 = work;
    *work = layout;
    next = 0;
    for (i = 0; i < 4; i++) {
        if (D_80108EA8_2E0F58_name_44[i] != 0) {
            status = &D_80101510_102110[i];
            slot = 3;
            if (i != D_80108EA0_2E0F50_name_44) {
                if (i == D_80108EA4_2E0F54_name_44) {
                    slot = 2;
                } else {
                    slot = next;
                    D_80108EC0_2E0F70_name_44[slot] = i;
                    next = slot + 1;
                }
            }
            if (D_80108920_2E09D0_name_44[layout].pos[slot][0] != -1) {
                status->xPos = D_80108920_2E09D0_name_44[layout].pos[slot][0];
            }
            if (D_80108920_2E09D0_name_44[layout].pos[slot][1] != -1) {
                status->yPos = D_80108920_2E09D0_name_44[layout].pos[slot][1];
            }
            func_800600F8_60CF8(i, status->xPos, status->yPos);
            status->unk_0C = D_80108920_2E09D0_name_44[layout].frames - 1;
            if (D_80108920_2E09D0_name_44[layout].pos[slot][2] != -1) {
                status->unk_18 = D_80108920_2E09D0_name_44[layout].pos[slot][2];
            }
            if (D_80108920_2E09D0_name_44[layout].pos[slot][3] != -1) {
                status->unk_1C = D_80108920_2E09D0_name_44[layout].pos[slot][3];
            }
            status->unk_20 = status->unk_28 = 2.0f * (status->unk_18 - status->xPos) / ((status->unk_0C + 1) * (status->unk_0C + 1));
            status->unk_24 = status->unk_2C = 2.0f * (status->unk_1C - status->yPos) / ((status->unk_0C + 1) * (status->unk_0C + 1));
        }
    }
    if (D_80108AE8_2E0B98_name_44[0] == 1) {
        status = &D_80101510_102110[D_80108EA0_2E0F50_name_44];
        D_800FD854_FE454[0].unk_00 = D_800FC990_FD590[0].unk_00 = status->unk_28;
        D_800FD854_FE454[0].unk_04 = D_800FC990_FD590[0].unk_04 = status->unk_2C;
        D_800FA604_FB204 = D_80108920_2E09D0_name_44[layout].frames - 1;
    }
}

void func_80105AE4_2DDB94_name_44(omObjData* obj) {
    BoardStatus* status;
    s32 done;
    s32 i;

    done = 0;
    for (i = 0; i < 4; i++) {
        if (D_80108EA8_2E0F58_name_44[i] != 0) {
            status = &D_80101510_102110[i];
            if (status->unk_0C == 0) {
                status->xPos = status->unk_18;
                status->yPos = status->unk_1C;
                done++;
            }
        }
    }
    if (done == D_80108EB8_2E0F68_name_44) {
        D_80108E80_2E0F30_name_44 = 1;
        omDelObj(obj);
    }
}

void func_80105B7C_2DDC2C_name_44(void) {
    omAddObj(0x10, 0, 0, -1, func_80105BB8_2DDC68_name_44);
    func_80069764_6A364(60);
}

void func_80105BB8_2DDC68_name_44(omObjData* obj) {
    if (func_800696E4_6A2E4() == 0) {
        InitFadeOut(0, 20);
        if (D_80108FE4_2E1094_name_44 != 0) {
            func_80079614_7A214(20);
        }
        obj->func_ptr = func_80105C10_2DDCC0_name_44;
    }
}

void func_80105C10_2DDCC0_name_44(omObjData* obj) {
    if (func_8008F618_90218() == 0) {
        MBDBackKill();
        func_80050AE0_516E0();
        func_80059400_5A000();
        func_80069770_6A370();
        func_8008CE5C_8DA5C();
        omOvlReturnEx(1);
    }
}

void func_80105C64_2DDD14_name_44(void) {
    omObjData* obj;
    PdShrink* work;

    obj = omAddObj(0x10, 0, 0, -1, func_80105CF4_2DDDA4_name_44);
    work = func_80027154_27D54(sizeof(PdShrink), 0x7918);
    obj->unk_50 = work;
    work->scaleSpeed = -0.06666667f;
    work->rotSpeed = -3.0f;
    work->unk10 = 0;
    work->unkC = 1.0f;
    work->timer = 15;
}

void func_80105CF4_2DDDA4_name_44(omObjData* obj) {
    PdShrink* work = obj->unk_50;

    D_80108FF0_2E10A0_name_44->scale.x += work->scaleSpeed;
    D_80108FF0_2E10A0_name_44->scale.y += work->scaleSpeed;
    D_80108FF0_2E10A0_name_44->scale.z += work->scaleSpeed;
    D_80108FF0_2E10A0_name_44->obj->rot.x += work->rotSpeed;
    if (--work->timer == 0) {
        MBModelDispOff(D_80108FF0_2E10A0_name_44);
        omDelObj(obj);
    }
}

void func_80105D84_2DDE34_name_44(void) {
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
    win = func_80105584_2DD634_name_44(70, 178, size[0], size[1], 0, 0, 200);
    func_8008AD44_8B944(win);
    func_800890CC_89CCC(win, 0x212, -1, -1);
    sel = 0;
    count = D_80108EB8_2E0F68_name_44 - 1;
    if (D_80108EB8_2E0F68_name_44 == 4) {
        src = ys4;
    } else {
        src = ys3;
    }
    for (i = 0; i < D_80108EB8_2E0F68_name_44; i++) {
        ys[i] = *src++;
    }
    spr = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x42), 0, 1);
    espDispOn(spr);
    if (gPlayers[D_80108EA0_2E0F50_name_44].flags & 1) {
        func_80107208_2DF2B8_name_44(sel, 0, 2);
    }
    while (TRUE) {
        btn = func_801056EC_2DD79C_name_44();
        if (gPlayers[D_80108EA0_2E0F50_name_44].flags & 1) {
            btn = func_801079D8_2DFA88_name_44();
        }
        if ((btn & 0x8000) && BoardSpaceGet(D_80108EC0_2E0F70_name_44[sel], 1) != 0) {
            PlaySound(2);
            D_80108E80_2E0F30_name_44 = 1;
            D_80108EA4_2E0F54_name_44 = D_80108EC0_2E0F70_name_44[sel];
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

#define PD_STAKE_SHOW(win, stake)                                           \
    sprintf(num, "%d", stake);                                              \
    len = func_800A5610_A6210(num);                                         \
    for (j = 0; j < 3 - len; j++) {                                         \
        pad[j] = 0x1A;                                                      \
    }                                                                       \
    pad[j] = 0;                                                             \
    sprintf(buf, "%c%c%s%d", 0xF, 6, pad, stake);                           \
    func_800890CC_89CCC(win, (s32)buf, x, y)

void func_80106050_2DE100_name_44(void) {
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

    turn = D_80108ED4_2E0F84_name_44;
    i = 0;
    while (turn >= turns[i]) {
        if (++i == 4) {
            break;
        }
    }
    coins1 = BoardPlayerGet(D_80108EA0_2E0F50_name_44)->coins;
    coins2 = BoardPlayerGet(D_80108EA4_2E0F54_name_44)->coins;
    D_80108EDC_2E0F8C_name_44 = coins1;
    if (coins2 < coins1) {
        D_80108EDC_2E0F8C_name_44 = coins2;
    }
    i++;
    while (D_80108EDC_2E0F8C_name_44 < stakes[i]) {
        if (--i == 0) {
            break;
        }
    }
    D_80108E84_2E0F34_name_44 = D_80108ED0_2E0F80_name_44 = stakes[i];
    x = 0x2F;
    y = 0x2E;
    stake = D_80108ED0_2E0F80_name_44;
    sprintf(mess, "", stake);
    func_8008D974_8E574(mess, 0);
    func_8008DACC_8E6CC(1, size, 0x213);
    win = func_80105584_2DD634_name_44(24, 72, size[0], size[1], 0, 0, 200);
    func_80089308_89F08(win, mess, 0);
    func_8008AD44_8B944(win);
    func_800890CC_89CCC(win, 0x213, -1, -1);
    HuPrcVSleep();
    func_80089284_89E84(win, 0x10004, 0x10004);
    PD_STAKE_SHOW(win, stake);
    func_80057730_58330(win, D_80108EA0_2E0F50_name_44);
    AdjustPlayerCoins(D_80108EA0_2E0F50_name_44, -D_80108E84_2E0F34_name_44);
    AdjustPlayerCoins(D_80108EA4_2E0F54_name_44, -D_80108E84_2E0F34_name_44);
    func_80089284_89E84(win, 4, 4);
    if (gPlayers[D_80108EA0_2E0F50_name_44].flags & 1) {
        func_80107208_2DF2B8_name_44(D_80108E84_2E0F34_name_44, D_80108EDC_2E0F8C_name_44, 3);
    }
    while (TRUE) {
        D_80108E84_2E0F34_name_44 = stake;
        btn = ContDStkTrg[gPlayers[D_80108EA0_2E0F50_name_44].port];
        if (gPlayers[D_80108EA0_2E0F50_name_44].flags & 1) {
            btn = func_801079D8_2DFA88_name_44();
        }
        if (btn & 0x8000) {
            PlaySound(2);
            D_800F851A_F911A = 0;
            func_8008CCA8_8D8A8(win);
            D_80108E80_2E0F30_name_44 = 1;
            omDelPrcObj(NULL);
        } else if (btn & 0x800) {
            if (gPlayers[D_80108EA0_2E0F50_name_44].coins > 0 && gPlayers[D_80108EA4_2E0F54_name_44].coins > 0) {
                if (++stake >= 1000) {
                    stake = 999;
                } else {
                    PlaySound(0x37B);
                }
                PD_STAKE_SHOW(win, stake);
                AdjustPlayerCoins(D_80108EA0_2E0F50_name_44, -1);
                AdjustPlayerCoins(D_80108EA4_2E0F54_name_44, -1);
            }
        } else if (btn & 0x400) {
            if (D_80108ED0_2E0F80_name_44 < stake) {
                stake--;
                PlaySound(0x37C);
                PD_STAKE_SHOW(win, stake);
                AdjustPlayerCoins(D_80108EA0_2E0F50_name_44, 1);
                AdjustPlayerCoins(D_80108EA4_2E0F54_name_44, 1);
            }
        } else if (btn & 0x200) {
            if (stake - 10 >= D_80108ED0_2E0F80_name_44) {
                stake -= 10;
                PlaySound(0x37C);
                PD_STAKE_SHOW(win, stake);
                AdjustPlayerCoins(D_80108EA0_2E0F50_name_44, 10);
                AdjustPlayerCoins(D_80108EA4_2E0F54_name_44, 10);
            }
        } else if (btn & 0x100) {
            if (gPlayers[D_80108EA0_2E0F50_name_44].coins >= 10 && gPlayers[D_80108EA4_2E0F54_name_44].coins >= 10) {
                stake += 10;
                if (stake >= 1000) {
                    stake = 999;
                } else {
                    PlaySound(0x37B);
                }
                PD_STAKE_SHOW(win, stake);
                AdjustPlayerCoins(D_80108EA0_2E0F50_name_44, -10);
                AdjustPlayerCoins(D_80108EA4_2E0F54_name_44, -10);
            }
        }
        HuPrcVSleep();
    }
}

/* The CPU duelists' answers: a copy of the sequence with 16 - skill wrong moves in it (easy 3-7 right,
   normal 6-10, hard 10-14, hardest 12-15), answered by func_80106C24 on the beat. */
/* NON_MATCHING: masked 38, registers only: retail keeps the constant 1 in fp (the wrong flag, case 1)
   and not 0xCCCCCCCD (rand8() % 5); GCC hoists the other one, and the work/count registers swap. */
#ifdef NON_MATCHING
void func_801068CC_2DE97C_name_44(void) {
    omObjData* obj;
    D44CpuWork* work;
    s32 player;
    s32 errors;
    s32 side;
    s32 i;
    s32 j;

    obj = omAddObj(0x10, 0, 0, -1, func_80106C24_2DECD4_name_44);
    work = obj->unk_50 = func_80027154_27D54(sizeof(D44CpuWork), 0x7918);
    errors = 0;
    D_80108FC4_2E1074_name_44 = obj;
    for (side = 0; side < 2; side++) {
        if (side == 0) {
            player = D_80108EA0_2E0F50_name_44;
        } else {
            player = D_80108EA4_2E0F54_name_44;
        }
        if (gPlayers[player].flags & 1) {
            switch (gPlayers[player].cpu_difficulty) {
                case 0:
                    errors = (u8)(rand8() % 5) + 3;
                    break;
                case 1:
                    errors = (u8)(rand8() % 5) + 6;
                    break;
                case 2:
                    errors = (u8)(rand8() % 5) + 10;
                    break;
                case 3:
                    errors = (rand8() & 3) + 12;
                    break;
            }
            errors = 16 - errors;
            for (i = 0; i < 16; i++) {
                work->wrong[side * 16 + i] = 0;
                work->moves[side * 16 + i] = D_80108F00_2E0FB0_name_44[i];
            }
            for (i = 0; i < errors; i++) {
                do {
                    j = rand8() & 0xF;
                } while (work->wrong[side * 16 + j] != 0);
                if (work->moves[side * 16 + j] == D_80108F00_2E0FB0_name_44[j]) {
                    do {
                        work->moves[side * 16 + j] = (u8)(rand8() % 3);
                        work->wrong[side * 16 + j] = 1;
                    } while (work->moves[side * 16 + j] == D_80108F00_2E0FB0_name_44[j]);
                }
            }
            work->idx[side] = -1;
            work->wait[0] = 4;
            for (i = 1; i < 16; i++) {
                work->wait[i] = D_80108AE8_2E0B98_name_44[i] + 5;
            }
            work->timer[side] = 4;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_44_name/2DA8B0", func_801068CC_2DE97C_name_44);
#endif

/* The duelists' answers: A, B and Z are moves 0, 1, 2 for a person; a CPU answers its next move
   when its timer runs out. */
void func_80106C24_2DECD4_name_44(omObjData* obj) {
    D44CpuWork* work = obj->unk_50;

    if (!(gPlayers[D_80108EA0_2E0F50_name_44].flags & 1)) {
        if (ContBtnTrg[gPlayers[D_80108EA0_2E0F50_name_44].port] == 0x8000) {
            func_80107BF4_2DFCA4_name_44(0, 0, D_80108EA0_2E0F50_name_44, D_80108F58_2E1008_name_44 == 0);
        }
        if (ContBtnTrg[gPlayers[D_80108EA0_2E0F50_name_44].port] == 0x4000) {
            func_80107BF4_2DFCA4_name_44(1, 0, D_80108EA0_2E0F50_name_44, D_80108F58_2E1008_name_44 == 1);
        }
        if (ContBtnTrg[gPlayers[D_80108EA0_2E0F50_name_44].port] == 0x2000) {
            func_80107BF4_2DFCA4_name_44(2, 0, D_80108EA0_2E0F50_name_44, D_80108F58_2E1008_name_44 == 2);
        }
    } else if (work->timer[0] != 0 && --work->timer[0] == 0) {
        func_80107BF4_2DFCA4_name_44(work->moves[work->idx[0]], 0, D_80108EA0_2E0F50_name_44,
                                     work->moves[work->idx[0]] == D_80108F58_2E1008_name_44);
    }
    if (!(gPlayers[D_80108EA4_2E0F54_name_44].flags & 1)) {
        if (ContBtnTrg[gPlayers[D_80108EA4_2E0F54_name_44].port] == 0x8000) {
            func_80107BF4_2DFCA4_name_44(0, 1, D_80108EA4_2E0F54_name_44, D_80108F58_2E1008_name_44 == 0);
        }
        if (ContBtnTrg[gPlayers[D_80108EA4_2E0F54_name_44].port] == 0x4000) {
            func_80107BF4_2DFCA4_name_44(1, 1, D_80108EA4_2E0F54_name_44, D_80108F58_2E1008_name_44 == 1);
        }
        if (ContBtnTrg[gPlayers[D_80108EA4_2E0F54_name_44].port] == 0x2000) {
            func_80107BF4_2DFCA4_name_44(2, 1, D_80108EA4_2E0F54_name_44, D_80108F58_2E1008_name_44 == 2);
        }
    } else if (work->timer[1] != 0 && --work->timer[1] == 0) {
        func_80107BF4_2DFCA4_name_44(work->moves[work->idx[1] + 16], 1, D_80108EA4_2E0F54_name_44,
                                     work->moves[work->idx[1] + 16] == D_80108F58_2E1008_name_44);
    }
}

s32 func_80106F1C_2DEFCC_name_44(void) {
    s32 cand[4];
    s32 n;
    s32 i;

    n = 0;
    for (i = 0; i < D_80108EB8_2E0F68_name_44 - 1; i++) {
        if (func_80059FD0_5ABD0(D_80108EC0_2E0F70_name_44[i]) == 0 && gPlayers[D_80108EC0_2E0F70_name_44[i]].coins > 0) {
            cand[n++] = i;
        }
    }
    if (n == 0) {
        for (i = 0; i < D_80108EB8_2E0F68_name_44 - 1; i++) {
            if (func_80059FD0_5ABD0(D_80108EC0_2E0F70_name_44[i]) == 1 && gPlayers[D_80108EC0_2E0F70_name_44[i]].coins > 0) {
                cand[n++] = i;
            }
        }
    }
    if (n == 0) {
        for (i = 0; i < D_80108EB8_2E0F68_name_44 - 1; i++) {
            if (func_80059FD0_5ABD0(D_80108EC0_2E0F70_name_44[i]) == 2 && gPlayers[D_80108EC0_2E0F70_name_44[i]].coins > 0) {
                cand[n++] = i;
            }
        }
    }
    if (n == 0) {
        for (i = 0; i < D_80108EB8_2E0F68_name_44 - 1; i++) {
            if (func_80059FD0_5ABD0(D_80108EC0_2E0F70_name_44[i]) == 3 && gPlayers[D_80108EC0_2E0F70_name_44[i]].coins > 0) {
                cand[n++] = i;
            }
        }
    }
    return cand[rand8() % n];
}

#define PD_ABS(x) ((x) < 0 ? -(x) : (x))
#ifdef NON_MATCHING
void func_80107208_2DF2B8_name_44(s32 cur, s32 target, s32 mode) {
    s32 cand[4];
    s32 flag[4];
    s32 rows[32] = {
        -1, 1, 3, 2, 3, 3, 3, 3,
        0, 1, -1, 1, 1, 2, 1, 2,
        0, 1, 0, 1, -1, 1, 1, 2,
        0, 0, 0, 1, 0, 1, -1, -1,
    };
    s32 range[4] = { 10, 20, 20, 9 };
    s32 base[4] = { 90, 60, 20, 1 };
    s32 unused[8];
    omObjData* obj;
    PdCpuInput* work;
    s32 diff;
    s32 row;
    s32 n;
    s32 i;

    obj = omAddObj(0x10, 0, 0, -1, func_80107838_2DF8E8_name_44);
    work = obj->unk_50 = func_80027154_27D54(sizeof(PdCpuInput), 0x7918);
    work->timer = 0;
    work->cur = cur;
    work->target = target;
    work->mode = mode;
    D_80108EE8_2E0F98_name_44 = 0;
    if (mode == 2) {
        if (gPlayers[D_80108EA0_2E0F50_name_44].coins >= 20) {
            n = 0;
            for (i = 0; i < D_80108EB8_2E0F68_name_44 - 1; i++) {
                flag[i] = 0;
            }
            for (i = 0; i < D_80108EB8_2E0F68_name_44 - 1; i++) {
                if (func_80059FD0_5ABD0(D_80108EC0_2E0F70_name_44[i]) == 0) {
                    flag[i] = 1;
                    n++;
                }
            }
            if (n == 0) {
                for (i = 0; i < D_80108EB8_2E0F68_name_44 - 1; i++) {
                    if (func_80059FD0_5ABD0(D_80108EC0_2E0F70_name_44[i]) == 1) {
                        flag[i] = 1;
                        n++;
                    }
                }
            }
            if (n == 0) {
                for (i = 0; i < D_80108EB8_2E0F68_name_44 - 1; i++) {
                    if (func_80059FD0_5ABD0(D_80108EC0_2E0F70_name_44[i]) == 2) {
                        flag[i] = 1;
                        n++;
                    }
                }
            }
            if (n == 0) {
                for (i = 0; i < D_80108EB8_2E0F68_name_44 - 1; i++) {
                    if (func_80059FD0_5ABD0(D_80108EC0_2E0F70_name_44[i]) == 3) {
                        flag[i] = 1;
                        n++;
                    }
                }
            }
            n = 0;
            for (i = 0; i < D_80108EB8_2E0F68_name_44 - 1; i++) {
                if (flag[i] != 0 && gPlayers[D_80108EC0_2E0F70_name_44[i]].coins >= 20) {
                    cand[n++] = i;
                }
            }
            if (n == 0) {
                for (i = 0; i < D_80108EB8_2E0F68_name_44 - 1; i++) {
                    if (flag[i] == 0 && gPlayers[D_80108EC0_2E0F70_name_44[i]].coins >= 20) {
                        cand[n++] = i;
                    }
                }
            }
            if (n > 0) {
                work->target = cand[rand8() % n];
            } else {
                work->target = func_80106F1C_2DEFCC_name_44();
            }
        } else {
            work->target = func_80106F1C_2DEFCC_name_44();
        }
    }
    if (mode == 3) {
        row = func_80059FD0_5ABD0(D_80108EA0_2E0F50_name_44) * 8;
        row += func_80059FD0_5ABD0(D_80108EA0_2E0F50_name_44) * 2;
        diff = PD_ABS(gPlayers[D_80108EA0_2E0F50_name_44].stars - gPlayers[D_80108EA4_2E0F54_name_44].stars);
        row += diff < 2;
        work->target = (rand8() % range[rows[row]] + base[rows[row]]) * D_80108EDC_2E0F8C_name_44 / 100;
        if (work->target < D_80108ED0_2E0F80_name_44) {
            work->target = D_80108ED0_2E0F80_name_44;
        }
    }
}
#else
__asm__(".section .rodata");
const u32 D_80108D38_2E0DE8_name_44[32] = { 0xFFFFFFFF, 0x00000001, 0x00000003, 0x00000002, 0x00000003, 0x00000003, 0x00000003, 0x00000003, 0x00000000, 0x00000001, 0xFFFFFFFF, 0x00000001, 0x00000001, 0x00000002, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000001, 0xFFFFFFFF, 0x00000001, 0x00000001, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000001, 0xFFFFFFFF, 0xFFFFFFFF };

const u32 D_80108DB8_2E0E68_name_44[4] = { 0x0000000A, 0x00000014, 0x00000014, 0x00000009 };

const u32 D_80108DC8_2E0E78_name_44[4] = { 0x0000005A, 0x0000003C, 0x00000014, 0x00000001 };
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_44_name/2DA8B0", func_80107208_2DF2B8_name_44);
#endif

void func_80107838_2DF8E8_name_44(omObjData* obj) {
    PdCpuInput* work = obj->unk_50;

    D_80108EE8_2E0F98_name_44 = 0;
    if (++work->timer >= 10) {
        switch (work->mode) {
            case 0:
                if (work->timer >= 30) {
                    D_80108EE8_2E0F98_name_44 = 0x1000;
                    omDelObj(obj);
                }
                break;
            case 1:
                if (work->timer >= 30) {
                    D_80108EE8_2E0F98_name_44 = 0x8000;
                    omDelObj(obj);
                }
                break;
            case 2:
                if (work->cur == work->target) {
                    D_80108EE8_2E0F98_name_44 = 0x8000;
                    omDelObj(obj);
                } else if (work->cur < work->target) {
                    D_80108EE8_2E0F98_name_44 = 0x400;
                    work->cur++;
                    work->timer = 0;
                } else if (work->cur > work->target) {
                    D_80108EE8_2E0F98_name_44 = 0x800;
                    work->cur--;
                    work->timer = 0;
                }
                break;
            case 3:
                work->cur = D_80108E84_2E0F34_name_44;
                if (work->cur == work->target) {
                    D_80108EE8_2E0F98_name_44 = 0x8000;
                    omDelObj(obj);
                } else if (work->cur - work->target >= 10) {
                    D_80108EE8_2E0F98_name_44 = 0x200;
                    work->timer = 0;
                } else if (work->cur - work->target < -9) {
                    D_80108EE8_2E0F98_name_44 = 0x100;
                    work->timer = 0;
                } else if (work->cur - work->target < 10) {
                    D_80108EE8_2E0F98_name_44 = 0x800;
                    work->timer = 0;
                } else if (work->cur - work->target >= -9) {
                    D_80108EE8_2E0F98_name_44 = 0x400;
                    work->timer = 0;
                }
                break;
        }
    }
}

s32 func_801079D8_2DFA88_name_44(void) {
    return D_80108EE8_2E0F98_name_44;
}

/* Deals the 16-move sequence (0..2 each): never three alike in a row. */
void func_801079E4_2DFA94_name_44(void) {
    s32 run;
    s32 i;
    s32 move;
    s32 ok;

    run = 0;
    for (i = 0; i < 16; i++) {
        do {
            move = (u8)(rand8() % 3);
            ok = TRUE;
            if (i > 0 && move == D_80108F00_2E0FB0_name_44[i - 1]) {
                if (++run == 3) {
                    run = 2;
                    ok = FALSE;
                }
                if (i >= 4 && D_80108F00_2E0FB0_name_44[i - 3] == D_80108F00_2E0FB0_name_44[i - 2]) {
                    run--;
                    ok = FALSE;
                }
            } else {
                run = 1;
            }
        } while (!ok);
        D_80108F00_2E0FB0_name_44[i] = move;
    }
}

/* Shows the sequence: each move's sprite in the middle for its beat (D_80108AE8[i + 1] frames). */
void func_80107B1C_2DFBCC_name_44(void) {
    s32* spr;
    s32 move;
    s32 i;

    for (i = 0; i < 16; i++) {
        func_8010838C_2E043C_name_44();
        move = D_80108F58_2E1008_name_44 = D_80108F00_2E0FB0_name_44[i];
        spr = &D_80108F4C_2E0FFC_name_44[move];
        espPosSet(*spr, 160, 80);
        espDispOn(*spr);
        HuPrcSleep(D_80108AE8_2E0B98_name_44[i + 1]);
        espDispOff(*spr);
        HuPrcSleep(5);
    }
    D_80108E80_2E0F30_name_44 = 1;
    omDelPrcObj(NULL);
}

/* A duelist answers a move: the swing motion and an answer object (func_80107F28) at a
   per-character spot beside the model; ignored while the side's last answer is showing. */
void func_80107BF4_2DFCA4_name_44(s32 move, s32 side, s32 player, s32 correct) {
    Vec2f screen;
    Vec pos;
    f32 xs[12] = {
        40.0f, 40.0f, 25.0f, 45.0f, 50.0f, 40.0f,
        80.0f, 80.0f, 5.0f, 95.0f, 100.0f, 110.0f,
    }; /* [side * 6 + character] */
    f32 ys[12] = {
        110.0f, 120.0f, 110.0f, 110.0f, 110.0f, 95.0f,
        110.0f, 120.0f, 110.0f, 110.0f, 110.0f, 95.0f,
    };
    f32 zs[6] = { -100.0f, -65.0f, -65.0f, -88.0f, -110.0f, -115.0f };
    omObjData* obj;
    D44AnswerWork* work;

    if (D_80109018_2E10C8_name_44[side] == 0) {
        obj = omAddObj(0x10, 0, 0, -1, func_80107F28_2DFFD8_name_44);
        obj->unk_50 = func_80027154_27D54(sizeof(D44AnswerWork), 0x7918);
        D_80108FC8_2E1078_name_44[side] = obj;
        work = obj->unk_50;
        work->timer = 0;
        work->move = move;
        work->side = side;
        work->y = 250.0f;
        work->vel = 30.0f;
        work->player = player;
        D_80109018_2E10C8_name_44[side] = 1;
        MBMotionSet(PLAYER_MODEL(player), 2, 0);
        func_80029FE4_2ABE4(*PLAYER_MODEL(player)->obj->model, 6.0f);
        PlaySound(0x3EA);
        work->flags = 0;
        work->scale = 1.0f;
        work->alpha = 255.0f;
        work->correct = correct;
        D_80109020_2E10D0_name_44[side].x = PLAYER_MODEL(player)->pos.x + xs[side * 6 + gPlayers[player].character];
        D_80109020_2E10D0_name_44[side].y = PLAYER_MODEL(player)->pos.y + ys[side * 6 + gPlayers[player].character];
        D_80109020_2E10D0_name_44[side].z = PLAYER_MODEL(player)->pos.z + zs[gPlayers[player].character];
        pos.x = D_80109020_2E10D0_name_44[side].x;
        pos.y = D_80109020_2E10D0_name_44[side].y;
        pos.z = D_80109020_2E10D0_name_44[side].z;
        Hu3DCam3DToScreen(0, &pos, &screen);
        work->sx = screen.unk_00;
        work->sy = screen.unk_04;
    }
}

/* An answer: at frame 6 its sprite pops beside the duelist (and func_801085BC's), at 10 the move's
   model appears with a sound and the answer is scored (D_80108FB8), 11-17 the model swells, from 18
   it drops until it lands; gone at 23. */
void func_80107F28_2DFFD8_name_44(omObjData* obj) {
    D44AnswerWork* work = obj->unk_50;
    f32 scale;

    if (++work->timer == 6) {
        espPosSet(D_80108F60_2E1010_name_44[work->side], work->sx - 10, work->sy - 10);
        espDispOn(D_80108F60_2E1010_name_44[work->side]);
        func_8001A854_1B454(D_80108F60_2E1010_name_44[work->side], 0, 0);
        func_801085BC_2E066C_name_44(work->side, work->y);
    }
    if (work->timer == 12) {
        espDispOff(D_80108F60_2E1010_name_44[work->side]);
    }
    if (work->timer == 10) {
        func_800298A4_2A4A4(D_80109000_2E10B0_name_44[work->move * 2 + work->side], 4, 0);
        D_800FC834_FD434[D_80109000_2E10B0_name_44[work->move * 2 + work->side]].pos.y = work->y;
        work->scale = 1.0f;
        func_800297E8_2A3E8(D_80109000_2E10B0_name_44[work->move * 2 + work->side], 0.0f, 0.0f, 0.0f);
        MBMotionShiftSet(PLAYER_MODEL(work->player), 1, 0, 5, 2);
        func_80029FE4_2ABE4(*PLAYER_MODEL(work->player)->obj->model, 1.0f);
        func_8007975C_7A35C(0x3D5, work->player);
        if (work->move == D_80108F58_2E1008_name_44) {
            D_80108FB8_2E1068_name_44[work->side]++;
            work->correct = TRUE;
        } else {
            work->correct = FALSE;
        }
    }
    if (work->timer >= 11 && work->timer < 18) {
        scale = work->scale = HuMathSin((work->timer - 11) * 270.0f / 6.0f + -90.0f) + 1.0f;
        func_800297E8_2A3E8(D_80109000_2E10B0_name_44[work->move * 2 + work->side], scale, scale, scale);
        D_800FC834_FD434[D_80109000_2E10B0_name_44[work->move * 2 + work->side]].pos.y = work->y;
    }
    if (work->timer >= 18 && !(work->flags & 1)) {
        D_800FC834_FD434[D_80109000_2E10B0_name_44[work->move * 2 + work->side]].pos.y = work->y;
        work->y -= work->vel;
        work->vel += 2.0f;
        if (work->y <= 100.0f) {
            work->flags |= 1;
            D_80109018_2E10C8_name_44[work->side] = 0;
            func_800298A4_2A4A4(D_80109000_2E10B0_name_44[work->move * 2 + work->side], 4, 4);
        }
    }
    if (work->timer == 23) {
        D_80108FC8_2E1078_name_44[work->side] = NULL;
        omDelObj(obj);
    }
}

/* NON_MATCHING: masked 5, registers only: retail gives the side s2 and &D_80108FC8[side] s3, GCC
   swaps them. */
#ifdef NON_MATCHING
/* A new beat: clears both sides' last answers (motion back, sprites off, models reset) and
   moves the CPU answers on. */
void func_8010838C_2E043C_name_44(void) {
    s32 players[2] = { D_80108EA0_2E0F50_name_44, D_80108EA4_2E0F54_name_44 };
    D44CpuWork* cpu;
    s32 i;
    s32 side;

    cpu = D_80108FC4_2E1074_name_44->unk_50;
    for (side = 0; side < 2; side++) {
        if (D_80108FC8_2E1078_name_44[side] != NULL) {
            D_80109018_2E10C8_name_44[side] = 0;
            MBMotionShiftSet(PLAYER_MODEL(players[side]), 1, 0, 5, 2);
            func_80029FE4_2ABE4(*PLAYER_MODEL(players[side])->obj->model, 1.0f);
            omDelObj(D_80108FC8_2E1078_name_44[side]);
            D_80108FC8_2E1078_name_44[side] = NULL;
            if (D_80108FD0_2E1080_name_44[side] != NULL) {
                D_80108FD8_2E1088_name_44[side] = 1;
                espDispOff(D_80108F70_2E1020_name_44[side]);
            }
            espDispOff(D_80108F60_2E1010_name_44[side]);
            for (i = 0; i < 3; i++) {
                func_800298A4_2A4A4(D_80109000_2E10B0_name_44[i * 2 + side], 4, 4);
                func_800297E8_2A3E8(D_80109000_2E10B0_name_44[i * 2 + side], 1.0f, 1.0f, 1.0f);
                D_800FC834_FD434[D_80109000_2E10B0_name_44[i * 2 + side]].pos.y = 0.0f;
            }
        }
        cpu->idx[side]++;
        cpu->timer[side] = 4;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_44_name/2DA8B0", func_8010838C_2E043C_name_44);
#endif

/* The answer's side sprite (func_80108750), placed on screen from D_80108B98[side] at height y. */
void func_801085BC_2E066C_name_44(s32 side, f32 height) {
    Vec pos;
    Vec2f screen;
    s32 dx[5] = { 0, 0, -16, 0, 0 };
    s32 dy[5] = { 0, 16, 0, -16, 0 };
    omObjData* obj;
    D44SprWork* work;
    s32 x;
    s32 y;

    if (D_80108FD0_2E1080_name_44[side] != NULL) {
        omDelObj(D_80108FD0_2E1080_name_44[side]);
    }
    obj = omAddObj(0x10, 0, 0, -1, func_80108750_2E0800_name_44);
    obj->unk_50 = func_80027154_27D54(sizeof(D44SprWork), 0x7918);
    D_80108FD0_2E1080_name_44[side] = obj;
    work = obj->unk_50;
    pos.x = D_80108B98_2E0C48_name_44[side].x;
    pos.y = height;
    pos.z = D_80108B98_2E0C48_name_44[side].z;
    Hu3DCam3DToScreen(0, &pos, &screen);
    x = (s32)screen.unk_00 + dx[0];
    y = (s32)screen.unk_04 + dy[0];
    espPosSet(D_80108F70_2E1020_name_44[side], x, y);
    work->timer = 0;
    work->side = side;
}

void func_80108750_2E0800_name_44(omObjData* obj) {
    D44SprWork* work = obj->unk_50;

    if (work->timer == 0) {
        espDispOn(D_80108F70_2E1020_name_44[work->side]);
        func_8001A854_1B454(D_80108F70_2E1020_name_44[work->side], 0, 0);
        func_8001A89C_1B49C(D_80108F70_2E1020_name_44[work->side], 1);
    }
    if (work->timer == 11) {
        espDispOff(D_80108F70_2E1020_name_44[work->side]);
    }
    if (work->timer == 12 || D_80108FD8_2E1088_name_44[work->side] == 1) {
        D_80108FD0_2E1080_name_44[work->side] = NULL;
        D_80108FD8_2E1088_name_44[work->side] = 0;
        omDelObj(obj);
    }
    work->timer++;
}

void func_80108870_2E0920_name_44(void) {
    omAddObj(0x10, 0, 0, -1, func_801088A4_2E0954_name_44);
}

void func_801088A4_2E0954_name_44(void) {
}

/* Rumbles both duelists' pads every 20 frames until D_80108FE0 is set. */
void func_801088AC_2E095C_name_44(void) {
    while (D_80108FE0_2E1090_name_44 == 0) {
        omVibrate(D_80108EA0_2E0F50_name_44, 10, 0, 10);
        omVibrate(D_80108EA4_2E0F54_name_44, 10, 0, 10);
        HuPrcSleep(20);
    }
    omDelPrcObj(NULL);
}
