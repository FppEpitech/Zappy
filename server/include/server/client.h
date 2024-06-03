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

#include "app/app.h"

typedef struct s_client {
    int fd;
} client_t;

/**
 * @brief Create a client object.
 *
 * @param fd File descriptor of ia
 * @return client_t* Struct client initialized
 */
client_t *create_client(int fd);

/**
 * @brief Know if the fd in paramater is owned by a client.
 *
 * @param app App with list of clients.
 * @param fd File Descriptor to check.
 * @return true If parameter fd is owned by a client.
 * @return false If parameter fd isn't owned by a client.
 */
bool its_client(app_t *app, int fd);
