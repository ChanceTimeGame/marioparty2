#include "common.h"
#include "game/board.h"

/* Koopa-suit model helpers. C from MP3 ovl_80_shared_board F9DE0.c (MBKSuit*), FA250.c (which kills both
   with omDelPrcObj; MP2 kills a model and an object) and MP1 ovl_33_PaddleBattle 2341E0.c; the rest have no reference (or an asm one) and stay asm. MP3's
   MBKSuitDispOn/Off names are swapped against what they call, so those two keep MP2 names. */


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
/* .data (0xCCCF0-0xCCE00). Model file lists: a count, then the files. */
s32 D_800CC0F0_CCCF0[] = { 7, 0x80084, 0x80084, 0x80085, 0x80088, 0x80089, 0x80087, 0x80087 };
/* .rodata (0xD3938-0xD39B8): model object names, by character, then D_800D2DA0_D39A0 below. */
const char D_800D2D38_D3938[] = "c005_000-bmerge1";
const char D_800D2D4C_D394C[] = "Luigi1-atama_1";
const char D_800D2D5C_D395C[] = "c003_000-head_1";
const char D_800D2D6C_D396C[] = "C002_000b-bmerge10_1";
const char D_800D2D84_D3984[] = "c001_000-atama_2";
const char D_800D2D98_D3998[] = "atama_2";
char* D_800CC110_CCD10[] = { /* per character */
    (char*)D_800D2D98_D3998, (char*)D_800D2D84_D3984, (char*)D_800D2D6C_D396C, (char*)D_800D2D5C_D395C, (char*)D_800D2D4C_D394C, (char*)D_800D2D38_D3938,
};
u8 D_800CC128_CCD28[] = { 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B }; /* per board: model id */
s32 D_800CC130_CCD30[] = { 0x6, 0x80046, 0x80040, 0x8003E, 0x80041, 0x80044, 0x80073 };
s32 D_800CC14C_CCD4C[] = { 0x6, 0x80046, 0x80040, 0x8003E, 0x80041, 0x80044, 0x80074 };
s32 D_800CC168_CCD68[] = { 0x6, 0x80046, 0x80040, 0x8003E, 0x80041, 0x80044, 0x80075 };
s32 D_800CC184_CCD84[] = { 0x6, 0x8005D, 0x8005D, 0x8005D, 0x8005D, 0x8005D, 0x80076 };
s32 D_800CC1A0_CCDA0[] = { 0x6, 0x80046, 0x80040, 0x8003E, 0x80041, 0x80044, 0x80077 };
s32 D_800CC1BC_CCDBC[] = { 0x6, 0x80046, 0x80040, 0x8003E, 0x80041, 0x80044, 0x80078 };
s32* D_800CC1D8_CCDD8[] = { /* per board: model file list */
    D_800CC130_CCD30, D_800CC14C_CCD4C, D_800CC168_CCD68, D_800CC184_CCD84, D_800CC1A0_CCDA0, D_800CC1BC_CCDBC,
};
MBModel* D_800CC1F0_CCDF0 = NULL; /* MP1/MP3 Object* */
omObjData* D_800CC1F4_CCDF4 = NULL;
const char D_800D2DA0_D39A0[] = "21_kimoti_1b-atama_3";
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
