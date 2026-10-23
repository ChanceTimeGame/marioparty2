#include "common.h"

#include "game/data.h"
#include "game/malloc.h"

typedef f32 Matrix4f[4][4];

extern s16 D_800F8D12_F9912;
extern s16 D_800E1B8A_E278A[]; /* star space of each star spawn slot */
extern s16 D_800F928C_F9E8C;
extern Mtx* D_800FD83C_FE43C;
void func_800204C0_210C0(s16, Gfx**);
void func_8002064C_2124C(s16, Gfx**);
void func_80053754_54354(void* arg0);
void func_800B30D0_B3CD0(Matrix4f mf, Mtx* m); /* guMtxL2F */
void func_80025770_26370(Matrix4f, f32, f32, f32); /* translate */
void func_80025830_26430(Matrix4f, f32, f32, f32); /* scale */
void func_80026104_26D04(Matrix4f, f32);           /* rotate (y) */
void func_800B3040_B3C40(Matrix4f mf, Mtx* m);     /* guMtxF2L */
s32 _CheckFlag(s32);


/* Board spaces and chains. C from MP1 src/engine/spaces.c (BoardSpace there is MP2's SpaceData,
   ChainData MP3's LinkData) and MP3 ovl_80_shared_board FA250.c (MBMasu*; func_800556F4_562F4 is
   MBMasuEventCall); the rest have no reference and stay asm. */

#define SPACE_TYPE_TOTAL 18
#define SPACE_INDEX_INVALID -1

typedef struct LinkData {
    /* 0x00 */ s16 chainIndicies;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16* spaces;
} LinkData; // size 0x8

typedef struct EventTableEntry {
    s16 spaceIndex;
    void* eventList;
} EventTableEntry;

extern u16 gTotalSpaces; //total current board spaces
extern u16 D_800E18D2_E24D2;
extern SpaceData* D_800E18D4_E24D4;
extern LinkData* D_800E18D8_E24D8;
extern void* D_800E18E0_E24E0[];
extern void* D_800E192C_E252C;
extern void* D_800E1930_E2530;
extern void* D_800E1934_E2534;
extern void* D_800E1938_E2538;
extern f32 D_800E1940_E2540[];
extern s32 D_800E1960_E2560;
extern u16 D_800FCE90_FDA90;
extern s16 D_800E1B66_E2766;
extern s16 D_800E1B88_E2788; //total blue spaces hidden blocks cannot spawn on
extern s16 D_800E1B68_E2768[];
extern s16 D_800E1968_E2568[];
SpaceData* GetSpaceData(s16);
s32 MBRand(f32 arg0);
void LoadSpaceTextures(s16 type);
void MBMasuDraw(Gfx** gfx, Mtx* mtx, u8 arg2);
f32 MBDBackMdlScaleGet(void);
u16* func_8005484C_5544C(void*, s32);
void func_8002D018_2DC18(s32, void* func);
void SetPlayerOntoChain(s16 player, s16 chain_index, s16 space_index);
void func_800552E8_55EE8(void);
void func_800553EC_55FEC(void);
void func_800554EC_560EC(void);
void func_800555EC_561EC(s16 arg0, void* arg1);
void func_800558E8_564E8(s16 arg0);
s16 func_800558F4_564F4(void);
s16 GetChainSpaceIndexFromAbsSpaceIndex(s16 absIndex, s32 chainIndex);
s16 GetAbsSpaceIndexFromChainSpaceIndex(u16 chainIndex, u16 spaceIndex);
s16 BoardGetChainLength(u16 chainIndex);

typedef struct MbEventListEntry {
    /* 0x00 */ s16 activation_type;
    /* 0x02 */ s16 execution_type;
    /* 0x04 */ void (*event_fn)();
} MbEventListEntry; // size 0x8

extern s16 D_800E1928_E2528;
extern s32 D_800E193C_E253C;

typedef struct SpaceTexSets {
    /* 0x00 */ u32 set2[15];
    /* 0x3C */ u32 next[18]; /* set 3 */
} SpaceTexSets;

typedef struct SpaceQuads {
    /* 0x00 */ f32 scale[14];
    /* 0x38 */ Vtx quad32[4];
    /* 0x78 */ Vtx quad8[4];
} SpaceQuads;

/* .data (0xCCE80-0xCD190) */
void* D_800CC280_CCE80 = NULL;
/* Space texture files by space type, per texture set (LoadSpaceTextures). */
u32 D_800CC284_CCE84[] = {
    0, 0xA0033, 0xA0034, 0, 0xA0036, 0xA003C,
    0xA0037, 0xA003A, 0, 0xA0035, 0, 0,
    0xA003B, 0xA003F, 0xA0038, 0xA0039, 0xA003D, 0xA003E,
};
u32 D_800CC2CC_CCECC[] = {
    0, 0xA0051, 0xA0052, 0, 0xA0054, 0xA0055,
    0xA005A, 0xA0059, 0, 0xA0053, 0, 0,
    0xA0058, 0xA005B, 0xA0056, 0xA0057, 0, 0,
};
/* Set 2 has 15 entries and the 18-entry loop reads on into set 3 (retail): one block, so the host
   reads the same words. D_800CC350_CCF50 is an undefined_syms.txt alias of .next. */
SpaceTexSets D_800CC314_CCF14 = {
    {
        0xA005E, 0xA005D, 0xA005C, 0, 0xA005F, 0xA0060,
        0, 0, 0, 0, 0, 0,
        0, 0, 0,
    },
    {
        0, 0xA0033, 0xA0034, 0, 0xA0036, 0xA003C,
        0xA0037, 0xA003A, 0, 0xA0035, 0, 0,
        0xA003B, 0xA003F, 0xA0038, 0xA0038, 0xA003D, 0xA003D,
    },
};
u32 D_800CC398_CCF98[] = {
    0, 0xA0051, 0xA0052, 0, 0xA0054, 0xA0055,
    0xA0055, 0xA0053, 0, 0xA0053, 0, 0,
    0xA0058, 0, 0xA0056, 0xA0056, 0, 0,
};
f32 D_800CC3E0_CCFE0[] = { /* space scale per space type */
    2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f,
    2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f,
    2.0f, 2.0f, 2.0f, 2.0f, 1.5f, 1.5f,
};
/* Space scales for set 2 (14 entries: the 18-entry loop reads on into the vertices, retail) and the
   space quads for 32x32 and 8x8 textures. D_800CC460_CD060 / D_800CC4A0_CD0A0 are undefined_syms.txt
   aliases of .quad32 / .quad8. */
SpaceQuads D_800CC428_CD028 = {
    {
        2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f,
        2.0f, 2.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f,
    },
    {
        { { { 50, 0, -50 }, 0, { 1024, 1024 }, { 0, 0, 127, 255 } } },
        { { { -50, 0, -50 }, 0, { 0, 1024 }, { 0, 0, 127, 255 } } },
        { { { -50, 0, 50 }, 0, { 0, 0 }, { 0, 0, 127, 255 } } },
        { { { 50, 0, 50 }, 0, { 1024, 0 }, { 0, 0, 127, 255 } } },
    },
    {
        { { { 50, 0, -50 }, 0, { 224, 224 }, { 0, 0, 127, 255 } } },
        { { { -50, 0, -50 }, 0, { 0, 224 }, { 0, 0, 127, 255 } } },
        { { { -50, 0, 50 }, 0, { 0, 0 }, { 0, 0, 127, 255 } } },
        { { { 50, 0, 50 }, 0, { 224, 0 }, { 0, 0, 127, 255 } } },
    },
};
Gfx D_800CC4E0_CD0E0[] = {
    gsSPSegment(0x00, 0x00000000),
    gsSPClipRatio(FRUSTRATIO_2),
    gsSPClearGeometryMode(0xFFFFFFFF),
    gsSPSetGeometryMode(G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_AVERAGE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetAlphaDither(G_AD_DISABLE),
    gsSPEndDisplayList(),
};
u8 D_800CC570_CD170[] = { /* flags per space type */
    0x01, 0x02, 0x04, 0x01, 0x10, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
};

void LoadSpaceTextures(s16 type) {
    s32 i;
    u32* ptr;

    D_800E1928_E2528 = type;
    switch (type) {
        case 0:
            ptr = D_800CC284_CCE84;
            break;
        case 1:
            ptr = D_800CC2CC_CCECC;
            break;
        default:
            ptr = D_800CC314_CCF14.set2;
            break;
        case 3:
            ptr = D_800CC314_CCF14.next;
            break;
        case 4:
            ptr = D_800CC398_CCF98;
            break;
    }

    for (i = 0; i < SPACE_TYPE_TOTAL; i++) {
        if (ptr[i] != 0) {
            D_800E18E0_E24E0[i] = DataRead(ptr[i]);
        } else {
            D_800E18E0_E24E0[i] = NULL;
        }
    }
}

void FreeSpaceTextures(void) {
   s32 i;
   for (i = 0; i < SPACE_TYPE_TOTAL; i++) {
      if (D_800E18E0_E24E0[i] != NULL) {
         DataClose(D_800E18E0_E24E0[i]);
      }
      D_800E18E0_E24E0[i] = NULL;
   }
}

void func_80054228_54E28(void) {
    if (D_800F8D12_F9912 != 0) {
        LoadSpaceTextures(3);
    } else {
        LoadSpaceTextures(0);
    }
    D_800CC280_CCE80 = NULL;
    D_800E1960_E2560 = 0;
}

void MBMasuArrowAngleAdd(f32 arg0) {
    if (D_800E1960_E2560 != 8) {
        D_800E1940_E2540[D_800E1960_E2560++] = arg0;
    }
}

void func_8005429C_54E9C(void) {
    FreeSpaceTextures();
}

void ChangeSpaceTextures(s16 type) {
   FreeSpaceTextures();
   LoadSpaceTextures(type);
}

void func_800542E8_54EE8(s32 arg0, s16 arg1) {
    D_800E1B8A_E278A[arg0] = arg1;
}

/* Draws every space: one quad per space, by space type. Type 16 draws only the current star space and
   type 17 only the space GwSystem.unk_1C names (neither when flag 0xC or 0xD is set). */
// register allocation and loop-invariant placement (retail hoists size * size and the tile size into
// stack slots before the type loop); calls, stores and branches match
#ifdef NON_MATCHING
void MBMasuDraw(Gfx** gfx, Mtx* mtx, u8 arg2) {
    Matrix4f sp10;
    f32 sp50[2];
    Mtx* sp5C;
    Vtx* sp64;
    f32* sp6C;
    SpaceData* space;
    s32 i;
    s32 j;
    s32 arrow;
    s32 size;
    Mtx* m;
    f32 scale;
    GW_SYSTEM* gw;

    sp5C = mtx;
    gw = &GwSystem;
    arrow = 0;
    if (arg2 == 0 && D_800FCE90_FDA90 != 0) {
        gSPDisplayList((*gfx)++, D_800CC4E0_CD0E0);
        func_800204C0_210C0(0, gfx);
        func_8002064C_2124C(0, gfx);
        func_80053754_54354(sp50);
        switch (D_800E1928_E2528) {
            case 0:
            case 3:
                sp64 = (Vtx*)OS_K0_TO_PHYSICAL(D_800CC428_CD028.quad32);
                sp6C = D_800CC3E0_CCFE0;
                size = 32;
                break;
            case 1:
            case 4:
                sp64 = (Vtx*)OS_K0_TO_PHYSICAL(D_800CC428_CD028.quad8);
                sp6C = D_800CC3E0_CCFE0;
                size = 8;
                break;
            default:
                size = 32;
                sp64 = (Vtx*)OS_K0_TO_PHYSICAL(D_800CC428_CD028.quad32);
                sp6C = D_800CC428_CD028.scale;
                break;
        }
        for (i = 0; i < SPACE_TYPE_TOTAL; i++) {
            if (D_800E18E0_E24E0[i] == NULL) {
                continue;
            }
            scale = sp6C[i];
            gDPLoadTextureBlock((*gfx)++, (u8*)D_800E18E0_E24E0[i] + 0x10, G_IM_FMT_RGBA, G_IM_SIZ_32b, size, size, 0,
                                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
            space = NULL;
            if (i == 16) {
                if (_CheckFlag(0xD) != 0 || _CheckFlag(0xC) != 0) {
                    continue;
                }
                if (gw->current_board_index != 8) {
                    space = GetSpaceData(D_800E1B8A_E278A[gw->star_spawn_indices[gw->unk_0A]]);
                }
            } else if (i == 17) {
                if (_CheckFlag(0xD) != 0 || _CheckFlag(0xC) != 0) {
                    continue;
                }
                if (gw->unk_1C != -1 && gw->current_board_index != 8) {
                    space = GetSpaceData(D_800E1B8A_E278A[gw->unk_1C]);
                }
            }
            for (j = 0; j < gTotalSpaces; j++) {
                if ((j == 0) & (space != NULL)) {
                    /* the one space chosen above: draw it once */
                    j = gTotalSpaces;
                } else {
                    space = GetSpaceData(j);
                    if (space->space_type != i || !(space->unk_00 & 1)) {
                        continue;
                    }
                }
                func_800B30D0_B3CD0(sp10, &sp5C[1]);
                func_80025770_26370(sp10, space->coords.x, space->coords.y, space->coords.z);
                if (i == 13 && arrow < D_800E1960_E2560) {
                    func_80026104_26D04(sp10, D_800E1940_E2540[arrow++]);
                }
                func_80025830_26430(sp10, scale * space->rot.x, 1.0f, scale * space->rot.z);
                m = &D_800FD83C_FE43C[D_800F928C_F9E8C++];
                func_800B3040_B3C40(sp10, m);
                gSPMatrix((*gfx)++, OS_K0_TO_PHYSICAL(m), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPVertex((*gfx)++, sp64, 4, 0);
                gSP1Quadrangle((*gfx)++, 0, 1, 2, 3, 0);
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/54CB0", MBMasuDraw);
#endif

u16* func_8005484C_5544C(void* base, s32 offset) {
    return (u16*)((u8*)base + *(u16*)((u8*)base + offset));
}

s32 MBMasuCreate(s32 arg0, s32 arg1) {
    f32 sp10[3];
    LinkData* var_s1_2;
    SpaceData* var_s1;
    s16* temp_v0_3;
    u16* var_s0_2;
    s32 var_s2;
    s32 var_v1;
    u16* temp_s3;
    u16* temp_v0_2;
    struct var_s0* var_s0;

    D_800CC280_CCE80 = DataRead((arg0 << 0x10) | (arg1 << 0x10 >> 0x10));
    if (D_800CC280_CCE80 != NULL) {
        D_800E192C_E252C = 0;
        D_800E1930_E2530 = 0;
        D_800E1934_E2534 = 0;
        D_800E1938_E2538 = 0;
        var_s0_2 = D_800CC280_CCE80;
        gTotalSpaces = var_s0_2[0];
        D_800E18D2_E24D2 = var_s0_2[1];
        D_800E18D4_E24D4 = HuMemMemoryAllocTemp(gTotalSpaces * 0x24);
        var_s0_2 = func_8005484C_5544C(D_800CC280_CCE80, 4);
        var_s1 = D_800E18D4_E24D4;
        for (var_s2 = 0; var_s2 < gTotalSpaces; var_s2++) {
            var_s1->unk_00 = 1;
            var_s1->unk_02 = *var_s0_2++;
            var_s1->space_type = *var_s0_2++;
            sp10[0] = var_s1->coords.x = (((f32*)var_s0_2))[0] * 5.0f * MBDBackMdlScaleGet();
            sp10[1] = var_s1->coords.y = (((f32*)var_s0_2))[1] * 5.0f * MBDBackMdlScaleGet();
            sp10[2] = var_s1->coords.z = (((f32*)var_s0_2))[2] * 5.0f * MBDBackMdlScaleGet();
            var_s0_2 += 6;
            var_s1->rot.x = MBDBackMdlScaleGet();
            var_s1->rot.y = MBDBackMdlScaleGet();
            var_s1->rot.z = MBDBackMdlScaleGet();
            var_s1->event_list = NULL;
            var_s1 += 1;
        }
        D_800E18D8_E24D8 = HuMemMemoryAllocTemp(D_800E18D2_E24D2 * 8);
        temp_s3 = func_8005484C_5544C(D_800CC280_CCE80, 6);
        var_s1_2 = D_800E18D8_E24D8;
        for (var_s2 = 0; var_s2 < D_800E18D2_E24D2; var_s2++) {
            var_s0_2 = func_8005484C_5544C(temp_s3, var_s2 * 2);
            var_s1_2->chainIndicies = *var_s0_2++;
            var_s1_2->spaces = HuMemMemoryAllocTemp(((var_s1_2->chainIndicies << 1)));
            temp_v0_3 = var_s1_2->spaces;
            for (var_v1 = 0; var_v1 < var_s1_2->chainIndicies; var_v1++) {
                *temp_v0_3++ = *var_s0_2++;
            }
            var_s1_2 += 1;
        }
        DataClose(D_800CC280_CCE80);
        func_8002D018_2DC18(1, &MBMasuDraw);
        D_800FCE90_FDA90 = 1;
    }
    D_800E1B66_E2766 = 0;
    D_800E1B88_E2788 = 0;

    return 0;
}

void func_80054AE8_556E8(void) {
    LinkData* var_s1;
    s32 i;

    if (D_800CC280_CCE80 != NULL) {
        D_800CC280_CCE80 = NULL;
        D_800FCE90_FDA90 = 0;
        HuMemMemoryFreeTemp(D_800E18D4_E24D4);

        var_s1 = D_800E18D8_E24D8;
        for (i = 0; i < D_800E18D2_E24D2; i++, var_s1++) {
            HuMemMemoryFreeTemp(var_s1->spaces);
        }

        HuMemMemoryFreeTemp(D_800E18D8_E24D8);
        func_8002D018_2DC18(1, NULL);
    }
}

SpaceData *GetSpaceData(s16 arg0) {
    return &D_800E18D4_E24D4[arg0];
}

s16 GetAbsSpaceIndexFromChainSpaceIndex(u16 chainIndex, u16 spaceIndex) {
   return D_800E18D8_E24D8[chainIndex].spaces[spaceIndex];
}

s16 BoardGetChainLength(u16 chainIndex) {
   return D_800E18D8_E24D8[chainIndex].chainIndicies;
}

s16 GetChainSpaceIndexFromAbsSpaceIndex(s16 absIndex, s32 chainIndex) {
   s32 i;
   for (i = 0; i < BoardGetChainLength(chainIndex); i++) {
      if (GetAbsSpaceIndexFromChainSpaceIndex(chainIndex, i) == absIndex) {
         return i;
      }
   }
   return SPACE_INDEX_INVALID;
}

void func_80054C78_55878(s16 arg0, s16* chainOut, s16* linkOut) {
    s32 chain;
    s32 link;

    for (chain = 0; chain < D_800E18D2_E24D2; chain++) {
        for (link = 0; link < BoardGetChainLength(chain); link++) {
            if (GetAbsSpaceIndexFromChainSpaceIndex(chain, link) == arg0) {
                *chainOut = chain;
                *linkOut = link;
                return;
            }
        }
    }
}

s32 func_80054D3C_5593C(s16 arg0, s16* arg1, s16* arg2) {
    s16 link;
    s32 i;

    for (i = 0; i < D_800E18D2_E24D2; i++) {
        if (*arg1 == i) {
            continue;
        }

        link = GetChainSpaceIndexFromAbsSpaceIndex(arg0, (s16)i);
        if (link != -1) {
            *arg1 = i;
            *arg2 = link;
            return 0;
        }
    }
    return -1;
}

void func_80054DEC_559EC(void) {
    LinkData *chain;
    s16 *space;
    s16 i;
    s16 j;
    s16 k;

    chain = D_800E18D8_E24D8;

    for (i = 0; i < D_800E18D2_E24D2; i++) {
        space = chain->spaces;

        for (j = 0; j < chain->chainIndicies; j++) {
            if (GetSpaceData(*space)->space_type == 0) {
                for (k = 0; k < 4; k++) {
                    SetPlayerOntoChain(k, i, j);
                }
                return;
            }
            space++;
        }
        chain++;
    }

    for (k = 0; k < 4; k++) {
        SetPlayerOntoChain(k, 0, 0);
    }
}

s16 BoardGetRandomSpaceTypeInChain(u16 type, u16 chainIndex) {
   u8 randByte;
   s32 i;
   SpaceData *space;
   s32 chainLen;

   chainLen = BoardGetChainLength(chainIndex);
   randByte = (rand8() % 30) + 1;

   i = 0;
   while (TRUE) {
      s16 absIndex = GetAbsSpaceIndexFromChainSpaceIndex(chainIndex, i);
      space = GetSpaceData(absIndex);

      // Get Nth space in chain of type
      if ((D_800CC570_CD170[space->space_type & 0xf] & type) != 0)
         if (--randByte == 0) {
            break;
      }
      // Wrap around
      if (++i >= chainLen) {
         i = 0;
      }
   }

   return i;
}

s16 func_80055008_55C08(u16 arg0, u8 arg1) {
    u8 var_s1;
    SpaceData* space;
    s32 i, j;
    var_s1 = 0;

    for (i = 0; i < gTotalSpaces; i++) {
        space = GetSpaceData(i);
        if (D_800CC570_CD170[space->space_type & 0xF] & arg0) {
            var_s1++;
        }
    }

    var_s1 -= D_800E1B88_E2788;
    if (arg1 < 5) {
        var_s1 -= D_800E1B66_E2766;
    }

    var_s1 = MBRand(var_s1);

    for (i = 0;; i = (++i < gTotalSpaces) ? i : 0) {
        space = GetSpaceData(i);
        for (j = 0; j < D_800E1B88_E2788; j++) {
            if (D_800E1B68_E2768[j] == i) {
                break;
            }
        }

        if (j == D_800E1B88_E2788) {
            if (arg1 < 5) {
                for (j = 0; j < D_800E1B66_E2766; j++) {
                    if (D_800E1968_E2568[j] == i) {
                        break;
                    }
                }

                if (j == D_800E1B66_E2766) {
                    if (D_800CC570_CD170[space->space_type & 0xF] & arg0) {
                        if (var_s1 == 0) {
                            break;
                        }
                        var_s1--;
                    }
                }
            } else {
                if (D_800CC570_CD170[space->space_type & 0xF] & arg0) {
                    if (var_s1 == 0) {
                        break;
                    }
                    var_s1--;
                }
            }
        }
    }
    return i;
}


void BoardSpaceTypeSet(s16 spaceIndex, u8 spaceType) {
   SpaceData *space;

   space = GetSpaceData(spaceIndex);
   space->space_type = spaceType;
}

void BoardSetSpaceTypeInChain(u16 chainIndex, u16 oldType, u8 newType) {
   s32 chainLen;
   s16 absIndex;
   SpaceData *space;
   s32 i;

   chainLen = BoardGetChainLength(chainIndex);
   for (i = 0; i < chainLen; i++) {
      absIndex = GetAbsSpaceIndexFromChainSpaceIndex(chainIndex, i);
      space = GetSpaceData(absIndex);
      if (space->space_type == oldType) {
         space->space_type = newType;
      }
   }
}

void func_800552E8_55EE8(void) {
    SpaceData* temp_v0;
    f32 temp_f22;
    f32 var_f20;
    Process* proc =  HuPrcCurrentGet();

    temp_v0 = GetSpaceData((s16)proc->user_data);
    temp_f22 = temp_v0->rot.x;
    var_f20 = temp_f22 + 0.03f;
    if (D_800CC280_CCE80 != 0) {
        while (1) {
            HuPrcVSleep();
            
            var_f20 -= 0.005f;
            if (var_f20 <= temp_f22) {
                var_f20 = temp_f22;
            }
            
            temp_v0->rot.x = var_f20;
            temp_v0->rot.z = var_f20;
            if ((var_f20 <= temp_f22) || (D_800CC280_CCE80 == 0)) {
                break;
            }            
        }

    }
    omDelPrcObj(NULL);
}

void func_800553A8_55FA8(s16 spaceIndex) {
   Process *process;
   process = omAddPrcObj(func_800552E8_55EE8, 0xEF00, 0, 0);
   process->user_data = (void *)(s32)spaceIndex;
}

void func_800553EC_55FEC(void) {
   Process *process;
   SpaceData *space;
   f32 fval;

   process = HuPrcCurrentGet();
   space = GetSpaceData((s32)process->user_data);

   fval = 1.0f;
   if (D_800CC280_CCE80 != NULL) {
      do {
         HuPrcVSleep();
         fval -= 0.1f;
         if (fval <= 0.0f) {
            fval = 0.0f;
         }

         space->rot.x = fval;
         space->rot.z = fval;
      }
      while (!(fval <= 0.0f) && D_800CC280_CCE80 != NULL);
   }

    omDelPrcObj(NULL);
}

void func_800554A8_560A8(s16 spaceIndex) {
   Process *process;
   process = omAddPrcObj(func_800553EC_55FEC, 0xEF00, 0, 0);
   process->user_data = (void *)(s32)spaceIndex;
}

void func_800554EC_560EC(void) {
   Process *process;
   SpaceData *space;
   f32 fval;

   process = HuPrcCurrentGet();
   space = GetSpaceData((s32)process->user_data);

   fval = 0.0f;
   if (D_800CC280_CCE80 != NULL) {
      do {
         HuPrcVSleep();

         fval += 0.1f;
         if (fval >= 1.0f) {
            fval = 1.0f;
         }

         space->rot.x = fval;
         space->rot.z = fval;
      } while (!(fval >= 1.0f) && D_800CC280_CCE80 != NULL);
   }

   omDelPrcObj(NULL);
}

void func_800555A8_561A8(s16 spaceIndex) {
   Process *process;
   process = omAddPrcObj(func_800554EC_560EC, 0xEF00, 0, 0);
   process->user_data = (void *)(s32)spaceIndex;
}

void func_800555EC_561EC(s16 arg0, void *arg1) {
    switch (arg0) {
        case -2:
            D_800E192C_E252C = arg1;
            break;
        case -3:
            D_800E1930_E2530 = arg1;
            break;
        case -4:
            D_800E1934_E2534 = arg1;
            break;
        case -5:
            D_800E1938_E2538 = arg1;
            break;
        default:
            GetSpaceData(arg0)->event_list = arg1;
            break;
    }
}

void EventTableHydrate(EventTableEntry *table) {
   while (table->spaceIndex != -1) {
      func_800555EC_561EC(table->spaceIndex, table->eventList);
      table++;
   }
}

s32 func_800556F4_562F4(s16 arg0, s16 arg1) {
    MbEventListEntry* entry;
    Process* proc;
    s16 prevSpace;
    s32 ret;

    if ((GwSystem.current_player_index == 4) && (arg1 != 1)) {
        return 0;
    }

    switch (arg0) {
        case -2: entry = D_800E192C_E252C; break;
        case -3: entry = D_800E1930_E2530; break;
        case -4: entry = D_800E1934_E2534; break;
        case -5: entry = D_800E1938_E2538; break;
        default: entry = GetSpaceData(arg0)->event_list; break;
    }

    ret = 0;
    prevSpace = func_800558F4_564F4();
    func_800558E8_564E8(arg0);

    if (entry != NULL) {
        while (entry->activation_type != 0) {
            if (entry->activation_type == arg1) {
                D_800E193C_E253C = 0;
                switch (entry->execution_type) {
                    case 1:
                        entry->event_fn();
                        break;
                    case 2:
                        proc = HuPrcCurrentGet();
                        HuPrcChildLink(proc, omAddPrcObj(entry->event_fn, 0x4800, 0, 0));
                        HuPrcChildWatch();
                        break;
                }
                ret |= D_800E193C_E253C;
            }
            entry++;
        }
    }

    func_800558E8_564E8(prevSpace);
    return ret;
}

INCLUDE_ASM("asm/nonmatchings/54CB0", func_800558DC_564DC);

void func_800558E8_564E8(s16 arg0) {
    GwSystem.curPlayerAbsSpaceIndex = arg0;
}

s16 func_800558F4_564F4(void) {
    return GwSystem.curPlayerAbsSpaceIndex;
}

s16 func_80055900_56500(u8 arg0) {
    return func_80055008_55C08(2, arg0);
}

void func_80055928_56528(s16 *arg0) {
    s32 i;

    for (i = 0; *arg0 != -1; i++) {
        D_800E1968_E2568[i] = *arg0++;
    }
    
    D_800E1B66_E2766 = i;
}

void func_80055980_56580(s16 *arg0) {
    s32 i;

    for (i = 0; *arg0 != -1; i++) {
        D_800E1B68_E2768[i] = *arg0++;
    }
    
    D_800E1B88_E2788 = i;
}
