/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Client
*/

#pragma once

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_client {
    int     fd;
} client_t;

/**
 * @brief Create a client object
 *
 * @param fd File descriptor of ia
 * @return client_t* Struct client initialized
 */
client_t *create_client(int fd);
