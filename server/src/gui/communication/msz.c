/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** MSZ command.
*/

#include "app/app.h"
#include "gui/gui.h"

void msz_response(gui_t *gui, app_t *app, char *line)
{
    (void)line;
    char *response = NULL;

    response = format_string("msz %d %d\n", app->game->width,
    app->game->height);
    add_message(gui->list_messages, response);
}
