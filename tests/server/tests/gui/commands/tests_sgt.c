/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_sgt
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "types.h"
#include "app/app.h"
#include "gui/gui.h"
#include "gui/communication.h"
#include "gui/communication.h"

Test(sgt_response, basic_test)
{
    gui_t gui;
    app_t app;
    char line[] = "sgt";

    app.game = create_game(5, 5, 1);

    gui.list_messages = list_new();
    cr_assert_not_null(gui.list_messages);
    gui.fd = 1;

    sgt_response(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->data.message, "sgt 1\n");
    free_map(app.game->map, 5);
}

Test(sgt_response, basic_test_2)
{
    gui_t gui;
    app_t app;
    char line[] = "sgt";

    app.game = create_game(5, 5, 54);

    gui.list_messages = list_new();
    cr_assert_not_null(gui.list_messages);
    gui.fd = 1;

    sgt_response(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->data.message, "sgt 54\n");
    free_map(app.game->map, 5);
}

Test(sgt_response, invalid_command)
{
    gui_t gui;
    app_t app;
    char line[] = "sgt2 -3";

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

    sgt_response(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->data.message, "suc\n");
    free_map(app.game->map, 5);
}
