/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** parse_positive_int_tests
*/

#include "../include/parsing.h"
#include "rules.h"

#include <criterion/criterion.h>

Test(parse_positive_int, test_positive_int)
{
    cr_assert_eq(parse_positive_int_arg("42"), 42, "The function return a wrong value");
}

Test(parse_positive_int, test_negative_int)
{
    cr_assert_eq(parse_positive_int_arg("-42"), CODE_ERROR_INVALID_NUMBER, "The function return a wrong value");
}

Test(parse_positive_int, test_not_int)
{
    cr_assert_eq(parse_positive_int_arg("test"), CODE_ERROR_INVALID_NUMBER, "The function return a wrong value");
}
