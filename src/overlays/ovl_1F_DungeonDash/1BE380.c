#include "common.h"
#include "ovl_1F.h"

void func_80102800_1BE380_DungeonDash(void) {
    s16 i;
    s16 j;
    s32 slot;

    func_8002D4D0_2E0D0(0x32);
    func_8002F290_2FE90(D_800F9D30_FA930, 0x40);
    func_80020D20_21920(0x20);
    omInitObjMan(0x32, 0);
    func_80079128_79D28();
    D_8010B04C_1C6BCC_DungeonDash = omAddObj(0x7FDA, 0, 0, -1, func_80079FF4_7ABF4);
    omSetStatBit(D_8010B04C_1C6BCC_DungeonDash, 0xA0);
    D_8010B04C_1C6BCC_DungeonDash->work[0] = 2;
    func_80018ED0_19AD0(2);
    func_80018F58_19B58(2);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    ScissorSet(1, 320.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(1, 640.0f, 480.0f, 511.0f, 960.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 70.0f, 80.0f, 8000.0f);
    Hu3DCamSetPerspective(1, 70.0f, 80.0f, 8000.0f);
    D_8010B100_1C6C80_DungeonDash = 0;
    D_8010B102_1C6C82_DungeonDash = 3600;
    D_800F8FD0_F9BD0 = 1;
    D_8010B124_1C6CA4_DungeonDash = _CheckFlag(0xC);
    D_8010B120_1C6CA0_DungeonDash = 0;
    D_8010B134_1C6CB4_DungeonDash = 0;
    D_8010B130_1C6CB0_DungeonDash = 0;
    func_801068E8_1C2468_DungeonDash();
    D_8010B144_1C6CC4_DungeonDash = 0;
    D_8010B138_1C6CB8_DungeonDash = 0;
    for (i = 0; i < 4; i++) {
        D_8010B058_1C6BD8_DungeonDash[i] = 0;
    }
    D_800FA606_FB206 = 0;
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    func_8000C018_CC18(0);
    D_8010B048_1C6BC8_DungeonDash = omAddObj(1, 0, 0, -1, func_80102CF8_1BE878_DungeonDash);
    D_800FC7B0_FD3B0[D_800F8FE0_F9BE0++] = omAddObj(2, 0, 0, -1, func_801071C0_1C2D40_DungeonDash);
    omAddObj(2, 0, 0, -1, func_80102D94_1BE914_DungeonDash);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(3, 10, 60, -1, func_80103100_1BEC80_DungeonDash);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(3, 10, 60, -1, func_80103134_1BECB4_DungeonDash);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(3, 10, 60, -1, func_80103168_1BECE8_DungeonDash);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(3, 10, 60, -1, func_8010319C_1BED1C_DungeonDash);
    for (i = 0; i < 4; i++) {
        D_8010B110_1C6C90_DungeonDash[i] = -1;
    }
    for (i = 0; i < 4; i++) {
        slot = gPlayers[i].group * 2 + (rand8() & 1);
        for (j = 0; j < 4; j++) {
            if (D_8010B110_1C6C90_DungeonDash[j] == slot) {
                slot ^= 1;
            }
        }
        D_8010B110_1C6C90_DungeonDash[i] = slot;
    }
    D_8010B128_1C6CA8_DungeonDash[0] = D_8010B128_1C6CA8_DungeonDash[1] = 0;
    InitFadeIn(0, 0x10);
}

void func_80102CF8_1BE878_DungeonDash(omObjData* obj) {
    obj->func_ptr = func_801036B0_1BF230_DungeonDash;
    func_80106C3C_1C27BC_DungeonDash(0, 269.75f, 0.0f, 500.0f, -4025.0f, 17.25f, 0.0f, 0.0f);
    func_80106C3C_1C27BC_DungeonDash(1, 269.75f, 0.0f, 500.0f, -4025.0f, 17.25f, 0.0f, 0.0f);
}

void func_80102D94_1BE914_DungeonDash(omObjData* obj) {
    u8 files[2];
    s32 anim0;
    s32 anim1;
    s32 i;
    void* data;
    DDTeam* team;

    files[0] = 7;
    files[1] = 6;
    obj->func_ptr = func_801041F0_1BFD70_DungeonDash;
    data = DataRead(0x2F000B);
    anim0 = SprAnimRead(data);
    DataClose(data);
    D_8010B104_1C6C84_DungeonDash = SprCreate(2, 0);
    data = DataRead(0x2F000C);
    anim1 = SprAnimRead(data);
    DataClose(data);
    D_8010B108_1C6C88_DungeonDash = SprCreate(2, 0);
    for (i = 0; i < 2; i++) {
        team = &D_8010B068_1C6BE8_DungeonDash[i];
        team->unk14 = 0;
        team->unk1A = 0;
        team->unk8 = 0;
        team->unkE = func_80018A30_19630(files[i] | 0x2F0000, 0x2D9);
        team->unk10 = func_80027D3C_2893C(team->unkE);
        team->unk12 = func_80018A64_19664(0x2F0004, 0x6D9);
        SprAnimSet((s16)D_8010B104_1C6C84_DungeonDash, i, anim0, 0);
        func_8008225C_82E5C((s16)D_8010B104_1C6C84_DungeonDash, i, 0);
        SprAttrSet((s16)D_8010B104_1C6C84_DungeonDash, i, 0x9800);
        SprAnimSet((s16)D_8010B108_1C6C88_DungeonDash, i, anim1, 0);
        func_8008225C_82E5C((s16)D_8010B108_1C6C88_DungeonDash, i, 0);
        SprAttrSet((s16)D_8010B108_1C6C88_DungeonDash, i, 0x9000);
        func_800824B4_830B4((s16)D_8010B108_1C6C88_DungeonDash, (s16)i, 200, 0, 0, 0x100);
        SprScaleSet((s16)D_8010B108_1C6C88_DungeonDash, i, 1.2f, 1.2f);
    }
    func_80029714_2A314(D_8010B068_1C6BE8_DungeonDash[0].unkE, -250.0f, 0.0f, -625.0f);
    func_80029714_2A314(D_8010B068_1C6BE8_DungeonDash[0].unk10, -310.0f, 0.0f, -625.0f);
    func_80029714_2A314(D_8010B068_1C6BE8_DungeonDash[1].unkE, 310.0f, 0.0f, -625.0f);
    func_80029714_2A314(D_8010B068_1C6BE8_DungeonDash[1].unk10, 250.0f, 0.0f, -625.0f);
    func_800297E8_2A3E8(D_8010B068_1C6BE8_DungeonDash[0].unkE, 1.2f, 1.0f, 1.0f);
    func_800297E8_2A3E8(D_8010B068_1C6BE8_DungeonDash[0].unk10, 1.2f, 1.0f, 1.0f);
    func_800297E8_2A3E8(D_8010B068_1C6BE8_DungeonDash[1].unkE, 1.2f, 1.0f, 1.0f);
    func_800297E8_2A3E8(D_8010B068_1C6BE8_DungeonDash[1].unk10, 1.2f, 1.0f, 1.0f);
    func_80029714_2A314(D_8010B068_1C6BE8_DungeonDash[0].unk12, -280.0f, 16.0f, -700.0f);
    func_8002979C_2A39C(D_8010B068_1C6BE8_DungeonDash[0].unk12, 0.0f, 180.0f, 0.0f);
    func_80029714_2A314(D_8010B068_1C6BE8_DungeonDash[1].unk12, 280.0f, 16.0f, -700.0f);
    func_8002979C_2A39C(D_8010B068_1C6BE8_DungeonDash[1].unk12, 0.0f, 180.0f, 0.0f);
}

void func_801030CC_1BEC4C_DungeonDash(omObjData* obj) {
    if (func_8008F618_90218() == 0) {
        func_801060DC_1C1C5C_DungeonDash();
        omOvlReturnEx(1);
    }
}

void func_80103100_1BEC80_DungeonDash(omObjData* obj) {
    func_801031D0_1BED50_DungeonDash(obj, 0);
    func_80103354_1BEED4_DungeonDash(obj, 0);
}

void func_80103134_1BECB4_DungeonDash(omObjData* obj) {
    func_801031D0_1BED50_DungeonDash(obj, 1);
    func_80103354_1BEED4_DungeonDash(obj, 1);
}

void func_80103168_1BECE8_DungeonDash(omObjData* obj) {
    func_801031D0_1BED50_DungeonDash(obj, 2);
    func_80103354_1BEED4_DungeonDash(obj, 2);
}

void func_8010319C_1BED1C_DungeonDash(omObjData* obj) {
    func_801031D0_1BED50_DungeonDash(obj, 3);
    func_80103354_1BEED4_DungeonDash(obj, 3);
}

/* Puts the player into its team slot (D_8010B110) and at its start position. */
void func_801031D0_1BED50_DungeonDash(omObjData* obj, s32 player) {
    s32 member;
    s32 t;
    DDTeam* team;

    member = D_8010B110_1C6C90_DungeonDash[player];
    t = member >> 1;
    member &= 1;
    team = &D_8010B068_1C6BE8_DungeonDash[t];
    func_801060F8_1C1C78_DungeonDash(obj, team);
    team->obj[member] = obj;
    D_8010B068_1C6BE8_DungeonDash[t].player[member] = player;
    D_8010B068_1C6BE8_DungeonDash[t].unkB[member] = (u8)D_800CD438_CE038[gPlayers[player].character].unk_00;
    switch (D_8010B110_1C6C90_DungeonDash[player]) {
        case 0:
            func_8000C35C_CF5C(obj, -280.0f, 0.0f, -700.0f);
            break;
        case 1:
            func_8000C35C_CF5C(obj, -280.0f, 0.0f, -550.0f);
            break;
        case 2:
            func_8000C35C_CF5C(obj, 280.0f, 0.0f, -700.0f);
            break;
        case 3:
            func_8000C35C_CF5C(obj, 280.0f, 0.0f, -550.0f);
            break;
    }
}

__asm__(".section .rodata");
const u32 D_8010ABE0_1C6760_DungeonDash[4] = { 0x00000055, 0x00000056, 0x00000057, 0x00000000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80103354_1BEED4_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_801036B0_1BF230_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80104190_1BFD10_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_801041F0_1BFD70_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80105464_1C0FE4_DungeonDash);

__asm__(".section .rodata");
const u32 D_8010AD38_1C68B8_DungeonDash[4] = { 0 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80105618_1C1198_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80105E50_1C19D0_DungeonDash);

void func_801060DC_1C1C5C_DungeonDash(void) {
    func_80107350_1C2ED0_DungeonDash();
}

/* The player object keeps its team in work[0..3], the pointer big-endian (host hazard: a pointer in
   a 32-bit slot; MP1's port keeps the team index there instead). */
void func_801060F8_1C1C78_DungeonDash(omObjData* obj, DDTeam* team) {
    obj->work[0] = (u32)team >> 24;
    obj->work[1] = (u32)team >> 16;
    obj->work[2] = (u32)team >> 8;
    obj->work[3] = (u32)team;
}

DDTeam* func_80106118_1C1C98_DungeonDash(omObjData* obj) {
    return (DDTeam*)((obj->work[0] << 24) | (obj->work[1] << 16) | (obj->work[2] << 8) | obj->work[3]);
}

void func_80106144_1C1CC4_DungeonDash(omObjData* obj, s32 motion, f32 speed) {
    HmfModel* m;

    func_80019B9C_1A79C(obj, (u16)motion);
    m = &D_800FC834_FD434[obj->model[0]];
    m->unk44 = speed;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_801061A0_1C1D20_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_8010676C_1C22EC_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80106810_1C2390_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_801068E8_1C2468_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80106A28_1C25A8_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80106B6C_1C26EC_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80106C3C_1C27BC_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80106D2C_1C28AC_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80106E08_1C2988_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80106EC4_1C2A44_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80106F80_1C2B00_DungeonDash);
