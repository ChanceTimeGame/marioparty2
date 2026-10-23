#include "common.h"

typedef f32 Matrix4f[4][4];

/* HuVecCopyXYZ and HuVecCopy3F, from MP3 src/libhmath/veccopy.c (-O2 -ffast-math).
   guMtxL2F (func_800B30D0_B3CD0) from MP1 src/A1620.c. */

/* guMtxL2F (Hudson's copy) */
void func_800B30D0_B3CD0(Matrix4f mf, Mtx* m) {
    s32 i;
    s32 j;
    u16* ai;
    u16* af;

    ai = (u16*)m;
    af = (u16*)((u8*)m + 0x20);
    for (i = 0; i < 4; i++)
        for (j = 0; j < 2; j++) {
            mf[i][j * 2] = (s32)((*ai << 16) | *af) * (1.0f / 65536.0f);
            *(&mf[i][j * 2] + 1) = (s32)((*(ai + 1) << 16) | *(af + 1)) * (1.0f / 65536.0f);
            ai += 2;
            af += 2;
        }
}

void HuVecCopyXYZ(Vec *out, f32 x, f32 y, f32 z) {
    out->x = x;
    out->y = y;
    out->z = z;
}

void func_800B3170_B3D70(Vec *out, Vec *a) {
    *out = *a;
}
