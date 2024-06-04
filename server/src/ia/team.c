/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** team
*/

#include "ia/team.h"

team_t *create_team(char *name, int max_place)
{
    team_t *new_team = malloc(sizeof(team_t));

    if (new_team == NULL)
        return NULL;
    new_team->name = name;
    new_team->max_place = max_place;
    new_team->list_ai = list_new();
    if (new_team->list_ai == NULL)
        return NULL;
    return new_team;
}
