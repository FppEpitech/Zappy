/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI command move
*/

#include "ai/cmd/look.h"
#include "server/client.h"

static int get_y_line(app_t *app, ia_t *ai, int index_line)
{
    int depart_y = ai->position->y;

    for (int level_ai = index_line; level_ai != 0; level_ai--) {
        if (depart_y - 1 < 0)
            depart_y = app->game->height - 1;
        else
            depart_y--;
    }
    return depart_y;
}

static int decremente_value(app_t *app, int depart_y, int decompte)
{
    if (depart_y + decompte < 0)
        return ((int) app->game->width - 1);
    else if (depart_y + decompte == (int) app->game->width)
        return 0;
    else
        return depart_y + decompte;
}

static int get_x_line(app_t *app, ia_t *ai, int index_tile)
{
    int depart_y = ai->position->x;
    int goal = index_tile;
    int decompte = 0;

    if (index_tile == 0)
        return depart_y;
    if (index_tile < 0)
        decompte = -1;
    else
        decompte = 1;
    for (int index = 0; index != goal; index += decompte) {
        depart_y = decremente_value(app, depart_y, decompte);
    }
    return depart_y;
}

void look_north(app_t *app, ia_t *ai, int index_line, char **reply)
{
    vector2i_t *pos = create_vector2i(0, 0);
    pos->y = get_y_line(app, ai, index_line);

    printf("\n");
    for (int index_tile = (-index_line); index_tile <= index_line; index_tile++) {
        pos->x = get_x_line(app, ai, index_tile);
        printf("x: [%d] | [%d] :y\n", pos->x, pos->y);
        check_player(pos, app, reply, ai);
        check_egg(pos, app, reply);
        if (index_line != (int) ai->level || index_tile != index_line)
            concatenate_strings(reply, ",");
    }
    printf("\n");
}