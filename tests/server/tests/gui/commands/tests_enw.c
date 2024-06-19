/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** tests_enw
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "list/type.h"
#include "list/list.h"
#include "gui/communication.h"

Test(enw_command, basic_test_with_gui)
{
    app_t app;
    gui_t gui;
    egg_t egg;
    node_data_t gui_data;

    app.gui_list = list_new();
    cr_assert_not_null(app.gui_list);
    gui.list_messages = list_new();
    cr_assert_not_null(gui.list_messages);
    gui_data.gui = &gui;
    list_add_back(app.gui_list, gui_data);

    egg.id = 1;
    egg.id_player_laid = 1;
    egg.pos = malloc(sizeof(vector2i_t));
    egg.pos->x = 1;
    egg.pos->y = 1;

    enw_command(&app, &egg, &gui);
    cr_assert_str_eq(gui.list_messages->first->data.message, "enw 1 1 1 1\n");
    free(egg.pos);
}

Test(enw_command, multiple_gui_test)
{
    app_t app;
    gui_t gui;
    node_data_t gui_data;
    gui_t gui2;
    node_data_t gui_data2;
    egg_t egg;

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

    egg.id = 1;
    egg.id_player_laid = 1;
    egg.pos = malloc(sizeof(vector2i_t));
    egg.pos->x = 1;
    egg.pos->y = 1;

    enw_command(&app, &egg, NULL);

    list_node_t *node = gui.list_messages->first;
    while (node) {
        cr_assert_str_eq(node->data.message, "enw 1 1 1 1\n");
        node = node->next;
    }
    free(egg.pos);
}
