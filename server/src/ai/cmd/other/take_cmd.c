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

void take_cmd(app_t *app, ia_t *ai)
{
    int ai_x = ai->position->x;
    int ai_y = ai->position->y;
    char *reply = format_string("ok\n");

    ai->inventory->food += app->game->map[ai_y][ai_x].food;
    app->game->map[ai_y][ai_x].food = 0;
    ai->inventory->linemate += app->game->map[ai_y][ai_x].linemate;
    app->game->map[ai_y][ai_x].linemate = 0;
    ai->inventory->deraumere += app->game->map[ai_y][ai_x].deraumere;
    app->game->map[ai_y][ai_x].deraumere = 0;
    ai->inventory->sibur += app->game->map[ai_y][ai_x].sibur;
    app->game->map[ai_y][ai_x].sibur = 0;
    ai->inventory->mendiane += app->game->map[ai_y][ai_x].mendiane;
    app->game->map[ai_y][ai_x].mendiane = 0;
    ai->inventory->phiras += app->game->map[ai_y][ai_x].phiras;
    app->game->map[ai_y][ai_x].phiras = 0;
    ai->inventory->thystame += app->game->map[ai_y][ai_x].thystame;
    app->game->map[ai_y][ai_x].thystame = 0;
    add_message(ai->list_messages, reply);
    pgt_command(app, ai->fd);
}
