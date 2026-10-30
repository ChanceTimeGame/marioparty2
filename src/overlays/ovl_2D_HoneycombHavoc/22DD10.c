#include "ovl_2D.h"

/* Sets the camera (MP1 BumperBallMaze func_800F96B0). */
void func_80107240_22DD10_HoneycombHavoc(f32 fov, f32 zoom, f32 rotX, f32 rotY, f32 rotZ, f32 x, f32 y, f32 z) {
    func_80018E30_19A30(1);
    func_80018E78_19A78();
    D_800FA610_FB210 = zoom;
    D_800FD474_FE074.x = rotX;
    D_800FD474_FE074.y = rotY;
    D_800FD474_FE074.z = rotZ;
    D_8010274C_10334C.x = x;
    D_8010274C_10334C.y = y;
    D_8010274C_10334C.z = z;
    D_800C9B80_CA780->fov[0] = fov;
}

/* An empty loop over the controllers (MP1 func_800FD1B0). */
void func_801072F8_22DDC8_HoneycombHavoc(omObjData* obj) {
    s32 i;

    for (i = 0; i < gNumOfControllers; i++) {}
}

void func_80107330_22DE00_HoneycombHavoc(omObjData* obj) {
    omOvlReturnEx(1);
}
