/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** team
*/

#include "app/app.h"

static void add_egg(list_t *eggs, int random_x, int random_y)
{
    node_data_t data;

    data.coord = create_vector2i(random_x, random_y);
    list_add_back(eggs, data);
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
        add_egg(new_team->egg_position, rand() % app->game->height,
        rand() % app->game->width);
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
