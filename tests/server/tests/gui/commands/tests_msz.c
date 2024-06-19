/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** tests_msz
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "gui/communication.h"

Test(msz_response, basic_test_with_gui)
{
    app_t app;
    gui_t gui;
    node_data_t gui_data;

    app.game = create_game(5, 5, 1);
    app.gui_list = list_new();
    cr_assert_not_null(app.gui_list);
    gui.list_messages = list_new();
    cr_assert_not_null(gui.list_messages);
    gui_data.gui = &gui;
    list_add_back(app.gui_list, gui_data);

    msz_response(&gui, &app, "msz");
    cr_assert_str_eq(gui.list_messages->first->data.message, "msz 5 5\n");
}

Test(msz_response, invalid_command)
{
    app_t app;
    gui_t gui;
    node_data_t gui_data;

    app.game = create_game(5, 5, 1);
    app.gui_list = list_new();
    cr_assert_not_null(app.gui_list);
    gui.list_messages = list_new();
    cr_assert_not_null(gui.list_messages);
    gui_data.gui = &gui;
    list_add_back(app.gui_list, gui_data);

    msz_response(&gui, &app, "mszeffsd");
    cr_assert_str_eq(gui.list_messages->first->data.message, "suc\n");
}
