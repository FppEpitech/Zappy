/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Read data
*/

#include "server/server.h"

bool server_data_handler(server_t *server, size_t fd)
{
    (void) server;
    char buffer[1024 + 1] = {0};
    ssize_t bytes_read = 0;

    bytes_read = read(fd, buffer, 1024);
    if (bytes_read <= 0)
        return false;
    buffer[bytes_read] = '\0';
    printf("DATA: [%s]\n", buffer);
    return true;
}
