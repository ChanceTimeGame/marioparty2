#include "common.h"
#include "PR/gu.h"

/* Matrix helpers. Same code as Mario Party 1's src/engine/math.c; MP1 names in comments. */

typedef f32 Mat4[4][4];
typedef f32 Mat3[3][3];

void func_800B8070_B8C70(f32, f32*, f32*); // sin and cos of an angle

void func_80025770_26370(Mat4 mtx, f32 x, f32 y, f32 z) {
     mtx[3][0] = (x * mtx[0][0]) + (y * mtx[1][0]) + (z * mtx[2][0]) + mtx[3][0];
     mtx[3][1] = (x * mtx[0][1]) + (y * mtx[1][1]) + (z * mtx[2][1]) + mtx[3][1];
     mtx[3][2] = (x * mtx[0][2]) + (y * mtx[1][2]) + (z * mtx[2][2]) + mtx[3][2];
     mtx[3][3] = (x * mtx[0][3]) + (y * mtx[1][3]) + (z * mtx[2][3]) + mtx[3][3];
}

void func_80025830_26430(Mat4 mtx, f32 sx, f32 sy, f32 sz) {
    s32 i;
    for (i = 0; i < 3; i++) {
        mtx[0][i] *= sx;
        mtx[1][i] *= sy;
        mtx[2][i] *= sz;
    }
}

void func_80025884_26484(Mat4 mtx, f32 angle1, f32 angle2, f32 angle3) {    
    Mat3 rot;
    f32 sx, cx;
    f32 sy, cy;
    f32 sz, cz;

    /* Get sin and cosf for three angles. */
    func_800B8070_B8C70(angle1, &sx, &cx);
    if (angle1 == angle2){
        sy = sx;
        cy = cx;
    } else {
        func_800B8070_B8C70(angle2, &sy, &cy);
    }

    if (angle1 == angle3){
        sz = sx;
        cz = cx;
    } else if (angle2 == angle3) {
        sz = sy;
        cz = cy;
    } else {
        func_800B8070_B8C70(angle3, &sz, &cz);
    }

    /* Rotation Matrix First Column */
    rot[0][0] = cy * cz;
    rot[0][1] = cy * sz;
    rot[0][2] = -sy;
    /* Rotation Matrix Second Column */
    rot[1][0] = sx * sy * cz - cx * sz;
    rot[1][1] = sx * sy * sz + cx * cz;
    rot[1][2] = sx * cy;
    /* Rotation Matrix Third Column */
    rot[2][0] = cx * sy * cz + sx * sz;
    rot[2][1] = cx * sy * sz - sx * cz;
    rot[2][2] = cx * cy;

    {
        /* Multiply Matrices */
        f32 ret00, ret01, ret02;
        f32 ret10, ret11, ret12;

        ret00 = (rot[0][0] * mtx[0][0]) + (rot[0][1] * mtx[1][0]) + (rot[0][2] * mtx[2][0]);
        ret01 = (rot[0][0] * mtx[0][1]) + (rot[0][1] * mtx[1][1]) + (rot[0][2] * mtx[2][1]);
        ret02 = (rot[0][0] * mtx[0][2]) + (rot[0][1] * mtx[1][2]) + (rot[0][2] * mtx[2][2]);
        ret10 = (rot[1][0] * mtx[0][0]) + (rot[1][1] * mtx[1][0]) + (rot[1][2] * mtx[2][0]);
        ret11 = (rot[1][0] * mtx[0][1]) + (rot[1][1] * mtx[1][1]) + (rot[1][2] * mtx[2][1]);
        ret12 = (rot[1][0] * mtx[0][2]) + (rot[1][1] * mtx[1][2]) + (rot[1][2] * mtx[2][2]);

        /* Evaluate Result Matrix */
        mtx[2][0] = (rot[2][0] * mtx[0][0]) + (rot[2][1] * mtx[1][0]) + (rot[2][2] * mtx[2][0]);
        mtx[2][1] = (rot[2][0] * mtx[0][1]) + (rot[2][1] * mtx[1][1]) + (rot[2][2] * mtx[2][1]);
        mtx[2][2] = (rot[2][0] * mtx[0][2]) + (rot[2][1] * mtx[1][2]) + (rot[2][2] * mtx[2][2]);
        mtx[0][0] = ret00;
        mtx[0][1] = ret01;
        mtx[0][2] = ret02;
        mtx[1][0] = ret10;
        mtx[1][1] = ret11;
        mtx[1][2] = ret12;
    }
}

INCLUDE_ASM("asm/nonmatchings/26370", func_80025BA4_267A4);

s16 func_80025F00_26B00(Mat4 a, Mat4 b) {
    u32 success;
    f32 d0, d1, d2;
    f32 det;

    d0 = (a[1][1] * a[2][2]) - (a[1][2] * a[2][1]);
    d1 = (a[1][2] * a[2][0]) - (a[1][0] * a[2][2]);
    d2 = (a[1][0] * a[2][1]) - (a[1][1] * a[2][0]);
    det = (a[0][0] * d0) + (a[0][1] * d1) + (a[0][2] * d2);

    success = FALSE;
    if (det != 0.0f) {
        f32 idet = (det = 1.0f / det); // They use same var, but I prefer this alias.
        b[0][0] = d0 * idet;
        b[1][0] = d1 * idet;
        b[2][0] = d2 * idet;
        b[0][1] = ((a[0][2] * a[2][1]) - (a[0][1] * a[2][2])) * idet;
        b[0][2] = ((a[0][1] * a[1][2]) - (a[0][2] * a[1][1])) * idet;
        b[1][1] = ((a[0][0] * a[2][2]) - (a[0][2] * a[2][0])) * idet;
        b[1][2] = ((a[0][2] * a[1][0]) - (a[0][0] * a[1][2])) * idet;
        b[2][1] = ((a[0][1] * a[2][0]) - (a[0][0] * a[2][1])) * idet;
        b[2][2] = ((a[0][0] * a[1][1]) - (a[0][1] * a[1][0])) * idet;
        b[3][2] = 0.0f;
        b[3][1] = 0.0f;
        b[3][0] = 0.0f;
        b[2][3] = 0.0f;
        b[1][3] = 0.0f;
        b[0][3] = 0.0f;
        b[3][3] = 1.0f;
        success = TRUE;
    }
    return success;
}

u32 func_800260A4_26CA4(Mat4 a, Mat4 b) {
    Mat4 invA;
    u32 success;
    if (func_80025F00_26B00(a, invA)) {
        guMtxCatF(invA, a, b);
        success = TRUE;
    } else {
        guMtxIdentF(b);
        success = FALSE;
    }
    return success;
}

INCLUDE_ASM("asm/nonmatchings/26370", func_80026104_26D04);

INCLUDE_ASM("asm/nonmatchings/26370", func_800261CC_26DCC);

INCLUDE_ASM("asm/nonmatchings/26370", func_800264D8_270D8);

INCLUDE_ASM("asm/nonmatchings/26370", func_8002662C_2722C);
