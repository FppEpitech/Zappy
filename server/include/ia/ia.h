/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Ia struct
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
 * @brief Create a IA object.
 *
 * @param app Application with list of team.
 * @param fd File descriptor of IA.
 * @param team Team of IA
 * @return ia_t* Struct ia initialized.
 */
ia_t *create_ia(app_t *app, int fd, team_t *team);

/**
 * @brief Add ia to the corresponding team
 *
 * @param app Application with list of team.
 * @param fd File descriptor of IA.
 * @param line Line with name of the team.
 * @return true If no error.
 * @return false If error.
 */
bool add_ia(app_t *app, size_t fd, char *line);

/**
 * @brief Find the IA throught a file descriptor.
 *
 * @param app Application with list of IA.
 * @param fd File descriptor of IA to find.
 * @return ia_t* Ia find or NULL if not find.
 */
ia_t *find_ia(app_t *app, size_t fd);
