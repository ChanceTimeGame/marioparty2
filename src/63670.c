#include "common.h"
#include "game/object.h"

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

INCLUDE_ASM("asm/nonmatchings/63670", func_80062B14_63714);

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

INCLUDE_ASM("asm/nonmatchings/63670", func_80062CC0_638C0);

INCLUDE_ASM("asm/nonmatchings/63670", func_80062CCC_638CC);

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

INCLUDE_ASM("asm/nonmatchings/63670", func_80062D44_63944);

INCLUDE_ASM("asm/nonmatchings/63670", func_80062D50_63950);

INCLUDE_ASM("asm/nonmatchings/63670", func_80062E10_63A10);

INCLUDE_ASM("asm/nonmatchings/63670", func_80063178_63D78);

INCLUDE_ASM("asm/nonmatchings/63670", func_800632E4_63EE4);

INCLUDE_ASM("asm/nonmatchings/63670", func_800632F0_63EF0);

INCLUDE_ASM("asm/nonmatchings/63670", func_800632FC_63EFC);

INCLUDE_ASM("asm/nonmatchings/63670", func_80063308_63F08);

INCLUDE_ASM("asm/nonmatchings/63670", func_800636F8_642F8);

INCLUDE_ASM("asm/nonmatchings/63670", func_80063704_64304);

void func_80063710_64310(Vec* pos) {
    D_800E1FA4_E2BA4 = *pos;
}

INCLUDE_ASM("asm/nonmatchings/63670", func_80063734_64334);

INCLUDE_ASM("asm/nonmatchings/63670", func_80063740_64340);

INCLUDE_ASM("asm/nonmatchings/63670", func_80063844_64444);

INCLUDE_ASM("asm/nonmatchings/63670", func_800638C8_644C8);

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

INCLUDE_ASM("asm/nonmatchings/63670", func_80063BBC_647BC);

INCLUDE_ASM("asm/nonmatchings/63670", func_80063C40_64840);

INCLUDE_ASM("asm/nonmatchings/63670", func_80063F88_64B88);

INCLUDE_ASM("asm/nonmatchings/63670", func_80064134_64D34);

void MBBattleKuriboObjMain(omObjData *arg0) {
    mbBattleKuriboMdl->coords.y = HuMathSin(arg0->rot.x) * 3.0f;
    mbBattleKuriboUpperMdl->coords.y = HuMathSin(arg0->rot.x) * 3.0f;
    arg0->rot.x += 10.0f;
}

INCLUDE_ASM("asm/nonmatchings/63670", func_80064200_64E00);

INCLUDE_ASM("asm/nonmatchings/63670", func_800645C8_651C8);

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

INCLUDE_ASM("asm/nonmatchings/63670", func_800650BC_65CBC);

INCLUDE_ASM("asm/nonmatchings/63670", func_800650F0_65CF0);

INCLUDE_ASM("asm/nonmatchings/63670", func_8006692C_6752C);

INCLUDE_ASM("asm/nonmatchings/63670", func_80066994_67594);

INCLUDE_ASM("asm/nonmatchings/63670", func_80066C34_67834);

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

INCLUDE_ASM("asm/nonmatchings/63670", func_80067004_67C04);

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

INCLUDE_ASM("asm/nonmatchings/63670", func_8006706C_67C6C);

void func_8006707C_67C7C(s16 arg0, s16 arg1) {
    D_800E1F94_E2B94 = 0x10;
    D_800E1F96_E2B96 = arg0;
    D_800E1F98_E2B98 = arg1;
    func_80062CC0_638C0();
}

INCLUDE_ASM("asm/nonmatchings/63670", func_800670B0_67CB0);

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

INCLUDE_ASM("asm/nonmatchings/63670", MBPlayerVibrate);

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
