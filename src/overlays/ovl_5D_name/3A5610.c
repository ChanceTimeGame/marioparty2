#include "ovl_5D.h"

// register allocation (masked 14)
#ifdef NON_MATCHING
s16 func_80107C20_3A5610_name_5D(s16 cur, s16 n, s16 dx, s16 dy) {
    Vec2f dir[30];
    f32 dist[30];
    f32 x;
    f32 y;
    f32 len;
    f32 ux;
    f32 uy;
    f32 best;
    s16 i;
    s16 found;

    for (i = 0; i < n; i++) {
        if (i == cur || D_8010CDF8_3AA7E8_name_5D[i] != -1) {
            dist[i] = -1.0f;
        } else {
            x = D_8010BA78_3A9468_name_5D[cur][0] - D_8010BA78_3A9468_name_5D[i][0];
            y = D_8010BA78_3A9468_name_5D[cur][1] - D_8010BA78_3A9468_name_5D[i][1];
            dist[i] = len = func_800B1830_B2430(x * x + y * y);
            dir[i].unk_00 = x / len;
            dir[i].unk_04 = y / len;
        }
    }
    len = func_800B1830_B2430(dx * dx + dy * dy);
    ux = dx / len;
    uy = dy / len;
    for (i = 0; i < n; i++) {
        if (dist[i] < 0.0f) {
            continue;
        }
        x = ux - dir[i].unk_00;
        y = uy - dir[i].unk_04;
        if (func_800B1830_B2430(x * x + y * y) > 0.5f) {
            dist[i] = -1.0f;
        }
    }
    best = 100000.0f;
    found = -1;
    for (i = 0; i < n; i++) {
        if (dist[i] < 0.0f) {
            continue;
        }
        if (dist[i] < best) {
            best = dist[i];
            found = i;
        }
    }
    return found;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_5D_name/3A5610", func_80107C20_3A5610_name_5D);
#endif

void func_80107F70_3A5960_name_5D(omObjData* obj) {
    if (D_8010CDE4_3AA7D4_name_5D != 0 || D_801011FC_101DFC != 0) {
        if (D_8010CE2A_3AA81A_name_5D == 0) {
            InitFadeOut(0, 8);
            func_800794A8_7A0A8(30);
            func_80079614_7A214(30);
        }
        obj->func_ptr = func_80107FE4_3A59D4_name_5D;
    }
}

void func_80107FE4_3A59D4_name_5D(omObjData* obj) {
    u16 stat;

    if (func_8008F618_90218() == 0) {
        func_8001AC44_1B844(D_8010CCE4_3AA6D4_name_5D);
        func_8008CE5C_8DA5C();
        stat = 0x100;
        if (D_8010CE28_3AA818_name_5D == 0x58) {
            stat = 0x1000;
        }
        switch (D_8010CDF4_3AA7E4_name_5D) {
            case 0:
                omOvlReturnEx(1);
                break;
            case 2:
                omOvlCallEx(D_8010CE28_3AA818_name_5D, D_8010CDB8_3AA7A8_name_5D, stat | 0x11);
                break;
            case 1:
                omOvlGotoEx(D_8010CE28_3AA818_name_5D, D_8010CDB8_3AA7A8_name_5D, stat | 0x11);
                break;
        }
    }
}
