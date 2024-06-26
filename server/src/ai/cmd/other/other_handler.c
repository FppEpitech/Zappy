/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI other cmd handler
*/

#include "ai/cmd/look.h"
#include "server/client.h"
#include "ai/cmd/command_ai.h"

static bool object_cmd_handler(app_t *app, ia_t *ai, char *line)
{
    if (strncmp("Take ", line, 5) == 0) {
        take_cmd(app, ai, line + 5);
        set_time_stuck(ai, 7 / app->game->freq);
        return true;
    }
    if (strncmp("Set ", line, 4) == 0) {
        set_cmd(app, ai, line + 4);
        set_time_stuck(ai, 7 / app->game->freq);
        return true;
    }
    return false;
}

bool other_command(app_t *app, ia_t *ai, char *line)
{
    if (strcmp("Connect_nbr", line) == 0) {
        connect_nbr_cmd(app, ai);
        return true;
    }
    if (strcmp("Fork", line) == 0) {
        fork_cmd(app, ai);
        set_time_stuck(ai, 42 / app->game->freq);
        return true;
    }
    if (strcmp("Eject", line) == 0) {
        eject_cmd(app, ai);
        set_time_stuck(ai, 7 / app->game->freq);
        return true;
    }
    if (object_cmd_handler(app, ai, line))
        return true;
    return false;
}
