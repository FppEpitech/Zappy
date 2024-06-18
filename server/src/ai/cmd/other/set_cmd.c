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

void set_cmd(app_t *app, ia_t *ai)
{
    int ai_x = ai->position->x;
    int ai_y = ai->position->y;
    char *reply = format_string("ok\n");

    app->game->map[ai_y][ai_x].food += ai->inventory->food;
    ai->inventory->food = 0;
    app->game->map[ai_y][ai_x].linemate += ai->inventory->linemate;
    ai->inventory->linemate = 0;
    app->game->map[ai_y][ai_x].deraumere += ai->inventory->deraumere;
    ai->inventory->deraumere = 0;
    app->game->map[ai_y][ai_x].sibur += ai->inventory->sibur;
    ai->inventory->sibur = 0;
    app->game->map[ai_y][ai_x].mendiane += ai->inventory->mendiane;
    ai->inventory->mendiane = 0;
    app->game->map[ai_y][ai_x].phiras += ai->inventory->phiras;
    ai->inventory->phiras = 0;
    app->game->map[ai_y][ai_x].thystame += ai->inventory->thystame;
    ai->inventory->thystame = 0;
    add_message(ai->list_messages, reply);
    pdr_command(app, ai->fd);
}
