/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI eject player
*/

#include "ai/cmd/look.h"
#include "server/client.h"
#include "ai/cmd/command_ai.h"

static void eject_response_north(ia_t *ai)
{
    char *reply = NULL;

    if (ai->direction == NORTH)
        reply = format_string("eject : %d\n", 5);
    if (ai->direction == EAST)
        reply = format_string("eject : %d\n", 7);
    if (ai->direction == SOUTH)
        reply = format_string("eject : %d\n", 1);
    if (ai->direction == WEST)
        reply = format_string("eject : %d\n", 3);
    add_message(ai->list_messages, reply);
}

static void eject_response_east(ia_t *ai)
{
    char *reply = NULL;

    if (ai->direction == NORTH)
        reply = format_string("eject : %d\n", 3);
    if (ai->direction == EAST)
        reply = format_string("eject : %d\n", 5);
    if (ai->direction == SOUTH)
        reply = format_string("eject : %d\n", 7);
    if (ai->direction == WEST)
        reply = format_string("eject : %d\n", 1);
    add_message(ai->list_messages, reply);
}

static void eject_response_south(ia_t *ai)
{
    char *reply = NULL;

    if (ai->direction == NORTH)
        reply = format_string("eject : %d\n", 1);
    if (ai->direction == EAST)
        reply = format_string("eject : %d\n", 3);
    if (ai->direction == SOUTH)
        reply = format_string("eject : %d\n", 5);
    if (ai->direction == WEST)
        reply = format_string("eject : %d\n", 7);
    add_message(ai->list_messages, reply);
}

static void eject_response_west(ia_t *ai)
{
    char *reply = NULL;

    if (ai->direction == NORTH)
        reply = format_string("eject : %d\n", 7);
    if (ai->direction == EAST)
        reply = format_string("eject : %d\n", 1);
    if (ai->direction == SOUTH)
        reply = format_string("eject : %d\n", 3);
    if (ai->direction == WEST)
        reply = format_string("eject : %d\n", 5);
    add_message(ai->list_messages, reply);
}

static void eject_direction(app_t *app, ia_t *ai, ia_t *ai_eject)
{
    if (ai_eject->direction == NORTH) {
        ai->position->y = (ai->position->y == 0) ?
        (int)(app->game->height - 1) : (int)(ai->position->y - 1);
        eject_response_north(ai);
    }
    if (ai_eject->direction == EAST) {
        ai->position->x = (ai->position->x == (int) app->game->width - 1)
        ? (0) : (ai->position->x + 1);
        eject_response_east(ai);
    }
    if (ai_eject->direction == SOUTH) {
        ai->position->y = (ai->position->y == (int) app->game->height - 1)
        ? (0) : (ai->position->y + 1);
        eject_response_south(ai);
    }
    if (ai_eject->direction == WEST) {
        ai->position->x = (ai->position->x == 0) ?
        (int)(app->game->width - 1) : (int)(ai->position->x - 1);
        eject_response_west(ai);
    }
}

static void check_position_player(app_t *app, ia_t *ai, ia_t *ai_eject)
{
    if (ai->position->x == ai_eject->position->x &&
    ai->position->y == ai_eject->position->y && ai->fd != ai_eject->fd) {
        eject_direction(app, ai, ai_eject);
    }
}

void eject_player(app_t *app, ia_t *ai)
{
    list_node_t *temp = app->teams_list->first;
    team_t *team = NULL;
    list_node_t *ia_temp = NULL;

    while (temp) {
        team = temp->data.team;
        ia_temp = team->list_ai->first;
        while (ia_temp) {
            check_position_player(app, ia_temp->data.ai, ai);
            ia_temp = ia_temp->next;
        }
        temp = temp->next;
    }
}
