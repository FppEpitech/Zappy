/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** run
*/

#include "rules.h"
#include "utils.h"
#include "server/client.h"
#include "ai/cmd/command_ai.h"

#include <time.h>

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
            write_message(app, gui->list_messages, gui->fd);
        if (ai != NULL)
            write_message(app, ai->list_messages, ai->fd);
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

static int game_run(int result_select, app_t *app, bool logic_loop)
{
    if (result_select < 0)
        return ERROR;
    if (!logic_loop) {
        for (int fd = 0; fd < FD_SETSIZE; fd++) {
            handle_client_read(app, fd);
            handle_client_write(app, fd);
        }
    } else {
        spawn_ressources(app);
        treat_ai_command(app);
        treat_gui_command(app);
        treat_stuck(app);
        check_die(app);
        if (app->game->status_game == END_GAME)
            return END_GAME;
        check_win(app);
    }
    return GAME_CONTINUE;
}

static struct timeval get_timeout(app_t *app, struct timespec *start)
{
    struct timeval timeout_final;
    struct timespec end = {0};
    long time_elapsed = 0.0;
    double timeout = 1.0 / app->game->freq;

    timeout_final.tv_sec = 0;
    timeout_final.tv_usec = timeout * MICROSECOND_TO_SECOND;
    clock_gettime(CLOCK_MONOTONIC, &end);
    time_elapsed = (end.tv_sec - start->tv_sec) * MILLISECOND_TO_SECOND +
        (end.tv_nsec - start->tv_nsec) / MICROSECOND_TO_SECOND;
    if (time_elapsed < timeout * MILLISECOND_TO_SECOND) {
        timeout_final.tv_usec = (timeout * MILLISECOND_TO_SECOND -
            time_elapsed) * MILLISECOND_TO_SECOND;
    } else {
        clock_gettime(CLOCK_MONOTONIC, start);
    }
    return timeout_final;
}

bool server_run(app_t *app)
{
    struct timeval timeout;
    int result_game = 0;
    struct timespec start = {0};
    bool logic_loop = false;

    signal(SIGINT, handle_control_c);
    clock_gettime(CLOCK_MONOTONIC, &start);
    while (server_status(true)) {
        server_reset_fd(app);
        timeout = get_timeout(app, &start);
        if (timeout.tv_usec == (1.0 / app->game->freq) * MICROSECOND_TO_SECOND)
            logic_loop = true;
        result_game = game_run(select(FD_SETSIZE, &app->server->read_fds,
        &app->server->write_fds, NULL, &timeout), app, logic_loop);
        if (result_game != GAME_CONTINUE)
            return result_game == ERROR ? false : true;
        logic_loop = false;
    }
    return true;
}
