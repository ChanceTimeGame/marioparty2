#include "common.h"
#include "game/pad.h"

/* Audio and controller-copy wrappers (MP3 src/audio.c, MP1 src/objmain.c, src/388E0.c). The
   references' names are anonymous, so MP2's are kept. */

typedef struct UnkAudStruct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ char unk04[4];
    /* 0x08 */ s32 unk08;
    /* 0x0C */ char unk0C[0x24];
} UnkAudStruct; // size 0x30

extern s16 D_800CD524_CE124;
extern u16 D_800CD526_CE126;
extern s16 D_800FA188_FAD88;
extern s8 ContStkX[4];
extern s8 ContStkY[4];
extern s8 D_801026F8_1032F8[4];
extern s8 D_800FD3E4_FDFE4[4];
extern u16 D_800F92D4_F9ED4[4];
extern u16 D_800FA19C_FAD9C[4];
extern u16 D_800F851C_F911C[4];
extern u16 D_800FD410_FE010[4];

void func_80011128_11D28(s16);
void func_80011354_11F54(s8);
s32 func_80014B30_15730(s16, UnkAudStruct*);

s32 func_80011018_11C18(s16);
void func_80088604_89204(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
extern u16 D_800CD522_CE122;
extern s16 D_800E2140_E2D40[6];

/* Per-slot sound fades (7AA60.c's SndFadeWork; D_801026F0_1032F0->unk_50) */
typedef struct SndFadeWork {
    /* 0x00 */ f32* vol;
    /* 0x04 */ f32* volStep;
    /* 0x08 */ f32* vol2;
    /* 0x0C */ f32* vol2Step;
    /* 0x10 */ u8* flags;
} SndFadeWork; /* size 0x14 */

/* The sound configuration (ECE0.c SndConfig): bank ROM addresses and the effect record */
typedef struct SndConfigView {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ void* unk08; /* music bank ROM address */
    /* 0x0C */ void* unk0C; /* sound bank ROM address */
    /* 0x10 */ char unk10[0x18];
    /* 0x28 */ s32 unk28;   /* effect record */
    /* 0x2C */ char unk2C[0x40];
} SndConfigView; /* size 0x6C */

extern u16 D_800CD520_CE120;
extern s16 D_800CD528_CE128;
extern s16 D_800CD52A_CE12A;
extern s16 D_800CD52C_CE12C;
extern s16 D_800CD52E_CE12E;
extern s16 D_800CD530_CE130;
extern s16 D_800FA660_FB260[];
extern omObjData* D_801026F0_1032F0;
extern SndConfigView D_80101100_101D00;
extern u8 D_01750450[];
extern u8 D_0190A090[];
extern u8 D_01CBF410[];
/* ECE0.c defines it void, but it falls through with func_80010E74_11A74's result, which
   PlayMusic returns (host: ECE0's definition should return it) */
s32 func_80010E58_11A58(s32 id);
void func_8001122C_11E2C(s32 player, s32 vol);
void func_8001138C_11F8C(s32 player, s32 bpm);
s32 func_80014B14_15714(s32 defNo);
void func_80015580_16180(s32 arg);
s32 func_80015388_15F88(s32);
void func_800155B8_161B8(s32 slot, s32 vol);
void func_8000E9E8_F5E8(SndConfigView* out);
s32 func_8000E3FC_EFFC(SndConfigView* cfg);
void func_8000EA88_F688(s32 mono);
s32 func_8007975C_7A35C(s16 arg0, s16 arg1);
void func_800799A4_7A5A4(s16 ch, s16 frames);

/* MP1 func_80060128: start music id unless it is already the current one */
s16 PlayMusic(s16 id) {
    if (D_800CD520_CE120 == 0) {
        return 0;
    }
    if (D_800CD524_CE124 == id) {
        return 0;
    }
    func_80011128_11D28(D_800FA188_FAD88);
    D_800CD524_CE124 = id;
    D_800CD526_CE126 = (D_800CD526_CE126 | 2) & ~9;
    return D_800FA188_FAD88 = func_80010E58_11A58(id);
}

/* Start music id on another player, without making it the current music. */
s16 func_80079428_7A028(s16 id) {
    if (D_800CD520_CE120 == 0) {
        return 0;
    }
    return func_80010E58_11A58(id);
}

void func_80079464_7A064(void) {
    D_800CD524_CE124 = -1;
    func_80011128_11D28(D_800FA188_FAD88);
    D_800CD526_CE126 &= ~(2 | 8);
    D_800CD526_CE126 |= 1;
}

void func_800794A8_7A0A8(s32 speed) {
    D_800CD524_CE124 = -1;
    func_800114E8_120E8(D_800FA188_FAD88, (s16)speed);
    D_800CD526_CE126 |= 8;
}

/* MP3 func_8004A9DC_4B5DC: current music volume */
void func_800794F0_7A0F0(s8 vol) {
    func_8001122C_11E2C(D_800FA188_FAD88, vol);
}

void func_80079518_7A118(s8 arg0) {
    func_80011354_11F54(arg0);
    D_800CD526_CE126 &= ~8;
}

/* MP3 func_8004AA38_4B638: current music tempo */
void func_8007954C_7A14C(s16 bpm) {
    func_8001138C_11F8C(D_800FA188_FAD88, bpm);
}

INCLUDE_ASM("asm/nonmatchings/79F90", func_80079574_7A174);

s32 PlaySound(s32 id) {
    if (D_800CD522_CE122 == 0) {
        return 0;
    }
    return (s16)func_80014B14_15714((s16)id);
}

void func_800795D8_7A1D8(s16 index, s8 val) {
    D_800FA660_FB260[index] = val;
    func_800155B8_161B8(index, val);
}

/* MP3 func_8004AB0C_4B70C: fade out every sound slot over time frames */
void func_80079614_7A214(s16 time) {
    s32 i;

    if (D_801026F0_1032F0 != NULL) {
        for (i = 0; i < D_800CD530_CE130; i++) {
            func_800799A4_7A5A4(i, time);
        }
    }
}

/* MP3 func_8004AB7C_4B77C: every sound slot's volume */
void func_80079684_7A284(s8 vol) {
    s32 i;

    for (i = 0; i < D_800CD530_CE130; i++) {
        D_800FA660_FB260[i] = vol;
    }
    func_80015580_16180(vol);
}

void func_800796F0_7A2F0(s16 arg0, s16 arg1) {
    func_80015664_16264(arg0, arg1);
}

/* MP1 func_80060468: play sound id + offset */
s16 func_80079718_7A318(s16 id, u8 offset) {
    if (D_800CD522_CE122 == 0) {
        return 0;
    }
    return func_80014B14_15714(id + offset);
}

s32 func_8007975C_7A35C(s16 arg0, s16 arg1) {
    UnkAudStruct sp10;

    sp10.unk00 = 0x200;
    sp10.unk08 = arg1 + 1;
    return func_80014B30_15730(arg0, &sp10);
}

s16 func_80079798_7A398(s16 arg0, s16 arg1) {
    if (D_800CD522_CE122 == 0) {
        return 0;
    }
    return func_8007975C_7A35C(arg0, arg1);
}

/* MP1 func_80060618: play player's character voice id + character */
s16 func_800797DC_7A3DC(s32 id, s16 player) {
    s16 sound;

    if (D_800CD522_CE122 == 0) {
        return 0;
    }
    sound = id + gPlayers[player].character;
    return func_8007975C_7A35C(sound, player);
}

void func_80079848_7A448(s16 arg0) {
    func_80015868_16468(arg0);
}

void func_80079868_7A468(void) {
    func_80015868_16468(-1);
}

INCLUDE_ASM("asm/nonmatchings/79F90", func_80079884_7A484);

void func_800798D4_7A4D4(s16 arg0) {
    func_80015710_16310(-1, arg0);
}

void func_800798F8_7A4F8(s16 arg0, s16 arg1) {
    func_80015710_16310(arg0, arg1);
}

void func_80079920_7A520(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        D_800E2140_E2D40[i] = -1;
    }
    switch (func_80011018_11C18(D_800FA188_FAD88)) {
    case 0:
        D_800CD526_CE126 = (D_800CD526_CE126 | 1) & ~0xA;
        break;
    case 1:
        break;
    case 2:
        break;
    }
}

/* MP1 func_80060BC8: fade sound slot ch out over frames, then stop it */
void func_800799A4_7A5A4(s16 ch, s16 frames) {
    SndFadeWork* work;

    if (D_801026F0_1032F0 != NULL && func_80015388_15F88(ch) != 0) {
        work = D_801026F0_1032F0->unk_50;
        work->flags[ch] |= 1;
        work->vol[ch] = D_800FA660_FB260[ch];
        work->volStep[ch] = (f32)D_800FA660_FB260[ch] / frames;
    }
}

/* MP1 func_80060C84: fade every slot to silence over frames (pause) */
void func_80079A70_7A670(s16 frames) {
    SndFadeWork* work;
    s32 i;

    if (D_801026F0_1032F0 != NULL) {
        work = D_801026F0_1032F0->unk_50;
        for (i = 0; i < D_800CD530_CE130; i++) {
            work->flags[i] |= 6;
            if (work->flags[i] & 1) {
                work->vol2[i] = work->vol[i];
                work->vol2Step[i] = work->vol[i] / frames;
            } else {
                work->vol2[i] = D_800FA660_FB260[i];
                work->vol2Step[i] = (f32)D_800FA660_FB260[i] / frames;
            }
        }
    }
}

/* MP1 func_80060D4C: end the pause fade, restore every slot's volume */
void func_80079B88_7A788(void) {
    SndFadeWork* work;
    s32 i;
    s16 vol;

    if (D_801026F0_1032F0 != NULL) {
        work = D_801026F0_1032F0->unk_50;
        for (i = 0; i < D_800CD530_CE130; i++) {
            work->flags[i] &= ~6;
            if (work->flags[i] & 1) {
                vol = work->vol[i];
            } else {
                vol = D_800FA660_FB260[i];
            }
            func_800155B8_161B8(i, vol);
        }
    }
}

void func_80079C60_7A860(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_801026F8_1032F8[i] = ContStkX[i];
        D_800FD3E4_FDFE4[i] = ContStkY[i];
        D_800F92D4_F9ED4[i] = ContBtn[i];
        D_800FA19C_FAD9C[i] = ContBtnTrg[i];
        D_800F851C_F911C[i] = D_800FD410_FE010[i];
    }
}

void omVibrate(s16 player, s16 arg1, s16 arg2, s16 arg3) {
    if (!(gPlayers[player].flags & 1)) {
        func_80088604_89204(gPlayers[player].port, arg1, arg2, arg3);
    }
}

/* MP1 func_80060AB4: the requested sound mode/bank differs from the loaded one */
// bnel where retail has bne before the shared `li v0,1` (masked 1)
#ifdef NON_MATCHING
u16 func_80079D7C_7A97C(void) {
    if (D_800CD528_CE128 != D_800CD52A_CE12A) {
        return 1;
    }
    return D_800CD52C_CE12C != D_800CD52E_CE12E;
}
#else
INCLUDE_ASM("asm/nonmatchings/79F90", func_80079D7C_7A97C);
#endif

/* MP1 func_80060AF0: reload the sound banks for D_800CD52C_CE12C, then the output mode */
// retail addresses unk28 and the else branch's unk08/unk0C through their own symbols
// (D_80101128_101D28, D_80101108_101D08: splat labels inside D_80101100_101D00); same stores
#ifdef NON_MATCHING
void func_80079DB4_7A9B4(void) {
    func_8000E9E8_F5E8(&D_80101100_101D00);
    D_80101100_101D00.unk28 = 1;
    if (D_800CD52C_CE12C == 0) {
        D_80101100_101D00.unk08 = D_01750450;
        D_80101100_101D00.unk0C = D_0190A090;
    } else {
        D_80101100_101D00.unk08 = D_01750450;
        D_80101100_101D00.unk0C = D_01CBF410;
    }
    func_8000E3FC_EFFC(&D_80101100_101D00);
    if (_CheckFlag(2) != 0) {
        func_8000EA88_F688(0);
    } else {
        func_8000EA88_F688(1);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/79F90", func_80079DB4_7A9B4);
#endif
