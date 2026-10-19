#include "common.h"
#include "game/malloc.h"

/* Board camera setup and a model/process holder. C from MP1 src/48D90.c (func_80048190),
   src/engine/gameman.c (func_8001A428) and ovl_3D_EternalStar 254480.c (func_800F6AA0); the rest
   have no reference and stay asm. */

typedef struct ProcessHeader {
    /* 0x00 */ void* prev; /* MP1 Object* */
    /* 0x04 */ Process* process;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
} ProcessHeader;

extern Vec D_800DF960_E0560;
extern Vec D_800DF96C_E056C;
extern Vec D_800DF978_E0578;
extern Vec D_800DF984_E0584;
extern Vec D_800DF990_E0590;

void MBModelKill(void*);
void func_80020260_20E60(s16, Vec*, Vec*, Vec*);
void CameraViewportSet(s16, Vec*, Vec*);
void func_800203DC_20FDC(s16);
void func_8008E6AC_8F2AC(s32);


void func_80050270_50E70(void) {
    func_800202DC_20EDC(1, 40.0f, 80.0f, 8000.0f);
    func_80020260_20E60(1, &D_800DF960_E0560, &D_800DF96C_E056C, &D_800DF978_E0578);
    func_800203DC_20FDC(1);
    CameraViewportSet(1, &D_800DF984_E0584, &D_800DF990_E0590);
}

void func_800502D8_50ED8(void) {
    while (1) {
        func_80050270_50E70();
        HuPrcVSleep();       
    }
}

INCLUDE_ASM("asm/nonmatchings/50E70", func_80050304_50F04);

void func_8005057C_5117C(ProcessHeader* arg0) {
    if (arg0 != NULL) {
        MBModelKill(arg0->prev);
        omDelPrcObj(arg0->process);
        func_8008E6AC_8F2AC(arg0->unk_08);
        HuMemMemoryFreeTemp(arg0);
    }
}

INCLUDE_ASM("asm/nonmatchings/50E70", func_800505C4_511C4);
