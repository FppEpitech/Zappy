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

    nb_place = format_string("%ld\n", team->egg_position->len);
    map_size = format_string("%d %d\n", app->game->width, app->game->height);
    add_message(new_ia->list_messages, nb_place);
    add_message(new_ia->list_messages, map_size);
}

static inventory_t *create_inventory(void)
{
    inventory_t *new_inventory = malloc(sizeof(inventory_t));

    if (new_inventory == NULL)
        return NULL;
    new_inventory->food = 0;
    new_inventory->linemate = 0;
    new_inventory->deraumere = 0;
    new_inventory->sibur = 0;
    new_inventory->mendiane = 0;
    new_inventory->phiras = 0;
    new_inventory->thystame = 0;
    return new_inventory;
}

static incantation_info_t *create_incantation(void)
{
    incantation_info_t *new_incantation = malloc(sizeof(incantation_info_t));

    if (new_incantation == NULL)
        return NULL;
    new_incantation->status_incantation = false;
    new_incantation->target_level = 0;
    return new_incantation;
}

static time_info_t *create_time(app_t *app)
{
    time_info_t *new_time = malloc(sizeof(time_info_t));

    if (new_time == NULL)
        return NULL;
    new_time->stuck = false;
    new_time->total_stuck = 0.0;
    gettimeofday(&new_time->start_life, NULL);
    new_time->total_life = 1260.0 / app->game->freq;
    return new_time;
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
    free(team->egg_position->first->data.coord);
    list_remove_front(team->egg_position);
    new_ia->position = create_vector2i(x, y);
    new_ia->list_command = list_new();
    new_ia->list_messages = list_new();
    new_ia->inventory = create_inventory();
    new_ia->incantation = create_incantation();
    new_ia->time = create_time(app);
    add_message_to_ia(app, team, new_ia);
    return new_ia;
}

void add_ia(app_t *app, size_t fd, char *line)
{
    list_node_t *temp = app->teams_list->first;
    team_t *team = NULL;
    node_data_t data;
    list_node_t *client_node = find_client(app->clients_list, fd);

    while (temp) {
        team = temp->data.team;
        if (strcmp(line, team->name) == 0 &&
        team->egg_position->len > 0) {
            data.ai = create_ia(app, fd, team);
            list_add_back(team->list_ai, data);
            free(client_node->data.client);
            list_delete(app->clients_list, client_node);
            free(line);
            return;
        }
        temp = temp->next;
    }
    free(line);
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
