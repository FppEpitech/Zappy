/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI dead response
*/

#include "ai/cmd/look.h"
#include "server/client.h"
#include "ai/cmd/command_ai.h"

void dead_response(app_t *app)
{
    list_node_t *temp = app->teams_list->first;
    team_t *team = NULL;
    list_node_t *ia_temp = NULL;
    char *reply = NULL;

    while (temp) {
        team = temp->data.team;
        ia_temp = team->list_ai->first;
        while (ia_temp) {
            reply = strdup("dead\n");
            add_message(ia_temp->data.ai->list_messages, reply);
            ia_temp = ia_temp->next;
        }
        temp = temp->next;
    }
}
