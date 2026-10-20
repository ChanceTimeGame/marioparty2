#include "common.h"
#include "process.h"

/* Pause-menu start (MP1 src/72D90.c GamePauseStart); the rest of the unit has no exact reference. */

extern Process* D_800FA6E0_FB2E0;

void omPrcSetStatBit(Process* process, s32 value);
void func_80072874_73474(void);

typedef struct TextWindow {
    /* 0x000 */ char pad0[0x29];
    /* 0x029 */ u8 unk_29;
    /* 0x02A */ u8 unk_2A;
    /* 0x02B */ char pad2B[0x41];
    /* 0x06C */ s16 unk_6C;
    /* 0x06E */ char pad6E[0x206];
    /* 0x274 */ s16 unk_274;
    /* 0x276 */ char pad276[6];
} TextWindow; // size 0x27C (MP3 layout; 84FF0)

extern TextWindow* D_800F920C_F9E0C;

s16 func_800888A8_894A8(s16, s16, s16, s16, s32, s16);
void func_80089A7C_8A67C(s16, s16);
void func_80089A48_8A648(s16, s16);
void func_80089B2C_8A72C(s16, s16);
s16 func_80089404_8A004(s16 win_id, u32 spriteMainFsPair, s16 arg2, s16 arg3, u16 arg4);
void SprPrioSet(s16 group, s16 member, u16 prio);
void SprScaleSet(s16 group, s16 member, f32 x, f32 y);
void SprAttrSet(s16 group, s16 member, s32 attr);
void func_80082488_83088(s16 grpIdx, s16 idx, u16 a);
void func_80082450_83050(s16 grpIdx, s32 idx, s32 r, s32 g, u8 b);

void func_800727F0_733F0(void) {
    s32 i;

    GW_PLAYER* player;

    for (i = 0; i < 4; i++) {
        player = &gPlayers[i];
        player->coins_mg = 0;
        player->coins_mg_bonus = 0;
    }
}

void GamePauseStart(void) {
    D_800FA6E0_FB2E0 = omAddPrcObj(func_80072874_73474, 0x3FFF, 0x800, 0);
    omPrcSetStatBit(D_800FA6E0_FB2E0, 0xA0);
}

INCLUDE_ASM("asm/nonmatchings/733F0", func_80072874_73474);

INCLUDE_ASM("asm/nonmatchings/733F0", func_80072E20_73A20);

s16 func_80072E58_73A58(s16 arg0, s16 arg1) {
    TextWindow* temp_s0;
    s16 temp_v0;
    s16 temp_v0_2;

    temp_v0 = func_800888A8_894A8(arg0, arg1, 200, 60, 0, 8);
    func_80089A7C_8A67C(temp_v0, 0);

    temp_s0 = &D_800F920C_F9E0C[temp_v0];
    temp_s0->unk_29 = 0;
    temp_s0->unk_2A = 1;

    func_80089A48_8A648(temp_v0, 0);
    func_80089B2C_8A72C(temp_v0, 0);

    temp_s0->unk_274 = temp_v0_2 = func_80089404_8A004(temp_v0, 0xB00D7, 0, 0, 0);

    SprPrioSet(temp_s0->unk_6C, temp_v0_2, 1);
    SprScaleSet(temp_s0->unk_6C, temp_v0_2, 3.325f, 3.75f);
    SprAttrSet(temp_s0->unk_6C, temp_v0_2, 0x01001008);
    func_80082488_83088(temp_s0->unk_6C, temp_v0_2, 192);
    func_80082450_83050(temp_s0->unk_6C, temp_v0_2, 16, 16, 64);

    return temp_v0;
}
