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

typedef struct s_ia {
    size_t fd;
    list_t *list_messages;
    size_t level;
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
 * @brief Add ai to the corresponding team
 *
 * @param app Application with list of team.
 * @param fd File descriptor of AI.
 * @param line Line with name of the team.
 * @return true If no error.
 * @return false If error.
 */
bool add_ia(app_t *app, size_t fd, char *line);

/**
 * @brief Find the AI throught a file descriptor.
 *
 * @param app Application with list of AI.
 * @param fd File descriptor of AI to find.
 * @return ia_t* AI find or NULL if not find.
 */
ia_t *find_ia(app_t *app, size_t fd);
