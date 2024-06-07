/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** team
*/

#include "ai/team.h"

static void distribute_egg(team_t *new_team)
{
    (void) new_team;
    return;
}

team_t *create_team(char *name, size_t max_place)
{
    team_t *new_team = malloc(sizeof(team_t));

    if (new_team == NULL)
        return NULL;
    new_team->name = name;
    new_team->max_place = max_place;
    new_team->list_ai = list_new();
    new_team->egg_position = list_new();
    distribute_egg(new_team);
    if (new_team->list_ai == NULL)
        return NULL;
    return new_team;
}

void add_team(list_t *teams, char *team_name, size_t max_place)
{
    node_data_t data;

    data.team = create_team(team_name, max_place);
    list_add_back(teams, data);
}
