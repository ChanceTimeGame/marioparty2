#include "common.h"
#include "ovl_69.h"

#define OVL69_ABS(x) ((x) < 0 ? -(s32)(x) : (x))
/* Waits on a mover: makes it a child of the current process. */
#define OVL69_LINK(call) do { Process* _p = (call); HuPrcChildLink(HuPrcCurrentGet(), _p); } while (0)

void func_80102830_3F7160_name_69(void) {
    CoasterSpaceFlag* entry;

    entry = D_801062C0_3FABF0_name_69;
    while (entry->space >= 0) {
        if (func_80075390_75F90(entry->flag) != 0) {
            BoardSpaceTypeSet(entry->space, 1);
        }
        entry++;
    }
}

s32 func_8010288C_3F71BC_name_69(s32 bit) {
    return D_80106510_3FAE40_name_69.flags[bit / 8] & (1 << (bit % 8));
}

__asm__(".section .rodata");
const char D_801064D0_3FAE00_name_69[] = "%2d";

void func_801028D0_3F7200_name_69(void) {
    s16 size[2];
    void* data;
    s32 i;
    s32 win;

    D_80106544_3FAE74_name_69 = func_8005E688_5F288(1, 0);
    data = DataRead(D_801062DC_3FAC0C_name_69[(s8)D_80106510_3FAE40_name_69.character]);
    i = 0;
    D_80106544_3FAE74_name_69->unk0C[0] = SprAnimRead(data);
    SprAnimSet(D_80106544_3FAE74_name_69->unk0A, 0, D_80106544_3FAE74_name_69->unk0C[0], 0);
    SprPrioSet(D_80106544_3FAE74_name_69->unk0A, 0, 0x10);
    SprAttrSet(D_80106544_3FAE74_name_69->unk0A, 0, 0x1000);
    SprPosSet(D_80106544_3FAE74_name_69->unk0A, 0, 0x3E, 0x5F);
    DataClose(data);
    D_80106528_3FAE58_name_69[6] = func_80057480_58080(D_8010633C_3FAC6C_name_69[0], D_8010633C_3FAC6C_name_69[1], 0x18, 5);
    for (; i < 4; i++) {
        func_8008DACC_8E6CC(1, size, D_801062F4_3FAC24_name_69[i]);
        D_80106528_3FAE58_name_69[i] = (s16)func_800888A8_894A8(D_80106324_3FAC54_name_69[i][0], D_80106324_3FAC54_name_69[i][1], size[0], size[1], 0, 0);
        func_80089B2C_8A72C((s16)D_80106528_3FAE58_name_69[i], 0);
        func_80089A48_8A648((s16)D_80106528_3FAE58_name_69[i], 0);
        func_800890CC_89CCC((s16)D_80106528_3FAE58_name_69[i], (void*)D_801062F4_3FAC24_name_69[i], -1, -1);
    }
    func_8008DACC_8E6CC(1, size, D_8010630C_3FAC3C_name_69[D_80106510_3FAE40_name_69.difficulty]);
    i = 4;
    D_80106528_3FAE58_name_69[i] = (s16)func_800888A8_894A8(D_80106334_3FAC64_name_69, D_80106336_3FAC66_name_69, size[0], size[1], 0, 0);
    func_80089B2C_8A72C((s16)D_80106528_3FAE58_name_69[i], 0);
    func_80089A48_8A648((s16)D_80106528_3FAE58_name_69[i], 0);
    func_800890CC_89CCC((s16)D_80106528_3FAE58_name_69[i], (void*)D_8010630C_3FAC3C_name_69[D_80106510_3FAE40_name_69.difficulty], -1, -1);
    sprintf(D_80106548_3FAE78_name_69, D_801064D0_3FAE00_name_69, D_80106510_3FAE40_name_69.chapter);
    func_8008D974_8E574(D_80106548_3FAE78_name_69, 0);
    sprintf(D_80106550_3FAE80_name_69, D_801064D0_3FAE00_name_69, D_80106510_3FAE40_name_69.lives);
    func_8008D974_8E574(D_80106550_3FAE80_name_69, 1);
    sprintf(D_80106558_3FAE88_name_69, D_801064D0_3FAE00_name_69, D_80106510_3FAE40_name_69.coins);
    func_8008D974_8E574(D_80106558_3FAE88_name_69, 2);
    i = 5;
    func_8008DACC_8E6CC(1, size, D_801062F4_3FAC24_name_69[i]);
    win = func_800888A8_894A8(D_80106338_3FAC68_name_69, D_8010633A_3FAC6A_name_69, size[0], size[1] * 2, 0, 0);
    D_80106528_3FAE58_name_69[i] = win;
    D_800F920C_F9E0C[win].unk28 = 0x12;
    func_80089B2C_8A72C((s16)D_80106528_3FAE58_name_69[i], 0);
    func_80089A48_8A648((s16)D_80106528_3FAE58_name_69[i], 0);
    func_80089308_89F08((s16)D_80106528_3FAE58_name_69[i], D_80106548_3FAE78_name_69, 0);
    func_80089308_89F08((s16)D_80106528_3FAE58_name_69[i], D_80106550_3FAE80_name_69, 1);
    func_80089308_89F08((s16)D_80106528_3FAE58_name_69[i], D_80106558_3FAE88_name_69, 2);
    func_800890CC_89CCC((s16)D_80106528_3FAE58_name_69[i], (void*)D_801062F4_3FAC24_name_69[i], -1, -1);
}

void func_80102C88_3F75B8_name_69(void) {
    s32 i;

    for (i = 0; i < 7; i++) {
        func_8008CCA8_8D8A8((s16)D_80106528_3FAE58_name_69[i]);
    }
    HuMemDirectFree(D_80106544_3FAE74_name_69);
}

__asm__(".section .rodata");
const char D_801064D4_3FAE04_name_69[] = "%d";

void func_80102CE4_3F7614_name_69(void) {
    char buf[8];
    s32 choice;

again:
    {
        sprintf(buf, D_801064D4_3FAE04_name_69, D_800FD8A8_FE4A8.stage + 1);
        MBDlgWinInsertCreateY(0x29, 0x5CD, buf, NULL, NULL, NULL, NULL, 0xAA);
        choice = func_8008BB48_8C748(mbDlgWinId, 0, 1);
        MBDlgWinClose();
        func_80056168_56D68();
        HuPrcVSleep();
        if (choice == 0) {
            func_8007E0C8_7ECC8(&D_80106510_3FAE40_name_69);
            if (func_8010288C_3F71BC_name_69(0) != 0) {
                func_801028D0_3F7200_name_69();
                sprintf(buf, D_801064D4_3FAE04_name_69, D_80106510_3FAE40_name_69.stage + 1);
                MBDlgWinInsertCreateY(0x29, 0x5CF, buf, NULL, NULL, NULL, NULL, 0xAA);
                choice = func_8008BB48_8C748(mbDlgWinId, 0, 0);
                MBDlgWinClose();
                func_80056168_56D68();
                HuPrcVSleep();
                func_80102C88_3F75B8_name_69();
                if (choice != 0) {
                    goto again;
                }
            }
            func_800753D4_75FD4(0);
            _ClearFlag(0);
            func_8007E018_7EC18();
            func_8007E0C8_7ECC8(&D_80106510_3FAE40_name_69);
            func_801028D0_3F7200_name_69();
            MBDlgWinInsertCreateY(0x29, 0x5D0, NULL, NULL, NULL, NULL, NULL, 0xAA);
            choice = func_8008BB48_8C748(mbDlgWinId, 0, 1);
            MBDlgWinClose();
            func_80056168_56D68();
            func_80102C88_3F75B8_name_69();
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
    MBDlgWinExecY(0x29, D_80106318_3FAC48_name_69[D_800FD8A8_FE4A8.difficulty], 0xAA);
}

void func_801030B8_3F79E8_name_69(s32 sign) {
    s16 size[2];
    s32 win;
    s32 name;

    if (func_80075390_75F90(sign + OVL69_FLAG_BASE) == 0) {
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

void func_801031D0_3F7B00_name_69(void) {
    D_800FD8A8_FE4A8.stage = OVL69_STAGE;
    omInitObjMan(10, 0);
    omOvlGotoEx(OVL69_NEXT_SCENE, OVL69_NEXT_ENTRY, 0x192);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_69_name/3F7160", func_8010320C_3F7B3C_name_69);

void func_80103284_3F7BB4_name_69(void) {
    omInitObjMan(0x50, 0x28);
    func_80020070_20C70(2);
    func_80026D28_27928(1);
    func_80026DAC_279AC(0, 0x78, 0x78, 0x78);
    func_80026DAC_279AC(1, 0x40, 0x40, 0x60);
    func_80026E00_27A00(1, -100.0f, 100.0f, 300.0f);
    func_80074154_74D54(OVL69_BOARD_MODEL, OVL69_BOARD_FILE);
    EventTableHydrate(D_801063E0_3FAD10_name_69);
    func_80102830_3F7160_name_69();
}

void func_80103310_3F7C40_name_69(void) {
    func_80103284_3F7BB4_name_69();
    func_80074DB8_759B8(0);
    PlayMusic(OVL69_MUSIC);
}

void func_8010333C_3F7C6C_name_69(void) {
    func_80073410_74010(0x18);
    func_801030B8_3F79E8_name_69(0x18);
}

void func_80103360_3F7C90_name_69(void) {
    func_80073410_74010(0x19);
    func_801030B8_3F79E8_name_69(0x19);
}

void func_80103384_3F7CB4_name_69(void) {
    func_80073410_74010(0x1A);
    func_801030B8_3F79E8_name_69(0x1A);
}

void func_801033A8_3F7CD8_name_69(void) {
    func_80073410_74010(0x1B);
    func_801030B8_3F79E8_name_69(0x1B);
}

void func_801033CC_3F7CFC_name_69(void) {
    func_80073410_74010(0x1C);
    func_801030B8_3F79E8_name_69(0x1C);
}

void func_801033F0_3F7D20_name_69(void) {
    func_80073410_74010(0x1D);
    func_801030B8_3F79E8_name_69(0x1D);
}

void func_80103414_3F7D44_name_69(void) {
    func_80073410_74010(-2);
    func_80102CE4_3F7614_name_69();
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_69_name/3F7160", func_80103438_3F7D68_name_69);

void func_8010348C_3F7DBC_name_69(void) {
    func_80074FAC_75BAC(8, 0, 1, 0);
}

void func_801034B4_3F7DE4_name_69(void) {
    func_80074FAC_75BAC(6, 0, 1, 1);
}

#ifdef NON_MATCHING
void func_801034DC_3F7E0C_name_69(void) {
    s16 cnt[4];
    s16 digits[2][4];
    s16 val[2];
    s32 spr;
    s16 i;
    s16 j;
    s16 k;
    s32 file;
    void* data;

    D_80106560_3FAE90_name_69 = (s16)func_800888A8_894A8(0, 0, 0x140, 0xF0, 0, 4);
    func_80089B2C_8A72C((s16)D_80106560_3FAE90_name_69, 0xC8);
    func_8008D530_8E130((s16)D_80106560_3FAE90_name_69, 0, 0, 0);
    D_80106570_3FAEA0_name_69 = SprCreate(3, 5);
    SprPosSet((s16)D_80106570_3FAEA0_name_69, 0, 0, 0);
    data = DataRead(D_80106438_3FAD68_name_69[D_80106564_3FAE94_name_69][0]);
    i = 0;
    D_80106574_3FAEA4_name_69 = SprAnimRead(data);
    DataClose(data);
    SprAnimSet((s16)D_80106570_3FAEA0_name_69, 1, (s16)D_80106574_3FAEA4_name_69, 0);
    func_8008225C_82E5C((s16)D_80106570_3FAEA0_name_69, 1, 1);
    SprPrioSet((s16)D_80106570_3FAEA0_name_69, 1, 0x10);
    SprAttrSet((s16)D_80106570_3FAEA0_name_69, 1, 0x9000);
    SprPosSet((s16)D_80106570_3FAEA0_name_69, 1, 0xA0, 0xAA);
    func_8008221C_82E1C((s16)D_80106570_3FAEA0_name_69, 1, 0.0f);
    D_8010657C_3FAEAC_name_69 = SprCreate(3, 5);
    SprPosSet((s16)D_8010657C_3FAEAC_name_69, 0, 0, 0);
    data = DataRead(D_80106448_3FAD78_name_69[0]);
    D_80106580_3FAEB0_name_69 = SprAnimRead(data);
    DataClose(data);
    SprAnimSet((s16)D_8010657C_3FAEAC_name_69, 1, (s16)D_80106580_3FAEB0_name_69, 0);
    func_8008225C_82E5C((s16)D_8010657C_3FAEAC_name_69, 1, 1);
    SprPrioSet((s16)D_8010657C_3FAEAC_name_69, 1, 0x10);
    SprAttrSet((s16)D_8010657C_3FAEAC_name_69, 1, 0x9000);
    SprPosSet((s16)D_8010657C_3FAEAC_name_69, 1, 0xA0, 0xA0);
    func_8008221C_82E1C((s16)D_80106570_3FAEA0_name_69, 1, 0.0f);
    val[0] = D_800FD8A8_FE4A8.lives - D_80106568_3FAE98_name_69;
    val[1] = gPlayers[0].coins_mg_bonus + gPlayers[0].coins_mg;
    for (; i < 2; i++) {
        digits[i][0] = OVL69_ABS(val[i]) / 1000;
        digits[i][1] = (OVL69_ABS(val[i]) - digits[i][0] * 1000) / 100;
        digits[i][2] = (OVL69_ABS(val[i]) - digits[i][0] * 1000 - digits[i][1] * 100) / 10;
        digits[i][3] = OVL69_ABS(val[i]) - digits[i][0] * 1000 - digits[i][1] * 100 - digits[i][2] * 10;
        cnt[i] = 0;
        if (OVL69_ABS(val[i]) >= 10) {
            cnt[i] = 1;
        }
        if (OVL69_ABS(val[i]) >= 100) {
            cnt[i] = 2;
        }
        if (OVL69_ABS(val[i]) >= 1000) {
            cnt[i] = 3;
        }
    }
    for (i = 0; i < 2; i++) {
        j = 0;
        spr = SprCreate(7, 5);
        D_801065C0_3FAEF0_name_69[i] = spr;
        if (i == 0 || val[i] < 0) {
            file = 0xD0004;
        } else {
            file = 0xD0005;
        }
        data = DataRead(file);
        D_80106588_3FAEB8_name_69[i] = SprAnimRead(data);
        DataClose(data);
        SprAnimSet(spr, j, (s16)D_80106588_3FAEB8_name_69[i], 0);
        func_800824F4_830F4(spr, j, -1);
        SprAttrSet(spr, j, 0x8000);
        SprPosSet(spr, j, D_80106458_3FAD88_name_69[i][0], D_80106458_3FAD88_name_69[i][1]);
        j++;
        SprAnimSet(spr, j, (s16)D_80106588_3FAEB8_name_69[i], 0);
        func_8008225C_82E5C(spr, j, 1);
        SprPrioSet(spr, j, 0xF);
        SprAttrSet(spr, j, 0x9000);
        SprPosSet(spr, j, 0, 0);
        func_800824F4_830F4(spr, j, 0);
        j++;
        for (k = 0; k < 4; k++, j++) {
            data = DataRead(0xC000D);
            D_801065A0_3FAED0_name_69[i][k] = SprAnimRead(data);
            DataClose(data);
            SprAnimSet(spr, j, (s16)D_801065A0_3FAED0_name_69[i][k], 0);
            func_8008225C_82E5C(spr, j, 1);
            SprPrioSet(spr, j, 0xE);
            SprAttrSet(spr, j, 0x9000);
            func_800822A8_82EA8(spr, j, digits[i][k], 0);
            func_800824F4_830F4(spr, j, 0);
            func_8008221C_82E1C(spr, j, 0.0f);
            if (i == 0) {
                if (val[i] == 0) {
                    SprPosSet(spr, j, D_80106460_3FAD90_name_69[cnt[i]][k], 2);
                } else {
                    SprPosSet(spr, j, D_80106460_3FAD90_name_69[cnt[i]][k] + 4, 2);
                }
            } else if (D_80106564_3FAE94_name_69 == 0) {
                if (val[i] == 0) {
                    SprPosSet(spr, j, D_80106460_3FAD90_name_69[cnt[i]][k], 2);
                } else {
                    SprPosSet(spr, j, D_80106460_3FAD90_name_69[cnt[i]][k] + 4, 2);
                }
            } else {
                func_80082450_83050(spr, j, 0xFF, 0, 0);
                SprPosSet(spr, j, D_80106460_3FAD90_name_69[cnt[i]][k], 2);
            }
        }
        data = DataRead(0xC000D);
        D_80106594_3FAEC4_name_69[i] = SprAnimRead(data);
        DataClose(data);
        SprAnimSet(spr, j, (s16)D_80106594_3FAEC4_name_69[i], 0);
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
                SprPosSet(spr, j, D_80106460_3FAD90_name_69[cnt[i]][3 - cnt[i]] - 4, 2);
            }
        } else if (D_80106564_3FAE94_name_69 == 0 && val[i] != 0) {
            if (val[i] > 0) {
                func_800822A8_82EA8(spr, j, 11, 0);
            } else {
                func_800822A8_82EA8(spr, j, 12, 0);
            }
            SprPosSet(spr, j, D_80106460_3FAD90_name_69[cnt[i]][3 - cnt[i]] - 4, 2);
        } else {
            SprPosSet(spr, j, -1000, 2);
            func_800822A8_82EA8(spr, j, 10, 0);
        }
    }
    spr = SprCreate(7, 5);
    D_801065C0_3FAEF0_name_69[2] = spr;
    data = DataRead(0xD0005);
    D_80106588_3FAEB8_name_69[2] = SprAnimRead(data);
    DataClose(data);
    SprAnimSet(spr, 0, (s16)D_80106588_3FAEB8_name_69[2], 0);
    func_800824F4_830F4(spr, 0, -1);
    SprAttrSet(spr, 0, 0x8000);
    SprPosSet(spr, 0, D_80106458_3FAD88_name_69[0][0], D_80106458_3FAD88_name_69[0][1]);
    SprAnimSet(spr, 1, (s16)D_80106588_3FAEB8_name_69[2], 0);
    func_8008225C_82E5C(spr, 1, 1);
    SprPrioSet(spr, 1, 0xF);
    SprAttrSet(spr, 1, 0x9000);
    SprPosSet(spr, 1, 0, 0);
    func_800824F4_830F4(spr, 1, 0);
    data = DataRead(0xD0006);
    D_8010656C_3FAE9C_name_69 = SprAnimRead(data);
    DataClose(data);
    SprAnimSet(spr, 2, (s16)D_8010656C_3FAE9C_name_69, 0);
    func_8008225C_82E5C(spr, 2, 1);
    SprPrioSet(spr, 2, 0xE);
    SprAttrSet(spr, 2, 0x9000);
    func_800824F4_830F4(spr, 2, 0);
    SprPosSet(spr, 2, 0, 2);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_69_name/3F7160", func_801034DC_3F7E0C_name_69);
#endif

void func_801042A0_3F8BD0_name_69(void) {
    func_8008CCA8_8D8A8((s16)D_80106560_3FAE90_name_69);
}

void func_801042C0_3F8BF0_name_69(void) {
    Hu3DCamSetPerspective(1, 40.0f, 200.0f, 8000.0f);
    Hu3DCamSetPositionOrientation(1, &D_801065CC_3FAEFC_name_69, &D_801065D8_3FAF08_name_69, &D_801065E4_3FAF14_name_69);
    Hu3DCamUpdateMtx(1);
    CameraViewportSet(1, &D_801065F0_3FAF20_name_69, &D_801065FC_3FAF2C_name_69);
}

void func_80104328_3F8C58_name_69(void) {
    while (1) {
        func_801042C0_3F8BF0_name_69();
        HuPrcVSleep();
    }
}

__asm__(".section .rodata");
const char D_801064D8_3FAE08_name_69[] = "point1";

__asm__(".section .rodata");
const char D_801064E0_3FAE10_name_69[] = "point2";

void func_80104354_3F8C84_name_69(void) {
    Vec v;

    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    HuVecCopyXYZ(&v, 0.0f, 0.0f, 0.0f);
    OVL69_LINK(func_80056D80_57980(&D_80106618_3FAF48_name_69->pos, &v, &D_80106618_3FAF48_name_69->pos, 20));
    HuPrcChildWatch();
    func_80029E80_2AA80(D_80106618_3FAF48_name_69->obj->model[0], 2, 1);
    HuVecCopyXYZ(&D_80106610_3FAF40_name_69->pos, -6.278950214385986f, 19.16754913330078f, 0.0f);
    HuVecCopyXYZ(&D_80106614_3FAF44_name_69->pos, 5.623000144958496f, 19.16754913330078f, 0.0f);
    HuPrcVSleep();
    func_8005AA98_5B698(D_80106610_3FAF40_name_69->obj->model[0]);
    func_8005AA98_5B698(D_80106614_3FAF44_name_69->obj->model[0]);
    HuPrcVSleep();
    func_8005670C_5730C(&v);
    OVL69_LINK(func_80056B78_57778(&D_80106610_3FAF40_name_69->rot, &v, &D_80106610_3FAF40_name_69->rot, 10));
    OVL69_LINK(func_80056B78_57778(&D_80106614_3FAF44_name_69->rot, &v, &D_80106614_3FAF44_name_69->rot, 10));
    HuPrcChildWatch();
    if (D_80106564_3FAE94_name_69 == 0) {
        MBMotionSet(D_80106610_3FAF40_name_69, 6, 0);
        MBMotionSet(D_80106614_3FAF44_name_69, 6, 0);
        func_800732B0_73EB0(D_80106488_3FADB8_name_69[(s8)D_800FD8A8_FE4A8.character] | 0x54);
    } else {
        MBMotionSet(D_80106610_3FAF40_name_69, 3, 0);
        MBMotionSet(D_80106614_3FAF44_name_69, 3, 0);
    }
    while (1) {
        if (D_80106454_3FAD84_name_69 != 0) {
            MBMotionSet(D_80106610_3FAF40_name_69, 5, 0);
            MBMotionSet(D_80106614_3FAF44_name_69, 5, 0);
            HuPrcSleep(30);
            break;
        }
        if (D_80106453_3FAD83_name_69 != 0) {
            break;
        }
        HuPrcVSleep();
    }
    MBMotionShiftSet(D_80106610_3FAF40_name_69, -1, 0, 10, 2);
    MBMotionShiftSet(D_80106614_3FAF44_name_69, -1, 0, 10, 2);
    HuVecCopyXYZ(&v, -1.0f, 0.0f, 0.0f);
    OVL69_LINK(func_80056B78_57778(&D_80106610_3FAF40_name_69->rot, &v, &D_80106610_3FAF40_name_69->rot, 10));
    OVL69_LINK(func_80056B78_57778(&D_80106614_3FAF44_name_69->rot, &v, &D_80106614_3FAF44_name_69->rot, 10));
    HuPrcChildWatch();
    func_8005AA48_5B648(D_80106618_3FAF48_name_69, D_801064D8_3FAE08_name_69, D_80106610_3FAF40_name_69->obj->model[0]);
    func_8005AA48_5B648(D_80106618_3FAF48_name_69, D_801064E0_3FAE10_name_69, D_80106614_3FAF44_name_69->obj->model[0]);
    func_80029E80_2AA80(D_80106618_3FAF48_name_69->obj->model[0], 1, 2);
    HuVecCopyXYZ(&v, -100.0f, 0.0f, 0.0f);
    OVL69_LINK(func_80056D80_57980(&D_80106618_3FAF48_name_69->pos, &v, &D_80106618_3FAF48_name_69->pos, 20));
    HuPrcChildWatch();
    while (1) {
        HuPrcVSleep();
    }
}

void func_80104754_3F9084_name_69(void) {
    D_80106608_3FAF38_name_69 = omAddPrcObj(func_80104328_3F8C58_name_69, 0x4000, 0, 0);
    D_801065CC_3FAEFC_name_69.x = 0.0f;
    D_801065CC_3FAEFC_name_69.y = 250.0f;
    D_801065CC_3FAEFC_name_69.z = 200.0f;
    D_801065D8_3FAF08_name_69.x = 0.0f;
    D_801065D8_3FAF08_name_69.y = 0.0f;
    D_801065D8_3FAF08_name_69.z = 0.0f;
    D_801065E4_3FAF14_name_69.x = 0.0f;
    D_801065E4_3FAF14_name_69.y = 1.0f;
    D_801065E4_3FAF14_name_69.z = 0.0f;
    D_801065F0_3FAF20_name_69.x = 1280.0f;
    D_801065F0_3FAF20_name_69.y = 960.0f;
    D_801065F0_3FAF20_name_69.z = 511.0f;
    D_801065FC_3FAF2C_name_69.x = 640.0f;
    D_801065FC_3FAF2C_name_69.y = 480.0f;
    D_801065FC_3FAF2C_name_69.z = 511.5f;
    func_801042C0_3F8BF0_name_69();
    D_80106618_3FAF48_name_69 = func_80043510_44110(0xAA, NULL);
    HuVecCopyXYZ(&D_80106618_3FAF48_name_69->rot, -1.0f, 0.0f, 0.0f);
    HuVecCopyXYZ(&D_80106618_3FAF48_name_69->pos, 100.0f, 0.0f, 0.0f);
    D_80106618_3FAF48_name_69->attr |= 1;
    func_80029EDC_2AADC(D_80106618_3FAF48_name_69->obj->model[0], 2);
    D_80106610_3FAF40_name_69 = func_80043510_44110(D_80106480_3FADB0_name_69[(s8)D_800FD8A8_FE4A8.character], D_800CC8B8_CD4B8[(s8)D_800FD8A8_FE4A8.character]);
    HuVecCopyXYZ(&D_80106610_3FAF40_name_69->rot, -1.0f, 0.0f, 0.0f);
    D_80106610_3FAF40_name_69->attr |= 1;
    func_80029EDC_2AADC(D_80106610_3FAF40_name_69->obj->model[0], 2);
    D_80106614_3FAF44_name_69 = func_80043510_44110(D_80106480_3FADB0_name_69[(s8)D_800FD8A8_FE4A8.character2], D_800CC8B8_CD4B8[(s8)D_800FD8A8_FE4A8.character2]);
    HuVecCopyXYZ(&D_80106614_3FAF44_name_69->rot, -1.0f, 0.0f, 0.0f);
    D_80106614_3FAF44_name_69->attr |= 1;
    func_80029EDC_2AADC(D_80106614_3FAF44_name_69->obj->model[0], 2);
    func_8005AA48_5B648(D_80106618_3FAF48_name_69, D_801064D8_3FAE08_name_69, D_80106610_3FAF40_name_69->obj->model[0]);
    func_8005AA48_5B648(D_80106618_3FAF48_name_69, D_801064E0_3FAE10_name_69, D_80106614_3FAF44_name_69->obj->model[0]);
    D_8010660C_3FAF3C_name_69 = omAddPrcObj(func_80104354_3F8C84_name_69, 0x4000, 0, 0);
}

void func_80104A20_3F9350_name_69(void) {
    omDelPrcObj(D_80106608_3FAF38_name_69);
    omDelPrcObj(D_8010660C_3FAF3C_name_69);
    MBModelKill(D_80106610_3FAF40_name_69);
    MBModelKill(D_80106614_3FAF44_name_69);
    MBModelKill(D_80106618_3FAF48_name_69);
}

void func_80104A70_3F93A0_name_69(void) {
    switch (D_80106564_3FAE94_name_69) {
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

void func_80104ADC_3F940C_name_69(s8 idx) {
    f32 scale;
    s32 i;
    s32 n = idx;

    i = 0;
    do {
        i++;
        SprAttrReset((s16)D_801065C0_3FAEF0_name_69[n], i, 0x8000);
    } while (i < 6);
    for (scale = 0.0f; scale < 1.0; scale += 0.3) {
        i = 0;
        do {
            i++;
            SprScaleSet((s16)D_801065C0_3FAEF0_name_69[n], i, scale, scale);
        } while (i < 6);
        if (D_80106450_3FAD80_name_69 == 0) {
            HuPrcVSleep();
        }
    }
    i = 0;
    do {
        i++;
        SprScaleSet((s16)D_801065C0_3FAEF0_name_69[n], i, 1.0f, 1.0f);
    } while (i < 6);
}

void func_80104C24_3F9554_name_69(void) {
    f32 scale;
    s32 i;

    i = 0;
    do {
        i++;
        SprAttrReset((s16)D_801065C0_3FAEF0_name_69[0], i, 0x8000);
        SprAttrReset((s16)D_801065C0_3FAEF0_name_69[1], i, 0x8000);
    } while (i < 6);
    for (scale = 0.0f; scale < 1.0; scale += 0.3) {
        i = 0;
        do {
            i++;
            SprScaleSet((s16)D_801065C0_3FAEF0_name_69[0], i, scale, scale);
            SprScaleSet((s16)D_801065C0_3FAEF0_name_69[1], i, scale, scale);
        } while (i < 6);
        if (D_80106450_3FAD80_name_69 == 0) {
            HuPrcVSleep();
        }
    }
    i = 0;
    do {
        i++;
        SprScaleSet((s16)D_801065C0_3FAEF0_name_69[0], i, 1.0f, 1.0f);
        SprScaleSet((s16)D_801065C0_3FAEF0_name_69[1], i, 1.0f, 1.0f);
    } while (i < 6);
}

void func_80104DA4_3F96D4_name_69(void) {
    f32 scale;
    s32 i;

    i = 0;
    do {
        i++;
        SprScaleSet((s16)D_801065C0_3FAEF0_name_69[0], i, 1.0f, 1.0f);
        SprScaleSet((s16)D_801065C0_3FAEF0_name_69[1], i, 1.0f, 1.0f);
    } while (i < 6);
    scale = 1.0f;
    do {
        i = 0;
        do {
            i++;
            SprScaleSet((s16)D_801065C0_3FAEF0_name_69[0], i, scale, scale);
            SprScaleSet((s16)D_801065C0_3FAEF0_name_69[1], i, scale, scale);
        } while (i < 6);
        if (D_80106450_3FAD80_name_69 == 0) {
            HuPrcVSleep();
        }
        scale -= 0.3f;
    } while (scale > 0.0f);
    i = 0;
    do {
        i++;
        SprAttrSet((s16)D_801065C0_3FAEF0_name_69[0], i, 0x8000);
        SprAttrSet((s16)D_801065C0_3FAEF0_name_69[1], i, 0x8000);
    } while (i < 6);
}

#ifdef NON_MATCHING
void func_80104F24_3F9854_name_69(void) {
    s16 val[4];
    s16 cnt[4];
    s16 digits[4][4];
    s32 i;
    s32 k;
    s32 j;

    val[0] = D_800FD8A8_FE4A8.lives - D_80106568_3FAE98_name_69;
    if (D_800FD8A8_FE4A8.streak > 0) {
        val[1] = (gPlayers[0].coins_mg + gPlayers[0].coins_mg_bonus) * D_800FD8A8_FE4A8.streak - D_80106456_3FAD86_name_69;
    } else {
        val[1] = gPlayers[0].coins_mg + gPlayers[0].coins_mg_bonus - D_80106456_3FAD86_name_69;
    }
    for (i = 0; i < 2; i++) {
        digits[i][0] = OVL69_ABS(val[i]) / 1000;
        digits[i][1] = (OVL69_ABS(val[i]) - digits[i][0] * 1000) / 100;
        digits[i][2] = (OVL69_ABS(val[i]) - digits[i][0] * 1000 - digits[i][1] * 100) / 10;
        digits[i][3] = OVL69_ABS(val[i]) - digits[i][0] * 1000 - digits[i][1] * 100 - digits[i][2] * 10;
        cnt[i] = 0;
        if (OVL69_ABS(val[i]) >= 10) {
            cnt[i] = 1;
        }
        if (OVL69_ABS(val[i]) >= 100) {
            cnt[i] = 2;
        }
        if (OVL69_ABS(val[i]) >= 1000) {
            cnt[i] = 3;
        }
    }
    for (i = 0; i < 2; i++) {
        j = 2;
        for (k = 0; k < 4; k++, j++) {
            func_800822A8_82EA8((s16)D_801065C0_3FAEF0_name_69[i], j, digits[i][k], 0);
            if (i == 0) {
                if (val[i] == 0) {
                    SprPosSet((s16)D_801065C0_3FAEF0_name_69[i], j, D_801064A0_3FADD0_name_69[cnt[i]][k], 2);
                } else {
                    SprPosSet((s16)D_801065C0_3FAEF0_name_69[i], j, D_801064A0_3FADD0_name_69[cnt[i]][k] + 4, 2);
                }
            } else if (D_80106564_3FAE94_name_69 == 0 && val[i] != 0) {
                SprPosSet((s16)D_801065C0_3FAEF0_name_69[i], j, D_801064A0_3FADD0_name_69[cnt[i]][k] + 4, 2);
            } else {
                SprPosSet((s16)D_801065C0_3FAEF0_name_69[i], j, D_801064A0_3FADD0_name_69[cnt[i]][k], 2);
            }
        }
        if (i == 0) {
            if (val[i] == 0) {
                SprPosSet((s16)D_801065C0_3FAEF0_name_69[i], j, -1000, -2);
                func_800822A8_82EA8((s16)D_801065C0_3FAEF0_name_69[i], j, 10, 0);
            } else {
                if (val[i] > 0) {
                    func_800822A8_82EA8((s16)D_801065C0_3FAEF0_name_69[i], j, 11, 0);
                } else {
                    func_800822A8_82EA8((s16)D_801065C0_3FAEF0_name_69[i], j, 12, 0);
                }
                SprPosSet((s16)D_801065C0_3FAEF0_name_69[i], j, D_801064A0_3FADD0_name_69[cnt[i]][3 - cnt[i]] - 4, 2);
            }
        } else if (D_80106564_3FAE94_name_69 == 0 && val[i] != 0) {
            if (val[i] > 0) {
                func_800822A8_82EA8((s16)D_801065C0_3FAEF0_name_69[i], j, 11, 0);
            } else {
                func_800822A8_82EA8((s16)D_801065C0_3FAEF0_name_69[i], j, 12, 0);
            }
            SprPosSet((s16)D_801065C0_3FAEF0_name_69[i], j, D_801064A0_3FADD0_name_69[cnt[i]][3 - cnt[i]] - 4, 2);
        } else {
            SprPosSet((s16)D_801065C0_3FAEF0_name_69[i], j, -1000, -2);
            func_800822A8_82EA8((s16)D_801065C0_3FAEF0_name_69[i], j, 10, 0);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_69_name/3F7160", func_80104F24_3F9854_name_69);
#endif

void func_801055AC_3F9EDC_name_69(void) {
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
    while ((s16)coins > D_80106456_3FAD86_name_69) {
        D_80106456_3FAD86_name_69 += step;
        if ((s16)coins <= D_80106456_3FAD86_name_69) {
            D_800FD8A8_FE4A8.coins += step - ((u8)D_80106456_3FAD86_name_69 - coins);
            D_80106456_3FAD86_name_69 = coins;
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
                func_80104ADC_3F940C_name_69(2);
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
        func_80104F24_3F9854_name_69();
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
            func_80104ADC_3F940C_name_69(2);
        }
    }
    func_80104F24_3F9854_name_69();
}

void func_80105884_3FA1B4_name_69(void) {
    s16 size[2];
    s32 win;
    s8 choice;

    SprAttrSet((s16)D_80106570_3FAEA0_name_69, 1, 0x8000);
    HuPrcSleep(30);
    PlayMusic(0x14);
    SprAttrReset((s16)D_8010657C_3FAEAC_name_69, 1, 0x8000);
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
        D_80106454_3FAD84_name_69 = 1;
        HuPrcSleep(30);
    }
    D_80106452_3FAD82_name_69 = choice;
    D_80106451_3FAD81_name_69 = 1;
}

void func_80105A04_3FA334_name_69(void) {
    s16 size[2];
    char buf[8];
    GAMEMES mesX;
    GAMEMES mesN;
    s16 win;

    if (D_800FD8A8_FE4A8.streak >= 2) {
        sprintf(buf, D_801064D4_3FAE04_name_69, D_800FD8A8_FE4A8.streak);
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
        func_80104F24_3F9854_name_69();
        PlaySound(0x33D);
        HuPrcSleep(0x19);
    }
}

#ifdef NON_MATCHING
void func_80105BB4_3FA4E4_name_69(void) {
    s16 i;
    s32 show;
    s32 failed;

    switch (D_80106564_3FAE94_name_69) {
    case 0:
        HuPrcSleep(0x24);
        func_80079428_7A028(0x44);
        break;
    case 1:
        HuPrcSleep(0x24);
        func_80079428_7A028(0x45);
        break;
    }
    SprAttrReset((s16)D_80106570_3FAEA0_name_69, 1, 0x8000);
    omAddPrcObj(func_80104A70_3F93A0_name_69, 0x300, 0x2500, 0);
    HuPrcSleep(0x3C);
    if (D_80106564_3FAE94_name_69 == 0) {
        HuPrcSleep(30);
    } else {
        HuPrcSleep(20);
    }
    failed = 0;
    switch (D_80106564_3FAE94_name_69) {
    case 0:
        func_80104ADC_3F940C_name_69(1);
        for (i = 0; i < 30; i++) {
            if (D_80106450_3FAD80_name_69 == 1) {
                break;
            }
            HuPrcVSleep();
        }
        func_80105A04_3FA334_name_69();
        func_801055AC_3F9EDC_name_69();
        goto done;
    case 1:
        if (D_800FD8A8_FE4A8.lives <= 0) {
            failed = 1;
        }
        D_800FD8A8_FE4A8.lives--;
        func_80104F24_3F9854_name_69();
        if (D_800FD8A8_FE4A8.lives < 0) {
            D_800FD8A8_FE4A8.lives = 0;
        }
        func_80104C24_3F9554_name_69();
        for (i = 0; i < 30; i++) {
            if (D_80106450_3FAD80_name_69 == 1) {
                break;
            }
            HuPrcVSleep();
        }
    done:
        func_80104DA4_3F96D4_name_69();
        show = failed;
        break;
    default:
        show = failed;
        break;
    }
    if (show != 0) {
        func_80105884_3FA1B4_name_69();
    } else {
        D_80106453_3FAD83_name_69 = 1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_69_name/3F7160", func_80105BB4_3FA4E4_name_69);
#endif

s32 func_80105D90_3FA6C0_name_69(s16 minigame) {
    s32 total;

    total = gPlayers[0].coins_mg_bonus + gPlayers[0].coins_mg;
    switch (minigame) {
    case 0x24:
        if (total < D_801064C0_3FADF0_name_69[0][D_800FD8A8_FE4A8.difficulty]) {
            return 0;
        }
        break;
    case 0x47:
        if (total < D_801064C0_3FADF0_name_69[1][D_800FD8A8_FE4A8.difficulty]) {
            return 0;
        }
        break;
    case 0x48:
        if (total < D_801064C0_3FADF0_name_69[2][D_800FD8A8_FE4A8.difficulty]) {
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

void func_80105E5C_3FA78C_name_69(void) {
    s32 i;
    s32 j;

    SprKill((s16)D_80106570_3FAEA0_name_69);
    SprKill((s16)D_8010657C_3FAEAC_name_69);
    for (i = 0; i < 3; i++) {
        SprKill((s16)D_801065C0_3FAEF0_name_69[i]);
        SprAnimKill((s16)D_80106588_3FAEB8_name_69[i]);
    }
    SprAnimKill((s16)D_8010656C_3FAE9C_name_69);
    for (i = 0; i < 2; i++) {
        SprAnimKill((s16)D_80106594_3FAEC4_name_69[i]);
        for (j = 0; j < 4; j++) {
            SprAnimKill((s16)D_801065A0_3FAED0_name_69[i][j]);
        }
    }
    SprAnimKill((s16)D_80106574_3FAEA4_name_69);
    SprAnimKill((s16)D_80106580_3FAEB0_name_69);
}

void func_80105F74_3FA8A4_name_69(void) {
    func_80028334_28F34(D_800FD2A6_FDEA6, 2);
    func_80029EDC_2AADC(D_800FD2A6_FDEA6, 1);
    if (func_80105D90_3FA6C0_name_69(GwSystem.chosenMinigameIndex) != 0) {
        D_80106564_3FAE94_name_69 = 0;
        _SetFlag(0x16);
        D_800FD8A8_FE4A8.streak++;
        PlayMusic(0x42);
    } else {
        D_80106564_3FAE94_name_69 = 1;
        _ClearFlag(0x16);
        D_800FD8A8_FE4A8.streak = 0;
        PlayMusic(0x43);
    }
    D_80106566_3FAE96_name_69 = D_800FD8A8_FE4A8.coins;
    D_80106568_3FAE98_name_69 = D_800FD8A8_FE4A8.lives;
    func_801034DC_3F7E0C_name_69();
    func_80104754_3F9084_name_69();
    func_80029E80_2AA80(D_800FA618_FB218->obj->model[0], 2, 1);
    func_80029E80_2AA80(((MBModel*)gPlayers[0].unk_24)->obj->model[0], 2, 1);
    func_80029E80_2AA80(((MBModel*)gPlayers[1].unk_24)->obj->model[0], 2, 1);
    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    func_80105BB4_3FA4E4_name_69();
    HuPrcSleep(30);
    func_800794A8_7A0A8(0x5A);
    InitFadeOut(0, 0x10);
    HuPrcSleep(0x11);
    func_801042A0_3F8BD0_name_69();
    func_80104A20_3F9350_name_69();
    func_80105E5C_3FA78C_name_69();
    switch (D_80106452_3FAD82_name_69) {
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

void func_80106174_3FAAA4_name_69(void) {
    func_80103284_3F7BB4_name_69();
    func_80074DB8_759B8(1);
    omAddPrcObj(func_80105F74_3FA8A4_name_69, 0x1005, 0x1000, 0);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_69_name/3F7160", func_801061B0_3FAAE0_name_69);
