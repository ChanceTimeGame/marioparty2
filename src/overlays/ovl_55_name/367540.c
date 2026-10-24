#include "ovl_55.h"

/* .data (0x36AEA0-0x36B150) */
/* board 3, per character: MBPlayerModelCreate lists */
u32 D_8010BFB0_36AEA0_name_55[9] = {
    8, 0x20012, 0x20010, 0x20000, 0x20001, 0x20002, 0x20098, 0x20052,
    0x20050,
};
u32 D_8010BFD4_36AEC4_name_55[9] = {
    8, 0x30012, 0x30010, 0x30000, 0x30001, 0x30002, 0x30098, 0x30052,
    0x30050,
};
u32 D_8010BFF8_36AEE8_name_55[9] = {
    8, 0x70012, 0x70010, 0x70000, 0x70001, 0x70002, 0x70098, 0x70052,
    0x70050,
};
u32 D_8010C01C_36AF0C_name_55[9] = {
    8, 0x40012, 0x40010, 0x40000, 0x40001, 0x40002, 0x40098, 0x40052,
    0x40050,
};
u32 D_8010C040_36AF30_name_55[9] = {
    8, 0x50012, 0x50010, 0x50000, 0x50001, 0x50002, 0x50098, 0x50052,
    0x50050,
};
u32 D_8010C064_36AF54_name_55[9] = {
    8, 0x60012, 0x60010, 0x60000, 0x60001, 0x60002, 0x60098, 0x60052,
    0x60050,
};
void* D_8010C088_36AF78_name_55[6] = {
    D_8010BFB0_36AEA0_name_55, D_8010BFD4_36AEC4_name_55, D_8010BFF8_36AEE8_name_55, D_8010C01C_36AF0C_name_55,
    D_8010C040_36AF30_name_55, D_8010C064_36AF54_name_55,
};
u32 D_8010C0A0_36AF90_name_55[4] = {
    3, 0x8001E, 0x8001F, 0x8001D,
};
Vec D_8010C0B0_36AFA0_name_55[2] = {
    { 0.0f, 0.0f, -165.0f },
    { 214.0f, 0.0f, 161.0f },
};
u32 D_8010C0C8_36AFB8_name_55[6] = {
    3, 0x8008D, 0x80092, 0x8008E, 0, 0,
};
/* board 4, per character: MBPlayerModelCreate lists */
u32 D_8010C0E0_36AFD0_name_55[9] = {
    8, 0x20012, 0x20010, 0x20000, 0x20001, 0x20002, 0x20098, 0x20052,
    0x20050,
};
u32 D_8010C104_36AFF4_name_55[9] = {
    8, 0x30012, 0x30010, 0x30000, 0x30001, 0x30002, 0x30098, 0x30052,
    0x30050,
};
u32 D_8010C128_36B018_name_55[9] = {
    8, 0x70012, 0x70010, 0x70000, 0x70001, 0x70002, 0x70098, 0x70052,
    0x70050,
};
u32 D_8010C14C_36B03C_name_55[9] = {
    8, 0x40012, 0x40010, 0x40000, 0x40001, 0x40002, 0x40098, 0x40052,
    0x40050,
};
u32 D_8010C170_36B060_name_55[9] = {
    8, 0x50012, 0x50010, 0x50000, 0x50001, 0x50002, 0x50098, 0x50052,
    0x50050,
};
u32 D_8010C194_36B084_name_55[9] = {
    8, 0x60012, 0x60010, 0x60000, 0x60001, 0x60002, 0x60098, 0x60052,
    0x60050,
};
void* D_8010C1B8_36B0A8_name_55[6] = {
    D_8010C0E0_36AFD0_name_55, D_8010C104_36AFF4_name_55, D_8010C128_36B018_name_55, D_8010C14C_36B03C_name_55,
    D_8010C170_36B060_name_55, D_8010C194_36B084_name_55,
};
u32 D_8010C1D0_36B0C0_name_55[4] = {
    3, 0x80025, 0x80024, 0x80024,
};
Vec D_8010C1E0_36B0D0_name_55[2] = {
    { 75.0f, 0.0f, -105.0f },
    { 214.0f, 0.0f, 161.0f },
};
Vec D_8010C1F8_36B0E8_name_55 = { 53.0f, 0.0f, -66.0f };
Vec D_8010C204_36B0F4_name_55 = { 43.0f, 0.0f, -116.0f };
Vec D_8010C210_36B100_name_55 = { 350.0f, 0.0f, 35.0f };
u32 D_8010C21C_36B10C_name_55[4] = {
    3, 0x8008D, 0x80092, 0x8008E,
};
f32 D_8010C22C_36B11C_name_55[12] = {
    -260.0f, -213.0f, -166.0f, -119.0f, -72.0f, 25.0f, 72.0f, 119.0f,
    166.0f, 213.0f, 260.0f, 0.0f,
};

/* Board 3's scene setup: the players' and the host's models. */
void func_80108650_367540_name_55(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        gPlayers[i].unk_24 = func_80043510_44110((u8)(gPlayers[i].character + 15), D_8010C088_36AF78_name_55[gPlayers[i].character]);
        func_8005ABC0_5B7C0(&gPlayers[i], 2, 0);
        MBModelDispOff(PLAYER_MODEL(i));
    }
    D_8010C56C_36B45C_name_55 = MBModelFileCreate(0x8001C, 13, 0.8f, 0.8f, D_8010C0A0_36AF90_name_55);
    MBModelDispOff(D_8010C56C_36B45C_name_55);
    D_8010C564_36B454_name_55 = MBModelFileCreate(0x8001C, 13, 0.8f, 0.8f, D_8010C0A0_36AF90_name_55);
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
    host = MBModelFileCreate(0x8008B, 13, 1.0f, 1.3f, D_8010C0C8_36AFB8_name_55);
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

/* Board 3's explanation sign: a sprite bobs in from the right while the host walks up and faces
   the camera, then the title fades in over it and a process scrolls a third sprite under it. */
void func_80108DB0_367CA0_name_55(void) {
    Ovl55Banner* banner;
    Process* proc;
    f32 angle;
    f32 x;
    f32 y;
    f32 dx;
    f32 dy;
    s32 i;
    u16 turned;

    turned = FALSE;
    banner = D_8010C570_36B460_name_55 = HuMemMemoryAllocPerm(sizeof(Ovl55Banner));
    banner->alpha = 0.0f;
    banner->scrollY = 26;
    banner->file[0] = func_8001A2F8_1AEF8(0xA01B8);
    banner->file[1] = func_8001A2F8_1AEF8(0xA01B9);
    banner->file[2] = func_8001A2F8_1AEF8(0xA01B7);
    for (i = 0; i < 3; i++) {
        banner->spr[i] = func_8001AAAC_1B6AC(banner->file[i], 0, 1);
        func_8001A708_1B308(banner->spr[i], 0x4000);
        func_8001A788_1B388(banner->spr[i], (u16)((i << 12) + 0x1000));
        espDispOff(banner->spr[i]);
    }
    func_8001A6BC_1B2BC(banner->spr[1], 178);
    x = 340.0f;
    y = -30.0f;
    espPosSet(banner->spr[0], 340, -30);
    espDispOn(banner->spr[0]);
    MBMotionShiftSet(D_8010C56C_36B45C_name_55, 2, 0, 5, 2);
    PlaySound(0x3BB);
    dx = -3.0f;
    dy = 3.0f;
    angle = 0.0f;
    for (i = 0; i < 60; i++) {
        x += dx + HuMathSin(angle) * 8.0f;
        angle -= 12.0f;
        y += dy;
        if (angle <= -360.0f) {
            angle += 360.0f;
        }
        espPosSet(banner->spr[0], x, y);
        if (func_8005A5E8_5B1E8(D_8010C56C_36B45C_name_55, &D_8010BAD4_36A9C4_name_55, 30.0f) == 1) {
            if (func_8005A7E8_5B3E8(D_8010C56C_36B45C_name_55, &OVL55_CAMERA->pos, 12.0f) == 1) {
                if (!turned) {
                    MBMotionShiftSet(D_8010C56C_36B45C_name_55, 1, 0, 5, 2);
                    turned = TRUE;
                }
            }
        }
        HuPrcVSleep();
    }
    HuPrcSleep(10);
    espPosSet(banner->spr[2], 160, 90);
    func_8001A91C_1B51C(banner->spr[2], banner->alpha, 1.0f);
    espDispOn(banner->spr[2]);
    proc = omAddPrcObj(func_8010912C_36801C_name_55, 0x4FFF, 0x2000, 0);
    banner->proc = proc;
    proc->user_data = banner;
    PlaySound(0x3BD);
    for (i = 0; i < 10; i++) {
        banner->alpha += 0.1f;
        func_8001A91C_1B51C(banner->spr[2], banner->alpha, 1.0f);
        HuPrcVSleep();
    }
    for (i = 0; i < 4; i++) {
        func_8005A4EC_5B0EC(i, 1);
    }
    banner->alpha = 1.0f;
    func_8001A91C_1B51C(banner->spr[2], 1.0f, 1.0f);
}

/* Board 3's sign process: the middle sprite fades with the title and scrolls down, wrapping. */
void func_8010912C_36801C_name_55(void) {
    Ovl55Banner* banner = HuPrcCurrentGet()->user_data;

    espDispOn(banner->spr[1]);
    while (TRUE) {
        func_8001A91C_1B51C(banner->spr[1], banner->alpha, 1.0f);
        espPosSet(banner->spr[1], 160, banner->scrollY);
        if (++banner->scrollY >= 122) {
            banner->scrollY = 26;
        }
        HuPrcVSleep();
    }
}

/* Board 3's sign leaves: the title fades out, the sign slides off up-left (its angle is advanced
   but never used), then the sign's sprites and process are freed. */
void func_801091B4_3680A4_name_55(void) {
    Ovl55Banner* banner;
    f32 angle;
    f32 x;
    f32 y;
    f32 dx;
    f32 dy;
    s32 i;

    banner = D_8010C570_36B460_name_55;
    PlaySound(0x3BE);
    for (i = 0; i < 10; i++) {
        banner->alpha -= 0.1f;
        func_8001A91C_1B51C(banner->spr[2], banner->alpha, 1.0f);
        HuPrcVSleep();
    }
    banner->alpha = 0.0f;
    func_8001A91C_1B51C(banner->spr[2], banner->alpha, 1.0f);
    HuPrcSleep(10);
    x = 160.0f;
    y = 150.0f;
    dx = dy = -12.0f;
    angle = 0.0f;
    PlaySound(0x3BC);
    for (i = 0; i < 15; i++) {
        x += dx;
        angle += 53.8f;
        y += dy;
        if (angle >= 360.0f) {
            angle -= 360.0f;
        }
        espPosSet(banner->spr[0], x, y);
        HuPrcVSleep();
    }
    omDelPrcObj(banner->proc);
    for (i = 0; i < 3; i++) {
        func_8001AC44_1B844(banner->spr[i]);
        SprAnimKill(banner->file[i]);
    }
    HuMemMemoryFreePerm(D_8010C570_36B460_name_55);
    D_8010C570_36B460_name_55 = NULL;
}

/* Board 4's scene setup: the players' and the host's models. */
void func_80109380_368270_name_55(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        gPlayers[i].unk_24 = func_80043510_44110((u8)(gPlayers[i].character + 15), D_8010C1B8_36B0A8_name_55[gPlayers[i].character]);
        func_8005ABC0_5B7C0(&gPlayers[i], 2, 0);
        MBModelDispOff(PLAYER_MODEL(i));
    }
    D_8010C56C_36B45C_name_55 = MBModelFileCreate(0x80023, 13, 0.8f, 0.8f, D_8010C1D0_36B0C0_name_55);
    MBModelDispOff(D_8010C56C_36B45C_name_55);
    D_8010C564_36B454_name_55 = MBModelFileCreate(0x80023, 13, 0.8f, 0.8f, D_8010C1D0_36B0C0_name_55);
    func_8005AB50_5B750(D_8010C56C_36B45C_name_55, 2, 8, 0x80039);
    MBModelDispOff(D_8010C564_36B454_name_55);
}

/* Board 4: a player's model. */
void func_801094D0_3683C0_name_55(s32 player) {
    MBPlayerModelCreate(player, D_8010C1B8_36B0A8_name_55[gPlayers[player].character], 2);
    gPlayers[player].flags |= 2;
    func_8005ABC0_5B7C0(&gPlayers[player], 2, 0);
}

/* Board 4's title (80108830 with its own sprite). */
void func_80109560_368450_name_55(void) {
    f32 alpha;
    s32 n;

    func_80029708_2A308(1);
    func_8002CA48_2D648(255, 255, 255);
    D_8010C588_36B478_name_55 = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0xA01F6), 0, 1);
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

/* Board 4's explanation opening: the host walks on with a model (0x89) following it, turns to it,
   a beam (model 0x8B) drops on the host, which stretches up and vanishes; the beam lifts and the
   follower backs off. START jumps to the end. func_80056658 leaves a direction in rot, which the
   last loop uses. */
void func_801096C0_3685B0_name_55(void) {
    MBModel* host;
    MBModel* follower;
    MBModel* beam;
    f32 t;
    s32 n;
    s32 len;

    beam = NULL;
    func_80029708_2A308(0);
    func_80050E00_51A00(30);
    HuPrcSleep(3);
    MBDCameraPos3DSet(&D_8010C1E0_36B0D0_name_55[0]);
    host = MBModelFileCreate(0x8008B, 13, 1.0f, 1.3f, D_8010C21C_36B10C_name_55);
    MBMotionSet(host, 0, 2);
    host->pos.x = D_8010C1F8_36B0E8_name_55.x;
    host->pos.y = D_8010C1F8_36B0E8_name_55.y;
    host->pos.z = D_8010C1F8_36B0E8_name_55.z;
    func_80056658_57258(&host->pos, &D_8010C204_36B0F4_name_55, &host->rot);
    follower = func_80043510_44110(0x89, NULL);
    follower->pos.x = D_8010C210_36B100_name_55.x;
    follower->pos.y = D_8010C210_36B100_name_55.y;
    follower->pos.z = D_8010C210_36B100_name_55.z;
    func_80056658_57258(&follower->pos, &host->pos, &follower->rot);
    follower->rot.x = -follower->rot.x;
    follower->rot.y = -follower->rot.y;
    follower->rot.z = -follower->rot.z;
    InitFadeIn(0, 16);
    for (n = 0; n < 26; n++) {
        func_8005A5E8_5B1E8(host, &D_8010C204_36B0F4_name_55, 1.0f);
        func_8005A608_5B208(follower, &host->pos, 6.0f);
        if (D_8010C568_36B458_name_55->work[0] == 1) {
            goto end;
        }
        HuPrcVSleep();
    }
    while (func_8005A7E8_5B3E8(host, &follower->pos, 20.0f) != 1) {
        func_8005A608_5B208(follower, &host->pos, 6.0f);
        if (D_8010C568_36B458_name_55->work[0] == 1) {
            goto end;
        }
        HuPrcVSleep();
    }
    MBMotionShiftSet(host, -1, 0, 3, 2);
    while (func_8005A608_5B208(follower, &host->pos, 6.0f) != 1) {
        if (D_8010C568_36B458_name_55->work[0] == 1) {
            goto end;
        }
        HuPrcVSleep();
    }
    beam = func_80043510_44110(0x8B, NULL);
    func_800B3170_B3D70(&beam->pos, &host->pos);
    HuVecCopyXYZ(&beam->scale, 0.05f, 1.8f, 0.05f);
    for (n = 100; n >= 0; n -= 10) {
        beam->jumpY = n;
        if (D_8010C568_36B458_name_55->work[0] == 1) {
            goto end;
        }
        HuPrcVSleep();
    }
    for (n = 2; n < 30; n++) {
        if (n == 10) {
            MBMotionShiftSet(host, 1, 0, 4, 2);
        }
        t = n / 30.0f;
        HuVecCopyXYZ(&beam->scale, t, 1.8f, t);
        if (D_8010C568_36B458_name_55->work[0] == 1) {
            goto end;
        }
        HuPrcVSleep();
    }
    HuVecCopyXYZ(&beam->scale, 1.0f, 1.8f, 1.0f);
    for (n = 0; n < 15; n++) {
        t = n / 15.0f;
        host->scale.x = 1.0f - t;
        host->scale.y = t + 1.0f;
        host->scale.z = 1.0f - t;
        host->jumpY += 6.0f;
        if (D_8010C568_36B458_name_55->work[0] == 1) {
            goto end;
        }
        HuPrcVSleep();
    }
    MBModelDispOff(host);
    for (n = 30; n > 0; n--) {
        t = n / 30.0f;
        HuVecCopyXYZ(&beam->scale, t, 1.8f, t);
        if (D_8010C568_36B458_name_55->work[0] == 1) {
            goto end;
        }
        HuPrcVSleep();
    }
    for (n = 0; n <= 100; n += 10) {
        beam->jumpY = n;
        if (D_8010C568_36B458_name_55->work[0] == 1) {
            goto end;
        }
        HuPrcVSleep();
    }
    for (n = 0; n < 30; n++) {
        follower->pos.x += -follower->rot.x * 12.0f;
        follower->pos.y += -follower->rot.y * 12.0f;
        follower->pos.z += -follower->rot.z * 12.0f;
        if (D_8010C568_36B458_name_55->work[0] == 1) {
            goto end;
        }
        HuPrcVSleep();
    }
    if (D_8010C568_36B458_name_55->work[0] == 0) {
        func_80051500_52100();
        len = func_80059E7C_5AA7C(&D_8010C1E0_36B0D0_name_55[0], &D_8010C1E0_36B0D0_name_55[1], 3.0f) + 20;
        for (n = 0; n < len; n++) {
            if (D_8010C568_36B458_name_55->work[0] == 1) {
                break;
            }
            HuPrcVSleep();
        }
    }
end:
    if (beam != NULL) {
        MBModelKill(beam);
    }
    MBModelKill(host);
    MBModelKill(follower);
}

/* Board 4's sign rises from the bottom while the screen shakes (pads rumble every 15 frames) and
   the bubble object starts. Retail zeroes the saved screen offset before restoring it. */
void func_80109C58_368B48_name_55(void) {
    Vec2f cur;
    Vec2f saved;
    Ovl55Sign4* sign;
    f32 shake;
    f32 dir;
    s32 timer;
    s32 i;
    s32 j;
    s32 y;

    dir = 1.0f;
    sign = D_8010C570_36B460_name_55 = HuMemMemoryAllocPerm(sizeof(Ovl55Sign4));
    sign->file[0] = func_8001A2F8_1AEF8(0xA01BA);
    sign->file[1] = func_8001A2F8_1AEF8(0xA01BB);
    for (i = 0; i < 2; i++) {
        sign->spr[i] = func_8001AAAC_1B6AC(sign->file[i], 0, 1);
        func_8001A708_1B308(sign->spr[i], 0x4000);
        func_8001A788_1B388(sign->spr[i], (u16)(0x3000 - (i << 12)));
        espDispOff(sign->spr[i]);
    }
    SprAttrReset(((Ovl55EspSlot*)D_800F93FC_F9FFC)[sign->spr[1]].grp, 0, 0x1000);
    timer = 0;
    espDispOn(sign->spr[1]);
    y = 224;
    espDispOn(sign->spr[0]);
    espPosSet(sign->spr[1], 160, 196);
    espPosSet(sign->spr[0], 160, 224);
    D_8010C550_36B440_name_55[0] = func_80109F30_368E20_name_55();
    func_800537A0_543A0(&saved);
    saved.unk_00 = saved.unk_04 = 0.0f;
    PlaySound(0x3EC);
    while (y > 96) {
        if (timer == 0) {
            for (j = 0; j < 4; j++) {
                func_8005A4EC_5B0EC(j, 2);
            }
            timer = 15;
        } else {
            timer--;
        }
        cur = saved;
        if (dir >= 0.0f) {
            shake = ((rand8() & 1) + 1) * dir;
        } else {
            shake = -shake;
        }
        dir = -dir;
        cur.unk_04 -= shake;
        func_80054040_54C40(cur.unk_00, cur.unk_04);
        espPosSet(sign->spr[0], 160, y + shake);
        espPosSet(sign->spr[1], 160, shake + 196.0f);
        y -= 2;
        HuPrcVSleep();
    }
    espPosSet(sign->spr[0], 160, 96);
    espPosSet(sign->spr[1], 160, 196);
    func_800536E4_542E4(&saved);
    D_8010C550_36B440_name_55[0]->work[1] = 0;
    PlaySound(0x3FE);
}

/* Board 4's bubbles: an object with twelve copies of one model (LoadFormFile 0xA015C). */
omObjData* func_80109F30_368E20_name_55(void) {
    omObjData* obj;
    Ovl55Bubbles* work;
    s32 i;

    obj = omAddObj(500, 13, 0, -1, func_8010A064_368F54_name_55);
    work = obj->unk_50 = func_80027154_27D54(sizeof(Ovl55Bubbles), 0x7918);
    obj->model[0] = -1;
    for (i = 1; i < 13; i++) {
        if (i == 1) {
            obj->model[1] = LoadFormFile(0xA015C, 0x6B9);
        } else {
            obj->model[i] = func_80027D3C_2893C(obj->model[1]);
        }
    }
    for (i = 0; i < 12; i++) {
        work->delay[i] = 1;
        work->scale[i] = 0.0f;
        func_800297E8_2A3E8(obj->model[i + 1], 0.0f, 0.0f, 1.0f);
    }
    obj->work[0] = 0;
    obj->work[1] = 1;
    return obj;
}

/* The bubbles: each grows to 2.0 and restarts after a random delay at a random x near its
   column (D_8010C22C); work[1] = 1 hides them, work[0] = 1 lets them finish, and the object
   deletes itself once all twelve are done. */
void func_8010A064_368F54_name_55(omObjData* obj) {
    Ovl55Bubbles* work;
    s32 done;
    s32 i;

    done = 0;
    work = obj->unk_50;
    for (i = 0; i < 12; i++) {
        if (obj->work[1] == 1) {
            func_800298A4_2A4A4(obj->model[i + 1], 4, 0);
        }
        if (work->delay[i] == 0) {
            work->scale[i] += 0.25f;
            if (work->scale[i] > 2.0f) {
                if (obj->work[0] == 0) {
                    work->scale[i] = 0.0f;
                    work->delay[i] = (u8)(rand8() % 3);
                }
                if (obj->work[1] == 0 || obj->work[0] == 1) {
                    func_800298A4_2A4A4(obj->model[i + 1], 4, 4);
                    done++;
                }
            }
            func_800297E8_2A3E8(obj->model[i + 1], work->scale[i], work->scale[i], 1.0f);
        } else if (--work->delay[i] == 0) {
            func_80029714_2A314(obj->model[i + 1], D_8010C22C_36B11C_name_55[i] + ((u8)(rand8() % 20) - 10.0f), 0.0f, 1250.0f);
        }
    }
    if (obj->work[0] == 1 && done == 12) {
        for (i = 0; i < 12; i++) {
            func_800283DC_28FDC(obj->model[i + 1]);
        }
        omDelObj(obj);
    }
}

/* Board 4's sign sinks back while the screen shakes; the bubbles finish (work[0] = 1) and the
   sign's first sprite is freed (retail leaves the second). */
void func_8010A2E0_3691D0_name_55(void) {
    Vec2f cur;
    Vec2f saved;
    Ovl55Sign4* sign;
    f32 shake;
    f32 dir;
    s32 timer;
    s32 j;
    s32 y;

    dir = 1.0f;
    sign = D_8010C570_36B460_name_55;
    D_8010C550_36B440_name_55[0]->work[1] = 1;
    func_800537A0_543A0(&saved);
    PlaySound(0x3ED);
    timer = 0;
    for (y = 96; y < 224; y += 2) {
        if (timer == 0) {
            for (j = 0; j < 4; j++) {
                func_8005A4EC_5B0EC(j, 2);
            }
            timer = 15;
        } else {
            timer--;
        }
        cur = saved;
        if (dir >= 0.0f) {
            shake = ((rand8() & 1) + 1) * dir;
        } else {
            shake = -shake;
        }
        dir = -dir;
        cur.unk_04 += shake;
        func_80054040_54C40(cur.unk_00, cur.unk_04);
        espPosSet(sign->spr[0], 160, y - shake);
        espPosSet(sign->spr[1], 160, 196.0f - shake);
        HuPrcVSleep();
    }
    espPosSet(sign->spr[0], 160, 224);
    espPosSet(sign->spr[1], 160, 196);
    func_800536E4_542E4(&saved);
    D_8010C550_36B440_name_55[0]->work[0] = 1;
    PlaySound(0x3FE);
    func_8001AC44_1B844(sign->spr[0]);
    SprAnimKill(sign->file[0]);
    HuMemMemoryFreePerm(D_8010C570_36B460_name_55);
    D_8010C570_36B460_name_55 = NULL;
}
