#include "common.h"
#include "game/malloc.h"

/* Board turn banners. C from MP1 src/47320.c (func_80046720 .. func_80048134); the rest have no
   reference and stay asm. func_8004F7F0_503F0 (MP1 func_800479B8) stays asm: its u16 table is this
   unit's rodata (D3928), which cannot be carved while func_8004F5E8_501E8 (no reference) uses the
   "%d" at D3924. */

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
f32 HuMathSin(f32);
void SprScaleSet(s16, s16, f32, f32);
void SprPosSet(s16, s16, s16, s16);
void func_80082488_83088(s16, s16, s32);
extern u8 D_800DF7E0_E03E0[]; /* MP1 D_800D6518 (unkCommonStruct0[]) */
extern u8 D_800DF854_E0454[]; /* MP1 D_800D6580 */
extern u8 D_800DF8C8_E04C8[]; /* MP1 D_800D65E8 */
extern s16 D_800DF800_E0400[];
extern s16 D_800DF874_E0474[];
extern s16 D_800DF8E8_E04E8[];
extern Vec2s D_800DF93C_E053C;
extern s16 D_800DF940_E0540;
extern u16 ContBtnTrg[4];


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

void func_8004EB58_4F758(omObjData* arg0) {
    s32 i;

    switch (arg0->work[0]) {
    case 0:
        arg0->rot.x = arg0->rot.x + 30.0f;
        arg0->scale.x = HuMathSin(arg0->rot.x) * 0.5f + 1.0f;

        for (i = 1; (((D_800DF944_E0544 + 1) / 10) + 1) >= i; i++) {
            SprScaleSet(D_800DF8E8_E04E8[D_800DF940_E0540], i, arg0->scale.x, arg0->scale.x);
        }

        if (arg0->rot.x >= 360.0f) {
            arg0->rot.x -= 360.0f;
        }

        return;
    case 1:
        for (i = 1; (((D_800DF944_E0544 + 1) / 10) + 1) >= i; i++) {
            func_80082488_83088(D_800DF8E8_E04E8[D_800DF940_E0540], i, arg0->work[1]);
        }

        for (i = 1; i < 5; i++) {
            func_80082488_83088(D_800DF800_E0400[D_800DF93C_E053C.x], i, arg0->work[1]);
            func_80082488_83088(D_800DF874_E0474[D_800DF93C_E053C.y], i, arg0->work[1]);
        }

        arg0->work[1] -= 0xA;

        if (arg0->work[1] == 0) {
            arg0->work[0] = 2;
            return;
        }
        break;
    case 2:
        func_8006AE14_6BA14(D_800DF7E0_E03E0);
        func_8006AE14_6BA14(D_800DF854_E0454);
        func_8006AE14_6BA14(D_800DF8C8_E04C8);
        D_800DF7D4_E03D4 = 0;
        omDelObj(arg0);
        break;
    }
}

void func_8004EE40_4FA40(omObjData* obj) {
    s32 i;

    switch (obj->work[0]) {
        case 0:
            obj->scale.x += 0.2f;
            SprScaleSet(D_800DF7C8_E03C8, 0, obj->scale.x, obj->scale.x);
            if (obj->scale.x >= 1.0f) {
                obj->work[0] = 1;
                obj->work[1] = 12;
            }
            break;
        case 1:
            if (obj->work[3] == 6) {
                obj->work[1]--;
                for (i = 0; i < 4; i++) {
                    if (!(gPlayers[i].flags & 1)) {
                        break;
                    }
                }
                if (i != 4) {
                    for (i = 0; i < 4; i++) {
                        if (!(gPlayers[i].flags & 1) && (ContBtnTrg[gPlayers[i].port] & 0xC000)) {
                            obj->work[0] = 2;
                        }
                    }
                } else if (obj->work[1] == 0) {
                    obj->work[0] = 2;
                }
                if (obj->work[2] == 0) {
                    SprPosSet(D_800DF7C8_E03C8, 0, 160, (s32)(HuMathSin(obj->rot.x) * 5.0f + 0.5f) + 120);
                    obj->rot.x += 10.0f;
                    if (obj->rot.x >= 360.0f) {
                        obj->rot.x -= 360.0f;
                    }
                } else {
                    obj->work[2]--;
                }
            } else if (obj->work[1] != 0) {
                obj->work[1]--;
            } else if ((gPlayers[obj->work[3]].flags & 1) || (ContBtnTrg[gPlayers[obj->work[3]].port] & 0xC000)) {
                obj->work[0] = 2;
            }
            break;
        case 2:
            SprKill(D_800DF7C8_E03C8);
            SprAnimKill(D_800DF7CA_E03CA.x);
            D_800DF7CA_E03CA.x = D_800DF7C8_E03C8 = -1;
            if (D_800DF7D4_E03D4 != NULL) {
                func_8006AE14_6BA14(D_800DF7E0_E03E0);
                func_8006AE14_6BA14(D_800DF854_E0454);
                func_8006AE14_6BA14(D_800DF8C8_E04C8);
                omDelObj(D_800DF7D4_E03D4);
                D_800DF7D4_E03D4 = NULL;
            }
            D_800DF7D0_E03D0 = NULL;
            omDelObj(obj);
            break;
    }
}

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
