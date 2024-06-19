/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** tests_pdr
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "list/type.h"
#include "list/list.h"
#include "gui/communication.h"

Test(pdr_command, basic_test)
{
    app_t app;
    gui_t gui;
    node_data_t gui_data;

    app.gui_list = list_new();
    cr_assert_not_null(app.gui_list);
    gui.list_messages = list_new();
    cr_assert_not_null(gui.list_messages);
    gui_data.gui = &gui;
    list_add_back(app.gui_list, gui_data);
    pdr_command(&app, 1, 0);
    cr_assert_str_eq(gui.list_messages->first->data.message, "pdr 1 0\n");
}

Test(pdr_command, basic_test_2)
{
    app_t app;
    gui_t gui;
    node_data_t gui_data;

    app.gui_list = list_new();
    cr_assert_not_null(app.gui_list);
    gui.list_messages = list_new();
    cr_assert_not_null(gui.list_messages);
    gui_data.gui = &gui;
    list_add_back(app.gui_list, gui_data);
    pdr_command(&app, 58975, 1);
    cr_assert_str_eq(gui.list_messages->first->data.message, "pdr 58975 1\n");
}

Test(pdr_command, multiple_gui_test)
{
    app_t app;
    gui_t gui;
    node_data_t gui_data;
    gui_t gui2;
    node_data_t gui_data2;

    app.gui_list = list_new();
    cr_assert_not_null(app.gui_list);
    gui.list_messages = list_new();
    cr_assert_not_null(gui.list_messages);
    gui_data.gui = &gui;
    list_add_back(app.gui_list, gui_data);
    gui2.list_messages = list_new();
    cr_assert_not_null(gui2.list_messages);
    gui_data2.gui = &gui2;
    list_add_back(app.gui_list, gui_data2);
    pdr_command(&app, 1, 1);
    list_node_t *node = gui.list_messages->first;
    while (node) {
        cr_assert_str_eq(gui.list_messages->first->data.message, "pdr 1 1\n");
        node = node->next;
    }
}
