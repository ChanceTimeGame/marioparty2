#include "common.h"
#include "game/board.h"
#include "process.h"
#include "game/pad.h"

/* Board HUD icon helpers. C from MP1 src/59710.c and ovl_33_PaddleBattle 2341E0.c; the rest have no
   reference or differ (near) and stay asm. */

void HuMemDirectFree(void*);
void SprAttrSet(s16, s16, s32);
void SprAttrReset(s16, s16, s32);
void func_80067558_68158(void);
void func_80067720_68320(void);
void func_8005390C_5450C(s32);
void func_80061584_62184(void);
s16 SprAnimRead(void*);
void SprAnimSet(s16, s16, s16, s16);
void SprPrioSet(s16, s16, s16);
void SprPosSet(s16, s16, s16, s16);
void SprRotSet(s16, s16, f32);
unk_Struct02* func_8005E688_5F288(s32, s32);

typedef struct Vec2fxy {
    f32 x;
    f32 y;
} Vec2fxy; /* as 51630 */

GW_PLAYER* BoardPlayerGet(s32);
void MBModelDispOn(void*);
void MBModelKill(void*);
f32 func_80052E5C_53A5C(void); /* MP3 MBCameraZoomGet */
void func_800537A0_543A0(Vec2fxy* arg0); /* MP3 MBCameraPos2DGet */
void func_80078EC8_79AC8(void);
void func_80078FF8_79BF8(void);
void func_80053F54_54B54(void);
void func_80053F7C_54B7C(void);
Process* MBDCameraZoomMotStart(f32 arg0);
void omPrcSetStatBit(Process* process, s32 value);
void func_80067C18_68818(void);
void func_8006784C_6844C(void);

extern u16 ContDStk[4];
extern u16 ContDStkTrg[4];

f32 MBCameraSpeedGet(void);
void MBCameraSpeedSet(f32);
s16 func_80062CCC_638CC(void);
s32 func_80046D2C_4792C(s32);
void func_80046E94_47A94(s32);
void func_800794F0_7A0F0(s8);
unk_Struct02* func_800673A0_67FA0(void);
void func_800674D8_680D8(unk_Struct02* icons, u16 mask);
s32 func_8004CC7C_4D87C(s32, s32, s32);
u16 func_800536E4_542E4(Vec2fxy* arg0); /* MP3 MBCameraPos2DSet */
void func_80061518_62118(void);
void func_8008D23C_8DE3C(void);
void MBHelpWinKill(s32);
void func_800674BC_680BC(unk_Struct02* icons);
void func_800517C0_523C0(void);
void func_80051788_52388(void);
f32 func_80053614_54214(void);
void func_80053608_54208(f32);
void func_800514F0_520F0(void);
void func_80052E68_53A68(f32); /* MP3 MBCameraZoomSet */
void func_8004655C_4715C(s32);
void func_80046EFC_47AFC(s32);
void func_80067804_68404(void);
void func_80067820_68420(void);

extern s32 D_80100028_100C28;
extern s16 D_800FA198_FAD98;
extern void* D_800E2020_E2C20[4];
extern void* D_800CC1F0_CCDF0; /* MP1/MP3 Object* */
extern f32 D_800E2030_E2C30;
extern Vec2fxy D_800E2034_E2C34;
extern Vec2s D_800CCE08_CDA08[4];
extern f32 D_800CCE18_CDA18[4];
extern s32 D_800CCEE8_CDAE8[][6]; /* map-view model files per board and character */
extern s32 D_800CCE28_CDA28[][6];
extern f32 D_800CCDF0_CD9F0[];    /* per character */
void MBModelDispOff(void*);
MBModel* MBModelFileCreate(s32 arg0, s32 arg1, f32 arg2, f32 arg3, u32* arg4);
void HuVecCopyXYZ(Vec*, f32, f32, f32);
void func_80063C40_64840(s32, s32);
u16 MBDCameraPos3DSet(Vec*);


unk_Struct02* func_800673A0_67FA0(void) {
    unk_Struct02* icons = func_8005E688_5F288(4, 0);
    void* data = DataRead(0xA00B3);
    s32 i;

    for (i = 0; i < 4; i++) {
        icons->unk0C[i] = SprAnimRead(data);
        SprAnimSet(icons->unk0A, i, icons->unk0C[i], 0);
        SprPrioSet(icons->unk0A, i, 0);
        SprAttrSet(icons->unk0A, i, 0x8009800);
        SprPosSet(icons->unk0A, i, D_800CCE08_CDA08[i].x, D_800CCE08_CDA08[i].y);
        SprRotSet(icons->unk0A, i, D_800CCE18_CDA18[i]);
    }
    DataClose(data);
    return icons;
}

void func_800674BC_680BC(unk_Struct02* icons) {
    HuMemDirectFree(icons);
}

void func_800674D8_680D8(unk_Struct02* icons, u16 mask) {
    s32 i;

    i = 0;
    do {
        if ((mask >> i) & 1) {
            SprAttrSet(icons->unk0A, i, 0x8000);
            i++;
        } else {
            SprAttrReset(icons->unk0A, i, 0x8000);
            i++;
        }
    } while (i < 4);
}

/* Swap every player's board model for a map-view model (1.2x) and hide the item model. */
void func_80067558_68158(void) {
    GW_PLAYER* player;
    void* temp_a0;
    s32 i;

    for (i = 0; i < 4; i++) {
        player = BoardPlayerGet(i);
        MBModelDispOff(player->unk_24);
        if (gPlayers[i].turn_status != 0) {
            D_800E2020_E2C20[i] = MBModelFileCreate(D_800CCEE8_CDAE8[GwSystem.current_board_index][player->character], 0xD, 1.0f, D_800CCDF0_CD9F0[player->character], NULL);
        } else {
            D_800E2020_E2C20[i] = MBModelFileCreate(D_800CCE28_CDA28[GwSystem.current_board_index][player->character], 0xD, 1.0f, D_800CCDF0_CD9F0[player->character], NULL);
        }
        HuVecCopyXYZ(&((MBModel*)D_800E2020_E2C20[i])->scale, 1.2f, 1.2f, 1.2f);
    }
    if (D_800CC1F0_CCDF0 != NULL) {
        MBModelDispOff(D_800CC1F0_CCDF0);
    }
    for (i = 0; i < 4; i++) {
        player = BoardPlayerGet(i);
        temp_a0 = player->unk_24;
        player->unk_24 = D_800E2020_E2C20[i];
        D_800E2020_E2C20[i] = temp_a0;
    }
    for (i = 0; i < 4; i++) {
        func_80063C40_64840(i, 1);
    }
}

void func_80067720_68320(void) {
    GW_PLAYER* player;
    void* temp_a0;
    s32 i;

    for (i = 0; i < 4; i++) {
        player = BoardPlayerGet(i);
        temp_a0 = player->unk_24;
        player->unk_24 = D_800E2020_E2C20[i];
        D_800E2020_E2C20[i] = temp_a0;
    }

    for (i = 0; i < 4; i++) {
        player = BoardPlayerGet(i);
        if (gPlayers[i].turn_status == 0) {
            MBModelDispOn(player->unk_24);
        }
        MBModelKill(D_800E2020_E2C20[i]);
    }

    if (D_800CC1F0_CCDF0 != NULL) {
        MBModelDispOn(D_800CC1F0_CCDF0);
    }
}

void func_80067804_68404(void) {
    func_80067558_68158();
}

void func_80067820_68420(void) {
    func_80067720_68320();
    func_8005390C_5450C(0xFF);
    func_80061584_62184();
}

/* MP3 ovl_81 func_801008E8_E86B8_name_81: scroll the board map with the D-pad */
void func_8006784C_6844C(void) {
    Vec2fxy sp10;
    f32 temp_f20;
    f32 temp_f22;
    unk_Struct02* temp_s3;
    s32 temp_s2;
    s32 temp_s6;
    s16 var_s1;
    s32 var_s4;
    s32 var_s7;
    s16 sixteen;

    var_s4 = 0;

    do {
        temp_s2 = (s32)HuPrcCurrentGet()->user_data;
        var_s7 = 0;
        var_s1 = 0;
        temp_f22 = MBCameraSpeedGet();
        if (func_80062CCC_638CC() == 0) {
            InitFadeOut(6, 8);
            HuPrcSleep(8);
            var_s7 = func_80046D2C_4792C(GwSystem.current_player_index);
            func_80046E94_47A94(GwSystem.current_player_index);
            func_800794F0_7A0F0(0x60);
        }
        func_80067804_68404();
        InitFadeIn(6, 8);
        HuPrcSleep(7);
        temp_s3 = func_800673A0_67FA0();
        temp_s6 = func_8004CC7C_4D87C(4, 0xA0, 0);
        if (D_80100028_100C28 != 0) {
            var_s4 = func_8004CC7C_4D87C(6, 0x3C, 0);
        }
        MBCameraSpeedSet(3.5f);

        do {
            sixteen = 16;
            HuPrcVSleep();
            func_800537A0_543A0(&sp10);
            func_800674D8_680D8(temp_s3, func_800536E4_542E4(&sp10));

            if (ContDStk[temp_s2] & 0x200) {
                sp10.x -= sixteen;
                var_s1 = 0xF;
            }
            if (ContDStk[temp_s2] & 0x100) {
                sp10.x += sixteen;
                var_s1 = 0xF;
            }
            if (ContDStk[temp_s2] & 0x800) {
                sp10.y -= sixteen;
                var_s1 = 0xF;
            }
            if (ContDStk[temp_s2] & 0x400) {
                sp10.y += sixteen;
                var_s1 = 0xF;
            }

            func_800536E4_542E4(&sp10);

            if (var_s1 != 0) {
                var_s1 -= 1;
                func_80061518_62118();
            } else {
                func_80061584_62184();
            }

            if (gPlayers[GwSystem.current_player_index].flags & 1) {
                func_8008D23C_8DE3C();
                goto label;
            }
        } while (D_800FA198_FAD98 != 0 && !(ContDStkTrg[temp_s2] & 0xE010));

        while (1) {
        label:
            MBHelpWinKill(temp_s6);
            if (var_s4 != 0) {
                MBHelpWinKill(var_s4);
            }
            func_800674BC_680BC(temp_s3);
            InitFadeOut(6, 8);
            HuPrcSleep(8);
            if (func_80062CCC_638CC() == 0) {
                func_800517C0_523C0();
                func_80051788_52388();
                MBCameraSpeedSet(-1.0f);
                temp_f20 = func_80053614_54214();
                func_80053608_54208(1.0f);
                func_800514F0_520F0();
                func_80052E68_53A68(D_800E2030_E2C30);
                func_800536E4_542E4(&D_800E2034_E2C34);
                HuPrcVSleep();
                func_80053608_54208(temp_f20);
                if (var_s7 != 0) {
                    func_8004655C_4715C(GwSystem.current_player_index);
                }
                func_80046EFC_47AFC(GwSystem.current_player_index);
                func_80067820_68420();
                func_800794F0_7A0F0(0x7F);
                InitFadeIn(6, 8);
                HuPrcSleep(7);
                MBCameraSpeedSet(temp_f22);
                omDelPrcObj(0);
                return;
            } else {
                break;
            }
        }
        func_80067820_68420();
        MBCameraSpeedSet(temp_f22);
        omDelPrcObj(0);
    } while (0);
}

/* Keeps the camera on the current player's model (map scroll helper process). */
void func_80067C18_68818(void) {
    while (TRUE) {
        MBDCameraPos3DSet(&((MBModel*)gPlayers[GwSystem.current_player_index].unk_24)->pos);
        HuPrcVSleep();
    }
}

/* MP3 MBMapScrollExec */
void func_80067C6C_6886C(s32 arg0) {
    Process* temp_s0;
    Process* temp_v0;

    D_800E2030_E2C30 = func_80052E5C_53A5C();
    func_800537A0_543A0(&D_800E2034_E2C34);
    D_800F851A_F911A = 1;
    func_80078EC8_79AC8();
    temp_v0 = omAddPrcObj(func_80067C18_68818, 0x1005, 0, 0);
    omPrcSetStatBit(temp_v0, 0x20);
    HuPrcChildLink(HuPrcCurrentGet(), MBDCameraZoomMotStart(1.0f));
    HuPrcChildWatch();
    omDelPrcObj(temp_v0);
    func_80053F7C_54B7C();
    temp_s0 = HuPrcCurrentGet();
    temp_v0 = omAddPrcObj(func_8006784C_6844C, 0x1005, 0, 0);
    temp_v0->user_data = (void*)arg0;
    omPrcSetStatBit(temp_v0, 0x80);
    HuPrcChildLink(temp_s0, temp_v0);
    HuPrcChildWatch();
    func_80078FF8_79BF8();
    D_800F851A_F911A = 0;
    func_80053F54_54B54();
}
