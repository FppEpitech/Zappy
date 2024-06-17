/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI eject egg
*/

#include "ai/cmd/look.h"
#include "server/client.h"
#include "ai/cmd/command_ai.h"
#include "gui/communication.h"

static void check_position_egg(team_t *team,
    list_node_t *egg_temp, vector2i_t *ai_position, app_t *app)
{
    if (egg_temp->data.coord->x == ai_position->x &&
    egg_temp->data.coord->y == ai_position->y) {
        list_delete(team->eggs_list, egg_temp);
        edi_command(app, egg_temp->data.egg->id);
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
        egg_temp = team->eggs_list->first;
        while (egg_temp != NULL) {
            next_egg = egg_temp->next;
            check_position_egg(team, egg_temp, ai->position, app);
            egg_temp = next_egg;
        }
        temp = temp->next;
    }
}
