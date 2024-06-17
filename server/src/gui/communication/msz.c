/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** MSZ command.
*/

#include "app/app.h"
#include "gui/gui.h"
#include "gui/communication.h"

#include <string.h>

void msz_response(gui_t *gui, app_t *app, char *line)
{
    char *response = NULL;

    if (strlen(line) != LEN_COMMAND) {
        sbp_command(gui);
        return;
    }
    response = format_string("msz %d %d\n", app->game->width,
    app->game->height);
    add_message(gui->list_messages, response);
}
