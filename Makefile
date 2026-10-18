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
# Compile .c files with kmc gcc (use strip to fix objects so that they can be linked with modern gnu ld) 
$(BUILD_DIR)/src/%.c.o: src/%.c
	@$(PRINT)$(GREEN)Compiling C file: $(ENDGREEN)$(BLUE)$<$(ENDBLUE)$(ENDLINE)
	@mkdir -p $(shell dirname $@)
	@$(CC_HOST) $(CFLAGS_CHECK) $(CPPFLAGS) -MMD -MP -MT $@ -MF $@.d -I include/ $<
	$(V)export COMPILER_PATH=tools/gcc_2.7.2 && $(CC) $(CFLAGS) $(CPPFLAGS) -I include/ -c -o $@ $<
	@$(STRIP) $@ -N dummy-symbol-name

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
