/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Server struct
*/

#pragma once

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/select.h>
#include <netinet/in.h>

#define LISTEN_NUMBER 100

typedef struct s_app app_t;

typedef struct s_server {
    fd_set read_fds;
    fd_set write_fds;
    int fd;
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

/**
 * @brief Run the server
 *
 * @param app App struct with all necessary information (server, gui, client).
 * @return bool True if success else false.
 */
bool server_run(app_t *app);

/**
 * @brief Handler of server connection.
 *
 * @param app App struct with all necessary information (server, gui, client).
 * @param fd File Descriptor of th client who try to connect.
 * @return bool True if success else false.
 */
bool server_connection_handler(app_t *app, size_t fd);

/**
 * @brief Handler of server data reception.
 *
 * @param app App struct with all necessary information (server, gui, client).
 * @param fd File Descriptor of th client who try to connect.
 * @return bool True if success else false.
 */
bool server_data_handler(app_t *app, size_t fd);

/**
 * @brief Read a line from a file descriptor.
 *
 * @param fd File descriptor where read the line
 * @return char* The line readed.
 */
char *read_line(int fd);
