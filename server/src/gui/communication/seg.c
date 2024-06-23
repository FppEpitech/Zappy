/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** seg
*/

#include "ai/ai.h"
#include "app/app.h"

void seg_command(app_t *app, char *team)
{
    char *response = NULL;
    list_node_t *gui_node = app->gui_list->first;

    printf("TEAM: [%s] win\n", team);
    while (gui_node) {
        response = format_string("seg %s\n", team);
        add_message(gui_node->data.gui->list_messages, response);
        gui_node = gui_node->next;
    }
}
