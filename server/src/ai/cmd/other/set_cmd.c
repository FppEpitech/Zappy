/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI set cmd
*/

#include "ai/cmd/look.h"
#include "server/client.h"
#include "ai/cmd/command_ai.h"
#include "gui/communication.h"

static bool set_food(app_t *app, ia_t *ai, char *ressource)
{
    char *reply = format_string("ok\n");
    int ai_x = ai->position->x;
    int ai_y = ai->position->y;

    if (strcmp(ressource, "food") == 0) {
        if (ai->inventory->food > 0) {
            ai->inventory->food -= 1;
            app->game->map[ai_y][ai_x].food += 1;
            add_message(ai->list_messages, reply);
            pdr_command(app, ai->fd, FOOD_INDEX);
            return true;
        }
    }
    return false;
}

static bool set_linemate(app_t *app, ia_t *ai, char *ressource)
{
    char *reply = format_string("ok\n");
    int ai_x = ai->position->x;
    int ai_y = ai->position->y;

    if (strcmp(ressource, "linemate") == 0) {
        if (ai->inventory->linemate > 0) {
            ai->inventory->linemate -= 1;
            app->game->map[ai_y][ai_x].linemate += 1;
            add_message(ai->list_messages, reply);
            pdr_command(app, ai->fd, LINEMATE_INDEX);
            return true;
        }
    }
    return false;
}

static bool set_deraumere(app_t *app, ia_t *ai, char *ressource)
{
    char *reply = format_string("ok\n");
    int ai_x = ai->position->x;
    int ai_y = ai->position->y;

    if (strcmp(ressource, "deraumere") == 0) {
        if (ai->inventory->deraumere > 0) {
            ai->inventory->deraumere -= 1;
            app->game->map[ai_y][ai_x].deraumere += 1;
            add_message(ai->list_messages, reply);
            pdr_command(app, ai->fd, DERAUMERE_INDEX);
            return true;
        }
    }
    return false;
}

static bool set_sibur(app_t *app, ia_t *ai, char *ressource)
{
    char *reply = format_string("ok\n");
    int ai_x = ai->position->x;
    int ai_y = ai->position->y;

    if (strcmp(ressource, "sibur") == 0) {
        if (ai->inventory->sibur > 0) {
            ai->inventory->sibur -= 1;
            app->game->map[ai_y][ai_x].sibur += 1;
            add_message(ai->list_messages, reply);
            pdr_command(app, ai->fd, SIBUR_INDEX);
            return true;
        }
    }
    return false;
}

static bool set_mendiane(app_t *app, ia_t *ai, char *ressource)
{
    char *reply = format_string("ok\n");
    int ai_x = ai->position->x;
    int ai_y = ai->position->y;

    if (strcmp(ressource, "mendiane") == 0) {
        if (ai->inventory->mendiane > 0) {
            ai->inventory->mendiane -= 1;
            app->game->map[ai_y][ai_x].mendiane += 1;
            add_message(ai->list_messages, reply);
            pdr_command(app, ai->fd, MENDIANE_INDEX);
            return true;
        }
    }
    return false;
}

static bool set_phiras(app_t *app, ia_t *ai, char *ressource)
{
    char *reply = format_string("ok\n");
    int ai_x = ai->position->x;
    int ai_y = ai->position->y;

    if (strcmp(ressource, "phiras") == 0) {
        if (ai->inventory->phiras > 0) {
            ai->inventory->phiras -= 1;
            app->game->map[ai_y][ai_x].phiras += 1;
            add_message(ai->list_messages, reply);
            pdr_command(app, ai->fd, PHIRAS_INDEX);
            return true;
        }
    }
    return false;
}

static bool set_thystame(app_t *app, ia_t *ai, char *ressource)
{
    char *reply = format_string("ok\n");
    int ai_x = ai->position->x;
    int ai_y = ai->position->y;

    if (strcmp(ressource, "thystame") == 0) {
        if (ai->inventory->thystame > 0) {
            ai->inventory->thystame -= 1;
            app->game->map[ai_y][ai_x].thystame += 1;
            add_message(ai->list_messages, reply);
            pdr_command(app, ai->fd, THYSTAME_INDEX);
            return true;
        }
    }
    return false;
}

void set_cmd(app_t *app, ia_t *ai, char *ressource)
{
    char *bad_response = format_string("ko\n");

    if (set_food(app, ai, ressource))
        return;
    if (set_linemate(app, ai, ressource))
        return;
    if (set_deraumere(app, ai, ressource))
        return;
    if (set_sibur(app, ai, ressource))
        return;
    if (set_mendiane(app, ai, ressource))
        return;
    if (set_phiras(app, ai, ressource))
        return;
    if (set_thystame(app, ai, ressource))
        return;
    add_message(ai->list_messages, bad_response);
}
