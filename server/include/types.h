/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** Types for the server
*/

#pragma once

#include <stddef.h>
#include <stdbool.h>

/**
 * @brief Struct for parsing the arguments.
 *
 */
typedef struct s_parsing {
    int port;
    int width;
    int height;
    int clientsNb;
    int freq;
    char **names;
} parsing_t;

typedef struct s_vector2i {
    int x;
    int y;
} vector2i_t;

typedef struct s_egg {
    vector2i_t *pos;
    size_t id;
    bool is_laid;
    size_t id_player_laid;
} egg_t;
