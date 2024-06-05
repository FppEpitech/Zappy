/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** ia
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>

#include "app/app.h"
#include "server/client.h"

ia_t *create_ia(app_t *app, int fd, team_t *team)
{
    ia_t *new_ia = malloc(sizeof(ia_t));
    char *nb_place = NULL;
    char *map_size = NULL;

    if (new_ia == NULL)
        return NULL;
    new_ia->fd = fd;
    new_ia->level = 0;
    new_ia->list_messages = list_new();
    asprintf(&nb_place, "%ld\n", team->max_place - (team->list_ai->len + 1));
    asprintf(&map_size, "%d %d\n", app->game->width, app->game->height);
    add_message(new_ia->list_messages, nb_place);
    add_message(new_ia->list_messages, map_size);
    return new_ia;
}

bool add_ia(app_t *app, size_t fd, char *line)
{
    list_node_t *temp = app->teams_list->first;
    team_t *team = NULL;
    node_data_t data;

    while (temp) {
        team = temp->data.team;
        if (strcmp(line, team->name) == 0 &&
        (team->max_place - team->list_ai->len) > 0) {
            data.ia = create_ia(app, fd, team);
            list_add_back(team->list_ai, data);
            list_delete(app->clients_list, find_client(app->clients_list, fd));
            return true;
        }
        temp = temp->next;
    }
    return true;
}

ia_t *check_ia(team_t *team, size_t fd)
{
    list_node_t *ia_temp = team->list_ai->first;

    while (ia_temp) {
        if (ia_temp->data.ia->fd == fd)
            return ia_temp->data.ia;
        ia_temp = ia_temp->next;
    }
    return NULL;
}

ia_t *find_ia(app_t *app, size_t fd)
{
    list_node_t *temp = app->teams_list->first;
    team_t *team = NULL;
    ia_t *ia = NULL;

    while (temp) {
        team = temp->data.team;
        ia = check_ia(team, fd);
        if (ia != NULL) {
            return ia;
        }
        temp = temp->next;
    }
    return NULL;
}
