#include "common.h"
#include "game/data.h"
#include "game/malloc.h"

/* Board HUD and minigame-pick helpers. The C functions are MP1 src/43760.c (func_80042B60 ..
   func_800448A0) and MP3 ovl_80_shared_board F2910.c (MBArrayShuffle), F5070.c (MBCoinChange*) and
   EE660.c; the rest have no reference or differ (near) and stay asm. */

#define UNK_SIZE 4
#define UNK_SIZE2 2

typedef struct unk43760 {
    s16 unk_00;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
    s16 unk_0A;
} unk43760;

typedef struct unkUserData_00 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
} unkUserData_00; // size 0x10

extern u32 D_800CBDC4_CC9C4;
extern u8 D_800CBD60_CC960[];
extern u8 D_800CBD68_CC968[];
extern unk43760 D_800DF660_E0260[5];
extern u16 D_800DF664_E0264;
extern s8 D_800DF698_E0298[6][5];
extern s8 D_800DF6B6_E02B6[6];
extern omObjData* D_800DF6BC_E02BC;
extern s8 D_800DF6C5_E02C5;
extern s16 D_800DF6C6_E02C6;
extern s16 D_800DF6C8_E02C8;
extern s16 D_800DF6CA_E02CA;
extern s16 D_800DF6CC_E02CC;
extern s8 D_800DF6CE_E02CE[5];
extern s8 D_800DF6D3_E02D3;
extern s16 D_800DF6E0_E02E0[UNK_SIZE];
extern s16 D_800DF6E8_E02E8[UNK_SIZE][UNK_SIZE2];
extern omObjData* D_800DF6F8_E02F8[UNK_SIZE];
extern u8 D_800DF708_E0308;
extern u32 D_800FDC6C_FE86C;

s32 MBRand(f32);
s32 PlaySound(s32);
void SprKill(s16);
void SprAnimKill(s16);
s16 SprCreate(s32, s32);
void SprPosSet(s16, s16, s16, s16);
void SprAnimSet(s16, s16, s16, u16);
void SprPrioSet(s16, s16, u16);
void SprAttrSet(s16, s16, s32);
s16 SprAnimRead(void*);
void omDelObj(omObjData*);
void func_8004B65C_4C25C(void);
void func_8004BE4C_4CA4C(void);
void func_8004C3CC_4CFCC(s32);
void func_80060034_60C34(s32, s32);
s32 func_800600C0_60CC0(s32);
s32 func_800609D8_615D8(void);
void func_80082450_83050(s16, s32, s32, s32, u8);
void func_8008CCA8_8D8A8(s16);


void func_80049FB0_4ABB0(void) {
    if (D_800FDC6C_FE86C >= (D_800CBDC4_CC9C4 + 4)) {
        PlaySound(0x324);
        D_800CBDC4_CC9C4 = D_800FDC6C_FE86C;
    }
}

//same as func_800DED3C_F295C_shared_board in mp3
INCLUDE_ASM("asm/nonmatchings/4ABB0", func_80049FFC_4ABFC);

void func_8004A908_4B508(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 5; j++) {
            D_800DF698_E0298[i][j] = -1;
        }
        D_800DF6B6_E02B6[i] = 0;
    }
    for (i = 0; i < 5; i++) {
        D_800DF6CE_E02CE[i] = -1;
    }
    D_800DF6D3_E02D3 = 0;
}

void func_8004A98C_4B58C(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_800DF660_E0260); i++) {
        D_800DF660_E0260[i].unk_00 = -1;
    }

    D_800DF6BC_E02BC = 0;
    D_800DF6C8_E02C8 = -1;
    D_800DF6C6_E02C6 = -1;
    D_800DF6CC_E02CC = -1;
    D_800DF6CA_E02CA = -1;
}

void func_8004A9EC_4B5EC(void) {
    s32 i;
    unk43760* p;

    for (i = 0; i < ARRAY_COUNT(D_800DF660_E0260); i++) {
        p = &D_800DF660_E0260[i];
        if (p->unk_00 != -1) {
            func_8008CCA8_8D8A8(p->unk_00);
            p->unk_00 = -1;
        }
    }
    if (D_800DF6BC_E02BC != NULL) {
        omDelObj(D_800DF6BC_E02BC);
        D_800DF6BC_E02BC = NULL;
    }
    if (D_800DF6C6_E02C6 != -1) {
        SprKill(D_800DF6C6_E02C6);
        D_800DF6C6_E02C6 = -1;
    }
    if (D_800DF6C8_E02C8 != -1) {
        SprAnimKill(D_800DF6C8_E02C8);
        D_800DF6C8_E02C8 = -1;
    }
    if (D_800DF6CA_E02CA != -1) {
        SprKill(D_800DF6CA_E02CA);
        D_800DF6CA_E02CA = -1;
    }
    if (D_800DF6CC_E02CC != -1) {
        SprAnimKill(D_800DF6CC_E02CC);
        D_800DF6CC_E02CC = -1;
    }
}

void func_8004AB24_4B724(void) {
    void* temp_s0;

    if (D_800DF6C6_E02C6 == -1) {
        D_800DF6C6_E02C6 = SprCreate(1, 5);
        temp_s0 = DataRead(0xA0165);
        D_800DF6C8_E02C8 = SprAnimRead(temp_s0);
        DataClose(temp_s0);
        SprAnimSet(D_800DF6C6_E02C6, 0, D_800DF6C8_E02C8, 0);
        SprPrioSet(D_800DF6C6_E02C6, 0, 0x4770);
        SprAttrSet(D_800DF6C6_E02C6, 0, 0x1000U);
        SprPosSet(D_800DF6C6_E02C6, 0, 0xA0, D_800CBD60_CC960[D_800DF6C5_E02C5] + D_800DF664_E0264);
        
        if (rand8() & 1) {
            func_80082450_83050(D_800DF6C6_E02C6, 0, 0x35,  0x9D, 0xE6);
        } else {
            func_80082450_83050(D_800DF6C6_E02C6, 0, 0xAD, 0x71, 0xFE);
        }
    }
}

void func_8004AC60_4B860(void) {
    void* temp_s0;

    if (D_800DF6CA_E02CA == -1) {
        D_800DF6CA_E02CA = SprCreate(1, 5);
        temp_s0 = DataRead(0xA001B);
        D_800DF6CC_E02CC = SprAnimRead(temp_s0);
        DataClose(temp_s0);
        SprAnimSet(D_800DF6CA_E02CA, 0, D_800DF6CC_E02CC, 0);
        SprPrioSet(D_800DF6CA_E02CA, 0, 0x100);
        SprAttrSet(D_800DF6CA_E02CA, 0, 0x1000U);
        SprPosSet(D_800DF6CA_E02CA, 0, 0x32, D_800CBD68_CC968[D_800DF6C5_E02C5]);
    }
}

INCLUDE_ASM("asm/nonmatchings/4ABB0", func_8004AD34_4B934);

INCLUDE_ASM("asm/nonmatchings/4ABB0", func_8004B214_4BE14);

void MBArrayShuffle(u8 *output, s32 count) {
    s8 pool[256];
    s32 i;
    s32 j;
    s32 randIndex;

    for (i = 0; i <= count; i++) {
        pool[i] = i;
    }

    for (i = 0; i <= count; i++) {
        randIndex = MBRand((f32)(count - i + 1));
        output[i] = pool[randIndex];

        /* Remove picked element by shifting the rest down */
        for (j = randIndex; j < count; j++) {
            pool[j] = pool[j + 1];
        }
    }
}

void func_8004B304_4BF04(u8* out) {
    s32 res[4];
    u8 order[4];
    s32 i;
    s32 n4;
    s32 n1;
    s32 r;

    for (i = 0; i < 4; i++) {
        res[i] = 0;
    }
    n4 = 0;
    n1 = 0;
    for (i = 0; i < 4; i++) {
        if (func_800600C0_60CC0(i) == 1) {
            n1++;
        } else if (func_800600C0_60CC0(i) != 2) {
            n4 += func_800600C0_60CC0(i) == 4;
        }
    }
    r = MBRand(100.0f);
    switch (n4) {
        case 1:
            switch (n1) {
                case 3:
                    if (r < 20) {
                        res[0] = 1;
                    }
                    break;
                case 2:
                    if (r < 60) {
                        res[0] = 1;
                    }
                    break;
                case 1:
                    if (r < 50) {
                        res[0] = 1;
                    }
                    break;
                case 0:
                    if (r < 70) {
                        res[0] = 1;
                    }
                    break;
            }
            break;
        case 2:
            switch (n1) {
                case 2:
                    if (r < 15) {
                        res[0] = res[1] = 1;
                    } else if (r < 30) {
                        res[1] = 1;
                    }
                    break;
                case 1:
                    if (r < 20) {
                        res[0] = res[1] = 1;
                    } else if (r < 80) {
                        res[1] = 1;
                    }
                    break;
                case 0:
                    if (r < 70) {
                        res[0] = res[1] = 1;
                    } else if (r < 85) {
                        res[1] = 1;
                    }
                    break;
            }
            break;
        case 3:
            switch (n1) {
                case 1:
                    if (r < 10) {
                        res[0] = res[1] = res[2] = 1;
                    } else if (r < 30) {
                        res[1] = res[2] = 1;
                    } else if (r < 40) {
                        res[2] = 1;
                    }
                    break;
                case 0:
                    if (r < 60) {
                        res[0] = res[1] = res[2] = 1;
                    } else if (r < 70) {
                        res[1] = res[2] = 1;
                    } else if (r < 90) {
                        res[2] = 1;
                    }
                    break;
            }
            break;
        case 4:
            if (r < 25) {
                res[0] = res[1] = res[2] = res[3] = 1;
            } else if (r < 35) {
                res[1] = res[2] = res[3] = 1;
            } else if (r < 60) {
                res[2] = res[3] = 1;
            } else if (r < 75) {
                res[3] = 1;
            }
            break;
    }
    MBArrayShuffle(order, n4 - 1);
    n1 = 0;
    for (i = 0; i < 4; i++) {
        switch (func_800600C0_60CC0(i)) {
            case 1:
                out[i] = 1;
                break;
            case 2:
                out[i] = 2;
                break;
            case 4:
                if (res[order[n1++]] == 0) {
                    out[i] = 1;
                } else {
                    out[i] = 2;
                }
                break;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/4ABB0", func_8004B65C_4C25C);

Process* func_8004B974_4C574(void) {
    Process* process;
    s32* data;

    process = omAddPrcObj(&func_8004B65C_4C25C, 0, 0x2000, 0x40);
    data = HuMemMemoryAlloc(process->heap, 16);
    process->user_data = data;
    *data = 0;
    return process;
}

INCLUDE_ASM("asm/nonmatchings/4ABB0", func_8004B9C4_4C5C4);

INCLUDE_ASM("asm/nonmatchings/4ABB0", func_8004BB2C_4C72C);

INCLUDE_ASM("asm/nonmatchings/4ABB0", func_8004BB94_4C794);

INCLUDE_ASM("asm/nonmatchings/4ABB0", func_8004BBFC_4C7FC);

INCLUDE_ASM("asm/nonmatchings/4ABB0", func_8004BDE4_4C9E4);

void func_8004BE4C_4CA4C(void) {
    u8 isFour[4];
    u8 saved[4];
    unkUserData_00* data;
    s32 i;
    s32 j;

    data = HuPrcCurrentGet()->user_data;
    while (1) {
        switch (data->unk_00) {
            case 10:
                if (func_800609D8_615D8() == 0) {
                    data->unk_00 = 11;
                }
                break;
            case 11:
                j = 0;
                for (i = 0; i < 4; i++) {
                    if (func_800600C0_60CC0(i) == 4) {
                        j = 1;
                        isFour[i] = 1;
                    } else {
                        isFour[i] = 0;
                    }
                }
                if (j == 0) {
                    data->unk_00 = 1;
                } else {
                    data->unk_00 = 12;
                }
                break;
            case 12:
                func_8004B304_4BF04(saved);
                PlaySound(0x353);
                for (i = 0; i < 24; i++) {
                    for (j = 0; j < 4; j++) {
                        if (isFour[j]) {
                            func_80060034_60C34(j, i + 5);
                        }
                    }
                    HuPrcVSleep();
                }
                for (i = 0; i < 4; i++) {
                    if (func_800600C0_60CC0(i) != saved[i]) {
                        func_80060034_60C34(i, saved[i]);
                    }
                }
                data->unk_00 = 1;
                break;
            case 1:
                omDelPrcObj(NULL);
                break;
        }
        HuPrcVSleep();
    }
}

Process* func_8004C00C_4CC0C(s32 arg0) {
    Process* process;
    unkUserData_00* userData;

    process = omAddPrcObj(func_8004BE4C_4CA4C, 0, 0x2000, 0x40);
    userData = HuMemMemoryAlloc(process->heap, sizeof(unkUserData_00));
    process->user_data = userData;
    userData->unk_00 = 10;
    return process;
}

INCLUDE_ASM("asm/nonmatchings/4ABB0", func_8004C060_4CC60);

void MBCoinChangeInit(void) {
    s32 i, j;

    for (i = 0; i < UNK_SIZE; i++) {
        D_800DF6E0_E02E0[i] = -1;
        D_800DF6F8_E02F8[i] = 0;
        for (j = 0; j < UNK_SIZE2; j++) {
            D_800DF6E8_E02E8[i][j] = -1;
        }
    }
}

void MBCoinChangeKill(s32 arg0) {
    s32 i;

    if (D_800DF6E0_E02E0[arg0] != -1) {
        SprKill(D_800DF6E0_E02E0[arg0]);
        D_800DF6E0_E02E0[arg0] = -1;
    }
    if (D_800DF6F8_E02F8[arg0] != 0) {
        omDelObj(D_800DF6F8_E02F8[arg0]);
        D_800DF6F8_E02F8[arg0] = 0;
    }

    for (i = 0; i < UNK_SIZE2; i++) {
        if (D_800DF6E8_E02E8[arg0][i] != -1) {
            SprAnimKill(D_800DF6E8_E02E8[arg0][i]);
            D_800DF6E8_E02E8[arg0][i] = -1;
        }
    }
}

void func_8004C394_4CF94(void) {
    s32 i;

    for (i = 0; i < UNK_SIZE; i++) {
        MBCoinChangeKill(i);
    }
}

INCLUDE_ASM("asm/nonmatchings/4ABB0", func_8004C3CC_4CFCC);

void func_8004CA14_4D614(s32 arg0) {
    D_800DF708_E0308 = 0;
    func_8004C3CC_4CFCC(arg0);
}

void func_8004CA34_4D634(s32 arg0) {
    D_800DF708_E0308 = 1;
    func_8004C3CC_4CFCC(arg0);
}
