/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Read data
*/

#include <string.h>

#include "app/app.h"
#include "server/client.h"

static bool server_quit_gui(list_t *gui_list, size_t fd)
{
    list_node_t *temp = gui_list->first;
    gui_t *gui = NULL;

    while (temp) {
        gui = temp->data.gui;
        if (fd == gui->fd) {
            list_delete(gui_list, temp);
            return true;
        }
        temp = temp->next;
    }
    return false;
}

static bool server_quit_client(list_t *clients_list, size_t fd)
{
    list_node_t *temp = clients_list->first;
    client_t *client = NULL;

    while (temp) {
        client = temp->data.client;
        if (fd == client->fd) {
            list_delete(clients_list, temp);
            return true;
        }
        temp = temp->next;
    }
    return false;
}

static void check_ia(app_t *app, team_t *team, list_node_t *ia_temp)
{
    list_delete(team->list_ai, ia_temp);
    if (team->max_place > team->egg_position->len) {
        add_egg(team->egg_position, rand() % app->game->height,
        rand() % app->game->width);
    }
}

static bool server_quit_ia(app_t *app, size_t fd)
{
    team_t *team = find_team(app, fd);
    list_node_t *ia_temp = NULL;

    ia_temp = team->list_ai->first;
    while (ia_temp) {
        if (ia_temp->data.ai->fd == fd) {
            check_ia(app, team, ia_temp);
            return true;
        }
        ia_temp = ia_temp->next;
    }
    return false;
}

void server_quit_handler(app_t *app, size_t fd)
{
    if (server_quit_gui(app->gui_list, fd))
        return;
    if (server_quit_client(app->clients_list, fd))
        return;
    if (server_quit_ia(app, fd))
        return;
}
