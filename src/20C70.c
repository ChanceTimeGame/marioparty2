#include "common.h"
#include "game/camera.h"

/* Cameras: MP1 src/1DE40.c / MP3 src/camera.c, with MP2's HuCamera layout (game/camera.h). */

typedef f32 HuMtx4F[4][4];

f32 HuMathSin(f32);
f32 func_800B7890_B8490(f32); /* HuMathCos */
void func_800B1960_B2560(HuMtx4F, f32, f32, f32, f32, f32, f32, f32, f32, f32); /* guLookAtF */
void func_800B3820_B4420(Mtx*); /* guMtxIdent */
void* HuMemAlloc(s32 size);
void HuMemFree(void* ptr);

void CameraScissorSet(s16 camIndex, RectF* arg1);
void CameraViewportSet(s16 camIndex, Vec* arg1, Vec* arg2);

extern Vec D_800C9B84_CA784[];
extern Vec D_800C9BC0_CA7C0[];
extern RectF D_800C9BFC_CA7FC[];
extern s16 D_800F64B2_F70B2;
extern s16 D_800FFFD6_100BD6;
extern u8 D_800FDBCA_FE7CA;
extern u8 D_800FDBE0_FE7E0;
extern void* D_800FD2A8_FDEA8;
extern HuCamMtxs* D_800FC88C_FD48C;

void func_80020070_20C70(s16 count) {
    s16 i;
    s16 j;

    D_800F64B2_F70B2 = count;
    D_800FFFD6_100BD6 = 0;
    if (D_800C9B80_CA780 != NULL) {
        HuMemFree(D_800C9B80_CA780);
    }
    D_800C9B80_CA780 = HuMemAlloc(6 * sizeof(HuCamera));
    for (i = 0; i < 6; i++) {
        D_800C9B80_CA780[i].fov[0] = 45.0f;
        D_800C9B80_CA780[i].fov[1] = 80.0f;
        D_800C9B80_CA780[i].fov[2] = 8000.0f;
        D_800C9B80_CA780[i].unk2 = 0;
        CameraViewportSet(i, &D_800C9B84_CA784[0], &D_800C9BC0_CA7C0[0]);
        CameraScissorSet(i, &D_800C9BFC_CA7FC[0]);
        D_800C9B80_CA780[i].unkA8 = NULL;
        D_800C9B80_CA780[i].unkB0 = NULL;
        D_800C9B80_CA780[i].unkB4 = NULL;
        for (j = 0; j < D_800FDBCA_FE7CA; j++) {
            func_800B3820_B4420(&D_800C9B80_CA780[i].mtxs[j].perspMtx);
            func_800B3820_B4420(&D_800C9B80_CA780[i].mtxs[j].lookAtMtx);
        }
    }
    D_800FD2A8_FDEA8 = D_800C9B80_CA780;
    D_800FC88C_FD48C = D_800C9B80_CA780->mtxs;
}

INCLUDE_ASM("asm/nonmatchings/20C70", func_8002024C_20E4C);

void Hu3DCamSetPositionOrientation(s16 camIndex, Vec* pos, Vec* at, Vec* up) {
    HuCamera* camera = &D_800C9B80_CA780[camIndex];

    camera->pos = *pos;
    camera->at = *at;
    camera->up = *up;
}

void Hu3DCamSetPerspective(s16 camIndex, f32 fov, f32 near, f32 far) {
    HuCamera* camera = &D_800C9B80_CA780[camIndex];

    camera->fov[0] = fov;
    camera->fov[1] = near;
    camera->fov[2] = far;
    camera->perspNorm = 1;
}

void CameraScissorSet(s16 camIndex, RectF* arg1) {
    HuCamera* camera = &D_800C9B80_CA780[camIndex];

    camera->screenLeft = arg1->x1;
    camera->screenTop = arg1->y1;
    camera->screenRight = arg1->x2;
    camera->screenBottom = arg1->y2;
}

void CameraViewportSet(s16 camIndex, Vec* arg1, Vec* arg2) {
    HuCamera* camera = &D_800C9B80_CA780[camIndex];

    camera->screenScale = *arg1;
    camera->screenPos = *arg2;
}

void Hu3DCamUpdateMtx(s16 camIndex) {
    HuCamera* camera;
    HuCamMtxs* mtxs;

    camera = &D_800C9B80_CA780[camIndex];
    mtxs = &camera->mtxs[D_800FFFD6_100BD6];
    guPerspective(&mtxs->perspMtx, &camera->perspNorm, camera->fov[0], 4.0f / 3.0f, camera->fov[1],
                  camera->fov[2], 1.0f);
    guLookAt(&mtxs->lookAtMtx, camera->pos.x, camera->pos.y, camera->pos.z, camera->at.x, camera->at.y,
             camera->at.z, camera->up.x, camera->up.y, camera->up.z);
}

void func_800204C0_210C0(s16 camIndex, Gfx** dispList) {
    HuCamMtxs* camMtx;
    HuCamera* camera;

    camera = &D_800C9B80_CA780[camIndex];
    camMtx = &camera->mtxs[D_800FFFD6_100BD6];
    camera->viewports[D_800FFFD6_100BD6].vp.vscale[0] = camera->screenScale.x;
    camera->viewports[D_800FFFD6_100BD6].vp.vscale[1] = camera->screenScale.y;
    camera->viewports[D_800FFFD6_100BD6].vp.vscale[2] = camera->screenScale.z;
    camera->viewports[D_800FFFD6_100BD6].vp.vtrans[0] = camera->screenPos.x;
    camera->viewports[D_800FFFD6_100BD6].vp.vtrans[1] = camera->screenPos.y;
    camera->viewports[D_800FFFD6_100BD6].vp.vtrans[2] = camera->screenPos.z;

    gSPViewport((*dispList)++, &camera->viewports[D_800FFFD6_100BD6]);
    gSPPerspNormalize((*dispList)++, camera->perspNorm);
    gSPMatrix((*dispList)++, osVirtualToPhysical(&camMtx->perspMtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix((*dispList)++, (u8*) camMtx + 0x80000040, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
}

void func_8002064C_2124C(s16 camIndex, Gfx** dispList) {
    HuCamera* camera = &D_800C9B80_CA780[camIndex];

    gDPSetScissor((*dispList)++, G_SC_NON_INTERLACE, camera->screenLeft, camera->screenTop, camera->screenRight,
                  camera->screenBottom);
}

INCLUDE_ASM("asm/nonmatchings/20C70", func_80020718_21318);

INCLUDE_ASM("asm/nonmatchings/20C70", func_80020754_21354);

INCLUDE_ASM("asm/nonmatchings/20C70", func_8002078C_2138C);

void Hu3DCam3DToScreen(s16 camIndex, Vec* worldPos, Vec2f* outPos) {
    HuMtx4F viewMtx;
    f32 projectedZ;
    f32 projectedY;
    f32 projectedX;
    f32 y;
    f32 z;
    f32 x;
    HuCamera* camera;

    camera = &D_800C9B80_CA780[camIndex];
    func_800B1960_B2560(viewMtx, camera->pos.x, camera->pos.y, camera->pos.z, camera->at.x, camera->at.y,
                        camera->at.z, camera->up.x, camera->up.y, camera->up.z);
    x = worldPos->x;
    y = worldPos->y;
    z = worldPos->z;
    x -= camera->pos.x;
    y -= camera->pos.y;
    z -= camera->pos.z;
    projectedX = ((x * viewMtx[0][0]) + (y * viewMtx[1][0])) + (z * viewMtx[2][0]);
    projectedY = ((x * viewMtx[0][1]) + (y * viewMtx[1][1])) + (z * viewMtx[2][1]);
    projectedZ = ((x * viewMtx[0][2]) + (y * viewMtx[1][2])) + (z * viewMtx[2][2]);
    x = HuMathSin(camera->fov[0] / 2.0f) / func_800B7890_B8490(camera->fov[0] / 2.0f) * projectedZ * (4.0f / 3.0f);
    y = (HuMathSin(camera->fov[0] / 2.0f) / func_800B7890_B8490(camera->fov[0] / 2.0f)) * projectedZ;
    outPos->unk_00 = (projectedX * (160.0f / (-x))) + 160.0f;
    outPos->unk_04 = ((projectedY * (120.0f / y)) + 120.0f);
}

void func_800209C4_215C4(s16 camIndex, Vec* worldPos, Vec2f* outPos) {
    HuMtx4F viewMtx;
    f32 f0;
    f32 projectedZ;
    f32 projectedY;
    f32 projectedX;
    f32 y;
    f32 x;
    f32 z;
    f32 f2;
    HuCamera* camera;

    camera = &D_800C9B80_CA780[camIndex];
    func_800B1960_B2560(viewMtx, camera->pos.x, camera->pos.y, camera->pos.z, camera->at.x, camera->at.y,
                        camera->at.z, camera->up.x, camera->up.y, camera->up.z);
    x = worldPos->x;
    y = worldPos->y;
    z = worldPos->z;
    x -= camera->pos.x;
    y -= camera->pos.y;
    z -= camera->pos.z;
    projectedX = (x * viewMtx[0][0]) + (y * viewMtx[1][0]) + (z * viewMtx[2][0]);
    projectedY = (x * viewMtx[0][1]) + (y * viewMtx[1][1]) + (z * viewMtx[2][1]);
    projectedZ = (x * viewMtx[0][2]) + (y * viewMtx[1][2]) + (z * viewMtx[2][2]);
    x = HuMathSin(camera->fov[0] / 2.0f) / func_800B7890_B8490(camera->fov[0] / 2.0f) * projectedZ *
        (camera->screenScale.x / camera->screenScale.y);
    y = HuMathSin(camera->fov[0] / 2.0f) / func_800B7890_B8490(camera->fov[0] / 2.0f) * projectedZ;
    f2 = camera->screenPos.x / 4.0f;
    outPos->unk_00 = projectedX * (f2 / -x) + f2;
    f0 = camera->screenPos.y / 4.0f;
    outPos->unk_04 = projectedY * (f0 / y) + f0;
}

void func_80020BC4_217C4(s16 camIndex, f32 arg1, Vec2f* arg2, Vec2f* arg3) {
    HuMtx4F viewMtx;
    f32 temp_f20;
    f32 temp_f4;
    f32 unk_var1;
    f32 unk_var2;
    HuCamera* camera;

    camera = &D_800C9B80_CA780[camIndex];
    func_800B1960_B2560(viewMtx, camera->pos.x, camera->pos.y, camera->pos.z, camera->at.x, camera->at.y,
                        camera->at.z, camera->up.x, camera->up.y, camera->up.z);
    temp_f20 = HuMathSin(camera->fov[0] / 2.0f) / func_800B7890_B8490(camera->fov[0] / 2.0f) * arg1;
    temp_f4 = temp_f20 * (4.0f / 3.0f);
    unk_var1 = arg2->unk_00 / 320.0f;
    unk_var2 = (240.0f - arg2->unk_04) / 240.0f;
    arg3->unk_00 = 2.0f * temp_f4 * unk_var1 - temp_f4;
    arg3->unk_04 = 2.0f * temp_f20 * unk_var2 - temp_f20;
}
