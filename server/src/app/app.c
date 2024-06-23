/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** app
*/

#include "server/client.h"
#include "gui/communication.h"

static void create_teams(parsing_t *parsing, app_t *app)
{
    for (size_t index = 0; parsing->names[index] != NULL; index++)
        add_team(app, parsing->names[index], parsing->clientsNb);
}

static void destroy_error(parsing_t *parsing, app_t *new_app)
{
    destroy_game(new_app->game);
    destroy_parsing(parsing);
    free(new_app);
}

app_t *create_app(parsing_t *parsing)
{
    app_t *new_app = malloc(sizeof(app_t));

    if (new_app == NULL)
        return NULL;
    new_app->server = create_server(parsing->port);
    new_app->game = create_game(parsing->height,
    parsing->width, parsing->freq);
    if (new_app->server == NULL || new_app->game == NULL) {
        destroy_error(parsing, new_app);
        return NULL;
    }
    new_app->gui_list = list_new();
    new_app->clients_list = list_new();
    new_app->teams_list = list_new();
    create_teams(parsing, new_app);
    if (new_app->gui_list == NULL || new_app->clients_list == NULL
    || new_app->teams_list == NULL)
        return NULL;
    return new_app;
}

void destroy_message_list(list_t *message_list)
{
    list_node_t *temp = message_list->first;

    while (temp) {
        free(temp->data.message);
        list_remove_front(message_list);
        temp = message_list->first;
    }
}

void destroy_command_list(list_t *command_list)
{
    list_node_t *temp = command_list->first;

    while (temp) {
        free(temp->data.command);
        temp = temp->next;
    }
}

void destroy_app(app_t *app)
{
    destroy_server(app->server);
    destroy_gui(app, app->gui_list);
    destroy_client(app->clients_list);
    destroy_team(app->teams_list);
    destroy_game(app->game);
    free(app);
}
