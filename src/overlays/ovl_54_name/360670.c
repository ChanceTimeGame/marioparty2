#include "ovl_54.h"

/* .data (0x361640-0x361650): the model's ride flags */
s16 D_801037D0_361640_name_54 = 1;
s16 D_801037D2_361642_name_54 = 0;
s16 D_801037D4_361644_name_54 = 0;
s16 D_801037D6_361646_name_54 = 1;
f32 D_801037D8_361648_name_54 = 0.0f;

void func_80102800_360670_name_54(void) {
    D_8010388C_3616FC_name_54 = GwSystem.current_player_index;
    omInitObjMan(80, 80);
    func_801036EC_36155C_name_54();
    func_801034C8_361338_name_54();
    func_80088640_89240();
    omAddPrcObj(func_80102ACC_36093C_name_54, 0x300, 0x4000, 0);
    omAddObj(0x1000, 0, 0, -1, func_80103474_3612E4_name_54);
    D_800F64B0_F70B0 = func_80079428_7A028(0x5E);
    PlaySound(0x367);
    func_8008F624_90224(0xFF, 0xFF, 0xFF);
    InitFadeIn(0, 16);
}

/* The model's pulse and bob; the riding player follows it. obj->scale.x and obj->rot.y are the
   phases (degrees). */
void func_801028B4_360724_name_54(omObjData* obj) {
    if (D_801037D0_361640_name_54 == 1) {
        HuVecCopyXYZ(&D_80103880_3616F0_name_54->scale, 1.0f - HuMathSin(obj->scale.x) / 5.0f,
                     1.0f - HuMathSin(obj->scale.x) / 5.0f, 1.0f - HuMathSin(obj->scale.x) / 5.0f);
        obj->scale.x += 40.0f;
    } else if (D_801037D0_361640_name_54 == 0) {
        HuVecCopyXYZ(&D_80103880_3616F0_name_54->scale, 1.0f, 1.0f, 1.0f);
    }
    if (D_801037D6_361646_name_54 != 0) {
        D_80103880_3616F0_name_54->jumpY = HuMathSin(obj->rot.y) * 30.0f;
        obj->rot.y += 2.0f;
        if (obj->rot.y >= 360.0f) {
            obj->rot.y -= 360.0f;
        }
    }
    if (D_801037D2_361642_name_54 != 0) {
        PLAYER_MODEL(D_80103884_3616F4_name_54)->jumpY =
            D_801037D8_361648_name_54 * D_80103880_3616F0_name_54->scale.x + D_80103880_3616F0_name_54->jumpY;
        func_800B3170_B3D70(&PLAYER_MODEL(D_80103884_3616F4_name_54)->pos, &D_80103880_3616F0_name_54->pos);
        func_800B3170_B3D70(&PLAYER_MODEL(D_80103884_3616F4_name_54)->scale, &D_80103880_3616F0_name_54->scale);
    }
    if (D_801037D4_361644_name_54 != 0) {
        PLAYER_MODEL(D_80103884_3616F4_name_54)->rot.x = D_80103880_3616F0_name_54->rot.x;
        PLAYER_MODEL(D_80103884_3616F4_name_54)->rot.z = D_80103880_3616F0_name_54->rot.z;
    }
}

#define MODEL_MTX(m) (D_800FC834_FD434[*(m)->obj->model].mtx)

/* The scene's process. */
void func_80102ACC_36093C_name_54(void) {
    f32 speed;
    f32 angle;
    f32 scale;
    s32 i;

    HuPrcSleep(16);
    HuPrcSleep(30);
    func_8005DDEC_5E9EC(D_8010388C_3616FC_name_54, -1, 0, 10, 2);
    HuPrcSleep(15);
    D_801037D0_361640_name_54 = 0;
    MBDlgResultWinExec(0x1E9);

    /* The model flies up and off. */
    D_801037D6_361646_name_54 = 0;
    speed = 20.0f;
    while (D_80103880_3616F0_name_54->jumpY < 1000.0f) {
        D_80103880_3616F0_name_54->jumpY += speed;
        speed += 5.0f;
        HuPrcVSleep();
    }

    /* It comes back from the left. */
    HuVecCopyXYZ(&D_80103880_3616F0_name_54->pos, -1600.0f, -100.0f, 1600.0f);
    D_801037D6_361646_name_54 = 1;
    func_800B3870_B4470(MODEL_MTX(D_80103880_3616F0_name_54), 0.0f);
    D_80103880_3616F0_name_54->rot.x = HuMathSin(45.0f);
    D_80103880_3616F0_name_54->rot.z = func_800B7890_B8490(45.0f);
    speed = 50.0f;
    while (D_80103880_3616F0_name_54->pos.x < 0.0f) {
        D_80103880_3616F0_name_54->pos.x += 2.0f * speed;
        D_80103880_3616F0_name_54->pos.z += 2.0f * speed;
        speed -= 1.6f;
        if (speed <= 5.0f) {
            speed = 5.0f;
        }
        HuPrcVSleep();
    }

    /* The player jumps on. */
    MBPlayerMotionSet(D_8010388C_3616FC_name_54, 2, 0);
    {
        Vec jumpFrom = { 0.0f, -30.0f, 3200.0f };
        Vec jumpTo = { 0.0f, 0.0f, 0.0f };

        func_80058B58_59758((void*)D_8010388C_3616FC_name_54, &jumpFrom, 20, &jumpTo);
    }
    PLAYER_MODEL(D_80103884_3616F4_name_54)->jumpVel = 30.0f;
    PLAYER_MODEL(D_80103884_3616F4_name_54)->jumpAccel = -2.5f;
    HuPrcSleep(20);
    PLAYER_MODEL(D_80103884_3616F4_name_54)->jumpVel = PLAYER_MODEL(D_80103884_3616F4_name_54)->jumpAccel = 0.0f;
    D_801037D8_361648_name_54 = PLAYER_MODEL(D_80103884_3616F4_name_54)->pos.y - D_80103880_3616F0_name_54->pos.y - 10.0f;
    D_801037D2_361642_name_54 = 1;
    D_801037D4_361644_name_54 = 1;
    MBPlayerMotionSet(D_8010388C_3616FC_name_54, -1, 2);
    {
        Vec face1 = { 500.0f, 0.0f, 4000.0f };

        func_80058F18_59B18(D_8010388C_3616FC_name_54, &face1, 5, NULL);
    }
    HuPrcSleep(5);
    MBDlgWinExecY(-1, 0x1EA, 40);

    /* Both fly off into the distance, spinning. */
    {
        Vec flyTo1 = { 200.0f, 200.0f, 5000.0f };
        Vec flyVel1 = { 0.0f, 0.0f, -200.0f };

        func_80058F18_59B18(0, &flyTo1, 30, D_80103880_3616F0_name_54);
        func_80058B58_59758(D_80103880_3616F0_name_54, &flyTo1, 30, &flyVel1);
    }
    angle = 0.0f;
    for (i = 0; i < 30; i++) {
        func_800B3870_B4470(MODEL_MTX(D_80103880_3616F0_name_54), angle);
        func_800B3870_B4470(MODEL_MTX(PLAYER_MODEL(D_80103884_3616F4_name_54)), angle);
        angle -= 2.0f;
        HuPrcVSleep();
    }
    HuPrcSleep(5);

    /* The backdrop fades out. */
    D_801037D0_361640_name_54 = -1;
    for (i = 256; i >= 0; i -= 8) {
        func_80082488_83088(D_80103888_3616F8_name_54, 0, i);
        HuPrcVSleep();
    }
    func_80082488_83088(D_80103888_3616F8_name_54, 0, 0);

    /* They come back small from the left and grow. */
    PlaySound(0x361);
    {
    Vec face2 = { 300.0f, -100.0f, 3201.0f };
    Vec start2 = { -200.0f, 0.0f, 3200.0f };
    Vec flyTo2 = { 0.0f, -100.0f, 3200.0f };
    Vec flyVel2 = { -300.0f, 0.0f, 0.0f };

    func_800B3170_B3D70(&D_80103880_3616F0_name_54->pos, &start2);
    HuVecCopyXYZ(&D_80103880_3616F0_name_54->scale, 0.1f, 0.1f, 0.1f);
    func_800B3870_B4470(MODEL_MTX(D_80103880_3616F0_name_54), 0.0f);
    func_800B3870_B4470(MODEL_MTX(PLAYER_MODEL(D_80103884_3616F4_name_54)), 0.0f);
    D_80103880_3616F0_name_54->rot.x = HuMathSin(-90.0f);
    D_80103880_3616F0_name_54->rot.z = func_800B7890_B8490(-90.0f);
    func_80058F18_59B18(0, &face2, 60, D_80103880_3616F0_name_54);
    func_80058B58_59758(D_80103880_3616F0_name_54, &flyTo2, 60, &flyVel2);
    scale = 0.05f;
    for (i = 0; i < 60; i++) {
        HuVecCopyXYZ(&D_80103880_3616F0_name_54->scale, scale, scale, scale);
        scale += 0.017;
        if (scale > 1.0f) {
            scale = 1.0f;
        }
        HuPrcVSleep();
    }
    HuVecCopyXYZ(&D_80103880_3616F0_name_54->scale, 1.0f, 1.0f, 1.0f);
    }

    /* The player turns to the camera and celebrates. */
    D_801037D4_361644_name_54 = 0;
    {
    Vec rot;

    func_8005670C_5730C(&rot);
    func_80056B78_57778(&PLAYER_MODEL(D_80103884_3616F4_name_54)->rot, &rot, &PLAYER_MODEL(D_80103884_3616F4_name_54)->rot, 10);
    HuPrcSleep(10);
    MBPlayerMotionSet(D_8010388C_3616FC_name_54, 5, 0);
    func_80079718_7A318(0x103, gPlayers[D_8010388C_3616FC_name_54].character);
    HuPrcSleep(50);
    MBPlayerMotionSet(D_8010388C_3616FC_name_54, -1, 2);
    scale = 1.0f;
    rot.x = scale;
    rot.z = 0.0f;
    func_80056B78_57778(&PLAYER_MODEL(D_80103884_3616F4_name_54)->rot, &rot, &PLAYER_MODEL(D_80103884_3616F4_name_54)->rot, 10);
    HuPrcSleep(10);
    }

    /* Both fly off to the right, shrinking. */
    D_801037D4_361644_name_54 = 1;
    PlaySound(0x362);
    {
        Vec face3 = { 0.0f, -100.0f, 3199.0f };
        Vec flyTo3 = { 200.0f, 0.0f, 3200.0f };
        Vec flyVel3 = { 300.0f, 0.0f, 0.0f };

        func_80058F18_59B18(0, &face3, 60, D_80103880_3616F0_name_54);
        func_80058B58_59758(D_80103880_3616F0_name_54, &flyTo3, 60, &flyVel3);
    }
    for (i = 0; i < 60; i++) {
        HuVecCopyXYZ(&D_80103880_3616F0_name_54->scale, scale, scale, scale);
        scale -= 0.017;
        if (scale < 0.1f) {
            break;
        }
        HuPrcVSleep();
    }
    HuVecCopyXYZ(&D_80103880_3616F0_name_54->scale, 0.0f, 0.0f, 0.0f);
    D_801011FC_101DFC = 1;
    while (TRUE) {
        HuPrcVSleep();
    }
}

void func_80103430_3612A0_name_54(omObjData* obj) {
    if (func_8008F618_90218() == 0) {
        func_801037A8_361618_name_54();
        func_801036A8_361518_name_54();
        func_8008CE5C_8DA5C();
        omOvlReturnEx(1);
    }
}

void func_80103474_3612E4_name_54(omObjData* obj) {
    if (D_801011FC_101DFC != 0) {
        func_8008F624_90224(0xFF, 0xFF, 0xFF);
        InitFadeOut(0, 20);
        obj->func_ptr = func_80103430_3612A0_name_54;
    }
}

/* The backdrop sprite, the player's model and the ride model. */
void func_801034C8_361338_name_54(void) {
    void* file;
    omObjData* obj;

    MBModelInit();
    func_8005E2B8_5EEB8();
    D_80103888_3616F8_name_54 = SprCreate(1, 5);
    file = DataRead(0xA0189);
    D_8010388A_3616FA_name_54 = SprAnimRead(file);
    DataClose(file);
    SprAnimSet(D_80103888_3616F8_name_54, 0, D_8010388A_3616FA_name_54, 0);
    SprPrioSet(D_80103888_3616F8_name_54, 0, 10);
    func_8008225C_82E5C(D_80103888_3616F8_name_54, 0, 1);
    SprAttrSet(D_80103888_3616F8_name_54, 0, 0x5000);
    SprPosSet(D_80103888_3616F8_name_54, 0, 160, 120);
    SprScaleSet(D_80103888_3616F8_name_54, 0, 20.0f, 20.0f);
    func_8005E154_5ED54((s16)D_8010388C_3616FC_name_54);
    MBPlayerMotionSet(D_8010388C_3616FC_name_54, 4, 2);
    D_80103884_3616F4_name_54 = BoardPlayerGet(D_8010388C_3616FC_name_54);
    HuVecCopyXYZ(&PLAYER_MODEL(D_80103884_3616F4_name_54)->pos, 150.0f, -100.0f, 3000.0f);
    PLAYER_MODEL(D_80103884_3616F4_name_54)->attr |= 1;
    D_80103880_3616F0_name_54 = func_80043510_44110(0x72, NULL);
    HuVecCopyXYZ(&D_80103880_3616F0_name_54->pos, -150.0f, -50.0f, 3000.0f);
    func_800B3870_B4470(MODEL_MTX(D_80103880_3616F0_name_54), -60.0f);
    obj = omAddObj(0x1000, 0, 0, -1, func_801028B4_360724_name_54);
    obj->rot.y = 0.0f;
    obj->scale.x = 0.0f;
}

void func_801036A8_361518_name_54(void) {
    MBModelKill(D_80103880_3616F0_name_54);
    func_8005E260_5EE60((s16)D_8010388C_3616FC_name_54);
    SprAnimKill(D_8010388A_3616FA_name_54);
    SprKill(D_80103888_3616F8_name_54);
}

void func_801036EC_36155C_name_54(void) {
    func_80018E30_19A30(1);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_80050A30_51630(D_01164160);
    func_80050E00_51A00(0);
    func_8005321C_53E1C(200.0f, 3000.0f);
}

void func_801037A8_361618_name_54(void) {
    MBDBackKill();
    func_80050AE0_516E0();
}
