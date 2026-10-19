/* The libultra audio functions this unit calls are still auto-named in MP2 (their units belong to
   the libultra batch); map libultra's names onto them until those units name them. */
#define alSynSetPan func_80092C90_93890

#include "common.h"
#include "lib/2.0I/audio/sndp.h"

/* Sound player (libultra audio sndplayer.c; MP1 src/64FD0.c). MP1's names are anonymous. */

ALMicroTime func_8007F020_7FC20(void* node);
void func_8007F0B4_7FCB4(ALSndPlayer* sndp, ALSndpEvent* event);
void func_8007F52C_8012C(ALEventQueue* evtq, ALSoundState* state);
s32 func_8007F5D4_801D4(s32 i, f32 f);

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
void func_8007F0B4_7FCB4(ALSndPlayer* sndp, ALSndpEvent* event) {
    ALVoiceConfig vc;
    ALSndpEvent evt;
    ALSound* snd;
    ALSoundState* state;
    ALVoice* voice;
    s16 vol;
    s32 decayVol;
    s16 tmp;
    s16 pan;
    s32 delta;
    f32 pitch;

    state = event->common.state;
    snd = state->sound;
    switch (event->msg.type) {
    case AL_SNDP_PLAY_EVT:
        if (state->state != AL_STOPPED || snd == NULL) {
            return;
        }
        voice = &state->voice;
        vc.fxBus = 0;
        vc.priority = state->priority;
        vc.unityPitch = 0;
        alSynAllocVoice(sndp->drvr, voice, &vc);
        vol = (snd->envelope->attackVolume * state->vol) / AL_VOL_FULL;
        tmp = state->pan - AL_PAN_CENTER + snd->samplePan;
        tmp = MAX(tmp, AL_PAN_LEFT);
        pan = MIN(tmp, AL_PAN_RIGHT);
        pitch = state->pitch;
        delta = snd->envelope->attackTime;
        alSynStartVoice(sndp->drvr, voice, snd->wavetable);
        state->state = AL_PLAYING;
        alSynSetPan(sndp->drvr, voice, pan);
        alSynSetVol(sndp->drvr, voice, vol, delta);
        alSynSetPitch(sndp->drvr, voice, pitch);
        alSynSetFXMix(sndp->drvr, voice, state->fxMix);
        evt.common.type = AL_SNDP_DECAY_EVT;
        evt.common.state = state;
        alEvtqPostEvent(&sndp->evtq, (ALEvent*)&evt, func_8007F5D4_801D4(snd->envelope->attackTime, state->pitch));
        break;
    case AL_SNDP_STOP_EVT:
        if (state->state != AL_PLAYING || snd == NULL) {
            return;
        }
        delta = func_8007F5D4_801D4(snd->envelope->releaseTime, state->pitch);
        alSynSetVol(sndp->drvr, &state->voice, 0, delta);
        if (delta) {
            evt.common.type = AL_SNDP_END_EVT;
            evt.common.state = state;
            alEvtqPostEvent(&sndp->evtq, (ALEvent*)&evt, delta);
            state->state = AL_STOPPING;
        } else {
            alSynStopVoice(sndp->drvr, &state->voice);
            alSynFreeVoice(sndp->drvr, &state->voice);
            func_8007F52C_8012C(&sndp->evtq, state);
            state->state = AL_STOPPED;
        }
        break;
    case AL_SNDP_PAN_EVT:
        state->pan = event->pan.pan;
        if (state->state == AL_PLAYING && snd != NULL) {
            tmp = state->pan - AL_PAN_CENTER + snd->samplePan;
            tmp = MAX(tmp, AL_PAN_LEFT);
            pan = MIN(tmp, AL_PAN_RIGHT);
            alSynSetPan(sndp->drvr, &state->voice, pan);
        }
        break;
    case AL_SNDP_PITCH_EVT:
        if ((state->pitch = event->pitch.pitch) < MIN_RATIO) {
            state->pitch = MIN_RATIO;
        }
        if (state->state == AL_PLAYING) {
            alSynSetPitch(sndp->drvr, &state->voice, state->pitch);
        }
        break;
    case AL_SNDP_FX_EVT:
        state->fxMix = event->fx.mix;
        if (state->state == AL_PLAYING) {
            alSynSetFXMix(sndp->drvr, &state->voice, state->fxMix);
        }
        break;
    case AL_SNDP_VOL_EVT:
        state->vol = event->vol.vol;
        if (state->state == AL_PLAYING && snd != NULL) {
            decayVol = (snd->envelope->decayVolume * state->vol) / AL_VOL_FULL;
            alSynSetVol(sndp->drvr, &state->voice, (s16)decayVol, AL_GAIN_CHANGE_TIME);
        }
        break;
    case AL_SNDP_DECAY_EVT:
        if (snd->envelope->decayTime != -1) {
            decayVol = (snd->envelope->decayVolume * state->vol) / AL_VOL_FULL;
            delta = func_8007F5D4_801D4(snd->envelope->decayTime, state->pitch);
            alSynSetVol(sndp->drvr, &state->voice, (s16)decayVol, delta);
            evt.common.type = AL_SNDP_STOP_EVT;
            evt.common.state = state;
            alEvtqPostEvent(&sndp->evtq, (ALEvent*)&evt, delta);
        }
        break;
    case AL_SNDP_END_EVT:
        alSynStopVoice(sndp->drvr, &state->voice);
        alSynFreeVoice(sndp->drvr, &state->voice);
        func_8007F52C_8012C(&sndp->evtq, state);
        state->state = AL_STOPPED;
        break;
    default:
        break;
    }
}


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
/* MP1's func_80064AC4 without its divide-by-zero report. */
s32 func_8007F5D4_801D4(s32 i, f32 f) {
    f64 rd;
    s32 ri;

    rd = i / f;
    if (rd > 2147483647) {
        ri = 2147483647;
    } else {
        ri = rd;
    }
    return ri;
}
