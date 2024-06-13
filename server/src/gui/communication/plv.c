/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** plv
*/

#include "rules.h"
#include "ai/ai.h"
#include "utils.h"
#include "app/app.h"
#include "gui/gui.h"
#include "parsing.h"
#include "gui/communication.h"

#include <stddef.h>
#include <stdbool.h>

void plv_response(gui_t *gui, app_t *app, char *line)
{
    char *response = NULL;
    int player_id = 0;
    ia_t *ia = NULL;

    if (line[3] != ' ') {
        suc_command(gui);
        return;
    }
    player_id = parse_positive_int_arg(line + 4);
    if (player_id == CODE_ERROR_INVALID_NUMBER) {
        sbp_command(gui);
        return;
    }
    ia = find_ia(app, player_id);
    if (ia == NULL) {
        sbp_command(gui);
        return;
    }
    response = format_string("plv %d %d\n", ia->fd, ia->level);
    add_message(gui->list_messages, response);
}
