#include "common.h"
#include "ovl_68.h"

#define OVL68_ABS(x) ((x) < 0 ? -(s32)(x) : (x))
/* Waits on a mover: makes it a child of the current process. */
#define OVL68_LINK(call) do { Process* _p = (call); HuPrcChildLink(HuPrcCurrentGet(), _p); } while (0)

void func_80102830_3F3410_name_68(void) {
    CoasterSpaceFlag* entry;

    entry = D_80106330_3F6F10_name_68;
    while (entry->space >= 0) {
        if (func_80075390_75F90(entry->flag) != 0) {
            BoardSpaceTypeSet(entry->space, 1);
        }
        entry++;
    }
}

s32 func_8010288C_3F346C_name_68(s32 flag) {
    return D_80106550_3F7130_name_68.flags[flag / 8] & (1 << (flag % 8));
}

__asm__(".section .rodata");
const char D_80106510_3F70F0_name_68[] = "%2d";

void func_801028D0_3F34B0_name_68(void) {
    s16 size[2];
    void* data;
    s32 i;
    s32 win;

    D_80106584_3F7164_name_68 = func_8005E688_5F288(1, 0);
    data = DataRead(D_8010634C_3F6F2C_name_68[(s8)D_80106550_3F7130_name_68.character]);
    i = 0;
    D_80106584_3F7164_name_68->unk0C[0] = SprAnimRead(data);
    SprAnimSet(D_80106584_3F7164_name_68->unk0A, 0, D_80106584_3F7164_name_68->unk0C[0], 0);
    SprPrioSet(D_80106584_3F7164_name_68->unk0A, 0, 0x10);
    SprAttrSet(D_80106584_3F7164_name_68->unk0A, 0, 0x1000);
    SprPosSet(D_80106584_3F7164_name_68->unk0A, 0, 0x3E, 0x5F);
    DataClose(data);
    D_80106568_3F7148_name_68[6] = func_80057480_58080(D_801063AC_3F6F8C_name_68[0], D_801063AC_3F6F8C_name_68[1], 0x18, 5);
    for (; i < 4; i++) {
        func_8008DACC_8E6CC(1, size, D_80106364_3F6F44_name_68[i]);
        D_80106568_3F7148_name_68[i] = (s16)func_800888A8_894A8(D_80106394_3F6F74_name_68[i][0], D_80106394_3F6F74_name_68[i][1], size[0], size[1], 0, 0);
        func_80089B2C_8A72C((s16)D_80106568_3F7148_name_68[i], 0);
        func_80089A48_8A648((s16)D_80106568_3F7148_name_68[i], 0);
        func_800890CC_89CCC((s16)D_80106568_3F7148_name_68[i], (void*)D_80106364_3F6F44_name_68[i], -1, -1);
    }
    func_8008DACC_8E6CC(1, size, D_8010637C_3F6F5C_name_68[D_80106550_3F7130_name_68.difficulty]);
    i = 4;
    D_80106568_3F7148_name_68[i] = (s16)func_800888A8_894A8(D_801063A4_3F6F84_name_68, D_801063A6_3F6F86_name_68, size[0], size[1], 0, 0);
    func_80089B2C_8A72C((s16)D_80106568_3F7148_name_68[i], 0);
    func_80089A48_8A648((s16)D_80106568_3F7148_name_68[i], 0);
    func_800890CC_89CCC((s16)D_80106568_3F7148_name_68[i], (void*)D_8010637C_3F6F5C_name_68[D_80106550_3F7130_name_68.difficulty], -1, -1);
    sprintf(D_80106588_3F7168_name_68, D_80106510_3F70F0_name_68, D_80106550_3F7130_name_68.chapter);
    func_8008D974_8E574(D_80106588_3F7168_name_68, 0);
    sprintf(D_80106590_3F7170_name_68, D_80106510_3F70F0_name_68, D_80106550_3F7130_name_68.lives);
    func_8008D974_8E574(D_80106590_3F7170_name_68, 1);
    sprintf(D_80106598_3F7178_name_68, D_80106510_3F70F0_name_68, D_80106550_3F7130_name_68.coins);
    func_8008D974_8E574(D_80106598_3F7178_name_68, 2);
    i = 5;
    func_8008DACC_8E6CC(1, size, D_80106364_3F6F44_name_68[i]);
    win = func_800888A8_894A8(D_801063A8_3F6F88_name_68, D_801063AA_3F6F8A_name_68, size[0], size[1] * 2, 0, 0);
    D_80106568_3F7148_name_68[i] = win;
    D_800F920C_F9E0C[win].unk28 = 0x12;
    func_80089B2C_8A72C((s16)D_80106568_3F7148_name_68[i], 0);
    func_80089A48_8A648((s16)D_80106568_3F7148_name_68[i], 0);
    func_80089308_89F08((s16)D_80106568_3F7148_name_68[i], D_80106588_3F7168_name_68, 0);
    func_80089308_89F08((s16)D_80106568_3F7148_name_68[i], D_80106590_3F7170_name_68, 1);
    func_80089308_89F08((s16)D_80106568_3F7148_name_68[i], D_80106598_3F7178_name_68, 2);
    func_800890CC_89CCC((s16)D_80106568_3F7148_name_68[i], (void*)D_80106364_3F6F44_name_68[i], -1, -1);
}

void func_80102C88_3F3868_name_68(void) {
    s32 i;

    for (i = 0; i < 7; i++) {
        func_8008CCA8_8D8A8((s16)D_80106568_3F7148_name_68[i]);
    }
    HuMemDirectFree(D_80106584_3F7164_name_68);
}

__asm__(".section .rodata");
const char D_80106514_3F70F4_name_68[] = "%d";

void func_80102CE4_3F38C4_name_68(void) {
    char buf[8];
    s32 choice;

again:
    {
        sprintf(buf, D_80106514_3F70F4_name_68, D_800FD8A8_FE4A8.stage + 1);
        MBDlgWinInsertCreateY(0x29, 0x5CD, buf, NULL, NULL, NULL, NULL, 0xAA);
        choice = func_8008BB48_8C748(mbDlgWinId, 0, 1);
        MBDlgWinClose();
        func_80056168_56D68();
        HuPrcVSleep();
        if (choice == 0) {
            func_8007E0C8_7ECC8(&D_80106550_3F7130_name_68);
            if (func_8010288C_3F346C_name_68(0) != 0) {
                func_801028D0_3F34B0_name_68();
                sprintf(buf, D_80106514_3F70F4_name_68, D_80106550_3F7130_name_68.stage + 1);
                MBDlgWinInsertCreateY(0x29, 0x5CF, buf, NULL, NULL, NULL, NULL, 0xAA);
                choice = func_8008BB48_8C748(mbDlgWinId, 0, 0);
                MBDlgWinClose();
                func_80056168_56D68();
                HuPrcVSleep();
                func_80102C88_3F3868_name_68();
                if (choice != 0) {
                    goto again;
                }
            }
            func_800753D4_75FD4(0);
            _ClearFlag(0);
            func_8007E018_7EC18();
            func_8007E0C8_7ECC8(&D_80106550_3F7130_name_68);
            func_801028D0_3F34B0_name_68();
            MBDlgWinInsertCreateY(0x29, 0x5D0, NULL, NULL, NULL, NULL, NULL, 0xAA);
            choice = func_8008BB48_8C748(mbDlgWinId, 0, 1);
            MBDlgWinClose();
            func_80056168_56D68();
            func_80102C88_3F3868_name_68();
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
    MBDlgWinExecY(0x29, D_80106388_3F6F68_name_68[D_800FD8A8_FE4A8.difficulty], 0xAA);
}

void func_801030B8_3F3C98_name_68(s32 sign) {
    s16 size[2];
    s32 win;
    s32 name;

    if (func_80075390_75F90(sign + OVL68_FLAG_BASE) == 0) {
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

void func_801031D0_3F3DB0_name_68(void) {
    D_800FD8A8_FE4A8.stage = OVL68_STAGE;
    omInitObjMan(10, 0);
    omOvlGotoEx(OVL68_NEXT_SCENE, OVL68_NEXT_ENTRY, 0x192);
}

/* Scene 1: back on the start space, stop flags cleared (27-32), flag 26 set. */
void func_8010320C_3F3DEC_name_68(void) {
    omInitObjMan(10, 0);
    SetPlayerOntoChain(0, 0, 0);
    func_80075424_76024(OVL68_FLAG_BASE + 18);
    func_80075424_76024(OVL68_FLAG_BASE + 19);
    func_80075424_76024(OVL68_FLAG_BASE + 20);
    func_80075424_76024(OVL68_FLAG_BASE + 21);
    func_80075424_76024(OVL68_FLAG_BASE + 22);
    func_80075424_76024(OVL68_FLAG_BASE + 23);
    func_800753D4_75FD4(OVL68_FLAG_BASE + 17);
    func_80073410_74010(-1);
    omOvlReturnEx(1);
}

/* The board's common setup. */
void func_80103284_3F3E64_name_68(void) {
    omInitObjMan(0x50, 0x28);
    func_80020070_20C70(2);
    func_80026D28_27928(1);
    func_80026DAC_279AC(0, 0x78, 0x78, 0x78);
    func_80026DAC_279AC(1, 0x40, 0x40, 0x60);
    func_80026E00_27A00(1, -100.0f, 100.0f, 300.0f);
    func_80074154_74D54(OVL68_BOARD_MODEL, OVL68_BOARD_FILE);
    EventTableHydrate(D_80106430_3F7010_name_68);
    func_80102830_3F3410_name_68();
    func_801033D4_3F3FB4_name_68();
}

void func_80103318_3F3EF8_name_68(void) {
    func_80103284_3F3E64_name_68();
    func_80074DB8_759B8(0);
    PlayMusic(OVL68_MUSIC);
}

/* Model i of the stage's props (id 0xAD), created once and shown. */
void func_80103344_3F3F24_name_68(s16 i) {
    MBModel* m;

    if (D_801065A0_3F7180_name_68[i] == NULL) {
        m = func_80043510_44110(0xAD, NULL);
        func_800298A4_2A4A4(m->obj->model[0], 0x80000, 0x80000);
        func_80029A8C_2A68C(m->obj->model[0]);
        func_80043DAC_449AC(m);
        D_801065A0_3F7180_name_68[i] = m;
        m->attr |= 2;
    }
}

void func_801033D4_3F3FB4_name_68(void) {
    s32 i;

    for (i = 0; i < 1; i++) {
        D_801065A0_3F7180_name_68[i] = NULL;
        func_80103344_3F3F24_name_68(i);
    }
}

void func_80103428_3F4008_name_68(void) {
    func_80073410_74010(18);
    func_801030B8_3F3C98_name_68(18);
}

void func_8010344C_3F402C_name_68(void) {
    func_80073410_74010(19);
    func_801030B8_3F3C98_name_68(19);
}

void func_80103470_3F4050_name_68(void) {
    func_80073410_74010(20);
    func_801030B8_3F3C98_name_68(20);
}

void func_80103494_3F4074_name_68(void) {
    func_80073410_74010(21);
    func_801030B8_3F3C98_name_68(21);
}

void func_801034B8_3F4098_name_68(void) {
    func_80073410_74010(22);
    func_801030B8_3F3C98_name_68(22);
}

void func_801034DC_3F40BC_name_68(void) {
    func_80073410_74010(23);
    func_801030B8_3F3C98_name_68(23);
}

void func_80103500_3F40E0_name_68(void) {
    func_80073410_74010(-2);
    func_80102CE4_3F38C4_name_68();
}

void func_80103524_3F4104_name_68(void) {
    func_80074FAC_75BAC(5, 0, 1, 1);
}

#ifdef NON_MATCHING
void func_8010354C_3F412C_name_68(void) {
    s16 cnt[4];
    s16 digits[2][4];
    s16 val[2];
    s32 spr;
    s16 i;
    s16 j;
    s16 k;
    s32 file;
    void* data;

    D_801065A4_3F7184_name_68 = (s16)func_800888A8_894A8(0, 0, 0x140, 0xF0, 0, 4);
    func_80089B2C_8A72C((s16)D_801065A4_3F7184_name_68, 0xC8);
    func_8008D530_8E130((s16)D_801065A4_3F7184_name_68, 0, 0, 0);
    D_801065B4_3F7194_name_68 = SprCreate(3, 5);
    SprPosSet((s16)D_801065B4_3F7194_name_68, 0, 0, 0);
    data = DataRead(D_80106478_3F7058_name_68[D_801065A8_3F7188_name_68][0]);
    i = 0;
    D_801065B8_3F7198_name_68 = SprAnimRead(data);
    DataClose(data);
    SprAnimSet((s16)D_801065B4_3F7194_name_68, 1, (s16)D_801065B8_3F7198_name_68, 0);
    func_8008225C_82E5C((s16)D_801065B4_3F7194_name_68, 1, 1);
    SprPrioSet((s16)D_801065B4_3F7194_name_68, 1, 0x10);
    SprAttrSet((s16)D_801065B4_3F7194_name_68, 1, 0x9000);
    SprPosSet((s16)D_801065B4_3F7194_name_68, 1, 0xA0, 0xAA);
    func_8008221C_82E1C((s16)D_801065B4_3F7194_name_68, 1, 0.0f);
    D_801065C0_3F71A0_name_68 = SprCreate(3, 5);
    SprPosSet((s16)D_801065C0_3F71A0_name_68, 0, 0, 0);
    data = DataRead(D_80106488_3F7068_name_68[0]);
    D_801065C4_3F71A4_name_68 = SprAnimRead(data);
    DataClose(data);
    SprAnimSet((s16)D_801065C0_3F71A0_name_68, 1, (s16)D_801065C4_3F71A4_name_68, 0);
    func_8008225C_82E5C((s16)D_801065C0_3F71A0_name_68, 1, 1);
    SprPrioSet((s16)D_801065C0_3F71A0_name_68, 1, 0x10);
    SprAttrSet((s16)D_801065C0_3F71A0_name_68, 1, 0x9000);
    SprPosSet((s16)D_801065C0_3F71A0_name_68, 1, 0xA0, 0xA0);
    func_8008221C_82E1C((s16)D_801065B4_3F7194_name_68, 1, 0.0f);
    val[0] = D_800FD8A8_FE4A8.lives - D_801065AC_3F718C_name_68;
    val[1] = gPlayers[0].coins_mg_bonus + gPlayers[0].coins_mg;
    for (; i < 2; i++) {
        digits[i][0] = OVL68_ABS(val[i]) / 1000;
        digits[i][1] = (OVL68_ABS(val[i]) - digits[i][0] * 1000) / 100;
        digits[i][2] = (OVL68_ABS(val[i]) - digits[i][0] * 1000 - digits[i][1] * 100) / 10;
        digits[i][3] = OVL68_ABS(val[i]) - digits[i][0] * 1000 - digits[i][1] * 100 - digits[i][2] * 10;
        cnt[i] = 0;
        if (OVL68_ABS(val[i]) >= 10) {
            cnt[i] = 1;
        }
        if (OVL68_ABS(val[i]) >= 100) {
            cnt[i] = 2;
        }
        if (OVL68_ABS(val[i]) >= 1000) {
            cnt[i] = 3;
        }
    }
    for (i = 0; i < 2; i++) {
        j = 0;
        spr = SprCreate(7, 5);
        D_80106600_3F71E0_name_68[i] = spr;
        if (i == 0 || val[i] < 0) {
            file = 0xD0004;
        } else {
            file = 0xD0005;
        }
        data = DataRead(file);
        D_801065CC_3F71AC_name_68[i] = SprAnimRead(data);
        DataClose(data);
        SprAnimSet(spr, j, (s16)D_801065CC_3F71AC_name_68[i], 0);
        func_800824F4_830F4(spr, j, -1);
        SprAttrSet(spr, j, 0x8000);
        SprPosSet(spr, j, D_80106498_3F7078_name_68[i][0], D_80106498_3F7078_name_68[i][1]);
        j++;
        SprAnimSet(spr, j, (s16)D_801065CC_3F71AC_name_68[i], 0);
        func_8008225C_82E5C(spr, j, 1);
        SprPrioSet(spr, j, 0xF);
        SprAttrSet(spr, j, 0x9000);
        SprPosSet(spr, j, 0, 0);
        func_800824F4_830F4(spr, j, 0);
        j++;
        for (k = 0; k < 4; k++, j++) {
            data = DataRead(0xC000D);
            D_801065E0_3F71C0_name_68[i][k] = SprAnimRead(data);
            DataClose(data);
            SprAnimSet(spr, j, (s16)D_801065E0_3F71C0_name_68[i][k], 0);
            func_8008225C_82E5C(spr, j, 1);
            SprPrioSet(spr, j, 0xE);
            SprAttrSet(spr, j, 0x9000);
            func_800822A8_82EA8(spr, j, digits[i][k], 0);
            func_800824F4_830F4(spr, j, 0);
            func_8008221C_82E1C(spr, j, 0.0f);
            if (i == 0) {
                if (val[i] == 0) {
                    SprPosSet(spr, j, D_801064A0_3F7080_name_68[cnt[i]][k], 2);
                } else {
                    SprPosSet(spr, j, D_801064A0_3F7080_name_68[cnt[i]][k] + 4, 2);
                }
            } else if (D_801065A8_3F7188_name_68 == 0) {
                if (val[i] == 0) {
                    SprPosSet(spr, j, D_801064A0_3F7080_name_68[cnt[i]][k], 2);
                } else {
                    SprPosSet(spr, j, D_801064A0_3F7080_name_68[cnt[i]][k] + 4, 2);
                }
            } else {
                func_80082450_83050(spr, j, 0xFF, 0, 0);
                SprPosSet(spr, j, D_801064A0_3F7080_name_68[cnt[i]][k], 2);
            }
        }
        data = DataRead(0xC000D);
        D_801065D8_3F71B8_name_68[i] = SprAnimRead(data);
        DataClose(data);
        SprAnimSet(spr, j, (s16)D_801065D8_3F71B8_name_68[i], 0);
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
                SprPosSet(spr, j, D_801064A0_3F7080_name_68[cnt[i]][3 - cnt[i]] - 4, 2);
            }
        } else if (D_801065A8_3F7188_name_68 == 0 && val[i] != 0) {
            if (val[i] > 0) {
                func_800822A8_82EA8(spr, j, 11, 0);
            } else {
                func_800822A8_82EA8(spr, j, 12, 0);
            }
            SprPosSet(spr, j, D_801064A0_3F7080_name_68[cnt[i]][3 - cnt[i]] - 4, 2);
        } else {
            SprPosSet(spr, j, -1000, 2);
            func_800822A8_82EA8(spr, j, 10, 0);
        }
    }
    spr = SprCreate(7, 5);
    D_80106600_3F71E0_name_68[2] = spr;
    data = DataRead(0xD0005);
    D_801065CC_3F71AC_name_68[2] = SprAnimRead(data);
    DataClose(data);
    SprAnimSet(spr, 0, (s16)D_801065CC_3F71AC_name_68[2], 0);
    func_800824F4_830F4(spr, 0, -1);
    SprAttrSet(spr, 0, 0x8000);
    SprPosSet(spr, 0, D_80106498_3F7078_name_68[0][0], D_80106498_3F7078_name_68[0][1]);
    SprAnimSet(spr, 1, (s16)D_801065CC_3F71AC_name_68[2], 0);
    func_8008225C_82E5C(spr, 1, 1);
    SprPrioSet(spr, 1, 0xF);
    SprAttrSet(spr, 1, 0x9000);
    SprPosSet(spr, 1, 0, 0);
    func_800824F4_830F4(spr, 1, 0);
    data = DataRead(0xD0006);
    D_801065B0_3F7190_name_68 = SprAnimRead(data);
    DataClose(data);
    SprAnimSet(spr, 2, (s16)D_801065B0_3F7190_name_68, 0);
    func_8008225C_82E5C(spr, 2, 1);
    SprPrioSet(spr, 2, 0xE);
    SprAttrSet(spr, 2, 0x9000);
    func_800824F4_830F4(spr, 2, 0);
    SprPosSet(spr, 2, 0, 2);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_68_name/3F3410", func_8010354C_3F412C_name_68);
#endif

void func_80104310_3F4EF0_name_68(void) {
    func_8008CCA8_8D8A8((s16)D_801065A4_3F7184_name_68);
}

void func_80104330_3F4F10_name_68(void) {
    Hu3DCamSetPerspective(1, 40.0f, 200.0f, 8000.0f);
    Hu3DCamSetPositionOrientation(1, &D_8010660C_3F71EC_name_68, &D_80106618_3F71F8_name_68, &D_80106624_3F7204_name_68);
    Hu3DCamUpdateMtx(1);
    CameraViewportSet(1, &D_80106630_3F7210_name_68, &D_8010663C_3F721C_name_68);
}

void func_80104398_3F4F78_name_68(void) {
    while (1) {
        func_80104330_3F4F10_name_68();
        HuPrcVSleep();       
    }
}

__asm__(".section .rodata");
const char D_80106518_3F70F8_name_68[] = "point1";

__asm__(".section .rodata");
const char D_80106520_3F7100_name_68[] = "point2";

void func_801043C4_3F4FA4_name_68(void) {
    Vec v;

    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    HuVecCopyXYZ(&v, 0.0f, 0.0f, 0.0f);
    OVL68_LINK(func_80056D80_57980(&D_80106658_3F7238_name_68->pos, &v, &D_80106658_3F7238_name_68->pos, 20));
    HuPrcChildWatch();
    func_80029E80_2AA80(D_80106658_3F7238_name_68->obj->model[0], 2, 1);
    HuVecCopyXYZ(&D_80106650_3F7230_name_68->pos, -6.278950214385986f, 19.16754913330078f, 0.0f);
    HuVecCopyXYZ(&D_80106654_3F7234_name_68->pos, 5.623000144958496f, 19.16754913330078f, 0.0f);
    HuPrcVSleep();
    func_8005AA98_5B698(D_80106650_3F7230_name_68->obj->model[0]);
    func_8005AA98_5B698(D_80106654_3F7234_name_68->obj->model[0]);
    HuPrcVSleep();
    func_8005670C_5730C(&v);
    OVL68_LINK(func_80056B78_57778(&D_80106650_3F7230_name_68->rot, &v, &D_80106650_3F7230_name_68->rot, 10));
    OVL68_LINK(func_80056B78_57778(&D_80106654_3F7234_name_68->rot, &v, &D_80106654_3F7234_name_68->rot, 10));
    HuPrcChildWatch();
    if (D_801065A8_3F7188_name_68 == 0) {
        MBMotionSet(D_80106650_3F7230_name_68, 6, 0);
        MBMotionSet(D_80106654_3F7234_name_68, 6, 0);
        func_800732B0_73EB0(D_801064C8_3F70A8_name_68[(s8)D_800FD8A8_FE4A8.character] | 0x54);
    } else {
        MBMotionSet(D_80106650_3F7230_name_68, 3, 0);
        MBMotionSet(D_80106654_3F7234_name_68, 3, 0);
    }
    while (1) {
        if (D_80106494_3F7074_name_68 != 0) {
            MBMotionSet(D_80106650_3F7230_name_68, 5, 0);
            MBMotionSet(D_80106654_3F7234_name_68, 5, 0);
            HuPrcSleep(30);
            break;
        }
        if (D_80106493_3F7073_name_68 != 0) {
            break;
        }
        HuPrcVSleep();
    }
    MBMotionShiftSet(D_80106650_3F7230_name_68, -1, 0, 10, 2);
    MBMotionShiftSet(D_80106654_3F7234_name_68, -1, 0, 10, 2);
    HuVecCopyXYZ(&v, -1.0f, 0.0f, 0.0f);
    OVL68_LINK(func_80056B78_57778(&D_80106650_3F7230_name_68->rot, &v, &D_80106650_3F7230_name_68->rot, 10));
    OVL68_LINK(func_80056B78_57778(&D_80106654_3F7234_name_68->rot, &v, &D_80106654_3F7234_name_68->rot, 10));
    HuPrcChildWatch();
    func_8005AA48_5B648(D_80106658_3F7238_name_68, D_80106518_3F70F8_name_68, D_80106650_3F7230_name_68->obj->model[0]);
    func_8005AA48_5B648(D_80106658_3F7238_name_68, D_80106520_3F7100_name_68, D_80106654_3F7234_name_68->obj->model[0]);
    func_80029E80_2AA80(D_80106658_3F7238_name_68->obj->model[0], 1, 2);
    HuVecCopyXYZ(&v, -100.0f, 0.0f, 0.0f);
    OVL68_LINK(func_80056D80_57980(&D_80106658_3F7238_name_68->pos, &v, &D_80106658_3F7238_name_68->pos, 20));
    HuPrcChildWatch();
    while (1) {
        HuPrcVSleep();
    }
}

void func_801047C4_3F53A4_name_68(void) {
    D_80106648_3F7228_name_68 = omAddPrcObj(func_80104398_3F4F78_name_68, 0x4000, 0, 0);
    D_8010660C_3F71EC_name_68.x = 0.0f;
    D_8010660C_3F71EC_name_68.y = 250.0f;
    D_8010660C_3F71EC_name_68.z = 200.0f;
    D_80106618_3F71F8_name_68.x = 0.0f;
    D_80106618_3F71F8_name_68.y = 0.0f;
    D_80106618_3F71F8_name_68.z = 0.0f;
    D_80106624_3F7204_name_68.x = 0.0f;
    D_80106624_3F7204_name_68.y = 1.0f;
    D_80106624_3F7204_name_68.z = 0.0f;
    D_80106630_3F7210_name_68.x = 1280.0f;
    D_80106630_3F7210_name_68.y = 960.0f;
    D_80106630_3F7210_name_68.z = 511.0f;
    D_8010663C_3F721C_name_68.x = 640.0f;
    D_8010663C_3F721C_name_68.y = 480.0f;
    D_8010663C_3F721C_name_68.z = 511.5f;
    func_80104330_3F4F10_name_68();
    D_80106658_3F7238_name_68 = func_80043510_44110(0xAA, NULL);
    HuVecCopyXYZ(&D_80106658_3F7238_name_68->rot, -1.0f, 0.0f, 0.0f);
    HuVecCopyXYZ(&D_80106658_3F7238_name_68->pos, 100.0f, 0.0f, 0.0f);
    D_80106658_3F7238_name_68->attr |= 1;
    func_80029EDC_2AADC(D_80106658_3F7238_name_68->obj->model[0], 2);
    D_80106650_3F7230_name_68 = func_80043510_44110(D_801064C0_3F70A0_name_68[(s8)D_800FD8A8_FE4A8.character], D_800CC8B8_CD4B8[(s8)D_800FD8A8_FE4A8.character]);
    HuVecCopyXYZ(&D_80106650_3F7230_name_68->rot, -1.0f, 0.0f, 0.0f);
    D_80106650_3F7230_name_68->attr |= 1;
    func_80029EDC_2AADC(D_80106650_3F7230_name_68->obj->model[0], 2);
    D_80106654_3F7234_name_68 = func_80043510_44110(D_801064C0_3F70A0_name_68[(s8)D_800FD8A8_FE4A8.character2], D_800CC8B8_CD4B8[(s8)D_800FD8A8_FE4A8.character2]);
    HuVecCopyXYZ(&D_80106654_3F7234_name_68->rot, -1.0f, 0.0f, 0.0f);
    D_80106654_3F7234_name_68->attr |= 1;
    func_80029EDC_2AADC(D_80106654_3F7234_name_68->obj->model[0], 2);
    func_8005AA48_5B648(D_80106658_3F7238_name_68, D_80106518_3F70F8_name_68, D_80106650_3F7230_name_68->obj->model[0]);
    func_8005AA48_5B648(D_80106658_3F7238_name_68, D_80106520_3F7100_name_68, D_80106654_3F7234_name_68->obj->model[0]);
    D_8010664C_3F722C_name_68 = omAddPrcObj(func_801043C4_3F4FA4_name_68, 0x4000, 0, 0);
}

void func_80104A90_3F5670_name_68(void) {
    omDelPrcObj(D_80106648_3F7228_name_68);
    omDelPrcObj(D_8010664C_3F722C_name_68);
    MBModelKill(D_80106650_3F7230_name_68);
    MBModelKill(D_80106654_3F7234_name_68);
    MBModelKill(D_80106658_3F7238_name_68);
}

void func_80104AE0_3F56C0_name_68(void) {
    switch (D_801065A8_3F7188_name_68) {
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

void func_80104B4C_3F572C_name_68(s8 idx) {
    f32 scale;
    s32 i;
    s32 n = idx;

    i = 0;
    do {
        i++;
        SprAttrReset((s16)D_80106600_3F71E0_name_68[n], i, 0x8000);
    } while (i < 6);
    for (scale = 0.0f; scale < 1.0; scale += 0.3) {
        i = 0;
        do {
            i++;
            SprScaleSet((s16)D_80106600_3F71E0_name_68[n], i, scale, scale);
        } while (i < 6);
        if (D_80106490_3F7070_name_68 == 0) {
            HuPrcVSleep();
        }
    }
    i = 0;
    do {
        i++;
        SprScaleSet((s16)D_80106600_3F71E0_name_68[n], i, 1.0f, 1.0f);
    } while (i < 6);
}

void func_80104C94_3F5874_name_68(void) {
    f32 scale;
    s32 i;

    i = 0;
    do {
        i++;
        SprAttrReset((s16)D_80106600_3F71E0_name_68[0], i, 0x8000);
        SprAttrReset((s16)D_80106600_3F71E0_name_68[1], i, 0x8000);
    } while (i < 6);
    for (scale = 0.0f; scale < 1.0; scale += 0.3) {
        i = 0;
        do {
            i++;
            SprScaleSet((s16)D_80106600_3F71E0_name_68[0], i, scale, scale);
            SprScaleSet((s16)D_80106600_3F71E0_name_68[1], i, scale, scale);
        } while (i < 6);
        if (D_80106490_3F7070_name_68 == 0) {
            HuPrcVSleep();
        }
    }
    i = 0;
    do {
        i++;
        SprScaleSet((s16)D_80106600_3F71E0_name_68[0], i, 1.0f, 1.0f);
        SprScaleSet((s16)D_80106600_3F71E0_name_68[1], i, 1.0f, 1.0f);
    } while (i < 6);
}

void func_80104E14_3F59F4_name_68(void) {
    f32 scale;
    s32 i;

    i = 0;
    do {
        i++;
        SprScaleSet((s16)D_80106600_3F71E0_name_68[0], i, 1.0f, 1.0f);
        SprScaleSet((s16)D_80106600_3F71E0_name_68[1], i, 1.0f, 1.0f);
    } while (i < 6);
    scale = 1.0f;
    do {
        i = 0;
        do {
            i++;
            SprScaleSet((s16)D_80106600_3F71E0_name_68[0], i, scale, scale);
            SprScaleSet((s16)D_80106600_3F71E0_name_68[1], i, scale, scale);
        } while (i < 6);
        if (D_80106490_3F7070_name_68 == 0) {
            HuPrcVSleep();
        }
        scale -= 0.3f;
    } while (scale > 0.0f);
    i = 0;
    do {
        i++;
        SprAttrSet((s16)D_80106600_3F71E0_name_68[0], i, 0x8000);
        SprAttrSet((s16)D_80106600_3F71E0_name_68[1], i, 0x8000);
    } while (i < 6);
}

#ifdef NON_MATCHING
void func_80104F94_3F5B74_name_68(void) {
    s16 val[4];
    s16 cnt[4];
    s16 digits[4][4];
    s32 i;
    s32 k;
    s32 j;

    val[0] = D_800FD8A8_FE4A8.lives - D_801065AC_3F718C_name_68;
    if (D_800FD8A8_FE4A8.streak > 0) {
        val[1] = (gPlayers[0].coins_mg + gPlayers[0].coins_mg_bonus) * D_800FD8A8_FE4A8.streak - D_80106496_3F7076_name_68;
    } else {
        val[1] = gPlayers[0].coins_mg + gPlayers[0].coins_mg_bonus - D_80106496_3F7076_name_68;
    }
    for (i = 0; i < 2; i++) {
        digits[i][0] = OVL68_ABS(val[i]) / 1000;
        digits[i][1] = (OVL68_ABS(val[i]) - digits[i][0] * 1000) / 100;
        digits[i][2] = (OVL68_ABS(val[i]) - digits[i][0] * 1000 - digits[i][1] * 100) / 10;
        digits[i][3] = OVL68_ABS(val[i]) - digits[i][0] * 1000 - digits[i][1] * 100 - digits[i][2] * 10;
        cnt[i] = 0;
        if (OVL68_ABS(val[i]) >= 10) {
            cnt[i] = 1;
        }
        if (OVL68_ABS(val[i]) >= 100) {
            cnt[i] = 2;
        }
        if (OVL68_ABS(val[i]) >= 1000) {
            cnt[i] = 3;
        }
    }
    for (i = 0; i < 2; i++) {
        j = 2;
        for (k = 0; k < 4; k++, j++) {
            func_800822A8_82EA8((s16)D_80106600_3F71E0_name_68[i], j, digits[i][k], 0);
            if (i == 0) {
                if (val[i] == 0) {
                    SprPosSet((s16)D_80106600_3F71E0_name_68[i], j, D_801064E0_3F70C0_name_68[cnt[i]][k], 2);
                } else {
                    SprPosSet((s16)D_80106600_3F71E0_name_68[i], j, D_801064E0_3F70C0_name_68[cnt[i]][k] + 4, 2);
                }
            } else if (D_801065A8_3F7188_name_68 == 0 && val[i] != 0) {
                SprPosSet((s16)D_80106600_3F71E0_name_68[i], j, D_801064E0_3F70C0_name_68[cnt[i]][k] + 4, 2);
            } else {
                SprPosSet((s16)D_80106600_3F71E0_name_68[i], j, D_801064E0_3F70C0_name_68[cnt[i]][k], 2);
            }
        }
        if (i == 0) {
            if (val[i] == 0) {
                SprPosSet((s16)D_80106600_3F71E0_name_68[i], j, -1000, -2);
                func_800822A8_82EA8((s16)D_80106600_3F71E0_name_68[i], j, 10, 0);
            } else {
                if (val[i] > 0) {
                    func_800822A8_82EA8((s16)D_80106600_3F71E0_name_68[i], j, 11, 0);
                } else {
                    func_800822A8_82EA8((s16)D_80106600_3F71E0_name_68[i], j, 12, 0);
                }
                SprPosSet((s16)D_80106600_3F71E0_name_68[i], j, D_801064E0_3F70C0_name_68[cnt[i]][3 - cnt[i]] - 4, 2);
            }
        } else if (D_801065A8_3F7188_name_68 == 0 && val[i] != 0) {
            if (val[i] > 0) {
                func_800822A8_82EA8((s16)D_80106600_3F71E0_name_68[i], j, 11, 0);
            } else {
                func_800822A8_82EA8((s16)D_80106600_3F71E0_name_68[i], j, 12, 0);
            }
            SprPosSet((s16)D_80106600_3F71E0_name_68[i], j, D_801064E0_3F70C0_name_68[cnt[i]][3 - cnt[i]] - 4, 2);
        } else {
            SprPosSet((s16)D_80106600_3F71E0_name_68[i], j, -1000, -2);
            func_800822A8_82EA8((s16)D_80106600_3F71E0_name_68[i], j, 10, 0);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_68_name/3F3410", func_80104F94_3F5B74_name_68);
#endif

void func_8010561C_3F61FC_name_68(void) {
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
    while ((s16)coins > D_80106496_3F7076_name_68) {
        D_80106496_3F7076_name_68 += step;
        if ((s16)coins <= D_80106496_3F7076_name_68) {
            D_800FD8A8_FE4A8.coins += step - ((u8)D_80106496_3F7076_name_68 - coins);
            D_80106496_3F7076_name_68 = coins;
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
                func_80104B4C_3F572C_name_68(2);
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
        func_80104F94_3F5B74_name_68();
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
            func_80104B4C_3F572C_name_68(2);
        }
    }
    func_80104F94_3F5B74_name_68();
}

void func_801058F4_3F64D4_name_68(void) {
    s16 size[2];
    s32 win;
    s8 choice;

    SprAttrSet((s16)D_801065B4_3F7194_name_68, 1, 0x8000);
    HuPrcSleep(30);
    PlayMusic(0x14);
    SprAttrReset((s16)D_801065C0_3F71A0_name_68, 1, 0x8000);
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
        D_80106494_3F7074_name_68 = 1;
        HuPrcSleep(30);
    }
    D_80106492_3F7072_name_68 = choice;
    D_80106491_3F7071_name_68 = 1;
}

void func_80105A74_3F6654_name_68(void) {
    s16 size[2];
    char buf[8];
    GAMEMES mesX;
    GAMEMES mesN;
    s16 win;

    if (D_800FD8A8_FE4A8.streak >= 2) {
        sprintf(buf, D_80106514_3F70F4_name_68, D_800FD8A8_FE4A8.streak);
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
        func_80104F94_3F5B74_name_68();
        PlaySound(0x33D);
        HuPrcSleep(0x19);
    }
}

#ifdef NON_MATCHING
void func_80105C24_3F6804_name_68(void) {
    s16 i;
    s32 show;
    s32 failed;

    switch (D_801065A8_3F7188_name_68) {
    case 0:
        HuPrcSleep(0x24);
        func_80079428_7A028(0x44);
        break;
    case 1:
        HuPrcSleep(0x24);
        func_80079428_7A028(0x45);
        break;
    }
    SprAttrReset((s16)D_801065B4_3F7194_name_68, 1, 0x8000);
    omAddPrcObj(func_80104AE0_3F56C0_name_68, 0x300, 0x2500, 0);
    HuPrcSleep(0x3C);
    if (D_801065A8_3F7188_name_68 == 0) {
        HuPrcSleep(30);
    } else {
        HuPrcSleep(20);
    }
    failed = 0;
    switch (D_801065A8_3F7188_name_68) {
    case 0:
        func_80104B4C_3F572C_name_68(1);
        for (i = 0; i < 30; i++) {
            if (D_80106490_3F7070_name_68 == 1) {
                break;
            }
            HuPrcVSleep();
        }
        func_80105A74_3F6654_name_68();
        func_8010561C_3F61FC_name_68();
        goto done;
    case 1:
        if (D_800FD8A8_FE4A8.lives <= 0) {
            failed = 1;
        }
        D_800FD8A8_FE4A8.lives--;
        func_80104F94_3F5B74_name_68();
        if (D_800FD8A8_FE4A8.lives < 0) {
            D_800FD8A8_FE4A8.lives = 0;
        }
        func_80104C94_3F5874_name_68();
        for (i = 0; i < 30; i++) {
            if (D_80106490_3F7070_name_68 == 1) {
                break;
            }
            HuPrcVSleep();
        }
    done:
        func_80104E14_3F59F4_name_68();
        show = failed;
        break;
    default:
        show = failed;
        break;
    }
    if (show != 0) {
        func_801058F4_3F64D4_name_68();
    } else {
        D_80106493_3F7073_name_68 = 1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_68_name/3F3410", func_80105C24_3F6804_name_68);
#endif

s32 func_80105E00_3F69E0_name_68(s16 minigame) {
    s32 total;

    total = gPlayers[0].coins_mg_bonus + gPlayers[0].coins_mg;
    switch (minigame) {
    case 0x24:
        if (total < D_80106500_3F70E0_name_68[0][D_800FD8A8_FE4A8.difficulty]) {
            return 0;
        }
        break;
    case 0x47:
        if (total < D_80106500_3F70E0_name_68[1][D_800FD8A8_FE4A8.difficulty]) {
            return 0;
        }
        break;
    case 0x48:
        if (total < D_80106500_3F70E0_name_68[2][D_800FD8A8_FE4A8.difficulty]) {
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

void func_80105ECC_3F6AAC_name_68(void) {
    s32 i;
    s32 j;

    SprKill((s16)D_801065B4_3F7194_name_68);
    SprKill((s16)D_801065C0_3F71A0_name_68);
    for (i = 0; i < 3; i++) {
        SprKill((s16)D_80106600_3F71E0_name_68[i]);
        SprAnimKill((s16)D_801065CC_3F71AC_name_68[i]);
    }
    SprAnimKill((s16)D_801065B0_3F7190_name_68);
    for (i = 0; i < 2; i++) {
        SprAnimKill((s16)D_801065D8_3F71B8_name_68[i]);
        for (j = 0; j < 4; j++) {
            SprAnimKill((s16)D_801065E0_3F71C0_name_68[i][j]);
        }
    }
    SprAnimKill((s16)D_801065B8_3F7198_name_68);
    SprAnimKill((s16)D_801065C4_3F71A4_name_68);
}

void func_80105FE4_3F6BC4_name_68(void) {
    func_80028334_28F34(D_800FD2A6_FDEA6, 2);
    func_80029EDC_2AADC(D_800FD2A6_FDEA6, 1);
    if (func_80105E00_3F69E0_name_68(GwSystem.chosenMinigameIndex) != 0) {
        D_801065A8_3F7188_name_68 = 0;
        _SetFlag(0x16);
        D_800FD8A8_FE4A8.streak++;
        PlayMusic(0x42);
    } else {
        D_801065A8_3F7188_name_68 = 1;
        _ClearFlag(0x16);
        D_800FD8A8_FE4A8.streak = 0;
        PlayMusic(0x43);
    }
    D_801065AA_3F718A_name_68 = D_800FD8A8_FE4A8.coins;
    D_801065AC_3F718C_name_68 = D_800FD8A8_FE4A8.lives;
    func_8010354C_3F412C_name_68();
    func_801047C4_3F53A4_name_68();
    func_80029E80_2AA80(D_800FA618_FB218->obj->model[0], 2, 1);
    func_80029E80_2AA80(((MBModel*)gPlayers[0].unk_24)->obj->model[0], 2, 1);
    func_80029E80_2AA80(((MBModel*)gPlayers[1].unk_24)->obj->model[0], 2, 1);
    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    func_80105C24_3F6804_name_68();
    HuPrcSleep(30);
    func_800794A8_7A0A8(0x5A);
    InitFadeOut(0, 0x10);
    HuPrcSleep(0x11);
    func_80104310_3F4EF0_name_68();
    func_80104A90_3F5670_name_68();
    func_80105ECC_3F6AAC_name_68();
    switch (D_80106492_3F7072_name_68) {
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

void func_801061E4_3F6DC4_name_68(void) {
    func_80103284_3F3E64_name_68();
    func_80074DB8_759B8(1);
    omAddPrcObj(func_80105FE4_3F6BC4_name_68, 0x1005, 0x1000, 0);
}

/* Scene 4: back on the space after the last stop passed. */
void func_80106220_3F6E00_name_68(void) {
    if (func_80075390_75F90(OVL68_FLAG_BASE + 23) != 0) {
        SetPlayerOntoChain(0, 0, 24);
    } else if (func_80075390_75F90(OVL68_FLAG_BASE + 22) != 0) {
        SetPlayerOntoChain(0, 0, 21);
    } else if (func_80075390_75F90(OVL68_FLAG_BASE + 21) != 0) {
        SetPlayerOntoChain(0, 0, 16);
    } else if (func_80075390_75F90(OVL68_FLAG_BASE + 20) != 0) {
        SetPlayerOntoChain(0, 0, 12);
    } else if (func_80075390_75F90(OVL68_FLAG_BASE + 19) != 0) {
        SetPlayerOntoChain(0, 0, 9);
    } else if (func_80075390_75F90(OVL68_FLAG_BASE + 18) != 0) {
        SetPlayerOntoChain(0, 0, 5);
    } else {
        SetPlayerOntoChain(0, 0, 0);
    }
    omOvlReturnEx(1);
}
