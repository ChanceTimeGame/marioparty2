#include "common.h"

/* Directional pad repeat from the stick (MP1 src/engine/data.c: func_80014220, func_8001429C). */

extern u16 ContDStkTrg[4];
extern u16 ContBtn[4];
extern u16 D_800FC9E0_FD5E0[4];
extern s16 D_800FD2AC_FDEAC[4];
extern u16 D_800FD434_FE034[4];
extern s8 ContStkX[4];
extern s8 ContStkY[4];
extern u16 ContDStk[4];

void func_800172F0_17EF0(void) {
    s16 i;

    u16 *ContDStk_ptr;
    s16 *D_800FD2AC_ptr;
    u16 *D_800FC9E0_ptr;
    u16 *ContDStkTrg_ptr;
    u16 *D_800FD434_ptr;

    for (i = 0; i < 4; i++) {
        ContDStk_ptr = (ContDStk + i);
        D_800FD434_ptr = (D_800FD434_FE034 + i);
        ContDStkTrg_ptr = (ContDStkTrg + i);
        D_800FC9E0_ptr = (D_800FC9E0_FD5E0 + i);
        D_800FD2AC_ptr = (D_800FD2AC_FDEAC + i);

        *(D_800FD2AC_ptr) = 0;
        *(D_800FC9E0_ptr) = 0;
        *(ContDStkTrg_ptr) = 0;
        *(D_800FD434_ptr) = 0;
        *(ContDStk_ptr) = 0;
    }
}

void func_8001736C_17F6C(void) {
    s16 i;
    s32 sign;
    u16 btn;
    s8 stk;

    for (i = 0; i < 4; ++i) {
        D_800FD434_FE034[i] = ContDStk[i];
        btn = ContBtn[i];
        stk = ContStkX[i];
        sign = (stk >> 7) | 1;
        if ((stk * sign) - 30 > 0) {
            if (sign > 0) {
                btn = (btn & 0xFDFF) | 0x100;
            } else {
                btn = (btn & 0xFEFF) | 0x200;
            }
        }
        stk = ContStkY[i];
        sign = (stk >> 7) | 1;
        if ((stk * sign) - 30 > 0) {
            if (sign > 0) {
                btn = (btn & 0xFBFF) | 0x800;
            } else {
                btn = (btn & 0xF7FF) | 0x400;
            }
        }
        ContDStk[i] = btn;
        ContDStkTrg[i] = btn & (btn ^ D_800FD434_FE034[i]);
        if ((btn & 0xFFFF) != D_800FD434_FE034[i]) {
            D_800FD2AC_FDEAC[i] = 15;
            D_800FC9E0_FD5E0[i] = ContDStkTrg[i];
        } else if (D_800FD2AC_FDEAC[i] > 0) {
            D_800FD2AC_FDEAC[i] = D_800FD2AC_FDEAC[i] - 1;
            D_800FC9E0_FD5E0[i] = ContDStkTrg[i];
        } else {
            D_800FD2AC_FDEAC[i] = 5;
            D_800FC9E0_FD5E0[i] = btn;
        }
    }
}
