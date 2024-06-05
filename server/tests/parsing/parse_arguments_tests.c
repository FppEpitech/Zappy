/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** parse_arguments_tests
*/

#include "../include/parsing.h"

#include <criterion/criterion.h>

Test(parse_arguments, test_help_flag)
{
    char *av[] = {"./zappy_server", "--help"};
    cr_assert_eq(parse_arg(2, av), 0, "The function return a wrong value");
}

Test(parse_arguments, test_no_args)
{
    char *av[] = {"./zappy_server"};
    parsing_t *result = parse_arg(1, av);
    cr_assert_null(result, "The function return a wrong value");
}

Test(parse_arguments, test_not_enough_args)
{
    char *av[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10", "-n", "team1", "-c", "1"};
    parsing_t *result = parse_arg(10, av);
    cr_assert_null(result, "The function return a wrong value");
}

Test(parse_arguments, classic_test)
{
    char **av = malloc(sizeof(char *) * 15);
    av[0] = "./zappy_server";
    av[1] = "-p";
    av[2] = "8080";
    av[3] = "-x";
    av[4] = "10";
    av[5] = "-y";
    av[6] = "10";
    av[7] = "-c";
    av[8] = "10";
    av[9] = "-f";
    av[10] = "80";
    av[11] = "-n";
    av[12] = "kiki";
    av[13] = "valgrind";
    av[14] = NULL;
    parsing_t *result = parse_arg(14, av);
    cr_assert_not_null(result, "The function return a wrong value");
    free(av);
}
