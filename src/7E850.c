#include "common.h"

#include "PR/sptask.h"
#include "engine/siman.h"
#include "game/gamework.h"

/* Save-file EEPROM wrappers (MP1 src/59E80.c), Hudson's nn scheduler (MP1 src/engine/nnsched.c)
   and the SI manager (MP1 src/engine/siman.c). MP1's names are anonymous, so MP2's are kept. */

typedef struct NNScClient {
    struct NNScClient* next;
    OSMesgQueue* msgQ;
    s32 mask;
} NNScClient;

typedef struct {
    OSTask list;
    OSMesgQueue* msgQ;
    OSMesg msg; // bit 0 also requests func_8007C254_7CE54 after the frame
} NNScTask;

#define HOS_PRIORITY_SIMGR 0x5A

typedef s32 (*HuSiFuncVoid)(void);
typedef s32 (*HuSiFunc)(void*);

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

typedef struct {
    u32 unk0[4];
    unkMesg* unkMsg;
} unkMesgWrapper;

extern u8 D_800EB900_EC500;
extern u8 D_800FD420_FE020[0x12];

extern NNScClient* D_800EB910_EC510; // client list
extern NNScTask* D_800ECAD0_ED6D0;   // current audio task
extern NNScTask* D_800ECAD4_ED6D4;   // current graphics task
extern OSMesg D_800ECAD8_ED6D8;      // graphics RSP done message
extern s32 D_800ECB00_ED700;         // graphics task waiting on audio
extern OSMesgQueue D_800ECB08_ED708;
extern OSMesgQueue D_800EB950_EC550; // RSP
extern OSMesgQueue D_800EB988_EC588; // RDP
extern OSMesgQueue D_800F8F40_F9B40; // audio tasks
extern OSMesgQueue D_800F8F68_F9B68; // graphics tasks

extern OSMesg D_800ECB50_ED750;
extern OSMesg D_800ECBD0_ED7D0;
extern OSThread D_800ECC50_ED850;
extern functionListEntry* D_800ED600_EE200;
extern functionListEntry* D_800ED604_EE204;
extern OSMesgQueue D_800FA5E0_FB1E0;

void func_8001B078_1BC78(s32 arg0, UnkEep* arg1, s16 arg2);
void func_80075060_75C60(void);
void func_800751E0_75DE0(void);
void func_80075144_75D44(void);
void func_8007E0C8_7ECC8(u8* buf);
void func_8007E4D4_7F0D4(unkMesgWrapper*, OSMesgQueue*, s32);
s16 func_8007C0BC_7CCBC(u8 arg0, u8 arg1, u8 arg2);
void func_8007C134_7CD34(s16 arg0);
void func_8007C254_7CE54(void);
void func_8007ED44_7F944(void* arg0);

extern OSMesgQueue D_800FD3C8_FDFC8;
void HuPrcVSleep(void);

u16 func_8007DC50_7E850(void) {
    return GetSaveFileChecksum(0, (EEPROM_MAXBLOCKS * EEPROM_BLOCK_SIZE) - 0x10);
}

s32 func_8007DC74_7E874(void) {
    u16 sum;

    sum = 0;
    if (D_800EB900_EC500 != 0) {
        func_8001B078_1BC78(0x1F0, (UnkEep*)&sum, 2);
    }
    return sum;
}


void func_8007DCAC_7E8AC(void) {
    u16 checksumResult;

    checksumResult = func_8007DC50_7E850();
    if (D_800EB900_EC500 != 0) {
        func_8001AFD8_1BBD8((EEPROM_MAXBLOCKS * EEPROM_BLOCK_SIZE) - 0x10, &checksumResult, 2);
    }
}

INCLUDE_ASM("asm/nonmatchings/7E850", func_8007DCE8_7E8E8);

INCLUDE_ASM("asm/nonmatchings/7E850", func_8007DD68_7E968);

void func_8007DF5C_7EB5C(void) {
    if (D_800EB900_EC500 != 0) {
        func_8001AFD8_1BBD8(0, (UnkEep*)&D_800F8C60, 0x80);
    }
    func_8007DCAC_7E8AC();
}

void func_8007DF98_7EB98(void) {
    if (_CheckFlag(0) != 0) {
        _ClearFlag(0x40);
        if (D_800EB900_EC500 != 0) {
            func_8001AFD8_1BBD8(0, (UnkEep*)&D_800F8C60, sizeof(D_800F8C60));
        }
    } else if (D_800EB900_EC500 != 0) {
        func_8001AFD8_1BBD8(0, (UnkEep*)&D_800F8C60, 0x80);
    }
    _ClearFlag(0);
    func_8007DCAC_7E8AC();
}

void func_8007E018_7EC18(void) {
    func_80075060_75C60();
    if (D_800EB900_EC500 != 0) {
        func_8001AFD8_1BBD8(0, (UnkEep*)&D_800F8C60, 0x80);
        func_8001AFD8_1BBD8(0x1BC, (UnkEep*)&D_800FD8A8_FE4A8, sizeof(D_800FD8A8_FE4A8));
    }
    func_8007DCAC_7E8AC();
}

void func_8007E070_7EC70(void) {
    func_800751E0_75DE0();
    if (D_800EB900_EC500 != 0) {
        func_8001AFD8_1BBD8(0, (UnkEep*)&D_800F8C60, 0x80);
        func_8001AFD8_1BBD8(0x1CE, (UnkEep*)D_800FD420_FE020, sizeof(D_800FD420_FE020));
    }
    func_8007DCAC_7E8AC();
}

void func_8007E0C8_7ECC8(u8* buf) {
    if (D_800EB900_EC500 != 0) {
        func_8001B078_1BC78(0x1BC, (UnkEep*)buf, sizeof(D_800FD8A8_FE4A8));
    }
}

void func_8007E0F8_7ECF8(u8* buf) {
    if (D_800EB900_EC500 != 0) {
        func_8001B078_1BC78(0x1CE, (UnkEep*)buf, sizeof(D_800FD420_FE020));
    }
}

void func_8007E128_7ED28(void) {
    func_8007E0C8_7ECC8((u8*)&D_800FD8A8_FE4A8);
    func_80075144_75D44();
}

INCLUDE_ASM("asm/nonmatchings/7E850", func_8007E150_7ED50);

INCLUDE_ASM("asm/nonmatchings/7E850", func_8007E180_7ED80);

void func_8007E224_7EE24(void) {
    if (D_800EB900_EC500 != 0) {
        func_8001AFD8_1BBD8(0, (UnkEep*)&D_800F8C60, sizeof(D_800F8C60));
    }
    func_8007DCAC_7E8AC();
}

INCLUDE_ASM("asm/nonmatchings/7E850", func_8007E260_7EE60);

INCLUDE_ASM("asm/nonmatchings/7E850", func_8007E2A0_7EEA0);

INCLUDE_ASM("asm/nonmatchings/7E850", func_8007E4D4_7F0D4);

void func_8007E560_7F160(NNScClient* c) {
    OSIntMask intMask = osSetIntMask(OS_IM_NONE);
    NNScClient* client = D_800EB910_EC510;
    NNScClient* prev = NULL;

    while (client != NULL) {
        if (client == c) {
            if (prev != NULL) {
                prev->next = client->next;
            } else {
                D_800EB910_EC510 = c->next;
            }
            break;
        }
        prev = client;
        client = client->next;
    }
    osSetIntMask(intMask);
}

void func_8007E5DC_7F1DC(s32 mask) {
    NNScClient* client;

    for (client = D_800EB910_EC510; client != NULL; client = client->next) {
        if (mask & client->mask) {
            osSendMesg(client->msgQ, (OSMesg)mask, OS_MESG_NOBLOCK);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/7E850", func_8007E638_7F238);

void func_8007E754_7F354(void* arg) {
    NNScClient client;
    OSMesgQueue msgQ;
    OSMesg msgBuf[1];
    NNScTask* task = NULL;
    s32 yieldFlag;
    NNScTask* gfxTask;

    osCreateMesgQueue(&msgQ, msgBuf, 1);
    func_8007E4D4_7F0D4((unkMesgWrapper*)&client, &msgQ, 1);
    while (TRUE) {
        osRecvMesg(&msgQ, NULL, OS_MESG_BLOCK);
        if (osRecvMesg(&D_800F8F40_F9B40, (OSMesg*)&task, OS_MESG_NOBLOCK) != 0) {
            continue;
        }
        osWritebackDCacheAll();
        yieldFlag = 0;
        gfxTask = D_800ECAD4_ED6D4;
        if (gfxTask != NULL && D_800ECAD8_ED6D8 == NULL) {
            osSpTaskYield();
            yieldFlag = 2;
            osRecvMesg(&D_800EB950_EC550, NULL, OS_MESG_BLOCK);
            if (osSpTaskYielded(&gfxTask->list)) {
                yieldFlag = 1;
            }
        }
        D_800ECAD0_ED6D0 = task;
        osSpTaskStart(&task->list);
        osRecvMesg(&D_800EB950_EC550, NULL, OS_MESG_BLOCK);
        D_800ECAD0_ED6D0 = NULL;
        if (D_800ECB00_ED700 != 0) {
            osSendMesg(&D_800ECB08_ED708, NULL, OS_MESG_BLOCK);
        }
        switch (yieldFlag) {
            case 1:
                osSpTaskStart(&gfxTask->list);
                break;
            case 2:
                osSendMesg(&D_800EB950_EC550, (OSMesg)0x29B, OS_MESG_BLOCK);
                break;
        }
        osSendMesg(task->msgQ, task->msg, OS_MESG_BLOCK);
    }
}

void func_8007E8D4_7F4D4(void* arg) {
    NNScTask* task = NULL;
    OSIntMask intMask;
    s16 perf0;
    s16 perf1;

    while (TRUE) {
        osRecvMesg(&D_800F8F68_F9B68, (OSMesg*)&task, OS_MESG_BLOCK);
        osWritebackDCacheAll();
        intMask = osSetIntMask(OS_IM_NONE);
        if (D_800ECAD0_ED6D0 != NULL) {
            D_800ECB00_ED700 = 1;
            osSetIntMask(intMask);
            osRecvMesg(&D_800ECB08_ED708, NULL, OS_MESG_BLOCK);
            intMask = osSetIntMask(OS_IM_NONE);
            D_800ECB00_ED700 = 0;
        }
        D_800ECAD4_ED6D4 = task;
        osSpTaskStart(&task->list);
        osSetIntMask(intMask);
        perf0 = func_8007C0BC_7CCBC(0, 0, 0xFF);
        perf1 = func_8007C0BC_7CCBC(0, 0xFF, 0);
        osRecvMesg(&D_800EB950_EC550, &D_800ECAD8_ED6D8, OS_MESG_BLOCK);
        func_8007C134_7CD34(perf0);
        intMask = osSetIntMask(OS_IM_NONE);
        D_800ECAD4_ED6D4 = NULL;
        D_800ECAD8_ED6D8 = NULL;
        osSetIntMask(intMask);
        osRecvMesg(&D_800EB988_EC588, NULL, OS_MESG_BLOCK);
        func_8007C134_7CD34(perf1);
        osSendMesg(task->msgQ, task->msg, OS_MESG_BLOCK);
        if ((s32)task->msg & 1) {
            func_8007C254_7CE54();
        }
    }
}

void func_8007EA50_7F650(void) {
    D_800ED600_EE200 = NULL;
    D_800ED604_EE204 = NULL;
    osCreateMesgQueue(&D_800FA5E0_FB1E0, &D_800ECB50_ED750, 32);
    osSetEventMesg(OS_EVENT_SI, &D_800FA5E0_FB1E0, (OSMesg)32);
    osCreateMesgQueue(&D_800FD3C8_FDFC8, &D_800ECBD0_ED7D0, 32);
    osCreateThread(&D_800ECC50_ED850, 0x14, func_8007ED44_7F944, NULL, &D_800ED600_EE200, HOS_PRIORITY_SIMGR);
    osStartThread(&D_800ECC50_ED850);
}

functionListEntry ** func_8007EAF4_7F6F4(functionListEntry * entry) {
    switch (entry->type) {
    case 0:
        return &D_800ED600_EE200;
    case 1:
        return &D_800ED604_EE204;
    default:
        return NULL;
    }
}

s32 func_8007EB2C_7F72C(functionListEntry* node) {
    functionListEntry* pYoungest;
    functionListEntry* child;

    // Add node as youngest child of a linked list
    pYoungest = (functionListEntry*) func_8007EAF4_7F6F4(node);
    child = pYoungest->child;
    if (child != NULL) {
        pYoungest = child;
        if (pYoungest->child != NULL) {
            do {
                pYoungest = pYoungest->child;
            } while (pYoungest->child != NULL);
        }
    }
    pYoungest->child = node;
    node->child = NULL;
    return 0;
}

void func_8007EB8C_7F78C(functionListEntry * entry, s16 type, void * func) {
    OSMesg msgBuffer;
    OSMesgQueue mq;
    unkMesg msgOut;

    msgOut.func = (HuSiFunc)&func_8007EB2C_7F72C;
    msgOut.arg = entry;
    msgOut.recvQueue = &mq;
    entry->func = func;
    entry->type = type;

    osCreateMesgQueue(&mq, &msgBuffer, OS_MESG_BLOCK);
    osSendMesg(&D_800FD3C8_FDFC8, &msgOut, OS_MESG_BLOCK);
    osRecvMesg(&mq, NULL, 1);
}

s32 func_8007EBFC_7F7FC(functionListEntry* arg0) {
    functionListEntry* var_v0;
    functionListEntry* var_v1;
    functionListEntry** root;

    root = func_8007EAF4_7F6F4(arg0);
    var_v0 = *root;
    var_v1 = NULL;
    // Search until the end of the list
    while (var_v0 != NULL) {
        // Check if the node is the one we're looking for
        if (var_v0 == arg0) {
            // If this wasn't at the start of the list (previous node is nonnull), remove it from the list
            if (var_v1 != NULL) {
                var_v1->child = arg0->child;
            } else {
                // Otherwise set the root of the list to the next node
                *root = arg0->child;
            }
            return 0;
        }
        var_v1 = var_v0;        
        var_v0 = var_v0->child;
    }
    return 0;
}

void func_8007EC68_7F868(void *entry) {
    OSMesg msgBuffer;
    OSMesgQueue mq;
    unkMesg msgOut;

    msgOut.func = (HuSiFunc)&func_8007EBFC_7F7FC;
    msgOut.arg = entry;
    msgOut.recvQueue = &mq;
    
    osCreateMesgQueue(&mq, &msgBuffer, 1);
    osSendMesg(&D_800FD3C8_FDFC8, &msgOut, OS_MESG_BLOCK);
    osRecvMesg(&mq, NULL, OS_MESG_BLOCK);
}

void func_8007ECD0_7F8D0(s16 type) {
    functionListEntry* funcList;

    funcList = NULL;
    switch (type) {
    case 0:
        funcList = D_800ED600_EE200;
        break;
    case 1:
        funcList = D_800ED604_EE204;
        break;
    }
    if (funcList != NULL) {
        do {
            funcList->func();
            funcList = funcList->child;
        } while (funcList != 0);
    }
}

void func_8007ED44_7F944(void* arg0) {
    unkMesgWrapper msgWrapper;

    func_8007E4D4_7F0D4(&msgWrapper, &D_800FD3C8_FDFC8, 3);

    while (TRUE) {
        osRecvMesg(&D_800FD3C8_FDFC8, (OSMesg*) &msgWrapper.unkMsg, OS_MESG_BLOCK);       
        switch ((s32)msgWrapper.unkMsg) {
            case 1:
                func_8007ECD0_7F8D0((s16) 0);
                break;
            case 2:
                func_8007ECD0_7F8D0((s16) 1);
                break;
            default:
            {
                unkMesg* recvdMsg;
                recvdMsg = msgWrapper.unkMsg;
                recvdMsg->ret = recvdMsg->func(recvdMsg->arg);
                if (recvdMsg->recvQueue != NULL) {
                    osSendMesg(recvdMsg->recvQueue, NULL, OS_MESG_BLOCK);
                }
            }
        }
    }
}

s32 func_8007EE0C_7FA0C(unkfunc_8007EE0C* arg0, void* GetEepType, char* arg2, s32 arg3) {
    OSMesgQueue sp10;
    OSMesg sp28;

    arg0->GetEepTypeFunc = GetEepType;
    arg0->unk4 = (void*)arg2;
    arg0->mesgQueue = &sp10;
    osCreateMesgQueue(&sp10, &sp28, 1);
    osSendMesg(&D_800FD3C8_FDFC8, arg0, 1);
    switch (arg3) {
    case 0:
        arg0->unk8 = 0;
        break;
    case 1:
        osRecvMesg(&sp10, 0, 1);
        break;
    case 2:
        while (osRecvMesg(&sp10, 0, 0) != 0) {
            HuPrcVSleep(); //sleep 1 frame
        }
        break;
    }
    return arg0->unk8;
}
