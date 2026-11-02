#include "common.h"
#include "ovl_6C.h"

#define OVL6C_ABS(x) ((x) < 0 ? -(s32)(x) : (x))
/* Waits on a mover: makes it a child of the current process. */
#define OVL6C_LINK(call) do { Process* _p = (call); HuPrcChildLink(HuPrcCurrentGet(), _p); } while (0)

void func_80102830_402730_name_6C(void) {
    CoasterSpaceFlag* entry;

    entry = D_80106590_406490_name_6C;
    while (entry->space >= 0) {
        if (func_80075390_75F90(entry->flag) != 0) {
            BoardSpaceTypeSet(entry->space, 1);
        }
        entry++;
    }
}

s32 func_8010288C_40278C_name_6C(s32 bit) {
    return D_80106740_406640_name_6C.flags[bit / 8] & (1 << (bit % 8));
}

__asm__(".section .rodata");
const char D_801066F0_4065F0_name_6C[] = "%2d";

void func_801028D0_4027D0_name_6C(void) {
    s16 size[2];
    void* data;
    s32 i;
    s32 win;

    D_80106774_406674_name_6C = func_8005E688_5F288(1, 0);
    data = DataRead(D_80106594_406494_name_6C[(s8)D_80106740_406640_name_6C.character]);
    i = 0;
    D_80106774_406674_name_6C->unk0C[0] = SprAnimRead(data);
    SprAnimSet(D_80106774_406674_name_6C->unk0A, 0, D_80106774_406674_name_6C->unk0C[0], 0);
    SprPrioSet(D_80106774_406674_name_6C->unk0A, 0, 0x10);
    SprAttrSet(D_80106774_406674_name_6C->unk0A, 0, 0x1000);
    SprPosSet(D_80106774_406674_name_6C->unk0A, 0, 0x3E, 0x5F);
    DataClose(data);
    D_80106758_406658_name_6C[6] = func_80057480_58080(D_801065F4_4064F4_name_6C[0], D_801065F4_4064F4_name_6C[1], 0x18, 5);
    for (; i < 4; i++) {
        func_8008DACC_8E6CC(1, size, D_801065AC_4064AC_name_6C[i]);
        D_80106758_406658_name_6C[i] = (s16)func_800888A8_894A8(D_801065DC_4064DC_name_6C[i][0], D_801065DC_4064DC_name_6C[i][1], size[0], size[1], 0, 0);
        func_80089B2C_8A72C((s16)D_80106758_406658_name_6C[i], 0);
        func_80089A48_8A648((s16)D_80106758_406658_name_6C[i], 0);
        func_800890CC_89CCC((s16)D_80106758_406658_name_6C[i], (void*)D_801065AC_4064AC_name_6C[i], -1, -1);
    }
    func_8008DACC_8E6CC(1, size, D_801065C4_4064C4_name_6C[D_80106740_406640_name_6C.difficulty]);
    i = 4;
    D_80106758_406658_name_6C[i] = (s16)func_800888A8_894A8(D_801065EC_4064EC_name_6C, D_801065EE_4064EE_name_6C, size[0], size[1], 0, 0);
    func_80089B2C_8A72C((s16)D_80106758_406658_name_6C[i], 0);
    func_80089A48_8A648((s16)D_80106758_406658_name_6C[i], 0);
    func_800890CC_89CCC((s16)D_80106758_406658_name_6C[i], (void*)D_801065C4_4064C4_name_6C[D_80106740_406640_name_6C.difficulty], -1, -1);
    sprintf(D_80106778_406678_name_6C, D_801066F0_4065F0_name_6C, D_80106740_406640_name_6C.chapter);
    func_8008D974_8E574(D_80106778_406678_name_6C, 0);
    sprintf(D_80106780_406680_name_6C, D_801066F0_4065F0_name_6C, D_80106740_406640_name_6C.lives);
    func_8008D974_8E574(D_80106780_406680_name_6C, 1);
    sprintf(D_80106788_406688_name_6C, D_801066F0_4065F0_name_6C, D_80106740_406640_name_6C.coins);
    func_8008D974_8E574(D_80106788_406688_name_6C, 2);
    i = 5;
    func_8008DACC_8E6CC(1, size, D_801065AC_4064AC_name_6C[i]);
    win = func_800888A8_894A8(D_801065F0_4064F0_name_6C, D_801065F2_4064F2_name_6C, size[0], size[1] * 2, 0, 0);
    D_80106758_406658_name_6C[i] = win;
    D_800F920C_F9E0C[win].unk28 = 0x12;
    func_80089B2C_8A72C((s16)D_80106758_406658_name_6C[i], 0);
    func_80089A48_8A648((s16)D_80106758_406658_name_6C[i], 0);
    func_80089308_89F08((s16)D_80106758_406658_name_6C[i], D_80106778_406678_name_6C, 0);
    func_80089308_89F08((s16)D_80106758_406658_name_6C[i], D_80106780_406680_name_6C, 1);
    func_80089308_89F08((s16)D_80106758_406658_name_6C[i], D_80106788_406688_name_6C, 2);
    func_800890CC_89CCC((s16)D_80106758_406658_name_6C[i], (void*)D_801065AC_4064AC_name_6C[i], -1, -1);
}

void func_80102C88_402B88_name_6C(void) {
    s32 i;

    for (i = 0; i < 7; i++) {
        func_8008CCA8_8D8A8((s16)D_80106758_406658_name_6C[i]);
    }
    HuMemDirectFree(D_80106774_406674_name_6C);
}

__asm__(".section .rodata");
const char D_801066F4_4065F4_name_6C[] = "%d";

void func_80102CE4_402BE4_name_6C(void) {
    char buf[8];
    s32 choice;

again:
    {
        sprintf(buf, D_801066F4_4065F4_name_6C, D_800FD8A8_FE4A8.stage + 1);
        MBDlgWinInsertCreateY(0x29, 0x5CD, buf, NULL, NULL, NULL, NULL, 0xAA);
        choice = func_8008BB48_8C748(mbDlgWinId, 0, 1);
        MBDlgWinClose();
        func_80056168_56D68();
        HuPrcVSleep();
        if (choice == 0) {
            func_8007E0C8_7ECC8(&D_80106740_406640_name_6C);
            if (func_8010288C_40278C_name_6C(0) != 0) {
                func_801028D0_4027D0_name_6C();
                sprintf(buf, D_801066F4_4065F4_name_6C, D_80106740_406640_name_6C.stage + 1);
                MBDlgWinInsertCreateY(0x29, 0x5CF, buf, NULL, NULL, NULL, NULL, 0xAA);
                choice = func_8008BB48_8C748(mbDlgWinId, 0, 0);
                MBDlgWinClose();
                func_80056168_56D68();
                HuPrcVSleep();
                func_80102C88_402B88_name_6C();
                if (choice != 0) {
                    goto again;
                }
            }
            func_800753D4_75FD4(0);
            _ClearFlag(0);
            func_8007E018_7EC18();
            func_8007E0C8_7ECC8(&D_80106740_406640_name_6C);
            func_801028D0_4027D0_name_6C();
            MBDlgWinInsertCreateY(0x29, 0x5D0, NULL, NULL, NULL, NULL, NULL, 0xAA);
            choice = func_8008BB48_8C748(mbDlgWinId, 0, 1);
            MBDlgWinClose();
            func_80056168_56D68();
            func_80102C88_402B88_name_6C();
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
    MBDlgWinExecY(0x29, D_801065D0_4064D0_name_6C[D_800FD8A8_FE4A8.difficulty], 0xAA);
}

void func_801030B8_402FB8_name_6C(s32 sign) {
    s16 size[2];
    s32 win;
    s32 name;

    if (func_80075390_75F90(sign + OVL6C_FLAG_BASE) == 0) {
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

void func_801031D0_4030D0_name_6C(void) {
    D_800FD8A8_FE4A8.stage = OVL6C_STAGE;
    omInitObjMan(10, 0);
    omOvlGotoEx(OVL6C_NEXT_SCENE, OVL6C_NEXT_ENTRY, 0x192);
}

/* Scene 1: back at the start; the chain depends on the difficulty. */
void func_8010320C_40310C_name_6C(void) {
    omInitObjMan(10, 0);
    switch (D_800FD8A8_FE4A8.difficulty) {
    case 0:
        SetPlayerOntoChain(0, 1, 0);
        break;
    case 1:
        SetPlayerOntoChain(0, 2, 0);
        break;
    case 2:
        SetPlayerOntoChain(0, 0, 0);
        break;
    }
    func_800753D4_75FD4(0x32);
    func_80073410_74010(-1);
    omOvlReturnEx(1);
}

/* The board's common setup, plus the goal marker and its pointer. */
void func_801032A0_4031A0_name_6C(void) {
    omInitObjMan(0x50, 0x28);
    func_80020070_20C70(2);
    func_80026D28_27928(1);
    func_80026DAC_279AC(0, 0x78, 0x78, 0x78);
    func_80026DAC_279AC(1, 0x40, 0x40, 0x60);
    func_80026E00_27A00(1, -100.0f, 100.0f, 300.0f);
    func_80074154_74D54(OVL6C_BOARD_MODEL, OVL6C_BOARD_FILE);
    EventTableHydrate(D_80106634_406534_name_6C);
    func_80102830_402730_name_6C();
    func_801033B8_4032B8_name_6C();
    func_801034B8_4033B8_name_6C();
}

/* NON_MATCHING: control flow (class 3). Retail merges the three PlayMusic calls into one tail and skips it for
   other difficulties; every call and constant agrees. Stays asm in the matching build. */
#ifdef NON_MATCHING
void func_8010333C_40323C_name_6C(void) {
    func_801032A0_4031A0_name_6C();
    func_80074DB8_759B8(0);
    switch (D_800FD8A8_FE4A8.difficulty) {
    case 0:
        PlayMusic(0x4A);
        break;
    case 1:
        PlayMusic(0x4D);
        break;
    case 2:
        if (func_80075390_75F90(8) != 0) {
            PlayMusic(0x3D);
        } else {
            PlayMusic(0x4F);
        }
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6C_name/402730", func_8010333C_40323C_name_6C);
#endif

/* The goal marker (model 0xA7), put on the space of this difficulty. */
void func_801033B8_4032B8_name_6C(void) {
    MBModel* obj;

    obj = func_80043510_44110(0xA7, NULL);
    func_80043DAC_449AC(obj);
    D_80106790_406690_name_6C = obj;
    obj->attr |= 2;
    func_800B3170_B3D70(&obj->pos, &GetSpaceData(D_801065F8_4064F8_name_6C[D_800FD8A8_FE4A8.difficulty])->coords);
}

/* NON_MATCHING: register scheduling: retail forms the slot address (sll/lui/addiu) before the sra of the index;
   same calls, stores and fields. Stays asm in the matching build. */
#ifdef NON_MATCHING
/* Slot idx of the pointer models: made once (model 0xAE, clipped). */
void func_80103428_403328_name_6C(s16 idx) {
    MBModel** slot;
    MBModel* obj;

    slot = D_80106794_406694_name_6C + idx;
    if (*slot == NULL) {
        obj = func_80043510_44110(0xAE, NULL);
        func_800298A4_2A4A4(obj->obj->model[0], 0x80000, 0x80000);
        func_80029A8C_2A68C(obj->obj->model[0]);
        func_80043DAC_449AC(obj);
        *slot = obj;
        obj->attr |= 2;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6C_name/402730", func_80103428_403328_name_6C);
#endif

void func_801034B8_4033B8_name_6C(void) {
    s32 i;

    for (i = 0; i < 1; i++) {
        D_80106794_406694_name_6C[i] = NULL;
        func_80103428_403328_name_6C(i);
    }
}

void func_8010350C_40340C_name_6C(void) {
    func_80073410_74010(-2);
    func_80102CE4_402BE4_name_6C();
}

__asm__(".section .rodata");
const double D_801066F8_4065F8_name_6C = -90.0;
__asm__(".text");

/* Event: with the flags 5 and 8 set the scene is left for 0x6D; otherwise the player walks the path
   D_80106610 (a mover and a turn per space, the model tilted to the climb), then stands on chain 3. */
void func_80103530_403430_name_6C(void) {
    Vec dir;
    MBModel* mdl;
    Vec* to;
    s16* path;
    s32 i;
    f32 div;

    if (func_80075390_75F90(5) != 0) {
        if (func_80075390_75F90(8) != 0) {
            func_80074F7C_75B7C(0x6D, 0, 2, 0);
        } else {
            func_80074F7C_75B7C(0x6D, 0, 2, 1);
        }
        return;
    }
    mdl = D_800FA618_FB218;
    i = 0;
    MBMotionShiftSet(D_800FA618_FB218, 0, (s16)func_80029CE4_2A8E4(mdl->obj->model[0]), 1, 6);
    path = D_80106610_406510_name_6C;
    do {
        to = &GetSpaceData(path[i])->coords;
        div = 3.8f - i / 5.0f;
        OVL6C_LINK(func_80056FD4_57BD4(&mdl->pos, to, &mdl->pos, div));
        func_80056658_57258(to, &mdl->pos, &dir);
        func_80056B78_57778(&mdl->rot, &dir, &mdl->rot, (s32)((s32)HuVecDistance(&mdl->pos, to) / div));
        func_800B3870_B4470(D_800FC834_FD434[*mdl->obj->model].mtx,
                            (f32)(func_800B727C_B7E7C(func_800B1830_B2430(dir.x * dir.x + dir.z * dir.z), dir.y) + D_801066F8_4065F8_name_6C));
        HuPrcChildWatch();
        i++;
    } while (path[i] != -1);
    MBMotionShiftSet(D_800FA618_FB218, -1, (s16)func_80029CE4_2A8E4(D_800FA618_FB218->obj->model[0]), 1, 2);
    func_80054C78_55878(3, &gPlayers[0].cur_chain_index, &gPlayers[0].cur_space_index);
    gPlayers[0].next_chain_index = gPlayers[0].cur_chain_index;
    gPlayers[0].next_space_index = gPlayers[0].cur_space_index + 1;
    PlaySound(0x371);
    func_8010350C_40340C_name_6C();
}

#ifdef NON_MATCHING
void func_80103808_403708_name_6C(void) {
    s16 cnt[4];
    s16 digits[2][4];
    s16 val[2];
    s32 spr;
    s16 i;
    s16 j;
    s16 k;
    s32 file;
    void* data;

    D_80106798_406698_name_6C = (s16)func_800888A8_894A8(0, 0, 0x140, 0xF0, 0, 4);
    func_80089B2C_8A72C((s16)D_80106798_406698_name_6C, 0xC8);
    func_8008D530_8E130((s16)D_80106798_406698_name_6C, 0, 0, 0);
    D_801067A8_4066A8_name_6C = SprCreate(3, 5);
    SprPosSet((s16)D_801067A8_4066A8_name_6C, 0, 0, 0);
    data = DataRead(D_8010665C_40655C_name_6C[D_8010679C_40669C_name_6C][0]);
    i = 0;
    D_801067AC_4066AC_name_6C = SprAnimRead(data);
    DataClose(data);
    SprAnimSet((s16)D_801067A8_4066A8_name_6C, 1, (s16)D_801067AC_4066AC_name_6C, 0);
    func_8008225C_82E5C((s16)D_801067A8_4066A8_name_6C, 1, 1);
    SprPrioSet((s16)D_801067A8_4066A8_name_6C, 1, 0x10);
    SprAttrSet((s16)D_801067A8_4066A8_name_6C, 1, 0x9000);
    SprPosSet((s16)D_801067A8_4066A8_name_6C, 1, 0xA0, 0xAA);
    func_8008221C_82E1C((s16)D_801067A8_4066A8_name_6C, 1, 0.0f);
    D_801067B4_4066B4_name_6C = SprCreate(3, 5);
    SprPosSet((s16)D_801067B4_4066B4_name_6C, 0, 0, 0);
    data = DataRead(D_8010666C_40656C_name_6C[0]);
    D_801067B8_4066B8_name_6C = SprAnimRead(data);
    DataClose(data);
    SprAnimSet((s16)D_801067B4_4066B4_name_6C, 1, (s16)D_801067B8_4066B8_name_6C, 0);
    func_8008225C_82E5C((s16)D_801067B4_4066B4_name_6C, 1, 1);
    SprPrioSet((s16)D_801067B4_4066B4_name_6C, 1, 0x10);
    SprAttrSet((s16)D_801067B4_4066B4_name_6C, 1, 0x9000);
    SprPosSet((s16)D_801067B4_4066B4_name_6C, 1, 0xA0, 0xA0);
    func_8008221C_82E1C((s16)D_801067A8_4066A8_name_6C, 1, 0.0f);
    val[0] = D_800FD8A8_FE4A8.lives - D_801067A0_4066A0_name_6C;
    val[1] = gPlayers[0].coins_mg_bonus + gPlayers[0].coins_mg;
    for (; i < 2; i++) {
        digits[i][0] = OVL6C_ABS(val[i]) / 1000;
        digits[i][1] = (OVL6C_ABS(val[i]) - digits[i][0] * 1000) / 100;
        digits[i][2] = (OVL6C_ABS(val[i]) - digits[i][0] * 1000 - digits[i][1] * 100) / 10;
        digits[i][3] = OVL6C_ABS(val[i]) - digits[i][0] * 1000 - digits[i][1] * 100 - digits[i][2] * 10;
        cnt[i] = 0;
        if (OVL6C_ABS(val[i]) >= 10) {
            cnt[i] = 1;
        }
        if (OVL6C_ABS(val[i]) >= 100) {
            cnt[i] = 2;
        }
        if (OVL6C_ABS(val[i]) >= 1000) {
            cnt[i] = 3;
        }
    }
    for (i = 0; i < 2; i++) {
        j = 0;
        spr = SprCreate(7, 5);
        D_801067F8_4066F8_name_6C[i] = spr;
        if (i == 0 || val[i] < 0) {
            file = 0xD0004;
        } else {
            file = 0xD0005;
        }
        data = DataRead(file);
        D_801067C0_4066C0_name_6C[i] = SprAnimRead(data);
        DataClose(data);
        SprAnimSet(spr, j, (s16)D_801067C0_4066C0_name_6C[i], 0);
        func_800824F4_830F4(spr, j, -1);
        SprAttrSet(spr, j, 0x8000);
        SprPosSet(spr, j, D_8010667C_40657C_name_6C[i][0], D_8010667C_40657C_name_6C[i][1]);
        j++;
        SprAnimSet(spr, j, (s16)D_801067C0_4066C0_name_6C[i], 0);
        func_8008225C_82E5C(spr, j, 1);
        SprPrioSet(spr, j, 0xF);
        SprAttrSet(spr, j, 0x9000);
        SprPosSet(spr, j, 0, 0);
        func_800824F4_830F4(spr, j, 0);
        j++;
        for (k = 0; k < 4; k++, j++) {
            data = DataRead(0xC000D);
            D_801067D8_4066D8_name_6C[i][k] = SprAnimRead(data);
            DataClose(data);
            SprAnimSet(spr, j, (s16)D_801067D8_4066D8_name_6C[i][k], 0);
            func_8008225C_82E5C(spr, j, 1);
            SprPrioSet(spr, j, 0xE);
            SprAttrSet(spr, j, 0x9000);
            func_800822A8_82EA8(spr, j, digits[i][k], 0);
            func_800824F4_830F4(spr, j, 0);
            func_8008221C_82E1C(spr, j, 0.0f);
            if (i == 0) {
                if (val[i] == 0) {
                    SprPosSet(spr, j, D_80106684_406584_name_6C[cnt[i]][k], 2);
                } else {
                    SprPosSet(spr, j, D_80106684_406584_name_6C[cnt[i]][k] + 4, 2);
                }
            } else if (D_8010679C_40669C_name_6C == 0) {
                if (val[i] == 0) {
                    SprPosSet(spr, j, D_80106684_406584_name_6C[cnt[i]][k], 2);
                } else {
                    SprPosSet(spr, j, D_80106684_406584_name_6C[cnt[i]][k] + 4, 2);
                }
            } else {
                func_80082450_83050(spr, j, 0xFF, 0, 0);
                SprPosSet(spr, j, D_80106684_406584_name_6C[cnt[i]][k], 2);
            }
        }
        data = DataRead(0xC000D);
        D_801067CC_4066CC_name_6C[i] = SprAnimRead(data);
        DataClose(data);
        SprAnimSet(spr, j, (s16)D_801067CC_4066CC_name_6C[i], 0);
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
                SprPosSet(spr, j, D_80106684_406584_name_6C[cnt[i]][3 - cnt[i]] - 4, 2);
            }
        } else if (D_8010679C_40669C_name_6C == 0 && val[i] != 0) {
            if (val[i] > 0) {
                func_800822A8_82EA8(spr, j, 11, 0);
            } else {
                func_800822A8_82EA8(spr, j, 12, 0);
            }
            SprPosSet(spr, j, D_80106684_406584_name_6C[cnt[i]][3 - cnt[i]] - 4, 2);
        } else {
            SprPosSet(spr, j, -1000, 2);
            func_800822A8_82EA8(spr, j, 10, 0);
        }
    }
    spr = SprCreate(7, 5);
    D_801067F8_4066F8_name_6C[2] = spr;
    data = DataRead(0xD0005);
    D_801067C0_4066C0_name_6C[2] = SprAnimRead(data);
    DataClose(data);
    SprAnimSet(spr, 0, (s16)D_801067C0_4066C0_name_6C[2], 0);
    func_800824F4_830F4(spr, 0, -1);
    SprAttrSet(spr, 0, 0x8000);
    SprPosSet(spr, 0, D_8010667C_40657C_name_6C[0][0], D_8010667C_40657C_name_6C[0][1]);
    SprAnimSet(spr, 1, (s16)D_801067C0_4066C0_name_6C[2], 0);
    func_8008225C_82E5C(spr, 1, 1);
    SprPrioSet(spr, 1, 0xF);
    SprAttrSet(spr, 1, 0x9000);
    SprPosSet(spr, 1, 0, 0);
    func_800824F4_830F4(spr, 1, 0);
    data = DataRead(0xD0006);
    D_801067A4_4066A4_name_6C = SprAnimRead(data);
    DataClose(data);
    SprAnimSet(spr, 2, (s16)D_801067A4_4066A4_name_6C, 0);
    func_8008225C_82E5C(spr, 2, 1);
    SprPrioSet(spr, 2, 0xE);
    SprAttrSet(spr, 2, 0x9000);
    func_800824F4_830F4(spr, 2, 0);
    SprPosSet(spr, 2, 0, 2);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6C_name/402730", func_80103808_403708_name_6C);
#endif

void func_801045CC_4044CC_name_6C(void) {
    func_8008CCA8_8D8A8((s16)D_80106798_406698_name_6C);
}

void func_801045EC_4044EC_name_6C(void) {
    Hu3DCamSetPerspective(1, 40.0f, 200.0f, 8000.0f);
    Hu3DCamSetPositionOrientation(1, &D_80106804_406704_name_6C, &D_80106810_406710_name_6C, &D_8010681C_40671C_name_6C);
    Hu3DCamUpdateMtx(1);
    CameraViewportSet(1, &D_80106828_406728_name_6C, &D_80106834_406734_name_6C);
}

void func_80104654_404554_name_6C(void) {
    while (1) {
        func_801045EC_4044EC_name_6C();
        HuPrcVSleep();
    }
}

__asm__(".section .rodata");
const char D_80106700_406600_name_6C[] = "point1";

__asm__(".section .rodata");
const char D_80106708_406608_name_6C[] = "point2";

void func_80104680_404580_name_6C(void) {
    Vec v;

    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    HuVecCopyXYZ(&v, 0.0f, 0.0f, 0.0f);
    OVL6C_LINK(func_80056D80_57980(&D_80106850_406750_name_6C->pos, &v, &D_80106850_406750_name_6C->pos, 20));
    HuPrcChildWatch();
    func_80029E80_2AA80(D_80106850_406750_name_6C->obj->model[0], 2, 1);
    HuVecCopyXYZ(&D_80106848_406748_name_6C->pos, -6.278950214385986f, 19.16754913330078f, 0.0f);
    HuVecCopyXYZ(&D_8010684C_40674C_name_6C->pos, 5.623000144958496f, 19.16754913330078f, 0.0f);
    HuPrcVSleep();
    func_8005AA98_5B698(D_80106848_406748_name_6C->obj->model[0]);
    func_8005AA98_5B698(D_8010684C_40674C_name_6C->obj->model[0]);
    HuPrcVSleep();
    func_8005670C_5730C(&v);
    OVL6C_LINK(func_80056B78_57778(&D_80106848_406748_name_6C->rot, &v, &D_80106848_406748_name_6C->rot, 10));
    OVL6C_LINK(func_80056B78_57778(&D_8010684C_40674C_name_6C->rot, &v, &D_8010684C_40674C_name_6C->rot, 10));
    HuPrcChildWatch();
    if (D_8010679C_40669C_name_6C == 0) {
        MBMotionSet(D_80106848_406748_name_6C, 6, 0);
        MBMotionSet(D_8010684C_40674C_name_6C, 6, 0);
        func_800732B0_73EB0(D_801066AC_4065AC_name_6C[(s8)D_800FD8A8_FE4A8.character] | 0x54);
    } else {
        MBMotionSet(D_80106848_406748_name_6C, 3, 0);
        MBMotionSet(D_8010684C_40674C_name_6C, 3, 0);
    }
    while (1) {
        if (D_80106678_406578_name_6C != 0) {
            MBMotionSet(D_80106848_406748_name_6C, 5, 0);
            MBMotionSet(D_8010684C_40674C_name_6C, 5, 0);
            HuPrcSleep(30);
            break;
        }
        if (D_80106677_406577_name_6C != 0) {
            break;
        }
        HuPrcVSleep();
    }
    MBMotionShiftSet(D_80106848_406748_name_6C, -1, 0, 10, 2);
    MBMotionShiftSet(D_8010684C_40674C_name_6C, -1, 0, 10, 2);
    HuVecCopyXYZ(&v, -1.0f, 0.0f, 0.0f);
    OVL6C_LINK(func_80056B78_57778(&D_80106848_406748_name_6C->rot, &v, &D_80106848_406748_name_6C->rot, 10));
    OVL6C_LINK(func_80056B78_57778(&D_8010684C_40674C_name_6C->rot, &v, &D_8010684C_40674C_name_6C->rot, 10));
    HuPrcChildWatch();
    func_8005AA48_5B648(D_80106850_406750_name_6C, D_80106700_406600_name_6C, D_80106848_406748_name_6C->obj->model[0]);
    func_8005AA48_5B648(D_80106850_406750_name_6C, D_80106708_406608_name_6C, D_8010684C_40674C_name_6C->obj->model[0]);
    func_80029E80_2AA80(D_80106850_406750_name_6C->obj->model[0], 1, 2);
    HuVecCopyXYZ(&v, -100.0f, 0.0f, 0.0f);
    OVL6C_LINK(func_80056D80_57980(&D_80106850_406750_name_6C->pos, &v, &D_80106850_406750_name_6C->pos, 20));
    HuPrcChildWatch();
    while (1) {
        HuPrcVSleep();
    }
}

void func_80104A80_404980_name_6C(void) {
    D_80106840_406740_name_6C = omAddPrcObj(func_80104654_404554_name_6C, 0x4000, 0, 0);
    D_80106804_406704_name_6C.x = 0.0f;
    D_80106804_406704_name_6C.y = 250.0f;
    D_80106804_406704_name_6C.z = 200.0f;
    D_80106810_406710_name_6C.x = 0.0f;
    D_80106810_406710_name_6C.y = 0.0f;
    D_80106810_406710_name_6C.z = 0.0f;
    D_8010681C_40671C_name_6C.x = 0.0f;
    D_8010681C_40671C_name_6C.y = 1.0f;
    D_8010681C_40671C_name_6C.z = 0.0f;
    D_80106828_406728_name_6C.x = 1280.0f;
    D_80106828_406728_name_6C.y = 960.0f;
    D_80106828_406728_name_6C.z = 511.0f;
    D_80106834_406734_name_6C.x = 640.0f;
    D_80106834_406734_name_6C.y = 480.0f;
    D_80106834_406734_name_6C.z = 511.5f;
    func_801045EC_4044EC_name_6C();
    D_80106850_406750_name_6C = func_80043510_44110(0xAA, NULL);
    HuVecCopyXYZ(&D_80106850_406750_name_6C->rot, -1.0f, 0.0f, 0.0f);
    HuVecCopyXYZ(&D_80106850_406750_name_6C->pos, 100.0f, 0.0f, 0.0f);
    D_80106850_406750_name_6C->attr |= 1;
    func_80029EDC_2AADC(D_80106850_406750_name_6C->obj->model[0], 2);
    D_80106848_406748_name_6C = func_80043510_44110(D_801066A4_4065A4_name_6C[(s8)D_800FD8A8_FE4A8.character], D_800CC8B8_CD4B8[(s8)D_800FD8A8_FE4A8.character]);
    HuVecCopyXYZ(&D_80106848_406748_name_6C->rot, -1.0f, 0.0f, 0.0f);
    D_80106848_406748_name_6C->attr |= 1;
    func_80029EDC_2AADC(D_80106848_406748_name_6C->obj->model[0], 2);
    D_8010684C_40674C_name_6C = func_80043510_44110(D_801066A4_4065A4_name_6C[(s8)D_800FD8A8_FE4A8.character2], D_800CC8B8_CD4B8[(s8)D_800FD8A8_FE4A8.character2]);
    HuVecCopyXYZ(&D_8010684C_40674C_name_6C->rot, -1.0f, 0.0f, 0.0f);
    D_8010684C_40674C_name_6C->attr |= 1;
    func_80029EDC_2AADC(D_8010684C_40674C_name_6C->obj->model[0], 2);
    func_8005AA48_5B648(D_80106850_406750_name_6C, D_80106700_406600_name_6C, D_80106848_406748_name_6C->obj->model[0]);
    func_8005AA48_5B648(D_80106850_406750_name_6C, D_80106708_406608_name_6C, D_8010684C_40674C_name_6C->obj->model[0]);
    D_80106844_406744_name_6C = omAddPrcObj(func_80104680_404580_name_6C, 0x4000, 0, 0);
}

void func_80104D4C_404C4C_name_6C(void) {
    omDelPrcObj(D_80106840_406740_name_6C);
    omDelPrcObj(D_80106844_406744_name_6C);
    MBModelKill(D_80106848_406748_name_6C);
    MBModelKill(D_8010684C_40674C_name_6C);
    MBModelKill(D_80106850_406750_name_6C);
}

void func_80104D9C_404C9C_name_6C(void) {
    switch (D_8010679C_40669C_name_6C) {
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

void func_80104E08_404D08_name_6C(s8 idx) {
    f32 scale;
    s32 i;
    s32 n = idx;

    i = 0;
    do {
        i++;
        SprAttrReset((s16)D_801067F8_4066F8_name_6C[n], i, 0x8000);
    } while (i < 6);
    for (scale = 0.0f; scale < 1.0; scale += 0.3) {
        i = 0;
        do {
            i++;
            SprScaleSet((s16)D_801067F8_4066F8_name_6C[n], i, scale, scale);
        } while (i < 6);
        if (D_80106674_406574_name_6C == 0) {
            HuPrcVSleep();
        }
    }
    i = 0;
    do {
        i++;
        SprScaleSet((s16)D_801067F8_4066F8_name_6C[n], i, 1.0f, 1.0f);
    } while (i < 6);
}

void func_80104F50_404E50_name_6C(void) {
    f32 scale;
    s32 i;

    i = 0;
    do {
        i++;
        SprAttrReset((s16)D_801067F8_4066F8_name_6C[0], i, 0x8000);
        SprAttrReset((s16)D_801067F8_4066F8_name_6C[1], i, 0x8000);
    } while (i < 6);
    for (scale = 0.0f; scale < 1.0; scale += 0.3) {
        i = 0;
        do {
            i++;
            SprScaleSet((s16)D_801067F8_4066F8_name_6C[0], i, scale, scale);
            SprScaleSet((s16)D_801067F8_4066F8_name_6C[1], i, scale, scale);
        } while (i < 6);
        if (D_80106674_406574_name_6C == 0) {
            HuPrcVSleep();
        }
    }
    i = 0;
    do {
        i++;
        SprScaleSet((s16)D_801067F8_4066F8_name_6C[0], i, 1.0f, 1.0f);
        SprScaleSet((s16)D_801067F8_4066F8_name_6C[1], i, 1.0f, 1.0f);
    } while (i < 6);
}

void func_801050D0_404FD0_name_6C(void) {
    f32 scale;
    s32 i;

    i = 0;
    do {
        i++;
        SprScaleSet((s16)D_801067F8_4066F8_name_6C[0], i, 1.0f, 1.0f);
        SprScaleSet((s16)D_801067F8_4066F8_name_6C[1], i, 1.0f, 1.0f);
    } while (i < 6);
    scale = 1.0f;
    do {
        i = 0;
        do {
            i++;
            SprScaleSet((s16)D_801067F8_4066F8_name_6C[0], i, scale, scale);
            SprScaleSet((s16)D_801067F8_4066F8_name_6C[1], i, scale, scale);
        } while (i < 6);
        if (D_80106674_406574_name_6C == 0) {
            HuPrcVSleep();
        }
        scale -= 0.3f;
    } while (scale > 0.0f);
    i = 0;
    do {
        i++;
        SprAttrSet((s16)D_801067F8_4066F8_name_6C[0], i, 0x8000);
        SprAttrSet((s16)D_801067F8_4066F8_name_6C[1], i, 0x8000);
    } while (i < 6);
}

#ifdef NON_MATCHING
void func_80105250_405150_name_6C(void) {
    s16 val[4];
    s16 cnt[4];
    s16 digits[4][4];
    s32 i;
    s32 k;
    s32 j;

    val[0] = D_800FD8A8_FE4A8.lives - D_801067A0_4066A0_name_6C;
    if (D_800FD8A8_FE4A8.streak > 0) {
        val[1] = (gPlayers[0].coins_mg + gPlayers[0].coins_mg_bonus) * D_800FD8A8_FE4A8.streak - D_8010667A_40657A_name_6C;
    } else {
        val[1] = gPlayers[0].coins_mg + gPlayers[0].coins_mg_bonus - D_8010667A_40657A_name_6C;
    }
    for (i = 0; i < 2; i++) {
        digits[i][0] = OVL6C_ABS(val[i]) / 1000;
        digits[i][1] = (OVL6C_ABS(val[i]) - digits[i][0] * 1000) / 100;
        digits[i][2] = (OVL6C_ABS(val[i]) - digits[i][0] * 1000 - digits[i][1] * 100) / 10;
        digits[i][3] = OVL6C_ABS(val[i]) - digits[i][0] * 1000 - digits[i][1] * 100 - digits[i][2] * 10;
        cnt[i] = 0;
        if (OVL6C_ABS(val[i]) >= 10) {
            cnt[i] = 1;
        }
        if (OVL6C_ABS(val[i]) >= 100) {
            cnt[i] = 2;
        }
        if (OVL6C_ABS(val[i]) >= 1000) {
            cnt[i] = 3;
        }
    }
    for (i = 0; i < 2; i++) {
        j = 2;
        for (k = 0; k < 4; k++, j++) {
            func_800822A8_82EA8((s16)D_801067F8_4066F8_name_6C[i], j, digits[i][k], 0);
            if (i == 0) {
                if (val[i] == 0) {
                    SprPosSet((s16)D_801067F8_4066F8_name_6C[i], j, D_801066C4_4065C4_name_6C[cnt[i]][k], 2);
                } else {
                    SprPosSet((s16)D_801067F8_4066F8_name_6C[i], j, D_801066C4_4065C4_name_6C[cnt[i]][k] + 4, 2);
                }
            } else if (D_8010679C_40669C_name_6C == 0 && val[i] != 0) {
                SprPosSet((s16)D_801067F8_4066F8_name_6C[i], j, D_801066C4_4065C4_name_6C[cnt[i]][k] + 4, 2);
            } else {
                SprPosSet((s16)D_801067F8_4066F8_name_6C[i], j, D_801066C4_4065C4_name_6C[cnt[i]][k], 2);
            }
        }
        if (i == 0) {
            if (val[i] == 0) {
                SprPosSet((s16)D_801067F8_4066F8_name_6C[i], j, -1000, -2);
                func_800822A8_82EA8((s16)D_801067F8_4066F8_name_6C[i], j, 10, 0);
            } else {
                if (val[i] > 0) {
                    func_800822A8_82EA8((s16)D_801067F8_4066F8_name_6C[i], j, 11, 0);
                } else {
                    func_800822A8_82EA8((s16)D_801067F8_4066F8_name_6C[i], j, 12, 0);
                }
                SprPosSet((s16)D_801067F8_4066F8_name_6C[i], j, D_801066C4_4065C4_name_6C[cnt[i]][3 - cnt[i]] - 4, 2);
            }
        } else if (D_8010679C_40669C_name_6C == 0 && val[i] != 0) {
            if (val[i] > 0) {
                func_800822A8_82EA8((s16)D_801067F8_4066F8_name_6C[i], j, 11, 0);
            } else {
                func_800822A8_82EA8((s16)D_801067F8_4066F8_name_6C[i], j, 12, 0);
            }
            SprPosSet((s16)D_801067F8_4066F8_name_6C[i], j, D_801066C4_4065C4_name_6C[cnt[i]][3 - cnt[i]] - 4, 2);
        } else {
            SprPosSet((s16)D_801067F8_4066F8_name_6C[i], j, -1000, -2);
            func_800822A8_82EA8((s16)D_801067F8_4066F8_name_6C[i], j, 10, 0);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6C_name/402730", func_80105250_405150_name_6C);
#endif

void func_801058D8_4057D8_name_6C(void) {
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
    while ((s16)coins > D_8010667A_40657A_name_6C) {
        D_8010667A_40657A_name_6C += step;
        if ((s16)coins <= D_8010667A_40657A_name_6C) {
            D_800FD8A8_FE4A8.coins += step - ((u8)D_8010667A_40657A_name_6C - coins);
            D_8010667A_40657A_name_6C = coins;
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
                func_80104E08_404D08_name_6C(2);
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
        func_80105250_405150_name_6C();
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
            func_80104E08_404D08_name_6C(2);
        }
    }
    func_80105250_405150_name_6C();
}

void func_80105BB0_405AB0_name_6C(void) {
    s16 size[2];
    s32 win;
    s8 choice;

    SprAttrSet((s16)D_801067A8_4066A8_name_6C, 1, 0x8000);
    HuPrcSleep(30);
    PlayMusic(0x14);
    SprAttrReset((s16)D_801067B4_4066B4_name_6C, 1, 0x8000);
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
        D_80106678_406578_name_6C = 1;
        HuPrcSleep(30);
    }
    D_80106676_406576_name_6C = choice;
    D_80106675_406575_name_6C = 1;
}

void func_80105D30_405C30_name_6C(void) {
    s16 size[2];
    char buf[8];
    GAMEMES mesX;
    GAMEMES mesN;
    s16 win;

    if (D_800FD8A8_FE4A8.streak >= 2) {
        sprintf(buf, D_801066F4_4065F4_name_6C, D_800FD8A8_FE4A8.streak);
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
        func_80105250_405150_name_6C();
        PlaySound(0x33D);
        HuPrcSleep(0x19);
    }
}

#ifdef NON_MATCHING
void func_80105EE0_405DE0_name_6C(void) {
    s16 i;
    s32 show;
    s32 failed;

    switch (D_8010679C_40669C_name_6C) {
    case 0:
        HuPrcSleep(0x24);
        func_80079428_7A028(0x44);
        break;
    case 1:
        HuPrcSleep(0x24);
        func_80079428_7A028(0x45);
        break;
    }
    SprAttrReset((s16)D_801067A8_4066A8_name_6C, 1, 0x8000);
    omAddPrcObj(func_80104D9C_404C9C_name_6C, 0x300, 0x2500, 0);
    HuPrcSleep(0x3C);
    if (D_8010679C_40669C_name_6C == 0) {
        HuPrcSleep(30);
    } else {
        HuPrcSleep(20);
    }
    failed = 0;
    switch (D_8010679C_40669C_name_6C) {
    case 0:
        func_80104E08_404D08_name_6C(1);
        for (i = 0; i < 30; i++) {
            if (D_80106674_406574_name_6C == 1) {
                break;
            }
            HuPrcVSleep();
        }
        func_80105D30_405C30_name_6C();
        func_801058D8_4057D8_name_6C();
        goto done;
    case 1:
        if (D_800FD8A8_FE4A8.lives <= 0) {
            failed = 1;
        }
        D_800FD8A8_FE4A8.lives--;
        func_80105250_405150_name_6C();
        if (D_800FD8A8_FE4A8.lives < 0) {
            D_800FD8A8_FE4A8.lives = 0;
        }
        func_80104F50_404E50_name_6C();
        for (i = 0; i < 30; i++) {
            if (D_80106674_406574_name_6C == 1) {
                break;
            }
            HuPrcVSleep();
        }
    done:
        func_801050D0_404FD0_name_6C();
        show = failed;
        break;
    default:
        show = failed;
        break;
    }
    if (show != 0) {
        func_80105BB0_405AB0_name_6C();
    } else {
        D_80106677_406577_name_6C = 1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_6C_name/402730", func_80105EE0_405DE0_name_6C);
#endif

s32 func_801060BC_405FBC_name_6C(s16 minigame) {
    s32 total;

    total = gPlayers[0].coins_mg_bonus + gPlayers[0].coins_mg;
    switch (minigame) {
    case 0x24:
        if (total < D_801066E4_4065E4_name_6C[0][D_800FD8A8_FE4A8.difficulty]) {
            return 0;
        }
        break;
    case 0x47:
        if (total < D_801066E4_4065E4_name_6C[1][D_800FD8A8_FE4A8.difficulty]) {
            return 0;
        }
        break;
    case 0x48:
        if (total < D_801066E4_4065E4_name_6C[2][D_800FD8A8_FE4A8.difficulty]) {
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

void func_80106188_406088_name_6C(void) {
    s32 i;
    s32 j;

    SprKill((s16)D_801067A8_4066A8_name_6C);
    SprKill((s16)D_801067B4_4066B4_name_6C);
    for (i = 0; i < 3; i++) {
        SprKill((s16)D_801067F8_4066F8_name_6C[i]);
        SprAnimKill((s16)D_801067C0_4066C0_name_6C[i]);
    }
    SprAnimKill((s16)D_801067A4_4066A4_name_6C);
    for (i = 0; i < 2; i++) {
        SprAnimKill((s16)D_801067CC_4066CC_name_6C[i]);
        for (j = 0; j < 4; j++) {
            SprAnimKill((s16)D_801067D8_4066D8_name_6C[i][j]);
        }
    }
    SprAnimKill((s16)D_801067AC_4066AC_name_6C);
    SprAnimKill((s16)D_801067B8_4066B8_name_6C);
}

void func_801062A0_4061A0_name_6C(void) {
    func_80028334_28F34(D_800FD2A6_FDEA6, 2);
    func_80029EDC_2AADC(D_800FD2A6_FDEA6, 1);
    if (func_801060BC_405FBC_name_6C(GwSystem.chosenMinigameIndex) != 0) {
        D_8010679C_40669C_name_6C = 0;
        _SetFlag(0x16);
        D_800FD8A8_FE4A8.streak++;
        PlayMusic(0x42);
    } else {
        D_8010679C_40669C_name_6C = 1;
        _ClearFlag(0x16);
        D_800FD8A8_FE4A8.streak = 0;
        PlayMusic(0x43);
    }
    D_8010679E_40669E_name_6C = D_800FD8A8_FE4A8.coins;
    D_801067A0_4066A0_name_6C = D_800FD8A8_FE4A8.lives;
    func_80103808_403708_name_6C();
    func_80104A80_404980_name_6C();
    func_80029E80_2AA80(D_800FA618_FB218->obj->model[0], 2, 1);
    func_80029E80_2AA80(((MBModel*)gPlayers[0].unk_24)->obj->model[0], 2, 1);
    func_80029E80_2AA80(((MBModel*)gPlayers[1].unk_24)->obj->model[0], 2, 1);
    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    func_80105EE0_405DE0_name_6C();
    HuPrcSleep(30);
    func_800794A8_7A0A8(0x5A);
    InitFadeOut(0, 0x10);
    HuPrcSleep(0x11);
    func_801045CC_4044CC_name_6C();
    func_80104D4C_404C4C_name_6C();
    func_80106188_406088_name_6C();
    switch (D_80106676_406576_name_6C) {
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

void func_801064A0_4063A0_name_6C(void) {
    func_801032A0_4031A0_name_6C();
    func_80074DB8_759B8(1);
    omAddPrcObj(func_801062A0_4061A0_name_6C, 0x1005, 0x1000, 0);
}

/* Scene 4: back on the space after the last stop passed; the chain depends on the difficulty. */
void func_801064DC_4063DC_name_6C(void) {
    switch (D_800FD8A8_FE4A8.difficulty) {
    case 0:
        SetPlayerOntoChain(0, 1, 0);
        break;
    case 1:
        SetPlayerOntoChain(0, 2, 0);
        break;
    case 2:
        SetPlayerOntoChain(0, 0, 0);
        break;
    }
    omOvlReturnEx(1);
}
