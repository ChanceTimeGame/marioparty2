#include "common.h"
#include "game/malloc.h"

/* Board turn banners. C from MP1 src/47320.c (func_80046720 .. func_80048134); the rest have no
   reference or differ (near) and stay asm. */

typedef struct unkUserData {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} unkUserData;

extern u8 D_800DF750_E0350[]; /* MP1 unkCommonStruct0[] */
extern s16 D_800DF7C4_E03C4;
extern u8 D_800DF7C6_E03C6;
extern s16 D_800DF7C8_E03C8;
extern Vec2s D_800DF7CA_E03CA;
extern omObjData* D_800DF7D0_E03D0;
extern omObjData* D_800DF7D4_E03D4;
extern s32 D_800DF944_E0544;
extern GW_SYSTEM GwSystem;

s32 PlaySound(s32);
void SprKill(s16);
void SprAnimKill(s16);
void omDelObj(omObjData*);
void func_8004F5E8_501E8(void);
void func_8004F7F0_503F0(s32);
void func_8006AE14_6BA14(void*);


void func_8004EA50_4F650(void) {
    D_800DF7C4_E03C4 = -1;
    D_800DF7C6_E03C6 = 0;
    D_800DF7C8_E03C8 = -1;
    D_800DF7CA_E03CA.x = D_800DF7CA_E03CA.y = -1;
    D_800DF7D0_E03D0 = 0;
    D_800DF7D4_E03D4 = 0;
}

void func_8004EA90_4F690(void) {
    if (D_800DF7C6_E03C6 & 0x20) {
        func_8006AE14_6BA14(D_800DF750_E0350);
    }
    
    if (D_800DF7C6_E03C6 & 0x10) {
        SprKill(D_800DF7C8_E03C8);
        SprAnimKill(D_800DF7CA_E03CA.x);
        SprAnimKill(D_800DF7CA_E03CA.y);
    }
    
    if (D_800DF7D0_E03D0 != NULL) {
        omDelObj(D_800DF7D0_E03D0);
        D_800DF7D0_E03D0 = NULL;
    }
    
    if (D_800DF7D4_E03D4 != NULL) {
        omDelObj(D_800DF7D4_E03D4);
        D_800DF7D4_E03D4 = NULL;
    }
    
    D_800DF7C6_E03C6 &= 0xCF;
}

INCLUDE_ASM("asm/nonmatchings/4F650", func_8004EB58_4F758);

INCLUDE_ASM("asm/nonmatchings/4F650", func_8004EE40_4FA40);

INCLUDE_ASM("asm/nonmatchings/4F650", func_8004F1A4_4FDA4);

INCLUDE_ASM("asm/nonmatchings/4F650", func_8004F1B4_4FDB4);

INCLUDE_ASM("asm/nonmatchings/4F650", func_8004F5E8_501E8);

INCLUDE_ASM("asm/nonmatchings/4F650", func_8004F7F0_503F0);

INCLUDE_ASM("asm/nonmatchings/4F650", func_8004F9C8_505C8);

void func_8004F9D8_505D8(void) {
    SprKill(D_800DF7C8_E03C8);
    SprAnimKill(D_800DF7CA_E03CA.x);
    SprAnimKill(D_800DF7CA_E03CA.y);
    omDelObj(D_800DF7D0_E03D0);
    D_800DF7D0_E03D0 = NULL;
    D_800DF7C6_E03C6 &= ~0x3C;
}

INCLUDE_ASM("asm/nonmatchings/4F650", func_8004FA40_50640);

INCLUDE_ASM("asm/nonmatchings/4F650", func_8004FDD0_509D0);

INCLUDE_ASM("asm/nonmatchings/4F650", func_8004FDE0_509E0);

void func_8004FE88_50A88(void) {
    unkUserData* temp_s0;

    temp_s0 = HuPrcCurrentGet()->user_data;
    while (1) {
        switch (temp_s0->unk0) {
        case 0:
            func_8004F7F0_503F0(temp_s0->unk4);
            temp_s0->unk0++;
            break;
        case 1:
            if (D_800DF7C8_E03C8 == -1) {
                omDelPrcObj(NULL);
            }
            break;
        }
        
        HuPrcVSleep();       
    }
}

Process* func_8004FF20_50B20(void) {
    Process* temp_v0;
    unkUserData* temp_v0_2;

    temp_v0 = omAddPrcObj(func_8004FE88_50A88, 0, 0, 0x40);
    temp_v0_2 = HuMemMemoryAlloc(temp_v0->heap, sizeof(unkUserData));
    temp_v0->user_data = temp_v0_2;
    temp_v0_2->unk0 = 0;
    temp_v0_2->unk4 = 6;
    return temp_v0;
}

Process* func_8004FF78_50B78(void) {
    Process* temp_v0;
    unkUserData* temp_v0_2;

    temp_v0 = omAddPrcObj(func_8004FE88_50A88, 0, 0, 0x40);
    temp_v0_2 = HuMemMemoryAlloc(temp_v0->heap, sizeof(unkUserData));
    temp_v0->user_data = temp_v0_2;
    temp_v0_2->unk0 = 0;
    temp_v0_2->unk4 = 5;
    return temp_v0;
}

void func_8004FFD0_50BD0(void) {
    unkUserData* temp_s0 = HuPrcCurrentGet()->user_data;
    
    while (1) {  
        switch (temp_s0->unk0) {
        case 0:
            PlaySound(0x340);
            if (temp_s0->unk4 == 0) {
                D_800DF944_E0544 = GwSystem.total_turns - GwSystem.current_turn;
                switch (D_800DF944_E0544) {
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                    case 9:
                        func_8004F5E8_501E8();
                        break;
                }
            }
            func_8004F7F0_503F0(temp_s0->unk4);
            temp_s0->unk0++;
            break;
        case 1:
            if (D_800DF7C8_E03C8 == -1) {
                omDelPrcObj(NULL);
            }
            break;
        }
        
        HuPrcVSleep();        
    }
}

INCLUDE_ASM("asm/nonmatchings/4F650", func_800500CC_50CCC);

void func_80050144_50D44(void) {
    s32 temp_v0;
    s32 temp_v1;
    unkUserData* temp_s0;

    temp_s0 = HuPrcCurrentGet()->user_data;
    D_800DF944_E0544 = GwSystem.total_turns - GwSystem.current_turn;
    switch (D_800DF944_E0544) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 9:
            break;
        default:
            temp_s0->unk0 = 1;
    }

    while (1) {
        switch (temp_s0->unk0) {
            case 0:
                PlaySound(0x33F);
                func_8004F5E8_501E8();
                temp_s0->unk0 += 1;
                break;
            case 1:
                if (D_800DF7D0_E03D0 == 0) {
                    omDelPrcObj(0);
                }
                break;

        } 
        HuPrcVSleep();    
    }
}

Process* func_80050218_50E18(void) {
    Process* temp_v0;
    unkUserData* temp_v0_2;

    temp_v0 = omAddPrcObj(func_80050144_50D44, 0, 0, 64);
    temp_v0_2 = HuMemMemoryAlloc(temp_v0->heap, sizeof(unkUserData));
    temp_v0->user_data = temp_v0_2;
    temp_v0_2->unk0 = 0;
    return temp_v0;
}
