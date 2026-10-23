#include "common.h"
#include "game/board.h"

/* Koopa-suit model helpers. C from MP3 ovl_80_shared_board F9DE0.c (MBKSuit*), FA250.c (which kills both
   with omDelPrcObj; MP2 kills a model and an object) and MP1 ovl_33_PaddleBattle 2341E0.c; the rest have no reference (or an asm one) and stay asm. MP3's
   MBKSuitDispOn/Off names are swapped against what they call, so those two keep MP2 names. */

extern MBModel* D_800CC1F0_CCDF0; /* MP1/MP3 Object* */
extern omObjData* D_800CC1F4_CCDF4;

void MBModelKill(void*);
void omDelObj(omObjData*);
void MBModelDispOn(void*);
void MBModelDispOff(void*);
void MBMotionSet(void* arg0, s16 arg1, u16 arg2);
void MBMotionShiftSet(void* arg0, s16 arg1, s32 arg2, s32 arg3, u16 arg4);
void func_800B3170_B3D70(void* dst, void* src); /* HuVecCopy3F */
void func_80054C78_55878(s16, s16*, s16*);
extern void* D_800F64C8_F70C8; /* MP3 D_80105710: an Object* (coords at 0xC) */
extern s16 D_800DF9A0_E05A0;
/* gPlayers[4] (a fifth player slot past the 4-entry array): chain/space index pairs at 0x10 and 0x14 */
extern s16 D_800FD3A0_FDFA0[2];
extern s16 D_800FD3A4_FDFA4[2];
extern void* D_800FD3B4_FDFB4; /* gPlayers[4].unk_24: the fifth slot's model */
extern s32 D_800CC0F0_CCCF0[]; /* model file list */
extern char* D_800CC110_CCD10[]; /* per character */
extern u8 D_800CC128_CCD28[]; /* per board: model id */
extern s32* D_800CC1D8_CCDD8[]; /* per board: model file list */
extern char D_800D2DA0_D39A0[];
GW_PLAYER* BoardPlayerGet(s32 playerIndex);
MBModel* func_80043510_44110(s32, void*);
void func_80023DAC_249AC(s16 arg0, char* arg1, s16 arg2, char* arg3);
void func_80050860_51460(void);


void func_800506A0_512A0(omObjData* obj) {
    GW_PLAYER* p = BoardPlayerGet(obj->work[0]);

    func_800B3170_B3D70(&D_800CC1F0_CCDF0->pos, &((MBModel*)p->unk_24)->pos);
    func_800B3170_B3D70(&D_800CC1F0_CCDF0->rot, &((MBModel*)p->unk_24)->rot);
    D_800CC1F0_CCDF0->jumpY = ((MBModel*)p->unk_24)->jumpY;
}

/* MP3 MBKSuitCreate (asm there; its commented C): MP2 creates model 0x70 and passes a character
   name list and a string to func_80023DAC_249AC. */
MBModel* func_8005070C_5130C(void) {
    u32 player = GwSystem.current_player_index;
    GW_PLAYER* p = BoardPlayerGet(-1);
    omObjData* obj;

    func_80050860_51460();
    if (player < 4) {
        D_800CC1F0_CCDF0 = func_80043510_44110(0x70, D_800CC0F0_CCCF0);
        obj = omAddObj(0x3FFF, 0, 0, -1, func_800506A0_512A0);
        D_800CC1F4_CCDF4 = obj;
        obj->work[0] = player;
        func_80023DAC_249AC(((MBModel*)p->unk_24)->obj->model[0], D_800CC110_CCD10[gPlayers[player].character],
                            D_800CC1F0_CCDF0->obj->model[0], D_800D2DA0_D39A0);
        func_800B3170_B3D70(&D_800CC1F0_CCDF0->pos, &((MBModel*)p->unk_24)->pos);
    } else {
        D_800CC1F0_CCDF0 = func_80043510_44110(D_800CC128_CCD28[GwSystem.current_board_index],
                                               D_800CC1D8_CCDD8[GwSystem.current_board_index]);
        D_800FD3B4_FDFB4 = D_800CC1F0_CCDF0;
        MBModelDispOff(D_800CC1F0_CCDF0);
    }
    return D_800CC1F0_CCDF0;
}

void func_80050860_51460(void) {
    if (D_800CC1F0_CCDF0 != NULL) {
        MBModelKill(D_800CC1F0_CCDF0);
        D_800CC1F0_CCDF0 = NULL;
    }
    if (D_800CC1F4_CCDF4 != NULL) {
        omDelObj(D_800CC1F4_CCDF4);
        D_800CC1F4_CCDF4 = NULL;
    }
}

void func_800508B4_514B4(void) {
    D_800CC1F0_CCDF0 = NULL;
    D_800CC1F4_CCDF4 = NULL;
}

void func_800508C8_514C8(void) {
    func_80050860_51460();
}

void MBKSuitMotionSet(s16 arg0, s32 arg1) {
    MBMotionSet(D_800CC1F0_CCDF0, arg0, arg1);
}

void MBKSuitMotionShiftSet(s16 arg0, s16 arg1, s16 arg2, s32 arg3) {
    MBMotionShiftSet(D_800CC1F0_CCDF0, arg0, arg1, arg2, arg3);
}

void func_80050950_51550(void) {
    func_800B3170_B3D70((u8*)D_800CC1F0_CCDF0 + 0xC, (u8*)D_800F64C8_F70C8 + 0xC);
    func_80054C78_55878(D_800DF9A0_E05A0, &D_800FD3A0_FDFA0[0], &D_800FD3A0_FDFA0[1]);
    func_80054C78_55878(D_800DF9A0_E05A0, &D_800FD3A4_FDFA4[0], &D_800FD3A4_FDFA4[1]);
    D_800FD3A4_FDFA4[1] = D_800FD3A4_FDFA4[1] + 1;
}

void func_800509C4_515C4(s16 arg0) {
    D_800DF9A0_E05A0 = arg0;
}

void func_800509D0_515D0(void) {
    if (D_800CC1F0_CCDF0 != NULL) {
        MBModelDispOff(D_800CC1F0_CCDF0);
    }
}

void func_800509FC_515FC(void) {
    if (D_800CC1F0_CCDF0 != NULL) {
        MBModelDispOn(D_800CC1F0_CCDF0);
    }
}
