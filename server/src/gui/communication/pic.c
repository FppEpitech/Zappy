/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** pic
*/

#include "app/app.h"
#include "gui/gui.h"

#include <stddef.h>

static char *get_players(list_t *ai)
{
    char *players = NULL;
    list_node_t *node = ai->first;

    players = format_string("%d", node->data.ai->fd);
    node = node->next;
    while (node) {
        players = format_string("%s %d", players, node->data.ai->fd);
        node = node->next;
    }
    return players;
}

void pic_command(app_t *app, list_t *ai)
{
    char *response = NULL;
    char *players = get_players(ai);
    list_node_t *gui_node = app->gui_list->first;

    while (gui_node) {
        response = format_string("pic %d %d %d %s\n",
        ai->first->data.ai->position->x,
        ai->first->data.ai->position->y,
        ai->first->data.ai->level + 1, players);
        add_message(gui_node->data.gui->list_messages, response);
        gui_node = gui_node->next;
    }
}
