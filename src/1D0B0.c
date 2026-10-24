#include "common.h"
#include "game/hmfman.h"
#include "game/rsp.h"
#include "game/gamework.h"
#include "game/malloc.h"
#include "process.h"

/* Game loop processes (MP1 src/engine/gameman.c, MP3 src/gameman.c), the graphics swap chain
   (MP3 src/graphics.c, MP1 src/engine/graphics.c) and the HMF model loader (MP3 src/hmfload.c,
   MP1 src/1B800.c). */

typedef struct {
    Gfx* unk00; /* the frame's display list */
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
extern Gfx D_800F8F30_F9B30[];
extern s32 D_800F8C44_F9844;
extern void *D_800FDC68_FE868;
extern void *D_800F8418_F9018;
extern u32 D_800DEF60_DFB60;
extern u8 D_800F92D0_F9ED0[]; /* per player: 1 = CPU (no pad) */
void func_800B0EF0_B1AF0(void*, s32, s32); /* memset */
extern OSMesgQueue D_800DEE08_DFA08;
extern void *D_800DEE20_DFA20;
extern s16 D_800F8F60_F9B60;
extern OSMesgQueue D_800DEF20_DFB20;
extern void *D_800DEF38_DFB38;
extern u32 D_800FDC6C_FE86C;
extern OSMesgQueue D_800F8F68_F9B68;
extern s32 D_800F9298_F9E98;

void func_8002FB6C_3076C(void);
void func_80020E70_21A70(void);
void func_800295D4_2A1D4(void*, void*);
void pfClsScr(void);
void omMain(void);
void espMain(void);
void func_80021490_22090(s32);
void func_800286FC_292FC(void*, s32);

/* Audio and sound setup handed to func_8000E38C_EF8C (MP3 D_800D5298_D5E98). */
typedef struct UnkSndConfig {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ char unk04[4];
    /* 0x08 */ void* unk08;
    /* 0x0C */ void* unk0C;
    /* 0x10 */ void* unk10;
    /* 0x14 */ void* unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ char unk1C[0xC];
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ char unk30[0x2C];
    /* 0x5C */ s32 unk5C;
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ s32 unk68;
} UnkSndConfig;

extern Vec D_800FD474_FE074;  /* CRot */
extern f32 D_800FA610_FB210;  /* CZoom */
extern Vec D_8010274C_10334C; /* Center */
extern Vec D_80102770_103370[4]; /* CRotM */
extern f32 D_800F94A8_FA0A8[4];  /* CZoomM */
extern Vec D_801013B0_101FB0[4]; /* CenterM */
extern u8 D_800FD7F5_FE3F5;
extern u16 D_800FFDF2_1009F2;
extern u16 D_800F9562_FA162;
extern u16 D_80102702_103302;
extern s16 D_800FD80C_FE40C;
extern Process* D_800FC894_FD494;
extern Process* D_800FD7F0_FE3F0;
extern UnkSndConfig D_80101100_101D00;
/* D_80101100_101D00.unk08 and unk0C: retail addresses them through their own symbol */
extern void* D_80101108_101D08[2];
extern s16 D_800CD52E_CE12E;
extern s16 D_800CD52C_CE12C;
extern s32 D_800FA190_FAD90;

void func_8008EFB0_8FBB0(void);
void func_800277B0_283B0(void* (*arg0)(s32), void (*arg1)(void*), u16 arg2, u16 arg3, u16 arg4, u8 arg5);
void func_80020070_20C70(s16);
void pfInit(void);
void func_80068B80_69780(u32);
s32 HuGetPadInserted(s16);
s32 func_8007DD68_7E968(void);
void func_8001C8E0_1D4E0(void);
void func_8000E9E8_F5E8(UnkSndConfig*);
void func_8000E38C_EF8C(UnkSndConfig*);
void func_8000EA88_F688(s32);
void GWMgRecordSet(s16, s16);
void func_8001C81C_1D41C(void);
void func_8001C868_1D468(void);
void func_8001C894_1D494(void);

void func_8001C4B0_1D0B0(void) {
    s32 i;

    HuPrcVSleep();

    D_800FD474_FE074.x = 325.0f;
    D_800FD474_FE074.y = 0.0f;
    D_800FD474_FE074.z = 0.0f;

    D_800FA610_FB210 = 2250.0f;

    D_8010274C_10334C.x = D_8010274C_10334C.y = D_8010274C_10334C.z = D_800FD474_FE074.y;

    for (i = 0; i < 4; i++) {
        D_80102770_103370[i].x = 325.0f;
        D_80102770_103370[i].y = D_80102770_103370[i].z = 0.0f;
        D_800F94A8_FA0A8[i] = 2250.0f;
        D_801013B0_101FB0[i].x = D_801013B0_101FB0[i].y = D_801013B0_101FB0[i].z = 0.0f;
    }

    D_800FD7F5_FE3F5 = 3;
    D_800FFDF2_1009F2 = 0x1000;
    D_800F9562_FA162 = 0x2004;
    D_80102702_103302 = 0x180;
    func_8008EFB0_8FBB0();
    func_800277B0_283B0((void* (*)(s32)) HuMemMemoryAllocPerm, HuMemMemoryFreePerm, D_800FFDF2_1009F2,
                        D_800F9562_FA162, D_80102702_103302, D_800FD7F5_FE3F5);
    func_80020070_20C70(1);
    pfInit();
    func_80068B80_69780((u32) D_01142DD0);
    D_800FD80C_FE40C = 0;

    do {
        if (HuGetPadInserted(D_800FD80C_FE40C) != 0) {
            break;
        }
    } while (++D_800FD80C_FE40C < 4);

    if (D_800FD80C_FE40C == 4) {
        D_800FD80C_FE40C = -1;
    }

    HuMemHeapAllocPermSizeGet();
    D_800FC894_FD494 = HuPrcCreate(func_8001C81C_1D41C, 0xF000, 0x3000, 0);
    HuPrcCreate(func_8001C868_1D468, 0x4000, 0x3000, 0);
    D_800FD7F0_FE3F0 = HuPrcCreate(func_8001C894_1D494, 0x1000, 0x3000, 0);

    {
        s32 temp_s0 = func_8007DD68_7E968();

        func_8001C8E0_1D4E0();
        func_8000E9E8_F5E8(&D_80101100_101D00);
        if (temp_s0 == 1) {
            omOvlCallEx(0x5A, 0, 0x81);
        } else {
            omOvlCallEx(0x57, 0, 0x84);
        }
    }

    D_80101108_101D08[0] = D_01750450;
    D_80101108_101D08[1] = D_01CBF410;
    D_800CD52E_CE12E = 1;
    D_800CD52C_CE12C = 1;
    D_80101100_101D00.unk00 = 0x70018F;
    D_80101100_101D00.unk10 = D_01E2A560;
    D_80101100_101D00.unk28 = 1;
    D_80101100_101D00.unk2C = 0;
    D_80101100_101D00.unk14 = (void*) 0x802E0000;
    D_80101100_101D00.unk18 = 0x80000;
    D_80101100_101D00.unk5C = 0x6E;
    D_80101100_101D00.unk60 = 0;
    D_80101100_101D00.unk64 = 0;
    D_80101100_101D00.unk68 = D_800FA190_FAD90;
    func_8000E38C_EF8C(&D_80101100_101D00);

    if (_CheckFlag(2) != 0) {
        func_8000EA88_F688(0);
    } else {
        func_8000EA88_F688(1);
    }
    D_800F8C60.unk01 = 2;

    HuPrcKill(HuPrcCurrentGet());

    while (TRUE) {
        HuPrcVSleep();
    }
}

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

/* Clears the four player records: pads present are human, the rest CPU. */
void func_8001C8E0_1D4E0(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_800B0EF0_B1AF0(&gPlayers[i], 0, sizeof(GW_PLAYER));
        if (HuGetPadInserted(i)) {
            D_800F92D0_F9ED0[i] = 0;
            gPlayers[i].flags = (u16)gPlayers[i].flags & ~1;
        } else {
            D_800F92D0_F9ED0[i] = 1;
            gPlayers[i].flags |= 1;
        }
        gPlayers[i].port = i;
        gPlayers[i].coins = 10;
        gPlayers[i].coins_mg = 0;
        gPlayers[i].group = i;
        gPlayers[i].cpu_difficulty2 = 1;
        gPlayers[i].cpu_difficulty = 0;
        gPlayers[i].stars = 0;
    }
}

void func_8001CA48_1D648(void) {
    func_8001C8E0_1D4E0();
    GWMgRecordSet(0, 18000);
    GWMgRecordSet(1, 5400);
    GWMgRecordSet(2, 3600);
    GWMgRecordSet(3, 5400);
    GWMgRecordSet(4, 0);
    GWMgRecordSet(5, 1200);
    GWMgRecordSet(6, 1500);
    GWMgRecordSet(7, 1800);
    GWMgRecordSet(8, 0);
    GWMgRecordSet(9, 0);
    GWMgRecordSet(10, 0);
    GWMgRecordSet(11, 0);
    GWMgRecordSet(12, 0);
}

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

u8 func_8001D054_1DC54(Gfx* arg0, u16 arg1, s32 arg2, OSMesgQueue *arg3, s32 arg4) {
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

void func_8001D178_1DD78(s32* arg0) {
    D_800FCE7C_FDA7C = arg0;
}

void func_8001D184_1DD84(u32 arg0) {
    D_800DEF60_DFB60 = arg0;
}


/* ---- HMF loader (MP3 src/hmfload.c) ---- */

typedef struct {
    Gfx* unk00[4];
    void* unk10;
    void* unk14;
} HmfModelData_Unk64_Unk3C_Struct;

typedef struct {
    u8 unk00;
    char unk01[0x33];
} HmfModelData_Unk64_Unk60_Unk54_Struct;

typedef struct {
    char unk00[0x22];
    s16 unk22;
    char unk24[4];
    s16 unk28;
    s16 unk2A;
    char unk2C[0x24];
    s32 unk50;
    HmfModelData_Unk64_Unk60_Unk54_Struct* unk54;
    char unk58[0x10];
} HmfModelData_Unk64_Unk60_Struct;

typedef struct {
    char unk00[0x18];
} HmfModelData_Unk64_Unk8C_Struct;

typedef struct {
    char unk00[2];
    s16 unk02;
    char unk04[4];
    s32 unk08;
} HmfModelData_Unk64_Unk98_Struct;


// New struct for the array at unk84 (0x10 bytes per entry)
typedef struct {
    u8 unk0[3];
    u8 unk3;
    u8 unk4;
    u8 unk5[4];
    u8 unk9;
    u8 unkA[2];
    HmfTex* unkC;
} HmfData_Unk84_Entry;




typedef struct {
    /* 0x00 */ u8 unk00;
    /* 0x01 */ char unk01;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s16 unk04; /* vertex count (MP3 0x22) */
    /* 0x06 */ s16 unk06; /* MP3 0x24 */
    /* 0x08 */ s16 unk08; /* MP3 0x26 */
    /* 0x0A */ char unk0A[2];
    /* 0x0C */ s16 unk0C;
    /* 0x0E */ s16 unk0E;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ char unk12[0x1C]; /* handed to func_8001F380_1FF80 (MP3 passes the entry itself) */
    /* 0x2E */ u8 unk2E; /* MP3 0x1C */
    /* 0x2F */ char unk2F[0x13];
    /* 0x42 */ s16 unk42[3];
    /* 0x48 */ s16 unk48[3];
    /* 0x4E */ char unk4E[2];
    /* 0x50 */ s32 unk50;
    /* 0x54 */ HmfFaceRec *unk54;
    /* 0x58 */ void *unk58;
    /* 0x5C */ void *unk5C; /* HmfPart's texture refs and second list */
    /* 0x60 */ void *unk60;
    /* 0x64 */ void *unk64;
} HmfObjectData;

typedef struct {
    s16 unk00;
    char unk02[2];
    s32 unk04;
    s32 unk08;
    s32 unk0C;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    s32 unk48;
    u8 unk4C;
    u8 unk4D;
    u8 unk4E;
    char unk4F[1];
    void *unk50;
    void *unk54;
    char unk58[0x40];
} HmfMotionData;

typedef struct {
    char unk00[0x1C];
    s16 unk1C;
    char unk1E[2];
    s32 unk20;
    s32 unk24;
    s32 unk28;
} HmfMapData;

typedef struct {
    char unk00[0x1C];
    s16 unk1C;
    s16 unk1E;
    s16 unk20;
    char unk22[2];
    f32 unk24;
    s16 *unk28;
    s16 *unk2C;
    u8 *unk30;
} HmfDispData;

typedef struct {
    s16 unk00;
    s16 unk02;
    s16 *unk04;
} HmfMtnData;

typedef struct {
    s16 unk00;
    s16 unk02;
    s16 unk04;
    char unk06[2];
    f32 unk08;
    f32 unk0C;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
} HmfData_UnkBC;

typedef struct {
    u8 unk00;
    u8 unk01;
    u8 unk02;
    u8 unk03;
    u8 unk04;
    u8 unk05;
    u8 unk06;
    u8 unk07;
    u8 unk08;
    u8 unk09;
    u8 unk0A;
    u8 unk0B;
    u8 unk0C; /* flags (MP3 0x09) */
    u8 unk0D; /* MP3 0x0A */
} HmfData_Unk88_Entry; /* size 0xE: MP3's 0xB plus a third colour at 0x09 */

typedef struct {
    s16 unk00;
    s16 unk02;
    s16 unk04;
    char unk06[2];
    s32 unk08;
    s32 unk0C;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    u8 unk44;
    u8 unk45;
    char unk46[2];
    void *unk48;
    char unk4C[0x40];
} HmfSkeletonData;

typedef struct {
    u8 unk00;
    s8 unk01;
    char unk02[8];
    u8 unk0A;
    s8 unk0B;
    s8 unk0C;
    char unk0D[1];
    s16 unk0E;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    char unk18[4];
    u16 unk1C;
    s16 unk1E;
    s16 unk20; /* MP3 0x22 */
    s16 unk22; /* MP3 0x24 */
    s16 unk24;
    s16 unk26;
    char unk28[4];
    u8 *unk2C;
    u8 *unk30;
    u8 *unk34;
    u8 *unk38;
    HmfModelData_Unk64_Unk3C_Struct *unk3C;
    void *unk40;
    Vtx *unk44[4]; /* inferred: MP3 fields 0x50-0xB8 sit 4 bytes later in MP2 */
    void *unk54;
    u8 *unk58;
    void *unk5C;
    void *unk60;
    HmfObjectData *unk64;
    s16 unk68;
    char unk6A[2];
    HmfSkeletonData *unk6C;
    char unk70[0x14];
    HmfMotionData *unk84;
    HmfData_Unk84_Entry *unk88;
    HmfData_Unk88_Entry *unk8C;
    HmfModelData_Unk64_Unk8C_Struct *unk90;
    HmfModelData_Unk64_Unk8C_Struct *unk94;
    HmfModelData_Unk64_Unk8C_Struct *unk98;
    HmfModelData_Unk64_Unk98_Struct *unk9C;
    void *unkA0;
    s32 unkA4;
    f32 unkA8;
    f32 unkAC;
    f32 unkB0;
    void *unkB4;
    HmfDispData *unkB8;
    HmfMtnData *unkBC;
    void *unkC0; /* inferred: one field where MP3 has two (0xBC, 0xC0) */
    HmfMapData *unkC4;
    u8 *unkC8;
    void *unkCC;
    HmfData_UnkD0 *unkD0;
    void (*unkD4)(f32 *, f32, f32, f32);
    void (*unkD8)(f32 *, f32, f32, f32);
    s32 unkDC;
} HmfLoadData;

typedef struct {
    char unk00[6];
    s16 loopIndex;
    char unk08[6];
    s16 recordCount;
    char unk10[6];
    s16 mapCount;
    char unk18[6];
    s16 recordSize;
    char unk20[6];
    s16 unk3BCount;
    char unk28[4];
    s32 flagsMask;
} HmfLoadWork;

typedef union {
    s32 word;
    f32 single;
} HmfFloatBits;

extern u8 *D_800DEF70_DFB70;
extern u8 *D_800DEF74_DFB74;
extern u8 *D_800DEF78_DFB78;
extern u8 *D_800DEF7C_DFB7C;
extern u8 *D_800DEF80_DFB80;
extern u8 *D_800DEF84_DFB84;
extern u8 *D_800DEF88_DFB88;
extern u8 *D_800DEF8C_DFB8C;
extern u8 *D_800DEF90_DFB90;
extern u8 D_800F842C_F902C;
extern u8 D_800F92DD_F9EDD;
/* .data (0xCA770-0xCA780; objects' .data start 16-aligned, so 274D0's fill colour sits here) */
u8 D_800C9B70_CA770 = 0; /* fill colour r, g, b (274D0) */
u8 D_800C9B71_CA771 = 0;
u8 D_800C9B72_CA772 = 0;
s16 D_800C9B74_CA774 = 0;
extern s16 D_800FA1AA_FADAA;
extern s16 D_8010106C_101C6C;

void func_80025884_26484(f32 *, f32, f32, f32);
void func_800261CC_26DCC(f32 *, f32, f32, f32);
void func_800264D8_270D8(f32 *, f32, f32, f32);
void func_800B2060_B2C60(f32 *, f32, f32, f32);
s16 func_8001DA90_1E690(HmfLoadData *, void *);
s16 func_8001DE08_1EA08(void *, s16);
void func_8001DF00_1EB00(HmfLoadData *);
s16 func_8001E108_1ED08(HmfLoadData *);
s16 func_8001E57C_1F17C(HmfLoadData *);
s16 func_8001E78C_1F38C(HmfLoadData *, u16, void *);
u8 *func_8001EA88_1F688(s32, void *, void *);
void *func_8001EB18_1F718(void *);
void func_8001EB48_1F748(HmfLoadData *, s16, s16, s16);
void func_8001EF00_1FB00(HmfFaceRec *, u8 *, HmfLoadData *, u16 *);
void func_8001F1B8_1FDB8(s8 *, u16 *, u16 *, u16 *);
s16 func_8001F380_1FF80(HmfLoadData *, void *, s16);
s32 func_8001F50C_2010C(HmfLoadData *);
s32 func_8001F8C0_204C0(HmfLoadData *);
void func_8001FBE0_207E0(HmfLoadData *, void *, s16);
s32 func_8001FC8C_2088C(HmfLoadData *, void *);
void func_8001FFCC_20BCC(HmfLoadData *);
void func_8001203C_12C3C(HmfLoadData *, u8 *, s32);
void func_8002CAE4_2D6E4(HmfLoadData *);
void func_80031630_32230(HmfLoadData *);
void func_800339D0_345D0(HmfLoadData *);
void func_80038654_39254(HmfLoadData *);
void func_8003EF04_3FB04(HmfLoadData *);
void osSyncPrintf(const char *fmt, ...);
f32 func_800B1830_B2430(f32); /* sqrtf */

/* MP3 Hmfload (src/hmfload.c) without the 0x3B records, MP2's object entries (0x68 bytes).
   Register allocation differs (recordCount stays in s0 where retail spills it, so flags and the
   counters land in other registers); otherwise the same code. Its string is the unit's only
   rodata, D2CCC, which starts on a 4-byte boundary a carved object cannot: it is defined at the
   end of 1C7C0.c's carved rodata as D_800D20CC_D2CCC. */
#ifdef NON_MATCHING
void func_8001D190_1DD90(HmfLoadData *hmf, void *fileData, s32 flags) {
    s16 i;
    s16 motionCount;
    s16 mapCount;
    s16 recordSize;
    s32 flagsMask;
    s16 modelCount;
    u8 *file;
    char *fileHeader;
    u8 *record;
    u8 *recordStart;
    s16 extraCount;
    s16 objectIndex;
    HmfObjectData *data;
    s16 recordCount;

    file = fileData;
    fileHeader = (char *)file;
    if (fileHeader[0] != 'F' || fileHeader[1] != 'O') {
        osSyncPrintf("Unknown Hmf Format!\n");
    }
    hmf->unk2C = file;
    hmf->unk34 = file + 0xC;
    hmf->unk30 = hmf->unk2C + (hmf->unk2C[5] << 0x10) + (hmf->unk2C[6] << 8) + hmf->unk2C[7] + 8;

    D_800DEF74_DFB74 = func_8001EA88_1F688(0x56545831, hmf->unk34, hmf->unk30);
    D_800DEF78_DFB78 = func_8001EA88_1F688(0x46414331, hmf->unk34, hmf->unk30);
    D_800DEF7C_DFB7C = func_8001EA88_1F688(0x4F424A31, hmf->unk34, hmf->unk30);
    D_800DEF80_DFB80 = func_8001EA88_1F688(0x4D415431, hmf->unk34, hmf->unk30);
    D_800DEF84_DFB84 = func_8001EA88_1F688(0x434F4C31, hmf->unk34, hmf->unk30);
    D_800DEF88_DFB88 = func_8001EA88_1F688(0x41545231, hmf->unk34, hmf->unk30);
    D_800DEF8C_DFB8C = func_8001EA88_1F688(0x4D544E31, hmf->unk34, hmf->unk30);
    D_800DEF90_DFB90 = func_8001EA88_1F688(0x53545247, hmf->unk34, hmf->unk30);
    hmf->unk38 = func_8001EA88_1F688(0x4D415031, hmf->unk34, hmf->unk30);

    hmf->unk16 = 0;
    hmf->unk14 = 0;
    hmf->unk12 = 0;
    hmf->unk10 = 0;
    hmf->unk40 = NULL;
    hmf->unk3C = NULL;
    hmf->unkB4 = NULL;
    hmf->unkA0 = NULL;
    hmf->unk0A = 0;
    hmf->unkC0 = NULL;
    hmf->unk60 = NULL;
    hmf->unk5C = NULL;
    hmf->unkCC = NULL;
    hmf->unkD0 = NULL;

    D_800DEF70_DFB70 = func_8001EA88_1F688(0x4D4F4445, hmf->unk34, hmf->unk30);
    func_8001FFCC_20BCC(hmf);
    if (D_800DEF74_DFB74 != NULL) {
        func_8001DF00_1EB00(hmf);
    }
    if (D_800DEF80_DFB80 != NULL) {
        func_8001E108_1ED08(hmf);
    }
    D_800F92DD_F9EDD = flags;
    func_8003CB70_3D770((HmfData *)hmf); /* HmfLoadData is this unit's view of HmfData */
    if (D_800DEF88_DFB88 != NULL) {
        func_8001E57C_1F17C(hmf);
    }
    hmf->unk94 = NULL;
    hmf->unk90 = NULL;
    hmf->unk9C = NULL;

    record = D_800DEF7C_DFB7C + 8;
    recordCount = record[0];
    recordCount = (recordCount << 8) + record[1];
    hmf->unk68 = 0;
    hmf->unk84 = (HmfMotionData *)-1;
    if ((recordCount << 0x10) == 0) {
        hmf->unk16 = 0;
        hmf->unk10 = 0;
        return;
    }

    record += 4;
    recordStart = record;
    i = 0;
    mapCount = 0;
    modelCount = 0;
    motionCount = 0;
    extraCount = 0;
    for (; i < recordCount; i++) {
        switch (record[2]) {
            case 0x3A:
                modelCount++;
                break;

            case 0x3D:
                motionCount++;
                break;

            case 0x61:
                mapCount++;
                break;

            case 0x5D:
                extraCount++;
                break;
        }
        record += ((record[0] << 8) + record[1]) + 2;
    }

    if (motionCount != 0) {
        hmf->unk84 = func_80027154_27D54(recordCount * sizeof(HmfMotionData), D_800FA1AA_FADAA);
    }

    if (flags & 0x200000) {
        if (mapCount != 0) {
            hmf->unkC4 = func_80027154_27D54(mapCount * sizeof(HmfMapData), D_800FA1AA_FADAA);
            hmf->unk24 = mapCount;
        }
        if (extraCount != 0) {
            hmf->unkC0 = func_80027154_27D54(sizeof(HmfData_UnkBC), D_800FA1AA_FADAA);
        } else {
            hmf->unkC0 = NULL;
        }
    } else {
        hmf->unkC4 = NULL;
        hmf->unkC0 = NULL;
    }

    hmf->unk64 = func_80027154_27D54(modelCount * sizeof(HmfObjectData), D_800FA1AA_FADAA);
    record = recordStart;
    hmf->unk1C = 0;
    i = 0;
    objectIndex = 0;
    mapCount = 0;
    motionCount = 0;
    flagsMask = flags & 0x200000;
    for (; i < recordCount; i++) {
        switch (record[2]) {
            case 0x3A: {
                s16 linkIndex;
                s16 vertexCount;
                s32 attrMask;

                recordStart = record + 5;
                recordSize = (record[0] << 8) + record[1];
                linkIndex = (record[6] << 8) + record[7];
                hmf->unk64[objectIndex].unk08 = func_8001F380_1FF80(hmf, hmf->unk64[objectIndex].unk12, (record[3] << 8) + record[4]);
                data = &hmf->unk64[objectIndex];
                vertexCount = (record[8] << 8) + record[9];
                data->unk04 = vertexCount;
                hmf->unk1C += vertexCount;
                hmf->unk64[objectIndex].unk50 = 0x2B00;
                hmf->unk64[objectIndex].unk58 = NULL;
                hmf->unk64[objectIndex].unk02 = -1;
                if (hmf->unk14 != 0) {
                    func_8001EB48_1F748(hmf, objectIndex, linkIndex, vertexCount);
                    if (vertexCount != 0) {
                        /* the first face's texture, low byte (a byte read of the s16) */
                        hmf->unk64[objectIndex].unk2E = ((u8*)&hmf->unk64[objectIndex].unk54->unk32)[1];
                    } else {
                        hmf->unk64[objectIndex].unk2E = 0xFF;
                    }
                }
                attrMask = hmf->unk64[objectIndex].unk50 & 0x10000;
                if (((D_800F842C_F902C != 0) & (recordSize >= 0x3A)) && recordStart[0x35] != 0 && recordStart[0x36] == 0) {
                    if (recordSize == 0x3E) {
                        hmf->unk64[objectIndex].unk50 = (recordStart[0x37] << 0x18) | (recordStart[0x39] << 8) | recordStart[0x3A] | attrMask;
                    } else {
                        hmf->unk64[objectIndex].unk50 = (recordStart[0x37] << 0x18) | attrMask;
                    }
                    hmf->unk64[objectIndex].unk06 = recordStart[0x38];
                }
                objectIndex++;
                break;
            }

            case 0x10:
                func_8001DA90_1E690(hmf, record + 5);
                break;

            case 0x3D:
                func_8001E78C_1F38C(hmf, motionCount, record + 5);
                motionCount++;
                break;

            case 0x61:
                if (flagsMask) {
                    hmf->unkC4[mapCount].unk1C = func_8001F380_1FF80(hmf, &hmf->unkC4[mapCount], (record[3] << 8) + record[4]);
                    func_8001FBE0_207E0(hmf, record + 5, mapCount);
                    mapCount++;
                }
                break;

            case 0x5D:
                if (flagsMask) {
                    func_8001FC8C_2088C(hmf, record + 5);
                }
                break;
        }
        record += ((record[0] << 8) + record[1]) + 2;
    }

    hmf->unk10 = objectIndex;
    hmf->unk16 = motionCount;
    func_80038654_39254(hmf);
    func_8003EF04_3FB04(hmf);
    func_8001F50C_2010C(hmf);
}
#else
INCLUDE_ASM("asm/nonmatchings/1D0B0", func_8001D190_1DD90);
#endif

void func_8001D9D4_1E5D4(HmfLoadData *hmf) {
    s16 i;

    if (hmf->unk84 != (HmfMotionData *)-1) {
        if (hmf->unk16 > 0) {
            i = 0;
            do {
                HuMemFree(hmf->unk84[i].unk50);
                i++;
            } while (i < hmf->unk16);
        }
        HuMemFree(hmf->unk84);

    } else if (hmf->unk68 != 0) {
        HuMemFree(hmf->unk6C);
    }
    HuMemFree(hmf->unk64);
}

s16 func_8001DA90_1E690(HmfLoadData *hmf, void *arg1) {
    u8 *data;
    u8 *argData;
    HmfSkeletonData *entry;
    s16 target;
    s16 count;
    s16 i;
    s32 value;
    s32 value2;
    s32 value3;

    argData = arg1;
    target = (argData[0] << 8) + argData[1];
    data = hmf->unk34;
    while (data < hmf->unk30) {
        data = func_8001EA88_1F688(0x534B4C31, data, hmf->unk30);
        if (data == NULL) {
            return 0;
        }
        if (((data[8] << 8) + data[9]) == target) {
            break;
        }
        data = func_8001EB18_1F718(data + 4);
    }

    count = data[0xA];
    hmf->unk68 = count;
    hmf->unk6C = func_80027154_27D54(count * sizeof(HmfSkeletonData), D_800FA1AA_FADAA);
    data += 0xB;
    for (i = 0; i < count; i++) {
        entry = &hmf->unk6C[i];
        entry->unk00 = func_8001DE08_1EA08(hmf, (data[1] << 8) + data[2]);
        entry->unk48 = hmf;
        data += (data[0] << 1) + 1;
        value = data[0];
        value <<= 0x18;
        value += data[1] << 0x10;
        value += data[2] << 8;
        entry->unk08 = value + data[3];
        value = data[4];
        value <<= 0x18;
        value += data[5] << 0x10;
        value += data[6] << 8;
        entry->unk0C = value + data[7];
        value = data[8];
        value <<= 0x18;
        value += data[9] << 0x10;
        value += data[0xA] << 8;
        entry->unk10 = value + data[0xB];
        data += 0xC;
        value = data[0];
        value <<= 0x18;
        value += data[1] << 0x10;
        value += data[2] << 8;
        entry->unk14 = value + data[3];
        value = data[4];
        value <<= 0x18;
        value += data[5] << 0x10;
        value += data[6] << 8;
        entry->unk18 = value + data[7];
        value = data[8];
        value <<= 0x18;
        value += data[9] << 0x10;
        value += data[0xA] << 8;
        entry->unk1C = value + data[0xB];
        data += 0xC;
        value = data[0];
        value <<= 0x18;
        value += data[1] << 0x10;
        value += data[2] << 8;
        entry->unk20 = value + data[3];
        value = data[4];
        value <<= 0x18;
        value += data[5] << 0x10;
        value += data[6] << 8;
        entry->unk24 = value + data[7];
        value = data[8];
        value <<= 0x18;
        value += data[9] << 0x10;
        value += data[0xA] << 8;
        entry->unk28 = value + data[0xB];
        data += 0x18;
        entry->unk02 = (data[0] << 8) + data[1];
        entry->unk04 = (data[2] << 8) + data[3];
        value2 = entry->unk08;
        value = entry->unk0C;
        value3 = entry->unk10;
        entry->unk2C = value2;
        entry->unk30 = value;
        entry->unk34 = value3;
        value2 = entry->unk14;
        value = entry->unk18;
        value3 = entry->unk1C;
        entry->unk38 = value2;
        entry->unk3C = value;
        entry->unk40 = value3;
        entry->unk45 = 0;
        entry->unk44 = 0;
        data += 5;
    }
    return count;
}

/* MP1 func_8001B608 (src/1B800.c); MP2 reads the OBJ1 chunk from its global. */
s16 func_8001DE08_1EA08(void *arg0, s16 arg1) {
    s16 temp_v1;
    s16 var_t0;
    s16 var_a3;
    u8 *temp_v0;
    u8 *var_a2;
    s16 i;

    temp_v0 = D_800DEF7C_DFB7C;
    temp_v1 = (temp_v0[8] << 8) + temp_v0[9];
    var_a2 = temp_v0 + 12;

    for (var_a3 = var_t0 = i = 0; i < temp_v1; i++) {
        switch (var_a2[2]) {
            case 58:
                if (arg1 == (var_a2[3] << 8) + var_a2[4]) {
                    return var_t0;
                }
                var_t0++;
                break;
            case 61:
                if (arg1 == (var_a2[3] << 8) + var_a2[4]) {
                    return var_a3 | 0x8000;
                }
                var_a3++;
                break;
        }

        var_a2 += (var_a2[0] << 8) + var_a2[1] + 2;
    }

    return -1;
}

void func_8001DF00_1EB00(HmfLoadData *hmf) {
    u8 *data;
    s16 count;
    s16 count2;
    s16 *coords;
    u8 *colors;
    s32 coordBytes;
    HmfFloatBits scale;
    s32 value;
    s16 i;

    data = D_800DEF74_DFB74;
    count = (data[8] << 8) + data[9];
    hmf->unk14 = count;
    count2 = count;
    if (count2 != 0) {
        coordBytes = count2 << 1;
        coordBytes += count2;
        hmf->unk54 = func_80027154_27D54(coordBytes * 2, D_8010106C_101C6C);
        coords = hmf->unk54;
        hmf->unk58 = func_80027154_27D54(coordBytes, D_8010106C_101C6C);
        colors = hmf->unk58;
        value = data[0xC] << 0x18;
        value += data[0xD] << 0x10;
        value += data[0xE] << 8;
        scale.word = value + data[0xF];
        data += 0x10;
        i = 0;
        if (count2 > 0) {
            do {
                *coords++ = (s16)((f32)(s16)((data[0] << 8) + data[1]) * scale.single);
                data += 2;
                *coords++ = (s16)((f32)(s16)((data[0] << 8) + data[1]) * scale.single);
                data += 2;
                *coords++ = (s16)((f32)(s16)((data[0] << 8) + data[1]) * scale.single);
                data += 2;
                *colors++ = *data++;
                *colors++ = *data++;
                *colors++ = *data++;
                i++;
            } while (i < count);
        }
    }
}

/* MP3 func_800100EC_10CEC (src/hmfload.c) with a third colour per material. */
s16 func_8001E108_1ED08(HmfLoadData *hmf) {
    u8 *records;
    u8 *src;
    HmfData_Unk88_Entry *entry;
    s16 count;
    s16 i;

    count = (D_800DEF80_DFB80[8] << 8) + D_800DEF80_DFB80[9];
    if (count == 0) {
        D_800DEF80_DFB80 = 0;
        return 0;
    }
    hmf->unk1E = count;
    hmf->unk8C = func_80027154_27D54(count * sizeof(HmfData_Unk88_Entry), D_800FA1AA_FADAA);
    records = D_800DEF80_DFB80 + 0xA;
    for (i = 0; i < count; ++i) {
        entry = &hmf->unk8C[i];
        entry->unk00 = i;
        entry->unk0C = 0;
        src = D_800DEF84_DFB84 + (((records[0] << 8) + records[1]) * 4 + 0xA);
        entry->unk01 = ((f32)src[0] > 255.0f) ? 255 : (u32)(f32)src[0];
        entry->unk02 = ((f32)src[1] > 255.0f) ? 255 : (u32)(f32)src[1];
        entry->unk03 = ((f32)src[2] > 255.0f) ? 255 : (u32)(f32)src[2];
        entry->unk04 = src[3];
        src = D_800DEF84_DFB84 + (((records[2] << 8) + records[3]) * 4 + 0xA);
        entry->unk05 = ((f32)src[0] > 255.0f) ? 255 : (u32)(f32)src[0];
        entry->unk06 = ((f32)src[1] > 255.0f) ? 255 : (u32)(f32)src[1];
        entry->unk07 = ((f32)src[2] > 255.0f) ? 255 : (u32)(f32)src[2];
        entry->unk08 = src[3];
        if (entry->unk08 != 255) {
            entry->unk0C |= 1;
            entry->unk0D = entry->unk08;
        } else {
            entry->unk0D = 255;
        }
        src = D_800DEF84_DFB84 + (((records[4] << 8) + records[5]) * 4 + 0xA);
        entry->unk09 = src[0];
        entry->unk0A = src[1];
        entry->unk0B = src[2];
        records += 0xC;
    }
    return count;
}

s16 func_8001E57C_1F17C(HmfLoadData *hmf) {
    u8 *data;
    u8 *colorData;
    HmfData_Unk84_Entry *entry;
    void *temp;
    s16 count;
    s16 i;
    s8 type;

    count = (D_800DEF88_DFB88[8] << 8) + D_800DEF88_DFB88[9];
    hmf->unk88 = func_80027154_27D54(count * sizeof(HmfData_Unk84_Entry), D_800FA1AA_FADAA);
    temp = HuMemAlloc(count * sizeof(s16));
    data = D_800DEF88_DFB88 + 0xA;
    hmf->unk12 = count;
    for (i = 0; i < count; i++) {
        s8 fill;

        entry = &hmf->unk88[i];
        type = data[2];
        entry->unk0[0] = type;
        colorData = D_800DEF84_DFB84 + (((data[3] << 8) + data[4]) * 4 + 0xA);
        if (type == 0x2B) {
            entry->unk5[0] = colorData[0];
            entry->unk5[1] = colorData[1];
            entry->unk5[2] = colorData[2];
            entry->unk5[3] = colorData[3];
        } else {
            entry->unk5[3] = 0;
            entry->unk5[2] = 0;
            entry->unk5[1] = 0;
            entry->unk5[0] = 0;
        }
        switch (data[5]) {
            case 0x2D:
                entry->unk0[1] = 0;
                break;

            case 0x2E:
                entry->unk0[1] = 2;
                break;

            default:
                entry->unk0[1] = 1;
                break;
        }
        switch (data[6]) {
            case 0x2D:
                entry->unk0[2] = 0;
                break;

            case 0x2E:
                entry->unk0[2] = 2;
                break;

            default:
                entry->unk0[2] = 1;
                break;
        }
        entry->unkC = func_8003CF48_3DB48((HmfData *)hmf, (data[0xA] << 8) + data[0xB]);
        fill = -1;
        entry->unk3 = fill;
        entry->unk4 = fill;
        entry->unk9 = 0xFF;
        data += ((data[0] << 8) + data[1]) + 2;
    }
    HuMemFree(temp);
    return count;
}

s16 func_8001E78C_1F38C(HmfLoadData *hmf, u16 motionIndex, void *arg2) {
    u8 *data;
    HmfMotionData *entry;
    s16 count;
    s16 count2;
    s32 value;
    s32 value2;
    s32 value3;
    s16 i;

    data = arg2;
    entry = &hmf->unk84[motionIndex];
    entry->unk00 = count2 = (data[0] << 8) + data[1];
    count = count2;
    entry->unk50 = func_80027154_27D54(count2 * sizeof(s16), D_800FA1AA_FADAA);
    data += 2;
    for (i = 0; i < count; i++) {
        ((s16 *)entry->unk50)[i] = func_8001DE08_1EA08(hmf, (data[0] << 8) + data[1]);
        data += 2;
    }
    entry->unk54 = hmf;
    value = data[0];
    value <<= 0x18;
    value += data[1] << 0x10;
    value += data[2] << 8;
    entry->unk04 = value + data[3];
    value = data[4];
    value <<= 0x18;
    value += data[5] << 0x10;
    value += data[6] << 8;
    entry->unk08 = value + data[7];
    value = data[8];
    value <<= 0x18;
    value += data[9] << 0x10;
    value += data[0xA] << 8;
    entry->unk0C = value + data[0xB];
    data += 0xC;
    value = data[0];
    value <<= 0x18;
    value += data[1] << 0x10;
    value += data[2] << 8;
    entry->unk10 = value + data[3];
    value = data[4];
    value <<= 0x18;
    value += data[5] << 0x10;
    value += data[6] << 8;
    entry->unk14 = value + data[7];
    value = data[8];
    value <<= 0x18;
    value += data[9] << 0x10;
    value += data[0xA] << 8;
    entry->unk18 = value + data[0xB];
    data += 0xC;
    value = data[0];
    value <<= 0x18;
    value += data[1] << 0x10;
    value += data[2] << 8;
    entry->unk1C = value + data[3];
    value = data[4];
    value <<= 0x18;
    value += data[5] << 0x10;
    value += data[6] << 8;
    entry->unk20 = value + data[7];
    value = data[8];
    value <<= 0x18;
    value += data[9] << 0x10;
    value += data[0xA] << 8;
    entry->unk24 = value + data[0xB];
    value2 = entry->unk04;
    value = entry->unk08;
    value3 = entry->unk0C;
    entry->unk28 = value2;
    entry->unk2C = value;
    entry->unk30 = value3;
    value2 = entry->unk10;
    value = entry->unk14;
    value3 = entry->unk18;
    entry->unk34 = value2;
    entry->unk38 = value;
    entry->unk3C = value3;
    value2 = entry->unk1C;
    value = entry->unk20;
    value3 = entry->unk24;
    entry->unk40 = value2;
    entry->unk44 = value;
    entry->unk48 = value3;
    entry->unk4E = 0;
    entry->unk4D = 0;
    entry->unk4C = 0;
    return count;
}

u8* func_8001EA88_1F688(s32 arg0, void* arg1_, void* arg2_) {
    u8* arg1 = arg1_;
    u8* arg2 = arg2_;
    while (arg1 < arg2) {
        if (arg0 == (arg1[0] << 24) + (arg1[1] << 16) + (arg1[2] << 8) + arg1[3]) {
            return arg1;
        }
        arg1 += 4;
        arg1 += (arg1[0] << 24) + (arg1[1] << 16) + (arg1[2] << 8) + arg1[3] + 4;
        arg1 += (u32) arg1 & 1;
    }

    return NULL;
}

void* func_8001EB18_1F718(void* arg0_) {
    u8* arg0 = arg0_;
    arg0 += (arg0[1] << 16) + (arg0[2] << 8) + arg0[3] + 4;
    arg0 += (u32) arg0 & 1;

    return arg0;
}

void func_8001EB48_1F748(HmfLoadData *hmf, s16 objectIndex, s16 linkIndex, s16 faceCount) {
    u8 *record;
    u8 *next;
    HmfFaceRec *faces;
    s16 *p;
    s16 *bounds;
    s16 pointCount;
    u16 flags;
    s16 v;
    s16 count;
    s16 minX;
    s16 minY;
    s16 minZ;
    s16 maxX;
    s16 maxY;
    s16 maxZ;
    s16 i;
    s16 j;

    count = linkIndex;
    if (hmf->unk14 == 0) {
        return;
    }

    hmf->unk64[objectIndex].unk54 = func_80027154_27D54(faceCount * sizeof(HmfFaceRec), D_8010106C_101C6C);
    faces = hmf->unk64[objectIndex].unk54;
    record = D_800DEF78_DFB78 + 0x10;
    for (i = 0; i < linkIndex; i++) {
        if (record[0] == 0x16) {
            next = record + 0x2A;
        } else if (record[0] != 0x35) {
            next = record + 0xC;
        } else {
            next = record + 0x36;
        }
        record = next;
    }

    minX = minY = minZ = 0x7FFF;
    maxX = maxY = maxZ = -0x8000;
    flags = 0;

    for (i = 0; i < faceCount; i++) {
        func_8001EF00_1FB00(&faces[i], record, hmf, &flags);
        if (record[0] == 0x16) {
            pointCount = 3;
        } else if (record[0] == 0x35) {
            pointCount = 4;
        } else {
            pointCount = 2;
        }

        for (j = 0; j < pointCount; j++) {
            p = &((s16 *)hmf->unk54)[faces[i].unk04[j] * 3];
            v = p[0];
            if (minX > v) {
                minX = v;
            }
            if (maxX < v) {
                maxX = v;
            }
            v = p[1];
            if (minY > v) {
                minY = v;
            }
            if (maxY < v) {
                maxY = v;
            }
            v = p[2];
            if (minZ > v) {
                minZ = v;
            }
            if (maxZ < v) {
                maxZ = v;
            }
        }
        switch (record[0]) {
            case 0x35:
                next = record + 0x36;
                break;
            case 0x16:
                next = record + 0x2A;
                break;
            default:
                next = record + 0xC;
                break;
        }
        record = next;
    }

    hmf->unk64[objectIndex].unk50 =
        (flags & 1) ? (hmf->unk64[objectIndex].unk50 | 0x10000) : hmf->unk64[objectIndex].unk50;
    bounds = hmf->unk64[objectIndex].unk42;
    bounds[0] = minX;
    bounds[1] = minY;
    bounds[2] = minZ;
    bounds = hmf->unk64[objectIndex].unk48;
    bounds[0] = maxX;
    bounds[1] = maxY;
    bounds[2] = maxZ;
}

/* MP3 func_80010EB0_11AB0 (src/hmfload.c); MP2's HmfLoadData fields sit 4 bytes later. */
void func_8001EF00_1FB00(HmfFaceRec *arg0, u8 *arg1, HmfLoadData *arg2, u16 *arg3) {
    s32 *values1;
    s32 *values2;
    u8 *colors;
    u8 *attr;
    u16 *coords1;
    u16 *coords2;
    u16 *coords3;
    s16 count;
    s16 i;
    s16 hasColor;
    s16 step;
    s32 temp;
    s32 value;

    switch (arg1[0]) {
        case 0x35:
            count = 4;
            step = 0xC;
            break;
        case 0x16:
            count = 3;
            step = 0xC;
            break;
        default:
            count = 2;
            step = 4;
            break;
    }
    arg0->unk00 = count;
    arg1++;
    /* the file's s and t are float bits, copied as words */
    values1 = (s32*)&arg0->unk0C[0];
    values2 = (s32*)&arg0->unk1C[0];
    i = 0;
    hasColor = 0;
    while (i < count) {
        arg0->unk04[i] = (arg1[0] << 8) + arg1[1];
        arg0->unk2C[i] = arg1[3];
        value = arg1[4];
        value <<= 0x18;
        value += arg1[5] << 0x10;
        value += arg1[6] << 8;
        *values1++ = value + arg1[7];
        value = arg1[8];
        value <<= 0x18;
        value += arg1[9] << 0x10;
        value += arg1[0xA] << 8;
        *values2++ = value + arg1[0xB];
        arg0->unk04[i] = (arg1[0] << 8) + arg1[1];
        if (arg1[3] != 0xFF) {
            temp = arg0->unk04[i];
            colors = arg2->unk58;
            colors[temp * 3 + 0] = colors[temp * 3 + 1] = colors[temp * 3 + 2] = 0;
            hasColor = -1;
        }
        arg1 += step;
        i++;
    }
    arg0->unk30 = (arg1[0] << 8) + arg1[1];
    if (hasColor != 0) {
        arg0->unk00 |= 0x80;
    }
    coords1 = &((u16 *)arg2->unk54)[arg0->unk04[0] * 3];
    coords2 = &((u16 *)arg2->unk54)[arg0->unk04[1] * 3];
    coords3 = &((u16 *)arg2->unk54)[arg0->unk04[2] * 3];
    func_8001F1B8_1FDB8(arg0->unk01, coords1, coords2, coords3);
    if (D_800DEF80_DFB80 != NULL) {
        *arg3 |= arg2->unk8C[arg0->unk30].unk0C;
        if (count == 2) {
            arg0->unk32 = -1;
        } else {
            arg0->unk32 = (arg1[2] << 8) + arg1[3];
            if (arg0->unk32 != -1) {
                attr = (u8 *)arg2->unk88[arg0->unk32].unkC;
                if (((attr[0x1C] - 3) < 2U) || attr[0x1D] == 3) {
                    *arg3 |= 1;
                }
            }
        }
    }
}

/* MP1 func_8001C9F4 (src/1B800.c): face normal from three vertices. */
void func_8001F1B8_1FDB8(s8 *arg0, u16 *arg1, u16 *arg2, u16 *arg3) {
    s16 ax;
    s16 bx;
    s16 ay;
    s16 by;
    s16 az;
    s16 bz;
    f32 nx;
    f32 ny;
    f32 nz;
    f32 scale;

    ax = arg1[0] - arg2[0];
    bx = arg3[0] - arg1[0];
    ay = arg1[1] - arg2[1];
    by = arg3[1] - arg1[1];
    az = arg1[2] - arg2[2];
    bz = arg3[2] - arg1[2];
    nx = ax * by - ay * bx;
    ny = ay * bz - az * by;
    nz = az * bx - ax * bz;
    scale = 127.0f / func_800B1830_B2430(nx * nx + ny * ny + nz * nz);
    if (nx != 0.0f) {
        arg0[0] = nx * scale;
    } else {
        arg0[0] = 0;
    }
    if (ny != 0.0f) {
        arg0[1] = ny * scale;
    } else {
        arg0[1] = 0;
    }
    if (nz != 0.0f) {
        arg0[2] = nz * scale;
    } else {
        arg0[2] = 0;
    }
}

s16 func_8001F380_1FF80(HmfLoadData *hmf, void *arg1, s16 index) {
    u8 *data;
    u8 *src;
    u8 *dst;
    s16 sum;
    s16 i;
    s16 j;
    s16 len;

    data = D_800DEF90_DFB90;
    sum = data[8];
    sum = (sum << 8) + data[9];
    if (sum == 0) {
        ((u8 *)arg1)[0] = 0;
        return 0;
    }
    data += 0xA;
    src = data + sum;
    for (i = 0; i < index; i++) {
        src += data[0];
        data++;
    }
    len = data[0];
    dst = arg1;
    i = 0;
    sum = 0;
    j = 0;
    for (; i < len; i++) {
        if (j >= 0x1B) {
            *dst = 0;
            return sum;
        }
        if (src[0] == 0x2F) {
            dst = arg1;
            sum = 0;
            j = 0;
            src++;
        } else {
            *dst = src[0];
            src++;
            sum += (j + 1) * *dst;
            dst++;
            j++;
        }
    }
    *dst = 0;
    return sum;
}

s16 func_8001F4AC_200AC(u8 *arg0) {
    s32 sum = 0;
    s16 i = 1;
    u8 c = arg0[0];

    while (c != 0 && i < 28) {
        sum += i * c;
        arg0++;
        i++;
        c = arg0[0];
    }
    return sum;
}

s32 func_8001F50C_2010C(HmfLoadData *hmf) {
    u8 *data;
    u8 *src;
    HmfDispData *entry;
    s16 *indices;
    s16 *coords;
    u8 *colors;
    HmfFloatBits scale;
    s32 size;
    s16 dispCount;
    s16 dispIndex;
    s16 vtxCount;
    s16 count;
    s16 j;

    data = hmf->unk34;
    dispCount = 0;

    while (1) {
        data = func_8001EA88_1F688(0x44495350, data, hmf->unk30);
        if (data == NULL) {
            break;
        }
        data = func_8001EB18_1F718(data + 4);
        dispCount++;
    }

    if (dispCount == 0) {
        hmf->unk20 = 0;
        hmf->unkB8 = NULL;
        return 0;
    }

    hmf->unkB8 = func_80027154_27D54(dispCount * sizeof(HmfDispData), D_800FA1AA_FADAA);
    hmf->unk20 = dispCount;
    data = hmf->unk34;
    dispIndex = 0;

    while (1) {
        data = func_8001EA88_1F688(0x44495350, data, hmf->unk30);

        if (data == NULL) {
            break;
        }

        if (data[0xC] == 0x43) {
            entry = &hmf->unkB8[dispIndex];
            entry->unk1E = func_8001F380_1FF80(hmf, entry, (data[8] << 8) + data[9]);
            vtxCount = (data[0xA] << 8) + data[0xB];
            count = vtxCount;
            entry->unk1C = count;
            size = vtxCount * 2;
            indices = func_80027154_27D54(size, D_800FA1AA_FADAA);
            entry->unk28 = indices;
            size += vtxCount;
            coords = func_80027154_27D54(size * 2, D_800FA1AA_FADAA);
            entry->unk2C = coords;
            colors = func_80027154_27D54(size, D_800FA1AA_FADAA);
            entry->unk30 = colors;
            entry->unk20 = (data[0xD] << 8) + data[0xE];
            scale.word = (data[0xF] << 0x18) + (data[0x10] << 0x10) + (data[0x11] << 8) + data[0x12];
            scale.single *= 5.0f;
            entry->unk24 = scale.single;
            src = data + 0x13;
            for (j = 0; j < count; j++) {
                indices[0] = (src[0] << 8) + src[1];
                coords[0] = (s16)((src[2] << 8) + src[3]) * scale.single;
                coords[1] = (s16)((src[4] << 8) + src[5]) * scale.single;
                coords[2] = (s16)((src[6] << 8) + src[7]) * scale.single;
                if (((s8 *)hmf->unk58)[indices[0] * 3 + 0] == 0 && ((s8 *)hmf->unk58)[indices[0] * 3 + 1] == 0 && ((s8 *)hmf->unk58)[indices[0] * 3 + 2] == 0) {
                    colors[0] = colors[1] = colors[2] = 0;
                } else {
                    colors[0] = src[8];
                    colors[1] = src[9];
                    colors[2] = src[0xA];
                }
                indices++;
                coords += 3;
                colors += 3;
                src += 0xB;
            }
        }
        data = func_8001EB18_1F718(data + 4);
        dispIndex++;
    }
    func_8001F8C0_204C0(hmf);
    return 1;
}

s32 func_8001F8C0_204C0(HmfLoadData *hmf) {
    char buf[0x20];
    u8 *data;
    u8 *sub2;
    u8 *cur;
    HmfMtnData *entry;
    s16 id;
    s16 cnt;
    s16 count2;
    s16 mtnCount;
    s16 subCount;
    s32 subCount1;
    s16 i;
    s16 k;
    s16 m;

    data = hmf->unk34;
    mtnCount = 0;
    while (1) {
        data = func_8001EA88_1F688(0x4D544E31, data, hmf->unk30);
        if (data == NULL) {
            break;
        }
        cur = data + 0xD;
        subCount1 = data[0xA];
        for (i = 0; i < subCount1; i++) {
            if (cur[2] == 0xA) {
                mtnCount++;
            }
            cur += ((cur[0] << 8) + cur[1]) + 2;
        }
        data = func_8001EB18_1F718(data + 4);
    }
    if (mtnCount == 0) {
        hmf->unkBC = NULL;
        return 0;
    }
    hmf->unkBC = func_80027154_27D54(mtnCount * sizeof(HmfMtnData), D_800FA1AA_FADAA);
    hmf->unk22 = mtnCount;
    data = hmf->unk34;
    mtnCount = 0;
    while (1) {
        data = func_8001EA88_1F688(0x4D544E31, data, hmf->unk30);
        if (data == NULL) {
            break;
        }
        subCount = data[0xA];
        sub2 = data + 0xD;
        entry = &hmf->unkBC[mtnCount];
        for (i = 0; i < subCount; i++) {
            cur = sub2;
            sub2 += ((cur[0] << 8) + cur[1]) + 2;
            if (cur[2] == 0xA) {
                cur += 3;
                entry->unk00 = (cur[0] << 8) + cur[1];
                cnt = (cur[2] << 8) + cur[3];
                count2 = cnt;
                entry->unk02 = count2;
                entry->unk04 = func_80027154_27D54(cnt * 2, D_800FA1AA_FADAA);
                cur += 4;
                for (k = 0; k < count2; k++) {
                    id = func_8001F380_1FF80(hmf, buf, (cur[0] << 8) + cur[1]);
                    for (m = 0; m < hmf->unk20; m++) {
                        if (id == hmf->unkB8[m].unk1E && func_800B0FD0_B1BD0(hmf->unkB8[m].unk00, buf) == 0) {
                            break;
                        }
                    }
                    if (m == hmf->unk20) {
                        entry->unk04[k] = 0;
                    } else {
                        entry->unk04[k] = m;
                    }
                    cur += 2;
                }
                mtnCount++;
            }
        }
        data = func_8001EB18_1F718(data + 4);
    }
    return 1;
}

void func_8001FBE0_207E0(HmfLoadData *hmf, void *arg1, s16 index) {
    u8 *data;
    HmfMapData *entry;
    s32 value;

    data = arg1;
    entry = &hmf->unkC4[index];
    value = ((data[0] << 0x18) + (data[1] << 0x10)) + (data[2] << 8);
    entry->unk20 = value + data[3];
    value = 0x10;
    value = ((data[4] << 0x18) + (data[5] << value)) + (data[6] << 8);
    entry->unk24 = value + data[7];
    value = ((data[8] << 0x18) + (data[9] << 0x10)) + (data[10] << 8);
    entry->unk28 = value + data[11];
}

/* MP3 func_80011C40_12840 (src/hmfload.c) without the name compare: three map points by id. */
s32 func_8001FC8C_2088C(HmfLoadData *hmf, void *arg1) {
    char buf[0x20];
    u8 *data;
    HmfData_UnkBC *env;
    s16 id;
    s16 m;
    s32 temp1, temp2;

    data = arg1;
    env = hmf->unkC0;
    id = func_8001F380_1FF80(hmf, buf, (data[0] << 8) + data[1]);
    for (m = 0; m < hmf->unk24; m++) {
        if (id == hmf->unkC4[m].unk1C) {
            break;
        }
    }
    if (m == hmf->unk24) {
        return 0;
    }
    env->unk08 = *(f32 *)&hmf->unkC4[m].unk20;
    env->unk0C = *(f32 *)&hmf->unkC4[m].unk24;
    env->unk10 = *(f32 *)&hmf->unkC4[m].unk28;
    env->unk00 = m;
    id = func_8001F380_1FF80(hmf, buf, (data[2] << 8) + data[3]);
    for (m = 0; m < hmf->unk24; m++) {
        if (id == hmf->unkC4[m].unk1C) {
            break;
        }
    }
    if (m == hmf->unk24) {
        return 0;
    }
    env->unk14 = *(f32 *)&hmf->unkC4[m].unk20;
    env->unk18 = *(f32 *)&hmf->unkC4[m].unk24;
    env->unk1C = *(f32 *)&hmf->unkC4[m].unk28;
    env->unk02 = m;
    id = func_8001F380_1FF80(hmf, buf, (data[4] << 8) + data[5]);
    for (m = 0; m < hmf->unk24; m++) {
        if (id == hmf->unkC4[m].unk1C) {
            break;
        }
    }
    if (m == hmf->unk24) {
        return 0;
    }
    env->unk20 = *(f32 *)&hmf->unkC4[m].unk20;
    env->unk24 = *(f32 *)&hmf->unkC4[m].unk24;
    env->unk28 = *(f32 *)&hmf->unkC4[m].unk28;
    env->unk04 = m;
    temp1 = data[6] << 0x18;
    temp1 += data[7] << 0x10;
    temp1 += data[8] << 0x8;
    temp2 = data[9];
    temp1 += temp2;
    temp2 = temp1;
    temp1 = temp2;

    *((s32 *)(&env->unk2C)) = temp1;

    return 1;
}

void func_8001FFCC_20BCC(HmfLoadData *hmf) {
    u8 *data;
    s32 value;

    data = D_800DEF70_DFB70;
    value = data[0xC];
    value <<= 0x18;
    value += data[0xD] << 0x10;
    value += data[0xE] << 8;
    value += data[0xF];
    if (value & 2) {
        D_800C9B74_CA774 = 1;
    } else {
        D_800C9B74_CA774 = 0;
    }
    if (D_800DEF70_DFB70[0x1C] == 0x45) {
        hmf->unkD4 = func_80025884_26484;
        hmf->unkD8 = func_800B2060_B2C60;
    } else {
        hmf->unkD4 = func_800261CC_26DCC;
        hmf->unkD8 = func_800264D8_270D8;
    }
}
