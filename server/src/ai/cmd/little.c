/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI little
*/

#include "ai/cmd/look.h"
#include "server/client.h"
#include "ai/cmd/command_ai.h"

static void connect_nbr_cmd(app_t *app, ia_t *ai)
{
    team_t *team = find_team(app, ai->fd);
    char *reply = format_string("%d\n", team->egg_position->len);

    add_message(ai->list_messages, reply);
}

static void fork_cmd(app_t *app, ia_t *ai)
{
    team_t *team = find_team(app, ai->fd);
    char *reply = format_string("ok\n");

    add_egg(team->egg_position, rand() % app->game->height,
    rand() % app->game->width);
    add_message(ai->list_messages, reply);
}

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

bool little_command(app_t *app, ia_t *ai, char *line)
{
    if (strcmp("Connect_nbr", line) == 0) {
        connect_nbr_cmd(app, ai);
        return true;
    }
    if (strcmp("Fork", line) == 0) {
        fork_cmd(app, ai);
        return true;
    }
    if (strcmp("Eject", line) == 0) {
        eject_cmd(app, ai);
        return true;
    }
    return false;
}
