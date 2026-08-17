# From: Mistral AI.

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude -std=c11
LDFLAGS = -Llib
LIBRARIES = -lmodule1

# Directories
SRC_DIR = src
INCLUDE_DIR = include
LIB_DIR = lib
BIN_DIR = bin

# Files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,%.o,$(SRCS))
DEPS = $(OBJS:.o=.d)
TARGET = $(BIN_DIR)/my_program



# Default target
all: $(TARGET)

# Link object files into executable
$(TARGET): $(OBJS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(LIBRARIES)

# Compile .c files into .o files
%.o: $(SRC_DIR)/%.c | $(INCLUDE_DIR)/%.h
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

# Include dependency files
-include $(DEPS)

# Clean build artifacts
clean:
	rm -rf $(OBJS) $(DEPS) $(TARGET)

# Phony targets (not files)
.PHONY: all clean

# Create static library (example for module1)
libmodule1.a: $(SRC_DIR)/module1.o
	ar rcs $(LIB_DIR)/$@ $^
