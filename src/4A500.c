#include "common.h"
#include "game/malloc.h"
#include "game/object.h"

/* Model effects. func_80049900_4A500 and func_80049A38_4A638 are MP1 src/42E40.c's func_80042240 and
   func_80042378 (exact). */

typedef struct Vec3f {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct ModelEffectWork {
    /* 0x00 */ Object* model;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ Vec3f vel;
    /* 0x1C */ Vec3f scale;
    /* 0x28 */ f32 duration;
} ModelEffectWork; /* size = 0x2C */

typedef struct ModelEmitterWork {
    /* 0x00 */ Process* process;
    /* 0x04 */ Object* model;
    /* 0x08 */ Object* parent;
    /* 0x0C */ Vec3f offset;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ s16 type;
    /* 0x1E */ s16 flags;
} ModelEmitterWork; /* size = 0x20 */

extern s16 D_800DF650_E0250;

void MBModelDispOn(Object*);
void MBModelKill(void*);
void MBModelDispOff(Object*);
Object* func_80043510_44110(s32, void*);
void func_80049B2C_4A72C(void);
Object* MBModelParamCreate(Object*);
void func_80029EDC_2AADC(s16, s32);
s16 func_80029F04_2AB04(s16);
void HuVecCopyXYZ(Vec3f*, f32, f32, f32);
void func_800B3170_B3D70(Vec3f* ptr, Vec3f* ptr2);
f32 func_800B7890_B8490(f32);

void func_80049900_4A500(void) {
    ModelEffectWork* work = HuPrcCurrentGet()->user_data;
    Object* model = work->model;
    f32 t;
    f32 s;

    MBModelDispOn(model);
    func_800B3170_B3D70(&model->coords, &work->pos);
    t = 0.0f;
    while (D_800DF650_E0250 != 0) {
        s = func_800B7890_B8490(t);
        HuVecCopyXYZ(&model->scale.x, s * work->scale.x, s * work->scale.y, s * work->scale.z);
        t += 90.0f / work->duration;
        if (t >= 90.0f) {
            break;
        }
        HuPrcVSleep();
        model->coords.x += work->vel.x * work->scale.x;
        model->coords.y += work->vel.y * work->scale.y;
        model->coords.z += work->vel.z * work->scale.z;
    }
    MBModelKill(model);
    omDelPrcObj(NULL);
}

Process* func_80049A38_4A638(Object* model, Vec3f* pos, Vec3f* vel, Vec3f* scale, f32 duration) {
    Process* process = omAddPrcObj(func_80049900_4A500, 0x4700, 0, 0x40);
    ModelEffectWork* work = HuMemMemoryAlloc(process->heap, sizeof(ModelEffectWork));

    process->user_data = work;
    work->model = MBModelParamCreate(model);
    func_80029EDC_2AADC(work->model->omObj1->model[0], func_80029F04_2AB04(model->omObj1->model[0]));
    func_800B3170_B3D70(&work->pos, pos);
    func_800B3170_B3D70(&work->vel, vel);
    func_800B3170_B3D70(&work->scale, scale);
    work->duration = duration;
    return process;
}

INCLUDE_ASM("asm/nonmatchings/4A500", func_80049B2C_4A72C);

/* near MP1 func_80042728 (src/42E40.c): MP2 adds a scale (unk18) to the work. */
void* func_80049ED4_4AAD4(Object* ptr, s16 num) {
    ModelEmitterWork* work;
    Process* process;
    Object* model;

    D_800DF650_E0250 = 1;
    work = HuMemMemoryAllocTemp(sizeof(ModelEmitterWork));
    if (work != NULL) {
        work->process = process = omAddPrcObj(func_80049B2C_4A72C, 0x4700, 0, 0);
        process->user_data = work;
        work->model = model = func_80043510_44110(0x1C, NULL);
        MBModelDispOff(model);
        work->parent = ptr;
        work->type = num;
        HuVecCopyXYZ(&work->offset, 0.0f, -30.0f, 0.0f);
        work->flags = 0;
        work->unk18 = 1.0f;
    }
    return work;
}

INCLUDE_ASM("asm/nonmatchings/4A500", func_80049F90_4AB90);

INCLUDE_ASM("asm/nonmatchings/4A500", func_80049FA0_4ABA0);
