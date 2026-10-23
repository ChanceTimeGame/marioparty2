#include "common.h"

#include "game/malloc.h"
#include "game/sprite.h"
#include "game/hmfman.h"

#include "game/camera.h"

f32 __sinf(f32);
f32 __cosf(f32);

#define READ32(p) (((p)[0] << 24) + ((p)[1] << 16) + ((p)[2] << 8) + (p)[3])
#define READ16(p) (((p)[0] << 8) + (p)[1])

f64 fabs(f64);

/* Palette animation state, HuSprite 0x98-0x113 */
typedef struct SprPalAnim {
    /* 0x00 */ HuSprAnmDesc* desc;
    /* 0x04 */ u16 frame[0x10];
    /* 0x24 */ f32 timer[0x10];
    /* 0x64 */ f32 speed;
    /* 0x68 */ u16 bufIdx;
    /* 0x6C */ u16* cur;
    /* 0x70 */ u16* bufs[3];
} SprPalAnim;

typedef struct SprPalEntry {
    /* 0x00 */ u16 idx;
    /* 0x02 */ u16 color;
} SprPalEntry;

typedef struct SprPalFrame {
    /* 0x00 */ s16 dur;
    /* 0x04 */ SprPalEntry* entries;
} SprPalFrame;

typedef struct SprPalGroup {
    /* 0x00 */ u16 count; /* palette entries per frame; 0 = not animated */
    /* 0x02 */ u16 nframes;
    /* 0x04 */ SprPalFrame** frames;
} SprPalGroup;

extern s16 D_800FFFD6_100BD6; /* current viewport */
extern f32 D_800ED654_EE254;  /* view distance of the last SprPos3DSet point */
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* HuMathCos */
f32 fabsf(f32);

void func_800B30D0_B3CD0(f32 mf[4][4], Mtx* m); /* guMtxL2F */
f64 func_800B0D98_B1998(f64, f64);

/* Sprite manager (MP1 src/65770.c, MP3 src/sprman.c). MP2's sprite object has MP3's layout (0x208
   bytes) and its group MP1's (members at 0xC); MP1's code is written against those layouts here.
   Rodata D4240-D42A0 carved. SprAnimRead and func_800841B8 are NON_MATCHING (register allocation). */

typedef struct SprBucket {
    /* 0x00 */ HuSprite* head;
    /* 0x04 */ HuSprite* tail;
} SprBucket;

extern HuSprGrp* D_800F64B4_F70B4;               /* first group */
extern HuSprGrp* D_800F8C40_F9840;               /* last group */
extern u16 D_80101074_101C74;                  /* group count */
extern s16 D_800F841C_F901C;                   /* sprites in the draw list */
extern HuSprite_Unk84_Struct* D_800F60B0_F6CB0[256]; /* MP3 D_800C9530 */
extern u16 D_800F8F88_F9B88;
extern HuSprAnmDesc* D_800FCEA0_FDAA0[256];    /* MP3 D_800D0A50 */
extern u16 D_80101630_102230;
extern void* D_800FA5F8_FB1F8[3];
extern u8 D_800FDBE0_FE7E0;
extern s32 D_800FD8BC_FE4BC;
extern void* D_801016C0_1022C0;

void* HuMemAlloc(s32 size);           /* MP3 HuMemAlloc */
void HuMemFree(void* data);          /* MP3 HuMemFree */
void func_80027340_27F40(void* data);
void SprFree(HuSprite* arg0);
void SprKill(s16 idx);
HuSprGrp* SprAlloc(s16 num, u16 attr);
void InitData(HuSprGrp* grp, u16 num);
void LinkSprite(HuSprite* obj, HuSprite* a, HuSprite* b);
void RestoreAnimState(HuSprite* arg0);
void InitAnimState(HuSprAnm* arg0);
HuSprite_Unk84_Struct* SprAnimGet(s16 animIdx);
s16 SprAnimRead(void*);
void SprAnimKill(s16 animIdx);
void SprAnimKillAll(void);
void SprClose(void);
void AnimateSprite(HuSprAnm* arg0);
s16 func_800832FC_83EFC(HuSprAnm* arg0);
void func_80082FE4_83BE4(HuSprAnm* arg0, s16 arg1, u16 arg2, u16 arg3);
struct SprPalAnim;
void func_800841B8_84DB8(struct SprPalAnim* pa);
void func_80083F70_84B70(s16 arg0);
void func_80084148_84D48(void);

/* The camera a layer hook draws for (only its scissor box is named) */
typedef struct SprCamera {
    /* 0x00 */ char unk00[0x98];
    /* 0x98 */ f32 scissor[4];
} SprCamera;

extern Mtx D_800ED610_EE210;  /* sprite orthographic projection */
/* .data (0xCE1A0-0xCE1B0) */
Vp D_800CD5A0_CE1A0 = { { { 640, 480, G_MAXZ / 2, 0 }, { 640, 480, G_MAXZ / 2, 0 } } };
extern Gfx* D_800ED650_EE250;  /* first sprite display list command */
extern void* D_800F9294_F9E94;
extern s16 D_800FC89C_FD49C;
extern s16 D_800FD2A6_FDEA6;
void SprBegin(void);
HuSprite* GetFirstSprite(void);
void func_80081378_81F78(void);
void SprDisp(Gfx** gfx, HuSprite* obj, SprCamera* cam);
void SprExec(Gfx** gfx, Mtx* mtx, SprCamera* cam);
void SprLayerHook(Gfx** gfx, Mtx* mtx, SprCamera* cam);
void SprAnimInit(void);
void func_80083CC0_848C0(void);
s16 func_8002838C_28F8C(s32, void*, s32);
void func_80029EDC_2AADC(s16, s32);
void func_800B3820_B4420(Mtx* m); /* MP3 func_8008A0D0 */

/* MP1 func_80064B70: sprite manager init */
void func_8007F630_80230(void) {
    s16 i;

    D_80101074_101C74 = 0;
    for (i = 0; i < 256; i++) {
        HuSprGrpData[i] = NULL;
    }
    D_800F8C40_F9840 = NULL;
    D_800F64B4_F70B4 = NULL;
    D_800F841C_F901C = 0;
    D_800FA5F8_FB1F8[0] = D_800FA5F8_FB1F8[1] = D_800FA5F8_FB1F8[2] = D_801016C0_1022C0 = NULL;
    D_800FD8BC_FE4BC = 0;
    guOrtho(&D_800ED610_EE210, -160.0f, 160.0f, -120.0f, 120.0f, 0.0f, 8000.0f, 2.0f);
    D_800FC89C_FD49C = func_8002838C_28F8C(0, SprExec, 0);
    func_80029EDC_2AADC(D_800FC89C_FD49C, 1);
    D_800FD2A6_FDEA6 = func_8002838C_28F8C(0, SprLayerHook, 6);
    SprAnimInit();
    func_80083CC0_848C0();
}

HuSprGrp* SprAlloc(s16 num, u16 attr) {
    HuSprGrp* grp = HuMemAlloc(num * sizeof(HuSprite*) + sizeof(HuSprGrp) - sizeof(HuSprite*));

    if (grp == NULL) {
        return NULL;
    }
    grp->unk_08 = attr;
    grp->count = num;
    if (D_800F64B4_F70B4 == NULL) {
        D_800F64B4_F70B4 = grp;
    }
    grp->prev = D_800F8C40_F9840;
    if (D_800F8C40_F9840 != NULL) {
        D_800F8C40_F9840->next = grp;
    }
    grp->next = NULL;
    D_800F8C40_F9840 = grp;
    D_80101074_101C74++;
    return grp;
}

void SprFree(HuSprite* arg0) {
    s16 i;

    for (i = 0; i < 3; i++) {
        if (arg0->unk_128[i] != NULL) {
            func_80027340_27F40(arg0->unk_128[i]);
        }
        if (arg0->unk_134[i] != NULL) {
            func_80027340_27F40(arg0->unk_134[i]);
        }
        if (arg0->unk_108[i] != NULL) {
            func_80027340_27F40(arg0->unk_108[i]);
        }
    }
    func_80027340_27F40(arg0);
}

void SprKill(s16 idx) {
    HuSprGrp* grp = HuSprGrpData[idx];
    HuSprGrp* prev = grp->prev;
    HuSprGrp* next = grp->next;
    HuSprite** p;
    s16 i;

    if (grp->members[0] != NULL) {
        p = grp->members;
        for (i = 0; i < grp->count; i++) {
            SprFree(*p++);
        }
    }
    if (prev != NULL) {
        prev->next = next;
    }
    if (next != NULL) {
        next->prev = prev;
    }
    if (D_800F64B4_F70B4 == grp) {
        D_800F64B4_F70B4 = next;
        if (next != NULL) {
            next->prev = NULL;
        }
    }
    if (D_800F8C40_F9840 == grp) {
        D_800F8C40_F9840 = prev;
        if (prev != NULL) {
            prev->next = NULL;
        }
    }
    HuMemFree(grp);
    HuSprGrpData[idx] = NULL;
    D_80101074_101C74--;
}

void SprClose(void) {
    s16 i;

    D_80101074_101C74 = 0;
    for (i = 0; i < 256; i++) {
        if (HuSprGrpData[i] != NULL) {
            SprKill(i);
        }
    }
    D_800F8C40_F9840 = NULL;
    D_800F64B4_F70B4 = NULL;
    D_800F841C_F901C = 0;
}

s16 SprCreate(s32 num, s32 attr) {
    HuSprGrp* grp;
    HuSprite** p;
    s16 i;
    s16 idx;

    for (i = 0; i < 256; i++) {
        if (HuSprGrpData[i] == NULL) {
            break;
        }
    }
    if (i == 256) {
        return -1;
    }
    idx = i;
    grp = SprAlloc(num, attr);
    if (grp == NULL) {
        return -1;
    }
    HuSprGrpData[idx] = grp;
    grp->count = 0;
    p = grp->members;
    for (i = 0; i < (u16)num; i++) {
        if ((*p++ = HuMemAlloc(sizeof(**p))) == NULL) {
            SprKill(idx);
            return -1;
        }
        grp->count++;
    }
    InitData(grp, num);
    return idx;
}

s32 func_8007FBB4_807B4(s16 idx, s16 start, u16 num) {
    HuSprGrp* grp = HuSprGrpData[idx];
    HuSprite** p = &grp->members[start];
    HuSprite* obj;
    s16 i;

    for (i = 0; i < num; i++) {
        SprFree(*p++);
    }
    grp->count -= num;
    if (grp->count == 0) {
        grp->members[0] = NULL;
        SprKill(idx);
        return 0;
    }
    HuMemMemoryReallocPerm(grp, grp->count * 4 + 0xC);
    p = &grp->members[start];
    for (i = 0; i < grp->count - start; i++) {
        *p = p[num];
        p++;
    }
    for (i = 0; i < grp->count; i++) {
        obj = grp->members[i];
        obj->unk_00 = i;
        obj->unk_02 = grp->count;
    }
    return 0;
}

s32 func_8007FD58_80958(s16 idx, s16 pos, u16 num) {
    HuSprGrp* old = HuSprGrpData[idx];
    HuSprGrp* grp;
    HuSprite** p;
    HuSprite* obj;
    s16 i;
    s16 newIdx;

    for (i = 0; i < 256; i++) {
        if (HuSprGrpData[i] == NULL) {
            break;
        }
    }
    if (i == 256) {
        return -1;
    }
    newIdx = i;
    grp = SprAlloc(num + old->count, old->unk_08);
    if (grp == NULL) {
        return -1;
    }
    HuSprGrpData[newIdx] = grp;
    grp->count = 0;
    p = grp->members;
    for (i = 0; i < num; i++) {
        if ((*p++ = HuMemAlloc(sizeof(**p))) == NULL) {
            SprKill(newIdx);
            return -1;
        }
        grp->count++;
    }
    InitData(grp, num);
    grp->members[0]->unk_2E = 0;
    if (pos >= 0) {
        p = grp->members + num - 1;
        for (i = 0; i < num; i++) {
            p[pos + 1] = *p;
            p--;
        }
        p = grp->members;
        for (i = 0; i < pos + 1; i++) {
            *p++ = old->members[i];
        }
    }
    p = &grp->members[pos] + num + 1;
    for (i = 0; i < old->count - (pos + 1); i++) {
        *p++ = (old->members + pos)[i + 1];
    }
    grp->count = num + old->count;
    for (i = 0; i < grp->count; i++) {
        obj = grp->members[i];
        obj->unk_00 = i;
        obj->unk_02 = grp->count;
    }
    old->members[0] = NULL;
    SprKill(idx);
    HuSprGrpData[idx] = grp;
    HuSprGrpData[newIdx] = NULL;
    return 0;
}

void InitAnimState(HuSprAnm* arg0) {
    arg0->unk00 = NULL;
    arg0->unk04 = 0;
    arg0->unk06 = 0;
    arg0->unk08 = 0;
    arg0->unk0A = 0;
    arg0->unk0C = 0.0f;
    arg0->unk10 = 1.0f;
    arg0->unk14 = 0;
    arg0->unk16 = 0;
    arg0->unk18 = 0;
    arg0->unk17 = 0;
}

void RestoreAnimState(HuSprite* arg0) {
    arg0->unk_68.unk00 = arg0->unk_84;
    arg0->unk_68.unk04 = arg0->unk_88;
    arg0->unk_68.unk06 = arg0->unk_0E;
    arg0->unk_68.unk0A = arg0->unk_8A;
    arg0->unk_68.unk08 = arg0->unk_0C;
    arg0->unk_68.unk0C = arg0->unk_8C;
    arg0->unk_68.unk10 = arg0->unk_10;
    arg0->unk_68.unk16 = arg0->unk_92;
    arg0->unk_68.unk14 = arg0->unk_90;
    arg0->unk_68.unk18 = 0;
    arg0->unk_68.unk17 = 0;
}

/* MP3 func_80052E68_53A68 */
void InitData(HuSprGrp* group, u16 count) {
    HuSprite* sprite;
    s16 i;
    s16 j;

    for (i = 0; i < count; i++) {
        sprite = group->members[i];
        sprite->unk_04 = 0;
        sprite->unk_08 = 0;
        sprite->unk_18 = sprite->unk_1C = 1.0f;
        sprite->prio = 0x8000;
        sprite->unk_20 = 0;
        sprite->unk_24 = 0;
        sprite->unk_28[0] = sprite->unk_28[1] = sprite->unk_28[2] = 0;
        sprite->unk_2C = 0x100;
        if (i != 0) {
            sprite->unk_2E = 0;
        } else {
            sprite->unk_2E = -1;
        }
        sprite->unk_30 = sprite->unk_34 = 1.0f;
        sprite->unk_38 = sprite->unk_3A = 0;
        sprite->unk_3C = sprite->unk_3E = sprite->unk_40 = sprite->unk_42 = 0;
        sprite->unk_44 = 0;
        sprite->unk_116 = sprite->unk_114 = -1;
        sprite->unk_48 = 0.0f;
        sprite->unk_4C = 0.0f;
        sprite->unk_50 = sprite->unk_54 = 1.0f;
        sprite->unk_58 = 0.0f;
        sprite->unk_5C = 0;
        sprite->unk_60 = sprite->unk_64 = 1.0f;
        InitAnimState(&sprite->unk_68);
        sprite->unk_84 = sprite->unk_68.unk00;
        sprite->unk_88 = sprite->unk_68.unk04;
        sprite->unk_0E = (u16)sprite->unk_68.unk06;
        sprite->unk_0C = (u16)sprite->unk_68.unk08;
        sprite->unk_8C = sprite->unk_68.unk0C;
        sprite->unk_10 = sprite->unk_68.unk10;
        sprite->unk_90 = (u16)sprite->unk_68.unk14;
        sprite->unk_92 = sprite->unk_68.unk16;
        sprite->unk_93 = sprite->unk_68.unk17;
        sprite->unk_94 = sprite->unk_68.unk18;
        sprite->unk_98 = NULL;
        sprite->unk_FC = 1.0f;
        for (j = 0; j < 0x10; j++) {
            sprite->unk_9C[j] = 0xFFFF;
            sprite->unk_BC[j] = 0;
        }
        sprite->unk_100 = 0;
        sprite->unk_104 = NULL;
        sprite->unk_108[0] = sprite->unk_108[1] = sprite->unk_108[2] = NULL;
        sprite->unk_00 = i;
        sprite->unk_02 = count;
        sprite->unk_118 = sprite->unk_11C = NULL;
        sprite->unk_128[0] = sprite->unk_128[1] = sprite->unk_128[2] = NULL;
        sprite->unk_134[0] = sprite->unk_134[1] = sprite->unk_134[2] = NULL;
        func_800B3820_B4420(&sprite->unk_140[0]);
        func_800B3820_B4420(&sprite->unk_140[1]);
        func_800B3820_B4420(&sprite->unk_140[2]);
        sprite->unk_120 = 0;
        sprite->unk_124 = NULL;
    }
}

void LinkSprite(HuSprite* obj, HuSprite* a, HuSprite* b) {
    if (a != NULL) {
        a->unk_11C = obj;
    }
    if (b != NULL) {
        b->unk_118 = obj;
    }
    obj->unk_118 = a;
    obj->unk_11C = b;
}

HuSprite* GetFirstSprite(void) {
    SprBucket bucket[256];
    HuSprGrp* grp;
    HuSprite* obj;
    HuSprite* s2;
    s16 min = -1;
    s16 max = 0;
    s16 pri;
    s16 i;
    s16 j;

    s2 = 0;
    D_800F841C_F901C = 0;
    grp = D_800F64B4_F70B4;
    for (pri = 0; pri < 256; pri++) {
        bucket[pri].head = (bucket[pri].tail = 0);
    }

    for (; grp != 0; grp = grp->next) {
        for (i = 0; i < grp->count; i++) {
            obj = grp->members[i];
            if (obj->unk_24 & 0x8000) {
                continue;
            }
            pri = obj->prio >> 8;
            do { } while (0);
            if (min < 0) {
                min = (max = pri);
                bucket[max].head = (bucket[max].tail = obj);
            } else {
                if (pri <= max) {
                    for (j = pri; j < (max + 1); j++) {
                        s2 = bucket[j].tail;
                        if ((s2 != 0) && (obj->prio <= s2->prio)) {
                            if ((bucket[j].head != 0) && (bucket[j].head->prio >= obj->prio)) {
                                s2 = bucket[j].head;
                            }
                            break;
                        }
                    }

                    if (j == (max + 1)) {
                        s2 = bucket[max].tail;
                    }
                } else {
                    s2 = bucket[max].tail;
                }
                for (; s2 != 0; s2 = s2->unk_118) {
                    if (s2->prio < obj->prio) {
                        break;
                    }
                }

                if (s2 != 0) {
                    LinkSprite(obj, s2, s2->unk_11C);
                } else {
                    LinkSprite(obj, 0, bucket[min].head);
                }
                if ((bucket[pri].head == 0) || (obj->prio <= bucket[pri].head->prio)) {
                    bucket[pri].head = obj;
                }
                if ((bucket[pri].tail == 0) || (obj->prio > bucket[pri].tail->prio)) {
                    bucket[pri].tail = obj;
                }
                if (pri < min) {
                    min = pri;
                }
                if (pri > max) {
                    max = pri;
                }
            }
            D_800F841C_F901C++;
        }
    }

    return bucket[max].tail;
}

s16 func_80080698_81298(HuSprGrp* grp) {
    HuSprite* obj;
    HuSprite* parent;
    HuSprite* other;
    s16 root = 0;
    s16 i;
    s16 j;

    for (j = 0; j < grp->count; j++) {
        obj = grp->members[j];
        obj->unk_114 = obj->unk_116 = -1;
    }
    for (i = 0; i < grp->count; i++) {
        obj = grp->members[i];
        if (obj->unk_2E >= 0) {
            parent = grp->members[obj->unk_2E];
            if (parent->unk_116 < 0) {
                parent->unk_116 = i;
            } else {
                for (j = 0; j < i; j++) {
                    other = grp->members[j];
                    if (j != i && obj->unk_2E == other->unk_2E && other->unk_114 < 0) {
                        other->unk_114 = i;
                        break;
                    }
                }
            }
        } else {
            root = i;
        }
    }
    return root;
}

void CalcGroupCenter(f32 a[3][2], f32 b[3][2], f32 out[3][2]) {
    s16 i;

    for (i = 0; i < 3; i++) {
        out[i][0] = a[i][0] * b[0][0] + a[i][1] * b[1][0];
        out[i][1] = a[i][0] * b[0][1] + a[i][1] * b[1][1];
    }
    out[2][0] += b[2][0];
    out[2][1] += b[2][1];
}

void SprBegin(void) {
    f32 mtx[256][3][2];
    f32 mA[3][2];
    f32 mB[3][2];
    s16 stack[256];
    HuSprGrp* grp;
    HuSprite* obj;
    HuSprite* parent;
    f32 angle;
    f32 s;
    u16 sp = 0;
    s16 cur;
    s16 i;
    s16 idx;

    for (grp = D_800F64B4_F70B4; grp != NULL; grp = grp->next) {
        switch (grp->unk_08) {
            case 0:
                for (cur = 0; cur < grp->count; cur++) {
                    obj = grp->members[cur];
                    SprFinish(obj);
                    obj->unk_04 = obj->unk_93 + obj->unk_48;
                    obj->unk_08 = obj->unk_94 + obj->unk_4C;
                    obj->unk_20 = obj->unk_58;
                    func_80083748_84348(obj);
                }
                break;
            case 1:
                cur = func_80080698_81298(grp);
                for (i = 0; i < grp->count; i++) {
                    obj = grp->members[cur];
                    SprFinish(obj);
                    if (obj->unk_2E < 0) {
                        obj->unk_04 = obj->unk_93 + obj->unk_48;
                        obj->unk_08 = obj->unk_94 + obj->unk_4C;
                        obj->unk_20 = obj->unk_58;
                    } else {
                        parent = grp->members[obj->unk_2E];
                        obj->unk_04 = obj->unk_93 + obj->unk_48;
                        obj->unk_08 = obj->unk_94 + obj->unk_4C;
                        obj->unk_20 = parent->unk_20 + obj->unk_58;
                    }
                    func_80083748_84348(obj);
                    if (obj->unk_116 >= 0) {
                        stack[sp++] = cur;
                        cur = obj->unk_116;
                        sp %= 256;
                    } else {
                        while (obj->unk_114 < 0 && sp != 0) {
                            idx = stack[--sp];
                            sp %= 256;
                            obj = grp->members[idx];
                        }
                        cur = obj->unk_114;
                    }
                }
                break;
            case 2:
                cur = func_80080698_81298(grp);
                for (i = 0; i < grp->count; i++) {
                    obj = grp->members[cur];
                    SprFinish(obj);
                    if (obj->unk_2E < 0) {
                        obj->unk_04 = obj->unk_93 + obj->unk_48;
                        obj->unk_08 = obj->unk_94 + obj->unk_4C;
                    } else {
                        parent = grp->members[obj->unk_2E];
                        obj->unk_04 = (obj->unk_93 + obj->unk_48) * obj->unk_18 + parent->unk_04;
                        obj->unk_08 = (obj->unk_94 + obj->unk_4C) * obj->unk_1C + parent->unk_08;
                    }
                    obj->unk_20 = obj->unk_58;
                    func_80083748_84348(obj);
                    if (obj->unk_116 >= 0) {
                        stack[sp++] = cur;
                        cur = obj->unk_116;
                        sp %= 256;
                    } else {
                        while (obj->unk_114 < 0 && sp != 0) {
                            idx = stack[--sp];
                            sp %= 256;
                            obj = grp->members[idx];
                        }
                        cur = obj->unk_114;
                    }
                }
                break;
            case 3:
                cur = func_80080698_81298(grp);
                for (i = 0; i < grp->count; i++) {
                    obj = grp->members[cur];
                    SprFinish(obj);
                    if (obj->unk_2E < 0) {
                        obj->unk_04 = obj->unk_93 + obj->unk_48;
                        obj->unk_08 = obj->unk_94 + obj->unk_4C;
                        obj->unk_20 = obj->unk_58;
                    } else {
                        parent = grp->members[obj->unk_2E];
                        obj->unk_04 = (obj->unk_93 + obj->unk_48) * obj->unk_18 + parent->unk_04;
                        obj->unk_08 = (obj->unk_94 + obj->unk_4C) * obj->unk_1C + parent->unk_08;
                        obj->unk_20 = parent->unk_20 + obj->unk_58;
                    }
                    func_80083748_84348(obj);
                    if (obj->unk_116 >= 0) {
                        stack[sp++] = cur;
                        cur = obj->unk_116;
                        sp %= 256;
                    } else {
                        while (obj->unk_114 < 0 && sp != 0) {
                            idx = stack[--sp];
                            sp %= 256;
                            obj = grp->members[idx];
                        }
                        cur = obj->unk_114;
                    }
                }
                break;
            case 4:
                cur = func_80080698_81298(grp);
                for (i = 0; i < grp->count; i++) {
                    obj = grp->members[cur];
                    SprFinish(obj);
                    if (obj->unk_2E < 0) {
                        mA[0][0] = mA[1][1] = 1.0f;
                        mA[0][1] = mA[1][0] = 0.0f;
                        mA[2][0] = obj->unk_93 + obj->unk_48;
                        mA[2][1] = obj->unk_94 + obj->unk_4C;
                        obj->unk_04 = obj->unk_48;
                        obj->unk_08 = obj->unk_4C;
                    } else {
                        mB[0][0] = mB[1][1] = 1.0f;
                        mB[0][1] = mB[1][0] = 0.0f;
                        mB[2][0] = (obj->unk_93 + obj->unk_48) * obj->unk_18;
                        mB[2][1] = (obj->unk_94 + obj->unk_4C) * obj->unk_1C;
                        CalcGroupCenter(mB, mtx[obj->unk_2E], mA);
                        obj->unk_04 = (s16)mA[2][0];
                        obj->unk_08 = (s16)mA[2][1];
                    }
                    obj->unk_20 = obj->unk_58;
                    angle = -obj->unk_58 * 0.0174532925222222225;
                    mB[0][0] = mB[1][1] = __cosf(angle);
                    s = __sinf(angle);
                    mB[0][1] = s;
                    mB[1][0] = -s;
                    mB[2][0] = mB[2][1] = 0.0f;
                    CalcGroupCenter(mB, mA, mtx[obj->unk_00]);
                    func_80083748_84348(obj);
                    if (obj->unk_116 >= 0) {
                        stack[sp++] = cur;
                        cur = obj->unk_116;
                        sp %= 256;
                    } else {
                        while (obj->unk_114 < 0 && sp != 0) {
                            idx = stack[--sp];
                            sp %= 256;
                            obj = grp->members[idx];
                        }
                        cur = obj->unk_114;
                    }
                }
                break;
            case 5:
                cur = func_80080698_81298(grp);
                for (i = 0; i < grp->count; i++) {
                    obj = grp->members[cur];
                    SprFinish(obj);
                    if (obj->unk_2E < 0) {
                        mA[0][0] = mA[1][1] = 1.0f;
                        mA[0][1] = mA[1][0] = 0.0f;
                        mA[2][0] = obj->unk_93 + obj->unk_48;
                        mA[2][1] = obj->unk_94 + obj->unk_4C;
                        obj->unk_04 = obj->unk_48;
                        obj->unk_08 = obj->unk_4C;
                        obj->unk_20 = obj->unk_58;
                    } else {
                        parent = grp->members[obj->unk_2E];
                        mB[0][0] = mB[1][1] = 1.0f;
                        mB[0][1] = mB[1][0] = 0.0f;
                        mB[2][0] = (obj->unk_93 + obj->unk_48) * obj->unk_18;
                        mB[2][1] = (obj->unk_94 + obj->unk_4C) * obj->unk_1C;
                        CalcGroupCenter(mB, mtx[obj->unk_2E], mA);
                        obj->unk_04 = (s16)mA[2][0];
                        obj->unk_08 = (s16)mA[2][1];
                        obj->unk_20 = parent->unk_20 + obj->unk_58;
                    }
                    angle = -obj->unk_58 * 0.0174532925222222225;
                    mB[0][0] = mB[1][1] = __cosf(angle);
                    s = __sinf(angle);
                    mB[0][1] = s;
                    mB[1][0] = -s;
                    mB[2][0] = mB[2][1] = 0.0f;
                    CalcGroupCenter(mB, mA, mtx[obj->unk_00]);
                    func_80083748_84348(obj);
                    if (obj->unk_116 >= 0) {
                        stack[sp++] = cur;
                        cur = obj->unk_116;
                        sp %= 256;
                    } else {
                        while (obj->unk_114 < 0 && sp != 0) {
                            idx = stack[--sp];
                            sp %= 256;
                            obj = grp->members[idx];
                        }
                        cur = obj->unk_114;
                    }
                }
                break;
        }
    }
}
void func_80081378_81F78(void) {
    if (D_800FA5F8_FB1F8[D_800FDBE0_FE7E0] != NULL) {
        HuMemFree(D_800FA5F8_FB1F8[D_800FDBE0_FE7E0]);
    }
    if (D_800FD8BC_FE4BC != 0) {
        D_800FA5F8_FB1F8[D_800FDBE0_FE7E0] = HuMemAlloc(D_800FD8BC_FE4BC);
    } else {
        D_800FA5F8_FB1F8[D_800FDBE0_FE7E0] = NULL;
    }
    D_801016C0_1022C0 = D_800FA5F8_FB1F8[D_800FDBE0_FE7E0];
}

/* MP1 func_8006677C: the sprite layer's draw hook */
void SprExec(Gfx** gfx, Mtx* mtx, SprCamera* cam) {
    HuSprite* obj;
    HuSprite* next;
    s16 flag = 0;
    Gfx* branch = NULL;
    Gfx* end = NULL;

    D_800FD8BC_FE4BC = 0;
    SprBegin();
    obj = GetFirstSprite();
    func_80081378_81F78();
    D_800F9294_F9E94 = HuMemAlloc(0x4000);
    gSPViewport((*gfx)++, &D_800CD5A0_CE1A0);
    gSPPerspNormalize((*gfx)++, 0x8000);
    gSPMatrix((*gfx)++, osVirtualToPhysical(&D_800ED610_EE210), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gDPSetScissor((*gfx)++, G_SC_NON_INTERLACE, 0, 0, 320, 240);
    gDPPipeSync((*gfx)++);
    gDPSetTexturePersp((*gfx)++, G_TP_NONE);
    gSPTexture((*gfx)++, 0xFFFF, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gSPClearGeometryMode((*gfx)++, G_CULL_BOTH);
    gSPSetGeometryMode((*gfx)++, G_ZBUFFER | G_TEXTURE_GEN_LINEAR); /* 0x80001 */
    gDPSetBlendColor((*gfx)++, 0, 0, 0, 1);
    gDPSetAlphaCompare((*gfx)++, G_AC_THRESHOLD);
    D_800ED650_EE250 = NULL;
    while (obj != NULL) {
        if (obj->unk_24 & 0x4000) {
            if (flag) {
                if (branch != NULL) {
                    gSPBranchList(branch, *gfx + 1);
                }
                end = (*gfx)++;
            }
            flag = 0;
        } else {
            if (!flag) {
                if (end != NULL) {
                    gSPBranchList(end, *gfx + 1);
                }
                branch = (*gfx)++;
                if (D_800ED650_EE250 == NULL) {
                    D_800ED650_EE250 = *gfx;
                }
            }
            flag = 1;
        }
        SprDisp(gfx, obj, cam);
        next = obj->unk_118;
        obj->unk_11C = NULL;
        obj->unk_118 = NULL;
        obj = next;
    }
    if (flag) {
        gSPEndDisplayList((*gfx)++);
        if (branch != NULL) {
            gSPBranchList(branch, *gfx);
        }
    } else if (D_800ED650_EE250 != NULL) {
        gSPEndDisplayList(end);
    }
    gDPSetTextureLUT((*gfx)++, G_TT_NONE);
    HuMemFree(D_800F9294_F9E94);
    gSPMatrix((*gfx)++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix((*gfx)++, mtx + 1, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPSetScissor((*gfx)++, G_SC_NON_INTERLACE, cam->scissor[0], cam->scissor[1], cam->scissor[2], cam->scissor[3]);
}

void SprLayerHook(Gfx** gfx, Mtx* mtx, SprCamera* cam) {
    if (D_800ED650_EE250 != NULL) {
        gSPViewport((*gfx)++, &D_800CD5A0_CE1A0);
        gSPPerspNormalize((*gfx)++, 0x8000);
        gSPMatrix((*gfx)++, osVirtualToPhysical(&D_800ED610_EE210), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
        gDPSetScissor((*gfx)++, G_SC_NON_INTERLACE, 0, 0, 320, 240);
        gDPPipeSync((*gfx)++);
        gDPSetTexturePersp((*gfx)++, G_TP_NONE);
        gSPTexture((*gfx)++, 0xFFFF, 0x8000, 0, G_TX_RENDERTILE, G_ON);
        gSPClearGeometryMode((*gfx)++, G_CULL_BOTH);
        gSPSetGeometryMode((*gfx)++, G_ZBUFFER | G_TEXTURE_GEN_LINEAR); /* 0x80001 */
        gDPSetBlendColor((*gfx)++, 0, 0, 0, 1);
        gDPSetAlphaCompare((*gfx)++, G_AC_THRESHOLD);
        gSPDisplayList((*gfx)++, D_800ED650_EE250);
        gDPSetTextureLUT((*gfx)++, G_TT_NONE);
        gSPMatrix((*gfx)++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
        gSPMatrix((*gfx)++, mtx + 1, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gDPSetScissor((*gfx)++, G_SC_NON_INTERLACE, cam->scissor[0], cam->scissor[1], cam->scissor[2], cam->scissor[3]);
    }
}
void SprPosSet(s16 grpIdx, s16 idx, s16 x, s16 y) {
    HuSprite* sprite = HuSprGrpData[grpIdx]->members[idx];

    sprite->unk_48 = x;
    sprite->unk_4C = y;
}
void func_80081B28_82728(s16 group, s16 member, s16 arg2) {
    HuSprite* sprite = HuSprGrpData[group]->members[member];

    sprite->unk_44 = arg2;
}

void TransformPoint(Mtx* m, f32 x, f32 y, f32 z, f32 w, f32* ox, f32* oy, f32* oz, f32* ow) {
    f32 mf[4][4];

    func_800B30D0_B3CD0(mf, m);
    *ox = x * mf[0][0] + y * mf[1][0] + z * mf[2][0] + mf[3][0];
    *oy = x * mf[0][1] + y * mf[1][1] + z * mf[2][1] + mf[3][1];
    *oz = x * mf[0][2] + y * mf[1][2] + z * mf[2][2] + mf[3][2];
    *ow = x * mf[0][3] + y * mf[1][3] + z * mf[2][3] + mf[3][3];
}
/* Screen position (and depth in unk_44) of world point (x, y, z) seen from camera camIdx. */
void SprPos3DSet(s16 grpIdx, s16 idx, s16 camIdx, f32 x, f32 y, f32 z) {
    Mtx persp;
    Mtx lookAt;
    u16 perspNorm;
    f32 vx;
    f32 vy;
    f32 vz;
    f32 vw;
    f32 px;
    f32 py;
    f32 pz;
    f32 pw;
    HuSprite* sprite = HuSprGrpData[grpIdx]->members[idx];
    HuCamera* cam = &D_800C9B80_CA780[camIdx];
    s32 depth;
    f32 dist;

    guPerspective(&persp, &perspNorm, cam->fov[0], 1.3333334f, cam->fov[1], cam->fov[2], 1.0f);
    guLookAt(&lookAt, cam->pos.x, cam->pos.y, cam->pos.z, cam->at.x, cam->at.y, cam->at.z, cam->up.x, cam->up.y,
             cam->up.z);
    TransformPoint(&lookAt, x, y, z, 1.0f, &vx, &vy, &vz, &vw);
    TransformPoint(&persp, vx, vy, vz, vw, &px, &py, &pz, &pw);
    if (pw != 0.0f) {
        depth = (cam->viewports[D_800FFFD6_100BD6].vp.vscale[2] << 5) * pz / pw + (cam->viewports[D_800FFFD6_100BD6].vp.vtrans[2] << 5);
    } else {
        depth = cam->viewports[D_800FFFD6_100BD6].vp.vtrans[2] << 5;
    }
    if (depth < 0) {
        depth = 0;
    } else if (depth > 0x7FC0) {
        depth = 0x7FC0;
    }
    dist = fabsf(HuMathSin(D_800C9B80_CA780[camIdx].fov[0] * 0.5) * vz /
                 func_800B7890_B8490(D_800C9B80_CA780[camIdx].fov[0] * 0.5));
    D_800ED654_EE254 = dist;
    if (dist != 0.0) {
        sprite->unk_48 = cam->viewports[D_800FFFD6_100BD6].vp.vscale[0] / 4.0 * vx / dist / 1.3333334f + cam->viewports[D_800FFFD6_100BD6].vp.vtrans[0] / 4.0;
        sprite->unk_4C = cam->viewports[D_800FFFD6_100BD6].vp.vscale[1] / 4.0 * -vy / dist + cam->viewports[D_800FFFD6_100BD6].vp.vtrans[1] / 4.0;
    }
    sprite->unk_44 = depth;
}
void SprPosPerspectiveSet(s16 grpIdx, s16 idx, s16 camIdx, f32 x, f32 y, f32 z) {
    HuSprite* sprite = HuSprGrpData[grpIdx]->members[idx];
    HuCamera* cam = &D_800C9B80_CA780[camIdx];
    HuCamera* vp;

    SprPos3DSet(grpIdx, idx, camIdx, x, y, z);
    if (D_800ED654_EE254 != 0.0) {
        vp = (HuCamera*)((u8*)cam + D_800FFFD6_100BD6 * 16);
        sprite->unk_60 = vp->viewports[0].vp.vscale[0] / 4.0 / D_800ED654_EE254 / 1.3333334f;
        sprite->unk_64 = vp->viewports[0].vp.vscale[1] / 4.0 / D_800ED654_EE254;
    }
}
void SprBankSet(s16 grpIdx, s16 idx, u16 bank) {
    HuSprGrpData[grpIdx]->members[idx]->unk_90 = bank;
}

void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3) {
    HuSprite* sprite_ptr = HuSprGrpData[group]->members[member];

    sprite_ptr->unk_84 = D_800F60B0_F6CB0[arg2];
    if (D_800F60B0_F6CB0[arg2]->unk04 != 0) {
        sprite_ptr->unk_0E = 1;
    }
    sprite_ptr->unk_0C = arg3;
    sprite_ptr->unk_8C = 0.0f;
    sprite_ptr->unk_10 = 1.0f;
    sprite_ptr->unk_8A = 0;
    sprite_ptr->unk_88 = 0;
    sprite_ptr->unk_90 = 0;
    RestoreAnimState(sprite_ptr);
}

void func_8008221C_82E1C(s16 group, s16 member, f32 arg2) {
    HuSprite* sprite_ptr = HuSprGrpData[group]->members[member];

    sprite_ptr->unk_10 = arg2;
    RestoreAnimState(sprite_ptr);
}

void func_8008225C_82E5C(s16 group, s16 member, s32 arg2) {
    HuSprite* sprite_ptr = HuSprGrpData[group]->members[member];

    sprite_ptr->unk_88 &= 0x7F;
    sprite_ptr->unk_0E = arg2;
    RestoreAnimState(sprite_ptr);
}

void func_800822A8_82EA8(s16 group, s16 member, u16 arg2, s32 arg3) {
    HuSprite* sprite = HuSprGrpData[group]->members[member];

    sprite->unk_88 &= 0x7F;
    sprite->unk_0C = arg2;
    sprite->unk_8A = arg3;
    sprite->unk_8C = 0;
    RestoreAnimState(sprite);
}

HuSprite_Unk84_Struct* SprAnimGet(s16 animIdx) {
    return D_800F60B0_F6CB0[animIdx];
}

u8 func_80082314_82F14(s16 grpIdx, s16 idx) {
    return HuSprGrpData[grpIdx]->members[idx]->unk_88;
}

void SprScaleSet(s16 grpIdx, s16 idx, f32 sx, f32 sy) {
    HuSprite* sprite = HuSprGrpData[grpIdx]->members[idx];

    sprite->unk_50 = sx;
    sprite->unk_54 = sy;
    sprite->unk_60 = sprite->unk_64 = 1.0f;
}
void SprPrioSet(s16 grpIdx, s16 idx, u16 pri) {
    HuSprGrpData[grpIdx]->members[idx]->prio = pri;
}

void SprRotSet(s16 grpIdx, s16 idx, f32 rot) {
    HuSprGrpData[grpIdx]->members[idx]->unk_58 = rot;
}

void SprAttrReset(s16 grpIdx, s16 idx, s32 flag) {
    HuSprite* obj = HuSprGrpData[grpIdx]->members[idx];

    obj->unk_24 = obj->unk_5C &= ~flag;
}

void SprAttrSet(s16 grpIdx, s16 idx, s32 flag) {
    HuSprite* obj = HuSprGrpData[grpIdx]->members[idx];

    obj->unk_24 = obj->unk_5C |= flag;
}

void func_80082450_83050(s16 grpIdx, s32 idx, s32 r, s32 g, u8 b) {
    HuSprite* obj = HuSprGrpData[grpIdx]->members[(s16)idx];

    obj->unk_28[0] = r;
    obj->unk_28[1] = g;
    obj->unk_28[2] = b;
}

void func_80082488_83088(s16 grpIdx, s16 idx, u16 a) {
    HuSprGrpData[grpIdx]->members[idx]->unk_2C = a;
}

void func_800824B4_830B4(s16 grpIdx, s32 idx, u8 r, u8 g, u8 b, u16 a) {
    HuSprite* obj = HuSprGrpData[grpIdx]->members[(s16)idx];

    obj->unk_28[0] = r;
    obj->unk_28[1] = g;
    obj->unk_28[2] = b;
    obj->unk_2C = a;
}

void func_800824F4_830F4(s16 grpIdx, s16 idx, s16 arg2) {
    HuSprGrpData[grpIdx]->members[idx]->unk_2E = arg2;
}

void func_80082520_83120(s16 grpIdx, s16 idx, u8 arg2, u8 arg3) {
    HuSprite* obj = HuSprGrpData[grpIdx]->members[idx];

    obj->unk_93 = arg2;
    obj->unk_94 = arg3;
}

HuSprite* func_80082550_83150(s16 grpIdx, s16 idx) {
    return HuSprGrpData[grpIdx]->members[idx];
}

void func_80082578_83178(s16 grpIdx, s16 idx, s16 arg2, s16 arg3, u16 arg4, u16 arg5) {
    HuSprite* obj = HuSprGrpData[grpIdx]->members[idx];

    obj->unk_3C = arg2;
    obj->unk_3E = arg3;
    obj->unk_40 = arg4;
    obj->unk_42 = arg5;
}

void func_800825B8_831B8(s16 grpIdx, s16 idx, f32 arg2, f32 arg3) {
    HuSprite* obj = HuSprGrpData[grpIdx]->members[idx];

    obj->unk_30 = arg2;
    obj->unk_34 = arg3;
}

void func_800825E8_831E8(s16 grpIdx, s16 idx, s16 arg2, s16 arg3) {
    HuSprite* obj = HuSprGrpData[grpIdx]->members[idx];

    obj->unk_38 = arg2;
    obj->unk_3A = arg3;
}

void SprAnimInit(void) {
    s16 i;

    D_800F8F88_F9B88 = 0;
    for (i = 0; i < 256; i++) {
        D_800F60B0_F6CB0[i] = NULL;
    }
}

void SprAnimKill(s16 animIdx) {
    HuSprite_Unk84_Struct* anim = D_800F60B0_F6CB0[animIdx];
    HuSprCelAnm* cel;
    HuSprite_Unk84_Unk00_Struct* bmp;
    s16 i;

    if (anim->unk04 != NULL) {
        cel = *anim->unk04;
        if (cel != NULL) {
            for (i = 0; i < anim->unk12; i++) {
                HuMemFree(cel->unk04);
                cel++;
            }
        }
        HuMemFree(*anim->unk04);
        HuMemFree(anim->unk04);
    }
    func_80027340_27F40(anim->unk0C);
    bmp = anim->unk00;
    for (i = 0; i < anim->unk10; i++) {
        func_80027340_27F40((bmp++)->unk00);
    }
    HuMemFree(anim->unk00);
    HuMemFree(anim);
    D_800F60B0_F6CB0[animIdx] = NULL;
    D_800F8F88_F9B88--;
}

void SprAnimKillAll(void) {
    s16 i;

    for (i = 0; i < 256; i++) {
        if (D_800F60B0_F6CB0[i] != NULL) {
            SprAnimKill(i);
        }
    }
}

/* Loads a sprite animation (MP1 func_800678A4): frames, palette and key banks. */
// register allocation (pal/idx swap s7/s8, the keys base hoisted) and a reload differ (masked 135)
#ifdef NON_MATCHING
s16 SprAnimRead(void* arg0) {
    u8* data = arg0;
    HuSprCelFrame* keys[256];
    u8* bankTbl;
    HuSprite_Unk84_Struct* anim;
    HuSprite_Unk84_Unk00_Struct* frame;
    HuSprCelAnm** tbl;
    HuSprCelAnm* banks;
    HuSprCelFrame* key;
    u8* src;
    u8* pix;
    u8* pal;
    u8* p;
    u8* palDst;
    s32 size;
    u32 j;
    s16 i;
    s16 k;
    s16 idx;

    for (i = 0; i < 256; i++) {
        if (D_800F60B0_F6CB0[i] == NULL) {
            break;
        }
    }
    if (i == 256) {
        return -1;
    }
    idx = i;
    anim = HuMemAlloc(sizeof(*anim));
    if (anim == NULL) {
        return -1;
    }
    src = data + READ32(data);
    bankTbl = data + READ32(data + 4);
    pix = data + READ32(data + 8);
    pal = data + READ32(data + 0xC);
    anim->unk10 = READ16(data + 0x10);
    anim->unk12 = READ16(data + 0x12);
    anim->unk14 = READ16(data + 0x14);
    anim->unk16 = READ16(data + 0x16);
    anim->unk18 = READ16(data + 0x18);
    anim->unk1A = data[0x1A];
    /* an 8-bit image with no palette size gets 256 entries (retail tests both halves as one word) */
    if (*(s32*)&anim->unk18 == 0x80000) {
        anim->unk1A = 0x100;
    }
    anim->unk00 = NULL;
    anim->unk04 = NULL;
    anim->unk08 = NULL;
    anim->unk0C = NULL;
    D_800F60B0_F6CB0[idx] = anim;
    D_800F8F88_F9B88++;
    frame = HuMemAlloc(anim->unk10 * sizeof(*frame));
    if (frame == NULL) {
        SprAnimKill(idx);
        return -1;
    }
    anim->unk00 = frame;
    for (i = 0; i < anim->unk10; i++) {
        frame->unk04 = READ16(src + 4);
        frame->unk06 = READ16(src + 6);
        frame->unk08 = READ16(src + 8);
        frame->unk0A = READ16(src + 0xA);
        size = frame->unk04 * frame->unk06 * (anim->unk18 & 0x7FFF) / 8;
        if ((frame->unk00 = HuMemAlloc(size)) == NULL) {
            goto fail_frame;
        }
        for (j = 0; j < size; j++) {
            ((u8*)frame->unk00)[j] = *pix++;
        }
        src += 0xC;
        if (i == 0) {
            anim->unk08 = frame->unk00;
        }
        frame++;
    }
    if (anim->unk1A != 0) {
        palDst = HuMemAlloc(anim->unk1A * 2);
        if (palDst == NULL) {
            goto fail;
        }
        anim->unk0C = palDst;
        for (i = 0; i < anim->unk1A; i++) {
            *palDst++ = pal[i * 2];
            *palDst++ = pal[i * 2 + 1];
        }
    }
    if (anim->unk12 != 0) {
        tbl = HuMemAlloc(anim->unk12 * sizeof(*tbl));
        if (tbl == NULL) {
            goto fail;
        }
        anim->unk04 = tbl;
        banks = HuMemAlloc(anim->unk12 * sizeof(*banks));
        if (banks != NULL) {
            goto ok;
        }
        goto fail;
    fail_frame:
        anim->unk10 = i;
        goto fail;
    fail_bank:
        anim->unk12 = k;
    fail:
        SprAnimKill(idx);
        return -1;
    ok:
        /* retail bug: the stride is 64 bytes, not one bank; only tbl[0] is ever read */
        for (i = 0; i < anim->unk12; i++) {
            tbl[i] = &banks[i * 8];
        }
        for (k = 0; k < anim->unk12; k++) {
            p = data + READ32(bankTbl + k * 4);
            banks->unk00 = READ16(p);
            p += 2;
            keys[k] = HuMemAlloc(banks->unk00 * 8);
            if (keys[k] == NULL) {
                goto fail_bank;
            }
            banks->unk04 = keys[k];
            key = keys[k];
            for (i = 0; i < banks->unk00; i++) {
                key->unk00 = READ16(p);
                key->unk02 = READ16(p + 2);
                key->unk04 = p[4];
                key->unk05 = p[5];
                key->unk06 = p[6];
                p += 7;
                key++;
            }
            banks++;
        }
    }
    return idx;
}
#else
INCLUDE_ASM("asm/nonmatchings/80230", SprAnimRead);
#endif
s32 SprAnimMake(u16 arg0, u16 arg1, u16 arg2, u16 arg3, u16 arg4) {
    HuSprite_Unk84_Struct* desc;
    HuSprite_Unk84_Unk00_Struct* cel;
    s16 i;
    s16 slot;

    for (i = 0; i < 0x100 && D_800F60B0_F6CB0[i] != NULL; i++) {
    }
    if (i == 0x100) {
        return -1;
    }
    slot = i;
    desc = HuMemAlloc(0x1C);
    if (desc == NULL) {
        return -1;
    }
    desc->unk10 = arg4;
    desc->unk12 = 0;
    desc->unk14 = arg0;
    desc->unk16 = arg1 * arg4;
    desc->unk18 = arg2;
    desc->unk1A = arg3;
    desc->unk00 = NULL;
    desc->unk04 = 0;
    desc->unk08 = NULL;
    desc->unk0C = NULL;
    D_800F60B0_F6CB0[slot] = desc;
    D_800F8F88_F9B88++;
    cel = HuMemAlloc(desc->unk10 * 0xC);
    if (cel != NULL) {
        desc->unk00 = cel;
    } else {
        SprAnimKill(slot);
        return -1;
    }
    for (i = 0; i < desc->unk10; i++) {
        s32 size;

        cel->unk04 = arg0;
        cel->unk06 = arg1;
        cel->unk08 = arg0 >> 1;
        cel->unk0A = arg1 >> 1;
        size = cel->unk04 * cel->unk06 * (desc->unk18 & 0x7FFF);
        cel->unk00 = HuMemAlloc(size / 8);
        if (cel->unk00 == NULL) {
            desc->unk10 = i;
            SprAnimKill(slot);
            return -1;
        }
        if (i == 0) {
            desc->unk08 = cel->unk00;
        }
        cel++;
    }
    if (desc->unk1A != 0) {
        void* pal = HuMemAlloc(desc->unk1A * 2);

        if (pal != NULL) {
            desc->unk0C = pal;
        } else {
            SprAnimKill(slot);
            return -1;
        }
    }
    return slot;
}

void func_80082FE4_83BE4(HuSprAnm* arg0, s16 arg1, u16 arg2, u16 arg3) {
    InitAnimState(arg0);
    arg0->unk06 = arg3;
    arg0->unk08 = arg2;
    arg0->unk00 = SprAnimGet(arg1);
}

s16 func_80083044_83C44(void* arg0, HuSprAnm* arg1, u16 arg2, u16 arg3) {
    s16 temp = SprAnimRead(arg0);

    func_80082FE4_83BE4(arg1, temp, arg2, arg3);
    return temp;
}

HuSprite_Unk84_Unk00_Struct* SprAnimBmpDirectGet(HuSprite_Unk84_Struct** arg0, u16 arg1) {
    return &(*arg0)->unk00[arg1];
}

HuSprite_Unk84_Unk00_Struct* SprAnimBmpGet(s16 arg0, u16 arg1) {
    return &D_800F60B0_F6CB0[arg0]->unk00[arg1];
}

HuSprite_Unk84_Unk00_Struct* func_800830F8_83CF8(HuSprAnm* arg0) {
    return &arg0->unk00->unk00[arg0->unk14];
}

void* SprAnimBmpDataDirectGet(HuSprite_Unk84_Struct** arg0, u16 arg1) {
    HuSprite_Unk84_Unk00_Struct* entry = &(*arg0)->unk00[arg1];

    return entry->unk00;
}

void* SprAnimBmpDataGet(s16 arg0, u16 arg1) {
    HuSprite_Unk84_Unk00_Struct* entry = &D_800F60B0_F6CB0[arg0]->unk00[arg1];

    return entry->unk00;
}

void func_80083170_83D70(HuSprite_Unk84_Struct** arg0, u16 arg1, void* arg2) {
    HuSprite_Unk84_Unk00_Struct* entry = &(*arg0)->unk00[arg1];

    func_80027340_27F40(entry->unk00);
    entry->unk00 = arg2;
}

void func_800831C0_83DC0(s16 arg0, u16 arg1, void* arg2) {
    HuSprite_Unk84_Unk00_Struct* entry = &D_800F60B0_F6CB0[arg0]->unk00[arg1];

    func_80027340_27F40(entry->unk00);
    entry->unk00 = arg2;
}

void* func_80083220_83E20(HuSprAnm* arg0) {
    HuSprite_Unk84_Unk00_Struct* entry = &arg0->unk00->unk00[arg0->unk14];

    return entry->unk00;
}

void* SprAnimBmpPalDirectGet(HuSprite_Unk84_Struct** arg0) {
    return (*arg0)->unk0C;
}
void* SprAnimBmpPalGet(s16 arg0) {
    return D_800F60B0_F6CB0[arg0]->unk0C;
}

void func_8008326C_83E6C(HuSprite_Unk84_Struct** arg0, void* arg1) {
    func_80027340_27F40((*arg0)->unk0C);
    (*arg0)->unk0C = arg1;
}

void func_800832AC_83EAC(s16 arg0, void* arg1) {
    func_80027340_27F40(D_800F60B0_F6CB0[arg0]->unk0C);
    D_800F60B0_F6CB0[arg0]->unk0C = arg1;
}

s16 func_800832FC_83EFC(HuSprAnm* arg0) {
    HuSprite_Unk84_Struct* desc = arg0->unk00;

    if (desc == NULL) {
        return -1;
    }
    if (arg0->unk06 == 1) {
        HuSprCelAnm* cel;
        HuSprCelFrame* frame;

        if (desc->unk04 == NULL) {
            return 0;
        }
        cel = &(*desc->unk04)[arg0->unk08];
        frame = &cel->unk04[arg0->unk0A];
        arg0->unk14 = frame->unk00;
        arg0->unk17 = frame->unk04;
        arg0->unk18 = frame->unk05;
        arg0->unk16 = frame->unk06;
    } else if (arg0->unk06 >= 2) {
        if (arg0->unk06 < 4) {
            arg0->unk14 = arg0->unk0A;
        }
    }
    return 0;
}

void AnimateSprite(HuSprAnm* anm) {
    HuSprite_Unk84_Struct* anim;
    HuSprCelAnm* bank;
    HuSprCelFrame* key;
    s16 old;

    anim = anm->unk00;
    if (anim == NULL) {
        return;
    }
    anm->unk04 &= 0x80;
    switch (anm->unk06) {
        case 0:
            break;
        case 1:
            if (anim->unk04 == NULL) {
                break;
            }
            bank = &(*anim->unk04)[anm->unk08];
            key = &bank->unk04[anm->unk0A];
            anm->unk0C += anm->unk10;
            if ((s16)anm->unk0C > (s16)key->unk02) {
                anm->unk0C = 0.0f;
                anm->unk0A++;
                anm->unk04 |= 4;
                if (anm->unk0A >= bank->unk00) {
                    anm->unk06 = 0;
                    anm->unk04 |= 2;
                } else if ((s16)bank->unk04[anm->unk0A].unk02 < 0) {
                    anm->unk0A = 0;
                    anm->unk04 |= 8;
                }
            }
            anm->unk14 = key->unk00;
            anm->unk17 = key->unk04;
            anm->unk18 = key->unk05;
            anm->unk16 = key->unk06;
            anm->unk04 |= 1;
            break;
        case 2:
            old = anm->unk0A;
            anm->unk0C += anm->unk10;
            anm->unk0A = (s32)anm->unk0C + anm->unk0A;
            if (anm->unk0A != old) {
                anm->unk0C -= anm->unk0A - old;
                anm->unk04 |= 4;
            }
            if (anm->unk0A >= anm->unk00->unk10) {
                anm->unk0A = 0;
                anm->unk0C = 0.0f;
                anm->unk04 |= 8;
            }
            anm->unk14 = anm->unk0A;
            anm->unk04 |= 1;
            break;
        case 3:
            old = anm->unk0A;
            anm->unk0C += anm->unk10;
            anm->unk0A = (s32)anm->unk0C + anm->unk0A;
            if (anm->unk0A != old) {
                anm->unk0C -= anm->unk0A - old;
                anm->unk04 |= 8;
            }
            if (anm->unk0A < 0 || anm->unk0A >= anm->unk00->unk10) {
                anm->unk0A = (anm->unk10 < 0.0f) ? 1 : anm->unk00->unk10 - 2;
                anm->unk0C = 0.0f;
                anm->unk10 = -anm->unk10;
                anm->unk04 |= 8;
            }
            anm->unk14 = anm->unk0A;
            anm->unk04 |= 1;
            break;
    }
}
void SprFinish(HuSprite* sprite) {
    HuSprAnm* anm = &sprite->unk_68;

    RestoreAnimState(sprite);
    if (!(sprite->unk_68.unk04 & 0x80)) {
        if (func_800832FC_83EFC(anm) == 0) {
            sprite->unk_68.unk04 |= 0x80;
        }
    } else {
        if (D_800FDC9C_FE89C == 0 || (sprite->unk_24 & 0x1000000)) {
            AnimateSprite(anm);
        }
    }
    sprite->unk_88 = anm->unk04;
    sprite->unk_0E = (u16)anm->unk06;
    sprite->unk_90 = (u16)anm->unk14;
    sprite->unk_93 = anm->unk17;
    sprite->unk_94 = anm->unk18;
    sprite->unk_92 = anm->unk16;
    sprite->unk_8A = (u16)anm->unk0A;
    sprite->unk_8C = anm->unk0C;
    sprite->unk_10 = anm->unk10;
    sprite->unk_18 = sprite->unk_50 * sprite->unk_60;
    sprite->unk_1C = sprite->unk_54 * sprite->unk_64;
    if (sprite->unk_98 != NULL) {
        func_800841B8_84DB8((struct SprPalAnim*)&sprite->unk_98);
    }
}

/* Before drawing (MP1 func_80068124): a sprite that is rotated, scaled or flagged for the
   textured-quad path counts the display-list space it needs (D_800FD8BC), or (flag 0x8000000)
   gets its own buffer. */
void func_80083748_84348(HuSprite* sprite) {
    HuSprite_Unk84_Struct* anim;
    HuSprite_Unk84_Unk00_Struct* frame;
    s32 fmt = 0;
    s32 siz = 0;
    s32 w;
    u32 lines;
    s32 n;
    s32 diff;

    sprite->unk_24 = (u8)sprite->unk_92 ^ sprite->unk_5C;
    if (sprite->unk_84 != NULL && !(sprite->unk_24 & 0x8000)) {
        if (fabs(func_800B0D98_B1998(sprite->unk_20, 360.0)) > 0.1f || (sprite->unk_24 & 0x3C0C00) ||
            (sprite->unk_24 & 0x30000) == 0x30000 || (sprite->unk_24 & 0x20000000)) {
            anim = sprite->unk_84;
            frame = &anim->unk00[sprite->unk_90];
            switch (anim->unk18 & 0x7FFF) {
                case 4:
                    fmt = 2;
                    siz = 0;
                    break;
                case 8:
                    fmt = 2;
                    siz = 1;
                    break;
                case 16:
                    fmt = 0;
                    siz = 2;
                    break;
                case 24:
                    fmt = 0;
                    siz = 3;
                    break;
            }
            w = (((frame->unk04 << siz) >> 4) << 4) >> siz;
            if (w < frame->unk04) {
                w += 16 >> siz;
            }
            switch (fmt) {
            case 2:
                if ((0x1000 >> siz) >= frame->unk06 * w) {
                    lines = frame->unk06;
                } else {
                    lines = (0x1000 >> siz) / w;
                }
                break;
            case 4:
                lines = frame->unk06;
                if (frame->unk06 * w > 0x1000) {
                    lines = 0x1000 / w;
                }
                break;
            default:
                if ((0x2000 >> siz) >= frame->unk06 * w) {
                    lines = frame->unk06;
                } else {
                    lines = (0x2000 >> siz) / w;
                }
                break;
            }
            n = frame->unk06 / lines;
            sprite->unk_24 |= 0x40000000;
            if (!(sprite->unk_24 & 0x8000000)) {
                if (!(sprite->unk_24 & 0x2000)) {
                    D_800FD8BC_FE4BC += (n + 2) << 5;
                } else {
                    D_800FD8BC_FE4BC += (n + 2) << 6;
                }
            } else {
                diff = sprite->unk_24 ^ sprite->unk_200;
                if (sprite->unk_124 == NULL || (diff & 0x40000000)) {
                    sprite->unk_24 |= 0x10000000;
                }
                if (sprite->unk_24 & 0x10000000) {
                    if (sprite->unk_128[sprite->unk_120] != NULL) {
                        HuMemFree(sprite->unk_128[sprite->unk_120]);
                        HuMemFree(sprite->unk_134[sprite->unk_120]);
                        sprite->unk_128[sprite->unk_120] = NULL;
                        sprite->unk_134[sprite->unk_120] = NULL;
                    }
                    if (!(sprite->unk_24 & 0x2000)) {
                        sprite->unk_134[sprite->unk_120] = HuMemAlloc((n + 2) << 5);
                    } else {
                        sprite->unk_134[sprite->unk_120] = HuMemAlloc((n + 2) << 6);
                    }
                }
            }
        } else {
            sprite->unk_24 &= ~0x40000000;
            if (sprite->unk_24 & 0x8000000) {
                diff = sprite->unk_24 ^ sprite->unk_200;
                if (sprite->unk_124 == NULL || (diff & 0x40000000)) {
                    sprite->unk_24 |= 0x10000000;
                }
                if (sprite->unk_24 & 0x10000000) {
                    if (sprite->unk_128[sprite->unk_120] != NULL) {
                        HuMemFree(sprite->unk_128[sprite->unk_120]);
                        HuMemFree(sprite->unk_134[sprite->unk_120]);
                        sprite->unk_128[sprite->unk_120] = NULL;
                        sprite->unk_134[sprite->unk_120] = NULL;
                    }
                }
            }
        }
        sprite->unk_200 = sprite->unk_24;
    }
}
void func_80083B9C_8479C(void) {
    s16 i;

    SprClose();
    SprAnimKillAll();
    func_80084148_84D48();
    for (i = 0; i < 3; i++) {
        if (D_800FA5F8_FB1F8[i] != NULL) {
            HuMemFree(D_800FA5F8_FB1F8[i]);
        }
    }
}

void func_80083C18_84818(void) {
    f32 mf[4][4];
    Mtx m1;
    Mtx m2;

    func_800B0D98_B1998(0.0, 0.0);
    guTranslateF(mf, 0.0f, 0.0f, 0.0f);
    guMtxCatL(&m1, &m2, &m1);
}
u16 func_80083C64_84864(u8** arg0) {
    u8* p = *arg0;
    u16 val = (p[0] << 8) + p[1];

    *arg0 = p + 2;
    return val;
}

u32 func_80083C88_84888(u8** arg0) {
    u8* p = *arg0;
    u32 val = (p[0] << 24) + (p[1] << 16) + (p[2] << 8) + p[3];

    *arg0 = p + 4;
    return val;
}

void func_80083CC0_848C0(void) {
    s16 i;

    D_80101630_102230 = 0;
    for (i = 0; i < 256; i++) {
        D_800FCEA0_FDAA0[i] = NULL;
    }
}

s16 func_80083D08_84908(u8* data) {
    u8* p;
    HuSprAnmDesc* desc;
    SprPalGroup* grp;
    SprPalFrame* frame;
    SprPalEntry* e;
    s32 i;
    s32 j;
    s32 k;
    s32 slot;
    u8* base = data;

    for (i = 0; i < 256; i++) {
        if (D_800FCEA0_FDAA0[i] == NULL) {
            break;
        }
    }
    if (i == 256) {
        return -1;
    }
    slot = i;
    desc = HuMemAlloc(sizeof(HuSprAnmDesc));
    desc->unk00 = func_80083C64_84864(&data);
    desc->unk02 = func_80083C64_84864(&data);
    desc->unk04 = HuMemAlloc(desc->unk02 * 4);
    for (j = 0; j < desc->unk02; j++) {
        desc->unk04[j] = (HuSprAnmEntry*)(grp = HuMemAlloc(sizeof(SprPalGroup)));
        p = base + func_80083C88_84888(&data);
        grp->count = func_80083C64_84864(&p);
        if (grp->count != 0) {
            grp->nframes = func_80083C64_84864(&p);
            grp->frames = HuMemAlloc(grp->nframes * 4);
            for (k = 0; k < grp->nframes; k++) {
                frame = HuMemAlloc(sizeof(SprPalFrame));
                grp->frames[k] = frame;
                frame->dur = func_80083C64_84864(&p);
                e = HuMemAlloc(grp->count * 4);
                frame->entries = e;
                for (i = 0; i < grp->count; i++, e++) {
                    e->idx = func_80083C64_84864(&p);
                    e->color = func_80083C64_84864(&p);
                }
            }
        }
    }
    desc->unk08 = func_80083C64_84864(&data);
    desc->unk0C = HuMemAlloc(desc->unk08 * 2);
    for (i = 0; i < desc->unk08; i++) {
        ((u16*)desc->unk0C)[i] = func_80083C64_84864(&data);
    }
    D_800FCEA0_FDAA0[slot] = desc;
    D_80101630_102230++;
    return slot;
}
void func_80083F70_84B70(s16 arg0) {
    HuSprAnmDesc* desc = D_800FCEA0_FDAA0[arg0];
    s32 i;

    for (i = 0; i < desc->unk02; i++) {
        HuSprAnmEntry* group = desc->unk04[i];

        if (group->unk00 != 0) {
            s32 j;

            for (j = 0; j < group->unk02; j++) {
                HuSprAnmEntry* cel = group->unk04[j];

                HuMemFree(cel->unk04);
                HuMemFree(cel);
            }
            HuMemFree(group->unk04);
        }
        HuMemFree(group);
    }
    HuMemFree(desc->unk04);
    HuMemFree(desc->unk0C);
    HuMemFree(desc);
    D_800FCEA0_FDAA0[arg0] = NULL;
    D_80101630_102230--;
}

void func_80084098_84C98(s16 group, s16 member, s16 arg2) {
    HuSprite* sprite = HuSprGrpData[group]->members[member];
    s32 i;

    sprite->unk_98 = D_800FCEA0_FDAA0[arg2];
    sprite->unk_FC = 1.0f;
    for (i = 0; i < 0x10; i++) {
        sprite->unk_9C[i] = 0xFFFF;
        sprite->unk_BC[i] = 0;
    }
    sprite->unk_104 = NULL;
}

void func_8008411C_84D1C(s16 grpIdx, s16 idx, f32 speed) {
    HuSprGrpData[grpIdx]->members[idx]->unk_FC = speed;
}

void func_80084148_84D48(void) {
    s16 i;

    for (i = 0; i < 256; i++) {
        if (D_800FCEA0_FDAA0[i] != NULL) {
            func_80083F70_84B70(i);
        }
    }
}

/* Steps a sprite's palette animation; when a frame changes, rebuilds the palette in the next of
   three buffers. */
// register allocation and the frame-reset branch layout differ (masked 110, 8 bytes short)
#ifdef NON_MATCHING
void func_800841B8_84DB8(SprPalAnim* pa) {
    HuSprAnmDesc* desc;
    SprPalGroup* grp;
    SprPalEntry* e;
    s32 changed;
    s32 i;
    s32 j;
    s32 dur;

    changed = 0;
    desc = pa->desc;
    for (i = 0; i < desc->unk02; i++) {
        grp = (SprPalGroup*)desc->unk04[i];
        if (grp->count != 0) {
            pa->timer[i] -= pa->speed;
            do {
                if (pa->timer[i] <= 0.0f) {
                    pa->frame[i]++;
                    if (pa->frame[i] >= grp->nframes || (dur = grp->frames[pa->frame[i]]->dur) <= 0) {
                        pa->frame[i] = 0;
                        dur = (*grp->frames)->dur;
                    }
                    pa->timer[i] = dur + pa->timer[i];
                    changed = 1;
                }
            } while (pa->timer[i] < 0.0f);
        }
    }
    if (changed) {
        if (pa->bufs[pa->bufIdx] == NULL) {
            pa->bufs[pa->bufIdx] = HuMemAlloc(desc->unk08 * 2);
        }
        pa->cur = pa->bufs[pa->bufIdx];
        bcopy(desc->unk0C, pa->cur, desc->unk08 * 2);
        pa->bufIdx++;
        if (pa->bufIdx >= 3) {
            pa->bufIdx = 0;
        }
        for (i = 0; i < desc->unk02; i++) {
            grp = (SprPalGroup*)desc->unk04[i];
            if (grp->count != 0) {
                e = grp->frames[pa->frame[i]]->entries;
                for (j = 0; j < grp->count; j++, e++) {
                    pa->cur[e->idx] = e->color;
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/80230", func_800841B8_84DB8);
#endif
