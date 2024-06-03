/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** client
*/

#include "server/client.h"

client_t *create_client(int fd)
{
    client_t *new_client = malloc(sizeof(client_t));

    if (new_client == NULL)
        return NULL;
    new_client->fd = fd;
    return new_client;
}

bool its_client(app_t *app, int fd)
{
    list_node_t *temp = app->clients_list->first;
    client_t *client = NULL;

    while (temp) {
        client = temp->data.client;
        if (client->fd == fd)
            return true;
        temp = temp->next;
    }
    return false;
}
