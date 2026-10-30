#include "ovl_0D.h"

void func_80102800_138530_HotBobOmb(void) {
    func_8002D4D0_2E0D0(4);
    func_80020D20_21920(0x50);
    omInitObjMan(0x20, 0);
    func_80079128_79D28();
    func_8000C38C_CF8C();
    omAddObj(0xA, 0, 0, -1, func_80102D10_138A40_HotBobOmb);
    func_8002CA48_2D648(0, 0, 0);
    func_80102B30_138860_HotBobOmb();
    func_80026D28_27928(1);
    func_80026E00_27A00(0, 0.0f, 30.0f, 115.0f);
    func_80026DAC_279AC(0, 0xFF, 0xFF, 0xFF);
    func_801032EC_13901C_HotBobOmb();
    func_801028D4_138604_HotBobOmb();
    func_80102E94_138BC4_HotBobOmb();
    func_8010322C_138F5C_HotBobOmb();
    InitFadeIn(0, 0x10);
}

/* Each round's fuse (seconds) and the fuse sprite's bob period, drawn at random. */
void func_801028D4_138604_HotBobOmb(void) {
    D_80106E90_13CBC0_HotBobOmb[0] = (u8)(rand8() % 9) + 10;
    D_80106E90_13CBC0_HotBobOmb[1] = (u8)(rand8() % 9) + 8;
    D_80106E90_13CBC0_HotBobOmb[2] = (u8)(rand8() % 9) + 6;
    D_80106E90_13CBC0_HotBobOmb[3] = (u8)(rand8() % 7) + 4;
    D_80106E88_13CBB8_HotBobOmb = D_80106E90_13CBC0_HotBobOmb[D_80106E80_13CBB0_HotBobOmb];
    D_80106E8C_13CBBC_HotBobOmb = D_80106E90_13CBC0_HotBobOmb[3];
    D_80106EA0_13CBD0_HotBobOmb = 0x28;
    D_80106EA2_13CBD2_HotBobOmb = 0x1E;
    omAddObj(0, 0, 0, -1, func_80102A74_1387A4_HotBobOmb);
}

/* Counts the fuse down one second every 30 frames. */
void func_80102A28_138758_HotBobOmb(omObjData* obj) {
    D_80106EA2_13CBD2_HotBobOmb--;
    if (D_80106EA2_13CBD2_HotBobOmb == 0) {
        D_80106EA2_13CBD2_HotBobOmb = 0x1E;
        if (D_80106E88_13CBB8_HotBobOmb > 0) {
            D_80106E88_13CBB8_HotBobOmb--;
        }
    }
}

/* The start message; once it closes the game runs and the fuse starts. */
void func_80102A74_1387A4_HotBobOmb(omObjData* obj) {
    if (D_80106EA0_13CBD0_HotBobOmb == 0x28) {
        D_80106E86_13CBB6_HotBobOmb = PlaySound(0x4A3);
    }
    if (D_80106EA0_13CBD0_HotBobOmb != 0) {
        D_80106EA0_13CBD0_HotBobOmb--;
        if (D_80106EA0_13CBD0_HotBobOmb == 0) {
            func_800799A4_7A5A4(D_80106E86_13CBB6_HotBobOmb, 0x5A);
            func_800691FC_69DFC(0);
        }
    }
    if (func_80069538_6A138() == 2) {
        D_8010700C_13CD3C_HotBobOmb = 1;
        obj->func_ptr = func_80102A28_138758_HotBobOmb;
    }
}

void func_80102B30_138860_HotBobOmb(void) {
    s32 cam;

    D_8010274C_10334C.x = 0.0f;
    D_8010274C_10334C.y = 0.0f;
    D_8010274C_10334C.z = 20.0f;
    D_800FD474_FE074.x = -52.0f;
    D_800FD474_FE074.y = 0.0f;
    D_800FD474_FE074.z = 0.0f;
    D_800FA610_FB210 = 1050.0f;
    D_80106F9C_13CCCC_HotBobOmb.x = 0.0f;
    D_80106F9C_13CCCC_HotBobOmb.y = 50.0f;
    D_80106F9C_13CCCC_HotBobOmb.z = 50.0f;
    D_80106FBC_13CCEC_HotBobOmb.x = 0.0f;
    D_80106FBC_13CCEC_HotBobOmb.y = 0.0f;
    D_80106FBC_13CCEC_HotBobOmb.z = -120.0f;
    D_80106FD8_13CD08_HotBobOmb.x = 0.0f;
    D_80106FD8_13CD08_HotBobOmb.y = 1.0f;
    D_80106FD8_13CD08_HotBobOmb.z = 0.0f;
    func_80018E30_19A30(1);
    cam = func_80018E78_19A78();
    ScissorSet(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(cam, 45.0f, 80.0f, 8000.0f);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_80079E60_7AA60), 0xA0);
}

/* Unused: applies the camera. */
void func_80102CD4_138A04_HotBobOmb(void) {
    Hu3DCamSetPositionOrientation(0, &D_80106F9C_13CCCC_HotBobOmb, &D_80106FBC_13CCEC_HotBobOmb,
                                  &D_80106FD8_13CD08_HotBobOmb);
    Hu3DCamUpdateMtx(0);
}

void func_80102D10_138A40_HotBobOmb(omObjData* obj) {
    if (D_80106F90_13CCC0_HotBobOmb != 0) {
        if (func_8008F618_90218() == 0) {
            omOvlReturnEx(1);
        }
    } else if (D_801011FC_101DFC == 1) {
        func_80079614_7A214(0x3C);
        func_800794A8_7A0A8(0x3C);
        InitFadeOut(0, 0x14);
        D_80106F90_13CCC0_HotBobOmb = 1;
    }
}

/* The stage model's object, once loaded: starts the music. */
void func_80102D8C_138ABC_HotBobOmb(omObjData* obj) {
    func_8000C3C8_CFC8();
    if (D_80106C54_13C984_HotBobOmb == 0) {
        PlayMusic(0x1B);
        D_80106C54_13C984_HotBobOmb = 1;
    }
}

/* The fuse sprite. */
s16 func_80102DCC_138AFC_HotBobOmb(void) {
    s16 spr;
    void* data;
    s16 anim;

    spr = SprCreate(1, 5);
    data = DataRead(0x1C0004);
    anim = SprAnimRead(data);
    DataClose(data);
    SprAnimSet(spr, 0, anim, 0);
    SprPosSet(spr, 0, 0xA0, 0xC8);
    SprAttrReset(spr, 0, 0xFFFF);
    SprAttrSet(spr, 0, 8);
    SprPrioSet(spr, 0, 0x7000);
    return spr;
}

void func_80102E94_138BC4_HotBobOmb(void) {
    void* data;

    D_80106F92_13CCC2_HotBobOmb = SprCreate(1, 5);
    data = DataRead(0x1C0003);
    D_80106FCC_13CCFC_HotBobOmb = SprAnimRead(data);
    DataClose(data);
    SprAnimSet(D_80106F92_13CCC2_HotBobOmb, 0, D_80106FCC_13CCFC_HotBobOmb, 0);
    SprPosSet(D_80106F92_13CCC2_HotBobOmb, 0, 0xA0, 0x78);
    SprAttrReset(D_80106F92_13CCC2_HotBobOmb, 0, 0xFFFF);
    SprAttrSet(D_80106F92_13CCC2_HotBobOmb, 0, 0x4000);
    SprPrioSet(D_80106F92_13CCC2_HotBobOmb, 0, 0x8000);
    D_80106ED8_13CC08_HotBobOmb = func_80102DCC_138AFC_HotBobOmb();
    D_800F8FE0_F9BE0 = 0;
    func_8000C018_CC18(0);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(1, 4, 0, -1, func_80102FF0_138D20_HotBobOmb);
    D_80106C44_13C974_HotBobOmb = 280.0f;
    omAddObj(1, 4, 0, -1, func_80103034_138D64_HotBobOmb);
}

void func_80102FF0_138D20_HotBobOmb(omObjData* obj) {
    obj->model[0] = func_80018A30_19630(0x1C0001, 0x28D);
    obj->func_ptr = func_80102D8C_138ABC_HotBobOmb;
}

/* The fuse sprite: slides in, then bobs (faster as the round ends).
   NON_MATCHING: retail keeps min in s0 and max in s1, and reloads the period for the divide
   (address CSE'd, value not); masked 4. */
#ifdef NON_MATCHING
void func_80103034_138D64_HotBobOmb(omObjData* obj) {
    s32 max;
    s32 min;

    switch (D_8010700C_13CD3C_HotBobOmb) {
    case 0:
        D_80106C44_13C974_HotBobOmb =
            (D_80106C44_13C974_HotBobOmb > 200.0f) ? D_80106C44_13C974_HotBobOmb - 4.0f : 200.0f;
        min = 10;
        max = 16;
        break;
    case 1:
        D_80106C44_13C974_HotBobOmb = 200.0f;
        min = 8;
        max = 16;
        break;
    case 2:
        min = 4;
        D_80106C44_13C974_HotBobOmb = 200.0f;
        max = 6;
        break;
    }
    if (--D_80106E8C_13CBBC_HotBobOmb == 0) {
        if (D_80106EE8_13CC18_HotBobOmb == 7) {
            D_80106E8C_13CBBC_HotBobOmb = 4;
        } else {
            D_80106E8C_13CBBC_HotBobOmb = D_80106E90_13CBC0_HotBobOmb[3] = rand8() % (max - min + 1) + min;
        }
    }
    obj->trans.y = HuMathSin(((f32)D_80106E90_13CBC0_HotBobOmb[3] - (f32)D_80106E8C_13CBBC_HotBobOmb) /
                                 (f32)D_80106E90_13CBC0_HotBobOmb[3] * 180.0f) * 8.0f +
                   D_80106C44_13C974_HotBobOmb;
    SprPosSet(D_80106ED8_13CC08_HotBobOmb, 0, 0xA0, obj->trans.y);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0D_HotBobOmb/138530", func_80103034_138D64_HotBobOmb);
#endif

void func_8010322C_138F5C_HotBobOmb(void) {
    s32 i;

    D_80106C30_13C960_HotBobOmb = 0;
    D_800FC87A_FD47A = 0;
    for (i = 0; i < 4; i++) {
        D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(2, 1, 0x14, -1, func_8010349C_1391CC_HotBobOmb);
    }
    D_80106ED4_13CC04_HotBobOmb = omAddObj(2, 0xC, 0xA, -1, func_80105124_13AE54_HotBobOmb);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0D_HotBobOmb/138530", func_801032EC_13901C_HotBobOmb);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0D_HotBobOmb/138530", func_8010349C_1391CC_HotBobOmb);

__asm__(".section .rodata");
const u32 D_80106C90_13C9C0_HotBobOmb[3] = { 0x00000010, 0x0000000E, 0x0000000C };

__asm__(".section .rodata");
const char D_80106C9C_13C9CC_HotBobOmb[] = "item_hook";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0D_HotBobOmb/138530", func_801037D0_139500_HotBobOmb);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0D_HotBobOmb/138530", func_801045B0_13A2E0_HotBobOmb);

__asm__(".section .rodata");
const u32 D_80106CE0_13CA10_HotBobOmb[36] = { 0x00000003, 0x00000003, 0x00000002, 0x00000003, 0x00000002, 0x00000001, 0x00000003, 0x00000001, 0x00000001, 0x00000003, 0x00000003, 0x00000002, 0x00000000, 0x00000003, 0x00000002, 0x00000000, 0x00000000, 0x00000002, 0x00000003, 0x00000003, 0x00000003, 0x00000003, 0x00000000, 0x00000001, 0x00000000, 0x00000001, 0x00000001, 0x00000002, 0x00000002, 0x00000002, 0x00000000, 0x00000001, 0x00000002, 0x00000000, 0x00000000, 0x00000001 };

__asm__(".section .rodata");
const u32 D_80106D70_13CAA0_HotBobOmb[16] = { 0x00000001, 0x00000002, 0x00000003, 0x00000000, 0x00000002, 0x00000003, 0x00000000, 0x00000001, 0x00000003, 0x00000000, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000002, 0x00000003 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0D_HotBobOmb/138530", func_80104674_13A3A4_HotBobOmb);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0D_HotBobOmb/138530", func_80104790_13A4C0_HotBobOmb);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0D_HotBobOmb/138530", func_80104A50_13A780_HotBobOmb);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0D_HotBobOmb/138530", func_80104CD4_13AA04_HotBobOmb);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0D_HotBobOmb/138530", func_80104D80_13AAB0_HotBobOmb);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0D_HotBobOmb/138530", func_80104E34_13AB64_HotBobOmb);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0D_HotBobOmb/138530", func_80104F7C_13ACAC_HotBobOmb);

__asm__(".section .rodata");
const char D_80106DC8_13CAF8_HotBobOmb[] = "c104_n0_DEF";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0D_HotBobOmb/138530", func_80105124_13AE54_HotBobOmb);

__asm__(".section .rodata");
const u32 D_80106DD4_13CB04_HotBobOmb[13] = { 0x43AA0000, 0x43FA0000, 0x442F0000, 0xC3AA0000, 0x43FA0000, 0x442F0000, 0xC3AA0000, 0x43FA0000, 0xC42F0000, 0x43AA0000, 0x43FA0000, 0xC42F0000, 0x00000000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0D_HotBobOmb/138530", func_801056C8_13B3F8_HotBobOmb);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0D_HotBobOmb/138530", func_80106750_13C480_HotBobOmb);
