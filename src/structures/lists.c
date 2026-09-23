// src/structures/lists.c
#include <stdlib.h>
#include <stdio.h>

#include "../../include/structures/lists.h"


struct SimpleNode;

struct SimpleNode * linked_list_new() { return NULL; }

/** Create linked `SimpleNode`s from an `array` with `length`. */
struct SimpleNode * linked_list_from_array(int *array, int length)
{
    struct SimpleNode *node = malloc(sizeof(struct SimpleNode));
    node->value = array[0];
    node->next = (length > 1) ? linked_list_from_array(&array[1], length - 1) : NULL;

    printf("%s %s() v=%d, p=%p \n", __FILE__, __func__, array[0], (void *) node->next);

    return node;
}

/** Returns the length of the `list`. */
int linked_list_length(struct SimpleNode *list)
{
    return (list->next) ? 1 + linked_list_length(list->next) : 1;
}

/** Prints nicely `list` to the console. */
void linked_list_print(struct SimpleNode *list)
{
    struct SimpleNode *current = list;
    printf("< \n");
    printf(" %d (%p) \n", current->value, (void *) current->next);

    while (current->next != NULL) {
        current = current->next;
        printf(" %d (%p) \n", current->value, (void *) current->next);
    }
    printf(">");

    return;
}

