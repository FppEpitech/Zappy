/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI broadcast command
*/

#include <math.h>

#include "app/app.h"
#include "server/client.h"
#include "ai/cmd/command_ai.h"

static vector2i_t *min_distance(vector2i_t *base,
    vector2i_t *first, vector2i_t *second)
{
    if (sqrt(pow(base->x - first->x, 2) + pow(base->y - first->y, 2)) <
    sqrt(pow(base->x - second->x, 2) + pow(base->y - second->y, 2))) {
        free(second);
        return first;
    } else {
        free(first);
        return second;
    }
}

static vector2i_t *find_closest_distance(app_t *app,
    vector2i_t *sender, ia_t *ai_destination)
{
    int ai_x = ai_destination->position->x;
    int ai_y = ai_destination->position->y;
    vector2i_t *up_middle = create_vector2i(ai_x + app->game->width, ai_y);
    vector2i_t *middle_left = create_vector2i(ai_x, ai_y + app->game->height);
    vector2i_t *middle_middle = create_vector2i(ai_x + app->game->width,
    ai_y + app->game->height);
    vector2i_t *middle_right = create_vector2i(ai_x + (2 * app->game->width),
    ai_y + app->game->height);
    vector2i_t *down_middle = create_vector2i(ai_x + app->game->width,
    ai_y + (2 * app->game->height));
    vector2i_t *min = min_distance(sender, up_middle, middle_left);

    min = min_distance(sender, min, middle_middle);
    min = min_distance(sender, min, middle_right);
    min = min_distance(sender, min, down_middle);
    return min;
}

static size_t tile_hit_north(double angle)
{
    if (0 <= angle && angle <= 22.5)
        return 3;
    if (22.5 < angle && angle <= 67.5)
        return 2;
    if (67.5 < angle && angle <= 112.5)
        return 1;
    if (112.5 < angle && angle <= 157.5)
        return 8;
    if (157.5 < angle && angle <= 180.0)
        return 7;
    if (-180.0 <= angle && angle <= -157.5)
        return 7;
    if (-157.5 < angle && angle <= -112.5)
        return 6;
    if (-112.5 < angle && angle <= -67.5)
        return 5;
    if (-67.5 < angle && angle <= -22.5)
        return 4;
    else
        return 3;
}

static size_t tile_hit_east(double angle)
{
    if (0 <= angle && angle <= 22.5)
        return 5;
    if (22.5 < angle && angle <= 67.5)
        return 4;
    if (67.5 < angle && angle <= 112.5)
        return 3;
    if (112.5 < angle && angle <= 157.5)
        return 2;
    if (157.5 < angle && angle <= 180.0)
        return 1;
    if (-180.0 <= angle && angle <= -157.5)
        return 1;
    if (-157.5 < angle && angle <= -112.5)
        return 8;
    if (-112.5 < angle && angle <= -67.5)
        return 7;
    if (-67.5 < angle && angle <= -22.5)
        return 6;
    else
        return 5;
}

static size_t tile_hit_south(double angle)
{
    if (0 <= angle && angle <= 22.5)
        return 7;
    if (22.5 < angle && angle <= 67.5)
        return 6;
    if (67.5 < angle && angle <= 112.5)
        return 5;
    if (112.5 < angle && angle <= 157.5)
        return 4;
    if (157.5 < angle && angle <= 180.0)
        return 3;
    if (-180.0 <= angle && angle <= -157.5)
        return 3;
    if (-157.5 < angle && angle <= -112.5)
        return 2;
    if (-112.5 < angle && angle <= -67.5)
        return 1;
    if (-67.5 < angle && angle <= -22.5)
        return 8;
    else
        return 7;
}

static size_t tile_hit_west(double angle)
{
    if (0 <= angle && angle <= 22.5)
        return 1;
    if (22.5 < angle && angle <= 67.5)
        return 8;
    if (67.5 < angle && angle <= 112.5)
        return 7;
    if (112.5 < angle && angle <= 157.5)
        return 6;
    if (157.5 < angle && angle <= 180.0)
        return 5;
    if (-180.0 <= angle && angle <= -157.5)
        return 5;
    if (-157.5 < angle && angle <= -112.5)
        return 4;
    if (-112.5 < angle && angle <= -67.5)
        return 3;
    if (-67.5 < angle && angle <= -22.5)
        return 2;
    else
        return 1;
}

static void free_pos(vector2i_t *sender, vector2i_t *min)
{
    free(sender);
    free(min);
}

size_t calcul_k(app_t *app, ia_t *ai_sender, ia_t *ai_destination)
{
    vector2i_t *sender = create_vector2i(ai_sender->position->x +
    app->game->width, ai_sender->position->y + app->game->height);
    vector2i_t *min = find_closest_distance(app, sender, ai_destination);
    double angle = atan2(min->y - sender->y, min->x - sender->x);

    angle = angle * (180.0 / M_PI);
    if (sender->x == min->x && sender->y == min->y) {
        free_pos(sender, min);
        return 0;
    }
    free_pos(sender, min);
    if (ai_destination->direction == NORTH)
        return tile_hit_north(angle);
    if (ai_destination->direction == EAST)
        return tile_hit_east(angle);
    if (ai_destination->direction == SOUTH)
        return tile_hit_south(angle);
    if (ai_destination->direction == WEST)
        return tile_hit_west(angle);
    return 1;
}
