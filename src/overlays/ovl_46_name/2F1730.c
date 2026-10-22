#include "common.h"
#include "ovl_46.h"

void func_80102800_2F1730_name_46(void) {
    s32 i;

    omInitObjMan(40, 15);
    func_80079128_79D28();
    func_80018E30_19A30(1);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_80050A30_51630(D_01164160);
    MBModelInit();
    func_8005E2B8_5EEB8();
    func_800593C0_59FC0();
    func_800581A0_58DA0();
    func_801029F8_2F1928_name_46();
    func_80088640_89240();
    func_801070C8_2F5FF8_name_46();
    func_8005FE10_60A10();
    func_80060034_60C34(0, (u8)gPlayers[0].player_space_color);
    func_80060034_60C34(1, (u8)gPlayers[1].player_space_color);
    func_80060034_60C34(2, (u8)gPlayers[2].player_space_color);
    func_80060034_60C34(3, (u8)gPlayers[3].player_space_color);
    HidePlayerHUDVisibility(0, 1);
    HidePlayerHUDVisibility(1, 1);
    HidePlayerHUDVisibility(2, 1);
    HidePlayerHUDVisibility(3, 1);
    omAddPrcObj(func_80102D0C_2F1C3C_name_46, 0x5000, 0x2000, 0);
    omAddObj(1000, 0, 0, -1, func_80102C2C_2F1B5C_name_46);
    for (i = 0; i < 2; i++) {
        D_80108268_2F7198_name_46[i] = func_80107158_2F6088_name_46(i * 116 + 110, 80);
        func_801073EC_2F631C_name_46(D_80108268_2F7198_name_46[i]);
    }
}

void func_801029F8_2F1928_name_46(void) {
    s32 bits;
    s32 i;

    D_801081F4_2F7124_name_46 = -1;
    D_801081E8_2F7118_name_46 = 0;
    D_8010826C_2F719C_name_46 = 0;
    if (_CheckFlag(0x17) == 0) {
        D_8010826C_2F719C_name_46 = 1;
    }
    bits = D_800F8D1A_F991A.attacker;
    if (_CheckFlag(0x19) != 0) {
        if (ContBtn[0] & 0x8000) {
            bits = 1;
            D_8010826C_2F719C_name_46 = 0;
        }
        if (ContBtn[0] & 0x4000) {
            bits = 1;
            D_8010826C_2F719C_name_46 = 1;
        }
    }
    D_801081F0_2F7120_name_46 = 0;
    for (i = 0; bits != 0; i++) {
        bits >>= 1;
        if (bits == 0) {
            break;
        }
        D_801081F0_2F7120_name_46++;
    }
    D_80108208_2F7138_name_46 = 1;
    D_801081F8_2F7128_name_46[i] = 1;
    bits = D_800F8D1A_F991A.targets;
    if (_CheckFlag(0x19) != 0) {
        if (ContBtn[0] & 0x8000) {
            bits = 0xE;
        }
        if (ContBtn[0] & 0x4000) {
            bits = 2;
        }
    }
    for (i = 0; i < 4; i++) {
        if ((bits >> i) & 1) {
            D_80108208_2F7138_name_46++;
            D_801081F8_2F7128_name_46[i] = 1;
        }
    }
    for (i = 0; i < 2; i++) {
        D_80108240_2F7170_name_46[i] = 0;
    }
    if (D_80108208_2F7138_name_46 == 2) {
        for (i = 0; i < 4; i++) {
            if (D_801081F8_2F7128_name_46[i] == 1 && i != D_801081F0_2F7120_name_46) {
                D_801081F4_2F7124_name_46 = i;
                break;
            }
        }
    }
    D_800FC880_FD480 = 0;
    D_800F8C5C_F985C = 0;
    D_80108224_2F7154_name_46 = GwSystem.current_turn;
}

void func_80102C2C_2F1B5C_name_46(omObjData* obj) {
    if (D_801011FC_101DFC != 0) {
        MBDBackKill();
        func_80050AE0_516E0();
        func_80059400_5A000();
        func_80069770_6A370();
        func_8008CE5C_8DA5C();
        omOvlReturnEx(1);
    }
}

void func_80102C80_2F1BB0_name_46(void) {
    Vec pos;
    Vec rot;
    Vec up;

    pos.x = 0.0f;
    pos.y = 150.0f;
    pos.z = 1300.0f;
    rot.x = rot.z = pos.x;
    rot.y = 100.0f;
    up.x = pos.x;
    up.y = 1.0f;
    up.z = pos.x;
    Hu3DCamSetPositionOrientation(0, &pos, &rot, &up);
    Hu3DCamUpdateMtx(0);
}

/* The duel scene's flow (42's func_80102CA0): duelists, stands and buttons, the referee drops in;
   the opponent and the stake are chosen; the stands slide in and a target of 2-5 seconds is drawn;
   each side presses A once (func_80106038) and the press nearer the target wins (D_80108230:
   1 draw, 2 challenger, 3 opponent). Both times count up, the loser's stand blows up and the
   winner takes both stakes. Retail quirk: both stands and buttons start at D_80108038[0] /
   D_8010805C[0] (the index is not used); the slide puts them in place. */
#ifdef NON_MATCHING
/* masked 3 (raw 58): the referee's drop loop allocates f0/f2 the other way round, one delay slot
   (the referee's motion before the win message) is filled with a2 instead of a1, and the
   winner's column test is a bne where retail has bnel. */
void func_80102D0C_2F1C3C_name_46(void) {
    s32 chr;
    ModelPathWork* work[4];
    MBModel* model;
    u32 file;
    s32 x;
    s32 winner;
    s16 loserMes;
    Vec pos[2];
    char mes[4];
    char digits[9] = "\x82\x51\x82\x52\x82\x53\x82\x54"; /* SJIS "2345" */
    s32 duelists[2];
    u32 motions[3] = { 2, 0x800A7, 0x800AA };
    s16 win;
    u16 done;
    s32 layout;
    s32 offs;
    s32 last;
    f32 start;
    f32 end;
    f32 speed;
    f32 gap;
    f32 step;
    f32 t0;
    f32 t1;
    f32 shown0;
    f32 shown1;
    s32 i;

    func_80050E00_51A00(25);
    func_8005321C_53E1C(80.0f, 8000.0f);
    for (i = 0; i < 4; i++) {
        if (D_801081F8_2F7128_name_46[i] != 0) {
            chr = gPlayers[i].character;
            MBPlayerModelCreate(i, D_80107F98_2F6EC8_name_46[chr], 2);
            func_8005ABC0_5B7C0(&gPlayers[i], 1, 0);
            PLAYER_MODEL(i)->pos.x = -1000.0f;
            PLAYER_MODEL(i)->pos.y = 34.0f;
            PLAYER_MODEL(i)->pos.z = 700.0f;
            gPlayers[i].flags |= 2;
            MBMotionSet(PLAYER_MODEL(i), 2, 2);
            func_80043DAC_449AC(PLAYER_MODEL(i));
        }
    }
    for (i = 0; i < 2; i++) {
        D_80108250_2F7180_name_46[i] = MBModelFileCreate(0xA01E9, 0xD, 1.0f, 1.0f, NULL);
        D_80108250_2F7180_name_46[i]->pos.x = D_80108020_2F6F50_name_46[i].x;
        D_80108250_2F7180_name_46[i]->pos.y = D_80108020_2F6F50_name_46[i].y;
        D_80108250_2F7180_name_46[i]->pos.z = D_80108020_2F6F50_name_46[i].z;
        D_80108250_2F7180_name_46[i]->attr |= 1;
        D_80108258_2F7188_name_46[i] = MBModelFileCreate(0xA01EA, 0xD, 1.0f, 2.0f, NULL);
        D_80108258_2F7188_name_46[i]->pos.x = D_80108038_2F6F68_name_46[0].x;
        D_80108258_2F7188_name_46[i]->pos.y = 0.0f;
        D_80108258_2F7188_name_46[i]->pos.z = D_80108038_2F6F68_name_46[0].z;
        D_80108258_2F7188_name_46[i]->jumpY = D_80108038_2F6F68_name_46[0].y;
        D_80108260_2F7190_name_46[i] = MBModelFileCreate(0x2B0003, 0xD, 1.0f, 1.0f, NULL);
        D_80108260_2F7190_name_46[i]->pos.x = D_8010805C_2F6F8C_name_46[0].x;
        D_80108260_2F7190_name_46[i]->pos.y = D_8010805C_2F6F8C_name_46[0].y;
        D_80108260_2F7190_name_46[i]->pos.z = D_8010805C_2F6F8C_name_46[0].z;
        func_80029E80_2AA80(D_80108260_2F7190_name_46[i]->obj->model[0], 0, 1);
        func_80107C44_2F6B74_name_46(i);
    }
    D_80108274_2F71A4_name_46 = MBModelFileCreate(0x800A6, 0xD, 1.0f, 1.0f, motions);
    func_8005AB50_5B750(D_80108274_2F71A4_name_46, 1, 0xB, 0x800AD);
    func_80056658_57258(&D_80108274_2F71A4_name_46->pos, &D_80107FB4_2F6EE4_name_46, &D_80108274_2F71A4_name_46->rot);
    D_80108274_2F71A4_name_46->pos.x = D_80107FB4_2F6EE4_name_46.x;
    D_80108274_2F71A4_name_46->pos.y = 0.0f;
    D_80108274_2F71A4_name_46->pos.z = D_80107FB4_2F6EE4_name_46.z;
    if (D_8010826C_2F719C_name_46 == 0) {
        D_80108274_2F71A4_name_46->jumpY = D_80107FB4_2F6EE4_name_46.y;
        D_80108274_2F71A4_name_46->jumpVel = 7.5f;
        D_80108274_2F71A4_name_46->jumpAccel = 0.0f;
        D_80108278_2F71A8_name_46 = MBModelFileCreate(0xA019D, 0xD, 1.0f, 1.0f, NULL);
        D_80108278_2F71A8_name_46->pos.x = D_80107FB4_2F6EE4_name_46.x;
        D_80108278_2F71A8_name_46->pos.y = 0.0f;
        D_80108278_2F71A8_name_46->pos.z = D_80107FB4_2F6EE4_name_46.z;
        D_80108278_2F71A8_name_46->jumpY = D_80107FB4_2F6EE4_name_46.y;
        D_80108278_2F71A8_name_46->jumpVel = 7.5f;
        D_80108278_2F71A8_name_46->jumpAccel = 0.0f;
    }
    D_8010824C_2F717C_name_46 = (u16)LoadFormFile(0x10013, 0x69D);
    func_80029E80_2AA80((s16)D_8010824C_2F717C_name_46, 1, 1);
    PlayMusic(0x25);
    InitFadeIn(0, 0x10);
    if (D_8010826C_2F719C_name_46 == 0) {
        /* the referee drops in with his hat */
        goto drop;
    fall:
        HuPrcVSleep();
    drop:
        D_80108278_2F71A8_name_46->jumpY = D_80108274_2F71A4_name_46->jumpY;
        if (!((D_80108274_2F71A4_name_46->jumpY = D_80108274_2F71A4_name_46->jumpY - D_80108274_2F71A4_name_46->jumpVel) <= D_80108274_2F71A4_name_46->pos.y)) {
            goto fall;
        }
        D_80108274_2F71A4_name_46->jumpY = D_80108274_2F71A4_name_46->pos.y;
        func_80105368_2F4298_name_46();
        layout = (D_80108208_2F7138_name_46 == 4) ? 0 : -1;
        if (D_80108208_2F7138_name_46 == 3) {
            layout = 6;
        }
        if (layout != -1) {
            /* three or four players: the challenger picks the opponent */
            func_80104EB0_2F3DE0_name_46(layout);
            PD_WAIT_STEP();
            PlaySound(0xE8);
            omAddPrcObj(func_80105488_2F43B8_name_46, 0x12, 0, 0);
            D_801081D0_2F7100_name_46 = 0;
            PD_WAIT_STEP();
            func_80104EB0_2F3DE0_name_46(1);
            PD_WAIT_STEP();
            func_80104EB0_2F3DE0_name_46(2);
            PD_WAIT_STEP();
        } else {
            func_80104EB0_2F3DE0_name_46(7);
            PD_WAIT_STEP();
        }
        MBVsSprCreateY(160.0f, 90.0f);
        HuPrcSleep(10);
        D_80107FB0_2F6EE0_name_46 = 1;
        func_80104EB0_2F3DE0_name_46(3);
        PD_WAIT_STEP();
        omAddPrcObj(func_80105754_2F4684_name_46, 0x12, 0, 0);
        D_801081D0_2F7100_name_46 = 0;
        PD_WAIT_STEP();
        func_80104EB0_2F3DE0_name_46(4);
        MBVsSprKill();
        PD_WAIT_STEP();
    }
    /* the duelists and their stands slide in */
    start = -450.0f;
    end = -130.0f;
    PLAYER_MODEL(D_801081F0_2F7120_name_46)->pos.x = start;
    PLAYER_MODEL(D_801081F4_2F7124_name_46)->pos.x = -start;
    D_80108258_2F7188_name_46[0]->pos.x = -470.0f;
    D_80108260_2F7190_name_46[0]->pos.x = start;
    D_80108258_2F7188_name_46[1]->pos.x = 470.0f;
    D_80108260_2F7190_name_46[1]->pos.x = -start;
    speed = 21.333334f;
    gap = 20.0f;
    goto slide_in;
slide_in_wait:
    HuPrcVSleep();
slide_in:
    {
        D_80108258_2F7188_name_46[0]->pos.x += speed;
        D_80108260_2F7190_name_46[0]->pos.x += speed;
        D_80108258_2F7188_name_46[1]->pos.x -= speed;
        D_80108260_2F7190_name_46[1]->pos.x -= speed;
        PLAYER_MODEL(D_801081F0_2F7120_name_46)->pos.x += speed;
        PLAYER_MODEL(D_801081F4_2F7124_name_46)->pos.x -= speed;
        if (!(D_80108260_2F7190_name_46[0]->pos.x >= end)) {
            goto slide_in_wait;
        }
    }
    D_80108258_2F7188_name_46[0]->pos.x = end - gap;
    D_80108260_2F7190_name_46[0]->pos.x = end;
    D_80108258_2F7188_name_46[1]->pos.x = -end + gap;
    D_80108260_2F7190_name_46[1]->pos.x = -end;
    PLAYER_MODEL(D_801081F0_2F7120_name_46)->pos.x = end;
    PLAYER_MODEL(D_801081F4_2F7124_name_46)->pos.x = -end;
    /* the referee walks to the middle */
    work[0] = func_8005A718_5B318(D_80108274_2F71A4_name_46, 30.0f, 1, D_80107FCC_2F6EFC_name_46);
    while (func_8005A778_5B378(work[0]) == 0) {
        HuPrcVSleep();
    }
    HuMemMemoryFreePerm(work[0]);
    model = D_80108274_2F71A4_name_46;
    model->rot.x = __sinf(0.34906584f); /* 20 degrees */
    model = D_80108274_2F71A4_name_46;
    model->rot.y = 0.0f;
    model->rot.z = __cosf(0.34906584f);
    D_80108274_2F71A4_name_46->obj->rot.z = 20.0f;
    PlaySound(0xE8);
    D_801081E4_2F7114_name_46 = 0x21B;
    D_801081D8_2F7108_name_46 = 90;
    D_801081DC_2F710C_name_46 = 40;
    D_801081E0_2F7110_name_46 = 1;
    omAddPrcObj(func_80104880_2F37B0_name_46, 0x12, 0, 0);
    D_801081D0_2F7100_name_46 = 0;
    PD_WAIT_STEP();
    D_80108274_2F71A4_name_46->rot.x = HuMathSin(0.0f);
    D_80108274_2F71A4_name_46->rot.y = 0.0f;
    D_80108274_2F71A4_name_46->rot.z = func_800B7890_B8490(D_80108274_2F71A4_name_46->rot.y);
    D_80108274_2F71A4_name_46->obj->rot.z = 0.0f;
    work[0] = func_8005A718_5B318(D_80108274_2F71A4_name_46, 30.0f, 1, D_80107FC0_2F6EF0_name_46);
    while (func_8005A778_5B378(work[0]) == 0) {
        HuPrcVSleep();
    }
    offs = 0;
    HuMemMemoryFreePerm(work[0]);
    D_80108274_2F71A4_name_46->rot.x = HuMathSin(0.0f);
    D_80108274_2F71A4_name_46->rot.y = 0.0f;
    D_80108274_2F71A4_name_46->rot.z = func_800B7890_B8490(D_80108274_2F71A4_name_46->rot.y);
    HuPrcSleep(15);
    /* the target: 2 to 5 seconds */
    D_80108298_2F71C8_name_46 = (rand8() & 3) + 2;
    mes[0] = digits[(D_80108298_2F71C8_name_46 - 2) * 2];
    mes[1] = digits[(D_80108298_2F71C8_name_46 - 2) * 2 + 1];
    mes[2] = 0;
    win = func_800691FC_69DFC(9, mes, 160, 56, 1.0f, 1.0f, 1);
    func_800695D8_6A1D8(win, -1);
    /* a CPU presses at a preset frame: off by 30-55 (easy) or 20-30 frames, or 2-17 / 2-12 */
    duelists[0] = D_801081F0_2F7120_name_46;
    duelists[1] = D_801081F4_2F7124_name_46;
    for (i = 0; i < 2; i++) {
        if (gPlayers[duelists[i]].flags & 1) {
            switch (gPlayers[duelists[i]].cpu_difficulty) {
                case 0:
                    offs = (u8)(rand8() % 26) + 30;
                    break;
                case 1:
                    offs = (u8)(rand8() % 11) + 20;
                    break;
                case 2:
                    offs = (rand8() & 15) + 2;
                    if (rand8() == 0) {
                        offs = -offs;
                    }
                    break;
                case 3:
                    offs = (u8)(rand8() % 11) + 2;
                    if (rand8() == 0) {
                        offs = -offs;
                    }
                    break;
            }
            D_80108228_2F7158_name_46[i] = D_80108298_2F71C8_name_46 * 30 + offs;
        }
    }
    D_801081E4_2F7114_name_46 = 0x21C;
    D_801081D8_2F7108_name_46 = 70;
    D_801081DC_2F710C_name_46 = 70;
    D_801081E0_2F7110_name_46 = 4;
    omAddPrcObj(func_80104880_2F37B0_name_46, 0x12, 0, 0);
    D_801081D0_2F7100_name_46 = 0;
    PD_WAIT_STEP();
    MBMotionShiftSet(PLAYER_MODEL(D_801081F0_2F7120_name_46), 1, 0, 15, 1);
    MBMotionShiftSet(PLAYER_MODEL(D_801081F4_2F7124_name_46), 1, 0, 15, 1);
    func_8008CE5C_8DA5C();
    func_800691FC_69DFC(1);
    HuPrcSleep(45);
    /* the duel */
    D_80108272_2F71A2_name_46 = PlaySound(0x3CC);
    func_80069654_6A254(win);
    omAddPrcObj(func_80106F38_2F5E68_name_46, 0x12, 0, 0);
    D_801081D0_2F7100_name_46 = 0;
    D_80108230_2F7160_name_46 = 0;
    func_80105FD0_2F4F00_name_46();
    PD_WAIT_STEP();
    HuPrcVSleep();
    switch (D_80108230_2F7160_name_46) {
        case 2:
            D_800FC880_FD480 = D_801081F0_2F7120_name_46;
            D_800F8C5C_F985C = D_801081F4_2F7124_name_46;
            break;
        case 3:
            D_800FC880_FD480 = D_801081F4_2F7124_name_46;
            D_800F8C5C_F985C = D_801081F0_2F7120_name_46;
            break;
        case 1:
            D_800F8C5C_F985C = D_800FC880_FD480 = -1;
            break;
    }
    if (D_80108238_2F7168_name_46[0] < 901 || D_80108238_2F7168_name_46[1] < 901) {
        /* both times count up to the presses over 30 frames */
        last = D_80108238_2F7168_name_46[0];
        if (last < D_80108238_2F7168_name_46[1]) {
            last = D_80108238_2F7168_name_46[1];
        }
        step = last / 900.0f;
        shown1 = 0.0f;
        shown0 = shown1;
        t0 = D_80108238_2F7168_name_46[0] / 30.0f + 0.005f;
        t1 = D_80108238_2F7168_name_46[1] / 30.0f + 0.005f;
        for (i = 0; i < 30; i++) {
            shown0 += step;
            if (t0 < shown0) {
                shown0 = t0;
            }
            shown1 += step;
            if (t1 < shown1) {
                shown1 = t1;
            }
            if (D_80108238_2F7168_name_46[0] < 901) {
                func_80107448_2F6378_name_46(D_80108268_2F7198_name_46[0], shown0);
            }
            if (D_80108238_2F7168_name_46[1] < 901) {
                func_80107448_2F6378_name_46(D_80108268_2F7198_name_46[1], shown1);
            }
            HuPrcVSleep();
        }
        if (D_80108238_2F7168_name_46[0] < 901) {
            func_80107448_2F6378_name_46(D_80108268_2F7198_name_46[0], t0);
        }
        if (D_80108238_2F7168_name_46[1] < 901) {
            func_80107448_2F6378_name_46(D_80108268_2F7198_name_46[1], t1);
        }
        omAddPrcObj(func_801076B4_2F65E4_name_46, 0x12, 0, 0);
        if (D_800FC880_FD480 != -1) {
            /* the stands slide back out */
            goto slide_out;
        slide_out_wait:
            HuPrcVSleep();
        slide_out:
            {
                D_80108258_2F7188_name_46[0]->pos.x -= speed;
                D_80108260_2F7190_name_46[0]->pos.x -= speed;
                D_80108258_2F7188_name_46[1]->pos.x += speed;
                D_80108260_2F7190_name_46[1]->pos.x += speed;
                PLAYER_MODEL(D_801081F0_2F7120_name_46)->pos.x -= speed;
                PLAYER_MODEL(D_801081F4_2F7124_name_46)->pos.x += speed;
                if (!(D_80108258_2F7188_name_46[0]->pos.x <= start)) {
                    goto slide_out_wait;
                }
            }
        } else {
            MBMotionSet(PLAYER_MODEL(D_801081F0_2F7120_name_46), 1, 4);
            func_80029E80_2AA80(D_80108260_2F7190_name_46[0]->obj->model[0], 4, 4);
            MBMotionSet(PLAYER_MODEL(D_801081F4_2F7124_name_46), 1, 4);
            func_80029E80_2AA80(D_80108260_2F7190_name_46[1]->obj->model[0], 4, 4);
            if (D_8010826C_2F719C_name_46 != 0) {
                func_800794A8_7A0A8(60);
            }
        }
        HuPrcSleep(45);
    } else if (D_8010826C_2F719C_name_46 != 0) {
        func_800794A8_7A0A8(30);
        HuPrcSleep(45);
    }
    if (D_800FC880_FD480 == -1) {
        /* a draw: both get their stake back */
        if (D_8010826C_2F719C_name_46 == 0) {
            D_801081D0_2F7100_name_46 = 0;
            func_80104EB0_2F3DE0_name_46(2);
            PD_WAIT_STEP();
            HuPrcSleep(20);
        }
        MBMotionShiftSet(PLAYER_MODEL(D_801081F0_2F7120_name_46), 2, 0, 5, 2);
        MBMotionShiftSet(PLAYER_MODEL(D_801081F4_2F7124_name_46), 2, 0, 5, 2);
        HuPrcSleep(40);
        if (D_8010826C_2F719C_name_46 == 0) {
            MBMotionShiftSet(D_80108274_2F71A4_name_46, 1, 0, 5, 0);
            HuPrcSleep(23);
            MBMotionShiftSet(D_80108274_2F71A4_name_46, 0, 0, 20, 2);
            func_80088640_89240();
            D_80102708_103308 = 1;
            PlaySound(0xE8);
            D_801081E4_2F7114_name_46 = 0x216;
            D_801081D8_2F7108_name_46 = 85;
            D_801081DC_2F710C_name_46 = 70;
            D_801081E0_2F7110_name_46 = 2;
            omAddPrcObj(func_80104880_2F37B0_name_46, 0x12, 0, 0);
            D_801081D0_2F7100_name_46 = 0;
            PD_WAIT_STEP();
            func_800614B4_620B4(D_801081F0_2F7120_name_46, D_801081D4_2F7104_name_46);
            func_8006135C_61F5C(D_801081F4_2F7124_name_46, D_801081D4_2F7104_name_46, 0);
            func_800794A8_7A0A8(30);
            HuPrcSleep(30);
        }
        PlayMusic(0x57);
        func_800691FC_69DFC(0x13);
        PD_WAIT_MESSAGE();
    } else {
        /* the loser's stand blows up */
        func_80107850_2F6780_name_46();
        PD_WAIT_STEP();
        for (i = 0; i < 2; i++) {
            func_801073EC_2F631C_name_46(D_80108268_2F7198_name_46[i]);
        }
        HuPrcSleep(60);
        if (D_8010826C_2F719C_name_46 == 0) {
            D_801081D0_2F7100_name_46 = 0;
            func_80104EB0_2F3DE0_name_46(2);
        }
        PLAYER_MODEL(D_801081F0_2F7120_name_46)->pos.y = 0.0f;
        PLAYER_MODEL(D_801081F4_2F7124_name_46)->pos.y = -0.0f;
        MBMotionShiftSet(PLAYER_MODEL(D_801081F0_2F7120_name_46), 3, 0, 5, 2);
        work[0] = func_8005A718_5B318(PLAYER_MODEL(D_801081F0_2F7120_name_46), 15.0f, 1, D_80107FF0_2F6F20_name_46);
        MBMotionShiftSet(PLAYER_MODEL(D_801081F4_2F7124_name_46), 3, 0, 5, 2);
        work[1] = func_8005A718_5B318(PLAYER_MODEL(D_801081F4_2F7124_name_46), 15.0f, 1, D_80107FFC_2F6F2C_name_46);
        while (TRUE) {
            done = 0;
            for (i = 0; i < 2; i++) {
                if (func_8005A778_5B378(work[i]) != 0) {
                    done++;
                }
            }
            if (done == 2) {
                break;
            }
            HuPrcVSleep();
        }
        for (i = 0; i < 2; i++) {
            HuMemMemoryFreePerm(work[i]);
        }
        MBMotionShiftSet(PLAYER_MODEL(D_801081F0_2F7120_name_46), 2, 0, 5, 2);
        MBMotionShiftSet(PLAYER_MODEL(D_801081F4_2F7124_name_46), 2, 0, 5, 2);
        /* both turn to the camera */
        HuVecCopyXYZ(&pos[0], D_800C9B80_CA780->pos.x, PLAYER_MODEL(D_800FC880_FD480)->pos.y, D_800C9B80_CA780->pos.z);
        HuVecCopyXYZ(&pos[1], D_800C9B80_CA780->pos.x, PLAYER_MODEL(D_800F8C5C_F985C)->pos.y, D_800C9B80_CA780->pos.z);
        func_800446B4_452B4(PLAYER_MODEL(D_800FC880_FD480), &pos[0], 10);
        func_800446B4_452B4(PLAYER_MODEL(D_800F8C5C_F985C), &pos[1], 10);
        HuPrcSleep(20);
        if (D_8010826C_2F719C_name_46 == 0) {
            MBMotionShiftSet(D_80108274_2F71A4_name_46, 1, 0, 5, 0);
            HuPrcSleep(23);
            MBMotionShiftSet(D_80108274_2F71A4_name_46, 0, 0, 20, 2);
            func_80088640_89240();
            D_80102708_103308 = 1;
            PlaySound(0xE8);
            D_801081EC_2F711C_name_46 = D_800FC880_FD480;
            D_801081E4_2F7114_name_46 = 0x215;
            D_801081D8_2F7108_name_46 = 90;
            D_801081DC_2F710C_name_46 = 70;
            D_801081E0_2F7110_name_46 = 3;
            omAddPrcObj(func_80104880_2F37B0_name_46, 0x12, 0, 0);
            D_801081D0_2F7100_name_46 = 0;
            PD_WAIT_STEP();
            func_800614B4_620B4(D_800FC880_FD480, D_801081D4_2F7104_name_46 * 2);
            if (D_80108270_2F71A0_name_46 != -1) {
                func_800799A4_7A5A4(D_80108270_2F71A0_name_46, 40);
            }
            HuPrcSleep(30);
        }
        PlayMusic(0x51);
        winner = D_800FC880_FD480;
        file = D_80107F98_2F6EC8_name_46[gPlayers[winner].character][5];
        x = (winner == D_801081F0_2F7120_name_46) ? 0x2C : 0x54;
        func_800732FC_73EFC(file, x, winner);
        MBMotionSet(PLAYER_MODEL(D_800FC880_FD480), 4, 0);
        func_8005ACD0_5B8D0(&gPlayers[D_800FC880_FD480], 1);
        loserMes = func_800797DC_7A3DC(0xFC, D_800F8C5C_F985C);
        if (D_800F8C5C_F985C == D_801081F0_2F7120_name_46) {
            func_800798F8_7A4F8(loserMes, 0x2C);
        } else {
            func_800798F8_7A4F8(loserMes, 0x54);
        }
        MBMotionSet(PLAYER_MODEL(D_800F8C5C_F985C), 5, 0);
        func_8005ACD0_5B8D0(&gPlayers[D_800F8C5C_F985C], 2);
        func_800691FC_69DFC(6, gPlayers[D_800FC880_FD480].character);
        PD_WAIT_MESSAGE();
    }
    HuPrcSleep(8);
    func_80105280_2F41B0_name_46();
    while (TRUE) {
        HuPrcVSleep();
    }
}
#else
__asm__(".section .rodata");
const char D_80108080_2F6FB0_name_46[] = "\202Q\202R\202S\202T";

__asm__(".section .rodata");
const u32 D_8010808C_2F6FBC_name_46[3] = { 0x00000002, 0x000800A7, 0x000800AA };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_46_name/2F1730", func_80102D0C_2F1C3C_name_46);
__asm__(".section .rodata");
#endif


void func_80104880_2F37B0_name_46(void) {
    s16 size[2];
    char num[0x100];
    char name[0x100];
    s32 win;
    u16 btn;

    if (D_801081E0_2F7110_name_46 == 2) {
        sprintf(num, "%d", D_801081D4_2F7104_name_46);
        func_8008D974_8E574(num, 0);
    }
    if (D_801081E0_2F7110_name_46 == 3) {
        sprintf(num, "%d", D_801081D4_2F7104_name_46);
        sprintf(name, "%c%c", 0x18, gPlayers[D_801081EC_2F711C_name_46].character);
        func_8008D974_8E574(name, 0);
        func_8008D974_8E574(num, 1);
        func_8008D974_8E574(name, 2);
    }
    if (D_801081E0_2F7110_name_46 == 4) {
        sprintf(num, "%d", D_80108298_2F71C8_name_46);
        func_8008D974_8E574(num, 0);
    }
    func_8008DACC_8E6CC(1, size, D_801081E4_2F7114_name_46);
    win = func_80104C88_2F3BB8_name_46((s16)D_801081D8_2F7108_name_46, (s16)D_801081DC_2F710C_name_46, size[0], size[1], 0, 0, 200);
    if (D_801081E8_2F7118_name_46 & 1) {
        ShowTextWindow((s16)win);
    }
    if (D_801081E0_2F7110_name_46 == 2 || D_801081E0_2F7110_name_46 == 4) {
        func_80089308_89F08(win, num, 0);
    }
    if (D_801081E0_2F7110_name_46 == 3) {
        func_80089308_89F08(win, name, 0);
        func_80089308_89F08(win, num, 1);
        func_80089308_89F08(win, name, 2);
    }
    func_8008AD44_8B944(win);
    func_800890CC_89CCC(win, D_801081E4_2F7114_name_46, -1, -1);
    func_80057A78_58678((s16)win, D_801081F0_2F7120_name_46, D_801081F4_2F7124_name_46);
    if (D_801081E0_2F7110_name_46 == 1 && (gPlayers[D_801081F0_2F7120_name_46].flags & 1) && (gPlayers[D_801081F4_2F7124_name_46].flags & 1)) {
        func_8010675C_2F568C_name_46(0, 0, 0);
    }
    while (TRUE) {
        switch (D_801081E0_2F7110_name_46) {
            case 1:
                if ((gPlayers[D_801081F0_2F7120_name_46].flags & 1) && (gPlayers[D_801081F4_2F7124_name_46].flags & 1)) {
                    btn = func_80106F2C_2F5E5C_name_46();
                } else {
                    btn = func_80104DF0_2F3D20_name_46();
                }
                if (btn & 0x1000) {
                    PlaySound(2);
                    D_801081D0_2F7100_name_46 = 1;
                    func_8008CCA8_8D8A8(win);
                    omDelPrcObj(NULL);
                }
                break;
            case 2:
            case 3:
            case 4:
                if (D_801081E8_2F7118_name_46 & 1) {
                    func_8005762C_5822C((s16)win);
                } else {
                    func_8008CCA8_8D8A8(win);
                }
                D_801081D0_2F7100_name_46 = 1;
                omDelPrcObj(NULL);
                break;
        }
        HuPrcVSleep();
    }
}

#ifdef NON_MATCHING
s32 func_80104C88_2F3BB8_name_46(s16 x, s16 y, s16 w, s16 h, s16 arg4, s16 arg5, s32 arg6) {
    s32 win;
    s16 mask;

    win = func_800888A8_894A8(x, y, w, h, arg4, arg5);
    func_80089284_89E84(win, 0x40, 0x40);
    func_80089A48_8A648(win, 0);
    func_8008D88C_8E48C(win);
    func_80089B2C_8A72C(win, arg6);
    if (D_801081F4_2F7124_name_46 != -1) {
        mask = (1 << gPlayers[D_801081F0_2F7120_name_46].port) | (1 << gPlayers[D_801081F4_2F7124_name_46].port);
    } else {
        mask = 1 << gPlayers[D_801081F0_2F7120_name_46].port;
    }
    func_8008D59C_8E19C(win, mask);
    return (s16)win;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_46_name/2F1730", func_80104C88_2F3BB8_name_46);
#endif

u16 func_80104DF0_2F3D20_name_46(void) {
    u16 btn;

    btn = 0;
    if (!(gPlayers[D_801081F0_2F7120_name_46].flags & 1)) {
        btn = ContDStkTrg[gPlayers[D_801081F0_2F7120_name_46].port];
    }
    if (D_801081F4_2F7124_name_46 != -1 && btn == 0) {
        if (!(gPlayers[D_801081F4_2F7124_name_46].flags & 1)) {
            btn = ContDStkTrg[gPlayers[D_801081F4_2F7124_name_46].port];
        }
    }
    return btn;
}

void func_80104EB0_2F3DE0_name_46(s32 layout) {
    omObjData* obj;
    s32* work;
    BoardStatus* status;
    s32 slot;
    s32 i;
    s32 next;

    D_801081D0_2F7100_name_46 = 0;
    obj = omAddObj(0x12, 0, 0, -1, func_801051E8_2F4118_name_46);
    work = func_80027154_27D54(8, 0x7918);
    obj->unk_50 = work;
    *work = layout;
    next = 0;
    for (i = 0; i < 4; i++) {
        if (D_801081F8_2F7128_name_46[i] != 0) {
            status = &D_80101510_102110[i];
            slot = 3;
            if (i != D_801081F0_2F7120_name_46) {
                if (i == D_801081F4_2F7124_name_46) {
                    slot = 2;
                } else {
                    slot = next;
                    D_80108210_2F7140_name_46[slot] = i;
                    next = slot + 1;
                }
            }
            if (D_80107DD0_2F6D00_name_46[layout].pos[slot][0] != -1) {
                status->xPos = D_80107DD0_2F6D00_name_46[layout].pos[slot][0];
            }
            if (D_80107DD0_2F6D00_name_46[layout].pos[slot][1] != -1) {
                status->yPos = D_80107DD0_2F6D00_name_46[layout].pos[slot][1];
            }
            func_800600F8_60CF8(i, status->xPos, status->yPos);
            status->unk_0C = D_80107DD0_2F6D00_name_46[layout].frames - 1;
            if (D_80107DD0_2F6D00_name_46[layout].pos[slot][2] != -1) {
                status->unk_18 = D_80107DD0_2F6D00_name_46[layout].pos[slot][2];
            }
            if (D_80107DD0_2F6D00_name_46[layout].pos[slot][3] != -1) {
                status->unk_1C = D_80107DD0_2F6D00_name_46[layout].pos[slot][3];
            }
            status->unk_20 = status->unk_28 = 2.0f * (status->unk_18 - status->xPos) / ((status->unk_0C + 1) * (status->unk_0C + 1));
            status->unk_24 = status->unk_2C = 2.0f * (status->unk_1C - status->yPos) / ((status->unk_0C + 1) * (status->unk_0C + 1));
        }
    }
    if (D_80107FB0_2F6EE0_name_46 == 1) {
        status = &D_80101510_102110[D_801081F0_2F7120_name_46];
        D_800FD854_FE454[0].unk_00 = D_800FC990_FD590[0].unk_00 = status->unk_28;
        D_800FD854_FE454[0].unk_04 = D_800FC990_FD590[0].unk_04 = status->unk_2C;
        D_800FA604_FB204 = D_80107DD0_2F6D00_name_46[layout].frames - 1;
    }
}

void func_801051E8_2F4118_name_46(omObjData* obj) {
    BoardStatus* status;
    s32 done;
    s32 i;

    done = 0;
    for (i = 0; i < 4; i++) {
        if (D_801081F8_2F7128_name_46[i] != 0) {
            status = &D_80101510_102110[i];
            if (status->unk_0C == 0) {
                status->xPos = status->unk_18;
                status->yPos = status->unk_1C;
                done++;
            }
        }
    }
    if (done == D_80108208_2F7138_name_46) {
        D_801081D0_2F7100_name_46 = 1;
        omDelObj(obj);
    }
}

void func_80105280_2F41B0_name_46(void) {
    omAddObj(0x10, 0, 0, -1, func_801052BC_2F41EC_name_46);
    func_80069764_6A364(60);
}

void func_801052BC_2F41EC_name_46(omObjData* obj) {
    if (func_800696E4_6A2E4() == 0) {
        InitFadeOut(0, 20);
        if (D_8010826C_2F719C_name_46 != 0) {
            func_80079614_7A214(20);
        }
        obj->func_ptr = func_80105314_2F4244_name_46;
    }
}

void func_80105314_2F4244_name_46(omObjData* obj) {
    if (func_8008F618_90218() == 0) {
        MBDBackKill();
        func_80050AE0_516E0();
        func_80059400_5A000();
        func_80069770_6A370();
        func_8008CE5C_8DA5C();
        omOvlReturnEx(1);
    }
}

void func_80105368_2F4298_name_46(void) {
    omObjData* obj;
    PdShrink* work;

    obj = omAddObj(0x10, 0, 0, -1, func_801053F8_2F4328_name_46);
    work = func_80027154_27D54(sizeof(PdShrink), 0x7918);
    obj->unk_50 = work;
    work->scaleSpeed = -0.06666667f;
    work->rotSpeed = -3.0f;
    work->unk10 = 0;
    work->unkC = 1.0f;
    work->timer = 15;
}

void func_801053F8_2F4328_name_46(omObjData* obj) {
    PdShrink* work = obj->unk_50;

    D_80108278_2F71A8_name_46->scale.x += work->scaleSpeed;
    D_80108278_2F71A8_name_46->scale.y += work->scaleSpeed;
    D_80108278_2F71A8_name_46->scale.z += work->scaleSpeed;
    D_80108278_2F71A8_name_46->obj->rot.x += work->rotSpeed;
    if (--work->timer == 0) {
        MBModelDispOff(D_80108278_2F71A8_name_46);
        omDelObj(obj);
    }
}

void func_80105488_2F43B8_name_46(void) {
    s32 ys4[3] = { 32, 90, 148 };
    s32 ys3[2] = { 59, 121 };
    s32 ys[4];
    s16 size[2];
    s32* src;
    s32 win;
    s16 spr;
    u16 btn;
    s32 sel;
    s32 count;
    s32 i;

    func_8008DACC_8E6CC(1, size, 0x212);
    win = func_80104C88_2F3BB8_name_46(70, 178, size[0], size[1], 0, 0, 200);
    func_8008AD44_8B944(win);
    func_800890CC_89CCC(win, 0x212, -1, -1);
    sel = 0;
    count = D_80108208_2F7138_name_46 - 1;
    if (D_80108208_2F7138_name_46 == 4) {
        src = ys4;
    } else {
        src = ys3;
    }
    for (i = 0; i < D_80108208_2F7138_name_46; i++) {
        ys[i] = *src++;
    }
    spr = func_8001AAAC_1B6AC(func_8001A2F8_1AEF8(0x42), 1, 1);
    espDispOn(spr);
    if (gPlayers[D_801081F0_2F7120_name_46].flags & 1) {
        func_8010675C_2F568C_name_46(sel, 0, 2);
    }
    while (TRUE) {
        btn = func_80104DF0_2F3D20_name_46();
        if (gPlayers[D_801081F0_2F7120_name_46].flags & 1) {
            btn = func_80106F2C_2F5E5C_name_46();
        }
        if ((btn & 0x8000) && BoardSpaceGet(D_80108210_2F7140_name_46[sel], 1) != 0) {
            PlaySound(2);
            D_801081D0_2F7100_name_46 = 1;
            D_801081F4_2F7124_name_46 = D_80108210_2F7140_name_46[sel];
            espDispOff(spr);
            func_8008CCA8_8D8A8(win);
            omDelPrcObj(NULL);
        }
        if (btn & 0x400) {
            PlaySound(1);
            sel++;
            if (sel >= count) {
                sel = 0;
            }
        }
        if (btn & 0x800) {
            PlaySound(1);
            sel--;
            if (sel < 0) {
                sel = count - 1;
            }
        }
        espPosSet(spr, 184, ys[sel]);
        D_800F851A_F911A = 1;
        HuPrcVSleep();
    }
}

#define PD_STAKE_SHOW(win, stake)                                           \
    sprintf(num, "%d", stake);                                              \
    len = func_800A5610_A6210(num);                                         \
    for (j = 0; j < 3 - len; j++) {                                         \
        pad[j] = 0x1A;                                                      \
    }                                                                       \
    pad[j] = 0;                                                             \
    sprintf(buf, "%c%c%s%d", 0xF, 6, pad, stake);                           \
    func_800890CC_89CCC(win, (s32)buf, x, y)

void func_80105754_2F4684_name_46(void) {
    s32 stakes[6] = { 1, 5, 10, 20, 30, 50 };
    s32 turns[4] = { 11, 21, 36, 46 };
    char buf[0x200];
    char mess[0x20];
    s16 size[2];
    char num[8];
    char pad[16];
    s32 win;
    s32 coins1;
    s32 coins2;
    u16 btn;
    s32 stake;
    s32 len;
    s32 turn;
    s32 y;
    s32 x;
    s32 i;
    s32 j;

    turn = D_80108224_2F7154_name_46;
    i = 0;
    while (turn >= turns[i]) {
        if (++i == 4) {
            break;
        }
    }
    coins1 = BoardPlayerGet(D_801081F0_2F7120_name_46)->coins;
    coins2 = BoardPlayerGet(D_801081F4_2F7124_name_46)->coins;
    D_80108234_2F7164_name_46 = coins1;
    if (coins2 < coins1) {
        D_80108234_2F7164_name_46 = coins2;
    }
    i++;
    while (D_80108234_2F7164_name_46 < stakes[i]) {
        if (--i == 0) {
            break;
        }
    }
    D_801081D4_2F7104_name_46 = D_80108220_2F7150_name_46 = stakes[i];
    x = 0x2F;
    y = 0x2E;
    stake = D_80108220_2F7150_name_46;
    sprintf(mess, "", stake);
    func_8008D974_8E574(mess, 0);
    func_8008DACC_8E6CC(1, size, 0x213);
    win = func_80104C88_2F3BB8_name_46(24, 72, size[0], size[1], 0, 0, 200);
    func_80089308_89F08(win, mess, 0);
    func_8008AD44_8B944(win);
    func_800890CC_89CCC(win, 0x213, -1, -1);
    HuPrcVSleep();
    func_80089284_89E84(win, 0x10004, 0x10004);
    PD_STAKE_SHOW(win, stake);
    func_80057730_58330(win, D_801081F0_2F7120_name_46);
    AdjustPlayerCoins(D_801081F0_2F7120_name_46, -D_801081D4_2F7104_name_46);
    AdjustPlayerCoins(D_801081F4_2F7124_name_46, -D_801081D4_2F7104_name_46);
    func_80089284_89E84(win, 4, 4);
    if (gPlayers[D_801081F0_2F7120_name_46].flags & 1) {
        func_8010675C_2F568C_name_46(D_801081D4_2F7104_name_46, D_80108234_2F7164_name_46, 3);
    }
    while (TRUE) {
        D_801081D4_2F7104_name_46 = stake;
        btn = ContDStkTrg[gPlayers[D_801081F0_2F7120_name_46].port];
        if (gPlayers[D_801081F0_2F7120_name_46].flags & 1) {
            btn = func_80106F2C_2F5E5C_name_46();
        }
        if (btn & 0x8000) {
            PlaySound(2);
            D_800F851A_F911A = 0;
            func_8008CCA8_8D8A8(win);
            D_801081D0_2F7100_name_46 = 1;
            omDelPrcObj(NULL);
        } else if (btn & 0x800) {
            if (gPlayers[D_801081F0_2F7120_name_46].coins > 0 && gPlayers[D_801081F4_2F7124_name_46].coins > 0) {
                if (++stake >= 1000) {
                    stake = 999;
                } else {
                    PlaySound(0x37B);
                }
                PD_STAKE_SHOW(win, stake);
                AdjustPlayerCoins(D_801081F0_2F7120_name_46, -1);
                AdjustPlayerCoins(D_801081F4_2F7124_name_46, -1);
            }
        } else if (btn & 0x400) {
            if (D_80108220_2F7150_name_46 < stake) {
                stake--;
                PlaySound(0x37C);
                PD_STAKE_SHOW(win, stake);
                AdjustPlayerCoins(D_801081F0_2F7120_name_46, 1);
                AdjustPlayerCoins(D_801081F4_2F7124_name_46, 1);
            }
        } else if (btn & 0x200) {
            if (stake - 10 >= D_80108220_2F7150_name_46) {
                stake -= 10;
                PlaySound(0x37C);
                PD_STAKE_SHOW(win, stake);
                AdjustPlayerCoins(D_801081F0_2F7120_name_46, 10);
                AdjustPlayerCoins(D_801081F4_2F7124_name_46, 10);
            }
        } else if (btn & 0x100) {
            if (gPlayers[D_801081F0_2F7120_name_46].coins >= 10 && gPlayers[D_801081F4_2F7124_name_46].coins >= 10) {
                stake += 10;
                if (stake >= 1000) {
                    stake = 999;
                } else {
                    PlaySound(0x37B);
                }
                PD_STAKE_SHOW(win, stake);
                AdjustPlayerCoins(D_801081F0_2F7120_name_46, -10);
                AdjustPlayerCoins(D_801081F4_2F7124_name_46, -10);
            }
        }
        HuPrcVSleep();
    }
}

void func_80105FD0_2F4F00_name_46(void) {
    omObjData* obj;
    s32* work;

    obj = omAddObj(0x10, 0, 0, -1, func_80106038_2F4F68_name_46);
    work = func_80027154_27D54(8, 0x7918);
    obj->unk_50 = work;
    work[1] = 0;
    D_80108238_2F7168_name_46[0] = -1;
    D_80108238_2F7168_name_46[1] = -1;
}

/* The duel: each side presses A (a CPU at its preset frame); the press nearer the target
   (D_80108298 seconds, 30 frames each) wins; nobody pressing by frame 900 counts as 1000. */
#ifdef NON_MATCHING
/* masked 0: only the registers of the final comparison differ. */
void func_80106038_2F4F68_name_46(omObjData* obj) {
    s32* work;
    s32 diff1;
    s32 diff0;
    s32 target;

    work = obj->unk_50;
    if (gPlayers[D_801081F0_2F7120_name_46].flags & 1) {
        if (work[1] == D_80108228_2F7158_name_46[0]) {
            func_80029E80_2AA80(PLAYER_MODEL(D_801081F0_2F7120_name_46)->obj->model[0], 1, 0);
            func_80029E80_2AA80(D_80108260_2F7190_name_46[0]->obj->model[0], 1, 0);
            func_80029E80_2AA80(D_80108260_2F7190_name_46[0]->obj->model[0], 2, 0);
            D_80108238_2F7168_name_46[0] = work[1];
            func_8007975C_7A35C(0x3C8, (s16)D_801081F0_2F7120_name_46);
        }
    } else if ((ContBtnTrg[gPlayers[D_801081F0_2F7120_name_46].port] & 0x8000) && D_80108238_2F7168_name_46[0] == -1) {
        func_80029E80_2AA80(PLAYER_MODEL(D_801081F0_2F7120_name_46)->obj->model[0], 1, 0);
        func_80029E80_2AA80(D_80108260_2F7190_name_46[0]->obj->model[0], 1, 0);
        func_80029E80_2AA80(D_80108260_2F7190_name_46[0]->obj->model[0], 2, 0);
        D_80108238_2F7168_name_46[0] = work[1];
        func_8007975C_7A35C(0x3C8, (s16)D_801081F0_2F7120_name_46);
    }
    if (gPlayers[D_801081F4_2F7124_name_46].flags & 1) {
        if (work[1] == D_8010822C_2F715C_name_46) {
            func_80029E80_2AA80(PLAYER_MODEL(D_801081F4_2F7124_name_46)->obj->model[0], 1, 0);
            func_80029E80_2AA80(D_80108264_2F7194_name_46->obj->model[0], 1, 0);
            func_80029E80_2AA80(D_80108264_2F7194_name_46->obj->model[0], 2, 0);
            D_80108238_2F7168_name_46[1] = work[1];
            func_8007975C_7A35C(0x3C8, (s16)D_801081F4_2F7124_name_46);
        }
    } else if ((ContBtnTrg[gPlayers[D_801081F4_2F7124_name_46].port] & 0x8000) && D_80108238_2F7168_name_46[1] == -1) {
        func_80029E80_2AA80(PLAYER_MODEL(D_801081F4_2F7124_name_46)->obj->model[0], 1, 0);
        func_80029E80_2AA80(D_80108264_2F7194_name_46->obj->model[0], 1, 0);
        func_80029E80_2AA80(D_80108264_2F7194_name_46->obj->model[0], 2, 0);
        D_80108238_2F7168_name_46[1] = work[1];
        func_8007975C_7A35C(0x3C8, (s16)D_801081F4_2F7124_name_46);
    }
    if (++work[1] == 900) {
        if (D_80108238_2F7168_name_46[0] == -1) {
            D_80108238_2F7168_name_46[0] = 1000;
        }
        if (D_80108238_2F7168_name_46[1] == -1) {
            D_80108238_2F7168_name_46[1] = 1000;
        }
    }
    if ((diff0 = D_80108238_2F7168_name_46[0]) != -1 && (diff1 = D_80108238_2F7168_name_46[1]) != -1) {
        target = D_80108298_2F71C8_name_46 * 30;
        diff0 = target - diff0;
        if (diff0 < 0) {
            diff0 = -diff0;
        }
        diff1 = target - diff1;
        if (diff1 < 0) {
            diff1 = -diff1;
        }
        if (diff0 < diff1) {
            D_80108230_2F7160_name_46 = 2;
        }
        if (diff1 < diff0) {
            D_80108230_2F7160_name_46 = 3;
        }
        if (diff0 == diff1) {
            D_80108230_2F7160_name_46 = 1;
        }
        D_801081D0_2F7100_name_46 = 1;
        func_80079848_7A448(D_80108272_2F71A2_name_46);
        omDelObj(obj);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_46_name/2F1730", func_80106038_2F4F68_name_46);
#endif

s32 func_80106470_2F53A0_name_46(void) {
    s32 cand[4];
    s32 n;
    s32 i;

    n = 0;
    for (i = 0; i < D_80108208_2F7138_name_46 - 1; i++) {
        if (func_80059FD0_5ABD0(D_80108210_2F7140_name_46[i]) == 0 && gPlayers[D_80108210_2F7140_name_46[i]].coins > 0) {
            cand[n++] = i;
        }
    }
    if (n == 0) {
        for (i = 0; i < D_80108208_2F7138_name_46 - 1; i++) {
            if (func_80059FD0_5ABD0(D_80108210_2F7140_name_46[i]) == 1 && gPlayers[D_80108210_2F7140_name_46[i]].coins > 0) {
                cand[n++] = i;
            }
        }
    }
    if (n == 0) {
        for (i = 0; i < D_80108208_2F7138_name_46 - 1; i++) {
            if (func_80059FD0_5ABD0(D_80108210_2F7140_name_46[i]) == 2 && gPlayers[D_80108210_2F7140_name_46[i]].coins > 0) {
                cand[n++] = i;
            }
        }
    }
    if (n == 0) {
        for (i = 0; i < D_80108208_2F7138_name_46 - 1; i++) {
            if (func_80059FD0_5ABD0(D_80108210_2F7140_name_46[i]) == 3 && gPlayers[D_80108210_2F7140_name_46[i]].coins > 0) {
                cand[n++] = i;
            }
        }
    }
    return cand[rand8() % n];
}

__asm__(".section .rodata");
const u32 D_801080F8_2F7028_name_46[32] = { 0xFFFFFFFF, 0x00000001, 0x00000003, 0x00000002, 0x00000003, 0x00000003, 0x00000003, 0x00000003, 0x00000000, 0x00000001, 0xFFFFFFFF, 0x00000001, 0x00000001, 0x00000002, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000001, 0xFFFFFFFF, 0x00000001, 0x00000001, 0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000001, 0xFFFFFFFF, 0xFFFFFFFF };

__asm__(".section .rodata");
const u32 D_80108178_2F70A8_name_46[4] = { 0x0000000A, 0x00000014, 0x00000014, 0x00000009 };

__asm__(".section .rodata");
const u32 D_80108188_2F70B8_name_46[4] = { 0x0000005A, 0x0000003C, 0x00000014, 0x00000001 };

#ifdef NON_MATCHING
void func_8010675C_2F568C_name_46(s32 cur, s32 target, s32 mode) {
    s32 cand[4];
    s32 flag[4];
    s32 rows[32] = {
        -1, 1, 3, 2, 3, 3, 3, 3,
        0, 1, -1, 1, 1, 2, 1, 2,
        0, 1, 0, 1, -1, 1, 1, 2,
        0, 0, 0, 1, 0, 1, -1, -1,
    };
    s32 range[4] = { 10, 20, 20, 9 };
    s32 base[4] = { 90, 60, 20, 1 };
    s32 unused[8];
    omObjData* obj;
    PdCpuInput* work;
    s32 diff;
    s32 row;
    s32 n;
    s32 i;

    obj = omAddObj(0x10, 0, 0, -1, func_80106D8C_2F5CBC_name_46);
    work = obj->unk_50 = func_80027154_27D54(sizeof(PdCpuInput), 0x7918);
    work->timer = 0;
    work->cur = cur;
    work->target = target;
    work->mode = mode;
    D_80108248_2F7178_name_46 = 0;
    if (mode == 2) {
        if (gPlayers[D_801081F0_2F7120_name_46].coins >= 20) {
            n = 0;
            for (i = 0; i < D_80108208_2F7138_name_46 - 1; i++) {
                flag[i] = 0;
            }
            for (i = 0; i < D_80108208_2F7138_name_46 - 1; i++) {
                if (func_80059FD0_5ABD0(D_80108210_2F7140_name_46[i]) == 0) {
                    flag[i] = 1;
                    n++;
                }
            }
            if (n == 0) {
                for (i = 0; i < D_80108208_2F7138_name_46 - 1; i++) {
                    if (func_80059FD0_5ABD0(D_80108210_2F7140_name_46[i]) == 1) {
                        flag[i] = 1;
                        n++;
                    }
                }
            }
            if (n == 0) {
                for (i = 0; i < D_80108208_2F7138_name_46 - 1; i++) {
                    if (func_80059FD0_5ABD0(D_80108210_2F7140_name_46[i]) == 2) {
                        flag[i] = 1;
                        n++;
                    }
                }
            }
            if (n == 0) {
                for (i = 0; i < D_80108208_2F7138_name_46 - 1; i++) {
                    if (func_80059FD0_5ABD0(D_80108210_2F7140_name_46[i]) == 3) {
                        flag[i] = 1;
                        n++;
                    }
                }
            }
            n = 0;
            for (i = 0; i < D_80108208_2F7138_name_46 - 1; i++) {
                if (flag[i] != 0 && gPlayers[D_80108210_2F7140_name_46[i]].coins >= 20) {
                    cand[n++] = i;
                }
            }
            if (n == 0) {
                for (i = 0; i < D_80108208_2F7138_name_46 - 1; i++) {
                    if (flag[i] == 0 && gPlayers[D_80108210_2F7140_name_46[i]].coins >= 20) {
                        cand[n++] = i;
                    }
                }
            }
            if (n > 0) {
                work->target = cand[rand8() % n];
            } else {
                work->target = func_80106470_2F53A0_name_46();
            }
        } else {
            work->target = func_80106470_2F53A0_name_46();
        }
    }
    if (mode == 3) {
        row = func_80059FD0_5ABD0(D_801081F0_2F7120_name_46) * 8;
        row += func_80059FD0_5ABD0(D_801081F0_2F7120_name_46) * 2;
        diff = PD_ABS(gPlayers[D_801081F0_2F7120_name_46].stars - gPlayers[D_801081F4_2F7124_name_46].stars);
        row += diff < 2;
        work->target = (rand8() % range[rows[row]] + base[rows[row]]) * D_80108234_2F7164_name_46 / 100;
        if (work->target < D_80108220_2F7150_name_46) {
            work->target = D_80108220_2F7150_name_46;
        }
    }
}
#else
__asm__(".section .rodata");


INCLUDE_ASM("asm/nonmatchings/overlays/ovl_46_name/2F1730", func_8010675C_2F568C_name_46);
#endif

void func_80106D8C_2F5CBC_name_46(omObjData* obj) {
    PdCpuInput* work = obj->unk_50;

    D_80108248_2F7178_name_46 = 0;
    if (++work->timer >= 10) {
        switch (work->mode) {
            case 0:
                if (work->timer >= 30) {
                    D_80108248_2F7178_name_46 = 0x1000;
                    omDelObj(obj);
                }
                break;
            case 1:
                if (work->timer >= 30) {
                    D_80108248_2F7178_name_46 = 0x8000;
                    omDelObj(obj);
                }
                break;
            case 2:
                if (work->cur == work->target) {
                    D_80108248_2F7178_name_46 = 0x8000;
                    omDelObj(obj);
                } else if (work->cur < work->target) {
                    D_80108248_2F7178_name_46 = 0x400;
                    work->cur++;
                    work->timer = 0;
                } else if (work->cur > work->target) {
                    D_80108248_2F7178_name_46 = 0x800;
                    work->cur--;
                    work->timer = 0;
                }
                break;
            case 3:
                work->cur = D_801081D4_2F7104_name_46;
                if (work->cur == work->target) {
                    D_80108248_2F7178_name_46 = 0x8000;
                    omDelObj(obj);
                } else if (work->cur - work->target >= 10) {
                    D_80108248_2F7178_name_46 = 0x200;
                    work->timer = 0;
                } else if (work->cur - work->target < -9) {
                    D_80108248_2F7178_name_46 = 0x100;
                    work->timer = 0;
                } else if (work->cur - work->target < 10) {
                    D_80108248_2F7178_name_46 = 0x800;
                    work->timer = 0;
                } else if (work->cur - work->target >= -9) {
                    D_80108248_2F7178_name_46 = 0x400;
                    work->timer = 0;
                }
                break;
        }
    }
}

s32 func_80106F2C_2F5E5C_name_46(void) {
    return D_80108248_2F7178_name_46;
}

void func_80106F38_2F5E68_name_46(void) {
    f32 scale;
    s32 i;

    scale = D_80108250_2F7180_name_46[0]->scale.x;
    while (TRUE) {
        while (scale >= 0.95f) {
            for (i = 0; i < 2; i++) {
                if (D_80108238_2F7168_name_46[i] == 0) {
                    D_80108250_2F7180_name_46[i]->scale.x = scale;
                    D_80108250_2F7180_name_46[i]->scale.y = scale;
                    D_80108250_2F7180_name_46[i]->scale.z = scale;
                }
            }
            scale -= 0.0071f;
            HuPrcVSleep();
        }
        while (scale <= 1.05f) {
            for (i = 0; i < 2; i++) {
                if (D_80108238_2F7168_name_46[i] == 0) {
                    D_80108250_2F7180_name_46[i]->scale.x = scale;
                    D_80108250_2F7180_name_46[i]->scale.y = scale;
                    D_80108250_2F7180_name_46[i]->scale.z = scale;
                }
            }
            scale += 0.0071f;
            HuPrcVSleep();
        }
        if (scale >= 1.05f && D_80108238_2F7168_name_46[0] != 0 && D_80108238_2F7168_name_46[1] != 0) {
            omDelPrcObj(NULL);
        }
    }
}

void func_801070C8_2F5FF8_name_46(void) {
    void* data;

    data = DataRead(0x3A);
    D_8010827C_2F71AC_name_46 = SprAnimRead(data);
    DataClose(data);
    data = DataRead(0x38);
    D_8010828C_2F71BC_name_46 = SprAnimRead(data);
    DataClose(data);
    data = DataRead(0x3C);
    D_8010828A_2F71BA_name_46 = SprAnimRead(data);
    DataClose(data);
    D_80108288_2F71B8_name_46 = 0;
}

s16 func_80107158_2F6088_name_46(s16 x, s16 y) {
    s32 xs[5] = { -36, -16, 4, 8, 22 };
    s32 ys[5] = { 0, 0, 0, 4, 4 };
    s32 anims[5] = { D_8010827C_2F71AC_name_46, D_8010827C_2F71AC_name_46, D_8010828A_2F71BA_name_46,
                     D_8010828C_2F71BC_name_46, D_8010828C_2F71BC_name_46 };
    s16 group;
    s16 i;

    group = D_8010827E_2F71AE_name_46[D_80108288_2F71B8_name_46] = SprCreate(6, 5);
    func_800824F4_830F4(group, 1, 0);
    func_800824F4_830F4(group, 2, 0);
    func_800824F4_830F4(group, 3, 0);
    func_800824F4_830F4(group, 4, 0);
    func_800824F4_830F4(group, 5, 0);
    SprAnimSet(group, 0, D_8010827C_2F71AC_name_46, 0);
    SprAttrReset(group, 0, 0xFFFF);
    SprAttrSet(group, 0, 0x8000);
    SprPosSet(group, 0, x, y);
    for (i = 1; i < 6; i++) {
        SprAnimSet(group, i, anims[i - 1], 0);
        SprAttrReset(group, i, 0xFFFF);
        SprAttrSet(group, i, 0x8000);
        SprPosSet(group, i, xs[i - 1], ys[i - 1]);
    }
    D_80108288_2F71B8_name_46++;
    return group;
}

void func_801073EC_2F631C_name_46(s16 group) {
    s16 i;

    for (i = 0; i < 6; i++) {
        SprAttrSet(group, i, 0x8000);
    }
}

void func_80107448_2F6378_name_46(s16 group, f32 secs) {
    s32 n;

    n = secs * 100.0f;
    SprAttrReset(group, 5, 0x8000);
    func_800822A8_82EA8(group, 5, n % 10, 0);
    n /= 10;
    func_8008225C_82E5C(group, 5, 1);
    SprAttrReset(group, 4, 0x8000);
    func_800822A8_82EA8(group, 4, n % 10, 0);
    n /= 10;
    func_8008225C_82E5C(group, 4, 1);
    SprAttrReset(group, 3, 0x8000);
    func_800822A8_82EA8(group, 3, 7, 0);
    func_8008225C_82E5C(group, 3, 1);
    SprAttrReset(group, 2, 0x8000);
    func_800822A8_82EA8(group, 2, n % 10, 0);
    n /= 10;
    func_8008225C_82E5C(group, 2, 1);
    if (n != 0) {
        SprAttrReset(group, 1, 0x8000);
        func_800822A8_82EA8(group, 1, n, 0);
        func_8008225C_82E5C(group, 1, 1);
    } else {
        SprAttrSet(group, 1, 0x8000);
    }
}

void func_80107644_2F6574_name_46(s16 group, f32 scale) {
    s16 i;

    for (i = 0; i < 6; i++) {
        SprScaleSet(group, i, scale, scale);
    }
}

/* The winner's time pulses (1.0 -> 0.8 -> 1.2) for at least 30 frames; nothing on a draw. */
#ifdef NON_MATCHING
/* Only the winner test differs: retail branches (and reloads D_80108230) where this compiles
   to a set-on-equal. */
void func_801076B4_2F65E4_name_46(void) {
    f32 scale;
    f32 step;
    s32 side;
    s32 i;

    scale = 1.0f;
    side = 0;
    if (D_80108230_2F7160_name_46 == 3) {
        side = 1;
    }
    if (D_80108230_2F7160_name_46 == 1) {
        omDelPrcObj(NULL);
    }
    step = -0.05f;
    i = 0;
    while (TRUE) {
        scale += step;
        if ((step < 0.0f) & (scale < 0.8f)) {
            step = -step;
        } else if ((step > 0.0f) & (scale > 1.2f)) {
            step = -step;
        }
        i++;
        func_80107644_2F6574_name_46(D_80108268_2F7198_name_46[side], scale);
        HuPrcVSleep();
        if ((i >= 30) & (scale == 1.0f)) {
            break;
        }
    }
    omDelPrcObj(NULL);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_46_name/2F1730", func_801076B4_2F65E4_name_46);
#endif

void func_80107850_2F6780_name_46(void) {
    omObjData* obj;
    Ovl46Blast* work;
    s32 side;

    side = (D_80108230_2F7160_name_46 == 2);
    if (D_80108230_2F7160_name_46 == 3) {
        side = 0;
    }
    if (D_80108230_2F7160_name_46 != 1) {
        obj = omAddObj(0x10, 0, 0, -1, func_80107978_2F68A8_name_46);
        work = func_80027154_27D54(sizeof(Ovl46Blast), 0x7918);
        obj->unk_50 = work;
        work->unk0 = 0;
        work->scale = 0;
        work->frame = 0;
        work->side = side;
        work->grow = 1.0f;
        HmfModelObjAttrSet(D_80108250_2F7180_name_46[work->side]->obj->model[0], 0x20000, 0x20000);
        func_80029A8C_2A68C(D_80108250_2F7180_name_46[work->side]->obj->model[0]);
        func_8002A00C_2AC0C(D_80108250_2F7180_name_46[work->side]->obj->model[0]);
        D_800CA02C_CAC2C = 0;
    }
}

void func_80107978_2F68A8_name_46(omObjData* obj) {
    Ovl46Blast* work;
    MBModel* model;

    work = obj->unk_50;
    work->grow += 0.01f;
    if (work->grow < 1.3f) {
        D_80108250_2F7180_name_46[work->side]->scale.x = work->grow;
        D_80108250_2F7180_name_46[work->side]->scale.y = work->grow;
        D_80108250_2F7180_name_46[work->side]->scale.z = work->grow;
        return;
    }
    if (work->unk0 == 0.0f) {
        func_800298A4_2A4A4((s16)D_8010824C_2F717C_name_46, 4, 0);
        model = D_80108250_2F7180_name_46[work->side];
        func_80029714_2A314((s16)D_8010824C_2F717C_name_46, model->pos.x, model->pos.y + 250.0f, model->pos.z);
        func_800297E8_2A3E8((s16)D_8010824C_2F717C_name_46, 5.0f, 5.0f, 5.0f);
        func_80029E80_2AA80((s16)D_8010824C_2F717C_name_46, 1, 0);
        func_80029FE4_2ABE4((s16)D_8010824C_2F717C_name_46, 2.5f);
        omVibrate(D_800F8C5C_F985C, 20, 0, 20);
        func_800794A8_7A0A8(45);
        PlaySound(0x3C7);
        D_80108270_2F71A0_name_46 = PlaySound(0x4B5);
    }
    func_8002AC10_2B810(D_80108250_2F7180_name_46[work->side]->obj->model[0], work->unk0, work->scale, 2);
    D_800CA02C_CAC2C += 20.0f;
    if (work->unk0 < 1.0f) {
        work->unk0 += 0.02f;
    }
    func_800297E8_2A3E8(D_80108250_2F7180_name_46[work->side]->obj->model[0], work->scale, work->scale, work->scale);
    work->scale += 0.4f;
    if (++work->frame == 2) {
        D_801081D0_2F7100_name_46 = 1;
    }
    if (work->scale >= 16.0f) {
        MBModelDispOff(D_80108250_2F7180_name_46[work->side]);
        omDelObj(obj);
    }
}

void func_80107C44_2F6B74_name_46(s32 side) {
    f32 v[2][2];
    omObjData* obj;
    Ovl46Bob* work;

    v[0][0] = 2.5f;
    v[0][1] = -2.5f;
    v[1][0] = 1.0f;
    v[1][1] = -1.0f;
    obj = omAddObj(0x10, 0, 0, -1, func_80107D00_2F6C30_name_46);
    work = func_80027154_27D54(sizeof(Ovl46Bob), 0x7918);
    obj->unk_50 = work;
    work->vel = v[0][side];
    work->acc = v[1][side];
    work->side = side;
}

void func_80107D00_2F6C30_name_46(omObjData* obj) {
    Ovl46Bob* work;

    work = obj->unk_50;
    D_80108250_2F7180_name_46[work->side]->pos.y += work->vel;
    work->vel += work->acc * 0.1f;
    if (work->vel >= 1.0) {
        work->vel = 1.0f;
        work->acc = -work->acc;
    }
    if (work->vel <= -1.0) {
        work->vel = -1.0f;
        work->acc = -work->acc;
    }
}
