/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ebo
*/

#include "ai/ai.h"
#include "app/app.h"

void ebo_command(app_t *app, int egg_id)
{
    char *response = NULL;
    list_node_t *gui_node = app->gui_list->first;

    response = format_string("ebo %d\n", egg_id);
    while (gui_node) {
        add_message(gui_node->data.gui->list_messages, response);
        gui_node = gui_node->next;
    }
}
