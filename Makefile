# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror

# Source and build directories
SRC_DIR = src
BUILD_DIR = ../../build

# Source files (all .c files in src directory)
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

# Object files (corresponding .o files in build directory)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))

# Executable name
TARGET = $(notdir $(patsubst %/,%,$(dir $(realpath $(lastword $(MAKEFILE_LIST))))))

# Default target
all: clean $(TARGET) rm_junk move run

# Rule to build the executable
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to build object files from source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# ////////////////// Routines

clean:
	rm -f $(TARGET) $(OBJ_FILES)

move:
	mv $(TARGET) ../../build

rm_junk:
	rm -f $(OBJ_FILES)

run:
	@clear
	@echo "////// RUNNING [ $(TARGET) ]"
	@echo
	@../../build/$(TARGET)
	@echo
	@echo

.PHONY: all clean
