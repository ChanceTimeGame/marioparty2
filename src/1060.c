#include "common.h"
#include "game/rsp.h"

/* MP1 src/1060.c (ultraMain, thread1_idle); MP2 adds a call before the init thread starts. */

void func_8007E260_7EE60(void);
void func_800409E0_415E0(void);
void func_800004C0_10C0(void* arg);

extern u8 D_800D4BF0_D57F0[]; /* init thread stack (0x800, bss start); its OSThread follows it */
extern OSThread D_800D53F0_D5FF0;
extern OSThread D_800D55A0_D61A0;

void func_80000460_1060(void) {
    __osInitialize_common();
    func_8007E260_7EE60();
    osCreateThread(&D_800D53F0_D5FF0, 1, func_800004C0_10C0, NULL, &D_800D4BF0_D57F0[0x800], 10);
    osStartThread(&D_800D53F0_D5FF0);
}

void func_800004C0_10C0(void* arg) {
    osCreateThread(&D_800D55A0_D61A0, 3, (void (*)(void*))func_800409E0_415E0, arg, &D_800FC730_FD330, 2);
    osStartThread(&D_800D55A0_D61A0);
    osSetIntMask(0x3FFF01);
    osSetThreadPri(NULL, 0);

    // idle forever
    while (1) {}
}
