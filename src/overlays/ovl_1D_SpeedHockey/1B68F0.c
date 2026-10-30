#include "ovl_1D.h"

/* Play motion slot mot (len / 5 frames; a speed < 0 keeps the motion's own speed). */
void func_801047A0_1B68F0_SpeedHockey(omObjData* obj, s32 mot) {
    SHPlayer* w = obj->unk_50;

    if (w->mot[mot].speed < 0) {
        func_80029BF0_2A7F0(obj->model[0], obj->motion[mot], 0, w->mot[mot].len / 5, 0);
        w->motion = mot;
    } else {
        func_80029BF0_2A7F0(obj->model[0], obj->motion[mot], 0, w->mot[mot].len / 5, 2);
        func_80029FBC_2ABBC(obj->model[0], w->mot[mot].speed);
        w->motion = mot;
    }
}

/* CPU state 0: wait (stick centred). */
void func_801048D4_1B6A24_SpeedHockey(omObjData* obj, SHPlayer* w) {
    if (--w->cpuTimer < 0) {
        w->cpuState = 1;
    }
    func_8010650C_1B865C_SpeedHockey(w->port, 0, 0, 0, 0);
}

#ifdef NON_MATCHING
/* masked 8: retail keeps the new target in f0 and shares the clamp constant's store (f2) between both bounds; GCC here swaps f0/f2 and stores in each arm */
/* CPU state 1: pick a z to move to (random, or the puck's when it comes this way). */
void func_8010491C_1B6A6C_SpeedHockey(omObjData* obj, SHPlayer* w) {
    Vec dir;
    Vec pos;
    Vec prev;
    f32 target;

    if ((u8)(rand8() % 10) < D_80106AE0_1B8C30_SpeedHockey[w->cpuLevel].chance) {
        target = (f32)(u8)(rand8() % 80) - 40.0f + 0.0f;
    } else {
        func_8010463C_1B678C_SpeedHockey(&dir, &pos, &prev);
        if (!(dir.x * obj->trans.x > 0.0f)) {
            return;
        }
        target = pos.z;
    }
    w->cpuTarget = target;
    if (target < -33.800003f) {
        w->cpuTarget = -33.800003f;
    } else if (w->cpuTarget > 33.800003f) {
        w->cpuTarget = 33.800003f;
    }
    w->cpuRange = 8.0f;
    w->cpuState = 2;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B68F0", func_8010491C_1B6A6C_SpeedHockey);
#endif

#ifdef NON_MATCHING
/* masked 12: retail keeps the table value and the signed speed in separate registers (two more mov.s); GCC here negates in place */
/* CPU state 2: push the stick toward the target z (slower when near), then wait. */
void func_80104A90_1B6BE0_SpeedHockey(omObjData* obj, SHPlayer* w) {
    f32 d = obj->trans.z - w->cpuTarget;
    f32 ad = (d < 0.0f) ? -d : d;
    f32 v;

    if (ad < w->cpuRange) {
        w->cpuState = 0;
        w->cpuTimer = (s8)D_80106AE0_1B8C30_SpeedHockey[w->cpuLevel].wait;
        func_8010650C_1B865C_SpeedHockey(w->port, 0, 0, 0, 0);
        return;
    }
    if (ad < 2.0f * w->cpuRange) {
        v = D_80106AE0_1B8C30_SpeedHockey[w->cpuLevel].slow * ((d < 0.0f) ? -1.0f : ((d > 0.0f) ? 1.0f : 0.0f));
    } else {
        v = D_80106AE0_1B8C30_SpeedHockey[w->cpuLevel].fast * ((d < 0.0f) ? -1.0f : ((d > 0.0f) ? 1.0f : 0.0f));
    }
    func_8010650C_1B865C_SpeedHockey(w->port, 0, (s8)v, 0, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B68F0", func_80104A90_1B6BE0_SpeedHockey);
#endif

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B68F0", func_80104C00_1B6D50_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B68F0", func_80104C64_1B6DB4_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B68F0", func_80104D4C_1B6E9C_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B68F0", func_801050F0_1B7240_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B68F0", func_801053F0_1B7540_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B68F0", func_801054A8_1B75F8_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B68F0", func_80105560_1B76B0_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B68F0", func_80105618_1B7768_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B68F0", func_801056D0_1B7820_SpeedHockey);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B68F0", func_80105768_1B78B8_SpeedHockey);
