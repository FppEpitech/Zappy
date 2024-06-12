/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** pdr
*/

#include "ai/ai.h"
#include "app/app.h"

void pdr_command(app_t *app, int player_id)
{
    char *response = NULL;
    list_node_t *gui_node = app->gui_list->first;

    for (int i = 0; i < 7; i++) {
        response = format_string("pdr %d %d\n", player_id, i);
        gui_node = app->gui_list->first;
        printf("%s", response);
        while (gui_node) {
            add_message(gui_node->data.gui->list_messages, response);
            gui_node = gui_node->next;
        }
    }
}
