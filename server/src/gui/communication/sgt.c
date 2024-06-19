/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** sgt
*/

#include "app/app.h"
#include "gui/gui.h"
#include "gui/communication.h"

#include <stddef.h>
#include <string.h>

void sgt_response(gui_t *gui, app_t *app, char *line)
{
    char *response = NULL;
    int freq = app->game->freq;

    if (strlen(line) != LEN_COMMAND) {
        suc_command(gui);
        return;
    }
    response = format_string("sgt %d\n", freq);
    add_message(gui->list_messages, response);
}
