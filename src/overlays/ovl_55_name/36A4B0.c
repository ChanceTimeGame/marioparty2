#include "ovl_55.h"

/* .data (0x36B2E0-0x36B3E0) */
/* board 6, per character: MBPlayerModelCreate lists */
u32 D_8010C3F0_36B2E0_name_55[9] = {
    8, 0x20012, 0x20010, 0x20000, 0x20001, 0x20002, 0x20098, 0x20052,
    0x20050,
};
u32 D_8010C414_36B304_name_55[9] = {
    8, 0x30012, 0x30010, 0x30000, 0x30001, 0x30002, 0x30098, 0x30052,
    0x30050,
};
u32 D_8010C438_36B328_name_55[9] = {
    8, 0x70012, 0x70010, 0x70000, 0x70001, 0x70002, 0x70098, 0x70052,
    0x70050,
};
u32 D_8010C45C_36B34C_name_55[9] = {
    8, 0x40012, 0x40010, 0x40000, 0x40001, 0x40002, 0x40098, 0x40052,
    0x40050,
};
u32 D_8010C480_36B370_name_55[9] = {
    8, 0x50012, 0x50010, 0x50000, 0x50001, 0x50002, 0x50098, 0x50052,
    0x50050,
};
u32 D_8010C4A4_36B394_name_55[9] = {
    8, 0x60012, 0x60010, 0x60000, 0x60001, 0x60002, 0x60098, 0x60052,
    0x60050,
};
void* D_8010C4C8_36B3B8_name_55[6] = {
    D_8010C3F0_36B2E0_name_55, D_8010C414_36B304_name_55, D_8010C438_36B328_name_55, D_8010C45C_36B34C_name_55,
    D_8010C480_36B370_name_55, D_8010C4A4_36B394_name_55,
};
u32 D_8010C4E0_36B3D0_name_55[4] = {
    3, 0x80037, 0x80036, 0x80037,
};

/* Board 6's scene setup: the players' models and the host. */
void func_8010B5C0_36A4B0_name_55(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        gPlayers[i].unk_24 = func_80043510_44110((u8)(gPlayers[i].character + 15), D_8010C4C8_36B3B8_name_55[gPlayers[i].character]);
        func_8005ABC0_5B7C0(&gPlayers[i], 2, 0);
        MBModelDispOff(PLAYER_MODEL(i));
    }
    D_8010C56C_36B45C_name_55 = MBModelFileCreate(0x80035, 13, 1.0f, 0.7f, D_8010C4E0_36B3D0_name_55);
    MBModelDispOff(D_8010C56C_36B45C_name_55);
}

/* Board 6: a player's model. */
void func_8010B6C0_36A5B0_name_55(s32 player) {
    MBPlayerModelCreate(player, D_8010C4C8_36B3B8_name_55[gPlayers[player].character], 2);
    gPlayers[player].flags |= 2;
    func_8005ABC0_5B7C0(&gPlayers[player], 2, 0);
}
