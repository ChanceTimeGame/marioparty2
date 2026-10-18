#include "common.h"

/* Vector angle and rotation helpers (MP1 src/3DEB0.c). */

f32 HuVecGetLength3F(Vec*);
f32 func_800B75A8_B81A8(f32, f32);
f32 func_800B7890_B8490(f32);
f32 func_800B83C0_B8FC0(f32);

void func_800B33E0_B3FE0(Vec*);
f32 func_800B3500_B4100(Vec*, Vec*);
f64 func_800B0828_B1428(f64);


f32 func_80042BE0_437E0(Vec* v) {
    f32 a;

    if (v->x != 0.0f || v->z != 0.0f) {
        if (v->x == 0.0f) {
            if (0.0f < v->z) {
                return 0.0f;
            }
            return 180.0f;
        }
        if (v->z == 0.0f) {
            if (0.0f < v->x) {
                return 90.0f;
            }
            return 270.0f;
        }
        a = func_800B75A8_B81A8(v->z, v->x);
        if (v->z < 0.0f) {
            a = 90.0f - a;
        } else {
            a = 90.0f - a;
            if (a < 0.0f) {
                a += 360.0f;
            }
        }
        return a;
    }
    return -1.0f;
}
void func_80042D38_43938(Vec* v) {
    if (v->x == 0.0f && v->y == 0.0f && v->z == 0.0f) {
        v->z = 1.0f;
    }
    func_800B33E0_B3FE0(v);
}
void func_80042DA8_439A8(Vec* v, f32 angle) {
    Vec orig;

    orig.y = v->y;
    orig.z = v->z;
    v->y = func_800B7890_B8490(angle) * orig.y - func_800B83C0_B8FC0(angle) * orig.z;
    v->z = func_800B7890_B8490(angle) * orig.z + func_800B83C0_B8FC0(angle) * orig.y;
}
void func_80042E44_43A44(Vec* v, f32 angle) {
    Vec orig;

    orig.x = v->x;
    orig.z = v->z;
    v->x = func_800B7890_B8490(angle) * orig.x + func_800B83C0_B8FC0(angle) * orig.z;
    v->z = func_800B7890_B8490(angle) * orig.z - func_800B83C0_B8FC0(angle) * orig.x;
}
void func_80042EE0_43AE0(Vec* v, f32 angle) {
    Vec orig;

    orig.x = v->x;
    orig.y = v->y;
    v->x = func_800B7890_B8490(angle) * orig.x - func_800B83C0_B8FC0(angle) * orig.y;
    v->y = func_800B7890_B8490(angle) * orig.y + func_800B83C0_B8FC0(angle) * orig.x;
}
void func_80042F7C_43B7C(Vec* v, Vec* axis, f32 angle) {
    Vec orig;

    orig.x = v->x;
    orig.y = v->y;
    orig.z = v->z;
    func_80042D38_43938(axis);
    v->x = (axis->x * axis->x + (1.0f - axis->x * axis->x) * func_800B7890_B8490(angle)) * orig.x +
           (axis->x * axis->y * (1.0f - func_800B7890_B8490(angle)) - func_800B83C0_B8FC0(angle) * axis->z) * orig.y +
           (axis->x * axis->z * (1.0f - func_800B7890_B8490(angle)) + func_800B83C0_B8FC0(angle) * axis->y) * orig.z;
    v->y = (axis->x * axis->y * (1.0f - func_800B7890_B8490(angle)) + func_800B83C0_B8FC0(angle) * axis->z) * orig.x +
           (axis->y * axis->y + (1.0f - axis->y * axis->y) * func_800B7890_B8490(angle)) * orig.y +
           (axis->y * axis->z * (1.0f - func_800B7890_B8490(angle)) - func_800B83C0_B8FC0(angle) * axis->x) * orig.z;
    v->z = (axis->x * axis->z * (1.0f - func_800B7890_B8490(angle)) - func_800B83C0_B8FC0(angle) * axis->y) * orig.x +
           (axis->y * axis->z * (1.0f - func_800B7890_B8490(angle)) + func_800B83C0_B8FC0(angle) * axis->x) * orig.y +
           (axis->z * axis->z + (1.0f - axis->z * axis->z) * func_800B7890_B8490(angle)) * orig.z;
}
// register allocation: the length product lands in $f20, retail $f12 (masked 0)
#ifdef NON_MATCHING
f32 func_800431FC_43DFC(Vec* a, Vec* b) {
    f32 dot;
    f32 len;

    dot = func_800B3500_B4100(a, b);
    len = HuVecGetLength3F(a) * HuVecGetLength3F(b);
    if (len != 0.0f) {
        return func_800B0828_B1428(dot / len) / 0.017453292519943295;
    }
    return 0.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/437E0", func_800431FC_43DFC);
#endif
