/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** mct
*/

#include "app/app.h"
#include "gui/gui.h"
#include "types.h"

static void print_tile(gui_t *gui, app_t *app, vector2i_t pos)
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
    add_message(gui->list_messages, response);
}

// TODO error handling
void mct_response(gui_t *gui, app_t *app, char *line)
{
    (void) line;
    vector2i_t pos = {0, 0};

    while ((size_t)pos.y < app->game->height) {
        pos.x = 0;
        while ((size_t)pos.x < app->game->width) {
            print_tile(gui, app, pos);
            pos.x++;
        }
        pos.y++;
    }
}
