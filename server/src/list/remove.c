/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** list
*/

#include <stdlib.h>
#include "list/type.h"

void list_remove_front(list_t *list)
{
    list_node_t *temp = NULL;

    if (list->first == NULL)
        return;
    temp = list->first;
    list->first = list->first->next;
    if (list->first != NULL)
        list->first->prev = NULL;
    else
        list->last = NULL;
    free(temp);
    list->len -= 1;
}

void list_remove_back(list_t *list)
{
    list_node_t *temp = NULL;

    if (list->last == NULL)
        return;
    temp = list->last;
    list->last = list->last->prev;
    if (list->last != NULL)
        list->last->next = NULL;
    else
        list->first = NULL;
    free(temp);
    list->len -= 1;
}

void list_delete(list_t *list, list_node_t *node)
{
    if (node == NULL)
        return;
    if (node == list->first) {
        list_remove_front(list);
    } else if (node == list->last) {
        list_remove_back(list);
    } else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        free(node);
        list->len -= 1;
    }
}
