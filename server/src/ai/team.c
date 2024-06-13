/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** team
*/

#include "app/app.h"

void add_egg(list_t *eggs, int random_x, int random_y)
{
    node_data_t data;

    data.coord = create_vector2i(random_x, random_y);
    list_add_back(eggs, data);
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
    new_team->egg_position = list_new();
    for (size_t index_egg = 0; index_egg < new_team->max_place; index_egg++) {
        add_egg(new_team->egg_position, rand() % app->game->width,
        rand() % app->game->height);
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
        egg_temp = team->egg_position->first;
        while (egg_temp) {
            printf("\t\tEgg in: [%d] | [%d]\n",
            egg_temp->data.coord->x, egg_temp->data.coord->y);
            egg_temp = egg_temp->next;
        }
        printf("\n");
        temp = temp->next;
    }
}
