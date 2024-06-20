/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** pdr
*/

#include "ai/ai.h"
#include "app/app.h"

void pdr_command(app_t *app, int player_id, size_t index_ressource)
{
    char *response = NULL;
    list_node_t *gui_node = app->gui_list->first;

    response = format_string("pdr %d %d\n", player_id, index_ressource);
    gui_node = app->gui_list->first;
    while (gui_node) {
        add_message(gui_node->data.gui->list_messages, response);
        gui_node = gui_node->next;
    }
}
