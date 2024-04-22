PROJ_NAME := Project_01
PATH_MAKEFILE := C:/Users/Admins/OneDrive/Desktop/TrainningEmbedded/_Make_File
PATH_COMPILER := C:/NXP/S32DS_ARM_v2.2/S32DS/build_tools/gcc_v6.3/gcc-6.3-arm32-eabi
#link nay thay doi theo tuy folder

SOURCE_DIRS := $(PATH_MAKEFILE)/Source
INCLUDE_DIRS := $(PATH_MAKEFILE)/Include

SOURCE_FILES := $(foreach SOURCE_DIRS, $(SOURCE_DIRS), $(wildcard $(SOURCE_DIRS)/*.c))
INCLUDE_FILES := $(foreach INCLUDE_DIRS, $(INCLUDE_DIRS), $(wildcard $(INCLUDE_DIRS)/*.h))
#in ra duong link cua cac files

LINKER_FILE := ./linker/TuanLDM_s32k144.ld
CC := $(PATH_COMPILER)/bin/arm-none-eabi-gcc.exe
LD := $(PATH_COMPILER)/bin/arm-none-eabi-ld.exe

INCLUDE_DIRS_OPT := $(foreach INCLUDE_DIRS, $(INCLUDE_DIRS), -I$(INCLUDE_DIRS))
CC_OPT := -mcpu=cortex-m4 -c -O0 -g -mfloat-abi=soft -std=gnu11 -gthumb $(INCLUDE_DIRS_OPT)
LD_OPT := 	-T $(LINKER_FILE)	-Map ./Output/$(PROJ_NAME).map


OBJ_FILES := $(notdir $(SOURCE_FILES))
#in ra cac files (xoa het link, chi in ra file cho de nhin)
OBJ_FILES := $(subst .c,.o,$(OBJ_FILES))
#sua text tu text.c -> text.o
OBJ_DIRS := $(foreach OBJ_FILES, $(OBJ_FILES), ./Output/$(OBJ_FILES))

vpath %.c $(SOURCE_DIRS)
vpath %.h $(INCLUDE_DIRS)

build: $(OBJ_FILES) $(LINKER_FILE)
	$(LD) $(LD_OPT) $(OBJ_DIRS) -o ./Output/$(PROJ_NAME).elf
	$(PATH_COMPILER)/arm-none-eabi/bin/objcopy.exe -O ihex "./Output/$(PROJ_NAME).elf" "./Output/$(PROJ_NAME).hex"
	size ./Output/$(PROJ_NAME).elf
	@echo "--------------Build Done-----------"

%.o: %.c $(INCLUDE_FILES)
	mkdir -p ./Output
	$(CC) $(CC_OPT) -c $< -o ./Output/$@

.PHONY: clean
clean:
	rm ./Output/*

print-%:
	@echo $($(subst print-,,$@))
	