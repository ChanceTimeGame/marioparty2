#include "common.h"
#include "game/camera.h"

/* One camera-anchored 2D object on camera 0, its plane the floor (normal +y). */

/* Object-manager camera view and a frame timer object (MP3 src/4BF40.c omOutView, MP1
   src/objmain.c). MP2's names are kept. */

extern f32 D_800FA5BC_FB1BC[];
extern f32 D_80101078_101C78;
extern f32 D_800F8410_F9010;
extern omObjData* D_800FA5D4_FB1D4;
extern s32 D_80102748_103348;
extern u16 D_801011FC_101DFC;

f32 HuMathSin(f32); /* HuMathSin */
f32 func_800B7890_B8490(f32); /* HuMathCos */
void Hu3DCamSetPositionOrientation(s16 camIndex, Vec* pos, Vec* at, Vec* up);
void Hu3DCamUpdateMtx(s16 camIndex);
void func_8007BA14_7C614(omObjData* obj);

/* The work block of a camera-anchored 2D object (func_8007A2CC_7AECC: one camera,
   func_8007A4A0_7B0A0: one per camera): a sprite drawn by `draw` at the screen position of a
   point on a plane, scaled with the camera distance. */
typedef struct CamSprWork {
    /* 0x00 */ s16 sprId;
    /* 0x04 */ f32 scaleX;     // baseScaleX * baseZoom / current distance
    /* 0x08 */ f32 scaleY;
    /* 0x0C */ f32 baseScaleX; // screenScale.x / 640
    /* 0x10 */ f32 baseScaleY; // screenScale.y / 480
    /* 0x14 */ f32 baseZoom;   // camera distance at creation
    /* 0x18 */ f32 offsetX;    // screen offset of the plane point since creation
    /* 0x1C */ f32 offsetY;
    /* 0x20 */ Vec planePos;   // where the view ray met the plane at creation
    /* 0x2C */ void (*draw)(struct CamSprWork*);
    /* 0x30 */ HuCamera* cam;
} CamSprWork; /* size 0x34 */

/* Per-slot sound fades (func_8007BA44_7C644 / func_8007BB74_7C774), one entry per sound slot. */
typedef struct SndFadeWork {
    /* 0x00 */ f32* vol;      // flag 1: fade out, then stop the slot
    /* 0x04 */ f32* volStep;
    /* 0x08 */ f32* vol2;     // flag 4 (with flag 2): fade to silence, keep playing
    /* 0x0C */ f32* vol2Step;
    /* 0x10 */ u8* flags;
} SndFadeWork; /* size 0x14 */

/* The sound configuration func_8000E9E8_F5E8 copies out (ECE0.c SndConfig); only the slot count
   is read here. */
typedef struct SndConfigView {
    /* 0x00 */ char unk00[0x54];
    /* 0x54 */ s32 sndMaxVoices;
    /* 0x58 */ char unk58[0x14];
} SndConfigView; /* size 0x6C */

extern Gfx* D_800FDBCC_FE7CC; /* gMainGfxPos */
extern Vec D_8010270C_10330C;     /* plane normal for the one-camera object */
extern Vec D_800F9518_FA118[4];   /* plane normals, one per camera */
extern omObjData* D_801026F0_1032F0;
extern SndConfigView D_800FD480_FE080;
extern s16 D_800CD530_CE130; /* sound slot count */

void* func_80027154_27D54(s32 size, s16 tag); /* HuMemAlloc-like */
f32 func_800B1830_B2430(f32);               /* sqrtf */
f32 func_800B75A8_B81A8(f32, f32);          /* atan2 (degrees) */
void func_800209C4_215C4(s16 camIndex, Vec* worldPos, Vec2f* outPos);
void func_8000E9E8_F5E8(SndConfigView* out);
s32 func_80015388_15F88(s32 slot);
void func_800155B8_161B8(s16 slot, s16 vol);
void func_80015868_16468(s16 slot);

void func_8007A2CC_7AECC(s32 prio, s16 sprId, void (*draw)(CamSprWork*), f32 fov, Vec* eye, Vec* at);
void func_8007A4A0_7B0A0(u8 count, s32 prio, u16* sprIds, void (*draw)(CamSprWork*), f32 fov, Vec* eye, Vec* at);
void func_8007A718_7B318(void);
void func_8007A7FC_7B3FC(CamSprWork* work);
void func_8007AFDC_7BBDC(omObjData* obj);
void func_8007B284_7BE84(omObjData* obj);
void func_8007B658_7C258(Vec* out, Vec* normal);
void func_8007B818_7C418(Vec* eye, Vec* at, f32* zoom, Vec* rot, Vec* center);
void func_8007BB74_7C774(void);

extern Vec D_80102770_103370[]; /* CRotM */
extern Vec D_801013B0_101FB0[]; /* CenterM */
extern f32 D_800F94A8_FA0A8[];  /* CZoomM */
extern f32 D_800FC8F8_FD4F8[][6];
extern f32 D_800F92E8_F9EE8[];
extern f32 D_80100018_100C18[];

/* func_80079E60_7AA60 is MP3 omOutView, whose omObjData argument is unused; functions.h declares it
   void, so it is kept that way here. */

void func_80079E60_7AA60(void) {
    Vec pos, at, up;
    f32 rot_x = D_800FD474_FE074.x;
    f32 rot_y = D_800FD474_FE074.y;

    pos.x = D_8010274C_10334C.x + HuMathSin(rot_y) * func_800B7890_B8490(rot_x) * D_800FA610_FB210;
    pos.y = D_8010274C_10334C.y + -HuMathSin(rot_x) * D_800FA610_FB210;
    pos.z = D_8010274C_10334C.z + func_800B7890_B8490(rot_y) * func_800B7890_B8490(rot_x) * D_800FA610_FB210;
    at.x = D_8010274C_10334C.x;
    at.y = D_8010274C_10334C.y;
    at.z = D_8010274C_10334C.z;
    up.x = HuMathSin(rot_y) * HuMathSin(rot_x);
    up.y = func_800B7890_B8490(rot_x);
    up.z = func_800B7890_B8490(rot_y) * HuMathSin(rot_x);
    D_800FA5BC_FB1BC[0] = pos.x;
    D_800FA5BC_FB1BC[1] = pos.z;
    D_800FA5BC_FB1BC[-1] = D_800FD474_FE074.y;
    D_800FA5BC_FB1BC[2] = D_800C9B80_CA780->fov[0];
    D_800FA5BC_FB1BC[3] = D_80101078_101C78;
    D_800FA5BC_FB1BC[4] = D_800F8410_F9010;
    Hu3DCamSetPositionOrientation(0, &pos, &at, &up);
    Hu3DCamUpdateMtx(0);
}

/* MP3 omOutViewMulti */
void func_80079FF4_7ABF4(omObjData* object) {
    u8 i;

    for (i = 0; i < object->work[0]; i++) {
        Vec pos, at, up;
        f32 rot_x = D_80102770_103370[i].x;
        f32 rot_y = D_80102770_103370[i].y;

        pos.x = D_801013B0_101FB0[i].x + HuMathSin(rot_y) * func_800B7890_B8490(rot_x) * D_800F94A8_FA0A8[i];
        pos.y = D_801013B0_101FB0[i].y + -HuMathSin(rot_x) * D_800F94A8_FA0A8[i];
        pos.z = D_801013B0_101FB0[i].z + func_800B7890_B8490(rot_y) * func_800B7890_B8490(rot_x) * D_800F94A8_FA0A8[i];
        at.x = D_801013B0_101FB0[i].x;
        at.y = D_801013B0_101FB0[i].y;
        at.z = D_801013B0_101FB0[i].z;
        up.x = HuMathSin(rot_y) * HuMathSin(rot_x);
        up.y = func_800B7890_B8490(rot_x);
        up.z = func_800B7890_B8490(rot_y) * HuMathSin(rot_x);
        D_800FC8F8_FD4F8[i][1] = pos.x;
        D_800FC8F8_FD4F8[i][2] = pos.z;
        D_800FC8F8_FD4F8[i][0] = D_80102770_103370[i].y;
        D_800FC8F8_FD4F8[i][3] = D_800C9B80_CA780[i].fov[0];
        D_800FC8F8_FD4F8[i][4] = D_800F92E8_F9EE8[i];
        D_800FC8F8_FD4F8[i][5] = D_80100018_100C18[i];
        Hu3DCamSetPositionOrientation(i, &pos, &at, &up);
        Hu3DCamUpdateMtx(i);
    }
}

/* One camera-anchored 2D object on camera 0, its plane the floor (normal +y). */
void func_8007A27C_7AE7C(s32 prio, s32 sprId, void (*draw)(CamSprWork*), f32 fov, Vec* eye, Vec* at) {
    D_8010270C_10330C.x = 0.0f;
    D_8010270C_10330C.y = 1.0f;
    D_8010270C_10330C.z = 0.0f;
    func_8007A2CC_7AECC(prio, sprId, draw, fov, eye, at);
}

void func_8007A2CC_7AECC(s32 prio, s16 sprId, void (*draw)(CamSprWork*), f32 fov, Vec* eye, Vec* at) {
    Mtx unused; /* retail's frame has 0x40 bytes of unused locals */
    omObjData* obj;
    CamSprWork* work;
    HuCamera* cam;

    obj = omAddObj(prio, 0, 0, -1, func_8007AFDC_7BBDC);
    omSetStatBit(obj, 0xA0);
    work = func_80027154_27D54(sizeof(CamSprWork), 0x7918);
    obj->unk_50 = work;
    work->draw = draw;
    work->sprId = sprId;
    func_8007B818_7C418(eye, at, &D_800FA610_FB210, &D_800FD474_FE074, &D_8010274C_10334C);
    Hu3DCamSetPerspective(0, fov, 80.0f, 8000.0f);
    cam = D_800C9B80_CA780;
    func_8007B658_7C258(&work->planePos, &D_8010270C_10330C);
    work->baseZoom = D_800FA610_FB210;
    work->baseScaleX = cam->screenScale.x / 640.0f;
    work->baseScaleY = cam->screenScale.y / 480.0f;
    work->scaleX = work->baseScaleX;
    work->scaleY = work->baseScaleY;
    work->cam = cam;
}

/* One camera-anchored 2D object per camera (count cameras), each plane the floor. */
void func_8007A420_7B020(s32 count, s32 prio, u16* sprIds, void (*draw)(CamSprWork*), f32 fov, Vec* eye, Vec* at) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_800F9518_FA118[i].x = 0.0f;
        D_800F9518_FA118[i].y = 1.0f;
        D_800F9518_FA118[i].z = 0.0f;
    }
    func_8007A4A0_7B0A0(count, prio, sprIds, draw, fov, eye, at);
}

void func_8007A4A0_7B0A0(u8 count, s32 prio, u16* sprIds, void (*draw)(CamSprWork*), f32 fov, Vec* eye, Vec* at) {
    Mtx unused; /* retail's frame has 0x40 bytes of unused locals */
    omObjData* obj;
    CamSprWork* work;
    HuCamera* cam;
    s32 i;
    f32 near, far;

    obj = omAddObj(prio, 0, 0, -1, func_8007B284_7BE84);
    omSetStatBit(obj, 0xA0);
    obj->unk_50 = func_80027154_27D54(count * sizeof(CamSprWork), 0x7918);
    work = obj->unk_50;
    func_8007B818_7C418(eye, at, &D_800FA610_FB210, &D_800FD474_FE074, &D_8010274C_10334C);
    near = 80.0f;
    far = 8000.0f;
    obj->work[0] = count;
    for (i = 0; i < count; i++, work++) {
        Hu3DCamSetPerspective(i, fov, near, far);
        work->draw = draw;
        work->sprId = sprIds[i];
        D_800F94A8_FA0A8[i] = D_800FA610_FB210;
        D_80102770_103370[i] = D_800FD474_FE074;
        D_801013B0_101FB0[i] = D_8010274C_10334C;
        cam = &D_800C9B80_CA780[i];
        func_8007B658_7C258(&work->planePos, &D_800F9518_FA118[i]);
        work->baseZoom = D_800FA610_FB210;
        work->baseScaleX = cam->screenScale.x / 640.0f;
        work->baseScaleY = cam->screenScale.y / 480.0f;
        work->scaleX = work->baseScaleX;
        work->scaleY = work->baseScaleY;
        work->cam = cam;
    }
}

/* Render state for the objects' sprites. */
void func_8007A718_7B318(void) {
    gDPPipeSync(D_800FDBCC_FE7CC++);
    gDPSetCycleType(D_800FDBCC_FE7CC++, G_CYC_1CYCLE);
    gDPSetCombineLERP(D_800FDBCC_FE7CC++, TEXEL0, 0, TEXEL0_ALPHA, 0, TEXEL0, 0, PRIM_LOD_FRAC, 0, TEXEL0, 0,
                      TEXEL0_ALPHA, 0, TEXEL0, 0, PRIM_LOD_FRAC, 0);
    gDPSetRenderMode(D_800FDBCC_FE7CC++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);
    gDPSetAlphaCompare(D_800FDBCC_FE7CC++, G_AC_THRESHOLD);
    gDPSetTextureFilter(D_800FDBCC_FE7CC++, G_TF_BILERP);
    gDPSetTexturePersp(D_800FDBCC_FE7CC++, G_TP_NONE);
}

INCLUDE_ASM("asm/nonmatchings/7AA60", func_8007A7FC_7B3FC);

/* Object function of func_8007A2CC_7AECC: camera 0 from CRot/CZoom/Center (as omOutView), then
   the sprite's scale and screen offset, and its draw callback. */
void func_8007AFDC_7BBDC(omObjData* obj) {
    Vec pos, at, up;
    Vec planePos;
    Vec2f scr0, scr1;
    CamSprWork* work = obj->unk_50;
    f32 rot_x = D_800FD474_FE074.x;
    f32 rot_y = D_800FD474_FE074.y;
    f32 dist;

    pos.x = D_8010274C_10334C.x + HuMathSin(rot_y) * func_800B7890_B8490(rot_x) * D_800FA610_FB210;
    pos.y = D_8010274C_10334C.y + -HuMathSin(rot_x) * D_800FA610_FB210;
    pos.z = D_8010274C_10334C.z + func_800B7890_B8490(rot_y) * func_800B7890_B8490(rot_x) * D_800FA610_FB210;
    at.x = D_8010274C_10334C.x;
    at.y = D_8010274C_10334C.y;
    at.z = D_8010274C_10334C.z;
    up.x = HuMathSin(rot_y) * HuMathSin(rot_x);
    up.y = func_800B7890_B8490(rot_x);
    up.z = func_800B7890_B8490(rot_y) * HuMathSin(rot_x);
    D_800FA5BC_FB1BC[0] = pos.x;
    D_800FA5BC_FB1BC[1] = pos.z;
    D_800FA5BC_FB1BC[-1] = D_800FD474_FE074.y;
    D_800FA5BC_FB1BC[2] = D_800C9B80_CA780->fov[0];
    D_800FA5BC_FB1BC[3] = D_80101078_101C78;
    D_800FA5BC_FB1BC[4] = D_800F8410_F9010;
    Hu3DCamSetPositionOrientation(0, &pos, &at, &up);
    Hu3DCamUpdateMtx(0);
    dist = func_800B1830_B2430((D_8010274C_10334C.x - pos.x) * (D_8010274C_10334C.x - pos.x) +
                               (D_8010274C_10334C.y - pos.y) * (D_8010274C_10334C.y - pos.y) +
                               (D_8010274C_10334C.z - pos.z) * (D_8010274C_10334C.z - pos.z));
    work->scaleX = (work->baseZoom / dist) * work->baseScaleX;
    work->scaleY = (work->baseZoom / dist) * work->baseScaleY;
    func_8007B658_7C258(&planePos, &D_8010270C_10330C);
    func_800209C4_215C4(0, &planePos, &scr0);
    func_800209C4_215C4(0, &work->planePos, &scr1);
    work->offsetX = (scr0.unk_00 - scr1.unk_00) * work->baseScaleX;
    work->offsetY = (scr0.unk_04 - scr1.unk_04) * work->baseScaleY;
    if (work->draw != NULL) {
        func_8007A718_7B318();
        work->draw(work);
        gSPEndDisplayList(D_800FDBCC_FE7CC++);
    }
}

/* Object function of func_8007A4A0_7B0A0: the same for each of its cameras (omOutViewMulti).
   Retail projects every camera's plane point through camera 0 (func_800209C4_215C4's first
   argument). */
void func_8007B284_7BE84(omObjData* obj) {
    Vec pos, at, up;
    Vec planePos;
    Vec2f scr0, scr1;
    CamSprWork* work = obj->unk_50;
    s32 i;
    f32 rot_x, rot_y;
    f32 dist;

    func_8007A718_7B318();
    for (i = 0; i < obj->work[0]; i++, work++) {
        rot_x = D_80102770_103370[i].x;
        rot_y = D_80102770_103370[i].y;
        pos.x = D_801013B0_101FB0[i].x + HuMathSin(rot_y) * func_800B7890_B8490(rot_x) * D_800F94A8_FA0A8[i];
        pos.y = D_801013B0_101FB0[i].y + -HuMathSin(rot_x) * D_800F94A8_FA0A8[i];
        pos.z = D_801013B0_101FB0[i].z + func_800B7890_B8490(rot_y) * func_800B7890_B8490(rot_x) * D_800F94A8_FA0A8[i];
        at.x = D_801013B0_101FB0[i].x;
        at.y = D_801013B0_101FB0[i].y;
        at.z = D_801013B0_101FB0[i].z;
        up.x = HuMathSin(rot_y) * HuMathSin(rot_x);
        up.y = func_800B7890_B8490(rot_x);
        up.z = func_800B7890_B8490(rot_y) * HuMathSin(rot_x);
        D_800FC8F8_FD4F8[i][1] = pos.x;
        D_800FC8F8_FD4F8[i][2] = pos.z;
        D_800FC8F8_FD4F8[i][0] = D_80102770_103370[i].y;
        D_800FC8F8_FD4F8[i][3] = D_800C9B80_CA780[i].fov[0];
        D_800FC8F8_FD4F8[i][4] = D_800F92E8_F9EE8[i];
        D_800FC8F8_FD4F8[i][5] = D_80100018_100C18[i];
        Hu3DCamSetPositionOrientation(i, &pos, &at, &up);
        Hu3DCamUpdateMtx(i);
        dist = func_800B1830_B2430((D_801013B0_101FB0[i].x - pos.x) * (D_801013B0_101FB0[i].x - pos.x) +
                                   (D_801013B0_101FB0[i].y - pos.y) * (D_801013B0_101FB0[i].y - pos.y) +
                                   (D_801013B0_101FB0[i].z - pos.z) * (D_801013B0_101FB0[i].z - pos.z));
        work->scaleX = (work->baseZoom / dist) * work->baseScaleX;
        work->scaleY = (work->baseZoom / dist) * work->baseScaleY;
        func_8007B658_7C258(&planePos, &D_800F9518_FA118[i]);
        func_800209C4_215C4(0, &planePos, &scr0);
        func_800209C4_215C4(0, &work->planePos, &scr1);
        work->offsetX = (scr0.unk_00 - scr1.unk_00) * work->baseScaleX;
        work->offsetY = (scr0.unk_04 - scr1.unk_04) * work->baseScaleY;
        if (work->draw != NULL) {
            work->draw(work);
            if (i != obj->work[0] - 1) {
                gDPPipeSync(D_800FDBCC_FE7CC++);
            }
        }
    }
    gSPEndDisplayList(D_800FDBCC_FE7CC++);
}

/* Where the camera's view ray (from the eye through Center) meets the plane through the origin
   with the given normal. */
void func_8007B658_7C258(Vec* out, Vec* normal) {
    Vec pos;
    f32 rot_x = D_800FD474_FE074.x;
    f32 rot_y = D_800FD474_FE074.y;
    f32 dist, dx, dy, dz, t;

    pos.x = D_8010274C_10334C.x + HuMathSin(rot_y) * func_800B7890_B8490(rot_x) * D_800FA610_FB210;
    pos.y = D_8010274C_10334C.y + -HuMathSin(rot_x) * D_800FA610_FB210;
    pos.z = D_8010274C_10334C.z + func_800B7890_B8490(rot_y) * func_800B7890_B8490(rot_x) * D_800FA610_FB210;
    dist = func_800B1830_B2430((D_8010274C_10334C.x - pos.x) * (D_8010274C_10334C.x - pos.x) +
                               (D_8010274C_10334C.y - pos.y) * (D_8010274C_10334C.y - pos.y) +
                               (D_8010274C_10334C.z - pos.z) * (D_8010274C_10334C.z - pos.z));
    dx = (pos.x - D_8010274C_10334C.x) / dist;
    dy = (pos.y - D_8010274C_10334C.y) / dist;
    dz = (pos.z - D_8010274C_10334C.z) / dist;
    dist = dx * normal->x + dy * normal->y + dz * normal->z;
    t = (-pos.x * normal->x + -pos.y * normal->y + -pos.z * normal->z) / dist;
    out->x = dx * t + pos.x;
    out->y = dy * t + pos.y;
    out->z = dz * t + pos.z;
}

/* CZoom, CRot and Center for a camera at `eye` looking at `at`. */
void func_8007B818_7C418(Vec* eye, Vec* at, f32* zoom, Vec* rot, Vec* center) {
    f32 mtx[4][4];
    f32 dx, dy, dz, ang, x, y;

    dx = eye->x - at->x;
    dy = eye->y - at->y;
    dz = eye->z - at->z;
    *zoom = func_800B1830_B2430(dx * dx + dy * dy + dz * dz);
    ang = func_800B75A8_B81A8(dz, dx);
    rot->y = -(ang - 90.0f);
    ang = -ang;
    mtx[0][0] = mtx[2][2] = func_800B7890_B8490(ang);
    mtx[2][0] = -HuMathSin(ang);
    mtx[0][2] = HuMathSin(ang);
    mtx[1][1] = mtx[3][3] = 1.0f;
    mtx[1][0] = mtx[3][0] = mtx[0][1] = mtx[2][1] = mtx[3][1] = mtx[1][2] = mtx[3][2] = mtx[0][3] = mtx[1][3] =
        mtx[2][3] = 0.0f;
    x = dx * mtx[0][0] + dy * mtx[1][0] + dz * mtx[2][0];
    y = dx * mtx[0][1] + dy * mtx[1][1] + dz * mtx[2][1];
    rot->x = -func_800B75A8_B81A8(y, x);
    rot->z = 0.0f;
    center->x = at->x;
    center->y = at->y;
    center->z = at->z;
}
void func_8007B9B8_7C5B8(void) {
    D_800FA5D4_FB1D4 = omAddObj(0x7FD8, 0, 0, -1, func_8007BA14_7C614);
    omSetStatBit(D_800FA5D4_FB1D4, 0xA0);
    *(s32*)D_800FA5D4_FB1D4->work = D_80102748_103348;
}

void func_8007BA14_7C614(omObjData* obj) {
    s32* timer = (s32*)obj->work;

    if (*timer == 0) {
        D_801011FC_101DFC = 1;
    } else {
        (*timer)--;
    }
}

/* Creates the sound-fade object: per-slot fade arrays sized by the configured sound slots. */
void func_8007BA44_7C644(void) {
    SndFadeWork* work;
    s32 i;

    D_801026F0_1032F0 = omAddObj(0x7FD8, 0, 0, -1, func_8007BB74_7C774);
    D_801026F0_1032F0->unk_50 = func_80027154_27D54(sizeof(SndFadeWork), 0x7918);
    work = D_801026F0_1032F0->unk_50;
    func_8000E9E8_F5E8(&D_800FD480_FE080);
    D_800CD530_CE130 = D_800FD480_FE080.sndMaxVoices;
    work->vol = func_80027154_27D54(D_800CD530_CE130 * sizeof(f32), 0x7918);
    work->volStep = func_80027154_27D54(D_800CD530_CE130 * sizeof(f32), 0x7918);
    work->vol2 = func_80027154_27D54(D_800CD530_CE130 * sizeof(f32), 0x7918);
    work->vol2Step = func_80027154_27D54(D_800CD530_CE130 * sizeof(f32), 0x7918);
    work->flags = func_80027154_27D54(D_800CD530_CE130, 0x7918);
    omSetStatBit(D_801026F0_1032F0, 0xA0);
    for (i = 0; i < D_800CD530_CE130; i++) {
        work->flags[i] = 0;
    }
}

/* Steps every slot's fade; a slot that stopped playing drops its fade. */
void func_8007BB74_7C774(void) {
    SndFadeWork* work = D_801026F0_1032F0->unk_50;
    s16 i;
    u8 flags;
    s32 playing;

    for (i = 0; i < D_800CD530_CE130; i++) {
        flags = work->flags[i];
        playing = func_80015388_15F88(i);
        if (flags & 2) {
            if (playing == 0) {
                work->flags[i] &= ~1;
                work->flags[i] &= ~4;
            } else if (flags & 4) {
                work->vol2[i] -= work->vol2Step[i];
                if (work->vol2[i] <= 0.0f) {
                    work->vol2[i] = 0.0f;
                    func_800155B8_161B8(i, 0);
                    work->flags[i] &= ~4;
                } else {
                    func_800155B8_161B8(i, work->vol2[i]);
                }
            }
        } else if (work->flags[i] & 1) {
            if (playing == 0) {
                work->flags[i] &= ~1;
            } else {
                work->vol[i] -= work->volStep[i];
                if (work->vol[i] <= 0.0f) {
                    work->vol[i] = 0.0f;
                    func_800155B8_161B8(i, 0);
                    func_80015868_16468(i);
                    work->flags[i] &= ~1;
                } else {
                    func_800155B8_161B8(i, work->vol[i]);
                }
            }
        }
    }
}