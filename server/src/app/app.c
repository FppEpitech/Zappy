/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** app
*/

#include "app/app.h"

app_t *create_app(size_t port)
{
    app_t *new_app = malloc(sizeof(app_t));

    if (new_app == NULL)
        return NULL;
    new_app->server = create_server(port);
    new_app->gui = malloc(sizeof(gui_t));
    new_app->gui->connected = false;
    new_app->gui->fd = 0;
    new_app->clients_list = malloc(sizeof(list_t));
    if (new_app->gui == NULL || new_app->clients_list == NULL)
        return NULL;
    return new_app;
}

void destroy_app(app_t *app)
{
    free(app->gui);
    destroy_server(app->server);
    list_free(app->clients_list);
}
