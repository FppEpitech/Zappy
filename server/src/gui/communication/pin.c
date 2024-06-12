/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** pin
*/

#include "rules.h"
#include "ai/ai.h"
#include "app/app.h"
#include "gui/gui.h"
#include "parsing.h"

#include <stddef.h>
#include <stdbool.h>

static bool is_str_number(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == '\r')
            continue;
        if (str[i] == '\n' && str[i - 1] == '\r')
            return true;
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

// TODO error
void pin_response(gui_t *gui, app_t *app, char *line)
{
    char *response = NULL;
    int player_id = 0;
    ia_t *ia = NULL;

    if (line[3] != ' ')
        return;
    line += 4;
    if (!is_str_number(line))
        return;
    player_id = atoi(line);
    ia = find_ia(app, player_id);
    if (ia == NULL)
        return;
    response = format_string("pin %d %d %d %d %d %d %d %d %d\n",
        ia->fd, ia->position->x, ia->position->y, ia->inventory->food,
        ia->inventory->linemate, ia->inventory->deraumere,
        ia->inventory->sibur, ia->inventory->mendiane,
        ia->inventory->phiras, ia->inventory->thystame);
    add_message(gui->list_messages, response);
}
