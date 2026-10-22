#include "common.h"
#include "ovl_46.h"

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_46_name/2F1730", func_80102800_2F1730_name_46);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_46_name/2F1730", func_801029F8_2F1928_name_46);

void func_80102C2C_2F1B5C_name_46(omObjData* obj) {
    if (D_801011FC_101DFC != 0) {
        MBDBackKill();
        func_80050AE0_516E0();
        func_80059400_5A000();
        func_80069770_6A370();
        func_8008CE5C_8DA5C();
        omOvlReturnEx(1);
    }
}

void func_80102C80_2F1BB0_name_46(void) {
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
const char D_80108080_2F6FB0_name_46[] = "\202Q\202R\202S\202T";

__asm__(".section .rodata");
const u32 D_8010808C_2F6FBC_name_46[3] = { 0x00000002, 0x000800A7, 0x000800AA };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_46_name/2F1730", func_80102D0C_2F1C3C_name_46);

__asm__(".section .rodata");

void func_80104880_2F37B0_name_46(void) {
    s16 size[2];
    char num[0x100];
    char name[0x100];
    s32 win;
    u16 btn;

    if (D_801081E0_2F7110_name_46 == 2) {
        sprintf(num, "%d", D_801081D4_2F7104_name_46);
        func_8008D974_8E574(num, 0);
    }
    if (D_801081E0_2F7110_name_46 == 3) {
        sprintf(num, "%d", D_801081D4_2F7104_name_46);
        sprintf(name, "%c%c", 0x18, gPlayers[D_801081EC_2F711C_name_46].character);
        func_8008D974_8E574(name, 0);
        func_8008D974_8E574(num, 1);
        func_8008D974_8E574(name, 2);
    }
    if (D_801081E0_2F7110_name_46 == 4) {
        sprintf(num, "%d", D_80108298_2F71C8_name_46);
        func_8008D974_8E574(num, 0);
    }
    func_8008DACC_8E6CC(1, size, D_801081E4_2F7114_name_46);
    win = func_80104C88_2F3BB8_name_46((s16)D_801081D8_2F7108_name_46, (s16)D_801081DC_2F710C_name_46, size[0], size[1], 0, 0, 200);
    if (D_801081E8_2F7118_name_46 & 1) {
        ShowTextWindow((s16)win);
    }
    if (D_801081E0_2F7110_name_46 == 2 || D_801081E0_2F7110_name_46 == 4) {
        func_80089308_89F08(win, num, 0);
    }
    if (D_801081E0_2F7110_name_46 == 3) {
        func_80089308_89F08(win, name, 0);
        func_80089308_89F08(win, num, 1);
        func_80089308_89F08(win, name, 2);
    }
    func_8008AD44_8B944(win);
    func_800890CC_89CCC(win, D_801081E4_2F7114_name_46, -1, -1);
    func_80057A78_58678((s16)win, D_801081F0_2F7120_name_46, D_801081F4_2F7124_name_46);
    if (D_801081E0_2F7110_name_46 == 1 && (gPlayers[D_801081F0_2F7120_name_46].flags & 1) && (gPlayers[D_801081F4_2F7124_name_46].flags & 1)) {
        func_8010675C_2F568C_name_46(0, 0, 0);
    }
    while (TRUE) {
        switch (D_801081E0_2F7110_name_46) {
            case 1:
                if ((gPlayers[D_801081F0_2F7120_name_46].flags & 1) && (gPlayers[D_801081F4_2F7124_name_46].flags & 1)) {
                    btn = func_80106F2C_2F5E5C_name_46();
                } else {
                    btn = func_80104DF0_2F3D20_name_46();
                }
                if (btn & 0x1000) {
                    PlaySound(2);
                    D_801081D0_2F7100_name_46 = 1;
                    func_8008CCA8_8D8A8(win);
                    omDelPrcObj(NULL);
                }
                break;
            case 2:
            case 3:
            case 4:
                if (D_801081E8_2F7118_name_46 & 1) {
                    func_8005762C_5822C((s16)win);
                } else {
                    func_8008CCA8_8D8A8(win);
                }
                D_801081D0_2F7100_name_46 = 1;
                omDelPrcObj(NULL);
                break;
        }
        HuPrcVSleep();
    }
}

#ifdef NON_MATCHING
s32 func_80104C88_2F3BB8_name_46(s16 x, s16 y, s16 w, s16 h, s16 arg4, s16 arg5, s32 arg6) {
    s32 win;
    s16 mask;

    win = func_800888A8_894A8(x, y, w, h, arg4, arg5);
    func_80089284_89E84(win, 0x40, 0x40);
    func_80089A48_8A648(win, 0);
    func_8008D88C_8E48C(win);
    func_80089B2C_8A72C(win, arg6);
    if (D_801081F4_2F7124_name_46 != -1) {
        mask = (1 << gPlayers[D_801081F0_2F7120_name_46].port) | (1 << gPlayers[D_801081F4_2F7124_name_46].port);
    } else {
        mask = 1 << gPlayers[D_801081F0_2F7120_name_46].port;
    }
    func_8008D59C_8E19C(win, mask);
    return (s16)win;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_46_name/2F1730", func_80104C88_2F3BB8_name_46);
#endif

u16 func_80104DF0_2F3D20_name_46(void) {
    u16 btn;

    btn = 0;
    if (!(gPlayers[D_801081F0_2F7120_name_46].flags & 1)) {
        btn = ContDStkTrg[gPlayers[D_801081F0_2F7120_name_46].port];
    }
    if (D_801081F4_2F7124_name_46 != -1 && btn == 0) {
        if (!(gPlayers[D_801081F4_2F7124_name_46].flags & 1)) {
            btn = ContDStkTrg[gPlayers[D_801081F4_2F7124_name_46].port];
        }
    }
    return btn;
}

void func_80104EB0_2F3DE0_name_46(s32 layout) {
    omObjData* obj;
    s32* work;
    BoardStatus* status;
    s32 slot;
    s32 i;
    s32 next;

    D_801081D0_2F7100_name_46 = 0;
    obj = omAddObj(0x12, 0, 0, -1, func_801051E8_2F4118_name_46);
    work = func_80027154_27D54(8, 0x7918);
    obj->unk_50 = work;
    *work = layout;
    next = 0;
    for (i = 0; i < 4; i++) {
        if (D_801081F8_2F7128_name_46[i] != 0) {
            status = &D_80101510_102110[i];
            slot = 3;
            if (i != D_801081F0_2F7120_name_46) {
                if (i == D_801081F4_2F7124_name_46) {
                    slot = 2;
                } else {
                    slot = next;
                    D_80108210_2F7140_name_46[slot] = i;
                    next = slot + 1;
                }
            }
            if (D_80107DD0_2F6D00_name_46[layout].pos[slot][0] != -1) {
                status->xPos = D_80107DD0_2F6D00_name_46[layout].pos[slot][0];
            }
            if (D_80107DD0_2F6D00_name_46[layout].pos[slot][1] != -1) {
                status->yPos = D_80107DD0_2F6D00_name_46[layout].pos[slot][1];
            }
            func_800600F8_60CF8(i, status->xPos, status->yPos);
            status->unk_0C = D_80107DD0_2F6D00_name_46[layout].frames - 1;
            if (D_80107DD0_2F6D00_name_46[layout].pos[slot][2] != -1) {
                status->unk_18 = D_80107DD0_2F6D00_name_46[layout].pos[slot][2];
            }
            if (D_80107DD0_2F6D00_name_46[layout].pos[slot][3] != -1) {
                status->unk_1C = D_80107DD0_2F6D00_name_46[layout].pos[slot][3];
            }
            status->unk_20 = status->unk_28 = 2.0f * (status->unk_18 - status->xPos) / ((status->unk_0C + 1) * (status->unk_0C + 1));
            status->unk_24 = status->unk_2C = 2.0f * (status->unk_1C - status->yPos) / ((status->unk_0C + 1) * (status->unk_0C + 1));
        }
    }
    if (D_80107FB0_2F6EE0_name_46 == 1) {
        status = &D_80101510_102110[D_801081F0_2F7120_name_46];
        D_800FD854_FE454[0].unk_00 = D_800FC990_FD590[0].unk_00 = status->unk_28;
        D_800FD854_FE454[0].unk_04 = D_800FC990_FD590[0].unk_04 = status->unk_2C;
        D_800FA604_FB204 = D_80107DD0_2F6D00_name_46[layout].frames - 1;
    }
}

void func_801051E8_2F4118_name_46(omObjData* obj) {
    BoardStatus* status;
    s32 done;
    s32 i;

    done = 0;
    for (i = 0; i < 4; i++) {
        if (D_801081F8_2F7128_name_46[i] != 0) {
            status = &D_80101510_102110[i];
            if (status->unk_0C == 0) {
                status->xPos = status->unk_18;
                status->yPos = status->unk_1C;
                done++;
            }
        }
    }
    if (done == D_80108208_2F7138_name_46) {
        D_801081D0_2F7100_name_46 = 1;
        omDelObj(obj);
    }
}

void func_80105280_2F41B0_name_46(void) {
    omAddObj(0x10, 0, 0, -1, func_801052BC_2F41EC_name_46);
    func_80069764_6A364(60);
}

void func_801052BC_2F41EC_name_46(omObjData* obj) {
    if (func_800696E4_6A2E4() == 0) {
        InitFadeOut(0, 20);
        if (D_8010826C_2F719C_name_46 != 0) {
            func_80079614_7A214(20);
        }
        obj->func_ptr = func_80105314_2F4244_name_46;
    }
}

void func_80105314_2F4244_name_46(omObjData* obj) {
    if (func_8008F618_90218() == 0) {
        MBDBackKill();
        func_80050AE0_516E0();
        func_80059400_5A000();
        func_80069770_6A370();
        func_8008CE5C_8DA5C();
        omOvlReturnEx(1);
    }
}

void func_80105368_2F4298_name_46(void) {
    omObjData* obj;
    PdShrink* work;

    obj = omAddObj(0x10, 0, 0, -1, func_801053F8_2F4328_name_46);
    work = func_80027154_27D54(sizeof(PdShrink), 0x7918);
    obj->unk_50 = work;
    work->scaleSpeed = -0.06666667f;
    work->rotSpeed = -3.0f;
    work->unk10 = 0;
    work->unkC = 1.0f;
    work->timer = 15;
}

void func_801053F8_2F4328_name_46(omObjData* obj) {
    PdShrink* work = obj->unk_50;

    D_80108278_2F71A8_name_46->scale.x += work->scaleSpeed;
    D_80108278_2F71A8_name_46->scale.y += work->scaleSpeed;
    D_80108278_2F71A8_name_46->scale.z += work->scaleSpeed;
    D_80108278_2F71A8_name_46->obj->rot.x += work->rotSpeed;
    if (--work->timer == 0) {
        MBModelDispOff(D_80108278_2F71A8_name_46);
        omDelObj(obj);
    }
}

void func_80105488_2F43B8_name_46(void) {
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
    win = func_80104C88_2F3BB8_name_46(70, 178, size[0], size[1], 0, 0, 200);
    func_8008AD44_8B944(win);
    func_800890CC_89CCC(win, 0x212, -1, -1);
    sel = 0;
    count = D_80108208_2F7138_name_46 - 1;
    if (D_80108208_2F7138_name_46 == 4) {
        src = ys4;
    } else {
        src = ys3;
    }
    for (i = 0; i < D_80108208_2F7138_name_46; i++) {
        ys[i] = *src++;
    }
    spr = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x42), 1, 1);
    espDispOn(spr);
    if (gPlayers[D_801081F0_2F7120_name_46].flags & 1) {
        func_8010675C_2F568C_name_46(sel, 0, 2);
    }
    while (TRUE) {
        btn = func_80104DF0_2F3D20_name_46();
        if (gPlayers[D_801081F0_2F7120_name_46].flags & 1) {
            btn = func_80106F2C_2F5E5C_name_46();
        }
        if ((btn & 0x8000) && BoardSpaceGet(D_80108210_2F7140_name_46[sel], 1) != 0) {
            PlaySound(2);
            D_801081D0_2F7100_name_46 = 1;
            D_801081F4_2F7124_name_46 = D_80108210_2F7140_name_46[sel];
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

void func_80105754_2F4684_name_46(void) {
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

    turn = D_80108224_2F7154_name_46;
    i = 0;
    while (turn >= turns[i]) {
        if (++i == 4) {
            break;
        }
    }
    coins1 = BoardPlayerGet(D_801081F0_2F7120_name_46)->coins;
    coins2 = BoardPlayerGet(D_801081F4_2F7124_name_46)->coins;
    D_80108234_2F7164_name_46 = coins1;
    if (coins2 < coins1) {
        D_80108234_2F7164_name_46 = coins2;
    }
    i++;
    while (D_80108234_2F7164_name_46 < stakes[i]) {
        if (--i == 0) {
            break;
        }
    }
    D_801081D4_2F7104_name_46 = D_80108220_2F7150_name_46 = stakes[i];
    x = 0x2F;
    y = 0x2E;
    stake = D_80108220_2F7150_name_46;
    sprintf(mess, "", stake);
    func_8008D974_8E574(mess, 0);
    func_8008DACC_8E6CC(1, size, 0x213);
    win = func_80104C88_2F3BB8_name_46(24, 72, size[0], size[1], 0, 0, 200);
    func_80089308_89F08(win, mess, 0);
    func_8008AD44_8B944(win);
    func_800890CC_89CCC(win, 0x213, -1, -1);
    HuPrcVSleep();
    func_80089284_89E84(win, 0x10004, 0x10004);
    PD_STAKE_SHOW(win, stake);
    func_80057730_58330(win, D_801081F0_2F7120_name_46);
    AdjustPlayerCoins(D_801081F0_2F7120_name_46, -D_801081D4_2F7104_name_46);
    AdjustPlayerCoins(D_801081F4_2F7124_name_46, -D_801081D4_2F7104_name_46);
    func_80089284_89E84(win, 4, 4);
    if (gPlayers[D_801081F0_2F7120_name_46].flags & 1) {
        func_8010675C_2F568C_name_46(D_801081D4_2F7104_name_46, D_80108234_2F7164_name_46, 3);
    }
    while (TRUE) {
        D_801081D4_2F7104_name_46 = stake;
        btn = ContDStkTrg[gPlayers[D_801081F0_2F7120_name_46].port];
        if (gPlayers[D_801081F0_2F7120_name_46].flags & 1) {
            btn = func_80106F2C_2F5E5C_name_46();
        }
        if (btn & 0x8000) {
            PlaySound(2);
            D_800F851A_F911A = 0;
            func_8008CCA8_8D8A8(win);
            D_801081D0_2F7100_name_46 = 1;
            omDelPrcObj(NULL);
        } else if (btn & 0x800) {
            if (gPlayers[D_801081F0_2F7120_name_46].coins > 0 && gPlayers[D_801081F4_2F7124_name_46].coins > 0) {
                if (++stake >= 1000) {
                    stake = 999;
                } else {
                    PlaySound(0x37B);
                }
                PD_STAKE_SHOW(win, stake);
                AdjustPlayerCoins(D_801081F0_2F7120_name_46, -1);
                AdjustPlayerCoins(D_801081F4_2F7124_name_46, -1);
            }
        } else if (btn & 0x400) {
            if (D_80108220_2F7150_name_46 < stake) {
                stake--;
                PlaySound(0x37C);
                PD_STAKE_SHOW(win, stake);
                AdjustPlayerCoins(D_801081F0_2F7120_name_46, 1);
                AdjustPlayerCoins(D_801081F4_2F7124_name_46, 1);
            }
        } else if (btn & 0x200) {
            if (stake - 10 >= D_80108220_2F7150_name_46) {
                stake -= 10;
                PlaySound(0x37C);
                PD_STAKE_SHOW(win, stake);
                AdjustPlayerCoins(D_801081F0_2F7120_name_46, 10);
                AdjustPlayerCoins(D_801081F4_2F7124_name_46, 10);
            }
        } else if (btn & 0x100) {
            if (gPlayers[D_801081F0_2F7120_name_46].coins >= 10 && gPlayers[D_801081F4_2F7124_name_46].coins >= 10) {
                stake += 10;
                if (stake >= 1000) {
                    stake = 999;
                } else {
                    PlaySound(0x37B);
                }
                PD_STAKE_SHOW(win, stake);
                AdjustPlayerCoins(D_801081F0_2F7120_name_46, -10);
                AdjustPlayerCoins(D_801081F4_2F7124_name_46, -10);
            }
        }
        HuPrcVSleep();
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_46_name/2F1730", func_80105FD0_2F4F00_name_46);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_46_name/2F1730", func_80106038_2F4F68_name_46);

s32 func_80106470_2F53A0_name_46(void) {
    s32 cand[4];
    s32 n;
    s32 i;

    n = 0;
    for (i = 0; i < D_80108208_2F7138_name_46 - 1; i++) {
        if (func_80059FD0_5ABD0(D_80108210_2F7140_name_46[i]) == 0 && gPlayers[D_80108210_2F7140_name_46[i]].coins > 0) {
            cand[n++] = i;
        }
    }
    if (n == 0) {
        for (i = 0; i < D_80108208_2F7138_name_46 - 1; i++) {
            if (func_80059FD0_5ABD0(D_80108210_2F7140_name_46[i]) == 1 && gPlayers[D_80108210_2F7140_name_46[i]].coins > 0) {
                cand[n++] = i;
            }
        }
    }
    if (n == 0) {
        for (i = 0; i < D_80108208_2F7138_name_46 - 1; i++) {
            if (func_80059FD0_5ABD0(D_80108210_2F7140_name_46[i]) == 2 && gPlayers[D_80108210_2F7140_name_46[i]].coins > 0) {
                cand[n++] = i;
            }
        }
    }
    if (n == 0) {
        for (i = 0; i < D_80108208_2F7138_name_46 - 1; i++) {
            if (func_80059FD0_5ABD0(D_80108210_2F7140_name_46[i]) == 3 && gPlayers[D_80108210_2F7140_name_46[i]].coins > 0) {
                cand[n++] = i;
            }
        }
    }
    return cand[rand8() % n];
}

__asm__(".section .rodata");
const u32 D_801080F8_2F7028_name_46[32] = { 0xFFFFFFFF, 0x00000001, 0x00000003, 0x00000002, 0x00000003, 0x00000003, 0x00000003, 0x00000003, 0x00000000, 0x00000001, 0xFFFFFFFF, 0x00000001, 0x00000001, 0x00000002, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000001, 0xFFFFFFFF, 0x00000001, 0x00000001, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000001, 0xFFFFFFFF, 0xFFFFFFFF };

__asm__(".section .rodata");
const u32 D_80108178_2F70A8_name_46[4] = { 0x0000000A, 0x00000014, 0x00000014, 0x00000009 };

__asm__(".section .rodata");
const u32 D_80108188_2F70B8_name_46[4] = { 0x0000005A, 0x0000003C, 0x00000014, 0x00000001 };

#ifdef NON_MATCHING
void func_8010675C_2F568C_name_46(s32 cur, s32 target, s32 mode) {
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

    obj = omAddObj(0x10, 0, 0, -1, func_80106D8C_2F5CBC_name_46);
    work = obj->unk_50 = func_80027154_27D54(sizeof(PdCpuInput), 0x7918);
    work->timer = 0;
    work->cur = cur;
    work->target = target;
    work->mode = mode;
    D_80108248_2F7178_name_46 = 0;
    if (mode == 2) {
        if (gPlayers[D_801081F0_2F7120_name_46].coins >= 20) {
            n = 0;
            for (i = 0; i < D_80108208_2F7138_name_46 - 1; i++) {
                flag[i] = 0;
            }
            for (i = 0; i < D_80108208_2F7138_name_46 - 1; i++) {
                if (func_80059FD0_5ABD0(D_80108210_2F7140_name_46[i]) == 0) {
                    flag[i] = 1;
                    n++;
                }
            }
            if (n == 0) {
                for (i = 0; i < D_80108208_2F7138_name_46 - 1; i++) {
                    if (func_80059FD0_5ABD0(D_80108210_2F7140_name_46[i]) == 1) {
                        flag[i] = 1;
                        n++;
                    }
                }
            }
            if (n == 0) {
                for (i = 0; i < D_80108208_2F7138_name_46 - 1; i++) {
                    if (func_80059FD0_5ABD0(D_80108210_2F7140_name_46[i]) == 2) {
                        flag[i] = 1;
                        n++;
                    }
                }
            }
            if (n == 0) {
                for (i = 0; i < D_80108208_2F7138_name_46 - 1; i++) {
                    if (func_80059FD0_5ABD0(D_80108210_2F7140_name_46[i]) == 3) {
                        flag[i] = 1;
                        n++;
                    }
                }
            }
            n = 0;
            for (i = 0; i < D_80108208_2F7138_name_46 - 1; i++) {
                if (flag[i] != 0 && gPlayers[D_80108210_2F7140_name_46[i]].coins >= 20) {
                    cand[n++] = i;
                }
            }
            if (n == 0) {
                for (i = 0; i < D_80108208_2F7138_name_46 - 1; i++) {
                    if (flag[i] == 0 && gPlayers[D_80108210_2F7140_name_46[i]].coins >= 20) {
                        cand[n++] = i;
                    }
                }
            }
            if (n > 0) {
                work->target = cand[rand8() % n];
            } else {
                work->target = func_80106470_2F53A0_name_46();
            }
        } else {
            work->target = func_80106470_2F53A0_name_46();
        }
    }
    if (mode == 3) {
        row = func_80059FD0_5ABD0(D_801081F0_2F7120_name_46) * 8;
        row += func_80059FD0_5ABD0(D_801081F0_2F7120_name_46) * 2;
        diff = PD_ABS(gPlayers[D_801081F0_2F7120_name_46].stars - gPlayers[D_801081F4_2F7124_name_46].stars);
        row += diff < 2;
        work->target = (rand8() % range[rows[row]] + base[rows[row]]) * D_80108234_2F7164_name_46 / 100;
        if (work->target < D_80108220_2F7150_name_46) {
            work->target = D_80108220_2F7150_name_46;
        }
    }
}
#else
__asm__(".section .rodata");


INCLUDE_ASM("asm/nonmatchings/overlays/ovl_46_name/2F1730", func_8010675C_2F568C_name_46);
#endif

void func_80106D8C_2F5CBC_name_46(omObjData* obj) {
    PdCpuInput* work = obj->unk_50;

    D_80108248_2F7178_name_46 = 0;
    if (++work->timer >= 10) {
        switch (work->mode) {
            case 0:
                if (work->timer >= 30) {
                    D_80108248_2F7178_name_46 = 0x1000;
                    omDelObj(obj);
                }
                break;
            case 1:
                if (work->timer >= 30) {
                    D_80108248_2F7178_name_46 = 0x8000;
                    omDelObj(obj);
                }
                break;
            case 2:
                if (work->cur == work->target) {
                    D_80108248_2F7178_name_46 = 0x8000;
                    omDelObj(obj);
                } else if (work->cur < work->target) {
                    D_80108248_2F7178_name_46 = 0x400;
                    work->cur++;
                    work->timer = 0;
                } else if (work->cur > work->target) {
                    D_80108248_2F7178_name_46 = 0x800;
                    work->cur--;
                    work->timer = 0;
                }
                break;
            case 3:
                work->cur = D_801081D4_2F7104_name_46;
                if (work->cur == work->target) {
                    D_80108248_2F7178_name_46 = 0x8000;
                    omDelObj(obj);
                } else if (work->cur - work->target >= 10) {
                    D_80108248_2F7178_name_46 = 0x200;
                    work->timer = 0;
                } else if (work->cur - work->target < -9) {
                    D_80108248_2F7178_name_46 = 0x100;
                    work->timer = 0;
                } else if (work->cur - work->target < 10) {
                    D_80108248_2F7178_name_46 = 0x800;
                    work->timer = 0;
                } else if (work->cur - work->target >= -9) {
                    D_80108248_2F7178_name_46 = 0x400;
                    work->timer = 0;
                }
                break;
        }
    }
}

s32 func_80106F2C_2F5E5C_name_46(void) {
    return D_80108248_2F7178_name_46;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_46_name/2F1730", func_80106F38_2F5E68_name_46);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_46_name/2F1730", func_801070C8_2F5FF8_name_46);

__asm__(".section .rodata");
const u32 D_80108198_2F70C8_name_46[5] = { 0xFFFFFFDC, 0xFFFFFFF0, 0x00000004, 0x00000008, 0x00000016 };

__asm__(".section .rodata");
const u32 D_801081AC_2F70DC_name_46[5] = { 0x00000000, 0x00000000, 0x00000000, 0x00000004, 0x00000004 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_46_name/2F1730", func_80107158_2F6088_name_46);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_46_name/2F1730", func_801073EC_2F631C_name_46);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_46_name/2F1730", func_80107448_2F6378_name_46);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_46_name/2F1730", func_80107644_2F6574_name_46);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_46_name/2F1730", func_801076B4_2F65E4_name_46);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_46_name/2F1730", func_80107850_2F6780_name_46);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_46_name/2F1730", func_80107978_2F68A8_name_46);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_46_name/2F1730", func_80107C44_2F6B74_name_46);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_46_name/2F1730", func_80107D00_2F6C30_name_46);
