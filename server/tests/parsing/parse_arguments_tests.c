/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** parse_arguments_tests
*/

#include <criterion/criterion.h>

#include "../include/parsing.h"

Test(parse_arguments, test_help_flag)
{
    char *av[] = {"./zappy_server", "--help"};
    cr_assert_eq(parse_arg(2, av), 0, "The function return a wrong value");
}

Test(parse_arguments, test_no_args)
{
    char *av[] = {"./zappy_server"};
    int result = parse_arg(1, av);
    cr_assert_eq(result, -1, "The function return a wrong value : %d", result);
}

Test(parse_arguments, test_not_enough_args)
{
    char *av[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "-c", "1"};
    int result = parse_arg(10, av);
    cr_assert_eq(result, -1, "The function return a wrong value : %d", result);
}

Test(parse_arguments, classic_test)
{
    char *av[] = {"./zappy_server", "-c", "4242", "-c", "10", "-c", "10", "-c", "1", "-c", "1", "-c", "100"};
    int result = parse_arg(13, av);
    cr_assert_eq(result, 0, "The function return a wrong value : %d", result);
}
