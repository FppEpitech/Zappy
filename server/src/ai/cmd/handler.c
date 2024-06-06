/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI command handler
*/

#include "app/app.h"
#include "server/client.h"
#include "ai/command_ai.h"

void command_ai_handler(app_t *app, ia_t *ai, char *line)
{
    if (move_command(app, ai, line))
        return;
}
