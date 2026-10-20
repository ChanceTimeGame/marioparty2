#include "common.h"
#include "game/malloc.h"
#include "game/board.h"

/* Direction choice arrows and prompt (MP1 src/3C420.c; the stick-selection process from MP3
   ovl_80_shared_board/EAB00.c). Board models are MBModel (MP1's Object view of them). */

typedef struct unk_ProcessUserData08 {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ char unk02[2];
    /* 0x04 */ MBModel* unk04;
} unk_ProcessUserData08;

typedef struct unk_8003B8D4Struct {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02; // number of choices
    /* 0x04 */ unk_ProcessUserData08** unk04; // choice arrows
    /* 0x08 */ Process* unk08;
    /* 0x0C */ s16 unk0C; // current choice
    /* 0x0E */ s16 unk0E; // controller port
    /* 0x10 */ OSMesgQueue unk10;
    /* 0x28 */ OSMesg unk28[16];
    /* 0x68 */ GW_PLAYER* unk68;
} unk_8003B8D4Struct;

extern s8 ContStkX[4];
extern s8 ContStkY[4];
extern u16 ContDStkTrg[4];

GW_PLAYER* BoardPlayerGet(s32);
void HuVecAdd(Vec*, Vec*, Vec*);
void HuVecSubtract(Vec*, Vec*, Vec*);
void HuVecMulScalar(Vec*, f32, Vec*);
MBModel* func_80043510_44110(s32, void*);
void func_800298A4_2A4A4(s16, s32, s32);
void func_80029A8C_2A68C(s16);
void func_80029F2C_2AB2C(s16, s32);
void MBModelKill(void*);
s16 func_800569B8_575B8(s16, f32);
f32 func_800431FC_43DFC(Vec*, Vec*);
void func_80056658_57258(Vec*, Vec*, Vec*);
void func_800B3170_B3D70(Vec*, Vec*);
unk_8003B8D4Struct* func_800419A4_425A4(s16, s16*, s32);
SpaceData* GetSpaceData(s16);
void PlaySound(s32);
void HuVecCopyXYZ(Vec*, f32, f32, f32);
f32 func_800B7890_B8490(f32);
unk_8003B8D4Struct* func_80041058_41C58(void);
void func_80041118_41D18(unk_8003B8D4Struct*, unk_ProcessUserData08*, s16);
void func_80041924_42524(unk_ProcessUserData08*, Vec*, Vec*, f32);
extern s16 D_800FA198_FAD98;
extern s16 D_80101058_101C58;
void func_800412CC_41ECC(void);
s32 func_80041610_42210(unk_8003B8D4Struct*, s32);
unk_ProcessUserData08* func_800412B4_41EB4(unk_8003B8D4Struct*, s16);
void func_80041640_42240(void);

/* same c: marioparty func_8003B820 (src/3C420.c) */
unk_ProcessUserData08* func_80040F20_41B20() {
    MBModel* temp_v0_2;
    unk_ProcessUserData08* temp_v0;

    temp_v0 = HuMemMemoryAllocTemp(sizeof(*temp_v0)); /* 8 on the N64; a pointer field */
    temp_v0->unk00 = 0;
    temp_v0_2 = func_80043510_44110(0x15, NULL);
    temp_v0->unk04 = temp_v0_2;
    func_800298A4_2A4A4(*temp_v0_2->obj->model, 0x180, 0);
    func_80029A8C_2A68C(*temp_v0->unk04->obj->model);
    func_80029F2C_2AB2C(*temp_v0->unk04->obj->model, 0x1400);
    return temp_v0;
}

/* same c: marioparty func_8003B820 (src/3C420.c) */
unk_ProcessUserData08* func_80040FA4_41BA4() {
    MBModel* temp_v0_2;
    unk_ProcessUserData08* temp_v0;

    temp_v0 = HuMemMemoryAllocTemp(sizeof(*temp_v0)); /* 8 on the N64; a pointer field */
    temp_v0->unk00 = 0;
    temp_v0_2 = func_80043510_44110(0x9F, NULL);
    temp_v0->unk04 = temp_v0_2;
    func_800298A4_2A4A4(*temp_v0_2->obj->model, 0x180, 0);
    func_80029A8C_2A68C(*temp_v0->unk04->obj->model);
    func_80029F2C_2AB2C(*temp_v0->unk04->obj->model, 0x1400);
    return temp_v0;
}

/* exact c: marioparty func_8003B8A4 (src/3C420.c) */
void func_80041028_41C28(unk_ProcessUserData08* arg0) {
    MBModelKill(arg0->unk04);
    HuMemMemoryFreeTemp(arg0);
}

/* exact c: marioparty func_8003B8D4 (src/3C420.c) */
unk_8003B8D4Struct* func_80041058_41C58(void) {
    unk_8003B8D4Struct* temp_v0;

    temp_v0 = HuMemMemoryAllocTemp(sizeof(*temp_v0)); /* 0x6C on the N64; pointers and a message queue */
    temp_v0->unk00 = 0;
    temp_v0->unk02 = 0;
    temp_v0->unk04 = 0;
    temp_v0->unk08 = 0;
    temp_v0->unk0C = 0;
    temp_v0->unk68 = 0;
    return temp_v0;
}

/* exact c: marioparty func_8003B908 (src/3C420.c) */
void func_8004108C_41C8C(unk_8003B8D4Struct* arg0) {
    Process* temp_a0_2;
    s16 temp_v0;
    s32 var_s0;
    unk_ProcessUserData08** var_s1;
    unk_ProcessUserData08* temp_a0;

    temp_v0 = arg0->unk02;
    if (temp_v0 != 0) {
        var_s1 = arg0->unk04;
        for (var_s0 = 0; var_s0 < arg0->unk02; var_s0++) {
            temp_a0 = *var_s1;
            var_s1++;
            func_80041028_41C28(temp_a0);
        }
        HuMemMemoryFreeTemp(arg0->unk04);
    }
    temp_a0_2 = arg0->unk08;
    if (temp_a0_2 != NULL) {
        omDelPrcObj(temp_a0_2);
    }
    HuMemMemoryFreeTemp(arg0);
}

/* exact c: marioparty func_8003B994 (src/3C420.c) */
void func_80041118_41D18(unk_8003B8D4Struct* arg0, unk_ProcessUserData08* arg1, s16 arg2) {
    unk_ProcessUserData08** temp_a0_2;
    unk_ProcessUserData08** temp_v0;
    unk_ProcessUserData08** temp_v0_2;
    unk_ProcessUserData08** var_a0;
    unk_ProcessUserData08** var_a1;
    s32 var_v1;
    u16 temp_a0;

    temp_a0 = arg0->unk02 + 1;
    arg0->unk02 = temp_a0;
    temp_v0 = HuMemMemoryAllocTemp((temp_a0 << 0x10) >> 0xE);
    temp_v0_2 = arg0->unk04;
    var_a0 = temp_v0;
    if (temp_v0_2 != NULL) {
        var_a1 = temp_v0_2;
        for (var_v1 = 0; var_v1 < (arg0->unk02 - 1); var_v1++) {
            *var_a0 = *var_a1;
            var_a1++;
            var_a0++;
        }
    }
    *var_a0 = arg1;
    temp_a0_2 = arg0->unk04;
    if (temp_a0_2 != NULL) {
        HuMemMemoryFreeTemp(temp_a0_2);
    }
    arg0->unk04 = temp_v0;
    arg1->unk00 = arg2;
    if (arg2 & 1) {
        arg0->unk0C = arg0->unk02 - 1;
    }
}

/* exact c: marioparty func_8003BA68 (src/3C420.c) */
void func_800411EC_41DEC(unk_8003B8D4Struct* arg0, unk_ProcessUserData08* arg1) {
    unk_ProcessUserData08** list;
    unk_ProcessUserData08** dst;
    unk_ProcessUserData08** src;
    s32 i;

    list = NULL;
    if (arg0->unk02 >= 2) {
        arg0->unk02--;
        list = HuMemMemoryAllocTemp(arg0->unk02 * sizeof(unk_ProcessUserData08*));
        dst = list;
        src = arg0->unk04;
        for (i = 0; i <= arg0->unk02; i++) {
            if (*src == arg1) {
                src++;
            } else {
                *dst = *src;
                src++;
                dst++;
            }
        }
    } else {
        arg0->unk02 = 0;
    }
    if (arg0->unk04 != NULL) {
        HuMemMemoryFreeTemp(arg0->unk04);
    }
    arg0->unk04 = list;
}

/* exact c: marioparty func_8003BB30 (src/3C420.c) */
unk_ProcessUserData08* func_800412B4_41EB4(unk_8003B8D4Struct* arg0, s16 arg1) {
    return arg0->unk04[arg1];
}

/* near MP1 func_8003BB48 (src/3C420.c, NON_MATCHING there): MP2 plays sounds 3/4/1 and clears
   two flags on a confirm. NON_MATCHING: the loop hoists 360.0f into $f24 (retail reloads it each
   pass) and fills the delay slot of the fade > 0 test; logic as retail. Its jump table stays in the
   data blob while this is asm. */
#ifdef NON_MATCHING
void func_800412CC_41ECC(void) {
    OSMesg msg;
    unk_8003B8D4Struct* w;
    f32 angle;
    f32 scale;
    s16 fade;
    s16 repeat;
    s16 prev;
    s32 ret;
    s32 i;

    fade = -1;
    w = HuPrcCurrentGet()->user_data;
    prev = w->unk0C;
    angle = 0.0f;
    repeat = 0;
    do {
        HuPrcVSleep();
        if (fade < 0) {
            if (repeat == 0) {
                if ((ret = osRecvMesg(&w->unk10, &msg, OS_MESG_NOBLOCK)) == -1) {
                    msg = (OSMesg)ret;
                }
                if (w->unk00 & 1) {
                    repeat = 8;
                }
            } else {
                msg = (OSMesg)-1;
                repeat--;
            }
            switch ((s32)msg) {
                case -2:
                    w->unk0C++;
                    if (w->unk0C >= w->unk02) {
                        w->unk0C = 0;
                    }
                    break;
                case -3:
                    w->unk0C--;
                    if (w->unk0C < 0) {
                        w->unk0C = w->unk02 - 1;
                    }
                    break;
                case -4:
                    if (w->unk0C >= 0) {
                        PlaySound(3);
                        D_800FA198_FAD98 = 0;
                        D_80101058_101C58 = 0;
                        fade = 30;
                    }
                    break;
                case -5:
                    PlaySound(4);
                    w->unk0C = -1;
                    fade = 0;
                    break;
                case -6:
                    w->unk0C = -1;
                    break;
                case -1:
                    break;
                default:
                    if ((s32)msg < w->unk02) {
                        w->unk0C = (s32)msg;
                    }
                    break;
            }
            if (prev != w->unk0C) {
                PlaySound(1);
                if (prev >= 0) {
                    HuVecCopyXYZ(&func_800412B4_41EB4(w, prev)->unk04->scale, 1.0f, 1.0f, 1.0f);
                    angle = 0.0f;
                }
                prev = w->unk0C;
            }
        }
        if (prev >= 0) {
            if (fade >= 0) {
                angle += 50.0f;
            } else {
                angle += 15.0f;
            }
            if (angle > 360.0f) {
                angle -= 360.0f;
            }
            scale = func_800B7890_B8490(angle) * 0.3f + 1.2f;
            HuVecCopyXYZ(&func_800412B4_41EB4(w, prev)->unk04->scale, scale, 1.0f, scale);
        }
        if (fade > 0) {
            fade--;
            scale = fade * (1.0f / 30.0f);
            for (i = 0; i < w->unk02; i++) {
                if (i != prev) {
                    Vec* sc = &func_800412B4_41EB4(w, i)->unk04->scale;
                    HuVecMulScalar(sc, scale, sc);
                }
            }
        }
    } while (fade != 0);
    omDelPrcObj(NULL);
}
#else
INCLUDE_ASM("asm/nonmatchings/41B20", func_800412CC_41ECC);
#endif

/* exact c: marioparty func_8003BE84 (src/3C420.c) */
s32 func_80041610_42210(unk_8003B8D4Struct* arg0, s32 arg1) {
    if (arg0->unk08 != NULL) {
        return osSendMesg(&arg0->unk10, (OSMesg)arg1, OS_MESG_NOBLOCK);
    }
    return -1;
}

/* exact c: marioparty3 func_800D7280_EAEA0_shared_board (src/overlays/ovl_80_shared_board/EAB00.c) */
void func_80041640_42240(void) {
    Vec stick;
    Vec diff;
    unk_8003B8D4Struct* work;
    GW_PLAYER *player;
    s32 sel;
    s32 i;
    s16 run;

    run = 1;
    work = HuPrcCurrentGet()->user_data;
    player = work->unk68;
    sel = work->unk0C;

    while (run) {
        HuPrcVSleep();

        stick.x = ContStkX[work->unk0E];
        stick.z = ContStkY[work->unk0E];
        stick.z = -stick.z;
        stick.y = 0.0f;

        if (func_800569B8_575B8(work->unk0E, 40.0f) != 0) {
            for (i = 0; i < work->unk02; i++) {
                HuVecSubtract(&diff,
                              &func_800412B4_41EB4(work, i)->unk04->pos,
                              &((MBModel*)player->unk_24)->pos);
                diff.y = 0.0f;
                if (func_800431FC_43DFC(&stick, &diff) <= 38.0f) {
                    if (sel != i) {
                        sel = i;
                        func_80041610_42210(work, sel);
                    }
                    break;
                }
            }
        }

        if ((ContDStkTrg[work->unk0E] & 0x8000) && (sel >= 0)) {
            sel = -4;
            func_80041610_42210(work, sel);
            run = 0;
        }
    }
    omDelPrcObj(NULL);
}

/* exact c: marioparty func_8003C060 (src/3C420.c) */
s32 func_800417EC_423EC(unk_8003B8D4Struct* arg0, s16 arg1, s16 arg2) {
    GW_PLAYER* player;

    if (arg0->unk08 == NULL) {
        arg0->unk08 = omAddPrcObj(func_800412CC_41ECC, 0xEFFF, 0, 0);
        arg0->unk08->user_data = arg0;
        osCreateMesgQueue(&arg0->unk10, arg0->unk28, ARRAY_COUNT(arg0->unk28));
        arg0->unk00 |= arg2;
        player = BoardPlayerGet(arg1);
        if (player->flags & 1) {
            arg0->unk00 |= 1;
            func_80041610_42210(arg0, -1);
        } else {
            arg0->unk0E = player->port;
            omAddPrcObj(func_80041640_42240, 0xEFFF, 0, 0)->user_data = arg0;
        }
        return player->flags & 1;
    }
    return -1;
}

/* exact c: marioparty DirectionPrompt (src/3C420.c) */
s32 DirectionPrompt(unk_8003B8D4Struct* arg0) {
    if (arg0->unk08 != NULL) {
        HuPrcChildLink(HuPrcCurrentGet(), arg0->unk08);
        HuPrcChildWatch();
    }
    return arg0->unk0C;
}

/* exact c: marioparty func_8003C198 (src/3C420.c) */
void func_80041924_42524(unk_ProcessUserData08* arg0, Vec* arg1, Vec* arg2, f32 arg3) {
    Vec dir;

    func_80056658_57258(arg1, arg2, &dir);
    func_800B3170_B3D70(&arg0->unk04->rot, &dir);
    HuVecMulScalar(&dir, arg3, &dir);
    HuVecAdd(&arg0->unk04->pos, &dir, arg1);
}

/* near MP3 func_800D75E8_EB208_shared_board (EAB00.c): MP2 picks the arrow model by arg2. */
unk_8003B8D4Struct* func_800419A4_425A4(s16 arg0, s16* arg1, s32 arg2) {
    GW_PLAYER* player;
    unk_ProcessUserData08* arrow;
    unk_8003B8D4Struct* w;

    player = BoardPlayerGet(arg0);
    w = func_80041058_41C58();
    w->unk68 = player;
    for (; *arg1 >= 0; arg1++) {
        if (arg2 == 0) {
            arrow = func_80040F20_41B20();
        } else {
            arrow = func_80040FA4_41BA4();
        }
        func_80041924_42524(arrow, &((MBModel*)player->unk_24)->pos, &GetSpaceData(*arg1)->coords, 18.0f);
        func_80041118_41D18(w, arrow, 0);
    }
    return w;
}

/* exact c: marioparty3 func_800F25B4_1061D4_shared_board (src/overlays/ovl_80_shared_board/105D50.c) */
void func_80041A74_42674(s16 arg0, s16 *arg1) {
    func_800419A4_425A4(arg0, arg1, 0);
}

