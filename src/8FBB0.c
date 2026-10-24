#include "common.h"

#include "game/malloc.h"
#include "game/data.h"

/* Screen fades and wipes (MP1 src/72D90.c, ovl_33 2341E0.c). MP1's names are anonymous (its
   SetFadeInTypeAndTime is MP2's InitFadeIn), so MP2's are kept. */

#ifndef SCREEN_WIDTH
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#endif
#ifndef VIRTUAL_TO_PHYSICAL
#define VIRTUAL_TO_PHYSICAL(addr) (u32)((u8*)(addr) - 0x80000000)
#endif

typedef struct unk72D90Struct0 {
    /* 0x00 */ Vtx* unk_00;
    /* 0x04 */ Gfx* unk_04;
} unk72D90Struct0; // size 8

typedef struct unk72D90Struct1 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ void* unk_04;
} unk72D90Struct1;

extern u8 D_800F92DC_F9EDC;    /* MP1 fadeStatus */
extern u8 D_800F8C56_F9856;    /* fade mode */
/* .data (0xCE850-0xCE910) */
u8 D_800CDC50_CE850 = 0;       /* fade type */
void* D_800CDC54_CE854 = NULL; /* captured frame buffer */
Gfx D_800CDC58_CE858[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPSetRenderMode(G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0xC0),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetAlphaDither(G_AD_DISABLE),
    gsSPEndDisplayList(),
};
s32 D_800CDCA8_CE8A8[4] = { -1, -1, -1, -1 };
Vp D_800CDCB8_CE8B8 = { { { 640, 480, G_MAXZ / 2, 0 }, { 640, 480, G_MAXZ / 2, 0 } } };
Gfx D_800CDCC8_CE8C8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_FILL),
    gsDPSetRenderMode(G_RM_NOOP, G_RM_NOOP2),
    gsDPSetFillColor(0x00000000),
    gsDPFillRectangle(0, 0, 319, 239),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPEndDisplayList(),
};
extern void* D_800F8418_F9018; /* current frame buffer */
extern f32 D_800FCE88_FDA88;   /* fade length */
extern f32 D_80101054_101C54;  /* fade time */
extern u8 D_800F9D20_FA920;    /* fade colour */
extern u8 D_800FC9E8_FD5E8;
extern u8 D_800FDEA1_FEAA1;
extern u8 D_8010116C_101D6C;
extern u8* D_80101638_102238;  /* 64-byte aligned frame buffer */
extern unk72D90Struct0* D_800F8FD8_F9BD8;
extern s16 D_800FFFD6_100BD6;
extern Mtx D_800FDDA0_FE9A0[];
extern Mtx D_80101400_102000[];
extern unk72D90Struct1 D_800FD834_FE434;
extern Gfx* D_800ED8F0_EE4F0;
extern u8* D_800ED8F4_EE4F4;
extern s8 D_800ED8F8_EE4F8;
extern Gfx* D_800ED8FC_EE4FC;
extern s16 D_800ED900_EE500;
extern s16 D_800ED902_EE502;

extern void guLookAt(Mtx*, f32, f32, f32, f32, f32, f32, f32, f32, f32);
extern void guPerspective(Mtx*, u16*, f32, f32, f32, f32, f32);
u32 osVirtualToPhysical(void*);
void func_80068DAC_699AC(void); /* MP1 GMesInit */
void func_8003F710_40310(Gfx**, void*, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void* HuMemAlloc(s32 size);
void* func_80027154_27D54(s32 size, s32 tag);
void func_80027340_27F40(void* data);
s16 func_8002838C_28F8C(s32, void*, s32);
void func_800283DC_28FDC(s16);
void func_8008F7F4_903F4(Gfx** arg0, u8 arg1, s32* arg2);
void func_8008FB34_90734(Gfx** arg0, u8* arg1);
void func_8008FD5C_9095C(Gfx** arg0, u8* arg1);
s32 func_8008FA5C_9065C(Gfx** arg0);
Gfx* func_80090000_90C00(Gfx* arg0, Vtx* arg1);
void* func_80091024_91C24(s32 arg0);
void func_8009110C_91D0C(Gfx** arg0, f32 arg1, f32 arg2);
void func_80092A24_93624(Gfx** arg0);
void func_80092A5C_9365C(Gfx** arg0);
void func_80068E64_69A64(Gfx** arg0); /* MP1 GMesCall */
void func_8008F624_90224(u8 arg0, u8 arg1, u8 arg2);
void func_800273A8_27FA8(s32);
void func_8008FD1C_9091C(Gfx** arg0);
s32 func_8008F640_90240(Gfx** arg0);
s32 func_8008F71C_9031C(Gfx** arg0);
s32 func_8008F8C8_904C8(Gfx** arg0);
s32 func_8008FF08_90B08(Gfx** arg0);
s32 func_8008FFE4_90BE4(Gfx** arg0);
s32 func_80090460_91060(Gfx** arg0);
s32 func_80090E84_91A84(Gfx** arg0);
s32 func_80090F40_91B40(Gfx** arg0);
s32 func_80091B20_92720(Gfx** arg0);
s32 func_80091BE0_927E0(Gfx** arg0);
s32 func_80091CB4_928B4(Gfx** arg0);
s32 func_80091DBC_929BC(Gfx** arg0);
s32 func_80091EC0_92AC0(Gfx** arg0);
s32 func_80091FC8_92BC8(Gfx** arg0);
s32 func_800920CC_92CCC(Gfx** arg0);
s32 func_800921D4_92DD4(Gfx** arg0);
s32 func_800922D8_92ED8(Gfx** arg0);
s32 func_80092398_92F98(Gfx** arg0);
s32 func_8009246C_9306C(Gfx** arg0);
s32 func_8009252C_9312C(Gfx** arg0);
s32 func_80092600_93200(Gfx** arg0, s32 arg1);
s32 func_8009270C_9330C(Gfx** arg0, s32 arg1);

void func_8008EFB0_8FBB0(void) {
    D_800F92DC_F9EDC = 0;
    D_800F8C56_F9856 = 0;
    D_800FDEA1_FEAA1 = 0;
    D_800FC9E8_FD5E8 = 0;
    D_800F9D20_FA920 = 0;
    D_8010116C_101D6C = 0;

    func_80068DAC_699AC();
}

/* MP1 func_800721D8 (fade/wipe dispatch); MP2 adds wipe types 9-14 */
void func_8008EFF8_8FBF8(Gfx** arg0) {
    if (D_800F8C56_F9856 == 3) {
        if (D_800CDC50_CE850 == 254) {
            func_8008FD1C_9091C(arg0);
        } else {
            func_8008F7F4_903F4(arg0, 255, D_800CDCA8_CE8A8);
        }
        return;
    }

    func_80068E64_69A64(arg0);

    if (D_800F8C56_F9856 == 0) {
        return;
    }

    switch (D_800F8C56_F9856) {
        case 1:
            switch (D_800CDC50_CE850) {
                case 0:
                    D_800F92DC_F9EDC = func_8008F640_90240(arg0);
                    break;
                case 254:
                    D_800F92DC_F9EDC = func_8008F8C8_904C8(arg0);
                    break;
                case 253:
                    D_800F92DC_F9EDC = func_8008FF08_90B08(arg0);
                    break;
                case 252:
                    D_800F92DC_F9EDC = 0;
                    break;
                case 1:
                    D_800F92DC_F9EDC = func_80090E84_91A84(arg0);
                    break;
                case 2:
                    D_800F92DC_F9EDC = func_80091B20_92720(arg0);
                    break;
                case 3:
                    D_800F92DC_F9EDC = func_80091CB4_928B4(arg0);
                    break;
                case 4:
                    D_800F92DC_F9EDC = func_80091EC0_92AC0(arg0);
                    break;
                case 5:
                    D_800F92DC_F9EDC = func_800920CC_92CCC(arg0);
                    break;
                case 6:
                    D_800F92DC_F9EDC = func_800922D8_92ED8(arg0);
                    break;
                case 7:
                    D_800F92DC_F9EDC = func_8009246C_9306C(arg0);
                    break;
                case 8:
                    D_800F92DC_F9EDC = func_80092600_93200(arg0, 28);
                    break;
                case 9:
                    D_800F92DC_F9EDC = func_80092600_93200(arg0, 32);
                    break;
                case 10:
                    D_800F92DC_F9EDC = func_80092600_93200(arg0, 33);
                    break;
                case 11:
                    D_800F92DC_F9EDC = func_80092600_93200(arg0, 34);
                    break;
                case 12:
                    D_800F92DC_F9EDC = func_80092600_93200(arg0, 29);
                    break;
                case 13:
                    D_800F92DC_F9EDC = func_80092600_93200(arg0, 30);
                    break;
                case 14:
                    D_800F92DC_F9EDC = func_80092600_93200(arg0, 31);
                    break;
            }
            D_80101054_101C54 += 1.0f;
            if (D_800F92DC_F9EDC == 0) {
                func_8008F624_90224(0, 0, 0);
                if (D_800CDC54_CE854 != NULL) {
                    if (D_8010116C_101D6C == 0) {
                        HuMemMemoryFreePerm(D_800CDC54_CE854);
                    }
                    D_800CDC54_CE854 = NULL;
                }
                func_800273A8_27FA8(28000);
            }
            break;
        case 2:
            switch (D_800CDC50_CE850) {
                case 0:
                    D_800F92DC_F9EDC = func_8008F71C_9031C(arg0);
                    break;
                case 254:
                    D_800F92DC_F9EDC = func_8008FA5C_9065C(arg0);
                    break;
                case 253:
                    D_800F92DC_F9EDC = func_8008FFE4_90BE4(arg0);
                    break;
                case 252:
                    D_800F92DC_F9EDC = func_80090460_91060(arg0);
                    break;
                case 1:
                    D_800F92DC_F9EDC = func_80090F40_91B40(arg0);
                    break;
                case 2:
                    D_800F92DC_F9EDC = func_80091BE0_927E0(arg0);
                    break;
                case 3:
                    D_800F92DC_F9EDC = func_80091DBC_929BC(arg0);
                    break;
                case 4:
                    D_800F92DC_F9EDC = func_80091FC8_92BC8(arg0);
                    break;
                case 5:
                    D_800F92DC_F9EDC = func_800921D4_92DD4(arg0);
                    break;
                case 6:
                    D_800F92DC_F9EDC = func_80092398_92F98(arg0);
                    break;
                case 7:
                    D_800F92DC_F9EDC = func_8009252C_9312C(arg0);
                    break;
                case 8:
                    D_800F92DC_F9EDC = func_8009270C_9330C(arg0, 28);
                    break;
                case 9:
                    D_800F92DC_F9EDC = func_8009270C_9330C(arg0, 32);
                    break;
                case 10:
                    D_800F92DC_F9EDC = func_8009270C_9330C(arg0, 33);
                    break;
                case 11:
                    D_800F92DC_F9EDC = func_8009270C_9330C(arg0, 34);
                    break;
                case 12:
                    D_800F92DC_F9EDC = func_8009270C_9330C(arg0, 29);
                    break;
                case 13:
                    D_800F92DC_F9EDC = func_8009270C_9330C(arg0, 30);
                    break;
                case 14:
                    D_800F92DC_F9EDC = func_8009270C_9330C(arg0, 31);
                    break;
            }
            D_80101054_101C54 += 1.0f;
            break;
    }

    if (D_800F92DC_F9EDC == 0) {
        if (D_800F8C56_F9856 == 2) {
            D_800F8C56_F9856 = 3;
        } else {
            D_800F8C56_F9856 = 0;
        }
        D_80101054_101C54 = 0.0f;
    }
}

void InitFadeIn(s32 arg0, s32 arg1) {
    s16 a = arg0;
    s16 b = arg1;

    if (D_800F92DC_F9EDC == 0) {
        D_800F8C56_F9856 = 1;
        D_800F92DC_F9EDC = 1;
        if (a != 255) {
            D_800CDC50_CE850 = a;
        }
        D_800FCE88_FDA88 = b;
        D_80101054_101C54 = 0.0f;
    }
}

void InitFadeOut(s32 arg0, s32 arg1) {
    s16 a = arg0;
    s16 b = arg1;

    if (D_800F92DC_F9EDC == 0) {
        D_800F8C56_F9856 = 2;
        D_800F92DC_F9EDC = 1;
        if (a != 255) {
            D_800CDC50_CE850 = a;
        }
        D_800FCE88_FDA88 = b;
        D_80101054_101C54 = 0.0f;
    }
}

extern u8 D_800F92DC_F9EDC;

s32 func_8008F618_90218(void) {
    return D_800F92DC_F9EDC;
}

void func_8008F624_90224(u8 arg0, u8 arg1, u8 arg2) {
    D_800F9D20_FA920 = arg0;
    D_800FC9E8_FD5E8 = arg1;
    D_800FDEA1_FEAA1 = arg2;
}

s32 func_8008F640_90240(Gfx** arg0) {
    if (D_800FCE88_FDA88 == 0.0f) {
        return 0;
    }

    func_8008F7F4_903F4(arg0, 255.0f - D_80101054_101C54 / D_800FCE88_FDA88 * 255.0f, D_800CDCA8_CE8A8);

    if (D_80101054_101C54 >= D_800FCE88_FDA88) {
        return 0;
    }

    return 1;
}

s32 func_8008F71C_9031C(Gfx** arg0) {
    if (D_800FCE88_FDA88 == 0.0f) {
        return 0;
    }

    func_8008F7F4_903F4(arg0, D_80101054_101C54 / D_800FCE88_FDA88 * 255.0f, D_800CDCA8_CE8A8);

    if (D_80101054_101C54 >= D_800FCE88_FDA88) {
        return 0;
    }

    return 1;
}

void func_8008F7F4_903F4(Gfx** arg0, u8 arg1, s32* arg2) {
    gSPDisplayList((*arg0)++, D_800CDC58_CE858);
    gDPSetRenderMode((*arg0)++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
    gDPSetCombineMode((*arg0)++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetPrimColor((*arg0)++, 0, 0, D_800F9D20_FA920, D_800FC9E8_FD5E8, D_800FDEA1_FEAA1, arg1);
    gDPFillRectangle((*arg0)++, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}

// decomp-permuter
s32 func_8008F8C8_904C8(Gfx** arg0) {
    f32 new_var;
    if (D_800CDC54_CE854 == 0) {
        return 0;
    }
    do {
        if ((new_var = D_800FCE88_FDA88) != 0.0f) {
            u8 var_a1 = 255.0f - ((D_80101054_101C54 / D_800FCE88_FDA88) * 255.0f);
            gSPDisplayList((*arg0)++, D_800CDC58_CE858);
            gDPSetCombineMode((*arg0)++, G_CC_MODULATEI_PRIM, G_CC_MODULATEI_PRIM);
            gDPSetRenderMode((*arg0)++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
            gDPSetPrimColor((*arg0)++, 0, 0, 255, 255, 255, var_a1);
            func_8008FD5C_9095C(arg0, D_80101638_102238);
            if (!(D_80101054_101C54 >= D_800FCE88_FDA88)) {
                return 1;
            }
        }
        if (D_8010116C_101D6C == 0) {
            HuMemMemoryFreePerm(D_800CDC54_CE854);
        }
    } while (0);
    D_800CDC54_CE854 = 0;
    return 0;
}

s32 func_8008FA5C_9065C(Gfx** arg0) {
    gSPDisplayList((*arg0)++, D_800CDC58_CE858);

    if (D_80101054_101C54 == 0.0f) {
        D_800CDC54_CE854 = HuMemMemoryAllocPerm(153664);
        D_80101638_102238 = (u8*)((u32)((u8*)D_800CDC54_CE854 + 63) & ~63);
        func_8008FB34_90734(arg0, D_80101638_102238);
        return 1;
    }

    func_8008FD5C_9095C(arg0, D_80101638_102238);

    if (D_80101054_101C54 > 1.0f) {
        return 0;
    }

    return 1;
}

void func_8008FB34_90734(Gfx** arg0, u8* arg1) {
    s16 i;
    s16 j;

    gDPSetColorImage((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, arg1);

    for (i = 0; i < SCREEN_HEIGHT; i += 16) {
        for (j = 0; j < SCREEN_WIDTH; j += 64) {
            func_8003F710_40310(arg0, (void*)(((j + (i * SCREEN_WIDTH)) * 2) + 0x02000000), 0, 2, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 64, 16, 0, 2, 2, 0, 0, 0, 0);
            gSPTextureRectangle((*arg0)++, j * 4, i * 4, (j + 64) * 4, (i + 16) * 4, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
        }
    }

    gDPSetColorImage((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, 0x02000000);
}

void func_8008FD1C_9091C(Gfx** arg0) {
    gSPDisplayList((*arg0)++, D_800CDC58_CE858);
    func_8008FD5C_9095C(arg0, D_80101638_102238);
}

void func_8008FD5C_9095C(Gfx** arg0, u8* arg1) {
    s16 i;
    s16 j;

    for (i = 0; i < SCREEN_HEIGHT; i += 16) {
        for (j = 0; j < SCREEN_WIDTH; j += 64) {
            func_8003F710_40310(arg0, arg1 + (j + i * SCREEN_WIDTH) * 2, 0, 2, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 64, 16, 0, 2, 2, 0, 0, 0, 0);
            gSPTextureRectangle((*arg0)++, j * 4, i * 4, (j + 64) * 4, (i + 16) * 4, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
        }
    }
}

s32 func_8008FF08_90B08(Gfx** arg0) {
    unk72D90Struct0* temp_v0;

    if (D_80101054_101C54 == 0.0f) {
        temp_v0 = D_800F8FD8_F9BD8 = func_80027154_27D54(sizeof(unk72D90Struct0), 28000);
        temp_v0->unk_00 = func_80027154_27D54(400 * sizeof(Vtx), 28000);
        temp_v0->unk_04 = func_80027154_27D54(1000 * sizeof(Gfx), 28000);
        func_80090000_90C00(temp_v0->unk_04, temp_v0->unk_00);
    }

    temp_v0 = D_800F8FD8_F9BD8;

    gSPDisplayList((*arg0)++, temp_v0->unk_04);

    if (D_80101054_101C54 >= 60.0f) {
        return 0;
    }

    return 1;
}

s32 func_8008FFE4_90BE4(Gfx** arg0) {
    return func_8008FA5C_9065C(arg0);
}

Gfx* func_80090000_90C00(Gfx*, Vtx*);

Gfx* func_80090000_90C00(Gfx* arg0, Vtx* arg1) {
    Gfx* sp4C = arg0;
    Vtx* var_s2 = arg1;
    u16 sp48;
    s16 i;
    s16 j;

    gSPDisplayList(sp4C++, D_800CDC58_CE858);
    gDPSetCombineMode(sp4C++, G_CC_DECALRGB, G_CC_DECALRGB);
    gDPSetRenderMode(sp4C++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
    gDPSetTexturePersp(sp4C++, G_TP_PERSP);
    gSPTexture(sp4C++, -1, -1, 0, G_TX_RENDERTILE, G_ON);

    guPerspective(&D_800FDDA0_FE9A0[D_800FFFD6_100BD6], &sp48, 20.0f, 1.3333334f, 80.0f, 8000.0f, 1.0f);
    guLookAt(&D_80101400_102000[D_800FFFD6_100BD6], 0.0f, 0.0f, 3000.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    gSPPerspNormalize(sp4C++, &sp48);
    gSPViewport(sp4C++, &D_800CDCB8_CE8B8);
    gSPMatrix(sp4C++, osVirtualToPhysical(&D_800FDDA0_FE9A0[D_800FFFD6_100BD6]), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(sp4C++, VIRTUAL_TO_PHYSICAL(&D_80101400_102000[D_800FFFD6_100BD6]), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPSetScissor(sp4C++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    for (i = 96; i >= -120; i -= 24) {
        for (j = -160; j < 160; j += 32) {
            s32 sp54 = (96 - i) * SCREEN_WIDTH + 160;

            func_8003F710_40310(&sp4C, D_80101638_102238 + (j + sp54) * 2, 0, 2, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 32, 24, 0, 2, 2, 5, 5, 0, 0);

            gSPVertex(sp4C++, osVirtualToPhysical(var_s2), 4, 0);
            gSP1Quadrangle(sp4C++, 0, 1, 2, 3, 0);

            var_s2->n.ob[0] = j * 10;
            var_s2->n.ob[1] = i * 10;
            var_s2->n.ob[2] = 0;
            var_s2->n.n[0] = var_s2->n.n[1] = var_s2->n.n[2] = -1;
            var_s2->n.tc[0] = 0;
            var_s2->n.tc[1] = 768;
            var_s2->n.a = 255;
            var_s2++;

            var_s2->n.ob[0] = j * 10;
            var_s2->n.ob[1] = i * 10 + SCREEN_HEIGHT;
            var_s2->n.ob[2] = 0;
            var_s2->n.n[0] = var_s2->n.n[1] = var_s2->n.n[2] = -1;
            var_s2->n.tc[0] = 0;
            var_s2->n.tc[1] = 0;
            var_s2->n.a = 255;
            var_s2++;

            var_s2->n.ob[0] = j * 10 + SCREEN_WIDTH;
            var_s2->n.ob[1] = i * 10 + SCREEN_HEIGHT;
            var_s2->n.ob[2] = 0;
            var_s2->n.n[0] = var_s2->n.n[1] = var_s2->n.n[2] = -1;
            var_s2->n.tc[0] = 1024;
            var_s2->n.tc[1] = 0;
            var_s2->n.a = 255;
            var_s2++;

            var_s2->n.ob[0] = j * 10 + SCREEN_WIDTH;
            var_s2->n.ob[1] = i * 10;
            var_s2->n.ob[2] = 0;
            var_s2->n.n[0] = var_s2->n.n[1] = var_s2->n.n[2] = -1;
            var_s2->n.tc[0] = 1024;
            var_s2->n.tc[1] = 768;
            var_s2->n.a = 255;
            var_s2++;
        }
    }

    gSPEndDisplayList(sp4C++);
    return sp4C;
}

/* MP1 func_80073560: shrink the frame into the depth buffer and draw it back scaled */
s32 func_80090460_91060(Gfx** arg0) {
    f32 temp_f22;
    f32 temp_f24;
    u8* var_s8; /* a frame buffer address */
    s16 i;
    s16 j;

    if (D_800FCE88_FDA88 - 1.0f <= D_80101054_101C54) {
        func_8008F7F4_903F4(arg0, 255, D_800CDCA8_CE8A8);
        return 0;
    }

    temp_f22 = 1.0f - D_80101054_101C54 / D_800FCE88_FDA88;
    temp_f24 = 1.0f / temp_f22;

    gSPDisplayList((*arg0)++, D_800CDC58_CE858);
    gDPSetAlphaCompare((*arg0)++, G_AC_THRESHOLD);
    gDPSetBlendColor((*arg0)++, 0, 0, 0, 0);
    gDPSetTextureFilter((*arg0)++, G_TF_BILERP);
    gDPSetScissor((*arg0)++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    var_s8 = D_800F8418_F9018;

    gDPSetColorImage((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, 0x003D0800);
    gSPDisplayList((*arg0)++, D_800CDCC8_CE8C8);
    gDPSetCombineMode((*arg0)++, G_CC_DECALRGB, G_CC_DECALRGB);
    gDPSetRenderMode((*arg0)++, G_RM_OPA_SURF, G_RM_OPA_SURF2);

    for (i = 0; i < SCREEN_HEIGHT; i += 16) {
        for (j = 0; j < SCREEN_WIDTH; j += 64) {
            func_8003F710_40310(arg0, var_s8 + (j + i * SCREEN_WIDTH) * 2, 0, 2, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 64, 16, 0, 2, 2, 0, 0, 0, 0);
            gSPTextureRectangle((*arg0)++, j * temp_f22 * 4.0f, i * temp_f22 * 4.0f,
                (j * temp_f22 + temp_f22 * 64.0f) * 4.0f, (i * temp_f22 + temp_f22 * 16.0f) * 4.0f,
                G_TX_RENDERTILE, 0, 0, temp_f24 * 1024.0f, temp_f24 * 1024.0f);
        }
    }

    gDPSetColorImage((*arg0)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, 0x02000000);

    var_s8 = (u8*)0x803D0800;
    for (i = 0; i < temp_f22 * (f32)SCREEN_HEIGHT + 15.0f; i += 16) {
        for (j = 0; j < temp_f22 * (f32)SCREEN_WIDTH + 31.0f; j += 32) {
            func_8003F710_40310(arg0, var_s8 + (j + i * SCREEN_WIDTH) * 2, 0, 2, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 32, 16, 0, 2, 2, 0, 0, 0, 0);
            gSPTextureRectangle((*arg0)++, j * temp_f24 * 4.0f, i * temp_f24 * 4.0f,
                (j + 32) * temp_f24 * 4.0f, (i + 16) * temp_f24 * 4.0f,
                G_TX_RENDERTILE, 0, 0, temp_f22 * 1024.0f, temp_f22 * 1024.0f);
        }
    }

    gDPPipeSync((*arg0)++);
    gDPSetCombineMode((*arg0)++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetRenderMode((*arg0)++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetPrimColor((*arg0)++, 0, 0, 0, 0, 0, 8);
    gDPFillRectangle((*arg0)++, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    return 1;
}

s32 func_80090E84_91A84(Gfx** arg0) {
    if (D_800FCE88_FDA88 == 0.0f) {
        return 0;
    }

    if (D_80101054_101C54 == 0.0f) {
        func_80091024_91C24(0x15);
    }

    func_8009110C_91D0C(arg0, D_80101054_101C54 / D_800FCE88_FDA88, 1.0f);

    if (D_80101054_101C54 >= D_800FCE88_FDA88) {
        return 0;
    }

    return 1;
}

s32 func_80090F40_91B40(Gfx** arg0) {
    f32 var_a2;

    if (D_800FCE88_FDA88 == 0.0f) {
        return 0;
    }

    if (D_80101054_101C54 == 0.0f) {
        func_80091024_91C24(0x15);
    }

    var_a2 = (1.0f - D_80101054_101C54 / D_800FCE88_FDA88) * 1.1f;
    func_8009110C_91D0C(arg0, var_a2, 1.0f);

    if (D_80101054_101C54 >= D_800FCE88_FDA88) {
        return 0;
    }

    return 1;
}

void* func_80091024_91C24(s32 arg0) {
    u8* data;
    u8* p;

    data = DataRead(arg0);
    p = data + (data[2] << 8) + data[3];
    D_800FD834_FE434.unk_00 = (p[4] << 8) + p[5];
    D_800FD834_FE434.unk_02 = (p[6] << 8) + p[7];
    p = data + (p[2] << 8) + p[3];
    D_800FD834_FE434.unk_04 = func_80027154_27D54(D_800FD834_FE434.unk_00 * D_800FD834_FE434.unk_02, 0x6D60);
    bcopy(p, D_800FD834_FE434.unk_04, D_800FD834_FE434.unk_00 * D_800FD834_FE434.unk_02);
    DataClose(data);
    return data;
}

/* MP1 func_8007420C: draw the wipe texture scaled by arg1 about the centre, fill the rest
   (MP2 renders both passes anti-aliased) */
void func_8009110C_91D0C(Gfx** arg0, f32 arg1, f32 arg2) {
    s16 var_t1;
    s16 var_t2;
    s16 var_t3;
    s16 var_t4;
    f32 temp_f4;

    if (arg1 == 0) {
        func_8008F7F4_903F4(arg0, 255, D_800CDCA8_CE8A8);
        return;
    }

    gSPDisplayList((*arg0)++, D_800CDC58_CE858);
    gDPSetAlphaCompare((*arg0)++, G_AC_THRESHOLD);
    gDPSetBlendColor((*arg0)++, 0, 0, 0, 1);
    gDPSetScissor((*arg0)++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    gDPSetTextureFilter((*arg0)++, G_TF_BILERP);
    gDPSetRenderMode((*arg0)++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
    gDPSetCombineLERP((*arg0)++, 0, 0, 0, PRIMITIVE, PRIMITIVE, 0, TEXEL0, 0, 0, 0, 0, PRIMITIVE, PRIMITIVE, 0, TEXEL0, 0);
    gDPLoadTextureBlock((*arg0)++, D_800FD834_FE434.unk_04, G_IM_FMT_I, G_IM_SIZ_8b, D_800FD834_FE434.unk_00, D_800FD834_FE434.unk_02, 0,
        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gDPSetPrimColor((*arg0)++, 0, 0, D_800F9D20_FA920, D_800FC9E8_FD5E8, D_800FDEA1_FEAA1, arg2 * 255.0f);

    var_t3 = 160.0f - arg1 * 160.0f;
    var_t1 = 120.0f - arg1 * 160.0f;
    var_t4 = 160.0f + arg1 * 160.0f;
    var_t2 = 120.0f + arg1 * 160.0f;
    temp_f4 = ((f32) var_t4 - var_t3) / D_800FD834_FE434.unk_00;

    gSPScisTextureRectangle((*arg0)++, var_t3 * 4, var_t1 * 4, var_t4 * 4, var_t2 * 4, 0, 0, 0,
        (1.0f / temp_f4) * 1024.0f, (1.0f / temp_f4) * 1024.0f);
    gDPSetRenderMode((*arg0)++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
    gDPSetCombineMode((*arg0)++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetPrimColor((*arg0)++, 0, 0, D_800F9D20_FA920, D_800FC9E8_FD5E8, D_800FDEA1_FEAA1, arg2 * 255.0f);

    if (var_t1 > 0) {
        gDPScisFillRectangle((*arg0)++, 0, 0, SCREEN_WIDTH, var_t1);
    } else {
        var_t1 = 0;
    }

    if (var_t2 < SCREEN_HEIGHT) {
        gDPScisFillRectangle((*arg0)++, 0, var_t2, SCREEN_WIDTH, SCREEN_HEIGHT);
    } else {
        var_t2 = SCREEN_HEIGHT;
    }

    if (var_t3 > 0) {
        gDPScisFillRectangle((*arg0)++, 0, var_t1, var_t3, var_t2);
    }

    if (var_t4 < SCREEN_WIDTH) {
        gDPScisFillRectangle((*arg0)++, var_t4, var_t1, SCREEN_WIDTH, var_t2);
    }
}

s32 func_80091B20_92720(Gfx** arg0) {
    if (D_800FCE88_FDA88 == 0.0f) {
        return 0;
    }

    if (D_80101054_101C54 == 0.0f) {
        func_80091024_91C24(0x16);
    }

    func_8009110C_91D0C(arg0, D_80101054_101C54 / D_800FCE88_FDA88 * 2.0f, 1.0f);

    if (D_80101054_101C54 >= D_800FCE88_FDA88) {
        return 0;
    }

    return 1;
}

s32 func_80091BE0_927E0(Gfx** arg0) {
    if (D_800FCE88_FDA88 == 0.0f) {
        return 0;
    }

    if (D_80101054_101C54 == 0.0f) {
        func_80091024_91C24(0x16);
    }

    func_8009110C_91D0C(arg0, (1.0f - D_80101054_101C54 / D_800FCE88_FDA88) * 2.0f, 1.0f);

    if (D_80101054_101C54 >= D_800FCE88_FDA88) {
        return 0;
    }

    return 1;
}

s32 func_80091CB4_928B4(Gfx** arg0) {
    f32 var_a2;
    f32 temp_f2;
    f32 var_f2;

    if (D_800FCE88_FDA88 == 0.0f) {
        return 0;
    }

    if (D_80101054_101C54 == 0.0f) {
        func_80091024_91C24(0x17);
    }

    var_a2 = D_80101054_101C54 / D_800FCE88_FDA88 * 2.0f;
    temp_f2 = D_800FCE88_FDA88 * 0.5f;
    if (temp_f2 < D_80101054_101C54) {
        var_f2 = 1.0f - (D_80101054_101C54 - temp_f2) / temp_f2;
    } else {
        var_f2 = 1.0f;
    }

    func_8009110C_91D0C(arg0, var_a2, var_f2);

    if (D_80101054_101C54 >= D_800FCE88_FDA88) {
        return 0;
    }

    return 1;
}

s32 func_80091DBC_929BC(Gfx** arg0) {
    f32 var_a2;
    f32 temp_f2;
    f32 var_f2;

    if (D_800FCE88_FDA88 == 0.0f) {
        return 0;
    }

    if (D_80101054_101C54 == 0.0f) {
        func_80091024_91C24(0x17);
    }

    var_a2 = (1.0f - D_80101054_101C54 / D_800FCE88_FDA88) * 2.0f;
    temp_f2 = D_800FCE88_FDA88 * 0.5f;
    if (temp_f2 > D_80101054_101C54) {
        var_f2 = D_80101054_101C54 / temp_f2;
    } else {
        var_f2 = 1.0f;
    }

    func_8009110C_91D0C(arg0, var_a2, var_f2);

    if (D_80101054_101C54 >= D_800FCE88_FDA88) {
        return 0;
    }

    return 1;
}

s32 func_80091EC0_92AC0(Gfx** arg0) {
    f32 var_a2;
    f32 temp_f2;
    f32 var_f2;

    if (D_800FCE88_FDA88 == 0.0f) {
        return 0;
    }

    if (D_80101054_101C54 == 0.0f) {
        func_80091024_91C24(0x18);
    }

    var_a2 = D_80101054_101C54 / D_800FCE88_FDA88 * 2.0f;
    temp_f2 = D_800FCE88_FDA88 * 0.5f;
    if (temp_f2 < D_80101054_101C54) {
        var_f2 = 1.0f - (D_80101054_101C54 - temp_f2) / temp_f2;
    } else {
        var_f2 = 1.0f;
    }

    func_8009110C_91D0C(arg0, var_a2, var_f2);

    if (D_80101054_101C54 >= D_800FCE88_FDA88) {
        return 0;
    }

    return 1;
}

s32 func_80091FC8_92BC8(Gfx** arg0) {
    f32 var_a2;
    f32 temp_f2;
    f32 var_f2;

    if (D_800FCE88_FDA88 == 0.0f) {
        return 0;
    }

    if (D_80101054_101C54 == 0.0f) {
        func_80091024_91C24(0x18);
    }

    var_a2 = (1.0f - D_80101054_101C54 / D_800FCE88_FDA88) * 2.0f;
    temp_f2 = D_800FCE88_FDA88 * 0.5f;
    if (temp_f2 > D_80101054_101C54) {
        var_f2 = D_80101054_101C54 / temp_f2;
    } else {
        var_f2 = 1.0f;
    }

    func_8009110C_91D0C(arg0, var_a2, var_f2);

    if (D_80101054_101C54 >= D_800FCE88_FDA88) {
        return 0;
    }

    return 1;
}

s32 func_800920CC_92CCC(Gfx** arg0) {
    f32 var_a2;
    f32 temp_f2;
    f32 var_f2;

    if (D_800FCE88_FDA88 == 0.0f) {
        return 0;
    }

    if (D_80101054_101C54 == 0.0f) {
        func_80091024_91C24(0x19);
    }

    var_a2 = D_80101054_101C54 / D_800FCE88_FDA88 * 2.0f;
    temp_f2 = D_800FCE88_FDA88 * 0.5f;
    if (temp_f2 < D_80101054_101C54) {
        var_f2 = 1.0f - (D_80101054_101C54 - temp_f2) / temp_f2;
    } else {
        var_f2 = 1.0f;
    }

    func_8009110C_91D0C(arg0, var_a2, var_f2);

    if (D_80101054_101C54 >= D_800FCE88_FDA88) {
        return 0;
    }

    return 1;
}

s32 func_800921D4_92DD4(Gfx** arg0) {
    f32 var_a2;
    f32 temp_f2;
    f32 var_f2;

    if (D_800FCE88_FDA88 == 0.0f) {
        return 0;
    }

    if (D_80101054_101C54 == 0.0f) {
        func_80091024_91C24(0x19);
    }

    var_a2 = (1.0f - D_80101054_101C54 / D_800FCE88_FDA88) * 2.0f;
    temp_f2 = D_800FCE88_FDA88 * 0.5f;
    if (temp_f2 > D_80101054_101C54) {
        var_f2 = D_80101054_101C54 / temp_f2;
    } else {
        var_f2 = 1.0f;
    }

    func_8009110C_91D0C(arg0, var_a2, var_f2);

    if (D_80101054_101C54 >= D_800FCE88_FDA88) {
        return 0;
    }

    return 1;
}

s32 func_800922D8_92ED8(Gfx** arg0) {
    if (D_800FCE88_FDA88 == 0.0f) {
        return 0;
    }

    if (D_80101054_101C54 == 0.0f) {
        func_80091024_91C24(0x1A);
    }

    func_8009110C_91D0C(arg0, D_80101054_101C54 / D_800FCE88_FDA88 * 2.0f, 1.0f);

    if (D_80101054_101C54 >= D_800FCE88_FDA88) {
        return 0;
    }

    return 1;
}

s32 func_80092398_92F98(Gfx** arg0) {
    if (D_800FCE88_FDA88 == 0.0f) {
        return 0;
    }

    if (D_80101054_101C54 == 0.0f) {
        func_80091024_91C24(0x1A);
    }

    func_8009110C_91D0C(arg0, (1.0f - D_80101054_101C54 / D_800FCE88_FDA88) * 2.0f, 1.0f);

    if (D_80101054_101C54 >= D_800FCE88_FDA88) {
        return 0;
    }

    return 1;
}

s32 func_8009246C_9306C(Gfx** arg0) {
    if (D_800FCE88_FDA88 == 0.0f) {
        return 0;
    }

    if (D_80101054_101C54 == 0.0f) {
        func_80091024_91C24(0x1B);
    }

    func_8009110C_91D0C(arg0, D_80101054_101C54 / D_800FCE88_FDA88 * 2.0f, 1.0f);

    if (D_80101054_101C54 >= D_800FCE88_FDA88) {
        return 0;
    }

    return 1;
}

s32 func_8009252C_9312C(Gfx** arg0) {
    if (D_800FCE88_FDA88 == 0.0f) {
        return 0;
    }

    if (D_80101054_101C54 == 0.0f) {
        func_80091024_91C24(0x1B);
    }

    func_8009110C_91D0C(arg0, (1.0f - D_80101054_101C54 / D_800FCE88_FDA88) * 2.0f, 1.0f);

    if (D_80101054_101C54 >= D_800FCE88_FDA88) {
        return 0;
    }

    return 1;
}

/* MP1 func_80074FC0; MP2 passes the wipe type in */
s32 func_80092600_93200(Gfx** arg0, s32 arg1) {
    f32 var_a2;
    f32 temp_f2;
    f32 var_f2;

    if (D_800FCE88_FDA88 == 0.0f) {
        return 0;
    }

    if (D_80101054_101C54 == 0.0f) {
        func_80091024_91C24(arg1);
    }

    var_a2 = D_80101054_101C54 / D_800FCE88_FDA88 * 2.0f;
    temp_f2 = D_800FCE88_FDA88 * 0.5f;
    if (temp_f2 < D_80101054_101C54) {
        var_f2 = 1.0f - (D_80101054_101C54 - temp_f2) / temp_f2;
    } else {
        var_f2 = 1.0f;
    }

    func_8009110C_91D0C(arg0, var_a2, var_f2);

    if (D_80101054_101C54 >= D_800FCE88_FDA88) {
        return 0;
    }

    return 1;
}

/* MP1 func_80074EBC; MP2 passes the wipe type in */
s32 func_8009270C_9330C(Gfx** arg0, s32 arg1) {
    f32 var_a2;
    f32 temp_f2;
    f32 var_f2;

    if (D_800FCE88_FDA88 == 0.0f) {
        return 0;
    }

    if (D_80101054_101C54 == 0.0f) {
        func_80091024_91C24(arg1);
    }

    var_a2 = (1.0f - D_80101054_101C54 / D_800FCE88_FDA88) * 2.0f;
    temp_f2 = D_800FCE88_FDA88 * 0.5f;
    if (temp_f2 > D_80101054_101C54) {
        var_f2 = D_80101054_101C54 / temp_f2;
    } else {
        var_f2 = 1.0f;
    }

    func_8009110C_91D0C(arg0, var_a2, var_f2);

    if (D_80101054_101C54 >= D_800FCE88_FDA88) {
        return 0;
    }

    return 1;
}

void func_80092814_93414(void) {
    Gfx* sp10;

    D_800ED8F0_EE4F0 = HuMemAlloc(153664);
    sp10 = D_800ED8FC_EE4FC = HuMemAlloc(6400);

    D_800ED8F4_EE4F4 = (u8*)(((u32)D_800ED8F0_EE4F0 + 63) & ~63);
    D_800ED900_EE500 = func_8002838C_28F8C(0, &func_80092A24_93624, 6);

    gSPDisplayList(sp10++, D_800CDC58_CE858);
    func_8008FB34_90734(&sp10, D_800ED8F4_EE4F4);
    gSPEndDisplayList(sp10);

    D_800ED8F8_EE4F8 = 0;
}

s32 func_800928D0_934D0(void) {
    if (D_800ED8F8_EE4F8 >= 0 && D_800ED8F8_EE4F8 < 3) {
        return 0;
    }

    func_80027340_27F40(D_800ED8FC_EE4FC);
    func_800283DC_28FDC(D_800ED900_EE500);

    return 1;
}

void func_80092914_93514(void) {
    Gfx* sp10;

    sp10 = D_800ED8FC_EE4FC = HuMemAlloc(6400);
    D_800ED902_EE502 = func_8002838C_28F8C(0, &func_80092A5C_9365C, 0);

    gSPDisplayList(sp10++, D_800CDC58_CE858);
    gDPSetCombineMode(sp10++, G_CC_MODULATEI_PRIM, G_CC_MODULATEI_PRIM);
    gDPSetRenderMode(sp10++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
    gDPSetPrimColor(sp10++, 0, 0, 255, 255, 255, 128);

    func_8008FD5C_9095C(&sp10, D_800ED8F4_EE4F4);
    gSPEndDisplayList(sp10);
}

void func_800929EC_935EC(void) {
    func_80027340_27F40(D_800ED8FC_EE4FC);
    func_80027340_27F40(D_800ED8F0_EE4F0);
    func_800283DC_28FDC(D_800ED902_EE502);
}

void func_80092A24_93624(Gfx** arg0) {
    gSPDisplayList((*arg0)++, D_800ED8FC_EE4FC);
    D_800ED8F8_EE4F8++;
}

void func_80092A5C_9365C(Gfx** arg0) {
    gSPDisplayList((*arg0)++, D_800ED8FC_EE4FC);
}

void func_80092A80_93680(void) {
    D_800ED8F0_EE4F0 = D_800CDC54_CE854;
    D_800ED8F4_EE4F4 = D_80101638_102238;
    D_8010116C_101D6C = 1;
}

void func_80092AB0_936B0(void) {
    func_80027340_27F40(D_800ED8FC_EE4FC);
    HuMemMemoryFreePerm(D_800ED8F0_EE4F0);
    func_800283DC_28FDC(D_800ED902_EE502);
    D_8010116C_101D6C = 0;
}
