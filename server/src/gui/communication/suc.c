/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** suc
*/

#include "app/app.h"
#include "gui/gui.h"
#include "server/server.h"

void suc_command(gui_t *gui)
{
    char *response = NULL;

    response = format_string("suc\n");
    add_message(gui->list_messages, response);
}
