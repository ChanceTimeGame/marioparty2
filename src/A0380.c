/* A0380: from Mario Party 1 src/lib/2.0I/audio/seqpgetprogram.c */
#include "include_asm.h"
#include <libaudio.h>

s32 alSeqpGetChlProgram(ALSeqPlayer* seqp, u8 chan) {
    s32 i;
    ALBank* b = seqp->bank;
    ALInstrument* inst;
    ALChanState s;

    s = seqp->chanState[chan];
    for (i = 0; i < b->instCount; i++) {
        inst = b->instArray[i];
        if (inst == s.instrument) {
            return i;
        }
    }
    return -1;
}
