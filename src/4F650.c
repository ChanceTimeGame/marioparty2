#include "common.h"
#include "game/malloc.h"
#include "game/data.h"
#include "game/gamemes.h"

/* Board turn banners. C from MP1 src/47320.c (func_80046720 .. func_80048134). This unit's rodata
   (the "%d" at D3924 and the u16 banner table at D3928) stays in the data blob: the C names it
   through externs (D_800D2D24_D3924, D_800D2D28_D3928). */

typedef struct unkUserData {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} unkUserData;

extern GAMEMES D_800DF750_E0350; /* MP1 unkCommonStruct0 */
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
void func_80082488_83088(s16, s16, u16);
extern GAMEMES D_800DF7E0_E03E0[3]; /* MP1 D_800D6518 (unkCommonStruct0[]) */
extern u8 D_800DF854_E0454[]; /* MP1 D_800D6580 */
extern u8 D_800DF8C8_E04C8[]; /* MP1 D_800D65E8 */
extern s16 D_800DF800_E0400[];
extern s16 D_800DF874_E0474[];
extern s16 D_800DF8E8_E04E8[];
extern Vec2s D_800DF93C_E053C;
extern s16 D_800DF940_E0540;
extern u16 ContBtnTrg[4];
extern char* D_800CC0B0_CCCB0[]; /* banner texts: MP1 D_800C4EE0 */
extern Vec2s D_800CC0C4_CCCC4[]; /* banner positions: MP1 D_800C4EF8 */
extern char D_800DF958_E0558[]; /* turn count text */
extern s16 D_800DF948_E0548;
extern s16 D_800DF94A_E054A;
extern s16 D_800DF94C_E054C[5];
extern s16 D_800DF956_E0556;
void func_8004FFD0_50BD0(void);
void func_8004F1B4_4FDB4(omObjData*);
s32 func_80060A1C_6161C(void);
void func_8004AD34_4B934(s32);
void func_80082450_83050(s16, s16, s32, s32, s32);
extern char* D_800CC090_CCC90[]; /* MP1 D_800C4ED0 */
extern s8 D_800CC0A8_CCCA8[];
extern s8 D_800CC0BC_CCCBC[]; /* MP1 D_800C4EEC */
extern u8 D_800DF7C5_E03C5;
extern char D_800D2D24_D3924[]; /* "%d" */
typedef struct BannerFiles {
    u16 file[8];
} BannerFiles;
extern BannerFiles D_800D2D28_D3928; /* character banner files 0x133-0x139 */
s16 func_8006A608_6B208(void* mes, char* str, u8 arg2, s16 arg3, s16 arg4); /* MP1 GMesFontMesCreate */
s16 SprCreate(s32, s32);
s16 SprAnimRead(void*);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprPrioSet(s16 group, s16 member, u16 prio);
void SprAttrSet(s16 group, s16 member, s32 attr);
void func_8004EB58_4F758(omObjData* arg0);
void func_8004EE40_4FA40(omObjData* obj);
/* .data (0xCCC90-0xCCCE0) */
extern char D_800D2CFC_D38FC[];
extern char D_800D2CEC_D38EC[];
extern char D_800D2CDC_D38DC[];
extern char D_800D2CCC_D38CC[];
extern char D_800D2CBC_D38BC[];
extern char D_800D2CAC_D38AC[];
extern char D_800D2D1C_D391C[];
extern char D_800D2D14_D3914[];
extern char D_800D2D0C_D390C[];
char* D_800CC090_CCC90[] = {
    D_800D2CFC_D38FC, D_800D2CEC_D38EC, D_800D2CDC_D38DC,
    D_800D2CCC_D38CC, D_800D2CBC_D38BC, D_800D2CAC_D38AC,
};
s8 D_800CC0A8_CCCA8[] = { 13, 15, 15, 12, 12, 12 }; /* characters in each D_800CC090_CCC90 text */
char* D_800CC0B0_CCCB0[] = { D_800D2D1C_D391C, D_800D2D14_D3914, D_800D2D0C_D390C };
s8 D_800CC0BC_CCCBC[] = { -6, 0, 0, 0, 0, 0 };
Vec2s D_800CC0C4_CCCC4[] = { { 80, 88 }, { 240, 88 }, { 155, 88 }, { 104, 88 }, { 216, 88 }, { 640, 480 } };




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
        func_8006AE14_6BA14(&D_800DF750_E0350);
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

extern u8 D_800DF7D8_E03D8;

void func_8004F1A4_4FDA4(void) {
    D_800DF7D8_E03D8 = 1;
}

/* Banner object (func_8004FA40_50640): slide the title in, pulse the sprite row and grow the
   text. work[3] and work[2] delay the row and the text; work[0] indexes D_800CC0A8_CCCA8 and work[1]
   is the text's string group. */
void func_8004F1B4_4FDB4(omObjData* obj) {
    s32 i;
    s16 alpha;
    f32 scale;

    if (obj->trans.x >= -100.0f) {
        obj->trans.x -= 16.0f;
    }
    SprPosSet(D_800DF948_E0548, 0, obj->trans.x, 0x3C);
    if (obj->work[3] != 0) {
        obj->work[3]--;
    } else {
        if ((obj->trans.z += 16.0f) >= 1000.0f) {
            obj->trans.z = 1000.0f;
        }
        if ((obj->rot.y += 8.0f) >= 360.0f) {
            obj->rot.y -= 360.0f;
        }
        for (i = 0; i < 5; i++) {
            alpha = (s32)obj->trans.z - i * 24;
            if (alpha > 256) {
                alpha = 256;
            }
            if (alpha < 0) {
                alpha = 0;
            }
            scale = (obj->trans.z - i * 24) / 256.0f;
            if (scale >= 1.0f) {
                scale = 1.0f;
            }
            if (scale <= 0.0f) {
                scale = 0.0f;
            }
            obj->trans.y = HuMathSin(i * 90 + obj->rot.y) * 5.0f;
            SprPosSet(D_800DF94C_E054C[i], 0, 0xF5 - i * 0x28, obj->trans.y + 60.0f);
            func_80082488_83088(D_800DF94C_E054C[i], 0, alpha);
            SprScaleSet(D_800DF94C_E054C[i], 0, scale, scale);
        }
    }
    if (obj->work[2] != 0) {
        obj->work[2]--;
        return;
    }
    if ((obj->scale.x += 0.05f) >= 1.0f) {
        obj->scale.x = 1.0f;
        if ((obj->rot.z += 20.0f) >= 360.0f) {
            obj->rot.z -= 360.0f;
        }
    }
    SprPosSet(D_800DF750_E0350.strGId[D_800DF7C4_E03C4], 0, obj->rot.x + 80.0f, 2.0f * HuMathSin(obj->rot.z) + 60.0f);
    for (i = 1; i <= D_800CC0A8_CCCA8[obj->work[0]]; i++) {
        SprScaleSet(D_800DF750_E0350.strGId[obj->work[1]], i, 1.0f, obj->scale.x);
    }
}

/* MP1 func_800477AC (src/47320.c). D_800DF93C_E053C and D_800DF940_E0540 are read as one s16[3]. */
void func_8004F5E8_501E8(void) {
    omObjData* obj;
    s32 i;

    for (i = 0; i < 3; i++) {
        if (i != 2) {
            if (i == 1 && D_800DF944_E0544 == 0) {
                ((s16*)&D_800DF93C_E053C)[i] = func_8006A608_6B208(&D_800DF7E0_E03E0[i], D_800CC0B0_CCCB0[2], 1, -1, -1);
            } else {
                ((s16*)&D_800DF93C_E053C)[i] = func_8006A608_6B208(&D_800DF7E0_E03E0[i], D_800CC0B0_CCCB0[i], 1, -1, -1);
            }
        } else {
            sprintf(D_800DF958_E0558, D_800D2D24_D3924, D_800DF944_E0544 + 1);
            ((s16*)&D_800DF93C_E053C)[i] = func_8006A608_6B208(&D_800DF7E0_E03E0[i], D_800DF958_E0558, 1, -1, -1);
        }
        if (D_800DF944_E0544 == 0) {
            SprPosSet(D_800DF7E0_E03E0[i].strGId[((s16*)&D_800DF93C_E053C)[i]], 0, D_800CC0C4_CCCC4[i + 3].x,
                      D_800CC0C4_CCCC4[i + 3].y);
        } else {
            SprPosSet(D_800DF7E0_E03E0[i].strGId[((s16*)&D_800DF93C_E053C)[i]], 0, D_800CC0C4_CCCC4[i].x,
                      D_800CC0C4_CCCC4[i].y);
        }
    }
    obj = omAddObj(-0x8000, 0, 0, -1, func_8004EB58_4F758);
    D_800DF7D4_E03D4 = obj;
    obj->rot.x = 0.0f;
    obj->work[0] = 0;
}

/* MP1 func_800479B8 (src/47320.c): its local table is the rodata BannerFiles here. */
void func_8004F7F0_503F0(s32 arg0) {
    omObjData* obj;
    void* file;
    BannerFiles files = D_800D2D28_D3928;

    D_800DF7C8_E03C8 = SprCreate(1, 5);
    if (arg0 >= 6) {
        file = DataRead(files.file[arg0] | 0xA0000);
    } else {
        file = DataRead(files.file[gPlayers[arg0].character] | 0xA0000);
    }
    D_800DF7CA_E03CA.x = SprAnimRead(file);
    DataClose(file);
    SprAnimSet(D_800DF7C8_E03C8, 0, D_800DF7CA_E03CA.x, 0);
    SprPrioSet(D_800DF7C8_E03C8, 0, 0x10);
    SprAttrSet(D_800DF7C8_E03C8, 0, 0x1000);
    SprPosSet(D_800DF7C8_E03C8, 0, 0xA0, 0x78);
    obj = omAddObj(-0x8000, 0, 0, -1, func_8004EE40_4FA40);
    D_800DF7D0_E03D0 = obj;
    obj->scale.x = 0.0f;
    obj->rot.x = 180.0f;
    obj->work[2] = 0x1E;
    obj->work[0] = 1;
    obj->work[1] = 0xC;
    if (D_800DF7D4_E03D4 != NULL) {
        obj->work[1] = 0x18;
    }
    obj->work[3] = arg0;
    if (arg0 >= 4) {
        obj->work[3] = 4;
    }
}

s32 func_8004F9C8_505C8(void) {
    return D_800DF7C6_E03C6 & 4;
}

void func_8004F9D8_505D8(void) {
    SprKill(D_800DF7C8_E03C8);
    SprAnimKill(D_800DF7CA_E03CA.x);
    SprAnimKill(D_800DF7CA_E03CA.y);
    omDelObj(D_800DF7D0_E03D0);
    D_800DF7D0_E03D0 = NULL;
    D_800DF7C6_E03C6 &= ~0x3C;
}

/* MP1 func_80047BE0 (src/47320.c), with MP2's sprite row. NON_MATCHING: GCC keeps the loop's 0.0f
   scale in $f20 where retail passes it in a2/a3 directly (masked 15). */
#ifdef NON_MATCHING
void func_8004FA40_50640(s32 arg0) {
    s32 var_s2;
    s32 i;
    void* file;
    omObjData* obj;

    if (!(D_800DF7C6_E03C6 & 4) && ((var_s2 = func_80060A1C_6161C(), (((~var_s2 == 0) | (arg0 != 0)) == 0)) ||
                                     (var_s2 = arg0 + 2, (arg0 != 0)))) {
        D_800DF948_E0548 = SprCreate(1, 5);
        file = DataRead(0xA0162);
        D_800DF94A_E054A = SprAnimRead(file);
        DataClose(file);
        SprAnimSet(D_800DF948_E0548, 0, D_800DF94A_E054A, 0);
        SprPrioSet(D_800DF948_E0548, 0, 4);
        SprAttrSet(D_800DF948_E0548, 0, 0x1000);
        SprPosSet(D_800DF948_E0548, 0, 0x190, 0x3C);
        file = DataRead(0xA0163);
        D_800DF956_E0556 = SprAnimRead(file);
        DataClose(file);
        for (i = 0; i < 5; i++) {
            SprAnimSet(D_800DF94C_E054C[i] = SprCreate(1, 5), 0, D_800DF956_E0556, 0);
            func_80082450_83050(D_800DF94C_E054C[i], 0, 0xFF, 0xFF, 0xFF);
            SprPrioSet(D_800DF94C_E054C[i], 0, 6);
            SprAttrSet(D_800DF94C_E054C[i], 0, 0x1000);
            SprPosSet(D_800DF94C_E054C[i], 0, 0xF5 - i * 0x28, 0x3C);
            func_80082488_83088(D_800DF94C_E054C[i], 0, 0);
            SprScaleSet(D_800DF94C_E054C[i], 0, 0.0f, 0.0f);
        }
        D_800DF7C4_E03C4 = func_8006A608_6B208(&D_800DF750_E0350, D_800CC090_CCC90[var_s2], 0, 0, 0);
        SprPosSet(D_800DF750_E0350.strGId[D_800DF7C4_E03C4], 0, D_800CC0BC_CCCBC[var_s2] + 0x50, 0x3C);
        for (i = 1; i <= D_800CC0A8_CCCA8[var_s2]; i++) {
            SprScaleSet(D_800DF750_E0350.strGId[D_800DF7C4_E03C4], i, 1.0f, 0.0f);
        }
        obj = omAddObj(-0x8000, 0, 0, -1, func_8004F1B4_4FDB4);
        D_800DF7D0_E03D0 = obj;
        obj->scale.x = 0.0f;
        obj->trans.x = 400.0f;
        obj->trans.z = 0.0f;
        obj->rot.x = D_800CC0BC_CCCBC[var_s2];
        obj->rot.y = 0.0f;
        obj->rot.z = 0.0f;
        obj->work[0] = var_s2;
        obj->work[1] = D_800DF7C5_E03C5;
        obj->work[2] = 0xF;
        obj->work[3] = 7;
        D_800DF7C6_E03C6 = 0x26;
        if (var_s2 >= 3) {
            func_8004AD34_4B934(var_s2 - 3);
        } else {
            func_8004AD34_4B934(-1);
        }
        PlaySound(0x3AF);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/4F650", func_8004FA40_50640);
#endif

s32 func_8004FDD0_509D0(void) {
    return D_800DF7C6_E03C6 & 0xC;
}

/* MP1 func_80047D48 (src/47320.c), with MP2's extra sprites. */
void func_8004FDE0_509E0(void) {
    s32 i;

    SprKill(D_800DF948_E0548);
    SprAnimKill(D_800DF94A_E054A);
    for (i = 0; i < 5; i++) {
        SprKill(D_800DF94C_E054C[i]);
    }
    SprAnimKill(D_800DF956_E0556);
    omDelObj(D_800DF7D0_E03D0);
    D_800DF7D0_E03D0 = NULL;
    func_8006AE14_6BA14(&D_800DF750_E0350);
    D_800DF7C6_E03C6 &= ~0x3C;
}

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

/* MP1 func_80048000 (src/47320.c) */
Process* func_800500CC_50CCC(u32 arg0) {
    Process* process;
    unkUserData* work;

    process = omAddPrcObj(func_8004FFD0_50BD0, 0, 0, 0x40);
    work = HuMemMemoryAlloc(process->heap, sizeof(unkUserData));
    process->user_data = work;
    work->unk0 = 0;
    if (arg0 < 4) {
        work->unk4 = arg0;
    } else {
        work->unk4 = 7;
    }
    return process;
}

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
