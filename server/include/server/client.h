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
    size_t fd;
} client_t;

/**
 * @brief Create a client object.
 *
 * @param fd File descriptor of ai.
 * @return client_t* Struct client initialized.
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
bool its_client(app_t *app, size_t fd);

/**
 * @brief Find a client thanks to an file descriptor.
 *
 * @param clients_list List of clients.
 * @param fd File descriptor of client.
 * @return list_node_t* Node of client.
 */
list_node_t *find_client(list_t *clients_list, size_t fd);

/**
 * @brief Destroy list of client.
 *
 * @param client_list List of client to destroy.
 */
void destroy_client(list_t *client_list);
