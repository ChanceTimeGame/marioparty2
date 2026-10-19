#include "common.h"

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

void* func_80027138_27D38(s32 size) {
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

void func_800271D8_27DD8(void* arg0) {
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

INCLUDE_ASM("asm/nonmatchings/274D0", func_800277B0_283B0);

INCLUDE_ASM("asm/nonmatchings/274D0", Hu3DModelCreate);

INCLUDE_ASM("asm/nonmatchings/274D0", func_80027D3C_2893C);

INCLUDE_ASM("asm/nonmatchings/274D0", func_80027FA4_28BA4);

INCLUDE_ASM("asm/nonmatchings/274D0", func_800282D4_28ED4);

INCLUDE_ASM("asm/nonmatchings/274D0", func_80028334_28F34);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002838C_28F8C);

INCLUDE_ASM("asm/nonmatchings/274D0", func_800283DC_28FDC);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002864C_2924C);

INCLUDE_ASM("asm/nonmatchings/274D0", func_800286FC_292FC);

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029368_29F68);

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029558_2A158);

INCLUDE_ASM("asm/nonmatchings/274D0", func_800295D4_2A1D4);

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029708_2A308);

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029714_2A314);

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029760_2A360);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002979C_2A39C);

INCLUDE_ASM("asm/nonmatchings/274D0", func_800297E8_2A3E8);

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029834_2A434);

INCLUDE_ASM("asm/nonmatchings/274D0", func_800298A4_2A4A4);

INCLUDE_ASM("asm/nonmatchings/274D0", HmfModelObjAttrSet);

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029988_2A588);

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029A34_2A634);

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029A8C_2A68C);

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029AFC_2A6FC);

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029B80_2A780);

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029BF0_2A7F0);

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029C74_2A874);

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029CE4_2A8E4);

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029D0C_2A90C);

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029D5C_2A95C);

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029DA4_2A9A4);

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029E14_2AA14);

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029E3C_2AA3C);

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029E80_2AA80);

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029EDC_2AADC);

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029F04_2AB04);

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029F2C_2AB2C);

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029F94_2AB94);

INCLUDE_ASM("asm/nonmatchings/274D0", func_80029FBC_2ABBC);

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

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002AF2C_2BB2C);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002B184_2BD84);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002B4C4_2C0C4);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002BB4C_2C74C);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002BCA8_2C8A8);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002BED4_2CAD4);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002C20C_2CE0C);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002C3A0_2CFA0);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002C524_2D124);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002C570_2D170);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002C59C_2D19C);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002C5D8_2D1D8);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002C5E4_2D1E4);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002C628_2D228);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002C6A8_2D2A8);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002C6F4_2D2F4);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002C810_2D410);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002C8B8_2D4B8);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002C9C0_2D5C0);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002CA14_2D614);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002CA48_2D648);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002CA64_2D664);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002CB0C_2D70C);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002CB78_2D778);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002CD24_2D924);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002CD6C_2D96C);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002CD78_2D978);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002CDB4_2D9B4);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002CDF0_2D9F0);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002D018_2DC18);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002D030_2DC30);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002D0A0_2DCA0);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002D124_2DD24);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002D1EC_2DDEC);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002D274_2DE74);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002D2B4_2DEB4);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002D3C0_2DFC0);

INCLUDE_ASM("asm/nonmatchings/274D0", func_8002D4A0_2E0A0);
