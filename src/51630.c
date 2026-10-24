#include "common.h"
#include "game/malloc.h"

/* A tile bank (h1-D): an alternative set of background tiles; D_800DFE64 holds D_800DFE58 of them,
   loaded from the ROM table at D_016EC470 by func_80053AA0_546A0. */
typedef struct BgTileBank {
    /* 0x00 */ s32 count; /* entries in offsets[] (ids[] has count - 1) */
    /* 0x04 */ s32* ids;  /* tile id each replaced tile has */
    /* 0x08 */ u32* offsets; /* ROM address of each tile */
} BgTileBank; // size 0xC

extern s32* D_800DF9D0_E05D0; /* the DMA buffer being decoded: magic word, then the data */
extern u32 D_800DFE54_E0A54;  /* ROM address of the bank table */
extern s32 D_800DFE58_E0A58;  /* number of banks */
extern s32 D_800DFE5C_E0A5C;  /* current bank + 1 (0 = none) */
extern s32 D_800DFE60_E0A60;  /* current bank */
extern BgTileBank* D_800DFE64_E0A64;
extern u32* D_800CC21C_CCE1C;
extern Process* D_800CC220_CCE20;
void func_80096188_96D88(u8* code, u16* outbuf, s32 outbufWidth, u8* workbuf);
void func_80096708_97308(void* header);
void func_80096C10_97810(u8 alpha);
void func_80051204_51E04(u8* input, u8* output, s32 compressedSize);
u32 func_80053EB0_54AB0(u16 arg0);
s32 func_80053EEC_54AEC(u16 arg0);
void func_80053F30_54B30(u16 arg0);
void func_800539A8_545A8(void);
void omPrcSetStatBit(Process*, s32);


/* Board background (HVQ tiles streamed by two threads) and the board camera. C from MP1 src/48D90.c
   and MP3 ovl_80_shared_board FA250.c / ovl_81_name CCD20.c (their copies of the same code); the
   rest have no reference and stay asm (func_80053230_53E30 is in the permuter list). MP1's unk20 is
   MP3's OverlayBgEntry. The unit builds with the KMC mul fix on (Makefile b3-C). */

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
void MBDBackCreate(s32, s32);
void MBBackOffsetSet(s16, s16);
s32 dmaRead(u32 src, u8* dest, s32 size);
void func_8002D018_2DC18(s32, void* func);
void func_800512F8_51EF8(void*);
void func_800514F0_520F0(void);
OverlayBgEntry* func_800518B8_524B8(u16);
void func_80051BCC_527CC(Gfx**, void*, s16, s16);
void func_8003FB9C_4079C(Gfx** arg0, void* arg1, s32 fmt, s32 siz, s32 width, s32 height, s32 uls, s32 ult, s32 lrs, s32 lrt, s32 pal, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts, s32 shiftt);
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
void func_80051500_52100(void);
void func_80053230_53E30(void);
extern Vec D_800E18C0_E24C0;
extern s32 D_800CC224_CCE24;
extern s32 D_800CC270_CCE70;
extern s32 D_801027B8_1033B8;
s32 func_80051864_52464(u16 arg0);
void func_80052B4C_5374C(Gfx** gfx, s32 arg1, u8 arg2);
void func_80051788_52388(void);
void func_80052FE8_53BE8(void);
void func_80053608_54208(f32);
void func_8005390C_5450C(s32);
void MBCameraSpeedSet(f32);
void func_80052E68_53A68(f32);


/* .data (0xCCE00-0xCCE80) */
s32* D_800CC200_CCE00 = NULL;
u32* D_800CC204_CCE04 = NULL;
UnkModelStruct* D_800CC208_CCE08 = NULL;
s8 D_800CC20C_CCE0C = -1; /* fade alpha (read as u8) */
f32 D_800CC210_CCE10 = 1.0f;
f32 D_800CC214_CCE14 = 0.0f;
f32 D_800CC218_CCE18 = 0.0f;
u32* D_800CC21C_CCE1C = NULL;
Process* D_800CC220_CCE20 = NULL;
s32 D_800CC224_CCE24 = 0;
Gfx D_800CC228_CCE28[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureFilter(G_TF_AVERAGE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetAlphaDither(G_AD_DISABLE),
    gsSPEndDisplayList(),
};
s32 D_800CC270_CCE70 = 1;

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

void func_80050AD4_516D4(void) {
    D_800CC208_CCE08 = NULL;
}

void func_80050AE0_516E0(void) {
    if (D_800CC200_CCE00 != NULL) {
        HuMemMemoryFreeTemp(D_800CC200_CCE00);
        D_800CC200_CCE00 = NULL;
        HuMemMemoryFreeTemp(D_800DF9CC_E05CC);
    }
}

void MBDBackCreate(s32 arg0, s32 arg1) {
    s32* temp_v0;
    u32 temp_s0;
    u32* temp_v0_2;
    UnkModelStruct* temp_v0_3;

    D_801027B8_1033B8 = arg0;
    D_800DF9B8_E05B8 = D_800DF9B0_E05B0 + D_800CC200_CCE00[arg0];
    temp_v0 = HuMemMemoryAllocTemp(sizeof(HVQHeader));
    dmaRead(D_800DF9B8_E05B8, (u8*)temp_v0, sizeof(HVQHeader));
    arg0 = *temp_v0;
    HuMemMemoryFreeTemp(temp_v0);
    arg0++;
    temp_s0 = arg0 * 4;
    temp_v0_2 = HuMemMemoryAllocTemp(temp_s0);
    D_800CC204_CCE04 = temp_v0_2;
    dmaRead(D_800DF9B8_E05B8 + 4, (u8*)temp_v0_2, temp_s0);
    temp_v0_3 = HuMemMemoryAllocTemp(sizeof(UnkModelStruct));
    D_800CC208_CCE08 = temp_v0_3;
    dmaRead(D_800DF9B8_E05B8 + D_800CC204_CCE04[0], (u8*)&temp_v0_3->unk0, sizeof(UnkModelStruct));
    D_800CC208_CCE08->unk18 *= 5.0f;
    D_800CC208_CCE08->unk1C *= 5.0f;
    D_800CC208_CCE08->unk20 *= 5.0f;
    D_800CC208_CCE08->unk24 *= 5.0f;
    D_800CC208_CCE08->unk28 *= 5.0f;
    D_800CC208_CCE08->unk2C *= 5.0f;
    if (D_800CC208_CCE08->unk1C >= 5000.0f) {
        D_800CC208_CCE08->unk18 /= 1.2f;
        D_800CC208_CCE08->unk1C /= 1.2f;
        D_800CC208_CCE08->unk20 /= 1.2f;
        D_800CC208_CCE08->unk14 /= 1.2f;
    }
    D_800DFE50_E0A50 = HuMemMemoryAllocTemp(func_80051864_52464(0));
    dmaRead(D_800DF9B8_E05B8 + D_800CC204_CCE04[1], D_800DFE50_E0A50, func_80051864_52464(0));
    D_800DF9C4_E05C4 = 0;
    D_800DF9C2_E05C2 = 0;
    D_800DF9C6_E05C6 = D_800CC208_CCE08->unk0 * D_800CC208_CCE08->unk8 / 2;
    D_800DF9C8_E05C8 = D_800CC208_CCE08->unk4 * D_800CC208_CCE08->unkC / 2;
    D_800DF9C0_E05C0 = 1;
    func_8002D018_2DC18(0, func_80052B4C_5374C);
    func_80051788_52388();
    func_800514F0_520F0();
    if (arg1 != 0) {
        func_80052FE8_53BE8();
    }
    func_80053608_54208(1.0f);
    func_8005390C_5450C(0xFF);
    MBCameraSpeedSet(-1.0f);
    D_800CC214_CCE14 = 0.0f;
    D_800CC218_CCE18 = 0.0f;
    func_80052E68_53A68(1.0f);
}

void func_80050E00_51A00(s32 obj) {
    MBDBackCreate(obj, 1);
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

void MBBackOffsetSet(s16 arg0, s16 arg1) {
    D_800DF9C2_E05C2 = arg0;
    D_800DF9C4_E05C4 = arg1;
}

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

/* Tile decode thread: decodes each DMA'd tile (HVQS or the 0x1800-byte LZ form) into its buffer. */
void func_800512F8_51EF8(void* arg0) {
    OverlayBgEntry* entry;
    s16 color;

    func_80096C10_97810(0xFF);
    func_80096708_97308(D_800DFE50_E0A50);
    while (1) {
        osRecvMesg(&D_800E12C0_E1EC0, (OSMesg*)&entry, OS_MESG_BLOCK);
        if (entry == NULL) {
            break;
        }
        D_800DF9D0_E05D0 = entry->unk_08;
        color = func_8007C058_7CC58(0xFF, 0xFF, 0xFF);
        if (D_800DF9D0_E05D0[0] == 0x48565153) { /* "HVQS" */
            func_80096188_96D88((u8*)(D_800DF9D0_E05D0 + 1), entry->unk4, 0x40, D_800DF9CC_E05CC);
        } else {
            func_80051204_51E04((u8*)(D_800DF9D0_E05D0 + 1), entry->unk4, 0x1800);
        }
        func_8007C094_7CC94(color);
        osSendMesg(&D_800E13A0_E1FA0, entry, OS_MESG_NOBLOCK);
    }
    osSendMesg(&D_800E1480_E2080, (OSMesg)2, OS_MESG_NOBLOCK);
    osDestroyThread(NULL);
}

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

void func_800514F0_520F0(void) {
    D_800E0AB0_E16B0 = 3;
}

void func_80051500_52100(void) {
    D_800E0AB0_E16B0 = 1;
}

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

/* Finds (or starts loading) the buffer of tile arg0, from the current bank when it replaces that tile. */
OverlayBgEntry* func_800518B8_524B8(u16 arg0) {
    OverlayBgEntry* entry;
    OverlayBgEntry* slot;
    u16 bank;
    s32 i;
    s32 idx;

    slot = NULL;
    entry = D_800DF9D8_E05D8;
    bank = 0;
    if (D_800DFE5C_E0A5C != 0) {
        for (i = 0; i < D_800DFE64_E0A64[D_800DFE60_E0A60].count - 1; i++) {
            if (arg0 == D_800DFE64_E0A64[D_800DFE60_E0A60].ids[i]) {
                bank = D_800DFE5C_E0A5C;
                idx = i;
            }
        }
    }
    for (i = 0; i < 50; i++, entry++) {
        if (entry->unk2 == -1) {
            slot = entry;
        } else if (entry->unk2 == arg0) {
            if (entry->unk1 == bank) {
                entry->unk0 = 1;
                return entry;
            }
        }
    }
    if (slot != NULL) {
        slot->unk0 = 1;
        slot->unk2 = arg0;
        slot->unk1 = bank;
        if (bank != 0) {
            slot->unk10 = func_80053EB0_54AB0(idx);
            slot->unkC = func_80053EEC_54AEC(idx);
        } else {
            slot->unk10 = func_8005188C_5248C(arg0);
            slot->unkC = func_80051864_52464(arg0);
        }
        slot->unk_08 = HuMemMemoryAllocPerm(slot->unkC);
        osSendMesg(&D_800DFE68_E0A68, slot, OS_MESG_NOBLOCK);
    }
    return slot;
}

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

#define gSPScisTextureRectangle_MP(pkt,xl,yl,xh,yh,tile,s,t,dsdx,dtdy) { \
    Gfx *_g = (Gfx *)(pkt); \
    _g->words.w0 = (_SHIFTL(G_TEXRECT, 24, 8) | \
    _SHIFTL(MAX((s16)(xh),0), 12, 12) | \
    _SHIFTL(MAX((s16)(yh),0), 0, 12)); \
    _g->words.w1 = (_SHIFTL((tile), 24, 3) | \
    _SHIFTL(MAX((s16)(xl),0), 12, 12) | \
    _SHIFTL(MAX((s16)(yl),0), 0, 12)); \
    gImmp1(pkt, G_RDPHALF_1, \
    (_SHIFTL(((s) - (((s16)(xl) < 0) ? (((s16)(dsdx) < 0) ? (MAX((((s16)(xl)*(s16)(dsdx))>>7),0)) : (MIN((((s16)(xl)*(s16)(dsdx))>>7),0))) : 0)), 16, 16) |\
    _SHIFTL(((t) - (((s32)(yl) < 0) ? (((s16)(dtdy) < 0) ? (MAX((((s16)(yl)*(s16)(dtdy))>>7),0)) : (MIN((((s16)(yl)*(s16)(dtdy))>>7),0))) : 0)), 0, 16))); \
    gImmp1(pkt, G_RDPHALF_2, (_SHIFTL((s16)(dsdx), 16, 16) | _SHIFTL((s16)(dtdy), 0, 16))); \
}

void func_80051BCC_527CC(Gfx** arg0, void* arg1, s16 arg2, s16 arg3) {
    f32 temp_f20;
    f32 temp_f22;

    temp_f20 = ((f32) arg2 + (D_800E18A8_E24A8[0] / 4.0f)) - (f32) (s32) (D_800E18A8_E24A8[0] / 4.0f);
    temp_f22 = ((f32) arg3 + (D_800E18A8_E24A8[1] / 4.0f)) - (f32) (s32) (D_800E18A8_E24A8[1] / 4.0f);
    func_8003FB9C_4079C(arg0, arg1, 0, 2, 0x40, 0x20, 0, 0, 0x40, 0x20, 0, 1, 1, 6, 5, 0, 0);
    if (!(D_800DF9C0_E05C0 & 0x10)) {
        gSPScisTextureRectangle_MP((*arg0)++,
            /*xl*/(temp_f20 * D_800CC210_CCE10 * 4.0f),
            /*yl*/(temp_f22 * D_800CC210_CCE10 * 4.0f),
            /*xh*/(temp_f20 + 64.0f) * D_800CC210_CCE10 * 4.0f,
            /*yh*/(temp_f22 + 32.0f) * D_800CC210_CCE10 * 4.0f,
            /*tile*/0,
            /*s*/0,
            /*t*/0,
            /*dsdx*/(s16)(1024.0f / D_800CC210_CCE10),
            /*dtdy*/(s16)(1024.0f / D_800CC210_CCE10)
        );
    } else {
        gSPScisTextureRectangle_MP((*arg0)++,
            /*xl*/((256.0f - temp_f20) * D_800CC210_CCE10 * 4.0f),
            /*yl*/((temp_f22 * D_800CC210_CCE10 * 4.0f)),
            /*xh*/((320.0f - temp_f20) * D_800CC210_CCE10 * 4.0f),
            /*yh*/((temp_f22 + 32.0f) * D_800CC210_CCE10 * 4.0f),
            /*tile*/0,
            /*s*/0x7e0,
            /*t*/0,
            /*dsdx*/-(s16)(1024.0f / D_800CC210_CCE10),
            /*dtdy*/(s16)(1024.0f / D_800CC210_CCE10)
        );
    }
    func_8003FB9C_4079C(arg0, (u8*)arg1 + 0x1000, 0, 2, 0x40, 0x10, 0, 0, 0x40, 0x10, 0, 1, 1, 6, 4, 0, 0);
    if (!(D_800DF9C0_E05C0 & 0x10)) {
        gSPScisTextureRectangle_MP((*arg0)++,
            /*xl*/(temp_f20 * D_800CC210_CCE10 * 4.0f),
            /*yl*/((temp_f22 + 32.0f) * D_800CC210_CCE10 * 4.0f),
            /*xh*/((temp_f20 + 64.0f) * D_800CC210_CCE10 * 4.0f),
            /*yh*/((temp_f22 + 48.0f) * D_800CC210_CCE10 * 4.0f),
            /*tile*/0,
            /*s*/0,
            /*t*/0,
            /*dsdx*/(s16)(1024.0f / D_800CC210_CCE10),
            /*dtdy*/(s16)(1024.0f / D_800CC210_CCE10)
        );
    } else {
        gSPScisTextureRectangle_MP((*arg0)++,
            /*xl*/((256.0f - temp_f20) * D_800CC210_CCE10 * 4.0f),
            /*yl*/((temp_f22 + 32.0f) * D_800CC210_CCE10 * 4.0f),
            /*xh*/((320.0f - temp_f20) * D_800CC210_CCE10 * 4.0f),
            /*yh*/((temp_f22 + 48.0f) * D_800CC210_CCE10 * 4.0f),
            /*tile*/0,
            /*s*/0x7e0,
            /*t*/0,
            /*dsdx*/-(s16)(1024.0f / D_800CC210_CCE10),
            /*dtdy*/(s16)(1024.0f / D_800CC210_CCE10)
        );
    }
}

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

f32 func_80052E5C_53A5C(void) {
    return D_800CC210_CCE10;
}

void func_80052E68_53A68(f32 arg0) {
    D_800CC210_CCE10 = arg0;
}

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

void func_80052FE8_53BE8(void) {
    f32 temp_f2;
    Process* temp_v0;
    f32* pFloat = (f32*)D_800CC208_CCE08;

    temp_f2 = (D_800CC208_CCE08->unk4 * D_800CC208_CCE08->unkC) / 240.0f;
    D_800E18BC_E24BC = temp_f2;
    D_800FDC88_FE888.x = pFloat[6];
    D_800FDC88_FE888.y = pFloat[7];
    D_800FDC88_FE888.z = pFloat[8];
    D_800FDC74_FE874.x = pFloat[9];
    D_800FDC74_FE874.y = pFloat[10];
    D_800FDC74_FE874.z = pFloat[11];
    D_80101060_101C60.x = pFloat[12];
    D_80101060_101C60.y = pFloat[13];
    D_80101060_101C60.z = pFloat[14];
    D_800E18C0_E24C0.x = (temp_f2 * 640.0f);
    D_800E18C0_E24C0.y = (temp_f2 * 480.0f);
    D_800E18C0_E24C0.z = 511.0f;
    D_800E18A8_E24A8[0] = 640.0f;
    D_800E18A8_E24A8[1] = 480.0f;
    D_800E18A0_E24A0.x = 159.5f;
    D_800E18A0_E24A0.y = 119.5f;
    D_800E18B8_E24B8 = 1.0f;
    temp_v0 = omAddPrcObj(func_80053230_53E30, 0x1001, 0, 0);
    D_800E18B0_E24B0 = temp_v0;
    omPrcSetStatBit(temp_v0, 0x80);
    D_800E18B4_E24B4 = NULL;
    Hu3DCamSetPerspective(0, ((f32*)D_800CC208_CCE08)[4], 10.0f, 200.0f);
    Hu3DCamSetPositionOrientation(0, &D_800FDC88_FE888, &D_800FDC74_FE874, &D_80101060_101C60);
    Hu3DCamUpdateMtx(0);
}

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

void func_8005321C_53E1C(f32 arg0, f32 arg1) {
    D_800CC218_CCE18 = arg0;
    D_800CC214_CCE14 = arg1;
}

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

void func_80053608_54208(f32 arg0) {
    D_800E18B8_E24B8 = arg0;
}

f32 func_80053614_54214(void) {
    return D_800E18B8_E24B8;
}

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

void func_8005390C_5450C(s32 arg0) {
    D_800CC20C_CCE0C = arg0;
}

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

void MBCameraSpeedSet(f32 arg0) {
    D_800DF9BC_E05BC = arg0;
}

f32 MBCameraSpeedGet(void) {
    return D_800DF9BC_E05BC;
}

s32 func_80053998_54598(void) {
    return D_800DF9C0_E05C0 & 2;
}

/* Bank cycler: while the background has not moved for 16 frames, step to the next bank (0..count). */
void func_800539A8_545A8(void) {
    s32 timer;
    s32 bank;
    s16 x;
    s16 y;

    timer = 16;
    bank = 0;
    x = D_800DF9C2_E05C2;
    y = D_800DF9C4_E05C4;
    while (1) {
        if (x == D_800DF9C2_E05C2 && y == D_800DF9C4_E05C4 && D_800CC224_CCE24 == 1) {
            if (--timer == 0) {
                bank++;
                if (bank > D_800DFE58_E0A58) {
                    bank = 0;
                }
                func_80053F30_54B30(bank);
                timer = 16;
            }
        }
        x = D_800DF9C2_E05C2;
        y = D_800DF9C4_E05C4;
        HuPrcVSleep();
    }
}

void func_80053A8C_5468C(void) {
    D_800DFE5C_E0A5C = 0;
    D_800CC220_CCE20 = NULL;
}

/* Loads tile bank set arg0 from the ROM table at D_016EC470 and starts the bank cycler. */
// register allocation only (masked 0): retail keeps the first size's >> 4 in v0
#ifdef NON_MATCHING
void func_80053AA0_546A0(s32 arg0) {
    s32* buf;
    u32 hdrSize;
    u32 size;
    u32 base;
    s32 i;
    s32 j;

    D_800DFE54_E0A54 = (u32)D_016EC470;
    D_800DFE60_E0A60 = 0;
    D_800DFE5C_E0A5C = 0;
    hdrSize = (arg0 + 1) * 16;
    buf = HuMemMemoryAllocTemp(hdrSize);
    dmaRead(D_800DFE54_E0A54, (u8*)buf, hdrSize);
    if (buf[0] < arg0 - 1) {
        return;
    }
    D_800DFE54_E0A54 += buf[arg0 + 1];
    HuMemMemoryFreeTemp(buf);
    buf = HuMemMemoryAllocTemp(16);
    dmaRead(D_800DFE54_E0A54, (u8*)buf, 16);
    size = (D_800DFE58_E0A58 = buf[0]) * 4;
    size = ((size + 15) >> 4) << 4;
    D_800CC21C_CCE1C = HuMemMemoryAllocTemp(size);
    dmaRead(D_800DFE54_E0A54 + 4, (u8*)D_800CC21C_CCE1C, size);
    /* 0xC each on the N64 */
    D_800DFE64_E0A64 = HuMemMemoryAllocTemp(D_800DFE58_E0A58 * sizeof(BgTileBank));
    for (i = 0; i < D_800DFE58_E0A58; i++) {
        base = D_800DFE54_E0A54 + D_800CC21C_CCE1C[i];
        dmaRead(base, (u8*)buf, 16);
        size = (D_800DFE64_E0A64[i].count = buf[0]) * 4;
        size = ((size + 15) >> 4) << 4;
        D_800DFE64_E0A64[i].offsets = HuMemMemoryAllocTemp(size);
        dmaRead(base + 4, (u8*)D_800DFE64_E0A64[i].offsets, size);
        for (j = 0; j < D_800DFE64_E0A64[i].count; j++) {
            D_800DFE64_E0A64[i].offsets[j] += base;
        }
        D_800DFE64_E0A64[i].ids = HuMemMemoryAllocTemp(size);
        for (j = 0; j < D_800DFE64_E0A64[i].count - 1; j++) {
            dmaRead(D_800DFE64_E0A64[i].offsets[j], (u8*)buf, 16);
            D_800DFE64_E0A64[i].ids[j] = buf[0];
        }
    }
    HuMemMemoryFreeTemp(buf);
    D_800CC220_CCE20 = omAddPrcObj(func_800539A8_545A8, 0x1001, 0, 0);
    omPrcSetStatBit(D_800CC220_CCE20, 0x80);
    D_800CC224_CCE24 = 1;
}

#else
INCLUDE_ASM("asm/nonmatchings/51630", func_80053AA0_546A0);
#endif

void func_80053DD0_549D0(void) {
    func_80053DEC_549EC();
}

void func_80053DEC_549EC(void) {
    s32 i;

    if (D_800CC220_CCE20 != NULL) {
        for (i = 0; i < D_800DFE58_E0A58; i++) {
            HuMemMemoryFreeTemp(D_800DFE64_E0A64[i].ids);
            HuMemMemoryFreeTemp(D_800DFE64_E0A64[i].offsets);
        }
        HuMemMemoryFreeTemp(D_800DFE64_E0A64);
        HuMemMemoryFreeTemp(D_800CC21C_CCE1C);
        omDelPrcObj(D_800CC220_CCE20);
        D_800CC220_CCE20 = NULL;
    }
    D_800DFE5C_E0A5C = 0;
}

u32 func_80053EB0_54AB0(u16 arg0) {
    return D_800DFE64_E0A64[D_800DFE60_E0A60].offsets[arg0] + 4;
}

s32 func_80053EEC_54AEC(u16 arg0) {
    return D_800DFE64_E0A64[D_800DFE60_E0A60].offsets[arg0 + 1] - D_800DFE64_E0A64[D_800DFE60_E0A60].offsets[arg0] - 4;
}

void func_80053F30_54B30(u16 arg0) {
    if ((D_800DFE5C_E0A5C = arg0) != 0) {
        D_800DFE60_E0A60 = arg0 - 1;
    }
}

void func_80053F54_54B54(void) {
    D_800CC224_CCE24 = D_800CC270_CCE70;
    func_800514F0_520F0();
}

void func_80053F7C_54B7C(void) {
    D_800CC270_CCE70 = D_800CC224_CCE24;
    D_800CC224_CCE24 = 0;
    func_80051500_52100();
}

void func_80053FAC_54BAC(void) {
    D_800CC224_CCE24 = 1;
}

void func_80053FBC_54BBC(void) {
    D_800CC224_CCE24 = 0;
}

void func_80053FC8_54BC8(void) {
    func_80050A30_51630(D_01164160);
}

void func_80053FE8_54BE8(s32 arg0) {
    MBDBackCreate(arg0, 1);
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
