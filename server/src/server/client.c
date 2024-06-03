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
