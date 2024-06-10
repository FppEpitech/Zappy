/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI command handler
*/

#include "app/app.h"
#include "server/client.h"
#include "ai/cmd/command_ai.h"

void add_command_to_list(ia_t *ai, char *line)
{
    node_data_t node;

    node.command = line;
    list_add_back(ai->list_command, node);
}

void command_ai_handler(app_t *app, ia_t *ai, char *line)
{
    char *bad_command = NULL;

    bad_command = format_string("ko\n");
    if (move_command(app, ai, line))
        return;
    if (object_info_command(app, ai, line))
        return;
    if (other_command(app, ai, line))
        return;
    if (broadcast_command(app, ai, line))
        return;
    if (incantation_command(app, ai, line))
        return;
    add_message(ai->list_messages, bad_command);
}

static void check_ai_stuck(ia_t *ai, app_t *app)
{
    char *command = NULL;

    if (ai->list_command->first != NULL)
        command = ai->list_command->first->data.command;
    else
        return;
    if (ai->time->stuck == false) {
        command_ai_handler(app, ai, command);
        list_remove_front(ai->list_command);
    }
}

void treat_command(app_t *app)
{
    list_node_t *temp_team = app->teams_list->first;
    team_t *team = NULL;
    list_node_t *ia_temp = NULL;

    while (temp_team) {
        team = temp_team->data.team;
        ia_temp = team->list_ai->first;
        while (ia_temp) {
            check_ai_stuck(ia_temp->data.ai, app);
            ia_temp = ia_temp->next;
        }
        temp_team = temp_team->next;
    }
}
