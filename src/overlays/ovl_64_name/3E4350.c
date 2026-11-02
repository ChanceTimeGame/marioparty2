#include "common.h"
#include "ovl_64.h"

#define OVL64_ABS(x) ((x) < 0 ? -(s32)(x) : (x))
/* Waits on a mover: makes it a child of the current process. */
#define OVL64_LINK(call) do { Process* _p = (call); HuPrcChildLink(HuPrcCurrentGet(), _p); } while (0)

__asm__(".section .rodata");
const char D_80106370_3E7E90_name_64[] = "%2d";

__asm__(".section .rodata");
const char D_80106374_3E7E94_name_64[] = "%d";

__asm__(".section .rodata");
const char D_80106378_3E7E98_name_64[] = "point1";
const char D_80106380_3E7EA0_name_64[] = "point2";
__asm__(".text");

/* Sets the board spaces of the stops already cleared (D_801061C0_3E7CE0_name_64). */
void func_80102830_3E4350_name_64(void) {
    CoasterSpaceFlag* entry;

    entry = D_801061C0_3E7CE0_name_64;
    while (entry->space >= 0) {
        if (func_80075390_75F90(entry->flag) != 0) {
            BoardSpaceTypeSet(entry->space, 1);
        }
        entry++;
    }
}

/* One bit of the saved game's flags. */
s32 func_8010288C_3E43AC_name_64(s32 bit) {
    return D_801063B0_3E7ED0_name_64.flags[bit / 8] & (1 << (bit % 8));
}

/* Opens the save menu's panel: the saved game's character, stage, lives and coins. */
void func_801028D0_3E43F0_name_64(void) {
    s16 size[2];
    void* data;
    s32 i;
    s32 win;

    D_801063E4_3E7F04_name_64 = func_8005E688_5F288(1, 0);
    data = DataRead(D_801061D4_3E7CF4_name_64[(s8)D_801063B0_3E7ED0_name_64.character]);
    i = 0;
    D_801063E4_3E7F04_name_64->unk0C[0] = SprAnimRead(data);
    SprAnimSet(D_801063E4_3E7F04_name_64->unk0A, 0, D_801063E4_3E7F04_name_64->unk0C[0], 0);
    SprPrioSet(D_801063E4_3E7F04_name_64->unk0A, 0, 0x10);
    SprAttrSet(D_801063E4_3E7F04_name_64->unk0A, 0, 0x1000);
    SprPosSet(D_801063E4_3E7F04_name_64->unk0A, 0, 0x3E, 0x5F);
    DataClose(data);
    D_801063C8_3E7EE8_name_64[6] = func_80057480_58080(D_80106234_3E7D54_name_64[0], D_80106234_3E7D54_name_64[1], 0x18, 5);
    for (; i < 4; i++) {
        func_8008DACC_8E6CC(1, size, D_801061EC_3E7D0C_name_64[i]);
        D_801063C8_3E7EE8_name_64[i] = (s16)func_800888A8_894A8(D_8010621C_3E7D3C_name_64[i][0], D_8010621C_3E7D3C_name_64[i][1], size[0], size[1], 0, 0);
        func_80089B2C_8A72C((s16)D_801063C8_3E7EE8_name_64[i], 0);
        func_80089A48_8A648((s16)D_801063C8_3E7EE8_name_64[i], 0);
        func_800890CC_89CCC((s16)D_801063C8_3E7EE8_name_64[i], (void*)D_801061EC_3E7D0C_name_64[i], -1, -1);
    }
    func_8008DACC_8E6CC(1, size, D_80106204_3E7D24_name_64[D_801063B0_3E7ED0_name_64.difficulty]);
    i = 4;
    D_801063C8_3E7EE8_name_64[i] = (s16)func_800888A8_894A8(D_8010622C_3E7D4C_name_64, D_8010622E_3E7D4E_name_64, size[0], size[1], 0, 0);
    func_80089B2C_8A72C((s16)D_801063C8_3E7EE8_name_64[i], 0);
    func_80089A48_8A648((s16)D_801063C8_3E7EE8_name_64[i], 0);
    func_800890CC_89CCC((s16)D_801063C8_3E7EE8_name_64[i], (void*)D_80106204_3E7D24_name_64[D_801063B0_3E7ED0_name_64.difficulty], -1, -1);
    sprintf(D_801063E8_3E7F08_name_64, D_80106370_3E7E90_name_64, D_801063B0_3E7ED0_name_64.chapter);
    func_8008D974_8E574(D_801063E8_3E7F08_name_64, 0);
    sprintf(D_801063F0_3E7F10_name_64, D_80106370_3E7E90_name_64, D_801063B0_3E7ED0_name_64.lives);
    func_8008D974_8E574(D_801063F0_3E7F10_name_64, 1);
    sprintf(D_801063F8_3E7F18_name_64, D_80106370_3E7E90_name_64, D_801063B0_3E7ED0_name_64.coins);
    func_8008D974_8E574(D_801063F8_3E7F18_name_64, 2);
    i = 5;
    func_8008DACC_8E6CC(1, size, D_801061EC_3E7D0C_name_64[i]);
    win = func_800888A8_894A8(D_80106230_3E7D50_name_64, D_80106232_3E7D52_name_64, size[0], size[1] * 2, 0, 0);
    D_801063C8_3E7EE8_name_64[i] = win;
    D_800F920C_F9E0C[win].unk28 = 0x12;
    func_80089B2C_8A72C((s16)D_801063C8_3E7EE8_name_64[i], 0);
    func_80089A48_8A648((s16)D_801063C8_3E7EE8_name_64[i], 0);
    func_80089308_89F08((s16)D_801063C8_3E7EE8_name_64[i], D_801063E8_3E7F08_name_64, 0);
    func_80089308_89F08((s16)D_801063C8_3E7EE8_name_64[i], D_801063F0_3E7F10_name_64, 1);
    func_80089308_89F08((s16)D_801063C8_3E7EE8_name_64[i], D_801063F8_3E7F18_name_64, 2);
    func_800890CC_89CCC((s16)D_801063C8_3E7EE8_name_64[i], (void*)D_801061EC_3E7D0C_name_64[i], -1, -1);
}

/* Closes the save menu's panel. */
void func_80102C88_3E47A8_name_64(void) {
    s32 i;

    for (i = 0; i < 7; i++) {
        func_8008CCA8_8D8A8((s16)D_801063C8_3E7EE8_name_64[i]);
    }
    HuMemDirectFree(D_801063E4_3E7F04_name_64);
}

/* The save point: offers to save (over a saved game, showing it first), then says goodbye; the
   difficulty's last stops have their own farewell. */
void func_80102CE4_3E4804_name_64(void) {
    char buf[8];
    s32 choice;

again:
    {
        sprintf(buf, D_80106374_3E7E94_name_64, D_800FD8A8_FE4A8.stage + 1);
        MBDlgWinInsertCreateY(0x29, 0x5CD, buf, NULL, NULL, NULL, NULL, 0xAA);
        choice = func_8008BB48_8C748(mbDlgWinId, 0, 1);
        MBDlgWinClose();
        func_80056168_56D68();
        HuPrcVSleep();
        if (choice == 0) {
            func_8007E0C8_7ECC8(&D_801063B0_3E7ED0_name_64);
            if (func_8010288C_3E43AC_name_64(0) != 0) {
                func_801028D0_3E43F0_name_64();
                sprintf(buf, D_80106374_3E7E94_name_64, D_801063B0_3E7ED0_name_64.stage + 1);
                MBDlgWinInsertCreateY(0x29, 0x5CF, buf, NULL, NULL, NULL, NULL, 0xAA);
                choice = func_8008BB48_8C748(mbDlgWinId, 0, 0);
                MBDlgWinClose();
                func_80056168_56D68();
                HuPrcVSleep();
                func_80102C88_3E47A8_name_64();
                if (choice != 0) {
                    goto again;
                }
            }
            func_800753D4_75FD4(0);
            _ClearFlag(0);
            func_8007E018_7EC18();
            func_8007E0C8_7ECC8(&D_801063B0_3E7ED0_name_64);
            func_801028D0_3E43F0_name_64();
            MBDlgWinInsertCreateY(0x29, 0x5D0, NULL, NULL, NULL, NULL, NULL, 0xAA);
            choice = func_8008BB48_8C748(mbDlgWinId, 0, 1);
            MBDlgWinClose();
            func_80056168_56D68();
            func_80102C88_3E47A8_name_64();
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
    MBDlgWinExecY(0x29, D_80106210_3E7D30_name_64[D_800FD8A8_FE4A8.difficulty], 0xAA);
}

/* A signpost: unless flag 9 + sign is set, names that stop's minigame until A. */
void func_801030B8_3E4BD8_name_64(s32 sign) {
    s16 size[2];
    s32 win;
    s32 name;

    if (func_80075390_75F90(sign + OVL64_FLAG_BASE) == 0) {
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

/* Scene 0: a new game goes back to the course map (63). */
void func_801031D0_3E4CF0_name_64(void) {
    D_800FD8A8_FE4A8.stage = OVL64_STAGE;
    omInitObjMan(10, 0);
    omOvlGotoEx(OVL64_NEXT_SCENE, OVL64_NEXT_ENTRY, 0x192);
}

/* Scene 1: back on the start space, stop flags cleared. */
void func_80103208_3E4D28_name_64(void) {
    omInitObjMan(10, 0);
    SetPlayerOntoChain(0, 0, 0);
    func_80075010_75C10(0);
    func_80075424_76024(OVL64_FLAG_BASE + 0);
    func_80075424_76024(OVL64_FLAG_BASE + 1);
    func_80075424_76024(OVL64_FLAG_BASE + 2);
    func_80075424_76024(OVL64_FLAG_BASE + 3);
    func_80073410_74010(-1);
    omOvlReturnEx(1);
}

/* The board's common setup. */
void func_80103270_3E4D90_name_64(void) {
    omInitObjMan(0x50, 0x28);
    func_80020070_20C70(2);
    func_80026D28_27928(1);
    func_80026DAC_279AC(0, 0x78, 0x78, 0x78);
    func_80026DAC_279AC(1, 0x40, 0x40, 0x60);
    func_80026E00_27A00(1, -100.0f, 100.0f, 300.0f);
    func_80074154_74D54(OVL64_BOARD_MODEL, OVL64_BOARD_FILE);
    EventTableHydrate(D_80106298_3E7DB8_name_64);
    func_80102830_3E4350_name_64();
}

/* Scene 2: the board; the player walks, D_80106298_3E7DB8_name_64 fires the signposts. */
void func_801032FC_3E4E1C_name_64(void) {
    func_80103270_3E4D90_name_64();
    func_80074DB8_759B8(0);
    PlayMusic(OVL64_MUSIC);
}

void func_80103328_3E4E48_name_64(void) {
    func_80073410_74010(0);
    func_801030B8_3E4BD8_name_64(0);
}

void func_8010334C_3E4E6C_name_64(void) {
    func_80073410_74010(1);
    func_801030B8_3E4BD8_name_64(1);
}

void func_80103370_3E4E90_name_64(void) {
    func_80073410_74010(2);
    func_801030B8_3E4BD8_name_64(2);
}

void func_80103394_3E4EB4_name_64(void) {
    func_80073410_74010(3);
    func_801030B8_3E4BD8_name_64(3);
}

void func_801033B8_3E4ED8_name_64(void) {
    MBPlayerVibrate(-1, 3);
    func_80075010_75C10(1);
    func_80073410_74010(-2);
    func_80102CE4_3E4804_name_64();
}

void func_801033F0_3E4F10_name_64(void) {
    func_80074FAC_75BAC(1, 0, 1, 1);
}

/* Creates the result screen: fade window, banners, and the lives and coins panels (a sign and
   four digits each, in thousands..units, placed by the number of digits). */
/* NON_MATCHING: control flow (class 3). Retail reloads val[i] after the zero test on the sign
   sprite; every call, store and table read agrees. Stays asm in the matching build. */
#ifdef NON_MATCHING
void func_80103418_3E4F38_name_64(void) {
    s16 cnt[4];
    s16 digits[2][4];
    s16 val[2];
    s32 spr;
    s16 i;
    s16 j;
    s16 k;
    s32 file;
    void* data;

    D_80106400_3E7F20_name_64 = (s16)func_800888A8_894A8(0, 0, 0x140, 0xF0, 0, 4);
    func_80089B2C_8A72C((s16)D_80106400_3E7F20_name_64, 0xC8);
    func_8008D530_8E130((s16)D_80106400_3E7F20_name_64, 0, 0, 0);
    D_80106410_3E7F30_name_64 = SprCreate(3, 5);
    SprPosSet((s16)D_80106410_3E7F30_name_64, 0, 0, 0);
    data = DataRead(D_801062D0_3E7DF0_name_64[D_80106404_3E7F24_name_64][0]);
    i = 0;
    D_80106414_3E7F34_name_64 = SprAnimRead(data);
    DataClose(data);
    SprAnimSet((s16)D_80106410_3E7F30_name_64, 1, (s16)D_80106414_3E7F34_name_64, 0);
    func_8008225C_82E5C((s16)D_80106410_3E7F30_name_64, 1, 1);
    SprPrioSet((s16)D_80106410_3E7F30_name_64, 1, 0x10);
    SprAttrSet((s16)D_80106410_3E7F30_name_64, 1, 0x9000);
    SprPosSet((s16)D_80106410_3E7F30_name_64, 1, 0xA0, 0xAA);
    func_8008221C_82E1C((s16)D_80106410_3E7F30_name_64, 1, 0.0f);
    D_8010641C_3E7F3C_name_64 = SprCreate(3, 5);
    SprPosSet((s16)D_8010641C_3E7F3C_name_64, 0, 0, 0);
    data = DataRead(D_801062E0_3E7E00_name_64[0]);
    D_80106420_3E7F40_name_64 = SprAnimRead(data);
    DataClose(data);
    SprAnimSet((s16)D_8010641C_3E7F3C_name_64, 1, (s16)D_80106420_3E7F40_name_64, 0);
    func_8008225C_82E5C((s16)D_8010641C_3E7F3C_name_64, 1, 1);
    SprPrioSet((s16)D_8010641C_3E7F3C_name_64, 1, 0x10);
    SprAttrSet((s16)D_8010641C_3E7F3C_name_64, 1, 0x9000);
    SprPosSet((s16)D_8010641C_3E7F3C_name_64, 1, 0xA0, 0xA0);
    func_8008221C_82E1C((s16)D_80106410_3E7F30_name_64, 1, 0.0f);
    val[0] = D_800FD8A8_FE4A8.lives - D_80106408_3E7F28_name_64;
    val[1] = gPlayers[0].coins_mg_bonus + gPlayers[0].coins_mg;
    for (; i < 2; i++) {
        digits[i][0] = OVL64_ABS(val[i]) / 1000;
        digits[i][1] = (OVL64_ABS(val[i]) - digits[i][0] * 1000) / 100;
        digits[i][2] = (OVL64_ABS(val[i]) - digits[i][0] * 1000 - digits[i][1] * 100) / 10;
        digits[i][3] = OVL64_ABS(val[i]) - digits[i][0] * 1000 - digits[i][1] * 100 - digits[i][2] * 10;
        cnt[i] = 0;
        if (OVL64_ABS(val[i]) >= 10) {
            cnt[i] = 1;
        }
        if (OVL64_ABS(val[i]) >= 100) {
            cnt[i] = 2;
        }
        if (OVL64_ABS(val[i]) >= 1000) {
            cnt[i] = 3;
        }
    }
    for (i = 0; i < 2; i++) {
        j = 0;
        spr = SprCreate(7, 5);
        D_80106460_3E7F80_name_64[i] = spr;
        if (i == 0 || val[i] < 0) {
            file = 0xD0004;
        } else {
            file = 0xD0005;
        }
        data = DataRead(file);
        D_80106428_3E7F48_name_64[i] = SprAnimRead(data);
        DataClose(data);
        SprAnimSet(spr, j, (s16)D_80106428_3E7F48_name_64[i], 0);
        func_800824F4_830F4(spr, j, -1);
        SprAttrSet(spr, j, 0x8000);
        SprPosSet(spr, j, D_801062F0_3E7E10_name_64[i][0], D_801062F0_3E7E10_name_64[i][1]);
        j++;
        SprAnimSet(spr, j, (s16)D_80106428_3E7F48_name_64[i], 0);
        func_8008225C_82E5C(spr, j, 1);
        SprPrioSet(spr, j, 0xF);
        SprAttrSet(spr, j, 0x9000);
        SprPosSet(spr, j, 0, 0);
        func_800824F4_830F4(spr, j, 0);
        j++;
        for (k = 0; k < 4; k++, j++) {
            data = DataRead(0xC000D);
            D_80106440_3E7F60_name_64[i][k] = SprAnimRead(data);
            DataClose(data);
            SprAnimSet(spr, j, (s16)D_80106440_3E7F60_name_64[i][k], 0);
            func_8008225C_82E5C(spr, j, 1);
            SprPrioSet(spr, j, 0xE);
            SprAttrSet(spr, j, 0x9000);
            func_800822A8_82EA8(spr, j, digits[i][k], 0);
            func_800824F4_830F4(spr, j, 0);
            func_8008221C_82E1C(spr, j, 0.0f);
            if (i == 0) {
                if (val[i] == 0) {
                    SprPosSet(spr, j, D_801062F8_3E7E18_name_64[cnt[i]][k], 2);
                } else {
                    SprPosSet(spr, j, D_801062F8_3E7E18_name_64[cnt[i]][k] + 4, 2);
                }
            } else if (D_80106404_3E7F24_name_64 == 0) {
                if (val[i] == 0) {
                    SprPosSet(spr, j, D_801062F8_3E7E18_name_64[cnt[i]][k], 2);
                } else {
                    SprPosSet(spr, j, D_801062F8_3E7E18_name_64[cnt[i]][k] + 4, 2);
                }
            } else {
                func_80082450_83050(spr, j, 0xFF, 0, 0);
                SprPosSet(spr, j, D_801062F8_3E7E18_name_64[cnt[i]][k], 2);
            }
        }
        data = DataRead(0xC000D);
        D_80106434_3E7F54_name_64[i] = SprAnimRead(data);
        DataClose(data);
        SprAnimSet(spr, j, (s16)D_80106434_3E7F54_name_64[i], 0);
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
                SprPosSet(spr, j, D_801062F8_3E7E18_name_64[cnt[i]][3 - cnt[i]] - 4, 2);
            }
        } else if (D_80106404_3E7F24_name_64 == 0 && val[i] != 0) {
            if (val[i] > 0) {
                func_800822A8_82EA8(spr, j, 11, 0);
            } else {
                func_800822A8_82EA8(spr, j, 12, 0);
            }
            SprPosSet(spr, j, D_801062F8_3E7E18_name_64[cnt[i]][3 - cnt[i]] - 4, 2);
        } else {
            SprPosSet(spr, j, -1000, 2);
            func_800822A8_82EA8(spr, j, 10, 0);
        }
    }
    spr = SprCreate(7, 5);
    D_80106460_3E7F80_name_64[2] = spr;
    data = DataRead(0xD0005);
    D_80106428_3E7F48_name_64[2] = SprAnimRead(data);
    DataClose(data);
    SprAnimSet(spr, 0, (s16)D_80106428_3E7F48_name_64[2], 0);
    func_800824F4_830F4(spr, 0, -1);
    SprAttrSet(spr, 0, 0x8000);
    SprPosSet(spr, 0, D_801062F0_3E7E10_name_64[0][0], D_801062F0_3E7E10_name_64[0][1]);
    SprAnimSet(spr, 1, (s16)D_80106428_3E7F48_name_64[2], 0);
    func_8008225C_82E5C(spr, 1, 1);
    SprPrioSet(spr, 1, 0xF);
    SprAttrSet(spr, 1, 0x9000);
    SprPosSet(spr, 1, 0, 0);
    func_800824F4_830F4(spr, 1, 0);
    data = DataRead(0xD0006);
    D_8010640C_3E7F2C_name_64 = SprAnimRead(data);
    DataClose(data);
    SprAnimSet(spr, 2, (s16)D_8010640C_3E7F2C_name_64, 0);
    func_8008225C_82E5C(spr, 2, 1);
    SprPrioSet(spr, 2, 0xE);
    SprAttrSet(spr, 2, 0x9000);
    func_800824F4_830F4(spr, 2, 0);
    SprPosSet(spr, 2, 0, 2);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_64_name/3E4350", func_80103418_3E4F38_name_64);
#endif

void func_801041DC_3E5CFC_name_64(void) {
    func_8008CCA8_8D8A8((s16)D_80106400_3E7F20_name_64);
}

/* The result scene's camera. */
void func_801041FC_3E5D1C_name_64(void) {
    Hu3DCamSetPerspective(1, 40.0f, 200.0f, 8000.0f);
    Hu3DCamSetPositionOrientation(1, &D_8010646C_3E7F8C_name_64, &D_80106478_3E7F98_name_64, &D_80106484_3E7FA4_name_64);
    Hu3DCamUpdateMtx(1);
    CameraViewportSet(1, &D_80106490_3E7FB0_name_64, &D_8010649C_3E7FBC_name_64);
}

void func_80104264_3E5D84_name_64(void) {
    while (1) {
        func_801041FC_3E5D1C_name_64();
        HuPrcVSleep();
    }
}

/* The result scene's staging: the vehicle (model 0xAA) moves in, the two characters are detached
   from it, turn, play the clear/fail motion, turn back, are re-attached to "point1"/"point2", and it
   moves off. */
void func_80104290_3E5DB0_name_64(void) {
    Vec v;

    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    HuVecCopyXYZ(&v, 0.0f, 0.0f, 0.0f);
    OVL64_LINK(func_80056D80_57980(&D_801064B8_3E7FD8_name_64->pos, &v, &D_801064B8_3E7FD8_name_64->pos, 20));
    HuPrcChildWatch();
    func_80029E80_2AA80(D_801064B8_3E7FD8_name_64->obj->model[0], 2, 1);
    HuVecCopyXYZ(&D_801064B0_3E7FD0_name_64->pos, -6.278950214385986f, 19.16754913330078f, 0.0f);
    HuVecCopyXYZ(&D_801064B4_3E7FD4_name_64->pos, 5.623000144958496f, 19.16754913330078f, 0.0f);
    HuPrcVSleep();
    func_8005AA98_5B698(D_801064B0_3E7FD0_name_64->obj->model[0]);
    func_8005AA98_5B698(D_801064B4_3E7FD4_name_64->obj->model[0]);
    HuPrcVSleep();
    func_8005670C_5730C(&v);
    OVL64_LINK(func_80056B78_57778(&D_801064B0_3E7FD0_name_64->rot, &v, &D_801064B0_3E7FD0_name_64->rot, 10));
    OVL64_LINK(func_80056B78_57778(&D_801064B4_3E7FD4_name_64->rot, &v, &D_801064B4_3E7FD4_name_64->rot, 10));
    HuPrcChildWatch();
    if (D_80106404_3E7F24_name_64 == 0) {
        MBMotionSet(D_801064B0_3E7FD0_name_64, 6, 0);
        MBMotionSet(D_801064B4_3E7FD4_name_64, 6, 0);
        func_800732B0_73EB0(D_80106320_3E7E40_name_64[(s8)D_800FD8A8_FE4A8.character] | 0x54);
    } else {
        MBMotionSet(D_801064B0_3E7FD0_name_64, 3, 0);
        MBMotionSet(D_801064B4_3E7FD4_name_64, 3, 0);
    }
    while (1) {
        if (D_801062EC_3E7E0C_name_64 != 0) {
            MBMotionSet(D_801064B0_3E7FD0_name_64, 5, 0);
            MBMotionSet(D_801064B4_3E7FD4_name_64, 5, 0);
            HuPrcSleep(30);
            break;
        }
        if (D_801062EB_3E7E0B_name_64 != 0) {
            break;
        }
        HuPrcVSleep();
    }
    MBMotionShiftSet(D_801064B0_3E7FD0_name_64, -1, 0, 10, 2);
    MBMotionShiftSet(D_801064B4_3E7FD4_name_64, -1, 0, 10, 2);
    HuVecCopyXYZ(&v, -1.0f, 0.0f, 0.0f);
    OVL64_LINK(func_80056B78_57778(&D_801064B0_3E7FD0_name_64->rot, &v, &D_801064B0_3E7FD0_name_64->rot, 10));
    OVL64_LINK(func_80056B78_57778(&D_801064B4_3E7FD4_name_64->rot, &v, &D_801064B4_3E7FD4_name_64->rot, 10));
    HuPrcChildWatch();
    func_8005AA48_5B648(D_801064B8_3E7FD8_name_64, D_80106378_3E7E98_name_64, D_801064B0_3E7FD0_name_64->obj->model[0]);
    func_8005AA48_5B648(D_801064B8_3E7FD8_name_64, D_80106380_3E7EA0_name_64, D_801064B4_3E7FD4_name_64->obj->model[0]);
    func_80029E80_2AA80(D_801064B8_3E7FD8_name_64->obj->model[0], 1, 2);
    HuVecCopyXYZ(&v, -100.0f, 0.0f, 0.0f);
    OVL64_LINK(func_80056D80_57980(&D_801064B8_3E7FD8_name_64->pos, &v, &D_801064B8_3E7FD8_name_64->pos, 20));
    HuPrcChildWatch();
    while (1) {
        HuPrcVSleep();
    }
}

/* Builds the result scene: camera, vehicle, the two characters on it. */
void func_80104690_3E61B0_name_64(void) {
    D_801064A8_3E7FC8_name_64 = omAddPrcObj(func_80104264_3E5D84_name_64, 0x4000, 0, 0);
    D_8010646C_3E7F8C_name_64.x = 0.0f;
    D_8010646C_3E7F8C_name_64.y = 250.0f;
    D_8010646C_3E7F8C_name_64.z = 200.0f;
    D_80106478_3E7F98_name_64.x = 0.0f;
    D_80106478_3E7F98_name_64.y = 0.0f;
    D_80106478_3E7F98_name_64.z = 0.0f;
    D_80106484_3E7FA4_name_64.x = 0.0f;
    D_80106484_3E7FA4_name_64.y = 1.0f;
    D_80106484_3E7FA4_name_64.z = 0.0f;
    D_80106490_3E7FB0_name_64.x = 1280.0f;
    D_80106490_3E7FB0_name_64.y = 960.0f;
    D_80106490_3E7FB0_name_64.z = 511.0f;
    D_8010649C_3E7FBC_name_64.x = 640.0f;
    D_8010649C_3E7FBC_name_64.y = 480.0f;
    D_8010649C_3E7FBC_name_64.z = 511.5f;
    func_801041FC_3E5D1C_name_64();
    D_801064B8_3E7FD8_name_64 = func_80043510_44110(0xAA, NULL);
    HuVecCopyXYZ(&D_801064B8_3E7FD8_name_64->rot, -1.0f, 0.0f, 0.0f);
    HuVecCopyXYZ(&D_801064B8_3E7FD8_name_64->pos, 100.0f, 0.0f, 0.0f);
    D_801064B8_3E7FD8_name_64->attr |= 1;
    func_80029EDC_2AADC(D_801064B8_3E7FD8_name_64->obj->model[0], 2);
    D_801064B0_3E7FD0_name_64 = func_80043510_44110(D_80106318_3E7E38_name_64[(s8)D_800FD8A8_FE4A8.character], D_800CC8B8_CD4B8[(s8)D_800FD8A8_FE4A8.character]);
    HuVecCopyXYZ(&D_801064B0_3E7FD0_name_64->rot, -1.0f, 0.0f, 0.0f);
    D_801064B0_3E7FD0_name_64->attr |= 1;
    func_80029EDC_2AADC(D_801064B0_3E7FD0_name_64->obj->model[0], 2);
    D_801064B4_3E7FD4_name_64 = func_80043510_44110(D_80106318_3E7E38_name_64[(s8)D_800FD8A8_FE4A8.character2], D_800CC8B8_CD4B8[(s8)D_800FD8A8_FE4A8.character2]);
    HuVecCopyXYZ(&D_801064B4_3E7FD4_name_64->rot, -1.0f, 0.0f, 0.0f);
    D_801064B4_3E7FD4_name_64->attr |= 1;
    func_80029EDC_2AADC(D_801064B4_3E7FD4_name_64->obj->model[0], 2);
    func_8005AA48_5B648(D_801064B8_3E7FD8_name_64, D_80106378_3E7E98_name_64, D_801064B0_3E7FD0_name_64->obj->model[0]);
    func_8005AA48_5B648(D_801064B8_3E7FD8_name_64, D_80106380_3E7EA0_name_64, D_801064B4_3E7FD4_name_64->obj->model[0]);
    D_801064AC_3E7FCC_name_64 = omAddPrcObj(func_80104290_3E5DB0_name_64, 0x4000, 0, 0);
}

void func_8010495C_3E647C_name_64(void) {
    omDelPrcObj(D_801064A8_3E7FC8_name_64);
    omDelPrcObj(D_801064AC_3E7FCC_name_64);
    MBModelKill(D_801064B0_3E7FD0_name_64);
    MBModelKill(D_801064B4_3E7FD4_name_64);
    MBModelKill(D_801064B8_3E7FD8_name_64);
}

/* The fail's jingle call (func_80079718 with the character). */
void func_801049AC_3E64CC_name_64(void) {
    switch (D_80106404_3E7F24_name_64) {
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

/* Zooms panel idx in. */
void func_80104A18_3E6538_name_64(s8 idx) {
    f32 scale;
    s32 i;
    s32 n = idx;

    i = 0;
    do {
        i++;
        SprAttrReset((s16)D_80106460_3E7F80_name_64[n], i, 0x8000);
    } while (i < 6);
    for (scale = 0.0f; scale < 1.0; scale += 0.3) {
        i = 0;
        do {
            i++;
            SprScaleSet((s16)D_80106460_3E7F80_name_64[n], i, scale, scale);
        } while (i < 6);
        if (D_801062E8_3E7E08_name_64 == 0) {
            HuPrcVSleep();
        }
    }
    i = 0;
    do {
        i++;
        SprScaleSet((s16)D_80106460_3E7F80_name_64[n], i, 1.0f, 1.0f);
    } while (i < 6);
}

/* Zooms both panels in. */
void func_80104B60_3E6680_name_64(void) {
    f32 scale;
    s32 i;

    i = 0;
    do {
        i++;
        SprAttrReset((s16)D_80106460_3E7F80_name_64[0], i, 0x8000);
        SprAttrReset((s16)D_80106460_3E7F80_name_64[1], i, 0x8000);
    } while (i < 6);
    for (scale = 0.0f; scale < 1.0; scale += 0.3) {
        i = 0;
        do {
            i++;
            SprScaleSet((s16)D_80106460_3E7F80_name_64[0], i, scale, scale);
            SprScaleSet((s16)D_80106460_3E7F80_name_64[1], i, scale, scale);
        } while (i < 6);
        if (D_801062E8_3E7E08_name_64 == 0) {
            HuPrcVSleep();
        }
    }
    i = 0;
    do {
        i++;
        SprScaleSet((s16)D_80106460_3E7F80_name_64[0], i, 1.0f, 1.0f);
        SprScaleSet((s16)D_80106460_3E7F80_name_64[1], i, 1.0f, 1.0f);
    } while (i < 6);
}

/* Zooms both panels out. */
void func_80104CE0_3E6800_name_64(void) {
    f32 scale;
    s32 i;

    i = 0;
    do {
        i++;
        SprScaleSet((s16)D_80106460_3E7F80_name_64[0], i, 1.0f, 1.0f);
        SprScaleSet((s16)D_80106460_3E7F80_name_64[1], i, 1.0f, 1.0f);
    } while (i < 6);
    scale = 1.0f;
    do {
        i = 0;
        do {
            i++;
            SprScaleSet((s16)D_80106460_3E7F80_name_64[0], i, scale, scale);
            SprScaleSet((s16)D_80106460_3E7F80_name_64[1], i, scale, scale);
        } while (i < 6);
        if (D_801062E8_3E7E08_name_64 == 0) {
            HuPrcVSleep();
        }
        scale -= 0.3f;
    } while (scale > 0.0f);
    i = 0;
    do {
        i++;
        SprAttrSet((s16)D_80106460_3E7F80_name_64[0], i, 0x8000);
        SprAttrSet((s16)D_80106460_3E7F80_name_64[1], i, 0x8000);
    } while (i < 6);
}

/* Redraws the two panels from the save and the coins still to count. */
/* NON_MATCHING: control flow (class 3). Retail reloads val[i] after the zero test on the sign
   sprite; every call, store and table read agrees. Stays asm in the matching build. */
#ifdef NON_MATCHING
void func_80104E60_3E6980_name_64(void) {
    s16 val[4];
    s16 cnt[4];
    s16 digits[4][4];
    s32 i;
    s32 k;
    s32 j;

    val[0] = D_800FD8A8_FE4A8.lives - D_80106408_3E7F28_name_64;
    if (D_800FD8A8_FE4A8.streak > 0) {
        val[1] = (gPlayers[0].coins_mg + gPlayers[0].coins_mg_bonus) * D_800FD8A8_FE4A8.streak - D_801062EE_3E7E0E_name_64;
    } else {
        val[1] = gPlayers[0].coins_mg + gPlayers[0].coins_mg_bonus - D_801062EE_3E7E0E_name_64;
    }
    for (i = 0; i < 2; i++) {
        digits[i][0] = OVL64_ABS(val[i]) / 1000;
        digits[i][1] = (OVL64_ABS(val[i]) - digits[i][0] * 1000) / 100;
        digits[i][2] = (OVL64_ABS(val[i]) - digits[i][0] * 1000 - digits[i][1] * 100) / 10;
        digits[i][3] = OVL64_ABS(val[i]) - digits[i][0] * 1000 - digits[i][1] * 100 - digits[i][2] * 10;
        cnt[i] = 0;
        if (OVL64_ABS(val[i]) >= 10) {
            cnt[i] = 1;
        }
        if (OVL64_ABS(val[i]) >= 100) {
            cnt[i] = 2;
        }
        if (OVL64_ABS(val[i]) >= 1000) {
            cnt[i] = 3;
        }
    }
    for (i = 0; i < 2; i++) {
        j = 2;
        for (k = 0; k < 4; k++, j++) {
            func_800822A8_82EA8((s16)D_80106460_3E7F80_name_64[i], j, digits[i][k], 0);
            if (i == 0) {
                if (val[i] == 0) {
                    SprPosSet((s16)D_80106460_3E7F80_name_64[i], j, D_80106338_3E7E58_name_64[cnt[i]][k], 2);
                } else {
                    SprPosSet((s16)D_80106460_3E7F80_name_64[i], j, D_80106338_3E7E58_name_64[cnt[i]][k] + 4, 2);
                }
            } else if (D_80106404_3E7F24_name_64 == 0 && val[i] != 0) {
                SprPosSet((s16)D_80106460_3E7F80_name_64[i], j, D_80106338_3E7E58_name_64[cnt[i]][k] + 4, 2);
            } else {
                SprPosSet((s16)D_80106460_3E7F80_name_64[i], j, D_80106338_3E7E58_name_64[cnt[i]][k], 2);
            }
        }
        if (i == 0) {
            if (val[i] == 0) {
                SprPosSet((s16)D_80106460_3E7F80_name_64[i], j, -1000, -2);
                func_800822A8_82EA8((s16)D_80106460_3E7F80_name_64[i], j, 10, 0);
            } else {
                if (val[i] > 0) {
                    func_800822A8_82EA8((s16)D_80106460_3E7F80_name_64[i], j, 11, 0);
                } else {
                    func_800822A8_82EA8((s16)D_80106460_3E7F80_name_64[i], j, 12, 0);
                }
                SprPosSet((s16)D_80106460_3E7F80_name_64[i], j, D_80106338_3E7E58_name_64[cnt[i]][3 - cnt[i]] - 4, 2);
            }
        } else if (D_80106404_3E7F24_name_64 == 0 && val[i] != 0) {
            if (val[i] > 0) {
                func_800822A8_82EA8((s16)D_80106460_3E7F80_name_64[i], j, 11, 0);
            } else {
                func_800822A8_82EA8((s16)D_80106460_3E7F80_name_64[i], j, 12, 0);
            }
            SprPosSet((s16)D_80106460_3E7F80_name_64[i], j, D_80106338_3E7E58_name_64[cnt[i]][3 - cnt[i]] - 4, 2);
        } else {
            SprPosSet((s16)D_80106460_3E7F80_name_64[i], j, -1000, -2);
            func_800822A8_82EA8((s16)D_80106460_3E7F80_name_64[i], j, 10, 0);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_64_name/3E4350", func_80104E60_3E6980_name_64);
#endif

/* Counts the coins won into the save; 100 coins buy a life. */
void func_801054E8_3E7008_name_64(void) {
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
    while ((s16)coins > D_801062EE_3E7E0E_name_64) {
        D_801062EE_3E7E0E_name_64 += step;
        if ((s16)coins <= D_801062EE_3E7E0E_name_64) {
            D_800FD8A8_FE4A8.coins += step - ((u8)D_801062EE_3E7E0E_name_64 - coins);
            D_801062EE_3E7E0E_name_64 = coins;
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
                func_80104A18_3E6538_name_64(2);
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
        func_80104E60_3E6980_name_64();
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
            func_80104A18_3E6538_name_64(2);
        }
    }
    func_80104E60_3E6980_name_64();
}

/* Out of lives: the "continue?" banner and question. */
void func_801057C0_3E72E0_name_64(void) {
    s16 size[2];
    s32 win;
    s8 choice;

    SprAttrSet((s16)D_80106410_3E7F30_name_64, 1, 0x8000);
    HuPrcSleep(30);
    PlayMusic(0x14);
    SprAttrReset((s16)D_8010641C_3E7F3C_name_64, 1, 0x8000);
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
        D_801062EC_3E7E0C_name_64 = 1;
        HuPrcSleep(30);
    }
    D_801062EA_3E7E0A_name_64 = choice;
    D_801062E9_3E7E09_name_64 = 1;
}

/* The win-streak multiplier flies in over the coin panel. */
void func_80105940_3E7460_name_64(void) {
    s16 size[2];
    char buf[8];
    GAMEMES mesX;
    GAMEMES mesN;
    s16 win;

    if (D_800FD8A8_FE4A8.streak >= 2) {
        sprintf(buf, D_80106374_3E7E94_name_64, D_800FD8A8_FE4A8.streak);
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
        func_80104E60_3E6980_name_64();
        PlaySound(0x33D);
        HuPrcSleep(0x19);
    }
}

/* The result's sequence. */
/* NON_MATCHING: register allocation (masked 0): retail keeps `failed` in s2 and the 1 in s1. `show`
   is an extra copy (fakematch form) that gives retail's instruction count. Stays asm in the
   matching build. */
#ifdef NON_MATCHING
void func_80105AF0_3E7610_name_64(void) {
    s16 i;
    s32 show;
    s32 failed;

    switch (D_80106404_3E7F24_name_64) {
    case 0:
        HuPrcSleep(0x24);
        func_80079428_7A028(0x44);
        break;
    case 1:
        HuPrcSleep(0x24);
        func_80079428_7A028(0x45);
        break;
    }
    SprAttrReset((s16)D_80106410_3E7F30_name_64, 1, 0x8000);
    omAddPrcObj(func_801049AC_3E64CC_name_64, 0x300, 0x2500, 0);
    HuPrcSleep(0x3C);
    if (D_80106404_3E7F24_name_64 == 0) {
        HuPrcSleep(30);
    } else {
        HuPrcSleep(20);
    }
    failed = 0;
    switch (D_80106404_3E7F24_name_64) {
    case 0:
        func_80104A18_3E6538_name_64(1);
        for (i = 0; i < 30; i++) {
            if (D_801062E8_3E7E08_name_64 == 1) {
                break;
            }
            HuPrcVSleep();
        }
        func_80105940_3E7460_name_64();
        func_801054E8_3E7008_name_64();
        goto done;
    case 1:
        if (D_800FD8A8_FE4A8.lives <= 0) {
            failed = 1;
        }
        D_800FD8A8_FE4A8.lives--;
        func_80104E60_3E6980_name_64();
        if (D_800FD8A8_FE4A8.lives < 0) {
            D_800FD8A8_FE4A8.lives = 0;
        }
        func_80104B60_3E6680_name_64();
        for (i = 0; i < 30; i++) {
            if (D_801062E8_3E7E08_name_64 == 1) {
                break;
            }
            HuPrcVSleep();
        }
    done:
        func_80104CE0_3E6800_name_64();
        show = failed;
        break;
    default:
        show = failed;
        break;
    }
    if (show != 0) {
        func_801057C0_3E72E0_name_64();
    } else {
        D_801062EB_3E7E0B_name_64 = 1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_64_name/3E4350", func_80105AF0_3E7610_name_64);
#endif

/* Whether the minigame's score clears this stage. */
s32 func_80105CCC_3E77EC_name_64(s16 minigame) {
    s32 total;

    total = gPlayers[0].coins_mg_bonus + gPlayers[0].coins_mg;
    switch (minigame) {
    case 0x24:
        if (total < D_80106358_3E7E78_name_64[0][D_800FD8A8_FE4A8.difficulty]) {
            return 0;
        }
        break;
    case 0x47:
        if (total < D_80106358_3E7E78_name_64[1][D_800FD8A8_FE4A8.difficulty]) {
            return 0;
        }
        break;
    case 0x48:
        if (total < D_80106358_3E7E78_name_64[2][D_800FD8A8_FE4A8.difficulty]) {
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

/* Frees the result screen's sprites. */
void func_80105D98_3E78B8_name_64(void) {
    s32 i;
    s32 j;

    SprKill((s16)D_80106410_3E7F30_name_64);
    SprKill((s16)D_8010641C_3E7F3C_name_64);
    for (i = 0; i < 3; i++) {
        SprKill((s16)D_80106460_3E7F80_name_64[i]);
        SprAnimKill((s16)D_80106428_3E7F48_name_64[i]);
    }
    SprAnimKill((s16)D_8010640C_3E7F2C_name_64);
    for (i = 0; i < 2; i++) {
        SprAnimKill((s16)D_80106434_3E7F54_name_64[i]);
        for (j = 0; j < 4; j++) {
            SprAnimKill((s16)D_80106440_3E7F60_name_64[i][j]);
        }
    }
    SprAnimKill((s16)D_80106414_3E7F34_name_64);
    SprAnimKill((s16)D_80106420_3E7F40_name_64);
}

/* The result scene's main process. */
void func_80105EB0_3E79D0_name_64(void) {
    func_80028334_28F34(D_800FD2A6_FDEA6, 2);
    func_80029EDC_2AADC(D_800FD2A6_FDEA6, 1);
    if (func_80105CCC_3E77EC_name_64(GwSystem.chosenMinigameIndex) != 0) {
        D_80106404_3E7F24_name_64 = 0;
        _SetFlag(0x16);
        D_800FD8A8_FE4A8.streak++;
        PlayMusic(0x42);
    } else {
        D_80106404_3E7F24_name_64 = 1;
        _ClearFlag(0x16);
        D_800FD8A8_FE4A8.streak = 0;
        PlayMusic(0x43);
    }
    D_80106406_3E7F26_name_64 = D_800FD8A8_FE4A8.coins;
    D_80106408_3E7F28_name_64 = D_800FD8A8_FE4A8.lives;
    func_80103418_3E4F38_name_64();
    func_80104690_3E61B0_name_64();
    func_80029E80_2AA80(D_800FA618_FB218->obj->model[0], 2, 1);
    func_80029E80_2AA80(((MBModel*)gPlayers[0].unk_24)->obj->model[0], 2, 1);
    func_80029E80_2AA80(((MBModel*)gPlayers[1].unk_24)->obj->model[0], 2, 1);
    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    func_80105AF0_3E7610_name_64();
    HuPrcSleep(30);
    func_800794A8_7A0A8(0x5A);
    InitFadeOut(0, 0x10);
    HuPrcSleep(0x11);
    func_801041DC_3E5CFC_name_64();
    func_8010495C_3E647C_name_64();
    func_80105D98_3E78B8_name_64();
    switch (D_801062EA_3E7E0A_name_64) {
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

/* Scene 3: the result, entered when a minigame returns. */
void func_801060B0_3E7BD0_name_64(void) {
    func_80103270_3E4D90_name_64();
    func_80074DB8_759B8(1);
    omAddPrcObj(func_80105EB0_3E79D0_name_64, 0x1005, 0x1000, 0);
}

/* Scene 4: back on the space after the last stop passed. */
void func_801060EC_3E7C0C_name_64(void) {
    if (func_80075390_75F90(OVL64_FLAG_BASE + 3) != 0) {
        SetPlayerOntoChain(0, 0, 15);
    } else if (func_80075390_75F90(OVL64_FLAG_BASE + 2) != 0) {
        SetPlayerOntoChain(0, 0, 11);
    } else if (func_80075390_75F90(OVL64_FLAG_BASE + 1) != 0) {
        SetPlayerOntoChain(0, 0, 9);
    } else if (func_80075390_75F90(OVL64_FLAG_BASE + 0) != 0) {
        SetPlayerOntoChain(0, 0, 6);
    } else {
        SetPlayerOntoChain(0, 0, 0);
    }
    omOvlReturnEx(1);
}

/* .data (0x3E7CB0-0x3E7E90, 80106190-80106370) */
board_overlay_entrypoint D_80106190_3E7CB0_name_64[6] = {
    { 0, func_801031D0_3E4CF0_name_64 }, { 1, func_80103208_3E4D28_name_64 },
    { 2, func_801032FC_3E4E1C_name_64 }, { 3, func_801060B0_3E7BD0_name_64 },
    { 4, func_801060EC_3E7C0C_name_64 }, { -1, NULL },
};
CoasterSpaceFlag D_801061C0_3E7CE0_name_64[5] = {
    { 0, 9 }, { 1, 10 }, { 2, 11 }, { 3, 12 }, { -1, -1 },
};
s32 D_801061D4_3E7CF4_name_64[6] = { 0x000A010F, 0x000A0110, 0x000A0111, 0x000A0112, 0x000A0113, 0x000A0114 };
s32 D_801061EC_3E7D0C_name_64[6] = { 0x5DA, 0x5DB, 0x5DC, 0x5DD, 0, 0x5E1 };
s32 D_80106204_3E7D24_name_64[3] = { 0x5DE, 0x5DF, 0x5E0 };
s32 D_80106210_3E7D30_name_64[3] = { 0x5D2, 0x5D4, 0x5D6 };
s16 D_8010621C_3E7D3C_name_64[4][2] = { { 0x64, 0x3C }, { 0x64, 0x4E }, { 0x64, 0x60 }, { 0x64, 0x72 } };
s16 D_8010622C_3E7D4C_name_64 = 0xC8;
s16 D_8010622E_3E7D4E_name_64 = 0x3C;
s16 D_80106230_3E7D50_name_64 = 0xC8;
s16 D_80106232_3E7D52_name_64 = 0x4E;
s16 D_80106234_3E7D54_name_64[2] = { 0x18, 0x3C };
BoardEventListEntry D_80106238_3E7D58_name_64[2] = { { 1, 1, func_80103328_3E4E48_name_64 }, { 0, 0, NULL } };
BoardEventListEntry D_80106248_3E7D68_name_64[2] = { { 1, 1, func_8010334C_3E4E6C_name_64 }, { 0, 0, NULL } };
BoardEventListEntry D_80106258_3E7D78_name_64[2] = { { 1, 1, func_80103370_3E4E90_name_64 }, { 0, 0, NULL } };
BoardEventListEntry D_80106268_3E7D88_name_64[2] = { { 1, 1, func_80103394_3E4EB4_name_64 }, { 0, 0, NULL } };
BoardEventListEntry D_80106278_3E7D98_name_64[2] = { { 1, 1, func_801033B8_3E4ED8_name_64 }, { 0, 0, NULL } };
BoardEventListEntry D_80106288_3E7DA8_name_64[2] = { { 1, 1, func_801033F0_3E4F10_name_64 }, { 0, 0, NULL } };
BoardEventTableEntry D_80106298_3E7DB8_name_64[7] = {
    { 0, D_80106238_3E7D58_name_64 }, { 1, D_80106248_3E7D68_name_64 }, { 2, D_80106258_3E7D78_name_64 },
    { 3, D_80106268_3E7D88_name_64 }, { 4, D_80106278_3E7D98_name_64 }, { 0x11, D_80106288_3E7DA8_name_64 },
    { -1, NULL },
};
s32 D_801062D0_3E7DF0_name_64[2][2] = { { 0xD0000, 0xD0001 }, { 0xB00E1, 0xB00E2 } };
s32 D_801062E0_3E7E00_name_64[2] = { 0xD0002, 0xD0003 };
s8 D_801062E8_3E7E08_name_64 = 0;
s8 D_801062E9_3E7E09_name_64 = 0;
s8 D_801062EA_3E7E0A_name_64 = -1;
s8 D_801062EB_3E7E0B_name_64 = 0;
s8 D_801062EC_3E7E0C_name_64 = 0;
s8 D_801062ED_3E7E0D_name_64 = 0; /* padding */
s16 D_801062EE_3E7E0E_name_64 = 0;
s16 D_801062F0_3E7E10_name_64[2][2] = { { 0x50, 0x34 }, { 0x108, 0x34 } };
s16 D_801062F8_3E7E18_name_64[4][4] = {
    { -1000, -1000, -1000, 0 }, { -1000, -1000, -4, 4 }, { -1000, -8, 0, 8 }, { -14, -6, 2, 10 },
};
u8 D_80106318_3E7E38_name_64[8] = { 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0, 0 };
s32 D_80106320_3E7E40_name_64[6] = { 0x20000, 0x30000, 0x70000, 0x40000, 0x50000, 0x60000 };
s16 D_80106338_3E7E58_name_64[4][4] = {
    { -1000, -1000, -1000, 0 }, { -1000, -1000, -4, 4 }, { -1000, -8, 0, 8 }, { -14, -6, 2, 10 },
};
u8 D_80106358_3E7E78_name_64[3][3] = { { 0, 0xA, 0xF }, { 0, 0xA, 0xF }, { 0, 0, 0xF } };
s8 D_80106361_3E7E81_name_64 = 0; /* padding to .rodata */
s8 D_80106362_3E7E82_name_64 = 0;
s8 D_80106363_3E7E83_name_64 = 0;
s32 D_80106364_3E7E84_name_64[3] = { 0, 0, 0 };
