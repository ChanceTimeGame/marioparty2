#include "common.h"

/* Audio manager thread (N64 SDK audiomgr.c, MP1 src/138F0.c) and controller reads (MP1
   src/engine/pad.c). */

#include "PR/libaudio.h"
#include "PR/sptask.h"
#include "game/pad.h"
#include "game/rsp.h"
#include "game/si.h"

#define PAD_COUNT (4)

typedef struct AMConfig {
    /* 0x00 */ char unk_00[0x1C];
    /* 0x1C */ s32 outputRate;
    /* 0x20 */ s32 maxVoices;
    /* 0x24 */ s32 maxUpdates;
    /* 0x28 */ char unk_28[0x4];
    /* 0x2C */ s32* params; /* NULL: no effect; else a custom effect (MP1 has fxType here) */
    /* 0x30 */ s32 maxACMDSize;
    /* 0x34 */ s32 numDMABuffers;
    /* 0x38 */ s32 dmaBufferLength;
    /* 0x3C */ s32 frameLag;
    /* 0x40 */ s32 framesPerField;
    /* 0x44 */ s32 fieldRate;
    /* 0x48 */ s32 extraSamples; /* added to the frame size for the buffers and each frame */
    /* 0x4C */ char unk_4C[0x10];
    /* 0x5C */ OSPri pri;
    /* 0x60 */ OSId id;
    /* 0x64 */ s32 unk_64;
    /* 0x68 */ s32 unk_68;
} AMConfig;

typedef struct AMTask {
    /* 0x00 */ OSTask list;
    /* 0x40 */ OSMesgQueue* msgQ;
    /* 0x44 */ OSMesg msg;
} AMTask; /* size = 0x48 */

struct AudioInfo;

typedef struct AMAudioMsg {
    /* 0x00 */ s16 type;
    /* 0x04 */ struct AudioInfo* done;
} AMAudioMsg;

typedef struct AudioInfo {
    /* 0x00 */ s16* data;
    /* 0x04 */ s16 frameSamples;
    /* 0x08 */ AMTask task;
    /* 0x50 */ AMAudioMsg msg;
} AudioInfo; /* size = 0x58 */

typedef struct AMAudioMgr {
    /* 0x000 */ Acmd* ACMDList[2];
    /* 0x008 */ AudioInfo* audioInfo[3];
    /* 0x018 */ OSThread thread;
    /* 0x1C8 */ OSMesgQueue audioFrameMsgQ;
    /* 0x1E0 */ OSMesg audioFrameMsgBuf[8];
    /* 0x200 */ OSMesgQueue audioReplyMsgQ;
    /* 0x218 */ OSMesg audioReplyMsgBuf[8];
    /* 0x238 */ ALGlobals g;
} AMAudioMgr; /* size = 0x288 */

typedef struct DMABuffer {
    /* 0x00 */ ALLink node;
    /* 0x08 */ u32 startAddr;
    /* 0x0C */ u32 lastFrame;
    /* 0x10 */ char* ptr;
} DMABuffer; /* size = 0x14 */

typedef struct DMAState {
    /* 0x00 */ DMABuffer* firstUsed;
    /* 0x04 */ DMABuffer* firstFree;
} DMAState;

typedef struct {
    /* 0x00 */ OSContPad pad[PAD_COUNT];
} pad_unk; /* sizeof = 0x18 */

/* Scheduler client (0x10 bytes), followed directly by the 0x2000-byte audio thread stack. */
extern u8 D_800D58F0_D64F0[];
extern OSMesgQueue* D_800D7900_D8500;
extern AMAudioMgr D_800D7908_D8508;
extern DMAState D_800D7B90_D8790;
extern u32 D_800D7B98_D8798;
extern s32 D_800D7B9C_D879C; /* nextDMA */
extern s32 D_800D7BA0_D87A0; /* DMA buffer length */
extern u32 D_800D7BA4_D87A4; /* frame lag */
extern s32 D_800D7BA8_D87A8; /* curAcmdList */
extern u32 D_800D7BAC_D87AC; /* minFrameSize */
extern u32 D_800D7BB0_D87B0; /* maxFrameSize */
extern u32 D_800D7BB4_D87B4; /* frameSize */
extern s32 D_800D7BB8_D87B8; /* AMConfig.extraSamples */
extern s32 D_800D8038_D8C38;
extern OSMesgQueue D_800D7F80_D8B80;
extern OSMesg D_800D7F98_D8B98[];
extern OSMesgQueue D_800F8F40_F9B40;
extern u64 D_800D1480_D2080[]; /* aspMainDataStart */

void* func_8000EC10_F810(s32 size);
void func_8000FEFC_10AFC(void);
void func_80016620_17220(void);
ALDMAproc func_80016608_17208(void* state);
void func_8001679C_1739C(AMTask* t, AMAudioMsg* msg, Acmd* cmdp);
void func_80010070_10C70(void);
void func_800148C4_154C4(void);
void func_80014A60_15660(void);
u32 func_80016320_16F20(AudioInfo* info, AudioInfo* lastInfo);
void func_8001644C_1704C(AudioInfo* info);
s32 func_80016454_17054(s32 addr, s32 len, void* state);
void func_80016734_17334(s32 arg0, s32 remove);
void func_800161D4_16DD4(void* arg);
void func_8007E4D4_7F0D4(void*, OSMesgQueue*, s32);
void func_8007E560_7F160(void*);

extern pad_unk D_800D8040_D8C40[8];
extern s16 D_800D8180_D8D80;
extern s16 D_800D8182_D8D82;
extern s16 D_800D8184_D8D84;
extern u8 D_800D8186_D8D86[];
extern u8 D_800D818A_D8D8A[];
extern s8 D_800D818E_D8D8E;
extern s8 D_800D818F_D8D8F;
extern u32 D_800D8190_D8D90;
extern s16 D_800D819C_D8D9C;
extern unkfunc_8007EE0C D_800D8100_D8D00[];
extern OSMesgQueue D_800D81A0_D8DA0;
extern OSMesgQueue D_800FA5E0_FB1E0;
extern OSMesg D_800D81B8_D8DB8;
extern u16 D_800F8700_F9300[4];
extern s8 ContStkX[4];
extern u16 D_800FC9BE_FD5BE[4];
extern u16 D_800FD410_FE010[4];
extern s16 D_800FD468_FE068[4];
extern s16 gNumOfControllers;
extern s8 ContStkY[4];
extern s8 D_800FA700_FB300[PAD_COUNT][8];
extern s8 D_80101310_101F10[PAD_COUNT][8];
extern s16 D_80101500_102100;

s32 func_80016840_17440(u16* arg0);
s32 func_80016A44_17644(s32 arg0);
void func_80016BBC_177BC(s8 arg0, s8 arg1);
s16 func_80016BD0_177D0(void);
void func_80017228_17E28(void);
void func_80017244_17E44(void);
void func_80017294_17E94(void);
void func_8007EB8C_7F78C(functionListEntry* entry, s16 type, void* func);
void func_8007EC68_7F868(void* entry);

s32 func_80015DB0_169B0(AMConfig* amc, ALHeap* heap) {
    ALSynConfig c;
    f32 fsize;
    s32 i;
    DMABuffer* dmaBuffs;

    c.outputRate = osAiSetFrequency(amc->outputRate);
    D_800D7BB8_D87B8 = amc->extraSamples;
    fsize = (f32) amc->framesPerField * c.outputRate / (f32) amc->fieldRate;
    D_800D7BB4_D87B4 = (s32) fsize;
    if (D_800D7BB4_D87B4 < fsize) {
        D_800D7BB4_D87B4++;
    }
    if (D_800D7BB4_D87B4 & 0xF) {
        D_800D7BB4_D87B4 = (D_800D7BB4_D87B4 & ~0xF) + 0x10;
    }
    D_800D7BAC_D87AC = D_800D7BB4_D87B4 - 0x10;
    D_800D7BB0_D87B0 = D_800D7BB4_D87B4 + D_800D7BB8_D87B8 + 0x10;
    if (amc->params != NULL) {
        c.fxType = AL_FX_CUSTOM;
        c.params = amc->params;
    } else {
        c.fxType = AL_FX_NONE;
        c.params = NULL;
    }
    c.maxVVoices = c.maxPVoices = amc->maxVoices;
    c.maxUpdates = amc->maxUpdates;
    c.dmaproc = (ALDMANew) func_80016608_17208;
    c.heap = heap;
    c.maxFXbusses = 0;
    alInit(&D_800D7908_D8508.g, &c);
    D_800D7BA8_D87A8 = 0;
    D_800D7B9C_D879C = 0;
    D_800D7B98_D8798 = 0;
    D_800D7BA0_D87A0 = amc->dmaBufferLength;
    D_800D7BA4_D87A4 = amc->frameLag;
    dmaBuffs = func_8000EC10_F810(amc->numDMABuffers * sizeof(DMABuffer));
    if (dmaBuffs == NULL) {
        return 1;
    }
    dmaBuffs[amc->numDMABuffers - 1].node.next = NULL;
    dmaBuffs[0].node.next = NULL;
    dmaBuffs[0].node.prev = NULL;
    for (i = 0; i < amc->numDMABuffers - 1; i++) {
        alLink(&dmaBuffs[i + 1].node, &dmaBuffs[i].node);
        if ((dmaBuffs[i].ptr = func_8000EC10_F810(D_800D7BA0_D87A0)) == NULL) {
            return 1;
        }
    }
    if ((dmaBuffs[i].ptr = func_8000EC10_F810(D_800D7BA0_D87A0)) == NULL) {
        return 1;
    }
    D_800D7B90_D8790.firstUsed = NULL;
    D_800D7B90_D8790.firstFree = dmaBuffs;
    D_800D8038_D8C38 = amc->unk_68;
    for (i = 0; i < 2; i++) {
        if ((D_800D7908_D8508.ACMDList[i] = func_8000EC10_F810(amc->maxACMDSize * sizeof(Acmd))) == NULL) {
            return 2;
        }
    }
    for (i = 0; i < 3; i++) {
        if ((D_800D7908_D8508.audioInfo[i] = func_8000EC10_F810(sizeof(AudioInfo))) == NULL) {
            return 3;
        }
        D_800D7908_D8508.audioInfo[i]->msg.type = 0;
        D_800D7908_D8508.audioInfo[i]->msg.done = D_800D7908_D8508.audioInfo[i];
        D_800D7908_D8508.audioInfo[i]->data = func_8000EC10_F810(D_800D7BB0_D87B0 * 4);
        if (D_800D7908_D8508.audioInfo[i]->data == NULL) {
            return 4;
        }
    }
    return 0;
}

void func_800160FC_16CFC(AMConfig* amc) {
    osCreateMesgQueue(&D_800D7908_D8508.audioReplyMsgQ, D_800D7908_D8508.audioReplyMsgBuf, 8);
    osCreateMesgQueue(&D_800D7F80_D8B80, D_800D7F98_D8B98, 0x28);
    func_80016734_17334(amc->unk_64, 0);
    osCreateThread(&D_800D7908_D8508.thread, amc->id, func_800161D4_16DD4, NULL, D_800D58F0_D64F0 + 0x2010, amc->pri);
    osStartThread(&D_800D7908_D8508.thread);
}

INCLUDE_ASM("asm/nonmatchings/169B0", func_80016190_16D90);

void func_800161D4_16DD4(void* arg) {
    OSMesg msg;
    AMAudioMsg* reply;
    s32 done = 0;
    AudioInfo* lastInfo = NULL;

    do {
        osRecvMesg(&D_800D7908_D8508.audioFrameMsgQ, &msg, OS_MESG_BLOCK);
        switch ((u32)msg) {
            case 1:
                if (func_80016320_16F20(D_800D7908_D8508.audioInfo[D_800D7B98_D8798 % 3], lastInfo)) {
                    osRecvMesg(&D_800D7908_D8508.audioReplyMsgQ, (OSMesg*)&reply, OS_MESG_BLOCK);
                    func_8001644C_1704C(reply->done);
                    lastInfo = reply->done;
                    func_8000FEFC_10AFC();
                    func_800148C4_154C4();
                }
                break;
            case 2:
                done = 1;
                func_80010070_10C70();
                func_80014A60_15660();
                break;
            case 10:
                done = 1;
                break;
        }
    } while (!done);
    alClose(&D_800D7908_D8508.g);
}

u32 func_80016320_16F20(AudioInfo* info, AudioInfo* lastInfo) {
    s32 cmdLen;
    s16* audioPtr;
    Acmd* cmdp;
    AMTask* t;

    func_80016620_17220();
    audioPtr = (s16*) osVirtualToPhysical(info->data);
    if (lastInfo != NULL) {
        osAiSetNextBuffer(lastInfo->data, lastInfo->frameSamples << 2);
    }
    info->frameSamples = ((D_800D7BB4_D87B4 - (osAiGetLength() >> 2) + D_800D7BB8_D87B8) & ~0xF) + 0x10;
    if ((u32) info->frameSamples < D_800D7BAC_D87AC) {
        info->frameSamples = D_800D7BAC_D87AC;
    }
    cmdp = alAudioFrame(D_800D7908_D8508.ACMDList[D_800D7BA8_D87A8], &cmdLen, audioPtr, info->frameSamples);
    t = &info->task;
    if (cmdLen == 0) {
        return 0;
    }
    func_8001679C_1739C(t, &info->msg, cmdp);
    osSendMesg(D_800D7900_D8500, t, OS_MESG_BLOCK);
    D_800D7BA8_D87A8 ^= 1;
    return 1;
}

void func_8001644C_1704C(AudioInfo* info) {
}

INCLUDE_ASM("asm/nonmatchings/169B0", func_80016454_17054);

ALDMAproc func_80016608_17208(void* state) {
    *(DMAState**)state = &D_800D7B90_D8790;
    return (ALDMAproc)func_80016454_17054;
}

INCLUDE_ASM("asm/nonmatchings/169B0", func_80016620_17220);

void func_80016734_17334(s32 arg0, s32 remove) {
    if (remove) {
        func_8007E560_7F160(D_800D58F0_D64F0);
        return;
    }
    osCreateMesgQueue(&D_800D7908_D8508.audioFrameMsgQ, D_800D7908_D8508.audioFrameMsgBuf, 8);
    D_800D7900_D8500 = &D_800F8F40_F9B40;
    func_8007E4D4_7F0D4(D_800D58F0_D64F0, &D_800D7908_D8508.audioFrameMsgQ, 3);
}

void func_8001679C_1739C(AMTask* t, AMAudioMsg* msg, Acmd* cmdp) {
    t->msgQ = &D_800D7908_D8508.audioReplyMsgQ;
    t->msg = msg;
    t->list.t.data_ptr = (u64*)D_800D7908_D8508.ACMDList[D_800D7BA8_D87A8];
    t->list.t.data_size = (cmdp - D_800D7908_D8508.ACMDList[D_800D7BA8_D87A8]) * sizeof(Acmd);
    t->list.t.type = 2; /* M_AUDTASK */
    t->list.t.ucode_boot = D_800B8590_B9190;
    t->list.t.ucode_boot_size = (u32)D_800B8660_B9260 - (u32)D_800B8590_B9190;
    t->list.t.flags = 0;
    t->list.t.ucode = (u64*)aspMainTextStart;
    t->list.t.ucode_data = D_800D1480_D2080;
    t->list.t.ucode_data_size = 0x800;
    t->list.t.dram_stack = NULL;
    t->list.t.dram_stack_size = 0;
    t->list.t.output_buff = NULL;
    t->list.t.output_buff_size = 0;
    t->list.t.yield_data_ptr = NULL;
    t->list.t.yield_data_size = 0;
}

s32 func_80016840_17440(u16* arg0) {
    OSContStatus status[PAD_COUNT];
    u8 pattern;
    s16 index;

    osContInit(&D_800FA5E0_FB1E0, &pattern, status);
    D_800D8184_D8D84 = 0;
    D_800D8182_D8D82 = 0;
    D_800D8180_D8D80 = 0;
    gNumOfControllers = 0;
    for (index = 0; index < PAD_COUNT; index++) {
        if ((pattern >> index) & 1) {
            if (!(status[index].errno & 8)) {
                gNumOfControllers++;
                if (gNumOfControllers == arg0[0]) {
                    break;
                }
            }
        }
        ContBtn[index] = ContBtnTrg[index] = D_800F8700_F9300[index] = D_800FD410_FE010[index] = 0;
        D_800FC9BE_FD5BE[index] = D_800FD468_FE068[index] = 0;
        ContStkY[index] = 0;
        ContStkX[index] = 0;
        D_800D818A_D8D8A[index] = 0;
    }
    osContSetCh(arg0[0]);
    return 0;
}

s16 func_800169AC_175AC(s16 arg0, s32 arg1) {
    unkfunc_8007EE0C sp10;
    s16 sp20;

    sp20 = arg0;
    func_8007EE0C_7FA0C(&sp10, (void*)func_80016840_17440, (void*)&sp20, 1);
    D_800D819C_D8D9C = 0;
    if (arg1 & 1) {
        func_80017244_17E44();
    }
    func_80016BBC_177BC(0x46, 0x46);
    osCreateMesgQueue(&D_800D81A0_D8DA0, &D_800D81B8_D8DB8, 1);
    osSendMesg(&D_800D81A0_D8DA0, NULL, 1);
    return gNumOfControllers;
}

s32 func_80016A44_17644(s32 arg0) {
    osRecvMesg(&D_800D81A0_D8DA0, 0, 1);
    if (D_800D8180_D8D80 < 8) {
        osSendMesg(&D_800D81A0_D8DA0, 0, 1);

        osContStartReadData(&D_800FA5E0_FB1E0);
        osRecvMesg(&D_800FA5E0_FB1E0, 0, 1);

        osContGetReadData(D_800D8040_D8C40[D_800D8184_D8D84].pad);

        osRecvMesg(&D_800D81A0_D8DA0, 0, 1);

        D_800D8180_D8D80++;
        D_800D8184_D8D84++;
        if (D_800D8184_D8D84 >= 8) {
            D_800D8184_D8D84 = 0;
        }
    }
    osSendMesg(&D_800D81A0_D8DA0, 0, 1);

    return 0;
}

void func_80016B44_17744(void) {
    osRecvMesg(&D_800D81A0_D8DA0, NULL, 1);
    if (D_800D8180_D8D80 < 8) {
        func_8007EE0C_7FA0C(&D_800D8100_D8D00[D_800D8184_D8D84], (void*)&func_80016A44_17644, 0, 0);
    }
    osSendMesg(&D_800D81A0_D8DA0, NULL, 1);
}

INCLUDE_ASM("asm/nonmatchings/169B0", func_80016BBC_177BC);

s16 func_80016BD0_177D0(void)
{
  s16 count;
  s16 i;
  OSContPad *slot;
  u16 btn;
  osRecvMesg(&D_800D81A0_D8DA0, 0, 1);
  count = D_800D8180_D8D80;
  if (count != 0)
  {
    D_800D8180_D8D80 = count - 1;
    slot = D_800D8040_D8C40[D_800D8182_D8D82].pad;
    if ((++D_800D8182_D8D82) >= 8)
    {
      D_800D8182_D8D82 = 0;
    }
    for (i = 0; i < 4; i++)
    {
      D_800D818A_D8D8A[i] = slot[i].errno != 0x8;
      btn = (ContBtn[i] = slot[i].button);
      ContStkX[i] = slot[i].stick_x;
      D_800FC9BE_FD5BE[i] = ContStkX[i];
      ContStkY[i] = slot[i].stick_y;
      D_800FD468_FE068[i] = ContStkY[i];
      ContBtnTrg[i] = btn & (btn ^ D_800F8700_F9300[i]);
      if (D_800F8700_F9300[i] == btn)
      {
        if ((--D_800D8186_D8D86[i]) == 0)
        {
          D_800FD410_FE010[i] = btn;
          D_800D8186_D8D86[i] = 10;
        }
        else
        {
          D_800FD410_FE010[i] = 0;
        }
      }
      else
      {
        D_800FD410_FE010[i] = ContBtnTrg[i];
        D_800D8186_D8D86[i] = 30;
      }
      if (((u8) (ContStkX[i] + 9)) < 19)
      {
        ContStkX[i] = 0;
      }
      else
        if (ContStkX[i] > D_800D818E_D8D8E)
      {
        ContStkX[i] = D_800D818E_D8D8E;
      }
      else
        if (ContStkX[i] < (-D_800D818E_D8D8E))
      {
        ContStkX[i] = -D_800D818E_D8D8E;
      }
      if (((u8) (ContStkY[i] + 9)) < 19)
      {
        ContStkY[i] = 0;
      }
      else
        if (ContStkY[i] > D_800D818F_D8D8F)
      {
        ContStkY[i] = D_800D818F_D8D8F;
      }
      else
        if (ContStkY[i] < (-D_800D818F_D8D8F))
      {
        ContStkY[i] = -D_800D818F_D8D8F;
      }
      D_800F8700_F9300[i] = btn;
    }

  }
  osSendMesg(&D_800D81A0_D8DA0, 0, 1);
  return count;
}

s16 func_80016F54_17B54(void) {
    u16 trg[PAD_COUNT];
    u16 rep[PAD_COUNT];
    s16 i;
    s16 n = 0;

    if (func_80016BD0_177D0() > 0) {
        for (i = 0; i < PAD_COUNT; i++) {
            trg[i] = ContBtnTrg[i];
            rep[i] = D_800FD410_FE010[i];
            D_800FC9BE_FD5BE[i] = ContStkX[i];
            D_800FD468_FE068[i] = ContStkY[i];
            D_800FA700_FB300[i][n] = ContStkX[i];
            D_80101310_101F10[i][n] = ContStkY[i];
        }
        n++;
        while (func_80016BD0_177D0() != 0) {
            for (i = 0; i < PAD_COUNT; i++) {
                trg[i] |= ContBtnTrg[i];
                rep[i] |= D_800FD410_FE010[i];
                D_800FC9BE_FD5BE[i] += ContStkX[i];
                D_800FD468_FE068[i] += ContStkY[i];
                D_800FA700_FB300[i][n] = ContStkX[i];
                D_80101310_101F10[i][n] = ContStkY[i];
            }
            n++;
        }
        for (i = 0; i < PAD_COUNT; i++) {
            ContBtnTrg[i] = trg[i];
            D_800FD410_FE010[i] = rep[i];
        }
    }
    D_80101500_102100 = n;
    return n;
}

void func_80017228_17E28(void) {
    func_80016A44_17644(0);
}

void func_80017244_17E44(void) {
    if (D_800D819C_D8D9C != 0) {
        func_80017294_17E94();
    }
    func_8007EB8C_7F78C((functionListEntry*) &D_800D8190_D8D90, 0, func_80017228_17E28);
    D_800D819C_D8D9C = 1;
}

void func_80017294_17E94(void) {
    if (D_800D819C_D8D9C != 0) {
        func_8007EC68_7F868(&D_800D8190_D8D90);
    }
    D_800D819C_D8D9C = 0;
}

s32 HuGetPadInserted(s16 arg0) {
    return D_800D818A_D8D8A[arg0];
}
