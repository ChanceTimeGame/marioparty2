#include "common.h"
#include "ovl_4C.h"

void func_80102830_325BF0_name_4C(void) {
    GwSystem.current_board_index = 8;
    omInitObjMan(10, 0);
    omOvlGotoEx(0x3D, 0, 0x192);
}

void func_8010286C_325C2C_name_4C(void) {
    s32 i;

    omInitObjMan(10, 0);
    SetPlayerOntoChain(0, 0, 0);
    SetPlayerOntoChain(1, 0, 0);
    SetPlayerOntoChain(2, 0, 0);
    SetPlayerOntoChain(3, 0, 0);
    func_80102D2C_3260EC_name_4C();
    for (i = 0; i < 4; i++) {
        BoardPlayerGet(i)->character = D_801054F0_3288B0_name_4C[i];
    }
    omOvlReturnEx(1);
}

void func_8010291C_325CDC_name_4C(void) {
    MBModel* model;

    if (D_80105670_328A30_name_4C == NULL) {
        model = func_80043510_44110(0x17, NULL);
        func_80043DAC_449AC(model);
        D_80105670_328A30_name_4C = model;
        model->attr |= 2;
        func_80056754_57354(model);
        func_800B3170_B3D70(&model->pos, &GetSpaceData(0x13)->coords);
    }
}

void func_8010298C_325D4C_name_4C(void) {
    D_80105670_328A30_name_4C = NULL;
    func_8010291C_325CDC_name_4C();
}

void func_801029AC_325D6C_name_4C(void) {
    MBModel* model;

    if (D_80105674_328A34_name_4C == NULL) {
        model = func_80043510_44110(8, NULL);
        func_8002D124_2DD24(*model->obj->model);
        func_8002D124_2DD24(*model->shadow->model);
        D_80105674_328A34_name_4C = model;
        model->attr |= 2;
        model->jumpY = 10.0f;
        func_800B3170_B3D70(&model->pos, &GetSpaceData(0x15)->coords);
        MBModelDispOff(model);
    }
}

void func_80102A44_325E04_name_4C(void) {
    D_80105674_328A34_name_4C = NULL;
    func_801029AC_325D6C_name_4C();
}

void func_80102A64_325E24_name_4C(void) {
    MBModel* model;

    if (D_80105678_328A38_name_4C == NULL) {
        model = func_80043510_44110(0x1D, NULL);
        func_80043DAC_449AC(model);
        D_80105678_328A38_name_4C = model;
        model->attr |= 2;
        func_800B3170_B3D70(&model->pos, &GetSpaceData(0x14)->coords);
    }
}

void func_80102ACC_325E8C_name_4C(void) {
    D_80105678_328A38_name_4C = NULL;
    func_80102A64_325E24_name_4C();
}

void func_80102AEC_325EAC_name_4C(void) {
    MBModel* model;

    if (D_8010567C_328A3C_name_4C == NULL) {
        model = func_80043510_44110(6, D_80105500_3288C0_name_4C);
        func_80043DAC_449AC(model);
        D_8010567C_328A3C_name_4C = model;
        model->attr |= 2;
        func_800B3170_B3D70(&model->pos, &GetSpaceData(0x14)->coords);
        MBModelDispOff(D_8010567C_328A3C_name_4C);
    }
}

void func_80102B68_325F28_name_4C(void) {
    D_8010567C_328A3C_name_4C = NULL;
    func_80102AEC_325EAC_name_4C();
}

void func_80102B88_325F48_name_4C(void) {
    SetNextChainAndSpace(-1, 2, 8);
}

void func_80102BAC_325F6C_name_4C(void) {
    SetNextChainAndSpace(-1, 0, 1);
}

void func_80102BD0_325F90_name_4C(void) {
    while (func_80053998_54598() != 0) {
        HuPrcVSleep();
    }
    HuPrcVSleep();
    HuPrcSleep(3);
}

void func_80102C14_325FD4_name_4C(void) {
}

void func_80102C1C_325FDC_name_4C(void) {
    struct unk_8003B8D4Struct* prompt;
    s32 choice;
    s32 moves;
    s32 i;

    MBPlayerMotionSet(-1, -1, 2);
    func_80102BD0_325F90_name_4C();
    prompt = func_80041A74_42674(-1, D_8010552C_3288EC_name_4C);
    func_800417EC_423EC(prompt, -1, 0);
    if (PlayerIsCPU(-1) != 0) {
        moves = D_80105534_3288F4_name_4C[D_800F8CE4_F98E4[0]++];
        for (i = 0; i < moves; i++) {
            func_80041610_42210(prompt, -2);
        }
        func_80041610_42210(prompt, -4);
    }
    choice = DirectionPrompt(prompt);
    func_8004108C_41C8C(prompt);
    func_80102C14_325FD4_name_4C();
    if (choice == 0) {
        SetNextChainAndSpace(-1, 2, 0);
    } else {
        SetNextChainAndSpace(-1, 1, 0);
    }
    omDelPrcObj(NULL);
}

void func_80102D2C_3260EC_name_4C(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        BoardPlayerGet(i)->flags |= 1;
    }
}

void func_80102D70_326130_name_4C(void) {
    Process* process;

    process = HuPrcCurrentGet();
    HuPrcChildLink(process, func_8005E478_5F078());
    HuPrcChildWatch();
}

void func_80102DAC_32616C_name_4C(void) {
    Process* process;

    process = HuPrcCurrentGet();
    HuPrcChildLink(process, func_8005E544_5F144());
    HuPrcChildWatch();
}

Ovl4CTip* func_80102DE8_3261A8_name_4C(s16 tip, s16 x, s16 y) {
    Ovl4CTip* work;
    s16 xbase;
    void* data;

    work = HuMemMemoryAllocTemp(sizeof(Ovl4CTip));
    work->group = SprCreate(3, 0);
    data = DataRead(0xA0026);
    work->anim0 = SprAnimRead(data);
    SprAnimSet(work->group, 0, work->anim0, 0);
    SprPrioSet(work->group, 0, 0xB);
    SprAttrSet(work->group, 0, 0x1000);
    xbase = x + 5;
    SprPosSet(work->group, 0, xbase, y);
    DataClose(data);
    data = DataRead(0xA0027);
    work->anim1 = SprAnimRead(data);
    SprAnimSet(work->group, 1, work->anim1, 0);
    SprPrioSet(work->group, 1, 0xB);
    SprAttrSet(work->group, 1, 0x1000);
    SprPosSet(work->group, 1, xbase, y);
    func_80082488_83088(work->group, 1, 0xFF);
    func_80082450_83050(work->group, 1, 0xFF, 0xD3, 0x4F);
    DataClose(data);
    data = DataRead(D_8010556C_32892C_name_4C[tip]);
    work->anim2 = SprAnimRead(data);
    SprAnimSet(work->group, 2, work->anim2, 0);
    SprPrioSet(work->group, 2, 0xA);
    SprAttrSet(work->group, 2, 0x1000);
    SprPosSet(work->group, 2, x, y);
    DataClose(data);
    return work;
}

void func_80102FF8_3263B8_name_4C(Ovl4CTip* work) {
    SprAnimKill(work->anim0);
    SprAnimKill(work->anim1);
    SprAnimKill(work->anim2);
    SprKill(work->group);
    HuMemMemoryFreeTemp(work);
}

void func_80103040_326400_name_4C(s16 index, s16 x, s16 y) {
    void* data;

    D_80105680_328A40_name_4C = SprCreate(1, 0);
    data = DataRead(D_80105594_328954_name_4C[index]);
    D_80105682_328A42_name_4C = SprAnimRead(data);
    SprAnimSet(D_80105680_328A40_name_4C, 0, D_80105682_328A42_name_4C, 0);
    SprPrioSet(D_80105680_328A40_name_4C, 0, 0xB);
    SprAttrSet(D_80105680_328A40_name_4C, 0, 0x1000);
    SprPosSet(D_80105680_328A40_name_4C, 0, x, y);
    DataClose(data);
}

void func_80103124_3264E4_name_4C(void) {
    SprAnimKill(D_80105682_328A42_name_4C);
    SprKill(D_80105680_328A40_name_4C);
}

void func_80103150_326510_name_4C(void) {
    D_80105684_328A44_name_4C = -1;
    func_80063C40_64840(0, 1);
    func_80063C40_64840(1, 1);
    func_80063C40_64840(2, 1);
    func_80063C40_64840(3, 1);
    InitFadeIn(2, 16);
    func_8008F624_90224(0xFF, 0xFF, 0xFF);
    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    func_80051500_52100();
    while (1) {
        if (D_80105684_328A44_name_4C < 0) {
            MBDCameraPos3DSet(&PLAYER_MODEL_4C(-1)->pos);
        } else {
            MBDCameraPos3DSet(&GetSpaceData(D_80105684_328A44_name_4C)->coords);
        }
        HuPrcVSleep();
    }
}

void func_80103230_3265F0_name_4C(s16 space) {
    D_80105684_328A44_name_4C = space;
    MBCameraSpeedSet(4.0f);
}

void func_8010325C_32661C_name_4C(void) {
    HuPrcSleep(3);
    while (func_80053998_54598() != 0) {
        HuPrcVSleep();
    }
    MBCameraSpeedSet(-1.0f);
}

void func_801032A8_326668_name_4C(void) {
    GW_PLAYER* player;
    s32 i;

    for (i = 0; i < 4; i++) {
        player = BoardPlayerGet(i);
        player->player_space_color = 0;
        player->flags = (u16)player->flags & 0xFFFD;
    }
}

void func_801032F0_3266B0_name_4C(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_80060034_60C34(i, (u8)BoardPlayerGet(i)->player_space_color);
    }
}

void func_80103334_3266F4_name_4C(void) {
    GW_SYSTEM* gw = &GwSystem;
    GW_PLAYER* player;
    s32 i;

    if (++gw->current_player_index >= 4) {
        gw->current_player_index = 0;
    }
    for (i = 0; i < 4; i++) {
        player = BoardPlayerGet(i);
        MBPlayerForwardSet(i);
        MBMotionSet(player->unk_24, -1, 2);
        func_80063C40_64840(i, 1);
    }
    func_80052E68_53A68(1.0f);
}

void func_801033DC_32679C_name_4C(Vec* arg0) {
    func_800670BC_67CBC(arg0);
}

void func_801033F8_3267B8_name_4C(void) {
    Process* process;

    process = HuPrcCurrentGet();
    HuPrcChildLink(process, func_800500CC_50CCC(GwSystem.current_player_index));
    HuPrcChildWatch();
}

void func_8010343C_3267FC_name_4C(s16 roll) {
    GW_SYSTEM* gw = &GwSystem;
    Process* process;
    Process* child;

    func_80047DB0_489B0(gw->current_player_index, roll);
    process = HuPrcCurrentGet();
    HuPrcChildLink(process, MBDCameraZoomMotStart(1.3f));
    child = func_80048800_49400(gw->current_player_index);
    HuPrcChildWatch();
    HuPrcChildLink(process, child);
    HuPrcChildWatch();
}

/* wall: register allocation. Masked 0: `player` wants s2 and the pair of `chain`/`space` s1; retail
   swaps them against GCC's priority order. */
#ifdef NON_MATCHING
void func_801034C8_326888_name_4C(void) {
    GW_SYSTEM* gw = &GwSystem;
    Vec dir;
    GW_PLAYER* player;
    s16 spaceIndex;
    s16 steps;
    s32 i;
    Vec* rot;

    player = BoardPlayerGet(-1);
    spaceIndex = 0;
    steps = func_80047DE8_489E8(gw->current_player_index);
    MBPlayerMotionSet(-1, 0, 2);
    while (steps != 0) {
        s16 chain;
        s16 next;
        SpaceData* space;

        chain = player->cur_chain_index;
        next = player->cur_space_index;
        player->cur_chain_index = player->next_chain_index;
        player->cur_space_index = player->next_space_index;
        for (i = 0; i < 4; i++) {
            func_80063C40_64840(i, 10);
        }
        player->cur_chain_index = chain;
        player->cur_space_index = next;
        if (((u16)GetSpaceData(GetAbsSpaceIndexFromChainSpaceIndex(player->next_chain_index, player->next_space_index))->unk_02 & 0x8000)
            || func_80063F88_64B88(gw->current_player_index) != 0) {
            func_800797DC_7A3DC(0x42, gw->current_player_index);
            MBPlayerMotionSet(-1, 2, 0);
            ((MBModel*)player->unk_24)->jumpVel = 4.0f;
            ((MBModel*)player->unk_24)->jumpAccel = -0.5f;
            func_80056E34_57A34(gw->current_player_index, 15);
        } else {
            if (((MBModel*)player->unk_24)->curMot != 0) {
                MBPlayerMotionSet(-1, 0, 2);
            }
            func_80056E34_57A34(gw->current_player_index, 10);
        }
        player->cur_chain_index = player->next_chain_index;
        player->cur_space_index = player->next_space_index;
        player->next_space_index++;
        spaceIndex = GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain_index, player->cur_space_index);
        space = GetSpaceData(spaceIndex);
        func_800558E8_564E8(spaceIndex);
        switch (space->space_type) {
            case 1:
            case 2:
            case 4:
            case 5:
            case 6:
            case 7:
            case 9:
            case 12:
                steps--;
                func_80046E2C_47A2C(gw->current_player_index);
                func_800553A8_55FA8(spaceIndex);
                break;
        }
        if (steps != 0) {
            switch (space->space_type) {
                case 1:
                case 2:
                case 4:
                case 5:
                case 6:
                case 7:
                case 9:
                case 12:
                    PlaySound(0x315);
                    break;
                case 14:
                    PlaySound(0x315);
                    break;
            }
        } else {
            switch (space->space_type) {
                case 4:
                    PlaySound(0x334);
                    break;
                case 1:
                    PlaySound(0x316);
                    break;
                case 2:
                    PlaySound(0x317);
                    break;
                case 12:
                    PlaySound(0x344);
                    break;
                case 5:
                case 6:
                    PlaySound(0x371);
                    break;
                case 9:
                    PlaySound(0x372);
                    break;
                case 7:
                    PlaySound(0x373);
                    break;
                case 14:
                    PlaySound(0x341);
                    break;
            }
        }
        func_800556F4_562F4(spaceIndex, 1);
    }
    MBPlayerMotionSet(-1, -1, 2);
    func_800556F4_562F4(spaceIndex, 3);
    func_8005670C_5730C(&dir);
    rot = &((MBModel*)player->unk_24)->rot;
    func_80056B78_57778(rot, &dir, rot, 8);
    func_80061078_61C78(gw->current_player_index);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_4C_name/325BC0", func_801034C8_326888_name_4C);
#endif

void func_801037E4_326BA4_name_4C(void) {
    GW_SYSTEM* gw = &GwSystem;
    GW_PLAYER* player;
    SpaceData* space;

    player = BoardPlayerGet(-1);
    space = GetSpaceData(GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain_index, player->cur_space_index));
    func_80056884_57484(-1, space->space_type);
    func_80060034_60C34(gw->current_player_index, (u8)player->player_space_color);
    switch (space->space_type) {
        case 1:
            func_8004CA34_4D634(gw->current_player_index, 3);
            func_800614B4_620B4(gw->current_player_index, 3);
            PlaySound(0x316);
            HuPrcSleep(30);
            break;
        case 2:
            func_8004CA34_4D634(gw->current_player_index, -3);
            func_800614B4_620B4(gw->current_player_index, -3);
            PlaySound(0x317);
            HuPrcSleep(30);
            break;
    }
}

void func_801038C8_326C88_name_4C(UnkMBGuideData* guide, s32 mess) {
    func_800890CC_89CCC(guide->amount, mess, -1, -1);
    func_8008E2DC_8EEDC(guide->amount, 1);
    func_8005812C_58D2C(guide->amount);
    func_8008E4D0_8F0D0(guide->amount, 1);
    func_8008AD44_8B944(guide->amount);
    HuPrcVSleep();
}

void func_80103930_326CF0_name_4C(UnkMBGuideData* guide, s32 mess) {
    func_800890CC_89CCC(guide->amount, mess, -1, -1);
    func_8008E2DC_8EEDC(guide->amount, 1);
}

void func_8010396C_326D2C_name_4C(UnkMBGuideData* guide) {
    func_8005812C_58D2C(guide->amount);
    func_8008E4D0_8F0D0(guide->amount, 1);
    func_8008AD44_8B944(guide->amount);
    HuPrcVSleep();
}

void func_801039B4_326D74_name_4C(UnkMBGuideData* guide) {
    MBModel* model = guide->obj;

    model->jumpVel = 4.0f;
    model->jumpAccel = -0.6f;
    MBMotionSet(guide->obj, 0, 0);
    HuPrcSleep(3);
    while (MBMotionCheck(guide->obj) == 0) {
        HuPrcVSleep();
    }
    MBMotionSet(guide->obj, -1, 2);
}

void func_80103A48_326E08_name_4C(UnkMBGuideData* guide, s16 y) {
    MBModel* model;
    s16 y0;
    s32 diff;
    s32 step;
    s32 i;

    y0 = guide->spriteGroup;
    model = guide->obj;
    model->jumpVel = 4.0f;
    model->jumpAccel = -0.5f;
    MBMotionSet(guide->obj, 0, 0);
    diff = y - y0;
    step = diff / 14;
    for (i = 0; i < 14; i++) {
        y0 = guide->spriteGroup;
        func_800505C4_511C4(guide, y0 + step, 8);
        HuPrcVSleep();
    }
    func_800505C4_511C4(guide, y, 8);
    while (MBMotionCheck(guide->obj) == 0) {
        HuPrcVSleep();
    }
    MBMotionSet(guide->obj, -1, 2);
}

void func_80103B74_326F34_name_4C(void) {
    UnkMBGuideData* guide;
    u16 request;

    guide = HuPrcCurrentGet()->user_data;
    while (1) {
        HuPrcVSleep();
        if (D_801055B8_328978_name_4C == -1) {
            continue;
        }
        if (D_801055B8_328978_name_4C == -2) {
            D_801055B8_328978_name_4C = -1;
            MBMotionShiftSet(guide->obj, -1, 0, 10, 0);
        } else {
            MBMotionShiftSet(guide->obj, D_801055B8_328978_name_4C, 0, 10, 0);
        }
        request = D_801055B8_328978_name_4C;
        D_801055B8_328978_name_4C = -1;
        while (MBMotionCheck(guide->obj) == 0 && D_801055B8_328978_name_4C == -1) {
            HuPrcVSleep();
        }
        switch ((s16)request) {
            case 1:
                MBMotionSet(guide->obj, 3, 2);
                break;
            case 2:
                MBMotionSet(guide->obj, 4, 2);
                break;
            default:
                MBMotionSet(guide->obj, -1, 2);
                break;
        }
    }
}

void func_80103C90_327050_name_4C(s16 request) {
    D_801055B8_328978_name_4C = request;
}

void func_80103C9C_32705C_name_4C(void) {
    Ovl4CTip* tip1;
    Ovl4CTip* tip2;
    Ovl4CTip* tip3;
    Ovl4CTip* tip4;
    Ovl4CTip* tip5;
    Ovl4CTip* tip6;
    Ovl4CTip* tip7;
    MBModel* model;
    Process* process;
    f32 scale;
    f32 rot;
    s32 i;

    process = HuPrcCurrentGet();
    D_800F8CE4_F98E4[0] = 0;
    func_80102D2C_3260EC_name_4C();
    D_80105688_328A48_name_4C = func_80050304_50F04(D_801055A0_328960_name_4C, 0);
    HuVecCopyXYZ(&D_80105688_328A48_name_4C->obj->scale, 1.1f, 1.1f, 1.1f);
    D_80105688_328A48_name_4C->obj->pos.x -= 1.0f;
    D_80105688_328A48_name_4C->obj->pos.y -= 2.0f;
    func_8005AB50_5B750(D_80105688_328A48_name_4C->obj, 2, 8, D_801054F8_3288B8_name_4C[0]);
    func_800505C4_511C4(D_80105688_328A48_name_4C, 0x42, 8);
    omAddPrcObj(&func_80103B74_326F34_name_4C, 0x4800U, 0, 0)->user_data = D_80105688_328A48_name_4C;
    func_80089284_89E84(D_80105688_328A48_name_4C->amount, 0x40, 0x40);
    func_801032A8_326668_name_4C();
    func_801032F0_3266B0_name_4C();
    HuPrcSleep(3);
    while (func_8008F618_90218() != 0) {
        HuPrcVSleep();
    }
    HuPrcSleep(3);
    func_801039B4_326D74_name_4C(D_80105688_328A48_name_4C);
    func_801038C8_326C88_name_4C(D_80105688_328A48_name_4C, 0x624);
    func_801033F8_3267B8_name_4C();
    func_8010343C_3267FC_name_4C(1);
    func_801038C8_326C88_name_4C(D_80105688_328A48_name_4C, 0x625);
    func_801034C8_326888_name_4C();
    func_801039B4_326D74_name_4C(D_80105688_328A48_name_4C);
    func_801038C8_326C88_name_4C(D_80105688_328A48_name_4C, 0x626);
    func_80103C90_327050_name_4C(1);
    HuPrcVSleep();
    tip1 = func_80102DE8_3261A8_name_4C(0, 0x64, 0x64);
    func_801038C8_326C88_name_4C(D_80105688_328A48_name_4C, 0x627);
    func_80103C90_327050_name_4C(-2);
    func_80102FF8_3263B8_name_4C(tip1);
    func_801037E4_326BA4_name_4C();
    func_80102D70_326130_name_4C();
    func_80103334_3266F4_name_4C();
    func_801033DC_32679C_name_4C(0);
    func_80102DAC_32616C_name_4C();
    func_801032F0_3266B0_name_4C();
    func_801033F8_3267B8_name_4C();
    func_8010343C_3267FC_name_4C(2);
    func_801034C8_326888_name_4C();
    func_80103C90_327050_name_4C(1);
    HuPrcVSleep();
    tip2 = func_80102DE8_3261A8_name_4C(1, 0x64, 0x64);
    func_801038C8_326C88_name_4C(D_80105688_328A48_name_4C, 0x628);
    func_80103C90_327050_name_4C(-2);
    func_80102FF8_3263B8_name_4C(tip2);
    func_801037E4_326BA4_name_4C();
    func_80102D70_326130_name_4C();
    func_80103334_3266F4_name_4C();
    func_801033DC_32679C_name_4C(0);
    func_80102DAC_32616C_name_4C();
    func_801032F0_3266B0_name_4C();
    func_801033F8_3267B8_name_4C();
    func_8010343C_3267FC_name_4C(3);
    func_801034C8_326888_name_4C();
    func_80103C90_327050_name_4C(1);
    HuPrcVSleep();
    tip3 = func_80102DE8_3261A8_name_4C(3, 0x64, 0x64);
    func_801038C8_326C88_name_4C(D_80105688_328A48_name_4C, 0x629);
    func_80103C90_327050_name_4C(-2);
    func_80102FF8_3263B8_name_4C(tip3);
    func_801037E4_326BA4_name_4C();
    func_80102D70_326130_name_4C();
    func_80103334_3266F4_name_4C();
    func_801033DC_32679C_name_4C(0);
    func_80102DAC_32616C_name_4C();
    func_801032F0_3266B0_name_4C();
    func_801033F8_3267B8_name_4C();
    func_8010343C_3267FC_name_4C(5);
    func_801034C8_326888_name_4C();
    func_80103C90_327050_name_4C(1);
    HuPrcVSleep();
    tip4 = func_80102DE8_3261A8_name_4C(4, 0x64, 0x64);
    func_801038C8_326C88_name_4C(D_80105688_328A48_name_4C, 0x62A);
    func_80103C90_327050_name_4C(-2);
    func_80102FF8_3263B8_name_4C(tip4);
    func_801037E4_326BA4_name_4C();
    HuPrcSleep(0xA);
    func_801038C8_326C88_name_4C(D_80105688_328A48_name_4C, 0x62B);
    func_80102D70_326130_name_4C();
    func_80103334_3266F4_name_4C();
    func_801033DC_32679C_name_4C(0);
    func_80102DAC_32616C_name_4C();
    func_801032A8_326668_name_4C();
    func_801032F0_3266B0_name_4C();
    func_801033F8_3267B8_name_4C();
    func_8010343C_3267FC_name_4C(5);
    func_801034C8_326888_name_4C();
    func_80103C90_327050_name_4C(1);
    HuPrcVSleep();
    tip5 = func_80102DE8_3261A8_name_4C(7, 0x64, 0x64);
    func_801038C8_326C88_name_4C(D_80105688_328A48_name_4C, 0x62C);
    func_80103C90_327050_name_4C(-2);
    func_80102FF8_3263B8_name_4C(tip5);
    func_801037E4_326BA4_name_4C();
    func_80102D70_326130_name_4C();
    func_80103334_3266F4_name_4C();
    func_801033DC_32679C_name_4C(0);
    func_80102DAC_32616C_name_4C();
    func_801032F0_3266B0_name_4C();
    func_801033F8_3267B8_name_4C();
    func_8010343C_3267FC_name_4C(5);
    func_801034C8_326888_name_4C();
    func_80103C90_327050_name_4C(1);
    HuPrcVSleep();
    tip6 = func_80102DE8_3261A8_name_4C(8, 0x64, 0x64);
    func_801038C8_326C88_name_4C(D_80105688_328A48_name_4C, 0x62D);
    func_80103C90_327050_name_4C(-2);
    func_80102FF8_3263B8_name_4C(tip6);
    func_801037E4_326BA4_name_4C();
    func_80102D70_326130_name_4C();
    func_80103334_3266F4_name_4C();
    func_801033DC_32679C_name_4C(0);
    func_80102DAC_32616C_name_4C();
    func_801032F0_3266B0_name_4C();
    func_801033F8_3267B8_name_4C();
    func_8010343C_3267FC_name_4C(2);
    func_801034C8_326888_name_4C();
    func_80103C90_327050_name_4C(1);
    HuPrcVSleep();
    tip7 = func_80102DE8_3261A8_name_4C(9, 0x64, 0x64);
    func_801038C8_326C88_name_4C(D_80105688_328A48_name_4C, 0x62E);
    func_80103C90_327050_name_4C(-2);
    func_80102FF8_3263B8_name_4C(tip7);
    func_801037E4_326BA4_name_4C();
    func_80102D70_326130_name_4C();
    func_80103334_3266F4_name_4C();
    func_801033DC_32679C_name_4C(0);
    func_80102DAC_32616C_name_4C();
    func_801032F0_3266B0_name_4C();
    func_801033F8_3267B8_name_4C();
    func_8010343C_3267FC_name_4C(1);
    func_801034C8_326888_name_4C();
    func_80104CC4_328084_name_4C(D_80105688_328A48_name_4C);
    func_801037E4_326BA4_name_4C();
    func_801039B4_326D74_name_4C(D_80105688_328A48_name_4C);
    func_801038C8_326C88_name_4C(D_80105688_328A48_name_4C, 0x632);
    func_80060210_60E10(4);
    func_80103A48_326E08_name_4C(D_80105688_328A48_name_4C, -0x1E);
    while (func_800609D8_615D8() != 0) {
        HuPrcVSleep();
    }
    func_80103C90_327050_name_4C(2);
    func_801038C8_326C88_name_4C(D_80105688_328A48_name_4C, 0x633);
    func_80103C90_327050_name_4C(-2);
    HuPrcChildLink(process, func_8004C00C_4CC0C());
    HuPrcChildWatch();
    func_801038C8_326C88_name_4C(D_80105688_328A48_name_4C, 0x634);
    func_80060034_60C34(0, 2);
    func_80060034_60C34(1, 2);
    func_80060034_60C34(2, 2);
    func_80060034_60C34(3, 2);
    HuPrcSleep(0x1E);
    func_80060034_60C34(0, 1);
    func_80060034_60C34(1, 1);
    func_80060034_60C34(2, 1);
    func_80060034_60C34(3, 1);
    func_80060210_60E10(2);
    func_80060B04_61704();
    while (func_800609D8_615D8() != 0) {
        HuPrcVSleep();
    }
    func_80103C90_327050_name_4C(2);
    func_801038C8_326C88_name_4C(D_80105688_328A48_name_4C, 0x635);
    MBVsSprKill();
    func_80060034_60C34(0, 2);
    func_80060034_60C34(1, 1);
    func_80060034_60C34(2, 2);
    func_80060034_60C34(3, 1);
    func_80060210_60E10(2);
    func_80060B04_61704();
    while (func_800609D8_615D8() != 0) {
        HuPrcVSleep();
    }
    func_801038C8_326C88_name_4C(D_80105688_328A48_name_4C, 0x636);
    MBVsSprKill();
    func_80060034_60C34(0, 1);
    func_80060034_60C34(1, 2);
    func_80060034_60C34(2, 2);
    func_80060034_60C34(3, 2);
    func_80060210_60E10(2);
    func_80060B04_61704();
    while (func_800609D8_615D8() != 0) {
        HuPrcVSleep();
    }
    func_801038C8_326C88_name_4C(D_80105688_328A48_name_4C, 0x637);
    func_80060034_60C34(0, 2);
    func_80060034_60C34(1, 1);
    func_80060034_60C34(2, 1);
    func_80060034_60C34(3, 1);
    func_801038C8_326C88_name_4C(D_80105688_328A48_name_4C, 0x638);
    func_80103C90_327050_name_4C(-2);
    HuPrcSleep(0xF);
    func_801038C8_326C88_name_4C(D_80105688_328A48_name_4C, 0x639);
    D_801055BC_32897C_name_4C = 0;
    HuPrcSleep(1);
    GwSystem.chosenMinigameIndex = -1;
    func_8004AD34_4B934(-1);
    func_8004B214_4BE14();
    func_80060210_60E10(5);
    if (GwSystem.chosenMinigameIndex == -1) {
        do {
            HuPrcVSleep();
        } while (GwSystem.chosenMinigameIndex == -1);
    }
    MBVsSprKill();
    func_801038C8_326C88_name_4C(D_80105688_328A48_name_4C, 0x63A);
    func_8004A9EC_4B5EC();
    D_801055BC_32897C_name_4C = 1;
    i = 0;
    func_80061518_62118();
    func_80051500_52100();
    func_8002D4A0_2E0A0(*PLAYER_MODEL_4C(0)->obj->model);
    func_8002D4A0_2E0A0(*PLAYER_MODEL_4C(1)->obj->model);
    func_8002D4A0_2E0A0(*PLAYER_MODEL_4C(2)->obj->model);
    func_8002D4A0_2E0A0(*PLAYER_MODEL_4C(3)->obj->model);
    func_80103A48_326E08_name_4C(D_80105688_328A48_name_4C, 0x69);
    func_801039B4_326D74_name_4C(D_80105688_328A48_name_4C);
    func_801038C8_326C88_name_4C(D_80105688_328A48_name_4C, 0x63B);
    D_801055BC_32897C_name_4C = 0;
    func_80103230_3265F0_name_4C(0x12);
    func_8010325C_32661C_name_4C();
    D_801055BC_32897C_name_4C = 1;
    func_80103C90_327050_name_4C(1);
    func_801038C8_326C88_name_4C(D_80105688_328A48_name_4C, 0x63C);
    func_80103C90_327050_name_4C(-2);
    HuPrcSleep(0xA);
    D_801055BC_32897C_name_4C = 0;
    func_80103230_3265F0_name_4C(0x1C);
    func_8010325C_32661C_name_4C();
    D_801055BC_32897C_name_4C = 1;
    func_80103C90_327050_name_4C(1);
    func_801038C8_326C88_name_4C(D_80105688_328A48_name_4C, 0x63D);
    func_80103C90_327050_name_4C(-2);
    HuPrcSleep(0xA);
    func_801039B4_326D74_name_4C(D_80105688_328A48_name_4C);
    func_801038C8_326C88_name_4C(D_80105688_328A48_name_4C, 0x63E);
    D_801055BC_32897C_name_4C = 0;
    func_80103230_3265F0_name_4C(0x13);
    func_8010325C_32661C_name_4C();
    D_801055BC_32897C_name_4C = 1;
    PlaySound(0x11E);
    func_80103C90_327050_name_4C(1);
    func_801038C8_326C88_name_4C(D_80105688_328A48_name_4C, 0x63F);
    func_80103C90_327050_name_4C(-2);
    HuPrcSleep(0xA);
    D_801055BC_32897C_name_4C = 0;
    func_80103230_3265F0_name_4C(0x15);
    func_8010325C_32661C_name_4C();
    D_801055BC_32897C_name_4C = 1;
    PlaySound(0xEB);
    MBModelDispOn(D_80105674_328A34_name_4C);
    do {
        func_8002D0A0_2DCA0(*D_80105674_328A34_name_4C->obj->model, i);
        func_8002D0A0_2DCA0(*D_80105674_328A34_name_4C->shadow->model, i);
        i += 0xC;
        HuPrcVSleep();
    } while (i < 0x100);
    func_8002D0A0_2DCA0(*D_80105674_328A34_name_4C->obj->model, 0xFF);
    func_8002D0A0_2DCA0(*D_80105674_328A34_name_4C->shadow->model, 0xFF);
    func_80103C90_327050_name_4C(1);
    func_801038C8_326C88_name_4C(D_80105688_328A48_name_4C, 0x640);
    func_80103C90_327050_name_4C(-2);
    i = 0xFF;
    do {
        func_8002D0A0_2DCA0(*D_80105674_328A34_name_4C->obj->model, i);
        func_8002D0A0_2DCA0(*D_80105674_328A34_name_4C->shadow->model, i);
        i -= 0xC;
        HuPrcVSleep();
    } while (i >= 0);
    func_8002D0A0_2DCA0(*D_80105674_328A34_name_4C->obj->model, 0);
    func_8002D0A0_2DCA0(*D_80105674_328A34_name_4C->shadow->model, 0);
    MBModelDispOff(D_80105674_328A34_name_4C);
    D_801055BC_32897C_name_4C = 0;
    func_80103230_3265F0_name_4C(0x14);
    func_8010325C_32661C_name_4C();
    D_801055BC_32897C_name_4C = 1;
    PlaySound(0x363);
    func_80059120_59D20(D_80105678_328A38_name_4C, 2.0f, -0.5f);
    func_80059158_59D58(D_80105678_328A38_name_4C);
    func_80059120_59D20(D_80105678_328A38_name_4C, 2.0f, -0.5f);
    func_80059158_59D58(D_80105678_328A38_name_4C);
    func_80103C90_327050_name_4C(1);
    func_801038C8_326C88_name_4C(D_80105688_328A48_name_4C, 0x641);
    func_80103C90_327050_name_4C(-2);
    PlaySound(0x36C);
    model = func_80043510_44110(0x6F, NULL);
    func_800B3170_B3D70(&model->pos, &D_80105678_328A38_name_4C->pos);
    model->pos.z += 20.0f;
    model->pos.y += 30.0f;
    rot = 0.0f;
    scale = 1.0f;
    do {
        HuVecCopyXYZ(&model->scale, scale, scale, scale);
        func_800B3B80_B4780(D_800FC834_FD434[*model->obj->model].mtx, rot);
        rot += 20.0f;
        HuPrcVSleep();
        scale += 1.0;
    } while (scale < 10.0f);
    MBModelDispOff(D_80105678_328A38_name_4C);
    MBModelDispOn(D_8010567C_328A3C_name_4C);
    if (scale >= 1.0f) {
        do {
            HuVecCopyXYZ(&model->scale, scale, scale, scale);
            func_800B3B80_B4780(D_800FC834_FD434[*model->obj->model].mtx, rot);
            rot += 20.0f;
            HuPrcVSleep();
            scale -= 1.0;
        } while (scale >= 1.0f);
    }
    MBModelKill(model);
    PlaySound(0x123);
    MBMotionSet(D_8010567C_328A3C_name_4C, 0, 2);
    func_80103C90_327050_name_4C(1);
    func_801038C8_326C88_name_4C(D_80105688_328A48_name_4C, 0x642);
    func_80103C90_327050_name_4C(-2);
    PlaySound(0x122);
    MBMotionShiftSet(D_8010567C_328A3C_name_4C, 1, 0, 0xA, 2);
    HuPrcSleep(0x1E);
    D_801055BC_32897C_name_4C = 0;
    func_80103230_3265F0_name_4C(0x18);
    func_8010325C_32661C_name_4C();
    D_801055BC_32897C_name_4C = 1;
    func_80103C90_327050_name_4C(-2);
    func_801039B4_326D74_name_4C(D_80105688_328A48_name_4C);
    func_801038C8_326C88_name_4C(D_80105688_328A48_name_4C, 0x643);
    func_80103040_326400_name_4C(0, 0xA0, 0x50);
    func_80103C90_327050_name_4C(1);
    func_801038C8_326C88_name_4C(D_80105688_328A48_name_4C, 0x644);
    func_80103124_3264E4_name_4C();
    func_80103040_326400_name_4C(1, 0xA0, 0x50);
    func_801038C8_326C88_name_4C(D_80105688_328A48_name_4C, 0x645);
    func_80103124_3264E4_name_4C();
    func_80103040_326400_name_4C(2, 0xA0, 0x50);
    func_801038C8_326C88_name_4C(D_80105688_328A48_name_4C, 0x646);
    func_80103C90_327050_name_4C(-2);
    func_80103124_3264E4_name_4C();
    HuPrcSleep(0xA);
    func_801038C8_326C88_name_4C(D_80105688_328A48_name_4C, 0x647);
    func_801039B4_326D74_name_4C(D_80105688_328A48_name_4C);
    func_801038C8_326C88_name_4C(D_80105688_328A48_name_4C, 0x648);
    func_800794A8_7A0A8(0x3C);
    InitFadeOut(2, 0x10);
    func_8008F624_90224(0xFF, 0xFF, 0xFF);
    HuPrcSleep(0x10);
    func_8005057C_5117C(D_80105688_328A48_name_4C);
    func_80063178_63D78();
    func_80062CC0_638C0();
    omOvlReturnEx(1);
    omOvlKill();
    HuPrcVSleep();
}

void func_80104CC4_328084_name_4C(UnkMBGuideData* guide) {
    GW_SYSTEM* gw = &GwSystem;
    Process* child;
    Process* process;

    process = HuPrcCurrentGet();
    HuPrcChildLink(process, MBDCameraZoomMotStart(1.6f));
    child = func_80049408_4A008(gw->current_player_index);
    func_8004947C_4A07C();
    HuPrcChildWatch();
    func_80103C90_327050_name_4C(1);
    func_801038C8_326C88_name_4C(guide, 0x62F);
    func_80103C90_327050_name_4C(-2);
    func_8004948C_4A08C();
    while (func_80049470_4A070() == 0) {
        HuPrcVSleep();
    }
    HuPrcChildLink(process, child);
    HuPrcChildWatch();
    func_801038C8_326C88_name_4C(guide, 0x630);
    child = func_80049028_49C28(gw->current_player_index);
    func_8004947C_4A07C();
    func_8004948C_4A08C();
    while (func_80049470_4A070() == 0) {
        HuPrcVSleep();
    }
    func_80103930_326CF0_name_4C(guide, 0x631);
    func_8004948C_4A08C();
    HuPrcChildLink(process, child);
    HuPrcChildWatch();
    func_8010396C_326D2C_name_4C(guide);
    func_80103C90_327050_name_4C(-2);
    HuPrcChildLink(process, MBDCameraZoomMotStart(1.3f));
    HuPrcChildWatch();
    HuPrcSleep(1);
}

s32 func_80104E50_328210_name_4C(s32 pad) {
    s16 size[2];
    Ovl4CBox* back;
    Ovl4CBox* icon;
    void* data;
    s16 choice;
    s32 win;

    func_800794F0_7A0F0(0x60);
    back = func_8005E688_5F288(1, 0);
    data = DataRead(0xA00D6);
    back->anims[0] = SprAnimRead(data);
    SprAnimSet(back->group, 0, back->anims[0], 0);
    SprPrioSet(back->group, 0, 9);
    SprAttrSet(back->group, 0, 0x1000);
    SprPosSet(back->group, 0, 160, 120);
    SprScaleSet(back->group, 0, 40.0f, 30.0f);
    func_800824B4_830B4(back->group, 0, 0, 0, 0, 0xC0);
    DataClose(data);
    icon = func_8005E688_5F288(2, 0);
    data = DataRead(0xA01E0);
    icon->anims[0] = SprAnimRead(data);
    DataClose(data);
    SprAnimSet(icon->group, 0, icon->anims[0], 0);
    SprPrioSet(icon->group, 0, 8);
    SprAttrSet(icon->group, 0, 0x1000);
    SprPosSet(icon->group, 0, 158, 120);
    func_80082450_83050(icon->group, 0, 0, 0, 0xFF);
    data = DataRead(0xA01E1);
    icon->anims[1] = SprAnimRead(data);
    DataClose(data);
    SprAnimSet(icon->group, 1, icon->anims[1], 0);
    SprPrioSet(icon->group, 1, 7);
    SprAttrSet(icon->group, 1, 0x1000);
    SprPosSet(icon->group, 1, 158, 120);
    func_8008DACC_8E6CC(1, size, 0x649);
    win = func_800888A8_894A8(0x49, 0x4B, size[0], size[1], 0, 2);
    func_80089A7C_8A67C(win, 5);
    func_80089B2C_8A72C(win, 0);
    func_8008D88C_8E48C(win);
    func_800890CC_89CCC(win, 0x649, -1, -1);
    func_80089A48_8A648(win, 0);
    while (func_8008BA30_8C630(win) != 0) {
        HuPrcVSleep();
    }
    func_8008D59C_8E19C(win, 1 << pad);
    choice = func_8008BB48_8C748(win, 0, 0);
    func_8008CCA8_8D8A8(win);
    func_800794F0_7A0F0(0x7F);
    HuMemDirectFree(back);
    HuMemDirectFree(icon);
    return choice == 1;
}

void func_80105164_328524_name_4C(void) {
    Vec2f pos;
    s32 player;
    s32 i;

    while (1) {
        HuPrcVSleep();
        if (func_8008F618_90218() != 0 || D_800F8C56_F9856 == 3) {
            continue;
        }
        player = GetCurrentPlayerIndex();
        for (i = 0; i < 4; i++) {
            if ((ContDStkTrg[i] & 0x1000) && D_801055BC_32897C_name_4C != 0) {
                func_80049498_4A098(player);
                func_800537A0_543A0(&pos);
                func_800536E4_542E4(&pos);
                D_800F851A_F911A = 1;
                func_80078EC8_79AC8();
                D_800FDC9C_FE89C = 1;
                if ((s16)func_80104E50_328210_name_4C(i) != 0) {
                    func_800794A8_7A0A8(0x5A);
                    InitFadeOut(0, 16);
                    HuPrcSleep(17);
                    func_80063178_63D78();
                    func_80062CC0_638C0();
                    omOvlReturnEx(1);
                    omOvlKill();
                    HuPrcVSleep();
                }
                D_800FDC9C_FE89C = 0;
                func_80078FF8_79BF8();
                D_800F851A_F911A = 0;
                func_800494FC_4A0FC(player);
                break;
            }
        }
    }
}

void func_801052CC_32868C_name_4C(void) {
    Vec dir;
    GW_PLAYER* player;
    SpaceData* space;
    s16 index;
    s32 i;

    PlayMusic(5);
    func_80020070_20C70(2);
    omInitObjMan(0x50, 0x28);
    func_80079128_79D28();
    func_80026D28_27928(1);
    func_80026DAC_279AC(0, 0x78, 0x78, 0x78);
    func_80026DAC_279AC(1, 0x40, 0x40, 0x60);
    func_80026E00_27A00(1, -100.0f, 100.0f, 300.0f);
    func_80062E10_63A10(0x3B, 0x50, 0, 0);
    space = GetSpaceData(0x1C);
    func_80056658_57258(&space->coords, &GetSpaceData(0x17)->coords, &dir);
    MBMasuArrowAngleAdd(func_80042BE0_437E0(&dir) + 180.0f);
    for (i = 0; i < 4; i++) {
        BoardPlayerGet(i)->coins = 10;
    }
    func_8010298C_325D4C_name_4C();
    func_80102A44_325E04_name_4C();
    func_80102ACC_325E8C_name_4C();
    func_80102B68_325F28_name_4C();
    EventTableHydrate(D_8010554C_32890C_name_4C);
    for (i = 0; i < 4; i++) {
        player = BoardPlayerGet(i);
        index = GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain_index, player->cur_space_index);
        func_8005660C_5720C(i, index);
        MBPlayerForwardSet(i);
    }
    func_800514F0_520F0();
    func_80053608_54208(1.0f);
    MBCameraSpeedSet(-1.0f);
    MBDCameraPos3DSet(&PLAYER_MODEL_4C(-1)->pos);
    omAddPrcObj(func_80103C9C_32705C_name_4C, 0xEFFF, 0, 0);
    omAddPrcObj(func_80103150_326510_name_4C, 0x1005, 0, 0);
    omPrcSetStatBit(omAddPrcObj(func_80105164_328524_name_4C, 0x1005, 0, 0), 0x80);
}

/* .data (0x328890-0x328980, 801054D0-801055C0) */
board_overlay_entrypoint D_801054D0_328890_name_4C[] = {
    { 0, func_80102830_325BF0_name_4C },
    { 1, func_8010286C_325C2C_name_4C },
    { 2, func_801052CC_32868C_name_4C },
    { -1, NULL },
};
s16 D_801054F0_3288B0_name_4C[4] = { 4, 0, 1, 2 };
s32 D_801054F8_3288B8_name_4C[2] = { 0x00080039, 0x0008003A };
s32 D_80105500_3288C0_name_4C[3] = { 2, 0x0008003F, 0x00080047 };
BoardEventListEntry D_8010550C_3288CC_name_4C[2] = {
    { 1, 1, func_80102B88_325F48_name_4C },
    { 0, 0, NULL },
};
BoardEventListEntry D_8010551C_3288DC_name_4C[2] = {
    { 1, 1, func_80102BAC_325F6C_name_4C },
    { 0, 0, NULL },
};
s16 D_8010552C_3288EC_name_4C[4] = { 14, 3, -1, 0 };
s16 D_80105534_3288F4_name_4C[4] = { 1, 0, 0, 0 };
BoardEventListEntry D_8010553C_3288FC_name_4C[2] = {
    { 1, 2, func_80102C1C_325FDC_name_4C },
    { 0, 0, NULL },
};
BoardEventTableEntry D_8010554C_32890C_name_4C[4] = {
    { 5, D_8010550C_3288CC_name_4C },
    { 10, D_8010551C_3288DC_name_4C },
    { 25, D_8010553C_3288FC_name_4C },
    { -1, NULL },
};
s32 D_8010556C_32892C_name_4C[10] = {
    0x000A001E, 0x000A001F, 0x000A0020, 0x000A0176, 0x000A0179,
    0x000A0023, 0x000A0024, 0x000A0025, 0x000A0177, 0x000A0178,
};
s32 D_80105594_328954_name_4C[3] = { 0x000A0160, 0x000A017B, 0x000A017A };
s32 D_801055A0_328960_name_4C[6] = { 5, 0x000800CE, 0x000800CF, 0x000800D1, 0x000800D0, 0x000800D2 };
s16 D_801055B8_328978_name_4C = -1;
s32 D_801055BC_32897C_name_4C = 1;
