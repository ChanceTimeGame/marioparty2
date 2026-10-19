#include "common.h"
#include "game/malloc.h"

/* Model effects. func_80049900_4A500 and func_80049A38_4A638 are MP1 src/42E40.c's func_80042240 and
   func_80042378 (exact). */

typedef struct Vec3f {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct unk_Struct04 {
    /* 0x00 */ char pad0[0x14];
    /* 0x14 */ void* func_ptr;
    /* 0x18 */ Vec3f pos;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ Vec3f scale;
    /* 0x3C */ u16 mdlcnt;
    /* 0x40 */ s16* unk_40;
} unk_Struct04; /* size = 0x44 */

typedef struct Object {
    /* 0x00 */ struct Object* prev;
    /* 0x04 */ struct Object* next;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ u16 unk_0A;
    /* 0x0C */ Vec3f coords;
    /* 0x18 */ Vec3f unk_18;
    /* 0x24 */ f32 xScale;
    /* 0x28 */ f32 yScale;
    /* 0x2C */ f32 zScale;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ unk_Struct04* unk_3C;
    /* 0x40 */ unk_Struct04* unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ f32 unk_48;
    /* 0x4C */ s32 unk_4C;
    /* 0x50 */ char unk_50[3];
    /* 0x53 */ s8 unk_53;
    /* 0x54 */ char unk_54[0x38];
    /* 0x8C */ struct Object* unk_8C;
} Object; /* size = 0x90 */

typedef struct ModelEffectWork {
    /* 0x00 */ Object* model;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ Vec3f vel;
    /* 0x1C */ Vec3f scale;
    /* 0x28 */ f32 duration;
} ModelEffectWork; /* size = 0x2C */

extern s16 D_800DF650_E0250;

void MBModelDispOn(Object*);
void MBModelKill(void*);
Object* MBModelParamCreate(Object*);
void func_80029EDC_2AADC(s16, s32);
s16 func_80029F04_2AB04(s16);
void func_800B3160_B3D60(Vec3f*, f32, f32, f32);
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
        func_800B3160_B3D60(&model->xScale, s * work->scale.x, s * work->scale.y, s * work->scale.z);
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
    func_80029EDC_2AADC(work->model->unk_3C->unk_40[0], func_80029F04_2AB04(model->unk_3C->unk_40[0]));
    func_800B3170_B3D70(&work->pos, pos);
    func_800B3170_B3D70(&work->vel, vel);
    func_800B3170_B3D70(&work->scale, scale);
    work->duration = duration;
    return process;
}

INCLUDE_ASM("asm/nonmatchings/4A500", func_80049B2C_4A72C);

INCLUDE_ASM("asm/nonmatchings/4A500", func_80049ED4_4AAD4);

INCLUDE_ASM("asm/nonmatchings/4A500", func_80049F90_4AB90);

INCLUDE_ASM("asm/nonmatchings/4A500", func_80049FA0_4ABA0);
