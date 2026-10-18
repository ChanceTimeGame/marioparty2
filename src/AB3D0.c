/* alFilterNew: libultra audio/filter.c, from MP1 src/9ACE0.c. */
#define alFilterNew func_800AA7D0_AB3D0

#include <libaudio.h>
#include "synthInternals.h"

void alFilterNew(ALFilter* f, ALCmdHandler h, ALSetParam s, s32 type) {
    f->source = 0;
    f->handler = h;
    f->setParam = s;
    f->inp = 0;
    f->outp = 0;
    f->type = type;
}
