#include "common.h"
#include "PR/os.h"
#include "game/rsp.h"

/* Performance meter task and timers (MP1 src/61B70.c, non-host path). MP1's names are anonymous. */

extern OSMesg D_800E23F8_E2FF8[];
extern s32 D_800E240C_E300C;
extern void* D_800E2410_E3010;
extern s32 D_800E2414_E3014;
extern s32 D_800E2418_E3018;
extern s32 D_800E241C_E301C;
extern s32 D_800E2420_E3020;
extern s32 D_800E2424_E3024;
extern s32 D_800E242C_E302C;
extern Gfx* D_800E2438_E3038;
extern s32 D_800E243C_E303C;
extern s32 D_800E2444_E3044;
extern OSMesgQueue* D_800E2448_E3048;
extern s32 D_800E244C_E304C;


typedef struct unk_Struct_func_800611A4 {
    OSTime unk_00;
    s16 unk_08;
    Vec2s unk_0A;
    char unk_0E[2]; // likely padding or Vec3s unk_0A;
    s32 unk_10[10];
    u64 unk_38[10];
    u64 unk_88[10];
} unk_Struct_func_800611A4;

extern OSMesg D_800E2408_E3008;
extern s32 D_800E2428_E3028;
extern s32 D_800E2430_E3030;
extern s32 D_800E2434_E3034;
extern s32 D_800E2440_E3040;
extern Gfx D_800E2450_E3050;
extern OSMesgQueue D_800F8F68_F9B68;
extern s32 osJamMesg(OSMesgQueue *, OSMesg, s32);
extern s32 D_800E2304_E2F04;
extern s16 D_800E2308_E2F08;
extern s32 D_800E23DC_E2FDC;
extern unk_Struct_func_800611A4 D_800E2150_E2D50;
extern unk_Struct_func_800611A4 D_800E2228_E2E28;
extern unk_Struct_func_800611A4 D_800E2300_E2F00;
extern unk_Struct_func_800611A4 D_800E23D8_E2FD8;
extern OSMesgQueue D_800E23E0_E2FE0;

void func_8007BDA0_7C9A0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u16 arg4) {
    D_800E2228_E2E28.unk_0A.x = arg1;
    D_800E2228_E2E28.unk_0A.y = arg2;
    D_800E2300_E2F00.unk_0A.x = arg3;
    D_800E2300_E2F00.unk_0A.y = arg4;
    D_800E2448_E3048 = &D_800E23E0_E2FE0;
    D_800E244C_E304C = 0;
    D_800E2408_E3008 = (OSMesg)1;
    D_800E240C_E300C = 2;
    D_800E2410_E3010 = D_800B8590_B9190;
    D_800E2414_E3014 = (u32)D_800B8660_B9260 - (u32)D_800B8590_B9190;
    D_800E241C_E301C = 0x1000;
    D_800E2424_E3024 = 0x800;
    D_800E242C_E302C = 0x400;
    D_800E2438_E3038 = &D_800E2450_E3050;
    D_800E243C_E303C = 0;
    D_800E2444_E3044 = 0xC00;
    D_800E2418_E3018 = D_800FCE7C_FDA7C[arg0 * 2];
    D_800E2420_E3020 = D_800FCE7C_FDA7C[(arg0 * 2) | 1];
    osCreateMesgQueue(&D_800E23E0_E2FE0, D_800E23F8_E2FF8, 3);
}
void func_8007BEC4_7CAC4(void) {
    D_800E23D8_E2FD8.unk_00 = osGetTime();
    while (!osRecvMesg(&D_800E23E0_E2FE0, NULL, 0)) {

    } 
}

s16 func_8007BF0C_7CB0C(unk_Struct_func_800611A4* arg0, u8 arg1, u8 arg2, u8 arg3) {
    if (arg0->unk_08 >= 10) {
        return -1;
    }
    arg0->unk_38[arg0->unk_08] = osGetTime();
    arg0->unk_10[arg0->unk_08] = (GPACK_RGBA5551(arg1, arg2, arg3, 1) << 16) | GPACK_RGBA5551(arg1, arg2, arg3, 1);
    return arg0->unk_08++;
}

u64 func_8007BFD4_7CBD4(unk_Struct_func_800611A4* arg0, s16 arg1) {
    if (arg1 >= 0) {
        arg0->unk_88[arg1] = osGetTime();
    }
    return arg0->unk_88[arg1] - arg0->unk_38[arg1];
}

s16 func_8007C058_7CC58(u8 arg0, u8 arg1, u8 arg2) {
    return func_8007BF0C_7CB0C(&D_800E2228_E2E28, arg0, arg1, arg2);
}

void func_8007C094_7CC94(s16 arg0) {
    func_8007BFD4_7CBD4(&D_800E2228_E2E28, arg0);
}

s16 func_8007C0BC_7CCBC(u8 arg0, u8 arg1, u8 arg2) {
    s16 temp_s0;
    OSIntMask temp_s3;

    temp_s3 = osSetIntMask(OS_IM_NONE);
    temp_s0 = func_8007BF0C_7CB0C(&D_800E2300_E2F00, arg0, arg1, arg2);
    osSetIntMask(temp_s3);
    return temp_s0;
}

void func_8007C134_7CD34(s16 arg0) {
    OSIntMask temp_s1;

    temp_s1 = osSetIntMask(OS_IM_NONE);
    func_8007BFD4_7CBD4(&D_800E2300_E2F00, arg0);
    osSetIntMask(temp_s1);
}

void func_8007C184_7CD84(void) {
    unk_Struct_func_800611A4* temp = &D_800E2228_E2E28;
    unk_Struct_func_800611A4* temp2 = &D_800E23D8_E2FD8;
    u32 temp_v0;
    
    temp->unk_08 = 0;
    temp_v0 = osSetIntMask(1U);
    temp->unk_00 = temp2->unk_00;
    osSetIntMask(temp_v0);
}

void func_8007C1D0_7CDD0(void) {
    OSIntMask temp_s0;

    temp_s0 = osSetIntMask(OS_IM_NONE);
    bcopy(&D_800E2228_E2E28, &D_800E2150_E2D50, sizeof(unk_Struct_func_800611A4));
    osSetIntMask(temp_s0);
}

void func_8007C218_7CE18(void) {
    unk_Struct_func_800611A4* temp = &D_800E2300_E2F00;
    unk_Struct_func_800611A4* temp2 = &D_800E23D8_E2FD8;
    
    temp->unk_08 = 0;
    temp->unk_00 = temp2->unk_00;
}

void func_8007C244_7CE44(void) {
}

Gfx* func_8007C24C_7CE4C(void * arg0, Gfx* arg1, s32 arg2) {
    return arg1;
}

void func_8007C254_7CE54(void) {
    Gfx* gfx = &D_800E2450_E3050;
    D_800E2428_E3028 = (s32)D_800FC730_FD330;
    D_800E2440_E3040 = (s32)D_800FA638_FB238;
    D_800E2430_E3030 = (s32)D_800FC98C_FD58C;
    D_800E2434_E3034 = (s32)D_800F8430_F9030;
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_FILL);
    gDPSetRenderMode(gfx++, G_RM_NOOP, G_RM_NOOP2);
    gfx = func_8007C24C_7CE4C(&D_800E2150_E2D50, gfx, 0);
    gfx = func_8007C24C_7CE4C(&D_800E2300_E2F00, gfx, 2);
    gDPFullSync(gfx++);
    gSPEndDisplayList(gfx++);
    osJamMesg(&D_800F8F68_F9B68, &D_800E2408_E3008, 0);
}
