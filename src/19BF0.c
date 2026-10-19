#include "common.h"
#include "game/data.h"

/* Actor motion helpers. Functions with C come from MP1 src/18650.c and MP3
   src/overlays/minigame/B7600.c; MP2's actor work is laid out differently (offsets below). */

typedef struct MotionEntry {
    /* 0x00 */ u16 flags;
    /* 0x02 */ u16 speed;
    /* 0x04 */ char unk_04[8];
} MotionEntry; // size 0xC

typedef struct MotionReq {
    /* 0x00 */ u16 flags;
    /* 0x02 */ u16 motion;
} MotionReq;

typedef struct ActorWork {
    /* 0x00 */ char unk_00[0x50];
    /* 0x50 */ u16 flags;
    /* 0x52 */ char unk_52[0x56];
    /* 0xA8 */ u16 unk_A8;
    /* 0xAA */ char unk_AA[0x2E];
    /* 0xD8 */ MotionReq req;
    /* 0xDC */ char unk_DC[0xC];
    /* 0xE8 */ MotionEntry* table;
} ActorWork;

typedef struct ModelUnk9C {
    /* 0x00 */ char unk_00[8];
    /* 0x08 */ s32 unk_08;
} ModelUnk9C;

typedef struct ModelUnk64 {
    /* 0x00 */ char unk_00[0x9C];
    /* 0x9C */ ModelUnk9C* unk_9C;
} ModelUnk64;

typedef struct ModelData {
    /* 0x00 */ char unk_00[0x64];
    /* 0x64 */ ModelUnk64* unk_64;
    /* 0x68 */ char unk_68[0x58];
} ModelData; // size 0xC0

extern ModelData* D_800FC834_FD434;

void func_80029714_2A314(s16, f32, f32, f32);
void func_8002979C_2A39C(s16, f32, f32, f32);
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029C74_2A874(s16, f32);
f32 func_80029CE4_2A8E4(s16);
f32 func_80029D0C_2A90C(s16);
s16 func_80029E14_2AA14(s16);
void func_8002C524_2D124(s16, s16, s16);
s32 func_8002C8B8_2D4B8(void*, s32);
s32 func_80019CA4_1A8A4(omObjData* obj, u16 motion);
void func_80019E04_1AA04(omObjData* obj, s32 idx, u16 motion);
void func_80019114_19D14(u8 mdl);

INCLUDE_ASM("asm/nonmatchings/19BF0", func_80018FF0_19BF0);

INCLUDE_ASM("asm/nonmatchings/19BF0", func_80019000_19C00);

void func_80019114_19D14(u8 mdl) {
    f32 cur;

    if (mdl != 0) {
        cur = func_80029CE4_2A8E4(mdl);
        if (func_80029D0C_2A90C(mdl) <= cur) {
            func_800298A4_2A4A4(mdl, 4, 4);
        }
    }
}

void func_80019178_19D78(omObjData* obj) {
    s32 i;

    i = 3;
loop:
    if (i < obj->mdlcnt) {
        func_80019114_19D14(obj->model[i++]);
        if (i < 9) {
            goto loop;
        }
    }
}

void func_800191D4_19DD4(omObjData* obj, u8 idx, f32 x, f32 y, f32 z, f32 a, f32 b) {
    u8 mdl = obj->model[idx];
    f32 cur;

    if (obj->mdlcnt > idx) {
        if (mdl != 0) {
            cur = func_80029CE4_2A8E4(mdl);
            if (func_80029D0C_2A90C(mdl) <= cur) {
                if (D_800FC834_FD434[mdl].unk_64->unk_9C != NULL) {
                    D_800FC834_FD434[mdl].unk_64->unk_9C->unk_08 = 0;
                }
                func_80029C74_2A874(mdl, 0.0f);
            }
            func_800298A4_2A4A4(mdl, 4, 0);
            func_80029714_2A314(mdl, x, y, z);
            func_8002979C_2A39C(mdl, a, b, 0.0f);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/19BF0", func_800192E4_19EE4);

INCLUDE_ASM("asm/nonmatchings/19BF0", func_80019378_19F78);

INCLUDE_ASM("asm/nonmatchings/19BF0", func_80019644_1A244);

void func_80019B28_1A728(omObjData* obj, u8 flags) {
    ActorWork* w = obj->unk_50;

    w->flags |= flags;
    w->unk_A8 = 0;
}

INCLUDE_ASM("asm/nonmatchings/19BF0", func_80019B44_1A744);

s32 func_80019B70_1A770(omObjData* obj, u16 motion) {
    return ((ActorWork*)obj->unk_50)->req.motion == motion;
}

INCLUDE_ASM("asm/nonmatchings/19BF0", func_80019B88_1A788);

INCLUDE_ASM("asm/nonmatchings/19BF0", func_80019B9C_1A79C);

INCLUDE_ASM("asm/nonmatchings/19BF0", func_80019CA4_1A8A4);

s32 func_80019D54_1A954(omObjData* obj, u16 motion, u16 next) {
    ActorWork* w = obj->unk_50;

    if (func_80019CA4_1A8A4(obj, motion) == 1) {
        func_80019E04_1AA04(obj, 22, next);
        w->flags |= 0x100;
        return 1;
    }
    return 0;
}

void func_80019DC0_1A9C0(omObjData* obj, s32 src, s32 dst) {
    obj->motion[dst] = obj->motion[src];
}

INCLUDE_ASM("asm/nonmatchings/19BF0", func_80019DE0_1A9E0);

INCLUDE_ASM("asm/nonmatchings/19BF0", func_80019E04_1AA04);

INCLUDE_ASM("asm/nonmatchings/19BF0", func_80019E84_1AA84);

void func_80019F0C_1AB0C(omObjData* arg0, u16 arg1, s32 arg2, s32 arg3, u16 arg4) {
    ActorWork* temp_a1;
    MotionEntry* temp_v0_2;
    s16 temp_v0;

    temp_v0 = func_8002C8B8_2D4B8(DataRead(arg2), 0x18);
    if (temp_v0 < 0) {
        return;
    }
    temp_a1 = (ActorWork*)arg0->unk_50;
    arg0->motion[arg1] = temp_v0;
    temp_v0_2 = &temp_a1->table[arg1];
    temp_v0_2->flags = arg3 | 4;
    temp_v0_2->speed = arg4;
}

INCLUDE_ASM("asm/nonmatchings/19BF0", func_80019FA4_1ABA4);

INCLUDE_ASM("asm/nonmatchings/19BF0", func_8001A014_1AC14);

INCLUDE_ASM("asm/nonmatchings/19BF0", func_8001A12C_1AD2C);
