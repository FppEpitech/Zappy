/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** tests_pie
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "list/type.h"
#include "list/list.h"
#include "gui/communication.h"

Test(pie_command, basic_test)
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
    app.teams_list = list_new();

    team_t *team = create_team(&app, "kiki", 3);
    cr_assert_not_null(team);

    list_t *list_ai = list_new();
    cr_assert_not_null(list_ai);
    ia_t *ia = malloc(sizeof(ia_t));
    cr_assert_not_null(ia);
    ia->position = create_vector2i(1, 1);
    ia->fd = 1;
    ia->level = 1;
    ia_t *ia2 = malloc(sizeof(ia_t));
    cr_assert_not_null(ia2);
    ia2->position = create_vector2i(1, 1);
    ia2->fd = 2;
    ia->level = 1;
    node_data_t ia_data;
    ia_data.ai = ia;
    node_data_t ia_data2;
    ia_data2.ai = ia2;
    list_add_back(list_ai, ia_data);
    list_add_back(list_ai, ia_data2);

    pie_command(&app, list_ai);
    cr_assert_str_eq(gui.list_messages->first->data.message, "pie 1 1 2\n");
}

Test(pie_command, basic_test_2)
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
    app.teams_list = list_new();

    team_t *team = create_team(&app, "kiki", 3);
    cr_assert_not_null(team);

    list_t *list_ai = list_new();
    cr_assert_not_null(list_ai);
    ia_t *ia = malloc(sizeof(ia_t));
    cr_assert_not_null(ia);
    ia->position = create_vector2i(1, 1);
    ia->fd = 1;
    ia->level = 5;
    ia_t *ia2 = malloc(sizeof(ia_t));
    cr_assert_not_null(ia2);
    ia2->position = create_vector2i(1, 1);
    ia2->fd = 2;
    ia->level = 5;
    node_data_t ia_data;
    ia_data.ai = ia;
    node_data_t ia_data2;
    ia_data2.ai = ia2;
    list_add_back(list_ai, ia_data);
    list_add_back(list_ai, ia_data2);

    pie_command(&app, list_ai);
    cr_assert_str_eq(gui.list_messages->first->data.message, "pie 1 1 6\n");}

Test(pie_command, multiple_gui_test)
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
    app.teams_list = list_new();

    team_t *team = create_team(&app, "kiki", 3);
    cr_assert_not_null(team);

    list_t *list_ai = list_new();
    cr_assert_not_null(list_ai);
    ia_t *ia = malloc(sizeof(ia_t));
    cr_assert_not_null(ia);
    ia->position = create_vector2i(1, 1);
    ia->fd = 1;
    ia->level = 1;
    ia_t *ia2 = malloc(sizeof(ia_t));
    cr_assert_not_null(ia2);
    ia2->position = create_vector2i(1, 1);
    ia2->fd = 2;
    ia->level = 1;
    node_data_t ia_data;
    ia_data.ai = ia;
    node_data_t ia_data2;
    ia_data2.ai = ia2;
    list_add_back(list_ai, ia_data);
    list_add_back(list_ai, ia_data2);

    pie_command(&app, list_ai);

    list_node_t *node = gui.list_messages->first;
    while (node) {
        cr_assert_str_eq(gui.list_messages->first->data.message, "pie 1 1 2\n");
        node = node->next;
    }
}
