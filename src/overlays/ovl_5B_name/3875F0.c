#include "common.h"
#include "ovl_5B.h"

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010A940_3875F0_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010ACBC_38796C_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010B5A8_388258_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010B654_388304_name_5B);



__asm__(".section .rodata");
const char D_801139A4_390654_name_5B[] = "record";

__asm__(".section .rodata");
const char D_801139AC_39065C_name_5B[] = "hari";

/* Opens the record book (model [12]): the cover ("hari") swings while the "record" part lifts
   towards the camera. */
void func_8010C5D4_389284_name_5B(void) {
    s16 model = D_80114758_391408_name_5B[12];
    s16 frame;
    HmfMotionObj* hari;
    HmfMotionObj* record;
    f32 hariY;
    f32 x, y, z;
    f32 dx, dy, dz;
    f32 t;
    f32 angle;
    s16 i;

    frame = func_80029E14_2AA14(model);
    func_80029E80_2AA80(model, 1, 1);
    func_8003B72C_3C32C(model, frame, D_801139A4_390654_name_5B, 0x4C, 0x47);
    hari = func_8002A9F4_2B5F4(model, D_801139AC_39065C_name_5B);
    record = func_8002A9F4_2B5F4(model, D_801139A4_390654_name_5B);
    hariY = hari->unk04.y;
    x = record->unk04.x;
    dx = 100.0f - x;
    y = record->unk04.y;
    dy = 140.0f - y;
    z = record->unk04.z;
    dz = -6.0f - z;
    PlaySound(D_800CD52C_CE12C == 1 ? 0xC2 : 0x370);
    for (i = 0; i < 11; i++) {
        t = i;
        angle = t * 9.0f;
        hari->unk28.y = hariY + HuMathSin(angle) * 10.0f;
        record->unk28.x = x + HuMathSin(angle) * dx;
        record->unk28.y = y + t / 10.0f * dy;
        record->unk28.z = z + HuMathSin(angle) * dz;
        if (i >= 4) {
            record->unk10.z = (i - 3) * 12.857142f;
        }
        HuPrcVSleep();
    }
}

/* Closes the record book (model [12]), the reverse of 8010C5D4. mode 0 restores the model's
   textures; otherwise its texture animation slot D_801144A8 is reset to frame D_801144AA (mode
   1) or D_801144A8 (mode 2). */
void func_8010C828_3894D8_name_5B(s16 mode) {
    u16 model = D_80114758_391408_name_5B[12];
    TexAnimSlot* slot;
    HmfMotionObj* hari;
    HmfMotionObj* record;
    f32 hariY;
    f32 x, y, z;
    f32 dx, dy, dz;
    f32 t;
    f32 angle;
    s16 i;

    if (mode == 0) {
        func_8003EE44_3FA44(D_800FC834_FD434[(s16)model].hmf);
    } else {
        func_8003EEA4_3FAA4(D_800FC834_FD434[(s16)model].hmf);
        slot = &D_800FD7F8_FE3F8[D_801144A8_391158_name_5B];
        if (mode == 1) {
            slot->unk_00 = D_801144AA_39115A_name_5B;
        } else {
            slot->unk_00 = D_801144A8_391158_name_5B;
        }
        slot->unk_04 = 0;
        slot->unk_0A = 0;
        slot->unk_06 = 0;
        slot->unk_02 = 0;
    }
    func_80029E14_2AA14(model);
    hari = func_8002A9F4_2B5F4(model, D_801139AC_39065C_name_5B);
    record = func_8002A9F4_2B5F4(model, D_801139A4_390654_name_5B);
    hariY = hari->unk04.y;
    x = record->unk04.x;
    dx = 100.0f - x;
    y = record->unk04.y;
    dy = 140.0f - y;
    z = record->unk04.z;
    dz = -6.0f - z;
    for (i = 0; i < 11; i++) {
        t = i;
        angle = t * 9.0f;
        record->unk28.x = x + func_800B7890_B8490(angle) * dx;
        record->unk28.y = y + (1.0f - t / 10.0f) * dy;
        record->unk28.z = z + func_800B7890_B8490(angle) * dz;
        if (i < 8) {
            record->unk10.z = 90.0f - t * 12.857142f;
        }
        HuPrcVSleep();
    }
    for (i = 0; i < 6; i++) {
        hari->unk28.y = hariY + func_800B7890_B8490(i * 18.0f) * 10.0f;
        HuPrcVSleep();
    }
    PlaySound(D_800CD52C_CE12C == 1 ? 0xC1 : 0x320);
    func_80029E80_2AA80(model, 1, 0);
    HuPrcSleep(10);
}

/* The record book's sound test (model [15], its shadow [17]): the book rises, a page window
   lists the page's sounds (D_801137F0: message and sound count per page, -1 ends; the last page
   only with flag 0xB). A plays the chosen sound, the pad's left/right (0x200/0x100) turn one page,
   C-left/C-right (2/1) two; each turned page plays the page motion. B closes the book. */
#ifdef NON_MATCHING
/* NON_MATCHING: logic complete; GCC's loop-invariant hoisting differs (retail hoists the table
   addresses in the page loops and only two window offsets) and the branch layout of the C-right
   case. */
void func_8010CB88_389838_name_5B(void) {
    u16 model = D_80114758_391408_name_5B[15];
    u16 shadow = D_80114758_391408_name_5B[17];
    s16 i;
    f32 scale;
    f32 one;
    s16 win;
    s16 win2;
    s16 sound;
    s16 pages;
    s16 choice;
    s16 step;
    s16 sum;
    s16 idx;
    TextWindow* w;

    sound = -1;
    if (!_CheckFlag(0xB)) {
        D_801137F0_3904A0_name_5B[15][0] = D_801137F0_3904A0_name_5B[15][1] = sound;
    }
    for (i = 1; i < 3; i++) {
        D_800FC834_FD434[(s16)model].pos.y += 5.0f;
        HuPrcVSleep();
    }
    one = scale = 1.0f;
    func_8002C9C0_2D5C0(model, D_801147D0_391480_name_5B[15]);
    while (func_80029CE4_2A8E4(model) < 30.0f) {
        scale -= 0.03f;
        func_800297E8_2A3E8(shadow, one, 1.0f, scale);
        HuPrcVSleep();
    }
    D_801144AC_39115C_name_5B = 0;
    D_801144AE_39115E_name_5B = model;
    D_801144C0_391170_name_5B.x = D_800FC834_FD434[(s16)model].rot.x;
    D_801144C0_391170_name_5B.y = D_800FC834_FD434[(s16)model].rot.y;
    D_801144C0_391170_name_5B.z = D_800FC834_FD434[(s16)model].rot.z;
    D_801144B4_391164_name_5B.x = D_800FC834_FD434[(s16)model].pos.x;
    D_801144B4_391164_name_5B.y = D_800FC834_FD434[(s16)model].pos.y;
    D_801144B4_391164_name_5B.z = D_800FC834_FD434[(s16)model].pos.z;
    D_801144B0_391160_name_5B[0] = shadow;
    PlaySound(0xA4);
    PlaySound(0xA8);
    func_80108788_385438_name_5B(15, 20, 0, func_8010D6E8_38A398_name_5B);
    win = func_800888A8_894A8(0xA0, 0x20, 0x80, 0xAA, 0, 0);
    func_8008D59C_8E19C(win, 1 << D_80114862_391512_name_5B);
    func_80089284_89E84(win, 0x8020, 0x8020);
    D_800F920C_F9E0C[win].unkAA = -1;
    func_80089B2C_8A72C(win, 0);
    func_80089A48_8A648(win, 0);
    func_80089C78_8A878(win, 1);
    func_80089DA0_8A9A0(win, 0xA0, 0xA0, 0x90);
    win2 = func_800888A8_894A8(0xA0, 0xAC, 0x80, 0x24, 0, 0);
    func_80089B2C_8A72C(win2, 0);
    func_80089A48_8A648(win2, 0);
    func_80089C78_8A878(win2, 1);
    func_80089DA0_8A9A0(win2, 0xA0, 0xA0, 0x90);
    pages = 0;
    while (D_801137F0_3904A0_name_5B[pages][0] != -1) {
        pages++;
    }
    choice = 0;
    step = 0;
    func_800890CC_89CCC(win, D_801137F0_3904A0_name_5B[D_80113834_3904E4_name_5B][0], -1, -1);
    func_800794A8_7A0A8(20);
    func_8010C5D4_389284_name_5B();
    D_800CD52C_CE12C = 0;
    HuPrcSleep(10);
    func_80079464_7A064();
    func_80079868_7A468();
    HuPrcSleep(10);
    while (func_8000E930_F530()) {
        HuPrcVSleep();
    }
    func_80079DB4_7A9B4();
    func_8010C828_3894D8_name_5B(2);
    while (1) {
        func_800890CC_89CCC(win, D_801137F0_3904A0_name_5B[D_80113834_3904E4_name_5B][0], -1, -1);
        func_800890CC_89CCC(win2, 0x676, -1, 0x90);
        while (func_8008BA30_8C630(win)) {
            HuPrcVSleep();
        }
        func_8008DF9C_8EB9C(win, 0x303);
        func_8008BB48_8C748(win, choice, 0);
        if (D_800F920C_F9E0C[win].unkA8 & 0x4000) {
            break;
        }
        if (D_800F920C_F9E0C[win].unkA8 & 0x8000) {
            for (i = 0, sum = 0; i < D_80113834_3904E4_name_5B; i++) {
                sum += D_801137F0_3904A0_name_5B[i][1];
            }
            idx = sum + D_800F920C_F9E0C[win].unk32;
            func_80079868_7A468();
            sound = PlaySound(D_801135E0_390290_name_5B[idx]);
        }
        if ((D_800F920C_F9E0C[win].unkA8 & 0x200) && D_80113834_3904E4_name_5B > 0) {
            D_80113834_3904E4_name_5B--;
            step = -1;
        } else if ((D_800F920C_F9E0C[win].unkA8 & 0x100)
                   && D_801137F0_3904A0_name_5B[D_80113834_3904E4_name_5B + 1][0] != -1) {
            D_80113834_3904E4_name_5B++;
            step = 1;
        } else if (D_800F920C_F9E0C[win].unkA8 & 2) {
            step = -D_80113834_3904E4_name_5B;
            if (D_80113834_3904E4_name_5B < 2) {
                D_80113834_3904E4_name_5B = 0;
            } else {
                D_80113834_3904E4_name_5B -= 2;
                step = -2;
            }
        } else if (D_800F920C_F9E0C[win].unkA8 & 1) {
            step = 2;
            if (D_80113834_3904E4_name_5B + 2 >= pages) {
                step = pages - (D_80113834_3904E4_name_5B + 1);
                D_80113834_3904E4_name_5B = pages - 1;
            } else {
                D_80113834_3904E4_name_5B += 2;
            }
        }
        if (step != 0) {
            func_8008D5D8_8E1D8(win);
            func_8008D5D8_8E1D8(win2);
            for (i = 0; i < (step < 0 ? -step : step); i++) {
                PlaySound(0x354);
                func_8002C9C0_2D5C0(model, D_801147D0_391480_name_5B[16]);
                func_80029FE4_2ABE4(model, (step >= 0) ? step : -step);
                if (step > 0) {
                    while (func_80029CE4_2A8E4(model) < func_80029D0C_2A90C(model)) {
                        HuPrcVSleep();
                    }
                } else {
                    func_80029C74_2A874(model, func_80029D0C_2A90C(model));
                    func_80029E80_2AA80(model, 4, 4);
                    while (func_80029CE4_2A8E4(model) != 0.0f) {
                        HuPrcVSleep();
                    }
                }
            }
            func_8008D6F0_8E2F0(win);
            func_8008D6F0_8E2F0(win2);
            step = 0;
        }
        w = &D_800F920C_F9E0C[win];
        choice = w->unk32;
        if (choice >= D_801137F0_3904A0_name_5B[D_80113834_3904E4_name_5B][1]) {
            w->unk32 = D_801137F0_3904A0_name_5B[D_80113834_3904E4_name_5B][1] - 1;
            choice = w->unk32;
        }
    }
    func_800794A8_7A0A8(20);
    if (sound != -1) {
        func_80079848_7A448(sound);
    }
    func_8010C5D4_389284_name_5B();
    HuPrcSleep(10);
    D_800CD52C_CE12C = 1;
    func_80079464_7A064();
    func_80079868_7A468();
    HuPrcSleep(10);
    while (func_8000E930_F530()) {
        HuPrcVSleep();
    }
    func_80079DB4_7A9B4();
    func_8010C828_3894D8_name_5B(0);
    PlayMusic(4);
    func_8008CCA8_8D8A8(win);
    func_8008CCA8_8D8A8(win2);
    func_8002C9C0_2D5C0(model, D_801147D0_391480_name_5B[15]);
    func_80029C74_2A874(model, func_80029D0C_2A90C(model));
    func_80029E80_2AA80(model, 4, 4);
    func_8002979C_2A39C(model, D_801144C0_391170_name_5B.x, D_801144C0_391170_name_5B.y, D_801144C0_391170_name_5B.z);
    D_801144AC_39115C_name_5B = 1;
    PlaySound(0xA9);
    func_80108788_385438_name_5B(10, 15, 0, func_8010D6E8_38A398_name_5B);
    while (func_80029CE4_2A8E4(model) != 0.0f) {
        scale += 0.03f;
        func_800297E8_2A3E8(shadow, one, 1.0f, scale);
        HuPrcVSleep();
    }
    func_800297E8_2A3E8(shadow, 1.0f, 1.0f, 1.0f);
    for (i = 1; i < 3; i++) {
        D_800FC834_FD434[(s16)model].pos.y -= 5.0f;
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010CB88_389838_name_5B);
#endif

/* 80108788's per-frame callback while the camera moves to the record book: moves the book (and
   its shadow) between its place and a point 145 in front of the camera at screen (316, 208);
   towards the camera when D_801144AC is 0 (the book then faces the camera), back otherwise. */
void func_8010D6E8_38A398_name_5B(s16* arg0) {
    Ovl5BCamStep* step = (Ovl5BCamStep*)arg0;
    f32 screen[2];
    f32 t;
    f32 x, y, z;

    if (step->frame == 0) {
        screen[0] = 316.0f;
        screen[1] = 208.0f;
        if (D_801144AC_39115C_name_5B == 0) {
            func_8010A53C_3871EC_name_5B(15, 145.0f, screen, &step->to);
            step->from.x = D_800FC834_FD434[D_801144AE_39115E_name_5B].pos.x;
            step->from.y = D_800FC834_FD434[D_801144AE_39115E_name_5B].pos.y;
            step->from.z = D_800FC834_FD434[D_801144AE_39115E_name_5B].pos.z;
        } else {
            func_8010A53C_3871EC_name_5B(15, 145.0f, screen, &step->from);
            step->to = D_801144B4_391164_name_5B;
        }
    }
    t = HuMathSin(step->frame * 90.0f / step->len);
    x = t * (step->to.x - step->from.x) + step->from.x;
    y = t * (step->to.y - step->from.y) + step->from.y;
    z = t * (step->to.z - step->from.z) + step->from.z;
    func_80029714_2A314(D_801144AE_39115E_name_5B, x, y, z);
    func_80029714_2A314(D_801144B0_391160_name_5B[0], x, 104.0f, z);
    if (D_801144AC_39115C_name_5B == 0) {
        func_8002979C_2A39C(D_801144AE_39115E_name_5B, D_800FD474_FE074.x, D_800FD474_FE074.y, D_800FD474_FE074.z);
    }
}

/* Toggles the record book's mono/stereo switch (D_80114860; flag 2 set = stereo): plays the
   switch motion forwards (mono) or backwards (stereo), then its idle motion for the new state. */
void func_8010D8B0_38A560_name_5B(void) {
    u16 model = D_80114758_391408_name_5B[12];

    D_80114860_391510_name_5B ^= 1;
    func_8002C9C0_2D5C0(model, D_801147D0_391480_name_5B[14]);
    func_80088604_89204(D_80114862_391512_name_5B, 5, 0, 5);
    if (D_80114860_391510_name_5B != 0) {
        _ClearFlag(2);
        func_8000EA88_F688(1);
        while (func_80029CE4_2A8E4(model) != func_80029D0C_2A90C(model)) {
            HuPrcVSleep();
        }
        func_8002C9C0_2D5C0(model, D_801147D0_391480_name_5B[13]);
    } else {
        _SetFlag(2);
        func_8000EA88_F688(0);
        func_80029C74_2A874(model, func_80029D0C_2A90C(model));
        func_80029E80_2AA80(model, 4, 4);
        while (func_80029CE4_2A8E4(model) != 0.0f) {
            HuPrcVSleep();
        }
        func_8002C9C0_2D5C0(model, D_801147D0_391480_name_5B[12]);
    }
    func_80029E80_2AA80(model, 2, 2);
}

/* Leaves the menu for overlay 0x61 through models [7] and [8]: [8] plays its motion, then both
   shake for 100 frames (rumble every 8) while the music fades and a white wipe closes at frame
   60. Sets flag 0x1A; returns to 5B's entry 2 afterwards (history). Does not return. */
void func_8010DA34_38A6E4_name_5B(void) {
    s16 model = D_80114758_391408_name_5B[8];
    f32 shake = 1.0f;
    f32 x, y, z;
    f32 sx, sz;
    s16 i;

    func_8002C9C0_2D5C0(model, D_801147D0_391480_name_5B[8]);
    func_80029FE4_2ABE4(D_80114758_391408_name_5B[7], shake);
    PlaySound(0xB9);
    while (func_80029CE4_2A8E4(model) < func_80029D0C_2A90C(model)) {
        HuPrcVSleep();
    }
    PlaySound(0xBA);
    func_80029FE4_2ABE4(D_80114758_391408_name_5B[7], 3.0f);
    x = D_800FC834_FD434[model].pos.x;
    y = D_800FC834_FD434[model].pos.y;
    z = D_800FC834_FD434[model].pos.z;
    for (i = 0; i < 100; i++) {
        if ((i & 7) == 0) {
            func_80088604_89204(D_80114862_391512_name_5B, 5, 0, 5);
        }
        sx = x + shake;
        sz = z + shake;
        func_80029714_2A314(D_80114758_391408_name_5B[7], sx, y, sz);
        func_80029714_2A314(model, sx, y, sz);
        shake = -shake;
        if (i == 60) {
            func_80079614_7A214(70);
            func_800794A8_7A0A8(80);
            func_8008F624_90224(0xFF, 0xFF, 0xFF);
            InitFadeOut(0, 40);
        }
        HuPrcVSleep();
    }
    _SetFlag(0x1A);
    func_80088604_89204(D_80114862_391512_name_5B, 5, 0, 5);
    D_8011269A_38F34A_name_5B = 1;
    HuPrcSleep(3);
    if (D_801134D0_390180_name_5B[0] != 0) {
        func_8007DF5C_7EB5C();
    }
    omOvlHisChg(0, 0x5B, 2, 0x1014);
    D_80114850_391500_name_5B = 2;
    D_8011473A_3913EA_name_5B = 0x61;
    D_80112690_38F340_name_5B = 1;
    while (1) {
        HuPrcVSleep();
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010DCAC_38A95C_name_5B);


__asm__(".section .rodata");
const char D_801139B4_390664_name_5B[] = "item_hook";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010DF24_38ABD4_name_5B);


__asm__(".section .rodata");
const char D_801139C0_390670_name_5B[] = "%d";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010E618_38B2C8_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010ED80_38BA30_name_5B);



__asm__(".section .rodata");
const u32 D_801139C8_390678_name_5B[2] = { 0x05256405, 0x00000000 };

__asm__(".section .rodata");
const u32 D_801139D0_390680_name_5B[2] = { 0x05253032, 0x64050000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8010F734_38C3E4_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_801101E8_38CE98_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_80110770_38D420_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_8011083C_38D4EC_name_5B);


__asm__(".section .rodata");
const char D_801139F4_3906A4_name_5B[28] = "c168_000-atama";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_80110908_38D5B8_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_80110AF8_38D7A8_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_80112094_38ED44_name_5B);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5B_name/3875F0", func_80112304_38EFB4_name_5B);
