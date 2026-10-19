#include "common.h"
#include "process.h"
#include "game/malloc.h"

/* Board player position, facing and movement helpers (MP1 src/4D770.c; MP3
   src/overlays/ovl_80_shared_board/1006F0.c). Names follow MP1 where it names them, MP3 otherwise. */

typedef struct BoardObjUnk3C {
    /* 0x00 */ char unk_00[0x24];
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
} BoardObjUnk3C;

typedef struct Object {
    /* 0x00 */ char unk_00[0xC];
    /* 0x0C */ Vec coords;
    /* 0x18 */ Vec unk_18;
    /* 0x24 */ char unk_24[0x18];
    /* 0x3C */ BoardObjUnk3C* unk_3C;
} Object;

typedef struct BoardCamera {
    /* 0x00 */ char unk_00[0xC];
    /* 0x0C */ Vec pos;
} BoardCamera;

typedef struct unkProcessUserDataStruct {
    Vec unk_00;
    Vec unk_0C;
    Vec* unk_18;
    union {
        f32 floatUnk1C;
        s32 signed32Unk1C;
    } unk_1C;
} unkProcessUserDataStruct;

#define PLAYER_OBJ(player) ((Object*)(player)->unk_24)

extern Vec2f D_800CC5C0_CD1C0[4];
extern s32 D_800CC5E0_CD1E0[3];
extern BoardCamera* D_800C9B80_CA780;
extern s8 ContStkX[];
extern s8 ContStkY[];
extern s16 D_800F8D12_F9912;

SpaceData* GetSpaceData(s16);
GW_PLAYER* BoardPlayerGet(s32);
s16 func_80054BB0_557B0(u16, u16);
void func_800576F8_582F8(s32);
s16 func_80062CCC_638CC(void);
void func_80067040_67C40(s32, s32, s32);
f32 func_80042BE0_437E0(Vec*);
void MBVecNormalize(Vec*);
void func_80042E44_43A44(Vec*, f32);
f32 func_800431FC_43DFC(Vec*, Vec*);
void HuVecCopyXYZ(Vec*, f32, f32, f32);
void func_800B3170_B3D70(Vec*, Vec*);
void HuVecAdd(Vec*, Vec*, Vec*);
void HuVecSubtract(Vec*, Vec*, Vec*);
void HuVecMulScalar(Vec*, f32, Vec*);
f32 HuVecGetLength3F(Vec*);
f32 HuVecDistance(Vec*, Vec*);
void func_80056658_57258(Vec* arg0, Vec* arg1, Vec* arg2);
void MBMasuPosGet(s16 playerNo, s16 spaceIdx, Vec* out);

void MBMasuPosGet(s16 playerNo, s16 spaceIdx, Vec* out) {
    SpaceData* space = GetSpaceData(spaceIdx);

    out->x = space->coords.x;
    out->y = space->coords.y;
    out->z = space->coords.z;
}

void func_80056594_57194(s16 arg0, s16 arg1, Vec* arg2) {
    SpaceData* space;

    space = GetSpaceData(arg1);
    arg2->x = (space->coords.x + D_800CC5C0_CD1C0[arg0].unk_00);
    arg2->y = space->coords.y;
    arg2->z = (space->coords.z + D_800CC5C0_CD1C0[arg0].unk_04);
}

void func_8005660C_5720C(s16 arg0, s16 arg1) {
    MBMasuPosGet(arg0, arg1, &PLAYER_OBJ(&gPlayers[arg0])->coords);
}

void func_80056658_57258(Vec* arg0, Vec* arg1, Vec* arg2) {
    HuVecSubtract(arg2, arg1, arg0);
    MBVecNormalize(arg2);
}

void func_80056690_57290(s16 playerIdx, Vec* arg1) {
    Object* playerObj;

    playerObj = PLAYER_OBJ(BoardPlayerGet(playerIdx));
    func_80056658_57258(&playerObj->coords, arg1, &playerObj->unk_18);
}

void func_800566D0_572D0(Object* arg0, s16 arg1) {
    func_80056658_57258(&arg0->coords, &GetSpaceData(arg1)->coords, &arg0->unk_18);
}

void func_8005670C_5730C(Vec* arg0) {
    arg0->x = 0.0f;
    arg0->y = 0.0f;
    arg0->z = 1.0f;
}

void MBPlayerForwardSet(s16 playerNo) {
    func_8005670C_5730C(&PLAYER_OBJ(BoardPlayerGet(playerNo))->unk_18);
}

void func_80056754_57354(Object* unk) {
    Vec sp10;
    Vec sp20;

    HuVecSubtract(&sp10, &D_800C9B80_CA780->pos, &unk->coords);
    HuVecCopyXYZ(&sp20, sp10.x, 0.0f, sp10.z);
    unk->unk_3C->unk_24 = -func_800431FC_43DFC(&sp10, &sp20);
    func_80056658_57258(&unk->coords, &D_800C9B80_CA780->pos, &sp10);
    unk->unk_3C->unk_28 = func_80042BE0_437E0(&sp10);
    unk->unk_3C->unk_2C = 0.0f;
}

void SwapPlayerLocationData(s16 arg0, s16 arg1) {
    GW_PLAYER* player1;
    GW_PLAYER* player2;
    u16 temp;

    player1 = BoardPlayerGet(arg0);
    player2 = BoardPlayerGet(arg1);
    temp = player1->cur_chain_index;
    player1->cur_chain_index = player2->cur_chain_index;
    player2->cur_chain_index = temp;
    temp = player1->cur_space_index;
    player1->cur_space_index = player2->cur_space_index;
    player2->cur_space_index = temp;
    temp = player1->next_chain_index;
    player1->next_chain_index = player2->next_chain_index;
    player2->next_chain_index = temp;
    temp = player1->next_space_index;
    player1->next_space_index = player2->next_space_index;
    player2->next_space_index = temp;
}

void func_80056884_57484(s16 playerNo, s16 spaceType) {
    GW_PLAYER* player = BoardPlayerGet(playerNo);
    u8 newColor;

    switch (spaceType) {
    case 1:
        newColor = 1;
        break;
    case 2:
    case 12:
        newColor = 2;
        break;
    case 0:
    case 4:
    case 5:
    case 6:
    case 7:
    case 9:
        newColor = 4;
        break;
    default:
        newColor = 0;
        break;
    }
    player->player_space_color = newColor;
}

s16 GetSumOfPlayerStars(void) {
    s32 starTotal = 0;
    s32 i;

    for (i = 0; i < 4; i++) {
        starTotal += BoardPlayerGet(i)->stars;
    }

    return starTotal;
}

s16 RNGPercentChance(s8 arg0) {
    return arg0 > ((rand8() * 99) >> 8);
}

s16 GetTurnsElapsed(void) {
    GW_SYSTEM* gameStatus = &GwSystem;
    return gameStatus->total_turns - gameStatus->current_turn + 1;
}

s32 func_800569B8_575B8(s16 arg0, f32 arg1) {
    Vec sp10;

    sp10.x = ContStkX[arg0];
    sp10.y = 0.0f;
    sp10.z = ContStkY[arg0];

    if ((arg1 <= HuVecGetLength3F(&sp10))) {
        return 1;
    } else {
        return 0;
    }
}

void func_80056A3C_5763C(s16 arg0) {
    func_800576F8_582F8(D_800CC5E0_CD1E0[arg0]);
}

void func_80056A68_57668(void) {
    unkProcessUserDataStruct *temp_s0 = HuPrcCurrentGet()->user_data;
    s32 temp_s1 = temp_s0->unk_1C.signed32Unk1C;
    f32 temp_f20 = func_80042BE0_437E0(&temp_s0->unk_00);
    f32 new_var = func_80042BE0_437E0(&temp_s0->unk_0C) - temp_f20;
    f32 var_f2;

    if (new_var < 0.0f) {
        new_var += 360.0f;
    }

    var_f2 = func_800431FC_43DFC(&temp_s0->unk_00, &temp_s0->unk_0C) / temp_s1;

    if (!(new_var < 180.0f)) {
        var_f2 = -var_f2;
    }

    new_var = var_f2;
    temp_f20 = 0.0f;

    while (temp_s0->unk_1C.signed32Unk1C != 0) {
        func_800B3170_B3D70(temp_s0->unk_18, &temp_s0->unk_00);
        temp_f20 += new_var;
        func_80042E44_43A44(temp_s0->unk_18, temp_f20);
        temp_s0->unk_1C.signed32Unk1C = temp_s0->unk_1C.signed32Unk1C - 1;
        HuPrcVSleep();
    }

    omDelPrcObj(0);
}

Process* func_80056B78_57778(Vec* arg0, Vec* arg1, Vec* arg2, s32 arg3) {
    Process* temp_s1;
    unkProcessUserDataStruct* temp_s0;

    temp_s1 = omAddPrcObj(func_80056A68_57668, 0x4001, 0, 0x50);
    temp_s0 = HuMemMemoryAlloc(temp_s1->heap, sizeof(unkProcessUserDataStruct));
    temp_s1->user_data = temp_s0;
    HuVecCopyXYZ(&temp_s0->unk_00, arg0->x, 0.0f, arg0->z);
    HuVecCopyXYZ(&temp_s0->unk_0C, arg1->x, 0.0f, arg1->z);
    temp_s0->unk_18 = arg2;
    temp_s0->unk_1C.signed32Unk1C = arg3;
    return temp_s1;
}

void func_80056C30_57830(s16 playerNo, s32 arg1, s16 masuAbsIndex) {
    GW_PLAYER* player = BoardPlayerGet(playerNo);
    Vec sp10;

    HuVecSubtract(&sp10, &GetSpaceData(masuAbsIndex)->coords, &PLAYER_OBJ(player)->coords);
    MBVecNormalize(&sp10);
    func_80056B78_57778(&PLAYER_OBJ(player)->unk_18, &sp10, &PLAYER_OBJ(player)->unk_18, arg1);
}

void func_80056CB4_578B4(void) {
    unkProcessUserDataStruct* temp_s0 = HuPrcCurrentGet()->user_data;
    s32 temp_s1 = temp_s0->unk_1C.signed32Unk1C;

    while (temp_s0->unk_1C.signed32Unk1C != 0) {
        HuVecSubtract(temp_s0->unk_18, &temp_s0->unk_0C, &temp_s0->unk_00);
        HuVecMulScalar(temp_s0->unk_18, 1.0f - (1.0f / temp_s1) * (temp_s0->unk_1C.signed32Unk1C - 1), temp_s0->unk_18);
        HuVecAdd(temp_s0->unk_18, temp_s0->unk_18, &temp_s0->unk_00);
        temp_s0->unk_1C.signed32Unk1C = temp_s0->unk_1C.signed32Unk1C - 1;
        HuPrcVSleep();
    }
    omDelPrcObj(NULL);
}

Process* func_80056D80_57980(Vec* arg0, Vec* arg1, Vec* arg2, s32 arg3) {
    Process* temp_s1;
    unkProcessUserDataStruct* temp_s0;

    temp_s1 = omAddPrcObj(func_80056CB4_578B4, 0x4001, 0, 0x50);
    temp_s0 = HuMemMemoryAlloc(temp_s1->heap, sizeof(*temp_s0));
    temp_s1->user_data = temp_s0;
    temp_s0->unk_00 = *arg0;
    temp_s0->unk_0C = *arg1;
    temp_s0->unk_18 = arg2;
    temp_s0->unk_1C.signed32Unk1C = arg3;
    return temp_s1;
}

void func_80056E34_57A34(s16 arg0, s32 arg1) {
    Vec sp10;
    Vec sp20;
    GW_PLAYER* temp_v0;
    Process* process;

    temp_v0 = BoardPlayerGet(arg0);
    MBMasuPosGet(arg0, func_80054BB0_557B0(temp_v0->cur_chain_index, temp_v0->cur_space_index), &sp10);
    MBMasuPosGet(arg0, func_80054BB0_557B0(temp_v0->next_chain_index, temp_v0->next_space_index), &sp20);
    func_80056658_57258(&sp10, &sp20, &PLAYER_OBJ(temp_v0)->unk_18);
    process = func_80056D80_57980(&sp10, &sp20, &PLAYER_OBJ(temp_v0)->coords, arg1);
    HuPrcChildLink(HuPrcCurrentGet(), process);
    HuPrcChildWatch();
}

void func_80056F0C_57B0C(void) {
    unkProcessUserDataStruct* temp_s0 = HuPrcCurrentGet()->user_data;
    Vec* temp_s1;
    f32 temp_f20;

    temp_f20 = temp_s0->unk_1C.floatUnk1C;
    temp_s1 = &temp_s0->unk_0C;

    while (!(HuVecDistance(&temp_s0->unk_00, temp_s1) < temp_f20)) {
        HuVecSubtract(temp_s0->unk_18, temp_s1, &temp_s0->unk_00);
        MBVecNormalize(temp_s0->unk_18);
        HuVecMulScalar(temp_s0->unk_18, temp_f20, temp_s0->unk_18);
        HuVecAdd(temp_s0->unk_18, temp_s0->unk_18, &temp_s0->unk_00);
        func_800B3170_B3D70(&temp_s0->unk_00, temp_s0->unk_18);
        HuPrcVSleep();
    }
    func_800B3170_B3D70(temp_s0->unk_18, &temp_s0->unk_0C);
    omDelPrcObj(NULL);
}

Process* func_80056FD4_57BD4(Vec* arg0, Vec* arg1, Vec* arg2, f32 arg3) {
    Process* temp_s1;
    unkProcessUserDataStruct* temp_s0;

    temp_s1 = omAddPrcObj(func_80056F0C_57B0C, 0x4001, 0, 0x50);
    temp_s0 = HuMemMemoryAlloc(temp_s1->heap, sizeof(*temp_s0));
    temp_s1->user_data = temp_s0;
    temp_s0->unk_00 = *arg0;
    temp_s0->unk_0C = *arg1;
    temp_s0->unk_18 = arg2;
    temp_s0->unk_1C.floatUnk1C = arg3;
    return temp_s1;
}

void func_80057088_57C88(void) {
    unkProcessUserDataStruct* temp_s0 = HuPrcCurrentGet()->user_data;
    f32 temp_f20 = temp_s0->unk_1C.floatUnk1C;
    s32 var_s1 = 0;

    while (1) {
        if (HuVecDistance(&temp_s0->unk_00, &temp_s0->unk_0C) < temp_f20) {
            var_s1 = 1;
        }
        HuVecSubtract(temp_s0->unk_18, &temp_s0->unk_0C, &temp_s0->unk_00);
        MBVecNormalize(temp_s0->unk_18);
        HuVecMulScalar(temp_s0->unk_18, temp_f20, temp_s0->unk_18);
        HuVecAdd(temp_s0->unk_18, temp_s0->unk_18, &temp_s0->unk_00);
        func_800B3170_B3D70(&temp_s0->unk_00, temp_s0->unk_18);

        if (var_s1 != 0) {
            break;
        }
        HuPrcVSleep();
    }

    omDelPrcObj(NULL);
}

Process* func_80057150_57D50(Vec* arg0, Vec* arg1, Vec* arg2, f32 arg3) {
    Process* temp_s1;
    unkProcessUserDataStruct* temp_s0;

    temp_s1 = omAddPrcObj(func_80057088_57C88, 0x4001, 0, 0x50);
    temp_s0 = HuMemMemoryAlloc(temp_s1->heap, sizeof(*temp_s0));
    temp_s1->user_data = temp_s0;
    temp_s0->unk_00 = *arg0;
    temp_s0->unk_0C = *arg1;
    temp_s0->unk_18 = arg2;
    temp_s0->unk_1C.floatUnk1C = arg3;
    return temp_s1;
}

void func_80057204_57E04(s16 arg0, f32 arg1) {
    Vec sp10;
    Vec sp20;
    GW_PLAYER* temp_v0;
    Process* process;

    temp_v0 = BoardPlayerGet(arg0);
    MBMasuPosGet(arg0, func_80054BB0_557B0(temp_v0->cur_chain_index, temp_v0->cur_space_index), &sp10);
    MBMasuPosGet(arg0, func_80054BB0_557B0(temp_v0->next_chain_index, temp_v0->next_space_index), &sp20);
    func_80056658_57258(&sp10, &sp20, &PLAYER_OBJ(temp_v0)->unk_18);
    process = func_80056FD4_57BD4(&sp10, &sp20, &PLAYER_OBJ(temp_v0)->coords, arg1);
    HuPrcChildLink(HuPrcCurrentGet(), process);
    HuPrcChildWatch();
}

void SetPlayerOntoChain(s16 player, s16 chain_index, s16 space_index) {
    GW_PLAYER* temp_v1 = BoardPlayerGet(player);

    if (chain_index >= 0) {
        temp_v1->cur_chain_index = chain_index;
        temp_v1->next_chain_index = chain_index;
    }
    if (space_index >= 0) {
        temp_v1->cur_space_index = space_index;
        temp_v1->next_space_index = space_index + 1;
    }
}

void SetNextChainAndSpace(s16 arg0, s16 arg1, s16 arg2) {
    GW_PLAYER* temp_v0 = BoardPlayerGet(arg0);

    if (arg1 >= 0) {
        temp_v0->next_chain_index = arg1;
    }
    if (arg2 >= 0) {
        temp_v0->next_space_index = arg2;
    }
}

s32 func_800573AC_57FAC(void) {
    s32 ret = 0;

    _SetFlag(GwSystem.unk_1A);
    _SetFlag(0x4D);
    D_800F8D12_F9912 = 0;
    if (func_80062CCC_638CC() == 1) {
        if (_CheckFlag(0x43) != 0) {
            func_80062A70_63670(-2, 4, 0x192);
            ret = 1;
        }
    } else if (_CheckFlag(0x43) != 0) {
        func_80067040_67C40(-2, 4, 2);
        ret = 1;
    }
    return ret;
}

INCLUDE_ASM("asm/nonmatchings/57150", func_80057448_58048);
