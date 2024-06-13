/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI incantation command
*/

#include "app/app.h"
#include "server/client.h"
#include "ai/cmd/command_ai.h"

static int check_position(vector2i_t *pos, ia_t *ai_check,
    size_t level, int status)
{
    if (ai_check->position->x == pos->x
    && ai_check->position->y == pos->y
    && ai_check->level == level) {
        if (status == END_INCANTATION &&
        ai_check->incantation->status_incantation == true)
            return 1;
        if (status == BEGIN_INCANTATION)
            return 1;
    }
    return 0;
}

static bool nb_player_level(list_t *teams, ia_t *ai,
    size_t number_ai, int status)
{
    size_t nb_ai_find = 0;
    list_node_t *temp_team = teams->first;
    list_node_t *ia_temp;
    team_t *team = NULL;

    while (temp_team) {
        team = temp_team->data.team;
        ia_temp = team->list_ai->first;
        while (ia_temp) {
            nb_ai_find += check_position(ai->position,
            ia_temp->data.ai, ai->level, status);
            ia_temp = ia_temp->next;
        }
        temp_team = temp_team->next;
    }
    if (nb_ai_find >= number_ai)
        return true;
    return false;
}

static bool verif_data(app_t *app, ia_t *ai, size_t *data, int status)
{
    int x = ai->position->x;
    int y = ai->position->y;

    if (app->game->map[y][x].linemate < data[1])
        return false;
    if (app->game->map[y][x].deraumere < data[2])
        return false;
    if (app->game->map[y][x].sibur < data[3])
        return false;
    if (app->game->map[y][x].mendiane < data[4])
        return false;
    if (app->game->map[y][x].phiras < data[5])
        return false;
    if (app->game->map[y][x].thystame < data[6])
        return false;
    if (nb_player_level(app->teams_list, ai, data[0], status) == false)
        return false;
    return true;
}

bool check_incantation(app_t *app, ia_t *ai, int status)
{
    bool result = false;

    if (ai->level == 1)
        result = verif_data(app, ai, (size_t[]) {1, 1, 0, 0, 0, 0, 0}, status);
    if (ai->level == 2)
        result = verif_data(app, ai, (size_t[]) {2, 1, 1, 1, 0, 0, 0}, status);
    if (ai->level == 3)
        result = verif_data(app, ai, (size_t[]) {2, 2, 0, 1, 0, 2, 0}, status);
    if (ai->level == 4)
        result = verif_data(app, ai, (size_t[]) {4, 1, 1, 2, 0, 1, 0}, status);
    if (ai->level == 5)
        result = verif_data(app, ai, (size_t[]) {4, 1, 2, 1, 3, 0, 0}, status);
    if (ai->level == 6)
        result = verif_data(app, ai, (size_t[]) {6, 1, 2, 3, 0, 1, 0}, status);
    if (ai->level == 7)
        result = verif_data(app, ai, (size_t[]) {6, 2, 2, 2, 2, 2, 1}, status);
    return result;
}
