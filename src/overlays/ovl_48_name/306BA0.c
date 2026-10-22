#include "common.h"
#include "ovl_48.h"

void func_80102800_306BA0_name_48(void) {
    RectF scissor = D_80108790_30CB30_name_48;

    omInitObjMan(40, 15);
    func_80079128_79D28();
    func_80018E30_19A30(1);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_80050A30_51630(D_01164160);
    CameraScissorSet(0, &scissor);
    MBModelInit();
    func_8005E2B8_5EEB8();
    func_800593C0_59FC0();
    func_800581A0_58DA0();
    func_801029A0_306D40_name_48();
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
    omAddPrcObj(func_80102CB4_307054_name_48, 0x5000, 0x2000, 0);
    omAddObj(1000, 0, 0, -1, func_80102BD4_306F74_name_48);
}

void func_801029A0_306D40_name_48(void) {
    s32 bits;
    s32 i;

    D_80108934_30CCD4_name_48 = -1;
    D_80108928_30CCC8_name_48 = 0;
    D_80108BEC_30CF8C_name_48 = 0;
    if (_CheckFlag(0x17) == 0) {
        D_80108BEC_30CF8C_name_48 = 1;
    }
    bits = D_800F8D1A_F991A.attacker;
    if (_CheckFlag(0x19) != 0) {
        if (ContBtn[0] & 0x8000) {
            bits = 1;
            D_80108BEC_30CF8C_name_48 = 0;
        }
        if (ContBtn[0] & 0x4000) {
            bits = 1;
            D_80108BEC_30CF8C_name_48 = 1;
        }
    }
    D_80108930_30CCD0_name_48 = 0;
    for (i = 0; bits != 0; i++) {
        bits >>= 1;
        if (bits == 0) {
            break;
        }
        D_80108930_30CCD0_name_48++;
    }
    D_80108948_30CCE8_name_48 = 1;
    D_80108938_30CCD8_name_48[i] = 1;
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
            D_80108948_30CCE8_name_48++;
            D_80108938_30CCD8_name_48[i] = 1;
        }
    }
    for (i = 0; i < 2; i++) {
        D_80108980_30CD20_name_48[i] = 0;
    }
    if (D_80108948_30CCE8_name_48 == 2) {
        for (i = 0; i < 4; i++) {
            if (D_80108938_30CCD8_name_48[i] == 1 && i != D_80108930_30CCD0_name_48) {
                D_80108934_30CCD4_name_48 = i;
                break;
            }
        }
    }
    D_800FC880_FD480 = 0;
    D_800F8C5C_F985C = 0;
    D_80108964_30CD04_name_48 = GwSystem.current_turn;
}

void func_80102BD4_306F74_name_48(omObjData* obj) {
    if (D_801011FC_101DFC != 0) {
        MBDBackKill();
        func_80050AE0_516E0();
        func_80059400_5A000();
        func_80069770_6A370();
        func_8008CE5C_8DA5C();
        omOvlReturnEx(1);
    }
}

void func_80102C28_306FC8_name_48(void) {
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
const u32 D_801087B0_30CB50_name_48[3] = { 0x00000002, 0x000800A7, 0x000800AA };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_name/306BA0", func_80102CB4_307054_name_48);

__asm__(".section .rodata");
const char D_801087E8_30CB88_name_48[] = "%c%c";

__asm__(".section .rodata");
const char D_801087F0_30CB90_name_48[] = "%d";

void func_80105354_3096F4_name_48(void) {
    s16 size[2];
    char num[0x100];
    char name[0x100];
    s32 win;
    u16 btn;

    if (D_80108920_30CCC0_name_48 == 1) {
        sprintf(num, D_801087E8_30CB88_name_48, 0x18, gPlayers[D_8010892C_30CCCC_name_48].character);
        func_8008D974_8E574(num, 0);
    }
    if (D_80108920_30CCC0_name_48 == 3) {
        sprintf(num, D_801087F0_30CB90_name_48, D_80108914_30CCB4_name_48);
        sprintf(name, D_801087E8_30CB88_name_48, 0x18, gPlayers[D_8010892C_30CCCC_name_48].character);
        func_8008D974_8E574(name, 0);
        func_8008D974_8E574(num, 1);
        func_8008D974_8E574(name, 2);
    }
    func_8008DACC_8E6CC(1, size, D_80108924_30CCC4_name_48);
    win = func_8010571C_309ABC_name_48((s16)D_80108918_30CCB8_name_48, (s16)D_8010891C_30CCBC_name_48, size[0], size[1], 0, 0, 200);
    if (D_80108928_30CCC8_name_48 & 1) {
        ShowTextWindow((s16)win);
    }
    if (D_80108920_30CCC0_name_48 == 3) {
        func_80089308_89F08(win, name, 0);
        func_80089308_89F08(win, num, 1);
        func_80089308_89F08(win, name, 2);
    }
    func_8008AD44_8B944(win);
    func_800890CC_89CCC(win, D_80108924_30CCC4_name_48, -1, -1);
    func_80057A78_58678((s16)win, D_80108930_30CCD0_name_48, D_80108934_30CCD4_name_48);
    if (D_80108920_30CCC0_name_48 == 2 && (gPlayers[D_80108930_30CCD0_name_48].flags & 1) && (gPlayers[D_80108934_30CCD4_name_48].flags & 1)) {
        func_801077F4_30BB94_name_48(0, 0, 0);
    }
    while (TRUE) {
        switch (D_80108920_30CCC0_name_48) {
            case 0:
            case 1:
            case 3:
                if (D_80108928_30CCC8_name_48 & 1) {
                    func_8005762C_5822C((s16)win);
                } else {
                    func_8008CCA8_8D8A8(win);
                }
                D_80108910_30CCB0_name_48 = 1;
                omDelPrcObj(NULL);
                break;
            case 2:
                if ((gPlayers[D_80108930_30CCD0_name_48].flags & 1) && (gPlayers[D_80108934_30CCD4_name_48].flags & 1)) {
                    btn = func_80107FBC_30C35C_name_48();
                } else {
                    btn = func_80105884_309C24_name_48();
                }
                if (btn & 0x1000) {
                    PlaySound(2);
                    D_80108910_30CCB0_name_48 = 1;
                    func_8008CCA8_8D8A8(win);
                    omDelPrcObj(NULL);
                }
                break;
        }
        HuPrcVSleep();
    }
}

#ifdef NON_MATCHING
s32 func_8010571C_309ABC_name_48(s16 x, s16 y, s16 w, s16 h, s16 arg4, s16 arg5, s32 arg6) {
    s32 win;
    s16 mask;

    win = func_800888A8_894A8(x, y, w, h, arg4, arg5);
    func_80089284_89E84(win, 0x40, 0x40);
    func_80089A48_8A648(win, 0);
    func_8008D88C_8E48C(win);
    func_80089B2C_8A72C(win, arg6);
    if (D_80108934_30CCD4_name_48 != -1) {
        mask = (1 << gPlayers[D_80108930_30CCD0_name_48].port) | (1 << gPlayers[D_80108934_30CCD4_name_48].port);
    } else {
        mask = 1 << gPlayers[D_80108930_30CCD0_name_48].port;
    }
    func_8008D59C_8E19C(win, mask);
    return (s16)win;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_name/306BA0", func_8010571C_309ABC_name_48);
#endif

u16 func_80105884_309C24_name_48(void) {
    u16 btn;

    btn = 0;
    if (!(gPlayers[D_80108930_30CCD0_name_48].flags & 1)) {
        btn = ContDStkTrg[gPlayers[D_80108930_30CCD0_name_48].port];
    }
    if (D_80108934_30CCD4_name_48 != -1 && btn == 0) {
        if (!(gPlayers[D_80108934_30CCD4_name_48].flags & 1)) {
            btn = ContDStkTrg[gPlayers[D_80108934_30CCD4_name_48].port];
        }
    }
    return btn;
}

void func_80105944_309CE4_name_48(s32 layout) {
    omObjData* obj;
    s32* work;
    BoardStatus* status;
    s32 slot;
    s32 i;
    s32 next;

    D_80108910_30CCB0_name_48 = 0;
    obj = omAddObj(0x12, 0, 0, -1, func_80105C7C_30A01C_name_48);
    work = func_80027154_27D54(44, 0x7918);
    obj->unk_50 = work;
    *work = layout;
    next = 0;
    for (i = 0; i < 4; i++) {
        if (D_80108938_30CCD8_name_48[i] != 0) {
            status = &D_80101510_102110[i];
            slot = 3;
            if (i != D_80108930_30CCD0_name_48) {
                if (i == D_80108934_30CCD4_name_48) {
                    slot = 2;
                } else {
                    slot = next;
                    D_80108950_30CCF0_name_48[slot] = i;
                    next = slot + 1;
                }
            }
            if (D_801084D0_30C870_name_48[layout].pos[slot][0] != -1) {
                status->xPos = D_801084D0_30C870_name_48[layout].pos[slot][0];
            }
            if (D_801084D0_30C870_name_48[layout].pos[slot][1] != -1) {
                status->yPos = D_801084D0_30C870_name_48[layout].pos[slot][1];
            }
            func_800600F8_60CF8(i, status->xPos, status->yPos);
            status->unk_0C = D_801084D0_30C870_name_48[layout].frames - 1;
            if (D_801084D0_30C870_name_48[layout].pos[slot][2] != -1) {
                status->unk_18 = D_801084D0_30C870_name_48[layout].pos[slot][2];
            }
            if (D_801084D0_30C870_name_48[layout].pos[slot][3] != -1) {
                status->unk_1C = D_801084D0_30C870_name_48[layout].pos[slot][3];
            }
            status->unk_20 = status->unk_28 = 2.0f * (status->unk_18 - status->xPos) / ((status->unk_0C + 1) * (status->unk_0C + 1));
            status->unk_24 = status->unk_2C = 2.0f * (status->unk_1C - status->yPos) / ((status->unk_0C + 1) * (status->unk_0C + 1));
        }
    }
    if (D_801086C8_30CA68_name_48 == 1) {
        status = &D_80101510_102110[D_80108930_30CCD0_name_48];
        D_800FD854_FE454[0].unk_00 = D_800FC990_FD590[0].unk_00 = status->unk_28;
        D_800FD854_FE454[0].unk_04 = D_800FC990_FD590[0].unk_04 = status->unk_2C;
        D_800FA604_FB204 = D_801084D0_30C870_name_48[layout].frames - 1;
    }
}

void func_80105C7C_30A01C_name_48(omObjData* obj) {
    BoardStatus* status;
    s32 done;
    s32 i;

    done = 0;
    for (i = 0; i < 4; i++) {
        if (D_80108938_30CCD8_name_48[i] != 0) {
            status = &D_80101510_102110[i];
            if (status->unk_0C == 0) {
                status->xPos = status->unk_18;
                status->yPos = status->unk_1C;
                done++;
            }
        }
    }
    if (done == D_80108948_30CCE8_name_48) {
        D_80108910_30CCB0_name_48 = 1;
        omDelObj(obj);
    }
}

void func_80105D14_30A0B4_name_48(void) {
    omAddObj(0x10, 0, 0, -1, func_80105D50_30A0F0_name_48);
    func_80069764_6A364(60);
}

void func_80105D50_30A0F0_name_48(omObjData* obj) {
    if (func_800696E4_6A2E4() == 0) {
        InitFadeOut(0, 20);
        if (D_80108BEC_30CF8C_name_48 != 0) {
            func_80079614_7A214(20);
        }
        obj->func_ptr = func_80105DA8_30A148_name_48;
    }
}

void func_80105DA8_30A148_name_48(omObjData* obj) {
    if (func_8008F618_90218() == 0) {
        MBDBackKill();
        func_80050AE0_516E0();
        func_80059400_5A000();
        func_80069770_6A370();
        func_8008CE5C_8DA5C();
        omOvlReturnEx(1);
    }
}

void func_80105DFC_30A19C_name_48(void) {
    omObjData* obj;
    PdShrink* work;

    obj = omAddObj(0x10, 0, 0, -1, func_80105E8C_30A22C_name_48);
    work = func_80027154_27D54(sizeof(PdShrink), 0x7918);
    obj->unk_50 = work;
    work->scaleSpeed = -0.06666667f;
    work->rotSpeed = -3.0f;
    work->unk10 = 0;
    work->unkC = 1.0f;
    work->timer = 15;
}

void func_80105E8C_30A22C_name_48(omObjData* obj) {
    PdShrink* work = obj->unk_50;

    D_80108BF4_30CF94_name_48->scale.x += work->scaleSpeed;
    D_80108BF4_30CF94_name_48->scale.y += work->scaleSpeed;
    D_80108BF4_30CF94_name_48->scale.z += work->scaleSpeed;
    D_80108BF4_30CF94_name_48->obj->rot.x += work->rotSpeed;
    if (--work->timer == 0) {
        MBModelDispOff(D_80108BF4_30CF94_name_48);
        omDelObj(obj);
    }
}

void func_80105F1C_30A2BC_name_48(void) {
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
    win = func_8010571C_309ABC_name_48(70, 178, size[0], size[1], 0, 0, 200);
    func_8008AD44_8B944(win);
    func_800890CC_89CCC(win, 0x212, -1, -1);
    sel = 0;
    count = D_80108948_30CCE8_name_48 - 1;
    if (D_80108948_30CCE8_name_48 == 4) {
        src = ys4;
    } else {
        src = ys3;
    }
    for (i = 0; i < D_80108948_30CCE8_name_48; i++) {
        ys[i] = *src++;
    }
    spr = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x42), 1, 1);
    espDispOn(spr);
    if (gPlayers[D_80108930_30CCD0_name_48].flags & 1) {
        func_801077F4_30BB94_name_48(sel, 0, 2);
    }
    while (TRUE) {
        btn = func_80105884_309C24_name_48();
        if (gPlayers[D_80108930_30CCD0_name_48].flags & 1) {
            btn = func_80107FBC_30C35C_name_48();
        }
        if ((btn & 0x8000) && BoardSpaceGet(D_80108950_30CCF0_name_48[sel], 1) != 0) {
            PlaySound(2);
            D_80108910_30CCB0_name_48 = 1;
            D_80108934_30CCD4_name_48 = D_80108950_30CCF0_name_48[sel];
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

/* The stake (as 42's func_80105A80 and 3F's func_80105054): the starting amount comes from the
   turn (turns[] bands) and the poorer player's coins (stakes[]); right/left add or take 1, up/down
   10, A accepts. Both duelists pay the stake as it changes. Retail quirk: at the 999 cap a further
   raise still takes the coin from both players. */
#define PD_STAKE_SHOW(win, stake)                                           \
    sprintf(num, D_801087F0_30CB90_name_48, stake);                         \
    len = func_800A5610_A6210(num);                                         \
    for (j = 0; j < 3 - len; j++) {                                         \
        pad[j] = 0x1A;                                                      \
    }                                                                       \
    pad[j] = 0;                                                             \
    sprintf(buf, "%c%c%s%d", 0xF, 6, pad, stake);                           \
    func_800890CC_89CCC(win, (s32)buf, x, y)

void func_801061E8_30A588_name_48(void) {
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

    turn = D_80108964_30CD04_name_48;
    i = 0;
    while (turn >= turns[i]) {
        if (++i == 4) {
            break;
        }
    }
    coins1 = BoardPlayerGet(D_80108930_30CCD0_name_48)->coins;
    coins2 = BoardPlayerGet(D_80108934_30CCD4_name_48)->coins;
    D_8010896C_30CD0C_name_48 = coins1;
    if (coins2 < coins1) {
        D_8010896C_30CD0C_name_48 = coins2;
    }
    i++;
    while (D_8010896C_30CD0C_name_48 < stakes[i]) {
        if (--i == 0) {
            break;
        }
    }
    D_80108914_30CCB4_name_48 = D_80108960_30CD00_name_48 = stakes[i];
    x = 0x2F;
    y = 0x2E;
    stake = D_80108960_30CD00_name_48;
    sprintf(mess, "", stake);
    func_8008D974_8E574(mess, 0);
    func_8008DACC_8E6CC(1, size, 0x213);
    win = func_8010571C_309ABC_name_48(24, 72, size[0], size[1], 0, 0, 200);
    func_80089308_89F08(win, mess, 0);
    func_8008AD44_8B944(win);
    func_800890CC_89CCC(win, 0x213, -1, -1);
    HuPrcVSleep();
    func_80089284_89E84(win, 0x10004, 0x10004);
    PD_STAKE_SHOW(win, stake);
    func_80057730_58330(win, D_80108930_30CCD0_name_48);
    AdjustPlayerCoins(D_80108930_30CCD0_name_48, -D_80108914_30CCB4_name_48);
    AdjustPlayerCoins(D_80108934_30CCD4_name_48, -D_80108914_30CCB4_name_48);
    func_80089284_89E84(win, 4, 4);
    if (gPlayers[D_80108930_30CCD0_name_48].flags & 1) {
        func_801077F4_30BB94_name_48(D_80108914_30CCB4_name_48, D_8010896C_30CD0C_name_48, 3);
    }
    while (TRUE) {
        D_80108914_30CCB4_name_48 = stake;
        btn = ContDStkTrg[gPlayers[D_80108930_30CCD0_name_48].port];
        if (gPlayers[D_80108930_30CCD0_name_48].flags & 1) {
            btn = func_80107FBC_30C35C_name_48();
        }
        if (btn & 0x8000) {
            PlaySound(2);
            D_800F851A_F911A = 0;
            func_8008CCA8_8D8A8(win);
            D_80108910_30CCB0_name_48 = 1;
            omDelPrcObj(NULL);
        } else if (btn & 0x800) {
            if (gPlayers[D_80108930_30CCD0_name_48].coins > 0 && gPlayers[D_80108934_30CCD4_name_48].coins > 0) {
                if (++stake >= 1000) {
                    stake = 999;
                } else {
                    PlaySound(0x37B);
                }
                PD_STAKE_SHOW(win, stake);
                AdjustPlayerCoins(D_80108930_30CCD0_name_48, -1);
                AdjustPlayerCoins(D_80108934_30CCD4_name_48, -1);
            }
        } else if (btn & 0x400) {
            if (D_80108960_30CD00_name_48 < stake) {
                stake--;
                PlaySound(0x37C);
                PD_STAKE_SHOW(win, stake);
                AdjustPlayerCoins(D_80108930_30CCD0_name_48, 1);
                AdjustPlayerCoins(D_80108934_30CCD4_name_48, 1);
            }
        } else if (btn & 0x200) {
            if (stake - 10 >= D_80108960_30CD00_name_48) {
                stake -= 10;
                PlaySound(0x37C);
                PD_STAKE_SHOW(win, stake);
                AdjustPlayerCoins(D_80108930_30CCD0_name_48, 10);
                AdjustPlayerCoins(D_80108934_30CCD4_name_48, 10);
            }
        } else if (btn & 0x100) {
            if (gPlayers[D_80108930_30CCD0_name_48].coins >= 10 && gPlayers[D_80108934_30CCD4_name_48].coins >= 10) {
                stake += 10;
                if (stake >= 1000) {
                    stake = 999;
                } else {
                    PlaySound(0x37B);
                }
                PD_STAKE_SHOW(win, stake);
                AdjustPlayerCoins(D_80108930_30CCD0_name_48, -10);
                AdjustPlayerCoins(D_80108934_30CCD4_name_48, -10);
            }
        }
        HuPrcVSleep();
    }
}

__asm__(".section .rodata");
const u32 D_80108838_30CBD8_name_48[3] = { 0x3FB33333, 0x3F800000, 0x3F800000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_name/306BA0", func_80106A64_30AE04_name_48);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_name/306BA0", func_80106DEC_30B18C_name_48);

s32 func_80107508_30B8A8_name_48(void) {
    s32 cand[4];
    s32 n;
    s32 i;

    n = 0;
    for (i = 0; i < D_80108948_30CCE8_name_48 - 1; i++) {
        if (func_80059FD0_5ABD0(D_80108950_30CCF0_name_48[i]) == 0 && gPlayers[D_80108950_30CCF0_name_48[i]].coins > 0) {
            cand[n++] = i;
        }
    }
    if (n == 0) {
        for (i = 0; i < D_80108948_30CCE8_name_48 - 1; i++) {
            if (func_80059FD0_5ABD0(D_80108950_30CCF0_name_48[i]) == 1 && gPlayers[D_80108950_30CCF0_name_48[i]].coins > 0) {
                cand[n++] = i;
            }
        }
    }
    if (n == 0) {
        for (i = 0; i < D_80108948_30CCE8_name_48 - 1; i++) {
            if (func_80059FD0_5ABD0(D_80108950_30CCF0_name_48[i]) == 2 && gPlayers[D_80108950_30CCF0_name_48[i]].coins > 0) {
                cand[n++] = i;
            }
        }
    }
    if (n == 0) {
        for (i = 0; i < D_80108948_30CCE8_name_48 - 1; i++) {
            if (func_80059FD0_5ABD0(D_80108950_30CCF0_name_48[i]) == 3 && gPlayers[D_80108950_30CCF0_name_48[i]].coins > 0) {
                cand[n++] = i;
            }
        }
    }
    return cand[rand8() % n];
}

/* NON_MATCHING: masked 34, as 42's and 3F's twins: the rank loops' guards and the n != 0 exits
   (retail threads them with bnezl/blez); logic checked against the asm. Unlike 42, the flag-clearing
   loop runs over all D_80108948 entries, not D_80108948 - 1. */
#define PD_ABS(x) ((x) < 0 ? -(x) : (x))
#ifdef NON_MATCHING
void func_801077F4_30BB94_name_48(s32 cur, s32 target, s32 mode) {
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

    obj = omAddObj(0x10, 0, 0, -1, func_80107E1C_30C1BC_name_48);
    work = obj->unk_50 = func_80027154_27D54(sizeof(PdCpuInput), 0x7918);
    work->timer = 0;
    work->cur = cur;
    work->target = target;
    work->mode = mode;
    D_80108988_30CD28_name_48 = 0;
    if (mode == 2) {
        if (gPlayers[D_80108930_30CCD0_name_48].coins >= 20) {
            n = 0;
            for (i = 0; i < D_80108948_30CCE8_name_48; i++) {
                flag[i] = 0;
            }
            for (i = 0; i < D_80108948_30CCE8_name_48 - 1; i++) {
                if (func_80059FD0_5ABD0(D_80108950_30CCF0_name_48[i]) == 0) {
                    flag[i] = 1;
                    n++;
                }
            }
            if (n == 0) {
                for (i = 0; i < D_80108948_30CCE8_name_48 - 1; i++) {
                    if (func_80059FD0_5ABD0(D_80108950_30CCF0_name_48[i]) == 1) {
                        flag[i] = 1;
                        n++;
                    }
                }
            }
            if (n == 0) {
                for (i = 0; i < D_80108948_30CCE8_name_48 - 1; i++) {
                    if (func_80059FD0_5ABD0(D_80108950_30CCF0_name_48[i]) == 2) {
                        flag[i] = 1;
                        n++;
                    }
                }
            }
            if (n == 0) {
                for (i = 0; i < D_80108948_30CCE8_name_48 - 1; i++) {
                    if (func_80059FD0_5ABD0(D_80108950_30CCF0_name_48[i]) == 3) {
                        flag[i] = 1;
                        n++;
                    }
                }
            }
            n = 0;
            for (i = 0; i < D_80108948_30CCE8_name_48 - 1; i++) {
                if (flag[i] != 0 && gPlayers[D_80108950_30CCF0_name_48[i]].coins >= 20) {
                    cand[n++] = i;
                }
            }
            if (n == 0) {
                for (i = 0; i < D_80108948_30CCE8_name_48 - 1; i++) {
                    if (flag[i] == 0 && gPlayers[D_80108950_30CCF0_name_48[i]].coins >= 20) {
                        cand[n++] = i;
                    }
                }
            }
            if (n > 0) {
                work->target = cand[rand8() % n];
            } else {
                work->target = func_80107508_30B8A8_name_48();
            }
        } else {
            work->target = func_80107508_30B8A8_name_48();
        }
    }
    if (mode == 3) {
        row = func_80059FD0_5ABD0(D_80108930_30CCD0_name_48) * 8;
        row += func_80059FD0_5ABD0(D_80108930_30CCD0_name_48) * 2;
        diff = PD_ABS(gPlayers[D_80108930_30CCD0_name_48].stars - gPlayers[D_80108934_30CCD4_name_48].stars);
        row += diff < 2;
        work->target = (rand8() % range[rows[row]] + base[rows[row]]) * D_8010896C_30CD0C_name_48 / 100;
        if (work->target < D_80108960_30CD00_name_48) {
            work->target = D_80108960_30CD00_name_48;
        }
    }
}
#else
__asm__(".section .rodata");
const u32 D_80108844_30CBE4_name_48[32] = { 0xFFFFFFFF, 0x00000001, 0x00000003, 0x00000002, 0x00000003, 0x00000003, 0x00000003, 0x00000003, 0x00000000, 0x00000001, 0xFFFFFFFF, 0x00000001, 0x00000001, 0x00000002, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000001, 0xFFFFFFFF, 0x00000001, 0x00000001, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000001, 0xFFFFFFFF, 0xFFFFFFFF };

__asm__(".section .rodata");
const u32 D_801088C4_30CC64_name_48[4] = { 0x0000000A, 0x00000014, 0x00000014, 0x00000009 };

__asm__(".section .rodata");
const u32 D_801088D4_30CC74_name_48[4] = { 0x0000005A, 0x0000003C, 0x00000014, 0x00000001 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_name/306BA0", func_801077F4_30BB94_name_48);
#endif

void func_80107E1C_30C1BC_name_48(omObjData* obj) {
    PdCpuInput* work = obj->unk_50;

    D_80108988_30CD28_name_48 = 0;
    if (++work->timer >= 10) {
        switch (work->mode) {
            case 0:
                if (work->timer >= 30) {
                    D_80108988_30CD28_name_48 = 0x1000;
                    omDelObj(obj);
                }
                break;
            case 1:
                if (work->timer >= 30) {
                    D_80108988_30CD28_name_48 = 0x8000;
                    omDelObj(obj);
                }
                break;
            case 2:
                if (work->cur == work->target) {
                    D_80108988_30CD28_name_48 = 0x8000;
                    omDelObj(obj);
                } else if (work->cur < work->target) {
                    D_80108988_30CD28_name_48 = 0x400;
                    work->cur++;
                    work->timer = 0;
                } else if (work->cur > work->target) {
                    D_80108988_30CD28_name_48 = 0x800;
                    work->cur--;
                    work->timer = 0;
                }
                break;
            case 3:
                work->cur = D_80108914_30CCB4_name_48;
                if (work->cur == work->target) {
                    D_80108988_30CD28_name_48 = 0x8000;
                    omDelObj(obj);
                } else if (work->cur - work->target >= 10) {
                    D_80108988_30CD28_name_48 = 0x200;
                    work->timer = 0;
                } else if (work->cur - work->target < -9) {
                    D_80108988_30CD28_name_48 = 0x100;
                    work->timer = 0;
                } else if (work->cur - work->target < 10) {
                    D_80108988_30CD28_name_48 = 0x800;
                    work->timer = 0;
                } else if (work->cur - work->target >= -9) {
                    D_80108988_30CD28_name_48 = 0x400;
                    work->timer = 0;
                }
                break;
        }
    }
}

s32 func_80107FBC_30C35C_name_48(void) {
    return D_80108988_30CD28_name_48;
}

/* The countdown: full-width 5 to 0 in the centre, one a second. */
void func_80107FC8_30C368_name_48(void) {
    func_800695D8_6A1D8(func_800691FC_69DFC(9, "\x82\x54", 160, 56, 1.0, 1.0, 1), 25);
    HuPrcSleep(30);
    func_800695D8_6A1D8(func_800691FC_69DFC(9, "\x82\x53", 160, 56, 1.0, 1.0, 1), 25);
    HuPrcSleep(30);
    func_800695D8_6A1D8(func_800691FC_69DFC(9, "\x82\x52", 160, 56, 1.0, 1.0, 1), 25);
    HuPrcSleep(30);
    func_800695D8_6A1D8(func_800691FC_69DFC(9, "\x82\x51", 160, 56, 1.0, 1.0, 1), 25);
    HuPrcSleep(30);
    func_800695D8_6A1D8(func_800691FC_69DFC(9, "\x82\x50", 160, 56, 1.0, 1.0, 1), 25);
    HuPrcSleep(30);
    func_800695D8_6A1D8(func_800691FC_69DFC(9, "\x82\x4F", 160, 56, 1.0, 1.0, 1), 30);
    D_80108910_30CCB0_name_48 = 1;
    omDelPrcObj(NULL);
}

/* Shake the camera: four rounds of up, down, left, right, each smaller. */
void func_80108168_30C508_name_48(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_80054040_54C40(0, 8 - i * 2);
        HuPrcVSleep();
        func_80054040_54C40(0, i * 2 - 8);
        HuPrcVSleep();
        func_80054040_54C40(8 - i, 0);
        HuPrcVSleep();
        func_80054040_54C40(i - 8, 0);
        HuPrcVSleep();
    }
    omDelPrcObj(NULL);
}

/* Spin the winner's sign (model D_80108BF8[D_80108778]) a quarter turn to face front, then drop it
   32 units in eight steps. */
void func_80108220_30C5C0_name_48(void) {
    s32 i;

    if (D_80108778_30CB18_name_48 == 0) {
        D_80108C40_30CFE0_name_48[D_80108778_30CB18_name_48] = 90.0f;
        do {
            D_80108C40_30CFE0_name_48[D_80108778_30CB18_name_48] += D_8010877C_30CB1C_name_48[D_80108778_30CB18_name_48];
            D_800FC834_FD434[D_80108BF8_30CF98_name_48[D_80108778_30CB18_name_48]].rot.y = D_80108C40_30CFE0_name_48[D_80108778_30CB18_name_48];
            HuPrcVSleep();
        } while (D_80108C40_30CFE0_name_48[D_80108778_30CB18_name_48] > 0.0f);
    } else {
        D_80108C40_30CFE0_name_48[D_80108778_30CB18_name_48] = 270.0f;
        do {
            D_80108C40_30CFE0_name_48[D_80108778_30CB18_name_48] += D_8010877C_30CB1C_name_48[D_80108778_30CB18_name_48];
            D_800FC834_FD434[D_80108BF8_30CF98_name_48[D_80108778_30CB18_name_48]].rot.y = D_80108C40_30CFE0_name_48[D_80108778_30CB18_name_48];
            HuPrcVSleep();
        } while (D_80108C40_30CFE0_name_48[D_80108778_30CB18_name_48] < 360.0f);
    }
    D_800FC834_FD434[D_80108BF8_30CF98_name_48[D_80108778_30CB18_name_48]].rot.y = 0.0f;
    HuPrcSleep(15);
    D_80108C48_30CFE8_name_48 = 32.0f;
    for (i = 0; i < 8; i++) {
        D_80108C48_30CFE8_name_48 -= 4.0f;
        D_800FC834_FD434[D_80108BF8_30CF98_name_48[D_80108778_30CB18_name_48]].pos.y = D_80108C48_30CFE8_name_48 + 237.02071f;
        HuPrcVSleep();
    }
    omDelPrcObj(NULL);
}

void func_8010848C_30C82C_name_48(void) {
    omAddObj(0x10, 0, 0, -1, func_801084C0_30C860_name_48);
}

void func_801084C0_30C860_name_48(omObjData* obj) {
}
