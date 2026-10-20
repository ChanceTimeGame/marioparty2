#include "common.h"
#include "game/data.h"
#include "game/malloc.h"
#include "game/board.h"

void func_8008225C_82E5C(s16, s16, s32);
void func_800822A8_82EA8(s16, s16, u16, s32);
void SprScaleSet(s16, s16, f32, f32);

void func_80060B04_61704(void);
s32 func_8004FDD0_509D0(void);
void MBVsSprKill(void);

typedef struct Rect4ABB0 {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
    /* 0x04 */ s16 w;
    /* 0x06 */ s16 h;
} Rect4ABB0;

/* Minigame lists per type (lengths D_800CBDC8_CC9C8) and window rectangles per type. */
extern u8 D_800CBCD0_CC8D0[];
extern u8 D_800CBCE8_CC8E8[];
extern u8 D_800CBCF4_CC8F4[];
extern u8 D_800CBD00_CC900[];
extern u8 D_800CBD08_CC908[];
extern u8 D_800CBD0C_CC90C[];
extern Rect4ABB0 D_800CBD20_CC920[];
extern Rect4ABB0 D_800CBD38_CC938[];
extern u8 D_800CBD77_CC977[]; /* one byte per minigame id from 1: indexed by the id */
extern u8 D_800CBDC8_CC9C8[];
s32 func_80060A1C_6161C(void);
s16 func_80068040_68C40(s16);
s16 func_800888A8_894A8(s16, s16, s16, s16, s32, s16);
void func_8008D88C_8E48C(s16);
void func_800898F0_8A4F0(s16, s32, s32);

extern u8 D_800CBD10_CC910[];
extern u8 D_800CBD18_CC918[];
extern s8 D_800CBD70_CC970[][2];
extern s8 D_800DF6C0_E02C0[];
void func_800896DC_8A2DC(s16, s16, s16);
void func_8008D530_8E130(s16, u8, u8, u8);
void func_80089B2C_8A72C(s16, s16);
void func_80089A7C_8A67C(s16, s16);
void func_8008AD84_8B984(void);
void func_8008AD44_8B944(s16);
void func_800890CC_89CCC(s16, s32, s32, s32);
void func_80089C78_8A878(s16, s32);
void func_80089DA0_8A9A0(s16, s32, s32, s32);
void func_80089A48_8A648(s16, s16);
void func_80067E6C_68A6C(s16);
void func_8004FDE0_509E0(void);
void func_8004AC60_4B860(void);
void func_8004A9EC_4B5EC(void);

/* Board HUD and minigame-pick helpers: the minigame roulette (MP1 src/43760.c func_80042B60 ..
   func_800448A0), MBArrayShuffle and MBMgCallBattleExec (MP3 ovl_80_shared_board F2910.c), the
   coin-change popup (MP3 F5070.c MBCoinChange*). Rodata D3220-D3430 carved; the SJIS strings after
   it (D3430-, reached only from .data) stay in the blob. */

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
void func_8004C3CC_4CFCC(s32, s32);
void func_80060034_60C34(s32, s32);
s32 func_800600C0_60CC0(s32);
s32 func_800609D8_615D8(void);
void func_80060210_60E10(s32);
void func_8004FA40_50640(s32);
void func_8004B214_4BE14(void);
void func_8004BBFC_4C7FC(void);
void MBCoinChangeKill(s32);
void MBDCamera3Dto2D(Vec*, Vec2f*);
extern Vec2f D_800CBDD0_CC9D0[];
extern u16 ContBtnTrg[4];
void func_80082450_83050(s16, s32, s32, s32, u8);
void func_8008CCA8_8D8A8(s16);


void func_80049FB0_4ABB0(void) {
    if (D_800FDC6C_FE86C >= (D_800CBDC4_CC9C4 + 4)) {
        PlaySound(0x324);
        D_800CBDC4_CC9C4 = D_800FDC6C_FE86C;
    }
}

//same as func_800DED3C_F295C_shared_board in mp3
/* Minigame roulette object (MP1 func_80042BAC): scrolls the list in, spins and slows the cursor,
   then records the pick in the history table. */
void func_80049FFC_4ABFC(omObjData* obj) {
    s32 i;
    unk43760* p;

    switch (obj->work[0]) {
        case 0:
            obj->trans.y += 16.0f;
            for (i = 0; i < D_800CBD10_CC910[D_800DF6C5_E02C5]; i++) {
                p = &D_800DF660_E0260[i];
                func_800896DC_8A2DC(p->unk_00, p->unk_04 + p->unk_08 / 2, (s32)-obj->trans.y + p->unk_06 + p->unk_0A / 2);
            }
            SprPosSet(D_800DF6C6_E02C6, 0, 160, (s32)-obj->trans.y + D_800DF664_E0264 + D_800CBD60_CC960[D_800DF6C5_E02C5]);
            if (obj->trans.y > 218.0f) {
                func_80049FB0_4ABB0();
                obj->work[0] = 1;
                obj->scale.x = 1.0f;
                obj->scale.z = -1.0f;
                obj->scale.y = 0.0f;
                obj->work[1] = 0;
                obj->work[2] = MBRand(D_800CBD10_CC910[D_800DF6C5_E02C5]);
                obj->work[3] = 0;
                func_8004AC60_4B860();
            }
            break;
        case 1:
            obj->scale.z += obj->scale.x;
            if (obj->scale.z >= 1.0f) {
                if (obj->work[3] != 0 && obj->scale.x <= 0.08f) {
                    obj->work[3]--;
                }
                obj->scale.z -= 1.0f;
                if (obj->scale.y == 0.0f) {
                    obj->work[1]++;
                    obj->work[1] %= D_800CBD10_CC910[D_800DF6C5_E02C5];
                } else {
                    obj->work[1]--;
                    if (obj->work[1] >= 128) {
                        obj->work[1] = D_800CBD10_CC910[D_800DF6C5_E02C5] - 1;
                    }
                }
                func_80049FB0_4ABB0();
            }
            for (i = 0; i < D_800CBD10_CC910[D_800DF6C5_E02C5]; i++) {
                p = &D_800DF660_E0260[i];
                if (i == obj->work[1]) {
                    func_8008D530_8E130(p->unk_00, 0, 200, 0);
                    func_80089B2C_8A72C(p->unk_00, 0x100);
                    func_80089A7C_8A67C(p->unk_00, 9000);
                } else {
                    func_8008D530_8E130(p->unk_00, 0x40, 0x40, 0x80);
                    func_80089B2C_8A72C(p->unk_00, 0);
                    func_80089A7C_8A67C(p->unk_00, 10000);
                }
            }
            if (obj->work[1] == obj->work[2] || obj->scale.x < 1.0f) {
                obj->scale.x -= 0.02;
            }
            if (obj->scale.x <= 0.08f) {
                obj->scale.x = 0.08f;
                if (obj->work[1] == obj->work[2] && obj->work[3] == 0 && obj->scale.z + obj->scale.x >= 1.0f) {
                    if ((rand8() & 0xF) || obj->scale.y == 1.0f || obj->work[1] == 0) {
                        if (GwSystem.unk_25 == 0 || GwSystem.current_board_index == 8) {
                            PlaySound(0x325);
                        } else {
                            PlaySound(0x374);
                        }
                        obj->work[0] = 2;
                        obj->work[3] = 60;
                        func_8008AD84_8B984();
                        func_8008AD44_8B944(D_800DF660_E0260[obj->work[1]].unk_00);
                        func_800890CC_89CCC(D_800DF660_E0260[obj->work[1]].unk_00, D_800DF6C0_E02C0[obj->work[1]] + 0x3D8, -2, 4);
                        switch (D_800DF6C0_E02C0[obj->work[1]]) {
                            case 25:
                            case 36:
                            case 56:
                            case 71:
                            case 72:
                                func_80089C78_8A878(D_800DF660_E0260[obj->work[1]].unk_00, 4);
                                break;
                            default:
                                func_80089C78_8A878(D_800DF660_E0260[obj->work[1]].unk_00, 1);
                                break;
                        }
                        func_80089DA0_8A9A0(D_800DF660_E0260[obj->work[1]].unk_00, 0xA0, 0xA0, 0xA0);
                        func_8008D530_8E130(D_800DF660_E0260[obj->work[1]].unk_00, 0xFE, 0xFF, 0xD0);
                        func_80089A48_8A648(D_800DF660_E0260[obj->work[1]].unk_00, 0);
                    } else {
                        obj->scale.y = 1.0f;
                        obj->work[2]--;
                        if (obj->work[2] >= 128) {
                            obj->work[2] = D_800CBD10_CC910[D_800DF6C5_E02C5] - 1;
                        }
                    }
                }
            }
            break;
        case 2:
            if (obj->work[3] != 0) {
                obj->work[3]--;
            } else {
                D_800DF698_E0298[D_800DF6C5_E02C5][D_800DF6B6_E02B6[D_800DF6C5_E02C5]] = D_800DF6C0_E02C0[obj->work[2]];
                D_800DF6B6_E02B6[D_800DF6C5_E02C5]++;
                D_800DF6B6_E02B6[D_800DF6C5_E02C5] %= D_800CBD18_CC918[D_800DF6C5_E02C5];
                func_80067E6C_68A6C(D_800DF6C0_E02C0[obj->work[2]]);
                if (GwSystem.current_board_index != 8) {
                    func_8004FDE0_509E0();
                    func_8004A9EC_4B5EC();
                }
            }
            obj->rot.z += 1.0f;
            if (obj->rot.z >= 13.0f) {
                obj->rot.z -= 13.0f;
            }
            break;
    }
    if (D_800DF6CA_E02CA != -1) {
        for (i = 0; !(obj->rot.z < (*(D_800CBD70_CC970 + i))[0]); i++) {
        }
        SprPosSet(D_800DF6CA_E02CA, 0, D_800CBD70_CC970[i][1] + 50, D_800CBD68_CC968[D_800DF6C5_E02C5] + obj->work[1] * 20);
    }
}
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

/* Minigame roulette setup (MP1 func_8004388C): picks the minigame type (arg0: 0 = 4P, 1 = 1v3,
   2 = 2v2, -1 = from func_80060A1C), fills one window per slot with a minigame not already
   offered or recently played (some are kept out of the early turns, two need func_80068040),
   then starts func_80049FFC. */
void func_8004AD34_4B934(s32 arg0) {
    Rect4ABB0* rects[6] = { D_800CBD38_CC938, D_800CBD20_CC920, D_800CBD20_CC920,
                            D_800CBD38_CC938, D_800CBD20_CC920, D_800CBD20_CC920 };
    u8* lists[6] = { D_800CBCD0_CC8D0, D_800CBCE8_CC8E8, D_800CBCF4_CC8F4,
                     D_800CBD08_CC908, D_800CBD00_CC900, D_800CBD0C_CC90C };
    s32 i;
    s32 j;
    s32 k;
    s32 sel;
    unk43760* p;
    omObjData* obj;

    switch (arg0) {
        case 0:
            sel = 3;
            break;
        case -1:
            sel = func_80060A1C_6161C();
            if (sel != -1) {
                break;
            }
        default:
            sel = 3;
            break;
        case 2:
            sel = 5;
            break;
        case 1:
            sel = 4;
            break;
    }
    D_800DF6C5_E02C5 = sel;
    for (i = 0; i < D_800CBD10_CC910[sel]; i++) {
        p = &D_800DF660_E0260[i];
        p->unk_04 = rects[sel][i].x;
        p->unk_06 = rects[sel][i].y;
        p->unk_08 = rects[sel][i].w;
        p->unk_0A = rects[sel][i].h;
        p->unk_00 = func_800888A8_894A8(p->unk_04 + p->unk_08 / 2, p->unk_06 + p->unk_0A / 2, p->unk_08, p->unk_0A, 0, 4);
        func_80089A7C_8A67C(p->unk_00, 9000);
        func_8008D88C_8E48C(p->unk_00);
        func_800898F0_8A4F0(p->unk_00, p->unk_08 / 2, p->unk_0A / 2);
        func_80089B2C_8A72C(p->unk_00, 0);
        while (1) {
            D_800DF6C0_E02C0[i] = lists[sel][MBRand(D_800CBDC8_CC9C8[sel])];
            for (j = 0; j < i; j++) {
                if (j != i && D_800DF6C0_E02C0[j] == D_800DF6C0_E02C0[i]) {
                    break;
                }
            }
            if (j != i) {
                continue;
            }
            for (k = 0; k < D_800CBD18_CC918[sel]; k++) {
                if (D_800DF6C0_E02C0[i] == D_800DF698_E0298[sel][k]) {
                    break;
                }
            }
            if (k != D_800CBD18_CC918[sel]) {
                continue;
            }
            switch (GwSystem.current_game_length) {
                case 0:
                    if (GwSystem.current_turn >= 6) {
                        break;
                    }
                case 1:
                    if (GwSystem.current_turn >= 21) {
                        break;
                    }
                case 2:
                    if (GwSystem.current_turn >= 36) {
                        break;
                    }
                    switch (D_800DF6C0_E02C0[i]) {
                        case 25:
                        case 36:
                        case 56:
                        case 71:
                        case 72:
                            continue;
                    }
                    break;
            }
            switch (D_800DF6C0_E02C0[i]) {
                case 16:
                case 35:
                    if (func_80068040_68C40(D_800DF6C0_E02C0[i] - 1) == 0) {
                        continue;
                    }
                    break;
            }
            break;
        }
        func_8008AD84_8B984();
        func_800890CC_89CCC(p->unk_00, D_800DF6C0_E02C0[i] + 0x3D8, -2, 4);
        func_80089C78_8A878(p->unk_00, D_800CBD77_CC977[D_800DF6C0_E02C0[i]]);
        func_80089A48_8A648(p->unk_00, 0);
    }
    obj = omAddObj(-0x8000, 0, 0, -1, func_80049FFC_4ABFC);
    D_800DF6BC_E02BC = obj;
    obj->work[0] = 3;
    obj->trans.y = 0.0f;
    obj->rot.z = 0.0f;
    func_8004AB24_4B724();
}
/* Starts the roulette: the object's state 0 scrolls the list in. */
void func_8004B214_4BE14(void) {
    D_800DF6BC_E02BC->work[0] = 0;
}

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

/* Minigame-roulette process (MP1 func_800441D4). */
void func_8004B65C_4C25C(void) {
    u8 isFour[4];
    u8 saved[4];
    unkUserData_00* data;
    s32 i;
    s32 j;

    data = HuPrcCurrentGet()->user_data;
    while (1) {
        switch (data->unk_00) {
            case 0:
                func_80060210_60E10(4);
                data->unk_00 = 10;
                break;
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
                if (j != 0) {
                    data->unk_00 = 12;
                } else {
                    data->unk_00 = 1;
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
                if (func_800609D8_615D8() == 0) {
                    HuPrcSleep(1);
                    func_8004FA40_50640(0);
                    HuPrcSleep(5);
                    data->unk_00++;
                }
                break;
            case 2:
                func_80060210_60E10(2);
                func_80060B04_61704();
                data->unk_00++;
                break;
            case 3:
                if (func_800609D8_615D8() == 0) {
                    for (i = 0; i < 4; i++) {
                        if (!(gPlayers[i].flags & 1)) {
                            break;
                        }
                    }
                    if (i != 4) {
                        for (i = 0; i < 4; i++) {
                            if ((ContBtnTrg[gPlayers[i].port] & 0x8000) && !(gPlayers[i].flags & 1)) {
                                break;
                            }
                        }
                        if (i == 4) {
                            break;
                        }
                    }
                    if (func_80060A1C_6161C() != -1) {
                        func_8004B214_4BE14();
                        func_80060210_60E10(5);
                    } else {
                        func_80067E6C_68A6C(-1);
                    }
                    data->unk_00++;
                }
                break;
            case 4:
                if (func_80060A1C_6161C() == -1 || func_8004FDD0_509D0() == 0) {
                    MBVsSprKill();
                    omDelPrcObj(NULL);
                }
                break;
        }
        HuPrcVSleep();
    }
}
Process* func_8004B974_4C574(void) {
    Process* process;
    s32* data;

    process = omAddPrcObj(&func_8004B65C_4C25C, 0, 0x2000, 0x40);
    data = HuMemMemoryAlloc(process->heap, 16);
    process->user_data = data;
    *data = 0;
    return process;
}

/* near MP1 func_8004452C (src/43760.c): MP2 also passes unk_08 on. */
void func_8004B9C4_4C5C4(void) {
    unkUserData_00* temp_s0 = HuPrcCurrentGet()->user_data;
    u16* temp = ContBtnTrg;

loop_1:
    switch (temp_s0->unk_00) {
    case 0:
        func_80060210_60E10(temp_s0->unk_04 + 6);
        func_8004FA40_50640(temp_s0->unk_08);
        temp_s0->unk_00++;
        break;
    case 1:
        if (func_800609D8_615D8() == 0) {
            if (temp[gPlayers[temp_s0->unk_04].port] & 0x8000) {
                if (!(gPlayers[temp_s0->unk_04].flags & 1)) {
                    func_8004B214_4BE14();
                    func_80060210_60E10(5);
                    temp_s0->unk_00++;
                    break;
                }
            }

            if (gPlayers[temp_s0->unk_04].flags & 1) {
                func_8004B214_4BE14();
                func_80060210_60E10(5);
                temp_s0->unk_00++;
            }
        }
        break;
    case 2:
        if (D_800DF6C6_E02C6 == -1) {
            omDelPrcObj(NULL);
        }
        break;
    }
    HuPrcVSleep();
    goto loop_1;
}

/* near MP1 func_80044680 (src/43760.c): MP2 also stores a mode (1). */
Process* func_8004BB2C_4C72C(s32 arg0) {
    Process* process;
    unkUserData_00* userData;

    process = omAddPrcObj(func_8004B9C4_4C5C4, 0, 0x2000, 0x40);
    userData = HuMemMemoryAlloc(process->heap, sizeof(unkUserData_00));
    process->user_data = userData;
    userData->unk_00 = 0;
    userData->unk_04 = arg0;
    userData->unk_08 = 1;
    return process;
}

/* near MP1 func_80044680 (src/43760.c): MP2 also stores a mode (3). */
Process* func_8004BB94_4C794(s32 arg0) {
    Process* process;
    unkUserData_00* userData;

    process = omAddPrcObj(func_8004B9C4_4C5C4, 0, 0x2000, 0x40);
    userData = HuMemMemoryAlloc(process->heap, sizeof(unkUserData_00));
    process->user_data = userData;
    userData->unk_00 = 0;
    userData->unk_04 = arg0;
    userData->unk_08 = 3;
    return process;
}

/* Battle-minigame announcement process (MP3 MBMgCallBattleExec). */
void func_8004BBFC_4C7FC(void) {
    unkUserData_00* data;
    s32 i;

    data = HuPrcCurrentGet()->user_data;
    while (1) {
        switch (data->unk_00) {
            case 0:
                func_80060210_60E10(4);
                HuPrcSleep(20);
                data->unk_00++;
                break;
            case 1:
                if (func_800609D8_615D8() == 0) {
                    HuPrcSleep(1);
                    func_8004FA40_50640(data->unk_08);
                    HuPrcSleep(5);
                    data->unk_00++;
                }
                /* fallthrough */
            case 2:
                func_80060210_60E10(2);
                func_80060B04_61704();
                data->unk_00++;
                break;
            case 3:
                if (func_800609D8_615D8() == 0) {
                    for (i = 0; i < 4; i++) {
                        if (!(gPlayers[i].flags & 1)) {
                            break;
                        }
                    }
                    if (i != 4) {
                        for (i = 0; i < 4; i++) {
                            if ((ContBtnTrg[gPlayers[i].port] & 0x8000) && !(gPlayers[i].flags & 1)) {
                                break;
                            }
                        }
                        if (i == 4) {
                            break;
                        }
                    }
                    func_8004B214_4BE14();
                    func_80060210_60E10(5);
                    data->unk_00++;
                }
                break;
            case 4:
                if (D_800DF6C6_E02C6 == -1) {
                    MBVsSprKill();
                    omDelPrcObj(NULL);
                }
                break;
        }
        HuPrcVSleep();
    }
}
/* near MP1 func_80044680 (src/43760.c): MP2 also stores a mode (2). */
Process* func_8004BDE4_4C9E4(s32 arg0) {
    Process* process;
    unkUserData_00* userData;

    process = omAddPrcObj(func_8004BBFC_4C7FC, 0, 0x2000, 0x40);
    userData = HuMemMemoryAlloc(process->heap, sizeof(unkUserData_00));
    process->user_data = userData;
    userData->unk_00 = 0;
    userData->unk_04 = arg0;
    userData->unk_08 = 2;
    return process;
}

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

/* near MP1 func_80045500 (src/46100.c): the coin counter rises over the player, or sits at a
   fixed HUD position when D_800DF708 is clear. */
void func_8004C060_4CC60(omObjData* arg0) {
    Vec sp10;
    Vec2f sp20;

    if (D_800DF708_E0308 != 0) {
        sp10.x = ((MBModel*)gPlayers[arg0->work[3]].unk_24)->pos.x;
        sp10.y = ((MBModel*)gPlayers[arg0->work[3]].unk_24)->pos.y + 30.0f;
        sp10.z = ((MBModel*)gPlayers[arg0->work[3]].unk_24)->pos.z;
        MBDCamera3Dto2D(&sp10, &sp20);
    } else {
        sp20.unk_00 = D_800CBDD0_CC9D0[arg0->work[3]].unk_00;
        sp20.unk_04 = D_800CBDD0_CC9D0[arg0->work[3]].unk_04;
    }
    if (arg0->work[0] < 30) {
        if (arg0->rot.x > 0.0f) {
            arg0->trans.y -= 0.5f;
        } else {
            arg0->trans.y += 0.5f;
        }
        SprPosSet(D_800DF6E0_E02E0[arg0->work[3]], 0, (sp20.unk_00 - 16.0f), (sp20.unk_04 + arg0->trans.y));
    } else {
        MBCoinChangeKill(arg0->work[3]);
        return;
    }
    arg0->work[0]++;
}

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

/* Coin-change popup above a player (MP3 func_800E1934 in F5070.c): a coin icon, a +/- sign and up
   to three digits, positioned from the player's model (D_800DF708 set) or a fixed table. */
void func_8004C3CC_4CFCC(s32 player, s32 coins) {
    Vec pos;
    Vec2f pos2d;
    s16 sprId;
    void* data;
    s32 i = 0;

    if (D_800DF6E0_E02E0[player] == -1) {
        if (coins < -999) {
            coins = -999;
        }
        if (coins > 999) {
            coins = 999;
        }
        pos.x = ((MBModel*)gPlayers[player].unk_24)->pos.x;
        pos.y = ((MBModel*)gPlayers[player].unk_24)->pos.y + 30.0f;
        pos.z = ((MBModel*)gPlayers[player].unk_24)->pos.z;
        MBDCamera3Dto2D(&pos, &pos2d);
        D_800DF6F8_E02F8[player] = omAddObj(-0x8000, 0, 0, -1, func_8004C060_4CC60);
        D_800DF6F8_E02F8[player]->work[0] = 0;
        D_800DF6F8_E02F8[player]->rot.x = coins;
        D_800DF6F8_E02F8[player]->trans.x = pos2d.unk_00 - 16.0f;
        D_800DF6F8_E02F8[player]->trans.y = 0.0f;
        D_800DF6F8_E02F8[player]->work[3] = player;
        D_800DF6E0_E02E0[player] = sprId = SprCreate(5, 5);
        data = DataRead(0xA0010);
        D_800DF6E8_E02E8[player][0] = SprAnimRead(data);
        DataClose(data);
        data = DataRead(coins > 0 ? 0xA002B : 0xA002C);
        D_800DF6E8_E02E8[player][1] = SprAnimRead(data);
        DataClose(data);
        SprAnimSet(sprId, i, D_800DF6E8_E02E8[player][0], 0);
        SprPrioSet(sprId, i, 0x2010);
        SprAttrSet(sprId, i, 0x1000);
        if (D_800DF708_E0308 != 0) {
            SprPosSet(sprId, i, pos2d.unk_00 - 16.0f, pos2d.unk_04);
        } else {
            SprPosSet(sprId, i, D_800CBDD0_CC9D0[player].unk_00, D_800CBDD0_CC9D0[player].unk_04);
        }
        SprScaleSet(sprId, i, 0.5f, 0.5f);
        i++;
        SprAnimSet(sprId, i, D_800DF6E8_E02E8[player][1], 0);
        func_8008225C_82E5C(sprId, i, 1);
        if (coins > 0) {
            func_800822A8_82EA8(sprId, i, 10, 0);
        } else {
            func_800822A8_82EA8(sprId, i, 11, 0);
        }
        SprPrioSet(sprId, i, 0x2010);
        SprAttrSet(sprId, i, 0x1000);
        SprPosSet(sprId, i, 16, 0);
        i++;
        coins = (coins < 0) ? -coins : coins;
        if (coins >= 100) {
            SprAnimSet(sprId, i, D_800DF6E8_E02E8[player][1], 0);
            func_8008225C_82E5C(sprId, i, 1);
            func_800822A8_82EA8(sprId, i, coins / 100, 0);
            SprPrioSet(sprId, i, 0x2010);
            SprAttrSet(sprId, i, 0x1000);
            SprPosSet(sprId, i, 32, 0);
            i++;
        }
        if (coins >= 10) {
            SprAnimSet(sprId, i, D_800DF6E8_E02E8[player][1], 0);
            func_8008225C_82E5C(sprId, i, 1);
            func_800822A8_82EA8(sprId, i, (coins / 10) % 10, 0);
            SprPrioSet(sprId, i, 0x2010);
            SprAttrSet(sprId, i, 0x1000);
            SprPosSet(sprId, i, i * 16, 0);
            i++;
        }
        coins %= 10;
        SprAnimSet(sprId, i, D_800DF6E8_E02E8[player][1], 0);
        func_8008225C_82E5C(sprId, i, 1);
        func_800822A8_82EA8(sprId, i, coins, 0);
        SprPrioSet(sprId, i, 0x2010);
        SprAttrSet(sprId, i, 0x1000);
        SprPosSet(sprId, i, i * 16, 0);
        i++;
        for (; i < 5; i++) {
            SprAttrSet(sprId, i, 0x8000);
        }
    }
}
/* arg1 is the coin count, passed through to func_8004C3CC (MP3 MBCoinChangeCreate) */
void func_8004CA14_4D614(s32 arg0, s32 arg1) {
    D_800DF708_E0308 = 0;
    func_8004C3CC_4CFCC(arg0, arg1);
}

/* arg1 is the coin count, passed through to func_8004C3CC (MP3 MBCoinChangeCreate) */
void func_8004CA34_4D634(s32 arg0, s32 arg1) {
    D_800DF708_E0308 = 1;
    func_8004C3CC_4CFCC(arg0, arg1);
}
