#include "common.h"
#include "game/malloc.h"
#include "game/data.h"
#include "game/board.h"

/* Board map markers: MP3 ovl_80_shared_board/EB2F0.c (the marker table) and MP1 src/3CED0.c (the
   map's player-position lines and their blink). func_8004232C (the map view, near MP1
   func_8003CAB4) stays asm. */

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

extern s16 D_800CB10C_CBD0C[4];
extern s16 D_800CB114_CBD14[4];
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
void SprPrioSet(s16, s16, s16);
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

INCLUDE_ASM("asm/nonmatchings/426A0", func_8004232C_42F2C);

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
