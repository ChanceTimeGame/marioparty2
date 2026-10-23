#include "common.h"

/* func_8001C45C_1D05C starts the thread whose entry is func_8001C3E8_1CFE8; same code as MP1
   ovl_67 func_800F6C1C_LogosSequenceCopy (other id, priority and stack). */

extern OSThread D_800D8C10_D9810;
extern u8 D_800D91C0_D9DC0[]; /* top of the thread's stack */

extern OSThread D_800F9058_F9C58;
extern OSMesgQueue D_800D8BF0_D97F0;
extern OSMesg D_800D8C08_D9808[];
extern u16 D_800BF880_C0480[]; /* 8x8 font, one halfword per pixel */
extern s32 D_800FA63C_FB23C;
extern u16 D_800FA5D0_FB1D0;
extern u32 D_800F8F5C_F9B5C;

void func_8001C3E8_1CFE8(void*);
void func_8001C160_1CD60(char* str, s16 x, s16 y);
void func_8001C270_1CE70(char* str, s16* fb, s16 x, s16 y, s16 color);
void func_8001C320_1CF20(s16 c, s16* fb, s16 x, s16 y, s16 color);
OSThread* func_8009CCB0_9D8B0(void); /* __osGetCurrFaultedThread */

/* Fault screen: prints the faulted thread's registers into all three frame buffers and hangs. */
void func_8001BBC0_1C7C0(OSThread* t) {
    char buf[0x80];
    char r[3][0x80];

    osDestroyThread(&D_800F9058_F9C58);
    sprintf(buf, "Fault in thread %d:", t->id);
    func_8001C160_1CD60(buf, 20, 16);
    sprintf(buf, "epc\t\t0x%08x", t->context.pc);
    func_8001C160_1CD60(buf, 20, 24);
    sprintf(r[0], "%016llx", t->context.at);
    sprintf(r[1], "%016llx", t->context.v0);
    sprintf(r[2], "%016llx", t->context.v1);
    sprintf(buf, "at %s v0 %s v1 %s", &r[0][8], &r[1][8], &r[2][8]);
    func_8001C160_1CD60(buf, 20, 32);
    sprintf(r[0], "%016llx", t->context.a0);
    sprintf(r[1], "%016llx", t->context.a1);
    sprintf(r[2], "%016llx", t->context.a2);
    sprintf(buf, "a0 %s a1 %s a2 %s", &r[0][8], &r[1][8], &r[2][8]);
    func_8001C160_1CD60(buf, 20, 40);
    sprintf(r[0], "%016llx", t->context.a3);
    sprintf(r[1], "%016llx", t->context.t0);
    sprintf(r[2], "%016llx", t->context.t1);
    sprintf(buf, "a3 %s t0 %s t1 %s", &r[0][8], &r[1][8], &r[2][8]);
    func_8001C160_1CD60(buf, 20, 48);
    sprintf(r[0], "%016llx", t->context.t2);
    sprintf(r[1], "%016llx", t->context.t3);
    sprintf(r[2], "%016llx", t->context.t4);
    sprintf(buf, "t2 %s t3 %s t4 %s", &r[0][8], &r[1][8], &r[2][8]);
    func_8001C160_1CD60(buf, 20, 56);
    sprintf(r[0], "%016llx", t->context.t5);
    sprintf(r[1], "%016llx", t->context.t6);
    sprintf(r[2], "%016llx", t->context.t7);
    sprintf(buf, "t5 %s t6 %s t7 %s", &r[0][8], &r[1][8], &r[2][8]);
    func_8001C160_1CD60(buf, 20, 64);
    sprintf(r[0], "%016llx", t->context.s0);
    sprintf(r[1], "%016llx", t->context.s1);
    sprintf(r[2], "%016llx", t->context.s2);
    sprintf(buf, "s0 %s s1 %s s2 %s", &r[0][8], &r[1][8], &r[2][8]);
    func_8001C160_1CD60(buf, 20, 72);
    sprintf(r[0], "%016llx", t->context.s3);
    sprintf(r[1], "%016llx", t->context.s4);
    sprintf(r[2], "%016llx", t->context.s5);
    sprintf(buf, "s3 %s s4 %s s5 %s", &r[0][8], &r[1][8], &r[2][8]);
    func_8001C160_1CD60(buf, 20, 80);
    sprintf(r[0], "%016llx", t->context.s6);
    sprintf(r[1], "%016llx", t->context.s7);
    sprintf(r[2], "%016llx", t->context.t8);
    sprintf(buf, "s6 %s s7 %s t8 %s", &r[0][8], &r[1][8], &r[2][8]);
    func_8001C160_1CD60(buf, 20, 88);
    sprintf(r[0], "%016llx", t->context.t9);
    sprintf(r[1], "%016llx", t->context.gp);
    sprintf(r[2], "%016llx", t->context.sp);
    sprintf(buf, "t9 %s gp %s sp %s", &r[0][8], &r[1][8], &r[2][8]);
    func_8001C160_1CD60(buf, 20, 96);
    sprintf(r[0], "%016llx", t->context.s8);
    sprintf(r[1], "%016llx", t->context.ra);
    sprintf(buf, "s8 %s ra %s", &r[0][8], &r[1][8]);
    func_8001C160_1CD60(buf, 20, 104);
    sprintf(buf, "eDataNo %03d Phase %02x", D_800FA63C_FB23C, D_800FA5D0_FB1D0);
    func_8001C160_1CD60(buf, 20, 120);
    sprintf(buf, "Prog %08x", D_800F8F5C_F9B5C);
    func_8001C160_1CD60(buf, 20, 128);
    osViSetYScale(1.0f);
    osViBlack(0);
    while (1) {
    }
}

/* Draws str at (x, y) in the three frame buffers: a shadow at (x + 1, y + 1), then the text.
   The buffers are fixed N64 addresses (a host port needs its own). */
void func_8001C160_1CD60(char* str, s16 x, s16 y) {
    func_8001C270_1CE70(str, (s16*)0x80360000, x + 1, y + 1, 0);
    func_8001C270_1CE70(str, (s16*)0x80385800, x + 1, y + 1, 0);
    func_8001C270_1CE70(str, (s16*)0x803AB000, x + 1, y + 1, 0);
    func_8001C270_1CE70(str, (s16*)0x80360000, x, y, 1);
    func_8001C270_1CE70(str, (s16*)0x80385800, x, y, 1);
    func_8001C270_1CE70(str, (s16*)0x803AB000, x, y, 1);
}

// register allocation: x and y swap s1/s2 (masked 0)
#ifdef NON_MATCHING
void func_8001C270_1CE70(char* str, s16* fb, s16 x, s16 y, s16 color) {
    osWritebackDCacheAll();
    for (; *str != 0; str++, x += 8) {
        func_8001C320_1CF20(*str, fb, x, y, color);
    }
    osWritebackDCacheAll();
}
#else
INCLUDE_ASM("asm/nonmatchings/1C7C0", func_8001C270_1CE70);
#endif

/* One 8x8 glyph of D_800BF880_C0480 (64 halfwords per character) into a 320-wide RGBA16 buffer. */
void func_8001C320_1CF20(s16 c, s16* fb, s16 x, s16 y, s16 color) {
    s16 i = 0;
    s16 row;
    s16 col;
    s16* p;

    for (row = 0; row < 8; row++) {
        p = fb + (y + row) * 320 + x;
        for (col = 0; col < 8; col++) {
            if (D_800BF880_C0480[c * 64 + i] != 0) {
                if (color == 0) {
                    *p = 1;
                } else {
                    *p = -0x7FF; /* 0xF801 */
                }
            }
            p++;
            i++;
        }
    }
}

void func_8001C3E8_1CFE8(void* arg) {
    OSMesg msg;
    OSThread* t;

    osCreateMesgQueue(&D_800D8BF0_D97F0, D_800D8C08_D9808, 1);
    osSetEventMesg(OS_EVENT_FAULT, &D_800D8BF0_D97F0, (OSMesg)16);
    while (1) {
        osRecvMesg(&D_800D8BF0_D97F0, &msg, OS_MESG_BLOCK);
        t = func_8009CCB0_9D8B0();
        if (t != NULL) {
            func_8001BBC0_1C7C0(t);
        }
    }
}

void func_8001C45C_1D05C(void) {
    osCreateThread(&D_800D8C10_D9810, 5, func_8001C3E8_1CFE8, NULL, D_800D91C0_D9DC0, 0xBE);
    osStartThread(&D_800D8C10_D9810);
}

/* 1D0B0's string (its user func_8001D190_1DD90 is still asm): a data piece cannot start at
   0xD2CCC under the linker script's SUBALIGN(8), so it ends this unit's carved rodata. */
const char D_800D20CC_D2CCC[] = "Unknown Hmf Format!\n";
