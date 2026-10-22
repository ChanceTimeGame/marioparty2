#include "ovl_10.h"

void func_80107F70_151A90_CraneGame(void) {
    void* p;

    D_8010C264_155D84_CraneGame = 0;
    D_8010C262_155D82_CraneGame = 0;
    D_8010C904_156424_CraneGame = 0;
    D_8010C260_155D80_CraneGame = func_8002838C_28F8C(0, func_801082F4_151E14_CraneGame, 2);
    D_8010C8F8_156418_CraneGame.x = D_8010C8F8_156418_CraneGame.y = D_8010C8F8_156418_CraneGame.z = 0.0f;
    D_8010CAF0_156610_CraneGame = 1.0f;
    D_8010C908_156428_CraneGame = 0;
    p = DataRead(0x200012);
    D_8010C8E8_156408_CraneGame = SprAnimRead(p);
    DataClose(p);
    D_8010C8EC_15640C_CraneGame = **SprAnimGet(D_8010C8E8_156408_CraneGame);
}

void func_80108038_151B58_CraneGame(void) {
    s32 i;

    if (D_8010C262_155D82_CraneGame != 0) {
        for (i = 0; i < D_8010C262_155D82_CraneGame; i++) {
            HuMemFree(D_8010C4E8_156008_CraneGame[i][0]);
            HuMemFree(D_8010C4E8_156008_CraneGame[i][1]);
            HuMemFree(D_8010C4E8_156008_CraneGame[i][2]);
            HuMemFree(D_8010C7E8_156308_CraneGame[i]->dl);
            HuMemFree(D_8010C7E8_156308_CraneGame[i]);
        }
    }
    func_800283DC_28FDC(D_8010C260_155D80_CraneGame);
    D_8010C264_155D84_CraneGame = 0;
    D_8010C262_155D82_CraneGame = 0;
}

void func_80108114_151C34_CraneGame(s16 model) {
    D_8010C268_155D88_CraneGame[D_8010C262_155D82_CraneGame] = model;
    D_8010C2E8_155E08_CraneGame[D_8010C262_155D82_CraneGame].cur = 1.0f;
    D_8010C2E8_155E08_CraneGame[D_8010C262_155D82_CraneGame].target = 1.0f;
    D_8010C4E8_156008_CraneGame[D_8010C262_155D82_CraneGame][0] = NULL;
    D_8010C4E8_156008_CraneGame[D_8010C262_155D82_CraneGame][1] = NULL;
    D_8010C4E8_156008_CraneGame[D_8010C262_155D82_CraneGame][2] = NULL;
    D_8010C7E8_156308_CraneGame[D_8010C262_155D82_CraneGame] = NULL;
    D_8010C8F0_156410_CraneGame = D_8010C262_155D82_CraneGame;
    func_80108D18_152838_CraneGame(model);
    D_8010C262_155D82_CraneGame++;
}

void func_801081C8_151CE8_CraneGame(s16 model, f32 target) {
    s32 i;

    for (i = 0; i < D_8010C262_155D82_CraneGame; i++) {
        if (D_8010C268_155D88_CraneGame[i] == model) {
            D_8010C2E8_155E08_CraneGame[i].target = target;
            return;
        }
    }
}

void func_80108238_151D58_CraneGame(s16 model, f32 target) {
    s32 i;

    for (i = 0; i < D_8010C262_155D82_CraneGame; i++) {
        if (D_8010C268_155D88_CraneGame[i] == model) {
            D_8010C2E8_155E08_CraneGame[i].cur = D_8010C2E8_155E08_CraneGame[i].target = target;
            return;
        }
    }
}

void func_801082B8_151DD8_CraneGame(f32 y) {
    D_8010C908_156428_CraneGame = 1;
    D_8010C90C_15642C_CraneGame = y;
}

void func_801082D0_151DF0_CraneGame(f32 x, f32 y, f32 z) {
    D_8010C8F8_156418_CraneGame.x = x;
    D_8010C8F8_156418_CraneGame.y = y;
    D_8010C8F8_156418_CraneGame.z = z;
}

void func_801082E8_151E08_CraneGame(f32 scale) {
    D_8010CAF0_156610_CraneGame = scale;
}

void func_801082F4_151E14_CraneGame(Gfx** gfx, Mtx* mtx) {
    Matrix4f m1;
    Matrix4f m2;
    Matrix4f inv;
    HmfModel* p;
    HmfData* m;
    s32 i;
    s16 mdl;
    f32 a;

    if (++D_8010C264_155D84_CraneGame >= 3) {
        D_8010C264_155D84_CraneGame = 0;
    }
    D_8010C904_156424_CraneGame = (D_8010C904_156424_CraneGame + 1) & 0xF;
    gDPPipeSync((*gfx)++);
    gSPDisplayList((*gfx)++, D_8010BCE0_155800_CraneGame);
    gDPPipeSync((*gfx)++);
    gDPSetCycleType((*gfx)++, G_CYC_1CYCLE);
    gSPSetGeometryMode((*gfx)++, G_ZBUFFER | G_CULL_BACK | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH);
    gDPSetRenderMode((*gfx)++, G_RM_AA_ZB_XLU_DECAL, G_RM_NOOP2);
    gDPSetCombineLERP((*gfx)++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, SHADE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, SHADE, 0);
    gDPSetAlphaCompare((*gfx)++, G_AC_THRESHOLD);
    gDPSetBlendColor((*gfx)++, 0x08, 0x08, 0x08, 0x08);
    gDPSetColorDither((*gfx)++, G_CD_NOISE);
    gDPSetAlphaDither((*gfx)++, G_AD_PATTERN);
    gDPSetTexturePersp((*gfx)++, G_TP_PERSP);
    gDPSetPrimColor((*gfx)++, 0, 0, 0xFF, 0xFF, 0xFF, 0xB0);
    gDPLoadTextureBlock_4b((*gfx)++, D_8010C8EC_15640C_CraneGame, G_IM_FMT_I, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                           G_TX_NOMIRROR | G_TX_CLAMP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gSPTexture((*gfx)++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    func_800204C0_210C0(0, gfx);
    func_800B30D0_B3CD0(m1, mtx + 1);
    func_80025770_26370(m1, D_8010C8F8_156418_CraneGame.x, D_8010C8F8_156418_CraneGame.y, D_8010C8F8_156418_CraneGame.z);
    func_800B1F50_B2B50(m2, -m1[3][0], -m1[3][1], -m1[3][2]);
    func_80025F00_26B00(m1, inv);
    func_800B6410_B7010(m2, inv, inv);
    for (i = 0; i < D_8010C262_155D82_CraneGame; i++) {
        D_8010C8F0_156410_CraneGame = i;
        if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
            if (D_8010C2E8_155E08_CraneGame[i].cur < CG_FADE_TARGET(i)) {
                D_8010C2E8_155E08_CraneGame[i].cur += 0.1;
                if (CG_FADE_TARGET(i) < D_8010C2E8_155E08_CraneGame[i].cur) {
                    D_8010C2E8_155E08_CraneGame[i].cur = CG_FADE_TARGET(i);
                }
            } else {
                D_8010C2E8_155E08_CraneGame[i].cur -= 0.1;
                if (D_8010C2E8_155E08_CraneGame[i].cur < CG_FADE_TARGET(i)) {
                    D_8010C2E8_155E08_CraneGame[i].cur = CG_FADE_TARGET(i);
                }
            }
            CG_FADE_TARGET(i) = 1.0f;
        }
        a = D_8010C2E8_155E08_CraneGame[i].cur;
        D_8010C8F4_156414_CraneGame = a;
        mdl = D_8010C268_155D88_CraneGame[i];
        if (mdl >= 0) {
            p = &D_800FC834_FD434[mdl];
            m = p->hmf;
            if (m != NULL) {
                if (!(p->unk18 & 4)) {
                    if (a != 0.0f) {
                        *gfx = func_8010887C_15239C_CraneGame(*gfx, m, inv);
                    }
                }
            }
        }
    }
    gDPPipeSync((*gfx)++);
    gDPSetRenderMode((*gfx)++, 0x404BD8, 0);
    *gfx = func_801097A0_1532C0_CraneGame(*gfx, mtx);
    gDPPipeSync((*gfx)++);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/151A90", func_8010887C_15239C_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/151A90", func_80108D18_152838_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/151A90", func_80109024_152B44_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/151A90", func_801091D4_152CF4_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/151A90", func_801093A0_152EC0_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/151A90", func_801095A4_1530C4_CraneGame);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_10_CraneGame/151A90", func_801097A0_1532C0_CraneGame);
