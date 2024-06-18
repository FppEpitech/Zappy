/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI connect_nbr cmd
*/

#include "ai/cmd/look.h"
#include "server/client.h"
#include "ai/cmd/command_ai.h"

void connect_nbr_cmd(app_t *app, ia_t *ai)
{
    team_t *team = find_team(app, ai->fd);
    char *reply = format_string("%d\n", team->eggs_list->len);

    add_message(ai->list_messages, reply);
}
