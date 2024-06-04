/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Team struct
*/

#pragma once

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list/list.h"

typedef struct s_team {
    list_t *list_ai;
    char *name;
    int max_place;
} team_t;

/**
 * @brief Create a team object.
 *
 * @param name Name of the team.
 * @param max_place Max place in a team
 * @return team_t* Team created.
 */
team_t *create_team(char *name, int max_place);
