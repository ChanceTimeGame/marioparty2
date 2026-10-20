#include "common.h"
#include "game/data.h"
#include "game/malloc.h"
#include "game/sprite.h"
#include "game/hmfman.h"

/* Sprite-model slots and the coin-sparkle effect. Functions with C come from MP1 src/1EA70.c
   (and two one-liners from MP1 ovl_15/ovl_28); the rest is asm. */

typedef struct unk1EA70StructC {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16* unk_04;
    /* 0x08 */ void* unk_08;
} unk1EA70StructC; // sizeof 0xC

typedef struct unk1EA70Struct20 {
    /* 0x00 */ char unk_00[2];
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ char unk_14[4];
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ char unk_1E[2];
} unk1EA70Struct20; // sizeof 0x20

typedef struct unk1EA70Struct1C {
    /* 0x00 */ unk1EA70Struct20* unk_00;
    /* 0x04 */ u8* unk_04;
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ u8 unk_09;
    /* 0x0A */ u8 unk_0A;
    /* 0x0B */ char unk_0B;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ u16 unk_18;
    /* 0x1A */ char unk_1A[2];
} unk1EA70Struct1C; // sizeof 0x1C

extern u8 D_800C9C50_CA850;
extern u8 D_800C9D00_CA900[], D_800C9D14_CA914[], D_800C9D28_CA928[], D_800C9D3C_CA93C[], D_800C9D50_CA950[];
extern void* D_800F8C20_F9820;
extern unk1EA70Struct1C* D_800F904C_F9C4C;
extern u16 D_800FA18C_FAD8C;
extern void* D_800FA194_FAD94;
extern void* D_800FD448_FE048;
extern void* D_800FD804_FE404;
extern u8 D_800FDBCA_FE7CA;
extern u8 D_800FDBE0_FE7E0;

void* func_80027154_27D54(s32, s32);
void HuMemFree(void*);
void func_800273A8_27FA8(s16);
void HmfModelObjAttrSet(s16, s32, s32);
void func_800298A4_2A4A4(s16, s32, s32);
void func_80021160_21D60(s16, s32, s32);
void func_8003E8E4_3F4E4(s16);
void func_800283DC_28FDC(s16);
s16 func_8003DF08_3EB08(void*);
u16 func_80020EBC_21ABC(void*, s32, s32);
void func_800247EC_253EC(unk1EA70Struct1C*, f32, f32, f32);
s16 func_800244F4_250F4(unk1EA70Struct1C*, s16, f32, f32, f32, s16);
void func_80029F2C_2AB2C(s16, s32);
void func_80020E70_21A70(void);
void func_8002308C_23C8C(s32 index);
void func_80021424_22024(s16 index, u32 arg1);
void func_800246F8_252F8(unk1EA70Struct1C* arg0, s16 arg1, s16 arg2);
unk1EA70Struct1C* func_800240C8_24CC8(s32 arg0, s16 arg1);
void func_800242BC_24EBC(unk1EA70Struct1C*);
void func_80024D58_25958(void);

void func_80020D20_21920(s16 arg0) {
    s16 i;
    unk_800ECDE0* temp_v1;

    D_800FA18C_FAD8C = arg0;
    for (i = 0; i < D_800FDBCA_FE7CA; i++) {
        *(&D_800F8C20_F9820 + i) = func_80027154_27D54(arg0 << 7, 0x7530);
        *(&D_800FD448_FE048 + i) = func_80027154_27D54(arg0 << 8, 0x7530);
    }
    D_800F86D8_F92D8 = func_80027154_27D54(arg0 * sizeof(*D_800F86D8_F92D8), 0x7530);
    for (i = 0; i < arg0; i++) {
        temp_v1 = &D_800F86D8_F92D8[i];
        temp_v1->unk00 = -1;
    }
    D_800C9C50_CA850 = 1;
    func_80020E70_21A70();
}

void func_80020E70_21A70() {
    u8 temp_v0;

    if (D_800C9C50_CA850 != 0) {
        temp_v0 = D_800FDBE0_FE7E0;
        D_800FA194_FAD94 = *(&D_800F8C20_F9820 + temp_v0);
        D_800FD804_FE404 = *(&D_800FD448_FE048 + temp_v0);
    }
}

INCLUDE_ASM("asm/nonmatchings/21920", func_80020EBC_21ABC);

INCLUDE_ASM("asm/nonmatchings/21920", func_8002109C_21C9C);

INCLUDE_ASM("asm/nonmatchings/21920", func_80021160_21D60);

void func_80021198_21D98(s16 index, u16 arg1) {
    D_800F86D8_F92D8[index].unk04 = arg1;
}

u16 func_800211C0_21DC0(s16 index) {
    return D_800F86D8_F92D8[index].unk04;
}

void func_800211E8_21DE8(s16 index, u8 arg1) {
    s32 unk_var;

    if (index != -1) {
        D_800F86D8_F92D8[index].unk12 = arg1;
        unk_var = (arg1 != 0xFF) << 0x10;
        HmfModelObjAttrSet(D_800F86D8_F92D8[index].unk00, 0x10000, unk_var);
    }
}

void func_80021250_21E50(s16 index, u8 arg1, u8 arg2, u8 arg3) {
    if (index != -1) {
        D_800F86D8_F92D8[index].unk13 = arg1;
        D_800F86D8_F92D8[index].unk14 = arg2;
        D_800F86D8_F92D8[index].unk15 = arg3;
    }
}

void func_800212A4_21EA4(s16 index) {
    unk_800ECDE0* temp_v1;

    temp_v1 = &D_800F86D8_F92D8[index];
    temp_v1->unk0A = 0;
    temp_v1->unk04 = 0;
    temp_v1->unk10 = temp_v1->unk10 & 0xFF7F;
    func_800298A4_2A4A4(temp_v1->unk00, 4, 0);
}

void func_800212FC_21EFC(s16 index, s8 arg1, s8 arg2, s8 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8) {
    if (index != -1) {
        func_80021160_21D60(index, 0x40, 0x40);
        D_800F86D8_F92D8[index].unk16 = arg1;
        D_800F86D8_F92D8[index].unk17 = arg2;
        D_800F86D8_F92D8[index].unk18 = arg3;
        D_800F86D8_F92D8[index].unk19 = arg4;
        D_800F86D8_F92D8[index].unk1A = arg5;
        D_800F86D8_F92D8[index].unk1B = arg6;
        D_800F86D8_F92D8[index].unk1C = arg7;
        D_800F86D8_F92D8[index].unk1D = arg8;
    }
}

void func_80021424_22024(s16 index, u32 arg1) {
    if (index != -1) {
        func_80021160_21D60(index, 0x40, 0x40);
        D_800F86D8_F92D8[index].unk20 = arg1;
        D_800F86D8_F92D8[index].unk0E = 0;
        D_800F86D8_F92D8[index].unk0C = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/21920", func_80021490_22090);

void func_8002308C_23C8C(s32 index) {
    if (D_800C9C50_CA850 != 0) {
        if ((u16) D_800F86D8_F92D8[index].unk02 != 0xFFFF) {
            func_8003E8E4_3F4E4(D_800F86D8_F92D8[index].unk02);
        }
        func_800283DC_28FDC(D_800F86D8_F92D8[index].unk00);
        D_800F86D8_F92D8[index].unk00 = -1;
    }
}

void func_80023124_23D24() {
    s16 i;

    if (D_800C9C50_CA850 != 0) {
        for (i = 0; i < D_800FA18C_FAD8C; i++) {
            if (D_800F86D8_F92D8[i].unk00 != -1) {
                func_8003E8E4_3F4E4(D_800F86D8_F92D8[i].unk02);
            }
        }
        func_800273A8_27FA8(0x7530);
        D_800C9C50_CA850 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/21920", func_800231D8_23DD8);

INCLUDE_ASM("asm/nonmatchings/21920", func_800232FC_23EFC);

INCLUDE_ASM("asm/nonmatchings/21920", func_80023434_24034);

INCLUDE_ASM("asm/nonmatchings/21920", func_80023554_24154);

INCLUDE_ASM("asm/nonmatchings/21920", func_80023680_24280);

INCLUDE_ASM("asm/nonmatchings/21920", func_80023A08_24608);

INCLUDE_ASM("asm/nonmatchings/21920", func_80023B7C_2477C);

void func_80023D74_24974(unk1EA70StructC* arg0) {
    HuMemMemoryFreePerm(arg0->unk_08);
    HuMemMemoryFreePerm(arg0->unk_04);
    HuMemMemoryFreePerm(arg0);
}

INCLUDE_ASM("asm/nonmatchings/21920", func_80023DAC_249AC);

unk1EA70Struct1C* func_800240C8_24CC8(s32 arg0, s16 arg1) {
    unk1EA70Struct1C* ret;
    void* file;
    s16 sprite;
    s16 i;
    u16 idx;

    ret = func_80027154_27D54(sizeof(unk1EA70Struct1C), 0x7918);
    ret->unk_18 = arg1;
    ret->unk_00 = func_80027154_27D54(arg1 * sizeof(unk1EA70Struct20), 0x7918);
    ret->unk_04 = func_80027154_27D54(arg1, 0x7918);
    file = DataReadTemp(arg0);
    sprite = func_8003DF08_3EB08(file);
    DataCloseTemp(file);
    for (i = 0; i < arg1; i++) {
        idx = func_80020EBC_21ABC((void*) -1, 0x284, 8);
        ret->unk_00[i].unk_1C = idx;
        D_800F86D8_F92D8[(s16) idx].unk02 = sprite;
        func_80021160_21D60(idx, 4, 4);
        ret->unk_04[i] = 0;
    }
    ret->unk_14 = 1.0f;
    ret->unk_10 = 1.0f;
    ret->unk_0C = 1.0f;
    ret->unk_0A = 0xFF;
    ret->unk_09 = 0xFF;
    ret->unk_08 = 0xFF;
    return ret;
}

void func_80024234_24E34(unk1EA70Struct1C* arg0) {
    s16 i;

    for (i = 0; i < arg0->unk_18; i++) {
        func_8002308C_23C8C(arg0->unk_00[i].unk_1C);
    }
    HuMemFree(arg0->unk_04);
    HuMemFree(arg0->unk_00);
    HuMemFree(arg0);
}

INCLUDE_ASM("asm/nonmatchings/21920", func_800242BC_24EBC);

INCLUDE_ASM("asm/nonmatchings/21920", func_800244F4_250F4);

void func_800246F8_252F8(unk1EA70Struct1C* arg0, s16 arg1, s16 arg2) {
    s16 obj;

    if (arg1 == -1) {
        return;
    }
    obj = D_800F86D8_F92D8[arg0->unk_00[arg1].unk_1C].unk00;
    if (arg2 == 0) {
        func_800298A4_2A4A4(obj, 4, 0);
        D_800F86D8_F92D8[arg0->unk_00[arg1].unk_1C].unk04 = 0;
        arg0->unk_00[arg1].unk_06 = 0;
    } else {
        func_800298A4_2A4A4(obj, 4, 4);
        arg0->unk_00[arg1].unk_06 = arg2;
    }
}

INCLUDE_ASM("asm/nonmatchings/21920", func_800247EC_253EC);

INCLUDE_ASM("asm/nonmatchings/21920", func_800247FC_253FC);

INCLUDE_ASM("asm/nonmatchings/21920", func_8002480C_2540C);

INCLUDE_ASM("asm/nonmatchings/21920", func_80024938_25538);

INCLUDE_ASM("asm/nonmatchings/21920", func_80024AB4_256B4);

INCLUDE_ASM("asm/nonmatchings/21920", func_80024B00_25700);

void func_80024D10_25910(void) {
    omAddObj(0x7F76, 0, 0, -1, func_80024D58_25958);
    D_800F904C_F9C4C = func_800240C8_24CC8(0x13, 10);
}

void func_80024D58_25958(void) {
    func_800242BC_24EBC(D_800F904C_F9C4C);
}

void func_80024D78_25978(s16 arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 x;
    f32 y;
    f32 z;
    f32 scale;
    s16 i;
    s16 slot;
    s16 idx;
    s32 spr;
    s32 pad[2];

    if (arg0 == 0) {
        func_800247EC_253EC(D_800F904C_F9C4C, 12.0f, 12.0f, 12.0f);
        idx = D_800F904C_F9C4C->unk_00[func_800244F4_250F4(D_800F904C_F9C4C, 0, arg1, arg2, arg3, 4)].unk_1C;
        HmfModelObjAttrSet(D_800F86D8_F92D8[idx].unk00, 0x70000000, 0x70000000);
        func_80029F2C_2AB2C(D_800F86D8_F92D8[idx].unk00, 0x1400);
        func_80021424_22024(idx, (u32) D_800C9D14_CA914);
        D_800F86D8_F92D8[idx].unk10 |= 0x100;
    } else if (arg0 == 1) {
        func_800247EC_253EC(D_800F904C_F9C4C, 12.0f, 12.0f, 12.0f);
        idx = D_800F904C_F9C4C->unk_00[func_800244F4_250F4(D_800F904C_F9C4C, 0, arg1, arg2, arg3, 4)].unk_1C;
        HmfModelObjAttrSet(D_800F86D8_F92D8[idx].unk00, 0x70000000, 0x70000000);
        func_80029F2C_2AB2C(D_800F86D8_F92D8[idx].unk00, 0x1400);
        func_80021424_22024(idx, (u32) D_800C9D50_CA950);
        D_800F86D8_F92D8[idx].unk10 |= 0x100;
    } else {
        for (i = 0; i < 4; i++) {
            if ((i == 0) | (i == 3)) {
                x = arg1;
                y = arg2;
                z = arg3;
            } else {
                x = arg1 + ((rand8() & 0x1F) - 0x10) * 12.0f;
                y = arg2 + ((rand8() & 0x1F) - 0x10) * 12.0f;
                z = arg3 + ((rand8() & 0x1F) - 0x10) * 1.2f;
            }
            scale = (s16) (i * 2.4f + 12.0f);
            func_800247EC_253EC(D_800F904C_F9C4C, scale, scale, scale);
            slot = func_800244F4_250F4(D_800F904C_F9C4C, 0, x, y, z, 4);
            if (slot == -1) {
                break;
            }
            spr = (u16) D_800F904C_F9C4C->unk_00[slot].unk_1C;
            idx = D_800F904C_F9C4C->unk_00[slot].unk_1C;
            HmfModelObjAttrSet(D_800F86D8_F92D8[idx].unk00, 0x70000000, 0x70000000);
            func_80029F2C_2AB2C(D_800F86D8_F92D8[idx].unk00, 0x1400);
            switch (i) {
                case 0:
                    func_80021424_22024(spr, (u32) D_800C9D00_CA900);
                    break;
                case 1:
                    func_80021424_22024(spr, (u32) D_800C9D14_CA914);
                    break;
                case 2:
                    func_80021424_22024(spr, (u32) D_800C9D28_CA928);
                    break;
                case 3:
                    func_80021424_22024(spr, (u32) D_800C9D3C_CA93C);
                    break;
            }
            func_800246F8_252F8(D_800F904C_F9C4C, slot, i * 4);
            D_800F86D8_F92D8[(s16) spr].unk10 |= 0x100;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/21920", func_8002523C_25E3C);

/* MP1's neighbour in src/1EA70.c (func_8001E2D0) reads a field of a table by index the same way. */
void func_8002529C_25E9C(s16 index, s32 arg1) {
    D_800F92B4_F9EB4[index].unk18 = arg1;
}

INCLUDE_ASM("asm/nonmatchings/21920", func_800252C4_25EC4);

INCLUDE_ASM("asm/nonmatchings/21920", func_80025384_25F84);

INCLUDE_ASM("asm/nonmatchings/21920", func_80025554_26154);

s16 func_80025684_26284(s32 id) {
    void* file;
    s16 sprite;

    file = DataRead(id);
    sprite = func_8003DF08_3EB08(file);
    DataClose(file);
    return sprite;
}

INCLUDE_ASM("asm/nonmatchings/21920", func_800256CC_262CC);

INCLUDE_ASM("asm/nonmatchings/21920", func_80025718_26318);
