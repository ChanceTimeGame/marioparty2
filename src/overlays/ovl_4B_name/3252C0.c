#include "common.h"
#include "ovl_4B.h"

/* MP1 ovl_7F func_800F6610 */
void func_80102830_3252F0_name_4B(void) {
    GwSystem.current_board_index = 6;
    _SetFlag(0xD);
    omInitObjMan(10, 0);
    omOvlGotoEx(0x3D, 0, 0x192);
}

void func_80102874_325334_name_4B(void) {
    omInitObjMan(10, 0);
    SetPlayerOntoChain(0, 0, 0);
    SetPlayerOntoChain(1, 0, 0);
    SetPlayerOntoChain(2, 0, 0);
    SetPlayerOntoChain(3, 0, 0);
    omOvlReturnEx(1);
}

void func_801028DC_32539C_name_4B(void) {
    omInitObjMan(0xA0, 0x50);
    func_80026DAC_279AC(1, 100, 100, 100);
    func_80026DAC_279AC(2, 200, 200, 200);
    func_80062E10_63A10(0x2B, 0x46, 0x2D, 0);
    func_801029BC_32547C_name_4B();
    func_80102A2C_3254EC_name_4B();
    func_80102D64_325824_name_4B();
}

void func_80102950_325410_name_4B(void) {
    PlayMusic(0x36);
    func_80020070_20C70(2);
    func_801028DC_32539C_name_4B();
    EventTableHydrate(D_801030C4_325B84_name_4B);
    func_80066C34_67834(0);
}

void func_80102990_325450_name_4B(void) {
    func_80020070_20C70(1);
    func_801028DC_32539C_name_4B();
    func_80066C34_67834(1);
}

void func_801029BC_32547C_name_4B(void) {
    MBModel* obj;

    obj = func_80043510_44110(0xA7, NULL);
    func_80043DAC_449AC(obj);
    D_80103100_325BC0_name_4B = obj;
    obj->attr |= 2;
    func_800B3170_B3D70(&obj->pos, &GetSpaceData(0x17)->coords);
    func_80041AEC_426EC(6, obj, 0, 0);
}

void func_80102A2C_3254EC_name_4B(void) {
    MBModel* obj;

    obj = func_80043510_44110(0xA5, NULL);
    func_800298A4_2A4A4(obj->obj->model[0], 0x80000, 0x80000);
    func_80029A8C_2A68C(obj->obj->model[0]);
    func_80043DAC_449AC(obj);
    D_80103104_325BC4_name_4B = obj;
    obj->attr |= 2;
}

/* A spectator that turns to face the current player. */
void func_80102A9C_32555C_name_4B(void) {
    MBModel* obj = HuPrcCurrentGet()->user_data;
    Vec* rot = &obj->rot;
    Vec dir;

    while (TRUE) {
        func_80056658_57258(&obj->pos, &PLAYER_MODEL_4B(-1)->pos, &dir);
        func_80056B78_57778(rot, &dir, rot, 6);
        HuPrcSleep(7);
    }
}

#ifdef NON_MATCHING
/* NON_MATCHING: scheduling only (rot's addiu placed before the constant loads) */
/* The same, also hopping at random intervals. */
void func_80102B0C_3255CC_name_4B(void) {
    s32 timer = 0;
    MBModel* obj = HuPrcCurrentGet()->user_data;
    Vec* rot;
    Vec dir;
    s32 i;

    rot = &obj->rot;

    while (TRUE) {
        if (timer == 0) {
            i = (u8)(rand8() % 3);
            timer = (u8)(rand8() % 30) + D_80103050_325B10_name_4B[i];
            obj->jumpVel = D_80103058_325B18_name_4B[i] / 10.0f;
            obj->jumpAccel = D_80103064_325B24_name_4B[i] / 10.0f;
        }
        timer--;
        func_80056658_57258(&obj->pos, &PLAYER_MODEL_4B(-1)->pos, &dir);
        func_80056B78_57778(rot, &dir, rot, 6);
        HuPrcSleep(7);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4B_name/3252C0", func_80102B0C_3255CC_name_4B);
#endif

void func_80102C6C_32572C_name_4B(s16 index) {
    MBModel* obj;
    void (*func)(void);

    if (D_80103110_325BD0_name_4B[index] == NULL) {
        if (D_80103108_325BC8_name_4B == NULL) {
            obj = func_80043510_44110(0xA6, NULL);
            func_80043DAC_449AC(obj);
            D_80103108_325BC8_name_4B = obj;
        } else {
            obj = MBModelParamCreate(D_80103108_325BC8_name_4B);
        }
        D_80103110_325BD0_name_4B[index] = obj;
        obj->attr |= 2;
        func_800B3170_B3D70(&obj->pos, &GetSpaceData(D_80103070_325B30_name_4B[index])->coords);
        if (index & 1) {
            func = func_80102B0C_3255CC_name_4B;
        } else {
            func = func_80102A9C_32555C_name_4B;
        }
        omAddPrcObj(func, 0x4800, 0, 0)->user_data = obj;
    }
}

void func_80102D64_325824_name_4B(void) {
    s32 i;

    D_80103108_325BC8_name_4B = NULL;
    for (i = 0; i < 9; i++) {
        D_80103110_325BD0_name_4B[i] = NULL;
        func_80102C6C_32572C_name_4B(i);
    }
}

void func_80102DC4_325884_name_4B(void) {
    SetNextChainAndSpace(-1, 1, 0);
}

__asm__(".section .rodata");
const char D_801030F0_325BB0_name_4B[16] = "%d";

#ifdef NON_MATCHING
/* NON_MATCHING: retail reads GwSystem by absolute address before HuPrcSleep and through a base register after; GCC folds all into the base */
/* Space event: the turn count (or "last turn"), then 10 coins. */
void func_80102DE8_3258A8_name_4B(void) {
    char turns[8];
    char rank[8];
    GW_SYSTEM* gw = &GwSystem;
    s32 left;

    func_80046D2C_4792C(GwSystem.current_player_index);
    MBPlayerMotionSet(-1, -1, 2);
    func_80056C30_57830(-1, 8, 0x17);
    HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.6f));
    HuPrcChildWatch();
    PlaySound(0x11E);
    MBDlgWinExec(0x29, 0x6C0);
    func_8004CA34_4D634(GwSystem.current_player_index, 10);
    func_800614B4_620B4(GwSystem.current_player_index, 10);
    HuPrcSleep(30);
    if (GwSystem.total_turns == GwSystem.current_turn) {
        MBDlgWinExec(0x29, 0x6C3);
    } else {
        left = gw->total_turns - gw->current_turn;
        if (left < 5) {
            sprintf(turns, D_801030F0_325BB0_name_4B, left + 1);
            func_80056368_56F68(0x29, 0x6C2, (s32)turns, 0, 0, 0, 0);
        } else {
            sprintf(turns, D_801030F0_325BB0_name_4B, gw->current_turn);
            sprintf(rank, D_801030F0_325BB0_name_4B, func_80059FD0_5ABD0(gw->current_player_index) + 1);
            func_80056368_56F68(0x29, 0x6C1, (s32)turns, (s32)rank, 0, 0, 0);
        }
        MBDlgWinClose();
        func_80056168_56D68();
    }
    func_8004655C_4715C(gw->current_player_index);
    HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.3f));
    HuPrcChildWatch();
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4B_name/3252C0", func_80102DE8_3258A8_name_4B);
#endif

void func_80102FC8_325A88_name_4B(void) {
    PLAYER_MODEL_4B(-1)->attr |= 1;
}

void func_80102FF4_325AB4_name_4B(void) {
    PLAYER_MODEL_4B(-1)->attr &= ~1;
}
