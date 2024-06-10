/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** run
*/

#include "server/client.h"
#include "ai/cmd/command_ai.h"

static void reset_ai(app_t *app)
{
    list_node_t *temp = app->teams_list->first;
    list_node_t *ia_temp = NULL;
    team_t *team = NULL;

    while (temp) {
        team = temp->data.team;
        ia_temp = team->list_ai->first;
        while (ia_temp) {
            FD_SET(ia_temp->data.ai->fd, &app->server->read_fds);
            FD_SET(ia_temp->data.ai->fd, &app->server->write_fds);
            ia_temp = ia_temp->next;
        }
        temp = temp->next;
    }
}

static void reset_gui(app_t *app)
{
    list_node_t *temp_gui = app->gui_list->first;
    gui_t *gui = NULL;

    while (temp_gui) {
        gui = temp_gui->data.gui;
        FD_SET(gui->fd, &app->server->read_fds);
        FD_SET(gui->fd, &app->server->write_fds);
        temp_gui = temp_gui->next;
    }
}

void server_reset_fd(app_t *app)
{
    list_node_t *temp = app->clients_list->first;
    client_t *client = NULL;

    FD_ZERO(&app->server->read_fds);
    FD_ZERO(&app->server->write_fds);
    FD_SET(app->server->fd, &app->server->read_fds);
    while (temp) {
        client = temp->data.client;
        FD_SET(client->fd, &app->server->read_fds);
        FD_SET(client->fd, &app->server->write_fds);
        temp = temp->next;
    }
    reset_gui(app);
    reset_ai(app);
}

void handle_client_read(app_t *app, int fd)
{
    if (FD_ISSET(fd, &app->server->read_fds)) {
        if (fd == app->server->fd)
            server_connection_handler(app, fd);
        else
            server_data_handler(app, fd);
    }
}

void handle_client_write(app_t *app, int fd)
{
    gui_t *gui = find_gui(app, fd);
    ia_t *ai = find_ia(app, fd);

    if (gui != NULL)
        write_message(gui->list_messages, gui->fd);
    if (ai != NULL)
        write_message(ai->list_messages, ai->fd);
}

bool server_run(app_t *app)
{
    while (true) {
        server_reset_fd(app);
        if (select(FD_SETSIZE, &app->server->read_fds,
        &app->server->write_fds, NULL, NULL) < 0)
            return false;
        for (int fd = 0; fd < FD_SETSIZE; fd++) {
            handle_client_read(app, fd);
            handle_client_write(app, fd);
        }
        treat_command(app);
        treat_stuck(app);
        check_die(app);
    }
    return true;
}
