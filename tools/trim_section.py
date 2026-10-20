#!/usr/bin/env python3
"""Shrink an ELF32 big-endian object's section to SIZE bytes, in place.

KMC as (2.6) raises .rodata's alignment to 16 when it pools an li.d literal and pads the section
to that alignment; a unit whose rodata is carved out of the data blob on an 8-byte (not 16-byte)
boundary then emits 8 bytes more than retail has there. This drops that tail padding: it refuses
unless the bytes cut are zero and no relocation of the section lies in them.

usage: trim_section.py <object> <section> <size>
"""
import struct
import sys


def main():
    path, name, size = sys.argv[1], sys.argv[2], int(sys.argv[3], 0)
    data = bytearray(open(path, "rb").read())
    if data[:4] != b"\x7fELF" or data[4] != 1 or data[5] != 2:
        sys.exit("trim_section: %s is not an ELF32 big-endian object" % path)
    shoff, = struct.unpack_from(">I", data, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from(">HHH", data, 0x2E)

    def sec(i):
        return struct.unpack_from(">IIIIIIIIII", data, shoff + i * shentsize)

    strtab = sec(shstrndx)

    def secname(i):
        off = strtab[4] + sec(i)[0]
        return data[off:data.index(b"\0", off)].decode()

    idx = [i for i in range(shnum) if secname(i) == name]
    if len(idx) != 1:
        sys.exit("trim_section: %s: %d sections named %s" % (path, len(idx), name))
    i = idx[0]
    s = sec(i)
    offset, cur = s[4], s[5]
    if cur == size:
        return
    if cur < size:
        sys.exit("trim_section: %s %s is 0x%X bytes, smaller than 0x%X" % (path, name, cur, size))
    if any(data[offset + size:offset + cur]):
        sys.exit("trim_section: %s %s: the bytes past 0x%X are not zero" % (path, name, size))
    for j in range(shnum):
        r = sec(j)
        if r[1] == 9 and r[7] == i:  # SHT_REL against this section
            for k in range(r[5] // r[9]):
                roff, = struct.unpack_from(">I", data, r[4] + k * r[9])
                if roff >= size:
                    sys.exit("trim_section: %s %s: a relocation at 0x%X" % (path, name, roff))
        elif r[1] == 4 and r[7] == i:  # SHT_RELA
            sys.exit("trim_section: %s: RELA relocations are not handled" % path)
    struct.pack_into(">I", data, shoff + i * shentsize + 0x14, size)
    open(path, "wb").write(data)


if __name__ == "__main__":
    main()
