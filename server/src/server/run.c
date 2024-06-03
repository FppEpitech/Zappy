/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** run
*/

#include "server/server.h"

static int server_reset_fd(server_t *server)
{
    FD_ZERO(&server->read_fds);
    FD_ZERO(&server->write_fds);
    FD_SET(server->server_fd, &server->read_fds);
    return 0;
}

static int handle_client_read(server_t *server, size_t fd)
{
    if (FD_ISSET(fd, &server->read_fds)) {
        if (fd == server->server_fd) {
            server_connection_handler(server, fd);
        } else {
            server_data_handler(server, fd);
        }
    }
    return 0;
}

static int handle_client_write(server_t *server, size_t fd)
{
    (void) server;
    (void) fd;
    return 0;
}

bool server_run(server_t *server)
{
    while (true) {
        server_reset_fd(server);
        if (select(FD_SETSIZE, &server->read_fds,
        &server->write_fds, NULL, NULL) < 0)
            return false;
        for (size_t fd = 0; fd < FD_SETSIZE; fd++) {
            handle_client_read(server, fd);
            handle_client_write(server, fd);
        }
    }
    return true;
}
