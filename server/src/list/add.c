/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** list
*/

#include <stdlib.h>
#include <stdbool.h>

#include "list/type.h"

bool list_add_back(list_t *list, node_data_t data)
{
    list_node_t *new = malloc(sizeof(list_node_t));

    if (new == NULL)
        return false;
    new->data = data;
    new->next = NULL;
    new->prev = list->last;
    if (list->last != NULL)
        list->last->next = new;
    list->last = new;
    if (list->first == NULL)
        list->first = new;
    list->len += 1;
    return true;
}

bool list_add_front(list_t *list, node_data_t data)
{
    list_node_t *new = malloc(sizeof(list_node_t));

    if (new == NULL)
        return false;
    new->data = data;
    new->next = list->first;
    new->prev = NULL;
    if (list->first != NULL)
        list->first->prev = new;
    list->first = new;
    if (list->last == NULL)
        list->last = new;
    list->len += 1;
    return true;
}
