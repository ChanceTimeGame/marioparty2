#include "ovl_4F.h"

void func_8010D210_33FE50_name_4F(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_80110460_3430A0_name_4F[i][0] = NULL;
        D_801104E0_343120_name_4F[i][0] = NULL;
    }
}

omObjData* func_8010D248_33FE88_name_4F(void (*init)(omObjData*), void (*func)(omObjData*), s32 nvtx, s32 ngfx) {
    omObjData* obj;
    s16 slot;
    s32 i;

    obj = omAddObj(0x1F4, 1, 0, -1, func);
    for (slot = 0; slot < 4; slot++) {
        if (D_801104E0_343120_name_4F[slot][0] == NULL) {
            break;
        }
    }
    if (slot == 4) {
        return NULL;
    }
    obj->work[0] = 0;
    obj->work[1] = slot;
    for (i = 0; i < D_800FDBCA_FE7CA; i++) {
        D_80110460_3430A0_name_4F[slot][i] = func_80027154_27D54(nvtx * sizeof(Vtx), 0x7918);
        D_801104E0_343120_name_4F[slot][i] = func_80027154_27D54(ngfx * sizeof(Gfx), 0x7918);
    }
    if (init != NULL) {
        init(obj);
    }
    obj->model[0] = func_80027FA4_28BA4(0x684, D_801104E0_343120_name_4F[slot][D_800FDBE0_FE7E0], 4);
    return obj;
}

void func_8010D3E8_340028_name_4F(omObjData* obj) {
    u8 slot = obj->work[1];
    s16 i;

    func_800283DC_28FDC(obj->model[0]);
    for (i = 0; i < D_800FDBCA_FE7CA; i++) {
        if (D_80110460_3430A0_name_4F[slot][i] != NULL) {
            HuMemFree(D_80110460_3430A0_name_4F[slot][i]);
            D_80110460_3430A0_name_4F[slot][i] = NULL;
        }
        if (D_801104E0_343120_name_4F[slot][i] != NULL) {
            HuMemFree(D_801104E0_343120_name_4F[slot][i]);
            D_801104E0_343120_name_4F[slot][i] = NULL;
        }
    }
    omDelObj(obj);
}

omObjData* func_8010D4D8_340118_name_4F(void) {
    omObjData* obj;

    obj = func_8010D248_33FE88_name_4F(func_8010D528_340168_name_4F, func_8010D6FC_34033C_name_4F, 48, 114);
    obj->unk_50 = func_80027154_27D54(16 * sizeof(Ovl4FStreak), 0x7918);
    return obj;
}

/* NON_MATCHING: retail hoists the 0xE3000A01 (cycle type) word out of the loop with the other
   constants; everything else matches. */
#ifdef NON_MATCHING
void func_8010D528_340168_name_4F(omObjData* obj) {
    Gfx* gfx;
    Vtx* vtx;
    s32 i;
    s32 rest;
    s32 n;
    s32 base;
    s32 k;
    u8 slot = obj->work[1];

    for (i = 0; i < D_800FDBCA_FE7CA; i++) {
        gfx = D_801104E0_343120_name_4F[slot][i];
        vtx = D_80110460_3430A0_name_4F[slot][i];
        rest = 48;
        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_1CYCLE);
        gDPSetRenderMode(gfx++, G_RM_ZB_OPA_SURF, G_RM_ZB_OPA_SURF2);
        gSPClearGeometryMode(gfx++, G_LIGHTING);
        gDPSetCombineMode(gfx++, G_CC_SHADE, G_CC_SHADE);
        gSPTexture(gfx++, 0, 0x8000, 0, G_TX_RENDERTILE, G_OFF);
        base = 0;
        do {
            n = rest;
            if (rest >= 30) {
                n = 30;
            }
            rest -= n;
            gSPVertex(gfx++, &vtx[base], n, 0);
            for (k = 0; k < n; k += 3) {
                gSP1Triangle(gfx++, k, k + 1, k + 2, 0);
            }
            base += n;
        } while (rest != 0);
        gDPPipeSync(gfx++);
        gSPEndDisplayList(gfx++);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/33FE50", func_8010D528_340168_name_4F);
#endif

/* NON_MATCHING: the colour fade clamps (max 0) differ: retail sign-extends the green and blue
   differences as s16 before the clamp and orders the first and differently. Logic checked. */
#ifdef NON_MATCHING
void func_8010D6FC_34033C_name_4F(omObjData* obj) {
    Vec dir;
    Vtx* vtx;
    Ovl4FStreak* p;
    s32 i;
    s32 k;
    s32 r;
    s16 g;
    s16 b;
    u8 slot = obj->work[1];

    *(Gfx**)D_800FC834_FD434[obj->model[0]].hmf->unk3C = D_801104E0_343120_name_4F[slot][D_800FDBE0_FE7E0];
    if (obj->work[0] != 0) {
        vtx = D_80110460_3430A0_name_4F[slot][D_800FDBE0_FE7E0];
        p = obj->unk_50;
        for (i = 0; i < 16; i++, p++) {
            dir.x = p->dir.x;
            dir.y = p->dir.y;
            dir.z = p->dir.z;
            MBVecNormalize(&dir);
            for (k = 0; k < 4; k++) {
                vtx->v.cn[k] = p->col[0][k];
            }
            vtx->v.ob[0] = p->pos.x;
            vtx->v.ob[1] = p->pos.y;
            vtx->v.ob[2] = p->pos.z;
            vtx++;
            for (k = 0; k < 4; k++) {
                vtx->v.cn[k] = p->col[1][k];
            }
            vtx->v.ob[0] = dir.x * p->len + p->pos.x;
            vtx->v.ob[1] = dir.y * p->len + p->pos.y;
            vtx->v.ob[2] = dir.z * p->len + p->pos.z;
            vtx++;
            for (k = 0; k < 4; k++) {
                vtx->v.cn[k] = p->col[2][k];
            }
            vtx->v.ob[0] = (dir.x + 0.08f) * (p->len - 15.0f) + p->pos.x;
            vtx->v.ob[1] = (p->len - 15.0f) * dir.y + p->pos.y;
            vtx->v.ob[2] = (p->len - 15.0f) * dir.z + p->pos.z;
            vtx++;
            p->pos.x += dir.x * p->speed;
            p->pos.y += dir.y * p->speed;
            p->pos.z += dir.z * p->speed;
            for (k = 0; k < 3; k++) {
                r = p->col[k][0] - 5;
                if (r < 0) {
                    r = 0;
                }
                p->col[k][0] = r;
                g = p->col[k][1] - 13;
                if (g < 0) {
                    g = 0;
                }
                p->col[k][1] = g;
                b = p->col[k][2] - 18;
                if (b < 0) {
                    b = 0;
                }
                p->col[k][2] = b;
            }
        }
        if (++obj->work[2] >= obj->work[3]) {
            obj->work[0] = 0;
            func_800298A4_2A4A4(obj->model[0], 4, 4);
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/33FE50", func_8010D6FC_34033C_name_4F);
#endif

void func_8010DA90_3406D0_name_4F(omObjData* obj, f32 x, f32 y, f32 z, u8 frames) {
    Ovl4FStreak* p;
    s32 i;
    s32 j;
    s32 k;

    omSetTra(obj, x, y, z);
    obj->work[3] = frames;
    obj->work[0] = 1;
    obj->work[2] = 0;
    func_800298A4_2A4A4(obj->model[0], 4, 0);
    p = obj->unk_50;
    for (i = 0; i < 16; i++, p++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 4; k++) {
                p->col[j][k] = D_80110390_342FD0_name_4F[j][k];
            }
        }
        p->pos.x = p->pos.y = p->pos.z = 0.0f;
        p->len = (u8)(rand8() % 120) - 40;
        p->speed = (u8)(rand8() % 110) - 50;
        p->dir.x = HuMathSin((rand8() + rand8()) % 360);
        p->dir.y = HuMathSin((rand8() + rand8()) % 360);
        p->dir.z = HuMathSin((rand8() + rand8()) % 360);
        if (p->dir.x == 0.0f && p->dir.y == 0.0f && p->dir.z == 0.0f) {
            p->dir.y = 1.0f;
        }
        MBVecNormalize(&p->dir);
    }
}

omObjData* func_8010DD7C_3409BC_name_4F(void) {
    omObjData* obj;

    obj = func_8010D248_33FE88_name_4F(func_8010DDCC_340A0C_name_4F, func_8010DFCC_340C0C_name_4F, 17, 114);
    obj->unk_50 = func_80027154_27D54(sizeof(Ovl4FDiscWork), 0x7918);
    return obj;
}

void func_8010DDCC_340A0C_name_4F(omObjData* obj) {
    Gfx* gfx;
    Vtx* vtx;
    s32 i;
    s32 rest;
    s32 n;
    s32 base;
    s32 k;
    u8 slot = obj->work[1];

    for (i = 0; i < D_800FDBCA_FE7CA; i++) {
        gfx = D_801104E0_343120_name_4F[slot][i];
        vtx = D_80110460_3430A0_name_4F[slot][i];
        rest = 17;
        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_1CYCLE);
        gDPSetRenderMode(gfx++, G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2);
        gSPClearGeometryMode(gfx++, G_LIGHTING);
        gDPSetCombineMode(gfx++, G_CC_SHADE, G_CC_SHADE);
        gSPTexture(gfx++, 0, 0x8000, 0, G_TX_RENDERTILE, G_OFF);
        base = 0;
        do {
            n = rest;
            if (rest >= 30) {
                n = 30;
            }
            rest -= n;
            gSPVertex(gfx++, &vtx[base], n, 0);
            for (k = 1; k < n; k++) {
                if (k < n - 1) {
                    gSP1Triangle(gfx++, 0, k + 1, k, 0);
                } else {
                    gSP1Triangle(gfx++, 0, 1, k, 0);
                }
            }
            base += n;
        } while (rest != 0);
        gDPPipeSync(gfx++);
        gSPEndDisplayList(gfx++);
    }
}

void func_8010DFCC_340C0C_name_4F(omObjData* obj) {
    Vtx* vtx;
    Ovl4FDiscWork* work;
    f32 angle;
    s32 i;
    s32 k;
    u8 slot = obj->work[1];

    *(Gfx**)D_800FC834_FD434[obj->model[0]].hmf->unk3C = D_801104E0_343120_name_4F[slot][D_800FDBE0_FE7E0];
    if (obj->work[0] != 0) {
        vtx = D_80110460_3430A0_name_4F[slot][D_800FDBE0_FE7E0];
        work = obj->unk_50;
        vtx->v.ob[0] = 0;
        vtx->v.ob[1] = 0;
        vtx->v.ob[2] = 0;
        for (k = 0; k < 3; k++) {
            vtx->v.cn[k] = fabs(HuMathSin(work->col[0][k])) * 255.0;
            work->col[0][k] += work->vel[0][k];
            if (work->col[0][k] >= 360.0f) {
                work->col[0][k] -= 360.0f;
            }
        }
        vtx->v.cn[3] = work->col[0][3];
        vtx++;
        angle = 0.0f;
        for (i = 1; i < 17; i++) {
            vtx->v.ob[0] = HuMathSin(angle) * work->radius;
            vtx->v.ob[1] = func_800B7890_B8490(angle) * work->radius;
            vtx->v.ob[2] = 0;
            work->rot[i - 1] += 5.0f;
            if (work->rot[i - 1] >= 360.0f) {
                work->rot[i - 1] -= 360.0f;
            }
            for (k = 0; k < 3; k++) {
                vtx->v.cn[k] = fabs(HuMathSin(work->col[i][k])) * 255.0;
                work->col[i][k] += work->vel[i][k];
                if (work->col[i][k] >= 360.0f) {
                    work->col[i][k] -= 360.0f;
                }
            }
            vtx->v.cn[3] = work->col[0][3]; /* retail: the centre's alpha for every vertex */
            vtx++;
            angle += 22.5f;
        }
        if (work->radius < 180.0f) {
            work->radius += 30.0f;
            return;
        }
        if (obj->work[2] == 1) {
            for (i = 0; i < 17; i++) {
                work->col[i][3] -= work->vel[i][3];
                if (work->col[i][3] < 0.0f) {
                    work->col[i][3] = 0.0f;
                }
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/33FE50", func_8010E430_341070_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/33FE50", func_8010E5D8_341218_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/33FE50", func_8010E610_341250_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/33FE50", func_8010E660_3412A0_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/33FE50", func_8010E70C_34134C_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/33FE50", func_8010E950_341590_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/33FE50", func_8010EF9C_341BDC_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/33FE50", func_8010F128_341D68_name_4F);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/33FE50", func_8010F188_341DC8_name_4F);
