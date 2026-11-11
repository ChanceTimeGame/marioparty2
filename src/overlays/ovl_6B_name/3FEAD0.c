#include "common.h"
#include "ovl_6B.h"

#define OVL6B_ABS(x) ((x) < 0 ? -(s32)(x) : (x))
/* Waits on a mover: makes it a child of the current process. */
#define OVL6B_LINK(call) do { Process* _p = (call); HuPrcChildLink(HuPrcCurrentGet(), _p); } while (0)

void func_80102830_3FEAD0_name_6B(void) {
    CoasterSpaceFlag* entry;

    entry = D_80106240_4024E0_name_6B;
    while (entry->space >= 0) {
        if (func_80075390_75F90(entry->flag) != 0) {
            BoardSpaceTypeSet(entry->space, 1);
        }
        entry++;
    }
}

s32 func_8010288C_3FEB2C_name_6B(s32 bit) {
    return D_80106460_402700_name_6B.flags[bit / 8] & (1 << (bit % 8));
}

__asm__(".section .rodata");
const char D_80106420_4026C0_name_6B[] = "%2d";

void func_801028D0_3FEB70_name_6B(void) {
    s16 size[2];
    void* data;
    s32 i;
    s32 win;

    D_80106494_402734_name_6B = func_8005E688_5F288(1, 0);
    data = DataRead(D_8010625C_4024FC_name_6B[(s8)D_80106460_402700_name_6B.character]);
    i = 0;
    D_80106494_402734_name_6B->unk0C[0] = SprAnimRead(data);
    SprAnimSet(D_80106494_402734_name_6B->unk0A, 0, D_80106494_402734_name_6B->unk0C[0], 0);
    SprPrioSet(D_80106494_402734_name_6B->unk0A, 0, 0x10);
    SprAttrSet(D_80106494_402734_name_6B->unk0A, 0, 0x1000);
    SprPosSet(D_80106494_402734_name_6B->unk0A, 0, 0x3E, 0x5F);
    DataClose(data);
    D_80106478_402718_name_6B[6] = func_80057480_58080(D_801062BC_40255C_name_6B[0], D_801062BC_40255C_name_6B[1], 0x18, 5);
    for (; i < 4; i++) {
        func_8008DACC_8E6CC(1, size, D_80106274_402514_name_6B[i]);
        D_80106478_402718_name_6B[i] = (s16)func_800888A8_894A8(D_801062A4_402544_name_6B[i][0], D_801062A4_402544_name_6B[i][1], size[0], size[1], 0, 0);
        func_80089B2C_8A72C((s16)D_80106478_402718_name_6B[i], 0);
        func_80089A48_8A648((s16)D_80106478_402718_name_6B[i], 0);
        func_800890CC_89CCC((s16)D_80106478_402718_name_6B[i], (void*)D_80106274_402514_name_6B[i], -1, -1);
    }
    func_8008DACC_8E6CC(1, size, D_8010628C_40252C_name_6B[D_80106460_402700_name_6B.difficulty]);
    i = 4;
    D_80106478_402718_name_6B[i] = (s16)func_800888A8_894A8(D_801062B4_402554_name_6B, D_801062B6_402556_name_6B, size[0], size[1], 0, 0);
    func_80089B2C_8A72C((s16)D_80106478_402718_name_6B[i], 0);
    func_80089A48_8A648((s16)D_80106478_402718_name_6B[i], 0);
    func_800890CC_89CCC((s16)D_80106478_402718_name_6B[i], (void*)D_8010628C_40252C_name_6B[D_80106460_402700_name_6B.difficulty], -1, -1);
    sprintf(D_80106498_402738_name_6B, D_80106420_4026C0_name_6B, D_80106460_402700_name_6B.chapter);
    func_8008D974_8E574(D_80106498_402738_name_6B, 0);
    sprintf(D_801064A0_402740_name_6B, D_80106420_4026C0_name_6B, D_80106460_402700_name_6B.lives);
    func_8008D974_8E574(D_801064A0_402740_name_6B, 1);
    sprintf(D_801064A8_402748_name_6B, D_80106420_4026C0_name_6B, D_80106460_402700_name_6B.coins);
    func_8008D974_8E574(D_801064A8_402748_name_6B, 2);
    i = 5;
    func_8008DACC_8E6CC(1, size, D_80106274_402514_name_6B[i]);
    win = func_800888A8_894A8(D_801062B8_402558_name_6B, D_801062BA_40255A_name_6B, size[0], size[1] * 2, 0, 0);
    D_80106478_402718_name_6B[i] = win;
    D_800F920C_F9E0C[win].unk28 = 0x12;
    func_80089B2C_8A72C((s16)D_80106478_402718_name_6B[i], 0);
    func_80089A48_8A648((s16)D_80106478_402718_name_6B[i], 0);
    func_80089308_89F08((s16)D_80106478_402718_name_6B[i], D_80106498_402738_name_6B, 0);
    func_80089308_89F08((s16)D_80106478_402718_name_6B[i], D_801064A0_402740_name_6B, 1);
    func_80089308_89F08((s16)D_80106478_402718_name_6B[i], D_801064A8_402748_name_6B, 2);
    func_800890CC_89CCC((s16)D_80106478_402718_name_6B[i], (void*)D_80106274_402514_name_6B[i], -1, -1);
}

void func_80102C88_3FEF28_name_6B(void) {
    s32 i;

    for (i = 0; i < 7; i++) {
        func_8008CCA8_8D8A8((s16)D_80106478_402718_name_6B[i]);
    }
    HuMemDirectFree(D_80106494_402734_name_6B);
}

__asm__(".section .rodata");
const char D_80106424_4026C4_name_6B[] = "%d";

void func_80102CE4_3FEF84_name_6B(void) {
    char buf[8];
    s32 choice;

again:
    {
        sprintf(buf, D_80106424_4026C4_name_6B, D_800FD8A8_FE4A8.stage + 1);
        MBDlgWinInsertCreateY(0x29, 0x5CD, buf, NULL, NULL, NULL, NULL, 0xAA);
        choice = func_8008BB48_8C748(mbDlgWinId, 0, 1);
        MBDlgWinClose();
        func_80056168_56D68();
        HuPrcVSleep();
        if (choice == 0) {
            func_8007E0C8_7ECC8(&D_80106460_402700_name_6B);
            if (func_8010288C_3FEB2C_name_6B(0) != 0) {
                func_801028D0_3FEB70_name_6B();
                sprintf(buf, D_80106424_4026C4_name_6B, D_80106460_402700_name_6B.stage + 1);
                MBDlgWinInsertCreateY(0x29, 0x5CF, buf, NULL, NULL, NULL, NULL, 0xAA);
                choice = func_8008BB48_8C748(mbDlgWinId, 0, 0);
                MBDlgWinClose();
                func_80056168_56D68();
                HuPrcVSleep();
                func_80102C88_3FEF28_name_6B();
                if (choice != 0) {
                    goto again;
                }
            }
            func_800753D4_75FD4(0);
            _ClearFlag(0);
            func_8007E018_7EC18();
            func_8007E0C8_7ECC8(&D_80106460_402700_name_6B);
            func_801028D0_3FEB70_name_6B();
            MBDlgWinInsertCreateY(0x29, 0x5D0, NULL, NULL, NULL, NULL, NULL, 0xAA);
            choice = func_8008BB48_8C748(mbDlgWinId, 0, 1);
            MBDlgWinClose();
            func_80056168_56D68();
            func_80102C88_3FEF28_name_6B();
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
    MBDlgWinExecY(0x29, D_80106298_402538_name_6B[D_800FD8A8_FE4A8.difficulty], 0xAA);
}

void func_801030B8_3FF358_name_6B(s32 sign) {
    s16 size[2];
    s32 win;
    s32 name;

    if (func_80075390_75F90(sign + OVL6B_FLAG_BASE) == 0) {
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

void func_801031D0_3FF470_name_6B(void) {
    D_800FD8A8_FE4A8.stage = OVL6B_STAGE;
    omInitObjMan(10, 0);
    omOvlGotoEx(OVL6B_NEXT_SCENE, OVL6B_NEXT_ENTRY, 0x192);
}

void func_8010320C_3FF4AC_name_6B(void) {
    omInitObjMan(10, 0);
    SetPlayerOntoChain(0, 0, 0);
    func_80075424_76024(OVL6B_FLAG_BASE + 0x24);
    func_80075424_76024(OVL6B_FLAG_BASE + 0x25);
    func_80075424_76024(OVL6B_FLAG_BASE + 0x26);
    func_80075424_76024(OVL6B_FLAG_BASE + 0x27);
    func_80075424_76024(OVL6B_FLAG_BASE + 0x28);
    func_80075424_76024(OVL6B_FLAG_BASE + 0x29);
    func_800753D4_75FD4(0x2C);
    func_80073410_74010(-1);
    omOvlReturnEx(1);
}

void func_80103284_3FF524_name_6B(void) {
    omInitObjMan(0x50, 0x28);
    func_80020070_20C70(2);
    func_80026D28_27928(1);
    func_80026DAC_279AC(0, 0x78, 0x78, 0x78);
    func_80026DAC_279AC(1, 0x40, 0x40, 0x60);
    func_80026E00_27A00(1, -100.0f, 100.0f, 300.0f);
    func_80074154_74D54(OVL6B_BOARD_MODEL, OVL6B_BOARD_FILE);
    EventTableHydrate(D_80106340_4025E0_name_6B);
    func_80102830_3FEAD0_name_6B();
}

void func_80103310_3FF5B0_name_6B(void) {
    func_80103284_3FF524_name_6B();
    func_80074DB8_759B8(0);
    PlayMusic(OVL6B_MUSIC);
}

void func_8010333C_3FF5DC_name_6B(void) {
    func_80073410_74010(0x24);
    func_801030B8_3FF358_name_6B(0x24);
}

void func_80103360_3FF600_name_6B(void) {
    func_80073410_74010(0x25);
    func_801030B8_3FF358_name_6B(0x25);
}

void func_80103384_3FF624_name_6B(void) {
    func_80073410_74010(0x26);
    func_801030B8_3FF358_name_6B(0x26);
}

void func_801033A8_3FF648_name_6B(void) {
    func_80073410_74010(0x27);
    func_801030B8_3FF358_name_6B(0x27);
}

void func_801033CC_3FF66C_name_6B(void) {
    func_80073410_74010(0x28);
    func_801030B8_3FF358_name_6B(0x28);
}

void func_801033F0_3FF690_name_6B(void) {
    func_80073410_74010(0x29);
    func_801030B8_3FF358_name_6B(0x29);
}

void func_80103414_3FF6B4_name_6B(void) {
    func_80073410_74010(-2);
    func_80102CE4_3FEF84_name_6B();
}

void func_80103438_3FF6D8_name_6B(void) {
    func_80074FAC_75BAC(8, 0, 1, 0);
}

#ifdef NON_MATCHING
void func_80103460_3FF700_name_6B(void) {
    s16 cnt[4];
    s16 digits[2][4];
    s16 val[2];
    s32 spr;
    s16 i;
    s16 j;
    s16 k;
    s32 file;
    void* data;

    D_801064B0_402750_name_6B = (s16)func_800888A8_894A8(0, 0, 0x140, 0xF0, 0, 4);
    func_80089B2C_8A72C((s16)D_801064B0_402750_name_6B, 0xC8);
    func_8008D530_8E130((s16)D_801064B0_402750_name_6B, 0, 0, 0);
    D_801064C0_402760_name_6B = SprCreate(3, 5);
    SprPosSet((s16)D_801064C0_402760_name_6B, 0, 0, 0);
    data = DataRead(D_80106388_402628_name_6B[D_801064B4_402754_name_6B][0]);
    i = 0;
    D_801064C4_402764_name_6B = SprAnimRead(data);
    DataClose(data);
    SprAnimSet((s16)D_801064C0_402760_name_6B, 1, (s16)D_801064C4_402764_name_6B, 0);
    func_8008225C_82E5C((s16)D_801064C0_402760_name_6B, 1, 1);
    SprPrioSet((s16)D_801064C0_402760_name_6B, 1, 0x10);
    SprAttrSet((s16)D_801064C0_402760_name_6B, 1, 0x9000);
    SprPosSet((s16)D_801064C0_402760_name_6B, 1, 0xA0, 0xAA);
    func_8008221C_82E1C((s16)D_801064C0_402760_name_6B, 1, 0.0f);
    D_801064CC_40276C_name_6B = SprCreate(3, 5);
    SprPosSet((s16)D_801064CC_40276C_name_6B, 0, 0, 0);
    data = DataRead(D_80106398_402638_name_6B[0]);
    D_801064D0_402770_name_6B = SprAnimRead(data);
    DataClose(data);
    SprAnimSet((s16)D_801064CC_40276C_name_6B, 1, (s16)D_801064D0_402770_name_6B, 0);
    func_8008225C_82E5C((s16)D_801064CC_40276C_name_6B, 1, 1);
    SprPrioSet((s16)D_801064CC_40276C_name_6B, 1, 0x10);
    SprAttrSet((s16)D_801064CC_40276C_name_6B, 1, 0x9000);
    SprPosSet((s16)D_801064CC_40276C_name_6B, 1, 0xA0, 0xA0);
    func_8008221C_82E1C((s16)D_801064C0_402760_name_6B, 1, 0.0f);
    val[0] = D_800FD8A8_FE4A8.lives - D_801064B8_402758_name_6B;
    val[1] = gPlayers[0].coins_mg_bonus + gPlayers[0].coins_mg;
    for (; i < 2; i++) {
        digits[i][0] = OVL6B_ABS(val[i]) / 1000;
        digits[i][1] = (OVL6B_ABS(val[i]) - digits[i][0] * 1000) / 100;
        digits[i][2] = (OVL6B_ABS(val[i]) - digits[i][0] * 1000 - digits[i][1] * 100) / 10;
        digits[i][3] = OVL6B_ABS(val[i]) - digits[i][0] * 1000 - digits[i][1] * 100 - digits[i][2] * 10;
        cnt[i] = 0;
        if (OVL6B_ABS(val[i]) >= 10) {
            cnt[i] = 1;
        }
        if (OVL6B_ABS(val[i]) >= 100) {
            cnt[i] = 2;
        }
        if (OVL6B_ABS(val[i]) >= 1000) {
            cnt[i] = 3;
        }
    }
    for (i = 0; i < 2; i++) {
        j = 0;
        spr = SprCreate(7, 5);
        D_80106510_4027B0_name_6B[i] = spr;
        if (i == 0 || val[i] < 0) {
            file = 0xD0004;
        } else {
            file = 0xD0005;
        }
        data = DataRead(file);
        D_801064D8_402778_name_6B[i] = SprAnimRead(data);
        DataClose(data);
        SprAnimSet(spr, j, (s16)D_801064D8_402778_name_6B[i], 0);
        func_800824F4_830F4(spr, j, -1);
        SprAttrSet(spr, j, 0x8000);
        SprPosSet(spr, j, D_801063A8_402648_name_6B[i][0], D_801063A8_402648_name_6B[i][1]);
        j++;
        SprAnimSet(spr, j, (s16)D_801064D8_402778_name_6B[i], 0);
        func_8008225C_82E5C(spr, j, 1);
        SprPrioSet(spr, j, 0xF);
        SprAttrSet(spr, j, 0x9000);
        SprPosSet(spr, j, 0, 0);
        func_800824F4_830F4(spr, j, 0);
        j++;
        for (k = 0; k < 4; k++, j++) {
            data = DataRead(0xC000D);
            D_801064F0_402790_name_6B[i][k] = SprAnimRead(data);
            DataClose(data);
            SprAnimSet(spr, j, (s16)D_801064F0_402790_name_6B[i][k], 0);
            func_8008225C_82E5C(spr, j, 1);
            SprPrioSet(spr, j, 0xE);
            SprAttrSet(spr, j, 0x9000);
            func_800822A8_82EA8(spr, j, digits[i][k], 0);
            func_800824F4_830F4(spr, j, 0);
            func_8008221C_82E1C(spr, j, 0.0f);
            if (i == 0) {
                if (val[i] == 0) {
                    SprPosSet(spr, j, D_801063B0_402650_name_6B[cnt[i]][k], 2);
                } else {
                    SprPosSet(spr, j, D_801063B0_402650_name_6B[cnt[i]][k] + 4, 2);
                }
            } else if (D_801064B4_402754_name_6B == 0) {
                if (val[i] == 0) {
                    SprPosSet(spr, j, D_801063B0_402650_name_6B[cnt[i]][k], 2);
                } else {
                    SprPosSet(spr, j, D_801063B0_402650_name_6B[cnt[i]][k] + 4, 2);
                }
            } else {
                func_80082450_83050(spr, j, 0xFF, 0, 0);
                SprPosSet(spr, j, D_801063B0_402650_name_6B[cnt[i]][k], 2);
            }
        }
        data = DataRead(0xC000D);
        D_801064E4_402784_name_6B[i] = SprAnimRead(data);
        DataClose(data);
        SprAnimSet(spr, j, (s16)D_801064E4_402784_name_6B[i], 0);
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
                SprPosSet(spr, j, D_801063B0_402650_name_6B[cnt[i]][3 - cnt[i]] - 4, 2);
            }
        } else if (D_801064B4_402754_name_6B == 0) {
            if (val[i] == 0) {
                SprPosSet(spr, j, -1000, 2);
                func_800822A8_82EA8(spr, j, 10, 0);
            } else {
                if (val[i] > 0) {
                    func_800822A8_82EA8(spr, j, 11, 0);
                } else {
                    func_800822A8_82EA8(spr, j, 12, 0);
                }
                SprPosSet(spr, j, D_801063B0_402650_name_6B[cnt[i]][3 - cnt[i]] - 4, 2);
            }
        } else {
            SprPosSet(spr, j, -1000, 2);
            func_800822A8_82EA8(spr, j, 10, 0);
        }
    }
    spr = SprCreate(7, 5);
    D_80106510_4027B0_name_6B[2] = spr;
    data = DataRead(0xD0005);
    D_801064D8_402778_name_6B[2] = SprAnimRead(data);
    DataClose(data);
    SprAnimSet(spr, 0, (s16)D_801064D8_402778_name_6B[2], 0);
    func_800824F4_830F4(spr, 0, -1);
    SprAttrSet(spr, 0, 0x8000);
    SprPosSet(spr, 0, D_801063A8_402648_name_6B[0][0], D_801063A8_402648_name_6B[0][1]);
    SprAnimSet(spr, 1, (s16)D_801064D8_402778_name_6B[2], 0);
    func_8008225C_82E5C(spr, 1, 1);
    SprPrioSet(spr, 1, 0xF);
    SprAttrSet(spr, 1, 0x9000);
    SprPosSet(spr, 1, 0, 0);
    func_800824F4_830F4(spr, 1, 0);
    data = DataRead(0xD0006);
    D_801064BC_40275C_name_6B = SprAnimRead(data);
    DataClose(data);
    SprAnimSet(spr, 2, (s16)D_801064BC_40275C_name_6B, 0);
    func_8008225C_82E5C(spr, 2, 1);
    SprPrioSet(spr, 2, 0xE);
    SprAttrSet(spr, 2, 0x9000);
    func_800824F4_830F4(spr, 2, 0);
    SprPosSet(spr, 2, 0, 2);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_name/3FEAD0", func_80103460_3FF700_name_6B);
#endif

void func_80104224_4004C4_name_6B(void) {
    func_8008CCA8_8D8A8((s16)D_801064B0_402750_name_6B);
}

void func_80104244_4004E4_name_6B(void) {
    Hu3DCamSetPerspective(1, 40.0f, 200.0f, 8000.0f);
    Hu3DCamSetPositionOrientation(1, &D_8010651C_4027BC_name_6B, &D_80106528_4027C8_name_6B, &D_80106534_4027D4_name_6B);
    Hu3DCamUpdateMtx(1);
    CameraViewportSet(1, &D_80106540_4027E0_name_6B, &D_8010654C_4027EC_name_6B);
}

void func_801042AC_40054C_name_6B(void) {
    while (1) {
        func_80104244_4004E4_name_6B();
        HuPrcVSleep();
    }
}

__asm__(".section .rodata");
const char D_80106428_4026C8_name_6B[] = "point1";

__asm__(".section .rodata");
const char D_80106430_4026D0_name_6B[] = "point2";

void func_801042D8_400578_name_6B(void) {
    Vec v;

    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    HuVecCopyXYZ(&v, 0.0f, 0.0f, 0.0f);
    OVL6B_LINK(func_80056D80_57980(&D_80106568_402808_name_6B->pos, &v, &D_80106568_402808_name_6B->pos, 20));
    HuPrcChildWatch();
    func_80029E80_2AA80(D_80106568_402808_name_6B->obj->model[0], 2, 1);
    HuVecCopyXYZ(&D_80106560_402800_name_6B->pos, -6.278950214385986f, 19.16754913330078f, 0.0f);
    HuVecCopyXYZ(&D_80106564_402804_name_6B->pos, 5.623000144958496f, 19.16754913330078f, 0.0f);
    HuPrcVSleep();
    func_8005AA98_5B698(D_80106560_402800_name_6B->obj->model[0]);
    func_8005AA98_5B698(D_80106564_402804_name_6B->obj->model[0]);
    HuPrcVSleep();
    func_8005670C_5730C(&v);
    OVL6B_LINK(func_80056B78_57778(&D_80106560_402800_name_6B->rot, &v, &D_80106560_402800_name_6B->rot, 10));
    OVL6B_LINK(func_80056B78_57778(&D_80106564_402804_name_6B->rot, &v, &D_80106564_402804_name_6B->rot, 10));
    HuPrcChildWatch();
    if (D_801064B4_402754_name_6B == 0) {
        MBMotionSet(D_80106560_402800_name_6B, 6, 0);
        MBMotionSet(D_80106564_402804_name_6B, 6, 0);
        func_800732B0_73EB0(D_801063D8_402678_name_6B[(s8)D_800FD8A8_FE4A8.character] | 0x54);
    } else {
        MBMotionSet(D_80106560_402800_name_6B, 3, 0);
        MBMotionSet(D_80106564_402804_name_6B, 3, 0);
    }
    while (1) {
        if (D_801063A4_402644_name_6B != 0) {
            MBMotionSet(D_80106560_402800_name_6B, 5, 0);
            MBMotionSet(D_80106564_402804_name_6B, 5, 0);
            HuPrcSleep(30);
            break;
        }
        if (D_801063A3_402643_name_6B != 0) {
            break;
        }
        HuPrcVSleep();
    }
    MBMotionShiftSet(D_80106560_402800_name_6B, -1, 0, 10, 2);
    MBMotionShiftSet(D_80106564_402804_name_6B, -1, 0, 10, 2);
    HuVecCopyXYZ(&v, -1.0f, 0.0f, 0.0f);
    OVL6B_LINK(func_80056B78_57778(&D_80106560_402800_name_6B->rot, &v, &D_80106560_402800_name_6B->rot, 10));
    OVL6B_LINK(func_80056B78_57778(&D_80106564_402804_name_6B->rot, &v, &D_80106564_402804_name_6B->rot, 10));
    HuPrcChildWatch();
    func_8005AA48_5B648(D_80106568_402808_name_6B, D_80106428_4026C8_name_6B, D_80106560_402800_name_6B->obj->model[0]);
    func_8005AA48_5B648(D_80106568_402808_name_6B, D_80106430_4026D0_name_6B, D_80106564_402804_name_6B->obj->model[0]);
    func_80029E80_2AA80(D_80106568_402808_name_6B->obj->model[0], 1, 2);
    HuVecCopyXYZ(&v, -100.0f, 0.0f, 0.0f);
    OVL6B_LINK(func_80056D80_57980(&D_80106568_402808_name_6B->pos, &v, &D_80106568_402808_name_6B->pos, 20));
    HuPrcChildWatch();
    while (1) {
        HuPrcVSleep();
    }
}

void func_801046D8_400978_name_6B(void) {
    D_80106558_4027F8_name_6B = omAddPrcObj(func_801042AC_40054C_name_6B, 0x4000, 0, 0);
    D_8010651C_4027BC_name_6B.x = 0.0f;
    D_8010651C_4027BC_name_6B.y = 250.0f;
    D_8010651C_4027BC_name_6B.z = 200.0f;
    D_80106528_4027C8_name_6B.x = 0.0f;
    D_80106528_4027C8_name_6B.y = 0.0f;
    D_80106528_4027C8_name_6B.z = 0.0f;
    D_80106534_4027D4_name_6B.x = 0.0f;
    D_80106534_4027D4_name_6B.y = 1.0f;
    D_80106534_4027D4_name_6B.z = 0.0f;
    D_80106540_4027E0_name_6B.x = 1280.0f;
    D_80106540_4027E0_name_6B.y = 960.0f;
    D_80106540_4027E0_name_6B.z = 511.0f;
    D_8010654C_4027EC_name_6B.x = 640.0f;
    D_8010654C_4027EC_name_6B.y = 480.0f;
    D_8010654C_4027EC_name_6B.z = 511.5f;
    func_80104244_4004E4_name_6B();
    D_80106568_402808_name_6B = func_80043510_44110(0xAA, NULL);
    HuVecCopyXYZ(&D_80106568_402808_name_6B->rot, -1.0f, 0.0f, 0.0f);
    HuVecCopyXYZ(&D_80106568_402808_name_6B->pos, 100.0f, 0.0f, 0.0f);
    D_80106568_402808_name_6B->attr |= 1;
    func_80029EDC_2AADC(D_80106568_402808_name_6B->obj->model[0], 2);
    D_80106560_402800_name_6B = func_80043510_44110(D_801063D0_402670_name_6B[(s8)D_800FD8A8_FE4A8.character], D_800CC8B8_CD4B8[(s8)D_800FD8A8_FE4A8.character]);
    HuVecCopyXYZ(&D_80106560_402800_name_6B->rot, -1.0f, 0.0f, 0.0f);
    D_80106560_402800_name_6B->attr |= 1;
    func_80029EDC_2AADC(D_80106560_402800_name_6B->obj->model[0], 2);
    D_80106564_402804_name_6B = func_80043510_44110(D_801063D0_402670_name_6B[(s8)D_800FD8A8_FE4A8.character2], D_800CC8B8_CD4B8[(s8)D_800FD8A8_FE4A8.character2]);
    HuVecCopyXYZ(&D_80106564_402804_name_6B->rot, -1.0f, 0.0f, 0.0f);
    D_80106564_402804_name_6B->attr |= 1;
    func_80029EDC_2AADC(D_80106564_402804_name_6B->obj->model[0], 2);
    func_8005AA48_5B648(D_80106568_402808_name_6B, D_80106428_4026C8_name_6B, D_80106560_402800_name_6B->obj->model[0]);
    func_8005AA48_5B648(D_80106568_402808_name_6B, D_80106430_4026D0_name_6B, D_80106564_402804_name_6B->obj->model[0]);
    D_8010655C_4027FC_name_6B = omAddPrcObj(func_801042D8_400578_name_6B, 0x4000, 0, 0);
}

void func_801049A4_400C44_name_6B(void) {
    omDelPrcObj(D_80106558_4027F8_name_6B);
    omDelPrcObj(D_8010655C_4027FC_name_6B);
    MBModelKill(D_80106560_402800_name_6B);
    MBModelKill(D_80106564_402804_name_6B);
    MBModelKill(D_80106568_402808_name_6B);
}

void func_801049F4_400C94_name_6B(void) {
    switch (D_801064B4_402754_name_6B) {
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

void func_80104A60_400D00_name_6B(s8 idx) {
    f32 scale;
    s32 i;
    s32 n = idx;

    i = 0;
    do {
        i++;
        SprAttrReset((s16)D_80106510_4027B0_name_6B[n], i, 0x8000);
    } while (i < 6);
    for (scale = 0.0f; scale < 1.0; scale += 0.3) {
        i = 0;
        do {
            i++;
            SprScaleSet((s16)D_80106510_4027B0_name_6B[n], i, scale, scale);
        } while (i < 6);
        if (D_801063A0_402640_name_6B == 0) {
            HuPrcVSleep();
        }
    }
    i = 0;
    do {
        i++;
        SprScaleSet((s16)D_80106510_4027B0_name_6B[n], i, 1.0f, 1.0f);
    } while (i < 6);
}

void func_80104BA8_400E48_name_6B(void) {
    f32 scale;
    s32 i;

    i = 0;
    do {
        i++;
        SprAttrReset((s16)D_80106510_4027B0_name_6B[0], i, 0x8000);
        SprAttrReset((s16)D_80106510_4027B0_name_6B[1], i, 0x8000);
    } while (i < 6);
    for (scale = 0.0f; scale < 1.0; scale += 0.3) {
        i = 0;
        do {
            i++;
            SprScaleSet((s16)D_80106510_4027B0_name_6B[0], i, scale, scale);
            SprScaleSet((s16)D_80106510_4027B0_name_6B[1], i, scale, scale);
        } while (i < 6);
        if (D_801063A0_402640_name_6B == 0) {
            HuPrcVSleep();
        }
    }
    i = 0;
    do {
        i++;
        SprScaleSet((s16)D_80106510_4027B0_name_6B[0], i, 1.0f, 1.0f);
        SprScaleSet((s16)D_80106510_4027B0_name_6B[1], i, 1.0f, 1.0f);
    } while (i < 6);
}

void func_80104D28_400FC8_name_6B(void) {
    f32 scale;
    s32 i;

    i = 0;
    do {
        i++;
        SprScaleSet((s16)D_80106510_4027B0_name_6B[0], i, 1.0f, 1.0f);
        SprScaleSet((s16)D_80106510_4027B0_name_6B[1], i, 1.0f, 1.0f);
    } while (i < 6);
    scale = 1.0f;
    do {
        i = 0;
        do {
            i++;
            SprScaleSet((s16)D_80106510_4027B0_name_6B[0], i, scale, scale);
            SprScaleSet((s16)D_80106510_4027B0_name_6B[1], i, scale, scale);
        } while (i < 6);
        if (D_801063A0_402640_name_6B == 0) {
            HuPrcVSleep();
        }
        scale -= 0.3f;
    } while (scale > 0.0f);
    i = 0;
    do {
        i++;
        SprAttrSet((s16)D_80106510_4027B0_name_6B[0], i, 0x8000);
        SprAttrSet((s16)D_80106510_4027B0_name_6B[1], i, 0x8000);
    } while (i < 6);
}

// masked 11 (twin of ovl_6B/6C): in the "D_8010679C == 0 && val[i] != 0" arm retail reloads val[i] for
// the > 0 sign test (no CSE with the != 0 test); ours reuses it. Shared 12/tail blocks agree.
#ifdef NON_MATCHING
void func_80104EA8_401148_name_6B(void) {
    s16 val[4];
    s16 cnt[4];
    s16 digits[4][4];
    s32 i;
    s32 k;
    s32 j;

    val[0] = D_800FD8A8_FE4A8.lives - D_801064B8_402758_name_6B;
    if (D_800FD8A8_FE4A8.streak > 0) {
        val[1] = (gPlayers[0].coins_mg + gPlayers[0].coins_mg_bonus) * D_800FD8A8_FE4A8.streak - D_801063A6_402646_name_6B;
    } else {
        val[1] = gPlayers[0].coins_mg + gPlayers[0].coins_mg_bonus - D_801063A6_402646_name_6B;
    }
    for (i = 0; i < 2; i++) {
        digits[i][0] = OVL6B_ABS(val[i]) / 1000;
        digits[i][1] = (OVL6B_ABS(val[i]) - digits[i][0] * 1000) / 100;
        digits[i][2] = (OVL6B_ABS(val[i]) - digits[i][0] * 1000 - digits[i][1] * 100) / 10;
        digits[i][3] = OVL6B_ABS(val[i]) - digits[i][0] * 1000 - digits[i][1] * 100 - digits[i][2] * 10;
        cnt[i] = 0;
        if (OVL6B_ABS(val[i]) >= 10) {
            cnt[i] = 1;
        }
        if (OVL6B_ABS(val[i]) >= 100) {
            cnt[i] = 2;
        }
        if (OVL6B_ABS(val[i]) >= 1000) {
            cnt[i] = 3;
        }
    }
    for (i = 0; i < 2; i++) {
        j = 2;
        for (k = 0; k < 4; k++, j++) {
            func_800822A8_82EA8((s16)D_80106510_4027B0_name_6B[i], j, digits[i][k], 0);
            if (i == 0) {
                if (val[i] == 0) {
                    SprPosSet((s16)D_80106510_4027B0_name_6B[i], j, D_801063F0_402690_name_6B[cnt[i]][k], 2);
                } else {
                    SprPosSet((s16)D_80106510_4027B0_name_6B[i], j, D_801063F0_402690_name_6B[cnt[i]][k] + 4, 2);
                }
            } else if (D_801064B4_402754_name_6B == 0 && val[i] != 0) {
                SprPosSet((s16)D_80106510_4027B0_name_6B[i], j, D_801063F0_402690_name_6B[cnt[i]][k] + 4, 2);
            } else {
                SprPosSet((s16)D_80106510_4027B0_name_6B[i], j, D_801063F0_402690_name_6B[cnt[i]][k], 2);
            }
        }
        if (i == 0) {
            if (val[i] == 0) {
                SprPosSet((s16)D_80106510_4027B0_name_6B[i], j, -1000, -2);
                func_800822A8_82EA8((s16)D_80106510_4027B0_name_6B[i], j, 10, 0);
            } else {
                if (val[i] > 0) {
                    func_800822A8_82EA8((s16)D_80106510_4027B0_name_6B[i], j, 11, 0);
                } else {
                    func_800822A8_82EA8((s16)D_80106510_4027B0_name_6B[i], j, 12, 0);
                }
                SprPosSet((s16)D_80106510_4027B0_name_6B[i], j, D_801063F0_402690_name_6B[cnt[i]][3 - cnt[i]] - 4, 2);
            }
        } else if (D_801064B4_402754_name_6B == 0 && val[i] != 0) {
            if (val[i] > 0) {
                func_800822A8_82EA8((s16)D_80106510_4027B0_name_6B[i], j, 11, 0);
            } else {
                func_800822A8_82EA8((s16)D_80106510_4027B0_name_6B[i], j, 12, 0);
            }
            SprPosSet((s16)D_80106510_4027B0_name_6B[i], j, D_801063F0_402690_name_6B[cnt[i]][3 - cnt[i]] - 4, 2);
        } else {
            SprPosSet((s16)D_80106510_4027B0_name_6B[i], j, -1000, -2);
            func_800822A8_82EA8((s16)D_80106510_4027B0_name_6B[i], j, 10, 0);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6B_name/3FEAD0", func_80104EA8_401148_name_6B);
#endif

void func_80105530_4017D0_name_6B(void) {
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
    while ((s16)coins > D_801063A6_402646_name_6B) {
        D_801063A6_402646_name_6B += step;
        if ((s16)coins <= D_801063A6_402646_name_6B) {
            D_800FD8A8_FE4A8.coins += step - ((u8)D_801063A6_402646_name_6B - coins);
            D_801063A6_402646_name_6B = coins;
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
                func_80104A60_400D00_name_6B(2);
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
        func_80104EA8_401148_name_6B();
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
            func_80104A60_400D00_name_6B(2);
        }
    }
    func_80104EA8_401148_name_6B();
}

void func_80105808_401AA8_name_6B(void) {
    s16 size[2];
    s32 win;
    s8 choice;

    SprAttrSet((s16)D_801064C0_402760_name_6B, 1, 0x8000);
    HuPrcSleep(30);
    PlayMusic(0x14);
    SprAttrReset((s16)D_801064CC_40276C_name_6B, 1, 0x8000);
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
        D_801063A4_402644_name_6B = 1;
        HuPrcSleep(30);
    }
    D_801063A2_402642_name_6B = choice;
    D_801063A1_402641_name_6B = 1;
}

void func_80105988_401C28_name_6B(void) {
    s16 size[2];
    char buf[8];
    GAMEMES mesX;
    GAMEMES mesN;
    s16 win;

    if (D_800FD8A8_FE4A8.streak >= 2) {
        sprintf(buf, D_80106424_4026C4_name_6B, D_800FD8A8_FE4A8.streak);
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
        func_80104EA8_401148_name_6B();
        PlaySound(0x33D);
        HuPrcSleep(0x19);
    }
}

void func_80105B38_401DD8_name_6B(void) {
    s16 i;
    s16 failed;

    switch (D_801064B4_402754_name_6B) {
    case 0:
        HuPrcSleep(0x24);
        func_80079428_7A028(0x44);
        break;
    case 1:
        HuPrcSleep(0x24);
        func_80079428_7A028(0x45);
        break;
    }
    SprAttrReset((s16)D_801064C0_402760_name_6B, 1, 0x8000);
    omAddPrcObj(func_801049F4_400C94_name_6B, 0x300, 0x2500, 0);
    HuPrcSleep(0x3C);
    if (D_801064B4_402754_name_6B == 0) {
        HuPrcSleep(30);
    } else {
        HuPrcSleep(20);
    }
    failed = 0;
    switch (D_801064B4_402754_name_6B) {
    case 0:
        func_80104A60_400D00_name_6B(1);
        for (i = 0; i < 30; i++) {
            if (D_801063A0_402640_name_6B == 1) {
                break;
            }
            HuPrcVSleep();
        }
        func_80105988_401C28_name_6B();
        func_80105530_4017D0_name_6B();
        goto done;
    case 1:
        if (D_800FD8A8_FE4A8.lives <= 0) {
            failed = 1;
        }
        D_800FD8A8_FE4A8.lives--;
        func_80104EA8_401148_name_6B();
        if (D_800FD8A8_FE4A8.lives < 0) {
            D_800FD8A8_FE4A8.lives = 0;
        }
        func_80104BA8_400E48_name_6B();
        for (i = 0; i < 30; i++) {
            if (D_801063A0_402640_name_6B == 1) {
                break;
            }
            HuPrcVSleep();
        }
    done:
        func_80104D28_400FC8_name_6B();
        break;
    }
    if (failed != 0) {
        func_80105808_401AA8_name_6B();
    } else {
        D_801063A3_402643_name_6B = 1;
    }
}

s32 func_80105D14_401FB4_name_6B(s16 minigame) {
    s32 total;

    total = gPlayers[0].coins_mg_bonus + gPlayers[0].coins_mg;
    switch (minigame) {
    case 0x24:
        if (total < D_80106410_4026B0_name_6B[0][D_800FD8A8_FE4A8.difficulty]) {
            return 0;
        }
        break;
    case 0x47:
        if (total < D_80106410_4026B0_name_6B[1][D_800FD8A8_FE4A8.difficulty]) {
            return 0;
        }
        break;
    case 0x48:
        if (total < D_80106410_4026B0_name_6B[2][D_800FD8A8_FE4A8.difficulty]) {
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

void func_80105DE0_402080_name_6B(void) {
    s32 i;
    s32 j;

    SprKill((s16)D_801064C0_402760_name_6B);
    SprKill((s16)D_801064CC_40276C_name_6B);
    for (i = 0; i < 3; i++) {
        SprKill((s16)D_80106510_4027B0_name_6B[i]);
        SprAnimKill((s16)D_801064D8_402778_name_6B[i]);
    }
    SprAnimKill((s16)D_801064BC_40275C_name_6B);
    for (i = 0; i < 2; i++) {
        SprAnimKill((s16)D_801064E4_402784_name_6B[i]);
        for (j = 0; j < 4; j++) {
            SprAnimKill((s16)D_801064F0_402790_name_6B[i][j]);
        }
    }
    SprAnimKill((s16)D_801064C4_402764_name_6B);
    SprAnimKill((s16)D_801064D0_402770_name_6B);
}

void func_80105EF8_402198_name_6B(void) {
    func_80028334_28F34(D_800FD2A6_FDEA6, 2);
    func_80029EDC_2AADC(D_800FD2A6_FDEA6, 1);
    if (func_80105D14_401FB4_name_6B(GwSystem.chosenMinigameIndex) != 0) {
        D_801064B4_402754_name_6B = 0;
        _SetFlag(0x16);
        D_800FD8A8_FE4A8.streak++;
        PlayMusic(0x42);
    } else {
        D_801064B4_402754_name_6B = 1;
        _ClearFlag(0x16);
        D_800FD8A8_FE4A8.streak = 0;
        PlayMusic(0x43);
    }
    D_801064B6_402756_name_6B = D_800FD8A8_FE4A8.coins;
    D_801064B8_402758_name_6B = D_800FD8A8_FE4A8.lives;
    func_80103460_3FF700_name_6B();
    func_801046D8_400978_name_6B();
    func_80029E80_2AA80(D_800FA618_FB218->obj->model[0], 2, 1);
    func_80029E80_2AA80(((MBModel*)gPlayers[0].unk_24)->obj->model[0], 2, 1);
    func_80029E80_2AA80(((MBModel*)gPlayers[1].unk_24)->obj->model[0], 2, 1);
    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    func_80105B38_401DD8_name_6B();
    HuPrcSleep(30);
    func_800794A8_7A0A8(0x5A);
    InitFadeOut(0, 0x10);
    HuPrcSleep(0x11);
    func_80104224_4004C4_name_6B();
    func_801049A4_400C44_name_6B();
    func_80105DE0_402080_name_6B();
    switch (D_801063A2_402642_name_6B) {
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

void func_801060F8_402398_name_6B(void) {
    func_80103284_3FF524_name_6B();
    func_80074DB8_759B8(1);
    omAddPrcObj(func_80105EF8_402198_name_6B, 0x1005, 0x1000, 0);
}

void func_80106134_4023D4_name_6B(void) {
    if (func_80075390_75F90(OVL6B_FLAG_BASE + 0x29) != 0) {
        SetPlayerOntoChain(0, 0, 22);
    } else if (func_80075390_75F90(OVL6B_FLAG_BASE + 0x28) != 0) {
        SetPlayerOntoChain(0, 0, 19);
    } else if (func_80075390_75F90(OVL6B_FLAG_BASE + 0x27) != 0) {
        SetPlayerOntoChain(0, 0, 14);
    } else if (func_80075390_75F90(OVL6B_FLAG_BASE + 0x26) != 0) {
        SetPlayerOntoChain(0, 0, 12);
    } else if (func_80075390_75F90(OVL6B_FLAG_BASE + 0x25) != 0) {
        SetPlayerOntoChain(0, 0, 10);
    } else if (func_80075390_75F90(OVL6B_FLAG_BASE + 0x24) != 0) {
        SetPlayerOntoChain(0, 0, 5);
    } else {
        SetPlayerOntoChain(0, 0, 0);
    }
    omOvlReturnEx(1);
}

/* .data (0x4024B0-0x4026C0,80106210-80106420) */
board_overlay_entrypoint D_80106210_4024B0_name_6B[6] = { { 0, func_801031D0_3FF470_name_6B }, { 1, func_8010320C_3FF4AC_name_6B }, { 2, func_80103310_3FF5B0_name_6B }, { 3, func_801060F8_402398_name_6B }, { 4, func_80106134_4023D4_name_6B }, { -1, NULL } };
CoasterSpaceFlag D_80106240_4024E0_name_6B[7] = { { 0, 45 }, { 1, 46 }, { 2, 47 }, { 3, 48 }, { 4, 49 }, { 5, 50 }, { -1, -1 } };
s32 D_8010625C_4024FC_name_6B[6] = { 0x000A010F, 0x000A0110, 0x000A0111, 0x000A0112, 0x000A0113, 0x000A0114 };
s32 D_80106274_402514_name_6B[6] = { 0x000005DA, 0x000005DB, 0x000005DC, 0x000005DD, 0x00000000, 0x000005E1 };
s32 D_8010628C_40252C_name_6B[3] = { 0x000005DE, 0x000005DF, 0x000005E0 };
s32 D_80106298_402538_name_6B[3] = { 0x000005D2, 0x000005D4, 0x000005D6 };
s16 D_801062A4_402544_name_6B[4][2] = { { 0x0064, 0x003C }, { 0x0064, 0x004E }, { 0x0064, 0x0060 }, { 0x0064, 0x0072 } };
s16 D_801062B4_402554_name_6B = 0x00C8;
s16 D_801062B6_402556_name_6B = 0x003C;
s16 D_801062B8_402558_name_6B = 0x00C8;
s16 D_801062BA_40255A_name_6B = 0x004E;
s16 D_801062BC_40255C_name_6B[2] = { 0x0018, 0x003C };
BoardEventListEntry D_801062C0_402560_name_6B[2] = { { 1, 1, func_8010333C_3FF5DC_name_6B }, { 0, 0, NULL } };
BoardEventListEntry D_801062D0_402570_name_6B[2] = { { 1, 1, func_80103360_3FF600_name_6B }, { 0, 0, NULL } };
BoardEventListEntry D_801062E0_402580_name_6B[2] = { { 1, 1, func_80103384_3FF624_name_6B }, { 0, 0, NULL } };
BoardEventListEntry D_801062F0_402590_name_6B[2] = { { 1, 1, func_801033A8_3FF648_name_6B }, { 0, 0, NULL } };
BoardEventListEntry D_80106300_4025A0_name_6B[2] = { { 1, 1, func_801033CC_3FF66C_name_6B }, { 0, 0, NULL } };
BoardEventListEntry D_80106310_4025B0_name_6B[2] = { { 1, 1, func_801033F0_3FF690_name_6B }, { 0, 0, NULL } };
BoardEventListEntry D_80106320_4025C0_name_6B[2] = { { 1, 1, func_80103414_3FF6B4_name_6B }, { 0, 0, NULL } };
BoardEventListEntry D_80106330_4025D0_name_6B[2] = { { 1, 1, func_80103438_3FF6D8_name_6B }, { 0, 0, NULL } };
BoardEventTableEntry D_80106340_4025E0_name_6B[9] = { { 0, D_801062C0_402560_name_6B }, { 1, D_801062D0_402570_name_6B }, { 2, D_801062E0_402580_name_6B }, { 3, D_801062F0_402590_name_6B }, { 4, D_80106300_4025A0_name_6B }, { 5, D_80106310_4025B0_name_6B }, { 6, D_80106320_4025C0_name_6B }, { 11, D_80106330_4025D0_name_6B }, { -1, NULL } };
s32 D_80106388_402628_name_6B[2][2] = { { 0x000D0000, 0x000D0001 }, { 0x000B00E1, 0x000B00E2 } };
s32 D_80106398_402638_name_6B[2] = { 0x000D0002, 0x000D0003 };
s8 D_801063A0_402640_name_6B = 0;
s8 D_801063A1_402641_name_6B = 0;
s8 D_801063A2_402642_name_6B = -1;
s8 D_801063A3_402643_name_6B = 0;
s8 D_801063A4_402644_name_6B = 0;
s8 D_801063A5_402645_name_6B = 0; /* padding */
s16 D_801063A6_402646_name_6B = 0;
s16 D_801063A8_402648_name_6B[2][2] = { { 0x0050, 0x0034 }, { 0x0108, 0x0034 } };
s16 D_801063B0_402650_name_6B[4][4] = { { -1000, -1000, -1000, 0 }, { -1000, -1000, -4, 4 }, { -1000, -8, 0, 8 }, { -14, -6, 2, 10 } };
u8 D_801063D0_402670_name_6B[8] = { 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x00, 0x00 };
s32 D_801063D8_402678_name_6B[6] = { 0x00020000, 0x00030000, 0x00070000, 0x00040000, 0x00050000, 0x00060000 };
s16 D_801063F0_402690_name_6B[4][4] = { { -1000, -1000, -1000, 0 }, { -1000, -1000, -4, 4 }, { -1000, -8, 0, 8 }, { -14, -6, 2, 10 } };
u8 D_80106410_4026B0_name_6B[3][3] = { { 0x00, 0x0A, 0x0F }, { 0x00, 0x0A, 0x0F }, { 0x00, 0x00, 0x0F } };
s8 D_80106419_4026B9_name_6B = 0; /* padding to .rodata */
s8 D_8010641A_4026BA_name_6B = 0;
s8 D_8010641B_4026BB_name_6B = 0;
s32 D_8010641C_4026BC_name_6B[1] = { 0 };
