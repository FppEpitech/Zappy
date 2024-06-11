/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI incantation command
*/

#include "app/app.h"
#include "server/client.h"
#include "ai/cmd/command_ai.h"

static void decremente_ressources(app_t *app, size_t *data, ia_t *ai)
{
    int x = ai->position->x;
    int y = ai->position->y;

    app->game->map[y][x].linemate -= data[1];
    app->game->map[y][x].deraumere -= data[2];
    app->game->map[y][x].sibur -= data[3];
    app->game->map[y][x].mendiane -= data[4];
    app->game->map[y][x].phiras -= data[5];
    app->game->map[y][x].thystame -= data[6];
}

static void delete_ressources(app_t *app, ia_t *ai)
{
    if (ai->level == 2)
        decremente_ressources(app, (size_t[]) {1, 1, 0, 0, 0, 0, 0}, ai);
    if (ai->level == 3)
        decremente_ressources(app, (size_t[]) {2, 1, 1, 1, 0, 0, 0}, ai);
    if (ai->level == 4)
        decremente_ressources(app, (size_t[]) {2, 2, 0, 1, 0, 2, 0}, ai);
    if (ai->level == 5)
        decremente_ressources(app, (size_t[]) {4, 1, 1, 2, 0, 1, 0}, ai);
    if (ai->level == 6)
        decremente_ressources(app, (size_t[]) {4, 1, 2, 1, 3, 0, 0}, ai);
    if (ai->level == 7)
        decremente_ressources(app, (size_t[]) {6, 1, 2, 3, 0, 1, 0}, ai);
    if (ai->level == 8)
        decremente_ressources(app, (size_t[]) {6, 2, 2, 2, 2, 2, 1}, ai);
}

static void update_ai(ia_t *ai, ia_t *ai_check,
    size_t level_before, size_t target_level)
{
    if (ai_check->position->x == ai->position->x
    && ai_check->position->y == ai->position->y
    && ai_check->level == level_before
    && ai_check->incantation->status_incantation == true
    && ai_check->incantation->target_level == target_level) {
        ai_check->incantation->status_incantation = false;
        ai_check->incantation->target_level = 0;
        ai_check->level += 1;
    }
}

void level_up(app_t *app, ia_t *ai)
{
    list_node_t *temp_team = app->teams_list->first;
    list_node_t *ia_temp;
    team_t *team = NULL;
    size_t level_before = ai->level;
    size_t target_level = ai->incantation->target_level;

    while (temp_team) {
        team = temp_team->data.team;
        ia_temp = team->list_ai->first;
        while (ia_temp) {
            update_ai(ai, ia_temp->data.ai, level_before, target_level);
            ia_temp = ia_temp->next;
        }
        temp_team = temp_team->next;
    }
    delete_ressources(app, ai);
}
