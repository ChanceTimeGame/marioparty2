#include "common.h"

typedef f32 Matrix4f[4][4];

void func_800B8070_B8C70(f32 angle, f32* sine, f32* cosine);

/* guRotateYF (Hudson, MP3 src/8AEA0.c asm there), from MP1 src/A4CD0.c */
void func_800B39F0_B45F0(Matrix4f m, f32 angle) {
    func_800B8070_B8C70(angle, &m[2][0], &m[2][2]);
    m[0][2] = -m[2][0];
    m[0][0] = m[2][2];
    m[0][1] = m[0][3] = m[1][0] = m[1][2] = m[1][3] = m[2][1] = m[2][3] = m[3][0] = m[3][1] = m[3][2] = 0.0f;
    m[1][1] = m[3][3] = 1.0f;
}
