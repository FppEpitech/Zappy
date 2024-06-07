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
        return;
    }
    if (ai->direction == EAST) {
        ai->position->x = (ai->position->x == (int) app->game->width - 1) ?
        (0) : (ai->position->x + 1);
        return;
    }
    if (ai->direction == SOUTH) {
        ai->position->y = (ai->position->y == (int) app->game->height - 1) ?
        (0) : (ai->position->y + 1);
        return;
    }
    if (ai->direction == WEST) {
        ai->position->x = (ai->position->x == 0) ?
        (int)(app->game->width - 1) : (int)(ai->position->x - 1);
        return;
    }
}

static void right_cmd(ia_t *ai)
{
    if (ai->direction == NORTH) {
        ai->direction = EAST;
        return;
    }
    if (ai->direction == EAST) {
        ai->direction = SOUTH;
        return;
    }
    if (ai->direction == SOUTH) {
        ai->direction = WEST;
        return;
    }
    if (ai->direction == WEST) {
        ai->direction = NORTH;
        return;
    }
}

static void left_cmd(ia_t *ai)
{
    if (ai->direction == NORTH) {
        ai->direction = WEST;
        return;
    }
    if (ai->direction == WEST) {
        ai->direction = SOUTH;
        return;
    }
    if (ai->direction == SOUTH) {
        ai->direction = EAST;
        return;
    }
    if (ai->direction == EAST) {
        ai->direction = NORTH;
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
        right_cmd(ai);
        add_message(ai->list_messages, reply);
        return true;
    }
    if (strcmp("Left", line) == 0) {
        left_cmd(ai);
        add_message(ai->list_messages, reply);
        return true;
    }
    return false;
}
