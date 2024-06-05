/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** app
*/

#include "app/app.h"

static void create_teams(parsing_t *parsing, app_t *app)
{
    for (size_t index = 0; parsing->names[index]; index++) {
        add_team(app->teams_list, parsing->names[index], parsing->clientsNb);
    }
}

app_t *create_app(parsing_t *parsing)
{
    app_t *new_app = malloc(sizeof(app_t));

    if (new_app == NULL)
        return NULL;
    new_app->server = create_server(parsing->port);
    new_app->game = create_game(parsing->height, parsing->width);
    if (new_app->server == NULL || new_app->game == NULL)
        return NULL;
    new_app->gui_list = malloc(sizeof(list_t));
    new_app->clients_list = malloc(sizeof(list_t));
    new_app->teams_list = malloc(sizeof(list_t));
    create_teams(parsing, new_app);
    if (new_app->gui_list == NULL || new_app->clients_list == NULL
    || new_app->teams_list == NULL)
        return NULL;
    return new_app;
}

void destroy_app(app_t *app)
{
    destroy_server(app->server);
    list_free(app->gui_list);
    list_free(app->clients_list);
    list_free(app->teams_list);
}
