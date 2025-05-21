# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99
DEBUG_FLAGS = -g -O0
RELEASE_FLAGS = -O2

# Project files
SRC_DIR = src
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(SRC_FILES:.c=.o)
MAIN_SRC = folderGen.c
MAIN_OBJ = $(MAIN_SRC:.c=.o)
TARGET = folderGen

# Default target
all: $(TARGET)

# Compile the main program
$(TARGET): $(MAIN_OBJ) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(RELEASE_FLAGS) -o $@ $^

# Compile source files
%.o: %.c
	$(CC) $(CFLAGS) $(RELEASE_FLAGS) -c $< -o $@

# Debug build
debug: CFLAGS += $(DEBUG_FLAGS)
debug: clean $(TARGET)

# Clean build files
clean:
	rm -f $(TARGET) *.o $(SRC_DIR)/*.o

# Run the program
run: $(TARGET)
	./$(TARGET)

# Help target
help:
	@echo "Available targets:"
	@echo "  all      - Build the program (default)"
	@echo "  debug    - Build with debug flags"
	@echo "  clean    - Remove all built files"
	@echo "  run      - Build and run the program"
	@echo "  help     - Show this help message"

.PHONY: all debug clean run help
