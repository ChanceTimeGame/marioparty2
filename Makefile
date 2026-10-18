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
