#include "ovl_55.h"

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
