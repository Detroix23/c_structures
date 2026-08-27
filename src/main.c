// src/main.c
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "../include/structures/vectors.h"
#include "../include/structures/lists.h"

/**
 * Test: first 2D vectors.
 */
void test_vectors1() 
{
    printf("\n## Test: vectors 1.\n");

    struct Vector2D v1 = {4.0, 3.0};

    printf("|v1(%f, %f)| = %f\n", v1.x, v1.y, vector_length(&v1));

    struct Vector2D n1 = vector_normalized(&v1);
    printf("|n1(%f, %f)| = %f\n", n1.x, n1.y, vector_length(&n1));

    return;
}

/**
 * Test: first lists.
 */
void test_lists1() 
{
    printf("\n## Test: lists 1.\n");

    struct SimpleNode l1_3 = {3, NULL};
    struct SimpleNode l1_2 = {2, &l1_3};
    struct SimpleNode l1 = {1, &l1_2};
    
    printf("l1 length l=%d\n", linked_list_length(&l1));
    printf("l1: ");
    linked_list_print(&l1);
    printf("\n");


    int a2[] = {3, 4, 5, 6, 7, 8};
    struct SimpleNode *l2 = linked_list_from_array(a2, 6);
    printf("I/ l2 created ([0] = (%d, %p).\n", l2->value, l2->next);
    printf("1. %d (%p) \n", l2->value, l2->next);
    printf("2. %d (%p) \n", l2->next->value, l2->next->next);

    printf("l2 length l=%d\n", linked_list_length(l2));
    printf("l2: ");
    linked_list_print(l2);

    return;
};

/**
 * Test: playing around with memory.
 */
void test_memory1() 
{
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

    /*
    This function allocates an array of num elements each of which size in bytes will be size.
    `void *calloc(int num, int size);`
    
    This function releases a block of memory block specified by address.
    `void free(void *address);`
    
    This function allocates an array of num bytes and leave them uninitialized.
    `void *malloc(size_t size);`

    This function re-allocates memory extending it up to newsize.
    `void *realloc(void *address, int newsize);`
    */

    return;
};

/**
 * Prints the `int` `array` of given `size`.
 */
void array_print(int *array, int size)
{
    printf("Length of `array`: l=%ld \n", sizeof(array));
    printf("Length of `*array`: l=%ld \n", sizeof(*array));
    
    printf("[ ");
    for (int index = 0; index < size; index++) {
        printf("%d ", array[index]);
    }
    printf("] \n");
}

/**
 * Main entry point.
 */
int main() 
{
    printf("# C structures.\n");
  
    // test_memory1();
    // test_vectors1();
    test_lists1();

    // int *ptr0 = 0;
    // printf("*ptr0 = %d", *ptr0);

    printf("\n*End of `%s`.*", __FILE__);
    return 0;
};
