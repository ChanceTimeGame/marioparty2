#include "common.h"
#include "game/malloc.h"
#include "game/data.h"
#include "game/board.h"

/* Board map markers: MP3 ovl_80_shared_board/EB2F0.c (the marker table) and MP1 src/3CED0.c (the
   map's player-position lines and their blink). func_8004232C is the map view (near MP1
   func_8003CAB4). */

typedef struct UnkBoard6 {
    /* 0x00 */ s8 unk_00;
    /* 0x04 */ void* unk4;
    /* 0x08 */ Process* process;
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s16 unkE;
    /* 0x10 */ Vec unk10;
} UnkBoard6; /* size = 0x1C */

typedef struct MapMarkerBlink {
    /* 0x00 */ s16 sprite;
    /* 0x02 */ s16 idx;
} MapMarkerBlink;

/* .data (0xCBCB0-0xCBD60) */
s32 D_800CB0B0_CBCB0[6] = { 0x000A00B5, 0x000A00B6, 0x000A00B7, 0x000A00B8, 0x000A00B9, 0x000A00BA };
s32 D_800CB0C8_CBCC8[9] = { /* unreferenced */
    0x000A00B2, 0x000A00AC, 0x000A00AF, 0x000A00B0, 0x000A00B1, 0x000A00AD, 0x000A00CE, 0x000A00CF, 0x000A00D0,
};
s16 D_800CB0EC_CBCEC[4][4] = { { 0, 2, 0, 1 }, { 0, 2, -1, 0 }, { -2, 0, 0, 1 }, { -2, 0, -1, 0 } };
s16 D_800CB10C_CBD0C[4] = { 0x42, 0xFC, 0x42, 0xFC };
s16 D_800CB114_CBD14[4] = { 0x1E, 0x1E, 0xD2, 0xD2 };
s32 D_800CB11C_CBD1C[6] = { 0x000A00B5, 0x000A00B6, 0x000A00B7, 0x000A00B8, 0x000A00B9, 0x000A00BA };
s32 D_800CB134_CBD34[7] = { 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0 };
u8 D_800CB150 = 0; /* overlay 4E's flag (the map gives 0xCBD50-0xCBD60 to 426A0; 437E0 could own it) */

extern s32 D_800DEFF0_DFBF0;
extern s16 D_800DEFF4_DFBF4;
extern UnkBoard6 D_800DEFF8_DFBF8[32];
extern s16 D_800DF378_DFF78[4];
extern s16 D_800DF380_DFF80[4];
extern unk_Struct02* D_800DF388_DFF88[4];
extern s16 D_800DF398_DFF98;

void omPrcSetStatBit(Process*, s32);
s16 SprAnimRead(void*);
void SprAnimSet(s16, s16, s16, s16);
void SprAttrSet(s16, s16, s32);
void SprAttrReset(s16, s16, s32);
void SprPrioSet(s16, s16, u16);
void SprPosSet(s16, s16, s16, s16);
void SprScaleSet(s16, s16, f32, f32);
void SprRotSet(s16, s16, f32);
void func_800824B4_830B4(s16, s16, u8, u8, u8, u8);
unk_Struct02* func_8005E688_5F288(s32, s32);
void HuMemDirectFree(unk_Struct02*);
void func_80078EC8_79AC8(void);
void func_80078FF8_79BF8(void);
f32 func_80042BE0_437E0(Vec*);
f32 func_800B1830_B2430(f32);
f32 HuMathSin(f32);
void func_800B3170_B3D70(Vec*, Vec*);
void func_8004232C_42F2C(void);

extern s32 D_801027B8_1033B8;
extern s8 D_800FDC9C_FE89C;
extern u16 D_80101330_101F30;
extern s16 D_800F8D12_F9912;
extern u16 ContDStkTrg[4];
extern u16 ContBtnTrg[4];

s32 PlayerIsCPU(s16);
GW_PLAYER* BoardPlayerGet(s32);
s16 GetAbsSpaceIndexFromChainSpaceIndex(u16, u16);
SpaceData* GetSpaceData(s16);
void MBDCamera3Dto2D(Vec*, Vec2f*);
void ChangeSpaceTextures(s16);
void MBDBackKill(void);
void func_80050E00_51A00(s32);
f32 func_80052E5C_53A5C(void);
void func_80052E68_53A68(f32);
void func_800537A0_543A0(Vec2f*);
void func_800536E4_542E4(Vec2f*);
void InitFadeOut(s32, s32);
void InitFadeIn(s32, s32);
void func_80061518_62118(void);
void func_80061584_62184(void);
void func_80046E94_47A94(s32);
void func_80046EFC_47AFC(s32);
void func_80046D2C_4792C(s32);
void func_8004655C_4715C(s32);
void func_800794F0_7A0F0(s32);
s32 func_8004CC7C_4D87C(s32, s32, s32);
void MBHelpWinKill(s32);

/* exact c: marioparty3 func_800D76D0_EB2F0_shared_board (src/overlays/ovl_80_shared_board/EB2F0.c) */
void func_80041AA0_426A0(s32 arg0) {
    s32 i;

    D_800DEFF0_DFBF0 = arg0;
    for (i = 0; i < ARRAY_COUNT(D_800DEFF8_DFBF8); i++) {
        D_800DEFF8_DFBF8[i].unk_00 = -1;
    }

    D_800DEFF4_DFBF4 = 0;
}

void func_80041AE4_426E4(void) {
}

/* exact c: marioparty3 func_800D771C_EB33C_shared_board (src/overlays/ovl_80_shared_board/EB2F0.c) */
s32 func_80041AEC_426EC(s8 arg0, void* arg1, s16 arg2, s16 arg3) {
    UnkBoard6* temp_v0;

    temp_v0 = &D_800DEFF8_DFBF8[D_800DEFF4_DFBF4++];
    temp_v0->unk_00 = arg0;
    temp_v0->unk4 = arg1;
    temp_v0->unkC = arg2;
    temp_v0->unkE = arg3;
    return D_800DEFF4_DFBF4 - 1;
}

/* exact c: marioparty3 func_800D7770_EB390_shared_board (src/overlays/ovl_80_shared_board/EB2F0.c) */
void func_80041B40_42740(s32 arg0) {
    D_800DEFF8_DFBF8[arg0].unk_00 = -1;
}

/* exact c: marioparty3 func_800D7790_EB3B0_shared_board (src/overlays/ovl_80_shared_board/EB2F0.c) */
void func_80041B60_42760(s8 arg0, Vec* arg1, s16 arg2, s16 arg3) {
    UnkBoard6* temp_v1;

    temp_v1 = &D_800DEFF8_DFBF8[D_800DEFF4_DFBF4++];
    temp_v1->unk_00 = arg0;
    temp_v1->unk4 = 0;
    temp_v1->unkC = arg2;
    temp_v1->unkE = arg3;
    func_800B3170_B3D70(&temp_v1->unk10, arg1);
}

/* exact c: marioparty3 MBMapFullStarGlowKill (src/overlays/ovl_80_shared_board/EB2F0.c) */
void func_80041BC0_427C0(void) {
    UnkBoard6 *entry;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_800DEFF8_DFBF8); i++) {
        entry = &D_800DEFF8_DFBF8[i];
        if (entry->unk_00 >= 0) {
            if (entry->process != NULL) {
                omDelPrcObj(entry->process);
            }
            entry->process = NULL;
        }
    }
}

/* exact c: marioparty func_8003C3C4 (src/3CED0.c) */
void func_80041C3C_4283C(void) {
    f32 v;
    f32 t1;
    f32 t2;
    MapMarkerBlink* d;
    s32 c;

    d = HuPrcCurrentGet()->user_data;
    t1 = 0.0f;
    t2 = 0.0f;
    while (TRUE) {
        v = HuMathSin(t2);
        v = (v < 0.0f) ? -v : v;
        c = v * 255.0f;
        t2 += 6.0f;
        if (t2 > 360.0f) {
            t2 -= 360.0f;
        }
        func_800824B4_830B4(d->sprite, d->idx, 0xFF, c, 0, 0xC0);
        v = HuMathSin(t1);
        v = (v < 0.0f) ? 0.0f : 0.2f;
        t1 += 15.0f;
        if (t1 > 360.0f) {
            t1 -= 360.0f;
        }
        SprScaleSet(d->sprite, d->idx, v + 1.0f, v + 1.0f);
        HuPrcVSleep();
    }
}

/* exact c: marioparty func_8003C528 (src/3CED0.c) */
Process* func_80041DA0_429A0(s16 sprite, s16 idx) {
    Process* p = omAddPrcObj(func_80041C3C_4283C, 0x1005, 0, 0x40);
    MapMarkerBlink* d = HuMemMemoryAlloc(p->heap, sizeof(MapMarkerBlink));

    p->user_data = d;
    d->sprite = sprite;
    d->idx = idx;
    return p;
}

/* exact c: marioparty func_8003C594 (src/3CED0.c) */
void func_80041E0C_42A0C(unk_Struct02* arg0, s16 i) {
    Vec v;
    f32 angle;

    SprPosSet(arg0->unk0A, 0, D_800CB10C_CBD0C[i], D_800CB114_CBD14[i]);
    SprPosSet(arg0->unk0A, 1, D_800CB10C_CBD0C[i], D_800CB114_CBD14[i]);
    v.x = D_800DF378_DFF78[i] - D_800CB10C_CBD0C[i];
    v.y = 0.0f;
    v.z = D_800DF380_DFF80[i] - D_800CB114_CBD14[i];
    angle = func_80042BE0_437E0(&v);
    SprScaleSet(arg0->unk0A, 0, 0.25f, func_800B1830_B2430(v.x * v.x + v.z * v.z) / 32.0f);
    SprRotSet(arg0->unk0A, 0, angle);
}

/* same c: marioparty func_8003C6C4 (src/3CED0.c) */
void func_80041F3C_42B3C(void) {
    unk_Struct02* s;
    s32 i;
    void* data;
    void* data2;

    for (i = 0; i < 4; i++) {
        s = func_8005E688_5F288(2, 0);
        data = DataRead(0xA00B4);
        s->unk0C[0] = SprAnimRead(data);
        SprAnimSet(s->unk0A, 0, s->unk0C[0], 0);
        SprAttrSet(s->unk0A, 0, 0x01001808);
        SprPrioSet(s->unk0A, 0, 2);
        func_800824B4_830B4(s->unk0A, 0, 0, 0, 0xFF, 0x80);
        DataClose(data);
        data2 = DataRead(0xA0018);
        s->unk0C[1] = SprAnimRead(data2);
        SprAnimSet(s->unk0A, 1, s->unk0C[1], 0);
        SprAttrSet(s->unk0A, 1, 0x01001808);
        SprPrioSet(s->unk0A, 1, 2);
        func_800824B4_830B4(s->unk0A, 1, 0, 0, 0xFF, 0x80);
        DataClose(data2);
        func_80041E0C_42A0C(s, i);
        D_800DF388_DFF88[i] = s;
    }
}

/* exact c: marioparty func_8003C858 (src/3CED0.c) */
void func_800420D0_42CD0(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        HuMemDirectFree(D_800DF388_DFF88[i]);
    }
}

/* exact c: marioparty func_8003C8A8 (src/3CED0.c) */
void func_80042120_42D20(void) {
    unk_Struct02* s;
    s16 cur;
    s32 i;
    s16 c;
    f32 t;

    cur = -1;
    t = 90.0f;
    while (TRUE) {
        // fake branch: fixes register allocation (MP3 MBMapFullLineFlash needs one too)
        if (cur) {
            HuPrcVSleep();
        } else {
            HuPrcVSleep();
        }
        if (cur != D_800DF398_DFF98) {
            cur = D_800DF398_DFF98;
            for (i = 0; i < 4; i++) {
                s = D_800DF388_DFF88[i];
                if (i == cur) {
                    SprPrioSet(s->unk0A, 0, 2);
                    SprPrioSet(s->unk0A, 1, 2);
                } else {
                    func_800824B4_830B4(s->unk0A, 0, 0, 0, 0xFF, 0xA0);
                    func_800824B4_830B4(s->unk0A, 1, 0, 0, 0xFF, 0xFF);
                    SprPrioSet(s->unk0A, 0, 3);
                    SprPrioSet(s->unk0A, 1, 3);
                }
                SprAttrReset(s->unk0A, 0, 0x8000);
                SprAttrReset(s->unk0A, 1, 0x8000);
            }
        }
        s = D_800DF388_DFF88[cur];
        c = HuMathSin(t) * 255.0f;
        c = (c < 0) ? -c : c;
        t += 6.0f;
        if (t > 360.0f) {
            t -= 360.0f;
        }
        func_800824B4_830B4(s->unk0A, 0, 0xFF, c, 0, 0xA0);
        func_800824B4_830B4(s->unk0A, 1, 0xFF, c, 0, 0xFF);
    }
}

/* near MP1 func_8003CAB4 (src/3CED0.c): the map view. MP2 keeps the camera zoom, uses 32 markers
   (type 11 swaps art when D_800F8D12 is set), a second label pair on board 6 and restores the
   space textures on exit. */
void func_8004232C_42F2C(void) {
    Vec2f cam;
    Vec2f pos;
    s32 port;
    s32 bg;
    s16 sel;
    f32 zoom;
    Process* proc;
    s32 i;
    s32 j;
    GW_PLAYER* player;
    UnkBoard6* m;
    void* data;
    unk_Struct02* markers;
    unk_Struct02* icons;
    s16 x;
    s16 y;
    s32 label1;
    s32 label2;
    s16 dir;
    u16 pad;

    port = (s32)HuPrcCurrentGet()->user_data;
    bg = D_801027B8_1033B8;
    sel = 0;
    for (i = 0; i < 4; i++) {
        if (PlayerIsCPU(i) != 0) {
            continue;
        }
        if (gPlayers[i].port == port) {
            sel = i;
            break;
        }
    }
    D_800DF398_DFF98 = sel;
    zoom = func_80052E5C_53A5C();
    func_800537A0_543A0(&cam);
    InitFadeOut(6, 8);
    HuPrcSleep(8);
    func_80061518_62118();
    func_80046E94_47A94(port);
    HuPrcVSleep();
    D_800FDC9C_FE89C = 1;
    D_80101330_101F30 &= ~1;
    func_80046D2C_4792C(GwSystem.current_player_index);
    func_80046E94_47A94(GwSystem.current_player_index);
    if (D_800F8D12_F9912 != 0) {
        ChangeSpaceTextures(4);
    } else {
        ChangeSpaceTextures(1);
    }
    MBDBackKill();
    func_80050E00_51A00(D_800DEFF0_DFBF0);
    markers = func_8005E688_5F288(32, 0);
    for (i = 0; i < 4; i++) {
        player = BoardPlayerGet(i);
        MBDCamera3Dto2D(&GetSpaceData(GetAbsSpaceIndexFromChainSpaceIndex(player->cur_chain_index, player->cur_space_index))->coords, &pos);
        D_800DF378_DFF78[i] = pos.unk_00;
        D_800DF380_DFF80[i] = pos.unk_04;
    }
    for (i = 0, j = 0; j < 32; i++, j++) {
        m = &D_800DEFF8_DFBF8[j];
        if (m->unk_00 < 0) {
            continue;
        }
        if (D_800F8D12_F9912 != 0 && m->unk_00 == 11) {
            data = DataRead(D_800CB0B0_CBCB0[6]);
        } else {
            data = DataRead(D_800CB0B0_CBCB0[m->unk_00]);
        }
        markers->unk0C[i] = SprAnimRead(data);
        SprAnimSet(markers->unk0A, i, markers->unk0C[i], 0);
        SprAttrSet(markers->unk0A, i, 0x01001000);
        MBDCamera3Dto2D((m->unk4 != NULL) ? &((MBModel*)m->unk4)->pos : &m->unk10, &pos);
        x = (s32)pos.unk_00 + m->unkC;
        y = (s32)pos.unk_04 + m->unkE;
        SprPosSet(markers->unk0A, i, x, y);
        SprPrioSet(markers->unk0A, i, ~y);
        DataClose(data);
        if (m->unk_00 == 6 || (m->unk_00 == 11 && D_800F8D12_F9912 != 0)) {
            i++;
            data = DataRead(0xA00CD);
            markers->unk0C[i] = SprAnimRead(data);
            SprAnimSet(markers->unk0A, i, markers->unk0C[i], 0);
            SprAttrSet(markers->unk0A, i, 0x01001808);
            SprPosSet(markers->unk0A, i, x, y - 1);
            SprPrioSet(markers->unk0A, i, 0xFFFF);
            DataClose(data);
            m->process = func_80041DA0_429A0(markers->unk0A, i);
        }
    }
    func_80041F3C_42B3C();
    proc = omAddPrcObj(func_80042120_42D20, 0x1005, 0, 0);
    icons = func_8005E688_5F288(8, 0);
    for (i = 0; i < 4; i++) {
        player = BoardPlayerGet(i);
        data = DataRead(D_800CB11C_CBD1C[player->character]);
        icons->unk0C[i] = SprAnimRead(data);
        SprAnimSet(icons->unk0A, i, icons->unk0C[i], 0);
        SprPrioSet(icons->unk0A, i, 1);
        SprAttrSet(icons->unk0A, i, 0x01001000);
        SprPosSet(icons->unk0A, i, D_800CB10C_CBD0C[i] - 30, D_800CB114_CBD14[i]);
        DataClose(data);
        data = DataRead(D_800CB134_CBD34[player->character]);
        icons->unk0C[i + 4] = SprAnimRead(data);
        SprAnimSet(icons->unk0A, i + 4, icons->unk0C[i + 4], 0);
        SprPrioSet(icons->unk0A, i + 4, 1);
        SprAttrSet(icons->unk0A, i + 4, 0x01001000);
        SprPosSet(icons->unk0A, i + 4, D_800CB10C_CBD0C[i] + 8, D_800CB114_CBD14[i]);
        DataClose(data);
    }
    func_800794F0_7A0F0(0x60);
    InitFadeIn(6, 8);
    HuPrcSleep(7);
    if (GwSystem.current_board_index == 6) {
        label1 = func_8004CC7C_4D87C(0, 0xBC, 0);
        label2 = func_8004CC7C_4D87C(4, 0xCA, 0);
    } else {
        label1 = func_8004CC7C_4D87C(0, 0x14, 0);
        label2 = func_8004CC7C_4D87C(4, 0x22, 0);
    }
    do {
        HuPrcVSleep();
        pad = ContDStkTrg[port];
        dir = -((pad & 0x800) == 0);
        if (pad & 0x400) {
            dir = 1;
        }
        if (ContDStkTrg[port] & 0x200) {
            dir = 2;
        }
        if (ContDStkTrg[port] & 0x100) {
            dir = 3;
        }
        if (dir != -1) {
            sel += D_800CB0EC_CBCEC[sel][dir];
        }
        D_800DF398_DFF98 = sel;
    } while (!(ContBtnTrg[port] & 0xE010));
    InitFadeOut(6, 8);
    HuPrcSleep(8);
    D_800FDC9C_FE89C = 0;
    MBDBackKill();
    func_80050E00_51A00(bg);
    func_80052E68_53A68(zoom);
    func_800536E4_542E4(&cam);
    HuPrcVSleep();
    D_80101330_101F30 |= 1;
    func_8004655C_4715C(GwSystem.current_player_index);
    func_80046EFC_47AFC(GwSystem.current_player_index);
    MBHelpWinKill(label1);
    MBHelpWinKill(label2);
    omDelPrcObj(proc);
    HuMemDirectFree(icons);
    HuMemDirectFree(markers);
    func_800420D0_42CD0();
    func_80041BC0_427C0();
    func_80046EFC_47AFC(port);
    func_80061584_62184();
    if (D_800F8D12_F9912 != 0) {
        ChangeSpaceTextures(3);
    } else {
        ChangeSpaceTextures(0);
    }
    func_800794F0_7A0F0(0x7F);
    InitFadeIn(6, 8);
    HuPrcSleep(8);
    omDelPrcObj(NULL);
}

/* exact c: marioparty func_8003D20C (src/3CED0.c) */
void func_80042B38_43738(void* arg0) {
    Process* cur;
    Process* p;

    D_800F851A_F911A = 1;
    func_80078EC8_79AC8();
    cur = HuPrcCurrentGet();
    p = omAddPrcObj(func_8004232C_42F2C, 0x1005, 0, 0);
    p->user_data = arg0;
    omPrcSetStatBit(p, 0x80);
    HuPrcChildLink(cur, p);
    HuPrcChildWatch();
    func_80078FF8_79BF8();
    D_800F851A_F911A = 0;
}
