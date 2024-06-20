/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** sst
*/

#include "rules.h"
#include "utils.h"
#include "app/app.h"
#include "gui/gui.h"
#include "parsing.h"
#include "gui/communication.h"

#include <stddef.h>
#include <stdbool.h>
#include <string.h>

void sst_response(gui_t *gui, app_t *app, char *line)
{
    char *response = NULL;
    int freq = 0;

    if (line[POS_SPACE] != ' ') {
        suc_command(gui);
        return;
    }
    line += LEN_COMMAND_AND_SPACE;
    freq = parse_positive_int_arg(line);
    if (freq == CODE_ERROR_INVALID_NUMBER || freq == 0) {
        sbp_command(gui);
        return;
    }
    printf("sst %d\n", freq);
    app->game->freq = freq;
    response = format_string("sst %d\n", freq);
    add_message(gui->list_messages, response);
}
