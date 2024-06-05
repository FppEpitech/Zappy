/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** ia
*/

#include "server/client.h"

gui_t *create_gui(int fd)
{
    gui_t *new_gui = malloc(sizeof(gui_t));

    if (new_gui == NULL)
        return NULL;
    new_gui->fd = fd;
    new_gui->list_messages = list_new();
    return new_gui;
}

bool add_gui(app_t *app, size_t fd)
{
    node_data_t data;

    data.gui = create_gui(fd);
    list_add_back(app->gui_list, data);
    list_delete(app->clients_list, find_client(app->clients_list, fd));
    return true;
}

gui_t *find_gui(app_t *app, size_t fd)
{
    list_node_t *temp = app->gui_list->first;

    while (temp) {
        if (temp->data.gui->fd == fd) {
            return temp->data.gui;
        }
        temp = temp->next;
    }
    return NULL;
}
