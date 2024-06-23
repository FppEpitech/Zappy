/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** app
*/

#include "server/client.h"

static void destroy_egg(list_t *egg_list)
{
    list_node_t *temp = egg_list->first;

    while (temp) {
        free(temp->data.egg->pos);
        free(temp->data.egg);
        temp = temp->next;
    }
}

static void destroy_ai(ia_t *ai)
{
    close(ai->fd);
    destroy_message_list(ai->list_messages);
    destroy_command_list(ai->list_command);
    free(ai->position);
    free(ai->inventory);
    free(ai->incantation);
    free(ai->time);
    list_free(ai->list_command);
    list_free(ai->list_messages);
    free(ai);
}

void destroy_team(list_t *teams_list)
{
    list_node_t *temp = teams_list->first;
    team_t *team = NULL;
    list_node_t *ia_temp = NULL;

    while (temp) {
        team = temp->data.team;
        ia_temp = team->list_ai->first;
        while (ia_temp) {
            destroy_ai(ia_temp->data.ai);
            ia_temp = ia_temp->next;
        }
        list_free(team->list_ai);
        destroy_egg(team->eggs_list);
        list_free(team->eggs_list);
        free(team->name);
        free(team);
        temp = temp->next;
    }
    list_free(teams_list);
}
