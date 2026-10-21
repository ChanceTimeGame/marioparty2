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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80104354_2AA4F4_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_801043E4_2AA584_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80104474_2AA614_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_801047AC_2AA94C_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80104844_2AA9E4_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_801049AC_2AAB4C_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80104C9C_2AAE3C_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80104CE4_2AAE84_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80104D28_2AAEC8_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80104DF4_2AAF94_DesertDuel);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3F_DesertDuel/2A89A0", func_80104EF8_2AB098_DesertDuel);

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
