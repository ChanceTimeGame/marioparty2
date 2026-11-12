#include "common.h"
#include "sdk_leo.h"


// leoRezero
void func_8009B3D0_9BFD0(void) {
    u8 retry = 8;
    u8 sense;

    do {
        if ((sense = func_80098164_98D64()) == 0) {
            D_800F2070_F2C70.cylinder = 0;
            D_800F2070_F2C70.head = 0;
            D_800F2070_F2C70.zone = 0;
            LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_GOOD;
            return;
        }
        if (func_80098280_98E80(sense) != 0) {
            break;
        }
    } while (retry--);
    LEO_CUR(LEOCmdHeader)->sense_code = sense;
    LEO_CUR(LEOCmdHeader)->status = LEO_STATUS_CHECK_CONDITION;
}
