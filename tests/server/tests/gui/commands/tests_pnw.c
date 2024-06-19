/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** tests_pnw
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "list/type.h"
#include "list/list.h"
#include "gui/communication.h"

Test(pnw_command, basic_test)
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

    ia_t *ia = malloc(sizeof(ia_t));
    cr_assert_not_null(ia);
    ia->position = create_vector2i(1, 1);
    ia->fd = 1;
    ia->level = 1;
    ia->direction = 1;
    ia->team_name = "kiki";

    pnw_command(&app, ia);
    cr_assert_str_eq(gui.list_messages->first->data.message, "pnw 1 1 1 1 1 kiki\n");
}

Test(pnw_command, basic_test_2)
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

    ia_t *ia = malloc(sizeof(ia_t));
    cr_assert_not_null(ia);
    ia->position = create_vector2i(4, 3);
    ia->fd = 54;
    ia->level = 5;
    ia->direction = 2;
    ia->team_name = "alice";

    pnw_command(&app, ia);
    cr_assert_str_eq(gui.list_messages->first->data.message, "pnw 54 4 3 2 5 alice\n");
}

Test(pnw_command, multiple_gui_test)
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

    ia_t *ia = malloc(sizeof(ia_t));
    cr_assert_not_null(ia);
    ia->position = create_vector2i(2, 3);
    ia->fd = 105;
    ia->level = 5;
    ia->direction = 2;
    ia->team_name = "leo";

    pnw_command(&app, ia);

    list_node_t *node = gui.list_messages->first;
    while (node) {
        cr_assert_str_eq(gui.list_messages->first->data.message, "pnw 105 2 3 2 5 leo\n");
        node = node->next;
    }
}
