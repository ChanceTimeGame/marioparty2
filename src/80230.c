#include "common.h"

#include "game/malloc.h"

/* Sprite manager (MP1 src/65770.c, MP3 src/sprman.c). MP2's sprite object has MP3's layout (0x208
   bytes) and its group MP1's (members at 0xC); MP1's code is written against those layouts here. */

typedef struct {
    /* 0x00 */ void* unk00;
    /* 0x04 */ u16 unk04;
    /* 0x06 */ u16 unk06;
    /* 0x08 */ s16 unk08;
    /* 0x0A */ s16 unk0A;
} HuSprite_Unk84_Unk00_Struct; // size 0xC

typedef struct HuSprCelFrame {
    /* 0x00 */ u16 unk00;
    /* 0x02 */ u16 unk02;
    /* 0x04 */ u8 unk04;
    /* 0x05 */ u8 unk05;
    /* 0x06 */ u8 unk06;
    /* 0x07 */ u8 unk07;
} HuSprCelFrame; // size 0x8

typedef struct HuSprCelAnm {
    /* 0x00 */ u16 unk00;
    /* 0x02 */ u16 unk02;
    /* 0x04 */ HuSprCelFrame* unk04;
} HuSprCelAnm; // size 0x8

typedef struct {
    /* 0x00 */ HuSprite_Unk84_Unk00_Struct* unk00;
    /* 0x04 */ HuSprCelAnm** unk04;
    /* 0x08 */ void* unk08;
    /* 0x0C */ void* unk0C;
    /* 0x10 */ u16 unk10;
    /* 0x12 */ u16 unk12;
    /* 0x14 */ s16 unk14;
    /* 0x16 */ s16 unk16;
    /* 0x18 */ u16 unk18;
    /* 0x1A */ u16 unk1A;
} HuSprite_Unk84_Struct; // size 0x1C

typedef struct HuSprAnm {
    /* 0x00 */ HuSprite_Unk84_Struct* unk00;
    /* 0x04 */ u8 unk04;
    /* 0x06 */ s16 unk06;
    /* 0x08 */ s16 unk08;
    /* 0x0A */ s16 unk0A;
    /* 0x0C */ f32 unk0C;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ s16 unk14;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ u8 unk18;
} HuSprAnm; // size 0x1C

typedef struct HuSprAnmEntry {
    /* 0x00 */ u16 unk00;
    /* 0x02 */ u16 unk02;
    /* 0x04 */ struct HuSprAnmEntry** unk04;
} HuSprAnmEntry; // size 0x8

typedef struct HuSprAnmDesc {
    /* 0x00 */ u16 unk00;
    /* 0x02 */ u16 unk02;
    /* 0x04 */ HuSprAnmEntry** unk04;
    /* 0x08 */ u16 unk08;
    /* 0x0C */ void* unk0C;
} HuSprAnmDesc; // size 0x10

typedef struct HuSprite {
    /* 0x000 */ s16 unk_00;
    /* 0x002 */ s16 unk_02;
    /* 0x004 */ s32 unk_04;
    /* 0x008 */ s32 unk_08;
    /* 0x00C */ s16 unk_0C;
    /* 0x00E */ s16 unk_0E;
    /* 0x010 */ f32 unk_10;
    /* 0x014 */ u16 prio;
    /* 0x018 */ f32 unk_18;
    /* 0x01C */ f32 unk_1C;
    /* 0x020 */ s32 unk_20;
    /* 0x024 */ s32 unk_24;
    /* 0x028 */ u8 unk_28[4];
    /* 0x02C */ u16 unk_2C;
    /* 0x02E */ s16 unk_2E;
    /* 0x030 */ f32 unk_30;
    /* 0x034 */ f32 unk_34;
    /* 0x038 */ s16 unk_38;
    /* 0x03A */ s16 unk_3A;
    /* 0x03C */ s16 unk_3C;
    /* 0x03E */ s16 unk_3E;
    /* 0x040 */ u16 unk_40;
    /* 0x042 */ u16 unk_42;
    /* 0x044 */ s32 unk_44;
    /* 0x048 */ f32 unk_48;
    /* 0x04C */ f32 unk_4C;
    /* 0x050 */ f32 unk_50;
    /* 0x054 */ f32 unk_54;
    /* 0x058 */ f32 unk_58;
    /* 0x05C */ s32 unk_5C;
    /* 0x060 */ f32 unk_60;
    /* 0x064 */ f32 unk_64;
    /* 0x068 */ HuSprAnm unk_68;
    /* 0x084 */ HuSprite_Unk84_Struct* unk_84;
    /* 0x088 */ u8 unk_88;
    /* 0x08A */ s16 unk_8A;
    /* 0x08C */ f32 unk_8C;
    /* 0x090 */ s16 unk_90;
    /* 0x092 */ s8 unk_92;
    /* 0x093 */ u8 unk_93;
    /* 0x094 */ u8 unk_94;
    /* 0x098 */ HuSprAnmDesc* unk_98;
    /* 0x09C */ u16 unk_9C[0x10];
    /* 0x0BC */ s32 unk_BC[0x10];
    /* 0x0FC */ f32 unk_FC;
    /* 0x100 */ s16 unk_100;
    /* 0x104 */ s32 unk_104;
    /* 0x108 */ void* unk_108[3];
    /* 0x114 */ s16 unk_114; // next sibling in the group's tree
    /* 0x116 */ s16 unk_116; // first child
    /* 0x118 */ struct HuSprite* unk_118; // next in the priority-sorted draw list
    /* 0x11C */ struct HuSprite* unk_11C; // previous in the draw list
    /* 0x120 */ void* unk_120;
    /* 0x124 */ void* unk_124;
    /* 0x128 */ void* unk_128[3];
    /* 0x134 */ void* unk_134[3];
    /* 0x140 */ Mtx unk_140[3];
    /* 0x200 */ char unk_200[8];
} HuSprite; // size 0x208

typedef struct SprGrp {
    /* 0x00 */ struct SprGrp* prev;
    /* 0x04 */ struct SprGrp* next;
    /* 0x08 */ u16 unk8;
    /* 0x0A */ u16 count;
    /* 0x0C */ HuSprite* obj[1];
} SprGrp;

typedef struct SprBucket {
    /* 0x00 */ HuSprite* head;
    /* 0x04 */ HuSprite* tail;
} SprBucket;

extern SprGrp* D_800FA1B0_FADB0[256];          /* MP1 D_800EE330, MP3 HuSprGrpData */
extern SprGrp* D_800F64B4_F70B4;               /* first group */
extern SprGrp* D_800F8C40_F9840;               /* last group */
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
extern s8 D_800FDC9C_FE89C;                    /* MP3 HmfPauseF */

void* func_80027138_27D38(s32 size);           /* MP3 HuMemAlloc */
void func_800271D8_27DD8(void* data);          /* MP3 HuMemFree */
void func_80027340_27F40(void* data);
void SprFree(HuSprite* arg0);
void SprKill(s16 idx);
SprGrp* SprAlloc(s16 num, u16 attr);
void InitData(SprGrp* grp, u16 num);
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
void func_800841B8_84DB8(HuSprAnmDesc** arg0);
void func_80083F70_84B70(s16 arg0);
void func_80084148_84D48(void);

INCLUDE_ASM("asm/nonmatchings/80230", func_8007F630_80230);

SprGrp* SprAlloc(s16 num, u16 attr) {
    SprGrp* grp = func_80027138_27D38(num * sizeof(HuSprite*) + sizeof(SprGrp) - sizeof(HuSprite*));

    if (grp == NULL) {
        return NULL;
    }
    grp->unk8 = attr;
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
    SprGrp* grp = D_800FA1B0_FADB0[idx];
    SprGrp* prev = grp->prev;
    SprGrp* next = grp->next;
    HuSprite** p;
    s16 i;

    if (grp->obj[0] != NULL) {
        p = grp->obj;
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
    func_800271D8_27DD8(grp);
    D_800FA1B0_FADB0[idx] = NULL;
    D_80101074_101C74--;
}

void SprClose(void) {
    s16 i;

    D_80101074_101C74 = 0;
    for (i = 0; i < 256; i++) {
        if (D_800FA1B0_FADB0[i] != NULL) {
            SprKill(i);
        }
    }
    D_800F8C40_F9840 = NULL;
    D_800F64B4_F70B4 = NULL;
    D_800F841C_F901C = 0;
}

s16 SprCreate(s32 num, s32 attr) {
    SprGrp* grp;
    HuSprite** p;
    s16 i;
    s16 idx;

    for (i = 0; i < 256; i++) {
        if (D_800FA1B0_FADB0[i] == NULL) {
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
    D_800FA1B0_FADB0[idx] = grp;
    grp->count = 0;
    p = grp->obj;
    for (i = 0; i < (u16)num; i++) {
        if ((*p++ = func_80027138_27D38(sizeof(**p))) == NULL) {
            SprKill(idx);
            return -1;
        }
        grp->count++;
    }
    InitData(grp, num);
    return idx;
}

s32 func_8007FBB4_807B4(s16 idx, s16 start, u16 num) {
    SprGrp* grp = D_800FA1B0_FADB0[idx];
    HuSprite** p = &grp->obj[start];
    HuSprite* obj;
    s16 i;

    for (i = 0; i < num; i++) {
        SprFree(*p++);
    }
    grp->count -= num;
    if (grp->count == 0) {
        grp->obj[0] = NULL;
        SprKill(idx);
        return 0;
    }
    HuMemMemoryReallocPerm(grp, grp->count * 4 + 0xC);
    p = &grp->obj[start];
    for (i = 0; i < grp->count - start; i++) {
        *p = p[num];
        p++;
    }
    for (i = 0; i < grp->count; i++) {
        obj = grp->obj[i];
        obj->unk_00 = i;
        obj->unk_02 = grp->count;
    }
    return 0;
}

s32 func_8007FD58_80958(s16 idx, s16 pos, u16 num) {
    SprGrp* old = D_800FA1B0_FADB0[idx];
    SprGrp* grp;
    HuSprite** p;
    HuSprite* obj;
    s16 i;
    s16 newIdx;

    for (i = 0; i < 256; i++) {
        if (D_800FA1B0_FADB0[i] == NULL) {
            break;
        }
    }
    if (i == 256) {
        return -1;
    }
    newIdx = i;
    grp = SprAlloc(num + old->count, old->unk8);
    if (grp == NULL) {
        return -1;
    }
    D_800FA1B0_FADB0[newIdx] = grp;
    grp->count = 0;
    p = grp->obj;
    for (i = 0; i < num; i++) {
        if ((*p++ = func_80027138_27D38(sizeof(**p))) == NULL) {
            SprKill(newIdx);
            return -1;
        }
        grp->count++;
    }
    InitData(grp, num);
    grp->obj[0]->unk_2E = 0;
    if (pos >= 0) {
        p = grp->obj + num - 1;
        for (i = 0; i < num; i++) {
            p[pos + 1] = *p;
            p--;
        }
        p = grp->obj;
        for (i = 0; i < pos + 1; i++) {
            *p++ = old->obj[i];
        }
    }
    p = &grp->obj[pos] + num + 1;
    for (i = 0; i < old->count - (pos + 1); i++) {
        *p++ = (old->obj + pos)[i + 1];
    }
    grp->count = num + old->count;
    for (i = 0; i < grp->count; i++) {
        obj = grp->obj[i];
        obj->unk_00 = i;
        obj->unk_02 = grp->count;
    }
    old->obj[0] = NULL;
    SprKill(idx);
    D_800FA1B0_FADB0[idx] = grp;
    D_800FA1B0_FADB0[newIdx] = NULL;
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

INCLUDE_ASM("asm/nonmatchings/80230", InitData);

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
    SprGrp* grp;
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
            obj = grp->obj[i];
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

s16 func_80080698_81298(SprGrp* grp) {
    HuSprite* obj;
    HuSprite* parent;
    HuSprite* other;
    s16 root = 0;
    s16 i;
    s16 j;

    for (j = 0; j < grp->count; j++) {
        obj = grp->obj[j];
        obj->unk_114 = obj->unk_116 = -1;
    }
    for (i = 0; i < grp->count; i++) {
        obj = grp->obj[i];
        if (obj->unk_2E >= 0) {
            parent = grp->obj[obj->unk_2E];
            if (parent->unk_116 < 0) {
                parent->unk_116 = i;
            } else {
                for (j = 0; j < i; j++) {
                    other = grp->obj[j];
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

INCLUDE_ASM("asm/nonmatchings/80230", SprBegin);

void func_80081378_81F78(void) {
    if (D_800FA5F8_FB1F8[D_800FDBE0_FE7E0] != NULL) {
        func_800271D8_27DD8(D_800FA5F8_FB1F8[D_800FDBE0_FE7E0]);
    }
    if (D_800FD8BC_FE4BC != 0) {
        D_800FA5F8_FB1F8[D_800FDBE0_FE7E0] = func_80027138_27D38(D_800FD8BC_FE4BC);
    } else {
        D_800FA5F8_FB1F8[D_800FDBE0_FE7E0] = NULL;
    }
    D_801016C0_1022C0 = D_800FA5F8_FB1F8[D_800FDBE0_FE7E0];
}

INCLUDE_ASM("asm/nonmatchings/80230", SprExec);

INCLUDE_ASM("asm/nonmatchings/80230", SprLayerHook);

INCLUDE_ASM("asm/nonmatchings/80230", SprPosSet);

void func_80081B28_82728(s16 group, s16 member, s16 arg2) {
    HuSprite* sprite = D_800FA1B0_FADB0[group]->obj[member];

    sprite->unk_44 = arg2;
}

INCLUDE_ASM("asm/nonmatchings/80230", TransformPoint);

INCLUDE_ASM("asm/nonmatchings/80230", SprPos3DSet);

INCLUDE_ASM("asm/nonmatchings/80230", SprPosPerspectiveSet);

void SprBankSet(s16 grpIdx, s16 idx, u16 bank) {
    D_800FA1B0_FADB0[grpIdx]->obj[idx]->unk_90 = bank;
}

void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3) {
    HuSprite* sprite_ptr = D_800FA1B0_FADB0[group]->obj[member];

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
    HuSprite* sprite_ptr = D_800FA1B0_FADB0[group]->obj[member];

    sprite_ptr->unk_10 = arg2;
    RestoreAnimState(sprite_ptr);
}

void func_8008225C_82E5C(s16 group, s16 member, s32 arg2) {
    HuSprite* sprite_ptr = D_800FA1B0_FADB0[group]->obj[member];

    sprite_ptr->unk_88 &= 0x7F;
    sprite_ptr->unk_0E = arg2;
    RestoreAnimState(sprite_ptr);
}

void func_800822A8_82EA8(s16 group, s16 member, u16 arg2, s32 arg3) {
    HuSprite* sprite = D_800FA1B0_FADB0[group]->obj[member];

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
    return D_800FA1B0_FADB0[grpIdx]->obj[idx]->unk_88;
}

INCLUDE_ASM("asm/nonmatchings/80230", SprScaleSet);

void SprPrioSet(s16 grpIdx, s16 idx, u16 pri) {
    D_800FA1B0_FADB0[grpIdx]->obj[idx]->prio = pri;
}

void SprRotSet(s16 grpIdx, s16 idx, f32 rot) {
    D_800FA1B0_FADB0[grpIdx]->obj[idx]->unk_58 = rot;
}

void SprAttrReset(s16 grpIdx, s16 idx, s32 flag) {
    HuSprite* obj = D_800FA1B0_FADB0[grpIdx]->obj[idx];

    obj->unk_24 = obj->unk_5C &= ~flag;
}

void SprAttrSet(s16 grpIdx, s16 idx, s32 flag) {
    HuSprite* obj = D_800FA1B0_FADB0[grpIdx]->obj[idx];

    obj->unk_24 = obj->unk_5C |= flag;
}

void func_80082450_83050(s16 grpIdx, s32 idx, s32 r, s32 g, u8 b) {
    HuSprite* obj = D_800FA1B0_FADB0[grpIdx]->obj[(s16)idx];

    obj->unk_28[0] = r;
    obj->unk_28[1] = g;
    obj->unk_28[2] = b;
}

void func_80082488_83088(s16 grpIdx, s16 idx, u16 a) {
    D_800FA1B0_FADB0[grpIdx]->obj[idx]->unk_2C = a;
}

void func_800824B4_830B4(s16 grpIdx, s32 idx, u8 r, u8 g, u8 b, u16 a) {
    HuSprite* obj = D_800FA1B0_FADB0[grpIdx]->obj[(s16)idx];

    obj->unk_28[0] = r;
    obj->unk_28[1] = g;
    obj->unk_28[2] = b;
    obj->unk_2C = a;
}

void func_800824F4_830F4(s16 grpIdx, s16 idx, s16 arg2) {
    D_800FA1B0_FADB0[grpIdx]->obj[idx]->unk_2E = arg2;
}

void func_80082520_83120(s16 grpIdx, s16 idx, u8 arg2, u8 arg3) {
    HuSprite* obj = D_800FA1B0_FADB0[grpIdx]->obj[idx];

    obj->unk_93 = arg2;
    obj->unk_94 = arg3;
}

HuSprite* func_80082550_83150(s16 grpIdx, s16 idx) {
    return D_800FA1B0_FADB0[grpIdx]->obj[idx];
}

void func_80082578_83178(s16 grpIdx, s16 idx, s16 arg2, s16 arg3, u16 arg4, u16 arg5) {
    HuSprite* obj = D_800FA1B0_FADB0[grpIdx]->obj[idx];

    obj->unk_3C = arg2;
    obj->unk_3E = arg3;
    obj->unk_40 = arg4;
    obj->unk_42 = arg5;
}

void func_800825B8_831B8(s16 grpIdx, s16 idx, f32 arg2, f32 arg3) {
    HuSprite* obj = D_800FA1B0_FADB0[grpIdx]->obj[idx];

    obj->unk_30 = arg2;
    obj->unk_34 = arg3;
}

void func_800825E8_831E8(s16 grpIdx, s16 idx, s16 arg2, s16 arg3) {
    HuSprite* obj = D_800FA1B0_FADB0[grpIdx]->obj[idx];

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
                func_800271D8_27DD8(cel->unk04);
                cel++;
            }
        }
        func_800271D8_27DD8(*anim->unk04);
        func_800271D8_27DD8(anim->unk04);
    }
    func_80027340_27F40(anim->unk0C);
    bmp = anim->unk00;
    for (i = 0; i < anim->unk10; i++) {
        func_80027340_27F40((bmp++)->unk00);
    }
    func_800271D8_27DD8(anim->unk00);
    func_800271D8_27DD8(anim);
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

INCLUDE_ASM("asm/nonmatchings/80230", SprAnimRead);

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
    desc = func_80027138_27D38(0x1C);
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
    cel = func_80027138_27D38(desc->unk10 * 0xC);
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
        cel->unk00 = func_80027138_27D38(size / 8);
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
        void* pal = func_80027138_27D38(desc->unk1A * 2);

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

INCLUDE_ASM("asm/nonmatchings/80230", SprAnimBmpPalDirectGet);

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

INCLUDE_ASM("asm/nonmatchings/80230", AnimateSprite);

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
        func_800841B8_84DB8(&sprite->unk_98);
    }
}

INCLUDE_ASM("asm/nonmatchings/80230", func_80083748_84348);

void func_80083B9C_8479C(void) {
    s16 i;

    SprClose();
    SprAnimKillAll();
    func_80084148_84D48();
    for (i = 0; i < 3; i++) {
        if (D_800FA5F8_FB1F8[i] != NULL) {
            func_800271D8_27DD8(D_800FA5F8_FB1F8[i]);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/80230", func_80083C18_84818);

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

INCLUDE_ASM("asm/nonmatchings/80230", func_80083D08_84908);

void func_80083F70_84B70(s16 arg0) {
    HuSprAnmDesc* desc = D_800FCEA0_FDAA0[arg0];
    s32 i;

    for (i = 0; i < desc->unk02; i++) {
        HuSprAnmEntry* group = desc->unk04[i];

        if (group->unk00 != 0) {
            s32 j;

            for (j = 0; j < group->unk02; j++) {
                HuSprAnmEntry* cel = group->unk04[j];

                func_800271D8_27DD8(cel->unk04);
                func_800271D8_27DD8(cel);
            }
            func_800271D8_27DD8(group->unk04);
        }
        func_800271D8_27DD8(group);
    }
    func_800271D8_27DD8(desc->unk04);
    func_800271D8_27DD8(desc->unk0C);
    func_800271D8_27DD8(desc);
    D_800FCEA0_FDAA0[arg0] = NULL;
    D_80101630_102230--;
}

void func_80084098_84C98(s16 group, s16 member, s16 arg2) {
    HuSprite* sprite = D_800FA1B0_FADB0[group]->obj[member];
    s32 i;

    sprite->unk_98 = D_800FCEA0_FDAA0[arg2];
    sprite->unk_FC = 1.0f;
    for (i = 0; i < 0x10; i++) {
        sprite->unk_9C[i] = 0xFFFF;
        sprite->unk_BC[i] = 0;
    }
    sprite->unk_104 = 0;
}

void func_8008411C_84D1C(s16 grpIdx, s16 idx, f32 speed) {
    D_800FA1B0_FADB0[grpIdx]->obj[idx]->unk_FC = speed;
}

void func_80084148_84D48(void) {
    s16 i;

    for (i = 0; i < 256; i++) {
        if (D_800FCEA0_FDAA0[i] != NULL) {
            func_80083F70_84B70(i);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/80230", func_800841B8_84DB8);
