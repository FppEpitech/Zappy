/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** entities
*/

#pragma once

#include <stdbool.h>

#include "list.h"

/**
* @brief Enum for the different types of entities.
*/
typedef enum entity_type_e {
    EGG,
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    NONE
} type_e;

/**
* @brief Struct of an entity.
*/
typedef struct entity_s
{
    type_e type;
} entity_t;

/**
* @brief Struct of a player.
*/
typedef struct player_s {
    bool hatched;
    int x;
    int y;
    list_t *inventory;
    int level;
    char *team_name;
} player_t;
