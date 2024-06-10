/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI broadcast command
*/

#include "app/app.h"
#include "server/client.h"
#include "ai/cmd/command_ai.h"

static void send_text(ia_t *ai_sender, ia_t *ai, char *text)
{
    char *reply = NULL;

    if (ai_sender->fd != ai->fd) {
        reply = format_string("message K, %s\n", text);
        add_message(ai->list_messages, reply);
    }
}

static void browse_ia(app_t *app, ia_t *ai, char *text)
{
    list_node_t *temp = app->teams_list->first;
    team_t *team = NULL;
    list_node_t *ia_temp = NULL;

    while (temp) {
        team = temp->data.team;
        ia_temp = team->list_ai->first;
        while (ia_temp) {
            send_text(ai, ia_temp->data.ai, text);
            ia_temp = ia_temp->next;
        }
        temp = temp->next;
    }
}

bool broadcast_command(app_t *app, ia_t *ai, char *line)
{
    char *reply = NULL;

    if (strncmp("Broadcast", line, 9) == 0) {
        reply = format_string("ok\n");
        browse_ia(app, ai, line + 10);
        add_message(ai->list_messages, reply);
        set_time_stuck(ai, 7 / app->game->freq);
        return true;
    }
    return false;
}
