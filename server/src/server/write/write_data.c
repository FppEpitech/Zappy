/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Write data
*/

#include <string.h>

#include "app/app.h"
#include "list/list.h"

void add_message(list_t *list, char *message)
{
    node_data_t message_team;

    message_team.message = message;
    list_add_back(list, message_team);
}

bool write_message(list_t *list_messages, size_t fd)
{
    list_node_t *tmp = NULL;
    ssize_t bytes_writted = 0;

    if (list_messages->len == 0)
        return true;
    tmp = list_messages->first;
    bytes_writted = write(fd, tmp->data.message, strlen(tmp->data.message));
    if (bytes_writted == -1)
        return false;
    free(tmp->data.message);
    list_remove_front(list_messages);
    return true;
}
