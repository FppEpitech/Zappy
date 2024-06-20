/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** pnw
*/

#include "rules.h"
#include "ai/ai.h"
#include "app/app.h"
#include "gui/gui.h"

#include <stddef.h>

void pnw_command(app_t *app, ia_t *ai, gui_t *gui)
{
    char *response = NULL;
    list_node_t *gui_node = app->gui_list->first;

    if (gui) {
        response = format_string("pnw %d %d %d %d %d %s\n",
        ai->fd, ai->position->x, ai->position->y, ai->direction,
        ai->level, ai->team_name);
        add_message(gui->list_messages, response);
        return;
    }
    while (gui_node) {
        response = format_string("pnw %d %d %d %d %d %s\n",
        ai->fd, ai->position->x, ai->position->y, ai->direction,
        ai->level, ai->team_name);
        add_message(gui_node->data.gui->list_messages, response);
        gui_node = gui_node->next;
    }
}
