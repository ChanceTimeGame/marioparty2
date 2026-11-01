#include "ovl_3A.h"

/* .data (0x28B5C0-0x28B5E0, 801093B0-801093D0) */
s32 D_801093B0_28B5C0_TorpedoTargets = 0;
f32 D_801093B4_28B5C4_TorpedoTargets = 0.1f;
Vec D_801093B8_28B5C8_TorpedoTargets = { 0.0f, 0.0f, 0.0f };
s32 D_801093C4_28B5D4_TorpedoTargets = 0;
s32 D_801093C8_28B5D8_TorpedoTargets = 0;
s32 D_801093CC_28B5DC_TorpedoTargets = 0;

s32 func_80108900_28AB10_TorpedoTargets(void) {
    s32 r;

    do {
        r = rand8() & 3;
    } while (r == D_80109490_28B6A0_TorpedoTargets);
    return r;
}

void func_80108934_28AB44_TorpedoTargets(void) {
    f32 s;
    f32 c;

    switch (D_801092B4_28B4C4_TorpedoTargets) {
    case 0:
        func_800298A4_2A4A4(D_8010949C_28B6AC_TorpedoTargets, 4, 0);
        func_8002D0A0_2DCA0(D_8010949C_28B6AC_TorpedoTargets, D_801093B3_28B5C3_TorpedoTargets);
        if (D_801093B0_28B5C0_TorpedoTargets == 0) {
            D_80109490_28B6A0_TorpedoTargets = func_80108900_28AB10_TorpedoTargets();
            switch (D_80109490_28B6A0_TorpedoTargets) {
            case 0:
                D_80109478_28B688_TorpedoTargets = (rand8() & 0xFF) * 1.40625f;
                D_8010947C_28B68C_TorpedoTargets = (rand8() & 0xFF) * 3.0f;
                D_80109474_28B684_TorpedoTargets = (rand8() & 0xFF) * 15;
                if (D_80109474_28B684_TorpedoTargets > 3000.0f) {
                    D_80109474_28B684_TorpedoTargets = 2500.0f;
                }
                if (D_80109474_28B684_TorpedoTargets < 1500.0f) {
                    D_80109474_28B684_TorpedoTargets = 1500.0f;
                }
                D_801093B8_28B5C8_TorpedoTargets.x = HuMathSin(D_80109478_28B688_TorpedoTargets) * D_80109474_28B684_TorpedoTargets;
                D_801093B8_28B5C8_TorpedoTargets.y = HuMathSin(D_80109478_28B688_TorpedoTargets) * 50.0f + D_8010947C_28B68C_TorpedoTargets;
                D_801093B8_28B5C8_TorpedoTargets.z = func_800B7890_B8490(D_80109478_28B688_TorpedoTargets) * D_80109474_28B684_TorpedoTargets;
                break;
            case 1:
                D_80109478_28B688_TorpedoTargets = (rand8() & 0xFF) * 1.40625f;
                D_8010947C_28B68C_TorpedoTargets = rand8() & 0xFF;
                D_8010948C_28B69C_TorpedoTargets = (rand8() & 0xFF) / 30.0f + D_801093C4_28B5D4_TorpedoTargets;
                if (D_8010948C_28B69C_TorpedoTargets < 5.0f) {
                    D_8010948C_28B69C_TorpedoTargets = 5.0f;
                }
                s = HuMathSin(D_80109478_28B688_TorpedoTargets);
                D_801093B8_28B5C8_TorpedoTargets.x = s * (rand8() & 0xFF) * 6.0f;
                D_801093B8_28B5C8_TorpedoTargets.y = D_8010947C_28B68C_TorpedoTargets;
                c = func_800B7890_B8490(D_80109478_28B688_TorpedoTargets);
                D_801093B8_28B5C8_TorpedoTargets.z = c * (rand8() & 0xFF) * 6.0f;
                break;
            case 2:
                D_80109480_28B690_TorpedoTargets.x = rand8() & 0xFF;
                D_80109480_28B690_TorpedoTargets.y = (rand8() & 0xFF) / 20.0f;
                D_80109480_28B690_TorpedoTargets.z = rand8() & 0xFF;
                D_8010947C_28B68C_TorpedoTargets = (rand8() & 0xFF) * 3.0f;
                D_80109478_28B688_TorpedoTargets = (rand8() & 0xFF) * 1.40625f;
                func_8002D9AC_2E5AC((Vec3f*)&D_80109480_28B690_TorpedoTargets);
                D_80109470_28B680_TorpedoTargets = D_801093C4_28B5D4_TorpedoTargets + 3.0f;
                D_801093B8_28B5C8_TorpedoTargets.x = HuMathSin(D_80109478_28B688_TorpedoTargets) * 2000.0f;
                D_801093B8_28B5C8_TorpedoTargets.y = D_8010947C_28B68C_TorpedoTargets;
                D_801093B8_28B5C8_TorpedoTargets.z = func_800B7890_B8490(D_80109478_28B688_TorpedoTargets) * 2000.0f;
                break;
            case 3:
                {
                    s32 r = rand8() & 3;

                    D_801093B8_28B5C8_TorpedoTargets.x = D_80109284_28B494_TorpedoTargets[r].x;
                    D_801093B8_28B5C8_TorpedoTargets.y = D_80109284_28B494_TorpedoTargets[r].y + 200.0f;
                    D_801093B8_28B5C8_TorpedoTargets.z = D_80109284_28B494_TorpedoTargets[r].z;
                }
                break;
            }
            D_801093C4_28B5D4_TorpedoTargets += 2;
            D_801093B4_28B5C4_TorpedoTargets += 0.025f;
        }
        D_801093B0_28B5C0_TorpedoTargets += 0x10;
        if (D_801093B0_28B5C0_TorpedoTargets >= 0x100) {
            D_801093B0_28B5C0_TorpedoTargets = 0xFF;
            D_801092B4_28B4C4_TorpedoTargets = 1;
        }
        break;
    case 1:
        switch (D_80109490_28B6A0_TorpedoTargets) {
        case 0:
            func_80108F94_28B1A4_TorpedoTargets(1, &D_801093B8_28B5C8_TorpedoTargets);
            D_80109478_28B688_TorpedoTargets = func_8002D958_2E558(D_80109478_28B688_TorpedoTargets + D_801093B4_28B5C4_TorpedoTargets);
            break;
        case 1:
            func_80109060_28B270_TorpedoTargets(1, &D_801093B8_28B5C8_TorpedoTargets);
            break;
        case 2:
            func_801090F8_28B308_TorpedoTargets(1, (f32*)&D_801093B8_28B5C8_TorpedoTargets);
            break;
        case 3:
            func_801091F0_28B400_TorpedoTargets(1, &D_801093B8_28B5C8_TorpedoTargets);
            break;
        }
        break;
    default:
        func_800298A4_2A4A4(D_8010949C_28B6AC_TorpedoTargets, 4, 4);
        D_801092B4_28B4C4_TorpedoTargets++;
        D_801093B0_28B5C0_TorpedoTargets = 0;
        break;
    }
    func_80029714_2A314(D_8010949C_28B6AC_TorpedoTargets, D_801093B8_28B5C8_TorpedoTargets.x, D_801093B8_28B5C8_TorpedoTargets.y,
                        D_801093B8_28B5C8_TorpedoTargets.z);
}

void func_80108F94_28B1A4_TorpedoTargets(s32 n, Vec* out) {
    f32 t = n;
    f32 a = t * 0.1f;

    out->x = HuMathSin(a + D_80109478_28B688_TorpedoTargets) * D_80109474_28B684_TorpedoTargets;
    out->y = HuMathSin(t * D_801093B4_28B5C4_TorpedoTargets + D_80109478_28B688_TorpedoTargets) * 50.0f + D_8010947C_28B68C_TorpedoTargets;
    out->z = func_800B7890_B8490(a + D_80109478_28B688_TorpedoTargets) * D_80109474_28B684_TorpedoTargets;
}

void func_80109060_28B270_TorpedoTargets(s32 n, Vec* out) {
    s32 i;

    out->x = D_801093B8_28B5C8_TorpedoTargets.x;
    out->z = D_801093B8_28B5C8_TorpedoTargets.z;
    for (i = 0; i < n; i++) {
        out->y += D_8010948C_28B69C_TorpedoTargets;
        if (out->y > 1000.0f || out->y < -1000.0f) {
            D_8010948C_28B69C_TorpedoTargets = -D_8010948C_28B69C_TorpedoTargets;
        }
    }
}

void func_801090F8_28B308_TorpedoTargets(s32 n, f32* out) {
    s32 i;

    for (i = 0; i < n; i++) {
        out[0] += D_80109480_28B690_TorpedoTargets.x * D_80109470_28B680_TorpedoTargets;
        out[1] += D_80109480_28B690_TorpedoTargets.y * D_80109470_28B680_TorpedoTargets;
        out[2] += D_80109480_28B690_TorpedoTargets.z * D_80109470_28B680_TorpedoTargets;
        if (func_800B1830_B2430(out[0] * out[0] + out[2] * out[2]) > 2500.0f) {
            D_80109470_28B680_TorpedoTargets = -D_80109470_28B680_TorpedoTargets;
        }
    }
}

void func_801091F0_28B400_TorpedoTargets(s32 n, Vec* out) {
    out->x = D_801093B8_28B5C8_TorpedoTargets.x;
    out->y = D_801093B8_28B5C8_TorpedoTargets.y;
    out->z = D_801093B8_28B5C8_TorpedoTargets.z;
}

void func_80109214_28B424_TorpedoTargets(void) {
    D_801093B0_28B5C0_TorpedoTargets -= 0x10;
    if (D_801093B0_28B5C0_TorpedoTargets < 0) {
        D_801093B0_28B5C0_TorpedoTargets = 0;
    }
    func_8002D0A0_2DCA0(D_8010949C_28B6AC_TorpedoTargets, D_801093B3_28B5C3_TorpedoTargets);
}
