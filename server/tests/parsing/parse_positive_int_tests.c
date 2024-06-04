/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** parse_positive_int_tests
*/

#include <criterion/criterion.h>

#include "../include/parsing.h"

Test(parse_positive_int, test_positive_int)
{
    cr_assert_eq(parse_positive_int_arg("42"), 42, "The function return a wrong value");
}

Test(parse_positive_int, test_negative_int)
{
    cr_assert_eq(parse_positive_int_arg("-42"), -1, "The function return a wrong value");
}

Test(parse_positive_int, test_not_int)
{
    cr_assert_eq(parse_positive_int_arg("test"), -1, "The function return a wrong value");
}
