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
    size_t id = 0;

    if (app->eggs_list->last != NULL)
        id = app->eggs_list->last->data.egg->id + 1;
    return id;
}

void add_egg(list_t *eggs, int id_player_laid, app_t *app)
{
    node_data_t data;
    size_t id = get_last_id(app);

    data.egg = malloc(sizeof(egg_t));
    if (data.egg == NULL)
        return;
    data.egg->pos = create_vector2i(rand() % app->game->height,
    rand() % app->game->width);
    data.egg->id = id;
    data.egg->is_laid = false;
    data.egg->id_player_laid = id_player_laid;
    list_add_back(eggs, data);
    list_add_back(app->eggs_list, data);
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
    new_team->name = name;
    new_team->max_place = max_place;
    new_team->list_ai = list_new();
    new_team->eggs_list = list_new();
    for (size_t index_egg = 0; index_egg < new_team->max_place; index_egg++) {
        add_egg(new_team->eggs_list, -1, app);
    }
    if (new_team->list_ai == NULL)
        return NULL;
    return new_team;
}

void add_team(app_t *app, char *team_name, size_t max_place)
{
    node_data_t data;

    data.team = create_team(app, team_name, max_place);
    list_add_back(app->teams_list, data);
}

void display_egg_position(app_t *app)
{
    list_node_t *temp = app->teams_list->first;
    team_t *team = NULL;
    list_node_t *egg_temp = NULL;

    printf("\nEgg Position:\n");
    while (temp) {
        team = temp->data.team;
        printf("\tTeam name: [%s]\n", team->name);
        egg_temp = team->eggs_list->first;
        while (egg_temp) {
            printf("\t\tEgg in: [%d] | [%d]\n",
            egg_temp->data.egg->pos->x, egg_temp->data.egg->pos->y);
            egg_temp = egg_temp->next;
        }
        printf("\n");
        temp = temp->next;
    }
}
