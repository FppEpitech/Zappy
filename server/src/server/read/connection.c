/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Read Connection
*/

#include <string.h>

#include "server/client.h"

bool server_connection_handler(app_t *app, size_t fd)
{
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);
    int client_fd = 0;
    node_data_t data;

    client_fd = accept(fd, (struct sockaddr *) &addr, &addr_len);
    if (client_fd == -1)
        return false;
    data.client = create_client(client_fd);
    if (data.client == NULL)
        return false;
    list_add_back(app->clients_list, data);
    write(client_fd, "WELCOME\n", strlen("WELCOME\n"));
    printf("NEW CONNECTION !\n");
    return true;
}
