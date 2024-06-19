/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_mct
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "types.h"
#include "app/app.h"
#include "gui/gui.h"
#include "gui/communication.h"

Test(mct_response, valid_position)
{
    gui_t gui;
    app_t app;
    char line[] = "mct";

    app.game = create_game(2, 2, 1);
    app.game->map[0][0].food = 1;
    app.game->map[0][0].linemate = 2;
    app.game->map[0][0].deraumere = 3;
    app.game->map[0][0].sibur = 4;
    app.game->map[0][0].mendiane = 5;
    app.game->map[0][0].phiras = 6;
    app.game->map[0][0].thystame = 7;
    app.game->map[0][1].food = 0;
    app.game->map[0][1].linemate = 0;
    app.game->map[0][1].deraumere = 0;
    app.game->map[0][1].sibur = 0;
    app.game->map[0][1].mendiane = 0;
    app.game->map[0][1].phiras = 0;
    app.game->map[0][1].thystame = 0;
    app.game->map[1][0].food = 5;
    app.game->map[1][0].linemate = 1;
    app.game->map[1][0].deraumere = 1;
    app.game->map[1][0].sibur = 1;
    app.game->map[1][0].mendiane = 1;
    app.game->map[1][0].phiras = 1;
    app.game->map[1][0].thystame = 1;
    app.game->map[1][1].food = 3;
    app.game->map[1][1].linemate = 3;
    app.game->map[1][1].deraumere = 3;
    app.game->map[1][1].sibur = 3;
    app.game->map[1][1].mendiane = 3;
    app.game->map[1][1].phiras = 3;
    app.game->map[1][1].thystame = 3;

    gui.list_messages = list_new();
    cr_assert_not_null(gui.list_messages);
    gui.fd = 1;

    mct_response(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->data.message, "bct 0 0 1 2 3 4 5 6 7\nbct 1 0 0 0 0 0 0 0 0\nbct 0 1 5 1 1 1 1 1 1\nbct 1 1 3 3 3 3 3 3 3\n");
    free_map(app.game->map, 2);
}

Test(mct_response, invalid_command)
{
    gui_t gui;
    app_t app;
    char line[] = "mctee";

    app.game = create_game(5, 5, 1);
    app.game->map[3][2].food = 1;
    app.game->map[3][2].linemate = 2;
    app.game->map[3][2].deraumere = 3;
    app.game->map[3][2].sibur = 4;
    app.game->map[3][2].mendiane = 5;
    app.game->map[3][2].phiras = 6;
    app.game->map[3][2].thystame = 7;

    gui.list_messages = list_new();
    cr_assert_not_null(gui.list_messages);
    gui.fd = 1;

    mct_response(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->data.message, "suc\n");
    free_map(app.game->map, 5);
}
