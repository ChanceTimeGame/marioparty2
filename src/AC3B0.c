/* AC3B0: libultra audio/save.c (alSavePull, alSaveParam; MP1 src/98B20.c) and audio/seqplayer.c
   (MP1 src/lib/2.0I/audio/seqplayer.c; no __lookupSound here). __seqpVoiceHandler and
   __handleNextSeqEvent stay in asm (not exact matches of MP1; the voice handler owns the jump table
   at D5350, left in the data blob). */
#define alSavePull func_800AB7B0_AC3B0
#define alSeqpNew func_800AB880_AC480
#define __seqpVoiceHandler func_800ABA04_AC604
#define __postNextSeqEvent func_800ABED8_ACAD8
#define __handleNextSeqEvent func_800ABFA8_ACBA8
#define __handleMIDIMsg func_800AC1A8_ACDA8
#define __handleMetaMsg func_800AC9D0_AD5D0
#define __mapVoice func_800ACA3C_AD63C
#define __unmapVoice func_800ACA8C_AD68C
#define __lookupVoice func_800ACAF0_AD6F0
#define __lookupSoundQuick func_800ACB44_AD744
#define __vsVol func_800ACC18_AD818
#define __vsDelta func_800ACC88_AD888
#define __vsPan func_800ACCA4_AD8A4
#define __seqpReleaseVoice func_800ACCE8_AD8E8
#define __voiceNeedsNoteKill func_800ACE0C_ADA0C
#define __initFromBank func_800ACEBC_ADABC
#define __setInstChanState func_800ACF68_ADB68
#define __resetPerfChanState func_800ACFBC_ADBBC
#define __initChanState func_800AD03C_ADC3C
#define __seqpStopOsc func_800AD0F0_ADCF0
#define __setUsptFromTempo func_800AD1E0_ADDE0
#define alSynStartVoiceParams func_80092AF0_936F0
#define alSynSetPan func_80092C90_93890
#define alSynSetPriority func_800AD220_ADE20
#define alSeqGetTicks func_800AF634_B0234

#include <libaudio.h>
#include <os_internal.h>
#include <ultraerror.h>
#include <libc/assert.h>
#include "synthInternals.h"
#include "seqp.h"
#include "seq.h"
#include "include_asm.h"

ALMicroTime     __seqpVoiceHandler(void *node);
void            __handleMIDIMsg(ALSeqPlayer *seqp, ALEvent *event);
void            __handleMetaMsg(ALSeqPlayer *seqp, ALEvent *event);
void            __handleNextSeqEvent(ALSeqPlayer *seqp);
void            __setUsptFromTempo(ALSeqPlayer *seqp, f32 tempo);

Acmd *alSavePull(void *filter, s16 *outp, s32 outCount, s32 sampleOffset,
                 Acmd *p) 
{
    Acmd        *ptr = p;
    ALSave *f = (ALSave *)filter;
    ALFilter    *source = f->filter.source;

    ptr = (*source->handler)(source, outp, outCount, sampleOffset, ptr);

    aSetBuffer (ptr++, 0, 0, 0, outCount<<1);
    aInterleave(ptr++, AL_MAIN_L_OUT, AL_MAIN_R_OUT);
    aSetBuffer (ptr++, 0, 0, 0, outCount<<2);
    aSaveBuffer(ptr++, f->dramout);
    return ptr;
}

s32 alSaveParam(void *filter, s32 paramID, void *param)
{
    ALSave *a = (ALSave *) filter;
    ALFilter *f = (ALFilter *) filter;
    s32 pp = (s32) param;

    switch (paramID) {
        case (AL_FILTER_SET_SOURCE):
            f->source = (ALFilter *) param;
            break;

        case (AL_FILTER_SET_DRAM): 
            a->dramout = pp;
            break;

        default:
            break;
    }
    return 0;

}

void alSeqpNew(ALSeqPlayer *seqp, ALSeqpConfig *c)
{
    s32                 i;
    ALEventListItem     *items;
    ALVoiceState        *vs;
    ALVoiceState        *voices;
    ALHeap *hp = c->heap;    
    
    /*
     * initialize member variables
     */
    seqp->bank          = 0;
    seqp->target        = NULL;
    seqp->drvr          = &alGlobals->drvr;
    seqp->chanMask      = 0xff;
    seqp->uspt          = 488;
    seqp->nextDelta     = 0;
    seqp->state         = AL_STOPPED;
    seqp->vol           = 0x7FFF;                  /* full volume  */
    seqp->debugFlags    = c->debugFlags;
    seqp->frameTime     = AL_USEC_PER_FRAME; /* should get this from driver */
    seqp->curTime       = 0;
    seqp->initOsc       = c->initOsc;
    seqp->updateOsc     = c->updateOsc;
    seqp->stopOsc       = c->stopOsc;
    seqp->loopStart = 0;
    seqp->loopEnd   = 0;
    seqp->loopCount = 0;      /* -1 = loop forever, 0 = no loop   */
    
    seqp->nextEvent.type = AL_SEQP_API_EVT; /* start the voice handler "spinning" */
    
    /*
     * init the channel state
     */
    seqp->maxChannels = c->maxChannels;
    seqp->chanState = alHeapAlloc(hp, c->maxChannels, sizeof(ALChanState) );
    __initChanState(seqp);	/* sct 11/6/95 */
    
    /*
     * init the voice state array
     */
    voices = alHeapAlloc(hp, c->maxVoices, sizeof(ALVoiceState));
    seqp->vFreeList = 0;
    for (i = 0; i < c->maxVoices; i++) {
        vs = &voices[i];
        vs->next = seqp->vFreeList;
        seqp->vFreeList = vs;        
    }
    
    seqp->vAllocHead = 0;
    seqp->vAllocTail = 0;    
        
    /*
     * init the event queue
     */
    items = alHeapAlloc(hp, c->maxEvents, sizeof(ALEventListItem));
    alEvtqNew(&seqp->evtq, items, c->maxEvents);

    /*
     * add ourselves to the driver
     */
    seqp->node.next       = NULL;
    seqp->node.handler    = __seqpVoiceHandler;
    seqp->node.clientData = seqp;
    alSynAddPlayer(&alGlobals->drvr, &seqp->node);
}

INCLUDE_ASM("asm/nonmatchings/AC3B0", func_800ABA04_AC604);

void __postNextSeqEvent(ALSeqPlayer *seqp) 
{
    ALEvent     evt;
    s32		deltaTicks;
    ALSeq       *seq = seqp->target;

    /* sct 1/5/96 - Do nothing if we're not playing or don't have a target sequence. */
    if ((seqp->state != AL_PLAYING) || (seq == NULL))
	return;

    /* Get the next event time in ticks. */
    /* If false is returned, then there is no next delta (ie. end of sequence reached). */
    if (!__alSeqNextDelta(seq, &deltaTicks))
	return;

    /* Handle loops. */
    if (seqp->loopCount)
    {
        /* Assume that the loop end falls on a MIDI event. Delta time
           will be correct even if we loop */
        if (alSeqGetTicks(seq) + deltaTicks >= seqp->loopEnd->curTicks)
	{
	    alSeqSetLoc(seq, seqp->loopStart);            

	    if (seqp->loopCount != -1)
		seqp->loopCount--;
	}
    }    

    evt.type = AL_SEQ_REF_EVT;
    alEvtqPostEvent(&seqp->evtq, &evt, deltaTicks * seqp->uspt);
}

INCLUDE_ASM("asm/nonmatchings/AC3B0", func_800ABFA8_ACBA8);

void __handleMIDIMsg(ALSeqPlayer *seqp, ALEvent *event)
{
    ALVoice             *voice;
    ALVoiceState        *vs;
    s32                 status;
    u8                  chan;
    u8                  key;
    u8                  vel;
    u8                  byte1;
    u8                  byte2;
    ALMIDIEvent         *midi = &event->msg.midi;
    s16                 vol;
    ALEvent             evt;
    ALMicroTime         deltaTime;
    ALVoiceState        *vstate;
    ALPan   		    pan;
    ALFxRef		        fxref;

    /* sct 12/15/95 - Fixed assert to also allow seqp midi event types. */
    assert(event->type == AL_SEQ_MIDI_EVT || event->type == AL_SEQP_MIDI_EVT);
    
    status = midi->status & AL_MIDI_StatusMask;
    chan = midi->status & AL_MIDI_ChannelMask;
    byte1 = key  = midi->byte1;
    byte2 = vel  = midi->byte2;

    switch (status) {

        case (AL_MIDI_NoteOn):
            
            if (vel != 0) {		/* a real note on */
                ALVoiceConfig   config;
                ALSound         *sound;                    
                s16             cents;
                f32             pitch,oscValue;
                u8              fxmix;
                void            *oscState;
                ALInstrument    *inst;

		/* If we're not playing, don't process note ons. */
		if (seqp->state != AL_PLAYING)
		    break;

                sound = __lookupSoundQuick(seqp, key, vel, chan);
                ALFlagFailIf(!sound, seqp->debugFlags & NO_SOUND_ERR_MASK,
			   ERR_ALSEQP_NO_SOUND);
                
                config.priority = seqp->chanState[chan].priority;
                config.fxBus    = 0;
                config.unityPitch = 0;

                vstate = __mapVoice(seqp, key, vel, chan);
                ALFlagFailIf(!vstate, seqp->debugFlags & NO_VOICE_ERR_MASK,
			 ERR_ALSEQP_NO_VOICE );

                voice = &vstate->voice;
                
                alSynAllocVoice(seqp->drvr, voice, &config);

                /*
                 * set up the voice state structure
                 */
                vstate->sound = sound;
                vstate->envPhase = AL_PHASE_ATTACK;
                if (seqp->chanState[chan].sustain > AL_SUSTAIN)
                    vstate->phase = AL_PHASE_SUSTAIN;
                else
                    vstate->phase = AL_PHASE_NOTEON;
                
                cents = (key - sound->keyMap->keyBase) * 100
                    + sound->keyMap->detune;
                
                vstate->pitch = alCents2Ratio(cents);
                vstate->envGain = sound->envelope->attackVolume;
                vstate->envEndTime = seqp->curTime +
                    sound->envelope->attackTime;

                /*
                 * setup tremelo and vibrato if active
                 */
                vstate->flags = 0;
                inst = seqp->chanState[chan].instrument;

                oscValue = (f32)AL_VOL_FULL; /* set this as a default */

                if(inst->tremType)
                {
                    if(seqp->initOsc)
                    {
                        deltaTime = (*seqp->initOsc)(&oscState,&oscValue,
                                                     inst->tremType,
                                                     inst->tremRate,
                                                     inst->tremDepth,
                                                     inst->tremDelay);

                        if(deltaTime) /* if deltaTime = zero, don't run osc */
                        {
                            evt.type = AL_TREM_OSC_EVT;
                            evt.msg.osc.vs = vstate;
                            evt.msg.osc.oscState = oscState;
                            alEvtqPostEvent(&seqp->evtq, &evt, deltaTime);
                            vstate->flags |= 0x01; /* set tremelo flag bit */
                        }
                    }
                }
                /* will default if not changed by initOsc */
                vstate->tremelo = (u8)oscValue;
                
                oscValue = 1.0f; /* set this as a default */
                if(inst->vibType)
                {
                    if(seqp->initOsc)
                    {
                        deltaTime = (*seqp->initOsc)(&oscState,&oscValue,
                                                     inst->vibType,
                                                     inst->vibRate,
                                                     inst->vibDepth,
                                                     inst->vibDelay);

                        if(deltaTime)  /* if deltaTime = zero,don't run osc. */
                        {
                            evt.type = AL_VIB_OSC_EVT;
                            evt.msg.osc.vs = vstate;
                            evt.msg.osc.oscState = oscState;
                            evt.msg.osc.chan = chan;
                            alEvtqPostEvent(&seqp->evtq, &evt, deltaTime);
                            vstate->flags |= 0x02; /* set the vibrato flag bit */
                        }
                    }
                }
                /* will default if not changed by initOsc */
                vstate->vibrato = oscValue;

                /*
                 * calculate the note on parameters
                 */
                pitch = vstate->pitch * seqp->chanState[chan].pitchBend *
                    vstate->vibrato;
                fxmix = seqp->chanState[chan].fxmix;
                pan   = __vsPan(vstate, seqp);
                vol   = __vsVol(vstate, seqp);
                deltaTime  = sound->envelope->attackTime;

                alSynStartVoiceParams(seqp->drvr, voice, sound->wavetable,
                                      pitch, vol, pan, fxmix, deltaTime);
                /*
                 * set up callbacks for envelope
                 */
                evt.type          = AL_SEQP_ENV_EVT;
                evt.msg.vol.voice = voice;
                evt.msg.vol.vol   = sound->envelope->decayVolume;
                evt.msg.vol.delta = sound->envelope->decayTime;
                deltaTime = sound->envelope->attackTime;
                
                alEvtqPostEvent(&seqp->evtq, &evt, deltaTime);

                break;
            }

            /*
             * NOTE: intentional fall-through for note on with zero
             * velocity
             */
            
        case (AL_MIDI_NoteOff):
            vstate = __lookupVoice(seqp, key, chan);
            ALFlagFailIf(!vstate, (seqp->debugFlags & NOTE_OFF_ERR_MASK),
		       ERR_ALSEQP_OFF_VOICE );

            if (vstate->phase == AL_PHASE_SUSTAIN)
                vstate->phase = AL_PHASE_SUSTREL;
            else {
                vstate->phase = AL_PHASE_RELEASE;
                __seqpReleaseVoice(seqp, &vstate->voice,
				   vstate->sound->envelope->releaseTime);
            }

            break;
            
        case (AL_MIDI_PolyKeyPressure):
	    /*
	     * Aftertouch per key (hardwired to volume). Note that
	     * aftertouch affects only notes that are already
	     * sounding.
             */
	    vstate = __lookupVoice(seqp, key, chan);
	    ALFailIf(!vstate,  ERR_ALSEQP_POLY_VOICE );

	    vstate->velocity = byte2;
	    alSynSetVol(seqp->drvr, &vstate->voice, __vsVol(vstate, seqp),
			__vsDelta(vstate, seqp->curTime));
	    break;

        case (AL_MIDI_ChannelPressure):
	    /*
             * Aftertouch per channel (hardwired to volume). Note that
             * aftertouch affects only notes that are already
             * sounding.
             */
	    for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
		if (vs->channel == chan) {
		    vs->velocity = byte1;
		    alSynSetVol(seqp->drvr, &vs->voice, __vsVol(vs, seqp),
				__vsDelta(vs, seqp->curTime));
		}
	    }
            break;
            
        case (AL_MIDI_ControlChange):

	    switch (byte1) {
		  
	    case (AL_MIDI_PAN_CTRL):
		seqp->chanState[chan].pan = byte2;
		for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
		    if (vs->channel == chan) {
			pan = __vsPan(vs, seqp);
			alSynSetPan(seqp->drvr, &vs->voice, pan);
		    }
		}
		break;

	    case (AL_MIDI_VOLUME_CTRL):
		seqp->chanState[chan].vol = byte2;
		for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
		    if ((vs->channel == chan) &&
			(vs->envPhase != AL_PHASE_RELEASE))
		    {
			vol = __vsVol(vs, seqp);
			alSynSetVol(seqp->drvr, &vs->voice, vol,
				    __vsDelta(vs, seqp->curTime));
		    }
		}
		break;
            case (AL_MIDI_PRIORITY_CTRL):
		/* leave current voices where they are */
		seqp->chanState[chan].priority = byte2;
		break;
	    case (AL_MIDI_SUSTAIN_CTRL):
		seqp->chanState[chan].sustain = byte2;
		for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
		    if ((vs->channel == chan) &&
			(vs->phase != AL_PHASE_RELEASE)) {
			if ( byte2 > AL_SUSTAIN ) {
			    /*
			     * sustain pedal down
			     */
			    if (vs->phase == AL_PHASE_NOTEON)
				vs->phase = AL_PHASE_SUSTAIN;
			} else {
			    /*
			     * sustain pedal up
			     */
			    if (vs->phase == AL_PHASE_SUSTAIN)
				vs->phase = AL_PHASE_NOTEON;
			    else if(vs->phase == AL_PHASE_SUSTREL) {
				vs->phase = AL_PHASE_RELEASE;
				__seqpReleaseVoice(seqp, &vs->voice,
						   vs->sound->envelope->releaseTime);
			    }
			}
		    }
		}
		break;
	    
	    case (AL_MIDI_FX1_CTRL):
		seqp->chanState[chan].fxmix = byte2;
		for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
		    if (vs->channel == chan) {
			alSynSetFXMix(seqp->drvr, &vs->voice, byte2);
		    }
		}
		break;

	    case (AL_MIDI_FX_CTRL_0):
	    case (AL_MIDI_FX_CTRL_1):
	    case (AL_MIDI_FX_CTRL_2):
	    case (AL_MIDI_FX_CTRL_3):
	    case (AL_MIDI_FX_CTRL_4):
	    case (AL_MIDI_FX_CTRL_5):
	    case (AL_MIDI_FX_CTRL_6):
	    case (AL_MIDI_FX_CTRL_7):
#if 0	/* fx control not implemented */      
		fxref = alSynGetFXRef(seqp->drvr, 0, 0);
		if (fxref)
		    alSynSetFXParam(seqp->drvr, fxref, (s16)byte1, (void *)byte2);
		break;
#endif
	    case (AL_MIDI_FX3_CTRL):
	    default:
		break;

	    }
            break;

        case (AL_MIDI_ProgramChange):
	    /* sct 1/16/96 - We must have a valid bank in order to process the program change. */
	    assert(seqp->bank != NULL);

            if (key < seqp->bank->instCount) {
                ALInstrument *inst = seqp->bank->instArray[key];
                __setInstChanState(seqp, inst, chan);        /* sct 11/6/95 */
            }
#ifdef _DEBUG
	    else
		__osError(ERR_ALSEQPINVALIDPROG, 2, key, seqp->bank->instCount);
#endif                
            break;
            
        case (AL_MIDI_PitchBendChange):
	    {
		s32 bendVal;
		f32 bendRatio;
		s32 cents;
                
		/*
                 * get 14-bit unsigned midi value
                 */
                bendVal = ( (byte2 << 7) + byte1) - 8192;

                /*
                 * calculate pitch bend in cents
                 */
                cents = (seqp->chanState[chan].bendRange * bendVal)/8192;

                /*
                 * calculate the corresponding ratio
                 */
                bendRatio = alCents2Ratio(cents);
                seqp->chanState[chan].pitchBend = bendRatio;
                
                for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
                    if (vs->channel == chan) {
                        alSynSetPitch(seqp->drvr, &vs->voice,
                                      vs->pitch * bendRatio * vs->vibrato);
                    }
                }
            }
            break;
            
        default:
#ifdef _DEBUG
	    __osError(ERR_ALSEQPUNKNOWNMIDI, 1, status);
#endif
	    break;
    }        
}

void __handleMetaMsg(ALSeqPlayer *seqp, ALEvent *event)
{
    ALTempoEvent *tevt = &event->msg.tempo;
    ALEvent      evt;
    s32          tempo;

    if (event->msg.tempo.status == AL_MIDI_Meta)
    {
        if (event->msg.tempo.type == AL_MIDI_META_TEMPO)
	{
	    tempo =
		(tevt->byte1 << 16) |
		(tevt->byte2 <<  8) |
		(tevt->byte3 <<  0);
	    __setUsptFromTempo (seqp, (f32)tempo);	/* sct 1/8/96 */
        }
    }
}

ALVoiceState *__mapVoice(ALSeqPlayer *seqp, u8 key, u8 vel, u8 channel)
{
    ALVoiceState  *vs = seqp->vFreeList;

    if (vs) {

        seqp->vFreeList = vs->next;

        vs->next = 0;
        
        if (!seqp->vAllocHead)
            seqp->vAllocHead = vs;
        else
            seqp->vAllocTail->next = vs;
        
        seqp->vAllocTail = vs;

        vs->channel             = channel;
        vs->key                 = key;
        vs->velocity            = vel;
        vs->voice.clientPrivate = vs;
    }
    
    return vs;
}

void __unmapVoice(ALSeqPlayer *seqp, ALVoice *voice) 
{
    ALVoiceState *prev = 0;
    ALVoiceState *vs;
    
    /*
     * we could use doubly linked lists here and save some code and
     * execution time, but time spent here in negligible, so it won't
     * make much difference.
     */
    for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
        if (&vs->voice == voice) {

            if (prev)
                prev->next = vs->next;
            else
                seqp->vAllocHead = vs->next;
            
            if (vs == seqp->vAllocTail) {
                seqp->vAllocTail = prev;
            }

            vs->next = seqp->vFreeList;
            seqp->vFreeList = vs;
            return;

        }
        prev = vs;
    }
#ifdef _DEBUG
    __osError(ERR_ALSEQPUNMAP, 1, voice);
#endif    
}

ALVoiceState *__lookupVoice(ALSeqPlayer *seqp, u8 key, u8 channel)
{
    ALVoiceState  *vs;

    for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
        if ((vs->key == key) && (vs->channel == channel) &&
            (vs->phase != AL_PHASE_RELEASE) && (vs->phase != AL_PHASE_SUSTREL))
            return vs;
    }
    
    return 0;
}

ALSound *__lookupSoundQuick(ALSeqPlayer *seqp, u8 key, u8 vel, u8 chan)
{
    ALInstrument *inst = seqp->chanState[chan].instrument;
    s32 l = 1;
    s32 r = inst->soundCount;
    s32 i;
    ALKeyMap *keymap;

    assert(inst != NULL);       /* sct 10/31/95 - If inst is NULL, then the seqp probably wasn't setup correctly. */
    
    while (r >= l) {
        i = (l+r)/2;

        keymap = inst->soundArray[i-1]->keyMap;

        if ((key >= keymap->keyMin) && (key <= keymap->keyMax) &&
            (vel >= keymap->velocityMin) && (vel <= keymap->velocityMax)) {
            return inst->soundArray[i-1];
        } else if ((key < keymap->keyMin) ||
                   ((vel < keymap->velocityMin) && (key <= keymap->keyMax))) {
            r = i - 1;
        } else {
            l = i + 1;
        }
    }
    
    return 0;
}

s16 __vsVol(ALVoiceState *vs, ALSeqPlayer *seqp) 
{

    u32     t1,t2;

    t1 = (vs->tremelo*vs->velocity*vs->envGain) >> 6;
    t2 = (vs->sound->sampleVolume*seqp->vol*
          seqp->chanState[vs->channel].vol) >> 14;

    t1 *= t2;
    t1 >>= 15;
    
    return( (s16)t1 );
    
}

ALMicroTime __vsDelta(ALVoiceState *vs, ALMicroTime t)
{
    /*
     * If we are interrupting a previously set envelope segment, we
     * need to recalculate the segment end time given the current
     * time. Note: this routine assumes that the voice is currently
     * playing.
     */
    
    s32 delta = vs->envEndTime - t;
    
    if (delta >= 0) {
        return delta;
    } else {
        return AL_GAIN_CHANGE_TIME;
    }
}

ALPan __vsPan(ALVoiceState *vs, ALSeqPlayer *seqp) 
{
    s32 tmp;

    tmp = seqp->chanState[vs->channel].pan - AL_PAN_CENTER +
        vs->sound->samplePan;
    tmp = MAX(tmp, AL_PAN_LEFT);
    tmp = MIN(tmp, AL_PAN_RIGHT);

    return (ALPan) tmp;
}

void __seqpReleaseVoice(ALSeqPlayer *seqp, ALVoice *voice,
                        ALMicroTime deltaTime)
{
    ALEvent             evt;
    ALVoiceState	*vs = (ALVoiceState *)voice->clientPrivate;

    /*
     * if in attack phase, remove all pending volume
     * events for this voice from the queue
     */

    if (vs->envPhase == AL_PHASE_ATTACK) {
	ALLink              *thisNode;
	ALLink              *nextNode;
	ALEventListItem     *thisItem, *nextItem;

	thisNode = seqp->evtq.allocList.next;
	while( thisNode != 0 ) {
	    nextNode = thisNode->next;
	    thisItem = (ALEventListItem *)thisNode;
	    nextItem = (ALEventListItem *)nextNode;
	    if (thisItem->evt.type == AL_SEQP_ENV_EVT) {
		if(thisItem->evt.msg.vol.voice == voice) {
		    if( nextItem )
			nextItem->delta += thisItem->delta;
		    alUnlink(thisNode);
		    alLink(thisNode, &seqp->evtq.freeList);
		}
	    }
	    thisNode = nextNode;
	}
    }
    
    vs->velocity = 0;
    vs->envPhase = AL_PHASE_RELEASE;
    vs->envGain  = 0;
    vs->envEndTime = seqp->curTime + deltaTime;

    alSynSetPriority(seqp->drvr, voice, 0); /* make candidate for stealing */
    alSynSetVol(seqp->drvr, voice, 0, deltaTime);
    evt.type  = AL_NOTE_END_EVT;
    evt.msg.note.voice = voice;
    
    alEvtqPostEvent(&seqp->evtq, &evt, deltaTime);
}

char __voiceNeedsNoteKill (ALSeqPlayer *seqp, ALVoice *voice, ALMicroTime killTime)
{
    ALLink              *thisNode;
    ALLink              *nextNode;
    ALEventListItem     *thisItem;
    ALMicroTime		itemTime = 0;
    char		needsNoteKill = TRUE;

#if VOICENEEDSNOTEKILL_DEBUG
    alEvtqPrintAllocEvts (&seqp->evtq);
#endif

    thisNode = seqp->evtq.allocList.next;
    while (thisNode != 0)
    {
	nextNode = thisNode->next;
	thisItem = (ALEventListItem *)thisNode;
	itemTime += thisItem->delta;

	if (thisItem->evt.type == AL_NOTE_END_EVT)
	{
	    if (thisItem->evt.msg.note.voice == voice)
	    {
		if (itemTime > killTime)
		{
		    if ((ALEventListItem *)nextNode)
			((ALEventListItem *)nextNode)->delta += thisItem->delta;
		    alUnlink(thisNode);
		    alLink(thisNode, &seqp->evtq.freeList);
		}
		else
		    needsNoteKill = FALSE;
		break;
	    }
	}
	thisNode = nextNode;
    }

#if VOICENEEDSNOTEKILL_DEBUG 
    if (thisNode)
	osSyncPrintf("vox 0x%0x: end time %d  kill time %d\n\n", voice, itemTime, killTime);
    else
	osSyncPrintf("vox 0x%0x: not found\n\n", voice);

    alEvtqPrintAllocEvts (&seqp->evtq);
#endif

   return needsNoteKill;
}

void __initFromBank(ALSeqPlayer *seqp, ALBank *b)
{
    /*
     * init the chanState with the default instrument
     */
    s32 i;    
    ALInstrument *inst = 0;
    
    /* set to the first available instrument. */
    for(i = 0; !inst ; i++)
      inst = b->instArray[i];
    
    /* sct 11/6/95 - Setup the channel state for the given instrument. */
    /* There is some wasted effort here since both calls the same state vars */
    /* but it's safer. */
    for (i = 0; i < seqp->maxChannels; i++) {
      __resetPerfChanState(seqp, i);
      __setInstChanState(seqp, inst, i);
    }

    if (b->percussion) {
      __resetPerfChanState(seqp, i);
      __setInstChanState(seqp, b->percussion, 9);
    }
}

void __setInstChanState(ALSeqPlayer *seqp, ALInstrument *inst, s32 chan)
{
    seqp->chanState[chan].instrument = inst;
    seqp->chanState[chan].pan = inst->pan;
    seqp->chanState[chan].vol = inst->volume;
    seqp->chanState[chan].priority = inst->priority;
    seqp->chanState[chan].bendRange = inst->bendRange;
}

void __resetPerfChanState(ALSeqPlayer *seqp, s32 chan) 
{
  seqp->chanState[chan].fxId = AL_FX_NONE;
  seqp->chanState[chan].fxmix = AL_DEFAULT_FXMIX;
  seqp->chanState[chan].pan = AL_PAN_CENTER;
  seqp->chanState[chan].vol = AL_VOL_FULL;
  seqp->chanState[chan].priority = AL_DEFAULT_PRIORITY;
  seqp->chanState[chan].sustain = 0;
  seqp->chanState[chan].bendRange = 200;
  seqp->chanState[chan].pitchBend = 1.0f;
}

void __initChanState(ALSeqPlayer *seqp) 
{
    int i;
    
    for (i = 0; i < seqp->maxChannels; i++)
    {
        seqp->chanState[i].instrument = 0;
	__resetPerfChanState (seqp, i);
    }
}

void __seqpStopOsc(ALSeqPlayer *seqp, ALVoiceState *vs)
{
    ALEventListItem  *thisNode,*nextNode;
    s16              evtType;
    
    thisNode = (ALEventListItem*)seqp->evtq.allocList.next;
    while(thisNode)
    {
        nextNode = (ALEventListItem*)thisNode->node.next;
        evtType = thisNode->evt.type;
        if(evtType == AL_TREM_OSC_EVT || evtType == AL_VIB_OSC_EVT)
        {
            if(thisNode->evt.msg.osc.vs == vs)
            {
                (*seqp->stopOsc)(thisNode->evt.msg.osc.oscState);
                alUnlink((ALLink*)thisNode);
                if(nextNode)
                    nextNode->delta += thisNode->delta;
                alLink((ALLink*)thisNode, &seqp->evtq.freeList);
                if(evtType == AL_TREM_OSC_EVT)
                    vs->flags = vs->flags & 0xFE;
                else /* must be a AL_VIB_OSC_EVT */
                    vs->flags = vs->flags & 0xFD;
                if(!vs->flags)
                    return;  /* there should be no more events */
            }
        }
        
        thisNode = nextNode;
    }
}

void __setUsptFromTempo (ALSeqPlayer *seqp, f32 tempo)
{
    if (seqp->target)
	seqp->uspt = (s32)((f32)tempo * seqp->target->qnpt);
    else
	seqp->uspt = 488;		/* This is the initial value set by alSeqpNew. */
}
