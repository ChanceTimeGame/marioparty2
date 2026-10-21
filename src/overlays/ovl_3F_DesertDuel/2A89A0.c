#include "common.h"
#include "ovl_3F.h"

#ifdef NON_MATCHING /* rodata-pending */
void func_80102800_2A89A0_DesertDuel(void) {
    omInitObjMan(30, 10);
    func_80079128_79D28();
    func_80018E30_19A30(1);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_80050A30_51630(D_01164160);
    MBModelInit();
    func_8005E2B8_5EEB8();
    func_800593C0_59FC0();
    func_800581A0_58DA0();
    func_801029C0_2A8B60_DesertDuel();
    func_80088640_89240();
    func_8005FE10_60A10();
    func_80060034_60C34(0, (u8)gPlayers[0].player_space_color);
    func_80060034_60C34(1, (u8)gPlayers[1].player_space_color);
    func_80060034_60C34(2, (u8)gPlayers[2].player_space_color);
    func_80060034_60C34(3, (u8)gPlayers[3].player_space_color);
    HidePlayerHUDVisibility(0, 1);
    HidePlayerHUDVisibility(1, 1);
    HidePlayerHUDVisibility(2, 1);
    HidePlayerHUDVisibility(3, 1);
    omAddPrcObj(func_80102D1C_2A8EBC_DesertDuel, 0x5000, 0x2000, 0);
    omAddObj(1000, 0, 0, -1, func_80102C3C_2A8DDC_DesertDuel);
    D_80108C54_2AEDF4_DesertDuel = 0;
    func_80104D28_2AAEC8_DesertDuel();
    D_80108CD8_2AEE78_DesertDuel = 0;
    func_8007273C_7333C("\x82\x60\x82\x61\x82\x62\x81\x49", 1); /* SJIS "ABC!" */
    func_8007273C_7333C("\x82\x4F\x82\x50\x82\x51\x82\x52\x82\x53\x82\x54\x82\x55\x82\x56\x82\x57\x82\x58", 1); /* SJIS "0123456789" */
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80102800_2A89A0_DesertDuel);
#endif

/* Who is in the scene: the challenger (D_800F8D1A.attacker's bit), the players it may challenge
   (.targets), and the opponent when there is only one. Flag 0x19 (debug) lets A/B override. */
void func_801029C0_2A8B60_DesertDuel(void) {
    s32 bits;
    s32 i;

    D_800F8FE0_F9BE0 = 0;
    D_800FC87A_FD47A = 0;
    D_800FA606_FB206 = 0;
    D_80108C14_2AEDB4_DesertDuel = GwSystem.current_player_index;
    D_80108C1C_2AEDBC_DesertDuel = -1;
    D_80108C30_2AEDD0_DesertDuel = 0;
    for (i = 0; i < 2; i++) {
        D_80108C5C_2AEDFC_DesertDuel[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        D_80108C38_2AEDD8_DesertDuel[i] = 0;
    }
    D_80108C7C_2AEE1C_DesertDuel = 0;
    D_80108C9C_2AEE3C_DesertDuel = 0;
    if (_CheckFlag(0x17) == 0) {
        D_80108C9C_2AEE3C_DesertDuel = 1;
    }
    bits = D_800F8D1A_F991A.attacker;
    if (_CheckFlag(0x19) != 0) {
        if (ContBtn[0] & 0x8000) {
            bits = 1;
            D_80108C9C_2AEE3C_DesertDuel = 0;
        }
        if (ContBtn[0] & 0x4000) {
            bits = 1;
            D_80108C9C_2AEE3C_DesertDuel = 1;
        }
    }
    D_80108C18_2AEDB8_DesertDuel = 0;
    for (i = 0; bits != 0; i++) {
        bits >>= 1;
        if (bits == 0) {
            break;
        }
        D_80108C18_2AEDB8_DesertDuel++;
    }
    D_80108C48_2AEDE8_DesertDuel = 1;
    D_80108C38_2AEDD8_DesertDuel[i] = 1;
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
            D_80108C48_2AEDE8_DesertDuel++;
            D_80108C38_2AEDD8_DesertDuel[i] = 1;
        }
    }
    if (D_80108C48_2AEDE8_DesertDuel == 2) {
        for (i = 0; i < 4; i++) {
            if (D_80108C38_2AEDD8_DesertDuel[i] == 1 && i != D_80108C18_2AEDB8_DesertDuel) {
                D_80108C1C_2AEDBC_DesertDuel = i;
                break;
            }
        }
    }
    D_80108C90_2AEE30_DesertDuel = GwSystem.current_turn;
}

void func_80102C3C_2A8DDC_DesertDuel(omObjData* obj) {
    if (D_801011FC_101DFC != 0) {
        MBDBackKill();
        func_80050AE0_516E0();
        func_80059400_5A000();
        func_80069770_6A370();
        func_8008CE5C_8DA5C();
        omOvlReturnEx(1);
    }
}

void func_80102C90_2A8E30_DesertDuel(void) {
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

void func_80102D1C_2A8EBC_DesertDuel(void) {
    func_80102D48_2A8EE8_DesertDuel();
    while (TRUE) {
        HuPrcVSleep();
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80102D48_2A8EE8_DesertDuel);

/* The referee's hat flies off: it shrinks and spins for 15 frames, then hides. */
void func_80104354_2AA4F4_DesertDuel(void) {
    omObjData* obj;
    Unk3FShrink* work;

    obj = omAddObj(0x10, 0, 0, -1, func_801043E4_2AA584_DesertDuel);
    work = func_80027154_27D54(sizeof(Unk3FShrink), 0x7918);
    obj->unk_50 = work;
    work->scaleSpeed = -0.06666667f;
    work->rotSpeed = -3.0f;
    work->unk10 = 0;
    work->unkC = 1.0f;
    work->timer = 15;
}

void func_801043E4_2AA584_DesertDuel(omObjData* obj) {
    Unk3FShrink* work = obj->unk_50;

    D_80108CA8_2AEE48_DesertDuel->scale.x += work->scaleSpeed;
    D_80108CA8_2AEE48_DesertDuel->scale.y += work->scaleSpeed;
    D_80108CA8_2AEE48_DesertDuel->scale.z += work->scaleSpeed;
    D_80108CA8_2AEE48_DesertDuel->obj->rot.x += work->rotSpeed;
    if (--work->timer == 0) {
        MBModelDispOff(D_80108CA8_2AEE48_DesertDuel);
        omDelObj(obj);
    }
}

/* Moves the status windows of the players in the scene to layout `layout` of D_80108730; the
   challenger takes slot 3, the chosen opponent slot 2, the others slots 0, 1 (and are listed in
   D_80108C20). D_80108C50 is set when every window has arrived. */
void func_80104474_2AA614_DesertDuel(s32 layout) {
    omObjData* obj;
    s32* work;
    BoardStatus* status;
    s32 slot;
    s32 i;
    s32 next;

    D_80108C50_2AEDF0_DesertDuel = 0;
    obj = omAddObj(0x12, 0, 0, -1, func_801047AC_2AA94C_DesertDuel);
    work = func_80027154_27D54(8, 0x7918);
    obj->unk_50 = work;
    *work = layout;
    next = 0;
    for (i = 0; i < 4; i++) {
        if (D_80108C38_2AEDD8_DesertDuel[i] != 0) {
            status = &D_80101510_102110[i];
            slot = 3;
            if (i != D_80108C18_2AEDB8_DesertDuel) {
                if (i == D_80108C1C_2AEDBC_DesertDuel) {
                    slot = 2;
                } else {
                    slot = next;
                    D_80108C20_2AEDC0_DesertDuel[slot] = i;
                    next = slot + 1;
                }
            }
            if (D_80108730_2AE8D0_DesertDuel[layout].pos[slot][0] != -1) {
                status->xPos = D_80108730_2AE8D0_DesertDuel[layout].pos[slot][0];
            }
            if (D_80108730_2AE8D0_DesertDuel[layout].pos[slot][1] != -1) {
                status->yPos = D_80108730_2AE8D0_DesertDuel[layout].pos[slot][1];
            }
            func_800600F8_60CF8(i, status->xPos, status->yPos);
            status->unk_0C = D_80108730_2AE8D0_DesertDuel[layout].frames - 1;
            if (D_80108730_2AE8D0_DesertDuel[layout].pos[slot][2] != -1) {
                status->unk_18 = D_80108730_2AE8D0_DesertDuel[layout].pos[slot][2];
            }
            if (D_80108730_2AE8D0_DesertDuel[layout].pos[slot][3] != -1) {
                status->unk_1C = D_80108730_2AE8D0_DesertDuel[layout].pos[slot][3];
            }
            status->unk_20 = status->unk_28 = 2.0f * (status->unk_18 - status->xPos) / ((status->unk_0C + 1) * (status->unk_0C + 1));
            status->unk_24 = status->unk_2C = 2.0f * (status->unk_1C - status->yPos) / ((status->unk_0C + 1) * (status->unk_0C + 1));
        }
    }
    if (D_80108CD8_2AEE78_DesertDuel == 6) {
        status = &D_80101510_102110[D_80108C18_2AEDB8_DesertDuel];
        D_800FD854_FE454[0].unk_00 = D_800FC990_FD590[0].unk_00 = status->unk_28;
        D_800FD854_FE454[0].unk_04 = D_800FC990_FD590[0].unk_04 = status->unk_2C;
        D_800FA604_FB204 = D_80108730_2AE8D0_DesertDuel[layout].frames - 1;
    }
}

void func_801047AC_2AA94C_DesertDuel(omObjData* obj) {
    BoardStatus* status;
    s32 done;
    s32 i;

    done = 0;
    for (i = 0; i < 4; i++) {
        if (D_80108C38_2AEDD8_DesertDuel[i] != 0) {
            status = &D_80101510_102110[i];
            if (status->unk_0C == 0) {
                status->xPos = status->unk_18;
                status->yPos = status->unk_1C;
                done++;
            }
        }
    }
    if (done == D_80108C48_2AEDE8_DesertDuel) {
        D_80108C50_2AEDF0_DesertDuel = 1;
        omDelObj(obj);
    }
}

/* Opens a message window that only the duelists' pads can advance. */
/* NON_MATCHING: registers (masked 14): retail keeps the raw window id in s2 and its s16 copy in s1
   (arg6 in s0) and narrows the mask in each branch. */
#ifdef NON_MATCHING
s16 func_80104844_2AA9E4_DesertDuel(s16 x, s16 y, s16 w, s16 h, s16 arg4, s16 arg5, s32 arg6) {
    s16 win;
    s16 mask;

    win = func_800888A8_894A8(x, y, w, h, arg4, arg5);
    func_80089284_89E84(win, 0x40, 0x40);
    func_80089A48_8A648(win, 0);
    func_8008D88C_8E48C(win);
    func_80089B2C_8A72C(win, arg6);
    if (D_80108C1C_2AEDBC_DesertDuel != -1) {
        mask = (1 << gPlayers[D_80108C18_2AEDB8_DesertDuel].port) | (1 << gPlayers[D_80108C1C_2AEDBC_DesertDuel].port);
    } else {
        mask = 1 << gPlayers[D_80108C18_2AEDB8_DesertDuel].port;
    }
    func_8008D59C_8E19C(win, mask);
    return win;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80104844_2AA9E4_DesertDuel);
#endif

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_801049AC_2AAB4C_DesertDuel);

/* A tumbleweed every 210 frames. */
void func_80104C9C_2AAE3C_DesertDuel(void) {
    D_80108C4C_2AEDEC_DesertDuel = 210;
    D_80108CE0_2AEE80_DesertDuel = omAddObj(0x10, 0, 0, -1, func_80104CE4_2AAE84_DesertDuel);
}

void func_80104CE4_2AAE84_DesertDuel(omObjData* obj) {
    if (--D_80108C4C_2AEDEC_DesertDuel == 0) {
        func_80104DF4_2AAF94_DesertDuel(D_80108CD4_2AEE74_DesertDuel);
        D_80108C4C_2AEDEC_DesertDuel = 210;
    }
}

/* The tumbleweed: model 0xA019E with shadow 0x0D. */
void func_80104D28_2AAEC8_DesertDuel(void) {
    omObjData* obj;
    Unk3FTumbleweed* work;

    obj = omAddObj(0x10, 3, 3, -1, func_80104EF8_2AB098_DesertDuel);
    obj->model[0] = LoadFormFile(0xA019E, 0x699);
    obj->model[1] = LoadFormFile(0xD, 0x299);
    work = func_80027154_27D54(sizeof(Unk3FTumbleweed), 0x7918);
    obj->unk_50 = work;
    obj->trans.x = 600.0f;
    obj->trans.y = 45.0f;
    obj->trans.z = 1500.0f;
    obj->rot.x = 0.0f;
    obj->rot.y = 0.0f;
    obj->rot.z = 0.0f;
    work->active = 0;
    work->count = 0;
    D_80108CD4_2AEE74_DesertDuel = obj;
}

/* Starts the tumbleweed across the stage: the first time from the right, then from a random side. */
void func_80104DF4_2AAF94_DesertDuel(omObjData* obj) {
    Unk3FTumbleweed* work = obj->unk_50;

    work->active = 1;
    work->rot = 0.0f;
    work->count &= 0xFF;
    if (work->count == 0 || (rand8() & 1)) {
        work->startX = 140.0f;
        work->endX = -300.0f;
        work->speed = -13.0f;
    } else {
        work->startX = -140.0f;
        work->endX = 300.0f;
        work->speed = 13.0f;
    }
    obj->trans.x = work->startX * 5.0f;
    obj->trans.y = 45.0f;
    obj->trans.z = 1350.0f;
    work->count++;
}

void func_80104EF8_2AB098_DesertDuel(omObjData* obj) {
    Unk3FTumbleweed* work = obj->unk_50;

    if (work->active) {
        obj->trans.x += work->speed;
        obj->trans.y = 36.0f;
        obj->trans.z = 850.0f;
        work->rot -= work->speed;
        if (work->rot < 0.0f) {
            work->rot += 360.0f;
        }
        omSetRot(obj, 0.0f, 0.0f, work->rot);
        omSetSca(obj, 0.8f, 0.8f, 0.8f);
        func_80029714_2A314(obj->model[1], obj->trans.x, 0.0f, obj->trans.z);
        if ((work->speed < 0.0f && obj->trans.x < work->endX) || (work->speed > 0.0f && obj->trans.x > work->endX)) {
            work->active = 0;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80105054_2AB1F4_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_801058C8_2ABA68_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80105AAC_2ABC4C_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80105DB8_2ABF58_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80106040_2AC1E0_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80106328_2AC4C8_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80106600_2AC7A0_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80106988_2ACB28_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80106C94_2ACE34_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80107018_2AD1B8_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80107128_2AD2C8_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_801071C8_2AD368_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80107314_2AD4B4_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80107350_2AD4F0_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_801073A8_2AD548_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_801073FC_2AD59C_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80107940_2ADAE0_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80107A00_2ADBA0_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80107BF8_2ADD98_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80107EE4_2AE084_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80108580_2AE720_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80108720_2AE8C0_DesertDuel);
