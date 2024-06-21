/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** pie
*/

#include "app/app.h"
#include "gui/gui.h"

#include <stddef.h>

void pie_command(app_t *app, list_t *ai)
{
    char *response = NULL;
    list_node_t *gui_node = app->gui_list->first;

    while (gui_node) {
        response = format_string("pie %d %d %d\n",
        ai->first->data.ai->position->x,
        ai->first->data.ai->position->y,
        ai->first->data.ai->level + 1);
        add_message(gui_node->data.gui->list_messages, response);
        gui_node = gui_node->next;
    }
    list_free(ai);
}
