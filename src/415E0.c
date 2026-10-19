#include "common.h"

/* func_80040CF8 is MP1 src/3BF30.c's func_8003B5EC (clear the frame buffers); func_800409E0 (the
   boot thread, near MP3 main.c) stays asm. */

extern void* D_800CB040_CBC40[];

void* func_800B0EF0_B1AF0(void*, s32, s32); /* memset */

INCLUDE_ASM("asm/nonmatchings/415E0", func_800409E0_415E0);

void func_80040CF8_418F8(s16 arg0) {
    s16 i;

    for (i = 0; i < arg0; i++) {
        func_800B0EF0_B1AF0(D_800CB040_CBC40[i], 0, 0x25800);
    }
}
