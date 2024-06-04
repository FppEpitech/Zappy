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
    (void) argc;
    app_t *app = create_app(atoi(argv[1]));

    if (app == NULL)
        return 84;

    node_data_t data;
    data.team = create_team(strdup("team 1\r"), 4);
    list_add_front(app->teams_list, data);

    node_data_t data_1;
    data_1.team = create_team(strdup("team 2\r"), 4);
    list_add_front(app->teams_list, data_1);


    printf("Welcome to Server\n");
    server_run(app);
    destroy_app(app);
    return 0;
}
