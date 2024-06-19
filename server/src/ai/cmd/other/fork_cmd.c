/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI fork cmd
*/

#include "ai/cmd/look.h"
#include "server/client.h"
#include "ai/cmd/command_ai.h"
#include "gui/communication.h"

void fork_cmd(app_t *app, ia_t *ai)
{
    team_t *team = find_team(app, ai->fd);
    char *reply = format_string("ok\n");

    add_egg_on_player(team->eggs_list, ai->fd, app, ai);
    pfk_command(app, ai->fd);
    add_message(ai->list_messages, reply);
    printf("EGG IS LAYING\n");
}
