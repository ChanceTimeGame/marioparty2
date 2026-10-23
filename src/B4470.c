#include "common.h"

typedef f32 Matrix4f[4][4];

void func_800B8070_B8C70(f32 angle, f32* sine, f32* cosine);

/* guRotateXF (Hudson, MP3 src/8AD20.c asm there), from MP1 src/A4770.c */
void func_800B3870_B4470(Matrix4f m, f32 angle) {
    func_800B8070_B8C70(angle, &m[1][2], &m[1][1]);
    m[2][1] = -m[1][2];
    m[2][2] = m[1][1];
    m[0][1] = m[0][2] = m[0][3] = m[1][0] = m[1][3] = m[2][0] = m[2][3] = m[3][0] = m[3][1] = m[3][2] = 0.0f;
    m[0][0] = m[3][3] = 1.0f;
}
