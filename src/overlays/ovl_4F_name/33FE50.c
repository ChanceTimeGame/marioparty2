#include "ovl_4F.h"

/* .data (0x342FD0-0x342FE0) */
u8 D_80110390_342FD0_name_4F[3][4] = {
    { 0xFF, 0xFA, 0xBE, 0xFF },
    { 0xFF, 0xBE, 0x6E, 0xFF },
    { 0xFF, 0xD2, 0x3C, 0xFF },
};


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

void func_8010E430_341070_name_4F(omObjData* obj, f32 x, f32 y, f32 z, f32 rotY) {
    Ovl4FDiscWork* work = obj->unk_50;
    s32 i;

    func_800298A4_2A4A4(obj->model[0], 4, 0);
    obj->work[0] = 1;
    obj->trans.x = x;
    obj->trans.y = y;
    obj->trans.z = z;
    obj->rot.x = obj->rot.z = 0.0f;
    obj->rot.y = rotY;
    obj->scale.x = obj->scale.y = obj->scale.z = 1.0f;
    for (i = 0; i < 16; i++) {
        work->rot[i] = (i & 1) * 180.0f;
    }
    work->radius = 0.0f;
    work->col[0][0] = 315.0f;
    work->col[0][1] = 0.0f;
    work->col[0][2] = 45.0f;
    work->col[0][3] = 255.0f;
    work->vel[0][0] = 4.0f;
    work->vel[0][1] = 0.0f;
    work->vel[0][2] = 4.0f;
    work->vel[0][3] = 10.0f;
    for (i = 1; i < 17; i++) {
        work->col[i][0] = 90.0f;
        work->col[i][1] = 0.0f;
        work->col[i][2] = 0.0f;
        work->col[i][3] = 64.0f;
        work->vel[i][0] = 4.0f;
        work->vel[i][1] = 0.0f;
        work->vel[i][2] = 4.0f;
        work->vel[i][3] = 10.0f;
    }
}

void func_8010E5D8_341218_name_4F(omObjData* obj) {
    func_800298A4_2A4A4(obj->model[0], 4, 4);
    obj->work[0] = 0;
}

omObjData* func_8010E610_341250_name_4F(void) {
    omObjData* obj;

    obj = func_8010D248_33FE88_name_4F(func_8010E660_3412A0_name_4F, func_8010E950_341590_name_4F, 260, 690);
    obj->unk_50 = func_80027154_27D54(sizeof(Ovl4FBoltWork), 0x7918);
    return obj;
}

void func_8010E660_3412A0_name_4F(omObjData* obj) {
    u8 slot = obj->work[1];
    s16 i;

    for (i = 0; i < D_800FDBCA_FE7CA; i++) {
        func_8010E70C_34134C_name_4F(obj, D_801104E0_343120_name_4F[slot][i], D_80110460_3430A0_name_4F[slot][i]);
    }
}

void func_8010E70C_34134C_name_4F(omObjData* obj, Gfx* gfx, Vtx* vtx) {
    Ovl4FBoltWork* work = obj->unk_50;
    s32 rest;
    s32 n;
    s32 base;
    s32 k;

    if (obj->work[0] == 1) {
        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_1CYCLE);
        gDPSetRenderMode(gfx++, G_RM_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2);
        gSPClearGeometryMode(gfx++, G_LIGHTING);
        gDPSetCombineMode(gfx++, G_CC_SHADE, G_CC_SHADE);
        gSPTexture(gfx++, 0, 0x8000, 0, G_TX_RENDERTILE, G_OFF);
        rest = work->count * 4;
        base = 0;
        while (rest > 4) {
            n = 32;
            if (rest < 33) {
                n = rest;
            }
            gSPVertex(gfx++, &vtx[base], n, 0);
            for (k = 4; k < n; k += 4) {
                gSP1Triangle(gfx++, k - 2, k - 1, k + 2, 0);
                gSP1Triangle(gfx++, k - 1, k + 3, k + 2, 0);
                gSP1Triangle(gfx++, k - 4, k - 3, k, 0);
                gSP1Triangle(gfx++, k - 3, k + 1, k, 0);
            }
            n -= 4;
            rest -= n;
            base += n;
        }
        gDPPipeSync(gfx++);
    }
    gSPEndDisplayList(gfx++);
}

/* NON_MATCHING: register allocation (work/i swapped in s0/s1) and retail reuses i * 4 for seg[i]
   at the loop head; masked 6. */
#ifdef NON_MATCHING
void func_8010E950_341590_name_4F(omObjData* obj) {
    Vtx* vtx;
    f32 step;
    s32 i;
    Ovl4FBoltWork* work;
    s32 j;
    s32 k;
    s32 a;

    *(Gfx**)D_800FC834_FD434[obj->model[0]].hmf->unk3C = D_801104E0_343120_name_4F[obj->work[1]][D_800FDBE0_FE7E0];
    if (obj->work[0] != 0) {
        vtx = D_80110460_3430A0_name_4F[obj->work[1]][D_800FDBE0_FE7E0];
        work = obj->unk_50;
        i = work->count - 1;
        step = work->speed;
        if ((work->seg[i] -= step) <= 0.0f) {
            while (work->done == 0) {
                step = -work->seg[i];
                for (j = 0; j < 2; j++) {
                    work->edge[j][i].x = work->targetA[j].x;
                    work->edge[j][i].y = work->targetA[j].y;
                    work->edge[j][i].z = work->targetA[j].z;
                    work->edge2[j][i].x = work->targetB[j].x;
                    work->edge2[j][i].y = work->targetB[j].y;
                    work->edge2[j][i].z = work->targetB[j].z;
                }
                if (func_8010F188_341DC8_name_4F(work)) {
                    work->done = 1;
                    break;
                }
                i = work->count - 1;
                if (!((work->seg[i] -= step) <= 0.0f)) {
                    break;
                }
            }
        }
        if (work->done == 0) {
            for (j = 0; j < 2; j++) {
                work->edge[j][i].x += step * work->dirA[j].x;
                work->edge[j][i].y += step * work->dirA[j].y;
                work->edge[j][i].z += step * work->dirA[j].z;
                work->edge2[j][i].x += step * work->dirB[j].x;
                work->edge2[j][i].y += step * work->dirB[j].y;
                work->edge2[j][i].z += step * work->dirB[j].z;
            }
        } else {
            switch (work->mode) {
                case 0:
                    work->dir.x = 1.0f - work->dir.x;
                    work->dir.z = 1.0f - work->dir.z;
                    work->dir.y += rand8() / 50.0f;
                    MBVecNormalize(&work->dir);
                    work->length += 500.0f;
                    work->mode = 1;
                    func_8010F128_341D68_name_4F(work);
                    work->done = 0;
                    break;
                case 1:
                    for (i = 0; i < work->count; i++) {
                        work->col[i][3] -= 40.0f;
                        if (work->col[i][3] < 0.0f) {
                            work->col[i][3] = 0.0f;
                        }
                    }
                    break;
            }
        }
        for (i = 0; i < work->count; i++) {
            for (j = 0; j < 2; j++) {
                for (k = 0; k < 4; k++) {
                    vtx->v.cn[k] = work->col[i][k];
                }
                vtx->v.ob[0] = work->edge[j][i].x;
                vtx->v.ob[1] = work->edge[j][i].y;
                vtx->v.ob[2] = work->edge[j][i].z;
                vtx++;
            }
            for (j = 0; j < 2; j++) {
                for (k = 0; k < 4; k++) {
                    vtx->v.cn[k] = work->col[i][k];
                }
                a = work->col[i][3];
                a = a - 30.0f;
                if (a < 0.0f) {
                    a = 0;
                }
                vtx->v.cn[3] = a;
                vtx->v.ob[0] = work->edge2[j][i].x;
                vtx->v.ob[1] = work->edge2[j][i].y;
                vtx->v.ob[2] = work->edge2[j][i].z;
                vtx++;
            }
        }
        func_8010E70C_34134C_name_4F(obj, D_801104E0_343120_name_4F[obj->work[1]][D_800FDBE0_FE7E0],
                                     D_80110460_3430A0_name_4F[obj->work[1]][D_800FDBE0_FE7E0]);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/33FE50", func_8010E950_341590_name_4F);
#endif

void func_8010EF9C_341BDC_name_4F(omObjData* obj, u8* col, f32* colVel, Vec* dir, f32 width, f32 length, f32 speed, u16 mode) {
    Ovl4FBoltWork* work = obj->unk_50;
    s32 i;

    obj->work[0] = 1;
    func_800298A4_2A4A4(obj->model[0], 4, 0);
    work->dir = *dir;
    func_8010F128_341D68_name_4F(work);
    for (i = 0; i < 4; i++) {
        work->col0[i] = col[i];
        work->colVel[i] = colVel[i];
    }
    work->length = length;
    work->speed = speed;
    work->mode = mode;
    work->width = width;
    work->done = 0;
    work->sign = 1;
    work->count = 1;
    for (i = 0; i < 2; i++) {
        work->edge[i][0].x = 0.0f;
        work->edge[i][0].y = 0.0f;
        work->edge[i][0].z = 0.0f;
        work->edge2[i][0].x = 0.0f;
        work->edge2[i][0].y = 0.0f;
        work->edge2[i][0].z = 0.0f;
    }
    for (i = 0; i < 4; i++) {
        work->col[0][i] = col[i];
    }
    work->spine[0].x = 0.0f;
    work->spine[0].y = 0.0f;
    work->spine[0].z = 0.0f;
    func_8010F188_341DC8_name_4F(work);
}

void func_8010F128_341D68_name_4F(Ovl4FBoltWork* work) {
    f32 angle = func_80042BE0_437E0(&work->dir) + 90.0f;

    work->side.x = HuMathSin(angle);
    work->side.y = 0.0f;
    work->side.z = func_800B7890_B8490(angle);
    MBVecNormalize(&work->side);
}

/* NON_MATCHING: instruction order only: the spine[i] sum computes &spine[i - 1] before &seg[i],
   and hoists width + 5.0f after the loop's other invariants. */
#ifdef NON_MATCHING
u16 func_8010F188_341DC8_name_4F(Ovl4FBoltWork* work) {
    f32 dist;
    f32 width;
    s32 i;
    s32 j;
    s32 k;
    s32 n;

    if (work->count == 64) {
        return TRUE;
    }
    i = work->count - 1;
    dist = func_800B1830_B2430(work->spine[i].x * work->spine[i].x + work->spine[i].z * work->spine[i].z);
    if (work->length <= dist) {
        return TRUE;
    }
    width = work->width;
    for (j = 0; j < 2; j++) {
        work->edge[j][i + 1] = work->edge[j][i];
        work->edge2[j][i + 1] = work->edge2[j][i];
    }
    work->count++;
    i = work->count - 1;
    for (j = 0; j < 4; j++) {
        work->col[i][j] = work->col0[j];
    }
    for (j = 0; j < i; j++) {
        for (k = 0; k < 4; k++) {
            work->col[j][k] += work->colVel[k];
            if (work->col[j][k] < 0.0f) {
                work->col[j][k] = 0.0f;
            }
        }
    }
    work->seg[i] = (u8)(rand8() % 20) + 20;
    if ((u8)(rand8() % 10) < 4 && work->count >= 5) {
        work->seg[i] += 50.0f;
    }
    if (work->length <= dist + work->seg[i]) {
        work->seg[i] = dist + work->seg[i] - work->length;
    }
    n = ((u8)(rand8() % 20) + 5) * work->sign;
    work->fwd = work->dir;
    work->fwd.y += HuMathSin(n) * 3.0f;
    MBVecNormalize(&work->fwd);
    if (work->sign > 0) {
        work->sign = -1;
    } else {
        work->sign = 1;
    }
    work->dirA[0].x = work->fwd.y * work->side.z - work->fwd.z * work->side.y;
    work->dirA[0].y = work->fwd.z * work->side.x - work->fwd.x * work->side.z;
    work->dirA[0].z = work->fwd.x * work->side.y - work->fwd.y * work->side.x;
    MBVecNormalize(&work->dirA[0]);
    work->dirA[1].x = -work->dirA[0].x;
    work->dirA[1].y = -work->dirA[0].y;
    work->dirA[1].z = -work->dirA[0].z;
    work->spine[i].x = work->fwd.x * work->seg[i] + work->spine[i - 1].x;
    work->spine[i].y = work->fwd.y * work->seg[i] + work->spine[i - 1].y;
    work->spine[i].z = work->fwd.z * work->seg[i] + work->spine[i - 1].z;
    for (j = 0; j < 2; j++) {
        work->targetB[j].x = (width + 5.0f) * work->dirA[j].x + work->spine[i].x;
        work->targetB[j].y = (width + 5.0f) * work->dirA[j].y + work->spine[i].y;
        work->targetB[j].z = (width + 5.0f) * work->dirA[j].z + work->spine[i].z;
        work->dirB[j].x = work->targetB[j].x - work->edge2[j][i].x;
        work->dirB[j].y = work->targetB[j].y - work->edge2[j][i].y;
        work->dirB[j].z = work->targetB[j].z - work->edge2[j][i].z;
        MBVecNormalize(&work->dirB[j]);
        work->targetA[j].x = width * work->dirA[j].x + work->spine[i].x;
        work->targetA[j].y = width * work->dirA[j].y + work->spine[i].y;
        work->targetA[j].z = width * work->dirA[j].z + work->spine[i].z;
        work->dirA[j].x = work->targetA[j].x - work->edge[j][i].x;
        work->dirA[j].y = work->targetA[j].y - work->edge[j][i].y;
        work->dirA[j].z = work->targetA[j].z - work->edge[j][i].z;
        MBVecNormalize(&work->dirA[j]);
    }
    return FALSE;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4F_name/33FE50", func_8010F188_341DC8_name_4F);
#endif
