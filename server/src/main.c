/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** main
*/

#include <stdio.h>

#include "app/app.h"


#include "list/list.h"
#include "ia/team.h"
#include <string.h>

int main(int argc, char **argv)
{
    app_t *app = create_app(atoi(argv[1]));

    (void) argc;
    if (app == NULL)
        return 84;
    printf("Welcome to Server\n");
    server_run(app);
    destroy_app(app);
    return 0;
}
