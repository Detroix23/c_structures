// src/structures/lists.c
#include "../../include/structures/lists.h"

struct LinkedList;

int linked_list_length(struct LinkedList *list)
{
    return (list->next) ? 1 + linked_list_length(list->next) : 1;
}
