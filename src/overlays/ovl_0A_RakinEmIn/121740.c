#include "common.h"
#include "ovl_0A.h"

void func_80102800_121740_RakinEmIn(void) {
    func_801069D8_125918_RakinEmIn();
}

void func_8010281C_12175C_RakinEmIn(u8 player) {
    ContBtn[gPlayers[player].port] = 0;
    ContBtnTrg[gPlayers[player].port] = 0;
    ContStkX[gPlayers[player].port] = 0;
    ContStkY[gPlayers[player].port] = 0;
}

/* Picks one of the first n bits still clear in *used at random, sets it and returns it. */
u8 func_801028A0_1217E0_RakinEmIn(u8 n, u64* used) {
    u64 m;
    u8 k;
    u8 i;

    m = *used;
    i = n;
    while (m != 0) {
        if (m & 1) {
            i--;
        }
        m >>= 1;
    }
    k = rand8() % i;
    m = *used;
    for (i = 0; i < n; i++) {
        if (m & 1) {
        } else if (k-- == 0) {
            break;
        }
        m >>= 1;
    }
    i = (i < n) ? i : 0;
    *used |= 1 << i;
    return i;
}

/* atan(x) by a continued fraction. */
/* NON_MATCHING: retail keeps the quotient in $f2 and converts it in the goto's delay slot (f64
   register allocation, masked 8; MP1's func_800FDBF4_name_2A and ovl_23's twin are the same). */
#ifdef NON_MATCHING
f32 func_801029F0_121930_RakinEmIn(f32 x) {
    f32 a;
    f32 b;
    f32 sum;
    f64 base;
    f64 frac;
    s32 sign;
    s32 i;

    sign = 1;
    if (x > 1.0f) {
        x = 1.0f / x;
    } else {
        sign = -1;
        if (x < -1.0f) {
            x = 1.0f / x;
        } else {
            sign = 0;
        }
    }
    sum = 0.0f;
    i = 6;
    do {
        a = (f32)(i * i) * x * x;
        b = (f32)(i * 2 + 1) + sum;
        i--;
        sum = a / b;
    } while (i > 0);
    if (sum != -1.0f) {
        if (sign > 0) {
            base = 1.5707963267948966;
            frac = x / (sum + 1.0f);
            goto done;
        }
        if (sign < 0) {
            frac = x / (sum + 1.0f);
            base = -1.5707963267948966;
        done:
            return base - frac;
        }
        return x / (sum + 1.0f);
    }
    return 0.0f;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_801029F0_121930_RakinEmIn);
#endif

/* From `from` to `to`: out = { distance, pitch + 90 (degrees), yaw (degrees) }. */
/* NON_MATCHING: the 180.0f load is scheduled before the near-zero test, not into its delay
   slots (masked 25; ovl_23's func_80106EB0 has the same residue). */
#ifdef NON_MATCHING
void func_80102B40_121A80_RakinEmIn(Vec* from, Vec* to, Vec* out) {
    Vec delta;
    Vec fromV;
    Vec toV;
    f32 horizontal;
    f32 pitch;
    f32 yaw;
    s32 nearPositive;
    s32 nearNegative;

    fromV.x = from->x;
    fromV.y = from->y;
    fromV.z = from->z;
    toV.x = to->x;
    toV.y = to->y;
    toV.z = to->z;
    delta.x = toV.x - fromV.x;
    delta.y = toV.y - fromV.y;
    delta.z = toV.z - fromV.z;
    horizontal = func_800B1820_B2420(delta.x * delta.x + delta.z * delta.z);
    nearPositive = horizontal <= 0.002f;
    nearNegative = horizontal >= -0.002f;
    if (nearPositive & nearNegative) {
        yaw = 0.0f;
        pitch = 180.0f;
        horizontal = yaw;
        if (!(delta.y > 0.0001f) && delta.y < 0.0001f) {
            pitch = yaw;
        }
    } else {
        if (delta.x != 0.0f || delta.z != 0.0f) {
            yaw = func_801029F0_121930_RakinEmIn(delta.x / delta.z) * 57.29577951308232;
        } else {
            yaw = 0.0f;
        }
        if (delta.z < 0.0f) {
            yaw -= 180.0f;
        }
        if (horizontal != 0.0f || delta.y != 0.0f) {
            pitch = func_801029F0_121930_RakinEmIn(delta.y / horizontal) * 57.29577951308232;
        } else {
            pitch = 0.0f;
        }
        yaw = yaw >= 360.0f ? yaw - 360.0f : yaw < 0.0f ? yaw + 360.0f : yaw;
        pitch = pitch + 90.0f >= 360.0f ? pitch + 90.0f - 360.0f : pitch + 90.0f < 0.0f ? pitch + 90.0f + 360.0f : pitch + 90.0f;
    }
    nearPositive = pitch <= 0.002f;
    nearNegative = pitch >= -0.002f;
    if (nearPositive & nearNegative) {
        pitch = 0.0f;
    }
    out->x = func_800B1820_B2420(delta.y * delta.y + horizontal * horizontal);
    out->y = pitch;
    out->z = yaw;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_80102B40_121A80_RakinEmIn);
#endif

/* angle + add, wrapped to [0, 360). */
f32 func_80102EB4_121DF4_RakinEmIn(f32 angle, f32 add) {
    angle += add;
    if (angle >= 360.0f) {
        angle -= 360.0f;
    } else if (angle < 0.0f) {
        angle += 360.0f;
    }
    return angle;
}

void func_80102F0C_121E4C_RakinEmIn(void) {
    s32 i;

    if (D_80106F74_125EB4_RakinEmIn == 0) {
        D_80106F74_125EB4_RakinEmIn = 1;
        for (i = 0; i < 2; i++) {
            Hu3DCamSetPerspective(i, 24.287f, 80.0f, 8000.0f);
            D_800F94A8_FA0A8[i] = 2560.929f;
            D_80102770_103370[i].x = 324.783f;
            D_80102770_103370[i].y = 0.0f;
            D_80102770_103370[i].z = 0.0f;
            D_801013B0_101FB0[i].x = 0.0f;
            D_801013B0_101FB0[i].y = 83.450005f;
            D_801013B0_101FB0[i].z = 61.75f;
        }
    }
}

void func_8010302C_121F6C_RakinEmIn(RIObj* o, s16 member, u16 anim, u16 x, s32 y) {
    D_801071E0_126120_RakinEmIn[(u16)(member + 10)] = anim;
    SprAnimSet(o->spr, member, anim, 0);
    SprAttrSet(o->spr, member, 0x1000);
    SprPosSet(o->spr, member, x, y);
    SprPrioSet(o->spr, member, 0xFFF4);
}

/* The scores: count the shown number one step towards the score (left-aligned digits), then
   pop it. */
void func_801030E4_122024_RakinEmIn(omObjData* obj) {
    RIObj* hud;
    RIScore* sc;
    f32 s;
    s16 i;
    s16 m;
    s16 lead;
    u16 n;
    u16 d;

    hud = &D_80107AC0_126A00_RakinEmIn;
    for (i = 0; i < 4; i++) {
        sc = &D_801071B0_1260F0_RakinEmIn[i];
        switch (sc->state) {
        case 0:
            if (sc->shown != sc->score) {
                if (sc->shown < sc->score) {
                    n = sc->shown + 1;
                } else {
                    n = sc->shown - 1;
                }
                lead = 0;
                m = i * 3 + 12;
                d = n / 100;
                if (d != 0) {
                    SprBankSet(hud->spr, m++, d);
                    lead = 1;
                } else {
                    SprAttrSet(hud->spr, m + 2, 0x8000);
                }
                if ((d = (u16)(n % 100) / 10) != 0) {
                    goto show;
                }
                if (lead != 0) {
                show:
                    SprBankSet(hud->spr, m++, d);
                } else {
                    SprAttrSet(hud->spr, m + 1, 0x8000);
                }
                d = n % 10;
                SprBankSet(hud->spr, m, d);
                SprAttrReset(hud->spr, m, 0x8000);
                sc->shown = n;
                sc->state = 1;
            }
            break;
        case 1:
            m = i + 4;
            sc->angle += 40.0f;
            if (sc->angle > 180.0f) {
                sc->angle = 0.0f;
                sc->state = 0;
            }
            s = func_800B80D0_B8CD0(sc->angle) + 1.0;
            SprScaleSet(hud->spr, m, s, s);
            break;
        }
    }
}

/* The HUD: four faces, four basket icons, four "x" signs and three digits per player. */
void func_801033B0_1222F0_RakinEmIn(omObjData* obj) {
    s16 i;
    s16 j;
    u16 anim;
    RIObj* hud;

    hud = &D_80107AC0_126A00_RakinEmIn;
    func_800B0EF0_B1AF0(D_801071B0_1260F0_RakinEmIn, 0, 0x30);
    D_80107AC4_126A04_RakinEmIn = SprCreate(24, 0);
    for (i = 0; i < 4; i++) {
        func_8010302C_121F6C_RakinEmIn(hud, i,
                                       func_8001A2F8_1AEF8(D_80106F5C_125E9C_RakinEmIn[gPlayers[i].character]),
                                       D_80106F1C_125E5C_RakinEmIn[i][0], D_80106F1E_125E5E_RakinEmIn[i][0]);
    }
    anim = func_8001A2F8_1AEF8(0x17000F);
    for (; i < 8; i++) {
        func_8010302C_121F6C_RakinEmIn(hud, i, anim, D_80106F1C_125E5C_RakinEmIn[i][0],
                                       D_80106F1E_125E5E_RakinEmIn[i][0]);
    }
    anim = func_8001A2F8_1AEF8(0x170010);
    for (; i < 12; i++) {
        func_8010302C_121F6C_RakinEmIn(hud, i, anim, D_80106F1C_125E5C_RakinEmIn[i][0],
                                       D_80106F1E_125E5E_RakinEmIn[i][0]);
    }
    anim = func_8001A2F8_1AEF8(0x43);
    for (j = i; j < 16; j++) {
        func_8010302C_121F6C_RakinEmIn(hud, i++, anim, D_80106F1C_125E5C_RakinEmIn[j][0],
                                       D_80106F1E_125E5E_RakinEmIn[j][0]);
        func_8010302C_121F6C_RakinEmIn(hud, i, anim, D_80106F1C_125E5C_RakinEmIn[j][0] + 12,
                                       D_80106F1E_125E5E_RakinEmIn[j][0]);
        SprAttrSet(hud->spr, i++, 0x8000);
        func_8010302C_121F6C_RakinEmIn(hud, i, anim, D_80106F1C_125E5C_RakinEmIn[j][0] + 24,
                                       D_80106F1E_125E5E_RakinEmIn[j][0]);
        SprAttrSet(hud->spr, i++, 0x8000);
    }
    obj->func_ptr = func_801030E4_122024_RakinEmIn;
}

void func_801036B8_1225F8_RakinEmIn(void) {
    D_80107AC0_126A00_RakinEmIn.obj = omAddObj(600, 0, 0, -1, func_801033B0_1222F0_RakinEmIn);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_801036F4_122634_RakinEmIn);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_8010378C_1226CC_RakinEmIn);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_80103BB0_122AF0_RakinEmIn);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_80103E04_122D44_RakinEmIn);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_80103E4C_122D8C_RakinEmIn);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_80103F9C_122EDC_RakinEmIn);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_8010428C_1231CC_RakinEmIn);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_80104340_123280_RakinEmIn);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_801043B0_1232F0_RakinEmIn);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_80104418_123358_RakinEmIn);

__asm__(".section .rodata");
const u32 D_80106FF0_125F30_RakinEmIn[2] = { 0x000F001E, 0x00320046 };

__asm__(".section .rodata");
const u32 D_80106FF8_125F38_RakinEmIn[2] = { 0x003C0028, 0x0014000A };

__asm__(".section .rodata");
const u32 D_80107000_125F40_RakinEmIn[2] = { 0x00020001, 0x00010001 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_80104474_1233B4_RakinEmIn);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_8010468C_1235CC_RakinEmIn);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_80104950_123890_RakinEmIn);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_80104A6C_1239AC_RakinEmIn);

__asm__(".section .rodata");
const u32 D_80107008_125F48_RakinEmIn[2] = { 0x00200060, 0x00300050 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_80104BCC_123B0C_RakinEmIn);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_801051D8_124118_RakinEmIn);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_80105550_124490_RakinEmIn);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_801055F4_124534_RakinEmIn);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_80105E98_124DD8_RakinEmIn);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_80106060_124FA0_RakinEmIn);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_80106104_125044_RakinEmIn);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_80106164_1250A4_RakinEmIn);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_80106218_125158_RakinEmIn);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_80106258_125198_RakinEmIn);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_801062CC_12520C_RakinEmIn);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_801064C8_125408_RakinEmIn);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_801065BC_1254FC_RakinEmIn);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_801065E0_125520_RakinEmIn);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_80106618_125558_RakinEmIn);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_80106670_1255B0_RakinEmIn);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_80106920_125860_RakinEmIn);

__asm__(".section .rodata");
const char D_80107098_125FD8_RakinEmIn[] = "\202`\202a\202b";

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_0A_RakinEmIn/121740", func_801069D8_125918_RakinEmIn);
