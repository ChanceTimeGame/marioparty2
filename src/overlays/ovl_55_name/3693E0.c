#include "ovl_55.h"

/* .data (0x36B150-0x36B2E0) */
/* board 5, per character: MBPlayerModelCreate lists */
u32 D_8010C260_36B150_name_55[9] = {
    8, 0x20012, 0x20010, 0x20000, 0x20001, 0x20002, 0x20098, 0x20052,
    0x20050,
};
u32 D_8010C284_36B174_name_55[9] = {
    8, 0x30012, 0x30010, 0x30000, 0x30001, 0x30002, 0x30098, 0x30052,
    0x30050,
};
u32 D_8010C2A8_36B198_name_55[9] = {
    8, 0x70012, 0x70010, 0x70000, 0x70001, 0x70002, 0x70098, 0x70052,
    0x70050,
};
u32 D_8010C2CC_36B1BC_name_55[9] = {
    8, 0x40012, 0x40010, 0x40000, 0x40001, 0x40002, 0x40098, 0x40052,
    0x40050,
};
u32 D_8010C2F0_36B1E0_name_55[9] = {
    8, 0x50012, 0x50010, 0x50000, 0x50001, 0x50002, 0x50098, 0x50052,
    0x50050,
};
u32 D_8010C314_36B204_name_55[9] = {
    8, 0x60012, 0x60010, 0x60000, 0x60001, 0x60002, 0x60098, 0x60052,
    0x60050,
};
void* D_8010C338_36B228_name_55[6] = {
    D_8010C260_36B150_name_55, D_8010C284_36B174_name_55, D_8010C2A8_36B198_name_55, D_8010C2CC_36B1BC_name_55,
    D_8010C2F0_36B1E0_name_55, D_8010C314_36B204_name_55,
};
u32 D_8010C350_36B240_name_55[4] = {
    3, 0x800B3, 0x800B2, 0x800B3,
};
u32 D_8010C360_36B250_name_55[4] = {
    3, 0x80043, 0x80040, 0x80043,
};
Vec D_8010C370_36B260_name_55[2] = {
    { -20.0f, 0.0f, -80.0f },
    { 214.0f, 0.0f, 161.0f },
};
Vec D_8010C388_36B278_name_55 = { -10.0f, 0.0f, -125.0f };
Vec D_8010C394_36B284_name_55 = { -10.0f, 0.0f, 200.0f };
u32 D_8010C3A0_36B290_name_55[4] = {
    3, 0x8008D, 0x80092, 0x8008E,
};
s32 D_8010C3B0_36B2A0_name_55[7] = {
    0, 30, 60, 90, 0x78, 0x96, 0xAA,
};
Ovl55Item D_8010C3CC_36B2BC_name_55[6] = {
    { 0, 0, 0, 0x91 },
    { 0, 0, 0, 0x92 },
    { 0, 0, 0, 0x93 },
    { 0, 0, 0, 0x94 },
    { 0, 0, 0, 0x95 },
    { 0, 0, 0, 0x96 },
};

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

/* Board 5's explanation opening: the host (model 0x8008B) walks on with a queue of five items
   behind it in a random order (D_8010C3CC) and the board's host model (0x7B) at its end, all
   drifting along z; the host turns round to the queue, then forward again. START jumps to the
   end. Each model's pos is rewritten whole every frame (x and y with their own values). */
/* NON_MATCHING: one scheduling difference only: retail hoists &order[-1] before the item
   table's address out of the item-model loop, this C the other way round. */
#ifdef NON_MATCHING
void func_8010A804_3696F4_name_55(void) {
    MBModel* models[7];
    Ovl55Item* items;
    s16 order[5];
    s16 pool[6];
    s32 i;
    s32 j;
    s32 n; /* the random pick, later the camera pan's length */

    func_80029708_2A308(0);
    func_80050E00_51A00(37);
    HuPrcSleep(3);
    MBDCameraPos3DSet(&D_8010C370_36B260_name_55[0]);
    for (i = 0; i < 6; i++) {
        pool[i] = i;
    }
    for (j = 0; j < 5; ) {
        n = (u8)(rand8() % 6);
        if (pool[n] != -1) {
            order[j] = pool[n];
            pool[n] = -1;
            j++;
        }
    }
    models[0] = MBModelFileCreate(0x8008B, 13, 1.0f, 1.3f, D_8010C3A0_36B290_name_55);
    MBMotionSet(models[0], 0, 2);
    models[0]->pos.x = D_8010C388_36B278_name_55.x;
    models[0]->pos.y = D_8010C388_36B278_name_55.y;
    models[0]->pos.z = D_8010C388_36B278_name_55.z;
    func_80056658_57258(&models[0]->pos, &D_8010C394_36B284_name_55, &models[0]->rot);
    for (i = 1; i < 6; i++) {
        items = D_8010C3CC_36B2BC_name_55;
        models[i] = func_80043510_44110(items[order[i - 1]].model, NULL);
        func_80043DAC_449AC(models[i]);
    }
    models[6] = func_80043510_44110(0x7B, D_8010C350_36B240_name_55);
    MBMotionSet(models[6], 1, 2);
    for (i = 1; i < 7; i++) {
        models[i]->pos.x = models[0]->pos.x;
        models[i]->pos.y = models[0]->pos.y;
        models[i]->pos.z = models[0]->pos.z - D_8010C3B0_36B2A0_name_55[i] + -50.0f;
    }
    InitFadeIn(0, 16);
    for (i = 0; i < 36; i++) {
        models[0]->pos.x = models[0]->pos.x;
        models[0]->pos.y = models[0]->pos.y;
        models[0]->pos.z = models[0]->pos.z + 0.5f;
        for (j = 0; j < 7; j++) {
            models[j]->pos.x = models[j]->pos.x;
            models[j]->pos.y = models[j]->pos.y;
            models[j]->pos.z = models[j]->pos.z + 1.25f;
        }
        if (D_8010C568_36B458_name_55->work[0] == 1) {
            goto end;
        }
        HuPrcVSleep();
    }
    while (func_8005A7E8_5B3E8(models[0], &models[1]->pos, 15.0f) == 0) {
        for (j = 1; j < 7; j++) {
            models[j]->pos.x = models[j]->pos.x;
            models[j]->pos.y = models[j]->pos.y;
            models[j]->pos.z = models[j]->pos.z + 1.25f;
        }
        if (D_8010C568_36B458_name_55->work[0] == 1) {
            goto end;
        }
        HuPrcVSleep();
    }
    MBMotionShiftSet(models[0], -1, 0, 4, 2);
    for (i = 0; i < 30; i++) {
        for (j = 1; j < 7; j++) {
            models[j]->pos.x = models[j]->pos.x;
            models[j]->pos.y = models[j]->pos.y;
            models[j]->pos.z = models[j]->pos.z + 1.25f;
        }
        if (D_8010C568_36B458_name_55->work[0] == 1) {
            goto end;
        }
        HuPrcVSleep();
    }
    MBMotionShiftSet(models[0], 1, 0, 4, 2);
    while (func_8005A7E8_5B3E8(models[0], &D_8010C394_36B284_name_55, 15.0f) == 0) {
        for (j = 1; j < 7; j++) {
            models[j]->pos.x = models[j]->pos.x;
            models[j]->pos.y = models[j]->pos.y;
            models[j]->pos.z = models[j]->pos.z + 1.25f;
        }
        if (D_8010C568_36B458_name_55->work[0] == 1) {
            goto end;
        }
        HuPrcVSleep();
    }
    for (i = 0; i < 30; i++) {
        for (j = 0; j < 7; j++) {
            models[j]->pos.x = models[j]->pos.x;
            models[j]->pos.y = models[j]->pos.y;
            models[j]->pos.z = models[j]->pos.z + 1.25f;
        }
        if (D_8010C568_36B458_name_55->work[0] == 1) {
            goto end;
        }
        HuPrcVSleep();
    }
    if (D_8010C568_36B458_name_55->work[0] == 0) {
        func_80051500_52100();
        n = func_80059E7C_5AA7C(&D_8010C370_36B260_name_55[0], &D_8010C370_36B260_name_55[1], 2.5f) + 20;
        for (i = 0; i < n; i++) {
            for (j = 0; j < 7; j++) {
                models[j]->pos.x = models[j]->pos.x;
                models[j]->pos.y = models[j]->pos.y;
                models[j]->pos.z = models[j]->pos.z + 1.0f;
            }
            if (D_8010C568_36B458_name_55->work[0] == 1) {
                break;
            }
            HuPrcVSleep();
        }
    }
end:
    for (i = 0; i < 7; i++) {
        MBModelKill(models[i]);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3693E0", func_8010A804_3696F4_name_55);
#endif

/* Board 5's sign: two halves drop in from the top, a glow (spr[24], spr[25]) grows behind them,
   twenty sparkles (func_8010B444) rise, the halves roll apart and the glow drops down. */
/* NON_MATCHING: retail keeps two constant additions where they are written (file[i % 3 + 5]
   adds 5 before scaling; the sparkle x adds 118 to the random part before adding i * 4); GCC
   here folds the 5 into the load offset and reassociates the 118. */
#ifdef NON_MATCHING
void func_8010AE68_369D58_name_55(void) {
    Ovl55Sign5* sign;
    f32 rotL;
    f32 rotR;
    f32 scale;
    f32 t;
    s32 i;
    s32 n;

    sign = D_8010C570_36B460_name_55 = HuMemMemoryAllocPerm(sizeof(Ovl55Sign5));
    sign->file[0] = func_8001A2F8_1AEF8(0xA01BD);
    sign->file[1] = func_8001A2F8_1AEF8(0xA01BE);
    sign->file[2] = func_8001A2F8_1AEF8(0xA01BF);
    sign->file[3] = func_8001A2F8_1AEF8(0xA01BC);
    sign->file[4] = func_8001A2F8_1AEF8(0xA01C0);
    sign->file[5] = func_8001A2F8_1AEF8(0xA01C1);
    sign->file[6] = func_8001A2F8_1AEF8(0xA01C2);
    sign->file[7] = func_8001A2F8_1AEF8(0xA01C3);
    sign->spr[0] = func_8001AAAC_1B6AC(sign->file[0], 0, 1);
    sign->spr[1] = func_8001AAAC_1B6AC(sign->file[1], 0, 1);
    sign->spr[2] = func_8001AAAC_1B6AC(sign->file[2], 0, 1);
    sign->spr[3] = func_8001AAAC_1B6AC(sign->file[2], 0, 1);
    sign->spr[24] = func_8001AAAC_1B6AC(sign->file[4], 0, 1);
    sign->spr[25] = func_8001AAAC_1B6AC(sign->file[3], 0, 1);
    for (i = 0; i < 20; i++) {
        sign->spr[i + 4] = func_8001AAAC_1B6AC(sign->file[i % 3 + 5], 0, 2);
        espDispOff(sign->spr[i + 4]);
    }
    for (i = 0; i < 26; i++) {
        func_8001A708_1B308(sign->spr[i], 0x4008);
        func_8001A788_1B388(sign->spr[i], (u16)(i * 10 + 0x1000));
    }
    espDispOff(sign->spr[25]);
    espDispOff(sign->spr[24]);
    func_8001A708_1B308(sign->spr[3], 1);
    for (n = 100; n >= 0; n -= 10) {
        espPosSet(sign->spr[0], 132, 30 - n);
        espPosSet(sign->spr[1], 187, 30 - n);
        espPosSet(sign->spr[2], 135, 10 - n);
        espPosSet(sign->spr[3], 184, 10 - n);
        HuPrcVSleep();
    }
    rotR = 0.0f;
    rotL = 0.0f;
    scale = 0.6f;
    t = 0.0f;
    espDispOn(sign->spr[25]);
    espPosSet(sign->spr[25], 160, 50);
    espDispOn(sign->spr[24]);
    espPosSet(sign->spr[24], 160, 50);
    func_8001A91C_1B51C(sign->spr[24], scale, 1.0f);
    func_8001A91C_1B51C(sign->spr[25], scale, t);
    for (i = 0; i < 20; i++) {
        func_8010B444_36A334_name_55(sign->spr[i + 4], i * 4 + ((u8)(rand8() % 3) + 118), (u8)(rand8() % 41) + 30, (u8)(rand8() % 20) + 20.0f);
    }
    PlaySound(0x40A);
    for (i = 0; i < 4; i++) {
        func_8005A4EC_5B0EC(i, 2);
    }
    for (i = 0; i < 8; i++) {
        rotL -= 8.0f;
        rotR += 8.0f;
        func_8001A9C0_1B5C0(sign->spr[0], rotL);
        func_8001A9C0_1B5C0(sign->spr[1], rotR);
        scale += 0.05f;
        func_8001A91C_1B51C(sign->spr[24], scale, 1.0f);
        func_8001A91C_1B51C(sign->spr[25], scale, t);
        HuPrcVSleep();
    }
    for (i = 0; i < 5; i++) {
        t += 0.2f;
        func_8001A91C_1B51C(sign->spr[25], 1.0f, t);
        espPosSet(sign->spr[24], 160, t * 104.0f + 50.0f);
        HuPrcVSleep();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3693E0", func_8010AE68_369D58_name_55);
#endif

/* Board 5's sign is freed (from the overlay's exit, func_80102AE0). */
void func_8010B3B4_36A2A4_name_55(void) {
    Ovl55Sign5* sign;
    s32 i;

    if (D_8010C570_36B460_name_55 != NULL) {
        sign = D_8010C570_36B460_name_55;
        for (i = 0; i < 26; i++) {
            func_8001AC44_1B844(sign->spr[i]);
        }
        for (i = 0; i < 8; i++) {
            SprAnimKill(sign->file[i]);
        }
        HuMemMemoryFreePerm(D_8010C570_36B460_name_55);
        D_8010C570_36B460_name_55 = NULL;
    }
}

/* A sparkle: an object that moves sprite spr down by speed / 10 a frame (trans.z) until y 180. */
void func_8010B444_36A334_name_55(s16 spr, f32 x, f32 y, f32 speed) {
    omObjData* obj;

    obj = omAddObj(500, 0, 0, -1, func_8010B518_36A408_name_55);
    obj->trans.x = x;
    obj->trans.y = y;
    obj->trans.z = speed / 10.0f;
    obj->unk_10 = spr;
    espPosSet(spr, x, y);
    espDispOn(spr);
}

void func_8010B518_36A408_name_55(omObjData* obj) {
    u16 spr;

    spr = obj->unk_10;
    obj->trans.y += obj->trans.z;
    espPosSet(spr, obj->trans.x, obj->trans.y);
    if (obj->trans.y >= 180.0f) {
        espDispOff(spr);
        omDelObj(obj);
    }
}
