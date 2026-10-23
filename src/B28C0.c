#include "common.h"

/* Hudson's gu matrix builders (MP3 src/89170.c, asm there): guRotateF about an axis, guScaleF,
   guScale, guTranslateF, guTranslate. The float versions from MP1 src/9EC60.c and 9F4F0.c. */

typedef f32 Matrix4f[4][4];

f32 func_800B1830_B2430(f32);
void func_800B8070_B8C70(f32 angle, f32* sine, f32* cosine);

/* guRotateF without the degree conversion: the angle goes to func_800B8070_B8C70 (sine/cosine).
   Unlike MP1's it leaves mf[3][3] alone. */

void func_800B1CC0_B28C0(Matrix4f mf, f32 a, f32 x, f32 y, f32 z) {
    f32 sine;
    f32 cosine;
    f32 xx;
    f32 yy;
    f32 zz;
    f32 ab;
    f32 bc;
    f32 ca;
    f32 t;

    t = 1.0f / func_800B1830_B2430(x * x + y * y + z * z);
    x *= t;
    y *= t;
    z *= t;
    xx = x * x;
    yy = y * y;
    zz = z * z;
    func_800B8070_B8C70(a, &sine, &cosine);
    t = 1.0f - cosine;
    ab = x * y * t;
    bc = y * z * t;
    ca = z * x * t;
    x *= sine;
    y *= sine;
    z *= sine;
    mf[0][0] = xx + cosine * (1.0f - xx);
    mf[2][1] = bc - x;
    mf[1][2] = bc + x;
    mf[1][1] = yy + cosine * (1.0f - yy);
    mf[2][0] = ca + y;
    mf[0][2] = ca - y;
    mf[2][2] = zz + cosine * (1.0f - zz);
    mf[1][0] = ab - z;
    mf[0][1] = ab + z;
    mf[3][0] = mf[0][3] = mf[1][3] = mf[2][3] = mf[3][1] = mf[3][2] = 0.0f;
}

/* guScaleF */
void func_800B1E50_B2A50(Matrix4f mf, f32 x, f32 y, f32 z) {
    mf[0][0] = x;
    mf[1][1] = y;
    mf[2][2] = z;
    mf[0][1] = mf[0][2] = mf[0][3] = mf[1][0] = mf[1][2] = mf[1][3] = mf[2][0] = mf[2][1] = mf[2][3] = mf[3][0] =
        mf[3][1] = mf[3][2] = 0.0f;
    mf[3][3] = 1.0f;
}

INCLUDE_ASM("asm/nonmatchings/B28C0", func_800B1EA0_B2AA0);

/* guTranslateF */
void func_800B1F50_B2B50(Matrix4f mf, f32 x, f32 y, f32 z) {
    mf[3][0] = x;
    mf[3][1] = y;
    mf[3][2] = z;
    mf[0][0] = mf[1][1] = mf[2][2] = mf[3][3] = 1.0f;
    mf[0][1] = mf[0][2] = mf[0][3] = mf[1][0] = mf[1][2] = mf[1][3] = mf[2][0] = mf[2][1] = mf[2][3] = 0.0f;
}

INCLUDE_ASM("asm/nonmatchings/B28C0", func_800B1FA0_B2BA0);
