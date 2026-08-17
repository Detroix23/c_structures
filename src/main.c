// src/main.c
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "../include/structures/vectors.h"


/**
 * Test: first 2D vectors.
 */
void test_vectors1() {
    printf("\n## Test: vectors 1.\n");

    struct Vector2D v1 = {5.0, 14.0};

    printf("v1(%f, %f)\n", v1.x, v1.y);

    return;
}

/**
 * Test: playing around with memory.
 */
void test_memory1() {
    printf("\n## Test: memory 1.\n");

    int universe = 42;
    int* pointer1 = &universe;
    int** pointer2 = &pointer1;

    printf("Variable: %d\n", universe);
    printf("- Memory address: %p\n", pointer1);
    assert(pointer1 == *pointer2);
    printf("- Pointer of pointer: %p\n", pointer2);
    assert(pointer1 != (int*) pointer2);
    // Unsafe:
    // printf("- Int value of pointer of pointer: %d\n", *((int*) pointer2));
    printf("- `bool` size B=%ld \n", sizeof(true));
    printf("- `int` size B=%ld \n", sizeof(universe));
    printf("- `long int` size B=%ld \n", sizeof((long int) 42));
    printf("- `long unsigned int` size B=%ld \n", sizeof((long unsigned int) 42));
    printf("- `long long int` size B=%ld \n", sizeof((long long int) 42));
    printf("- `long long unsigned int` size B=%ld \n", sizeof((long long unsigned int) 42));

    return;
};

/**
 * Main entry point.
 */
int main() {
    printf("# Learn C.\n");
  
    // test_memory1();
    test_vectors1();

    printf("\n*End of `src/main.c`.*");
    return 0;
};
