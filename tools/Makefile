# Fetches the tools that are not committed: IDO 5.3 (static recompilation, for the libleo units)
# and asm-processor (INCLUDE_ASM inside IDO-compiled C). Run `make -C tools` once after cloning.

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	DETECTED_OS := linux
else ifeq ($(UNAME_S),Darwin)
	DETECTED_OS := macos
endif

IDO_53_DIR    := ido_recomp/$(DETECTED_OS)/5.3
IDO_53_CC     := $(IDO_53_DIR)/cc

ASM_PROC_REV  := f3b2f85a5bc7e8ae2030ea5a83ea8aa0bcbede03
ASM_PROC_DIR  := asm-processor
ASM_PROC      := $(ASM_PROC_DIR)/build.py

all: $(IDO_53_CC) $(ASM_PROC)

clean:
	$(RM) -rf ido_recomp $(ASM_PROC_DIR)

.PHONY: all clean

$(IDO_53_CC):
	mkdir -p $(IDO_53_DIR)
	wget https://github.com/decompals/ido-static-recomp/releases/latest/download/ido-5.3-recomp-$(DETECTED_OS).tar.gz
	tar xf ido-5.3-recomp-$(DETECTED_OS).tar.gz -C $(IDO_53_DIR)
	$(RM) ido-5.3-recomp-$(DETECTED_OS).tar.gz

$(ASM_PROC):
	mkdir -p $(ASM_PROC_DIR)
	wget -O asm-processor.tar.gz https://github.com/simonlindholm/asm-processor/archive/$(ASM_PROC_REV).tar.gz
	tar xf asm-processor.tar.gz -C $(ASM_PROC_DIR) --strip-components=1
	$(RM) asm-processor.tar.gz
