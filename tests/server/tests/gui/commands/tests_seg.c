/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** tests_seg
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "list/type.h"
#include "list/list.h"
#include "gui/communication.h"

Test(seg_command, basic_test)
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

    seg_command(&app, "kiki forcement");
    cr_assert_str_eq(gui.list_messages->first->data.message, "seg kiki forcement\n");
}

Test(seg_command, basic_test_2)
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
    seg_command(&app, "la valgrind sinon");
    cr_assert_str_eq(gui.list_messages->first->data.message, "seg la valgrind sinon\n");
}

Test(seg_command, multiple_gui_test)
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
    seg_command(&app, "kiki toujours");
    list_node_t *node = gui.list_messages->first;
    while (node) {
        cr_assert_str_eq(gui.list_messages->first->data.message, "seg kiki toujours\n");
        node = node->next;
    }
}
