/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI command handler
*/

#include "app/app.h"
#include "server/client.h"
#include "ai/cmd/command_ai.h"

void command_ai_handler(app_t *app, ia_t *ai, char *line)
{
    char *bad_command = NULL;

    bad_command = format_string("ko\n");
    if (move_command(app, ai, line))
        return;
    if (object_info_command(app, ai, line))
        return;
    if (little_command(app, ai, line))
        return;
    add_message(ai->list_messages, bad_command);
}
