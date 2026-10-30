#include "ovl_1E.h"

void func_801079B0_1BDFA0_CakeFactory(s16 cam, f32 zoom, f32 rx, f32 ry, f32 rz, f32 cx, f32 cy, f32 cz) {
    D_800F94A8_FA0A8[cam] = zoom;
    D_80102770_103370[cam].x = rx;
    D_80102770_103370[cam].y = ry;
    D_80102770_103370[cam].z = rz;
    D_801013B0_101FB0[cam].x = cx;
    D_801013B0_101FB0[cam].y = cy;
    D_801013B0_101FB0[cam].z = cz;
}
