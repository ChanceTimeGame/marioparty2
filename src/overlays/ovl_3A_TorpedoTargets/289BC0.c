#include "ovl_3A.h"

/* Logic right; retail keeps the array address in a register. */
#ifdef NON_MATCHING
void func_801079B0_289BC0_TorpedoTargets(void) {
    D_80109264_28B474_TorpedoTargets[0]->func_ptr = func_80106DEC_288FFC_TorpedoTargets;
    D_80109264_28B474_TorpedoTargets[1]->func_ptr = func_80106DEC_288FFC_TorpedoTargets;
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3A_TorpedoTargets/289BC0", func_801079B0_289BC0_TorpedoTargets);
#endif

void func_801079D4_289BE4_TorpedoTargets(omObjData* obj) {
    s32 team = ((TTSub*)obj->unk_50)->team;

    if (D_80109390_28B5A0_TorpedoTargets == 0) {
        f32 x;
        f32 y;
        f32 z;

        D_80109460_28B670_TorpedoTargets = func_800B75A8_B81A8(obj->trans.x, obj->trans.z);
        x = D_801013B0_101FB0[team].x;
        y = D_801013B0_101FB0[team].y;
        z = D_801013B0_101FB0[team].z;
        D_80109464_28B674_TorpedoTargets = func_800B1830_B2430(x * x + y * y + z * z);
    }
    if (D_80109390_28B5A0_TorpedoTargets < 0xB4) {
        D_80109394_28B5A4_TorpedoTargets += 2.0f;
        D_80109464_28B674_TorpedoTargets -= 5.0f;
        if (D_80109464_28B674_TorpedoTargets < 400.0f) {
            D_80109464_28B674_TorpedoTargets = 400.0f;
        }
    }
    D_80102770_103370[team].y = D_80109460_28B670_TorpedoTargets + D_80109394_28B5A4_TorpedoTargets;
    D_801013B0_101FB0[team].x = obj->trans.x;
    D_801013B0_101FB0[team].y = obj->trans.y - (D_80102770_103370[team].x * 5.0f - 20.0f);
    D_801013B0_101FB0[team].z = obj->trans.z;
    D_800F94A8_FA0A8[team] = D_80109464_28B674_TorpedoTargets;
    D_80109390_28B5A0_TorpedoTargets++;
}

void func_80107BAC_289DBC_TorpedoTargets(omObjData* obj) {
    TTSub* w = obj->unk_50;

    w->stickY = 0;
    w->stickX = 0;
    w->gStickY = 0;
    w->gStickX = 0;
    w->gBtn = 0;
    w->btn = 0;
    if ((u32)(D_80109398_28B5A8_TorpedoTargets - 0x3D) < 0x77) {
        w->stickX = 0;
        w->stickY = -0x20;
        w->btn = 0x8000;
    }
    if (D_80109398_28B5A8_TorpedoTargets > 0x50) {
        w->stickX = -0x14;
    }
    func_80106DEC_288FFC_TorpedoTargets(obj);
    D_80109398_28B5A8_TorpedoTargets++;
}

void func_80107C38_289E48_TorpedoTargets(omObjData* obj) {
    TTSub* w = obj->unk_50;

    w->stickY = 0;
    w->stickX = 0;
    w->gStickY = 0;
    w->gStickX = 0;
    w->gBtn = 0;
    w->btn = 0;
    if (_CheckFlag(0xC) == 0) {
        w->tilt += 2.0f;
        if (w->tilt > 180.0f) {
            w->tilt = 180.0f;
            w->roll = HuMathSin(D_8010939C_28B5AC_TorpedoTargets) * 15.0f;
            D_8010939C_28B5AC_TorpedoTargets += 5.0f;
        } else {
            w->btn = 0x8000;
        }
        w->camDist *= 0.99f;
        if (w->camDist < 900.0f) {
            w->camDist = 900.0f;
        }
    }
    func_80106DEC_288FFC_TorpedoTargets(obj);
}

void func_80107D54_289F64_TorpedoTargets(omObjData* obj) {
    TTSub* w = obj->unk_50;

    w->stickY = 0;
    w->stickX = 0;
    w->gStickY = 0;
    w->gStickX = 0;
    w->gBtn = 0;
    w->btn = 0;
    if (_CheckFlag(0xC) == 0) {
        w->stickY = 0x20;
        w->camDist *= 0.99f;
        if (w->camDist < 900.0f) {
            w->camDist = 900.0f;
        }
    }
    func_80106DEC_288FFC_TorpedoTargets(obj);
}

void func_80107DF0_28A000_TorpedoTargets(Vec* out, s16 level) {
    s32 n;

    switch (level) {
    case 0:
        n = 8;
        break;
    case 3:
        n = 0xF;
        break;
    case 1:
        n = 0xA;
        break;
    case 2:
        n = 0xD;
        break;
    }
    switch (D_80109490_28B6A0_TorpedoTargets) {
    case 0:
        func_80108F94_28B1A4_TorpedoTargets(n * 2, out);
        break;
    case 1:
        func_80109060_28B270_TorpedoTargets(n, out);
        break;
    case 2:
        func_801090F8_28B308_TorpedoTargets(n, (f32*)out);
        break;
    case 3:
        func_801091F0_28B400_TorpedoTargets(n, out);
        break;
    }
}

__asm__(".section .rodata");
const Vec D_80109404_28B614_TorpedoTargets = { 0.0f, 0.0f, 0.0f };

void func_80107EDC_28A0EC_TorpedoTargets(omObjData* obj) {
    s32 p;
    TTSub* w = obj->unk_50;
    Vec3f dir;
    Vec aim = D_80109404_28B614_TorpedoTargets;
    f32 turnLim;
    f32 stick;
    f32 stop;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 d;
    f32 a;
    f32 sn;

    if (gPlayers[w->pilot].flags & 1) {
        p = w->pilot;
        w->stickX = 0;
        w->stickY = 0;
        w->btn = 0;
        switch (gPlayers[p].cpu_difficulty) {
        case 0:
            turnLim = 0.45f;
            stick = 0.7f;
            stop = 2000.0f;
            break;
        case 1:
            turnLim = 0.4f;
            stick = 0.8f;
            stop = 1500.0f;
            break;
        case 2:
            turnLim = 0.35f;
            stick = 0.9f;
            stop = 1000.0f;
            break;
        case 3:
            turnLim = 0.3f;
            stick = 1.0f;
            stop = 800.0f;
            break;
        }
        aim.x = D_801093B8_28B5C8_TorpedoTargets.x;
        aim.y = D_801093B8_28B5C8_TorpedoTargets.y;
        aim.z = D_801093B8_28B5C8_TorpedoTargets.z;
        func_80107DF0_28A000_TorpedoTargets(&aim, gPlayers[p].cpu_difficulty);
        dir.x = dx = aim.x - obj->trans.x;
        dir.y = dy = aim.y - (obj->trans.y - 122.5f);
        dir.z = dz = aim.z - obj->trans.z;
        func_8002D9AC_2E5AC(&dir);
        d = func_800B1830_B2430(dx * dx + dy * dy + dz * dz);
        a = w->yaw - 90.0f;
        sn = HuMathSin(a);
        a = func_8000DA2C_E62C(dx, dz, sn, func_800B7890_B8490(a));
        if (stop + 500.0f < d) {
            w->btn |= 0x8000;
        }
        if (fabs(a) > turnLim && gPlayers[p].cpu_difficulty != 0) {
            w->btn = 0x4000;
        }
        w->stickX = a * 100.0f * stick;
        w->stickY = dir.y * -100.0f * stick;
    }
}

/* Logic right; float register allocation differs. */
#ifdef NON_MATCHING
void func_80108234_28A444_TorpedoTargets(omObjData* obj) {
    TTSub* w = obj->unk_50;
    omObjData* sub;
    Vec3f f;
    Vec3f dir;
    Vec3f* pd;
    Vec aim = D_80109404_28B614_TorpedoTargets;
    s32 other;
    f32 reach;
    f32 cone;
    f32 stick;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 d;
    f32 d2;
    f32 c;
    f32 c2;
    f32 a;
    f32 sn;
    f32 k;

    if (gPlayers[w->gunner].flags & 1) {
        w->gStickX = 0;
        w->gStickY = 0;
        w->gBtn = 0;
        switch (gPlayers[w->gunner].cpu_difficulty) {
        case 0:
            reach = 4000.0f;
            cone = 0.34f;
            stick = 0.7f;
            break;
        case 1:
            reach = 4500.0f;
            cone = 0.36f;
            stick = 0.8f;
            break;
        case 2:
            reach = 5000.0f;
            cone = 0.38f;
            stick = 0.9f;
            break;
        case 3:
            reach = 6000.0f;
            cone = 0.4f;
            stick = 1.0f;
            break;
        }
        aim.x = D_801093B8_28B5C8_TorpedoTargets.x;
        aim.y = D_801093B8_28B5C8_TorpedoTargets.y;
        aim.z = D_801093B8_28B5C8_TorpedoTargets.z;
        func_80107DF0_28A000_TorpedoTargets(&aim, gPlayers[w->gunner].cpu_difficulty);
        dir.x = dx = aim.x - obj->trans.x;
        k = 122.5f;
        dir.y = dy = aim.y - (obj->trans.y - k);
        dir.z = dz = aim.z - obj->trans.z;
        pd = &dir;
        func_8002D9AC_2E5AC(pd);
        d = func_800B1830_B2430(dx * dx + dy * dy + dz * dz);
        a = w->yaw - 90.0f;
        sn = HuMathSin(a);
        c = func_8000DA2C_E62C(dx, dz, sn, func_800B7890_B8490(a));
        other = w->team == 0;
        sub = D_80109264_28B474_TorpedoTargets[other];
        dir.x = dx = sub->trans.x - obj->trans.x;
        dir.y = dy = sub->trans.y - (obj->trans.y - k);
        dir.z = dz = sub->trans.z - obj->trans.z;
        func_8002D9AC_2E5AC(pd);
        d2 = func_800B1830_B2430(dx * dx + dy * dy + dz * dz);
        a = w->yaw - 90.0f;
        sn = HuMathSin(a);
        c2 = func_8000DA2C_E62C(dx, dz, sn, func_800B7890_B8490(a));
        f.x = HuMathSin(w->yaw);
        f.y = HuMathSin(obj->rot.x);
        f.z = func_800B7890_B8490(w->yaw);
        func_8002D9AC_2E5AC(&f);
        switch (D_801092B8_28B4C8_TorpedoTargets[w->team]) {
        case 0:
            if (d < reach && fabs(c) < cone && fabs(d * f.y + obj->trans.y - aim.y) < cone * 1000.0f) {
                w->gBtn |= 0x8000;
                D_80109468_28B678_TorpedoTargets[w->team] = d;
                D_801093A0_28B5B0_TorpedoTargets[w->team] = 0;
            }
            if (w->gBtn == 0) {
                s32 level = gPlayers[w->gunner].cpu_difficulty;

                if (level < 4 && level >= 2 && d2 < reach && fabs(c2) < cone) {
                    w->gBtn |= 0x8000;
                    D_80109468_28B678_TorpedoTargets[w->team] = d2;
                    D_801093A0_28B5B0_TorpedoTargets[w->team] = 1;
                }
            }
            break;
        case 1:
            if (D_801093A0_28B5B0_TorpedoTargets[w->team] == 0) {
                dx = aim.x - D_8010926C_28B47C_TorpedoTargets[w->team].x;
                dy = aim.y - D_8010926C_28B47C_TorpedoTargets[w->team].y;
                dz = aim.z - D_8010926C_28B47C_TorpedoTargets[w->team].z;
            } else {
                dx = sub->trans.x - D_8010926C_28B47C_TorpedoTargets[w->team].x;
                dy = sub->trans.y - D_8010926C_28B47C_TorpedoTargets[w->team].y;
                dz = sub->trans.z - D_8010926C_28B47C_TorpedoTargets[w->team].z;
            }
            d2 = func_800B1830_B2430(dx * dx + dy * dy + dz * dz);
            a = w->tYaw - 90.0f;
            sn = HuMathSin(a);
            a = func_8000DA2C_E62C(dx, dz, sn, func_800B7890_B8490(a)) * 200.0f * (d2 / D_80109468_28B678_TorpedoTargets[w->team]);
            if (a > 64.0f) {
                a = 64.0f;
            }
            if (a < -64.0f) {
                a = -64.0f;
            }
            w->gStickX = a;
            w->gStickY = dir.y * -100.0f * stick;
            break;
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_3A_TorpedoTargets/289BC0", func_80108234_28A444_TorpedoTargets);
#endif
