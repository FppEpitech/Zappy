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

typedef struct s_app app_t;

typedef struct s_ia {
    size_t fd;
    size_t level;
} ia_t;

/**
 * @brief Create a ia object.
 *
 * @param fd File descriptor of ia.
 * @return ia_t* Struct ia initialized.
 */
ia_t *create_ia(int fd);

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
