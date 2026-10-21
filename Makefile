### Build Options ###

BASEROM      := baserom.us.z64
TARGET       := marioparty2
COMPARE      ?= 1
NON_MATCHING ?= 0
CHECK        ?= 1
VERBOSE      ?= 0

# Patches
# PATCHES_ASFLAGS := --defsym MP_SAVETYPE_PATCH=1

# Fail early if baserom does not exist
ifeq ($(wildcard $(BASEROM)),)
$(error Baserom `$(BASEROM)' not found.)
endif

# NON_MATCHING=1 implies COMPARE=0
ifeq ($(NON_MATCHING),1)
override COMPARE=0
endif

ifeq ($(VERBOSE),0)
V := @
endif


### Output ###

BUILD_DIR := build
ROM       := $(BUILD_DIR)/$(TARGET).z64
ELF       := $(BUILD_DIR)/$(TARGET).elf
LD_SCRIPT := $(TARGET).ld
LD_MAP    := $(BUILD_DIR)/$(TARGET).map


### Tools ###

PYTHON     := venv/bin/python3
N64CKSUM   := $(PYTHON) tools/n64cksum.py
SPLAT_YAML := marioparty2.yaml
SPLAT      := splat split $(SPLAT_YAML)
EMULATOR   := mupen64plus
DIFF       := diff

CROSS    := mips-linux-gnu-
AS       := $(CROSS)as
LD       := $(CROSS)ld
OBJCOPY  := $(CROSS)objcopy
STRIP    := $(CROSS)strip

CC       := tools/gcc_2.7.2/gcc
CC_HOST  := gcc
CPP      := cpp -P

PRINT := printf '
 ENDCOLOR := \033[0m
 WHITE     := \033[0m
 ENDWHITE  := $(ENDCOLOR)
 GREEN     := \033[0;32m
 ENDGREEN  := $(ENDCOLOR)
 BLUE      := \033[0;34m
 ENDBLUE   := $(ENDCOLOR)
 YELLOW    := \033[0;33m
 ENDYELLOW := $(ENDCOLOR)
ENDLINE := \n'

### Compiler Options ###

ASFLAGS      := -G 0 -I include -mips3 -mabi=32
NOP_FIX 	 :=
CFLAGS       := -O1 -G0 -mips3 -mgp32 -mfp32 $(NOP_FIX)
CPPFLAGS     := -I include -I $(BUILD_DIR)/include -I src -DF3DEX_GBI_2 -D_LANGUAGE_C
LDFLAGS      := -T undefined_syms.txt -T undefined_funcs.txt -T undefined_funcs_auto.txt -T undefined_syms_auto.txt -T $(LD_SCRIPT) -Map $(LD_MAP) --no-check-sections
CFLAGS_CHECK := -fsyntax-only -fsigned-char -nostdinc -fno-builtin -D CC_CHECK\
                -std=gnu90 -Wall -Wextra -Wno-format-security -Wno-unused-parameter -Wno-pointer-to-int-cast -Wno-int-to-pointer-cast

ifneq ($(CHECK),1)
CFLAGS_CHECK += -w
endif

### Sources ###

# Object files
OBJECTS := $(shell grep -E 'build.+\.o' marioparty2.ld -o)
DEPENDS := $(OBJECTS:=.d) 

### Targets ###

build/src/overlays/ovl_00_Debug/D57F0.c : NOP_FIX = -Wa,--vr4300mul-off

# b1-G2: libultra units copied from MP1's SDK lib units (MP1 Makefile SDK_LIB_UNITS / src/lib):
# -O3 -funsigned-char with the lib headers, as MP1 builds them.
G2_SDK_LIB_UNITS := build/src/A70F0.c.o build/src/AEA90.c.o build/src/AEAE0.c.o build/src/B1150.c.o build/src/AEB30.c.o build/src/AECD0.c.o build/src/A8EE0.c.o build/src/A9140.c.o build/src/AF0D0.c.o build/src/AF2E0.c.o build/src/A92D0.c.o build/src/AA720.c.o build/src/AB3D0.c.o build/src/AB810.c.o
$(G2_SDK_LIB_UNITS): CFLAGS = -O3 -funsigned-char -G0 -mips3 -mgp32 -mfp32 -D_MIPS_SZLONG=32 -D_LANGUAGE_C -DF3DEX_GBI
# KMC as: the libultra objects keep the vr4300 mul fix on (MP1 builds them without --vr4300mul-off)
$(G2_SDK_LIB_UNITS): export VR4300MUL = ON
$(G2_SDK_LIB_UNITS): CPPFLAGS = -I include -I include/PR -I $(BUILD_DIR)/include -I src -DNDEBUG -D_LANGUAGE_C -D_MIPS_SZLONG=32 -DF3DEX_GBI_2

# b1-G2: MP1 per-file flags for non-lib units: 9B9F0.c (ldiv) -O3 -funsigned-char; 9C190.c (libm)
# keeps KMC's vr4300 mul fix on.
build/src/B1170.c.o: CFLAGS = -O3 -funsigned-char -G0 -mips3 -mgp32 -mfp32
build/src/B1910.c.o: export VR4300MUL = ON

# b1-G2: MP3 flags: libhmath -O2 -ffast-math; 8ACD0.c -O2.
G2_HMATH_UNITS := build/src/B2470.c.o build/src/B3D90.c.o build/src/B3DC0.c.o build/src/B3E00.c.o build/src/B3E40.c.o build/src/B3EC0.c.o build/src/B3F80.c.o build/src/B3FB0.c.o
$(G2_HMATH_UNITS): CFLAGS = -O2 -G0 -mips3 -mgp32 -mfp32 -ffast-math
build/src/B4420.c.o: CFLAGS = -O2 -G0 -mips3 -mgp32 -mfp32
# A5E10 (libc/string.c part): MP3 src/2.0L/libc/string.c builds -O2, signed char
build/src/A5E10.c.o: CFLAGS = -O2 -G0 -mips3 -mgp32 -mfp32

#build/src/libultra/os/%.o: CFLAGS := -O2 $(CFLAGSCOMMON)
#build/src/libultra/libc/%.o: CFLAGS := -O2 $(CFLAGSCOMMON)
#build/src/lib/%.o: CFLAGS := -O2 $(CFLAGSCOMMON)

all: $(ROM)

-include $(DEPENDS)

clean:
	$(V)rm -rf build
	$(V)rm -rf asm

distclean: clean
	$(V)rm -rf asm
	$(V)rm -rf assets
	$(V)rm -f *auto.txt
	$(V)rm -f marioparty2.ld
	$(V)rm -f include/ld_addrs.h

setup: distclean split

split:
	$(V)$(SPLAT)

test: $(ROM)
	$(V)$(EMULATOR) $<
	
export VR4300MUL := OFF

# b1-G1: units built with the KMC assembler's VR4300 mul fix on (as MP1 builds their sources)
# 1BD70.c (MP1 1A2A0.c): nop between back-to-back mul.s in func_8001B170_1BD70
build/src/1BD70.c.o: export VR4300MUL := ON
# 437E0.c (MP1 3DEB0.c): nop between back-to-back mul.s in func_80042F7C_43B7C
build/src/437E0.c.o: export VR4300MUL := ON
# 7FAE0.c is libultra's audio/sndplayer.c (MP1 64FD0.c): the lib audio headers, as MP1 builds it
build/src/7FAE0.c.o: CPPFLAGS += -I include/PR -DNDEBUG -D_MIPS_SZLONG=32
# Compile .c files with kmc gcc (use strip to fix objects so that they can be linked with modern gnu ld) 
$(BUILD_DIR)/src/%.c.o: src/%.c
	@$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	@$(CC_HOST) $(CFLAGS_CHECK) $(CPPFLAGS) -MMD -MP -MT $@ -MF $@.d -I include/ $<
	$(V)export COMPILER_PATH=tools/gcc_2.7.2 && $(CC) $(CFLAGS) $(CPPFLAGS) -I include/ -c -o $@ $<
	@$(STRIP) $@ -N dummy-symbol-name
	$(if $(RODATA_AS_DATA),$(V)$(OBJCOPY) --rename-section .rodata=.data $@)

# Assemble .s files with modern gnu as
$(BUILD_DIR)/asm/%.s.o: asm/%.s
	@$(PRINT)$(GREEN)Assembling asm file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	$(V)$(AS) $(ASFLAGS) -o $@ $<

# Create .o files from .bin files.
$(BUILD_DIR)/%.bin.o: %.bin
	@$(PRINT)$(GREEN)Objcopying binary file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	$(V)$(LD) -r -b binary -o $@ $<

# Link the .o files into the .elf
$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS)
	@$(PRINT)$(GREEN)Linking elf file: $(ENDGREEN)$(BLUE)$@$(ENDBLUE)$(ENDLINE)
	$(V)$(LD) $(LDFLAGS) -o $@

# Convert the .elf to the final rom
$(ROM): $(BUILD_DIR)/$(TARGET).elf
	@$(PRINT)$(GREEN)Creating z64: $(ENDGREEN)$(BLUE)$@$(ENDBLUE)$(ENDLINE)
	$(V)$(OBJCOPY) $< $@ -O binary
	$(V)$(N64CKSUM) $@
ifeq ($(COMPARE),1)
	@$(DIFF) $(BASEROM) $(ROM) && printf "OK\n" || (echo 'The build succeeded, but did not match the base ROM. This is expected if you are making changes to the game. To skip this check, use "make COMPARE=0".' && false)
endif

### Make Settings ###

.PHONY: all clean distclean test setup split

# Remove built-in implicit rules to improve performance
MAKEFLAGS += --no-builtin-rules

# Print target for debugging
print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true

# b1-L: libultra units copied from MP1 src/lib/2.0I build like MP1's src/lib (-O3, unsigned char, lib defines)
B1L_UNITS := build/src/9D320.c.o build/src/9D6D0.c.o build/src/9D750.c.o build/src/9D840.c.o build/src/9E2C0.c.o build/src/9E3C0.c.o build/src/9E550.c.o build/src/9E740.c.o build/src/9E7A0.c.o build/src/9E800.c.o build/src/9E8A0.c.o build/src/9EDE0.c.o build/src/9EED0.c.o build/src/9F0A0.c.o build/src/9F370.c.o build/src/9F6C0.c.o build/src/9F770.c.o build/src/9F7B0.c.o build/src/9F800.c.o build/src/9F840.c.o build/src/A0300.c.o build/src/A0320.c.o build/src/A0340.c.o build/src/A0360.c.o build/src/A0380.c.o build/src/A0400.c.o build/src/A0440.c.o build/src/A0470.c.o build/src/A04A0.c.o build/src/A04D0.c.o build/src/A0520.c.o build/src/A0550.c.o build/src/A17E0.c.o build/src/A1810.c.o build/src/A18D0.c.o build/src/A1920.c.o build/src/A1990.c.o build/src/A19E0.c.o build/src/A1A00.c.o build/src/A1A50.c.o build/src/A1A80.c.o build/src/A1AD0.c.o build/src/A1B20.c.o build/src/A1B70.c.o build/src/A21C0.c.o build/src/A2210.c.o build/src/A22B0.c.o build/src/A2350.c.o build/src/A2530.c.o build/src/A25B0.c.o build/src/A2650.c.o build/src/A26E0.c.o build/src/A27A0.c.o build/src/A2840.c.o build/src/A28E0.c.o build/src/A2B20.c.o build/src/A2D00.c.o build/src/A3010.c.o build/src/A3070.c.o build/src/A30D0.c.o build/src/A3220.c.o build/src/A3930.c.o build/src/A4390.c.o build/src/A4980.c.o build/src/A4B10.c.o build/src/A4C10.c.o build/src/A4E90.c.o build/src/A5110.c.o build/src/A5490.c.o build/src/A54C0.c.o build/src/A57A0.c.o build/src/A5AC0.c.o build/src/A5BA0.c.o build/src/A5D40.c.o build/src/A6260.c.o build/src/A6320.c.o build/src/A6350.c.o build/src/A6490.c.o build/src/A65C0.c.o build/src/A66F0.c.o build/src/A67D0.c.o build/src/A6A20.c.o build/src/A6A40.c.o build/src/A6A90.c.o build/src/A6B40.c.o build/src/A6DE0.c.o build/src/A6E00.c.o build/src/A6ED0.c.o build/src/A6FF0.c.o build/src/A70B0.c.o build/src/A7140.c.o build/src/A71D0.c.o build/src/A7270.c.o build/src/A7630.c.o build/src/A7670.c.o build/src/A76B0.c.o build/src/A79F0.c.o build/src/A7A50.c.o build/src/A7AA0.c.o build/src/A7C60.c.o build/src/A7CB0.c.o build/src/A7FC0.c.o build/src/A8020.c.o build/src/A83B0.c.o build/src/A8880.c.o build/src/A8C30.c.o build/src/A8E50.c.o build/src/A8E90.c.o build/src/A9B00.c.o build/src/AA610.c.o build/src/AB3F0.c.o build/src/AB560.c.o build/src/AEDF0.c.o build/src/AFD70.c.o
$(B1L_UNITS): CFLAGS = -O3 -funsigned-char -G0 -mips3 -mgp32 -mfp32 -D_MIPS_SZLONG=32 -D_LANGUAGE_C -DF3DEX_GBI
$(B1L_UNITS): CPPFLAGS = -I include/lib2.0I -I include/lib2.0I/PR -I include -I $(BUILD_DIR)/include -I src -DNDEBUG -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -D_LANGUAGE_C
# MP1 builds src/lib without --vr4300mul-off (KMC mul fix on); MP2 exports VR4300MUL=OFF globally
$(B1L_UNITS): export VR4300MUL := ON
# b1-L: the splat main segment is one asm data blob, so C .rodata is carved in as .data (yaml '.data' subsegments)
B1L_RODATA_UNITS := build/src/9EED0.c.o build/src/9F840.c.o build/src/A1B70.c.o build/src/A30D0.c.o build/src/A3220.c.o build/src/A3930.c.o build/src/A4390.c.o build/src/A5110.c.o build/src/A5BA0.c.o build/src/A7CB0.c.o build/src/AB560.c.o build/src/AFD70.c.o
$(B1L_RODATA_UNITS): RODATA_AS_DATA = 1
# Main units whose .rodata is carved out of the data blob's rodata half (ROM D2400-D57F0)
CARVED_RODATA_UNITS := build/src/187C0.c.o build/src/57150.c.o build/src/7FAE0.c.o build/src/3D6A0.c.o
$(CARVED_RODATA_UNITS): RODATA_AS_DATA = 1
# Data-blob pieces that end where a carved unit starts on an 8-byte (not 16-byte) boundary: gas would
# pad them to 16 and shift everything after
# (a piece is named by its start address: splitting the blob before it renames it, so update this)
NOPAD_DATA_PIECES := build/asm/data/D2F60.data.s.o
$(NOPAD_DATA_PIECES): ASFLAGS += --no-pad-sections
# b3-D: carved rodata (5F3B0 D3B00-D3BE8)
B3D_CARVED_RODATA_UNITS := build/src/5F3B0.c.o
CARVED_RODATA_UNITS += $(B3D_CARVED_RODATA_UNITS)
$(B3D_CARVED_RODATA_UNITS): RODATA_AS_DATA = 1
B3D_NOPAD_DATA_PIECES := build/asm/data/D3BE8.data.s.o
NOPAD_DATA_PIECES += $(B3D_NOPAD_DATA_PIECES)
$(B3D_NOPAD_DATA_PIECES): ASFLAGS += --no-pad-sections
# w1-C/w1-D: ECE0's whole rodata carved (D2420-D2AA0; func_80012800_13400's table is defined in C beside its INCLUDE_ASM)
W1D_CARVED_RODATA_UNITS := build/src/ECE0.c.o
CARVED_RODATA_UNITS += $(W1D_CARVED_RODATA_UNITS)
$(W1D_CARVED_RODATA_UNITS): RODATA_AS_DATA = 1
# w3-A: 21920's whole rodata carved (D2CE8-D2DF8; the asm switch's table and the strings the asm
# .data tables name are defined in C); the piece before it ends on an 8-byte boundary
W3A_CARVED_RODATA_UNITS := build/src/21920.c.o
CARVED_RODATA_UNITS += $(W3A_CARVED_RODATA_UNITS)
$(W3A_CARVED_RODATA_UNITS): RODATA_AS_DATA = 1
W3A_NOPAD_DATA_PIECES := build/asm/data/D2AD0.data.s.o
NOPAD_DATA_PIECES += $(W3A_NOPAD_DATA_PIECES)
$(W3A_NOPAD_DATA_PIECES): ASFLAGS += --no-pad-sections
# b2-A: units retail built with the KMC assembler VR4300 mul fix on (a nop between mul.s pairs), as MP1/MP3 build their sources
build/src/26370.c.o: export VR4300MUL := ON
build/src/274D0.c.o: export VR4300MUL := ON
build/src/C8E0.c.o: export VR4300MUL := ON

# b2-B: per-file flags as MP1 builds the reference files
# 2E0D0 (MP1 29C90.c), 3D6A0 (nop before a mult, as MP1 3AC60.c): KMC as keeps the vr4300 mul fix on
B2B_MULFIX_UNITS := build/src/2E0D0.c.o build/src/3D6A0.c.o
$(B2B_MULFIX_UNITS): export VR4300MUL = ON

# b2-E: libultra units from MP1's SDK lib / src/lib units, built as MP1 builds them (-O3, unsigned char, lib headers)
B2E_LIB_UNITS := build/src/9EA20.c.o build/src/AC3B0.c.o build/src/A0580.c.o build/src/A6C30.c.o build/src/A88A0.c.o build/src/AE970.c.o build/src/AE9B0.c.o
$(B2E_LIB_UNITS): CFLAGS = -O3 -funsigned-char -G0 -mips3 -mgp32 -mfp32 -D_MIPS_SZLONG=32 -D_LANGUAGE_C -DF3DEX_GBI
$(B2E_LIB_UNITS): CPPFLAGS = -I include/lib2.0I -I include/lib2.0I/PR -I include -I $(BUILD_DIR)/include -I src -DNDEBUG -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -D_LANGUAGE_C
$(B2E_LIB_UNITS): export VR4300MUL := ON
# AC3B0 (seqplayer), A0580 (csplayer): retail tests __al(C)SeqNextDelta's char result as signed (sll 24), so no -funsigned-char
build/src/AC3B0.c.o build/src/A0580.c.o: CFLAGS = -O3 -G0 -mips3 -mgp32 -mfp32 -D_MIPS_SZLONG=32 -D_LANGUAGE_C -DF3DEX_GBI
# b2-E: ADEF0 (xprintf) builds like MP3's src/2.0L/libc/xprintf.c: -O2, signed char
build/src/ADEF0.c.o: CFLAGS = -O2 -G0 -mips3 -mgp32 -mfp32 -D_LANGUAGE_C
# b2-E: B0360 (xldtob): MP1 src/9AF70.c is -O3 -funsigned-char; MP2 tests the char code signed, so -O3 only
build/src/B0360.c.o: CFLAGS = -O3 -G0 -mips3 -mgp32 -mfp32
# b2-E: units whose .rodata is carved out of the data blob
B2E_CARVED := build/src/9EA20.c.o build/src/A92D0.c.o build/src/AA720.c.o build/src/AB810.c.o build/src/ADEF0.c.o build/src/B0360.c.o build/src/B1350.c.o build/src/B14D0.c.o build/src/B1910.c.o
CARVED_RODATA_UNITS += $(B2E_CARVED)
$(B2E_CARVED): RODATA_AS_DATA = 1
# b2-E: MP3 libhmath units (-O2 -ffast-math, as MP3 and b1-G2's G2_HMATH_UNITS)
B2E_HMATH_UNITS := build/src/B24A0.c.o build/src/B3CD0.c.o build/src/B40B0.c.o
$(B2E_HMATH_UNITS): CFLAGS = -O2 -G0 -mips3 -mgp32 -mfp32 -ffast-math
# B40B0 (HuVecCross): nop between back-to-back mul.s, KMC as mul fix on
build/src/B40B0.c.o: export VR4300MUL = ON

# b2-C: units whose retail code has the KMC VR4300 mul fix (a nop between dependent mul.s)
B2C_MULFIX_UNITS := build/src/54CB0.c.o
$(B2C_MULFIX_UNITS): export VR4300MUL := ON

# b3-A: main units whose .rodata is carved out of the data blob
B3A_CARVED := build/src/169B0.c.o
CARVED_RODATA_UNITS += $(B3A_CARVED)
$(B3A_CARVED): RODATA_AS_DATA = 1
# b3-A: 1D0B0 (MP1 1B800.c) is built as MP1 builds 1B800.c: GCC's assembly with blank lines removed,
# assembled with the KMC VR4300 mul fix on (func_8001F1B8_1FDB8: a nop between the sqrt argument's
# mul.s pair, none after a branch-likely's store)
B3A_BLANKSTRIP_UNITS := build/src/1D0B0.c.o
$(B3A_BLANKSTRIP_UNITS): export VR4300MUL := ON
$(B3A_BLANKSTRIP_UNITS): $(BUILD_DIR)/src/%.c.o: src/%.c
	@$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	@$(CC_HOST) $(CFLAGS_CHECK) $(CPPFLAGS) -MMD -MP -MT $@ -MF $@.d -I include/ $<
	$(V)export COMPILER_PATH=tools/gcc_2.7.2 && $(CC) $(CFLAGS) $(CPPFLAGS) -I include/ -S -o $(@:.o=.s) $< && sed -i '/^[[:space:]]*$$/d' $(@:.o=.s) && $(CC) $(CFLAGS) -c -o $@ $(@:.o=.s)
	@$(STRIP) $@ -N dummy-symbol-name
# b3-B: units whose retail code has the KMC VR4300 mul fix (a nop between dependent mul.s)
B3B_MULFIX_UNITS := build/src/43E90.c.o
$(B3B_MULFIX_UNITS): export VR4300MUL := ON
# b3-C: units whose retail code has the KMC VR4300 mul fix (a nop between dependent mul.s)
B3C_MULFIX_UNITS := build/src/51630.c.o
$(B3C_MULFIX_UNITS): export VR4300MUL := ON
# b3-E: per-file flags as MP1/MP3 build the reference files
# B2430 (MP3 libhmath/vecmag.c): -O2 -ffast-math, KMC as mul fix on
build/src/B2430.c.o: CFLAGS = -O2 -G0 -mips3 -mgp32 -mfp32 -ffast-math
build/src/B2430.c.o: export VR4300MUL = ON
# ADE40 (libultra gu/normalize.c): libultra flags as MP1's src/lib (-O3, unsigned char, mul fix on)
build/src/ADE40.c.o: CFLAGS = -O3 -funsigned-char -G0 -mips3 -mgp32 -mfp32 -D_MIPS_SZLONG=32 -D_LANGUAGE_C -DF3DEX_GBI
build/src/ADE40.c.o: export VR4300MUL = ON
# b3-E: units whose .rodata is carved out of the data blob
B3E_CARVED := build/src/A0580.c.o build/src/AC3B0.c.o
CARVED_RODATA_UNITS += $(B3E_CARVED)
$(B3E_CARVED): RODATA_AS_DATA = 1
# b3-E: 936F0 (synstartvoiceparam.c), 93890 (synsetpan.c): MP1 builds these lib files -O0 (mono sound patch)
B3E_O0_LIB_UNITS := build/src/936F0.c.o build/src/93890.c.o
$(B3E_O0_LIB_UNITS): CFLAGS = -O0 -g -G0 -mips3 -mgp32 -mfp32 -D_MIPS_SZLONG=32 -D_LANGUAGE_C -DF3DEX_GBI
$(B3E_O0_LIB_UNITS): CPPFLAGS = -I include/lib2.0I -I include/lib2.0I/PR -I include -I $(BUILD_DIR)/include -I src -DNDEBUG -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -D_LANGUAGE_C
$(B3E_O0_LIB_UNITS): export VR4300MUL := ON
# carve-58080: the head of 58080's rodata (D3A38-D3AA0) carved out of the data blob. KMC as gives
# .rodata 16-byte alignment and padding once it pools an li.d literal, so the object emits 0x70
# bytes for retail's 0x68: tools/trim_section.py drops the zero tail (SUBALIGN(8) places it)
C58080_CARVED := build/src/58080.c.o
CARVED_RODATA_UNITS += $(C58080_CARVED)
$(C58080_CARVED): RODATA_AS_DATA = 1
C58080_NOPAD := build/asm/data/D39F0.data.s.o
NOPAD_DATA_PIECES += $(C58080_NOPAD)
$(C58080_NOPAD): ASFLAGS += --no-pad-sections
$(C58080_CARVED): $(BUILD_DIR)/src/%.c.o: src/%.c
	@$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	@$(CC_HOST) $(CFLAGS_CHECK) $(CPPFLAGS) -MMD -MP -MT $@ -MF $@.d -I include/ $<
	$(V)export COMPILER_PATH=tools/gcc_2.7.2 && $(CC) $(CFLAGS) $(CPPFLAGS) -I include/ -c -o $@ $<
	@$(STRIP) $@ -N dummy-symbol-name
	$(V)$(PYTHON) tools/trim_section.py $@ .rodata 0x68
	$(V)$(OBJCOPY) --rename-section .rodata=.data $@
# pilot: units made fully C by the fresh-decompilation pilot, their rodata carved
PILOT_CARVED := build/src/459D0.c.o build/src/46250.c.o build/src/4ABB0.c.o build/src/80230.c.o
CARVED_RODATA_UNITS += $(PILOT_CARVED)
$(PILOT_CARVED): RODATA_AS_DATA = 1
PILOT_NOPAD := build/asm/data/D3430.data.s.o
NOPAD_DATA_PIECES += $(PILOT_NOPAD)
$(PILOT_NOPAD): ASFLAGS += --no-pad-sections
# 46250 is built as 1D0B0 is: GCC's assembly with blank lines removed, assembled with the KMC
# VR4300 mul fix on (func_800456BC: a nop between dependent mul.s; func_80047EC0: none after a call)
PILOT_BLANKSTRIP_UNITS := build/src/46250.c.o
$(PILOT_BLANKSTRIP_UNITS): export VR4300MUL := ON
$(PILOT_BLANKSTRIP_UNITS): $(BUILD_DIR)/src/%.c.o: src/%.c
	@$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	@$(CC_HOST) $(CFLAGS_CHECK) $(CPPFLAGS) -MMD -MP -MT $@ -MF $@.d -I include/ $<
	$(V)export COMPILER_PATH=tools/gcc_2.7.2 && $(CC) $(CFLAGS) $(CPPFLAGS) -I include/ -S -o $(@:.o=.s) $< && sed -i '/^[[:space:]]*$$/d' $(@:.o=.s) && $(CC) $(CFLAGS) -c -o $@ $(@:.o=.s)
	@$(STRIP) $@ -N dummy-symbol-name
	$(if $(RODATA_AS_DATA),$(V)$(OBJCOPY) --rename-section .rodata=.data $@)
# w1-A/w1-B: 69950 is built as 1D0B0 is: GCC's assembly with blank lines removed, assembled with the KMC
# VR4300 mul fix on (func_8006CF9C_6DB9C: a nop between dependent mul.s; func_8006D580_6E180: none after a call).
# Its whole rodata (D3D60-D40C0) is carved out of the data blob; trim_section.py drops any zero tail
# the li.d pool's 16-byte alignment adds (58080 rule).
W1_CARVED := build/src/69950.c.o
CARVED_RODATA_UNITS += $(W1_CARVED)
$(W1_CARVED): export VR4300MUL := ON
$(W1_CARVED): $(BUILD_DIR)/src/%.c.o: src/%.c
	@$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	@$(CC_HOST) $(CFLAGS_CHECK) $(CPPFLAGS) -MMD -MP -MT $@ -MF $@.d -I include/ $<
	$(V)export COMPILER_PATH=tools/gcc_2.7.2 && $(CC) $(CFLAGS) $(CPPFLAGS) -I include/ -S -o $(@:.o=.s) $< && sed -i '/^[[:space:]]*$$/d' $(@:.o=.s) && $(CC) $(CFLAGS) -c -o $@ $(@:.o=.s)
	@$(STRIP) $@ -N dummy-symbol-name
	$(V)$(PYTHON) tools/trim_section.py $@ .rodata 0x360
	$(V)$(OBJCOPY) --rename-section .rodata=.data $@
# w1-E: 93A80 (HVQ decoder) builds -O3 like MP1 src/7CD60.c
build/src/93A80.c.o: CFLAGS = -O3 -G0 -mips3 -mgp32 -mfp32
# w1-E: 93A80's rodata 0xD45E0-0xD4614 (the two HVQ-MPS strings) carved out of the data blob; the
# yaml pad starts at 0xD4618, after the 8-byte alignment of the next C object's empty .data
W1E_CARVED := build/src/93A80.c.o
CARVED_RODATA_UNITS += $(W1E_CARVED)
$(W1E_CARVED): RODATA_AS_DATA = 1

# w1-C: ECE0 (audio driver) was built with the KMC VR4300 mul fix on (nop between mul.s in func_8001138C_11F8C)
build/src/ECE0.c.o: export VR4300MUL = ON
# w2-C: 274D0 (model manager) fully C; its whole rodata (D2DF8-D2E30) carved out of the data blob
W2C_CARVED := build/src/274D0.c.o
CARVED_RODATA_UNITS += $(W2C_CARVED)
$(W2C_CARVED): RODATA_AS_DATA = 1
W2C_NOPAD := build/asm/data/D2AD0.data.s.o
NOPAD_DATA_PIECES += $(W2C_NOPAD)
$(W2C_NOPAD): ASFLAGS += --no-pad-sections
# w2-D: 63670's whole rodata carved (D3BE8-D3D60; func_800645C8_651C8's string and func_800650F0_65CF0's tables are defined in C beside their INCLUDE_ASM)
W2D_CARVED_RODATA_UNITS := build/src/63670.c.o
CARVED_RODATA_UNITS += $(W2D_CARVED_RODATA_UNITS)
$(W2D_CARVED_RODATA_UNITS): RODATA_AS_DATA = 1

# w2-A: 30560 (MP1 2C0C0.c, model setup and drawing) was built with the KMC VR4300 mul fix on
# (nop between dependent mul.s in func_8003A4B8_3B0B8), as MP1 builds 2C0C0.c
build/src/30560.c.o: export VR4300MUL = ON
# w2-A: 30560's whole rodata (0xD2E30-0xD2EE0) carved out of the data blob
build/src/30560.c.o: RODATA_AS_DATA = 1

# w2-B: 84FF0 (sprite put, window system) is built as 1D0B0 is: GCC's assembly with blank lines removed,
# assembled with the KMC VR4300 mul fix on (SprDispCheck: a nop between dependent mul.s)
W2B_BLANKSTRIP_UNITS := build/src/84FF0.c.o
# w2-B: 84FF0's whole rodata (D42A0-D45E0) is carved out of the data blob
CARVED_RODATA_UNITS += $(W2B_BLANKSTRIP_UNITS)
$(W2B_BLANKSTRIP_UNITS): RODATA_AS_DATA = 1
$(W2B_BLANKSTRIP_UNITS): export VR4300MUL := ON
$(W2B_BLANKSTRIP_UNITS): $(BUILD_DIR)/src/%.c.o: src/%.c
	@$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	@$(CC_HOST) $(CFLAGS_CHECK) $(CPPFLAGS) -MMD -MP -MT $@ -MF $@.d -I include/ $<
	$(V)export COMPILER_PATH=tools/gcc_2.7.2 && $(CC) $(CFLAGS) $(CPPFLAGS) -I include/ -S -o $(@:.o=.s) $< && sed -i '/^[[:space:]]*$$/d' $(@:.o=.s) && $(CC) $(CFLAGS) -c -o $@ $(@:.o=.s)
	@$(STRIP) $@ -N dummy-symbol-name
	$(if $(RODATA_AS_DATA),$(V)$(OBJCOPY) --rename-section .rodata=.data $@)
