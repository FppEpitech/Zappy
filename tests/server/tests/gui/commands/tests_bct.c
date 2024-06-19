/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_bct
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "types.h"
#include "app/app.h"
#include "gui/gui.h"
#include "gui/communication.h"

Test(bct_response, valid_position)
{
    gui_t gui;
    app_t app;
    char line[] = "bct 2 3";

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

    bct_response(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->data.message, "bct 2 3 1 2 3 4 5 6 7\n");
    free_map(app.game->map, 5);
}

Test(bct_response, invalid_position_x)
{
    gui_t gui;
    app_t app;
    char line[] = "bct -2 3";

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

    bct_response(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->data.message, "sbp\n");
    free_map(app.game->map, 5);
}

Test(bct_response, invalid_position_y)
{
    gui_t gui;
    app_t app;
    char line[] = "bct 2 -3";

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

    bct_response(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->data.message, "sbp\n");
    free_map(app.game->map, 5);
}

Test(bct_response, invalid_position_xy)
{
    gui_t gui;
    app_t app;
    char line[] = "bct -2 -3";

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

    bct_response(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->data.message, "sbp\n");
    free_map(app.game->map, 5);
}

Test(bct_response, higher_position_x)
{
    gui_t gui;
    app_t app;
    char line[] = "bct 10 3";

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

    bct_response(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->data.message, "sbp\n");
    free_map(app.game->map, 5);
}

Test(bct_response, higher_position_y)
{
    gui_t gui;
    app_t app;
    char line[] = "bct 2 10";

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

    bct_response(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->data.message, "sbp\n");
    free_map(app.game->map, 5);
}

Test(bct_response, higher_position_xy)
{
    gui_t gui;
    app_t app;
    char line[] = "bct 10 10";

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

    bct_response(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->data.message, "sbp\n");
    free_map(app.game->map, 5);
}

Test(bct_response, invalid_command)
{
    gui_t gui;
    app_t app;
    char line[] = "bct2 -3";

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

    bct_response(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->data.message, "suc\n");
    free_map(app.game->map, 5);
}
