/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI command move
*/

#include "ai/cmd/look.h"
#include "server/client.h"
#include "ai/cmd/command_ai.h"

bool object_info_command(app_t *app, ia_t *ai, char *line)
{
    if (strcmp("Look", line) == 0) {
        look_cmd(app, ai);
        return true;
    }
    return false;
}
