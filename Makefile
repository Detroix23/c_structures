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
LDFLAGS := -Llib

DIR_SRC := src
DIR_BIN := bin
DIR_LIB := lib
DIR_TEST := test
DIR_OBJECTS := objects
DIR_INCLUDE := include

FILES_C := $(wildcard $(DIR_SRC)/*.c)
FILES_O := $(patsubst $(DIR_SRC)/%.c,$(DIR_OBJECTS)/%.o,$(FILES_C))
FILES_TARGETS := $(patsubst $(DIR_SRC)/%.c,$(DIR_BIN)/%,$(FILES_C))

# Default target (because first listed target).
all: $(FILES_TARGETS)

# Linking object files to make executables.
$(FILES_TARGETS): $(DIR_BIN)/%: $(DIR_OBJECTS)/%.o
	@echo "Linking \`$@\` from \`$^\`"
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $^ 

# Compiling C files to make object files.
$(FILES_O): $(DIR_OBJECTS)/%.o: $(DIR_SRC)/%.c
	@echo "Compiling \`$@\` from \`$^\`"
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
	@echo $(FILES_TARGETS)

clean:
	rm -rf $(FILES_O) $(DIR_TEST)/*

# Mark these target not as files.
.PHONY: all clean preview_code
