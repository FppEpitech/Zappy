/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Read Connection
*/

#include <string.h>

#include "app/app.h"

bool server_connection_handler(app_t *app, size_t fd)
{
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);
    size_t client_fd = 0;

    client_fd = accept(fd, (struct sockaddr *) &addr, &addr_len);
    (void) client_fd;
    (void) app;
    printf("NEW CONNECTION !\n");
    return true;
}
