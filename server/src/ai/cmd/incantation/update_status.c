/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI incantation command
*/

#include "app/app.h"
#include "server/client.h"
#include "ai/cmd/command_ai.h"

static void send_message_begin(ia_t *ai)
{
    char *success = NULL;

    success = format_string("Elevation underway\n");
    add_message(ai->list_messages, success);
}

static void update_other_ai(ia_t *ai, ia_t *ai_check,
    app_t *app, int update_status)
{
    if (ai_check->fd != ai->fd && update_status == BEGIN_INCANTATION
    && ai_check->position->x == ai->position->x
    && ai_check->position->y == ai->position->y
    && ai_check->level == ai->level) {
        ai_check->incantation->status_incantation = true;
        ai_check->incantation->target_level = ai->level + 1;
        set_time_stuck(ai_check, 300 / app->game->freq);
        send_message_begin(ai_check);
    }
    if (ai_check->fd != ai->fd && update_status == END_INCANTATION
    && ai_check->position->x == ai->position->x
    && ai_check->position->y == ai->position->y
    && ai_check->level == ai->level
    && ai_check->incantation->status_incantation == true
    && ai_check->incantation->target_level == ai->incantation->target_level) {
        ai_check->incantation->status_incantation = false;
        ai_check->incantation->target_level = 0;
        ai_check->time->stuck = false;
        ai_check->time->total_stuck = 0.0;
    }
}

static void update_ai(ia_t *ai, app_t *app, int update_status)
{
    if (update_status == BEGIN_INCANTATION) {
        ai->incantation->status_incantation = true;
        ai->incantation->target_level = ai->level + 1;
        set_time_stuck(ai, 300 / app->game->freq);
        send_message_begin(ai);
    }
    if (update_status == END_INCANTATION) {
        ai->incantation->status_incantation = false;
        ai->incantation->target_level = 0;
    }
}

void update_status(app_t *app, ia_t *ai, int update_status)
{
    list_node_t *temp_team = app->teams_list->first;
    list_node_t *ia_temp;
    team_t *team = NULL;

    while (temp_team) {
        team = temp_team->data.team;
        ia_temp = team->list_ai->first;
        while (ia_temp) {
            update_other_ai(ai, ia_temp->data.ai, app, update_status);
            ia_temp = ia_temp->next;
        }
        temp_team = temp_team->next;
    }
    update_ai(ai, app, update_status);
}
