/* 9D840: from Mario Party 1 src/lib/2.0I/io/conteeplongread.c */
#include "include_asm.h"
#include "PR/os_internal.h"

#include "controller.h"

s32 osEepromLongRead(OSMesgQueue *mq, u8 address, u8 *buffer, int length) {
    s32 ret = 0;

    while (length > 0) {
        ERRCK(osEepromRead(mq, address, buffer));
        length -= EEPROM_BLOCK_SIZE;
        address++;
        buffer += EEPROM_BLOCK_SIZE;
    }
    
    return ret;
}

INCLUDE_ASM("asm/nonmatchings/9D840", func_8009CCB0_9D8B0);
