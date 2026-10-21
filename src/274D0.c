#include "common.h"
#include "game/hmfman.h"
#include "game/camera.h"

/* ---- Model manager (MP3 src/hmfman.c, MP1 src/24740.c); MP3's HmfModel layout ---- */

typedef struct {
    /* 0x00 */ f32 v[8];
} unk24740Floats8;

#define HU3D_MODEL_MAX 128

extern s32 D_800FDC98_FE898;
extern s32 D_800FD848_FE448;
extern u8 D_800F94A4_FA0A4;
extern void* D_800F8F80_F9B80[2];
extern s16 D_800F64B2_F70B2;
extern u8 D_800C9B70_CA770;
extern u8 D_800C9B71_CA771;
extern u8 D_800C9B72_CA772;
extern u8 D_800FA60C_FB20C;
extern s16 D_800CA028_CAC28;
extern u8 D_800F8C48_F9848;
extern s16 D_801027FA_1033FA;
extern s16 D_800F8C54_F9854;
extern u8 D_800FC9E9_FD5E9;
extern u8 D_8010002C_100C2C;
extern u8 D_800F9D2C_FA92C;

void func_8002F960_30560(void* (*arg0)(s32), void (*arg1)(void*), u16 arg2, u16 arg3, u16 arg4, u8 arg5);
void func_80038DD0_399D0(void);
void func_8002FB6C_3076C(void);
s16 func_80027D3C_2893C(s16);
s16 func_80027FA4_28BA4(u32, void*, u8);
void func_80025884_26484(f32 (*)[4], f32, f32, f32); /* MP1 MtxRotate */
void func_800B2060_B2C60(f32 (*)[4], f32, f32, f32);
void func_8002741C_2801C(void);
void func_8003847C_3907C(HmfData*, char*, HmfData*);
s16 func_80038398_38F98(HmfData*, char*);
void* func_8003CF84_3DB84(HmfData*);
void func_80029A8C_2A68C(s16);
void func_800298A4_2A4A4(s16 arg0, s32 arg1, s32 arg2);
void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2);
void* HuMemAlloc(s32 size);
void func_80027274_27E74(s16 arg0);
void func_800273A8_27FA8(s16 arg0);

typedef struct unkMallocBlockStruct {
/* 0x00 */ void* unk_00;
/* 0x04 */ s8 unk_04;
/* 0x05 */ char unk_05;
/* 0x06 */ s16 unk_06;
/* 0x08 */ s32 unk_08;
/* 0x0C */ s32 unk_0C;
/* 0x10 */ struct unkMallocBlockStruct* unk_10;
/* 0x14 */ struct unkMallocBlockStruct* unk_14;
} unkMallocBlockStruct; //sizeof 0x18

extern s16 D_800C9E50_CAA50;
extern s16 D_800F64C0_F70C0;
extern unkMallocBlockStruct* D_800FC830_FD430;
extern void (*D_800FD440_FE040)(void*);
extern u8 D_800FDBCA_FE7CA;
extern s32 D_800FDC98_FE898;
extern void* (*D_8010164C_10224C)(s32);
extern unkMallocBlockStruct* D_801027FC_1033FC;
extern unkMallocBlockStruct* D_800FD3E0_FDFE0;

void* func_80027154_27D54(s32, s16);
void func_80027230_27E30(unkMallocBlockStruct*);
void func_80027274_27E74(s16 arg0);
void func_8002742C_2802C(void);

/* Model lights (MP3 src/hmflight.c), heap blocks (MP1 src/engine/mallocblock.c, MP3
   src/mallocblock.c) and model manager helpers (MP3 src/hmfman.c, MP1 src/24740.c). */

typedef struct {
    /* 0x00 */ s8 r;
    /* 0x01 */ s8 g;
    /* 0x02 */ s8 b;
    /* 0x03 */ u8 stat;
    /* 0x04 */ s8 unk04;
    /* 0x05 */ s8 unk05;
    /* 0x06 */ s8 unk06;
} UnkLightData_unk02; // Size 7

typedef struct {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ UnkLightData_unk02 unk02[8];
    /* 0x3A */ char unk3A[6];
    /* 0x40 */ Light unk40[4][8][8];
} UnkLightData; // Size 0x1040

extern HuCamMtxs *D_800FC88C_FD48C;
extern Light *D_800F8424_F9024;
extern UnkLightData *D_800FA620_FB220;
extern u8 D_800FDBE0_FE7E0;

f32 func_800B1830_B2430(f32);

/* MP3 HmfLightInit (src/hmflight.c) */
void func_800268D0_274D0(void) {
    s16 var_a1;

    if (D_800FA620_FB220 == NULL) {
        D_800FA620_FB220 = HuMemAlloc(sizeof(UnkLightData));
    }
    for (var_a1 = 0; var_a1 < 8; var_a1++) {
        D_800FA620_FB220->unk02[var_a1].stat = 0;
        D_800FA620_FB220->unk02[var_a1].r =
            D_800FA620_FB220->unk02[var_a1].g =
                D_800FA620_FB220->unk02[var_a1].b = 0x40;
        D_800FA620_FB220->unk02[var_a1].unk04 =
            D_800FA620_FB220->unk02[var_a1].unk05 = 0;
        D_800FA620_FB220->unk02[var_a1].unk06 = 100;
    }
    D_800FA620_FB220->unk00 = 1;
}

void func_80026994_27594(void) {
}

void func_8002699C_2759C(s16 arg0) {
    s16 var_s1;

    D_800F8424_F9024 = D_800FA620_FB220->unk40[D_800FDBE0_FE7E0][arg0];
    for (var_s1 = 0; var_s1 < D_800FA620_FB220->unk00 + 1; var_s1++) {
        Light *temp_s0 = &D_800F8424_F9024[var_s1];

        temp_s0->l.col[0] = temp_s0->l.colc[0] = D_800FA620_FB220->unk02[var_s1].r;
        temp_s0->l.col[1] = temp_s0->l.colc[1] = D_800FA620_FB220->unk02[var_s1].g;
        temp_s0->l.col[2] = temp_s0->l.colc[2] = D_800FA620_FB220->unk02[var_s1].b;
        if (D_800FA620_FB220->unk02[var_s1].stat & 1) {
            f32 sp10[4][4];
            f32 temp_f24 = D_800FA620_FB220->unk02[var_s1].unk04;
            f32 temp_f26 = D_800FA620_FB220->unk02[var_s1].unk05;
            f32 temp_f28 = D_800FA620_FB220->unk02[var_s1].unk06;
            f32 temp_f22;
            f32 temp_f20;
            f32 temp_f24_2;
            f32 temp_f0;

            guMtxL2F(sp10, &D_800FC88C_FD48C->lookAtMtx);
            temp_f22 = temp_f24 * sp10[0][0] + temp_f26 * sp10[1][0] + temp_f28 * sp10[2][0];
            temp_f20 = temp_f24 * sp10[0][1] + temp_f26 * sp10[1][1] + temp_f28 * sp10[2][1];
            temp_f24_2 = temp_f24 * sp10[0][2] + temp_f26 * sp10[1][2] + temp_f28 * sp10[2][2];
            temp_f0 = temp_f22 * temp_f22 + temp_f20 * temp_f20 + temp_f24_2 * temp_f24_2;
            temp_f0 = func_800B1830_B2430(temp_f0);
            temp_s0->l.dir[0] = (temp_f22 / temp_f0) * 120.0f;
            temp_s0->l.dir[1] = (temp_f20 / temp_f0) * 120.0f;
            temp_s0->l.dir[2] = (temp_f24_2 / temp_f0) * 120.0f;
        } else {
            temp_s0->l.dir[0] = D_800FA620_FB220->unk02[var_s1].unk04;
            temp_s0->l.dir[1] = D_800FA620_FB220->unk02[var_s1].unk05;
            temp_s0->l.dir[2] = D_800FA620_FB220->unk02[var_s1].unk06;
        }
    }
}

void func_80026C40_27840(void) {
    s16 var_a3;

    D_800F8424_F9024 = D_800FA620_FB220->unk40[D_800FDBE0_FE7E0][0];
    for (var_a3 = 0; var_a3 < D_800FA620_FB220->unk00 + 1; var_a3++) {
        D_800F8424_F9024[var_a3].l.col[0] = D_800F8424_F9024[var_a3].l.colc[0] = D_800FA620_FB220->unk02[var_a3].r;
        D_800F8424_F9024[var_a3].l.col[1] = D_800F8424_F9024[var_a3].l.colc[1] = D_800FA620_FB220->unk02[var_a3].g;
        D_800F8424_F9024[var_a3].l.col[2] = D_800F8424_F9024[var_a3].l.colc[2] = D_800FA620_FB220->unk02[var_a3].b;
    }
}

void func_80026D28_27928(s16 arg0) {
    if (arg0 >= 8) {
        arg0 = 7;
    }
    D_800FA620_FB220->unk00 = arg0;
}

void func_80026D50_27950(s16 arg0, u8 arg1, u8 arg2) {
    if (D_800FA620_FB220->unk00 >= arg0) {
        D_800FA620_FB220->unk02[arg0].stat &= ~arg1;
        D_800FA620_FB220->unk02[arg0].stat |= arg2;
    }
}

void func_80026DAC_279AC(s16 arg0, u8 arg1, u8 arg2, u8 arg3) {
    if (D_800FA620_FB220->unk00 >= arg0) {
        D_800FA620_FB220->unk02[arg0].r = arg1;
        D_800FA620_FB220->unk02[arg0].g = arg2;
        D_800FA620_FB220->unk02[arg0].b = arg3;
    }
}

void func_80026E00_27A00(s16 arg0, f32 arg1, f32 arg2, f32 arg3) {
    if (D_800FA620_FB220->unk00 >= arg0) {
        f32 temp_f0 = arg1 * arg1 + arg2 * arg2 + arg3 * arg3;

        temp_f0 = func_800B1830_B2430(temp_f0);
        D_800FA620_FB220->unk02[arg0].unk04 = (arg1 / temp_f0) * 120.0f;
        D_800FA620_FB220->unk02[arg0].unk05 = (arg2 / temp_f0) * 120.0f;
        D_800FA620_FB220->unk02[arg0].unk06 = (arg3 / temp_f0) * 120.0f;
    }
}

void func_80026F00_27B00(HmfData_UnkD0 *arg0) {
    Light *temp_s0 = &arg0->unk08[D_800FDBE0_FE7E0];

    temp_s0->l.col[0] = temp_s0->l.colc[0] = arg0->unk00;
    temp_s0->l.col[1] = temp_s0->l.colc[1] = arg0->unk01;
    temp_s0->l.col[2] = temp_s0->l.colc[2] = arg0->unk02;
    if (arg0->unk03 & 1) {
        f32 sp10[4][4];
        f32 temp_f22 = arg0->unk04;
        f32 temp_f26 = arg0->unk05;
        f32 temp_f28 = arg0->unk06;
        f32 temp_f24;
        f32 temp_f20;
        f32 temp_f22_2;
        f32 temp_f0;

        guMtxL2F(sp10, &D_800FC88C_FD48C->lookAtMtx);
        temp_f24 = temp_f22 * sp10[0][0] + temp_f26 * sp10[1][0] + temp_f28 * sp10[2][0];
        temp_f20 = temp_f22 * sp10[0][1] + temp_f26 * sp10[1][1] + temp_f28 * sp10[2][1];
        temp_f22_2 = temp_f22 * sp10[0][2] + temp_f26 * sp10[1][2] + temp_f28 * sp10[2][2];
        temp_f0 = temp_f24 * temp_f24 + temp_f20 * temp_f20 + temp_f22_2 * temp_f22_2;
        temp_f0 = func_800B1830_B2430(temp_f0);
        temp_s0->l.dir[0] = (temp_f24 / temp_f0) * 120.0f;
        temp_s0->l.dir[1] = (temp_f20 / temp_f0) * 120.0f;
        temp_s0->l.dir[2] = (temp_f22_2 / temp_f0) * 120.0f;
    } else {
        temp_s0->l.dir[0] = arg0->unk04;
        temp_s0->l.dir[1] = arg0->unk05;
        temp_s0->l.dir[2] = arg0->unk06;
    }
}

void func_800270C0_27CC0(void* (*arg0)(s32), void (*arg1)(void*)) {
    unkMallocBlockStruct* temp_v0;

    D_8010164C_10224C = arg0;
    D_800FD440_FE040 = arg1;

    if (D_800C9E50_CAA50 != 0) {
        func_8002742C_2802C();
    }

    temp_v0 = (unkMallocBlockStruct*) D_8010164C_10224C(sizeof(unkMallocBlockStruct));
    D_800FC830_FD430 = temp_v0;
    D_801027FC_1033FC = temp_v0;

    temp_v0->unk_00 = NULL;
    temp_v0->unk_06 = -1;
    temp_v0->unk_10 = temp_v0;
    temp_v0->unk_14 = temp_v0;

    D_800F64C0_F70C0 = 0;
}

void* HuMemAlloc(s32 size) {
    return func_80027154_27D54(size, 0);
}

void* func_80027154_27D54(s32 size, s16 arg1) {
    void* temp_v0;
    unkMallocBlockStruct* temp_v1;

    size = (size + 7) & ~7;

    temp_v0 = D_8010164C_10224C(size + sizeof(unkMallocBlockStruct));
    temp_v1 = (unkMallocBlockStruct*) (temp_v0 + size);

    temp_v1->unk_10 = D_801027FC_1033FC;
    temp_v1->unk_14 = D_801027FC_1033FC->unk_14;

    D_801027FC_1033FC->unk_14->unk_10 = temp_v1;
    D_801027FC_1033FC->unk_14 = temp_v1;

    temp_v1->unk_06 = arg1;
    temp_v1->unk_08 = size;
    temp_v1->unk_00 = temp_v0;
    temp_v1->unk_0C = D_800FDC98_FE898;

    return temp_v1->unk_00;
}

void HuMemFree(void* arg0) {
    unkMallocBlockStruct* var_a0 = D_801027FC_1033FC->unk_14;

    while (arg0 != var_a0->unk_00) {
        var_a0 = var_a0->unk_14;

        if (var_a0 == D_800FC830_FD430) {
            return;
        }
    }

    func_80027230_27E30(var_a0);
}

void func_80027230_27E30(unkMallocBlockStruct* arg0) {
    D_800FD3E0_FDFE0 = arg0;
    arg0->unk_14->unk_10 = arg0->unk_10;
    arg0->unk_10->unk_14 = arg0->unk_14;

    D_800FD440_FE040(arg0->unk_00);
}

void func_80027274_27E74(s16 arg0) {
    unkMallocBlockStruct* var_a0 = D_801027FC_1033FC->unk_14;
    unkMallocBlockStruct* temp_s0;

    while (var_a0 != D_800FC830_FD430) {
        if (var_a0->unk_06 == arg0) {
            if (var_a0->unk_06 != -1) {
                temp_s0 = var_a0->unk_10;
                func_80027230_27E30(var_a0);
                var_a0 = temp_s0;
            } else {
                var_a0->unk_04--;

                if (!(var_a0->unk_04 & 0xFF)) {
                    temp_s0 = var_a0->unk_10;
                    func_80027230_27E30(var_a0);
                    var_a0 = temp_s0;

                    D_800F64C0_F70C0--;
                    if (D_800F64C0_F70C0 <= 0) {
                        break;
                    }
                }
            }
        }

        var_a0 = var_a0->unk_14;
    }
}

void func_80027340_27F40(void* arg0) {
    unkMallocBlockStruct* var_v1 = D_801027FC_1033FC->unk_14;

    while (arg0 != var_v1->unk_00) {
        var_v1 = var_v1->unk_14;

        if (var_v1 == D_800FC830_FD430) {
            return;
        }
    }

    var_v1->unk_06 = -1;
    var_v1->unk_04 = D_800FDBCA_FE7CA + 1;
    D_800F64C0_F70C0++;
}

void func_800273A8_27FA8(s16 arg0) {
    unkMallocBlockStruct* var_v1 = D_801027FC_1033FC->unk_14;

    while (var_v1 != D_800FC830_FD430) {
        if (var_v1->unk_06 == arg0) {
            var_v1->unk_06 = -1;
            var_v1->unk_04 = D_800FDBCA_FE7CA + 1;
            D_800F64C0_F70C0++;
        }

        var_v1 = var_v1->unk_14;
    }
}

void func_8002741C_2801C(void) {
    D_800C9E50_CAA50 = 1;
}

void func_8002742C_2802C(void) {
    unkMallocBlockStruct* var_a0 = D_801027FC_1033FC->unk_14;

    while (var_a0 != D_800FC830_FD430) {
        unkMallocBlockStruct* temp_s0 = var_a0->unk_10;
        func_80027230_27E30(var_a0);
        var_a0 = temp_s0->unk_14;
    }

    D_800FD440_FE040(D_800FC830_FD430);

    D_800F64C0_F70C0 = 0;
    D_800C9E50_CAA50 = 0;
}

void func_800274A4_280A4(void) {
    if (D_800C9E50_CAA50 != 0) {
        func_8002742C_2802C();
    } else if (D_800F64C0_F70C0 != 0) {
        func_80027274_27E74(-1);
    }
}

s32 func_800274F0_280F0(s16 arg0) {
    unkMallocBlockStruct* var_v1 = D_801027FC_1033FC->unk_14;
    s32 var_a1 = 0;

    while (var_v1 != D_800FC830_FD430) {
        if (var_v1->unk_06 == arg0) {
            var_a1 += var_v1->unk_08;
        }

        var_v1 = var_v1->unk_14;
    }

    return var_a1;
}

s32 func_80027544_28144(void) {
    unkMallocBlockStruct* var_v1 = D_801027FC_1033FC->unk_14;
    s32 var_a0 = 0;

    while (var_v1 != D_800FC830_FD430) {
        var_a0 += var_v1->unk_08;
        var_v1 = var_v1->unk_14;
    }

    return var_a0;
}

void func_80027580_28180(void* arg0, s16 arg1) {
    unkMallocBlockStruct* var_v1 = D_801027FC_1033FC->unk_14;

    while (arg0 != var_v1->unk_00) {
        var_v1 = var_v1->unk_14;

        if (var_v1 == D_800FC830_FD430) {
            return;
        }
    }

    var_v1->unk_06 = arg1;
}

extern void* D_800F64D0_F70D0[];
extern void* D_800FDEB0_FEAB0[];
extern s16 D_800C9E52_CAA52;
void osSyncPrintf(const char* fmt, ...);
/* "%x\n" and "Model Entry Over!\n": 274D0's rodata (D2DF8) is not carved while
   func_80027FA4_28BA4 is asm, so C names the strings, as MP3's hmfman.c/mallocblock.c do */
extern char D_800D21F8_D2DF8[];
extern char D_800D21FC_D2DFC[];

/* MP3 HuMemDebugCheck (src/mallocblock.c) */
s32 func_800275C4_281C4(void) {
    unkMallocBlockStruct* block;
    s16 i;
    s16 count;
    s16 var_v1;
    s32 size;

    block = D_801027FC_1033FC->unk_14;
    size = 0;
    count = 0;
    while (block != D_800FC830_FD430) {
        D_800F64D0_F70D0[count] = block->unk_00;
        size += block->unk_08;
        block = block->unk_14;
        count++;
    }

    if ((D_800C9E52_CAA52 != 0) && (D_800C9E52_CAA52 != count)) {
        for (i = 0; i < count; i++) {
            for (var_v1 = 0; var_v1 < D_800C9E52_CAA52; var_v1++) {
                if (D_800FDEB0_FEAB0[var_v1] == D_800F64D0_F70D0[i])
                    break;
            }
            if (var_v1 == D_800C9E52_CAA52) {
                osSyncPrintf(D_800D21F8_D2DF8, D_800F64D0_F70D0[i]);
            }
        }
    }

    D_800C9E52_CAA52 = count;
    for (i = 0; i < count; i++) {
        D_800FDEB0_FEAB0[i] = D_800F64D0_F70D0[i];
    }
    return size;
}

void func_800277B0_283B0(void* (*arg0)(s32), void (*arg1)(void*), u16 arg2, u16 arg3, u16 arg4, u8 arg5) {
    s16 i;

    func_8002F960_30560(arg0, arg1, arg2, arg3, arg4, arg5);
    func_80038DD0_399D0();
    D_800FC834_FD434 = HuMemAlloc(HU3D_MODEL_MAX * sizeof(*D_800FC834_FD434));
    for (i = 0; i < HU3D_MODEL_MAX; i++) {
        D_800FC834_FD434[i].hmf = NULL;
    }
    func_8002FB6C_3076C();
    D_800FDC98_FE898 = 0;
    D_800FD848_FE448 = 0;
    D_800FDCD0_FE8D0 = 1;
    D_800FDC9C_FE89C = 0;
    D_800F94A4_FA0A4 = 1;
    D_800F8F80_F9B80[0] = D_800F8F80_F9B80[1] = NULL;
}

s16 func_80038F0C_39B0C(u8*);
s16 func_80038E38_39A38(u8*, HmfData*);
void* func_8001EB18_1F718(void*);
u8 func_8003BA2C_3C62C(u8*, void*);
void func_8001D190_1DD90(HmfData*, void*, s32); /* Hmfload */
void func_8001D9D4_1E5D4(HmfData*);
s16 func_8002D5B4_2E1B4(s16);
void func_8002FD38_30938(HmfData*);
extern s16 D_8010106C_101C6C;
extern s16 D_800FA1AA_FADAA;
extern s32 D_800F64C4_F70C4;
void func_800B37C0_B43C0(f32*); /* guMtxIdentF */

/* MP3 Hu3DModelCreate (src/hmfman.c) */
s16 Hu3DModelCreate(u8 *data, u32 arg1) {
    HmfModel *modelP;
    HmfData *hmf;
    void *var_a1;
    s16 modelId;
    s16 var_a0;

    for (modelId = 0; modelId < HU3D_MODEL_MAX; modelId++) {
        if (D_800FC834_FD434[modelId].hmf == NULL) {
            break;
        }
    }
    if (modelId == HU3D_MODEL_MAX) {
        osSyncPrintf(D_800D21FC_D2DFC);
        return -1;
    }
    D_8010106C_101C6C = 10000 + modelId * 2;
    D_800FA1AA_FADAA = 10001 + modelId * 2;
    modelP = &D_800FC834_FD434[modelId];
    modelP->unk08 = 0xFF;
    hmf = modelP->hmf = HuMemAlloc(sizeof(HmfData));
    hmf->unk0E = D_8010106C_101C6C;
    if (data[0] == 'M' && data[1] == 'T') {
        hmf->unk14 = 0;
        hmf->unk88 = 0;
        hmf->unk38 = 0;
        hmf->unkC8 = 0;
        if (data[2] == 'N' && data[3] == 'X') {
            modelP->unk02 = func_80038F0C_39B0C(data);
            arg1 &= ~(0x10 | 0x1);
        } else {
            var_a1 = data + 8;
            if (data[8] == 'M') {
                if (data[9] == 'T' && data[10] == 'N' && data[11] == 'X') {
                    modelP->unk02 = func_80038F0C_39B0C(var_a1);
                    arg1 &= ~0x11;
                    var_a1 = func_8001EB18_1F718(data + 12);
                } else {
                    modelP->unk02 = 0xFF;
                }
            } else {
                modelP->unk02 = 0xFF;
            }
            modelP->unk08 = func_8003BA2C_3C62C(data, var_a1);
        }
    } else {
        func_8001D190_1DD90(hmf, data, arg1);
        if (hmf->unk38 != 0) {
            func_80027580_28180(hmf->unk54, D_800FA1AA_FADAA);
            modelP->unk10 = func_8002D5B4_2E1B4(modelId);
        } else {
            modelP->unk10 = -1;
        }
        hmf->unk00 = (arg1 >> 10) & 7;
        modelP->unk18 = arg1;
        modelP->unk02 = func_80038E38_39A38(data, hmf);
        if (modelP->unk02 != 0xFF) {
            if (hmf->unk14 == 0) {
                func_8001D9D4_1E5D4(hmf);
            } else {
                goto skip;
            }
        }
    }
    if (hmf->unk14 == 0) {
        arg1 |= 4;
    }
skip:
    modelP->unk18 = arg1;
    if (arg1 & 8) {
        D_800FD440_FE040(data);
    }
    if (arg1 & 1) {
        D_800F64C4_F70C4 = modelP->unk18;
        func_8002FD38_30938(hmf);
    }
    hmf->unk0B = 1;
    if (arg1 & 0x10) {
        for (var_a0 = 0; var_a0 < hmf->unk10; var_a0++) {
            if (hmf->unk64[var_a0].unk50 & 0x06000000) {
                break;
            }
        }
        if (var_a0 == hmf->unk10) {
            func_80027274_27E74(D_8010106C_101C6C);
        }
    }
    modelP->unk40 =
        modelP->unk03 =
            modelP->unk48 =
                modelP->unk4C =
                    modelP->unk05 =
                        modelP->unk54 =
                            modelP->unk58 =
                                modelP->unk07 =
                                    modelP->unk60 = 0;
    modelP->unk5C = 1.0f;
    modelP->unk50 = 1.0f;
    modelP->unk44 = 1.0f;
    modelP->unk06 = -1;
    modelP->unk04 = -1;
    modelP->unk09 = -1;
    modelP->pos.x = modelP->pos.y = modelP->pos.z = 0.0f;
    modelP->rot.x = modelP->rot.y = modelP->rot.z = 0.0f;
    modelP->scale.x = modelP->scale.y = modelP->scale.z = 1.0f;
    modelP->unk01 = -1;
    modelP->unk00 = 0;
    modelP->unkB4 = 0;
    modelP->unkB8 = 0;
    func_800B37C0_B43C0(modelP->mtx);
    return modelId;
}

/* MP3 Hu3DModelLink (src/hmfman.c) */
s16 func_80027D3C_2893C(s16 linkMdlId) {
    HmfModel *modelP;
    s16 modelId;

    for (modelId = 0; modelId < HU3D_MODEL_MAX; modelId++) {
        if (D_800FC834_FD434[modelId].hmf == NULL) {
            break;
        }
    }
    if (modelId == HU3D_MODEL_MAX) {
        osSyncPrintf(D_800D21FC_D2DFC);
        return -1;
    }
    modelP = &D_800FC834_FD434[modelId];
    modelP->hmf = D_800FC834_FD434[linkMdlId].hmf;
    modelP->unk18 = D_800FC834_FD434[linkMdlId].unk18;
    modelP->unk00 = D_800FC834_FD434[linkMdlId].unk00;
    modelP->unk10 = D_800FC834_FD434[linkMdlId].unk10;
    modelP->unk02 = D_800FC834_FD434[linkMdlId].unk02;
    modelP->hmf->unk0B++;
    modelP->unk40 =
        modelP->unk03 =
            modelP->unk48 =
                modelP->unk4C =
                    modelP->unk05 =
                        modelP->unk54 =
                            modelP->unk58 =
                                modelP->unk07 =
                                    modelP->unk60 = 0;
    modelP->unk5C = 1.0f;
    modelP->unk50 = 1.0f;
    modelP->unk44 = 1.0f;
    modelP->unk06 = -1;
    modelP->unk04 = -1;
    modelP->unk09 = -1;
    modelP->unk08 = -1;
    modelP->unkB4 = 0;
    modelP->unkB8 = 0;
    modelP->pos.x = modelP->pos.y = modelP->pos.z = 0.0f;
    modelP->rot.x = modelP->rot.y = modelP->rot.z = 0.0f;
    modelP->scale.x = modelP->scale.y = modelP->scale.z = 1.0f;
    modelP->unk01 = -1;
    func_800B37C0_B43C0(modelP->mtx);
    return modelId;
}

/* MP1 func_80024198 (src/24740.c): a model drawn from a display list */
s16 func_80027FA4_28BA4(u32 arg0, void* arg1, u8 arg2) {
    HmfData* hmf;
    HmfModel* modelP;
    s16 i;

    for (i = 0; i < HU3D_MODEL_MAX; i++) {
        if (D_800FC834_FD434[i].hmf == NULL) {
            break;
        }
    }
    if (i == HU3D_MODEL_MAX) {
        osSyncPrintf(D_800D21FC_D2DFC);
        return -1;
    }
    D_8010106C_101C6C = i * 2 + 10000;
    D_800FA1AA_FADAA = i * 2 + 10001;
    modelP = &D_800FC834_FD434[i];
    hmf = modelP->hmf = func_80027154_27D54(sizeof(HmfData), D_800FA1AA_FADAA);
    hmf->unk0E = D_8010106C_101C6C;
    hmf->unk3C = arg1;
    hmf->unk0B = 1;
    hmf->unk00 = (arg0 >> 10) & 7;
    modelP->unk70 = NULL;
    modelP->hmf->unk9C = NULL;
    modelP->unk08 = 0xFF;
    modelP->unk18 = arg0 | 1;
    modelP->unk40 =
        modelP->unk03 =
            modelP->unk48 =
                modelP->unk4C =
                    modelP->unk05 =
                        modelP->unk54 = 0;
    modelP->unk44 = modelP->unk50 = 1.0f;
    modelP->unk04 = 0xFF;
    modelP->unk02 = 0xFF;
    modelP->unk09 = 0xFF;
    modelP->unkB4 = NULL;
    modelP->unkB8 = 0;
    modelP->pos.x = modelP->pos.y = modelP->pos.z = 0.0f;
    modelP->rot.x = modelP->rot.y = modelP->rot.z = 0.0f;
    modelP->scale.x = modelP->scale.y = modelP->scale.z = 1.0f;

    switch (arg2 & 6) {
        case 4:
            func_800B37C0_B43C0(modelP->mtx);
            hmf->unk3C = func_80027154_27D54(sizeof(void*), D_800FA1AA_FADAA);
            hmf->unk3C->unk00[0] = arg1;
            hmf->unk64 = func_80027154_27D54(sizeof(HmfPart), D_800FA1AA_FADAA);
            hmf->unk10 = 1;
            hmf->unk14 = 1;
            hmf->unk38 = NULL;
            hmf->unkC8 = 0;
            hmf->unk64->unk50 = 0;
            hmf->unk64->unk02 = -1;
            hmf->unk64->unk5C = -1;
            hmf->unk64->unk60 = 0;
            hmf->unkB8 = NULL;
            hmf->unk0A = 0;
            hmf->unkD4 = func_80025884_26484;
            hmf->unkD8 = func_800B2060_B2C60;
            hmf->unk64->unk42 = hmf->unk64->unk44 = hmf->unk64->unk46 = -0x8000;
            hmf->unk64->unk48 = hmf->unk64->unk4A = hmf->unk64->unk4C = -0x8000;
        case 0:
        case 2:
            modelP->unk01 = 0xFF;
            break;
        case 6:
            modelP->unk01 = 0;
            break;
    }
    modelP->unk00 = arg2 | 1;
    return i;
}

s16 func_800282D4_28ED4(s16 arg0, s8 arg1) {
    s16 temp_v0 = func_80027D3C_2893C(arg0);

    if (temp_v0 < 0) {
        return -1;
    }
    D_800FC834_FD434[temp_v0].unk00 = arg1;
    return temp_v0;
}

void func_80028334_28F34(s16 arg0, u8 arg1) {
    HmfModel* modelP = &D_800FC834_FD434[arg0];

    modelP->unk00 &= ~6;
    modelP->unk00 |= 1;
    modelP->unk00 |= arg1;
    if (arg1 == 6) {
        modelP->unk01 = 0;
    } else {
        modelP->unk01 = 0xFF;
    }
}

s16 func_8002838C_28F8C(s32 arg0, void (*arg1)(Gfx **, s32, s32), u8 arg2) {
    s16 idx = func_80027FA4_28BA4(arg0, NULL, arg2);
    HmfModel *var_v1 = &D_800FC834_FD434[idx];

    var_v1->unk70 = arg1;
    return idx;
}

void func_8002F1D0_2FDD0(s16);
void func_8003BAD8_3C6D8(s16);
void func_8003CDAC_3D9AC(HmfData*);
void func_8003E888_3F488(s16);
void func_80039018_39C18(s16);

/* MP1 func_8002456C (src/24740.c): release a model */
void func_800283DC_28FDC(s16 arg0) {
    HmfData* hmf;
    s32 j;
    s16 i;

    if (D_800FC834_FD434[arg0].hmf == NULL) {
        return;
    }
    if (D_800FC834_FD434[arg0].unk09 != 0xFF && D_800FC834_FD434[arg0].unk14 != 0.0f) {
        hmf = D_800FC834_FD434[arg0].unk6C;
    } else {
        hmf = D_800FC834_FD434[arg0].hmf;
    }
    D_800FC834_FD434[arg0].hmf = NULL;
    if (D_800FC834_FD434[arg0].unk00 & 1) {
        if (--hmf->unk0B == 0) {
            func_800273A8_27FA8(hmf->unk0E);
            func_800273A8_27FA8(hmf->unk0E + 1);
        }
    } else if ((u8)D_800FC834_FD434[arg0].unk00 == 0) {
        if (--hmf->unk0B == 0) {
            func_800273A8_27FA8(hmf->unk0E);
            func_800273A8_27FA8(hmf->unk0E + 1);
            func_8003CDAC_3D9AC(hmf);
            if (hmf->unk38 != NULL) {
                func_8002F1D0_2FDD0(D_800FC834_FD434[arg0].unk10);
            }
            j = D_800FC834_FD434[arg0].unk08;
            if (j != 0xFF) {
                func_8003BAD8_3C6D8(j);
            }
            if (hmf->unkC8 != 0) {
                /* unkC8 holds a u8* (a pointer in an s32 field) */
                for (i = 0; i < hmf->unk28; i++) {
                    func_8003E888_3F488(((u8*)hmf->unkC8)[i]);
                }
            }
            func_80027340_27F40(hmf);
            if (D_800FC834_FD434[arg0].unk02 != 0xFF) {
                func_80039018_39C18(D_800FC834_FD434[arg0].unk02);
            }
        }
    }
}

void func_8003EA44_3F644(void);
void func_8003E984_3F584(void);
void func_8003BAF0_3C6F0(void);
void func_8002F1A4_2FDA4(void);
void func_80039074_39C74(void);
void func_8002C5D8_2D1D8(void);

/* MP1 func_80024754 (src/24740.c) */
void func_8002864C_2924C(void) {
    s16 i;

    for (i = 0; i < HU3D_MODEL_MAX; i++) {
        if (D_800FC834_FD434[i].hmf != NULL) {
            func_800283DC_28FDC(i);
        }
    }
    func_8003EA44_3F644();
    func_8003E984_3F584();
    func_8003BAF0_3C6F0();
    func_8002F1A4_2FDA4();
    func_80039074_39C74();
    func_8002C5D8_2D1D8();
    D_800F8F80_F9B80[0] = D_800F8F80_F9B80[1] = NULL;
}

INCLUDE_ASM("asm/nonmatchings/274D0", func_800286FC_292FC);

extern u16 D_800F8710_F9310[];
extern u16 D_800FCA00_FD600[][HU3D_MODEL_MAX];
extern s16 D_800F9564_FA164;
extern u8 D_800FA5D8_FB1D8;
extern Gfx* D_800FDBCC_FE7CC; /* gMainGfxPos */
u8 func_8001D054_1DC54(void *arg0, u16 arg1, s32 arg2, void *arg3, s32 arg4);

Gfx *func_80029368_29F68(Gfx *arg0, s16 arg1, u16 arg2) {
    s16 i;

    for (i = 0; i < D_800F8710_F9310[arg1]; i++) {
        HmfModel *temp_s0 = &D_800FC834_FD434[D_800FCA00_FD600[arg1][i]];

        if (!(temp_s0->unk01 & arg2) && arg2 != 0) {
            continue;
        }
        D_800F9564_FA164 = D_800FCA00_FD600[arg1][i];
        if (temp_s0->hmf->unk00 != D_800FA5D8_FB1D8) {
            gDPFullSync(D_800FDBCC_FE7CC++);
            gSPEndDisplayList(D_800FDBCC_FE7CC++);
            func_8001D054_1DC54(arg0, D_800FA5D8_FB1D8, 0, NULL, 0);
            D_800FA5D8_FB1D8 = temp_s0->hmf->unk00;
            arg0 = D_800FDBCC_FE7CC;
        }
        if (temp_s0->unk70 != NULL) {
            temp_s0->unk70(&D_800FDBCC_FE7CC, (s32)D_800FC88C_FD48C, (s32)D_800FD2A8_FDEA8);
        } else if (temp_s0->hmf->unk3C != NULL) {
            gSPDisplayList(D_800FDBCC_FE7CC++, temp_s0->hmf->unk3C);
        }
    }
    return arg0;
}

void func_80029558_2A158(void) {
    s16 i;

    func_8002741C_2801C();
    for (i = 0; i < HU3D_MODEL_MAX; i++) {
        D_800FC834_FD434[i].hmf = NULL;
    }
    D_800C9B80_CA780 = NULL;
    D_800F64B2_F70B2 = 0;
    D_800FDBE0_FE7E0 = 0;
    D_800FDCD0_FE8D0 = 0;
}

extern Gfx D_800C9F60_CAB60[];
extern Gfx D_800C9FB8_CABB8[];
extern Gfx D_800C9FE8_CABE8[];

void func_800295D4_2A1D4(void* arg0, void* arg1) {
    gSPSegment(D_800FDBCC_FE7CC++, 0, 0);
    gSPDisplayList(D_800FDBCC_FE7CC++, D_800C9F60_CAB60);
    gDPSetDepthImage(D_800FDBCC_FE7CC++, arg1);
    gDPSetColorImage(D_800FDBCC_FE7CC++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, arg1);
    gSPDisplayList(D_800FDBCC_FE7CC++, D_800C9FB8_CABB8);
    gDPSetColorImage(D_800FDBCC_FE7CC++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, arg0);
    if (D_800F94A4_FA0A4 != 0) {
        gDPSetFillColor(D_800FDBCC_FE7CC++, GPACK_RGBA5551(D_800C9B70_CA770, D_800C9B71_CA771, D_800C9B72_CA772, 1) << 16 |
                                      GPACK_RGBA5551(D_800C9B70_CA770, D_800C9B71_CA771, D_800C9B72_CA772, 1));
        gSPDisplayList(D_800FDBCC_FE7CC++, D_800C9FE8_CABE8);
    }
}

void func_80029708_2A308(s32 arg0) {
    D_800F94A4_FA0A4 = arg0;
}

void func_80029714_2A314(s16 idx, f32 x, f32 y, f32 z) {
    HmfModel* model;

    if (D_800FC834_FD434[idx].hmf != NULL) {
        model = &D_800FC834_FD434[idx];
        model->pos.x = x;
        model->pos.y = y;
        model->pos.z = z;
    }
}

void func_80029760_2A360(s16 idx, Vec *arg1) {
    arg1->x = D_800FC834_FD434[idx].pos.x;
    arg1->y = D_800FC834_FD434[idx].pos.y;
    arg1->z = D_800FC834_FD434[idx].pos.z;
}

void func_8002979C_2A39C(s16 idx, f32 x, f32 y, f32 z) {
    HmfModel* model;

    if (D_800FC834_FD434[idx].hmf != NULL) {
        model = &D_800FC834_FD434[idx];
        model->rot.x = x;
        model->rot.y = y;
        model->rot.z = z;
    }
}

void func_800297E8_2A3E8(s16 idx, f32 x, f32 y, f32 z) {
    HmfModel* model;

    if (D_800FC834_FD434[idx].hmf != NULL) {
        model = &D_800FC834_FD434[idx];
        model->scale.x = x;
        model->scale.y = y;
        model->scale.z = z;
    }
}

void func_80029834_2A434(s16 arg0, s32 arg1) {
    HmfModel* temp_v1;
    s16 i;

    for (i = 0; i < HU3D_MODEL_MAX; i++) {
        temp_v1 = &D_800FC834_FD434[i];
        if (temp_v1->hmf != NULL) {
            temp_v1->unk18 &= ~arg0;
            temp_v1->unk18 |= arg1;
        }
    }
}

void func_800298A4_2A4A4(s16 arg0, s32 arg1, s32 arg2) {
    HmfModel* temp_a0 = &D_800FC834_FD434[arg0];

    if (temp_a0->hmf != NULL) {
        temp_a0->unk18 &= ~arg1;
        temp_a0->unk18 |= arg2;
    }
}

void HmfModelObjAttrSet(s16 idx, s32 arg1, s32 arg2) {
    HmfData *temp_a3 = D_800FC834_FD434[idx].hmf;
    s16 var_t0;

    for (var_t0 = 0; var_t0 < temp_a3->unk10; var_t0++) {
        temp_a3->unk64[var_t0].unk50 &= ~arg1;
        temp_a3->unk64[var_t0].unk50 |= arg2;
    }
}

void func_80029988_2A588(s16 idx, char* arg1, s32 arg2, s32 arg3) {
    HmfData *temp_s0 = D_800FC834_FD434[idx].hmf;
    s16 temp_v0 = func_80038398_38F98(temp_s0, arg1);

    if (temp_v0 >= 0) {
        temp_s0->unk64[temp_v0].unk50 &= ~arg2;
        temp_s0->unk64[temp_v0].unk50 |= arg3;
    }
}

void func_80029A34_2A634(s16 arg0, char* arg1, s16 arg2) {
    func_8003847C_3907C(D_800FC834_FD434[arg0].hmf, arg1, D_800FC834_FD434[arg2].hmf);
}

s32 func_800308D8_314D8(HmfData*);
void func_8002A00C_2AC0C(s16);

/* MP1 func_80025AD4 (src/24740.c) */
void func_80029A8C_2A68C(s16 arg0) {
    func_800298A4_2A4A4(arg0, 1, 1);
    D_800F64C4_F70C4 = D_800FC834_FD434[arg0].unk18;
    if (func_800308D8_314D8(D_800FC834_FD434[arg0].hmf)) {
        func_8002A00C_2AC0C(arg0);
    }
}

void func_80029AFC_2A6FC(s16 arg0) {
    HmfData* model = D_800FC834_FD434[arg0].hmf;

    if (model->unk0A != 0) {
        func_800273A8_27FA8(model->unk0E);
    } else {
        func_80027274_27E74(D_800FC834_FD434[arg0].hmf->unk0E);
    }
}

void func_80029B80_2A780(s16 arg0, s16 arg1) {
    HmfModel* modelP = &D_800FC834_FD434[arg0];

    modelP->unk02 = D_800FC834_FD434[arg1].unk02;
    modelP->unk48 = modelP->unk40 = modelP->unk03 = 0;
    modelP->unk44 = 1.0f;
    modelP->unk04 = 0xFF;
}

void func_80029BF0_2A7F0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    HmfModel *temp_a0;

    temp_a0 = &D_800FC834_FD434[arg0];
    if (temp_a0->unk04 != 0xFF) {
        temp_a0->unk02 = temp_a0->unk04;
        temp_a0->unk40 = temp_a0->unk4C;
        temp_a0->unk03 = temp_a0->unk05;
        temp_a0->unk48 = temp_a0->unk54;
    }
    temp_a0->unk04 = (u8)arg1;
    temp_a0->unk4C = arg2;
    temp_a0->unk0E = (u16)0;
    temp_a0->unk0C = arg3;
    temp_a0->unk05 = (u8)arg4;
    temp_a0->unk54 = 0.0f;
}

/* MP1 func_80025CA8 (src/24740.c) */
void func_80029C74_2A874(s16 arg0, f32 arg1) {
    HmfModel* modelP = &D_800FC834_FD434[arg0];
    f32 len = D_800F92B4_F9EB4[modelP->unk02].unk02;

    if (len < arg1) {
        modelP->unk40 = len;
    } else {
        modelP->unk40 = arg1;
    }
}

f32 func_80029CE4_2A8E4(s16 arg0) {
    return D_800FC834_FD434[arg0].unk40;
}

/* MP1 func_80025D40 (src/24740.c) */
f32 func_80029D0C_2A90C(s16 arg0) {
    return D_800F92B4_F9EB4[D_800FC834_FD434[arg0].unk02].unk02;
}

/* MP1 func_80025D90 (src/24740.c; its decomp-permuter shape) */
f32 func_80029D5C_2A95C(s16 arg0) {
    f32 new_var;
    f32 x = D_800FC834_FD434[arg0].unk58;
    f32 r;

    if (!(x < 0.0f)) {
        new_var = x;
        r = new_var;
    } else {
        r = 0.0f;
    }
    return r;
}

/* MP1 func_80025DD8 (src/24740.c) */
f32 func_80029DA4_2A9A4(s16 arg0) {
    if (D_800FC834_FD434[arg0].unk58 < 0.0f) {
        return 0.0f;
    }
    return D_800F92B4_F9EB4[D_800FC834_FD434[arg0].unk06].unk02;
}

u8 func_80029E14_2AA14(s16 arg0) {
    return D_800FC834_FD434[arg0].unk02;
}

f32 func_80029E3C_2AA3C(s16 idx) {
    if (D_800FC834_FD434[idx].unk04 == 0xFF) {
        return -1.0f;
    }
    return D_800FC834_FD434[idx].unk4C;
}

/* MP1 func_80025EB4 (src/24740.c) */
void func_80029E80_2AA80(s16 arg0, s32 arg1, s32 arg2) {
    HmfModel* modelP = &D_800FC834_FD434[arg0];

    modelP->unk03 = (modelP->unk03 & ~arg1) | arg2;
    if (modelP->unk04 != 0xFF) {
        modelP->unk05 = (modelP->unk05 & ~arg1) | arg2;
    }
}

void func_80029EDC_2AADC(s16 arg0, u8 arg1) {
    D_800FC834_FD434[arg0].unk01 = arg1;
}

u8 func_80029F04_2AB04(s16 arg0) {
    return D_800FC834_FD434[arg0].unk01;
}

void func_80029F2C_2AB2C(s16 arg0, s32 arg1) {
    func_800298A4_2A4A4(arg0, 0x1C00, arg1);
    D_800FC834_FD434[arg0].hmf->unk00 = ((u32)arg1 >> 10) & 7;
}

void func_80029F94_2AB94(s16 arg0, f32 arg1) {
    D_800FC834_FD434[arg0].unk48 = arg1;
}

void func_80029FBC_2ABBC(s16 arg0, f32 arg1) {
    D_800FC834_FD434[arg0].unk54 = arg1;
}

void func_80029FE4_2ABE4(s16 arg0, f32 arg1) {
    HmfModel* modelP = &D_800FC834_FD434[arg0];

    modelP->unk44 = arg1;
}

/* MP1 func_80026040 (src/24740.c); MP2 copies only frame buffers still shared with unk40 */
void func_8002A00C_2AC0C(s16 arg0) {
    HmfData* hmf = D_800FC834_FD434[arg0].hmf;
    HmfVtx* dst;
    HmfVtx* src;
    s16 n;
    s16 j;
    s16 i;

    for (i = 0; i < D_800FDBCA_FE7CA; i++) {
        src = hmf->unk40;
        if (hmf->unk44[i] == src) {
            n = hmf->unk18;
            dst = hmf->unk44[i] = func_80027154_27D54(n * sizeof(HmfVtx), hmf->unk0E + 1);
            for (j = 0; j < n; j++) {
                *dst++ = *src++;
            }
        }
    }
}

/* MP1 func_80026174 (src/24740.c): blend two models' vertices */
void func_8002A15C_2AD5C(s16 arg0, s16 arg1, f32 arg2) {
    HmfData* model = D_800FC834_FD434[arg0].hmf;
    HmfVtx* var_a3 = model->unk40;
    HmfVtx* var_a2 = D_800FC834_FD434[arg1].hmf->unk40;
    HmfVtx* var_t0 = model->unk44[D_800FDBE0_FE7E0];
    s16 n = model->unk18;
    s16 i;

    for (i = 0; i < n; i++) {
        *var_t0 = *var_a3;
        if (var_a3->unk00 != var_a2->unk00 || var_a3->unk02 != var_a2->unk02 || var_a3->unk04 != var_a2->unk04) {
            var_t0->unk00 = var_a3->unk00 * arg2 + var_a2->unk00 * (1.0f - arg2);
            var_t0->unk02 = var_a3->unk02 * arg2 + var_a2->unk02 * (1.0f - arg2);
            var_t0->unk04 = var_a3->unk04 * arg2 + var_a2->unk04 * (1.0f - arg2);
            var_t0->unk0C[0] = (s32) ((s8) var_a3->unk0C[0] * arg2 + (s8) var_a2->unk0C[0] * (1.0f - arg2));
            var_t0->unk0C[1] = (s32) ((s8) var_a3->unk0C[1] * arg2 + (s8) var_a2->unk0C[1] * (1.0f - arg2));
            var_t0->unk0C[2] = (s32) ((s8) var_a3->unk0C[2] * arg2 + (s8) var_a2->unk0C[2] * (1.0f - arg2));
        }
        var_a3++;
        var_a2++;
        var_t0++;
    }
}

void func_8002A5D4_2B1D4(HmfData* arg0, HmfData* arg1, f32 arg2, s16 arg3, s16 arg4, s32 arg5);

/* MP1 func_80026404 (src/24740.c) */
void func_8002A3EC_2AFEC(s16 arg0, s16 arg1, f32 arg2, char* arg3, s32 arg4) {
    s16 temp_s0;
    s16 temp_v0;
    HmfData* temp_s2;
    HmfData* temp_s3;

    temp_s3 = D_800FC834_FD434[arg0].hmf;
    temp_s2 = D_800FC834_FD434[arg1].hmf;
    temp_s0 = func_80038398_38F98(temp_s3, arg3);
    temp_v0 = func_80038398_38F98(temp_s2, arg3);

    if (temp_s0 == -1 || temp_v0 == -1) {
        return;
    }

    func_8002A5D4_2B1D4(temp_s3, temp_s2, arg2, temp_s0, temp_v0, arg4);
}

/* MP1 func_800264F8 (src/24740.c) */
void func_8002A4E0_2B0E0(s16 arg0, s16 arg1, f32 arg2, char* arg3, char* arg4, s32 arg5) {
    s16 temp_s0;
    s16 temp_v0;
    HmfData* temp_s2;
    HmfData* temp_s3;

    temp_s3 = D_800FC834_FD434[arg0].hmf;
    temp_s2 = D_800FC834_FD434[arg1].hmf;
    temp_s0 = func_80038398_38F98(temp_s3, arg3);
    temp_v0 = func_80038398_38F98(temp_s2, arg4);

    if (temp_s0 == -1 || temp_v0 == -1) {
        return;
    }

    func_8002A5D4_2B1D4(temp_s3, temp_s2, arg2, temp_s0, temp_v0, arg5);
}

/* MP1 func_800265EC (src/24740.c): blend one part's vertices */
void func_8002A5D4_2B1D4(HmfData* arg0, HmfData* arg1, f32 arg2, s16 arg3, s16 arg4, s32 arg5) {
    HmfVtx* var_a2;
    HmfVtx* var_a3;
    HmfVtx* var_t0;
    s16 temp_v1;
    s16 temp_t3;
    s16 var_t4;
    s16 i;

    var_t4 = 0;

    if (arg5 != 0) {
        var_t0 = arg0->unk40;
        var_a2 = arg0->unk44[D_800FDBE0_FE7E0];
        var_t4 = arg0->unk64[arg3].unk0A;

        for (i = 0; i < var_t4; i++) {
            *var_a2 = *var_t0;
            var_t0++;
            var_a2++;
        }
    }

    var_t0 = &arg0->unk40[arg0->unk64[arg3].unk0A];
    var_a3 = &arg1->unk40[arg1->unk64[arg4].unk0A];
    var_a2 = &arg0->unk44[D_800FDBE0_FE7E0][arg0->unk64[arg3].unk0A];

    temp_t3 = arg0->unk64[arg3].unk0C;
    for (i = 0; i < temp_t3; i++) {
        *var_a2 = *var_t0;
        if (var_t0->unk00 != var_a3->unk00 || var_t0->unk02 != var_a3->unk02 || var_t0->unk04 != var_a3->unk04) {
            var_a2->unk00 = var_t0->unk00 * arg2 + var_a3->unk00 * (1.0f - arg2);
            var_a2->unk02 = var_t0->unk02 * arg2 + var_a3->unk02 * (1.0f - arg2);
            var_a2->unk04 = var_t0->unk04 * arg2 + var_a3->unk04 * (1.0f - arg2);
            var_a2->unk0C[0] = (s32) ((s8) var_t0->unk0C[0] * arg2 + (s8) var_a3->unk0C[0] * (1.0f - arg2));
            var_a2->unk0C[1] = (s32) ((s8) var_t0->unk0C[1] * arg2 + (s8) var_a3->unk0C[1] * (1.0f - arg2));
            var_a2->unk0C[2] = (s32) ((s8) var_t0->unk0C[2] * arg2 + (s8) var_a3->unk0C[2] * (1.0f - arg2));
        }
        var_t0++;
        var_a3++;
        var_a2++;
    }

    if (arg5 != 0) {
        temp_v1 = var_t4 + temp_t3;
        temp_t3 = arg0->unk18;
        for (i = temp_v1; i < temp_t3; i++) {
            *var_a2 = *var_t0;
            var_t0++;
            var_a2++;
        }
    }
}

void func_8002A9E8_2B5E8(s16 arg0) {
    D_800CA028_CAC28 = arg0;
}

/* HmfData.unk84 entries (MP1 unk2C0C0Struct50, 0xA4 there) */
typedef struct HmfMotionGroup {
    /* 0x00 */ s16 unk00; /* count of unk50 */
    /* 0x02 */ char unk02[0x4E];
    /* 0x50 */ s16* unk50; /* part indices */
    /* 0x54 */ char unk54[0x44];
} HmfMotionGroup; /* size = 0x98 */

/* MP1 func_80026A0C (src/24740.c; its decomp-permuter shape): the motion group holding a part;
   MP2 falls back to the hit transforms (unk6C) when the model has no groups */
void* func_8002A9F4_2B5F4(s16 arg0, char* arg1) {
    HmfData* model = D_800FC834_FD434[arg0].hmf;
    s16 new_var;
    s16 idx = func_80038398_38F98(model, arg1);
    s16 n;
    s16 j;
    s16 i;

    if (model->unk84 != (void*)-1) {
        for (i = 0; i < model->unk16; i++) {
            n = ((HmfMotionGroup*)model->unk84)[i].unk00;
            for (j = 0; j < n; j++) {
                if (((HmfMotionGroup*)model->unk84)[i].unk50[j] == idx) {
                    break;
                }
            }
            new_var = j;
            if (new_var != n) {
                break;
            }
        }
        if (i == model->unk16) {
            return (void*)-1;
        }
        return &((HmfMotionGroup*)model->unk84)[i];
    }
    for (i = 0; i < model->unk68; i++) {
        if (model->unk6C[i].unk00 == idx) {
            break;
        }
    }
    if (i == model->unk68) {
        return (void*)-1;
    }
    return &model->unk6C[i];
}

void func_8002AF2C_2BB2C(HmfData* arg0, f32 arg1, f32 arg2, u16 arg3, u16 arg4);
void func_8002B184_2BD84(HmfData* arg0, f32 arg1, f32 arg2, u16 arg3, u16 arg4);
void func_8002B4C4_2C0C4(HmfData* arg0, f32 arg1, f32 arg2, u16 arg3, u16 arg4);

/* MP1 func_80026B8C (src/24740.c) */
void func_8002AC10_2B810(s16 arg0, f32 arg1, f32 arg2, s32 arg3) {
    HmfData* model = D_800FC834_FD434[arg0].hmf;

    if (model != NULL) {
        switch (arg3 & 0xF) {
            case 0:
                func_8002AF2C_2BB2C(model, arg1, arg2, 0, model->unk1A);
                break;
            case 1:
                func_8002B184_2BD84(model, arg1, arg2, 0, model->unk1A);
                break;
            case 2:
                func_8002B4C4_2C0C4(model, arg1, arg2, 0, model->unk1A);
                break;
        }
    }
}

/* MP1 func_80026C6C (src/24740.c) */
// retail keeps a second copy of arg4 (s2) for the switch, as MP1's does (masked 16)
#ifdef NON_MATCHING
void func_8002ACF0_2B8F0(s16 arg0, f32 arg1, f32 arg2, char* arg3, s32 arg4) {
    HmfData* model = D_800FC834_FD434[arg0].hmf;
    HmfVtx* src;
    HmfVtx* dst;
    s16 idx;
    s16 n;
    s16 i;

    if (model == NULL) {
        return;
    }
    idx = func_80038398_38F98(model, arg3);
    if (idx == -1) {
        return;
    }
    if (arg4 & 0x80) {
        src = model->unk40;
        dst = model->unk44[D_800FDBE0_FE7E0];
        n = model->unk18;
        for (i = 0; i < n; i++) {
            *dst++ = *src++;
        }
    }
    switch (arg4 & 0xF) {
        case 0:
            func_8002AF2C_2BB2C(model, arg1, arg2, model->unk64[idx].unk0E, model->unk64[idx].unk10);
            break;
        case 1:
            func_8002B184_2BD84(model, arg1, arg2, model->unk64[idx].unk0E, model->unk64[idx].unk10);
            break;
        case 2:
            func_8002B4C4_2C0C4(model, arg1, arg2, model->unk64[idx].unk0E, model->unk64[idx].unk10);
            break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/274D0", func_8002ACF0_2B8F0);
#endif

extern f32 D_800D2210_D2E10[];
extern f32 D_800CA02C_CAC2C;
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32);
void func_8002CD78_2D978(s16, u8, u8, u8, u8);
void func_8002CDB4_2D9B4(s16, u8, u8, u8, u8);

void func_8002AF2C_2BB2C(HmfData* arg0, f32 arg1, f32 arg2, u16 arg3, u16 arg4) {
    HmfFace* b = &arg0->unkB4[arg3];
    f32 inv = 1.0f - arg1;
    HmfVtx* src;
    HmfVtx* dst;
    s16* idx;
    s16 cx, cy, cz;
    s16 sx, sy, sz;
    s16 n;
    s16 j;
    s16 i;

    for (i = 0; i < arg4; i++) {
        cx = b->unk0C;
        cy = b->unk10;
        cz = b->unk14;
        sx = cx * arg2;
        sy = cy * arg2;
        sz = cz * arg2;
        n = (u8)(b->unk00 & 0x7F);
        idx = b->unk02;
        for (j = 0; j < n; j++) {
            src = &arg0->unk40[*idx];
            dst = &arg0->unk44[D_800FDBE0_FE7E0][*idx];
            dst->unk00 = (src->unk00 - cx) * inv + sx;
            dst->unk02 = (src->unk02 - cy) * inv + sy;
            dst->unk04 = (src->unk04 - cz) * inv + sz;
            idx++;
        }
        b++;
    }
}

void func_8002B184_2BD84(HmfData* arg0, f32 arg1, f32 arg2, u16 arg3, u16 arg4) {
    unk24740Floats8 sp0 = *(unk24740Floats8*)D_800D2210_D2E10;
    HmfFace* b = &arg0->unkB4[arg3];
    f32 inv = 1.0f - arg1;
    HmfVtx* src;
    HmfVtx* dst;
    s16* idx;
    s16 cx, cy, cz;
    s16 sx, sy, sz;
    s16 n;
    s16 j;
    s16 i;

    for (i = 0; i < arg4; i++) {
        cx = b->unk0C;
        cy = b->unk10;
        cz = b->unk14;
        if (arg2 == 1.0f) {
            sx = cx * arg2;
            sy = cy * arg2;
            sz = cz * arg2;
        } else {
            sx = cx * arg2 * sp0.v[i & 7];
            sy = cy * arg2 * sp0.v[i & 7];
            sz = cz * arg2 * sp0.v[i & 7];
        }
        n = (u8)(b->unk00 & 0x7F);
        idx = b->unk02;
        for (j = 0; j < n; j++) {
            src = &arg0->unk40[*idx];
            dst = &arg0->unk44[D_800FDBE0_FE7E0][*idx];
            dst->unk00 = (src->unk00 - cx) * inv + sx;
            dst->unk02 = (src->unk02 - cy) * inv + sy;
            dst->unk04 = (src->unk04 - cz) * inv + sz;
            idx++;
        }
        b++;
    }
}

void func_8002B4C4_2C0C4(HmfData* arg0, f32 arg1, f32 arg2, u16 arg3, u16 arg4) {
    unk24740Floats8 sp10 = *(unk24740Floats8*)D_800D2210_D2E10;
    HmfFace* b = &arg0->unkB4[arg3];
    f32 inv = 1.0f - arg1;
    f32 s = HuMathSin(D_800CA02C_CAC2C);
    f32 c = func_800B7890_B8490(D_800CA02C_CAC2C);
    HmfVtx* src;
    HmfVtx* dst;
    s16* idx;
    s16 cx, cy, cz;
    s16 sx, sy, sz;
    f32 dx, dy, dz;
    s16 n;
    s16 j;
    s16 i;

    for (i = 0; i < arg4; i++) {
        cx = b->unk0C;
        cy = b->unk10;
        cz = b->unk14;
        if (arg2 == 1.0f) {
            sx = cx * arg2;
            sy = cy * arg2;
            sz = cz * arg2;
        } else {
            sx = cx * arg2 * sp10.v[i & 7];
            sy = cy * arg2 * sp10.v[i & 7];
            sz = cz * arg2 * sp10.v[i & 7];
        }
        n = (u8)(b->unk00 & 0x7F);
        idx = b->unk02;
        switch (i & 3) {
            case 0:
            case 2:
                for (j = 0; j < n; j++) {
                    src = &arg0->unk40[*idx];
                    dst = &arg0->unk44[D_800FDBE0_FE7E0][*idx];
                    dx = src->unk00 - cx;
                    dy = src->unk02 - cy;
                    dz = src->unk04 - cz;
                    dst->unk00 = dx * inv + sx;
                    dst->unk02 = (dy * c + dz * s) * inv + sy;
                    dst->unk04 = (-dy * s + dz * c) * inv + sz;
                    idx++;
                }
                break;
            case 1:
                for (j = 0; j < n; j++) {
                    src = &arg0->unk40[*idx];
                    dst = &arg0->unk44[D_800FDBE0_FE7E0][*idx];
                    dx = src->unk00 - cx;
                    dy = src->unk02 - cy;
                    dz = src->unk04 - cz;
                    dst->unk00 = (dx * c - dz * s) * inv + sx;
                    dst->unk02 = dy * inv + sy;
                    dst->unk04 = (dx * s + dz * c) * inv + sz;
                    idx++;
                }
                break;
            case 3:
                for (j = 0; j < n; j++) {
                    src = &arg0->unk40[*idx];
                    dst = &arg0->unk44[D_800FDBE0_FE7E0][*idx];
                    dx = src->unk00 - cx;
                    dy = src->unk02 - cy;
                    dz = src->unk04 - cz;
                    dst->unk00 = (dx * c + dy * s) * inv + sx;
                    dst->unk02 = (-dx * s + dy * c) * inv + sy;
                    dst->unk04 = dz * inv + sz;
                    idx++;
                }
                break;
        }
        b++;
    }
}

extern HmfTex* D_800FD89C_FE49C; /* the texture table, 128 entries */
u16 func_8001F4AC_200AC(char*); /* name hash */
s32 func_800B0FD0_B1BD0(char*, char*); /* strcmp */

/* MP1 func_80027AC8 (src/24740.c): point a model's texture arg1 at the loaded texture arg2 */
void func_8002BB4C_2C74C(s16 arg0, char* arg1, char* arg2) {
    HmfTex* found = NULL;
    HmfData* model = D_800FC834_FD434[arg0].hmf;
    u16 hash = func_8001F4AC_200AC(arg2);
    s16 i;

    for (i = 0; i < 128; i++) {
        if (D_800FD89C_FE49C[i].unk24 != 0 && D_800FD89C_FE49C[i].unk24 == hash
            && func_800B0FD0_B1BD0((char*)&D_800FD89C_FE49C[i], arg2) == 0) {
            found = &D_800FD89C_FE49C[i];
            break;
        }
    }
    hash = func_8001F4AC_200AC(arg1);
    for (i = 0; i < model->unk12; i++) {
        if (model->unk88[i].unk0C->unk24 == hash) {
            model->unk88[i].unk0C = found;
        }
    }
}

/* MP1 func_80027C1C (src/24740.c): scroll the texture coordinates */
void func_8002BCA8_2C8A8(s16 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4) {
    u16 w;
    u16 h;
    s16 i;
    u16 var_a0;
    u16 var_a0_2;
    s16 temp_t2;
    HmfData* temp_s0;
    HmfVtx* var_t0;
    HmfVtx* var_t1;

    temp_s0 = D_800FC834_FD434[arg0].hmf;
    if (temp_s0 != NULL) {
        var_t0 = temp_s0->unk40;
        var_t1 = temp_s0->unk44[D_800FDBE0_FE7E0];
        temp_t2 = temp_s0->unk18;
        w = arg3 << 5;
        h = arg4 << 5;
        var_a0 = arg1 * 32.0f;
        var_a0_2 = arg2 * 32.0f;

        if (arg1 < 0.0f) {
            arg1 = -arg1;
        }
        if (arg2 < 0.0f) {
            arg2 = -arg2;
        }

        if ((arg1 * 32.0f) > w) {
            var_a0 = var_a0 % w;
        }

        if ((arg2 * 32.0f) > h) {
            var_a0_2 = var_a0_2 % h;
        }

        for (i = 0; i < temp_t2; i++) {
            var_t1->unk08 = var_a0 + var_t0->unk08;
            var_t1->unk0A = var_a0_2 + var_t0->unk0A;
            var_t0++;
            var_t1++;
        }
    }
}

/* MP1 func_80027E48 (src/24740.c): scroll one part's texture coordinates */
void func_8002BED4_2CAD4(s16 arg0, f32 arg1, f32 arg2, u16 arg3, u16 arg4, char* arg5, u8 arg6) {
    s16 i;
    u16 var_a0;
    u16 var_a0_2;
    s16 temp_t2;
    HmfData* temp_s0;
    HmfVtx* var_t0;
    HmfVtx* var_t1;
    s32 temp2;

    temp_s0 = D_800FC834_FD434[arg0].hmf;
    if (temp_s0 != NULL) {
        if (arg6 != 0) {
            var_t0 = temp_s0->unk40;
            var_t1 = temp_s0->unk44[D_800FDBE0_FE7E0];
            temp_t2 = temp_s0->unk18;
            for (i = 0; i < temp_t2; i++) {
                *var_t1++ = *var_t0++;
            }
        }
        temp2 = func_80038398_38F98(temp_s0, arg5);
        temp_t2 = temp_s0->unk64[temp2].unk0C;
        var_t0 = &temp_s0->unk40[temp_s0->unk64[temp2].unk0A];
        var_t1 = &temp_s0->unk44[D_800FDBE0_FE7E0][temp_s0->unk64[temp2].unk0A];
        arg3 = (arg3 << 5);
        arg4 = (arg4 << 5);
        var_a0 = arg1 * 32.0f;
        var_a0_2 = arg2 * 32.0f;

        if (arg1 < 0.0f) {
            arg1 = -arg1;
        }
        if (arg2 < 0.0f) {
            arg2 = -arg2;
        }

        if ((arg1 * 32.0f) > arg3) {
            var_a0 = var_a0 % arg3;
        }

        if ((arg2 * 32.0f) > arg4) {
            var_a0_2 = var_a0_2 % arg4;
        }

        for (i = 0; i < temp_t2; i++) {
            var_t1->unk08 = var_a0 + var_t0->unk08;
            var_t1->unk0A = var_a0_2 + var_t0->unk0A;
            var_t0++;
            var_t1++;
        }
    }
}

/* MP1 func_80028180 (src/24740.c): set one part's vertex colours */
void func_8002C20C_2CE0C(s16 arg0, char* arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5) {
    HmfData* model = D_800FC834_FD434[arg0].hmf;
    HmfVtx* src;
    HmfVtx* dst;
    s16 idx;
    s16 n;
    s16 i;

    if (model != NULL) {
        if (arg5 != 0) {
            src = model->unk40;
            dst = model->unk44[D_800FDBE0_FE7E0];
            n = model->unk18;
            for (i = 0; i < n; i++) {
                *dst++ = *src++;
            }
        }
        idx = func_80038398_38F98(model, arg1);
        n = model->unk64[idx].unk0C;
        src = &model->unk44[D_800FDBE0_FE7E0][model->unk64[idx].unk0A];
        for (i = 0; i < n; i++) {
            src->unk0C[0] = arg2;
            src->unk0C[1] = arg3;
            src->unk0C[2] = arg4;
            src++;
        }
    }
}

/* A part's face (MP1 unk2C0C0Struct20; 30560 has the same view) */
typedef struct HmfFaceRec {
    /* 0x00 */ u8 unk00; /* vertex count | 0x80 unlit */
    /* 0x01 */ s8 unk01[3]; /* normal */
    /* 0x04 */ s16 unk04[4]; /* vertices */
    /* 0x0C */ f32 unk0C[4]; /* s */
    /* 0x1C */ f32 unk1C[4]; /* t */
    /* 0x2C */ u8 unk2C[4];
    /* 0x30 */ s16 unk30;
    /* 0x32 */ s16 unk32;
} HmfFaceRec; /* size 0x34 */

/* MP1 func_80028314 (src/24740.c): reverse every face's winding */
void func_8002C3A0_2CFA0(s16 arg0) {
    HmfData* model = D_800FC834_FD434[arg0].hmf;
    HmfPart* obj;
    HmfFaceRec* key;
    s16 tmp;
    f32 ftmp;
    s16 n;
    s16 k;
    s16 j;
    s16 i;

    for (i = 0; i < model->unk10; i++) {
        obj = &model->unk64[i];
        for (j = 0; j < obj->unk04; j++) {
            key = &obj->unk54[j];
            n = (u8)(key->unk00 & 0x7F);
            for (k = 0; k < n / 2; k++) {
                tmp = key->unk04[k];
                key->unk04[k] = key->unk04[n - k - 1];
                key->unk04[n - k - 1] = tmp;
                ftmp = key->unk0C[k];
                key->unk0C[k] = key->unk0C[n - k - 1];
                key->unk0C[n - k - 1] = ftmp;
                ftmp = key->unk1C[k];
                key->unk1C[k] = key->unk1C[n - k - 1];
                key->unk1C[n - k - 1] = ftmp;
            }
        }
    }
}

void func_8002C524_2D124(s16 arg0, u8 arg1, s8 arg2) {
    HmfModel* modelP = &D_800FC834_FD434[arg0];

    modelP->unk06 = arg1;
    modelP->unk60 = modelP->unk58 = 0.0f;
    modelP->unk07 = arg2;
    modelP->unk5C = 1.0f;
}

void func_8002C570_2D170(s16 arg0) {
    D_800FC834_FD434[arg0].unk06 = 0xFF;
}

void func_8002C59C_2D19C(s16 arg0, s16 arg1, u8 arg2, u8 arg3, u8 arg4) {
    D_800FA60C_FB20C = 1;
    D_801027FA_1033FA = arg0;
    D_800F8C54_F9854 = arg1;
    D_800FC9E9_FD5E9 = arg2;
    D_8010002C_100C2C = arg3;
    D_800F9D2C_FA92C = arg4;
}

void func_8002C5D8_2D1D8(void) {
    D_800FA60C_FB20C = 0;
}

void func_8002C5E4_2D1E4(s16 arg0, s16 arg1) {
    D_800FC834_FD434[arg0].hmf = D_800FC834_FD434[arg1].hmf;
}

/* MP1 func_8002859C (src/24740.c): make model arg0 follow part arg2 of model arg1 */
void func_8002C628_2D228(s16 arg0, s16 arg1, char* arg2) {
    HmfData* model = D_800FC834_FD434[arg1].hmf;
    s16 idx = func_80038398_38F98(model, arg2);

    D_800FC834_FD434[arg0].unk68 = model;
    D_800FC834_FD434[arg0].unk0A = idx;
}

void func_8002C6A8_2D2A8(s16 arg0) {
    HmfData* model = D_800FC834_FD434[arg0].hmf;

    model->unkA0 = func_8003CF84_3DB84(model);
}

f32 func_8003B628_3C228(HmfMotionSlot*, s16, f32, f32, f32);

/* MP1 func_80028668 (src/24740.c): advance a model's three motions */
void func_8002C6F4_2D2F4(HmfModel* arg0, u16 arg1) {
    arg0->unk40 = func_8003B628_3C228(&D_800F92B4_F9EB4[arg0->unk02], arg0->unk03, arg0->unk40, arg0->unk48, (f32)arg1 * arg0->unk44);
    if (arg0->unk04 != 0xFF) {
        arg0->unk4C = func_8003B628_3C228(&D_800F92B4_F9EB4[arg0->unk04], arg0->unk05, arg0->unk4C, arg0->unk54, (f32)arg1 * arg0->unk50);
    }
    if (arg0->unk06 != 0xFF) {
        arg0->unk58 = func_8003B628_3C228(&D_800F92B4_F9EB4[arg0->unk06], (u8)arg0->unk07, arg0->unk58, arg0->unk60, (f32)arg1 * arg0->unk5C);
    }
}

void func_8003F57C_4017C(s16, s16);

void func_8002C810_2D410(HmfModel* arg0) {
    HmfData* hmf = arg0->hmf;
    s16 frame = arg0->unk40;
    s16 i;

    /* unkC8 holds a u8* (a pointer in an s32 field) */
    for (i = 0; i < hmf->unk28; i++) {
        func_8003E4F4_3F0F4(((u8*)hmf->unkC8)[i], 1, 1);
        func_8003F57C_4017C(((u8*)hmf->unkC8)[i], frame);
    }
}

extern HmfData D_800F8438_F9038; /* scratch model for motion-only files */

/* MP1 func_80028784 (src/24740.c): load a motion file */
s16 func_8002C8B8_2D4B8(u8* arg0, s16 arg1) {
    s16 ret;

    if (arg0[0] != 'M' || arg0[1] != 'T' || arg0[2] != 'N' || arg0[3] != 'X') {
        D_8010106C_101C6C = 10256;
        D_800FA1AA_FADAA = 10257;
        D_800F8438_F9038.unk0E = D_8010106C_101C6C;
        func_8001D190_1DD90(&D_800F8438_F9038, arg0, arg1);
        ret = func_80038E38_39A38(arg0, &D_800F8438_F9038);
        func_80027274_27E74(D_8010106C_101C6C);
        func_80027274_27E74(D_800FA1AA_FADAA);
    } else {
        ret = func_80038F0C_39B0C(arg0);
    }
    if (arg1 & 8) {
        D_800FD440_FE040(arg0);
    }
    return ret;
}

void func_8002C9C0_2D5C0(s16 arg0, s16 arg1) {
    HmfModel *temp_v0;

    temp_v0 = &D_800FC834_FD434[arg0];
    temp_v0->unk02 = arg1;
    temp_v0->unk03 = 0;
    temp_v0->unk48 =
        temp_v0->unk40 = 0.0f;
    temp_v0->unk44 = 1.0f;
    temp_v0->unk04 = 0xFF;
}

f32 func_8002CA14_2D614(s16 arg0) {
    return D_800F92B4_F9EB4[arg0].unk02;
}

void func_8002CA48_2D648(u8 arg0, u8 arg1, u8 arg2) {
    D_800C9B70_CA770 = arg0;
    D_800C9B71_CA771 = arg1;
    D_800C9B72_CA772 = arg2;
}

/* MP1 func_80028928 (src/24740.c) */
void func_8002CA64_2D664(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    HmfModel* p = &D_800FC834_FD434[arg0];

    if ((arg1 & 1) && p->unk02 != 0xFF) {
        p->unk03 = (p->unk03 & ~arg2) | arg3;
        if ((arg1 & 2) && p->unk04 != 0xFF) {
            p->unk05 = (p->unk05 & ~arg2) | arg3;
        }
        if ((arg1 & 4) && p->unk06 != 0xFF) {
            p->unk07 = arg3 | (p->unk07 & ~arg2);
        }
    }
}

/* MP1 func_800289D0 (src/24740.c): level of detail, model arg1 replaces arg0 beyond distance arg2 */
void func_8002CB0C_2D70C(s16 arg0, s16 arg1, f32 arg2) {
    HmfModel* p = &D_800FC834_FD434[arg0];

    p->unk09 = arg1;
    p->unk6C = p->hmf;
    p->unk14 = arg2;
    p = &D_800FC834_FD434[arg1];
    p->unk09 = arg0;
    p->unk6C = NULL;
    p->unk14 = 0.0f;
    p->unk18 |= 4;
}

f32 func_800B1830_B2430(f32);
#define CAM ((HuCamera*)D_800FD2A8_FDEA8)

/* MP1 func_80028A34 (src/24740.c): pick the level-of-detail model by camera distance */
void func_8002CB78_2D778(s16 arg0) {
    HmfModel* p = &D_800FC834_FD434[arg0];
    f32 dx = CAM->pos.x - p->pos.x;
    f32 dy = CAM->pos.y - p->pos.y;
    f32 dz = CAM->pos.z - p->pos.z;
    HmfData* model;
    HmfModel* q;
    s32 flags;
    s16 i;

    if (p->unk14 < func_800B1830_B2430(dx * dx + dy * dy + dz * dz)) {
        model = p->unk6C;
    } else {
        model = D_800FC834_FD434[p->unk09].hmf;
    }
    if (model != p->hmf) {
        p->hmf = model;
        for (i = 0; i < HU3D_MODEL_MAX; i++) {
            q = &D_800FC834_FD434[i];
            if (q->hmf != NULL) {
                continue;
            }
            flags = q->unk18;
            if (flags & 4) {
                continue;
            }
            if (!(flags & 0x4000)) {
                continue;
            }
            if (p->hmf == q->unk68 || D_800FC834_FD434[p->unk09].hmf == q->unk68) {
                D_800FC834_FD434[i].unk68 = model;
            }
        }
    }
    D_800FC834_FD434[p->unk09].unk18 |= 4;
}

s32 func_8002CD24_2D924(s16 arg0) {
    HmfModel* p = &D_800FC834_FD434[arg0];

    return p->hmf == D_800FC834_FD434[p->unk09].hmf;
}

void func_8002CD6C_2D96C(u8 arg0) {
    D_800F8C48_F9848 = arg0;
}

/* MP1 func_80028BEC (src/24740.c) */
void func_8002CD78_2D978(s16 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4) {
    HmfData* model = D_800FC834_FD434[arg0].hmf;

    model->unk02 = arg1;
    model->unk03 = arg2;
    model->unk04 = arg3;
    model->unk05 = arg4;
}

/* MP1 func_80028C28 (src/24740.c) */
void func_8002CDB4_2D9B4(s16 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4) {
    HmfData* model = D_800FC834_FD434[arg0].hmf;

    model->unk06 = arg1;
    model->unk07 = arg2;
    model->unk08 = arg3;
    model->unk09 = arg4;
}

void func_8002CDF0_2D9F0(s16 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4) {
    func_8002CD78_2D978(arg0, arg1, arg2, arg3, arg4);
    func_8002CDB4_2D9B4(arg0, arg1 * 0.5f, arg2 * 0.5f, arg3 * 0.5f, arg4 * 0.5f);
}

void func_8002D018_2DC18(s16 arg0, void* arg1) {
    D_800F8F80_F9B80[arg0] = arg1;
}

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002D030_2DC30);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002D0A0_2DCA0);

void func_8002D124_2DD24(s16 index) {
    s16 i;
    HmfMat* temp_v1;
    HmfData* temp_s0;

    temp_s0 = D_800FC834_FD434[index].hmf;
    HmfModelObjAttrSet(index, 0x110000, 0x110000);
    for (i = 0; i < temp_s0->unk1E; i++) {
        temp_s0->unk8C[i].unk0D = 0xFF;
        temp_v1 = &temp_s0->unk8C[i];
        temp_v1->unk0C = temp_v1->unk0C | 5;
    }
    func_80029A8C_2A68C(index);
}

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002D1EC_2DDEC);

void func_8002D274_2DE74(s16 arg0, s8 arg1, s8 arg2, s8 arg3) {
    HmfModel *other;

    other = D_800FC834_FD434[arg0].unkB4;
    if (other != NULL) {
        other->unk00 = arg1;
        other->unk01 = arg2;
        other->unk02 = arg3;
    }
}

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002D2B4_2DEB4);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002D3C0_2DFC0);

void func_8002D4A0_2E0A0(s16 arg0) {
    D_800FC834_FD434[arg0].unk02 = 0xFF;
}
