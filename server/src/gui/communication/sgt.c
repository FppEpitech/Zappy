/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** sgt
*/

#include "app/app.h"
#include "gui/gui.h"

#include <stddef.h>


void sgt_response(gui_t *gui, app_t *app)
{
    char *response = NULL;
    int freq = app->game->freq;

    response = format_string("sgt %d\n", freq);
    add_message(gui->list_messages, response);
}
