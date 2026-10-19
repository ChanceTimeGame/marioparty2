#include "common.h"
#include "game/malloc.h"
#include "game/data.h"

/* Board models (MBModel): motion reference counts and the model list, from MP1 src/3E560.c (and
   one helper shaped like MP1 src/53C80.c's func_800532F4: kill every board model). Functions
   without MP1 C, or only near it, stay asm. */

typedef struct MBModel {
    /* 0x00 */ struct MBModel* next;
    /* 0x04 */ struct MBModel* prev;
    /* 0x08 */ u8 id;
    /* 0x0A */ u16 attr;
    /* 0x0C */ Vec pos;
    /* 0x18 */ Vec rot;
    /* 0x24 */ Vec scale;
    /* 0x30 */ f32 jumpY;
    /* 0x34 */ f32 jumpVel;
    /* 0x38 */ f32 jumpAccel;
    /* 0x3C */ omObjData* obj;
    /* 0x40 */ omObjData* shadow;
    /* 0x44 */ s16 baseMot;
    /* 0x46 */ s16 curMot;
} MBModel; // sizeof 0x48

#define MB(o) ((MBModel*)(o))

extern MBModel* D_800DF3A0_DFFA0;
extern u16 D_800DF3A4_DFFA4;
extern s16 D_800DF3A8_DFFA8[128];
extern u16 D_80101330_101F30;

s16 func_8002C8B8_2D4B8(void*, s16);
void func_80039018_39C18(s16);
void func_800B3160_B3D60(Vec*, f32, f32, f32);
void func_80029AFC_2A6FC(s16);
void func_800298A4_2A4A4(s16, s32, s32);
void func_8002C9C0_2D5C0(s16, s16);
void func_800283DC_28FDC(s16);
void func_80029E80_2AA80(s16, s32, s32);
void func_80029BF0_2A7F0(s16, s16, s16, s16, s16);
f32 func_80029CE4_2A8E4(s16);
f32 func_80029D0C_2A90C(s16);
void omDelObj(omObjData*);
void func_80043334_43F34(s16);
void MBModelAttrSetDispOn(MBModel*);
void MBModelAttrSetDispOff(MBModel*);
void MBModelKill(void*);

/* exact c: marioparty func_8003D960 (src/3E560.c) */
void func_80043290_43E90(void) {
    s32 i;

    for (i = 0; i < 128; i++) {
        D_800DF3A8_DFFA8[i] = 0;
    }
}

/* exact c: marioparty func_8003D990 (src/3E560.c) */
s16 func_800432C0_43EC0(s16 arg0) {
    D_800DF3A8_DFFA8[arg0]++;
    return arg0;
}

/* exact c: marioparty func_8003D9B8 (src/3E560.c) */
s16 func_800432E8_43EE8(s32 arg0) {
    s16 idx = func_8002C8B8_2D4B8(DataRead(arg0), 8);

    D_800DF3A8_DFFA8[idx]++;
    return idx;
}

/* exact c: marioparty func_8003DA04 (src/3E560.c) */
void func_80043334_43F34(s16 arg0) {
    if (D_800DF3A8_DFFA8[arg0] != 0) {
        if (--D_800DF3A8_DFFA8[arg0] == 0) {
            func_80039018_39C18(arg0);
        }
    }
}

/* exact c: marioparty func_8003DA58 (src/3E560.c) */
s16 func_80043388_43F88(s16 arg0) {
    if (D_800DF3A8_DFFA8[arg0] != 0) {
        D_800DF3A8_DFFA8[arg0]++;
        return arg0;
    }
    return -1;
}

/* exact c: marioparty MBModelInit (src/3E560.c) */
void MBModelInit(void) {
    D_800DF3A0_DFFA0 = NULL;
    D_800DF3A4_DFFA4 = 0;
    D_80101330_101F30 = 1;
    func_80043290_43E90();
}

/* exact c: marioparty func_800532F4 (src/53C80.c) */
void func_8004340C_4400C(void) {
    while (D_800DF3A0_DFFA0 != NULL) {
        MBModelKill(D_800DF3A0_DFFA0);
    }
}

/* exact c: marioparty func_8003DB1C (src/3E560.c) */
MBModel* func_8004344C_4404C(void) {
    MBModel* m = HuMemMemoryAllocTemp(sizeof(MBModel));

    if (m != NULL) {
        D_800DF3A4_DFFA4++;
        m->next = D_800DF3A0_DFFA0;
        m->prev = NULL;
        if (D_800DF3A0_DFFA0 != NULL) {
            D_800DF3A0_DFFA0->prev = m;
        }
        D_800DF3A0_DFFA0 = m;
        m->attr = 8;
        func_800B3160_B3D60(&m->pos, 0.0f, 0.0f, 0.0f);
        func_800B3160_B3D60(&m->rot, 0.0f, 0.0f, 1.0f);
        func_800B3160_B3D60(&m->scale, 1.0f, 1.0f, 1.0f);
        m->jumpY = 0.0f;
        m->jumpVel = 0.0f;
        m->jumpAccel = 0.0f;
        m->baseMot = -1;
        m->curMot = -1;
    }
    return m;
}

INCLUDE_ASM("asm/nonmatchings/43E90", func_80043510_44110);

INCLUDE_ASM("asm/nonmatchings/43E90", MBModelFileCreate);

INCLUDE_ASM("asm/nonmatchings/43E90", func_80043A60_44660);

INCLUDE_ASM("asm/nonmatchings/43E90", func_80043C64_44864);

/* exact c: marioparty func_8003E174 (src/3E560.c) */
void func_80043DAC_449AC(void* ptr) {
    MBModel* m = (MBModel*)ptr;

    func_80029AFC_2A6FC(*m->obj->model);
    if (m->shadow != NULL) {
        func_80029AFC_2A6FC(*m->shadow->model);
    }
}

INCLUDE_ASM("asm/nonmatchings/43E90", func_80043DF4_449F4);

INCLUDE_ASM("asm/nonmatchings/43E90", func_80043F7C_44B7C);

/* exact c: marioparty MBModelAttrSetDispOn (src/3E560.c) */
void MBModelAttrSetDispOn(MBModel* arg0) {
    func_800298A4_2A4A4(*arg0->obj->model, 4, 0);
    if (arg0->shadow != NULL) {
        func_800298A4_2A4A4(*arg0->shadow->model, 4, 0);
    }
}

/* exact c: marioparty MBModelDispOn (src/3E560.c) */
void MBModelDispOn(MBModel* arg0) {
    MBModelAttrSetDispOn(arg0);
    arg0->attr |= 8;
}

/* exact c: marioparty MBModelAttrSetDispOff (src/3E560.c) */
void MBModelAttrSetDispOff(MBModel* arg0) {
    func_800298A4_2A4A4(*arg0->obj->model, 4, 4);
    if (arg0->shadow != NULL) {
        func_800298A4_2A4A4(*arg0->shadow->model, 4, 4);
    }
}

/* exact c: marioparty MBModelDispOff (src/3E560.c) */
void MBModelDispOff(MBModel* arg0) {
    MBModelAttrSetDispOff(arg0);
    arg0->attr &= ~8;
}

/* exact c: marioparty MBModelKill (src/3E560.c) */
void MBModelKill(void* arg0) {
    MBModel* m = arg0;
    s32 i;

    if (m->next != NULL) {
        m->next->prev = m->prev;
    }
    if (m->prev != NULL) {
        m->prev->next = m->next;
    } else {
        D_800DF3A0_DFFA0 = m->next;
    }
    func_8002C9C0_2D5C0(*m->obj->model, -1);
    func_800283DC_28FDC(*m->obj->model);
    if (m->shadow != NULL) {
        func_800283DC_28FDC(*m->shadow->model);
    }
    for (i = 0; i < m->obj->mtncnt; i++) {
        func_80043334_43F34(m->obj->motion[i]);
    }
    if (m->baseMot != -1) {
        func_80043334_43F34(m->baseMot);
    }
    HuMemMemoryFreeTemp(m->obj->unk_50);
    m->obj->unk_50 = NULL;
    omDelObj(m->obj);
    if (m->shadow != NULL) {
        HuMemMemoryFreeTemp(m->shadow->unk_50);
        m->shadow->unk_50 = NULL;
        omDelObj(m->shadow);
    }
    HuMemMemoryFreeTemp(m);
    D_800DF3A4_DFFA4--;
}

/* exact c: marioparty MBModelCheck (src/3E560.c) */
s32 MBModelCheck(void* arg0) {
    MBModel* m;

    for (m = D_800DF3A0_DFFA0; m != NULL; m = m->next) {
        if (m == arg0) {
            return 1;
        }
    }
    return 0;
}

/* exact c: marioparty MBMotionSet (src/3E560.c) */
void MBMotionSet(void* arg0, s16 arg1, u16 arg2) {
    u16 mot;

    if (arg1 == -1) {
        mot = MB(arg0)->baseMot;
        MB(arg0)->curMot = arg1;
    } else {
        mot = MB(arg0)->obj->motion[arg1];
        MB(arg0)->curMot = arg1;
    }
    func_8002C9C0_2D5C0(*MB(arg0)->obj->model, mot);
    func_80029E80_2AA80(*MB(arg0)->obj->model, -1, (s16)arg2);
}

/* exact c: marioparty MBMotionShiftSet (src/3E560.c) */
void MBMotionShiftSet(void* ptr, s16 a, s16 b, s16 c, u16 d) {
    MBModel* m = (MBModel*)ptr;
    u16 mot;

    if (a == -1) {
        mot = m->baseMot;
        m->curMot = a;
    } else {
        mot = m->obj->motion[a];
        m->curMot = a;
    }
    func_80029BF0_2A7F0(*m->obj->model, mot, b, c, d);
}

/* exact c: marioparty MBMotionCheck (src/3E560.c) */
u16 MBMotionCheck(void* arg0) {
    MBModel* m = (MBModel*)arg0;
    s32 ret = 0;
    s16 model = *m->obj->model;
    f32 cur = func_80029CE4_2A8E4(model);

    if (cur == func_80029D0C_2A90C(model)) {
        ret = 1;
    }
    return ret;
}

INCLUDE_ASM("asm/nonmatchings/43E90", func_80044620_45220);

INCLUDE_ASM("asm/nonmatchings/43E90", func_800446B4_452B4);

