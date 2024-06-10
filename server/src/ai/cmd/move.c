/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI command move
*/

#include "app/app.h"
#include "server/client.h"

static void forward_cmd(app_t *app, ia_t *ai)
{
    if (ai->direction == NORTH) {
        ai->position->y = (ai->position->y == 0) ?
        (int)(app->game->height - 1) : (int)(ai->position->y - 1);
    }
    if (ai->direction == EAST) {
        ai->position->x = (ai->position->x == (int) app->game->width - 1) ?
        (0) : (ai->position->x + 1);
    }
    if (ai->direction == SOUTH) {
        ai->position->y = (ai->position->y == (int) app->game->height - 1) ?
        (0) : (ai->position->y + 1);
    }
    if (ai->direction == WEST) {
        ai->position->x = (ai->position->x == 0) ?
        (int)(app->game->width - 1) : (int)(ai->position->x - 1);
    }
    set_time_stuck(ai, 7 / app->game->freq);
}

static void right_cmd(app_t *app, ia_t *ai)
{
    if (ai->direction == NORTH) {
        ai->direction = EAST;
        set_time_stuck(ai, 7 / app->game->freq);
        return;
    }
    if (ai->direction == EAST) {
        ai->direction = SOUTH;
        set_time_stuck(ai, 7 / app->game->freq);
        return;
    }
    if (ai->direction == SOUTH) {
        ai->direction = WEST;
        set_time_stuck(ai, 7 / app->game->freq);
        return;
    }
    if (ai->direction == WEST) {
        ai->direction = NORTH;
        set_time_stuck(ai, 7 / app->game->freq);
        return;
    }
}

static void left_cmd(app_t *app, ia_t *ai)
{
    if (ai->direction == NORTH) {
        ai->direction = WEST;
        set_time_stuck(ai, 7 / app->game->freq);
        return;
    }
    if (ai->direction == WEST) {
        ai->direction = SOUTH;
        set_time_stuck(ai, 7 / app->game->freq);
        return;
    }
    if (ai->direction == SOUTH) {
        ai->direction = EAST;
        set_time_stuck(ai, 7 / app->game->freq);
        return;
    }
    if (ai->direction == EAST) {
        ai->direction = NORTH;
        set_time_stuck(ai, 7 / app->game->freq);
        return;
    }
}

bool move_command(app_t *app, ia_t *ai, char *line)
{
    char *reply = NULL;

    reply = format_string("ok\n");
    if (strcmp("Forward", line) == 0) {
        forward_cmd(app, ai);
        add_message(ai->list_messages, reply);
        return true;
    }
    if (strcmp("Right", line) == 0) {
        right_cmd(app, ai);
        add_message(ai->list_messages, reply);
        return true;
    }
    if (strcmp("Left", line) == 0) {
        left_cmd(app, ai);
        add_message(ai->list_messages, reply);
        return true;
    }
    return false;
}
