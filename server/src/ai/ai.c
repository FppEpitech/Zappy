/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI
*/

#include "app/app.h"
#include "server/client.h"

static orientation_t choose_direction(void)
{
    int random = 0;

    random = rand() % 4;
    if (random == 0)
        return NORTH;
    if (random == 1)
        return SOUTH;
    if (random == 2)
        return EAST;
    if (random == 3)
        return WEST;
    return NORTH;
}

static void add_message_to_ia(app_t *app, team_t *team, ia_t *new_ia)
{
    char *nb_place = NULL;
    char *map_size = NULL;

    nb_place = format_string("%ld\n", team->max_place -
    (team->list_ai->len + 1));
    map_size = format_string("%d %d\n", app->game->width, app->game->height);
    add_message(new_ia->list_messages, nb_place);
    add_message(new_ia->list_messages, map_size);
}

static inventory_t *create_inventory(void)
{
    inventory_t *new_inventory = malloc(sizeof(inventory_t));

    if (new_inventory == NULL)
        return NULL;
    new_inventory->linemate = 0;
    new_inventory->deraumere = 0;
    new_inventory->sibur = 0;
    new_inventory->mendiane = 0;
    new_inventory->phiras = 0;
    new_inventory->thystame = 0;
    return new_inventory;
}

ia_t *create_ia(app_t *app, int fd, team_t *team)
{
    ia_t *new_ia = malloc(sizeof(ia_t));
    int x = team->egg_position->first->data.coord->x;
    int y = team->egg_position->first->data.coord->y;

    if (new_ia == NULL)
        return NULL;
    new_ia->fd = fd;
    new_ia->level = 1;
    new_ia->direction = choose_direction();
    list_remove_front(team->egg_position);
    new_ia->position = create_vector2i(x, y);
    new_ia->list_messages = list_new();
    new_ia->inventory = create_inventory();
    add_message_to_ia(app, team, new_ia);
    return new_ia;
}

void add_ia(app_t *app, size_t fd, char *line)
{
    list_node_t *temp = app->teams_list->first;
    team_t *team = NULL;
    node_data_t data;

    while (temp) {
        team = temp->data.team;
        if (strcmp(line, team->name) == 0 &&
        (team->max_place - team->list_ai->len) > 0) {
            data.ai = create_ia(app, fd, team);
            list_add_back(team->list_ai, data);
            list_delete(app->clients_list, find_client(app->clients_list, fd));
            return;
        }
        temp = temp->next;
    }
}

static ia_t *check_ia(team_t *team, size_t fd)
{
    list_node_t *ia_temp = team->list_ai->first;

    while (ia_temp) {
        if (ia_temp->data.ai->fd == fd)
            return ia_temp->data.ai;
        ia_temp = ia_temp->next;
    }
    return NULL;
}

ia_t *find_ia(app_t *app, size_t fd)
{
    list_node_t *temp = app->teams_list->first;
    team_t *team = NULL;
    ia_t *ai = NULL;

    while (temp) {
        team = temp->data.team;
        ai = check_ia(team, fd);
        if (ai != NULL)
            return ai;
        temp = temp->next;
    }
    return NULL;
}
