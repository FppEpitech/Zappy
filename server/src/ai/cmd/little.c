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
    char *reply = format_string("%d\n",
    (team->max_place - team->list_ai->len));

    add_message(ai->list_messages, reply);
}

static void fork_cmd(app_t *app, ia_t *ai)
{
    team_t *team = find_team(app, ai->fd);
    char *reply = format_string("ok\n");

    team->max_place += 1;
    add_egg(team->egg_position, rand() % app->game->height,
    rand() % app->game->width);
    add_message(ai->list_messages, reply);
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
    return false;
}
