/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** bct
*/

#include "app/app.h"
#include "gui/gui.h"
#include "types.h"

static vector2i_t get_pos_requested(char *line)
{
    vector2i_t pos = {0, 0};

    pos.x = atoi(strtok(line, " "));
    pos.y = atoi(strtok(NULL, " \n\r"));
    return pos;
}

// TODO error handling
void bct_response(gui_t *gui, app_t *app, char *line)
{
    char *response = NULL;
    vector2i_t pos = {0, 0};

    if (line[3] != ' ')
        return;
    line += 4;
    pos = get_pos_requested(line);
    if (pos.x < 0 || (size_t)pos.x >= app->game->width ||
        pos.y < 0 || (size_t)pos.y >= app->game->height)
        return;
    response = format_string("bct %d %d %d %d %d %d %d %d\n",
        pos.x, pos.y,
        app->game->map[pos.y][pos.x].food,
        app->game->map[pos.y][pos.x].linemate,
        app->game->map[pos.y][pos.x].deraumere,
        app->game->map[pos.y][pos.x].sibur,
        app->game->map[pos.y][pos.x].mendiane,
        app->game->map[pos.y][pos.x].phiras,
        app->game->map[pos.y][pos.x].thystame);
    add_message(gui->list_messages, response);
}
