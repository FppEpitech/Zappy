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

#include <stddef.h>
#include <stdbool.h>

// TODO error
void ppo_response(gui_t *gui, app_t *app, char *line)
{
    char *response = NULL;
    int player_id = 0;
    ia_t *ia = NULL;

    if (line[3] != ' ')
        return;
    line += 4;
    player_id = parse_positive_int_arg(line);
    if (player_id == CODE_ERROR_INVALID_NUMBER)
        return;
    player_id = atoi(line);
    ia = find_ia(app, player_id);
    if (ia == NULL)
        return;
    response = format_string("ppo %d %d %d %d\n",
        ia->fd, ia->position->x, ia->position->y, ia->direction);
    add_message(gui->list_messages, response);
}
