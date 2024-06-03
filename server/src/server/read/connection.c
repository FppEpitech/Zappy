/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Read Connection
*/

#include "server/server.h"

bool server_connection_handler(server_t *server, size_t fd)
{
    (void) server;
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);

    int client_fd = accept(fd, (struct sockaddr *) &addr, &addr_len);
    (void) client_fd;
    printf("NEW CONNECTION !\n");
    return true;
}
