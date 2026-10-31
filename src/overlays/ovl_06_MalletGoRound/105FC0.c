#include "common.h"
#include "ovl_06.h"

__asm__(".section .rodata");
const u32 D_80108510_10BCD0_MalletGoRound[18] = { 0x82728273, 0x82608271, 0x82738268, 0x82738264, 0x826C8266, 0x82648273, 0x81498148, 0x00000000, 0x82688273, 0x8264826C, 0x81408266, 0x82648273, 0x81480000, 0x82688273, 0x8264826C, 0x81408266, 0x82648273, 0x81490000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_MalletGoRound/105FC0", func_80102800_105FC0_MalletGoRound);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_MalletGoRound/105FC0", func_80102C14_1063D4_MalletGoRound);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_MalletGoRound/105FC0", func_80102CAC_10646C_MalletGoRound);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_MalletGoRound/105FC0", func_801037B0_106F70_MalletGoRound);

void func_80103DB4_107574_MalletGoRound(omObjData* obj) {
    if (D_80108458_10BC18_MalletGoRound == 1) {
        if (obj->trans.y > -50.0f) {
            obj->rot.x -= 12.0f;
            if (obj->rot.x < 0.0f) {
                obj->rot.x += 360.0f;
            }
            obj->trans.z -= 10.0f;
            obj->trans.y += D_80108470_10BC30_MalletGoRound;
            D_80108470_10BC30_MalletGoRound -= 8.0f;
        } else {
            obj->trans.y = -50.0f;
        }
    }
}

void func_80103E7C_10763C_MalletGoRound(omObjData* obj) {
    ColActorWork* w;

    obj->unk_50 = w = func_80027154_27D54(sizeof(ColActorWork), 0x7918);
    func_800B0EF0_B1AF0(w, 0, sizeof(ColActorWork));
    w->unk_7C = 0;
    w->unk_54 = 1;
    w->unk_44 = 0.1f;
    w->unk_48 = 30.0f;
    w->unk_34 = 50.0f;
    w->unk_3C = 0.0f;
    w->unk_78 = 0;
    w->unk_38 = 1000.0f;
    w->unk_52 = 3;
    *(f32*)&w->unk_74 = 0.5f;
    w->unk_50 = 0x20;
    obj->model[0] = func_80018A64_19664(0x160003, 0x2B9);
    func_80105168_108928_MalletGoRound(D_801087A0_10BF60_MalletGoRound, D_80108794_10BF54_MalletGoRound);
    obj->func_ptr = func_80103DB4_107574_MalletGoRound;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_MalletGoRound/105FC0", func_80103F78_107738_MalletGoRound);

__asm__(".section .rodata");
const u32 D_80108558_10BD18_MalletGoRound[4] = { 0xFF000102, 0x03040506, 0x07080900, 0x00000000 };

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_MalletGoRound/105FC0", func_801042D4_107A94_MalletGoRound);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_06_MalletGoRound/105FC0", func_80104BC8_108388_MalletGoRound);

void func_801050B0_108870_MalletGoRound(f32 fov, f32 x, f32 y, f32 z, f32 rx, f32 ry, f32 rz) {
    D_800FA610_FB210 = fov;
    D_800FD474_FE074.x = x;
    D_800FD474_FE074.y = y;
    D_800FD474_FE074.z = z;
    D_8010274C_10334C.x = rx;
    D_8010274C_10334C.y = ry;
    D_8010274C_10334C.z = rz;
}

/* The skip object: START while the framework says so (D_801011FC) fades out and leaves. */
void func_801050F0_1088B0_MalletGoRound(void) {
    if (D_801011FC_101DFC == 1) {
        if (D_80108490_10BC50_MalletGoRound == 0) {
            InitFadeOut(0, 0x14);
            D_80108490_10BC50_MalletGoRound = 1;
        } else if (func_8008F618_90218() == 0) {
            func_800794A8_7A0A8(0x28);
            func_80069770_6A370();
            omOvlReturnEx(1);
        }
    }
}

/* Puts the item in the player's hand. */
s32 func_80105168_108928_MalletGoRound(omObjData* obj, omObjData* item) {
    MgWork* w;
    ColActorWork* iw;
    u16 f;

    w = obj->unk_50;
    iw = item->unk_50;

    if (iw->unk_50 & 0x20) {
        if (!(((volatile ColActorWork*)iw)->unk_50 & 0x10)) { /* retail reloads the flags */
            f = w->unk_50;
            if (f & 0x10) {
                return 0;
            }
            w->unk_50 = f | 0x10;
            iw->unk_50 |= 0x10;
            w->unk_C8 = item;
            func_8002C628_2D228(item->model[0], obj->model[0], "item_hook");
            func_800298A4_2A4A4(item->model[0], 0x4000, 0x4000);
            w->unk_B4 = *(f32*)&iw->unk_74;
            return 1;
        }
    }
    return 0;
}

/* Lets the item go. */
s32 func_80105224_1089E4_MalletGoRound(omObjData* obj, omObjData* item) {
    MgWork* w = obj->unk_50;
    ColActorWork* iw = item->unk_50;

    if (!(iw->unk_50 & 0x20)) {
        return 0;
    }
    w->unk_50 &= 0xFFEF;
    iw->unk_50 &= 0xFFEF;
    w->unk_C8 = NULL;
    func_800298A4_2A4A4(item->model[0], 0x4000, 0);
    return 1;
}

void func_80105284_108A44_MalletGoRound(omObjData* obj) {
    f32 scale = 0.4f - obj->trans.y * 0.0015f;

    func_800297E8_2A3E8(obj->model[1], scale, 0.0f, scale);
    func_80029714_2A314(obj->model[1], obj->trans.x, 2.4f, obj->trans.z);
}

f32 func_80105308_108AC8_MalletGoRound(void) {
    s8 x;
    s8 y;
    s8 port;
    f32 ret;
    s16 i;
    f32 sx;
    f32 sy;

    port = ((MgWork*)D_800FFFD8_100BD8[0]->unk_50)->unk_57;
    y = ContStkY[port];
    x = ContStkX[port];
    if (x > 60) {
        x = 60;
    }
    if (y > 60) {
        y = 60;
    }
    if (x < -60) {
        x = -60;
    }
    if (y < -60) {
        y = -60;
    }
    D_80108494_10BC54_MalletGoRound[D_801084A4_10BC64_MalletGoRound] = (f32)x;
    D_8010849C_10BC5C_MalletGoRound[D_801084A4_10BC64_MalletGoRound] = (f32)y;
    D_801084A4_10BC64_MalletGoRound = ((u8)D_801084A4_10BC64_MalletGoRound + 1) & 7;
    sx = 0.0f;
    sy = 0.0f;
    for (i = 0; i < 8; i++) {
        sx += D_80108494_10BC54_MalletGoRound[i];
        sy += D_8010849C_10BC5C_MalletGoRound[i];
    }
    sx /= 8.0f;
    sy /= 8.0f;
    if (sx * sx + sy * sy > 100.0f) {
        ret = func_800B75A8_B81A8(sx, -sy) + 180.0f;
    } else {
        ret = -1.0f;
    }
    return ret;
}

/* Park-Miller step (16807 mod 2^31 - 1); a zero seed is re-seeded. */
u32 func_801054D4_108C94_MalletGoRound(u32 seed) {
    s32 hi;
    s32 lo;

    if (seed == 0) {
        seed = rand8();
        seed = seed ^ guRandom();
        seed ^= 0xD826BC89;
    }
    hi = seed / 127773;
    lo = seed - hi * 127773;
    seed = hi * 2836;
    seed = seed - lo * 16807;
    return seed;
}

u32 func_801055A8_108D68_MalletGoRound(void) {
    return D_801084A8_10BC68_MalletGoRound = func_801054D4_108C94_MalletGoRound(D_801084A8_10BC68_MalletGoRound);
}

u16 func_801055D0_108D90_MalletGoRound(s32 file, s32 attr, u8 arg2) {
    void* data = DataRead(file);
    u16 id = func_80020EBC_21ABC(data, attr, arg2);

    HuMemMemoryFreePerm(data);
    return id;
}

__asm__(".section .rodata\n\t.balign 16\n\t.text");
