#include "common.h"
#include "game/malloc.h"
#include "game/board.h"

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
void Hu3DCamSetPositionOrientation(s16, Vec*, Vec*, Vec*);
void CameraViewportSet(s16, Vec*, Vec*);
void Hu3DCamUpdateMtx(s16);
void func_8008E6AC_8F2AC(s32);
/* .data (0xCCCE0-0xCCCF0): per board: guide model id */
u8 D_800CC0E0_CCCE0[] = { 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B, 0xA7, 0xA7, 0xA8, 0x07 };
extern s16 D_800DF99C_E059C; /* guide x offset */
extern s16 D_800DF99E_E059E; /* guide y offset */
MBModel* func_80043510_44110(s32, void*);
void HuVecCopyXYZ(Vec*, f32, f32, f32);
void func_80029EDC_2AADC(s16, s32);
s32 func_8008DFC4_8EBC4(s32 x, s32 y, s32 style); /* retail passes unextended sums here (definition: s16 x, s16 y) */
void func_800896DC_8A2DC(s16 winId, s16 x, s16 y);


void func_80050270_50E70(void) {
    Hu3DCamSetPerspective(1, 40.0f, 80.0f, 8000.0f);
    Hu3DCamSetPositionOrientation(1, &D_800DF960_E0560, &D_800DF96C_E056C, &D_800DF978_E0578);
    Hu3DCamUpdateMtx(1);
    CameraViewportSet(1, &D_800DF984_E0584, &D_800DF990_E0590);
}

void func_800502D8_50ED8(void) {
    while (1) {
        func_80050270_50E70();
        HuPrcVSleep();       
    }
}

/* MP3 F5E80.c's MBGuideCreate, an older shape: no matrix setup, a viewport offset pair and a
   board-7 window position. NON_MATCHING: register swap in the window-position sums (masked 2). */
#ifdef NON_MATCHING
UnkMBGuideData* func_80050304_50F04(void* arg0, s32 arg1) {
    UnkMBGuideData* guide = HuMemMemoryAllocTemp(sizeof(UnkMBGuideData));
    Process* process;
    s32 y;

    if (guide != NULL) {
        guide->obj = func_80043510_44110(D_800CC0E0_CCCE0[GwSystem.current_board_index], arg0);
        HuVecCopyXYZ(&guide->obj->scale, 1.43f, 1.43f, 1.43f);
        guide->obj->attr |= 1;
        D_800DF99C_E059C = 0;
        D_800DF99E_E059E = 0;
        func_80029EDC_2AADC(guide->obj->obj->model[0], 2);
        process = omAddPrcObj(func_800502D8_50ED8, 0x4000, 0, 0);
        guide->unk_04 = process;
        process->user_data = guide;
        guide->spriteGroup = 0x69;
        D_800DF960_E0560.x = 0.0f;
        D_800DF960_E0560.y = 0.0f;
        D_800DF960_E0560.z = 120.0f;
        D_800DF96C_E056C.x = 0.0f;
        D_800DF96C_E056C.y = 0.0f;
        D_800DF96C_E056C.z = 0.0f;
        D_800DF978_E0578.x = 0.0f;
        D_800DF978_E0578.y = 1.0f;
        D_800DF978_E0578.z = 0.0f;
        D_800DF984_E0584.x = 1280.0f;
        D_800DF984_E0584.y = 960.0f;
        D_800DF984_E0584.z = 511.0f;
        D_800DF990_E0590.x = (-100.0f - D_800DF99C_E059C) * 4.0f + 640.0f;
        D_800DF990_E0590.y = (f32)(guide->spriteGroup + D_800DF99E_E059E) * 4.0f + 480.0f;
        D_800DF990_E0590.z = 511.5f;
        func_80050270_50E70();
        if (GwSystem.current_board_index == 7) {
            y = arg1 + 0x50;
            guide->amount = func_8008DFC4_8EBC4(0x4B, y + guide->spriteGroup, 4);
        } else {
            y = arg1 + 0x5A;
            if (arg1 != 0) {
                guide->amount = func_8008DFC4_8EBC4(0x5B, y + guide->spriteGroup, 8);
            } else {
                guide->amount = func_8008DFC4_8EBC4(0x4B, y + guide->spriteGroup, 3);
            }
        }
    }
    return guide;
}
#else
INCLUDE_ASM("asm/nonmatchings/50E70", func_80050304_50F04);
#endif

void func_8005057C_5117C(ProcessHeader* arg0) {
    if (arg0 != NULL) {
        MBModelKill(arg0->prev);
        omDelPrcObj(arg0->process);
        func_8008E6AC_8F2AC(arg0->unk_08);
        HuMemMemoryFreeTemp(arg0);
    }
}

/* MP3 MBGuidePosSet. NON_MATCHING: retail shares the board-7 call with the last arm and keeps
   arg2 unextended (masked 10); it stores to D_800DF994_E0594, the y of D_800DF990_E0590. */
#ifdef NON_MATCHING
void func_800505C4_511C4(UnkMBGuideData* guide, s16 y, s16 arg2) {
    s32 x;

    guide->spriteGroup = y;
    D_800DF990_E0590.y = (f32)(y + D_800DF99E_E059E) * 4.0f + 480.0f;
    if (GwSystem.current_board_index == 7) {
        x = arg2 + 0x50;
        func_800896DC_8A2DC(guide->amount, 0x4B, guide->spriteGroup + x);
    } else if (arg2 != 0 && GwSystem.current_board_index != 8) {
        x = arg2 + 0x5A;
        func_800896DC_8A2DC(guide->amount, 0x5B, guide->spriteGroup + x);
    } else {
        x = arg2 + 0x5A;
        func_800896DC_8A2DC(guide->amount, 0x4B, guide->spriteGroup + x);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/50E70", func_800505C4_511C4);
#endif
