/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Type of List
*/

#pragma once

#include <stddef.h>

#include "ia/ia.h"
#include "server/client.h"

typedef union s_node_data {
    ia_t *ia;
    client_t *client;
} node_data_t;

typedef struct s_list_node {
    node_data_t data;
    struct s_list_node *next;
    struct s_list_node *prev;
} list_node_t;

typedef struct s_list {
    list_node_t *first;
    list_node_t *last;
    size_t len;
} list_t;
