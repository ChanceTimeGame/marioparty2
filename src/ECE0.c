#include "common.h"

/* Audio driver. Functions with C come from MP1 src/B980.c (oscillator free list, vibrato depth),
   MP3 src/1140.c (audio command queue) and MP1 ovl_22 (a one-argument wrapper); the rest is asm. */

typedef struct ECE0Osc {
    /* 0x00 */ struct ECE0Osc* next;
} ECE0Osc;

typedef struct {
    /* 0x00 */ s8 cmdType;
    /* 0x01 */ s8 voiceSlot;
    /* 0x04 */ s32 cmdArg;
} AudioCmd; // size 0x8

typedef struct {
    /* 0x00 */ char unk00[0x34];
    /* 0x34 */ s32 unk34;           // write index (wraps at 0x80)
    /* 0x38 */ AudioCmd cmds[0x80];
} UnkAudio;

extern ECE0Osc* D_800D58DC_D64DC;
extern UnkAudio* D_800D58E4_D64E4;

void func_8000EC8C_F88C(s32, s32);
void func_80010E74_11A74(void*, u8);
void func_80014B30_15730(void*, u8);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000E0E0_ECE0);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000E1F0_EDF0);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000E38C_EF8C);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000E3FC_EFFC);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000E930_F530);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000E9DC_F5DC);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000E9E8_F5E8);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000EA34_F634);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000EA54_F654);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000EA60_F660);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000EA68_F668);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000EA88_F688);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000EB1C_F71C);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000EB3C_F73C);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000EC10_F810);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000EC64_F864);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000EC8C_F88C);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000EC94_F894);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000ECB8_F8B8);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000EDA4_F9A4);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000EE1C_FA1C);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000EEA0_FAA0);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000EF60_FB60);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000F634_10234);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000F69C_1029C);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000F744_10344);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000F878_10478);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000F968_10568);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000FE48_10A48);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8000FEFC_10AFC);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80010070_10C70);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_800100FC_10CFC);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80010108_10D08);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80010114_10D14);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80010570_11170);

void func_80010DFC_119FC(ECE0Osc* osc) {
    osc->next = D_800D58DC_D64DC;
    D_800D58DC_D64DC = osc;
}

f32 func_80010E14_11A14(u8 depth) {
    f32 x = 1.03099303;
    f32 cents = 1.0f;

    while (depth) {
        if (depth & 1) {
            cents *= x;
        }
        x *= x;
        depth >>= 1;
    }
    return cents;
}

void func_80010E58_11A58(void* obj) {
    func_80010E74_11A74(obj, 0);
}

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80010E74_11A74);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80011018_11C18);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80011064_11C64);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8001108C_11C8C);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_800110D8_11CD8);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80011100_11D00);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80011128_11D28);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8001122C_11E2C);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80011308_11F08);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80011354_11F54);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8001138C_11F8C);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80011430_12030);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_800114E8_120E8);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80011568_12168);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_800115B4_121B4);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_800116B4_122B4);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80011738_12338);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_800117FC_123FC);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80011938_12538);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80011A28_12628);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80011AF8_126F8);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8001240C_1300C);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8001248C_1308C);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_800124FC_130FC);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80012548_13148);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80012800_13400);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_800132A0_13EA0);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_800132EC_13EEC);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80013648_14248);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80013A80_14680);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80013BE4_147E4);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80013D44_14944);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80013FD0_14BD0);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_800142C4_14EC4);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8001434C_14F4C);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80014520_15120);

void func_80014768_15368(s32 voiceSlot, s32 cmdType, s32 cmdArg) {
    u32 temp_s3;
    AudioCmd *cmd;

    temp_s3 = osSetIntMask(1);
    cmd = &D_800D58E4_D64E4->cmds[D_800D58E4_D64E4->unk34];
    cmd->cmdType = cmdType;
    cmd->voiceSlot = voiceSlot;
    cmd->cmdArg = cmdArg;
    if (++D_800D58E4_D64E4->unk34 >= 128) {
        func_8000EC8C_F88C(0, 0x200);
        D_800D58E4_D64E4->unk34 = 0;
    }
    osSetIntMask(temp_s3);
}

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80014814_15414);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_800148C4_154C4);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80014A60_15660);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80014AFC_156FC);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80014B08_15708);

void func_80014B14_15714(void* obj) {
    func_80014B30_15730(obj, 0);
}

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80014B30_15730);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80014D34_15934);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80015148_15D48);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80015334_15F34);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8001535C_15F5C);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80015388_15F88);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_800153CC_15FCC);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_8001545C_1605C);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_800154A0_160A0);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_800154F0_160F0);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80015580_16180);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_800155B8_161B8);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80015664_16264);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80015710_16310);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_800157BC_163BC);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80015868_16468);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80015950_16550);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80015988_16588);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_800159B4_165B4);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80015A64_16664);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80015AAC_166AC);

INCLUDE_ASM("asm/nonmatchings/ECE0", func_80015B9C_1679C);
