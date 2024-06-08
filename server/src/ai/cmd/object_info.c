/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI command move
*/

#include "server/client.h"
#include "ai/command_ai.h"

bool object_info_command(app_t *app, ia_t *ai, char *line)
{
    char *reply = NULL;

    reply = format_string("ok\n");
    if (strcmp("Look", line) == 0) {
        look_cmd(app, ai);
        add_message(ai->list_messages, reply);
        return true;
    }
    return false;
}
