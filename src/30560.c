#include "common.h"
#include "game/hmfman.h"

/* Model (HMF) setup, texture and display-list state, matrix copies and animation helpers. The
   functions in C are MP1 src/2C0C0.c and src/34D80.c code (two from MP3 src/22EB0.c); the rest
   have no MP1/MP3 C and stay asm, as do func_8003076C and func_80038C04, whose string and jump
   table sit in this unit's piece of the data blob next to rodata of functions still in asm.
   MP2's model structs have MP3's layout; fields are named by their MP2 offset. */

typedef f32 Matrix4f[4][4];

#define INTEGER_LOG2(x) ((x) <= 2 ? 1 : (x) <= 4 ? 2 : (x) <= 8 ? 3 : (x) <= 16 ? 4 : (x) <= 32 ? 5 : (x) <= 64 ? 6 : (x) <= 128 ? 7 : 8)

/* MP1 unk2C0C0StructE0 */

/* MP1 unk2C0C0StructB0 */

/* MP1 unk2C0C0Struct60 (4 bytes longer at the start in MP2) */

/* MP1 unk2C0C0Struct70 (4 bytes longer at the start in MP2) */

/* MP1 unk2C0C0Struct90 */

/* MP1 unk34D80Struct80 */
typedef struct HmfMotion {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ char unk_01;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ void** unk_04;
    /* 0x08 */ u8* unk_08;
    /* 0x0C */ s16* unk_0C;
    /* 0x10 */ f32* unk_10;
    /* 0x14 */ char unk_14[4];
} HmfMotion; /* size = 0x18 */

/* MP1 unk2C0C0StructB4 */

/* MP1 unk2C0C0StructB8 */

/* MP3 HmfModelData_Unk64_Unk3C_Struct */

/* MP3 HmfModelData_Unk64_Unk60_Struct */

/* MP3 HmfData / MP1 unk2C0C0StructC0 (fields used here; MP1 offsets in the comments) */

/* MP1 unk2C0C0Struct10 */
typedef struct HmfLight {
    /* 0x00 */ Hilite unk_00;
    /* 0x10 */ char unk_10[0x30];
    /* 0x40 */ LookAt unk_40;
} HmfLight; /* size = 0x60 */

extern s16 D_800CA028_CAC28;
extern Gfx D_800CA030_CAC30[];
extern s16 D_800CA090_CAC90[];
extern s32 D_800CA098_CAC98[];
extern s16 D_800CAD20_CB920;
extern u32 D_800F60A4_F6CA4;
extern u8 D_800F8C48_F9848;
extern s16 D_800F8C54_F9854;
extern s16 D_800F8D24_F9924;
extern s16 D_800F9050_F9C50;
extern s16 D_800F928C_F9E8C;
extern u32 D_800F92E0_F9EE0;
extern void* D_800F93D8_F9FD8[];
extern u8 D_800F94C0_FA0C0;
extern u32 D_800F956C_FA16C;
extern u8 D_800F9D2C_FA92C;
extern s16 D_800FA1AA_FADAA;
extern u8 D_800FA5D8_FB1D8;
extern u8 D_800FA60C_FB20C;
extern s16 D_800FA61C_FB21C;
extern HmfLight* D_800FA658_FB258;
extern u8 D_800FC9E9_FD5E9;
extern s16 D_800FCE00_FDA00;
extern s16 D_800FD470_FE070;
extern HmfLight D_800FD4F0_FE0F0[];
extern u8 D_800FD800_FE400;
extern Gfx* D_800FD810_FE410[];
extern void* D_800FD83C_FE43C;
extern s32 D_800FD84C_FE44C;
extern s16 D_800FD8BA_FE4BA;
extern u8 D_800FDBCA_FE7CA;
extern Gfx* D_800FDBCC_FE7CC;
extern Gfx* D_800FDBD0_FE7D0;
extern u32 D_800FDBD4_FE7D4;
extern u8 D_800FDBE0_FE7E0;
extern u8 D_800FDC84_FE884;
extern s32 D_800FDC98_FE898;
extern u8 D_800FDEA0_FEAA0;
extern s16 D_800FFDFA_1009FA;
extern u8 D_8010002C_100C2C;
extern s16 D_8010106C_101C6C;
extern HmfVtx* D_80101170_101D70;
extern Matrix4f D_801016D0_1022D0[];
extern u32 D_801026D0_1032D0;
extern s16 D_80102718_103318;
extern s16 D_80102722_103322;
extern HmfVtx* D_80102728_103328[];
extern s16 D_801027FA_1033FA;

void func_8002024C_20E4C();
void func_800260A4_26CA4(s32, s32);
void func_80026994_27594(s32);
void* func_80027154_27D54(s32, s16);
void HuMemFree(void*);
void func_80027340_27F40(void*);
void func_800274A4_280A4(void);
void func_8002FD38_30938(HmfData*);
void func_80030CD4_318D4(Matrix4f, Matrix4f);
void func_80031FD8_32BD8(HmfData*, s16, void*, Matrix4f);
void func_80036D5C_3795C(HmfData*, s16);
void func_80037C7C_3887C(HmfData*, s16);
void func_8003811C_38D1C(HmfData*, s32, s16);
s16 func_80038398_38F98(HmfData*, char*);
void func_800384C8_390C8(HmfData*, s16, HmfData*);
s16 func_80038E38_39A38(u8*, HmfData*);
void func_800B30D0_B3CD0(Matrix4f, void*);

INCLUDE_ASM("asm/nonmatchings/30560", func_8002F960_30560);

/* exact c: marioparty func_8002B6C8 (src/2C0C0.c) */
void func_8002FB6C_3076C(void) {
    func_800274A4_280A4();

    if (D_800FDCD0_FE8D0 != 0) {
        s32 temp_v0 = D_800FDBE0_FE7E0;

        D_80101170_101D70 = D_80102728_103328[temp_v0];
        D_800FD83C_FE43C = D_800F93D8_F9FD8[temp_v0];
        D_800FDBD0_FE7D0 = D_800FDBCC_FE7CC = D_800FD810_FE410[temp_v0];
        D_800FA658_FB258 = &D_800FD4F0_FE0F0[temp_v0];

        if (++D_800FDBE0_FE7E0 >= D_800FDBCA_FE7CA) {
            D_800FDBE0_FE7E0 = 0;
        }

        func_80026994_27594(temp_v0);

        D_800FA61C_FB21C = 0;
        D_800F928C_F9E8C = 0;
        D_800FD8BA_FE4BA = 0;
        D_80102722_103322 = 0;
        D_800FA5D8_FB1D8 = 0;
        D_800FCE00_FDA00 = 0;
        D_80102718_103318 = 0;
        D_800F8D24_F9924 = 0;
        D_800FFDFA_1009FA = 0;
        D_800F9050_F9C50 = 0;

        func_8002024C_20E4C();

        D_800FDC98_FE898++;
    }
}

INCLUDE_ASM("asm/nonmatchings/30560", func_8002FCAC_308AC);

INCLUDE_ASM("asm/nonmatchings/30560", func_8002FD38_30938);

INCLUDE_ASM("asm/nonmatchings/30560", func_8003057C_3117C);

/* same c: marioparty func_8002BDC0 (src/2C0C0.c) */
void func_80030668_31268(HmfData* arg0) {
    HmfFace* var_a3;
    f32 var_f4;
    f32 var_f6;
    f32 var_f8;
    s16* var_a1;
    u16 temp_t2;
    s16 i;
    s16 j;

    if (arg0->unkB4 == NULL) {
        return;
    }

    var_a3 = arg0->unkB4;
    for (i = 0; i < arg0->unk1A; i++, var_a3++) {
        var_a1 = var_a3->unk02;
        temp_t2 = var_a3->unk00;

        var_f6 = var_f8 = var_f4 = 0.0f;
        for (j = 0; j < temp_t2; j++, var_a1++) {
            var_f6 += arg0->unk40[*var_a1].unk00;
            var_f8 += arg0->unk40[*var_a1].unk02;
            var_f4 += arg0->unk40[*var_a1].unk04;
        }

        var_a3->unk0C = var_f6 / temp_t2;
        var_a3->unk10 = var_f8 / temp_t2;
        var_a3->unk14 = var_f4 / temp_t2;
    }
}

INCLUDE_ASM("asm/nonmatchings/30560", func_8003076C_3136C);

/* same c: marioparty3 func_80023264_23E64 (src/22EB0.c) */
s32 func_800308D8_314D8(HmfData *arg0) {
    s32 var_s2;
    s16 i;

    var_s2 = 0;
    if (arg0->unk40 != NULL) {
        for (i = 0; i < ARRAY_COUNT(arg0->unk44); i++) {
            if (arg0->unk40 != arg0->unk44[i]) {
                if (arg0->unk0A != 0) {
                    func_80027340_27F40(arg0->unk44[i]);
                } else {
                    HuMemFree(arg0->unk44[i]);
                }
                arg0->unk44[i] = arg0->unk40;
                var_s2 = 1;
            }
        }

        if (arg0->unk0A != 0) {
            func_80027340_27F40(arg0->unk40);
        } else {
            HuMemFree(arg0->unk40);
        }
    }
    if (arg0->unk3C != NULL) {
        for (i = 0; i < arg0->unk10; i++) {
            if (arg0->unk0A != 0) {
                func_80027340_27F40(arg0->unk3C->unk00[i]);
            } else {
                HuMemFree(arg0->unk3C->unk00[i]);
            }
        }

        if (arg0->unk0A != 0) {
            func_80027340_27F40(arg0->unk3C);
        } else {
            HuMemFree(arg0->unk3C);
        }
    }
    D_8010106C_101C6C = arg0->unk0E;
    D_800FA1AA_FADAA = arg0->unk0E + 1;
    func_8002FD38_30938(arg0);
    return var_s2;
}

INCLUDE_ASM("asm/nonmatchings/30560", func_80030A78_31678);

/* exact c: marioparty func_8002C37C (src/2C0C0.c) */
void func_80030CD4_318D4(Matrix4f arg0, Matrix4f arg1) {
    arg0[0][0] = arg1[0][0];
    arg0[0][1] = arg1[0][1];
    arg0[0][2] = arg1[0][2];
    arg0[0][3] = arg1[0][3];
    arg0[1][0] = arg1[1][0];
    arg0[1][1] = arg1[1][1];
    arg0[1][2] = arg1[1][2];
    arg0[1][3] = arg1[1][3];
    arg0[2][0] = arg1[2][0];
    arg0[2][1] = arg1[2][1];
    arg0[2][2] = arg1[2][2];
    arg0[2][3] = arg1[2][3];
    arg0[3][0] = arg1[3][0];
    arg0[3][1] = arg1[3][1];
    arg0[3][2] = arg1[3][2];
    arg0[3][3] = arg1[3][3];
}

INCLUDE_ASM("asm/nonmatchings/30560", func_80030D58_31958);

INCLUDE_ASM("asm/nonmatchings/30560", func_80031170_31D70);

INCLUDE_ASM("asm/nonmatchings/30560", func_800316F0_322F0);

INCLUDE_ASM("asm/nonmatchings/30560", func_800319EC_325EC);

/* exact c: marioparty func_8002D270 (src/2C0C0.c) */
void func_80031F7C_32B7C(HmfData* arg0, s16 arg1, void* arg2) {
    Matrix4f sp10;

    func_800B30D0_B3CD0(sp10, arg2);
    func_80031FD8_32BD8(arg0, arg1, arg2, sp10);
}

INCLUDE_ASM("asm/nonmatchings/30560", func_80031FD8_32BD8);

INCLUDE_ASM("asm/nonmatchings/30560", func_800322BC_32EBC);

INCLUDE_ASM("asm/nonmatchings/30560", func_800329E8_335E8);

INCLUDE_ASM("asm/nonmatchings/30560", func_80033288_33E88);

INCLUDE_ASM("asm/nonmatchings/30560", func_80035C18_36818);

INCLUDE_ASM("asm/nonmatchings/30560", func_80035FBC_36BBC);

/* exact c: marioparty func_800318D0 (src/2C0C0.c) */
void func_800368B4_374B4(u16 arg0) {
    u8 temp_v1;

    temp_v1 = (arg0 >> 7) & 3;
    if (temp_v1 != D_800FD800_FE400) {
        D_800FD800_FE400 = temp_v1;
        gDPSetTextureFilter(D_800FDBCC_FE7CC++, G_TF_POINT | D_800CA090_CAC90[temp_v1]);
    }

    if (D_800FDC84_FE884 != D_800FDEA0_FEAA0) {
        D_800FDEA0_FEAA0 = D_800FDC84_FE884;
        if (D_800FDC84_FE884 == 0) {
            gSPSetGeometryMode(D_800FDBCC_FE7CC++, G_SHADING_SMOOTH);
        } else {
            gSPClearGeometryMode(D_800FDBCC_FE7CC++, G_SHADING_SMOOTH);
        }
    }

    temp_v1 = (arg0 >> 9) & 3;
    if (temp_v1 != D_800F94C0_FA0C0) {
        D_800F94C0_FA0C0 = temp_v1;
        switch (temp_v1) {
            case 0:
                gDPSetColorDither(D_800FDBCC_FE7CC++, G_CD_DISABLE);
                break;
            case 1:
                gDPSetColorDither(D_800FDBCC_FE7CC++, G_CD_NOISE);
                break;
            case 2:
                gDPSetColorDither(D_800FDBCC_FE7CC++, G_CD_BAYER);
                break;
            case 3:
                gDPSetColorDither(D_800FDBCC_FE7CC++, G_CD_MAGICSQ);
                break;
            }
    }

    if (D_800FA60C_FB20C != 0) {
        gSPFogFactor(D_800FDBCC_FE7CC++, 500 * 256 / (D_800F8C54_F9854 - D_801027FA_1033FA), (500 - D_801027FA_1033FA) * 256 / (D_800F8C54_F9854 - D_801027FA_1033FA));
        gDPSetFogColor(D_800FDBCC_FE7CC++, D_800FC9E9_FD5E9, D_8010002C_100C2C, D_800F9D2C_FA92C, 255);
    }
}

/* exact c: marioparty func_80031BB4 (src/2C0C0.c) */
void func_80036B98_37798(void) {
    gMoveWd(D_800FDBCC_FE7CC++, G_MW_CLIP, G_MWO_CLIP_RNX, *(D_800F8C48_F9848 * 2 + &D_800CA098_CAC98[0]));
    gMoveWd(D_800FDBCC_FE7CC++, G_MW_CLIP, G_MWO_CLIP_RNY, *(D_800F8C48_F9848 * 2 + &D_800CA098_CAC98[0]));
    gMoveWd(D_800FDBCC_FE7CC++, G_MW_CLIP, G_MWO_CLIP_RPX, *(D_800F8C48_F9848 * 2 + &D_800CA098_CAC98[1]));
    gMoveWd(D_800FDBCC_FE7CC++, G_MW_CLIP, G_MWO_CLIP_RPY, *(D_800F8C48_F9848 * 2 + &D_800CA098_CAC98[1]));
}

/* exact c: marioparty func_80031C60 (src/2C0C0.c) */
void func_80036C44_37844(HmfData* arg0, s32 arg1, s16 arg2) {
    if (D_800FD84C_FE44C != arg1 || arg1 & 0x0E000000) {
        D_800FD84C_FE44C = arg1;

        gSPDisplayList(D_800FDBCC_FE7CC++, D_800CA030_CAC30);

        if (arg1 & 0x2000) {
            gSPSetGeometryMode(D_800FDBCC_FE7CC++, G_CULL_BACK);
        }

        if (D_800FA60C_FB20C != 0) {
            gDPSetCycleType(D_800FDBCC_FE7CC++, G_CYC_2CYCLE);
            gSPSetGeometryMode(D_800FDBCC_FE7CC++, G_FOG);
        }

        if (arg1 & 0x06000000) {
            func_80037C7C_3887C(arg0, arg2);
        } else if (arg1 & 0x08000000) {
            func_80036D5C_3795C(arg0, arg2);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/30560", func_80036D5C_3795C);

/* same c: marioparty func_80031F14 (src/2C0C0.c) */
void func_80036EF8_37AF8(HmfTex* arg0, s32 arg1, s32 arg2) {
    if (arg0->unk1C != 2) {
        gDPSetTextureLUT(D_800FDBCC_FE7CC++, G_TT_NONE);

        switch (arg0->unk1D) {
            case G_IM_SIZ_16b:
                D_800F92E0_F9EE0 = G_IM_SIZ_16b_LOAD_BLOCK;
                D_800F956C_FA16C = G_IM_SIZ_16b_INCR;
                D_801026D0_1032D0 = G_IM_SIZ_16b_BYTES;
                D_800F60A4_F6CA4 = G_IM_SIZ_16b_LINE_BYTES;
                D_800FDBD4_FE7D4 = G_IM_SIZ_16b_SHIFT;
                break;
            case G_IM_SIZ_8b:
                D_800F92E0_F9EE0 = G_IM_SIZ_8b_LOAD_BLOCK;
                D_800F956C_FA16C = G_IM_SIZ_8b_INCR;
                D_801026D0_1032D0 = G_IM_SIZ_8b_BYTES;
                D_800F60A4_F6CA4 = G_IM_SIZ_8b_LINE_BYTES;
                D_800FDBD4_FE7D4 = G_IM_SIZ_8b_SHIFT;
                break;
            case G_IM_SIZ_4b:
                D_800F92E0_F9EE0 = G_IM_SIZ_4b_LOAD_BLOCK;
                D_800F956C_FA16C = G_IM_SIZ_4b_INCR;
                D_801026D0_1032D0 = G_IM_SIZ_4b_BYTES;
                D_800F60A4_F6CA4 = G_IM_SIZ_4b_LINE_BYTES;
                D_800FDBD4_FE7D4 = G_IM_SIZ_4b_SHIFT;
                break;
            default:
                D_800F92E0_F9EE0 = G_IM_SIZ_32b_LOAD_BLOCK;
                D_800F956C_FA16C = G_IM_SIZ_32b_INCR;
                D_801026D0_1032D0 = G_IM_SIZ_32b_BYTES;
                D_800F60A4_F6CA4 = G_IM_SIZ_32b_LINE_BYTES;
                D_800FDBD4_FE7D4 = G_IM_SIZ_32b_SHIFT;
                break;
        }

        gDPSetTextureImage(D_800FDBCC_FE7CC++, arg0->unk1C, D_800F92E0_F9EE0, 1, arg0->unk28);
        gDPSetTile(D_800FDBCC_FE7CC++, arg0->unk1C, D_800F92E0_F9EE0, 0, 0x0000, G_TX_LOADTILE, 0,
            arg2, INTEGER_LOG2(arg0->unk1F), G_TX_NOLOD, arg1, INTEGER_LOG2(arg0->unk1E), G_TX_NOLOD);
        gDPLoadSync(D_800FDBCC_FE7CC++);
        gDPLoadBlock(D_800FDBCC_FE7CC++, G_TX_LOADTILE, 0, 0,
            ((arg0->unk1E * arg0->unk1F + D_800F956C_FA16C) >> D_800FDBD4_FE7D4) - 1,
            CALC_DXT(arg0->unk1E, D_801026D0_1032D0));
        gDPPipeSync(D_800FDBCC_FE7CC++);
        gDPSetTile(D_800FDBCC_FE7CC++, arg0->unk1C, arg0->unk1D, (arg0->unk1E * D_800F60A4_F6CA4 + 7) >> 3, 0x0000, G_TX_RENDERTILE, 0,
            arg2, INTEGER_LOG2(arg0->unk1F), G_TX_NOLOD, arg1, INTEGER_LOG2(arg0->unk1E), G_TX_NOLOD);
        gDPSetTileSize(D_800FDBCC_FE7CC++, G_TX_RENDERTILE, 0, 0, (arg0->unk1E - 1) * 4, (arg0->unk1F - 1) * 4);
    } else {
        gDPSetTextureLUT(D_800FDBCC_FE7CC++, G_TT_RGBA16);

        if (arg0->unk30->unk1E < 17) {
            gDPLoadTLUT_pal16(D_800FDBCC_FE7CC++, 0, arg0->unk30->unk28);
            gDPLoadTextureBlock_4b(D_800FDBCC_FE7CC++, arg0->unk28, arg0->unk1C, arg0->unk1E, arg0->unk1F, 0,
                arg1, arg2, INTEGER_LOG2(arg0->unk1E), INTEGER_LOG2(arg0->unk1F), 0, 0);
        } else {
            gDPLoadTLUT_pal256(D_800FDBCC_FE7CC++, arg0->unk30->unk28);
            gDPLoadTextureBlockYuv(D_800FDBCC_FE7CC++, arg0->unk28, arg0->unk1C, G_IM_SIZ_8b, arg0->unk1E, arg0->unk1F, 0,
                arg1, arg2, INTEGER_LOG2(arg0->unk1E), INTEGER_LOG2(arg0->unk1F), 0, 0);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/30560", func_80037C7C_3887C);

/* same c: marioparty3 func_8002C4C0_2D0C0 (src/22EB0.c) */
s32 func_80038024_38C24(HmfData *arg0, s16 arg1, s32 arg2, s32 arg3) {
    if (!(arg0->unk64[arg1].unk50 & 0x70000000)) {
        return 0;
    }
    func_800260A4_26CA4(arg2, arg3);
    return 1;
}

/* same c: marioparty func_80033408 (src/2C0C0.c) */
void func_80038084_38C84(HmfData* arg0, s16 arg1, Matrix4f arg2) {
    D_800FD470_FE070 = 0;
    guMtxIdentF(D_801016D0_1022D0[0]);
    if (arg0->unk84 == (void*)-1 && arg0->unk68 != 0) {
        func_8003811C_38D1C(arg0, 0, arg1);
        func_80030CD4_318D4(arg2, D_801016D0_1022D0[D_800FD470_FE070]);
    }
}

INCLUDE_ASM("asm/nonmatchings/30560", func_8003811C_38D1C);

INCLUDE_ASM("asm/nonmatchings/30560", func_80038398_38F98);

/* exact c: marioparty func_800337E4 (src/2C0C0.c) */
void func_8003847C_3907C(HmfData* arg0, char* arg1, HmfData* arg2) {
    s16 idx;

    idx = func_80038398_38F98(arg0, arg1);
    if (idx != -1) {
        func_800384C8_390C8(arg0, idx, arg2);
    }
}

INCLUDE_ASM("asm/nonmatchings/30560", func_800384C8_390C8);

INCLUDE_ASM("asm/nonmatchings/30560", func_80038654_39254);

INCLUDE_ASM("asm/nonmatchings/30560", func_800386DC_392DC);

INCLUDE_ASM("asm/nonmatchings/30560", func_80038964_39564);

INCLUDE_ASM("asm/nonmatchings/30560", func_80038C04_39804);

INCLUDE_ASM("asm/nonmatchings/30560", func_80038DD0_399D0);

INCLUDE_ASM("asm/nonmatchings/30560", func_80038E38_39A38);

/* exact c: marioparty func_800342BC (src/34D80.c) */
s16 func_80038F0C_39B0C(u8* arg0) {
    return func_80038E38_39A38(arg0, NULL);
}

INCLUDE_ASM("asm/nonmatchings/30560", func_80038F30_39B30);

INCLUDE_ASM("asm/nonmatchings/30560", func_80039018_39C18);

INCLUDE_ASM("asm/nonmatchings/30560", func_80039074_39C74);

INCLUDE_ASM("asm/nonmatchings/30560", func_80039110_39D10);

INCLUDE_ASM("asm/nonmatchings/30560", func_800395F8_3A1F8);

/* same c: marioparty func_80034C28 (src/34D80.c) */
s32 func_800398AC_3A4AC(HmfData* arg0, s16 arg1, u8* arg2) {
    HmfAnimTrack* temp_s3;
    s16 temp_s0;
    s16 var_a3;
    s16 i;

    temp_s3 = &arg0->unk9C->unk0C[arg1];

    temp_s3->unk04 = (arg2[0] << 8) + arg2[1];
    temp_s3->unk00 = (arg2[2] << 8) + arg2[3];

    arg0->unk8C[temp_s3->unk00].unk0C |= 5;

    temp_s0 = temp_s3->unk02 = (arg2[6] << 8) + arg2[7];
    temp_s3->unk08 = func_80027154_27D54(temp_s0 * sizeof(u16), arg0->unk0E + 1);
    temp_s3->unk0C = func_80027154_27D54(temp_s0 * sizeof(s32), arg0->unk0E + 1);

    arg2 += 8;

    for (var_a3 = i = 0; i < temp_s0; i++) {
        ((u8*) &temp_s3->unk0C[i])[0] = arg2[0];
        ((u8*) &temp_s3->unk0C[i])[1] = arg2[1];
        ((u8*) &temp_s3->unk0C[i])[2] = arg2[2];
        ((u8*) &temp_s3->unk0C[i])[3] = arg2[3];

        temp_s3->unk08[i] = (arg2[4] << 8) + arg2[5];
        var_a3 += temp_s3->unk08[i];

        arg2 += 6;
    }

    temp_s3->unk08[i - 1]++;
    temp_s3->unk06 = var_a3 + 1;

    return 1;
}

INCLUDE_ASM("asm/nonmatchings/30560", func_80039A88_3A688);

INCLUDE_ASM("asm/nonmatchings/30560", func_80039B54_3A754);

INCLUDE_ASM("asm/nonmatchings/30560", func_8003A154_3AD54);

INCLUDE_ASM("asm/nonmatchings/30560", func_8003A2B0_3AEB0);

INCLUDE_ASM("asm/nonmatchings/30560", func_8003A4B8_3B0B8);

INCLUDE_ASM("asm/nonmatchings/30560", func_8003AFF4_3BBF4);

/* same c: marioparty func_800368AC (src/34D80.c) */
void func_8003B4D8_3C0D8(HmfData* arg0, f32 arg1) {
    if (!(arg0->unk9C->unk02 & 1)) {
        arg0->unk9C->unk08 += arg1;
        if (arg0->unk9C->unk04 <= arg0->unk9C->unk08) {
            if (arg0->unk9C->unk02 & 2) {
                arg0->unk9C->unk08 = 0.0f;
            } else {
                arg0->unk9C->unk08 = arg0->unk9C->unk04;
            }
        }
    }
}

/* same c: marioparty func_80036930 (src/34D80.c) */
void func_8003B55C_3C15C(HmfData* arg0, f32 arg1) {
    arg0->unkA4 += arg1;
    if (((HmfMotion*)arg0->unk90)->unk_02 <= arg0->unkA4) {
        if (D_800CAD20_CB920 != 0) {
            arg0->unkA4 = 0.0f;
        } else {
            arg0->unkA4 = ((HmfMotion*)arg0->unk90)->unk_02;
        }
    }
}

/* same c: marioparty func_800369A0 (src/34D80.c) */
void func_8003B5CC_3C1CC(HmfData* arg0, f32 arg1) {
    arg0->unkA4 -= arg1;
    if (arg0->unkA4 < 0.0f) {
        if (D_800CAD20_CB920 != 0) {
            arg0->unkA4 = ((HmfMotion*)arg0->unk90)->unk_02;
        } else {
            arg0->unkA4 = 0.0f;
        }
    }
}

/* exact c: marioparty func_800369FC (src/34D80.c) */
f32 func_8003B628_3C228(HmfMotion* arg0, s16 arg1, f32 arg2, f32 arg3, f32 arg4) {
    arg4 *= D_800CA028_CAC28;
    if (!(arg1 & 9)) {
        if (!(arg1 & 4)) {
            arg2 += arg4;
            if (arg0->unk_02 <= arg2) {
                if (arg1 & 2) {
                    return arg3;
                }
                return arg0->unk_02;
            }
        } else {
            arg2 -= arg4;
            if (arg2 < arg3) {
                if (arg1 & 2) {
                    return arg0->unk_02 - arg4;
                }
                return arg3;
            }
        }
    }
    return arg2;
}

INCLUDE_ASM("asm/nonmatchings/30560", func_8003B6E8_3C2E8);

/* same c: marioparty func_80036AC4 (src/34D80.c) */
void func_8003B6F0_3C2F0(HmfData* arg0) {
    arg0->unkA4 = ((HmfMotion*)arg0->unk90)->unk_02 - 1;
}

/* same c: marioparty func_80036AE4 (src/34D80.c) */
s16 func_8003B710_3C310(HmfData* arg0) {
    return arg0->unkA4;
}

INCLUDE_ASM("asm/nonmatchings/30560", func_8003B72C_3C32C);

INCLUDE_ASM("asm/nonmatchings/30560", func_8003B76C_3C36C);

INCLUDE_ASM("asm/nonmatchings/30560", func_8003B7A8_3C3A8);

INCLUDE_ASM("asm/nonmatchings/30560", func_8003B9D0_3C5D0);

INCLUDE_ASM("asm/nonmatchings/30560", func_8003BA2C_3C62C);

INCLUDE_ASM("asm/nonmatchings/30560", func_8003BAD8_3C6D8);

INCLUDE_ASM("asm/nonmatchings/30560", func_8003BAF0_3C6F0);

INCLUDE_ASM("asm/nonmatchings/30560", func_8003BB58_3C758);

INCLUDE_ASM("asm/nonmatchings/30560", func_8003BCBC_3C8BC);

INCLUDE_ASM("asm/nonmatchings/30560", func_8003BD08_3C908);

INCLUDE_ASM("asm/nonmatchings/30560", func_8003C6AC_3D2AC);
