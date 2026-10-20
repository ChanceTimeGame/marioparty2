#include "common.h"
#include "game/board.h"

/* Object manager. omObj/omPrc helpers, groups and the debug-key setup from MP1 src/objmain.c
   (func_80076BD0_777D0 from MP3 src/objmain.c); the near/unreferenced functions stay in asm. */

void func_80079338_79F38(s8);
void func_8007935C_79F5C(s16 arg0, s16 arg1, s16 arg2);
void func_8001A4C0_1B0C0(void);
void func_80023124_23D24(void);
void func_8002864C_2924C(void);
void func_80029708_2A308(s32);
void func_8002F1A4_2FDA4(void);
void func_80069698_6A298(void);
void omDestroyObjMan(void);

/* Object and process tables (MP1 src/objmain.c / MP3 src/objmain.c names in comments). */
typedef struct omGrpData {
    /* 0x00 */ u16 next;
    /* 0x02 */ u16 max;
    /* 0x04 */ u16 num;
    /* 0x08 */ u16* nextIdx;
    /* 0x0C */ omObjData** obj;
} omGrpData; // sizeof 0x10

typedef struct unkProcessStruct {
    /* 0x00 */ u16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ Process* processInstance;
    /* 0x08 */ void (*unk8)();
} unkProcessStruct; // sizeof 0xC

extern omObjData* D_800CD420_CE020;          /* omobjall */
extern s16 D_800CD424_CE024;                 /* process slots */
extern s16 D_800CD426_CE026;                 /* processes in use */
extern s16 D_800CD428_CE028;                 /* next free process slot */
extern unkProcessStruct* D_800CD42C_CE02C;   /* process table */
extern s16 D_800F8FD4_F9BD4;                 /* omobjlast */
extern s16 D_800F92B0_F9EB0;                 /* object slots */
extern s16 D_800F92E4_F9EE4;                 /* omnumobjs */
extern omGrpData D_800F9400_FA000[10];       /* omgroup */
extern omObjData* D_800FDD98_FE998;          /* omDBGSysKeyObj */
extern u8 D_800FD7F5_FE3F5;
extern s16 D_80101644_102244;                /* omobjfirst */
extern s16 D_801027DA_1033DA;                /* omnextidx */

void HuMemMemoryFreeTemp(void* ptr);
void* HuMemMemoryAllocTemp(u32 size);
void HuMemFree(void* ptr); /* HuMemFree */
void func_800884AC_890AC(s16);
void func_80078A08_79608(omObjData*); /* omSystemKeyCheck */
void omInsertObj(omObjData* obj);
void func_80076D10_77910(omObjData* obj);
void omDestroyPrcObj(void);
void omResetStatBit(omObjData* obj, s32 bit);
void omPrcResetStatBit(Process* process, s32 bit);
void func_80076CA0_778A0(u16 grp, omObjData* obj); /* omAddMember */
void func_80027274_27E74(s32);
extern s16 D_801011FC_101DFC;
extern f32 D_80101078_101C78;
extern f32 D_800F8410_F9010;
extern f32 D_800F92E8_F9EE8[4];
extern f32 D_80100018_100C18[4];
extern void* D_801026F0_1032F0;

/* MP3 omInitObjMan */
void omInitObjMan(s32 numOfObjs, s32 numOfPrcs) {
    s16 prcCount;
    s32 i;
    omObjData* obj;
    unkProcessStruct* prcInfo;

    D_800F92B0_F9EB0 = numOfObjs + 1;
    D_800F92E4_F9EE4 = 0;
    D_801027DA_1033DA = 0;
    D_800F8FD4_F9BD4 = -1;
    D_80101644_102244 = -1;
    D_800FDD98_FE998 = NULL;
    D_801011FC_101DFC = 0;
    D_80102720_103320 = 0;

    if (D_800CD420_CE020 != NULL) {
        HuMemMemoryFreeTemp(D_800CD420_CE020);
    }

    D_800CD420_CE020 = HuMemMemoryAllocTemp(D_800F92B0_F9EB0 * sizeof(omObjData));

    for (i = 0; i < D_800F92B0_F9EB0; ++i) {
        obj = &D_800CD420_CE020[i];
        obj->stat = 1;
        obj->next = -1;
        obj->prev = -1;
        obj->prio = -1;
        obj->unk_10 = 0;
        obj->rot.x = obj->rot.y = obj->rot.z = 0.0f;
        obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
        obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
        obj->motion = NULL;
        obj->model = NULL;
        obj->unk_50 = NULL;
        obj->func_ptr = NULL;
        obj->next_idx = i + 1;
        obj->mtncnt = 0;
        obj->motion = NULL;
    }

    for (i = 0; i < 10; ++i) {
        D_800F9400_FA000[i].max = 0;
        D_800F9400_FA000[i].num = 0;
        D_800F9400_FA000[i].next = 0;
        D_800F9400_FA000[i].obj = NULL;
        D_800F9400_FA000[i].nextIdx = NULL;
    }

    prcCount = numOfPrcs + 2;
    D_800CD424_CE024 = prcCount;
    D_800CD426_CE026 = 0;
    D_800CD428_CE028 = 0;
    D_800CD42C_CE02C = HuMemMemoryAllocTemp(prcCount * sizeof(unkProcessStruct));

    for (i = 0; i < D_800CD424_CE024; ++i) {
        prcInfo = &D_800CD42C_CE02C[i];
        prcInfo->unk0 = 1;
        prcInfo->unk2 = i + 1;
        prcInfo->processInstance = NULL;
        prcInfo->unk8 = NULL;
    }

    D_80101078_101C78 = 20000.0f;
    D_800F8410_F9010 = 10000.0f;

    for (i = 0; i < 4; ++i) {
        D_800F92E8_F9EE8[i] = 20000.0f;
        D_80100018_100C18[i] = 10000.0f;
    }

    D_801026F0_1032F0 = NULL;
    D_800F93A0_F9FA0 = 90;
}

/* MP1 omDestroyObjMan; MP2 also clears the object count */
void omDestroyObjMan(void) {
    omObjData* obj;
    unkProcessStruct* prc;
    s32 i;

    D_800F8FD4_F9BD4 = -1;
    for (i = 0; i < D_800F92B0_F9EB0; i++) {
        obj = &D_800CD420_CE020[i];
        if (obj->stat != 1) {
            if (obj->model != NULL) {
                HuMemMemoryFreeTemp(obj->model);
            }
            if (obj->motion != NULL) {
                HuMemMemoryFreeTemp(obj->motion);
            }
            if (obj->unk_50 != NULL) {
                HuMemFree(obj->unk_50);
            }
        }
    }
    HuMemMemoryFreeTemp(D_800CD420_CE020);
    D_800CD420_CE020 = NULL;
    D_800F92B0_F9EB0 = 0;
    for (i = 0; i < 10; i++) {
        if (D_800F9400_FA000[i].max != 0) {
            if (D_800F9400_FA000[i].obj != NULL) {
                HuMemMemoryFreeTemp(D_800F9400_FA000[i].obj);
                D_800F9400_FA000[i].obj = NULL;
            }
            if (D_800F9400_FA000[i].nextIdx != NULL) {
                HuMemMemoryFreeTemp(D_800F9400_FA000[i].nextIdx);
                D_800F9400_FA000[i].nextIdx = NULL;
            }
            D_800F9400_FA000[i].max = 0;
        }
    }
    for (i = 0; i < D_800CD424_CE024; i++) {
        prc = &D_800CD42C_CE02C[i];
        if (prc->unk0 != 1) {
            HuPrcDestructorSet2(prc->processInstance, prc->unk8);
            HuPrcKill(prc->processInstance);
        }
    }
    D_800CD424_CE024 = 0;
    D_800CD426_CE026 = 0;
    HuMemMemoryFreeTemp(D_800CD42C_CE02C);
    D_800CD42C_CE02C = NULL;
    func_80027274_27E74(0x7918);
    D_801026F0_1032F0 = NULL;
}

/* MP3 omAddObj */
omObjData* omAddObj(s16 prio, u16 mdlcnt, u16 mtncnt, s16 group, void* func) {
    omObjData* object;
    s32 i;

    if (D_800F92E4_F9EE4 == D_800F92B0_F9EB0) {
        return NULL;
    }

    object = &D_800CD420_CE020[D_801027DA_1033DA];
    object->next_idx_alloc = D_801027DA_1033DA;
    object->prio = prio;

    omInsertObj(object);

    if (mdlcnt != 0) {
        object->model = HuMemMemoryAllocTemp(mdlcnt * sizeof(s16));
        object->mdlcnt = mdlcnt;
        for (i = 0; i < mdlcnt; ++i) {
            object->model[i] = -1;
        }
    } else {
        object->model = NULL;
        object->mdlcnt = 0;
    }

    if (mtncnt != 0) {
        object->motion = HuMemMemoryAllocTemp(mtncnt * sizeof(s16));
        object->mtncnt = mtncnt;
    } else {
        object->motion = NULL;
        object->mtncnt = 0;
    }

    if (group >= 0) {
        func_80076CA0_778A0(group, object);
    } else {
        object->group = group;
        object->group_idx = 0;
    }

    object->stat = 4;
    object->unk_10 = 0;
    object->func_ptr = func;
    object->work[0] = object->work[1] = object->work[2] = object->work[3] = 0;
    D_801027DA_1033DA = object->next_idx;
    ++D_800F92E4_F9EE4;

    return object;
}

void omSetObjPrio(omObjData* obj, s16 prio) {
    obj->prio = prio;
    if (D_800F8FD4_F9BD4 != D_80101644_102244) {
        if (obj->next >= 0) {
            D_800CD420_CE020[obj->next].prev = obj->prev;
        }
        if (obj->prev >= 0) {
            D_800CD420_CE020[obj->prev].next = obj->next;
        }
        if (obj->prev < 0) {
            D_80101644_102244 = D_800CD420_CE020[obj->next].next_idx_alloc;
        }
        if (obj->next < 0) {
            D_800F8FD4_F9BD4 = D_800CD420_CE020[obj->prev].next_idx_alloc;
        }
        omInsertObj(obj);
    }
}

void omInsertObj(omObjData* obj) {
    s16 idx = obj->next_idx_alloc;
    s16 prio = obj->prio;
    s16 i;
    s16 last;
    omObjData* o;

    if (D_80101644_102244 == -1) {
        obj->next = obj->prev = -1;
        D_80101644_102244 = idx;
    } else {
        i = D_80101644_102244;
        while (i != -1) {
            o = &D_800CD420_CE020[i];
            if (prio >= o->prio) {
                break;
            }
            last = i;
            i = o->next;
        }
        if (i != -1) {
            obj->prev = o->prev;
            obj->next = i;
            if (o->prev != -1) {
                D_800CD420_CE020[o->prev].next = idx;
            } else {
                D_80101644_102244 = idx;
            }
            o->prev = idx;
            return;
        }
        obj->next = -1;
        obj->prev = last;
        o->next = idx;
    }
    D_800F8FD4_F9BD4 = idx;
}

void omDelObj(omObjData* obj) {
    s16 idx = obj->next_idx_alloc;

    if (D_800F92E4_F9EE4 != 0) {
        D_800F92E4_F9EE4--;
        if (obj->group >= 0) {
            func_80076D10_77910(obj);
        }
        if (obj->motion != NULL) {
            HuMemMemoryFreeTemp(obj->motion);
            obj->motion = NULL;
        }
        if (obj->model != NULL) {
            HuMemMemoryFreeTemp(obj->model);
            obj->model = NULL;
        }
        if (obj->unk_50 != NULL) {
            HuMemFree(obj->unk_50);
            obj->unk_50 = NULL;
        }
        obj->stat = 1;
        if (obj->next >= 0) {
            D_800CD420_CE020[obj->next].prev = obj->prev;
        }
        if (obj->prev >= 0) {
            D_800CD420_CE020[obj->prev].next = obj->next;
        }
        if (obj->prev < 0) {
            D_80101644_102244 = D_800CD420_CE020[obj->next].next_idx_alloc;
        }
        if (obj->next < 0) {
            D_800F8FD4_F9BD4 = D_800CD420_CE020[obj->prev].next_idx_alloc;
        }
        obj->next_idx = D_801027DA_1033DA;
        D_801027DA_1033DA = idx;
    }
}

INCLUDE_ASM("asm/nonmatchings/objmain", omSetStat);

INCLUDE_ASM("asm/nonmatchings/objmain", omSetStatBit);

INCLUDE_ASM("asm/nonmatchings/objmain", omResetStatBit);

void omPrcSetStat(Process* process, u16 stat) {
    D_800CD42C_CE02C[process->dtor_idx].unk0 = stat;
}

void omPrcSetStatBit(Process* process, s32 bit) {
    D_800CD42C_CE02C[process->dtor_idx].unk0 |= bit;
}

void omPrcResetStatBit(Process* process, s32 bit) {
    D_800CD42C_CE02C[process->dtor_idx].unk0 &= ~bit;
}

INCLUDE_ASM("asm/nonmatchings/objmain", omSetTra);

INCLUDE_ASM("asm/nonmatchings/objmain", omSetRot);

INCLUDE_ASM("asm/nonmatchings/objmain", omSetSca);

/* MP3 func_80047C0C_4880C: (re)allocate group grp's member table */
void func_80076BD0_777D0(u16 grp, u16 max) {
    omGrpData* g = &D_800F9400_FA000[grp];
    s32 i;

    if (g->obj != NULL) {
        HuMemMemoryFreeTemp(g->obj);
    }
    if (g->nextIdx != NULL) {
        HuMemMemoryFreeTemp(g->nextIdx);
    }
    g->next = 0;
    g->max = max;
    g->num = 0;
    g->obj = HuMemMemoryAllocTemp(max * sizeof(omObjData*));
    g->nextIdx = HuMemMemoryAllocTemp(max * sizeof(u16));
    for (i = 0; i < max; i++) {
        g->obj[i] = NULL;
        g->nextIdx[i] = i + 1;
    }
}

void func_80076CA0_778A0(u16 grp, omObjData* obj) {
    omGrpData* g = &D_800F9400_FA000[grp];

    if (g->num != g->max) {
        obj->group = grp;
        obj->group_idx = g->next;
        g->obj[g->next] = obj;
        g->next = g->nextIdx[g->next];
        g->num++;
    }
}

void func_80076D10_77910(omObjData* obj) {
    omGrpData* g;

    if (obj->group != -1) {
        g = &D_800F9400_FA000[obj->group];
        g->obj[(u16)obj->group_idx] = NULL;
        g->nextIdx[(u16)obj->group_idx] = g->next;
        g->next = obj->group_idx;
        obj->group = -1;
        g->num--;
    }
}

omObjData** func_80076D80_77980(s16 grp) {
    return D_800F9400_FA000[grp].obj;
}

omObjData* func_80076D98_77998(s16 grp, u16 idx) {
    return D_800F9400_FA000[grp].obj[idx];
}

void func_80076DC0_779C0(s16 grp, s32 bit) {
    omGrpData* g = &D_800F9400_FA000[grp];
    s32 i;
    omObjData* obj;

    for (i = 0; i < g->max; i++) {
        obj = g->obj[i];
        if (obj != NULL) {
            obj->unk_10 |= bit;
        }
    }
}

void func_80076E20_77A20(s16 grp, u16 idx, s32 bit) {
    omObjData* obj = D_800F9400_FA000[grp].obj[idx];
    obj->unk_10 |= bit;
}

INCLUDE_ASM("asm/nonmatchings/objmain", func_80076E54_77A54);

Process* omAddPrcObj(void* func, u16 priority, s32 stack_size, s32 extra_data_size) {
    unkProcessStruct* temp_s0;
    Process* process;
    s16 temp_s1;

    if (D_800CD426_CE026 != D_800CD424_CE024) {
        temp_s1 = D_800CD428_CE028;
        temp_s0 = &D_800CD42C_CE02C[D_800CD428_CE028];
        temp_s0->unk0 = 4;
        D_800CD428_CE028 = temp_s0->unk2;
        process = HuPrcCreate(func, priority, stack_size, extra_data_size);
        temp_s0->processInstance = process;
        process->dtor_idx = temp_s1;
        HuPrcDestructorSet2(temp_s0->processInstance, &omDestroyPrcObj);
        temp_s0->unk8 = 0;
        D_800CD426_CE026++;
        return temp_s0->processInstance;
    } else {
        return NULL;
    }
}

Process* func_80076F14_77B14(process_func arg0, u16 arg1, s32 arg2, s32 arg3, Process* arg4) {
    unkProcessStruct* temp_s0;
    Process* process;
    s16 temp_s1;

    if (D_800CD426_CE026 != D_800CD424_CE024) {
        temp_s1 = D_800CD428_CE028;
        temp_s0 = &D_800CD42C_CE02C[D_800CD428_CE028];
        temp_s0->unk0 = 4;
        D_800CD428_CE028 = temp_s0->unk2;
        process = HuPrcChildCreate(arg0, arg1, arg2, arg3, arg4);
        temp_s0->processInstance = process;
        process->dtor_idx = temp_s1;
        HuPrcDestructorSet2(temp_s0->processInstance, omDestroyPrcObj);
        temp_s0->unk8 = 0;
        D_800CD426_CE026++;
        return temp_s0->processInstance;
    }

    return NULL;
}

s32 omDelPrcObj(void* arg0) {
    if (arg0 != NULL) {
        return HuPrcKill(arg0);
    }

    if (HuPrcKill(HuPrcCurrentGet()) == 0) {
        HuPrcVSleep();
    }

    return -1;
}

void omDestroyPrcObj(void) {
    Process* temp_s1 = HuPrcCurrentGet();
    unkProcessStruct* temp_s0 = &D_800CD42C_CE02C[temp_s1->dtor_idx];

    if (temp_s0->unk8 != 0) {
        (temp_s0->unk8)();
    }

    temp_s0->unk0 = 1;
    temp_s0->unk2 = D_800CD428_CE028;
    D_800CD428_CE028 = temp_s1->dtor_idx;
    D_800CD426_CE026--;
}

void omPrcSetDestructor(s32 arg0, void (*arg1)()) {
    unkProcessStruct* temp = &D_800CD42C_CE02C[HuPrcCurrentGet()->dtor_idx];
    temp->unk8 = arg1;
}

s32 omOvlCallEx(s32 overlayID, s16 event, s16 stat) {
    omOvlHisData* history;
    s32 result;

    if (omovlhisidx < ARRAY_COUNT(omovlhis)) {
        history = &omovlhis[++omovlhisidx];
        history->overlayID = overlayID;
        history->event = event;
        history->stat = stat;
        omOvlGotoEx(overlayID, event, stat);
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

s32 omOvlReturnEx(s16 level) {
    omovlhisidx -= level;
    
    if (omovlhisidx < 0) {
        omovlhisidx = 0;
        omOvlGotoEx(omovlhis[0].overlayID, omovlhis[0].event, omovlhis[0].stat);
        return 0;
    }
    omOvlGotoEx(omovlhis[omovlhisidx].overlayID, omovlhis[omovlhisidx].event, omovlhis[omovlhisidx].stat);
    return 1;
}

void omOvlGotoEx(s32 arg0, s16 arg1, u16 arg2) {
    u8 var_a0_3;
    u8 var_v1_2;
    s32 var_v0_3;

    if ((D_800FA63C_FB23C != 0x73) && (D_800FA63C_FB23C != 0)) {
        if ((D_800FA63C_FB23C != 0x5F) && (D_800FA63C_FB23C != 0x6F) && (D_800FA63C_FB23C != 0x70)) {
            D_800CD408_CE008 = D_800FA63C_FB23C;
        }
        if ((D_800FA63C_FB23C != 0x73) && (D_800FA63C_FB23C != 0)) {
            D_800CD404_CE004 = D_800FA63E_FB23E;
        }
    }

    D_800CD41C_CE01C = 1;
    D_800FA63C_FB23C = arg0;
    D_800CD414_CE014 = arg1;
    D_800CD416_CE016 = arg2;
    D_800FCE84_FDA84 = 0;

    if (arg2 & 0x40 && D_800F92B2_F9EB2 != 2) {
        func_80079338_79F38(2);
    } else if (arg2 & 0x80 && (D_800F92B2_F9EB2 != 3)) {
        func_80079338_79F38(3);
    }

    if ((arg2 & 1) && (D_800FFDF2_1009F2 != 0x1000 || (D_800F9562_FA162 != 0x2004) || (D_80102702_103302 != 0x180))) {
        func_8007935C_79F5C(0x1000, 0x2004, 0x180);
    } else if ((arg2 & 2) && (D_800FFDF2_1009F2 != 0x800 || (D_800F9562_FA162 != 0x1000) || (D_80102702_103302 != 0x180))) {
        func_8007935C_79F5C(0x800, 0x1000, 0x180);
    } else if (arg2 & 4 && (D_800FFDF2_1009F2 != 0x1000 || (D_800F9562_FA162 != 0x2004) || (D_80102702_103302 != 0x180))) {
        func_8007935C_79F5C(0x1000, 0x2004, 0x180);
    }

    if (!(arg2 & 0x2000)) {
        if (arg2 & 2) {
            var_a0_3 = D_800CD3F0_CDFF0[GwSystem.current_board_index][0];
            var_v1_2 = D_800CD3F0_CDFF0[GwSystem.current_board_index][1];
            var_v0_3 = arg2 & 0x100;
        } else if (arg2 & 4) {
            var_a0_3 = 1;
            if ((arg0 == 0x5F) || (arg0 == 0x6F)) {
                var_v1_2 = 0x14;
                var_v0_3 = arg2 & 0x100;
            } else {
                var_a0_3 = D_800CD360_CDF60[GwSystem.chosenMinigameIndex - 1][0];
                var_v1_2 = D_800CD360_CDF60[GwSystem.chosenMinigameIndex - 1][1];
                var_v0_3 = arg2 & 0x100;
            }
        } else {
            var_a0_3 = 1;
            var_v1_2 = 0x14;
            var_v0_3 = arg2 & 0x100;
        }

        if (var_v0_3) {
            var_a0_3 = 1;
            var_v1_2 = 0x14;
        } else if (arg2 & 0x200) {
            var_a0_3 = 2;
            var_v1_2 = 0x14;
        } else if (arg2 & 0x400) {
            var_a0_3 = 3;
            var_v1_2 = 0x14;
        } else if (arg2 & 0x800) {
            var_a0_3 = 4;
            var_v1_2 = 0x14;
        } else if (arg2 & 0x1000) {
            var_a0_3 = 5;
            var_v1_2 = 0x14;
        }

        D_800CD434_CE034 = var_v1_2;
        D_800CD528_CE128 = var_a0_3 & 0xFF;
    }

    if (
    (arg0 == 0x5A) || 
    (arg0 == 0x5B) || 
    (arg0 == 0x5C) || 
    (arg0 == 0x5D) || 
    (arg0 == 0x62) || 
    (arg0 == 0x58))
    {
        D_800CD52C_CE12C = 1;
        return;
    }
    D_800CD52C_CE12C = 0;
}

void omOvlHisChg(s16 arg0, s32 overlay, s16 event, s16 stat) {
    s32 ovlhisIndex = omovlhisidx - arg0;
    omOvlHisData* history;

    if (ovlhisIndex >= 0) {
        history = &omovlhis[ovlhisIndex];
        history->overlayID = overlay;
        history->event = event;
        history->stat = stat;
    }
}

void omOvlKill(void) {
    D_800CD412_CE012 = 4;
    D_800E2130_E2D30 = D_800F93A0_F9FA0;
    func_80069698_6A298();
    func_8002864C_2924C();
    func_8002F1A4_2FDA4();
    omDestroyObjMan();
    func_8001A4C0_1B0C0();
    func_80023124_23D24();
    func_80029708_2A308(1);
}

INCLUDE_ASM("asm/nonmatchings/objmain", omMain);

/* omSystemKeyCheckSetup */
void func_80077EF0_78AF0(void) {
    omObjData* obj;

    obj = D_800FDD98_FE998 = omAddObj(0x7FD9, 0, 0, -1, func_80078A08_79608);
    omSetStatBit(obj, 0xA0);
    obj->work[0] = 0;
    obj->work[1] = 0;
    obj->work[2] = 0;
}

INCLUDE_ASM("asm/nonmatchings/objmain", func_80077F50_78B50);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80078A08_79608);

u16 func_80078EA8_79AA8(void) {
    if (D_800FDD98_FE998 == NULL) {
        return 0;
    }
    return D_800FDD98_FE998->work[0] & 1;
}

INCLUDE_ASM("asm/nonmatchings/objmain", func_80078EC8_79AC8);

void func_80078FF8_79BF8(void) {
    s32 i;

    D_80102720_103320 = 0;
    for (i = 0; i < D_800F92B0_F9EB0; i++) {
        if (!(D_800CD420_CE020[i].stat & 0x81)) {
            omResetStatBit(&D_800CD420_CE020[i], 0x40);
        }
    }
    for (i = 0; i < D_800CD424_CE024; i++) {
        if (!(D_800CD42C_CE02C[i].unk0 & 0x81)) {
            omPrcResetStatBit(D_800CD42C_CE02C[i].processInstance, 0x40);
            if (!(D_800CD42C_CE02C[i].unk0 & 0x10)) {
                D_800CD42C_CE02C[i].processInstance->stat &= ~1;
            }
        }
    }
    for (i = 0; i < 4; i++) {
        func_800884AC_890AC(i);
    }
}

void func_8007B9B8_7C5B8(void);
void func_8007BA44_7C644(void);
s16 func_8001A2F8_1AEF8(s32 arg0);
s16 func_8001AAAC_1B6AC(s16 arg0, u16 arg1, u16 arg2);
void func_8001A6BC_1B2BC(u16 spriteId, s16 arg1);
void func_8001A788_1B388(u16 spriteId, s32 arg1);
void espPosSet(u16 spriteId, s16 x, s16 y);
void func_80079294_79E94(omObjData* obj);
extern u8 D_80102708_103308;
extern s16 D_800E2132_E2D32;
extern u16 D_800E2134_E2D34;
extern s16 D_800E2136_E2D36;
extern s16 D_80101650_102250;

/* MP3 func_8004A208_4AE08 */
void func_80079128_79D28(void) {
    func_800727F0_733F0();
    if (D_800CD416_CE016 & 0x10) {
        func_80077EF0_78AF0();
        if (D_800CD416_CE016 & 4) {
            D_80102708_103308 = 1;
        }
    }
    if (D_800CD416_CE016 & 0x20) {
        func_8007B9B8_7C5B8();
    }
    func_8007BA44_7C644();
    if (_CheckFlag(0x15) != 0) {
        D_800E2132_E2D32 = func_8001A2F8_1AEF8(0x900FB);
        D_800E2134_E2D34 = func_8001AAAC_1B6AC(D_800E2132_E2D32, 0, 1);
        func_8001A6BC_1B2BC(D_800E2134_E2D34, 0x100);
        func_8001A788_1B388(D_800E2134_E2D34, 1);
        switch ((u32)D_800FA63C_FB23C) {
            case 0x1A:
                D_80101650_102250 = 0xC4;
                break;
            case 0x11:
            case 0x18:
                D_80101650_102250 = 0x18;
                break;
            default:
                D_80101650_102250 = 0xD8;
                break;
        }
        espPosSet(D_800E2134_E2D34, 0xA0, D_80101650_102250);
        D_800E2136_E2D36 = 0;
        omSetStatBit(omAddObj(10, 0, 0, -1, func_80079294_79E94), 0xA0);
    }
}

INCLUDE_ASM("asm/nonmatchings/objmain", func_80079294_79E94);

void func_80079338_79F38(s8 arg0) {
    D_800CD430_CE030 = 1;
    D_800FCE84_FDA84 = 4;
    D_800FD7F5_FE3F5 = arg0;
}

void func_8007935C_79F5C(s16 arg0, s16 arg1, s16 arg2) {
    D_800FFDF2_1009F2 = arg0;
    D_800F9562_FA162 = arg1;
    D_80102702_103302 = arg2;
    D_800CD430_CE030 = 1;
    D_800FCE84_FDA84 = 4;
}
