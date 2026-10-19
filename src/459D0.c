#include "common.h"
#include "game/malloc.h"

/* Debug text with a drop shadow and the button-sequence watcher, from MP1 src/3F5B0.c
   (func_80044F5C and func_80044F78 are MP1 func_8003EE3C and func_8003EE58). The debug readouts
   (sprintf with strings in this unit's rodata, shared with functions still in asm) stay asm. */

typedef struct ButtonSeqWork {
    /* 0x00 */ Process* process;
    /* 0x04 */ u16* sequence;
    /* 0x08 */ s16 index;
} ButtonSeqWork;

extern s32 fontcolor;
extern u16 ContBtnTrg[];

s16 DrawDebugText(u16, u16, char*); /* MP1 print8 */

void func_80044DD0_459D0(u16 arg0, u16 arg1, s32 arg2, u8 arg3, u8 arg4) {
    fontcolor = arg4;
    DrawDebugText((arg0 + 1), (arg1 + 1), (char*)arg2);
    fontcolor = arg3;
    DrawDebugText(arg0, arg1, (char*)arg2);
}

void func_80044E50_45A50(void) {
    ButtonSeqWork* work = HuPrcCurrentGet()->user_data;

    while (TRUE) {
        if (ContBtnTrg[0] != 0) {
            if (ContBtnTrg[0] == work->sequence[work->index]) {
                work->index++;
                if (work->sequence[work->index] == 0) {
                    work->index = -1;
                    break;
                }
            } else {
                work->index = 0;
            }
        }
        HuPrcVSleep();
    }
    while (TRUE) {
        HuPrcVSleep();
    }
}

s32 func_80044EFC_45AFC(s32* sequence) {
    Process* process = omAddPrcObj(func_80044E50_45A50, 0xEFFF, 0, 0x40);
    ButtonSeqWork* work = HuMemMemoryAlloc(process->heap, sizeof(ButtonSeqWork));

    process->user_data = work;
    work->sequence = (u16*)sequence;
    work->index = 0;
    work->process = process;
    return (s32)work;
}

void func_80044F5C_45B5C(s32 work) {
    omDelPrcObj(((ButtonSeqWork*)work)->process);
}

s32 func_80044F78_45B78(s32 work) {
    return ((ButtonSeqWork*)work)->index == -1;
}

INCLUDE_ASM("asm/nonmatchings/459D0", func_80044F88_45B88);

INCLUDE_ASM("asm/nonmatchings/459D0", func_800450C0_45CC0);

INCLUDE_ASM("asm/nonmatchings/459D0", func_80045184_45D84);

INCLUDE_ASM("asm/nonmatchings/459D0", func_800451F8_45DF8);

INCLUDE_ASM("asm/nonmatchings/459D0", func_800453C4_45FC4);

INCLUDE_ASM("asm/nonmatchings/459D0", func_80045488_46088);

INCLUDE_ASM("asm/nonmatchings/459D0", func_800455CC_461CC);
