/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** run
*/

#include "app/app.h"
#include "server/client.h"

static int server_reset_fd(app_t *app)
{
    list_node_t *temp = app->clients_list->first;
    client_t *client = NULL;

    FD_ZERO(&app->server->read_fds);
    FD_ZERO(&app->server->write_fds);
    FD_SET(app->server->fd, &app->server->read_fds);
    if (app->gui->connected)
        FD_SET(app->gui->fd, &app->server->read_fds);
    while (temp) {
        client = temp->data.client;
        FD_SET(client->fd, &app->server->read_fds);
        FD_SET(client->fd, &app->server->write_fds);
        temp = temp->next;
    }
    return 0;
}

static int handle_client_read(app_t *app, int fd)
{
    if (FD_ISSET(fd, &app->server->read_fds)) {
        if (fd == app->server->fd) {
            server_connection_handler(app, fd);
        } else {
            server_data_handler(app, fd);
        }
    }
    return 0;
}

static int handle_client_write(app_t *app, int fd)
{
    (void) app;
    (void) fd;
    return 0;
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
    }
    return true;
}
