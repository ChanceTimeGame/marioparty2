#include "common.h"

/* func_8001C45C_1D05C starts the thread whose entry is func_8001C3E8_1CFE8; same code as MP1
   ovl_67 func_800F6C1C_LogosSequenceCopy (other id, priority and stack). */

extern OSThread D_800D8C10_D9810;
extern u8 D_800D91C0_D9DC0[]; /* top of the thread's stack */

void func_8001C3E8_1CFE8(void*);

INCLUDE_ASM("asm/nonmatchings/1C7C0", func_8001BBC0_1C7C0);

INCLUDE_ASM("asm/nonmatchings/1C7C0", func_8001C160_1CD60);

INCLUDE_ASM("asm/nonmatchings/1C7C0", func_8001C270_1CE70);

INCLUDE_ASM("asm/nonmatchings/1C7C0", func_8001C320_1CF20);

INCLUDE_ASM("asm/nonmatchings/1C7C0", func_8001C3E8_1CFE8);

void func_8001C45C_1D05C(void) {
    osCreateThread(&D_800D8C10_D9810, 5, func_8001C3E8_1CFE8, NULL, D_800D91C0_D9DC0, 0xBE);
    osStartThread(&D_800D8C10_D9810);
}
