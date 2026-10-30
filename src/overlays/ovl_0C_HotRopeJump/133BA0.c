#include "ovl_0C.h"

/* Sets up the lights and the floor and torch objects (MP1 func_800FB260). */
void func_80107FB0_133BA0_HotRopeJump(void) {
    HRJLight* l;
    s32 i;

    l = D_80111420_13D010_HotRopeJump;
    for (i = 0; i < 32; i++, l++) {
        l->used = 0;
        l->z = 0;
        l->y = 0;
        l->x = 0;
        l->radius = l->aspect = l->radiusSq = 0;
        l->fadeFrom = l->fadeTime = l->fade = 0;
    }
    D_8011182C_13D41C_HotRopeJump = 0;
    D_80111830_13D420_HotRopeJump = 1.0f;
    omAddObj(10, 3, 0, -1, func_801085B4_1341A4_HotRopeJump);
    omAddObj(8, 2, 0, -1, func_801096E4_1352D4_HotRopeJump);
    omAddObj(9, 13, 0, -1, func_8010A0F0_135CE0_HotRopeJump);
    func_80026D28_27928(4);
    func_80026DAC_279AC(4, 0, 0, 0);
}

void func_801080A0_133C90_HotRopeJump(void) {
    HuMemFree(D_80111920_13D510_HotRopeJump);
    HuMemFree(D_80111924_13D514_HotRopeJump);
    func_80023D74_24974((s32)D_80111918_13D508_HotRopeJump[0]); /* a pointer (host) */
}

/* The scene lights (MP1 func_800FB354): while the blend changes, the ambient colour and light 3
   move between their two colours (and the lit place-3 player follows light 3); light 3 points
   along the rope's angle. */
void func_801080D8_133CC8_HotRopeJump(f32 angle) {
    Matrix4f m;
    Vec v;
    HuCamera* c;

    c = D_800C9B80_CA780;
    if (D_8010C268_137E58_HotRopeJump != D_8010C260_137E50_HotRopeJump) {
        D_80111410_13D000_HotRopeJump[0] = func_8010BF04_137AF4_HotRopeJump(D_8010C3A0_137F90_HotRopeJump[0][0], D_8010C3A4_137F94_HotRopeJump, D_8010C260_137E50_HotRopeJump);
        D_80111410_13D000_HotRopeJump[1] = func_8010BF04_137AF4_HotRopeJump(D_8010C3A1_137F91_HotRopeJump, D_8010C3A5_137F95_HotRopeJump, D_8010C260_137E50_HotRopeJump);
        D_80111410_13D000_HotRopeJump[2] = func_8010BF04_137AF4_HotRopeJump(D_8010C3A2_137F92_HotRopeJump, D_8010C3A6_137F96_HotRopeJump, D_8010C260_137E50_HotRopeJump);
        D_80111410_13D000_HotRopeJump[3] = func_8010BF04_137AF4_HotRopeJump(D_8010C3A8_137F98_HotRopeJump, D_8010C3AC_137F9C_HotRopeJump, D_8010C260_137E50_HotRopeJump);
        D_80111410_13D000_HotRopeJump[4] = func_8010BF04_137AF4_HotRopeJump(D_8010C3A9_137F99_HotRopeJump, D_8010C3AD_137F9D_HotRopeJump, D_8010C260_137E50_HotRopeJump);
        D_80111410_13D000_HotRopeJump[5] = func_8010BF04_137AF4_HotRopeJump(D_8010C3AA_137F9A_HotRopeJump, D_8010C3AE_137F9E_HotRopeJump, D_8010C260_137E50_HotRopeJump);
        func_80026DAC_279AC(0, D_80111410_13D000_HotRopeJump[0], D_80111410_13D000_HotRopeJump[1], D_80111410_13D000_HotRopeJump[2]);
        func_80026DAC_279AC(3, D_80111410_13D000_HotRopeJump[3], D_80111410_13D000_HotRopeJump[4], D_80111410_13D000_HotRopeJump[5]);
        if (D_80111928_13D518_HotRopeJump != -1) {
            func_8002D274_2DE74((s16)D_80111928_13D518_HotRopeJump, D_80111410_13D000_HotRopeJump[3], D_80111410_13D000_HotRopeJump[4], D_80111410_13D000_HotRopeJump[5]);
        }
    }
    func_80026DAC_279AC(2, 0, 0, 0);
    func_800B1960_B2560(m, c->pos.x, c->pos.y, c->pos.z, c->at.x, c->at.y, c->at.z, c->up.x, c->up.y, c->up.z);
    m[3][0] = m[3][1] = m[3][2] = 0.0f;
    func_8010C074_137C64_HotRopeJump(m, func_800B7890_B8490(angle) * 100.0, HuMathSin(angle) * 100.0, 0.0f, &v);
    func_80026DAC_279AC(1, 0x40, 0x40, 0x60);
    func_80026E00_27A00(1, 0.0f, 0.0f, -100.0f);
    func_80026E00_27A00(3, v.x, v.y, v.z);
}

/* The floor object's setup (MP1 func_800FB494): floor, its sprite and the two rope models. */
void func_801085B4_1341A4_HotRopeJump(omObjData* obj) {
    obj->func_ptr = func_801086AC_13429C_HotRopeJump;
    omSetStatBit(obj, 0xA0);
    D_80111824_13D414_HotRopeJump = func_8001A2F8_1AEF8(0x1D0002);
    obj->model[0] = func_80109078_134C68_HotRopeJump();
    obj->model[1] = LoadFormFile(0x1D0000, 0x219);
    D_800FC834_FD434[obj->model[1]].unk44 = 0.5f;
    obj->model[2] = LoadFormFile(0x1D0001, 0x219);
    D_800FC834_FD434[obj->model[2]].unk44 = 1.5f;
    D_80111918_13D508_HotRopeJump[0] = func_80105570_131160_HotRopeJump(obj->model[2], 2);
}

/* The floor object (MP1 func_800FB4E0): animates model 2, eases the light blend toward its
   target by 0.05 a frame, and updates the lights. */
void func_801086AC_13429C_HotRopeJump(omObjData* obj) {
    HmfModel* m;

    if (func_80078EA8_79AA8() + D_80102720_103320 == 0) {
        m = &D_800FC834_FD434[obj->model[2]];
        m->unk40 += m->unk44;
        if (m->unk40 >= 20.0) {
            m->unk40 = 0.0f;
        }
        func_80023A08_24608(obj->model[2], D_80111918_13D508_HotRopeJump[0], m->unk40);
        if (D_8010C260_137E50_HotRopeJump > D_8010C264_137E54_HotRopeJump) {
            D_8010C260_137E50_HotRopeJump -= 0.05;
        } else if (D_8010C260_137E50_HotRopeJump < D_8010C264_137E54_HotRopeJump) {
            D_8010C260_137E50_HotRopeJump += 0.05;
        }
        if (D_8010C268_137E58_HotRopeJump != D_8010C260_137E50_HotRopeJump) {
            D_8010C26C_137E5C_HotRopeJump = 0.9 - D_8010C260_137E50_HotRopeJump * 0.4;
        }
        func_801080D8_133CC8_HotRopeJump(D_80111920_13D510_HotRopeJump[6].angle);
    }
    func_8010BB48_137738_HotRopeJump(D_8010C260_137E50_HotRopeJump);
    if (D_8010C268_137E58_HotRopeJump != D_8010C260_137E50_HotRopeJump) {
        D_8010C268_137E58_HotRopeJump = D_8010C260_137E50_HotRopeJump;
    }
}

/* Takes a free floor light (MP1 func_800FB504); -1 when all 32 are used. */
s16 func_80108850_134440_HotRopeJump(f32 x, f32 y, f32 z, f32 radius) {
    HRJLight* l;
    s32 i;

    l = D_80111420_13D010_HotRopeJump;
    for (i = 0; i < 32; i++, l++) {
        if (l->used == 0) {
            break;
        }
    }
    if (i < 32) {
        l->used = 1;
        func_80108918_134508_HotRopeJump(i, x, y, z);
        func_80108978_134568_HotRopeJump(i, radius, radius);
        D_80111820_13D410_HotRopeJump++;
    } else {
        i = -1;
    }
    return i;
}

void func_80108918_134508_HotRopeJump(s16 id, f32 x, f32 y, f32 z) {
    D_80111420_13D010_HotRopeJump[id].x = x;
    D_80111420_13D010_HotRopeJump[id].y = y;
    D_80111420_13D010_HotRopeJump[id].z = z;
}

void func_80108978_134568_HotRopeJump(s16 id, f32 radius, f32 h) {
    D_80111420_13D010_HotRopeJump[id].radius = radius;
    D_80111420_13D010_HotRopeJump[id].aspect = radius / h;
    D_80111420_13D010_HotRopeJump[id].radiusSq = radius * radius;
    D_80111420_13D010_HotRopeJump[id].used = 1;
}

void func_801089D4_1345C4_HotRopeJump(s16 id) {
    D_80111420_13D010_HotRopeJump[id].used = 0;
}

/* Starts a light's fade over `time` frames (func_80108A44 shrinks it), unless one is running. */
void func_801089EC_1345DC_HotRopeJump(s16 id, s32 time) {
    if (D_80111420_13D010_HotRopeJump[id].fade == 0) {
        D_80111420_13D010_HotRopeJump[id].fadeTime = time;
        D_80111420_13D010_HotRopeJump[id].fade = time;
        D_80111420_13D010_HotRopeJump[id].fadeFrom = D_80111420_13D010_HotRopeJump[id].radius;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/133BA0", func_80108A44_134634_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/133BA0", func_80109078_134C68_HotRopeJump);

__asm__(".section .rodata");
const u32 D_8010C770_138360_HotRopeJump[4] = { 0x00000096, 0xFDA80000, 0x00000096, 0x025800B4 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/133BA0", func_801096E4_1352D4_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/133BA0", func_80109A58_135648_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/133BA0", func_8010A0F0_135CE0_HotRopeJump);

__asm__(".section .rodata");
const char D_8010C810_138400_HotRopeJump[] = "@Y";

__asm__(".section .rodata");
const char D_8010C814_138404_HotRopeJump[] = "";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/133BA0", func_8010A4E4_1360D4_HotRopeJump);

__asm__(".section .rodata");
const u32 D_8010C828_138418_HotRopeJump[1] = { 0x3FA99999 };

__asm__(".section .rodata");
const u32 D_8010C82C_13841C_HotRopeJump[1] = { 0x9999999A };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010C830_138420_HotRopeJump[2] = { 0x3FC99999, 0x9999999A };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010C838_138428_HotRopeJump[2] = { 0x3FECCCCC, 0xCCCCCCCD };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010C840_138430_HotRopeJump[2] = { 0x3FF00000, 0x00000000 };

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_8010C848_138438_HotRopeJump[8] = "@i";

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010C850_138440_HotRopeJump[2] = { 0x4062C000, 0x00000000 };

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_8010C858_138448_HotRopeJump[8] = "@I";

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_8010C860_138450_HotRopeJump[8] = "@T";

__asm__(".section .rodata");
const u32 jtbl_8010C868_138458_HotRopeJump[6] = { 0x8010A764, 0x8010A8F4, 0x8010A960, 0x8010AA30, 0x8010AC04, 0x8010ACF8 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010C880_138470_HotRopeJump[2] = { 0x40000000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010C888_138478_HotRopeJump[2] = { 0x40668000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010C890_138480_HotRopeJump[2] = { 0x400C0000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010C898_138488_HotRopeJump[2] = { 0x400C0000, 0x00000000 };

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_8010C8A0_138490_HotRopeJump[8] = "@I";

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010C8A8_138498_HotRopeJump[2] = { 0x40000000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010C8B0_1384A0_HotRopeJump[2] = { 0x40140000, 0x00000000 };

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_8010C8B8_1384A8_HotRopeJump[8] = "@>";

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010C8C0_1384B0_HotRopeJump[2] = { 0x4070E000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010C8C8_1384B8_HotRopeJump[2] = { 0xC0668000, 0x00000000 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010C8D0_1384C0_HotRopeJump[2] = { 0x40668000, 0x00000000 };

__asm__(".section .rodata");
const char __attribute__((aligned(8))) D_8010C8D8_1384C8_HotRopeJump[8] = "@$";

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010C8E0_1384D0_HotRopeJump[2] = { 0x3FC33333, 0x33333333 };

__asm__(".section .rodata");
const u32 __attribute__((aligned(8))) D_8010C8E8_1384D8_HotRopeJump[2] = { 0x3FE00000, 0x00000000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/133BA0", func_8010B0A0_136C90_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/133BA0", func_8010B754_137344_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/133BA0", func_8010BB48_137738_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/133BA0", func_8010BF04_137AF4_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/133BA0", func_8010BF70_137B60_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/133BA0", func_8010BF80_137B70_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/133BA0", func_8010BF8C_137B7C_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/133BA0", func_8010BF98_137B88_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/133BA0", func_8010C074_137C64_HotRopeJump);
