/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI command look east
*/

#include "ai/cmd/look.h"
#include "server/client.h"

static int get_x_line(app_t *app, ia_t *ai, int index_line)
{
    int depart_x = ai->position->x;

    for (int level_ai = index_line; level_ai != 0; level_ai--) {
        if (depart_x + 1 == (int) app->game->width)
            depart_x = 0;
        else
            depart_x++;
    }
    return depart_x;
}

static int decremente_value(app_t *app, int depart_y, int count)
{
    if (depart_y + count < 0)
        return ((int) app->game->height - 1);
    else if (depart_y + count == (int) app->game->height)
        return 0;
    else
        return depart_y + count;
}

static int get_y_line(app_t *app, ia_t *ai, int index_tile)
{
    int depart_y = ai->position->y;
    int goal = index_tile;
    int count = 0;

    if (index_tile == 0)
        return depart_y;
    if (index_tile < 0)
        count = -1;
    else
        count = 1;
    for (int index = 0; index != goal; index += count)
        depart_y = decremente_value(app, depart_y, count);
    return depart_y;
}

void look_east(app_t *app, ia_t *ai, int index_line, char **reply)
{
    vector2i_t *pos = create_vector2i(0, 0);

    pos->x = get_x_line(app, ai, index_line);
    for (int index_tile = (-index_line); index_tile <= index_line;
    index_tile++) {
        pos->y = get_y_line(app, ai, index_tile);
        check_player(pos, app, reply, ai);
        check_egg(pos, app, reply);
        check_resources(pos, app, reply);
        if (index_line != (int) ai->level || index_tile != index_line)
            concatenate_strings(reply, ",");
    }
    free(pos);
}
