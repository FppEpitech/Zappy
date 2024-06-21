/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** run
*/

#include "server/client.h"
#include "ai/cmd/command_ai.h"

static void reset_ai(app_t *app, list_node_t *node_ai)
{
    while (node_ai) {
        FD_SET(node_ai->data.ai->fd, &app->server->read_fds);
        if (node_ai->data.ai->list_messages->first != NULL)
            FD_SET(node_ai->data.ai->fd, &app->server->write_fds);
        node_ai = node_ai->next;
    }
}

static void reset_ais(app_t *app)
{
    list_node_t *temp = app->teams_list->first;
    team_t *team = NULL;

    while (temp) {
        team = temp->data.team;
        reset_ai(app, team->list_ai->first);
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
        if (temp_gui->data.gui->list_messages->first != NULL)
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
    reset_ais(app);
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
    gui_t *gui = NULL;
    ia_t *ai = NULL;

    if (FD_ISSET(fd, &app->server->write_fds)) {
        gui = find_gui(app, fd);
        ai = find_ia(app, fd);
        if (gui != NULL)
            write_message(gui->list_messages, gui->fd);
        if (ai != NULL)
            write_message(ai->list_messages, ai->fd);
    }
}

static bool server_status(bool status)
{
    static bool server_status = true;

    if (status == false)
        server_status = status;
    return server_status;
}

static void handle_control_c(int sig)
{
    if (sig == SIGINT)
        server_status(false);
}

static int game_run(int result_select, app_t *app)
{
    if (result_select < 0)
        return ERROR;
    if (result_select != 0) {
        for (int fd = 0; fd < FD_SETSIZE; fd++) {
            handle_client_read(app, fd);
            handle_client_write(app, fd);
        }
    }
    spawn_ressources(app);
    treat_command(app);
    treat_stuck(app);
    check_die(app);
    if (check_win(app))
        return END_GAME;
    return GAME_CONTINUE;
}

bool server_run(app_t *app)
{
    struct timeval timeout;
    int result_select = 0;
    int result_game = 0;

    timeout.tv_sec = SELECT_TIMEOUT_SECONDS;
    timeout.tv_usec = 0;
    signal(SIGINT, handle_control_c);
    while (server_status(true)) {
        server_reset_fd(app);
        result_select = select(FD_SETSIZE, &app->server->read_fds,
        &app->server->write_fds, NULL, &timeout);
        result_game = game_run(result_select, app);
        if (result_game == -1)
            return false;
        if (result_game == 1)
            return true;
    }
    return true;
}
