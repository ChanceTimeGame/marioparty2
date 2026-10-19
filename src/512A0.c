#include "common.h"

/* Koopa-suit model helpers. C from MP3 ovl_80_shared_board F9DE0.c (MBKSuit*), FA250.c (which kills both
   with omDelPrcObj; MP2 kills a model and an object) and MP1 ovl_33_PaddleBattle 2341E0.c; the rest have no reference or differ (near) and stay asm. MP3's
   MBKSuitDispOn/Off names are swapped against what they call, so those two keep MP2 names. */

extern void* D_800CC1F0_CCDF0; /* MP1/MP3 Object* */
extern omObjData* D_800CC1F4_CCDF4;

void MBModelKill(void*);
void omDelObj(omObjData*);
void MBModelDispOn(void*);
void MBModelDispOff(void*);
void MBMotionSet(void* arg0, s16 arg1, u16 arg2);
void MBMotionShiftSet(void* arg0, s16 arg1, s32 arg2, s32 arg3, u16 arg4);


INCLUDE_ASM("asm/nonmatchings/512A0", func_800506A0_512A0);

INCLUDE_ASM("asm/nonmatchings/512A0", func_8005070C_5130C);

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

INCLUDE_ASM("asm/nonmatchings/512A0", func_800508B4_514B4);

void func_800508C8_514C8(void) {
    func_80050860_51460();
}

void MBKSuitMotionSet(s16 arg0, s32 arg1) {
    MBMotionSet(D_800CC1F0_CCDF0, arg0, arg1);
}

void MBKSuitMotionShiftSet(s16 arg0, s16 arg1, s16 arg2, s32 arg3) {
    MBMotionShiftSet(D_800CC1F0_CCDF0, arg0, arg1, arg2, arg3);
}

INCLUDE_ASM("asm/nonmatchings/512A0", func_80050950_51550);

INCLUDE_ASM("asm/nonmatchings/512A0", func_800509C4_515C4);

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
