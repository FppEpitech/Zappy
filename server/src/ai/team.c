/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** team
*/

#include "app/app.h"
#include "gui/communication.h"

static size_t get_last_id(app_t *app)
{
    list_node_t *temp = app->teams_list->first;
    team_t *team = NULL;
    size_t id = 0;

    while (temp) {
        team = temp->data.team;
        if (team->eggs_list->last == NULL) {
            temp = temp->next;
            continue;
        }
        if (team->eggs_list->last->data.egg->id > id)
            id = team->eggs_list->last->data.egg->id;
        temp = temp->next;
    }
    return id + 1;
}

void add_egg(list_t *eggs, int id_player_laid, app_t *app)
{
    node_data_t data;
    size_t id = get_last_id(app);

    data.egg = malloc(sizeof(egg_t));
    if (data.egg == NULL)
        return;
    data.egg->pos = create_vector2i(rand() % app->game->width,
    rand() % app->game->height);
    data.egg->id = id;
    data.egg->is_laid = false;
    data.egg->id_player_laid = id_player_laid;
    list_add_back(eggs, data);
}

void add_egg_on_player(list_t *eggs, int id_player_laid,
    app_t *app, ia_t *ai)
{
    node_data_t data;
    size_t id = get_last_id(app);

    data.egg = malloc(sizeof(egg_t));
    if (data.egg == NULL)
        return;
    data.egg->pos = create_vector2i(ai->position->x,
    ai->position->y);
    data.egg->id = id;
    data.egg->is_laid = true;
    data.egg->id_player_laid = id_player_laid;
    list_add_back(eggs, data);
}

static void add_egg_with_id(list_t *eggs, int id_player_laid, app_t *app,
    size_t id)
{
    node_data_t data;

    data.egg = malloc(sizeof(egg_t));
    if (data.egg == NULL)
        return;
    data.egg->pos = create_vector2i(rand() % app->game->width,
    rand() % app->game->height);
    data.egg->is_laid = false;
    data.egg->id = id;
    data.egg->id_player_laid = id_player_laid;
    list_add_back(eggs, data);
}

static void add_eggs(team_t *team, app_t *app)
{
    size_t id = get_last_id(app);

    for (size_t index_egg = 0; index_egg < team->max_place; index_egg++) {
        add_egg_with_id(team->eggs_list, -1, app, id + index_egg);
    }
}

static bool check_team(team_t *team, size_t fd)
{
    list_node_t *ia_temp = team->list_ai->first;

    while (ia_temp) {
        if (ia_temp->data.ai->fd == fd)
            return true;
        ia_temp = ia_temp->next;
    }
    return false;
}

team_t *find_team(app_t *app, size_t fd)
{
    list_node_t *temp = app->teams_list->first;
    team_t *team = NULL;

    while (temp) {
        team = temp->data.team;
        if (check_team(team, fd))
            return team;
        temp = temp->next;
    }
    return NULL;
}

team_t *create_team(app_t *app, char *name, size_t max_place)
{
    team_t *new_team = malloc(sizeof(team_t));

    if (new_team == NULL)
        return NULL;
    new_team->name = strdup(name);
    if (!new_team->name)
        return NULL;
    new_team->max_place = max_place;
    new_team->list_ai = list_new();
    new_team->eggs_list = list_new();
    add_eggs(new_team, app);
    if (new_team->list_ai == NULL)
        return NULL;
    return new_team;
}

void add_team(app_t *app, char *team_name, size_t max_place)
{
    node_data_t data;

    data.team = create_team(app, team_name, max_place);
    if (!data.team)
        return;
    list_add_back(app->teams_list, data);
}
