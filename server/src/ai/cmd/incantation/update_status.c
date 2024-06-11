/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI incantation command
*/

#include "app/app.h"
#include "server/client.h"
#include "ai/cmd/command_ai.h"

static void update_ai(ia_t *ai, ia_t *ai_check)
{
    if (ai_check->position->x == ai->position->x
    && ai_check->position->y == ai->position->y
    && ai_check->level == ai->level) {
        ai_check->incantation->status_incantation = true;
        ai_check->incantation->target_level = ai->level + 1;
    }
}

void update_status(app_t *app, ia_t *ai)
{
    list_node_t *temp_team = app->teams_list->first;
    list_node_t *ia_temp;
    team_t *team = NULL;

    while (temp_team) {
        team = temp_team->data.team;
        ia_temp = team->list_ai->first;
        while (ia_temp) {
            update_ai(ai, ia_temp->data.ai);
            ia_temp = ia_temp->next;
        }
        temp_team = temp_team->next;
    }
    ai->incantation->status_incantation = true;
    ai->incantation->target_level = ai->level + 1;
}
