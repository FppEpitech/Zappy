/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** bct
*/

#include "types.h"
#include "app/app.h"
#include "gui/gui.h"
#include "gui/communication.h"

static vector2i_t get_pos_requested(char *line)
{
    vector2i_t pos = {0, 0};

    pos.x = atoi(strtok(line, " "));
    pos.y = atoi(strtok(NULL, " \n\r"));
    return pos;
}

char *get_response(app_t *app, vector2i_t pos)
{
    char *response = NULL;

    response = format_string("bct %d %d %d %d %d %d %d %d %d\n",
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

void bct_response(gui_t *gui, app_t *app, char *line)
{
    vector2i_t pos = {0, 0};

    if (line[POS_SPACE] != ' ') {
        suc_command(gui);
        return;
    }
    line += LEN_COMMAND_AND_SPACE;
    pos = get_pos_requested(line);
    if (pos.x < 0 || (size_t)pos.x >= app->game->width ||
        pos.y < 0 || (size_t)pos.y >= app->game->height) {
        sbp_command(gui);
        return;
    }
    add_message(gui->list_messages, get_response(app, pos));
}
