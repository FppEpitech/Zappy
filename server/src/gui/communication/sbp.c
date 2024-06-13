/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** sbp
*/

#include "app/app.h"
#include "gui/gui.h"
#include "server/server.h"

void sbp_command(gui_t *gui)
{
    char *response = NULL;

    response = format_string("sbp\n");
    add_message(gui->list_messages, response);
}
