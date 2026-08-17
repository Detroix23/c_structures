// include/structures/list.h
#ifndef STRUCTURES_LIST_H
#define STRUCTURES_LIST_H

/**
 * # A one way `LinkedList`
 * 
 * Attributes:
 * - `value`: `int`;
 * - `next`: `struct LinkedList *`;
 */
struct LinkedList {
    int value;
    struct LinkedList *next;
};

/**
 * Returns recursively the length of the given `LinkedList` `list`.
 */
int linked_list_length(struct LinkedList *list);

# endif
