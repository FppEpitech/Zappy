/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** tna
*/

#include "app/app.h"
#include "gui/gui.h"
#include "list/list.h"
#include "gui/communication.h"

#include <stdlib.h>
#include <string.h>

void tna_response(gui_t *gui, app_t *app, char *line)
{
    char *response = NULL;
    list_node_t *node = app->teams_list->first;

    if (strlen(line) != LEN_COMMAND) {
        suc_command(gui);
        return;
    }
    while (node) {
        response = format_string("tna %s\n", node->data.team->name);
        add_message(gui->list_messages, response);
        node = node->next;
    }
}
