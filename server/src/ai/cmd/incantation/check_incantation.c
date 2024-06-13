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

static void update_list_ai(int result_chk_pos, list_t *list_ai,
    list_node_t *ia_temp)
{
    node_data_t data = {0};

    if (result_chk_pos == 1) {
        data.ai = ia_temp->data.ai;
        list_add_back(list_ai, data);
    }
}

static list_t *get_ai_in_incantation(list_t *teams, ia_t *ai, int status)
{
    list_t *list_ai = list_new();
    list_node_t *temp_team = teams->first;
    list_node_t *ia_temp;
    size_t result_chk_pos = 0;

    if (list_ai == NULL)
        return NULL;
    while (temp_team) {
        ia_temp = temp_team->data.team->list_ai->first;
        while (ia_temp) {
            result_chk_pos = check_position(ai->position,
            ia_temp->data.ai, ai->level, status);
            update_list_ai(result_chk_pos, list_ai, ia_temp);
            ia_temp = ia_temp->next;
        }
        temp_team = temp_team->next;
    }
    return list_ai;
}

static list_t *nb_player_level(list_t *teams, ia_t *ai,
    size_t number_ai, int status)
{
    list_t *list_ai = get_ai_in_incantation(teams, ai, status);

    if (list_ai == NULL)
        return NULL;
    if (list_ai->len >= number_ai)
        return list_ai;
    return NULL;
}

static list_t *verif_data(app_t *app, ia_t *ai, size_t *data, int status)
{
    int x = ai->position->x;
    int y = ai->position->y;

    if (app->game->map[y][x].linemate < data[1])
        return NULL;
    if (app->game->map[y][x].deraumere < data[2])
        return NULL;
    if (app->game->map[y][x].sibur < data[3])
        return NULL;
    if (app->game->map[y][x].mendiane < data[4])
        return NULL;
    if (app->game->map[y][x].phiras < data[5])
        return NULL;
    if (app->game->map[y][x].thystame < data[6])
        return NULL;
    return nb_player_level(app->teams_list, ai, data[0], status);
}

list_t *check_incantation(app_t *app, ia_t *ai, int status)
{
    list_t *result = NULL;

    if (ai->level == 1)
        result = verif_data(app, ai, (size_t[]) {1, 0, 0, 0, 0, 0, 0}, status);
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
