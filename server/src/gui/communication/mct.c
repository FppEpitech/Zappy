/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** mct
*/

#include "types.h"
#include "app/app.h"
#include "gui/gui.h"
#include "gui/communication.h"

#include <string.h>

static char *get_string(app_t *app, vector2i_t pos)
{
    char *response = format_string("bct %d %d %d %d %d %d %d %d %d\n",
        pos.x, pos.y,
        app->game->map[pos.y][pos.x].food,
        app->game->map[pos.y][pos.x].linemate,
        app->game->map[pos.y][pos.x].deraumere,
        app->game->map[pos.y][pos.x].sibur,
        app->game->map[pos.y][pos.x].mendiane,
        app->game->map[pos.y][pos.x].phiras,
        app->game->map[pos.y][pos.x].thystame);

    return response;
}

void mct_response(gui_t *gui, app_t *app, char *line)
{
    vector2i_t pos = {0, 0};
    char *response = NULL;
    char *final_response = "";

    if (strlen(line) != LEN_COMMAND) {
        suc_command(gui);
        return;
    }
    while ((size_t)pos.y < app->game->height) {
        pos.x = 0;
        while ((size_t)pos.x < app->game->width) {
            response = get_string(app, pos);
            final_response = format_string("%s%s", final_response, response);
            pos.x++;
        }
        pos.y++;
    }
    add_message(gui->list_messages, final_response);
}
