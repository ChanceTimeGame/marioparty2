#include "common.h"
#include "game/malloc.h"
#include "game/data.h"
#include "game/board.h"

/* Board models (MBModel): motion reference counts and the model list, from MP1 src/3E560.c (and
   one helper shaped like MP1 src/53C80.c's func_800532F4: kill every board model). Functions
   without MP1 C, or only near it, stay asm. */

#define MB(o) ((MBModel*)(o))

extern MBModel* D_800DF3A0_DFFA0;
extern u16 D_800DF3A4_DFFA4;
extern s16 D_800DF3A8_DFFA8[128];
extern u16 D_80101330_101F30;

s16 func_8002C8B8_2D4B8(void*, s16);
void func_80039018_39C18(s16);
void HuVecCopyXYZ(Vec*, f32, f32, f32);
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

typedef struct MBModelWork {
    /* 0x00 */ MBModel* model;
    /* 0x04 */ f32 scale;
} MBModelWork; /* size = 0x8 */

typedef struct MBModelParam {
    /* 0x00 */ f32 scale;
    /* 0x04 */ f32 shadowScale;
    /* 0x08 */ char unk08[8];
} MBModelParam; /* size = 0x10 */

extern MBModelParam D_800CB168_CBD68[];

/* The same table from its start: D_800CB168_CBD68 is its +8 view. */
typedef struct MBModelFiles {
    /* 0x00 */ s32 file;
    /* 0x04 */ s32 shadowFile;
    /* 0x08 */ f32 scale;
    /* 0x0C */ f32 shadowScale;
} MBModelFiles; /* size = 0x10 */

/* .data (0xCBD60-0xCC880): board model files and scales. Layout-dependent: asm and the
   MBModelParam view read it through D_800CB164/168/16C, aliases at +4/+8/+0xC (undefined_syms.txt). */
MBModelFiles D_800CB160_CBD60[178] = {
    { 0x000200D3, 0x0000000D, 1.0f, 0.9f },
    { 0x000300D3, 0x0000000D, 1.0f, 0.9f },
    { 0x000700D3, 0x0000000D, 1.0f, 1.2f },
    { 0x000400D3, 0x0000000D, 1.0f, 1.1f },
    { 0x000500D3, 0x0000000D, 1.0f, 1.1f },
    { 0x000600D3, 0x0000000D, 1.0f, 1.5f },
    { 0x0008003C, 0x0000000D, 0.7f, 1.4f },
    { 0x00080000, 0x0000000D, 1.0f, 1.0f },
    { 0x000A0084, 0x0000000D, 1.0f, 1.2f },
    { 0x000800BE, 0x000A015A, 0.5f, 2.0f },
    { 0x000800A6, 0x0000000D, 1.0f, 1.0f },
    { 0x000800BD, 0x000A015A, 1.0f, 2.0f },
    { 0x000A02A8, 0x0000000D, 1.0f, 0.0f },
    { 0x000A015B, 0x0000000D, 1.0f, 0.0f },
    { 0x000A0156, 0x0000000D, 1.0f, 0.0f },
    { 0x000200D1, 0x0000000D, 1.0f, 0.9f },
    { 0x000300D1, 0x0000000D, 1.0f, 0.9f },
    { 0x000700D1, 0x0000000D, 1.0f, 1.2f },
    { 0x000400D1, 0x0000000D, 1.0f, 1.1f },
    { 0x000500D1, 0x0000000D, 1.0f, 1.1f },
    { 0x000600D1, 0x0000000D, 1.0f, 1.5f },
    { 0x000A0157, 0x0000000D, 1.0f, 0.0f },
    { 0x000A0158, 0x0000000D, 1.0f, 0.0f },
    { 0x0008000D, 0x0000000D, 1.2f, 0.7f },
    { 0x00000027, 0x0000000D, 0.15f, 0.0f },
    { 0x000A0159, 0x0000000D, 1.0f, 0.0f },
    { 0x00080000, 0x0000000D, 1.0f, 0.0f },
    { 0x000A015D, 0x0000000D, 1.0f, 0.0f },
    { 0x000A00E3, 0x0000000D, 1.0f, 0.0f },
    { 0x000800BB, 0x0000000D, 1.2f, 0.7f },
    { 0x000200D4, 0x0000000D, 1.0f, 0.9f },
    { 0x000300D4, 0x0000000D, 1.0f, 0.9f },
    { 0x000700D4, 0x0000000D, 1.0f, 1.2f },
    { 0x000400D4, 0x0000000D, 1.0f, 1.1f },
    { 0x000500D4, 0x0000000D, 1.0f, 1.1f },
    { 0x000600D4, 0x0000000D, 1.0f, 1.5f },
    { 0x000200D5, 0x0000000D, 1.0f, 0.9f },
    { 0x000300D5, 0x0000000D, 1.0f, 0.9f },
    { 0x000700D5, 0x0000000D, 1.0f, 1.2f },
    { 0x000400D5, 0x0000000D, 1.0f, 1.1f },
    { 0x000500D5, 0x0000000D, 1.0f, 1.1f },
    { 0x000600D5, 0x0000000D, 1.0f, 1.5f },
    { 0x000200D6, 0x0000000D, 1.0f, 0.9f },
    { 0x000300D6, 0x0000000D, 1.0f, 0.9f },
    { 0x000700D6, 0x0000000D, 1.0f, 1.2f },
    { 0x000400D6, 0x0000000D, 1.0f, 1.1f },
    { 0x000500D6, 0x0000000D, 1.0f, 1.1f },
    { 0x000600D6, 0x0000000D, 1.0f, 1.5f },
    { 0x000200D7, 0x0000000D, 1.0f, 0.9f },
    { 0x000300D7, 0x0000000D, 1.0f, 0.9f },
    { 0x000700D7, 0x0000000D, 1.0f, 1.2f },
    { 0x000400D7, 0x0000000D, 1.0f, 1.1f },
    { 0x000500D7, 0x0000000D, 1.0f, 1.1f },
    { 0x000600D7, 0x0000000D, 1.0f, 1.5f },
    { 0x000200D8, 0x0000000D, 1.0f, 0.9f },
    { 0x000300D8, 0x0000000D, 1.0f, 0.9f },
    { 0x000700D8, 0x0000000D, 1.0f, 1.2f },
    { 0x000400D8, 0x0000000D, 1.0f, 1.1f },
    { 0x000500D8, 0x0000000D, 1.0f, 1.1f },
    { 0x000600D8, 0x0000000D, 1.0f, 1.5f },
    { 0x000200D9, 0x0000000D, 1.0f, 0.9f },
    { 0x000300D9, 0x0000000D, 1.0f, 0.9f },
    { 0x000700D9, 0x0000000D, 1.0f, 1.2f },
    { 0x000400D9, 0x0000000D, 1.0f, 1.1f },
    { 0x000500D9, 0x0000000D, 1.0f, 1.1f },
    { 0x000600D9, 0x0000000D, 1.0f, 1.5f },
    { 0x000200DA, 0x0000000D, 1.0f, 0.9f },
    { 0x000300DA, 0x0000000D, 1.0f, 0.9f },
    { 0x000700DA, 0x0000000D, 1.0f, 1.2f },
    { 0x000400DA, 0x0000000D, 1.0f, 1.1f },
    { 0x000500DA, 0x0000000D, 1.0f, 1.1f },
    { 0x000600DA, 0x0000000D, 1.0f, 1.5f },
    { 0x000200DB, 0x0000000D, 1.0f, 0.9f },
    { 0x000300DB, 0x0000000D, 1.0f, 0.9f },
    { 0x000700DB, 0x0000000D, 1.0f, 1.2f },
    { 0x000400DB, 0x0000000D, 1.0f, 1.1f },
    { 0x000500DB, 0x0000000D, 1.0f, 1.1f },
    { 0x000600DB, 0x0000000D, 1.0f, 1.5f },
    { 0x000200DC, 0x0000000D, 1.0f, 0.9f },
    { 0x000300DC, 0x0000000D, 1.0f, 0.9f },
    { 0x000700DC, 0x0000000D, 1.0f, 1.2f },
    { 0x000400DC, 0x0000000D, 1.0f, 1.1f },
    { 0x000500DC, 0x0000000D, 1.0f, 1.1f },
    { 0x000600DC, 0x0000000D, 1.0f, 1.5f },
    { 0x000200DD, 0x0000000D, 1.0f, 0.9f },
    { 0x000300DD, 0x0000000D, 1.0f, 0.9f },
    { 0x000700DD, 0x0000000D, 1.0f, 1.2f },
    { 0x000400DD, 0x0000000D, 1.0f, 1.1f },
    { 0x000500DD, 0x0000000D, 1.0f, 1.1f },
    { 0x000600DD, 0x0000000D, 1.0f, 1.5f },
    { 0x000200D3, 0x0000000D, 1.0f, 0.9f },
    { 0x000300D3, 0x0000000D, 1.0f, 0.9f },
    { 0x000700D3, 0x0000000D, 1.0f, 1.2f },
    { 0x000400D3, 0x0000000D, 1.0f, 1.1f },
    { 0x000500D3, 0x0000000D, 1.0f, 1.1f },
    { 0x000600D3, 0x0000000D, 1.0f, 1.5f },
    { 0x000200D1, 0x0000000D, 1.0f, 0.9f },
    { 0x000300D1, 0x0000000D, 1.0f, 0.9f },
    { 0x000700D1, 0x0000000D, 1.0f, 1.2f },
    { 0x000400D1, 0x0000000D, 1.0f, 1.1f },
    { 0x000500D1, 0x0000000D, 1.0f, 1.1f },
    { 0x000600D1, 0x0000000D, 1.0f, 1.5f },
    { 0x0008004B, 0x0000000D, 0.7f, 1.4f },
    { 0x00080051, 0x0000000D, 0.7f, 1.4f },
    { 0x00080059, 0x0000000D, 0.7f, 1.4f },
    { 0x0008005B, 0x0000000D, 0.7f, 1.4f },
    { 0x0008005F, 0x0000000D, 0.7f, 1.4f },
    { 0x0008004A, 0x0000000D, 0.7f, 1.4f },
    { 0x000A0154, 0x0000000D, 1.0f, 0.0f },
    { 0x000A019D, 0x0000000D, 1.0f, 0.0f },
    { 0x000A0184, 0x0000000D, 1.0f, 0.0f },
    { 0x000A0188, 0x0000000D, 1.0f, 0.0f },
    { 0x00080081, 0x0000000D, 0.7f, 1.4f },
    { 0x000A0185, 0x0000000D, 1.0f, 0.0f },
    { 0x000A0187, 0x0000000D, 1.0f, 0.0f },
    { 0x000A0195, 0x0000000D, 1.0f, 0.0f },
    { 0x000A018A, 0x0000000D, 1.0f, 0.0f },
    { 0x000A018B, 0x0000000D, 1.0f, 0.0f },
    { 0x0008000E, 0x0000000D, 1.0f, 0.7f },
    { 0x00080016, 0x0000000D, 1.0f, 0.7f },
    { 0x00080028, 0x0000000D, 1.0f, 0.7f },
    { 0x0008001C, 0x0000000D, 1.0f, 0.7f },
    { 0x00080023, 0x0000000D, 1.0f, 0.7f },
    { 0x000800B0, 0x0000000D, 1.0f, 0.7f },
    { 0x000A019F, 0x0000000D, 1.0f, 0.0f },
    { 0x000A01A3, 0x0000000D, 1.0f, 0.0f },
    { 0x000A01A4, 0x0000000D, 1.0f, 0.0f },
    { 0x000A01A5, 0x0000000D, 1.0f, 0.0f },
    { 0x000A022A, 0x0000000D, 1.0f, 0.0f },
    { 0x000A01E2, 0x0000000D, 1.0f, 0.0f },
    { 0x000A0200, 0x0000000D, 1.0f, 0.0f },
    { 0x000A0210, 0x0000000D, 1.0f, 0.0f },
    { 0x000A01E4, 0x0000000D, 1.0f, 1.0f },
    { 0x000A01E5, 0x0000000D, 1.0f, 2.0f },
    { 0x000A01E6, 0x0000000D, 1.0f, 2.0f },
    { 0x000A01E7, 0x0000000D, 1.0f, 2.0f },
    { 0x000A01F0, 0x0000000D, 1.0f, 0.0f },
    { 0x000A0201, 0x0000000D, 1.0f, 0.0f },
    { 0x000A0206, 0x0000000D, 1.0f, 0.0f },
    { 0x000A0207, 0x0000000D, 1.0f, 0.0f },
    { 0x000A020A, 0x0000000D, 1.0f, 0.0f },
    { 0x000A0209, 0x0000000D, 1.0f, 0.0f },
    { 0x000A020B, 0x0000000D, 1.0f, 0.0f },
    { 0x000A020C, 0x0000000D, 1.0f, 0.0f },
    { 0x000A0211, 0x0000000D, 1.0f, 0.0f },
    { 0x000A0212, 0x0000000D, 1.0f, 0.0f },
    { 0x000A0213, 0x0000000D, 1.0f, 0.0f },
    { 0x000A0214, 0x0000000D, 1.0f, 0.0f },
    { 0x000A0215, 0x0000000D, 1.0f, 0.0f },
    { 0x000A0216, 0x0000000D, 1.0f, 0.0f },
    { 0x000A0217, 0x0000000D, 1.0f, 0.0f },
    { 0x000A0218, 0x0000000D, 1.0f, 0.0f },
    { 0x000A0219, 0x0000000D, 1.0f, 0.0f },
    { 0x000A021A, 0x0000000D, 1.0f, 0.0f },
    { 0x000A021B, 0x0000000D, 1.0f, 0.0f },
    { 0x000A021C, 0x0000000D, 1.0f, 0.0f },
    { 0x000A0227, 0x0000000D, 1.0f, 0.0f },
    { 0x000A0228, 0x0000000D, 1.0f, 0.0f },
    { 0x000A0229, 0x0000000D, 1.0f, 0.0f },
    { 0x000A020F, 0x0000000D, 1.0f, 0.0f },
    { 0x000A022B, 0x0000000D, 1.0f, 1.0f },
    { 0x000A022E, 0x0000000D, 1.0f, 1.0f },
    { 0x000A0232, 0x0000000D, 2.0f, 0.0f },
    { 0x000A0240, 0x0000000D, 1.0f, 0.0f },
    { 0x000A0233, 0x0000000D, 1.0f, 0.0f },
    { 0x000A0250, 0x0000000D, 1.0f, 0.0f },
    { 0x00080007, 0x0000000D, 1.0f, 0.7f },
    { 0x00080035, 0x0000000D, 1.0f, 0.7f },
    { 0x000800CD, 0x0000000D, 1.0f, 1.0f },
    { 0x000A0252, 0x0000000D, 1.0f, 0.0f },
    { 0x000A0257, 0x0000000D, 1.0f, 0.0f },
    { 0x000A025A, 0x0000000D, 1.0f, 0.0f },
    { 0x000A0254, 0x0000000D, 1.0f, 0.0f },
    { 0x000A0255, 0x0000000D, 1.0f, 0.0f },
    { 0x000A0256, 0x0000000D, 1.0f, 0.0f },
    { 0x000A0258, 0x0000000D, 1.0f, 0.0f },
    { 0x000A0259, 0x0000000D, 1.0f, 0.0f },
    { 0x000A025B, 0x0000000D, 1.0f, 0.0f },
};
void func_800297E8_2A3E8(s16, f32, f32, f32);
typedef struct Vec2fxy {
    f32 x;
    f32 y;
} Vec2fxy; /* as in 51630.c */
void MBDCamera3Dto2D(Vec*, Vec2fxy*);

void omSetRot(omObjData*, f32, f32, f32);
s16 LoadFormFile(s32, s32);
s32 func_80027D3C_2893C(s16);
void func_80029EDC_2AADC(s16, s32);
s16 func_80029E14_2AA14(s16);
f32 MBDBackMdlScaleGet(void);
void func_80043A60_44660(omObjData*);
void func_80043C64_44864(omObjData*);
MBModel* func_8004344C_4404C(void);
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32);
f32 func_80042BE0_437E0(Vec*);
void func_80056658_57258(Vec*, Vec*, Vec*);

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
        HuVecCopyXYZ(&m->pos, 0.0f, 0.0f, 0.0f);
        HuVecCopyXYZ(&m->rot, 0.0f, 0.0f, 1.0f);
        HuVecCopyXYZ(&m->scale, 1.0f, 1.0f, 1.0f);
        m->jumpY = 0.0f;
        m->jumpVel = 0.0f;
        m->jumpAccel = 0.0f;
        m->baseMot = -1;
        m->curMot = -1;
    }
    return m;
}

/* MP1 MBModelCreate (src/3E560.c): MP2 adds func_800297E8_2A3E8, reads the base motion only when
   the model has one and picks the shadow's load flags by flag 0xD. */
MBModel* func_80043510_44110(u8 id, void* arg1) {
    MBModel* m;
    u16 mtncnt;
    omObjData* obj;
    MBModelWork* work;
    s16 model;
    s16 i;

    mtncnt = 0;
    m = func_8004344C_4404C();
    if (m != NULL) {
        m->id = id;
        if (arg1 != NULL) {
            mtncnt = *(s32*)arg1;
            arg1 = (s32*)arg1 + 1;
        }
        obj = m->obj = omAddObj(0x4000, 1, mtncnt, -1, func_80043A60_44660);
        model = LoadFormFile(D_800CB160_CBD60[m->id].file, 0x6A9);
        omSetStatBit(obj, 0x80);
        *obj->model = model;
        omSetRot(obj, 0.0f, 0.0f, 0.0f);
        func_80029E80_2AA80(model, 2, 2);
        func_80029EDC_2AADC(model, 1);
        func_800297E8_2A3E8(model, 0.0f, 0.0f, 0.0f);
        if (func_80029E14_2AA14(model) != 0xFF) {
            m->baseMot = func_800432C0_43EC0(func_80029E14_2AA14(model));
        }
        work = HuMemMemoryAllocTemp(sizeof(MBModelWork));
        obj->unk_50 = work;
        work->model = m;
        work->scale = D_800CB168_CBD68[m->id].scale;
        for (i = 0; i < (s16)mtncnt; i++) {
            obj->motion[i] = func_800432E8_43EE8(*(s32*)arg1);
            arg1 = (s32*)arg1 + 1;
        }
        if (D_800CB168_CBD68[m->id].shadowScale > 0.0f) {
            obj = m->shadow = omAddObj(0x4000, 1, 0, -1, func_80043C64_44864);
            if (!_CheckFlag(0xD)) {
                model = LoadFormFile(D_800CB160_CBD60[m->id].shadowFile, 0x229);
            } else {
                model = LoadFormFile(D_800CB160_CBD60[m->id].shadowFile, 0x2A9);
            }
            omSetStatBit(obj, 0x80);
            *obj->model = model;
            omSetRot(obj, 0.0f, 0.0f, 0.0f);
            func_80029EDC_2AADC(model, 1);
            func_800297E8_2A3E8(model, 0.0f, 0.0f, 0.0f);
            work = HuMemMemoryAllocTemp(sizeof(MBModelWork));
            obj->unk_50 = work;
            work->model = m;
            work->scale = D_800CB168_CBD68[m->id].shadowScale;
        } else {
            m->shadow = NULL;
        }
    }
    return m;
}

/* near MP3 MBModelFileCreate (ECA50.c): MP2 reads the base motion from the model and sets no
   model scale. */
MBModel* MBModelFileCreate(s32 arg0, s32 arg1, f32 arg2, f32 arg3, u32* arg4) {
    MBModel* m;
    omObjData* obj;
    MBModelWork* work;
    u32* dataPtr;
    s16 mdl;
    s16 motionCnt;
    s16 i;

    dataPtr = arg4;
    motionCnt = 0;
    m = func_8004344C_4404C();
    if (m != NULL) {
        m->id = 0xFF;
        if (dataPtr != NULL) {
            motionCnt = dataPtr[0];
            dataPtr++;
        }
        obj = m->obj = omAddObj(0x4000, 1, motionCnt, -1, func_80043A60_44660);
        mdl = LoadFormFile(arg0, 0x6A9);
        omSetStatBit(obj, 0x80);
        obj->model[0] = mdl;
        omSetRot(obj, 0.0f, 0.0f, 0.0f);
        func_80029E80_2AA80(mdl, 2, 2);
        func_80029EDC_2AADC(mdl, 1);
        if (func_80029E14_2AA14(mdl) != 0xFF) {
            m->baseMot = func_800432C0_43EC0(func_80029E14_2AA14(mdl));
        }
        work = HuMemMemoryAllocTemp(sizeof(MBModelWork));
        obj->unk_50 = work;
        work->model = m;
        work->scale = arg2;
        for (i = 0; i < motionCnt; i++) {
            obj->motion[i] = func_800432E8_43EE8(*dataPtr++);
        }
        if ((arg1 >= 0) && (arg3 > 0.0f)) {
            obj = m->shadow = omAddObj(0x4000, 1, 0, -1, func_80043C64_44864);
            mdl = LoadFormFile(arg1, 0x229);
            omSetStatBit(obj, 0x80);
            obj->model[0] = mdl;
            omSetRot(obj, 0.0f, 0.0f, 0.0f);
            func_80029EDC_2AADC(mdl, 1);
            work = HuMemMemoryAllocTemp(sizeof(MBModelWork));
            obj->unk_50 = work;
            work->model = m;
            work->scale = arg3;
        } else {
            m->shadow = NULL;
        }
    }
    return m;
}

/* MP1 func_8003DE60 (src/3E560.c): MP2 scales by MBDBackMdlScaleGet. */
void func_80043A60_44660(omObjData* obj) {
    Vec2fxy pos2d;
    MBModelWork* work = obj->unk_50;
    MBModel* m = work->model;

    if (D_80102720_103320 == 0 || (m->attr & 0x10)) {
        if (m->jumpAccel != 0.0f) {
            m->jumpVel += m->jumpAccel;
            if ((m->jumpY += m->jumpVel) < 0.0f) {
                m->jumpY = 0.0f;
                m->jumpVel = 0.0f;
                m->jumpAccel = 0.0f;
            }
        }
    }
    if (!(D_80101330_101F30 & 1)) {
        goto off;
    }
    /* retail reloads attr for each test; only a volatile read reproduces it */
    if (!(((volatile MBModel*)m)->attr & 8)) {
        goto off;
    }
    if (!(((volatile MBModel*)m)->attr & 2)) {
        goto on;
    }
    MBDCamera3Dto2D(&m->pos, &pos2d);
    if (pos2d.x > 370.0f || pos2d.x < -50.0f || pos2d.y > 290.0f || pos2d.y < -20.0f) {
    off:
        MBModelAttrSetDispOff(m);
        return;
    }
on:
    MBModelAttrSetDispOn(m);
    if (!(m->attr & 4)) {
        obj->rot.y = func_80042BE0_437E0(&m->rot);
    }
    obj->trans.x = m->pos.x;
    obj->trans.y = m->pos.y + m->jumpY;
    obj->trans.z = m->pos.z;
    obj->scale.x = m->scale.x * work->scale * MBDBackMdlScaleGet();
    obj->scale.y = m->scale.y * work->scale * MBDBackMdlScaleGet();
    obj->scale.z = m->scale.z * work->scale * MBDBackMdlScaleGet();
}

/* near MP3 func_800D95D0_ED1F0_shared_board (ECA50.c): the shadow follows its model. */
void func_80043C64_44864(omObjData* arg0) {
    f32 f;
    MBModel* m;
    MBModelWork* work;

    work = arg0->unk_50;
    m = work->model;
    f = 1.0f;
    arg0->rot.y = func_80042BE0_437E0(&m->rot);
    if (m->attr & 1) {
        f = 0.0f;
    } else {
        if (m->jumpY != 0.0f) {
            f = 1.0f - (m->jumpY / 700.0f);
            if (f <= 0.0f) {
                f = 0.0f;
            }
            if (f >= 1.0f) {
                f = 1.0f;
            }
        }
    }
    arg0->scale.x = f * m->scale.x * work->scale * MBDBackMdlScaleGet();
    arg0->scale.y = MBDBackMdlScaleGet();
    arg0->scale.z = f * m->scale.z * work->scale * MBDBackMdlScaleGet();
    arg0->trans.x = m->pos.x;
    arg0->trans.y = m->pos.y;
    arg0->trans.z = m->pos.z;
}

/* exact c: marioparty func_8003E174 (src/3E560.c) */
void func_80043DAC_449AC(void* ptr) {
    MBModel* m = (MBModel*)ptr;

    func_80029AFC_2A6FC(*m->obj->model);
    if (m->shadow != NULL) {
        func_80029AFC_2A6FC(*m->shadow->model);
    }
}

INCLUDE_ASM("asm/nonmatchings/43E90", func_80043DF4_449F4);

/* near MP1 MBModelParamCreate (src/3E560.c, NON_MATCHING there): copy a board model. */
MBModel* MBModelParamCreate(MBModel* arg0) {
    MBModel* m;
    omObjData* obj;
    MBModelWork* work;
    s16 model;
    s16 i;

    m = func_8004344C_4404C();
    if (m != NULL) {
        m->id = arg0->id;
        obj = m->obj = omAddObj(0x4000, 1, arg0->obj->mtncnt, -1, func_80043A60_44660);
        model = func_80027D3C_2893C(*arg0->obj->model);
        omSetStatBit(obj, 0x80);
        *obj->model = model;
        omSetRot(obj, 0.0f, 0.0f, 0.0f);
        func_80029E80_2AA80(model, 2, 2);
        func_80029EDC_2AADC(model, 1);
        if (func_80029E14_2AA14(model) != 0xFF) {
            m->baseMot = func_80043388_43F88(func_80029E14_2AA14(model));
        }
        work = HuMemMemoryAllocTemp(sizeof(MBModelWork));
        obj->unk_50 = work;
        work->model = m;
        work->scale = D_800CB168_CBD68[m->id].scale;
        for (i = 0; i < arg0->obj->mtncnt; i++) {
            obj->motion[i] = func_80043388_43F88(arg0->obj->motion[i]);
        }
        if (D_800CB168_CBD68[m->id].shadowScale > 0.0f) {
            obj = m->shadow = omAddObj(0x4000, 1, 0, -1, func_80043C64_44864);
            model = func_80027D3C_2893C(*arg0->shadow->model);
            omSetStatBit(obj, 0x80);
            *obj->model = model;
            omSetRot(obj, 0.0f, 0.0f, 0.0f);
            func_80029EDC_2AADC(model, 1);
            work = HuMemMemoryAllocTemp(sizeof(MBModelWork));
            obj->unk_50 = work;
            work->model = m;
            work->scale = D_800CB168_CBD68[m->id].shadowScale;
        } else {
            m->shadow = NULL;
        }
    }
    return m;
}

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

/* near MP3 func_800D9ED0_EDAF0_shared_board (ECA50.c): turn a board model over work[1] frames. */
void func_80044620_45220(omObjData* arg0) {
    MBModel* m;

    m = arg0->unk_50;
    arg0->work[1]--;
    if (arg0->work[1] == 0) {
        m->rot.x = arg0->rot.x;
        m->rot.y = arg0->rot.y;
        m->rot.z = arg0->rot.z;
        arg0->unk_50 = NULL;
        omDelObj(arg0);
        return;
    }
    arg0->scale.y += arg0->scale.x;
    m->rot.x = HuMathSin(arg0->scale.y);
    m->rot.y = 0.0f;
    m->rot.z = func_800B7890_B8490(arg0->scale.y);
}

/* near MP3 func_800D9F5C_EDB7C_shared_board (ECA50.c): start that turn towards arg1. */
omObjData* func_800446B4_452B4(MBModel* arg0, Vec* arg1, s32 arg2) {
    Vec dir;
    f32 from;
    f32 to;
    omObjData* obj;

    func_80056658_57258(&arg0->pos, arg1, &dir);
    obj = omAddObj(0x1000, 0, 0, -1, func_80044620_45220);
    obj->work[1] = arg2;
    obj->rot.x = dir.x;
    obj->rot.y = dir.y;
    obj->rot.z = dir.z;
    from = func_80042BE0_437E0(&arg0->rot);
    to = func_80042BE0_437E0(&dir);
    if (to < from) {
        if ((from - to) >= 180.0f) {
            to += 360.0f;
        }
    } else if ((to - from) >= 180.0f) {
        from += 360.0f;
    }
    obj->scale.y = from;
    obj->scale.x = (to - from) / (f32)arg2;
    obj->unk_50 = arg0;
    return obj;
}

