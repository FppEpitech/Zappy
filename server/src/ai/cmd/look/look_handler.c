/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI command move
*/

#include "ai/cmd/look.h"
#include "server/client.h"
#include "ai/cmd/command_ai.h"

static void concat_player(vector2i_t *pos, list_node_t *ia_temp,
    char **reply, ia_t *ai)
{
    if (ia_temp->data.ai->position->x == pos->x &&
    ia_temp->data.ai->position->y == pos->y &&
    ia_temp->data.ai->fd != ai->fd) {
        concatenate_strings(reply, PLAYER_STRING);
    }
}

void check_player(vector2i_t *pos, app_t *app, char **reply, ia_t *ai)
{
    list_node_t *temp = app->teams_list->first;
    team_t *team = NULL;
    list_node_t *ia_temp = NULL;

    while (temp) {
        team = temp->data.team;
        ia_temp = team->list_ai->first;
        while (ia_temp) {
            concat_player(pos, ia_temp, reply, ai);
            ia_temp = ia_temp->next;
        }
        temp = temp->next;
    }
}

static void concat_egg(vector2i_t *pos, list_node_t *egg_temp,
    char **reply)
{
    if (egg_temp->data.coord->x == pos->x &&
    egg_temp->data.coord->y == pos->y) {
        concatenate_strings(reply, EGG_STRING);
    }
}

void check_egg(vector2i_t *pos, app_t *app, char **reply)
{
    list_node_t *temp = app->teams_list->first;
    team_t *team = NULL;
    list_node_t *egg_temp = NULL;

    while (temp) {
        team = temp->data.team;
        egg_temp = team->egg_position->first;
        while (egg_temp) {
            concat_egg(pos, egg_temp, reply);
            egg_temp = egg_temp->next;
        }
        temp = temp->next;
    }
}

void look_cmd(app_t *app, ia_t *ai)
{
    char *reply = strdup("[player");

    for (size_t index_line = 0; index_line <= ai->level; index_line++) {
        if (ai->direction == NORTH)
            look_north(app, ai, index_line, &reply);
    }
    concatenate_strings(&reply, "]\n");
    add_message(ai->list_messages, reply);
}