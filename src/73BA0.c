#include "common.h"
#include "process.h"

/* Pause-menu tables and the board's current status-window message slot (MP3 src/pause.c, MP1
   src/5C460.c). MP1/MP3 names are anonymous, so MP2's are kept. */

typedef struct UnkPauseEntry {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s8 unk04;
    /* 0x05 */ u8 unk05;
    /* 0x06 */ u8 unk06;
    /* 0x07 */ u8 unk07;
} UnkPauseEntry; // size 8

typedef struct UnkMesSlot {
    /* 0x00 */ s8 flag;
    /* 0x01 */ s8 unk1;
    /* 0x02 */ s8 unk2;
} UnkMesSlot; // size 3

typedef struct BoardObjUnk {
    /* 0x00 */ char unk_00[0x18];
    /* 0x18 */ Vec unk_18;
} BoardObjUnk;

/* .data (0xCDD80-0xCDEB0) */
u8 D_800CD180_CDD80[13] = { 0xC7, 0xC9, 0xCA, 0xCB, 0xCC, 0x37, 0x4E, 0x4F, 0x50, 0x51, 0x52, 0x53, 0x54 };
u8 D_800CD190_CDD90[3] = { 0, 11, 12 };
u16 D_800CD194_CDD94[3] = { 0x102, 0x109, 0x102 };
u8 D_800CD19C_CDD9C[13] = { 0x57, 0x6D, 0x0F, 0x00, 0x1F, 0x00, 0x4D, 0x5C, 0x42, 0x19, 0x03, 0x56, 0x64 };
u8 D_800CD1AC_CDDAC[13] = { 0x00, 0x16, 0x0D, 0x00, 0x00, 0x00, 0x67, 0x53, 0x0E, 0x0F, 0x1B, 0x3A, 0x20 };
u8 D_800CD1BC_CDDBC[13] = { 0x57, 0x09, 0x09, 0x09, 0x15, 0x00, 0x5B, 0x3E, 0x3D, 0x12, 0x1B, 0x4F, 0x5F };
u8 D_800CD1CC_CDDCC[13] = { 0x60, 0x5F, 0x22, 0x19, 0x15, 0x00, 0x5C, 0x61, 0x3C, 0x12, 0x15, 0x90, 0x4D };
u8 D_800CD1DC_CDDDC[13] = { 0x24, 0x00, 0x00, 0x00, 0x20, 0x00, 0x24, 0x0A, 0x00, 0x10, 0x00, 0x5C, 0x12 };
u8 D_800CD1EC_CDDEC[13] = { 0x00, 0x63, 0x00, 0x00, 0x00, 0x00, 0x43, 0x55, 0x00, 0x0C, 0x00, 0x45, 0x72 };
u8* D_800CD1FC_CDDFC[6] = {
    D_800CD19C_CDD9C, D_800CD1AC_CDDAC, D_800CD1BC_CDDBC, D_800CD1CC_CDDCC, D_800CD1DC_CDDDC, D_800CD1EC_CDDEC,
};
u8 D_800CD214_CDE14[12] = { 2, 3, 7, 4, 5, 6, 0, 0, 0, 0, 0, 0 };
UnkMesSlot D_800CD220_CDE20[48] = {
    { 0x2E, 1, 1 }, { 0x2A, 1, 2 }, { 0x46, 1, 3 }, { 0x35, 1, 4 }, { 0x21, 2, 1 }, { 0x44, 2, 2 },
    { 0x1E, 2, 3 }, { 0x42, 2, 4 }, { 0x20, 2, 5 }, { 0x11, 3, 1 }, { 0x14, 3, 2 }, { 0x18, 3, 3 },
    { 0x0F, 3, 4 }, { 0x28, 4, 1 }, { 0x31, 4, 2 }, { 0x2D, 4, 3 }, { 0x45, 4, 4 }, { 0x27, 4, 5 },
    { 0x24, 5, 1 }, { 0x1B, 5, 2 }, { 0x1C, 5, 3 }, { 0x1F, 5, 4 }, { 0x43, 5, 5 }, { 0x1A, 5, 6 },
    { 0x47, 6, 1 }, { 0x16, 6, 2 }, { 0x15, 6, 3 }, { 0x12, 6, 4 }, { 0x17, 6, 5 }, { 0x13, 6, 6 },
    { 0x32, 7, 1 }, { 0x29, 7, 2 }, { 0x2B, 7, 3 }, { 0x26, 7, 4 }, { 0x34, 7, 5 }, { 0x2C, 7, 6 },
    { 0x48, 8, 1 }, { 0x36, 8, 2 }, { 0x37, 8, 3 }, { 0x33, 8, 4 }, { 0x25, 8, 5 }, { 0x30, 8, 6 },
    { 0x37, 9, 1 }, { 0x00, 0, 0 }, { 0x00, 0, 0 }, { 0x00, 0, 0 }, { 0x00, 0, 0 }, { 0x00, 0, 0 },
};
extern UnkPauseEntry D_800E2070_E2C70[];
extern omObjData* D_800E20A0_E2CA0;
extern s16 D_800E20B0_E2CB0;
extern s16 D_800FD2A2_FDEA2;
extern s16 D_800FD840_FE440;

omObjData* func_80073328_73F28(u32 arg0, s16 arg1, s16 arg2, s16 arg3);
s32 func_80072FA0_73BA0(s32 arg0);
void func_80073124_73D24(omObjData*);
s32 PlaySound(s32);
s16 func_800888A8_894A8(s16, s16, s16, s16, s32, s16);
void func_80089A7C_8A67C(s16, s16);
void func_80089A48_8A648(s16, s16);
void func_80089B2C_8A72C(s16, s16);
void func_800890CC_89CCC(s16, s32, s32, s32);
s16 func_8008BA30_8C630(s16);
void func_8008D59C_8E19C(s16, s16);
s16 func_8008BB48_8C748(s16, s32, s32);
void func_8008CCA8_8D8A8(s16);

void func_80067E6C_68A6C(s16);
s32 func_80075390_75F90(s32);
void func_800753D4_75FD4(s32);
GW_PLAYER* BoardPlayerGet(s32);
void MBPlayerMotionSet(s32 index, s16 animation, s32 unk);
void func_8005670C_5730C(Vec*);
s16 func_800797DC_7A3DC(s32 id, s16 player);
s32 func_8007975C_7A35C(s16 arg0, s16 arg1);
void func_800798F8_7A4F8(s16 arg0, s16 arg1);
void func_800795D8_7A1D8(s16 index, s8 val);
Process* func_80056B78_57778(Vec*, Vec*, Vec*, s32);

s32 func_80072FA0_73BA0(s32 arg0) {
    u32 var_v0;
    u32 var_v1;

    for (var_v1 = 0; var_v1 < 13; var_v1++) {
        if ((arg0 & 0xFF) == D_800CD180_CDD80[var_v1]) {
            break;
        }
    }
    if (var_v1 >= 13) {
        var_v1 = -1;
    }
    return var_v1;
}

void func_80072FDC_73BDC(void) {
    s32 var_v1;

    D_800E20A0_E2CA0 = NULL;
    for (var_v1 = 0; var_v1 < 6; var_v1++) {
        D_800E2070_E2C70[var_v1].unk00 = -1;
    }
}

s16 func_80073014_73C14(u32 arg0, UnkPauseEntry* arg1) {
    s32 temp_v0;
    s32 var_v1;
    s16 var_a2;
    s16 var_a1;
    s32 temp_a0;

    temp_v0 = func_80072FA0_73BA0(arg0);
    if (temp_v0 < 0) {
        return -1;
    }
    temp_a0 = (arg0 >> 16) & 0xFF;
    for (var_v1 = 0; var_v1 < 6; var_v1++) {
        if (temp_a0 == D_800CD214_CDE14[var_v1]) {
            break;
        }
    }
    if (var_v1 >= 6) {
        return -1;
    }
    temp_a0 = var_v1;
    for (var_v1 = 1; var_v1 < 3; var_v1++) {
        if (temp_v0 < D_800CD190_CDD90[var_v1]) {
            break;
        }
    }
    var_v1--;
    var_a2 = D_800CD194_CDD94[var_v1];
    var_a1 = D_800CD1FC_CDDFC[temp_a0][temp_v0];
    var_v1 = var_a1;
    if (var_v1 == 0xFF) {
        var_a1 = -1;
        var_a2 = -1;
    }
    if (arg1 != NULL) {
        arg1->unk00 = var_a2;
        arg1->unk06 = temp_a0;
        var_v1 = var_a1 + 1;
        var_v1 >>= 1;
        arg1->unk07 = var_v1;
    }
    return var_a1;
}

/* Plays the queued voice entries: a character voice (unk05 < 4: that player's character) or a
   sound cycling through obj->work[0], then its volume (unk02) and pan (unk04). */
// retail loads unk00 (lh) before unk06 for the second call's sound id (masked 2)
#ifdef NON_MATCHING
void func_80073124_73D24(omObjData* obj) {
    s32 i;
    s16 snd;
    u8 pl;

    for (i = 0; i < 6; i++) {
        if (D_800E2070_E2C70[i].unk00 < 0) {
            continue;
        }
        if (D_800E2070_E2C70[i].unk07 != 0) {
            D_800E2070_E2C70[i].unk07--;
            continue;
        }
        pl = D_800E2070_E2C70[i].unk05;
        if (pl < 4) {
            snd = func_800797DC_7A3DC((s16)(D_800E2070_E2C70[i].unk00 + 1), (s8)pl);
        } else {
            snd = func_8007975C_7A35C(D_800E2070_E2C70[i].unk06 + D_800E2070_E2C70[i].unk00 + 1, obj->work[0]);
            obj->work[0]++;
            if (obj->work[0] >= 4) {
                obj->work[0] = 0;
            }
        }
        if (snd >= 0) {
            if (D_800E2070_E2C70[i].unk02 >= 0) {
                func_800798F8_7A4F8(snd, D_800E2070_E2C70[i].unk02);
            }
            if (D_800E2070_E2C70[i].unk04 >= 0) {
                func_800795D8_7A1D8(snd, D_800E2070_E2C70[i].unk04);
            }
        }
        D_800E2070_E2C70[i].unk00 = -1;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/73BA0", func_80073124_73D24);
#endif

omObjData* func_800732B0_73EB0(u32 arg0) {
    return func_80073328_73F28(arg0, -1, -1, -1);
}

omObjData* func_800732D4_73ED4(u32 arg0, s16 arg1) {
    return func_80073328_73F28(arg0, arg1, -1, -1);
}

omObjData* func_800732FC_73EFC(u32 arg0, s16 arg1, s16 arg2) {
    return func_80073328_73F28(arg0, arg1, -1, arg2);
}

omObjData* func_80073328_73F28(u32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    UnkPauseEntry sp18;

    if (func_80073014_73C14(arg0, &sp18) >= 0) {
        u8 temp_06 = sp18.unk06;

        D_800E2070_E2C70[temp_06].unk00 = sp18.unk00;
        D_800E2070_E2C70[temp_06].unk02 = arg1;
        D_800E2070_E2C70[temp_06].unk04 = arg2;
        D_800E2070_E2C70[temp_06].unk05 = arg3;
        D_800E2070_E2C70[temp_06].unk06 = sp18.unk06;
        D_800E2070_E2C70[temp_06].unk07 = sp18.unk07;
        if (D_800E20A0_E2CA0 == NULL) {
            D_800E20A0_E2CA0 = omAddObj(32000, 0, 0, -1, func_80073124_73D24);
            D_800E20A0_E2CA0->work[0] = 0;
        }
    }
    return D_800E20A0_E2CA0;
}

void func_80073410_74010(s16 index) {
    D_800E20B0_E2CB0 = index;
    if (index >= 0) {
        func_80067E6C_68A6C(D_800CD220_CDE20[index].flag);
        D_800FD2A2_FDEA2 = D_800CD220_CDE20[index].unk1;
        D_800FD840_FE440 = D_800CD220_CDE20[index].unk2;
    } else {
        func_80067E6C_68A6C(index);
        D_800FD2A2_FDEA2 = -1;
        D_800FD840_FE440 = -1;
    }
}

INCLUDE_ASM("asm/nonmatchings/73BA0", func_800734B0_740B0);

void func_800734E8_740E8(void) {
    s16 index = D_800E20B0_E2CB0;

    if (_CheckFlag(0x16) != 0 && index >= 0) {
        _ClearFlag(0x16);
        func_800753D4_75FD4(index + 9);
    }
}

s32 func_80073538_74138(void) {
    return (D_800E20B0_E2CB0 < 0) ? 1 : func_80075390_75F90(D_800E20B0_E2CB0 + 9);
}

s16 func_8007356C_7416C(s32 str) {
    u8 port = gPlayers[0].port;
    s16 win;
    s16 choice;

    PlaySound(0);
    win = func_800888A8_894A8(0x5F, 0x32, 0x81, 0x22, 0, 0);
    func_80089A7C_8A67C(win, 5);
    func_80089B2C_8A72C(win, 0xDC);
    if (str != 0) {
        func_800890CC_89CCC(win, str, -1, -1);
    }
    func_80089A48_8A648(win, 0);
    while (func_8008BA30_8C630(win) != 0) {
        HuPrcVSleep();
    }
    func_8008D59C_8E19C(win, (s16)(1 << port));
    choice = func_8008BB48_8C748(win, 0, 0);
    func_8008CCA8_8D8A8(win);
    PlaySound(0);
    return choice;
}

INCLUDE_ASM("asm/nonmatchings/73BA0", func_80073688_74288);

void func_80073790_74390(void) {
    Vec pos;
    GW_PLAYER* player = BoardPlayerGet(-1);

    MBPlayerMotionSet(-1, -1, 2);
    func_8005670C_5730C(&pos);
    func_80056B78_57778(&((BoardObjUnk*)player->unk_24)->unk_18, &pos, &((BoardObjUnk*)player->unk_24)->unk_18, 8);
}
