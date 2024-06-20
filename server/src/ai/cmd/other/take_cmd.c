/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI take cmd
*/

#include "ai/cmd/look.h"
#include "server/client.h"
#include "ai/cmd/command_ai.h"
#include "gui/communication.h"

static bool take_food(app_t *app, ia_t *ai, char *ressource)
{
    char *reply = NULL;
    int ai_x = ai->position->x;
    int ai_y = ai->position->y;

    if (strcmp(ressource, "food") == 0) {
        if (app->game->map[ai_y][ai_x].food > 0) {
            ai->inventory->food += 1;
            app->game->map[ai_y][ai_x].food -= 1;
            reply = format_string("ok\n");
            add_message(ai->list_messages, reply);
            pgt_command(app, ai->fd, FOOD_INDEX);
            return true;
        }
    }
    return false;
}

static bool take_linemate(app_t *app, ia_t *ai, char *ressource)
{
    char *reply = NULL;
    int ai_x = ai->position->x;
    int ai_y = ai->position->y;

    if (strcmp(ressource, "linemate") == 0) {
        if (app->game->map[ai_y][ai_x].linemate > 0) {
            ai->inventory->linemate += 1;
            app->game->map[ai_y][ai_x].linemate -= 1;
            reply = format_string("ok\n");
            add_message(ai->list_messages, reply);
            pgt_command(app, ai->fd, LINEMATE_INDEX);
            return true;
        }
    }
    return false;
}

static bool take_deraumere(app_t *app, ia_t *ai, char *ressource)
{
    char *reply = NULL;
    int ai_x = ai->position->x;
    int ai_y = ai->position->y;

    if (strcmp(ressource, "deraumere") == 0) {
        if (app->game->map[ai_y][ai_x].deraumere > 0) {
            ai->inventory->deraumere += 1;
            app->game->map[ai_y][ai_x].deraumere -= 1;
            reply = format_string("ok\n");
            add_message(ai->list_messages, reply);
            pgt_command(app, ai->fd, DERAUMERE_INDEX);
            return true;
        }
    }
    return false;
}

static bool take_sibur(app_t *app, ia_t *ai, char *ressource)
{
    char *reply = NULL;
    int ai_x = ai->position->x;
    int ai_y = ai->position->y;

    if (strcmp(ressource, "sibur") == 0) {
        if (app->game->map[ai_y][ai_x].sibur > 0) {
            ai->inventory->sibur += 1;
            app->game->map[ai_y][ai_x].sibur -= 1;
            reply = format_string("ok\n");
            add_message(ai->list_messages, reply);
            pgt_command(app, ai->fd, SIBUR_INDEX);
            return true;
        }
    }
    return false;
}

static bool take_mendiane(app_t *app, ia_t *ai, char *ressource)
{
    char *reply = NULL;
    int ai_x = ai->position->x;
    int ai_y = ai->position->y;

    if (strcmp(ressource, "mendiane") == 0) {
        if (app->game->map[ai_y][ai_x].mendiane > 0) {
            ai->inventory->mendiane += 1;
            app->game->map[ai_y][ai_x].mendiane -= 1;
            reply = format_string("ok\n");
            add_message(ai->list_messages, reply);
            pgt_command(app, ai->fd, MENDIANE_INDEX);
            return true;
        }
    }
    return false;
}

static bool take_phiras(app_t *app, ia_t *ai, char *ressource)
{
    char *reply = NULL;
    int ai_x = ai->position->x;
    int ai_y = ai->position->y;

    if (strcmp(ressource, "phiras") == 0) {
        if (app->game->map[ai_y][ai_x].phiras > 0) {
            ai->inventory->phiras += 1;
            app->game->map[ai_y][ai_x].phiras -= 1;
            reply = format_string("ok\n");
            add_message(ai->list_messages, reply);
            pgt_command(app, ai->fd, PHIRAS_INDEX);
            return true;
        }
    }
    return false;
}

static bool take_thystame(app_t *app, ia_t *ai, char *ressource)
{
    char *reply = NULL;
    int ai_x = ai->position->x;
    int ai_y = ai->position->y;

    if (strcmp(ressource, "thystame") == 0) {
        if (app->game->map[ai_y][ai_x].thystame > 0) {
            ai->inventory->thystame += 1;
            app->game->map[ai_y][ai_x].thystame -= 1;
            reply = format_string("ok\n");
            add_message(ai->list_messages, reply);
            pgt_command(app, ai->fd, THYSTAME_INDEX);
            return true;
        }
    }
    return false;
}

void take_cmd(app_t *app, ia_t *ai, char *ressource)
{
    char *bad_response = NULL;

    if (take_food(app, ai, ressource))
        return;
    if (take_linemate(app, ai, ressource))
        return;
    if (take_deraumere(app, ai, ressource))
        return;
    if (take_sibur(app, ai, ressource))
        return;
    if (take_mendiane(app, ai, ressource))
        return;
    if (take_phiras(app, ai, ressource))
        return;
    if (take_thystame(app, ai, ressource))
        return;
    bad_response = format_string("ko\n");
    add_message(ai->list_messages, bad_response);
}
