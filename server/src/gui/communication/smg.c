/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** smg
*/

#include "ai/ai.h"
#include "app/app.h"

void smg_command(app_t *app, char *message)
{
    char *response = NULL;
    list_node_t *gui_node = app->gui_list->first;

    response = format_string("smg %s\n", message);
    while (gui_node) {
        add_message(gui_node->data.gui->list_messages, response);
        gui_node = gui_node->next;
    }
}
