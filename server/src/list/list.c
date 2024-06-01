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

void list_remove_front(list_t *list)
{
    list_node_t *temp = NULL;

    if (list->first == NULL) {
        return;
    }
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

int list_add_back(list_t *list, node_data_t data)
{
    list_node_t *new = malloc(sizeof(list_node_t));

    if (new == NULL)
        return 84;
    new->data = data;
    new->next = NULL;
    new->prev = list->last;
    if (list->last != NULL)
        list->last->next = new;
    list->last = new;
    if (list->first == NULL)
        list->first = new;
    list->len += 1;
    return 0;
}

int list_add_front(list_t *list, node_data_t data)
{
    list_node_t *new = malloc(sizeof(list_node_t));

    if (new == NULL)
        return 84;
    new->data = data;
    new->next = list->first;
    new->prev = NULL;
    if (list->first != NULL)
        list->first->prev = new;
    list->first = new;
    if (list->last == NULL)
        list->last = new;
    list->len += 1;
    return 0;
}
