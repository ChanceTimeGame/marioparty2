#include "common.h"
#include "game/data.h"
#include "game/malloc.h"

/* Esprite slots. Same code as Mario Party 3's src/esprite.c (and MP1 src/engine/esprite.c);
   names follow MP3. */

typedef struct {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s16 unk04; // sprite group
    /* 0x06 */ s16 unk06;
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA; // x center
    /* 0x0C */ s16 unkC; // y center
    /* 0x0E */ s16 unkE;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ char unk18[4];
    /* 0x1C */ s16 unk1C;
    /* 0x1E */ s16 unk1E;
    /* 0x20 */ s16 unk20;
    /* 0x22 */ char unk22[2];
} EspriteSlot; // Size 0x24

extern u16 D_800F608C_F6C8C;
extern u16 D_800F8434_F9034;
extern EspriteSlot *D_800F93FC_F9FFC;
extern s16 D_80101332_101F32;

void* func_80027138_27D38(s32 size);
void func_800271D8_27DD8(void* data);
void func_8007F630_80230(void);
void SprKill(s16);
s16 SprCreate(u16 arg0, u16 arg1);
void SprBankSet(s16 group, s16 member, s32 arg2);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void func_8008221C_82E1C(s16 group, s16 member, f32 arg2);
void func_8008225C_82E5C(s16, s16, s32);
void func_800822A8_82EA8(s16, s16, u16, s32);
u8 func_80082314_82F14(s16 group, s16 member);
void SprScaleSet(s16 group, s16 member, f32 x, f32 y);
void SprPrioSet(s16 group, s16 member, u16 prio);
void SprRotSet(s16, s16, f32);
void SprAttrReset(s16 group, s16 member, s32 attr);
void SprAttrSet(s16 group, s16 member, s32 attr);
void func_80082450_83050(s16, s16, u8, u8, u8);
void func_80082488_83088(s16, s16, u16);
s16 SprAnimRead(void *);
void func_80083B9C_8479C(void);

void espInit(void) {
    u16 var_a0;

    func_8007F630_80230();
    D_800F93FC_F9FFC = func_80027138_27D38(0x100 * sizeof(EspriteSlot));
    D_800F608C_F6C8C = 0x100;
    D_800F8434_F9034 = 0;
    for (var_a0 = 0; var_a0 < 0x100; var_a0++) {
        EspriteSlot *temp_v0 = &D_800F93FC_F9FFC[var_a0];

        temp_v0->unk00 = 0;
        temp_v0->unk02 = var_a0 + 1;
        temp_v0->unk1C = 0xFF;
        temp_v0->unk1E = 0xFF;
        temp_v0->unk20 = 0;
    }
    D_80101332_101F32 = 0;
}

s16 func_8001A2F8_1AEF8(s32 arg0) {
    void *temp_v0;
    s16 temp_s0;

    temp_v0 = DataRead(arg0);
    temp_s0 = SprAnimRead(temp_v0);
    HuMemMemoryFreePerm(temp_v0);
    return temp_s0;
}

INCLUDE_ASM("asm/nonmatchings/1AE60", func_8001A340_1AF40);

void func_8001A4C0_1B0C0() {
    func_80083B9C_8479C();
    func_800271D8_27DD8(D_800F93FC_F9FFC);
    D_800F93FC_F9FFC = NULL;
}

INCLUDE_ASM("asm/nonmatchings/1AE60", espMain);

void espDispOn(u16 arg0) {
    SprAttrReset(D_800F93FC_F9FFC[arg0].unk04, 0, 0x8000);
}

void espDispOff(u16 arg0) {
    SprAttrSet(D_800F93FC_F9FFC[arg0].unk04, 0, 0x8000);
}

void espPosSet(u16 spriteId, s16 x, s16 y) {
    EspriteSlot *sprite;

    sprite = D_800F93FC_F9FFC + spriteId;
    sprite->unkA = x;
    sprite->unkC = y;
}

void func_8001A6BC_1B2BC(u16 spriteId, s16 arg1) {
    EspriteSlot *sprite;

    sprite = D_800F93FC_F9FFC + spriteId;
    sprite->unk1E = arg1;
    sprite->unk1C = arg1;
    func_80082488_83088(sprite->unk04, 0, arg1);
}

void func_8001A708_1B308(u16 arg0, u16 arg1) {
    EspriteSlot *temp = &D_800F93FC_F9FFC[arg0];

    SprAttrSet(temp->unk04, 0, arg1);
}

void func_8001A748_1B348(u16 arg0, u16 arg1) {
    EspriteSlot *temp = &D_800F93FC_F9FFC[arg0];

    SprAttrReset(temp->unk04, 0, arg1);
}

void func_8001A788_1B388(u16 spriteId, s32 arg1) {
    EspriteSlot *sprite;

    sprite = D_800F93FC_F9FFC + spriteId;
    SprPrioSet(sprite->unk04, 0, arg1);
}

void func_8001A7C8_1B3C8(u16 spriteId, f32 arg1) {
    EspriteSlot *sprite;

    sprite = D_800F93FC_F9FFC + spriteId;
    func_8008221C_82E1C(sprite->unk04, 0, arg1);
}

void func_8001A810_1B410(u16 spriteId, s16 arg1) {
    EspriteSlot *sprite;

    sprite = D_800F93FC_F9FFC + spriteId;
    SprBankSet(sprite->unk04, 0, arg1);
}

void func_8001A854_1B454(u16 spriteId, s32 arg1, s32 arg2) {
    EspriteSlot *sprite;

    sprite = D_800F93FC_F9FFC + spriteId;
    func_800822A8_82EA8(sprite->unk04, 0, arg1, (u16)arg2);
}

void func_8001A89C_1B49C(u16 spriteId, s32 arg1) {
    EspriteSlot *sprite;

    sprite = D_800F93FC_F9FFC + spriteId;
    func_8008225C_82E5C(sprite->unk04, 0, (u16)arg1);
}

u8 func_8001A8DC_1B4DC(u16 spriteId) {
    EspriteSlot *sprite;

    sprite = D_800F93FC_F9FFC + spriteId;
    return func_80082314_82F14(sprite->unk04, 0);
}

void func_8001A91C_1B51C(u16 spriteId, f32 x, f32 y) {
    EspriteSlot *sprite;

    sprite = D_800F93FC_F9FFC + spriteId;
    SprScaleSet(sprite->unk04, 0, x, y);
}

void func_8001A96C_1B56C(u16 spriteId, s32 arg1, s32 arg2, s32 arg3) {
    EspriteSlot *sprite;

    sprite = D_800F93FC_F9FFC + spriteId;
    func_80082450_83050(sprite->unk04, 0, arg1, arg2, arg3);
}

void func_8001A9C0_1B5C0(u16 spriteId, f32 arg1) {
    EspriteSlot *sprite;

    sprite = D_800F93FC_F9FFC + spriteId;
    SprRotSet(sprite->unk04, 0, arg1);
}

void func_8001AA08_1B608(u16 spriteId, s16 arg1, s16 arg2, s16 arg3) {
    u16 temp_v0;
    EspriteSlot *sprite;

    sprite = D_800F93FC_F9FFC + spriteId;
    sprite->unk00 |= 2;
    sprite->unk1C = arg1;
    if (arg2 > 0) {
        sprite->unk1E = arg2;
    }
    sprite->unk20 = arg3;
}

void func_8001AA4C_1B64C(u16 spriteId, s16 arg1) {
    u16 temp_v0;
    EspriteSlot *sprite;
    u16 phi_return;

    sprite = D_800F93FC_F9FFC + spriteId;
    sprite->unk00 &= 0xFFFD;
    if (arg1 > 0) {
        sprite->unk1E = arg1;
        sprite->unk1C = arg1;
        func_80082488_83088(sprite->unk04, 0, arg1 & 0xFFFF);
    }
}

s16 func_8001AAAC_1B6AC(s16 arg0, u16 arg1, u16 arg2) {
    EspriteSlot *temp_s0;
    s16 temp_s3;
    s16 temp_v0;

    if (D_800F8434_F9034 == D_800F608C_F6C8C) {
        return -1;
    }
    D_800F8434_F9034++;
    temp_s3 = D_80101332_101F32;
    temp_s0 = &D_800F93FC_F9FFC[temp_s3];
    D_80101332_101F32 = temp_s0->unk02;
    temp_s0->unk04 = temp_v0 = SprCreate(1, 0);
    temp_s0->unk00 |= 1;
    temp_s0->unk06 = arg0;
    temp_s0->unk10 = temp_s0->unk14 = 1.0f;
    func_80082488_83088(temp_v0, 0, 0x100);
    SprAttrReset(temp_v0, 0, 0xFFFF);
    SprAttrSet(temp_v0, 0, 0x1000);
    SprScaleSet(temp_v0, 0, 1.0f, 1.0f);
    func_8008225C_82E5C(temp_v0, 0, arg2);
    SprAnimSet(temp_v0, 0, arg0, arg1);
    SprPrioSet(temp_v0, 0, 10);
    if (arg2 == 0) {
        SprBankSet(temp_v0, 0, 0);
    }
    return temp_s3;
}

void func_8001AC44_1B844(u16 arg0) {
    EspriteSlot *sprite;

    sprite = D_800F93FC_F9FFC + arg0;
    if ((sprite->unk00 & 1) != 0) {
        SprKill(sprite->unk04);
        sprite->unk00 = 0;
        sprite->unk02 = D_80101332_101F32;
        D_80101332_101F32 = arg0;
        D_800F8434_F9034--;
    }
}
