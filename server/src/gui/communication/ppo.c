/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ppo
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

    response = format_string("ppo %d %d %d %d\n",
        ia->fd, ia->position->x, ia->position->y, ia->direction);
    return response;
}

void send_ppo(app_t *app, ia_t *ia)
{
    char *response = NULL;
    list_node_t *tmp_gui = app->gui_list->first;

    while (tmp_gui) {
        response = format_string("ppo %d %d %d %d\n",
        ia->fd, ia->position->x, ia->position->y, ia->direction);
        add_message(tmp_gui->data.gui->list_messages, response);
        tmp_gui = tmp_gui->next;
    }
}

void ppo_response(gui_t *gui, app_t *app, char *line)
{
    int player_id = 0;
    ia_t *ia = NULL;

    if (line[POS_SPACE] != ' ') {
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
