/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** pex
*/

#include "ai/ai.h"
#include "app/app.h"

void pex_command(app_t *app, int player_id)
{
    char *response = NULL;
    list_node_t *gui_node = app->gui_list->first;

    response = format_string("pex %d\n", player_id);
    while (gui_node) {
        add_message(gui_node->data.gui->list_messages, response);
        gui_node = gui_node->next;
    }
}
