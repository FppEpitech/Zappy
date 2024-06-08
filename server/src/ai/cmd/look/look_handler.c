/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI command move
*/

#include "server/client.h"
#include "ai/command_ai.h"

void look_cmd(app_t *app, ia_t *ai)
{
    for (size_t index_line = 0; index_line <= ai->level; index_line++) {
        if (ai->direction == NORTH)
            look_north(app, ai, index_line);
    }
}