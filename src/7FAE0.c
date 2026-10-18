/* The libultra audio functions this unit calls are still auto-named in MP2 (their units belong to
   the libultra batch); map libultra's names onto them until those units name them. */
#define alHeapDBAlloc func_8009EBB0_9F7B0
#define alEvtqNew func_8009E770_9F370
#define alEvtqNextEvent func_8009E7EC_9F3EC
#define alEvtqPostEvent func_8009E884_9F484
#define alLink func_8009EB1C_9F71C
#define alUnlink func_8009EB3C_9F73C
#define alSynAddPlayer func_800A15C0_A21C0
#define alGlobals D_800CDE50_CEA50

#include "common.h"
#include "lib/2.0I/audio/sndp.h"

/* Sound player (libultra audio sndplayer.c; MP1 src/64FD0.c). MP1's names are anonymous. */

ALMicroTime func_8007F020_7FC20(void* node);
void func_8007F0B4_7FCB4(ALSndPlayer* sndp, ALSndpEvent* event);
void func_8007F52C_8012C(ALEventQueue* evtq, ALSoundState* state);

void func_8007EEE0_7FAE0(ALSndPlayer* sndp, ALSndpConfig* c) {
    ALEvent evt;
    ALSoundState* sState;
    u32 i;
    u8* ptr;

    sndp->maxSounds = c->maxSounds;
    sndp->target = -1;
    sndp->frameTime = AL_USEC_PER_FRAME;
    sState = alHeapAlloc(c->heap, 1, c->maxSounds * sizeof(ALSoundState));
    sndp->sndState = sState;
    for (i = 0; i < c->maxSounds; i++) {
        sState[i].sound = NULL;
    }
    ptr = alHeapAlloc(c->heap, 1, c->maxEvents * sizeof(ALEventListItem));
    alEvtqNew(&sndp->evtq, (ALEventListItem*)ptr, c->maxEvents);
    sndp->drvr = &alGlobals->drvr;
    sndp->node.next = NULL;
    sndp->node.handler = func_8007F020_7FC20;
    sndp->node.clientData = sndp;
    alSynAddPlayer(sndp->drvr, &sndp->node);
    evt.type = AL_SNDP_API_EVT;
    alEvtqPostEvent(&sndp->evtq, &evt, sndp->frameTime);
    sndp->nextDelta = alEvtqNextEvent(&sndp->evtq, &sndp->nextEvent);
}
ALMicroTime func_8007F020_7FC20(void* node) {
    ALSndPlayer* sndp = (ALSndPlayer*)node;
    ALSndpEvent evt;

    do {
        switch (sndp->nextEvent.type) {
        case AL_SNDP_API_EVT:
            evt.common.type = AL_SNDP_API_EVT;
            evt.common.state = (ALSoundState*)-1;
            alEvtqPostEvent(&sndp->evtq, (ALEvent*)&evt, sndp->frameTime);
            break;
        default:
            func_8007F0B4_7FCB4(sndp, (ALSndpEvent*)&sndp->nextEvent);
            break;
        }
        sndp->nextDelta = alEvtqNextEvent(&sndp->evtq, &sndp->nextEvent);
    } while (sndp->nextDelta == 0);
    sndp->curTime += sndp->nextDelta;
    return sndp->nextDelta;
}
INCLUDE_ASM("asm/nonmatchings/7FAE0", func_8007F0B4_7FCB4);

void func_8007F52C_8012C(ALEventQueue* evtq, ALSoundState* state) {
    ALLink* thisNode;
    ALLink* nextNode;
    ALEventListItem* thisItem;
    ALEventListItem* nextItem;
    ALSndpEvent* thisEvent;
    OSIntMask mask;

    mask = osSetIntMask(OS_IM_NONE);
    thisNode = evtq->allocList.next;
    while (thisNode != NULL) {
        nextNode = thisNode->next;
        thisItem = (ALEventListItem*)thisNode;
        nextItem = (ALEventListItem*)nextNode;
        thisEvent = (ALSndpEvent*)&thisItem->evt;
        if (thisEvent->common.state == state) {
            if (nextItem != NULL) {
                nextItem->delta += thisItem->delta;
            }
            alUnlink(thisNode);
            alLink(thisNode, &evtq->freeList);
        }
        thisNode = nextNode;
    }
    osSetIntMask(mask);
}
INCLUDE_ASM("asm/nonmatchings/7FAE0", func_8007F5D4_801D4);
