#include "common.h"

/* Game loop processes (MP1 src/engine/gameman.c, MP3 src/gameman.c), the graphics swap chain
   (MP3 src/graphics.c, MP1 src/engine/graphics.c) and the HMF model loader (MP3 src/hmfload.c,
   MP1 src/1B800.c). */

typedef struct {
    s32 unk00;
    u16 unk04;
    s32 unk08;
    OSMesgQueue *unk0C;
    s32 unk10; // OSMesg to send to unk0C
} graphicsMessage;

typedef struct combinedStruct {
    /* 0x00 */ OSTask task;
    /* 0x40 */ OSMesgQueue* mtqueue;
    /* 0x44 */ void* fullqueue;
} swapChainTaskQueue; // size 0x48

typedef struct {
    s32 unk00;
    OSMesgQueue *unk04;
    s32 unk08;
} unkSchedStruct;

typedef struct {
    u8 unk00[0x20];
} unkGraphicsMessage2;

extern void *osViGetCurrentFramebuffer(void);
extern void *osViGetNextFramebuffer(void);
extern void osViSwapBuffer(void *);
extern void osViBlack(u8);
extern void osViSetYScale(f32);

void func_8001D114_1DD14(void**, u16, u16);
void func_8001D13C_1DD3C(u64**);
void func_8001D178_1DD78(s32*);
void func_8001D184_1DD84(u32);
void func_8001CCDC_1D8DC(void*);
void* func_8001CC50_1D850(void);
graphicsMessage* func_8001D000_1DC00(void);
void func_8007E4D4_7F0D4(unkSchedStruct*, OSMesgQueue*, s32);
void func_8007C218_7CE18();
void func_8007C244_7CE44();

extern swapChainTaskQueue D_800DEDC0_DF9C0;
extern OSThread D_800F9058_F9C58;
extern u8 D_800DB5C0_DC1C0[];
extern graphicsMessage D_800F8720_F9320[0x40];
extern s16 D_800F842A_F902A;
extern void **D_800DEF58_DFB58;
extern u16 D_800DEF5C_DFB5C;
extern u16 D_800DEF5E_DFB5E;
extern u64 *D_800F8430_F9030;
extern u64 *D_800FA638_FB238;
extern u64 *D_800FC98C_FD58C;
extern u64 *D_800FC730_FD330;
extern Gfx D_800F8F30_F9B30[];
extern s32 D_800F8C44_F9844;
extern void *D_800FDC68_FE868;
extern void *D_800F8418_F9018;
extern s32 *D_800FCE7C_FDA7C;
extern u32 D_800DEF60_DFB60;
extern OSMesgQueue D_800DEE08_DFA08;
extern void *D_800DEE20_DFA20;
extern s16 D_800F8F60_F9B60;
extern OSMesgQueue D_800DEF20_DFB20;
extern void *D_800DEF38_DFB38;
extern u32 D_800FDC6C_FE86C;
extern OSMesgQueue D_800F8F68_F9B68;
extern u64 D_800B8590_B9190[];
extern u64 D_800B8660_B9260[];
extern s32 D_800F9298_F9E98;

void func_8002FB6C_3076C(void);
void func_80020E70_21A70(void);
void func_800295D4_2A1D4(void*, void*);
void pfClsScr(void);
void omMain(void);
void espMain(void);
void func_80021490_22090(s32);
void func_800286FC_292FC(void*, s32);

INCLUDE_ASM("asm/nonmatchings/1D0B0", func_8001C4B0_1D0B0);

void func_8001C81C_1D41C(void) {
    while (1) {
        HuPrcVSleep();
        func_8002FB6C_3076C();
        func_80020E70_21A70();
        func_800295D4_2A1D4((void*)0x02000000, (void*)0x3D0800);
        pfClsScr();        
    }
}

void func_8001C868_1D468(void) {
    while (1) {
        HuPrcVSleep();
        omMain();       
    }
}

void func_8001C894_1D494(void) {
    while (TRUE) {
        HuPrcVSleep();
        rand8();
        espMain(); // esprite
        func_80021490_22090(2);
        func_800286FC_292FC(&D_800F9298_F9E98, 2); // hmfman
    }
}

INCLUDE_ASM("asm/nonmatchings/1D0B0", func_8001C8E0_1D4E0);

INCLUDE_ASM("asm/nonmatchings/1D0B0", func_8001CA48_1D648);

void func_8001CB00_1D700(void **arg1, s32 arg2, s32 arg3, u64 **arg4, s32 *arg5) {
    func_8001D114_1DD14(arg1, arg2, arg3);
    func_8001D13C_1DD3C(arg4);
    func_8001D178_1DD78(arg5);
    func_8001D184_1DD84(0);

    D_800DEDC0_DF9C0.mtqueue = &D_800DEF20_DFB20;
    D_800DEDC0_DF9C0.task.t.type = 1;
    D_800DEDC0_DF9C0.task.t.flags = 2;
    D_800DEDC0_DF9C0.task.t.ucode_boot = (u64 *)D_800B8590_B9190;
    D_800DEDC0_DF9C0.task.t.ucode_boot_size = (u32)D_800B8660_B9260 - (u32)D_800B8590_B9190;
    D_800DEDC0_DF9C0.task.t.ucode_size = 0x1000;
    D_800DEDC0_DF9C0.task.t.ucode_data_size = 0x800;
    D_800DEDC0_DF9C0.task.t.dram_stack_size = 0x400;
    D_800DEDC0_DF9C0.task.t.data_ptr = (u64 *)&D_800F8F30_F9B30;
    D_800DEDC0_DF9C0.task.t.data_size = 2;
    D_800DEDC0_DF9C0.task.t.yield_data_size = 0xC00;

    D_800F8F60_F9B60 = 0;
    D_800F842A_F902A = 0;
    D_800F8C44_F9844 = 0;
    D_800FDC68_FE868 = 0;
    D_800F8418_F9018 = 0;
    osCreateMesgQueue(&D_800DEE08_DFA08, &D_800DEE20_DFA20, 0x40);
    osCreateMesgQueue(&D_800DEF20_DFB20, &D_800DEF38_DFB38, 8);
    osCreateThread(&D_800F9058_F9C58, 0x10, &func_8001CCDC_1D8DC, NULL, &D_800DB5C0_DC1C0, 0x64);
    osStartThread(&D_800F9058_F9C58);
}

void *func_8001CC50_1D850(void) {
    void *current;
    void *next;
    void *fBuffer;
    s16 i;

    current = osViGetCurrentFramebuffer();
    next = osViGetNextFramebuffer();
    
    for (i = 0; i < D_800DEF5C_DFB5C; i++) {
        fBuffer = D_800DEF58_DFB58[i];
        if (fBuffer != current) {
            if (fBuffer != next) {
                return fBuffer;
            }
        }
    }
    return NULL;
}

void func_8001CCDC_1D8DC(void *arg0) {
    unkSchedStruct sp10;
    OSMesgQueue mesgQueue;
    unkGraphicsMessage2 sp38;
    unkSchedStruct sp58;
    OSMesgQueue mesgQueue2;
    unkGraphicsMessage2 sp68;
    graphicsMessage *recvdMesg;
    void *pAvailableFrameBuffer;
    s32 var_s4;
    u32 i;

    swapChainTaskQueue *pSwapChain;
    OSTask *pTask;

    recvdMesg = NULL;
    pSwapChain = &D_800DEDC0_DF9C0;
    pTask = &D_800DEDC0_DF9C0.task;
    var_s4 = 0;

    osCreateMesgQueue(&mesgQueue, (OSMesg *)&sp38, 8);
    func_8007E4D4_7F0D4(&sp10, &mesgQueue, 1);
    osCreateMesgQueue(&mesgQueue2, (OSMesg *)&sp68, 8);
    func_8007E4D4_7F0D4(&sp58, &mesgQueue2, 2);

    while (TRUE) {
        do {
        recvmesg:
            osRecvMesg(&mesgQueue, NULL, 1);
            if (osRecvMesg(&mesgQueue2, NULL, 0) == 0) {
                while (TRUE)
                    ;
            } // Infinite loop?
            if ((D_800FDC6C_FE86C - var_s4) < D_800DEF60_DFB60) {
                goto recvmesg;
            }

            var_s4 = D_800FDC6C_FE86C;
            func_8007C218_7CE18();
            pAvailableFrameBuffer = (void *)func_8001CC50_1D850();
        } while (pAvailableFrameBuffer == NULL);

        D_800F8418_F9018 = D_800FDC68_FE868;
        D_800FDC68_FE868 = pAvailableFrameBuffer;

        /* Need redundant do for regalloc? */
        do {
            do {

                osRecvMesg(&D_800DEE08_DFA08, (OSMesg)&recvdMesg, 1);
                if (osRecvMesg(&mesgQueue2, NULL, 0) == 0) {
                    while (TRUE)
                        ;
                } else {
                    u32 intMask;
                    Gfx *dl = D_800F8F30_F9B30;
                    gSPSegment(dl++, D_800DEF5E_DFB5E, pAvailableFrameBuffer);
                    gSPBranchList(dl++, recvdMesg->unk00);
                    pSwapChain->fullqueue = (void *)recvdMesg->unk08;
                    pTask->t.dram_stack = D_800FC730_FD330;
                    pTask->t.output_buff = D_800FC98C_FD58C;
                    pTask->t.output_buff_size = D_800F8430_F9030;
                    pTask->t.yield_data_ptr = D_800FA638_FB238;
                    pTask->t.ucode = (u64 *)*((recvdMesg->unk04 * 2) + D_800FCE7C_FDA7C);            // offset     (data pairs?)
                    pTask->t.ucode_data = (u64 *)*(((recvdMesg->unk04 * 2) | 1) + D_800FCE7C_FDA7C); // offset + 1

                    osSendMesg(&D_800F8F68_F9B68, (OSMesg)pSwapChain, 1);
                    osRecvMesg(&D_800DEF20_DFB20, NULL, 1);

                    intMask = osSetIntMask(1);
                    D_800F8F60_F9B60 -= 1;
                    osSetIntMask(intMask);

                    if (recvdMesg->unk0C != NULL) {
                        osSendMesg(recvdMesg->unk0C, (OSMesg)recvdMesg->unk10, 1);
                    }
                }

            } while (!((s32)recvdMesg->unk08 & 1));
        } while (FALSE);

        for (i = 1; i < D_800DEF60_DFB60; i++) {
            osRecvMesg(&mesgQueue, NULL, 1);
        }

        osViSwapBuffer(pAvailableFrameBuffer);
        if (D_800F8C44_F9844 == 0) {
            if (osRecvMesg(&mesgQueue2, NULL, 0) == 0) {
                while (TRUE)
                    ;
            }
            osViSetYScale(1.0f);
            osViBlack(0);
        }
        D_800F8C44_F9844++;
        func_8007C244_7CE44(); // empty function
    }
}

graphicsMessage *func_8001D000_1DC00(void) {
    if (D_800F842A_F902A >= 0x40) {
        D_800F842A_F902A = 0;
    }
    return &D_800F8720_F9320[D_800F842A_F902A++];
}

u8 func_8001D054_1DC54(s32 arg0, u16 arg1, s32 arg2, OSMesgQueue *arg3, s32 arg4) {
    graphicsMessage *mesg;
    u32 intMask;

    if (D_800F8F60_F9B60 >= 0x40) {
        return FALSE;
    }

    intMask = osSetIntMask(1);
    D_800F8F60_F9B60++;
    osSetIntMask(intMask);
    mesg = func_8001D000_1DC00();

    /* Initialize message. */
    mesg->unk00 = arg0;
    mesg->unk04 = arg1;
    mesg->unk08 = arg2;
    mesg->unk0C = arg3;
    mesg->unk10 = arg4;

    osSendMesg(&D_800DEE08_DFA08, mesg, 1);
    return TRUE;
}

void func_8001D114_1DD14(void **pool, u16 size, u16 segment) {
    D_800DEF58_DFB58 = pool;
    D_800DEF5C_DFB5C = size;
    D_800DEF5E_DFB5E = segment;
}

INCLUDE_ASM("asm/nonmatchings/1D0B0", func_8001D130_1DD30);

void func_8001D13C_1DD3C(u64 **threadStacks) {
    D_800FC730_FD330 = *threadStacks++;
    D_800FC98C_FD58C = *threadStacks++;
    D_800F8430_F9030 = *threadStacks++;
    D_800FA638_FB238 = *threadStacks;
}

INCLUDE_ASM("asm/nonmatchings/1D0B0", func_8001D178_1DD78);

INCLUDE_ASM("asm/nonmatchings/1D0B0", func_8001D184_1DD84);

INCLUDE_ASM("asm/nonmatchings/1D0B0", func_8001D190_1DD90);

INCLUDE_ASM("asm/nonmatchings/1D0B0", func_8001D9D4_1E5D4);

INCLUDE_ASM("asm/nonmatchings/1D0B0", func_8001DA90_1E690);

INCLUDE_ASM("asm/nonmatchings/1D0B0", func_8001DE08_1EA08);

INCLUDE_ASM("asm/nonmatchings/1D0B0", func_8001DF00_1EB00);

INCLUDE_ASM("asm/nonmatchings/1D0B0", func_8001E108_1ED08);

INCLUDE_ASM("asm/nonmatchings/1D0B0", func_8001E57C_1F17C);

INCLUDE_ASM("asm/nonmatchings/1D0B0", func_8001E78C_1F38C);

INCLUDE_ASM("asm/nonmatchings/1D0B0", func_8001EA88_1F688);

INCLUDE_ASM("asm/nonmatchings/1D0B0", func_8001EB18_1F718);

INCLUDE_ASM("asm/nonmatchings/1D0B0", func_8001EB48_1F748);

INCLUDE_ASM("asm/nonmatchings/1D0B0", func_8001EF00_1FB00);

INCLUDE_ASM("asm/nonmatchings/1D0B0", func_8001F1B8_1FDB8);

INCLUDE_ASM("asm/nonmatchings/1D0B0", func_8001F380_1FF80);

INCLUDE_ASM("asm/nonmatchings/1D0B0", func_8001F4AC_200AC);

INCLUDE_ASM("asm/nonmatchings/1D0B0", func_8001F50C_2010C);

INCLUDE_ASM("asm/nonmatchings/1D0B0", func_8001F8C0_204C0);

INCLUDE_ASM("asm/nonmatchings/1D0B0", func_8001FBE0_207E0);

INCLUDE_ASM("asm/nonmatchings/1D0B0", func_8001FC8C_2088C);

INCLUDE_ASM("asm/nonmatchings/1D0B0", func_8001FFCC_20BCC);
