#include "common.h"

#include "game/malloc.h"
#include "game/data.h"
#include "engine/siman.h"
#include "game/pad.h"

/* Window system, rumble and the queued-input ring (MP1 src/6C470.c, src/6D4E0.c, src/388E0.c, MP3
   src/window.c). MP2's TextWindow has MP3's layout (0x27C bytes). MP2's names are kept. */

typedef struct Unk6C470Part {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
    /* 0x0C */ f32 radius;
    /* 0x10 */ f32 angle;
    /* 0x14 */ f32 scale;
    /* 0x18 */ s16 state;
    /* 0x1A */ s16 timer;
} Unk6C470Part; // size 0x1C

typedef struct Unk6C470Work {
    /* 0x000 */ s32 unk0;
    /* 0x004 */ void (*func4)(void);
    /* 0x008 */ void (*func8)(omObjData*);
    /* 0x00C */ void (*funcC)(omObjData*);
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01C */ f32 unk1C;
    /* 0x020 */ s32 unk20;
    /* 0x024 */ Unk6C470Part parts[10];
    /* 0x13C */ Unk6C470Part parts2[10];
    /* 0x254 */ s16 sprites[23];
    /* 0x282 */ u16 unk282;
    /* 0x284 */ u16 unk284;
    /* 0x286 */ u16 unk286;
    /* 0x288 */ u16 unk288;
    /* 0x28A */ u16 unk28A;
    /* 0x28C */ u16 unk28C;
    /* 0x28E */ u16 unk28E;
} Unk6C470Work; // size 0x290

typedef struct RumbleState {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA;
} RumbleState; // size 0xC

typedef s32 (*HuSiFunc)(void*);
typedef s32 (*HuSiFuncVoid)(void);

typedef struct functionListEntryt {
    struct functionListEntryt* child;
    HuSiFuncVoid func;
    s16 type;
} functionListEntry;

typedef struct {
    HuSiFunc func;
    void* arg;
    s32 ret;
    OSMesgQueue* recvQueue;
} unkMesg;

typedef struct TWInput {
    /* 0x00 */ s16 v[4];
    /* 0x08 */ s16 count;
} TWInput; // size 0xA

typedef struct TWEntry {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ char pad1[0xF];
} TWEntry; // size 0x10

typedef struct TextWindow {
    /* 0x000 */ char pad0[0x2D];
    /* 0x02D */ u8 unk_2D;
    /* 0x02E */ u8 unk_2E;
    /* 0x02F */ u8 unk_2F;
    /* 0x030 */ s8 unk_30;
    /* 0x031 */ s8 unk_31;
    /* 0x032 */ char pad32[6];
    /* 0x038 */ u32 unk_38;
    /* 0x03C */ u16 unk3C;
    /* 0x03E */ u16 unk3E;
    /* 0x040 */ char pad40[0x2C];
    /* 0x06C */ s16 unk_6C;
    /* 0x06E */ s16 unk_6E[0xC];
    /* 0x086 */ char pad86[0x27];
    /* 0x0AD */ s8 usingStringIDBool[5];
    /* 0x0B2 */ s8 unk_B2[6];
    /* 0x0B8 */ void* unk_B8[4];
    /* 0x0C8 */ char padC8[0x2C];
    /* 0x0F4 */ TWEntry unk_F4[0x18];
    /* 0x274 */ s16 unk274;
    /* 0x276 */ s16 unk276;
    /* 0x278 */ char pad278[4];
} TextWindow; // size 0x27C

extern s16 D_800ED6B0_EE2B0[4];
extern OSPfs D_800ED6C0_EE2C0[4];
extern RumbleState D_800ED860_EE460[4];
extern RumbleState D_800ED862_EE462[]; /* label for D_800ED860_EE460[0].unk2 */
extern functionListEntry D_800ED890_EE490;
extern functionListEntry D_800ED89C_EE49C;
extern s16 D_800ED8A8_EE4A8;
extern OSMesgQueue D_800FA5E0_FB1E0;
extern TextWindow* D_800F920C_F9E0C;
extern TWInput D_800FA048_FAC48[32];
extern TWInput D_800FA04A_FAC4A[]; /* labels for the fields of D_800FA048_FAC48[0] */
extern TWInput D_800FA04C_FAC4C[];
extern TWInput D_800FA04E_FAC4E[];
extern TWInput D_800FA050_FAC50[];
extern u8 D_800FD808_FE408;
extern u8 D_801026D4_1032D4;
extern u8 D_800CDA98_CE698[];
extern u8* D_800CDAB0_CE6B0[];
extern s8 D_800ED8E6_EE4E6;
extern s8 D_801013FA_101FFA;

void func_800873D8_87FD8(omObjData* obj);
s32 func_800877FC_883FC(omObjData* obj);
void func_80087D4C_8894C(omObjData* obj);
void func_80087F48_88B48(omObjData* obj);
void* func_80027154_27D54(s32 size, s32 tag);
void* func_800B0EF0_B1AF0(void* arg0, u8 arg1, u32 size);
void func_80029714_2A314(s16, f32, f32, f32);
void func_8002979C_2A39C(s16, f32, f32, f32);
void func_800297E8_2A3E8(s16, f32, f32, f32);
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029C74_2A874(s16, f32);
f32 func_80029CE4_2A8E4(s16);
f32 func_80029D0C_2A90C(s16);
s16 PlaySound(s16);
s32 __osMotorAccess(OSPfs* pfs, s32 flag);
s32 osMotorInit(OSMesgQueue*, OSPfs*, int);
void func_8007EB8C_7F78C(functionListEntry* entry, s16 type, void* func);
void func_80088540_89140(s16* arg0);
s32 func_800883B8_88FB8(s16* arg0);
void func_80068D24_69924(void* file);
void* func_80068CD4_698D4(s32 stringIndex);
s16 SprAnimRead(void*);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprPosSet(s16 group, s16 member, s16 x, s16 y);
void func_800824F4_830F4(s16 grpIdx, s16 idx, s16 arg2);
void SprAnimKill(s16);
s16 func_800896A0_8A2A0(s16, s16);
void SprRotSet(s16 grpIdx, s16 idx, f32 rot);
void SprAttrSet(s16 grpIdx, s16 idx, s32 flag);
void SprAttrReset(s16 grpIdx, s16 idx, s32 flag);
void func_80082488_83088(s16 grpIdx, s16 idx, u16 a);
void func_80082450_83050(s16 grpIdx, s32 idx, s32 r, s32 g, u8 b);
void func_8008A834_8B434(TextWindow* arg0);
void func_8008B66C_8C26C(TextWindow* arg0);
void func_8008D0BC_8DCBC(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
u8 func_8008D3C8_8DFC8(u8* arg0);
void func_8008CCA8_8D8A8(s16);

void func_8008DCDC_8E8DC(s32);
extern u16 D_800ED8E8_EE4E8;
extern u8 D_800ED8E9_EE4E9;
extern u16 D_800ED8EA_EE4EA;
extern u8 D_8010106E_101C6E[5];

INCLUDE_ASM("asm/nonmatchings/84FF0", SprDispCheck);

INCLUDE_ASM("asm/nonmatchings/84FF0", DispCheck);

INCLUDE_ASM("asm/nonmatchings/84FF0", SprDisp);

INCLUDE_ASM("asm/nonmatchings/84FF0", PutSprite);

INCLUDE_ASM("asm/nonmatchings/84FF0", SprTexLoad);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_80086C08_87808);

void func_80087010_87C10(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_800ED6B0_EE2B0[i] = -1;
    }
}

omObjData* func_80087044_87C44(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u16 arg4) {
    omObjData* obj;
    Unk6C470Work* w;
    s16* mdl;
    s32 i;

    obj = omAddObj(arg0, 0x17, 0, -1, func_800873D8_87FD8);
    mdl = obj->model;
    for (i = 0; i < 0x17; i++) {
        *mdl++ = -1;
    }
    w = func_80027154_27D54(sizeof(*w), 0x7918);
    obj->unk_50 = w;
    func_800B0EF0_B1AF0(w, 0, sizeof(*w));
    w->unk282 = arg1;
    w->unk284 = arg2;
    w->unk286 = arg3;
    w->unk288 = arg4;
    w->unk28A = 0x18;
    w->unk28C = 0x78;
    w->unk28E = 1;
    w->unk20 = 0;
    w->func4 = NULL;
    w->func8 = func_80087D4C_8894C;
    w->funcC = func_80087F48_88B48;
    return obj;
}

INCLUDE_ASM("asm/nonmatchings/84FF0", func_80087150_87D50);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_80087160_87D60);

void func_80087170_87D70(omObjData* obj, f32 x, f32 y, f32 z) {
    Unk6C470Work* w = obj->unk_50;
    s16 mdl;
    f32 s;

    obj->scale.x = x;
    obj->scale.y = y;
    obj->scale.z = z;
    w->unk28C = y * 120.0f;
    w->unk28E = y;
    mdl = obj->model[2];
    if (mdl >= 0) {
        s = y * 3.0f;
        func_80029714_2A314(mdl, s, s, s);
    }
}

INCLUDE_ASM("asm/nonmatchings/84FF0", func_80087270_87E70);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008727C_87E7C);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_80087290_87E90);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008729C_87E9C);

void func_800872A8_87EA8(omObjData* obj, u16 mode) {
    s16 mdl = obj->model[0];
    Unk6C470Part* p;
    s16 i;

    if (mdl >= 0) {
        switch (mode) {
        case 0:
            func_80029C74_2A874(mdl, 0.0f);
            break;
        case 4:
            p = ((Unk6C470Work*)obj->unk_50)->parts;
            for (i = 10; i != 0; i--) {
                p->state = 0;
                p++;
            }
            p = ((Unk6C470Work*)obj->unk_50)->parts2;
            for (i = 10; i != 0; i--) {
                p->state = 0;
                p++;
            }
            break;
        }
        func_800298A4_2A4A4(mdl, 4, mode);
        func_800298A4_2A4A4(obj->model[1], 4, mode);
        for (i = 2; i < 0x17; i++) {
            func_800298A4_2A4A4(obj->model[i], 4, 4);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/84FF0", func_800873D8_87FD8);

void func_80087794_88394(omObjData* obj) {
    Unk6C470Work* w = obj->unk_50;

    if (w->func4 != NULL) {
        w->func4();
    }
    if (w->func8 != NULL) {
        w->func8(obj);
    }
    if (w->funcC != NULL) {
        w->funcC(obj);
    }
}

INCLUDE_ASM("asm/nonmatchings/84FF0", func_800877FC_883FC);

void func_80087D4C_8894C(omObjData* obj) {
    Unk6C470Work* w = obj->unk_50;
    Unk6C470Part* p;
    s16 mdl;
    s32 t;
    s32 i;
    f32 cur;

    if (w->unk20 > 0) {
        mdl = obj->model[0];
        switch (w->unk20) {
            case 1:
                func_80029E80_2AA80(mdl, 1, 0);
                w->unk20 = 2;
                PlaySound(0xBD);
                break;
            case 2:
                cur = func_80029CE4_2A8E4(mdl);
                if (func_80029D0C_2A90C(mdl) <= cur) {
                    w->unk20 = 3;
                    p = w->parts;
                    t = 0;
                    for (i = 0; i < 10; i++, p++) {
                        p->timer = t;
                        t += 2;
                        p->radius = w->unk28C;
                        p->angle = 180.0f;
                        p->scale = w->unk28E;
                        p->state = 1;
                        p->x = obj->trans.x;
                        p->y = obj->trans.y + p->radius;
                        p->z = obj->trans.z;
                    }
                    p = w->parts2;
                    t--;
                    for (i = 0; i < 10; i++, p++) {
                        p->timer = t;
                        t++;
                        p->radius = w->unk28C;
                        p->angle = 180.0f;
                        p->scale = w->unk28E;
                        p->state = 1;
                        p->x = obj->trans.x;
                        p->y = obj->trans.y + p->radius;
                        p->z = obj->trans.z;
                    }
                }
                break;
            case 3:
                if (func_800877FC_883FC(obj) == 0) {
                    w->unk20 = 0;
                }
                break;
        }
    }
}

void func_80087F48_88B48(omObjData* obj) {
    Unk6C470Work* w = obj->unk_50;
    s16 mdl = obj->model[1];
    f32 d;
    f32 s;

    func_80029714_2A314(mdl, obj->trans.x, w->unk1C, obj->trans.z);
    d = obj->trans.y - w->unk1C - obj->scale.y * 50.0f;
    if (!w->unk288) {
        s = obj->scale.y * 0.58f;
    } else {
        s = obj->scale.y * 1.2f;
    }
    if (d < 0.0f) {
        d = s;
    } else {
        d = s - (d * 0.002f);
        if (d < 0.00001f) {
            d = 0.00001f;
        }
    }
    func_800297E8_2A3E8(mdl, d, d, d);
    func_8002979C_2A39C(mdl, obj->rot.x, obj->rot.y, obj->rot.z);
}

void func_80088080_88C80(void) {
    s16 i;
    RumbleState* r;
    OSPfs* pfs;

    if (D_800ED8A8_EE4A8 == 0) {
        for (i = 0; i < 4; i++) {
            r = &D_800ED860_EE460[i];
            pfs = &D_800ED6C0_EE2C0[i];
            if (r->unk0 != 0 && r->unkA != 0) {
                r->unkA--;
                __osMotorAccess(pfs, 0);
            }
        }
        return;
    }
    for (i = 0; i < 4; i++) {
        r = &D_800ED860_EE460[i];
        pfs = &D_800ED6C0_EE2C0[i];
        switch (r->unk2) {
        case 1:
            if (--r->unkA == 0) {
                r->unk0 = 1;
                r->unk2 = 0;
            }
            __osMotorAccess(pfs, 0);
            break;
        case 2:
            __osMotorAccess(pfs, 1);
            r->unk0 = 2;
            r->unk2 = 0;
            break;
        case 3:
            if (r->unk8 <= 0) {
                switch (r->unk0) {
                case 1:
                    if (r->unk4 != 0) {
                        __osMotorAccess(pfs, 1);
                        r->unk0 = 2;
                        r->unk8 = r->unk4;
                    }
                    break;
                case 2:
                    if (r->unk6 != 0) {
                        __osMotorAccess(pfs, 0);
                        r->unk0 = 1;
                        r->unk8 = r->unk6;
                    }
                    break;
                }
            }
            r->unk8--;
            if (r->unkA != 0) {
                if (--r->unkA == 0) {
                    r->unk2 = 1;
                    r->unkA = 3;
                }
            }
            break;
        }
    }
}

void func_800882BC_88EBC(void) {
    s16 i;
    s16 sp10;

    D_800ED8A8_EE4A8 = 0;
    for (i = 0; i < 4; i++) {
        sp10 = i;
        func_80088540_89140(&sp10);
    }
}

s32 func_8008830C_88F0C(void) {
    s16 i;

    for (i = 0; i < 4; i++) {
        func_800883B8_88FB8(&i);
    }
    return 0;
}

void func_80088350_88F50(void) {
    unkMesg sp10;

    D_800ED8A8_EE4A8 = 1;
    func_8007EE0C_7FA0C((unkfunc_8007EE0C*)&sp10, (void*)func_8008830C_88F0C, (char*)0, 1);
    func_8007EB8C_7F78C(&D_800ED890_EE490, 0, func_80088080_88C80);
    func_8007EB8C_7F78C(&D_800ED89C_EE49C, 1, func_800882BC_88EBC);
}

s32 func_800883B8_88FB8(s16* arg0) {
    s32 ret = osMotorInit(&D_800FA5E0_FB1E0, &D_800ED6C0_EE2C0[*arg0], *arg0);

    if (ret == 0) {
        D_800ED860_EE460[*arg0].unk0 = 1;
        __osMotorAccess(&D_800ED6C0_EE2C0[*arg0], 0);
    } else {
        D_800ED860_EE460[*arg0].unk0 = 0;
    }
    D_800ED862_EE462[*arg0].unk0 = 0;
    return ret;
}

void func_800884AC_890AC(s16 arg0) {
    unkMesg sp10;
    s16 sp20 = arg0;

    func_8007EE0C_7FA0C((unkfunc_8007EE0C*)&sp10, (void*)func_800883B8_88FB8, (char*)&sp20, 1);
}

void func_800884DC_890DC(s16* arg0) {
    RumbleState* r = &D_800ED860_EE460[*arg0];

    if (r->unk0 != 0) {
        r->unk2 = 2;
    }
}

void func_80088510_89110(s16 arg0) {
    unkMesg sp10;
    s16 sp20 = arg0;

    func_8007EE0C_7FA0C((unkfunc_8007EE0C*)&sp10, (void*)func_800884DC_890DC, (char*)&sp20, 1);
}

void func_80088540_89140(s16* arg0) {
    RumbleState* r = &D_800ED860_EE460[*arg0];

    if (r->unk0 != 0) {
        r->unk2 = 1;
        r->unkA = 3;
    }
}

void func_8008857C_8917C(s16 arg0) {
    unkMesg sp10;
    s16 sp20 = arg0;

    func_8007EE0C_7FA0C((unkfunc_8007EE0C*)&sp10, (void*)func_80088540_89140, (char*)&sp20, 1);
}

void func_800885AC_891AC(s16* arg0) {
    RumbleState* r = &D_800ED860_EE460[arg0[0]];

    if (r->unk0 != 0) {
        r->unk0 = 1;
        r->unk2 = 3;
        r->unk4 = arg0[1];
        r->unk6 = arg0[2];
        r->unkA = arg0[3];
        r->unk8 = 0;
    }
}

void func_80088604_89204(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    unkMesg sp10;
    s16 sp20[4];

    sp20[0] = arg0;
    sp20[1] = arg1;
    sp20[2] = arg2;
    sp20[3] = arg3;
    func_8007EE0C_7FA0C((unkfunc_8007EE0C*)&sp10, (void*)func_800885AC_891AC, (char*)sp20, 1);
}

INCLUDE_ASM("asm/nonmatchings/84FF0", func_80088640_89240);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_800888A8_894A8);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_80088F44_89B44);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_800890CC_89CCC);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_80089234_89E34);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008925C_89E5C);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_80089284_89E84);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_800892D8_89ED8);

void func_80089308_89F08(s16 win_id, u32 arg1, s8 arg2) {
    TextWindow* textWindow = &D_800F920C_F9E0C[win_id];

    if (textWindow->unk_B8[arg2] != 0) {
        if (textWindow->usingStringIDBool[arg2] != 0) {
            func_80068D24_69924(textWindow->unk_B8[arg2]);
        }
    }
    // pointer check
    if (0x80000000 < arg1) {
        textWindow->usingStringIDBool[arg2] = 0;
        textWindow->unk_B8[arg2] = (char*)arg1;
    } else {
        textWindow->usingStringIDBool[arg2] = 1;
        textWindow->unk_B8[arg2] = func_80068CD4_698D4(arg1);
    }
    textWindow->unk_B2[arg2] = -1;
}

s16 func_80089404_8A004(s16 win_id, u32 spriteMainFsPair, s16 arg2, s16 arg3, u16 arg4) {
    TextWindow* window = &D_800F920C_F9E0C[win_id];
    s16 spriteId;
    void* spriteBytes;
    s16 i;

    for (i = 4; i < ARRAY_COUNT(window->unk_6E); i++) {
        if (window->unk_6E[i] != -1) {
            continue;
        }
        break;
    }
    if (i >= ARRAY_COUNT(window->unk_6E)) {
        return -1;
    }

    spriteBytes = DataRead(spriteMainFsPair);
    spriteId = SprAnimRead(spriteBytes);
    window->unk_6E[i] = spriteId;
    HuMemMemoryFreePerm(spriteBytes);
    SprAnimSet(window->unk_6C, i, spriteId, arg4);
    SprPosSet(window->unk_6C, i, arg2, arg3);
    func_800824F4_830F4(window->unk_6C, i, 0);
    return i;
}

void func_80089544_8A144(s16 arg0, s16 arg1) {
    SprAnimKill(func_800896A0_8A2A0(arg0, arg1));
    D_800F920C_F9E0C[arg0].unk_6E[arg1] = -1;
}

INCLUDE_ASM("asm/nonmatchings/84FF0", func_800895C0_8A1C0);

TextWindow* func_80089674_8A274(s16 arg0) {
    return &D_800F920C_F9E0C[arg0];
}

INCLUDE_ASM("asm/nonmatchings/84FF0", func_800896A0_8A2A0);

void func_800896DC_8A2DC(s16 winId, s16 arg1, s16 arg2) {
    TextWindow* window;

    window = &D_800F920C_F9E0C[winId];

    SprPosSet(window->unk_6C, 0, arg1, arg2);
    window->unk3C = arg1;
    window->unk3E = arg2;
}

INCLUDE_ASM("asm/nonmatchings/84FF0", func_80089764_8A364);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008980C_8A40C);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_800898F0_8A4F0);

void func_800899F4_8A5F4(s16 winId, f32 arg1) {
    TextWindow* window;

    window = &D_800F920C_F9E0C[winId];
    SprRotSet(window->unk_6C, 0, arg1);
}

INCLUDE_ASM("asm/nonmatchings/84FF0", func_80089A48_8A648);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_80089A7C_8A67C);

void func_80089B2C_8A72C(s16 winId, s16 arg1) {
    TextWindow* window;

    window = &D_800F920C_F9E0C[winId];

    if (arg1 == 0) {
        SprAttrSet(window->unk_6C, 0, 0x8000);
    } else {
        SprAttrReset(window->unk_6C, 0, 0x8000);
    }
    func_80082488_83088(window->unk_6C, 0, arg1 & 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/84FF0", func_80089BBC_8A7BC);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_80089C78_8A878);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_80089CAC_8A8AC);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_80089DA0_8A9A0);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_80089DDC_8A9DC);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008A6DC_8B2DC);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008A700_8B300);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008A7A0_8B3A0);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008A7E8_8B3E8);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008A834_8B434);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008A8C0_8B4C0);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008A960_8B560);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008AA44_8B644);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008AA90_8B690);

void func_8008AD44_8B944(s16 win_id) {
    func_8008A834_8B434(&D_800F920C_F9E0C[win_id]);
}

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008AD84_8B984);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008AD94_8B994);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008B154_8BD54);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008B3BC_8BFBC);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008B5AC_8C1AC);

void func_8008B62C_8C22C(s16 win_id) {
    func_8008B66C_8C26C(&D_800F920C_F9E0C[win_id]);
}

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008B66C_8C26C);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008B6F4_8C2F4);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008BA30_8C630);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008BB18_8C718);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008BB48_8C748);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008BCB8_8C8B8);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008C828_8D428);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008CCA8_8D8A8);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008CE5C_8DA5C);

void func_8008CFD0_8DBD0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4) {
    func_8008D0BC_8DCBC(-(~arg0 == 0), -(~arg1 == 0), -(~arg2 == 0), -(~arg3 == 0), arg4);
    func_8008D0BC_8DCBC(arg0, arg1, arg2, arg3, 1);
}

void func_8008D07C_8DC7C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_8008D0BC_8DCBC(arg0, arg1, arg2, arg3, 1);
}

void func_8008D0BC_8DCBC(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    D_800FA048_FAC48[D_800FD808_FE408].v[0] = arg0;
    D_800FA04A_FAC4A[D_800FD808_FE408].v[0] = arg1;
    D_800FA04C_FAC4C[D_800FD808_FE408].v[0] = arg2;
    D_800FA04E_FAC4E[D_800FD808_FE408].v[0] = arg3;
    D_800FA050_FAC50[D_800FD808_FE408].v[0] = arg4;
    D_800FD808_FE408 = (D_800FD808_FE408 + 1) & 0x1F;
}

void func_8008D12C_8DD2C(s16* arg0) {
    s16 i;

    if (D_801026D4_1032D4 == D_800FD808_FE408) {
        arg0[0] = arg0[1] = arg0[2] = arg0[3] = 0;
        return;
    }
    for (i = 0; i < 4; i++) {
        arg0[i] = (D_800FA048_FAC48 + D_801026D4_1032D4)->v[i];
        if (arg0[i] == -1) {
            arg0[i] = D_800FC9E0_FD5E0[i];
        }
    }
    D_800FA050_FAC50[D_801026D4_1032D4].v[0]--;
    if (D_800FA050_FAC50[D_801026D4_1032D4].v[0] == 0) {
        D_801026D4_1032D4 = (D_801026D4_1032D4 + 1) & 0x1F;
    }
}

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008D23C_8DE3C);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008D250_8DE50);

u8 func_8008D3C8_8DFC8(u8* arg0) {
    s16 i, j;

    for (i = 0; i < 10; i += 2) {
        if (D_800CDA98_CE698[i] == arg0[0] && D_800CDA98_CE698[i + 1] == arg0[1]) {
            return i / 2;
        }
    }
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 32; j += 2) {
            if (D_800CDAB0_CE6B0[i][j] == arg0[0] && D_800CDAB0_CE6B0[i][j + 1] == arg0[1]) {
                return i * 16 + j / 2;
            }
        }
    }
    return 16;
}

void func_8008D4DC_8E0DC(u8* arg0, u8* arg1) {
    for (; *arg1 != 0; arg0++, arg1 += 2) {
        *arg0 = func_8008D3C8_8DFC8(arg1);
    }
    *arg0 = 0;
}

void func_8008D530_8E130(s16 arg0, u8 arg1, u8 arg2, u8 arg3) {
    TextWindow* textWindow = &D_800F920C_F9E0C[arg0];

    textWindow->unk_2D = arg1;
    textWindow->unk_2E = arg2;
    textWindow->unk_2F = arg3;
    func_80082450_83050(textWindow->unk_6C, 0, arg1, arg2, arg3);
}

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008D59C_8E19C);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008D5D8_8E1D8);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008D6F0_8E2F0);

void func_8008D808_8E408(s16 winId, s32 arg1) {
    TextWindow* window;

    window = &D_800F920C_F9E0C[winId];
    if (arg1 != 0) {
        window->unk_38 |= 0x10;
    } else {
        window->unk_38 &= ~0x10;
    }
}

void func_8008D854_8E454(s32 arg0, s16 arg1) {
    TextWindow* textWindow = &D_800F920C_F9E0C[arg0];
    textWindow->unk_F4[arg1].unk0 = 2;
}

void func_8008D88C_8E48C(void) {
}

s16 func_8008D894_8E494(s32 winId) {
    return D_800F920C_F9E0C[winId].unk_31;
}

void func_8008D8BC_8E4BC(u8* arg0, u8* arg1) {
    while (*arg0 != 0) {
        if (*arg0 == 10) {
            arg0++;
        } else {
            *arg1++ = *arg0++;
        }
    }
    *arg1 = *arg0;
}

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008D904_8E504);

void func_8008D974_8E574(s32 arg0, s16 arg1) {
    D_800ED8E6_EE4E6 = 1;
    D_800ED8EA_EE4EA = 0;
    D_800ED8E8_EE4E8 = 0;
    func_8008DCDC_8E8DC(arg0);
    D_8010106E_101C6E[arg1] = D_800ED8E9_EE4E9;
}

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008D9D0_8E5D0);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008DA84_8E684);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008DAC0_8E6C0);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008DACC_8E6CC);

void func_8008DBE0_8E7E0(s16* arg0, s16 arg1, s16 arg2) {
    u32 i;

    if (arg2 < arg1) {
        arg0[1] = 0x64;
        arg0[0] = 0x64;
        return;
    }

    D_800ED8E6_EE4E6 = 0;
    D_800ED8EA_EE4EA = 0;
    D_800ED8E8_EE4E8 = 0;

    for (i = arg1; arg2 >= i; i++) {
        func_8008DCDC_8E8DC(i);
    }

    for (i = 0; i < ARRAY_COUNT(D_8010106E_101C6E); i++) {
        D_8010106E_101C6E[i] = 0;
    }

    D_801013FA_101FFA = 0xC;
    arg0[0] = D_800ED8E8_EE4E8 + 10;
    arg0[1] = D_800ED8EA_EE4EA + 6;
}

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008DCDC_8E8DC);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008DF9C_8EB9C);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008DFC4_8EBC4);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008E2DC_8EEDC);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008E434_8F034);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008E4D0_8F0D0);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008E644_8F244);

void func_8008E6AC_8F2AC(s16 arg0) {
    func_8008CCA8_8D8A8(arg0);
}

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008E6CC_8F2CC);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008E73C_8F33C);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008E978_8F578);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008EBE4_8F7E4);

INCLUDE_ASM("asm/nonmatchings/84FF0", func_8008EED8_8FAD8);
