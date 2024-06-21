/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** server
*/

#include "server/server.h"

#include <sys/time.h>

static bool init_server(server_t *server)
{
    if (server->fd < 0)
        return false;
    if (bind(server->fd, (struct sockaddr *) &server->addr,
        server->addrlen) < 0)
        return false;
    if (listen(server->fd, LISTEN_NUMBER) < 0)
        return false;
    return true;
}

server_t *create_server(size_t port)
{
    server_t *new_server = malloc(sizeof(server_t));

    if (new_server == NULL)
        return NULL;
    new_server->addr.sin_family = AF_INET;
    new_server->addr.sin_addr.s_addr = INADDR_ANY;
    new_server->addr.sin_port = htons(port);
    new_server->addrlen = sizeof(new_server->addr);
    new_server->fd = socket(AF_INET, SOCK_STREAM, 0);
    if (init_server(new_server) == false) {
        printf("WARNING: [Port is still used]\n");
        free(new_server);
        return NULL;
    }
    return new_server;
}

void destroy_server(server_t *server)
{
    close(server->fd);
    free(server);
}
