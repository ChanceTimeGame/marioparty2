#include "common.h"
#include "game/malloc.h"
#include "game/data.h"

/* Board dice blocks and coin/dice processes (MP3 ovl_80_shared_board/EE660.c, MP1 src/3F5B0.c)
   and music fades (MP1 src/42CA0.c). func_80047868, func_80047908 (MP1 func_80041048,
   func_800410E8), func_80047978 and func_800479E4 stay asm: their name strings share this unit's
   rodata piece with asm functions, so it is not carved; functions without C reference stay asm. */

#define DICE_TOTAL 3

typedef struct UnkDiceRelated {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s8 predecidedRollValue[DICE_TOTAL]; // forced roll values, indexed by rollValueIdx
    /* 0x05 */ s8 rollValue[DICE_TOTAL]; // rolled values
    /* 0x08 */ s8 rollValueIdx; // current roll index (0-2)
    /* 0x09 */ s8 unk_09;
    /* 0x0A */ s8 unk_0A;
    /* 0x0B */ s8 unk_0B;
    /* 0x0C */ s8 unk_0C;
    /* 0x0D */ s8 unk_0D;
    /* 0x0E */ s16 sprites[DICE_TOTAL];
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ s16 unk_16; // model, -1 = none
    /* 0x18 */ s16 unk_18; // model, -1 = none
    /* 0x1A */ s16 unk_1A[6];
    /* 0x26 */ s16 unk_26;
    /* 0x28 */ s16 unk28; // sound, -1 = none
    /* 0x2A */ s16 unk2A;
    /* 0x2C */ void* unk_2C;
    /* 0x30 */ void* unk_30;
    /* 0x34 */ void* dice;
    /* 0x38 */ omObjData* unk_38;
    /* 0x3C */ omObjData* omObj;
    /* 0x40 */ f32 unk40;
    /* 0x44 */ f32 unk44;
    /* 0x48 */ f32 unk48;
} UnkDiceRelated; /* size = 0x4C */

typedef struct UnkCoinProc {
    /* 0x00 */ s32 playerNo;
    /* 0x04 */ s32 state;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ char unk_0C[4];
} UnkCoinProc;

typedef struct DiceProcWork {
    /* 0x00 */ s32 player;
    /* 0x04 */ s32 state;
} DiceProcWork;

typedef struct MBModel {
    /* 0x00 */ struct MBModel* next;
    /* 0x04 */ struct MBModel* prev;
    /* 0x08 */ u8 id;
    /* 0x0A */ u16 attr;
    /* 0x0C */ Vec pos;
    /* 0x18 */ Vec rot;
    /* 0x24 */ Vec scale;
    /* 0x30 */ f32 jumpY;
    /* 0x34 */ f32 jumpVel;
    /* 0x38 */ f32 jumpAccel;
    /* 0x3C */ omObjData* obj;
    /* 0x40 */ omObjData* shadow;
    /* 0x44 */ s16 baseMot;
    /* 0x46 */ s16 curMot;
} MBModel; // sizeof 0x48

typedef struct HmfModel {
    /* 0x00 */ char unk_00[0x74];
    /* 0x74 */ f32 mtx[16];
    /* 0xB4 */ char unk_B4[0xC];
} HmfModel; /* size = 0xC0 */

extern UnkDiceRelated D_800DF4C0_E00C0[5];
extern s8 D_800DF63D_E023D;
extern s8 D_800DF63F_E023F;
extern f32 D_800DF640_E0240;
extern u8 D_800DF644_E0244;
extern s8 D_800DF646_E0246;
extern s16 D_800FC734_FD334;
extern HmfModel* D_800FC834_FD434;

void omDelObj(omObjData*);
void SprAttrSet(s16, s16, s32);
void SprAttrReset(s16, s16, s32);
void SprPosSet(s16, s16, s16, s16);
void func_800283DC_28FDC(s16);
void func_800298A4_2A4A4(s16, s32, s32);
void func_8003E964_3F564(s16);
MBModel* func_80043510_44110(s32, void*);
void MBModelKill(void*);
s32 MBRand(f32);
void func_800794F0_7A0F0(s8);
void func_80079848_7A448(s16);
void HuVecCopyXYZ(Vec*, f32, f32, f32);
void func_800B39F0_B45F0(f32*, f32);
void func_80046D2C_4792C(s32);
void func_80047EC0_48AC0(void);
void func_80048860_49460(void);
void func_80048AA8_496A8(void);
void func_80048E80_49A80(void);
void func_800491F0_49DF0(void);
void func_80049090_49C90(void);
void func_80049760_4A360(void);
void func_80049800_4A400(void);

INCLUDE_ASM("asm/nonmatchings/46250", func_80045650_46250);

INCLUDE_ASM("asm/nonmatchings/46250", func_800456BC_462BC);

INCLUDE_ASM("asm/nonmatchings/46250", func_80045B40_46740);

INCLUDE_ASM("asm/nonmatchings/46250", func_80045F54_46B54);

/* exact c: marioparty3 func_800DB56C_EF18C_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_800461C8_46DC8(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < DICE_TOTAL; j++) {
            D_800DF4C0_E00C0[i].rollValue[j] = 0;
            D_800DF4C0_E00C0[i].predecidedRollValue[j] = 0;
        }
    }
    D_800DF646_E0246 = 0;
}

INCLUDE_ASM("asm/nonmatchings/46250", func_80046238_46E38);

INCLUDE_ASM("asm/nonmatchings/46250", func_80046308_46F08);

INCLUDE_ASM("asm/nonmatchings/46250", func_8004655C_4715C);

INCLUDE_ASM("asm/nonmatchings/46250", func_80046918_47518);

/* exact c: marioparty3 func_800DBE6C_EFA8C_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_80046CD8_478D8(s32 arg0) {
    UnkDiceRelated* dice = &D_800DF4C0_E00C0[arg0];

    if (dice->omObj != NULL) {
        omDelObj(dice->omObj);
        dice->omObj = NULL;
    }
}

INCLUDE_ASM("asm/nonmatchings/46250", func_80046D2C_4792C);

/* exact c: marioparty3 func_800DBFBC_EFBDC_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_80046E2C_47A2C(s32 arg0) {
    UnkDiceRelated* dice = &D_800DF4C0_E00C0[arg0];

    dice->rollValue[dice->rollValueIdx]--;
    if (dice->rollValue[dice->rollValueIdx] <= 0) {
        func_80046D2C_4792C(arg0);
    }
}

/* exact c: marioparty3 func_800DC024_EFC44_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_80046E94_47A94(s32 arg0) {
    if (D_800DF4C0_E00C0[arg0].unk_16 != -1) {
        func_800298A4_2A4A4(D_800DF4C0_E00C0[arg0].unk_16, 4, 4);
    }
}

/* exact c: marioparty3 func_800DC06C_EFC8C_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_80046EDC_47ADC(s32 arg0) {
    D_800DF644_E0244 = 0;
    func_80046E94_47A94(arg0);
}

/* exact c: marioparty3 func_800DC08C_EFCAC_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_80046EFC_47AFC(s32 arg0) {
    if (D_800DF644_E0244 != 0) {
        if (D_800DF4C0_E00C0[arg0].unk_16 != -1) {
            func_800298A4_2A4A4(D_800DF4C0_E00C0[arg0].unk_16, 4, 0);
        }
    }
}

/* exact c: marioparty3 func_800DC0E0_EFD00_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_80046F50_47B50(s32 arg0) {
    D_800DF644_E0244 = 1;
    func_80046EFC_47AFC(arg0);
}

/* exact c: marioparty3 func_800DE988_F25A8_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_80046F74_47B74(s32 arg0, s32 arg1) {
    D_800DF4C0_E00C0[arg0].unk_09 = arg1;
}

INCLUDE_ASM("asm/nonmatchings/46250", func_80046F98_47B98);

INCLUDE_ASM("asm/nonmatchings/46250", func_80047580_48180);

INCLUDE_ASM("asm/nonmatchings/46250", func_80047868_48468);

INCLUDE_ASM("asm/nonmatchings/46250", func_80047908_48508);

INCLUDE_ASM("asm/nonmatchings/46250", func_80047978_48578);

INCLUDE_ASM("asm/nonmatchings/46250", func_800479E4_485E4);

/* exact c: marioparty3 func_800DCA64_F0684_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_80047A50_48650(s32 arg0) {
    UnkDiceRelated *entry = &D_800DF4C0_E00C0[arg0];
    s16 id;
    s32 i;

    if (entry->unk_16 != -1) {
        func_800283DC_28FDC(entry->unk_16);
        for (i = 0; i < 6; i++) {
            if (entry->unk_1A[i] != -1) {
                func_8003E964_3F564(entry->unk_1A[i]);
            }
        }
        if (entry->unk_2C != NULL) {
            DataClose(entry->unk_2C);
        }
        omDelObj((omObjData*)entry->dice);
        entry->dice = NULL;
        entry->unk_16 = -1;
    }

    if (entry->unk_18 != -1) {
        func_800283DC_28FDC(entry->unk_18);
        entry->unk_18 = -1;
        if (entry->unk_38 != NULL) {
            omDelObj(entry->unk_38);
            entry->unk_38 = NULL;
        }
    }

    if (entry->unk_26 != -1) {
        func_8003E964_3F564(entry->unk_26);
        entry->unk_26 = -1;
    }

    if (entry->unk_30 != NULL) {
        DataClose(entry->unk_30);
        entry->unk_30 = NULL;
    }
}

/* exact c: marioparty3 func_800DCB8C_F07AC_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_80047B78_48778(void) {
    s32 i;

    for (i = 0; i < 5; i++) {
        func_80047A50_48650(i);
        func_80046D2C_4792C(i);
    }
}

INCLUDE_ASM("asm/nonmatchings/46250", func_80047BB8_487B8);

/* exact c: marioparty3 func_800DCCE0_F0900_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_80047D2C_4892C(void) {
    D_800DF63D_E023D = 1;
    D_800DF640_E0240 = 250.0f;
}

/* exact c: marioparty3 func_800DCD00_F0920_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
s32 func_80047D4C_4894C(s32 arg0) {
    if (~D_800DF4C0_E00C0[arg0].unk_16) {
        return 1;
    } else {
        return 0;
    }
}

/* exact c: marioparty3 func_800DCD64_F0984_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_80047D78_48978(s32 arg0, s32 arg1) {
    D_800DF4C0_E00C0[arg0].rollValue[D_800DF4C0_E00C0[arg0].rollValueIdx] = arg1;
}

/* exact c: marioparty3 func_800DCD64_F0984_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_80047DB0_489B0(s32 arg0, s32 arg1) {
    D_800DF4C0_E00C0[arg0].predecidedRollValue[D_800DF4C0_E00C0[arg0].rollValueIdx] = arg1;
}

/* exact c: marioparty3 func_800DCD9C_F09BC_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
s32 func_80047DE8_489E8(s32 arg0) {
    return D_800DF4C0_E00C0[arg0].rollValue[D_800DF4C0_E00C0[arg0].rollValueIdx];
}

INCLUDE_ASM("asm/nonmatchings/46250", func_80047E20_48A20);

INCLUDE_ASM("asm/nonmatchings/46250", func_80047E48_48A48);

INCLUDE_ASM("asm/nonmatchings/46250", func_80047E70_48A70);

INCLUDE_ASM("asm/nonmatchings/46250", func_80047E98_48A98);

INCLUDE_ASM("asm/nonmatchings/46250", func_80047EC0_48AC0);

/* exact c: marioparty func_800419D8 (src/3F5B0.c) */
Process* func_80048800_49400(s32 player) {
    Process* process = omAddPrcObj(func_80047EC0_48AC0, 0, 0, 0x40);
    DiceProcWork* work = HuMemMemoryAlloc(process->heap, 0x10);

    process->user_data = work;
    work->player = player;
    work->state = 0;
    return process;
}

INCLUDE_ASM("asm/nonmatchings/46250", func_80048860_49460);

/* exact c: marioparty func_800419D8 (src/3F5B0.c) */
Process* func_80048A48_49648(s32 player) {
    Process* process = omAddPrcObj(func_80048860_49460, 0, 0, 0x40);
    DiceProcWork* work = HuMemMemoryAlloc(process->heap, 0x10);

    process->user_data = work;
    work->player = player;
    work->state = 0;
    return process;
}

INCLUDE_ASM("asm/nonmatchings/46250", func_80048AA8_496A8);

/* exact c: marioparty3 func_800DDBC8_F17E8_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_80048E0C_49A0C(void* arg0) {
    Process* temp_v0;

    D_800FC734_FD334 = 0;
    temp_v0 = omAddPrcObj(func_80048AA8_496A8, 0x4800U, 0, 0);
    temp_v0->user_data = arg0;
    HuPrcChildLink(HuPrcCurrentGet(), temp_v0);
    HuPrcChildWatch();
    D_800FC734_FD334 = 1;
}

INCLUDE_ASM("asm/nonmatchings/46250", func_80048E80_49A80);

/* exact c: marioparty3 func_800DDDD4_F19F4_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
Process* func_80049028_49C28(s32 arg0) {
    Process* temp_v0;
    UnkCoinProc* temp_v0_2;

    temp_v0 = omAddPrcObj(func_80048E80_49A80, 0, 0, 0x40);
    temp_v0_2 = HuMemMemoryAlloc(temp_v0->heap, sizeof(UnkCoinProc));
    temp_v0->user_data = temp_v0_2;
    temp_v0_2->playerNo = arg0;
    temp_v0_2->state = 0;
    D_800DF63F_E023F = 0;
    return temp_v0;
}

/* same c: marioparty3 func_800DE48C_F20AC_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_80049090_49C90(void) {
    MBModel* temp_v0;
    MBModel* temp_s0;
    f32 var_f20;
    s32 i;
    
    temp_s0 = HuPrcCurrentGet()->user_data;
    temp_v0 = func_80043510_44110(0x18, NULL);
    HuVecCopyXYZ(&temp_v0->pos, temp_s0->pos.x, 0.0f, temp_s0->pos.z);
    HuVecCopyXYZ(&temp_v0->scale, 2.0f, 2.0f, 2.0f);
    temp_v0->jumpY = 35.0f;
    var_f20 = (f32) MBRand(360.0f);

    for (i = 0; i < 5; i++) {
        HuPrcVSleep();
        temp_v0->jumpY += 3.0f;
        var_f20 += 40.0f;
        func_800B39F0_B45F0(D_800FC834_FD434[temp_v0->obj->model[0]].mtx, var_f20);
    }

    MBModelKill(temp_v0);
    omDelPrcObj(NULL);
}

/* exact c: marioparty func_800F8E80_DKsJungleAdventure (src/overlays/ovl_36_DKsJungleAdventure/2418D0.c) */
Process* func_800491B4_49DB4(void* arg0) {
    Process* proc;

    proc = omAddPrcObj(func_80049090_49C90, 0x4800, 0, 0);
    proc->user_data = arg0;
    return proc;
}

INCLUDE_ASM("asm/nonmatchings/46250", func_800491F0_49DF0);

/* exact c: marioparty3 func_800DDDD4_F19F4_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
Process* func_80049408_4A008(s32 arg0) {
    Process* temp_v0;
    UnkCoinProc* temp_v0_2;

    temp_v0 = omAddPrcObj(func_800491F0_49DF0, 0, 0, 0x40);
    temp_v0_2 = HuMemMemoryAlloc(temp_v0->heap, sizeof(UnkCoinProc));
    temp_v0->user_data = temp_v0_2;
    temp_v0_2->playerNo = arg0;
    temp_v0_2->state = 0;
    D_800DF63F_E023F = 0;
    return temp_v0;
}

INCLUDE_ASM("asm/nonmatchings/46250", func_80049470_4A070);

INCLUDE_ASM("asm/nonmatchings/46250", func_8004947C_4A07C);

INCLUDE_ASM("asm/nonmatchings/46250", func_8004948C_4A08C);

/* exact c: marioparty3 func_800DE874_F2494_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_80049498_4A098(s32 arg0) {
    UnkDiceRelated* temp_s0 = &D_800DF4C0_E00C0[arg0];

    if (temp_s0->unk28 != -1) {
        func_80079848_7A448(temp_s0->unk28);
        temp_s0->unk28 = -1;
    }
    temp_s0->unk2A = 1;
}

INCLUDE_ASM("asm/nonmatchings/46250", func_800494FC_4A0FC);

INCLUDE_ASM("asm/nonmatchings/46250", func_800495A8_4A1A8);

/* exact c: marioparty3 func_800DE988_F25A8_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_800495B4_4A1B4(s32 arg0, s32 arg1) {
    D_800DF4C0_E00C0[arg0].rollValueIdx = arg1;
}

INCLUDE_ASM("asm/nonmatchings/46250", func_800495D8_4A1D8);

/* exact c: marioparty3 func_800DE9B8_F25D8_shared_board (src/overlays/ovl_80_shared_board/EE660.c) */
void func_800495E4_4A1E4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    UnkDiceRelated *entry;

    entry = &D_800DF4C0_E00C0[arg0];

    if (entry->rollValue[arg1] >= 10) {
        SprAttrReset(entry->sprites[arg1], 1, 0x8000);
        SprPosSet(entry->sprites[arg1], 0, arg2 + 10, arg3);
        SprPosSet(entry->sprites[arg1], 1, -0x1C, 0);
    } else {
        SprAttrSet(entry->sprites[arg1], 1, 0x8000);
        SprPosSet(entry->sprites[arg1], 0, arg2, arg3);
    }
}

INCLUDE_ASM("asm/nonmatchings/46250", func_800496CC_4A2CC);

/* exact c: marioparty func_800420A0 (src/42CA0.c) */
void func_80049760_4A360(void) {
    f32 volume = 96.0f;

    func_800794F0_7A0F0(96);
    do {
        HuPrcVSleep();
        volume += 1.9375f;
        if (volume >= 127.0f) {
            volume = 127.0f;
        }
        func_800794F0_7A0F0((s8)volume);
    } while (volume < 127.0f);
    omDelPrcObj(NULL);
}

/* exact c: marioparty func_80042140 (src/42CA0.c) */
void func_80049800_4A400(void) {
    f32 volume = 127.0f;

    func_800794F0_7A0F0(127);
    do {
        HuPrcVSleep();
        volume -= 1.9375f;
        if (volume <= 96.0f) {
            volume = 96.0f;
        }
        func_800794F0_7A0F0((s8)volume);
    } while (volume > 96.0f);
    omDelPrcObj(NULL);
}

/* exact c: marioparty func_800421E0 (src/42CA0.c) */
void func_800498A0_4A4A0(void) {
    omAddPrcObj(func_80049800_4A400, 0xEFFF, 0, 0);
}

/* exact c: marioparty func_800421E0 (src/42CA0.c) */
void func_800498CC_4A4CC(void) {
    omAddPrcObj(func_80049760_4A360, 0xEFFF, 0, 0);
}

