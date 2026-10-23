#include "common.h"
#include "process.h"
#include "game/malloc.h"

/* Board camera scissor wipe and a list of sprite groups (MP1 src/53C80.c). MP1's names are
   anonymous, so MP2's are kept. */

typedef struct Vec4f {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec4f;

typedef struct UnkList53 {
    /* 0x00 */ struct UnkList53* next;
    /* 0x04 */ struct UnkList53* prev;
    /* 0x08 */ s16 count;
    /* 0x0A */ s16 unkA;
    /* 0x0C */ s16* data;
} UnkList53;

Vec4f D_800CC980_CD580 = { 16.0f, 12.0f, 304.0f, 228.0f };
extern UnkList53* D_800E1D10_E2910;
extern u16 D_800E1D14_E2914;

void CameraScissorSet(s16, void*);
s16 SprCreate(u16, u16);
void SprKill(s16);
void SprAnimKill(s16);
void HuMemDirectFree(UnkList53* p);

void func_8005E310_5EF10(void) {
    D_800CC980_CD580.x = 16.0f;
    D_800CC980_CD580.y = 12.0f;
    D_800CC980_CD580.z = 304.0f;
    D_800CC980_CD580.w = 228.0f;
    CameraScissorSet(0, &D_800CC980_CD580);
}

void func_8005E374_5EF74(void) {
    D_800CC980_CD580.x = 16.0f;
    D_800CC980_CD580.y = 120.0f;
    D_800CC980_CD580.z = 304.0f;
    D_800CC980_CD580.w = 120.0f;
    CameraScissorSet(0, &D_800CC980_CD580);
}

void func_8005E3CC_5EFCC(void) {
    s32 i;

    D_800CC980_CD580.y = 12.0f;
    D_800CC980_CD580.w = 228.0f;
    for (i = 0; i < 9; i++) {
        HuPrcVSleep();
        D_800CC980_CD580.y += 12.0f;
        D_800CC980_CD580.w -= 12.0f;
        CameraScissorSet(0, &D_800CC980_CD580);
    }
    omDelPrcObj(NULL);
}

Process* func_8005E478_5F078(void) {
    return omAddPrcObj(func_8005E3CC_5EFCC, 0x1002, 0, 0);
}

void func_8005E4A4_5F0A4(void) {
    s32 i;

    D_800CC980_CD580.y = 120.0f;
    D_800CC980_CD580.w = 120.0f;
    for (i = 0; i < 9; i++) {
        HuPrcVSleep();
        D_800CC980_CD580.y -= 12.0f;
        D_800CC980_CD580.w += 12.0f;
        CameraScissorSet(0, &D_800CC980_CD580);
    }
    omDelPrcObj(NULL);
}

Process* func_8005E544_5F144(void) {
    return omAddPrcObj(func_8005E4A4_5F0A4, 0x1002, 0, 0);
}

void func_8005E570_5F170(void) {
    D_800E1D10_E2910 = NULL;
    D_800E1D14_E2914 = 0;
}

void func_8005E584_5F184(void) {
    while (D_800E1D10_E2910 != NULL) {
        HuMemDirectFree(D_800E1D10_E2910);
    }
}

UnkList53* func_8005E5C4_5F1C4(s16 n) {
    UnkList53* p;
    s32 i;

    p = HuMemMemoryAllocTemp(sizeof(UnkList53));
    if (p != NULL) {
    D_800E1D14_E2914++;
    p->next = D_800E1D10_E2910;
    p->prev = NULL;
    if (D_800E1D10_E2910 != NULL) {
        D_800E1D10_E2910->prev = p;
    }
    D_800E1D10_E2910 = p;
    p->count = n;
    p->data = HuMemMemoryAllocTemp(n * 2);
    for (i = 0; i < n; i++) {
        p->data[i] = -1;
    }
    }
    return p;
}

void* func_8005E688_5F288(u16 a, u16 b) {
    UnkList53* p;

    p = func_8005E5C4_5F1C4(a);
    if (p != NULL) {
        p->unkA = SprCreate(a, b);
    }
    return p;
}

void HuMemDirectFree(UnkList53* p) {
    s32 i;

    if (p->next != NULL) {
        p->next->prev = p->prev;
    }
    if (p->prev != NULL) {
        p->prev->next = p->next;
    } else {
        D_800E1D10_E2910 = p->next;
    }
    for (i = 0; i < p->count; i++) {
        if (p->data[i] >= 0) {
            SprAnimKill(p->data[i]);
        }
    }
    SprKill(p->unkA);
    HuMemMemoryFreeTemp(p->data);
    HuMemMemoryFreeTemp(p);
    D_800E1D14_E2914--;
}
