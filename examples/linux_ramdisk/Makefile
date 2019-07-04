CC = gcc
PROGRAM = freertos_fat_ramdisk
BUILD_DIR = build

FREERTOS_FAT_DIR_NAME = FreeRTOS-Plus-FAT
FREERTOS_FAT_DIR_LEVEL = ../..
FREERTOS_FAT_DIR = $(FREERTOS_FAT_DIR_LEVEL)/$(FREERTOS_FAT_DIR_NAME)

ALL_SRC = $(wildcard $(FREERTOS_FAT_DIR)/*.c) \
	$(wildcard $(FREERTOS_FAT_DIR)/portable/common/*.c) \
        $(wildcard $(FREERTOS_FAT_DIR)/portable/no-os/*.c) \
        src/main.c

EXCLUDE_SRC = $(FREERTOS_FAT_DIR)/ff_dev_support.c \
        $(FREERTOS_FAT_DIR)/ff_locking.c \
        $(FREERTOS_FAT_DIR)/portable/no-os/heap_4.c

SRC = $(filter-out $(EXCLUDE_SRC), $(ALL_SRC))

OBJ_REL = $(subst $(FREERTOS_FAT_DIR_LEVEL)/,,$(SRC))
OBJ = $(OBJ_REL:%.c=$(BUILD_DIR)/%.o)

INC_FLAGS = -Iinclude \
        -I$(FREERTOS_FAT_DIR)/include \
	-I$(FREERTOS_FAT_DIR)/portable/common \
	-I$(FREERTOS_FAT_DIR)/portable/no-os/include \
	-I$(FREERTOS_FAT_DIR)/portable/linux/include

CFLAGS = $(INC_FLAGS) -g

all: $(BUILD_DIR)/$(PROGRAM)


$(BUILD_DIR)/$(PROGRAM): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(FREERTOS_FAT_DIR_LEVEL)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $^
	
$(BUILD_DIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -r $(BUILD_DIR)
