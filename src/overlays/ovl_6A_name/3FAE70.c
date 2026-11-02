#include "common.h"
#include "ovl_6A.h"

#define OVL6A_ABS(x) ((x) < 0 ? -(s32)(x) : (x))
/* Waits on a mover: makes it a child of the current process. */
#define OVL6A_LINK(call) do { Process* _p = (call); HuPrcChildLink(HuPrcCurrentGet(), _p); } while (0)

void func_80102830_3FAE70_name_6A(void) {
    CoasterSpaceFlag* entry;

    entry = D_80106240_3FE880_name_6A;
    while (entry->space >= 0) {
        if (func_80075390_75F90(entry->flag) != 0) {
            BoardSpaceTypeSet(entry->space, 1);
        }
        entry++;
    }
}

s32 func_8010288C_3FAECC_name_6A(s32 bit) {
    return D_80106460_3FEAA0_name_6A.flags[bit / 8] & (1 << (bit % 8));
}

__asm__(".section .rodata");
const char D_80106420_3FEA60_name_6A[] = "%2d";

void func_801028D0_3FAF10_name_6A(void) {
    s16 size[2];
    void* data;
    s32 i;
    s32 win;

    D_80106494_3FEAD4_name_6A = func_8005E688_5F288(1, 0);
    data = DataRead(D_8010625C_3FE89C_name_6A[(s8)D_80106460_3FEAA0_name_6A.character]);
    i = 0;
    D_80106494_3FEAD4_name_6A->unk0C[0] = SprAnimRead(data);
    SprAnimSet(D_80106494_3FEAD4_name_6A->unk0A, 0, D_80106494_3FEAD4_name_6A->unk0C[0], 0);
    SprPrioSet(D_80106494_3FEAD4_name_6A->unk0A, 0, 0x10);
    SprAttrSet(D_80106494_3FEAD4_name_6A->unk0A, 0, 0x1000);
    SprPosSet(D_80106494_3FEAD4_name_6A->unk0A, 0, 0x3E, 0x5F);
    DataClose(data);
    D_80106478_3FEAB8_name_6A[6] = func_80057480_58080(D_801062BC_3FE8FC_name_6A[0], D_801062BC_3FE8FC_name_6A[1], 0x18, 5);
    for (; i < 4; i++) {
        func_8008DACC_8E6CC(1, size, D_80106274_3FE8B4_name_6A[i]);
        D_80106478_3FEAB8_name_6A[i] = (s16)func_800888A8_894A8(D_801062A4_3FE8E4_name_6A[i][0], D_801062A4_3FE8E4_name_6A[i][1], size[0], size[1], 0, 0);
        func_80089B2C_8A72C((s16)D_80106478_3FEAB8_name_6A[i], 0);
        func_80089A48_8A648((s16)D_80106478_3FEAB8_name_6A[i], 0);
        func_800890CC_89CCC((s16)D_80106478_3FEAB8_name_6A[i], (void*)D_80106274_3FE8B4_name_6A[i], -1, -1);
    }
    func_8008DACC_8E6CC(1, size, D_8010628C_3FE8CC_name_6A[D_80106460_3FEAA0_name_6A.difficulty]);
    i = 4;
    D_80106478_3FEAB8_name_6A[i] = (s16)func_800888A8_894A8(D_801062B4_3FE8F4_name_6A, D_801062B6_3FE8F6_name_6A, size[0], size[1], 0, 0);
    func_80089B2C_8A72C((s16)D_80106478_3FEAB8_name_6A[i], 0);
    func_80089A48_8A648((s16)D_80106478_3FEAB8_name_6A[i], 0);
    func_800890CC_89CCC((s16)D_80106478_3FEAB8_name_6A[i], (void*)D_8010628C_3FE8CC_name_6A[D_80106460_3FEAA0_name_6A.difficulty], -1, -1);
    sprintf(D_80106498_3FEAD8_name_6A, D_80106420_3FEA60_name_6A, D_80106460_3FEAA0_name_6A.chapter);
    func_8008D974_8E574(D_80106498_3FEAD8_name_6A, 0);
    sprintf(D_801064A0_3FEAE0_name_6A, D_80106420_3FEA60_name_6A, D_80106460_3FEAA0_name_6A.lives);
    func_8008D974_8E574(D_801064A0_3FEAE0_name_6A, 1);
    sprintf(D_801064A8_3FEAE8_name_6A, D_80106420_3FEA60_name_6A, D_80106460_3FEAA0_name_6A.coins);
    func_8008D974_8E574(D_801064A8_3FEAE8_name_6A, 2);
    i = 5;
    func_8008DACC_8E6CC(1, size, D_80106274_3FE8B4_name_6A[i]);
    win = func_800888A8_894A8(D_801062B8_3FE8F8_name_6A, D_801062BA_3FE8FA_name_6A, size[0], size[1] * 2, 0, 0);
    D_80106478_3FEAB8_name_6A[i] = win;
    D_800F920C_F9E0C[win].unk28 = 0x12;
    func_80089B2C_8A72C((s16)D_80106478_3FEAB8_name_6A[i], 0);
    func_80089A48_8A648((s16)D_80106478_3FEAB8_name_6A[i], 0);
    func_80089308_89F08((s16)D_80106478_3FEAB8_name_6A[i], D_80106498_3FEAD8_name_6A, 0);
    func_80089308_89F08((s16)D_80106478_3FEAB8_name_6A[i], D_801064A0_3FEAE0_name_6A, 1);
    func_80089308_89F08((s16)D_80106478_3FEAB8_name_6A[i], D_801064A8_3FEAE8_name_6A, 2);
    func_800890CC_89CCC((s16)D_80106478_3FEAB8_name_6A[i], (void*)D_80106274_3FE8B4_name_6A[i], -1, -1);
}

void func_80102C88_3FB2C8_name_6A(void) {
    s32 i;

    for (i = 0; i < 7; i++) {
        func_8008CCA8_8D8A8((s16)D_80106478_3FEAB8_name_6A[i]);
    }
    HuMemDirectFree(D_80106494_3FEAD4_name_6A);
}

__asm__(".section .rodata");
const char D_80106424_3FEA64_name_6A[] = "%d";

void func_80102CE4_3FB324_name_6A(void) {
    char buf[8];
    s32 choice;

again:
    {
        sprintf(buf, D_80106424_3FEA64_name_6A, D_800FD8A8_FE4A8.stage + 1);
        MBDlgWinInsertCreateY(0x29, 0x5CD, buf, NULL, NULL, NULL, NULL, 0xAA);
        choice = func_8008BB48_8C748(mbDlgWinId, 0, 1);
        MBDlgWinClose();
        func_80056168_56D68();
        HuPrcVSleep();
        if (choice == 0) {
            func_8007E0C8_7ECC8(&D_80106460_3FEAA0_name_6A);
            if (func_8010288C_3FAECC_name_6A(0) != 0) {
                func_801028D0_3FAF10_name_6A();
                sprintf(buf, D_80106424_3FEA64_name_6A, D_80106460_3FEAA0_name_6A.stage + 1);
                MBDlgWinInsertCreateY(0x29, 0x5CF, buf, NULL, NULL, NULL, NULL, 0xAA);
                choice = func_8008BB48_8C748(mbDlgWinId, 0, 0);
                MBDlgWinClose();
                func_80056168_56D68();
                HuPrcVSleep();
                func_80102C88_3FB2C8_name_6A();
                if (choice != 0) {
                    goto again;
                }
            }
            func_800753D4_75FD4(0);
            _ClearFlag(0);
            func_8007E018_7EC18();
            func_8007E0C8_7ECC8(&D_80106460_3FEAA0_name_6A);
            func_801028D0_3FAF10_name_6A();
            MBDlgWinInsertCreateY(0x29, 0x5D0, NULL, NULL, NULL, NULL, NULL, 0xAA);
            choice = func_8008BB48_8C748(mbDlgWinId, 0, 1);
            MBDlgWinClose();
            func_80056168_56D68();
            func_80102C88_3FB2C8_name_6A();
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
    MBDlgWinExecY(0x29, D_80106298_3FE8D8_name_6A[D_800FD8A8_FE4A8.difficulty], 0xAA);
}

void func_801030B8_3FB6F8_name_6A(s32 sign) {
    s16 size[2];
    s32 win;
    s32 name;

    if (func_80075390_75F90(sign + OVL6A_FLAG_BASE) == 0) {
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

void func_801031D0_3FB810_name_6A(void) {
    D_800FD8A8_FE4A8.stage = OVL6A_STAGE;
    omInitObjMan(10, 0);
    omOvlGotoEx(OVL6A_NEXT_SCENE, OVL6A_NEXT_ENTRY, 0x192);
}

void func_8010320C_3FB84C_name_6A(void) {
    omInitObjMan(10, 0);
    SetPlayerOntoChain(0, 0, 0);
    func_80075424_76024(OVL6A_FLAG_BASE + 0x1E);
    func_80075424_76024(OVL6A_FLAG_BASE + 0x1F);
    func_80075424_76024(OVL6A_FLAG_BASE + 0x20);
    func_80075424_76024(OVL6A_FLAG_BASE + 0x21);
    func_80075424_76024(OVL6A_FLAG_BASE + 0x22);
    func_80075424_76024(OVL6A_FLAG_BASE + 0x23);
    func_800753D4_75FD4(0x26);
    func_80073410_74010(-1);
    omOvlReturnEx(1);
}

void func_80103284_3FB8C4_name_6A(void) {
    omInitObjMan(0x50, 0x28);
    func_80020070_20C70(2);
    func_80026D28_27928(1);
    func_80026DAC_279AC(0, 0x78, 0x78, 0x78);
    func_80026DAC_279AC(1, 0x40, 0x40, 0x60);
    func_80026E00_27A00(1, -100.0f, 100.0f, 300.0f);
    func_80074154_74D54(OVL6A_BOARD_MODEL, OVL6A_BOARD_FILE);
    EventTableHydrate(D_80106340_3FE980_name_6A);
    func_80102830_3FAE70_name_6A();
}

void func_80103310_3FB950_name_6A(void) {
    func_80103284_3FB8C4_name_6A();
    func_80074DB8_759B8(0);
    PlayMusic(OVL6A_MUSIC);
}

void func_8010333C_3FB97C_name_6A(void) {
    func_80073410_74010(0x1E);
    func_801030B8_3FB6F8_name_6A(0x1E);
}

void func_80103360_3FB9A0_name_6A(void) {
    func_80073410_74010(0x1F);
    func_801030B8_3FB6F8_name_6A(0x1F);
}

void func_80103384_3FB9C4_name_6A(void) {
    func_80073410_74010(0x20);
    func_801030B8_3FB6F8_name_6A(0x20);
}

void func_801033A8_3FB9E8_name_6A(void) {
    func_80073410_74010(0x21);
    func_801030B8_3FB6F8_name_6A(0x21);
}

void func_801033CC_3FBA0C_name_6A(void) {
    func_80073410_74010(0x22);
    func_801030B8_3FB6F8_name_6A(0x22);
}

void func_801033F0_3FBA30_name_6A(void) {
    func_80073410_74010(0x23);
    func_801030B8_3FB6F8_name_6A(0x23);
}

void func_80103414_3FBA54_name_6A(void) {
    func_80073410_74010(-2);
    func_80102CE4_3FB324_name_6A();
}

void func_80103438_3FBA78_name_6A(void) {
    func_80074FAC_75BAC(7, 0, 1, 1);
}

#ifdef NON_MATCHING
void func_80103460_3FBAA0_name_6A(void) {
    s16 cnt[4];
    s16 digits[2][4];
    s16 val[2];
    s32 spr;
    s16 i;
    s16 j;
    s16 k;
    s32 file;
    void* data;

    D_801064B0_3FEAF0_name_6A = (s16)func_800888A8_894A8(0, 0, 0x140, 0xF0, 0, 4);
    func_80089B2C_8A72C((s16)D_801064B0_3FEAF0_name_6A, 0xC8);
    func_8008D530_8E130((s16)D_801064B0_3FEAF0_name_6A, 0, 0, 0);
    D_801064C0_3FEB00_name_6A = SprCreate(3, 5);
    SprPosSet((s16)D_801064C0_3FEB00_name_6A, 0, 0, 0);
    data = DataRead(D_80106388_3FE9C8_name_6A[D_801064B4_3FEAF4_name_6A][0]);
    i = 0;
    D_801064C4_3FEB04_name_6A = SprAnimRead(data);
    DataClose(data);
    SprAnimSet((s16)D_801064C0_3FEB00_name_6A, 1, (s16)D_801064C4_3FEB04_name_6A, 0);
    func_8008225C_82E5C((s16)D_801064C0_3FEB00_name_6A, 1, 1);
    SprPrioSet((s16)D_801064C0_3FEB00_name_6A, 1, 0x10);
    SprAttrSet((s16)D_801064C0_3FEB00_name_6A, 1, 0x9000);
    SprPosSet((s16)D_801064C0_3FEB00_name_6A, 1, 0xA0, 0xAA);
    func_8008221C_82E1C((s16)D_801064C0_3FEB00_name_6A, 1, 0.0f);
    D_801064CC_3FEB0C_name_6A = SprCreate(3, 5);
    SprPosSet((s16)D_801064CC_3FEB0C_name_6A, 0, 0, 0);
    data = DataRead(D_80106398_3FE9D8_name_6A[0]);
    D_801064D0_3FEB10_name_6A = SprAnimRead(data);
    DataClose(data);
    SprAnimSet((s16)D_801064CC_3FEB0C_name_6A, 1, (s16)D_801064D0_3FEB10_name_6A, 0);
    func_8008225C_82E5C((s16)D_801064CC_3FEB0C_name_6A, 1, 1);
    SprPrioSet((s16)D_801064CC_3FEB0C_name_6A, 1, 0x10);
    SprAttrSet((s16)D_801064CC_3FEB0C_name_6A, 1, 0x9000);
    SprPosSet((s16)D_801064CC_3FEB0C_name_6A, 1, 0xA0, 0xA0);
    func_8008221C_82E1C((s16)D_801064C0_3FEB00_name_6A, 1, 0.0f);
    val[0] = D_800FD8A8_FE4A8.lives - D_801064B8_3FEAF8_name_6A;
    val[1] = gPlayers[0].coins_mg_bonus + gPlayers[0].coins_mg;
    for (; i < 2; i++) {
        digits[i][0] = OVL6A_ABS(val[i]) / 1000;
        digits[i][1] = (OVL6A_ABS(val[i]) - digits[i][0] * 1000) / 100;
        digits[i][2] = (OVL6A_ABS(val[i]) - digits[i][0] * 1000 - digits[i][1] * 100) / 10;
        digits[i][3] = OVL6A_ABS(val[i]) - digits[i][0] * 1000 - digits[i][1] * 100 - digits[i][2] * 10;
        cnt[i] = 0;
        if (OVL6A_ABS(val[i]) >= 10) {
            cnt[i] = 1;
        }
        if (OVL6A_ABS(val[i]) >= 100) {
            cnt[i] = 2;
        }
        if (OVL6A_ABS(val[i]) >= 1000) {
            cnt[i] = 3;
        }
    }
    for (i = 0; i < 2; i++) {
        j = 0;
        spr = SprCreate(7, 5);
        D_80106510_3FEB50_name_6A[i] = spr;
        if (i == 0 || val[i] < 0) {
            file = 0xD0004;
        } else {
            file = 0xD0005;
        }
        data = DataRead(file);
        D_801064D8_3FEB18_name_6A[i] = SprAnimRead(data);
        DataClose(data);
        SprAnimSet(spr, j, (s16)D_801064D8_3FEB18_name_6A[i], 0);
        func_800824F4_830F4(spr, j, -1);
        SprAttrSet(spr, j, 0x8000);
        SprPosSet(spr, j, D_801063A8_3FE9E8_name_6A[i][0], D_801063A8_3FE9E8_name_6A[i][1]);
        j++;
        SprAnimSet(spr, j, (s16)D_801064D8_3FEB18_name_6A[i], 0);
        func_8008225C_82E5C(spr, j, 1);
        SprPrioSet(spr, j, 0xF);
        SprAttrSet(spr, j, 0x9000);
        SprPosSet(spr, j, 0, 0);
        func_800824F4_830F4(spr, j, 0);
        j++;
        for (k = 0; k < 4; k++, j++) {
            data = DataRead(0xC000D);
            D_801064F0_3FEB30_name_6A[i][k] = SprAnimRead(data);
            DataClose(data);
            SprAnimSet(spr, j, (s16)D_801064F0_3FEB30_name_6A[i][k], 0);
            func_8008225C_82E5C(spr, j, 1);
            SprPrioSet(spr, j, 0xE);
            SprAttrSet(spr, j, 0x9000);
            func_800822A8_82EA8(spr, j, digits[i][k], 0);
            func_800824F4_830F4(spr, j, 0);
            func_8008221C_82E1C(spr, j, 0.0f);
            if (i == 0) {
                if (val[i] == 0) {
                    SprPosSet(spr, j, D_801063B0_3FE9F0_name_6A[cnt[i]][k], 2);
                } else {
                    SprPosSet(spr, j, D_801063B0_3FE9F0_name_6A[cnt[i]][k] + 4, 2);
                }
            } else if (D_801064B4_3FEAF4_name_6A == 0) {
                if (val[i] == 0) {
                    SprPosSet(spr, j, D_801063B0_3FE9F0_name_6A[cnt[i]][k], 2);
                } else {
                    SprPosSet(spr, j, D_801063B0_3FE9F0_name_6A[cnt[i]][k] + 4, 2);
                }
            } else {
                func_80082450_83050(spr, j, 0xFF, 0, 0);
                SprPosSet(spr, j, D_801063B0_3FE9F0_name_6A[cnt[i]][k], 2);
            }
        }
        data = DataRead(0xC000D);
        D_801064E4_3FEB24_name_6A[i] = SprAnimRead(data);
        DataClose(data);
        SprAnimSet(spr, j, (s16)D_801064E4_3FEB24_name_6A[i], 0);
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
                SprPosSet(spr, j, D_801063B0_3FE9F0_name_6A[cnt[i]][3 - cnt[i]] - 4, 2);
            }
        } else if (D_801064B4_3FEAF4_name_6A == 0 && val[i] != 0) {
            if (val[i] > 0) {
                func_800822A8_82EA8(spr, j, 11, 0);
            } else {
                func_800822A8_82EA8(spr, j, 12, 0);
            }
            SprPosSet(spr, j, D_801063B0_3FE9F0_name_6A[cnt[i]][3 - cnt[i]] - 4, 2);
        } else {
            SprPosSet(spr, j, -1000, 2);
            func_800822A8_82EA8(spr, j, 10, 0);
        }
    }
    spr = SprCreate(7, 5);
    D_80106510_3FEB50_name_6A[2] = spr;
    data = DataRead(0xD0005);
    D_801064D8_3FEB18_name_6A[2] = SprAnimRead(data);
    DataClose(data);
    SprAnimSet(spr, 0, (s16)D_801064D8_3FEB18_name_6A[2], 0);
    func_800824F4_830F4(spr, 0, -1);
    SprAttrSet(spr, 0, 0x8000);
    SprPosSet(spr, 0, D_801063A8_3FE9E8_name_6A[0][0], D_801063A8_3FE9E8_name_6A[0][1]);
    SprAnimSet(spr, 1, (s16)D_801064D8_3FEB18_name_6A[2], 0);
    func_8008225C_82E5C(spr, 1, 1);
    SprPrioSet(spr, 1, 0xF);
    SprAttrSet(spr, 1, 0x9000);
    SprPosSet(spr, 1, 0, 0);
    func_800824F4_830F4(spr, 1, 0);
    data = DataRead(0xD0006);
    D_801064BC_3FEAFC_name_6A = SprAnimRead(data);
    DataClose(data);
    SprAnimSet(spr, 2, (s16)D_801064BC_3FEAFC_name_6A, 0);
    func_8008225C_82E5C(spr, 2, 1);
    SprPrioSet(spr, 2, 0xE);
    SprAttrSet(spr, 2, 0x9000);
    func_800824F4_830F4(spr, 2, 0);
    SprPosSet(spr, 2, 0, 2);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_name/3FAE70", func_80103460_3FBAA0_name_6A);
#endif

void func_80104224_3FC864_name_6A(void) {
    func_8008CCA8_8D8A8((s16)D_801064B0_3FEAF0_name_6A);
}

void func_80104244_3FC884_name_6A(void) {
    Hu3DCamSetPerspective(1, 40.0f, 200.0f, 8000.0f);
    Hu3DCamSetPositionOrientation(1, &D_8010651C_3FEB5C_name_6A, &D_80106528_3FEB68_name_6A, &D_80106534_3FEB74_name_6A);
    Hu3DCamUpdateMtx(1);
    CameraViewportSet(1, &D_80106540_3FEB80_name_6A, &D_8010654C_3FEB8C_name_6A);
}

void func_801042AC_3FC8EC_name_6A(void) {
    while (1) {
        func_80104244_3FC884_name_6A();
        HuPrcVSleep();
    }
}

__asm__(".section .rodata");
const char D_80106428_3FEA68_name_6A[] = "point1";

__asm__(".section .rodata");
const char D_80106430_3FEA70_name_6A[] = "point2";

void func_801042D8_3FC918_name_6A(void) {
    Vec v;

    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    HuVecCopyXYZ(&v, 0.0f, 0.0f, 0.0f);
    OVL6A_LINK(func_80056D80_57980(&D_80106568_3FEBA8_name_6A->pos, &v, &D_80106568_3FEBA8_name_6A->pos, 20));
    HuPrcChildWatch();
    func_80029E80_2AA80(D_80106568_3FEBA8_name_6A->obj->model[0], 2, 1);
    HuVecCopyXYZ(&D_80106560_3FEBA0_name_6A->pos, -6.278950214385986f, 19.16754913330078f, 0.0f);
    HuVecCopyXYZ(&D_80106564_3FEBA4_name_6A->pos, 5.623000144958496f, 19.16754913330078f, 0.0f);
    HuPrcVSleep();
    func_8005AA98_5B698(D_80106560_3FEBA0_name_6A->obj->model[0]);
    func_8005AA98_5B698(D_80106564_3FEBA4_name_6A->obj->model[0]);
    HuPrcVSleep();
    func_8005670C_5730C(&v);
    OVL6A_LINK(func_80056B78_57778(&D_80106560_3FEBA0_name_6A->rot, &v, &D_80106560_3FEBA0_name_6A->rot, 10));
    OVL6A_LINK(func_80056B78_57778(&D_80106564_3FEBA4_name_6A->rot, &v, &D_80106564_3FEBA4_name_6A->rot, 10));
    HuPrcChildWatch();
    if (D_801064B4_3FEAF4_name_6A == 0) {
        MBMotionSet(D_80106560_3FEBA0_name_6A, 6, 0);
        MBMotionSet(D_80106564_3FEBA4_name_6A, 6, 0);
        func_800732B0_73EB0(D_801063D8_3FEA18_name_6A[(s8)D_800FD8A8_FE4A8.character] | 0x54);
    } else {
        MBMotionSet(D_80106560_3FEBA0_name_6A, 3, 0);
        MBMotionSet(D_80106564_3FEBA4_name_6A, 3, 0);
    }
    while (1) {
        if (D_801063A4_3FE9E4_name_6A != 0) {
            MBMotionSet(D_80106560_3FEBA0_name_6A, 5, 0);
            MBMotionSet(D_80106564_3FEBA4_name_6A, 5, 0);
            HuPrcSleep(30);
            break;
        }
        if (D_801063A3_3FE9E3_name_6A != 0) {
            break;
        }
        HuPrcVSleep();
    }
    MBMotionShiftSet(D_80106560_3FEBA0_name_6A, -1, 0, 10, 2);
    MBMotionShiftSet(D_80106564_3FEBA4_name_6A, -1, 0, 10, 2);
    HuVecCopyXYZ(&v, -1.0f, 0.0f, 0.0f);
    OVL6A_LINK(func_80056B78_57778(&D_80106560_3FEBA0_name_6A->rot, &v, &D_80106560_3FEBA0_name_6A->rot, 10));
    OVL6A_LINK(func_80056B78_57778(&D_80106564_3FEBA4_name_6A->rot, &v, &D_80106564_3FEBA4_name_6A->rot, 10));
    HuPrcChildWatch();
    func_8005AA48_5B648(D_80106568_3FEBA8_name_6A, D_80106428_3FEA68_name_6A, D_80106560_3FEBA0_name_6A->obj->model[0]);
    func_8005AA48_5B648(D_80106568_3FEBA8_name_6A, D_80106430_3FEA70_name_6A, D_80106564_3FEBA4_name_6A->obj->model[0]);
    func_80029E80_2AA80(D_80106568_3FEBA8_name_6A->obj->model[0], 1, 2);
    HuVecCopyXYZ(&v, -100.0f, 0.0f, 0.0f);
    OVL6A_LINK(func_80056D80_57980(&D_80106568_3FEBA8_name_6A->pos, &v, &D_80106568_3FEBA8_name_6A->pos, 20));
    HuPrcChildWatch();
    while (1) {
        HuPrcVSleep();
    }
}

void func_801046D8_3FCD18_name_6A(void) {
    D_80106558_3FEB98_name_6A = omAddPrcObj(func_801042AC_3FC8EC_name_6A, 0x4000, 0, 0);
    D_8010651C_3FEB5C_name_6A.x = 0.0f;
    D_8010651C_3FEB5C_name_6A.y = 250.0f;
    D_8010651C_3FEB5C_name_6A.z = 200.0f;
    D_80106528_3FEB68_name_6A.x = 0.0f;
    D_80106528_3FEB68_name_6A.y = 0.0f;
    D_80106528_3FEB68_name_6A.z = 0.0f;
    D_80106534_3FEB74_name_6A.x = 0.0f;
    D_80106534_3FEB74_name_6A.y = 1.0f;
    D_80106534_3FEB74_name_6A.z = 0.0f;
    D_80106540_3FEB80_name_6A.x = 1280.0f;
    D_80106540_3FEB80_name_6A.y = 960.0f;
    D_80106540_3FEB80_name_6A.z = 511.0f;
    D_8010654C_3FEB8C_name_6A.x = 640.0f;
    D_8010654C_3FEB8C_name_6A.y = 480.0f;
    D_8010654C_3FEB8C_name_6A.z = 511.5f;
    func_80104244_3FC884_name_6A();
    D_80106568_3FEBA8_name_6A = func_80043510_44110(0xAA, NULL);
    HuVecCopyXYZ(&D_80106568_3FEBA8_name_6A->rot, -1.0f, 0.0f, 0.0f);
    HuVecCopyXYZ(&D_80106568_3FEBA8_name_6A->pos, 100.0f, 0.0f, 0.0f);
    D_80106568_3FEBA8_name_6A->attr |= 1;
    func_80029EDC_2AADC(D_80106568_3FEBA8_name_6A->obj->model[0], 2);
    D_80106560_3FEBA0_name_6A = func_80043510_44110(D_801063D0_3FEA10_name_6A[(s8)D_800FD8A8_FE4A8.character], D_800CC8B8_CD4B8[(s8)D_800FD8A8_FE4A8.character]);
    HuVecCopyXYZ(&D_80106560_3FEBA0_name_6A->rot, -1.0f, 0.0f, 0.0f);
    D_80106560_3FEBA0_name_6A->attr |= 1;
    func_80029EDC_2AADC(D_80106560_3FEBA0_name_6A->obj->model[0], 2);
    D_80106564_3FEBA4_name_6A = func_80043510_44110(D_801063D0_3FEA10_name_6A[(s8)D_800FD8A8_FE4A8.character2], D_800CC8B8_CD4B8[(s8)D_800FD8A8_FE4A8.character2]);
    HuVecCopyXYZ(&D_80106564_3FEBA4_name_6A->rot, -1.0f, 0.0f, 0.0f);
    D_80106564_3FEBA4_name_6A->attr |= 1;
    func_80029EDC_2AADC(D_80106564_3FEBA4_name_6A->obj->model[0], 2);
    func_8005AA48_5B648(D_80106568_3FEBA8_name_6A, D_80106428_3FEA68_name_6A, D_80106560_3FEBA0_name_6A->obj->model[0]);
    func_8005AA48_5B648(D_80106568_3FEBA8_name_6A, D_80106430_3FEA70_name_6A, D_80106564_3FEBA4_name_6A->obj->model[0]);
    D_8010655C_3FEB9C_name_6A = omAddPrcObj(func_801042D8_3FC918_name_6A, 0x4000, 0, 0);
}

void func_801049A4_3FCFE4_name_6A(void) {
    omDelPrcObj(D_80106558_3FEB98_name_6A);
    omDelPrcObj(D_8010655C_3FEB9C_name_6A);
    MBModelKill(D_80106560_3FEBA0_name_6A);
    MBModelKill(D_80106564_3FEBA4_name_6A);
    MBModelKill(D_80106568_3FEBA8_name_6A);
}

void func_801049F4_3FD034_name_6A(void) {
    switch (D_801064B4_3FEAF4_name_6A) {
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

void func_80104A60_3FD0A0_name_6A(s8 idx) {
    f32 scale;
    s32 i;
    s32 n = idx;

    i = 0;
    do {
        i++;
        SprAttrReset((s16)D_80106510_3FEB50_name_6A[n], i, 0x8000);
    } while (i < 6);
    for (scale = 0.0f; scale < 1.0; scale += 0.3) {
        i = 0;
        do {
            i++;
            SprScaleSet((s16)D_80106510_3FEB50_name_6A[n], i, scale, scale);
        } while (i < 6);
        if (D_801063A0_3FE9E0_name_6A == 0) {
            HuPrcVSleep();
        }
    }
    i = 0;
    do {
        i++;
        SprScaleSet((s16)D_80106510_3FEB50_name_6A[n], i, 1.0f, 1.0f);
    } while (i < 6);
}

void func_80104BA8_3FD1E8_name_6A(void) {
    f32 scale;
    s32 i;

    i = 0;
    do {
        i++;
        SprAttrReset((s16)D_80106510_3FEB50_name_6A[0], i, 0x8000);
        SprAttrReset((s16)D_80106510_3FEB50_name_6A[1], i, 0x8000);
    } while (i < 6);
    for (scale = 0.0f; scale < 1.0; scale += 0.3) {
        i = 0;
        do {
            i++;
            SprScaleSet((s16)D_80106510_3FEB50_name_6A[0], i, scale, scale);
            SprScaleSet((s16)D_80106510_3FEB50_name_6A[1], i, scale, scale);
        } while (i < 6);
        if (D_801063A0_3FE9E0_name_6A == 0) {
            HuPrcVSleep();
        }
    }
    i = 0;
    do {
        i++;
        SprScaleSet((s16)D_80106510_3FEB50_name_6A[0], i, 1.0f, 1.0f);
        SprScaleSet((s16)D_80106510_3FEB50_name_6A[1], i, 1.0f, 1.0f);
    } while (i < 6);
}

void func_80104D28_3FD368_name_6A(void) {
    f32 scale;
    s32 i;

    i = 0;
    do {
        i++;
        SprScaleSet((s16)D_80106510_3FEB50_name_6A[0], i, 1.0f, 1.0f);
        SprScaleSet((s16)D_80106510_3FEB50_name_6A[1], i, 1.0f, 1.0f);
    } while (i < 6);
    scale = 1.0f;
    do {
        i = 0;
        do {
            i++;
            SprScaleSet((s16)D_80106510_3FEB50_name_6A[0], i, scale, scale);
            SprScaleSet((s16)D_80106510_3FEB50_name_6A[1], i, scale, scale);
        } while (i < 6);
        if (D_801063A0_3FE9E0_name_6A == 0) {
            HuPrcVSleep();
        }
        scale -= 0.3f;
    } while (scale > 0.0f);
    i = 0;
    do {
        i++;
        SprAttrSet((s16)D_80106510_3FEB50_name_6A[0], i, 0x8000);
        SprAttrSet((s16)D_80106510_3FEB50_name_6A[1], i, 0x8000);
    } while (i < 6);
}

#ifdef NON_MATCHING
void func_80104EA8_3FD4E8_name_6A(void) {
    s16 val[4];
    s16 cnt[4];
    s16 digits[4][4];
    s32 i;
    s32 k;
    s32 j;

    val[0] = D_800FD8A8_FE4A8.lives - D_801064B8_3FEAF8_name_6A;
    if (D_800FD8A8_FE4A8.streak > 0) {
        val[1] = (gPlayers[0].coins_mg + gPlayers[0].coins_mg_bonus) * D_800FD8A8_FE4A8.streak - D_801063A6_3FE9E6_name_6A;
    } else {
        val[1] = gPlayers[0].coins_mg + gPlayers[0].coins_mg_bonus - D_801063A6_3FE9E6_name_6A;
    }
    for (i = 0; i < 2; i++) {
        digits[i][0] = OVL6A_ABS(val[i]) / 1000;
        digits[i][1] = (OVL6A_ABS(val[i]) - digits[i][0] * 1000) / 100;
        digits[i][2] = (OVL6A_ABS(val[i]) - digits[i][0] * 1000 - digits[i][1] * 100) / 10;
        digits[i][3] = OVL6A_ABS(val[i]) - digits[i][0] * 1000 - digits[i][1] * 100 - digits[i][2] * 10;
        cnt[i] = 0;
        if (OVL6A_ABS(val[i]) >= 10) {
            cnt[i] = 1;
        }
        if (OVL6A_ABS(val[i]) >= 100) {
            cnt[i] = 2;
        }
        if (OVL6A_ABS(val[i]) >= 1000) {
            cnt[i] = 3;
        }
    }
    for (i = 0; i < 2; i++) {
        j = 2;
        for (k = 0; k < 4; k++, j++) {
            func_800822A8_82EA8((s16)D_80106510_3FEB50_name_6A[i], j, digits[i][k], 0);
            if (i == 0) {
                if (val[i] == 0) {
                    SprPosSet((s16)D_80106510_3FEB50_name_6A[i], j, D_801063F0_3FEA30_name_6A[cnt[i]][k], 2);
                } else {
                    SprPosSet((s16)D_80106510_3FEB50_name_6A[i], j, D_801063F0_3FEA30_name_6A[cnt[i]][k] + 4, 2);
                }
            } else if (D_801064B4_3FEAF4_name_6A == 0 && val[i] != 0) {
                SprPosSet((s16)D_80106510_3FEB50_name_6A[i], j, D_801063F0_3FEA30_name_6A[cnt[i]][k] + 4, 2);
            } else {
                SprPosSet((s16)D_80106510_3FEB50_name_6A[i], j, D_801063F0_3FEA30_name_6A[cnt[i]][k], 2);
            }
        }
        if (i == 0) {
            if (val[i] == 0) {
                SprPosSet((s16)D_80106510_3FEB50_name_6A[i], j, -1000, -2);
                func_800822A8_82EA8((s16)D_80106510_3FEB50_name_6A[i], j, 10, 0);
            } else {
                if (val[i] > 0) {
                    func_800822A8_82EA8((s16)D_80106510_3FEB50_name_6A[i], j, 11, 0);
                } else {
                    func_800822A8_82EA8((s16)D_80106510_3FEB50_name_6A[i], j, 12, 0);
                }
                SprPosSet((s16)D_80106510_3FEB50_name_6A[i], j, D_801063F0_3FEA30_name_6A[cnt[i]][3 - cnt[i]] - 4, 2);
            }
        } else if (D_801064B4_3FEAF4_name_6A == 0 && val[i] != 0) {
            if (val[i] > 0) {
                func_800822A8_82EA8((s16)D_80106510_3FEB50_name_6A[i], j, 11, 0);
            } else {
                func_800822A8_82EA8((s16)D_80106510_3FEB50_name_6A[i], j, 12, 0);
            }
            SprPosSet((s16)D_80106510_3FEB50_name_6A[i], j, D_801063F0_3FEA30_name_6A[cnt[i]][3 - cnt[i]] - 4, 2);
        } else {
            SprPosSet((s16)D_80106510_3FEB50_name_6A[i], j, -1000, -2);
            func_800822A8_82EA8((s16)D_80106510_3FEB50_name_6A[i], j, 10, 0);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_name/3FAE70", func_80104EA8_3FD4E8_name_6A);
#endif

void func_80105530_3FDB70_name_6A(void) {
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
    while ((s16)coins > D_801063A6_3FE9E6_name_6A) {
        D_801063A6_3FE9E6_name_6A += step;
        if ((s16)coins <= D_801063A6_3FE9E6_name_6A) {
            D_800FD8A8_FE4A8.coins += step - ((u8)D_801063A6_3FE9E6_name_6A - coins);
            D_801063A6_3FE9E6_name_6A = coins;
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
                func_80104A60_3FD0A0_name_6A(2);
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
        func_80104EA8_3FD4E8_name_6A();
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
            func_80104A60_3FD0A0_name_6A(2);
        }
    }
    func_80104EA8_3FD4E8_name_6A();
}

void func_80105808_3FDE48_name_6A(void) {
    s16 size[2];
    s32 win;
    s8 choice;

    SprAttrSet((s16)D_801064C0_3FEB00_name_6A, 1, 0x8000);
    HuPrcSleep(30);
    PlayMusic(0x14);
    SprAttrReset((s16)D_801064CC_3FEB0C_name_6A, 1, 0x8000);
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
        D_801063A4_3FE9E4_name_6A = 1;
        HuPrcSleep(30);
    }
    D_801063A2_3FE9E2_name_6A = choice;
    D_801063A1_3FE9E1_name_6A = 1;
}

void func_80105988_3FDFC8_name_6A(void) {
    s16 size[2];
    char buf[8];
    GAMEMES mesX;
    GAMEMES mesN;
    s16 win;

    if (D_800FD8A8_FE4A8.streak >= 2) {
        sprintf(buf, D_80106424_3FEA64_name_6A, D_800FD8A8_FE4A8.streak);
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
        func_80104EA8_3FD4E8_name_6A();
        PlaySound(0x33D);
        HuPrcSleep(0x19);
    }
}

#ifdef NON_MATCHING
void func_80105B38_3FE178_name_6A(void) {
    s16 i;
    s32 show;
    s32 failed;

    switch (D_801064B4_3FEAF4_name_6A) {
    case 0:
        HuPrcSleep(0x24);
        func_80079428_7A028(0x44);
        break;
    case 1:
        HuPrcSleep(0x24);
        func_80079428_7A028(0x45);
        break;
    }
    SprAttrReset((s16)D_801064C0_3FEB00_name_6A, 1, 0x8000);
    omAddPrcObj(func_801049F4_3FD034_name_6A, 0x300, 0x2500, 0);
    HuPrcSleep(0x3C);
    if (D_801064B4_3FEAF4_name_6A == 0) {
        HuPrcSleep(30);
    } else {
        HuPrcSleep(20);
    }
    failed = 0;
    switch (D_801064B4_3FEAF4_name_6A) {
    case 0:
        func_80104A60_3FD0A0_name_6A(1);
        for (i = 0; i < 30; i++) {
            if (D_801063A0_3FE9E0_name_6A == 1) {
                break;
            }
            HuPrcVSleep();
        }
        func_80105988_3FDFC8_name_6A();
        func_80105530_3FDB70_name_6A();
        goto done;
    case 1:
        if (D_800FD8A8_FE4A8.lives <= 0) {
            failed = 1;
        }
        D_800FD8A8_FE4A8.lives--;
        func_80104EA8_3FD4E8_name_6A();
        if (D_800FD8A8_FE4A8.lives < 0) {
            D_800FD8A8_FE4A8.lives = 0;
        }
        func_80104BA8_3FD1E8_name_6A();
        for (i = 0; i < 30; i++) {
            if (D_801063A0_3FE9E0_name_6A == 1) {
                break;
            }
            HuPrcVSleep();
        }
    done:
        func_80104D28_3FD368_name_6A();
        show = failed;
        break;
    default:
        show = failed;
        break;
    }
    if (show != 0) {
        func_80105808_3FDE48_name_6A();
    } else {
        D_801063A3_3FE9E3_name_6A = 1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6A_name/3FAE70", func_80105B38_3FE178_name_6A);
#endif

s32 func_80105D14_3FE354_name_6A(s16 minigame) {
    s32 total;

    total = gPlayers[0].coins_mg_bonus + gPlayers[0].coins_mg;
    switch (minigame) {
    case 0x24:
        if (total < D_80106410_3FEA50_name_6A[0][D_800FD8A8_FE4A8.difficulty]) {
            return 0;
        }
        break;
    case 0x47:
        if (total < D_80106410_3FEA50_name_6A[1][D_800FD8A8_FE4A8.difficulty]) {
            return 0;
        }
        break;
    case 0x48:
        if (total < D_80106410_3FEA50_name_6A[2][D_800FD8A8_FE4A8.difficulty]) {
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

void func_80105DE0_3FE420_name_6A(void) {
    s32 i;
    s32 j;

    SprKill((s16)D_801064C0_3FEB00_name_6A);
    SprKill((s16)D_801064CC_3FEB0C_name_6A);
    for (i = 0; i < 3; i++) {
        SprKill((s16)D_80106510_3FEB50_name_6A[i]);
        SprAnimKill((s16)D_801064D8_3FEB18_name_6A[i]);
    }
    SprAnimKill((s16)D_801064BC_3FEAFC_name_6A);
    for (i = 0; i < 2; i++) {
        SprAnimKill((s16)D_801064E4_3FEB24_name_6A[i]);
        for (j = 0; j < 4; j++) {
            SprAnimKill((s16)D_801064F0_3FEB30_name_6A[i][j]);
        }
    }
    SprAnimKill((s16)D_801064C4_3FEB04_name_6A);
    SprAnimKill((s16)D_801064D0_3FEB10_name_6A);
}

void func_80105EF8_3FE538_name_6A(void) {
    func_80028334_28F34(D_800FD2A6_FDEA6, 2);
    func_80029EDC_2AADC(D_800FD2A6_FDEA6, 1);
    if (func_80105D14_3FE354_name_6A(GwSystem.chosenMinigameIndex) != 0) {
        D_801064B4_3FEAF4_name_6A = 0;
        _SetFlag(0x16);
        D_800FD8A8_FE4A8.streak++;
        PlayMusic(0x42);
    } else {
        D_801064B4_3FEAF4_name_6A = 1;
        _ClearFlag(0x16);
        D_800FD8A8_FE4A8.streak = 0;
        PlayMusic(0x43);
    }
    D_801064B6_3FEAF6_name_6A = D_800FD8A8_FE4A8.coins;
    D_801064B8_3FEAF8_name_6A = D_800FD8A8_FE4A8.lives;
    func_80103460_3FBAA0_name_6A();
    func_801046D8_3FCD18_name_6A();
    func_80029E80_2AA80(D_800FA618_FB218->obj->model[0], 2, 1);
    func_80029E80_2AA80(((MBModel*)gPlayers[0].unk_24)->obj->model[0], 2, 1);
    func_80029E80_2AA80(((MBModel*)gPlayers[1].unk_24)->obj->model[0], 2, 1);
    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    func_80105B38_3FE178_name_6A();
    HuPrcSleep(30);
    func_800794A8_7A0A8(0x5A);
    InitFadeOut(0, 0x10);
    HuPrcSleep(0x11);
    func_80104224_3FC864_name_6A();
    func_801049A4_3FCFE4_name_6A();
    func_80105DE0_3FE420_name_6A();
    switch (D_801063A2_3FE9E2_name_6A) {
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

void func_801060F8_3FE738_name_6A(void) {
    func_80103284_3FB8C4_name_6A();
    func_80074DB8_759B8(1);
    omAddPrcObj(func_80105EF8_3FE538_name_6A, 0x1005, 0x1000, 0);
}

/* Scene 4: back on the space after the last stop passed. */
void func_80106134_3FE774_name_6A(void) {
    if (func_80075390_75F90(OVL6A_FLAG_BASE + 0x23) != 0) {
        SetPlayerOntoChain(0, 0, 24);
    } else if (func_80075390_75F90(OVL6A_FLAG_BASE + 0x22) != 0) {
        SetPlayerOntoChain(0, 0, 22);
    } else if (func_80075390_75F90(OVL6A_FLAG_BASE + 0x21) != 0) {
        SetPlayerOntoChain(0, 0, 17);
    } else if (func_80075390_75F90(OVL6A_FLAG_BASE + 0x20) != 0) {
        SetPlayerOntoChain(0, 0, 14);
    } else if (func_80075390_75F90(OVL6A_FLAG_BASE + 0x1F) != 0) {
        SetPlayerOntoChain(0, 0, 10);
    } else if (func_80075390_75F90(OVL6A_FLAG_BASE + 0x1E) != 0) {
        SetPlayerOntoChain(0, 0, 6);
    } else {
        SetPlayerOntoChain(0, 0, 0);
    }
    omOvlReturnEx(1);
}

/* .data (0x3FE850-0x3FEA60,80106210-80106420) */
board_overlay_entrypoint D_80106210_3FE850_name_6A[6] = { { 0, func_801031D0_3FB810_name_6A }, { 1, func_8010320C_3FB84C_name_6A }, { 2, func_80103310_3FB950_name_6A }, { 3, func_801060F8_3FE738_name_6A }, { 4, func_80106134_3FE774_name_6A }, { -1, NULL } };
CoasterSpaceFlag D_80106240_3FE880_name_6A[7] = { { 0, 39 }, { 1, 40 }, { 2, 41 }, { 3, 42 }, { 4, 43 }, { 5, 44 }, { -1, -1 } };
s32 D_8010625C_3FE89C_name_6A[6] = { 0x000A010F, 0x000A0110, 0x000A0111, 0x000A0112, 0x000A0113, 0x000A0114 };
s32 D_80106274_3FE8B4_name_6A[6] = { 0x000005DA, 0x000005DB, 0x000005DC, 0x000005DD, 0x00000000, 0x000005E1 };
s32 D_8010628C_3FE8CC_name_6A[3] = { 0x000005DE, 0x000005DF, 0x000005E0 };
s32 D_80106298_3FE8D8_name_6A[3] = { 0x000005D2, 0x000005D4, 0x000005D6 };
s16 D_801062A4_3FE8E4_name_6A[4][2] = { { 0x0064, 0x003C }, { 0x0064, 0x004E }, { 0x0064, 0x0060 }, { 0x0064, 0x0072 } };
s16 D_801062B4_3FE8F4_name_6A = 0x00C8;
s16 D_801062B6_3FE8F6_name_6A = 0x003C;
s16 D_801062B8_3FE8F8_name_6A = 0x00C8;
s16 D_801062BA_3FE8FA_name_6A = 0x004E;
s16 D_801062BC_3FE8FC_name_6A[2] = { 0x0018, 0x003C };
BoardEventListEntry D_801062C0_3FE900_name_6A[2] = { { 1, 1, func_8010333C_3FB97C_name_6A }, { 0, 0, NULL } };
BoardEventListEntry D_801062D0_3FE910_name_6A[2] = { { 1, 1, func_80103360_3FB9A0_name_6A }, { 0, 0, NULL } };
BoardEventListEntry D_801062E0_3FE920_name_6A[2] = { { 1, 1, func_80103384_3FB9C4_name_6A }, { 0, 0, NULL } };
BoardEventListEntry D_801062F0_3FE930_name_6A[2] = { { 1, 1, func_801033A8_3FB9E8_name_6A }, { 0, 0, NULL } };
BoardEventListEntry D_80106300_3FE940_name_6A[2] = { { 1, 1, func_801033CC_3FBA0C_name_6A }, { 0, 0, NULL } };
BoardEventListEntry D_80106310_3FE950_name_6A[2] = { { 1, 1, func_801033F0_3FBA30_name_6A }, { 0, 0, NULL } };
BoardEventListEntry D_80106320_3FE960_name_6A[2] = { { 1, 1, func_80103414_3FBA54_name_6A }, { 0, 0, NULL } };
BoardEventListEntry D_80106330_3FE970_name_6A[2] = { { 1, 1, func_80103438_3FBA78_name_6A }, { 0, 0, NULL } };
BoardEventTableEntry D_80106340_3FE980_name_6A[9] = { { 0, D_801062C0_3FE900_name_6A }, { 1, D_801062D0_3FE910_name_6A }, { 2, D_801062E0_3FE920_name_6A }, { 3, D_801062F0_3FE930_name_6A }, { 4, D_80106300_3FE940_name_6A }, { 5, D_80106310_3FE950_name_6A }, { 6, D_80106320_3FE960_name_6A }, { 12, D_80106330_3FE970_name_6A }, { -1, NULL } };
s32 D_80106388_3FE9C8_name_6A[2][2] = { { 0x000D0000, 0x000D0001 }, { 0x000B00E1, 0x000B00E2 } };
s32 D_80106398_3FE9D8_name_6A[2] = { 0x000D0002, 0x000D0003 };
s8 D_801063A0_3FE9E0_name_6A = 0;
s8 D_801063A1_3FE9E1_name_6A = 0;
s8 D_801063A2_3FE9E2_name_6A = -1;
s8 D_801063A3_3FE9E3_name_6A = 0;
s8 D_801063A4_3FE9E4_name_6A = 0;
s8 D_801063A5_3FE9E5_name_6A = 0; /* padding */
s16 D_801063A6_3FE9E6_name_6A = 0;
s16 D_801063A8_3FE9E8_name_6A[2][2] = { { 0x0050, 0x0034 }, { 0x0108, 0x0034 } };
s16 D_801063B0_3FE9F0_name_6A[4][4] = { { -1000, -1000, -1000, 0 }, { -1000, -1000, -4, 4 }, { -1000, -8, 0, 8 }, { -14, -6, 2, 10 } };
u8 D_801063D0_3FEA10_name_6A[8] = { 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x00, 0x00 };
s32 D_801063D8_3FEA18_name_6A[6] = { 0x00020000, 0x00030000, 0x00070000, 0x00040000, 0x00050000, 0x00060000 };
s16 D_801063F0_3FEA30_name_6A[4][4] = { { -1000, -1000, -1000, 0 }, { -1000, -1000, -4, 4 }, { -1000, -8, 0, 8 }, { -14, -6, 2, 10 } };
u8 D_80106410_3FEA50_name_6A[3][3] = { { 0x00, 0x0A, 0x0F }, { 0x00, 0x0A, 0x0F }, { 0x00, 0x00, 0x0F } };
s8 D_80106419_3FEA59_name_6A = 0; /* padding to .rodata */
s8 D_8010641A_3FEA5A_name_6A = 0;
s8 D_8010641B_3FEA5B_name_6A = 0;
s32 D_8010641C_3FEA5C_name_6A[1] = { 0 };
