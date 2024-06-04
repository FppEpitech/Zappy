/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** parse_client_tests
*/

#include <criterion/criterion.h>

#include "parsing.h"

Test(parse_client, no_arg_passed)
{
    char *arg[] = {"-c", NULL};
    int res = parse_client(arg, 0);

    cr_assert_eq(res, -1);
}

Test(parse_client, invalid_arg_passed)
{
    char *arg[] = {"-c", "test", NULL};
    int res = parse_client(arg, 0);

    cr_assert_eq(res, -1);
}

Test(parse_client, valid_arg_passed)
{
    char *arg[] = {"-c", "10", NULL};
    int res = parse_client(arg, 0);

    cr_assert_eq(res, 10);
}

Test(parse_client, invalid_flag_passed)
{
    char *arg[] = {"-t", "10", NULL};
    int res = parse_client(arg, 0);

    cr_assert_eq(res, -1);
}
