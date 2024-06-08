/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI eject handler
*/

#include "ai/cmd/look.h"
#include "server/client.h"
#include "ai/cmd/command_ai.h"

void eject_cmd(app_t *app, ia_t *ai)
{
    char *reply = format_string("ok\n");

    eject_egg(app, ai);
    eject_player(app, ai);
    add_message(ai->list_messages, reply);
}
