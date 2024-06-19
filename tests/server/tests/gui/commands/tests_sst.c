/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** test_sst
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "types.h"
#include "app/app.h"
#include "gui/gui.h"
#include "gui/communication.h"

Test(sst_response, basic_test)
{
    gui_t gui;
    app_t app;
    char line[] = "sst 1";

    app.game = create_game(5, 5, 0);

    gui.list_messages = list_new();
    cr_assert_not_null(gui.list_messages);
    gui.fd = 0;

    sgt_response(&gui, &app, "sgt");
    cr_assert_str_eq(gui.list_messages->first->data.message, "sgt 0\n");
    sst_response(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->next->data.message, "sst 1\n");
    sgt_response(&gui, &app, "sgt");
    cr_assert_str_eq(gui.list_messages->first->next->next->data.message, "sgt 1\n");
    free_map(app.game->map, 5);
}

Test(sst_response, basic_test_2)
{
    gui_t gui;
    app_t app;
    char line[] = "sst 54";

    app.game = create_game(5, 5, 5);

    gui.list_messages = list_new();
    cr_assert_not_null(gui.list_messages);
    gui.fd = 1;

    sgt_response(&gui, &app, "sgt");
    cr_assert_str_eq(gui.list_messages->first->data.message, "sgt 5\n");
    sst_response(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->next->data.message, "sst 54\n");
    sgt_response(&gui, &app, "sgt");
    cr_assert_str_eq(gui.list_messages->first->next->next->data.message, "sgt 54\n");
    free_map(app.game->map, 5);
}

Test(sst_response, invalid_command)
{
    gui_t gui;
    app_t app;
    char line[] = "sst2 -3";

    app.game = create_game(5, 5, 1);

    gui.list_messages = list_new();
    cr_assert_not_null(gui.list_messages);
    gui.fd = 1;

    sst_response(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->data.message, "suc\n");
    free_map(app.game->map, 5);
}

Test(sst_response, invalid_parameter)
{
    gui_t gui;
    app_t app;
    char line[] = "sst -2";

    app.game = create_game(5, 5, 1);

    gui.list_messages = list_new();
    cr_assert_not_null(gui.list_messages);
    gui.fd = 1;

    sst_response(&gui, &app, line);
    cr_assert_str_eq(gui.list_messages->first->data.message, "sbp\n");
    free_map(app.game->map, 5);
}
