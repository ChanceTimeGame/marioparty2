#include "ovl_55.h"

/* Board 5's scene setup: the players' models, the host (model 0x7B) and its stand-in. */
void func_8010A4F0_3693E0_name_55(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        gPlayers[i].unk_24 = func_80043510_44110((u8)(gPlayers[i].character + 15), D_8010C338_36B228_name_55[gPlayers[i].character]);
        func_8005ABC0_5B7C0(&gPlayers[i], 2, 0);
        MBModelDispOff(PLAYER_MODEL(i));
    }
    D_8010C56C_36B45C_name_55 = func_80043510_44110(0x7B, D_8010C350_36B240_name_55);
    MBModelDispOff(D_8010C56C_36B45C_name_55);
    D_8010C564_36B454_name_55 = MBModelFileCreate(0x80049, 13, 0.7f, 1.4f, D_8010C360_36B250_name_55);
    MBModelDispOff(D_8010C564_36B454_name_55);
}

/* Board 5: a player's model. */
void func_8010A614_369504_name_55(s32 player) {
    MBPlayerModelCreate(player, D_8010C338_36B228_name_55[gPlayers[player].character], 2);
    gPlayers[player].flags |= 2;
    func_8005ABC0_5B7C0(&gPlayers[player], 2, 0);
}

/* Board 5's title (80108830 with its own sprite). */
void func_8010A6A4_369594_name_55(void) {
    f32 alpha;
    s32 n;

    func_80029708_2A308(1);
    func_8002CA48_2D648(255, 255, 255);
    D_8010C588_36B478_name_55 = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0xA0223), 0, 1);
    func_8001A788_1B388(D_8010C588_36B478_name_55, 0x2000);
    espPosSet(D_8010C588_36B478_name_55, 160, 64);
    func_8001A91C_1B51C(D_8010C588_36B478_name_55, 0.0f, 1.0f);
    func_8008F624_90224(255, 255, 255);
    InitFadeIn(0, 16);
    HuPrcSleep(16);
    alpha = 0.0f;
    PlayMusic(0x59);
    for (n = 0; n < 15; n++) {
        if (n == 3) {
            D_8010B762_36A652_name_55 = 1;
        }
        func_8001A91C_1B51C(D_8010C588_36B478_name_55, alpha, 1.0f);
        alpha += 0.06666667f;
        if (D_8010C568_36B458_name_55->work[0] == 1) {
            return;
        }
        HuPrcVSleep();
    }
    func_8001A91C_1B51C(D_8010C588_36B478_name_55, 1.0f, 1.0f);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3693E0", func_8010A804_3696F4_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3693E0", func_8010AE68_369D58_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3693E0", func_8010B3B4_36A2A4_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3693E0", func_8010B444_36A334_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3693E0", func_8010B518_36A408_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3693E0", func_8010B5C0_36A4B0_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3693E0", func_8010B6C0_36A5B0_name_55);
