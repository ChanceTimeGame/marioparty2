#include "common.h"
#include "game/board.h"

/* Board message windows. C from MP3 ovl_80_shared_board FFB10.c (MBWin and MBDlg functions) and MP1
   ovl_3E_FirstMap 257020.c; the two without a reference stay asm. */

void func_80055A38_56638(s16, s32);
void func_800890CC_89CCC(s16, s32, s32, s32);
void func_80089308_89F08(s16, s32, s32);
void func_8008BB18_8C718(s16, s16);
void func_8008D974_8E574(s32, s16);
void func_8008DACC_8E6CC(s32, char*, s32);
void func_8008E978_8F578(s16);
extern s16 D_800CC590_CD190;
extern s16 mbDlgWinId;
extern s16 mbWinId;
extern s16 D_800CC592_CD192;

void func_800559E0_565E0(s16);
void func_80089284_89E84(s16, s32, s32);
void func_8008CCA8_8D8A8(s16);
s32 func_8008E73C_8F33C(s16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u16 arg5);
void func_8008EED8_8FAD8(s16, s16);
void MBDlgWinInsertCreateY(s16 arg0, u32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s16 arg7);

typedef struct MbTextWindow {
    /* 0x000 */ u8 unk_00[0x20];
    /* 0x020 */ u8 unk_20;
    /* 0x021 */ u8 unk_21[0x27C - 0x21];
} MbTextWindow; /* size 0x27C; the full type is TextWindow in 84FF0.c */

extern MbTextWindow* D_800F920C_F9E0C;
void func_80057730_58330(s16, s32);
void func_8005774C_5834C(s16, s32);
void func_80057DA4_589A4(s16);
void func_80057DC0_589C0(s16);
void HuPrcVSleep(void);

void func_800559E0_565E0(s16 arg0) {
    if ((GwSystem.current_player_index == 4) || (D_800CC592_CD192 != 0)) {
        func_80057DA4_589A4(arg0);
        return;
    }
    func_80057730_58330(arg0, GwSystem.current_player_index);
}

void func_80055A38_56638(s16 arg0, s32 arg1) {
    if ((GwSystem.current_player_index == 4) || (D_800CC592_CD192 != 0)) {
        func_80057DC0_589C0(arg0);
        return;
    }
    func_8005774C_5834C(arg0, arg1);
}

s16 MBWinCreate(s16 arg0, s16 *arg1, s16 arg2) {
    s32 result;

    if (arg2 == -1) {
        if (arg0 == arg2) {
            result = func_8008E73C_8F33C(-1, 0, 0, arg1[0], arg1[1], 2);
        } else {
            result = func_8008E73C_8F33C(arg0, 0, 0, arg1[0], arg1[1], 2);
        }
    } else {
        if (arg0 == -1) {
            result = func_8008E73C_8F33C(-1, 0xA0 - arg1[0] / 2, arg2, arg1[0], arg1[1], 0);
        } else {
            result = func_8008E73C_8F33C(arg0, 0xA0 - arg1[0] / 2, arg2, arg1[0], arg1[1], 0);
        }
    }

    if (D_800F851A_F911A == 0) {
        func_80089284_89E84(result, 0x40, 0x40);
    }

    return result;
}

void MBWinOpen(s32 arg0) {
    s16 sp18[2];
    s16 temp_v0;

    func_8008DACC_8E6CC(1, sp18, arg0);
    temp_v0 = func_8008E73C_8F33C(-1, 0, 0, sp18[0], sp18[1], 2);
    mbWinId = temp_v0;

    if (D_800F851A_F911A == 0) {
        func_80089284_89E84(temp_v0, 0x40, 0x40);
    }

    func_800890CC_89CCC(temp_v0, arg0, -1, -1);
    func_8008E978_8F578(temp_v0);
}

void MBWinInsertOpen(s32 arg0, char *arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5) {
    s16 sp18[2];
    s16 temp_v0;

    // if arg isn't a pointer, treat as ID and return pointer to message from dynamic memory
    if (arg1 != NULL) {
        func_8008D974_8E574((u32)arg1, 0);
    }
    if (arg2 != NULL) {
        func_8008D974_8E574((u32)arg2, 1);
    }
    if (arg3 != NULL) {
        func_8008D974_8E574((u32)arg3, 2);
    }
    if (arg4 != NULL) {
        func_8008D974_8E574((u32)arg4, 3);
    }
    if (arg5 != NULL) {
        func_8008D974_8E574((u32)arg5, 4);
    }

    func_8008DACC_8E6CC(1, sp18, arg0);
    temp_v0 = func_8008E73C_8F33C(-1, 0, 0, sp18[0], sp18[1], 2);
    mbWinId = temp_v0;

    if (D_800F851A_F911A == 0) {
        func_80089284_89E84(temp_v0, 0x40, 0x40);
    }
    if (arg1 != NULL) {
        func_80089308_89F08(temp_v0, (u32)arg1, 0);
    }
    if (arg2 != 0) {
        func_80089308_89F08(temp_v0, (u32)arg2, 1);
    }
    if (arg3 != 0) {
        func_80089308_89F08(temp_v0, (u32)arg3, 2);
    }
    if (arg4 != 0) {
        func_80089308_89F08(temp_v0, (u32)arg4, 3);
    }
    if (arg5 != 0) {
        func_80089308_89F08(temp_v0, (u32)arg5, 4);
    }
    func_800890CC_89CCC(temp_v0, arg0, -1, -1);
    func_8008E978_8F578(temp_v0);
}

void func_80055E3C_56A3C(s32 arg0) {
    func_80055A38_56638(mbWinId, arg0);
}

void func_80055E60_56A60(void) {
    func_8008EED8_8FAD8(mbWinId, 0);
    func_8008CCA8_8D8A8(mbWinId);
}

void MBDlgResultWinExec(s32 arg0) {
    s16 sp18[2];
    s16 temp_v0;

    func_8008DACC_8E6CC(1, sp18, arg0);
    temp_v0 = func_8008E73C_8F33C(-1, 0, 0, sp18[0], sp18[1], 2);
    mbDlgWinId = temp_v0;

    if (D_800F851A_F911A == 0) {
        func_80089284_89E84(temp_v0, 0x40, 0x40);
    }

    func_800890CC_89CCC(temp_v0, arg0, -1, -1);
    func_8008E978_8F578(temp_v0);
    func_800559E0_565E0(temp_v0);
    func_8008EED8_8FAD8(temp_v0, 0);
    func_8008CCA8_8D8A8(temp_v0);
}

void MBDlgWinExecY(s16 arg0, s32 arg1, s32 arg2) {
    s16 sp10[2];
    s16 temp_v0;

    func_8008DACC_8E6CC(1, sp10, arg1);
    temp_v0 = MBWinCreate(arg0, sp10, arg2);
    mbDlgWinId = temp_v0;
    func_800890CC_89CCC(temp_v0, arg1, -1, -1);
    func_8008E978_8F578(temp_v0);
    func_800559E0_565E0(temp_v0);
    func_8008EED8_8FAD8(temp_v0, 0);
    func_8008CCA8_8D8A8(temp_v0);
}

void MBDlgWinExec(s32 arg0, s32 arg1) {
    MBDlgWinExecY(arg0, arg1, -1);
}

void func_80056030_56C30(s16 arg0, s32 arg1) {
    D_800CC592_CD192 = 1;
    MBDlgWinExecY(arg0, arg1, -1);
    D_800CC592_CD192 = 0;
}

void func_80056068_56C68(s16 arg0, s32 arg1, s16 arg2) {
    D_800CC592_CD192 = 1;
    MBDlgWinExecY(arg0, arg1, arg2);
    D_800CC592_CD192 = 0;
}

void MBDlgWinCreate(s32 arg0, s32 arg1) {
    s16 sp10[2];
    s16 temp_v0;

    func_8008DACC_8E6CC(1, sp10, arg1);
    temp_v0 = MBWinCreate(arg0, sp10, -1);
    mbDlgWinId = temp_v0;
    func_800890CC_89CCC(temp_v0, arg1, -1, -1);
    func_8008E978_8F578(temp_v0);
}

void func_80056124_56D24(void) {
    func_8008E978_8F578(mbDlgWinId);
}

void MBDlgWinClose(void) {
    func_8008EED8_8FAD8(mbDlgWinId, 0);
}

void func_80056168_56D68(void) {
    func_8008CCA8_8D8A8(mbDlgWinId);
}

void MBDlgWinInsertCreateY(s16 arg0, u32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s16 arg7) {
    char sp10[8];
    s16 temp_v0;

    if (arg2 != 0) {
        func_8008D974_8E574(arg2, 0);
    }
    if (arg3 != 0) {
        func_8008D974_8E574(arg3, 1);
    }
    if (arg4 != 0) {
        func_8008D974_8E574(arg4, 2);
    }
    if (arg5 != 0) {
        func_8008D974_8E574(arg5, 3);
    }
    if (arg6 != 0) {
        func_8008D974_8E574(arg6, 4);
    }
    func_8008DACC_8E6CC(1, sp10, arg1);
    temp_v0 = MBWinCreate(arg0, sp10, arg7);
    mbDlgWinId = temp_v0;
    if (arg2 != 0) {
        func_80089308_89F08(temp_v0, arg2, 0);
    }
    if (arg3 != 0) {
        func_80089308_89F08(temp_v0, arg3, 1);
    }
    if (arg4 != 0) {
        func_80089308_89F08(temp_v0, arg4, 2);
    }
    if (arg5 != 0) {
        func_80089308_89F08(temp_v0, arg5, 3);
    }
    if (arg6 != 0) {
        func_80089308_89F08(temp_v0, arg6, 4);
    }
    if (D_800CC590_CD190 != 0) {
        func_8008BB18_8C718(temp_v0, D_800CC590_CD190);
    }
    func_800890CC_89CCC(temp_v0, arg1, -1, -1);
    
    if (arg0 == -1) {
        func_8008E978_8F578(temp_v0);
    } else {
        func_8008E978_8F578(temp_v0);
    }
    
    func_80055A38_56638(temp_v0, GwSystem.current_player_index);
}

void func_80056368_56F68(s16 arg0, u32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    MBDlgWinInsertCreateY(arg0, arg1, arg2, arg3, arg4, arg5, arg6, -1);
}

void func_800563A8_56FA8(s16 arg0, s32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6) {
    D_800CC592_CD192 = 1;
    MBDlgWinInsertCreateY(arg0, arg1, arg2, arg3, arg4, arg5, arg6, -1);
    D_800CC592_CD192 = 0;
}

void func_800563FC_56FFC(s16 arg0, s32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6, s16 arg7) {
    D_800CC592_CD192 = 1;
    MBDlgWinInsertCreateY(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    D_800CC592_CD192 = 0;
}

void func_80056458_57058(void) {
    D_800F920C_F9E0C[mbDlgWinId].unk_20 = 1;
    HuPrcVSleep();
    func_80055A38_56638(mbDlgWinId, GwSystem.current_player_index);
}

void func_800564B4_570B4(void) {
    D_800CC592_CD192 = 1;
    D_800F920C_F9E0C[mbDlgWinId].unk_20 = 1;
    HuPrcVSleep();
    func_80055A38_56638(mbDlgWinId, GwSystem.current_player_index);
    D_800CC592_CD192 = 0;
}

INCLUDE_ASM("asm/nonmatchings/565E0", func_80056524_57124);

INCLUDE_ASM("asm/nonmatchings/565E0", func_80056530_57130);
