#include "common.h"
#include "ovl_14.h"

__asm__(".section .rodata");
const char D_80106F90_16FED0_ShockDropOrRoll[] = "\202r\202s\202`\202q\202s";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_ShockDropOrRoll/16B740", func_80102800_16B740_ShockDropOrRoll);

/* The solo player's object. */
void func_80102EC8_16BE08_ShockDropOrRoll(omObjData* obj) {
    u8 chr = gPlayers[D_801072B8_1701F8_ShockDropOrRoll[0]].character;
    s32 dir = D_800CD438_CE038[chr].unk_04;
    s32 file = D_800CD438_CE038[chr].unk_08;

    func_80104B98_16DAD8_ShockDropOrRoll(obj, dir, file, D_801072B8_1701F8_ShockDropOrRoll[0], 0.0f, 200.0f, 600.0f);
}

/* Roller player 1's object. */
void func_80102F54_16BE94_ShockDropOrRoll(omObjData* obj) {
    u8 chr = gPlayers[D_801072B8_1701F8_ShockDropOrRoll[1]].character;
    s32 dir = D_800CD438_CE038[chr].unk_04;
    s32 file = D_800CD438_CE038[chr].unk_08;

    func_80103FE8_16CF28_ShockDropOrRoll(obj, dir, file, D_801072B8_1701F8_ShockDropOrRoll[1], -200.0f,
                                         450.0f, 0.0f, 0);
}

/* Roller player 2's object. */
void func_80102FE4_16BF24_ShockDropOrRoll(omObjData* obj) {
    u8 chr = gPlayers[D_801072B8_1701F8_ShockDropOrRoll[2]].character;
    s32 dir = D_800CD438_CE038[chr].unk_04;
    s32 file = D_800CD438_CE038[chr].unk_08;

    func_80103FE8_16CF28_ShockDropOrRoll(obj, dir, file, D_801072B8_1701F8_ShockDropOrRoll[2], 0.0f,
                                         450.0f, 0.0f, 1);
}

/* Roller player 3's object. */
void func_8010306C_16BFAC_ShockDropOrRoll(omObjData* obj) {
    u8 chr = gPlayers[D_801072B8_1701F8_ShockDropOrRoll[3]].character;
    s32 dir = D_800CD438_CE038[chr].unk_04;
    s32 file = D_800CD438_CE038[chr].unk_08;

    func_80103FE8_16CF28_ShockDropOrRoll(obj, dir, file, D_801072B8_1701F8_ShockDropOrRoll[3], 200.0f,
                                         450.0f, 0.0f, 2);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_ShockDropOrRoll/16B740", func_80103100_16C040_ShockDropOrRoll);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_ShockDropOrRoll/16B740", func_801038C4_16C804_ShockDropOrRoll);

__asm__(".section .rodata");
const u32 D_80106FA4_16FEE4_ShockDropOrRoll[13] = { 0x001E3223, 0x42F00000, 0x42FA0000, 0x001E321E, 0x42C80000, 0x43A28000, 0x001E3223, 0x43160000, 0x432F0000, 0x001E3223, 0x42C80000, 0x42480000, 0x001E3C28 };

__asm__(".section .rodata");
const u32 D_80106FD8_16FF18_ShockDropOrRoll[4] = { 0x00000064, 0x00000032, 0x00000019, 0x0000000A };

__asm__(".section .rodata");
const u32 D_80106FE8_16FF28_ShockDropOrRoll[2] = { 0x000A0008, 0x00060004 };

/* A roller player's setup: its SDPlayer, marker, sounds, models and motions. */
void func_80103FE8_16CF28_ShockDropOrRoll(omObjData* obj, s32 dir, s32 file, u16 player, f32 x, f32 y, f32 z, u16 slot) {
    MgWork* w;
    SDPlayer* p;
    s8 i;

    func_8000C6FC_D2FC(obj, dir, file, player, 0xAB9, 0xAB9);
    w = obj->unk_50;
    w->unk_158 = func_80027154_27D54(sizeof(SDPlayer), 0x7918);
    func_800B0EF0_B1AF0(w->unk_158, 0, sizeof(SDPlayer));
    p = w->unk_158;
    p->fell = 0;
    p->dropped = 0;
    p->cheered = 0;
    p->mark = D_801072C8_170208_ShockDropOrRoll->model[slot + 0x11];
    p->fallVel = -50.0f;
    p->jumpWait = 30;
    p->level = D_801072BC_1701FC_ShockDropOrRoll[slot];
    p->aimWait = 0;
    p->aim = 0.0f;
    p->spinWait = 0;
    p->spin = 0.0f;
    p->jump = 0;
    p->voiced = 0;
    for (i = 0; i < 3; i++) {
        p->pos[i] = 0.0f;
        p->rot[i] = 0.0f;
    }
    p->hist = 0;
    for (i = 0; i < 32; i++) {
        p->stk[i] = 0;
        p->btn[i] = 0;
        p->trg[i] = 0;
    }
    w->unk_3C = 0.0f;
    D_800BF7E4_C03E4[w->unk_59][4] = 0x2D2;
    D_800BF7E4_C03E4[w->unk_59][9] = 0x2D2;
    D_800BF7E4_C03E4[w->unk_59][7] = 0x2D2;
    obj->model[3] = LoadFormFile(7, 0x88D);
    obj->model[4] = LoadFormFile(8, 0x88D);
    obj->model[6] = LoadFormFile(9, 0x88D);
    obj->model[5] = LoadFormFile(0xA, 0x88D);
    obj->model[7] = LoadFormFile(0xC, 0x88D);
    obj->model[8] = LoadFormFile(0xB, 0x88D);
    func_8001A12C_1AD2C(obj, 0, dir, 1, 0, 0);
    func_8001A12C_1AD2C(obj, 1, dir | 1, 1, 0, 2);
    func_8001A12C_1AD2C(obj, 2, dir | 2, 1, 0, 3);
    func_80019F0C_1AB0C(obj, 6, dir | 4, 1, 0x13);
    func_80019F0C_1AB0C(obj, 9, dir | 7, 1, 0x27);
    func_80019F0C_1AB0C(obj, 0x10, dir | 0xE, 1, 0);
    func_80019F0C_1AB0C(obj, 0x11, dir | 0xF, 1, 0xF);
    func_80019F0C_1AB0C(obj, 0x12, dir | 0x10, 2, 0);
    func_80019F0C_1AB0C(obj, 0x13, dir | 0x11, 2, 0);
    func_80019F0C_1AB0C(obj, 0xA, dir | 0x12, 1, 0x27);
    func_80019E84_1AA84(obj, 0x15, dir | 0x2E, 0, 0);
    func_80019E84_1AA84(obj, 3, dir | 0x2C, 1, 0);
    func_80019E84_1AA84(obj, 4, dir | 0x2D, 1, 0);
    func_80019E84_1AA84(obj, 0x1E, dir | 0x2F, 2, 0);
    func_80019E84_1AA84(obj, 0x1F, dir | 0x30, 2, 0);
    func_80019E84_1AA84(obj, 0x20, dir | 0x31, 0, 0);
    func_80019E84_1AA84(obj, 0x21, dir | 0x32, 2, 0);
    func_80019E84_1AA84(obj, 0x22, dir | 0x33, 2, 0);
    func_80019E84_1AA84(obj, 0x26, dir | 0x1C, 1, 0);
    func_80019E84_1AA84(obj, 0xD, dir | 0x4F, 1, 0x78);
    func_80019E84_1AA84(obj, 0xE, dir | 0x56, 1, 0x78);
    func_8000C004_CC04(obj);
    func_8000C35C_CF5C(obj, x, y, z);
    func_80029714_2A314(obj->model[0], x, y, z);
    func_8000C024_CC24(obj, 0, 2);
    func_8000C024_CC24(obj, 1, 2);
    obj->func_ptr = func_801038C4_16C804_ShockDropOrRoll;
}

__asm__(".section .rodata");
const u32 D_80106FF0_16FF30_ShockDropOrRoll[2] = { 0x14282828, 0x28282828 };

__asm__(".section .rodata");
const u32 D_80106FF8_16FF38_ShockDropOrRoll[2] = { 0xD32DD32D, 0xD32DD32D };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_ShockDropOrRoll/16B740", func_801044BC_16D3FC_ShockDropOrRoll);

__asm__(".section .rodata");
const u32 D_80107000_16FF40_ShockDropOrRoll[16] = { 0x00320064, 0x00960032, 0x00780032, 0x00640032, 0x00320096, 0x00280096, 0x0028001E, 0x00960032, 0x00280096, 0x0028001E, 0x0028001E, 0x00960028, 0x001E00C8, 0x00140064, 0x00140014, 0x001E00C8 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_ShockDropOrRoll/16B740", func_80104784_16D6C4_ShockDropOrRoll);

/* The solo player's setup: it stands at the crank (model 0x240006 beside it). */
void func_80104B98_16DAD8_ShockDropOrRoll(omObjData* obj, s32 dir, s32 file, u16 player, f32 x, f32 y, f32 z) {
    MgWork* w;

    obj->unk_50 = func_80027154_27D54(sizeof(MgWork), 0x7918);
    func_800B0EF0_B1AF0(obj->unk_50, 0, sizeof(MgWork));
    w = obj->unk_50;
    w->unk_57 = gPlayers[player].port;
    obj->model[0] = LoadFormFile(dir | file, 0xAB9);
    obj->model[1] = LoadFormFile(1, 0xAB9);
    obj->model[2] = LoadFormFile(0x240006, 0xAB9);
    w->unk_59 = player;
    w->unk_52 = 0;
    w->unk_B4 = 1.0f;
    w->unk_D0 = 0xFFFF;
    w->unk_38 = 1000.0f;
    w->unk_50 = 0;
    func_8000BEB0_CAB0(obj, 60.0f);
    func_8000BEBC_CABC(obj, 150.0f);
    func_8000BEC8_CAC8(obj, 20.0f);
    func_8000C024_CC24(obj, 0, 1);
    func_80018CCC_198CC(obj, 0, dir);
    func_80018CCC_198CC(obj, 0xD, dir | 0x4F);
    func_80018CCC_198CC(obj, 0xE, dir | 0x56);
    func_80018CCC_198CC(obj, 0x26, dir | 0x80);
    func_8000C35C_CF5C(obj, x, y, z);
    func_80029714_2A314(obj->model[0], x, y, z);
    func_8000C36C_CF6C(obj, 0.0f, 180.0f, 0.0f);
    func_80029714_2A314(obj->model[1], x, y, z);
    func_80029714_2A314(obj->model[2], x, y, z);
    func_80029B80_2A780(obj->model[0], obj->motion[0x26]);
    func_80029E80_2AA80(obj->model[0], 1, 1);
    func_80029E80_2AA80(obj->model[2], 1, 1);
    func_80029C74_2A874(obj->model[0], 30.0f);
    func_80029C74_2A874(obj->model[2], 30.0f);
    obj->func_ptr = func_80104784_16D6C4_ShockDropOrRoll;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_ShockDropOrRoll/16B740", func_80104E24_16DD64_ShockDropOrRoll);

__asm__(".section .rodata");
const u32 D_80107078_16FFB8_ShockDropOrRoll[21] = { 0x447A0000, 0x447A0000, 0x447A0000, 0x43A48000, 0x43A48000, 0x43A48000, 0xC30D0000, 0xC2B40000, 0xC2480000, 0x00000000, 0x00000000, 0x00000000, 0xC4148000, 0xC4584000, 0xC4424000, 0x440E8000, 0x440E8000, 0x440E8000, 0xC4124000, 0x43700000, 0x4453C000 };

__asm__(".section .rodata");
const u32 D_801070CC_17000C_ShockDropOrRoll[2] = { 0x02000102, 0x00010000 };

__asm__(".section .rodata");
const u32 D_801070D4_170014_ShockDropOrRoll[6] = { 0x00000000, 0x42700000, 0x42B40000, 0x42F00000, 0x43340000, 0x43520000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_14_ShockDropOrRoll/16B740", func_80105920_16E860_ShockDropOrRoll);

__asm__(".section .rodata");
const u32 D_80107104_170044_ShockDropOrRoll[11] = { 0xC2040000, 0x432E0000, 0x43A08000, 0xC2BA0000, 0x00000000, 0xC4A4A000, 0x44848000, 0xC2540000, 0x00000000, 0x00000000, 0x00000000 };
