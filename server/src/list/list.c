/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** list
*/

#include <stdlib.h>
#include "list/type.h"

list_t *list_new(void)
{
    list_t *list = malloc(sizeof(list_t));

    if (list == NULL)
        return NULL;
    list->first = NULL;
    list->last = NULL;
    list->len = 0;
    return list;
}

void list_free(list_t *list)
{
    list_node_t *node = list->first;
    list_node_t *next = NULL;

    while (node) {
        next = node->next;
        free(node);
        node = next;
    }
    free(list);
}
