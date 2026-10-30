#include "ovl_1D.h"

/* .data (0x1B8C10-0x1B8D20, 80106AC0-80106BD0); the zero words after D_80106BB8 are the
   object's 16-byte alignment. */

f32 D_80106AC0_1B8C10_SpeedHockey[4] = { -34.0f, -70.0f, 34.0f, 70.0f };
f32 D_80106AD0_1B8C20_SpeedHockey[4] = { 90.0f, 90.0f, -90.0f, -90.0f };
SHCpuDef D_80106AE0_1B8C30_SpeedHockey[4] = {
    { 25, 40, 15, 7 },
    { 20, 50, 20, 5 },
    { 15, 60, 25, 3 },
    { 10, 60, 30, 1 },
};
s32 D_80106AF0_1B8C40_SpeedHockey[6] = { 0x002D001B, 0x002D001C, 0x002D001D, 0x002D001E, 0x002D001F, 0x002D0020 };
SHMotDef D_80106B08_1B8C58_SpeedHockey[6][3] = {
    { { 0x002D0009, 0xFFFF }, { 0x002D000A, 0x0 }, { 0x002D000B, 0xFFFF } },
    { { 0x002D000C, 0xFFFF }, { 0x002D000D, 0x0 }, { 0x002D000E, 0xFFFF } },
    { { 0x002D000F, 0xFFFF }, { 0x002D0010, 0x0 }, { 0x002D0011, 0xFFFF } },
    { { 0x002D0012, 0xFFFF }, { 0x002D0013, 0x0 }, { 0x002D0014, 0xFFFF } },
    { { 0x002D0015, 0xFFFF }, { 0x002D0016, 0x0 }, { 0x002D0017, 0xFFFF } },
    { { 0x002D0018, 0xFFFF }, { 0x002D0019, 0x0 }, { 0x002D001A, 0xFFFF } },
};
void (*D_80106B98_1B8CE8_SpeedHockey[3])(omObjData*, SHPlayer*) = {
    func_801048D4_1B6A24_SpeedHockey,
    func_8010491C_1B6A6C_SpeedHockey,
    func_80104A90_1B6BE0_SpeedHockey,
};
void (*D_80106BA4_1B8CF4_SpeedHockey[5])(omObjData*) = {
    NULL, NULL, func_80104C00_1B6D50_SpeedHockey, func_80104C64_1B6DB4_SpeedHockey, NULL,
};
void (*D_80106BB8_1B8D08_SpeedHockey[4])(omObjData*) = {
    func_801053F0_1B7540_SpeedHockey,
    func_801054A8_1B75F8_SpeedHockey,
    func_80105560_1B76B0_SpeedHockey,
    func_80105618_1B7768_SpeedHockey,
};

#define SH_ABS(x) ((x) < 0.0f ? -(x) : (x))


/* Play motion slot mot (len / 5 frames; a speed < 0 keeps the motion's own speed). */
void func_801047A0_1B68F0_SpeedHockey(omObjData* obj, s32 mot) {
    SHPlayer* w = obj->unk_50;

    if (w->mot[mot].speed < 0) {
        func_80029BF0_2A7F0(obj->model[0], obj->motion[mot], 0, w->mot[mot].len / 5, 0);
        w->motion = mot;
    } else {
        func_80029BF0_2A7F0(obj->model[0], obj->motion[mot], 0, w->mot[mot].len / 5, 2);
        func_80029FBC_2ABBC(obj->model[0], w->mot[mot].speed);
        w->motion = mot;
    }
}

/* CPU state 0: wait (stick centred). */
void func_801048D4_1B6A24_SpeedHockey(omObjData* obj, SHPlayer* w) {
    if (--w->cpuTimer < 0) {
        w->cpuState = 1;
    }
    func_8010650C_1B865C_SpeedHockey(w->port, 0, 0, 0, 0);
}

#ifdef NON_MATCHING
/* masked 8: retail keeps the new target in f0 and shares the clamp constant's store (f2) between both bounds; GCC here swaps f0/f2 and stores in each arm */
/* CPU state 1: pick a z to move to (random, or the puck's when it comes this way). */
void func_8010491C_1B6A6C_SpeedHockey(omObjData* obj, SHPlayer* w) {
    Vec dir;
    Vec pos;
    Vec prev;
    f32 target;

    if ((u8)(rand8() % 10) < D_80106AE0_1B8C30_SpeedHockey[w->cpuLevel].chance) {
        target = (f32)(u8)(rand8() % 80) - 40.0f + 0.0f;
    } else {
        func_8010463C_1B678C_SpeedHockey(&dir, &pos, &prev);
        if (!(dir.x * obj->trans.x > 0.0f)) {
            return;
        }
        target = pos.z;
    }
    w->cpuTarget = target;
    if (target < -33.800003f) {
        w->cpuTarget = -33.800003f;
    } else if (w->cpuTarget > 33.800003f) {
        w->cpuTarget = 33.800003f;
    }
    w->cpuRange = 8.0f;
    w->cpuState = 2;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B68F0", func_8010491C_1B6A6C_SpeedHockey);
#endif

#ifdef NON_MATCHING
/* masked 12: retail keeps the table value and the signed speed in separate registers (two more mov.s); GCC here negates in place */
/* CPU state 2: push the stick toward the target z (slower when near), then wait. */
void func_80104A90_1B6BE0_SpeedHockey(omObjData* obj, SHPlayer* w) {
    f32 d = obj->trans.z - w->cpuTarget;
    f32 ad = (d < 0.0f) ? -d : d;
    f32 v;

    if (ad < w->cpuRange) {
        w->cpuState = 0;
        w->cpuTimer = (s8)D_80106AE0_1B8C30_SpeedHockey[w->cpuLevel].wait;
        func_8010650C_1B865C_SpeedHockey(w->port, 0, 0, 0, 0);
        return;
    }
    if (ad < 2.0f * w->cpuRange) {
        v = D_80106AE0_1B8C30_SpeedHockey[w->cpuLevel].slow * ((d < 0.0f) ? -1.0f : ((d > 0.0f) ? 1.0f : 0.0f));
    } else {
        v = D_80106AE0_1B8C30_SpeedHockey[w->cpuLevel].fast * ((d < 0.0f) ? -1.0f : ((d > 0.0f) ? 1.0f : 0.0f));
    }
    func_8010650C_1B865C_SpeedHockey(w->port, 0, (s8)v, 0, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B68F0", func_80104A90_1B6BE0_SpeedHockey);
#endif

/* A player in play: CPU input for CPU players, then the stick moves the paddle along z unless
   the puck is in the way. */
void func_80104C00_1B6D50_SpeedHockey(omObjData* obj) {
    SHPlayer* w = obj->unk_50;

    if (gPlayers[w->player].flags & 1) {
        D_80106B98_1B8CE8_SpeedHockey[w->cpuState](obj, w);
    }
}

/* A player after the game: cheer or sulk. */
void func_80104C64_1B6DB4_SpeedHockey(omObjData* obj) {
    SHPlayer* w = obj->unk_50;

    switch (w->state) {
        case 0:
            if (w->timer++ >= 31) {
                if (func_8010658C_1B86DC_SpeedHockey() == w->team) {
                    func_80106598_1B86E8_SpeedHockey(w->player);
                }
                if (_CheckFlag(0xC)) {
                    w->state += 2;
                } else {
                    w->state++;
                }
            }
            break;
        case 1:
            if (func_8010658C_1B86DC_SpeedHockey() == w->team) {
                func_800797DC_7A3DC(0x103, w->player);
                func_801047A0_1B68F0_SpeedHockey(obj, 1);
            } else {
                func_801047A0_1B68F0_SpeedHockey(obj, 2);
            }
            w->state++;
            break;
    }
}

#ifdef NON_MATCHING
/* masked 0: retail keeps obj in s0 and &D_80106BA4 in s1; GCC here swaps them */
void func_80104D4C_1B6E9C_SpeedHockey(omObjData* obj) {
    Vec pos;
    Vec prev;
    Vec dir;
    s8 y;
    f32 z;
    SHPlayer* w;

    w = obj->unk_50;
    if (D_80106BA4_1B8CF4_SpeedHockey[func_80106548_1B8698_SpeedHockey()] != NULL) {
        D_80106BA4_1B8CF4_SpeedHockey[func_80106548_1B8698_SpeedHockey()](obj);
    }
    y = ContStkY[w->port];
    if ((y >= 0) ? (y >= 6) : (-y >= 6)) {
        if (y < -60) {
            y = -60;
        } else if (y > 60) {
            y = 60;
        }
        z = obj->trans.z - (f32)y * 0.82f * 0.1f;
        if (z < -33.800003f) {
            z = -33.800003f;
        }
        if (z > 33.800003f) {
            z = 33.800003f;
        }
        func_8010463C_1B678C_SpeedHockey(&dir, &pos, &prev);
        if ((SH_ABS(pos.x - obj->trans.x) > 12.91f && SH_ABS(prev.x - obj->trans.x) > 12.91f) ||
            (SH_ABS(pos.z - z) > 20.35f && SH_ABS(prev.z - z) > 20.35f)) {
            obj->trans.z = z;
        }
    }
    func_80029714_2A314(obj->model[1], obj->trans.x, obj->trans.y, obj->trans.z);
    if (func_801046A0_1B67F0_SpeedHockey(obj) != 0) {
        omVibrate(w->player, 10, 0, 10);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1D_SpeedHockey/1B68F0", func_80104D4C_1B6E9C_SpeedHockey);
#endif

/* Set up a player object: model, motions, work, paddle slot. */
void func_801050F0_1B7240_SpeedHockey(omObjData* obj, s32 player, s32 team, s32 paddle) {
    s8 chr = gPlayers[player].character;
    SHPlayer* w;
    s32 i;

    obj->model[0] = LoadFormFile(D_80106AF0_1B8C40_SpeedHockey[chr], 0x6D9);
    obj->model[1] = func_80018A64_19664(0xD, 0x6D9);
    func_8003C8E0_3D4E0(obj->model[1]);
    w = func_80027154_27D54(sizeof(SHPlayer), 0x7918);
    if (w == NULL) {
        while (1) {
        }
    }
    func_800B0EF0_B1AF0(w, 0, sizeof(SHPlayer));
    obj->unk_50 = w;
    for (i = 0; i < 3; i++) {
        obj->motion[i] = func_8002C8B8_2D4B8(DataRead(D_80106B08_1B8C58_SpeedHockey[chr][i].file), 0x18);
        if (obj->motion[i] < 0) {
            while (1) {
            }
        }
        w->mot[i].len = func_8002CA14_2D614(obj->motion[i]);
        w->mot[i].speed = D_80106B08_1B8C58_SpeedHockey[chr][i].speed;
    }
    func_801047A0_1B68F0_SpeedHockey(obj, 0);
    w->player = player;
    w->port = gPlayers[player].port;
    if (team == 0) {
        w->team = 0;
    } else {
        w->team = 1;
    }
    switch (gPlayers[player].cpu_difficulty) {
        case 0:
            w->cpuLevel = 0;
            break;
        case 1:
            w->cpuLevel = 1;
            break;
        case 2:
            w->cpuLevel = 2;
            break;
        case 3:
            w->cpuLevel = 3;
            break;
        default:
            while (1) {
            }
    }
    omSetTra(obj, D_80106AC0_1B8C10_SpeedHockey[paddle], 10.5f, 0.0f);
    omSetRot(obj, 0.0f, D_80106AD0_1B8C20_SpeedHockey[paddle], 0.0f);
    omSetSca(obj, 0.15f, 0.15f, 0.15f);
    func_80029714_2A314(obj->model[1], D_80106AC0_1B8C10_SpeedHockey[paddle], 10.5f, 0.0f);
    func_800297E8_2A3E8(obj->model[1], 0.15f, 0.15f, 0.15f);
}

/* Player 1-4 object setup: team and paddle slot from the player's group. */
void func_801053F0_1B7540_SpeedHockey(omObjData* obj) {
    s32 team;
    s32 paddle;

    switch (gPlayers[0].group) {
        case 0:
            team = 0;
            paddle = 1;
            break;
        case 1:
            team = 0;
            paddle = 0;
            break;
        case 2:
            team = 1;
            paddle = 2;
            break;
        case 3:
            team = 1;
            paddle = 3;
            break;
    }
    func_801050F0_1B7240_SpeedHockey(obj, 0, team, paddle);
    func_8010461C_1B676C_SpeedHockey(paddle, obj);
    obj->func_ptr = func_80104D4C_1B6E9C_SpeedHockey;
}

void func_801054A8_1B75F8_SpeedHockey(omObjData* obj) {
    s32 team;
    s32 paddle;

    switch (gPlayers[1].group) {
        case 0:
            team = 0;
            paddle = 1;
            break;
        case 1:
            team = 0;
            paddle = 0;
            break;
        case 2:
            team = 1;
            paddle = 2;
            break;
        case 3:
            team = 1;
            paddle = 3;
            break;
    }
    func_801050F0_1B7240_SpeedHockey(obj, 1, team, paddle);
    func_8010461C_1B676C_SpeedHockey(paddle, obj);
    obj->func_ptr = func_80104D4C_1B6E9C_SpeedHockey;
}

void func_80105560_1B76B0_SpeedHockey(omObjData* obj) {
    s32 team;
    s32 paddle;

    switch (gPlayers[2].group) {
        case 0:
            team = 0;
            paddle = 1;
            break;
        case 1:
            team = 0;
            paddle = 0;
            break;
        case 2:
            team = 1;
            paddle = 2;
            break;
        case 3:
            team = 1;
            paddle = 3;
            break;
    }
    func_801050F0_1B7240_SpeedHockey(obj, 2, team, paddle);
    func_8010461C_1B676C_SpeedHockey(paddle, obj);
    obj->func_ptr = func_80104D4C_1B6E9C_SpeedHockey;
}

void func_80105618_1B7768_SpeedHockey(omObjData* obj) {
    s32 team;
    s32 paddle;

    switch (gPlayers[3].group) {
        case 0:
            team = 0;
            paddle = 1;
            break;
        case 1:
            team = 0;
            paddle = 0;
            break;
        case 2:
            team = 1;
            paddle = 2;
            break;
        case 3:
            team = 1;
            paddle = 3;
            break;
    }
    func_801050F0_1B7240_SpeedHockey(obj, 3, team, paddle);
    func_8010461C_1B676C_SpeedHockey(paddle, obj);
    obj->func_ptr = func_80104D4C_1B6E9C_SpeedHockey;
}

/* Create object group 0: the four players. */
void func_801056D0_1B7820_SpeedHockey(void) {
    s32 i;

    func_80076BD0_777D0(0, 4);
    D_80106EA0_1B8FF0_SpeedHockey = func_80076D80_77980(0);
    for (i = 0; i < 4; i++) {
        D_80106EA0_1B8FF0_SpeedHockey[i] = omAddObj(2, 2, 3, 0, D_80106BB8_1B8D08_SpeedHockey[i]);
    }
}

void func_80105768_1B78B8_SpeedHockey(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        omDelObj(func_80076D98_77998(0, i));
    }
}
