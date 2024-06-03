/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Read Connection
*/

#include <string.h>

#include "ia/ia.h"
#include "app/app.h"

bool server_connection_handler(app_t *app, size_t fd)
{
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);
    int ia_fd = 0;
    node_data_t data;

    ia_fd = accept(fd, (struct sockaddr *) &addr, &addr_len);
    if (ia_fd == -1)
        return false;
    data.ia = create_ia(ia_fd);
    list_add_back(app->ia, data);
    printf("NEW CONNECTION !\n");
    return true;
}
