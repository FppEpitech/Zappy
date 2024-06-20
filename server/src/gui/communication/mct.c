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

static char *get_string(app_t *app, int x, int y)
{
    char *response = format_string("bct %d %d %d %d %d %d %d %d %d\n", x, y,
        app->game->map[y][x].food,
        app->game->map[y][x].linemate,
        app->game->map[y][x].deraumere,
        app->game->map[y][x].sibur,
        app->game->map[y][x].mendiane,
        app->game->map[y][x].phiras,
        app->game->map[y][x].thystame);

    return response;
}

static void free_tile_map(char *tile, char *map)
{
    free(tile);
    free(map);
}

void mct_response(gui_t *gui, app_t *app, char *line)
{
    char *tile = NULL;
    char *map = strdup("");
    char *final_response = NULL;

    if (!map)
        return;
    if (strlen(line) != LEN_COMMAND) {
        suc_command(gui);
        return;
    }
    for (size_t y = 0; y < app->game->height; y++) {
        for (size_t x = 0; x < app->game->width; x++) {
            tile = get_string(app, x, y);
            final_response = format_string("%s%s", map, tile);
            free_tile_map(tile, map);
            map = strdup(final_response);
            free(final_response);
        }
    }
    add_message(gui->list_messages, map);
}
