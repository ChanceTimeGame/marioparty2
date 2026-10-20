#include "common.h"
#include "game/malloc.h"
#include "game/data.h"
#include "process.h"

/* func_800409E0 is the boot thread (near MP3 main.c's func_800354A0_360A0); func_80040CF8 is MP1
   src/3BF30.c's func_8003B5EC (clear the frame buffers). */

extern void* D_800CB040_CBC40[];
extern u8 D_800CB04C_CBC4C[];
extern u8 D_800CB05C_CBC5C[];
extern s32 D_800CB0A0_CBCA0;
extern s32 D_800C9E60_CAA60;
extern u32 D_800FDC6C_FE86C;
extern s32 D_800FD848_FE448;
extern OSMesgQueue D_800F9298_F9E98;
extern OSMesgQueue D_800F92B8_F9EB8;
extern u8 D_0041DD30[];

void* func_800B0EF0_B1AF0(void*, s32, s32); /* memset */
void func_8007E2A0_7EEA0(s32, s32);
void func_80040CF8_418F8(s16 arg0);
void func_8001CB00_1D700(void**, s32, s32, void*, void*);
void func_8007BDA0_7C9A0(s32, s32, s32, s32, s32);
void func_8007EA50_7F650(void);
void func_800169AC_175AC(s32, s32);
void func_80088350_88F50(void);
void func_800172F0_17EF0(void);
void func_8007C370_7CF70(void);
void func_8007E4D4_7F0D4(void*, OSMesgQueue*, s32);
void func_80016F54_17B54(void);
void func_8001D184_1DD84(s32);
void func_8001C4B0_1D0B0(void);
void func_8007C184_7CD84(void);
s16 func_8007C058_7CC58(s32, s32, s32);
void func_8001736C_17F6C(void);
void func_8007C094_7CC94(s16);
void func_8007C1D0_7CDD0(void);

void func_800409E0_415E0(void) {
    u32 iVar5;
    s32 stopLooping;
    OSMesg msg;
    OSMesg intrMesgBuf[0x100 + 4];
    OSMesg otherMesgBuf[8 + 4];
    OSMesg* msgTempVar;

    iVar5 = 0;
    stopLooping = FALSE;

    HuMemHeapInitPerm((void*)0x80140000, 0x1A0000);
    HuMemHeapInitTemp((void*)0x80128000, 0x18000);

    if (osTvType == 1) {
        func_8007E2A0_7EEA0(2, 1);
    } else if (osTvType != 1) {
        func_8007E2A0_7EEA0(0x1E, 1);
    } else {
        goto spinloop;
    }

    func_80040CF8_418F8(3);

    if (osTvType == 0) {
        while (TRUE) {}
    }

    D_800F92B2_F9EB2 = 3;
    func_8001CB00_1D700(D_800CB040_CBC40, 3, 2, D_800CB04C_CBC4C, D_800CB05C_CBC5C);
    func_8007BDA0_7C9A0(0, 0x20, 0xD2, 0x20, 0xD4);
    func_8007EA50_7F650();
    func_800169AC_175AC(4, 1);
    func_80088350_88F50();
    func_800172F0_17EF0();
    func_8007C370_7CF70();
    DataInit(D_0041DD30);
    HuPrcInit();

    msgTempVar = &intrMesgBuf[4];
    osCreateMesgQueue(&D_800F9298_F9E98, msgTempVar, 0x100);
    func_8007E4D4_7F0D4((void*)&intrMesgBuf, &D_800F9298_F9E98, 1);
    msgTempVar = &otherMesgBuf[4];
    osCreateMesgQueue(&D_800F92B8_F9EB8, msgTempVar, 8);
    func_8007E4D4_7F0D4((void*)&otherMesgBuf, &D_800F92B8_F9EB8, 2);

    func_80016F54_17B54();
    osViSetSpecialFeatures(2);
    func_8001D184_1DD84(2);
    HuPrcCreate(func_8001C4B0_1D0B0, 1, 0, 0);

    while (!stopLooping) {
        if (osRecvMesg(&D_800F92B8_F9EB8, &msg, OS_MESG_NOBLOCK) != -1) {
            if (D_800FDC6C_FE86C) {
            }
            break;
        }

        osRecvMesg(&D_800F9298_F9E98, &msg, OS_MESG_BLOCK);
        switch ((s32)msg) {
            case 1: {
                s32 temp_s0;
                s16 temp_s1;

                func_8007C184_7CD84();
                temp_s1 = func_8007C058_7CC58(0xC8, 0, 0);
                if (D_800FDC6C_FE86C - iVar5 >= 2) {
                    iVar5 = D_800FDC6C_FE86C;
                    if (D_800CB0A0_CBCA0 < D_800F92B2_F9EB2) {
                        func_80016F54_17B54();
                        func_8001736C_17F6C();
                        temp_s0 = D_800C9E60_CAA60;
                        HuPrcCall(1);
                        if (temp_s0 != D_800C9E60_CAA60) {
                            D_800CB0A0_CBCA0++;
                        }
                        func_8007C094_7CC94(temp_s1);
                        func_8007C1D0_7CDD0();
                    }
                }
            } break;

            case 777:
                D_800CB0A0_CBCA0--;
                D_800FD848_FE448++;
                break;

            case 2:
                stopLooping = TRUE;
                break;
        }
    }

spinloop:
    while (TRUE) {}
}

void func_80040CF8_418F8(s16 arg0) {
    s16 i;

    for (i = 0; i < arg0; i++) {
        func_800B0EF0_B1AF0(D_800CB040_CBC40[i], 0, 0x25800);
    }
}
