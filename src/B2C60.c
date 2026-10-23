#include "common.h"

typedef f32 Matrix4f[4][4];

void func_800B8070_B8C70(f32 angle, f32* sine, f32* cosine);

/* guRotateRPYF (Hudson, MP3 src/89510.c asm there), from MP1 src/9F750.c: rotations about x, y, z */

void func_800B2060_B2C60(Matrix4f m, f32 x, f32 y, f32 z) {
    f32 sx;
    f32 cx;
    f32 sy;
    f32 cy;
    f32 sz;
    f32 cz;

    func_800B8070_B8C70(x, &sx, &cx);
    func_800B8070_B8C70(y, &sy, &cy);
    func_800B8070_B8C70(z, &sz, &cz);
    m[0][0] = cy * cz;
    m[0][1] = cy * sz;
    m[0][2] = -sy;
    m[1][0] = sx * sy * cz - cx * sz;
    m[1][1] = sx * sy * sz + cx * cz;
    m[1][2] = sx * cy;
    m[2][0] = cx * sy * cz + sx * sz;
    m[2][1] = cx * sy * sz - sx * cz;
    m[2][2] = cx * cy;
    m[3][0] = m[0][3] = m[1][3] = m[2][3] = m[3][1] = m[3][2] = 0.0f;
    m[3][3] = 1.0f;
}

INCLUDE_ASM("asm/nonmatchings/B2C60", func_800B21C0_B2DC0);
