/*
** EPITECH PROJECT, 2024
** Zappy Server
** File description:
** Test on list
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "list/list.h"


Test(list, list_create, .timeout = 5)
{
    list_t *new_list = list_new();

    cr_assert_not_null(new_list);
    list_free(new_list);
}

Test(list, list_free, .timeout = 5)
{
    node_data_t data;
    list_t *new_list = list_new();

    list_add_back(new_list, data);
    list_add_back(new_list, data);
    list_add_back(new_list, data);
    cr_assert_eq(new_list->len, 3);
    list_free(new_list);
}

Test(list, list_add_back, .timeout = 5)
{
    node_data_t data;
    list_t *new_list = list_new();

    cr_assert_not_null(new_list);

    list_add_back(new_list, data);
    list_add_back(new_list, data);
    list_add_back(new_list, data);
    cr_assert_eq(new_list->len, 3);
}

Test(list, list_add_front, .timeout = 5)
{
    node_data_t data;
    list_t *new_list = list_new();

    cr_assert_not_null(new_list);

    list_add_front(new_list, data);
    list_add_front(new_list, data);

    cr_assert_eq(new_list->len, 2);
}

Test(list, list_remove_front_empty, .timeout = 5)
{
    list_t *new_list = list_new();

    cr_assert_eq(new_list->len, 0);
    list_remove_front(new_list);
    cr_assert_eq(new_list->len, 0);
}

Test(list, list_remove_front_list_of_one, .timeout = 5)
{
    node_data_t data;
    list_t *new_list = list_new();

    cr_assert_eq(new_list->len, 0);
    list_add_front(new_list, data);
    cr_assert_eq(new_list->len, 1);
    list_remove_front(new_list);
    cr_assert_eq(new_list->len, 0);
}

Test(list, list_remove_front, .timeout = 5)
{
    node_data_t data;
    list_t *new_list = list_new();

    cr_assert_eq(new_list->len, 0);
    list_add_front(new_list, data);
    cr_assert_eq(new_list->len, 1);
    list_add_front(new_list, data);
    cr_assert_eq(new_list->len, 2);
    list_remove_front(new_list);
    cr_assert_eq(new_list->len, 1);
}

Test(list, list_remove_back_empty, .timeout = 5)
{
    list_t *new_list = list_new();

    cr_assert_eq(new_list->len, 0);
    list_remove_back(new_list);
    cr_assert_eq(new_list->len, 0);
}

Test(list, list_remove_back_list_of_one, .timeout = 5)
{
    node_data_t data;
    list_t *new_list = list_new();

    cr_assert_eq(new_list->len, 0);
    list_add_back(new_list, data);
    cr_assert_eq(new_list->len, 1);
    list_remove_back(new_list);
    cr_assert_eq(new_list->len, 0);
}

Test(list, list_remove_back, .timeout = 5)
{
    node_data_t data;
    list_t *new_list = list_new();

    cr_assert_eq(new_list->len, 0);
    list_add_back(new_list, data);
    cr_assert_eq(new_list->len, 1);
    list_add_back(new_list, data);
    cr_assert_eq(new_list->len, 2);
    list_remove_back(new_list);
    cr_assert_eq(new_list->len, 1);
}

Test(list, list_delete_null, .timeout = 5)
{
    list_t *new_list = list_new();

    cr_assert_eq(new_list->len, 0);
    list_delete(new_list, NULL);
    cr_assert_eq(new_list->len, 0);
}

Test(list, list_delete_first, .timeout = 5)
{
    node_data_t node;
    list_t *new_list = list_new();

    cr_assert_eq(new_list->len, 0);
    list_add_back(new_list, node);
    cr_assert_eq(new_list->len, 1);
    list_delete(new_list, new_list->first);
    cr_assert_eq(new_list->len, 0);
}

Test(list, list_delete_last, .timeout = 5)
{
    node_data_t node;
    list_t *new_list = list_new();

    cr_assert_eq(new_list->len, 0);
    list_add_back(new_list, node);
    list_add_back(new_list, node);
    cr_assert_eq(new_list->len, 2);
    list_delete(new_list, new_list->last);
    cr_assert_eq(new_list->len, 1);
}

Test(list, list_delete_middle, .timeout = 5)
{
    node_data_t node;
    list_t *new_list = list_new();

    cr_assert_eq(new_list->len, 0);
    list_add_back(new_list, node);
    list_add_back(new_list, node);
    list_add_back(new_list, node);
    cr_assert_eq(new_list->len, 3);
    list_delete(new_list, new_list->first->next);
    cr_assert_eq(new_list->len, 2);
}
