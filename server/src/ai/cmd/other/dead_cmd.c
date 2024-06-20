/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI dead response
*/

#include "ai/cmd/look.h"
#include "server/client.h"
#include "ai/cmd/command_ai.h"

void dead_response(ia_t *ai)
{
    char *reply = NULL;

    reply = strdup("dead\n");
    add_message(ai->list_messages, reply);
}
