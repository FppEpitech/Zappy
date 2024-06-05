/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** parse_port_tests
*/

#include <criterion/criterion.h>

#include "parsing.h"
#include "types.h"

Test(parse_port, no_arg_passed)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));

    cr_assert_not_null(parsing);
    char *arg[] = {"-p", NULL};
    int pos = 0;
    int res = parse_port(arg, &pos, parsing);

    cr_assert_eq(res, CODE_ERROR_MISSING_ARG);
    free(parsing);
}

Test(parse_port, invalid_arg_passed)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));

    cr_assert_not_null(parsing);
    char *arg[] = {"-p", "test", NULL};
    int pos = 0;
    int res = parse_port(arg, &pos, parsing);

    cr_assert_eq(res, CODE_ERROR_INVALID_ARG);
    free(parsing);
}

Test(parse_port, valid_arg_passed)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));

    cr_assert_not_null(parsing);
    char *arg[] = {"-p", "10", NULL};
    int pos = 0;
    int res = parse_port(arg, &pos, parsing);

    cr_assert_eq(res, 0);
    cr_assert_eq(parsing->port, 10);
    cr_assert_eq(pos, 2);
    free(parsing);
}

Test(parse_port, invalid_flag_passed)
{
    parsing_t *parsing = malloc(sizeof(parsing_t));

    cr_assert_not_null(parsing);
    char *arg[] = {"-t", "10", NULL};
    int pos = 0;
    int res = parse_port(arg, &pos, parsing);

    cr_assert_eq(res, CODE_ERROR_WRONG_FLAG);
    free(parsing);
}
