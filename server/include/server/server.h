/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Server struct
*/

#pragma once

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/select.h>
#include <netinet/in.h>

#define LISTEN_NUMBER 100

typedef struct s_server {
    fd_set read_fds;
    fd_set write_fds;
    int server_fd;
    socklen_t addrlen;
    struct sockaddr_in addr;
} server_t;

/**
 * @brief Destroy the server.
 *
 * @param server The server to destroy.
 */
void destroy_server(server_t *server);

/**
 * @brief Create a server object
 *
 * @param port Port on witch bind server.
 * @return server_t* Server init.
 */
server_t *create_server(size_t port);
