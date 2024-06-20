/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** enw
*/

#include "app/app.h"
#include "gui/gui.h"
#include "types.h"

#include <stddef.h>

void enw_command(app_t *app, egg_t *egg, gui_t *gui)
{
    char *response = NULL;
    list_node_t *gui_node = app->gui_list->first;

    if (gui) {
        response = format_string("enw %d %d %d %d\n", egg->id, egg->id_player_laid,
        egg->pos->x, egg->pos->y);
        add_message(gui->list_messages, response);
        return;
    }
    while (gui_node) {
        response = format_string("enw %d %d %d %d\n", egg->id, egg->id_player_laid,
        egg->pos->x, egg->pos->y);
        add_message(gui_node->data.gui->list_messages, response);
        gui_node = gui_node->next;
    }
}
