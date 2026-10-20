#include "common.h"
#include "game/object.h"

void PlaySound(s32);
void func_800116B4_122B4(s16, s32);
s16 GetCurrentPlayerIndex(void);
void omVibrate(s16, s16, s16, s16);


extern s8 D_800CCC14_CD814;
extern s8 D_800CCC15_CD815;
extern s16 D_800E1FE4_E2BE4;
extern s16 D_800E1FE6_E2BE6;
extern s16 D_800F8518_F9118;
extern s16 D_800F8CE4_F98E4[];
extern s16 D_800F8F58_F9B58;
extern s16 D_800F9560_FA160;
extern s16 D_800FA60A_FB20A;
extern s16 D_800FCE80_FDA80;
extern s16 D_800FD2A0_FDEA0;
extern s16 D_800FD2B4_FDEB4;
extern s16 D_800FD898_FE498;
extern s16 D_800FDBD8_FE7D8;
extern s16 D_800FDEAC_FEAAC;
extern s16 D_800FFDF0_1009F0;
extern s16 D_800FFDF8_1009F8;
extern s32 D_80100028_100C28;
extern s16 D_801026D6_1032D6;
extern s16 D_801027D8_1033D8;
extern s16 D_801027F8_1033F8;
extern s16 D_800F64B0_F70B0;
extern s16 D_800FA652_FB252;
void func_8004A908_4B508(void);
void func_8005DF18_5EB18(s32);



extern s32 D_800CCC10;
void func_80047B78_48778(void);
void func_8005FF9C_60B9C(void);
void func_8004EA90_4F690(void);
void func_8004C394_4CF94(void);
void func_8004A9EC_4B5EC(void);
void func_8005E584_5F184(void);
void func_8008CE5C_8DA5C(void);
void func_800508C8_514C8(void);
void func_8005E2FC_5EEFC(void);
void func_8004340C_4400C(void);
void func_80041AE4_426E4(void);
void func_80054AE8_556E8(void);
void func_8005429C_54E9C(void);
void MBDBackKill(void);
void func_80050AE0_516E0(void);
void func_80050AD4_516D4(void);
void func_80053DEC_549EC(void);
void func_80053DD0_549D0(void);



extern u8 D_01164160[];
void func_80053A8C_5468C(void);
void func_80050A30_51630(u8*);
void func_80050E00_51A00(s32);
void func_80054228_54E28(void);
void MBMasuCreate(s32, s16);
void func_80041AA0_426A0(s32);
void MBModelInit(void);
void func_8005E2B8_5EEB8(void);
void func_800508B4_514B4(void);
void func_8005E1A0_5EDA0(s32);
void func_8005E154_5ED54(s32);
void func_8005070C_5130C(void);
void func_80043DAC_449AC(Object*);
void MBModelDispOff(Object*);
void func_8002D4A0_2E0A0(s16);
void func_8005E570_5F170(void);
void func_8004A98C_4B58C(void);
void MBCoinChangeInit(void);
void func_8004EA50_4F650(void);
void func_8005FE10_60A10(void);
void func_8005ECB8_5F8B8(void);
void func_80046238_46E38(void);
void func_80088640_89240(void);
void func_80056530_57130(void);
void func_80062D50_63950(void);



extern s32 D_800CCC40_CD840[];
extern void (*D_800CCC68_CD868)(void);
extern s16 D_800E1F88_E2B88;
void func_80056A3C_5763C(s8);
void func_80063308_63F08(void);


/* Board flow: overlay history, scenes, camera and rumble. C from MP1 src/57330.c, src/5CDB0.c,
   src/59510.c and MP3 ovl_80_shared_board 10C230.c / 113520.c, ovl_81 E3CD0.c / E78B0.c; the rest
   have no reference or differ (near) and stay asm, and func_80063BBC and MBPlayerVibrate stay asm
   because their rodata (D3BE8-D3D48) is shared with asm functions. */

#define CUR_PLAYER -1

typedef struct UnkE78B0 {
    /* 0x00 */ s16 unk_00; /* player */
    /* 0x02 */ s16 unk_02; /* type */
    /* 0x04 */ s16 unk_04; /* delay */
    /* 0x08 */ Process* proc;
} UnkE78B0; // size 0xC

s16 func_80055900_56500(u8);
void func_8004CA14_4D614(s32, s32);
void func_8006135C_61F5C(s32, s32, s32);
extern s16 coinBlockSpaceIndex;
extern s16 prevCoinBlockSpaceIndexes[10];
extern u16 D_800FA654_FB254;
extern u16 D_800FC878_FD478;
extern s16 starBlockSpaceIndex;
extern s16 prevStarBlockSpaceIndexes[10];
extern s32 D_800CCC1C_CD81C[];
extern s16 mbovlhisidx;
extern omOvlHisData mbovlhis[5];
extern s16 D_800E1F50_E2B50;
extern s16 D_800E1F80_E2B80;
extern s16 D_800E1F82_E2B82;
extern s32 mbGameMode;
extern s16 D_800E1F94_E2B94;
extern s16 D_800E1F96_E2B96;
extern s16 D_800E1F98_E2B98;
extern s32 D_800E1F9C_E2B9C;
extern Vec D_800E1FA4_E2BA4;
extern Object* mbBattleKuriboMdl;
extern Object* mbBattleKuriboUpperMdl;
extern s32 D_800CCDD0_CD9D0;
extern s32 D_800CCDD4_CD9D4;
extern s32 D_800CCDD8_CD9D8;
extern s32 D_800CCDDC_CD9DC;
extern s8 D_800CCDE0_CD9E0[];

GW_PLAYER* BoardPlayerGet(s32);
f32 HuMathSin(f32);
f32 MBCameraSpeedGet(void);
void MBCameraSpeedSet(f32);
u16 MBDCameraPos3DSet(Vec*);
void MBPlayerVibrate(s16, s16);
void func_800514F0_520F0(void);
void func_80051788_52388(void);
void func_800517C0_523C0(void);
void func_80053608_54208(f32);
f32 func_80053614_54214(void);
void* HuMemMemoryAllocTemp(u32 size);
void HuMemMemoryFreeTemp(void* ptr);
s32 PlayerIsCPU(s16);
void func_800797DC_7A3DC(s32, s16);
s32 func_8004E94C_4F54C(void);
void func_800537A0_543A0(Vec2f* arg0);
u16 func_800536E4_542E4(Vec2f* arg0);
extern u16 ContDStkTrg[4];
extern s32 D_800CCC18_CD818;
extern s16 D_800E1FA2_E2BA2;
extern Vec* D_800E1FB0_E2BB0;
extern Vec D_800E1FE8_E2BE8[4];
extern f32 D_800CCC6C_CD86C[][2];
extern f32 D_800CCC8C_CD88C[][2];
extern f32 D_800CCCA4_CD8A4[][2];
extern f32 D_800CCCB4_CD8B4[][2];
extern f32 D_800CCCD4_CD8D4[][2];
extern f32 D_800CCCEC_CD8EC[][2];
SpaceData* GetSpaceData(s16);
s16 GetAbsSpaceIndexFromChainSpaceIndex(u16 chainIndex, u16 spaceIndex);
void HuVecCopyXYZ(Vec* out, f32 x, f32 y, f32 z);
void func_800B3170_B3D70(Vec* dst, Vec* src); /* HuVecCopy3F */
extern f32 D_800CCD04_CD904[][2];
extern f32 D_800CCD2C_CD92C[][2];
void HuVecSubtract(Vec* out, Vec* a, Vec* b);
f32 func_80042BE0_437E0(Vec*); /* MBVecAngleGet */
void func_80064FF8_65BF8(void);
void func_80067040_67C40(s32 arg0, s16 arg1, s16 arg2);
void func_80067C6C_6886C(s32 arg0);
void func_80063178_63D78(void);
void func_8005660C_5720C(s16 arg0, s16 arg1); /* MBPlayerPosMasuSet */
void func_80029708_2A308(s32);
void func_8005E374_5EF74(void);
void func_8005E310_5EF10(void);
void func_8008F624_90224(s32, s32, s32);
void func_80052E68_53A68(f32); /* MBCameraZoomSet */
void func_800650F0_65CF0(void);
void func_80063950_64550(void);
void func_80066994_67594(void);
void func_800636F8_642F8(s32);
s32 func_80011308_11F08(s16);
void func_800498CC_4A4CC(void);
void func_80060034_60C34(s32, s32); /* MBStatusColorSet */
void func_80061518_62118(void);
void omPrcSetStatBit(Process* process, s32 value);
extern s16 D_800CCC64_CD864;
extern f32 D_800E1F84_E2B84;
extern s16 D_800FA188_FAD88;
extern s16 D_800FA198_FAD98;
extern s16 D_800FC734_FD334;
extern s16 D_800FA1A4_FADA4;
extern s16 D_80101058_101C58;
Process* func_80056D80_57980(Vec* arg0, Vec* arg1, Vec* arg2, s32 arg3); /* MBPlayerPosMoveCreate */

/* MP2 compares a player's chain and space index (0x10, 0x12) as one word */
#define PLAYER_CHAIN_SPACE(p) (*(s32*)&(p)->cur_chain_index)
#define PLAYER_NEXT_CHAIN_SPACE(p) (*(s32*)&(p)->next_chain_index)
#define PLAYER_MODEL(p) ((Object*)(p)->unk_24)

void MBOvlCall(s32 arg0, s16 arg1, s16 arg2) {
    omOvlHisData* temp_v1;
    temp_v1 = &mbovlhis[mbovlhisidx++];
    
    switch (arg0) {
    case -1:
        arg0 = omovlhis[omovlhisidx].overlayID;
        temp_v1->overlayID = arg0;
        break;
    case -2:
        arg0 = D_800CCC1C_CD81C[GwSystem.current_board_index];
        temp_v1->overlayID = arg0;
        break;
    default:
        temp_v1->overlayID = arg0;
    }
    
    temp_v1->event = arg1;
    temp_v1->stat = arg2;
    if (mbovlhisidx >= 5) {
        mbovlhisidx = 4;
    }
}

void func_80062B14_63714(void) {
    D_800E1F50_E2B50 = 1;
    mbovlhisidx = 0;
    if (_CheckFlag(0x41) == 0) {
        switch (GwSystem.current_board_index) {
        case 6:
        case 8:
            break;
        default:
            MBOvlCall(-2, 4, 0x192);
            break;
        }
        if (D_800CCC40_CD840[GwSystem.current_board_index] != 0) {
            MBOvlCall(D_800CCC40_CD840[GwSystem.current_board_index], 0, 0x192);
        }
        MBOvlCall(-2, 1, 0x192);
    }
    GwSystem.unk_00 = 2;
    func_80063308_63F08();
    func_80056A3C_5763C(GwSystem.unk_26[0]);
    _ClearFlag(0x12);
    D_800E1F82_E2B82 = 0;
}
void func_80062BE0_637E0(void) {
    omOvlHisData* history;

    D_800E1F80_E2B80 = 1;
    if (mbovlhisidx != 0) {
        history = &mbovlhis[--mbovlhisidx];
        ((s32 (*)(s32, s16, u16))omOvlCallEx)(history->overlayID, history->event, history->stat);
        return;
    }
    if (D_800E1F50_E2B50 != 0) {
        D_800E1F80_E2B80 = 0;
        omOvlCallEx(D_800CCC1C_CD81C[GwSystem.current_board_index], 2, 0x192);
        return;
    }
    
    _ClearFlag(13);
    
    if (D_800E1F82_E2B82 != 0) {
        _SetFlag(18);
    } else {
        _ClearFlag(18);
    }
    omOvlReturnEx(1);
}

void func_80062CC0_638C0(void) {
    D_800E1F50_E2B50 = 0;
}
s16 func_80062CCC_638CC(void) {
    return D_800E1F80_E2B80;
}
void func_80062CD8_638D8(s16 arg0) {
    s16 temp_v0 = mbovlhisidx;

    mbovlhis[mbovlhisidx].event = arg0;
    mbovlhisidx = temp_v0 + 1;
    if (mbovlhisidx >= ARRAY_COUNT(mbovlhis)) {
        mbovlhisidx = ARRAY_COUNT(mbovlhis) - 1;
    }
    MBOvlCall(-2, 3, 0x192);
    omOvlReturnEx(1);
}

s32 func_80062D44_63944(void) {
    return mbGameMode;
}
void func_80062D50_63950(void) {
    s32* temp_s0 = HuPrcCurrentGet()->user_data;

    while (1) {
        if ((PlayerIsCPU(temp_s0[0]) == 0) &&
            ((GwSystem.current_player_index != temp_s0[0]) || (D_800CCC18_CD818 == 0)) &&
            (ContDStkTrg[gPlayers[temp_s0[0]].port] & 0x20)) {
            func_800797DC_7A3DC(0x4B6, temp_s0[0]);
        }
        HuPrcVSleep();
    }
}

/* Board scene setup (MP1 func_80056A08, MP3 MBObjectSetup) */
void func_80062E10_63A10(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    Process* proc;
    s32* work;
    u16 cur;
    s32 i;
    GW_SYSTEM* sys;

    func_80053A8C_5468C();
    func_80050A30_51630(D_01164160);
    if (arg0 >= 0) {
        func_80050E00_51A00(arg0);
    }
    func_80054228_54E28();
    if (arg1 >= 0) {
        MBMasuCreate(0xA, arg1);
    }
    func_80041AA0_426A0(arg2);
    MBModelInit();
    func_8005E2B8_5EEB8();
    func_800508B4_514B4();
    if (GwSystem.current_player_index == 4) {
        func_8005E1A0_5EDA0(0);
        func_8005E1A0_5EDA0(1);
        func_8005E1A0_5EDA0(2);
        func_8005E1A0_5EDA0(3);
        func_8005070C_5130C();
    } else {
        func_8005E154_5ED54(0);
        func_8005E154_5ED54(1);
        func_8005E154_5ED54(2);
        func_8005E154_5ED54(3);
    }
    func_80043DAC_449AC(PLAYER_MODEL(BoardPlayerGet(0)));
    func_80043DAC_449AC(PLAYER_MODEL(BoardPlayerGet(1)));
    func_80043DAC_449AC(PLAYER_MODEL(BoardPlayerGet(2)));
    func_80043DAC_449AC(PLAYER_MODEL(BoardPlayerGet(3)));
    PLAYER_MODEL(BoardPlayerGet(0))->flags |= 2;
    PLAYER_MODEL(BoardPlayerGet(1))->flags |= 2;
    PLAYER_MODEL(BoardPlayerGet(2))->flags |= 2;
    PLAYER_MODEL(BoardPlayerGet(3))->flags |= 2;
    sys = &GwSystem;
    cur = sys->current_player_index;
    if (cur < 4 && gPlayers[sys->current_player_index].turn_status != 0) {
        func_8005070C_5130C();
        MBModelDispOff(PLAYER_MODEL(&gPlayers[sys->current_player_index]));
    }
    func_8002D4A0_2E0A0(PLAYER_MODEL(BoardPlayerGet(0))->omObj1->model[0]);
    func_8002D4A0_2E0A0(PLAYER_MODEL(BoardPlayerGet(1))->omObj1->model[0]);
    func_8002D4A0_2E0A0(PLAYER_MODEL(BoardPlayerGet(2))->omObj1->model[0]);
    func_8002D4A0_2E0A0(PLAYER_MODEL(BoardPlayerGet(3))->omObj1->model[0]);
    func_8005E570_5F170();
    func_8004A98C_4B58C();
    MBCoinChangeInit();
    func_8004EA50_4F650();
    func_8005FE10_60A10();
    if (GwSystem.current_board_index == 5) {
        func_80061518_62118();
        func_8005ECB8_5F8B8();
    }
    func_80046238_46E38();
    func_80088640_89240();
    func_80056530_57130();
    D_800E1F94_E2B94 = -1;
    D_800E1F96_E2B96 = 0;
    D_800E1F98_E2B98 = 0;
    func_8005E310_5EF10();
    D_800CCC68_CD868 = 0;
    for (i = 0; i < 4; i++) {
        proc = omAddPrcObj(func_80062D50_63950, 0, 0, 0x40);
        work = HuMemMemoryAlloc(proc->heap, 0x10);
        proc->user_data = work;
        work[0] = i;
        omPrcSetStatBit(proc, 0xA0);
    }
}
/* Board scene teardown (MP1 func_80056AF4, MP3 MBExit); D_800CCC10 traces progress */
void func_80063178_63D78(void) {
    D_800CCC10 = 1;
    func_80047B78_48778();
    D_800CCC10 = 2;
    func_8005FF9C_60B9C();
    D_800CCC10 = 3;
    func_8004EA90_4F690();
    D_800CCC10 = 4;
    func_8004C394_4CF94();
    D_800CCC10 = 5;
    func_8004A9EC_4B5EC();
    D_800CCC10 = 6;
    func_8005E584_5F184();
    D_800CCC10 = 7;
    func_8008CE5C_8DA5C();
    D_800CCC10 = 8;
    func_800508C8_514C8();
    D_800CCC10 = 9;
    func_8005E2FC_5EEFC();
    D_800CCC10 = 10;
    func_8004340C_4400C();
    D_800CCC10 = 11;
    func_80041AE4_426E4();
    D_800CCC10 = 12;
    func_80054AE8_556E8();
    D_800CCC10 = 13;
    func_8005429C_54E9C();
    D_800CCC10 = 14;
    MBDBackKill();
    D_800CCC10 = 15;
    func_80050AE0_516E0();
    D_800CCC10 = 16;
    func_80050AD4_516D4();
    D_800CCC10 = 17;
    func_80053DEC_549EC();
    D_800CCC10 = 18;
    func_80053DD0_549D0();
    D_800CCC10 = 19;
    if (D_800CCC68_CD868 != NULL) {
        D_800CCC68_CD868();
    }
    func_80064FF8_65BF8();
    D_800CCC10 = 20;
}
void func_800632E4_63EE4(void (*arg0)(void)) {
    D_800CCC68_CD868 = arg0;
}
void func_800632F0_63EF0(s16 arg0) {
    D_800E1F88_E2B88 = arg0;
}
s16 func_800632FC_63EFC(void) {
    return D_800E1F88_E2B88;
}
/* Board game-state reset (MP1 func_80056B78, MP3 MBSaveInit) */
void func_80063308_63F08(void) {
    GW_PLAYER* player;
    GW_SYSTEM* sys = &GwSystem;
    s32 i;

    D_801027D8_1033D8 = 0;
    D_800FD898_FE498 = 0;
    D_800FA60A_FB20A = 0;
    D_801026D6_1032D6 = 0;
    D_800FD2A0_FDEA0 = 0;
    D_800FCE80_FDA80 = 0;
    D_800F8518_F9118 = 0;
    D_800F8F58_F9B58 = 0;
    D_801027F8_1033F8 = 0;
    D_800FDBD8_FE7D8 = 0;
    D_800FFDF8_1009F8 = 0;
    D_800FD2B4_FDEB4 = 0;
    D_800F9560_FA160 = 0;
    mbGameMode = 0;
    D_80100028_100C28 = 0;
    D_800FA654_FB254 = 0;
    D_800FC878_FD478 = 0;
    starBlockSpaceIndex = -1;
    coinBlockSpaceIndex = -1;
    D_800FFDF0_1009F0 = 0;
    D_800FDEAC_FEAAC = 0;
    for (i = 0; i < 10; i++) {
        prevCoinBlockSpaceIndexes[i] = prevStarBlockSpaceIndexes[i] = -1;
    }
    D_800E1FE6_E2BE6 = 0;
    D_800E1FE4_E2BE4 = 0;
    D_800E1F84_E2B84 = 1.0f;
    func_8004A908_4B508();
    D_800CCC64_CD864 = -1;
    D_800F64B0_F70B0 = -1;
    D_800FA652_FB252 = 0;
    D_800CCC18_CD818 = 1;
    func_8005DF18_5EB18(0);
    func_8005DF18_5EB18(1);
    func_8005DF18_5EB18(2);
    func_8005DF18_5EB18(3);
    if (_CheckFlag(0x41) != 0) {
        D_800CCC14_CD814 = sys->unk_25;
        D_800CCC15_CD815 = sys->unk_26[0];
        return;
    }
    sys->unk_0A = 0;
    sys->current_turn = 1;
    sys->current_player_index = 0;
    sys->chosenMinigameIndex = 0;
    sys->unk_1C = -1;
    if (_CheckFlag(0xD) == 0) {
        switch (sys->current_game_length) {
            case 0:
                sys->total_turns = 20;
                break;
            case 1:
                sys->total_turns = 35;
                break;
            case 2:
                sys->total_turns = 50;
                break;
        }
    } else {
        switch (sys->current_game_length) {
            case 0:
                sys->total_turns = 10;
                break;
            case 1:
                sys->total_turns = 20;
                break;
            case 2:
                sys->total_turns = 30;
                break;
        }
    }
    sys->unk_24[0] = 2;
    if (D_800CCC14_CD814 == -1) {
        sys->unk_25 = 0;
    } else {
        sys->unk_25 = D_800CCC14_CD814;
    }
    if (D_800CCC15_CD815 == -1) {
        sys->unk_26[0] = 1;
    } else {
        sys->unk_26[0] = D_800CCC15_CD815;
    }
    for (i = 0; i < 5; i++) {
        player = BoardPlayerGet(i);
        player->stars = 0;
        player->unk_18 = 0;
        player->coins_total = 0;
        player->coins_max = 0;
        player->happening_spaces_landed_on = 0;
        player->red_spaces_landed_on = 0;
        player->blue_spaces_landed_on = 0;
        player->chance_spaces_landed_on = 0;
        player->bowser_spaces_landed_on = 0;
        player->battle_spaces_landed_on = 0;
        player->item_spaces_landed_on = 0;
        player->bank_spaces_landed_on = 0;
        player->item = -1;
        player->turn_status = 0;
    }
    for (i = 0; i < 32; i++) {
        D_800F8CE4_F98E4[i] = 0;
    }
    _ClearFlag(0x46);
    _ClearFlag(0x47);
    _ClearFlag(0x48);
    _ClearFlag(0x49);
    _ClearFlag(0x4A);
    _ClearFlag(0x4B);
    _ClearFlag(0x4C);
    _ClearFlag(0x50);
    _ClearFlag(0x51);
    _ClearFlag(0x52);
    _ClearFlag(0x53);
    _ClearFlag(0x54);
    _ClearFlag(0x55);
    _ClearFlag(0x56);
    _ClearFlag(0x57);
    _ClearFlag(0x58);
    _ClearFlag(0x59);
    _ClearFlag(0x5A);
    _ClearFlag(0x5B);
    _ClearFlag(0x5C);
    _ClearFlag(0x5D);
    _ClearFlag(0x5E);
    _ClearFlag(0x42);
    _ClearFlag(0x43);
    _ClearFlag(0x44);
    _ClearFlag(0x4D);
    _ClearFlag(0x41);
}
void func_800636F8_642F8(s32 arg0) {
    D_800E1FA2_E2BA2 = arg0;
}
s16 func_80063704_64304(void) {
    return D_800E1FA2_E2BA2;
}
void func_80063710_64310(Vec* pos) {
    D_800E1FA4_E2BA4 = *pos;
}

void func_80063734_64334(Vec* arg0) {
    D_800E1FB0_E2BB0 = arg0;
}
void func_80063740_64340(void) {
    Vec2f sp10;

    while (1) {
        switch (D_800E1FA2_E2BA2) {
            case 1:
                MBDCameraPos3DSet(&((Object*)gPlayers[GwSystem.current_player_index].unk_24)->coords);
                break;
            case 2:
                MBDCameraPos3DSet(&D_800E1FA4_E2BA4);
                break;
            case 4:
                MBDCameraPos3DSet(D_800E1FB0_E2BB0);
                break;
            case 3:
                func_800537A0_543A0(&sp10);
                func_800536E4_542E4(&sp10);
                break;
        }
        HuPrcVSleep();
    }
}

void func_80063844_64444(void) {
    GW_SYSTEM* sys = &GwSystem;

    if (++sys->current_player_index >= 4 && func_8004E94C_4F54C() == 0) {
        sys->current_player_index = 0;
        if (++sys->current_turn >= 99) {
            sys->current_turn = 99;
        }
    }
}

/* 1 when five turns are left once the last player of the round has moved (MP1 func_80056FA8) */
// GCC folds the final compare into xor/sltiu; retail branches to separate return 0/1 (masked 7)
#ifdef NON_MATCHING
s32 func_800638C8_644C8(void) {
    GW_SYSTEM* sys = &GwSystem;

    if (_CheckFlag(0xD) != 0) {
        return 0;
    }
    if ((sys->current_player_index == 3 && func_8004E94C_4F54C() == 0) || (u16)sys->current_player_index >= 4) {
        if (sys->total_turns >= 0) {
            if (sys->current_turn != sys->total_turns - 5) {
                return 0;
            }
            return 1;
        }
        return 0;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/63670", func_800638C8_644C8);
#endif

extern s32 D_800CCC10;
extern s16 D_800E1F82_E2B82;
extern s16 D_800E1F94_E2B94;
extern s16 D_800E1F96_E2B96;
extern s16 D_800E1F98_E2B98;
extern s32 D_800E1F9C_E2B9C;
extern s16 D_800E1FA0_E2BA0;
extern s16 D_800F64B0_F70B0;
extern s16 D_800FA652_FB252;
extern u16 D_801011FC_101DFC;

void func_80063950_64550(void) {
    s16 minigameOverlayID;

    do {
        HuPrcVSleep();
    } while (func_8008F618_90218() != 0);
    while (1) {
        HuPrcVSleep();
        if (D_801011FC_101DFC == 0) {
            if (D_800E1F94_E2B94 < 0) {
                continue;
            }
        }
        D_800CCC10 = 0;
    
        while (func_8008F618_90218() != 0) {
            HuPrcVSleep();
        }
        
        if (D_800E1F98_E2B98 != 0) {
            func_800794A8_7A0A8(0x5A);
            if (D_800F64B0_F70B0 != -1) {
                func_800114E8_120E8(D_800F64B0_F70B0, 0x5A);
                D_800F64B0_F70B0 = -1;
                func_80079464_7A064();
            }
            if (D_800FA652_FB252 != 0) {
                func_80079464_7A064();
                D_800FA652_FB252 = 0;
            }
        }
        D_800CCC10 = 0x64;
        InitFadeOut(D_800E1F96_E2B96, 0x10);
        HuPrcSleep(17);
        D_800CCC10 = 0x65;
        func_80063178_63D78();
        D_800CCC10 = 0x66;
        
        if (D_800E1F94_E2B94 & 0x20) {
            D_800E1F82_E2B82 = 1;
            if ((GwSystem.current_board_index == 5) && (_CheckFlag(0xB) == 0)) {
                MBOvlCall(0x61, 0, 0x192);
            }
            MBOvlCall(0x52, 0, 0x192);
            func_80062CC0_638C0();
        }
        
        if (D_800E1F94_E2B94 & 1) {
            if (func_800638C8_644C8() != 0) {
                MBOvlCall(0x40, 0, 0x192);
            }
            func_80063844_64444();
        }
        
        D_800CCC10 = 0x67;
        
        if (D_800E1F94_E2B94 & 2) {
            minigameOverlayID = func_8003F6F0_402F0(GwSystem.chosenMinigameIndex);
            MBOvlCall(minigameOverlayID, 0, 0x94);
        }
        
        D_800CCC10 = 0x68;
        
        if (D_800E1F94_E2B94 & 8) {
            MBOvlCall(D_800E1F9C_E2B9C, D_800E1FA0_E2BA0, 0x192);
        }
        
        D_800CCC10 = 0x69;
        _ClearFlag(0x45);
        omOvlReturnEx(1);
        omOvlKill();
        HuPrcVSleep();
    }
}

void func_80063BBC_647BC(s16 arg0) {
    switch (--arg0) {
        case 3:
            PlaySound(0x334);
            break;
        case 0:
            PlaySound(0x316);
            break;
        case 1:
            PlaySound(0x317);
            break;
        case 11:
            PlaySound(0x344);
            break;
        case 4:
        case 5:
            PlaySound(0x371);
            break;
        case 8:
            PlaySound(0x372);
            break;
        case 6:
            PlaySound(0x373);
            break;
        case 13:
            PlaySound(0x341);
            break;
    }
}
/* MP3 MBPlayerPosFixSet */
void func_80063C40_64840(s32 playerNo, s32 arg1) {
    GW_PLAYER* player;
    GW_PLAYER* playerCur;
    SpaceData* space;
    s32 var_s1;
    s32 var_s4;
    s32 playersShareSpace;
    s32 i;
    GW_SYSTEM* system = &GwSystem;

    player = BoardPlayerGet(playerNo);
    space = GetSpaceData(GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain_index, player->cur_space_index));
    if (system->current_player_index == playerNo) {
        func_800B3170_B3D70(&PLAYER_MODEL(player)->coords, &space->coords);
        return;
    }

    playerCur = BoardPlayerGet(system->current_player_index);
    var_s4 = 0;
    playersShareSpace = PLAYER_CHAIN_SPACE(player) == PLAYER_CHAIN_SPACE(playerCur);

    var_s1 = 0;
    for (i = 0; i < 4; i++) {
        if ((playerNo != i) && (i != system->current_player_index)) {
            if (PLAYER_CHAIN_SPACE(player) == PLAYER_CHAIN_SPACE(BoardPlayerGet(i))) {
                var_s1 += 1;
                var_s4 += i < playerNo;
            }
        }
    }

    if (playersShareSpace == 1) {
        if (var_s1 == 2) {
            HuVecCopyXYZ(&D_800E1FE8_E2BE8[playerNo], space->coords.x + D_800CCCD4_CD8D4[var_s4][0], space->coords.y, space->coords.z + D_800CCCD4_CD8D4[var_s4][1]);
        } else if (var_s1 == 3) {
            HuVecCopyXYZ(&D_800E1FE8_E2BE8[playerNo], space->coords.x + D_800CCCB4_CD8B4[var_s4][0], space->coords.y, space->coords.z + D_800CCCB4_CD8B4[var_s4][1]);
        } else {
            HuVecCopyXYZ(&D_800E1FE8_E2BE8[playerNo], space->coords.x + D_800CCCEC_CD8EC[var_s4][0], space->coords.y, space->coords.z + D_800CCCEC_CD8EC[var_s4][1]);
        }
    } else {
        if (var_s1 == 0) {
            func_800B3170_B3D70(&D_800E1FE8_E2BE8[playerNo], &space->coords);
        } else if (var_s1 == 2) {
            HuVecCopyXYZ(&D_800E1FE8_E2BE8[playerNo], space->coords.x + D_800CCC8C_CD88C[var_s4][0], space->coords.y, space->coords.z + D_800CCC8C_CD88C[var_s4][1]);
        } else if (var_s1 == 3) {
            HuVecCopyXYZ(&D_800E1FE8_E2BE8[playerNo], space->coords.x + D_800CCC6C_CD86C[var_s4][0], space->coords.y, space->coords.z + D_800CCC6C_CD86C[var_s4][1]);
        } else {
            HuVecCopyXYZ(&D_800E1FE8_E2BE8[playerNo], space->coords.x + D_800CCCA4_CD8A4[var_s4][0], space->coords.y, space->coords.z + D_800CCCA4_CD8A4[var_s4][1]);
        }
    }

    if (arg1 < 2) {
        func_800B3170_B3D70(&PLAYER_MODEL(player)->coords, &D_800E1FE8_E2BE8[playerNo]);
        return;
    }
    func_80056D80_57980(&PLAYER_MODEL(player)->coords, &D_800E1FE8_E2BE8[playerNo], &PLAYER_MODEL(player)->coords, arg1);
}

s32 func_80063F88_64B88(s32 arg0) {
    Vec sp10;
    GW_PLAYER* curPlayer;
    GW_PLAYER* player;
    f32 var_f4;
    SpaceData* space;
    s32 var_s2;
    s32 var_s4;
    s32 i;

    curPlayer = BoardPlayerGet(arg0);
    var_s2 = 0;
    var_s4 = 0;

    for (i = 0; i < 4; i++) {
        if (i == arg0) {
            continue;
        }
        player = BoardPlayerGet(i);
        var_s4 += PLAYER_CHAIN_SPACE(curPlayer) == PLAYER_CHAIN_SPACE(player);
        var_s2 += PLAYER_NEXT_CHAIN_SPACE(curPlayer) == PLAYER_CHAIN_SPACE(player);
    }

    space = GetSpaceData(GetAbsSpaceIndexFromChainSpaceIndex(curPlayer->cur_chain_index, curPlayer->cur_space_index));
    HuVecSubtract(&sp10, &GetSpaceData(GetAbsSpaceIndexFromChainSpaceIndex(curPlayer->next_chain_index, curPlayer->next_space_index))->coords, &space->coords);
    var_f4 = func_80042BE0_437E0(&sp10);
    if ((var_s4 == 0) || (!(D_800CCD04_CD904[var_s4][0] < var_f4)) || (!(var_f4 <= D_800CCD04_CD904[var_s4][1]))) {
        if (var_s2 != 0) {
            if (D_800CCD2C_CD92C[var_s2][0] < 0.0f) {
                var_f4 -= 360.0f;
            }
            if (!(D_800CCD2C_CD92C[var_s2][0] < var_f4) || (!(var_f4 <= D_800CCD2C_CD92C[var_s2][1]))) {
                return 0;
            } else {
                return 1;
            }
        } else {
            return 0;
        }
    } else {
        return 1;
    }
}

void func_80064134_64D34(void) {
    HuPrcSleep(30);
    if (D_800F64B0_F70B0 == -1) {
        func_800116B4_122B4(D_800FA188_FAD88, 60);
        D_800FA652_FB252 = 0;
    }
    omDelPrcObj(NULL);
}
void MBBattleKuriboObjMain(omObjData *arg0) {
    mbBattleKuriboMdl->coords.y = HuMathSin(arg0->rot.x) * 3.0f;
    mbBattleKuriboUpperMdl->coords.y = HuMathSin(arg0->rot.x) * 3.0f;
    arg0->rot.x += 10.0f;
}

INCLUDE_ASM("asm/nonmatchings/63670", func_80064200_64E00);

INCLUDE_ASM("asm/nonmatchings/63670", func_800645C8_651C8);

const char D_800D3020_D3C20[] __attribute__((aligned(8), section(".rodata"))) = "%d";

void func_80064C98_65898(void) {
    s32 var_a0;
    s32 var_s2;
    s32 i;

    var_s2 = -1;
    var_a0 = 0;
    for (i = 0; i < MAX_PLAYERS; i++) {
        if (var_a0 < gPlayers[i].coins_mg_bonus) {
            var_s2 = i;
            var_a0 = gPlayers[i].coins_mg_bonus;
        }
    }

    for (i = 0; i < MAX_PLAYERS; i++) {
        if (gPlayers[i].coins_mg_bonus != 0) {
            func_8004CA14_4D614(i, gPlayers[i].coins_mg_bonus);
            if (var_s2 == i) {
                func_8006135C_61F5C(i, gPlayers[i].coins_mg_bonus, 1);
            } else {
                func_8006135C_61F5C(i, gPlayers[i].coins_mg_bonus, 0);    
            }            
        }
    }
    HuPrcSleep(30);
}

void func_80064DA8_659A8(void) {
    s32 i;

    if (_CheckFlag(0xD) == 0 && _CheckFlag(0x4E) != 0) {
        while (coinBlockSpaceIndex == -1 || coinBlockSpaceIndex == starBlockSpaceIndex) {
            coinBlockSpaceIndex = func_80055900_56500(D_800FC878_FD478);
            D_800FC878_FD478 += 1;
            for (i = 0; i < ARRAY_COUNT(prevCoinBlockSpaceIndexes); i++) {
                if (coinBlockSpaceIndex == prevCoinBlockSpaceIndexes[i]) {
                    break;
                }
            }
            if (i != ARRAY_COUNT(prevCoinBlockSpaceIndexes)) {
                coinBlockSpaceIndex = -1;
            }
        }
        while (starBlockSpaceIndex == -1 || coinBlockSpaceIndex == starBlockSpaceIndex) {
            starBlockSpaceIndex = func_80055900_56500(D_800FA654_FB254);
            D_800FA654_FB254 += 1;
            for (i = 0; i < ARRAY_COUNT(prevStarBlockSpaceIndexes); i++) {
                if (starBlockSpaceIndex == prevStarBlockSpaceIndexes[i]) {
                    break;
                }
            }
            if (i != ARRAY_COUNT(prevStarBlockSpaceIndexes)) {
                starBlockSpaceIndex = -1;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/63670", func_80064F1C_65B1C);

void func_80064FF8_65BF8(void) {
    if (D_800CCDD0_CD9D0 != NULL) {
        MBHelpWinKill(D_800CCDD0_CD9D0);
        D_800CCDD0_CD9D0 = NULL;
    }
    if (D_800CCDD4_CD9D4 != NULL) {
        MBHelpWinKill(D_800CCDD4_CD9D4);
        D_800CCDD4_CD9D4 = NULL;
    }
    if (D_800CCDD8_CD9D8 != NULL) {
        MBHelpWinKill(D_800CCDD8_CD9D8);
        D_800CCDD8_CD9D8 = NULL;
    }
    if (D_800CCDDC_CD9DC != NULL) {
        MBHelpWinKill(D_800CCDDC_CD9DC);
        D_800CCDDC_CD9DC = NULL;
    }
}

void func_8006508C_65C8C(void) {
    mbGameMode = 10;
    D_800E1F96_E2B96 = 11;
    func_80064FF8_65BF8();
}

void func_800650BC_65CBC(void) {
    mbGameMode = 0xB;
    func_80064FF8_65BF8();
    func_80067040_67C40(0x54, 0, 0);
}

INCLUDE_ASM("asm/nonmatchings/63670", func_800650F0_65CF0);

const u32 jtbl_800D3028_D3C28[] __attribute__((aligned(8), section(".rodata"))) = {
    0x80065970, 0x800659C4, 0x80065B84, 0x80065BD8,
    0x80065590, 0x800665AC, 0x800665F4, 0x800662A8,
    0x80065620, 0x80065480, 0x800665AC, 0x80066484,
    0x80066574,
};

const u32 jtbl_800D3060_D3C60[] __attribute__((aligned(8), section(".rodata"))) = {
    0x80065868, 0x80065868, 0x80065890, 0x80065868,
    0x80065868, 0x80065868, 0x80065868, 0x80065890,
    0x80065868, 0x80065890, 0x80065890, 0x80065868,
};

const u32 jtbl_800D3090_D3C90[] __attribute__((aligned(8), section(".rodata"))) = {
    0x80065900, 0x80065900, 0x80065918, 0x80065900,
    0x80065900, 0x80065900, 0x80065900, 0x80065918,
    0x80065900, 0x80065918, 0x80065918, 0x80065900,
    0x80065918, 0x800658C8, 0x800658E0,
};

const u32 jtbl_800D30D0_D3CD0[] __attribute__((aligned(8), section(".rodata"))) = {
    0x80065A98, 0x80065A7C, 0x80065B48, 0x80065A60,
    0x80065AA8, 0x80065B20, 0x80065B3C, 0x80065B48,
    0x80065AE0, 0x80065B48, 0x80065B48, 0x80065AC4,
};

const u32 jtbl_800D3100_D3D00[] __attribute__((aligned(8), section(".rodata"))) = {
    0x800662E8, 0x80066334, 0x800665B8, 0x800665B8,
    0x80066368, 0x800663B8, 0x800665B8, 0x800665B8,
    0x800664F4, 0x800665B8, 0x800665B8, 0x80066584,
};

const u32 jtbl_800D3130_D3D30[] __attribute__((aligned(8), section(".rodata"))) = {
    0x8006670C, 0x80066724, 0x8006673C, 0x80066724,
    0x8006670C,
};

void func_8006692C_6752C(void) {
    HuPrcVSleep();
    func_80067C6C_6886C(gPlayers[GwSystem.current_player_index].port);
    func_80063178_63D78();
    omOvlReturnEx(1);
    omOvlKill();
    HuPrcVSleep();
}

INCLUDE_ASM("asm/nonmatchings/63670", func_80066994_67594);

/* MP3 MBStart */
void func_80066C34_67834(u32 arg0) {
    GW_PLAYER* player;
    s32 i;

    for (i = 0; i < 4; i++) {
        s16 masuID;
        player = BoardPlayerGet(i);
        masuID = GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain_index, player->cur_space_index);
        func_8005660C_5720C(i, masuID);
    }

    func_800514F0_520F0();
    func_80053608_54208(1.0f);
    MBCameraSpeedSet(-1.0f);
    func_80029708_2A308(1);
    switch (arg0) {
        case 0:
            switch (mbGameMode) {
                case 0:
                case 1:
                    InitFadeIn(0, 0);
                    func_8005E374_5EF74();
                    break;
                default:
                    if (D_800CCC64_CD864 != -1) {
                        if (D_800CCC64_CD864 == 13) {
                            func_8008F624_90224(255, 255, 255);
                        } else {
                            func_8008F624_90224(0, 0, 0);
                        }
                        InitFadeIn(D_800CCC64_CD864, 0x10);
                        D_800CCC64_CD864 = -1;
                        MBPlayerVibrate(0, 0);
                        MBPlayerVibrate(1, 0);
                        MBPlayerVibrate(2, 0);
                        MBPlayerVibrate(3, 0);
                    } else {
                        InitFadeIn(0xFF, 0x10);
                    }
                    func_80052E68_53A68(D_800E1F84_E2B84);
                    func_8005E310_5EF10();
                    break;
            }
            MBDCameraPos3DSet(&PLAYER_MODEL(&gPlayers[GwSystem.current_player_index])->coords);
            omAddPrcObj(func_800650F0_65CF0, 0xEFFF, 0x2000, 0);
            omAddPrcObj(func_80063950_64550, 0x1005, 0, 0);
            omPrcSetStatBit(omAddPrcObj(func_80066994_67594, 0x1005, 0, 0), 0x80);
            D_800FA198_FAD98 = 0;
            D_800FC734_FD334 = 0;
            D_800FA1A4_FADA4 = 0;
            D_80101058_101C58 = 0;
            omAddPrcObj(func_80063740_64340, 0x1005, 0, 0);
            func_800636F8_642F8(1);
            if (func_80011308_11F08(D_800FA188_FAD88) < 0x7F) {
                func_800498CC_4A4CC();
                return;
            }
            return;
        case 1:
            MBDCameraPos3DSet(&PLAYER_MODEL(&gPlayers[GwSystem.current_player_index])->coords);
            for (i = 0; i < 4; i++) {
                func_80060034_60C34(i, (u8)BoardPlayerGet(i)->player_space_color);
            }
            omAddPrcObj(func_80063950_64550, 0x1005, 0, 0);
            omPrcSetStatBit(omAddPrcObj(func_8006692C_6752C, 0x1005, 0, 0), 0x80);
            D_800FA198_FAD98 = 1;
            return;
        case 2:
            func_80061518_62118();
            func_800636F8_642F8(0);
            break;
    }
}

void ExecBoardScene(board_overlay_entrypoint* arg0, s16 arg1) {
    if (arg0->index < 0) {
        return;
    }
    for (; arg0->index >= 0; arg0++) {
        if (arg0->index == arg1) {
            arg0->fn();
        }
    }       
}

void func_80066FD8_67BD8(s16 arg0) {
    D_800E1F50_E2B50 = 1;
    D_800E1F94_E2B94 = 0x40;
    D_800E1F96_E2B96 = arg0;
    D_800E1F98_E2B98 = 0;
}

void func_80067004_67C04(s16 arg0) {
    D_800CCC64_CD864 = arg0;
}
void func_80067010_67C10(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_800E1F9C_E2B9C = arg0;
    D_800E1FA0_E2BA0 = arg1;
    D_800E1F94_E2B94 = 8;
    D_800E1F96_E2B96 = arg2;
    D_800E1F98_E2B98 = arg3;
}

void func_80067040_67C40(s32 arg0, s16 arg1, s16 arg2) {
    func_80067010_67C10(arg0, arg1,  arg2, 0);
}

void func_8006706C_67C6C(void) {
    D_801011FC_101DFC = 1;
}
void func_8006707C_67C7C(s16 arg0, s16 arg1) {
    D_800E1F94_E2B94 = 0x10;
    D_800E1F96_E2B96 = arg0;
    D_800E1F98_E2B98 = arg1;
    func_80062CC0_638C0();
}

s16 func_800670B0_67CB0(void) {
    return D_800E1F94_E2B94;
}
void func_800670BC_67CBC(Vec *arg0) {
    f32 temp_f20;
    f32 temp_f22;

    func_800517C0_523C0();
    func_80051788_52388();
    temp_f22 = MBCameraSpeedGet();
    MBCameraSpeedSet(-1.0f);
    temp_f20 = func_80053614_54214();
    func_80053608_54208(1.0f);
    func_800514F0_520F0();

    if (arg0 == NULL) {
        arg0 = &((Object*)BoardPlayerGet(CUR_PLAYER)->unk_24)->coords;
    }

    MBDCameraPos3DSet(arg0);
    HuPrcVSleep();
    func_80053608_54208(temp_f20);
    MBCameraSpeedSet(temp_f22);
}

void MBPlayerVibrate(s16 playerIndex, s16 vibrationStrength) {
    if (playerIndex == CUR_PLAYER) {
        playerIndex = GetCurrentPlayerIndex();
    }
    if (playerIndex != 4) {
        switch (vibrationStrength) {
            case 0:
                omVibrate(playerIndex, 5, 0, 5);
                break;
            case 1:
                omVibrate(playerIndex, 2, 3, 10);
                break;
            case 2:
                omVibrate(playerIndex, 10, 0, 10);
                break;
            case 3:
                omVibrate(playerIndex, 2, 2, 20);
                break;
            case 4:
                omVibrate(playerIndex, 20, 0, 20);
                break;
            case 5:
                omVibrate(playerIndex, 30, 0, 30);
                break;
        }
    }
}
void func_8006727C_67E7C(void) {
    UnkE78B0* r = HuPrcCurrentGet()->user_data;

    while (1) {
        MBPlayerVibrate(r->unk_00, r->unk_02);
        HuPrcSleep(r->unk_04);
    }
}

void *func_800672BC_67EBC(s16 arg0, s16 arg1, s32 arg2) {
    Process *process;
    s16 temp_s1;
    UnkE78B0 *unk;

    temp_s1 = D_800CCDE0_CD9E0[arg1] + arg2;
    unk = HuMemMemoryAllocTemp(sizeof(UnkE78B0));

    if (unk != NULL) {
        unk->unk_00 = arg0;
        unk->unk_02 = arg1;
        unk->unk_04 = temp_s1 - 1;
        process = omAddPrcObj(func_8006727C_67E7C, 0x1005, 0, 0);
        unk->proc = process;
        process->user_data = unk;
    }

    return unk;
}

void func_8006735C_67F5C(UnkE78B0* r) {
    if (r != NULL) {
        omDelPrcObj(r->proc);
        HuMemMemoryFreeTemp(r);
    }
}
