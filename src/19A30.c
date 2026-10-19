#include "common.h"

/* Camera count setup and the camera draw processes. Same code as Mario Party 1's
   src/engine/ovlman.c (func_800178A0 etc.). */

typedef struct Camera {
    /* 0x00 */ char unk_00[0x4C];
    /* 0x4C */ f32 fov;
} Camera;

extern u8 D_800C99C0_CA5C0;
extern u8 D_800C99C1_CA5C1;
extern Camera* D_800C9B80_CA780;
extern s32 D_800FA5B8_FB1B8;
extern s32 D_800FC8F8_FD4F8[];

void func_80020070_20C70(s32);
void func_80020718_21318(s16, void*, void*);
void func_8002E544_2F144(void);

void func_80018E30_19A30(s32 arg0) {
    D_800C99C0_CA5C0 = (u8) arg0;
    func_80020070_20C70(D_800C99C0_CA5C0);
    D_800C9B80_CA780->fov = 45.0f;
    D_800C99C1_CA5C1 = 0;
}

s32 func_80018E78_19A78(void) {
    s32 temp_s0;

    temp_s0 = D_800C99C1_CA5C1;
    func_80020718_21318(D_800C99C1_CA5C1, &func_8002E544_2F144, &D_800FA5B8_FB1B8);
    D_800C99C1_CA5C1 += 1;
    return temp_s0;
}

INCLUDE_ASM("asm/nonmatchings/19A30", func_80018ED0_19AD0);

u8 func_80018F58_19B58(s32 arg0) {
    s32 var_a0;
    s32 i;

    for (i = 0; i < arg0; i++) {
        var_a0 = i << 0x10;
        func_80020718_21318(var_a0 >> 0x10, &func_8002E544_2F144, (i * 0x6) + D_800FC8F8_FD4F8);
        D_800C99C1_CA5C1 += 1;
    }

    return D_800C99C1_CA5C1;
}
