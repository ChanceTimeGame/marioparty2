#include "common.h"
#include "game/malloc.h"

/* Board background (HVQ tiles streamed by two threads) and the board camera. C from MP1 src/48D90.c
   and MP3 ovl_80_shared_board FA250.c / ovl_81_name CCD20.c (their copies of the same code); the
   rest have no reference or differ (near) and stay asm. MP1's unk20 is MP3's OverlayBgEntry. */

#define SlideReadUint(buffer, src)    \
    do {                              \
        (buffer) = ((*src++) << 24);  \
        (buffer) += ((*src++) << 16); \
        (buffer) += ((*src++) << 8);  \
        (buffer) += (*src++);         \
    } while (0)

typedef struct Vec2fxy {
    f32 x;
    f32 y;
} Vec2fxy;

typedef struct HVQHeader {
    /* 0x00 */ s32 allocSize;
    /* 0x04 */ u8* unk_04;
    /* 0x08 */ char unk_08[8];
} HVQHeader; // size 0x10

typedef struct UnkModelStruct {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ f32 unk30;
    /* 0x34 */ f32 unk34;
    /* 0x38 */ f32 unk38;
} UnkModelStruct; // size 0x3C

typedef struct OverlayBgEntry {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ void* unk4;   /* MP1 data: the decoded tile */
    /* 0x08 */ void* unk_08; /* MP1 archive: the DMA buffer */
    /* 0x0C */ s32 unkC;     /* MP1 dirTblSize: DMA size */
    /* 0x10 */ u32 unk10;    /* MP1 bytes: ROM source */
} OverlayBgEntry; // size 0x14

extern s32* D_800CC200_CCE00;
extern u32* D_800CC204_CCE04;
extern UnkModelStruct* D_800CC208_CCE08;
extern s8 D_800CC20C_CCE0C;
extern f32 D_800CC210_CCE10;
extern f32 D_800CC214_CCE14;
extern f32 D_800CC218_CCE18;
extern Gfx D_800CC228_CCE28[];
extern u32 D_800DF9B0_E05B0;
extern s32 D_800DF9B4_E05B4;
extern u32 D_800DF9B8_E05B8;
extern f32 D_800DF9BC_E05BC;
extern u16 D_800DF9C0_E05C0;
extern s16 D_800DF9C2_E05C2;
extern s16 D_800DF9C4_E05C4;
extern s16 D_800DF9C6_E05C6;
extern s16 D_800DF9C8_E05C8;
extern u8* D_800DF9CC_E05CC;
extern OverlayBgEntry D_800DF9D8_E05D8[50];
extern OverlayBgEntry* D_800DFDC0_E09C0[6][6];
extern u8* D_800DFE50_E0A50;
extern OSMesgQueue D_800DFE68_E0A68;
extern OSMesg D_800DFE80_E0A80;
extern OSThread D_800DFF48_E0B48;
extern OSThread D_800E0900_E1500;
extern OSPri D_800E0AB0_E16B0;
extern OSMesgQueue D_800E12C0_E1EC0;
extern OSMesg D_800E12D8_E1ED8;
extern OSMesgQueue D_800E13A0_E1FA0;
extern OSMesg D_800E13B8_E1FB8;
extern OSMesgQueue D_800E1480_E2080;
extern OSMesg D_800E1498_E2098;
extern Vec2fxy D_800E18A0_E24A0;
extern f32 D_800E18A8_E24A8[2];
extern Process* D_800E18B0_E24B0;
extern Process* D_800E18B4_E24B4;
extern f32 D_800E18B8_E24B8;
extern f32 D_800E18BC_E24BC;
extern Vec D_800FDC74_FE874;
extern Vec D_800FDC88_FE888;
extern Vec D_80101060_101C60;
extern u8 D_01164160[];

void Hu3DCam3DToScreen(s16 camIndex, Vec* worldPos, Vec2fxy* outPos);
void Hu3DCamSetPositionOrientation(s16 camIndex, Vec* pos, Vec* at, Vec* up);
void Hu3DCamUpdateMtx(s16 camIndex);
void CameraViewportSet(s16 camIndex, Vec* arg1, Vec* arg2);
void* HuMemAlloc(s32 size);
void HuMemFree(void* data);
void HuVecCopyXYZ(Vec* out, f32 x, f32 y, f32 z);
f32 HuVecDistance(Vec* a, Vec* b);
f32 HuVecGetLength3F(Vec* vec);
void HuVecMulScalar(Vec*, f32, Vec*);
void MBVecNormalize(Vec*);
void MBDBackCreate(omObjData*, s32);
void MBBackOffsetSet(s16, s16);
s32 dmaRead(u32 src, u8* dest, s32 size);
void func_8002D018_2DC18(s32, void* func);
void func_800512F8_51EF8(void*);
void func_800514F0_520F0(void);
OverlayBgEntry* func_800518B8_524B8(u16);
void func_80051BCC_527CC(Gfx**, void*, s16, s16);
void func_80053DEC_549EC(void);
s16 func_8007C058_7CC58(u8, u8, u8);
void func_8007C094_7CC94(s16);
void func_800517C0_523C0(void);
void func_80053200_53E00(void);
void func_80051510_52110(void);
void func_80051664_52264(void);
void func_800513FC_51FFC(void);
void func_8005159C_5219C(void);
void func_80051720_52320(void);
u16 func_80051834_52434(s32, s32);


void func_80050A30_51630(u8* arg0) {
    HVQHeader* temp_v0;
    s32* temp_v0_2;
    u32 temp_s0;

    D_800DF9B0_E05B0 = (u32)arg0;
    temp_v0 = HuMemMemoryAllocTemp(sizeof(HVQHeader));
    dmaRead((u32)arg0, (u8*)temp_v0, sizeof(HVQHeader));
    D_800DF9B4_E05B4 = temp_v0->allocSize;
    HuMemMemoryFreeTemp(temp_v0);
    temp_s0 = D_800DF9B4_E05B4 * 4;
    temp_v0_2 = HuMemMemoryAllocTemp(temp_s0);
    D_800CC200_CCE00 = temp_v0_2;
    dmaRead((u32)(arg0 + 4), (u8*)temp_v0_2, temp_s0);
    D_800DF9CC_E05CC = HuMemMemoryAllocTemp(0x300); //TODO: hardcoded size
    D_800CC208_CCE08 = NULL;
}

INCLUDE_ASM("asm/nonmatchings/51630", func_80050AD4_516D4);

void func_80050AE0_516E0(void) {
    if (D_800CC200_CCE00 != NULL) {
        HuMemMemoryFreeTemp(D_800CC200_CCE00);
        D_800CC200_CCE00 = NULL;
        HuMemMemoryFreeTemp(D_800DF9CC_E05CC);
    }
}

INCLUDE_ASM("asm/nonmatchings/51630", MBDBackCreate);

void func_80050E00_51A00(s32 obj) {
    MBDBackCreate((omObjData*)obj, 1);
}

void MBDBackKill(void) {
    if (D_800CC204_CCE04 != NULL) {
        HuMemMemoryFreeTemp(D_800CC204_CCE04);
        D_800CC204_CCE04 = NULL;
        HuMemMemoryFreeTemp(D_800CC208_CCE08);
        HuMemMemoryFreeTemp(D_800DFE50_E0A50);
        func_8002D018_2DC18(0, 0);
        func_800517C0_523C0();
        func_80053200_53E00();
    }
}

INCLUDE_ASM("asm/nonmatchings/51630", MBBackOffsetSet);

u16 MBDBackPosClamp(Vec2fxy* arg0, f32 arg1) {
    u16 var_v1;

    var_v1 = 0;
    if (arg0->x <= (((-D_800DF9C6_E05C6 + 160.0f) / arg1) + 160.0f)) {
        arg0->x = ((-D_800DF9C6_E05C6 + 160.0f) / arg1) + 160.0f;
        var_v1 = 1;
    }
    if (((D_800DF9C6_E05C6 - 160.0f) / arg1) + 160.0f + ((320.0f / arg1) - (320.0f / (arg1 * D_800CC210_CCE10))) <= arg0->x) {
        arg0->x = ((D_800DF9C6_E05C6 - 160.0f) / arg1) + 160.0f + ((320.0f / arg1) - (320.0f / (arg1 * D_800CC210_CCE10)));
        var_v1 |= 2;
    }
    if (arg0->y <= ((-D_800DF9C8_E05C8 + 120.0f) / arg1) + 120.0f) {
        arg0->y = ((-D_800DF9C8_E05C8 + 120.0f) / arg1) + 120.0f;
        var_v1 |= 4;
    }
    if (((D_800DF9C8_E05C8 - 120.0f) / arg1) + 120.0f + ((240.0f / arg1) - (240.0f / (arg1 * D_800CC210_CCE10))) <= arg0->y) {
        arg0->y = ((D_800DF9C8_E05C8 - 120.0f) / arg1) + 120.0f + ((240.0f / arg1) - (240.0f / (arg1 * D_800CC210_CCE10)));
        var_v1 |= 8;
    }
    return var_v1;
}

void func_80051020_51C20(u16 arg0) {
    s16 var_v0;

    if (arg0) {
        var_v0 = (u16) D_800DF9C0_E05C0 | 1;
    } else {
        var_v0 = (u16) D_800DF9C0_E05C0 & 0xFFFE;
    }
    D_800DF9C0_E05C0 = var_v0;
}

void func_80051054_51C54(void) {
    OverlayBgEntry* sp10;

    while (TRUE) {
        osRecvMesg(&D_800DFE68_E0A68, (OSMesg) &sp10, 1);
        if (sp10 == NULL) break;
        dmaRead(sp10->unk10, sp10->unk_08, sp10->unkC);
        osSendMesg(&D_800E12C0_E1EC0, sp10, 0);
    }
    osSendMesg(&D_800E1480_E2080, (OSMesg) 1, 0);
    osDestroyThread(NULL);
}

INCLUDE_ASM("asm/nonmatchings/51630", func_800510CC_51CCC);

void func_80051204_51E04(u8 *input, u8 *output, s32 compressedSize) {
    u8 *src = input + 4;       // Skip metadata
    s32 flagLen = 0;           // Remaining bits in the bit buffer
    s32 flag = 0;              // Buffer holding bits for control decisions
    s32 size = compressedSize; // Bytes left to decompress
    u8 *matchPtr;              // Pointer for back-reference matches
    u32 offset, len;           // Offset and length for back-references
    u32 dist;                  // Temporary value for reading data

    while (size != 0) {
        // Refill the bit buffer if empty
        if (flagLen == 0) {
            SlideReadUint(flag, src);
            flagLen = 32;
        }

        // Determine if the next data is a literal or back-reference
        if (flag >> 31) {
            *output++ = *src++; // Write literal byte
            size--;
        } else {
            // Read the next 16 bits for the back-reference
            dist = (*src++ << 8);
            dist += (*src++);
            len = (dist >> 12) & 0xF;
            dist &= 0xFFF;
            // Calculate the pointer for the back-reference match
            matchPtr = output - dist;

            // Handle extended match lengths
            if (len == 0) {
                len = (*src++) + 0x12;
            } else {
                len += 2;
            }

            size -= len;
            if (size < 0) {
                break; // Prevent buffer overflow
            }

            // Copy the match data from the back-reference
            while (len > 0) {
                *output++ = matchPtr[-1];
                matchPtr++;
                len--;
            }
        }

        // Shift the bit buffer and decrement remaining bits
        flag <<= 1;
        flagLen--;

        // Exit if all bytes have been decompressed
        if (size == 0) {
            break;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/51630", func_800512F8_51EF8);

void func_800513FC_51FFC(void) {
    osCreateMesgQueue(&D_800DFE68_E0A68, &D_800DFE80_E0A80, 50);
    osCreateMesgQueue(&D_800E12C0_E1EC0, &D_800E12D8_E1ED8, 50);
    osCreateMesgQueue(&D_800E13A0_E1FA0, &D_800E13B8_E1FB8, 50);
    osCreateMesgQueue(&D_800E1480_E2080, &D_800E1498_E2098, 2);
    D_800E0AB0_E16B0 = 1;
    osCreateThread(&D_800E0900_E1500, 0x64, (void (*)(void*))func_800512F8_51EF8, NULL, &D_800E12C0_E1EC0, D_800E0AB0_E16B0);
    osStartThread(&D_800E0900_E1500);
    osCreateThread(&D_800DFF48_E0B48, 0x65, (void (*)(void*))func_80051054_51C54, NULL, &D_800E0900_E1500, 4);
    osStartThread(&D_800DFF48_E0B48);
}

INCLUDE_ASM("asm/nonmatchings/51630", func_800514F0_520F0);

INCLUDE_ASM("asm/nonmatchings/51630", func_80051500_52100);

void func_80051510_52110(void) {
    if (osGetThreadPri(&D_800E0900_E1500) != D_800E0AB0_E16B0) {
        osSetThreadPri(&D_800E0900_E1500, D_800E0AB0_E16B0);
    }
}

void func_8005154C_5214C(void) {
    OverlayBgEntry* mesg;
    while (osRecvMesg(&D_800E13A0_E1FA0, (OSMesg) &mesg, 0) == 0) {
        if (mesg) {
            HuMemMemoryFreeTemp(mesg->unk_08);
            mesg->unk_08 = NULL;
        }
    }
}

void func_8005159C_5219C(void) {
    s32 i;

    osJamMesg(&D_800DFE68_E0A68, NULL, OS_MESG_NOBLOCK);
    osJamMesg(&D_800E12C0_E1EC0, NULL, OS_MESG_NOBLOCK);

    func_800514F0_520F0();
    func_80051510_52110();

    osRecvMesg(&D_800E1480_E2080, NULL, OS_MESG_BLOCK);
    osRecvMesg(&D_800E1480_E2080, NULL, OS_MESG_BLOCK);

    for (i = 0; i < ARRAY_COUNT(D_800DF9D8_E05D8); i++) {
        OverlayBgEntry* temp = &D_800DF9D8_E05D8[i];
        if (temp->unk_08 != NULL) {
            HuMemMemoryFreeTemp(temp->unk_08);
            temp->unk_08 = NULL;
        }
    }
}

void func_80051664_52264(void) {
    OverlayBgEntry* var_s0 = D_800DF9D8_E05D8;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_800DF9D8_E05D8); i++, var_s0++) {
        var_s0->unk0 = 0;
        var_s0->unk1 = 0;
        var_s0->unk2 = -1;
        var_s0->unk4 = HuMemAlloc(0x1800);
        var_s0->unk_08 = NULL;
    }

    bzero(D_800DFDC0_E09C0, sizeof(D_800DFDC0_E09C0));
}

void func_800516DC_522DC(void) {
    OverlayBgEntry* var_v1 = D_800DF9D8_E05D8;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_800DF9D8_E05D8); i++, var_v1++) {
        if ((var_v1->unk_08 == NULL) && (var_v1->unk0 == 0)) {
            var_v1->unk2 = -1;
        }
        var_v1->unk0 = 0;
    }
}

void func_80051720_52320(void) {
    OverlayBgEntry* var_s0 = D_800DF9D8_E05D8;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_800DF9D8_E05D8); i++, var_s0++) {
        var_s0->unk0 = 0;
        var_s0->unk2 = -1;

        if (var_s0->unk4 != NULL) {
            HuMemFree(var_s0->unk4);
            var_s0->unk4 = NULL;
        }
    }
}

void func_80051788_52388(void) {
    func_80051664_52264();
    func_800513FC_51FFC();
    D_800DF9C0_E05C0 |= 4;
}

void func_800517C0_523C0(void) {
    func_8005159C_5219C();
    func_80051720_52320();
    D_800DF9C0_E05C0 &= 0xFFFB;
}

void func_800517F8_523F8(void) {
    D_800DF9C0_E05C0 &= ~4;
}

f32 MBDBackMdlScaleGet(void) {
    if (D_800CC208_CCE08 == NULL) {
        return 1.0f;
    } else {
        return D_800CC208_CCE08->unk14;
    }
}

u16 func_80051834_52434(s32 arg0, s32 arg1) {
    return (D_800CC208_CCE08->unkC - arg1 - 1) * D_800CC208_CCE08->unk8 + arg0 + 1;
}

s32 func_80051864_52464(u16 arg0) {
    arg0++;
    return D_800CC204_CCE04[(arg0 + 1)] - D_800CC204_CCE04[(arg0 + 0)];
}

s32 func_8005188C_5248C(u16 arg0) {
    arg0++;
    return D_800DF9B8_E05B8 + D_800CC204_CCE04[(arg0)];
}

INCLUDE_ASM("asm/nonmatchings/51630", func_800518B8_524B8);

void func_80051A74_52674(void) {
    s32 var_s1;
    u32 var_s2;
    s32 i, j;

    var_s2 = ((D_800DF9C8_E05C8 + D_800DF9C4_E05C4) - 0x78) / 48;
    for (i = 0; i < 6; var_s2++, i++) {
        s32 temp = D_800DF9C6_E05C6 + D_800DF9C2_E05C2 - 0xA0;
        if (temp < 0) {
            temp = D_800DF9C6_E05C6 + D_800DF9C2_E05C2 - 0x61;
        }
        var_s1 = temp >> 6;
        for (j = 0; j < 6; var_s1++, j++) {
            if (((((u32) var_s1 >> 0x1F) | (var_s2 >> 0x1F)) != 0) ||
                ((var_s1 < D_800CC208_CCE08->unk8) == 0) ||
                ((s32) var_s2 >= D_800CC208_CCE08->unkC)) {
                D_800DFDC0_E09C0[j][i] = NULL;
            } else {
                D_800DFDC0_E09C0[j][i] = func_800518B8_524B8(func_80051834_52434(var_s1, var_s2));
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/51630", func_80051BCC_527CC);

void func_80052B4C_5374C(Gfx** gfx, s32 arg1, u8 arg2) {
    s16 prev;
    s16 i;
    s16 j;
    s16 offY;
    s16 offX;

    if (arg2 == 0 && (D_800DF9C0_E05C0 & 4)) {
        func_8005154C_5214C();
        if (D_800DF9C0_E05C0 & 1) {
            func_800516DC_522DC();
            prev = func_8007C058_7CC58(0, 0, 0);
            func_80051A74_52674();
            func_8007C094_7CC94(prev);
            offY = (D_800DF9C8_E05C8 + D_800DF9C4_E05C4 - 120) % 48;
            offX = (D_800DF9C6_E05C6 + D_800DF9C2_E05C2 - 160) % 64;
            gSPDisplayList((*gfx)++, D_800CC228_CCE28);
            gDPSetEnvColor((*gfx)++, 0xFF, 0xFF, 0xFF, (u8) D_800CC20C_CCE0C);
            if ((u8) D_800CC20C_CCE0C < 0xFF) {
                if (D_800DF9C0_E05C0 & 8) {
                    gDPSetCombine((*gfx)++, 0x52FEA5, 0x11FFFBFD);
                } else {
                    gDPSetCombine((*gfx)++, 0xFFFFFF, 0xFFFCFA7D);
                }
                gDPSetRenderMode((*gfx)++, 0x504240, 0);
            } else {
                if (D_800DF9C0_E05C0 & 8) {
                    gDPSetCombine((*gfx)++, 0x52FEA5, 0x11FFF3F9);
                }
                gDPSetRenderMode((*gfx)++, 0x552248, 0);
            }
            for (j = 0; j < 6; j++) {
                for (i = 0; i < 6; i++) {
                    if (D_800DFDC0_E09C0[i][j] != NULL) {
                        func_80051BCC_527CC(gfx, D_800DFDC0_E09C0[i][j]->unk4, (s16) (i * 64 - offX), (s16) (j * 48 - offY));
                    }
                }
            }
            func_80051510_52110();
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/51630", func_80052E5C_53A5C);

INCLUDE_ASM("asm/nonmatchings/51630", func_80052E68_53A68);

void func_80052E74_53A74(void) {
    f32 target;
    f32 diff;
    f32 step;
    f32 next;
    f32 temp;

    target = *(f32 *)HuPrcCurrentGet()->user_data;

    while (1) {
        diff = D_800CC210_CCE10 - target;
        step = (0.0f < diff) ? diff : 0.0f - (D_800CC210_CCE10 - target);
        
        if (step <= 0.005f) {
            break;
        }
        
        step /= 4.0f;
        if (step < 0.005f) {
            step = 0.005f;
        }
        if (target < D_800CC210_CCE10) {
            next = D_800CC210_CCE10 - step;
        } else {
            next = step + D_800CC210_CCE10;
        }
        D_800CC210_CCE10 = next;
        HuPrcVSleep();
    }

    D_800CC210_CCE10 = target;
    D_800E18B4_E24B4 = NULL;
    omDelPrcObj(NULL);
}

Process* MBDCameraZoomMotStart(f32 arg0) {
    Process* temp_v0;
    f32* temp_v0_2;

    if (D_800E18B4_E24B4 != NULL) {
        omDelPrcObj(D_800E18B4_E24B4);
    }
    D_800E18B4_E24B4 = omAddPrcObj(func_80052E74_53A74, 1U, 0, 0x40);

    temp_v0_2 = HuMemMemoryAlloc(D_800E18B4_E24B4->heap, 0x10);
    D_800E18B4_E24B4->user_data = temp_v0_2;
    *temp_v0_2 = arg0;
    return D_800E18B4_E24B4;
}

INCLUDE_ASM("asm/nonmatchings/51630", func_80052FE8_53BE8);

void func_800531AC_53DAC(void) {
    if (D_800E18B0_E24B0 != NULL) {
        omDelPrcObj(D_800E18B0_E24B0);
        D_800E18B0_E24B0 = NULL;
    }
    if (D_800E18B4_E24B4 != NULL) {
        omDelPrcObj(D_800E18B4_E24B4);
        D_800E18B4_E24B4 = NULL;
    }
}

void func_80053200_53E00(void) {
    func_800531AC_53DAC();
}

INCLUDE_ASM("asm/nonmatchings/51630", func_8005321C_53E1C);

/* Retail builds this function with the KMC VR4300 mul fix (a nop between dependent mul.s), but with
   the fix on, the assembler also pads INCLUDE_ASM functions that follow some C ones, so it stays asm
   until the rest of the unit is C. */
#ifdef NON_MATCHING
void func_80053230_53E30(void) {
    Vec sp10;
    s16 sp20[2];
    Vec sp28;
    Vec sp38;
    f32 temp_f2;
    f32 temp_f4;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f2;

    while (1) {
        temp_f4 = HuVecDistance(&D_800FDC88_FE888, &D_800FDC74_FE874);
        var_f2 = D_800CC214_CCE14;
        if ((var_f2 == 0.0f) || (var_f0 = D_800CC218_CCE18, (var_f0 == 0.0f))) {
            var_f2 = temp_f4 + 1000.0f;
            var_f0 = var_f2 - 4000.0f;
        }
        if (var_f0 < 10.0f) {
            var_f0 = 10.0f;
        }
        Hu3DCamSetPerspective(0, D_800CC208_CCE08->unk10, var_f0, var_f2);
        Hu3DCamSetPositionOrientation(0, &D_800FDC88_FE888, &D_800FDC74_FE874, &D_80101060_101C60);
        Hu3DCamUpdateMtx(0);

        sp38.x = ((((D_800E18A0_E24A0.x - 160.0f) * D_800E18BC_E24BC * -4.0f) + 640.0f) - D_800E18A8_E24A8[0]) / D_800E18B8_E24B8;
        sp38.y = ((((D_800E18A0_E24A0.y - 120.0f) * D_800E18BC_E24BC * -4.0f) + 480.0f) - D_800E18A8_E24A8[1]) / D_800E18B8_E24B8;
        sp38.z = 0.0f;

        temp_f2 = HuVecGetLength3F(&sp38) / 4.0f;

        if (temp_f2 <= 1.0f) {
            D_800DF9C0_E05C0 &= 0xFFFD;
            D_800E18A8_E24A8[0] = ((D_800E18A0_E24A0.x - 160.0f) * D_800E18BC_E24BC * -4.0f) + 640.0f;
            D_800E18A8_E24A8[1] = ((D_800E18A0_E24A0.y - 120.0f) * D_800E18BC_E24BC * -4.0f) + 480.0f;
        } else {
            D_800DF9C0_E05C0 |= 2;
            if ((D_800DF9BC_E05BC >= 0.0f) && (D_800DF9BC_E05BC < temp_f2)) {
                MBVecNormalize(&sp38);
                HuVecMulScalar(&sp38, D_800DF9BC_E05BC * 4.0f, &sp38);
            }
            D_800E18A8_E24A8[0] += sp38.x;
            D_800E18A8_E24A8[1] = D_800E18A8_E24A8[1] + sp38.y;
        }

        sp20[0] = D_800E18A8_E24A8[0] / 4.0f;
        sp20[1] = D_800E18A8_E24A8[1] / 4.0f;

        sp10.x = D_800E18A8_E24A8[0] * D_800CC210_CCE10;
        sp10.y = D_800E18A8_E24A8[1] * D_800CC210_CCE10;
        sp10.z = 511.5f;

        sp28.x = D_800E18BC_E24BC * 640.0f * D_800CC210_CCE10;
        sp28.y = D_800E18BC_E24BC * 480.0f * D_800CC210_CCE10;
        sp28.z = 511.0f;

        CameraViewportSet(0, &sp28, &sp10);
        MBBackOffsetSet(-sp20[0] + 0xA0, -sp20[1] + 0x78);
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/51630", func_80053230_53E30);
#endif

INCLUDE_ASM("asm/nonmatchings/51630", func_80053608_54208);

INCLUDE_ASM("asm/nonmatchings/51630", func_80053614_54214);

u16 MBDCameraPos3DSet(Vec *arg0) {
    Vec sp10;
    f32 scale;
    f32 halfW;
    f32 halfH;
    Vec2fxy* temp;

    HuVecCopyXYZ(&sp10, arg0->x, arg0->y + 10.0f, arg0->z);
    Hu3DCam3DToScreen(0, &sp10, &D_800E18A0_E24A0);

    temp = &D_800E18A0_E24A0;

    halfW = 320.0f / (2.0f * D_800E18BC_E24BC);
    temp->x += halfW - (halfW / D_800CC210_CCE10);

    halfH = 240.0f / (2.0f * D_800E18BC_E24BC);
    D_800E18A0_E24A0.y += halfH - (halfH / D_800CC210_CCE10);

    return MBDBackPosClamp(&D_800E18A0_E24A0, D_800E18BC_E24BC);
}

u16 func_800536E4_542E4(Vec2fxy* arg0) {
    D_800E18A0_E24A0.x = (arg0->x / D_800E18BC_E24BC) + 160.0f;
    D_800E18A0_E24A0.y = (arg0->y / D_800E18BC_E24BC) + 120.0f;
    return MBDBackPosClamp(&D_800E18A0_E24A0, D_800E18BC_E24BC);
}

void func_80053754_54354(Vec2fxy* arg0) {
    arg0->x = (f32) ((D_800E18A0_E24A0.x - 160.0f) * D_800E18BC_E24BC);
    arg0->y = (f32) ((D_800E18A0_E24A0.y - 120.0f) * D_800E18BC_E24BC);
}

void func_800537A0_543A0(Vec2fxy* arg0) {
    arg0->x = -((D_800E18A8_E24A8[0] / 4.0f) - 160.0f);
    arg0->y = -((D_800E18A8_E24A8[1] / 4.0f) - 120.0f);
}

void MBDCamera3Dto2D(Vec *arg0, Vec2fxy *arg1) {
    typedef struct UnkData {
        Vec2fxy vec;
        f32 unk_08;
        f32 unk_0C;
    } UnkData;

    UnkData sp10;
    f32 temp_f0;
    f32 temp_f2;
    f32 temp_f6;

    Hu3DCam3DToScreen(0, arg0, &sp10.vec);
    temp_f6 = 2.0f * D_800E18BC_E24BC;
    temp_f2 = 320.0f / temp_f6;
    sp10.vec.x = (temp_f2 - (temp_f2 / D_800CC210_CCE10)) + sp10.vec.x;
    temp_f0 = 240.0f / temp_f6;
    sp10.vec.y = (temp_f0 - (temp_f0 / D_800CC210_CCE10)) + sp10.vec.y;
    sp10.vec.x = ((sp10.vec.x - 160.0f) * D_800E18BC_E24BC) + 160.0f;
    sp10.vec.y = ((sp10.vec.y - 120.0f) * D_800E18BC_E24BC) + 120.0f;
    sp10.unk_08 = (D_800E18A8_E24A8[0] / 4.0f) - 160.0f;
    sp10.unk_0C = (D_800E18A8_E24A8[1] / 4.0f) - 120.0f;
    arg1->x = sp10.vec.x + sp10.unk_08;
    arg1->y = sp10.vec.y + sp10.unk_0C;
}

INCLUDE_ASM("asm/nonmatchings/51630", func_8005390C_5450C);

void func_80053918_54518(s16 flag) {
    if (flag) {
        D_800DF9C0_E05C0 |= 8;
    } else {
        D_800DF9C0_E05C0 &= 0xFFF7;
    }
}

void MBDBackFlipSet(s16 arg0) {
    if (arg0) {
        D_800DF9C0_E05C0 |= 0x10;
    } else {
        D_800DF9C0_E05C0 &= ~0x10;
    }
}

INCLUDE_ASM("asm/nonmatchings/51630", MBCameraSpeedSet);

INCLUDE_ASM("asm/nonmatchings/51630", MBCameraSpeedGet);

INCLUDE_ASM("asm/nonmatchings/51630", func_80053998_54598);

INCLUDE_ASM("asm/nonmatchings/51630", func_800539A8_545A8);

INCLUDE_ASM("asm/nonmatchings/51630", func_80053A8C_5468C);

INCLUDE_ASM("asm/nonmatchings/51630", func_80053AA0_546A0);

void func_80053DD0_549D0(void) {
    func_80053DEC_549EC();
}

INCLUDE_ASM("asm/nonmatchings/51630", func_80053DEC_549EC);

INCLUDE_ASM("asm/nonmatchings/51630", func_80053EB0_54AB0);

INCLUDE_ASM("asm/nonmatchings/51630", func_80053EEC_54AEC);

INCLUDE_ASM("asm/nonmatchings/51630", func_80053F30_54B30);

INCLUDE_ASM("asm/nonmatchings/51630", func_80053F54_54B54);

INCLUDE_ASM("asm/nonmatchings/51630", func_80053F7C_54B7C);

INCLUDE_ASM("asm/nonmatchings/51630", func_80053FAC_54BAC);

INCLUDE_ASM("asm/nonmatchings/51630", func_80053FBC_54BBC);

void func_80053FC8_54BC8(void) {
    func_80050A30_51630(D_01164160);
}

void func_80053FE8_54BE8(s32 arg0) {
    MBDBackCreate((omObjData*)arg0, 1);
    omDelPrcObj(D_800E18B0_E24B0);
    D_800E18B0_E24B0 = NULL;
}

void func_80054018_54C18(s16 arg0, s16 arg1) {
    MBBackOffsetSet(arg0, arg1);
}

void func_80054040_54C40(s16 arg0, s16 arg1) {
    D_800E18A0_E24A0.x = (arg0 / D_800E18BC_E24BC) + 160.0f;
    D_800E18A0_E24A0.y = (arg1 / D_800E18BC_E24BC) + 120.0f;
}
