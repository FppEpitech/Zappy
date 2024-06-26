/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI die
*/

#include "utils.h"
#include "server/client.h"
#include "ai/cmd/command_ai.h"
#include "gui/communication.h"

static void change_ai(app_t *app, ia_t *ai)
{
    team_t *ai_team = find_team(app, ai->fd);
    list_node_t *node = ai_team->list_ai->first;

    while (node) {
        if (node->data.ai->fd == ai->fd)
            break;
        node = node->next;
    }
    list_delete(ai_team->list_ai, node);
    if (ai_team->max_place > ai_team->eggs_list->len) {
        add_egg(ai_team->eggs_list, -1, app);
        pfk_command(app, -1);
    }
}

void free_ai(app_t *app, ia_t *ai)
{
    destroy_message_list(ai->list_messages);
    destroy_command_list(ai->list_command);
    free(ai->position);
    free(ai->inventory);
    free(ai->incantation);
    free(ai->time);
    list_free(ai->list_command);
    list_free(ai->list_messages);
    close(ai->fd);
    change_ai(app, ai);
    free(ai);
}

static void ia_die(app_t *app, ia_t *ai)
{
    ai->dead = true;
    dead_response(ai);
    pdi_command(app, ai->fd);
}

static void check_statut_life(app_t *app, ia_t *ai)
{
    char *response = NULL;
    list_node_t *temp = app->gui_list->first;

    if (time_elapsed(&ai->time->start_life) >= ai->time->total_life) {
        if (ai->inventory->food == 0) {
            ia_die(app, ai);
            return;
        }
        gettimeofday(&ai->time->start_life, NULL);
        ai->time->total_life = 126.0 / app->game->freq;
        ai->inventory->food -= 1;
        while (temp) {
            response = format_string("pin %d", ai->fd);
            pin_response(temp->data.gui, app, response);
            temp = temp->next;
        }
    }
}

void check_die(app_t *app)
{
    list_node_t *temp_team = app->teams_list->first;
    team_t *team = NULL;
    list_node_t *ia_temp = NULL;
    list_node_t *next = NULL;

    while (temp_team) {
        team = temp_team->data.team;
        ia_temp = team->list_ai->first;
        while (ia_temp) {
            next = ia_temp->next;
            check_statut_life(app, ia_temp->data.ai);
            ia_temp = next;
        }
        temp_team = temp_team->next;
    }
}
