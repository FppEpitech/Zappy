/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** ai
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

void add_gui(app_t *app, size_t fd, char *line)
{
    node_data_t data;
    list_node_t *client_node = find_client(app->clients_list, fd);

    data.gui = create_gui(fd);
    list_add_back(app->gui_list, data);
    free(client_node->data.client);
    list_delete(app->clients_list, client_node);
    free(line);
}

gui_t *find_gui(app_t *app, size_t fd)
{
    list_node_t *temp = app->gui_list->first;

    while (temp) {
        if (temp->data.gui->fd == fd)
            return temp->data.gui;
        temp = temp->next;
    }
    return NULL;
}

void destroy_gui(list_t *gui_list)
{
    list_node_t *temp = gui_list->first;

    while (temp) {
        close(temp->data.gui->fd);
        destroy_message_list(temp->data.gui->list_messages);
        free(temp->data.gui);
        temp = temp->next;
    }
    list_free(gui_list);
}
