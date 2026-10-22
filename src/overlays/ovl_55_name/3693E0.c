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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3693E0", func_8010AE68_369D58_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3693E0", func_8010B3B4_36A2A4_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3693E0", func_8010B444_36A334_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3693E0", func_8010B518_36A408_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3693E0", func_8010B5C0_36A4B0_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/3693E0", func_8010B6C0_36A5B0_name_55);
