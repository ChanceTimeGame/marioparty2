#include "common.h"
#include "ovl_1F.h"

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80102800_1BE380_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80102CF8_1BE878_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80102D94_1BE914_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_801030CC_1BEC4C_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80103100_1BEC80_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80103134_1BECB4_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80103168_1BECE8_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_8010319C_1BED1C_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_801031D0_1BED50_DungeonDash);

__asm__(".section .rodata");
const u32 D_8010ABE0_1C6760_DungeonDash[4] = { 0x00000055, 0x00000056, 0x00000057, 0x00000000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80103354_1BEED4_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_801036B0_1BF230_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80104190_1BFD10_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_801041F0_1BFD70_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80105464_1C0FE4_DungeonDash);

__asm__(".section .rodata");
const u32 D_8010AD38_1C68B8_DungeonDash[4] = { 0 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80105618_1C1198_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80105E50_1C19D0_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_801060DC_1C1C5C_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_801060F8_1C1C78_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80106118_1C1C98_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_80106144_1C1CC4_DungeonDash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_1F_DungeonDash/1BE380", func_801061A0_1C1D20_DungeonDash);

void func_8010676C_1C22EC_DungeonDash(void) {
    DDTeam* team;
    s32 i;

    for (team = D_8010B068_1C6BE8_DungeonDash, i = 0; i < 2; i++, team++) {
        if (team->unk14 != 13) {
            func_800298A4_2A4A4(team->obj[0]->model[0], 4, 4);
            func_800298A4_2A4A4(team->obj[1]->model[0], 4, 4);
            func_800298A4_2A4A4(team->unkE, 4, 4);
            func_800298A4_2A4A4(team->unk10, 4, 4);
        }
    }
}

s32 func_80106810_1C2390_DungeonDash(s32 team) {
    DDBlock* b;
    DDTeam* t;

    b = D_8010B2E0_1C6E60_DungeonDash;
    t = &D_8010B068_1C6BE8_DungeonDash[team];
    if (t->unk18 > 0) {
        t->unk18--;
        return 0;
    }
    for (; team < 2; team += 2, b++) {
        if (fabs(b->unk1C - t->unk28) < 100.0 && fabs(b->unk10 - 90.0) < 20.0) {
            t->unk18 = 90;
            return 1;
        }
    }
    return 0;
}

void func_801068E8_1C2468_DungeonDash(void) {
    void* data;
    DDFx* fx;
    s32 i;

    data = DataRead(0x2F000D);
    D_8010B140_1C6CC0_DungeonDash = SprAnimRead(data);
    DataClose(data);
    D_8010B13C_1C6CBC_DungeonDash = func_80027154_27D54(0x168, 0x7918);
    func_800B0EF0_B1AF0(D_8010B13C_1C6CBC_DungeonDash, 0, 0x168);
    for (fx = D_8010B13C_1C6CBC_DungeonDash, i = 0; i < 10; i++, fx++) {
        fx->unk0 = fx->unk4 = fx->unk6 = 0;
        if (i == 0) {
            fx->unk2 = func_80109958_1C54D8_DungeonDash(D_8010A750_1C62D0_DungeonDash,
                                                        SprAnimGet((s16)D_8010B140_1C6CC0_DungeonDash), 3);
        } else {
            fx->unk2 = func_8010A4DC_1C605C_DungeonDash(-1, D_8010B13C_1C6CBC_DungeonDash->unk2,
                                                        SprAnimGet((s16)D_8010B140_1C6CC0_DungeonDash), 3);
        }
        func_800298A4_2A4A4(fx->unk2, 4, 4);
        fx->unk8 = 1.0f;
        fx->pos.x = fx->pos.y = fx->pos.z = 0.0f;
        fx->vel.x = fx->vel.y = fx->vel.z = 0.0f;
    }
}

void func_80106A28_1C25A8_DungeonDash(void) {
    DDFx* fx;
    s32 i;

    for (fx = D_8010B13C_1C6CBC_DungeonDash, i = 0; i < 10; i++, fx++) {
        if (i == 0) {
            func_8010A340_1C5EC0_DungeonDash(fx->unk2, SprAnimGet((s16)D_8010B140_1C6CC0_DungeonDash), fx->unk6);
        } else {
            func_8010A4DC_1C605C_DungeonDash(fx->unk2, D_8010B13C_1C6CBC_DungeonDash->unk2,
                                             SprAnimGet((s16)D_8010B140_1C6CC0_DungeonDash), fx->unk6);
        }
        if (fx->unk0 != 0) {
            fx->pos.x += fx->vel.x;
            fx->pos.y += fx->vel.y;
            fx->pos.z += fx->vel.z;
            func_80029714_2A314(fx->unk2, fx->pos.x, fx->pos.y, fx->pos.z);
            fx->unk6 += 2;
            if (fx->unk6 >= 16) {
                fx->unk4 = 0;
                fx->unk6 = 0;
            }
            if (--fx->unk4 <= 0) {
                func_800298A4_2A4A4(fx->unk2, 4, 4);
                fx->unk0 = fx->unk4 = fx->unk6 = 0;
            }
        }
    }
}

void func_80106B6C_1C26EC_DungeonDash(Vec* pos, Vec* vel, f32 scale, s16 time) {
    DDFx* fx;
    s32 i;

    for (fx = D_8010B13C_1C6CBC_DungeonDash, i = 0; i < 10; i++, fx++) {
        if (fx->unk0 == 0) {
            fx->unk0 = 1;
            fx->pos.x = pos->x;
            fx->pos.y = pos->y;
            fx->pos.z = pos->z;
            fx->vel.x = vel->x;
            fx->vel.y = vel->y;
            fx->vel.z = vel->z;
            fx->unk8 = scale;
            fx->unk4 = time;
            fx->unk6 = 0;
            func_80029714_2A314(fx->unk2, fx->pos.x, fx->pos.y, fx->pos.z);
            func_800297E8_2A3E8(fx->unk2, scale, scale, 1.0f);
            func_800298A4_2A4A4(fx->unk2, 4, 0);
            return;
        }
    }
}

void func_80106C3C_1C27BC_DungeonDash(s32 cam, f32 zoom, f32 cx, f32 cy, f32 cz, f32 rx, f32 ry, f32 rz) {
    D_8010B270_1C6DF0_DungeonDash[cam] = 0;
    D_8010B268_1C6DE8_DungeonDash[cam] = 0;
    D_800F94A8_FA0A8[cam] = zoom;
    D_801013B0_101FB0[cam].x = cx;
    D_801013B0_101FB0[cam].y = cy;
    D_801013B0_101FB0[cam].z = cz;
    D_80102770_103370[cam].x = rx;
    D_80102770_103370[cam].y = ry;
    D_80102770_103370[cam].z = rz;
    D_8010B248_1C6DC8_DungeonDash[cam] = zoom;
    D_8010B188_1C6D08_DungeonDash[cam].x = cx;
    D_8010B188_1C6D08_DungeonDash[cam].y = cy;
    D_8010B188_1C6D08_DungeonDash[cam].z = cz;
    D_8010B1E8_1C6D68_DungeonDash[cam].x = rx;
    D_8010B1E8_1C6D68_DungeonDash[cam].y = ry;
    D_8010B1E8_1C6D68_DungeonDash[cam].z = rz;
}

void func_80106D2C_1C28AC_DungeonDash(s32 cam, f32 zoom, f32 cx, f32 cy, f32 cz, f32 rx, f32 ry, f32 rz,
                                      u16 frames) {
    D_8010B258_1C6DD8_DungeonDash[cam] = zoom;
    D_8010B1B8_1C6D38_DungeonDash[cam].x = cx;
    D_8010B1B8_1C6D38_DungeonDash[cam].y = cy;
    D_8010B1B8_1C6D38_DungeonDash[cam].z = cz;
    D_8010B218_1C6D98_DungeonDash[cam].x = rx;
    D_8010B218_1C6D98_DungeonDash[cam].y = ry;
    D_8010B218_1C6D98_DungeonDash[cam].z = rz;
    if (D_8010B268_1C6DE8_DungeonDash[cam] != 0) {
        func_80106EC4_1C2A44_DungeonDash(cam);
    }
    D_8010B270_1C6DF0_DungeonDash[cam] = frames;
    D_8010B268_1C6DE8_DungeonDash[cam] = frames;
}

void func_80106E08_1C2988_DungeonDash(s32 cam) {
    D_8010B248_1C6DC8_DungeonDash[cam] = D_8010B258_1C6DD8_DungeonDash[cam];
    D_8010B1E8_1C6D68_DungeonDash[cam].x = D_8010B218_1C6D98_DungeonDash[cam].x;
    D_8010B1E8_1C6D68_DungeonDash[cam].y = D_8010B218_1C6D98_DungeonDash[cam].y;
    D_8010B1E8_1C6D68_DungeonDash[cam].z = D_8010B218_1C6D98_DungeonDash[cam].z;
    D_8010B188_1C6D08_DungeonDash[cam].x = D_8010B1B8_1C6D38_DungeonDash[cam].x;
    D_8010B188_1C6D08_DungeonDash[cam].y = D_8010B1B8_1C6D38_DungeonDash[cam].y;
    D_8010B188_1C6D08_DungeonDash[cam].z = D_8010B1B8_1C6D38_DungeonDash[cam].z;
}

void func_80106EC4_1C2A44_DungeonDash(s32 cam) {
    D_8010B248_1C6DC8_DungeonDash[cam] = D_800F94A8_FA0A8[cam];
    D_8010B1E8_1C6D68_DungeonDash[cam].x = D_80102770_103370[cam].x;
    D_8010B1E8_1C6D68_DungeonDash[cam].y = D_80102770_103370[cam].y;
    D_8010B1E8_1C6D68_DungeonDash[cam].z = D_80102770_103370[cam].z;
    D_8010B188_1C6D08_DungeonDash[cam].x = D_801013B0_101FB0[cam].x;
    D_8010B188_1C6D08_DungeonDash[cam].y = D_801013B0_101FB0[cam].y;
    D_8010B188_1C6D08_DungeonDash[cam].z = D_801013B0_101FB0[cam].z;
}

/* Steps every camera tween; returns the last camera whose tween ran. */
s32 func_80106F80_1C2B00_DungeonDash(omObjData* obj, s32 count) {
    s32 i;
    s32 last;
    f32 t;

    i = 0;
    last = 0;
    for (; i < count; i++) {
        if (D_8010B268_1C6DE8_DungeonDash[i] != 0) {
            last = i;
            if (--D_8010B268_1C6DE8_DungeonDash[i] == 0) {
                func_80106E08_1C2988_DungeonDash(last);
            }
            t = (f32)(D_8010B270_1C6DF0_DungeonDash[i] - D_8010B268_1C6DE8_DungeonDash[i]) / D_8010B270_1C6DF0_DungeonDash[i];
            D_800F94A8_FA0A8[i] = (D_8010B258_1C6DD8_DungeonDash[i] - D_8010B248_1C6DC8_DungeonDash[i]) * t + D_8010B248_1C6DC8_DungeonDash[i];
            D_80102770_103370[i].x = (D_8010B218_1C6D98_DungeonDash[i].x - D_8010B1E8_1C6D68_DungeonDash[i].x) * t + D_8010B1E8_1C6D68_DungeonDash[i].x;
            D_80102770_103370[i].y = (D_8010B218_1C6D98_DungeonDash[i].y - D_8010B1E8_1C6D68_DungeonDash[i].y) * t + D_8010B1E8_1C6D68_DungeonDash[i].y;
            D_80102770_103370[i].z = (D_8010B218_1C6D98_DungeonDash[i].z - D_8010B1E8_1C6D68_DungeonDash[i].z) * t + D_8010B1E8_1C6D68_DungeonDash[i].z;
            D_801013B0_101FB0[i].x = (D_8010B1B8_1C6D38_DungeonDash[i].x - D_8010B188_1C6D08_DungeonDash[i].x) * t + D_8010B188_1C6D08_DungeonDash[i].x;
            D_801013B0_101FB0[i].y = (D_8010B1B8_1C6D38_DungeonDash[i].y - D_8010B188_1C6D08_DungeonDash[i].y) * t + D_8010B188_1C6D08_DungeonDash[i].y;
            D_801013B0_101FB0[i].z = (D_8010B1B8_1C6D38_DungeonDash[i].z - D_8010B188_1C6D08_DungeonDash[i].z) * t + D_8010B188_1C6D08_DungeonDash[i].z;
        }
    }
    return last;
}
