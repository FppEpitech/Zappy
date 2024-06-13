/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** pin
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

static char *get_response(ia_t *ia)
{
    char *response = NULL;

    response = format_string("pin %d %d %d %d %d %d %d %d %d %d\n",
        ia->fd, ia->position->x, ia->position->y, ia->inventory->food,
        ia->inventory->linemate, ia->inventory->deraumere,
        ia->inventory->sibur, ia->inventory->mendiane,
        ia->inventory->phiras, ia->inventory->thystame);
    return response;
}

void pin_response(gui_t *gui, app_t *app, char *line)
{
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
    add_message(gui->list_messages, get_response(ia));
}
