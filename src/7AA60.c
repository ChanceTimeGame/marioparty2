#include "common.h"

/* Object-manager camera view and a frame timer object (MP3 src/4BF40.c omOutView, MP1
   src/objmain.c). MP2's names are kept. */

typedef struct HuCameraUnk {
    /* 0x00 */ char unk_00[0x4C];
    /* 0x4C */ f32 fov[3];
} HuCameraUnk;

extern f32 D_800FA5BC_FB1BC[];
extern HuCameraUnk* D_800C9B80_CA780; /* MP3 gCameraList */
extern f32 D_80101078_101C78;
extern f32 D_800F8410_F9010;
extern omObjData* D_800FA5D4_FB1D4;
extern s32 D_80102748_103348;
extern u16 D_801011FC_101DFC;

f32 func_800B83C0_B8FC0(f32); /* HuMathSin */
f32 func_800B7890_B8490(f32); /* HuMathCos */
void func_80020260_20E60(s16 camIndex, Vec* pos, Vec* at, Vec* up);
void func_800203DC_20FDC(s16 camIndex);
void func_8007BA14_7C614(omObjData* obj);

/* func_80079E60_7AA60 is MP3 omOutView, whose omObjData argument is unused; functions.h declares it
   void, so it is kept that way here. */

void func_80079E60_7AA60(void) {
    Vec pos, at, up;
    f32 rot_x = D_800FD474_FE074.x;
    f32 rot_y = D_800FD474_FE074.y;

    pos.x = D_8010274C_10334C.x + func_800B83C0_B8FC0(rot_y) * func_800B7890_B8490(rot_x) * D_800FA610_FB210;
    pos.y = D_8010274C_10334C.y + -func_800B83C0_B8FC0(rot_x) * D_800FA610_FB210;
    pos.z = D_8010274C_10334C.z + func_800B7890_B8490(rot_y) * func_800B7890_B8490(rot_x) * D_800FA610_FB210;
    at.x = D_8010274C_10334C.x;
    at.y = D_8010274C_10334C.y;
    at.z = D_8010274C_10334C.z;
    up.x = func_800B83C0_B8FC0(rot_y) * func_800B83C0_B8FC0(rot_x);
    up.y = func_800B7890_B8490(rot_x);
    up.z = func_800B7890_B8490(rot_y) * func_800B83C0_B8FC0(rot_x);
    D_800FA5BC_FB1BC[0] = pos.x;
    D_800FA5BC_FB1BC[1] = pos.z;
    D_800FA5BC_FB1BC[-1] = D_800FD474_FE074.y;
    D_800FA5BC_FB1BC[2] = D_800C9B80_CA780->fov[0];
    D_800FA5BC_FB1BC[3] = D_80101078_101C78;
    D_800FA5BC_FB1BC[4] = D_800F8410_F9010;
    func_80020260_20E60(0, &pos, &at, &up);
    func_800203DC_20FDC(0);
}

INCLUDE_ASM("asm/nonmatchings/7AA60", func_80079FF4_7ABF4);

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
