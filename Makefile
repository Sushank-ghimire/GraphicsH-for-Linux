# Compiler
CC := gcc

# Project name
TARGET := app

# Directories
SRC_DIR := src
GFX_DIR := gfx
BUILD_DIR := build

# Flags
CFLAGS := -Wall -Wextra -I$(GFX_DIR)
LDFLAGS := -lSDL2

# Source files
SRC := $(SRC_DIR)/main.c \
       $(GFX_DIR)/gfx.c

# Object files
OBJ := $(SRC:%.c=$(BUILD_DIR)/%.o)

# Default rule
all: $(TARGET)

# Link
$(TARGET): $(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS)

# Compile
$(BUILD_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Cleanup
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Full rebuild
rebuild: clean all

.PHONY: all clean rebuild
