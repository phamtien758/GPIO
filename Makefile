COMPILER := arm-none-eabi-gcc
CPU := cortex-m4
CFLAGS := -mthumb -Wall -O0 -mcpu=$(CPU)
LINKER_SCRIPT_FILE = ./Linker_script/STM32F401RETX_FLASH.ld
APPLICATION_FILE := ./App/*
INCLUDE := ./driver/Inc
OUTPUT_DIR := output
ELF_FILE := out.elf

OZONE_DIR := D:/SEGGER/Ozone/Ozone.exe
OZONE_CFG := ozone_config.jdebug

SRC_FILE = Startup/startup_stm32f401retx.s
SRC_FILE += driver/Src/gpio.c
SRC_FILE += App/syscalls.c
SRC_FILE += App/sysmem.c
SRC_FILE += App/main.c

# Object files
OBJEC = $(OUTPUT_DIR)/startup_stm32f401retx.o
OBJEC += $(OUTPUT_DIR)/gpio.o
OBJEC += $(OUTPUT_DIR)/syscalls.o
OBJEC += $(OUTPUT_DIR)/sysmem.o
OBJEC += $(OUTPUT_DIR)/main.o

# Make object files
mk_obj: make_dir $(OBJEC)

$(OUTPUT_DIR)/startup_stm32f401retx.o: Startup/startup_stm32f401retx.s
	$(COMPILER) -c $(CFLAGS) -I $(INCLUDE) $^ -o $@

$(OUTPUT_DIR)/gpio.o: driver/Src/gpio.c
	$(COMPILER) -c $(CFLAGS) -I $(INCLUDE) $^ -o $@

$(OUTPUT_DIR)/syscalls.o: App/syscalls.c
	$(COMPILER) -c $(CFLAGS) -I $(INCLUDE) $^ -o $@

$(OUTPUT_DIR)/sysmem.o: App/sysmem.c
	$(COMPILER) -c $(CFLAGS) -I $(INCLUDE) $^ -o $@

$(OUTPUT_DIR)/main.o: App/main.c
	$(COMPILER) -c $(CFLAGS) -I $(INCLUDE) $^ -o $@

# Load elf to target board
debug: build
	$(OZONE_DIR) -project $(OZONE_CFG)

# Make elf file for debug
build: make_dir
	$(COMPILER) -g $(CFLAGS) -T $(LINKER_SCRIPT_FILE) -I $(INCLUDE) $(SRC_FILE) -o $(OUTPUT_DIR)/$(ELF_FILE)

# Create output folder
make_dir:
	mkdir -p $(OUTPUT_DIR)

# Clean all output
clean:
	rm -rf $(OUTPUT_DIR)