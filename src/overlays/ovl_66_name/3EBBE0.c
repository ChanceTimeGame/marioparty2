#include "common.h"
#include "ovl_66.h"

#define OVL66_ABS(x) ((x) < 0 ? -(s32)(x) : (x))
/* Waits on a mover: makes it a child of the current process. */
#define OVL66_LINK(call) do { Process* _p = (call); HuPrcChildLink(HuPrcCurrentGet(), _p); } while (0)

void func_80102830_3EBBE0_name_66(void) {
    CoasterSpaceFlag* entry;

    entry = D_80106220_3EF5D0_name_66;
    while (entry->space >= 0) {
        if (func_80075390_75F90(entry->flag) != 0) {
            BoardSpaceTypeSet(entry->space, 1);
        }
        entry++;
    }
}

s32 func_8010288C_3EBC3C_name_66(s32 flag) {
    return D_80106440_3EF7F0_name_66.flags[flag / 8] & (1 << (flag % 8));
}

__asm__(".section .rodata");
const char D_80106400_3EF7B0_name_66[] = "%2d";

void func_801028D0_3EBC80_name_66(void) {
    s16 size[2];
    void* data;
    s32 i;
    s32 win;

    D_80106474_3EF824_name_66 = func_8005E688_5F288(1, 0);
    data = DataRead(D_80106234_3EF5E4_name_66[(s8)D_80106440_3EF7F0_name_66.character]);
    i = 0;
    D_80106474_3EF824_name_66->unk0C[0] = SprAnimRead(data);
    SprAnimSet(D_80106474_3EF824_name_66->unk0A, 0, D_80106474_3EF824_name_66->unk0C[0], 0);
    SprPrioSet(D_80106474_3EF824_name_66->unk0A, 0, 0x10);
    SprAttrSet(D_80106474_3EF824_name_66->unk0A, 0, 0x1000);
    SprPosSet(D_80106474_3EF824_name_66->unk0A, 0, 0x3E, 0x5F);
    DataClose(data);
    D_80106458_3EF808_name_66[6] = func_80057480_58080(D_80106294_3EF644_name_66[0], D_80106294_3EF644_name_66[1], 0x18, 5);
    for (; i < 4; i++) {
        func_8008DACC_8E6CC(1, size, D_8010624C_3EF5FC_name_66[i]);
        D_80106458_3EF808_name_66[i] = (s16)func_800888A8_894A8(D_8010627C_3EF62C_name_66[i][0], D_8010627C_3EF62C_name_66[i][1], size[0], size[1], 0, 0);
        func_80089B2C_8A72C((s16)D_80106458_3EF808_name_66[i], 0);
        func_80089A48_8A648((s16)D_80106458_3EF808_name_66[i], 0);
        func_800890CC_89CCC((s16)D_80106458_3EF808_name_66[i], (void*)D_8010624C_3EF5FC_name_66[i], -1, -1);
    }
    func_8008DACC_8E6CC(1, size, D_80106264_3EF614_name_66[D_80106440_3EF7F0_name_66.difficulty]);
    i = 4;
    D_80106458_3EF808_name_66[i] = (s16)func_800888A8_894A8(D_8010628C_3EF63C_name_66, D_8010628E_3EF63E_name_66, size[0], size[1], 0, 0);
    func_80089B2C_8A72C((s16)D_80106458_3EF808_name_66[i], 0);
    func_80089A48_8A648((s16)D_80106458_3EF808_name_66[i], 0);
    func_800890CC_89CCC((s16)D_80106458_3EF808_name_66[i], (void*)D_80106264_3EF614_name_66[D_80106440_3EF7F0_name_66.difficulty], -1, -1);
    sprintf(D_80106478_3EF828_name_66, D_80106400_3EF7B0_name_66, D_80106440_3EF7F0_name_66.chapter);
    func_8008D974_8E574(D_80106478_3EF828_name_66, 0);
    sprintf(D_80106480_3EF830_name_66, D_80106400_3EF7B0_name_66, D_80106440_3EF7F0_name_66.lives);
    func_8008D974_8E574(D_80106480_3EF830_name_66, 1);
    sprintf(D_80106488_3EF838_name_66, D_80106400_3EF7B0_name_66, D_80106440_3EF7F0_name_66.coins);
    func_8008D974_8E574(D_80106488_3EF838_name_66, 2);
    i = 5;
    func_8008DACC_8E6CC(1, size, D_8010624C_3EF5FC_name_66[i]);
    win = func_800888A8_894A8(D_80106290_3EF640_name_66, D_80106292_3EF642_name_66, size[0], size[1] * 2, 0, 0);
    D_80106458_3EF808_name_66[i] = win;
    D_800F920C_F9E0C[win].unk28 = 0x12;
    func_80089B2C_8A72C((s16)D_80106458_3EF808_name_66[i], 0);
    func_80089A48_8A648((s16)D_80106458_3EF808_name_66[i], 0);
    func_80089308_89F08((s16)D_80106458_3EF808_name_66[i], D_80106478_3EF828_name_66, 0);
    func_80089308_89F08((s16)D_80106458_3EF808_name_66[i], D_80106480_3EF830_name_66, 1);
    func_80089308_89F08((s16)D_80106458_3EF808_name_66[i], D_80106488_3EF838_name_66, 2);
    func_800890CC_89CCC((s16)D_80106458_3EF808_name_66[i], (void*)D_8010624C_3EF5FC_name_66[i], -1, -1);
}

void func_80102C88_3EC038_name_66(void) {
    s32 i;

    for (i = 0; i < 7; i++) {
        func_8008CCA8_8D8A8((s16)D_80106458_3EF808_name_66[i]);
    }
    HuMemDirectFree(D_80106474_3EF824_name_66);
}

__asm__(".section .rodata");
const char D_80106404_3EF7B4_name_66[] = "%d";

void func_80102CE4_3EC094_name_66(void) {
    char buf[8];
    s32 choice;

again:
    {
        sprintf(buf, D_80106404_3EF7B4_name_66, D_800FD8A8_FE4A8.stage + 1);
        MBDlgWinInsertCreateY(0x29, 0x5CD, buf, NULL, NULL, NULL, NULL, 0xAA);
        choice = func_8008BB48_8C748(mbDlgWinId, 0, 1);
        MBDlgWinClose();
        func_80056168_56D68();
        HuPrcVSleep();
        if (choice == 0) {
            func_8007E0C8_7ECC8(&D_80106440_3EF7F0_name_66);
            if (func_8010288C_3EBC3C_name_66(0) != 0) {
                func_801028D0_3EBC80_name_66();
                sprintf(buf, D_80106404_3EF7B4_name_66, D_80106440_3EF7F0_name_66.stage + 1);
                MBDlgWinInsertCreateY(0x29, 0x5CF, buf, NULL, NULL, NULL, NULL, 0xAA);
                choice = func_8008BB48_8C748(mbDlgWinId, 0, 0);
                MBDlgWinClose();
                func_80056168_56D68();
                HuPrcVSleep();
                func_80102C88_3EC038_name_66();
                if (choice != 0) {
                    goto again;
                }
            }
            func_800753D4_75FD4(0);
            _ClearFlag(0);
            func_8007E018_7EC18();
            func_8007E0C8_7ECC8(&D_80106440_3EF7F0_name_66);
            func_801028D0_3EBC80_name_66();
            MBDlgWinInsertCreateY(0x29, 0x5D0, NULL, NULL, NULL, NULL, NULL, 0xAA);
            choice = func_8008BB48_8C748(mbDlgWinId, 0, 1);
            MBDlgWinClose();
            func_80056168_56D68();
            func_80102C88_3EC038_name_66();
            if (choice == 1) {
                MBDlgWinExecY(0x29, 0x5D1, 0xAA);
                func_800794A8_7A0A8(0x5A);
                InitFadeOut(0, 0x10);
                HuPrcSleep(0x11);
                func_800744C0_750C0();
                func_800740AC_74CAC();
                omOvlReturnEx(1);
                omOvlKill();
                HuPrcVSleep();
            }
            goto end;
        }
        MBDlgWinInsertCreateY(0x29, 0x5CE, NULL, NULL, NULL, NULL, NULL, 0xAA);
        choice = func_8008BB48_8C748(mbDlgWinId, 0, 0);
        MBDlgWinClose();
        func_80056168_56D68();
        if (choice != 0) {
            goto again;
        }
    }
end:
    if (D_800FD8A8_FE4A8.difficulty == 0 && D_800FD8A8_FE4A8.stage == 2) {
        MBDlgWinExecY(0x29, 0x5D3, 0xAA);
        return;
    }
    if (D_800FD8A8_FE4A8.difficulty == 1 && D_800FD8A8_FE4A8.stage == 5) {
        MBDlgWinExecY(0x29, 0x5D5, 0xAA);
        return;
    }
    if (D_800FD8A8_FE4A8.difficulty == 2) {
        if (D_800FD8A8_FE4A8.stage == 7) {
            MBDlgWinExecY(0x29, 0x5D7, 0xAA);
            return;
        }
        if (D_800FD8A8_FE4A8.difficulty == 2 && D_800FD8A8_FE4A8.stage == 8) {
            if (func_80075390_75F90(8) == 0) {
                MBDlgWinExecY(0x29, 0x5D8, 0xAA);
                return;
            }
        }
        if (D_800FD8A8_FE4A8.difficulty == 2 && D_800FD8A8_FE4A8.stage == 8) {
            if (func_80075390_75F90(8) != 0) {
                buf[0] = 0x18;
                buf[1] = gPlayers[0].character;
                buf[2] = 0;
                MBDlgWinInsertCreateY(0x29, 0x5D9, buf, NULL, NULL, NULL, NULL, 0xAA);
                MBDlgWinClose();
                func_80056168_56D68();
                return;
            }
        }
    }
    MBDlgWinExecY(0x29, D_80106270_3EF620_name_66[D_800FD8A8_FE4A8.difficulty], 0xAA);
}

void func_801030B8_3EC468_name_66(s32 sign) {
    s16 size[2];
    s32 win;
    s32 name;

    if (func_80075390_75F90(sign + OVL66_FLAG_BASE) == 0) {
        name = func_800734B0_740B0(sign) + 0x3D8;
        func_8008D9D0_8E5D0(name, 0);
        func_8008DACC_8E6CC(1, size, 0x5C5);
        win = MBWinCreate(-1, size, 0xAA);
        mbDlgWinId = win;
        win = (s16)win;
        func_8008D904_8E504(win, name, 0);
        func_800890CC_89CCC(win, (void*)0x5C5, -1, -1);
        func_8008E978_8F578(win);
        func_80055A38_56638(win, GwSystem.current_player_index);
        while (1) {
            if (ContBtnTrg[gPlayers[0].port] & 0x8000) {
                break;
            }
            HuPrcVSleep();
        }
        MBDlgWinClose();
        func_80056168_56D68();
        func_8007501C_75C1C();
    }
}

void func_801031D0_3EC580_name_66(void) {
    D_800FD8A8_FE4A8.stage = OVL66_STAGE;
    omInitObjMan(10, 0);
    omOvlGotoEx(OVL66_NEXT_SCENE, OVL66_NEXT_ENTRY, 0x192);
}

void func_8010320C_3EC5BC_name_66(void) {
    omInitObjMan(10, 0);
    SetPlayerOntoChain(0, 2, 0);
    func_80075424_76024(OVL66_FLAG_BASE + 9);
    func_80075424_76024(OVL66_FLAG_BASE + 10);
    func_80075424_76024(OVL66_FLAG_BASE + 11);
    func_80075424_76024(OVL66_FLAG_BASE + 12);
    func_800753D4_75FD4(OVL66_FLAG_BASE + 8);
    func_80073410_74010(-1);
    omOvlReturnEx(1);
}

void func_80103274_3EC624_name_66(void) {
    omInitObjMan(0x50, 0x28);
    func_80020070_20C70(2);
    func_80026D28_27928(1);
    func_80026DAC_279AC(0, 0x78, 0x78, 0x78);
    func_80026DAC_279AC(1, 0x40, 0x40, 0x60);
    func_80026E00_27A00(1, -100.0f, 100.0f, 300.0f);
    func_80074154_74D54(OVL66_BOARD_MODEL, OVL66_BOARD_FILE);
    EventTableHydrate(D_80106318_3EF6C8_name_66);
    func_80102830_3EBBE0_name_66();
}

void func_80103300_3EC6B0_name_66(void) {
    func_80103274_3EC624_name_66();
    func_80074DB8_759B8(0);
    PlayMusic(OVL66_MUSIC);
}

void func_8010332C_3EC6DC_name_66(void) {
    func_80073410_74010(9);
    func_801030B8_3EC468_name_66(9);
}

void func_80103350_3EC700_name_66(void) {
    func_80073410_74010(10);
    func_801030B8_3EC468_name_66(10);
}

void func_80103374_3EC724_name_66(void) {
    func_80073410_74010(11);
    func_801030B8_3EC468_name_66(11);
}

void func_80103398_3EC748_name_66(void) {
    func_80073410_74010(12);
    func_801030B8_3EC468_name_66(12);
}

void func_801033BC_3EC76C_name_66(void) {
    func_80073410_74010(-2);
    func_80102CE4_3EC094_name_66();
}

/* The event at the fork: on difficulty 0 the dialog and the other chain. */
void func_801033E0_3EC790_name_66(void) {
    if (D_800FD8A8_FE4A8.difficulty == 0) {
        PlaySound(0x11E);
        MBDlgWinExec(0x29, 0x5CB);
        SetNextChainAndSpace(-1, 1, 0);
    } else {
        SetNextChainAndSpace(-1, 0, 0);
    }
}

void func_80103430_3EC7E0_name_66(void) {
    func_80074FAC_75BAC(8, 0, 1, 0);
}

void func_80103458_3EC808_name_66(void) {
    func_80074FAC_75BAC(3, 0, 1, 1);
}

/* masked 6, raw 86: s7/s8 swap, and retail places the 0xD0005 arm of the file choice inline with
   0xD0004 as the shared join; the inverted test and a nested if both turn it into a branchless
   sign mask (masked 28-29), a ternary changes nothing. */
#ifdef NON_MATCHING
void func_80103480_3EC830_name_66(void) {
    s16 cnt[4];
    s16 digits[2][4];
    s16 val[2];
    s32 spr;
    s16 i;
    s16 j;
    s16 k;
    s32 file;
    void* data;

    D_80106490_3EF840_name_66 = (s16)func_800888A8_894A8(0, 0, 0x140, 0xF0, 0, 4);
    func_80089B2C_8A72C((s16)D_80106490_3EF840_name_66, 0xC8);
    func_8008D530_8E130((s16)D_80106490_3EF840_name_66, 0, 0, 0);
    D_801064A0_3EF850_name_66 = SprCreate(3, 5);
    SprPosSet((s16)D_801064A0_3EF850_name_66, 0, 0, 0);
    data = DataRead(D_80106360_3EF710_name_66[D_80106494_3EF844_name_66][0]);
    i = 0;
    D_801064A4_3EF854_name_66 = SprAnimRead(data);
    DataClose(data);
    SprAnimSet((s16)D_801064A0_3EF850_name_66, 1, (s16)D_801064A4_3EF854_name_66, 0);
    func_8008225C_82E5C((s16)D_801064A0_3EF850_name_66, 1, 1);
    SprPrioSet((s16)D_801064A0_3EF850_name_66, 1, 0x10);
    SprAttrSet((s16)D_801064A0_3EF850_name_66, 1, 0x9000);
    SprPosSet((s16)D_801064A0_3EF850_name_66, 1, 0xA0, 0xAA);
    func_8008221C_82E1C((s16)D_801064A0_3EF850_name_66, 1, 0.0f);
    D_801064AC_3EF85C_name_66 = SprCreate(3, 5);
    SprPosSet((s16)D_801064AC_3EF85C_name_66, 0, 0, 0);
    data = DataRead(D_80106370_3EF720_name_66[0]);
    D_801064B0_3EF860_name_66 = SprAnimRead(data);
    DataClose(data);
    SprAnimSet((s16)D_801064AC_3EF85C_name_66, 1, (s16)D_801064B0_3EF860_name_66, 0);
    func_8008225C_82E5C((s16)D_801064AC_3EF85C_name_66, 1, 1);
    SprPrioSet((s16)D_801064AC_3EF85C_name_66, 1, 0x10);
    SprAttrSet((s16)D_801064AC_3EF85C_name_66, 1, 0x9000);
    SprPosSet((s16)D_801064AC_3EF85C_name_66, 1, 0xA0, 0xA0);
    func_8008221C_82E1C((s16)D_801064A0_3EF850_name_66, 1, 0.0f);
    val[0] = D_800FD8A8_FE4A8.lives - D_80106498_3EF848_name_66;
    val[1] = gPlayers[0].coins_mg_bonus + gPlayers[0].coins_mg;
    for (; i < 2; i++) {
        digits[i][0] = OVL66_ABS(val[i]) / 1000;
        digits[i][1] = (OVL66_ABS(val[i]) - digits[i][0] * 1000) / 100;
        digits[i][2] = (OVL66_ABS(val[i]) - digits[i][0] * 1000 - digits[i][1] * 100) / 10;
        digits[i][3] = OVL66_ABS(val[i]) - digits[i][0] * 1000 - digits[i][1] * 100 - digits[i][2] * 10;
        cnt[i] = 0;
        if (OVL66_ABS(val[i]) >= 10) {
            cnt[i] = 1;
        }
        if (OVL66_ABS(val[i]) >= 100) {
            cnt[i] = 2;
        }
        if (OVL66_ABS(val[i]) >= 1000) {
            cnt[i] = 3;
        }
    }
    for (i = 0; i < 2; i++) {
        j = 0;
        spr = SprCreate(7, 5);
        D_801064F0_3EF8A0_name_66[i] = spr;
        if (i == 0 || val[i] < 0) {
            file = 0xD0004;
        } else {
            file = 0xD0005;
        }
        data = DataRead(file);
        D_801064B8_3EF868_name_66[i] = SprAnimRead(data);
        DataClose(data);
        SprAnimSet(spr, j, (s16)D_801064B8_3EF868_name_66[i], 0);
        func_800824F4_830F4(spr, j, -1);
        SprAttrSet(spr, j, 0x8000);
        SprPosSet(spr, j, D_80106380_3EF730_name_66[i][0], D_80106380_3EF730_name_66[i][1]);
        j++;
        SprAnimSet(spr, j, (s16)D_801064B8_3EF868_name_66[i], 0);
        func_8008225C_82E5C(spr, j, 1);
        SprPrioSet(spr, j, 0xF);
        SprAttrSet(spr, j, 0x9000);
        SprPosSet(spr, j, 0, 0);
        func_800824F4_830F4(spr, j, 0);
        j++;
        for (k = 0; k < 4; k++, j++) {
            data = DataRead(0xC000D);
            D_801064D0_3EF880_name_66[i][k] = SprAnimRead(data);
            DataClose(data);
            SprAnimSet(spr, j, (s16)D_801064D0_3EF880_name_66[i][k], 0);
            func_8008225C_82E5C(spr, j, 1);
            SprPrioSet(spr, j, 0xE);
            SprAttrSet(spr, j, 0x9000);
            func_800822A8_82EA8(spr, j, digits[i][k], 0);
            func_800824F4_830F4(spr, j, 0);
            func_8008221C_82E1C(spr, j, 0.0f);
            if (i == 0) {
                if (val[i] == 0) {
                    SprPosSet(spr, j, D_80106388_3EF738_name_66[cnt[i]][k], 2);
                } else {
                    SprPosSet(spr, j, D_80106388_3EF738_name_66[cnt[i]][k] + 4, 2);
                }
            } else if (D_80106494_3EF844_name_66 == 0) {
                if (val[i] == 0) {
                    SprPosSet(spr, j, D_80106388_3EF738_name_66[cnt[i]][k], 2);
                } else {
                    SprPosSet(spr, j, D_80106388_3EF738_name_66[cnt[i]][k] + 4, 2);
                }
            } else {
                func_80082450_83050(spr, j, 0xFF, 0, 0);
                SprPosSet(spr, j, D_80106388_3EF738_name_66[cnt[i]][k], 2);
            }
        }
        data = DataRead(0xC000D);
        D_801064C4_3EF874_name_66[i] = SprAnimRead(data);
        DataClose(data);
        SprAnimSet(spr, j, (s16)D_801064C4_3EF874_name_66[i], 0);
        func_8008225C_82E5C(spr, j, 1);
        SprPrioSet(spr, j, 0xE);
        SprAttrSet(spr, j, 0x9000);
        func_800824F4_830F4(spr, j, 0);
        func_8008221C_82E1C(spr, j, 0.0f);
        if (i == 0) {
            if (val[i] == 0) {
                SprPosSet(spr, j, -1000, 2);
                func_800822A8_82EA8(spr, j, 10, 0);
            } else {
                if (val[i] > 0) {
                    func_800822A8_82EA8(spr, j, 11, 0);
                } else {
                    func_800822A8_82EA8(spr, j, 12, 0);
                }
                SprPosSet(spr, j, D_80106388_3EF738_name_66[cnt[i]][3 - cnt[i]] - 4, 2);
            }
        } else if (D_80106494_3EF844_name_66 == 0) {
            if (val[i] == 0) {
                SprPosSet(spr, j, -1000, 2);
                func_800822A8_82EA8(spr, j, 10, 0);
            } else {
                if (val[i] > 0) {
                    func_800822A8_82EA8(spr, j, 11, 0);
                } else {
                    func_800822A8_82EA8(spr, j, 12, 0);
                }
                SprPosSet(spr, j, D_80106388_3EF738_name_66[cnt[i]][3 - cnt[i]] - 4, 2);
            }
        } else {
            SprPosSet(spr, j, -1000, 2);
            func_800822A8_82EA8(spr, j, 10, 0);
        }
    }
    spr = SprCreate(7, 5);
    D_801064F0_3EF8A0_name_66[2] = spr;
    data = DataRead(0xD0005);
    D_801064B8_3EF868_name_66[2] = SprAnimRead(data);
    DataClose(data);
    SprAnimSet(spr, 0, (s16)D_801064B8_3EF868_name_66[2], 0);
    func_800824F4_830F4(spr, 0, -1);
    SprAttrSet(spr, 0, 0x8000);
    SprPosSet(spr, 0, D_80106380_3EF730_name_66[0][0], D_80106380_3EF730_name_66[0][1]);
    SprAnimSet(spr, 1, (s16)D_801064B8_3EF868_name_66[2], 0);
    func_8008225C_82E5C(spr, 1, 1);
    SprPrioSet(spr, 1, 0xF);
    SprAttrSet(spr, 1, 0x9000);
    SprPosSet(spr, 1, 0, 0);
    func_800824F4_830F4(spr, 1, 0);
    data = DataRead(0xD0006);
    D_8010649C_3EF84C_name_66 = SprAnimRead(data);
    DataClose(data);
    SprAnimSet(spr, 2, (s16)D_8010649C_3EF84C_name_66, 0);
    func_8008225C_82E5C(spr, 2, 1);
    SprPrioSet(spr, 2, 0xE);
    SprAttrSet(spr, 2, 0x9000);
    func_800824F4_830F4(spr, 2, 0);
    SprPosSet(spr, 2, 0, 2);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_66_name/3EBBE0", func_80103480_3EC830_name_66);
#endif

void func_80104244_3ED5F4_name_66(void) {
    func_8008CCA8_8D8A8((s16)D_80106490_3EF840_name_66);
}

void func_80104264_3ED614_name_66(void) {
    Hu3DCamSetPerspective(1, 40.0f, 200.0f, 8000.0f);
    Hu3DCamSetPositionOrientation(1, &D_801064FC_3EF8AC_name_66, &D_80106508_3EF8B8_name_66, &D_80106514_3EF8C4_name_66);
    Hu3DCamUpdateMtx(1);
    CameraViewportSet(1, &D_80106520_3EF8D0_name_66, &D_8010652C_3EF8DC_name_66);
}

void func_801042CC_3ED67C_name_66(void) {
    while (1) {
        func_80104264_3ED614_name_66();
        HuPrcVSleep();       
    }
}

__asm__(".section .rodata");
const char D_80106408_3EF7B8_name_66[] = "point1";

__asm__(".section .rodata");
const char D_80106410_3EF7C0_name_66[] = "point2";

void func_801042F8_3ED6A8_name_66(void) {
    Vec v;

    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    HuVecCopyXYZ(&v, 0.0f, 0.0f, 0.0f);
    OVL66_LINK(func_80056D80_57980(&D_80106548_3EF8F8_name_66->pos, &v, &D_80106548_3EF8F8_name_66->pos, 20));
    HuPrcChildWatch();
    func_80029E80_2AA80(D_80106548_3EF8F8_name_66->obj->model[0], 2, 1);
    HuVecCopyXYZ(&D_80106540_3EF8F0_name_66->pos, -6.278950214385986f, 19.16754913330078f, 0.0f);
    HuVecCopyXYZ(&D_80106544_3EF8F4_name_66->pos, 5.623000144958496f, 19.16754913330078f, 0.0f);
    HuPrcVSleep();
    func_8005AA98_5B698(D_80106540_3EF8F0_name_66->obj->model[0]);
    func_8005AA98_5B698(D_80106544_3EF8F4_name_66->obj->model[0]);
    HuPrcVSleep();
    func_8005670C_5730C(&v);
    OVL66_LINK(func_80056B78_57778(&D_80106540_3EF8F0_name_66->rot, &v, &D_80106540_3EF8F0_name_66->rot, 10));
    OVL66_LINK(func_80056B78_57778(&D_80106544_3EF8F4_name_66->rot, &v, &D_80106544_3EF8F4_name_66->rot, 10));
    HuPrcChildWatch();
    if (D_80106494_3EF844_name_66 == 0) {
        MBMotionSet(D_80106540_3EF8F0_name_66, 6, 0);
        MBMotionSet(D_80106544_3EF8F4_name_66, 6, 0);
        func_800732B0_73EB0(D_801063B0_3EF760_name_66[(s8)D_800FD8A8_FE4A8.character] | 0x54);
    } else {
        MBMotionSet(D_80106540_3EF8F0_name_66, 3, 0);
        MBMotionSet(D_80106544_3EF8F4_name_66, 3, 0);
    }
    while (1) {
        if (D_8010637C_3EF72C_name_66 != 0) {
            MBMotionSet(D_80106540_3EF8F0_name_66, 5, 0);
            MBMotionSet(D_80106544_3EF8F4_name_66, 5, 0);
            HuPrcSleep(30);
            break;
        }
        if (D_8010637B_3EF72B_name_66 != 0) {
            break;
        }
        HuPrcVSleep();
    }
    MBMotionShiftSet(D_80106540_3EF8F0_name_66, -1, 0, 10, 2);
    MBMotionShiftSet(D_80106544_3EF8F4_name_66, -1, 0, 10, 2);
    HuVecCopyXYZ(&v, -1.0f, 0.0f, 0.0f);
    OVL66_LINK(func_80056B78_57778(&D_80106540_3EF8F0_name_66->rot, &v, &D_80106540_3EF8F0_name_66->rot, 10));
    OVL66_LINK(func_80056B78_57778(&D_80106544_3EF8F4_name_66->rot, &v, &D_80106544_3EF8F4_name_66->rot, 10));
    HuPrcChildWatch();
    func_8005AA48_5B648(D_80106548_3EF8F8_name_66, D_80106408_3EF7B8_name_66, D_80106540_3EF8F0_name_66->obj->model[0]);
    func_8005AA48_5B648(D_80106548_3EF8F8_name_66, D_80106410_3EF7C0_name_66, D_80106544_3EF8F4_name_66->obj->model[0]);
    func_80029E80_2AA80(D_80106548_3EF8F8_name_66->obj->model[0], 1, 2);
    HuVecCopyXYZ(&v, -100.0f, 0.0f, 0.0f);
    OVL66_LINK(func_80056D80_57980(&D_80106548_3EF8F8_name_66->pos, &v, &D_80106548_3EF8F8_name_66->pos, 20));
    HuPrcChildWatch();
    while (1) {
        HuPrcVSleep();
    }
}

void func_801046F8_3EDAA8_name_66(void) {
    D_80106538_3EF8E8_name_66 = omAddPrcObj(func_801042CC_3ED67C_name_66, 0x4000, 0, 0);
    D_801064FC_3EF8AC_name_66.x = 0.0f;
    D_801064FC_3EF8AC_name_66.y = 250.0f;
    D_801064FC_3EF8AC_name_66.z = 200.0f;
    D_80106508_3EF8B8_name_66.x = 0.0f;
    D_80106508_3EF8B8_name_66.y = 0.0f;
    D_80106508_3EF8B8_name_66.z = 0.0f;
    D_80106514_3EF8C4_name_66.x = 0.0f;
    D_80106514_3EF8C4_name_66.y = 1.0f;
    D_80106514_3EF8C4_name_66.z = 0.0f;
    D_80106520_3EF8D0_name_66.x = 1280.0f;
    D_80106520_3EF8D0_name_66.y = 960.0f;
    D_80106520_3EF8D0_name_66.z = 511.0f;
    D_8010652C_3EF8DC_name_66.x = 640.0f;
    D_8010652C_3EF8DC_name_66.y = 480.0f;
    D_8010652C_3EF8DC_name_66.z = 511.5f;
    func_80104264_3ED614_name_66();
    D_80106548_3EF8F8_name_66 = func_80043510_44110(0xAA, NULL);
    HuVecCopyXYZ(&D_80106548_3EF8F8_name_66->rot, -1.0f, 0.0f, 0.0f);
    HuVecCopyXYZ(&D_80106548_3EF8F8_name_66->pos, 100.0f, 0.0f, 0.0f);
    D_80106548_3EF8F8_name_66->attr |= 1;
    func_80029EDC_2AADC(D_80106548_3EF8F8_name_66->obj->model[0], 2);
    D_80106540_3EF8F0_name_66 = func_80043510_44110(D_801063A8_3EF758_name_66[(s8)D_800FD8A8_FE4A8.character], D_800CC8B8_CD4B8[(s8)D_800FD8A8_FE4A8.character]);
    HuVecCopyXYZ(&D_80106540_3EF8F0_name_66->rot, -1.0f, 0.0f, 0.0f);
    D_80106540_3EF8F0_name_66->attr |= 1;
    func_80029EDC_2AADC(D_80106540_3EF8F0_name_66->obj->model[0], 2);
    D_80106544_3EF8F4_name_66 = func_80043510_44110(D_801063A8_3EF758_name_66[(s8)D_800FD8A8_FE4A8.character2], D_800CC8B8_CD4B8[(s8)D_800FD8A8_FE4A8.character2]);
    HuVecCopyXYZ(&D_80106544_3EF8F4_name_66->rot, -1.0f, 0.0f, 0.0f);
    D_80106544_3EF8F4_name_66->attr |= 1;
    func_80029EDC_2AADC(D_80106544_3EF8F4_name_66->obj->model[0], 2);
    func_8005AA48_5B648(D_80106548_3EF8F8_name_66, D_80106408_3EF7B8_name_66, D_80106540_3EF8F0_name_66->obj->model[0]);
    func_8005AA48_5B648(D_80106548_3EF8F8_name_66, D_80106410_3EF7C0_name_66, D_80106544_3EF8F4_name_66->obj->model[0]);
    D_8010653C_3EF8EC_name_66 = omAddPrcObj(func_801042F8_3ED6A8_name_66, 0x4000, 0, 0);
}

void func_801049C4_3EDD74_name_66(void) {
    omDelPrcObj(D_80106538_3EF8E8_name_66);
    omDelPrcObj(D_8010653C_3EF8EC_name_66);
    MBModelKill(D_80106540_3EF8F0_name_66);
    MBModelKill(D_80106544_3EF8F4_name_66);
    MBModelKill(D_80106548_3EF8F8_name_66);
}

void func_80104A14_3EDDC4_name_66(void) {
    switch (D_80106494_3EF844_name_66) {
    case 0:
        HuPrcSleep(12);
        break;
    case 1:
        HuPrcSleep(12);
        func_80079718_7A318(0xFC, D_800FD8A8_FE4A8.character);
        break;
    }
    while (1) {
        HuPrcVSleep();
    }
}

void func_80104A80_3EDE30_name_66(s8 idx) {
    f32 scale;
    s32 i;
    s32 n = idx;

    i = 0;
    do {
        i++;
        SprAttrReset((s16)D_801064F0_3EF8A0_name_66[n], i, 0x8000);
    } while (i < 6);
    for (scale = 0.0f; scale < 1.0; scale += 0.3) {
        i = 0;
        do {
            i++;
            SprScaleSet((s16)D_801064F0_3EF8A0_name_66[n], i, scale, scale);
        } while (i < 6);
        if (D_80106378_3EF728_name_66 == 0) {
            HuPrcVSleep();
        }
    }
    i = 0;
    do {
        i++;
        SprScaleSet((s16)D_801064F0_3EF8A0_name_66[n], i, 1.0f, 1.0f);
    } while (i < 6);
}

void func_80104BC8_3EDF78_name_66(void) {
    f32 scale;
    s32 i;

    i = 0;
    do {
        i++;
        SprAttrReset((s16)D_801064F0_3EF8A0_name_66[0], i, 0x8000);
        SprAttrReset((s16)D_801064F0_3EF8A0_name_66[1], i, 0x8000);
    } while (i < 6);
    for (scale = 0.0f; scale < 1.0; scale += 0.3) {
        i = 0;
        do {
            i++;
            SprScaleSet((s16)D_801064F0_3EF8A0_name_66[0], i, scale, scale);
            SprScaleSet((s16)D_801064F0_3EF8A0_name_66[1], i, scale, scale);
        } while (i < 6);
        if (D_80106378_3EF728_name_66 == 0) {
            HuPrcVSleep();
        }
    }
    i = 0;
    do {
        i++;
        SprScaleSet((s16)D_801064F0_3EF8A0_name_66[0], i, 1.0f, 1.0f);
        SprScaleSet((s16)D_801064F0_3EF8A0_name_66[1], i, 1.0f, 1.0f);
    } while (i < 6);
}

void func_80104D48_3EE0F8_name_66(void) {
    f32 scale;
    s32 i;

    i = 0;
    do {
        i++;
        SprScaleSet((s16)D_801064F0_3EF8A0_name_66[0], i, 1.0f, 1.0f);
        SprScaleSet((s16)D_801064F0_3EF8A0_name_66[1], i, 1.0f, 1.0f);
    } while (i < 6);
    scale = 1.0f;
    do {
        i = 0;
        do {
            i++;
            SprScaleSet((s16)D_801064F0_3EF8A0_name_66[0], i, scale, scale);
            SprScaleSet((s16)D_801064F0_3EF8A0_name_66[1], i, scale, scale);
        } while (i < 6);
        if (D_80106378_3EF728_name_66 == 0) {
            HuPrcVSleep();
        }
        scale -= 0.3f;
    } while (scale > 0.0f);
    i = 0;
    do {
        i++;
        SprAttrSet((s16)D_801064F0_3EF8A0_name_66[0], i, 0x8000);
        SprAttrSet((s16)D_801064F0_3EF8A0_name_66[1], i, 0x8000);
    } while (i < 6);
}

#ifdef NON_MATCHING
void func_80104EC8_3EE278_name_66(void) {
    s16 val[4];
    s16 cnt[4];
    s16 digits[4][4];
    s32 i;
    s32 k;
    s32 j;

    val[0] = D_800FD8A8_FE4A8.lives - D_80106498_3EF848_name_66;
    if (D_800FD8A8_FE4A8.streak > 0) {
        val[1] = (gPlayers[0].coins_mg + gPlayers[0].coins_mg_bonus) * D_800FD8A8_FE4A8.streak - D_8010637E_3EF72E_name_66;
    } else {
        val[1] = gPlayers[0].coins_mg + gPlayers[0].coins_mg_bonus - D_8010637E_3EF72E_name_66;
    }
    for (i = 0; i < 2; i++) {
        digits[i][0] = OVL66_ABS(val[i]) / 1000;
        digits[i][1] = (OVL66_ABS(val[i]) - digits[i][0] * 1000) / 100;
        digits[i][2] = (OVL66_ABS(val[i]) - digits[i][0] * 1000 - digits[i][1] * 100) / 10;
        digits[i][3] = OVL66_ABS(val[i]) - digits[i][0] * 1000 - digits[i][1] * 100 - digits[i][2] * 10;
        cnt[i] = 0;
        if (OVL66_ABS(val[i]) >= 10) {
            cnt[i] = 1;
        }
        if (OVL66_ABS(val[i]) >= 100) {
            cnt[i] = 2;
        }
        if (OVL66_ABS(val[i]) >= 1000) {
            cnt[i] = 3;
        }
    }
    for (i = 0; i < 2; i++) {
        j = 2;
        for (k = 0; k < 4; k++, j++) {
            func_800822A8_82EA8((s16)D_801064F0_3EF8A0_name_66[i], j, digits[i][k], 0);
            if (i == 0) {
                if (val[i] == 0) {
                    SprPosSet((s16)D_801064F0_3EF8A0_name_66[i], j, D_801063C8_3EF778_name_66[cnt[i]][k], 2);
                } else {
                    SprPosSet((s16)D_801064F0_3EF8A0_name_66[i], j, D_801063C8_3EF778_name_66[cnt[i]][k] + 4, 2);
                }
            } else if (D_80106494_3EF844_name_66 == 0 && val[i] != 0) {
                SprPosSet((s16)D_801064F0_3EF8A0_name_66[i], j, D_801063C8_3EF778_name_66[cnt[i]][k] + 4, 2);
            } else {
                SprPosSet((s16)D_801064F0_3EF8A0_name_66[i], j, D_801063C8_3EF778_name_66[cnt[i]][k], 2);
            }
        }
        if (i == 0) {
            if (val[i] == 0) {
                SprPosSet((s16)D_801064F0_3EF8A0_name_66[i], j, -1000, -2);
                func_800822A8_82EA8((s16)D_801064F0_3EF8A0_name_66[i], j, 10, 0);
            } else {
                if (val[i] > 0) {
                    func_800822A8_82EA8((s16)D_801064F0_3EF8A0_name_66[i], j, 11, 0);
                } else {
                    func_800822A8_82EA8((s16)D_801064F0_3EF8A0_name_66[i], j, 12, 0);
                }
                SprPosSet((s16)D_801064F0_3EF8A0_name_66[i], j, D_801063C8_3EF778_name_66[cnt[i]][3 - cnt[i]] - 4, 2);
            }
        } else if (D_80106494_3EF844_name_66 == 0 && val[i] != 0) {
            if (val[i] > 0) {
                func_800822A8_82EA8((s16)D_801064F0_3EF8A0_name_66[i], j, 11, 0);
            } else {
                func_800822A8_82EA8((s16)D_801064F0_3EF8A0_name_66[i], j, 12, 0);
            }
            SprPosSet((s16)D_801064F0_3EF8A0_name_66[i], j, D_801063C8_3EF778_name_66[cnt[i]][3 - cnt[i]] - 4, 2);
        } else {
            SprPosSet((s16)D_801064F0_3EF8A0_name_66[i], j, -1000, -2);
            func_800822A8_82EA8((s16)D_801064F0_3EF8A0_name_66[i], j, 10, 0);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_66_name/3EBBE0", func_80104EC8_3EE278_name_66);
#endif

void func_80105550_3EE900_name_66(void) {
    u16 coins;
    s32 step;
    s8 n;

    coins = (gPlayers[0].coins_mg_bonus + gPlayers[0].coins_mg) * D_800FD8A8_FE4A8.streak;
    if ((s16)coins < 31) {
        step = (s16)coins < 0 ? -1 : 1;
    } else if ((s16)coins >= 0) {
        step = (s16)coins >= 100 ? 4 : 2;
    } else {
        step = (s16)coins / 30.0f - 0.5f;
    }
    n = 0;
    while ((s16)coins > D_8010637E_3EF72E_name_66) {
        D_8010637E_3EF72E_name_66 += step;
        if ((s16)coins <= D_8010637E_3EF72E_name_66) {
            D_800FD8A8_FE4A8.coins += step - ((u8)D_8010637E_3EF72E_name_66 - coins);
            D_8010637E_3EF72E_name_66 = coins;
            break;
        }
        D_800FD8A8_FE4A8.coins = step + D_800FD8A8_FE4A8.coins;
        if (D_800FD8A8_FE4A8.coins >= 100) {
            if (D_800FD8A8_FE4A8.lives >= 99) {
                D_800FD8A8_FE4A8.coins = 99;
                D_800FD8A8_FE4A8.lives = 99;
            } else {
                D_800FD8A8_FE4A8.coins -= 100;
                D_800FD8A8_FE4A8.lives++;
                if (D_800FD8A8_FE4A8.lives >= 100) {
                    D_800FD8A8_FE4A8.lives = 99;
                }
                func_80104A80_3EDE30_name_66(2);
                PlaySound(0x18);
            }
        }
        if ((s16)coins > 0) {
            if (n < 2) {
                PlaySound(9);
            }
            n++;
            if (n >= 3) {
                n = 0;
            }
        }
        func_80104EC8_3EE278_name_66();
        HuPrcVSleep();
    }
    if (D_800FD8A8_FE4A8.coins >= 100) {
        if (D_800FD8A8_FE4A8.lives >= 99) {
            D_800FD8A8_FE4A8.coins = 99;
            D_800FD8A8_FE4A8.lives = 99;
        } else {
            D_800FD8A8_FE4A8.coins -= 100;
            D_800FD8A8_FE4A8.lives++;
            if (D_800FD8A8_FE4A8.lives >= 100) {
                D_800FD8A8_FE4A8.lives = 99;
            }
            PlaySound(0x18);
            func_80104A80_3EDE30_name_66(2);
        }
    }
    func_80104EC8_3EE278_name_66();
}

void func_80105828_3EEBD8_name_66(void) {
    s16 size[2];
    s32 win;
    s8 choice;

    SprAttrSet((s16)D_801064A0_3EF850_name_66, 1, 0x8000);
    HuPrcSleep(30);
    PlayMusic(0x14);
    SprAttrReset((s16)D_801064AC_3EF85C_name_66, 1, 0x8000);
    func_8008DACC_8E6CC(1, size, 0x5E2);
    win = func_800888A8_894A8(0xA0 - size[0] / 2, 0xAA, size[0], size[1], 0, 0);
    func_800890CC_89CCC(win, (void*)0x5E2, -1, -1);
    func_80089B2C_8A72C(win, 0);
    func_800890CC_89CCC(win, (void*)0x5E2, -1, -1);
    func_80089A48_8A648(win, 0);
    while (func_8008BA30_8C630(win) != 0) {
        HuPrcVSleep();
    }
    func_8008D59C_8E19C(win, 1);
    func_8008D07C_8DC7C(-1, 0, 0, 0);
    choice = func_8008BB48_8C748(win, 0, 1);
    if (choice == 0) {
        D_8010637C_3EF72C_name_66 = 1;
        HuPrcSleep(30);
    }
    D_8010637A_3EF72A_name_66 = choice;
    D_80106379_3EF729_name_66 = 1;
}

void func_801059A8_3EED58_name_66(void) {
    s16 size[2];
    char buf[8];
    GAMEMES mesX;
    GAMEMES mesN;
    s16 win;

    if (D_800FD8A8_FE4A8.streak >= 2) {
        sprintf(buf, D_80106404_3EF7B4_name_66, D_800FD8A8_FE4A8.streak);
        func_8008D974_8E574(buf, 0);
        func_8008DACC_8E6CC(1, size, 0x5E3);
        win = func_800888A8_894A8(0x104 - size[0] / 2, 0x50, size[0], size[1], 0, 0);
        func_80089308_89F08(win, buf, 0);
        func_800890CC_89CCC(win, (void*)0x5E3, -1, -1);
        func_80089B2C_8A72C(win, 0);
        func_80089A48_8A648(win, 0);
        PlaySound(0x355);
        HuPrcSleep(0x19);
        func_8008CCA8_8D8A8(win);
        func_8006A608_6B208(&mesX, "X", 0, -1, -1);
        SprPosSet(mesX.strGId[0], 0, 0xFA, 0x46);
        func_8006A608_6B208(&mesN, buf, 0, -1, -1);
        if (D_800FD8A8_FE4A8.streak < 10) {
            SprPosSet(mesN.strGId[0], 0, 0x10A, 0x46);
        } else {
            SprPosSet(mesN.strGId[0], 0, 0x112, 0x46);
        }
        HuPrcSleep(0x19);
        func_8006985C_6A45C(&mesX);
        func_8006985C_6A45C(&mesN);
        func_80104EC8_3EE278_name_66();
        PlaySound(0x33D);
        HuPrcSleep(0x19);
    }
}

void func_80105B58_3EEF08_name_66(void) {
    s16 i;
    s16 failed;

    switch (D_80106494_3EF844_name_66) {
    case 0:
        HuPrcSleep(0x24);
        func_80079428_7A028(0x44);
        break;
    case 1:
        HuPrcSleep(0x24);
        func_80079428_7A028(0x45);
        break;
    }
    SprAttrReset((s16)D_801064A0_3EF850_name_66, 1, 0x8000);
    omAddPrcObj(func_80104A14_3EDDC4_name_66, 0x300, 0x2500, 0);
    HuPrcSleep(0x3C);
    if (D_80106494_3EF844_name_66 == 0) {
        HuPrcSleep(30);
    } else {
        HuPrcSleep(20);
    }
    failed = 0;
    switch (D_80106494_3EF844_name_66) {
    case 0:
        func_80104A80_3EDE30_name_66(1);
        for (i = 0; i < 30; i++) {
            if (D_80106378_3EF728_name_66 == 1) {
                break;
            }
            HuPrcVSleep();
        }
        func_801059A8_3EED58_name_66();
        func_80105550_3EE900_name_66();
        goto done;
    case 1:
        if (D_800FD8A8_FE4A8.lives <= 0) {
            failed = 1;
        }
        D_800FD8A8_FE4A8.lives--;
        func_80104EC8_3EE278_name_66();
        if (D_800FD8A8_FE4A8.lives < 0) {
            D_800FD8A8_FE4A8.lives = 0;
        }
        func_80104BC8_3EDF78_name_66();
        for (i = 0; i < 30; i++) {
            if (D_80106378_3EF728_name_66 == 1) {
                break;
            }
            HuPrcVSleep();
        }
    done:
        func_80104D48_3EE0F8_name_66();
        break;
    }
    if (failed != 0) {
        func_80105828_3EEBD8_name_66();
    } else {
        D_8010637B_3EF72B_name_66 = 1;
    }
}

s32 func_80105D34_3EF0E4_name_66(s16 minigame) {
    s32 total;

    total = gPlayers[0].coins_mg_bonus + gPlayers[0].coins_mg;
    switch (minigame) {
    case 0x24:
        if (total < D_801063E8_3EF798_name_66[0][D_800FD8A8_FE4A8.difficulty]) {
            return 0;
        }
        break;
    case 0x47:
        if (total < D_801063E8_3EF798_name_66[1][D_800FD8A8_FE4A8.difficulty]) {
            return 0;
        }
        break;
    case 0x48:
        if (total < D_801063E8_3EF798_name_66[2][D_800FD8A8_FE4A8.difficulty]) {
            return 0;
        }
        break;
    default:
        if (gPlayers[0].coins_mg_bonus < 10) {
            return 0;
        }
        break;
    }
    return 1;
}

void func_80105E00_3EF1B0_name_66(void) {
    s32 i;
    s32 j;

    SprKill((s16)D_801064A0_3EF850_name_66);
    SprKill((s16)D_801064AC_3EF85C_name_66);
    for (i = 0; i < 3; i++) {
        SprKill((s16)D_801064F0_3EF8A0_name_66[i]);
        SprAnimKill((s16)D_801064B8_3EF868_name_66[i]);
    }
    SprAnimKill((s16)D_8010649C_3EF84C_name_66);
    for (i = 0; i < 2; i++) {
        SprAnimKill((s16)D_801064C4_3EF874_name_66[i]);
        for (j = 0; j < 4; j++) {
            SprAnimKill((s16)D_801064D0_3EF880_name_66[i][j]);
        }
    }
    SprAnimKill((s16)D_801064A4_3EF854_name_66);
    SprAnimKill((s16)D_801064B0_3EF860_name_66);
}

void func_80105F18_3EF2C8_name_66(void) {
    func_80028334_28F34(D_800FD2A6_FDEA6, 2);
    func_80029EDC_2AADC(D_800FD2A6_FDEA6, 1);
    if (func_80105D34_3EF0E4_name_66(GwSystem.chosenMinigameIndex) != 0) {
        D_80106494_3EF844_name_66 = 0;
        _SetFlag(0x16);
        D_800FD8A8_FE4A8.streak++;
        PlayMusic(0x42);
    } else {
        D_80106494_3EF844_name_66 = 1;
        _ClearFlag(0x16);
        D_800FD8A8_FE4A8.streak = 0;
        PlayMusic(0x43);
    }
    D_80106496_3EF846_name_66 = D_800FD8A8_FE4A8.coins;
    D_80106498_3EF848_name_66 = D_800FD8A8_FE4A8.lives;
    func_80103480_3EC830_name_66();
    func_801046F8_3EDAA8_name_66();
    func_80029E80_2AA80(D_800FA618_FB218->obj->model[0], 2, 1);
    func_80029E80_2AA80(((MBModel*)gPlayers[0].unk_24)->obj->model[0], 2, 1);
    func_80029E80_2AA80(((MBModel*)gPlayers[1].unk_24)->obj->model[0], 2, 1);
    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    func_80105B58_3EEF08_name_66();
    HuPrcSleep(30);
    func_800794A8_7A0A8(0x5A);
    InitFadeOut(0, 0x10);
    HuPrcSleep(0x11);
    func_80104244_3ED5F4_name_66();
    func_801049C4_3EDD74_name_66();
    func_80105E00_3EF1B0_name_66();
    switch (D_8010637A_3EF72A_name_66) {
    case 0:
        func_800740B8_74CB8();
        break;
    case 1:
        func_800740AC_74CAC();
        break;
    }
    func_80028334_28F34(D_800FD2A6_FDEA6, 6);
    func_800744C0_750C0();
    omOvlReturnEx(1);
    omOvlKill();
    HuPrcVSleep();
}

void func_80106118_3EF4C8_name_66(void) {
    func_80103274_3EC624_name_66();
    func_80074DB8_759B8(1);
    omAddPrcObj(func_80105F18_3EF2C8_name_66, 0x1005, 0x1000, 0);
}

void func_80106154_3EF504_name_66(void) {
    if (func_80075390_75F90(OVL66_FLAG_BASE + 12) != 0) {
        SetPlayerOntoChain(0, 2, 17);
    } else if (func_80075390_75F90(OVL66_FLAG_BASE + 11) != 0) {
        SetPlayerOntoChain(0, 2, 13);
    } else if (func_80075390_75F90(OVL66_FLAG_BASE + 10) != 0) {
        SetPlayerOntoChain(0, 2, 10);
    } else if (func_80075390_75F90(OVL66_FLAG_BASE + 9) != 0) {
        SetPlayerOntoChain(0, 2, 3);
    } else {
        SetPlayerOntoChain(0, 2, 0);
    }
    omOvlReturnEx(1);
}

/* .data (0x3EF5A0) */
board_overlay_entrypoint D_801061F0_3EF5A0_name_66[6] = {
    { 0, func_801031D0_3EC580_name_66 }, { 1, func_8010320C_3EC5BC_name_66 }, { 2, func_80103300_3EC6B0_name_66 }, { 3, func_80106118_3EF4C8_name_66 }, { 4, func_80106154_3EF504_name_66 }, { -1, NULL },
};
CoasterSpaceFlag D_80106220_3EF5D0_name_66[5] = { { 0, 18 }, { 1, 19 }, { 2, 20 }, { 3, 21 }, { -1, -1 } };
s32 D_80106234_3EF5E4_name_66[6] = { 0x000A010F, 0x000A0110, 0x000A0111, 0x000A0112, 0x000A0113, 0x000A0114 };
s32 D_8010624C_3EF5FC_name_66[6] = { 0x000005DA, 0x000005DB, 0x000005DC, 0x000005DD, 0x00000000, 0x000005E1 };
s32 D_80106264_3EF614_name_66[3] = { 0x000005DE, 0x000005DF, 0x000005E0 };
s32 D_80106270_3EF620_name_66[3] = { 0x000005D2, 0x000005D4, 0x000005D6 };
s16 D_8010627C_3EF62C_name_66[4][2] = { { 100, 60 }, { 100, 78 }, { 100, 96 }, { 100, 114 } };
s16 D_8010628C_3EF63C_name_66 = 200;
s16 D_8010628E_3EF63E_name_66 = 60;
s16 D_80106290_3EF640_name_66 = 200;
s16 D_80106292_3EF642_name_66 = 78;
s16 D_80106294_3EF644_name_66[2] = { 24, 60 };
BoardEventListEntry D_80106298_3EF648_name_66[2] = { { 1, 1, func_8010332C_3EC6DC_name_66 }, { 0, 0, NULL } };
BoardEventListEntry D_801062A8_3EF658_name_66[2] = { { 1, 1, func_80103350_3EC700_name_66 }, { 0, 0, NULL } };
BoardEventListEntry D_801062B8_3EF668_name_66[2] = { { 1, 1, func_80103374_3EC724_name_66 }, { 0, 0, NULL } };
BoardEventListEntry D_801062C8_3EF678_name_66[2] = { { 1, 1, func_80103398_3EC748_name_66 }, { 0, 0, NULL } };
BoardEventListEntry D_801062D8_3EF688_name_66[2] = { { 1, 1, func_801033BC_3EC76C_name_66 }, { 0, 0, NULL } };
BoardEventListEntry D_801062E8_3EF698_name_66[2] = { { 1, 1, func_801033E0_3EC790_name_66 }, { 0, 0, NULL } };
BoardEventListEntry D_801062F8_3EF6A8_name_66[2] = { { 1, 1, func_80103430_3EC7E0_name_66 }, { 0, 0, NULL } };
BoardEventListEntry D_80106308_3EF6B8_name_66[2] = { { 1, 1, func_80103458_3EC808_name_66 }, { 0, 0, NULL } };
BoardEventTableEntry D_80106318_3EF6C8_name_66[9] = { { 0, D_80106298_3EF648_name_66 }, { 1, D_801062A8_3EF658_name_66 }, { 2, D_801062B8_3EF668_name_66 }, { 3, D_801062C8_3EF678_name_66 }, { 4, D_801062D8_3EF688_name_66 }, { 6, D_801062E8_3EF698_name_66 }, { 7, D_801062F8_3EF6A8_name_66 }, { 9, D_80106308_3EF6B8_name_66 }, { -1, NULL } };
s32 D_80106360_3EF710_name_66[2][2] = { { 0x000D0000, 0x000D0001 }, { 0x000B00E1, 0x000B00E2 } };
s32 D_80106370_3EF720_name_66[2] = { 0x000D0002, 0x000D0003 };
s8 D_80106378_3EF728_name_66 = 0;
s8 D_80106379_3EF729_name_66 = 0;
s8 D_8010637A_3EF72A_name_66 = -1;
s8 D_8010637B_3EF72B_name_66 = 0;
s8 D_8010637C_3EF72C_name_66 = 0;
s8 D_8010637D_pad_66 = 0; /* padding */
s16 D_8010637E_3EF72E_name_66 = 0;
s16 D_80106380_3EF730_name_66[2][2] = { { 80, 52 }, { 264, 52 } };
s16 D_80106388_3EF738_name_66[4][4] = {
    { -1000, -1000, -1000, 0 }, { -1000, -1000, -4, 4 }, { -1000, -8, 0, 8 }, { -14, -6, 2, 10 },
};
u8 D_801063A8_3EF758_name_66[8] = { 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x00, 0x00 };
s32 D_801063B0_3EF760_name_66[6] = { 0x00020000, 0x00030000, 0x00070000, 0x00040000, 0x00050000, 0x00060000 };
s16 D_801063C8_3EF778_name_66[4][4] = {
    { -1000, -1000, -1000, 0 }, { -1000, -1000, -4, 4 }, { -1000, -8, 0, 8 }, { -14, -6, 2, 10 },
};
u8 D_801063E8_3EF798_name_66[3][3] = { { 0, 0xA, 0xF }, { 0, 0xA, 0xF }, { 0, 0, 0xF } };
s8 D_801063F1_pad0_66 = 0; /* padding to .rodata */
s8 D_801063F2_pad1_66 = 0; /* padding to .rodata */
s8 D_801063F3_pad2_66 = 0; /* padding to .rodata */
s32 D_801063F4_pad_66[3] = { 0, 0, 0 };
