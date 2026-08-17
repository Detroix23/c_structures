# Makefile: from the ground up.
# 
# Pieces from:
# - https://makefiletutorial.com/
#
# Format:
#
# 	target: prerequisites (activate if newer than the target) 
# 		command
# 		...
#

CC := gcc
CFLAGS := -g -Wall -Wextra -Werror -Iinclude -std=c11
LIBRARIES := -lm

DIR_SRC := src
DIR_BIN := bin
DIR_LIB := lib
DIR_TEST := test
DIR_OBJECTS := objects
DIR_INCLUDE := include

# Every folder in ./src will need to be passed to GCC so that it can find header files
INC_DIRS := $(shell find $(DIR_SRC) -type d)
# Add a prefix to INC_DIRS. So moduleA would become -ImoduleA. GCC understands this -I flag
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

FILES_C := $(shell find $(DIR_SRC) -name '*.c')
FILES_O := $(patsubst $(DIR_SRC)/%.c,$(DIR_OBJECTS)/%.o,$(FILES_C))
# String substitution (suffix version without %).
# As an example, ./build/hello.cpp.o turns into ./build/hello.cpp.d
FILES_DEPS := $(FILES_O:.o=.d)
# TARGET := $(patsubst $(DIR_SRC)/%.c,$(DIR_BIN)/%,$(FILES_C))
TARGET := $(DIR_BIN)/main


# Default target (because first listed target).
all: $(TARGET)

run: $(TARGET)
	@echo "Running \`$@\` with \`$(ARGS)\`."
	@echo
	@./$(TARGET) $(ARGS)

# Linking object files to make executables.
$(TARGET): $(FILES_O)
	@echo "Linking \`$@\` from \`$^\`."
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBRARIES)

# Compiling C files to make object files.	
$(FILES_O): $(DIR_OBJECTS)/%.o: $(DIR_SRC)/%.c | $(DIR_INCLUDE)/%.h
	@echo "Compiling \`$@\` from \`$^\`."
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $^ -o $@

preview_code:
	@echo "Preview of files to be compiled: "
	@echo " "
	@echo "C: "
	@echo $(FILES_C)
	@echo " "
	@echo "O: "
	@echo $(FILES_O)
	@echo " "
	@echo "Targets: "
	@echo $(TARGET)

clean:
	rm -rf $(FILES_O) $(DIR_TEST)/*

# Mark these target not as files.
.PHONY: all clean preview_code
