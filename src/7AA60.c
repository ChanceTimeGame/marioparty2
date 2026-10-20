#include "common.h"
#include "game/camera.h"

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

INCLUDE_ASM("asm/nonmatchings/7AA60", func_8007A27C_7AE7C);

INCLUDE_ASM("asm/nonmatchings/7AA60", func_8007A2CC_7AECC);

INCLUDE_ASM("asm/nonmatchings/7AA60", func_8007A420_7B020);

INCLUDE_ASM("asm/nonmatchings/7AA60", func_8007A4A0_7B0A0);

INCLUDE_ASM("asm/nonmatchings/7AA60", func_8007A718_7B318);

INCLUDE_ASM("asm/nonmatchings/7AA60", func_8007A7FC_7B3FC);

INCLUDE_ASM("asm/nonmatchings/7AA60", func_8007AFDC_7BBDC);

INCLUDE_ASM("asm/nonmatchings/7AA60", func_8007B284_7BE84);

INCLUDE_ASM("asm/nonmatchings/7AA60", func_8007B658_7C258);

INCLUDE_ASM("asm/nonmatchings/7AA60", func_8007B818_7C418);

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

INCLUDE_ASM("asm/nonmatchings/7AA60", func_8007BA44_7C644);

INCLUDE_ASM("asm/nonmatchings/7AA60", func_8007BB74_7C774);
