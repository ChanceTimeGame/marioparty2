#include "common.h"

/* ---- Model manager (MP3 src/hmfman.c, MP1 src/24740.c); MP3's HmfModel layout ---- */

typedef struct {
    /* 0x00 */ char unk00[0x50];
    /* 0x50 */ s32 unk50;
    /* 0x54 */ char unk54[0x14];
} HmfObject; // size 0x68

typedef struct {
    /* 0x00 */ char unk00[0xC];
    /* 0x0C */ u8 unk0C;
    /* 0x0D */ u8 unk0D;
} HmfMaterial; // size 0xE

typedef struct {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ char unk_06[0xA];
} HmfVertex; // size 0x10 (MP1 unk2C0C0StructE0)

typedef struct {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ char unk_01;
    /* 0x02 */ s16 unk_02[1]; // unknown array size
    /* 0x04 */ char unk_04[8];
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
} HmfVtxGroup; // size 0x18 (MP1 unk2C0C0StructB0)

typedef struct {
    /* 0x00 */ f32 v[8];
} unk24740Floats8;

typedef struct {
    /* 0x00 */ u8 unk00;
    /* 0x01 */ char unk01[9];
    /* 0x0A */ u8 unk0A;
    /* 0x0B */ char unk0B[3];
    /* 0x0E */ s16 unk0E;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ char unk12[0xC];
    /* 0x1E */ s16 unk1E;
    /* 0x20 */ char unk20[0x1C];
    /* 0x3C */ Gfx* unk3C;
    /* 0x40 */ HmfVertex* unk40;
    /* 0x44 */ HmfVertex* unk44[4]; /* per frame buffer */
    /* 0x54 */ char unk54[0x10];
    /* 0x64 */ HmfObject* unk64;
    /* 0x68 */ char unk68[0x24];
    /* 0x8C */ HmfMaterial* unk8C;
    /* 0x90 */ char unk90[0x10];
    /* 0xA0 */ void* unkA0;
    /* 0xA4 */ char unkA4[0x10];
    /* 0xB4 */ HmfVtxGroup* unkB4;
} HmfData;

typedef struct HmfModel {
    /* 0x00 */ s8 unk00;
    /* 0x01 */ u8 unk01;
    /* 0x02 */ u8 unk02;
    /* 0x03 */ u8 unk03;
    /* 0x04 */ u8 unk04;
    /* 0x05 */ u8 unk05;
    /* 0x06 */ u8 unk06;
    /* 0x07 */ s8 unk07;
    /* 0x08 */ u8 unk08;
    /* 0x09 */ u8 unk09;
    /* 0x0A */ u8 unk0A;
    /* 0x0C */ s16 unk0C;
    /* 0x0E */ s16 unk0E;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ char unk12[6];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ Vec pos;
    /* 0x28 */ Vec rot;
    /* 0x34 */ Vec scale;
    /* 0x40 */ f32 unk40;
    /* 0x44 */ f32 unk44;
    /* 0x48 */ f32 unk48;
    /* 0x4C */ f32 unk4C;
    /* 0x50 */ f32 unk50;
    /* 0x54 */ f32 unk54;
    /* 0x58 */ f32 unk58;
    /* 0x5C */ f32 unk5C;
    /* 0x60 */ f32 unk60;
    /* 0x64 */ HmfData* hmf;
    /* 0x68 */ char unk68[8];
    /* 0x70 */ void (*unk70)(Gfx**, s32, s32);
    /* 0x74 */ f32 mtx[16];
    /* 0xB4 */ struct HmfModel* unkB4;
    /* 0xB8 */ char unkB8[4];
    /* 0xBC */ void* unkBC;
} HmfModel; // Size 0xC0

#define HU3D_MODEL_MAX 128

extern HmfModel* D_800FC834_FD434; /* HmfModelData */
extern s32 D_800FDC98_FE898;
extern s32 D_800FD848_FE448;
extern s16 D_800FDCD0_FE8D0;
extern u8 D_800FDC9C_FE89C;
extern u8 D_800F94A4_FA0A4;
extern void* D_800F8F80_F9B80[2];
extern void* D_800C9B80_CA780; /* gCameraList */
extern s16 D_800F64B2_F70B2;
extern u8 D_800C9B70_CA770;
extern u8 D_800C9B71_CA771;
extern u8 D_800C9B72_CA772;
extern u8 D_800FA60C_FB20C;
extern s16 D_801027FA_1033FA;
extern s16 D_800F8C54_F9854;
extern u8 D_800FC9E9_FD5E9;
extern u8 D_8010002C_100C2C;
extern u8 D_800F9D2C_FA92C;

void func_8002F960_30560(void* (*arg0)(s32), void (*arg1)(void*), u16 arg2, u16 arg3, u16 arg4, u8 arg5);
void func_80038DD0_399D0(void);
void func_8002FB6C_3076C(void);
s16 func_80027D3C_2893C(s16);
s16 func_80027FA4_28BA4(s32, void*, u8);
void func_8002741C_2801C(void);
void func_8003847C_3907C(HmfData*, char*, HmfData*);
s16 func_80038398_38F98(HmfData*, s32);
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
    Mtx perspMtx;
    Mtx lookAtMtx;
} HuCamMtxs;

typedef struct {
    /* 0x00 */ s8 unk00;
    /* 0x01 */ s8 unk01;
    /* 0x02 */ s8 unk02;
    /* 0x03 */ s8 unk03;
    /* 0x04 */ s8 unk04;
    /* 0x05 */ s8 unk05;
    /* 0x06 */ s8 unk06;
    /* 0x07 */ char unk07[1];
    /* 0x08 */ Light unk08[1]; // length unknown
} HmfData_UnkD0;

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
    /* 0x40 */ Light unk40[3][8][8];
} UnkLightData; // Size 0xC40

extern HuCamMtxs *D_800FC88C_FD48C;
extern Light *D_800F8424_F9024;
extern UnkLightData *D_800FA620_FB220;
extern u8 D_800FDBE0_FE7E0;

f32 func_800B1830_B2430(f32);

INCLUDE_ASM("asm/nonmatchings/274D0", func_800268D0_274D0);

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

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002741C_2801C);

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

INCLUDE_ASM("asm/nonmatchings/274D0", func_800275C4_281C4);

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

INCLUDE_ASM("asm/nonmatchings/274D0", Hu3DModelCreate);

INCLUDE_ASM("asm/nonmatchings/274D0", func_80027D3C_2893C);

INCLUDE_ASM("asm/nonmatchings/274D0", func_80027FA4_28BA4);

s16 func_800282D4_28ED4(s16 arg0, s8 arg1) {
    s16 temp_v0 = func_80027D3C_2893C(arg0);

    if (temp_v0 < 0) {
        return -1;
    }
    D_800FC834_FD434[temp_v0].unk00 = arg1;
    return temp_v0;
}

INCLUDE_ASM("asm/nonmatchings/274D0", func_80028334_28F34);

s16 func_8002838C_28F8C(s32 arg0, void (*arg1)(Gfx **, s32, s32), u8 arg2) {
    s16 idx = func_80027FA4_28BA4(arg0, NULL, arg2);
    HmfModel *var_v1 = &D_800FC834_FD434[idx];

    var_v1->unk70 = arg1;
    return idx;
}

INCLUDE_ASM("asm/nonmatchings/274D0", func_800283DC_28FDC);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002864C_2924C);

INCLUDE_ASM("asm/nonmatchings/274D0", func_800286FC_292FC);

extern u16 D_800F8710_F9310[];
extern u16 D_800FCA00_FD600[][HU3D_MODEL_MAX];
extern s16 D_800F9564_FA164;
extern u8 D_800FA5D8_FB1D8;
extern Gfx* D_800FDBCC_FE7CC; /* gMainGfxPos */
extern s32 D_800FD2A8_FDEA8;
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
            temp_s0->unk70(&D_800FDBCC_FE7CC, (s32)D_800FC88C_FD48C, D_800FD2A8_FDEA8);
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

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029708_2A308);

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

void func_80029988_2A588(s16 idx, s32 arg1, s32 arg2, s32 arg3) {
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

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029A8C_2A68C);

void func_80029AFC_2A6FC(s16 arg0) {
    HmfData* model = D_800FC834_FD434[arg0].hmf;

    if (model->unk0A != 0) {
        func_800273A8_27FA8(model->unk0E);
    } else {
        func_80027274_27E74(D_800FC834_FD434[arg0].hmf->unk0E);
    }
}

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029B80_2A780);

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

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029C74_2A874);

f32 func_80029CE4_2A8E4(s16 arg0) {
    return D_800FC834_FD434[arg0].unk40;
}

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029D0C_2A90C);

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029D5C_2A95C);

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029DA4_2A9A4);

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029E14_2AA14);

f32 func_80029E3C_2AA3C(s16 idx) {
    if (D_800FC834_FD434[idx].unk04 == 0xFF) {
        return -1.0f;
    }
    return D_800FC834_FD434[idx].unk4C;
}

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029E80_2AA80);

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029EDC_2AADC);

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029F04_2AB04);

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

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029FE4_2ABE4);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002A00C_2AC0C);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002A15C_2AD5C);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002A3EC_2AFEC);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002A4E0_2B0E0);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002A5D4_2B1D4);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002A9E8_2B5E8);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002A9F4_2B5F4);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002AC10_2B810);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002ACF0_2B8F0);

extern f32 D_800D2210_D2E10[];
extern f32 D_800CA02C_CAC2C;
f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32);
void func_8002CD78_2D978(s16, u8, u8, u8, u8);
void func_8002CDB4_2D9B4(s16, u8, u8, u8, u8);

void func_8002AF2C_2BB2C(HmfData* arg0, f32 arg1, f32 arg2, u16 arg3, u16 arg4) {
    HmfVtxGroup* b = &arg0->unkB4[arg3];
    f32 inv = 1.0f - arg1;
    HmfVertex* src;
    HmfVertex* dst;
    s16* idx;
    s16 cx, cy, cz;
    s16 sx, sy, sz;
    s16 n;
    s16 j;
    s16 i;

    for (i = 0; i < arg4; i++) {
        cx = b->unk_0C;
        cy = b->unk_10;
        cz = b->unk_14;
        sx = cx * arg2;
        sy = cy * arg2;
        sz = cz * arg2;
        n = (u8)(b->unk_00 & 0x7F);
        idx = b->unk_02;
        for (j = 0; j < n; j++) {
            src = &arg0->unk40[*idx];
            dst = &arg0->unk44[D_800FDBE0_FE7E0][*idx];
            dst->unk_00 = (src->unk_00 - cx) * inv + sx;
            dst->unk_02 = (src->unk_02 - cy) * inv + sy;
            dst->unk_04 = (src->unk_04 - cz) * inv + sz;
            idx++;
        }
        b++;
    }
}

void func_8002B184_2BD84(HmfData* arg0, f32 arg1, f32 arg2, u16 arg3, u16 arg4) {
    unk24740Floats8 sp0 = *(unk24740Floats8*)D_800D2210_D2E10;
    HmfVtxGroup* b = &arg0->unkB4[arg3];
    f32 inv = 1.0f - arg1;
    HmfVertex* src;
    HmfVertex* dst;
    s16* idx;
    s16 cx, cy, cz;
    s16 sx, sy, sz;
    s16 n;
    s16 j;
    s16 i;

    for (i = 0; i < arg4; i++) {
        cx = b->unk_0C;
        cy = b->unk_10;
        cz = b->unk_14;
        if (arg2 == 1.0f) {
            sx = cx * arg2;
            sy = cy * arg2;
            sz = cz * arg2;
        } else {
            sx = cx * arg2 * sp0.v[i & 7];
            sy = cy * arg2 * sp0.v[i & 7];
            sz = cz * arg2 * sp0.v[i & 7];
        }
        n = (u8)(b->unk_00 & 0x7F);
        idx = b->unk_02;
        for (j = 0; j < n; j++) {
            src = &arg0->unk40[*idx];
            dst = &arg0->unk44[D_800FDBE0_FE7E0][*idx];
            dst->unk_00 = (src->unk_00 - cx) * inv + sx;
            dst->unk_02 = (src->unk_02 - cy) * inv + sy;
            dst->unk_04 = (src->unk_04 - cz) * inv + sz;
            idx++;
        }
        b++;
    }
}

void func_8002B4C4_2C0C4(HmfData* arg0, f32 arg1, f32 arg2, u16 arg3, u16 arg4) {
    unk24740Floats8 sp10 = *(unk24740Floats8*)D_800D2210_D2E10;
    HmfVtxGroup* b = &arg0->unkB4[arg3];
    f32 inv = 1.0f - arg1;
    f32 s = HuMathSin(D_800CA02C_CAC2C);
    f32 c = func_800B7890_B8490(D_800CA02C_CAC2C);
    HmfVertex* src;
    HmfVertex* dst;
    s16* idx;
    s16 cx, cy, cz;
    s16 sx, sy, sz;
    f32 dx, dy, dz;
    s16 n;
    s16 j;
    s16 i;

    for (i = 0; i < arg4; i++) {
        cx = b->unk_0C;
        cy = b->unk_10;
        cz = b->unk_14;
        if (arg2 == 1.0f) {
            sx = cx * arg2;
            sy = cy * arg2;
            sz = cz * arg2;
        } else {
            sx = cx * arg2 * sp10.v[i & 7];
            sy = cy * arg2 * sp10.v[i & 7];
            sz = cz * arg2 * sp10.v[i & 7];
        }
        n = (u8)(b->unk_00 & 0x7F);
        idx = b->unk_02;
        switch (i & 3) {
            case 0:
            case 2:
                for (j = 0; j < n; j++) {
                    src = &arg0->unk40[*idx];
                    dst = &arg0->unk44[D_800FDBE0_FE7E0][*idx];
                    dx = src->unk_00 - cx;
                    dy = src->unk_02 - cy;
                    dz = src->unk_04 - cz;
                    dst->unk_00 = dx * inv + sx;
                    dst->unk_02 = (dy * c + dz * s) * inv + sy;
                    dst->unk_04 = (-dy * s + dz * c) * inv + sz;
                    idx++;
                }
                break;
            case 1:
                for (j = 0; j < n; j++) {
                    src = &arg0->unk40[*idx];
                    dst = &arg0->unk44[D_800FDBE0_FE7E0][*idx];
                    dx = src->unk_00 - cx;
                    dy = src->unk_02 - cy;
                    dz = src->unk_04 - cz;
                    dst->unk_00 = (dx * c - dz * s) * inv + sx;
                    dst->unk_02 = dy * inv + sy;
                    dst->unk_04 = (dx * s + dz * c) * inv + sz;
                    idx++;
                }
                break;
            case 3:
                for (j = 0; j < n; j++) {
                    src = &arg0->unk40[*idx];
                    dst = &arg0->unk44[D_800FDBE0_FE7E0][*idx];
                    dx = src->unk_00 - cx;
                    dy = src->unk_02 - cy;
                    dz = src->unk_04 - cz;
                    dst->unk_00 = (dx * c + dy * s) * inv + sx;
                    dst->unk_02 = (-dx * s + dy * c) * inv + sy;
                    dst->unk_04 = dz * inv + sz;
                    idx++;
                }
                break;
        }
        b++;
    }
}

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002BB4C_2C74C);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002BCA8_2C8A8);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002BED4_2CAD4);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002C20C_2CE0C);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002C3A0_2CFA0);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002C524_2D124);

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

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002C5D8_2D1D8);

void func_8002C5E4_2D1E4(s16 arg0, s16 arg1) {
    D_800FC834_FD434[arg0].hmf = D_800FC834_FD434[arg1].hmf;
}

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002C628_2D228);

void func_8002C6A8_2D2A8(s16 arg0) {
    HmfData* model = D_800FC834_FD434[arg0].hmf;

    model->unkA0 = func_8003CF84_3DB84(model);
}

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002C6F4_2D2F4);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002C810_2D410);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002C8B8_2D4B8);

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

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002CA14_2D614);

void func_8002CA48_2D648(u8 arg0, u8 arg1, u8 arg2) {
    D_800C9B70_CA770 = arg0;
    D_800C9B71_CA771 = arg1;
    D_800C9B72_CA772 = arg2;
}

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002CA64_2D664);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002CB0C_2D70C);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002CB78_2D778);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002CD24_2D924);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002CD6C_2D96C);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002CD78_2D978);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002CDB4_2D9B4);

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
    HmfMaterial* temp_v1;
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
