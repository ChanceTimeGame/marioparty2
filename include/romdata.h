#ifndef _ROMDATA_H_
#define _ROMDATA_H_

/* ROM offsets of data the main code and the overlays read by DMA. They are linker symbols whose
   address is the offset (undefined_syms_auto.txt), so the code passes `D_01164160` where it means
   ROM 0x1164160. Declared once here rather than in each unit. */
extern u8 D_0041DD30[];
extern u8 D_01142DD0[]; /* strings */
extern u8 D_01164160[]; /* passed to func_80050A30 by every board scene */
extern u8 D_016EC470[];
extern u8 D_01750450[];
extern u8 D_0190A090[];
extern u8 D_01CBF410[];
extern u8 D_01E2A560[];

#endif
