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
    list_t *eggs_list;
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
 * @brief Add an egg in the list.
 *
 * @param eggs List of eggs.
 * @param id_player_laid Id of the player who laid the egg.
 * @param app Application with list of team.
 */
void add_egg(list_t *eggs, int id_player_laid, app_t *app);

/**
 * @brief Add an egg on the player.
 *
 * @param eggs Eggs list.
 * @param id_player_laid Id of player.
 * @param app Application with all information
 * @param ai AI who want add an egg.
 */
void add_egg_on_player(list_t *eggs, int id_player_laid,
    app_t *app, ia_t *ai);

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
