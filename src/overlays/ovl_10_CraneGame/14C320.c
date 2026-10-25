#include "ovl_10.h"

/* .data (0x155280-0x1554F0, 8010B760-8010B9D0). The labels 8010B99C and 8010B9B4 (inside
   D_8010B998 and D_8010B9B0) are undefined_syms.txt aliases for the asm. */

s32 D_8010B760_155280_CraneGame = 0;
CGHang D_8010B764_155284_CraneGame[7] = {
    { -800.0f, 350.0f, 0.5f },
    { -500.0f, 450.0f, 0.25f },
    { -100.0f, 550.0f, 0.3f },
    { 0.0f, 400.0f, 0.6f },
    { 300.0f, 450.0f, 0.4f },
    { 600.0f, 350.0f, 0.5f },
    { 800.0f, 550.0f, 0.25f },
};
s32 D_8010B7B8_1552D8_CraneGame[7] = {
    0x0020000C, 0x0020000E, 0x0020000C, 0x0020000C, 0x0020000D, 0x0020000C, 0x0020000C,
};
/* unreferenced: the zero word before the display lists */
s32 D_8010B7D4_1552F4_CraneGame = 0;

/* The render setup D_8010B8E8 (MP1 D_800FF870) and the lists it calls; 151A90.c has its own
   copy at D_8010BBD0-D_8010BCE0. */
Gfx D_8010B7D8_1552F8_CraneGame[] = {
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
Gfx D_8010B890_1553B0_CraneGame[] = {
    gsSPClearGeometryMode(0xFFFFFFFF),
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_OFF),
    gsSPSetGeometryMode(G_SHADE | G_SHADING_SMOOTH),
    gsSPClipRatio(FRUSTRATIO_2),
    gsSPEndDisplayList(),
};
Gfx D_8010B8D0_1553F0_CraneGame[] = {
    gsSPDisplayList(D_8010B890_1553B0_CraneGame),
    gsSPDisplayList(D_8010B7D8_1552F8_CraneGame),
    gsSPEndDisplayList(),
};
Gfx D_8010B8E8_155408_CraneGame[] = {
    gsDPPipeSync(),
    gsSPDisplayList(D_8010B8D0_1553F0_CraneGame),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPSetGeometryMode(G_ZBUFFER | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsDPSetBlendColor(0x00, 0x00, 0x00, 0x00),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0xFF),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPEndDisplayList(),
};
Gfx D_8010B928_155448_CraneGame[] = {
    gsDPPipeSync(),
    gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, 319, 239),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_SHADE | G_CULL_BOTH | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH),
    gsDPSetRenderMode(G_RM_AA_ZB_XLU_LINE, G_RM_NOOP2),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
s16 D_8010B978_155498_CraneGame[4] = { 3, 4, 5, 0 };
f32 D_8010B980_1554A0_CraneGame[6] = { 0.0f, 30.0f, 40.0f, 50.0f, -50.0f, -60.0f };
f32 D_8010B998_1554B8_CraneGame[3][2] = { { -1.0f, -1.0f }, { 1.0f, 0.0f }, { -1.0f, 1.0f } };
f32 D_8010B9B0_1554D0_CraneGame[4][2] = { { -1.0f, -1.0f }, { 1.0f, -1.0f }, { -1.0f, 1.0f }, { 1.0f, 1.0f } };


void func_80102800_14C320_CraneGame(void) {
    s16 var_a0;
    u8 temp_s0;
    s16 i;

    func_8002D4D0_2E0D0(0x32);
    func_8002F290_2FE90(D_800F9D30_FA930, 0x40);
    func_80020D20_21920(0x20);
    omInitObjMan(0x32, 0);
    func_80079128_79D28();
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_80079E60_7AA60), 0xA0);
    func_80018E30_19A30(1);
    temp_s0 = func_80018E78_19A78();
    ScissorSet(temp_s0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(temp_s0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 30.0f, 1000.0f, 4000.0f);
    D_800FA606_FB206 = 0;
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    D_8010C174_155C94_CraneGame = 0;
    D_8010C176_155C96_CraneGame = 0;
    D_8010C17C_155C9C_CraneGame = 900;
    D_8010C17E_155C9E_CraneGame = 0x78;
    D_8010C17A_155C9A_CraneGame = 0;
    D_8010C178_155C98_CraneGame = 1;
    D_8010C182_155CA2_CraneGame = _CheckFlag(0xC);
    D_8010C180_155CA0_CraneGame = 0;
    D_8010C184_155CA4_CraneGame = 0;
    D_8010C258_155D78_CraneGame = 0;
    D_8010D234_156D54_CraneGame = 0;
    for (i = 0; i < ARRAY_COUNT(D_8010CE30_156950_CraneGame); i++) {
        D_8010CE30_156950_CraneGame[i] = 0;
    }
    D_8010D230_156D50_CraneGame = omAddObj(3, 0, 0, -1, func_80102CFC_14C81C_CraneGame);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0] = omAddObj(8, 1, 0, -1, func_80103974_14D494_CraneGame);
    omSetStatBit(D_800FC7B0_FD3B0[D_800F8FE0_F9BE0], 0xA0);
    D_800F8FE0_F9BE0++;
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(4, 2, 0x32, -1, func_80104854_14E374_CraneGame);

    for (i = 0; i < 6; i++) {
        D_800F9CE0_FA8E0[D_800FA606_FB206] = omAddObj(5, 1, 0, -1, func_80106F00_150A20_CraneGame);
        omSetStatBit(D_800F9CE0_FA8E0[D_800FA606_FB206], 0xA0);
        D_800FA606_FB206++;
    }

    for (i = 0; i < ARRAY_COUNT(D_8010C188_155CA8_CraneGame); i++) {
        D_8010C188_155CA8_CraneGame[i] = i;
    }

    for (i = 0; i < 36; i++) {
        u32 index1;
        u32 index2;
        s16 temp;

        index1 = (rand8() * 3);
        index1 = index1 >> 7;
        index2 = (rand8() * 3);

        temp = D_8010C188_155CA8_CraneGame[index1];
        index2 = index2 >> 7;

        D_8010C188_155CA8_CraneGame[index1] = D_8010C188_155CA8_CraneGame[index2];
        D_8010C188_155CA8_CraneGame[index2] = temp;
    }

    func_80026DAC_279AC(0, 0x80, 0x80, 0x80);
    func_80026DAC_279AC(1, 0xFF, 0xFF, 0xFF);
    func_80026E00_27A00(1, 0.0f, 64.0f, 192.0f);
    D_800FA610_FB210 = 2200.0f;
    D_800FD474_FE074.x = -35.0f;
    D_800FD474_FE074.y = 0.0f;
    D_800FD474_FE074.z = 0.0f;
    D_8010274C_10334C.x = 0.0f;
    D_8010274C_10334C.y = 420.0f;
    D_8010274C_10334C.z = 300.0f;
    func_80109A70_153590_CraneGame();
    func_80107F70_151A90_CraneGame();
    func_801082B8_151DD8_CraneGame(0.0f);
    for (i = 0, var_a0 = 0; i < 4; i++) {
        if (gPlayers[i].group == 0) {
            D_8010C194_155CB4_CraneGame = i;
        } else {
            D_8010C196_155CB6_CraneGame[var_a0++] = i;
        }
    }
    D_8010C1A0_155CC0_CraneGame = 0;
}

void func_80102CFC_14C81C_CraneGame(omObjData* obj) {
    obj->func_ptr = &func_80102D28_14C848_CraneGame;
    InitFadeIn(0, 0x10);
}

void func_80102D28_14C848_CraneGame(omObjData* obj) {
    s16 i;

    switch (D_8010C174_155C94_CraneGame) {
    case 0:
        if (D_8010C176_155C96_CraneGame != 0) {
            if (--D_8010C17E_155C9E_CraneGame == 0) {
                D_8010C174_155C94_CraneGame++;
                D_8010C17E_155C9E_CraneGame = 0x3C;
                func_800691FC_69DFC(0);
            }
        }
        if (D_8010C258_155D78_CraneGame >= 4 && D_8010B760_155280_CraneGame == 0) {
            PlayMusic(0x29);
            D_8010B760_155280_CraneGame++;
        }
        break;
    case 1:
        if (--D_8010C17E_155C9E_CraneGame == 0) {
            D_8010C174_155C94_CraneGame++;
            D_8010C178_155C98_CraneGame = 0;
            D_8010C170_155C90_CraneGame = omAddObj(7, 0, 0, -1, func_80103250_14CD70_CraneGame);
            D_8010C17E_155C9E_CraneGame = 0x10;
        }
        break;
    case 2:
        if (D_8010C178_155C98_CraneGame == 0 && D_8010C17C_155C9C_CraneGame != 0) {
            D_8010C17C_155C9C_CraneGame -= 1;
        }
        if (D_8010C17A_155C9A_CraneGame != 0) {
            D_8010C178_155C98_CraneGame = 1;
            if (--D_8010C17E_155C9E_CraneGame == 0) {
                if (D_8010C1A0_155CC0_CraneGame == 3) {
                    gPlayers[D_8010C194_155CB4_CraneGame].coins_mg_bonus += 10;
                } else {
                    for (i = 0; i < 3; i++) {
                        gPlayers[D_8010C196_155CB6_CraneGame[i]].coins_mg_bonus += 10;
                    }
                }
                if (D_8010C182_155CA2_CraneGame == 0) {
                    D_8010C174_155C94_CraneGame++;
                } else {
                    D_8010C174_155C94_CraneGame = 4;
                    D_8010C17E_155C9E_CraneGame = 0x3C;
                }
                func_800691FC_69DFC(3);
                func_800794A8_7A0A8(0x28);
            }
        }
        break;
    case 3:
        if (func_80069538_6A138() == 2) {
            D_8010C174_155C94_CraneGame++;
            if (D_8010C1A0_155CC0_CraneGame == 3) {
                func_800691FC_69DFC(6, gPlayers[D_8010C194_155CB4_CraneGame].character);
                PlayMusic(0x51);
                D_8010C17E_155C9E_CraneGame = 0x78;
                D_8010C184_155CA4_CraneGame = 1;
            } else {
                func_800691FC_69DFC(0x15, gPlayers[D_8010C196_155CB6_CraneGame[0]].character,
                                    gPlayers[D_8010C196_155CB6_CraneGame[1]].character,
                                    gPlayers[D_8010C196_155CB6_CraneGame[2]].character);
                PlayMusic(0x52);
                D_8010C17E_155C9E_CraneGame = 0xA8;
                D_8010C184_155CA4_CraneGame = 2;
            }
        }
        break;
    case 4:
        if (--D_8010C17E_155C9E_CraneGame == 0) {
            D_8010C174_155C94_CraneGame = -1;
            D_8010C17A_155C9A_CraneGame = -1;
            if (D_8010C182_155CA2_CraneGame == 0) {
                func_80079614_7A214(0x28);
                func_800794A8_7A0A8(0x28);
            }
            InitFadeOut(0, 0x14);
        }
        break;
    }
    if (D_8010C17A_155C9A_CraneGame >= 0 && D_801011FC_101DFC != 0) {
        D_8010C17A_155C9A_CraneGame = -1;
        D_8010C174_155C94_CraneGame = -1;
        InitFadeOut(0, 0x14);
        func_80079614_7A214(0x28);
        func_800794A8_7A0A8(0x28);
    }
    func_801031EC_14CD0C_CraneGame();
}

void func_801031B8_14CCD8_CraneGame(void) {
    SprAnimKill(D_8010C19E_155CBE_CraneGame);
    SprKill(D_8010C19C_155CBC_CraneGame);
    func_80103F38_14DA58_CraneGame();
}

void func_801031EC_14CD0C_CraneGame(void) {
    if (D_8010C17A_155C9A_CraneGame < 0 && func_8008F618_90218() == 0) {
        func_80109AA8_1535C8_CraneGame();
        func_80108038_151B58_CraneGame();
        func_80107EC0_1519E0_CraneGame();
        func_801031B8_14CCD8_CraneGame();
        func_80079464_7A064();
        omOvlReturnEx(1);
    }
}

void func_80103250_14CD70_CraneGame(omObjData* obj) {
    obj->work[0] = func_800691FC_69DFC(0xA, D_8010C17C_155C9C_CraneGame / 30, 0xA0, 0x18);
    obj->func_ptr = &func_801032C8_14CDE8_CraneGame;
}

void func_801032C8_14CDE8_CraneGame(omObjData* obj) {
    func_8006D4D0_6E0D0((D_8010C17C_155C9C_CraneGame + 29) / 30);
    if (D_8010C17A_155C9A_CraneGame != 0) {
        obj->func_ptr = NULL;
        func_8006D518_6E118();
    }
}

s32 func_80103338_14CE58_CraneGame(omObjData* obj) {
    f32 temp_f12;
    s32 var_s0;
    HmfMotionObj* temp_v0;

    temp_v0 = D_800FC834_FD434[D_8010C186_155CA6_CraneGame].hmf->unk84;
    temp_f12 = (temp_v0->unk04.x - obj->trans.x) * (temp_v0->unk04.x - obj->trans.x) +
               (temp_v0->unk04.z - obj->trans.z) * (temp_v0->unk04.z - obj->trans.z);
    var_s0 = 0;
    if (sqrtf(temp_f12) < 180.0) {
        var_s0 = 1;
    }
    return var_s0;
}

s16 func_801033E4_14CF04_CraneGame(f32 arg0) {
    f32 temp_f0;
    f32 var_f12;
    s16 var_s4;
    HmfData* temp_s2;
    HmfVtx* var_s0;
    HmfVtx* var_s1;
    s16 i;

    var_s4 = 0;
    temp_s2 = D_800FC834_FD434[D_8010C186_155CA6_CraneGame].hmf;
    var_s1 = temp_s2->unk40;
    var_s0 = temp_s2->unk44[D_800FDBE0_FE7E0];

    for (i = 0; i < temp_s2->unk18; i++) {
        var_f12 = (temp_s2->unk84->unk04.y + var_s0->unk02 - arg0) / 4.0;
        if (var_f12 < -90.0) {
            var_f12 = -90.0f;
        }
        if (var_f12 > 90.0) {
            var_f12 = 90.0f;
        }
        temp_f0 = func_800B7890_B8490(var_f12);
        if (temp_f0 != 0.0) {
            var_s4 = 1;
        }
        var_s0->unk00 = (var_s1->unk00 + (var_s1->unk00 * 0.8 * temp_f0));
        var_s0->unk04 = (var_s1->unk04 + (var_s1->unk04 * 0.8 * temp_f0));
        var_s1++;
        var_s0++;
    }

    return var_s4;
}

s16 func_801035C0_14D0E0_CraneGame(f32* x, f32* y, f32* z, f32 dx, f32 dy, f32 dz, f32 r, s16 mode) {
    Vec d;
    HmfData* m;
    f32 dist;
    f32 h;
    f32 f;
    s16 ret;

    ret = 0;
    if (mode != 2) {
        m = D_800FC834_FD434[D_8010C186_155CA6_CraneGame].hmf;
        d.x = m->unk84->unk04.x - *x;
        d.z = m->unk84->unk04.z - *z;
        dist = sqrtf(d.x * d.x + d.z * d.z);
        if (dist < r + 280.0) {
            h = *y - r;
            if (h < 300.0) {
                if (mode == 0 && h - dy >= 300.0) {
                    *y = r + 300.0;
                } else {
                    f = 300.0 - (*y - r);
                    if (r < f) {
                        f = r;
                    }
                    h = HuMathSin(f / r * 90.0) * r + 280.0;
                    if (dist != 0.0) {
                        d.x /= dist;
                        d.z /= dist;
                        *x = m->unk84->unk04.x + -d.x * h;
                        *z = m->unk84->unk04.z + -d.z * h;
                    }
                }
                ret = 2;
            }
        }
    }
    if (*x < -360.0) {
        *x = -360.0f;
        ret |= 1;
    }
    if (*x > 420.0) {
        *x = 420.0f;
        ret |= 1;
    }
    if (*z < -360.0) {
        *z = -360.0f;
        ret |= 1;
    }
    if (*z > 640.0) {
        *z = 640.0f;
        ret |= 1;
    }
    return ret;
}

void func_801038FC_14D41C_CraneGame(void) {
    D_8010C254_155D74_CraneGame = (rand8() * 0.5f / 256.0f - 0.25f) * 10.0;
}

void func_80103974_14D494_CraneGame(omObjData* obj) {
    HmfData* hmf;
    s32 i;

    obj->func_ptr = func_80103CB8_14D7D8_CraneGame;
    obj->trans.x = obj->trans.y = obj->trans.z = 0.0f;
    obj->scale.z = 1.0f;
    obj->scale.y = 1.0f;
    obj->scale.x = 1.0f;
    obj->model[0] = D_8010C186_155CA6_CraneGame = func_80018A30_19630(0x200001, 0xA9);
    func_80029714_2A314(obj->model[0], 0.0f, 0.0f, 0.0f);
    func_8002979C_2A39C(obj->model[0], 0.0f, 0.0f, 0.0f);
    func_800297E8_2A3E8(obj->model[0], 1.0f, 1.0f, 1.0f);
    func_8002A00C_2AC0C(obj->model[0]);
    func_80108114_151C34_CraneGame(obj->model[0]);
    func_801082E8_151E08_CraneGame(1.75f);
    D_8010C19E_155CBE_CraneGame = func_8001A2F8_1AEF8(0x200011);
    D_8010C19C_155CBC_CraneGame = SprCreate(1, 0);
    SprAnimSet(D_8010C19C_155CBC_CraneGame, 0, D_8010C19E_155CBE_CraneGame, 0);
    SprAttrSet(D_8010C19C_155CBC_CraneGame, 0, 0x4000);
    SprPosSet(D_8010C19C_155CBC_CraneGame, 0, 0xA0, 0x78);
    for (i = 0; i < 7; i++) {
        obj->model[i + 1] = func_80018A30_19630(D_8010B7B8_1552D8_CraneGame[i], 0xA9);
        func_80029714_2A314(obj->model[i + 1], D_8010B764_155284_CraneGame[i].x, D_8010B764_155284_CraneGame[i].y, -600.0f);
        func_8002979C_2A39C(obj->model[i + 1], 0.0f, 0.0f, 0.0f);
        func_800297E8_2A3E8(obj->model[i + 1], D_8010B764_155284_CraneGame[i].scale, D_8010B764_155284_CraneGame[i].scale, 1.0f);
        D_8010C1A8_155CC8_CraneGame[i].a = D_8010B764_155284_CraneGame[i].x;
        D_8010C1A8_155CC8_CraneGame[i].b = 1000.0f;
        D_8010C1E0_155D00_CraneGame[i] = 1000.0f - D_8010B764_155284_CraneGame[i].y;
        D_8010C200_155D20_CraneGame[i].b = 0.0f;
        D_8010C200_155D20_CraneGame[i].a = 0.0f;
        D_8010C238_155D58_CraneGame[i] = 0.0f;
    }
    D_8010C1A4_155CC4_CraneGame = func_8002838C_28F8C(0x1080, func_80103FC8_14DAE8_CraneGame, 2);
    hmf = D_800FC834_FD434[D_8010C1A4_155CC4_CraneGame].hmf;
    for (i = 0; i < D_800FDBCA_FE7CA; i++) {
        hmf->unk44[i] = HuMemAlloc(0xE0);
    }
    D_8010C254_155D74_CraneGame = 0.0f;
}

void func_80103CB8_14D7D8_CraneGame(omObjData* obj) {
    HmfModel* m;
    f32 len;
    f32 dx;
    f32 dy;
    f32 d;
    f32 px;
    f32 py;
    s16 i;

    for (i = 0; i < 7; i++) {
        m = &D_800FC834_FD434[obj->model[i + 1]];
        len = D_8010C1E0_155D00_CraneGame[i];
        px = m->pos.x;
        py = m->pos.y;
        px += D_8010C200_155D20_CraneGame[i].a + D_8010C254_155D74_CraneGame;
        py += D_8010C200_155D20_CraneGame[i].b + -4.0;
        dx = px - D_8010C1A8_155CC8_CraneGame[i].a;
        dy = py - D_8010C1A8_155CC8_CraneGame[i].b;
        d = len / sqrtf(dx * dx + dy * dy);
        dx *= d;
        dy *= d;
        px = dx + D_8010C1A8_155CC8_CraneGame[i].a;
        py = dy + D_8010C1A8_155CC8_CraneGame[i].b;
        D_8010C200_155D20_CraneGame[i].a = px - m->pos.x;
        D_8010C200_155D20_CraneGame[i].b = py - m->pos.y;
        m->pos.x = px;
        m->pos.y = py;
        D_8010C238_155D58_CraneGame[i] = D_8010C200_155D20_CraneGame[i].a * 4.0f;
        if (m->rot.y != D_8010C238_155D58_CraneGame[i]) {
            if (D_8010C238_155D58_CraneGame[i] < m->rot.y) {
                m->rot.y -= 1.0f;
                if (m->rot.y < D_8010C238_155D58_CraneGame[i]) {
                    m->rot.y = D_8010C238_155D58_CraneGame[i];
                }
            } else {
                m->rot.y += 1.0f;
                if (D_8010C238_155D58_CraneGame[i] < m->rot.y) {
                    m->rot.y = D_8010C238_155D58_CraneGame[i];
                }
            }
        }
    }
    D_8010C254_155D74_CraneGame = 0.0f;
}

void func_80103F38_14DA58_CraneGame(void) {
    HmfData* hmf;
    s16 i;

    hmf = D_800FC834_FD434[D_8010C1A4_155CC4_CraneGame].hmf;
    for (i = 0; i < D_800FDBCA_FE7CA; i++) {
        HuMemFree(hmf->unk44[i]);
    }
}

void func_80103FC8_14DAE8_CraneGame(Gfx** gfx) {
    omObjData* bg;
    HmfData* hmf;
    HmfModel* m;
    HmfVtx* v;
    HmfVtx* vtx;
    s16 i;

    bg = D_800FC7B0_FD3B0[0];
    hmf = D_800FC834_FD434[D_800F9564_FA164].hmf;
    gSPDisplayList((*gfx)++, osVirtualToPhysical(D_8010B8E8_155408_CraneGame));
    func_800204C0_210C0(0, gfx);
    gSPDisplayList((*gfx)++, osVirtualToPhysical(D_8010B928_155448_CraneGame));
    v = vtx = hmf->unk44[D_800FDBE0_FE7E0];
    for (i = 0; i < 7; i++) {
        m = &D_800FC834_FD434[bg->model[i + 1]];
        v->unk00 = D_8010C1A8_155CC8_CraneGame[i].a;
        v->unk02 = D_8010C1A8_155CC8_CraneGame[i].b;
        v->unk04 = m->pos.z;
        v->unk08 = v->unk0A = 0;
        v->unk0C[0] = v->unk0C[1] = v->unk0C[2] = 0x20;
        v->unk0F = 0xFF;
        v++;
        v->unk00 = m->pos.x;
        v->unk02 = m->pos.y;
        v->unk04 = m->pos.z;
        v->unk08 = v->unk0A = 0;
        v->unk0C[0] = v->unk0C[1] = v->unk0C[2] = 0x20;
        v->unk0F = 0xFF;
        v++;
    }
    for (i = 0; i < 7; i++) {
        gSPVertex((*gfx)++, &vtx[i * 2], 2, 0);
        CG_SP_LINE3D_01((*gfx)++);
    }
    gDPPipeSync((*gfx)++);
}

s16 func_8010422C_14DD4C_CraneGame(f32 x, f32 y, f32 z, f32 r) {
    f32 dx;
    f32 dz;
    f32 d;
    f32 rad;
    f32 best;
    s16 sel;
    s16 i;
    omObjData* o;
    CGWork* w;

    sel = -1;
    best = 9999.0f;
    for (i = 0; i < D_800FA606_FB206; i++) {
        o = D_800F9CE0_FA8E0[i];
        w = o->unk_50;
        if (w->unk34 > w->unk38) {
            rad = w->unk34;
        } else {
            rad = w->unk38;
        }
        if (w->unk50 >= 0) {
            dx = o->trans.x - x;
            if (fabs(dx) < rad + r) {
                dz = o->trans.z - z;
                if (fabs(dz) < rad + r) {
                    d = sqrtf(dx * dx + dz * dz);
                    if (d < best && d < 120.0) {
                        best = d;
                        sel = i;
                    }
                }
            }
        }
    }
    return sel;
}

s16 func_801043D8_14DEF8_CraneGame(f32 arg0, f32 arg1, f32 arg2, s16 arg3) {
    f32 distanceSquared;
    f32 clampedDistance;
    s16 ret;
    omObjData* temp_v0;

    temp_v0 = D_800F9CE0_FA8E0[arg3];
    distanceSquared = ((temp_v0->trans.x - arg0) * (temp_v0->trans.x - arg0)) + ((temp_v0->trans.z - arg1) * (temp_v0->trans.z - arg1));
    clampedDistance = sqrtf(distanceSquared);

    clampedDistance -= arg2;
    if (clampedDistance < 0.0) {
        clampedDistance = 0.0f;
    }
    if (clampedDistance < 40.0) {
        ret = 0;
    } else if (clampedDistance < 80.0) {
        ret = 1;
    } else if (clampedDistance < 120.0) {
        ret = 2;
    } else {
        ret = -1;
    }
    return ret;
}

#ifdef NON_MATCHING
/* Register allocation only: retail keeps the angle's double in $f20, this uses $f0. */
f32 func_801044E0_14E000_CraneGame(Vec* a, Vec* b) {
    f32 t;
    f32 best;
    s16 i;

    best = 0.0f;
    for (i = 0; i < 33; i++) {
        if (i == 0) {
            b->x = a->x;
            b->z = a->z;
        } else if (i < 17) {
            t = i - 1;
            t *= 22.5;
            b->x = a->x + func_800B7890_B8490(t) * 10.0 * 10.0;
            b->z = a->z + HuMathSin(t) * 10.0 * 10.0;
        } else {
            t = i - 17;
            t *= 22.5;
            b->x = a->x + func_800B7890_B8490(t) * 5.0 * 10.0;
            b->z = a->z + HuMathSin(t) * 5.0 * 10.0;
        }
        b->y = 600.0f;
        if (func_8010A4D8_153FF8_CraneGame(b, 0.0f, -800.0f, 0.0f, -1) != 0 && best < b->y) {
            best = b->y;
            if (i == 0) {
                break;
            }
        }
    }
    return best;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/14C320", func_801044E0_14E000_CraneGame);
#endif

s16 func_801046E8_14E208_CraneGame(omObjData* obj) {
    s16 list[2][4]; /* [0] every free prize, [1] those from index 3 */
    s16 nfar;
    s16 nall;
    s16 sel;
    s16 i;

    nfar = 0;
    nall = 0;
    for (i = 0; i < D_800FA606_FB206; i++) {
        if (func_80107F40_151A60_CraneGame(D_800F9CE0_FA8E0[i])->unk2 & 4) {
            list[0][nall++] = i;
            if (i >= 3) {
                list[1][nfar++] = i;
            }
        }
    }
    if ((D_8010C17C_155C9C_CraneGame < 450) & (nfar != 0)) {
        sel = list[1][(rand8() * nfar) >> 8];
    } else {
        sel = list[0][(rand8() * nall) >> 8];
    }
    return sel;
}

void func_80104854_14E374_CraneGame(omObjData* obj) {
    CGClaw* c;
    CGWork* w;
    CGWork* w2;

    obj->model[0] = LoadFormFile(D_800CD438_CE038[gPlayers[D_8010C194_155CB4_CraneGame].character].unk_04 |
                                     D_800CD438_CE038[gPlayers[D_8010C194_155CB4_CraneGame].character].unk_0C,
                                 0x2B9);
    w = func_80027154_27D54(sizeof(CGWork), 0x7918);
    obj->unk_50 = w;
    func_800B0EF0_B1AF0(w, 0, sizeof(CGWork));
    w->unkE8 = func_80027154_27D54(obj->mtncnt * sizeof(CGWork), 0x7918);
    func_800B0EF0_B1AF0(w->unkE8, 0, obj->mtncnt * sizeof(CGWork));
    func_80019E84_1AA84(obj, 0, D_800CD438_CE038[gPlayers[D_8010C194_155CB4_CraneGame].character].unk_04 | 0x26, 1, 0);
    func_80019E84_1AA84(obj, 1, D_800CD438_CE038[gPlayers[D_8010C194_155CB4_CraneGame].character].unk_04 | 0x27, 2, 0);
    func_80019E84_1AA84(obj, 2, D_800CD438_CE038[gPlayers[D_8010C194_155CB4_CraneGame].character].unk_04 | 0x28, 0, 0);
    func_80019E84_1AA84(obj, 3, D_800CD438_CE038[gPlayers[D_8010C194_155CB4_CraneGame].character].unk_04 | 0x92, 1, 0);
    func_80019E84_1AA84(obj, 4, D_800CD438_CE038[gPlayers[D_8010C194_155CB4_CraneGame].character].unk_04 | 0x93, 0, 0);
    obj->model[1] = func_80018A30_19630(0x200000, 0xD9);
    obj->model[2] = func_80018A30_19630(0x20000F, 0xDD);
    obj->model[3] = func_80018A30_19630(0x200010, 0xDD);
    obj->func_ptr = func_80104CB0_14E7D0_CraneGame;
    func_8000C35C_CF5C(obj, -360.0f, 1240.0f, 640.0f);
    func_8000C36C_CF6C(obj, 0.0f, -30.0f, 0.0f);
    func_8000C37C_CF7C(obj, 2.0f, 2.0f, 2.0f);
    w2 = obj->unk_50;
    w2->unk50 = 0;
    w2->unk52 = 0;
    w2->unk59 = (u8)D_8010C194_155CB4_CraneGame;
    w2->unk57 = gPlayers[D_8010C194_155CB4_CraneGame].port;
    w2->unkD0 = 0xFFFF;
    w2->unk3C = -1.0f;
    c = func_80107DD4_1518F4_CraneGame(obj);
    c->unkC = obj->trans.x;
    c->unk10 = obj->trans.y + 1700.0;
    c->unk14 = obj->trans.z;
    func_80029714_2A314(obj->model[1], c->unkC, c->unk10, c->unk14);
    func_8002979C_2A39C(obj->model[1], 0.0f, 0.0f, 0.0f);
    func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[1]), 0x28, func_80029D0C_2A90C(obj->motion[1]), 1);
}

void func_80104CB0_14E7D0_CraneGame(omObjData* obj) {
    Vec pos;
    Vec d;
    Vec a;
    f32 ox;
    f32 oy;
    f32 oz;
    f32 ang;
    f32 len;
    f32 h;
    CGWork* w;
    CGClaw* c;
    CGClaw* pc;
    omObjData* o;
    HmfModel* m;
    s16 sz;
    s16 sx;
    s16 k;
    s16 t;
    s16 moving;
    u16 btn;

    w = obj->unk_50;
    moving = 0;
    c = func_80107F40_151A60_CraneGame(obj);
    if (c->unk0 == 0) {
        c->unk0 |= 1;
        c->unk2 = 0;
        c->unk6 = 100;
        c->unk4 = 100;
        c->unk8 = 0;
        c->unk18 = c->unk20 = 0.0f;
        c->unk3C = 32;
        c->unk3E = 0;
        c->unk40 = 0;
        c->unk44 = -1;
        c->unk46 = 0;
        c->unk48 = -1;
        c->unk4C = 0;
        c->unk4E = 0;
        c->unk50 = 0;
        c->unk56 = 0;
        c->unk58 = -1;
        c->unk5A = -1;
    }
    ox = obj->trans.x;
    oy = obj->trans.y;
    oz = obj->trans.z;
    pos.x = c->unkC;
    pos.y = c->unk10;
    pos.z = c->unk14;
    btn = 0;
    if (D_8010C178_155C98_CraneGame != 0 && (c->unk8 < 0 || (c->unk8 >= 2 && c->unk8 <= 8))) {
        if (c->unk44 >= 0) {
            func_80079848_7A448(c->unk44);
            c->unk44 = -1;
        }
        if (c->unk48 >= 0) {
            func_80079848_7A448(c->unk48);
            c->unk48 = -1;
        }
        if (D_8010C184_155CA4_CraneGame > 0) {
            if (D_8010C184_155CA4_CraneGame == 1) {
                func_80019B9C_1A79C(obj, 3);
                func_80079718_7A318(0x103, gPlayers[w->unk59].character);
                c->unk8 = 9;
            } else {
                func_80019B9C_1A79C(obj, 4);
                c->unk8 = -1;
            }
            D_8010C184_155CA4_CraneGame = -1;
        }
    } else {
        switch (c->unk8) {
        case 0:
            if (--c->unk3C == 0) {
                c->unk8++;
                c->unk3C = 64;
                c->unk48 = PlaySound(0x191);
            }
            func_801082D0_151DF0_CraneGame(obj->trans.x, obj->trans.y, obj->trans.z);
            return;
        case 1:
            obj->trans.y -= 10.0;
            obj->rot.y = func_800B0D98_B1998(obj->rot.y + 5.625f, 360.0);
            if (--c->unk3C == 0) {
                c->unk8++;
                func_80079848_7A448(c->unk48);
                c->unk48 = -1;
                func_80029BF0_2A7F0(obj->model[0], func_80029E14_2AA14(obj->motion[0]), 0, 30, 2);
                D_8010C176_155C96_CraneGame = 1;
                c->unk10 = obj->trans.y + 1700.0;
            }
            func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y + 1700.0, obj->trans.z);
            func_8002979C_2A39C(obj->model[1], 0.0f, obj->rot.y + 30.0f, 0.0f);
            func_801082D0_151DF0_CraneGame(obj->trans.x, obj->trans.y, obj->trans.z);
            return;
        case 2:
            func_80019B9C_1A79C(obj, 0);
            if (D_8010C17C_155C9C_CraneGame == 0) {
                D_8010C17A_155C9A_CraneGame = 1;
                c->unk8 = -1;
                return;
            }
            if (!(gPlayers[D_8010C194_155CB4_CraneGame].flags & 1)) {
                sx = ContStkX[w->unk57];
                sz = ContStkY[w->unk57];
                btn = ContBtnTrg[w->unk57];
            } else {
                if (c->unk58 < 0) {
                    c->unk58 = func_801046E8_14E208_CraneGame(obj);
                }
                o = D_800F9CE0_FA8E0[c->unk58];
                sz = 0;
                sx = 0;
                if (fabs(pos.x - o->trans.x) >= 10.0) {
                    sx = -1;
                    if (pos.x < o->trans.x) {
                        sx = 1;
                    }
                } else if (fabs(pos.z - o->trans.z) >= 10.0) {
                    sz = 1;
                    if (pos.z < o->trans.z) {
                        sz = -1;
                    }
                } else {
                    btn |= 0x8000;
                }
            }
            ang = func_800B0D98_B1998(func_800B75A8_B81A8(sx, sz) + 180.0, 360.0);
            if (sx | sz) {
                if (c->unk44 < 0 && w->unk3C == -1.0) {
                    c->unk44 = PlaySound(0x18F);
                }
                ang = (s16)(func_800B0D98_B1998(ang + 45.0, 360.0) / 90.0) * 90.0;
                if (ang != w->unk3C) {
                    c->unk3E = 0;
                    w->unk3C = ang;
                    func_801038FC_14D41C_CraneGame();
                } else {
                    w->unk40 = (c->unk3E < 4) ? (f32)c->unk3E / 4.0f * 1.5 * 10.0 : 15.0f;
                    pos.x -= HuMathSin(ang) * w->unk40;
                    pos.z += func_800B7890_B8490(ang) * w->unk40;
                    c->unk3E++;
                }
                moving = 1;
            } else {
                w->unk3C = -1.0f;
            }
            if (btn & 0x8000) {
                c->unk2 &= ~4;
                c->unk8 = 3;
                c->unk1C = func_8010B364_154E84_CraneGame(pos.x - 72.0, pos.z - 72.0, pos.x + 72.0f, pos.z + 72.0f) - 100.0;
                c->unk48 = PlaySound(0x191);
                h = (f32)(pos.y - 1700.0 + D_8010B980_1554A0_CraneGame[gPlayers[w->unk59].character] - c->unk1C) / 20.0;
                c->unk3C = (s16)h - 15;
                if (c->unk3C <= 0) {
                    c->unk3C = 1;
                }
            }
            break;
        case 3:
            pos.y -= 20.0;
            if (!(c->unk2 & 2)) {
                if (pos.y - 1700.0 <= c->unk1C - D_8010B980_1554A0_CraneGame[gPlayers[w->unk59].character]) {
                    pos.y = c->unk1C + 1700.0 - D_8010B980_1554A0_CraneGame[gPlayers[w->unk59].character];
                    goto stop;
                }
            } else {
            stop:
                c->unk8++;
                c->unk3C = 32;
                if ((c->unk2 & 2) || pos.y - 1700.0 <= -100.0) {
                    c->unk2 |= 4;
                }
                func_80079848_7A448(c->unk48);
                c->unk48 = -1;
            }
            if (c->unk3C != 0) {
                if (--c->unk3C == 0) {
                    func_80019B9C_1A79C(obj, 1);
                }
            }
            break;
        case 4:
            if (--c->unk3C == 0) {
                c->unk8++;
                if ((s8)c->unk5A >= 0) {
                    t = (s8)func_801043D8_14DEF8_CraneGame(obj->trans.x, obj->trans.z, 0.0f, c->unk5A);
                    c->unk40 = t;
                    if ((s8)t >= 0) {
                        pc = func_80107F40_151A60_CraneGame(D_800F9CE0_FA8E0[c->unk5A]);
                        pc->unk8 = 2;
                        pc->unk4C = pc->unk4E = 0;
                        pc->unk56 = 0;
                        c->unk4E = c->unk4C = 0;
                    } else {
                        c->unk5A = -1;
                    }
                }
                c->unk48 = PlaySound(0x191);
                break;
            }
            if ((s8)c->unk5A >= 0 && c->unk3C == 24) {
                PlaySound(0x192);
            }
            if (!(c->unk2 & 4)) {
                c->unk5A = func_8010422C_14DD4C_CraneGame(obj->trans.x, obj->trans.y, obj->trans.z, c->unk4);
            }
            break;
        case 5:
            pos.y += 20.0;
            if (pos.y >= 2300.0) {
                pos.y = 2300.0f;
                func_80079848_7A448(c->unk48);
                c->unk48 = -1;
                if ((s8)c->unk5A < 0 && D_8010C17C_155C9C_CraneGame == 0) {
                    D_8010C17A_155C9A_CraneGame = 1;
                } else {
                    c->unk8++;
                    c->unk3C = 8;
                    if (c->unk44 < 0) {
                        c->unk44 = PlaySound(0x18F);
                    }
                    func_801038FC_14D41C_CraneGame();
                }
            }
            break;
        case 6:
            moving = 1;
            if (pos.z != 640.0) {
                if (c->unk3C == 0) {
                    if (pos.z > 640.0) {
                        pos.z -= 15.0;
                        if (pos.z <= 640.0) {
                            pos.z = 640.0f;
                            c->unk3C = 16;
                        }
                    } else {
                        pos.z += 15.0;
                        if (pos.z >= 640.0) {
                            pos.z = 640.0f;
                            c->unk3C = 16;
                        }
                    }
                } else {
                    c->unk3C--;
                }
            } else if (pos.x != -360.0) {
                if (c->unk3C == 0) {
                    if (pos.x > -360.0) {
                        pos.x -= 15.0;
                        if (pos.x < -360.0) {
                            pos.x = -360.0f;
                        }
                    } else {
                        pos.x += 15.0;
                        if (pos.x > -360.0) {
                            pos.x = -360.0f;
                        }
                    }
                } else {
                    c->unk3C--;
                }
            } else {
                c->unk8++;
                c->unk3C = 32;
            }
            break;
        case 7:
            if (c->unk3C == 24) {
                func_80019B9C_1A79C(obj, 1);
            }
            if (c->unk3C == 16 && (s8)c->unk5A >= 0) {
                func_80107F40_151A60_CraneGame(D_800F9CE0_FA8E0[c->unk5A])->unk3E = 1;
                c->unk5A = -1;
            }
            if (--c->unk3C == 0) {
                if (D_8010C17C_155C9C_CraneGame != 0) {
                    c->unk8++;
                    c->unk3C = 30;
                } else {
                    D_8010C178_155C98_CraneGame = 1;
                    D_8010C17A_155C9A_CraneGame = 1;
                }
            }
            break;
        case 8:
            func_80019B9C_1A79C(obj, 0);
            if (--c->unk3C == 0) {
                c->unk8 = 2;
                c->unk3E = 0;
                w->unk3C = -1.0f;
                c->unk58 = -1;
            }
            break;
        case 9:
            obj->rot.y = func_800B0D98_B1998(obj->rot.y + 4.0f, 360.0);
            func_8002979C_2A39C(obj->model[1], 0.0f, obj->rot.y + 30.0f, 0.0f);
            return;
        }
    }
    func_801035C0_14D0E0_CraneGame(&pos.x, &pos.y, &pos.z, 0.0f, 0.0f, 0.0f, 50.0f, 2);
    d.x = obj->trans.x - pos.x;
    d.y = obj->trans.y - pos.y + -256.0;
    d.z = obj->trans.z - pos.z;
    a.x = func_800B0D98_B1998(func_800B75A8_B81A8(d.z, d.y) + 180.0, 360.0);
    a.y = func_800B0D98_B1998(func_800B75A8_B81A8(d.y, d.x) + 90.0, 360.0);
    func_8002979C_2A39C(obj->model[1], a.x, 0.0f, a.y);
    len = sqrtf(d.x * d.x + d.y * d.y + d.z * d.z);
    if (len != 0.0) {
        d.x /= len;
        d.y /= len;
        d.z /= len;
        obj->trans.x = pos.x + d.x * 1700.0;
        obj->trans.y = pos.y + d.y * 1700.0;
        obj->trans.z = pos.z + d.z * 1700.0;
    }
    c->unk2 = func_801035C0_14D0E0_CraneGame(&obj->trans.x, &obj->trans.y, &obj->trans.z, obj->trans.x - ox,
                                             obj->trans.y - oy, obj->trans.z - oz, 50.0f, 0) |
              (c->unk2 & 0xFFFC);
    if ((u16)c->unk8 - 5 < 3U) {
        if ((s8)c->unk5A >= 0) {
            o = D_800F9CE0_FA8E0[c->unk5A];
            if (func_80107F40_151A60_CraneGame(o)->unk8 == 2) {
                o->trans.x += obj->trans.x - ox;
                o->trans.y += obj->trans.y - oy;
                o->trans.z += obj->trans.z - oz;
            }
        }
        if (gPlayers[D_8010C194_155CB4_CraneGame].flags & 1) {
            if (rand8() < gPlayers[D_8010C194_155CB4_CraneGame].cpu_difficulty * 8 + 64) {
                btn |= 0x8000;
            }
        } else {
            btn = ContBtnTrg[w->unk57];
        }
        c->unk4E++;
        if (D_8010C178_155C98_CraneGame == 0 && c->unk40 < 3 && (btn & 0x8000)) {
            c->unk4C++;
            func_80019B9C_1A79C(obj, 2);
        }
        c->unk50 = (f32)c->unk4C / (f32)c->unk4E * 30.0;
        if ((s8)c->unk5A >= 0) {
            if (D_8010C17C_155C9C_CraneGame == 0) {
                func_80107F40_151A60_CraneGame(D_800F9CE0_FA8E0[c->unk5A])->unk3E = 1;
                c->unk58 = -1;
                c->unk5A = -1;
            }
            if ((s8)c->unk5A >= 0 && c->unk4E >= 16) {
                pc = func_80107F40_151A60_CraneGame(D_800F9CE0_FA8E0[c->unk5A]);
                if (pc->unk40 < 3) {
                    k = D_8010B978_155498_CraneGame[c->unk40] + pc->unk50 / 2;
                    if (k >= 16) {
                        k = 15;
                    }
                    if (c->unk50 < k) {
                        if (++c->unk40 < 3) {
                            c->unk4C = c->unk4E = 0;
                            pc->unk4C = pc->unk4E = 0;
                        } else {
                            func_80107F40_151A60_CraneGame(D_800F9CE0_FA8E0[c->unk5A])->unk3E = 1;
                            c->unk58 = -1;
                            c->unk5A = -1;
                        }
                    }
                }
            }
        }
    }
    c->unkC = pos.x;
    c->unk10 = pos.y;
    c->unk14 = pos.z;
    func_80029714_2A314(obj->model[1], c->unkC, c->unk10, c->unk14);
    if (moving) {
        if (c->unk46 < 6) {
            c->unk46++;
            if (c->unk44 >= 0) {
                func_800795D8_7A1D8(c->unk44, c->unk46 * 10 + 67);
                func_800796F0_7A2F0(c->unk44, c->unk46 * 100 - 600);
            }
        }
    } else if (c->unk46 != 0) {
        if (--c->unk46 == 0) {
            if (c->unk44 >= 0) {
                func_80079848_7A448(c->unk44);
                c->unk44 = -1;
            }
        } else if (c->unk44 >= 0) {
            func_800795D8_7A1D8(c->unk44, c->unk46 * 10 + 67);
            func_800796F0_7A2F0(c->unk44, c->unk46 * 100 - 600);
        }
    }
    if (c->unk56 != 0) {
        m = &D_800FC834_FD434[obj->model[1]];
        func_800298A4_2A4A4(obj->model[1], 4, 4);
        if (--c->unk56 == 0) {
            func_800298A4_2A4A4(obj->model[1], 4, 0);
            func_800298A4_2A4A4(obj->model[2], 4, 4);
            func_800298A4_2A4A4(obj->model[3], 4, 4);
        } else if (c->unk56 & 4) {
            func_800298A4_2A4A4(obj->model[2], 4, 0);
            func_800298A4_2A4A4(obj->model[3], 4, 4);
            func_80029714_2A314(obj->model[2], m->pos.x, m->pos.y, m->pos.z);
            func_8002979C_2A39C(obj->model[2], m->rot.x, m->rot.y, m->rot.z);
        } else {
            func_800298A4_2A4A4(obj->model[2], 4, 4);
            func_800298A4_2A4A4(obj->model[3], 4, 0);
            func_80029714_2A314(obj->model[3], m->pos.x, m->pos.y, m->pos.z);
            func_8002979C_2A39C(obj->model[3], m->rot.x, m->rot.y, m->rot.z);
        }
    }
    h = (0.0f - pos.y) / d.y;
    func_801082D0_151DF0_CraneGame(h * d.x + pos.x, obj->trans.y, h * d.z + pos.z);
    func_80019378_19F78(obj);
}

#ifdef NON_MATCHING
/* Scheduling: retail loads w->unk34 in both arms and passes 0.0f as an integer zero; the
   MP1 pointer form (p = table[i]) is further off. */
s32 func_80106268_14FD88_CraneGame(omObjData* obj, Vec* out) {
    f32 m[4][4];
    f32 m2[4][4];
    Vec r;
    s32 cnt = 0;
    f32 px;
    f32 pz;
    CGWork* w;
    s32 i;
    s32 n;

    w = obj->unk_50;
    guRotateRPYF(m, obj->rot.x, obj->rot.y, obj->rot.z);
    func_80025770_26370(m, 0.0f, 1.0f, 0.0f);
    r.x = -func_800B75A8_B81A8(sqrtf(m[3][0] * m[3][0] + m[3][2] * m[3][2]), m[3][1]);
    n = 4;
    r.y = -(func_800B75A8_B81A8(m[3][2], m[3][0]) + 90.0f);
    guTranslateF(m, obj->trans.x, obj->trans.y, obj->trans.z);
    func_80025884_26484(m, r.x, r.y, 0.0f);
    if (w->unk53 == 0) {
        n = 3;
    }
    for (i = 0; i < n; i++) {
        if (w->unk53 == 0) {
            px = D_8010B998_1554B8_CraneGame[i][0];
            pz = D_8010B998_1554B8_CraneGame[i][1];
        } else {
            px = D_8010B9B0_1554D0_CraneGame[i][0];
            pz = D_8010B9B0_1554D0_CraneGame[i][1];
        }
        guTranslateF(m2, 0.0f, px * w->unk34, pz * w->unk38);
        guMtxCatF(m2, m, m2);
        if (m2[3][1] < 0.0f) {
            out[cnt].x = m2[3][0];
            out[cnt].y = m2[3][1];
            out[cnt].z = m2[3][2];
            cnt++;
        }
    }
    return cnt;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/14C320", func_80106268_14FD88_CraneGame);
#endif

void func_8010646C_14FF8C_CraneGame(s16 n, Vec* v) {
    s16 i;
    s16 j;
    f32 x;
    f32 y;
    f32 z;

    for (i = 0; i < n - 1; i++) {
        for (j = n - 1; j > i; j--) {
            if (v[i].y > v[j].y) {
                x = v[i].x;
                y = v[i].y;
                z = v[i].z;
                v[i].x = v[j].x;
                v[i].y = v[j].y;
                v[i].z = v[j].z;
                v[j].x = x;
                v[j].y = y;
                v[j].z = z;
            }
        }
    }
}

#ifdef NON_MATCHING
/* Float register allocation only (masked 0), as MP1's func_800F97D4. */
s16 func_80106568_150088_CraneGame(omObjData* obj) {
    f32 m1[4][4];
    f32 m2[4][4];
    Vec rot;
    Vec pts[64];
    f32 px;
    f32 py;
    f32 pz;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 x;
    f32 y;
    f32 z;
    f32 len;
    f32 l;
    f32 nx;
    f32 ny;
    f32 nz;
    f32 a1;
    f32 a2;
    s32 n;
    s32 n2;

    n = func_80106268_14FD88_CraneGame(obj, pts);
    if (n != 0) {
        if (n >= 2) {
            func_8010646C_14FF8C_CraneGame(n, pts);
            l = 0.0 - pts[1].y;
            obj->trans.y += l;
            pts[0].y += l;
        }
        if (obj->trans.y < 0.0) {
            l = 0.0 - pts[0].y;
            obj->trans.y += l;
            pts[0].y += l;
        } else {
            px = pts[0].x;
            py = pts[0].y;
            pz = pts[0].z;
            dx = obj->trans.x - px;
            dy = obj->trans.y - py;
            dz = obj->trans.z - pz;
            if (n == 1 && dx == 0.0 && dz == 0.0) {
                obj->trans.x = (obj->trans.x > 0.0f) ? obj->trans.x - 1.0 : obj->trans.x + 1.0;
            }
            len = sqrtf(dx * dx + dy * dy + dz * dz);
            x = obj->trans.x;
            y = obj->trans.y;
            z = obj->trans.z;
            l = 0.0 - py;
            obj->trans.y = l + y;
            py += l;
            dx = x - px;
            dy = y - py;
            dz = z - pz;
            l = sqrtf(dx * dx + dy * dy + dz * dz);
            if (l != 0.0) {
                nx = px + dx / l * len;
                ny = py + dy / l * len;
                nz = pz + dz / l * len;
                a1 = 90.0 - func_800B75A8_B81A8(py - obj->trans.y, sqrtf((px - obj->trans.x) * (px - obj->trans.x) +
                                                                  (pz - obj->trans.z) * (pz - obj->trans.z)));
                a2 = 90.0 - func_800B75A8_B81A8(py - ny, sqrtf((px - nx) * (px - nx) + (pz - nz) * (pz - nz)));
                a1 -= a2;
                obj->trans.x = nx;
                obj->trans.y = ny;
                obj->trans.z = nz;
                guRotateRPYF(m1, obj->rot.x, obj->rot.y, obj->rot.z);
                px -= obj->trans.x;
                pz -= obj->trans.z;
                l = sqrtf(px * px + pz * pz);
                if (l != 0.0) {
                    guRotateF(m2, -a1, pz / l, 0.0f, -(px / l));
                    guMtxCatF(m1, m2, m2);
                    func_80106D58_150878_CraneGame(m2, &rot);
                    obj->rot.x = rot.x;
                    obj->rot.y = rot.y;
                    obj->rot.z = rot.z;
                }
            }
            n2 = func_80106268_14FD88_CraneGame(obj, pts);
            if (n2 != 0) {
                func_8010646C_14FF8C_CraneGame(n2, pts);
                obj->trans.y -= pts[n2 - 1].y;
            }
        }
    }
    return n;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/14C320", func_80106568_150088_CraneGame);
#endif

void func_80106A28_150548_CraneGame(omObjData* obj) {
    f32 r;
    f32 r2;
    f32 dy;
    f32 rr;
    f32 lim;
    f32 dx;
    f32 dz;
    f32 d;
    f32 a;
    s16 i;
    omObjData* o;
    CGWork* ow;
    CGClaw* oc;

    ow = obj->unk_50;
    func_80107F40_151A60_CraneGame(obj);
    if (ow->unk38 > ow->unk34) {
        r = ow->unk38;
    } else {
        r = ow->unk34;
    }
    for (i = 0; i < D_800FA606_FB206; i++) {
        o = D_800F9CE0_FA8E0[i];
        oc = func_80107F40_151A60_CraneGame(o);
        ow = o->unk_50;
        if (obj == o) {
            continue;
        }
        if (oc->unk2 & 1) {
            continue;
        }
        if (oc->unk3C != 0) {
            continue;
        }
        if (ow->unk38 > ow->unk34) {
            r2 = ow->unk38;
        } else {
            r2 = ow->unk34;
        }
        dy = fabsf(o->trans.y - obj->trans.y);
        rr = r + r2;
        if (dy < rr) {
            lim = func_800B7890_B8490(dy / rr * 90.0) * rr;
            dx = o->trans.x - obj->trans.x;
            dz = o->trans.z - obj->trans.z;
            d = sqrtf(dx * dx + dz * dz);
            if (d < lim) {
                if (d != 0.0) {
                    dx /= d;
                    dz /= d;
                } else {
                    a = (rand8() * 45) >> 5;
                    dx = func_800B7890_B8490(a);
                    dz = HuMathSin(a);
                }
                d = lim - d;
                obj->trans.x += -dx * d;
                obj->trans.z += -dz * d;
            }
        }
    }
}

f32 func_80106C98_1507B8_CraneGame(f32 x, f32 z) {
    f32 a;

    if (x == 0.0 && z == 0.0) {
        a = 0.0f;
    } else {
        a = func_800B75A8_B81A8(z, x);
        if (a < 0.0) {
            a += 360.0;
        } else if (a >= 360.0) {
            a -= 360.0;
        }
    }
    return a;
}

void func_80106D58_150878_CraneGame(Matrix4f m, Vec* out) {
    f32 s;
    f32 c;
    f64 t;

    out->x = func_80106C98_1507B8_CraneGame(m[2][2], m[1][2]);
    out->z = func_80106C98_1507B8_CraneGame(m[0][0], m[0][1]);
    s = -m[0][2];
    t = 1.0 - s * s;
    if (t < 0.0) {
        t = -t;
    }
    c = sqrtf(t);
    if (out->x > 90.0 && out->x < 270.0) {
        if (out->z > 90.0 && out->z < 270.0) {
            out->x += 180.0;
            if (out->x >= 360.0) {
                out->x -= 360.0;
            }
            out->z += 180.0;
            c = -c;
            if (out->z >= 360.0) {
                out->z -= 360.0;
            }
        }
    }
    out->y = func_80106C98_1507B8_CraneGame(c, s);
}


void func_80106F00_150A20_CraneGame(omObjData* obj) {
    CGPrizeType types[9] = {
        { 2, 0, 0, 15, 14 }, { 3, 0, 0, 16, 12 }, { 4, 0, 0, 16, 12 }, { 5, 0, 0, 16, 12 }, { 6, 0, 0, 17, 16 },
        { 7, 0, 0, 19, 19 }, { 8, 0, 1, 4, 15 },  { 9, 0, 1, 4, 15 },  { 10, 0, 1, 4, 15 },
    };
    CGWork* w;
    HmfModel* m;
    s16 idx;

    w = func_80027154_27D54(sizeof(CGWork), 0x7918);
    obj->unk_50 = w;
    func_800B0EF0_B1AF0(w, 0, sizeof(CGWork));
    if (D_8010C180_155CA0_CraneGame < 3) {
        idx = gPlayers[D_8010C196_155CB6_CraneGame[D_8010C180_155CA0_CraneGame]].character;
        w->unk57 = gPlayers[D_8010C196_155CB6_CraneGame[D_8010C180_155CA0_CraneGame]].port;
    } else {
        idx = D_8010C180_155CA0_CraneGame + 3;
    }
    obj->model[0] = func_80018A30_19630(types[idx].file | 0x200000, 0xA9);
    D_800FC834_FD434[obj->model[0]].unk44 = 0.0f;
    m = &D_800FC834_FD434[obj->model[0]];
    m->unk40 = D_800F92B4_F9EB4[m->unk02].unk02;
    obj->func_ptr = func_8010755C_15107C_CraneGame;
    func_8000C35C_CF5C(obj,
                       ((f32)(s16)(D_8010C188_155CA8_CraneGame[D_8010C180_155CA0_CraneGame] % 3) * 40.0 +
                        ((f32)(s32)((u32)(rand8() * 5) >> 6) + -10.0) - 45.0) * 10.0,
                       1500.0f,
                       ((f32)(s16)(D_8010C188_155CA8_CraneGame[D_8010C180_155CA0_CraneGame] / 3) * 50.0 +
                        ((f32)(s32)((u32)(rand8() * 5) >> 6) + -10.0) - 45.0) * 10.0);
    if (D_8010C180_155CA0_CraneGame < 3) {
        obj->rot.x = (rand8() * 45) >> 5;
        obj->rot.y = (rand8() * 45) >> 5;
        obj->rot.z = (rand8() * 45) >> 5;
    } else {
        obj->rot.x = ((rand8() * 45) >> 7) - 45.0f;
        obj->rot.y = (rand8() * 45) >> 5;
        obj->rot.z = 0.0f;
    }
    func_8000C37C_CF7C(obj, 1.0f, 1.0f, 1.0f);
    w->unk53 = types[idx].unk3;
    w->unk34 = types[idx].unk4 * 10.0;
    w->unk38 = types[idx].unk6 * 10.0;
    w->unk3C = -1.0f;
    func_80109BAC_1536CC_CraneGame(obj->model[0]);
    func_80108114_151C34_CraneGame(obj->model[0]);
    func_80107DD4_1518F4_CraneGame(obj)->unk40 = D_8010C180_155CA0_CraneGame;
    D_8010C180_155CA0_CraneGame++;
}

void func_80107460_150F80_CraneGame(omObjData* obj, s16 arg1) {
    f32 m1[4][4];
    f32 m2[4][4];
    Vec rot;
    CGClaw* c;

    c = func_80107F40_151A60_CraneGame(obj);
    guRotateRPYF(m1, obj->rot.x, obj->rot.y, obj->rot.z);
    guRotateF(m2, HuMathSin((f32)c->unk42 * 11.25) * (2.0 * arg1), 1.0f, 0.0f, 0.0f);
    guMtxCatF(m1, m2, m2);
    func_80106D58_150878_CraneGame(m2, &rot);
    obj->rot.x = rot.x;
    obj->rot.y = rot.y;
    obj->rot.z = rot.z;
    c->unk42 = (c->unk42 + 1) & 0x1F;
}

void func_8010755C_15107C_CraneGame(omObjData* obj) {
    f32 y;
    s32 bit;
    u16 btn;
    HmfData* hmf;
    CGWork* w;
    CGClaw* claw;
    CGClaw* c;
    GAMEMES* mes;

    w = obj->unk_50;
    btn = 0;
    claw = func_80107F40_151A60_CraneGame(*D_800FFFD8_100BD8);
    c = func_80107F40_151A60_CraneGame(obj);
    if (c->unk0 == 0) {
        c->unk0 |= 1;
        c->unk2 = 6;
        c->unk8 = 0;
        c->unk3C = c->unk40 * 8 + 0x60;
        c->unk3E = 0;
        c->unk42 = 0;
        c->unk4C = 0;
        c->unk4E = 0;
        c->unk50 = 0;
        c->unk56 = 0;
        c->unk58 = 0;
    }
    if (c->unk40 < 3 && D_8010C178_155C98_CraneGame == 0) {
        if (!(gPlayers[D_8010C196_155CB6_CraneGame[c->unk40]].flags & 1)) {
            btn = ContBtnTrg[w->unk57];
        } else {
            btn = 0;
            if (rand8() < gPlayers[D_8010C196_155CB6_CraneGame[c->unk40]].cpu_difficulty * 12 + 8) {
                bit = 0x8000;
                btn = bit;
            }
        }
        if (btn & 0x8000) {
            if (D_800FC834_FD434[obj->model[0]].unk40 == D_800F92B4_F9EB4[D_800FC834_FD434[obj->model[0]].unk02].unk02) {
                D_800FC834_FD434[obj->model[0]].unk44 = 1.0f;
                D_800FC834_FD434[obj->model[0]].unk40 = 0.0f;
            }
        }
    }
    switch (c->unk8) {
    case 0:
        if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
            if (--c->unk3C == 0) {
                c->unk8++;
                return;
            }
        }
        return;
    case 1:
        if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
            y = obj->trans.y;
            c->unk1C += -4.0;
            obj->trans.y += c->unk1C;
            if (!(c->unk2 & 1)) {
                if (func_80106568_150088_CraneGame(obj) != 0) {
                    c->unk1C = -16.0f;
                    if (c->unk2 & 2) {
                        c->unk2 &= ~2;
                        PlaySound(0x193);
                        if (D_8010C17C_155C9C_CraneGame == 0) {
                            D_8010C17A_155C9A_CraneGame = 1;
                        }
                        D_8010C258_155D78_CraneGame++;
                    }
                } else {
                    c->unk2 |= 2;
                }
            } else {
                if (c->unk58 < 48) {
                    obj->scale.x = obj->scale.y = obj->scale.z = 1.0f - c->unk58 / 48.0f;
                    c->unk58++;
                }
                if (obj->trans.y < 300.0) {
                    hmf = D_800FC834_FD434[D_8010C186_155CA6_CraneGame].hmf;
                    if (obj->trans.x != hmf->unk84->unk04.x) {
                        if (hmf->unk84->unk04.x < obj->trans.x) {
                            obj->trans.x -= 20.0;
                            if (obj->trans.x < hmf->unk84->unk04.x) {
                                obj->trans.x = hmf->unk84->unk04.x;
                            }
                        } else {
                            obj->trans.x += 20.0;
                            if (hmf->unk84->unk04.x < obj->trans.x) {
                                obj->trans.x = hmf->unk84->unk04.x;
                            }
                        }
                    }
                    if (obj->trans.z != hmf->unk84->unk04.z) {
                        if (hmf->unk84->unk04.z < obj->trans.z) {
                            obj->trans.z -= 20.0;
                            if (obj->trans.z < hmf->unk84->unk04.z) {
                                obj->trans.z = hmf->unk84->unk04.z;
                            }
                        } else {
                            obj->trans.z += 20.0;
                            if (hmf->unk84->unk04.z < obj->trans.z) {
                                obj->trans.z = hmf->unk84->unk04.z;
                            }
                        }
                    }
                }
                if (y >= 300.0 && obj->trans.y < 300.0) {
                    PlaySound(0x194);
                    omVibrate(D_8010C194_155CB4_CraneGame, 2, 2, 20);
                    mes = &D_800F9570_FA170[D_8010C170_155C90_CraneGame->work[0]];
                    switch (c->unk40) {
                    default:
                        D_8010C1A0_155CC0_CraneGame++;
                        break;
                    case 3:
                        D_8010C17C_155C9C_CraneGame += 600;
                        mes->unk0A = 0;
                        mes->unk04 = 2;
                        break;
                    case 4:
                        D_8010C17C_155C9C_CraneGame += 450;
                        mes->unk0A = 0;
                        mes->unk04 = 2;
                        break;
                    case 5:
                        D_8010C17C_155C9C_CraneGame += 900;
                        mes->unk0A = 0;
                        mes->unk04 = 2;
                        break;
                    }
                    if (D_8010C1A0_155CC0_CraneGame == 3) {
                        D_8010C17A_155C9A_CraneGame = 1;
                    }
                    claw->unk56 = 32;
                }
                if (obj->trans.y < -2000.0) {
                    c->unk8 = -1;
                    c->unk2 &= ~4;
                    if (D_8010C17C_155C9C_CraneGame == 0) {
                        D_8010C17A_155C9A_CraneGame = 1;
                    }
                }
            }
        }
        if ((c->unk2 & 1) && func_801033E4_14CF04_CraneGame(obj->trans.y) != 0) {
            func_80108238_151D58_CraneGame(D_8010C186_155CA6_CraneGame, 0.0f);
        }
        func_80106A28_150548_CraneGame(obj);
        if (w->unk34 > w->unk38) {
            y = w->unk34;
        } else {
            y = w->unk38;
        }
        func_801035C0_14D0E0_CraneGame(&obj->trans.x, &obj->trans.y, &obj->trans.z, 0.0f, 0.0f, 0.0f, y, (c->unk2 & 1) + 1);
        return;
    case 2:
        if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
            if (c->unk3E != 0) {
                c->unk8 = 1;
                c->unk2 |= 2;
                if ((s16)func_80103338_14CE58_CraneGame(obj) != 0) {
                    c->unk2 |= 1;
                } else {
                    c->unk2 &= ~1;
                }
                c->unk3E = 0;
                c->unk1C = 0.0f;
                c->unk4E = 0;
                c->unk4C = 0;
                return;
            }
            func_801081C8_151CE8_CraneGame(obj->model[0], 0.0f);
            c->unk4E++;
            if (btn & 0x8000) {
                c->unk4C++;
                if (c->unk56 == 0) {
                    omVibrate(D_8010C194_155CB4_CraneGame, 5, 0, 5);
                    c->unk56 = 4;
                }
            }
            c->unk50 = (f32)c->unk4C / (f32)c->unk4E * 30.0;
            if (c->unk56 != 0) {
                c->unk56--;
            }
            func_80107460_150F80_CraneGame(obj, claw->unk40);
        }
        break;
    }
}

CGClaw* func_80107DD4_1518F4_CraneGame(omObjData* arg0) {
    CGClaw* temp_v0;

    temp_v0 = HuMemMemoryAllocPerm(sizeof(CGClaw));
    D_8010CE30_156950_CraneGame[D_8010D234_156D54_CraneGame] = temp_v0;
    arg0->work[0] = (u32)temp_v0 >> 0x18;
    arg0->work[1] = (u32)temp_v0 >> 0x10;
    arg0->work[2] = (u32)temp_v0 >> 8;
    arg0->work[3] = (u32)temp_v0;
    temp_v0->unk0 = 0;
    temp_v0->unk2 = 0;
    temp_v0->unk8 = 0;
    temp_v0->unkA = (u16)D_8010D234_156D54_CraneGame;
    temp_v0->unkC = temp_v0->unk10 = temp_v0->unk14 = 0.0f;
    temp_v0->unk18 = temp_v0->unk1C = temp_v0->unk20 = 0.0f;
    temp_v0->unk24 = temp_v0->unk28 = temp_v0->unk2C = 0.0f;
    temp_v0->unk3C = temp_v0->unk3E = temp_v0->unk40 = temp_v0->unk42 = 0;
    temp_v0->unk44 = temp_v0->unk46 = temp_v0->unk48 = temp_v0->unk4A = 0;
    temp_v0->unk4C = temp_v0->unk4E = temp_v0->unk50 = temp_v0->unk52 = 0;
    temp_v0->unk54 = temp_v0->unk56 = temp_v0->unk58 = temp_v0->unk5A = 0;
    D_8010D234_156D54_CraneGame++;
    return temp_v0;
}

void func_80107EC0_1519E0_CraneGame(void) {
    s16 i;

    for (i = 0; i < D_8010D234_156D54_CraneGame; i++) {
        if (D_8010CE30_156950_CraneGame[i] != NULL) {
            HuMemMemoryFreePerm(D_8010CE30_156950_CraneGame[i]);
        }
    }
}

CGClaw* func_80107F40_151A60_CraneGame(omObjData* arg0) {
    return (CGClaw*)((arg0->work[0] << 0x18) | (arg0->work[1] << 0x10) | (arg0->work[2] << 8) | arg0->work[3]);
}
