/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Type of List
*/

#pragma once

#include <stddef.h>

#include "types.h"

typedef struct s_ia ia_t;
typedef struct s_gui gui_t;
typedef struct s_team team_t;
typedef struct s_client client_t;
typedef struct s_vector2i vector2i_t;

typedef union s_node_data {
    ia_t *ai;
    gui_t *gui;
    client_t *client;
    team_t *team;
    char *message;
    char *command;
    vector2i_t *coord;
    egg_t *egg;
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
