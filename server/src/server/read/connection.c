/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Read Connection
*/

#include <string.h>

#include "server/server.h"

static void connection_gui(server_t *server, size_t client_fd)
{
    server->gui->connected = true;
    server->gui->fd = client_fd;
}

static void connection_ai(server_t *server, size_t client_fd)
{

}

bool server_connection_handler(server_t *server, size_t fd)
{
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);
    size_t client_fd = 0;
    char *team = NULL;

    client_fd = accept(fd, (struct sockaddr *) &addr, &addr_len);
    write(client_fd, "WELCOME\n", strlen("WELCOME\n"));
    team = read_line(client_fd);
    if (strcmp(team, "GRAPHIC\n") == 0) {
        if (server->gui->connected = false) {
            connection_gui(server, client_fd);
        }
    } else {
        connection_ai(server, client_fd);
    }
    printf("NEW CONNECTION !\n");
    return true;
}
