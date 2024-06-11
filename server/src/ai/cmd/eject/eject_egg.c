/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI eject egg
*/

#include "ai/cmd/look.h"
#include "server/client.h"
#include "ai/cmd/command_ai.h"

static void check_position_egg(team_t *team,
    list_node_t *egg_temp, vector2i_t *ai_position)
{
    if (egg_temp->data.coord->x == ai_position->x &&
    egg_temp->data.coord->y == ai_position->y) {
        list_delete(team->egg_position, egg_temp);
    }
}

void eject_egg(app_t *app, ia_t *ai)
{
    list_node_t *temp = app->teams_list->first;
    team_t *team = NULL;
    list_node_t *egg_temp = NULL;
    list_node_t *next_egg = NULL;

    while (temp != NULL) {
        team = temp->data.team;
        egg_temp = team->egg_position->first;
        while (egg_temp != NULL) {
            next_egg = egg_temp->next;
            check_position_egg(team, egg_temp, ai->position);
            egg_temp = next_egg;
        }
        temp = temp->next;
    }
}