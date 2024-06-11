/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** AI die
*/

#include "server/client.h"
#include "ai/cmd/command_ai.h"

static void change_ai(app_t *app, ia_t *ai)
{
    team_t *ai_team = find_team(app, ai->fd);
    list_node_t *node = ai_team->list_ai->first;
    node_data_t data;

    data.client = create_client(ai->fd);
    if (data.client == NULL)
        return;
    list_add_back(app->clients_list, data);
    while (node) {
        if (node->data.ai->fd == ai->fd)
            break;
        node = node->next;
    }
    list_delete(ai_team->list_ai, node);
    if (ai_team->max_place > ai_team->egg_position->len) {
        add_egg(ai_team->egg_position, rand() % app->game->height,
        rand() % app->game->width);
    }
}

static void free_ai(ia_t *ai)
{
    destroy_message_list(ai->list_messages);
    destroy_command_list(ai->list_command);
    free(ai->position);
    free(ai->inventory);
    free(ai->incantation);
    free(ai->time);
    list_free(ai->list_command);
    list_free(ai->list_messages);
}

static void ia_die(app_t *app, ia_t *ai)
{
    list_node_t *temp_command = ai->list_command->first;
    list_node_t *temp_message = ai->list_messages->first;

    while (temp_command) {
        free(temp_command->data.command);
        temp_command = temp_command->next;
    }
    while (temp_message) {
        free(temp_message->data.message);
        temp_message = temp_message->next;
    }
    free_ai(ai);
    change_ai(app, ai);
    dead_response(app);
    free(ai);
}

static void check_statut_life(app_t *app, ia_t *ai)
{
    if (time_elapsed(&ai->time->start_life) >= ai->time->total_life) {
        if (ai->inventory->food == 0) {
            ia_die(app, ai);
            return;
        }
        gettimeofday(&ai->time->start_life, NULL);
        ai->time->total_life = 126.0 / app->game->freq;
        ai->inventory->food -= 1;
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
