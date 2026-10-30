#include "common.h"
#include "ovl_1F.h"

/* .data (0x1C6370-0x1C6760, 8010A7F0-8010ABE0). D_8010A7F2 (the seed's low half, which
   func_801074F0's (u16) cast reads) has no users of its own. D_8010A9DC's vertices end 4 bytes
   short of the display lists' 8-byte alignment. */

u32 D_8010A7F0_1C6370_DungeonDash = 0x19971204;
f32 D_8010A7F4_1C6374_DungeonDash[2] = { -280.0f, 280.0f };
Vtx_t D_8010A7FC_1C637C_DungeonDash[10] = {
    { { 20, 40, 0 }, 0, { 0, 0 }, { 0, 0, 0, 255 } },
    { { 20, -40, 0 }, 0, { 0, 4096 }, { 0, 0, 0, 255 } },
    { { -20, 40, 0 }, 0, { 2048, 0 }, { 0, 0, 0, 255 } },
    { { -20, -40, 0 }, 0, { 2048, 4096 }, { 0, 0, 0, 255 } },
    { { 0, 0, 0 }, 0, { 1024, 2048 }, { 0, 0, 0, 255 } },
    { { 20, 20, 0 }, 0, { 0, 0 }, { 0, 0, 0, 0 } },
    { { 20, 20, 0 }, 0, { 0, 0 }, { 0, 0, 0, 0 } },
    { { 20, 20, 0 }, 0, { 0, 0 }, { 0, 0, 0, 0 } },
    { { 20, 20, 0 }, 0, { 0, 0 }, { 0, 0, 0, 0 } },
    { { 20, 20, 0 }, 0, { 0, 0 }, { 0, 0, 0, 0 } },
};
Vtx_t D_8010A89C_1C641C_DungeonDash[10] = {
    { { 20, 40, 0 }, 0, { 0, 0 }, { 0, 0, 0, 255 } },
    { { 20, 0, 0 }, 0, { 0, 1984 }, { 0, 0, 0, 255 } },
    { { -20, 40, 0 }, 0, { 1984, 0 }, { 0, 0, 0, 255 } },
    { { -20, 0, 0 }, 0, { 1984, 1984 }, { 0, 0, 0, 255 } },
    { { 0, 0, 0 }, 0, { 1024, 1024 }, { 0, 0, 0, 255 } },
    { { 20, 20, 0 }, 0, { 0, 0 }, { 0, 0, 0, 0 } },
    { { 20, 20, 0 }, 0, { 0, 0 }, { 0, 0, 0, 0 } },
    { { 20, 20, 0 }, 0, { 0, 0 }, { 0, 0, 0, 0 } },
    { { 20, 20, 0 }, 0, { 0, 0 }, { 0, 0, 0, 0 } },
    { { 20, 20, 0 }, 0, { 0, 0 }, { 0, 0, 0, 0 } },
};
Vtx_t D_8010A93C_1C64BC_DungeonDash[10] = {
    { { 20, 20, 0 }, 0, { 0, 0 }, { 0, 0, 0, 255 } },
    { { 20, -20, 0 }, 0, { 0, 1984 }, { 0, 0, 0, 255 } },
    { { -20, 20, 0 }, 0, { 1984, 0 }, { 0, 0, 0, 255 } },
    { { -20, -20, 0 }, 0, { 1984, 1984 }, { 0, 0, 0, 255 } },
    { { 0, 0, 0 }, 0, { 1024, 1024 }, { 0, 0, 0, 255 } },
    { { 20, 20, 0 }, 0, { 0, 0 }, { 0, 0, 0, 0 } },
    { { 20, 20, 0 }, 0, { 0, 0 }, { 0, 0, 0, 0 } },
    { { 20, 20, 0 }, 0, { 0, 0 }, { 0, 0, 0, 0 } },
    { { 20, 20, 0 }, 0, { 0, 0 }, { 0, 0, 0, 0 } },
    { { 20, 20, 0 }, 0, { 0, 0 }, { 0, 0, 0, 0 } },
};
Vtx_t D_8010A9DC_1C655C_DungeonDash[10] = {
    { { 20, 20, 0 }, 0, { 0, 0 }, { 0, 0, 0, 255 } },
    { { 20, -20, 0 }, 0, { 0, 4032 }, { 0, 0, 0, 255 } },
    { { -20, 20, 0 }, 0, { 4032, 0 }, { 0, 0, 0, 255 } },
    { { -20, -20, 0 }, 0, { 4032, 4032 }, { 0, 0, 0, 255 } },
    { { 0, 0, 0 }, 0, { 2048, 2048 }, { 0, 0, 0, 255 } },
    { { 20, 20, 0 }, 0, { 0, 0 }, { 0, 0, 0, 0 } },
    { { 20, 20, 0 }, 0, { 0, 0 }, { 0, 0, 0, 0 } },
    { { 20, 20, 0 }, 0, { 0, 0 }, { 0, 0, 0, 0 } },
    { { 20, 20, 0 }, 0, { 0, 0 }, { 0, 0, 0, 0 } },
    { { 20, 20, 0 }, 0, { 0, 0 }, { 0, 0, 0, 0 } },
};
Gfx D_8010AA80_1C6600_DungeonDash[] = {
    gsSPSegment(0x00, 0x00000000),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPPipelineMode(G_PM_1PRIMITIVE),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0, 0),
    gsDPSetTileSize(1, 0, 0, 0, 0),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0000, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetDepthSource(G_ZS_PIXEL),
    gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
    gsDPNoOp(),
    gsDPSetColorDither(G_CD_DISABLE),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
Gfx D_8010AB38_1C66B8_DungeonDash[] = {
    gsSPClearGeometryMode(0xFFFFFFFF),
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_OFF),
    gsSPSetGeometryMode(G_SHADE | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};
Gfx D_8010AB58_1C66D8_DungeonDash[] = {
    gsSPDisplayList(D_8010AB38_1C66B8_DungeonDash),
    gsSPDisplayList(D_8010AA80_1C6600_DungeonDash),
    gsSPEndDisplayList(),
};
Gfx D_8010AB70_1C66F0_DungeonDash[] = {
    gsDPPipeSync(),
    gsSPDisplayList(D_8010AB58_1C66D8_DungeonDash),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPSetGeometryMode(G_ZBUFFER | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsDPSetBlendColor(0x00, 0x00, 0x00, 0x00),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0xFF),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPEndDisplayList(),
};
u32 D_8010ABB0_1C6730_DungeonDash = 0;
u32 D_8010ABB4_1C6734_DungeonDash = 0;
s16 D_8010ABB8_1C6738_DungeonDash = 60;
s16 D_8010ABBA_1C673A_DungeonDash = 20;
s16 D_8010ABBC_1C673C_DungeonDash = 0;
s16 D_8010ABBE_1C673E_DungeonDash = 0;
f32 D_8010ABC0_1C6740_DungeonDash[2][2] = { { 0.0f, 0.0f }, { 0.0f, 0.0f } };
s32 D_8010ABD0_1C6750_DungeonDash = 0;

void func_801071C0_1C2D40_DungeonDash(omObjData* obj) {
    obj->func_ptr = func_80107290_1C2E10_DungeonDash;
    func_80026DAC_279AC(0, 0x50, 0x50, 0x50);
    func_80026DAC_279AC(1, 0x80, 0x80, 0x80);
    func_80026E00_27A00(1, -96.0f, 100.0f, 26.0f);
    func_8002C59C_2D19C(0x3B6, 0x3E8, 0, 0, 0);
    func_80020D20_21920(0x40);
    func_80107560_1C30E0_DungeonDash(rand8());
    func_8010764C_1C31CC_DungeonDash();
    D_8010B2BA_1C6E3A_DungeonDash = 1;
    D_8010B2BC_1C6E3C_DungeonDash = 1;
    D_8010B2BE_1C6E3E_DungeonDash = 0;
    D_8010B2D2_1C6E52_DungeonDash = 0;
    D_8010B2D0_1C6E50_DungeonDash = 0;
    D_8010B2A8_1C6E28_DungeonDash = 0;
    D_8010B2A6_1C6E26_DungeonDash = 0;
}

/* Course driver: after 80 frames the race starts; for 120 frames it releases the obstacles. */
void func_80107290_1C2E10_DungeonDash(void) {
    DDObstacle* o;
    u16 i;

    o = D_8010B2E4_1C6E64_DungeonDash;
    func_80108574_1C40F4_DungeonDash();
    func_80108F9C_1C4B1C_DungeonDash();
    if (D_8010ABB0_1C6730_DungeonDash < 80) {
        if (++D_8010ABB0_1C6730_DungeonDash == 80) {
            D_8010B2BA_1C6E3A_DungeonDash = 1;
            D_8010B2BC_1C6E3C_DungeonDash = 0;
        }
    } else if (D_8010ABB4_1C6734_DungeonDash < 120) {
        for (i = 0; i < 5; i++, o++) {
            if (o->unk2 != 0 && o->unk0 != 0) {
                o->unk2 = 0;
            }
        }
        D_8010ABB4_1C6734_DungeonDash++;
    }
}

void func_80107350_1C2ED0_DungeonDash(void) {
}

/* The start banner: x is the split position (320 = full). */
// register allocation only (the D_8010ABB8 load goes to v1 in retail)
#ifdef NON_MATCHING
void func_80107358_1C2ED8_DungeonDash(s16 x) {
    s16* grp;

    if (D_8010B2BE_1C6E3E_DungeonDash != 0) {
        if (D_8010ABB8_1C6738_DungeonDash > 0) {
            if (func_8008F618_90218() == 0) {
                D_8010ABB8_1C6738_DungeonDash--;
            }
        } else if (D_8010ABBA_1C673A_DungeonDash > 0) {
            D_8010ABBA_1C673A_DungeonDash--;
        }
        grp = &D_8010B2B2_1C6E32_DungeonDash[2];
        SprPosSet(*grp, 0, x, 120);
        if (x == 320 && D_8010ABBC_1C673C_DungeonDash == 0) {
            SprAttrSet(*grp, 0, 0x9000);
            D_8010ABBC_1C673C_DungeonDash = 1;
        } else if (x < 320 && D_8010ABBE_1C673E_DungeonDash == 0) {
            SprAttrReset(D_8010B2B2_1C6E32_DungeonDash[2], 0, 0x8000);
            D_8010ABBE_1C673E_DungeonDash = 1;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1C2D40", func_80107358_1C2ED8_DungeonDash);
#endif

s32 func_80107484_1C3004_DungeonDash(void) {
    return D_8010B2D0_1C6E50_DungeonDash != 0;
}

s32 func_80107494_1C3014_DungeonDash(void) {
    if (D_8010B2D0_1C6E50_DungeonDash == 1) {
        D_8010B2D0_1C6E50_DungeonDash = 2;
    }
    return 1;
}

void func_801074BC_1C303C_DungeonDash(void) {
    if (D_8010B2D2_1C6E52_DungeonDash == 0) {
        D_8010B2D2_1C6E52_DungeonDash = 1;
        PlaySound(0x23F);
    }
}

/* The overlay's own random generator (D_8010A7F0). */
u16 func_801074F0_1C3070_DungeonDash(u16 range) {
    D_8010A7F0_1C6370_DungeonDash = (D_8010A7F0_1C6370_DungeonDash * 0x19971204 + 0x19760831) >> 16;
    if (range == 0) {
        return (u16)D_8010A7F0_1C6370_DungeonDash;
    }
    return D_8010A7F0_1C6370_DungeonDash % range;
}

void func_80107560_1C30E0_DungeonDash(u8 seed) {
    D_8010A7F0_1C6370_DungeonDash = seed + seed * D_8010A7F0_1C6370_DungeonDash;
}

void func_80107584_1C3104_DungeonDash(DDObstacle* o) {
    s32 pad[4]; /* retail's 16-byte frame */

    o->unk4 = 3;
    o->unk14 = 15.0f;
}

void func_801075A8_1C3128_DungeonDash(s16 sound, f32 pan) {
    if (sound >= 0) {
        if (pan > 0.0) {
            func_800798F8_7A4F8(sound, 0x60);
        } else {
            func_800798F8_7A4F8(sound, 0x20);
        }
    }
}

u16 func_80107608_1C3188_DungeonDash(s32 file) {
    void* data;
    u16 ret;

    data = DataRead(file);
    ret = SprAnimRead(data);
    DataClose(data);
    return ret;
}

void func_8010764C_1C31CC_DungeonDash(void) {
    HuSprite_Unk84_Unk00_Struct* frame;

    D_8010B288_1C6E08_DungeonDash[0] = D_800FC7B0_FD3B0[0] = omAddObj(2, 0, 0, -1, func_801077C8_1C3348_DungeonDash);
    omSetStatBit(D_8010B288_1C6E08_DungeonDash[0], 0xA0);
    D_8010B288_1C6E08_DungeonDash[0]->work[0] = 1;
    D_8010B288_1C6E08_DungeonDash[0]->work[1] = 0;
    D_8010B288_1C6E08_DungeonDash[1] = D_800FC7B0_FD3B0[1] = omAddObj(3, 0, 0, -1, func_801077C8_1C3348_DungeonDash);
    omSetStatBit(D_8010B288_1C6E08_DungeonDash[1], 0xA0);
    D_8010B288_1C6E08_DungeonDash[1]->work[0] = 2;
    D_8010B288_1C6E08_DungeonDash[1]->work[1] = 1;
    D_8010B288_1C6E08_DungeonDash[2] = D_800FC7B0_FD3B0[2] = omAddObj(4, 6, 0, -1, func_80107C6C_1C37EC_DungeonDash);
    omSetStatBit(D_8010B288_1C6E08_DungeonDash[2], 0xA0);
    D_8010B2AA_1C6E2A_DungeonDash[1] = func_80107608_1C3188_DungeonDash(0x2F000A);
    D_8010B2AA_1C6E2A_DungeonDash[2] = func_80107608_1C3188_DungeonDash(0x2F000F);
    frame = D_800F60B0_F6CB0[D_8010B2AA_1C6E2A_DungeonDash[2]]->unk00;
    frame->unk0A = 0;
    frame->unk08 = 0;
    frame->unk06 = frame->unk04;
    D_8010B2C0_1C6E40_DungeonDash[0] = D_8010B2C0_1C6E40_DungeonDash[1] = 0.0;
}

/* A team's curtain sprite (work[0] = camera group, work[1] = team). */
void func_801077C8_1C3348_DungeonDash(omObjData* obj) {
    s32 w;

    obj->func_ptr = func_801078BC_1C343C_DungeonDash;
    obj->trans.x = obj->trans.y = 0.0f;
    w = obj->work[1];
    D_8010B2B2_1C6E32_DungeonDash[(u16)w] = SprCreate(1, 0);
    SprAnimSet(D_8010B2B2_1C6E32_DungeonDash[(u16)w], 0, D_8010B2AA_1C6E2A_DungeonDash[2], 0);
    SprAttrSet(D_8010B2B2_1C6E32_DungeonDash[(u16)w], 0, 0x103C);
    SprPrioSet(D_8010B2B2_1C6E32_DungeonDash[(u16)w], 0, w - 16);
    SprPosSet(D_8010B2B2_1C6E32_DungeonDash[(u16)w], 0, (u16)w * 160, 0);
    SprScaleSet(D_8010B2B2_1C6E32_DungeonDash[(u16)w], 0, 5.0f, 7.5f);
    func_80082488_83088(D_8010B2B2_1C6E32_DungeonDash[(u16)w], 0, 0x20);
}

/* Fades a team's curtain: closing as its team nears the goal, open for the start, gone at the end. */
// KMC mul fix: retail has no nop between the HuMathSin call's delay slot and the first mul.s
#ifdef NON_MATCHING
void func_801078BC_1C343C_DungeonDash(omObjData* obj) {
    f32* a;
    f32* step;
    s32 t;
    f32 d;
    f32 s;

    t = obj->work[1];
    a = &D_8010ABC0_1C6740_DungeonDash[0][t];
    step = &D_8010ABC0_1C6740_DungeonDash[1][t];
    if (D_8010B2BC_1C6E3C_DungeonDash == 0 && D_8010B2BA_1C6E3A_DungeonDash != 0) {
        d = fabs(D_8010B2C0_1C6E40_DungeonDash[t]) - 3450.0;
        if (d > 0.0) {
            s = HuMathSin(d / 1150.0 * 90.0);
            *a = s * s * s * 128.0f;
            func_80082488_83088(D_8010B2B2_1C6E32_DungeonDash[t], 0, (s32)*a);
        }
    } else if (D_8010B2BA_1C6E3A_DungeonDash == 0 && D_8010B2D0_1C6E50_DungeonDash == 0) {
        if (*step == 0.0) {
            *step = 256.0 - *a;
        }
        *a = *a + *step * 0.15;
        if (*a > 256.0) {
            *a = 256.0f;
        }
        if (D_8010ABC0_1C6740_DungeonDash[0][0] >= 256.0 && D_8010ABC0_1C6740_DungeonDash[0][1] >= 256.0) {
            if (++D_8010ABD0_1C6750_DungeonDash >= 31) {
                D_8010B2D0_1C6E50_DungeonDash = 1;
            }
        }
        func_80082488_83088(D_8010B2B2_1C6E32_DungeonDash[t], 0, (s32)*a);
        func_80082488_83088(D_8010B2B2_1C6E32_DungeonDash[2], 0, 256.0 - (s32)*a);
    } else if (D_8010B2D0_1C6E50_DungeonDash == 2 && *a > 0.0) {
        *a = *a - 38.4;
        if (*a < 0.0) {
            *a = 0.0f;
        }
        func_80082488_83088(D_8010B2B2_1C6E32_DungeonDash[0], 0, (s32)*a);
        func_80082488_83088(D_8010B2B2_1C6E32_DungeonDash[1], 0, (s32)*a);
    } else if (D_8010B2D0_1C6E50_DungeonDash == 2) {
        SprAttrSet(D_8010B2B2_1C6E32_DungeonDash[0], 0, 0x8000);
        SprAttrSet(D_8010B2B2_1C6E32_DungeonDash[1], 0, 0x8000);
        SprAttrSet(D_8010B2B2_1C6E32_DungeonDash[2], 0, 0x8000);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1C2D40", func_801078BC_1C343C_DungeonDash);
#endif

/* The dungeon scenery: walls, gate, the far glow, six torches, the obstacles and the start banner. */
// FPR allocation only (torch z: f0/f2 swapped); the goto loop keeps GCC from hoisting the 0.0f arguments
#ifdef NON_MATCHING
void func_80107C6C_1C37EC_DungeonDash(omObjData* obj) {
    DDTorch* e;
    u16 i;
    s32 r;

    obj->func_ptr = func_80108054_1C3BD4_DungeonDash;
    obj->model[0] = LoadFormFile(0x2F0000, 0x99);
    obj->model[1] = LoadFormFile(0x2F0001, 0x9D);
    obj->model[2] = LoadFormFile(0x2F0002, 0xBD);
    func_80029714_2A314(obj->model[2], 0.0f, 400.0f, 50.0f);
    obj->model[3] = LoadFormFile(0x2F0003, 0xB9);
    D_8010B2AA_1C6E2A_DungeonDash[0] = func_80107608_1C3188_DungeonDash(0x2F000E);
    obj->model[4] = func_80109958_1C54D8_DungeonDash(D_8010A89C_1C641C_DungeonDash,
                                                     SprAnimGet(D_8010B2AA_1C6E2A_DungeonDash[0]), 1);
    func_80029714_2A314(obj->model[4], 0.0f, -20.0f, -4600.0f);
    func_800297E8_2A3E8(obj->model[4], 20.0f, 20.0f, 1.0f);
    obj->model[5] = LoadFormFile(0x2F0008, 0x99);
    func_80029714_2A314(obj->model[5], 0.0f, 3.0f, -700.0f);
    func_800297E8_2A3E8(obj->model[5], 1.0f, 1.0f, 0.4f);
    e = D_8010B29C_1C6E1C_DungeonDash = func_80027154_27D54(0x90, D_800FA1AA_FADAA);
    func_800B0EF0_B1AF0(e, 0, 0x90);
    D_8010B2AA_1C6E2A_DungeonDash[3] = func_80107608_1C3188_DungeonDash(0x2F0010);
    i = 0;
loop:
    {
        if (i == 0) {
            e->model = func_80109958_1C54D8_DungeonDash(D_8010A93C_1C64BC_DungeonDash,
                                                        SprAnimGet(D_8010B2AA_1C6E2A_DungeonDash[3]), 2);
        } else {
            e->model = func_8010A430_1C5FB0_DungeonDash(-1, D_8010B29C_1C6E1C_DungeonDash->model);
        }
        e->unk2 = (rand8() + rand8()) % 360;
        e->unk8 = 5.0f;
        if (i & 1) {
            e->unk4 = -45.0f;
            e->x = 525.0f;
        } else {
            e->unk4 = 45.0f;
            e->x = -525.0f;
        }
        e->y = 425.0f;
        e->z = -550.0 - 1000.0 * ((i + 2) >> 1);
        func_80029714_2A314(e->model, e->x, e->y, e->z);
        i++;
        func_8002979C_2A39C(e->model, 0.0f, e->unk4, 0.0f);
        func_800297E8_2A3E8(e->model, e->unk8, e->unk8, 1.0f);
        e++;
        if (i < 6) {
            goto loop;
        }
    }
    func_801083B0_1C3F30_DungeonDash(2);
    func_80108C8C_1C480C_DungeonDash();
    D_8010B2B2_1C6E32_DungeonDash[2] = SprCreate(1, 0);
    SprAnimSet(D_8010B2B2_1C6E32_DungeonDash[2], 0, D_8010B2AA_1C6E2A_DungeonDash[1], 0);
    SprAttrSet(D_8010B2B2_1C6E32_DungeonDash[2], 0, 0x1000);
    SprScaleSet(D_8010B2B2_1C6E32_DungeonDash[2], 0, 1.0f, 1.0f);
    SprPosSet(D_8010B2B2_1C6E32_DungeonDash[2], 0, 160, 120);
    SprPrioSet(D_8010B2B2_1C6E32_DungeonDash[2], 0, 0x7FF0);
    D_8010B2BE_1C6E3E_DungeonDash = 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1C2D40", func_80107C6C_1C37EC_DungeonDash);
#endif

void func_80108054_1C3BD4_DungeonDash(omObjData* obj) {
    DDTorch* e;
    s32 i;

    e = D_8010B29C_1C6E1C_DungeonDash;
    if (func_80078EA8_79AA8() + D_80102720_103320 != 0) {
        return;
    }
    if (D_8010B2BA_1C6E3A_DungeonDash == 0 && D_8010B2BC_1C6E3C_DungeonDash == 0 && D_8010B2D0_1C6E50_DungeonDash != 0) {
        func_800298A4_2A4A4(obj->model[0], 4, 4);
        func_800298A4_2A4A4(obj->model[1], 4, 0);
        func_800298A4_2A4A4(obj->model[2], 4, 0);
        func_800298A4_2A4A4(obj->model[3], 4, 4);
        func_800298A4_2A4A4(obj->model[4], 4, 4);
        func_800298A4_2A4A4(obj->model[5], 4, 4);
        for (i = 0; i < 6; i++, e++) {
            func_800298A4_2A4A4(e->model, 4, 4);
        }
        if (D_8010B2D2_1C6E52_DungeonDash == 1) {
            if ((D_800FC834_FD434[obj->model[2]].pos.y -= 12.5) < -30.0) {
                D_800FC834_FD434[obj->model[2]].pos.y = -30.0f;
                D_8010B2D2_1C6E52_DungeonDash = 2;
                PlaySound(0x240);
            }
        }
    } else {
        func_8010A340_1C5EC0_DungeonDash(obj->model[4], SprAnimGet(D_8010B2AA_1C6E2A_DungeonDash[0]), 0);
        for (i = 0; i < 6; i++, e++) {
            e->unk2 += 30;
            if (e->unk2 >= 360) {
                e->unk2 -= 360;
            }
            e->unk8 = HuMathSin(e->unk2) * 0.3 + 5.0;
            func_800297E8_2A3E8(e->model, e->unk8, e->unk8, 1.0f);
            if (i == 0) {
                func_8010A340_1C5EC0_DungeonDash(e->model, SprAnimGet(D_8010B2AA_1C6E2A_DungeonDash[3]), 0);
            } else {
                func_8010A430_1C5FB0_DungeonDash(e->model, D_8010B29C_1C6E1C_DungeonDash->model);
            }
        }
    }
}

/* Records team t's z; 1 when it reached the goal. */
s32 func_80108308_1C3E88_DungeonDash(u16 team, f32 z) {
    if (team >= 2) {
        return 0;
    }
    D_8010B2C0_1C6E40_DungeonDash[team] = z;
    func_80108A14_1C4594_DungeonDash(team, z);
    func_80109884_1C5404_DungeonDash(team, z);
    if (z <= -4600.0) {
        D_8010B2BA_1C6E3A_DungeonDash = 0;
        return 1;
    }
    return 0;
}

void func_801083A8_1C3F28_DungeonDash(void) {
}

void func_801083B0_1C3F30_DungeonDash(u16 n) {
    DDObstacle* o;
    u16 i;

    o = D_8010B2E4_1C6E64_DungeonDash = func_80027154_27D54(0xB4, D_800FA1AA_FADAA);
    func_800B0EF0_B1AF0(o, 0, 0xB4);
    if (n >= 6) {
        n = 5;
    }
    for (i = 0; i < 5; i++, o++) {
        o->unk0 = 0;
        if (i < n) {
            o->unk0 = 1;
            func_80107584_1C3104_DungeonDash(o);
            o->unk2 = 1;
            o->x = D_8010A7F4_1C6374_DungeonDash[i & 1];
            o->y = 0.0f;
            o->z = -3250.0f;
            if (i == 0) {
                o->unk6 = LoadFormFile(0x800BD, 0x99);
                o->unk8 = LoadFormFile(0x2F0005, 0x499);
            } else {
                o->unk6 = func_80027D3C_2893C(D_8010B2E4_1C6E64_DungeonDash->unk6);
                o->unk8 = func_80027D3C_2893C(D_8010B2E4_1C6E64_DungeonDash->unk8);
            }
            o->unkA = LoadFormFile(0xB, 0x499);
            func_800298A4_2A4A4(o->unkA, 4, 4);
            func_80029EDC_2AADC(o->unk6, 3);
            func_80029EDC_2AADC(o->unk8, 3);
            D_800FC834_FD434[o->unkA].unk44 = 1.0f;
        }
    }
    D_8010B2A6_1C6E26_DungeonDash = 1;
}

/* Moves the obstacles up and down; plays the slam sound for the teams that see one land. */
// MP1 func_800FAFD4's residue: loop-head branch layout (bnez/j where retail has beqzl) and FP constant registers
#ifdef NON_MATCHING
void func_80108574_1C40F4_DungeonDash(void) {
    DDObstacle* o;
    u16 i;
    u16 j;
    f32 v;
    s32 vol;
    s16 h;
    f32 s;
    s16 bit;

    i = 0;
    if (D_8010B2A6_1C6E26_DungeonDash == 0) {
        return;
    }
    o = D_8010B2E4_1C6E64_DungeonDash;
    do {
        if (o->unk0 == 0) {
            i++;
        } else {
        switch (o->unk4) {
            case 2:
                o->y = 0.0f;
                if (o->unk14 <= 0.0f) {
                    o->unk14 = 180.0f;
                    o->unk4 = 0;
                }
                break;
            case 0:
                o->y = 440.0f - o->unk14 / 180.0f * 440.0f;
                if (o->unk14 <= 0.0f) {
                    o->unk14 = 30.0f;
                    o->unk4 = 3;
                }
                break;
            case 3:
                o->y = 440.0f;
                if (o->unk14 <= 0.0f) {
                    o->unk14 = 5.0f;
                    o->unk4 = 1;
                }
                if (o->unk2 == 0 && D_8010B2BA_1C6E3A_DungeonDash != 0) {
                    o->unk14 -= 1.0f;
                }
                goto place;
            case 1:
                o->y = o->unk14 / 5.0f * 440.0f;
                if (o->unk14 <= 0.0f) {
                    o->y = 0.0f;
                    o->unk14 = 30.0f;
                    o->unk4 = 2;
                    for (j = 0; j < 2; j++) {
                        if (!(i & 1)) {
                            bit = 1 << j;
                            if (bit & D_800FC834_FD434[o->unk6].unk01) {
                                v = 1.0 - (f32)fabs(D_8010B2C0_1C6E40_DungeonDash[j] + 200.0 - o->z) / 2300.0;
                                if (v > 1.0) {
                                    v = 1.0f;
                                } else if (v < 0.0) {
                                    v = 0.0f;
                                }
                                vol = v * 57.0 + 70.0;
                                if (j == 0) {
                                    h = func_80079798_7A398(0x237, 6);
                                } else {
                                    h = func_80079798_7A398(0x237, 7);
                                }
                                if (h != -1) {
                                    func_800795D8_7A1D8(h, vol);
                                    func_801075A8_1C3128_DungeonDash(h, D_8010A7F4_1C6374_DungeonDash[j & 1]);
                                }
                            }
                        }
                    }
                    func_80108B54_1C46D4_DungeonDash(o->unkA);
                }
                break;
            default:
                goto place;
        }
        if (o->unk2 == 0) {
            o->unk14 -= 1.0f;
        }
    place:
        func_80029714_2A314(o->unk6, o->x, o->y, o->z);
        func_800297E8_2A3E8(o->unk6, 2.0f, 2.0f, 1.0f);
        if (D_8010B2D0_1C6E50_DungeonDash < 2) {
            func_80029714_2A314(o->unk8, o->x, 20.0f, o->z);
            s = 1.0 - o->y / 440.0f / 3.0;
            func_800297E8_2A3E8(o->unk8, 2.0 * s, 1.0f, s);
        } else {
            func_800298A4_2A4A4(o->unk8, 4, 4);
        }
        func_80029714_2A314(o->unkA, o->x, 2.0f, o->z);
        i++;
        func_800297E8_2A3E8(o->unkA, 3.0f, 3.0f, 3.0f);
        func_80108BFC_1C477C_DungeonDash(o->unkA);
        }
        o++;
    } while (i < 5);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1C2D40", func_80108574_1C40F4_DungeonDash);
#endif

/* Hides the obstacles behind team t's camera, shows those ahead (bit t of the model flags). */
// register allocation: retail hoists 1 << team into t0 and copies it per branch (MP1 func_800FB4F8's residue)
#ifdef NON_MATCHING
void func_80108A14_1C4594_DungeonDash(s32 team, f32 z) {
    DDObstacle* o;
    u16 i;
    s32 bit;

    o = D_8010B2E4_1C6E64_DungeonDash;
    if (D_8010B2A6_1C6E26_DungeonDash == 0) {
        return;
    }
    for (i = 0; i < 5; i++, o++) {
        if (o->unk0 != 0 && D_8010B2BC_1C6E3C_DungeonDash == 0) {
            if (o->z > z + 200.0) {
                bit = 1 << team;
                if (D_800FC834_FD434[o->unk6].unk01 & (u16)bit) {
                    D_800FC834_FD434[o->unk6].unk01 ^= bit;
                    D_800FC834_FD434[o->unk8].unk01 ^= bit;
                }
            } else {
                bit = 1 << team;
                D_800FC834_FD434[o->unk6].unk01 |= bit;
                D_800FC834_FD434[o->unk8].unk01 |= bit;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1C2D40", func_80108A14_1C4594_DungeonDash);
#endif

void func_80108B54_1C46D4_DungeonDash(s16 mdl) {
    f32 end;

    end = func_80029CE4_2A8E4(mdl);
    if (func_80029D0C_2A90C(mdl) <= end) {
        if (D_800FC834_FD434[mdl].hmf->unk9C != NULL) {
            D_800FC834_FD434[mdl].hmf->unk9C->unk08 = 0.0f;
        }
        func_80029C74_2A874(mdl, 0.0f);
    }
    func_800298A4_2A4A4(mdl, 4, 0);
}

void func_80108BFC_1C477C_DungeonDash(s16 mdl) {
    f32 end;

    if (mdl != -1 && !(D_800FC834_FD434[mdl].unk18 & 4)) {
        end = func_80029CE4_2A8E4(mdl);
        if (func_80029D0C_2A90C(mdl) <= end) {
            func_800298A4_2A4A4(mdl, 4, 4);
        }
    }
}

/* The two swinging blades (D_8010B2E0). */
void func_80108C8C_1C480C_DungeonDash(void) {
    DDBlock* b;
    u16 i;
    u16 anim0;
    u16 anim1;
    u16 anim2;
    f32 d[2];

    D_8010B2A0_1C6E20_DungeonDash = anim0 = func_80107608_1C3188_DungeonDash(0x2F0011);
    D_8010B2A2_1C6E22_DungeonDash = anim1 = func_80107608_1C3188_DungeonDash(0x2F0009);
    D_8010B2A4_1C6E24_DungeonDash = anim2 = func_80107608_1C3188_DungeonDash(0x2F0012);
    b = D_8010B2E0_1C6E60_DungeonDash = func_80027154_27D54(0x40, D_800FA1AA_FADAA);
    func_800B0EF0_B1AF0(b, 0, 0x40);
    for (i = 0; i < 2; i++, b++) {
        b->unk0 = 1;
        b->unk2 = 60;
        if (i & 1) {
            b->unk4 = 0;
            b->unk10 = 0.0f;
            b->x = 280.0f;
        } else {
            b->unk4 = 2;
            b->unk10 = 180.0f;
            b->x = -280.0f;
        }
        b->y = -200.0f;
        b->unk1C = -2100.0f;
        if (i == 0) {
            b->unk6 = func_80109958_1C54D8_DungeonDash(D_8010A7FC_1C637C_DungeonDash, SprAnimGet(anim0), 0);
            b->unkA = func_80109958_1C54D8_DungeonDash(D_8010A93C_1C64BC_DungeonDash, SprAnimGet(anim1), 4);
        } else {
            b->unk6 = func_8010A430_1C5FB0_DungeonDash(-1, D_8010B2E0_1C6E60_DungeonDash->unk6);
            b->unkA = func_8010A430_1C5FB0_DungeonDash(-1, D_8010B2E0_1C6E60_DungeonDash->unkA);
        }
        func_800297E8_2A3E8(b->unk6, 2.8f, 2.8f, 1.0f);
        func_800297E8_2A3E8(b->unkA, 4.8f, 4.8f, 1.0f);
        func_8002979C_2A39C(b->unkA, 270.0f, 0.0f, 0.0f);
        b->unk8 = func_80109958_1C54D8_DungeonDash(D_8010A9DC_1C655C_DungeonDash, SprAnimGet(anim2), 5);
        func_800298A4_2A4A4(b->unk8, 4, 4);
        func_800297E8_2A3E8(b->unk8, 7.28f, 7.28f, 1.0f);
        d[0] = func_800B7890_B8490(b->unk10) * (2.2 * 100.0);
        d[1] = HuMathSin(b->unk10) * 350.0;
        func_80029714_2A314(b->unk6, b->x + d[0], b->y + d[1], b->unk1C);
        func_8002979C_2A39C(b->unk6, 90.0f, 0.0f, 0.0f);
    }
    D_8010B2A8_1C6E28_DungeonDash = 1;
}

/* Swings the two blades: down (0), rest (1, slam sound), back (2), rest (3, slam sound). */
void func_80108F9C_1C4B1C_DungeonDash(void) {
    DDBlock* b;
    u16 i;
    s16 frame;
    f32 scale;
    HuSprite_Unk84_Struct* anim1;
    HuSprite_Unk84_Struct* anim2;
    HuSprite_Unk84_Struct* anim0;
    f32 d[4];
    s32 h;
    f32 v;
    f32 t;
    f32 sc;

    b = D_8010B2E0_1C6E60_DungeonDash;
    scale = 4.8f;
    frame = 0;
    if (D_8010B2A8_1C6E28_DungeonDash == 0) {
        return;
    }
    if (D_8010B280_1C6E00_DungeonDash++ >= 15) {
        D_8010B280_1C6E00_DungeonDash = 0;
    }
    anim0 = SprAnimGet(D_8010B2A0_1C6E20_DungeonDash);
    anim1 = SprAnimGet(D_8010B2A2_1C6E22_DungeonDash);
    anim2 = SprAnimGet(D_8010B2A4_1C6E24_DungeonDash);
    for (i = 0; i < 2; i++, b++) {
        if (b->unk0 == 0) {
            continue;
        }
        if (i == 0) {
            func_8010A340_1C5EC0_DungeonDash(b->unk6, anim0, D_8010B280_1C6E00_DungeonDash);
            func_8010A340_1C5EC0_DungeonDash(b->unkA, anim1, 0);
        } else {
            func_8010A430_1C5FB0_DungeonDash(b->unk6, D_8010B2E0_1C6E60_DungeonDash->unk6);
            func_8010A430_1C5FB0_DungeonDash(b->unkA, D_8010B2E0_1C6E60_DungeonDash->unkA);
        }
        if (b->unkC < 16) {
            frame = b->unkC;
        }
        func_8010A340_1C5EC0_DungeonDash(b->unk8, anim2, frame);
        if (b->unk2 > 0) {
            b->unk2--;
            continue;
        }
        d[0] = func_800B7890_B8490(b->unk10) * (2.2 * 100.0);
        d[1] = HuMathSin(b->unk10) * 350.0;
        func_80029714_2A314(b->unk6, b->x + d[0], b->y + d[1], b->unk1C);
        d[2] = b->unk10;
        if (b->unk4 == 0) {
            d[2] = d[2] + 180.0;
        }
        func_8002979C_2A39C(b->unk6, 0.0f, 0.0f, d[2]);
        switch (b->unk4) {
            case 0:
                if (++b->unkC >= 16) {
                    func_800298A4_2A4A4(b->unk8, 4, 4);
                }
                b->unk10 += 6.0;
                if (b->unk10 >= 180.0) {
                    if (D_8010B2D0_1C6E50_DungeonDash == 0) {
                        func_800298A4_2A4A4(b->unk8, 4, 0);
                        func_80029714_2A314(b->unk8, b->x + d[0], b->y + 10.0, b->unk1C);
                    }
                    b->unk10 = 180.0f;
                    b->unkC = 0;
                    b->unk4++;
                }
                break;
            case 1:
                if (++b->unkC < 60 && D_8010B2D0_1C6E50_DungeonDash == 0) {
                    func_800298A4_2A4A4(b->unk6, 4, 4);
                    if (b->unkC >= 16) {
                        func_800298A4_2A4A4(b->unk8, 4, 4);
                    }
                } else {
                    func_800298A4_2A4A4(b->unk6, 4, 0);
                    b->unk4++;
                    b->unkC = 0;
                    func_800298A4_2A4A4(b->unk8, 4, 0);
                    func_80029714_2A314(b->unk8, b->x + d[0], b->y + 10.0, b->unk1C);
                    if (D_8010B2BA_1C6E3A_DungeonDash != 0) {
                        h = PlaySound(0x23E);
                        if ((s16)h >= 0) {
                            func_801075A8_1C3128_DungeonDash(h, b->x);
                            v = 1.0 - (f32)fabs(D_8010B2C0_1C6E40_DungeonDash[i & 1] - b->unk1C) / 2300.0;
                            if (v < 0.0) {
                                v = 0.0f;
                            } else if (v > 1.0) {
                                v = 1.0f;
                            }
                            func_800795D8_7A1D8(h, v * 20.0f + 107.0f);
                        }
                    }
                }
                break;
            case 2:
                if (++b->unkC >= 16) {
                    func_800298A4_2A4A4(b->unk8, 4, 4);
                }
                b->unk10 -= 6.0;
                if (b->unk10 <= 0.0) {
                    if (D_8010B2D0_1C6E50_DungeonDash == 0) {
                        func_800298A4_2A4A4(b->unk8, 4, 0);
                        func_80029714_2A314(b->unk8, b->x + d[0], b->y + 10.0, b->unk1C);
                    }
                    b->unk10 = 0.0f;
                    b->unkC = 0;
                    b->unk4++;
                }
                break;
            case 3:
                if (++b->unkC < 60 && D_8010B2D0_1C6E50_DungeonDash == 0) {
                    func_800298A4_2A4A4(b->unk6, 4, 4);
                    if (b->unkC >= 16) {
                        func_800298A4_2A4A4(b->unk8, 4, 4);
                    }
                } else {
                    func_800298A4_2A4A4(b->unk6, 4, 0);
                    b->unk4 = 0;
                    b->unkC = 0;
                    func_800298A4_2A4A4(b->unk8, 4, 0);
                    func_80029714_2A314(b->unk8, b->x + d[0], b->y + 10.0, b->unk1C);
                    if (D_8010B2BA_1C6E3A_DungeonDash != 0) {
                        h = PlaySound(0x23E);
                        if ((s16)h >= 0) {
                            func_801075A8_1C3128_DungeonDash(h, b->x);
                            v = 1.0 - (f32)fabs(D_8010B2C0_1C6E40_DungeonDash[i & 1] - b->unk1C) / 2300.0;
                            if (v < 0.0) {
                                v = 0.0f;
                            } else if (v > 1.0) {
                                v = 1.0f;
                            }
                            func_800795D8_7A1D8(h, v * 20.0f + 107.0f);
                        }
                    }
                }
                break;
            case 0xFF:
                func_800298A4_2A4A4(b->unk6, 4, 4);
                break;
        }
        func_80029714_2A314(b->unkA, b->x + d[0], 6.0f, b->unk1C);
        if (b->unk10 > 27.0 && b->unk10 < 153.0 && D_8010B2D0_1C6E50_DungeonDash == 0) {
            if (b->unk10 > 27.0 && b->unk10 < 37.0) {
                scale = scale * ((b->unk10 - 27.0) / 10.0);
            } else if (b->unk10 < 153.0 && b->unk10 > 143.0) {
                scale = scale * (1.0 - (b->unk10 - 143.0) / 10.0);
            }
            func_800298A4_2A4A4(b->unkA, 4, 0);
        } else {
            func_800298A4_2A4A4(b->unkA, 4, 4);
        }
        t = func_800B0D98_B1998(b->unk10, 16.0);
        t = t / 16.0;
        sc = scale + (f32)(HuMathSin(t * 180.0) * 0.5);
        func_800297E8_2A3E8(b->unkA, sc, sc, 0.5f);
    }
}

/* Hides the blades behind team t's camera, shows those ahead. */
void func_80109884_1C5404_DungeonDash(s32 team, f32 z) {
    DDBlock* b;
    u16 i;

    b = D_8010B2E0_1C6E60_DungeonDash;
    if (D_8010B2A8_1C6E28_DungeonDash == 0) {
        return;
    }
    for (i = 0; i < 2; i++, b++) {
        if (b->unk0 != 0 && D_8010B2BC_1C6E3C_DungeonDash == 0) {
            if (b->unk1C > z + 400.0) {
                D_800FC834_FD434[b->unk6].unk01 ^= 1 << team;
            } else {
                D_800FC834_FD434[b->unk6].unk01 |= 1 << team;
            }
        }
    }
}

/* Builds a sprite model: a textured quad from vtx (10 vertices copied per frame buffer) showing
   sprite animation spr; type picks the render and combine modes (2-5 tinted, translucent). */
s16 func_80109958_1C54D8_DungeonDash(Vtx_t* vtx, HuSprite_Unk84_Struct* spr, s32 type) {
    HmfData* hmf;
    Gfx* buf;
    Gfx* gfx;
    Vtx_t* dst;
    Vtx_t* src;
    s32 idx;
    s32 size;
    s32 i;
    s32 j;

    buf = gfx = HuMemAlloc(0x200);
    if (type == 1) {
        idx = func_80027FA4_28BA4(0, buf, 4);
    } else {
        idx = func_80027FA4_28BA4(0x8C0, buf, 4);
    }
    hmf = D_800FC834_FD434[idx].hmf;
    if (type == 1) {
        hmf->unk64->unk50 |= 0x70010000;
    } else if (type > 0) {
        if (type < 4) {
            hmf->unk64->unk50 |= 0x71010000;
        } else {
            hmf->unk64->unk50 |= 0x01010000;
        }
    } else {
        hmf->unk64->unk50 |= 0x01010000;
    }
    HuMemFree(hmf->unk3C);
    hmf->unk3C = func_80027154_27D54(0x14, D_800FA1AA_FADAA);
    for (i = 0; i < D_800FDBCA_FE7CA; i++) {
        dst = (Vtx_t*)(hmf->unk44[i] = func_80027154_27D54(0xA0, hmf->unk0E));
        for (src = vtx, j = 0; j < 10; j++) {
            *dst++ = *src++;
        }
    }
    gSPDisplayList(gfx++, osVirtualToPhysical(D_8010AB70_1C66F0_DungeonDash));
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPPipeSync(gfx++);
    gSPClearGeometryMode(gfx++, G_CULL_BOTH | G_LIGHTING);
    if (type != 0) {
        gSPSetGeometryMode(gfx++, G_ZBUFFER | G_CULL_FRONT | G_TEXTURE_GEN_LINEAR);
    } else {
        gSPSetGeometryMode(gfx++, G_ZBUFFER | G_SHADE | G_CULL_FRONT | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH);
    }
    gDPSetColorDither(gfx++, G_CD_NOISE);
    gDPSetTexturePersp(gfx++, G_TP_NONE);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gDPSetTextureConvert(gfx++, G_TC_FILT);
    gDPSetAlphaDither(gfx++, G_AD_PATTERN);
    gDPSetAlphaCompare(gfx++, G_AC_THRESHOLD);
    gDPSetBlendColor(gfx++, 0x01, 0x01, 0x01, 0x01);
    gDPPipeSync(gfx++);
    switch (type) {
        case 2:
            gDPSetRenderMode(gfx++, 0x004049D8, 0);
            gDPSetCombine(gfx++, 0xFF97FF, 0xFF2DFEFF);
            gDPSetPrimColor(gfx++, 0, 0, 0xFF, 0xFF, 0xFF, 0x40);
            break;
        case 3:
            gDPSetRenderMode(gfx++, 0x004049D8, 0);
            gDPSetCombine(gfx++, 0xFF97FF, 0xFF2DFEFF);
            gDPSetPrimColor(gfx++, 0, 0, 0x00, 0x00, 0x00, 0x80);
            break;
        case 4:
            gDPSetRenderMode(gfx++, 0x004049D8, 0);
            gDPSetCombine(gfx++, 0xFF97FF, 0xFF2DFEFF);
            gDPSetPrimColor(gfx++, 0, 0, 0xFF, 0x64, 0x00, 0x80);
            break;
        case 5:
            gDPSetRenderMode(gfx++, 0x004049D8, 0);
            gDPSetCombine(gfx++, 0xFF97FF, 0xFF2DFEFF);
            gDPSetPrimColor(gfx++, 0, 0, 0xFF, 0x64, 0x00, 0xFF);
            break;
        default:
            gDPSetCombine(gfx++, 0xFF99FF, 0xFF30FE7F);
            gDPSetRenderMode(gfx++, 0x00404A50, 0);
            break;
    }
    if (spr->unk1A >= 2) {
        gDPSetTextureLUT(gfx++, G_TT_RGBA16);
        gDPLoadTLUT_pal16(gfx++, 0, spr->unk0C);
        gDPLoadTextureBlock_4b(gfx++, 0x04000000, G_IM_FMT_CI, spr->unk00->unk04, spr->unk00->unk06, 0,
                               G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                               G_TX_NOLOD, G_TX_NOLOD);
        gDPPipeSync(gfx++);
    } else {
        gDPSetTexturePersp(gfx++, G_TP_NONE);
        gDPSetTextureLUT(gfx++, G_TT_NONE);
        gDPLoadTextureBlock_4b(gfx++, 0x04000000, G_IM_FMT_I, spr->unk00->unk04, spr->unk00->unk06, 0,
                               G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                               G_TX_NOLOD, G_TX_NOLOD);
        gDPPipeSync(gfx++);
    }
    gSPVertex(gfx++, 0x01000000, 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
    gSPSetGeometryMode(gfx++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_TEXTURE_GEN_LINEAR);
    gDPPipeSync(gfx++);
    gSPEndDisplayList(gfx++);
    size = (u32)gfx - (u32)buf;
    hmf->unk3C->unk00[0] = hmf->unk3C->unk10 = func_80027154_27D54(size, hmf->unk0E);
    bcopy(buf, hmf->unk3C->unk00[0], size);
    HuMemFree(buf);
    for (i = 0; i < D_800FDBCA_FE7CA; i++) {
        hmf->unk3C->unk00[i + 1] = func_80027154_27D54(0x100, hmf->unk0E);
    }
    return idx;
}

/* Points a sprite model's display list at frame `frame` of `anim`. */
void func_8010A340_1C5EC0_DungeonDash(s16 model, HuSprite_Unk84_Struct* anim, s16 frame) {
    HmfModel* m = &D_800FC834_FD434[model];
    HmfData* hmf = m->hmf;
    Gfx* gfx = hmf->unk3C->unk00[D_800FDBE0_FE7E0 + 1];

    hmf->unk3C->unk00[0] = gfx;
    gDPPipeSync(&gfx[0]);
    gSPSegment(&gfx[1], 0x04, osVirtualToPhysical(anim->unk00[frame].unk00));
    gSPSegment(&gfx[2], 0x01, osVirtualToPhysical(hmf->unk44[0]));
    gSPDisplayList(&gfx[3], osVirtualToPhysical(hmf->unk3C->unk10));
    gDPPipeSync(&gfx[4]);
    gSPEndDisplayList(&gfx[5]);
}

/* A copy of sprite model src (a new one when model is -1) sharing its current frame. */
s32 func_8010A430_1C5FB0_DungeonDash(s32 model, s32 src) {
    HmfModel* m;
    HmfData* dst;
    HmfData* from;

    if (model == -1) {
        m = &D_800FC834_FD434[src];
        model = func_80027FA4_28BA4(m->unk18, NULL, 4);
    }
    dst = D_800FC834_FD434[model].hmf;
    from = D_800FC834_FD434[src].hmf;
    dst->unk64->unk50 = from->unk64->unk50;
    dst->unk3C->unk00[0] = from->unk3C->unk00[0];
    return model;
}

/* A copy of sprite model src (a new one with its own display-list buffers when model is -1) showing
   frame `frame` of `anim`. */
s32 func_8010A4DC_1C605C_DungeonDash(s32 model, s32 src, HuSprite_Unk84_Struct* anim, s32 frame) {
    HmfModel* m;
    HmfData* dst;
    HmfData* from;
    Gfx* gfx;
    s32 i;

    if (model == -1) {
        m = &D_800FC834_FD434[src];
        model = func_80027FA4_28BA4(m->unk18, NULL, 4);
        dst = D_800FC834_FD434[model].hmf;
        HuMemFree(dst->unk3C);
        dst->unk3C = func_80027154_27D54(0x10, D_800FA1AA_FADAA);
        for (i = 0; i < 3; i++) {
            dst->unk3C->unk00[i + 1] = func_80027154_27D54(0x100, dst->unk0E);
        }
    }
    dst = D_800FC834_FD434[model].hmf;
    from = D_800FC834_FD434[src].hmf;
    dst->unk64->unk50 = from->unk64->unk50;
    dst->unk3C->unk00[0] = gfx = dst->unk3C->unk00[D_800FDBE0_FE7E0 + 1];
    gDPPipeSync(gfx++);
    gSPSegment(gfx++, 0x04, osVirtualToPhysical(anim->unk00[frame].unk00));
    gSPSegment(gfx++, 0x01, osVirtualToPhysical(from->unk44[0]));
    gSPDisplayList(gfx++, osVirtualToPhysical(from->unk3C->unk10));
    gDPPipeSync(gfx++);
    gSPEndDisplayList(gfx++);
    return model;
}
