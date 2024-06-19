/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** tests_suc
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "gui/communication.h"

Test(suc_command, basic_test)
{
    gui_t gui;

    gui.list_messages = list_new();
    cr_assert_not_null(gui.list_messages);
    suc_command(&gui);
    cr_assert_str_eq(gui.list_messages->first->data.message, "suc\n");
}
