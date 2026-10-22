#include "ovl_55.h"

/* Board 3's scene setup: the players' and the host's models. */
void func_80108650_367540_name_55(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        gPlayers[i].unk_24 = func_80043510_44110((u8)(gPlayers[i].character + 15), D_8010C088_36AF78_name_55[gPlayers[i].character]);
        func_8005ABC0_5B7C0(&gPlayers[i], 2, 0);
        MBModelDispOff(PLAYER_MODEL(i));
    }
    D_8010C56C_36B45C_name_55 = MBModelFileCreate(0x8001C, 13, 0.8f, 0.8f, (u32*)D_8010C0A0_36AF90_name_55);
    MBModelDispOff(D_8010C56C_36B45C_name_55);
    D_8010C564_36B454_name_55 = MBModelFileCreate(0x8001C, 13, 0.8f, 0.8f, (u32*)D_8010C0A0_36AF90_name_55);
    func_8005AB50_5B750(D_8010C56C_36B45C_name_55, 2, 8, 0x80039);
    MBModelDispOff(D_8010C564_36B454_name_55);
}

/* Board 3: a player's model. */
void func_801087A0_367690_name_55(s32 player) {
    MBPlayerModelCreate(player, D_8010C088_36AF78_name_55[gPlayers[player].character], 2);
    gPlayers[player].flags |= 2;
    func_8005ABC0_5B7C0(&gPlayers[player], 2, 0);
}

/* Board 3's title: a sprite fades in over the white screen (START may skip from the fourth frame). */
void func_80108830_367720_name_55(void) {
    f32 alpha;
    s32 n;

    func_80029708_2A308(1);
    func_8002CA48_2D648(255, 255, 255);
    D_8010C588_36B478_name_55 = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0xA01F4), 0, 1);
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

/* Board 3's explanation opening: the host walks on (model 0x8008B) with an item (model 0x85)
   sliding in from the right, turns back and both leave left; START jumps to the end. */
void func_80108990_367880_name_55(void) {
    Vec target;
    MBModel* host;
    MBModel* item;
    f32 hostX, hostY, hostZ;
    f32 itemX, itemY, itemZ;
    s32 n;
    s32 len;

    func_80029708_2A308(0);
    func_80050E00_51A00(24);
    HuPrcSleep(3);
    MBDCameraPos3DSet(&D_8010C0B0_36AFA0_name_55[0]);
    host = MBModelFileCreate(0x8008B, 13, 1.0f, 1.3f, (u32*)D_8010C0C8_36AFB8_name_55);
    MBMotionSet(host, 0, 2);
    hostX = 0.0f;
    hostY = 0.0f;
    hostZ = -156.0f;
    host->pos.x = hostX;
    host->pos.y = hostY;
    host->pos.z = hostZ;
    target.x = 100.0f;
    target.y = hostY;
    target.z = hostZ;
    func_80056658_57258(&host->pos, &target, &host->rot);
    item = func_80043510_44110(0x85, NULL);
    item->jumpY = 5.0f;
    itemX = 150.0f;
    itemY = hostY;
    itemZ = hostZ;
    item->pos.x = itemX;
    item->pos.y = itemY;
    item->pos.z = itemZ;
    target.x = 50.0f;
    target.y = itemY;
    target.z = itemZ;
    func_80056658_57258(&item->pos, &target, &item->rot);
    InitFadeIn(0, 16);
    for (n = 0; n < 16; n++) {
        hostX += 2.0f;
        host->pos.x = hostX;
        host->pos.y = hostY;
        host->pos.z = hostZ;
        if (D_8010C568_36B458_name_55->work[0] == 1) {
            goto end;
        }
        HuPrcVSleep();
    }
    for (n = 0; n < 10; n++) {
        hostX += 2.0f;
        host->pos.x = hostX;
        host->pos.y = hostY;
        host->pos.z = hostZ;
        if (D_8010C568_36B458_name_55->work[0] == 1) {
            goto end;
        }
        HuPrcVSleep();
    }
    for (n = 0; n < 6; n++) {
        hostX += 2.0f;
        host->pos.x = hostX;
        host->pos.y = hostY;
        host->pos.z = hostZ;
        itemX -= 4.0f;
        item->pos.x = itemX;
        item->pos.y = itemY;
        item->pos.z = itemZ;
        if (D_8010C568_36B458_name_55->work[0] == 1) {
            goto end;
        }
        HuPrcVSleep();
    }
    MBMotionShiftSet(host, 1, 0, 5, 2);
    for (n = 0; n < 8; n++) {
        itemX -= 4.0f;
        item->pos.x = itemX;
        item->pos.y = itemY;
        item->pos.z = itemZ;
        if (D_8010C568_36B458_name_55->work[0] == 1) {
            goto end;
        }
        HuPrcVSleep();
    }
    target.x = hostX - 100.0f;
    target.y = hostY;
    target.z = hostZ;
    func_80056658_57258(&host->pos, &target, &host->rot);
    MBMotionShiftSet(host, 2, 0, 2, 2);
    for (n = 0; n < 23; n++) {
        hostX -= 4.0f;
        host->pos.x = hostX;
        host->pos.y = hostY;
        host->pos.z = hostZ;
        itemX -= 4.0f;
        item->pos.x = itemX;
        item->pos.y = itemY;
        item->pos.z = itemZ;
        if (D_8010C568_36B458_name_55->work[0] == 1) {
            goto end;
        }
        HuPrcVSleep();
    }
    if (D_8010C568_36B458_name_55->work[0] == 0) {
        func_80051500_52100();
        len = func_80059E7C_5AA7C(&D_8010C0B0_36AFA0_name_55[0], &D_8010C0B0_36AFA0_name_55[1], 3.0f) + 20;
        for (n = 0; n < len; n++) {
            hostX -= 4.0f;
            host->pos.x = hostX;
            host->pos.y = hostY;
            host->pos.z = hostZ;
            itemX -= 4.0f;
            item->pos.x = itemX;
            item->pos.y = itemY;
            item->pos.z = itemZ;
            if (D_8010C568_36B458_name_55->work[0] == 1) {
                break;
            }
            HuPrcVSleep();
        }
    }
end:
    MBModelKill(host);
    MBModelKill(item);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/367540", func_80108DB0_367CA0_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/367540", func_8010912C_36801C_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/367540", func_801091B4_3680A4_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/367540", func_80109380_368270_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/367540", func_801094D0_3683C0_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/367540", func_80109560_368450_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/367540", func_801096C0_3685B0_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/367540", func_80109C58_368B48_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/367540", func_80109F30_368E20_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/367540", func_8010A064_368F54_name_55);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_55_name/367540", func_8010A2E0_3691D0_name_55);
