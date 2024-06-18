/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Game win
*/

#include "app/app.h"
#include "gui/communication.h"

static size_t check_max_level(ia_t *ai)
{
    if (ai->level == 8)
        return 1;
    else
        return 0;
    return 0;
}

bool check_win(app_t *app)
{
    list_node_t *temp_team = app->teams_list->first;
    team_t *team = NULL;
    list_node_t *ia_temp = NULL;
    size_t nb_player_max = 0;

    while (temp_team) {
        team = temp_team->data.team;
        ia_temp = team->list_ai->first;
        while (ia_temp) {
            nb_player_max += check_max_level(ia_temp->data.ai);
            ia_temp = ia_temp->next;
        }
        if (nb_player_max >= 6) {
            seg_command(app, team->name);
            return true;
        }
        nb_player_max = 0;
        temp_team = temp_team->next;
    }
    return false;
}
