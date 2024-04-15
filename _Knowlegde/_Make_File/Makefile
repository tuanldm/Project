
PATH_MAKEFILE := C:/Users/Admins/OneDrive/Desktop/TrainningEmbedded/_Make_File
#link nay thay doi theo tuy folder

SOURCE_DIRS := $(PATH_MAKEFILE)/Source
INCLUDE_DIRS := $(PATH_MAKEFILE)/Include

SOURCE_FILES := $(foreach SOURCE_DIRS, $(SOURCE_DIRS), $(wildcard $(SOURCE_DIRS)/*.c))
INCLUDE_FILES := $(foreach INCLUDE_DIRS, $(INCLUDE_DIRS), $(wildcard $(INCLUDE_DIRS)/*.h))
#in ra duong link cua cac files

OBJ_FILES := $(notdir $(SOURCE_FILES))
#in ra cac files (xoa het link, chi in ra file cho de nhin)
OBJ_FILES := $(subst .c,.o,$(OBJ_FILES))
#sua text tu text.c -> text.o

main.o:
	gcc -c ./Source/main.c -o "./Output/main.o"
	gcc -c ./Source/main_01.c -o "./Output/main_01.o"

build: main.o
	gcc "./Output/main_01.o" -o "./Output/LapTrinh.exe"
	"./Output/LapTrinh.exe"

.PHONY: clean
clean:
	rm ./Output/*

print-%:
	@echo $($(subst print-,,$@))
	