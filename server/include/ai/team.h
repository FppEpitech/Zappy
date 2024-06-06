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
    size_t max_place;
} team_t;

/**
 * @brief Create a team object.
 *
 * @param name Name of the team.
 * @param max_place Max place in a team.
 * @return team_t* Team created.
 */
team_t *create_team(char *name, size_t max_place);

/**
 * @brief Add a team in the list.
 *
 * @param teams List of teams.
 * @param team_name Name of the team to add.
 * @param max_place Maximum places in a team.
 */
void add_team(list_t *teams, char *team_name, size_t max_place);
