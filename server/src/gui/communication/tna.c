/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** tna
*/

#include "app/app.h"
#include "gui/gui.h"
#include "list/list.h"

#include <stdlib.h>
#include <string.h>

#define TEAM_NAME data.team->name

void tna_response(gui_t *gui, app_t *app)
{
    char *response = NULL;
    list_node_t *node = app->teams_list->first;

    while (node) {
        response = format_string("tna %s\n", node->TEAM_NAME);
        add_message(gui->list_messages, response);
        node = node->next;
    }
}
