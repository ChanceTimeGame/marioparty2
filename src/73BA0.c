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

extern u8 D_800CD180_CDD80[];
extern UnkPauseEntry D_800E2070_E2C70[];
extern omObjData* D_800E20A0_E2CA0;
extern s16 D_800E20B0_E2CB0;
extern UnkMesSlot D_800CD220_CDE20[];
extern s16 D_800FD2A2_FDEA2;
extern s16 D_800FD840_FE440;

omObjData* func_80073328_73F28(u32 arg0, s16 arg1, s16 arg2, s16 arg3);
void func_80067E6C_68A6C(s16);
s32 func_80075390_75F90(s32);
void func_800753D4_75FD4(s32);
GW_PLAYER* BoardPlayerGet(s32);
void MBPlayerMotionSet(s32 index, s16 animation, s32 unk);
void func_8005670C_5730C(Vec*);
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

INCLUDE_ASM("asm/nonmatchings/73BA0", func_80073014_73C14);

INCLUDE_ASM("asm/nonmatchings/73BA0", func_80073124_73D24);

omObjData* func_800732B0_73EB0(u32 arg0) {
    return func_80073328_73F28(arg0, -1, -1, -1);
}

omObjData* func_800732D4_73ED4(u32 arg0, s16 arg1) {
    return func_80073328_73F28(arg0, arg1, -1, -1);
}

omObjData* func_800732FC_73EFC(u32 arg0, s16 arg1, s16 arg2) {
    return func_80073328_73F28(arg0, arg1, -1, arg2);
}

INCLUDE_ASM("asm/nonmatchings/73BA0", func_80073328_73F28);

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

INCLUDE_ASM("asm/nonmatchings/73BA0", func_8007356C_7416C);

INCLUDE_ASM("asm/nonmatchings/73BA0", func_80073688_74288);

void func_80073790_74390(void) {
    Vec pos;
    GW_PLAYER* player = BoardPlayerGet(-1);

    MBPlayerMotionSet(-1, -1, 2);
    func_8005670C_5730C(&pos);
    func_80056B78_57778(&((BoardObjUnk*)player->unk_24)->unk_18, &pos, &((BoardObjUnk*)player->unk_24)->unk_18, 8);
}
