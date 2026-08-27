// include/structures/list.h
#ifndef STRUCTURES_LIST_H
#define STRUCTURES_LIST_H

/**
 * # A one way `SimpleNode`
 * 
 * Attributes:
 * - `value`: `int`;
 * - `next`: `struct LinkedList *`;
 */
struct SimpleNode {
    int value;
    struct SimpleNode *next;
};

/**
 * Creates a new empty simple list;
 */
struct SimpleNode * linked_list_new();

/**
 * Creates recursively a `LinkedList` from an `array` of `length`.
 */
struct SimpleNode * linked_list_from_array(int *array, int length);

/**
 * Returns recursively the length of the given `LinkedList` `list`.
 */
int linked_list_length(struct SimpleNode *list);

/**
 * Walks `list` to prints in values
 * 
 * Format:
   ```
   < 1 2 3 ... >
   ``` 
 */
void linked_list_print(struct SimpleNode *list);

# endif
