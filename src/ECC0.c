#include "common.h"

#include "game/collision.h"

/* Sets a minigame player's override hook (MgWork::unk_104). */
void func_8000E0C0_ECC0(MgWork* work, s32 slot, void* hook) {
    if (slot < 21) {
        work->unk_104[slot] = hook;
    }
}
