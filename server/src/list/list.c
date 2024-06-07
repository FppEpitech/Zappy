/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** list
*/

#include <stdlib.h>
#include "list/type.h"

vector2i_t *vector2i_new(int x, int y)
{
    vector2i_t *new_coord = malloc(sizeof(vector2i_t));

    if (new_coord == NULL)
        return NULL;
    new_coord->x = x;
    new_coord->y = y;
    return new_coord;
}

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
