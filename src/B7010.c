#include "common.h"

typedef f32 Matrix4f[4][4];

/* guMtxCatF (Hudson, MP3 src/8D8C0.c asm there), from MP1 src/ACCB0.c: arg0 * arg1 -> arg2 */
// loop counters: retail keeps i as its own counter where GCC reduces it to i*16 (masked 4)
#ifdef NON_MATCHING
void func_800B6410_B7010(Matrix4f arg0, Matrix4f arg1, Matrix4f arg2) {
    s32 i;
    s32 j;
    Matrix4f temp;
    f32 a0;
    f32 a1;
    f32 a2;
    f32 a3;

    for (i = 0; i < 4; i++) {
        a0 = arg0[i][0];
        a1 = arg0[i][1];
        a2 = arg0[i][2];
        a3 = arg0[i][3];
        for (j = 0; j < 4; j++) {
            temp[i][j] = a0 * arg1[0][j] + a1 * arg1[1][j] + a2 * arg1[2][j] + a3 * arg1[3][j];
        }
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            arg2[i][j] = temp[i][j];
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/B7010", func_800B6410_B7010);
#endif

INCLUDE_ASM("asm/nonmatchings/B7010", func_800B64E0_B70E0);

INCLUDE_ASM("asm/nonmatchings/B7010", func_800B6550_B7150);

INCLUDE_ASM("asm/nonmatchings/B7010", func_800B6630_B7230);

INCLUDE_ASM("asm/nonmatchings/B7010", func_800B66F0_B72F0);

INCLUDE_ASM("asm/nonmatchings/B7010", func_800B67C0_B73C0);

INCLUDE_ASM("asm/nonmatchings/B7010", func_800B6880_B7480);

INCLUDE_ASM("asm/nonmatchings/B7010", func_800B6940_B7540);
