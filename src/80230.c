#include "common.h"

#include "game/malloc.h"
#include "game/sprite.h"

/* Sprite manager (MP1 src/65770.c, MP3 src/sprman.c). MP2's sprite object has MP3's layout (0x208
   bytes) and its group MP1's (members at 0xC); MP1's code is written against those layouts here. */

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
extern s8 D_800FDC9C_FE89C;                    /* MP3 HmfPauseF */

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
void func_800841B8_84DB8(HuSprAnmDesc** arg0);
void func_80083F70_84B70(s16 arg0);
void func_80084148_84D48(void);

INCLUDE_ASM("asm/nonmatchings/80230", func_8007F630_80230);

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

INCLUDE_ASM("asm/nonmatchings/80230", SprBegin);

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

INCLUDE_ASM("asm/nonmatchings/80230", SprExec);

INCLUDE_ASM("asm/nonmatchings/80230", SprLayerHook);

INCLUDE_ASM("asm/nonmatchings/80230", SprPosSet);

void func_80081B28_82728(s16 group, s16 member, s16 arg2) {
    HuSprite* sprite = HuSprGrpData[group]->members[member];

    sprite->unk_44 = arg2;
}

INCLUDE_ASM("asm/nonmatchings/80230", TransformPoint);

INCLUDE_ASM("asm/nonmatchings/80230", SprPos3DSet);

INCLUDE_ASM("asm/nonmatchings/80230", SprPosPerspectiveSet);

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

INCLUDE_ASM("asm/nonmatchings/80230", SprScaleSet);

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
            HuMemFree(D_800FA5F8_FB1F8[i]);
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
    sprite->unk_104 = 0;
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

INCLUDE_ASM("asm/nonmatchings/80230", func_800841B8_84DB8);
