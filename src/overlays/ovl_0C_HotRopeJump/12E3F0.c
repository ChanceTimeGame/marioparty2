#include "ovl_0C.h"

/* The game's setup: objects, camera, each player's place drawn at random, the motion constants.
   NON_MATCHING: retail hoists only the source table and -1 out of the place-drawing loop and keeps
   D_8010C11C by %lo (GCC hoists its address too; masked 17) */
#ifdef NON_MATCHING
void func_80102800_12E3F0_HotRopeJump(void) {
    s32* tbl;
    u8 cam;
    s16 i;
    s32 r;

    func_8002D4D0_2E0D0(50);
    func_8002F290_2FE90(D_800F9D30_FA930, 64);
    omInitObjMan(50, 0);
    func_80079128_79D28();
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, func_80079E60_7AA60), 0xA0);
    func_80018E30_19A30(1);
    cam = func_80018E78_19A78();
    ScissorSet(cam, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(cam, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 30.0f, 80.0f, 8000.0f);
    func_8010781C_13340C_HotRopeJump(1600.0f, 0.0f, 100.0f, 100.0f, -30.0f, -50.0f, 0.0f);
    D_80111318_13CF08_HotRopeJump = 0;
    D_800F8FD0_F9BD0 = 1;
    if ((D_8010C140_137D30_HotRopeJump = _CheckFlag(0xC)) != 0) {
        D_8010C110_137D00_HotRopeJump = 50;
    }
    D_800FA606_FB206 = 0;
    D_800FC87A_FD47A = 0;
    D_800F8FE0_F9BE0 = 0;
    func_8000C018_CC18(0);
    D_80111150_13CD40_HotRopeJump = omAddObj(1, 0, 0, -1, func_80102C10_12E800_HotRopeJump);
    omSetStatBit(D_80111150_13CD40_HotRopeJump, 0xA0);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(3, 10, 60, -1, func_80102DD0_12E9C0_HotRopeJump);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(3, 10, 60, -1, func_80102F18_12EB08_HotRopeJump);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(3, 10, 60, -1, func_80103060_12EC50_HotRopeJump);
    D_800FFFD8_100BD8[D_800FC87A_FD47A++] = omAddObj(3, 10, 60, -1, func_801031A8_12ED98_HotRopeJump);
    func_80107FB0_133BA0_HotRopeJump();
    D_80111140_13CD30_HotRopeJump = D_800BF7C0_C03C0;
    D_80111144_13CD34_HotRopeJump = D_800BF7A4_C03A4;
    D_80111148_13CD38_HotRopeJump = D_800BF7A8_C03A8;
    D_8011114C_13CD3C_HotRopeJump = D_800BF7D4_C03D4;
    i = 0;
    tbl = D_8010C12C_137D1C_HotRopeJump;
    do {
        do {
            r = rand8() & 3;
        } while (tbl[r] == -1);
        D_8010C11C_137D0C_HotRopeJump[i] = tbl[r];
        i++;
        tbl[r] = -1;
    } while (i < 4);
    D_80111928_13D518_HotRopeJump = -1;
    D_80111338_13CF28_HotRopeJump = 4;
    D_80111334_13CF24_HotRopeJump = 0;
    D_8011133C_13CF2C_HotRopeJump = 0;
    D_80111340_13CF30_HotRopeJump = 0;
    D_80111348_13CF38_HotRopeJump = 0;
    D_80111344_13CF34_HotRopeJump = 0;
    D_800BF7A4_C03A4 = 1.6f;
    D_800BF7A8_C03A8 = 0.175f;
    InitFadeIn(0, 16);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80102800_12E3F0_HotRopeJump);
#endif

void func_80102C10_12E800_HotRopeJump(omObjData* obj) {
    void* file;
    s32 sprite;
    s32 i;

    obj->func_ptr = func_80103620_12F210_HotRopeJump;
    func_80105DC0_1319B0_HotRopeJump(48);
    file = DataRead(0x1D0005);
    D_8011131C_13CF0C_HotRopeJump = SprAnimRead(file);
    DataClose(file);
    i = 0;
    func_80107424_133014_HotRopeJump();
    file = DataRead(0x38);
    sprite = SprAnimRead(file);
    DataClose(file);
    D_80111320_13CF10_HotRopeJump = SprCreate(2, 0);
    do {
        SprAnimSet((s16)D_80111320_13CF10_HotRopeJump, i, sprite, 0);
        SprPosSet((s16)D_80111320_13CF10_HotRopeJump, i, (s16)D_8010C1D4_137DC4_HotRopeJump[i][0],
                  (s16)D_8010C1D4_137DC4_HotRopeJump[i][1]);
        SprScaleSet((s16)D_80111320_13CF10_HotRopeJump, i, 1.0f, 1.0f);
        func_80082488_83088((s16)D_80111320_13CF10_HotRopeJump, i, 0x100);
        SprAttrSet((s16)D_80111320_13CF10_HotRopeJump, i, 0x1000);
        func_8008225C_82E5C((s16)D_80111320_13CF10_HotRopeJump, i, 0);
        i++;
    } while (i < 2);
}

void func_80102D84_12E974_HotRopeJump(omObjData* obj) {
    func_80107424_133014_HotRopeJump();
    func_80107B4C_13373C_HotRopeJump(obj);
    if (func_8008F618_90218() == 0) {
        func_80105CD4_1318C4_HotRopeJump();
        omOvlReturnEx(1);
    }
}

void func_80102DD0_12E9C0_HotRopeJump(omObjData* obj) {
    func_801032F0_12EEE0_HotRopeJump(obj, 0);
    func_80105D74_131964_HotRopeJump(obj, &D_80111158_13CD48_HotRopeJump[0]);
    func_8000C35C_CF5C(obj, -800.0f, 0.0f, -800.0f);
    D_80111158_13CD48_HotRopeJump[0].home.x = 0.0f;
    D_80111158_13CD48_HotRopeJump[0].home.y = 0.0f;
    D_80111158_13CD48_HotRopeJump[0].home.z = D_8010C1F4_137DE4_HotRopeJump[D_8010C11C_137D0C_HotRopeJump[0]] * 100.0;
    D_80111158_13CD48_HotRopeJump[0].speed = 20;
    D_80111158_13CD48_HotRopeJump[0].unk_64 = 0;
    if (!(gPlayers[0].flags & 1)) {
        D_80111334_13CF24_HotRopeJump++;
        if (D_8010C140_137D30_HotRopeJump != 0) {
            D_8011133C_13CF2C_HotRopeJump = 0;
        }
    }
    if (D_8010C11C_137D0C_HotRopeJump[0] == 3) {
        func_8002D1EC_2DDEC(obj->model[0], 0);
        func_8002D274_2DE74(obj->model[0], 0, 0, 0);
        func_8002D2B4_2DEB4(obj->model[0], 10.0f, 0.0f, 0.0f);
        D_80111928_13D518_HotRopeJump = obj->model[0];
    }
    func_80105214_130E04_HotRopeJump(obj, 6);
}

void func_80102F18_12EB08_HotRopeJump(omObjData* obj) {
    func_801032F0_12EEE0_HotRopeJump(obj, 1);
    func_80105D74_131964_HotRopeJump(obj, &D_80111158_13CD48_HotRopeJump[1]);
    func_8000C35C_CF5C(obj, -800.0f, 0.0f, -800.0f);
    D_80111158_13CD48_HotRopeJump[1].home.x = 0.0f;
    D_80111158_13CD48_HotRopeJump[1].home.y = 0.0f;
    D_80111158_13CD48_HotRopeJump[1].home.z = D_8010C1F4_137DE4_HotRopeJump[D_8010C11C_137D0C_HotRopeJump[1]] * 100.0;
    D_80111158_13CD48_HotRopeJump[1].speed = 20;
    D_80111158_13CD48_HotRopeJump[1].unk_64 = 0;
    if (!(gPlayers[1].flags & 1)) {
        D_80111334_13CF24_HotRopeJump++;
        if (D_8010C140_137D30_HotRopeJump != 0) {
            D_8011133C_13CF2C_HotRopeJump = 1;
        }
    }
    if (D_8010C11C_137D0C_HotRopeJump[1] == 3) {
        func_8002D1EC_2DDEC(obj->model[0], 0);
        func_8002D274_2DE74(obj->model[0], 0, 0, 0);
        func_8002D2B4_2DEB4(obj->model[0], 10.0f, 0.0f, 0.0f);
        D_80111928_13D518_HotRopeJump = obj->model[0];
    }
    func_80105214_130E04_HotRopeJump(obj, 6);
}

void func_80103060_12EC50_HotRopeJump(omObjData* obj) {
    func_801032F0_12EEE0_HotRopeJump(obj, 2);
    func_80105D74_131964_HotRopeJump(obj, &D_80111158_13CD48_HotRopeJump[2]);
    func_8000C35C_CF5C(obj, -800.0f, 0.0f, -800.0f);
    D_80111158_13CD48_HotRopeJump[2].home.x = 0.0f;
    D_80111158_13CD48_HotRopeJump[2].home.y = 0.0f;
    D_80111158_13CD48_HotRopeJump[2].home.z = D_8010C1F4_137DE4_HotRopeJump[D_8010C11C_137D0C_HotRopeJump[2]] * 100.0;
    D_80111158_13CD48_HotRopeJump[2].speed = 20;
    D_80111158_13CD48_HotRopeJump[2].unk_64 = 0;
    if (!(gPlayers[2].flags & 1)) {
        D_80111334_13CF24_HotRopeJump++;
        if (D_8010C140_137D30_HotRopeJump != 0) {
            D_8011133C_13CF2C_HotRopeJump = 2;
        }
    }
    if (D_8010C11C_137D0C_HotRopeJump[2] == 3) {
        func_8002D1EC_2DDEC(obj->model[0], 0);
        func_8002D274_2DE74(obj->model[0], 0, 0, 0);
        func_8002D2B4_2DEB4(obj->model[0], 10.0f, 0.0f, 0.0f);
        D_80111928_13D518_HotRopeJump = obj->model[0];
    }
    func_80105214_130E04_HotRopeJump(obj, 6);
}

void func_801031A8_12ED98_HotRopeJump(omObjData* obj) {
    func_801032F0_12EEE0_HotRopeJump(obj, 3);
    func_80105D74_131964_HotRopeJump(obj, &D_80111158_13CD48_HotRopeJump[3]);
    func_8000C35C_CF5C(obj, -800.0f, 0.0f, -800.0f);
    D_80111158_13CD48_HotRopeJump[3].home.x = 0.0f;
    D_80111158_13CD48_HotRopeJump[3].home.y = 0.0f;
    D_80111158_13CD48_HotRopeJump[3].home.z = D_8010C1F4_137DE4_HotRopeJump[D_8010C11C_137D0C_HotRopeJump[3]] * 100.0;
    D_80111158_13CD48_HotRopeJump[3].speed = 20;
    D_80111158_13CD48_HotRopeJump[3].unk_64 = 0;
    if (D_8010C11C_137D0C_HotRopeJump[3] == 3) {
        func_8002D1EC_2DDEC(obj->model[0], 0);
        func_8002D274_2DE74(obj->model[0], 0, 0, 0);
        func_8002D2B4_2DEB4(obj->model[0], 10.0f, 0.0f, 0.0f);
        D_80111928_13D518_HotRopeJump = obj->model[0];
    }
    if (!(gPlayers[3].flags & 1)) {
        D_80111334_13CF24_HotRopeJump++;
        if (D_8010C140_137D30_HotRopeJump != 0) {
            D_8011133C_13CF2C_HotRopeJump = 3;
        }
    }
    func_80105214_130E04_HotRopeJump(obj, 6);
}

/* Loads a player's model and motions; the win/lose motions are a random pair, kept in
   D_80111350_13CF40_HotRopeJump for func_80104518. */
void func_801032F0_12EEE0_HotRopeJump(omObjData* obj, s32 player) {
    s32 mot[4];
    s32 dir;
    s32 file;
    s32 r;
    MgWork* w;

    mot[0] = 0x4E;
    mot[1] = 0x4F;
    mot[2] = 0x55;
    mot[3] = 0x56;
    dir = D_800CD438_CE038[gPlayers[player].character].dir;
    file = D_800CD438_CE038[gPlayers[player].character].file;
    func_8000C578_D178(0);
    func_8000C6FC_D2FC(obj, dir, file, player, 0x4B9, 0x6B9);
    obj->func_ptr = func_80104518_130108_HotRopeJump;
    w = obj->unk_50;
    w->unk_EC = NULL;
    w->unk_59 = player;
    if (gPlayers[player].flags & 1) {
        D_8010C11A_137D0A_HotRopeJump |= 1 << player;
    }
    obj->model[3] = LoadFormFile(7, 0x68D);
    obj->model[4] = LoadFormFile(8, 0x68D);
    func_80019E84_1AA84(obj, 0, dir, 1, 0);
    func_80019E84_1AA84(obj, 1, dir | 1, 1, 0);
    func_80019E84_1AA84(obj, 2, dir | 2, 1, 0);
    func_80019E84_1AA84(obj, 6, dir | 4, 1, 0x13);
    r = rand8() & 1;
    func_80019E84_1AA84(obj, 0xD, dir | mot[r], 1, 999);
    D_80111350_13CF40_HotRopeJump[player][0] = dir | mot[r];
    func_80019E84_1AA84(obj, 0xE, dir | mot[r + 2], 1, 999);
    D_80111350_13CF40_HotRopeJump[player][1] = dir | mot[r + 2];
    func_80019E84_1AA84(obj, 0x11, dir | 0xF, 0, 0);
    func_80019E84_1AA84(obj, 0x15, dir | 0x2E, 0, 0);
    func_80019E84_1AA84(obj, 0x1E, dir | 0x2F, 0, 0);
    func_80019E84_1AA84(obj, 0x1F, dir | 0x30, 0, 0);
    func_80019E84_1AA84(obj, 0x21, dir | 0x32, 2, 0);
    func_80019E84_1AA84(obj, 0x22, dir | 0x33, 2, 0);
    func_80019E84_1AA84(obj, 0x26, dir | 0x1C, 1, 0);
    func_80019E84_1AA84(obj, 0x27, dir, 2, 0);
    func_8000C35C_CF5C(obj, 0.0f, 0.0f, 0.0f);
    omSetTra(obj, 0.0f, 0.0f, 0.0f);
    func_80019B9C_1A79C(obj, 2);
    func_80019378_19F78(obj);
    func_8000C024_CC24(obj, 0, 2);
}

/* The game's control object: intro, the rope's speed script and the music tempo, the jump count,
   the result (coins to the players left standing) and the camera follow. */
/* NON_MATCHING: retail reloads D_8010C220 for the phase increment; GCC reuses the value it indexed
   D_8010C1C0 with (one register, everything else matches) */
#ifdef NON_MATCHING
void func_80103620_12F210_HotRopeJump(omObjData* obj) {
    Vec v;
    Vec out;
    s32 chars[4];
    HRJPhase* ph;
    f32 a;
    f32 d;
    s32 i;
    s32 n;
    s16 mes;

    n = 0;
    if (D_8010C224_137E14_HotRopeJump != 0) {
        if (D_8010C224_137E14_HotRopeJump == 1) {
            obj->func_ptr = func_80102D84_12E974_HotRopeJump;
        }
        D_8010C224_137E14_HotRopeJump--;
    } else if (D_801011FC_101DFC == 1 && D_8010C114_137D04_HotRopeJump != 11) {
        D_80111318_13CF08_HotRopeJump = -1;
        D_8010C224_137E14_HotRopeJump = 20;
        InitFadeOut(0, (s16)D_8010C224_137E14_HotRopeJump);
        func_800794A8_7A0A8((s16)D_8010C224_137E14_HotRopeJump);
        func_80079614_7A214((s16)D_8010C224_137E14_HotRopeJump);
    }
    if (func_80078EA8_79AA8() + D_80102720_103320 != 0) {
        return;
    }
    switch (D_8010C114_137D04_HotRopeJump) {
        case 0:
            if (func_8008F618_90218() == 0) {
                if (D_8010C208_137DF8_HotRopeJump != 0) {
                    if (D_8010C208_137DF8_HotRopeJump >= 50) {
                        D_8010C114_137D04_HotRopeJump = 1;
                        D_8010C208_137DF8_HotRopeJump = 0;
                    }
                }
                D_8010C208_137DF8_HotRopeJump++;
            }
            break;
        case 1:
            D_8010C208_137DF8_HotRopeJump++;
            if (D_8010C118_137D08_HotRopeJump != 0) {
                D_8010C114_137D04_HotRopeJump = 2;
                D_8010C118_137D08_HotRopeJump = 0;
                D_8010C208_137DF8_HotRopeJump = 0;
            }
            break;
        case 2:
            if (D_8010C208_137DF8_HotRopeJump == 0) {
                func_800691FC_69DFC(0);
                PlayMusic(0x26);
                D_8010C208_137DF8_HotRopeJump++;
            } else if (func_80069538_6A138() == 0) {
                D_8010C114_137D04_HotRopeJump = 3;
                D_8010C208_137DF8_HotRopeJump = 30;
                func_8010BF70_137B60_HotRopeJump();
                D_80111328_13CF18_HotRopeJump = D_8011132C_13CF1C_HotRopeJump = D_80111324_13CF14_HotRopeJump =
                    D_8010C1C0_137DB0_HotRopeJump[0]->speed[0];
                D_80111330_13CF20_HotRopeJump = D_8010C1C0_137DB0_HotRopeJump[0]->unk_08;
                func_8010BF98_137B88_HotRopeJump(D_8010C1C0_137DB0_HotRopeJump[0]->unk_08);
                D_80111398_13CF88_HotRopeJump = D_8010C1C0_137DB0_HotRopeJump[0]->unk_08;
                func_8010BF8C_137B7C_HotRopeJump(D_80111324_13CF14_HotRopeJump);
            }
            break;
        case 3:
            if (D_80111344_13CF34_HotRopeJump == 0) {
                D_80111344_13CF34_HotRopeJump = D_80111348_13CF38_HotRopeJump = func_80079574_7A174();
            }
            a = D_80111920_13D510_HotRopeJump[6].angle;
            if (a >= 270.0f) {
                if (D_8010C214_137E04_HotRopeJump == 0.0f) {
                    if (D_8010C144_137D34_HotRopeJump < 255) {
                        D_8010C144_137D34_HotRopeJump++;
                    }
                    ph = D_8010C1C0_137DB0_HotRopeJump[D_8010C220_137E10_HotRopeJump];
                    if (ph->count != -1) {
                        if (++D_8010C21C_137E0C_HotRopeJump >= ph->count) {
                            D_8010C220_137E10_HotRopeJump++;
                            ph++;
                            D_8010C21C_137E0C_HotRopeJump = 0;
                        }
                    } else {
                        D_8010C21C_137E0C_HotRopeJump = 0;
                    }
                    switch (ph->mode) {
                        case 0:
                            D_80111328_13CF18_HotRopeJump = ph->speed[0];
                            break;
                        case 1:
                            D_80111328_13CF18_HotRopeJump = ph->speed[(u8)(rand8() % 3)];
                            break;
                        case 2:
                            D_80111328_13CF18_HotRopeJump = D_80111328_13CF18_HotRopeJump + ph->speed[0];
                            break;
                        default:
                            if ((u8)(rand8() % 100) < 75) {
                                D_80111328_13CF18_HotRopeJump = ph->speed[0];
                            } else {
                                D_80111328_13CF18_HotRopeJump = ph->speed[(rand8() & 1) + 1];
                            }
                            break;
                    }
                    if (D_80111328_13CF18_HotRopeJump < 0.48) {
                        D_80111328_13CF18_HotRopeJump = 0.48f;
                    } else if (D_80111328_13CF18_HotRopeJump > 1.7) {
                        D_80111328_13CF18_HotRopeJump = 1.7f;
                    }
                    if (D_80111344_13CF34_HotRopeJump != 0) {
                        if (D_80111330_13CF20_HotRopeJump < ph->unk_08) {
                            D_80111344_13CF34_HotRopeJump += 5;
                            if (D_80111344_13CF34_HotRopeJump >= 131) {
                                D_80111344_13CF34_HotRopeJump = 130;
                            }
                        } else if (D_8011132C_13CF1C_HotRopeJump < D_80111328_13CF18_HotRopeJump) {
                            D_80111344_13CF34_HotRopeJump += 10;
                            if (D_80111344_13CF34_HotRopeJump >= 131) {
                                D_80111344_13CF34_HotRopeJump = 130;
                            }
                        } else if (D_8011132C_13CF1C_HotRopeJump < D_80111328_13CF18_HotRopeJump) {
                            /* retail tests the same condition again: the slow-down never runs */
                            D_80111344_13CF34_HotRopeJump -= 10;
                            if (D_80111344_13CF34_HotRopeJump < 105) {
                                D_80111344_13CF34_HotRopeJump = 105;
                            }
                        }
                        D_8011132C_13CF1C_HotRopeJump = D_80111328_13CF18_HotRopeJump;
                        D_80111330_13CF20_HotRopeJump = ph->unk_08;
                    }
                    func_8010BF98_137B88_HotRopeJump(ph->unk_08);
                    D_80111398_13CF88_HotRopeJump = ph->unk_08;
                    if (D_80111334_13CF24_HotRopeJump == 0) {
                        for (i = 0; i < 4; i++) {
                            D_80111158_13CD48_HotRopeJump[i].unk_0C = (rand8() & 3) + (u16)D_8010C144_137D34_HotRopeJump;
                        }
                        D_80111334_13CF24_HotRopeJump = -1;
                    }
                }
                D_80111324_13CF14_HotRopeJump = func_80107F54_133B44_HotRopeJump(D_80111324_13CF14_HotRopeJump, D_80111328_13CF18_HotRopeJump, 0.2f);
                D_8010C214_137E04_HotRopeJump = 1.0f;
            } else if (a < D_8010C210_137E00_HotRopeJump) {
                D_80111324_13CF14_HotRopeJump = func_80107F54_133B44_HotRopeJump(D_80111324_13CF14_HotRopeJump, D_80111328_13CF18_HotRopeJump, 0.2f);
                func_8010BF8C_137B7C_HotRopeJump(D_80111324_13CF14_HotRopeJump);
                D_8010C214_137E04_HotRopeJump = 0.0f;
                if (D_8010C118_137D08_HotRopeJump == 0 && D_8010C144_137D34_HotRopeJump < 100) {
                    SprBankSet((s16)D_80111320_13CF10_HotRopeJump, 0, D_8010C144_137D34_HotRopeJump / 10);
                    SprBankSet((s16)D_80111320_13CF10_HotRopeJump, 1, D_8010C144_137D34_HotRopeJump % 10);
                }
                if (D_8010C144_137D34_HotRopeJump >= D_8010C110_137D00_HotRopeJump && D_8010C140_137D30_HotRopeJump != 0 &&
                    D_8010C118_137D08_HotRopeJump == 0) {
                    D_80111340_13CF30_HotRopeJump = 1;
                    D_8010C118_137D08_HotRopeJump = 1;
                }
                if (D_8010C118_137D08_HotRopeJump != 0) {
                    func_800691FC_69DFC(3);
                    func_800794A8_7A0A8(40);
                    if (D_8010C140_137D30_HotRopeJump != 0) {
                        D_8010C114_137D04_HotRopeJump = 10;
                    } else {
                        D_8010C114_137D04_HotRopeJump = 9;
                    }
                    func_8010BF80_137B70_HotRopeJump();
                    D_8010C208_137DF8_HotRopeJump = 30;
                    if (D_8010C204_137DF4_HotRopeJump != NULL) {
                        func_801078A4_133494_HotRopeJump(800.0f, D_8010C204_137DF4_HotRopeJump->trans.x, 200.0f,
                                                          D_8010C204_137DF4_HotRopeJump->trans.z, -30.0f, -50.0f, 0.0f, 30);
                    }
                }
            }
            D_8010C210_137E00_HotRopeJump = a;
            break;
        case 9:
            if (D_8010C204_137DF4_HotRopeJump != NULL && D_8010C204_137DF4_HotRopeJump->trans.y <= 180.0) {
                func_801078A4_133494_HotRopeJump(1800.0f, 0.0f, 100.0f, 0.0f, -30.0f, -90.0f, 0.0f, 45);
                D_8010C204_137DF4_HotRopeJump = NULL;
            }
            func_80107928_133518_HotRopeJump(D_8010C13C_137D2C_HotRopeJump, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
            D_8010C13C_137D2C_HotRopeJump = 0.0f;
            if (D_8010C218_137E08_HotRopeJump == 0) {
                if (!(func_80069538_6A138() & 2)) {
                    break;
                }
                if (D_80111338_13CF28_HotRopeJump > 0) {
                    for (i = 0; i < 4; i++) {
                        if (func_80105D94_131984_HotRopeJump(D_800FFFD8_100BD8[i])->unk_00 == 0) {
                            gPlayers[i].coins_mg_bonus += 10;
                        }
                    }
                    mes = 0x51;
                } else {
                    mes = 0x57;
                }
                PlayMusic(mes);
                for (i = 0; i < 2; i++) {
                    SprAttrSet((s16)D_80111320_13CF10_HotRopeJump, i, 0x8000);
                }
                for (i = 0; i < 4; i++) {
                    if (func_80105D94_131984_HotRopeJump(D_800FFFD8_100BD8[i])->unk_00 == 0) {
                        chars[n++] = gPlayers[i].character;
                    }
                }
                switch (D_80111338_13CF28_HotRopeJump) {
                    case 4:
                        mes = 0xB;
                        goto show;
                    case 3:
                        func_800691FC_69DFC(0x15, chars[0], chars[1], chars[2]);
                        break;
                    case 2:
                        func_800691FC_69DFC(0x11, chars[0], chars[1]);
                        break;
                    case 1:
                        func_800691FC_69DFC(6, chars[0]);
                        break;
                    default:
                        mes = 0x13;
                    show:
                        func_800691FC_69DFC(mes);
                        break;
                }
            } else if (D_8010C218_137E08_HotRopeJump >= 120.0) {
                func_80079614_7A214(40);
                D_8010C114_137D04_HotRopeJump = 11;
            }
            D_8010C218_137E08_HotRopeJump++;
            break;
        case 10:
            if (D_8010C204_137DF4_HotRopeJump != NULL) {
                if (D_8010C204_137DF4_HotRopeJump->trans.y <= 180.0) {
                    func_801078A4_133494_HotRopeJump(1800.0f, 0.0f, 100.0f, 0.0f, -30.0f, -90.0f, 0.0f, 45);
                    D_8010C204_137DF4_HotRopeJump = NULL;
                }
                func_80107928_133518_HotRopeJump(D_8010C13C_137D2C_HotRopeJump, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
                D_8010C13C_137D2C_HotRopeJump = 0.0f;
            }
            if (D_8010C218_137E08_HotRopeJump == 0) {
                for (i = 0; i < 4; i++) {
                    if (func_80105D94_131984_HotRopeJump(D_800FFFD8_100BD8[i])->unk_00 == 0) {
                        gPlayers[i].coins_mg_bonus += 10;
                    }
                }
                for (i = 0; i < 2; i++) {
                    SprAttrSet((s16)D_80111320_13CF10_HotRopeJump, i, 0x8000);
                }
            } else if (D_8010C218_137E08_HotRopeJump >= 60.0) {
                D_8010C114_137D04_HotRopeJump = 11;
            }
            D_8010C218_137E08_HotRopeJump++;
            break;
        case 11:
            if (D_8010C140_137D30_HotRopeJump == 0) {
                func_80107928_133518_HotRopeJump(D_8010C13C_137D2C_HotRopeJump, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
            }
            D_8010C13C_137D2C_HotRopeJump = 0.0f;
            D_80111318_13CF08_HotRopeJump = -1;
            func_800794A8_7A0A8(40);
            if (D_8010C140_137D30_HotRopeJump != 0) {
                func_80079614_7A214(40);
            }
            InitFadeOut(0, 20);
            obj->func_ptr = func_80102D84_12E974_HotRopeJump;
            break;
    }
    if (D_8010C204_137DF4_HotRopeJump != NULL) {
        v.x = D_8010C204_137DF4_HotRopeJump->trans.x;
        if (D_8010C204_137DF4_HotRopeJump->trans.y > 180.0) {
            v.y = D_8010C204_137DF4_HotRopeJump->trans.y + 180.0;
        } else {
            v.y = 180.0f;
        }
        v.z = D_8010C204_137DF4_HotRopeJump->trans.z;
        func_80107CA4_133894_HotRopeJump(0, &v, &out);
        if (out.y < 48.0f) {
            d = out.y - 48.0f;
        } else if (out.y > 184.0f) {
            d = out.y - 184.0f;
        } else {
            goto pan;
        }
        d = -d / 24.0f;
        func_80107928_133518_HotRopeJump(0.0f, 0.0f, d * 10.0f, 0.0f, d * 1.25, 0.0f, 0.0f);
    pan:
        if (out.x < 56.0f) {
            d = out.x - 56.0f;
        } else if (out.x > 272.0f) {
            d = out.x - 264.0f;
        } else {
            goto end;
        }
        func_80107928_133518_HotRopeJump(0.0f, 0.0f, 0.0f, d / 28.0f, 0.0f, 0.0f, 0.0f);
    }
end:
    func_80107424_133014_HotRopeJump();
    if (D_8010C114_137D04_HotRopeJump >= 3) {
        func_80107B4C_13373C_HotRopeJump(obj);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80103620_12F210_HotRopeJump);
#endif

/* A player: the intro walk to its place, jumping (A) while the rope turns (a CPU jumps until its
   allowance, unk_0C, runs out), getting hit and bouncing off the stage, and the win pose. */
void func_80104518_130108_HotRopeJump(omObjData* obj) {
    Vec pos;
    MgWork* w;
    HRJPlayer* p;
    u16 trg;
    u16 btn;
    u16 cnt;
    u8 port;
    s32 motEnd;
    s32 r;
    f32 a;
    f32 x;
    f32 y;
    f32 z;
    f32 v2;
    f32 sc;

    trg = 0;
    w = obj->unk_50;
    btn = 0;
    p = func_80105D94_131984_HotRopeJump(obj);
    a = obj->rot.y;
    port = w->unk_57;
    cnt = D_8010C228_137E18_HotRopeJump[w->unk_59];
    motEnd = func_80019000_19C00(obj);
    pos.x = x = obj->trans.x;
    pos.y = y = obj->trans.y;
    pos.z = z = obj->trans.z;
    if (!(gPlayers[w->unk_59].flags & 1) && D_8010C114_137D04_HotRopeJump == 3) {
        trg = ContBtnTrg[(s8)port];
        btn = ContBtn[(s8)port];
    }
    switch (D_8010C114_137D04_HotRopeJump) {
        case 0:
            p->intro = p->unk_46 = p->unk_48 = p->unk_4A = 0;
            p->unk_00 = 0;
            if (gPlayers[w->unk_59].flags & 1) {
                if (D_80111334_13CF24_HotRopeJump != 0) {
                    p->unk_0C = (u8)(rand8() % 10) + 5 + gPlayers[w->unk_59].cpu_difficulty * 10;
                } else {
                    p->unk_0C = (u8)(rand8() % 7) + 3;
                    if (w->unk_59 == 3) {
                        D_80111334_13CF24_HotRopeJump = -1;
                    }
                }
            }
            p->state = 0x100;
            a = func_800B75A8_B81A8(p->home.x - obj->trans.x, p->home.z - obj->trans.z);
            break;
        case 1:
            switch (p->intro) {
                case 0:
                    if ((x - p->home.x) * (x - p->home.x) + (z - p->home.z) * (z - p->home.z) <= 22500.0) {
                        p->speed = 10;
                        p->intro = 1;
                        func_80019B9C_1A79C(obj, 0x11);
                        p->unk_38 = HuMathSin(a) * 0.7 * 100.0;
                        p->unk_40 = func_800B7890_B8490(a) * 0.7 * 100.0;
                        func_80079798_7A398(D_8010C248_137E38_HotRopeJump[gPlayers[w->unk_59].character], w->unk_57);
                    }
                    break;
                case 1:
                    func_800191D4_19DD4(obj, 4, x + p->unk_38, y, z + p->unk_40, 0.0f, a + 180.0f);
                    if ((x - p->home.x) * (x - p->home.x) + (z - p->home.z) * (z - p->home.z) <= 100.0) {
                        p->speed = 0;
                        p->intro = 2;
                        x = p->home.x;
                        y = p->home.y;
                        z = p->home.z;
                        p->state = 1;
                        func_801054E4_1310D4_HotRopeJump(obj, 0);
                    }
                    break;
                case 2:
                    func_80019114_19D14(obj->model[4]);
                    if (fabs(a) <= 2.0) {
                        D_8010C254_137E44_HotRopeJump |= 1 << w->unk_59;
                        a = 0.0f;
                    } else {
                        a = a - 2.0;
                    }
                    break;
            }
            x += HuMathSin(a) * p->speed;
            z += func_800B7890_B8490(a) * p->speed;
            if (D_8010C254_137E44_HotRopeJump == 0xF) {
                D_8010C118_137D08_HotRopeJump = 1;
            }
            break;
        case 3:
            if ((gPlayers[w->unk_59].flags & 1) && p->unk_0C < D_8010C144_137D34_HotRopeJump) {
                p->unk_0A = 1;
            }
            r = func_80105AB8_1316A8_HotRopeJump(obj);
            if (r == 1 && p->unk_00 == 0) {
                w->unk_38 = 60.0f;
                p->unk_00 = 1;
                p->unk_46 = 1;
                p->hit.x = x;
                p->hit.y = 0.0f;
                p->hit.z = z;
                p->state = 8;
                func_801054E4_1310D4_HotRopeJump(obj, 0x26);
                if (--D_80111338_13CF28_HotRopeJump < 2 && D_8010C140_137D30_HotRopeJump == 0) {
                    D_8010C118_137D08_HotRopeJump = 1;
                } else {
                    if (D_80111344_13CF34_HotRopeJump != 0 && D_80111338_13CF28_HotRopeJump >= 2) {
                        D_80111344_13CF34_HotRopeJump += 5;
                        if (D_80111344_13CF34_HotRopeJump >= 131) {
                            D_80111344_13CF34_HotRopeJump = 130;
                        }
                    }
                    if (!(gPlayers[w->unk_59].flags & 1)) {
                        D_80111334_13CF24_HotRopeJump--;
                    }
                    if (D_8011133C_13CF2C_HotRopeJump == w->unk_59 && D_8010C140_137D30_HotRopeJump != 0) {
                        D_8010C118_137D08_HotRopeJump = 1;
                    }
                }
                func_80079798_7A398(0x16D, w->unk_59);
                omVibrate(w->unk_59, 30, 0, 30);
                func_80079718_7A318(0x111, gPlayers[w->unk_59].character);
                break;
            }
            if (r != 0 && (gPlayers[w->unk_59].flags & 1)) {
                if ((D_8010C11A_137D0A_HotRopeJump != 0xF || (rand8() & 3)) && p->unk_0A == 0) {
                    trg |= 0x8000;
                }
                btn |= 0x8000;
            }
            if (btn & 0x8000) {
                if ((trg & 0x8000) && (p->state & 1)) {
                    if (func_801054E4_1310D4_HotRopeJump(obj, 6) != 0) {
                        w->unk_38 = -D_800BF7A4_C03A4 * 0.55;
                        p->state = 2;
                        cnt++;
                        func_80079798_7A398(D_8010C23C_137E2C_HotRopeJump[gPlayers[w->unk_59].character], w->unk_57);
                    }
                } else if (cnt != 0) {
                    if (cnt < 8) {
                        cnt++;
                        w->unk_38 = w->unk_38 - D_800BF7A4_C03A4 * 0.075;
                    } else {
                        cnt = 0;
                    }
                }
            } else {
                if (cnt != 0) {
                    cnt = 0;
                }
            }
            D_8010C228_137E18_HotRopeJump[w->unk_59] = cnt;
            break;
        case 9:
        case 11:
            if ((func_80069538_6A138() & 2) && p->unk_00 == 0 && (p->state & 1)) {
                a = D_800FD478_FE078;
                w->unk_3C = a;
                func_801054E4_1310D4_HotRopeJump(obj, 0xD);
                p->state = 0x10;
                func_800732B0_73EB0(D_80111350_13CF40_HotRopeJump[w->unk_59][0]);
            }
            break;
    }
    switch (p->state & 0xF) {
        case 2:
            v2 = w->unk_38 * w->unk_38;
            if (w->unk_38 >= 0.0f) {
                y += v2 * -35.0f;
            } else {
                y += v2 * 35.0f;
            }
            w->unk_38 += D_800BF7A8_C03A8;
            if (y <= 0.0) {
                w->unk_38 = 1000.0f;
                func_801054E4_1310D4_HotRopeJump(obj, 0x15);
                p->state = 4;
                y = 0.0f;
            }
            break;
        case 4:
            if (motEnd & 1) {
                func_801054E4_1310D4_HotRopeJump(obj, 0);
                p->state = 1;
            }
            break;
        case 8:
            y += w->unk_38;
            w->unk_38 = w->unk_38 - 5.0;
            if (p->state & 0x20) {
                x = pos.x + 30.0;
                a = func_800B75A8_B81A8(x - pos.x, z - pos.z);
                w->unk_3C = a;
            }
            if (y <= 0.0) {
                y = 0.0f;
                w->unk_38 = 40.0f;
                p->state |= 0x20;
                func_80079798_7A398(D_8010C230_137E20_HotRopeJump[p->unk_64], w->unk_57);
                if (p->unk_64 < 4) {
                    p->unk_64++;
                }
                if (x > 2000.0 || x < -1500.0) {
                    func_800298A4_2A4A4(obj->model[0], 4, 4);
                    func_800298A4_2A4A4(obj->model[1], 4, 4);
                    p->state = 0x400;
                }
            }
            if (!(p->unk_46 & 3)) {
                func_8010515C_130D4C_HotRopeJump(x, y, z);
            }
            p->unk_46 = (s16)(p->unk_46 + 1) % 240;
            break;
    }
    obj->trans.x = x;
    obj->trans.y = y;
    obj->trans.z = z;
    obj->rot.y = a;
    sc = 1.0 - y / 2000.0;
    func_80029714_2A314(obj->model[1], x, 0.0f, z);
    func_800297E8_2A3E8(obj->model[1], sc, sc, sc);
    func_8010530C_130EFC_HotRopeJump(obj, p);
    func_80019378_19F78(obj);
}

/* A burst of smoke where a hit player lands (MP1 func_800F8968). */
void func_8010515C_130D4C_HotRopeJump(f32 x, f32 y, f32 z) {
    s16 id;

    id = func_80105F80_131B70_HotRopeJump((s16)D_8011131C_13CF0C_HotRopeJump, 0x28);
    if (id != -1) {
        func_8010605C_131C4C_HotRopeJump(id, x, y, z);
        func_8010608C_131C7C_HotRopeJump(id, 3.0f, 3.0f, 1.0f);
        func_801060EC_131CDC_HotRopeJump(id, 0xC0, 0xC0, 0xC0, 0xFF);
        func_80106034_131C24_HotRopeJump(id, 4.0f);
    }
}

/* Starts motion slot `motion` of the player's model as a separate model motion (unk_6C), with the
   model's frame count borrowed from that motion's model. */
void func_80105214_130E04_HotRopeJump(omObjData* obj, s32 motion) {
    HRJPlayer* p;
    u8 save;

    p = func_80105D94_131984_HotRopeJump(obj);
    save = D_800FC834_FD434[obj->model[0]].unk02;
    D_800FC834_FD434[obj->model[0]].unk02 = D_800FC834_FD434[obj->motion[motion]].unk02;
    p->unk_6C = func_800231D8_23DD8(obj->model[0], 2);
    D_800FC834_FD434[obj->model[0]].unk02 = save;
    p->unk_68 = 0;
    p->unk_66 = D_800FC834_FD434[obj->motion[motion]].unk02;
}

/* Advances the separate motion two frames, holding its last frame.
   NON_MATCHING: retail converts the frame to unsigned through a double and loads obj->model[0]
   after the conversion (masked 10 with an f64 temporary) */
#ifdef NON_MATCHING
void func_8010530C_130EFC_HotRopeJump(omObjData* obj, HRJPlayer* p) {
    HmfModel* m;

    m = &D_800FC834_FD434[obj->model[0]];
    if (p->unk_68 == 1 && p->unk_6C != NULL) {
        m->unk40 += 2.0;
        if (p->unk_6C[0] <= m->unk40) {
            m->unk40 = p->unk_6C[0] - 1;
        }
        func_80023A08_24608(obj->model[0], p->unk_6C, (u16)m->unk40);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_8010530C_130EFC_HotRopeJump);
#endif

/* Copies consecutive matrices from src into the motion objects under hmf->unk84[idx] (nothing
   calls it). Retail passes the same src to a child tree as the parent's next part. */
void func_80105410_131000_HotRopeJump(HmfData* hmf, Vec* src, s16 idx) {
    HmfMotionObj* node;
    s32 i;
    s16 c;

    node = &hmf->unk84[idx];
    for (i = 0; i < node->unk00; i++) {
        c = node->unk50[i];
        if (c & 0x8000) {
            if (c != -1) {
                func_80105410_131000_HotRopeJump(hmf, src, c & 0x7FFF);
            }
        } else {
            func_80030CD4_318D4(node->unk58, (f32 (*)[4])src++);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_801054E4_1310D4_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80105570_131160_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80105694_131284_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_801057B4_1313A4_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80105AB8_1316A8_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80105CD4_1318C4_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80105D74_131964_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80105D94_131984_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80105DC0_1319B0_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80105F80_131B70_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80106034_131C24_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_8010605C_131C4C_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_8010608C_131C7C_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_801060BC_131CAC_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_801060EC_131CDC_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80106124_131D14_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_801061B0_131DA0_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80107424_133014_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_8010777C_13336C_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_8010781C_13340C_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_801078A4_133494_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80107928_133518_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80107A84_133674_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80107AE8_1336D8_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80107B4C_13373C_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80107CA4_133894_HotRopeJump);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0C_HotRopeJump/12E3F0", func_80107F54_133B44_HotRopeJump);
