/* A6260: from Mario Party 1 src/lib/2.0I/libc/sprintf.c */
#include "include_asm.h"
#include "xstdio.h"

#include "libc/string.h"

// TODO: this comes from a header
#ident "$Revision: 1.23 $"

static char *func_800A56B8_A62B8(char *dst, const char *src, size_t count);

int sprintf(char *dst, const char *fmt, ...)
{
    s32 ans;
    va_list ap;
    va_start(ap, fmt);
    ans = _Printf(func_800A56B8_A62B8, dst, fmt, ap);
    if (ans >= 0)
    {
        dst[ans] = 0;
    }
    return ans; 
}

static char *func_800A56B8_A62B8(char *dst, const char *src, size_t count)
{
    return (char *)memcpy((u8 *)dst, (u8 *)src, count) + count;
}
