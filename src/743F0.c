#include "common.h"
#include "process.h"

/* Board-event wrappers; func_80073D2C_7492C is MP1 src/51200.c func_80052934 (runs
   func_80073BF4_747F4 as a child process). The rest has no reference and stays asm. */

extern u8 D_800F851A_F911A;
extern s16 D_800FD2A6_FDEA6;
extern s16 D_800E20C0_E2CC0;

void func_80073BF4_747F4(void);
void func_80078EC8_79AC8(void);
void func_80078FF8_79BF8(void);
s32 HuGetPadInserted(s16 port);
void func_800884AC_890AC(s16);
void func_800794F0_7A0F0(s8);
void func_800794A8_7A0A8(s32);
void func_80028334_28F34(s16, s32);
void func_80029EDC_2AADC(s16, s32);
void omPrcSetStatBit(Process* process, s32 value);
void func_800744C0_750C0(void);
void func_800740AC_74CAC(void);

INCLUDE_ASM("asm/nonmatchings/743F0", func_800737F0_743F0);

INCLUDE_ASM("asm/nonmatchings/743F0", func_8007388C_7448C);

INCLUDE_ASM("asm/nonmatchings/743F0", func_80073BF4_747F4);

void func_80073D2C_7492C(s32 arg0) {
    Process* parent;
    Process* proc;
    s32 i;

    D_800F851A_F911A = 1;
    func_80078EC8_79AC8();
    for (i = 0; i < 4; i++) {
        if (HuGetPadInserted(i) != 0) {
            func_800884AC_890AC(i);
        }
    }
    func_800794F0_7A0F0(0x60);
    func_80028334_28F34(D_800FD2A6_FDEA6, 2);
    func_80029EDC_2AADC(D_800FD2A6_FDEA6, 1);
    D_800E20C0_E2CC0 = 0;
    parent = HuPrcCurrentGet();
    proc = omAddPrcObj(func_80073BF4_747F4, 0xEFFF, 0, 0);
    proc->user_data = (void*)arg0;
    omPrcSetStatBit(proc, 0x80);
    HuPrcChildLink(parent, proc);
    HuPrcChildWatch();
    func_80028334_28F34(D_800FD2A6_FDEA6, 6);
    func_800794F0_7A0F0(0x7F);
    if (D_800E20C0_E2CC0 != 0) {
        func_800794A8_7A0A8(0x5A);
        InitFadeOut(0, 0x10);
        HuPrcSleep(0x11);
        func_800744C0_750C0();
        func_800740AC_74CAC();
        omOvlReturnEx(1);
        omOvlKill();
        HuPrcVSleep();
    }
    func_80078FF8_79BF8();
    D_800F851A_F911A = 0;
}
