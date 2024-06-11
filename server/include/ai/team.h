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

typedef struct s_app app_t;

typedef struct s_team {
    list_t *list_ai;
    list_t *egg_position;
    char *name;
    size_t max_place;
} team_t;

/**
 * @brief Create a team object.
 *
 * @param name Name of the team.
 * @param max_place Max place in a team.
 * @param app Application with list of team.
 * @return team_t* Team created.
 */
team_t *create_team(app_t *app, char *name, size_t max_place);

/**
 * @brief Add a team in the list.
 *
 * @param app Application with list of teams.
 * @param team_name Name of the team to add.
 * @param max_place Maximum places in a team.
 */
void add_team(app_t *app, char *team_name, size_t max_place);

/**
 * @brief Display all egg position of all team.
 *
 * @param app Application with list of team.
 */
void display_egg_position(app_t *app);

/**
 * @brief Add egg in the list.
 *
 * @param eggs List of egg.
 * @param random_x Position x of egg.
 * @param random_y Position y of egg.
 */
void add_egg(list_t *eggs, int random_x, int random_y);

/**
 * @brief Find the team of fd given.
 *
 * @param app Application with list of teams.
 * @param fd File descriptor of the team to find.
 * @return team_t* Team finded.
 */
team_t *find_team(app_t *app, size_t fd);

/**
 * @brief Destroy the teams.
 *
 * @param teams_list Teams list.
 */
void destroy_team(list_t *teams_list);
