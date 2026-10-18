#include "common.h"

/* bcopy and bzero are hand-written asm in libultra. The rest is libultra libc/string.c, from MP3
   src/2.0L/libc/string.c (-O2, signed char; MP1 src/lib/2.0I/libc/string.c has the same code):
   func_800A55D0_A61D0 strchr, func_800A5610_A6210 strlen, func_800A5634_A6234 memcpy. */

INCLUDE_ASM("asm/nonmatchings/A5E10", bcopy);

INCLUDE_ASM("asm/nonmatchings/A5E10", bzero);

char* func_800A55D0_A61D0(const char* s, int c) {
    const char ch = c;
    while (*s != ch) {
        if (*s == 0) {
            return NULL;
        }
        s++;
    }
    return (char*)s;
}

unsigned int func_800A5610_A6210(const char* s) {
    const char* sc = s;
    while (*sc) {
        sc++;
    }
    return sc - s;
}

void* func_800A5634_A6234(void* s1, const void* s2, unsigned int n) {
    char* su1 = (char*)s1;
    const char* su2 = (const char*)s2;
    while (n > 0) {
        *su1++ = *su2++;
        n--;
    }
    return (void*)s1;
}
