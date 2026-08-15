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

CC = gcc
ALL_C_FILES = $(wildcard */*.c)

# Default target (because first listed target).
all: bin/hello test/test1

test/test1: 
	touch test/test1

bin/hello.o: src/hello.c
	echo "Compiling $@"
	$(CC) -c $^ -o $@

print: ALL_C_FILES
	echo "$?"

clean:
	rm -rf bin/*
	rm -rf test/*
