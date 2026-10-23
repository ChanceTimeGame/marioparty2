#include "common.h"
#include "process.h"

/* Pause-menu start (MP1 src/72D90.c GamePauseStart); the rest of the unit has no exact reference. */

extern Process* D_800FA6E0_FB2E0;

void omPrcSetStatBit(Process* process, s32 value);
void func_80072874_73474(void);
s32 func_80072E58_73A58(s16 arg0, s16 arg1);

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

/* Per-minigame pause-screen messages (minigame number - 1); str2 -1: one window only */
typedef struct MgPauseMes {
    /* 0x00 */ s16 str1;
    /* 0x02 */ s16 str2;
} MgPauseMes;

/* .data (0xCDC50-0xCDD80) */
MgPauseMes D_800CD050_CDC50[76] = {
    { 0x1C1, -1 }, { 0x1C4, -1 }, { 0x1C7, -1 }, { 0x1CA, -1 }, { 0x1CD, -1 }, { 0x1D0, -1 },
    { 0x18F, -1 }, { 0x192, -1 }, { 0x195, -1 }, { 0x198, -1 }, { 0x19B, -1 }, { 0x19E, -1 },
    { 0x1A1, -1 }, { 0x1A4, -1 }, { 0x0FE, 255 }, { 0x102, 259 }, { 0x106, 263 }, { 0x10A, -1 },
    { 0x10D, 270 }, { 0x111, -1 }, { 0x114, 277 }, { 0x118, 281 }, { 0x11C, -1 }, { 0x11F, 288 },
    { 0x1AA, 427 }, { 0x123, -1 }, { 0x126, -1 }, { 0x129, -1 }, { 0x12C, -1 }, { 0x12F, -1 },
    { 0x132, 307 }, { 0x136, -1 }, { 0x139, -1 }, { 0x13C, -1 }, { 0x13F, -1 }, { 0x1AE, -1 },
    { 0x14C, -1 }, { 0x14F, -1 }, { 0x152, -1 }, { 0x155, -1 }, { 0x158, -1 }, { 0x15B, -1 },
    { 0x160, -1 }, { 0x163, -1 }, { 0x166, -1 }, { 0x169, -1 }, { 0x16E, -1 }, { 0x171, -1 },
    { 0x174, -1 }, { 0x177, -1 }, { 0x17A, -1 }, { 0x17D, -1 }, { 0x180, -1 }, { 0x183, -1 },
    { 0x186, -1 }, { 0x1B1, -1 }, { 0x1DD, -1 }, { 0x1DD, -1 }, { 0x1DD, -1 }, { 0x1DD, -1 },
    { 0x1DD, -1 }, { 0x1DD, -1 }, { 0x1DD, -1 }, { 0x1DD, -1 }, { 0x1A7, -1 }, { 0x142, -1 },
    { 0x145, 326 }, { 0x149, -1 }, { 0x189, -1 }, { 0x18C, -1 }, { 0x1B4, 437 }, { 0x1B8, -1 },
    { -1, -1 }, { 0x000, 0 }, { 0x000, 0 }, { 0x000, 0 },
};
extern u8 D_800F851A_F911A;
extern s16 D_800FC9B8_FD5B8;  /* pause window 1's sprite */
extern s16 D_8010270A_10330A; /* pause window 2's sprite, or -1 */
extern s16 D_8010276A_10336A; /* PAUSE sprite */
extern s16 D_800FCE82_FDA82;  /* its animation */
extern u8 D_800FDEAE_FEAAE;
s16 func_800896A0_8A2A0(s16 winId, s16 idx);
void func_80089308_89F08(s16, s32, s8);
void func_800890CC_89CCC(s16, s32, s32, s32);
void func_8008D5D8_8E1D8(s16 winId);
void func_8008D6F0_8E2F0(s16 winId);
s16 SprCreate(s32 num, s32 attr);
s16 SprAnimRead(void*);
void SprAnimSet(s16 group, s16 member, s16 arg2, u16 arg3);
void SprPosSet(s16 grpIdx, s16 idx, s16 x, s16 y);
void SprAttrReset(s16 grpIdx, s16 idx, s32 flag);
void SprKill(s16 idx);
void SprAnimKill(s16 animIdx);
void HuPrcSleep(s32 time);
void HuPrcVSleep(void);
void* DataRead(s32 dirAndFile);
void DataClose(void* data);
u16 func_80078EA8_79AA8(void);
s32 omDelPrcObj(void*);
s32 PlaySound(s32);

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

/* MP1 func_8007B52C: the pause process. Shows the current minigame's instruction windows (a
   second window for two-team or 1-vs-3 minigames, filled with the players' names by group) and
   the PAUSE sprite, then idles until GamePauseEnd kills it. */
void func_80072874_73474(void) {
    s16 mg;
    s16 y;
    s16 win1;
    s16 win2;
    s16 i;
    s8 n1;
    s8 n2;
    void* data;

    HuPrcSleep(2);
    D_800F851A_F911A = 1;
    mg = GwSystem.chosenMinigameIndex - 1;
    y = D_800CD050_CDC50[mg].str2 == -1 ? 110 : 70;
    win1 = func_80072E58_73A58(60, y);
    D_800FC9B8_FD5B8 = func_800896A0_8A2A0(win1, D_800F920C_F9E0C[win1].unk_274);
    if (D_800CD050_CDC50[mg].str2 != -1) {
        win2 = func_80072E58_73A58(60, y + 70);
        D_8010270A_10330A = func_800896A0_8A2A0(win2, D_800F920C_F9E0C[win2].unk_274);
        n1 = 0;
        if (mg == 0x1E || mg == 0x42) {
            n2 = 0;
            for (i = 0; i < 4; i++) {
                switch (gPlayers[i].group) {
                    case 0:
                    case 2:
                        func_80089308_89F08(win1, gPlayers[i].character + 0x1BA, n1++);
                        break;
                    default:
                        func_80089308_89F08(win2, gPlayers[i].character + 0x1BA, n2++);
                        break;
                }
            }
        } else {
            n2 = 0;
            for (i = 0; i < 4; i++) {
                if (gPlayers[i].group == 0) {
                    func_80089308_89F08(win1, gPlayers[i].character + 0x1BA, n1++);
                } else {
                    func_80089308_89F08(win2, gPlayers[i].character + 0x1BA, n2++);
                }
            }
        }
        func_800890CC_89CCC(win2, D_800CD050_CDC50[mg].str2, -1, -1);
    } else {
        D_8010270A_10330A = -1;
        win2 = -1;
    }
    func_800890CC_89CCC(win1, D_800CD050_CDC50[mg].str1, -1, -1);
    data = DataRead(0xB00D8);
    D_800FCE82_FDA82 = SprAnimRead(data);
    D_8010276A_10336A = SprCreate(1, 5);
    DataClose(data);
    SprAnimSet(D_8010276A_10336A, 0, D_800FCE82_FDA82, 0);
    SprAttrSet(D_8010276A_10336A, 0, 0x1001000);
    SprPosSet(D_8010276A_10336A, 0, 0xA0, y - 20);
    SprPrioSet(D_8010276A_10336A, 0, 1);
    func_8008D5D8_8E1D8(win1);
    SprAttrSet(D_800F920C_F9E0C[win1].unk_6C, D_800F920C_F9E0C[win1].unk_274, 0x8000);
    SprAttrSet(D_8010276A_10336A, 0, 0x8000);
    if (win2 != -1) {
        func_8008D5D8_8E1D8(win2);
        SprAttrSet(D_800F920C_F9E0C[win2].unk_6C, D_800F920C_F9E0C[win2].unk_274, 0x8000);
    }
    HuPrcVSleep();
    PlaySound(6);
    func_8008D6F0_8E2F0(win1);
    SprAttrReset(D_800F920C_F9E0C[win1].unk_6C, D_800F920C_F9E0C[win1].unk_274, 0x8000);
    SprAttrReset(D_8010276A_10336A, 0, 0x8000);
    if (win2 != -1) {
        func_8008D6F0_8E2F0(win2);
        SprAttrReset(D_800F920C_F9E0C[win2].unk_6C, D_800F920C_F9E0C[win2].unk_274, 0x8000);
    }
    D_800FDEAE_FEAAE = 1;
    while (func_80078EA8_79AA8() != 0) {
        HuPrcVSleep();
    }
    while (TRUE) {
        HuPrcVSleep();
    }
}

/* MP1 GamePauseEnd */
void func_80072E20_73A20(void) {
    SprKill(D_8010276A_10336A);
    SprAnimKill(D_800FCE82_FDA82);
    omDelPrcObj(D_800FA6E0_FB2E0);
}

s32 func_80072E58_73A58(s16 arg0, s16 arg1) {
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
