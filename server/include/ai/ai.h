/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI
*/

#pragma once

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list/list.h"

typedef struct s_app app_t;

typedef enum {
    NORTH = 1,
    EAST,
    SOUTH,
    WEST,
} orientation_t;

typedef struct s_inventory {
    size_t food;
    size_t linemate;
    size_t deraumere;
    size_t sibur;
    size_t mendiane;
    size_t phiras;
    size_t thystame;
} inventory_t;

typedef struct s_time_info {
    bool stuck;
    struct timeval start_stuck;
    double total_stuck;
    struct timeval start_life;
    double total_life;
} time_info_t;

typedef struct s_incantation_info {
    bool status_incantation;
    size_t target_level;
} incantation_info_t;

typedef struct s_ia {
    size_t fd;
    list_t *list_command;
    list_t *list_messages;
    vector2i_t *position;
    orientation_t direction;
    inventory_t *inventory;
    incantation_info_t *incantation;
    size_t level;
    time_info_t *time;
    char *team_name;
} ia_t;

/**
 * @brief Create a AI object.
 *
 * @param app Application with list of team.
 * @param fd File descriptor of AI.
 * @param team Team of AI.
 * @return ia_t* Struct ai initialized.
 */
ia_t *create_ia(app_t *app, int fd, team_t *team);

/**
 * @brief Add ai to the corresponding team.
 *
 * @param app Application with list of team.
 * @param fd File descriptor of AI.
 * @param line Line with name of the team.
 */
void add_ia(app_t *app, size_t fd, char *line);

/**
 * @brief Find the AI throught a file descriptor.
 *
 * @param app Application with list of AI.
 * @param fd File descriptor of AI to find.
 * @return ia_t* AI find or NULL if not find.
 */
ia_t *find_ia(app_t *app, size_t fd);

/**
 * @brief Check if an AI die.
 *
 * @param app Application with list of AI.
 */
void check_die(app_t *app);
