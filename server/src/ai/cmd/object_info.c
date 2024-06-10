/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI command object info
*/

#include "ai/cmd/look.h"
#include "server/client.h"
#include "ai/cmd/command_ai.h"

static void inventory_cmd(app_t *app, ia_t *ai)
{
    char *reply = format_string(
        "[%s %d, %s %d, %s %d, %s %d, %s %d, %s %d, %s %d]\n",
        "food",
        ai->inventory->food,
        "linemate",
        ai->inventory->linemate,
        "deraumere",
        ai->inventory->deraumere,
        "sibur",
        ai->inventory->sibur,
        "mendiane",
        ai->inventory->mendiane,
        "phiras",
        ai->inventory->phiras,
        "thystame",
        ai->inventory->thystame
    );
    add_message(ai->list_messages, reply);
}

bool object_info_command(app_t *app, ia_t *ai, char *line)
{
    if (strcmp("Look", line) == 0) {
        look_cmd(app, ai);
        set_time_stuck(ai, 7 / app->game->freq);
        return true;
    }
    if (strcmp("Inventory", line) == 0) {
        inventory_cmd(app, ai);
        set_time_stuck(ai, 1 / app->game->freq);
        return true;
    }
    return false;
}
