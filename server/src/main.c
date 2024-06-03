/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** main
*/

#include <stdio.h>

#include "app/app.h"

int main(void)
{
    app_t *app = create_app(4444);

    if (app == NULL)
        return 84;
    printf("Welcome to Server\n");
    server_run(app);
    destroy_app(app);
    return 0;
}
