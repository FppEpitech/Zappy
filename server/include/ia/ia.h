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

typedef struct s_ia {
    int     fd;
    size_t  level;
    bool    have_team;
} ia_t;

/**
 * @brief Create a ia object
 *
 * @param fd File descriptor of ia
 * @return ia_t* Struct ia initialized
 */
ia_t *create_ia(int fd);
