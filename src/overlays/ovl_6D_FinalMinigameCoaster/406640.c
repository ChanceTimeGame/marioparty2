#include "ovl_6D.h"

#define HOST D_80106260_40A0A0_FinalMinigameCoaster[0]
#define CAR D_80106260_40A0A0_FinalMinigameCoaster[3]
#define HOST2 D_80106260_40A0A0_FinalMinigameCoaster[4]

void func_80102800_406640_FinalMinigameCoaster(void) {
    GwSystem.current_board_index = 7;
    omInitObjMan(50, 20);
    func_80106160_409FA0_FinalMinigameCoaster();
    func_80106018_409E58_FinalMinigameCoaster();
    func_80088640_89240();
    func_8005E570_5F170();
    omAddPrcObj(&func_80105CE8_409B28_FinalMinigameCoaster, 0x300U, 0x2000, 0);
    omAddObj(0x1000, 0, 0, -1, &func_80105FBC_409DFC_FinalMinigameCoaster);
    gPlayers[0].character = D_800FD8A8_FE4A8.unk00;
    gPlayers[1].character = D_800FD8A8_FE4A8.unk01;
    if (D_800FD8A8_FE4A8.unk04 == 2) {
        if (D_800CD414_CE014 == 0) {
            if (func_80075390_75F90(8) != 0) {
                PlayMusic(0x3D);
            } else {
                PlayMusic(0x13);
            }
        }
    } else {
        PlayMusic(15);
    }
}

void func_801028E0_406720_FinalMinigameCoaster(s16 arg0) {
    s32 thing = 1 << gPlayers[0].port;
    func_8008D59C_8E19C(arg0, thing);
}

/* One message box, centred plus x, wait for it, close it. */
void func_80102914_406754_FinalMinigameCoaster(s32 mess, s32 x, s32 y) {
    s16 size[2];
    s16 win;

    func_8008DACC_8E6CC(1, size, mess);
    win = func_8005AAC0_5B6C0(((0x140 - size[0]) / 2) + x, y, size[0], size[1]);
    func_800890CC_89CCC(win, (void*)mess, -1, -1);
    func_80089A48_8A648(win, 0);
    ShowTextWindow(win);
    func_80057730_58330(win, 0);
    func_8005762C_5822C(win);
}

/* The same with up to two string arguments. */
void func_801029C8_406808_FinalMinigameCoaster(s32 mess, s32 x, s32 y, char* str0, char* str1) {
    s16 size[2];
    s16 win;

    if (str0 != NULL) {
        func_8008D974_8E574(str0, 0);
    }
    if (str1 != NULL) {
        func_8008D974_8E574(str1, 1);
    }
    func_8008DACC_8E6CC(1, size, mess);
    win = func_8005AAC0_5B6C0(((0x140 - size[0]) / 2) + x, y, size[0], size[1]);
    if (str0 != NULL) {
        func_80089308_89F08(win, str0, 0);
    }
    if (str1 != NULL) {
        func_80089308_89F08(win, str1, 1);
    }
    func_800890CC_89CCC(win, (void*)mess, -1, -1);
    func_80089A48_8A648(win, 0);
    ShowTextWindow(win);
    func_80057730_58330(win, 0);
    func_8005762C_5822C(win);
}

/* Opens the box and returns its window; the caller drives and closes it. */
s16 func_80102AEC_40692C_FinalMinigameCoaster(s32 mess, s32 x, s32 y, char* str0, char* str1) {
    s16 size[2];
    s16 win;

    if (str0 != NULL) {
        func_8008D974_8E574(str0, 0);
    }
    if (str1 != NULL) {
        func_8008D974_8E574(str1, 1);
    }
    func_8008DACC_8E6CC(1, size, mess);
    win = func_8005AAC0_5B6C0(((0x140 - size[0]) / 2) + x, y, size[0], size[1]);
    if (str0 != NULL) {
        func_80089308_89F08(win, str0, 0);
    }
    if (str1 != NULL) {
        func_80089308_89F08(win, str1, 1);
    }
    func_800890CC_89CCC(win, (void*)mess, -1, -1);
    func_80089A48_8A648(win, 0);
    ShowTextWindow(win);
    return win;
}


/* The car (model 0xAB; the players ride its "point1"/"point2" hooks) arrives; they get off and
   face the host (model 0xA7). Hard mode also places three 0x7B models, hidden. */
void func_80102C00_406A40_FinalMinigameCoaster(void) {
    Vec vec;
    s32 i;
    Process* prc;

    if (D_800FD8A8_FE4A8.unk04 == 2) {
        for (i = 0; i < 3; i++) {
            D_80106260_40A0A0_FinalMinigameCoaster[i + 5] = func_80043510_44110(0x7B, D_80106470_40A2B0_FinalMinigameCoaster);
            func_80043DAC_449AC(D_80106260_40A0A0_FinalMinigameCoaster[i + 5]);
            func_800B3170_B3D70(&D_80106260_40A0A0_FinalMinigameCoaster[i + 5]->pos, &D_801062E8_40A128_FinalMinigameCoaster[i]);
            MBModelDispOff(D_80106260_40A0A0_FinalMinigameCoaster[i + 5]);
        }
    }
    CAR = func_80043510_44110(0xAB, NULL);
    func_80043DAC_449AC(CAR);
    func_800B3170_B3D70(&CAR->pos, &D_80106384_40A1C4_FinalMinigameCoaster);
    HuVecCopyXYZ(&CAR->rot, -1.0f, 0.0f, 0.0f);
    HOST = func_80043510_44110(0xA7, D_8010645C_40A29C_FinalMinigameCoaster);
    func_80043DAC_449AC(HOST);
    func_800B3170_B3D70(&HOST->pos, &D_801062AC_40A0EC_FinalMinigameCoaster);
    HuVecCopyXYZ(&HOST->rot, 1.0f, 0.0f, 0.0f);
    HuVecCopyXYZ(&HOST->scale, 0.8f, 0.8f, 0.8f);
    for (i = 0; i < 2; i++) {
        MBPlayerModelCreate(i, D_80106444_40A284_FinalMinigameCoaster[gPlayers[i].character], 2);
        HuVecCopyXYZ(&PLAYER_MODEL(i)->rot, -1.0f, 0.0f, 0.0f);
        PLAYER_MODEL(i)->attr |= 1;
    }
    func_8005AA48_5B648(CAR, "point1", PLAYER_MODEL(0)->obj->model[0]);
    func_8005AA48_5B648(CAR, "point2", PLAYER_MODEL(1)->obj->model[0]);
    InitFadeIn(2, 0x10);
    HuPrcSleep(0x10);
    PlaySound(0x456);
    prc = func_80056D80_57980(&CAR->pos, &D_80106390_40A1D0_FinalMinigameCoaster, &CAR->pos, 0x1E);
    HuPrcChildLink(HuPrcCurrentGet(), prc);
    HuPrcChildWatch();
    PlaySound(0x451);
    MBPlayerVibrate(-1, 2);
    func_80029E80_2AA80(CAR->obj->model[0], 2, 1);
    HuVecCopyXYZ(&PLAYER_MODEL(0)->pos, CAR->pos.x + -47.7895f, (CAR->pos.y * 5.0f) + 18.3945f, CAR->pos.z + 0.0f);
    HuVecCopyXYZ(&PLAYER_MODEL(1)->pos, CAR->pos.x + 41.230003f, (CAR->pos.y * 5.0f) + 18.3945f, CAR->pos.z + 0.0f);
    PLAYER_MODEL(0)->attr &= 0xFFFE;
    PLAYER_MODEL(1)->attr &= 0xFFFE;
    HuPrcVSleep();
    func_8005AA98_5B698(PLAYER_MODEL(0)->obj->model[0]);
    func_8005AA98_5B698(PLAYER_MODEL(1)->obj->model[0]);
    HuPrcVSleep();
    func_80059120_59D20(PLAYER_MODEL(0), 60.0f, -4.5f);
    func_80059120_59D20(PLAYER_MODEL(1), 60.0f, -4.5f);
    func_8005845C_5905C(0, &D_80106354_40A194_FinalMinigameCoaster, 0x18, PLAYER_MODEL(0));
    func_8005845C_5905C(0, &D_80106360_40A1A0_FinalMinigameCoaster, 0x18, PLAYER_MODEL(1));
    MBMotionSet(PLAYER_MODEL(0), 3, 0);
    MBMotionSet(PLAYER_MODEL(1), 3, 0);
    func_8005670C_5730C(&vec);
    prc = func_80056B78_57778(&PLAYER_MODEL(0)->rot, &vec, &PLAYER_MODEL(0)->rot, 0x18);
    HuPrcChildLink(HuPrcCurrentGet(), prc);
    prc = func_80056B78_57778(&PLAYER_MODEL(1)->rot, &vec, &PLAYER_MODEL(1)->rot, 0x18);
    HuPrcChildLink(HuPrcCurrentGet(), prc);
    HuPrcChildWatch();
    MBMotionShiftSet(PLAYER_MODEL(0), 0, 0, 0xA, 2);
    MBMotionShiftSet(PLAYER_MODEL(1), 0, 0, 0xA, 2);
    func_8005845C_5905C(0, &D_801062B8_40A0F8_FinalMinigameCoaster, 0x14, HOST);
    HuPrcSleep(0xA);
    func_80056658_57258(&PLAYER_MODEL(0)->pos, &HOST->pos, &vec);
    prc = func_80056B78_57778(&PLAYER_MODEL(0)->rot, &vec, &PLAYER_MODEL(0)->rot, 0xA);
    HuPrcChildLink(HuPrcCurrentGet(), prc);
    func_80056658_57258(&PLAYER_MODEL(1)->pos, &HOST->pos, &vec);
    prc = func_80056B78_57778(&PLAYER_MODEL(1)->rot, &vec, &PLAYER_MODEL(1)->rot, 0xA);
    HuPrcChildLink(HuPrcCurrentGet(), prc);
    HuPrcSleep(0xA);
    MBMotionSet(HOST, 1, 2);
}

/* A sprite (file 0x25) grows at the host and arcs to player 1; effect sprite 0x14 on landing. */
/* `scale` doubles as the x step: one retail register, and two locals do not match. */
void func_801031D0_407010_FinalMinigameCoaster(void) {
    Vec vec;
    Vec2fxy pos;
    Vec2fxy dest;
    Vec rot;
    CoasterSprite* spr;
    void* data;
    f32 scale;
    f32 dy;
    s32 i;
    Process* prc;

    PlaySound(0x355);
    MBMotionShiftSet(HOST, 3, 0, 0xA, 0);
    HuPrcSleep(0xA);
    spr = func_8005E688_5F288(2, 0);
    data = DataRead(0x25);
    spr->data[0] = SprAnimRead(data);
    DataClose(data);
    data = DataRead(0x14);
    spr->data[1] = SprAnimRead(data);
    DataClose(data);
    SprAnimSet(spr->group, 0, spr->data[0], 0);
    SprPrioSet(spr->group, 0, 0xA);
    SprAttrSet(spr->group, 0, 0x1000);
    SprScaleSet(spr->group, 0, 0.0f, 0.0f);
    func_800B3170_B3D70(&vec, &HOST->pos);
    MBDCamera3Dto2D(&vec, &pos);
    pos.y -= 48.0f;
    SprPosSet(spr->group, 0, pos.x, pos.y);
    for (scale = 0.0f; scale <= 1.0f; scale += 0.1f) {
        SprScaleSet(spr->group, 0, scale, scale);
        HuPrcVSleep();
    }
    SprScaleSet(spr->group, 0, 1.0f, 1.0f);
    HuPrcSleep(0xA);
    MBMotionShiftSet(HOST, 1, 0, 0xA, 2);
    func_800B3170_B3D70(&vec, &PLAYER_MODEL(0)->pos);
    MBDCamera3Dto2D(&vec, &dest);
    dest.y -= 48.0f;
    scale = (dest.x - pos.x) / 40.0f;
    dy = (dest.y - pos.y) / 40.0f;
    for (i = 0; i < 40; i++) {
        pos.x += scale;
        pos.y += dy;
        SprPosSet(spr->group, 0, pos.x, (pos.y - 16.0f) - (HuMathSin((i * 180) / 40) * 80.0f));
        HuPrcVSleep();
    }
    SprAttrSet(spr->group, 0, 0x8000);
    PlaySound(0x15);
    SprAnimSet(spr->group, 1, spr->data[1], 0);
    SprPosSet(spr->group, 1, dest.x, dest.y - 16.0f);
    SprPrioSet(spr->group, 1, 0xA);
    SprAttrSet(spr->group, 1, 0x1000);
    func_8008225C_82E5C(spr->group, 1, 1);
    func_80082450_83050(spr->group, 1, 0xFF, 0xFF, 0);
    SprScaleSet(spr->group, 1, 2.0f, 2.0f);
    func_8008221C_82E1C(spr->group, 1, 4.0f);
    HuPrcSleep(2);
    switch (D_800FD8A8_FE4A8.unk04) {
    case 0:
        MBPlayerVibrate(-1, 3);
        break;
    case 1:
        MBPlayerVibrate(-1, 4);
        break;
    case 2:
        MBPlayerVibrate(-1, 5);
        break;
    }
    func_80079718_7A318(0xF5, gPlayers[0].character);
    func_8005670C_5730C(&PLAYER_MODEL(0)->rot);
    MBMotionSet(PLAYER_MODEL(0), 4, 0);
    HuPrcSleep(0x12);
    HuMemDirectFree(spr);
    HuPrcSleep(0x34);
    MBMotionShiftSet(PLAYER_MODEL(0), 0, 0, 0xA, 2);
    func_80056658_57258(&PLAYER_MODEL(0)->pos, &HOST->pos, &rot);
    prc = func_80056B78_57778(&PLAYER_MODEL(0)->rot, &rot, &PLAYER_MODEL(0)->rot, 0xA);
    HuPrcChildLink(HuPrcCurrentGet(), prc);
    HuPrcChildWatch();
}

/* The same, after a message with the score: byte 3 x 100 + byte 0xD of D_800FD8A8, added to the
   coin bank (capped at 99999). Both zero: message 0x5C4 only. */
void func_8010370C_40754C_FinalMinigameCoaster(void) {
    Vec vec;
    Vec2fxy pos;
    Vec2fxy dest;
    Vec rot;
    char tens[8];
    char ones[8];
    char total[8];
    s16 size[2];
    CoasterSprite* spr;
    void* data;
    f32 scale;
    f32 dy;
    s32 i;
    s16 win;
    Process* prc;

    if (D_800FD8A8_FE4A8.unk02[1] == 0 && D_800FD8A8_FE4A8.unk05[8] == 0) {
        func_80102914_406754_FinalMinigameCoaster(0x5C4, 0, 0x3C);
        return;
    }
    sprintf(tens, "%d", D_800FD8A8_FE4A8.unk02[1]);
    sprintf(ones, "%d", D_800FD8A8_FE4A8.unk05[8]);
    sprintf(total, "%d", (D_800FD8A8_FE4A8.unk02[1] * 100) + D_800FD8A8_FE4A8.unk05[8]);
    D_800F8C60.coinNum += (D_800FD8A8_FE4A8.unk02[1] * 100) + D_800FD8A8_FE4A8.unk05[8];
    if (D_800F8C60.coinNum > 99999) {
        D_800F8C60.coinNum = 99999;
    }
    func_8008D974_8E574(tens, 0);
    func_8008D974_8E574(ones, 1);
    func_8008D974_8E574(total, 2);
    func_8008DACC_8E6CC(1, size, 0x5C3);
    win = func_8005AAC0_5B6C0((0x140 - size[0]) / 2, 0x3C, size[0], size[1]);
    func_80089308_89F08(win, tens, 0);
    func_80089308_89F08(win, ones, 1);
    func_80089308_89F08(win, total, 2);
    func_800890CC_89CCC(win, (void*)0x5C3, -1, -1);
    func_80089A48_8A648(win, 0);
    ShowTextWindow(win);
    func_80057730_58330(win, 0);
    func_8005762C_5822C(win);
    PlaySound(0x355);
    MBMotionShiftSet(HOST, 3, 0, 0xA, 0);
    HuPrcSleep(0xA);
    spr = func_8005E688_5F288(2, 0);
    data = DataRead(0x25);
    spr->data[0] = SprAnimRead(data);
    DataClose(data);
    data = DataRead(0x14);
    spr->data[1] = SprAnimRead(data);
    DataClose(data);
    SprAnimSet(spr->group, 0, spr->data[0], 0);
    SprPrioSet(spr->group, 0, 0xA);
    SprAttrSet(spr->group, 0, 0x1000);
    SprScaleSet(spr->group, 0, 0.0f, 0.0f);
    func_800B3170_B3D70(&vec, &HOST->pos);
    MBDCamera3Dto2D(&vec, &pos);
    pos.y -= 48.0f;
    SprPosSet(spr->group, 0, pos.x, pos.y);
    for (scale = 0.0f; scale <= 1.0f; scale += 0.1f) {
        SprScaleSet(spr->group, 0, scale, scale);
        HuPrcVSleep();
    }
    SprScaleSet(spr->group, 0, 1.0f, 1.0f);
    HuPrcSleep(0xA);
    MBMotionShiftSet(HOST, 1, 0, 0xA, 2);
    func_800B3170_B3D70(&vec, &PLAYER_MODEL(0)->pos);
    MBDCamera3Dto2D(&vec, &dest);
    dest.y -= 48.0f;
    scale = (dest.x - pos.x) / 40.0f;
    dy = (dest.y - pos.y) / 40.0f;
    for (i = 0; i < 40; i++) {
        pos.x += scale;
        pos.y += dy;
        SprPosSet(spr->group, 0, pos.x, (pos.y - 16.0f) - (HuMathSin((i * 180) / 40) * 80.0f));
        HuPrcVSleep();
    }
    SprAttrSet(spr->group, 0, 0x8000);
    PlaySound(0x15);
    SprAnimSet(spr->group, 1, spr->data[1], 0);
    SprPosSet(spr->group, 1, dest.x, dest.y - 16.0f);
    SprPrioSet(spr->group, 1, 0xA);
    SprAttrSet(spr->group, 1, 0x1000);
    func_8008225C_82E5C(spr->group, 1, 1);
    func_80082450_83050(spr->group, 1, 0xFF, 0xFF, 0);
    SprScaleSet(spr->group, 1, 2.0f, 2.0f);
    func_8008221C_82E1C(spr->group, 1, 4.0f);
    HuPrcSleep(2);
    switch (D_800FD8A8_FE4A8.unk04) {
    case 0:
        MBPlayerVibrate(-1, 3);
        break;
    case 1:
        MBPlayerVibrate(-1, 4);
        break;
    case 2:
        MBPlayerVibrate(-1, 5);
        break;
    }
    func_80079718_7A318(0xF5, gPlayers[0].character);
    func_8005670C_5730C(&PLAYER_MODEL(0)->rot);
    MBMotionSet(PLAYER_MODEL(0), 4, 0);
    HuPrcSleep(0x12);
    HuMemDirectFree(spr);
    HuPrcSleep(0x34);
    MBMotionShiftSet(PLAYER_MODEL(0), 0, 0, 0xA, 2);
    func_80056658_57258(&PLAYER_MODEL(0)->pos, &HOST->pos, &rot);
    prc = func_80056B78_57778(&PLAYER_MODEL(0)->rot, &rot, &PLAYER_MODEL(0)->rot, 0xA);
    HuPrcChildLink(HuPrcCurrentGet(), prc);
    HuPrcChildWatch();
}

/* The same flight with picture files[which] and a different landing sound. */
void func_80103E04_407C44_FinalMinigameCoaster(s32 which) {
    Vec vec;
    Vec2fxy pos;
    Vec2fxy dest;
    s32 files[2];
    CoasterSprite* spr;
    void* data;
    f32 scale;
    f32 dy;
    s32 i;

    files[0] = 0xA025D;
    files[1] = 0xA025C;
    PlaySound(0x355);
    MBMotionShiftSet(HOST, 3, 0, 0xA, 0);
    HuPrcSleep(0xA);
    spr = func_8005E688_5F288(2, 0);
    data = DataRead(files[which]);
    spr->data[0] = SprAnimRead(data);
    DataClose(data);
    data = DataRead(0x14);
    spr->data[1] = SprAnimRead(data);
    DataClose(data);
    SprAnimSet(spr->group, 0, spr->data[0], 0);
    SprPrioSet(spr->group, 0, 0xA);
    SprAttrSet(spr->group, 0, 0x1000);
    SprScaleSet(spr->group, 0, 0.0f, 0.0f);
    func_800B3170_B3D70(&vec, &HOST->pos);
    MBDCamera3Dto2D(&vec, &pos);
    pos.y -= 48.0f;
    SprPosSet(spr->group, 0, pos.x, pos.y);
    for (scale = 0.0f; scale <= 1.0f; scale += 0.1f) {
        SprScaleSet(spr->group, 0, scale, scale);
        HuPrcVSleep();
    }
    SprScaleSet(spr->group, 0, 1.0f, 1.0f);
    HuPrcSleep(0xA);
    MBMotionShiftSet(HOST, 1, 0, 0xA, 2);
    func_800B3170_B3D70(&vec, &PLAYER_MODEL(0)->pos);
    MBDCamera3Dto2D(&vec, &dest);
    dest.y -= 48.0f;
    scale = (dest.x - pos.x) / 40.0f;
    dy = (dest.y - pos.y) / 40.0f;
    for (i = 0; i < 40; i++) {
        pos.x += scale;
        pos.y += dy;
        SprPosSet(spr->group, 0, pos.x, (pos.y - 16.0f) - (HuMathSin((i * 180) / 40) * 80.0f));
        HuPrcVSleep();
    }
    SprAttrSet(spr->group, 0, 0x8000);
    MBPlayerVibrate(-1, 3);
    PlaySound(0x37D);
    SprAnimSet(spr->group, 1, spr->data[1], 0);
    SprPosSet(spr->group, 1, dest.x, dest.y - 16.0f);
    SprPrioSet(spr->group, 1, 0xA);
    SprAttrSet(spr->group, 1, 0x1000);
    func_8008225C_82E5C(spr->group, 1, 1);
    func_80082450_83050(spr->group, 1, 0xFF, 0xFF, 0);
    SprScaleSet(spr->group, 1, 2.0f, 2.0f);
    func_8008221C_82E1C(spr->group, 1, 4.0f);
    HuPrcSleep(0x14);
    HuMemDirectFree(spr);
}

void func_80104270_4080B0_FinalMinigameCoaster(void) {
    char name[4];

    PlaySound(0x11F);
    func_80102914_406754_FinalMinigameCoaster(0x595, 0, 0x3C);
    func_801031D0_407010_FinalMinigameCoaster();
    func_8010370C_40754C_FinalMinigameCoaster();
    name[0] = 0x18;
    name[1] = gPlayers[0].character;
    name[2] = 0;
    func_801029C8_406808_FinalMinigameCoaster(0x596, 0, 0x3C, name, NULL);
}

void func_801042DC_40811C_FinalMinigameCoaster(void) {
    PlaySound(0x11F);
    func_80102914_406754_FinalMinigameCoaster(0x597, 0, 0x3C);
    func_801031D0_407010_FinalMinigameCoaster();
    if (_CheckFlag(0x10) == 0) {
        func_80102914_406754_FinalMinigameCoaster(0x598, 0, 0x3C);
        func_80103E04_407C44_FinalMinigameCoaster(0);
        func_80102914_406754_FinalMinigameCoaster(0x599, 0, 0x3C);
    }
    func_8010370C_40754C_FinalMinigameCoaster();
    func_80102914_406754_FinalMinigameCoaster(D_8010647C_40A2BC_FinalMinigameCoaster[gPlayers[0].character], 0, 0x3C);
    func_80102914_406754_FinalMinigameCoaster(0x5A0, 0, 0x3C);
}

/* Hard, first time (flag 8 not yet set): a second 0xA7 model comes in, a big spinning model 0x6F
   covers the swap, the first host is replaced by the three 0x7B models. */
void func_80104380_4081C0_FinalMinigameCoaster(void) {
    char name[8];
    char arg[8];
    Vec vec;
    Process* prc;
    MBModel* fx;
    f32 rot;
    f32 scale;
    s16 win;
    s32 mess;
    s32 i;

    name[0] = 0x18;
    name[1] = gPlayers[0].character;
    name[2] = 0;
    PlaySound(0x11F);
    switch (rand8() & 3) {
    case 0:
        win = func_80102AEC_40692C_FinalMinigameCoaster(0x5A1, 0, 0x3C, name, NULL);
        break;
    case 1:
        sprintf(arg, "%d", D_800FD8A8_FE4A8.unk02[1] + 1);
        win = func_80102AEC_40692C_FinalMinigameCoaster(0x5A2, 0, 0x3C, name, arg);
        break;
    case 2:
        sprintf(arg, "%d", D_800FD8A8_FE4A8.unk05[8] + 1);
        win = func_80102AEC_40692C_FinalMinigameCoaster(0x5A3, 0, 0x3C, name, arg);
        break;
    default:
        arg[0] = 0x18;
        arg[1] = gPlayers[0].character;
        arg[2] = 0;
        win = func_80102AEC_40692C_FinalMinigameCoaster(0x5A4, 0, 0x3C, name, arg);
        break;
    }
    func_8005774C_5834C(win, 0);
    D_800F920C_F9E0C[win].unk20 = 1;
    HuPrcVSleep();
    func_8005774C_5834C(win, 0);
    D_800F920C_F9E0C[win].unk20 = 1;
    HuPrcVSleep();
    func_8005774C_5834C(win, 0);
    D_800F920C_F9E0C[win].unk20 = 1;
    HuPrcVSleep();
    PlaySound(0x120);
    func_8005774C_5834C(win, 0);
    func_8005762C_5822C(win);
    win = func_80102AEC_40692C_FinalMinigameCoaster(0x5A5, 0, 0x3C, NULL, NULL);
    func_801028E0_406720_FinalMinigameCoaster(win);
    func_8008BB48_8C748(win, 0, 1);
    func_8005762C_5822C(win);
    MBMotionShiftSet(HOST, 0, 0, 0xA, 2);
    HOST2 = func_80043510_44110(0xA7, D_8010645C_40A29C_FinalMinigameCoaster);
    func_80043DAC_449AC(HOST2);
    func_800B3170_B3D70(&HOST2->pos, &D_801062C4_40A104_FinalMinigameCoaster);
    func_80056658_57258(&HOST2->pos, &PLAYER_MODEL(0)->pos, &HOST2->rot);
    HuVecCopyXYZ(&HOST2->scale, 0.8f, 0.8f, 0.8f);
    func_8005845C_5905C(0, &D_801062D0_40A110_FinalMinigameCoaster, 0x14, HOST2);
    HuPrcSleep(0x14);
    MBMotionSet(HOST2, 1, 2);
    func_80056658_57258(&PLAYER_MODEL(0)->pos, &HOST2->pos, &vec);
    prc = func_80056B78_57778(&PLAYER_MODEL(0)->rot, &vec, &PLAYER_MODEL(0)->rot, 0xA);
    HuPrcChildLink(HuPrcCurrentGet(), prc);
    func_80056658_57258(&PLAYER_MODEL(1)->pos, &HOST2->pos, &vec);
    prc = func_80056B78_57778(&PLAYER_MODEL(1)->rot, &vec, &PLAYER_MODEL(1)->rot, 0xA);
    HuPrcChildLink(HuPrcCurrentGet(), prc);
    func_800794A8_7A0A8(0x78);
    PlaySound(0x11E);
    func_801029C8_406808_FinalMinigameCoaster(0x5A6, 0x1E, 0x3C, name, NULL);
    MBMotionShiftSet(HOST2, 0, 0, 0xA, 2);
    MBMotionSet(HOST, 1, 2);
    func_80056658_57258(&PLAYER_MODEL(0)->pos, &HOST->pos, &vec);
    prc = func_80056B78_57778(&PLAYER_MODEL(0)->rot, &vec, &PLAYER_MODEL(0)->rot, 0xA);
    HuPrcChildLink(HuPrcCurrentGet(), prc);
    func_80056658_57258(&PLAYER_MODEL(1)->pos, &HOST->pos, &vec);
    prc = func_80056B78_57778(&PLAYER_MODEL(1)->rot, &vec, &PLAYER_MODEL(1)->rot, 0xA);
    HuPrcChildLink(HuPrcCurrentGet(), prc);
    func_80102914_406754_FinalMinigameCoaster(0x5A7, -0x1E, 0x3C);
    func_8005845C_5905C(0, &D_8010636C_40A1AC_FinalMinigameCoaster[0], 0xA, PLAYER_MODEL(0));
    func_8005845C_5905C(0, &D_8010636C_40A1AC_FinalMinigameCoaster[1], 0xA, PLAYER_MODEL(1));
    func_8005845C_5905C(0, &D_801062DC_40A11C_FinalMinigameCoaster, 0xA, HOST2);
    MBMotionSet(PLAYER_MODEL(0), 1, 6);
    MBMotionSet(PLAYER_MODEL(1), 1, 6);
    MBMotionSet(HOST2, 1, 6);
    PlaySound(0x36C);
    fx = func_80043510_44110(0x6F, NULL);
    func_800B3170_B3D70(&fx->pos, &HOST->pos);
    fx->pos.z += 200.0f;
    fx->pos.y += 70.0f;
    fx->pos.x += 80.0f;
    rot = 0.0f;
    for (scale = 1.0f; scale < 10.0f; scale += 1.0) {
        HuVecCopyXYZ(&fx->scale, scale, scale, scale);
        func_800B3B80_B4780(D_800FC834_FD434[fx->obj->model[0]].mtx, rot);
        rot += 20.0f;
        HuPrcVSleep();
    }
    MBMotionSet(PLAYER_MODEL(0), 0, 2);
    MBMotionSet(PLAYER_MODEL(1), 0, 2);
    MBMotionSet(HOST2, 0, 2);
    MBModelKill(HOST);
    HOST = NULL;
    for (i = 0; i < 3; i++) {
        MBModelDispOn(D_80106260_40A0A0_FinalMinigameCoaster[i + 5]);
        func_80056658_57258(&D_80106260_40A0A0_FinalMinigameCoaster[i + 5]->pos, &PLAYER_MODEL(0)->pos, &D_80106260_40A0A0_FinalMinigameCoaster[i + 5]->rot);
    }
    for (; scale >= 1.0f; scale -= 1.0) {
        HuVecCopyXYZ(&fx->scale, scale, scale, scale);
        func_800B3B80_B4780(D_800FC834_FD434[fx->obj->model[0]].mtx, rot);
        rot += 20.0f;
        HuPrcVSleep();
    }
    MBModelKill(fx);
    PlayMusic(0x3D);
    PlaySound(0x455);
    MBMotionSet(D_80106260_40A0A0_FinalMinigameCoaster[5], 0, 2);
    MBMotionSet(D_80106260_40A0A0_FinalMinigameCoaster[6], 0, 2);
    MBMotionSet(D_80106260_40A0A0_FinalMinigameCoaster[7], 0, 2);
    func_801029C8_406808_FinalMinigameCoaster(0x5A8, 0, 0x3C, name, NULL);
}

/* Back from the minigame (entry 1). Player 1 won (coins_mg_bonus): rewards, flag 0x11, 1000 coins.
   Lost: the CPU level falls with the attempts D_800CD2C4, then retry (default) or leave by car. */
void func_80104AFC_40893C_FinalMinigameCoaster(void) {
    Vec vec;
    char name[4];
    Vec pos[2];
    s32 i;
    s16 win;
    s32 mess;
    s32 choice;
    Process* prc;

    for (i = 0; i < 3; i++) {
        D_80106260_40A0A0_FinalMinigameCoaster[i + 5] = func_80043510_44110(0x7B, D_80106470_40A2B0_FinalMinigameCoaster);
        func_80043DAC_449AC(D_80106260_40A0A0_FinalMinigameCoaster[i + 5]);
        func_800B3170_B3D70(&D_80106260_40A0A0_FinalMinigameCoaster[i + 5]->pos, &D_801062E8_40A128_FinalMinigameCoaster[i]);
    }
    CAR = func_80043510_44110(0xAB, NULL);
    func_80043DAC_449AC(CAR);
    func_800B3170_B3D70(&CAR->pos, &D_80106390_40A1D0_FinalMinigameCoaster);
    HuVecCopyXYZ(&CAR->rot, -1.0f, 0.0f, 0.0f);
    func_80029E80_2AA80(CAR->obj->model[0], 2, 1);
    HOST = func_80043510_44110(0xA7, D_8010645C_40A29C_FinalMinigameCoaster);
    func_80043DAC_449AC(HOST);
    func_800B3170_B3D70(&HOST->pos, &D_801062DC_40A11C_FinalMinigameCoaster);
    HuVecCopyXYZ(&HOST->scale, 0.8f, 0.8f, 0.8f);
    for (i = 0; i < 2; i++) {
        MBPlayerModelCreate(i, D_80106444_40A284_FinalMinigameCoaster[gPlayers[i].character], 2);
        func_800B3170_B3D70(&PLAYER_MODEL(i)->pos, &D_8010636C_40A1AC_FinalMinigameCoaster[i]);
        HuVecCopyXYZ(&PLAYER_MODEL(i)->rot, -1.0f, 0.0f, 0.0f);
    }
    func_80056658_57258(&HOST->pos, &D_80106260_40A0A0_FinalMinigameCoaster[5]->pos, &HOST->rot);
    for (i = 0; i < 3; i++) {
        func_80056658_57258(&D_80106260_40A0A0_FinalMinigameCoaster[i + 5]->pos, &PLAYER_MODEL(0)->pos, &D_80106260_40A0A0_FinalMinigameCoaster[i + 5]->rot);
    }
    if (gPlayers[0].coins_mg_bonus != 0) {
        PlayMusic(0x10);
    }
    InitFadeIn(2, 0x10);
    HuPrcSleep(0x10);
    if (gPlayers[0].coins_mg_bonus != 0) {
        PlaySound(0x455);
        func_80102914_406754_FinalMinigameCoaster(0x5B8, 0, 0x3C);
        MBMotionSet(D_80106260_40A0A0_FinalMinigameCoaster[5], 0, 2);
        MBMotionSet(D_80106260_40A0A0_FinalMinigameCoaster[6], 0, 2);
        MBMotionSet(D_80106260_40A0A0_FinalMinigameCoaster[7], 0, 2);
        HuVecCopyXYZ(&D_80106260_40A0A0_FinalMinigameCoaster[5]->rot, -1.0f, 0.0f, 0.0f);
        HuVecCopyXYZ(&D_80106260_40A0A0_FinalMinigameCoaster[6]->rot, -1.0f, 0.0f, 0.0f);
        HuVecCopyXYZ(&D_80106260_40A0A0_FinalMinigameCoaster[7]->rot, -1.0f, 0.0f, 0.0f);
        func_8005845C_5905C(0, &D_8010630C_40A14C_FinalMinigameCoaster, 0x3C, D_80106260_40A0A0_FinalMinigameCoaster[5]);
        func_8005845C_5905C(0, &D_80106318_40A158_FinalMinigameCoaster, 0x3C, D_80106260_40A0A0_FinalMinigameCoaster[6]);
        func_8005845C_5905C(0, &D_80106324_40A164_FinalMinigameCoaster, 0x3C, D_80106260_40A0A0_FinalMinigameCoaster[7]);
        HuPrcSleep(0x1E);
        MBModelKill(D_80106260_40A0A0_FinalMinigameCoaster[5]);
        MBModelKill(D_80106260_40A0A0_FinalMinigameCoaster[6]);
        MBModelKill(D_80106260_40A0A0_FinalMinigameCoaster[7]);
        D_80106260_40A0A0_FinalMinigameCoaster[5] = NULL;
        D_80106260_40A0A0_FinalMinigameCoaster[6] = NULL;
        D_80106260_40A0A0_FinalMinigameCoaster[7] = NULL;
        MBMotionSet(HOST, 1, 2);
        func_8005845C_5905C(0, &D_801062B8_40A0F8_FinalMinigameCoaster, 0x1E, HOST);
        HuPrcSleep(0x14);
        func_8005845C_5905C(0, &D_80106354_40A194_FinalMinigameCoaster, 0xA, PLAYER_MODEL(0));
        func_8005845C_5905C(0, &D_80106360_40A1A0_FinalMinigameCoaster, 0xA, PLAYER_MODEL(1));
        MBMotionSet(PLAYER_MODEL(0), 1, 2);
        MBMotionSet(PLAYER_MODEL(1), 1, 2);
        HuPrcSleep(0xA);
        MBMotionSet(PLAYER_MODEL(0), 0, 2);
        MBMotionSet(PLAYER_MODEL(1), 0, 2);
        func_80056658_57258(&HOST->pos, &PLAYER_MODEL(0)->pos, &vec);
        prc = func_80056B78_57778(&HOST->rot, &vec, &HOST->rot, 0xA);
        HuPrcChildLink(HuPrcCurrentGet(), prc);
        HuPrcChildWatch();
        PlaySound(0x11F);
        name[0] = 0x18;
        name[1] = gPlayers[0].character;
        name[2] = 0;
        func_801029C8_406808_FinalMinigameCoaster(0x5B9, 0, 0x3C, name, NULL);
        func_801031D0_407010_FinalMinigameCoaster();
        if (_CheckFlag(0x11) == 0) {
            func_80102914_406754_FinalMinigameCoaster(0x5BA, 0, 0x3C);
            func_80103E04_407C44_FinalMinigameCoaster(1);
            func_80102914_406754_FinalMinigameCoaster(0x5BB, 0, 0x3C);
        }
        func_8010370C_40754C_FinalMinigameCoaster();
        func_80102914_406754_FinalMinigameCoaster(D_80106494_40A2D4_FinalMinigameCoaster[gPlayers[0].character], 0, 0x3C);
        func_80102914_406754_FinalMinigameCoaster(0x5C2, 0, 0x3C);
        D_801062A0_40A0E0_FinalMinigameCoaster = 1;
        D_800F8C60.coinNum += 1000;
        if (D_800F8C60.coinNum > 99999) {
            D_800F8C60.coinNum = 99999;
        }
        func_800753D4_75FD4(3);
        _SetFlag(0x11);
        return;
    }
    PlayMusic(0x3D);
    PlaySound(0x455);
    MBMotionSet(D_80106260_40A0A0_FinalMinigameCoaster[5], 0, 2);
    MBMotionSet(D_80106260_40A0A0_FinalMinigameCoaster[6], 0, 2);
    MBMotionSet(D_80106260_40A0A0_FinalMinigameCoaster[7], 0, 2);
    if (D_800CD2C4_CDEC4 < 4) {
        gPlayers[1].cpu_difficulty = 3;
        gPlayers[2].cpu_difficulty = 3;
        gPlayers[3].cpu_difficulty = 3;
        func_80102914_406754_FinalMinigameCoaster(0x5A9, 0, 0x3C);
        win = func_80102AEC_40692C_FinalMinigameCoaster(0x5AA, 0, 0x3C, NULL, NULL);
        func_801028E0_406720_FinalMinigameCoaster(win);
        choice = func_8008BB48_8C748(win, 0, 1);
        func_8005762C_5822C(win);
        mess = 0x5AB;
        if (choice != 0) {
            goto ask;
        }
        func_80102914_406754_FinalMinigameCoaster(mess, 0, 0x3C);
        D_801062A4_40A0E4_FinalMinigameCoaster = 1;
        return;
    }
    if (D_800CD2C4_CDEC4 < 7) {
        gPlayers[1].cpu_difficulty = 2;
        gPlayers[2].cpu_difficulty = 2;
        gPlayers[3].cpu_difficulty = 2;
        func_80102914_406754_FinalMinigameCoaster(0x5AC, 0, 0x3C);
        win = func_80102AEC_40692C_FinalMinigameCoaster(0x5AD, 0, 0x3C, NULL, NULL);
        func_801028E0_406720_FinalMinigameCoaster(win);
        choice = func_8008BB48_8C748(win, 0, 1);
        func_8005762C_5822C(win);
        mess = 0x5AE;
        if (choice != 0) {
            goto ask;
        }
        func_80102914_406754_FinalMinigameCoaster(mess, 0, 0x3C);
        D_801062A4_40A0E4_FinalMinigameCoaster = 1;
        return;
    }
    if (D_800CD2C4_CDEC4 < 10) {
        gPlayers[1].cpu_difficulty = 1;
        gPlayers[2].cpu_difficulty = 1;
        gPlayers[3].cpu_difficulty = 1;
        func_80102914_406754_FinalMinigameCoaster(0x5AF, 0, 0x3C);
        win = func_80102AEC_40692C_FinalMinigameCoaster(0x5B0, 0, 0x3C, NULL, NULL);
        func_801028E0_406720_FinalMinigameCoaster(win);
        choice = func_8008BB48_8C748(win, 0, 1);
        func_8005762C_5822C(win);
        mess = 0x5B1;
        if (choice != 0) {
            goto ask;
        }
        func_80102914_406754_FinalMinigameCoaster(mess, 0, 0x3C);
        D_801062A4_40A0E4_FinalMinigameCoaster = 1;
        return;
    }
    gPlayers[1].cpu_difficulty = 0;
    gPlayers[2].cpu_difficulty = 0;
    gPlayers[3].cpu_difficulty = 0;
    func_80102914_406754_FinalMinigameCoaster(0x5B2, 0, 0x3C);
    win = func_80102AEC_40692C_FinalMinigameCoaster(0x5B3, 0, 0x3C, NULL, NULL);
    func_801028E0_406720_FinalMinigameCoaster(win);
    choice = func_8008BB48_8C748(win, 0, 1);
    func_8005762C_5822C(win);
    mess = 0x5B4;
    if (choice == 0) {
        func_80102914_406754_FinalMinigameCoaster(mess, 0, 0x3C);
        D_801062A4_40A0E4_FinalMinigameCoaster = 1;
        return;
    }
ask:
    win = func_80102AEC_40692C_FinalMinigameCoaster(0x5B5, 0, 0x3C, NULL, NULL);
    func_801028E0_406720_FinalMinigameCoaster(win);
    choice = func_8008BB48_8C748(win, 0, 1);
    func_8005762C_5822C(win);
    if (choice == 0) {
        func_80102914_406754_FinalMinigameCoaster(0x5B6, 0, 0x3C);
        HuVecCopyXYZ(&pos[0], CAR->pos.x + -47.7895f, (CAR->pos.y * 5.0f) + 18.3945f, CAR->pos.z + 0.0f);
        HuVecCopyXYZ(&pos[1], CAR->pos.x + 41.230003f, (CAR->pos.y * 5.0f) + 18.3945f, CAR->pos.z + 0.0f);
        func_80059120_59D20(PLAYER_MODEL(0), 60.0f, -4.5f);
        func_80059120_59D20(PLAYER_MODEL(1), 60.0f, -4.5f);
        func_8005845C_5905C(0, &pos[0], 0x18, PLAYER_MODEL(0));
        func_8005845C_5905C(0, &pos[1], 0x18, PLAYER_MODEL(1));
        MBMotionSet(PLAYER_MODEL(0), 3, 0);
        MBMotionSet(PLAYER_MODEL(1), 3, 0);
        HuVecCopyXYZ(&vec, -1.0f, 0.0f, 0.0f);
        prc = func_80056B78_57778(&PLAYER_MODEL(0)->rot, &vec, &PLAYER_MODEL(0)->rot, 0x18);
        HuPrcChildLink(HuPrcCurrentGet(), prc);
        prc = func_80056B78_57778(&PLAYER_MODEL(1)->rot, &vec, &PLAYER_MODEL(1)->rot, 0x18);
        HuPrcChildLink(HuPrcCurrentGet(), prc);
        HuPrcChildWatch();
        MBMotionShiftSet(PLAYER_MODEL(0), 0, 0, 0xA, 2);
        MBMotionShiftSet(PLAYER_MODEL(1), 0, 0, 0xA, 2);
        func_8005AA48_5B648(CAR, "point1", PLAYER_MODEL(0)->obj->model[0]);
        func_8005AA48_5B648(CAR, "point2", PLAYER_MODEL(1)->obj->model[0]);
        HuPrcSleep(0xA);
        MBMotionSet(D_80106260_40A0A0_FinalMinigameCoaster[5], 1, 2);
        MBMotionSet(D_80106260_40A0A0_FinalMinigameCoaster[6], 1, 2);
        MBMotionSet(D_80106260_40A0A0_FinalMinigameCoaster[7], 1, 2);
        func_8005845C_5905C(0, &D_80106330_40A170_FinalMinigameCoaster, 0xA, D_80106260_40A0A0_FinalMinigameCoaster[5]);
        func_8005845C_5905C(0, &D_8010633C_40A17C_FinalMinigameCoaster, 0xA, D_80106260_40A0A0_FinalMinigameCoaster[6]);
        func_8005845C_5905C(0, &D_80106348_40A188_FinalMinigameCoaster, 0xA, D_80106260_40A0A0_FinalMinigameCoaster[7]);
        HuPrcSleep(0xA);
        MBPlayerVibrate(-1, 5);
        func_80056D80_57980(&CAR->pos, &D_80106384_40A1C4_FinalMinigameCoaster, &CAR->pos, 0xA);
        HuPrcSleep(0x14);
        D_801062A8_40A0E8_FinalMinigameCoaster = 0;
        return;
    }
    func_80102914_406754_FinalMinigameCoaster(mess, 0, 0x3C);
    D_801062A4_40A0E4_FinalMinigameCoaster = 1;
}

/* Hard, flag 8 already set: the same arrival with the 0x7B models already standing. */
void func_8010565C_40949C_FinalMinigameCoaster(void) {
    Vec vec;
    s32 i;
    Process* prc;

    for (i = 0; i < 3; i++) {
        D_80106260_40A0A0_FinalMinigameCoaster[i + 5] = func_80043510_44110(0x7B, D_80106470_40A2B0_FinalMinigameCoaster);
        func_80043DAC_449AC(D_80106260_40A0A0_FinalMinigameCoaster[i + 5]);
        func_800B3170_B3D70(&D_80106260_40A0A0_FinalMinigameCoaster[i + 5]->pos, &D_801062E8_40A128_FinalMinigameCoaster[i]);
        HuVecCopyXYZ(&D_80106260_40A0A0_FinalMinigameCoaster[i + 5]->rot, 1.0f, 0.0f, 0.0f);
    }
    CAR = func_80043510_44110(0xAB, NULL);
    func_80043DAC_449AC(CAR);
    func_800B3170_B3D70(&CAR->pos, &D_80106384_40A1C4_FinalMinigameCoaster);
    HuVecCopyXYZ(&CAR->rot, -1.0f, 0.0f, 0.0f);
    HOST = func_80043510_44110(0xA7, D_8010645C_40A29C_FinalMinigameCoaster);
    func_80043DAC_449AC(HOST);
    func_800B3170_B3D70(&HOST->pos, &D_801062DC_40A11C_FinalMinigameCoaster);
    HuVecCopyXYZ(&HOST->rot, 0.0f, 0.0f, -1.0f);
    HuVecCopyXYZ(&HOST->scale, 0.8f, 0.8f, 0.8f);
    for (i = 0; i < 2; i++) {
        MBPlayerModelCreate(i, D_80106444_40A284_FinalMinigameCoaster[gPlayers[i].character], 2);
        HuVecCopyXYZ(&PLAYER_MODEL(i)->rot, -1.0f, 0.0f, 0.0f);
        PLAYER_MODEL(i)->attr |= 1;
    }
    func_8005AA48_5B648(CAR, "point1", PLAYER_MODEL(0)->obj->model[0]);
    func_8005AA48_5B648(CAR, "point2", PLAYER_MODEL(1)->obj->model[0]);
    InitFadeIn(2, 0x10);
    HuPrcSleep(0x10);
    PlaySound(0x456);
    prc = func_80056D80_57980(&CAR->pos, &D_80106390_40A1D0_FinalMinigameCoaster, &CAR->pos, 0x1E);
    HuPrcChildLink(HuPrcCurrentGet(), prc);
    HuPrcChildWatch();
    PlaySound(0x451);
    MBPlayerVibrate(-1, 2);
    func_80029E80_2AA80(CAR->obj->model[0], 2, 1);
    HuVecCopyXYZ(&PLAYER_MODEL(0)->pos, CAR->pos.x + -47.7895f, (CAR->pos.y * 5.0f) + 18.3945f, CAR->pos.z + 0.0f);
    HuVecCopyXYZ(&PLAYER_MODEL(1)->pos, CAR->pos.x + 41.230003f, (CAR->pos.y * 5.0f) + 18.3945f, CAR->pos.z + 0.0f);
    PLAYER_MODEL(0)->attr &= 0xFFFE;
    PLAYER_MODEL(1)->attr &= 0xFFFE;
    HuPrcVSleep();
    func_8005AA98_5B698(PLAYER_MODEL(0)->obj->model[0]);
    func_8005AA98_5B698(PLAYER_MODEL(1)->obj->model[0]);
    HuPrcVSleep();
    func_80059120_59D20(PLAYER_MODEL(0), 60.0f, -4.5f);
    func_80059120_59D20(PLAYER_MODEL(1), 60.0f, -4.5f);
    func_8005845C_5905C(0, &D_8010636C_40A1AC_FinalMinigameCoaster[0], 0x18, PLAYER_MODEL(0));
    func_8005845C_5905C(0, &D_8010636C_40A1AC_FinalMinigameCoaster[1], 0x18, PLAYER_MODEL(1));
    MBMotionSet(PLAYER_MODEL(0), 3, 0);
    MBMotionSet(PLAYER_MODEL(1), 3, 0);
    func_8005670C_5730C(&vec);
    prc = func_80056B78_57778(&PLAYER_MODEL(0)->rot, &vec, &PLAYER_MODEL(0)->rot, 0x18);
    HuPrcChildLink(HuPrcCurrentGet(), prc);
    prc = func_80056B78_57778(&PLAYER_MODEL(1)->rot, &vec, &PLAYER_MODEL(1)->rot, 0x18);
    HuPrcChildLink(HuPrcCurrentGet(), prc);
    HuPrcChildWatch();
    MBMotionShiftSet(PLAYER_MODEL(0), 0, 0, 0xA, 2);
    MBMotionShiftSet(PLAYER_MODEL(1), 0, 0, 0xA, 2);
    func_80056658_57258(&PLAYER_MODEL(0)->pos, &D_80106260_40A0A0_FinalMinigameCoaster[6]->pos, &vec);
    func_80056B78_57778(&PLAYER_MODEL(0)->rot, &vec, &PLAYER_MODEL(0)->rot, 0xA);
    func_80056658_57258(&PLAYER_MODEL(1)->pos, &D_80106260_40A0A0_FinalMinigameCoaster[6]->pos, &vec);
    func_80056B78_57778(&PLAYER_MODEL(1)->rot, &vec, &PLAYER_MODEL(1)->rot, 0xA);
    func_80056658_57258(&HOST->pos, &D_80106260_40A0A0_FinalMinigameCoaster[6]->pos, &vec);
    func_80056B78_57778(&HOST->rot, &vec, &HOST->rot, 0xA);
    func_80056658_57258(&D_80106260_40A0A0_FinalMinigameCoaster[5]->pos, &PLAYER_MODEL(0)->pos, &vec);
    func_80056B78_57778(&D_80106260_40A0A0_FinalMinigameCoaster[5]->rot, &vec, &D_80106260_40A0A0_FinalMinigameCoaster[5]->rot, 0xA);
    func_80056658_57258(&D_80106260_40A0A0_FinalMinigameCoaster[6]->pos, &PLAYER_MODEL(0)->pos, &vec);
    func_80056B78_57778(&D_80106260_40A0A0_FinalMinigameCoaster[6]->rot, &vec, &D_80106260_40A0A0_FinalMinigameCoaster[6]->rot, 0xA);
    func_80056658_57258(&D_80106260_40A0A0_FinalMinigameCoaster[7]->pos, &PLAYER_MODEL(0)->pos, &vec);
    func_80056B78_57778(&D_80106260_40A0A0_FinalMinigameCoaster[7]->rot, &vec, &D_80106260_40A0A0_FinalMinigameCoaster[7]->rot, 0xA);
    HuPrcSleep(0xA);
    MBMotionSet(D_80106260_40A0A0_FinalMinigameCoaster[5], 0, 2);
    MBMotionSet(D_80106260_40A0A0_FinalMinigameCoaster[6], 0, 2);
    MBMotionSet(D_80106260_40A0A0_FinalMinigameCoaster[7], 0, 2);
    PlaySound(0x455);
    func_80102914_406754_FinalMinigameCoaster(0x5B7, 0, 0x3C);
}

/* Main process. D_800CD414: 0 first entry, 1 back from the minigame. Course D_800FD8A8.unk04:
   0 and 1 reward and leave, 2 goes on to the minigame. */
void func_80105CE8_409B28_FinalMinigameCoaster(void) {
    func_80026D28_27928(1);
    func_80026DAC_279AC(0, 0x78, 0x78, 0x78);
    func_80026DAC_279AC(1, 0x40, 0x40, 0x60);
    func_80026E00_27A00(1, -100.0f, 100.0f, 300.0f);
    switch (D_800CD414_CE014) {
    case 0:
        switch (D_800FD8A8_FE4A8.unk04) {
        case 0:
            func_80102C00_406A40_FinalMinigameCoaster();
            func_80104270_4080B0_FinalMinigameCoaster();
            D_801062A0_40A0E0_FinalMinigameCoaster = 1;
            D_800F8C60.coinNum += 100;
            if (D_800F8C60.coinNum > 99999) {
                D_800F8C60.coinNum = 99999;
            }
            func_800753D4_75FD4(1);
            _SetFlag(0xF);
            break;
        case 1:
            func_80102C00_406A40_FinalMinigameCoaster();
            func_801042DC_40811C_FinalMinigameCoaster();
            D_801062A0_40A0E0_FinalMinigameCoaster = 1;
            D_800F8C60.coinNum += 500;
            if (D_800F8C60.coinNum > 99999) {
                D_800F8C60.coinNum = 99999;
            }
            func_800753D4_75FD4(2);
            _SetFlag(0x10);
            break;
        case 2:
            if (func_80075390_75F90(8) != 0) {
                func_8010565C_40949C_FinalMinigameCoaster();
            } else {
                func_800753D4_75FD4(8);
                func_80102C00_406A40_FinalMinigameCoaster();
                func_80104380_4081C0_FinalMinigameCoaster();
            }
            D_801062A4_40A0E4_FinalMinigameCoaster = 1;
            break;
        }
        break;
    case 1:
        func_80104AFC_40893C_FinalMinigameCoaster();
        break;
    }
    D_801011FC_101DFC = 1;
    while (1) {
        HuPrcVSleep();
    }
}

void func_80105EC0_409D00_FinalMinigameCoaster(void) {
    s16 minigameOverlayID;

    if (func_8008F618_90218() == 0) {
        if (D_801062A0_40A0E0_FinalMinigameCoaster != 0) {
            func_80075424_76024(0);
            _ClearFlag(0);
            func_8007E018_7EC18();
            func_8007E070_7EC70();
            func_800740AC_74CAC();
        }
        func_80106214_40A054_FinalMinigameCoaster();
        func_80106054_409E94_FinalMinigameCoaster();
        func_8008CE5C_8DA5C();
        func_8005E584_5F184();
        if (D_801062A4_40A0E4_FinalMinigameCoaster != 0) {
            _SetFlag(0xE);
            D_800CD2C4_CDEC4++;
            func_80067E6C_68A6C(0x27);
            minigameOverlayID = func_8003F6F0_402F0(GwSystem.chosenMinigameIndex);
            omOvlCallEx(minigameOverlayID, 0, 0x94);
            omOvlHisChg(1, 0x6D, 1, 0x192);
            return;
        }
        _ClearFlag(0xE);
        omOvlReturnEx(1);
    }
}

void func_80105FBC_409DFC_FinalMinigameCoaster(omObjData* obj) {
    if (D_801011FC_101DFC != 0) {
        InitFadeOut(2, 0x10);
        if (D_801062A8_40A0E8_FinalMinigameCoaster != 0) {
            func_800794A8_7A0A8(0x3C);
        }
        obj->func_ptr = &func_80105EC0_409D00_FinalMinigameCoaster;
    }
}

void func_80106018_409E58_FinalMinigameCoaster(void) {
    MBModelInit();
    func_8005E2B8_5EEB8();
    func_800593C0_59FC0();
    func_8005965C_5A25C();
    func_800581A0_58DA0();
}

void func_80106054_409E94_FinalMinigameCoaster(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_8005E260_5EE60(i);
    }
    for (i = 0; i < 8; i++) {
        if (D_80106240_40A080_FinalMinigameCoaster[i] != -1) {
            func_800283DC_28FDC(D_80106240_40A080_FinalMinigameCoaster[i]);
            D_80106240_40A080_FinalMinigameCoaster[i] = -1;
        }
        if (D_80106260_40A0A0_FinalMinigameCoaster[i] != NULL) {
            MBModelKill(D_80106260_40A0A0_FinalMinigameCoaster[i]);
            D_80106260_40A0A0_FinalMinigameCoaster[i] = NULL;
        }
        if (D_80106280_40A0C0_FinalMinigameCoaster[i] != NULL) {
            omDelObj(D_80106280_40A0C0_FinalMinigameCoaster[i]);
            D_80106280_40A0C0_FinalMinigameCoaster[i] = NULL;
        }
    }
    func_80059400_5A000();
    func_80059704_5A304();
    func_800581D0_58DD0();
}

void func_80106160_409FA0_FinalMinigameCoaster(void) {
    func_80018E30_19A30(1);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_80050A30_51630(D_01164160);
    func_80050E00_51A00(D_801064AC_40A2EC_FinalMinigameCoaster[D_800FD8A8_FE4A8.unk04]);
}

void func_80106214_40A054_FinalMinigameCoaster(void) {
    MBDBackKill();
    func_80050AE0_516E0();
}
