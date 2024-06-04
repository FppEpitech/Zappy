/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** ia
*/

#include "app/app.h"
#include "server/client.h"

ia_t *create_ia(int fd)
{
    ia_t *new_ia = malloc(sizeof(ia_t));

    if (new_ia == NULL)
        return NULL;
    new_ia->fd = fd;
    new_ia->level = 0;
    return new_ia;
}

bool add_ia(app_t *app, size_t fd, char *line)
{
    list_node_t *temp = app->teams_list->first;
    team_t *team = NULL;
    node_data_t data;

    while (temp) {
        team = temp->data.team;
        if (strcmp(line, team->name) == 0) {
            data.ia = create_ia(fd);
            list_add_back(team->list_ai, data);
            list_delete(app->clients_list, find_client(app->clients_list, fd));
            return true;
        }
        temp = temp->next;
    }
    return true;
}
