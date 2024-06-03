/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** main
*/

#include <stdio.h>

#include "server/server.h"

int main(void)
{
    printf("Welcome to Server\n");
    server_t *server = create_server(4444);

    server_run(server);
    return 0;
}
