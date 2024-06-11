/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** sst
*/

#include "rules.h"
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
void sst_response(gui_t *gui, app_t *app, char *line)
{
    char *response = NULL;
    int freq = 0;

    if (line[3] != ' ')
        return;
    line += 4;
    if (!is_str_number(line))
        return;
    freq = atoi(line);
    app->game->freq = freq;
    response = format_string("sst %d\n", freq);
    add_message(gui->list_messages, response);
}
